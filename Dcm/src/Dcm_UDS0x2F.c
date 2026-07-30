/**
 * @file        Dcm_UDS0x2F.c
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

/* PRQA S 0292, 0857, 0491, 2981, 2985, 0488, 5087 EOF #
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
 * 5.2985 -- Violates MISRA 2004 Required Rule 21.1, This operation is redundant. The value of the
 * result is always that of the left-hand operand.
 *
 * 6.0488 -- Violates MISRA 2004 Required Rule 17.4, Performing pointer arithmetic.
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

#if(STD_ON == DCM_UDS0x2F_ENABLE)
#if(STD_ON == DCM_UDS0x2F_INTERNAL_FNC_ENABLE)
/**
 * @req [SWS_Dcm_00256] The Dcm module shall implement the UDS Service InputOutputControlByIdentifier
 * 		(0x2F).
 *
 * @req [SWS_Dcm_00579] The Dcm shall support InputOutputControlParameter definitions.
 */
/*====================================================================================================*
 *                                  SOURCE FILE VERSION INFORMATION
 *====================================================================================================*/
#define DCM_UDS0X2F_VENDOR_ID_C                            	(0x00U)
#define DCM_UDS0X2F_AR_RELEASE_MAJOR_VERSION_C             	(0x04U)
#define DCM_UDS0X2F_AR_RELEASE_MINOR_VERSION_C             	(0x02U)
#define DCM_UDS0X2F_AR_RELEASE_REVISION_VERSION_C          	(0x02U)
#define DCM_UDS0X2F_SW_MAJOR_VERSION_C                     	(0x01U)
#define DCM_UDS0X2F_SW_MINOR_VERSION_C                     	(0x02U)
#define DCM_UDS0X2F_SW_PATCH_VERSION_C                     	(0x00U)
/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/
/* Check if current file and Dcm_Internal header file are of the same vendor */
#if(DCM_UDS0X2F_VENDOR_ID_C != DCM_INTERNAL_VENDOR_ID )
#error "Dcm_UDS0x2F.c and Dcm_Internal.h have different vendor id"
#endif
/* Check if current file and Dcm_Internal header file are of the same Autosar version */
#if(\
		(DCM_UDS0X2F_AR_RELEASE_MAJOR_VERSION_C != DCM_INTERNAL_AR_RELEASE_MAJOR_VERSION) || \
		(DCM_UDS0X2F_AR_RELEASE_MINOR_VERSION_C != DCM_INTERNAL_AR_RELEASE_MINOR_VERSION) || \
		(DCM_UDS0X2F_AR_RELEASE_REVISION_VERSION_C != DCM_INTERNAL_AR_RELEASE_REVISION_VERSION) \
)
#error "AutoSar Version Number of Dcm_UDS0x2F.c and Dcm_Internal.h are different"
#endif
/* Check if current file and Dcm_Internal header file are of the same software version */
#if(\
		(DCM_UDS0X2F_SW_MAJOR_VERSION_C != DCM_INTERNAL_SW_MAJOR_VERSION) || \
		(DCM_UDS0X2F_SW_MINOR_VERSION_C != DCM_INTERNAL_SW_MINOR_VERSION) || \
		(DCM_UDS0X2F_SW_PATCH_VERSION_C != DCM_INTERNAL_SW_PATCH_VERSION) \
)
#error "Software Version Number of Dcm_UDS0x2F.c and Dcm_Internal.h are different"
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
 * @brief	Store internal status of service 0x2F during its processing.
 */
STATIC VAR(Dcm_InputOutputControlByDidStatusType, DCM_VAR)Dcm_UDS0x2FStatus;

#define DCM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dcm_MemMap.h"
/*====================================================================================================*
 *                                      LOCAL FUNCTION PROTOTYPES
 *====================================================================================================*/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"

#if(0u != DCM_DSP_DID_NUM)
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x2FReqDidCheck
(
	P2VAR(uint8, AUTOMATIC, DCM_VAR)pReqDidIdx,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
);

STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x2FReqDataLenCheck
(
	uint8 u8ReqDidIdx,
	P2CONST(Dcm_MsgContextType, AUTOMATIC, DCM_CONST)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
);

#if(0u != DCM_DSP_DID_SIGNAL_NUM)
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x2FControlProcess
(
	Dcm_OpStatusType opState,
	P2CONST(Dcm_DspDidSignalType, AUTOMATIC, DCM_CONST)pDidSignal,
	P2CONST(Dcm_DspDidControlType, AUTOMATIC, DCM_CONST)pDidControl,
	P2CONST(Dcm_MsgContextType, AUTOMATIC, DCM_CONST)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
);

STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x2FReadProcess
(
	Dcm_OpStatusType opState,
	P2CONST(Dcm_DspDidSignalType, AUTOMATIC, DCM_CONST)pDidSignal,
	P2CONST(Dcm_MsgContextType, AUTOMATIC, DCM_CONST)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
);
#endif /* #if(0u != DCM_DSP_DID_SIGNAL_NUM) */

STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x2FControlAndReadHandle
(
	uint8 u8ReqDidIdx,
	Dcm_OpStatusType opState,
	P2CONST(Dcm_MsgContextType, AUTOMATIC, DCM_CONST)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
);
#endif /* #if(0u != DCM_DSP_DID_NUM) */

STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x2FDidProcess
(
	Dcm_OpStatusType opState,
	P2CONST(Dcm_MsgContextType, AUTOMATIC, DCM_CONST)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
);
/*====================================================================================================*
 *                                           LOCAL FUNCTIONS
 *====================================================================================================*/
#if(0u != DCM_DSP_DID_NUM)
/**
 * @brief			Dcm_UDS0x2FReqDidCheck
 * @details			Check whether the requested Did is valid.
 *
 * @param[out]		pReqDidIdx:If the requested Did is valid, output its index within the configuration.
 * @param[out]		pErrorCode:If error occur, output the NRC.
 *
 * @return        	Result of this operation.
 * @retval			E_OK:Processing successful.
 * @retval			E_NOT_OK:Processing failure.
 */
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x2FReqDidCheck
(
	P2VAR(uint8, AUTOMATIC, DCM_VAR)pReqDidIdx,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
)
{
	Std_ReturnType result;

	uint16 u16ReqDid = Dcm_UDS0x2FStatus.ReqDid;
	uint8 u8ControlType = Dcm_UDS0x2FStatus.ControlType;
	const Dcm_DspDidControlType* pDidControl = NULL_PTR;

	/**
	 * @req [SWS_Dcm_00563] On reception of the UDS Service InputOutputControlByIdentifier (0x2F), the
	 * 		DCM module shall check if the DID is supported (see configuration parameter DcmDspDid) If
	 * 		not, the DCM module shall send NRC 0x31 (Request out of range).
	 */
#if((STD_ON == DCM_UDS0x2C_ENABLE) || (STD_ON == DCM_UDS0x2A_ENABLE))
	result = DspInternal_CheckDidValid(\
				u16ReqDid, DCM_PERMISSION_CHECK_USER_CONTROL_DID, pReqDidIdx, NULL_PTR, NULL_PTR, pErrorCode\
				);
#else
	result = DspInternal_CheckDidValid(\
				u16ReqDid, DCM_PERMISSION_CHECK_USER_CONTROL_DID, pReqDidIdx, pErrorCode\
				);
#endif /* #if((STD_ON == DCM_UDS0x2C_ENABLE) || (STD_ON == DCM_UDS0x2A_ENABLE)) */

	if((Std_ReturnType)E_OK == result)
	{
		pDidControl = Dcm_ConfigPtr->DcmDsp->DcmDspDid[*pReqDidIdx].DcmDspDidInfoRef->DcmDspDidControl;

		if(((0x01u == u8ControlType) && ((boolean)FALSE == pDidControl->DcmDspDidResetToDefault)) ||\
			((0x02u == u8ControlType) && ((boolean)FALSE == pDidControl->DcmDspDidFreezeCurrentState)) ||\
			((0x03u == u8ControlType) && ((boolean)FALSE == pDidControl->DcmDspDidShortTermAdjustment)) ||\
			(0x03u < u8ControlType))
		{
			*pErrorCode = DCM_E_REQUESTOUTOFRANGE;

			result = (Std_ReturnType)E_NOT_OK;
		}
	}

	return result;
}

