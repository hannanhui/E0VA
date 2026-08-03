/**
 * @file        Dcm.c
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

/* PRQA S 0292, 1503, 0857, 0791, 3673, 0491, 0498, 2981, 2877, 5087 EOF #
 *
 * 1.0292 -- Violates MISRA 2004 Required Rule 3.1, Source file has comments containing one of the
 * characters '$', '@' or '`'.
 *
 * 2.1503 -- Violates MISRA 2004 Required Rule 14.1, The function is defined but is not used within this
 * project.
 *
 * 3.0857 -- Violates MISRA 2004 Required Rule 1.1, Number of macro definitions exceeds 1024 - program
 * does not conform strictly to ISO:C90.
 *
 * 4.0791 -- Violates MISRA 2004 Required Rule 5.1, Macro identifier does not differ from other macro
 * identifier(s) within the specified number of significant characters.
 *
 * 5.3673 -- Violates MISRA 2004 Required Rule 16.7, The object addressed by the pointer parameter
 * 'Data' and 'Retry' is not modified and so the pointer could be of type 'pointer to const'.
 *
 * 6.0491 -- Violates MISRA 2004 Required Rule 17.4, Array subscripting applied to an object of pointer
 * type. 
 *
 * 7.0498 -- Violates MISRA 2004 Required Rule 17.4, A unary increment or decrement operator is being
 * applied to a pointer.
 *
 * 8.2981 -- Violates MISRA 2004 Required Rule 21.1, This initialization is redundant. The value of
 * this object is never used before being modified.
 *
 * 9.2877 -- Violates MISRA 2004 Required Rule 21.1, This loop will never be executed more than once.
 *
 * 10.5087 -- Violates MISRA 2004 Required Rule 19.1, Use of #include directive after code fragment.
 *
 * @page misra_violations MISRA-C:2004 violations
 */

/*====================================================================================================*
 *                                           INCLUDE FILES
 *====================================================================================================*/
/**
 * @req [SWS_Dcm_00055] The Dcm module shall use the header file structure shown in Figure 4.
 */
#include "Dcm.h"
#include "Dcm_Internal.h"
#include "Dcm_Cbk.h"

#ifdef AH_TEST_DCM
#include "TestCode.h"
#endif /* #ifdef AH_TEST_DCM */
/*====================================================================================================*
 *                                  SOURCE FILE VERSION INFORMATION
 *====================================================================================================*/
#define DCM_VENDOR_ID_C                                 	(0x00U)
#define DCM_AR_RELEASE_MAJOR_VERSION_C                  	(0x04U)
#define DCM_AR_RELEASE_MINOR_VERSION_C                  	(0x02U)
#define DCM_AR_RELEASE_REVISION_VERSION_C               	(0x02U)
#define DCM_SW_MAJOR_VERSION_C                          	(0x01U)
#define DCM_SW_MINOR_VERSION_C                          	(0x02U)
#define DCM_SW_PATCH_VERSION_C                          	(0x00U)
/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/
/* Check if current file and Dcm header file are of the same vendor */
#if(DCM_VENDOR_ID_C != DCM_VENDOR_ID )
#error "Dcm.c and Dcm.h have different vendor id"
#endif
/* Check if current file and Dcm header file are of the same Autosar version */
#if(\
		(DCM_AR_RELEASE_MAJOR_VERSION_C != DCM_AR_RELEASE_MAJOR_VERSION) || \
		(DCM_AR_RELEASE_MINOR_VERSION_C != DCM_AR_RELEASE_MINOR_VERSION) || \
		(DCM_AR_RELEASE_REVISION_VERSION_C != DCM_AR_RELEASE_REVISION_VERSION) \
)
#error "AutoSar Version Number of Dcm.c and Dcm.h are different"
#endif
/* Check if current file and Dcm header file are of the same software version */
#if(\
		(DCM_SW_MAJOR_VERSION_C != DCM_SW_MAJOR_VERSION) || \
		(DCM_SW_MINOR_VERSION_C != DCM_SW_MINOR_VERSION) || \
		(DCM_SW_PATCH_VERSION_C != DCM_SW_PATCH_VERSION) \
)
#error "Software Version Number of Dcm.c and Dcm.h are different"
#endif
/* Check if current file and Dcm_Internal header file are of the same vendor */
#if(DCM_VENDOR_ID_C != DCM_INTERNAL_VENDOR_ID )
#error "Dcm.c and Dcm_Internal.h have different vendor id"
#endif
/* Check if current file and Dcm_Internal header file are of the same Autosar version */
#if(\
		(DCM_AR_RELEASE_MAJOR_VERSION_C != DCM_INTERNAL_AR_RELEASE_MAJOR_VERSION) || \
		(DCM_AR_RELEASE_MINOR_VERSION_C != DCM_INTERNAL_AR_RELEASE_MINOR_VERSION) || \
		(DCM_AR_RELEASE_REVISION_VERSION_C != DCM_INTERNAL_AR_RELEASE_REVISION_VERSION) \
)
#error "AutoSar Version Number of Dcm.c and Dcm_Internal.h are different"
#endif
/* Check if current file and Dcm_Internal header file are of the same software version */
#if(\
		(DCM_SW_MAJOR_VERSION_C != DCM_INTERNAL_SW_MAJOR_VERSION) || \
		(DCM_SW_MINOR_VERSION_C != DCM_INTERNAL_SW_MINOR_VERSION) || \
		(DCM_SW_PATCH_VERSION_C != DCM_INTERNAL_SW_PATCH_VERSION) \
)
#error "Software Version Number of Dcm.c and Dcm_Internal.h are different"
#endif
/* Check if current file and Dcm_Cbk header file are of the same vendor */
#if(DCM_VENDOR_ID_C != DCM_CBK_VENDOR_ID )
#error "Dcm.c and Dcm_Cbk.h have different vendor id"
#endif
/* Check if current file and Dcm_Cbk header file are of the same Autosar version */
#if(\
		(DCM_AR_RELEASE_MAJOR_VERSION_C != DCM_CBK_AR_RELEASE_MAJOR_VERSION) || \
		(DCM_AR_RELEASE_MINOR_VERSION_C != DCM_CBK_AR_RELEASE_MINOR_VERSION) || \
		(DCM_AR_RELEASE_REVISION_VERSION_C != DCM_CBK_AR_RELEASE_REVISION_VERSION) \
)
#error "AutoSar Version Number of Dcm.c and Dcm_Cbk.h are different"
#endif
/* Check if current file and Dcm_Dem header file are of the same software version */
#if(\
		(DCM_SW_MAJOR_VERSION_C != DCM_CBK_SW_MAJOR_VERSION) || \
		(DCM_SW_MINOR_VERSION_C != DCM_CBK_SW_MINOR_VERSION) || \
		(DCM_SW_PATCH_VERSION_C != DCM_CBK_SW_PATCH_VERSION) \
)
#error "Software Version Number of Dcm.c and Dcm_Cbk.h are different"
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
#define DCM_START_SEC_VAR_NO_INIT_8
#include "Dcm_MemMap.h"

/**
 * @brief 	Store the usage status of the configured protocols. Each bit represents a configured
 * 			protocol, and a set bit (1) indicates that the protocol is currently in use.
 */
VAR(uint8, DCM_VAR)Dcm_ProtocolStartState = 0u;

/**
 * @brief 	Store the current operating state of the Dcm module.
 */
VAR(Dcm_OpStatusType, DCM_VAR)Dcm_OpState = DCM_INITIAL;

/**
 * @brief  	Store the index of the currently used connection within the configuration.
 */
VAR(uint8, DCM_VAR)Dcm_ActiveConIdx;

/**
 * @brief  	Store the index of the currently used protocol within the configuration.
 */
VAR(uint8, DCM_VAR)Dcm_ActiveProRowIdx;

#ifdef DCM_DSP_SESSION_REF_DATA_TYPE_UINT8
/**
 * @brief	Store the index of the currently active diagnostic session mode within the configuration.
 */
VAR(Dcm_SessionDataType, DCM_VAR)Dcm_ActiveSessionIdx;
#endif /* #ifdef DCM_DSP_SESSION_REF_DATA_TYPE_UINT8 */

/**
 * @brief  	Store the currently active diagnostic session mode.
 */
VAR(Dcm_SesCtrlType, DCM_VAR)Dcm_ActiveSession;

#if(STD_ON == DCM_UDS0x10_ENABLE)
#ifdef DCM_DSP_SESSION_REF_DATA_TYPE_UINT8
/**
 * @brief	Store the index of the diagnostic session mode requested for transition within the
 * 			configuration.
 */
