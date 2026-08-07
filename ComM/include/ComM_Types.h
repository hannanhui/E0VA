/**
 * @file        ComM_Types.h
 * @brief       AUTOSAR ComM - ComM driver header file.
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

#ifndef COMM_TYPES_H
#define COMM_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif

/* PRQA S 0292, 0288, 1503, 1505, 0857, 0791, 0828, 0647 EOF #
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
#include "ComStack_Types.h"
#include "ComM_Cfg.h"

/*====================================================================================================*
 *                                  HEADER FILE VERSION INFORMATION
 *====================================================================================================*/

#define COMM_TYPES_VENDOR_ID                   0U
#define COMM_TYPES_MODULE_ID                   12u
#define COMM_TYPES_AR_RELEASE_MAJOR_VERSION    4u
#define COMM_TYPES_AR_RELEASE_MINOR_VERSION    2u
#define COMM_TYPES_AR_RELEASE_REVISION_VERSION 2u
#define COMM_TYPES_SW_MAJOR_VERSION            1u
#define COMM_TYPES_SW_MINOR_VERSION            2u
#define COMM_TYPES_SW_PATCH_VERSION            0U

/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/
#ifndef DISABLE_INTERMOD_VERSION_CHECK
/* Check if current file and ComStack_Types.h header file are of the same Autosar version  */
#if(\
      (COMM_TYPES_AR_RELEASE_MAJOR_VERSION != COMTYPE_AR_RELEASE_MAJOR_VERSION) || \
      (COMM_TYPES_AR_RELEASE_MINOR_VERSION != COMTYPE_AR_RELEASE_MINOR_VERSION) \
      )
#error "AutoSar Version Number of ComM_Types.h and ComStack_Types.h are different "
#endif
#endif

/* Check if current file and ComM_Cfg.h header file are of the same vendor  */
#if(COMM_TYPES_VENDOR_ID != COMM_CFG_VENDOR_ID )
#error "ComM_Types.h and ComM_Cfg.h have different vendor id"
#endif

/* Check if current file and ComM.h header file are of the same Autosar version  */
#if(\
      (COMM_TYPES_AR_RELEASE_MAJOR_VERSION != COMM_CFG_AR_RELEASE_MAJOR_VERSION) || \
      (COMM_TYPES_AR_RELEASE_MINOR_VERSION != COMM_CFG_AR_RELEASE_MINOR_VERSION) || \
      (COMM_TYPES_AR_RELEASE_REVISION_VERSION != COMM_CFG_AR_RELEASE_REVISION_VERSION) \
      )
#error "AutoSar Version Number of ComM_Types.h and ComM_Cfg.h are different "
#endif

/* Check if current file and ComM.h header file are of the same software version  */
#if(\
      (COMM_TYPES_SW_MAJOR_VERSION != COMM_CFG_SW_MAJOR_VERSION) || \
      (COMM_TYPES_SW_MINOR_VERSION != COMM_CFG_SW_MINOR_VERSION) ||\
	  (COMM_TYPES_SW_PATCH_VERSION != COMM_CFG_SW_PATCH_VERSION)\
      )
#error "Software Version Number of ComM_Types.h and ComM_Cfg.h are different "
#endif

/*====================================================================================================*
 *                                             CONSTANTS
 *====================================================================================================*/


/*====================================================================================================*
 *                                         DEFINES AND MACROS
 *====================================================================================================*/
/*@ req [SWS_ComM_00649]*/
/**
 * @brief 	Function call has been successfully but mode can not be granted because of mode inhibition.
 */
#define COMM_E_MODE_LIMITATION 0x02
/*@ req [SWS_ComM_00234]*/
#if (COMM_DEV_ERROR_DETECT == STD_ON)
#define  COMM_E_NOT_INITED                           (uint8)(0x01U)
#define  COMM_E_WRONG_PARAMETERS                     (uint8)(0x02U)
#define  COMM_E_PARAM_POINTER                        (uint8)(0x03U)
#define  COMM_E_INIT_FAILED                          (uint8)(0x04U)
#endif/* (COMM_DEV_ERROR_DETECT == STD_ON) */

#define COMM_INSTANCE_ID    						 (uint8)(0x00U)

