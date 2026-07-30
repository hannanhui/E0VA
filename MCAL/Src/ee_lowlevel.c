/***************************************************************************//**
 * @file     ee_lowlevel.c
 * @brief    This file provides low level functions used by eeprom emulation .
 * @version  V1.3
 * @date     May-2021
 * @author   Zhixin Semiconductor
 *
 * @note
 * Copyright (C) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 *
 ******************************************************************************/
#include "eep_emulation.h"




#if (defined(DEV_Z20K148M)) || (defined(DEV_Z20K146M))||(defined(DEV_Z20K144M))
#include "flash_drv.h"
#include "scm_drv.h"
#define SCM        ((scm_reg_t *) SCM_BASE_ADDR)        /*!< scm Register */   
#else
#include "Z20K11xM_flash.h"
#endif



#include "string.h"
#include "ee_lowlevel.h"

#define FLASHC      ((flash_reg_t *) FLASHC_BASE_ADDR)     /*!< flash controller Register */


/***************************************************************************!
 * @brief: This API is used to read data from flash. 
 *
 * @param[in] addr: the start address of data to be read out. 
 * @param[in] buffer: points to a buffer where the read-out data to be stored
 * @param[in] size: the size to be read out in byte.
 * @param[in]  CallBack: it points to a function to service the time critical 
 *                       events. Any code reachable from this function
 *                       must not be placed in the same Flash block as the 
 *                       EEPROM emulation
 *
 * @return EE_OK
 *         EE_ERROR_ECC: ECC error when read flash
 *
 ****************************************************************************/
uint32_t EE_FlashRead(uint32_t addr, uint8_t * buffer, uint32_t size,
                      void (*CallBack)(void))
{
    uint32_t returnCode = EE_OK;
    uint32_t counter;
    uint32_t alignedCnt, unalignedCnt;
    uint32_t buf32 = (uint32_t)buffer;
    uint32_t offset = 0U;
    
    /* Clear the double-bit ECC flag before reading */
    FLASH_IntClear(FLASH_INT_DFDIF);

    if((addr % 4U == 0U) && ((uint32_t)buffer % 4U == 0U))
    {
        alignedCnt = size >> 2U;
        unalignedCnt = size % 4U;
        
        for(counter = 0U; counter < alignedCnt; counter++)
        {
            /* Callback service */
            if ((counter % EE_CALLBACK_READ_BYTES_NUM) == 0U)
            {
                if (CallBack != NULL)
                {
                    CallBack();
                }
            }
            
            *(uint32_t *)(buf32 + offset) = *(uint32_t *)(addr + offset);
            offset += 4U;
        }
        
        for(counter = 0U; counter < unalignedCnt; counter++)
        {
            buffer[offset] = *(uint8_t *)(addr + offset);
            offset++;
        }
        
        if(FLASHC->FLASH_FSTAT.DFDIF  == 1U)
        {
            FLASH_IntClear(FLASH_INT_DFDIF);
            returnCode = EE_ERROR_ECC;
        }        
    }
    else
    {
        /* Read data */
        for (counter = 0U; counter < size; counter++)
        {
            /* Callback service */
            if ((counter % EE_CALLBACK_READ_BYTES_NUM) == 0U)
            {
                if (CallBack != NULL)
                {
                    CallBack();
                }
            }
        
            buffer[counter] = *(uint8_t *)(addr + counter);
        }
    
        if(FLASHC->FLASH_FSTAT.DFDIF  == 1U)
        {
            FLASH_IntClear(FLASH_INT_DFDIF);
            returnCode = EE_ERROR_ECC;
        }
    }

    return returnCode;
}

/***************************************************************************!
 * @brief: This API is used to read data from flash by word. 
 *
 * @param[in] addr: the start address of data to be read out. It must aligned 
 *                  to 32 bit.
 * @param[in] buffer: points to a buffer where the read-out data to be stored
 * @param[in] size: the size to be read out in word.
 * @param[in]  CallBack: it points to a function to service the time critical 
 *                       events. Any code reachable from this function
 *                       must not be placed in the same Flash block as the 
 *                       EEPROM emulation
 *
 * @return EE_OK
 *         EE_ERROR_ECC: ECC error when read flash
 *
 ****************************************************************************/
