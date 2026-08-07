/**
 * @file       	Dcm_Internal.c
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

/* PRQA S 0292, 0288, 1505, 0857, 0791, 3218, 0491, 2981, 2877, 2880, 2984, 0498, 5087, 2469, 2995 EOF #
 *
 * 1.0292 -- Violates MISRA 2004 Required Rule 3.1, Source file has comments containing one of the
 * characters '$', '@' or '`'.
 *
 * 2.0288 -- Violates MISRA 2004 Required Rule 3.1, Source file has comments containing characters which
 * are not members of the basic source character set.
 *
 * 3.1505 -- Violates MISRA 2004 Required Rule 8.10, The function is only referenced in the translation
 * unit where it is defined.
 *
 * 4.0857 -- Violates MISRA 2004 Required Rule 1.1, Number of macro definitions exceeds 1024 - program
 * does not conform strictly to ISO:C90.
 *
 * 5.0791 -- Violates MISRA 2004 Required Rule 5.1, Macro identifier does not differ from other macro
 * identifier(s) within the specified number of significant characters.
 *
 * 6.3218 -- Violates MISRA 2004 Required Rule 8.7, File scope static, 'Dcm_PendBuffer' and
 * 'Dcm_NRCBuffer', is only accessed in one function.
 *
 * 7.0491 -- Violates MISRA 2004 Required Rule 17.4, Array subscripting applied to an object of pointer
 * type.
 *
 * 8.2981 -- Violates MISRA 2004 Required Rule 21.1, This initialization is redundant. The value of this
 * object is never used before being modified.
 *
 * 9.2877 -- Violates MISRA 2004 Required Rule 21.1, This loop will never be executed more than once.
 *
 * 10.2880 -- Violates MISRA 2004 Required Rule 14.1, This code is unreachable.
 *
 * 11.2984 -- Violates MISRA 2004 Required Rule 21.1, This operation is redundant. The value of the
 * result is always '1'.
 *
 * 12.0498 -- Violates MISRA 2004 Required Rule 17.4, A unary increment or decrement operator is being
 * applied to a pointer.
 *
 * 13.5087 -- Violates MISRA 2004 Required Rule 19.1, Use of #include directive after code fragment.
 *
 * 14.2469 -- Violates MISRA 2004 Required Rule 13.6, Loop control variable in this 'for' statement,
 * %1s, is modified in the body of the loop.
 *
 * 15.2995 -- Violates MISRA 2004 Required Rule 13.7, The result of this logical operation is always
 * 'true'.
 *
 * @page misra_violations MISRA-C:2004 violations
 */
/* PRQA S 2996, 0492, 1031, 2792, 4391, 0715 EOF #
 *
 * 1.2996 -- Violates MISRA 2004 Required Rule 13.7, The result of this logical operation is always
 * 'false'.
 *
 * 2.0492 -- Violates MISRA 2004 Required Rule 17.4, Array subscripting applied to a function parameter
 * declared as a pointer.
 *
 * 3.1031 -- Violates MISRA 2004 Required Rule 1.1, [C99] Initializer for 'struct', 'union' or array
 * type is not a constant expression.
 *
 * 4.2792 -- Violates MISRA 2004 Required Rule 21.1, Apparent: Right hand operand of shift operator is
 * negative or too large.
 *
 * 5.4391 -- Violates MISRA 2004 Required Rule 10.3, A composite expression of 'essentially unsigned'
 * type (%1s) is being cast to a wider unsigned type, '%2s'.
 *
 * 6.0715 -- Violates MISRA 2004 Required Rule 1.1, [L] Nesting of control structures (statements)
 * exceeds 15 - program does not conform strictly to ISO:C90.
 *
 * @page misra_violations MISRA-C:2004 violations
 */

/*====================================================================================================*
 *                                           INCLUDE FILES
 *====================================================================================================*/
#include "Dcm_Internal.h"
#include "Rte_Dem.h"
#include "mcu.h"
#include "eep_emulation.h"
#if(STD_ON == DCM_DSP_TRNASFER_ERROR_HANDLING_ENABLE)
/* Bootloader module, no need version check. */
#include "FBL.h"
#endif /* #if(STD_ON == DCM_DSP_TRNASFER_ERROR_HANDLING_ENABLE) */

#ifdef AH_TEST_DCM
#include "TestCode.h"
#endif /* #ifdef AH_TEST_DCM */
/*====================================================================================================*
 *                                  SOURCE FILE VERSION INFORMATION
 *====================================================================================================*/
#define DCM_INTERNAL_VENDOR_ID_C                            (0x00U)
#define DCM_INTERNAL_AR_RELEASE_MAJOR_VERSION_C             (0x04U)
#define DCM_INTERNAL_AR_RELEASE_MINOR_VERSION_C             (0x02U)
#define DCM_INTERNAL_AR_RELEASE_REVISION_VERSION_C          (0x02U)
#define DCM_INTERNAL_SW_MAJOR_VERSION_C                     (0x01U)
#define DCM_INTERNAL_SW_MINOR_VERSION_C                     (0x02U)
#define DCM_INTERNAL_SW_PATCH_VERSION_C                     (0x00U)
/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/
/* Check if current file and Dcm_Internal header file are of the same vendor */
#if(DCM_INTERNAL_VENDOR_ID_C != DCM_INTERNAL_VENDOR_ID )
#error "Dcm_Internal.c and Dcm_Internal.h have different vendor id"
#endif
/* Check if current file and Dcm_Internal header file are of the same Autosar version */
#if(\
		(DCM_INTERNAL_AR_RELEASE_MAJOR_VERSION_C != DCM_INTERNAL_AR_RELEASE_MAJOR_VERSION) || \
		(DCM_INTERNAL_AR_RELEASE_MINOR_VERSION_C != DCM_INTERNAL_AR_RELEASE_MINOR_VERSION) || \
		(DCM_INTERNAL_AR_RELEASE_REVISION_VERSION_C != DCM_INTERNAL_AR_RELEASE_REVISION_VERSION) \
)
#error "AutoSar Version Number of Dcm_Internal.c and Dcm_Internal.h are different"
#endif
/* Check if current file and Dcm_Internal header file are of the same software version */
#if(\
		(DCM_INTERNAL_SW_MAJOR_VERSION_C != DCM_INTERNAL_SW_MAJOR_VERSION) || \
		(DCM_INTERNAL_SW_MINOR_VERSION_C != DCM_INTERNAL_SW_MINOR_VERSION) || \
		(DCM_INTERNAL_SW_PATCH_VERSION_C != DCM_INTERNAL_SW_PATCH_VERSION) \
)
#error "Software Version Number of Dcm_Internal.c and Dcm_Internal.h are different"
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
#define DCM_START_SEC_VAR_INIT_8
#include "Dcm_MemMap.h"

/**
 * @brief 	Independent pending buffer.
 */
STATIC VAR(uint8, DCM_VAR)Dcm_PendBuffer[3] = {(uint8)0x7F, (uint8)0xFF, (uint8)0x78};

#ifdef DCM_DSP_SECURITY_REF_DATA_TYPE_UINT8
/**
 * @brief	Store the index of the currently active security access level within the configuration.
 */
STATIC VAR(Dcm_SecurityDataType, DCM_VAR)Dcm_ActiveSecurityIdx;
#endif /* #ifdef DCM_DSP_SECURITY_REF_DATA_TYPE_UINT8 */

#define DCM_STOP_SEC_VAR_INIT_8
#include "Dcm_MemMap.h"

#ifdef DCM_DSP_SECURITY_REF_DATA_TYPE_UINT16

#define DCM_START_SEC_VAR_INIT_16
#include "Dcm_MemMap.h"

/**
 * @brief	Store the index of the currently active security access level within the configuration.
 */
STATIC VAR(Dcm_SecurityDataType, DCM_VAR)Dcm_ActiveSecurityIdx;

#define DCM_STOP_SEC_VAR_INIT_16
#include "Dcm_MemMap.h"

#endif /* #ifdef DCM_DSP_SECURITY_REF_DATA_TYPE_UINT16 */

#ifdef DCM_DSP_SECURITY_REF_DATA_TYPE_UINT32

#define DCM_START_SEC_VAR_INIT_32
#include "Dcm_MemMap.h"

/**
 * @brief	Store the index of the currently active security access level within the configuration.
 */
STATIC VAR(Dcm_SecurityDataType, DCM_VAR)Dcm_ActiveSecurityIdx;

#define DCM_STOP_SEC_VAR_INIT_32
#include "Dcm_MemMap.h"

#endif /* #ifdef DCM_DSP_SECURITY_REF_DATA_TYPE_UINT32 */

#define DCM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dcm_MemMap.h"

#if(0u != DCM_DSL_DIAG_RESP_MAX_NUM_RESP_PEND)
/**
 * @brief 	Store the relevant status of the P2* timer.
 */
STATIC VAR(Dcm_P2StarTimerStatusType, DCM_VAR)Dcm_P2StarTimerStatus;
#endif /* #if(0u != DCM_DSL_DIAG_RESP_MAX_NUM_RESP_PEND) */

#if((STD_ON == DCM_DSD_SERVICE_P4_TIMER_ENABLE) || (STD_ON == DCM_DSD_SUB_SERVICE_P4_TIMER_ENABLE))
/**
 * @brief 	Store the relevant status of the P4 timer.
 */
STATIC VAR(Dcm_P4TimerStatusType, DCM_VAR)Dcm_P4TimerStatus;
#endif /* #if((STD_ON == DCM_DSD_SERVICE_P4_TIMER_ENABLE) || (STD_ON == DCM_DSD_SUB_SERVICE_P4_TIMER_ENABLE)) */

#define DCM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dcm_MemMap.h"
/*====================================================================================================*
 *                                      LOCAL FUNCTION PROTOTYPES
 *====================================================================================================*/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"

#if(0u != DCM_DSL_PROTOCOLROW_NUM)
#if(STD_ON == DCM_DSL_CALLBACK_DCM_REQUEST_SERVICE_ENABLED)
STATIC FUNC(boolean, DCM_CODE)DslInternal_StopProtocol
(
	P2CONST(Dcm_DslProtocolRowType, AUTOMATIC, DCM_CONST)pProtocolRow
);
#else
STATIC FUNC(void, DCM_CODE)DslInternal_StopProtocol
(
	void
);
#endif /* #if(STD_ON == DCM_DSL_CALLBACK_DCM_REQUEST_SERVICE_ENABLED) */
#endif /* #if(0u != DCM_DSL_PROTOCOLROW_NUM) */

STATIC FUNC(boolean, DCM_CODE)DsdInternal_ResponseNRCHandle
(
	uint8 u8ConIdx,
	uint8 u8ProRowIdx
);

STATIC FUNC(void, DCM_CODE)DsdInternal_ResponseProcess
(
	Std_ReturnType result
);

#if(STD_ON == DCM_UDS0x27_ENABLE)
STATIC FUNC(void, DCM_CODE)DspInternal_SecurityInit
(
	void
);

#if(STD_ON == DCM_DSP_SECURITY_ATTEMPT_COUNTER_ENABLED)
STATIC FUNC(void, DCM_CODE)DspInternal_SecurityCancelInitHandle
(
	void
);

STATIC FUNC(void, DCM_CODE)DspInternal_SecurityInitHandle
(
	void
);
#endif /* #if(STD_ON == DCM_DSP_SECURITY_ATTEMPT_COUNTER_ENABLED) */

STATIC FUNC(void, DCM_CODE)DspInternal_SecurityDelayHandle
(
	void
);

#if(STD_ON == DCM_DSP_SECURITY_ATTEMPT_COUNTER_ENABLED)
STATIC FUNC(void, DCM_CODE)DspInternal_SecurityAttemptCntCheckHandle
(
	uint8 u8Index,
	P2CONST(Dcm_DspSecurityRowType, AUTOMATIC, DCM_CONST)pSecurityRow
);
#endif /* #if(STD_ON == DCM_DSP_SECURITY_ATTEMPT_COUNTER_ENABLED) */
#endif /* #if(STD_ON == DCM_UDS0x27_ENABLE) */

#if(STD_ON == DCM_UDS0x10_ENABLE)
STATIC FUNC(void, DCM_CODE)DspInternal_SessionControlConfirmation
(
	void
);
#endif /* #if(STD_ON == DCM_UDS0x10_ENABLE) */

#if(STD_ON == DCM_UDS0x11_ENABLE)
STATIC FUNC(void, DCM_CODE)DspInternal_EcuResetConfirmation
(
	void
);
#endif /* #if(STD_ON == DCM_UDS0x11_ENABLE) */

#if(STD_ON == DCM_UDS0x27_ENABLE)
STATIC FUNC(void, DCM_CODE)DspInternal_SecurityAccessConfirmation
(
	void
);
#endif /* #if(STD_ON == DCM_UDS0x27_ENABLE) */

#if(0u != DCM_DSP_DATA_BLOCK_USED_NUM)
STATIC FUNC(void, DCM_CODE)DspInternal_ReadBlockInit
(
	void
);
#endif /* #if(0u != DCM_DSP_DATA_BLOCK_USED_NUM) */
STATIC FUNC(void, DCM_CODE)DspInternal_ResetServiceSetState
(
	Dcm_SesCtrlType sesCtrlType,
	Dcm_SessionDataType newSesIdx
);

#if(STD_ON == DCM_UDS0x2A_ENABLE)
#if(STD_ON == DCM_DSP_DATA_READ_FNC_ENABLED)
STATIC FUNC(Std_ReturnType, DCM_CODE)DspInternal_PeriodicTransGetData
(
	uint8 u8DidIndex,
	P2VAR(uint16, AUTOMATIC, DCM_VAR)pBufOffset,
	P2VAR(uint8, AUTOMATIC, DCM_VAR)pDataBuffer,
	P2CONST(Dcm_SchedulerTableType, AUTOMATIC, DCM_CONST)pScheduler
);
#endif /* #if(STD_ON == DCM_DSP_DATA_READ_FNC_ENABLED) */

STATIC FUNC(Std_ReturnType, DCM_CODE)DspInternal_PeriodicTransProcess
(
	P2VAR(Dcm_SchedulerTableType, AUTOMATIC, DCM_VAR)pScheduler
);

STATIC FUNC(void, DCM_CODE)DspInternal_ReSortSchedulerTable
(
	uint8 u8SchedulerIndex
);
#endif /* #if(STD_ON == DCM_UDS0x2A_ENABLE) */

STATIC FUNC(Std_ReturnType, DCM_CODE)DspInternal_GeneralCheck
(
	uint8 u8Sid,
	Dcm_DslProtocolRxAddrType addrType,
	P2VAR(uint8, AUTOMATIC, DCM_VAR)pServiceIdx,
	P2CONST(Dcm_DslProtocolRowType, AUTOMATIC, DCM_CONST)pProtocolRow
);
/*====================================================================================================*
 *                                           LOCAL FUNCTIONS
 *====================================================================================================*/
#if(0u != DCM_DSL_PROTOCOLROW_NUM)
/**
 * @brief			DslInternal_StopProtocol
 * @details			When protocol preemption occurs and fails, the protocol can be disabled by calling
 * 					this interface
 *
 * @param[in]		pProtocolRow:Pointer to the used DcmDslProtocolRow container.
 *
 * @return        	Result of this operation.
 * @retval			TRUE:Disable successfully.
 * @retval			FALSE:Disable failed.
 */
#if(STD_ON == DCM_DSL_CALLBACK_DCM_REQUEST_SERVICE_ENABLED)
STATIC FUNC(boolean, DCM_CODE)DslInternal_StopProtocol
(
	P2CONST(Dcm_DslProtocolRowType, AUTOMATIC, DCM_CONST)pProtocolRow
)
#else
STATIC FUNC(void, DCM_CODE)DslInternal_StopProtocol
(
	void
)
#endif /* #if(STD_ON == DCM_DSL_CALLBACK_DCM_REQUEST_SERVICE_ENABLED) */
{
#if((STD_ON == DCM_DSL_CANCEL_TRANSMIT_ENABLE) || (STD_ON == DCM_DSL_CANCEL_RECEIVE_ENABLE))
	uint8 u8ConIdx = Dcm_ActiveConIdx;
#endif /* #if((STD_ON == DCM_DSL_CANCEL_TRANSMIT_ENABLE) || (STD_ON == DCM_DSL_CANCEL_RECEIVE_ENABLE)) */
	uint8 u8ProRowIdx = Dcm_ActiveProRowIdx;

#if(STD_ON == DCM_DSL_CALLBACK_DCM_REQUEST_SERVICE_ENABLED)
	boolean result = (boolean)TRUE;
	uint8 u8Index;
	Std_ReturnType callbackRet = (Std_ReturnType)E_NOT_OK;
	uint16 u16ConnectionId = Dcm_ConfigPtr->DcmDslMainConnection[u8ConIdx].DcmDslProtocolRxConnectionId;

	for(u8Index = 0u; u8Index < DCM_DSL_CALLBACK_STOP_PROTOCOL_NUM; u8Index++)
	{
		callbackRet = Dcm_ConfigPtr->DcmDsl->DcmDslCallbackDCMRequestService->DcmDslCallbackStopProtocol[u8Index](pProtocolRow->DcmDslProtocolID, 0xFFFFu, u16ConnectionId);

		if((Std_ReturnType)E_OK != callbackRet)
		{
			result = (boolean)FALSE;
			break;
		}
	}

	if((boolean)TRUE == result)
	{
#endif /* #if(STD_ON == DCM_DSL_CALLBACK_STOP_PROTOCOL_NUM) */

#if((STD_ON == DCM_DSL_CANCEL_TRANSMIT_ENABLE) || (STD_ON == DCM_DSL_CANCEL_RECEIVE_ENABLE))
		if(0xFFu != u8ConIdx)
		{
#if(STD_ON == DCM_DSL_CANCEL_TRANSMIT_ENABLE)
			/**
			 * @req [SWS_Dcm_00079] In order to cancel pending transmission in lower-layer, related to
			 * 		the lower priority request, the DCM module shall call PduR_DcmCancelTransmit () with
			 * 		the following parameters: PduId: the id of the Pdu to be canceled.
			 *
			 * @req [SWS_Dcm_00460] When PduR_DcmCancelTransmit() returns E_NOT_OK, the DCM module shall
			 * 		assume that the ongoing transmission cannot be cancelled and shall not retry to
			 * 		cancel the transmit request. The current protocol shall be stopped and the new one
			 * 		started.
			 */
			if((DCM_TX_STATE_COPY == Dcm_ConnectionStatus[u8ConIdx].TxState) ||\
				(DCM_TX_STATE_CONFIRM == Dcm_ConnectionStatus[u8ConIdx].TxState))
			{
				(void)PduR_DcmCancelTransmit(\
							Dcm_ConfigPtr->DcmDslMainConnection[u8ConIdx].DcmDslProtocolTx->DcmDslProtocolTxPduRef\
							);
			}
#endif /* #if(STD_ON == DCM_DSL_CANCEL_TRANSMIT_ENABLE) */

#if(STD_ON == DCM_DSL_CANCEL_RECEIVE_ENABLE)
			/**
			 * @req [SWS_Dcm_00575] In order to cancel pending reception in lower-layer, related to the
			 * 		lower priority request, the DCM module shall call PduR_DcmCancelReceive() with the
			 * 		following parameters: PduId: the id of the Pdu to be canceled.
			 *
			 * @req [SWS_Dcm_00576] When PduR_DcmCancelReceive () returns E_NOT_OK, the DCM module shall
			 * 		assume that the ongoing reception cannot be cancelled and shall not retry to cancel
			 * 		the receive request. The current protocol shall be stopped and the new one started.
			 */
			if((DCM_RX_STATE_COPY == Dcm_ConnectionStatus[u8ConIdx].RxState) ||\
				(DCM_RX_STATE_RECEIVED == Dcm_ConnectionStatus[u8ConIdx].RxState))
			{
				(void)PduR_DcmCancelReceive(\
							Dcm_ConfigPtr->DcmDslProtocolRx[Dcm_MsgContext[u8ProRowIdx].DcmRxPduId].DcmDslProtocolRxPduRef\
							);
			}
#endif /* #if(STD_ON == DCM_DSL_CANCEL_RECEIVE_ENABLE) */
		}
#endif /* #if((STD_ON == DCM_DSL_CANCEL_TRANSMIT_ENABLE) || (STD_ON == DCM_DSL_CANCEL_RECEIVE_ENABLE)) */

		DslInternal_ResetConnectionStatus();

		DCM_BIT_CLEAR(Dcm_ProtocolStartState, u8ProRowIdx, uint8);
#if(STD_ON == DCM_DSL_CALLBACK_DCM_REQUEST_SERVICE_ENABLED)
	}

	return result;
#endif /* #if(STD_ON == DCM_DSL_CALLBACK_DCM_REQUEST_SERVICE_ENABLED) */
}
#endif /* #if(0u != DCM_DSL_PROTOCOLROW_NUM) */

/**
 * @brief			DsdInternal_ResponseNRCHandle
 * @details			DSD internal interface, assembly negative response.
 *
 * @return     		Result of this operation.
 * @retval			TRUE:Need to transmit this response.
 * @retval			FALSE:No need to transmit this response.
 */
