/**
 * @file        BswM_AvaliableActionsType.h
 * @brief       AUTOSAR BSWM_AVALIABLEACTIONSTYPE - BswM_AvaliableActionsType driver header file.
 * @details     BswM_AvaliableActionsType driver header file, containing the Autosar API specification
 *              and other variables and functions that are exported by the BswM_AvaliableActionsType
 *              driver.
 * @version     1.2.0
 *
 * @addtogroup  BSWM_AVALIABLEACTIONSTYPE
 * @{
 */
/*====================================================================================================*
 * AngHui AUTOSAR BSW.
 *
 * Copyright(C) 2026 GuoKeAngHui Inc.
 *
 * All rights reserved.
 *
 * This file is part of AngHui AUTOSAR BSW, contains proprietary information.
 * Passing on and copying of this document, and communication of its contents
 * is not permitted without prior written authorization.
 *====================================================================================================*/
#ifndef BSWM_AVAILABLEACTIONSTYPE_H
#define BSWM_AVAILABLEACTIONSTYPE_H

#if defined(__cplusplus)
extern "C" 
{
#endif /* defined(__cplusplus) */

/*====================================================================================================*
 *                                           INCLUDE FILES
 *====================================================================================================*/

#include "BswM_Cfg.h"

#if ((STD_ON == BSWM_CANSM_ENABLED) || (STD_ON == BSWM_CANSM_ICOM_ENABLED))
#include "CanSM.h"
#endif /* ((STD_ON == BSWM_CANSM_ENABLED) || (STD_ON == BSWM_CANSM_ICOM_ENABLED)) */

#if (STD_ON == BSWM_COMM_ENABLED)
#include "ComM.h"
#endif /* (STD_ON == BSWM_COMM_ENABLED) */

#if (STD_ON == BSWM_COM_ENABLED)
#include "Com.h"
/*#include "Com_BswM.h"*/
#endif /* (STD_ON == BSWM_COM_ENABLED) */

#if (STD_ON == BSWM_DCM_ENABLED)
#include "Dcm.h"
#endif /* (STD_ON == BSWM_DCM_ENABLED) */

#if (STD_ON == BSWM_ECUM_ENABLED)
#include "EcuM.h"
#endif /* (STD_ON == BSWM_ECUM_ENABLED) */

#if (STD_ON == BSWM_ETHSM_ENABLED)
#include "EthSM.h"
#endif /* (STD_ON == BSWM_ETHSM_ENABLED) */

#if (STD_ON == BSWM_FRSM_ENABLED)
#include "FrSM.h"
#endif /* (STD_ON == BSWM_FRSM_ENABLED) */

#if (STD_ON == BSWM_J1939DCM_ENABLED)
#include "J1939Dcm.h"
#endif /* (STD_ON == BSWM_J1939DCM_ENABLED) */

#if (STD_ON == BSWM_J1939NM_ENABLED)
#include "J1939Nm.h"
#endif /* (STD_ON == BSWM_J1939NM_ENABLED) */

#if (STD_ON == BSWM_J1939RM_ENABLED)
#include "J1939Rm.h"
#endif /* (STD_ON == BSWM_J1939RM_ENABLED) */

#if (STD_ON == BSWM_LINSM_ENABLED)
#include "LinSM.h"
#endif /* (STD_ON == BSWM_LINSM_ENABLED) */

#if (STD_ON == BSWM_NVM_ENABLED)
#include "NvM.h"
#endif /* (STD_ON == BSWM_NVM_ENABLED) */

#if (STD_ON == BSWM_OS_ENABLED)
#include "Ecuc.h"
#include "Os.h"
#endif /* (STD_ON == BSWM_OS_ENABLED) */

#if (STD_ON == BSWM_PDUR_ENABLED)
#include "PduR.h"
#endif /* (STD_ON == BSWM_PDUR_ENABLED) */

#if (STD_ON == BSWM_SCHM_ENABLED)
#include "Rte.h"
#include "SchM.h"
#endif /* (STD_ON == BSWM_SCHM_ENABLED) */

#if (STD_ON == BSWM_SD_ENABLED)
#include "Sd.h"
#endif /* (STD_ON == BSWM_SD_ENABLED) */

/*====================================================================================================*
 *                                  HEADER FILE VERSION INFORMATION
 *====================================================================================================*/

#define BSWM_AVAILABLEACTIONSTYPE_VENDOR_ID                    0U
#define BSWM_AVAILABLEACTIONSTYPE_AR_RELEASE_MAJOR_VERSION     4U
#define BSWM_AVAILABLEACTIONSTYPE_AR_RELEASE_MINOR_VERSION     2U
#define BSWM_AVAILABLEACTIONSTYPE_AR_RELEASE_REVISION_VERSION  2U
#define BSWM_AVAILABLEACTIONSTYPE_SW_MAJOR_VERSION             1U
#define BSWM_AVAILABLEACTIONSTYPE_SW_MINOR_VERSION             2U
#define BSWM_AVAILABLEACTIONSTYPE_SW_PATCH_VERSION             0U

/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/

/* Check if current file and BswM_Cfg header file are of the same vendor */
#if(BSWM_AVAILABLEACTIONSTYPE_VENDOR_ID != BSWM_CFG_VENDOR_ID )
#error "BswM_AvaliableActionsType.h and BswM_Cfg.h have different vendor id"
#endif
/* Check if current file and BswM_Cfg header file are of the same Autosar version */
#if(\
		(BSWM_AVAILABLEACTIONSTYPE_AR_RELEASE_MAJOR_VERSION != \
				                            BSWM_CFG_AR_RELEASE_MAJOR_VERSION) || \
		(BSWM_AVAILABLEACTIONSTYPE_AR_RELEASE_MINOR_VERSION != \
				                            BSWM_CFG_AR_RELEASE_MINOR_VERSION) || \
		(BSWM_AVAILABLEACTIONSTYPE_AR_RELEASE_REVISION_VERSION != \
				                            BSWM_CFG_AR_RELEASE_REVISION_VERSION) \
	)
