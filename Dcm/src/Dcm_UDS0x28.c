/**
 * @file        Dcm_UDS0x28.c
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

/* PRQA S 0292, 0857, 0491, 2981, 2877, 2995, 5087 EOF #
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
 * 6.2955 -- Violates MISRA 2004 Required Rule 13.7, The result of this logical operation is always
 * 'true'.
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

#if(STD_ON == DCM_UDS0x28_ENABLE)
#if(STD_ON == DCM_UDS0x28_INTERNAL_FNC_ENABLE)
/**
 * @req [SWS_Dcm_00511] The Dcm module shall implement the CommunicationControl (service 0x28) of the
 * 		Unified Diagnostic Services.
 */
/*====================================================================================================*
 *                                  SOURCE FILE VERSION INFORMATION
 *====================================================================================================*/
#define DCM_UDS0X28_VENDOR_ID_C                            	(0x00U)
#define DCM_UDS0X28_AR_RELEASE_MAJOR_VERSION_C             	(0x04U)
#define DCM_UDS0X28_AR_RELEASE_MINOR_VERSION_C             	(0x02U)
#define DCM_UDS0X28_AR_RELEASE_REVISION_VERSION_C          	(0x02U)
#define DCM_UDS0X28_SW_MAJOR_VERSION_C                     	(0x01U)
#define DCM_UDS0X28_SW_MINOR_VERSION_C                     	(0x02U)
#define DCM_UDS0X28_SW_PATCH_VERSION_C                     	(0x00U)
/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/
/* Check if current file and Dcm_Internal header file are of the same vendor */
#if(DCM_UDS0X28_VENDOR_ID_C != DCM_INTERNAL_VENDOR_ID )
#error "Dcm_UDS0x28.c and Dcm_Internal.h have different vendor id"
#endif
/* Check if current file and Dcm_Internal header file are of the same Autosar version */
#if(\
		(DCM_UDS0X28_AR_RELEASE_MAJOR_VERSION_C != DCM_INTERNAL_AR_RELEASE_MAJOR_VERSION) || \
		(DCM_UDS0X28_AR_RELEASE_MINOR_VERSION_C != DCM_INTERNAL_AR_RELEASE_MINOR_VERSION) || \
		(DCM_UDS0X28_AR_RELEASE_REVISION_VERSION_C != DCM_INTERNAL_AR_RELEASE_REVISION_VERSION) \
)
#error "AutoSar Version Number of Dcm_UDS0x28.c and Dcm_Internal.h are different"
#endif
/* Check if current file and Dcm_Internal header file are of the same software version */
#if(\
		(DCM_UDS0X28_SW_MAJOR_VERSION_C != DCM_INTERNAL_SW_MAJOR_VERSION) || \
		(DCM_UDS0X28_SW_MINOR_VERSION_C != DCM_INTERNAL_SW_MINOR_VERSION) || \
		(DCM_UDS0X28_SW_PATCH_VERSION_C != DCM_INTERNAL_SW_PATCH_VERSION) \
)
#error "Software Version Number of Dcm_UDS0x28.c and Dcm_Internal.h are different"
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
#define DCM_START_SEC_VAR_NO_INIT_32
#include "Dcm_MemMap.h"

/**
 * @brief 	Each bit represents a channel, and set to 0 indicates that the channel is disabled for
 * 			application messages and network management messages.
 */
VAR(uint32, DCM_VAR)Dcm_CommunicationState = 0u;

#define DCM_STOP_SEC_VAR_NO_INIT_32
#include "Dcm_MemMap.h"

#define DCM_START_SEC_VAR_INIT_8
#include "Dcm_MemMap.h"

/**
 * @brief 	An array containing all of the communication modes.
 */