STATIC FUNC(boolean, DCM_CODE)DsdInternal_ResponseNRCHandle
(
	uint8 u8ConIdx,
	uint8 u8ProRowIdx
)
{
	boolean result = (boolean)TRUE;

	if(DCM_POS_RESP == Dcm_ConnectionStatus[u8ConIdx].NRC)
	{
		DslInternal_ResetConnectionStatus();

		DCM_DET_ERROR_REPORT(DCM_SID_TPRXINDICATION, DCM_E_INVALID_VALUE);

		result = (boolean)FALSE;
	}
	/**
	 * @req [SWS_Dcm_00001] In the case of a Negative Result of the execution and active Functional
	 * 		Addressing the DSD submodule shall activate the suppression of the following Negative
	 * 		Responses: NRC 0x11 (Service not supported), NRC 0x12 (SubFunction not supported), NRC 0x31
	 * 		(Request out of range), NRC 0x7E (Subfunction not supported in active session), NRC 0x7F
	 * 		(Service not supported in active session).
	 */
	else if((0x01u == (Dcm_MsgContext[u8ProRowIdx].MsgAddInfo & 0x01u)) &&\
			((DCM_E_SERVICENOTSUPPORTED == Dcm_ConnectionStatus[u8ConIdx].NRC) ||\
			(DCM_E_SUBFUNCTIONNOTSUPPORTED == Dcm_ConnectionStatus[u8ConIdx].NRC) ||\
			(DCM_E_REQUESTOUTOFRANGE == Dcm_ConnectionStatus[u8ConIdx].NRC) ||\
			(DCM_E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION == Dcm_ConnectionStatus[u8ConIdx].NRC) ||\
			(DCM_E_SERVICENOTSUPPORTEDINACTIVESESSION == Dcm_ConnectionStatus[u8ConIdx].NRC)))
	{
		DslInternal_ResetConnectionStatus();

		result = (boolean)FALSE;
	}
	else
	{
		/**
		 * @req [SWS_Dcm_00228] The DSD submodule shall handle all NRCs supported from the Application
		 * 		and defined in Dcm_NegativeResponseCodeType.
		 */

		if(DCM_E_RESPONSE_PENDING == Dcm_ConnectionStatus[u8ConIdx].NRC)
		{
#if(STD_ON == DCM_DSP_SESSION_TIM_P2_PENDING_WINDOW)
			if(Dcm_P2TimerStatus.PendingThreshold <= Dcm_P2TimerStatus.CurrentTime)
			{
#endif /* #if(STD_ON == DCM_DSP_SESSION_TIM_P2_PENDING_WINDOW) */

#if((STD_ON == DCM_DSD_SERVICE_P4_TIMER_ENABLE) || (STD_ON == DCM_DSD_SUB_SERVICE_P4_TIMER_ENABLE))
				if(Dcm_P4TimerStatus.TimeoutTime == Dcm_P2TimerStatus.TimeoutTime)
				{
					Dcm_P2StarTimerStatus.PendingProcessState = (boolean)TRUE;

					result = (boolean)FALSE;
				}
				else
#endif /* #if((STD_ON == DCM_DSD_SERVICE_P4_TIMER_ENABLE) || (STD_ON == DCM_DSD_SUB_SERVICE_P4_TIMER_ENABLE)) */
				{
					/**
					 * @req [SWS_Dcm_00203] In case of responsePending the DCM module shall clear the
					 * 		"suppressPosRspMsgIndicationBit.�
					 */
					DCM_BIT_CLEAR(Dcm_MsgContext[u8ProRowIdx].MsgAddInfo, 1u, Dcm_MsgAddInfoType);

#if(0u != DCM_DSL_DIAG_RESP_MAX_NUM_RESP_PEND)
					if((DCM_FORCE_RCRRP_OK == Dcm_OpState) ||\
						((boolean)TRUE == Dcm_P2StarTimerStatus.PendingNRCSendState))
					{
						Dcm_P2StarTimerStatus.PendingCnt++;

						if(DCM_DSL_DIAG_RESP_MAX_NUM_RESP_PEND < Dcm_P2StarTimerStatus.PendingCnt)
						{
							Dcm_OpState = DCM_CANCEL;
							Dcm_ConnectionStatus[u8ConIdx].NRC = DCM_E_GENERALREJECT;

							DCM_DET_ERROR_REPORT(DCM_SID_MAINFUNCTION, DCM_E_INTERFACE_TIMEOUT);
						}
						else
						{
							Dcm_MsgContext[u8ProRowIdx].ResData = Dcm_PendBuffer;
							Dcm_MsgContext[u8ProRowIdx].ResDataLen = 3u;

							Dcm_PendBuffer[1] = Dcm_MsgContext[u8ProRowIdx].ReqData[0];
						}
					}
					else
					{
						result = (boolean)FALSE;
					}
#else
					Dcm_OpState = DCM_CANCEL;
					Dcm_ConnectionStatus[u8ConIdx].NRC = DCM_E_GENERALREJECT;

					DCM_DET_ERROR_REPORT(DCM_SID_MAINFUNCTION, DCM_E_INTERFACE_TIMEOUT);
#endif /* #if(0u != DCM_DSL_DIAG_RESP_MAX_NUM_RESP_PEND) */
				}

#if(STD_ON == DCM_DSP_SESSION_TIM_P2_PENDING_WINDOW)
			}
			else
			{
				Dcm_P2StarTimerStatus.PendingProcessState = (boolean)TRUE;

				result = (boolean)FALSE;
			}
#endif /* #if(STD_ON == DCM_DSP_SESSION_TIM_P2_PENDING_WINDOW) */
		}

#if(0u != DCM_DSL_DIAG_RESP_MAX_NUM_RESP_PEND)
		if(DCM_E_RESPONSE_PENDING != Dcm_ConnectionStatus[u8ConIdx].NRC)
		{
			if(DCM_CANCEL != Dcm_OpState)
			{
				Dcm_OpState = DCM_FAILED;
			}
#endif /* #if(0u != DCM_DSL_DIAG_RESP_MAX_NUM_RESP_PEND) */

			Dcm_MsgContext[u8ProRowIdx].ResData = Dcm_ConfigPtr->DcmDsl->DcmDslProtocolRow[u8ProRowIdx].DcmDslProtocolTxBufferRef->DcmDslBufferRef;
			Dcm_MsgContext[u8ProRowIdx].ResData[0] = 0x7Fu;
			Dcm_MsgContext[u8ProRowIdx].ResData[1] = Dcm_MsgContext[u8ProRowIdx].ReqData[0];

			/**
			 * @req [SWS_Dcm_00271] Unless another particular NRC is specified,the DSP submodule shall
			 * 		trigger a negative response with NRC 0x10 (generalReject), when the API calls made
			 * 		to execute the service do not return OK.
			 */
			if((Dcm_NegativeResponseCodeType)0xFF == Dcm_ConnectionStatus[u8ConIdx].NRC)
			{
				Dcm_ConnectionStatus[u8ConIdx].NRC = DCM_E_GENERALREJECT;
			}

			Dcm_MsgContext[u8ProRowIdx].ResData[2] = Dcm_ConnectionStatus[u8ConIdx].NRC;
			Dcm_MsgContext[u8ProRowIdx].ResDataLen = 3u;

#if(0u != DCM_DSL_DIAG_RESP_MAX_NUM_RESP_PEND)
		}
#endif /* #if(0u != DCM_DSL_DIAG_RESP_MAX_NUM_RESP_PEND) */
	}

	return result;
}

/**
 * @brief			DsdInternal_ResponseProcess
 * @details			DSD internal interface, assembly the response.
 *
 * @param[in]		result:Indicate whether the response is positive or negative.
 */
STATIC FUNC(void, DCM_CODE)DsdInternal_ResponseProcess
(
	Std_ReturnType result
)
{
	boolean flag = (boolean)FALSE;
	uint8 u8ConIdx = Dcm_ActiveConIdx;
	uint8 u8ProRowIdx = Dcm_ActiveProRowIdx;
	const Dcm_DslProtocolTxType* pProtocolTx = Dcm_ConfigPtr->DcmDslMainConnection[u8ConIdx].DcmDslProtocolTx;

	if((Std_ReturnType)E_OK == result)
	{
		/**
		 * @req [SWS_Dcm_00200] If the "suppressPosRspMsgIndicationBit� is TRUE, the DSD submodule shall
		 * 		NOT send a positive response message.
		 *
		 * @req [SWS_Dcm_00231] In the case that the "suppressPosRspMsgIndicationBit� is indicated in
		 * 		the functionality "Handling of suppressPosRspMsgIndicationBit� (stored in the Variable
		 * 		Dcm_MsgContextType (Element: Dcm_MsgAddInfo)), the DSD submodule shall activate the
		 * 		suppression of Positive Responses.
		 *
		 * @req [SWS_Dcm_00238] In the case that no diagnostic (response) message shall be sent
		 * 		(Suppression of Responses) the DSL submodule shall not transmit any response.
		 */
		if((NULL_PTR == pProtocolTx) || (DCM_CHECK_BIT_SET(Dcm_MsgContext[u8ProRowIdx].MsgAddInfo, 1u, uint8)))
		{
			/* Suppression positive response or DcmDslProtocolTx is NULL. */
			(void)DsdInternal_TpTxConfirmation();
			DslInternal_ResetConnectionStatus();
		}
		else
		{
			/* No suppression positive response and DcmDslProtocolTx is not NULL. */
			Dcm_OpState = DCM_INITIAL;
			flag = (boolean)TRUE;
		}
	}
	else
	{
		/**
		 * @req [SWS_Dcm_01166] If the Multiplicity of DcmDslProtocolTx is set to "0" the Dcm shall
		 * 		process the received diagnostic request without sending a response.
		 */
		if(NULL_PTR == pProtocolTx)
		{
			DslInternal_ResetConnectionStatus();
		}
		else
		{
			flag = DsdInternal_ResponseNRCHandle(u8ConIdx, u8ProRowIdx);
		}
	}

	if((boolean)TRUE == flag)
	{
#if(STD_OFF == DCM_RESPOND_ALL_REQUEST)
		/**
		 * @req [SWS_Dcm_00084] If configured (configuration parameter DcmRespondAllRequest=FALSE), if
		 * 		the DCM module receives a diagnostic request that contains a service ID that is in the
		 * 		range from 0x40 to 0x7F or in the range from 0xC0 to 0xFF, the DCM shall not respond to
		 * 		such a request.
		 */
		if(((0x40u <= Dcm_ConnectionStatus[u8ConIdx].ServiceId) &&\
			(0x7Fu >= Dcm_ConnectionStatus[u8ConIdx].ServiceId)) ||\
			(0xC0u <= Dcm_ConnectionStatus[u8ConIdx].ServiceId))
		{
			DslInternal_ResetConnectionStatus();
		}
		else
#endif /* #if(STD_OFF == DCM_RESPONSE_ALL_REQUEST) */
		{
			/**
			 * @req [SWS_Dcm_00114] The DSD submodule shall request the DSL submodule for transmission
			 * 		of responses.
			 *
			 * @req [SWS_Dcm_00232] The DSD submodule shall forward the diagnostic (response) message
			 * 		(positive or negative response) to the DSL submodule.
			 */
			if(DCM_COMM_FULL_COMMUNICATION == Dcm_ComMStatus[u8ConIdx].CommunicationState)
			{
				DslInternal_TransmitHandle(pProtocolTx->DcmDslProtocolTxPduRef);
			}
			else
			{
				Dcm_ConnectionStatus[u8ConIdx].TxState = DCM_TX_STATE_WAITING;
			}
		}
	}
}

#if(STD_ON == DCM_UDS0x27_ENABLE)
/**
 * @brief			DspInternal_SecurityInit
 * @details			DSP internal interface, initialize security internal status.
 */
STATIC FUNC(void, DCM_CODE)DspInternal_SecurityInit
(
	void
)
{
	uint8 u8Index;

#if(STD_ON == DCM_DSP_SECURITY_ATTEMPT_COUNTER_ENABLED)
	Std_ReturnType result;
#endif /* #if(STD_ON == DCM_DSP_SECURITY_ATTEMPT_COUNTER_ENABLED) */

	const Dcm_DspSecurityRowType* pSecurityRow = NULL_PTR;

	Dcm_SecurityInitStatus.CurrentTime = 0u;
#if(STD_ON == DCM_DSP_SECURITY_ATTEMPT_COUNTER_ENABLED)
	Dcm_SecurityInitStatus.AlreadyInitNum = 0u;
	Dcm_SecurityInitStatus.InitState = (boolean)FALSE;
#endif /* #if(STD_ON == DCM_DSP_SECURITY_ATTEMPT_COUNTER_ENABLED) */
	Dcm_SecurityInitStatus.TimerEnable = (boolean)FALSE;

	for(u8Index = 0u; u8Index < DCM_DSP_SECURITY_ROW_NUM; u8Index++)
	{
		Dcm_SecurityStatus[u8Index].AttemptCnt = 0u;
		Dcm_SecurityStatus[u8Index].CurrentTime = 0u;
		Dcm_SecurityStatus[u8Index].TimeoutTime = 0u;
		Dcm_SecurityStatus[u8Index].DelayState = (boolean)FALSE;
		Dcm_SecurityStatus[u8Index].TimerEnable = (boolean)FALSE;
	}

	for(u8Index = 0u; u8Index < DCM_DSP_SECURITY_ROW_NUM; u8Index++)
	{
		pSecurityRow = &Dcm_ConfigPtr->DcmDsp->DcmDspSecurityRow[u8Index];

#if(STD_ON == DCM_DSP_SECURITY_ATTEMPT_COUNTER_ENABLED)
		/**
		 * @req [SWS_Dcm_01157] If configured (configuration parameter
		 * 		DcmDspSecurityAttemptCounterEnabled = TRUE), the Dcm shall provide the operations
		 * 		Xxx_GetSecurityAttemptCounter() and Xxx_SetSecurityAttemptCounter().
		 */
		if((boolean)TRUE == pSecurityRow->DcmDspSecurityAttemptCounterEnabled)
		{
			/**
			 * @req [SWS_Dcm_01154] The Dcm shall call Xxx_GetSecurityAttemptCounter() after
			 * 		initialization to restore the attempt counter values.
			 */
			result = pSecurityRow->DcmDspSecurityGetAttemptCounterFnc(DCM_INITIAL, &Dcm_SecurityStatus[u8Index].AttemptCnt);

			if((Std_ReturnType)E_NOT_OK == result)
			{
				Dcm_SecurityInitStatus.AlreadyInitNum++;

				/**
				 * @req [SWS_Dcm_01156] If Xxx_GetSecurityAttemptCounter() has returned E_NOT_OK the
				 * 		attempt counter shall be assumed as 0.
				 */
				Dcm_SecurityStatus[u8Index].AttemptCnt = 0u;

				/**
				 * @req [SWS_Dcm_01155] The Dcm shall call Xxx_SetSecurityAttemptCounter() when the
				 * 		Dcm has changed the attempt counter to inform the application about the counter
				 * 		change.
				 */
				(void)pSecurityRow->DcmDspSecuritySetAttemptCounterFnc(DCM_INITIAL, 0u);
			}
			else if((Std_ReturnType)DCM_E_PENDING == result)
			{
#if(0u != DCM_DSP_SECURITY_MAX_ATTEMPT_COUNTER_READOUT_TIME)

				Dcm_SecurityInitStatus.TimerEnable = (boolean)TRUE;

#else

				/**
				 * @req [SWS_Dcm_01154] The Dcm shall call Xxx_GetSecurityAttemptCounter() after
				 * 		initialization to restore the attempt counter values.
				 */
				(void)pSecurityRow->DcmDspSecurityGetAttemptCounterFnc(DCM_CANCEL, NULL_PTR);

				DspInternal_SecurityCancelInitHandle();

#endif /* #if(0u != DCM_DSP_SECURITY_MAX_ATTEMPT_COUNTER_READOUT_TIME) */

				break;
			}
			else
			{
				Dcm_SecurityInitStatus.AlreadyInitNum++;

				DspInternal_SecurityAttemptCntCheckHandle(u8Index, pSecurityRow);
			}
		}
		else
#endif /* #if(STD_ON == DCM_DSP_SECURITY_ATTEMPT_COUNTER_ENABLED) */
		{
			if(0u != pSecurityRow->DcmDspSecurityDelayTimeOnBoot)
			{
				Dcm_SecurityStatus[u8Index].DelayState = (boolean)TRUE;
				Dcm_SecurityStatus[u8Index].TimerEnable = (boolean)TRUE;
				Dcm_SecurityStatus[u8Index].TimeoutTime = pSecurityRow->DcmDspSecurityDelayTimeOnBoot;
			}
#if(STD_ON == DCM_DSP_SECURITY_ATTEMPT_COUNTER_ENABLED)
			Dcm_SecurityInitStatus.AlreadyInitNum++;
#endif /* #if(STD_ON == DCM_DSP_SECURITY_ATTEMPT_COUNTER_ENABLED) */
		}
	}

#if(STD_ON == DCM_DSP_SECURITY_ATTEMPT_COUNTER_ENABLED)
	if(DCM_DSP_SECURITY_ROW_NUM == Dcm_SecurityInitStatus.AlreadyInitNum)
	{
		Dcm_SecurityInitStatus.AlreadyInitNum = 0u;
#endif /* #if(STD_ON == DCM_DSP_SECURITY_ATTEMPT_COUNTER_ENABLED) */

		Dcm_SecurityInitStatus.InitState = (boolean)TRUE;

#if(STD_ON == DCM_DSP_SECURITY_ATTEMPT_COUNTER_ENABLED)
	}
#endif /* #if(STD_ON == DCM_DSP_SECURITY_ATTEMPT_COUNTER_ENABLED) */
}

#if(STD_ON == DCM_DSP_SECURITY_ATTEMPT_COUNTER_ENABLED)
STATIC FUNC(void, DCM_CODE)DspInternal_SecurityCancelInitHandle
(
	void
)
{
	uint8 u8Index;
	const Dcm_DspSecurityRowType* pSecurityRow = NULL_PTR;

	while(Dcm_SecurityInitStatus.AlreadyInitNum < DCM_DSP_SECURITY_ROW_NUM)
	{
		u8Index = Dcm_SecurityInitStatus.AlreadyInitNum;
		pSecurityRow = &Dcm_ConfigPtr->DcmDsp->DcmDspSecurityRow[u8Index];

		if((boolean)TRUE == pSecurityRow->DcmDspSecurityAttemptCounterEnabled)
		{
			Dcm_SecurityStatus[u8Index].AttemptCnt = pSecurityRow->DcmDspSecurityNumAttDelay;

			DspInternal_SecurityAttemptCntCheckHandle(u8Index, pSecurityRow);

			/**
			 * @req [SWS_Dcm_01155] The Dcm shall call Xxx_SetSecurityAttemptCounter() when the Dcm
			 * 		has changed the attempt counter to inform the application about the counter change.
			 */
			(void)pSecurityRow->DcmDspSecuritySetAttemptCounterFnc(DCM_INITIAL, Dcm_SecurityStatus[u8Index].AttemptCnt);
		}
		else
		{
			if(0u != pSecurityRow->DcmDspSecurityDelayTimeOnBoot)
			{
				Dcm_SecurityStatus[u8Index].DelayState = (boolean)TRUE;
				Dcm_SecurityStatus[u8Index].TimerEnable = (boolean)TRUE;
				Dcm_SecurityStatus[u8Index].TimeoutTime = pSecurityRow->DcmDspSecurityDelayTimeOnBoot;
			}
		}
		Dcm_SecurityInitStatus.AlreadyInitNum++;
	}
}

STATIC FUNC(void, DCM_CODE)DspInternal_SecurityInitHandle
(
	void
)
{
	uint8 u8Index;
	Std_ReturnType result;
	const Dcm_DspSecurityRowType* pSecurityRow = NULL_PTR;

	Dcm_SecurityInitStatus.CurrentTime += DCM_TASK_TIME;

#if(0u != DCM_DSP_SECURITY_MAX_ATTEMPT_COUNTER_READOUT_TIME)
	if(DCM_DSP_SECURITY_MAX_ATTEMPT_COUNTER_READOUT_TIME <= Dcm_SecurityInitStatus.CurrentTime)
	{
		pSecurityRow = &Dcm_ConfigPtr->DcmDsp->DcmDspSecurityRow[Dcm_SecurityInitStatus.AlreadyInitNum];

		/**
		 * @req [SWS_Dcm_01154] The Dcm shall call Xxx_GetSecurityAttemptCounter() after initialization
		 * 		to restore the attempt counter values.
		 */
		(void)pSecurityRow->DcmDspSecurityGetAttemptCounterFnc(DCM_CANCEL, NULL_PTR);

		DspInternal_SecurityCancelInitHandle();
	}
	else
	{
#endif /* #if(0u != DCM_DSP_SECURITY_MAX_ATTEMPT_COUNTER_READOUT_TIME) */
		while(Dcm_SecurityInitStatus.AlreadyInitNum < DCM_DSP_SECURITY_ROW_NUM)
		{
			u8Index = Dcm_SecurityInitStatus.AlreadyInitNum;
			pSecurityRow = &Dcm_ConfigPtr->DcmDsp->DcmDspSecurityRow[u8Index];

			if((boolean)TRUE == pSecurityRow->DcmDspSecurityAttemptCounterEnabled)
			{
				/**
				 * @req [SWS_Dcm_01154] The Dcm shall call Xxx_GetSecurityAttemptCounter() after
				 * 		initialization to restore the attempt counter values.
				 */
				result = pSecurityRow->DcmDspSecurityGetAttemptCounterFnc(DCM_INITIAL, &Dcm_SecurityStatus[u8Index].AttemptCnt);

				if((Std_ReturnType)E_OK == result)
				{
					Dcm_SecurityInitStatus.AlreadyInitNum++;

					DspInternal_SecurityAttemptCntCheckHandle(u8Index, pSecurityRow);
				}
				else if((Std_ReturnType)E_NOT_OK == result)
				{
					Dcm_SecurityInitStatus.AlreadyInitNum++;

					/**
					 * @req [SWS_Dcm_01156] If Xxx_GetSecurityAttemptCounter() has returned E_NOT_OK the
					 * 		attempt counter shall be assumed as 0.
					 */
					Dcm_SecurityStatus[u8Index].AttemptCnt = 0u;

					/**
					 * @req [SWS_Dcm_01155] The Dcm shall call Xxx_SetSecurityAttemptCounter() when
					 * 		the Dcm has changed the attempt counter to inform the application about the
					 * 		counter change.
					 */
					(void)pSecurityRow->DcmDspSecuritySetAttemptCounterFnc(DCM_INITIAL, 0u);
				}
				else
				{
					/* Result = DCM_E_PENDING. */
					break;
				}
			}
			else
			{
				if(0u != pSecurityRow->DcmDspSecurityDelayTimeOnBoot)
				{
					Dcm_SecurityStatus[u8Index].DelayState = (boolean)TRUE;
					Dcm_SecurityStatus[u8Index].TimerEnable = (boolean)TRUE;
					Dcm_SecurityStatus[u8Index].TimeoutTime = pSecurityRow->DcmDspSecurityDelayTimeOnBoot;
				}

				Dcm_SecurityInitStatus.AlreadyInitNum++;
			}
		}
#if(0u != DCM_DSP_SECURITY_MAX_ATTEMPT_COUNTER_READOUT_TIME)
	}
#endif /* #if(0u != DCM_DSP_SECURITY_MAX_ATTEMPT_COUNTER_READOUT_TIME) */

	if(DCM_DSP_SECURITY_ROW_NUM == Dcm_SecurityInitStatus.AlreadyInitNum)
	{
		Dcm_SecurityInitStatus.CurrentTime = 0u;
		Dcm_SecurityInitStatus.AlreadyInitNum = 0u;
		Dcm_SecurityInitStatus.InitState = (boolean)TRUE;
		Dcm_SecurityInitStatus.TimerEnable = (boolean)FALSE;
	}

	if(DCM_DSP_SECURITY_MAX_ATTEMPT_COUNTER_READOUT_TIME <= Dcm_SecurityInitStatus.CurrentTime)
	{
		pSecurityRow = &Dcm_ConfigPtr->DcmDsp->DcmDspSecurityRow[Dcm_SecurityInitStatus.AlreadyInitNum];

		/**
		 * @req [SWS_Dcm_01154] The Dcm shall call Xxx_GetSecurityAttemptCounter() after initialization
		 * 		to restore the attempt counter values.
		 */
		(void)pSecurityRow->DcmDspSecurityGetAttemptCounterFnc(DCM_CANCEL, NULL_PTR);

		DspInternal_SecurityCancelInitHandle();
	}
	else
	{
		while(Dcm_SecurityInitStatus.AlreadyInitNum < DCM_DSP_SECURITY_ROW_NUM)
		{
			u8Index = Dcm_SecurityInitStatus.AlreadyInitNum;
			pSecurityRow = &Dcm_ConfigPtr->DcmDsp->DcmDspSecurityRow[u8Index];

			if((boolean)TRUE == pSecurityRow->DcmDspSecurityAttemptCounterEnabled)
			{
				/**
				 * @req [SWS_Dcm_01154] The Dcm shall call Xxx_GetSecurityAttemptCounter() after
				 * 		initialization to restore the attempt counter values.
				 */
				result = pSecurityRow->DcmDspSecurityGetAttemptCounterFnc(DCM_INITIAL, &Dcm_SecurityStatus[u8Index].AttemptCnt);

				if((Std_ReturnType)E_OK == result)
				{
					Dcm_SecurityInitStatus.AlreadyInitNum++;

					DspInternal_SecurityAttemptCntCheckHandle(u8Index, pSecurityRow);
				}
				else if((Std_ReturnType)E_NOT_OK == result)
				{
					Dcm_SecurityInitStatus.AlreadyInitNum++;

					/**
					 * @req [SWS_Dcm_01156] If Xxx_GetSecurityAttemptCounter() has returned E_NOT_OK the
					 * 		attempt counter shall be assumed as 0.
					 */
					Dcm_SecurityStatus[u8Index].AttemptCnt = 0u;

					/**
					 * @req [SWS_Dcm_01155] The Dcm shall call Xxx_SetSecurityAttemptCounter() when
					 * 		the Dcm has changed the attempt counter to inform the application about the
					 * 		counter change.
					 */
					(void)pSecurityRow->DcmDspSecuritySetAttemptCounterFnc(DCM_INITIAL, 0u);
				}
				else
				{
					/* Result = DCM_E_PENDING. */
					break;
				}
			}
			else
			{
				if(0u != pSecurityRow->DcmDspSecurityDelayTimeOnBoot)
				{
					Dcm_SecurityStatus[u8Index].DelayState = (boolean)TRUE;
					Dcm_SecurityStatus[u8Index].TimerEnable = (boolean)TRUE;
					Dcm_SecurityStatus[u8Index].TimeoutTime = pSecurityRow->DcmDspSecurityDelayTimeOnBoot;
				}

				Dcm_SecurityInitStatus.AlreadyInitNum++;
			}
		}
	}

	if(DCM_DSP_SECURITY_ROW_NUM == Dcm_SecurityInitStatus.AlreadyInitNum)
	{
		Dcm_SecurityInitStatus.CurrentTime = 0u;
		Dcm_SecurityInitStatus.AlreadyInitNum = 0u;
		Dcm_SecurityInitStatus.InitState = (boolean)TRUE;
		Dcm_SecurityInitStatus.TimerEnable = (boolean)FALSE;
	}
}
#endif /* #if(STD_ON == DCM_DSP_SECURITY_ATTEMPT_COUNTER_ENABLED) */

