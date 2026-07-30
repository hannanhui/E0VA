/**
 * @file        Dcm_UDS0x31.c
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

/* PRQA S 0292, 0857, 0491, 2981, 2877, 0498, 5087 EOF #
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
 * 6.0498 -- Violates MISRA 2004 Required Rule 17.4, A unary increment or decrement operator is being
 * applied to pointer.
 *
 * 7.5087 -- Violates MISRA 2004 Required Rule 19.1, Use of #include directive after code fragment.
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

#if(STD_ON == DCM_UDS0x31_ENABLE)
#if(STD_ON == DCM_UDS0x31_INTERNAL_FNC_ENABLE)
/**
 * @req [SWS_Dcm_00257] The Dcm module shall implement the UDS Service RoutineControl (0x31) for
 * 		subFunctions startRoutine, stopRoutine and requestsRoutineResults.
 *
 * @req [SWS_Dcm_01139] The Dcm shall follow the NRC handling for RoutineControlService according to
 * 		ISO 14229-1 [15].
 */
/*====================================================================================================*
 *                                  SOURCE FILE VERSION INFORMATION
 *====================================================================================================*/
#define DCM_UDS0X31_VENDOR_ID_C                            	(0x00U)
#define DCM_UDS0X31_AR_RELEASE_MAJOR_VERSION_C             	(0x04U)
#define DCM_UDS0X31_AR_RELEASE_MINOR_VERSION_C             	(0x02U)
#define DCM_UDS0X31_AR_RELEASE_REVISION_VERSION_C          	(0x02U)
#define DCM_UDS0X31_SW_MAJOR_VERSION_C                     	(0x01U)
#define DCM_UDS0X31_SW_MINOR_VERSION_C                     	(0x02U)
#define DCM_UDS0X31_SW_PATCH_VERSION_C                     	(0x00U)
/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/
/* Check if current file and Dcm_Internal header file are of the same vendor */
#if(DCM_UDS0X31_VENDOR_ID_C != DCM_INTERNAL_VENDOR_ID )
#error "Dcm_UDS0x31.c and Dcm_Internal.h have different vendor id"
#endif
/* Check if current file and Dcm_Internal header file are of the same Autosar version */
#if(\
		(DCM_UDS0X31_AR_RELEASE_MAJOR_VERSION_C != DCM_INTERNAL_AR_RELEASE_MAJOR_VERSION) || \
		(DCM_UDS0X31_AR_RELEASE_MINOR_VERSION_C != DCM_INTERNAL_AR_RELEASE_MINOR_VERSION) || \
		(DCM_UDS0X31_AR_RELEASE_REVISION_VERSION_C != DCM_INTERNAL_AR_RELEASE_REVISION_VERSION) \
)
#error "AutoSar Version Number of Dcm_UDS0x31.c and Dcm_Internal.h are different"
#endif
/* Check if current file and Dcm_Internal header file are of the same software version */
#if(\
		(DCM_UDS0X31_SW_MAJOR_VERSION_C != DCM_INTERNAL_SW_MAJOR_VERSION) || \
		(DCM_UDS0X31_SW_MINOR_VERSION_C != DCM_INTERNAL_SW_MINOR_VERSION) || \
		(DCM_UDS0X31_SW_PATCH_VERSION_C != DCM_INTERNAL_SW_PATCH_VERSION) \
)
#error "Software Version Number of Dcm_UDS0x31.c and Dcm_Internal.h are different"
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
 * @brief	Store internal status of service 0x31 during its processing.
 */
STATIC VAR(Dcm_RoutineControlStatusType, DCM_VAR)Dcm_UDS0x31Status;

#define DCM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dcm_MemMap.h"
/*====================================================================================================*
 *                                      LOCAL FUNCTION PROTOTYPES
 *====================================================================================================*/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"

#if(0u != DCM_DSP_COMMON_AUTHORIZATION_NUM)
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x31PermissionCheckHandle
(
	P2CONST(Dcm_DspCommonAuthorizationType, AUTOMATIC, DCM_CONST)pCommonAuthorization,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
);
#endif /* #if(0u != DCM_DSP_COMMON_AUTHORIZATION_NUM) */

#if((0u != DCM_DSP_START_ROUTINE_IN_SIGNAL_NUM) ||\
	(0u != DCM_DSP_STOP_ROUTINE_IN_SIGNAL_NUM) ||\
	(0u != DCM_DSP_REQUEST_ROUTINE_RESULTS_IN_SIGNAL_NUM))
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x31ReqDataLenCheck
(
	uint8 u8InSignalNum,
	P2CONST(Dcm_DspRoutineSignalType, AUTOMATIC, DCM_CONST)pSignal,
	P2CONST(Dcm_MsgContextType, AUTOMATIC, DCM_CONST)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
);
#endif /* #if((0u != DCM_DSP_START_ROUTINE_IN_SIGNAL_NUM) ||\
			  (0u != DCM_DSP_STOP_ROUTINE_IN_SIGNAL_NUM) ||\
			  (0u != DCM_DSP_REQUEST_ROUTINE_RESULTS_IN_SIGNAL_NUM)) */

