/**
 * @file        ComM_Internal.c
 * @brief       Implementation for ComM
 * @version     1.2.0
 * @addtogroup  ComM
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

/* PRQA S 0292, 0288, 1503, 1505, 0857, 0791, 0828, 0647, 2877, 3200, 0491, 5087 EOF #
*
* 1.0292 -- Violates MISRA 2004 Required Rule 3.1, Source file has comments containing one of the* characters '$', '@' or '`'.
*
* 2.0288 -- Violates MISRA 2004 Required Rule 3.1, Source file has comments containing characters* which are not members of the basic source character set.
*
* 3.1503 -- Violates MISRA 2004 Required Rule 14.1, The function is defined but is not used within* this project.
*
* 4.1505 -- Violates MISRA 2004 Required Rule 8.10, The function is only referenced in the translation* unit where it is defined.
*
* 5.0857 -- Violates MISRA 2004 Required Rule 1.1, Number of macro definitions exceeds 1024 - program* does not conform strictly to ISO:C90.
*
* 6.0791 -- Violates MISRA 2004 Required Rule 5.1, Macro identifier does not differ from other macro* identifier(s) within the specified number of significant characters.
*
* 7.0828 -- Violates MISRA 2004 Required Rule 1.1, More than 8 levels of nested conditional inclusion* - program does not conform strictly to ISO:C90.
*
* 8.0647 -- Violates MISRA 2004 Required Rule 1.1, Number of enumeration constants exceeds 127-program
* does not conform strictly to ISO:C90.
*
* @page misra_violations MISRA-C:2004 violations
*/
/*====================================================================================================*
 *                                           INCLUDE FILES
 *====================================================================================================*/
#ifdef RTE_CODE
#include "Rte_ComM.h"
#include "Rte_ComM_Type.h"
#endif

#include "ComM.h"
#include "ComM_Internal.h"

#if (STD_ON == COMM_BUS_CAN_USED)
#include "CanSM_ComM.h"
#endif

#if (STD_ON == COMM_DCM_USED)
#include "Dcm_Cbk.h"
#endif

#if (STD_ON == COMM_NVM_USED)
#include "Nvm.h"
#endif /*#if (STD_ON == COMM_NVM_USED)*/

#if (STD_ON == COMM_BUS_CDD_USED)
#include "Cdd.h"
#endif /* (STD_OFF == COMM_BUS_CDD_USED) */

#if (STD_ON == COMM_BUS_ETH_USED)
#include "EthSM.h"
#endif /* (STD_OFF == COMM_BUS_ETH_USED) */

#if (STD_ON == COMM_BUS_FLEXRAY_USED)
#include "FrSM.h"
#endif /* (STD_OFF == COMM_BUS_FLEXRAY_USED) */

#if (STD_ON == COMM_BUS_LIN_USED)
#include "LinSM.h"
#endif /* (STD_OFF == COMM_BUS_LIN_USED) */

#if defined(AH_TEST_COMM)
#include "TestCode.h"
#endif /* AH_TEST_COMM */

/*====================================================================================================*
 *                                  SOURCE FILE VERSION INFORMATION
 *====================================================================================================*/
#define COMM_INTERNAL_VENDOR_ID_C                   0U
#define COMM_INTERNAL_AR_RELEASE_MAJOR_VERSION_C    4U
#define COMM_INTERNAL_AR_RELEASE_MINOR_VERSION_C    2U
#define COMM_INTERNAL_AR_RELEASE_REVISION_VERSION_C 2U
#define COMM_INTERNAL_SW_MAJOR_VERSION_C            1U
#define COMM_INTERNAL_SW_MINOR_VERSION_C            2U
#define COMM_INTERNAL_SW_PATCH_VERSION_C            0U

/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/

/* Check if current file and ComM_Internal.h header file are of the same vendor  */
#if(COMM_INTERNAL_VENDOR_ID_C != COMM_INTERNAL_VENDOR_ID )
#error "ComM_Internal.c and ComM_Internal.h have different vendor id"
#endif
/* Check if current file and ComM_Internal.h header file are of the same Autosar version  */
#if(\
      (COMM_INTERNAL_AR_RELEASE_MAJOR_VERSION_C != COMM_INTERNAL_AR_RELEASE_MAJOR_VERSION) || \
      (COMM_INTERNAL_AR_RELEASE_MINOR_VERSION_C != COMM_INTERNAL_AR_RELEASE_MINOR_VERSION) || \
      (COMM_INTERNAL_AR_RELEASE_REVISION_VERSION_C != COMM_INTERNAL_AR_RELEASE_REVISION_VERSION) \
      )
#error "AutoSar Version Number of ComM_Internal.c and ComM_Internal.h are different "
#endif
/* Check if current file and ComM_Internal.h header file are of the same software version  */
#if(\
      (COMM_INTERNAL_SW_MAJOR_VERSION_C != COMM_INTERNAL_SW_MAJOR_VERSION) || \
      (COMM_INTERNAL_SW_MINOR_VERSION_C != COMM_INTERNAL_SW_MINOR_VERSION) ||\
	  (COMM_INTERNAL_SW_PATCH_VERSION_C != COMM_INTERNAL_SW_PATCH_VERSION)\
      )
#error "Software Version Number of ComM_Internal.c and ComM_Internal.h are different "
#endif



/* Check if current file and ComM.h header file are of the same vendor  */
#if(COMM_INTERNAL_VENDOR_ID_C != COMM_VENDOR_ID )
#error "ComM_Internal.c and ComM.h have different vendor id"
#endif

/* Check if current file and ComM.h header file are of the same Autosar version  */
#if(\
      (COMM_INTERNAL_AR_RELEASE_MAJOR_VERSION_C != COMM_AR_RELEASE_MAJOR_VERSION) || \
      (COMM_INTERNAL_AR_RELEASE_MINOR_VERSION_C != COMM_AR_RELEASE_MINOR_VERSION) || \
      (COMM_INTERNAL_AR_RELEASE_REVISION_VERSION_C != COMM_AR_RELEASE_REVISION_VERSION) \
      )
#error "AutoSar Version Number of ComM_Internal.c and ComM.h are different "
#endif

/* Check if current file and ComM.h header file are of the same software version  */
#if(\
      (COMM_INTERNAL_SW_MAJOR_VERSION_C != COMM_SW_MAJOR_VERSION) || \
      (COMM_INTERNAL_SW_MINOR_VERSION_C != COMM_SW_MINOR_VERSION) ||\
	  (COMM_INTERNAL_SW_PATCH_VERSION_C != COMM_SW_PATCH_VERSION)\
      )
#error "Software Version Number of ComM_Internal.c and ComM.h are different "
#endif

#ifndef DISABLE_INTERMOD_VERSION_CHECK

#if (STD_ON == COMM_BUS_CDD_USED)
#if(\
      (COMM_INTERNAL_AR_RELEASE_MAJOR_VERSION_C != CDD_AR_RELEASE_MAJOR_VERSION) || \
      (COMM_INTERNAL_AR_RELEASE_MINOR_VERSION_C != CDD_AR_RELEASE_MINOR_VERSION) \
      )
#error "AutoSar Version Number of ComM_Internal.c and Cdd.h are different "
#endif
#endif /* (STD_OFF == COMM_BUS_CDD_USED) */

#if (STD_ON == COMM_BUS_ETH_USED)
#if(\
      (COMM_INTERNAL_AR_RELEASE_MAJOR_VERSION_C != ETHSM_AR_RELEASE_MAJOR_VERSION) || \
      (COMM_INTERNAL_AR_RELEASE_MINOR_VERSION_C != ETHSM_AR_RELEASE_MINOR_VERSION) \
      )
#error "AutoSar Version Number of ComM_Internal.c and EthSM.h are different "
#endif
#endif /* (STD_OFF == COMM_BUS_ETH_USED) */

#if (STD_ON == COMM_BUS_FLEXRAY_USED)
#if(\
      (COMM_INTERNAL_AR_RELEASE_MAJOR_VERSION_C != FRSM_AR_RELEASE_MAJOR_VERSION) || \
      (COMM_INTERNAL_AR_RELEASE_MINOR_VERSION_C != FRSM_AR_RELEASE_MINOR_VERSION) \
      )
#error "AutoSar Version Number of ComM_Internal.c and FrSM.h are different "
#endif
#endif /* (STD_OFF == COMM_BUS_FLEXRAY_USED) */

#if (STD_ON == COMM_BUS_LIN_USED)
#if(\
      (COMM_INTERNAL_AR_RELEASE_MAJOR_VERSION_C != LINSM_AR_RELEASE_MAJOR_VERSION) || \
      (COMM_INTERNAL_AR_RELEASE_MINOR_VERSION_C != LINSM_AR_RELEASE_MINOR_VERSION) \
      )
#error "AutoSar Version Number of ComM_Internal.c and LinSM.h are different "
#endif
#endif /* (STD_OFF == COMM_BUS_LIN_USED) */


#if (STD_ON == COMM_DCM_USED)
/* Check if current file and Dcm_Cbk.h header file are of the same Autosar version  */
#if(\
      (COMM_INTERNAL_AR_RELEASE_MAJOR_VERSION_C != DCM_CBK_AR_RELEASE_MAJOR_VERSION) || \
      (COMM_INTERNAL_AR_RELEASE_MINOR_VERSION_C != DCM_CBK_AR_RELEASE_MINOR_VERSION) \
      )
#error "AutoSar Version Number of ComM_Internal.c and Dcm_Cbk.h are different "
#endif
#endif