VAR(Dcm_SessionDataType, DCM_VAR)Dcm_NewActiveSessionIdx;
#endif /* #ifdef DCM_DSP_SESSION_REF_DATA_TYPE_UINT8 */

/**
 * @brief	Store the diagnostic session mode requested for transition.
 */
VAR(Dcm_SesCtrlType, DCM_VAR)Dcm_NewActiveSession;
#endif /* #if(STD_ON == DCM_UDS0x10_ENABLE) */

/**
 * @brief  	Store the currently active security access level.
 */
VAR(Dcm_SecLevelType, DCM_VAR)Dcm_ActiveSecurity;

#if(STD_ON == DCM_UDS0x27_ENABLE)
#ifdef DCM_DSP_SECURITY_REF_DATA_TYPE_UINT8
/**
 * @brief	Store the index of the security access level requested for unlocking.
 */
VAR(Dcm_SecurityDataType, DCM_VAR)Dcm_NewActiveSecurityIdx;
#endif /* #ifdef DCM_DSP_SECURITY_REF_DATA_TYPE_UINT8 */

/**
 * @brief	Store the security access level requested for unlocking.
 */
VAR(Dcm_SecLevelType, DCM_VAR)Dcm_NewActiveSecurity;
#endif /* #if(STD_ON == DCM_UDS0x27_ENABLE) */

#define DCM_STOP_SEC_VAR_NO_INIT_8
#include "Dcm_MemMap.h"

#define DCM_START_SEC_VAR_NO_INIT_16
#include "Dcm_MemMap.h"

#ifdef DCM_DSP_SESSION_REF_DATA_TYPE_UINT16
/**
 * @brief	Store the index of the currently active diagnostic session mode within the configuration.
 */
VAR(Dcm_SessionDataType, DCM_VAR)Dcm_ActiveSessionIdx;

#if(STD_ON == DCM_UDS0x10_ENABLE)
/**
 * @brief	Store the index of the diagnostic session mode requested for transition within the
 * 			configuration.
 */
VAR(Dcm_SessionDataType, DCM_VAR)Dcm_NewActiveSessionIdx;
#endif /* #if(STD_ON == DCM_UDS0x10_ENABLE) */
#endif /* #ifdef DCM_DSP_SESSION_REF_DATA_TYPE_UINT16 */

#if(STD_ON == DCM_UDS0x27_ENABLE)
#ifdef DCM_DSP_SECURITY_REF_DATA_TYPE_UINT16
/**
 * @brief	Store the index of the security access level requested for unlocking.
 */
VAR(Dcm_SecurityDataType, DCM_VAR)Dcm_NewActiveSecurityIdx;
#endif /* #ifdef DCM_DSP_SECURITY_REF_DATA_TYPE_UINT16 */
#endif /* #if(STD_ON == DCM_UDS0x27_ENABLE) */

#define DCM_STOP_SEC_VAR_NO_INIT_16
#include "Dcm_MemMap.h"

#define DCM_START_SEC_VAR_NO_INIT_32
#include "Dcm_MemMap.h"

#ifdef DCM_DSP_SESSION_REF_DATA_TYPE_UINT32
/**
 * @brief	Store the index of the currently active diagnostic session mode within the configuration.
 */
VAR(Dcm_SessionDataType, DCM_VAR)Dcm_ActiveSessionIdx;

#if(STD_ON == DCM_UDS0x10_ENABLE)
/**
 * @brief	Store the index of the diagnostic session mode requested for transition within the
 * 			configuration.
 */
VAR(Dcm_SessionDataType, DCM_VAR)Dcm_NewActiveSessionIdx;
#endif /* #if(STD_ON == DCM_UDS0x10_ENABLE) */
#endif /* #ifdef DCM_DSP_SESSION_REF_DATA_TYPE_UINT32 */

#if(STD_ON == DCM_UDS0x27_ENABLE)
#ifdef DCM_DSP_SECURITY_REF_DATA_TYPE_UINT32
/**
 * @brief	Store the index of the security access level requested for unlocking.
 */
VAR(Dcm_SecurityDataType, DCM_VAR)Dcm_NewActiveSecurityIdx;
#endif /* #ifdef DCM_DSP_SECURITY_REF_DATA_TYPE_UINT32 */
#endif /* #if(STD_ON == DCM_UDS0x27_ENABLE) */

#define DCM_STOP_SEC_VAR_NO_INIT_32
#include "Dcm_MemMap.h"

#define DCM_START_SEC_VAR_NO_INIT_BOOLEAN
#include "Dcm_MemMap.h"

/**
 * @brief  Store the initialization state of the Dcm module.
 */
STATIC VAR(boolean, DCM_VAR)Dcm_InitState = (boolean)FALSE;

#define DCM_STOP_SEC_VAR_NO_INIT_BOOLEAN
#include "Dcm_MemMap.h"

#define DCM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dcm_MemMap.h"

/**
 * @brief  Store the configuration pointer.
 */
P2CONST(Dcm_ConfigType, AUTOMATIC, DCM_CONST)Dcm_ConfigPtr = NULL_PTR;

/**
 * @brief	Store the diagnostic active state and communication state of the channel.
 */
VAR(Dcm_ComMStatusType, DCM_VAR)Dcm_ComMStatus[DCM_DSL_MAIN_CONNECTION_NUM];

/**
 * @brief  	Store the relevant information from the receipt of the request to the confirmation of the
 * 			response.
 */
VAR(Dcm_MsgContextType, DCM_VAR)Dcm_MsgContext[DCM_DSL_PROTOCOLROW_NUM];

/**
 * @brief 	Store the relevant connection status during the process form receiving the request to
 * 			confirming the response.
 */
VAR(Dcm_ConnectionStatusType, DCM_VAR)Dcm_ConnectionStatus[DCM_DSL_MAIN_CONNECTION_NUM];

/**
 * @brief 	Store the relevant status of the S3 timer.
 */
VAR(Dcm_S3TimerStatusType, DCM_VAR)Dcm_S3TimerStatus;

/**
 * @brief 	Store the relevant status of the P2 timer.
 */
VAR(Dcm_P2TimerStatusType, DCM_VAR)Dcm_P2TimerStatus;

#if(STD_ON == DCM_UDS0x2A_ENABLE)
/**
 * @brief 	Store the periodic transmission internal status.
 */
VAR(Dcm_PeriodicTransStatusType, DCM_VAR)Dcm_PeriodicTransStatus;
#endif /* #if(STD_ON == DCM_UDS0x2A_ENABLE) */

#if(STD_ON == DCM_UDS0x2C_ENABLE)
/**
 * @brief 	Store the DDDid internal status.
 */
VAR(Dcm_DDDidStatusType, DCM_VAR)Dcm_DDDidStatus[DCM_DSP_DDDID_NUM];
#endif /* #if(STD_ON == DCM_UDS0x2C_ENABLE) */

#if((STD_ON == DCM_UDS0x34_ENABLE) || (STD_ON == DCM_UDS0x35_ENABLE))
/**
 * @brief 	Store the relevant status during the process of downloading or uploading data.
 */
VAR(Dcm_TransferStatusType, DCM_VAR)Dcm_TransferStatus;
#endif /* #if((STD_ON == DCM_UDS0x34_ENABLE) || (STD_ON == DCM_UDS0x35_ENABLE)) */

#define DCM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dcm_MemMap.h"

#define DCM_START_SEC_VAR_INIT_8
#include "Dcm_MemMap.h"

#if((STD_ON == DCM_DSL_DIAG_RESP_ON_SECOND_DECLINED_REQUEST) ||\
	(STD_ON == DCM_DSL_CALLBACK_DCM_REQUEST_SERVICE_ENABLED))
/**
 * @brief 	Independent NRC buffer.
 */
VAR(uint8, DCM_VAR)Dcm_NRCBuffer[3] = {(uint8)0x7F, (uint8)0xFF, (uint8)0xFF};
#endif /* #if((STD_ON == DCM_DSL_DIAG_RESP_ON_SECOND_DECLINED_REQUEST) ||\
			  (STD_ON == DCM_DSL_CALLBACK_DCM_REQUEST_SERVICE_ENABLED)) */

#define DCM_STOP_SEC_VAR_INIT_8
#include "Dcm_MemMap.h"
/*====================================================================================================*
 *                                      LOCAL FUNCTION PROTOTYPES
 *====================================================================================================*/

/*====================================================================================================*
 *                                           LOCAL FUNCTIONS
 *====================================================================================================*/

/*====================================================================================================*
 *                                          GLOBAL FUNCTIONS
 *====================================================================================================*/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"