#if((0u != DCM_DSP_START_ROUTINE_OUT_SIGNAL_NUM) ||\
	(0u != DCM_DSP_STOP_ROUTINE_OUT_SIGNAL_NUM) ||\
	(0u != DCM_DSP_REQUEST_ROUTINE_RESULTS_OUT_SIGNAL_NUM))
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x31ResDataLenCheck
(
	uint8 u8OutSignalNum,
	P2CONST(Dcm_DspRoutineSignalType, AUTOMATIC, DCM_CONST)pSignal,
	P2CONST(Dcm_MsgContextType, AUTOMATIC, DCM_CONST)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
);
#endif /* #if((0u != DCM_DSP_START_ROUTINE_OUT_SIGNAL_NUM) ||\
			  (0u != DCM_DSP_STOP_ROUTINE_OUT_SIGNAL_NUM) ||\
			  (0u != DCM_DSP_REQUEST_ROUTINE_RESULTS_OUT_SIGNAL_NUM)) */

#if(STD_ON == DCM_DSP_ROUTINE_START_ENABLED)
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x31StartRoutineHandle
(
	Dcm_OpStatusType opState,
	P2CONST(Dcm_MsgContextType, AUTOMATIC, DCM_CONST)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
);
#endif /* #if(STD_ON == DCM_DSP_ROUTINE_START_ENABLED) */

#if(STD_ON == DCM_DSP_ROUTINE_STOP_ENABLED)
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x31StopRoutineHandle
(
	Dcm_OpStatusType opState,
	P2CONST(Dcm_MsgContextType, AUTOMATIC, DCM_CONST)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
);
#endif /* #if(STD_ON == DCM_DSP_ROUTINE_STOP_ENABLED) */

#if(STD_ON == DCM_DSP_ROUTINE_REQUEST_RESULTS_ENABLED)
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x31RequestRoutineResultsHandle
(
	Dcm_OpStatusType opState,
	P2CONST(Dcm_MsgContextType, AUTOMATIC, DCM_CONST)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
);
#endif /* #if(STD_ON == DCM_DSP_ROUTINE_REQUEST_RESULTS_ENABLED) */
/*====================================================================================================*
 *                                           LOCAL FUNCTIONS
 *====================================================================================================*/
#if(0u != DCM_DSP_COMMON_AUTHORIZATION_NUM)
/**
 * @brief			Dcm_UDS0x31PermissionCheckHandle
 * @details			Check the permissions for the routine and its sub-functions.
 *
 * @param[in]		pCommonAuthorization:Pointer to the permission configuration to be checked.
 *
 * @param[out]		pErrorCode:If error occur, output the NRC.
 *
 * @return        	Result of this operation.
 * @retval			E_OK:Processing successful.
 * @retval			E_NOT_OK:Processing failure.
 */
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x31PermissionCheckHandle
(
	P2CONST(Dcm_DspCommonAuthorizationType, AUTOMATIC, DCM_CONST)pCommonAuthorization,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
)
{
	Std_ReturnType result = (Std_ReturnType)E_OK;

	/**
	 * @req [SWS_Dcm_00570] On reception of the UDS Service RoutineControl (0x31), the DCM module shall
	 * 		check if the Routine can be executed in the current session (see configuration parameters
	 * 		DcmDspStartRoutineCommonAuthorizationRef, DcmDspStopRoutineCommonAuthorizationRef and
	 * 		DcmDspRequestRoutineResultsCommonAuthorizationRef). If not, the Dcm module shall send a NRC
	 * 		0x31 (Request Out of Range).
	 *
	 * @req [SWS_Dcm_00571] On reception of the UDS Service RoutineControl (0x31), the DCM module shall
	 * 		check if the Routine can be executed in the current security level (see configuration
	 * 		parameter DcmDspStartRoutineCommonAuthorizationRef, DcmDspStopRoutineCommonAuthorizationRef
	 * 		and DcmDspRequestRoutineResultsCommonAuthorizationRef). If not, the Dcm module shall send
	 * 		NRC 0x33 (Security access denied).
	 *
	 * @req [SWS_Dcm_01141] The Dcm shall call the appropriate routine functions of the SWC after having
	 * 		performed the total length check and the Mode rules, security level and session checks
	 * 		(DcmDspStartRoutineCommonAuthorizationRef, DcmDspStopRoutineCommonAuthorizationRef and
	 * 		DcmDspRequestRoutineResultsCommonAuthorizationRef).
	 */
	if(NULL_PTR != pCommonAuthorization)
	{
		result = DspInternal_PermissionCheck(\
					pCommonAuthorization->DcmDspCommonAuthorizationSessionRef,\
					pCommonAuthorization->DcmDspCommonAuthorizationSecurityLevelRef,\
					DCM_PERMISSION_CHECK_USER_ROUTINE, pErrorCode\
					);
	}

	return result;
}
#endif /* #if(0u != DCM_DSP_COMMON_AUTHORIZATION_NUM) */

