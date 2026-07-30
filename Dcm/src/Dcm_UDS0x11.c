/**
 * @file        Dcm_UDS0x11.c
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

/* PRQA S 0292, 0857, 0491, 2981, 3415, 5087, 2992, 2880, 2742 EOF #
 *
 * 1.0292 -- Violates MISRA 2004 Required Rule 3.1, Source file has comments containing one of the
 * characters '$', '@' or '`'.
 *
 * 2.0857 -- Violates MISRA 2004 Required Rule 1.1, Number of macro definitions exceeds 1024 - program
 * does not conform strictly to ISO:C90.
 *
 * 3.0497 -- Violates MISRA 2004 Required Rule 17.4, Array subscripting applied to an object of pointer
 * type.
 *
 * 4.2981 -- Violates MISRA 2004 Required Rule 21.1, This initialization is redundant. The value of this
 * object is never used before being modified.
 *
 * 5.3415 -- Violates MISRA 2004 Required Rule 12.4, Right hand operand of '&&' or '||' is an expression
 * with persistent side effects.
 *
 * 6.5087 -- Violates MISRA 2004 Required Rule 19.1, Use of #include directive after code fragment.
 *
 * 7.2992 -- Violates MISRA 2004 Required Rule 13.7, The value of this 'if' controlling expression is
 * always 'false'.
 *
 * 8.2880 -- Violates MISRA 2004 Required Rule 14.1, This code is unreachable.
 *
 * 9.2742 -- Violates MISRA 2004 Required Rule 14.1, This 'if' controlling expression is a constant
 * expression and its value is 'false'.
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

#if(STD_ON == DCM_UDS0x11_ENABLE)
#if(STD_ON == DCM_UDS0x11_INTERNAL_FNC_ENABLE)
/**
 * @req [SWS_Dcm_00260]	The Dcm module shall implement the UDS Service ECUReset (0x11).
 */
/*====================================================================================================*
 *                                  SOURCE FILE VERSION INFORMATION
 *====================================================================================================*/
#define DCM_UDS0X11_VENDOR_ID_C                            	(0x00U)
#define DCM_UDS0X11_AR_RELEASE_MAJOR_VERSION_C             	(0x04U)
#define DCM_UDS0X11_AR_RELEASE_MINOR_VERSION_C             	(0x02U)
#define DCM_UDS0X11_AR_RELEASE_REVISION_VERSION_C          	(0x02U)
#define DCM_UDS0X11_SW_MAJOR_VERSION_C                     	(0x01U)
#define DCM_UDS0X11_SW_MINOR_VERSION_C                     	(0x02U)
#define DCM_UDS0X11_SW_PATCH_VERSION_C                     	(0x00U)
/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/
/* Check if current file and Dcm_Internal header file are of the same vendor */
#if(DCM_UDS0X11_VENDOR_ID_C != DCM_INTERNAL_VENDOR_ID )
#error "Dcm_UDS0x11.c and Dcm_Internal.h have different vendor id"
#endif
/* Check if current file and Dcm_Internal header file are of the same Autosar version */
#if(\
		(DCM_UDS0X11_AR_RELEASE_MAJOR_VERSION_C != DCM_INTERNAL_AR_RELEASE_MAJOR_VERSION) || \
		(DCM_UDS0X11_AR_RELEASE_MINOR_VERSION_C != DCM_INTERNAL_AR_RELEASE_MINOR_VERSION) || \
		(DCM_UDS0X11_AR_RELEASE_REVISION_VERSION_C != DCM_INTERNAL_AR_RELEASE_REVISION_VERSION) \
)
#error "AutoSar Version Number of Dcm_UDS0x11.c and Dcm_Internal.h are different"
#endif
/* Check if current file and Dcm_Internal header file are of the same software version */
#if(\
		(DCM_UDS0X11_SW_MAJOR_VERSION_C != DCM_INTERNAL_SW_MAJOR_VERSION) || \
		(DCM_UDS0X11_SW_MINOR_VERSION_C != DCM_INTERNAL_SW_MINOR_VERSION) || \
		(DCM_UDS0X11_SW_PATCH_VERSION_C != DCM_INTERNAL_SW_PATCH_VERSION) \
)
#error "Software Version Number of Dcm_UDS0x11.c and Dcm_Internal.h are different"
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

STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x11SetProgConditionsHandle
(
	uint8 u8SubServiceId,
	uint8 u8ConnectionId,
	Dcm_OpStatusType opState,
	P2CONST(Dcm_MsgContextType, AUTOMATIC, DCM_CONST)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
);
/*====================================================================================================*
 *                                           LOCAL FUNCTIONS
 *====================================================================================================*/
/**
 * @brief			Dcm_UDS0x11SetProgConditionsHandle
 * @details			Store relevant conditional information when reset ECU.
 *
 * @param[in]		u8SubServiceId:Sub function identifier.
 * @param[in]		u8ConnectionId:The index of the used connection within the configuration.
 * @param[in]		opState:Operating state.
 * @param[in]		pMsgContext:Message-related information for one diagnostic protocol identifier.
 *
 * @param[out]		pErrorCode:If the called external interface returns E_NOT_OK, use this pointer to
 * 					output the NRC.
 *
 * @return        	Result of this operation.
 * @retval			E_OK:Processing successful.
 * @retval			E_NOT_OK:Processing failure.
 */
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x11SetProgConditionsHandle
(
	uint8 u8SubServiceId,
	uint8 u8ConnectionId,
	Dcm_OpStatusType opState,
	P2CONST(Dcm_MsgContextType, AUTOMATIC, DCM_CONST)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
)
{
	Std_ReturnType result = (Std_ReturnType)E_NOT_OK;

	Dcm_ProgConditionsType ProgConditions;

	if((DCM_INITIAL == opState) &&\
		((boolean)TRUE == Dcm_ConfigPtr->DcmDsl->DcmDslProtocolRow[Dcm_ActiveProRowIdx].DcmSendRespPendOnTransToBoot))
	{
		Dcm_OpState = DCM_FORCE_RCRRP_OK;
		*pErrorCode = DCM_E_RESPONSE_PENDING;
	}
	else
	{
		if((DCM_AFTER_RESET == DCM_RESPONSE_TO_ECU_RESET) && ((DCM_INITIAL != opState) || (DCM_CHECK_BIT_SET(pMsgContext->MsgAddInfo, 1u, uint8))))
		{
			ProgConditions.ResponseRequired = (boolean)TRUE;
		}
		else
		{
			ProgConditions.ResponseRequired = (boolean)FALSE;
		}

		ProgConditions.Sid = 0x11u;
		ProgConditions.SubFncId = u8SubServiceId;
		ProgConditions.ConnectionId = u8ConnectionId;
		ProgConditions.ReprogramingRequest = (boolean)FALSE;

		result = Dcm_SetProgConditions(opState, &ProgConditions);

		if((Std_ReturnType)E_OK == result)
		{
			/**
			 * @req [SWS_Dcm_00373] On reception of a request for UDS Service 0x11 with the sub
			 * 		functions other than enableRapidPowerShutDown (0x04) or disableRapidPowerShutDown
			 * 		(0x05), the DCM module shall trigger the mode switch of
			 * 		ModeDeclarationGroupPrototype DcmEcuReset equal to the received resetType. After the
			 * 		mode switch is requested the DCM shall trigger the start of the positive response
			 * 		message transmission: Sub function hardReset (0x01) to HARD, Sub function
			 * 		keyOffOnReset (0x02) to KEYONOFF, Sub function softReset (0x03) to SOFT.
			 *
			 * @req [SWS_Dcm_00818] On reception of a request for UDS Service 0x11 with the sub
			 * 		functions enableRapidPowerShutdown (0x04) or disableRapidPowerShutdown (0x05), the
			 * 		DCM module shall trigger the mode switch of ModeDeclarationGroupPrototype
			 * 		DcmRapidPowerShutDown: Sub function enableRapidPowerShutDown (0x04) to
			 * 		ENABLE_RAPIDPOWERSHUTDOWN, Sub function disableRapidPowerShutDown (0x05) to
			 * 		DISABLE_RAPIDPOWERSHUTDOWN.
			 */
			switch(u8SubServiceId)
			{
				case 0x01u:
				case 0x02u:
				case 0x03u:
					SchM_Switch_DcmEcuReset(u8SubServiceId);
					break;
				case 0x04u:
				case 0x05u:
					SchM_Switch_DcmRapidPowerShutDown(u8SubServiceId);
					break;
				default:
					/* Nothing to do here. */
					break;
			}


			if(DCM_AFTER_RESET == DCM_RESPONSE_TO_ECU_RESET)
			{
				SchM_Switch_DcmEcuReset(RTE_MODE_DcmEcuReset_EXECUTE);
			}
		}
		else
		{
			if((Std_ReturnType)DCM_E_PENDING == result)
			{
				Dcm_OpState = DCM_PENDING;
				*pErrorCode = DCM_E_RESPONSE_PENDING;
			}
			else if((Std_ReturnType)DCM_E_FORCE_RCRRP == result)
			{
				Dcm_OpState = DCM_FORCE_RCRRP_OK;
				*pErrorCode = DCM_E_RESPONSE_PENDING;
			}
			else
			{
				*pErrorCode = DCM_E_CONDITIONSNOTCORRECT;
			}

			result = (Std_ReturnType)E_NOT_OK;
		}
	}

	return result;
}
/*====================================================================================================*
 *                                          GLOBAL FUNCTIONS
 *====================================================================================================*/