STATIC FUNC(void, DCM_CODE)DspInternal_SecurityDelayHandle
(
	void
)
{
	uint8 u8Index;
#if(STD_ON == DCM_DSP_SECURITY_ATTEMPT_COUNTER_ENABLED)
	const Dcm_DspSecurityRowType* pSecurityRow = NULL_PTR;
#endif /* #if(STD_ON == DCM_DSP_SECURITY_ATTEMPT_COUNTER_ENABLED) */

	for(u8Index = 0u; u8Index < DCM_DSP_SECURITY_ROW_NUM; u8Index++)
	{
		if((boolean)TRUE == Dcm_SecurityStatus[u8Index].TimerEnable)
		{
			Dcm_SecurityStatus[u8Index].CurrentTime += DCM_TASK_TIME;

			if(Dcm_SecurityStatus[u8Index].TimeoutTime <= Dcm_SecurityStatus[u8Index].CurrentTime)
			{
#if(STD_ON == DCM_DSP_SECURITY_ATTEMPT_COUNTER_DELAY_END_RESET)
				Dcm_SecurityStatus[u8Index].AttemptCnt = 0u;
				Dcm_SecurityStatus[u8Index].CurrentTime = 0u;
				Dcm_SecurityStatus[u8Index].TimeoutTime = 0u;
				Dcm_SecurityStatus[u8Index].TimerEnable = (boolean)FALSE;
				Dcm_SecurityStatus[u8Index].DelayState = (boolean)FALSE;
#else
				if(0u != Dcm_SecurityStatus[u8Index].AttemptCnt)
				{
					Dcm_SecurityStatus[u8Index].AttemptCnt--;
				}
				if(0u == Dcm_SecurityStatus[u8Index].AttemptCnt)
				{
					Dcm_SecurityStatus[u8Index].TimeoutTime = 0u;
					Dcm_SecurityStatus[u8Index].TimerEnable = (boolean)FALSE;
				}
				Dcm_SecurityStatus[u8Index].CurrentTime = 0u;
				Dcm_SecurityStatus[u8Index].DelayState = (boolean)FALSE;
#endif /* #if(STD_ON == DCM_DSP_SECURITY_ATTEMPT_COUNTER_DELAY_END_RESET) */

#if(STD_ON == DCM_DSP_SECURITY_ATTEMPT_COUNTER_ENABLED)
				pSecurityRow = &Dcm_ConfigPtr->DcmDsp->DcmDspSecurityRow[u8Index];
				if((boolean)TRUE == pSecurityRow->DcmDspSecurityAttemptCounterEnabled)
				{
					/**
					 * @req [SWS_Dcm_01155] The Dcm shall call Xxx_SetSecurityAttemptCounter() when
					 * 		the Dcm has changed the attempt counter to inform the application about the
					 * 		counter change.
					 */
					(void)pSecurityRow->DcmDspSecuritySetAttemptCounterFnc(DCM_INITIAL, 0u);
				}
#endif /* #if(STD_ON == DCM_DSP_SECURITY_ATTEMPT_COUNTER_ENABLED) */
			}
		}
	}
}

#if(STD_ON == DCM_DSP_SECURITY_ATTEMPT_COUNTER_ENABLED)
/**
 * @brief			DspInternal_SecurityAttemptCntCheckHandle
 * @details			DSP internal interface, after successfully obtaining the external counter value,
 * 					check if it exceeds the maximum allowed number of times.
 *
 * @param[in]		u8Index:Security index.
 * @param[in]		pSecurityRow:Used security pointer.
 */
STATIC FUNC(void, DCM_CODE)DspInternal_SecurityAttemptCntCheckHandle
(
	uint8 u8Index,
	P2CONST(Dcm_DspSecurityRowType, AUTOMATIC, DCM_CONST)pSecurityRow
)
{
	if(pSecurityRow->DcmDspSecurityNumAttDelay <= Dcm_SecurityStatus[u8Index].AttemptCnt)
	{
		Dcm_SecurityStatus[u8Index].TimeoutTime =\
				(pSecurityRow->DcmDspSecurityDelayTime >\
					pSecurityRow->DcmDspSecurityDelayTimeOnBoot) ?\
						pSecurityRow->DcmDspSecurityDelayTime :\
							pSecurityRow->DcmDspSecurityDelayTimeOnBoot;
		if((uint32)0 != Dcm_SecurityStatus[u8Index].TimeoutTime)
		{
			Dcm_SecurityStatus[u8Index].DelayState = (boolean)TRUE;
			Dcm_SecurityStatus[u8Index].TimerEnable = (boolean)TRUE;
		}
	}
}
#endif /* #if(STD_ON == DCM_DSP_SECURITY_ATTEMPT_COUNTER_ENABLED) */
#endif /* #if(STD_ON == DCM_UDS0x27_ENABLE) */

#if(STD_ON == DCM_UDS0x10_ENABLE)
/**
 * @brief			DspInternal_SessionControlConfirmation
 * @details			After the UDS SessionControl service processing is completed, the Dsp internal
 * 					interface executes the corresponding internal operation.
 */
STATIC FUNC(void, DCM_CODE)DspInternal_SessionControlConfirmation
(
	void
)
{
	const Dcm_DspSessionRowType* pSessionRow = &Dcm_ConfigPtr->DcmDsp->DcmDspSessionRow[Dcm_NewActiveSessionIdx];

	/**
	 * @req [SWS_Dcm_01163] In the context of a request to jump to the bootloader (see [SWS_Dcm_00532]
	 * 		and [SWS_Dcm_00592]), after Dcm_SetProgConditions() returns E_OK according to
	 * 		[SWS_Dcm_00535], the Dcm shall trigger the mode switch of the ModeDeclarationGroupPrototype
	 * 		DcmEcuReset to EXECUTE.
	 */
	 if((DCM_PROGRAMMING_SESSION == pSessionRow->DcmDspSessionLevel) && (DCM_NO_BOOT != pSessionRow->DcmDspSessionForBoot))
	 {
//			SchM_Switch_DcmEcuReset(RTE_MODE_DcmEcuReset_EXECUTE);
//		 	uint32 appValFlagData = 0x95279527U;
//			EE_WriteRecord(&eeConf,EE_BLOCK_FINGER_AppValFlag,4,&appValFlagData,0,NULL);//升级标志位
//			Mcu_PerformReset();
	 }
	 else
	 {
	 	DslInternal_SetSesCtrlType(Dcm_NewActiveSession);
	 }
}
#endif /* #if(STD_ON == DCM_UDS0x10_ENABLE) */

#if(STD_ON == DCM_UDS0x11_ENABLE)
/**
 * @brief			DspInternal_EcuResetConfirmation
 * @details			After the UDS EcuReset service processing is completed, the Dsp internal interface
 * 					executes the corresponding internal operation.
 */
STATIC FUNC(void, DCM_CODE)DspInternal_EcuResetConfirmation
(
	void
)
{
	/**
	 * @req [SWS_Dcm_00594] On the transmit confirmation (call to Dcm_TpTxConfirmation) of the positive
	 * 		response, the DCM module shall trigger the mode switch of ModeDeclarationGroupPrototype
	 * 		DcmEcuReset to the mode EXECUTE
	 * 		(via SchM_Switch_<bsnp>_DcmEcuReset(RTE_MODE_DcmEcuReset_EXECUTE)).
	 *
	 * @req [SWS_Dcm_00834] After sending the positive response of EcuReset (call of
	 * 		Dcm_TpTxConfirmation) the DCM shall ignore all further requests during resetprocessing.
	 */
	SchM_Switch_DcmEcuReset(RTE_MODE_DcmEcuReset_EXECUTE);
}
#endif /* #if(STD_ON == DCM_UDS0x11_ENABLE) */

#if(STD_ON == DCM_UDS0x27_ENABLE)
/**
 * @brief			DspInternal_SecurityAccessConfirmation
 * @details			After the UDS SecurityAccess service processing is completed, the Dsp internal
 * 					interface executes the corresponding internal operation.
 */
STATIC FUNC(void, DCM_CODE)DspInternal_SecurityAccessConfirmation
(
	void
)
{
	/**
	 * @req [SWS_Dcm_00325] If the operation CompareKey()returns E_OK, the DSP submodule shall set the
	 * 		new access type with DslInternal_SetSecurityLevel()(see the conversion formula given in
	 * 		[SWS_Dcm_00754]).
	 */
	if(!DCM_CHECK_BIT_SET(Dcm_MsgContext[Dcm_ActiveProRowIdx].ReqData[1], 0u, uint8))
	{
		DslInternal_SetSecurityLevel(Dcm_NewActiveSecurity);
	}
}
#endif /* #if(STD_ON == DCM_UDS0x27_ENABLE) */

#if(0u != DCM_DSP_DATA_BLOCK_USED_NUM)
/**
 * @brief			DspInternal_ReadBlockInit
 * @details			DSP internal interface, Read all NV-block during initialization.
 */
STATIC FUNC(void, DCM_CODE)DspInternal_ReadBlockInit
(
	void
)
{
	uint8 u8Index;
	Dcm_DspDataReadBlockType* pDataReadBlock = NULL_PTR;

	for(u8Index = 0u; u8Index < DCM_DSP_DATA_BLOCK_USED_NUM; u8Index++)
	{
		pDataReadBlock = &Dcm_ConfigPtr->DcmDspDataReadBlock[u8Index];

		(void)NvM_ReadBlock(\
				pDataReadBlock->DcmDspDataReadBlockIdRef, pDataReadBlock->DcmDspDataReadInternalBuffer\
				);
	}
}
#endif /* #if(0u != DCM_DSP_DATA_BLOCK_USED_NUM) */

/**
 * @brief			DspInternal_ResetServiceSetState
 * @details			DSP internal interface, after switching the session mode, check and reconfigure the
 * 					service's set status.
 *
 * @param[in]		sesCtrlType:Session mode to switch to.
 * @param[in]		newSesIdx:Index of the session mode to switch to.
 *
 */
STATIC FUNC(void, DCM_CODE)DspInternal_ResetServiceSetState
(
	Dcm_SesCtrlType sesCtrlType,
	Dcm_SessionDataType newSesIdx
)
{
#if((STD_ON == DCM_UDS0x28_ENABLE) || (STD_ON == DCM_UDS0x2A_ENABLE) || (STD_ON == DCM_UDS0x85_ENABLE))

	uint8 u8ILoop;
#if((STD_ON == DCM_UDS0x2C_ENABLE) && (STD_ON == DCM_DSP_DDDID_CHECK_PER_SOURCE_DID))
	uint8 u8JLoop;
	Dcm_DDDIdElementStatus* pElementStatus = NULL_PTR;
#endif /* #if((STD_ON == DCM_UDS0x2C_ENABLE) && (STD_ON == DCM_DSP_DDDID_CHECK_PER_SOURCE_DID)) */

#if(STD_ON == DCM_UDS0x2A_ENABLE)
	Dcm_SchedulerTableType* pScheduler = NULL_PTR;
#endif /* #if(STD_ON == DCM_UDS0x2A_ENABLE) */

#if(STD_ON == DCM_UDS0x28_ENABLE)
	if((DCM_DEFAULT_SESSION == sesCtrlType) ||\
		(!DCM_CHECK_BIT_SET(Dcm_ConfigPtr->DcmDsd->DcmDsdUDS0x28SesRef, newSesIdx, uint8)))
	{
		/**
		 * @req [SWS_Dcm_00860] For a NetworkHandle which is currently in a state other than
		 * 		DCM_ENABLE_RX_TX_NORM_NM if the Dcm is transitioning to default session or upon any
		 * 		diagnostic session change where the new session does not support UDS Service
		 * 		CommunicationControl anymore, the Dcm shall:
		 * 		1. switch the mode group Dcm_CommunicationControl_<Network>
		 * 		   ModeDeclarationGroupPrototype to DCM_ENABLE_RX_TX_NORM_NM.
		 * 		2. call BswM_Dcm_CommunicationMode_CurrentState with the parameters NetworkHandleType
		 * 		   set to the corresponding NetworkHandle of the network and RequestedCommunicationMode
		 * 		   set to DCM_ENABLE_RX_TX_NORM_NM.
		 */
		for(u8ILoop = 0u; u8ILoop < 32u; u8ILoop++)
		{
			if(DCM_CHECK_BIT_SET(Dcm_CommunicationState, u8ILoop, uint32))
			{
				BswM_Dcm_CommunicationMode_CurrentState(u8ILoop, DCM_ENABLE_RX_TX_NORM_NM);

				DCM_BIT_CLEAR(Dcm_CommunicationState, u8ILoop, uint32);
			}
		}
	}
#endif /* #if(STD_ON == DCM_UDS0x28_ENABLE) */

#if(STD_ON == DCM_UDS0x2A_ENABLE)
	if(DCM_DEFAULT_SESSION == sesCtrlType)
	{
		/**
		 * @req [SWS_Dcm_01107] When the diagnostic session changes to DefaultSession, any scheduled
		 * 		periodic DID shall be stopped (see [SWS_Dcm_01113], [SWS_Dcm_01114], [SWS_Dcm_01115],
		 * 		[SWS_Dcm_01116], [SWS_Dcm_01117] and [SWS_Dcm_01118]).
		 */
		Dcm_PeriodicTransStatus.PDidNum = 0u;
	}
	else
	{
		/**
		 * @req [SWS_Dcm_01108] When the diagnostic session changes to a non-defaultSession, any
		 * 		scheduled periodic DID that was restricted by security access shall be stopped (see
		 * 		[SWS_Dcm_01113], [SWS_Dcm_01114], [SWS_Dcm_01115], [SWS_Dcm_01116], [SWS_Dcm_01117]
		 * 		and [SWS_Dcm_01118]).
		 *
		 * @req [SWS_Dcm_01109] When the diagnostic session changes to a non-defaultSession, any
		 * 		scheduled periodic DID that is not supported in the new session shall be stopped (see
		 * 		[SWS_Dcm_01113], [SWS_Dcm_01114], [SWS_Dcm_01115], [SWS_Dcm_01116], [SWS_Dcm_01117] and
		 * 		[SWS_Dcm_01118]).
		 *
		 * @req [SWS_Dcm_01111] On any Session change, the Dcm shall stop any scheduled periodic DDDID
		 * 		(see [SWS_Dcm_01114], [SWS_Dcm_01116], [SWS_Dcm_01117] and [SWS_Dcm_01118]), that
		 * 		contains source data, not supported in the current session or requires security access,
		 * 		in case the configuration parameter DcmDspDDDIDcheckPerSourceDID is set to TRUE.
		 */
		for(u8ILoop = 0u; u8ILoop < Dcm_PeriodicTransStatus.PDidNum;)
		{
			pScheduler = &Dcm_PeriodicTransStatus.SchedulerTable[u8ILoop];

			if((0u != pScheduler->SecLevelRef) ||\
				(!DCM_CHECK_BIT_SET(pScheduler->SesLevelRef, newSesIdx, Dcm_SessionDataType)))
			{
				DspInternal_DeletePeriodicDid(u8ILoop);
			}
#if((STD_ON == DCM_UDS0x2C_ENABLE) && (STD_ON == DCM_DSP_DDDID_CHECK_PER_SOURCE_DID))
			else if(0x03u == pScheduler->PDidType)
			{
				for(u8JLoop = 0u; u8JLoop < Dcm_DDDidStatus[pScheduler->PDDDidIndex].ElementNum; u8JLoop++)
				{
					pElementStatus = &Dcm_DDDidStatus[pScheduler->PDDDidIndex].ElementStatus[u8JLoop];

					if(!DCM_CHECK_BIT_SET(pElementStatus->SesLevelRef, newSesIdx, Dcm_SessionDataType))
					{
						DspInternal_DeletePeriodicDid(u8ILoop);

						break;
					}
				}
				if(Dcm_DDDidStatus[pScheduler->PDDDidIndex].ElementNum == u8JLoop)
				{
					u8ILoop++;
				}
			}
#endif /* #if((STD_ON == DCM_UDS0x2C_ENABLE) && (STD_ON == DCM_DSP_DDDID_CHECK_PER_SOURCE_DID)) */
			else
			{
				u8ILoop++;
			}
		}
	}
#endif /* #if(STD_ON == DCM_UDS0x2A_ENABLE) */

#if(STD_ON == DCM_UDS0x85_ENABLE)
	if(((boolean)TRUE == Dcm_DisableDTCState) && ((DCM_DEFAULT_SESSION == sesCtrlType) ||\
		(!DCM_CHECK_BIT_SET(Dcm_ConfigPtr->DcmDsd->DcmDsdUDS0x85SesRef, newSesIdx, Dcm_SessionDataType))))
	{
		/**
		 * @req [SWS_Dcm_00751] In case the DTCSetting is disabled and a transitions to default session
		 * 		or upon any diagnostic session change where the new session does not support UDS Service
		 * 		ControlDTCsetting anymore, the Dcm module shall call Dem_EnableDTCSetting() with the
		 * 		following parameters ClientId: Client Id for this Dcm instance (see DcmDemClientRef) and
		 * 		switch the mode DcmControlDTCSetting to DCM_ENABLEDTCSETTING.
		 */
		(void)Dem_DcmEnableDTCSetting(DEM_DTC_GROUP_ALL_DTCS, DEM_DTC_KIND_ALL_DTCS);
	}
#endif /* #if(STD_ON == DCM_UDS0x85_ENABLE) */

#else
	(void)sesCtrlType;
	(void)newSesIdx;
#endif /* #if((STD_ON == DCM_UDS0x28_ENABLE) || (STD_ON == DCM_UDS0x2A_ENABLE) || (STD_ON == DCM_UDS0x85_ENABLE)) */
}

#if(STD_ON == DCM_UDS0x2A_ENABLE)
#if(STD_ON == DCM_DSP_DATA_READ_FNC_ENABLED)
/**
 * @brief			DspInternal_PeriodicTransGetData
 * @details			DSP internal interface, acquiring the PDid data during the periodic transmission
 * 					process.
 *
 * @param[in]		pScheduler:Pointer to the PDid information.
 *
 * @return     		Result of this operation.
 * @retval			E_OK:Processing successfully.
 * @retval			E_NOT_OK:Processing not successfully.
 */
STATIC FUNC(Std_ReturnType, DCM_CODE)DspInternal_PeriodicTransGetData
(
	uint8 u8DidIndex,
	P2VAR(uint16, AUTOMATIC, DCM_VAR)pBufOffset,
	P2VAR(uint8, AUTOMATIC, DCM_VAR)pDataBuffer,
	P2CONST(Dcm_SchedulerTableType, AUTOMATIC, DCM_CONST)pScheduler
)
{
	Std_ReturnType result = (Std_ReturnType)E_NOT_OK;

	uint8 u8Index;
	const Dcm_DspDataType* pSignalData = NULL_PTR;
	const Dcm_DspDidSignalType* pSignal = NULL_PTR;
	const Dcm_DspDidType* pDid = &Dcm_ConfigPtr->DcmDsp->DcmDspDid[u8DidIndex];

	/**
	 * @req [SWS_Dcm_01105] After the periodicDIDs are started, initial request was responded
	 * 		positively, no negative response will be sent for those periodicDID's (when periodically
	 * 		triggered).
	 */

	for(u8Index = 0u; u8Index < pDid->DcmDspDidSignalNum; u8Index++)
	{
		pSignal = &pDid->DcmDspDidSignal[u8Index];

		pSignalData = pSignal->DcmDspDidDataRef;

		/**
		 * @req [SWS_Dcm_01106] Each time the counter of a periodicDataIdentifiers elapses, the Dcm
		 * 		shall retrieve the data via the ReadData operation (or respective C-Function) without
		 * 		validating the other conditions (i.e. session, security, mode dependencies,
		 * 		ConditionCheckRead and ReadDataLength).
		 */
		if(NULL_PTR != pSignalData->DcmDspDataReadFnc)
		{
			result = pSignalData->DcmDspDataReadFnc(\
						DCM_INITIAL, &pDataBuffer[(pSignal->DcmDspDidDataPos / 8u)], NULL_PTR\
						);
		}

		if((Std_ReturnType)E_OK == result)
		{
#if(STD_ON == DCM_DSP_DATA_READ_DATA_LENGTH_FNC_ENABLED)
			if(DCM_UINT8_DYN == pSignalData->DcmDspDataType)
			{
				*pBufOffset += pScheduler->DynDataLen;
			}
			else
			{
#endif /* #if(STD_ON == DCM_DSP_DATA_READ_DATA_LENGTH_FNC_ENABLED) */

				*pBufOffset += (pSignalData->DcmDspDataSize) / 8u;

#if(STD_ON == DCM_DSP_DATA_READ_DATA_LENGTH_FNC_ENABLED)
			}
#endif /* #if(STD_ON == DCM_DSP_DATA_READ_DATA_LENGTH_FNC_ENABLED) */
		}
		else
		{
			/**
			 * @req [SWS_Dcm_01115] On a static periodic DID stop event, after the asynchronous call of
			 * 		its data service port has already been initiated (i.e. its "ReadData" port operation
			 * 		already returned E_PENDING), the corresponding service port shall be immediately
			 * 		aborted by signaling OpStatus=DCM_CANCEL.
			 */
			if((Std_ReturnType)DCM_E_PENDING == result)
			{
				(void)pSignalData->DcmDspDataReadFnc(DCM_CANCEL, NULL_PTR, NULL_PTR);

				result = (Std_ReturnType)E_NOT_OK;
			}

			break;
		}
	}

	return result;
}
#endif /* #if(STD_ON == DCM_DSP_DATA_READ_FNC_ENABLED) */

/**
 * @brief			DspInternal_PeriodicTransProcess
 * @details			DSP internal interface, acquiring the PDid data during the periodic transmission
 * 					process.
 *
 * @param[in]		pScheduler:Pointer to the PDid information.
 *
 * @return     		Result of this operation.
 * @retval			E_OK:Processing successfully.
 * @retval			E_NOT_OK:Processing not successfully.
 */
