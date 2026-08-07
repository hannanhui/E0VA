/**
 * @file        BswM_ModeRequestSourceType.h
 * @brief       AUTOSAR BSWM_MODEREQUESTSOURCETYPE - BswM_ModeRequestSourceType driver header file.
 * @details     BswM_ModeRequestSourceType driver header file, containing the Autosar API specification and
 *              other variables and functions that are exported by the BswM_ModeRequestSourceType driver.
 * @version     1.2.0
 *
 * @addtogroup  BSWM_MODEREQUESTSOURCETYPE
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
#ifndef BSWM_MODEREQUESTSOURCETYPE_H
#define BSWM_MODEREQUESTSOURCETYPE_H

#if defined(__cplusplus)
extern "C" 
{
#endif /* defined(__cplusplus) */

/*====================================================================================================*
 *                                           INCLUDE FILES
 *====================================================================================================*/

#include "BswM_Cfg.h"

#if ((STD_ON == BSWM_CANSM_ICOM_ENABLED) || (STD_ON == BSWM_CANSM_ENABLED))
#include "CanSM.h"
#endif /* ((STD_ON == BSWM_CANSM_ICOM_ENABLED) || (STD_ON == BSWM_CANSM_ENABLED)) */

#if (STD_ON == BSWM_COMM_ENABLED)
#include "ComM.h"
#endif /* (STD_ON == BSWM_COMM_ENABLED) */

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

#if (STD_ON == BSWM_LINSM_ENABLED)
#include "LinSM.h"
#endif /* (STD_ON == BSWM_LINSM_ENABLED) */

#if (STD_ON == BSWM_NVM_ENABLED)
#include "NvM.h"
#endif /* (STD_ON == BSWM_NVM_ENABLED) */

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

#define BSWM_MODEREQUESTSOURCETYPE_VENDOR_ID                    0U
#define BSWM_MODEREQUESTSOURCETYPE_AR_RELEASE_MAJOR_VERSION     4U
#define BSWM_MODEREQUESTSOURCETYPE_AR_RELEASE_MINOR_VERSION     2U
#define BSWM_MODEREQUESTSOURCETYPE_AR_RELEASE_REVISION_VERSION  2U
#define BSWM_MODEREQUESTSOURCETYPE_SW_MAJOR_VERSION             1U
#define BSWM_MODEREQUESTSOURCETYPE_SW_MINOR_VERSION             2U
#define BSWM_MODEREQUESTSOURCETYPE_SW_PATCH_VERSION             0U

/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/

/* Check if current file and BswM_Cfg header file are of the same vendor */
#if(BSWM_MODEREQUESTSOURCETYPE_VENDOR_ID != BSWM_CFG_VENDOR_ID )
#error "BswM_ModeRequestSourceType.h and BswM_Cfg.h have different vendor id"
#endif
/* Check if current file and BswM_Cfg header file are of the same Autosar version */
#if(\
		(BSWM_MODEREQUESTSOURCETYPE_AR_RELEASE_MAJOR_VERSION != BSWM_CFG_AR_RELEASE_MAJOR_VERSION) || \
		(BSWM_MODEREQUESTSOURCETYPE_AR_RELEASE_MINOR_VERSION != BSWM_CFG_AR_RELEASE_MINOR_VERSION) || \
		(BSWM_MODEREQUESTSOURCETYPE_AR_RELEASE_REVISION_VERSION != BSWM_CFG_AR_RELEASE_REVISION_VERSION) \
	)
#error "AutoSar Version Number of BswM_ModeRequestSourceType.h and BswM_Cfg.h are different "
#endif
/* Check if current file and BswM_Cfg header file are of the same software version */
#if(\
		(BSWM_MODEREQUESTSOURCETYPE_SW_MAJOR_VERSION != BSWM_CFG_SW_MAJOR_VERSION) || \
		(BSWM_MODEREQUESTSOURCETYPE_SW_MINOR_VERSION != BSWM_CFG_SW_MINOR_VERSION) || \
		(BSWM_MODEREQUESTSOURCETYPE_SW_PATCH_VERSION != BSWM_CFG_SW_PATCH_VERSION) \
	)