#if (STD_ON == COMM_BUS_CAN_USED)
/* Check if current file and CanSM_ComM.h header file are of the same Autosar version  */
#if(\
      (COMM_INTERNAL_AR_RELEASE_MAJOR_VERSION_C != CANSM_COMM_AR_RELEASE_MAJOR_VERSION) || \
      (COMM_INTERNAL_AR_RELEASE_MINOR_VERSION_C != CANSM_COMM_AR_RELEASE_MINOR_VERSION)\
      )
#error "AutoSar Version Number of ComM_Internal.c and CanSM_ComM.h are different "
#endif
#endif

#ifdef RTE_CODE
/* Check if current file and Rte_ComM.h header file are of the same Autosar version  */
#if(\
      (COMM_INTERNAL_AR_RELEASE_MAJOR_VERSION_C != RTE_COMM_AR_RELEASE_MAJOR_VERSION) || \
      (COMM_INTERNAL_AR_RELEASE_MINOR_VERSION_C != RTE_COMM_AR_RELEASE_MINOR_VERSION)\
      )
#error "AutoSar Version Number of ComM_Internal.c and Rte_ComM.h are different "
#endif

/* Check if current file and Rte_ComM_Type.h header file are of the same Autosar version  */
#if(\
      (COMM_INTERNAL_AR_RELEASE_MAJOR_VERSION_C != RTE_COMM_TYPE_AR_RELEASE_MAJOR_VERSION) || \
      (COMM_INTERNAL_AR_RELEASE_MINOR_VERSION_C != RTE_COMM_TYPE_AR_RELEASE_MINOR_VERSION)\
      )
#error "AutoSar Version Number of ComM_Internal.c and Rte_ComM_Type.h are different "
#endif

#endif

#if (STD_ON == COMM_NVM_USED)
#include "Nvm.h"
/* Check if current file and Nvm.h header file are of the same Autosar version  */
#if(\
      (COMM_INTERNAL_AR_RELEASE_MAJOR_VERSION_C != NVM_AR_RELEASE_MAJOR_VERSION) || \
      (COMM_INTERNAL_AR_RELEASE_MINOR_VERSION_C != NVM_AR_RELEASE_MINOR_VERSION) \
      )
#error "AutoSar Version Number of ComM_Internal.c and Nvm.h are different "
#endif
#endif

#endif

/*====================================================================================================*
 *                                   EXTERNAL FUNCTION DECLARATIONS
 *====================================================================================================*/

/**
 * @req [SWS_ComM_00402] The ComM module shall use the corresponding interfaces of the Bus State Manager
 * 						 modules to control the communication capabilities.
 */
/**
 * @brief Define a map of the bus type to the bus processing function about change the communication
 * 		  mode to the requested one.
 */
#define COMM_START_SEC_VAR_INIT_UNSPECIFIED
#include "ComM_MemMap.h"

STATIC ComM_SMReqComMode ComM_SMRequestComModeTable[COMM_BUS_TYPE_COUT] = {
#if (STD_ON == COMM_BUS_CAN_USED)
	&CanSM_RequestComMode,/*COMM_BUS_TYPE_CAN*/
#else
	NULL_PTR,
#endif
#if (STD_ON == COMM_BUS_CDD_USED)
	&CddSM_RequestComMode,/*COMM_BUS_TYPE_CDD*/
#else
	NULL_PTR,
#endif
#if (STD_ON == COMM_BUS_ETH_USED)
	&EthSM_RequestComMode,/*COMM_BUS_TYPE_ETH*/
#else
	NULL_PTR,
#endif
#if (STD_ON == COMM_BUS_FLEXRAY_USED)
	&FrSM_RequestComMode,/*COMM_BUS_TYPE_FR*/
#else
	NULL_PTR,
#endif
	NULL_PTR,/*COMM_BUS_TYPE_INTERNAL*/
#if (STD_ON == COMM_BUS_LIN_USED)
	&LinSM_RequestComMode/*COMM_BUS_TYPE_LIN*/
#else
	NULL_PTR
#endif
};

#define COMM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "ComM_MemMap.h"


#define COMM_START_SEC_VAR_INIT_UNSPECIFIED
#include "ComM_MemMap.h"

/**
 * @brief Define a map of the  current mode type to the bus ModeIndication function .
 */
/* PRQA S 3218 EOF # violate MSIAR2004_8.7:ignore this warnning */
STATIC ComM_ModeIndication ComM_ModeIndicationTable[COMM_MODE_COUT] =
#if (STD_ON == COMM_DCM_USED)
{
	&Dcm_ComM_NoComModeEntered,/*COMM_NO_COMMUNICATION*/
	&Dcm_ComM_SilentComModeEntered,/*COMM_SILENT_COMMUNICATION*/
	&Dcm_ComM_FullComModeEntered/*COMM_FULL_COMMUNICATION*/
};
#else
{
	NULL_PTR,
	NULL_PTR,
	NULL_PTR
};
#endif

#define COMM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "ComM_MemMap.h"


#define COMM_START_SEC_VAR_INIT_UNSPECIFIED
#include "ComM_MemMap.h"

/**
 * @req [SWS_ComM_00803] The Communication Manager module shall use
 * 						<BusSm>_GetCurrentComMode() from the State Manager to
 * 						query the current communication mode if necessary.
 */
/**
 * @brief Define a map of the bus type to get bus mode function
 */
ComM_SMGetComMode ComM_SMGetComModeTable[COMM_BUS_TYPE_COUT] = {
#if (STD_ON == COMM_BUS_CAN_USED)
	&CanSM_GetCurrentComMode,/*COMM_BUS_TYPE_CAN*/
#else
	NULL_PTR,
#endif
#if (STD_ON == COMM_BUS_CDD_USED)
	&CddSM_GetCurrentComMode,/*COMM_BUS_TYPE_CDD*/
#else
	NULL_PTR,
#endif
#if (STD_ON == COMM_BUS_ETH_USED)
	&EthSM_GetCurrentComMode,/*COMM_BUS_TYPE_ETH*/
#else
	NULL_PTR,
#endif
#if (STD_ON == COMM_BUS_FLEXRAY_USED)
	&FrSM_GetCurrentComMode,/*COMM_BUS_TYPE_FR*/
#else
	NULL_PTR,
#endif
	&ComM_IntGetCurrentComMode,/*COMM_BUS_TYPE_INTERNAL*/
#if (STD_ON == COMM_BUS_LIN_USED)
	&LinSM_GetCurrentComMode,/*COMM_BUS_TYPE_LIN*/
#else
	NULL_PTR
#endif
};

#define COMM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "ComM_MemMap.h"

#if (STD_ON == COMM_NM_USED)
#define COMM_START_SEC_VAR_NO_INIT_BOOLEAN
#include "ComM_MemMap.h"

STATIC VAR(boolean, COMM_VAR) ComM_NmNetworkRequestflag[COMM_NUMBER_OF_CHANNELS];

#define COMM_STOP_SEC_VAR_NO_INIT_BOOLEAN
#include "ComM_MemMap.h"
#endif /*#if (STD_ON == COMM_NM_USED)*/
/*====================================================================================================*
 *                                           LOCAL TYPEDEFS
 *====================================================================================================*/

/*====================================================================================================*
 *                                            LOCAL MACROS
 *====================================================================================================*/

/*====================================================================================================*
 *                                      LOCAL FUNCTION PROTOTYPES
 *====================================================================================================*/

/*====================================================================================================*
 *                                           LOCAL CONSTANTS
 *====================================================================================================*/

/*====================================================================================================*
 *                                           LOCAL VARIABLES
 *====================================================================================================*/

/*====================================================================================================*
 *                                           LOCAL FUNCTIONS
 *====================================================================================================*/


/*====================================================================================================*
 *                                          GLOBAL FUNCTIONS
 *====================================================================================================*/
#define COMM_START_SEC_CODE
#include "ComM_MemMap.h"

/**
 * @brief         This function is used to determine the COMM_NO_COM_NO_PENDING_REQUEST State conversion
 * 				  conditions that are satisfied on COMMM_FULL
 * @param[in]     Channel, network channel
 * @param[out]    /
 * @param[in/out] /
 * @return        /
 * @retval		  /
 */