/**
 * @brief			Dcm_UDS0x11
 * @details			Internal processing interface for Service 0x11.
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
FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x11
(
	Dcm_OpStatusType OpStatus,
	P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
)
{
	Std_ReturnType result = (Std_ReturnType)E_NOT_OK;

	uint8 u8AddrType;
	uint8 u8SubServiceId;
	uint8 u8ConIdx = Dcm_ActiveConIdx;
	const Dcm_DsdServiceType* pService = NULL_PTR;

	if(2u != pMsgContext->ReqDataLen)
	{
		*ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
	}
	else
	{
		u8SubServiceId = pMsgContext->ReqData[1];

		u8AddrType = (pMsgContext->MsgAddInfo & 0x01u);

		pService = DCM_GET_SERVICE_PTR(Dcm_ConnectionStatus[u8ConIdx].ServiceIdx);

		if(((Std_ReturnType)E_OK == DspInternal_SubServiceCheck(u8AddrType, u8SubServiceId, pService, ErrorCode))\
			&& ((Std_ReturnType)E_OK == Dcm_UDS0x11SetProgConditionsHandle(u8SubServiceId, u8ConIdx, OpStatus,\
			pMsgContext, ErrorCode)))
		{
			/* The minimum length of the buffer is 8 bytes, no need to check the response length. */

			pMsgContext->ResData[0] = 0x51u;
			pMsgContext->ResData[1] = u8SubServiceId;
			pMsgContext->ResDataLen = 2u;

#ifdef DCM_DSP_POWER_DOWN_TIME
			/**
			 * @req [SWS_Dcm_00589] In case the parameter DcmDspPowerDownTime is present, the DCM shall
			 * 		set the powerDownTime in positive response to sub-service enableRapidPowerShutDown
			 * 		with value set in DcmDspPowerDownTime.
			 */
			if((uint8)0x04 == u8SubServiceId)
			{
				pMsgContext->ResData[2] = DCM_DSP_POWER_DOWN_TIME;
				pMsgContext->ResDataLen = 3u;
			}
#endif /* #ifdef DCM_DSP_POWER_DOWN_TIME */

			result = (Std_ReturnType)E_OK;
		}
	}

	return result;
}

#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#endif /* #if(STD_ON == DCM_UDS0x11_INTERNAL_FNC_ENABLE) */
#endif /* #if(STD_ON == DCM_UDS0x11_ENABLE) */

#ifdef __cplusplus
}
#endif
/** @} */
