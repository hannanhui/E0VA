/***************************************************************************//**
 * @file     ee_middlelevel.c
 * @brief    This file provides middle level functions used by eeprom emulation.
 * @version  V1.3
 * @date     May-2021
 * @author   Zhixin Semiconductor
 *
 * @note
 * Copyright (C) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 *
 ******************************************************************************/
#include <stdint.h>
#include <string.h>
#include "eep_emulation.h"
#include "ee_middlelevel.h"
#include "ee_lowlevel.h"

const uint32_t validPattern[EE_VALID_PATTERN_SIZE_IN_WORD] = 
{
    0x7869de01U,
    0xcdf0ab23U,
    0xFFFFFFFFU,
    0xFFFFFFFFU,
};

const uint32_t invalidPattern[EE_INVALID_PATTERN_SIZE_IN_WORD] = 
{
    0xcdf0ab23U,
    0x7869de01U,
    0xFFFFFFFFU,
    0xFFFFFFFFU,
};

void HalfwordToBytes(uint16_t src, uint8_t *dest)
{
    dest[0] = (uint8_t)(src & 0xFFU);
    dest[1] = (uint8_t)(src >> 8U);
}

void WordToBytes(uint32_t src, uint8_t *dest)
{
    dest[0] = (uint8_t)(src & 0xFFU);
    dest[1] = (uint8_t)((src >> 8U) & 0xFFU);
    dest[2] = (uint8_t)((src >> 16U) & 0xFFU);
    dest[3] = (uint8_t)((src >> 24U) & 0xFFU);
}

/***************************************************************************!
 * @brief: This API is to update the contents of the cache table while the
 *          data address is changed by writing a new value or sector swapping.
 *
 * @param[in]  cTable: a pointer that points to the cache table struct
 * @param[in]  recordID: record ID that to be updated
 * @param[in]  newValue: the value to be written to cache
 *
 * @return none
 *
 ****************************************************************************/
void EE_UpdateCacheTable(EE_cache_t* cTable, uint16_t recordID, 
                                   uint32_t newValue)
{
    /* Check if it is in the cache table */
    if (recordID < (cTable->num))
    {
        /* Update the cache table item with new value */
        cTable->cachePtr[recordID] = newValue;
    }
}

/***************************************************************************!
 *
 * @brief: This API is to search the required data record ID in the cache table.
 *
 * @param[in]  cTable: a pointer that points to the cache table struct
 * @param[in]  recordID: record ID that to be searched
 * @param[out] recAddr: record address
 *
 * @return EE_OK
 *         EE_ERROR_NOT_IN_CACHE
 *         EE_ERROR_DATA_NOT_FOUND
 *
 ****************************************************************************/
uint32_t EE_SearchInCache(EE_cache_t* cTable, uint16_t recordID, uint32_t* recAddr)
{
    uint32_t returnCode = EE_OK;

    /* check if the data ID is in the cache table ID range */
    if (recordID >= (cTable->num))
    {
        /* record ID is out of cache range */
        returnCode = EE_ERROR_NOT_IN_CACHE;
    }
    else
    {
        /* Fetch the required data record address */
        *recAddr = cTable->cachePtr[recordID];
        if (*recAddr >= EE_RECORD_ADDR_DELETED)   
        {
            /* The record was deleted or not found */
            returnCode = EE_ERROR_DATA_NOT_FOUND;
        }
    }

    return returnCode;
}

/***************************************************************************!
 *
 * @brief This function will read a valid/invalid flag.
 *
 * @param[in] addr: address of the flag
 * @param[in] flagPattern: the flag will be compared with flagPattern. If they
 *                         are equal, flag is SET.
 * @param[out] flag: the flag value will be stored in it by this function.
 * @param[in] CallBack: it points to a function to service the time critical 
 *                       events. Any code reachable from this function
 *                       must not be placed in the same Flash block as the 
 *                       EEPROM emulation
 *
 * @return
 *
 ****************************************************************************/
static uint32_t EE_ReadFlag(uint32_t addr, const uint32_t * flagPattern, 
                           FlagStatus_t *flag, void (*CallBack)(void))
{
    uint32_t returnCode;
    uint32_t buf[EE_VALID_PATTERN_SIZE_IN_WORD];
    uint8_t i;
    
    *flag =  RESET;
 
    returnCode = EE_FlashReadByWord(addr, buf,EE_VALID_PATTERN_SIZE_IN_WORD,CallBack);
    if (EE_OK != returnCode)
    {
        return returnCode;
    }

    *flag =  SET;
    for(i = 0U; i<EE_VALID_PATTERN_SIZE_IN_WORD; i++)
    {
        if(buf[i] != flagPattern[i])
        {
            *flag = RESET;
            break;
        }
    } 
    
    if(*flag == RESET)
    {
        for(i = 0U; i<EE_VALID_PATTERN_SIZE_IN_WORD; i++)
        {
            if(buf[i] != 0xFFFFFFFFU)
            {
                returnCode = EE_ERROR_HEADER_INVALID;
                break;
            }
        }        
    }
   
    return returnCode;
}