#error "AutoSar Version Number of BswM_AvaliableActionsType.h and BswM_Cfg.h are different "
#endif
/* Check if current file and BswM_Cfg header file are of the same software version */
#if(\
		(BSWM_AVAILABLEACTIONSTYPE_SW_MAJOR_VERSION != BSWM_CFG_SW_MAJOR_VERSION) || \
		(BSWM_AVAILABLEACTIONSTYPE_SW_MINOR_VERSION != BSWM_CFG_SW_MINOR_VERSION) || \
		(BSWM_AVAILABLEACTIONSTYPE_SW_PATCH_VERSION != BSWM_CFG_SW_PATCH_VERSION) \
	)
#error "Software Version Number of BswM_AvaliableActionsType.h and BswM_Cfg.h are different "
#endif

#ifndef DISABLE_INTERMOD_VERSION_CHECK

#if ((STD_ON == BSWM_CANSM_ENABLED) || (STD_ON == BSWM_CANSM_ICOM_ENABLED))
/* Check if current file and CanSM header file are of the same Autosar version */
#if(\
		(BSWM_AVAILABLEACTIONSTYPE_AR_RELEASE_MAJOR_VERSION != CANSM_AR_RELEASE_MAJOR_VERSION) || \
		(BSWM_AVAILABLEACTIONSTYPE_AR_RELEASE_MINOR_VERSION != CANSM_AR_RELEASE_MINOR_VERSION) \
	)
/*#error "AutoSar Version Number of BswM_AvaliableActionsType.h and CanSM.h are different "*/
#endif
#endif /* ((STD_ON == BSWM_CANSM_ENABLED) || (STD_ON == BSWM_CANSM_ICOM_ENABLED)) */


#if (STD_ON == BSWM_COMM_ENABLED)
/* Check if current file and ComM header file are of the same Autosar version */
#if(\
		(BSWM_AVAILABLEACTIONSTYPE_AR_RELEASE_MAJOR_VERSION != COMM_AR_RELEASE_MAJOR_VERSION) || \
		(BSWM_AVAILABLEACTIONSTYPE_AR_RELEASE_MINOR_VERSION != COMM_AR_RELEASE_MINOR_VERSION) \
	)
/*#error "AutoSar Version Number of BswM_AvaliableActionsType.h and ComM.h are different "*/
#endif
#endif /* (STD_ON == BSWM_COMM_ENABLED) */

#if (STD_ON == BSWM_COM_ENABLED)
/* Check if current file and Com header file are of the same Autosar version */
#if(\
		(BSWM_AVAILABLEACTIONSTYPE_AR_RELEASE_MAJOR_VERSION != COM_AR_RELEASE_MAJOR_VERSION) || \
		(BSWM_AVAILABLEACTIONSTYPE_AR_RELEASE_MINOR_VERSION != COM_AR_RELEASE_MINOR_VERSION) \
	)
/*#error "AutoSar Version Number of BswM_AvaliableActionsType.h and Com.h are different "*/
#endif

/* Check if current file and Com_BswM header file are of the same Autosar version */
#if(\
		(BSWM_AVAILABLEACTIONSTYPE_AR_RELEASE_MAJOR_VERSION != COM_BSWM_AR_RELEASE_MAJOR_VERSION) || \
		(BSWM_AVAILABLEACTIONSTYPE_AR_RELEASE_MINOR_VERSION != COM_BSWM_AR_RELEASE_MINOR_VERSION) \
	)
/*#error "AutoSar Version Number of BswM_AvaliableActionsType.h and Com_BswM.h are different "*/
#endif

#endif /* (STD_ON == BSWM_COM_ENABLED) */

#if (STD_ON == BSWM_DCM_ENABLED)
/* Check if current file and Dcm header file are of the same Autosar version */
#if(\
		(BSWM_AVAILABLEACTIONSTYPE_AR_RELEASE_MAJOR_VERSION != DCM_AR_RELEASE_MAJOR_VERSION) || \
		(BSWM_AVAILABLEACTIONSTYPE_AR_RELEASE_MINOR_VERSION != DCM_AR_RELEASE_MINOR_VERSION) \
	)
/*#error "AutoSar Version Number of BswM_AvaliableActionsType.h and Dcm.h are different "*/
#endif
#endif /* (STD_ON == BSWM_DCM_ENABLED) */

#if (STD_ON == BSWM_ECUM_ENABLED)
/* Check if current file and EcuM header file are of the same Autosar version */
#if(\
		(BSWM_AVAILABLEACTIONSTYPE_AR_RELEASE_MAJOR_VERSION != ECUM_AR_RELEASE_MAJOR_VERSION) || \
		(BSWM_AVAILABLEACTIONSTYPE_AR_RELEASE_MINOR_VERSION != ECUM_AR_RELEASE_MINOR_VERSION) \
	)
#error "AutoSar Version Number of BswM_AvaliableActionsType.h and EcuM.h are different "
#endif
#endif /* (STD_ON == BSWM_ECUM_ENABLED) */

#if (STD_ON == BSWM_ETHSM_ENABLED)
/* Check if current file and EthSM header file are of the same Autosar version */
#if(\
		(BSWM_AVAILABLEACTIONSTYPE_AR_RELEASE_MAJOR_VERSION != ETHSM_AR_RELEASE_MAJOR_VERSION) || \
		(BSWM_AVAILABLEACTIONSTYPE_AR_RELEASE_MINOR_VERSION != ETHSM_AR_RELEASE_MINOR_VERSION) \
	)