#define COMM_SID_INIT                        		 (uint8)(0x01U)
#define COMM_SID_DEINIT                      		 (uint8)(0x02U)
#define COMM_SID_GETSTATE                   		 (uint8)(0x34U)
#define COMM_SID_GETSTATUS                 		     (uint8)(0x03U)
#define COMM_SID_GETINHIBITIONSTATUS           		 (uint8)(0x04U)
#define COMM_SID_REQUESTCOMMODE            		     (uint8)(0x05U)
#define COMM_SID_GETMAXCOMMODE                		 (uint8)(0x06U)
#define COMM_SID_GETREQUESTEDCOMMODE          		 (uint8)(0x07U)
#define COMM_SID_GETCURRENTCOMMODE        		     (uint8)(0x08U)
#define COMM_SID_PREVENTWAKEUP              	     (uint8)(0x09U)
#define COMM_SID_LIMITCHANNELTONOCOMMODE      		 (uint8)(0x0bU)
#define COMM_SID_LIMITECUTONOCOMMODE         		 (uint8)(0x0cU)
#define COMM_SID_READINHIBITCOUNTER         	     (uint8)(0x0dU)
#define COMM_SID_RESETINHIBITCOUNTER        	     (uint8)(0x0eU)
#define COMM_SID_SETECUGROUPCLASSIFICATION    		 (uint8)(0x0fU)
#define COMM_SID_GETVERSIONINFO              		 (uint8)(0x10U)
#define COMM_SID_NM_NETWORKSTARTINDICATION  	     (uint8)(0x15U)
#define COMM_SID_NM_NETWORKMODE              		 (uint8)(0x18U)
#define COMM_SID_NM_PREPAREBUSSLEEPMODE     	     (uint8)(0x19U)
#define COMM_SID_NM_BUSSLEEPMODE           		     (uint8)(0x1aU)
#define COMM_SID_NM_RESTARTINDICATION      		     (uint8)(0x1bU)
#define COMM_SID_DCM_ACTIVEDIAGNOSTIC     		     (uint8)(0x1fU)
#define COMM_SID_DCM_INACTIVEDIAGNOSTIC  		     (uint8)(0x20U)
#define COMM_SID_COMMUNICATIONALLOWED      		     (uint8)(0x35U)
#define COMM_SID_ECUM_WAKEUPINDICATION   		     (uint8)(0x2aU)
#define COMM_SID_BUSSM_MODEINDICATION     		     (uint8)(0x33U)
#define COMM_SID_MAINFUNCATION            		     (uint8)(0x60U)

#if (STD_ON == COMM_DEV_ERROR_DETECT)
#define COMM_DET_REPORT(ApiId,ErrorId)     (\
                         (void)Det_ReportError(\
                                COMM_MODULE_ID,\
                                COMM_INSTANCE_ID,\
                                            (ApiId),\
                                            (ErrorId)))
#else
#define COMM_DET_REPORT(ApiId,ErrorId)
#endif/* STD_ON == CANNM_DEV_ERROR_DETECT */
/*====================================================================================================*
 *                                               ENUMS
 *====================================================================================================*/
/*@ req [SWS_ComM_00668]*/
/**
 * @brief 	Initialization status of ComM
 */
typedef uint8 ComM_InitStatusType;

#define COMM_UNINIT  0x00u
#define COMM_INIT    0x01u

/*@ req [SWS_ComM_00673]*/
/**
 * @brief 	Initialization status of ComM
 */
typedef enum
{
	COMM_PNC_REQUESTED,
	COMM_PNC_READY_SLEEP,
	COMM_PNC_PREPARE_SLEEP,
	COMM_PNC_NO_COMMUNICATION
}ComM_PncModeType;


/**
 * @brief 	Defines the bus type of the channel.
 */
typedef enum
{
    COMM_BUS_TYPE_CAN = 0u,
    COMM_BUS_TYPE_CDD,
    COMM_BUS_TYPE_ETH,
    COMM_BUS_TYPE_FR,
    COMM_BUS_TYPE_INTERNAL,
    COMM_BUS_TYPE_LIN
} ComM_BusType;

/**
 * @brief 	Identifies the Partial Network Gateway behaviour of a ComMChannel.
 */
