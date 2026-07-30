/**
 * @file        Dcm_UDS0x2E.c
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

/* PRQA S 0292, 0857, 0491, 2981, 5087, 0498 EOF #
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
 * 4.2981 -- Violates MISRA 2004 Required Rule 21.1, This initialization is redundant. The value of this
 * object is never used before being modified.
 *
 * 5.5087 -- Violates MISRA 2004 Required Rule 19.1, Use of #include directive after code fragment.
 *
 * 6.0498 -- Violates MISRA 2004 Required Rule 17.4, A unary increment or decrement operator is being
 * applied to a pointer.
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

#if(STD_ON == DCM_UDS0x2E_ENABLE)
#if(STD_ON == DCM_UDS0x2E_INTERNAL_FNC_ENABLE)
/**
 * @req [SWS_Dcm_00255] The Dcm module shall implement the UDS Service WriteDataByIdentifier (0x2E) of
 * 		the Unified Diagnostic Services.
 */
/*====================================================================================================*
 *                                  SOURCE FILE VERSION INFORMATION
 *====================================================================================================*/
#define DCM_UDS0X2E_VENDOR_ID_C                            	(0x00U)
#define DCM_UDS0X2E_AR_RELEASE_MAJOR_VERSION_C             	(0x04U)
#define DCM_UDS0X2E_AR_RELEASE_MINOR_VERSION_C             	(0x02U)
#define DCM_UDS0X2E_AR_RELEASE_REVISION_VERSION_C          	(0x02U)
#define DCM_UDS0X2E_SW_MAJOR_VERSION_C                     	(0x01U)
#define DCM_UDS0X2E_SW_MINOR_VERSION_C                     	(0x02U)
#define DCM_UDS0X2E_SW_PATCH_VERSION_C                     	(0x00U)
/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/
/* Check if current file and Dcm_Internal header file are of the same vendor */
#if(DCM_UDS0X2E_VENDOR_ID_C != DCM_INTERNAL_VENDOR_ID )
#error "Dcm_UDS0x2E.c and Dcm_Internal.h have different vendor id"
#endif
/* Check if current file and Dcm_Internal header file are of the same Autosar version */
#if(\
		(DCM_UDS0X2E_AR_RELEASE_MAJOR_VERSION_C != DCM_INTERNAL_AR_RELEASE_MAJOR_VERSION) || \
		(DCM_UDS0X2E_AR_RELEASE_MINOR_VERSION_C != DCM_INTERNAL_AR_RELEASE_MINOR_VERSION) || \
		(DCM_UDS0X2E_AR_RELEASE_REVISION_VERSION_C != DCM_INTERNAL_AR_RELEASE_REVISION_VERSION) \
)
#error "AutoSar Version Number of Dcm_UDS0x2E.c and Dcm_Internal.h are different"
#endif
/* Check if current file and Dcm_Internal header file are of the same software version */
#if(\
		(DCM_UDS0X2E_SW_MAJOR_VERSION_C != DCM_INTERNAL_SW_MAJOR_VERSION) || \
		(DCM_UDS0X2E_SW_MINOR_VERSION_C != DCM_INTERNAL_SW_MINOR_VERSION) || \
		(DCM_UDS0X2E_SW_PATCH_VERSION_C != DCM_INTERNAL_SW_PATCH_VERSION) \
)
#error "Software Version Number of Dcm_UDS0x2E.c and Dcm_Internal.h are different"
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
#define DCM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dcm_MemMap.h"

/**
 * @brief	Store internal status of service 0x2E during its processing.
 */
STATIC VAR(Dcm_WriteDataByDidStatusType, DCM_VAR)Dcm_UDS0x2EStatus;

#define DCM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dcm_MemMap.h"
/*====================================================================================================*
 *                                      LOCAL FUNCTION PROTOTYPES
 *====================================================================================================*/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"

#if((0u != DCM_DSP_DID_NUM) || (0u != DCM_DSP_DID_RANGE_NUM))
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x2EReqDidCheck
(
	Dcm_OpStatusType opState,
	P2VAR(uint8, AUTOMATIC, DCM_VAR)pReqDidIdx,
	P2VAR(boolean, AUTOMATIC, DCM_VAR)pIsRangeDid,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
);
#endif /* #if((0u != DCM_DSP_DID_NUM) || (0u != DCM_DSP_DID_RANGE_NUM)) */

