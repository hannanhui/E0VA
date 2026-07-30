/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      C source file                                                            */
/*   Name         :      FlashIf.c                                                                */
/*   Instance     :                                                                               */
/*   Author       :      Ed                                                                       */
/*   Modify date  :      2025-12-22 14:00:05 PM                                                   */
/*   Description  :                                                                               */
/*                                                                                                */
/*                                                                                                */
/*   Compiler    :       KungFu32 IDE  [Version: V1.0.20.3]                                       */
/*   Hardware    :       ChipOn microcontroller KF32A Family [KF32A156MQV]                        */
/*   Version     :       V1.0                                                                     */
/*                                                                                                */
/*                                                                                                */
/*   All rights reserved. Distribution or duplication without previous written agreement of the   */
/*   owner prohibited.                                                                            */
/*                                                                                                */
/**************************************************************************************************/
#include "..\CFlash.h"


//#include "Common.h"

#if (BUFFERS_AUTO_ALIGN_ENABLE == 1u)
static uint32_t TempData[(1024 / 4)] = {0};
#endif

static const FLASH_CmdConfig_t flashCfg = 
{
    .act = FLASH_CMD_ACT_WAIT,
#ifdef WATCHDOG_FUNC_EN
    .callBack = FeedWatchdog
#else
    .callBack = NULL   
#endif
};



/**
 *  @brief :Erase N pages. The minimum erasure unit is 1K.
 *             During this period, the whole play will be close !!!
 *             Recovery interrupt at the end !!!
 *  @param[in]
 *              Address :address aligned by 1K
 *                 Length :length like 1024 2048 3072 4096...
 *  @param[out] None
 *  @retval :    CMD_SUCCESS                                    0x00
 *                BUSY                                          0x0B
 *                SECTOR_NOT_PREPARED_FOR_WRITE_OPERATION       0x09
 *                INVALID_SECTOR                                0x07
 */
uint32_t __FlashEraseNPage(volatile unsigned int key,unsigned int Address, unsigned int Length)
{
   uint32_t FlashRetVal, IntState;

    
    return FlashRetVal;
}
uint8_t EraseOneSector(uint32_t addr)
{
	
	uint8_t RetVal=TRUE;
	ResultStatus_t res = SUCC;
	    INT_All_Enable(FALSE);
#ifdef BL_FLASH_DRV_FROM_HOST
    /* MISRA 2012 11.1 */
    res = FLASH_ERASE_SECTOR(addr,&flashCfg);
#else
    res = FLASH_EraseSector(addr,&flashCfg);
#endif
    INT_All_Enable(TRUE);
	if(res == SUCC)
	{
		RetVal=TRUE;
	}
	else
	{
		RetVal=FALSE;
	}
    return RetVal;
}
uint8_t FlashReadOneByte(uint32_t addr)	//读单字节IAP操作
{   
    uint8_t IAP_IapData; 
    IAP_IapData = *(uint32_t *)addr;
	return IAP_IapData;
}