STATIC VAR(Dcm_CommunicationModeType, DCM_VAR)Dcm_CommunicationModeTable[6][3] =
{
	{DCM_ENABLE_RX_TX_NORM, DCM_ENABLE_RX_TX_NM, DCM_ENABLE_RX_TX_NORM_NM},
	{DCM_ENABLE_RX_DISABLE_TX_NORM, DCM_ENABLE_RX_DISABLE_TX_NM, DCM_ENABLE_RX_DISABLE_TX_NORM_NM},
	{DCM_DISABLE_RX_ENABLE_TX_NORM, DCM_DISABLE_RX_ENABLE_TX_NM, DCM_DISABLE_RX_ENABLE_TX_NORM_NM},
	{DCM_DISABLE_RX_TX_NORM, DCM_DISABLE_RX_TX_NM, DCM_DISABLE_RX_TX_NORM_NM},
	{DCM_ENABLE_RX_DISABLE_TX_NORM, DCM_ENABLE_RX_DISABLE_TX_NM, DCM_ENABLE_RX_DISABLE_TX_NORM_NM},
	{DCM_ENABLE_RX_TX_NORM, DCM_ENABLE_RX_TX_NM, DCM_ENABLE_RX_TX_NORM_NM}
};

#define DCM_STOP_SEC_VAR_INIT_8
#include "Dcm_MemMap.h"
/*====================================================================================================*
 *                                      LOCAL FUNCTION PROTOTYPES
 *====================================================================================================*/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"

STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x28Sub0x00To0x03Process
(
	uint8 u8SubServiceId,
	P2CONST(Dcm_MsgContextType, AUTOMATIC, DCM_CONST)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
);

#if(0u != DCM_DSP_COM_CONTROL_SUB_NODE_NUM)
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x28Sub0x04And0x05Process
(
	uint8 u8SubServiceId,
	P2CONST(Dcm_MsgContextType, AUTOMATIC, DCM_CONST)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
);
#endif /* #if(0u != DCM_DSP_COM_CONTROL_SUB_NODE_NUM) */
/*====================================================================================================*
 *                                           LOCAL FUNCTIONS
 *====================================================================================================*/
/**
 * @brief			Dcm_UDS0x28Sub0x00To0x03Process
 * @details			Service 0x28 subfunction processing interface, used to handle subfunctions 0x00
 * 					to 0x03.
 *
 * @param[in]		u8SubServiceId:Sub function identifier.
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
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x28Sub0x00To0x03Process
(
	uint8 u8SubServiceId,
	P2CONST(Dcm_MsgContextType, AUTOMATIC, DCM_CONST)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
)
{
	Std_ReturnType result = (Std_ReturnType)E_NOT_OK;

#if((0u != DCM_DSP_COM_CONTROL_ALL_CHANNEL_NUM) || (0u != DCM_DSP_COM_CONTROL_SPECIFIC_CHANNEL_NUM))
	uint8 u8Index;
#endif /* #if((0u != DCM_DSP_COM_CONTROL_ALL_CHANNEL_NUM) || (0u != DCM_DSP_COM_CONTROL_SPECIFIC_CHANNEL_NUM)) */
	uint8 u8ComType;
	uint8 u8SubNetNum;
	Dcm_CommunicationModeType reqMode;
#if(0u != DCM_DSP_COM_CONTROL_ALL_CHANNEL_NUM)
	const Dcm_DspComControlAllChannelType* pAllChannel = NULL_PTR;
#endif /* #if(0u != DCM_DSP_COM_CONTROL_ALL_CHANNEL_NUM) */
#if(0u != DCM_DSP_COM_CONTROL_SPECIFIC_CHANNEL_NUM)
	const Dcm_DspComControlSpecificChannelType* pSpecificChannel = NULL_PTR;
#endif /* #if(0u != DCM_DSP_COM_CONTROL_SPECIFIC_CHANNEL_NUM) */
#if((0u != DCM_DSP_COM_CONTROL_ALL_CHANNEL_NUM) || (0u != DCM_DSP_COM_CONTROL_SPECIFIC_CHANNEL_NUM))
	const Dcm_DspComControlType* pComControl = Dcm_ConfigPtr->DcmDsp->DcmDspComControl;