/**
 * @brief			Dcm_UDS0x2FReqDataLenCheck
 * @details			Check whether the request length is correct.
 *
 * @param[in]		u8ReqDidIdx:The index of the Did to be control within the configuration.
 * @param[in]		pMsgContext:Message-related information for one diagnostic protocol identifier.
 *
 * @param[out]		pErrorCode:If error occur, output the NRC.
 *
 * @return        	Result of this operation.
 * @retval			E_OK:Processing successful.
 * @retval			E_NOT_OK:Processing failure.
 */
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x2FReqDataLenCheck
(
	uint8 u8ReqDidIdx,
	P2CONST(Dcm_MsgContextType, AUTOMATIC, DCM_CONST)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
)
{
	Std_ReturnType result = (Std_ReturnType)E_NOT_OK;

	uint8 u8Index;
	uint32 u32ReqMask = 0u;
	uint32 u32MaskOffset = 0u;
	uint32 u32ReqDataLen = 4u;
	const Dcm_DspDidType* pDid = &Dcm_ConfigPtr->DcmDsp->DcmDspDid[u8ReqDidIdx];
	const Dcm_DspDidControlType* pDidControl = pDid->DcmDspDidInfoRef->DcmDspDidControl;

	if(0x03u == Dcm_UDS0x2FStatus.ControlType)
	{
		for(u8Index = 0u; u8Index < pDid->DcmDspDidSignalNum; u8Index++)
		{
			u32ReqDataLen += ((uint32)pDid->DcmDspDidSignal[u8Index].DcmDspDidDataRef->DcmDspDataSize / 8u);
		}
	}

	/**
	 * @req [SWS_Dcm_01273] If the configuration parameter DcmDspDidControlMask is set to
	 * 		DCM_CONTROLMASK_EXTERNAL or DCM_CONTROLMASK_INTERNAL, or the DcmDspData element used in
	 * 		service 0x2F has DcmDspDataUsePorts set to USE_DATA_SENDER_RECEIVER or to
	 * 		USE_DATA_SENDER_RECEIVER_AS_SERVICE, the Dcm shall reject request without included control
	 * 		enable mask record with the NRC 0x13 (incorrectMessageLengthOrInvalidFormat).
	 */
	if(DCM_CONTROLMASK_NO != pDidControl->DcmDspDidControlMask)
	{
		u32MaskOffset = u32ReqDataLen;

		u32ReqDataLen += pDidControl->DcmDspDidControlMaskSize;
	}

	/**
	 * @req [SWS_Dcm_01274] If the configuration parameter DcmDspDidControlMask is set to
	 * 		DCM_CONTROLMASK_NO, the Dcm shall reject request with included control enable mask record
	 * 		with the NRC 0x13 (incorrectMessageLengthOrInvalidFormat).
	 */
	if(u32ReqDataLen != pMsgContext->ReqDataLen)
	{
		*pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
	}
	else
	{
		if(DCM_CONTROLMASK_NO != pDidControl->DcmDspDidControlMask)
		{
			for(u8Index = 0u; u8Index < pDidControl->DcmDspDidControlMaskSize; u8Index++)
			{
				u32ReqMask <<= 8u;
				u32ReqMask |= (uint32)pMsgContext->ReqData[u32MaskOffset + u8Index];
			}

			Dcm_UDS0x2FStatus.ReqMask = u32ReqMask;
		}

		result = (Std_ReturnType)E_OK;
	}

	return result;
}

