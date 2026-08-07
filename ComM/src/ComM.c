/**
 * @file        ComM.c
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

/* PRQA S 0292, 0288, 1503, 1505, 0857, 0791, 0828, 0647, 5087, 2877, 0491 EOF #
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

#if (STD_ON == COMM_DEV_ERROR_DETECT)
#include "Det.h"
#endif /*#if (STD_ON == COMM_DEV_ERROR_DETECT)*/

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
#define COMM_VENDOR_ID_C                   0U
#define COMM_AR_RELEASE_MAJOR_VERSION_C    4U
#define COMM_AR_RELEASE_MINOR_VERSION_C    2U
#define COMM_AR_RELEASE_REVISION_VERSION_C 2U
#define COMM_SW_MAJOR_VERSION_C            1U
#define COMM_SW_MINOR_VERSION_C            2U
#define COMM_SW_PATCH_VERSION_C            0U
/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/
/**
 * @req [SWS_ComM_00418] The version information in the module header and source files shall be
 * 						 validated and consistent (e.g. by comparing the version information in the
 * 						 module header and source files with a pre-processor macro).
 */
/* Check if current file and ComM_Internal.h header file are of the same vendor  */
#if(COMM_VENDOR_ID != COMM_INTERNAL_VENDOR_ID )
#error "ComM.c and ComM_Internal.h have different vendor id"
#endif
/* Check if current file and ComM_Internal.h header file are of the same Autosar version  */
#if(\
      (COMM_AR_RELEASE_MAJOR_VERSION_C != COMM_INTERNAL_AR_RELEASE_MAJOR_VERSION) || \
      (COMM_AR_RELEASE_MINOR_VERSION_C != COMM_INTERNAL_AR_RELEASE_MINOR_VERSION) || \
      (COMM_AR_RELEASE_REVISION_VERSION_C != COMM_INTERNAL_AR_RELEASE_REVISION_VERSION) \
      )
#error "AutoSar Version Number of ComM.c and ComM_Internal.h are different "
#endif
/* Check if current file and ComM_Internal.h header file are of the same software version  */
#if(\
      (COMM_SW_MAJOR_VERSION_C != COMM_INTERNAL_SW_MAJOR_VERSION) || \
      (COMM_SW_MINOR_VERSION_C != COMM_INTERNAL_SW_MINOR_VERSION) ||\
	  (COMM_SW_PATCH_VERSION_C != COMM_INTERNAL_SW_PATCH_VERSION)\
      )
#error "Software Version Number of ComM.c and ComM_Internal.h are different "
#endif

/* Check if current file and ComM.h header file are of the same vendor  */
#if(COMM_VENDOR_ID_C != COMM_VENDOR_ID )
#error "ComM.c and ComM.h have different vendor id"
#endif

/* Check if current file and ComM.h header file are of the same Autosar version  */
#if(\
      (COMM_AR_RELEASE_MAJOR_VERSION_C != COMM_AR_RELEASE_MAJOR_VERSION) || \
      (COMM_AR_RELEASE_MINOR_VERSION_C != COMM_AR_RELEASE_MINOR_VERSION) || \
      (COMM_AR_RELEASE_REVISION_VERSION_C != COMM_AR_RELEASE_REVISION_VERSION) \
      )
#error "AutoSar Version Number of ComM.c and ComM.h are different "
#endif

/* Check if current file and ComM.h header file are of the same software version  */
#if(\
      (COMM_SW_MAJOR_VERSION_C != COMM_SW_MAJOR_VERSION) || \
      (COMM_SW_MINOR_VERSION_C != COMM_SW_MINOR_VERSION) ||\
	  (COMM_SW_PATCH_VERSION_C != COMM_SW_PATCH_VERSION)\
      )
#error "Software Version Number of ComM.c and ComM.h are different "
#endif


#ifndef DISABLE_INTERMOD_VERSION_CHECK

#if (STD_ON == COMM_BUS_CDD_USED)
#if(\
      (COMM_AR_RELEASE_MAJOR_VERSION_C != CDD_AR_RELEASE_MAJOR_VERSION) || \
      (COMM_AR_RELEASE_MINOR_VERSION_C != CDD_AR_RELEASE_MINOR_VERSION) \
      )
#error "AutoSar Version Number of ComM.c and Cdd.h are different "
#endif
#endif /* (STD_OFF == COMM_BUS_CDD_USED) */

#if (STD_ON == COMM_BUS_ETH_USED)
#if(\
      (COMM_AR_RELEASE_MAJOR_VERSION_C != ETHSM_AR_RELEASE_MAJOR_VERSION) || \
      (COMM_AR_RELEASE_MINOR_VERSION_C != ETHSM_AR_RELEASE_MINOR_VERSION) \
      )
#error "AutoSar Version Number of ComM.c and EthSM.h are different "
#endif
#endif /* (STD_OFF == COMM_BUS_ETH_USED) */

#if (STD_ON == COMM_BUS_FLEXRAY_USED)
#if(\
      (COMM_AR_RELEASE_MAJOR_VERSION_C != FRSM_AR_RELEASE_MAJOR_VERSION) || \
      (COMM_AR_RELEASE_MINOR_VERSION_C != FRSM_AR_RELEASE_MINOR_VERSION) \
      )
#error "AutoSar Version Number of ComM.c and FrSM.h are different "
#endif
#endif /* (STD_OFF == COMM_BUS_FLEXRAY_USED) */

#if (STD_ON == COMM_BUS_LIN_USED)
#if(\
      (COMM_AR_RELEASE_MAJOR_VERSION_C != LINSM_AR_RELEASE_MAJOR_VERSION) || \
      (COMM_AR_RELEASE_MINOR_VERSION_C != LINSM_AR_RELEASE_MINOR_VERSION) \
      )
#error "AutoSar Version Number of ComM.c and LinSM.h are different "
#endif
#endif /* (STD_OFF == COMM_BUS_LIN_USED) */


#if (STD_ON == COMM_DCM_USED)
/* Check if current file and Dcm_Cbk.h header file are of the same Autosar version  */
#if(\
      (COMM_AR_RELEASE_MAJOR_VERSION_C != DCM_CBK_AR_RELEASE_MAJOR_VERSION) || \
      (COMM_AR_RELEASE_MINOR_VERSION_C != DCM_CBK_AR_RELEASE_MINOR_VERSION) \
      )
#error "AutoSar Version Number of ComM.c and Dcm_Cbk.h are different "
#endif
#endif

#if (STD_ON == COMM_BUS_CAN_USED)
/* Check if current file and CanSM_ComM.h header file are of the same Autosar version  */
#if(\
      (COMM_AR_RELEASE_MAJOR_VERSION_C != CANSM_COMM_AR_RELEASE_MAJOR_VERSION) || \
      (COMM_AR_RELEASE_MINOR_VERSION_C != CANSM_COMM_AR_RELEASE_MINOR_VERSION)\
      )
#error "AutoSar Version Number of ComM.c and CanSM_ComM.h are different "
#endif
#endif

#ifdef RTE_CODE
/* Check if current file and Rte_ComM.h header file are of the same Autosar version  */
#if(\
      (COMM_AR_RELEASE_MAJOR_VERSION_C != RTE_COMM_AR_RELEASE_MAJOR_VERSION) || \
      (COMM_AR_RELEASE_MINOR_VERSION_C != RTE_COMM_AR_RELEASE_MINOR_VERSION)\
      )
#error "AutoSar Version Number of ComM.c and Rte_ComM.h are different "
#endif

/* Check if current file and Rte_ComM_Type.h header file are of the same Autosar version  */
#if(\
      (COMM_AR_RELEASE_MAJOR_VERSION_C != RTE_COMM_TYPE_AR_RELEASE_MAJOR_VERSION) || \
      (COMM_AR_RELEASE_MINOR_VERSION_C != RTE_COMM_TYPE_AR_RELEASE_MINOR_VERSION)\
      )
#error "AutoSar Version Number of ComM.c and Rte_ComM_Type.h are different "
#endif

#endif

#if (STD_ON == COMM_NVM_USED)
#include "Nvm.h"
/* Check if current file and Nvm.h header file are of the same Autosar version  */
#if(\
      (COMM_AR_RELEASE_MAJOR_VERSION_C != NVM_AR_RELEASE_MAJOR_VERSION) || \
      (COMM_AR_RELEASE_MINOR_VERSION_C != NVM_AR_RELEASE_MINOR_VERSION) \
      )
#error "AutoSar Version Number of ComM.c and Nvm.h are different "
#endif
#endif

#if (STD_ON == COMM_DEV_ERROR_DETECT)
/* Check if current file and Det.h header file are of the same Autosar version  */
#if(\
      (COMM_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
      (COMM_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION) \
      )
#error "AutoSar Version Number of ComM.c and Det.h are different "
#endif
#endif

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
#if defined(AH_UNITTEST_ENABLED)
#define STATIC
#else
#define STATIC static
#endif /* #if defined(AH_UNITTEST_ENABLED)  */
/*====================================================================================================*
 *                                           LOCAL CONSTANTS
 *====================================================================================================*/
#define COMM_START_SEC_VAR_INIT_UNSPECIFIED
#include "ComM_MemMap.h"

/**
 * @brief Define a ComM state transformation table that represents a state that requires the
 * 		  transformation conditions that need to be met in each list, and when a particular
 * 		  condition is met by the specification, enter the corresponding ComM_StateHandler
 * 		  function
 */
/* PRQA S 1514, 3218 EOF # violate MSIAR2004_8.7: */
STATIC ComM_StateHandler ComM_StateTable[COMM_STATE_COUT][COMM_CONDITION_COUT] = {
 	{NULL_PTR,&ComM_EnterNoComPendingHandler,NULL_PTR},/*COMM_NO_COM_NO_PENDING_REQUEST*/
 	{&ComM_EnterNoComHandler,&ComM_EnterNetworkRequestedHandler,NULL_PTR},/*COMM_NO_COM_REQUEST_PENDING*/
 	{NULL_PTR,&ComM_EnterNetworkRequestedHandler,NULL_PTR},/*COMM_SILENT_COM*/
 	{&ComM_EnterReadySleepHandler,NULL_PTR,NULL_PTR},/*COMM_FULL_COM_NETWORK_REQUESTED*/
 	{&ComM_EnterNoComHandler,&ComM_EnterNetworkRequestedHandler,NULL_PTR}/*COMM_FULL_COM_READY_SLEEP*/
};

#define COMM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "ComM_MemMap.h"
/*====================================================================================================*
 *                                           LOCAL VARIABLES
 *====================================================================================================*/
#define COMM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "ComM_MemMap.h"

/**
 * @brief  Defines run-time variable of all channels
 */
 VAR(ComM_ChannelInfoType, COMM_VAR) ComM_ChannelInfo[COMM_NUMBER_OF_CHANNELS];

#define COMM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "ComM_MemMap.h"


#define COMM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "ComM_MemMap.h"

/**
 * @brief  the configuration (parameters) of ComM
 */
 P2CONST(ComM_ConfigType, AUTOMATIC, COMM_CONST) ComM_ConfigPtr;

#define COMM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "ComM_MemMap.h"


#define COMM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "ComM_MemMap.h"
/**
 * @brief Initialization status of ComM
 */