#if((0u != DCM_DSP_START_ROUTINE_IN_SIGNAL_NUM) ||\
	(0u != DCM_DSP_STOP_ROUTINE_IN_SIGNAL_NUM) ||\
	(0u != DCM_DSP_REQUEST_ROUTINE_RESULTS_IN_SIGNAL_NUM))
/**
 * @brief			Dcm_UDS0x31ReqDataLenCheck
 * @details			Check whether the request message length is correct.
 *
 * @param[in]		u8InSignalNum:Number of input signals.
 * @param[in]		pSignal:Pointer to the first input signal configuration.
 * @param[in]		pMsgContext:Message-related information for one diagnostic protocol identifier.
 *
 * @param[out]		pErrorCode:If error occur, output the NRC.
 *
 * @return        	Result of this operation.
 * @retval			E_OK:Processing successful.
 * @retval			E_NOT_OK:Processing failure.
 */
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x31ReqDataLenCheck
(
	uint8 u8InSignalNum,
	P2CONST(Dcm_DspRoutineSignalType, AUTOMATIC, DCM_CONST)pSignal,
	P2CONST(Dcm_MsgContextType, AUTOMATIC, DCM_CONST)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
)
{
	Std_ReturnType result = (Std_ReturnType)E_OK;

	uint8 u8Index;
	uint16 u16SignalLen;
	uint16 u16DataMinLen = 4u;
	uint16 u16DataMaxLen = 4u;

	/**
	 * @req [SWS_Dcm_01140] On reception of the UDS Service RoutineControl (0x31), the Dcm module shall
	 * 		check the overall length of the request. If length of the request is wrong, the Dcm module
	 * 		shall send NRC 0x13 (Incorrect message length or invalid format) to the tester.
	 */

	for(u8Index = 0u; u8Index < u8InSignalNum; u8Index++)
	{
		u16SignalLen = (pSignal->DcmDspRoutineSignalLength / 8u);

		u16DataMaxLen += u16SignalLen;

		if(DCM_UINT8_DYN != pSignal->DcmDspRoutineSignalType)
		{
			u16DataMinLen += u16SignalLen;
		}
		else
		{
			Dcm_UDS0x31Status.InSignalDynLen = ((uint16)pMsgContext->ReqDataLen - u16DataMinLen);

			Dcm_UDS0x31Status.DataInVarPtr = &pMsgContext->ReqData[u16DataMinLen];
		}

		pSignal++;
	}

	if((pMsgContext->ReqDataLen < u16DataMinLen) || (pMsgContext->ReqDataLen > u16DataMaxLen))
	{
		*pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;

		result = (Std_ReturnType)E_NOT_OK;
	}

	return result;
}
#endif /* #if((0u != DCM_DSP_START_ROUTINE_IN_SIGNAL_NUM) ||\
			  (0u != DCM_DSP_STOP_ROUTINE_IN_SIGNAL_NUM) ||\
			  (0u != DCM_DSP_REQUEST_ROUTINE_RESULTS_IN_SIGNAL_NUM)) */

#if((0u != DCM_DSP_START_ROUTINE_OUT_SIGNAL_NUM) ||\
	(0u != DCM_DSP_STOP_ROUTINE_OUT_SIGNAL_NUM) ||\
	(0u != DCM_DSP_REQUEST_ROUTINE_RESULTS_OUT_SIGNAL_NUM))