uint32_t EE_FlashReadByWord(uint32_t addr, uint32_t *buffer, uint32_t size,
                            void (*CallBack)(void))
{
    uint32_t returnCode = EE_OK;
    uint32_t counter;
    
    /* Clear the double-bit ECC flag before reading */
    FLASH_IntClear(FLASH_INT_DFDIF);

    /* Read data */
    for (counter = 0U; counter < size; counter++)
    {
        /* Callback service */
        if ((counter % EE_CALLBACK_READ_BYTES_NUM) == 0U)
        {
            if (CallBack != NULL)
            {
                CallBack();
            }
        }
        
        buffer[counter] = *(uint32_t *)(addr + counter*4U);
    }
    
    if(FLASHC->FLASH_FSTAT.DFDIF  == 1U)
    {
        FLASH_IntClear(FLASH_INT_DFDIF);
        returnCode = EE_ERROR_ECC;
    }

    return returnCode;
}

/***************************************************************************!
 * @brief: This API is used to read a word from flash.. 
 *
 * @param[in] addr: the address of phrase to be read out. It is required to be
 *                  phase aligned.
 * @param[in] word: points to a buffer where the read-out data to be stored

 *
 * @return EE_OK
 *         EE_ERROR_ECC: ECC error when read flash
 *
 ****************************************************************************/
uint32_t EE_FlashReadWord(uint32_t addr, uint32_t * word)
{
    uint32_t returnCode = EE_OK;
    uint32_t tmp;
    
    *word = 0U;
    
    /* Clear the double-bit ECC flag before reading */
    FLASH_IntClear(FLASH_INT_DFDIF);
    
    if(addr % 4U == 0U)
    {
        *word = *(uint32_t *)addr;
    }
    else
    {
        tmp = *(uint8_t *)(addr + 3U);
        *word |= (tmp << 24U);
        tmp = *(uint8_t *)(addr + 2U);
        *word |= (tmp << 16U);
        tmp = *(uint8_t *)(addr + 1U);
        *word |= (tmp << 8U);
        *word |= *(uint8_t *)(addr);
    }
 
    if(FLASHC->FLASH_FSTAT.DFDIF  == 1U)
    {
        FLASH_IntClear(FLASH_INT_DFDIF);
        returnCode = EE_ERROR_ECC;
    }

    return returnCode;
}

/***************************************************************************!
 * @brief: This API is used to read a halfword from flash. 
 *
 * @param[in] addr: the address of phrase to be read out. It is required to be
 *                  phase aligned.
 * @param[in] halfWord: points to a buffer where the read-out data to be stored

 *
 * @return EE_OK
 *         EE_ERROR_ECC: ECC error when read flash
 *
 ****************************************************************************/
uint32_t EE_FlashReadHalfWord(uint32_t addr, uint16_t * halfWord)
{
    uint32_t returnCode = EE_OK;
    uint16_t tmp;
    
    *halfWord = 0U;
    
    /* Clear the double-bit ECC flag before reading */
    FLASH_IntClear(FLASH_INT_DFDIF);
    
    if(addr % 2U == 0U)
    {
        *halfWord = *(uint16_t *)addr;
    }
    else
    {
        tmp = *(uint8_t *)(addr + 1U);
        *halfWord |= (tmp << 8U);
        *halfWord |= *(uint8_t *)(addr);
    }
 
    if(FLASHC->FLASH_FSTAT.DFDIF  == 1U)
    {
        FLASH_IntClear(FLASH_INT_DFDIF);
        returnCode = EE_ERROR_ECC;
    }

    return returnCode;
}