/* PRQA S 1504 EOF # violate MSIAR2004_8.10: */
STATIC VAR(ComM_InitStatusType, COMM_APPL_DATA) ComM_Status = (ComM_InitStatusType)COMM_UNINIT;

#define COMM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "ComM_MemMap.h"


#define COMM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "ComM_MemMap.h"

/**
 * @brief Defines run-time variable of all users
 */
 VAR(ComM_UserInfoType, COMM_VAR) ComM_UserInfo[COMM_NUMBER_OF_USERS];

#define COMM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "ComM_MemMap.h"


/**
 * @brief Defines global run-time variable
 */
#if ((STD_ON == COMM_WAKEUP_INHIBITION_ENABLED) || (STD_ON == COMM_MODE_LIMITATION_ENABLED))
#define COMM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "ComM_MemMap.h"

 VAR(ComM_GlobalInfoType, COMM_VAR) ComM_GlobalInfo;

#define COMM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "ComM_MemMap.h"
#endif /* (STD_ON == COMM_WAKEUP_INHIBITION_ENABLED) || (STD_ON == COMM_MODE_LIMITATION_ENABLED)*/
/*====================================================================================================*
 *                                      LOCAL FUNCTION PROTOTYPES
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
 * @sid           0x01
 * @brief         Initializes the AUTOSAR Communication Manager and restarts the internal state
 * @param[in]     ConfigPtr, Pointer to post-build configuration data
 * @param[out]    /
 * @param[in/out] /
 * @return        /
 * @retval		  /
 * @req [SWS_ComM_00146]
 */
FUNC(void, COMM_CODE)
ComM_Init(
	P2CONST(ComM_ConfigType, AUTOMATIC, COMM_APPL_DATA) ConfigPtr
)
{
	NetworkHandleType index ;

#if (STD_ON == COMM_DEV_ERROR_DETECT)
	/**
	 * @req [SWS_ComM_00612] If ComM is not initialized, all ComM module all API service other than
	 *  					  ComM_Init(), ComM_GetVersionInfo() and ComM_GetStatus(); shall:
	 *  					  - not execute their normal operation,
	 *  					  - and return E_NOT_OK, if it has a standard return type.
	 */
	/**
	 * @req [SWS_ComM_00858] If ComM is not initialized and default error detection has been
	 * 						  switched on by ComMDevErrorDetect (see ECUC_ComM_00555), the ComM
	 * 						  module shall report a development error COMM_E_NOT_INITED (by using
	 * 						  the Det_ReportError service of the Default Error Tracer module) for
	 * 						  all ComM module API services other than ComM_Init() and
	 * 						  ComM_GetVersionInfo(), and ComM_GetStatus().
	 */
	if(NULL_PTR == ConfigPtr)
	{
		COMM_DET_REPORT(COMM_SID_INIT,COMM_E_PARAM_POINTER);
	}
	else
#endif /* STD_ON == COMM_DEV_ERROR_DETECT */
	{
		ComM_ConfigPtr = ConfigPtr;

		if ((ComM_InitStatusType)COMM_UNINIT == ComM_Status)
		{
			#if (STD_ON == COMM_PNC_SUPPORT)
			/*init PNC info*/
			#endif/*#if (STD_ON == COMM_PNC_SUPPORT)*/

			/*init user info*/
			for (index = 0u; index < COMM_NUMBER_OF_USERS; index++)
			{
				ComM_UserInfo[index].RequestMode = COMM_NO_COMMUNICATION;
			}

		/*init channel info*/
		for (index = 0u; index < COMM_NUMBER_OF_CHANNELS; index++)
		{
			/**
			 * @req [SWS_ComM_00485] The default state for each ComM channel state machine shall
			 * 						  be COMM_NO_COMMUNICATION.
			 */
			ComM_ChannelInfo[index].ComMMode = COMM_NO_COMMUNICATION;
			ComM_ChannelInfo[index].ComMState = COMM_NO_COM_NO_PENDING_REQUEST;

			ComM_ChannelInfo[index].ModeTimer.Timer = 0u;
			ComM_ChannelInfo[index].ModeTimer.TimerType = COMM_NO_TIMER;

			ComM_ChannelInfo[index].EventFlags.DcmActive = (boolean)FALSE;
			ComM_ChannelInfo[index].EventFlags.EcuMWakeupInd = (boolean)FALSE;
			ComM_ChannelInfo[index].EventFlags.NmBusSleep = (boolean)FALSE;
			ComM_ChannelInfo[index].EventFlags.NmNetworkMode = (boolean)FALSE;
			ComM_ChannelInfo[index].EventFlags.NmPreSleep = (boolean)FALSE;
			ComM_ChannelInfo[index].EventFlags.NmReStart = (boolean)FALSE;
			ComM_ChannelInfo[index].EventFlags.NmStart = (boolean)FALSE;

			ComM_ChannelInfo[index].UserReqFullNum = 0u;
			/**
			 * @req [SWS_ComM_00884] The ComM module shall store status if communication for a
			 * 						 channel is allowed or not allowed in separate
			 * 						 CommunicationAllowed boolean flags for all supported channels.
			 * 						 The default value after ComM initialization shall be communication
			 * 						 is not allowed, i.e. CommunicationAllowed=FALSE.
			 */
			ComM_ChannelInfo[index].CommunicationAllowed = (boolean)FALSE;

			ComM_ChannelInfo[index].BusSetRecord.BusNMModeIndication = COMM_INVALID_UINT8;

			ComM_ChannelInfo[index].AllowedConditionType = COMM_KEEP_CURSTATE;

			#if (COMM_WAKEUP_INHIBITION_ENABLED || COMM_MODE_LIMITATION_ENABLED)
			/**
			 * @req [SWS_ComM_00157] ComMNoWakeup status must be stored non volatile.
			 */
			#if (STD_ON == COMM_WAKEUP_INHIBITION_ENABLED)
			ComM_GlobalInfo.ComMNoWakeup[index] = ComM_ConfigPtr->ComMChannelCfgInfo[index].ComMNoWakeup;
			#else
			ComM_GlobalInfo.ComMNoWakeup[index] = 0u;
			#endif
			ComM_GlobalInfo.inhibitStatu[index] = 0x0u;
			ComM_GlobalInfo.InhibitCounter = 0x0u;
			ComM_GlobalInfo.EcuGroupClassification = COMM_ECU_GROUP_CLASSIFICATION;
			/**
			 * @req [SWS_ComM_00488] It shall be possible to enable and disable the mode inhibition
			 * 						 for each channel (channel state machine) independently. This
			 * 						 functionality shall not be used by the ComM module itself.
			 */
			#if (STD_ON == COMM_WAKEUP_INHIBITION_ENABLED)
			if ((boolean)TRUE == ComM_ConfigPtr->ComMChannelCfgInfo[index].ComMNoWakeup)
			{
				ComM_GlobalInfo.inhibitStatu[index] |= COMM_MASK_INHIBIT_WAKEUP;
			}
			#endif /*#if (STD_ON == COMM_WAKEUP_INHIBITION_ENABLED) */

			#if (STD_ON == COMM_MODE_LIMITATION_ENABLED)
			if ((boolean)TRUE == ComM_ConfigPtr->ComMChannelCfgInfo[index].ComMNoCom)
			{
				ComM_GlobalInfo.inhibitStatu[index] |= COMM_MASK_LIMIT_TO_NOCOM;
			}
			#endif /*#if (STD_ON == COMM_MODE_LIMITATION_ENABLED) */
			/**
			 * @req [SWS_ComM_00140] The Inhibit counter (SWS_ComM_00138) for all rejected
			 * 						 COMM_FULL_COMMUNICATION mode requests shall be stored
			 * 						 in nonvolatile memory.
			 */
		#endif /*#if (COMM_WAKEUP_INHIBITION_ENABLED || COMM_MODE_LIMITATION_ENABLED)*/
		}
#if (COMM_WAKEUP_INHIBITION_ENABLED || COMM_MODE_LIMITATION_ENABLED)
			#if (STD_ON == COMM_NVM_USED)
			/**
			 * @req [SWS_ComM_00793] The NVRAM Manager module has to be initialized to have
			 * 						 the possibility to "direct" access the ComM module��s parameters.
			 */
			/**
			 *  @req [SWS_ComM_00864] read non-volatile parameters specified in SWS_ComM_00103
			 *  					  from NVRAM. If no parameters are available, ComM shall use
			 *  					  the default values in the ComM configuration
			 */
			/**
			 * @req [SWS_ComM_00103] The ComM module shall use the corresponding standardized
			 * 						 services of the NVRAM Manager module for storing and reading
			 * 						 non-volatile configuration data
			 */
			(void)NvM_ReadBlock(COMM_GLOBAL_NVM_BLOCK_DESCRIPTOR, &ComM_GlobalInfo);
			#endif /*#if (STD_ON == COMM_NVM_USED) */
#endif /*#if (COMM_WAKEUP_INHIBITION_ENABLED || COMM_MODE_LIMITATION_ENABLED)*/

			/* Set mode status */
			ComM_Status = (ComM_InitStatusType)COMM_INIT;
		}
	}
	return;
}


/**
 * @sid           0x02
 * @brief         This API de-initializes the AUTOSAR Communication Manager.
 * @param[in]     /
 * @param[out]    /
 * @param[in/out] /
 * @return        /
 * @retval		  /
 * @req [SWS_ComM_00147]
 */
FUNC(void, COMM_CODE)
ComM_DeInit(
	void
)
{
	boolean flag = (boolean)TRUE;
#if (STD_ON == COMM_DEV_ERROR_DETECT)
    if (COMM_UNINIT == ComM_Status)
    {
    	/**
    	 * @req [SWS_ComM_00612] If ComM is not initialized, all ComM module all API service other than
    	 *  					  ComM_Init(), ComM_GetVersionInfo() and ComM_GetStatus(); shall:
    	 *  					  - not execute their normal operation,
    	 *  					  - and return E_NOT_OK, if it has a standard return type.
    	 */
    	COMM_DET_REPORT(COMM_SID_DEINIT, COMM_E_NOT_INITED);
    }
    else
#endif /*#if (STD_ON == COMM_DEV_ERROR_DETECT) */
    {
        NetworkHandleType index  ;
    	/**
    	 * @req [SWS_ComM_00794] De-initialization in ComM_DeInit() shall only be performed if all
    	 * 						  channels controlled by the ComM module are in COMM_NO_COMMUNICATION
    	 * 						  mode.
    	 */
        for (index = 0u; index < COMM_NUMBER_OF_CHANNELS; index++)
        {
            if (COMM_NO_COMMUNICATION != ComM_ChannelInfo[index].ComMMode)
            {
            	flag = (boolean)FALSE;
            	break;
            }
        }
    	/**
    	 * @req [SWS_ComM_00865]In ComM_DeInit ComM shall store non-volatile parameters specified in
    	 * 						 SWS_ComM_00103 to NVRAM.
    	 */
        if((boolean)TRUE == flag)
        {
#if (STD_ON == COMM_NVM_USED)
#if ((STD_ON == COMM_WAKEUP_INHIBITION_ENABLED) || (STD_ON == COMM_MODE_LIMITATION_ENABLED))
        (void)NvM_WriteBlock(COMM_GLOBAL_NVM_BLOCK_DESCRIPTOR, &ComM_GlobalInfo);
#endif/* (STD_ON == COMM_WAKEUP_INHIBITION_ENABLED) || (STD_ON == COMM_MODE_LIMITATION_ENABLED)*/
#endif/* (STD_ON == COMM_NVM_USED)*/
        	ComM_Status =(ComM_InitStatusType)COMM_UNINIT;
        }
    }
    return;
}