/*#error "AutoSar Version Number of BswM_AvaliableActionsType.h and EthSM.h are different "*/
#endif
#endif /* (STD_ON == BSWM_ETHSM_ENABLED) */

#if (STD_ON == BSWM_FRSM_ENABLED)
/* Check if current file and FrSM header file are of the same Autosar version */
#if(\
		(BSWM_AVAILABLEACTIONSTYPE_AR_RELEASE_MAJOR_VERSION != FRSM_AR_RELEASE_MAJOR_VERSION) || \
		(BSWM_AVAILABLEACTIONSTYPE_AR_RELEASE_MINOR_VERSION != FRSM_AR_RELEASE_MINOR_VERSION) \
	)
/*#error "AutoSar Version Number of BswM_AvaliableActionsType.h and FrSM.h are different "*/
#endif
#endif /* (STD_ON == BSWM_FRSM_ENABLED) */

#if (STD_ON == BSWM_J1939DCM_ENABLED)
/* Check if current file and J1939Dcm header file are of the same Autosar version */
#if(\
		(BSWM_AVAILABLEACTIONSTYPE_AR_RELEASE_MAJOR_VERSION != J1939DCM_AR_RELEASE_MAJOR_VERSION) || \
		(BSWM_AVAILABLEACTIONSTYPE_AR_RELEASE_MINOR_VERSION != J1939DCM_AR_RELEASE_MINOR_VERSION) \
	)
/*#error "AutoSar Version Number of BswM_AvaliableActionsType.h and J1939Dcm.h are different "*/
#endif
#endif /* (STD_ON == BSWM_J1939DCM_ENABLED) */

#if (STD_ON == BSWM_J1939NM_ENABLED)
/* Check if current file and J1939Nm header file are of the same Autosar version */
#if(\
		(BSWM_AVAILABLEACTIONSTYPE_AR_RELEASE_MAJOR_VERSION != J1939NM_AR_RELEASE_MAJOR_VERSION) || \
		(BSWM_AVAILABLEACTIONSTYPE_AR_RELEASE_MINOR_VERSION != J1939NM_AR_RELEASE_MINOR_VERSION) \
	)
/*#error "AutoSar Version Number of BswM_AvaliableActionsType.h and J1939Nm.h are different "*/
#endif
#endif /* (STD_ON == BSWM_J1939NM_ENABLED) */

#if (STD_ON == BSWM_J1939RM_ENABLED)
/* Check if current file and J1939Rm header file are of the same Autosar version */
#if(\
		(BSWM_AVAILABLEACTIONSTYPE_AR_RELEASE_MAJOR_VERSION != J1939RM_AR_RELEASE_MAJOR_VERSION) || \
		(BSWM_AVAILABLEACTIONSTYPE_AR_RELEASE_MINOR_VERSION != J1939RM_AR_RELEASE_MINOR_VERSION) \
	)
/*#error "AutoSar Version Number of BswM_AvaliableActionsType.h and J1939Rm.h are different "*/
#endif
#endif /* (STD_ON == BSWM_J1939RM_ENABLED) */

#if (STD_ON == BSWM_LINSM_ENABLED)
/* Check if current file and LinSM header file are of the same Autosar version */
#if(\
		(BSWM_AVAILABLEACTIONSTYPE_AR_RELEASE_MAJOR_VERSION != LINSM_AR_RELEASE_MAJOR_VERSION) || \
		(BSWM_AVAILABLEACTIONSTYPE_AR_RELEASE_MINOR_VERSION != LINSM_AR_RELEASE_MINOR_VERSION) \
	)
#error "AutoSar Version Number of BswM_AvaliableActionsType.h and LinSM.h are different "
#endif
#endif /* (STD_ON == BSWM_LINSM_ENABLED) */

#if (STD_ON == BSWM_NVM_ENABLED)
/* Check if current file and NvM header file are of the same Autosar version */
#if(\
		(BSWM_AVAILABLEACTIONSTYPE_AR_RELEASE_MAJOR_VERSION != NVM_AR_RELEASE_MAJOR_VERSION) || \
		(BSWM_AVAILABLEACTIONSTYPE_AR_RELEASE_MINOR_VERSION != NVM_AR_RELEASE_MINOR_VERSION) \
	)
/*#error "AutoSar Version Number of BswM_AvaliableActionsType.h and NvM.h are different "*/
#endif
#endif /* (STD_ON == BSWM_NVM_ENABLED) */

#if (STD_ON == BSWM_OS_ENABLED)
/* Check if current file and Ecuc header file are of the same Autosar version */
#if(\
		(BSWM_AVAILABLEACTIONSTYPE_AR_RELEASE_MAJOR_VERSION != ECUC_AR_RELEASE_MAJOR_VERSION) || \
		(BSWM_AVAILABLEACTIONSTYPE_AR_RELEASE_MINOR_VERSION != ECUC_AR_RELEASE_MINOR_VERSION) \
	)
/*#error "AutoSar Version Number of BswM_AvaliableActionsType.h and Ecuc.h are different "*/
#endif
/* Check if current file and Os header file are of the same Autosar version */
#if(\
		(BSWM_AVAILABLEACTIONSTYPE_AR_RELEASE_MAJOR_VERSION != OS_AR_RELEASE_MAJOR_VERSION) || \
		(BSWM_AVAILABLEACTIONSTYPE_AR_RELEASE_MINOR_VERSION != OS_AR_RELEASE_MINOR_VERSION) \
	)
#error "AutoSar Version Number of BswM_AvaliableActionsType.h and Os.h are different "
#endif
#endif /* (STD_ON == BSWM_OS_ENABLED) */