/**
 * @sid				0x01
 * @brief			Dcm_Init
 * @details			Service for basic initialization of DCM module.
 *
 * @param[in]		ConfigPtr:Pointer to configuration set in Variant Post-Build.
 *
 * @req [SWS_Dcm_00037]
 */
FUNC(void, DCM_CODE)Dcm_Init
(
	P2CONST(Dcm_ConfigType, AUTOMATIC, DCM_CONST)ConfigPtr
)
{
	if(NULL_PTR == ConfigPtr)
	{
		DCM_DET_ERROR_REPORT(DCM_SID_INIT, DCM_E_PARAM_POINTER);
	}
	else
	{
		/* Store the configuration pointer. */
		Dcm_ConfigPtr = ConfigPtr;

		/* Set the module initialization state to TRUE. */
		Dcm_InitState = (boolean)TRUE;

		/* Initialize all internal status. */
		DslInternal_InitInternalStatus();

		DspInternal_JumpFromHandle();
	}
}

#if(STD_ON == DCM_VERSION_INFO_API)
/**
 * @sid				0x24
 * @brief			Dcm_GetVersionInfo
 * @details			Returns the version information of this module.
 *
 * @param[out]		VersionInfo:Pointer to where to store the version information of this module.
 *
 * @req [SWS_Dcm_00065]
 */
FUNC(void, DCM_CODE)Dcm_GetVersionInfo
(
	P2VAR(Std_VersionInfoType, AUTOMATIC, DCM_VAR)VersionInfo
)
{
	if(NULL_PTR == VersionInfo)
	{
		DCM_DET_ERROR_REPORT(DCM_SID_GETVERSIONINFO, DCM_E_PARAM_POINTER);
	}
	else
	{
		VersionInfo->vendorID = DCM_VENDOR_ID;
		VersionInfo->moduleID = DCM_MODULE_ID;
		VersionInfo->sw_major_version = DCM_SW_MAJOR_VERSION;
		VersionInfo->sw_minor_version = DCM_SW_MINOR_VERSION;
		VersionInfo->sw_patch_version = DCM_SW_PATCH_VERSION;
	}
}
#endif /* #if(STD_ON == DCM_VERSION_INFO_API) */

/**
 * @sid				0x2B
 * @brief			Dcm_DemTriggerOnDTCStatus
 * @details			Triggers on changes of the UDS status byte. Allows to trigger on ROE Event for
 * 					subservice OnDTCStatusChanged.
 *
 * @param[in]		DTC:This is the DTC the change trigger is assigned to.
 * @param[in]		DTCStatusOld:DTC status before change.
 * @param[in]		DTCStatusNew:DTC status after change.
 *
 * @return        	Result of this operation.
 * @retval		  	E_OK:This value is always returned.
 *
 * @req [SWS_Dcm_00614]
 */
#if(0)
FUNC(Std_ReturnType, DCM_CODE)Dcm_DemTriggerOnDTCStatus
(
	uint32 DTC,
	Dem_UdsStatusByteType DTCStatusOld,
	Dem_UdsStatusByteType DTCStatusNew
)
{
	if((boolean)FALSE == Dcm_InitState)
	{
		DCM_DET_ERROR_REPORT(DCM_SID_DEMTRIGGERONDTCSTATUS, DCM_E_UNINIT);
	}
	else
	{
		/* TODO:2025.12.10, LY: Not supported. */
		;
	}

	return (Std_ReturnType)E_OK;
}
#endif

/**
 * @sid				0x07
 * @brief			Dcm_GetVin
 * @details			Function to get the VIN (as defined in SAE J1979-DA).
 *
 * @param[out]		Data:Pointer to where to store the VIN.
 *
 * @return        	Result of this operation.
 * @retval		  	E_OK:The Data pointer has been filled with valid VIN.
 * @retval			E_NOT_OK:The default VIN will be used in the DoIP.
 *
 * @req [SWS_Dcm_00950]
 */
FUNC(Std_ReturnType, DCM_CODE)Dcm_GetVin
(
	P2VAR(uint8, AUTOMATIC, DCM_VAR)Data
)
{
	Std_ReturnType result = (Std_ReturnType)E_NOT_OK;

	if((boolean)FALSE == Dcm_InitState)
	{
		DCM_DET_ERROR_REPORT(DCM_SID_GETVIN, DCM_E_UNINIT);
	}
	else if(NULL_PTR == Data)
	{
		DCM_DET_ERROR_REPORT(DCM_SID_GETVIN, DCM_E_PARAM_POINTER);
	}
	else
	{
#if(0u != DCM_DSP_VEHINFO_NUM)
		/* TODO:2025.12.10, LY: Not supported. */
		;
#else
		;
#endif /* #if(0u != DCM_DSP_VEHINFO_NUM) */
	}

	return result;
}

/**
 * @sid				0x0d
 * @brief			Dcm_GetSecurityLevel
 * @details			This function provides the active security level value.
 *
 * @param[out]		SecLevel:Active Security Level value.
 *
 * @return        	Result of this operation.
 * @retval		  	E_OK:This value is always returned.
 *
 * @req [SWS_Dcm_00338]
 */
FUNC(Std_ReturnType, DCM_CODE)Dcm_GetSecurityLevel
(
	P2VAR(Dcm_SecLevelType, AUTOMATIC, DCM_VAR)SecLevel
)
{
	if((boolean)FALSE == Dcm_InitState)
	{
		DCM_DET_ERROR_REPORT(DCM_SID_GETSECURITYLEVEL, DCM_E_UNINIT);
	}
	else if(NULL_PTR == SecLevel)
	{
		DCM_DET_ERROR_REPORT(DCM_SID_GETSECURITYLEVEL, DCM_E_PARAM_POINTER);
	}
	else
	{
		*SecLevel = Dcm_ActiveSecurity;
	}

	return (Std_ReturnType)E_OK;
}

/**
 * @sid				0x06
 * @brief			Dcm_GetSesCtrlType
 * @details			This function provides the active session control type value.
 *
 * @param[out]		SesType:Active Session Control Type value.
 *
 * @return        	Result of this operation.
 * @retval		  	E_OK:This value is always returned.
 *
 * @req [SWS_Dcm_00339]
 */
FUNC(Std_ReturnType, DCM_CODE)Dcm_GetSesCtrlType
(
	P2VAR(Dcm_SesCtrlType, AUTOMATIC, DCM_VAR)SesType
)
{
	if((boolean)FALSE == Dcm_InitState)
	{
		DCM_DET_ERROR_REPORT(DCM_SID_GETSESCTRLTYPE, DCM_E_UNINIT);
	}
	else if(NULL_PTR == SesType)
	{
		DCM_DET_ERROR_REPORT(DCM_SID_GETSESCTRLTYPE, DCM_E_PARAM_POINTER);
	}
	else
	{
		*SesType = Dcm_ActiveSession;
	}

	return (Std_ReturnType)E_OK;
}

/**
 * @sid				0x0f
 * @brief			Dcm_GetActiveProtocol
 * @details			This function returns the active UDS protocol details.
 *
 * @param[out]		ActiveProtocolType:Active protocol type value.
 * @param[out]		ConnectionId:Unique connection identifier.
 * @param[out]		TesterSourceAddress:Source address of the tester.
 *
 * @return        	Result of this operation.
 * @retval		  	E_OK:This value is always returned.
 *
 * @req [SWS_Dcm_00340]
 */
FUNC(Std_ReturnType, DCM_CODE)Dcm_GetActiveProtocol
(
	P2VAR(Dcm_ProtocolType, AUTOMATIC, DCM_VAR)ActiveProtocolType,
	P2VAR(uint16, AUTOMATIC, DCM_VAR)ConnectionId,
	P2VAR(uint16, AUTOMATIC, DCM_VAR)TesterSourceAddress
)
{
	Dcm_ProtocolType type;

	if((boolean)FALSE == Dcm_InitState)
	{
		DCM_DET_ERROR_REPORT(DCM_SID_GETACTIVEPROTOCOL, DCM_E_UNINIT);
	}
	else if((NULL_PTR == ActiveProtocolType) || (NULL_PTR == ConnectionId) || (NULL_PTR == TesterSourceAddress))
	{
		DCM_DET_ERROR_REPORT(DCM_SID_GETACTIVEPROTOCOL, DCM_E_PARAM_POINTER);
	}
	else
	{
		*ConnectionId = 0xFFFFu;
		*TesterSourceAddress = 0xFFFFu;
		*ActiveProtocolType = DCM_NO_ACTIVE_PROTOCOL;

		if(0xFFu != Dcm_ActiveProRowIdx)
		{
			type = Dcm_ConfigPtr->DcmDsl->DcmDslProtocolRow[Dcm_ActiveProRowIdx].DcmDslProtocolID;

			if((DCM_OBD_ON_CAN != type) && (DCM_OBD_ON_FLEXRAY != type) && (DCM_OBD_ON_IP != type))
			{
				*ActiveProtocolType = type;

				if(0xFFu != Dcm_ActiveConIdx)
				{
					*ConnectionId = Dcm_ActiveConIdx;
				}

				/* TODO:2025.12.10 LY:No supported. */
				/* *TesterSourceAddress = 0xFFFFu; */
			}
		}
	}

	return (Std_ReturnType)E_OK;
}