#if (STD_ON == COMM_VERSION_INFO_API)
/**
 * @sid           0x10
 * @brief         This function returns the published information
 * @param[in]     /
 * @param[out]    /
 * @param[in/out] Versioninfo,A pointer to get the version information
 * @return        /
 * @retval		  /
 * @req [SWS_ComM_00370]
 */
FUNC(void, COMM_CODE)
ComM_GetVersionInfo(
    P2VAR(Std_VersionInfoType, AUTOMATIC, COMM_APPL_DATA) Versioninfo
)
{
#if (STD_ON == COMM_DEV_ERROR_DETECT)
	/**
	 * @req [SWS_ComM_00612] If ComM is not initialized, all ComM module all API service other than
	 *  					  ComM_Init(), ComM_GetVersionInfo() and ComM_GetStatus(); shall:
	 *  					  - not execute their normal operation,
	 *  					  - and return E_NOT_OK, if it has a standard return type.
	 */
	/**
	 * @req [SWS_ComM_00858] If ComM is not initialized and default error detection has been
	 * 						  switched on by ComMDevErrorDetect (see ECUC_ComM_00555), the ComM
	 * 						  module shall report a development error COMM_E_NOT_INITED (by using
	 * 						  the Det_ReportError service of the Default Error Tracer module) for
	 * 						  all ComM module API services other than ComM_Init() and
	 * 						  ComM_GetVersionInfo(), and ComM_GetStatus().
	 */
	if (NULL_PTR == Versioninfo)
    {
    	COMM_DET_REPORT(COMM_SID_GETVERSIONINFO,COMM_E_PARAM_POINTER);
    }
    else
#endif /*#if (STD_ON == COMM_DEV_ERROR_DETECT) */
    {
        Versioninfo->vendorID = COMM_VENDOR_ID;
        Versioninfo->moduleID = COMM_MODULE_ID;
        Versioninfo->sw_major_version = COMM_SW_MAJOR_VERSION;
        Versioninfo->sw_minor_version = COMM_SW_MINOR_VERSION;
        Versioninfo->sw_patch_version = COMM_SW_PATCH_VERSION;
    }
}
#endif/* STD_ON == COMM_VERSION_INFO_API */

/**
 * @sid           0x03
 * @brief         Returns the initialization status of the AUTOSAR Communication Manager.After
 * 				  a call to ComM_DeInit() ComM should have status COMM_UNINIT, and a new call
 * 				  to ComM_Init needed to make sure ComM restart internal state machines to
 * 		 		  default values.
 * @param[in]     /
 * @param[out]    Status,the initialization status of the AUTOSAR Communication Manager
 * @param[in/out] /
 * @return        Std_ReturnType
 * @retval		  E_OK: Successfully return of initialization status
 *                E_NOT_OK: Return of initialization status failed
 *                @req [SWS_ComM_00242]
 */
FUNC(Std_ReturnType, COMM_CODE)
ComM_GetStatus(
    P2VAR(ComM_InitStatusType, AUTOMATIC, COMM_APPL_DATA) Status
)
{
    Std_ReturnType ret;
	/**
	 * @req [SWS_ComM_00612] If ComM is not initialized, all ComM module all API service other than
	 *  					  ComM_Init(), ComM_GetVersionInfo() and ComM_GetStatus(); shall:
	 *  					  - not execute their normal operation,
	 *  					  - and return E_NOT_OK, if it has a standard return type.
	 */
	/**
	 * @req [SWS_ComM_00858] If ComM is not initialized and default error detection has been
	 * 						  switched on by ComMDevErrorDetect (see ECUC_ComM_00555), the ComM
	 * 						  module shall report a development error COMM_E_NOT_INITED (by using
	 * 						  the Det_ReportError service of the Default Error Tracer module) for
	 * 						  all ComM module API services other than ComM_Init() and
	 * 						  ComM_GetVersionInfo(), and ComM_GetStatus().
	 */
#if (STD_ON == COMM_DEV_ERROR_DETECT)
    ret = (Std_ReturnType)E_NOT_OK;
    if (NULL_PTR == Status)
    {
    	COMM_DET_REPORT(COMM_SID_GETSTATUS,COMM_E_PARAM_POINTER);
    }
    else
#endif /*#if (STD_ON == COMM_DEV_ERROR_DETECT)*/
    {
        *Status = ComM_Status;
        ret = (Std_ReturnType)E_OK;
    }
    return ret;
}

/**
 * @sid           0x34
 * @brief         Return current state, including sub-state, of the ComM channel state machine.
 * @param[in]     Channel, The Network Channel for the requested state of ComM state machine
 * @param[out]    State, State of the ComM channel state machine
 * @param[in/out] /
 * @return        Std_ReturnType
 * @retval		  E_OK: Successfully return current state of ComM state machine
 *                E_NOT_OK: Return of current state of ComM state machine failed
 *                @req [SWS_ComM_00872]
 */
FUNC(Std_ReturnType, COMM_CODE)
ComM_GetState(
    CONST(NetworkHandleType, CANTP_CONST) Channel,
    P2VAR(ComM_StateType, AUTOMATIC, COMM_APPL_DATA) State
)
{
    Std_ReturnType ret;

#if (STD_ON == COMM_DEV_ERROR_DETECT)
    ret = (Std_ReturnType)E_NOT_OK;
    if (COMM_UNINIT == ComM_Status)
    {
    	COMM_DET_REPORT(COMM_SID_GETSTATE,COMM_E_NOT_INITED);
    }
    else if (COMM_NUMBER_OF_CHANNELS <= Channel)
    {
    	COMM_DET_REPORT(COMM_SID_GETSTATE,COMM_E_WRONG_PARAMETERS);
    }
    else if (NULL_PTR == State)
    {
    	COMM_DET_REPORT(COMM_SID_GETSTATE,COMM_E_PARAM_POINTER);
    }
    else
#endif /*#if (STD_ON == COMM_DEV_ERROR_DETECT) */
    {
        *State = ComM_ChannelInfo[Channel].ComMState;
        ret = (Std_ReturnType)E_OK;
    }
    return ret;
}

/**
 * @sid           0x04
 * @brief         Returns the inhibition status of a ComM channel
 * @param[in]     Channel, network channel
 * @param[out]    Status, See ComM_InhibitionStatusType.
 * @param[in/out] /
 * @return        Std_ReturnType
 * @retval		  E_OK: Successfully returned Inhibition Status
 *                E_NOT_OK: Return of Inhibition Status failed
 *                @req [SWS_ComM_00619]
 */
FUNC(Std_ReturnType, COMM_CODE)
ComM_GetInhibitionStatus(
	CONST(NetworkHandleType, COMM_CONST) Channel,
    P2VAR(ComM_InhibitionStatusType, AUTOMATIC, COMM_APPL_DATA) Status
)
{
	Std_ReturnType ret;

#if (STD_ON == COMM_DEV_ERROR_DETECT)
	ret = (Std_ReturnType)E_NOT_OK;
    if (COMM_UNINIT == ComM_Status)
    {
    	COMM_DET_REPORT(COMM_SID_GETINHIBITIONSTATUS,COMM_E_NOT_INITED);
    }
    else if (NULL_PTR == Status)
    {
    	COMM_DET_REPORT(COMM_SID_GETINHIBITIONSTATUS,COMM_E_PARAM_POINTER);
    }
    else if (COMM_NUMBER_OF_CHANNELS <= Channel)
    {
    	COMM_DET_REPORT(COMM_SID_GETINHIBITIONSTATUS,COMM_E_WRONG_PARAMETERS);
    }
    else
#endif /*#if (STD_ON == COMM_DEV_ERROR_DETECT)*/
    {
#if (COMM_WAKEUP_INHIBITION_ENABLED || COMM_MODE_LIMITATION_ENABLED)
        *Status = ComM_GlobalInfo.inhibitStatu[Channel];
#else
        *Status = 0u;
#endif /*#if (COMM_WAKEUP_INHIBITION_ENABLED || COMM_MODE_LIMITATION_ENABLED)*/

        ret = (Std_ReturnType)E_OK;
    }
    return ret;
}

/**
 * @sid           0x05
 * @brief         Requesting of a Communication Mode by a user.
 * @param[in]     User, Handle of the user who requests a mode
 * @param[in]     ComMode, COMM_FULL_COMMUNICATION COMM_NO_COMMUNICATION
 * @param[out]    /
 * @param[in/out] /
 * @return        /
 * @retval		  E_OK: Successfully changed to the new mode
 *                E_NOT_OK: Changing to the new mode failed
 *                COMM_E_MODE_LIMITATION:Function call has been successfully but mode
 *                can not be granted because of mode inhibition.
 *                @req [SWS_ComM_00079]
 */