/**
 * @brief			Dcm_UDS0x31ResDataLenCheck
 * @details			Check whether the response message length is correct.
 *
 * @param[in]		u8OutSignalNum:Number of output signals.
 * @param[in]		pSignal:Pointer to the first output signal configuration.
 * @param[in]		pMsgContext:Message-related information for one diagnostic protocol identifier.
 *
 * @param[out]		pErrorCode:If error occur, output the NRC.
 *
 * @return        	Result of this operation.
 * @retval			E_OK:Processing successful.
 * @retval			E_NOT_OK:Processing failure.
 */
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x31ResDataLenCheck
(
	uint8 u8OutSignalNum,
	P2CONST(Dcm_DspRoutineSignalType, AUTOMATIC, DCM_CONST)pSignal,
	P2CONST(Dcm_MsgContextType, AUTOMATIC, DCM_CONST)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
)
{
	Std_ReturnType result = (Std_ReturnType)E_OK;

	uint8 u8Index;
	uint16 u16SignalLen;

	for(u8Index = 0u; u8Index < u8OutSignalNum; u8Index++)
	{
		u16SignalLen = (pSignal->DcmDspRoutineSignalLength / 8u);

		if(pMsgContext->ResMaxDataLen >= ((uint32)Dcm_UDS0x31Status.DataTotalLen + (uint32)u16SignalLen))
		{
			if(DCM_UINT8_DYN != pSignal->DcmDspRoutineSignalType)
			{
				Dcm_UDS0x31Status.DataTotalLen += u16SignalLen;
			}
			else
			{
				Dcm_UDS0x31Status.DataOutVarPtr = &pMsgContext->ResData[Dcm_UDS0x31Status.DataTotalLen];
			}
		}
		else
		{
			*pErrorCode = DCM_E_RESPONSETOOLONG;

			result = (Std_ReturnType)E_NOT_OK;

			break;
		}

		pSignal++;
	}

	return result;
}
#endif /* #if((0u != DCM_DSP_START_ROUTINE_OUT_SIGNAL_NUM) ||\
			  (0u != DCM_DSP_STOP_ROUTINE_OUT_SIGNAL_NUM) ||\
			  (0u != DCM_DSP_REQUEST_ROUTINE_RESULTS_OUT_SIGNAL_NUM)) */

#if(STD_ON == DCM_DSP_ROUTINE_START_ENABLED)
/**
 * @brief			Dcm_UDS0x31StartRoutineHandle
 * @details			Start Routine processing interface.
 *
 * @param[in]		opState:Operating state.
 * @param[in]		pMsgContext:Message-related information for one diagnostic protocol identifier.
 *
 * @param[out]		pErrorCode:If error occur, output the NRC.
 *
 * @return        	Result of this operation.
 * @retval			E_OK:Processing successful.
 * @retval			E_NOT_OK:Processing failure.
 */
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x31StartRoutineHandle
(
	Dcm_OpStatusType opState,
	P2CONST(Dcm_MsgContextType, AUTOMATIC, DCM_CONST)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
)
{
	Std_ReturnType result = (Std_ReturnType)E_OK;

	const Dcm_DspStartRoutineType* pStartRoutine = Dcm_UDS0x31Status.RoutinePtr->DcmDspStartRoutine;

	if(DCM_PENDING != opState)
	{
		if(NULL_PTR == pStartRoutine)
		{
			*pErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;

			result = (Std_ReturnType)E_NOT_OK;
		}
		else
		{
#if(0u != DCM_DSP_COMMON_AUTHORIZATION_NUM)
			result = Dcm_UDS0x31PermissionCheckHandle(\
						pStartRoutine->DcmDspStartRoutineCommonAuthorizationRef, pErrorCode\
						);

			if((Std_ReturnType)E_OK == result)
			{
#endif /* #if(0u != DCM_DSP_COMMON_AUTHORIZATION_NUM) */

#if(0u != DCM_DSP_START_ROUTINE_IN_SIGNAL_NUM)

				/**
				 * @req [SWS_Dcm_00400] When receiving a request for UDS Service RoutineControl (0x31)
				 * 		with subfunction startRoutine, if all verifications have been successfully done
				 * 		(see SWS_Dcm_00568, SWS_Dcm_00570, SWS_Dcm_00571), the DCM module shall call the
				 * 		configured Xxx_Start() function passing the dataIn, calculated from
				 * 		routineControlOptionRecord (see SWS_Dcm_00590), and the dataOut reference
				 * 		according of the list of output signal configured for this routine ( see
				 * 		configuration parameter DcmDspStartRoutineOut). The datalength of the dataIn can
				 * 		be fixed or dynamic according to DcmDspRoutineSignalType. If dynamic, the
				 * 		datalength shall be provided in the parameter currentDataLength who holds the
				 * 		length in bytes of the last dataIn parameter. The datalength can be dynamic only
				 * 		on the last dataIn parameter.
				 */
				result = Dcm_UDS0x31ReqDataLenCheck(\
							pStartRoutine->DcmDspStartRoutineInSignalNum,\
							pStartRoutine->DcmDspStartRoutineInSignal,\
							pMsgContext, pErrorCode\
							);

				if((Std_ReturnType)E_OK == result)
				{
#else
				if(4u != pMsgContext->ReqDataLen)
				{
					*pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;

					result = (Std_ReturnType)E_NOT_OK;
				}
				else
				{
#endif /* #if(0u != DCM_DSP_START_ROUTINE_IN_SIGNAL_NUM) */

#if(0u != DCM_DSP_START_ROUTINE_OUT_SIGNAL_NUM)

					/**
					 * @req [SWS_Dcm_00401] Upon completing SWS_Dcm_00400, when Xxx_Start() returns no
					 * 		ErrorCode, the Dcm module shall reply with a positive response with the data
					 * 		returned by Xxx_Start() in the dataOut as routineInfo and
					 * 		routineStatusRecord (dataOut are merged according to the list of output
					 * 		signal configured for this routine ( see configuration parameter
					 * 		DcmDspStartRoutineOut)). The datalength of the dataOut can be fixed or
					 * 		dynamic according to DcmDspRoutineSignalType. If dynamic, the datalength
					 * 		shall be provided in the parameter currentDataLength who holds the length in
					 * 		bytes of the last dataOut parameter. The datalength can be dynamic only on
					 * 		the last dataOut parameter.
					 */
					result = Dcm_UDS0x31ResDataLenCheck(\
								pStartRoutine->DcmDspStartRoutineOutSignalNum,\
								pStartRoutine->DcmDspStartRoutineOutSignal,\
								pMsgContext, pErrorCode\
								);

#else
					;
#endif /* #if(0u != DCM_DSP_START_ROUTINE_OUT_SIGNAL_NUM) */

#if(0u != DCM_DSP_START_ROUTINE_IN_SIGNAL_NUM)
				}
#else
				}
#endif /* #if(0u != DCM_DSP_START_ROUTINE_IN_SIGNAL_NUM) */

#if(0u != DCM_DSP_COMMON_AUTHORIZATION_NUM)
			}
#endif /* #if(0u != DCM_DSP_COMMON_AUTHORIZATION_NUM) */
		}
	}

	if((Std_ReturnType)E_OK == result)
	{
		result = pStartRoutine->DcmDspStartRoutineFnc(\
					&pMsgContext->ReqData[4], &pMsgContext->ReqData[4],\
					opState,\
					&pMsgContext->ResData[4], Dcm_UDS0x31Status.DataOutVarPtr,\
					Dcm_UDS0x31Status.InSignalDynLen,\
					&Dcm_UDS0x31Status.OutSignalDynLen,\
					pErrorCode\
					);
	}

	return result;
}
#endif /* #if(STD_ON == DCM_DSP_ROUTINE_START_ENABLED) */