STATIC FUNC(Std_ReturnType, DCM_CODE)DspInternal_PeriodicTransProcess
(
	P2VAR(Dcm_SchedulerTableType, AUTOMATIC, DCM_VAR)pScheduler
)
#if(STD_ON == DCM_UDS0x2C_ENABLE)
{
	Std_ReturnType result = (Std_ReturnType)E_NOT_OK;

	uint16 u16BufOffset = 1u;
	uint8* pDataBuffer = &pScheduler->DidData[u16BufOffset];

#if((STD_ON == DCM_UDS0x2C_SUB0x01_ENABLE) || (STD_ON == DCM_UDS0x2C_SUB0x02_ENABLE))
	uint8 u8Index;
	Dcm_DDDIdElementStatus* pElementStatus = NULL_PTR;
#if(STD_ON == DCM_UDS0x2C_SUB0x02_ENABLE)
	Dcm_ReturnReadMemoryType callRet = DCM_READ_FAILED;
#endif /* #if(STD_ON == DCM_UDS0x2C_SUB0x02_ENABLE) */
#endif /* #if((STD_ON == DCM_UDS0x2C_SUB0x01_ENABLE) || (STD_ON == DCM_UDS0x2C_SUB0x02_ENABLE)) */

#if((STD_ON == DCM_UDS0x2C_SUB0x01_ENABLE) || (STD_ON == DCM_UDS0x2C_SUB0x02_ENABLE))
	if(0x01u == pScheduler->PDidType)
	{
#endif /* #if((STD_ON == DCM_UDS0x2C_SUB0x01_ENABLE) || (STD_ON == DCM_UDS0x2C_SUB0x02_ENABLE)) */
#if(STD_ON == DCM_DSP_DATA_READ_FNC_ENABLED)
		result = DspInternal_PeriodicTransGetData(\
						pScheduler->PDidIndex, &u16BufOffset, pDataBuffer, pScheduler\
						);
#else
		(void)u16BufOffset;
		(void)pDataBuffer;
#endif /* #if(STD_ON == DCM_DSP_DATA_READ_FNC_ENABLED) */
#if((STD_ON == DCM_UDS0x2C_SUB0x01_ENABLE) || (STD_ON == DCM_UDS0x2C_SUB0x02_ENABLE))
	}
	else
	{
		for(u8Index = 0u; u8Index < Dcm_DDDidStatus[pScheduler->PDDDidIndex].ElementNum; u8Index++)
		{
			pDataBuffer = &pScheduler->DidData[u16BufOffset];

			pElementStatus = &Dcm_DDDidStatus[pScheduler->PDDDidIndex].ElementStatus[u8Index];

#if((STD_ON == DCM_UDS0x2C_SUB0x01_ENABLE) && (STD_ON == DCM_UDS0x2C_SUB0x02_ENABLE))
			if((boolean)TRUE == pElementStatus->IsDidType)
			{
#if(STD_ON == DCM_DSP_DATA_READ_FNC_ENABLED)
				result = DspInternal_PeriodicTransGetData(\
								pElementStatus->Element.SrcDid.SrcDidIndex, &u16BufOffset, pDataBuffer, pScheduler\
								);
#else
				;
#endif /* #if(STD_ON == DCM_DSP_DATA_READ_FNC_ENABLED) */
			}
			else
			{
				callRet = Dcm_ReadMemory(DCM_INITIAL,\
								pElementStatus->Element.Memory.MemoryId,\
								pElementStatus->Element.Memory.MemoryAddress,\
								pElementStatus->Element.Memory.MemorySize,\
								pDataBuffer, NULL_PTR\
								);
				/**
				 * @req [SWS_Dcm_01116] On a dynamically defined periodic DID stop event, after the
				 * 		asynchronous call of its source data service port/callout has already been
				 * 		initiated (e.g. a "ReadMemory" callout already returned DCM_READ_PENDING), the
				 * 		corresponding service port/callout shall be immediately aborted by signaling
				 * 		OpStatus=DCM_CANCEL.
				 */
				switch(callRet)
				{
				case DCM_READ_OK:
					result = (Std_ReturnType)E_OK;
					break;
				case DCM_READ_PENDING:
				case DCM_READ_FORCE_RCRRP:
					(void)Dcm_ReadMemory(DCM_CANCEL,\
								pElementStatus->Element.Memory.MemoryId,\
								pElementStatus->Element.Memory.MemoryAddress,\
								pElementStatus->Element.Memory.MemorySize,\
								NULL_PTR, NULL_PTR\
								);
					result = (Std_ReturnType)E_NOT_OK;
					break;
				default:
					result = (Std_ReturnType)E_NOT_OK;
					break;
				}
			}
#elif(STD_ON == DCM_UDS0x2C_SUB0x01_ENABLE)
#if(STD_ON == DCM_DSP_DATA_READ_FNC_ENABLED)
			result = DspInternal_PeriodicTransGetData(\
							pElementStatus->Element.SrcDid.SrcDidIndex, &u16BufOffset, pDataBuffer, pScheduler\
							);
#else
			(void)u16BufOffset;
			(void)pDataBuffer;
#endif /* #if(STD_ON == DCM_DSP_DATA_READ_FNC_ENABLED) */
#else
			callRet = Dcm_ReadMemory(DCM_INITIAL,\
							pElementStatus->Element.Memory.MemoryId,\
							pElementStatus->Element.Memory.MemoryAddress,\
							pElementStatus->Element.Memory.MemorySize,\
							pDataBuffer, NULL_PTR\
							);
			/**
			 * @req [SWS_Dcm_01116] On a dynamically defined periodic DID stop event, after the
			 * 		asynchronous call of its source data service port/callout has already been
			 * 		initiated (e.g. a "ReadMemory" callout already returned DCM_READ_PENDING), the
			 * 		corresponding service port/callout shall be immediately aborted by signaling
			 * 		OpStatus=DCM_CANCEL.
			 */
			switch(callRet)
			{
			case DCM_READ_OK:
				result = (Std_ReturnType)E_OK;
				break;
			case DCM_READ_PENDING:
			case DCM_READ_FORCE_RCRRP:
				(void)Dcm_ReadMemory(DCM_CANCEL,\
							pElementStatus->Element.Memory.MemoryId,\
							pElementStatus->Element.Memory.MemoryAddress,\
							pElementStatus->Element.Memory.MemorySize,\
							NULL_PTR, NULL_PTR\
							);
				result = (Std_ReturnType)E_NOT_OK;
				break;
			default:
				result = (Std_ReturnType)E_NOT_OK;
				break;
			}
#endif /* #if((STD_ON == DCM_UDS0x2C_SUB0x01_ENABLE) && (STD_ON == DCM_UDS0x2C_SUB0x02_ENABLE)) */

			if((Std_ReturnType)E_OK != result)
			{
				break;
			}
		}
	}
#endif /* #if((STD_ON == DCM_UDS0x2C_SUB0x01_ENABLE) || (STD_ON == DCM_UDS0x2C_SUB0x02_ENABLE)) */

	return result;
}
#else
{
	Std_ReturnType result = (Std_ReturnType)E_NOT_OK;

#if(STD_ON == DCM_DSP_DATA_READ_FNC_ENABLED)
	uint16 u16BufOffset = 1u;
	uint8* pDataBuffer = &pScheduler->DidData[u16BufOffset];

	result = DspInternal_PeriodicTransGetData(\
					pScheduler->PDidIndex, &u16BufOffset, pDataBuffer, pScheduler\
					);
#endif /* #if(STD_ON == DCM_DSP_DATA_READ_FNC_ENABLED) */

	return result;
}
#endif /* #if(STD_ON == DCM_UDS0x2C_ENABLE) */

/**
 * @brief			DspInternal_ReSortSchedulerTable
 * @details			DSP internal interface, rearrange the scheduler table by moving untransmitted PDIDs.
 *
 * @param[in]		u8SchedulerIndex:Index that needs to be moved.
 */
STATIC FUNC(void, DCM_CODE)DspInternal_ReSortSchedulerTable
(
	uint8 u8SchedulerIndex
)
{
	uint8 u8Index;
	uint8 u8InsertIndex = Dcm_PeriodicTransStatus.PDidInsertIndex;
	Dcm_SchedulerTableType Scheduler = Dcm_PeriodicTransStatus.SchedulerTable[u8SchedulerIndex];

	/**
	 * @req [SWS_Dcm_01104] In case of multiple configured UUDT messages, the Dcm shall use always the
	 * 		same order of periodicDIDs per client. Transmission errors shall not influence this order,
	 * 		the Dcm shall continue to retry the transmission. The Dcm shall consider the priority
	 * 		inversion of message transmission as well.
	 */

	if(u8SchedulerIndex != u8InsertIndex)
	{
		if(u8SchedulerIndex > u8InsertIndex)
		{
			for(u8Index = u8SchedulerIndex; u8Index > u8InsertIndex; u8Index--)
			{
				Dcm_PeriodicTransStatus.SchedulerTable[u8Index] = Dcm_PeriodicTransStatus.SchedulerTable[u8Index - 1u];
			}
		}
		else
		{
			for(u8Index = u8SchedulerIndex; u8Index < u8InsertIndex; u8Index++)
			{
				Dcm_PeriodicTransStatus.SchedulerTable[u8Index] = Dcm_PeriodicTransStatus.SchedulerTable[u8Index + 1u];
			}
		}

		Dcm_PeriodicTransStatus.SchedulerTable[u8InsertIndex] = Scheduler;

		if(Dcm_PeriodicTransStatus.PDidNum == u8InsertIndex)
		{
			Dcm_PeriodicTransStatus.PDidInsertIndex = 0u;
		}
		else
		{
			Dcm_PeriodicTransStatus.PDidInsertIndex++;
		}
	}
}
#endif /* #if(STD_ON == DCM_UDS0x2A_ENABLE) */

/**
 * @brief			DspInternal_GeneralCheck
 * @details			DSP internal interface, check whether the service to be processed is valid,
 * 					and whether the session mode and security level required by the service meet the
 * 					requirements.
 *
 * @param[in]		pProtocolRow:Used protocol pointer.
 * @param[in]		u8Sid:Service identifier.
 *
 * @param[out]		pServiceIdx:Returns the service index.
 *
 * @return     		Result of this operation.
 * @retval			E_OK:Check successful.
 * @retval			E_NOT_OK:Check failed.
 */
STATIC FUNC(Std_ReturnType, DCM_CODE)DspInternal_GeneralCheck
(
	uint8 u8Sid,
	Dcm_DslProtocolRxAddrType addrType,
	P2VAR(uint8, AUTOMATIC, DCM_VAR)pServiceIdx,
	P2CONST(Dcm_DslProtocolRowType, AUTOMATIC, DCM_CONST)pProtocolRow
)
{
	Std_ReturnType result = (Std_ReturnType)E_NOT_OK;

	uint8 u8Index;
	const Dcm_DsdServiceTableType* pServiceTable = pProtocolRow->DcmDslProtocolSIDTable;
	const Dcm_DsdServiceType* pService = NULL_PTR;

	/**
	 * @req [SWS_Dcm_00193] During this check, the DSD submodule shall search the newly received
	 * 		diagnostic service identifier in the "Service Identifier Table".
	 *
	 * @req [SWS_Dcm_00195] The DSL submodule shall provide the current "Service Identifier Table".
	 */
	for(u8Index = 0u; u8Index < pServiceTable->DcmServiceNum; u8Index++)
	{
		pService = &pServiceTable->DcmDsdService[u8Index];

		if(u8Sid == pService->DcmDsdSidTabServiceId)
		{
			/**
			 * @req [SWS_Dcm_00197] If the newly received diagnostic service identifier is not
			 * 		supported, the DSD submodule shall transmit a negative response with NRC 0x11
			 * 		(Service not supported) to the DSL submodule.
			 */
			if(((boolean)TRUE != pService->DcmDsdServiceUsed) ||\
				((addrType != pService->DcmDsdServiceRxAddrType) &&\
				(DCM_FUNCTIONAL_PHYSICAL_TYPE != pService->DcmDsdServiceRxAddrType)))
			{
				Dcm_ConnectionStatus[Dcm_ActiveConIdx].NRC = DCM_E_SERVICENOTSUPPORTED;
			}
			else
			{
				result = DspInternal_PermissionCheck(\
							pServiceTable->DcmDsdService[u8Index].DcmDsdSidTabSessionLevelRef,\
							pServiceTable->DcmDsdService[u8Index].DcmDsdSidTabSecurityLevelRef,\
							DCM_PERMISSION_CHECK_USER_SERVICE,\
							&Dcm_ConnectionStatus[Dcm_ActiveConIdx].NRC\
							);

#if(STD_ON == DCM_DSD_SERVICE_CONDITION_CHECK_FNC_USED)
				if(((Std_ReturnType)E_OK == result) && (NULL_PTR != pService->DcmDsdServiceConditionCheckFnc))
				{
					result = pService->DcmDsdServiceConditionCheckFnc(\
								&Dcm_ConnectionStatus[Dcm_ActiveConIdx].NRC\
								);
				}
#endif /* #if(STD_ON == DCM_DSD_SERVICE_CONDITION_CHECK_FNC_USED) */
			}

			*pServiceIdx = u8Index;

			break;
		}
	}
	if(u8Index == pServiceTable->DcmServiceNum)
	{
		Dcm_ConnectionStatus[Dcm_ActiveConIdx].NRC = DCM_E_SERVICENOTSUPPORTED;
	}

	return result;
}
/*====================================================================================================*
 *                                          GLOBAL FUNCTIONS
 *====================================================================================================*/
/**
 * @brief			DslInternal_InitInternalStatus
 * @details			Called during module initialization to initialize the internal status of all
 * 					protocols and connections.
 */
FUNC(void, DCM_CODE)DslInternal_InitInternalStatus
(
	void
)
{
	uint8 u8Index;

	/* No active protocol and connection currently exist. */
	Dcm_ActiveConIdx = 0xFFu;
	Dcm_ActiveProRowIdx = 0xFFu;

	for(u8Index = 0u; u8Index < DCM_DSL_PROTOCOLROW_NUM; u8Index++)
	{
		Dcm_MsgContext[u8Index].DcmRxPduId = 0xFFFFu;
		Dcm_MsgContext[u8Index].MsgAddInfo = 0u;
		Dcm_MsgContext[u8Index].ReqData = NULL_PTR;
		Dcm_MsgContext[u8Index].ReqDataLen = 0u;
		Dcm_MsgContext[u8Index].ResData = NULL_PTR;
		Dcm_MsgContext[u8Index].ResDataLen = 0u;
		Dcm_MsgContext[u8Index].ResMaxDataLen = 0u;
	}

	/**
	 * @req [SWS_Dcm_01069] After Dcm_Init(), the Dcm shall set ActiveDiagnostic to "DCM_COMM_ACTIVE".
	 */
	for(u8Index = 0u; u8Index < DCM_DSL_MAIN_CONNECTION_NUM; u8Index++)
	{
		Dcm_ComMStatus[u8Index].DiagnosticState = DCM_COMM_ACTIVE;
		Dcm_ComMStatus[u8Index].CommunicationState = DCM_COMM_NO_COMMUNICATION;

		Dcm_ConnectionStatus[u8Index].ServiceFnc = NULL_PTR;
		Dcm_ConnectionStatus[u8Index].ServiceId = 0xFFu;
		Dcm_ConnectionStatus[u8Index].ServiceIdx = 0xFFu;
		Dcm_ConnectionStatus[u8Index].RxState = DCM_RX_STATE_IDLE;
		Dcm_ConnectionStatus[u8Index].TxState = DCM_TX_STATE_IDLE;
		Dcm_ConnectionStatus[u8Index].RemainLen = 0u;
		Dcm_ConnectionStatus[u8Index].CopyOffset = 0u;
		Dcm_ConnectionStatus[u8Index].Concurrent3E = (boolean)FALSE;
		Dcm_ConnectionStatus[u8Index].NRC = 0xFFu;
	}

	/**
	 * @req [SWS_Dcm_00034] During DCM initialization, the session state is set to the value 0x01
	 * 		(DefaultSession).
	 */
	Dcm_ActiveSession = DCM_DEFAULT_SESSION;
	Dcm_ActiveSessionIdx = DCM_DSP_DEFAULT_SESSION_ROW_IDX;

	/**
	 * @req [SWS_Dcm_00033] During DCM initialization the security level is set to the value 0x00
	 * 		(DCM_SEC_LEV_LOCKED).
	 */
	Dcm_ActiveSecurity = DCM_SEC_LEV_LOCKED;
	Dcm_ActiveSecurityIdx = (Dcm_SecurityDataType)(~0u);

#if(0u != DCM_DSP_DATA_BLOCK_USED_NUM)
	DspInternal_ReadBlockInit();
#endif /* #if(0u != DCM_DSP_DATA_BLOCK_USED_NUM) */

#if(STD_ON == DCM_UDS0x27_ENABLE)
	DspInternal_SecurityInit();
#endif /* #if(STD_ON == DCM_UDS0x27_ENABLE) */

#if(STD_ON == DCM_UDS0x2A_ENABLE)
	Dcm_PeriodicTransStatus.PDidNum = 0u;
	Dcm_PeriodicTransStatus.ChannelStatus = 0u;
	Dcm_PeriodicTransStatus.PDidInsertIndex = 0u;
#endif /* #if(STD_ON == DCM_UDS0x2A_ENABLE) */

#if(STD_ON == DCM_UDS0x2C_ENABLE)
#if(STD_OFF == DCM_DDDID_STORAGE)
	/**
	 * @req [SWS_Dcm_00866] If DcmDDDIDStorage configuration parameter is set to FALSE, the DCM shall
	 * 		initialize all DDDIDs as not present at power-up (Dcm_Init).
	 */
	DspInternal_DDDidStatusInit(0xFFu);
#else
	/**
	 * @req [SWS_Dcm_00867] If DcmDDDIDStorage configuration parameter is set to TRUE, the DCM shall
	 * 		restore the DDDID definition from NvM at power-up (Dcm_Init).
	 */
	/* Call NvM_ReadAll() at Power-Up. */
#endif /* #if(STD_OFF == DCM_DDDID_STORAGE) */
#endif /* #if(STD_ON == DCM_UDS0x2C_ENABLE) */

#if((STD_ON == DCM_UDS0x34_ENABLE) || (STD_ON == DCM_UDS0x35_ENABLE))
	DspInternal_TransferInit();
#endif /* #if((STD_ON == DCM_UDS0x34_ENABLE) || (STD_ON == DCM_UDS0x35_ENABLE)) */

	/**
	 * @req [SWS_Dcm_00027] The DCM module shall handle the following protocol timing parameters in
	 * 		compliance with [18]: P2ServerMin, P2ServerMax, P2*ServerMin, P2*ServerMax, S3Server.
	 *
	 * @req [SWS_Dcm_00143] P2min / P2*min and S3Server shall be set to defined values: P2min = 0ms,
	 * 		P2*min = 0ms, S3Server = 5s.
	 */

	/* Initialize the S3 timer status. */
	Dcm_S3TimerStatus.CurrentTime = 0u;
	Dcm_S3TimerStatus.TimerEnable = (boolean)FALSE;

	/* Initialize the P2 timer status. */
	Dcm_P2TimerStatus.CurrentTime = 0u;
	Dcm_P2TimerStatus.TimeoutTime = 0u;
#if(STD_ON == DCM_DSP_SESSION_TIM_P2_PENDING_WINDOW)
	Dcm_P2TimerStatus.PendingThreshold = 0u;
#endif /* #if(STD_ON == DCM_DSP_SESSION_TIM_P2_PENDING_WINDOW) */
	Dcm_P2TimerStatus.TimerEnable = (boolean)FALSE;

#if(0u != DCM_DSL_DIAG_RESP_MAX_NUM_RESP_PEND)
	/* Initialize the P2* timer status. */
	Dcm_P2StarTimerStatus.PendingCnt = 0u;
	Dcm_P2StarTimerStatus.CurrentTime = 0u;
	Dcm_P2StarTimerStatus.TimeoutTime = 0u;
	Dcm_P2StarTimerStatus.TimerEnable = (boolean)FALSE;
	Dcm_P2StarTimerStatus.PendingNRCSendState = (boolean)TRUE;
	Dcm_P2StarTimerStatus.PendingProcessState = (boolean)FALSE;
#endif /* #if(0u != DCM_DSL_DIAG_RESP_MAX_NUM_RESP_PEND) */

#if((STD_ON == DCM_DSD_SERVICE_P4_TIMER_ENABLE) || (STD_ON == DCM_DSD_SUB_SERVICE_P4_TIMER_ENABLE))
	/* Initialize the P4 timer status. */
	Dcm_P4TimerStatus.CurrentTime = 0u;
	Dcm_P4TimerStatus.TimeoutTime = 0u;
	Dcm_P4TimerStatus.TimerEnable = (boolean)FALSE;
#endif /* #if((STD_ON == DCM_DSD_SERVICE_P4_TIMER_ENABLE) || (STD_ON == DCM_DSD_SUB_SERVICE_P4_TIMER_ENABLE)) */
}

/**
 * @brief			DslInternal_ResetConnectionStatus
 * @details			Reset all internal status related to the connection.
 */
FUNC(void, DCM_CODE)DslInternal_ResetConnectionStatus
(
	void
)
{
	/**
	 * @req [SWS_Dcm_00624] With the reception of Dcm_TpTxConfirmation() connected to the response
	 * 		given by the DSL submodule, the DCM shall not stop the current protocol (no call to
	 * 		xxx_StopProtocol).
	 */

	uint8 u8ConIdx = Dcm_ActiveConIdx;
	uint8 u8ProRowIdx = Dcm_ActiveProRowIdx;

	Dcm_ConnectionStatus[u8ConIdx].ServiceFnc = NULL_PTR;
	Dcm_ConnectionStatus[u8ConIdx].ServiceId = 0xFFu;
	Dcm_ConnectionStatus[u8ConIdx].ServiceIdx = 0xFFu;
	Dcm_ConnectionStatus[u8ConIdx].RxState = DCM_RX_STATE_IDLE;
	Dcm_ConnectionStatus[u8ConIdx].TxState = DCM_TX_STATE_IDLE;
	Dcm_ConnectionStatus[u8ConIdx].RemainLen = 0u;
	Dcm_ConnectionStatus[u8ConIdx].CopyOffset = 0u;
	Dcm_ConnectionStatus[u8ConIdx].Concurrent3E = (boolean)FALSE;
	Dcm_ConnectionStatus[u8ConIdx].NRC = 0xFFu;

	Dcm_MsgContext[u8ProRowIdx].DcmRxPduId = 0xFFFFu;
	Dcm_MsgContext[u8ProRowIdx].MsgAddInfo = 0u;
	Dcm_MsgContext[u8ProRowIdx].ReqData = NULL_PTR;
	Dcm_MsgContext[u8ProRowIdx].ReqDataLen = 0u;
	Dcm_MsgContext[u8ProRowIdx].ResData = NULL_PTR;
	Dcm_MsgContext[u8ProRowIdx].ResDataLen = 0u;
	Dcm_MsgContext[u8ProRowIdx].ResMaxDataLen = 0u;

	Dcm_OpState = DCM_INITIAL;

	/**
	 * @req [SWS_Dcm_00170] As long as the server is in a session other than the default session, the
	 * 		DCM shall not call ComM_DCM_InactiveDiagnostic(NetworkId), with the networkId associated to
	 * 		the received Pdu, with the reception of Dcm_TpTxConfirmation() connected to the response
	 * 		given by the DSL submodule.
	 */
	if(DCM_DEFAULT_SESSION != Dcm_ActiveSession)
	{
		Dcm_S3TimerStatus.TimerEnable = (boolean)TRUE;
	}
	else
	{
		/**
		 * @req [SWS_Dcm_00164] With the reception of Dcm_TpTxConfirmation() connected to the response
		 * 		given by the DSL submodule, the DCM shall call ComM_DCM_InactiveDiagnostic(NetworkId),
		 * 		with the networkId associated to the transmitted Pdu (see DcmDslProtocolComMChannelRef),
		 * 		to inform the ComM module that Full Communication is not longer needed.
		 *
		 * @req [SWS_Dcm_00165] The DCM shall not call ComM_DCM_InactiveDiagnostic(NetworkId) for NRC
		 * 		0x78 (Response pending). The DCM shall only call ComM_DCM_InactiveDiagnostic(NetworkId)
		 * 		with the very last response (positive or negative) connected to the request.
		 *
		 * @req [SWS_Dcm_00166] If a "suppressPosRspMsgIndicationBit" is indicated and the positive
		 * 		response will be suppressed, the DCM shall call ComM_DCM_InactiveDiagnostic(NetworkId).
		 *
		 * @req [SWS_Dcm_00697] If a negative response is suppressed in case of functional addressing
		 * 		(see SWS_Dcm_00001), the DCM shall call ComM_DCM_InactiveDiagnostic(NetworkId).
		 *
		 * @req [SWS_Dcm_00168] If the actual diagnostic session is changed from a session different
		 * 		than the default into the default session (initiated by UDS Service
		 * 		DiagnosticSessionControl or S3Server timeout or protocol preemption), then the DCM shall
		 * 		call ComM_DCM_InactiveDiagnostic(NetworkId),with the networkId associated to the
		 * 		received Pdu, to inform the ComM module that Full Communication is not longer needed.
		 */
		Dcm_ComMStatus[u8ConIdx].DiagnosticState = DCM_COMM_NOT_ACTIVE;
		ComM_DCM_InactiveDiagnostic(Dcm_ConfigPtr->DcmDslMainConnection[u8ConIdx].DcmDslProtocolComMChannelRef);
	}

	Dcm_ActiveConIdx = 0xFFu;

	Dcm_P2TimerStatus.CurrentTime = 0u;
	Dcm_P2TimerStatus.TimerEnable = (boolean)FALSE;

#if(0u != DCM_DSL_DIAG_RESP_MAX_NUM_RESP_PEND)
	Dcm_P2StarTimerStatus.PendingCnt = 0u;
	Dcm_P2StarTimerStatus.CurrentTime = 0u;
	Dcm_P2StarTimerStatus.TimerEnable = (boolean)FALSE;
	Dcm_P2StarTimerStatus.PendingNRCSendState = (boolean)TRUE;
	Dcm_P2StarTimerStatus.PendingProcessState = (boolean)FALSE;
#endif /* #if(0u != DCM_DSL_DIAG_RESP_MAX_NUM_RESP_PEND) */

#if((STD_ON == DCM_DSD_SERVICE_P4_TIMER_ENABLE) || (STD_ON == DCM_DSD_SUB_SERVICE_P4_TIMER_ENABLE))
	/* Initialize the P4 timer status. */
	Dcm_P4TimerStatus.CurrentTime = 0u;
	Dcm_P4TimerStatus.TimeoutTime = 0u;
	Dcm_P4TimerStatus.TimerEnable = (boolean)FALSE;
#endif /* #if((STD_ON == DCM_DSD_SERVICE_P4_TIMER_ENABLE) || (STD_ON == DCM_DSD_SUB_SERVICE_P4_TIMER_ENABLE)) */
}

/**
 * @brief			DslInternal_SetSesCtrlType
 * @details			DSL internal interface, switch internal session mode.
 *
 * @param[in]		SesCtrlType:Session type.
 */
