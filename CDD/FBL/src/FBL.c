/**
 * @file        FBL.c
 * @brief       AUTOSAR FBL  - FBL driver source file.
 * @details     FBL driver source file, containing the C implementation of Autosar API specification
 *              and other variables and functions that are exported by the FBL driver.
 * @version     1.0.0
 *
 * @addtogroup  FBL
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
#include "BM.h"
#include "flash_drv.h"
#include "eep_emulation.h"
#include "hash.h"


/*====================================================================================================*
 *                                  SOURCE FILE VERSION INFORMATION                                 
 *====================================================================================================*/

/**
* @brief Parameters that shall be published within the FBL driver header file and also in the
*        module's description file
*/
#define FBL_VENDOR_ID_C                    xx
#define FBL_AR_RELEASE_MAJOR_VERSION_C     xx
#define FBL_AR_RELEASE_MINOR_VERSION_C     xx
#define FBL_AR_RELEASE_REVISION_VERSION_C  xx  /* PRQA S 0791 EOF  */
#define FBL_SW_MAJOR_VERSION_C             xx
#define FBL_SW_MINOR_VERSION_C             xx
#define FBL_SW_PATCH_VERSION_C             xx

#define STATIC static

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

extern VAR(FBL_LengthType, AUTOMATIC) HashAppDataLength;

/* flash operation state */
typedef enum
{
	/* When initialization, wait for flash drive download  */
	FBL_WAIT_DOWNLOAD_STATE = 0,
	/* When the flash driver downloads, the state becomes download state  */
	FBL_DOWNLOAD_STATE,
	/* After the flash drive download is complete, the check initialization is checked  */
	FBL_WAIT_INIT_STATE,
	/* Flash drive erase state */
    FBL_ERARE_STATE,
	/* Flash writes app data operations */
	FBL_WRITE_STATE,
	/* Flash writes app data operations */
	FBL_CHECK_STATE,
	/*Flash is a data validation operation*/
	FBL_IDIE_STATE
} FBL_FlashOperationStateType;

/* flash drive state */
typedef enum
{
	/* Flash drive valid  */
	FBL_FLASH_DRIVE_VALID = 0,
    /* Flash drive  nullity */
	FBL_FLASH_DRIVE_INVALID
} FBL_FlashDriveType;

/*====================================================================================================*
 *                                            LOCAL MACROS                                          
 *====================================================================================================*/

/**
 * @brief Get the beginning address of the logical block
 */

#define FBL_APP_LOGIC_BLOCK_ADRESS(Index) \
	FBL_AppProgramInfo.FBL_LogicalBlInfo.FBL_LogicalBlPhyInfo[Index].BlockAddress

/**
 * @brief Get length of the logical block
 */
#define FBL_APP_LOGIC_BLOCK_LENGTH(Index) \
	FBL_AppProgramInfo.FBL_LogicalBlInfo.FBL_LogicalBlPhyInfo[Index].BlockLength

/**
 * @brief Get status of the logical block
 */
#define FBL_APP_LOGIC_BLOCK_STATUE(Index) \
	FBL_AppProgramInfo.FBL_LogicalBlInfo.FBL_LogicalBlPhyInfo[Index].BlockStatue

/**
 * @brief Get the CRC check value of the logical block
 */
#define FBL_APP_LOGIC_BLOCK_CRCCHECK(Index) \
	FBL_AppProgramInfo.FBL_LogicalBlInfo.FBL_LogicalBlPhyInfo[Index].BlockCrcCheck

/**
 * @brief Get the processing number of logical blocks
 */
#define FBL_APP_LOGIC_BLOCK_PRONUM(Index) \
	FBL_AppProgramInfo.FBL_LogicalBlInfo.FBL_LogicalBlPhyInfo[Index].BlockProNum

/**
 * @brief Get the segment information in the logical block
 */
#define FBL_APP_LOGIC_BLOCK_SEGMENTINFO(Index) \
	FBL_AppProgramInfo.FBL_LogicalBlInfo.FBL_LogicalBlPhyInfo[Index].FBL_SegmentInfo

/**
 * @brief Get the beginning address of the segment of the logical block
 */
#define FBL_APP_SEGMENT_ADDRESS(Index) \
	FBL_AppProgramInfo.FBL_LogicalBlInfo.FBL_LogicalBlPhyInfo[Index].FBL_SegmentInfo.SegmentAddre

/**
 * @brief Get the length of the segment in the logical block
 */
#define FBL_APP_SEGMENT_LENGTH(Index) \
	FBL_AppProgramInfo.FBL_LogicalBlInfo.FBL_LogicalBlPhyInfo[Index].FBL_SegmentInfo.SegmentLength

/**
 * @brief Get the check value of the segment in the logical block
 */
#define FBL_APP_SEGMENT_CRCCHECK(Index) \
	FBL_AppProgramInfo.FBL_LogicalBlInfo.FBL_LogicalBlPhyInfo[Index].FBL_SegmentInfo.SegmentCrcCheck



/*====================================================================================================*
 *                                           LOCAL CONSTANTS                                        
 *====================================================================================================*/

extern boolean ProgDependencies;
extern boolean F15AIsWrite;
extern uint32 appValFlagData;
extern uint8 Read_Actual_Lengh;

extern VAR(FBL_LengthType, AUTOMATIC) HashDataLength ;
extern  uint8* HashDataBuff;
extern sha256_ctx_t ctx;

/*====================================================================================================*
 *                                           LOCAL VARIABLES                                        
 *====================================================================================================*/

/*  The app was erased from success  */
STATIC VAR(boolean, AUTOMATIC) FBL_ErasingSuccess;

/* The error mark is set to true when the error occurs   */
STATIC VAR(boolean, AUTOMATIC) FBL_ErrorMark;

/* Uds call step */
STATIC VAR(uint8, AUTOMATIC) FBL_UDSCallStep;

/* Current logic block  */
STATIC VAR(uint8, AUTOMATIC) FBL_CurrentBlIndex = 0U;

STATIC VAR(uint8,AUTOMATIC) SegmentNum = 0U;

/* 36 data buffer of the service transmission  */
 P2CONST(uint8,AUTOMATIC,AUTOMATIC) FBL_TranDataBuff = NULL_PTR;

/*  error condition [status]   */
STATIC VAR(Std_ReturnType, AUTOMATIC) FBL_ErrorStatus;

/* Temporary (temporary) value for the temporary storage of the results of the  */
STATIC VAR(uint32, AUTOMATIC) FBL_TempCrc = 0U;

/* Transmission of the value  */
VAR(uint32, AUTOMATIC) FBL_TranCrcData = 0U;     //ֻ�е��������������֤ͨ��(��������crc_sum���ڼ����) ����ű���ֵ

/* 36 data address of the service transmission  */
 VAR(FBL_AddressType, AUTOMATIC)  FBL_TranDataAddres = 0U;

/* 0x36 service transfer data validation */
STATIC VAR(FBL_AddressType, AUTOMATIC) FBL_TranData0x36Verify = 0U;

/* 36 data length of the service transmission  */
 VAR(FBL_LengthType, AUTOMATIC) FBL_TranDataLength = 0U;

/* The operating state of the current flash  */
STATIC VAR(FBL_FlashOperationStateType, AUTOMATIC) FBL_FlashOperationState;

/* Indicates whether the current flahs drive is valid  */
STATIC VAR(FBL_FlashDriveType, AUTOMATIC) FBL_FlashDrive;

/* Flash driven download information  */
STATIC VAR(FBL_FlashDriveInfoType, AUTOMATIC) FBL_FlashDriveInfo;  //Fls��������Ϣ��

/* Flash drive information  */
tFlashParam FBL_FlashProgramInfo =                  //�ص� ����ṹ���Ǹ�fls�����õģ�������ǵ�ǰҪд��app����Ϣ
{

	(uint8)0x00,
	(uint8)0x01,
	(uint8)0x01,
	(uint8)0x00,
	(uint16)kFlashOk,
	(uint16)0x0000U,
	(uint32)0x00000000U,
	(uint32)0x00000000U,
	NULL_PTR,
	NULL_PTR,
};
/* information which shall be programmed to EEPROM */
VAR(FBL_AppProgramInfoType, AUTOMATIC) FBL_AppProgramInfo;   //����ṹ������������app����Ϣ��������fls��appǰ��  �����Ǹ�appinfo

boolean DidCanWritr = FALSE;

boolean ErrorApp = FALSE;

VAR(uint32, AUTOMATIC) Dcm_TempCrc = 0;


/*====================================================================================================*
 *                                      LOCAL FUNCTION PROTOTYPES                                   
 *====================================================================================================*/

//extern void Fls_Drive(uint32 *addr,uint32 length,uint32 *write_data,uint8 flag);

STATIC FUNC(Std_ReturnType,AUTOMATIC) FBL_EraseAppData(void);
STATIC FUNC(Std_ReturnType,AUTOMATIC) FBL_WriteAppData(void);
STATIC FUNC(void,AUTOMATIC) FBL_InitFlash(void);
FUNC(void,AUTOMATIC) FBL_MemoryManag
(
	P2VAR(uint8, AUTOMATIC, AUTOMATIC) DestBuffer,
	P2CONST(uint8, AUTOMATIC, AUTOMATIC) SourceBuffer,
	VAR(FBL_LengthType, AUTOMATIC) Length,
	VAR(boolean, AUTOMATIC) DuplicateFlag
);
STATIC FUNC(void,AUTOMATIC) FBL_FlashDown
(
	CONST(FBL_AddressType,AUTOMATIC)StartAdd,
	CONST(FBL_LengthType,AUTOMATIC)Length,
	P2CONST(uint8,AUTOMATIC,AUTOMATIC)SourceBuff
);
FUNC(void,AUTOMATIC) FBL_FlashWrite(void);
STATIC FUNC(void,AUTOMATIC) FBL_FlashInit(void);
FUNC(void,AUTOMATIC) FBL_FlashErase(void);
STATIC FUNC(void,AUTOMATIC) FBL_DataInfoCheck(void);
STATIC FUNC(Std_ReturnType,AUTOMATIC) FBL_Dcm0x31ff01Check(void);
STATIC FUNC(Std_ReturnType,AUTOMATIC) FBL_ErrorInit(void);
STATIC FUNC(Std_ReturnType,AUTOMATIC) FBL_AppDataCheck(void);
STATIC FUNC(Std_ReturnType,AUTOMATIC) FBL_FlashDriveCheck(void);
STATIC FUNC(Std_ReturnType,AUTOMATIC) FBL_FlashInitCheck(void);
STATIC FUNC(Std_ReturnType,AUTOMATIC) FBL_FlashEraseCheck(void);
STATIC FUNC(Std_ReturnType,AUTOMATIC) FBL_CreateAppInfoCrc(void);
STATIC FUNC(Std_ReturnType,AUTOMATIC) FBL_Dcm0x2ECheck(void);
STATIC FUNC(Std_ReturnType,AUTOMATIC) FBL_Dcm0x36Check
(
	CONST(FBL_AddressType,AUTOMATIC)StartAdd,
	CONST(FBL_LengthType,AUTOMATIC)Length,
	P2CONST(uint8,AUTOMATIC,AUTOMATIC)SourceBuff
);
STATIC FUNC(Std_ReturnType,AUTOMATIC) FBL_Dcm0x31ff00Check
(
	CONST(uint8,AUTOMATIC) Index
);

/*====================================================================================================*
 *                                           LOCAL FUNCTIONS
 *====================================================================================================*/

  /*CheckProgrammingDependncies*/
FUNC(Std_ReturnType,AUTOMATIC)CheckProgrammingDependncies(void)
{
	Std_ReturnType result = (Std_ReturnType)E_OK;
	FBL_FlashDrive = FBL_FLASH_DRIVE_VALID;
	FBL_AppProgramInfo.FBL_AppStatus.AppValid = (uint8)TRUE ;
	result = FBL_WriteFlashAppInfo();
	return result;
}

/**
 * @brief              Check whether 0x2e was performed and did to be written successfully
 * @param[in]      	   None
 * @param[out]     	   None
 * @return             Std_ReturnType
 */
STATIC FUNC(Std_ReturnType,AUTOMATIC) FBL_Dcm0x2ECheck(void)
{
	VAR(Std_ReturnType,AUTOMATIC) ret = FBL_OK;


	return ret;
}

/**
 * @brief          	Service validation, check for the address, length, and array
 * @param[in]      	StartAdd
 * @param[in]		Length
 * @param[in]		SourceBuff
 * @param[out]     	None
 * @return         	Std_ReturnType
 */


/**
 * @brief          	Check operation before checking service
 * @param[in]      	CheckSum
 * @param[out]     	None
 * @return         	Std_ReturnType
 */
STATIC FUNC(Std_ReturnType,AUTOMATIC) FBL_DcmCRCCheck(      //CheckSum�Ǵ����CRCֵ(������ϱ���)
	P2CONST(uint8,AUTOMATIC,AUTOMATIC) CheckSum)
{
	VAR(Std_ReturnType,AUTOMATIC) ret = FBL_NOT_OK;

	uint32 TempBuffer;

	/* todo: LXX 2025/08/13 */
	TempBuffer = ((uint32)CheckSum[0] << 24)|
				 ((uint32)CheckSum[1] << 16)|
				 ((uint32)CheckSum[2] << 8)|
				 (uint32)CheckSum[3];

	/* Check if the array is legal */
	if(CheckSum != NULL_PTR)
	{
		if(TempBuffer == FBL_TempCrc) //FBL_TempCrc �Ǵ������ݹ�����boot��������crc
		{
				/* Pass the incoming amount of the incoming value to the current data  */
				FBL_MemoryManag((uint8*)(&FBL_TranCrcData), CheckSum, 4U,(boolean)TRUE);
				ret = FBL_OK;
		}
		else
		{
				ret = FBL_NOT_OK;
		}
	}
	else
	{
		/*  nothing */
	}
	return ret;
}



/**
 * @brief          	Check the service before checking the time of the drive state call
 * @param[in]      	None
 * @param[out]     	None
 * @return         	Std_ReturnType
 */
STATIC FUNC(Std_ReturnType,AUTOMATIC) FBL_Dcm0x31ff01Check(void) //��¼ǰ����֤
{
	VAR(Std_ReturnType,AUTOMATIC) ret = FBL_NOT_OK;
	VAR(uint8,AUTOMATIC) index;

	if((FBL_FlashDrive == FBL_FLASH_DRIVE_VALID) && (FBL_ErasingSuccess == (boolean)TRUE))
	{
		for(index = 0U; index < (uint8)LOGICAL_MAX; index++)
		{
			/* Check that all the blocks are valid  */
			if(FBL_APP_LOGIC_BLOCK_STATUE(index) == (boolean)TRUE)
			{
				ret = FBL_OK;
			}
			else
			{
				if(FBL_UDSCallStep == (Std_ReturnType)FBL_UDS_DEPEND_CHECK_STEP)
				{
					  ret = FBL_NOT_OK;
				}
				else
				{
					  ret = FBL_EER_STEP;
				}

				return ret;
			}
		}
	}
	else
	{

	}
	return ret;
}

/**
 * @brief          Error initialization for error checking
 * @param[in]      None
 * @param[out]     None
 * @return         None
 */
STATIC FUNC(Std_ReturnType,AUTOMATIC) FBL_ErrorInit(void)
{
	VAR(Std_ReturnType,AUTOMATIC) ret = FBL_NOT_OK;
	if(FBL_ErrorStatus == FBL_OK)
	{
		FBL_ErrorStatus = (Std_ReturnType)FBL_NOT_OK;
		ret = FBL_OK;
	}
	return ret;
}