#if(0u != DCM_DSP_DID_NUM)
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x2ESingleDidProcess
(
	uint8 u8ReqDidIdx,
	Dcm_OpStatusType opState,
	P2CONST(Dcm_MsgContextType, AUTOMATIC, DCM_CONST)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
);
#endif /* #if(0u != DCM_DSP_DID_NUM) */

#if(0u != DCM_DSP_DID_RANGE_NUM)
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x2ERangeDidProcess
(
	uint8 u8ReqDidIdx,
	Dcm_OpStatusType opState,
	P2CONST(Dcm_MsgContextType, AUTOMATIC, DCM_CONST)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
);
#endif /* #if(0u != DCM_DSP_DID_RANGE_NUM) */

STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x2EDidProcess
(
	Dcm_OpStatusType opState,
	P2CONST(Dcm_MsgContextType, AUTOMATIC, DCM_CONST)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
);
/*====================================================================================================*
 *                                           LOCAL FUNCTIONS
 *====================================================================================================*/
#if((0u != DCM_DSP_DID_NUM) || (0u != DCM_DSP_DID_RANGE_NUM))
/**
 * @brief			Dcm_UDS0x2EReqDidCheck
 * @details			Check whether the requested Did is valid.
 *
 * @param[in]		opState:Operating state.
 *
 * @param[out]		pReqDidIdx:If the requested Did is valid, output its index within the configuration.
 * @param[out]		pIsRangeDid:Output whether the requested Did is a range Did.
 * @param[out]		pErrorCode:If error occur, output the NRC.
 *
 * @return        	Result of this operation.
 * @retval			E_OK:Processing successful.
 * @retval			E_NOT_OK:Processing failure.
 */
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x2EReqDidCheck
(
	Dcm_OpStatusType opState,
	P2VAR(uint8, AUTOMATIC, DCM_VAR)pReqDidIdx,
	P2VAR(boolean, AUTOMATIC, DCM_VAR)pIsRangeDid,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
)
{
	Std_ReturnType result = (Std_ReturnType)E_NOT_OK;

	uint16 u16ReqDid = Dcm_UDS0x2EStatus.ReqDid;

	/**
	 * @req [SWS_Dcm_00467] On reception of the UDS Service WriteDataByIdentifier (0x2E), the DCM
	 * 		module shall check if the DID is supported (see configuration parameter DcmDspDid and
	 * 		DcmDspDidRange) If not, the DCM module shall send NRC 0x31 (Request out of range) .
	 */

#if(0u != DCM_DSP_DID_NUM)

#if((STD_ON == DCM_UDS0x2C_ENABLE) || (STD_ON == DCM_UDS0x2A_ENABLE))

	result = DspInternal_CheckDidValid(\
				u16ReqDid, DCM_PERMISSION_CHECK_USER_WRITE_DID, pReqDidIdx, NULL_PTR, NULL_PTR, pErrorCode\
				);

#else

	result = DspInternal_CheckDidValid(\
				u16ReqDid, DCM_PERMISSION_CHECK_USER_WRITE_DID, pReqDidIdx, pErrorCode\
				);

#endif /* #if((STD_ON == DCM_UDS0x2C_ENABLE) || (STD_ON == DCM_UDS0x2A_ENABLE)) */

#if(0u != DCM_DSP_DID_RANGE_NUM)

	if(((Std_ReturnType)E_NOT_OK == result) && (DCM_E_REQUESTOUTOFRANGE == *pErrorCode))
	{
		result = DspInternal_CheckRangeDidValid(\
					u16ReqDid, opState, DCM_PERMISSION_CHECK_USER_WRITE_DID, pReqDidIdx, pErrorCode\
					);

		if((Std_ReturnType)E_OK == result)
		{
			*pIsRangeDid = (boolean)TRUE;
		}
	}

#endif /* #if(0u != DCM_DSP_DID_RANGE_NUM) */

#else

	/* If not exist the Single-DIDs, then the Range-DIDs must exist.  */

	result = DspInternal_CheckRangeDidValid(\
				u16ReqDid, opState, DCM_PERMISSION_CHECK_USER_WRITE_DID, pReqDidIdx, pErrorCode\
				);

	if((Std_ReturnType)E_OK == result)
	{
		*pIsRangeDid = (boolean)TRUE;
	}

#endif /* #if(0u != DCM_DSP_DID_NUM) */

	return result;
}
#endif /* #if((0u != DCM_DSP_DID_NUM) || (0u != DCM_DSP_DID_RANGE_NUM)) */