/***************************************************************************!
 *
 * @brief This function will read Sector header from specified address.
 *        It stores data into the Sector header structure.
 *
 * @param[in] addr: address of the Sector header
 * @param[out] head: points to a Sector header structure. The Sector header 
 *                   infomation will be stored into it by this API.
 * @param[in] CallBack: it points to a function to service the time critical 
 *                       events. Any code reachable from this function
 *                       must not be placed in the same Flash block as the 
 *                       EEPROM emulation
 *
 * @return status
 *
 ****************************************************************************/
uint32_t EE_ReadSectorHeader(uint32_t addr, EE_SectorHeader_t * head, 
                             void (*CallBack)(void))
{
    uint32_t returnCode;
    uint32_t checkSum, wordSize;
    FlagStatus_t validFlag, invalidFlag, infoBlankFlag;
    uint32_t buf[EE_RECORD_INFO_LEN>>2U];
    
    wordSize = EE_RECORD_INFO_LEN>>2U;    
    head->status = EE_SEC_STAT_HEADER_INVALID;
    
    /* read header info */
    returnCode = EE_FlashReadByWord(addr, buf, wordSize,CallBack);
    if(returnCode != EE_OK)
    {
        return returnCode;
    }
    
    infoBlankFlag = EE_SramCheckByWord(buf, wordSize, 0xFFFFFFFFU);
  
    if(infoBlankFlag == RESET)
    {
        head->id = buf[0U];
        head->startAddr = buf[1U];
        head->size = buf[2U];
        checkSum = buf[3U];
    
        if(head->id + head->startAddr + head->size != checkSum)
        {
            return EE_ERROR_HEADER_INVALID;
        }
    }

    returnCode = EE_ReadFlag(addr + EE_SECTOR_VALID_OFFSET, validPattern, 
                            &validFlag, CallBack );
    if(returnCode != EE_OK)
    {
        return returnCode;
    }
    returnCode = EE_ReadFlag(addr + EE_SECTOR_INVALID_OFFSET, invalidPattern, 
                            &invalidFlag, CallBack );
    if(returnCode != EE_OK)
    {
        return returnCode;
    }

    if((validFlag == RESET) && ( invalidFlag == RESET))
    {
        if(infoBlankFlag == RESET)
        {
            head->status = EE_SEC_STAT_INCONSISTENT;
        }
        else
        {
            head->status = EE_SEC_STAT_HEADER_BLANK;
        }
    }
    else if((validFlag == SET) && (invalidFlag == RESET))
    {
        head->status = EE_SEC_STAT_VALID;
    }
    else if((validFlag == SET) && ( invalidFlag == SET))
    {
        head->status = EE_SEC_STAT_INVALIDATED;
    }
    else
    {
        head->status = EE_SEC_STAT_HEADER_INVALID;
    }
    
    return returnCode;
}

/***************************************************************************!
 *
 * @brief This function will read record header from specified address.
 *        It stores data into the record header structure.
 *
 * @param[in] addr: address of the record header
 * @param[out] head: points to a record header structure. The record header 
 *                   infomation will be stored into it by this API.
 * @param[in] CallBack: it points to a function to service the time critical 
 *                       events. Any code reachable from this function
 *                       must not be placed in the same Flash block as the 
 *                       EEPROM emulation
 *
 * @return  - EE_OK
 *          - EE_ERROR_ECC
 *          - EE_ERROR_HEADER_INVALID
 *
 ****************************************************************************/
uint32_t EE_ReadRecordHeader(uint32_t addr, EE_RecordHeader_t * head,
                             void (*CallBack)(void))
{
    uint32_t returnCode;
    uint32_t checkSum, wordSize;
    FlagStatus_t validFlag, invalidFlag, infoBlankFlag;
    uint32_t buf[EE_RECORD_INFO_LEN>>2U];
    uint32_t bufAddr = (uint32_t)buf;
    
    wordSize = EE_RECORD_INFO_LEN>>2U;
    head->recordStatus = EE_REC_STAT_HEADER_INVALID;
 
    /* read header info */
    returnCode = EE_FlashReadByWord(addr, buf, wordSize,CallBack);
    if(returnCode != EE_OK)
    {
        return returnCode;
    }
    
    infoBlankFlag = EE_SramCheckByWord(buf, wordSize, 0xFFFFFFFFU);
  
    if(infoBlankFlag == RESET)
    {
        head->recordID = *(uint16_t *)(bufAddr + EE_RECORD_ID_OFFSET);
        head->dataSize = *(uint16_t *)(bufAddr + EE_RECORD_SIZE_OFFSET);
        head->dataStartAddr = *(uint32_t *)(bufAddr + EE_RECORD_ADDR_OFFSET);
        checkSum = *(uint32_t *)(bufAddr + EE_RECORD_CHECKSUM_OFFSET);
    
        if((uint32_t)(head->recordID) + (uint32_t)(head->dataSize)
           + head->dataStartAddr != checkSum)
        {
            return EE_ERROR_HEADER_INVALID;
        }
    }
    
    if(EE_OK != EE_ReadFlag(addr + EE_RECORD_VALID_OFFSET, validPattern, 
                           &validFlag, CallBack ))
    {
        return EE_ERROR_HEADER_INVALID;
    }
    
    if(EE_OK != EE_ReadFlag(addr + EE_RECORD_INVALID_OFFSET, invalidPattern, 
                           &invalidFlag, CallBack ))
    {
        return EE_ERROR_HEADER_INVALID;
    }

    if((validFlag == RESET) && ( invalidFlag == RESET))
    {
        if(infoBlankFlag == RESET)
        {
            head->recordStatus = EE_REC_STAT_INCONSISTENT;
        }
        else
        {
            head->recordStatus = EE_REC_STAT_HEADER_BLANK;
        }
    }
    else if((validFlag == SET) && (invalidFlag == RESET))
    {
        head->recordStatus = EE_REC_STAT_VALID;
    }
    else if((validFlag == SET) && ( invalidFlag == SET))
    {
        head->recordStatus = EE_REC_STAT_DELETED;
    }
    else
    {
        head->recordStatus = EE_REC_STAT_HEADER_INVALID;
    }
    
    return returnCode;
}