/**
 * @brief          Flash init
 * @param[in]      None
 * @param[out]     None
 * @return         None
 */
STATIC FUNC(void,AUTOMATIC) FBL_InitFlash(void)
{
	/* Downloaded image at FLASH_DRIVE_ADDRESS starts with tFlash_InfoType
	 * (function pointer table). Jump via pointers — do not link Boot code
	 * into 0x20007B00. */
	BLFlash_InfoPtr = (const tFlash_InfoType *)FLASH_DRIVE_ADDRESS;

	if ((BLFlash_InfoPtr != NULL_PTR) && (BLFlash_InfoPtr->flashInitFct != NULL_PTR))
	{
		BLFlash_InfoPtr->flashInitFct(&FBL_FlashProgramInfo);
	}

	DidCanWritr = TRUE;
}



/**
 * @brief           Log according to information, prepare for download
 * @param[in]      	None
 * @param[out]     	None
 * @return          None
 */
STATIC FUNC(void,AUTOMATIC) FBL_DataInfoCheck(void) //�Ѷε�ַ�Ƶ����ַ
{
	if(FBL_FlashDrive != FBL_FLASH_DRIVE_VALID)
	{
		FBL_FlashDriveInfo.FlashLength = ((FBL_FlashDriveInfo.FalshSegmentInfo.SegmentAddre + \
				FBL_FlashDriveInfo.FalshSegmentInfo.SegmentLength) - FBL_FlashDriveInfo.FlashAddress);
	}
	else
	{
		FBL_APP_LOGIC_BLOCK_ADRESS(FBL_CurrentBlIndex) = FBL_APP_SEGMENT_ADDRESS(FBL_CurrentBlIndex);

		FBL_APP_LOGIC_BLOCK_LENGTH(FBL_CurrentBlIndex) = FBL_APP_SEGMENT_LENGTH(FBL_CurrentBlIndex);
	}
}



/**
 * @brief           Flash init check
 * @param[in]      	None
 * @param[out]     	None
 * @return          Std_ReturnType
 */
STATIC FUNC(Std_ReturnType,AUTOMATIC) FBL_FlashInitCheck(void)
{
	VAR(Std_ReturnType,AUTOMATIC) ret;

	if(FBL_FlashOperationState == FBL_WAIT_INIT_STATE)
	{
		ret = FBL_ErrorInit();
	}
	else
	{
		ret = FBL_NOT_OK;
	}
	return ret;
}



/**
 * @brief              Computing programming information
 * @param[in]      	   None
 * @param[out]     	   None
 * @return             Std_ReturnType
 */
STATIC FUNC(Std_ReturnType,AUTOMATIC) FBL_CreateAppInfoCrc(void)
{
	VAR(Std_ReturnType,AUTOMATIC) ret = (Std_ReturnType)FBL_NOT_OK;

	VAR(SecM_CheckState,AUTOMATIC) checkState;

	checkState.CrcFirstCall = (boolean)TRUE;

	/* compute CRC of the block information */
    ret = SecM_CreatCrc(&checkState , (const BM_EepromDataType*)&FBL_AppProgramInfo , \
    		(BM_LengthType)(sizeof(FBL_AppProgramInfo)-(BM_LengthType)4));

    if((Std_ReturnType)FBL_OK == ret)
	{
		/* program computed CRC value to flash */
		FBL_AppProgramInfo.CrcCheck = checkState.CrcCheckSum;

		/* set input parameter of flash driver interface */
		FBL_FlashProgramInfo.data = (uint8 *)&FBL_AppProgramInfo;

		FBL_FlashProgramInfo.address = (FBL_AddressType)FBL_EEPROM_INFO_ADDRESS;

		FBL_FlashProgramInfo.length = FLASH_ERASE_LENGTH;
	}

	return ret;
}




/**
 * @sid				   0x03
 * @brief              0x31 service routine checksum.
 * @details			   The service is calibrated and compared to the calculated value.
 * @param[in]      	   CheckSum:	This parameter contains the relevant data for the check.
 * @param[out]     	   None
 * @return             ret
 */
FUNC(Std_ReturnType,AUTOMATIC) FBL_DcmIntegrityCheck(P2CONST(uint8,AUTOMATIC,AUTOMATIC) CheckSum)
{
	VAR(Std_ReturnType,AUTOMATIC) ret = (Std_ReturnType)FBL_NOT_OK;

#if(FBL_USE_DEPEND_CHECK == STD_OFF)
	VAR(Std_ReturnType,AUTOMATIC) blockNum = 0U;

	VAR(Std_ReturnType,AUTOMATIC) blockIndex = 0U;
#endif

	ret = FBL_ErrorInit();

	if(ret == (Std_ReturnType)FBL_OK)
    {
		if(FBL_UDSCallStep == (Std_ReturnType)FBL_UDS_DEPEND_CHECK_STEP)
		{
			ret = FBL_DcmCRCCheck(CheckSum);

			if(ret == (Std_ReturnType)FBL_OK)
			{
				if(FBL_FlashDrive == FBL_FLASH_DRIVE_VALID)
				{

					FBL_DataInfoCheck();

#if(FBL_USE_DEPEND_CHECK == STD_ON)

                    if( FBL_CurrentBlIndex <= LOGICAL_MAX)
                    {
                            FBL_UDSCallStep = FBL_UDS_INTEGRITY_CHECK_STEP;

                            ret = FBL_AppDataCheck();

                            if(ret == FBL_OK)
                            {
								FBL_ErrorStatus = (Std_ReturnType)FBL_OK;

								ret = (Std_ReturnType)FBL_OK;

								FBL_FlashOperationState = FBL_IDIE_STATE;
                            }
                            else
                            {
								ret = (Std_ReturnType)FBL_EER_DATA;

								/*  Error marker */
								FBL_ErrorMark = (boolean)TRUE;
                            }
                    }
                    else
                    {
                             FBL_UDSCallStep = FBL_UDS0X34_STEP;
                    }
#else
                    FBL_UDSCallStep = FBL_UDS0X34_STEP;

					if(FBL_CurrentBlIndex <= LOGICAL_MAX)
					{
						ret = FBL_AppDataCheck();

						if(ret == FBL_OK)
						{
							 FBL_ErrorStatus = (Std_ReturnType)FBL_OK;

							 ret = (Std_ReturnType)FBL_OK;

							 FBL_FlashOperationState = FBL_IDIE_STATE;

							 FBL_AppProgramInfo.FBL_AppStatus.AppValid = (boolean)TRUE;

							 if(FBL_AppProgramInfo.FBL_AppStatus.AppDownSucNum < 0xffU)
							 {
								 FBL_AppProgramInfo.FBL_AppStatus.AppDownSucNum++;
							 }
							 else
							 {
								 FBL_AppProgramInfo.FBL_AppStatus.AppDownSucNum = 0U;
							 }

							 for(blockIndex = 0U;blockIndex < LOGICAL_MAX; blockIndex++)
							 {
								 if(FBL_APP_LOGIC_BLOCK_STATUE(blockIndex) == (boolean)TRUE)
								 {
									 blockNum++;
									 FBL_ErrorStatus = (Std_ReturnType)FBL_OK;
									 ret = (Std_ReturnType)FBL_OK;
								 }
								 else
								 {
									 FBL_ErrorStatus = (Std_ReturnType)FBL_EER_DATA;
									 ret = (Std_ReturnType)FBL_EER_DATA;
								 }
							 }

							 if(ret == (Std_ReturnType)FBL_OK)
							 {
								 FBL_AppProgramInfo.FBL_LogicalBlInfo.BlockNumber = blockNum;
								 /*  Update block programming information   */
								 (void)FBL_WriteFlashAppInfo();
							 }
						}
					}
#endif
				}
				else
				{
					FBL_DataInfoCheck();

					FBL_UDSCallStep = FBL_UDS0X31FF00_STEP;

					SegmentNum = 0;

					ret = FBL_FlashDriveCheck();

					if(ret == FBL_OK)
					{
							FBL_ErrorStatus = (Std_ReturnType)FBL_OK;

							ret = (Std_ReturnType)FBL_OK;

							FBL_FlashInit();
					}
					else
					{
							ret = (Std_ReturnType)FBL_EER_DATA;

							FBL_ErrorMark = (boolean)TRUE;
					}
				}
			}
			else
			{
				ret = (Std_ReturnType)FBL_EER_DATA;
			}
		}
		else
		{
			ret = (Std_ReturnType)FBL_EER_STEP;
		}
    }
	return ret;
}



