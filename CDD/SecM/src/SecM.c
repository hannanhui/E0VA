/**
 * @file        SecM.c
 * @brief       AUTOSAR SecM  - SecM driver source file.
 * @details     SecM driver source file, containing the C implementation of Autosar API specification
 *              and other variables and functions that are exported by the SecM driver.
 * @version     1.0.0
 *
 * @addtogroup  SecM
 * @{
 */
/*====================================================================================================*
 * AngHui AUTOSAR BSW.
 *
 * Copyright(C) 2023 GuoKeAngHui Inc.
 *
 * All rights reserved.
 *
 * This file is part of AngHui AUTOSAR BSW, contains proprietary information.
 * Passing on and copying of this document, and communication of its contents
 * is not permitted without prior written authorization.
 *====================================================================================================*/

#ifdef __cplusplus
extern "C"{
#endif

/*====================================================================================================*
 *                                           INCLUDE FILES                                          
 *====================================================================================================*/

#include "SecM.h"
#include "hash.h"
//#include "FBL.h"
#include "Rsa3072.h"
/*====================================================================================================*
 *                                  SOURCE FILE VERSION INFORMATION                                 
 *====================================================================================================*/

/**
* @brief Parameters that shall be published within the SecM driver header file and also in the
*        module's description file
*/
#define SecM_VENDOR_ID_C                    xx
#define SecM_AR_RELEASE_MAJOR_VERSION_C     xx
#define SecM_AR_RELEASE_MINOR_VERSION_C     xx
#define SecM_AR_RELEASE_REVISION_VERSION_C  xx    /* PRQA S 0791 EOF */
#define SecM_SW_MAJOR_VERSION_C             xx
#define SecM_SW_MINOR_VERSION_C             xx
#define SecM_SW_PATCH_VERSION_C             xx

/*====================================================================================================*
 *                                         FILE VERSION CHECKS                                      
 *====================================================================================================*/

/* Add code here */

/*====================================================================================================*
 *                                   EXTERNAL FUNCTION DECLARATIONS                                 
 *====================================================================================================*/

/* Add code here */

/*====================================================================================================*
 *                                           LOCAL TYPEDEFS                                         
 *====================================================================================================*/

/* Add code here */

/*====================================================================================================*
 *                                            LOCAL MACROS                                          
 *====================================================================================================*/

/* Add code here */

/*====================================================================================================*
 *                                           LOCAL CONSTANTS                                        
 *====================================================================================================*/

/* Add code here */

/*====================================================================================================*
 *                                           LOCAL VARIABLES                                        
 *====================================================================================================*/


/*====================================================================================================*
 *                                      LOCAL FUNCTION PROTOTYPES                                   
 *====================================================================================================*/

/* Add code here */

/*====================================================================================================*
 *                                           LOCAL FUNCTIONS                                        
 *====================================================================================================*/

/* Add code here */

/*====================================================================================================*
 *                                          GLOBAL FUNCTIONS                                        
 *====================================================================================================*/
#define RSA3072_KEY_BYTES  384
#define SHA256_DIGEST_LEN   32
#define SIZE4096            4096
extern VAR(FBL_AddressType, AUTOMATIC)  FBL_TranDataAddres ;
extern VAR(FBL_LengthType, AUTOMATIC) FBL_TranDataLength ;
extern P2CONST(uint8,AUTOMATIC,AUTOMATIC) FBL_TranDataBuff;
extern FUNC(void,AUTOMATIC) FBL_FlashWrite(void);
extern FUNC(void,AUTOMATIC) FBL_FlashErase(void);
extern FUNC(void,AUTOMATIC) FBL_MemoryManag
(
	P2VAR(uint8, AUTOMATIC, AUTOMATIC) DestBuffer,
	P2CONST(uint8, AUTOMATIC, AUTOMATIC) SourceBuffer,
	VAR(FBL_LengthType, AUTOMATIC) Length,
	VAR(boolean, AUTOMATIC) DuplicateFlag
);
extern tFlashParam FBL_FlashProgramInfo;
 VAR(FBL_LengthType, AUTOMATIC) HashDataLength ;
VAR(FBL_LengthType, AUTOMATIC) HashAppDataLength;
 uint8* HashDataBuff;
uint8 FBL_MasterSHA[32] = {0};
uint8 FBL_SlaveSHA[32] = {0};
sha256_ctx_t ctx;
/* 公钥模数 N（384 字节，大端） */
static const uint8_t pubKeyN[RSA3072_KEY_BYTES] = {
		0xBB,0x0D,0x04,0x33,0x9F,0xC1,0x5F,0x24,0xB0,0xCA,0x2E,0x98,0x0D,0x44,0x8B,0x0E,
		    0x68,0xA4,0xB8,0xC3,0xE6,0xD7,0x82,0x0D,0x8D,0x20,0xA2,0xE1,0x7D,0x61,0x39,0xDD,
		    0x0C,0x63,0xA6,0x82,0x68,0x8A,0x8A,0x28,0x8C,0xB7,0x45,0xA5,0xB6,0x9C,0xA1,0x15,
		    0xAE,0x48,0x5E,0x89,0x81,0xCC,0xF8,0x44,0xCB,0x27,0x1F,0x67,0x58,0xD5,0x9D,0x4F,
		    0x9B,0x08,0x02,0x40,0x36,0xAD,0x8D,0x84,0xEA,0xCF,0xE6,0x52,0xE4,0xDC,0xB6,0x3B,
		    0x14,0xB1,0x5A,0x9D,0x70,0x45,0xC9,0xD8,0x2C,0x47,0xC9,0x35,0x4E,0x98,0x3F,0xE6,
		    0x8B,0x2A,0xEB,0x36,0xB1,0x77,0xBD,0x0B,0xAA,0x6B,0xD1,0xA7,0x8E,0x11,0x0E,0xDC,
		    0x6C,0xB1,0xE3,0x2C,0xE4,0x53,0x55,0xBC,0x12,0x4D,0xC3,0x18,0x9D,0x79,0x4B,0x23,
		    0x83,0xD7,0xB1,0x4F,0xF4,0x89,0x1A,0xFC,0xBE,0x8A,0x42,0x96,0xD3,0xD2,0x9F,0xAB,
		    0x54,0x57,0x73,0x49,0x20,0xA6,0x02,0x5C,0xB3,0x29,0x53,0x37,0x1B,0x58,0x68,0x9F,
		    0xB0,0xDA,0xDA,0x82,0x41,0xC2,0xE5,0x8A,0x4B,0x61,0x7E,0x3D,0x6E,0x65,0x28,0x24,
		    0x22,0xDD,0x58,0xB2,0x14,0xE4,0x0A,0x00,0x51,0x86,0x81,0x5D,0xB4,0x5F,0x22,0x51,
		    0x00,0x95,0xE9,0x51,0x41,0x5E,0x52,0x37,0x26,0xDC,0xA5,0xD9,0x0E,0x89,0xE7,0xC1,
		    0x52,0xC4,0x3A,0x00,0x9A,0x1A,0xEC,0x85,0x07,0xD7,0x16,0x0F,0x5B,0x48,0x36,0xCE,
		    0xC9,0xBC,0x2C,0xA4,0x8B,0x8C,0xB0,0xD8,0xAD,0xF6,0x6A,0xA0,0x86,0xD7,0x69,0x0E,
		    0x58,0x51,0xD7,0xFF,0x51,0x3D,0x5E,0x7C,0x63,0x1E,0x52,0x70,0x9A,0x43,0xFC,0xFB,
		    0xB2,0xEF,0x22,0xFB,0x8A,0xED,0x1F,0x48,0x64,0x84,0x4D,0x45,0x06,0x9F,0x9A,0x38,
		    0xA3,0x5A,0xB6,0xE5,0x44,0x5F,0xA8,0x68,0x41,0xB1,0x97,0x71,0xC0,0x08,0x8B,0x2A,
		    0x62,0x82,0x79,0x38,0x9C,0x31,0xE2,0xD3,0xE5,0x02,0x8F,0xE3,0x15,0xD0,0xD4,0xC1,
		    0x63,0x88,0xF3,0x67,0xE8,0xCE,0x8E,0xAE,0xDB,0x3E,0xB5,0xE3,0xDE,0x6D,0xDF,0xAB,
		    0xDF,0x6A,0x8A,0x7A,0x39,0x2F,0x5E,0x04,0xD9,0x21,0xF0,0xF5,0xA2,0x9D,0xEF,0xF9,
		    0x69,0x56,0x61,0xA6,0xFF,0xFB,0x7E,0x85,0xC6,0x1B,0xFA,0xB8,0x33,0x1A,0x63,0x16,
		    0xBD,0x23,0xEB,0xF6,0x84,0x79,0x96,0xA8,0xEA,0x52,0x7B,0x37,0xAF,0x4E,0x12,0x67,
		    0x2E,0x63,0x8C,0x74,0xBB,0x40,0x8A,0xA6,0x95,0x11,0xE3,0x16,0x67,0x47,0x6F,0x21
};

/* 公钥指数 E（通常为 0x01 0x00 0x01，3 字节） */
static const uint8_t pubKeyE[3] = { 0x01, 0x00, 0x01};


 P2VAR(uint8, AUTOMATIC, FBL) Decomp_OutputAdd;
 VAR(uint16, AUTOMATIC) Decomp_Outputlens;
 VAR(LZSS_GetStatus, AUTOMATIC) Decomp_Outputstatus;
/**
 * @sid				   0x00
 * @brief              The service calls the function interface to calculate.
 * @details			   Call the CRC the function interface to calculate the specified data.
 * @param[in]      	   SecmCrcPtr:	This parameter contains the relevant data for the check.
 * @param[out]     	   SecmCrcPtr
 * @return             ret
 */
FUNC(Std_ReturnType,AUTOMATIC) SecM_CreatCrc
(
	P2VAR(SecM_CheckState,AUTOMATIC,AUTOMATIC) CheckState,
	P2CONST(uint8,AUTOMATIC,AUTOMATIC) CheckBuffer,
	VAR(uint32, AUTOMATIC) CheckLength
)
{
    VAR(Std_ReturnType,AUTOMATIC) ret = E_NOT_OK;

    if((CheckState != NULL_PTR) && (CheckBuffer != NULL_PTR) && (CheckLength > 0U))
    {
#if(STD_ON == CRC32_ALGORITHM)
		CheckState->CrcCheckSum = Crc_CalculateCRC32(CheckBuffer,\
				CheckLength,CheckState->CrcCheckSum,CheckState->CrcFirstCall);
#endif

#if(STD_ON == CRC16_ALGORITHM)
		CheckState->CrcCheckSum = Crc_CalculateCRC16(CheckBuffer,\
				CheckLength,CheckState->CrcCheckSum,CheckState->CrcFirstCall);
#endif

		if(CheckState->CrcFirstCall == (boolean)TRUE)
		{
			CheckState->CrcFirstCall =(boolean)FALSE;
		}

		ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }
    return ret;
}

/**
 * @sid				   0x01
 * @brief              The service is calibrated and compared to the calculated value.
 * @details			   The service is calibrated and compared to the calculated value.
 * @param[in]      	   VerifyData:	This parameter contains the relevant data for the check.
 * @param[out]     	   None
 * @return             ret
 */
FUNC(Std_ReturnType,AUTOMATIC) SecM_SofawareCheck
(
	P2CONST(FBL_SegmentPhyInfoType,AUTOMATIC,AUTOMATIC) SegmentInfo,
	P2VAR(SecM_CheckState,AUTOMATIC,AUTOMATIC) CheckState
)
{
    VAR(Std_ReturnType,AUTOMATIC) ret = E_OK;
    VAR(uint32,AUTOMATIC) u32SegmentAdder;
    VAR(uint32,AUTOMATIC) u32SegmentLength;
    VAR(uint8,AUTOMATIC) CheckDataBuffer[SECM_CHECK_DATA_LENGTH];

    if((SegmentInfo != NULL_PTR) && (CheckState != NULL_PTR))
    {
		u32SegmentAdder = SegmentInfo->SegmentAddre;

		u32SegmentLength = SegmentInfo->SegmentLength;

		while((u32SegmentLength > 0U) && (ret == E_OK))
		{
			if(u32SegmentLength > (uint32)SECM_CHECK_DATA_LENGTH)
			{
				ret = SecM_CreatCrc(CheckState,CheckDataBuffer,(uint32)SECM_CHECK_DATA_LENGTH);

				u32SegmentLength -= (uint32)SECM_CHECK_DATA_LENGTH;

				u32SegmentAdder += (uint32)SECM_CHECK_DATA_LENGTH;
			}
			else
			{
				ret = SecM_CreatCrc(CheckState,CheckDataBuffer,u32SegmentLength);
				u32SegmentLength = 0U;
			}
		}

		if((ret == E_OK) && (CheckState->CrcCheckSum == SegmentInfo->SegmentCrcCheck))
		{

		}
		else
		{
			ret = E_NOT_OK;
		}
    }
    else
    {
						ret = E_NOT_OK;
    }

    return ret;
}


void SHA_Init()
{
	//清除SHA
	sha_init(&ctx);
	HashDataLength = 0;
	HashAppDataLength =0;
}

FUNC(Std_ReturnType,AUTOMATIC) SHA_Calculate()
{
	Std_ReturnType  ret = E_NOT_OK;
	//SHA连续计算解压后的数据
	sha_update(&ctx, HashDataBuff, HashDataLength);
	/*pxc*/
	ret = E_OK;
	return  ret ;
}

void  SHA_Finish(void)
{
	//完成SHA计算，输出哈希
	sha_final(&ctx, FBL_SlaveSHA);
}


void  SHA_Continue_Calculate(void)
{
	int i , AppLength ,Index= 0;
	uint32 CalculateAdd = FBL_BM_SOFTWARE_ADDR;
	uint8 TempBuff[SIZE4096] ;

	/*解压后得到APP总长度*/
	AppLength = HashAppDataLength - FBL_BM_SOFTWARE_ADDR;

	SHA_Init();
	uint8 buffer[8];
	buffer[0] = (uint8)(CalculateAdd>>24);
	buffer[1] = (uint8)(CalculateAdd>>16);
	buffer[2] = (uint8)(CalculateAdd>>8);
	buffer[3] = (uint8)(CalculateAdd);
	buffer[4] = (uint8)(AppLength>>24);
	buffer[5] = (uint8)(AppLength>>16);
	buffer[6] = (uint8)(AppLength>>8);
	buffer[7] = (uint8)(AppLength);
	sha_update(&ctx, buffer, 8);
	
	sha_update(&ctx, (uint8*)FBL_BM_SOFTWARE_ADDR, AppLength);

	//完成SHA计算，输出哈希
	sha_final(&ctx, FBL_SlaveSHA);
}




//解压，记录解压前后的长度
FUNC(Std_ReturnType,AUTOMATIC) LZSS_Calculate()
{
	Std_ReturnType  ret = E_NOT_OK;
	 VAR(InjectStatus,AUTOMATIC) ret_01;


	ret_01 = 	LZSS_InjectCompressedData(FBL_TranDataBuff, (uint16)FBL_TranDataLength);//注入数据
	if(ret_01 == INJECT_OK)
	{  
		LZSS_GetDecompressedData(&Decomp_OutputAdd, &Decomp_Outputlens, &Decomp_Outputstatus);  //注入后拿第一包数据数据  
		if((Decomp_Outputstatus != LZSS_GET_FAIL_NOT_ENOUGH) && (Decomp_Outputlens != 0U))
		{
			HashDataBuff = Decomp_OutputAdd;
			HashDataLength = Decomp_Outputlens;

			FBL_TranDataBuff = Decomp_OutputAdd;
			FBL_TranDataLength = Decomp_Outputlens;
			FBL_FlashWrite();

		}
		else
		{ //数据解压没有满
			ret = (Std_ReturnType)FBL_NOT_OK;
		}
	}
	else
	{
		ret = (Std_ReturnType)FBL_NOT_OK;
	}
do 
{
		LZSS_ContinueDecompress(&Decomp_Outputstatus);
		if(Decomp_Outputstatus != LZSS_GET_FAIL_NOT_ENOUGH)
		{
			LZSS_GetDecompressedData(&Decomp_OutputAdd, &Decomp_Outputlens, &Decomp_Outputstatus);    
			if((Decomp_Outputstatus != LZSS_GET_FAIL_NOT_ENOUGH) && (Decomp_Outputlens != 0U))
			{
				HashDataBuff = Decomp_OutputAdd;
				HashDataLength = Decomp_Outputlens;

				FBL_TranDataBuff = Decomp_OutputAdd;
				FBL_TranDataLength = Decomp_Outputlens;
				FBL_FlashWrite();
//				FBL_TranDataAddres += Decomp_Outputlens;
				if (Decomp_Outputstatus == LZSS_GET_END_OF_STREAM)
				{
					break;
				}
			}
			else
			{
				if ((Decomp_Outputstatus == LZSS_GET_END_OF_STREAM) && (Decomp_Outputlens == 0U))
				{
					break;
				}

			}
		}
		else 
		{
			
		}
}while((Decomp_Outputstatus != LZSS_GET_FAIL_NOT_ENOUGH));

	return  ret ;
}

/* RSA解密后，对比原始哈希与计算的哈希  */
FUNC(Std_ReturnType,AUTOMATIC) RSA_Calculate(uint8 *RawShaData)
{
	Std_ReturnType  ret = E_NOT_OK;
	uint8_t recoveredHash[32];
    ret = Rsa3072PssVerify(
    		FBL_SlaveSHA, SHA256_DIGEST_LEN,
			RawShaData, RSA3072_KEY_BYTES,
			pubKeyN, RSA3072_KEY_BYTES,
        pubKeyE, sizeof(pubKeyE),
        NULL, NULL,
        recoveredHash);

		if (ret == E_OK)
		{
			ret = E_OK;
		}
		else
		{
			ret = 0x02;
		}
	
	return  ret ;
}



#ifdef __cplusplus
}
#endif
/** @} */