FUNC(void, COMM_CODE)ComM_NoComCheck(
	CONST(NetworkHandleType, CANTP_CONST) Channel
)
{
#if (STD_ON == COMM_SYNCHRONOUS_WAKE_UP)
	uint8 chIndex;
#endif/* (STD_ON == COMM_SYNCHRONOUS_WAKE_UP)*/
	/**
	 * @req [SWS_ComM_00875] In sub-state COMM_NO_COM_NO_PENDING_REQUEST and user requests
	 * 						  COMM_FULL_COMMUNICATION and communication limitation is disabled
	 * 						  , the ComM channel state machine shall immediately switch to
	 * 						  sub-state COMM_NO_COM_REQUEST_PENDING.
	 */
	/**
	 * @req [SWS_ComM_00302] Bus wake up Inhibition shall be performed by ignoring user
	 * 						 requests.
	 */
	/**
	 * @req [SWS_ComM_00218] A communication request (COMM_FULL_COMMUNICATION) by a user shall
	 * 						 be inhibited if the ComM Inhibition status is equal to ComMNoWakeup=TRUE
	 * 						 for the corresponding channel and the current state of the channel is
	 * 						 COMM_NO_COMMUNICATION or COMM_SILENT_COMMUNICATION
	 */
	if (((ComM_ChannelInfo[Channel].UserReqFullNum > 0u)
	#if (COMM_MODE_LIMITATION_ENABLED == STD_ON)
		&& (!(((ComM_GlobalInfo.EcuGroupClassification & COMM_MASK_LIMIT_TO_NOCOM) == \
		COMM_MASK_LIMIT_TO_NOCOM) && (((boolean)TRUE == ComM_GlobalInfo.ComM_EcuToNoCom) || \
		((ComM_GlobalInfo.inhibitStatu[Channel] & COMM_MASK_LIMIT_TO_NOCOM) == \
		COMM_MASK_LIMIT_TO_NOCOM))))
		#endif /* (COMM_MODE_LIMITATION_ENABLED == STD_ON)*/
		#if (COMM_WAKEUP_INHIBITION_ENABLED == STD_ON)
		  && (!((ComM_GlobalInfo.EcuGroupClassification & COMM_MASK_INHIBIT_WAKEUP) && \
		  (ComM_GlobalInfo.inhibitStatu[Channel]\
				  & COMM_MASK_INHIBIT_WAKEUP)))
		#endif /* (COMM_WAKEUP_INHIBITION_ENABLED == STD_ON)*/
	)
		/**
		 * @req [SWS_ComM_00876] In sub-state COMM_NO_COM_NO_PENDING_REQUEST,configuration
		 * 						  parameter ComMNmVariant=FULL|LIGHT|NONE and DCM indicate
		 * 						  ComM_DCM_ActiveDiagnostic(SWS_ComM_00873), the ComM channel
		 * 						  state machine shall immediately switch to sub-state
		 * 						  COMM_NO_COM_REQUEST_PENDING.
		 */
		#if (STD_ON == COMM_DCM_USED)
		||(((boolean)TRUE == ComM_ChannelInfo[Channel].EventFlags.DcmActive)&&\
				(COMM_PASSIVE != ComM_ConfigPtr->ComMChannelCfgInfo[Channel].ComMNmVariant))
		#endif /*#if (STD_ON == COMM_DCM_USED)*/
		/**
		 * @req [SWS_ComM_00893] In sub-state COMM_NO_COM_NO_PENDING_REQUEST and a
		 * 						  wake-up-indication is indicated by the EcuM module,
		 * 						  ComM_EcuM_WakeUpIndication(), the ComMSpecification of
		 * 						  Communication Manager channel state machine shall immediately
		 * 						  switch to sub-state COMM_NO_COM_REQUEST_PENDING.
		 */
		||((boolean)TRUE == ComM_ChannelInfo[Channel].EventFlags.EcuMWakeupInd)
		/**
		 * @req [SWS_ComM_00894] In sub-state COMM_NO_COM_NO_PENDING_REQUEST and the NM module
		 * 						  indicates a restart, ComM_Nm_RestartIndication() ,the ComM
		 * 						  channel state machine shall immediately switch to sub-state
		 * 						  COMM_NO_COM_REQUEST_PENDING.
		 */
		/**
		 * @req [SWS_ComM_00583] The ComM module shall switch channel X to COMM_FULL_COMMUNICATION
		 * 						 if NM indicates ComM_Nm_NetworkStartIndication(<channel X>) and
		 * 						 CommunicationAllowed flag is set to TRUE.
		 */
		#if (STD_ON == COMM_NM_USED)
		||((boolean)TRUE == ComM_ChannelInfo[Channel].EventFlags.NmReStart)
		||((boolean)TRUE == ComM_ChannelInfo[Channel].EventFlags.NmStart)
		#endif /* (STD_ON == COMM_NM_USED)*/
	)
	{
		/*It will be converted to a higher communication state*/
	   ComM_ChannelInfo[Channel].AllowedConditionType = COMM_ALLOWED_TO_FULLCOM;
		/**
		 * @req [SWS_ComM_00694] In sub-state COMM_NO_COM_NO_PENDING_REQUEST and configuration
		 * 						  parameter ComMSynchronousWakeUp=(boolean)TRUE and a wake-up-indication
		 * 						  of a channel is indicated by the EcuM, the ComM module shall
		 * 						  immediately switch all ComM channel state machines (resp.
		 * 						  channels) to sub-state COMM_NO_COM_REQUEST_PENDING.
		 */
		#if (STD_ON == COMM_SYNCHRONOUS_WAKE_UP)
			if((boolean)TRUE == ComM_ChannelInfo[Channel].EventFlags.EcuMWakeupInd)
			{
				for (chIndex = 0u; chIndex < COMM_NUMBER_OF_CHANNELS; chIndex++)
				{
					ComM_ChannelInfo[chIndex].AllowedConditionType = COMM_ALLOWED_TO_FULLCOM;
				}
			}
		#endif/* (STD_ON == COMM_SYNCHRONOUS_WAKE_UP)*/
	}
	else
	{
		 /* stay in current communication state*/
		ComM_ChannelInfo[Channel].AllowedConditionType = COMM_KEEP_CURSTATE;
	}
}

/**
 * @brief         This function is used to determine the COMM_NO_COM_REQUEST_PENDING State conversion
 * 				  conditions that are satisfied on COMMM_FULL
 * @param[in]     Channel, network channel
 * @param[out]    /
 * @param[in/out] /
 * @return        /
 * @retval		  /
 */
FUNC(void, COMM_CODE)ComM_NoComPendingCheck(
	CONST(NetworkHandleType, CANTP_CONST) Channel
)
{
	/**
	 * @req [SWS_ComM_00895] In sub-state COMM_NO_COM_REQUEST_PENDING the ComM channel state
	 * 						  machine shall evaluate its corresponding CommunicationAllowed
	 * 						  flag, stored and set according to SWS_ComM_00884 and
	 * 						  SWS_ComM_00885. If evaluated to CommunicationAllowed=(boolean)TRUE, the
	 * 						  ComM channel state machine shall immediately switch to state
	 * 						  COMM_FULL_COMMUNICATION.
	 */
	/**
	 * @req [SWS_ComM_00896] Each ComM channel state machine shall only evaluate its corresponding
	 * 						 communication status flag CommunicationAllowed according to
	 * 						 SWS_ComM_00884 in sub-state COMM_NO_COM_REQUEST_PENDING.
	 */
	if((boolean)TRUE == ComM_ChannelInfo[Channel].CommunicationAllowed)
	{

		/*It will be converted to a higher communication state*/
	   ComM_ChannelInfo[Channel].AllowedConditionType = COMM_ALLOWED_TO_FULLCOM;
	}
	/**
	 * @req [SWS_ComM_00897] In sub-state COMM_NO_COM_REQUEST_PENDING and no longer any valid
	 * 						  pending request for COMM_FULL_COMMUNICATION, the ComM channel
	 * 						  state machine shall switch back to default sub-state
	 * 						  COMM_NO_COM_NO_PENDING_REQUEST.
	 */
	else if(0u == ComM_ChannelInfo[Channel].UserReqFullNum)
	{

		/*It will be converted to a lower communication state*/
		ComM_ChannelInfo[Channel].AllowedConditionType = COMM_ALLOWED_TO_NOCOM;
	}
	else
	{
		 /* stay in current communication state*/
		ComM_ChannelInfo[Channel].AllowedConditionType = COMM_KEEP_CURSTATE;
	}

}

/**
 * @brief         This function is used to determine the COMM_FULL_COM_NETWORK_REQUESTED State conversion
 * 				  conditions that are satisfied on COMMM_FULL
 * @param[in]     Channel, network channel
 * @param[out]    /
 * @param[in/out] /
 * @return        /
 * @retval		  /
 */