/**
 * @sid				   0x05
 * @brief              31 service programming dependency check.
 * @details			   31 service programming dependency check.
 * @param[in]      	   None.
 * @param[out]     	   None
 * @return             ret
 */
FUNC(Std_ReturnType,AUTOMATIC) FBL_DcmDependCheckCall(void)
{
	VAR(Std_ReturnType,AUTOMATIC) ret = (Std_ReturnType)FBL_NOT_OK;
	VAR(Std_ReturnType,AUTOMATIC) blockNum = 0U;
	VAR(Std_ReturnType,AUTOMATIC) blockIndex = 0U;

	ret = FBL_ErrorInit();
	if(ret == (Std_ReturnType)FBL_OK)
    {
		ret = FBL_Dcm0x31ff01Check();
		if(ret == (Std_ReturnType)FBL_OK)
		{
			if(FBL_UDSCallStep == (Std_ReturnType)FBL_UDS_INTEGRITY_CHECK_STEP)
			{
				FBL_UDSCallStep = FBL_UDS0X34_STEP;
				FBL_AppProgramInfo.FBL_AppStatus.AppValid = (boolean)TRUE;

				/* Record the number of downloads of app data */
				if(FBL_AppProgramInfo.FBL_AppStatus.AppDownSucNum < 0xffU)
				{
					FBL_AppProgramInfo.FBL_AppStatus.AppDownSucNum++;
				}
				else
				{
					FBL_AppProgramInfo.FBL_AppStatus.AppDownSucNum = 0U;
				}

				/* You need to add a block validity test, and the validity of the block,
				 * the validity of the block, the number of blocks is a few, and the number
				 *  of successful programming of the app state is + +*/
				for(blockIndex = 0U;blockIndex < LOGICAL_MAX; blockIndex++)
				{
					if(FBL_APP_LOGIC_BLOCK_STATUE(blockIndex) == (boolean)TRUE)
					{
						blockNum++;
						FBL_ErrorStatus = (Std_ReturnType)FBL_OK;
						ret = (Std_ReturnType)FBL_OK;
					}
					else
					{
						FBL_ErrorStatus = (Std_ReturnType)FBL_EER_DATA;
						ret = (Std_ReturnType)FBL_EER_DATA;
						break;
					}
				}

				if(ret == (Std_ReturnType)FBL_OK)
				{
					FBL_AppProgramInfo.FBL_LogicalBlInfo.BlockNumber = blockNum;
					/*  Update block programming information   */
					(void)FBL_WriteFlashAppInfo();
				}
			}
			else
			{
				FBL_ErrorStatus = (Std_ReturnType)FBL_EER_STEP;
				ret = (Std_ReturnType)FBL_NOT_OK;
			}
		}
    }
	return ret;
}




/*************************************************************************************************************/
/*************************************************************************************************************/
/*************************************************************************************************************/





















		/**
 * @brief          	Check the previous inspection
 * @param[in]      	Index
 * @param[out]     	None
 * @return         	Std_ReturnType
 */
STATIC FUNC(Std_ReturnType,AUTOMATIC) FBL_Dcm0x31ff00Check(   
		CONST(uint8,AUTOMATIC) Index)
{
	VAR(Std_ReturnType,AUTOMATIC) ret = FBL_NOT_OK;

	/* Check whether the block that needs to be erased is legal   */
	if(LOGICAL_MAX > Index)
	{
		if(FBL_FlashDrive == FBL_FLASH_DRIVE_VALID)
		{
			FBL_UDSCallStep = FBL_UDS0X31FF00_STEP;
			ret = FBL_OK;
		}
		FBL_ErasingSuccess = (boolean)FALSE;
	}
	else
	{

	}
    return ret;
}

	
/**
 * @sid				   0x04
 * @brief              0x31 service routine erase.
 * @details			   Call flash drivers to erase the app data.
 * @param[in]      	   Index:	block index.
 * @param[out]     	   None
 * @return             ret
 */
FUNC(Std_ReturnType,AUTOMATIC) FBL_Dcm0x31ff00Erase(CONST(uint8,AUTOMATIC) Index)
{
	VAR(Std_ReturnType,AUTOMATIC) ret = (Std_ReturnType)FBL_NOT_OK;
	VAR(Std_ReturnType,AUTOMATIC) index = Index;

	ret = FBL_ErrorInit();

	if(ret == (Std_ReturnType)FBL_OK)
	{
		/*pxc*/
		//FBL_FlashDrive = FBL_FLASH_DRIVE_VALID;
		ret = FBL_Dcm0x31ff00Check(index);

		if(ret == (Std_ReturnType)FBL_OK)
		{
			if(FBL_UDSCallStep == (Std_ReturnType)FBL_UDS0X31FF00_STEP)
			{
				FBL_UDSCallStep = FBL_UDS0X34_STEP;

				FBL_APP_LOGIC_BLOCK_ADRESS(index) = 0U;
				FBL_APP_LOGIC_BLOCK_LENGTH(index) = 0U;
				FBL_APP_LOGIC_BLOCK_CRCCHECK(index) = 0U;
				FBL_APP_LOGIC_BLOCK_STATUE(index) = (boolean)FALSE;

				FBL_AppProgramInfo.FBL_LogicalBlInfo.BlockNumber = 0U;
				FBL_AppProgramInfo.FBL_AppStatus.AppValid = (boolean)FALSE;

				if(FBL_AppProgramInfo.FBL_AppStatus.AppPrograNum < 0xffU)
				{
					FBL_AppProgramInfo.FBL_AppStatus.AppPrograNum++;
				}
				else
				{
					FBL_AppProgramInfo.FBL_AppStatus.AppPrograNum = 0U;
				}

				if(FBL_APP_LOGIC_BLOCK_PRONUM(index) < 0xffU)
				{
					FBL_APP_LOGIC_BLOCK_PRONUM(index)++;
				}
				else
				{
					FBL_APP_LOGIC_BLOCK_PRONUM(index) = 0U;
				}
				FBL_CurrentBlIndex = index;

				FBL_APP_SEGMENT_ADDRESS(index) = 0U;
				FBL_APP_SEGMENT_LENGTH(index) = 0U;
				FBL_APP_SEGMENT_CRCCHECK(index) = 0U;

				FBL_FlashOperationState = FBL_ERARE_STATE;

				FBL_ErrorStatus = (Std_ReturnType)FBL_OK;

				FBL_FlashErase();
			}
			else
			{
				FBL_ErrorStatus = (Std_ReturnType)FBL_EER_STEP;
				ret = (Std_ReturnType)FBL_EER_STEP;
			}
		}
		else
		{
			FBL_ErrorStatus = (Std_ReturnType)FBL_NOT_OK;
		}
	}

	return ret;
}

/**
 * @brief           The test of the app download data is used to determine whether the data is fully valid
 * @param[in]      	None
 * @param[out]     	None
 * @return          Std_ReturnType
 */