/***************************************************************************!
 * @brief: This API is used to check if flash data is 0xFF. 
 *
 * @param[in] addr: the address of phrase to be read out. It is required to be
 *                  phase aligned.
 * @param[in] size: the size to be checked in byte.
 * @param[out] blankFlag: the check result is stored in blankFlag by this function.
 * @param[in]  CallBack: it points to a function to service the time critical 
 *                       events. Any code reachable from this function
 *                       must not be placed in the same Flash block as the 
 *                       EEPROM emulation
 *
 * @return EE_OK
 *         EE_ERROR_ECC: ECC error when read flash
 *
 ****************************************************************************/
uint32_t EE_FlashBlankCheck(uint32_t addr, uint32_t size, 
                            FlagStatus_t *blankFlag, void (*CallBack)(void))
{
    uint32_t returnCode = EE_OK;
    uint32_t counter;
    uint32_t unalignedLen;
    uint32_t lenToCheck, restLen, addrToCheck;
    ResultStatus_t tmp;
    FLASH_CmdConfig_t cmdConfig = {
                                   FLASH_CMD_ACT_WAIT,
                                   CallBack
                                  };
    
    *blankFlag = SET;
    
    unalignedLen = (EE_FL_PHRASE_SIZE - addr%EE_FL_PHRASE_SIZE)%EE_FL_PHRASE_SIZE;
    
    /* Clear the double-bit ECC flag before reading */
    FLASH_IntClear(FLASH_INT_DFDIF);

    lenToCheck = (unalignedLen > size)? size:unalignedLen;
    for (counter = 0U; counter < lenToCheck; counter++)
    {
        /* Callback service */
        if ((counter % EE_CALLBACK_READ_BYTES_NUM) == 0U)
        {
            if (CallBack != NULL)
            {
                CallBack();
            }
        }
        
        if(0xFFU != *(uint8_t *)(addr + counter))
        {
            *blankFlag = RESET;
        }
    
        if(FLASHC->FLASH_FSTAT.DFDIF  == 1U)
        {
            FLASH_IntClear(FLASH_INT_DFDIF);
            returnCode = EE_ERROR_ECC;
            return returnCode;
        }
    }
    
    if(CallBack != NULL)
    {
        CallBack();
    }
    
    restLen = size - lenToCheck;
    addrToCheck = addr + lenToCheck;
    if(restLen != 0U)
    {
        for(counter = 0U; counter < restLen/EE_FL_PHRASE_SIZE; counter++)
        {
            tmp = FLASH_VerifyPhrase(addrToCheck + counter*EE_FL_PHRASE_SIZE,
                                     &cmdConfig);
            
            if(tmp != SUCC)
            {
                *blankFlag = RESET;
            }
        }
        
        if(restLen%EE_FL_PHRASE_SIZE != 0U)
        {
            restLen -= counter*EE_FL_PHRASE_SIZE;
            addrToCheck += counter*EE_FL_PHRASE_SIZE;
            
            for (counter = 0U; counter < restLen; counter++)
            {
                 /* Callback service */
                if ((counter % EE_CALLBACK_READ_BYTES_NUM) == 0U)
                {
                    if (CallBack != NULL)
                    {
                        CallBack();
                    }
                }
        
                if(0xFFU != *(uint8_t *)(addrToCheck + counter))
                {
                    *blankFlag = RESET;
                }
    
                if(FLASHC->FLASH_FSTAT.DFDIF  == 1U)
                {
                    FLASH_IntClear(FLASH_INT_DFDIF);
                    returnCode = EE_ERROR_ECC;
                }
            }
        }        
    }   

    return returnCode;
}

/***************************************************************************!
 * @brief: This API is used to check if flash data is equal to expected value 
 *
 * @param[in] addr: the address of data to be check
 * @param[in] src: the buffer which storeds the expected value.
 * @param[in] len: length of data to be checked.
 * @param[in] flag: if data are equal to expected value, flag is SET, otherwise
 *                  flash is RESET.
 * @param[in] CallBack: it points to a function to service the time critical 
 *                       events. Any code reachable from this function
 *                       must not be placed in the same Flash block as the 
 *                       EEPROM emulation
 *
 * @return EE_OK
 *         EE_ERROR_ECC: ECC error when read flash
 *
 ****************************************************************************/