uint8_t FlashIf_Erase_AppRunArea(uint32_t addr)
{
    uint16_t i;
	uint16_t k = 0;

	if(addr==ApplicationAddress)
	{
		k = (APP_SIZE/FLASH_ONE_SECTOR_SIZE);
	}
    else
    {
        return FALSE;
    }
    for(i=0;i<k;i++)
    {
		if(EraseOneSector(addr+FLASH_ONE_SECTOR_SIZE*i)==FALSE)
        {
            return FALSE;
        }        
        //回应流控帧
        if(i%10==9)
        {
            
        }
        
    }
    return TRUE;
}


 uint8_t FlashIf_WritePageByte(uint32_t addr,uint8_t * buff,uint32_t len)	//写多字节IAP操作
{
	
	uint8_t RetVal=TRUE;
	RetVal = FlashIf_WriteMultiByteNoErase(addr,buff,len);
	return RetVal;

}
/**
 *  @brief :Write 8*N bytes.
 *             No Erase .
 *             During this period, the whole play will be close !!!
 *             Recovery interrupt at the end !!!
 *  @param[in]
 *              Address :
 *                 Length :must align by 16,like 16 32 ... 8*N, or aligned by 16*N
 *                 Buffers:input data
 *  @retval :    CMD_SUCCESS                                     0x00
 */
 uint32_t FlashIf_WriteMultiByteNoErase(uint32_t addr,uint8_t * buff,uint32_t len)
{
	uint8_t RetVal=TRUE;
 	ResultStatus_t res = SUCC;
    uint32_t alignedLen;
    uint32_t remained;
    uint32_t writeAddr = addr;
    uint8_t lastData[FLASH_PHRASE_LEN];
    
    if(addr%FLASH_PHRASE_LEN != 0U)
    {
        res = ERR;
    }
    else
    {
        alignedLen = (len/FLASH_PHRASE_LEN)*FLASH_PHRASE_LEN;
        remained = len%FLASH_PHRASE_LEN;
    
       INT_All_Enable(FALSE);
    
        if(alignedLen != 0U)
        {
#ifdef BL_FLASH_DRV_FROM_HOST
            /* MISRA 2012 11.1 */
            if(ERR == FLASH_PROGRAM(writeAddr, alignedLen, buff, flashCfg.callBack))
            {
                res = ERR;
            }    
#else
            if(ERR == FLASH_Program(writeAddr, alignedLen, buff, flashCfg.callBack))
            {
                res = ERR;
            }
#endif
        }
    
        if(res == SUCC)
        {
            writeAddr += alignedLen;
            if(remained != 0U)
            {
                for(uint32_t i = 0U; i < FLASH_PHRASE_LEN; i++)
                {
                    if(i < remained)
                    {
                        lastData[i] = buff[alignedLen+i];
                    }
                    else
                    {
                        lastData[i] = 0xFFU;
                    }
                }
#ifdef BL_FLASH_DRV_FROM_HOST
                /* MISRA 2012 11.1 */
                if(ERR == FLASH_PROGRAM(writeAddr, FLASH_PHRASE_LEN, 
                                       (const uint8_t *)lastData, flashCfg.callBack))
                {
                    res = ERR;
                }  
#else        
                if(ERR == FLASH_Program(writeAddr, FLASH_PHRASE_LEN, 
                                       (const uint8_t *)lastData, flashCfg.callBack))
                {
                    res = ERR;
                }
#endif
            }
        }
    
        INT_All_Enable(TRUE);
    }
    if(res == SUCC)
   	{
		RetVal=TRUE;
	}
	else
	{
		RetVal=FALSE;
	}
    return RetVal;
}

/* check if the address is in flash and can be programmed */
FlagStatus_t FlashCheckValidAddr(uint32_t addr, uint32_t len)
{
    FlagStatus_t res = RESET;
    

    return 0;
}


uint8_t FlashIf_ReadMultiByte(uint32_t addr,uint8_t * buff,uint32_t len)	
{
	for (int i = 0; i < len; i++)
	{
		buff[i] = *(unsigned char *)addr++;
	}
	return TRUE;
}



uint32_t FlashIf_CalCheckSum(uint32_t addr ,uint32_t len )
{
    uint32_t check_sum= 0;
    for(uint8_t i =0;i<len;i=i+4)
    {
        check_sum += *(uint32_t *)(addr+i);
    }
    
    return check_sum;
}

/* check flash init */
ResultStatus_t FlashInit(void)
{
    ResultStatus_t ret = SUCC;
    #ifdef BL_FLASH_DRV_FROM_HOST
        if(1U == flsRegPtr->FLASH_FSTAT.FAIL)
        {
            ret = ERR;
        }
    #else  
        #if (defined(DEV_Z20K118M))|| (defined(DEV_Z20K116M)) || (defined(DEV_Z20K114M))
            if(ERR == Flash_Init())
            {
                ret = ERR;
            }
        #else
            if(ERR == FLASH_Init())
            {
                ret = ERR;
            }
        #endif
    #endif
    return ret;
}