#if (STD_ON == BSWM_PDUR_ENABLED)
/* Check if current file and PduR header file are of the same Autosar version */
#if(\
		(BSWM_AVAILABLEACTIONSTYPE_AR_RELEASE_MAJOR_VERSION != PDUR_AR_RELEASE_MAJOR_VERSION) || \
		(BSWM_AVAILABLEACTIONSTYPE_AR_RELEASE_MINOR_VERSION != PDUR_AR_RELEASE_MINOR_VERSION) \
	)
/*#error "AutoSar Version Number of BswM_AvaliableActionsType.h and PduR.h are different "*/
#endif
#endif /* (STD_ON == BSWM_PDUR_ENABLED) */

#if (STD_ON == BSWM_SCHM_ENABLED)
/* Check if current file and Rte header file are of the same Autosar version */
#if(\
		(BSWM_AVAILABLEACTIONSTYPE_AR_RELEASE_MAJOR_VERSION != RTE_AR_RELEASE_MAJOR_VERSION) || \
		(BSWM_AVAILABLEACTIONSTYPE_AR_RELEASE_MINOR_VERSION != RTE_AR_RELEASE_MINOR_VERSION) \
	)
/*#error "AutoSar Version Number of BswM_AvaliableActionsType.h and Rte.h are different "*/
#endif
/* Check if current file and SchM header file are of the same Autosar version */
#if(\
		(BSWM_AVAILABLEACTIONSTYPE_AR_RELEASE_MAJOR_VERSION != SCHM_AR_RELEASE_MAJOR_VERSION) || \
		(BSWM_AVAILABLEACTIONSTYPE_AR_RELEASE_MINOR_VERSION != SCHM_AR_RELEASE_MINOR_VERSION) \
	)
/*#error "AutoSar Version Number of BswM_AvaliableActionsType.h and SchM.h are different "*/
#endif
#endif /* (STD_ON == BSWM_SCHM_ENABLED) */

#if (STD_ON == BSWM_SD_ENABLED)
/* Check if current file and Sd header file are of the same Autosar version */
#if(\
		(BSWM_AVAILABLEACTIONSTYPE_AR_RELEASE_MAJOR_VERSION != SD_AR_RELEASE_MAJOR_VERSION) || \
		(BSWM_AVAILABLEACTIONSTYPE_AR_RELEASE_MINOR_VERSION != SD_AR_RELEASE_MINOR_VERSION) \
	)
/*#error "AutoSar Version Number of BswM_AvaliableActionsType.h and Sd.h are different "*/
#endif
#endif /* (STD_ON == BSWM_SD_ENABLED) */

#endif

/*====================================================================================================*
 *                                             CONSTANTS
 *====================================================================================================*/

/*====================================================================================================*
 *                                         DEFINES AND MACROS
 *====================================================================================================*/

/*====================================================================================================*
 *                                               ENUMS
 *====================================================================================================*/

/**
 * @brief Available Actions Type.
 */
typedef enum
{
	BSWM_COMM_ALLOW_COM,
	BSWM_COMM_MODE_LIMITATION,
	BSWM_COMM_MODE_SWITCH,
	BSWM_CORE_HALT_MODE,
	BSWM_DEADLINE_MONITORING_CONTROL,
	BSWM_ECUM_GODOWN,
	BSWM_ECUM_GOHALT,
	BSWM_ECUM_GOPOLL,
	BSWM_ECUM_SELECT_SHUTDOWN_TARGET,
	BSWM_ECUM_STATE_SWITCH,
	BSWM_FRSM_ALL_SLOTS,
	BSWM_J1939DCM_STATE_SWITCH,
	BSWM_J1939RM_STATE_SWITCH,
	BSWM_LIN_SCHEDULE_SWITCH,
	BSWM_NM_CONTROL,
	BSWM_PDU_GROUP_SWITCH,
	BSWM_PDU_ROUTER_CONTROL,
	BSWM_REQUEST_REMOTE_MODE,
	BSWM_RTE_MODE_REQUEST,
	BSWM_RTE_SWITCH,
	BSWM_SCHM_SWITCH,
	BSWM_SD_CLIENT_SERVICE_MODE_REQUEST,
	BSWM_SD_CONSUMED_EVENT_GROUP_MODE_REQUEST,
	BSWM_SD_SERVER_SERVICE_MODE_REQUEST,
	BSWM_SWITCH_IPDU_MODE,
	BSWM_TRIGGER_IPDU_SEND,
	BSWM_TRIGGER_SLAVE_RTE_STOP,
	BSWM_TRIGGER_STARTUP_PHASE2,
	BSWM_USER_CALLOUT
} BswM_AvailableActionsTypeType;

#if (STD_ON == BSWM_NM_ENABLED)
/**
 * @brief This parameter specifies if the communication of the corresponding NM channel
 * 		  should be enabled or disabled.
 */
typedef enum
{
	/**< @brief corresponding NM channel enabled */
	BSWM_NM_DISABLE,
	/**< @brief corresponding NM channel disabled */
	BSWM_NM_ENABLE
} BswM_NMActionType;
#endif /* (STD_ON == BSWM_NM_ENABLED) */

#if (STD_ON == BSWM_PDUR_ENABLED)
/**
 * @brief This parameter specifies if the communication of the corresponding NM channel
 * 		  should be enabled or disabled.
 */
typedef enum
{
	/**< @brief corresponding NM channel enabled */
	BSWM_PDUR_DISABLE,
	/**< @brief corresponding NM channel disabled */
	BSWM_PDUR_ENABLE
} BswM_PduRouterActionType;
#endif /* (STD_ON == BSWM_PDUR_ENABLED) */

/****************************************************************************************************/
/*                                   STRUCTURES AND OTHER TYPEDEFS                                  */
/****************************************************************************************************/