/***************************************************************************!
 *
 * @brief This API reads a record from the given record header address
 *
 * @param[in] recordAddr: the record header address
 * @param[in] dataSize: the size of data to be read out
 * @param[in] buf: points to a buffer where data that are read out are stored
 * @param[out] readSize: the size of data that are actually read out 
 *                      will be stored to the memory pointed by
 *                      readSize after calling this function
 * @param[in] CallBack: it points to a function to service the time critical 
 *                       events. Any code reachable from this function
 *                       must not be placed in the same Flash block as the 
 *                       EEPROM emulation
 *
 * @return  - EE_OK
 *          - EE_ERROR_ECC
 *          - EE_ERROR_REC_HEADER_INVALID
 *         
 *
 ****************************************************************************/
uint32_t EE_ReadRecordAtAddr(uint32_t recordAddr, uint16_t dataSize, 
                             uint8_t *buf, uint16_t *readSize, 
                             void (*CallBack)(void))
{
    EE_RecordHeader_t recHeader;     /* Local data record head structure */
    uint32_t returnCode;

    /* Read record head */
    returnCode = EE_ReadRecordHeader(recordAddr, &recHeader, CallBack);
    if(returnCode != EE_OK)
    {
        *readSize = 0;
    }
    else
    {
        *readSize = recHeader.dataSize;

        if (*readSize > dataSize)
        {
            *readSize = dataSize;
        }

        /* Read the data */
        if (EE_ERROR_ECC == EE_FlashRead(recHeader.dataStartAddr, buf, 
                                         *readSize, CallBack))
        {
            *readSize = 0;
            returnCode = EE_ERROR_ECC;
        }
    }
    
    return returnCode;
}
/***************************************************************************!
 *
 * @brief: This API will search the latest record ID in EEPROM flash
 *         with status that is valid or deleted.It will go through the entire 
 *         active sector for the latest data record.
 *
 * @param[in]  pSector: points to sector config struct
 * @param[in]  recordID: the ID of record to be read
 * @param[out] recAddr: record address
 * @param[in]  CallBack: it points to a function to service the time critical 
 *                       events. Any code reachable from this function
 *                       must not be placed in the same Flash block as the 
 *                       EEPROM emulation
 *
 * @return  void
 *
 ****************************************************************************/
static void EE_SearchRecord(EE_Config_t* eeConfig, uint16_t recordID, 
                     uint32_t* recordAddr, void (*CallBack)(void))
{
    const EE_SectorConfig_t* pSectorCfg;
    EE_RecordHeader_t recHeader;    /* Local data record head structure */
    uint32_t searchAddr;
    uint32_t count = 0U;

    pSectorCfg = eeConfig->sectors[eeConfig->actSecInfo.index];    

    /* set to invalid address */
    *recordAddr = EE_RECORD_ADDR_EMPTY;
    
    searchAddr = eeConfig->actSecInfo.recordAddr;

    while (searchAddr > (pSectorCfg->startAddr + EE_SECTOR_RECORD_OFFSET))
    {
        /* Point to header address of previous record */
        searchAddr -= EE_RECORD_HEADER_LEN;

        /* CallBack service routine */
        count++;
        if ((count % EE_CALLBACK_SEARCH_BYTES_NUM) == 0U)
        {
            if (CallBack != NULL)
            {
               CallBack();
            }
        }

        /* Read record head */
        if(EE_OK != EE_ReadRecordHeader(searchAddr, &recHeader, CallBack))
        {
            /* do nothing */
        }
        else
        {
            if (recordID == recHeader.recordID)
            {
                if (recHeader.recordStatus == EE_REC_STAT_DELETED)
                {
                    *recordAddr = EE_RECORD_ADDR_DELETED;    /* Mark as deleted */
                    break;  /* Stop searching */
                }
                else if(recHeader.recordStatus == EE_REC_STAT_VALID)
                {
                    /* Found the record */
                    *recordAddr = searchAddr;       
                    break;  /* Stop searching */
                }
                else
                {
                    /* EE_REC_STAT_HEADER_INVALID, EE_REC_STAT_INCONSISTENT,
                       EE_REC_STAT_HEADER_BLANK */
                }
            }
        }
    }
}

