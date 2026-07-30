/**
 * @file        Dcm_UDS0x27.c
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

/* PRQA S 0292, 0857, 0491, 2981, 2877, 5087 EOF #
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
 * 5.2877 -- Violates MISRA 2004 Required Rule 21.1, This loop will never be executed more than once.
 *
 * 6.5087 -- Violates MISRA 2004 Required Rule 19.1, Use of #include directive after code fragment.
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

#if(STD_ON == DCM_UDS0x27_ENABLE)
#if(STD_ON == DCM_UDS0x27_INTERNAL_FNC_ENABLE)
/**
 * @req [SWS_Dcm_00252] The Dcm module shall implement the UDS Service SecurityAccess (0x27).
 */
/*====================================================================================================*
 *                                  SOURCE FILE VERSION INFORMATION
 *====================================================================================================*/
#define DCM_UDS0X27_VENDOR_ID_C                            	(0x00U)
#define DCM_UDS0X27_AR_RELEASE_MAJOR_VERSION_C             	(0x04U)
#define DCM_UDS0X27_AR_RELEASE_MINOR_VERSION_C             	(0x02U)
#define DCM_UDS0X27_AR_RELEASE_REVISION_VERSION_C          	(0x02U)
#define DCM_UDS0X27_SW_MAJOR_VERSION_C                     	(0x01U)
#define DCM_UDS0X27_SW_MINOR_VERSION_C                     	(0x02U)
#define DCM_UDS0X27_SW_PATCH_VERSION_C                     	(0x00U)
/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/
/* Check if current file and Dcm_Internal header file are of the same vendor */
#if(DCM_UDS0X27_VENDOR_ID_C != DCM_INTERNAL_VENDOR_ID )
#error "Dcm_UDS0x27.c and Dcm_Internal.h have different vendor id"
#endif
/* Check if current file and Dcm_Internal header file are of the same Autosar version */
#if(\
		(DCM_UDS0X27_AR_RELEASE_MAJOR_VERSION_C != DCM_INTERNAL_AR_RELEASE_MAJOR_VERSION) || \
		(DCM_UDS0X27_AR_RELEASE_MINOR_VERSION_C != DCM_INTERNAL_AR_RELEASE_MINOR_VERSION) || \
		(DCM_UDS0X27_AR_RELEASE_REVISION_VERSION_C != DCM_INTERNAL_AR_RELEASE_REVISION_VERSION) \
)
#error "AutoSar Version Number of Dcm_UDS0x27.c and Dcm_Internal.h are different"
#endif
/* Check if current file and Dcm_Internal header file are of the same software version */
#if(\
		(DCM_UDS0X27_SW_MAJOR_VERSION_C != DCM_INTERNAL_SW_MAJOR_VERSION) || \
		(DCM_UDS0X27_SW_MINOR_VERSION_C != DCM_INTERNAL_SW_MINOR_VERSION) || \
		(DCM_UDS0X27_SW_PATCH_VERSION_C != DCM_INTERNAL_SW_PATCH_VERSION) \
)
#error "Software Version Number of Dcm_UDS0x27.c and Dcm_Internal.h are different"
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
 * @brief	Store the security access initialization status.
 */
VAR(Dcm_SecurityInitStatusType, DCM_VAR)Dcm_SecurityInitStatus;

/**
 * @brief	Store the timer, counter and delay state during the security access.
 */
VAR(Dcm_SecurityStatusType, DCM_VAR)Dcm_SecurityStatus[DCM_DSP_SECURITY_ROW_NUM];

#define DCM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dcm_MemMap.h"

#define DCM_START_SEC_VAR_INIT_8
#include "Dcm_MemMap.h"

/**
 * @brief	Store the security level requested to unlock when requesting Seed.
 */
STATIC VAR(uint8, DCM_VAR)Dcm_UDS0x27LastUnLockLevel = 0xFFu;

#define DCM_STOP_SEC_VAR_INIT_8
#include "Dcm_MemMap.h"
/*====================================================================================================*
 *                                      LOCAL FUNCTION PROTOTYPES
 *====================================================================================================*/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"

STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_USD0x27RequestSeedHandle
(
	uint8 u8UnLockLevel,
	Dcm_SecurityDataType secRowIdx,
	Dcm_OpStatusType opState,
	P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode,
	P2CONST(Dcm_DspSecurityRowType, AUTOMATIC, DCM_CONST)pSecurityRow
);

STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x27SendKeyHandle
(
	uint8 u8UnLockLevel,
	Dcm_SecurityDataType secRowIdx,
	Dcm_OpStatusType opState,
	P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode,
	P2CONST(Dcm_DspSecurityRowType, AUTOMATIC, DCM_CONST)pSecurityRow
);
/*====================================================================================================*
 *                                           LOCAL FUNCTIONS
 *====================================================================================================*/
/**
 * @brief			Dcm_USD0x27RequestSeedHandle
 * @details			Service 0x27 subfunction processing interface, used to request the Seed.
 *
 * @param[in]		u8UnLockLevel:Request to unlock the security level.
 * @param[in]		secRowIdx:The configuration index corresponding to the security level requested
 * 					for unlocking.
 * @param[in]		OpStatus:Operating state.
 * @param[in]		pMsgContext:Message-related information for one diagnostic protocol identifier.
 * 					The pointers in pMsgContext shall point behind the SID.
 * @param[in]		pSecurityRow:The configuration corresponding to the security level requested for
 * 					unlocking.
 *
 * @param[out]		ErrorCode:If the called external interface returns E_NOT_OK, use this pointer to
 * 					output the NRC.
 *
 * @return        	Result of this operation.
 * @retval			E_OK:Processing successful.
 * @retval			E_NOT_OK:Processing failure.
 */
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_USD0x27RequestSeedHandle
(
	uint8 u8UnLockLevel,
	Dcm_SecurityDataType secRowIdx,
	Dcm_OpStatusType opState,
	P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode,
	P2CONST(Dcm_DspSecurityRowType, AUTOMATIC, DCM_CONST)pSecurityRow
)
{
	Std_ReturnType result = (Std_ReturnType)E_NOT_OK;

	uint32 u32Index;
	const uint8* pDataRecord = NULL_PTR;

	if((boolean)TRUE == Dcm_SecurityStatus[secRowIdx].DelayState)
	{
		*pErrorCode = DCM_E_REQUIREDTIMEDELAYNOTEXPIRED;
	}
	else if(pMsgContext->ReqDataLen != (pSecurityRow->DcmDspSecurityADRSize + 2u))
	{
		*pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
	}
	else if(pMsgContext->ResMaxDataLen < (pSecurityRow->DcmDspSecuritySeedSize + 2u))
	{
		*pErrorCode = DCM_E_RESPONSETOOLONG;
	}
	else
	{
		/**
		 * @req [SWS_Dcm_00323] If the requested subfunction value is configured and a service with
		 * 		subfunction type "requestSeed" (= odd value) has been received and if the requested
		 * 		access type is already active (see Dcm_GetSecurityLevel()), the DSP submodule shall
		 * 		set the seed content to 0x00.
		 */
		if(Dcm_ActiveSecurity == u8UnLockLevel)
		{
			for(u32Index = 0u; u32Index < pSecurityRow->DcmDspSecuritySeedSize; u32Index++)
			{
				pMsgContext->ResData[u32Index + 2u] = 0x00u;
			}

			pMsgContext->ResDataLen = (pSecurityRow->DcmDspSecuritySeedSize + 2u);

			result = (Std_ReturnType)E_OK;
		}
		else
		{
			if(0u != pSecurityRow->DcmDspSecurityADRSize)
			{
				pDataRecord = &pMsgContext->ReqData[2];
			}

			/**
			 * @req [SWS_Dcm_00324] In the other case than the one described in [SWS_Dcm_00323] (access
			 * 		type is not active or "send key" request), if DcmDspSecurityUsePort is set to
			 * 		USE_ASYNCH_CLIENT_SERVER, the DSP submodule shall call the configured operation
			 * 		Xxx_GetSeed() (in case "request seed" is received) or Xxx_CompareKey() (in case
			 * 		"send key" is received).
			 *
			 * @req [SWS_Dcm_00862] On reception of the UDS Service SecurityAccess (0x27) with
			 * 		subfunction type "requestSeed" and if the requested access type is not already
			 * 		active, the DCM module shall request a seed by calling the configured Xxx_GetSeed()
			 * 		function (if the configuration parameter DcmDspSecurityUsePort is set to
			 * 		USE_ASYNCH_FNC, refer to configuration parameter DcmDspSecurityGetSeedFnc).
			 */
			result = pSecurityRow->DcmDspSecurityGetSeedFnc(pDataRecord, opState, &pMsgContext->ResData[2], pErrorCode);

			if((Std_ReturnType)DCM_E_PENDING == result)
			{
				Dcm_OpState = DCM_PENDING;
				*pErrorCode = DCM_E_RESPONSE_PENDING;
			}
			else if((Std_ReturnType)E_NOT_OK == result)
			{
				;
			}
			else
			{
				pMsgContext->ResDataLen = (pSecurityRow->DcmDspSecuritySeedSize + 2u);

				Dcm_UDS0x27LastUnLockLevel = u8UnLockLevel;
			}
		}
	}

	return result;
}