uint32_t EE_DataCheck(uint32_t addr, const uint8_t *buf, uint32_t len,
                      FlagStatus_t *flag, void (*CallBack)(void))
{
    uint32_t returnCode = EE_OK;
    uint32_t counter;
    
    *flag = SET;
    
    /* Clear the double-bit ECC flag before reading */
    FLASH_IntClear(FLASH_INT_DFDIF);

    for (counter = 0U; counter < len; counter++)
    {
        /* Callback service */
        if ((counter % EE_CALLBACK_READ_BYTES_NUM) == 0U)
        {
            if (CallBack != NULL)
            {
                CallBack();
            }
        }
        
        if(buf[counter] != *(uint8_t *)(addr + counter))
        {
            *flag = RESET;
        }
    
        if(FLASHC->FLASH_FSTAT.DFDIF  == 1U)
        {
            FLASH_IntClear(FLASH_INT_DFDIF);
            returnCode = EE_ERROR_ECC;
            break;
        }
    }

    return returnCode;
}
        
/***************************************************************************!
 * @brief: This API erases an EE sector 
 *
 * @param[in] addr: the address EE sector to be verified.
 * @param[in] size: the size of EE sector
 * @param[in]  CallBack: it points to a function to service the time critical 
 *                       events. Any code reachable from this function
 *                       must not be placed in the same Flash block as the 
 *                       EEPROM emulation
 *
 * @return EE_OK
 *         EE_ERROR_INPUT_PARA: input parameter are invalid
 *         EE_ERROR_FLASH_ERR
 *
 ****************************************************************************/
extern ResultStatus_t FLASH_EraseDflashSector(uint32_t addr, const FLASH_CmdConfig_t *config);
uint32_t EE_SectorErase(uint32_t addr, uint32_t size, void (*CallBack)(void))
{
    uint32_t returnCode = EE_OK;
    uint32_t counter;
    ResultStatus_t tmp;
    FLASH_CmdConfig_t cmdConfig =
    {
        FLASH_CMD_ACT_WAIT,
        CallBack
    };
    
    if((addr % EE_FL_SECTOR_SIZE != 0U) || (size % EE_FL_SECTOR_SIZE != 0U))
    {
        returnCode = EE_ERROR_INPUT_PARA;
        return returnCode;
    }

    for(counter = 0U; counter < size/EE_FL_SECTOR_SIZE; counter++)
    {           
        tmp = FLASH_EraseDflashSector(addr + counter*EE_FL_SECTOR_SIZE, &cmdConfig);
        
#if (defined(DEV_Z20K148M)) || (defined(DEV_Z20K146M))||(defined(DEV_Z20K144M))
        /* if cache is enable */
        if(0U == SCM->SCM_MISCCTL1.CACHE_DIS)
        {
            SCM_CacheClr();
        }
#endif
        
        if(tmp != SUCC)
        {
            returnCode = EE_ERROR_FLASH_ERR;
        }
    }        
       
    return returnCode;
}

/***************************************************************************!
 * @brief: This API is used to write data into flash. If the size of data is not
 *         multiple of phrase size. It will be padded with 0xFF.
 *         
 *
 * @param[in] srcAddr: the address of source data to be written into flash
 * @param[in] len: the size of data to be written.
 * @param[in] srcInFlash: it indicates if the location of data to be written
 *                         is in FLASH.
 *                         - 1: in flash
 *                         - 0: not in flash
 * @param[in] addr: the start address to be written to. It is required to be 
 *                  phrase-aligned.
 * @param[in] CallBack: it points to a function to service the time critical 
 *                       events. Any code reachable from this function
 *                       must not be placed in the same Flash block as the 
 *                       EEPROM emulation
 *
 * @return SUCC
 *         ERR
 *
 ****************************************************************************/
extern ResultStatus_t FLASH_ProgramDflashPhrase(uint32_t flashAddr, const uint8_t *dataP, 
                                   const FLASH_CmdConfig_t *config);


