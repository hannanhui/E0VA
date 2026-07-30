/**
 * @file        Dcm_UDS0x36.c
 * @brief       AUTOSAR 4.2.2 - 4.2.2 driver source file.
 * @details     Dcm driver source file, containing the C implementation of Autosar API specification
 *              and other variables and functions that are exported by the Dcm driver.
 * @version     1.2.0
 *
 * @addtogroup  Dcm
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

/* PRQA S 0292, 0857, 0491, 5087 EOF #
 *
 * 1.0292 -- Violates MISRA 2004 Required Rule 3.1, Source file has comments containing one of the
 * characters '$', '@' or '`'.
 *
 * 2.0857 -- Violates MISRA 2004 Required Rule 1.1, Number of macro definitions exceeds 1024 - program
 * does not conform strictly to ISO:C90.
 *
 * 3.0491 -- Violates MISRA 2004 Required Rule 17.4, Array subscripting applied to an object of pointer
 * type.
 *
 * 4.5087 -- Violates MISRA 2004 Required Rule 19.1, Use of #include directive after code fragment.
 *
 * @page misra_violations MISRA-C:2004 violations
 */

/*====================================================================================================*
 *                                           INCLUDE FILES
 *====================================================================================================*/
#include "Dcm_Internal.h"

#ifdef AH_TEST_DCM
#include "TestCode.h"
#endif /* #ifdef AH_TEST_DCM */

#if(STD_ON == DCM_UDS0x36_ENABLE)
#if(STD_ON == DCM_UDS0x36_INTERNAL_FNC_ENABLE)
/**
 * @req [SWS_Dcm_00502] The Dcm module shall implement the TransferData (service 0x36) of the Unified
 * 		Diagnostic Services.
 */
/*====================================================================================================*
 *                                  SOURCE FILE VERSION INFORMATION
 *====================================================================================================*/
#define DCM_UDS0X36_VENDOR_ID_C                            	(0x00U)
#define DCM_UDS0X36_AR_RELEASE_MAJOR_VERSION_C             	(0x04U)
#define DCM_UDS0X36_AR_RELEASE_MINOR_VERSION_C             	(0x02U)
#define DCM_UDS0X36_AR_RELEASE_REVISION_VERSION_C          	(0x02U)
#define DCM_UDS0X36_SW_MAJOR_VERSION_C                     	(0x01U)
#define DCM_UDS0X36_SW_MINOR_VERSION_C                     	(0x02U)
#define DCM_UDS0X36_SW_PATCH_VERSION_C                     	(0x00U)
/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/
/* Check if current file and Dcm_Internal header file are of the same vendor */
#if(DCM_UDS0X36_VENDOR_ID_C != DCM_INTERNAL_VENDOR_ID )
#error "Dcm_UDS0x36.c and Dcm_Internal.h have different vendor id"
#endif
/* Check if current file and Dcm_Internal header file are of the same Autosar version */
#if(\
		(DCM_UDS0X36_AR_RELEASE_MAJOR_VERSION_C != DCM_INTERNAL_AR_RELEASE_MAJOR_VERSION) || \
		(DCM_UDS0X36_AR_RELEASE_MINOR_VERSION_C != DCM_INTERNAL_AR_RELEASE_MINOR_VERSION) || \
		(DCM_UDS0X36_AR_RELEASE_REVISION_VERSION_C != DCM_INTERNAL_AR_RELEASE_REVISION_VERSION) \
)
#error "AutoSar Version Number of Dcm_UDS0x36.c and Dcm_Internal.h are different"
#endif
/* Check if current file and Dcm_Internal header file are of the same software version */
#if(\
		(DCM_UDS0X36_SW_MAJOR_VERSION_C != DCM_INTERNAL_SW_MAJOR_VERSION) || \
		(DCM_UDS0X36_SW_MINOR_VERSION_C != DCM_INTERNAL_SW_MINOR_VERSION) || \
		(DCM_UDS0X36_SW_PATCH_VERSION_C != DCM_INTERNAL_SW_PATCH_VERSION) \
)
#error "Software Version Number of Dcm_UDS0x36.c and Dcm_Internal.h are different"
#endif
/*====================================================================================================*
 *                                   EXTERNAL FUNCTION DECLARATIONS
 *====================================================================================================*/

/*====================================================================================================*
 *                                           LOCAL TYPEDEFS
 *====================================================================================================*/

/*====================================================================================================*
 *                                            LOCAL MACROS
 *====================================================================================================*/