FUNC(void, COMM_CODE)ComM_NetworkRequestCheck(
	CONST(NetworkHandleType, CANTP_CONST) Channel
)
{
	/**
	 * @req [SWS_ComM_00915] In sub-state COMM_FULL_COM_NETWORK_REQUESTED and configuration parameter
	 * 						  ComMNmVariant=PASSIVE (ECUC_ComM_00568), the ComM channel state machine
	 * 						  shall switch to sub-state COMM_FULL_COM_READY_SLEEP.
	 */
	if(COMM_PASSIVE == ComM_ConfigPtr->ComMChannelCfgInfo[Channel].ComMNmVariant)
	{
		/*It will be converted to a lower communication state*/
		ComM_ChannelInfo[Channel].AllowedConditionType = COMM_ALLOWED_TO_NOCOM;
	}
	else
	{
		/**
		 * @req [SWS_ComM_00841] The ComM module shall only perform the limit to
		 * 						 COMM_NO_COMMUNICATION mode if the current state is
		 * 						 COMM_FULL_COM_NETWORK_REQUESTED
		 */
	#if (COMM_MODE_LIMITATION_ENABLED == STD_ON)||(COMM_WAKEUP_INHIBITION_ENABLED == STD_ON)
	if (
		#if (COMM_MODE_LIMITATION_ENABLED == STD_ON)
		(((ComM_GlobalInfo.EcuGroupClassification & COMM_MASK_LIMIT_TO_NOCOM) == \
		COMM_MASK_LIMIT_TO_NOCOM) && (((boolean)TRUE == ComM_GlobalInfo.ComM_EcuToNoCom) || \
		((ComM_GlobalInfo.inhibitStatu[Channel] & COMM_MASK_LIMIT_TO_NOCOM) == \
		COMM_MASK_LIMIT_TO_NOCOM)))
		#endif /* (COMM_MODE_LIMITATION_ENABLED == STD_ON)*/
		#if (COMM_MODE_LIMITATION_ENABLED == STD_ON)&&(COMM_WAKEUP_INHIBITION_ENABLED == STD_ON)
		&&
		#endif /* (COMM_MODE_LIMITATION_ENABLED == STD_ON)&&(COMM_WAKEUP_INHIBITION_ENABLED == STD_ON)*/
		#if (COMM_WAKEUP_INHIBITION_ENABLED == STD_ON)
		   (ComM_GlobalInfo.EcuGroupClassification & COMM_MASK_INHIBIT_WAKEUP) && \
		  (ComM_GlobalInfo.inhibitStatu[Channel] & COMM_MASK_INHIBIT_WAKEUP)
		#endif /* (COMM_WAKEUP_INHIBITION_ENABLED == STD_ON)*/
		)
	   {
			/**
			 * @req [SWS_ComM_00890] In sub-state COMM_FULL_COM_NETWORK_REQUESTED and the DCM
			 * 						  does not indicate ComM_DCM_ActiveDiagnostic(<channel>) and
			 * 						  communication limitation is requested , ComM channel state
			 * 						  machine shall immediately switch to sub-state
			 * 						  COMM_FULL_COM_READY_SLEEP.
			 */
			#if (STD_ON == COMM_DCM_USED)
		   if((boolean)FALSE == ComM_ChannelInfo[Channel].EventFlags.DcmActive)
			#endif /*#if (STD_ON == COMM_DCM_USED)*/
		   {
				/**
				 * @req [SWS_ComM_00303] The ComM module shall perform the limit to
				 * 						 COMM_NO_COMMUNICATION mode by switching to
				 * 						 COMM_FULL_COM_READY_SLEEP state to initiate a shutdown despite
				 * 						 user requests for COMM_FULL_COMMUNICATION mode and ignoring new
				 * 						 COMM_FULL_COMMUNICATION mode requests.
				 */
				/*It will be converted to a lower communication state*/
				ComM_ChannelInfo[Channel].AllowedConditionType = COMM_ALLOWED_TO_NOCOM;
		   }
			#if (STD_ON == COMM_DCM_USED)
		   else
		   {
				 /* stay in current communication state*/
				ComM_ChannelInfo[Channel].AllowedConditionType = COMM_KEEP_CURSTATE;

		   }
			#endif /*#if (STD_ON == COMM_DCM_USED)*/
	   }
	   else
	   #endif /*#if (COMM_MODE_LIMITATION_ENABLED == STD_ON)||(COMM_WAKEUP_INHIBITION_ENABLED == STD_ON)*/
	   {
		   if(COMM_FULL == ComM_ConfigPtr->ComMChannelCfgInfo[Channel].ComMNmVariant)
		   {
				/**
				 * @req [SWS_ComM_00888] In sub-state COMM_FULL_COM_NETWORK_REQUESTED and configuration
				 * 						  parameter ComMNmVariant=FULL and no user request
				 * 						  ComM_RequestComMode(<user>,COMM_FULL_COMMUNICATION) and the DCM
				 * 						  does not indicate ComM_DCM_ActiveDiagnostic(<channel>), the
				 * 						  ComM channel state machine shall switch to sub-state
				 * 						  COMM_FULL_COM_READY_SLEEP.
				 */
			   if((ComM_ChannelInfo[Channel].UserReqFullNum == 0u)
	#if (STD_ON == COMM_DCM_USED)
					&&((boolean)FALSE == ComM_ChannelInfo[Channel].EventFlags.DcmActive)
	#endif /*#if (STD_ON == COMM_DCM_USED)*/
				)
			   {
					/*It will be converted to a lower communication state*/
					ComM_ChannelInfo[Channel].AllowedConditionType = COMM_ALLOWED_TO_NOCOM;

			   }
			   else
			   {
					 /* stay in current communication state*/
					ComM_ChannelInfo[Channel].AllowedConditionType = COMM_KEEP_CURSTATE;
			   }
		   }
			/**
			 * @req [SWS_ComM_00889] In sub-state COMM_FULL_COM_NETWORK_REQUESTED and configuration parameter
			 * 						  ComMNmVariant=LIGHT|NONE and timer for ComMTMinFullComModeDuration has
			 * 						  expired and no user request ComM_RequestComMode
			 * 						  (<user>,COMM_FULL_COMMUNICATION) and the DCM does not indicate
			 * 						  ComM_DCM_ActiveDiagnostic(<channel>), the ComM channel state machine shall
			 * 						  switch to sub-state COMM_FULL_COM_READY_SLEEP.
			 */
			if(((COMM_LIGHT == ComM_ConfigPtr->ComMChannelCfgInfo[Channel].ComMNmVariant)||\
					(COMM_NONE == ComM_ConfigPtr->ComMChannelCfgInfo[Channel].ComMNmVariant))&&\
					(ComM_ChannelInfo[Channel].ModeTimer.Timer == 0u)&&\
					(ComM_ChannelInfo[Channel].ModeTimer.TimerType == COMM_MIN_FULL_COM_MODE_DURATION_TIMER)\
					   &&(ComM_ChannelInfo[Channel].UserReqFullNum == 0u)
							 #if (STD_ON == COMM_DCM_USED)
							&& ((boolean)FALSE == ComM_ChannelInfo[Channel].EventFlags.DcmActive)
							 #endif /*#if (STD_ON == COMM_DCM_USED)*/
			)
			{
				/*It will be converted to a lower communication state*/
				ComM_ChannelInfo[Channel].AllowedConditionType = COMM_ALLOWED_TO_NOCOM;
			}
		}
	}
	return;
}

/**
 * @brief         This function is used to determine the COMM_FULL_COM_READY_SLEEP State conversion
 * 				  conditions that are satisfied on COMMM_FULL
 * @param[in]     Channel, network channel
 * @param[out]    /
 * @param[in/out] /
 * @return        /
 * @retval		  /
 */
FUNC(void, COMM_CODE)ComM_ReadySleepCheck(
	CONST(NetworkHandleType, CANTP_CONST) Channel
)
{
	/**
	 * @req [SWS_ComM_00610] In sub-state COMM_FULL_COM_READY_SLEEP and configuration parameter
	 * 						  ComMNmVariant=LIGHT and the timer for ComMNmLightTimeout has expired,
	 * 						  ComM channel state machine shall switch to state COMM_NO_COMMUNICATION.
	 */
	/**
	 * @req [SWS_ComM_00671] In sub-state COMM_FULL_COM_READY_SLEEP and configuration parameter
	 * 						  ComMBusType=COMM_BUS_TYPE_INTERNAL , the ComM channel state machine
	 * 						  shall immediately switch to state COMM_NO_COMMUNICATION.
	 */
	if((COMM_BUS_TYPE_INTERNAL == ComM_ConfigPtr->ComMChannelCfgInfo[Channel].ComMBusType)
		||((COMM_LIGHT == ComM_ConfigPtr->ComMChannelCfgInfo[Channel].ComMNmVariant)\
				&&(ComM_ChannelInfo[Channel].ModeTimer.Timer == 0u)\
				&&(ComM_ChannelInfo[Channel].ModeTimer.TimerType == COMM_NM_LIGHT_TIMER)))
	{

		/*It will be converted to a lower communication state*/
		ComM_ChannelInfo[Channel].AllowedConditionType = COMM_ALLOWED_TO_NOCOM;
	}
	else
	{
		/**
		 * @req [SWS_ComM_00882] In sub-state COMM_FULL_COM_NETWORK_REQUESTED and configuration
		 * 						  parameter ComMNmVariant=FULL and no user request
		 * 						  ComM_RequestComMode(<user>,COMM_FULL_COMMUNICATION) and the DCM
		 * 						  does not indicate ComM_DCM_ActiveDiagnostic(<channel>), the
		 * 						  ComM channel state machine shall switch to sub-state
		 * 						  COMM_FULL_COM_READY_SLEEP.
		 */
	   if(((ComM_ChannelInfo[Channel].UserReqFullNum > 0u)
		#if (COMM_MODE_LIMITATION_ENABLED == STD_ON)
		&& (!(((ComM_GlobalInfo.EcuGroupClassification & COMM_MASK_LIMIT_TO_NOCOM) == \
		COMM_MASK_LIMIT_TO_NOCOM) && (((boolean)TRUE == ComM_GlobalInfo.ComM_EcuToNoCom) \
		|| ((ComM_GlobalInfo.inhibitStatu[Channel] & COMM_MASK_LIMIT_TO_NOCOM) == \
		COMM_MASK_LIMIT_TO_NOCOM))))
		#endif /* (COMM_MODE_LIMITATION_ENABLED == STD_ON)*/
		#if (COMM_WAKEUP_INHIBITION_ENABLED == STD_ON)
		  && (!((ComM_GlobalInfo.EcuGroupClassification & COMM_MASK_INHIBIT_WAKEUP) && \
		  (ComM_GlobalInfo.inhibitStatu[Channel]\
				  & COMM_MASK_INHIBIT_WAKEUP)))
		#endif /* (COMM_WAKEUP_INHIBITION_ENABLED == STD_ON)*/
		)
		/**
		 * @req [SWS_ComM_00883] In sub-state COMM_FULL_COM_READY_SLEEP,configuration parameter
		 * 						  ComMNmVariant=FULL|LIGHT|NONE and DCM indicate
		 * 						  ComM_DCM_ActiveDiagnostic, the ComM channel state machine shall
		 * 						  switch to sub-state COMM_FULL_COM_NETWORK_REQUESTED.
		 */
		#if (STD_ON == COMM_DCM_USED)
/* PRQA S 3397 EOF # violate MSIAR2004_12.1: */
		||(((boolean)TRUE == ComM_ChannelInfo[Channel].EventFlags.DcmActive )&&\
				(COMM_PASSIVE != ComM_ConfigPtr->ComMChannelCfgInfo[Channel].ComMNmVariant))
		#endif /*#if (STD_ON == COMM_DCM_USED)*/
		)
	   {
			/*It will be converted to a higher communication state*/
			ComM_ChannelInfo[Channel].AllowedConditionType = COMM_ALLOWED_TO_FULLCOM;
			/**
			 * @req [SWS_ComM_00892] In sub-state COMM_FULL_COM_READY_SLEEP and configuration parameter
			 * 						 ComMNmVariant=LIGHT (ECUC_ComM_00568) and a switch to sub-state
			 * 						 COMM_FULL_COM_NETWORK_REQUESTED, due to request for COMM_FULL_COMMUNICATION
			 * 						 according to requirements in SWS_ComM_00882 or SWS_ComM_00883, the timer for
			 * 						 ComMNmLightTimeout (ECUC_ComM_00606) shall be canceled.
			 */
			if(COMM_LIGHT == ComM_ConfigPtr->ComMChannelCfgInfo[Channel].ComMNmVariant)
			{
				ComM_ChannelInfo[Channel].ModeTimer.IsStarted = (boolean)FALSE;
				ComM_ChannelInfo[Channel].ModeTimer.Timer = 0u;
				ComM_ChannelInfo[Channel].ModeTimer.TimerType = COMM_NO_TIMER;
			}
	   }
	   else
	   {
		   /*It will be converted to a lower communication state*/
		   ComM_ChannelInfo[Channel].AllowedConditionType = COMM_KEEP_CURSTATE;
	   }

	}
}