typedef enum
{
    COMM_GATEWAY_TYPE_ACTIVE = 0u,
    COMM_GATEWAY_TYPE_PASSIVE
} ComM_PncGatewayType;


/**
 * @brief 	Defines the functionality of the networkmanagement.Shall be harmonized with NM configuration.
 */
typedef enum
{
    COMM_FULL = 0u,  /**< @brief AUTOSAR NM available (default).*/
    COMM_LIGHT,      /**< @brief No AUTOSAR NM available but functionality to shut down a channel.*/
    COMM_NONE,       /**< @brief No NM available.*/
    COMM_PASSIVE     /**< @brief AUTOSAR NM running in passive mode available.*/
} ComM_NmVariantType;

/*====================================================================================================*
 *                                   STRUCTURES AND OTHER TYPEDEFS
 *====================================================================================================*/
/*@ req [SWS_ComM_00867]*/
/*@ req [SWS_ComM_00672]*/
/*@ req [SWS_ComM_00879]*/
/**
 * @brief 	Current mode of the Communication Manager
 * @details  (main state of the state machine)
 */
typedef uint8  ComM_ModeType;

#define COMM_NO_COMMUNICATION           (ComM_ModeType)0u
#define COMM_SILENT_COMMUNICATION       (ComM_ModeType)1u
#define COMM_FULL_COMMUNICATION         (ComM_ModeType)2u

/*@ req [SWS_ComM_00674]*/
/*@ req [SWS_ComM_00880]*/
/*@ req [SWS_ComM_00881]*/
/**
 * @brief 	State and sub-state of ComM state machine
 */
typedef uint8 ComM_StateType;

#define COMM_NO_COM_NO_PENDING_REQUEST		(ComM_StateType)0u
#define COMM_NO_COM_REQUEST_PENDING			(ComM_StateType)1u
#define COMM_SILENT_COM						(ComM_StateType)2u
#define COMM_FULL_COM_NETWORK_REQUESTED		(ComM_StateType)3u
#define COMM_FULL_COM_READY_SLEEP			(ComM_StateType)4u

/*@ req [SWS_ComM_00670]*/
/**
 * @brief 	Handle to identify a user.
 */
typedef uint8 ComM_UserHandleType;


#define COMM_INVALID_UINT8            	(uint8)0xFFu
#define COMM_STATE_COUT               	(uint8)0x5u
#define COMM_CONDITION_COUT           	(uint8)0x3u
#define COMM_BUS_TYPE_COUT           	(uint8)0x6u
#define COMM_MODE_COUT               	(uint8)0x3u

/*@ req [SWS_ComM_00669]*/
/**
* @brief 	Defines whether a mode inhibition is active or not.
* @details 	Bit 0 (LSB): Wake Up inhibition active
* 			Bit 1: Limit to COMM_NO_COMMUNICATION mode
*/
typedef uint8 ComM_InhibitionStatusType;

#define COMM_MASK_INHIBIT_WAKEUP    	(ComM_InhibitionStatusType)0x01u
#define COMM_MASK_LIMIT_TO_NOCOM    	(ComM_InhibitionStatusType)0x02u

/**
 * @brief 	Defines whether a mode inhibition is active or not.
 * @details 	Bit 0 (LSB): Wake Up inhibition active
 * 			Bit 1: Limit to COMM_NO_COMMUNICATION mode
 */
#define COMM_MAX_REJECT_COUNTER     0xFFFFu
#define COMM_MAX_NVM_TIMEOUT        0xFFFFu


/**
 * @brief 	 Bus mode indication event
 */
#define COMM_EVENT_BUS_REQUEST      0x1000u
#define COMM_EVENT_BUS_OK           0x2000u
#define COMM_EVENT_BUS_FAIL         0x4000u
#define COMM_EVENT_BUS_IND          0x6000u

/**
 * @brief 	This container contains the configuration (parameters) of the bus channel(s)
 * @details	The channel parameters shall be harmonized within the whole communication stack.
 */