/***************************************************************************
 * @brief: This API is to search the required record ID in the active sector.
 *         It returns the data if the record is found and valid.
 *
 * @param[in]  eeConfig: EE configuration struct
 * @param[in]  recordID: the ID of record to be read
 * @param[out] recAddr: record address
 * @param[in]  CallBack: it points to a function to service the time critical 
 *                       events. Any code reachable from this function
 *                       must not be placed in the same Flash block as the 
 *                       EEPROM emulation
 *
 * @return  EE_OK
 *          EE_ERROR_DATA_NOT_FOUND
 *
 ****************************************************************************/
uint32_t EE_SearchInSectors(EE_Config_t* eeConfig, uint16_t recordID, 
                            uint32_t* recordAddr, void (*CallBack) (void))
{
    uint32_t searchResult = EE_ERROR_DATA_NOT_FOUND;

    EE_SearchRecord(eeConfig, recordID, recordAddr, CallBack);

    if(*recordAddr != EE_RECORD_ADDR_EMPTY)         /* Found the record */
    {
        if(*recordAddr != EE_RECORD_ADDR_DELETED)   /* The record is valid */
        {
            searchResult = EE_OK;
        }
    }

    return searchResult;
}

/***************************************************************************
* @brief        Adjusts size so it's integer multiple of EE_FL_PHRASE_SIZE
* 
* @param[in]    size: actual size
* 
* @return       uint16_t
*               the size is integer multiple of EE_FL_PHRASE_SIZE
* 
****************************************************************************/
uint16_t EE_AlignToPhraseSize(uint16_t size)
{
    /* Check whether the size is integer multiple */
    if(0U == (size % EE_FL_PHRASE_SIZE))
    {
        /* size is integer multiple of EE_FL_PHRASE_SIZE */
    }
    else
    {
        size = ((size / EE_FL_PHRASE_SIZE) + 1U )* EE_FL_PHRASE_SIZE;
    }
    
    return size;
}

/***************************************************************************
 * @brief      Validate a sector
 * 
 * 
 * @param[in]  pSector: points to sector config struct
 * @param[in]  CallBack: it points to a function to service the time critical 
 *                       events. Any code reachable from this function
 *                       must not be placed in the same Flash block as the 
 *                       EEPROM emulation
 * @return    EE_OK
 *            EE_ERROR_FLASH_ERR
 *
 ****************************************************************************/
uint32_t EE_ValidateSector(const EE_SectorConfig_t *pSector, 
                           void (*CallBack)(void))
{
    uint32_t returnCode;
    uint32_t patternInFlash;
    
#ifdef EE_PATTERN_IN_SRAM
    patternInFlash = 0U;
#else
    patternInFlash = 1U;
#endif
    
    returnCode = EE_FlashWriteWithPadding((uint32_t)validPattern, EE_VALID_PATTERN_SIZE_IN_BYTE,
                                          patternInFlash,
                                          pSector->startAddr + EE_SECTOR_VALID_OFFSET,
                                           CallBack);

    return returnCode;
}

/***************************************************************************
 * @brief      Invalidate a sector
 * 
 * 
 * @param[in]  pSector: points to sector config struct
 * @param[in]  CallBack: it points to a function to service the time critical 
 *                       events. Any code reachable from this function
 *                       must not be placed in the same Flash block as the 
 *                       EEPROM emulation
 * @return    EE_OK
 *            EE_ERROR_FLASH_ERR
 *
 ****************************************************************************/
uint32_t EE_InvalidateSector(const EE_SectorConfig_t *pSector, 
                             void (*CallBack)(void))
{
    uint32_t returnCode;
    uint32_t patternInFlash;
    
#ifdef EE_PATTERN_IN_SRAM
    patternInFlash = 0U;
#else
    patternInFlash = 1U;
#endif
    
    returnCode =  EE_FlashWriteWithPadding((uint32_t)invalidPattern, EE_INVALID_PATTERN_SIZE_IN_BYTE,
                                           patternInFlash,
                                           pSector->startAddr + EE_SECTOR_INVALID_OFFSET,
                                           CallBack);

    return returnCode;
}

/***************************************************************************
 * @brief      Validate a record
 * 
 * 
 * @param[in]  recordAddr: the header address of record to be invalidated
 * @param[in]  CallBack: it points to a function to service the time critical 
 *                       events. Any code reachable from this function
 *                       must not be placed in the same Flash block as the 
 *                       EEPROM emulation
 * @return    EE_OK
 *            EE_ERROR_FLASH_ERR
 *
 ****************************************************************************/
