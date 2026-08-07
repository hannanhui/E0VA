/**
 * @file        Dcm_UDS0x10.c
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

/* PRQA S 0292, 0288, 0857, 0491, 2981, 3415, 5087 EOF #
 *
 * 1.0292 -- Violates MISRA 2004 Required Rule 3.1, Source file has comments containing one of the
 * characters '$', '@' or '`'.
 *
 * 2.0288 -- Violates MISRA 2004 Required Rule 3.1, Source file has comments containing characters which
 * are not members of the basic source character set.
 *
 * 3.0857 -- Violates MISRA 2004 Required Rule 1.1, Number of macro definitions exceeds 1024 - program
 * does not conform strictly to ISO:C90.
 *
 * 4.0491 -- Violates MISRA 2004 Required Rule 17.4, Array subscripting applied to a function parameter
 * declared as a pointer.
 *
 * 5.2981 -- Violates MISRA 2004 Required Rule 21.1, This initialization is redundant. The value of this
 * object is never used before being modified.
 *
 * 6.3415 -- Violates MISRA 2004 Required Rule 12.4, Right hand operand of '&&' or '||' is an expression
 * with persistent side effects.
 *
 * 7.5087 -- Violates MISRA 2004 Required Rule 19.1, Use of #include directive after code fragment.
 *
 * @page misra_violations MISRA-C:2004 violations
 */

/*====================================================================================================*
 *                                           INCLUDE FILES
 *====================================================================================================*/
#include "Dcm_Internal.h"
#include "mcu.h"
#include "eep_emulation.h"

#ifdef AH_TEST_DCM
#include "TestCode.h"
#endif /* #ifdef AH_TEST_DCM */
#include "ee_config.h"
#include "eep_emulation.h"
#include "trng.h"

#if(STD_ON == DCM_UDS0x10_ENABLE)
#if(STD_ON == DCM_UDS0x10_INTERNAL_FNC_ENABLE)
/**
 * @req [SWS_Dcm_00250] The Dcm module shall implement the UDS Service 0x10.
 *
 * @req [SWS_Dcm_01164] In case the service DiagnosticSessionControl implies an ECU reset, the Dcm
 * 		shall ignore all further requests while that reset is being processed.
 */
/*====================================================================================================*
 *                                  SOURCE FILE VERSION INFORMATION
 *====================================================================================================*/
#define DCM_UDS0X10_VENDOR_ID_C                            	(0x00U)
#define DCM_UDS0X10_AR_RELEASE_MAJOR_VERSION_C             	(0x04U)
#define DCM_UDS0X10_AR_RELEASE_MINOR_VERSION_C             	(0x02U)
#define DCM_UDS0X10_AR_RELEASE_REVISION_VERSION_C          	(0x02U)
#define DCM_UDS0X10_SW_MAJOR_VERSION_C                     	(0x01U)
#define DCM_UDS0X10_SW_MINOR_VERSION_C                     	(0x02U)
#define DCM_UDS0X10_SW_PATCH_VERSION_C                     	(0x00U)
/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/
/* Check if current file and Dcm_Internal header file are of the same vendor */
#if(DCM_UDS0X10_VENDOR_ID_C != DCM_INTERNAL_VENDOR_ID )
#error "Dcm_UDS0x10.c and Dcm_Internal.h have different vendor id"
#endif
/* Check if current file and Dcm_Internal header file are of the same Autosar version */
#if(\
		(DCM_UDS0X10_AR_RELEASE_MAJOR_VERSION_C != DCM_INTERNAL_AR_RELEASE_MAJOR_VERSION) || \
		(DCM_UDS0X10_AR_RELEASE_MINOR_VERSION_C != DCM_INTERNAL_AR_RELEASE_MINOR_VERSION) || \
		(DCM_UDS0X10_AR_RELEASE_REVISION_VERSION_C != DCM_INTERNAL_AR_RELEASE_REVISION_VERSION) \
)
#error "AutoSar Version Number of Dcm_UDS0x10.c and Dcm_Internal.h are different"
#endif
/* Check if current file and Dcm_Internal header file are of the same software version */
#if(\
		(DCM_UDS0X10_SW_MAJOR_VERSION_C != DCM_INTERNAL_SW_MAJOR_VERSION) || \
		(DCM_UDS0X10_SW_MINOR_VERSION_C != DCM_INTERNAL_SW_MINOR_VERSION) || \
		(DCM_UDS0X10_SW_PATCH_VERSION_C != DCM_INTERNAL_SW_PATCH_VERSION) \
)
#error "Software Version Number of Dcm_UDS0x10.c and Dcm_Internal.h are different"
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
		