#error "Software Version Number of BswM_ModeRequestSourceType.h and BswM_Cfg.h are different "
#endif

#ifndef DISABLE_INTERMOD_VERSION_CHECK

#if ((STD_ON == BSWM_CANSM_ICOM_ENABLED) || (STD_ON == BSWM_CANSM_ENABLED))
/* Check if current file and CanSM header file are of the same Autosar version */
#if(\
		(BSWM_MODEREQUESTSOURCETYPE_AR_RELEASE_MAJOR_VERSION != CANSM_AR_RELEASE_MAJOR_VERSION) || \
		(BSWM_MODEREQUESTSOURCETYPE_AR_RELEASE_MINOR_VERSION != CANSM_AR_RELEASE_MINOR_VERSION) \
	)
/*#error "AutoSar Version Number of BswM_ModeRequestSourceType.h and CanSM.h are different "*/
#endif
#endif /* ((STD_ON == BSWM_CANSM_ICOM_ENABLED) || (STD_ON == BSWM_CANSM_ENABLED)) */

#if (STD_ON == BSWM_COMM_ENABLED)
/* Check if current file and ComM header file are of the same Autosar version */
#if(\
		(BSWM_MODEREQUESTSOURCETYPE_AR_RELEASE_MAJOR_VERSION != COMM_AR_RELEASE_MAJOR_VERSION) || \
		(BSWM_MODEREQUESTSOURCETYPE_AR_RELEASE_MINOR_VERSION != COMM_AR_RELEASE_MINOR_VERSION) \
	)
/*#error "AutoSar Version Number of BswM_ModeRequestSourceType.h and ComM.h are different "*/
#endif
#endif /* (STD_ON == BSWM_COMM_ENABLED) */


#if (STD_ON == BSWM_DCM_ENABLED)
/* Check if current file and Dcm header file are of the same Autosar version */
#if(\
		(BSWM_MODEREQUESTSOURCETYPE_AR_RELEASE_MAJOR_VERSION != DCM_AR_RELEASE_MAJOR_VERSION) || \
		(BSWM_MODEREQUESTSOURCETYPE_AR_RELEASE_MINOR_VERSION != DCM_AR_RELEASE_MINOR_VERSION) \
	)
/*#error "AutoSar Version Number of BswM_ModeRequestSourceType.h and Dcm.h are different "*/
#endif
#endif /* (STD_ON == BSWM_DCM_ENABLED) */

#if (STD_ON == BSWM_ECUM_ENABLED)
/* Check if current file and EcuM header file are of the same Autosar version */
#if(\
		(BSWM_MODEREQUESTSOURCETYPE_AR_RELEASE_MAJOR_VERSION != ECUM_AR_RELEASE_MAJOR_VERSION) || \
		(BSWM_MODEREQUESTSOURCETYPE_AR_RELEASE_MINOR_VERSION != ECUM_AR_RELEASE_MINOR_VERSION) \
	)
#error "AutoSar Version Number of BswM_ModeRequestSourceType.h and EcuM.h are different "
#endif
#endif /* (STD_ON == BSWM_ECUM_ENABLED) */

#if (STD_ON == BSWM_ETHSM_ENABLED)
/* Check if current file and EthSM header file are of the same Autosar version */
#if(\
		(BSWM_MODEREQUESTSOURCETYPE_AR_RELEASE_MAJOR_VERSION != ETHSM_AR_RELEASE_MAJOR_VERSION) || \
		(BSWM_MODEREQUESTSOURCETYPE_AR_RELEASE_MINOR_VERSION != ETHSM_AR_RELEASE_MINOR_VERSION) \
	)
/*#error "AutoSar Version Number of BswM_ModeRequestSourceType.h and EthSM.h are different "*/
#endif
#endif /* (STD_ON == BSWM_ETHSM_ENABLED) */

#if (STD_ON == BSWM_FRSM_ENABLED)
/* Check if current file and FrSM header file are of the same Autosar version */
#if(\
		(BSWM_MODEREQUESTSOURCETYPE_AR_RELEASE_MAJOR_VERSION != FRSM_AR_RELEASE_MAJOR_VERSION) || \
		(BSWM_MODEREQUESTSOURCETYPE_AR_RELEASE_MINOR_VERSION != FRSM_AR_RELEASE_MINOR_VERSION) \
	)