#if(0u != DCM_DSP_DID_NUM)
/**
 * @brief			Dcm_UDS0x2ESingleDidProcess
 * @details			Handler for writing non-range Did data.
 *
 * @param[in]		u8ReqDidIdx:The index of the non-range Did to be write within the configuration.
 * @param[in]		opState:Operating state.
 * @param[in]		pMsgContext:Message-related information for one diagnostic protocol identifier.
 * 					The pointers in pMsgContext shall point behind the SID.
 *
 * @param[out]		pErrorCode:If the called external interface returns E_NOT_OK, use this pointer to
 * 					output the NRC.
 *
 * @return        	Result of this operation.
 * @retval			E_OK:Processing successful.
 * @retval			E_NOT_OK:Processing failure.
 */
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x2ESingleDidProcess
(
	uint8 u8ReqDidIdx,
	Dcm_OpStatusType opState,
	P2CONST(Dcm_MsgContextType, AUTOMATIC, DCM_CONST)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
)
{
	Std_ReturnType result = (Std_ReturnType)E_OK;

	uint8 u8Index;
	uint16 u16SignalLen;
	uint16 u16DataMinLen = 3u;
	uint16 u16DataMaxLen = 3u;
#if(0u)
#if(0u != DCM_DSP_DATA_BLOCK_USED_NUM)
	NvM_RequestResultType NvMRet = NVM_REQ_NOT_OK;
#endif /* #if(0u != DCM_DSP_DATA_BLOCK_USED_NUM) */
#endif /* #if(0u) */
#if(0u != DCM_DSP_DID_SIGNAL_NUM)
	uint8* pReqDataBuf = NULL_PTR;
#endif /* #if(0u != DCM_DSP_DID_SIGNAL_NUM) */
	const Dcm_DspDidType* pDid = &Dcm_ConfigPtr->DcmDsp->DcmDspDid[u8ReqDidIdx];
	const Dcm_DspDidSignalType* pSignal = NULL_PTR;
	const Dcm_DspDataType* pSignalData = NULL_PTR;

	if(DCM_PENDING != opState)
	{
		/**
		 * @req [SWS_Dcm_00473] On reception of the UDS Service WriteDataByIdentifier (0x2E), if all
		 * 		signals (DcmDspDidSignal) of the DID have fixed length (DcmDspDataType is different than
		 * 		UINT8_DYN), the Dcm module shall check if the received data length corresponds to the
		 * 		DID data length (addition of all DcmDspDataSize).
		 */
		for(u8Index = 0u; u8Index < pDid->DcmDspDidSignalNum; u8Index++)
		{
			pSignalData = pDid->DcmDspDidSignal[u8Index].DcmDspDidDataRef;

			u16SignalLen = (pSignalData->DcmDspDataSize / 8u);

			u16DataMaxLen += u16SignalLen;

			if(DCM_UINT8_DYN != pSignalData->DcmDspDataType)
			{
				u16DataMinLen += u16SignalLen;
			}
			else
			{
				Dcm_UDS0x2EStatus.SignalDynLen = ((uint16)pMsgContext->ReqDataLen - u16DataMinLen);
			}
		}
		if((pMsgContext->ReqDataLen < u16DataMinLen) || (pMsgContext->ReqDataLen > u16DataMaxLen))
		{
			*pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;

			result = (Std_ReturnType)E_NOT_OK;
		}
	}

#if(0u != DCM_DSP_DID_SIGNAL_NUM)

	if((Std_ReturnType)E_OK == result)
	{
		for(u8Index = Dcm_UDS0x2EStatus.ReqSignalIndex; u8Index < pDid->DcmDspDidSignalNum; u8Index++)
		{
			result = (Std_ReturnType)E_NOT_OK;

			Dcm_UDS0x2EStatus.ReqSignalIndex = u8Index;

			pSignal = &pDid->DcmDspDidSignal[u8Index];

			pReqDataBuf = &pMsgContext->ReqData[(pSignal->DcmDspDidDataPos / 8u) + 3u];

			pSignalData = pSignal->DcmDspDidDataRef;

			u16SignalLen = (pSignalData->DcmDspDataSize / 8u);

			switch(pSignalData->DcmDspDataUsePort)
			{
#if(STD_ON == DCM_DSP_DATA_WRITE_FNC_ENABLED)
				case DCM_USE_DATA_SYNCH_FNC:
				case DCM_USE_DATA_SYNCH_CLIENT_SERVER:
				case DCM_USE_DATA_ASYNCH_FNC:
				case DCM_USE_DATA_ASYNCH_FNC_ERROR:
				case DCM_USE_DATA_ASYNCH_CLIENT_SERVER:
				case DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR:
				case DCM_USE_DATA_SENDER_RECEIVER:
				case DCM_USE_DATA_SENDER_RECEIVER_AS_SERVICE:
					/**
					 * @req [SWS_Dcm_00395] After all verifications (see SWS_Dcm_00467, SWS_Dcm_00468,
					 * 		SWS_Dcm_00469, SWS_Dcm_00470, SWS_Dcm_00473 ) the Dcm module shall write all
					 * 		the signals (DcmDspDidSignal) of the DID by either calling the configured
					 * 		function DcmDspDataWriteFnc (if parameter DcmDspDataUsePort is set to
					 * 		USE_DATA_SYNCH_FNC or USE_DATA_ASYNCH_FNC or USE_DATA_ASYNCH_FNC_ERROR) or
					 * 		the associated WriteData operations (if parameter DcmDspDataUsePort is set
					 * 		to USE_DATA_SYNCH_CLIENT_SERVER or USE_DATA_ASYNCH_CLIENT_SERVER or
					 * 		USE_DATA_ASYNCH_CLIENT_SERVER_ERROR) or the associated SenderReceiver
					 * 		interfaces (if parameter DcmDspDataUsePort is set to
					 * 		USE_DATA_SENDER_RECEIVER or to USE_DATA_SENDER_RECEIVER_AS_SERVICE) with the
					 * 		following parameter values:
					 * 		Data: the dataRecord form the request,
					 * 		DataLength: the number of bytes in the dataRecord (get from the
					 * 		configuration if the data has fixed length (DcmDspDataType is different than
					 * 		UINT8_DYN) or from the diagnostic request length if the data has dynamic
					 * 		length (DcmDspDataType is set to UINT8_DYN)).
					 */
					if(DCM_UINT8_DYN == pSignalData->DcmDspDataType)
					{
						u16SignalLen = Dcm_UDS0x2EStatus.SignalDynLen;
					}
					if(NULL_PTR != pSignalData->DcmDspDataWriteFnc)
					{
						result = pSignalData->DcmDspDataWriteFnc(pReqDataBuf, u16SignalLen, opState, pErrorCode);
					}
					else
					{
						*pErrorCode = DCM_E_REQUESTOUTOFRANGE;
					}
					break;
#endif /* #if(STD_ON == DCM_DSP_DATA_READ_FNC_ENABLED) */
#if(0u != DCM_DSP_DATA_BLOCK_USED_NUM)
				case DCM_USE_BLOCK_ID:
#if(0u)
					/**
					 * @req [SWS_Dcm_00541] If the data is configured as a BlockId of the NvRam
					 * 		(parameter DcmDspDataUsePort set to USE_BLOCK_ID), the Dcm shall:
					 * 		1. Request NvM_SetBlockLockStatus(<DcmDspDataBlockIdRef>, FALSE), to
					 * 		   temporarily unlock the NvM Block (It might be locked by executing this
					 * 		   procedure before).
					 * 		2. Request NvM_WriteBlock(<DcmDspDataBlockIdRef >, <DataBuffer>) with
					 * 		   BlockId corresponding to the configuration parameter
					 * 		   DcmDspDataBlockIdRef).
					 * 		3. Poll for completion of write request, using NvM_GetErrorStatus().
					 * 		4.a) On success (NVM_REQ_OK), the DCM shall issue NvM_SetBlockLockStatus
					 * 		   (<DcmDspDataBlockIdRef >, TRUE) (to lock the NvM block against further
					 * 		   updates from the application) and send a positive response message.
					 * 		4.b) Otherwise (on any NvM failure) the DCM module shall trigger a negative
					 * 		   response with NRC 0x10 (GeneralReject).
					 */
					if((boolean)FALSE == Dcm_UDS0x2EStatus.WriteBlock)
					{
						NvM_SetBlockLockStatus(pSignalData->DcmDspDataBlockIdRef, (boolean)FALSE);

						result = NvM_WriteBlock(pSignalData->DcmDspDataBlockIdRef, pReqDataBuf);

						if((Std_ReturnType)E_OK == result)
						{
							Dcm_UDS0x2EStatus.WriteBlock = (boolean)TRUE;

							result = (Std_ReturnType)DCM_E_PENDING;
						}
					}
					else
					{
						result = NvM_GetErrorStatus(pSignalData->DcmDspDataBlockIdRef, &NvMRet);

						if((Std_ReturnType)E_OK == result)
						{
							if(NVM_REQ_OK == NvMRet)
							{
								NvM_SetBlockLockStatus(pSignalData->DcmDspDataBlockIdRef, (boolean)TRUE);
							}
							else if(NVM_REQ_PENDING == NvMRet)
							{
								result = (Std_ReturnType)DCM_E_PENDING;
							}
							else
							{
								result = (Std_ReturnType)E_NOT_OK;
							}
						}
					}
					if((Std_ReturnType)E_NOT_OK == result)
					{
						*pErrorCode = DCM_E_GENERALREJECT;
					}
#else
					(void)NvM_WriteBlock(pSignalData->DcmDspDataBlockIdRef, pReqDataBuf);

					DCM_MEMORY_COPY(pReqDataBuf, pSignalData->DcmDspDataInternalBuffer, u16SignalLen);

					result = (Std_ReturnType)E_OK;
#endif /* #if(0u) */
					break;
#endif /* #if(0u != DCM_DSP_DATA_BLOCK_USED_NUM) */
				default:
					(void)pReqDataBuf;
					*pErrorCode = DCM_E_REQUESTOUTOFRANGE;
					break;
			}

			if((Std_ReturnType)E_OK != result)
			{
				break;
			}
		}
	}

#else

	*pErrorCode = DCM_E_REQUESTOUTOFRANGE;

	result = (Std_ReturnType)E_NOT_OK;

#endif /* #if(0u != DCM_DSP_DID_SIGNAL_NUM) */

	return result;
}
#endif /* #if(0u != DCM_DSP_DID_NUM) */