FUNC(Std_ReturnType, COMM_CODE)
ComM_RequestComMode(
    CONST(ComM_UserHandleType, CANTP_CONST) User,
	CONST(ComM_ModeType, CANTP_CONST) ComMode
)
{
	Std_ReturnType ret;
	boolean reqRslt = (boolean)FALSE;
    uint8 index;
    NetworkHandleType ChIndex;

#if (STD_ON == COMM_DEV_ERROR_DETECT)
    ret = (Std_ReturnType)E_NOT_OK;

    if (COMM_UNINIT == ComM_Status)
    {
    	COMM_DET_REPORT(COMM_SID_REQUESTCOMMODE,COMM_E_NOT_INITED);
    }
	/**
	 * @req [SWS_ComM_00151] For a user it shall only be possible to request the Communication Modes
	 * 						 COMM_NO_COMMUNICATION and COMM_FULL_COMMUNICATION
	 */
	/**
	 * @req [SWS_ComM_00868] The Communication Mode COMM_SILENT_COMMUNICATION shall only be used for
	 * 					     network synchronization.
	 */
    else if ((COMM_NO_COMMUNICATION != ComMode) && (COMM_FULL_COMMUNICATION != ComMode))
    {
    	COMM_DET_REPORT(COMM_SID_REQUESTCOMMODE,COMM_E_WRONG_PARAMETERS);
    }
    else if (COMM_NUMBER_OF_USERS <= User)
    {
    	COMM_DET_REPORT(COMM_SID_REQUESTCOMMODE,COMM_E_WRONG_PARAMETERS);
    }
    else
#endif /*#if (STD_ON == COMM_DEV_ERROR_DETECT)*/
    {
    	/**
    	 * @req [SWS_ComM_00795] Configuration of ComM_RequestComMode: Relationship between users
    	 * 						  and channels. A user is statically mapped to one or more channels.
    	 */
    	/**
    	 * @req [SWS_ComM_00500] The ComM module shall not queue user requests. The latest user request
    	 * 						 of the same user shall overwrite an old user request even if the request
    	 * 						 is not finished.
    	 */
		/**
		 * @req [SWS_ComM_00625] The status of the user requests shall also be updated if a user releases
		 * 						 a request.
		 */
        if (ComMode != ComM_UserInfo[User].RequestMode)
        {
        	/**
        	 * @req [SWS_ComM_00839] The ComM module shall store the status of the user requests.
        	 */
        	ComM_UserInfo[User].RequestMode = ComMode;

            for(index = 0u;index < ComM_ConfigPtr->ComMUserCfgInfo[User].ChannelNum; index++)
            {
            	ChIndex = ComM_ConfigPtr->ComMUserCfgInfo[User].ChannelMap[index];

				if (COMM_FULL_COMMUNICATION == ComMode)
				{
					/**
					 * @req [SWS_ComM_00686] If at least one of multiple independent user requests
					 * 						 demands a higher Communication Mode , the ComM module
					 * 						 shall set this higher Communication Mode as the target
					 * 						 Communication Mode.
					 */
					/**
					 * @req [SWS_ComM_00138] The ComM module shall provide one Inhibit counter for
					 * 						 all rejected COMM_FULL_COMMUNICATION mode requests. It
					 * 						 shall count user requests, which cannot be fulfilled
					 * 						 because the system has inhibited communication modes.
					 */
					/**
					 * @req [SWS_ComM_00142] The Inhibit counter (SWS_ComM_00138) for all rejected
					 * 						 COMM_FULL_COMMUNICATION mode requests shall stop to
					 * 						 increment if the maximum counter value is reached.
					 */
				#if (STD_ON == COMM_WAKEUP_INHIBITION_ENABLED)
					if((ComM_GlobalInfo.InhibitCounter < COMM_MAX_REJECT_COUNTER)&&\
							(ComM_ChannelInfo[ChIndex].ComMState <= COMM_SILENT_COM))
					{
						if((ComM_GlobalInfo.EcuGroupClassification & \
								ComM_GlobalInfo.inhibitStatu[ChIndex]) == COMM_MASK_INHIBIT_WAKEUP)
							/* PRQA S 0715 EOF # violate MSIAR2004_1.1: */
						{
							ComM_GlobalInfo.InhibitCounter++;
						}
					}
					else
					{
						/*No Handle*/
					}

				#endif/* (STD_ON == COMM_WAKEUP_INHIBITION_ENABLED)*/

					/**
					 * @req [SWS_ComM_00842] The ComM module shall ignore requests in other states
					 * 						 than COMM_FULL_COM_NETWORK_REQUESTED.
					 */
					/**
					 * @req [SWS_ComM_00215] All active user requests for communication channel X
					 * 						 shall be ignored if the ComM Inhibition ComMNoCom=(boolean)TRUE
					 * 						 for the corresponding channel to guarantee entering the
					 * 						 COMM_NO_COMMUNICATION state for channel X.
					 */
				#if (STD_ON == COMM_MODE_LIMITATION_ENABLED)
					if((ComM_GlobalInfo.InhibitCounter < COMM_MAX_REJECT_COUNTER)&&\
							(ComM_ChannelInfo[ChIndex].ComMState == COMM_FULL_COM_NETWORK_REQUESTED))
					{
						if(((ComM_GlobalInfo.EcuGroupClassification & COMM_MASK_LIMIT_TO_NOCOM) == \
						   COMM_MASK_LIMIT_TO_NOCOM) && (((boolean)TRUE == \
						   ComM_GlobalInfo.ComM_EcuToNoCom) || ((ComM_GlobalInfo.inhibitStatu[ChIndex] \
						   & COMM_MASK_LIMIT_TO_NOCOM) == COMM_MASK_LIMIT_TO_NOCOM)))
						{
							ComM_GlobalInfo.InhibitCounter++;
							reqRslt = (boolean)TRUE;

						}
					}
					else
					{
						/*No Handle*/
					}
				#endif/* (STD_ON == COMM_MODE_LIMITATION_ENABLED)*/
						ComM_ChannelInfo[ChIndex].UserReqFullNum++;

				}
				else
				{
					/**
					 * @req [SWS_ComM_00840] The ComM module shall store the updated status of the user
					 * 						 requests if a user releases a request during an active mode
					 * 						 inhibition.
					 */
					if (ComM_ChannelInfo[ChIndex].UserReqFullNum > 0u)
					{
						ComM_ChannelInfo[ChIndex].UserReqFullNum--;
					}
				}
            }
        }
        if((boolean)TRUE == reqRslt)/* PRQA S 2992, 2996 #violate MISAR2004_4.13.7: */
        {
            ret = (Std_ReturnType)COMM_E_MODE_LIMITATION;/* PRQA S 2880 #violate MISAR2004_4.14.1: */
        }
        else
        {
            ret = (Std_ReturnType)E_OK;
        }
    }
    return ret;
}


/**
 * @sid           0x60
 * @brief         This function shall perform the processing of the AUTOSAR ComM activities
 * 				  that are not directly initiated by the calls e.g. from the RTE. There shall
 * 				  be one dedicated Main Function for each channel of ComM.
 * @param[in]     Channel, network channel
 * @param[out]    /
 * @param[in/out] /
 * @return        /
 * @retval		  /
 * @req [SWS_ComM_00429]
 */
FUNC(void, COMM_CODE)
ComM_MainFunction(
	CONST(NetworkHandleType, CANTP_CONST) Channel
)
{
#if (STD_ON == COMM_DEV_ERROR_DETECT)
    if (COMM_UNINIT == ComM_Status)
    {
		/**
		 * @req [SWS_ComM_00612] If ComM is not initialized, all ComM module all API service other than
		 *  					  ComM_Init(), ComM_GetVersionInfo() and ComM_GetStatus(); shall:
		 *  					  - not execute their normal operation,
		 *  					  - and return E_NOT_OK, if it has a standard return type.
		 */
    	/**
		 * @req [SWS_ComM_00858] If ComM is not initialized and default error detection has been
		 * 						  switched on by ComMDevErrorDetect (see ECUC_ComM_00555), the ComM
		 * 						  module shall report a development error COMM_E_NOT_INITED (by using
		 * 						  the Det_ReportError service of the Default Error Tracer module) for
		 * 						  all ComM module API services other than ComM_Init() and
		 * 						  ComM_GetVersionInfo(), and ComM_GetStatus().
		 */
    	COMM_DET_REPORT(COMM_SID_MAINFUNCATION,COMM_E_NOT_INITED);
    }
    else if (COMM_NUMBER_OF_CHANNELS <= Channel)
    {
    	COMM_DET_REPORT(COMM_SID_MAINFUNCATION,COMM_E_WRONG_PARAMETERS);
    }
    else
#endif /*#if (STD_ON == COMM_DEV_ERROR_DETECT) */
    {
    	ComM_StateType curState ;
    	ComM_ConditionType curCondition ;

		if((ComM_ChannelInfo[Channel].ModeTimer.IsStarted == (boolean)TRUE)&&\
				(ComM_ChannelInfo[Channel].ModeTimer.TimerType != COMM_NO_TIMER))
		{
			ComM_TimeHandle(Channel);
		}
		else
		{
			/*No Handle*/
		}

		/*Event time processing in the channel*/
		ComM_EventHandle(Channel);

		#if (STD_ON == COMM_NM_USED)
		if (((boolean)TRUE == ComM_ChannelInfo[Channel].EventFlags.NmBusSleep)||\
				((boolean)TRUE == ComM_ChannelInfo[Channel].EventFlags.NmPreSleep)||\
				((boolean)TRUE == ComM_ChannelInfo[Channel].EventFlags.NmNetworkMode))
		{
			/*Processing the transformation between the mode*/
			ComM_ModeHandle(Channel);
		}
		else
		{
			/*No Handle*/
		}
		#endif /*#if (STD_ON == COMM_NM_USED)*/

    	/**
		 * @req [SWS_ComM_00092] If ComM is not initialized and default error detection has been
		 * 						  switched on by ComMDevErrorDetect (see ECUC_ComM_00555), the ComM
		 * 						  module shall report a development error COMM_E_NOT_INITED (by using
		 * 						  the Det_ReportError service of the Default Error Tracer module) for
		 * 						  all ComM module API services other than ComM_Init() and
		 * 						  ComM_GetVersionInfo(), and ComM_GetStatus().
		 */

		/*Processing the transformation between the state*/
		ComM_ConditionCheck(Channel);

        curState = ComM_ChannelInfo[Channel].ComMState;
    	curCondition = ComM_ChannelInfo[Channel].AllowedConditionType;

		if(NULL_PTR != ComM_StateTable[curState][curCondition])
		{
			ComM_StateTable[curState][curCondition](Channel);
		}
		else
		{
			/*No Handle*/
		}
    }
}
#if (STD_ON == COMM_NM_USED)
/**
 * @sid           0x15
 * @brief         Indication that a NM-message has been received in the Bus Sleep Mode, what
 *                indicates that some nodes in the network have already entered the Network Mode.
 * @param[in]     Channel, network channel
 * @param[out]    /
 * @param[in/out] /
 * @return        /
 * @retval		  /
 * @req [SWS_ComM_00383]
 */
FUNC(void, COMM_NM_CODE)
ComM_Nm_NetworkStartIndication(
    CONST(NetworkHandleType, CANTP_CONST) Channel
)
{
#if (STD_ON == COMM_DEV_ERROR_DETECT)
    if (COMM_UNINIT == ComM_Status)
    {
    	/**
		 * @req [SWS_ComM_00805] Caveats of ComM_Nm_NetworkStartIndication: The ComM module is
		 * 						  initialized correctly.
		 */
    	COMM_DET_REPORT(COMM_SID_NM_NETWORKSTARTINDICATION,COMM_E_NOT_INITED);
    }
    else if (COMM_NUMBER_OF_CHANNELS <= Channel)
    {
    	COMM_DET_REPORT(COMM_SID_NM_NETWORKSTARTINDICATION,COMM_E_WRONG_PARAMETERS);
    }
	/**
	 * @req [SWS_ComM_00602] The ComM module shall omit calls of NM services if configuration
	 * 						 parameter ComMNmVariant=LIGHT|NONE
	 */
    else if ((ComM_ConfigPtr->ComMChannelCfgInfo[Channel].ComMNmVariant != (ComM_NmVariantType)COMM_FULL)
             && (ComM_ConfigPtr->ComMChannelCfgInfo[Channel].ComMNmVariant != COMM_PASSIVE))
    {
    	COMM_DET_REPORT(COMM_SID_NM_NETWORKSTARTINDICATION,COMM_E_WRONG_PARAMETERS);
    }
    else
#endif /*#if (STD_ON == COMM_DEV_ERROR_DETECT) */
    {
    	/**
		 * @req [SWS_ComM_00583] The ComM module shall switch channel X to COMM_FULL_COMMUNICATION
		 * 						  if NM indicates ComM_Nm_NetworkStartIndication(<channel X>) and
		 * 						  CommunicationAllowed flag is set to (boolean)TRUE.
		 */
    	ComM_ChannelInfo[Channel].EventFlags.NmStart = (boolean)TRUE;
    }
    return;
}