FUNC(void, DCM_CODE)DslInternal_SetSesCtrlType
(
	Dcm_SesCtrlType SesCtrlType
)
{
	uint8 u8ConIdx = Dcm_ActiveConIdx;
	uint8 u8ProRowIdx = Dcm_ActiveProRowIdx;
	Dcm_SessionDataType newSesIdx = Dcm_NewActiveSessionIdx;
	const Dcm_DspSessionRowType* pSessionRow = &Dcm_ConfigPtr->DcmDsp->DcmDspSessionRow[newSesIdx];
	const Dcm_DslProtocolRowType* pProtocolRow = &Dcm_ConfigPtr->DcmDsl->DcmDslProtocolRow[u8ProRowIdx];
	
	DspInternal_ResetServiceSetState(SesCtrlType, newSesIdx);

	/**
	 * @req [SWS_Dcm_00139] The DSL shall reset the security level to the value 0x00 (i.e. the security
	 * 		is enabled) under one of the following conditions: if a transition from any diagnostic
	 * 		session other than the defaultSession to another session other than the defaultSession
	 * 		(including the currently active diagnostic session) is performed or if a transition from any
	 * 		diagnostic session other than the defaultSession to the defaultSession
	 * 		(DslInternal_SetSecurityLevel()) (initiated by UDS Service DiagnosticSessionControl (0x10)
	 * 		or S3Server timeout) is performed.
	 */
	if(DCM_DEFAULT_SESSION != Dcm_ActiveSession)
	{
		Dcm_NewActiveSecurityIdx = (Dcm_SecurityDataType)(~0u);
		DslInternal_SetSecurityLevel(DCM_SEC_LEV_LOCKED);
	}

	/**
	 * @req [SWS_Dcm_00167] If ActiveDiagnostic is "DCM_COMM_ACTIVE" and the actual diagnostic session
	 * 		is changed into a session different than the default session (initiated by UDS Service
	 * 		DiagnosticSessionControl), the Dcm shall call ComM_DCM_ActiveDiagnostic(NetworkId), with the
	 * 		NetworkId associated to the received Pdu, to inform the ComM module about the need to stay
	 * 		in Full Communication Mode.
	 */
	if(DCM_DEFAULT_SESSION != SesCtrlType)
	{
		Dcm_ComMStatus[u8ConIdx].DiagnosticState = DCM_COMM_ACTIVE;
		//ComM_DCM_ActiveDiagnostic(Dcm_ConfigPtr->DcmDslMainConnection[u8ConIdx].DcmDslProtocolComMChannelRef);
		Dcm_ComMStatus[u8ConIdx].CommunicationState = DCM_COMM_FULL_COMMUNICATION;
	}

	/**
	 * @req [SWS_Dcm_00022] The DSL submodule shall save the state of the current active session.
	 */
	Dcm_ActiveSession = SesCtrlType;
	Dcm_ActiveSessionIdx = newSesIdx;

	/**
	 * @req [SWS_Dcm_00311] The send confirmation function shall set the new diagnostic session type
	 * 		with DslInternal_SetSesCtrlType() and shall set the new timing parameters (P2ServerMax,
	 * 		P2ServerMax*) (see configuration parameters DcmDspSessionP2ServerMax and
	 * 		DcmDspSessionP2StarServerMax) and do the mode switch of the ModeDeclarationGroupPrototype
	 * 		DcmDiagnosticSessionControl by calling SchM_Switch_<bsnp>_DcmDiagnosticSessionControl()
	 * 		with the new diagnostic session type (see SWS_Dcm_00778).
	 */
	Dcm_P2TimerStatus.CurrentTime = 0u;
	Dcm_P2TimerStatus.TimeoutTime = (pSessionRow->DcmDspSessionP2ServerMax - pProtocolRow->DcmTimStrP2ServerAdjust);
#if(STD_ON == DCM_DSP_SESSION_TIM_P2_PENDING_WINDOW)
	Dcm_P2TimerStatus.PendingThreshold = (pSessionRow->DcmDspSessionP2PendingThreshold - pProtocolRow->DcmTimStrP2ServerAdjust);
#endif /* #if(STD_ON == DCM_DSP_SESSION_TIM_P2_PENDING_WINDOW) */

#if(0u != DCM_DSL_DIAG_RESP_MAX_NUM_RESP_PEND)
	Dcm_P2StarTimerStatus.CurrentTime = 0u;
	Dcm_P2StarTimerStatus.TimeoutTime = (pSessionRow->DcmDspSessionP2StarServerMax - pProtocolRow->DcmTimStrP2StarServerAdjust);
#endif /* #if(0u != DCM_DSL_DIAG_RESP_MAX_NUM_RESP_PEND) */

	/**
	 * @req [SWS_Dcm_01062] The call to Dcm_ResetToDefaultSession() allows the application to
	 * 		reset the current session to Default session and invokes the mode switch of the
	 * 		ModeDeclarationGroupPrototype DcmDiagnosticSessionControl by calling
	 * 		SchM_Switch_<bsnp>_DcmDiagnosticSessionControl
	 * 		(RTE_MODE_DcmDiagnostic_SessionControl_DEFAULT_SESSION).
	 *
	 * @req [SWS_Dcm_00140] Whenever a non-default session is active and when the session timeout
	 * 		(S3Server) is reached without receiving any diagnostic request, the DSL submodule shall
	 * 		reset to the default session state ("DefaultSession", 0x01) and invoke the the mode switch
	 * 		of the ModeDeclarationGroupPrototype DcmDiagnosticSessionControl by calling
	 * 		SchM_Switch_<bsnp>_DcmDiagnosticSessionControl
	 * 		(RTE_MODE_DcmDiagnostic_SessionControl_DEFAULT_SESSION).
	 *
	 * @req [SWS_Dcm_00147] After all Xxx_StartProtocol() functions have returned E_OK (meaning all
	 * 		components have allowed the start of the protocol), the session state is reset to default
	 * 		session. Furthermore the DCM module shall invoke the the mode switch of the
	 * 		ModeDeclarationGroupPrototype DcmDiagnosticSessionControl by calling
	 * 		SchM_Switch_<bsnp>_DcmDiagnosticSessionControl
	 * 		(RTE_MODE_DcmDiagnostic_SessionControl_DEFAULT_SESSION).
	 */
	SchM_Switch_DcmDiagnosticSessionControl(Dcm_ActiveSession);
}

/**
 * @brief			DslInternal_SetSecurityLevel
 * @details			DSL internal interface, switch internal security level.
 *
 * @param[in]		SecurityLevel:Security level.
 */
FUNC(void, DCM_CODE)DslInternal_SetSecurityLevel
(
	Dcm_SecLevelType SecurityLevel
)
{
	Dcm_SecurityDataType newSecIdx = Dcm_NewActiveSecurityIdx;

#if(STD_ON == DCM_UDS0x2A_ENABLE)
	uint8 u8ILoop;
	Dcm_SecurityDataType secLevelRef;
	Dcm_SchedulerTableType* pScheduler = NULL_PTR;

#if((STD_ON == DCM_UDS0x2C_ENABLE) && (STD_ON == DCM_DSP_DDDID_CHECK_PER_SOURCE_DID))
	uint8 u8JLoop;
	Dcm_DDDIdElementStatus* pElementStatus = NULL_PTR;
#endif /* #if((STD_ON == DCM_UDS0x2C_ENABLE) && (STD_ON == DCM_DSP_DDDID_CHECK_PER_SOURCE_DID)) */

	/**
	 * @req [SWS_Dcm_01110] On any security level change, the Dcm shall stop any scheduled periodic DID
	 * 		(see [SWS_Dcm_01113], [SWS_Dcm_01114], [SWS_Dcm_01115], [SWS_Dcm_01116], [SWS_Dcm_01117] and
	 * 		[SWS_Dcm_01118]), that was restricted by security access, but not supported by the new
	 * 		security level anymore.
	 *
	 * @req [SWS_Dcm_01112] On any security level change, the Dcm shall stop any scheduled periodic
	 * 		DDDID (see [SWS_Dcm_01114], [SWS_Dcm_01116], [SWS_Dcm_01117] and [SWS_Dcm_01118]), that
	 * 		contains source data, not supported in the current security level, in case the configuration
	 * 		parameter DcmDspDDDIDcheckPerSourceDID is set to TRUE.
	 */
	for(u8ILoop = 0u; u8ILoop < Dcm_PeriodicTransStatus.PDidNum;)
	{
		pScheduler = &Dcm_PeriodicTransStatus.SchedulerTable[u8ILoop];

		secLevelRef = pScheduler->SecLevelRef;

		if(((DCM_SEC_LEV_LOCKED == SecurityLevel) && (0u != secLevelRef)) ||\
			((0xFFu != newSecIdx) && (!DCM_CHECK_BIT_SET(secLevelRef, newSecIdx, Dcm_SecurityDataType))))
		{
			DspInternal_DeletePeriodicDid(u8ILoop);
		}
#if((STD_ON == DCM_UDS0x2C_ENABLE) && (STD_ON == DCM_DSP_DDDID_CHECK_PER_SOURCE_DID))
		else if(0x03u == pScheduler->PDidType)
		{
			for(u8JLoop = 0u; u8JLoop < Dcm_DDDidStatus[pScheduler->PDDDidIndex].ElementNum; u8JLoop++)
			{
				pElementStatus = &Dcm_DDDidStatus[pScheduler->PDDDidIndex].ElementStatus[u8JLoop];

				if((0u != pElementStatus->SecLevelRef) &&\
					(!DCM_CHECK_BIT_SET(pElementStatus->SecLevelRef, newSecIdx, Dcm_SecurityDataType)))
				{
					DspInternal_DeletePeriodicDid(u8ILoop);

					break;
				}
			}
			if(Dcm_DDDidStatus[pScheduler->PDDDidIndex].ElementNum == u8JLoop)
			{
				u8ILoop++;
			}
		}
#endif /* #if((STD_ON == DCM_UDS0x2C_ENABLE) && (STD_ON == DCM_DSP_DDDID_CHECK_PER_SOURCE_DID)) */
		else
		{
			u8ILoop++;
		}
	}
#endif /* #if(STD_ON == DCM_UDS0x2A_ENABLE) */

	Dcm_ActiveSecurityIdx = newSecIdx;
	Dcm_ActiveSecurity = SecurityLevel;
}

/**
 * @brief			DslInternal_TimerProcess
 * @details			DSL internal interface, used for timeout handling of related timers.
 */
FUNC(void, DCM_CODE)DslInternal_TimerProcess
(
	void
)
{
	/**
	 * @req [SWS_Dcm_00024] If the Application (or the DSP submodule) is able to perform a requested
	 * 		diagnostic task, but needs additional time to finish the task and prepare the response,
	 * 		then the DSL submodule shall send a negative response with NRC 0x78 (Response pending) when
	 * 		reaching the response time (DcmDspSessionP2ServerMax -DcmTimStrP2ServerAdjust respectively
	 * 		DcmDspSessionP2StarServerMax - DcmTimStrP2StarServerAdjust).
	 *
	 * @req [SWS_Dcm_00139] The DSL shall reset the security level to the value 0x00 (i.e. the security
	 * 		is enabled) under one of the following conditions: if a transition from any diagnostic
	 * 		session other than the defaultSession to another session other than the defaultSession
	 * 		(including the currently active diagnostic session) is performed or if a transition from any
	 * 		diagnostic session other than the defaultSession to the defaultSession
	 * 		(DslInternal_SetSecurityLevel()) (initiated by UDS Service DiagnosticSessionControl (0x10)
	 * 		or S3Server timeout) is performed.
	 */

	uint8 u8Index;

	/* S3 Timer. */
	if((boolean)TRUE == Dcm_S3TimerStatus.TimerEnable)
	{
		Dcm_S3TimerStatus.CurrentTime += DCM_TASK_TIME;

		if((uint16)5000 <= Dcm_S3TimerStatus.CurrentTime)
		{
			Dcm_S3TimerStatus.CurrentTime = 0u;
			Dcm_S3TimerStatus.TimerEnable = (boolean)FALSE;

			Dcm_NewActiveSessionIdx = DCM_DSP_DEFAULT_SESSION_ROW_IDX;
			DslInternal_SetSesCtrlType(DCM_DEFAULT_SESSION);

			Dcm_NewActiveSecurityIdx = (Dcm_SecurityDataType)(~0u);
			DslInternal_SetSecurityLevel(DCM_SEC_LEV_LOCKED);

			for(u8Index = 0u; u8Index < DCM_DSL_MAIN_CONNECTION_NUM; u8Index++)
			{
				Dcm_ComMStatus[u8Index].DiagnosticState = DCM_COMM_NOT_ACTIVE;
				ComM_DCM_InactiveDiagnostic(Dcm_ConfigPtr->DcmDslMainConnection[u8Index].DcmDslProtocolComMChannelRef);
			}

#if(STD_ON == DCM_DSP_TRNASFER_ERROR_HANDLING_ENABLE)
			if(DCM_TRANSFER_IDLE != Dcm_TransferStatus.Process)
			{
				DspInternal_TransferInit();
				/* Initialize the FBL module. */
				FBL_Init();
			}
#endif /* #if(STD_ON == DCM_DSP_TRNASFER_ERROR_HANDLING_ENABLE) */
		}
	}

	/**
	 * @req [SWS_Dcm_00120] If the number of negative responses for a requested diagnostic tasks (see
	 * 		SWS_Dcm_00024) reaches the value defined in the configuration parameter
	 * 		DcmDslDiagRespMaxNumRespPend, the DCM module shall stop processing the active diagnostic
	 * 		request, inform the application or BSW (if this diagnostic task implies the call to a SW-C
	 * 		interface or a BSW interface) by setting OpStatus parameter, of active port interface, to
	 * 		DCM_CANCEL and shall send a negative response with NRC 0x10 (General reject).
	 */

	/* P2 Timer. */
	if((boolean)TRUE == Dcm_P2TimerStatus.TimerEnable)
	{
		Dcm_P2TimerStatus.CurrentTime += DCM_TASK_TIME;

		if(Dcm_P2TimerStatus.TimeoutTime <= Dcm_P2TimerStatus.CurrentTime)
		{
			/**
			 * @req [SWS_Dcm_01142] The Dcm shall wait the Full Communication mode indication from the
			 * 		ComM (call to Dcm_ComM_FullComModeEntered()) before initiating the transmission of
			 * 		the diagnostic answer. The time to wait should be no longer than the P2ServerMax
			 * 		calculated from the moment the request was received.
			 *
			 * @req [SWS_Dcm_01143] In case the Dcm needs to confirm a response pending transmission
			 * 		(DCM_E_FORCE_RCRRP), the Dcm shall trigger the DET error
			 * 		DCM_E_FORCE_RCRRP_IN_SILENT_COMM.
			 */
			if(DCM_TX_STATE_WAITING == Dcm_ConnectionStatus[Dcm_ActiveConIdx].TxState)
			{
				DCM_DET_ERROR_REPORT(DCM_SID_MAINFUNCTION, DCM_E_FORCE_RCRRP_IN_SILENT_COMM);

				DslInternal_ResetConnectionStatus();
			}
			else
			{
#if(0u != DCM_DSL_DIAG_RESP_MAX_NUM_RESP_PEND)
#if((STD_ON == DCM_DSD_SERVICE_P4_TIMER_ENABLE) || (STD_ON == DCM_DSD_SUB_SERVICE_P4_TIMER_ENABLE))
				if(Dcm_P4TimerStatus.TimeoutTime == Dcm_P2TimerStatus.TimeoutTime)
				{
					Dcm_ConnectionStatus[Dcm_ActiveConIdx].NRC = DCM_E_GENERALREJECT;
				}
				else
#endif /* #if((STD_ON == DCM_DSD_SERVICE_P4_TIMER_ENABLE) || (STD_ON == DCM_DSD_SUB_SERVICE_P4_TIMER_ENABLE)) */
				{
					Dcm_OpState = DCM_PENDING;
					Dcm_ConnectionStatus[Dcm_ActiveConIdx].NRC = DCM_E_RESPONSE_PENDING;
				}
#else
				Dcm_ConnectionStatus[Dcm_ActiveConIdx].NRC = DCM_E_GENERALREJECT;
#endif /* #if(0u != DCM_DSL_DIAG_RESP_MAX_NUM_RESP_PEND) */

				DsdInternal_ResponseProcess((Std_ReturnType)E_NOT_OK);
			}
		}
	}

#if(0u != DCM_DSL_DIAG_RESP_MAX_NUM_RESP_PEND)
	/* P2* Timer. */
	if((boolean)TRUE == Dcm_P2StarTimerStatus.TimerEnable)
	{
		Dcm_P2StarTimerStatus.CurrentTime += DCM_TASK_TIME;

		if(Dcm_P2StarTimerStatus.TimeoutTime <= Dcm_P2StarTimerStatus.CurrentTime)
		{
			Dcm_OpState = DCM_PENDING;
			Dcm_ConnectionStatus[Dcm_ActiveConIdx].NRC = DCM_E_RESPONSE_PENDING;

			Dcm_P2StarTimerStatus.PendingNRCSendState = (boolean)TRUE;

			DsdInternal_ResponseProcess((Std_ReturnType)E_NOT_OK);
		}
	}
#endif /* #if(0u != DCM_DSL_DIAG_RESP_MAX_NUM_RESP_PEND) */

#if((STD_ON == DCM_DSD_SERVICE_P4_TIMER_ENABLE) || (STD_ON == DCM_DSD_SUB_SERVICE_P4_TIMER_ENABLE))
	/* P4 Timer. */
	if((boolean)TRUE == Dcm_P4TimerStatus.TimerEnable)
	{
		Dcm_P4TimerStatus.CurrentTime += DCM_TASK_TIME;

		if(Dcm_P4TimerStatus.TimeoutTime <= Dcm_P4TimerStatus.CurrentTime)
		{
			Dcm_ConnectionStatus[Dcm_ActiveConIdx].NRC = DCM_E_GENERALREJECT;

			DsdInternal_ResponseProcess((Std_ReturnType)E_NOT_OK);

			Dcm_P4TimerStatus.TimerEnable = (boolean)FALSE;
		}
	}
#endif /* #if((STD_ON == DCM_DSD_SERVICE_P4_TIMER_ENABLE) || (STD_ON == DCM_DSD_SUB_SERVICE_P4_TIMER_ENABLE)) */
}

#if(0u != DCM_DSL_DIAG_RESP_MAX_NUM_RESP_PEND)
/**
 * @brief			DslInternal_PendingProcess
 * @details			DSL internal interface, used for pending handling of related services.
 */
FUNC(void, DCM_CODE)DslInternal_PendingProcess
(
	void
)
{
	Std_ReturnType result;
	const Dcm_DslProtocolRowType* pProtocolRow = &Dcm_ConfigPtr->DcmDsl->DcmDslProtocolRow[Dcm_ActiveProRowIdx];

	if((boolean)TRUE == Dcm_P2StarTimerStatus.PendingProcessState)
	{
		if(DCM_CANCEL == Dcm_OpState)
		{
			(void)Dcm_ConnectionStatus[Dcm_ActiveConIdx].ServiceFnc(\
							Dcm_OpState,\
							&Dcm_MsgContext[Dcm_ActiveProRowIdx],\
							&Dcm_ConnectionStatus[Dcm_ActiveConIdx].NRC\
							);

			DslInternal_ResetConnectionStatus();
		}
		else
		{
			Dcm_ConnectionStatus[Dcm_ActiveConIdx].NRC = DCM_E_GENERALREJECT;

			Dcm_MsgContext[Dcm_ActiveProRowIdx].ResData = pProtocolRow->DcmDslProtocolTxBufferRef->DcmDslBufferRef;

			result = Dcm_ConnectionStatus[Dcm_ActiveConIdx].ServiceFnc(\
							Dcm_OpState,\
							&Dcm_MsgContext[Dcm_ActiveProRowIdx],\
							&Dcm_ConnectionStatus[Dcm_ActiveConIdx].NRC\
							);

			DsdInternal_ResponseProcess(result);
		}

	}
}
#endif /* #if(0u != DCM_DSL_DIAG_RESP_MAX_NUM_RESP_PEND) */

#if((STD_ON == DCM_DSL_DIAG_RESP_ON_SECOND_DECLINED_REQUEST) || (STD_ON == DCM_DSL_CALLBACK_DCM_REQUEST_SERVICE_ENABLED))
/**
 * @brief			DslInternal_SetNRCAndTransmit
 * @details			DSL internal interface, when relevant service have not been processed yet but need
 * 					to reply to NRC, call this interface to reply directly.
 *
 * @param[in]		u8Sid:Service identifier.
 * @param[in]		u8ProConIdx:Connection index.
 * @param[in]		u8ProRowIdx:Protocol index.
 * @param[in]		NRC:Reply NRC.
 * @param[in]		pProtocolRow:Used protocol pointer.
 *
 * @return     		Result of this operation.
 * @retval			BUFREQ_OK:Reply successful.
 * @retval			BUFREQ_E_NOT_OK:Reply failed.
 */
FUNC(BufReq_ReturnType, DCM_CODE)DslInternal_SetNRCAndTransmit
(
	uint8 u8Sid,
	uint8 u8ProConIdx,
	uint8 u8ProRowIdx,
	Dcm_NegativeResponseCodeType NRC,
	boolean isResetStatus
)
{
	BufReq_ReturnType result = BUFREQ_E_NOT_OK;

	PduIdType id;
	PduInfoType info;
	const Dcm_DslMainConnectionType* pConnection = &Dcm_ConfigPtr->DcmDslMainConnection[u8ProConIdx];

	/**
	 * @req [SWS_Dcm_00119] The DSL submodule shall send negative responses as required in SWS_Dcm_00024
	 * 		from a separate buffer.
	 */
	if(NULL_PTR != pConnection->DcmDslProtocolTx)
	{
		id = pConnection->DcmDslProtocolTx->DcmDslProtocolTxPduRef;

		info.SduDataPtr = Dcm_NRCBuffer;
		info.SduLength = 3u;

		info.SduDataPtr[1] = u8Sid;
		info.SduDataPtr[2] = NRC;

		if((Std_ReturnType)E_OK == PduR_DcmTransmit(id, &info))
		{
			Dcm_ConnectionStatus[u8ProConIdx].CopyOffset = 0u;
			Dcm_ConnectionStatus[u8ProConIdx].RemainLen = info.SduLength;
			Dcm_ConnectionStatus[u8ProConIdx].TxState = DCM_TX_STATE_COPY;

			Dcm_MsgContext[u8ProRowIdx].ResData = Dcm_NRCBuffer;

			result = BUFREQ_OK;
		}
	}

	if((BUFREQ_E_NOT_OK == result) && ((boolean)TRUE == isResetStatus))
	{
		DslInternal_ResetConnectionStatus();
	}

	return result;
}
#endif /* #if((STD_ON == DCM_DSL_DIAG_RESP_ON_SECOND_DECLINED_REQUEST) || (STD_ON == DCM_DSL_CALLBACK_DCM_REQUEST_SERVICE_ENABLED)) */

/**
 * @brief			DslInternal_NoProtocolPreemption
 * @details			When protocol preemption does not occur but has active protocol, the handing
 * 					interface called by Dcm_StartOfReception().
 *
 * @param[in]		Info:Pointer to the request message, includes message buffer pointer and message
 * 					length.
 * @param[in] 		TpSduLength:Total length of the request message.
 * @param[in]		pProtocolRx:Pointer to the used DcmDslProtocolRx container.
 * @param[in]		pProtocolRow:Pointer to the used DcmDslProtocolRow container.
 *
 * @param[out]		BufferSizePtr:Available receive buffer size.
 *
 * @return        	Result of this operation.
 * @retval			BUFREQ_OK:Process successfully.
 * @retval			BUFREQ_E_NOT_OK:Process failed.
 */