#if(0u != DCM_DSP_DID_SIGNAL_NUM)
/**
 * @brief			Dcm_UDS0x2FControlProcess
 * @details			Compare the mask and execute the control process.
 *
 * @param[in]		opState:Operating state.
 * @param[in]		pDidSignal:Relevant configuration parameters of the used Did Signal.
 * @param[in]		pDidControl:Relevant configuration parameters of the used Did Control.
 * @param[in]		pMsgContext:Message-related information for one diagnostic protocol identifier.
 *
 * @param[out]		pErrorCode:If error occur, output the NRC.
 *
 * @return        	Result of this operation.
 * @retval			E_OK:Processing successful.
 * @retval			E_NOT_OK:Processing failure.
 */
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x2FControlProcess
(
	Dcm_OpStatusType opState,
	P2CONST(Dcm_DspDidSignalType, AUTOMATIC, DCM_CONST)pDidSignal,
	P2CONST(Dcm_DspDidControlType, AUTOMATIC, DCM_CONST)pDidControl,
	P2CONST(Dcm_MsgContextType, AUTOMATIC, DCM_CONST)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
)
{
	Std_ReturnType result = (Std_ReturnType)E_OK;

	uint8 u8BitOffset;
	uint8 u8ControlType = Dcm_UDS0x2FStatus.ControlType;
	uint32 u32ReqMask = Dcm_UDS0x2FStatus.ReqMask;
	boolean procState = (boolean)TRUE;
	const Dcm_DspDataType* pSignalData = pDidSignal->DcmDspDidDataRef;

#if(STD_ON == DCM_DSP_DATA_ECU_SIGNAL_FNC_ENABLED)
	uint16 u16Index;
	EcuSignalDataType EcuSignalValue = 0u;
#endif /* #if(STD_ON == DCM_DSP_DATA_ECU_SIGNAL_FNC_ENABLED) */

#if((STD_ON == DCM_DSP_DATA_ECU_SIGNAL_FNC_ENABLED) || (STD_ON == DCM_DSP_DATA_SHORT_TERM_ADJUSTMENT_FNC_ENABLED))
	uint16 u16SignalLen = (pSignalData->DcmDspDataSize / 8u);
	uint8* pReqDataBuf = &pMsgContext->ReqData[(pDidSignal->DcmDspDidDataPos / 8u) + 4u];
#endif /* #if((STD_ON == DCM_DSP_DATA_ECU_SIGNAL_FNC_ENABLED) || (STD_ON == DCM_DSP_DATA_SHORT_TERM_ADJUSTMENT_FNC_ENABLED)) */

	/**
	 * @req [SWS_Dcm_00581] In case of more than one supported I/O signal per DataIdentifier and the
	 * 		configuration parameter DcmDspDidControlMask is set to DCM_CONTROLMASK_INTERNAL, the Dcm
	 * 		shall internally consider the parameter controlEnableMaskRecord and control only the
	 * 		included signals in the request message.
	 */
	if(DCM_CONTROLMASK_INTERNAL == pDidControl->DcmDspDidControlMask)
	{
		u8BitOffset = (uint8)((pDidControl->DcmDspDidControlMaskSize * 8u) - 1u);

		/**
		 * @req [SWS_Dcm_00680] The following mapping shall be used for the controlMask management:
		 * 		First bit of controlMask maps to first DID data element).
		 */
		if((DCM_CHECK_BIT_SET(u32ReqMask, (u8BitOffset - pDidSignal->DcmDspDidSignalIndex), uint32)) &&\
			(DCM_CHECK_BIT_SET(pDidControl->DcmDspDidControlEnableMask, pDidSignal->DcmDspDidSignalIndex, uint32)))
		{
			u32ReqMask = 0xFFFFFFFFu;
		}
		else
		{
			procState = (boolean)FALSE;
		}
	}
	/**
	 * @req [SWS_Dcm_01272] If the configuration parameter DcmDspDidControlMask is set to
	 * 		DCM_CONTROLMASK_EXTERNAL, the control enable mask record shall be forwarded within each
	 * 		interface.
	 */
	else if(DCM_CONTROLMASK_EXTERNAL == pDidControl->DcmDspDidControlMask)
	{
		/* Nothing to do here. */
		;
	}
	else
	{
		/* DcmDspDidControlMask is DCM_CONTROLMASK_NO. */
		u32ReqMask = 0xFFFFFFFFu;
	}

	if((boolean)TRUE == procState)
	{
		result = (Std_ReturnType)E_NOT_OK;

		switch(pSignalData->DcmDspDataUsePort)
		{
#if(STD_ON == DCM_DSP_DATA_ECU_SIGNAL_FNC_ENABLED)
		/**
		 * @req [SWS_Dcm_00580] On reception of a request for UDS Service InputOutputControlByIdentifier
		 * 		(0x2F) , if all verifications have been successfully done (see SWS_Dcm_00563,
		 * 		SWS_Dcm_00565, SWS_Dcm_00566, SWS_Dcm_00567 ) and if the data is configured as a "ECU
		 * 		signal" of the IoHwAb (parameter DcmDspDataUsePort), the DCM shall call the Api
		 * 		IoHwAb_Dcm_<symbolic name of ECU signal (parameter DcmDspDataEcuSignal)>() with
		 * 		InputOutputControlParameter for the 'action' parameter and in case of
		 * 		InputOutputControlParameter is set to 'shortTermAdjustment' the signal value for the
		 * 		"signal" parameter. In this case the requirements SWS_Dcm_00396, SWS_Dcm_00397,
		 * 		SWS_Dcm_00398 and SWS_Dcm_00399 doesn't apply.
		 */
		case DCM_USE_ECU_SIGNAL:
			if(0x04u == u8ControlType)
			{
				for(u16Index = 0u; u16Index < u16SignalLen; u16Index++)
				{
					EcuSignalValue <<= 0u;
					EcuSignalValue |= (EcuSignalDataType)(*(pReqDataBuf + u16Index));
				}
			}
			if(NULL_PTR != pSignalData->DcmDspDataEcuSignal)
			{
				result = pSignalData->DcmDspDataEcuSignal(u8ControlType, EcuSignalValue);
			}
			else
			{
				*pErrorCode = DCM_E_REQUESTOUTOFRANGE;
			}
			break;
#endif /* #if(STD_ON == DCM_DSP_DATA_ECU_SIGNAL_FNC_ENABLED) */
		case DCM_USE_DATA_SYNCH_FNC:
		case DCM_USE_DATA_SYNCH_CLIENT_SERVER:
		case DCM_USE_DATA_ASYNCH_FNC:
		case DCM_USE_DATA_ASYNCH_FNC_ERROR:
		case DCM_USE_DATA_ASYNCH_CLIENT_SERVER:
		case DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR:
			switch(u8ControlType)
			{
#if(STD_ON == DCM_DSP_DATA_RETURN_CONTROL_TO_ECU_FNC_ENABLED)
			/**
			 * @req [SWS_Dcm_00396] On reception of a request for UDS Service
			 * 		InputOutputControlByIdentifier (0x2F) with InputOutputControlParameter equal to
			 * 		returnControlToEcu, if all verifications have been successfully done (see
			 * 		SWS_Dcm_00563, SWS_Dcm_00565, SWS_Dcm_00566, SWS_Dcm_00567 ), the DCM module shall
			 * 		invoke all impacted configured function of the controlEnableMaskRecord (if parameter
			 * 		DcmDspDataUsePort set to USE_DATA_SYNCH_FNC or USE_DATA_ASYNCH_FNC or
			 * 		USE_DATA_ASYNCH_FNC_ERROR; see configuration parameter
			 * 		DcmDspDataReturnControlToEcuFnc). Alternatively call all the associated
			 * 		ReturnControlToECU operations (if parameter DcmDspDataUsePort set to
			 * 		USE_DATA_SYNCH_CLIENT_SERVER or USE_DATA_ASYNCH_CLIENT_SERVER or
			 * 		USE_DATA_ASYNCH_CLIENT_SERVER_ERROR) for every data of the DID received in the
			 * 		request.
			 */
			case 0x00u:
				if(NULL_PTR != pSignalData->DcmDspDataReturnControlToEcuFnc)
				{
					result = pSignalData->DcmDspDataReturnControlToEcuFnc(u32ReqMask, pErrorCode);
				}
				else
				{
					*pErrorCode = DCM_E_REQUESTOUTOFRANGE;
				}
				break;
#endif /* #if(STD_ON == DCM_DSP_DATA_RETURN_CONTROL_TO_ECU_FNC_ENABLED) */
#if(STD_ON == DCM_DSP_DATA_RESET_TO_DEFAULT_FNC_ENABLED)
			/**
			 * @req [SWS_Dcm_00397] On reception of a request for UDS Service
			 * 		InputOutputControlByIdentifier (0x2F) with InputOutputControlParameter equal to
			 * 		resetToDefault, if all verifications have been successfully done (see SWS_Dcm_00563,
			 * 		SWS_Dcm_00565, SWS_Dcm_00566, SWS_Dcm_00567 ), the DCM module shall invoke all
			 * 		impacted configured function of the controlEnableMaskRecord (if parameter
			 * 		DcmDspDataUsePort set to USE_DATA_SYNCH_FNC or USE_DATA_ASYNCH_FNC or
			 * 		USE_DATA_ASYNCH_FNC_ERROR; see configuration parameter DcmDspDataResetToDefaultFnc).
			 * 		Alternatively call all the associated ResetToDefault operations (if parameter
			 * 		DcmDspDataUsePort set to USE_DATA_SYNCH_CLIENT_SERVER or
			 * 		USE_DATA_ASYNCH_CLIENT_SERVER or USE_DATA_ASYNCH_CLIENT_SERVER_ERROR) for every data
			 * 		of the DID received in the request.
			 */
			case 0x01u:
				if(NULL_PTR != pSignalData->DcmDspDataResetToDefaultFnc)
				{
					result = pSignalData->DcmDspDataResetToDefaultFnc(opState, u32ReqMask, pErrorCode);
				}
				else
				{
					*pErrorCode = DCM_E_REQUESTOUTOFRANGE;
				}
				break;
#endif /* #if(STD_ON == DCM_DSP_DATA_RESET_TO_DEFAULT_FNC_ENABLED) */
#if(STD_ON == DCM_DSP_DATA_FREEZE_CURRENT_STATE_FNC_ENABLED)
			/**
			 * @req [SWS_Dcm_00398] On reception of a request for UDS Service
			 * 		InputOutputControlByIdentifier (0x2F) with InputOutputControlParameter equal to
			 * 		freezeCurrentState, if all verifications have been successfully done (see
			 * 		SWS_Dcm_00563, SWS_Dcm_00565, SWS_Dcm_00566, SWS_Dcm_00567 ), the DCM module shall
			 * 		invoke all impacted configured function of the controlEnableMaskRecord (if parameter
			 * 		DcmDspDataUsePort set to USE_DATA_SYNCH_FNC or USE_DATA_ASYNCH_FNC or
			 * 		USE_DATA_ASYNCH_FNC_ERROR; see configuration parameter
			 * 		DcmDspDataFreezeCurrentStateFnc). Alternatively call all the associated
			 * 		FreezeCurrentState operations (if parameter DcmDspDataUsePort set to
			 * 		USE_DATA_SYNCH_CLIENT_SERVER or USE_DATA_ASYNCH_CLIENT_SERVER or
			 * 		USE_DATA_ASYNCH_CLIENT_SERVER_ERROR) for every data of the DID received in the
			 * 		request.
			 */
			case 0x02u:
				if(NULL_PTR != pSignalData->DcmDspDataFreezeCurrentStateFnc)
				{
					result = pSignalData->DcmDspDataFreezeCurrentStateFnc(opState, u32ReqMask, pErrorCode);
				}
				else
				{
					*pErrorCode = DCM_E_REQUESTOUTOFRANGE;
				}
				break;
#endif /* #if(STD_ON == DCM_DSP_DATA_FREEZE_CURRENT_STATE_FNC_ENABLED) */
#if(STD_ON == DCM_DSP_DATA_SHORT_TERM_ADJUSTMENT_FNC_ENABLED)
			/**
			 * @req [SWS_Dcm_00399] On reception of a request for UDS Service
			 * 		InputOutputControlByIdentifier (0x2F) with InputOutputControlParameter equal to
			 * 		shortTermAdjustment, if all verifications have been successfully done (see
			 * 		SWS_Dcm_00563, SWS_Dcm_00565, SWS_Dcm_00566, SWS_Dcm_00567 ), the DCM module shall
			 * 		invoke all impacted configured function of the controlEnableMaskRecord (if parameter
			 * 		DcmDspDataUsePort set to USE_DATA_SYNCH_FNC or USE_DATA_ASYNCH_FNC or
			 * 		USE_DATA_ASYNCH_FNC_ERROR; see configuration parameter
			 * 		DcmDspDataShortTermAdjustmentFnc). Alternatively call all the associated
			 * 		ShortTermAdjustment operations (if parameter DcmDspDataUsePort set to
			 * 		USE_DATA_SYNCH_CLIENT_SERVER or USE_DATA_ASYNCH_CLIENT_SERVER or
			 * 		USE_DATA_ASYNCH_CLIENT_SERVER_ERROR) for every data of the DID received in the
			 * 		request.
			 */
			case 0x03u:
				if(NULL_PTR != pSignalData->DcmDspDataShortTermAdjustmentFnc)
				{
					result = pSignalData->DcmDspDataShortTermAdjustmentFnc(pReqDataBuf, u16SignalLen, opState, u32ReqMask, pErrorCode);
				}
				else
				{
					*pErrorCode = DCM_E_REQUESTOUTOFRANGE;
				}
				break;
#endif /* #if(STD_ON == DCM_DSP_DATA_SHORT_TERM_ADJUSTMENT_FNC_ENABLED) */
			default:
				/* Nothing to do here. */
				break;
			}
			break;
		default:
			*pErrorCode = DCM_E_REQUESTOUTOFRANGE;
			break;
		}
	}

	if((Std_ReturnType)E_OK == result)
	{
		DCM_BIT_CLEAR(Dcm_UDS0x2FStatus.PendStep, 0u, uint8);
	}

	return result;
}