/**
 * @brief This container includes a reference to mode switch interface which the
 *         BswM must instantiate for the creation of a PPortPrototype in its SWCD.
 * @req    ECUC_BswM_00950
 */
typedef struct
{
	/**< @brief Reference to the ModeSwitchInterface of this BswMModeSwitchPort.
	 *   @todo not yet realized*/
	P2CONST(void, BSWM_CONFIG_DATA, RTE_APPL_CONST) pBswMModeSwitchInterfaceRef;
} BswM_SwitchPortType;

/**
 * @brief This container defines a mode request port which the BswM may utilize to
 *         send a mode request to a SW-C which is acting as a mode-manager.
 * @req    ECUC_BswM_01022
 */
typedef struct
{
	/**< @brief This is a foreign reference to the variable and parameter interface mapping
	 * 			used for the mode request.
	 *   @todo not yet realized
	 */
	P2CONST(void, BSWM_CONFIG_DATA, RTE_APPL_CONST) pBswMRteModeRequestPortInterfaceMappingRef;
	/**< @brief This is an instance reference to the variable data prototype used for the
	 * 			mode request.
	 *   @todo not yet realized
	 */
	P2CONST(void, BSWM_CONFIG_DATA, RTE_APPL_CONST) pBswMRteModeRequestPortInterfaceRef;
} BswM_RteModeRequestPortType;

#if (STD_ON == BSWM_GENERIC_REQUEST_ENABLED)
/**
 * @brief This container includes all details needed for a user defined function call.
 * @req    ECUC_BswM_00834
 */
typedef struct
{
	/**< @brief This parameter specifies the complete function call including all parameters.
	 *          The parameters are specified during configuration time, and cannot be changed
	 *          during run time. Any return values passed by the callout will be ignored.(1)
	 */
	P2FUNC(void, BSWM_APPL_CODE, BswMUserCalloutFunction)(void);
} BswM_UserCalloutType;
#endif /* (STD_ON == BSWM_GENERIC_REQUEST_ENABLED) */

#if (STD_ON == BSWM_COM_ENABLED)
/**
 * @brief This container includes all parameters related to the triggering of an I-PDU
 *         to be sent by COM. Com_TriggerIPDUSend is called when this action is configured.
 * @req    ECUC_BswM_00906
 */
typedef struct
{
	/**< @brief This reference corresponds to the parameter "PduId" of the function
	 *         Com_TriggerIPDUSend. (1..*)
	 */
	P2CONST(PduIdType, BSWM_CONFIG_DATA, BSWM_APPL_CONST) pBswMTriggeredIPduRef;
	CONST(uint16, BSWM_CONFIG_DATA) BswMTriggeredIPduCount;
} BswM_TriggerIPduSendType;

/**
 * @brief This container includes all parameters related to the selection of the
 *         transmission mode an I-PDU to be sent by COM. Com_SwitchIpduTxMode
 *         is called when this action is configured.
 * @req    ECUC_BswM_00958
 */
typedef struct
{
	/**< @brief This parameter corresponds to the parameter "Mode" of the function
	 *         Com_SwitchIpduTxMode. (1)
	 */
	CONST(boolean, BSWM_CONFIG_DATA) BswMSwitchIPduModeValue;
	/**< @brief This reference corresponds to the parameter "PduId" of the function
	 *          Com_SwitchIpduTxMode. (1)
	 */
	CONST(PduIdType, BSWM_CONFIG_DATA) BswMSwitchIPduModeRef;
} BswM_SwitchIPduModeType;
#endif /* (STD_ON == BSWM_COM_ENABLED) */

#if (STD_ON == BSWM_SD_ENABLED)
/**
 * @brief This container includes all parameters related to the selection of a server
 *         service of Sd. Sd_ServerServiceSetState is called when this action is configured.
 * @req    ECUC_BswM_001005
 */
typedef struct
{
	/**< @brief This parameter specifies if the corresponding server service shall be down or available. (1)*/
	CONST(Sd_ServerServiceSetStateType, BSWM_CONFIG_DATA) BswMSdServerServiceState;
	/**< @brief This is a reference to a server service in the Sd module. (1)*/
	CONST(uint16, BSWM_CONFIG_DATA) BswMSdServerMethodsRef;
} BswM_SdServerServiceModeRequestType;

/**
 * @brief This container includes all parameters related to the selection of a
 *         consumed EventGroup of Sd. Sd_ConsumedEventGroupSetState is called
 *         when this action is configured.
 * @req    ECUC_BswM_001004
 */
typedef struct
{
	/**< @brief This parameter specifies if the corresponding consumed event group shall be released
	 *         or requested. (1)
	 */
	CONST(Sd_ConsumedEventGroupSetStateType, BSWM_CONFIG_DATA) BswMSdConsumedEventGroupState;
	/**< @brief This is a reference to an eventGroup that is defined within a client service
	 *          in the Sd module. (1)
	 */
	CONST(uint16, BSWM_CONFIG_DATA) BswMSdConsumedEventGroupRef;
} BswM_SdConsumedEventGroupModeRequestType;

/**
 * @brief This container includes all parameters related to the selection of an client
 *         service of Sd. Sd_ClientServiceSetState is called when this action is configured.
 * @req    ECUC_BswM_000974
 */
typedef struct
{
	/**< @brief This parameter specifies if the corresponding client service shall be released or requested. (1)*/
	CONST(Sd_ClientServiceSetStateType, BSWM_CONFIG_DATA) BswMSdClientServiceState;
	/**< @brief This is a reference to a client service in the Sd module. (1)*/
	CONST(uint16, BSWM_CONFIG_DATA) BswMSdClientMethodsRef;
} BswM_SdClientServiceModeRequestType;
#endif /* (STD_ON == BSWM_SD_ENABLED) */