/*#error "AutoSar Version Number of BswM_ModeRequestSourceType.h and FrSM.h are different "*/
#endif
#endif /* (STD_ON == BSWM_FRSM_ENABLED) */

#if (STD_ON == BSWM_J1939DCM_ENABLED)
/* Check if current file and J1939Dcm header file are of the same Autosar version */
#if(\
		(BSWM_MODEREQUESTSOURCETYPE_AR_RELEASE_MAJOR_VERSION != J1939DCM_AR_RELEASE_MAJOR_VERSION) || \
		(BSWM_MODEREQUESTSOURCETYPE_AR_RELEASE_MINOR_VERSION != J1939DCM_AR_RELEASE_MINOR_VERSION) \
	)
/*#error "AutoSar Version Number of BswM_ModeRequestSourceType.h and J1939Dcm.h are different "*/
#endif
#endif /* (STD_ON == BSWM_J1939DCM_ENABLED) */

#if (STD_ON == BSWM_J1939NM_ENABLED)
/* Check if current file and J1939Nm header file are of the same Autosar version */
#if(\
		(BSWM_MODEREQUESTSOURCETYPE_AR_RELEASE_MAJOR_VERSION != J1939NM_AR_RELEASE_MAJOR_VERSION) || \
		(BSWM_MODEREQUESTSOURCETYPE_AR_RELEASE_MINOR_VERSION != J1939NM_AR_RELEASE_MINOR_VERSION) \
	)
/*#error "AutoSar Version Number of BswM_ModeRequestSourceType.h and J1939Nm.h are different "*/
#endif
#endif /* (STD_ON == BSWM_J1939NM_ENABLED) */

#if (STD_ON == BSWM_LINSM_ENABLED)
/* Check if current file and LinSM header file are of the same Autosar version */
#if(\
		(BSWM_MODEREQUESTSOURCETYPE_AR_RELEASE_MAJOR_VERSION != LINSM_AR_RELEASE_MAJOR_VERSION) || \
		(BSWM_MODEREQUESTSOURCETYPE_AR_RELEASE_MINOR_VERSION != LINSM_AR_RELEASE_MINOR_VERSION) \
	)
#error "AutoSar Version Number of BswM_ModeRequestSourceType.h and LinSM.h are different "
#endif
#endif /* (STD_ON == BSWM_LINSM_ENABLED) */

#if (STD_ON == BSWM_NVM_ENABLED)
/* Check if current file and NvM header file are of the same Autosar version */
#if(\
		(BSWM_MODEREQUESTSOURCETYPE_AR_RELEASE_MAJOR_VERSION != NVM_AR_RELEASE_MAJOR_VERSION) || \
		(BSWM_MODEREQUESTSOURCETYPE_AR_RELEASE_MINOR_VERSION != NVM_AR_RELEASE_MINOR_VERSION) \
	)
/*#error "AutoSar Version Number of BswM_ModeRequestSourceType.h and NvM.h are different "*/
#endif
#endif /* (STD_ON == BSWM_NVM_ENABLED) */

#if (STD_ON == BSWM_SCHM_ENABLED)
/* Check if current file and Rte header file are of the same Autosar version */
#if(\
		(BSWM_MODEREQUESTSOURCETYPE_AR_RELEASE_MAJOR_VERSION != RTE_AR_RELEASE_MAJOR_VERSION) || \
		(BSWM_MODEREQUESTSOURCETYPE_AR_RELEASE_MINOR_VERSION != RTE_AR_RELEASE_MINOR_VERSION) \
	)
/*#error "AutoSar Version Number of BswM_ModeRequestSourceType.h and Rte.h are different "*/
#endif
/* Check if current file and SchM header file are of the same Autosar version */
#if(\
		(BSWM_MODEREQUESTSOURCETYPE_AR_RELEASE_MAJOR_VERSION != SCHM_AR_RELEASE_MAJOR_VERSION) || \
		(BSWM_MODEREQUESTSOURCETYPE_AR_RELEASE_MINOR_VERSION != SCHM_AR_RELEASE_MINOR_VERSION) \
	)