#if(0u != DCM_DSP_DID_RANGE_NUM)
/**
 * @brief			Dcm_UDS0x2ERangeDidProcess
 * @details			Handler for writing range Did data.
 *
 * @param[in]		u8ReqDidIdx:The index of the range Did to be write within the configuration.
 * @param[in]		opState:Operating state.
 * @param[in]		pMsgContext:Message-related information for one diagnostic protocol identifier.
 * 					The pointers in pMsgContext shall point behind the SID.
 *
 * @param[out]		pErrorCode:If the called external interface returns E_NOT_OK, use this pointer to
 * 					output the NRC.
 *
 * @return        	Result of this operation.
 * @retval			E_OK:Processing successful.
 * @retval			E_NOT_OK:Processing failure.
 */
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x2ERangeDidProcess
(
	uint8 u8ReqDidIdx,
	Dcm_OpStatusType opState,
	P2CONST(Dcm_MsgContextType, AUTOMATIC, DCM_CONST)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
)
{
	Std_ReturnType result = (Std_ReturnType)E_NOT_OK;

#if(STD_ON == DCM_DSP_DID_RANGE_WRITE_DID_FNC_ENABLE)
	uint16 u16ReqDid = Dcm_UDS0x2EStatus.ReqDid;
#endif /* #if(STD_ON == DCM_DSP_DID_RANGE_WRITE_DID_FNC_ENABLE) */
	uint16 u16DataLen = ((uint16)pMsgContext->ReqDataLen - 3u);
	const Dcm_DspDidRangeType* pRangeDid = &Dcm_ConfigPtr->DcmDsp->DcmDspDidRange[u8ReqDidIdx];

	if(u16DataLen > pRangeDid->DcmDspDidRangeMaxDataLength)
	{
		*pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
	}
	else
	{
#if(STD_ON == DCM_DSP_DID_RANGE_WRITE_DID_FNC_ENABLE)

		if(NULL_PTR != pRangeDid->DcmDspDidRangeWriteDidFnc)
		{
			result = pRangeDid->DcmDspDidRangeWriteDidFnc(u16ReqDid, &pMsgContext->ReqData[3], opState, u16DataLen, pErrorCode);
		}

#else

		*pErrorCode = DCM_E_REQUESTOUTOFRANGE;

#endif /* #if(STD_ON == DCM_DSP_DID_RANGE_WRITE_DID_FNC_ENABLE) */
	}

	return result;
}
#endif /* #if(0u != DCM_DSP_DID_RANGE_NUM) */