#ifdef AH_UNITTEST_ENABLED

	#ifdef STATIC
		#undef STATIC
		#define STATIC
	#else
		#define STATIC
	#endif /* STATIC */

	#ifdef INLINE
		#undef INLINE
		#define INLINE
	#else
		#define STATIC_INLINE
	#endif /* INLINE */

	#ifdef STATIC_INLINE
		#undef STATIC_INLINE
		#define STATIC_INLINE
	#else
		#define STATIC_INLINE
	#endif /* STATIC_INLINE */
#else
	#ifndef STATIC
		#define STATIC static
	#endif /* STATIC */

	#ifndef INLINE
		#define INLINE inline
	#endif /* INLINE */

	#ifndef STATIC_INLINE
		#define STATIC_INLINE static inline
	#endif /* STATIC_INLINE */

#endif /* AH_UNITTEST_ENABLED */
/*====================================================================================================*
 *                                           LOCAL CONSTANTS
 *====================================================================================================*/

/*====================================================================================================*
 *                                           LOCAL VARIABLES
 *====================================================================================================*/

/*====================================================================================================*
 *                                      LOCAL FUNCTION PROTOTYPES
 *====================================================================================================*/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"

STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x36BlockSeqCntCheck
(
	uint8 u8ReqBlockSeqCnt,
	P2VAR(boolean, AUTOMATIC, DCM_VAR)pProcessState,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
);

#if(STD_ON == DCM_UDS0x34_ENABLE)
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x36DownloadHandle
(
	uint32 u32RecordDataLen,
	Dcm_OpStatusType opState,
	P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
);
#endif /* #if(STD_ON == DCM_UDS0x34_ENABLE) */

#if(STD_ON == DCM_UDS0x35_ENABLE)
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x36UploadHandle
(
	Dcm_OpStatusType opState,
	P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
);
#endif /* #if(STD_ON == DCM_UDS0x35_ENABLE) */
/*====================================================================================================*
 *                                           LOCAL FUNCTIONS
 *====================================================================================================*/
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x36BlockSeqCntCheck
(
	uint8 u8ReqBlockSeqCnt,
	P2VAR(boolean, AUTOMATIC, DCM_VAR)pProcessState,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
)
{
	Std_ReturnType result = (Std_ReturnType)E_OK;

	uint8 u8LastBlockSeqCnt;

	if(Dcm_TransferStatus.BlockSeqCnt != u8ReqBlockSeqCnt)
	{
		/**
		 * @req [SWS_Dcm_00645] On reception of the UDS Service TransferData (0x36), if a block sequence
		 * 		error is detected, the DCM module shall trigger a negative response with NRC 0x73
		 * 		(WrongBlockSequenceCounter).
		 */
		if((boolean)TRUE == Dcm_TransferStatus.IsFirstBlock)
		{
			*pErrorCode = DCM_E_WRONGBLOCKSEQUENCECOUNTER;

			result = (Std_ReturnType)E_NOT_OK;
		}
		else
		{
			if(0u == Dcm_TransferStatus.BlockSeqCnt)
			{
				u8LastBlockSeqCnt = 255u;
			}
			else
			{
				u8LastBlockSeqCnt = (Dcm_TransferStatus.BlockSeqCnt - 1u);
			}

			if(u8ReqBlockSeqCnt != u8LastBlockSeqCnt)
			{
				*pErrorCode = DCM_E_WRONGBLOCKSEQUENCECOUNTER;

				result = (Std_ReturnType)E_NOT_OK;
			}
			else if(DCM_TRANSFER_DOWNLOAD == Dcm_TransferStatus.Process)
			{
				*pProcessState = (boolean)FALSE;
			}
			else
			{
				if(1u < Dcm_TransferStatus.BlockSeqCnt)
				{
					Dcm_TransferStatus.BlockSeqCnt--;
				}
				else
				{
					Dcm_TransferStatus.BlockSeqCnt = 255u;
				}
				Dcm_TransferStatus.MemoryAddr -= Dcm_TransferStatus.BlockLength;
				Dcm_TransferStatus.MemorySize += Dcm_TransferStatus.BlockLength;
			}
		}
	}

	return result;
}