/*#error "AutoSar Version Number of BswM_ModeRequestSourceType.h and SchM.h are different "*/
#endif
#endif /* (STD_ON == BSWM_SCHM_ENABLED) */

#if (STD_ON == BSWM_SD_ENABLED)
/* Check if current file and Sd header file are of the same Autosar version */
#if(\
		(BSWM_MODEREQUESTSOURCETYPE_AR_RELEASE_MAJOR_VERSION != SD_AR_RELEASE_MAJOR_VERSION) || \
		(BSWM_MODEREQUESTSOURCETYPE_AR_RELEASE_MINOR_VERSION != SD_AR_RELEASE_MINOR_VERSION) \
	)
/*#error "AutoSar Version Number of BswM_ModeRequestSourceType.h and Sd.h are different "*/
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
 * @brief Define the type of BswMModeRequestSource.
 */
typedef enum
{
	BSWM_BSWM_MODE_REQUEST,  /* obsolete */
	BSWM_BSWM_MODE_SWITCH_NOTIFICATION,  /* obsolete */
	BSWM_BSW_MODE_NOTIFICATION, /* unrealized */
	BSWM_CANSM_ICOM_INDICATION,
	BSWM_CANSM_INDICATION,
	BSWM_COMM_INDICATION,
	BSWM_COMM_INITIATE_RESET,
	BSWM_COMM_PNC_REQUEST,
	BSWM_DCM_APPLICATION_UPDATED_INDICATION,
	BSWM_DCM_COM_MODE_REQUEST,
	BSWM_ECUM_INDICATION,
	BSWM_ECUM_RUN_REQUEST_INDICATION,
	BSWM_ECUM_WAKEUP_SOURCE,
	BSWM_ETHSM_INDICATION,
	BSWM_FRSM_INDICATION,
	BSWM_GENERIC_REQUEST,
	BSWM_J1939DCM_BROADCAST_STATUS,
	BSWM_J1939NM_INDICATION,
	BSWM_LINSM_INDICATION,
	BSWM_LIN_SCHEDULE_INDICATION,
	BSWM_LINTP_MODE_REQUEST,
	BSWM_MODE_SWITCH_ERROR_EVENT,
	BSWM_NMIF_CAR_WAKEUP_INDICATION,
	BSWM_NVM_JOB_MODE_INDICATION,
	BSWM_NVM_REQUEST,
	BSWM_PARTITION_RESTARTED,
	BSWM_SD_CLIENT_SERVICE_CURRENT_STATE,
	BSWM_SD_CONSUMED_EVENT_GROUP_CURRENT_STATE,
	BSWM_SD_EVENT_HANDLER_CURRENT_STATE,
	BSWM_SWC_MODE_NOTIFICATION,
	BSWM_SWC_MODE_REQUEST,
	BSWM_WDGM_REQUEST_PARTITION_RESET
} BswM_ModeRequestSourceTypeType;

#if (STD_ON == BSWM_ECUM_ENABLED)
/**
 * @brief This is an indication of the current State of the RUN Request Protocol.
 */
typedef enum
{
	/**< @brief Port for POST_RUN State of EcuM. */
	BSWM_POST_RUN = (uint8) 0x33u,
	/**< @brief Port for RUN State of EcuM */
	BSWM_RUN      = (uint8) 0x32u
} BswM_EcuMRUNRequestProtocolPortType;
#endif /* (STD_ON == BSWM_ECUM_ENABLED) */

#if (STD_ON == BSWM_NVM_ENABLED)
/**
 * @brief Identifies the Nvm job which is related to the mode request.
 */
typedef enum
{
	/**< @brief NvmReadAll corresponds to service Id 0x0c */
	BSWM_NVM_READ_ALL,
	/**< @brief NvmWriteAll corresponds to service Id 0x0d*/
	BSWM_NVM_WRITE_ALL
} BswM_NvmServiceType;
#endif /* (STD_ON == BSWM_NVM_ENABLED) */

/*====================================================================================================*
 *                                   STRUCTURES AND OTHER TYPEDEFS
 *====================================================================================================*/