/**
 * @brief         This function is used to determine the COMM_FULL_COM_READY_SLEEP State conversion
 * 				  conditions that are satisfied on COMMM_FULL
 * @param[in]     Channel, network channel
 * @param[out]    /
 * @param[in/out] /
 * @return        /
 * @retval		  /
 */
FUNC(void, COMM_CODE)ComM_SlientCheck(
	CONST(NetworkHandleType, CANTP_CONST) Channel
)
{
	/**
	 * @req [SWS_ComM_00899] On entering state COMM_FULL_COMMUNICATION the ComM channel state
	 * 						  machine shall go to sub-state COMM_FULL_COM_NETWORK_REQUESTED, if
	 * 						  not a specific sub-state is specified in the transition.
	 */
	/**
	 * @req [SWS_ComM_00877] In state COMM_SILENT_COMMUNICATION and user requests
	 * 						  COMM_FULL_COMMUNICATION and communication limitation is disabled,
	 * 						  the ComM channel state machine shall switch to state
	 * 						  COMM_FULL_COMMUNICATION.
	 */
   if(((ComM_ChannelInfo[Channel].UserReqFullNum > 0u)
	#if (COMM_MODE_LIMITATION_ENABLED == STD_ON)
		&& (!((((ComM_GlobalInfo.EcuGroupClassification & COMM_MASK_LIMIT_TO_NOCOM) \
		== COMM_MASK_LIMIT_TO_NOCOM) && (((boolean)TRUE == ComM_GlobalInfo.ComM_EcuToNoCom) \
		|| ((ComM_GlobalInfo.inhibitStatu[Channel] & COMM_MASK_LIMIT_TO_NOCOM) == \
		COMM_MASK_LIMIT_TO_NOCOM)))))
		#endif /* (COMM_MODE_LIMITATION_ENABLED == STD_ON)*/
		#if (COMM_WAKEUP_INHIBITION_ENABLED == STD_ON)
		  && (!((ComM_GlobalInfo.EcuGroupClassification & COMM_MASK_INHIBIT_WAKEUP) && \
		  (ComM_GlobalInfo.inhibitStatu[Channel]\
				  & COMM_MASK_INHIBIT_WAKEUP)))
		#endif /* (COMM_WAKEUP_INHIBITION_ENABLED == STD_ON)*/
	)
	/**
	 * @req [SWS_ComM_00878] In state COMM_SILENT_COMMUNICATION ,configuration parameter
	 * 						  ComMNmVariant=FULL|LIGHT|NONE and DCM indicate
	 * 						  ComM_DCM_ActiveDiagnostic(SWS_ComM_00873), the ComM channel
	 * 						  state machine shall switch to state COMM_FULL_COMMUNICATION.
	 */
	#if (STD_ON == COMM_DCM_USED)
	||(((boolean)TRUE == ComM_ChannelInfo[Channel].EventFlags.DcmActive) &&\
			(COMM_PASSIVE != ComM_ConfigPtr->ComMChannelCfgInfo[Channel].ComMNmVariant))
	#endif /*#if (STD_ON == COMM_DCM_USED)*/
	)
	{
		/*It will be converted to a higher communication state*/
		ComM_ChannelInfo[Channel].AllowedConditionType = COMM_ALLOWED_TO_FULLCOM;
	}
   else
   {
	   /*It will be converted to a lower communication state*/
	   ComM_ChannelInfo[Channel].AllowedConditionType = COMM_KEEP_CURSTATE;
   }
}


/**
 * @brief         This function is used to determine the state conversion conditions
 * 				  that are satisfied on COMMM_FULL
 * @param[in]     Channel, network channel
 * @param[out]    /
 * @param[in/out] /
 * @return        /
 * @retval		  /
 */
FUNC(void, COMM_CODE)ComM_ConditionCheck(
	CONST(NetworkHandleType, CANTP_CONST) Channel
)
{
	switch (ComM_ChannelInfo[Channel].ComMState)
	{
		case COMM_NO_COM_NO_PENDING_REQUEST:

			ComM_NoComCheck(Channel);

			break;

		case COMM_NO_COM_REQUEST_PENDING:

			ComM_NoComPendingCheck(Channel);

		   break;

		case COMM_FULL_COM_NETWORK_REQUESTED:

			ComM_NetworkRequestCheck(Channel);

			break;

		case COMM_FULL_COM_READY_SLEEP:

			ComM_ReadySleepCheck(Channel);

		   break;

		case COMM_SILENT_COM:

			ComM_SlientCheck(Channel);

		   break;
		default:
			break;

	}
}

/**
 * @brief         The processing after the state enters ReadySleep
 * @param[in]     Channel, network channel
 * @param[out]    /
 * @param[in/out] /
 * @return        /
 * @retval		  /
 */
FUNC(void, COMM_CODE) ComM_EnterReadySleepHandler(
	CONST(NetworkHandleType, CANTP_CONST) Channel
)
{
	ComM_BusType busType;

    if (ComM_ChannelInfo[Channel].ComMMode != COMM_FULL_COMMUNICATION)
    {
    	/*set cur ComM mode of channel*/
    	ComM_ChannelInfo[Channel].ComMMode = COMM_FULL_COMMUNICATION;

    	/*set the bus mode indication*/
        ComM_ChannelInfo[Channel].BusSetRecord.BusNMModeIndication = COMM_INVALID_UINT8;

        /*set the channel bus set is request*/
        ComM_ChannelInfo[Channel].BusSetRecord.Requested = (boolean)TRUE;

        busType = ComM_ConfigPtr->ComMChannelCfgInfo[Channel].ComMBusType;

    	if ((Std_ReturnType)E_OK != ComM_SMRequestComModeTable[busType](Channel,COMM_FULL_COMMUNICATION))
        {
			/*set mode failed,need retry*/
			ComM_ChannelInfo[Channel].BusSetRecord.RetrySet = (boolean)TRUE;
        }
    }

	ComM_ChannelInfo[Channel].ComMState = COMM_FULL_COM_READY_SLEEP;

	switch (ComM_ConfigPtr->ComMChannelCfgInfo[Channel].ComMNmVariant)
	{
	   case COMM_FULL:
	   #if ((STD_ON == COMM_NM_USED) && (STD_OFF == COMM_NM_PASSIVE_MODE_ENABLED))
	    	/**
	    	 * @req [SWS_ComM_00133] On entering sub-state COMM_FULL_COM_READY_SLEEP and configuration
	    	 * 						  parameter ComMNmVariant=FULL (ECUC_ComM_00568), the ComM module
	    	 * 						  shall request Nm_NetworkRelease() from the Network Management for
	    	 * 						  the corresponding NM channels.
	    	 */
		   Nm_NetworkRelease(Channel);
		   ComM_NmNetworkRequestflag[Channel]= (boolean)FALSE;
	   #endif /* #if ((STD_ON == COMM_NM_USED) && (STD_OFF == COMM_NM_PASSIVE_MODE_ENABLED))*/
		   break;
	   case COMM_LIGHT:
	    	/**
	    	 * @req [SWS_ComM_00891] On entering sub-state COMM_FULL_COM_READY_SLEEP and configuration
	    	 * 						 parameter ComMNmVariant=LIGHT (ECUC_ComM_00568), the timer for
	    	 * 						 ComMNmLightTimeout(ECUC_ComM_00606) shall be started.
	    	 */
		   ComM_ChannelInfo[Channel].ModeTimer.IsStarted= (boolean)TRUE;
		   ComM_ChannelInfo[Channel].ModeTimer.Timer = \
				   ComM_ConfigPtr->ComMChannelCfgInfo[Channel].ComMNmLightTimeout;
		   ComM_ChannelInfo[Channel].ModeTimer.TimerType = COMM_NM_LIGHT_TIMER;
		   break;
	   default:
		   break;
	}
}


/**
 * @brief         The processing after the state enters NetworkRequested
 * @param[in]     Channel, network channel
 * @param[out]    /
 * @param[in/out] /
 * @return        /
 * @retval		  /
 */