FUNC(BufReq_ReturnType, DCM_CODE)DslInternal_NoProtocolPreemption
(
	P2CONST(PduInfoType, AUTOMATIC, DCM_CONST)Info,
	PduLengthType TpSduLength,
	P2VAR(PduLengthType, AUTOMATIC, DCM_VAR)BufferSizePtr,
	P2CONST(Dcm_DslProtocolRxType, AUTOMATIC, DCM_CONST)pProtocolRx,
	P2CONST(Dcm_DslProtocolRowType, AUTOMATIC, DCM_CONST)pProtocolRow
)
{
	BufReq_ReturnType result = BUFREQ_E_NOT_OK;

	uint8 u8ConIdx = pProtocolRx->DcmDslRxParentConIdx;
	uint8 u8ProRowIdx = pProtocolRx->DcmDslRxParentProIdx;

	*BufferSizePtr = 0u;

	if(0xFFu == Dcm_ActiveConIdx)
	{
		/* No active connection is available, directly receive and process this diagnostic request. */

		if(DCM_DEFAULT_SESSION != Dcm_ActiveSession)
		{
			Dcm_S3TimerStatus.CurrentTime = 0u;
			Dcm_S3TimerStatus.TimerEnable = (boolean)FALSE;
		}

		Dcm_ActiveConIdx = u8ConIdx;

		Dcm_ConnectionStatus[u8ConIdx].RemainLen = TpSduLength;
		Dcm_ConnectionStatus[u8ConIdx].RxState = DCM_RX_STATE_COPY;

		Dcm_MsgContext[u8ProRowIdx].DcmRxPduId = pProtocolRx->DcmDslProtocolRxPduId;

		*BufferSizePtr = pProtocolRow->DcmDslProtocolRxBufferRef->DcmDslBufferSize;
		result = BUFREQ_OK;
	}
	else
	{
		if((DCM_DEFAULT_SESSION != Dcm_ActiveSession)\
			&& ((0x3Eu == Info->SduDataPtr[0])\
			&& (0x80u == Info->SduDataPtr[1])\
			&& (DCM_FUNCTIONAL_TYPE == pProtocolRx->DcmDslProtocolRxAddrType)))
		{
			Dcm_ConnectionStatus[u8ConIdx].Concurrent3E = (boolean)TRUE;

			result = BUFREQ_OK;
		}
#if(STD_ON == DCM_DSL_DIAG_RESP_ON_SECOND_DECLINED_REQUEST)
		else
		{
			/**
			 * @req [SWS_Dcm_00727] If a diagnostic request is already running and a second request
			 * 		(ClientB) can not be processed (e.g.due to priority assessment), the response
			 * 		behaviour depends on the configuration option parameter
			 * 		DcmDslDiagRespOnSecondDeclinedRequest (see SWS_Dcm_00914_Conf). If this
			 * 		configuration parameter is TRUE, a negative response with NRC 0x21
			 * 		(BusyRepeatRequest) shall be issued for the second request (see [SWS_Dcm_00788 and
			 * 		[SWS_Dcm_00789). If the configuration parameter is FALSE, no response shall be
			 * 		issued (see [SWS_Dcm_00790).
			 */
			if(Dcm_ActiveConIdx != u8ConIdx)
			{
				result = DslInternal_SetNRCAndTransmit(Info->SduDataPtr[0], u8ConIdx, u8ProRowIdx, DCM_E_BUSYREPEATREQUEST, (boolean)FALSE);
			}
		}
#endif /* #if(STD_ON == DCM_DSL_DIAG_RESP_ON_SECOND_DECLINED_REQUEST) */
	}

	return result;
}

#if(0u != DCM_DSL_PROTOCOLROW_NUM)
/**
 * @brief			DslInternal_ProtocolPreemption
 * @details			When protocol preemption is occur, the handing interface called by
 * 					Dcm_StartOfReception().
 *
 * @param[in]		Info:Pointer to the request message, includes message buffer pointer and message
 * 					length.
 * @param[in] 		TpSduLength:Total length of the request message.
 * @param[in]		pProtocolRx:Pointer to the used DcmDslProtocolRx container.
 * @param[in]		pProtocolRow:Pointer to the used DcmDslProtocolRow container.
 *
 * @param[out]		BufferSizePtr:Available receive buffer size.
 *
 * @return        	Result of this operation.
 * @retval			BUFREQ_OK:Process successfully.
 * @retval			BUFREQ_E_NOT_OK:Process failed.
 */
FUNC(BufReq_ReturnType, DCM_CODE)DslInternal_ProtocolPreemption
(
	PduIdType Id,
	P2CONST(PduInfoType, AUTOMATIC, DCM_CONST)Info,
	PduLengthType TpSduLength,
	P2VAR(PduLengthType, AUTOMATIC, DCM_VAR)BufferSizePtr,
	P2CONST(Dcm_DslProtocolRxType, AUTOMATIC, DCM_CONST)pProtocolRx,
	P2CONST(Dcm_DslProtocolRowType, AUTOMATIC, DCM_CONST)pProtocolRow
)
{
	BufReq_ReturnType result = BUFREQ_E_NOT_OK;

	boolean flag = (boolean)FALSE;
	uint8 u8ConIdx = pProtocolRx->DcmDslRxParentConIdx;
	uint8 u8ProRowIdx = pProtocolRx->DcmDslRxParentProIdx;
	const Dcm_DslProtocolRowType* pActiveProtocolRow = &Dcm_ConfigPtr->DcmDsl->DcmDslProtocolRow[Dcm_ActiveProRowIdx];

	*BufferSizePtr = 0u;

	/**
	 * @req [SWS_Dcm_00015] A protocol with higher priority is allowed to preempt the already running
	 * 		protocol.
	 */
	if(pProtocolRow->DcmDslProtocolPriority > pActiveProtocolRow->DcmDslProtocolPriority)
	{
		/**
		 * @req [SWS_Dcm_01144] Protocol preemption can�t be activated with a concurrent TesterPresent
		 * 		of a higher priority protocol (see also [SWS_Dcm_01146]).
		 *
		 * @req [SWS_Dcm_01050] In case of diagnostic parallel requests, with same / lower priority
		 * 		than the active request then the ComM APIs (ComM_DCM_ActiveDiagnostic,
		 * 		ComM_DCM_InactiveDiagnostic) shall not be called.
		 */
		if((DCM_DEFAULT_SESSION != Dcm_ActiveSession)\
			&& ((0x3Eu == Info->SduDataPtr[0])\
			&& (0x80u == Info->SduDataPtr[1])\
			&& (DCM_FUNCTIONAL_TYPE == pProtocolRx->DcmDslProtocolRxAddrType)))
		{
			Dcm_ConnectionStatus[u8ConIdx].Concurrent3E = (boolean)TRUE;

			result = BUFREQ_OK;
		}
		else
		{
			flag = (boolean)TRUE;
		}
	}
	else
	{
		/**
		 * @req [SWS_Dcm_00625] A Low-priority or same-priority request can preempt a higher priority
		 * 		protocol if this higher priority protocol is in default session and no active request
		 * 		is in execution phase. In this case the DSL submodule shall call all configured
		 * 		Xxx_StopProtocol() functions (see configuration parameter
		 * 		DcmDslCallbackDCMRequestService).
		 *
		 * @req [SWS_Dcm_00728] The handling of protocols with equal priority shall be possible.
		 */
		if((DCM_DEFAULT_SESSION == Dcm_ActiveSession) && ((uint8)0xFF == Dcm_ActiveConIdx))
		{
			flag = (boolean)TRUE;
		}
#if(STD_ON == DCM_DSL_DIAG_RESP_ON_SECOND_DECLINED_REQUEST)
		else
		{
			/**
			 * @req [SWS_Dcm_00729] In case of multiple clients with different PduIDs which are
			 * 		requesting the same protocol, as all the connections of the same protocol are having
			 * 		the same priority, a second request (with the different RxPduId) will not be
			 * 		processed. If the configuration parameter DcmDslDiagRespOnSecondDeclinedRequest is
			 * 		TRUE, a negative response with NRC 0x21 (BusyRepeatRequest) shall be issued for the
			 * 		second request. If the configuration parameter is FALSE, no response shall be issued.
			 */
			result = DslInternal_SetNRCAndTransmit(\
							Info->SduDataPtr[0], u8ConIdx, u8ProRowIdx,\
							DCM_E_BUSYREPEATREQUEST, (boolean)FALSE\
							);
		}
#endif /* #if(STD_ON == DCM_DSL_DIAG_RESP_ON_SECOND_DECLINED_REQUEST) */
	}

	if((boolean)TRUE == flag)
	{
		/**
		 * @req [SWS_Dcm_00459] If a running diagnostic request is preempted by a higher priority
		 * 		request (of another protocol), the DSL submodule shall call all configured
		 * 		Xxx_StopProtocol() functions (see configuration parameter
		 * 		DcmDslCallbackDCMRequestService).
		 */
#if(STD_ON == DCM_DSL_CALLBACK_DCM_REQUEST_SERVICE_ENABLED)
		if((boolean)TRUE == DslInternal_StopProtocol(pActiveProtocolRow))
		{
#else
			DslInternal_StopProtocol();
#endif /* #if(STD_ON == DCM_DSL_CALLBACK_DCM_REQUEST_SERVICE_ENABLED) */
			if(DCM_DEFAULT_SESSION != Dcm_ActiveSession)
			{
				Dcm_S3TimerStatus.CurrentTime = 0u;
				Dcm_S3TimerStatus.TimerEnable = (boolean)FALSE;
			}

			Dcm_ActiveConIdx = u8ConIdx;
			Dcm_ActiveProRowIdx = u8ProRowIdx;

			Dcm_ConnectionStatus[u8ConIdx].RemainLen = TpSduLength;
			Dcm_ConnectionStatus[u8ConIdx].RxState = DCM_RX_STATE_COPY;

			Dcm_MsgContext[u8ProRowIdx].DcmRxPduId = pProtocolRx->DcmDslProtocolRxPduId;

			*BufferSizePtr = pProtocolRow->DcmDslProtocolRxBufferRef->DcmDslBufferSize;
			result = BUFREQ_OK;
#if(STD_ON == DCM_DSL_CALLBACK_DCM_REQUEST_SERVICE_ENABLED)
		}
		else
		{
			/**
			 * @req [SWS_Dcm_01190] If Xxx_StopProtocol() does not return E_OK, the Dcm shall return
			 * 		NRC 0x22.
			 */
			result = DslInternal_SetNRCAndTransmit(\
							Info->SduDataPtr[0], u8ConIdx, u8ProRowIdx,\
							DCM_E_CONDITIONSNOTCORRECT, (boolean)FALSE\
							);
		}
#endif /* #if(STD_ON == DCM_DSL_CALLBACK_DCM_REQUEST_SERVICE_ENABLED) */
	}

	return result;
}
#endif /* #if(0u != DCM_DSL_PROTOCOLROW_NUM) */

/**
 * @brief			DslInternal_StartProtocol
 * @details			When a diagnostic request is successfully received, but the protocol has not yet
 * 					been enabled, invoke this interface to enable the protocol.
 *
 * @return        	Result of this operation.
 * @retval			TRUE:Enable successfully.
 * @retval			FALSE:Enable failed.
 */
#if(STD_ON == DCM_DSL_CALLBACK_DCM_REQUEST_SERVICE_ENABLED)
FUNC(boolean, DCM_CODE)DslInternal_StartProtocol
(
	P2CONST(Dcm_DslProtocolRowType, AUTOMATIC, DCM_CONST)pProtocolRow
)
#else
FUNC(void, DCM_CODE)DslInternal_StartProtocol
(
	void
)
#endif /* #if(STD_ON == DCM_DSL_CALLBACK_DCM_REQUEST_SERVICE_ENABLED) */
{
#if(STD_ON == DCM_DSL_CALLBACK_DCM_REQUEST_SERVICE_ENABLED)
	uint8 u8Index;
	boolean result = (boolean)TRUE;
	Std_ReturnType callbackRet = (Std_ReturnType)E_NOT_OK;
	uint16 u16ConnectionId = Dcm_ConfigPtr->DcmDslMainConnection[Dcm_ActiveConIdx].DcmDslProtocolRxConnectionId;

	for(u8Index = 0u; u8Index < DCM_DSL_CALLBACK_START_PROTOCOL_NUM; u8Index++)
	{
		callbackRet = Dcm_ConfigPtr->DcmDsl->DcmDslCallbackDCMRequestService->DcmDslCallbackStartProtocol[u8Index](pProtocolRow->DcmDslProtocolID, 0xFFFFu, u16ConnectionId);

		if((Std_ReturnType)E_OK != callbackRet)
		{
			result = (boolean)FALSE;
			break;
		}
	}

	if((boolean)TRUE == result)
	{
#endif /* #if(STD_ON == DCM_DSL_CALLBACK_DCM_REQUEST_SERVICE_ENABLED) */

		/**
		 * @req [SWS_Dcm_00144] After all Xxx_StartProtocol() functions have returned E_OK (meaning all
		 * 		components have allowed the start of the protocol), the default timing parameters are
		 * 		loaded from the default session configuration (see configuration parameter
		 * 		DcmDspSessionRow).
		 */
		Dcm_NewActiveSessionIdx = DCM_DSP_DEFAULT_SESSION_ROW_IDX;
		DslInternal_SetSesCtrlType(DCM_DEFAULT_SESSION);

		/**
		 * @req [SWS_Dcm_00146] After all Xxx_StartProtocol() functions have returned E_OK (meaning all
		 * 		components have allowed the start of the protocol), the default timing parameters are
		 * 		loaded from the default session configuration (see configuration parameter
		 * 		DcmDspSessionRow).
		 */
		Dcm_NewActiveSecurityIdx = (Dcm_SecurityDataType)(~0u);
		DslInternal_SetSecurityLevel(DCM_SEC_LEV_LOCKED);

		DCM_BIT_SET(Dcm_ProtocolStartState, Dcm_ActiveProRowIdx, uint8);

#if(STD_ON == DCM_DSL_CALLBACK_DCM_REQUEST_SERVICE_ENABLED)
	}

	return result;
#endif /* #if(STD_ON == DCM_DSL_CALLBACK_DCM_REQUEST_SERVICE_ENABLED) */
}

/**
 * @brief			DslInternal_TransmitHandle
 * @details			DSL internal interface, transmit respond to lower.
 *
 * @param[in]		pProtocolTx:Used ProtocolTx pointer.
 */
FUNC(void, DCM_CODE)DslInternal_TransmitHandle
(
	PduIdType id
)
{
	/**
	 * @req [SWS_Dcm_01075] The order of the transmitted NRC shall be compliant with the one described
	 * 		in ISO14229-1 [15].
	 */

	uint8 u8ConIdx = Dcm_ActiveConIdx;
	uint8 u8ProRowIdx = Dcm_ActiveProRowIdx;
	PduInfoType info;

	info.SduDataPtr = Dcm_MsgContext[u8ProRowIdx].ResData;
	info.SduLength = Dcm_MsgContext[u8ProRowIdx].ResDataLen;

	/**
	 * @req [SWS_Dcm_00115] When the diagnostic response of a DcmDslMainConnection is ready, the DSL
	 * 		submodule shall trigger the transmission of the diagnostic response to the PduR module by
	 * 		calling PduR_DcmTransmit() using the corresponding DcmDslProtocolTxPduRef parameter as
	 * 		PduId.
	 *
	 * @req [SWS_Dcm_00237] The DSL submodule shall forward the diagnostic (response) message (positive
	 * 		or negative response) further to the PduR module by executing a DSL transmit functionality.
	 */
	if((Std_ReturnType)E_OK == PduR_DcmTransmit(id, &info))
	{
		if((boolean)TRUE == Dcm_P2TimerStatus.TimerEnable)
		{
			Dcm_P2TimerStatus.TimerEnable = (boolean)FALSE;
#if(STD_ON == DCM_DSP_SESSION_TIM_P2_PENDING_WINDOW)
			Dcm_P2StarTimerStatus.PendingProcessState = (boolean)FALSE;
#endif /* #if(STD_ON == DCM_DSP_SESSION_TIM_P2_PENDING_WINDOW) */
		}

#if(0u != DCM_DSL_DIAG_RESP_MAX_NUM_RESP_PEND)
		if((boolean)TRUE == Dcm_P2StarTimerStatus.TimerEnable)
		{
			Dcm_P2StarTimerStatus.TimerEnable = (boolean)FALSE;
			Dcm_P2StarTimerStatus.PendingProcessState = (boolean)FALSE;
		}
#endif /* #if(0u != DCM_DSL_DIAG_RESP_MAX_NUM_RESP_PEND) */

		Dcm_ConnectionStatus[u8ConIdx].RemainLen = info.SduLength;
		Dcm_ConnectionStatus[u8ConIdx].CopyOffset = 0u;
		Dcm_ConnectionStatus[u8ConIdx].TxState = DCM_TX_STATE_COPY;
	}
	/**
	 * @req [SWS_Dcm_00995] If the NRC 0x78 (Response Pending) response in [SWS_Dcm_00535] is not sent
	 * 		successfully the Dcm shall cancel the current request.
	 *
	 * @req [SWS_Dcm_00997] If the NRC 0x78 (Response Pending) response in [SWS_Dcm_00535] is not sent
	 * 		successfully no jump to the bootloader shall be performed.
	 */
	else
	{
		DslInternal_ResetConnectionStatus();
	}
}

/**
 * @brief			DsdInternal_ServiceProcess
 * @details			DSD internal interface, conduct relevant service checks and execute corresponding
 * 					service processing.
 */
FUNC(void, DCM_CODE)DsdInternal_ServiceProcess
(
	void
)
{
	uint8 u8Sid;
	uint8 u8SubSid;
	uint8 u8ServiceIdx;
	uint8 u8ConIdx = Dcm_ActiveConIdx;
	uint8 u8ProRowIdx = Dcm_ActiveProRowIdx;
	Std_ReturnType result = (Std_ReturnType)E_NOT_OK;
	const Dcm_DsdServiceType* pService = NULL_PTR;
	const Dcm_DslProtocolRowType* pProtocolRow = NULL_PTR;

	if(DCM_RX_STATE_PROCESS == Dcm_ConnectionStatus[u8ConIdx].RxState)
	{
		Dcm_ConnectionStatus[u8ConIdx].RxState = DCM_RX_STATE_PROCESSING;

		/**
		 * @req [SWS_Dcm_00192] The DSD submodule shall analyze the (incoming) diagnostic message for the
		 * 		diagnostic service identifier (based on first byte of the diagnostic message) and shall
		 * 		check the supported services with the newly received diagnostic service identifier.
		 */
		u8Sid = Dcm_MsgContext[u8ProRowIdx].ReqData[0];
		u8SubSid = Dcm_MsgContext[u8ProRowIdx].ReqData[1];

		Dcm_ConnectionStatus[u8ConIdx].ServiceId = u8Sid;

		pProtocolRow = &Dcm_ConfigPtr->DcmDsl->DcmDslProtocolRow[u8ProRowIdx];

		/**
		 * @req [SWS_Dcm_00178] The DSD submodule shall only process valid requests and shall reject invalid
		 * 		ones.
		 *
		 * @req [SWS_Dcm_00827] The DSD sub-module shall check the received diagnostic request in the order
		 * 		given by ISO14229-1. If one of the computations failed the DCM shall stop the execution of
		 * 		the NRC check sequence then stop or do not start the execution of the received diagnostic
		 * 		request and finally transmit the NRC for which the computation failed.
		 */
		if((Std_ReturnType)E_OK == DspInternal_GeneralCheck(u8Sid,\
			Dcm_ConfigPtr->DcmDslProtocolRx[Dcm_MsgContext[u8ProRowIdx].DcmRxPduId].DcmDslProtocolRxAddrType,\
			&u8ServiceIdx, pProtocolRow))
		{
			pService = &pProtocolRow->DcmDslProtocolSIDTable->DcmDsdService[u8ServiceIdx];

#if(STD_ON == DCM_DSD_SERVICE_P4_TIMER_ENABLE)
			if(0u != pService->DcmDsdServiceP4ServerMax)
			{
				if(Dcm_P2TimerStatus.TimeoutTime != pService->DcmDsdServiceP4ServerMax)
				{
					Dcm_P4TimerStatus.TimerEnable = (boolean)TRUE;
					Dcm_P4TimerStatus.CurrentTime = Dcm_P2TimerStatus.CurrentTime;
				}
				Dcm_P4TimerStatus.TimeoutTime = pService->DcmDsdServiceP4ServerMax;
			}
#endif /* #if(STD_ON == DCM_DSD_SERVICE_P4_TIMER_ENABLE) */

			/**
			 * @req [SWS_Dcm_00201] The DSD submodule shall remove the "suppressPosRspMsgIndicationBit� (by
			 * 		masking the Bit) from the diagnostic message.
			 *
			 * @req [SWS_Dcm_00202] The DCM module shall transport the information on a suppression of a
			 * 		positive response being active (between the layers) via the parameter Dcm_MsgContextType.
			 *
			 * @req [SWS_Dcm_00204] The DCM module shall only perform the "suppressPosRspMsgIndicationBit�
			 * 		handling when the configuration parameter DcmDsdSidTabSubfuncAvail is set for the newly
			 * 		received service identifier.
			 */
			if(((boolean)TRUE == pService->DcmDsdSidTabSubfuncAvail) && (0x80u == (u8SubSid & 0x80u)))
			{
				Dcm_MsgContext[u8ProRowIdx].MsgAddInfo |= 0x02u;
				Dcm_MsgContext[u8ProRowIdx].ReqData[1] &= 0x7Fu;
			}

			/**
			 * @req [SWS_Dcm_00198] The DSD submodule shall store the newly received diagnostic service
			 * 		identifier for later use.
			 */
			Dcm_ConnectionStatus[u8ConIdx].ServiceIdx = u8ServiceIdx;
			Dcm_ConnectionStatus[u8ConIdx].ServiceFnc = pService->DcmDsdSidTabFnc;

			/**
			 * @req [SWS_Dcm_00196] For the check, the DSD submodule shall scan the active "Service
			 * 		Identifier Table" for a newly received diagnostic service identifier. If this service
			 * 		identifier is supported and if the configuration parameter DcmDsdSidTabFnc (see
			 * 		ECUC_Dcm_00777) is not empty, the DSD submodule shall call the configured service
			 * 		interface (<Module>_<DiagnosticService>). If the configuration parameter is empty, the
			 * 		DCM shall call the internally implemented service interface.
			 *
			 * @req [SWS_Dcm_00221] The DSD submodule shall search for the executable functionality of the
			 * 		DSP submodule for newly received diagnostic service identifier and shall call the
			 * 		corresponding DSP service interpreter.
			 *
			 * @req [SWS_Dcm_00222] When the DSP submodule has finished the execution of the requested
			 * 		Diagnostic Service the DSD submodule shall assemble the response.
			 *
			 * @req [SWS_Dcm_00272] The DSP submodule shall trigger a negative response with NRC 0x13
			 * 		(Incorrect message length or invalid format), when the analysis of the request message
			 * 		results in formatting or length failure.
			 */
			result = pService->DcmDsdSidTabFnc(\
						Dcm_OpState,\
						&Dcm_MsgContext[u8ProRowIdx],\
						&Dcm_ConnectionStatus[u8ConIdx].NRC\
						);
		}

		DsdInternal_ResponseProcess(result);
	}
}

/**
 * @brief			DsdInternal_TpTxConfirmation
 * @details			DSD internal interface, execute the corresponding confirmation processing.
 *
 * @return     		Result of this operation.
 * @retval			TRUE:Need reset the connection status.
 * @retval			FALSE:No need reset the connection status.
 */
FUNC(boolean, DCM_CODE)DsdInternal_TpTxConfirmation
(
	void
)
{
	boolean result = (boolean)TRUE;

	switch(Dcm_OpState)
	{
#if(0u != DCM_DSL_DIAG_RESP_MAX_NUM_RESP_PEND)
		case DCM_PENDING:
		case DCM_FORCE_RCRRP_OK:
			Dcm_P2StarTimerStatus.CurrentTime = 0u;
			Dcm_P2StarTimerStatus.TimerEnable = (boolean)TRUE;
			Dcm_P2StarTimerStatus.PendingNRCSendState = (boolean)FALSE;
			Dcm_P2StarTimerStatus.PendingProcessState = (boolean)TRUE;
			result = (boolean)FALSE;
			break;
		case DCM_CANCEL:
			Dcm_P2StarTimerStatus.PendingProcessState = (boolean)TRUE;
			result = (boolean)FALSE;
			break;
#endif /* #if(0u != DCM_DSL_DIAG_RESP_MAX_NUM_RESP_PEND) */
		case DCM_INITIAL:
			switch(Dcm_ConnectionStatus[Dcm_ActiveConIdx].ServiceId)
			{
#if(STD_ON == DCM_UDS0x10_ENABLE)
				case 0x10u:
					DspInternal_SessionControlConfirmation();
					break;
#endif /* #if(STD_ON == DCM_UDS0x10_ENABLE) */
#if(STD_ON == DCM_UDS0x11_ENABLE)
				case 0x11u:
					DspInternal_EcuResetConfirmation();
					break;
#endif /* #if(STD_ON == DCM_UDS0x11_ENABLE) */
#if(STD_ON == DCM_UDS0x27_ENABLE)
				case 0x27u:
					DspInternal_SecurityAccessConfirmation();
					break;
#endif /* #if(STD_ON == DCM_UDS0x27_ENABLE) */
				default:
					/* Nothing to do here. */
					break;
			}
			break;
		default:
			/* Nothing to do here. */
			break;
	}

	return result;
}

#if(0u != DCM_DSP_DID_NUM)
/**
 * @brief			DspInternal_CheckDidValid
 * @details			DSP internal interface, check the Did whether valid.
 *
 * @param[in]		checkDid:Did be checked.
 *
 * @param[out]		pDidIdx:Index of Did be checked.
 * @param[out]		pErrorCode:If error occur, output the NRC.
 *
 * @return        	Result of this operation.
 * @retval			TRUE:The request Did is valid.
 * @retval			FALSE:The request Did is not valid.
 */