uint32_t EE_ValidateRecord(uint32_t recordAddr, void (*CallBack)(void))
{
    uint32_t returnCode;
    uint32_t patternInFlash;
    
#ifdef EE_PATTERN_IN_SRAM
    patternInFlash = 0U;
#else
    patternInFlash = 1U;
#endif
    
    returnCode = EE_FlashWriteWithPadding((uint32_t)validPattern, 
                                          EE_VALID_PATTERN_SIZE_IN_BYTE,
                                          patternInFlash,
                                          recordAddr + EE_RECORD_VALID_OFFSET,
                                          CallBack);
    
    return returnCode;
}

/***************************************************************************
 * @brief      Invalidate a record
 * 
 * 
 * @param[in]  recordAddr: the header address of record to be invalidated
 * @param[in]  CallBack: it points to a function to service the time critical 
 *                       events. Any code reachable from this function
 *                       must not be placed in the same Flash block as the 
 *                       EEPROM emulation
 * @return    EE_OK
 *            EE_ERROR_FLASH_ERR
 *
 ****************************************************************************/
uint32_t EE_InvalidateRecord(uint32_t recordAddr, void (*CallBack)(void))
{
    uint32_t returnCode;
    uint32_t patternInFlash;
    
#ifdef EE_PATTERN_IN_SRAM
    patternInFlash = 0U;
#else
    patternInFlash = 1U;
#endif
    
    returnCode = EE_FlashWriteWithPadding((uint32_t)invalidPattern,
                                          EE_INVALID_PATTERN_SIZE_IN_BYTE,
                                          patternInFlash,
                                          recordAddr + EE_RECORD_INVALID_OFFSET,
                                          CallBack);
    
    return returnCode;
}

/***************************************************************************
 * @brief      Write and validate a record in a specific sector
 * 
 * 
 * @param[in]  secInfo: points to sector info struct
 * @param[in]  recordID: the ID of record to be written
 * @param[in]  size: the size of data to be written. 
 * @param[in]  src: it points to the buffer that stores the data to be written
 * @param[in]  srcInFlash: it indicates if the location of data to be written
 *                         is in FLASH.
 *                         - 1: in flash
 *                         - 0: not in flash
 * @param[in]  CallBack: it points to a function to service the time critical 
 *                       events. Any code reachable from this function
 *                       must not be placed in the same Flash block as the 
 *                       EEPROM emulation
 * @return    EE_OK
 *            EE_ERROR_NO_ENOUGH_SPACE
 *            EE_ERROR_FLASH_ERR
 *
 ****************************************************************************/
uint32_t EE_WriteRecordInSector(EE_SectorInfo_t *secInfo, uint16_t recordID, 
                                uint16_t size, const uint8_t *src, uint32_t srcInFlash,
                                void (*CallBack)(void))
{
    uint32_t alignedSize, space;
    uint32_t returnCode;
    uint32_t dataAddr, hdrAddr;
    uint8_t recordInfo[EE_FL_PHRASE_SIZE];
    uint32_t checkSum, i ;
    FlagStatus_t blankFlag = RESET;
    FlagStatus_t checkFlag = RESET;
    
    space = secInfo->dataAddr - secInfo->recordAddr;
    
    if(size == 0U)
    {
        return EE_ERROR_INPUT_PARA;
    }
        
    alignedSize = EE_AlignToPhraseSize(size);
    
    if((alignedSize + (2U * EE_RECORD_HEADER_LEN )) > space )
    {
        returnCode = EE_ERROR_NO_ENOUGH_SPACE;
    }
    else
    {
        dataAddr = secInfo->dataAddr - alignedSize;
        hdrAddr = secInfo->recordAddr;
        
        /* check if the flash location for record header is empty */
        returnCode = EE_FlashBlankCheck(hdrAddr, EE_RECORD_HEADER_LEN, 
                                        &blankFlag,CallBack);
        if((returnCode != EE_OK) || (blankFlag == RESET))
        {
            return EE_ERROR_WRITTEN_LOC_NOT_EMPTY;
        }        
    
        /* init recordInfo */
        for(i = 0U; i<EE_FL_PHRASE_SIZE;i++)
        {
            recordInfo[i] = 0xFFU;
        }        
        
        checkSum = (uint32_t)recordID + (uint32_t)size + dataAddr;
        
        HalfwordToBytes(recordID, &(recordInfo[EE_RECORD_ID_OFFSET]));
        HalfwordToBytes(size, &(recordInfo[EE_RECORD_SIZE_OFFSET]));
        WordToBytes(dataAddr, &(recordInfo[EE_RECORD_ADDR_OFFSET]));
        WordToBytes(checkSum, &(recordInfo[EE_RECORD_CHECKSUM_OFFSET]));
        
        /* write record info */
        returnCode = EE_FlashWriteWithPadding((uint32_t)recordInfo, EE_RECORD_INFO_LEN,
                                              0, hdrAddr, CallBack);
        if(returnCode != EE_OK)
        {
            return returnCode;
        }
        
        blankFlag = RESET;
        /* check if the flash location for record data is empty */
        returnCode = EE_FlashBlankCheck(dataAddr, alignedSize, &blankFlag,
                                        CallBack);
        if((returnCode != EE_OK) || (blankFlag == RESET))
        {
            return EE_ERROR_WRITTEN_LOC_NOT_EMPTY;
        }
        
        secInfo->recordAddr += EE_RECORD_HEADER_LEN;
        secInfo->dataAddr = dataAddr;
        /* write data into flash */
        returnCode = EE_FlashWriteWithPadding((uint32_t)src, size, srcInFlash, dataAddr, 
                                              CallBack);
        if(EE_OK == returnCode)
        {
            returnCode = EE_DataCheck(dataAddr, src, size, &checkFlag, CallBack);
            
            if((returnCode == EE_OK) && (checkFlag == SET))
            {
                /* validate record */
                returnCode = EE_ValidateRecord(hdrAddr, CallBack);
            }
            else
            {
                returnCode |= EE_ERROR_WRITTEN_VALUE;
            }            
        }
        else
        {
            returnCode = EE_ERROR_READ_REC_DATA_ECC;
        }
    }
    
    return returnCode;
}