#if(STD_ON == DCM_DSP_ROUTINE_STOP_ENABLED)
/**
 * @brief			Dcm_UDS0x31StopRoutineHandle
 * @details			Stop Routine processing interface.
 *
 * @param[in]		opState:Operating state.
 * @param[in]		pMsgContext:Message-related information for one diagnostic protocol identifier.
 *
 * @param[out]		pErrorCode:If error occur, output the NRC.
 *
 * @return        	Result of this operation.
 * @retval			E_OK:Processing successful.
 * @retval			E_NOT_OK:Processing failure.
 */
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x31StopRoutineHandle
(
	Dcm_OpStatusType opState,
	P2CONST(Dcm_MsgContextType, AUTOMATIC, DCM_CONST)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
)
{
	Std_ReturnType result = (Std_ReturnType)E_OK;

	const Dcm_DspStopRoutineType* pStopRoutine = Dcm_UDS0x31Status.RoutinePtr->DcmDspStopRoutine;

	if(DCM_PENDING != opState)
	{
		if(NULL_PTR == pStopRoutine)
		{
			*pErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;

			result = (Std_ReturnType)E_NOT_OK;
		}
		else
		{
#if(0u != DCM_DSP_COMMON_AUTHORIZATION_NUM)
			result = Dcm_UDS0x31PermissionCheckHandle(\
						pStopRoutine->DcmDspStopRoutineCommonAuthorizationRef, pErrorCode\
						);

			if((Std_ReturnType)E_OK == result)
			{
#endif /* #if(0u != DCM_DSP_COMMON_AUTHORIZATION_NUM) */

#if(0u != DCM_DSP_STOP_ROUTINE_IN_SIGNAL_NUM)

				/**
				 * @req [SWS_Dcm_00402] When receiving a request for UDS Service RoutineControl (0x31)
				 * 		with subfunction stopRoutine, if all verifications have been successfully done
				 * 		(see SWS_Dcm_00568, SWS_Dcm_00570, SWS_Dcm_00571), the DCM module shall call the
				 * 		configured Xxx_Stop() function passing the dataIn, calculated from
				 * 		routineControlOptionRecord (see SWS_Dcm_00590), and the dataOut reference
				 * 		according of the list of output signal configured for this routine ( see
				 * 		configuration parameter DcmDspStopRoutineOut). The datalength of the dataIn can
				 * 		be fixed or dynamic according to DcmDspRoutineSignalType. If dynamic, the
				 * 		datalength shall be provided in the parameter currentDataLength who holds the
				 * 		length in bytes of the last dataIn parameter. The datalength can be dynamic only
				 * 		on the last dataIn parameter.
				 */
				result = Dcm_UDS0x31ReqDataLenCheck(\
							pStopRoutine->DcmDspStopRoutineInSignalNum,\
							pStopRoutine->DcmDspStopRoutineInSignal,\
							pMsgContext, pErrorCode\
							);

				if((Std_ReturnType)E_OK == result)
				{
#else
				if(4u != pMsgContext->ReqDataLen)
				{
					*pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;

					result = (Std_ReturnType)E_NOT_OK;
				}
				else
				{
#endif /* #if(0u != DCM_DSP_STOP_ROUTINE_IN_SIGNAL_NUM) */

#if(0u != DCM_DSP_STOP_ROUTINE_OUT_SIGNAL_NUM)

					/**
					 * @req [SWS_Dcm_00403] Upon completing SWS_Dcm_00402, when Xxx_Stop() returns no
					 * 		ErrorCode, the Dcm module shall reply with a positive response with the data
					 * 		returned by Xxx_Stop()in the dataOut as routineInfo and routineStatusRecord
					 * 		(dataOut are merged according to the list of output signal configured for
					 * 		this routine ( see configuration parameter DcmDspStopRoutineOut)). The
					 * 		datalength of the dataOut can be fixed or dynamic according to
					 * 		DcmDspRoutineSignalType. If dynamic, the datalength shall be provided in the
					 * 		parameter currentDataLength who holds the length in bytes of the last
					 * 		dataOut parameter.The datalength can be dynamic only on the last dataOut
					 * 		parameter.
					 */
					result = Dcm_UDS0x31ResDataLenCheck(\
								pStopRoutine->DcmDspStopRoutineOutSignalNum,\
								pStopRoutine->DcmDspStopRoutineOutSignal,\
								pMsgContext, pErrorCode\
								);

#else
					;
#endif /* #if(0u != DCM_DSP_STOP_ROUTINE_OUT_SIGNAL_NUM) */

#if(0u != DCM_DSP_STOP_ROUTINE_IN_SIGNAL_NUM)
				}
#else
				}
#endif /* #if(0u != DCM_DSP_STOP_ROUTINE_IN_SIGNAL_NUM) */

#if(0u != DCM_DSP_COMMON_AUTHORIZATION_NUM)
			}
#endif /* #if(0u != DCM_DSP_COMMON_AUTHORIZATION_NUM) */
		}
	}

	if((Std_ReturnType)E_OK == result)
	{
		result = pStopRoutine->DcmDspStopRoutineFnc(\
					&pMsgContext->ReqData[4], Dcm_UDS0x31Status.DataInVarPtr,\
					&pMsgContext->ResData[4], Dcm_UDS0x31Status.DataOutVarPtr,\
					Dcm_UDS0x31Status.InSignalDynLen,\
					&Dcm_UDS0x31Status.OutSignalDynLen,\
					pErrorCode\
					);
	}

	return result;
}
#endif /* #if(STD_ON == DCM_DSP_ROUTINE_STOP_ENABLED) */