/**
 * @sid				0x2a
 * @brief			Dcm_ResetToDefaultSession
 * @details			The call to this function allows the application to reset the current session to
 * 					Default session. Example: Automatic termination of an extended diagnostic session
 * 					upon exceeding of a speed limit.
 *
 * @return        	Result of this operation.
 * @retval		  	E_OK:This value is always returned.
 *
 * @req [SWS_Dcm_00520]
 */
FUNC(Std_ReturnType, DCM_CODE)Dcm_ResetToDefaultSession
(
	void
)
{
	if((boolean)FALSE == Dcm_InitState)
	{
		DCM_DET_ERROR_REPORT(DCM_SID_RESETTODEFAULTSESSION, DCM_E_UNINIT);
	}
	else
	{
		if(DCM_DEFAULT_SESSION != Dcm_ActiveSession)
		{
			Dcm_NewActiveSessionIdx = DCM_DSP_DEFAULT_SESSION_ROW_IDX;
			DslInternal_SetSesCtrlType(DCM_DEFAULT_SESSION);
		}
	}

	return (Std_ReturnType)E_OK;
}

/**
 * @sid				0x2d
 * @brief			Dcm_TriggerOnEvent
 * @details			The call to this function allows to trigger an event linked to a ResponseOnEvent
 * 					request. On the function call, the DCM will execute the associated service if the
 * 					corresponding Mode of the RoeEventId is 'ROE started'.
 *
 * @param[in]		RoeEventId:Identifier of the event that is triggered.
 *
 * @return        	Result of this operation.
 * @retval		  	E_OK:RoeEventId value is valid.
 * @retval		  	E_NOT_OK:RoeEventId value is not valid.
 *
 * @req [SWS_Dcm_00521]
 */
FUNC(Std_ReturnType, DCM_CODE)Dcm_TriggerOnEvent
(
	uint8 RoeEventId
)
{
	Std_ReturnType result = (Std_ReturnType)E_NOT_OK;

	if((boolean)FALSE == Dcm_InitState)
	{
		DCM_DET_ERROR_REPORT(DCM_SID_TRIGGERONEVENT, DCM_E_UNINIT);
	}
	else
	{
#if(0u != DCM_DSP_ROE_NUM)
		/* TODO:2025.12.10, LY: Not supported. */
		;
#else
		;
#endif /* #if(0u != DCM_DSP_ROE_NUM) */
	}

	return result;
}

/**
 * @sid				0x56
 * @brief			Dcm_SetActiveDiagnostic
 * @details			Allows to activate and deactivate the call of ComM_DCM_ActiveDiagnostic() function.
 *
 * @param[in]		Active:If false Dcm shall not call ComM_DCM_ActiveDiagnostic(). If true Dcm will
 * 					call ComM_DCM_ActiveDiagnostic().
 *
 * @return        	Result of this operation.
 * @retval		  	E_OK:This value is always returned.
 *
 * @req [SWS_Dcm_01068]
 */
FUNC(Std_ReturnType, DCM_CODE)Dcm_SetActiveDiagnostic
(
	boolean Active
)
{
	uint8 u8Index;
	const Dcm_DslMainConnectionType* pConnection = NULL_PTR;

	if((boolean)FALSE == Dcm_InitState)
	{
		DCM_DET_ERROR_REPORT(DCM_SID_SETACTIVEDIAGNOSTIC, DCM_E_UNINIT);
	}
	else
	{
		if((boolean)TRUE == Active)
		{
			/**
			 * @req [SWS_Dcm_01071] If Xxx_SetActiveDiagnostic() is called with "true" the Dcm set
			 * 		ActiveDiagnostic to "DCM_COMM_ACTIVE".
			 */
			for(u8Index = 0u; u8Index < DCM_DSL_MAIN_CONNECTION_NUM; u8Index++)
			{
				pConnection = &Dcm_ConfigPtr->DcmDslMainConnection[u8Index];

				Dcm_ComMStatus[u8Index].DiagnosticState = DCM_COMM_ACTIVE;

//				(void)ComM_DCM_ActiveDiagnostic(pConnection->DcmDslProtocolComMChannelRef);
			}
		}
		else
		{
			/**
			 * @req [SWS_Dcm_01070] If Xxx_SetActiveDiagnostic() is called with "false" the Dcm set
			 * 		ActiveDiagnostic to "DCM_COMM_NOT_ACTIVE".
			 */
			for(u8Index = 0u; u8Index < DCM_DSL_MAIN_CONNECTION_NUM; u8Index++)
			{
				Dcm_ComMStatus[u8Index].DiagnosticState = DCM_COMM_NOT_ACTIVE;
			}
		}
	}

	return (Std_ReturnType)E_OK;
}

/**
 * @Sid				0x46
 * @brief			Dcm_StartOfReception
 * @details			This function is called at the start of receiving an N-SDU. The N-SDU might be
 * 					fragmented into multiple N-PDUs (FF with one or more following CFs) or might
 * 					consist of a single N-PDU (SF). The service shall provide the currently available
 * 					maximum buffer size when invoked with TpSduLength equal to 0.
 *
 * @param[in]		Id:Identification of the I-PDU.
 * @param[in]		Info:Pointer to a PduInfoType structure containing the payload data (without
 * 					protocol information) and payload length of the first frame or single frame of
 * 					a transport protocol I-PDU reception, and the MetaData related to this PDU. If
 * 					neither first/single frame data nor MetaData are available, this parameter is set
 * 					to NULL_PTR.
 * @param[in] 		TpSduLength:Total length of the N-SDU to be received.
 *
 * @param[out]		BufferSizePtr:Available receive buffer in the receiving module. This parameter will
 * 					be used to compute the Block Size (BS) in the transport protocol module.
 *
 * @return        	Result of this operation.
 * @retval			BUFREQ_OK: Connection has been accepted. bufferSizePtr indicates the available
 * 					receive buffer; reception is continued. If no buffer of the requested size is
 * 					available, a receive buffer size of 0 shall be indicated by bufferSizePtr.
 * @retval			BUFREQ_E_NOT_OK:Connection has been rejected; reception is aborted. bufferSizePtr
 * 					remains unchanged.
 * @retval			BUFREQ_E_OVFL:No buffer of the required length can be provided; reception is
 * 					aborted. bufferSizePtr remains unchanged.
 *
 * @req [SWS_Dcm_00094]
 */