/***************************************************************************
 * @brief      erase EE sector
 * 
 * 
 * @param[in]  pSector: points to sector config struct
 * @param[in]  CallBack: it points to a function to service the time critical 
 *                       events. Any code reachable from this function
 *                       must not be placed in the same Flash block as the 
 *                       EEPROM emulation
 *
 *
 ****************************************************************************/
uint32_t EE_EmptySector(const EE_SectorConfig_t* pSector, void (*CallBack)(void))
{
    uint32_t returnCode;

    /* erase the EE sector */
    returnCode = EE_SectorErase(pSector->startAddr,pSector->size,CallBack);
   
    return returnCode;    
}

/***************************************************************************
 * @brief      Write sector information into sector header
 * 
 * 
 * @param[in]  pSector: points to sector config struct
 * @param[in]  id: the active sector ID to be written into sector header
 * @param[in]  CallBack: it points to a function to service the time critical 
 *                       events. Any code reachable from this function
 *                       must not be placed in the same Flash block as the 
 *                       EEPROM emulation
 *
 *
 ****************************************************************************/
uint32_t EE_FormatSector(const EE_SectorConfig_t* pSector, uint32_t id, 
                         void (*CallBack) (void))
{
    uint8_t sectorInfo[EE_FL_PHRASE_SIZE];
    uint32_t checkSum;
    uint32_t returnCode;
        
    checkSum = id + pSector->startAddr + pSector->size;
        
    WordToBytes(id, &(sectorInfo[EE_SECTOR_ID_OFFSET]));
    WordToBytes(pSector->startAddr, &(sectorInfo[EE_SECTOR_ADDR_OFFSET]));
    WordToBytes(pSector->size, &(sectorInfo[EE_SECTOR_SIZE_OFFSET]));
    WordToBytes(checkSum, &(sectorInfo[EE_SECTOR_CHECKSUM_OFFSET]));
        
    /* write record info */
    returnCode = EE_FlashWriteWithPadding((uint32_t)sectorInfo, 
                                          EE_SECTOR_INFO_LEN, 0,
                                          pSector->startAddr, CallBack);
    
    return returnCode;    
}

/***************************************************************************
 * @brief      Check if there is enough space in the sector to store new
 *             record
 * 
 * 
 * @param[in]  secInfo: points to sector information struct
 * @param[in]  dataSize: data size of the record
 *
 * @return 
 *           - 0: no enough space
 *           - 1: space is enough 
 ****************************************************************************/
uint32_t EE_CheckSectorSpaceForRecord(EE_SectorInfo_t* secInfo, 
                                      uint16_t dataSize)
{
    uint32_t alignedSize, space,res;
    
    space = secInfo->dataAddr - secInfo->recordAddr;
        
    alignedSize = EE_AlignToPhraseSize(dataSize);

    /* One EE_RECORD_HEADER_LEN must be left blank to have a clear separation
       between header space and data space */
    if((alignedSize + (2U * EE_RECORD_HEADER_LEN)) > space )
    {
        /* no enough space */
        res = 0;
    }
    else
    {
        /* space is enough for new record */
        res = 1;
    }
    
    return res;
}

/***************************************************************************
 * @brief      scan the whole active sector, update active sector information, 
 *             update the cache if it is enabled
 * 
 * 
 * @param[in]  eeConfig: EE configuration struct
 * @param[in]  CallBack: it points to a function to service the time critical 
 *                       events. Any code reachable from this function
 *                       must not be placed in the same Flash block as the 
 *                       EEPROM emulation
 *
 *
 ****************************************************************************/