FUNC(void, COMM_CODE) ComM_EnterNetworkRequestedHandler(
	CONST(NetworkHandleType, CANTP_CONST) Channel
)
{
	ComM_BusType busType;

    if (ComM_ChannelInfo[Channel].ComMMode != COMM_FULL_COMMUNICATION)
    {
    	/**
    	 * @req [SWS_ComM_00069] On entering state COMM_FULL_COMMUNICATION the ComM channel state
    	 *  					  machine shall switch on the transmission and reception capability.
    	 *  					  This shall be performed by the ComM channel state machine requesting
    	 *  					  the corresponding Communication Mode from the Bus State Manager module
    	 */
    	/**
    	 * @req [SWS_ComM_00845] In COMM_FULL_COMMUNICATION mode, the ComM module shall allow transmission
    	 * 						 and reception on the affected physical channel.
    	 */
    	/**
    	 * @req [SWS_ComM_00092] There shall be one Communication Mode target state (evaluated according
    	 * 						 to SWS_ComM_00686) per communication channel. This target mode can differ
    	 * 						 temporarily from the actual mode controlled by the corresponding Bus State
    	 * 						 Manager module.
    	 */
    	/*set cur ComM mode of channel*/
    	ComM_ChannelInfo[Channel].ComMMode = COMM_FULL_COMMUNICATION;

    	/*set the bus mode indication*/
        ComM_ChannelInfo[Channel].BusSetRecord.BusNMModeIndication = COMM_INVALID_UINT8;

        /*set the channel bus set is request*/
        ComM_ChannelInfo[Channel].BusSetRecord.Requested = (boolean)TRUE;
        
		busType = ComM_ConfigPtr->ComMChannelCfgInfo[Channel].ComMBusType;

		/**
		 * @req [SWS_ComM_00958] Configuration of ComM_GetCurrentComMode: Relationship between
		 * 						 users and channels. A user is statically mapped to one or more
		 * 						 channels.
		 */
		    if (NULL_PTR != ComM_SMRequestComModeTable[busType])
				{
						if ((Std_ReturnType)E_OK != ComM_SMRequestComModeTable[busType](Channel,COMM_FULL_COMMUNICATION))
						{
								/*set mode failed,need retry*/
								ComM_ChannelInfo[Channel].BusSetRecord.RetrySet = (boolean)TRUE;
						}
				}
    }
	/**
	 * @req [SWS_ComM_00502] If ComMNmPassiveModeEnable is set to DISABLED the ComMNmVariant shall be limited
	 * 						 to the values LIGHT, NONE, and FULL.
	 */
#if (STD_ON == COMM_NM_USED)
#if (STD_OFF == COMM_NM_PASSIVE_MODE_ENABLED)
	/**
	 * @req [SWS_ComM_00667] The ComM module shall omit to call Nm_NetworkRequest() from NM if configuration
	 * 						 parameter ComMNmVariant=PASSIVE
	 */
	/**
	 * @req [SWS_ComM_00869] On entering sub-state COMM_FULL_COM_NETWORK_REQUESTED from another state
	 * 						  or substate, if configuration parameter ComMNmVariant=FULL and if a user
	 * 						  has requested ComM_RequestComMode(<user>,COMM_FULL_COMMUNICATION) the ComM
	 * 						  module shall request Nm_NetworkRequest(<channel>) from the Network
	 * 						  Management for the corresponding NM channel.
	 */
	if(((COMM_FULL == ComM_ConfigPtr->ComMChannelCfgInfo[Channel].ComMNmVariant)\
			&&(ComM_ChannelInfo[Channel].UserReqFullNum > 0u))
			/**
			 * @req [SWS_ComM_00870] On entering sub-state COMM_FULL_COM_NETWORK_REQUESTED, if configuration
			 * 						  parameter ComMNmVariant=FULL and the DCM has indicated
			 * 						  ComM_DCM_ActiveDiagnostic(<channel>) , the ComM module shall request
			 * 						  Nm_NetworkRequest(<channel>) from the Network Management for
			 * 						  the corresponding NM channel.
			 */
			#if(STD_ON == COMM_DCM_USED)
			||(((boolean)TRUE == ComM_ChannelInfo[Channel].EventFlags.DcmActive)&&\
					(COMM_FULL == ComM_ConfigPtr->ComMChannelCfgInfo[Channel].ComMNmVariant))
			#endif /*#if (STD_ON == COMM_DCM_USED)*/
			)
		{
			if((COMM_FULL_COMMUNICATION == ComM_ChannelInfo[Channel].BusSetRecord.BusNMModeIndication)\
			||((COMM_FULL_COM_READY_SLEEP == ComM_ChannelInfo[Channel].ComMState)&&((boolean)FALSE == ComM_ChannelInfo[Channel].BusSetRecord.Requested)))
			{
				ComM_ChannelInfo[Channel].ComMState = COMM_FULL_COM_NETWORK_REQUESTED;
				ComM_ChannelInfo[Channel].BusSetRecord.BusNMModeIndication = COMM_INVALID_UINT8;

				(void)Nm_NetworkRequest(Channel);
				 ComM_NmNetworkRequestflag[Channel] = (boolean)TRUE;
			}

		}

#endif /*#if (STD_OFF == COMM_NM_PASSIVE_MODE_ENABLED)*/
	/**
	 * @req [SWS_ComM_00902] On entering sub-state COMM_FULL_COM_NETWORK_REQUESTED and Nm module
	 * 						  has indicated a restart,ComM_Nm_RestartIndication(<channel>), the
	 * 						  ComM module shall request Nm_PassiveStartup(<channel>) from the Network
	 * 						  Management
	 */
	/**
	 * @req [SWS_ComM_00903] On entering sub-state COMM_FULL_COM_NETWORK_REQUESTED and Nm module has
	 * 						  indicated a Network start, ComM_Nm_NetworkStartIndication(<channel>) ,the
	 * 						  ComM module shall request Nm_PassiveStartup(<channel>) from the Network
	 * 						  Management
	 */
	/**
	 * @req [SWS_ComM_00665] On entering sub-state COMM_FULL_COM_NETWORK_REQUESTED and EcuM module has
	 * 						  indicated a wake-up, ComM_EcuM_WakeUpIndication(<channel>), the ComM
	 * 						  module shall request Nm_PassiveStartup(<channel>) from the Network
	 * 						  Management.
	 */
	if ((((boolean)TRUE == ComM_ChannelInfo[Channel].EventFlags.EcuMWakeupInd)||\
			((boolean)TRUE == ComM_ChannelInfo[Channel].EventFlags.NmStart)||\
			((boolean)TRUE == ComM_ChannelInfo[Channel].EventFlags.NmReStart))\
			&& (ComM_ChannelInfo[Channel].UserReqFullNum == 0u))
	{
		if ((COMM_FULL_COMMUNICATION == ComM_ChannelInfo[Channel].BusSetRecord.BusNMModeIndication)
			||((COMM_FULL_COM_READY_SLEEP == ComM_ChannelInfo[Channel].ComMState)&&((boolean)FALSE == ComM_ChannelInfo[Channel].BusSetRecord.Requested)))
		{
			/*clear the passive startup event*/
			ComM_ChannelInfo[Channel].EventFlags.EcuMWakeupInd = (boolean)FALSE;
			ComM_ChannelInfo[Channel].EventFlags.NmStart = (boolean)FALSE;
			ComM_ChannelInfo[Channel].EventFlags.NmReStart = (boolean)FALSE;

			(void)Nm_PassiveStartUp(Channel);
			ComM_NmNetworkRequestflag[Channel] = (boolean)TRUE;
			ComM_ChannelInfo[Channel].ComMState = COMM_FULL_COM_NETWORK_REQUESTED;
			ComM_ChannelInfo[Channel].BusSetRecord.BusNMModeIndication = COMM_INVALID_UINT8;
		}
	}
#endif
	/**
	 * @req [SWS_ComM_00886] On entering sub-state COMM_FULL_COM_NETWORK_REQUESTED
	 * 						  and configuration parameter ComMNmVariant=LIGHT|NONE ,
	 * 						  the timer for ComMTMinFullComModeDuration shall be started.
	 */
    if((COMM_LIGHT == ComM_ConfigPtr->ComMChannelCfgInfo[Channel].ComMNmVariant)||\
    	(COMM_NONE == ComM_ConfigPtr->ComMChannelCfgInfo[Channel].ComMNmVariant))
    {
			/**
			 * @req [SWS_ComM_00892] In sub-state COMM_FULL_COM_READY_SLEEP and configuration
			 * 						  parameter ComMNmVariant=LIGHT and a switch to sub-state
			 * 						  COMM_FULL_COM_NETWORK_REQUESTED, due to request for
			 * 						  COMM_FULL_COMMUNICATION according to requirements in
			 * 						  SWS_ComM_00882 or SWS_ComM_00883, the timer forComMNmLightTimeout
			 * 						  shall be canceled.
			 */
    	   ComM_ChannelInfo[Channel].ComMState = COMM_FULL_COM_NETWORK_REQUESTED;
		   ComM_ChannelInfo[Channel].ModeTimer.IsStarted= (boolean)TRUE;
		   ComM_ChannelInfo[Channel].ModeTimer.Timer = \
				   (uint32)(((uint32)COMM_T_MIN_FULL_COM_MODE_DURATION*1000u)/(uint32)ComM_ConfigPtr->ComMChannelCfgInfo[Channel].ComMMainFunctionPeriod);
		   ComM_ChannelInfo[Channel].ModeTimer.TimerType = COMM_MIN_FULL_COM_MODE_DURATION_TIMER;
    }
#if (STD_ON == COMM_BSWM_USED)
 BswM_ComM_CurrentMode(Channel, COMM_FULL_COMMUNICATION);
#endif /* if (STD_ON == COMM_BSWM_USED) */
 return;
}

/**
 * @brief         The processing after the state enters No Com No Pending
 * @param[in]     Channel, network channel
 * @param[out]    /
 * @param[in/out] /
 * @return        /
 * @retval		  /
 */