FUNC(BufReq_ReturnType, DCM_CODE)Dcm_StartOfReception
(
	PduIdType Id,
	P2CONST(PduInfoType, AUTOMATIC, DCM_CONST)Info,
	PduLengthType TpSduLength,
	P2VAR(PduLengthType, AUTOMATIC, DCM_VAR)BufferSizePtr
)
{
	BufReq_ReturnType result = BUFREQ_E_NOT_OK;

	uint8 u8ConIdx;
	uint8 u8ProRowIdx;
	const Dcm_DslProtocolRxType* pProtocolRx = NULL_PTR;
	const Dcm_DslProtocolRowType* pProtocolRow = NULL_PTR;

	if((boolean)FALSE == Dcm_InitState)
	{
		DCM_DET_ERROR_REPORT(DCM_SID_STARTOFRECEPTION, DCM_E_UNINIT);
	}
	else if(DCM_DSL_PROTOCOL_RX_NUM <= Id)
	{
		DCM_DET_ERROR_REPORT(DCM_SID_STARTOFRECEPTION, DCM_E_PARAM);
	}
	else if(NULL_PTR == BufferSizePtr)
	{
		DCM_DET_ERROR_REPORT(DCM_SID_STARTOFRECEPTION, DCM_E_PARAM_POINTER);
	}
	else
	{
		/**
		 * @req [SWS_Dcm_00241] As soon as a request message is received (after a call of
		 * 		Dcm_TpRxIndication() with parameter Result = E_OK (see SWS_Dcm_00093) and until a call
		 * 		to Dcm_TpTxConfirmation() (see SWS_Dcm_00351) for the associated Tx-DcmPduId), the DSL
		 * 		submodule shall block the corresponding DcmPduId. During the processing of this request,
		 * 		no other request of the same DcmDslConnection (e.g. an enhanced session can be ended by
		 * 		a OBD session) can be received, until the corresponding response message is sent and the
		 * 		DcmPduId is released again (except for concurrent TesterPresent requests).
		 */

		/* Get the DcmDslProtocolRx and DcmDslProtocolRow configurations corresponding to the Id. */
		pProtocolRx = &Dcm_ConfigPtr->DcmDslProtocolRx[Id];
		u8ConIdx = pProtocolRx->DcmDslRxParentConIdx;
		u8ProRowIdx = pProtocolRx->DcmDslRxParentProIdx;
		pProtocolRow = &Dcm_ConfigPtr->DcmDsl->DcmDslProtocolRow[u8ProRowIdx];

		if(0u != TpSduLength)
		{
			/**
			 * @req [SWS_Dcm_00444] If the requested size is large than the buffer available in the DCM,
			 * 		the function Dcm_StartOfReception() shall return BUFREQ_E_OVFL (see SWS_Dcm_00094).
			 */
			if(pProtocolRow->DcmDslProtocolRxBufferRef->DcmDslBufferSize < TpSduLength)
			{
				result = BUFREQ_E_OVFL;
			}
			else if(0xFFu == Dcm_ActiveProRowIdx)
			{
				/* There are currently no active protocol in place, the diagnostic request is directly
				 * received and processed. */

				/* Only for after jumping to the BootLoader, the session mode is programming. */
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
			}
			else if(Dcm_ActiveProRowIdx == u8ProRowIdx)
			{
				/* The protocol used to receive the diagnostic request is not consistent with the currently active protocol. */
				result = DslInternal_NoProtocolPreemption(Info, TpSduLength, BufferSizePtr, pProtocolRx, pProtocolRow);
			}
			else
			{
#if(0u != DCM_DSL_PROTOCOLROW_NUM)
				/* The protocol used to receive the diagnostic request is consistent with the currently active protocol. */
				result = DslInternal_ProtocolPreemption(Id, Info, TpSduLength, BufferSizePtr, pProtocolRx, pProtocolRow);
#else
				/* Nothing to do here. */
				;
#endif /* #if(0u != DCM_DSL_PROTOCOLROW_NUM) */
			}
		}
	}

	return result;
}

/**
 * @sid				0x44
 * @brief			Dcm_CopyRxData
 * @details			This function is called to provide the received data of an I-PDU segment (N-PDU)
 * 					to the upper layer. Each call to this function provides the next part of the I-PDU
 * 					data. The size of the remaining buffer is written to the position indicated by
 * 					bufferSizePtr.
 *
 * @param[in]		Id:Identification of the received I-PDU.
 * @param[in]		Info:Provides the source buffer (SduDataPtr) and the number of bytes to be copied
 * 					(SduLength). An SduLength of 0 can be used to query the current amount of available
 * 					buffer in the upper layer module. In this case, the SduDataPtr may be a NULL_PTR.
 *
 * @param[out]		BufferSizePtr:Available receive buffer after data has been copied.
 *
 * @return        	Result of this operation.
 * @retval			BUFREQ_OK:Data copied successfully.
 * @retval			BUFREQ_E_NOT_OK:Data was not copied because an error occurred.
 *
 * @req [SWS_Dcm_00556]
 */
FUNC(BufReq_ReturnType, DCM_CODE)Dcm_CopyRxData
(
	PduIdType Id,
	P2CONST(PduInfoType, AUTOMATIC, DCM_CONST)Info,
	P2VAR(PduLengthType, AUTOMATIC, DCM_VAR)BufferSizePtr
)
{
	BufReq_ReturnType result = BUFREQ_E_NOT_OK;

	uint8 u8ProConIdx;
	uint8 u8ProRowIdx;
	const Dcm_DslProtocolRxType* pProtocolRx = NULL_PTR;
	const Dcm_DslProtocolRowType* pProtocolRow = NULL_PTR;

	if((boolean)FALSE == Dcm_InitState)
	{
		DCM_DET_ERROR_REPORT(DCM_SID_COPYRXDATA, DCM_E_UNINIT);
	}
	else if(DCM_DSL_PROTOCOL_RX_NUM <= Id)
	{
		DCM_DET_ERROR_REPORT(DCM_SID_COPYRXDATA, DCM_E_PARAM);
	}
	else if((NULL_PTR == Info) || (NULL_PTR == BufferSizePtr))
	{
		DCM_DET_ERROR_REPORT(DCM_SID_COPYRXDATA, DCM_E_PARAM_POINTER);
	}
	else
	{
		pProtocolRx = &Dcm_ConfigPtr->DcmDslProtocolRx[Id];
		u8ProConIdx = pProtocolRx->DcmDslRxParentConIdx;

		if(DCM_RX_STATE_COPY == Dcm_ConnectionStatus[u8ProConIdx].RxState)
		{
			u8ProRowIdx = pProtocolRx->DcmDslRxParentProIdx;
			pProtocolRow = &Dcm_ConfigPtr->DcmDsl->DcmDslProtocolRow[u8ProRowIdx];

			if(0u == Info->SduLength)
			{
				*BufferSizePtr = (pProtocolRow->DcmDslProtocolRxBufferRef->DcmDslBufferSize - Dcm_ConnectionStatus[u8ProConIdx].CopyOffset);
				result = BUFREQ_OK;
			}
			else if(Info->SduLength <= Dcm_ConnectionStatus[u8ProConIdx].RemainLen)
			{
				DCM_MEMORY_COPY(\
						Info->SduDataPtr,\
						&pProtocolRow->DcmDslProtocolRxBufferRef->DcmDslBufferRef[Dcm_ConnectionStatus[u8ProConIdx].CopyOffset],\
						Info->SduLength\
						);

				Dcm_ConnectionStatus[u8ProConIdx].RemainLen -= Info->SduLength;
				Dcm_ConnectionStatus[u8ProConIdx].CopyOffset += Info->SduLength;

				if(0u == Dcm_ConnectionStatus[u8ProConIdx].RemainLen)
				{
					Dcm_ConnectionStatus[u8ProConIdx].RxState = DCM_RX_STATE_RECEIVED;
				}

				*BufferSizePtr = (pProtocolRow->DcmDslProtocolRxBufferRef->DcmDslBufferSize - Dcm_ConnectionStatus[u8ProConIdx].CopyOffset);
				result = BUFREQ_OK;
			}
			else
			{
				/* result = BUFREQ_E_NOT_OK. */
				;
			}
		}
	}

	return result;
}

/**
 * @sid				0x45
 * @brief			Dcm_TpRxIndication
 * @details			Called after an I-PDU has been received via the TP API, the result indicates whether
 * 					the transmission was successful or no.
 *
 * @param[in]		Id:Identification of the received I-PDU.
 * @param[in]		Result:Result of the reception.
 *
 * @req [SWS_Dcm_00093]
 */