STATIC FUNC(Std_ReturnType,AUTOMATIC) FBL_AppDataCheck(void)  //�ж�app�����Ƿ�����Ч
{
	VAR(Std_ReturnType,AUTOMATIC) ret = FBL_NOT_OK;
	VAR(FBL_AddressType,AUTOMATIC) u32BlockAddress = 0U;
	VAR(FBL_LengthType,AUTOMATIC) u32BlockLength = 0U;
	VAR(SecM_CheckState,AUTOMATIC) checkState;

	u32BlockAddress = FBL_APP_SEGMENT_ADDRESS(FBL_CurrentBlIndex);

	u32BlockLength = FBL_APP_SEGMENT_LENGTH(FBL_CurrentBlIndex);

	if((u32BlockAddress == FBL_APP_LOGIC_BLOCK_ADRESS(FBL_CurrentBlIndex)) && \
			(u32BlockLength == FBL_APP_LOGIC_BLOCK_LENGTH(FBL_CurrentBlIndex)))
	{
		checkState.CrcFirstCall = (boolean)TRUE;

		ret = SecM_SofawareCheck(&FBL_APP_LOGIC_BLOCK_SEGMENTINFO(FBL_CurrentBlIndex) , &checkState);

		if(ret == FBL_OK)
		{
			FBL_APP_LOGIC_BLOCK_STATUE(FBL_CurrentBlIndex) = (boolean)TRUE;

			FBL_APP_LOGIC_BLOCK_CRCCHECK(FBL_CurrentBlIndex) = checkState.CrcCheckSum;

			/* Update app programming data  */
			ret = FBL_WriteFlashAppInfo();
		}
		else
		{
			ret = FBL_EER_DATA;
		}
	}
	else
	{
		ret = FBL_EER_DATA;
	}
	return ret ;
}

/**
 * @brief           Flash drive for the check
 * @param[in]      	None
 * @param[out]     	None
 * @return          Std_ReturnType
 */
STATIC FUNC(Std_ReturnType,AUTOMATIC) FBL_FlashDriveCheck(void)   //�ж�fls�����Ĵ����Ƿ���ȷ
{
	VAR(Std_ReturnType,AUTOMATIC) ret = FBL_OK;
	VAR(SecM_CheckState,AUTOMATIC) checkState;

	checkState.CrcFirstCall = (boolean)TRUE;

	ret = SecM_CreatCrc(&checkState , (const uint8*)FBL_FlashDriveInfo.FalshSegmentInfo.SegmentAddre,\
			FBL_FlashDriveInfo.FalshSegmentInfo.SegmentLength);

	if((ret == FBL_OK) && (checkState.CrcCheckSum == FBL_FlashDriveInfo.FalshSegmentInfo.SegmentCrcCheck)) //��fls����info����洢��crc(��λ������������������)�Ƚ�
	{
		uint32 FBL_Tran=((FBL_TranCrcData&0xff000000)>>24)|
		            ((FBL_TranCrcData&0x00ff0000)>>8)|
		            ((FBL_TranCrcData&0x0000ff00)<<8)|
		            ((FBL_TranCrcData&0x000000ff)<<24);
		/* Compare the calculated results with the top machine */
		if(checkState.CrcCheckSum == FBL_Tran)   //����λ����������CRC�Ƚ�
		{
			/* Assign the calculated value of the amount to the flash  */
			FBL_FlashDriveInfo.FlashCrcCheck = checkState.CrcCheckSum;

			/* Flash check complete waiting initialization  */
			FBL_FlashOperationState = FBL_WAIT_INIT_STATE;
		}
	}
	else
	{
		ret = FBL_EER_DATA;
	}

	return ret;
}

/**
 * @brief          Flash erase
 * @param[in]      None
 * @param[out]     None
 * @return         None
 */
const tFlash_InfoType* BLFlash_InfoPtr = NULL_PTR;
STATIC FUNC(Std_ReturnType,AUTOMATIC) FBL_EraseAppData(void)
{
	VAR(Std_ReturnType,AUTOMATIC) ret = (Std_ReturnType)FBL_NOT_OK;

	if ((BLFlash_InfoPtr == NULL_PTR) || (BLFlash_InfoPtr->flashEraseFct == NULL_PTR))
	{
		return ret;
	}

	FBL_FlashProgramInfo.address = (tFlashAddress)FBL_ProgramBlInfo[FBL_CurrentBlIndex].DataBlddress;
	FBL_FlashProgramInfo.length = (tFlashLength)FBL_ProgramBlInfo[FBL_CurrentBlIndex].DataBlLength;
	FBL_FlashProgramInfo.data = NULL_PTR;
	FBL_FlashProgramInfo.errorCode = (tFlashResult)kFlashFailed;

	BLFlash_InfoPtr->flashEraseFct(&FBL_FlashProgramInfo);

	if (FBL_FlashProgramInfo.errorCode == (tFlashResult)kFlashOk)
	{
		ret = (Std_ReturnType)FBL_OK;
	}

	return ret;
}

/**
 * @brief          Flash write
 * @param[in]      None
 * @param[out]     None
 * @return         None
 */
STATIC FUNC(Std_ReturnType,AUTOMATIC) FBL_WriteAppData(void)
{
	VAR(Std_ReturnType,AUTOMATIC) ret = (Std_ReturnType)FBL_NOT_OK;

	if ((BLFlash_InfoPtr == NULL_PTR) || (BLFlash_InfoPtr->flashWriteFct == NULL_PTR))
	{
		return ret;
	}

	FBL_FlashProgramInfo.errorCode = (tFlashResult)kFlashFailed;
	BLFlash_InfoPtr->flashWriteFct(&FBL_FlashProgramInfo);

	if (FBL_FlashProgramInfo.errorCode == (tFlashResult)kFlashOk)
	{
		ret = (Std_ReturnType)FBL_OK;
	}

	return ret;
}


/**
 * @brief          	Set up the internal interface in FBL,
 * 					only for internal use of FBL, and the processing of data
 * @param[in]      	SourceBuffer
 * @param[in]       Length
 * @param[in]		DuplicateFlag
 * @param[out]     	DestBuffer
 * @return         	None
 */
FUNC(void,AUTOMATIC) FBL_MemoryManag        //����memcpy
(
	P2VAR(uint8, AUTOMATIC, AUTOMATIC) DestBuffer,
	P2CONST(uint8, AUTOMATIC, AUTOMATIC) SourceBuffer,
	VAR(FBL_LengthType, AUTOMATIC) Length,
	VAR(boolean, AUTOMATIC) DuplicateFlag
)
{
	P2VAR(uint8, AUTOMATIC, AUTOMATIC) u32DestBuffer;
	P2CONST(uint8, AUTOMATIC, AUTOMATIC) u32SourceBuffer;
	VAR(FBL_LengthType, AUTOMATIC) u32Length;
	VAR(boolean, AUTOMATIC) u8Duplicate = DuplicateFlag;

	/* Check if the parameters are correct  */
	if((DestBuffer != NULL_PTR) && (SourceBuffer != NULL_PTR) && (Length > 0U))
	{
		/*  Assign the parameters to the assignment */
		u32DestBuffer = DestBuffer;
		u32SourceBuffer = SourceBuffer;
		u32Length = Length;

		for( ; u32Length > 0U ; u32Length--)
		{
			*u32DestBuffer = *u32SourceBuffer;
			/* Processing by copying */
			if(u8Duplicate == (boolean)TRUE)
			{
				u32DestBuffer++;
				u32SourceBuffer++;
			}
			else
			{
				u32DestBuffer++;
			}
		}
	}
}

/**
 * @brief           Flash driven download
 * @param[in]      	SourceBuff
 * 					Length
 * @param[out]     	StartAdd
 * @return          None
 */
STATIC FUNC(void,AUTOMATIC) FBL_FlashDown(    //Fls��������
		CONST(FBL_AddressType,AUTOMATIC)StartAdd,
		CONST(FBL_LengthType,AUTOMATIC)Length,
		P2CONST(uint8,AUTOMATIC,AUTOMATIC)SourceBuff)
{
	FBL_MemoryManag((uint8*)StartAdd, SourceBuff, Length , (boolean)TRUE);
}


/**
 * @brief              The flash drive initialization
 * @param[in]      	   None
 * @param[out]     	   None
 * @return             None
 */