FUNC(void, COMM_CODE) ComM_EnterNoComHandler(
	CONST(NetworkHandleType, CANTP_CONST) Channel
)
{

	ComM_BusType busType;
	uint8 index;
	uint8 chIndex;
	uint8 userId;
	boolean clearUserRequestFlag = (boolean)TRUE;

	if (ComM_ChannelInfo[Channel].ComMMode != COMM_NO_COMMUNICATION)
	{
		/**
		 * @req [SWS_ComM_00846] On entering state COMM_NO_COMMUNICATION the ComM module shall prevent
		 * 						 transmission and reception on the affected physical channel.
		 */
		/*set cur ComM mode of channel*/
		ComM_ChannelInfo[Channel].ComMMode = COMM_NO_COMMUNICATION;

		/*set the bus mode indication*/
		ComM_ChannelInfo[Channel].BusSetRecord.BusNMModeIndication = COMM_INVALID_UINT8;

		/*set the channel bus set is request*/
		ComM_ChannelInfo[Channel].BusSetRecord.Requested = (boolean)TRUE;

		busType = ComM_ConfigPtr->ComMChannelCfgInfo[Channel].ComMBusType;
		/**
		 * @req [SWS_ComM_00073] On entering state COMM_NO_COMMUNICATION the ComM channel state machine
		 * 						 shall switch off the transmission and reception capability. This shall
		 * 						 be performed by the ComM channel state machine requesting the
		 * 						 corresponding Communication Mode from the Bus State Manager module
		 */
		if ((Std_ReturnType)E_OK != ComM_SMRequestComModeTable[busType](Channel,COMM_NO_COMMUNICATION))
		{
			/*set mode failed,need retry*/
			ComM_ChannelInfo[Channel].BusSetRecord.RetrySet = (boolean)TRUE;
		}

		#if (STD_ON == COMM_BSWM_USED)
		#if (STD_ON == COMM_RESET_AFTER_FORCING_NO_COMM)
		#if (STD_ON == COMM_MODE_LIMITATION_ENABLED)
			if((ComM_GlobalInfo.EcuGroupClassification & COMM_MASK_LIMIT_TO_NOCOM) && \
					  ((ComM_GlobalInfo.ComM_EcuToNoCom) || (ComM_GlobalInfo.inhibitStatu[Channel]\
							  & COMM_MASK_LIMIT_TO_NOCOM)))
			{
				/**
				 * @req [SWS_ComM_00355] ComM shall force an ECU reset by invoking
				 * 						 BswM_ComM_InitiateReset()  after entering "No Communication"
				 * 						 mode if configured (ComMResetAfterForcingNoComm=TRUE)
				 */
				BswM_ComM_InitiateReset();
			}
		#endif /* (STD_ON == COMM_MODE_LIMITATION_ENABLED) */
		#endif /* (STD_ON == COMM_RESET_AFTER_FORCING_NO_COMM)*/
		BswM_ComM_CurrentMode(Channel, COMM_NO_COMMUNICATION);
		#endif /* (STD_ON == COMM_BSWM_USED) */

	}

	/* clesr event */
	ComM_ChannelInfo[Channel].EventFlags.DcmActive = (boolean)FALSE;
	ComM_ChannelInfo[Channel].EventFlags.EcuMWakeupInd = (boolean)FALSE;
	ComM_ChannelInfo[Channel].EventFlags.NmBusSleep = (boolean)FALSE;
	ComM_ChannelInfo[Channel].EventFlags.NmNetworkMode = (boolean)FALSE;
	ComM_ChannelInfo[Channel].EventFlags.NmPreSleep = (boolean)FALSE;
	ComM_ChannelInfo[Channel].EventFlags.NmReStart = (boolean)FALSE;
	ComM_ChannelInfo[Channel].EventFlags.NmStart = (boolean)FALSE;

	ComM_ChannelInfo[Channel].ComMState = COMM_NO_COM_NO_PENDING_REQUEST;

	ComM_ChannelInfo[Channel].ModeTimer.IsStarted = (boolean)FALSE;
	ComM_ChannelInfo[Channel].ModeTimer.Timer = 0u;
	ComM_ChannelInfo[Channel].ModeTimer.TimerType = COMM_NO_TIMER;

	/**
	 * @req [SWS_ComM_00582] The ComM module shall clear the user requests after all the channels that
	 * 						 belong to the corresponding user enter COMM_NO_COMMUNICATION mode.
	 */

	for (userId = 0u; userId < COMM_NUMBER_OF_USERS; userId++)
	{
		for (index = 0u; index < ComM_ConfigPtr->ComMUserCfgInfo[userId].ChannelNum; index++)
		{
			chIndex = ComM_ConfigPtr->ComMUserCfgInfo[userId].ChannelMap[index];

			if(COMM_NO_COMMUNICATION == ComM_ChannelInfo[chIndex].ComMMode)
			{
				/*No Handle*/
			}
			else
			{
				clearUserRequestFlag = (boolean)FALSE;
			}
		}
		if((boolean)TRUE == clearUserRequestFlag)
		{
			ComM_UserInfo[userId].RequestMode = COMM_NO_COMMUNICATION;
		}
	}


#if (STD_ON == COMM_NM_USED)
	/**
	 * @req [SWS_ComM_00288] On entering state COMM_NO_COMMUNICATION and configuration parameter
	 * 						  ComMNmVariant=FULL the ComM module shall request release of the network
	 * 						  from the Network Management module, Nm_NetworkRelease().
	 */
	/* Nm_NetworkRelease is needed if ComM has requested the Nm (Nm_NetworkRequest or Nm_PassiveStartup)
	 * for that channel before and has not yet released it*/
    if ((COMM_FULL == ComM_ConfigPtr->ComMChannelCfgInfo[Channel].ComMNmVariant)&&((boolean)TRUE == ComM_NmNetworkRequestflag[Channel]))
    {
        (void)Nm_NetworkRelease(Channel);
		 ComM_NmNetworkRequestflag[Channel] = (boolean)FALSE;
    }
	/**
	 * @req [SWS_ComM_00313] On entering state COMM_NO_COMMUNICATION by default after initialization,
	 * 						 ComM module shall not indicate the mode change to users via RTE or BswM.
	 */
#endif
}

/**
 * @brief         The processing after the state enters No Com Request Pending
 * @param[in]     Channel, network channel
 * @param[out]    /
 * @param[in/out] /
 * @return        /
 * @retval		  /
 */
FUNC(void, COMM_CODE) ComM_EnterNoComPendingHandler(
	CONST(NetworkHandleType, CANTP_CONST) Channel
)
{
	ComM_ChannelInfo[Channel].ComMState = COMM_NO_COM_REQUEST_PENDING;

    if ((boolean)TRUE == ComM_ChannelInfo[Channel].CommunicationAllowed)
    {
    	ComM_EnterNetworkRequestedHandler(Channel);
    }

    return;
}

/**
 * @brief         The processing after the state enters Silent Com
 * @param[in]     Channel, network channel
 * @param[out]    /
 * @param[in/out] /
 * @return        /
 * @retval		  /
 */
FUNC(void, COMM_CODE) ComM_EnterSilentComHandler(
	CONST(NetworkHandleType, CANTP_CONST) Channel
)
{
	ComM_BusType busType;

	/**
	 * @req [SWS_ComM_00071] On entering state COMM_SILENT_COMMUNICATION the ComM channel state
	 * 						  machine shall switch off the transmission capability (and keep reception
	 * 						  capability on). This shall be performed by the ComM channel state machine
	 * 						  requesting the corresponding Communication Mode from the Bus State Manager
	 * 						  module
	 */
	/*set cur ComM mode of channel*/
	ComM_ChannelInfo[Channel].ComMMode = COMM_SILENT_COMMUNICATION;

	/*set the bus mode indication*/
	ComM_ChannelInfo[Channel].BusSetRecord.BusNMModeIndication = COMM_INVALID_UINT8;

	/*set the channel bus set is request*/
	ComM_ChannelInfo[Channel].BusSetRecord.Requested = (boolean)TRUE;

	busType = ComM_ConfigPtr->ComMChannelCfgInfo[Channel].ComMBusType;

	if ((Std_ReturnType)E_OK != ComM_SMRequestComModeTable[busType](Channel,COMM_SILENT_COMMUNICATION))
	{
		/*set mode failed,need retry*/
		ComM_ChannelInfo[Channel].BusSetRecord.RetrySet = (boolean)TRUE;
	}

	ComM_ChannelInfo[Channel].ComMState = COMM_SILENT_COM;

	/**
	 * @req [SWS_ComM_00472] Main state changes (see SWS_ComM_00879) shall be indicated
	 * 						 to the users with the corresponding notifications
	 */
	#if (STD_ON == COMM_BSWM_USED)
	BswM_ComM_CurrentMode(Channel, COMM_SILENT_COMMUNICATION);
	#endif /* if (STD_ON == COMM_BSWM_USED) */

}


/*
 * @brief         Processing the transformation between the state
 * @param[in]     Channel, network channel
 * @param[out]    /
 * @param[in/out] /
 * @return        /
 * @retval		  /
 */