/**
 * @sid           0x18
 * @brief         Notification that the network management has entered Network Mode.
 * @param[in]     Channel, network channel
 * @param[out]    /
 * @param[in/out] /
 * @return        /
 * @retval		  /
 * @req [SWS_ComM_00390]
 */
FUNC(void, COMM_NM_CODE)
ComM_Nm_NetworkMode(
    CONST(NetworkHandleType, CANTP_CONST) Channel
)
{
#if (STD_ON == COMM_DEV_ERROR_DETECT)
    if (COMM_UNINIT == ComM_Status)
    {
    	/**
		 * @req [SWS_ComM_00806] Caveats of ComM_Nm_NetworkMode: The ComM module is
		 * 						  initialized correctly.
		 */
    	COMM_DET_REPORT(COMM_SID_NM_NETWORKMODE,COMM_E_NOT_INITED);
    }
    else if (COMM_NUMBER_OF_CHANNELS <= Channel)
    {
    	COMM_DET_REPORT(COMM_SID_NM_NETWORKMODE,COMM_E_WRONG_PARAMETERS);
    }
	/**
	 * @req [SWS_ComM_00602] The ComM module shall omit calls of NM services if configuration
	 * 						 parameter ComMNmVariant=LIGHT|NONE
	 */
    else if ((ComM_ConfigPtr->ComMChannelCfgInfo[Channel].ComMNmVariant != COMM_FULL)
             && (ComM_ConfigPtr->ComMChannelCfgInfo[Channel].ComMNmVariant != COMM_PASSIVE))
    {
    	COMM_DET_REPORT(COMM_SID_NM_NETWORKMODE,COMM_E_WRONG_PARAMETERS);
    }
    else
#endif /*#if (STD_ON == COMM_DEV_ERROR_DETECT) */
    {
    	/* @req [SWS_ComM_00296] */
    	if(ComM_ChannelInfo[Channel].ComMState != COMM_FULL_COM_NETWORK_REQUESTED)
    	{
    		ComM_ChannelInfo[Channel].EventFlags.NmNetworkMode = (boolean)TRUE;
    	}
    }
    return;
}

/**
 * @sid           0x19
 * @brief         Notification that the network management has entered Prepare Bus-Sleep Mode.
 * @param[in]     Channel, network channel
 * @param[out]    /
 * @param[in/out] /
 * @return        /
 * @retval		  /
 * @req [SWS_ComM_00391]
 */
FUNC(void, COMM_NM_CODE)
ComM_Nm_PrepareBusSleepMode(
    CONST(NetworkHandleType, CANTP_CONST) Channel
)
{
#if (STD_ON == COMM_DEV_ERROR_DETECT)
    if (COMM_UNINIT == ComM_Status)
    {
    	/**
		 * @req [SWS_ComM_00808] Caveats of ComM_Nm_PrepareBusSleepMode: The ComM module is
		 * 						  initialized correctly.
		 */
    	COMM_DET_REPORT(COMM_SID_NM_PREPAREBUSSLEEPMODE,COMM_E_NOT_INITED);
    }
    else if (COMM_NUMBER_OF_CHANNELS <= Channel)
    {
    	COMM_DET_REPORT(COMM_SID_NM_PREPAREBUSSLEEPMODE,COMM_E_WRONG_PARAMETERS);
    }
	/**
	 * @req [SWS_ComM_00602] The ComM module shall omit calls of NM services if configuration
	 * 						 parameter ComMNmVariant=LIGHT|NONE
	 */
    else if ((ComM_ConfigPtr->ComMChannelCfgInfo[Channel].ComMNmVariant != COMM_FULL)
             && (ComM_ConfigPtr->ComMChannelCfgInfo[Channel].ComMNmVariant != COMM_PASSIVE))
    {
    	COMM_DET_REPORT(COMM_SID_NM_PREPAREBUSSLEEPMODE,COMM_E_WRONG_PARAMETERS);
    }
    else
#endif /*#if (STD_ON == COMM_DEV_ERROR_DETECT) */
    {
    	/* @req [SWS_ComM_00826] */
    	ComM_ChannelInfo[Channel].EventFlags.NmPreSleep = (boolean)TRUE;
    }
    return;
}

/**
 * @sid           0x1a
 * @brief         Notification that the network management has entered Bus-Sleep Mode.
 *                This callback function should perform a transition of the hardware and
 *                transceiver to bus-sleep mode.
 * @param[in]     Channel, network channel
 * @param[out]    /
 * @param[in/out] /
 * @return        /
 * @retval		  /
 * @req [SWS_ComM_00392]
 */
FUNC(void, COMM_NM_CODE)
ComM_Nm_BusSleepMode(
    CONST(NetworkHandleType, CANTP_CONST) Channel
)
{
#if (STD_ON == COMM_DEV_ERROR_DETECT)
    if (COMM_UNINIT == ComM_Status)
    {
    	/**
		 * @req [SWS_ComM_00810] Caveats of ComM_Nm_BusSleepMode: The ComM module is
		 * 						  initialized correctly.
		 */
    	COMM_DET_REPORT(COMM_SID_NM_BUSSLEEPMODE,COMM_E_NOT_INITED);
    }
    else if (COMM_NUMBER_OF_CHANNELS <= Channel)
    {
    	COMM_DET_REPORT(COMM_SID_NM_BUSSLEEPMODE,COMM_E_WRONG_PARAMETERS);
    }
	/**
	 * @req [SWS_ComM_00602] The ComM module shall omit calls of NM services if configuration
	 * 						 parameter ComMNmVariant=LIGHT|NONE
	 */
    else if ((ComM_ConfigPtr->ComMChannelCfgInfo[Channel].ComMNmVariant != COMM_FULL)
             && (ComM_ConfigPtr->ComMChannelCfgInfo[Channel].ComMNmVariant != COMM_PASSIVE))
    {
    	COMM_DET_REPORT(COMM_SID_NM_BUSSLEEPMODE,COMM_E_WRONG_PARAMETERS);
    }
    else
#endif /*#if (STD_ON == COMM_DEV_ERROR_DETECT) */
    {
    	/*  @req [SWS_ComM_00295]  @req [SWS_ComM_00637] */
    	ComM_ChannelInfo[Channel].EventFlags.NmBusSleep = (boolean)TRUE;
    }
    return;
}

/**
 * @sid           0x1a
 * @brief         If NmIf has started to shut down the coordinated busses, AND not all coordinated
 *                busses have indicated bus sleep state, AND on at least on one of the coordinated
 * 				  busses NM is restarted, THEN the NM Interface shall call the callback function
 *				  ComM_Nm_RestartIndication with the nmNetworkHandle of the channels which have
 * 				  already indicated bus sleep state.
 * @param[in]     Channel, network channel
 * @param[out]    /
 * @param[in/out] /
 * @return        /
 * @retval		  /
 * @req [SWS_ComM_00792]
 */
FUNC(void, COMM_NM_CODE)
ComM_Nm_RestartIndication(
    CONST(NetworkHandleType, CANTP_CONST) Channel
)
{
#if (STD_ON == COMM_DEV_ERROR_DETECT)
    if (COMM_UNINIT == ComM_Status)
    {
    	/**
		 * @req [SWS_ComM_00812] Caveats of ComM_Nm_RestartIndication: The ComM module is
		 * 						  initialized correctly.
		 */
    	COMM_DET_REPORT(COMM_SID_NM_RESTARTINDICATION,COMM_E_NOT_INITED);
    }
    else if (COMM_NUMBER_OF_CHANNELS <= Channel)
    {
    	COMM_DET_REPORT(COMM_SID_NM_RESTARTINDICATION,COMM_E_WRONG_PARAMETERS);
    }
	/**
	 * @req [SWS_ComM_00602] The ComM module shall omit calls of NM services if configuration
	 * 						 parameter ComMNmVariant=LIGHT|NONE
	 */
    else if ((ComM_ConfigPtr->ComMChannelCfgInfo[Channel].ComMNmVariant != COMM_FULL)
             && (ComM_ConfigPtr->ComMChannelCfgInfo[Channel].ComMNmVariant != COMM_PASSIVE))
    {
    	COMM_DET_REPORT(COMM_SID_NM_RESTARTINDICATION,COMM_E_WRONG_PARAMETERS);
    }
    else
#endif /*#if (STD_ON == COMM_DEV_ERROR_DETECT) */
    {
    	/* @req [SWS_ComM_00894] */
    	ComM_ChannelInfo[Channel].EventFlags.NmReStart = (boolean)TRUE;
    }
    return;
}
#endif /*#if (STD_ON == COMM_NM_USED)*/

#if (STD_ON == COMM_DCM_USED)
/**
 * @sid           0x1f
 * @brief         Indication of active diagnostic by the DCM.
 * @param[in]     Channel, Channel needed for Diagnostic communication
 * @param[out]    /
 * @param[in/out] /
 * @return        /
 * @retval		  /
 * @req [SWS_ComM_00873]
 */
FUNC(void, COMM_DCM_CODE)
ComM_DCM_ActiveDiagnostic(
    CONST(NetworkHandleType, CANTP_CONST) Channel
)
{
#if (STD_ON == COMM_DEV_ERROR_DETECT)
    if (COMM_UNINIT == ComM_Status)
    {
    	COMM_DET_REPORT(COMM_SID_DCM_ACTIVEDIAGNOSTIC,COMM_E_NOT_INITED);
    }
    else if (COMM_NUMBER_OF_CHANNELS <= Channel)
    {
    	COMM_DET_REPORT(COMM_SID_DCM_ACTIVEDIAGNOSTIC,COMM_E_WRONG_PARAMETERS);
    }
    else
#endif /*#if (STD_ON == COMM_DEV_ERROR_DETECT) */
    {
        if (COMM_PASSIVE != ComM_ConfigPtr->ComMChannelCfgInfo[Channel].ComMNmVariant)
        {
        	/**
    		 * @req [SWS_ComM_00866] If configuration parameter ComMNmVariant=FULL|LIGHT|NONE , an
    		 * 						 DCM_ActiveDiagnostic indication shall be treated as a
    		 * 						 COMM_FULL_COMMUNICATION request for the specified communication
    		 * 						 channel .
    		 */
        	ComM_ChannelInfo[Channel].EventFlags.DcmActive = (boolean)TRUE;

        	if(COMM_FULL_COMMUNICATION == ComM_ChannelInfo[Channel].ComMMode)
        	{
        		Dcm_ComM_FullComModeEntered(Channel);
        	}
        	/**
    		 * @req [SWS_ComM_00182] The communication inhibition shall get temporarily inactive
    		 * 						 during an active diagnostic session .
    		 */
#if((STD_ON==COMM_WAKEUP_INHIBITION_ENABLED) || (STD_ON==COMM_MODE_LIMITATION_ENABLED))
    	ComM_GlobalInfo.ComM_EcuToNoCom = (boolean)FALSE;
#endif /*#if ((STD_ON==COMM_WAKEUP_INHIBITION_ENABLED) || (STD_ON==COMM_MODE_LIMITATION_ENABLED)) */
        }
    }
    return;
}

/**
 * @sid           0x20
 * @brief         Indication of inactive diagnostic by the DCM.
 * @param[in]     Channel, Channel no longer needed for Diagnostic communication
 * @param[out]    /
 * @param[in/out] /
 * @return        /
 * @retval		  /
 * @req [SWS_ComM_00874]
 */