STATIC FUNC(void,AUTOMATIC) FBL_FlashInit(void)
{
	VAR(Std_ReturnType,AUTOMATIC) ret = (Std_ReturnType)FBL_NOT_OK;

	ret = FBL_FlashInitCheck();

	if(ret == (Std_ReturnType)FBL_OK)
	{
		if(FBL_FlashDrive != FBL_FLASH_DRIVE_VALID)
		{
			if(FBL_FlashOperationState == FBL_WAIT_INIT_STATE)
			{
				FBL_InitFlash();

				FBL_FlashOperationState = FBL_IDIE_STATE;

				FBL_FlashDrive = FBL_FLASH_DRIVE_VALID;

				FBL_ErrorStatus = (Std_ReturnType)FBL_OK;

				ret = (Std_ReturnType)FBL_OK;
			}
			else
			{
				ret = (Std_ReturnType)FBL_EER_STEP;
			}
		}
		else
		{
			ret = (Std_ReturnType)FBL_EER_STEP;
		}

		if(FBL_ErrorStatus != (Std_ReturnType)FBL_OK)
		{
			/*  Error marker */
			FBL_ErrorMark = (boolean)TRUE;
		}
	}
}


/**
 * @brief          Flash writes data operations, and writes the app data to the specified address
 * @param[in]      None
 * @param[out]     None
 * @return         None
 */
FUNC(void,AUTOMATIC) FBL_FlashWrite(void)
{
//	uint8 buffer[128] = {0u};
	uint8 i = 0;

	FBL_FlashProgramInfo.errorCode = 0U;

	while(FBL_TranDataLength >=(FBL_LengthType)1024U)
	{
		FBL_FlashProgramInfo.address = FBL_TranDataAddres;

		FBL_FlashProgramInfo.length = (FBL_LengthType)1024U;

		FBL_FlashProgramInfo.data = FBL_TranDataBuff;

		/* program the data */
		FBL_WriteAppData();

		FBL_TranDataLength -= (FBL_LengthType)1024U;

		FBL_TranDataBuff += (FBL_LengthType)1024U;

		FBL_TranDataAddres += (FBL_LengthType)1024U;

		FBL_ErrorStatus = (Std_ReturnType)FBL_OK;

	}

	if((FBL_TranDataLength != 0) && (FBL_TranDataLength < (FBL_LengthType)1024U))
	{
		FBL_FlashProgramInfo.address = FBL_TranDataAddres;

		FBL_FlashProgramInfo.length = (FBL_LengthType)FBL_TranDataLength;

		FBL_FlashProgramInfo.data = FBL_TranDataBuff;

		/* program the data */
		FBL_WriteAppData();


		FBL_TranDataBuff += (FBL_LengthType)FBL_TranDataLength;

		FBL_TranDataAddres += (FBL_LengthType)FBL_TranDataLength;

		FBL_ErrorStatus = (Std_ReturnType)FBL_OK;
		
		HashAppDataLength = FBL_TranDataAddres;
		

		FBL_TranDataLength = 0U;
	}

	FBL_FlashOperationState = FBL_IDIE_STATE;
}



/**
 * @brief              Flash performs erase tasks擦除APP，APPInfo操作
 * @param[in]      	   None
 * @param[out]     	   None
 * @return             None
 */
FUNC(void,AUTOMATIC) FBL_FlashErase(void)
{
	VAR(Std_ReturnType,AUTOMATIC) ret = FBL_NOT_OK;
	VAR(FBL_LengthType,AUTOMATIC) u32Length = 0U;
	VAR(FBL_AddressType,AUTOMATIC) u32Address = 0U;

	/*pxc*/
	//FBL_FlashDrive = FBL_FLASH_DRIVE_VALID;
	ret = FBL_FlashEraseCheck();

	if(ret == FBL_OK)
	{
		
		if(FBL_FlashDrive == FBL_FLASH_DRIVE_VALID)
		{
			u32Length = FBL_ProgramBlInfo[FBL_CurrentBlIndex].DataBlLength;

			u32Address = FBL_ProgramBlInfo[FBL_CurrentBlIndex].DataBlddress;

			FBL_FlashProgramInfo.errorCode = 0x00U;

			ret = FBL_EraseAppData();
			if (ret == (Std_ReturnType)FBL_OK)
			{
				FBL_ErrorStatus = (Std_ReturnType)FBL_OK;
				FBL_ErasingSuccess = (boolean)TRUE;
				FBL_FlashOperationState = FBL_IDIE_STATE;
			}
			else
			{
				FBL_ErrorStatus = FBL_ERR_FLASHDRIVER;
				FBL_ErrorMark = (boolean)TRUE;
				FBL_ErasingSuccess = (boolean)FALSE;
			}

			/* todo:(0x00U == FBL_FlashProgramInfo.errorCode) */
            // while(u32Length > 0U)
            // {
    		// 	if(FLASH_ERASE_LENGTH < u32Length)
    		// 	{
    		// 		FBL_FlashProgramInfo.address = (uint32)u32Address;

    		// 		FBL_FlashProgramInfo.length = (uint32)FLASH_ERASE_LENGTH;

    	    //         /* program the data */
    				

    	    //         u32Length -= FLASH_ERASE_LENGTH;

    	    //         u32Address += FLASH_ERASE_LENGTH;

    	    //         if(u32Length <= FLASH_ERASE_LENGTH)
    	    //         {
    	    //         	u32Length = FLASH_ERASE_LENGTH;
    	    //         }
    		// 	}
    		// 	else
    		// 	{
    		// 		FBL_FlashProgramInfo.address = u32Address;

    		// 		FBL_FlashProgramInfo.length = FLASH_ERASE_LENGTH;

    	    //         /* program the data */
    		// 		FBL_EraseAppData();

    	    //         u32Length = 0U;
    		// 	}
            // }

            // /* todo:((uint8)kFlashOk == FBL_FlashProgramInfo.errorCode) && ( */
            // if(u32Length == 0U)
            // {
            // 	FBL_ErrorStatus = (Std_ReturnType)FBL_OK;

            // 	FBL_ErasingSuccess = (boolean)TRUE;

            // 	ret = FBL_OK;

            // 	FBL_FlashOperationState = FBL_IDIE_STATE;
            // }
            // else
            // {
            // 	ret = FBL_NOT_OK;

            // 	FBL_ErrorStatus = FBL_ERR_FLASHDRIVER;

    		// 	/*  Error marker */
    		// 	FBL_ErrorMark = (boolean)TRUE;
            // }
		}
	}
}

/**
 * @brief              Flash erase check擦除前检差Flash驱动是否正确
 * @param[in]      	   None
 * @param[out]     	   None
 * @return             Std_ReturnType
 */
STATIC FUNC(Std_ReturnType,AUTOMATIC) FBL_FlashEraseCheck(void)
{
	VAR(Std_ReturnType,AUTOMATIC) ret;

	if(FBL_FlashOperationState == FBL_ERARE_STATE)
	{
		if(FBL_OK == FBL_WriteFlashAppInfo())
		{
			ret = FBL_ErrorInit();
		}
		else
		{
			ret = FBL_EER_PROGRAMINFO;
		}
	}
	else
	{
		ret = FBL_NOT_OK;
	}
	return ret;
}

/**
* @brief              写INFO区的数据
 * @param[in]      	   None
 * @param[out]     	   None
 * @return             Std_ReturnType
 */