/**
 * @brief			Dcm_UDS0x2FReadProcess
 * @details			Read the signal data after the control process is completed.
 *
 * @param[in]		opState:Operating state.
 * @param[in]		pDidSignal:Relevant configuration parameters of the used Did Signal.
 * @param[in]		pMsgContext:Message-related information for one diagnostic protocol identifier.
 *
 * @param[out]		pErrorCode:If error occur, output the NRC.
 *
 * @return        	Result of this operation.
 * @retval			E_OK:Processing successful.
 * @retval			E_NOT_OK:Processing failure.
 */
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x2FReadProcess
(
	Dcm_OpStatusType opState,
	P2CONST(Dcm_DspDidSignalType, AUTOMATIC, DCM_CONST)pDidSignal,
	P2CONST(Dcm_MsgContextType, AUTOMATIC, DCM_CONST)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
)
{
	Std_ReturnType result = (Std_ReturnType)E_NOT_OK;

	uint8* pResDataBuf = &pMsgContext->ResData[(pDidSignal->DcmDspDidDataPos / 8u) + 4u];
	const Dcm_DspDataType* pSignalData = pDidSignal->DcmDspDidDataRef;
	uint32 u32SignalLen = ((uint32)pSignalData->DcmDspDataSize / 8u);

	switch(pSignalData->DcmDspDataUsePort)
	{
#if(STD_ON == DCM_DSP_DATA_READ_ECU_SIGNAL_FNC_ENABLED)
	case DCM_USE_ECU_SIGNAL:
		if(NULL_PTR != pSignalData->DcmDspDataReadEcuSignal)
		{
			if(pMsgContext->ResMaxDataLen >= (pMsgContext->ResDataLen + u32SignalLen))
			{
				result = pSignalData->DcmDspDataReadEcuSignal(pResDataBuf);
			}
			else
			{
				*pErrorCode = DCM_E_RESPONSETOOLONG;
			}
		}
		else
		{
			*pErrorCode = DCM_E_REQUESTOUTOFRANGE;
		}
		break;
#endif /* #if(STD_ON == DCM_DSP_DATA_READ_ECU_SIGNAL_FNC_ENABLED) */
#if(STD_ON == DCM_DSP_DATA_READ_FNC_ENABLED)
	case DCM_USE_DATA_SYNCH_FNC:
	case DCM_USE_DATA_SYNCH_CLIENT_SERVER:
	case DCM_USE_DATA_ASYNCH_FNC:
	case DCM_USE_DATA_ASYNCH_FNC_ERROR:
	case DCM_USE_DATA_ASYNCH_CLIENT_SERVER:
	case DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR:
#if(STD_ON == DCM_DSP_DATA_CONDITION_CHECK_READ_FNC_ENABLED)
		result = (Std_ReturnType)E_OK;

		if((boolean)TRUE == pSignalData->DcmDspDataConditionCheckReadFncUsed)
		{
			result = pSignalData->DcmDspDataConditionCheckReadFnc(opState, pErrorCode);
		}

		if((Std_ReturnType)E_OK == result)
		{
#endif /* #if(STD_ON == DCM_DSP_DATA_CONDITION_CHECK_READ_FNC_ENABLED) */
			result = (Std_ReturnType)E_NOT_OK;

			if(NULL_PTR != pSignalData->DcmDspDataReadFnc)
			{
				if(pMsgContext->ResMaxDataLen >= (Dcm_UDS0x2FStatus.DataTotalLen + u32SignalLen))
				{
					if((DCM_USE_DATA_ASYNCH_FNC_ERROR == pSignalData->DcmDspDataUsePort) ||\
						(DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR == pSignalData->DcmDspDataUsePort))
					{
						result = pSignalData->DcmDspDataReadFnc(opState, pResDataBuf, pErrorCode);
					}
					else
					{
						result = pSignalData->DcmDspDataReadFnc(opState, pResDataBuf, NULL_PTR);
					}
				}
				else
				{
					*pErrorCode = DCM_E_RESPONSETOOLONG;
				}
			}
			else
			{
				*pErrorCode = DCM_E_REQUESTOUTOFRANGE;
			}
#if(STD_ON == DCM_DSP_DATA_CONDITION_CHECK_READ_FNC_ENABLED)
		}
#endif /* #if(STD_ON == DCM_DSP_DATA_CONDITION_CHECK_READ_FNC_ENABLED) */
		break;
#endif /* #if(STD_ON == DCM_DSP_DATA_READ_FNC_ENABLED) */
	default:
		*pErrorCode = DCM_E_REQUESTOUTOFRANGE;
		break;
	}

	if((Std_ReturnType)E_OK == result)
	{
		Dcm_UDS0x2FStatus.DataTotalLen += u32SignalLen;

		Dcm_UDS0x2FStatus.PendStep = 0xFFu;
	}

	return result;
}
#endif /* #if(0u != DCM_DSP_DID_SIGNAL_NUM) */