#endif /* #if((0u != DCM_DSP_COM_CONTROL_ALL_CHANNEL_NUM) || (0u != DCM_DSP_COM_CONTROL_SPECIFIC_CHANNEL_NUM)) */
	const Dcm_DslMainConnectionType* pConnection = &Dcm_ConfigPtr->DcmDslMainConnection[Dcm_ActiveConIdx];

	if(3u != pMsgContext->ReqDataLen)
	{
		*pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
	}
	else
	{
		u8ComType = (pMsgContext->ReqData[2] & 0x03u);
		u8SubNetNum = pMsgContext->ReqData[2] >> 4u;

		if(0x01u <= u8ComType)
		{
			reqMode = Dcm_CommunicationModeTable[u8SubServiceId][u8ComType - 1u];

			/**
			 * @Req [SWS_Dcm_00512] On invocation of the sent confirmation function of the UDS Service
			 * 		CommunicationControl (0x28) from DSD with the subnet parameter of the request equal
			 * 		to 0x00, the DCM shall do for each NetworkHandle (see DcmDspAllComMChannelRef) which
			 * 		is configured in DcmDspComControlAllChannel:
			 * 		1) trigger the mode switch Dcm_CommunicationControl_<Network>
			 * 		   ModeDeclarationGroupPrototype to the mode corresponding the communicationType and
			 * 		   controlType parameter from the CommunicationControl request.
			 * 		2) call the Api BswM_Dcm_CommunicationMode_CurrentState with the parameters
			 * 		   NetworkHandleType and Dcm_CommunicationModeType corresponding to the
			 * 		   communicationType and controlType parameter from the CommunicationControl request
			 * 		   (see Dcm_CommunicationModeType definition).
			 */
			if(0x00u == u8SubNetNum)
			{
#if(0u != DCM_DSP_COM_CONTROL_ALL_CHANNEL_NUM)
				for(u8Index = 0u; u8Index < DCM_DSP_COM_CONTROL_ALL_CHANNEL_NUM; u8Index++)
				{
					pAllChannel = &pComControl->DcmDspComControlAllChannel[u8Index];

					if((boolean)TRUE == pAllChannel->DcmDspComControlAllChannelUsed)
					{
						BswM_Dcm_CommunicationMode_CurrentState(pAllChannel->DcmDspAllComMChannelRef, reqMode);

						if(DCM_ENABLE_RX_TX_NORM_NM != reqMode)
						{
							DCM_BIT_SET(Dcm_CommunicationState, pAllChannel->DcmDspAllComMChannelRef, uint32);
						}
						else
						{
							DCM_BIT_CLEAR(Dcm_CommunicationState, pAllChannel->DcmDspAllComMChannelRef, uint32);
						}
					}
				}

				result = (Std_ReturnType)E_OK;
#endif /* #if(0u != DCM_DSP_COM_CONTROL_ALL_CHANNEL_NUM) */
			}
			/**
			 * @req [SWS_Dcm_00785] On invocation of the sent confirmation function of the UDS Service
			 * 		CommunicationControl (0x28) from DSD with the subnet parameter of the request equal
			 * 		to 0x0F(CommunicationControl on the network which request is received on), the DCM
			 * 		shall do for the NetworkHandle (see DcmDslProtocolComMChannelRef) of the current
			 * 		received DcmDslProtocolRxPduRef:
			 * 		1) trigger the mode switch Dcm_CommunicationControl_<Network>
			 * 		   ModeDeclarationGroupPrototype to the mode corresponding to the communicationType
			 * 		   and controlType parameter from the CommunicationControl request.
			 * 		2) call the Api BswM_Dcm_CommunicationMode_CurrentState with the parameters
			 * 		   NetworkHandleType and Dcm_CommunicationModeType corresponding to the
			 * 		   communicationType and controlType parameter from the CommunicationControl request
			 * 		   (see Dcm_CommunicationModeType definition).
			 */
			else if(0x0Fu == u8SubNetNum)
			{
				BswM_Dcm_CommunicationMode_CurrentState(pConnection->DcmDslProtocolComMChannelRef, reqMode);

				if(DCM_ENABLE_RX_TX_NORM_NM != reqMode)
				{
					DCM_BIT_SET(Dcm_CommunicationState, pConnection->DcmDslProtocolComMChannelRef, uint32);
				}
				else
				{
					DCM_BIT_CLEAR(Dcm_CommunicationState, pConnection->DcmDslProtocolComMChannelRef, uint32);
				}

				result = (Std_ReturnType)E_OK;
			}
			/**
			 * @req [SWS_Dcm_00786] On invocation of the sent confirmation function of the UDS Service
			 * 		CommunicationControl (0x28) from DSD with the subnet parameter of the request
			 * 		between 0x01 and 0x0E, the DCM shall check if the received subnet parameter (see
			 * 		DcmDspSubnetNumber) is supported. In case it is not supported a NegativeResponse
			 * 		code 0x31 shall be sent. In case it is supported the DCM shall do for the
			 * 		corresponding NetworkHandle (see DcmDspSpecificComMChannelRef) of the received
			 * 		subnet parameter (see DcmDspSubnetNumber):
			 * 		1) trigger the mode switch Dcm_CommunicationControl_<Network>
			 * 		   ModeDeclarationGroupPrototype to the mode corresponding the communicationType and
			 * 		   controlType parameter from the CommunicationControl request.
			 * 		2) call the Api BswM_Dcm_CommunicationMode_CurrentState the parameters
			 * 		   NetworkHandleType and with Dcm_CommunicationModeType corresponding the
			 * 		   communicationType and controlType parameter from the CommunicationControl request
			 * 		   (see Dcm_CommunicationModeType definition).
			 */
			else
			{
#if(0u != DCM_DSP_COM_CONTROL_SPECIFIC_CHANNEL_NUM)
				for(u8Index = 0u; u8Index < DCM_DSP_COM_CONTROL_SPECIFIC_CHANNEL_NUM; u8Index++)
				{
					pSpecificChannel = &pComControl->DcmDspComControlSpecificChannel[u8Index];

					if(((boolean)TRUE == pSpecificChannel->DcmDspComControlSpecificChannelUsed) &&\
						(u8SubNetNum == pSpecificChannel->DcmDspSubnetNumber))
					{
						BswM_Dcm_CommunicationMode_CurrentState(pSpecificChannel->DcmDspSpecificComMChannelRef, reqMode);

						if(DCM_ENABLE_RX_TX_NORM_NM != reqMode)
						{
							DCM_BIT_SET(Dcm_CommunicationState, pSpecificChannel->DcmDspSpecificComMChannelRef, uint32);
						}
						else
						{
							DCM_BIT_CLEAR(Dcm_CommunicationState, pSpecificChannel->DcmDspSpecificComMChannelRef, uint32);
						}

						result = (Std_ReturnType)E_OK;

						break;
					}
				}
#else
				;
#endif /* #if(0u != DCM_DSP_COM_CONTROL_SPECIFIC_CHANNEL_NUM) */
			}
		}

		if((Std_ReturnType)E_NOT_OK == result)
		{
			*pErrorCode = DCM_E_REQUESTOUTOFRANGE;
		}
	}

	return result;
}

