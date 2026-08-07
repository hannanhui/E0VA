/***************************************************************************//**
 * @file     eep_emulation.c
 * @brief    EEPROM emulation source file.
 * @version  V1.3
 * @date     May-2021
 * @author   Zhixin Semiconductor
 *
 * @note
 * Copyright (C) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 * 
 ******************************************************************************/
#include "eep_emulation.h"
#include "ee_middlelevel.h"
#include "common_drv.h"
//#include "Fls.h"
//#include "Flash_Drv.h"
#include "m_flash_drv.h".h"" 
/***************************************************************************!
 * @brief: Init the EEPROM Emulation driver
 *
 * @param[in]  eeConfig: EE configuration struct
 * @param[in]  swapEn: It indicates if it swaps sectors when it finds invalid 
 *                     record header during sector scanning.
 * @param[in]  CallBack: it points to a function to service the time critical 
 *                       events. Any code reachable from this function
 *                       must not be placed in the same Flash block as the 
 *                       EEPROM emulation
 *
 * @return result
 *         EE_OK
 *         EE_ERROR_BUSY
 *         EE_ERROR_NOT_ENOUGH_SECTORS
 *         EE_ERROR_FLASH_ERR
 *         EE_ERROR_ECC
 *         EE_ERROR_REC_HEADER_INVALID
 *         EE_ERROR_INPUT_PARA
 *         EE_ERROR_SWAP
 *         
 *
 ****************************************************************************/
uint32_t EE_Init(EE_Config_t* eeConfig, ControlState_t swapEn, 
                 void (*CallBack) (void))
{
    const EE_SectorConfig_t* pSector;
    EE_SectorHeader_t secHeader;
    uint32_t returnCode;
    uint32_t temp, cnt;
    uint16_t i;    
    
    if (eeConfig->sectorNum < MIN_SECTOR_NUM)
    {
        /* There isn't enough number of sectors for emulation */
        returnCode = EE_ERROR_NOT_ENOUGH_SECTORS;
    }
    else if (eeConfig->busyFlag == SET)
    {
        returnCode = EE_ERROR_BUSY;
    }
    else
    {
        /* Set the busy flag */
        eeConfig->busyFlag = SET;
        
        /* Clear Cache table */
        if (eeConfig->cacheEn == ENABLE)
        {
            /* Get number of Cache items */
            temp = eeConfig->cTable->num;  
            for (i = 0U; i < temp; i++)
            {
                 EE_UpdateCacheTable(eeConfig->cTable, i, EE_RECORD_ADDR_EMPTY);
            }
        }
        
        eeConfig->actSecInfo.id = 0U;
        eeConfig->actSecInfo.index = 0U;
        eeConfig->actSecInfo.status = EE_SEC_STAT_HEADER_INVALID;
        
        /* scan sector headers to find valid sector */
        temp = eeConfig->sectorNum;
        for (i = 0U; i < temp; i++)
        {
            pSector = eeConfig->sectors[i];
            
            cnt = 0;
            do
            {
                returnCode = EE_ReadSectorHeader(pSector->startAddr, &secHeader,
                                                 CallBack);
                cnt++;
                if(cnt >= EE_RETRY_TIMES)
                {
                    break;
                }
            }while(returnCode != EE_OK);
            
            if(returnCode != EE_OK)
            {
                /* read sector header error */
            }
            else
            {
                if(secHeader.status == EE_SEC_STAT_VALID)
                {
                    if((secHeader.id > eeConfig->actSecInfo.id) && 
                       (secHeader.startAddr == pSector->startAddr) &&
                       (secHeader.size == pSector->size))
                    {
                        eeConfig->actSecInfo.id = secHeader.id;
                        eeConfig->actSecInfo.status = EE_SEC_STAT_VALID;
                        eeConfig->actSecInfo.index = i;
                        eeConfig->actSecInfo.recordAddr = pSector->startAddr 
                                                         + EE_SECTOR_HEADER_LEN;
                        eeConfig->actSecInfo.dataAddr = pSector->startAddr 
                                                        + pSector->size;
                    }
                }
            }
        }        
        
        if(eeConfig->actSecInfo.id == 0U)
        {
            /* no active sector is found, erase the first sector */
            pSector = eeConfig->sectors[0];
            /* empty sector */
            returnCode = EE_EmptySector(pSector,CallBack);

            if(returnCode == EE_OK)
            {
                /* format the sector */
                returnCode =  EE_FormatSector(pSector, 1, CallBack);
                if(returnCode == EE_OK)
                {
                    /* validate the sector */
                    returnCode =  EE_ValidateSector(pSector, CallBack);
                        
                    eeConfig->actSecInfo.id = 1U;
                    eeConfig->actSecInfo.index = 0;
                    eeConfig->actSecInfo.status = EE_SEC_STAT_VALID;
                    eeConfig->actSecInfo.recordAddr = pSector->startAddr 
                                                     + EE_SECTOR_HEADER_LEN;
                    eeConfig->actSecInfo.dataAddr = pSector->startAddr 
                                                    + pSector->size;
                }
            }
            else
            {
                returnCode = EE_ERROR_FLASH_ERR;
            }
        }
        else
        {            
            returnCode = EE_ScanSector(eeConfig, swapEn, CallBack);            
        }        
        
        /* Unlock the busy lock */
        eeConfig->busyFlag = RESET;
    }

    return returnCode;
}
/***************************************************************************//**
 * @brief  This API is to read the specific data record. The data record size
 *         is determined by the data size stored in emulated EEPROM.
 *
 * @param[in]  eeConfig: EE configuration struct
 * @param[in]  recordID: the ID of record to be read
 * @param[in]  dataSize: the size of data to be read from the record. It can not
 *                       exceeds the size of record.
 * @param[in]  buf: it points to the buffer that stores the data read out from
 *                  record.
 * @param[out]  acturalReadSize: the size of data that are actually read out 
 *                               will be stored to the memory pointed by
 *                               acturalReadSize after calling this function
 * @param[in]  CallBack: it points to a function to service the time critical 
 *                       events. Any code reachable from this function
 *                       must not be placed in the same Flash block as the 
 *                       EEPROM emulation
 *
 * @note       User must ensure that the data size to be read does not exceed 
 *             the buffer size. 
 *             
 *
 * @return     EE_OK
 *             EE_ERROR_BUSY -- EE is writing or erasing
 *             EE_ERROR_DATA_NOT_FOUND
 *             EE_ERROR_REC_ID_OUT_OF_RANGE
 *             EE_ERROR_ECC
 *             EE_ERROR_REC_HEADER_INVALID
 *
 ******************************************************************************/  