FUNC(Std_ReturnType,AUTOMATIC) FBL_WriteFlashAppInfo(void)
{
	VAR(Std_ReturnType,AUTOMATIC) ret = FBL_NOT_OK;

	if(FBL_FlashDrive == FBL_FLASH_DRIVE_VALID)
	{

		/*pxc */
      FBL_FlashProgramInfo.errorCode = 0U;

      FBL_FlashProgramInfo.length = FBL_EEPROM_INFO_LENGTH;

			/* Erase the information before */
				// ret = FBL_EraseAppData();

				FBL_FlashProgramInfo.address = (FBL_AddressType)FBL_EEPROM_INFO_ADDRESS;
				FBL_FlashProgramInfo.data = (uint8 *)&FBL_AppProgramInfo;

				/* Erase + program Info via downloaded FLS driver function pointers */
				if ((BLFlash_InfoPtr != NULL_PTR) && (BLFlash_InfoPtr->flashEraseFct != NULL_PTR))
				{
					FBL_FlashProgramInfo.length = (tFlashLength)FBL_EEPROM_INFO_LENGTH;
					FBL_FlashProgramInfo.errorCode = (tFlashResult)kFlashFailed;
					BLFlash_InfoPtr->flashEraseFct(&FBL_FlashProgramInfo);
					if (FBL_FlashProgramInfo.errorCode == (tFlashResult)kFlashOk)
					{
						FBL_FlashProgramInfo.length = (FBL_LengthType)sizeof(FBL_AppProgramInfo);
						ret = FBL_WriteAppData();
					}
				}

	}
	return ret;
}

/**
 * @sid				   0x00
 * @brief              0x34 service.Request to download and be called by DCM.
 * @details			   Request the download routine, download the request segment data,
 *                     get the beginning address and length, and do different operations
 *                     based on the download flash drive or app.
 * @param[in]          StartAdd :segment Start address
 *                     Length  : segment Length
 * @param[out]     	   None
 * @return             ret
 */
FUNC(Std_ReturnType,AUTOMATIC)FBL_Dcm0x34Call
(
	uint32 MemoryAddress,
    uint32 MemorySize,
    P2VAR(uint32,AUTOMATIC,DCM_VAR)BlockLength
)
{
	VAR(Std_ReturnType,AUTOMATIC) ret = (Std_ReturnType)FBL_NOT_OK;
	VAR(Std_ReturnType,AUTOMATIC) IndexValid = (Std_ReturnType)FBL_NOT_OK;
	uint8 Index ;
	uint32 StartAdd = MemoryAddress;
	uint32 Length = MemorySize;

	FBL_ErrorStatus = (Std_ReturnType)FBL_NOT_OK;

	if((StartAdd > 0U) && (Length > 0U))
	{
		/* Did validation check */
		ret = FBL_Dcm0x2ECheck();
		if(ret == (Std_ReturnType)FBL_OK)
		{
			/* Diagnostic procedure check  */
			if((FBL_UDSCallStep == (Std_ReturnType)FBL_UDS0X34_STEP) || (FBL_UDSCallStep == \
					(Std_ReturnType)FBL_UDS_DEPEND_CHECK_STEP))
			{
				/* Address judgment assignment, Download flash drive first */
				if((StartAdd >= FLASH_DRIVE_ADDRESS)&&((StartAdd + Length)<= \
						(uint32)(FLASH_DRIVE_ADDRESS + FLASH_DRIVE_LENGTH)))
				{
					if((StartAdd == FLASH_DRIVE_ADDRESS) && (SegmentNum < SEGMENT_MAX))
					{
						FBL_FlashDriveInfo.FalshSegmentInfo.SegmentAddre = StartAdd;
						FBL_FlashDriveInfo.FalshSegmentInfo.SegmentLength = Length;
						FBL_TranData0x36Verify = StartAdd;
						FBL_ErrorStatus = (Std_ReturnType)FBL_OK;
						SegmentNum++;
						*BlockLength = 4093;
						FBL_TranDataAddres = StartAdd;
					}
					else
					{
						ret = (Std_ReturnType)FBL_ERR_SEQUENCE;
					}
				}
				else
				{
                    for(Index = 0 ; Index < LOGICAL_MAX ; Index++)
                    {
						if((StartAdd == FBL_ProgramBlInfo[Index].DataBlddress)&&
						((StartAdd+Length) <= (FBL_ProgramBlInfo[Index].DataBlddress+ \
										FBL_ProgramBlInfo[Index].DataBlLength)))
						{
							IndexValid = FBL_OK;
							FBL_CurrentBlIndex = Index;
							*BlockLength = 4093;
							FBL_TranDataAddres = StartAdd;	
							break;
						}
                    }

					/* Address judgment assignment, Then download the App */
					if(IndexValid == FBL_OK)
					{
						if((StartAdd == FBL_ProgramBlInfo[FBL_CurrentBlIndex].DataBlddress) && (SegmentNum < SEGMENT_MAX))
						{
							FBL_APP_SEGMENT_ADDRESS(FBL_CurrentBlIndex) = StartAdd;
							FBL_APP_SEGMENT_LENGTH(FBL_CurrentBlIndex) = Length;
							FBL_TranData0x36Verify = StartAdd;
							FBL_ErrorStatus = (Std_ReturnType)FBL_OK;
							SegmentNum++;
						}
						else
						{
							ret = (Std_ReturnType)FBL_ERR_SEQUENCE;
						}
					}
					else
					{
						ret = (Std_ReturnType)FBL_ERR_PHYSICAL_PAR;
					}
				}

				if(FBL_ErrorStatus == (Std_ReturnType)FBL_OK)
				{
					FBL_UDSCallStep = (Std_ReturnType)FBL_UDS0X36_STEP;
					 LZSS_Reset();			
					 SHA_Init();//重置SHA  Init

					if (StartAdd >= FLASH_DRIVE_ADDRESS)
					{
						uint8 buffer[8];
						extern sha256_ctx_t ctx;
						buffer[0] = (uint8)(StartAdd>>24);
						buffer[1] = (uint8)(StartAdd>>16);
						buffer[2] = (uint8)(StartAdd>>8);
						buffer[3] = (uint8)(StartAdd);
						buffer[4] = (uint8)(Length>>24);
						buffer[5] = (uint8)(Length>>16);
						buffer[6] = (uint8)(Length>>8);
						buffer[7] = (uint8)(Length);
						sha_update(&ctx, buffer, 8);
					}
					else
					{
						
					}



				}
				else
				{

				}
			}
			else
			{
				ret = (Std_ReturnType)FBL_EER_STEP;
			}
		}
		else
		{
			ret = (Std_ReturnType)FBL_EER_STEP;
		}
	}
	else
	{
		ret = (Std_ReturnType)FBL_ERR_PHYSICAL_PAR;
	}

	return ret;
}

STATIC FUNC(Std_ReturnType,AUTOMATIC) FBL_Dcm0x36Check(
	CONST(FBL_AddressType,AUTOMATIC)StartAdd,
	CONST(FBL_LengthType,AUTOMATIC)Length,
	P2CONST(uint8,AUTOMATIC,AUTOMATIC)SourceBuff
)
{
	VAR(Std_ReturnType,AUTOMATIC) ret = FBL_NOT_OK;
	/* Check the parameters  */
	if((NULL_PTR != SourceBuff) && ((Length > 0U) && (StartAdd == FBL_TranData0x36Verify)))
	{
		ret = FBL_OK;
	}
	return ret;
}

/**
 * @sid				   0x01
 * @brief              0x36 service. The data that is received is programmed and invoked by the DCM.
 * @details			   The 36 data transfer service, receiving data that needs to be downloaded to
 *                     the storage space, can be used to write the data directly to ram in the
 *                     current flash drive,and the flash drive is required to write when loading
 *                     the app data.
 * @param[in]      	   StartAdd:Download the starting address
 *                     Length  :Download data length
 *                     SourceBuff:A array of downloaded data
 * @param[out]     	   None
 * @return             ret
 */