#if(0u != DCM_DSP_COM_CONTROL_SUB_NODE_NUM)
/**
 * @brief			Dcm_UDS0x28Sub0x04And0x05Process
 * @details			Service 0x28 subfunction processing interface, used to handle subfunctions 0x04
 * 					and 0x05.
 *
 * @param[in]		u8SubServiceId:Sub function identifier.
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
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x28Sub0x04And0x05Process
(
	uint8 u8SubServiceId,
	P2CONST(Dcm_MsgContextType, AUTOMATIC, DCM_CONST)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
)
{
	Std_ReturnType result = (Std_ReturnType)E_NOT_OK;

	uint8 u8Index;
	uint8 u8ComType;
	uint16 u16Node;
	Dcm_CommunicationModeType reqMode;
	const Dcm_DspComControlSubNodeType* pSubNode = NULL_PTR;
	const Dcm_DspComControlType* pComControl = Dcm_ConfigPtr->DcmDsp->DcmDspComControl;

	if(5u != pMsgContext->ReqDataLen)
	{
		*pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
	}
	else
	{
		u8ComType = (pMsgContext->ReqData[2] & 0x03u);

		/**
		 * @req [SWS_Dcm_01077] If a CommunicationControl Request with the sub-function
		 *   	"enableRxAndDisableTxWithEnhancedAddressInformation" is received, the Dcm shall check
		 *   	the "nodeIdentification-Number" listed as DcmDspComControlSubNodeId and for the
		 *   	referenced network (see DcmDspComControlSubNodeComMChannelRef ), it shall do the
		 *   	followings:
		 *   	1) trigger the mode switch Dcm_CommunicationControl_<Network>
		 *		   ModeDeclarationGroupPrototype to the mode corresponding the communicationType and
		 *		   controlType parameter from the CommunicationControl request.
		 *		2) call the Api BswM_Dcm_CommunicationMode_CurrentState with the parameters
		 *		   NetworkHandleType and Dcm_CommunicationModeType corresponding to the
		 *		   communicationType and controlType parameter from the CommunicationControl request
		 *		   (see Dcm_CommunicationModeType definition).
		 *
		 * @req [SWS_Dcm_01079] If a CommunicationControl Request with the sub-function
		 * 		"enableRxAndTxWithEnhancedAddressInformation" is received, the Dcm shall check the
		 * 		"nodeIdentification-Number" listed as DcmDspComControlSubNodeId and for the referenced
		 * 		network (see DcmDspComControlSubNodeComMChannelRef ) it shall do the followings:
		 * 		1) trigger the mode switch Dcm_CommunicationControl_<Network>
		 * 		   ModeDeclarationGroupPrototype to the mode corresponding the communicationType and
		 * 		   controlType parameter from the CommunicationControl request.
		 * 		2) call the Api BswM_Dcm_CommunicationMode_CurrentState with the parameters
		 * 		   NetworkHandleType and Dcm_CommunicationModeType corresponding to the
		 * 		   communicationType and controlType parameter from the CommunicationControl request
		 * 		   (see Dcm_CommunicationModeType definition).
		 */
		if(0x01u <= u8ComType)
		{
			reqMode = Dcm_CommunicationModeTable[u8SubServiceId][u8ComType - 1u];

			u16Node = (uint16)pMsgContext->ReqData[3] << 8u;
			u16Node |= (uint16)pMsgContext->ReqData[4];

			for(u8Index = 0u; u8Index < DCM_DSP_COM_CONTROL_SUB_NODE_NUM; u8Index++)
			{
				pSubNode = &pComControl->DcmDspComControlSubNode[u8Index];

				/**
				 * @req [SWS_Dcm_01081] If DcmDspComControlSubNodeUsed is set to FALSE the subsystem
				 * 		(DcmDspComControlSubNode) is not available in this configuration.
				 *
				 * @req [SWS_Dcm_01082] If DcmDspComControlSubNodeUsed is set to TRUE the subsystem
				 * 		(DcmDspComControlSubNode) is available in this configuration.
				 */
				if(((boolean)TRUE == pSubNode->DcmDspComControlSubNodeUsed) && (u16Node == pSubNode->DcmDspComControlSubNodeId))
				{
					BswM_Dcm_CommunicationMode_CurrentState(pSubNode->DcmDspComControlSubNodeComMChannelRef, reqMode);

					if(DCM_ENABLE_RX_TX_NORM_NM != reqMode)
					{
						DCM_BIT_SET(Dcm_CommunicationState, pSubNode->DcmDspComControlSubNodeComMChannelRef, uint32);
					}
					else
					{
						DCM_BIT_CLEAR(Dcm_CommunicationState, pSubNode->DcmDspComControlSubNodeComMChannelRef, uint32);
					}

					result = (Std_ReturnType)E_OK;

					break;
				}
			}
		}

		/**
		 * @req [SWS_Dcm_01078] The Dcm shall trigger a negative response with NRC 0x31
		 * 		(RequestOutOfRange), if a CommunicationControl Request with the sub-function
		 * 		"enableRxAndDisableTxWithEnhancedAddressInformation" and a "nodeIdentificationNumber"
		 * 		which is not listed as DcmDspComControlSubNodeId is received.
		 *
		 * @req [SWS_Dcm_01080] The Dcm shall trigger a negative response with NRC 0x31
		 * 		(RequestOutOfRange), if a CommunicationControl Request with the sub-function
		 * 		"enableRxAndTxWithEnhancedAddressInformation" and a "nodeIdentification-Number" which
		 * 		is not listed as DcmDspComControlSubNodeId is received.
		 */
		if((Std_ReturnType)E_NOT_OK == result)
		{
			*pErrorCode = DCM_E_REQUESTOUTOFRANGE;
		}
	}

	return result;
}
#endif /* #if(0u != DCM_DSP_COM_CONTROL_SUB_NODE_NUM) */
/*====================================================================================================*
 *                                          GLOBAL FUNCTIONS
 *====================================================================================================*/