#if(STD_ON == DCM_DSP_ROUTINE_REQUEST_RESULTS_ENABLED)
/**
 * @brief			Dcm_UDS0x31RequestRoutineResultsHandle
 * @details			Request Routine Results processing interface.
 *
 * @param[in]		opState:Operating state.
 * @param[in]		pMsgContext:Message-related information for one diagnostic protocol identifier.
 *
 * @param[out]		pErrorCode:If error occur, output the NRC.
 *
 * @return        	Result of this operation.
 * @retval			E_OK:Processing successful.
 * @retval			E_NOT_OK:Processing failure.
 */
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x31RequestRoutineResultsHandle
(
	Dcm_OpStatusType opState,
	P2CONST(Dcm_MsgContextType, AUTOMATIC, DCM_CONST)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
)
{
	Std_ReturnType result = (Std_ReturnType)E_OK;

	const Dcm_DspRequestRoutineResultsType* pRequestRoutineResults = Dcm_UDS0x31Status.RoutinePtr->DcmDspRequestRoutineResults;

	if(DCM_PENDING != opState)
	{
		if(NULL_PTR == pRequestRoutineResults)
		{
			*pErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;

			result = (Std_ReturnType)E_NOT_OK;
		}
		else
		{
#if(0u != DCM_DSP_COMMON_AUTHORIZATION_NUM)
			result = Dcm_UDS0x31PermissionCheckHandle(\
						pRequestRoutineResults->DcmDspRequestRoutineResultsCommonAuthorizationRef,\
						pErrorCode\
						);

			if((Std_ReturnType)E_OK == result)
			{
#endif /* #if(0u != DCM_DSP_COMMON_AUTHORIZATION_NUM) */

				/**
				 * @req [SWS_Dcm_00404] When receiving a request for UDS Service RoutineControl (0x31)
				 * 		with subfunction requestRoutineResults, if all verifications have been
				 * 		successfully done (see SWS_Dcm_00568, SWS_Dcm_00570, SWS_Dcm_00571), the DCM
				 * 		module shall call the configured Xxx_RequestResults() function and provide the
				 * 		dataOut reference according of the list of output signal configured for this
				 * 		routine ( see configuration parameter DcmDspRequestRoutineResultsOut).
				 */
				if(4u != pMsgContext->ReqDataLen)
				{
					*pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;

					result = (Std_ReturnType)E_NOT_OK;
				}
#if(0u != DCM_DSP_REQUEST_ROUTINE_RESULTS_OUT_SIGNAL_NUM)
				else
				{
					/**
					 * @req [SWS_Dcm_00405] Upon completing SWS_Dcm_00404, when Xxx_RequestResults()
					 * 		returns no ErrorCode, the Dcm module shall reply with a positive response
					 * 		with the data returned by Xxx_RequestResults()in the dataOut as routineInfo
					 * 		and routineStatusRecord (dataOut are merged according to the list of output
					 * 		signal configured for this routine ( see configuration parameter
					 * 		DcmDspRequestRoutineResultsOut)).The datalength of the dataOut can be fixed
					 * 		or dynamic according to DcmDspRoutineSignalType. If dynamic, the datalength
					 * 		shall be provided in the parameter currentDataLength who holds the length in
					 * 		bytes of the last dataOut parameter.The datalength can be dynamic only on
					 * 		the last dataOut parameter.
					 */
					result = Dcm_UDS0x31ResDataLenCheck(\
								pRequestRoutineResults->DcmDspRequestRoutineResultsOutSignalNum,\
								pRequestRoutineResults->DcmDspRequestRoutineResultsOutSignal,\
								pMsgContext, pErrorCode\
								);
				}
#endif /* #if(0u != DCM_DSP_REQUEST_ROUTINE_RESULTS_OUT_SIGNAL_NUM) */

#if(0u != DCM_DSP_COMMON_AUTHORIZATION_NUM)
			}
#endif /* #if(0u != DCM_DSP_COMMON_AUTHORIZATION_NUM) */
		}
	}

	if((Std_ReturnType)E_OK == result)
	{
		result = pRequestRoutineResults->DcmDspRequestRoutineResultsFnc(\
					opState,\
					&pMsgContext->ResData[4], Dcm_UDS0x31Status.DataOutVarPtr,\
					&Dcm_UDS0x31Status.OutSignalDynLen,\
					pErrorCode\
					);
	}

	return result;
}
#endif /* #if(STD_ON == DCM_DSP_ROUTINE_REQUEST_RESULTS_ENABLED) */
/*====================================================================================================*
 *                                          GLOBAL FUNCTIONS
 *====================================================================================================*/