#if(STD_ON == DCM_UDS0x34_ENABLE)
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x36DownloadHandle
(
	uint32 u32RecordDataLen,
	Dcm_OpStatusType opState,
	P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
)
{
	Std_ReturnType result = (Std_ReturnType)E_OK;

	Dcm_ReturnWriteMemoryType OpRet;

	if((DCM_PENDING != opState) && (DCM_FORCE_RCRRP_OK != opState))
	{
		/*pxc modify first 1*/
		if(((Dcm_TransferStatus.BlockLength <= Dcm_TransferStatus.MemorySize) && (u32RecordDataLen != Dcm_TransferStatus.BlockLength))\
			|| ((Dcm_TransferStatus.BlockLength > Dcm_TransferStatus.MemorySize) && (((boolean)FALSE == Dcm_TransferStatus.IsLastBlock)\
			|| (u32RecordDataLen != Dcm_TransferStatus.MemorySize))))
		{
			*pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;

			result = (Std_ReturnType)E_NOT_OK;
		}
	}

	if((Std_ReturnType)E_OK == result)
	{
		/**
		 * @req [SWS_Dcm_00503] On reception of the UDS Service TransferData (0x36), if a download
		 * 		process is running (RequestDownload service has been previously received) and the
		 * 		request format is correct, the DCM module shall call the callout Dcm_WriteMemory().
		 */
		OpRet = Dcm_WriteMemory(\
						opState, Dcm_TransferStatus.MemoryId, Dcm_TransferStatus.MemoryAddr,\
						u32RecordDataLen, &pMsgContext->ReqData[2], pErrorCode\
						);

		if((Dcm_ReturnWriteMemoryType)DCM_WRITE_OK == OpRet)
		{
			if(255u != Dcm_TransferStatus.BlockSeqCnt)
			{
				Dcm_TransferStatus.BlockSeqCnt++;
			}
			else
			{
				Dcm_TransferStatus.BlockSeqCnt = 0u;
			}
			Dcm_TransferStatus.MemoryAddr += u32RecordDataLen;
			Dcm_TransferStatus.MemorySize -= u32RecordDataLen;

			if(0u == Dcm_TransferStatus.MemorySize)
			{
				Dcm_TransferStatus.Process = DCM_TRANSFER_EXIT;
			}
			else
			{
				if(Dcm_TransferStatus.BlockLength > Dcm_TransferStatus.MemorySize)
				{
					Dcm_TransferStatus.IsLastBlock = (boolean)TRUE;
				}
			}

			pMsgContext->ResDataLen = 2u;
		}
		else
		{
			if((Dcm_ReturnWriteMemoryType)DCM_WRITE_PENDING == OpRet)
			{
				Dcm_OpState = DCM_PENDING;
				*pErrorCode = DCM_E_RESPONSE_PENDING;
			}
			else if((Dcm_ReturnWriteMemoryType)DCM_WRITE_FORCE_RCRRP == OpRet)
			{
				Dcm_OpState = DCM_FORCE_RCRRP_OK;
				*pErrorCode = DCM_E_RESPONSE_PENDING;
			}
			else
			{
				/* Nothing to do here. */
				;
			}

			result = (Std_ReturnType)E_NOT_OK;
		}
	}

	return result;
}
#endif /* #if(STD_ON == DCM_UDS0x34_ENABLE) */

#if(STD_ON == DCM_UDS0x35_ENABLE)
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x36UploadHandle
(
	Dcm_OpStatusType opState,
	P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
)
{
	Std_ReturnType result = (Std_ReturnType)E_OK;

	uint32 u32RecordDataLen;
	Dcm_ReturnReadMemoryType OpRet;

	if(Dcm_TransferStatus.BlockLength <= Dcm_TransferStatus.MemorySize)
	{
		u32RecordDataLen = Dcm_TransferStatus.BlockLength;
	}
	else
	{
		u32RecordDataLen = Dcm_TransferStatus.MemorySize;
	}

	/**
	 * @req [SWS_Dcm_00504] On reception of the UDS Service TransferData (0x36), if an upload process
	 * 		is running (RequestUpload service has been previously received) and the request format is
	 * 		correct, the DCM module shall call the callout Dcm_ReadMemory().
	 */
	OpRet = Dcm_ReadMemory(\
					opState, Dcm_TransferStatus.MemoryId, Dcm_TransferStatus.MemoryAddr,\
					u32RecordDataLen, &pMsgContext->ResData[2], pErrorCode\
					);

	if((Dcm_ReturnReadMemoryType)DCM_READ_OK == OpRet)
	{
		if(255u != Dcm_TransferStatus.BlockSeqCnt)
		{
			Dcm_TransferStatus.BlockSeqCnt++;
		}
		else
		{
			Dcm_TransferStatus.BlockSeqCnt = 0u;
		}
		Dcm_TransferStatus.MemoryAddr += u32RecordDataLen;
		Dcm_TransferStatus.MemorySize -= u32RecordDataLen;

		if(0u == Dcm_TransferStatus.MemorySize)
		{
			Dcm_TransferStatus.Process = DCM_TRANSFER_EXIT;
		}

		pMsgContext->ResDataLen = (u32RecordDataLen + 2u);
	}
	else
	{
		if((Dcm_ReturnWriteMemoryType)DCM_READ_PENDING == OpRet)
		{
			Dcm_OpState = DCM_PENDING;
			*pErrorCode = DCM_E_RESPONSE_PENDING;
		}
		else if((Dcm_ReturnWriteMemoryType)DCM_READ_FORCE_RCRRP == OpRet)
		{
			Dcm_OpState = DCM_FORCE_RCRRP_OK;
			*pErrorCode = DCM_E_RESPONSE_PENDING;
		}
		else
		{
			/* Nothing to do here. */
			;
		}

		result = (Std_ReturnType)E_NOT_OK;
	}

	return result;
}
#endif /* #if(STD_ON == DCM_UDS0x35_ENABLE) */
/*====================================================================================================*
 *                                          GLOBAL FUNCTIONS
 *====================================================================================================*/