/**
 * @brief			Dcm_UDS0x2FControlAndReadHandle
 * @details			Check the mask and execute the corresponding main handler. After processing is
 * 					complete, retrieve the Did data.
 *
 * @param[in]		u8ReqDidIdx:The index of the Did to be control within the configuration.
 * @param[in]		opState:Operating state.
 * @param[in]		pMsgContext:Message-related information for one diagnostic protocol identifier.
 *
 * @param[out]		pErrorCode:If error occur, output the NRC.
 *
 * @return        	Result of this operation.
 * @retval			E_OK:Processing successful.
 * @retval			E_NOT_OK:Processing failure.
 */
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x2FControlAndReadHandle
(
	uint8 u8ReqDidIdx,
	Dcm_OpStatusType opState,
	P2CONST(Dcm_MsgContextType, AUTOMATIC, DCM_CONST)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
)
{
#if(0u != DCM_DSP_DID_SIGNAL_NUM)

	Std_ReturnType result = (Std_ReturnType)E_OK;

	uint8 u8Index;
	const Dcm_DspDidType* pDid = &Dcm_ConfigPtr->DcmDsp->DcmDspDid[u8ReqDidIdx];
	const Dcm_DspDidControlType* pDidControl = pDid->DcmDspDidInfoRef->DcmDspDidControl;
	const Dcm_DspDidSignalType* pDidSignal = NULL_PTR;

	for(u8Index = Dcm_UDS0x2FStatus.ReqSignalIndex; u8Index < pDid->DcmDspDidSignalNum; u8Index++)
	{
		Dcm_UDS0x2FStatus.ReqSignalIndex = u8Index;

		pDidSignal = &pDid->DcmDspDidSignal[u8Index];

		if(DCM_CHECK_BIT_SET(Dcm_UDS0x2FStatus.PendStep, 0u, uint8))
		{
			result = Dcm_UDS0x2FControlProcess(opState, pDidSignal, pDidControl, pMsgContext, pErrorCode);
		}

		if(((Std_ReturnType)E_OK == result) && (DCM_CHECK_BIT_SET(Dcm_UDS0x2FStatus.PendStep, 1u, uint8)))
		{
			result = Dcm_UDS0x2FReadProcess(opState, pDidSignal, pMsgContext, pErrorCode);
		}

		if((Std_ReturnType)E_OK != result)
		{
			break;
		}
	}

	return result;

#else

	*pErrorCode = DCM_E_REQUESTOUTOFRANGE;

	return (Std_ReturnType)E_NOT_OK;

#endif /* #if(0u != DCM_DSP_DID_SIGNAL_NUM) */
}
#endif /* #if(0u != DCM_DSP_DID_NUM) */