#if((STD_ON == DCM_UDS0x2C_ENABLE) || (STD_ON == DCM_UDS0x2A_ENABLE))
FUNC(Std_ReturnType, DCM_CODE)DspInternal_CheckDidValid
(
	uint16 checkDid,
	Dcm_PermissionCheckUserType userType,
	P2VAR(uint8, AUTOMATIC, DCM_VAR)pDidIdx,
	P2VAR(Dcm_SessionDataType, AUTOMATIC, DCM_VAR)pSesLevelRef,
	P2VAR(Dcm_SecurityDataType, AUTOMATIC, DCM_VAR)pSecLevelRef,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
)
#else
FUNC(Std_ReturnType, DCM_CODE)DspInternal_CheckDidValid
(
	uint16 checkDid,
	Dcm_PermissionCheckUserType userType,
	P2VAR(uint8, AUTOMATIC, DCM_VAR)pDidIdx,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
)
#endif /* #if((STD_ON == DCM_UDS0x2C_ENABLE) || (STD_ON == DCM_UDS0x2A_ENABLE)) */
{
	Std_ReturnType result = (Std_ReturnType)E_NOT_OK;

	uint8 u8Index;
	Dcm_SessionDataType sesLevelRef;
	Dcm_SecurityDataType secLevelRef;
	const Dcm_DspDidType* pDid = NULL_PTR;
	const Dcm_DspDidInfoType* pDidInfo = NULL_PTR;

	for(u8Index = 0u; u8Index < DCM_DSP_DID_NUM; u8Index++)
	{
		pDid = &Dcm_ConfigPtr->DcmDsp->DcmDspDid[u8Index];

		if(checkDid == pDid->DcmDspDidIdentifier)
		{
			/**
			 * @req [SWS_Dcm_00561] If a DID is set as unused (DcmDspDidUsed set to FALSE), the DCM
			 * 		shall consider the DID as not supported (according to SWS_Dcm_00438).
			 *
			 * @req [SWS_Dcm_00562] If a DID is set as unused (DcmDspDidUsed set to FALSE), the DCM
			 * 		shall consider the DID as not supported (according to SWS_Dcm_00467).
			 *
			 * @req [SWS_Dcm_00564] If a DID is set as unused (DcmDspDidUsed set to FALSE), the DCM
			 * 		shall consider the DID as not supported (according to SWS_Dcm_00563).
			 *
			 * @req [SWS_Dcm_01096] If a DID is set as unused (DcmDspDidUsed set to FALSE), the Dcm
			 * 		shall consider the DID as not supported.
			 */
			if((boolean)TRUE == pDid->DcmDspDidUsed)
			{
				pDidInfo = pDid->DcmDspDidInfoRef;

				switch(userType)
				{
#if((STD_ON == DCM_UDS0x22_ENABLE) || (STD_ON == DCM_UDS0x24_ENABLE))
#if(STD_ON == DCM_UDS0x22_ENABLE)
				case DCM_PERMISSION_CHECK_USER_READ_DID:
#endif /* #if(STD_ON == DCM_UDS0x22_ENABLE) */
#if(STD_ON == DCM_UDS0x24_ENABLE)
				case DCM_PERMISSION_CHECK_USER_SCALING_DID:
#endif /* #if(STD_ON == DCM_UDS0x24_ENABLE) */
					/**
					 * @req [SWS_Dcm_00433] On reception of the UDS Service ReadDataByIdentifier (0x22),
					 * 		for every requested DID the DCM module shall check if the DID has a Read
					 * 		access configured (see configuration parameter DcmDspDidRead in
					 * 		DcmDspDidInfo). If none of the DID has a Read access, the DCM module shall
					 * 		send NRC 0x31 (Request out of range).
					 */
					if(NULL_PTR != pDidInfo->DcmDspDidRead)
					{
						sesLevelRef = pDidInfo->DcmDspDidRead->DcmDspDidReadSessionRef;
						secLevelRef = pDidInfo->DcmDspDidRead->DcmDspDidReadSecurityLevelRef;

						result = (Std_ReturnType)E_OK;
					}
					break;
#endif /* #if((STD_ON == DCM_UDS0x22_ENABLE) || (STD_ON == DCM_UDS0x24_ENABLE)) */
#if(STD_ON == DCM_UDS0x2E_ENABLE)
				case DCM_PERMISSION_CHECK_USER_WRITE_DID:
					/**
					 * @req [SWS_Dcm_00468] On reception of the UDS Service WriteDataByIdentifier
					 * 		(0x2E), the DCM module shall check if the DID has a Write access configured
					 * 		(see configuration parameter DcmDspDidWrite in DcmDspDidInfo). If not, the
					 * 		DCM module shall send NRC 0x31 (Request out of range).
					 */
					if(NULL_PTR != pDidInfo->DcmDspDidWrite)
					{
						sesLevelRef = pDidInfo->DcmDspDidWrite->DcmDspDidWriteSessionRef;
						secLevelRef = pDidInfo->DcmDspDidWrite->DcmDspDidWriteSecurityLevelRef;

						result = (Std_ReturnType)E_OK;
					}
					break;
#endif /* #if(STD_ON == DCM_UDS0x2E_ENABLE) */
#if(STD_ON == DCM_UDS0x2F_ENABLE)
				case DCM_PERMISSION_CHECK_USER_CONTROL_DID:
					/**
					 * @req [SWS_Dcm_00565] On reception of the UDS Service
					 * 		InputOutputControlByIdentifier (0x2F), the DCM module shall check if the
					 * 		DID has a Control access configured (see configuration parameter
					 * 		DcmDspDidControl in DcmDspDidInfo). If not, the DCM module shall send NRC
					 * 		0x31 (Request out of range).
					 */
					if(NULL_PTR != pDidInfo->DcmDspDidControl)
					{
						sesLevelRef = pDidInfo->DcmDspDidControl->DcmDspDidControlSessionRef;
						secLevelRef = pDidInfo->DcmDspDidControl->DcmDspDidControlSecurityLevelRef;

						result = (Std_ReturnType)E_OK;
					}
					break;
#endif /* #if(STD_ON == DCM_UDS0x2F_ENABLE) */
#if(STD_ON == DCM_UDS0x2C_ENABLE)
				case DCM_PERMISSION_CHECK_USER_DYNAMICALLY_DEFINE_DID:
					if((0xF200u <= checkDid) && (0xF3FFu >= checkDid) &&\
						((boolean)TRUE == pDidInfo->DcmDspDidDynamicallyDefined) &&\
						(NULL_PTR != pDidInfo->DcmDspDidRead))
					{
						sesLevelRef = pDidInfo->DcmDspDidRead->DcmDspDidReadSessionRef;
						secLevelRef = pDidInfo->DcmDspDidRead->DcmDspDidReadSecurityLevelRef;

						result = (Std_ReturnType)E_OK;
					}
					break;
#endif /* #if(STD_ON == DCM_UDS0x2C_ENABLE) */
				default:
					/* User is invalid. */
					break;
				}
			}

			break;
		}
	}

	if((Std_ReturnType)E_OK == result)
	{
		/**
		 * @req [SWS_Dcm_00434] On reception of the UDS Service ReadDataByIdentifier (0x22), for every
		 * 		requested DID the DCM module shall check if the DID can be read in the current session
		 * 		(see configuration parameter DcmDspDidReadSessionRef). If none of the DID can be renden
		 * 		in the current session, the DCM module shall send a NRC 0x31 (Request out of Range).
		 *
		 * @req [SWS_Dcm_00435] On reception of the UDS Service ReadDataByIdentifier (0x22), for every
		 * 		requested DID the DCM module shall check if the DID can be read in the current security
		 * 		level (see configuration parameter DcmDspDidReadSecurityLevelRef). If not, the DCM
		 * 		module shall send NRC 0x33 (Security access denied).
		 *
		 * @req [SWS_Dcm_00469] On reception of the UDS Service WriteDataByIdentifier (0x2E), the DCM
		 * 		module shall check if the DID can be written in the current session (see configuration
		 * 		parameter DcmDspDidWriteSessionRef). If not, the DCM module shall send a NRC 0x31
		 * 		(Request Out of Range).
		 *
		 * @req [SWS_Dcm_00470] On reception of the UDS Service WriteDataByIdentifier (0x2E), the DCM
		 * 		module shall check if the DID can be written in the current security level (see
		 * 		configuration parameter DcmDspDidWriteSecurityLevelRef). If not, the DCM module shall
		 * 		send NRC 0x33 (Security access denied).
		 *
		 * @req [SWS_Dcm_00566] On reception of the UDS Service InputOutputControlByIdentifier (0x2F),
		 * 		the DCM module shall check if the DID can be control in the current session (see
		 * 		configuration parameter DcmDspDidControlSessionRef). If not, the DCM module shall send
		 * 		a NRC 0x31 (Request Out of Range).
		 *
		 * @req [SWS_Dcm_00567] On reception of the UDS Service InputOutputControlByIdentifier (0x2F),
		 * 		the DCM module shall check if the DID can be control in the current security level (see
		 * 		configuration parameter DcmDspDidControlSecurityLevelRef). If not, the DCM module shall
		 * 		send NRC 0x33 (Security access denied).
		 */
		result = DspInternal_PermissionCheck(sesLevelRef, secLevelRef, userType, pErrorCode);

		if((Std_ReturnType)E_OK == result)
		{
			if(NULL_PTR != pDidIdx)
			{
				*pDidIdx = u8Index;
			}

#if(STD_ON == DCM_UDS0x2C_ENABLE)
			if(NULL_PTR != pSesLevelRef)
			{
				*pSesLevelRef = sesLevelRef;
			}

			if(NULL_PTR != pSecLevelRef)
			{
				*pSecLevelRef = secLevelRef;
			}
#endif /* #if(STD_ON == DCM_UDS0x2C_ENABLE) */
		}
	}
	else
	{
		*pErrorCode = DCM_E_REQUESTOUTOFRANGE;
	}

	return result;
}
#endif /* #if(0u != DCM_DSP_DID_NUM) */

#if(0u != DCM_DSP_DID_RANGE_NUM)
/**
 * @brief			DspInternal_CheckRangeDidValid
 * @details			DSP internal interface, check the Range Did whether valid.
 *
 * @param[in]		checkRangeDid:Range Did be checked.
 * @param[in]		opState:Operating state.
 *
 * @param[out]		pRangeDidIdx:Index of Range Did be chekced.
 * @param[out]		pErrorCode:If error occur, output the NRC.
 *
 * @return        	Result of this operation.
 * @retval			TRUE:The request Did is valid.
 * @retval			FALSE:The request Did is not valid.
 */
FUNC(Std_ReturnType, DCM_CODE)DspInternal_CheckRangeDidValid
(
	uint16 checkRangeDid,
	Dcm_OpStatusType opState,
	Dcm_PermissionCheckUserType userType,
	P2VAR(uint8, AUTOMATIC, DCM_VAR)pRangeDidIdx,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
)
{
	Std_ReturnType result = (Std_ReturnType)E_OK;

	uint8 u8Index;
#if(STD_ON == DCM_DSP_DID_RANGE_IS_DID_AVAILABLE_FNC_ENABLE)
	Dcm_DidSupportedType isSupported = DCM_DID_SUPPORTED;
#endif /* #if(STD_ON == DCM_DSP_DID_RANGE_IS_DID_AVAILABLE_FNC_ENABLE) */
	Dcm_SessionDataType sesLevelRef = 0u;
	Dcm_SecurityDataType secLevelRef = 0u;
	const Dcm_DspDidRangeType* pRangeDid = NULL_PTR;
	const Dcm_DspDidInfoType* pRangeDidInfo = NULL_PTR;

	for(u8Index = 0u; u8Index < DCM_DSP_DID_RANGE_NUM; u8Index++)
	{
		pRangeDid = &Dcm_ConfigPtr->DcmDsp->DcmDspDidRange[u8Index];

		if((pRangeDid->DcmDspDidRangeIdentifierLowerLimit <= checkRangeDid) &&\
			(pRangeDid->DcmDspDidRangeIdentifierUpperLimit >= checkRangeDid))
		{
			pRangeDidInfo = pRangeDid->DcmDspDidRangeInfoRef;

#if(STD_ON == DCM_DSP_DID_RANGE_IS_DID_AVAILABLE_FNC_ENABLE)
			if(NULL_PTR != pRangeDid->DcmDspDidRangeIsDidAvailableFnc)
			{
				result = pRangeDid->DcmDspDidRangeIsDidAvailableFnc(checkRangeDid, opState, &isSupported);
			}

			if(((Std_ReturnType)E_OK == result) && (DCM_DID_SUPPORTED == isSupported))
			{
#endif /* #if(STD_ON == DCM_DSP_DID_RANGE_IS_DID_AVAILABLE_FNC_ENABLE) */
				switch(userType)
				{
#if(STD_ON == DCM_UDS0x22_ENABLE)
				case DCM_PERMISSION_CHECK_USER_READ_DID:
					if(NULL_PTR != pRangeDidInfo->DcmDspDidRead)
					{
						sesLevelRef = pRangeDidInfo->DcmDspDidRead->DcmDspDidReadSessionRef;
						secLevelRef = pRangeDidInfo->DcmDspDidRead->DcmDspDidReadSecurityLevelRef;
					}
					break;
#endif /* #if(STD_ON == DCM_UDS0x22_ENABLE) */
#if(STD_ON == DCM_UDS0x2E_ENABLE)
				case DCM_PERMISSION_CHECK_USER_WRITE_DID:
					if(NULL_PTR != pRangeDidInfo->DcmDspDidWrite)
					{
						sesLevelRef = pRangeDidInfo->DcmDspDidWrite->DcmDspDidWriteSessionRef;
						secLevelRef = pRangeDidInfo->DcmDspDidWrite->DcmDspDidWriteSecurityLevelRef;
					}
					break;
#endif /* #if(STD_ON == DCM_UDS0x2E_ENABLE) */
				default:
					result = (Std_ReturnType)E_NOT_OK;
					break;
				}
#if(STD_ON == DCM_DSP_DID_RANGE_IS_DID_AVAILABLE_FNC_ENABLE)
			}
#endif /* #if(STD_ON == DCM_DSP_DID_RANGE_IS_DID_AVAILABLE_FNC_ENABLE) */

			break;
		}
	}

	if((DCM_DSP_DID_RANGE_NUM != u8Index) && ((Std_ReturnType)E_OK == result))
	{
		result = DspInternal_PermissionCheck(sesLevelRef, secLevelRef, userType, pErrorCode);

		if((Std_ReturnType)E_OK == result)
		{
			*pRangeDidIdx = u8Index;
		}
	}
	else
	{
		*pErrorCode = DCM_E_REQUESTOUTOFRANGE;

		result = (Std_ReturnType)E_NOT_OK;
	}

	return result;
}
#endif /* #if(0u != DCM_DSP_DID_RANGE_NUM) */

#if(STD_ON == DCM_UDS0x2C_ENABLE)
/**
 * @brief			DspInternal_DDDidStatusInit
 * @details			DSP internal interface, initialize dynamically define Did internal status.
 *
 * @param[in]		u8DDDidIdx:The DDDid index in Dcm_DDDidStatus.
 */
FUNC(void, DCM_CODE)DspInternal_DDDidStatusInit
(
	uint8 u8DDDidIdx
)
{
	uint8 u8ILoop = 0u;
	uint8 u8JLoop;
	uint8 u8ILoopMaxCnt = DCM_DSP_DDDID_NUM;
	uint8 u8JLoopMaxCnt = DCM_DSP_DDDID_ELEMENT_MAX_NUM;

	if(0xFFu != u8DDDidIdx)
	{
		u8ILoop = u8DDDidIdx;
		u8ILoopMaxCnt = (u8DDDidIdx + 1u);
		u8JLoopMaxCnt = Dcm_DDDidStatus[u8ILoop].ElementNum;
	}

	for(; u8ILoop < u8ILoopMaxCnt; u8ILoop++)
	{
		Dcm_DDDidStatus[u8ILoop].DefinedState = (boolean)FALSE;
		Dcm_DDDidStatus[u8ILoop].ElementNum = 0u;

		for(u8JLoop = 0u; u8JLoop < u8JLoopMaxCnt; u8JLoop++)
		{
			Dcm_DDDidStatus[u8ILoop].ElementStatus[u8JLoop].IsDidType = (boolean)FALSE;
#if(STD_ON == DCM_UDS0x2C_SUB0x01_ENABLE)
			Dcm_DDDidStatus[u8ILoop].ElementStatus[u8JLoop].Element.SrcDid.Identifier = 0u;
			Dcm_DDDidStatus[u8ILoop].ElementStatus[u8JLoop].Element.SrcDid.SrcDidIndex = 0u;
			Dcm_DDDidStatus[u8ILoop].ElementStatus[u8JLoop].Element.SrcDid.SrcDidDataLen = 0u;
			Dcm_DDDidStatus[u8ILoop].ElementStatus[u8JLoop].Element.SrcDid.SrcDidDataPos = 0u;
#endif /* #if(STD_ON == DCM_UDS0x2C_SUB0x01_ENABLE) */
#if(STD_ON == DCM_UDS0x2C_SUB0x02_ENABLE)
			Dcm_DDDidStatus[u8ILoop].ElementStatus[u8JLoop].Element.Memory.MemoryId = 0u;
			Dcm_DDDidStatus[u8ILoop].ElementStatus[u8JLoop].Element.Memory.MemorySize = 0u;
			Dcm_DDDidStatus[u8ILoop].ElementStatus[u8JLoop].Element.Memory.MemoryAddress = 0u;
#endif /* #if(STD_ON == DCM_UDS0x2C_SUB0x02_ENABLE) */
		}
	}
}

/**
 * @brief			DspInternal_CheckDDDidReadValid
 * @details			DSP internal interface, check whether the DDDid is readable.
 *
 * @param[in]		u8ReqDDDidIdx:Index of DDDid be chekced.
 *
 * @param[out]		pErrorCode:If error occur, output the NRC.
 *
 * @return        	Result of this operation.
 * @retval			TRUE:The DDDid is readable.
 * @retval			FALSE:The DDDid is not readable.
 */
FUNC(Std_ReturnType, DCM_CODE)DspInternal_CheckDDDidReadValid
(
	uint8 u8ReqDidIdx,
	P2VAR(uint8, AUTOMATIC, DCM_VAR)pDidType,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
)
{
	Std_ReturnType result = (Std_ReturnType)E_OK;

	uint8 u8Index;
#if(STD_ON == DCM_DSP_DDDID_CHECK_PER_SOURCE_DID)
	Dcm_SessionDataType sesLevelRef;
	Dcm_SecurityDataType secLevelRef;
#endif /* #if(STD_ON == DCM_DSP_DDDID_CHECK_PER_SOURCE_DID) */
	const Dcm_DspDidInfoType* pDDDidInfo = Dcm_ConfigPtr->DcmDsp->DcmDspDid[u8ReqDidIdx].DcmDspDidInfoRef;

	if((boolean)TRUE == pDDDidInfo->DcmDspDidDynamicallyDefined)
	{
		*pDidType = 0x03u;

		if((boolean)TRUE == Dcm_DDDidStatus[pDDDidInfo->DcmDspDDDIDIndex].DefinedState)
		{
#if(STD_ON == DCM_DSP_DDDID_CHECK_PER_SOURCE_DID)

			for(u8Index = 0u; u8Index < Dcm_DDDidStatus[pDDDidInfo->DcmDspDDDIDIndex].ElementNum; u8Index++)
			{
				sesLevelRef = Dcm_DDDidStatus[pDDDidInfo->DcmDspDDDIDIndex].ElementStatus[u8Index].SesLevelRef;
				secLevelRef = Dcm_DDDidStatus[pDDDidInfo->DcmDspDDDIDIndex].ElementStatus[u8Index].SecLevelRef;

				if((boolean)TRUE == Dcm_DDDidStatus[pDDDidInfo->DcmDspDDDIDIndex].ElementStatus[u8Index].IsDidType)
				{
					result = DspInternal_PermissionCheck(sesLevelRef, secLevelRef, DCM_PERMISSION_CHECK_USER_READ_DID, pErrorCode);
				}
				else
				{
					result = DspInternal_PermissionCheck(sesLevelRef, secLevelRef, DCM_PERMISSION_CHECK_USER_MEMORY, pErrorCode);
				}

				if((Std_ReturnType)E_OK != result)
				{
					break;
				}
			}

#else
			;
#endif /* #if(STD_ON == DCM_DSP_DDDID_CHECK_PER_SOURCE_DID) */
		}
		else
		{
			*pErrorCode = DCM_E_REQUESTOUTOFRANGE;

			result = (Std_ReturnType)E_NOT_OK;
		}
	}

	return result;
}
#endif /* #if(STD_ON == DCM_UDS0x2C_ENABLE) */

/**
 * @brief			DspInternal_JumpFromHandle
 * @details			DSP internal interface, jump from the bootloader or ECUReset handle.
 */
FUNC(void, DCM_CODE)DspInternal_JumpFromHandle
(
	void
)
{
	Dcm_EcuStartModeType result;
	boolean responseFlag = (boolean)FALSE;
	Dcm_ProgConditionsType ProgConditions;
	const Dcm_DslProtocolRowType* pProtocolRow = NULL_PTR;
	const Dcm_DslMainConnectionType* pConnection = NULL_PTR;

	/**
	 * @req [SWS_Dcm_00536] At DCM initialization, the DCM shall call Dcm_GetProgConditions() to know if
	 * 		the initialization is the consequence of a jump from the bootloader / ECUReset.
	 */
	result = Dcm_GetProgConditions(&ProgConditions);

	if((DCM_COLD_START == result) && ((boolean)TRUE == ProgConditions.ResponseRequired))
	{
		responseFlag = (boolean)TRUE;
	}
	else if((DCM_WARM_START == result) && ((boolean)TRUE == ProgConditions.ApplUpdated))
	{
		if((boolean)TRUE == ProgConditions.ResponseRequired)
		{
			responseFlag = (boolean)TRUE;
		}

		/**
		 * @req [SWS_Dcm_00768] If the initialization of the DCM is the consequence of a jump from
		 * 		the bootloader (see [SWS_Dcm_00536 and the application is updated by an FLASH download
		 * 		(Dcm_ProgConditionsType.ApplUpdated == True), the DCM shall call
		 * 		BswM_Dcm_ApplicationUpdated() to notify the BswM that the application was updated.
		 */
		BswM_Dcm_ApplicationUpdated();
	}
	else
	{
		/* Nothing to do here. */
		;
	}

	if((boolean)TRUE == responseFlag)
	{
		pConnection = &Dcm_ConfigPtr->DcmDslMainConnection[ProgConditions.ConnectionId];

		Dcm_ActiveConIdx = (uint8)ProgConditions.ConnectionId;
		Dcm_ActiveProRowIdx = pConnection->DcmDslParentProIdx;

		pProtocolRow = &Dcm_ConfigPtr->DcmDsl->DcmDslProtocolRow[Dcm_ActiveProRowIdx];

		Dcm_MsgContext[Dcm_ActiveProRowIdx].ResData = pProtocolRow->DcmDslProtocolTxBufferRef->DcmDslBufferRef;
		Dcm_MsgContext[Dcm_ActiveProRowIdx].ResData[0] = ProgConditions.Sid;
		Dcm_MsgContext[Dcm_ActiveProRowIdx].ResData[1] = ProgConditions.SubFncId;
		Dcm_MsgContext[Dcm_ActiveProRowIdx].ResDataLen = 2u;

		Dcm_ConnectionStatus[Dcm_ActiveConIdx].TxState = DCM_TX_STATE_WAITING;

		/**
		 * @req [SWS_Dcm_00537] If the initialization of the DCM is the consequence of a jump from the
		 * 		bootloader / ECUReset (see [SWS_Dcm_00536, the DCM shall call ComM_DCM_ActiveDiagnostic
		 * 		(NetworkId) to request the ComManager for the full communication mode.
		 */
		//ComM_DCM_ActiveDiagnostic(pConnection->DcmDslProtocolComMChannelRef);
		Dcm_ComMStatus[Dcm_ActiveConIdx].CommunicationState = DCM_COMM_FULL_COMMUNICATION;
	}
}

#if(STD_ON == DCM_UDS0x27_ENABLE)
/**
 * @brief			DspInternal_SecurityTimerHandle
 * @details			DSP internal interface, security timeout processing handle.
 */
FUNC(void, DCM_CODE)DspInternal_SecurityTimerHandle
(
	void
)
{
#if(STD_ON == DCM_DSP_SECURITY_ATTEMPT_COUNTER_ENABLED)
	if((boolean)FALSE == Dcm_SecurityInitStatus.InitState)
	{
		if((boolean)TRUE == Dcm_SecurityInitStatus.TimerEnable)
		{
			DspInternal_SecurityInitHandle();
		}
	}
	else
#endif /* #if(STD_ON == DCM_DSP_SECURITY_ATTEMPT_COUNTER_ENABLED) */
	{
		DspInternal_SecurityDelayHandle();
	}
}
#endif /* #if(STD_ON == DCM_UDS0x27_ENABLE) */