uint32_t EE_ScanSector(EE_Config_t* eeConfig, ControlState_t swapEn, 
                       void (*CallBack)(void))
{    
    const EE_SectorConfig_t *pSector = eeConfig->sectors[eeConfig->actSecInfo.index];
    uint32_t recordAddr = pSector->startAddr + EE_SECTOR_HEADER_LEN;
    uint32_t dataAddr = pSector->startAddr + pSector->size;
    uint32_t returnCode = EE_OK;
    EE_RecordHeader_t recHead;
    FlagStatus_t swapFlag = RESET, scanEndFlag = RESET, lastHeaderInvalid = RESET;
    
    while((scanEndFlag == RESET) && (dataAddr > (recordAddr + EE_RECORD_HEADER_LEN*2U)))
    {        
        returnCode = EE_ReadRecordHeader(recordAddr, &recHead, CallBack);
        if((returnCode != EE_OK) && (swapEn == ENABLE))
        {
            swapFlag = SET;
        }
        
        switch(recHead.recordStatus)
        {
            case EE_REC_STAT_VALID:
                /* Check if the cache table is enabled */
                if(eeConfig->cacheEn == ENABLE)
                {
                    EE_UpdateCacheTable(eeConfig->cTable, recHead.recordID, 
                                        recordAddr);
                }
            
                recordAddr += EE_RECORD_HEADER_LEN;
                dataAddr = recHead.dataStartAddr;
                lastHeaderInvalid = RESET;
                break;
                
            case EE_REC_STAT_DELETED:
            case EE_REC_STAT_INCONSISTENT:
                recordAddr += EE_RECORD_HEADER_LEN;
                dataAddr = recHead.dataStartAddr;
                lastHeaderInvalid = RESET;
                break;
                
            case EE_REC_STAT_HEADER_INVALID:
                recordAddr += EE_RECORD_HEADER_LEN;
                lastHeaderInvalid = SET;
                /* the data start address info is invalid, so do not change the
                   dataAddr */
                break;
                
            case EE_REC_STAT_HEADER_BLANK:
                scanEndFlag = SET;
                break;
                
            default:
                /* impossible */
                break;
        }
    }
    
    eeConfig->actSecInfo.recordAddr = recordAddr;
    eeConfig->actSecInfo.dataAddr = dataAddr;
    
    /* if last record header is invalid, swap sector, no matter the swapEn is
       enabled or not */
    if(lastHeaderInvalid == SET)
    {
        swapFlag = SET;
    }
    
    if((swapFlag == SET) || (dataAddr <= (recordAddr + EE_RECORD_HEADER_LEN*2U)))
    {
        returnCode = EE_SectorSwap(eeConfig, CallBack);
        if(returnCode != EE_OK)
        {
            returnCode = EE_ERROR_SWAP;
        }
    }
    
    return returnCode;
}

/***************************************************************************
 * @brief      swap sectors
 * 
 * 
 * @param[in]  eeConfig: EE configuration struct
 * @param[in]  CallBack: it points to a function to service the time critical 
 *                       events. Any code reachable from this function
 *                       must not be placed in the same Flash block as the 
 *                       EEPROM emulation
 *
 *
 ****************************************************************************/