#if (STD_ON == BSWM_SCHM_ENABLED)
/**
 * @brief This container defines a mode switch indication that the BswM provides to
 *         the SW-C that need to be notified about the mode switch. SchM_Switch is
 *         called when this action is configured.
 * @req    ECUC_BswM_00899
 */
typedef struct
{
	/**< @brief This is the reference to a ModeDeclarationGroup to define a
	 * 			ModeDeclarationGroupPrototype in the role BswModuleDescription.providedModeGroup.
	 * 			Not supported at this time */
	CONST(uint8, BSWM_CONFIG_DATA) BswMSchMModeDeclarationGroupRef;
	/**< @brief This parameter contains the integer value that corresponds to a certain
     *          mode in a Mode Declaration Group.
	 * 			Not supported at this time */
	P2CONST(void, BSWM_CONFIG_DATA, RTE_APPL_CONST) pBswMSchMSwitchedMode;
} BswM_SchMSwitchType;

/**
 * @brief This container defines a mode request that the BswM may send to a SW-C
 *         which is acting as a mode-manager. RTE_Write is called when this action is configured.
 * @req    ECUC_BswM_01021
 */
typedef struct
{
	/**< @brief This is a foreign reference to the Mode Declaration used for the mode request,
	 * 			Not supported at this time*/
	P2CONST(void, BSWM_CONFIG_DATA, RTE_APPL_CONST) pBswMRequestedModeRef;
	/**< @brief This is a reference to a BswMRteModeRequestPort,Not supported at this time*/
	P2CONST(BswM_RteModeRequestPortType, BSWM_CONFIG_DATA, RTE_APPL_CONST) pBswMRteModeRequestPortRef;
} BswM_RteModeRequestType;

/**
 * @brief This container defines a mode switch indication that the BswM provides to
 *         the SW-C that need to be notified about the mode switch. RTE_Switch is
 *         called when this action is configured.
 * @req    ECUC_BswM_00803
 */
typedef struct
{
	/**< @brief This is a reference to the BswMSwitchPort.*/
	P2CONST(BswM_SwitchPortType, BSWM_CONFIG_DATA, BSWM_APPL_CONST) pBswMRteSwitchPortRef;
	/**< @brief This parameter contains the integer value that corresponds to a certain
	 * 			mode in a Mode Declaration Group.
	 * 			Not supported at this time*/
	P2CONST(void, BSWM_CONFIG_DATA, RTE_APPL_CONST) pBswMSwitchedMode;
} BswM_RteSwitchType;
#endif /* (STD_ON == BSWM_SCHM_ENABLED) */

#if (STD_ON == BSWM_PDUR_ENABLED)
/**
 * @brief This container includes all parameters related to enabling and disabling of
 *         routing of Routing Path Groups in the PDU Router. PduR_EnableRouting
 *         or PduR_DisableRouting is called when this action is configured.
 * @req    ECUC_BswM_00853
 */
typedef struct
{
	/**< @brief This parameter specifies if the routing of the corresponding PDU should be enabled
	 *         or disabled. (1)
	 */
	CONST(BswM_PduRouterActionType, BSWM_CONFIG_DATA) BswMPduRouterAction;

	/**< @brief  When BswPduRouterAction is set to BSWM_PDUR_DISABLE and this
	 *           parameter is set to true, then the call to PduR_DisableRouting will be
	 *           invoked with parameter "initialize" set to true, otherwise false. (0..1)
	 * @note     Set to false when quantity is 0
	 */
	CONST(boolean, BSWM_CONFIG_DATA) BswMPduRouterDisableInitBuffer;

	/**< @brief This reference corresponds to the parameter "id" of the function
	 *         PduR_EnableRouting and PduR_DisableRouting. (1..*)
	 */
	P2CONST(PduR_RoutingPathGroupIdType, BSWM_CONFIG_DATA, BSWM_APPL_CONST) pBswMPduRoutingPathGroupRef;
	/**< @brief Pdu Routing Path Group Count*/
	CONST(uint16, BSWM_CONFIG_DATA) BswMPduRoutingPathGroupCount;
} BswM_PduRouterControlType;
#endif /* (STD_ON == BSWM_PDUR_ENABLED) */

#if (STD_ON == BSWM_COM_ENABLED)
/**
 * @brief This container includes references to the PDU groups that shall be
 *         enabled and disabled. Com_IpduGroupControl is called when this action is configured.
 * @req    ECUC_BswM_00828
 */
typedef struct
{
	/**< @brief This parameter corresponds to the parameter "initialize" of the function
	 *          Com_IpduGroupControl. (0..1)
	 * @note   Set to false when quantity is 0
	 */
	CONST(boolean, BSWM_CONFIG_DATA) BswMPduGroupSwitchReinit;

	/**< @brief Together with the BswMEnabledIPduGroupRef, this reference corresponds to
	 *          the parameter "ipduGroupVector" of the function Com_IpduGroupControl. (0..*)
	 */
	P2CONST(Com_IpduGroupIdType, BSWM_CONFIG_DATA, BSWM_APPL_CONST) pBswMDisabledPduGroupRef;
	/**< @brief Diabled Count*/
	CONST(uint16, BSWM_CONFIG_DATA) BswMDiabledCount;

	/**< @brief Together with the BswMDisabledIPduGroupRef, this reference corresponds to
	 *          the parameter "ipduGroupVector" of the function Com_IpduGroupControl. (0..*)
	 */
	P2CONST(Com_IpduGroupIdType, BSWM_CONFIG_DATA, BSWM_APPL_CONST) pBswMEnabledPduGroupRef;
	/**< @brief Enabled Count*/
	CONST(uint16, BSWM_CONFIG_DATA) BswMEnabledCount;
} BswM_PduGroupSwitchType;
#endif /* (STD_ON == BSWM_COM_ENABLED) */