/**
 * @brief			Dcm_UDS0x2FDidProcess
 * @details			Check whether the requested Did and the request message length are valid. If valid,
 * 					execute the control and read processes.
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
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x2FDidProcess
(
	Dcm_OpStatusType opState,
	P2CONST(Dcm_MsgContextType, AUTOMATIC, DCM_CONST)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
)
{
	Std_ReturnType result = (Std_ReturnType)E_NOT_OK;

#if(0u != DCM_DSP_DID_NUM)

	uint8 u8ReqDidIdx;

	result = Dcm_UDS0x2FReqDidCheck(&u8ReqDidIdx, pErrorCode);

	if((Std_ReturnType)E_OK == result)
	{
		if(DCM_PENDING != opState)
		{
			result = Dcm_UDS0x2FReqDataLenCheck(u8ReqDidIdx, pMsgContext, pErrorCode);
		}

		if((Std_ReturnType)E_OK == result)
		{
			result = Dcm_UDS0x2FControlAndReadHandle(u8ReqDidIdx, opState, pMsgContext, pErrorCode);
		}
	}

#else

	*pErrorCode = DCM_E_REQUESTOUTOFRANGE;

#endif /* #if(0u != DCM_DSP_DID_NUM) */

	return result;
}
/*====================================================================================================*
 *                                          GLOBAL FUNCTIONS
 *====================================================================================================*/