/**
 * @brief			Dcm_UDS0x36
 * @details			Internal processing interface for Service 0x36.
 *
 * @param[in]		OpStatus:Operating state.
 * @param[in]		pMsgContext:Message-related information for one diagnostic protocol identifier.
 * 					The pointers in pMsgContext shall point behind the SID.
 *
 * @param[out]		ErrorCode:If the operation <Module>_<DiagnosticService> returns value  E_NOT_OK,
 * 					the DCM module shall send a negative response  with NRC code equal to the parameter
 * 					ErrorCode parameter value.
 *
 * @return        	Result of this operation.
 * @retval			E_OK:Request was successful.
 * @retval			E_NOT_OK:Request was not successful.
 */
FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x36
(
	Dcm_OpStatusType OpStatus,
	P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
)
{
	Std_ReturnType result = (Std_ReturnType)E_NOT_OK;

	boolean processFlag = (boolean)TRUE;

	if((DCM_PENDING != OpStatus) && (DCM_FORCE_RCRRP_OK != OpStatus))
	{
#if((STD_ON == DCM_UDS0x34_ENABLE) && (STD_ON == DCM_UDS0x35_ENABLE))
		if(2u > pMsgContext->ReqDataLen)
#elif(STD_ON == DCM_UDS0x34_ENABLE)
		if(3u > pMsgContext->ReqDataLen)
#else
		if(2u != pMsgContext->ReqDataLen)
#endif /* #if((STD_ON == DCM_UDS0x34_ENABLE) && (STD_ON == DCM_UDS0x35_ENABLE)) */
		{
			*ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
		}
		else if((DCM_TRANSFER_IDLE == Dcm_TransferStatus.Process)\
				|| (DCM_TRANSFER_EXIT == Dcm_TransferStatus.Process))
		{
			*ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
		}
		else
		{
			result = Dcm_UDS0x36BlockSeqCntCheck(pMsgContext->ReqData[1], &processFlag, ErrorCode);
		}
	}
	else
	{
		result = (Std_ReturnType)E_OK;
	}

	if((Std_ReturnType)E_OK == result)
	{
		switch(Dcm_TransferStatus.Process)
		{
#if(STD_ON == DCM_UDS0x34_ENABLE)
		case DCM_TRANSFER_DOWNLOAD:

			if((boolean)TRUE == processFlag)
			{
				result = Dcm_UDS0x36DownloadHandle((pMsgContext->ReqDataLen - 2u), OpStatus, pMsgContext, ErrorCode);
			}
			else
			{
				pMsgContext->ResDataLen = 2u;
			}

			break;
#endif /* #if(STD_ON == DCM_UDS0x34_ENABLE) */
#if(STD_ON == DCM_UDS0x35_ENABLE)
		case DCM_TRANSFER_UPLOAD:

			result = Dcm_UDS0x36UploadHandle(OpStatus, pMsgContext, ErrorCode);

			break;
#endif /* #if(STD_ON == DCM_UDS0x35_ENABLE) */
		default:
			/* Nothing to do here. */
			break;
		}

		if((Std_ReturnType)E_OK == result)
		{
			/* For the 0x35 service, the maximum response length is the block length, and for the 0x36
			 * service, the minimum length of the buffer is 8 bytes, no need to check the response
			 * length. */

			pMsgContext->ResData[0] = 0x76u;
			pMsgContext->ResData[1] = pMsgContext->ReqData[1];
		}
	}

	return result;
}

#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#endif /* #if(STD_ON == DCM_UDS0x36_INTERNAL_FNC_ENABLE) */
#endif /* #if(STD_ON == DCM_UDS0x36_ENABLE) */

#ifdef __cplusplus
}
#endif
/** @} */