uint32_t EE_ReadRecord(EE_Config_t* eeConfig, uint16_t recordID, 
                       uint16_t dataSize, uint8_t *buf, 
                       uint16_t *acturalReadSize, void (*CallBack) (void))
{
    /* record header address */
    uint32_t recordAddr = EE_RECORD_ADDR_EMPTY;  
    uint32_t returnCode = EE_OK;
    
    if(recordID > eeConfig->maxRecordId)
    {
        returnCode = EE_ERROR_REC_ID_OUT_OF_RANGE;
        return returnCode;
    }

    /* Check the write lock */
    if (eeConfig->busyFlag == SET)
    {
        /* EE is busy */
        returnCode = EE_ERROR_BUSY;
    }
    else
    {
        *acturalReadSize = 0U;
        
         /* Search in the cache table */
        if(eeConfig->cacheEn == ENABLE)
        {
            returnCode = EE_SearchInCache(eeConfig->cTable, recordID, &recordAddr);            
        }

        /* Search in flash sectors if cache is disable or the record is not in cache */
        if((eeConfig->cacheEn == DISABLE) || ((returnCode & EE_ERROR_NOT_IN_CACHE) != 0U))
        {
            returnCode = EE_SearchInSectors(eeConfig, recordID, &recordAddr,
                                            CallBack);
        }

        /* Read record if found */
        if(returnCode == EE_OK)
        {
            returnCode = EE_ReadRecordAtAddr(recordAddr, dataSize, buf, 
                                             acturalReadSize, CallBack);


					
            if(returnCode != EE_OK)
            {
                if(eeConfig->cacheEn == ENABLE)
                {
                    EE_UpdateCacheTable(eeConfig->cTable, recordID, 
                                        EE_RECORD_ADDR_EMPTY);
                }
            }
        }
        else
        {
            returnCode |= EE_ERROR_DATA_NOT_FOUND;
        }
    }

    return returnCode;
}

/***************************************************************************
 * @brief; This API is to write data records to the EEPROM emulated Flash
 *          and re-write data record if this program operation fails.
 *
 * @param[in]  eeConfig: EE configuration struct
 * @param[in]  recordID: the ID of record to be written
 * @param[in]  dataSize: the size of data to be written. 
 * @param[in]  buf: it points to the buffer that stores the data to be written
 * @param[in]  srcInFlash: it indicates if the location of data(buf) to be 
 *                         written is in FLASH.
 *                         - 1: in flash
 *                         - 0: not in flash
 * @param[in]  CallBack: it points to a function to service the time critical 
 *                       events. Any code reachable from this function
 *                       must not be placed in the same Flash block as the 
 *                       EEPROM emulation
 *
 * @return EE_OK
 *         EE_ERROR_BUSY -- EE is writing or erasing
 *         EE_ERROR_NO_ENOUGH_SPACE
 *         EE_ERROR_SWAP
 *         EE_ERROR_INPUT_PARA
 *         EE_ERROR_WRITTEN_LOC_NOT_EMPTY
 *         EE_ERROR_READ_REC_DATA_ECC
 *         EE_ERROR_WRITTEN_VALUE
 *         EE_ERROR_ECC
 *
 ****************************************************************************/