STATIC void Ecu_Reset(void)
{
			 	uint32 appValFlagData = 0x95279527U;
				EE_WriteRecord(&eeConf,EE_BLOCK_FINGER_AppValFlag,4,&appValFlagData,0,NULL);//?????
				Mcu_PerformReset();
}

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"

STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x10JumpToBootHandle
(
	uint8 u8ConIdx,
	Dcm_DspSessionForBootType type,
	Dcm_OpStatusType opState,
	P2CONST(Dcm_MsgContextType, AUTOMATIC, DCM_CONST)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
);
/*====================================================================================================*
 *                                           LOCAL FUNCTIONS
 *====================================================================================================*/
/**
 * @brief			Dcm_UDS0x10JumpToBootHandle
 * @details			Store relevant conditional information when switching to the programming session.
 *
 * @param[in]		u8ConIdx:The index of the used connection within the configuration.
 * @param[in]		type:The type of Bootloader to switch to and which entity will ultimately respond.
 * @param[in]		pMsgContext:Message-related information for one diagnostic protocol identifier.
 * @param[in]		opState:Operating state.
 *
 * @param[out]		pErrorCode:If the called external interface returns E_NOT_OK, use this pointer to
 * 					output the NRC.
 *
 * @return        	Result of this operation.
 * @retval			E_OK:Processing successful.
 * @retval			E_NOT_OK:Processing failure.
 */
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x10JumpToBootHandle
(
	uint8 u8ConIdx,
	Dcm_DspSessionForBootType type,
	Dcm_OpStatusType opState,
	P2CONST(Dcm_MsgContextType, AUTOMATIC, DCM_CONST)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
)
{
	Std_ReturnType result = (Std_ReturnType)E_NOT_OK;

	boolean jumpFlag = (boolean)TRUE;
	Dcm_ProgConditionsType ProgConditions;

	if(DCM_INITIAL == opState)
	{
		switch(type)
		{
		case DCM_OEM_BOOT:
		case DCM_OEM_BOOT_RESPAPP:
			/**
			 * @req [SWS_Dcm_00532] On reception of service DiagnosticSessionControl if the provided
			 * 		session is used to jump to OEM bootloader (parameter DcmDspSessionForBoot set to
			 * 		DCM_OEM_BOOT or DCM_OEM_BOOT_RESPAPP) the Dcm shall prepare the jump to the OEM
			 * 		bootloader (see SWS_Dcm_00535) by triggering the mode switch of
			 * 		ModeDeclarationGroupPrototype DcmEcuReset to JUMPTOBOOTLOADER.
			 */
			SchM_Switch_DcmEcuReset(RTE_MODE_DcmEcuReset_JUMPTOBOOTLOADER);

			break;
		case DCM_SYS_BOOT:
		case DCM_SYS_BOOT_RESPAPP:
			/**
			 * @req [SWS_Dcm_00592] On reception of service DiagnosticSessionControl if the provided
			 * 		session is used to jump to System Supplier bootloader (parameter
			 * 		DcmDspSessionForBoot set to DCM_SYS_BOOT or DCM_SYS_BOOT_RESPAPP) the Dcm shall
			 * 		prepare the jump to the System Supplier bootloader (see SWS_Dcm_00535) by
			 * 		triggering the mode switch of ModeDeclarationGroupPrototype DcmEcuReset to
			 * 		JUMPTOSYSSUPPLIERBOOTLOADER.
			 */
				Ecu_Reset();
//			SchM_Switch_DcmEcuReset(RTE_MODE_DcmEcuReset_JUMPTOSYSSUPPLIERBOOTLOADER);

			break;
		default:
			jumpFlag = (boolean)FALSE;

			result = (Std_ReturnType)E_OK;
			break;
		}

		/**
		 * @req [SWS_Dcm_00654] In case the ModeDeclarationGroupPrototype DcmEcuReset is switched to
		 * 		mode JUMPTOBOOTLOADER or JUMPTOSYSSUPPLIERBOOTLOADER and the configuration parameter
		 * 		DcmSendRespPendOnTransToBoot is set to TRUE, the DCM shall trigger transmission of NRC
		 * 		0x78 � RCR-RP.
		 *
		 * @req [SWS_Dcm_01177] If the jump to bootloader is requested (see [SWS_Dcm_00532],
		 * 		[SWS_Dcm_00592], the configuration parameter DcmSendRespPendOnTransToBoot is set to TRUE
		 * 		(see [SWS_Dcm_00654]), and the configuration parameter DcmDspSessionForBoot is set to
		 * 		DCM_OEM_BOOT_RESPAPP or DCM_SYS_BOOT_RESPAPP, the Dcm shall initiate the final response
		 * 		after a successful transmission of NRC 0x78 (Response pending).
		 */
		if(((boolean)TRUE == jumpFlag) &&\
			((boolean)TRUE == Dcm_ConfigPtr->DcmDsl->DcmDslProtocolRow[Dcm_ActiveProRowIdx].DcmSendRespPendOnTransToBoot))
		{
			jumpFlag = (boolean)FALSE;

			Dcm_OpState = DCM_FORCE_RCRRP_OK;
			*pErrorCode = DCM_E_RESPONSE_PENDING;
		}
	}

	if(((boolean)TRUE == jumpFlag) && (DCM_NO_BOOT != type))
	{
		/**
		 * @req [SWS_Dcm_01178] In case the ModeDeclarationGroupPrototype DcmEcuReset is switched to
		 * 		mode JUMPTOBOOTLOADER or JUMPTOSYSSUPPLIERBOOTLOADER, the configuration parameter
		 * 		DcmSendRespPendOnTransToBoot is set to FALSE and the configuration parameter
		 * 		DcmDspSessionForBoot is set to DCM_OEM_BOOT_RESPAPP or DCM_SYS_BOOT_RESPAPP , the Dcm
		 * 		shall initiate the final response.
		 */
		if((DCM_OEM_BOOT_RESPAPP == type) || (DCM_SYS_BOOT_RESPAPP == type))
		{
			ProgConditions.ResponseRequired = (boolean)FALSE;

			jumpFlag = (boolean)FALSE;
		}
		else
		{
			if((DCM_INITIAL != opState) || (DCM_CHECK_BIT_SET(pMsgContext->MsgAddInfo, 1u, uint8)))
			{
				ProgConditions.ResponseRequired = (boolean)TRUE;
			}
			else
			{
				ProgConditions.ResponseRequired = (boolean)FALSE;
			}
		}

		ProgConditions.Sid = 0x10u;
		ProgConditions.SubFncId = 0x02u;
		ProgConditions.ConnectionId = u8ConIdx;
		ProgConditions.ReprogramingRequest = (boolean)TRUE;

		/**
		 * @req [SWS_Dcm_00535] If the jump to bootloader is requested (see [SWS_Dcm_00532],
		 * 		[SWS_Dcm_00592], the configuration parameter DcmSendRespPendOnTransToBoot is set to
		 * 		TRUE (see [SWS_Dcm_00654]) and the configuration parameter DcmDspSessionForBoot is
		 * 		set to DCM_OEM_BOOT or DCM_SYS_BOOT, the Dcm shall call Dcm_SetProgConditions() after
		 * 		a successful transmission of NRC 0x78 (Response pending).
		 */
		result = Dcm_SetProgConditions(opState, &ProgConditions);

		if((Std_ReturnType)E_OK == result)
		{
			/**
			 * @req [SWS_Dcm_01163] In the context of a request to jump to the bootloader (see
			 * 		[SWS_Dcm_00532] and [SWS_Dcm_00592]), after Dcm_SetProgConditions() returns
			 * 		E_OK according to [SWS_Dcm_00535], the Dcm shall trigger the mode switch of
			 * 		the ModeDeclarationGroupPrototype DcmEcuReset to EXECUTE.
			 *
			 * @req [SWS_Dcm_01180] If Dcm_SetProgConditions() returns E_OK according to
			 * 		[SWS_Dcm_01179], the Dcm shall trigger the mode switch of the
			 * 		ModeDeclarationGroupPrototype DcmEcuReset to EXECUTE.
			 */
			if((boolean)TRUE == jumpFlag)
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
			/**
			 * @req [SWS_Dcm_01175] In case the ModeDeclarationGroupPrototype DcmEcuReset can not be
			 * 		switched JUMPTOBOOTLOADER or JUMPTOSYSSUPPLIERBOOTLOADER, the Dcm shall answer
			 * 		negatively to the request with NRC 0x22 (Conditions not correct).
			 */
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
 * @brief			Dcm_UDS0x10
 * @details			Internal processing interface for Service 0x10.
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

extern uint32 UpdataTriedCounter;
FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x10
(
	Dcm_OpStatusType OpStatus,
	P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
)
{
	Std_ReturnType result = (Std_ReturnType)E_NOT_OK;

	Dcm_SessionDataType index;
	uint8 u8AddrType;
	uint8 u8SubServiceId;
	uint8 u8ConIdx = Dcm_ActiveConIdx;
	const Dcm_DsdServiceType* pService = NULL_PTR;
	const Dcm_DspSessionRowType* pSessionRow = NULL_PTR;
	
			/*no comm*/
//	Dcm_ProtocolStartState = 1;

	if(2u != pMsgContext->ReqDataLen)
	{
		*ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
	}
	else
	{
		u8SubServiceId = pMsgContext->ReqData[1];

		/**
		 * @req [SWS_Dcm_00307] When responding to UDS Service 0x10, if the requested subfunction value
		 * 		is not configured in the ECU (configuration parameter DcmDspSessionLevel), the DSP
		 * 		submodule shall trigger a negative response with NRC 0x12 (SubFunction not supported).
		 */
		for(index = 0u; index < DCM_DSP_SESSION_ROW_NUM; index++)
		{
			pSessionRow = &Dcm_ConfigPtr->DcmDsp->DcmDspSessionRow[index];
			if(u8SubServiceId == pSessionRow->DcmDspSessionLevel)
			{
				break;
			}
		}
		if(DCM_DSP_SESSION_ROW_NUM == index)
		{
			*ErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
		}
		else
		{
			u8AddrType = (pMsgContext->MsgAddInfo & 0x01u);

			pService = DCM_GET_SERVICE_PTR(Dcm_ConnectionStatus[u8ConIdx].ServiceIdx);

			if(((Std_ReturnType)E_OK == DspInternal_SubServiceCheck(u8AddrType, u8SubServiceId, pService, ErrorCode))\
				&& ((Std_ReturnType)E_OK == Dcm_UDS0x10JumpToBootHandle(u8ConIdx, pSessionRow->DcmDspSessionForBoot,\
				OpStatus, pMsgContext, ErrorCode)))
			{
				/* The minimum length of the buffer is 8 bytes, no need to check the response length. */

				pMsgContext->ResData[0] = 0x50u;
				pMsgContext->ResData[1] = u8SubServiceId;
				pMsgContext->ResData[2] = (uint8)(pSessionRow->DcmDspSessionP2ServerMax >> 8u);
				pMsgContext->ResData[3] = (uint8)(pSessionRow->DcmDspSessionP2ServerMax);
				pMsgContext->ResData[4] = (uint8)((pSessionRow->DcmDspSessionP2StarServerMax / 10u) >> 8u);
				pMsgContext->ResData[5] = (uint8)(pSessionRow->DcmDspSessionP2StarServerMax / 10u);
				pMsgContext->ResDataLen = 6u;

				Dcm_NewActiveSession = u8SubServiceId;
				Dcm_NewActiveSessionIdx = index;

				if(Dcm_NewActiveSession == 0x02)
				{
					uint8 RealLeng = 0;
					EE_ReadRecord(&eeConf,EE_UpdataTriedCounter,4,&UpdataTriedCounter,&RealLeng,NULL_PTR);
					UpdataTriedCounter++;
					EE_WriteRecord(&eeConf,EE_UpdataTriedCounter,4,&UpdataTriedCounter,0,NULL_PTR);
				}
				

				result = (Std_ReturnType)E_OK;
			}
		}
	}

	return result;
}


#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#endif /* #if(STD_ON == DCM_UDS0x10_INTERNAL_FNC_ENABLE) */
#endif /* #if(STD_ON == DCM_UDS0x10_ENABLE) */

#ifdef __cplusplus
}
#endif
/** @} */