#if (STD_ON == BSWM_NM_ENABLED)
/**
 * @brief This container includes all parameters related to enabling and disabling of
 *         Network Management communication. Disabling of NM communication can be requested by DCM.
 *         Nm_EnableCommunication or Nm_DisableCommunication is called when this action is configured.
 * @req    ECUC_BswM_00837
 */
typedef struct
{
	/**< @brief This parameter specifies if the communication of the corresponding NM channel
	 *          should be enabled or disabled. (1)
	 */
	CONST(BswM_NMActionType, BSWM_CONFIG_DATA) BswMNMAction;

	/**< @brief This reference corresponds to the parameter "NetworkHandle" of the
	 *         function Nm_EnableCommunication and Nm_DisableCommunication. (1)
	 */
	CONST(NetworkHandleType, BSWM_CONFIG_DATA) BswMComMNetworkHandleRef;
} BswM_NMControlType;
#endif /* (STD_ON == BSWM_NM_ENABLED) */

#if (STD_ON == BSWM_LINSM_ENABLED)
/**
 * @brief This container includes all parameters related to a switch of LIN schedule
 *         table. LinSM_ScheduleRequest is called when this action is configured.
 * @req    ECUC_BswM_00827
 */
typedef struct
{
	/**< @brief Network Handle of LIN schedule. (1)*/
	CONST(NetworkHandleType, BSWM_CONFIG_DATA) BswMLinScheduleNetworkHandle;
	/**< @brief This reference corresponds to the parameter "schedule" of the function
	 *         LinSM_ScheduleRequest. (1)
	 */
	CONST(LinIf_SchHandleType, BSWM_CONFIG_DATA) BswMLinScheduleRef;
} BswM_LinScheduleSwitchType;
#endif /* (STD_ON == BSWM_LINSM_ENABLED) */

#if (STD_ON == BSWM_J1939RM_ENABLED)
/**
 * @brief This container includes all parameters related to a switch of the J1939
 *         Request Managers network state for a J1939 node. J1939Rm_SetState is
 *         called when this action is configured.
 * @req    ECUC_BswM_00998
 */
typedef struct
{
	/**< @brief This parameter describes the communication state of the J1939 Request Manager
	 *         and corresponds to the parameter "new state" of the function J1939Rm_SetState. (1)
	 */
	CONST(J1939Rm_StateType, BSWM_CONFIG_DATA)  BswMJ1939RmRequestedState;

	/**< @brief This reference corresponds to the parameter "channel" of the function J1939Rm_SetState. (1)*/
	CONST(NetworkHandleType, BSWM_CONFIG_DATA)   BswMJ1939RmChannelRef;

	/**< @brief This reference corresponds to the parameter "node" of the function J1939Rm_SetState. (1)*/
	CONST(uint8, BSWM_CONFIG_DATA) BswMJ1939RmNodeRef;
} BswM_J1939RmStateSwitchType;
#endif /* (STD_ON == BSWM_J1939RM_ENABLED) */

#if (STD_ON == BSWM_J1939DCM_ENABLED)
/**
 * @brief This container includes all parameters related to a switch of the J1939
 *         Diagnostic Communication Managers network state for a J1939 node.
 *         J1939Dcm_SetState is called when this action is configured.
 * @req    ECUC_BswM_01032
 */
typedef struct
{
	/**< @brief This parameter describes the communication state of the J1939 Diagnostic
	 *         Communication Manager and corresponds to the parameter "newState" of the
	 *         function J1939Dcm_SetState.
	 */
	CONST(J1939Dcm_StateType, BSWM_CONFIG_DATA) BswMJ1939DcmRequestedState;

	/**< @brief This reference corresponds to the parameter "channel" of the function J1939Dcm_SetState.*/
	CONST(NetworkHandleType, BSWM_CONFIG_DATA)   BswMJ1939DcmChannelRef;

	/**< @brief This reference points to a J1939NmNode and provides access to the
	 *         unique J1939NmNodeId.This reference corresponds to the parameter
	 *         "node" of the function J1939Dcm_SetState
	 */
	CONST(uint8, BSWM_CONFIG_DATA) BswMJ1939DcmNodeRef;
} BswM_J1939DcmStateSwitchType;
#endif /* (STD_ON == BSWM_J1939DCM_ENABLED) */

#if (STD_ON == BSWM_FRSM_ENABLED)
/**
 * @brief This container includes all parameter(s) for the action to request an exit
 *         from Flexray KeySlotOnlyMode. FrSM_AllSlots is called when this action is executed.
 * @req    ECUC_BswM_01037
 */
typedef struct
{
	/**< @brief This references the FlexRay cluster. The reference corresponds to the
     *         parameter "NetworkHandle" of the function FrSM_AllSlots.
	 */
	CONST(NetworkHandleType, BSWM_CONFIG_DATA) BswMFrSMAllSlotsNetworkHandleRef;
} BswM_FrSMAllSlotsType;
#endif /* (STD_ON == BSWM_FRSM_ENABLED) */

#if (STD_ON == BSWM_ECUM_ENABLED)
/**
 * @brief This container defines the action to switch a State of the EcuM.
 * @req    ECUC_BswM_01045
 */
typedef struct
{
	/**< @brief This parameter corresponds to the parameter "State" of the function EcuM_SetState().*/
	CONST(EcuM_StateType, BSWM_CONFIG_DATA) BswMEcuMState;
} BswM_EcuMStateSwitchType;

/**
 * @brief This container defines the shutdown target.
 * @req    ECUC_BswM_00961
 */