FUNC(void, DCM_CODE)Dcm_TpRxIndication
(
	PduIdType Id,
	Std_ReturnType Result
)
{
	uint8 u8ProConIdx;
	uint8 u8ProRowIdx;
#if(STD_ON == DCM_DSL_CALLBACK_DCM_REQUEST_SERVICE_ENABLED)
	boolean result = (boolean)TRUE;
#endif /* #if(STD_ON == DCM_DSL_CALLBACK_DCM_REQUEST_SERVICE_ENABLED) */
	const Dcm_DslProtocolRxType* pProtocolRx = NULL_PTR;
	const Dcm_DslProtocolRowType* pProtocolRow = NULL_PTR;

	if((boolean)FALSE == Dcm_InitState)
	{
		DCM_DET_ERROR_REPORT(DCM_SID_TPRXINDICATION, DCM_E_UNINIT);
	}
	else if(DCM_DSL_PROTOCOL_RX_NUM <= Id)
	{
		DCM_DET_ERROR_REPORT(DCM_SID_TPRXINDICATION, DCM_E_PARAM);
	}
	else
	{
		pProtocolRx = &Dcm_ConfigPtr->DcmDslProtocolRx[Id];
		u8ProConIdx = pProtocolRx->DcmDslRxParentConIdx;
		u8ProRowIdx = pProtocolRx->DcmDslRxParentProIdx;

		if((Std_ReturnType)E_OK != Result)
		{
			/* 1.Triggering Concurrent3E on the active protocol and connection;
			 * 2.Triggering Concurrent3E on the active protocol and other connection;
			 * 3.Triggering Concurrent3E on the other higher priority protocol;
			 * If enable DcmDslDiagRespOnSecondDeclinedRequest and request transmit NRC 0x21 success:
			 * 4.Triggering Request on the active protocol and other connection;
			 * 5.Triggering Concurrent3E or Request on the other lower priority protocol. */
			if((boolean)TRUE == Dcm_ConnectionStatus[u8ProConIdx].Concurrent3E)
			{
				Dcm_ConnectionStatus[u8ProConIdx].Concurrent3E = (boolean)FALSE;
			}
			else
			{
				if(DCM_RX_STATE_IDLE != Dcm_ConnectionStatus[u8ProConIdx].RxState)
				{
					DslInternal_ResetConnectionStatus();
				}
			}
		}
		else
		{
			if(DCM_RX_STATE_RECEIVED == Dcm_ConnectionStatus[u8ProConIdx].RxState)
			{
				pProtocolRow = &Dcm_ConfigPtr->DcmDsl->DcmDslProtocolRow[u8ProRowIdx];

				Dcm_MsgContext[u8ProRowIdx].ReqData = pProtocolRow->DcmDslProtocolRxBufferRef->DcmDslBufferRef;
				Dcm_MsgContext[u8ProRowIdx].ReqDataLen = Dcm_ConnectionStatus[u8ProConIdx].CopyOffset;

				/**
				 * @req [SWS_Dcm_00112] When the PduR module calls Dcm_TpRxIndication() with parameter
				 * 		Result=E_OK (see SWS_Dcm_00093) and if the request is a "TesterPresent" command
				 * 		with "suppressPosRspMsgIndicationBit" set to TRUE (SID equal to 0x3E,
				 * 		subfunction equal to 0x80), the DSL submodule shall reset the session timeout
				 * 		timer (S3Server).
				 *
				 * @req [SWS_Dcm_00113] When the PduR module calls Dcm_TpRxIndication() with parameter
				 * 		Result = E_OK (see SWS_Dcm_00093) and if the request is a "TesterPresent"
				 * 		command with "suppressPosRspMsgIndicationBit" set to TRUE (SID equal to 0x3E,
				 * 		subfunction equal to 0x80), the DSL submodule shall not forward this request to
				 * 		the DSD submodule for further interpretation.
				 *
				 * @req [SWS_Dcm_01168] The Dcm shall handle a tester present request as concurrent
				 * 		request only if it was received on a functional address with
				 * 		"suppressPosRspMsgIndicationBit" set to TRUE.
				 */
				if((DCM_DEFAULT_SESSION != Dcm_ActiveSession) &&\
					(DCM_FUNCTIONAL_TYPE == pProtocolRx->DcmDslProtocolRxAddrType) &&\
					(2u == Dcm_MsgContext[u8ProRowIdx].ReqDataLen) &&\
					(0x3Eu == Dcm_MsgContext[u8ProRowIdx].ReqData[0]) &&\
					(0x80u == Dcm_MsgContext[u8ProRowIdx].ReqData[1]))
				{
					Dcm_S3TimerStatus.CurrentTime = 0u;
					DslInternal_ResetConnectionStatus();
				}
				else
				{
					Dcm_MsgContext[u8ProRowIdx].MsgAddInfo |= (uint8)pProtocolRx->DcmDslProtocolRxAddrType;
					Dcm_MsgContext[u8ProRowIdx].ResData = pProtocolRow->DcmDslProtocolTxBufferRef->DcmDslBufferRef;
					Dcm_MsgContext[u8ProRowIdx].ResMaxDataLen = pProtocolRow->DcmDslProtocolTxBufferRef->DcmDslBufferSize;

					/**
					 * @req [SWS_Dcm_00163] If ActiveDiagnostic is "DCM_COMM_ACTIVE" and the Dcm is in
					 * 		default session of a diagnostic protocol the DCM shall call
					 * 		ComM_DCM_ActiveDiagnostic(NetworkId), with the networkId associated to the
					 * 		received Pdu (see DcmDslProtocolComMChannelRef), with every request, to
					 * 		inform the ComM module about the need to stay in Full Communication Mode.
					 *
					 * @req [SWS_Dcm_00169] As long as the server is in a session other than the default
					 * 		session, the DCM shall not call ComM_DCM_ActiveDiagnostic(NetworkId),with
					 * 		the networkId associated to the received Pdu, when receiving a request from
					 * 		a client provided by the PduR module.
					 */
					if(DCM_DEFAULT_SESSION == Dcm_ActiveSession)
					{
						Dcm_ComMStatus[u8ProConIdx].DiagnosticState = DCM_COMM_ACTIVE;
//						ComM_DCM_ActiveDiagnostic(Dcm_ConfigPtr->DcmDslMainConnection[u8ProConIdx].DcmDslProtocolComMChannelRef);
					}

					/**
					 * @req [SWS_Dcm_00036] With first request of a diagnostic protocol, the DSL
					 * 		submodule shall call all configured Xxx_StartProtocol() functions (see
					 * 		configuration parameter DcmDslCallbackDCMRequestService).
					 */
					if(!DCM_CHECK_BIT_SET(Dcm_ProtocolStartState, Dcm_ActiveProRowIdx, uint8))
					{
#if(STD_ON == DCM_DSL_CALLBACK_DCM_REQUEST_SERVICE_ENABLED)
						result = DslInternal_StartProtocol(pProtocolRow);
#else
						DslInternal_StartProtocol();
#endif /* #if(STD_ON != DCM_DSL_CALLBACK_DCM_REQUEST_SERVICE_ENABLED) */
					}
#if(STD_ON == DCM_DSL_CALLBACK_DCM_REQUEST_SERVICE_ENABLED)
					if((boolean)TRUE == result)
					{
#endif /* #if(STD_ON == DCM_DSL_CALLBACK_DCM_REQUEST_SERVICE_ENABLED) */
						Dcm_P2TimerStatus.TimerEnable = (boolean)TRUE;
						/**
						 * @req [SWS_Dcm_00111] The DSL submodule shall forward received data to the DSD
						 * 		submodule only after call of Dcm_TpRxIndication() with parameter Result
						 * 		= E_OK (see SWS_Dcm_00093).
						 */
						Dcm_ConnectionStatus[u8ProConIdx].RxState = DCM_RX_STATE_PROCESS;
#if(STD_ON == DCM_DSL_CALLBACK_DCM_REQUEST_SERVICE_ENABLED)
					}
					else
					{
						/**
						 * @req [SWS_Dcm_00674] If Xxx_StartProtocol() does not return E_OK, the Dcm
						 * 		shall return NRC 0x22.
						 */
						(void)DslInternal_SetNRCAndTransmit(\
								Dcm_MsgContext[u8ProRowIdx].ReqData[0], u8ProConIdx,\
								u8ProRowIdx, DCM_E_CONDITIONSNOTCORRECT, (boolean)TRUE\
								);
					}
#endif /* #if(STD_ON == DCM_DSL_CALLBACK_DCM_REQUEST_SERVICE_ENABLED) */
				}
			}
		}
	}
}

/**
 * @sid				0x43
 * @brief			Dcm_CopyTxData
 * @details			This function is called to acquire the transmit data of an I-PDU segment (N-PDU).
 * 					Each call to this function provides the next part of the I-PDU data unless retry->
 * 					TpDataState is TP_DATARETRY. In this case the function restarts to copy the data
 * 					beginning at the offset from the current position indicated by retry->TxTpDataCnt.
 * 					The size of the remaining data is written to the position indicated by
 * 					availableDataPtr.
 *
 * @param[in]		Id:Identification of the transmitted I-PDU.
 * @param[in]		Info:Provides the destination buffer (SduDataPtr) and the number of bytes to be
 * 					copied (SduLength). If not enough transmit data is available, no data is copied by
 * 					the upper layer module and BUFREQ_E_BUSY is returned. The lower layer module may
 * 					retry the call. An SduLength of 0 can be used to indicate state changes in the
 * 					retry parameter or to query the current amount of available data in the upper layer
 * 					module. In this case, the SduDataPtr may be a NULL_PTR.
 * @param[in]		Retry:This parameter is used to acknowledge transmitted data or to retransmit data
 * 					after transmission problems.
 *
 * @param[out]		AvailableDataPtr:Indicates the remaining number of bytes that are available in the
 * 					upper layer module's Tx buffer. availableDataPtr can be used by TP modules that
 * 					support dynamic payload lengths (e.g. FrIsoTp) to determine the size of the
 * 					following CFs.
 *
 * @return     		Result of this operation.
 * @retval			BUFREQ_OK:Data has been copied to the transmit buffer completely as requested.
 * @retval			BUFREQ_E_BUSY:Request could not be fulfilled, because the required amount of Tx data
 * 					is not available. The lower layer module may retry this call later on. No data has
 * 					been copied.
 * @retval			BUFREQ_E_NOT_OK: Data has not been copied. Request failed.
 *
 * @req [SWS_Dcm_00092]
 */