typedef struct
{
	/**< @brief Identifies the bus type of the channel. */
	CONST(ComM_BusType, COMM_CONST) ComMBusType;

    /**< @brief COMM_BUS_TYPE_CDD == ComMBusType, this menber valid*/
    P2FUNC(Std_ReturnType,COMM_APPL_DATA,ComMCDDBusPrefix) \
    		(NetworkHandleType network, ComM_ModeType ComM_Mode) ;

    /**< @brief Shall be stored none volatile (value must be kept during a reset).*/
    CONST(boolean, COMM_CONST) ComMFullCommRequestNotificationEnabled;

    /**< @brief Specifies the period in seconds that the MainFunction has to be triggered with.4~100ms*/
    CONST(uint8, COMM_CONST) ComMMainFunctionPeriod;

#if (STD_ON == COMM_MODE_LIMITATION_ENABLED)
    /**< @brief ECU is not allowed to change state of the channel to
     * "Silent Communication" or "Full Communication".*/
    CONST(boolean, COMM_CONST) ComMNoCom;
#endif /*#if (STD_ON == COMM_MODE_LIMITATION_ENABLED)*/

    /**< @brief true, a valid Nvm block reference must be given in the (existing, i.e. multiplicity 1)
    ComMGlobalNvmBlockDescriptor pointing to a sufficiently big Nvm block*/
    CONST(boolean, COMM_CONST) ComMNoWakeUpInhibitionNvmStorage;

#if (STD_ON == COMM_WAKEUP_INHIBITION_ENABLED)
    /**< @brief Defines if an ECU is not allowed to wake-up the channel.*/
    CONST(boolean, COMM_CONST) ComMNoWakeup;
#endif /*#if (STD_ON == COMM_WAKEUP_INHIBITION_ENABLED)*/

#if (STD_ON == COMM_PNC_SUPPORT)
#if (STD_ON == COMM_PNC_GATEWAY_ENABLED)
    /**< @brief Identifies the Partial Network Gateway behaviour of a ComMChannel.*/
    CONST(ComM_PncGatewayType, COMM_CONST) ComMPncGateway;
#endif/*#if (STD_ON == COMM_PNC_GATEWAY_ENABLED)*/
#endif/*#if (STD_ON == COMM_PNC_SUPPORT)*/

    /**< @brief Defines the functionality of the networkmanagement.
     * Shall be harmonized with NM configuration.*/
    CONST(ComM_NmVariantType, COMM_CONST) ComMNmVariant;

    /**< @brief Defines the timeout (in seconds) after state "ready sleep" is left.*/
    CONST(uint16, COMM_CONST) ComMNmLightTimeout;/*Multiplicity 0...1*/

#if (STD_ON == COMM_PNC_SUPPORT)
    CONST(boolean, COMM_CONST) ComMPncNmRequest;
#endif
}ComM_ChannelCfgType;


/**
 * @brief
 * @details	This container contains a list of identifiers that are needed to refer to
 	 	 	a user in the system which is designated to request Communication modes.
 */
typedef struct
{
    /**< @brief Number of channels in the user */
	CONST(uint8, AUTOMATIC)  ChannelNum;
	P2CONST(uint8, AUTOMATIC, COMM_CONST) ChannelMap;
    CONST(ComM_UserHandleType, AUTOMATIC) ComMUserIdentifier;
    CONSTP2CONST(ComM_UserHandleType, AUTOMATIC, COMM_CONST) ComMUserEcucPartitionRef;
} ComM_UserCfgType;

/*@ req [SWS_ComM_00162]*/
/**
 * @brief 	contains the implementation-specific post build configuration structure.
 * @details
 */
typedef struct
{
    CONST(boolean, TYPEDEF) ComMPncEnabled;

    P2CONST(ComM_ChannelCfgType, AUTOMATIC, COMM_CONST) ComMChannelCfgInfo;

#if (STD_ON == COMM_PNC_SUPPORT)
    P2CONST(ComM_PncCfgType, AUTOMATIC, COMM_CONST) ComMPncCfgInfo;
#endif

    P2CONST(ComM_UserCfgType, AUTOMATIC, COMM_CONST) ComMUserCfgInfo;
} ComM_ConfigType;

/*====================================================================================================*
 *                                    GLOBAL VARIABLE DECLARATIONS
 *====================================================================================================*/


/*====================================================================================================*
 *                                        FUNCTION PROTOTYPES
 *====================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif/* COMM_TYPES_H */
/** @} */