FUNC(void, COMM_CODE) ComM_ModeHandle(
    CONST(NetworkHandleType, CANTP_CONST) Channel
)
{
	/**
	 * @req [SWS_ComM_00868] The Communication Mode COMM_SILENT_COMMUNICATION shall only be used
	 * 						 for network synchronization.
	 */
	if(COMM_SILENT_COMMUNICATION == ComM_ChannelInfo[Channel].ComMMode)
	{
		 if ((boolean)TRUE == ComM_ChannelInfo[Channel].EventFlags.NmNetworkMode)
		{
			/*clear the NM indication event*/
			 ComM_ChannelInfo[Channel].EventFlags.NmNetworkMode = (boolean)FALSE;
			/**
			 * @req [SWS_ComM_00296] In state COMM_SILENT_COMMUNICATION and the Network Manager
			 * 						  module indicates See ComM_Nm_NetworkMode() SWS_ComM_00390,
			 * 						  the ComM channel state machine shall switch to state
			 * 						  COMM_FULL_COMMUNICATION and sub-state COMM_FULL_COM_READY_SLEEP.
			 */
			/**
			 * @req [SWS_ComM_00472] Main state changes (see SWS_ComM_00879) shall be indicated
			 * 						 to the users with the corresponding notifications
			 */
			ComM_EnterReadySleepHandler(Channel);
			#if (STD_ON == COMM_BSWM_USED)
			 BswM_ComM_CurrentMode(Channel, COMM_FULL_COMMUNICATION);
			#endif /* if (STD_ON == COMM_BSWM_USED) */

		}
		else if ((boolean)TRUE == ComM_ChannelInfo[Channel].EventFlags.NmBusSleep)
		{
			/*clear the NM indication event*/
			 ComM_ChannelInfo[Channel].EventFlags.NmBusSleep = (boolean)FALSE; 

			/**
			 * @req [SWS_ComM_00295] In state COMM_SILENT_COMMUNICATION and the Network Manager module
			 * 						  indicates ComM_Nm_BusSleepMode()(SWS_ComM_00392), the ComM channel
			 * 						  state machine shall switch to state COMM_NO_COMMUNICATION.
			 */
			/**
			 * @req [SWS_ComM_00898] On entering state COMM_NO_COMMUNICATION the ComM channel state machine
			 * 						 shall go to sub-state COMM_NO_COM_NO_PENDING_REQUEST.
			 */
			ComM_EnterNoComHandler(Channel);
		}
		else
		{
			/*No Handle*/
		}
	}
	else if(COMM_FULL_COMMUNICATION == ComM_ChannelInfo[Channel].ComMMode)
	{
        if (((COMM_FULL == ComM_ConfigPtr->ComMChannelCfgInfo[Channel].ComMNmVariant)
             || (COMM_PASSIVE == ComM_ConfigPtr->ComMChannelCfgInfo[Channel].ComMNmVariant))
            && ((boolean)TRUE == ComM_ChannelInfo[Channel].EventFlags.NmPreSleep))
        {
			/*clear the NM indication event*/
			 ComM_ChannelInfo[Channel].EventFlags.NmPreSleep = (boolean)FALSE;

			/**
			 * @req [SWS_ComM_00826] In COMM_FULL_COMMUNICATION and configuration parameter
			 * 						  ComMNmVariant=FULL|PASSIVE (ECUC_ComM_00568) and the Network
			 * 						  Manager module indicates ComM_Nm_PrepareBusSleepMode(), the ComM
			 * 						  state machine shall switch to state COMM_SILENT_COMMUNICATION.
			 */
            ComM_EnterSilentComHandler(Channel);
        }
        else if ((boolean)TRUE == ComM_ChannelInfo[Channel].EventFlags.NmBusSleep)
		{
			/*clear the NM indication event*/
			 ComM_ChannelInfo[Channel].EventFlags.NmBusSleep = (boolean)FALSE;
			/**
			 * @req [SWS_ComM_00637] In state COMM_FULL_COMMUNICATION and the Network Manager module
			 * 						  indicates ComM_Nm_BusSleepMode()(SWS_ComM_00392), the ComM channel
			 * 						  state machine shall switch to state COMM_NO_COMMUNICATION.
			 */
			ComM_EnterNoComHandler(Channel);
		}
   		else
        {
			/*No Handle*/
    	}
	}
	else
	{
		/*No Communication no Handle*/
	}

}

/*
 * @brief         Timer time processing in the channel.
 * @param[in]     Channel, network channel
 * @param[out]    /
 * @param[in/out] /
 * @return        /
 * @retval		  /
 */
FUNC(void, COMM_CODE) ComM_TimeHandle(
    CONST(NetworkHandleType, CANTP_CONST) Channel
)
{
	if(ComM_ChannelInfo[Channel].ModeTimer.Timer > 0u)
	{
		ComM_ChannelInfo[Channel].ModeTimer.Timer--;
	}
	else
	{
		/*No Handle*/
	}
}


/*
 * @brief         Event time processing in the channel.
 * @param[in]     Channel, network channel
 * @param[out]    /
 * @param[in/out] /
 * @return        /
 * @retval		  /
 */
FUNC(void, COMM_CODE) ComM_EventHandle(
    CONST(NetworkHandleType, CANTP_CONST) Channel
)
{
	ComM_BusType busType;
	ComM_ModeType modeType;

	modeType = ComM_ChannelInfo[Channel].ComMMode;
	/*receive the bus indication event*/

	if (COMM_INVALID_UINT8 != ComM_ChannelInfo[Channel].BusSetRecord.BusNMModeIndication)
	{
		ComM_ChannelInfo[Channel].BusSetRecord.Requested = (boolean)FALSE;
		/*set mode failed, do not need retry*/
		ComM_ChannelInfo[Channel].BusSetRecord.RetrySet = (boolean)FALSE;
		/*the event is bus_ok*/
		#if (STD_ON == COMM_RTE_NOTIFY_USED)
		/*UserModeNotify*/
		#endif /*#if (STD_ON == COMM_RTE_NOTIFY_USED)*/

#if (COMM_BSWM_USED== STD_ON)
		#if (COMM_RESET_AFTER_FORCING_NO_COMM == STD_ON)
		#if (STD_ON == COMM_MODE_LIMITATION_ENABLED)
		if(((ComM_GlobalInfo.EcuGroupClassification & COMM_MASK_LIMIT_TO_NOCOM) && \
				  ((ComM_GlobalInfo.ComM_EcuToNoCom) || (ComM_GlobalInfo.inhibitStatu[Channel]\
						  & COMM_MASK_LIMIT_TO_NOCOM)))&&\
				(COMM_NO_COMMUNICATION == ComM_ChannelInfo[Channel].ComMMode))
		{
			BswM_ComM_InitiateReset();
		}
		#endif /* if (STD_ON == COMM_MODE_LIMITATION_ENABLED) */
		#endif /*#if (COMM_RESET_AFTER_FORCING_NO_COMM == STD_ON)*/
#endif /*#if (COMM_BSWM_USED== STD_ON)*/

		/**
		 * @req [SWS_ComM_00266] The ComM module shall use the corresponding functions provided by DCM
		 * 						 to control the communication capabilities of the DCM module.
		 */
		/*informs the Dcm module about a ComM mode change */
		if(NULL_PTR != ComM_ModeIndicationTable[modeType])
		{
			ComM_ModeIndicationTable[modeType](Channel);
		}
		else
		{
			/*No Handle*/
		}


	}
	else if(((boolean)TRUE == ComM_ChannelInfo[Channel].BusSetRecord.Requested)||\
			((boolean)TRUE == ComM_ChannelInfo[Channel].BusSetRecord.RetrySet))
	{
		/*reset the bus mode*/
    	ComM_ChannelInfo[Channel].BusSetRecord.Requested = (boolean)TRUE;
		ComM_ChannelInfo[Channel].ComMMode = modeType;

		busType = ComM_ConfigPtr->ComMChannelCfgInfo[Channel].ComMBusType;

		if ((Std_ReturnType)E_OK != ComM_SMRequestComModeTable[busType](Channel,modeType))
		{
			/*set mode failed,need retry*/
			ComM_ChannelInfo[Channel].BusSetRecord.RetrySet = (boolean)TRUE;
		}
	}
	else
	{
		/*No handle*/
	}
}

/*
 * @brief         Get internal communication mode currently.
 * @param[in]     Channel, network channel
 * @param[out]    ComM_ModePtr,current ComM Mode
 * @param[in/out] /
 * @return        /
 * @retval		  /
 */
FUNC(Std_ReturnType, COMM_CODE) ComM_IntGetCurrentComMode(
    CONST(NetworkHandleType, CANTP_CONST) Channel,
    P2VAR(ComM_ModeType, AUTOMATIC, COMM_APPL_DATA) ComModePtr
)
{
    *ComModePtr = ComM_ChannelInfo[Channel].ComMMode;
    return (Std_ReturnType)E_OK;
}

/*
 * @brief         Request internal communication mode.
 * @param[in]     Channel, network channel
 * @param[in]     ComMode, request mode of the Communication Manager
 * @param[out]    /
 * @param[in/out] /
 * @return        /
 * @retval		  /
 */
FUNC(Std_ReturnType, COMM_CODE) ComM_InterRequestComMode(
    CONST(NetworkHandleType, CANTP_CONST)  Channel,
	CONST(ComM_ModeType, CANTP_CONST) ComMode
)
{
	/**
	 * @req [SWS_ComM_00664] The ComM module shall omit calls to control the communication capabilities
	 * 						 if configuration parameter ComMBusType=COMM_BUS_TYPE_INTERNAL
	 */
    ComM_ChannelInfo[Channel].BusSetRecord.Requested = (boolean)FALSE;

    ComM_ChannelInfo[Channel].BusSetRecord.RetrySet = (boolean)FALSE;
    return (Std_ReturnType)E_OK;
}

#define COMM_STOP_SEC_CODE
#include "ComM_MemMap.h"

#ifdef __cplusplus
}
#endif
/** @} */