#if (STD_ON == BSWM_WDGM_ENABLED)
/**
 * @brief This is a Partition Reset request from from the WdgM. This port
 *        corresponds to a call of the BswM_WdgM_RequestPartitionReset API.
 */
typedef struct
{
	/**< @brief This is a reference to the partition that shall be reset.*/
	/* not yet realized pBswMWdgMRequestPartitionResetRef */
	P2CONST(void, BSWM_CONFIG_DATA, ECUC_APPL_CONST) pBswMWdgMRequestPartitionResetRef;
} BswM_WdgMRequestPartitionResetType;
#endif /* (STD_ON == BSWM_WDGM_ENABLED) */

#if (STD_ON == BSWM_SCHM_ENABLED)
/**
 * @brief The source of the mode request is a SW Component.
 */
typedef struct
{
	/**< @brief This is a reference to the VariableDataPrototype.*/
	/* not yet realized pBswMSwcModeNotificationModeDeclarationGroupPrototypeRef */
	P2CONST(void, BSWM_CONFIG_DATA, RTE_APPL_CONST) pBswMSwcModeRequestVariableDataPrototypeRef;
} BswM_SwcModeRequestType;

/**
 * @brief This is a mode switch notification associated with a RTE switch interface.
 */
typedef struct
{
	/**< @brief This is a foreign reference to the ModeDeclarationGroupPrototype.*/
	/* not yet realized pBswMSwcModeNotificationModeDeclarationGroupPrototypeRef*/
	P2CONST(void, BSWM_CONFIG_DATA, RTE_APPL_CONST) pBswMSwcModeNotificationModeDeclarationGroupPrototypeRef;
} BswM_SwcModeNotificationType;
#endif /* (STD_ON == BSWM_SCHM_ENABLED) */

#if (STD_ON == BSWM_SD_ENABLED)
/**
 * @brief Used by Service Discovery to indicate current status of the EventHandler
 *        (requested/released).
 */
typedef struct
{
	/**< @brief This is a reference to an event handler that is defined within a server
	 * 			service in the Sd module.*/
	/* not yet realized BswMSdEventHandlerRef */
	CONST(uint16, BSWM_CONFIG_DATA) BswMSdEventHandlerRef;
} BswM_SdEventHandlerCurrentStateType;

/**
 * @brief Used by Service Discovery to indicate current status of the EventHandler
 *         (requested/released).
 */
typedef struct
{
	/**< @brief This is a reference to an eventGroup that is defined within a client service
	 * 			in the Sd module.*/
	/* not yet realized pBswMSdClientMethodsRef */
	CONST(uint16, BSWM_CONFIG_DATA) BswMSdConsumedEventGroupRef;
} BswM_SdConsumedEventGroupCurrentStateType;

/**
 * @brief Used by Service Discovery module to indicate current state of the Client
 *         Service (available/down).
 * @req    ECUC_BswM_01011
 */
typedef struct
{
	/**< @brief This is a reference to a client service in the Sd module.*/
	/* not yet realized pBswMSdClientMethodsRef*/
	CONST(uint16, BSWM_CONFIG_DATA) BswMSdClientMethodsRef;
} BswM_SdClientServiceCurrentStateType;
#endif /* (STD_ON == BSWM_SD_ENABLED) */

#if (STD_ON == BSWM_NVM_ENABLED)
/**
 * @brief Via this Mode Request Source the NvM indicates the current status of the specified block.
 * @req    ECUC_BswM_00890
 */
typedef struct
{
	/**< @brief This is a reference to the NvM Block Descriptor that the request
	 * 			corresponds to.*/
	/* not yet realized pBswMNvMBlockRef*/
	CONST(NvM_BlockIdType, BSWM_CONFIG_DATA) BswMNvMBlockRef;
} BswM_NvMRequestType;

/**
 * @brief Indicates the current status of the multiblock job. The job is identified via
 *        BswMNvmService, e.g. 0x0c for NvmReadAll, 0x0d for NvmWriteAll.
 */