uint32_t EE_FlashWriteWithPadding(uint32_t srcAddr, uint32_t len, 
                                  uint32_t srcInFlash, uint32_t addr, 
                                  void (*CallBack)(void))
{
    uint32_t returnCode = EE_OK;
    uint32_t alignedLen;
    uint32_t remaind;
    uint32_t writeAddr = addr;
    uint32_t readAddr = srcAddr;
    uint8_t buf[EE_FL_PHRASE_SIZE];
    FLASH_CmdConfig_t config = 
    {
        FLASH_CMD_ACT_WAIT,
        CallBack
    };
    
    if(addr%EE_FL_PHRASE_SIZE != 0U)
    {
        returnCode = EE_ERROR_INPUT_PARA;
    }
    else
    {        
        alignedLen = (len / EE_FL_PHRASE_SIZE) * EE_FL_PHRASE_SIZE;
        remaind = len % EE_FL_PHRASE_SIZE;
    
        while(alignedLen != 0U)
        {
            if(srcInFlash == 1U)
            {
                returnCode = EE_FlashRead(readAddr, buf, EE_FL_PHRASE_SIZE,
                                          CallBack);
                if(returnCode != EE_OK)
                {
                    return EE_ERROR_READ_ECC;
                }
                
                if(ERR == FLASH_ProgramDflashPhrase(writeAddr, buf, &config))
                {
                    returnCode = EE_ERROR_FLASH_ERR;
                }
            }
            else
            {
                if(ERR == FLASH_ProgramDflashPhrase(writeAddr, (uint8_t *)readAddr, &config))
                {
                    returnCode = EE_ERROR_FLASH_ERR;
                }
            }            
            
            alignedLen -= EE_FL_PHRASE_SIZE;
            readAddr += EE_FL_PHRASE_SIZE;
            writeAddr += EE_FL_PHRASE_SIZE;
        }
        
#if (defined(DEV_Z20K148M)) || (defined(DEV_Z20K146M))||(defined(DEV_Z20K144M))
        /* if cache is enable */
        if(0U == SCM->SCM_MISCCTL1.CACHE_DIS)
        {
            SCM_CacheClr();
        }
#endif
        if(returnCode == EE_OK)
        {
            if(remaind != 0U)
            {
                if(srcInFlash == 1U)
                {
                    returnCode = EE_FlashRead(readAddr, buf, remaind, CallBack);
                    if(returnCode != EE_OK)
                    {
                        return EE_ERROR_READ_ECC;
                    }
                }
                else
                {
                    for(uint32_t i = 0U; i < remaind; i++)
                    {
                        buf[i] = *(uint8_t*)(readAddr + i);
                    }
                }
            
                for(uint32_t i = remaind; i < EE_FL_PHRASE_SIZE; i++)
                {
                    buf[i] = 0xFFU;
                }
        
                if(ERR == FLASH_ProgramDflashPhrase(writeAddr, (const uint8_t *)buf, &config))
                {
                    returnCode = EE_ERROR_FLASH_ERR;
                }
            }
        }
    }
    
#if (defined(DEV_Z20K148M)) || (defined(DEV_Z20K146M))||(defined(DEV_Z20K144M))
        /* if cache is enable */
        if(0U == SCM->SCM_MISCCTL1.CACHE_DIS)
        {
            SCM_CacheClr();
        }
#endif
    
    return returnCode;
}

/***************************************************************************!
 * @brief: This API is used to check if sram data is equal to a value. 
 *
 * @param[in] buf: points to the data to be checked
 * @param[in] size: the size to be checked in word.
 * @param[in] value: value to compare with
 *
 * @return RESET - not equal
 *         SET - equal
 *
 ****************************************************************************/
FlagStatus_t EE_SramCheckByWord(uint32_t *buf, uint32_t size, uint32_t value)
{
    uint32_t i;
    
    for(i = 0U; i< size; i++)
    {
        if(buf[i] != value)
        {
            return RESET;
        }
    }
    
    return SET;
}