FUNC(void, COMM_DCM_CODE)
ComM_DCM_InactiveDiagnostic(
    CONST(NetworkHandleType, CANTP_CONST) Channel
)
{
#if (STD_ON == COMM_DEV_ERROR_DETECT)
    if (COMM_UNINIT == ComM_Status)
    {
    	COMM_DET_REPORT(COMM_SID_DCM_INACTIVEDIAGNOSTIC,COMM_E_NOT_INITED);
    }
    else if (COMM_NUMBER_OF_CHANNELS <= Channel)
    {
    	COMM_DET_REPORT(COMM_SID_DCM_INACTIVEDIAGNOSTIC,COMM_E_WRONG_PARAMETERS);
    }
    else
#endif /*#if (STD_ON == COMM_DEV_ERROR_DETECT) */
    {
    	ComM_ChannelInfo[Channel].EventFlags.DcmActive = (boolean)FALSE;
    }
    return;
}
#endif /*#if (STD_ON == COMM_DCM_USED)*/


/**
 * @sid           0x33
 * @brief         Indication of the actual bus mode by the corresponding Bus State Manager.
 * 				  ComM shall propagate the indicated state to the users with means of the RTE
 * 				  and BswM.
 * @param[in]     Channel, Channel Index
 * @param[in]     ComMode, Communication mode
 * @param[out]    /
 * @param[in/out] /
 * @req [SWS_ComM_00675]
 */
FUNC(void, COMM_BUSSM_CODE)
ComM_BusSM_ModeIndication(
    CONST(NetworkHandleType, CANTP_CONST) Channel,
	P2CONST(ComM_ModeType, AUTOMATIC, CANIF_APPL_DATA) ComMode
)
{
#if (STD_ON == COMM_DEV_ERROR_DETECT)
    if (COMM_UNINIT == ComM_Status)
    {
    	/**
		 * @req [SWS_ComM_00816] Caveats of ComM_BusSM_ModeIndication: The ComM module is
		 * 						  initialized correctly.
		 */
    	COMM_DET_REPORT(COMM_SID_BUSSM_MODEINDICATION,COMM_E_NOT_INITED);
    }
    else if (NULL_PTR == ComMode)
    {
    	COMM_DET_REPORT(COMM_SID_BUSSM_MODEINDICATION,COMM_E_PARAM_POINTER);
    }
    else if ((COMM_NO_COMMUNICATION != *ComMode) && (COMM_SILENT_COMMUNICATION != *ComMode)
             && (COMM_FULL_COMMUNICATION != *ComMode))
    {
    	COMM_DET_REPORT(COMM_SID_BUSSM_MODEINDICATION,COMM_E_WRONG_PARAMETERS);
    }
    else if (COMM_NUMBER_OF_CHANNELS <= Channel)
    {
    	COMM_DET_REPORT(COMM_SID_BUSSM_MODEINDICATION,COMM_E_WRONG_PARAMETERS);
    }
    else
#endif /*#if (STD_ON == COMM_DEV_ERROR_DETECT) */
    {
        if ((boolean)TRUE == ComM_ChannelInfo[Channel].BusSetRecord.Requested)
        {
        	/*clear bus request*/
        	ComM_ChannelInfo[Channel].BusSetRecord.Requested = (boolean)FALSE;

            if (ComM_ChannelInfo[Channel].ComMMode == *ComMode)
            {
            	/*bus request set ok*/
                ComM_ChannelInfo[Channel].BusSetRecord.BusNMModeIndication = *ComMode;
            }
            else
            {
            	/*set mode failed,need retry*/
				ComM_ChannelInfo[Channel].BusSetRecord.RetrySet = (boolean)TRUE;
            }
        }
    }
    return;
}

#if (STD_ON == COMM_ECUM_USED)
/**
 * @sid           0x2a
 * @brief         Notification of a wake up on the corresponding channel.
 * @param[in]     Channel, Channel Index
 * @param[out]    /
 * @param[in/out] /
 * @req [SWS_ComM_00275]
 */
FUNC(void, COMM_ECUM_CODE)
ComM_EcuM_WakeUpIndication(
    CONST(NetworkHandleType, CANTP_CONST) Channel
)
{
#if (STD_ON == COMM_SYNCHRONOUS_WAKE_UP)
	uint8 ChannelIndex;
#endif/*#if (STD_ON == COMM_SYNCHRONOUS_WAKE_UP)*/
#if (STD_ON == COMM_DEV_ERROR_DETECT)
    if (COMM_UNINIT == ComM_Status)
    {
    	/**
		 * @req [SWS_ComM_00814] Caveats of ComM_EcuM_WakeUpIndication: The ComM module is
		 * 						  initialized correctly.
		 */
    	COMM_DET_REPORT(COMM_SID_ECUM_WAKEUPINDICATION,COMM_E_NOT_INITED);
    }
    else if (COMM_NUMBER_OF_CHANNELS <= Channel)
    {
    	COMM_DET_REPORT(COMM_SID_ECUM_WAKEUPINDICATION,COMM_E_WRONG_PARAMETERS);
    }
    else
#endif /*#if (STD_ON == COMM_DEV_ERROR_DETECT) */
    {
#if (STD_ON == COMM_SYNCHRONOUS_WAKE_UP)
		/* @req [SWS_ComM_00694] */
        for (ChannelIndex = 0u; ChannelIndex < COMM_NUMBER_OF_CHANNELS; ChannelIndex++)
        {
        	ComM_ChannelInfo[ChannelIndex].EventFlags.EcuMWakeupInd = (boolean)TRUE;
        }
#else
        {
        	ComM_ChannelInfo[Channel].EventFlags.EcuMWakeupInd = (boolean)TRUE;
        }
#endif/*#if (STD_ON == COMM_SYNCHRONOUS_WAKE_UP)*/
    }

    return;
}
#endif /*#if (STD_ON == COMM_ECUM_USED)*/

/**
 * @sid           0x35
 * @brief         EcuM or BswM shall indicate to ComM when communication is allowed.
 * @param[in]     Channel, Channel
 * @param[in]     Allowed, (boolean)TRUE: Communication is allowed
 *                         FALSE: Communication is not allowed
 * @param[out]    /
 * @param[in/out] /
 *                @req [SWS_ComM_00871]
 */
FUNC(void, COMM_ECUMBSWM_CODE)
ComM_CommunicationAllowed(
    CONST(NetworkHandleType, CANTP_CONST) Channel,
	CONST(boolean, CANTP_CONST) Allowed
)
{
#if (STD_ON == COMM_DEV_ERROR_DETECT)
    if (COMM_UNINIT == ComM_Status)
    {
    	COMM_DET_REPORT(COMM_SID_COMMUNICATIONALLOWED,COMM_E_NOT_INITED);
    }
    else if (COMM_NUMBER_OF_CHANNELS <= Channel)
    {
    	COMM_DET_REPORT(COMM_SID_COMMUNICATIONALLOWED,COMM_E_WRONG_PARAMETERS);
    }
    else
#endif /*#if (STD_ON == COMM_DEV_ERROR_DETECT) */
    {
    	/**
    	 * @req [SWS_ComM_00885] Status changes for communication allowed or not allowed
    	 * 						 in SWS_ComM_00884 shall be provided to ComM
    	 * 						 inComM_CommunicationAllowed(<channel>
    	 */
        ComM_ChannelInfo[Channel].CommunicationAllowed = Allowed;
    }
}

#if (STD_ON == COMM_PNC_SUPPORT)
/**
 * @sid           0x36
 * @brief         This callback is called when the EIRA or ERA was updated in COM. The call
 * 				  only informs the ComM about ERA and EIRA changes. The actual handling is
 * 				  done in the next call to ComM_MainFunction_<Channel_Id> with changing the
 * 				  corresponding PN State machine.
 * @param[in]      signalId, ERA/EIRA signal id
 * @param[out]    /
 * @param[in/out] /
 *                @req [SWS_ComM_00819]
 */
FUNC(void, COMM_COM_CODE)
ComM_COMCbk(
    uint16 signalId
)
{

}
#endif/*#if (STD_ON == COMM_PNC_SUPPORT)*/

/**
 * @req [SWS_ComM_00301] The ComM module shall offer interfaces to request and release
 * 						 the corresponding mode inhibitions.
 */
#if ((STD_ON == COMM_WAKEUP_INHIBITION_ENABLED) || (STD_ON == COMM_MODE_LIMITATION_ENABLED))
/**
 * @sid           0x0f
 * @brief         Changes the ECU Group Classification status
 * @param[in]     Status, See ComM_InhibitionStatusType
 * @param[out]    /
 * @param[in/out] /
 * @return        Std_ReturnType
 * @retval		  E_OK: Successfully change the ECU Group Classification Status
 *                E_NOT_OK: Change of the ECU Group Classification Status failed
 *                @req [SWS_ComM_00552]
 */
FUNC(Std_ReturnType, COMM_CODE)
ComM_SetECUGroupClassification(
	CONST(ComM_InhibitionStatusType, CANTP_CONST) Status
)
{
	Std_ReturnType ret;
#if (STD_ON == COMM_DEV_ERROR_DETECT)
	ret = (Std_ReturnType)E_NOT_OK;

    if (COMM_UNINIT == ComM_Status)
    {
		/**
		 * @req [SWS_ComM_00612] If ComM is not initialized, all ComM module all API service other than
		 *  					  ComM_Init(), ComM_GetVersionInfo() and ComM_GetStatus(); shall:
		 *  					  - not execute their normal operation,
		 *  					  - and return E_NOT_OK, if it has a standard return type.
		 */
    	/**
		 * @req [SWS_ComM_00858] If ComM is not initialized and default error detection has been
		 * 						  switched on by ComMDevErrorDetect (see ECUC_ComM_00555), the ComM
		 * 						  module shall report a development error COMM_E_NOT_INITED (by using
		 * 						  the Det_ReportError service of the Default Error Tracer module) for
		 * 						  all ComM module API services other than ComM_Init() and
		 * 						  ComM_GetVersionInfo(), and ComM_GetStatus().
		 */
    	COMM_DET_REPORT(COMM_SID_SETECUGROUPCLASSIFICATION,COMM_E_NOT_INITED);
    }
    else
#endif /*#if (STD_ON == COMM_DEV_ERROR_DETECT) */
    {
    	ComM_GlobalInfo.EcuGroupClassification = Status;
    	ret = (Std_ReturnType)E_OK;
    }
	return ret;
}
#endif /*#if ((STD_ON==COMM_WAKEUP_INHIBITION_ENABLED) || (STD_ON==COMM_MODE_LIMITATION_ENABLED)) */


/**
 * @req [SWS_ComM_00799] Configuration of ComM_PreventWakeUp: Configurable with
 * 						 COMM_WAKEUP_INHIBITION_ENABLED
 */