typedef struct
{
	/**< @brief Identifies the Nvm job which is related to the mode request.*/
	CONST(BswM_NvmServiceType, BSWM_CONFIG_DATA) BswMNvmService;
} BswM_NvMJobModeIndicationType;
#endif /* (STD_ON == BSWM_NVM_ENABLED) */

#if (STD_ON == BSWM_NM_ENABLED)
/**
 * @brief This is an indication of a CarWakeup from the NmIf.
 */
typedef struct
{
	/**< @brief This is a reference to the channel handle that the indication corresponds to.*/
	CONST(NetworkHandleType, BSWM_CONFIG_DATA) BswMNmChannelRef;
} BswM_NmIfCarWakeUpIndicationType;
#endif /* (STD_ON == BSWM_NM_ENABLED) */

#if (STD_ON == BSWM_SCHM_ENABLED)
/**
 * @brief This is a notification that an error occurred because the partition containing
 *        the mode users of the Mode Declaration Group Prototype was restarted by the RTE.
 * @req    ECUC_BswM_00990
 */
typedef struct
{
	/**< @brief This is a reference to the BswMSwitchPort.*/
	/*  @todo not yet realized pBswMRteSwitchPortRef*/
	P2CONST(void, BSWM_CONFIG_DATA, BSWM_APPL_CONST) pBswMRteSwitchPortRef;
} BswM_ModeSwitchErrorEventType;
#endif /* (STD_ON == BSWM_SCHM_ENABLED) */

#if (STD_ON == BSWM_LINTP_ENABLED)
/**
 * @brief This is a LinTp mode request from the LinIf. This port corresponds to a call
 *         of the BswM_LinTp_RequestMode API.
 * @req    ECUC_BswM_00914
 */
typedef struct
{
	/**< @brief This is a reference to the LIN Interface Channel that the mode request
	 * 			corresponds to.*/
	CONST(NetworkHandleType, BSWM_CONFIG_DATA) BswMLinTpChannelRef;
} BswM_LinTpModeRequestType;
#endif /* (STD_ON == BSWM_LINTP_ENABLED) */

#if (STD_ON == BSWM_LINSM_ENABLED)
/**
 * @brief This is an indication of the currently active LIN Schedule Table for a
 *         specific LIN Interface.
 * @req    ECUC_BswM_00885
 */
typedef struct
{
	/**< @brief This is a reference to the LIN channel handle that the mode request
	 *          corresponds to.*/
	CONST(NetworkHandleType, BSWM_CONFIG_DATA) BswMLinSMChannelRef;

	/**< @brief This is a reference to the LIN Schedule Table handle that the mode
	 *          request corresponds to.The type depends on the LinSm*/
	CONST(uint8, BSWM_CONFIG_DATA) BswMLinScheduleRef;
} BswM_LinScheduleIndicationType;

/**
 * @brief This is an indication of the current state of the LIN State Manager.
 * @req    ECUC_BswM_00859
 */
typedef struct
{
	/**< @brief This is a reference to the LIN channel handle that the mode request
	 *          corresponds to.*/
	CONST(NetworkHandleType, BSWM_CONFIG_DATA) BswMLinSMChannelRef;
} BswM_LinSMIndicationType;
#endif /* (STD_ON == BSWM_LINSM_ENABLED) */

#if (STD_ON == BSWM_J1939NM_ENABLED)
/**
 * @brief This is an indication of the current state of the J1939 network management module.
 * @req    ECUC_BswM_00966
 */
typedef struct
{
	/**< @brief This is a reference to the J1939Nm channel handle that the mode request
	 *          corresponds to.*/
	CONST(NetworkHandleType, BSWM_CONFIG_DATA) BswMJ1939NmChannelRef;

	/**< @brief This is a reference to the node that the mode request corresponds to.
	 *          The type depends on J1939NM.*/
	CONST(uint8, BSWM_CONFIG_DATA) BswMJ1939NmNodeRef;
} BswM_J1939NmIndicationType;
#endif /* (STD_ON == BSWM_J1939NM_ENABLED) */

#if (STD_ON == BSWM_J1939DCM_ENABLED)
/**
 * @brief This is an indication of the current state of the J1939 network management module.
 * @req    ECUC_BswM_00985
 */