/**
 * @brief			Dcm_UDS0x27SendKeyHandle
 * @details			Service 0x27 subfunction processing interface, used to verify the Key.
 *
 * @param[in]		u8UnLockLevel:Request to unlock the security level.
 * @param[in]		secRowIdx:The configuration index corresponding to the security level requested
 * 					for unlocking.
 * @param[in]		OpStatus:Operating state.
 * @param[in]		pMsgContext:Message-related information for one diagnostic protocol identifier.
 * 					The pointers in pMsgContext shall point behind the SID.
 * @param[in]		pSecurityRow:The configuration corresponding to the security level requested for
 * 					unlocking.
 *
 * @param[out]		ErrorCode:If the called external interface returns E_NOT_OK, use this pointer to
 * 					output the NRC.
 *
 * @return        	Result of this operation.
 * @retval			E_OK:Processing successful.
 * @retval			E_NOT_OK:Processing failure.
 */
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x27SendKeyHandle
(
	uint8 u8UnLockLevel,
	Dcm_SecurityDataType secRowIdx,
	Dcm_OpStatusType opState,
	P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode,
	P2CONST(Dcm_DspSecurityRowType, AUTOMATIC, DCM_CONST)pSecurityRow
)
{
	Std_ReturnType result = (Std_ReturnType)E_NOT_OK;

#if(STD_ON == DCM_DSP_SECURITY_ATTEMPT_COUNTER_ENABLED)
	boolean flag = (boolean)FALSE;
#endif /* #if(STD_ON == DCM_DSP_SECURITY_ATTEMPT_COUNTER_ENABLED) */

	if(pMsgContext->ReqDataLen != (pSecurityRow->DcmDspSecurityKeySize + 2u))
	{
		*pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
        Dcm_UDS0x27LastUnLockLevel = 0xFFu;
	}
	else if(Dcm_UDS0x27LastUnLockLevel != u8UnLockLevel)
	{
		*pErrorCode = DCM_E_REQUESTSEQUENCEERROR;
        Dcm_UDS0x27LastUnLockLevel = 0xFFu;
	}
	else
	{
		/**
		 * @req [SWS_Dcm_00324] In the other case than the one described in [SWS_Dcm_00323] (access
		 * 		type is not active or "send key" request), if DcmDspSecurityUsePort is set to
		 * 		USE_ASYNCH_CLIENT_SERVER, the DSP submodule shall call the configured operation
		 * 		Xxx_GetSeed() (in case "request seed" is received) or Xxx_CompareKey() (in case "send
		 * 		key" is received).
		 *
		 * @req [SWS_Dcm_00863] On reception of the UDS Service SecurityAccess (0x27 with subfunction
		 * 		type "sendKey", if the requested access type is not already active and if the "request
		 * 		seed" for the related access type was executed successfully, the DCM module shall
		 * 		request the result of a key comparison by calling the configured Xxx_CompareKey()
		 * 		function (if the configuration parameter DcmDspSecurityUsePort is set to USE_ASYNCH_FNC,
		 * 		refer to configuration parameter DcmDspSecurityCompareKeyFnc).
		 */
		result = pSecurityRow->DcmDspSecurityCompareKeyFnc(&pMsgContext->ReqData[2], opState, pErrorCode);

		if((Std_ReturnType)DCM_E_PENDING == result)
		{
			Dcm_OpState = DCM_PENDING;
			*pErrorCode = DCM_E_RESPONSE_PENDING;
		}
		else if((Std_ReturnType)E_NOT_OK == result)
		{
	        Dcm_UDS0x27LastUnLockLevel = 0xFFu;
		}
		else if((Std_ReturnType)DCM_E_COMPARE_KEY_FAILED == result)
		{
#if(STD_ON == DCM_DSP_SECURITY_ATTEMPT_COUNTER_ENABLED)
			flag = (boolean)TRUE;
#endif /* #if(STD_ON == DCM_DSP_SECURITY_ATTEMPT_COUNTER_ENABLED) */
			*pErrorCode = DCM_E_INVALIDKEY;

			Dcm_SecurityStatus[secRowIdx].AttemptCnt++;

			if(pSecurityRow->DcmDspSecurityNumAttDelay == Dcm_SecurityStatus[secRowIdx].AttemptCnt)
			{
				*pErrorCode = DCM_E_EXCEEDEDNUMBEROFATTEMPTS;

#if(STD_ON == DCM_DSP_SECURITY_ATTEMPT_COUNTER_DELAY_END_RESET)
				Dcm_SecurityStatus[secRowIdx].DelayState = (boolean)TRUE;
				Dcm_SecurityStatus[secRowIdx].TimerEnable = (boolean)TRUE;
				Dcm_SecurityStatus[secRowIdx].CurrentTime = 0u;
				Dcm_SecurityStatus[secRowIdx].TimeoutTime = (uint32)pSecurityRow->DcmDspSecurityDelayTime;
#else
				Dcm_SecurityStatus[secRowIdx].DelayState = (boolean)TRUE;
				if((boolean)FALSE == Dcm_SecurityStatus[secRowIdx].TimerEnable)
				{
					Dcm_SecurityStatus[secRowIdx].TimerEnable = (boolean)TRUE;
					Dcm_SecurityStatus[secRowIdx].CurrentTime = 0u;
					Dcm_SecurityStatus[secRowIdx].TimeoutTime = (uint32)pSecurityRow->DcmDspSecurityDelayTime;
				}
#endif /* #if(STD_ON == DCM_DSP_SECURITY_ATTEMPT_COUNTER_DELAY_END_RESET) */
			}

	        Dcm_UDS0x27LastUnLockLevel = 0xFFu;
		}
		else
		{
#if(STD_ON == DCM_DSP_SECURITY_ATTEMPT_COUNTER_ENABLED)
			flag = (boolean)TRUE;
#endif /* #if(STD_ON == DCM_DSP_SECURITY_ATTEMPT_COUNTER_ENABLED) */
			Dcm_NewActiveSecurity = u8UnLockLevel;
			Dcm_NewActiveSecurityIdx = secRowIdx;

#if(STD_ON == DCM_DSP_SECURITY_ATTEMPT_COUNTER_DELAY_END_RESET)
			Dcm_SecurityStatus[secRowIdx].AttemptCnt = 0u;
#else
			Dcm_SecurityStatus[secRowIdx].AttemptCnt = 0u;
			if((boolean)TRUE == Dcm_SecurityStatus[secRowIdx].TimerEnable)
			{
				Dcm_SecurityStatus[secRowIdx].TimerEnable = (boolean)FALSE;
				Dcm_SecurityStatus[secRowIdx].CurrentTime = 0u;
				Dcm_SecurityStatus[secRowIdx].TimeoutTime = 0u;
			}
#endif /* #if(STD_ON == DCM_DSP_SECURITY_ATTEMPT_COUNTER_DELAY_END_RESET) */

			pMsgContext->ResDataLen = 2u;

	        Dcm_UDS0x27LastUnLockLevel = 0xFFu;
		}

#if(STD_ON == DCM_DSP_SECURITY_ATTEMPT_COUNTER_ENABLED)
		if(((boolean)TRUE == flag) && ((boolean)TRUE == pSecurityRow->DcmDspSecurityAttemptCounterEnabled))
		{
			(void)pSecurityRow->DcmDspSecuritySetAttemptCounterFnc(DCM_INITIAL, Dcm_SecurityStatus[secRowIdx].AttemptCnt);
		}
#endif /* #if(STD_ON == DCM_DSP_SECURITY_ATTEMPT_COUNTER_ENABLED) */
	}

	return result;
}
/*====================================================================================================*
 *                                          GLOBAL FUNCTIONS
 *====================================================================================================*/