uint32_t EE_WriteRecord(EE_Config_t* eeConfig, uint16_t recordID, 
                        uint16_t dataSize,const uint8_t *buf, 
                        uint32_t srcInFlash,void (*CallBack) (void))
{
    EE_SectorInfo_t *secInfo;
    uint32_t returnCode = EE_OK;
    uint32_t spaceFlag;
    
    if(recordID > eeConfig->maxRecordId)
    {
        returnCode = EE_ERROR_REC_ID_OUT_OF_RANGE;
        return returnCode;
    }
        
    if(dataSize == 0U)
    {
        returnCode = EE_ERROR_INPUT_PARA;
        return returnCode;
    }
    
    if (eeConfig->busyFlag == SET)
    {
        /* EE is busy */
        returnCode = EE_ERROR_BUSY;
    }
    else
    {
        /* Set the busy flag */
        eeConfig->busyFlag = SET; 

        secInfo = &(eeConfig->actSecInfo);
        spaceFlag = EE_CheckSectorSpaceForRecord(secInfo,dataSize);                                     

        /* One EE_RECORD_HEADER_LEN must be left blank to have a clear separation
        between header space and data space */
        if(spaceFlag == 0U )
        {
            /* The record won't fit into current sector. swap sectors */
            returnCode = EE_SectorSwap(eeConfig, CallBack);
            
            if(returnCode == EE_OK)
            {
                secInfo = &(eeConfig->actSecInfo);
                spaceFlag = EE_CheckSectorSpaceForRecord(secInfo,dataSize);
                if(spaceFlag == 0U)
                {
                    returnCode |= EE_ERROR_NO_ENOUGH_SPACE;
                }
                else
                {
                    /* enough space for new record */
                }
            }
            else
            {
                returnCode |= EE_ERROR_SWAP;
            }
        }
        
        if(returnCode == EE_OK)
        {
            returnCode |= EE_WriteRecordInSector(secInfo, recordID, dataSize, 
                                                buf, srcInFlash, CallBack);
 
            if(returnCode == EE_OK)
            {
                /* Check if the cache table is enabled */
                if(eeConfig->cacheEn == ENABLE)
                {
                    EE_UpdateCacheTable(eeConfig->cTable, recordID, 
                                        secInfo->recordAddr - EE_RECORD_HEADER_LEN);
                }
            }
        }
        
        /* clear the busy flag */
        eeConfig->busyFlag = RESET;        
    }

    return returnCode;
}

/***************************************************************************//**
 * @brief  This API is to delete the specific data record. 
 *
 * @param[in]  eeConfig: EE configuration struct
 * @param[in]  recordID: the ID of record to be read
 * @param[in]  CallBack: it points to a function to service the time critical 
 *                       events. Any code reachable from this function
 *                       must not be placed in the same Flash block as the 
 *                       EEPROM emulation
 *
 * @return     EE_OK
 *             EE_ERROR_BUSY -- EE is writing or erasing
 *             EE_ERROR_DATA_NOT_FOUND
 *             EE_ERROR_REC_ID_OUT_OF_RANGE
 *             EE_ERROR_FLASH_ERR
 *
 ******************************************************************************/  
uint32_t EE_DeleteRecord(EE_Config_t* eeConfig, uint16_t recordID, 
                         void (*CallBack) (void))
{
    uint32_t recordAddr = EE_RECORD_ADDR_EMPTY;  /* record header address */
    uint32_t returnCode = EE_OK;   /* Return code */
    
    if(recordID > eeConfig->maxRecordId)
    {
        returnCode = EE_ERROR_REC_ID_OUT_OF_RANGE;
        return returnCode;
    }

    /* Check the write lock */
    if (eeConfig->busyFlag == SET)
    {
        /* EE is busy */
        returnCode = EE_ERROR_BUSY;
    }
    else
    {      
         /* Search in the cache table */
        if(eeConfig->cacheEn == ENABLE)
        {
            returnCode = EE_SearchInCache(eeConfig->cTable, recordID, &recordAddr);            
        }

        /* Search in flash sectors if cache is disable or the record is not in cache */
        if((eeConfig->cacheEn == DISABLE) || (returnCode == EE_ERROR_NOT_IN_CACHE))
        {
            returnCode = EE_SearchInSectors(eeConfig, recordID, &recordAddr,
                                            CallBack);
        }

        /* Read record if found */
        if(returnCode == EE_OK)
        {
            returnCode = EE_InvalidateRecord(recordAddr,CallBack);
            if(returnCode == EE_OK)
            {
                if(eeConfig->cacheEn == ENABLE)
                {
                    EE_UpdateCacheTable(eeConfig->cTable, recordID, 
                                        EE_RECORD_ADDR_DELETED);
                }
            }
        }
        else
        {
            returnCode |= EE_ERROR_DATA_NOT_FOUND;
        }
    }

    return returnCode;
}
void Eep_Init()
{
    uint8_t i = 0U;
    uint32_t ret = ~EE_OK;
    
    /* Initialize eeprom, it will try 3 times if failed */
    while ((i < 3U) && (ret != EE_OK))
    {
        ret = EE_Init(&eeConf, ENABLE, &CallBack);
        i++;
    }
    if(ret != EE_OK)
    {
        ErrorTrap();
    }
}