FUNC(BufReq_ReturnType, DCM_CODE)Dcm_CopyTxData
(
	PduIdType Id,
	P2CONST(PduInfoType, AUTOMATIC, DCM_CONST)Info,
	P2VAR(RetryInfoType, AUTOMATIC, DCM_VAR)Retry,
	P2VAR(PduLengthType, AUTOMATIC, DCM_VAR)AvailableDataPtr
)
{
	BufReq_ReturnType result = BUFREQ_E_NOT_OK;

	uint8 u8ProConIdx;
	uint8 u8ProRowIdx;
#if((STD_ON == DCM_DSL_DIAG_RESP_ON_SECOND_DECLINED_REQUEST) ||\
	(STD_ON == DCM_DSL_CALLBACK_DCM_REQUEST_SERVICE_ENABLED))
	uint8* pResBuffer = NULL_PTR;
#endif /* #if((STD_ON == DCM_DSL_DIAG_RESP_ON_SECOND_DECLINED_REQUEST) ||\
			  (STD_ON == DCM_DSL_CALLBACK_DCM_REQUEST_SERVICE_ENABLED)) */
	const Dcm_DslProtocolTxType* pProtocolTx = NULL_PTR;

	if((boolean)FALSE == Dcm_InitState)
	{
		DCM_DET_ERROR_REPORT(DCM_SID_COPYTXDATA, DCM_E_UNINIT);
	}
	else if(DCM_DSL_PROTOCOL_TX_NUM <= Id)
	{
		DCM_DET_ERROR_REPORT(DCM_SID_COPYTXDATA, DCM_E_PARAM);
	}
	else if((NULL_PTR == Info) || (NULL_PTR == AvailableDataPtr))
	{
		DCM_DET_ERROR_REPORT(DCM_SID_COPYTXDATA, DCM_E_PARAM_POINTER);
	}
	else
	{
		pProtocolTx = &Dcm_ConfigPtr->DcmDslProtocolTx[Id];
		u8ProConIdx = pProtocolTx->DcmDslTxParentConIdx;
		u8ProRowIdx = pProtocolTx->DcmDslTxParentProIdx;

		if(DCM_TX_STATE_COPY == Dcm_ConnectionStatus[u8ProConIdx].TxState)
		{
			if(0u == Info->SduLength)
			{
				*AvailableDataPtr = Dcm_ConnectionStatus[u8ProConIdx].RemainLen;
				result = BUFREQ_OK;
			}
			else
			{
				if((NULL_PTR != Retry) && (TP_DATARETRY == Retry->TpDataState))
				{
					Dcm_ConnectionStatus[u8ProConIdx].CopyOffset -= Retry->TxTpDataCnt;
					Dcm_ConnectionStatus[u8ProConIdx].RemainLen += Retry->TxTpDataCnt;
				}

				if(Info->SduLength <= Dcm_ConnectionStatus[u8ProConIdx].RemainLen)
				{
#if((STD_ON == DCM_DSL_DIAG_RESP_ON_SECOND_DECLINED_REQUEST) ||\
	(STD_ON == DCM_DSL_CALLBACK_DCM_REQUEST_SERVICE_ENABLED))
					if((DCM_RX_STATE_IDLE == Dcm_ConnectionStatus[u8ProConIdx].RxState) &&\
						(NULL_PTR == Dcm_MsgContext[u8ProRowIdx].ResData))
					{
						pResBuffer = &Dcm_NRCBuffer[Dcm_ConnectionStatus[u8ProConIdx].CopyOffset];
					}
					else if(NULL_PTR != Dcm_MsgContext[u8ProRowIdx].ResData)
					{
						pResBuffer = &Dcm_MsgContext[u8ProRowIdx].ResData[Dcm_ConnectionStatus[u8ProConIdx].CopyOffset];
					}
					else
					{
						return BUFREQ_E_NOT_OK;
					}

					DCM_MEMORY_COPY(pResBuffer, Info->SduDataPtr, Info->SduLength);
#else
					if(NULL_PTR == Dcm_MsgContext[u8ProRowIdx].ResData)
					{
						return BUFREQ_E_NOT_OK;
					}
					DCM_MEMORY_COPY(\
							&Dcm_MsgContext[u8ProRowIdx].ResData[Dcm_ConnectionStatus[u8ProConIdx].CopyOffset],\
							Info->SduDataPtr,\
							Info->SduLength\
							);
#endif /* #if((STD_ON == DCM_DSL_DIAG_RESP_ON_SECOND_DECLINED_REQUEST) ||\
			  (STD_ON == DCM_DSL_CALLBACK_DCM_REQUEST_SERVICE_ENABLED)) */

					Dcm_ConnectionStatus[u8ProConIdx].CopyOffset += Info->SduLength;
					Dcm_ConnectionStatus[u8ProConIdx].RemainLen -= Info->SduLength;

					if(0u == Dcm_ConnectionStatus[u8ProConIdx].RemainLen)
					{
						Dcm_ConnectionStatus[u8ProConIdx].TxState = DCM_TX_STATE_CONFIRM;
					}

					*AvailableDataPtr = Dcm_ConnectionStatus[u8ProConIdx].RemainLen;
					result = BUFREQ_OK;
				}
				else
				{
					result = BUFREQ_E_BUSY;
				}
			}
		}
	}

	return result;
}

/**
 * @sid				0x48
 * @brief			Dcm_TpTxConfirmation
 * @details			This function is called after the I-PDU has been transmitted on its network, the
 * 					result indicates whether the transmission was successful or not.
 *
 * @param[in]		Id:Identification of the transmitted I-PDU.
 * @param[in] 		Result:Result of the transmission of the I-PDU.
 *
 * @req [SWS_Dcm_00351]
 */
FUNC(void, DCM_CODE)Dcm_TpTxConfirmation
(
	PduIdType Id,
	Std_ReturnType Result
)
{
	uint8 u8ProConIdx;
	uint8 u8ProRowIdx;
#if(0u != DCM_DSL_DIAG_RESP_MAX_NUM_RESP_PEND)
	boolean result = (boolean)TRUE;
#endif /* #if(0u != DCM_DSL_DIAG_RESP_MAX_NUM_RESP_PEND) */
	const Dcm_DslProtocolTxType* pProtocolTx = NULL_PTR;

	if((boolean)FALSE == Dcm_InitState)
	{
		DCM_DET_ERROR_REPORT(DCM_SID_TPTXCONFIRMATION, DCM_E_UNINIT);
	}
	else if(DCM_DSL_PROTOCOL_TX_NUM <= Id)
	{
		DCM_DET_ERROR_REPORT(DCM_SID_TPTXCONFIRMATION, DCM_E_PARAM);
	}
	else
	{
		/**
		 * @req [SWS_Dcm_00117] If the DSL submodule receives a confirmation after the complete DCM
		 * 		PDU has successfully been transmitted or an error occurred by a call of
		 * 		Dcm_TpTxConfirmation(), then the DSL submodule shall forward this confirmation to the
		 * 		DSD submodule.
		 *
		 * @req [SWS_Dcm_00118] In case of a failed transmission (failed PduR_DcmTransmit() request)
		 * 		or error confirmation (Dcm_TpTxConfirmation() with error), the DSD submodule shall not
		 * 		repeat the diagnostic response transmission.
		 */

		pProtocolTx = &Dcm_ConfigPtr->DcmDslProtocolTx[Id];
		u8ProConIdx = pProtocolTx->DcmDslTxParentConIdx;
		u8ProRowIdx = pProtocolTx->DcmDslTxParentProIdx;

		if((DCM_TX_STATE_IDLE != Dcm_ConnectionStatus[u8ProConIdx].TxState) &&\
			(DCM_TX_STATE_WAITING != Dcm_ConnectionStatus[u8ProConIdx].TxState))
		{
#if((STD_ON == DCM_DSL_CALLBACK_DCM_REQUEST_SERVICE_ENABLED) ||\
	(STD_ON == DCM_DSL_DIAG_RESP_ON_SECOND_DECLINED_REQUEST))
			if(DCM_RX_STATE_IDLE == Dcm_ConnectionStatus[u8ProConIdx].RxState)
			{
				Dcm_ConnectionStatus[u8ProConIdx].TxState = DCM_TX_STATE_IDLE;
				Dcm_ConnectionStatus[u8ProConIdx].RemainLen = (PduLengthType)0;
				Dcm_ConnectionStatus[u8ProConIdx].CopyOffset = (PduLengthType)0;

				Dcm_MsgContext[u8ProRowIdx].ResData = NULL_PTR;
			}
			else
#endif /* #if((STD_ON == DCM_DSL_CALLBACK_DCM_REQUEST_SERVICE_ENABLED) ||\
 	 	     (STD_ON == DCM_DSL_DIAG_RESP_ON_SECOND_DECLINED_REQUEST)) */
			{
				/**
				 * @req [SWS_Dcm_00235] The DSL submodule shall forward the received confirmation from
				 * 		the PduR module to the DSD submodule.
				 */
				if((Std_ReturnType)E_OK == Result)
				{
#if(0u != DCM_DSL_DIAG_RESP_MAX_NUM_RESP_PEND)
					result = DsdInternal_TpTxConfirmation();
#else
					(void)DsdInternal_TpTxConfirmation();
#endif /* #if(0u != DCM_DSL_DIAG_RESP_MAX_NUM_RESP_PEND) */
				}

#if(0u != DCM_DSL_DIAG_RESP_MAX_NUM_RESP_PEND)
				if((boolean)TRUE == result)
#endif /* #if(0u != DCM_DSL_DIAG_RESP_MAX_NUM_RESP_PEND) */
				{
					/* Do not wipe the static RCRRP template (PendBuffer). Clearing it yields
					 * a later SF 74 03 00 00 00 when length-3 is transmitted again. */
					if((NULL_PTR != Dcm_MsgContext[u8ProRowIdx].ResData) &&\
						(3u != Dcm_MsgContext[u8ProRowIdx].ResDataLen ||\
						 (uint8)0x78u != Dcm_MsgContext[u8ProRowIdx].ResData[2]))
					{
						DCM_BUFFER_CLEAR(Dcm_MsgContext[u8ProRowIdx].ResData, Dcm_MsgContext[u8ProRowIdx].ResDataLen);
					}

					DslInternal_ResetConnectionStatus();
				}
			}
		}
	}
}