typedef struct
{
	/**< @brief Reference to the channel represented by the nth bit in the networkMask
	 *          parameter to J1939DcmBroadcastStatus.*/
	CONST(NetworkHandleType, BSWM_CONFIG_DATA) pBswMJ1939DcmChannelRef;
} BswM_J1939DcmBroadcastStatusType;
#endif /* (STD_ON == BSWM_J1939DCM_ENABLED) */

#if (STD_ON == BSWM_GENERIC_REQUEST_ENABLED)
/**
 * @brief This mode request originates from a requester that is <b>not among the list of
 *         standardized mode requesters</b> (i.e. the different resource managers).
 * @req    ECUC_BswM_00861
 */
typedef struct
{
	/**< @brief This parameters identifies the different users of the generic
	 * 			mode request interface. (1)*/
	CONST(BswM_UserType, BSWM_CONFIG_DATA) BswMModeRequesterId;
	/**< @brief This parameter defines the upper limit for the modes requested
	 * 			by this mode requester. (1)*/
	CONST(BswM_ModeType, BSWM_CONFIG_DATA) BswMRequestedModeMax;
} BswM_GenericRequestType;
#endif /* (STD_ON == BSWM_GENERIC_REQUEST_ENABLED) */

#if (STD_ON == BSWM_FRSM_ENABLED)
/**
 * @brief This is an indication of the current state of the FlexRay State Manager.
 * @req    ECUC_BswM_00858
 */
typedef struct
{
	/**< @brief This is a reference to the FlexRay Cluster handle that the mode request
	 *          corresponds to.*/
	CONST(NetworkHandleType, BSWM_CONFIG_DATA) BswMFrSMChannelRef;
} BswM_FrSMIndicationType;
#endif /* (STD_ON == BSWM_FRSM_ENABLED) */

#if (STD_ON == BSWM_ETHSM_ENABLED)
/**
 * @brief This is an indication of the current state of the Ethernet State Manager.
 * @req    ECUC_BswM_00860
 */
typedef struct
{
	/**< @brief This is a reference to the Ethernet channel handle that the mode request
	 *          corresponds to.*/
	CONST(NetworkHandleType, BSWM_CONFIG_DATA) BswMEthSMChannelRef;
} BswM_EthSMIndicationType;
#endif /* (STD_ON == BSWM_ETHSM_ENABLED) */

#if (STD_ON == BSWM_ECUM_ENABLED)
/**
 * @brief This is a notification of the current state of an ECU State Manager wakeup source.
 * @req    ECUC_BswM_00904
 */
typedef struct
{
	/**< @brief This is a reference to the ECU State Manager Wakeup Source that the
	 *          indication corresponds to.*/
	CONST(EcuM_WakeupSourceType, BSWM_CONFIG_DATA) BswMEcuMWakeupSrcRef;
} BswM_EcuMWakeupSourceType;

/**
 * @brief This is an indication of the current State of the RUN Request Protocol.
 * @req    ECUC_BswM_01043
 */
typedef struct
{
	/**< @brief Identifies the EcuM State which is related to the mode request.*/
	CONST(BswM_EcuMRUNRequestProtocolPortType, BSWM_CONFIG_DATA) BswMEcuMRUNRequestProtocolPort;
} BswM_EcuMRUNRequestIndicationType;
#endif /* (STD_ON == BSWM_ECUM_ENABLED) */

#if (STD_ON == BSWM_DCM_ENABLED)
/**
 * @brief The source of the mode request is the Diagnostic Communication Manager.
 * @req   ECUC_BswM_00863
 */
typedef struct
{
	/**< @brief This is a reference from DcmModeRequest to the ComM channel that the
	 *          indication corresponds to.*/
	CONST(NetworkHandleType, BSWM_CONFIG_DATA) BswMDcmComMChannelRef;
} BswM_DcmComModeRequestType;
#endif /* (STD_ON == BSWM_DCM_ENABLED) */

#if (STD_ON == BSWM_COMM_ENABLED)
/**
 * @brief This is a request of the current communication mode of a Partial Network
 *         Cluster in the Communication Manager.
 * @req    ECUC_BswM_00922
 */