#if((STD_ON == DCM_UDS0x34_ENABLE) || (STD_ON == DCM_UDS0x35_ENABLE))
/**
 * @brief			DspInternal_TransferInit
 * @details			DSP internal interface, initialize transfer internal status.
 */
FUNC(void, DCM_CODE)DspInternal_TransferInit
(
	void
)
{
	Dcm_TransferStatus.MemoryId = 0u;
	Dcm_TransferStatus.MemoryAddr = 0xFFFFFFFFu;
	Dcm_TransferStatus.MemorySize = 0u;
	Dcm_TransferStatus.BlockSeqCnt = 0u;
	Dcm_TransferStatus.BlockLength = 0u;
	Dcm_TransferStatus.IsFirstBlock = (boolean)FALSE;
#if(STD_ON == DCM_UDS0x34_ENABLE)
	Dcm_TransferStatus.IsLastBlock = (boolean)FALSE;
#endif /* #if(STD_ON == DCM_UDS0x34_ENABLE) */
	Dcm_TransferStatus.Process = DCM_TRANSFER_IDLE;
}
#endif /* #if((STD_ON == DCM_UDS0x34_ENABLE) || (STD_ON == DCM_UDS0x35_ENABLE)) */

/**
 * @brief			DspInternal_PermissionCheck
 * @details			DSP internal interface, check the session mode, authentication state and security
 * 					level.
 *
 * @param[in]		sessionLevelRef:The session modes allowed to execute.
 * @param[in]		securityLevelRef:The security modes allowed to execute.
 * @param[in]		userType:User type.
 *
 * @param[out]		pErrorCode:If error occur, output the NRC.
 *
 * @return     		Result of this operation.
 * @retval			E_OK:Check successful.
 * @retval			E_NOT_OK:Check failed.
 */
FUNC(Std_ReturnType, DCM_CODE)DspInternal_PermissionCheck
(
	Dcm_SessionDataType sesLevelRef,
	Dcm_SecurityDataType secLevelRef,
	Dcm_PermissionCheckUserType userType,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
)
{
	Std_ReturnType result = (Std_ReturnType)E_OK;

	/**
	 * @req [SWS_Dcm_00211] If the newly received diagnostic service is not allowed in the current
	 * 		Diagnostic Session (according to the configuration parameter DcmDsdSidTabSessionLevelRef),
	 * 		the DSD submodule shall transmit a negative response with NRC 0x7F
	 * 		(serviceNotSupportedInActiveSession) to the DSL submodule.
	 *
	 * @req [SWS_Dcm_00616] If the newly received diagnostic service is allowed in the current
	 * 		Diagnostic Session ( see SWS_Dcm_00211), but the requested subservice is not allowed in the
	 * 		current Diagnostic Session (according to the configuration parameter
	 * 		DcmDsdSubServiceSessionLevelRef), the DSD submodule shall transmit a negative response with
	 * 		NRC 0x7E (subFunctionNotSupportedInActiveSession) to the DSL submodule.
	 */
	if(!DCM_CHECK_BIT_SET(sesLevelRef, Dcm_ActiveSessionIdx, uint8))
	{
		switch(userType)
		{
		case DCM_PERMISSION_CHECK_USER_SERVICE:
			*pErrorCode = DCM_E_SERVICENOTSUPPORTEDINACTIVESESSION;
			break;
		case DCM_PERMISSION_CHECK_USER_SUBSERVICE:
			*pErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION;
			break;
		case DCM_PERMISSION_CHECK_USER_READ_DID:
			/* Nothing to do here. */
			break;
		default:
			/**
			 * @req [SWS_Dcm_00275] The DSP submodule shall trigger a negative response with NRC 0x31
			 * 		(Request out of range), when the analysis of the request message results in other
			 * 		unsupported message parameters.
			 */
			*pErrorCode = DCM_E_REQUESTOUTOFRANGE;
			break;
		}

		result = (Std_ReturnType)E_NOT_OK;
	}
	else
	{
		/**
		 * @req [SWS_Dcm_00217] If the newly received diagnostic service is not allowed in the current
		 * 		Security level (according to the configuration parameter DcmDsdSidTabSecurityLevelRef),
		 * 		the DSD submodule shall transmit a negative response with NRC 0x33 (Security access
		 * 		denied) to the DSL submodule.
		 *
		 * @req [SWS_Dcm_00617] If the newly received diagnostic service is allowed in the current
		 * 		Security level ( see SWS_Dcm_00217), but the requested subservice is not allowed in the
		 * 		current Security level (according to the configuration parameter
		 * 		DcmDsdSubServiceSecurityLevelRef), the DSD submodule shall transmit a negative response
		 * 		with NRC 0x33 (Security access denied) to the DSL submodule.
		 */
		if((0u != secLevelRef) && ((DCM_SEC_LEV_LOCKED == Dcm_ActiveSecurity)\
			|| (!DCM_CHECK_BIT_SET(secLevelRef, Dcm_ActiveSecurityIdx, uint8))))
		{
			*pErrorCode = DCM_E_SECURITYACCESSDENIED;

			result = (Std_ReturnType)E_NOT_OK;
		}
	}

	return result;
}

/**
 * @brief			DspInternal_SubServiceCheck
 * @details			DSP internal interface, check whether the sub-service to be processed is valid,
 * 					and whether the session mode and security level required by the service meet the
 * 					requirements.
 *
 * @param[in]		u8SubServiceId:Sub-Service identifier.
 * @param[in]		pService:Service pointer.
 *
 * @param[out]		pErrorCode:If error occur, output the NRC.
 *
 * @return     		Result of this operation.
 * @retval			E_OK:Check successful.
 * @retval			E_NOT_OK:Check failed.
 */
FUNC(Std_ReturnType, DCM_CODE)DspInternal_SubServiceCheck
(
	uint8 u8AddrType,
	uint8 u8SubServiceId,
	P2CONST(Dcm_DsdServiceType, AUTOMATIC, DCM_CONST)pService,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
)
{
	Std_ReturnType result = (Std_ReturnType)E_NOT_OK;

	uint8 u8Index;
	const Dcm_DsdSubServiceType* pSubService = NULL_PTR;

	/**
	 * @req [SWS_Dcm_00273] The DSD submodule shall trigger a negative response with NRC 0x12
	 * 		(SubFunction not supported), when the analysis of the request message results in subfunction
	 * 		not supported. This analysis shall not be done for UDS Service RoutineControl (0x31).
	 */
	for(u8Index = 0u; u8Index < pService->DcmDsdSubServiceNum; u8Index++)
	{
		pSubService = &pService->DcmDsdSubService[u8Index];

		if(u8SubServiceId == pSubService->DcmDsdSubServiceId)
		{
			if(((boolean)TRUE != pSubService->DcmDsdSubServiceUsed) ||\
				((u8AddrType != (uint8)pSubService->DcmDsdSubServiceRxAddrType) &&\
				(DCM_FUNCTIONAL_PHYSICAL_TYPE != pSubService->DcmDsdSubServiceRxAddrType)))
			{
				*pErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
			}
			else
			{
				result = DspInternal_PermissionCheck(\
							pSubService->DcmDsdSubServiceSessionLevelRef,\
							pSubService->DcmDsdSubServiceSecurityLevelRef,\
							DCM_PERMISSION_CHECK_USER_SUBSERVICE, pErrorCode\
							);

#if(STD_ON == DCM_DSD_SERVICE_CONDITION_CHECK_FNC_USED)
				if(((Std_ReturnType)E_OK == result) &&\
					(NULL_PTR != pSubService->DcmDsdSubServiceConditionCheckFnc))
				{
					result = pSubService->DcmDsdSubServiceConditionCheckFnc(pErrorCode);
				}
#endif /* #if(STD_ON == DCM_DSD_SERVICE_CONDITION_CHECK_FNC_USED) */
			}

			break;
		}
	}
	if(pService->DcmDsdSubServiceNum == u8Index)
	{
		*pErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
	}
#if(STD_ON == DCM_DSD_SUB_SERVICE_P4_TIMER_ENABLE)
	else
	{
		if(((Std_ReturnType)E_OK == result) && (0u != pSubService->DcmDsdSubServiceP4ServerMax))
		{
			if(Dcm_P2TimerStatus.TimeoutTime != pSubService->DcmDsdSubServiceP4ServerMax)
			{
				Dcm_P4TimerStatus.TimerEnable = (boolean)TRUE;
				Dcm_P4TimerStatus.CurrentTime = Dcm_P2TimerStatus.CurrentTime;
			}
			Dcm_P4TimerStatus.TimeoutTime = pSubService->DcmDsdSubServiceP4ServerMax;
		}
	}
#endif /* #if(STD_ON == DCM_DSD_SUB_SERVICE_P4_TIMER_ENABLE) */

	return result;
}

#if((STD_ON == DCM_UDS0x23_ENABLE) || (STD_ON == DCM_UDS0x2C_ENABLE) ||\
	(STD_ON == DCM_UDS0x3D_ENABLE) || (STD_ON == DCM_UDS0x34_ENABLE) ||\
	(STD_ON == DCM_UDS0x35_ENABLE))
/**
 * @brief			DspInternal_MemoryAddrCheck
 * @details			DSP internal interface, check whether the memory address is valid or not.
 *
 * @param[in]		u32MemoryAddr:Checked memory address.
 * @param[in]		u32MemorySize:Checked memory size.
 * @param[in]		isReadProcess:Whether is read process or not.
 *
 * @param[in/out]	pMemoryId:Returns the memory identifier.
 *
 * @param[out]		pErrorCode:If error occur, output the NRC.
 *
 * @return     		Result of this operation.
 * @retval			E_OK:Check successful.
 * @retval			E_NOT_OK:Check failed.
 */
#if(STD_ON != DCM_UDS0x2C_ENABLE)
FUNC(Std_ReturnType, DCM_CODE)DspInternal_MemoryAddrCheck
(
	uint32 u32MemoryAddr,
	uint32 u32MemorySize,
	boolean isReadProcess,
	P2VAR(uint8, AUTOMATIC, DCM_VAR)pMemoryId,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
)
#else
FUNC(Std_ReturnType, DCM_CODE)DspInternal_MemoryAddrCheck
(
	uint32 u32MemoryAddr,
	uint32 u32MemorySize,
	boolean isReadProcess,
	P2VAR(uint8, AUTOMATIC, DCM_VAR)pMemoryId,
	P2VAR(Dcm_SessionDataType, AUTOMATIC, DCM_VAR)pSesLevelRef,
	P2VAR(Dcm_SecurityDataType, AUTOMATIC, DCM_VAR)pSecLevelRef,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
)
#endif /* #if(STD_ON != DCM_UDS0x2C_ENABLE) */
{
	Std_ReturnType result = (Std_ReturnType)E_NOT_OK;

#if((0u != DCM_DSP_READ_MEMORY_RANGE_INFO_NUM) || (0u != DCM_DSP_WRITE_MEMORY_RANGE_INFO_NUM))

	uint8 u8MemoryIdInfoLoop;
	uint8 u8MemoryRangeInfoLoop;
	uint32 u32MemoryRangeHigh;
	uint32 u32MemoryRangeLow;
	boolean flag = (boolean)FALSE;
	Dcm_SessionDataType sessionLevelRef = ~(Dcm_SessionDataType)0;
	Dcm_SecurityDataType securityLevelRef = (Dcm_SecurityDataType)0;
	const Dcm_DspMemoryIdInfoType* pMemoryIdInfo = &Dcm_ConfigPtr->DcmDsp->DcmDspMemory->DcmDspMemoryIdInfo[0];

	if((boolean)TRUE == isReadProcess)
	{
#if(0u != DCM_DSP_READ_MEMORY_RANGE_INFO_NUM)
		/**
		 * @req [SWS_Dcm_00493] On reception of the UDS Service ReadMemoryByAddress (0x23), the DCM
		 * 		shall check if the complete memory range to read (from �memoryAddress� parameter to
		 * 		�memoryAddress + memorySize -1�) is inside the allowed memory ranges (check of
		 * 		DcmDspReadMemoryRangeLow and DcmDspReadMemoryRangeHigh parameters for each
		 * 		DcmDspReadMemoryRangeInfo container). If not, the DCM module shall send NRC 0x31
		 * 		(Request out of range).
		 */
		for(u8MemoryIdInfoLoop = 0u; u8MemoryIdInfoLoop < DCM_DSP_MEMORY_ID_INFO_NUM; u8MemoryIdInfoLoop++)
		{
			if(NULL_PTR != pMemoryIdInfo->DcmDspReadMemoryRangeInfo)
			{
				for(u8MemoryRangeInfoLoop = 0u; u8MemoryRangeInfoLoop < pMemoryIdInfo->DcmDspReadMemoryRangeInfoNum; u8MemoryRangeInfoLoop++)
				{
					u32MemoryRangeHigh = pMemoryIdInfo->DcmDspReadMemoryRangeInfo[u8MemoryRangeInfoLoop].DcmDspReadMemoryRangeHigh;
					u32MemoryRangeLow = pMemoryIdInfo->DcmDspReadMemoryRangeInfo[u8MemoryRangeInfoLoop].DcmDspReadMemoryRangeLow;

					if((u32MemorySize <= (u32MemoryRangeHigh - u32MemoryRangeLow)) && (u32MemoryRangeLow <= u32MemoryAddr) && (((u32MemoryRangeHigh - u32MemorySize) + 1u) >= u32MemoryAddr))
					{
						flag = (boolean)TRUE;

						securityLevelRef = pMemoryIdInfo->DcmDspReadMemoryRangeInfo[u8MemoryRangeInfoLoop].DcmDspReadMemoryRangeSecurityLevelRef;

						break;
					}
				}
			}
			if((boolean)TRUE == flag)
			{
				break;
			}
			pMemoryIdInfo++;
		}
#endif /* #if(0u != DCM_DSP_READ_MEMORY_RANGE_INFO_NUM) */
	}
	else
	{
#if(0u != DCM_DSP_WRITE_MEMORY_RANGE_INFO_NUM)
		/**
		 * @req [SWS_Dcm_00489] On reception of the UDS Service WriteMemoryByAddress (0x3D), the DCM
		 * 		shall check if the complete memory range to write (from �memoryAddress� parameter to
		 * 		�memoryAddress + memorySize -1�) is inside the allowed memory ranges (check of
		 * 		DcmDspWriteMemoryRangeLow and DcmDspWriteMemoryRangeHigh parameters for each
		 * 		DcmDspWriteMemoryRangeInfo container). If not, the DCM module shall send NRC 0x31
		 * 		(Request out of range).
		 */
		for(u8MemoryIdInfoLoop = 0u; u8MemoryIdInfoLoop < DCM_DSP_MEMORY_ID_INFO_NUM; u8MemoryIdInfoLoop++)
		{
			if(NULL_PTR != pMemoryIdInfo->DcmDspWriteMemoryRangeInfo)
			{
				for(u8MemoryRangeInfoLoop = (uint8)0; u8MemoryRangeInfoLoop < pMemoryIdInfo->DcmDspWriteMemoryRangeInfoNum; u8MemoryRangeInfoLoop++)
				{
					u32MemoryRangeHigh = pMemoryIdInfo->DcmDspWriteMemoryRangeInfo[u8MemoryRangeInfoLoop].DcmDspWriteMemoryRangeHigh;
					u32MemoryRangeLow = pMemoryIdInfo->DcmDspWriteMemoryRangeInfo[u8MemoryRangeInfoLoop].DcmDspWriteMemoryRangeLow;

					if((u32MemorySize <= (u32MemoryRangeHigh - u32MemoryRangeLow)) && (u32MemoryRangeLow <= u32MemoryAddr) && (((u32MemoryRangeHigh - u32MemorySize) + 1u) >= u32MemoryAddr))
					{
						flag = (boolean)TRUE;

						securityLevelRef = pMemoryIdInfo->DcmDspWriteMemoryRangeInfo[u8MemoryRangeInfoLoop].DcmDspWriteMemoryRangeSecurityLevelRef;

						break;
					}
				}
			}
			if((boolean)TRUE == flag)
			{
				break;
			}
			pMemoryIdInfo++;
		}
#endif /* #if(0u != DCM_DSP_WRITE_MEMORY_RANGE_INFO_NUM) */
	}

	if((boolean)FALSE == flag)
	{
		*pErrorCode = DCM_E_REQUESTOUTOFRANGE;
	}
	else
	{
		/**
		 * @req [SWS_Dcm_00490] On reception of the UDS Service WriteMemoryByAddress (0x3D), the DCM
		 * 		shall check if the complete memory range (from �memoryAddress�  parameter to
		 * 		�memoryAddress + memorySize -1�) can be written in the current security level (see
		 * 		DcmDspWriteMemoryRangeSecurityLevelRef). If security level is not correct, the DCM
		 * 		module shall send NRC 0x33 (securityAccessDenied).
		 *
		 * @req [SWS_Dcm_00494] On reception of the UDS Service ReadMemoryByAddress (0x23), the DCM
		 * 		shall check if the complete memory range (from �memoryAddress� parameter to
		 * 		�memoryAddress + memorySize -1�) can be readen in the current security level (see
		 * 		DcmDspReadMemoryRangeSecurityLevelRef). If security level is not correct, the DCM
		 * 		module shall send NRC 0x33 (securityAccessDenied).
		 */
		result = DspInternal_PermissionCheck(\
					sessionLevelRef, securityLevelRef, DCM_PERMISSION_CHECK_USER_MEMORY, pErrorCode\
					);

		if((Std_ReturnType)E_OK == result)
		{
			/**
			 * @req [SWS_Dcm_01052] On reception of the UDS Service WriteMemoryByAddress (0x3D), if the
			 * 		request message contains different MemoryIdValue compare to the configured values in
			 * 		DcmDspMemoryIdInfo container, the Dcm shall send a NRC 0x31 (Request out of Range).
			 *
			 * @req [SWS_Dcm_01053] On reception of the UDS Service ReadMemoryByAddress (0x23), if the
			 * 		request message contains different MemoryIdValue compare to the configured values in
			 * 		DcmDspMemoryIdInfo container, the Dcm shall send a NRC 0x31 (Request out of Range).
			 */
			if(0xFFu != pMemoryIdInfo->DcmDspMemoryIdValue)
			{
				if(*pMemoryId != pMemoryIdInfo->DcmDspMemoryIdValue)
				{
					*pErrorCode = DCM_E_REQUESTOUTOFRANGE;

					result = (Std_ReturnType)E_NOT_OK;
				}
			}
			else
			{
				*pMemoryId = 0u;
			}

#if(STD_ON == DCM_UDS0x2C_ENABLE)
			if(NULL_PTR != pSesLevelRef)
			{
				*pSesLevelRef = sessionLevelRef;
			}

			if(NULL_PTR != pSecLevelRef)
			{
				*pSecLevelRef = securityLevelRef;
			}
#endif /* #if(STD_ON == DCM_UDS0x2C_ENABLE) */
		}
	}

#else

	*pErrorCode = DCM_E_REQUESTOUTOFRANGE;

#endif /* #if((0u != DCM_DSP_READ_MEMORY_RANGE_INFO_NUM) || (0u != DCM_DSP_WRITE_MEMORY_RANGE_INFO_NUM)) */

	return result;
}
#endif /* #if((STD_ON == DCM_UDS0x23_ENABLE) || (STD_ON == DCM_UDS0x2C_ENABLE) ||\
			  (STD_ON == DCM_UDS0x3D_ENABLE) || (STD_ON == DCM_UDS0x34_ENABLE) ||\
			  (STD_ON == DCM_UDS0x35_ENABLE)) */

#if(STD_ON == DCM_UDS0x2A_ENABLE)
/**
 * @brief			DspInternal_DeletePeriodicDid
 * @details			DSP internal interface, delete a specific PDID from the scheduler table.
 *
 * @param[in]		u8PDidIndex:The index of PDid.
 */
FUNC(void, DCM_CODE)DspInternal_DeletePeriodicDid
(
	uint8 u8PDidIndex
)
{
	uint8 u8Index;

	for(u8Index = u8PDidIndex; u8Index < (Dcm_PeriodicTransStatus.PDidNum - 1u); u8Index++)
	{
		Dcm_PeriodicTransStatus.SchedulerTable[u8Index] = Dcm_PeriodicTransStatus.SchedulerTable[u8Index + 1u];
	}

	Dcm_PeriodicTransStatus.PDidNum--;
}

/**
 * @brief			DspInternal_PeriodicTransmission
 * @details			DSP internal interface, Periodic-Transmission handle.
 */
FUNC(void, DCM_CODE)DspInternal_PeriodicTransmission
(
	void
)
{
	uint8 u8Bit;
	uint8 u8ILoop;
	uint8 u8JLoop;
	PduIdType id;
	PduInfoType info;
	Dcm_SchedulerTableType* pScheduler = NULL_PTR;
	const Dcm_DslMainConnectionType* pMainConnection = NULL_PTR;
	const Dcm_DslPeriodicConnectionType* pPeriodicConnection = NULL_PTR;

	for(u8ILoop = 0u; u8ILoop < Dcm_PeriodicTransStatus.PDidNum;)
	{
		pScheduler = &Dcm_PeriodicTransStatus.SchedulerTable[u8ILoop];

		/**
		 * @req [SWS_Dcm_00123] Periodic transmission communication shall only take place in Full
		 * 		Communication Mode.
		 *
		 * @req [SWS_Dcm_00126] Periodic transmission events shall not activate the Full Communication
		 * 		Mode.
		 */
		if(DCM_COMM_FULL_COMMUNICATION == Dcm_ComMStatus[pScheduler->MainConIndex].CommunicationState)
		{
			if(0u < pScheduler->Timer)
			{
				pScheduler->Timer -= DCM_TASK_TIME;
			}

			if(0u == pScheduler->Timer)
			{
				if((Std_ReturnType)E_OK == DspInternal_PeriodicTransProcess(pScheduler))
				{
					info.SduLength = (PduLengthType)(pScheduler->DataLen + 1u);
					info.SduDataPtr = pScheduler->DidData;

					pMainConnection = &Dcm_ConfigPtr->DcmDslMainConnection[pScheduler->MainConIndex];

					for(u8JLoop = 0u; u8JLoop < pMainConnection->DcmDslPeriodicConnectionNum; u8JLoop++)
					{
						pPeriodicConnection = &pMainConnection->DcmDslPeriodicConnection[u8JLoop];

						u8Bit = (uint8)(pPeriodicConnection->DcmDslPeriodicTxConfirmationPduId - DCM_DSL_PROTOCOL_TX_NUM);

						/**
						 * @req [SWS_Dcm_01101] All periodic responses (scheduled responses, not the
						 * 		initial response) will use dedicated IF-PDU's and transmission will be
						 * 		done through PduR. Each time PduR_DcmTransmit is called the data pointer
						 * 		shall be valid.
						 *
						 * @req [SWS_Dcm_01103] The Dcm shall not trigger a transmission request to the
						 * 		PduR unless the transmit confirmation for the previously transmitted
						 * 		periodic response is received.
						 */
						if(!DCM_CHECK_BIT_SET(Dcm_PeriodicTransStatus.ChannelStatus, u8Bit, uint16))
						{
							id = pPeriodicConnection->DcmDslPeriodicTxPduRef;

							if((Std_ReturnType)E_OK == PduR_DcmTransmit(id, &info))
							{
								/**
								 * @req [SWS_Dcm_01102] After triggering the transmission request to the
								 * 		PduR the corresponding periodicDID counter shall be reloaded.
								 */
								pScheduler->Timer = pScheduler->Rate;

								DCM_BIT_SET(Dcm_PeriodicTransStatus.ChannelStatus, u8Bit, uint16);

								break;
							}
						}
					}
					if(pMainConnection->DcmDslPeriodicConnectionNum == u8JLoop)
					{
						DspInternal_ReSortSchedulerTable(u8ILoop);
					}
				}
				else
				{
					DspInternal_ReSortSchedulerTable(u8ILoop);
				}
			}

			u8ILoop++;
		}
		/**
		 * @req [SWS_Dcm_00125] The Dcm module shall discard periodic transmission events beside Full
		 * 		Communication Mode and shall not queue it for transmission.
		 */
		else
		{
			DspInternal_DeletePeriodicDid(u8ILoop);
		}
	}

	Dcm_PeriodicTransStatus.PDidInsertIndex = 0u;
}
#endif /* #if(STD_ON == DCM_UDS0x2A_ENABLE) */

#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#ifdef __cplusplus
}
#endif
/** @} */