/**
 * @brief			Dcm_UDS0x28
 * @details			Internal processing interface for Service 0x28.
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
FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x28
(
	Dcm_OpStatusType OpStatus,
	P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
)
{
	Std_ReturnType result = (Std_ReturnType)E_NOT_OK;

	uint8 u8AddrType;
	uint8 u8SubServiceId;
	const Dcm_DsdServiceType* pService = NULL_PTR;

	if(2u > pMsgContext->ReqDataLen)
	{
		*ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
	}
	else
	{
		u8SubServiceId = pMsgContext->ReqData[1];

		u8AddrType = (pMsgContext->MsgAddInfo & 0x01u);

		pService = DCM_GET_SERVICE_PTR(Dcm_ConnectionStatus[Dcm_ActiveConIdx].ServiceIdx);

		if((Std_ReturnType)E_OK == DspInternal_SubServiceCheck(u8AddrType, u8SubServiceId, pService, ErrorCode))
		{
			switch(u8SubServiceId)
			{
				case 0x00u:
				case 0x01u:
				case 0x02u:
				case 0x03u:
					result = Dcm_UDS0x28Sub0x00To0x03Process(u8SubServiceId, pMsgContext, ErrorCode);
					break;
				case 0x04u:
				case 0x05u:
#if(0u != DCM_DSP_COM_CONTROL_SUB_NODE_NUM)
					result = Dcm_UDS0x28Sub0x04And0x05Process(u8SubServiceId, pMsgContext, ErrorCode);
					break;
#endif /* #if(0u != DCM_DSP_COM_CONTROL_SUB_NODE_NUM) */
				default:
					*ErrorCode = DCM_E_REQUESTOUTOFRANGE;
					break;
			}

			if((Std_ReturnType)E_OK == result)
			{
				/* The minimum length of the buffer is 8 bytes, no need to check the response length. */

				pMsgContext->ResData[0] = 0x68u;
				pMsgContext->ResData[1] = u8SubServiceId;

				pMsgContext->ResDataLen = 2u;
			}
		}
	}

	return result;
}

#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#endif /* #if(STD_ON == DCM_UDS0x28_INTERNAL_FNC_ENABLE) */
#endif /* #if(STD_ON == DCM_UDS0x28_ENABLE) */

#ifdef __cplusplus
}
#endif
/** @} */