/**
 * @brief			Dcm_UDS0x27
 * @details			Internal processing interface for Service 0x27.
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
FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x27
(
	Dcm_OpStatusType OpStatus,
	P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
)
{
	Std_ReturnType result = (Std_ReturnType)E_NOT_OK;

	Dcm_SecurityDataType index;
	uint8 u8AddrType;
	uint8 u8SubServiceId;
	uint8 u8UnLockLevel;
	const Dcm_DsdServiceType* pService = NULL_PTR;
	const Dcm_DspSecurityRowType* pSecurityRow = NULL_PTR;

	if(2u > pMsgContext->ReqDataLen)
	{
		*ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
	}
	else
	{
		u8SubServiceId = pMsgContext->ReqData[1];
		u8UnLockLevel = (u8SubServiceId + 1u) / 2u;

		/**
		 * @req [SWS_Dcm_00321] If the request length is correct, the DSP submodule shall check if the
		 * 		requested subfunction value (access type) is configured in the ECU (see configuration
		 * 		parameter DcmDspSecurityLevel). If the requested subfunction value is not configured,
		 * 		the DSP submodule shall trigger a negative response with NRC 0x12 (SubFunction not
		 * 		supported).
		 */
		for(index = 0u; index < DCM_DSP_SECURITY_ROW_NUM; index++)
		{
			pSecurityRow = &Dcm_ConfigPtr->DcmDsp->DcmDspSecurityRow[index];
			if(u8UnLockLevel == pSecurityRow->DcmDspSecurityLevel)
			{
				break;
			}
		}
		if(DCM_DSP_SECURITY_ROW_NUM == index)
		{
			*ErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
		}
		else
		{
			u8AddrType = (pMsgContext->MsgAddInfo & 0x01u);

			pService = DCM_GET_SERVICE_PTR(Dcm_ConnectionStatus[Dcm_ActiveConIdx].ServiceIdx);

			if((Std_ReturnType)E_OK == DspInternal_SubServiceCheck(u8AddrType, u8SubServiceId, pService, ErrorCode))
			{
				if((boolean)FALSE == Dcm_SecurityInitStatus.InitState)
				{
					*ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
				}
				else
				{
					if(0x01u == (u8SubServiceId & 0x01u))
					{
						/* Request seed. */
						result = Dcm_USD0x27RequestSeedHandle(\
									u8UnLockLevel, index, OpStatus,\
									pMsgContext, ErrorCode, pSecurityRow\
									);
					}
					else
					{
						/* Send key. */
						result = Dcm_UDS0x27SendKeyHandle(\
									u8UnLockLevel, index, OpStatus,\
									pMsgContext, ErrorCode, pSecurityRow\
									);
					}

					if((Std_ReturnType)E_OK == result)
					{
						pMsgContext->ResData[0] = 0x67u;
						pMsgContext->ResData[1] = u8SubServiceId;
					}
					else
					{
						result = (Std_ReturnType)E_NOT_OK;
					}
				}
			}
		}
	}

	return result;
}

#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#endif /* #if(STD_ON == DCM_UDS0x27_INTERNAL_FNC_ENABLE) */
#endif /* #if(STD_ON == DCM_UDS0x27_ENABLE) */

#ifdef __cplusplus
}
#endif
/** @} */