typedef struct
{
	/**< @brief This parameter contains the shutdown target that the BswM selects at the EcuM. (1)*/
	CONST(EcuM_ShutdownTargetType, BSWM_CONFIG_DATA) BswMEcuMShutdownTarget;

	/**< @brief This is a reference to a reset mode. (0..1)*/
	CONST(EcuM_ShutdownModeType, BSWM_CONFIG_DATA) BswMEcuMResetModeRef;

	/**< @brief This is a reference to a sleep mode. (0..1)*/
	CONST(EcuM_ShutdownModeType, BSWM_CONFIG_DATA) BswMEcuMSleepModeRef;

} BswM_EcuMSelectShutdownTargetType;

/**
 * @brief This container defines the UserId which shall be forwarded to the GoDown request.
 * @req    ECUC_BswM_00963
 */
typedef struct
{
	/**< @brief This is a reference to a EcuM UserId. (1)*/
	CONST(EcuM_UserType, BSWM_CONFIG_DATA) BswMEcuMUserIdRef;
} BswM_EcuMGoDownType;
#endif /* (STD_ON == BSWM_ECUM_ENABLED) */

#if (STD_ON == BSWM_COM_ENABLED)
/**
 * @brief This container includes all parameters related to enabling and disabling of
 *         deadline monitoring for one or several PDUs in COM.
 *         COM_ReceptionDMControl is called when this action is configured.
 * @req    ECUC_BswM_00830
 */
typedef struct
{
	/**< @brief Together with the BswMEnabledDMPduGroupRef, this reference
	 *          corresponds to the parameter "ipduGroupVector" of the function COM_ReceptionDMControl.
	 *          (0..*)
	 */
	P2CONST(Com_IpduGroupIdType, BSWM_CONFIG_DATA, BSWM_APPL_CONST) pBswMDisabledDMPduGroupRef;
	CONST(uint16, BSWM_CONFIG_DATA) BswMDiabledCount;

	/**< @brief Together with the BswMDisabledDMPduGroupRef, this reference
	 *          corresponds to the parameter "ipduGroupVector" of the function COM_ReceptionDMControl.
	 *          (0..*)
	 */
	P2CONST(Com_IpduGroupIdType, BSWM_CONFIG_DATA, BSWM_APPL_CONST) pBswMEnabledDMPduGroupRef;
	/**< @brief Enabled Count (1)*/
	CONST(uint16, BSWM_CONFIG_DATA) BswMEnabledCount;
} BswM_DeadlineMonitoringControlType;
#endif /* (STD_ON == BSWM_COM_ENABLED) */

#if (STD_ON == BSWM_OS_ENABLED)
/**
 * @brief This container includes all parameters related to a switch of the activation
 *         state of core Halt.
 * @req    ECUC_BswM_00970
 */
typedef struct
{
	/**< @brief Different possibilities are offered depending on the OS implementation and the
	 * 			CPU HW.
	 * 			Not supported at this time*/
	CONST(uint8, BSWM_CONFIG_DATA) BswMCoreHaltActivationState;
	/**< @brief This is a reference to the core on which the Core Halt process must be
	 * 			influenced.
	 * 			Not supported at this time*/
	CONST(Ecuc_CoreIdType, BSWM_CONFIG_DATA) BswMTargetCoreRef;
} BswM_CoreHaltModeType;
#endif /* (STD_ON == BSWM_OS_ENABLED) */

#if (STD_ON == BSWM_COMM_ENABLED)
/**
 * @brief This container includes all parameters related to a switch of
 *         communication mode for a ComM User. ComM_RequestComMode is
 *         called when this action is configured.
 * @req    ECUC_BswM_00831
 */
typedef struct
{
	/**< @brief This parameter corresponds to the parameter "ComMode" of the function
     *          ComM_RequestComMode.(1) */
	CONST(ComM_ModeType, BSWM_CONFIG_DATA) BswMComMRequestedMode;

	/**< @brief This reference corresponds to the parameter "User" of the function
	 *          ComM_RequestComMode.(1) */
	CONST(ComM_UserHandleType, BSWM_CONFIG_DATA) BswMComMUserRef;
} BswM_ComMModeSwitchType;

/**
 * @brief This container includes all parameters related to a limitation of
 *         communication mode for a ComM Channel. ComM_LimitChannelToNoComMode
 *         is called when this action is configured.
 * @req    ECUC_BswM_00908
 */
typedef struct
{
	/**< @brief This parameter corresponds to the parameter "Status" of the function
	 *          ComM_LimitChannelToNoComMode().(1) */
	CONST(boolean, BSWM_CONFIG_DATA) BswMComMLimitMode;

	/**< @brief This reference corresponds to the parameter "Channel" of the function
     *          ComM_LimitChannelToNoComMode().(1) */
	CONST(NetworkHandleType, BSWM_CONFIG_DATA) BswMComMLimitChannelRef;
} BswM_ComMModeLimitationType;

/**
 * @brief This container includes all parameters for the action to allow or to block
 *         communication for a ComM Channel.
 * @req    ECUC_BswM_00909
 */
typedef struct
{
	/**< @brief This parameter corresponds to the parameter "Allowed" of the function
     *          ComM_CommunicationAllowed(). (1) */
	CONST(boolean, BSWM_CONFIG_DATA) BswMComAllowed;

	/**< @brief This reference corresponds to the parameter "Channel" of the function
     *          ComM_CommunicationAllowed(). (1) */
	CONST(NetworkHandleType, BSWM_CONFIG_DATA) BswMComMAllowChannelRef;
} BswM_ComMAllowComType;
#endif /* (STD_ON == BSWM_COMM_ENABLED) */

/****************************************************************************************************/
/*                                       FUNCTION PROTOTYPES                                        */
/****************************************************************************************************/

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */
/** @} */

#endif /* #ifndef BSWM_AVAILABLEACTIONSTYPE_H */