#if (STD_ON == COMM_WAKEUP_INHIBITION_ENABLED)
/**
 * @sid           0x09
 * @brief         Changes the inhibition status COMM_NO_WAKEUP for the corresponding channel.
 * @param[in]     Status, FALSE: Wake up inhibition is switched off
 *                        TRUE: Wake up inhibition is switched on
 * @param[out]    /
 * @param[in/out] /
 * @return        Std_ReturnType
 * @retval		  E_OK: Successfully changed wake up status for the channel
 *                E_NOT_OK: Changed of wake up status for the channel failed
 *                @req [SWS_ComM_00156]
 */
FUNC(Std_ReturnType, COMM_CODE)
ComM_PreventWakeUp(
    CONST(NetworkHandleType, CANTP_CONST) Channel,
	CONST(boolean, CANTP_CONST) Status
)
{
    Std_ReturnType ret;
#if (STD_ON == COMM_DEV_ERROR_DETECT)
    ret = (Std_ReturnType)E_NOT_OK;

    if (COMM_UNINIT == ComM_Status)
    {
    	COMM_DET_REPORT(COMM_SID_PREVENTWAKEUP,COMM_E_NOT_INITED);
    }
    else if (COMM_NUMBER_OF_CHANNELS <= Channel)
    {
    	COMM_DET_REPORT(COMM_SID_PREVENTWAKEUP,COMM_E_WRONG_PARAMETERS);
    }
    else
#endif /*#if (STD_ON == COMM_DEV_ERROR_DETECT)*/
    {
        if ((boolean)TRUE == Status)
        {
            ComM_GlobalInfo.inhibitStatu[Channel] |= COMM_MASK_INHIBIT_WAKEUP;
        }
        else
        {
        	ComM_GlobalInfo.inhibitStatu[Channel] &= (ComM_InhibitionStatusType)(~COMM_MASK_INHIBIT_WAKEUP);
        }
        ret = (Std_ReturnType)E_OK;
    }
    return ret;
}
#endif /*#if (STD_ON == COMM_WAKEUP_INHIBITION_ENABLED)*/

/**
 * @req [SWS_ComM_00800] Configuration of ComM_LimitChannelToNoComMode: Configurable with
 * 						  ComMModeLimitationEnabled and COMM_RESET_AFTER_FORCING_NO_COMM
 */
/**
 * @req [SWS_ComM_00801] Configuration of ComM_LimitECUToNoComMode: Configurable with
 * 						  ComMModeLimitationEnabled and COMM_RESET_AFTER_FORCING_NO_COMM
 */
#if ((STD_ON == COMM_RESET_AFTER_FORCING_NO_COMM) && (STD_ON == COMM_MODE_LIMITATION_ENABLED))
/**
 * @sid           0x0b
 * @brief         Changes the inhibition status for the channel for changing from
 * 				  COMM_NO_COMMUNICATION to a higher Communication Mode.
 * @param[in]     Channel, Handle of network
 * @param[in]     Status, FALSE: Limit channel to COMM_NO_COMMUNICATION disabled
 *                TRUE: Limit channel to COMM_NO_COMMUNICATION enabled
 * @param[out]    /
 * @param[in/out] /
 * @return        Std_ReturnType
 * @retval		  E_OK: Successfully changed inhibition status for the channel
 *                E_NOT_OK: Changed of inhibition status for the channel failed
 *                @req [SWS_ComM_00163]
 */
FUNC(Std_ReturnType, COMM_CODE)
ComM_LimitChannelToNoComMode(
    CONST(NetworkHandleType, CANTP_CONST) Channel,
	CONST(boolean, CANTP_CONST) Status
)
{
    Std_ReturnType ret;
#if (STD_ON == COMM_DEV_ERROR_DETECT)
    ret = (Std_ReturnType)E_NOT_OK;

    if (COMM_UNINIT == ComM_Status)
    {
		/**
		 * @req [SWS_ComM_00612] If ComM is not initialized, all ComM module all API service other than
		 *  					  ComM_Init(), ComM_GetVersionInfo() and ComM_GetStatus(); shall:
		 *  					  - not execute their normal operation,
		 *  					  - and return E_NOT_OK, if it has a standard return type.
		 */
    	/**
		 * @req [SWS_ComM_00858] If ComM is not initialized and default error detection has been
		 * 						  switched on by ComMDevErrorDetect (see ECUC_ComM_00555), the ComM
		 * 						  module shall report a development error COMM_E_NOT_INITED (by using
		 * 						  the Det_ReportError service of the Default Error Tracer module) for
		 * 						  all ComM module API services other than ComM_Init() and
		 * 						  ComM_GetVersionInfo(), and ComM_GetStatus().
		 */
    	COMM_DET_REPORT(COMM_SID_LIMITCHANNELTONOCOMMODE,COMM_E_NOT_INITED);
    }
    else if (COMM_NUMBER_OF_CHANNELS <= Channel)
    {
    	COMM_DET_REPORT(COMM_SID_LIMITCHANNELTONOCOMMODE,COMM_E_WRONG_PARAMETERS);
    }
    else
#endif /*#if (STD_ON == COMM_DEV_ERROR_DETECT)*/
    {
        if ((boolean)TRUE == Status)
        {
            ComM_GlobalInfo.inhibitStatu[Channel] |= COMM_MASK_LIMIT_TO_NOCOM;
        }
        else
        {
        	ComM_GlobalInfo.inhibitStatu[Channel] &= (ComM_InhibitionStatusType)(~COMM_MASK_LIMIT_TO_NOCOM);
        }
        ret = (Std_ReturnType)E_OK;
    }
    return ret;
}

/**
 * @req [SWS_ComM_00488] It shall be possible to enable and disable the mode inhibition for
 * 						 each channel (channel state machine) independently. This functionality
 * 						 shall not be used by the ComM module itself.
 */
/**
 * @sid           0x0c
 * @brief         Changes the inhibition status for the ECU (=all channels) for changing from
 * 				  COMM_NO_COMMUNICATION to a higher Communication Mode.
 * @param[in]     Status, FALSE: Limit channel to COMM_NO_COMMUNICATION disabled
 *                TRUE: Limit channel to COMM_NO_COMMUNICATION enabled
 * @param[out]    /
 * @param[in/out] /
 * @return        Std_ReturnType
 * @retval		  E_OK: Successfully changed inhibition status for the ECU
 *                E_NOT_OK: Changed of inhibition status for the ECU failed
 *                @req [SWS_ComM_00124]
 */
FUNC(Std_ReturnType, COMM_CODE)
ComM_LimitECUToNoComMode(
	CONST(boolean, CANTP_CONST) Status
)
{
    Std_ReturnType ret;
#if (STD_ON == COMM_DEV_ERROR_DETECT)
    ret = (Std_ReturnType)E_NOT_OK;

    if (COMM_UNINIT == ComM_Status)
    {
		/**
		 * @req [SWS_ComM_00612] If ComM is not initialized, all ComM module all API service other than
		 *  					  ComM_Init(), ComM_GetVersionInfo() and ComM_GetStatus(); shall:
		 *  					  - not execute their normal operation,
		 *  					  - and return E_NOT_OK, if it has a standard return type.
		 */
    	/**
		 * @req [SWS_ComM_00858] If ComM is not initialized and default error detection has been
		 * 						  switched on by ComMDevErrorDetect (see ECUC_ComM_00555), the ComM
		 * 						  module shall report a development error COMM_E_NOT_INITED (by using
		 * 						  the Det_ReportError service of the Default Error Tracer module) for
		 * 						  all ComM module API services other than ComM_Init() and
		 * 						  ComM_GetVersionInfo(), and ComM_GetStatus().
		 */
    	COMM_DET_REPORT(COMM_SID_LIMITECUTONOCOMMODE,COMM_E_NOT_INITED);
    }
    else
#endif /*#if (STD_ON == COMM_DEV_ERROR_DETECT)*/
    {
        ComM_GlobalInfo.ComM_EcuToNoCom = Status;
        ret = (Std_ReturnType)E_OK;
    }
    return ret;
}
#endif /* ((STD_ON==COMM_RESET_AFTER_FORCING_NO_COMM) && (STD_ON==COMM_MODE_LIMITATION_ENABLED))*/

/**
 * @req [SWS_ComM_00143] It shall be possible to read out and reset the Inhibit counter for all
 * 						 rejected COMM_FULL_COMMUNICATION mode requests value by a ComM module
 * 						 API call.
 */
/**
 * @req [SWS_ComM_00802] Configuration of ComM_ReadInhibitCounter: Configurable with
 * 						  ComMModeLimitationEnabled .Function will only be available if
 * 						  ComMModeLimitationEnabled is enabled and ComMGlobalNvMBlockDescriptor
 * 						  is configured.
 */
/**
 * @req [SWS_ComM_00803] Configuration of ComM_ResetInhibitCounter: Configurable with
 * 						  ComMModeLimitationEnabled .Function will only be available if
 * 						  ComMModeLimitationEnabled is enabled and ComMGlobalNvMBlockDescriptor
 * 						  is configured.
 */

#if (STD_ON == COMM_MODE_LIMITATION_ENABLED)
#if defined (COMM_GLOBAL_NVM_BLOCK_DESCRIPTOR)
/**
 * @sid           0x0d
 * @brief         This function returns the amount of rejected COMM_FULL_COMMUNICATION user
 * @param[out]    CounterValue, Amount of rejected COMM_FULL_COMMUNICATION user requests.
 * @param[in/out] /
 * @return        Std_ReturnType
 * @retval		  E_OK: Successfully returned Inhibition Counter
 *                E_NOT_OK: Return of Inhibition Counter failed
 *                @req [SWS_ComM_00224]
 */
FUNC(Std_ReturnType, COMM_CODE)
ComM_ReadInhibitCounter(
    P2VAR(uint16, AUTOMATIC, COMM_APPL_DATA) CounterValue
)
{
	Std_ReturnType ret;

#if (STD_ON == COMM_DEV_ERROR_DETECT)
	ret = (Std_ReturnType)E_NOT_OK;

    if (COMM_UNINIT == ComM_Status)
    {
    	COMM_DET_REPORT(COMM_SID_READINHIBITCOUNTER,COMM_E_NOT_INITED);
    }
    else if (NULL_PTR == CounterValue)
    {
    	COMM_DET_REPORT(COMM_SID_READINHIBITCOUNTER,COMM_E_PARAM_POINTER);
    }
    else
#endif /*#if (STD_ON == COMM_DEV_ERROR_DETECT) */
    {
        *CounterValue = ComM_GlobalInfo.InhibitCounter;
        ret = (Std_ReturnType)E_OK;
    }
	return ret;
}


/**
 * @sid           0x0e
 * @brief         This function resets the Inhibited COMM_FULL_COMMUNICATION request Counter
 * @param[in]     /
 * @param[out]    /
 * @param[in/out] /
 * @return        Std_ReturnType
 * @retval		  E_OK: Successfully reset of Inhibit COMM_FULL_COMMUNICATION Counter
 *                E_NOT_OK: Reset of Inhibit COMM_FULL_COMMUNICATION Counter failed
 *                @req [SWS_ComM_00108]
 */