uint32_t EE_SectorSwap(EE_Config_t* eeConfig, void (*CallBack)(void))
{
    uint32_t nextSector, actSector, id;
    uint32_t returnCode;
    EE_SectorHeader_t secHead;
    EE_RecordHeader_t recHead;
    uint16_t nextRecordId;
    uint32_t recordAddr;
    const EE_SectorConfig_t *srcSector, *destSector;
    EE_SectorInfo_t destSecInfo;
    EE_SectorInfo_t *srcSecInfo;
    
    actSector = eeConfig->actSecInfo.index;
    srcSecInfo = &(eeConfig->actSecInfo);
    
    /* check the active sector status */
    if(EE_OK != EE_ReadSectorHeader(eeConfig->sectors[actSector]->startAddr, &secHead, CallBack))
    {
        /* do nothing */
    }
    
    if(EE_SEC_STAT_VALID != secHead.status)
    {
        /* the status of active sector is not valid */
        returnCode = EE_ERROR_INPUT_PARA;
        return returnCode;
    }
    
    srcSector = eeConfig->sectors[actSector];
    nextSector = (actSector + 1U) % eeConfig->sectorNum;
    destSector = eeConfig->sectors[nextSector];
    /* empty the next sector */
    returnCode = EE_EmptySector(destSector,CallBack);
    if(returnCode != EE_OK)
    {
        return returnCode;
    }
    
    destSecInfo.status = EE_SEC_STAT_HEADER_BLANK;
    
    /* format next sector */
    id = srcSecInfo->id + 1U;
    returnCode =  EE_FormatSector(destSector, id, CallBack);
    if(returnCode != EE_OK)
    {
        return returnCode;
    }
    /* update destination sector config parameters */
    destSecInfo.id = id;
    destSecInfo.recordAddr = destSector->startAddr + EE_RECORD_HEADER_LEN;
    destSecInfo.dataAddr = destSector->startAddr + destSector->size;
    destSecInfo.status = EE_SEC_STAT_INCONSISTENT;
    destSecInfo.index = nextSector;
    
    /* swap records */ 
    nextRecordId = 0U;
    if(eeConfig->cacheEn == ENABLE)
    {
        /* Check for each item in the cache table */
        for (nextRecordId = 0U; nextRecordId < eeConfig->cTable->num; nextRecordId++)
        {
            /* Get record address */
            recordAddr = eeConfig->cTable->cachePtr[nextRecordId];

            /* If the record is in the source sector */
            if ((recordAddr > srcSector->startAddr) &&
                (recordAddr < (srcSector->startAddr + srcSector->size)))
            {
                /* Read the record */
                if(EE_OK != EE_ReadRecordHeader(recordAddr, &recHead, CallBack))
                {
                    /* the recordStatus must be EE_REC_STAT_HEADER_INVALID, it
                       will be handled below, so do nothing here */
                }
                
                if(recHead.recordStatus == EE_REC_STAT_VALID)
                {
                    returnCode = EE_WriteRecordInSector(&destSecInfo, 
                                                        recHead.recordID, 
                                                        recHead.dataSize,
                                                        (uint8_t *)recHead.dataStartAddr,
                                                        1U, CallBack);

                    if(returnCode == EE_OK)
                    {
                        /* Check if the cache table is enabled */
                        if(eeConfig->cacheEn == ENABLE)
                        {
                            EE_UpdateCacheTable(eeConfig->cTable, recHead.recordID, 
                                                destSecInfo.recordAddr - EE_RECORD_HEADER_LEN);
                        }
                    }
                    else if( returnCode == EE_ERROR_READ_REC_DATA_ECC)
                    {
                        /* read source record data ECC,  the status of this
                           written record is inconsistent, skip this record */
                        if(eeConfig->cacheEn == ENABLE)
                        {
                            /* delete it in the cache */
                            EE_UpdateCacheTable(eeConfig->cTable, recHead.recordID, 
                                                EE_RECORD_ADDR_EMPTY);
                        }                        
                    }
                    else
                    {
                        /* fail to write a record, stop and return */
                        return returnCode;
                    }
                }
                else
                {
                    /* it is in cache, but the status of record is not valid 
                       the cache item error */
                    returnCode = EE_ERROR_CACHE_ITEM;
                    return returnCode;
                }
            }
        }
    }
    
    /* Continue copy records aren't in the cache table */
    while((nextRecordId <= eeConfig->maxRecordId) && (returnCode == EE_OK))
    {
        EE_SearchRecord(eeConfig, nextRecordId, &recordAddr, CallBack);
        if((recordAddr != EE_RECORD_ADDR_EMPTY) && 
           (recordAddr != EE_RECORD_ADDR_DELETED))
        {
            /* Read the record header*/
            returnCode = EE_ReadRecordHeader(recordAddr, &recHead, CallBack);
            if(returnCode != EE_OK)
            {
                /* record searched but flash error when read header */
                return returnCode;
            }
                
            if(recHead.recordStatus == EE_REC_STAT_VALID)
            {
                returnCode = EE_WriteRecordInSector(&destSecInfo, 
                                                    recHead.recordID, 
                                                    recHead.dataSize,
                                                    (uint8_t *)recHead.dataStartAddr,
                                                    1U, CallBack);

                if(returnCode == EE_OK)
                {
                    /* success,go on to next record */
                }
                else if( returnCode == EE_ERROR_READ_REC_DATA_ECC)
                {
                    /* read source record data ECC, the status of this
                       written record is inconsistent, skip this record */                    
                }
                else
                {
                    /* fail to write a record, stop and return */
                    return returnCode;
                }                
            }
            else
            {
                /* the read-out record status when searching and reading header 
                   is different, it is probably flash error when read flash */
                returnCode = EE_ERROR_FLASH_ERR;
            }
        }
        
        nextRecordId++;
    }
    
    if(returnCode == EE_OK)
    {
        /* make the sector to be valid */
        returnCode = EE_ValidateSector(destSector, CallBack);

        if(returnCode == EE_OK)
        {            
            if(EE_OK != EE_ReadSectorHeader(eeConfig->sectors[nextSector]->startAddr, 
                                            &secHead, CallBack))
            {
                /* the secHead.status must not be EE_SEC_STAT_VALID, so it is 
                   handled below, do nothing here */
            }
            if((secHead.status != EE_SEC_STAT_VALID) || 
               (destSecInfo.id != secHead.id))
            {
                returnCode = EE_ERROR_SWAP;
            }
            else
            {                
                eeConfig->actSecInfo.index = nextSector;
                eeConfig->actSecInfo.id = destSecInfo.id;
                eeConfig->actSecInfo.status = EE_SEC_STAT_VALID;
                eeConfig->actSecInfo.dataAddr = destSecInfo.dataAddr;
                eeConfig->actSecInfo.recordAddr = destSecInfo.recordAddr;
                
                /* invalidated the source sector */
                returnCode = EE_InvalidateSector(srcSector, CallBack);
            }
        }
    }
    
    return returnCode;
}