/**
 * @brief			Dcm_UDS0x2EDidProcess
 * @details			Check whether the Did is valid and execute the corresponding handler.
 *
 * @param[in]		opState:Operating state.
 * @param[in]		pMsgContext:Message-related information for one diagnostic protocol identifier.
 * 					The pointers in pMsgContext shall point behind the SID.
 *
 * @param[out]		pErrorCode:If the called external interface returns E_NOT_OK, use this pointer to
 * 					output the NRC.
 *
 * @return        	Result of this operation.
 * @retval			E_OK:Processing successful.
 * @retval			E_NOT_OK:Processing failure.
 */
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x2EDidProcess
(
	Dcm_OpStatusType opState,
	P2CONST(Dcm_MsgContextType, AUTOMATIC, DCM_CONST)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
)
{
	Std_ReturnType result = (Std_ReturnType)E_NOT_OK;

#if((0u != DCM_DSP_DID_NUM) || (0u != DCM_DSP_DID_RANGE_NUM))

	uint8 u8ReqDidIdx = 0xFFu;
	boolean isRangeDid = (boolean)FALSE;

	result = Dcm_UDS0x2EReqDidCheck(opState, &u8ReqDidIdx, &isRangeDid, pErrorCode);

	if((Std_ReturnType)E_OK == result)
	{
#if(0u != DCM_DSP_DID_NUM)
		if((boolean)FALSE == isRangeDid)
		{
			result = Dcm_UDS0x2ESingleDidProcess(u8ReqDidIdx, opState, pMsgContext, pErrorCode);
		}
#endif /* #if(0u != DCM_DSP_DID_NUM) */
#if((0u != DCM_DSP_DID_NUM) && (0u != DCM_DSP_DID_RANGE_NUM))
		else
#endif /* #if((0u != DCM_DSP_DID_NUM) && (0u != DCM_DSP_DID_RANGE_NUM)) */
#if(0u != DCM_DSP_DID_RANGE_NUM)
		{
			result = Dcm_UDS0x2ERangeDidProcess(u8ReqDidIdx, opState, pMsgContext, pErrorCode);
		}
#endif /* #if(0u != DCM_DSP_DID_RANGE_NUM) */
	}

#else

	*pErrorCode = DCM_E_REQUESTOUTOFRANGE;

#endif /* #if((0u != DCM_DSP_DID_NUM) || (0u != DCM_DSP_DID_RANGE_NUM)) */

	return result;
}
/*====================================================================================================*
 *                                          GLOBAL FUNCTIONS
 *====================================================================================================*/