FUNC(Std_ReturnType,AUTOMATIC) FBL_Dcm0x36Call
(
	CONST(FBL_AddressType,AUTOMATIC) StartAdd,
	P2CONST(uint8,AUTOMATIC,AUTOMATIC) SourceBuff,
	CONST(FBL_LengthType,AUTOMATIC) Length
)
{
	VAR(Std_ReturnType,AUTOMATIC) ret = (Std_ReturnType)FBL_OK;
	VAR(SecM_CheckState,AUTOMATIC) checkState;
	CONST(FBL_AddressType,AUTOMATIC)  u32StartAdd = StartAdd;
	CONST(FBL_LengthType,AUTOMATIC)  u32Length = Length;

	ret = FBL_ErrorInit();

	if(ret == (Std_ReturnType)FBL_OK)
	{
		ret = FBL_Dcm0x36Check(u32StartAdd,u32Length,SourceBuff);    //检测长度地址等

		if(ret == (Std_ReturnType)FBL_OK)
		{
			/* Diagnostic procedure check  */
			if(FBL_UDSCallStep == (Std_ReturnType)FBL_UDS0X36_STEP)
			{
				FBL_TranDataLength = u32Length;
				FBL_TranDataBuff = SourceBuff;
				FBL_TranData0x36Verify += u32Length;
				
				if(FBL_FlashDrive == FBL_FLASH_DRIVE_INVALID)	//如果fls驱动无效，说明是第一次烧录数据（烧录的是fls驱动）
				{
					FBL_FlashDown(FBL_TranDataAddres,FBL_TranDataLength,FBL_TranDataBuff);  //调用烧录fls驱动程序

					sha_update(&ctx, FBL_TranDataBuff, FBL_TranDataLength);    //积累计算SHA

					FBL_FlashOperationState = FBL_DOWNLOAD_STATE;

					if(FBL_TranData0x36Verify == (FBL_FlashDriveInfo.FalshSegmentInfo.SegmentAddre + FBL_FlashDriveInfo.FalshSegmentInfo.SegmentLength))   //判断整个段是否传输完成
					{
						//完成SHA  计算
						SHA_Finish();
						/* 对比原始哈希与计算的哈希  */

						FBL_UDSCallStep = FBL_UDS0X37_STEP;     //状态机更新
					}
					else
					{
						FBL_UDSCallStep = FBL_UDS0X36_STEP;
					}
				}
				else
				{
					//先解压数据
					LZSS_Calculate();
					//sha_update(&ctx, FBL_TranDataBuff, FBL_TranDataLength);     //积累计算SHA

						if(FBL_TranData0x36Verify == (FBL_APP_SEGMENT_ADDRESS(FBL_CurrentBlIndex) + FBL_APP_SEGMENT_LENGTH(FBL_CurrentBlIndex)))
						{
							//完成SHA  计算，得到最终哈希值
							//SHA_Finish();
							SHA_Continue_Calculate();
							FBL_UDSCallStep = FBL_UDS0X37_STEP;
						}
						else
						{
							FBL_UDSCallStep = FBL_UDS0X36_STEP;
						}
				
				}

				FBL_ErrorStatus = (Std_ReturnType)FBL_OK;

			}
			else
			{
				ret = FBL_EER_STEP;
			}
		}
		else
		{
			ret = FBL_EER_PARAMETER;
		}
	}

	return ret;
}

/**
 * @sid				   0x02
 * @brief              0x37 service.When a paragraph is over, call 37 to end the current transmission.
 * @details			   End the current data transfer and change the transport step.
 * @param[in]          None
 * @param[out]     	   None
 * @return             ret
 */
FUNC(Std_ReturnType,AUTOMATIC) FBL_Dcm0x37Call(void)
{
	VAR(Std_ReturnType,AUTOMATIC) ret = (Std_ReturnType)FBL_NOT_OK;

	ret = FBL_ErrorInit();

	if(ret == (Std_ReturnType)FBL_OK)
	{
		if(FBL_UDSCallStep == (Std_ReturnType)FBL_UDS0X37_STEP)
		{
			FBL_UDSCallStep = FBL_UDS_DEPEND_CHECK_STEP;
			FBL_ErrorStatus = (Std_ReturnType)FBL_OK;
			ret = (Std_ReturnType)FBL_OK;
		}
		else
		{
			ret = (Std_ReturnType)FBL_NOT_OK;
		}
	}
    return ret;
}


FUNC(Std_ReturnType,AUTOMATIC) FBL_Dcm0x31DD02Check(P2CONST(uint8,AUTOMATIC,AUTOMATIC) SourceBuff)
{
	VAR(Std_ReturnType,AUTOMATIC) ret = (Std_ReturnType)E_NOT_OK;

	

	if (FBL_TranDataAddres >= FLASH_DRIVE_ADDRESS)
	{
			ret = RSA_Calculate(SourceBuff);
			if(ret == E_OK)
			{
				FBL_FlashDrive = FBL_FLASH_DRIVE_VALID;
			}
			else
			{
				FBL_FlashDrive = FBL_FLASH_DRIVE_INVALID;
				FBL_ErrorMark = (boolean)TRUE;
			}
	}
	else{

			ret = RSA_Calculate(SourceBuff);
			if(ret == E_OK)
			{
				FBL_AppProgramInfo.FBL_AppStatus.AppValid = (uint8)TRUE ;
			}
			else
			{
				FBL_AppProgramInfo.FBL_AppStatus.AppValid = (uint8)FALSE;
				FBL_ErrorMark = (boolean)TRUE;

			}
	}


	/*pxc*/
//	ret =E_OK;

	return ret;
}
/**
 * @sid				   0x06
 * @brief              flash Bootloader module initialize.
 * @details			   flash Bootloader module initialize,Change the flag bit and the step working state to default.
 * @param[in]      	   None
 * @param[out]     	   None.
 * @return             ret
 */
FUNC(void,AUTOMATIC) FBL_Init(void)
{
	uint8 index = 0;

	FBL_FlashOperationState = FBL_WAIT_DOWNLOAD_STATE;

	FBL_UDSCallStep = FBL_UDS0X34_STEP;

	FBL_FlashDrive =FBL_FLASH_DRIVE_INVALID;

	FBL_ErrorStatus = (Std_ReturnType)FBL_OK;

	FBL_ErasingSuccess = (boolean)FALSE;

	FBL_ErrorMark = (boolean)FALSE;

	FBL_FlashDriveInfo.FlashAddress = 0U;
	FBL_FlashDriveInfo.FlashCrcCheck = 0U;
	FBL_FlashDriveInfo.FlashLength = 0U;
	FBL_FlashDriveInfo.FalshSegmentInfo.SegmentAddre = 0U;
	FBL_FlashDriveInfo.FalshSegmentInfo.SegmentCrcCheck = 0U;
	FBL_FlashDriveInfo.FalshSegmentInfo.SegmentLength = 0U;

	FBL_AppProgramInfo.CrcCheck = 0U;
	FBL_AppProgramInfo.FBL_AppStatus.AppValid = FALSE;
	FBL_AppProgramInfo.FBL_AppStatus.AppDownSucNum = 0U;
	FBL_AppProgramInfo.FBL_AppStatus.AppPrograNum = 0U;
	FBL_AppProgramInfo.FBL_LogicalBlInfo.BlockNumber = 0U;

	for(index = 0U ; index < LOGICAL_MAX ; index++)
	{
		FBL_APP_LOGIC_BLOCK_ADRESS(index) = 0U;
		FBL_APP_LOGIC_BLOCK_CRCCHECK(index) = 0U;
		FBL_APP_LOGIC_BLOCK_LENGTH(index) = 0U;
		FBL_APP_LOGIC_BLOCK_PRONUM(index) = 0U;
		FBL_APP_LOGIC_BLOCK_STATUE(index) = FALSE;
		FBL_APP_SEGMENT_ADDRESS(index) = 0U;
		FBL_APP_SEGMENT_CRCCHECK(index) = 0U;
		FBL_APP_SEGMENT_LENGTH(index) = 0U;
	}
}

/**
 * @sid				   0x07
 * @brief              Flash performs the task processing interface.
 * @details			   Flash performs the task processing interface.
 * @param[in]      	   None
 * @param[out]     	   None
 * @return             None
 */
FUNC(void,AUTOMATIC) FBL_MainFunction(void)
{
	/* Error management task*/
//	if(FBL_ErrorMark == (boolean)TRUE)
//	{
//		BM_DeInit();
//	}
}


#ifdef __cplusplus
}
#endif
/** @} */