/**
 * @brief			Dcm_UDS0x31
 * @details			Internal processing interface for Service 0x31.
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
FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x31
(
	Dcm_OpStatusType OpStatus,
	P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
)
{
	Std_ReturnType result = (Std_ReturnType)E_OK;

	uint8 u8Index;
	uint8 u8SubServiceId = pMsgContext->ReqData[1];
	uint16 u16Rid;
	const Dcm_DspRoutineType* pRoutine = NULL_PTR;

	if(DCM_PENDING != OpStatus)
	{
		if(4u > pMsgContext->ReqDataLen)
		{
			*ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;

			result = (Std_ReturnType)E_NOT_OK;
		}
		else
		{
			u16Rid = ((uint16)pMsgContext->ReqData[2] << 8u);
			u16Rid |= (uint16)pMsgContext->ReqData[3];

			/**
			 * @req [SWS_Dcm_00568] On reception of the UDS Service RoutineControl (0x31), the DCM
			 * 		module shall check if the Routine is supported (see configuration parameter
			 * 		DcmDspRoutine) If not, the DCM module shall send NRC 0x31 (Request out of range).
			 *
			 * @req [SWS_Dcm_00569] If a Routine is set as unused (DcmDspRoutineUsed set to FALSE), the
			 * 		DCM shall consider the Routine as not supported (according to SWS_Dcm_00568).
			 */
			for(u8Index = 0u; u8Index < DCM_DSP_ROUTINE_NUM; u8Index++)
			{
				pRoutine = &Dcm_ConfigPtr->DcmDsp->DcmDspRoutine[u8Index];

				if((pRoutine->DcmDspRoutineIdentifier == u16Rid) &&\
					((boolean)TRUE == pRoutine->DcmDspRoutineUsed))
				{
					break;
				}
			}
			if(DCM_DSP_ROUTINE_NUM == u8Index)
			{
				*ErrorCode = DCM_E_REQUESTOUTOFRANGE;

				result = (Std_ReturnType)E_NOT_OK;
			}
			else
			{
#if(0u != DCM_DSP_COMMON_AUTHORIZATION_NUM)

				result = Dcm_UDS0x31PermissionCheckHandle(\
							pRoutine->DcmDspCommonAuthorizationRef, ErrorCode\
							);

				if((Std_ReturnType)E_OK == result)
				{
#endif /* #if(0u != DCM_DSP_COMMON_AUTHORIZATION_NUM) */

					result = DspInternal_SubServiceCheck(\
								(pMsgContext->MsgAddInfo & 0x01u), u8SubServiceId,\
								DCM_GET_SERVICE_PTR(Dcm_ConnectionStatus[Dcm_ActiveConIdx].ServiceIdx),\
								ErrorCode\
								);

					if((Std_ReturnType)E_OK == result)
					{
						Dcm_UDS0x31Status.RoutinePtr = pRoutine;
						Dcm_UDS0x31Status.InSignalDynLen = 0u;
						Dcm_UDS0x31Status.OutSignalDynLen = 0u;
						Dcm_UDS0x31Status.DataTotalLen = 4u;
						Dcm_UDS0x31Status.DataInVarPtr = NULL_PTR;
						Dcm_UDS0x31Status.DataOutVarPtr = NULL_PTR;
					}

#if(0u != DCM_DSP_COMMON_AUTHORIZATION_NUM)
				}
#endif /* #if(0u != DCM_DSP_COMMON_AUTHORIZATION_NUM) */
			}
		}
	}

	if((Std_ReturnType)E_OK == result)
	{
		/**
		 * @req [SWS_Dcm_00869] On reception of the UDS Service RoutineControl (0x31), the Dcm module
		 * 		shall check if the SubFunction to the corresponding Routine is supported (see existence
		 * 		of configuration container DcmDspStopRoutine for SubFunction 0x02;
		 * 		DcmDspRequestRoutineResults for SubFunction 0x03). If not, the Dcm module shall send NRC
		 * 		0x12 (SubFunction not supported).
		 */
		switch(u8SubServiceId)
		{
#if(STD_ON == DCM_DSP_ROUTINE_START_ENABLED)
		case 0x01u:
			result = Dcm_UDS0x31StartRoutineHandle(OpStatus, pMsgContext, ErrorCode);
			break;
#endif /* #if(STD_ON == DCM_DSP_ROUTINE_START_ENABLED) */
#if(STD_ON == DCM_DSP_ROUTINE_STOP_ENABLED)
		case 0x02u:
			result = Dcm_UDS0x31StopRoutineHandle(OpStatus, pMsgContext, ErrorCode);
			break;
#endif /* #if(STD_ON == DCM_DSP_ROUTINE_STOP_ENABLED) */
#if(STD_ON == DCM_DSP_ROUTINE_REQUEST_RESULTS_ENABLED)
		case 0x03u:
			result = Dcm_UDS0x31RequestRoutineResultsHandle(OpStatus, pMsgContext, ErrorCode);
			break;
#endif /* #if(STD_ON == DCM_DSP_ROUTINE_REQUEST_RESULTS_ENABLED) */
		default:
			/* Nothing to do here. */
			break;
		}

		if((Std_ReturnType)E_OK == result)
		{
			pMsgContext->ResData[0] = 0x71u;
			pMsgContext->ResData[1] = pMsgContext->ReqData[1];
			pMsgContext->ResData[2] = pMsgContext->ReqData[2];
			pMsgContext->ResData[3] = pMsgContext->ReqData[3];
			pMsgContext->ResDataLen = ((uint32)Dcm_UDS0x31Status.DataTotalLen + (uint32)Dcm_UDS0x31Status.OutSignalDynLen);
		}
		else
		{
			if((Std_ReturnType)DCM_E_PENDING == result)
			{
				Dcm_OpState = DCM_PENDING;
				*ErrorCode = DCM_E_RESPONSE_PENDING;
			}
			else if((Std_ReturnType)DCM_E_FORCE_RCRRP == result)
			{
				Dcm_OpState = DCM_FORCE_RCRRP_OK;
				*ErrorCode = DCM_E_RESPONSE_PENDING;
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

#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#endif /* #if(STD_ON == DCM_UDS0x31_INTERNAL_FNC_ENABLE) */
#endif /* #if(STD_ON == DCM_UDS0x31_ENABLE) */

#ifdef __cplusplus
}
#endif
/** @} */