FUNC(Std_ReturnType, COMM_CODE)
ComM_ResetInhibitCounter(
    void
)
{
	Std_ReturnType ret;
#if (STD_ON == COMM_DEV_ERROR_DETECT)
	ret = (Std_ReturnType)E_NOT_OK;
    if (COMM_UNINIT == ComM_Status)
    {
    	COMM_DET_REPORT(COMM_SID_RESETINHIBITCOUNTER,COMM_E_NOT_INITED);
    }
    else
#endif /*#if (STD_ON == COMM_DEV_ERROR_DETECT) */
    {
        ComM_GlobalInfo.InhibitCounter = 0u;
        ret = (Std_ReturnType)E_OK;
    }
	return ret;
}
#endif /*#if defined (COMM_GLOBAL_NVM_BLOCK_DESCRIPTOR)*/
#endif /*#if (STD_ON == COMM_MODE_LIMITATION_ENABLED)*/

/**
 * @sid           0x08
 * @brief         Function to query the current Communication Mode.
 * @param[in]     User, Handle of the user who requests a mode
 * @param[out]    ComMode, Name of the requested mode
 * @param[in/out] /
 * @return        Std_ReturnType
 * @retval		  E_OK:Successfully returned Communication Mode from Bus State
 *                     Manager
 *                E_NOT_OK: Return of Communication Mode from Bus State Manager
 *                     failed
 *                @req [SWS_ComM_00083]
 */
FUNC(Std_ReturnType, COMM_CODE)
ComM_GetCurrentComMode(
	CONST(ComM_UserHandleType, CANTP_CONST) User,
    P2VAR(ComM_ModeType, AUTOMATIC, COMM_APPL_DATA) ComMode
)
{
	Std_ReturnType ret;
	uint8 index;
	NetworkHandleType ChIndex;
	ComM_ModeType mode = 0u;
	ComM_ModeType minMode = COMM_FULL_COMMUNICATION;
	ComM_BusType busType;

#if (STD_ON == COMM_DEV_ERROR_DETECT)
	ret = (Std_ReturnType)E_NOT_OK;

    if (COMM_UNINIT == ComM_Status)
    {
    	COMM_DET_REPORT(COMM_SID_GETCURRENTCOMMODE,COMM_E_NOT_INITED);
    }
    else if (NULL_PTR == ComMode)
    {
    	COMM_DET_REPORT(COMM_SID_GETCURRENTCOMMODE,COMM_E_PARAM_POINTER);
    }
    else if (COMM_NUMBER_OF_USERS <= User)
    {
    	COMM_DET_REPORT(COMM_SID_GETCURRENTCOMMODE,COMM_E_WRONG_PARAMETERS);
    }
    else
#endif /*#if (STD_ON == COMM_DEV_ERROR_DETECT) */
    {
        for(index = 0u;index < ComM_ConfigPtr->ComMUserCfgInfo[User].ChannelNum; index++)
        {
        	ChIndex = ComM_ConfigPtr->ComMUserCfgInfo[User].ChannelMap[index];
			/**
			 * @req [SWS_ComM_00176] If more than one channel is linked to one user request and
			 * 						 the modes of the channels are different, the function
			 * 						 ComM_GetCurrentComMode shall return the lowest mode
			 */
			/**
			 * @req [SWS_ComM_00798] Configuration of ComM_GetCurrentComMode: Relationship between
			 * 						 users and channels. A user is statically mapped to one or more
			 * 						 channels.
			 */
			/**
			 * @req [SWS_ComM_00963] The Communication Manager module shall use
			 * 						 <BusSm>_GetCurrentComMode() from the State Manager to query the
			 * 						 current communication mode if necessary.
			 */
			/**
			 * @req [SWS_ComM_00084] The ComM module shall propagate a call of ComM_GetCurrentComMode()
			 * 						 to the Bus State Manager module(s) for the channel(s) the user are
			 * 						 configured to (see also SWS_ComM_00176 and SWS_ComM_00798)
			 */
			busType = ComM_ConfigPtr->ComMChannelCfgInfo[ChIndex].ComMBusType;

			if (NULL_PTR != ComM_SMGetComModeTable[busType])
			{
				if(((Std_ReturnType)E_OK == ComM_SMGetComModeTable[busType](index, &mode))&&
						(mode <= minMode))
				{
					minMode = mode;
				}
			}
		}
		*ComMode = minMode;
		ret = (Std_ReturnType)E_OK;
    }
	return ret;
}

/**
 * @sid           0x06
 * @brief         Function to query the maximum allowed Communication Mode of the corresponding user.
 * @param[in]     User, Handle of the user who requests a mode
 * @param[out]    ComMode, Name of the requested mode
 * @param[in/out] /
 * @return        Std_ReturnType
 * @retval		  E_OK: Successfully returned maximum allowed Communication Mode
 *                E_NOT_OK: Return of maximum allowed Communication Mode failed
 *                @req [SWS_ComM_00085]
 */
FUNC(Std_ReturnType, COMM_CODE)
ComM_GetMaxComMode(
    CONST(ComM_UserHandleType, CANTP_CONST) User,
    P2VAR(ComM_ModeType, AUTOMATIC, COMM_APPL_DATA) ComMode
)
{
	Std_ReturnType ret;
#if (STD_ON == COMM_MODE_LIMITATION_ENABLED)
	uint8 index;
	NetworkHandleType ChIndex;
#endif

#if (STD_ON == COMM_DEV_ERROR_DETECT)
	ret = (Std_ReturnType)E_NOT_OK;

    if (COMM_UNINIT == ComM_Status)
    {
    	COMM_DET_REPORT(COMM_SID_GETMAXCOMMODE,COMM_E_NOT_INITED);
    }
    else if (NULL_PTR == ComMode)
    {
    	COMM_DET_REPORT(COMM_SID_GETMAXCOMMODE,COMM_E_PARAM_POINTER);
    }
    else if (COMM_NUMBER_OF_USERS <= User)
    {
    	COMM_DET_REPORT(COMM_SID_GETMAXCOMMODE,COMM_E_WRONG_PARAMETERS);
    }
    else
#endif /*#if (STD_ON == COMM_DEV_ERROR_DETECT) */
    {
#if (STD_ON == COMM_MODE_LIMITATION_ENABLED)

        *ComMode = COMM_FULL_COMMUNICATION;

			/**
			 * @req [SWS_ComM_00374] If more than one channel is linked to one user request and
			 * 						 the modes of the channels are different, the function
			 * 						 ComM_GetCurrentComMode shall return the lowest mode
			 */
			/**
			 * @req [SWS_ComM_00796] Configuration of ComM_GetMaxComMode: Relationship between users
			 * 						 and channels. A user is statically mapped to one or more channels.
			 */	
			
            for(index = 0u;(index < ComM_ConfigPtr->ComMUserCfgInfo[User].ChannelNum)\
            &&(*ComMode != COMM_NO_COMMUNICATION); index++)
            {
            	ChIndex = ComM_ConfigPtr->ComMUserCfgInfo[User].ChannelMap[index];
				/**
				 * @req [SWS_ComM_00218] A communication request (COMM_FULL_COMMUNICATION) by a
				 * 						 user shall be inhibited if the ComM Inhibition status is
				 * 						 equal to ComMNoWakeup=(boolean)TRUE for the corresponding
				 * 						 channel and the current state of the channel is
				 * 						 COMM_NO_COMMUNICATIONor COMM_SILENT_COMMUNICATION
				 */
				/**
				 * @req [SWS_ComM_00219] The inhibition shall not get active if the current
				 * 						 communication state is COMM_FULL_COMMUNICATION .
				 */
                switch(ComM_ChannelInfo[ChIndex].ComMMode)
                {
					/**
					 * @req [SWS_ComM_00302] Bus wake up Inhibition shall be performed by ignoring
					 * 						 user requests.
					 */
                    case COMM_NO_COMMUNICATION:
						#if (STD_ON == COMM_WAKEUP_INHIBITION_ENABLED)
						if((ComM_GlobalInfo.EcuGroupClassification & \
								ComM_GlobalInfo.inhibitStatu[ChIndex]) == COMM_MASK_INHIBIT_WAKEUP)
						{
							 *ComMode = COMM_NO_COMMUNICATION;
						}
						else
						{
							/*No Handle*/
						}
						#endif/* (STD_ON == COMM_WAKEUP_INHIBITION_ENABLED)*/
                        break;
                    case COMM_SILENT_COMMUNICATION:
						#if (STD_ON == COMM_MODE_LIMITATION_ENABLED)
                    	if((*ComMode == COMM_FULL_COMMUNICATION) &&
						   ((((ComM_GlobalInfo.EcuGroupClassification & COMM_MASK_LIMIT_TO_NOCOM) \
						   == COMM_MASK_LIMIT_TO_NOCOM)) && (((boolean)TRUE == \
						   ComM_GlobalInfo.ComM_EcuToNoCom) || ((ComM_GlobalInfo.inhibitStatu[ChIndex] \
						   & COMM_MASK_LIMIT_TO_NOCOM) == COMM_MASK_LIMIT_TO_NOCOM))))
                    		{
                    			 *ComMode = COMM_SILENT_COMMUNICATION;
                    		}
                    		else
                    		{
                    			/*No Handle*/
                    		}
						#endif /*#if (STD_ON == COMM_MODE_LIMITATION_ENABLED)*/
                        break;
                    default:
                        break;
                }
            }
#else
        *ComMode = COMM_FULL_COMMUNICATION;
#endif /*#if (STD_ON == COMM_MODE_LIMITATION_ENABLED)*/
        ret = (Std_ReturnType)E_OK;
    }
	return ret;
}

/**
 * @sid           0x07
 * @brief         Function to query the currently requested Communication Mode of the
 * 				  corresponding user.
 * @param[in]     User, Handle of the user who requests a mode
 * @param[out]    ComMode, Name of the requested mode
 * @param[in/out] /
 * @return        Std_ReturnType
 * @retval		  E_OK: Successfully returned requested Communication Mode
 *                E_NOT_OK: Return of requested Communication Mode failed
 *                @req [SWS_ComM_00079]
 */
FUNC(Std_ReturnType, COMM_CODE)
ComM_GetRequestedComMode(
	CONST(ComM_UserHandleType, CANTP_CONST) User,
    P2VAR(ComM_ModeType, AUTOMATIC, COMM_APPL_DATA) ComMode
)
{
	Std_ReturnType ret;
#if (STD_ON == COMM_DEV_ERROR_DETECT)
	ret = (Std_ReturnType)E_NOT_OK;

    if (COMM_UNINIT == ComM_Status)
    {
    	COMM_DET_REPORT(COMM_SID_GETREQUESTEDCOMMODE,COMM_E_NOT_INITED);
    }
    else if (NULL_PTR == ComMode)
    {
    	COMM_DET_REPORT(COMM_SID_GETREQUESTEDCOMMODE,COMM_E_PARAM_POINTER);
    }
    else if (COMM_NUMBER_OF_USERS <= User)
    {
    	COMM_DET_REPORT(COMM_SID_GETREQUESTEDCOMMODE,COMM_E_WRONG_PARAMETERS);
    }
    else
#endif /*#if (STD_ON == COMM_DEV_ERROR_DETECT) */
    {
    	*ComMode = ComM_UserInfo[User].RequestMode;
    	ret = (Std_ReturnType)E_OK;
    }
	return ret;
}
#define COMM_STOP_SEC_CODE
#include "ComM_MemMap.h"


#ifdef __cplusplus
}
#endif
/** @} */