/**
 * @brief			Dcm_UDS0x2F
 * @details			Internal processing interface for Service 0x2F.
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
FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x2F
(
	Dcm_OpStatusType OpStatus,
	P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
)
{
	Std_ReturnType result = (Std_ReturnType)E_OK;

	if(DCM_PENDING != Dcm_OpState)
	{
		if(4u > pMsgContext->ReqDataLen)
		{
			*ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;

			result = (Std_ReturnType)E_NOT_OK;
		}
		else
		{
			Dcm_UDS0x2FStatus.ReqDid = (uint16)pMsgContext->ReqData[1] << 8u;
			Dcm_UDS0x2FStatus.ReqDid |= (uint16)pMsgContext->ReqData[2];
			Dcm_UDS0x2FStatus.ReqSignalIndex = 0u;
			Dcm_UDS0x2FStatus.ReqMask = 0u;
			Dcm_UDS0x2FStatus.PendStep = 0xFFu;
			Dcm_UDS0x2FStatus.ControlType = pMsgContext->ReqData[3];
			Dcm_UDS0x2FStatus.DataTotalLen = 4u;
		}
	}

	if((Std_ReturnType)E_OK == result)
	{
		result = Dcm_UDS0x2FDidProcess(OpStatus, pMsgContext, ErrorCode);

		if((Std_ReturnType)E_OK == result)
		{
			pMsgContext->ResData[0] = 0x6Fu;
			pMsgContext->ResData[1] = pMsgContext->ReqData[1];
			pMsgContext->ResData[2] = pMsgContext->ReqData[2];
			pMsgContext->ResData[3] = pMsgContext->ReqData[3];

			pMsgContext->ResDataLen = Dcm_UDS0x2FStatus.DataTotalLen;
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

#endif /* #if(STD_ON == DCM_UDS0x2F_INTERNAL_FNC_ENABLE) */
#endif /* #if(STD_ON == DCM_UDS0x2F_ENABLE) */

#ifdef __cplusplus
}
#endif
/** @} */
