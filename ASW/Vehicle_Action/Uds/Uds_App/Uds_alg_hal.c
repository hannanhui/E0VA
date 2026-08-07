/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      C source file                                                            */
/*   Name         :      Uds_alg_hal.c                                                            */
/*   Instance     :                                                                               */
/*   Author       :      Ed                                                                       */
/*   Modify date  :      2025-04-11 11:08:33 AM                                                   */
/*   Description  :                                                                               */
/*                                                                                                */
/*                                                                                                */
/*   Compiler    :       KungFu32 IDE  [Version: V1.0.20.3]                                       */
/*   Hardware    :       ChipOn microcontroller KF32A Family [KF32A136KQT]                        */
/*   Version     :       V1.0                                                                     */
/*                                                                                                */
/*                                                                                                */
/*   All rights reserved. Distribution or duplication without previous written agreement of the   */
/*   owner prohibited.                                                                            */
/*                                                                                                */
/**************************************************************************************************/

#include "include.h"

#include<time.h>
#include<stdlib.h>


BOOL UDS_ALG_HAL_EncryptData(const uint8_t *i_pPlainText, const uint32_t i_dataLen, uint8_t *o_pCipherText)
{
	  BOOL RetVal = FALSE;
	  return RetVal;
}
BOOL UDS_ALG_HAL_DecryptData(const uint8_t *i_pCipherText, const uint32_t i_dataLen, uint8_t *o_pPlainText)
{
    BOOL RetVal = FALSE;
	  return RetVal;
}
/* Random value, seed is 0x12345678 */
static uint32_t u32RandVal = 0x12345678U; 
void fsl_srand (uint32_t u32Seed9)
{
     /* Value 0 is forbidden because it would block the LFSR */
     if (0U == u32Seed9)
     {   /* Forbidden value */
         u32Seed9++; /* Correct the value */
     }
     u32RandVal = u32Seed9; /* Set the seed */
}

/**
* @brief Returns pseudo-random number
* @details Function generates pseudo-random number using the LFSR algorithm.
* @return Pseudo-random number in the interval from 0 to 0xFFFFFFFF
*/
uint32_t fsl_rand(void)
{
    /* Generate the next value in the sequence */
    u32RandVal = (u32RandVal >> 1U) ^ ((0U - (u32RandVal & 1U)) & 0x80200003U);
    /* Return the value */
    return u32RandVal;
}
static uint32_t gs_UDS_SWTimerTickCnt;
/*UDS software timer tick*/
void UDS_ALG_HAL_AddSWTimerTickCnt(void)
{
	if(gs_UDS_SWTimerTickCnt<0xFFFFFFFF)
	{
		gs_UDS_SWTimerTickCnt++;
	}
	else
	{
		gs_UDS_SWTimerTickCnt =1u;
	}
	
}
/*check random is right?*/
uint8_t UDS_ALG_HAL_Check_ReceiveKeyRight(const uint8_t *i_pReceivedKey,
                                const uint8_t *i_pTxSeed,
                                const uint8_t KeyLen)
{
    //uint8_t index = 0u;
    //uint8_t aPlainText[AES_SEED_LEN] = {0u};
	uint16_t  KeyK=0x01E8;
	uint16_t  KeyResult=0,SaccSeed=0,SaccKey=0;
	uint8_t cal_key[AES_SEED_LEN];

	#if 0
    uint8_t cal_key[4];
    //测试简化安全算法，只用一个异或算法简单演示
    for(uint8_t i = 0;i<KeyLen;i++)
    {
        cal_key[i] = (*(i_pTxSeed+i))^0x55;
        if(cal_key[i]!=i_pReceivedKey[i])
        {
            return FALSE;
                
        }
    }
    #else
	SaccSeed=(i_pTxSeed[0]<<8)|i_pTxSeed[1];
    KeyResult= ((((SaccSeed >> 1) ^ SaccSeed) <<3) ^ (SaccSeed >>2));
    SaccKey = KeyResult ^ KeyK;
    cal_key[0]=(SaccKey>>8)&0xff;
    cal_key[1]=SaccKey&0xff;
	for(uint8_t i = 0;i<KeyLen;i++)
    {
        if(cal_key[i]!=i_pReceivedKey[i])
        {
            return FALSE;
                
        }
    }
	#endif
    return TRUE;
}

BOOL UDS_ALG_HAL_GetRandom(const uint32_t i_needRandomDataLen, uint8_t *o_pRandomDataBuf)
{
	BOOL ret = TRUE;
	#if 0
    
	uint8_t index = 0u;
	uint8_t *pRandomTmp = NULL;
	uint32_t random = (uint32_t)&index;
	
	if((0u == i_needRandomDataLen) || (NULL == o_pRandomDataBuf))
	{
		ret = FALSE;
	}

	random = 2000;					//不随机
//	random = TIMER_HAL_GetTimerTickCnt();
	
	random |= (gs_UDS_SWTimerTickCnt << 16u);
	fsl_srand(random);

	if(TRUE == ret)
	{		
		pRandomTmp = (uint8_t *)&random;
		
		for(index = 0u; index < i_needRandomDataLen; index++)
		{
			if(((index & 0x03u) == 0x03u))
			{
				/*get random*/
				random = fsl_rand();
			}
			
			o_pRandomDataBuf[index] = pRandomTmp[index & 0x03];
		}
	}

	#else
	uint32_t random = 0;
	uint16_t useseed = 0;
	uint32_t SrandSeed = 0;
	if((0u == i_needRandomDataLen) || (NULL == o_pRandomDataBuf))
	{
		ret = FALSE;
	}
	SrandSeed = gs_UDS_SWTimerTickCnt;
	srand(SrandSeed);
	random = rand();
	useseed= (random>>16)&0xffff;
	o_pRandomDataBuf[0] =  (useseed>>8)&0xff;
	o_pRandomDataBuf[1] = (useseed>>0)&0xff;
	#endif
	return ret;
}