/**
 * @sid				0x40
 * @brief			Dcm_TxConfirmation
 * @details			The lower layer communication interface module confirms the transmission of an
 * 					I-PDU.
 *
 * @param[in]		TxPduId:ID of the I-PDU that has been transmitted.
 *
 * @req [SWS_Dcm_01092]
 */
FUNC(void, DCM_CODE)Dcm_TxConfirmation
(
	PduIdType TxPduId
)
{
	if((boolean)FALSE == Dcm_InitState)
	{
		DCM_DET_ERROR_REPORT(DCM_SID_TXCONFIRMATION, DCM_E_UNINIT);
	}
	else if((DCM_DSL_PROTOCOL_TX_NUM > TxPduId) ||\
			((DCM_DSL_PROTOCOL_TX_NUM + DCM_DSL_PERIODIC_CONNECTION_NUM) <= TxPduId))
	{
		DCM_DET_ERROR_REPORT(DCM_SID_TXCONFIRMATION, DCM_E_PARAM);
	}
	else
	{
#if(STD_ON == DCM_UDS0x2A_ENABLE)
		DCM_BIT_CLEAR(Dcm_PeriodicTransStatus.ChannelStatus, (TxPduId - DCM_DSL_PROTOCOL_TX_NUM), uint16);
#else
		;
#endif /* #if(STD_ON == DCM_UDS0x2A_ENABLE) */
	}
}

/**
 * @sid				0x21
 * @brief			Dcm_ComM_NoComModeEntered
 * @details     	This call informs the Dcm module about a ComM mode change to COMM_NO_COMMUNICATION.
 *
 * @param[in]   	NetworkId:Identifier of the network concerned by the mode change.
 *
 * @req [SWS_Dcm_00356]
 */
FUNC(void, DCM_CODE)Dcm_ComM_NoComModeEntered
(
	uint8 NetworkId
)
{
	uint8 u8Index;
	const Dcm_DslMainConnectionType* pConnection = NULL_PTR;

	if((boolean)FALSE == Dcm_InitState)
	{
		DCM_DET_ERROR_REPORT(DCM_SID_COMMNOCOMMODEENTERED, DCM_E_UNINIT);
	}
	else
	{
		for(u8Index = 0u; u8Index < DCM_DSL_MAIN_CONNECTION_NUM; u8Index++)
		{
			pConnection = &Dcm_ConfigPtr->DcmDslMainConnection[u8Index];

			if(NetworkId == pConnection->DcmDslProtocolComMChannelRef)
			{
				Dcm_ComMStatus[u8Index].CommunicationState = DCM_COMM_NO_COMMUNICATION;
				break;
			}
		}
	}
}

/**
 * @sid				0x22
 * @brief			Dcm_ComM_SilentComModeEntered
 * @details     	This call informs the Dcm module about a ComM mode change to
 * 					COMM_SILENT_COMMUNICATION.
 *
 * @param[in]   	NetworkId:Identifier of the network concerned by the mode change.
 *
 * @req [SWS_Dcm_00358]
 */
FUNC(void, DCM_CODE)Dcm_ComM_SilentComModeEntered
(
	uint8 NetworkId
)
{
	uint8 u8Index;
	const Dcm_DslMainConnectionType* pConnection = NULL_PTR;

	if((boolean)FALSE == Dcm_InitState)
	{
		DCM_DET_ERROR_REPORT(DCM_SID_COMMSILENTCOMMODEENTERED, DCM_E_UNINIT);
	}
	else
	{
		for(u8Index = 0u; u8Index < DCM_DSL_MAIN_CONNECTION_NUM; u8Index++)
		{
			pConnection = &Dcm_ConfigPtr->DcmDslMainConnection[u8Index];

			if(NetworkId == pConnection->DcmDslProtocolComMChannelRef)
			{
				Dcm_ComMStatus[u8Index].CommunicationState = DCM_COMM_SILENT_COMMUNICATION;
				break;
			}
		}
	}
}

/**
 * @sid				0x23
 * @brief			Dcm_ComM_FullComModeEntered
 * @details     	This call informs the Dcm module about a ComM mode change to
 * 					COMM_FULL_COMMUNICATION.
 *
 * @param[in]   	NetworkId:Identifier of the network concerned by the mode change.
 *
 * @req [SWS_Dcm_00360]
 */
FUNC(void, DCM_CODE)Dcm_ComM_FullComModeEntered
(
	uint8 NetworkId
)
{
	uint8 u8Index;
	const Dcm_DslMainConnectionType* pConnection = NULL_PTR;

	if((boolean)FALSE == Dcm_InitState)
	{
		DCM_DET_ERROR_REPORT(DCM_SID_COMMFULLCOMMODEENTERED, DCM_E_UNINIT);
	}
	else
	{
		for(u8Index = 0u; u8Index < DCM_DSL_MAIN_CONNECTION_NUM; u8Index++)
		{
			pConnection = &Dcm_ConfigPtr->DcmDslMainConnection[u8Index];

			if(NetworkId == pConnection->DcmDslProtocolComMChannelRef)
			{
				Dcm_ComMStatus[u8Index].CommunicationState = DCM_COMM_FULL_COMMUNICATION;

				/**
				 * @req [SWS_Dcm_00767] When the ComM reports full communication to the Dcm, the Dcm
				 * 		shall send the Response to the Service Id passed in the Dcm_ProgConditionsType.
				 */
				if(DCM_TX_STATE_WAITING == Dcm_ConnectionStatus[u8Index].TxState)
				{
					DslInternal_TransmitHandle(pConnection->DcmDslProtocolTx->DcmDslProtocolTxPduRef);
				}
				break;
			}
		}
	}
}

/**
 * @sid				0x25
 * @brief			Dcm_MainFunction
 * @details			This service is used for processing the tasks of the main loop.
 *
 * @req [SWS_Dcm_00053]
 */
FUNC(void, DCM_CODE)Dcm_MainFunction
(
	void
)
{
	if((boolean)FALSE == Dcm_InitState)
	{
		DCM_DET_ERROR_REPORT(DCM_SID_MAINFUNCTION, DCM_E_UNINIT);
	}
	else
	{
		DslInternal_TimerProcess();

#if(STD_ON == DCM_UDS0x27_ENABLE)
		DspInternal_SecurityTimerHandle();
#endif /* #if(STD_ON == DCM_UDS0x27_ENABLE) */

#if(STD_ON == DCM_UDS0x2A_ENABLE)
		DspInternal_PeriodicTransmission();
#endif /* #if(STD_ON == DCM_UDS0x2A_ENABLE) */

#if(0u != DCM_DSL_DIAG_RESP_MAX_NUM_RESP_PEND)
		DslInternal_PendingProcess();
#endif /* #if(0u != DCM_DSL_DIAG_RESP_MAX_NUM_RESP_PEND) */

		DsdInternal_ServiceProcess();
	}
}

#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#ifdef __cplusplus
}
#endif
/** @} */