typedef struct
{
	/**< @brief This is a reference to the Communication Manager PNC handle of the
	 *          Partial Network Cluster that the request corresponds to.*/
	CONST(ComM_PncModeType, BSWM_CONFIG_DATA) BswMComMPncRef;
} BswM_ComMPncRequestType;

/**
 * @brief This is an indication of the current communication mode of a channel in the
 *         Communication Manager.
 * @req    ECUC_BswM_00880
 */
typedef struct
{
	/**< @brief This is a reference to the Communication Manager channel handle that the
	 *          indication corresponds to.*/
	CONST(NetworkHandleType, BSWM_CONFIG_DATA) BswMComMChannelRef;
} BswM_ComMIndicationType;
#endif /* (STD_ON == BSWM_COMM_ENABLED) */

#if (STD_ON == BSWM_CANSM_ENABLED)
/**
 * @brief This is an indication of the current state of the CAN State Manager.
 * @req    ECUC_BswM_00857
 */
typedef struct
{
	/**< @brief This is a reference to the CAN channel handle that the mode request
	 *          corresponds to.*/
	CONST(NetworkHandleType, BSWM_CONFIG_DATA) BswMCanSMChannelRef;
} BswM_CanSMIndicationType;
#endif /* (STD_ON == BSWM_CANSM_ENABLED) */

#if (STD_ON == BSWM_CANSM_ICOM_ENABLED)
/**
 * @brief This is an indication from CanSM of the configuration Id of the Icom configuration.
 */
typedef struct
{
	/**< @brief When this parameter is set to true, then this mode request source
	 *          corresponds to error indications from the CanSM. Otherwise, this mode
	 *          request source corresponds to error-free indications from the CanSM.
	 */
	CONST(boolean, BSWM_CONFIG_DATA) BswMCanSMIcomIndicationSwitchError;

	/**< @brief This is a reference to the CAN channel handle that the mode request corresponds to.*/
	CONST(NetworkHandleType, BSWM_CONFIG_DATA) BswMCanSMChannelRef;
} BswM_CanSMIcomIndicationType;
#endif /* (STD_ON == BSWM_CANSM_ICOM_ENABLED) */


/**
 * @brief This is a mode request source emanating from another BSW Module.
 * @req    ECUC_BswM_00926
 */
typedef struct
{
	/**< @brief This is a foreign reference to the Mode Declaration Group Prototype.*/
	/*@todo  Mode Declaration Group Prototype is not supported at this time.*/
	P2CONST(void, BSWM_CONFIG_DATA, RTE_APPL_CONST) pBswMBswModeDeclarationGroupPrototypeRef;
} BswM_BswModeNotificationType;

/**
 * @brief This indicates that another BswM has switched a mode. This container is
 *         only relevant for multi-partition systems.
 * @req    ECUC_BswM_00982
 * @note  obsolete
 */
typedef struct
{
	/**< @brief This is a foreign reference to the Mode Declaration Group Prototype.*/
	/* @todo  No support for Mode Declaration Group Prototype is not supported at this time.*/
	P2CONST(void, BSWM_CONFIG_DATA, RTE_APPL_CONST) pBswMBswMModeDeclarationGroupRef;
} BswM_BswMModeSwitchNotificationType;

/**
 * @brief The source of the mode request is a BswM on another partition. This
 *         container is only relevant for multi-partition systems.
 * @req    ECUC_BswM_00980
 * @note  obsolete
 */
typedef struct
{
	/**< @brief This is a foreign reference to the Mode Declaration Group Prototype.*/
	/* @todo  No support for Mode Declaration Group Prototype is not supported at this time.*/
	P2CONST(void, BSWM_CONFIG_DATA, RTE_APPL_CONST) pBswMBswMModeDeclarationGroupRef;
} BswM_BswMModeRequestType;


/*====================================================================================================*
 *                                    GLOBAL VARIABLE DECLARATIONS
 *====================================================================================================*/


/*====================================================================================================*
 *                                        FUNCTION PROTOTYPES
 *====================================================================================================*/

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */
/** @} */

#endif /* #ifndef BSWM_MODEREQUESTSOURCETYPE_H */