/**
 * @brief			Dcm_UDS0x2E
 * @details			Internal processing interface for Service 0x2E.
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
FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x2E
(
	Dcm_OpStatusType OpStatus,
	P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
)
{
	Std_ReturnType result = (Std_ReturnType)E_OK;

	if(DCM_PENDING != OpStatus)
	{
		if(4u > pMsgContext->ReqDataLen)
		{
			*ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;

			result = (Std_ReturnType)E_NOT_OK;
		}
		else
		{
			Dcm_UDS0x2EStatus.ReqDid = (uint16)pMsgContext->ReqData[1] << 8u;
			Dcm_UDS0x2EStatus.ReqDid |= (uint16)pMsgContext->ReqData[2];
			Dcm_UDS0x2EStatus.ReqSignalIndex = 0u;
			Dcm_UDS0x2EStatus.SignalDynLen = 0u;
#if(0u != DCM_DSP_DATA_BLOCK_USED_NUM)
			Dcm_UDS0x2EStatus.WriteBlock = (boolean)FALSE;
#endif /* #if(0u != DCM_DSP_DATA_BLOCK_USED_NUM) */
		}
	}

	if((Std_ReturnType)E_OK == result)
	{
		result = Dcm_UDS0x2EDidProcess(OpStatus, pMsgContext, ErrorCode);

		if((Std_ReturnType)E_OK == result)
		{
			/* The minimum length of the buffer is 8 bytes, no need to check the response length. */

			pMsgContext->ResData[0] = 0x6Eu;
			pMsgContext->ResData[1] = pMsgContext->ReqData[1];
			pMsgContext->ResData[2] = pMsgContext->ReqData[2];

			pMsgContext->ResDataLen = 3u;
		}
		else
		{
			if((Std_ReturnType)DCM_E_PENDING == result)
			{
				Dcm_OpState = DCM_PENDING;
				*ErrorCode = DCM_E_RESPONSE_PENDING;
			}

			result = (Std_ReturnType)E_NOT_OK;
		}
	}

	return result;
}

#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#endif /* #if(STD_ON == DCM_UDS0x2E_INTERNAL_FNC_ENABLE) */
#endif /* #if(STD_ON == DCM_UDS0x2E_ENABLE) */

#ifdef __cplusplus
}
#endif
/** @} */
