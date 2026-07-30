/**
 * @file        LinIf.h
 * @brief       AUTOSAR LinIf.h  - LinIf.h header file.
 * @details     LinIf driver header file, containing the Autosar API specification and
 *              other variables and functions that are exported by the LinIf driver.
 * @version     1.0.0
 * @addtogroup  LinIf
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

#ifndef LINIF_H
#define LINIF_H

#ifdef __cplusplus
extern "C"{
#endif

/* PRQA S 0292, 0288, 1503, 1505, 0857, 0791, 0828, 0647 EOF #
*
* 1.0292 -- Violates MISRA 2004 Required Rule 3.1, Source file has comments containing one of the
* characters '$', '@' or '`'.
*
* 2.0288 -- Violates MISRA 2004 Required Rule 3.1, Source file has comments containing characters
* which are not members of the basic source character set.
*
* 3.1503 -- Violates MISRA 2004 Required Rule 14.1, The function is defined but is not used within
* this project.
*
* 4.1503 -- Violates MISRA 2004 Required Rule 8.10, The function is only referenced in the translation
* unit where it is defined.
*
* 5.0857 -- Violates MISRA 2004 Required Rule 1.1, Number of macro definitions exceeds 1024 - program
* does not conform strictly to ISO:C90.
*
* 6.0791 -- Violates MISRA 2004 Required Rule 5.1, Macro identifier does not differ from other macro
* identifier(s) within the specified number of significant characters.
*
* 7.0828 -- Violates MISRA 2004 Required Rule 1.1, More than 8 levels of nested conditional inclusion
* - program does not conform strictly to ISO:C90.
*
* 8.0647 -- Violates MISRA 2004 Required Rule 1.1, Number of enumeration constants exceeds 127 -
program
* does not conform strictly to ISO:C90.
*
* @page misra_violations MISRA-C:2004 violations
*/

/* PRQA S 0779 EOF # Violates MISRA 2004 Required Rule 1.2 and 5.1, Identifier does not differ from other
 *                   identifier(s) within the specified number of significant characters.
 *
 */

/*====================================================================================================*
 *                                           INCLUDE FILES
 *====================================================================================================*/
#include "ComStack_Types.h"
#include "Lin_GeneralTypes.h"
#include "LinIf_Cfg.h"
#include "EcuM.h"
#if (LINIF_TRCV_DRIVER_SUPPORTED == STD_ON)
#include "LinTrcv.h"
#endif /* LINIF_TRCV_DRIVER_SUPPORTED == STD_ON */
#if (LINIF_TP_SUPPORTED == STD_ON)
#include "LinTp_Cfg.h"
#endif /* LINIF_TP_SUPPORTED == STD_ON */

/*====================================================================================================*
 *                                  HEADER FILE VERSION INFORMATION
 *====================================================================================================*/

#define LINIF_VENDOR_ID                       0U
#define LINIF_MODULE_ID                       62U
#define LINIF_AR_RELEASE_MAJOR_VERSION        4U
#define LINIF_AR_RELEASE_MINOR_VERSION        2U
#define LINIF_AR_RELEASE_REVISION_VERSION     2U
#define LINIF_SW_MAJOR_VERSION                1U
#define LINIF_SW_MINOR_VERSION                0U
#define LINIF_SW_PATCH_VERSION                0U

/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/
#ifndef  DISABLE_INTERMOD_VERSION_CHECK
/* Check if current file and ComStack_Types header file are of the same Autosar version */
#if(\
	(LINIF_AR_RELEASE_MAJOR_VERSION != COMTYPE_AR_RELEASE_MAJOR_VERSION) || \
	(LINIF_AR_RELEASE_MINOR_VERSION != COMTYPE_AR_RELEASE_MINOR_VERSION) \
	)
#error "AutoSar Version Number of LinIf.h and ComStack_Types.h are different "
#endif

/* Check if current file and Lin_GeneralTypes header file are of the same Autosar version */
#if(\
	(LINIF_AR_RELEASE_MAJOR_VERSION != LIN_GENERALTYPES_AR_RELEASE_MAJOR_VERSION) || \
	(LINIF_AR_RELEASE_MINOR_VERSION != LIN_GENERALTYPES_AR_RELEASE_MINOR_VERSION) \
	)
#error "AutoSar Version Number of LinIf.h and Lin_GeneralTypes.h are different "
#endif
#endif /* DISABLE_INTERMOD_VERSION_CHECK */

/* Check if current file and LinIf_Cfg header file are of the same vendor */
#if(LINIF_INTERNALTYPES_VENDOR_ID != LINIF_CFG_VENDOR_ID )
#error "LinIf.h and LinIf_Cfg.h have different vendor id"
#endif
/* Check if current file and LinIf_Cfg header file are of the same Autosar version */
#if(\
	(LINIF_AR_RELEASE_MAJOR_VERSION != LINIF_CFG_AR_RELEASE_MAJOR_VERSION) || \
	(LINIF_AR_RELEASE_MINOR_VERSION != LINIF_CFG_AR_RELEASE_MINOR_VERSION) || \
	(LINIF_AR_RELEASE_REVISION_VERSION != LINIF_CFG_AR_RELEASE_REVISION_VERSION) \
	)
#error "AutoSar Version Number of LinIf.h and LinIf_Cfg.h are different "
#endif
/* Check if current file and LinIf_Cfg header file are of the same software version */
#if(\
	(LINIF_SW_MAJOR_VERSION != LINIF_CFG_SW_MAJOR_VERSION) || \
	(LINIF_SW_MINOR_VERSION != LINIF_CFG_SW_MINOR_VERSION) || \
	(LINIF_SW_PATCH_VERSION != LINIF_CFG_SW_PATCH_VERSION) \
	)
#error "Software Version Number of LinIf.h and LinIf_Cfg.h are different "
#endif

/*====================================================================================================*
 *                                             CONSTANTS
 *====================================================================================================*/

/* Add code here */

/*====================================================================================================*
 *                                         DEFINES AND MACROS
 *====================================================================================================*/
/**
 * @brief Define transmission layer PID.
 */
#define LINIF_MRF_PID                                                ((uint8)0x3CU)
#define LINIF_SRF_PID                                                ((uint8)0x3DU)

#define LINTP_FRAME_MAX_LEN                                          ((uint8)8U)

/**
 * @brief LinIf Instance Identifier.
 */
#define LINIF_INSTANCE_ID                                            ((uint8)0x00U)

/**
 * @brief LinIf API ID
 */
#define LINIF_SID_INIT                                               ((uint8)0x01U)
#define LINIF_SID_GETVERSIONINFO                                 	 ((uint8)0x03U)
#define LINIF_SID_TRANSMIT                                       	 ((uint8)0x04U)
#define LINIF_SID_SCHEDULEREQUEST                                 	 ((uint8)0x05U)
#define LINIF_SID_GOTOSLEEP                                      	 ((uint8)0x06U)
#define LINIF_SID_WAKEUP                                         	 ((uint8)0x07U)
#define LINIF_SID_SETTRCVMODE                                    	 ((uint8)0x08U)
#define LINIF_SID_GETTRCVMODE                                    	 ((uint8)0x09U)
#define LINIF_SID_GETTRCVWAKEUPREASON                            	 ((uint8)0x0AU)
#define LINIF_SID_SETTRCVWAKEUPREASON                            	 ((uint8)0x0BU)
#define LINIF_SID_GETPIDTABLE                                        ((uint8)0x72U)
#define LINIF_SID_SETPIDTABLE                                        ((uint8)0x73U)
#define LINIF_SID_GETCONFIGUREDNAD                                   ((uint8)0x70U)
#define LINIF_SID_SETCONFIGUREDNAD                                   ((uint8)0x71U)
#define LINIF_SID_CHECKWAKEUP                                    	 ((uint8)0x60U)
#define LINIF_SID_ENABLEBUSMIRRORING                                 ((uint8)0x7FU)
#define LINIF_SID_WAKEUPCONFIRMATION                                 ((uint8)0x61U)
#define LINIF_SID_HEADERINDICATION                                   ((uint8)0x78U)
#define LINIF_SID_RXINDICATION                                       ((uint8)0x79U)
#define LINIF_SID_TXCONFIRMATION                                     ((uint8)0x7AU)
#define LINIF_SID_LINERRORINDICATION                                 ((uint8)0x7BU)
#define LINIF_SID_MAINFUNCTION                                       ((uint8)0x80U)
#define LINTP_SID_INIT                                               ((uint8)0x40U)
#define LINTP_SID_TRANSMIT                                           ((uint8)0x49U)
#define LINTP_SID_GETVERSIONINFO                                 	 ((uint8)0x42U)
#define LINTP_SID_SHUTDOWN                                           ((uint8)0x43U)
#define LINTP_SID_CHANGEPARAMETER                                    ((uint8)0x4BU)

/**
 * @brief LinIf Development Errors
 */
#define LINIF_E_UNINIT                                          	 ((uint8)0x00U)
#define LINIF_E_INIT_FAILED                                     	 ((uint8)0x10U)
#define LINIF_E_NONEXISTENT_CHANNEL                             	 ((uint8)0x20U)
#define LINIF_E_PARAMETER                                       	 ((uint8)0x30U)
#define LINIF_E_PARAM_POINTER                                   	 ((uint8)0x40U)
#define LINIF_E_SCHEDULE_REQUEST_ERROR                          	 ((uint8)0x51U)
#define LINIF_E_TRCV_INV_MODE                                   	 ((uint8)0x53U)
#define LINIF_E_TRCV_NOT_NORMAL                                 	 ((uint8)0x54U)
#define LINIF_E_PARAM_WAKEUPSOURCE                              	 ((uint8)0x55U)
#define LINIF_E_RESPONSE                                        	 ((uint8)0x60U)
#define LINIF_E_NC_NO_RESPONSE                                  	 ((uint8)0x61U)

#define LINIF_VALIDATE_GLOBAL_CALL                                   (LINIF_DEV_ERROR_DETECT)
#define LINIF_PARAM_CHECK                                            (LINIF_DEV_ERROR_DETECT)

/**
 * @brief The NULL_SCHEDULE
 */
#define NULL_SCHEDULE                                           	 ((LinIf_SchHandleType)0x00U)

/**
 * @brief The compiler abstraction for pointer to pointer to variable.
 */
#ifndef  P2P2VAR
#define  P2P2VAR(ptrtype, memclass, ptrclass) ptrtype **
#endif /* P2P2VAR */

/*====================================================================================================*
 *                                               ENUMS
 *====================================================================================================*/

/* Add code here */

/*====================================================================================================*
 *                                   STRUCTURES AND OTHER TYPEDEFS
 *====================================================================================================*/
/**
 * @brief Index of the schedule table that is selectable and followed by LIN Interface.
 * 		  Value is unique per LIN channel/controller, but not per ECU.
 * @req [SWS_LinIf_00197]
 */
typedef uint8 LinIf_SchHandleType;

/**
 * @brief Indicate the type of LinCheckWakeup function entry pointer.
 */
typedef P2FUNC(Std_ReturnType, LINIF_CODE, LinIf_LinCheckWakeupType)(VAR(uint8, AUTOMATIC) Channel);

/**
 * @brief Indicate the type of LinIf_LinSendFrame function entry pointer.
 */
typedef P2FUNC(Std_ReturnType, LINIF_CODE, LinIf_LinSendFrameType)(VAR(uint8, AUTOMATIC) Channel, \
        P2VAR(Lin_PduType, AUTOMATIC, LINIF_APPL_DATA) PduInfoPtr);

/**
 * @brief Indicate the type of LinIf_LinGoToSleep function entry pointer.
 */
typedef P2FUNC(Std_ReturnType, LINIF_CODE, LinIf_LinGoToSleepType)(VAR(uint8, AUTOMATIC) Channel);

/**
 * @brief Indicate the type of LinIf_LinGoToSleepInternal function entry pointer.
 */
typedef P2FUNC(Std_ReturnType, LINIF_CODE, LinIf_LinGoToSleepInternalType)(VAR(uint8, AUTOMATIC) Channel);

/**
 * @brief Indicate the type of LinIf_LinWakeup function entry pointer.
 */
typedef P2FUNC(Std_ReturnType, LINIF_CODE, LinIf_LinWakeupType)(VAR(uint8, AUTOMATIC) Channel);

/**
 * @brief Indicate the type of LinIf_LinWakeupInternal function entry pointer.
 */
typedef P2FUNC(Std_ReturnType, LINIF_CODE, LinIf_LinWakeupInternalType)(VAR(uint8, AUTOMATIC) Channel);

/**
 * @brief Indicate the type of LinIf_LinGetStatus function entry pointer.
 */
typedef P2FUNC(Lin_StatusType, LINIF_CODE, LinIf_LinGetStatusType)(VAR(uint8, AUTOMATIC) Channel, \
		P2P2VAR(uint8, AUTOMATIC, LINIF_APPL_DATA) Lin_SduPtr);

#if (LINIF_TRCV_DRIVER_SUPPORTED == STD_ON)
/**
 * @brief Indicate the type of LinTrcvSetOpMode function entry pointer.
 */
typedef P2FUNC(Std_ReturnType, LINIF_CODE, LinIf_LinTrcvSetOpModeType)(\
		VAR(uint8, AUTOMATIC) LinNetWork,VAR(LinTrcv_TrcvModeType,AUTOMATIC)OpMode);

/**
 * @brief Indicate the type of LinTrcvGetOpMode function entry pointer.
 */
typedef P2FUNC(Std_ReturnType, LINIF_CODE, LinIf_LinTrcvGetOpModeType)(\
		VAR(uint8, AUTOMATIC) LinNetWork,P2VAR(LinTrcv_TrcvModeType,AUTOMATIC,LINIF_APPL_DATA)OpMode);

/**
 * @brief Indicate the type of LinTrcvGetBusWuReason function entry pointer.
 */
typedef P2FUNC(Std_ReturnType, LINIF_CODE, LinIf_LinTrcvGetBusWuReasonType)(\
		VAR(uint8, AUTOMATIC) LinNetWork,P2VAR(LinTrcv_TrcvWakeupReasonType,AUTOMATIC,LINIF_APPL_DATA)Reason);

/**
 * @brief Indicate the type of LinTrcvCheckWakeup function entry pointer.
 */
typedef P2FUNC(Std_ReturnType, LINIF_CODE, LinIf_LinTrcvCheckWakeupType)(VAR(uint8, AUTOMATIC) LinNetWork);

/**
 * @brief Indicate the type of LinTrcvSetWakeupMode function entry pointer.
 */
typedef P2FUNC(Std_ReturnType, LINIF_CODE, LinIf_LinTrcvSetWakeupModeType)(\
		VAR(uint8, AUTOMATIC) LinNetWork,VAR(LinTrcv_TrcvWakeupModeType,AUTOMATIC)TrcvWakupMode);
#endif /* LINIF_TRCV_DRIVER_SUPPORTED == STD_ON */

//@todo
/**
 * @brief Indicate the type of <user>_GotoSleepConfirmation function entry pointer.
 */
typedef P2FUNC(void, LINIF_CODE, LinIf_GotoSleepConfirmationType)(VAR(NetworkHandleType, AUTOMATIC) Channel,
		VAR(boolean, AUTOMATIC) success);

/**
 * @brief Indicate the type of <user>_GotoSleepIndication function entry pointer.
 */
typedef P2FUNC(void, LINIF_CODE, LinIf_GotoSleepIndicationType)(VAR(NetworkHandleType, AUTOMATIC) Channel);

/**
 * @brief Indicate the type of <user>_ScheduleRequestConfirmation function entry pointer.
 */
typedef P2FUNC(void, LINIF_CODE, LinIf_ScheduleRequestConfirmationType)(VAR(NetworkHandleType, AUTOMATIC) Channel,\
		VAR(LinIf_SchHandleType, AUTOMATIC) schedule);

/**
 * @brief Indicate the type of <user>_WakeupConfirmation function entry pointer.
 */
typedef P2FUNC(void, LINIF_CODE, LinIf_WakeupConfirmationType)(VAR(NetworkHandleType, AUTOMATIC) Channel,\
		VAR(boolean, AUTOMATIC) success);

/**
 * @brief Indicate the type of <user>_RxIndication function entry pointer.
 */
typedef P2FUNC(void,LINIF_CODE,LinIf_RxIndicationType)(VAR(PduIdType,AUTOMATIC)RxPduId , \
		P2CONST(PduInfoType,AUTOMATIC,LINIF_APPL_CONST)PduInfoPtr);

/**
 * @brief Indicate the type of <user>_TxConfirmation function entry pointer.
 */
typedef P2FUNC(void,LINIF_CODE,LinIf_TxConfirmationType)(VAR(PduIdType,AUTOMATIC)TxPduId) ;

/**
 * @brief Indicate the type of <user>_TxConfirmation function entry pointer.
 */
typedef P2FUNC(Std_ReturnType,LINIF_CODE,LinIf_TxTriggerTransmitType)(VAR(PduIdType,AUTOMATIC) TxPduId, \
		  P2VAR(PduInfoType,AUTOMATIC,LINIF_APPL_DATA)PduInfoPtr) ;

/**
 * @brief The upper layer(UL)module.
 * @req [SWS_LinIf_00601]、[SWS_LinIf_00602]、[SWS_LinIf_00600]、[SWS_LinIf_00652]
 */
typedef enum{
	LINIF_CDD			= 0x00U,	/**< @brief Complex Driver. */
	LINIF_LIN_SM    	= 0x01U,    /**< @brief LIN State Manager. */
	LINIF_PDUR          = 0x02U,    /**< @brief Pdu Router. */
	LINIF_NONE          = 0x03U     /**< @brief None modeule */
} LinIf_ULModuleType;

/**
 * @brief The LIN node type of channel.
 * @req [SWS_LinIf_00654]
 */
typedef enum {
	LINIF_MASTER_NODE 	= 0x00U,	/**< @brief Master Node. */
	LINIF_SLAVE_NODE    = 0x01U     /**< @brief Slave Node. */
}LinIf_NodeType;

/**
 * @brief Type of checksum that the frame is using.
 * @req [SWS_LinIf_00005]
 */
typedef enum{
	LINIF_CLASSIC 		= 0x00U,	/**< @brief Classic  */
	LINIF_ENHANCED    	= 0x01U		/**< @brief Enhanced */
} LinIf_ChecksumType;

/**
 * @brief Type of frame that the frame is using.
 * @req [SWS_LinIf_00017]
 */
typedef enum{
	LINIF_ASSIGN        			= 0x00U,    /**< @brief AssignFrameId */
	LINIF_ASSIGN_FRAME_ID_RANGE     = 0x01U,    /**< @brief AssignFrameIdRange */
	LINIF_ASSIGN_NAD                = 0x02U,    /**< @brief AssignNAD */
	LINIF_CONDITIONAL               = 0x03U,    /**< @brief Conditional Change NAD */
	LINIF_EVENT_TRIGGERED           = 0x04U,    /**< @brief Event triggered frame */
	LINIF_FREE                      = 0x05U,    /**< @brief FreeFormat */
	LINIF_MRF                       = 0x06U,    /**< @brief Master Request Frame */
	LINIF_SAVE_CONFIGURATION        = 0x07U,    /**< @brief SaveConfiguration */
	LINIF_SPORADIC                  = 0x08U,    /**< @brief Sporadic slot */
	LINIF_SRF                       = 0x09U,    /**< @brief Slave Response Frame */
	LINIF_UNASSIGN                  = 0x0AU,    /**< @brief UnassignFrameId */
	LINIF_UNCONDITIONAL             = 0x0BU     /**< @brief Unconditional Frame */
}LinIf_FrameType;

/**
 * @brief Direction of the frame.
 * @req [SWS_LinIf_00027]
 */
typedef enum{
	/**< @brief Represents a Diagnostic or Configuration frame : no Message ID (no PduId). */
	LINIF_INTERNAL_PDU              = 0x00U,
	/**< @brief represents a received PDU/frame. */
	LINIF_RX_PDU                    = 0x01U,
	/**< @brief Represents a slave-to-slave PDU/frame. */
	LINIF_SLAVE_TO_SLAVE_PDU        = 0x02U,
	/**< @brief represents a transmitted PDU/frame. */
	LINIF_TX_PDU                    = 0x03U
}LinIf_PduDirectionType;

/**
 * @brief Defines where a schedule table shall proceed in
 * 		  case it has been interrupted by a RUN_ONCE table.
 * @req [SWS_LinIf_00033]
 */
typedef enum{
	/**< @brief Continue schedule table where it was interrupted.. */
	LINIF_CONTINUE_AT_IT_POINT		= 0x00U,
	/**< @brief Start schedule table from the beginning.. */
	LINIF_START_FROM_BEGINNING      = 0x01U
} LinIf_ResumePositionType;

/**
 * @brief The schedule table can be executed in two different modes.
 * @req [SWS_LinIf_00034]
 */
typedef enum{
	/**< @brief Scheduling table continuous execution. */
	LINIF_RUN_CONTINUOUS           = 0x00U,
	/**< @brief Scheduling table once execution. */
	LINIF_RUN_ONCE                 = 0x01U
}LinIf_RunModeType;

/**
 * @brief Defines the LIN protocol version of the slave node.
 * @req [SWS_LinIf_00647]
 */
typedef enum{
	LINIF_ISO17987                = 0x00U,
	LINIF_LIN13                  = 0x01U,
	LINIF_LIN20                  = 0x02U,
	LINIF_LIN21                  = 0x03U,
	LINIF_LIN22                  = 0x04U
}LinIf_LinProtocolVersionType;

typedef struct LinIf_ScheduleTableCfg   LinIf_ScheduleTableType;
typedef struct LinIf_FrameCfg           LinIf_FrameCfgType;

typedef struct LinIf_SlaveNodeCfg
{
	/**
	 *  @brief Defines the LIN protocol version of the slave node.
	 */
	CONST(LinIf_LinProtocolVersionType,AUTOMATIC) LinIfLinProtocolVersion;

	/**
	 *  @brief Reference to the response_error signal.
	 */
	CONST(uint16,AUTOMATIC)  LinIfResponseErrorSignal;

	/**
	 *  @brief Slave node configured NAD.
	 */
	CONST(uint8,AUTOMATIC) LinIfConfiguredNAD ;

	/**
	 *  @brief LIN function Id.
	 */
	CONST(uint16,AUTOMATIC) LinIfFunctionId ;

	/**
	 *  @brief Slave node initial NAD.
	 */
	CONST(uint8,AUTOMATIC) LinIfInitialNAD ;

	/**
	 *  @brief N_As timeout in milliseconds.
	 */
	CONST(uint16,AUTOMATIC)  LinIfNasTimeout;

	/**
	 *  @brief LIN consortium or ISO LIN supplier Id.
	 */
	CONST(uint16,AUTOMATIC) LinIfSupplierId ;

	/**
	 *  @brief LIN variant Id.
	 */
	CONST(uint8,AUTOMATIC) LinIfVariantId ;

} LinIf_SlaveNodeCfgType;

typedef struct LinIf_SubstitutionFramesCfg
{
	/**
	 *  @brief Priority of sporadic frame in a master node
	 *         or of event-triggered frame in slave node.
	 */
	CONST(uint8, AUTOMATIC) LinIfFramePriority;

	/**
	 *  @brief Reference to an unconditional Frame that is used as sporadic
	 *         frame in a master node or event-triggered frame in a slave node.
	 */
	P2CONST(LinIf_FrameCfgType,AUTOMATIC,LINIF_APPL_CONST) LinIfSubstitutionFrameRef;

	/**
	 *  @brief The index value in the channel replacement frame table.
	 */
	CONST(uint16, AUTOMATIC) LinIfSubtitutionIndex;

}LinIf_SubstitutionFramesCfgType;

typedef struct LinIf_FixedFrameSduCfg
{
	/**
	 *  @brief Index of the Byte in the SDU (response) 8 byte array
	 */
	CONST(uint8, AUTOMATIC) LinIfFixedFrameSduBytePos;

	/**
	 *  @brief Byte value in the SDU (response) 8-byte array.
	 */
	CONST(uint8, AUTOMATIC) LinIfFixedFrameSduByteVal;

} LinIf_FixedFrameSduCfgType;

typedef struct LinIf_RxPduCfg
{
	/**
	 *  @brief This parameter defines the upper layer (UL) module to which
	 *         the indication of the successfully received LinIfRxPdu has to be routed via
	 *         User_RxIndication
	 */
	CONST(LinIf_ULModuleType,AUTOMATIC) LinIfUserRxIndicationUL;

	/**
	 *  @brief This parameter defines the name of the User_RxIndication
	 */
	LinIf_RxIndicationType  LinIfRxIndication;

	/**
	 *  @brief Reference to the PDU that is received in this frame.
	 */
	CONST(PduIdType,AUTOMATIC) LinIfRxPduRef;
} LinIf_RxPduCfgType;

typedef struct LinIf_TxPduCfg
{
	/**
	 *  @brief This parameter defines the upper layer (UL) module to which the trigger
	 *         of the transmitted LinTxPdu User_TriggerTransmit
	 *         the confirmation of the successfully transmitted LinTxPdu has to be routed
	 *         User_TxConfirmation
	 */
	CONST(LinIf_ULModuleType,AUTOMATIC) LinIfUserTxUL;

	/**
	 *  @brief his parameter defines the name of the User_TxConfirmation
	 */
	LinIf_TxConfirmationType  LinIfTxConfirmationUL;

	/**
	 *  @brief Identifier of the Pdu for the upper layer.
	 */
	CONST(uint16,AUTOMATIC) LinIfTxPduId;

	/**
	 *  @brief his parameter defines the name of the User_TriggerTransmit
	 */
	LinIf_TxTriggerTransmitType  LinIfTxTriggerTransmitUL;

	/**
	 *  @brief Reference to the PDU that is transmitted in this frame.
	 */
	CONST(PduIdType,AUTOMATIC) LinIfTxPduRef;
} LinIf_TxPduCfgType;

typedef struct LinIf_FrameCfg
{
	/**
	 *  @brief Type of checksum that the frame is using.
	 */
	CONST(LinIf_ChecksumType, AUTOMATIC) LinIfChecksumType;

	/**
	 *  @brief ID of the LIN frame. The Protected ID including parity
	 *         is calculated by the generation tool.
	 */
	CONST(uint8, AUTOMATIC) LinIfFrameId;

	/**
	 *  @brief Protection ID identifier calculated by the tool.
	 */
	CONST(uint8, AUTOMATIC) LinIfFramePID;

	/**
	 *  @brief PID index of the frame. This index is used in the
	 *         AssignFrameIdentifierRange node configuration service to
	 *         identify the frame(s) to which a new PID shall be assigned.
	 */
	CONST(uint8, AUTOMATIC) LinIfFrameIndex;

	/**
	 *  @brief Index value of the LIN frame Length.
	 */
	CONST(uint8, AUTOMATIC) LinIfFrameLength;

	/**
	 *  @brief Index value of the LIN frame in the PID table.
	 */
	CONST(uint16, AUTOMATIC) LinIfFrameTableIndex;

	/**
	 *  @brief Does the frame contain a response error signal.
	 */
	CONST(boolean,AUTOMATIC) LinIfFrameIncludeResponseSignal;

	/**
	 *  @brief This parameter defines the type of frame (e.g. sporadic frame).
	 */
	CONST(LinIf_FrameType, AUTOMATIC) LinIfFrameType;

	/**
	 *  @brief In case this is a fixed frame this is the SDU (response).
	 *         This container represents an eight byte array.
	 *         The Byte order shall be MSB first.
	 */
	P2CONST(LinIf_FixedFrameSduCfgType,AUTOMATIC,LINIF_APPL_CONST) LinIfFixedFrameSdu;

	/**
	 *  @brief Direction of the frame.
	 */
	CONST(LinIf_PduDirectionType,AUTOMATIC) LinIfPduDirection;

	/**
	 *  @brief represents a received PDU/frame
	 */
	P2CONST(LinIf_RxPduCfgType,AUTOMATIC,LINIF_APPL_CONST) LinIfRxPdu;

	/**
	 *  @brief represents a transmitted PDU/frame
	 */
	P2CONST(LinIf_TxPduCfgType,AUTOMATIC,LINIF_APPL_CONST) LinIfTxPdu;

	/**
	 *  @brief The maximum number of associated unconditional frames.
	 */
	CONST(uint16 ,AUTOMATIC) LinIfMaxSubstitutionFramesNum ;

	/**
	 *  @brief Reference to an unconditional Frame that is used as
	 *         sporadic frame in a master node or event-triggered
	 *         frame in a slave node.
	 */
	P2CONST(LinIf_SubstitutionFramesCfgType,AUTOMATIC,LINIF_APPL_CONST) LinIfSubstitutionFrames;
}LinIf_FrameConfigType;

typedef struct LinIf_EntryCfg
{
	/**
	 *  @brief Delay to next entry in schedule table in milliseconds.
	 */
	CONST(uint16, AUTOMATIC) LinIfDelay;

	/**
	 *  @brief Position of the Frame Entry in the Schedule Table.
	 */
	CONST(uint16, AUTOMATIC) LinIfEntryIndex;

	/**
	 *  @brief Reference to the schedule table, which resolves the collision.
	 */
	P2CONST(LinIf_ScheduleTableType,AUTOMATIC,LINIF_APPL_CONST) LinIfCollisionResolvingRef;

	/**
	 *  @brief Reference to the frames that belong to this schedule table entry.
	 */
	P2CONST(LinIf_FrameCfgType,AUTOMATIC,LINIF_APPL_CONST) LinIfFrameRef;

} LinIf_EntryCfgType;

typedef struct LinIf_ScheduleTableCfg
{
	/**
	 *  @brief Defines where a RUN_CONTINUOUS schedule table shall
	 *         proceed in case it has been interrupted by a RUN_ONCE table.
	 */
	CONST(LinIf_ResumePositionType, AUTOMATIC) LinIfResumePosition;

	/**
	 *  @brief The schedule table can be executed in two different modes.
	 */
	CONST(LinIf_RunModeType, AUTOMATIC) LinIfRunMode;

	/**
	 *  @brief This is the unique index used by upper layers to identify a schedule
	 */
	CONST(uint8, AUTOMATIC) LinIfScheduleTableIndex;

	/**
	 *  @brief The number of entries in the scheduling table.
	 */
	CONST(uint16, AUTOMATIC) LinIfMaxEntryNum;

	/**
	 * 	@brief Describes an entry in the schedule table (also known as Frame Slot).
	 */
	P2CONST(LinIf_EntryCfgType,AUTOMATIC,LINIF_APPL_CONST) LinIfEntry;

}LinIf_ScheduleTableCfgType;

typedef struct LinIf_ChannelConfigCfg
{
	/**< @brief Bus idle timeout cycle. */
	CONST(uint16, AUTOMATIC) LinIfBusIdleTimeoutPeriod;

	/**
	 *  @brief This parameter defines the upper layer (UL) module
	 *         to which the confirmation of the goto-sleep command
	 *         shall be sent.
	 */
	CONST(LinIf_ULModuleType,AUTOMATIC) LinIfGotoSleepConfirmationUL;

	LinIf_GotoSleepConfirmationType   LinIfGotoSleepConfirmation;

	/**
	 *  @brief This parameter defines the upper layer (UL) module
	 *         to which the indication of the goto-sleep command
	 *         shall be sent.
	 */
	CONST(LinIf_ULModuleType,AUTOMATIC) LinIfGotoSleepIndicationUL;

	LinIf_GotoSleepIndicationType   LinIfGotoSleepIndication;

	/**
	 *  @brief Defines the interval of calls to main functions per channel in milliseconds.
	 */
	CONST(uint32, AUTOMATIC) LinIfMainFunctionPeriod;

	/**
	 *  @brief Maximum number of Frames
	 */
	CONST(uint16, AUTOMATIC) LinIfMaxFrameCnt;

	/**
	 *  @brief Enables/disables the switch to a new schedule table at the start of
	 *         the next time base after status check.
	 */
	CONST(boolean, AUTOMATIC) LinIfScheduleChangeNextTimeBase;

	/**
	 *  @brief This parameter defines the upper layer (UL) module to which the confirmation
	 *         of the successfully performed schedule table change shall be sent.
	 */
	CONST(LinIf_ULModuleType,AUTOMATIC) LinIfScheduleRequestConfirmationUL;

	LinIf_ScheduleRequestConfirmationType LinIfScheduleRequestConfirmation;

	/**
	 *  @brief This parameter defines the upper layer (UL) module to which the confirmation
	 *         of the wake-up shall be sent.
	 */
	CONST(LinIf_ULModuleType,AUTOMATIC) LinIfWakeupConfirmationUL;

	LinIf_WakeupConfirmationType LinIfWakeupConfirmation;

	/**
	 *  @brief Reference to the CDD module description.
	 */
	CONST(uint16,AUTOMATIC) LinIfCddRef;

	/**< @brief Reference to the channel definition in the LIN driver */
	CONST(uint8,AUTOMATIC) LinIfChannelRef;

	/**< @brief Reference Index values belonging to different LIN drivers. */
	CONST(uint8,AUTOMATIC) LinIfChannelRefIndex;

	/**< @brief The wake-up source configured for the current channel. */
	CONST(EcuM_WakeupSourceType,AUTOMATIC) LinIfWakeUpSource;

	/**
	 *  @brief Unique handle to identify one LIN network. Reference to one of the
	 *         network handles configured for the ComM.
	 */
	CONST(NetworkHandleType,AUTOMATIC) LinIfComMNetworkHandleIdRef;

	/**
	 *  @brief The maximum number of replacement frames that the channel can have..
	 */
	CONST(uint16 ,AUTOMATIC) LinIfMaxSporOrEventFramesNum ;

	/**
	 *  @brief The maximum number of data frames that the channel can have.
	 */
	CONST(uint16 ,AUTOMATIC) LinIfMaxFramesNum ;

	/**
	 *  @brief The configuration set of data frames that the channel has.
	 */
	P2CONST(LinIf_FrameCfgType,AUTOMATIC,LINIF_APPL_CONST) LinIfFrames;

	/**
	 *  @brief defines the LIN node type of this channel.
	 */
	CONST(LinIf_NodeType ,AUTOMATIC) LinIfNodeType ;

	/**
	 *  @brief The jitter specifies the differences between the maximum and minimum delay
	 *         from time base tick to the header sending start point in milliseconds.
	 */
	CONST(uint16 ,AUTOMATIC) LinIfJitter ;

	/**
	 * 	@brief Describes all parameters which are only relevant for a LIN Slave node.
	 */
	P2CONST(LinIf_SlaveNodeCfgType,AUTOMATIC,LINIF_APPL_CONST) LinIfSlaveNode;

	/**
	 *  @brief The maximum number of scheduling tables that the channel can have.
	 */
	CONST(uint8,AUTOMATIC) LinIfMaxScheduleTableNum;

	/**
	 * 	@brief Describes a schedule table. Each LinIfChannel may have several
	 *         schedule tables. Each schedule table can only be connected to
	 *         one channel.
	 */
	P2CONST(LinIf_ScheduleTableType,AUTOMATIC,LINIF_APPL_CONST)LinIfScheduleTable;

#if (LINIF_TRCV_DRIVER_SUPPORTED == STD_ON)
	/**
	 *  @brief Logical handle of the underlying LIN transceiver to be served by the LIN Interface.
	 */
	CONST(uint8,AUTOMATIC) LinIfTrcvIdRef;

	/**< @brief Reference Index values belonging to different LIN transceiver drivers. */
	CONST(uint8,AUTOMATIC) LinIfTrcvRefIndex;
#endif /*  LINIF_TRCV_DRIVER_SUPPORTED == STD_ON */
}LinIf_ChannelConfigCfgType;

/**
 * @brief Definition of Function Pointer Types for API Function Using the LIN Driver.
 * @req [SWS_LinIf_00462]
 */
typedef struct LinIf_LinDriverApiCfg
{
	/**< @brief Validates for upper layers the wake up of LIN channel.. */
	LinIf_LinCheckWakeupType LinCheckWakeup;

	/**< @brief Sends a LIN frame.. */
	LinIf_LinSendFrameType LinSendFrame;

	/**< @brief The service instructs the driver to transmit a
	 * 	go-to-sleep-command on the addressed LIN channel.
	 */
	LinIf_LinGoToSleepType LinGoToSleep;

	/**< @brief Put a Lin channel in the internal sleep state.. */
	LinIf_LinGoToSleepInternalType LinGoToSleepInternal;

	/**< @brief Generates a wake up pulse.. */
	LinIf_LinWakeupType LinWakeup;

	/**< @brief Wake up the LIN channel.. */
	LinIf_LinWakeupInternalType LinWakeupInternal;

	/**< @brief Gets the status of the LIN driver.. */
	LinIf_LinGetStatusType LinGetStatus;
}LinIf_LinDriverApiCfgType;

#if (LINIF_TRCV_DRIVER_SUPPORTED == STD_ON)
/**
 * @brief Definition of Function Pointer Types for API Function Using the LIN Transceiver Driver.
 */
typedef struct LinIf_LinTransDriverApiCfg
{
	/**< @brief The internal state of the LIN transceiver driver
	 *          is switched to mode given in the parameter OpMode.
	 */
	LinIf_LinTrcvSetOpModeType LinTrcvSetOpMode;

	/**< @brief API detects the actual software state of LIN transceiver driver. */
	LinIf_LinTrcvGetOpModeType LinTrcvGetOpMode;

	/**< @brief This API provides the reason for the wakeup that the LIN transceiver
	 *          has detected in the parameter "Reason".
	 */
	LinIf_LinTrcvGetBusWuReasonType LinTrcvGetBusWuReason;

	/**< @brief Notifies the calling function if a wakeup is detected. */
	LinIf_LinTrcvCheckWakeupType LinTrcvCheckWakeup;

	/**< @brief This API enables, disables and clears the notification for
	 *          wakeup events on the addressed network..
	 */
	LinIf_LinTrcvSetWakeupModeType LinTrcvSetWakeupMode;

}LinIf_LinTransDriverApiCfgType;
#endif /* LINIF_TRCV_DRIVER_SUPPORTED == STD_ON */

/**
 * @brief A pointer to an instance of this structure will be used in the initialization of
 * 		 the LIN Interface.
 * @req [SWS_LinIf_00668]
 */
typedef struct LinIf_ConfigCfg
{
	/**< @brief Total number of configured master node channels. */
	CONST(uint16,AUTOMATIC) LinIfMasterChannelNum;

	/**< @brief Total number of configured Slave node channels. */
	CONST(uint16,AUTOMATIC) LinIfSlaveChannelNum;

	/**< @brief LIN Driver API table used by LINIF */
	P2CONST(LinIf_LinDriverApiCfgType,AUTOMATIC,LINIF_APPL_CONST) LinIfLinApi;

#if (LINIF_TRCV_DRIVER_SUPPORTED == STD_ON)
	/**< @brief LIN Transceiver Driver API table used by LINIF */
	P2CONST(LinIf_LinTransDriverApiCfgType,AUTOMATIC,LINIF_APPL_CONST) LinIfLinTrcvApi;
#endif /* LINIF_TRCV_DRIVER_SUPPORTED == STD_ON */

	/**< @brief Configure the specific parameter information for LinIf Master channles */
	P2CONST(LinIf_ChannelConfigCfgType,AUTOMATIC,LINIF_APPL_CONST) LinIfMasterChannel;

	/**< @brief Configure the specific parameter information for LinIf Slave channles */
	P2CONST(LinIf_ChannelConfigCfgType,AUTOMATIC,LINIF_APPL_CONST) LinIfSlaveChannel;

}LinIf_ConfigType;

#if (LINIF_TP_SUPPORTED == STD_ON)
typedef struct
{
	/**< @brief Configures if TP Frames of not requested LIN-Slaves are dropped or not. */
	CONST(boolean,AUTOMATIC) LinTpDropNotRequestedNad;

	/**< @brief Configures the maximum number of allowed response pending frames.
	 *          Only used for LIN Master nodes, ignored for slave nodes.
	 */
	CONST(uint16,AUTOMATIC) LinTpMaxNumberOfRespPendingFrames;

	/**< @brief P2*max timeout when a response pending frame is expected in milliseconds.
	 *          Only used for LIN Master nodes, ignored for slave nodes
	 */
	CONST(uint16,AUTOMATIC) LinTpP2Max;

	/**< @brief Definition of the P2max timeout observation parameter in milliseconds.
	 *          Only used for LIN Master nodes, ignored for slave nodes
	 */
	CONST(uint16,AUTOMATIC) LinTpP2Timing;

	/**< @brief Enables or disables the call of BswM_LinTp_RequestMode() to diagnostic
	 *          request/response schedule.
	 *          Only used for LIN Master nodes, ignored for slave nodes
	 */
	CONST(boolean,AUTOMATIC) LinTpScheduleChangeDiag;

	/**< @brief Index of the channel this LinTp channel belongs to.*/
	CONST(NetworkHandleType,AUTOMATIC) LinTpChannelRef;

	/**< @brief Index of the channel this LinTp channel belongs to.*/
	CONST(uint16,AUTOMATIC) LinIfChannelRef;

}LinTp_ChannelConfigType;

typedef struct
{
	/**< @brief N_Cr timeout enable switch.*/
	CONST(boolean,AUTOMATIC) LinTpNcrSwitch;

	/**< @brief Value in milliseconds of the N_Cr timeout. N_Cr is the time until
	 *          reception of the next Consecutive Frame N_PDU.
	 */
	CONST(uint16,AUTOMATIC) LinTpNcr;

	/**< @brief The identifier of the Transport Protocol message. This ID will be
	 *          used by upper layers to call LinTp_ChangeParameter.
	 */
	CONST(PduIdType,AUTOMATIC) LinTpRxNSduId;

	/**< @brief A N-SDU transported on LIN is identified using the NAD for the specific slave.*/
	CONST(uint16,AUTOMATIC) LinTpRxNSduNad;

	/**< @brief Index of the channel this N-SDU belongs to.*/
	CONST(NetworkHandleType,AUTOMATIC) LinTpRxNSduChannelRef;

	/**< @brief Reference to the global PDU.*/
	CONST(PduIdType,AUTOMATIC) LinTpRxNSduPduRef;
}LinTp_RxNSduType;

typedef struct
{
	/**< @brief This parameter defines the maximum number of times the LinTp should
	 *          request upper layer for the Tx Buffer. It is also used to limit the
	 *          number of retries for PduR_LinTpCopyTxData when no timer is active.
	 */
	CONST(uint8,AUTOMATIC) LinTpMaxBufReq;

	/**< @brief Value in seconds of the N_As timeout. N_As is the time for transmission of
	 *          a LIN frame (any N_PDU) on the part of the sender.
	 */
	CONST(uint16,AUTOMATIC) LinTpNas;

	/**< @brief N_Cs timeout enable switch.*/
	CONST(boolean,AUTOMATIC) LinTpNcsSwitch;

	/**< @brief Value in seconds of the performance requirement of N_Cs. N_Cs is the
	 *          time which elapses between the transmit request of a CF N-PDU until the
	 *          transmit request of the next CF N-PDU.
	 */
	CONST(uint16,AUTOMATIC) LinTpNcs;

	/**< @brief The identifier of the Transport Protocol message. This ID will be the
	 *          one that is communicated with upper layers..*/
	CONST(PduIdType,AUTOMATIC) LinTpTxNSduId;

	/**< @brief A N-SDU transported on LIN is identified using the NAD for the specific slave.*/
	CONST(uint16,AUTOMATIC) LinTpTxNSduNad;

	/**< @brief Index of the channel this N-SDU belongs to.*/
	CONST(NetworkHandleType,AUTOMATIC) LinTpTxNSduChannelRef;

	/**< @brief Reference to the global PDU.*/
	CONST(PduIdType,AUTOMATIC) LinTpTxNSduPduRef;

}LinTp_TxNSduType;

typedef struct
{
	/**< @brief LinTp Channel configuration. */
	P2CONST(LinTp_ChannelConfigType,AUTOMATIC,LINIF_APPL_CONST) LinTpChannel;

	/**< @brief Rx NSdu Configuration for LinTp. */
	P2CONST(LinTp_RxNSduType,AUTOMATIC,LINIF_APPL_CONST) LinTpRxNSdu;

	/**< @brief Tx NSdu Configuration for LinTp. */
	P2CONST(LinTp_TxNSduType,AUTOMATIC,LINIF_APPL_CONST) LinTpTxNSdu;
}LinTp_ConfigType;
#endif /* LINIF_TP_SUPPORTED == STD_ON */


/*====================================================================================================*
 *                                    GLOBAL VARIABLE DECLARATIONS
 *====================================================================================================*/

LINIF_CONF_PB

#if (LINIF_TP_SUPPORTED == STD_ON)
LINTP_CONF_PB
#endif /* LINIF_TP_SUPPORTED == STD_ON */

/*====================================================================================================*
 *                                        FUNCTION PROTOTYPES
 *====================================================================================================*/
FUNC(void,LINIF_CODE)LinIf_Init
(
	P2CONST(LinIf_ConfigType, AUTOMATIC, LINIF_APPL_CONST)ConfigPtr
);

#if (LINIF_VERSION_INFO_API == STD_ON)
FUNC(void,LINIF_CODE)LinIf_GetVersionInfo
(
	P2VAR(Std_VersionInfoType, AUTOMATIC, LINIF_APPL_DATA) versioninfo
);
#endif /* LINIF_VERSION_INFO_API == STD_ON */

FUNC(Std_ReturnType,LINIF_CODE)LinIf_Transmit
(
    VAR(PduIdType,AUTOMATIC) LinTxPduId,
    P2CONST(PduInfoType,AUTOMATIC,LINIF_APPL_CONST) PduInfoPtr
);

FUNC(Std_ReturnType,LINIF_CODE)LinIf_GotoSleep
(
	VAR(NetworkHandleType,AUTOMATIC) Channel
);

FUNC(Std_ReturnType,LINIF_CODE)LinIf_Wakeup
(
	VAR(NetworkHandleType,AUTOMATIC) Channel
);

#if (LINIF_TRCV_DRIVER_SUPPORTED == STD_ON)
FUNC(Std_ReturnType,LINIF_CODE)LinIf_SetTrcvMode
(
	VAR(NetworkHandleType,AUTOMATIC) Channel,
	VAR(LinTrcv_TrcvModeType,AUTOMATIC) TransceiverMode
);

FUNC(Std_ReturnType,LINIF_CODE)LinIf_GetTrcvMode
(
	VAR(NetworkHandleType,AUTOMATIC) Channel,
	P2VAR(LinTrcv_TrcvModeType,AUTOMATIC,LINIF_APPL_DATA) TransceiverModePtr
);

FUNC(Std_ReturnType,LINIF_CODE)LinIf_GetTrcvWakeupReason
(
	VAR(NetworkHandleType,AUTOMATIC) Channel,
	P2VAR(LinTrcv_TrcvWakeupReasonType,AUTOMATIC,LINIF_APPL_DATA) TrcvWuReasonPtr
);

FUNC(Std_ReturnType,LINIF_CODE)LinIf_SetTrcvWakeupMode
(
	VAR(NetworkHandleType,AUTOMATIC) Channel,
	VAR(LinTrcv_TrcvWakeupModeType,AUTOMATIC) LinTrcvWakeupMode
);
#endif /* LINIF_TRCV_DRIVER_SUPPORTED == STD_ON */

FUNC(Std_ReturnType,LINIF_CODE)LinIf_CheckWakeup
(
	VAR(EcuM_WakeupSourceType,AUTOMATIC) WakeupSource
);

FUNC(Std_ReturnType,LINIF_CODE)LinIf_EnableBusMirroring
(
    VAR(NetworkHandleType,AUTOMATIC) Channel,
    VAR(boolean,AUTOMATIC) MirroringActive
);

#if (LINIF_USED_SLAVE_NODE == STD_ON)
FUNC(Std_ReturnType,LINIF_CODE)LinIf_GetPIDTable
(
    VAR(NetworkHandleType,AUTOMATIC) Channel,
    P2VAR(Lin_FramePidType,AUTOMATIC,LINIF_APPL_DATA) PidBuffer,
	P2VAR(uint8,AUTOMATIC,LINIF_APPL_DATA) PidBufferLength
);

FUNC(Std_ReturnType,LINIF_CODE)LinIf_SetPIDTable
(
    VAR(NetworkHandleType,AUTOMATIC) Channel,
    P2VAR(Lin_FramePidType,AUTOMATIC,LINIF_APPL_DATA) PidBuffer,
	VAR(uint8,AUTOMATIC) PidBufferLength
);

FUNC(Std_ReturnType,LINIF_CODE)LinIf_GetConfiguredNAD
(
    VAR(NetworkHandleType,AUTOMATIC) Channel,
	P2VAR(uint8, AUTOMATIC,LINIF_APPL_DATA) Nad
);

FUNC(Std_ReturnType,LINIF_CODE)LinIf_SetConfiguredNAD
(
    VAR(NetworkHandleType,AUTOMATIC) Channel,
	VAR(uint8, AUTOMATIC) Nad
);
#endif /* LINIF_USED_SLAVE_NODE == STD_ON */

#if (LINIF_TP_SUPPORTED == STD_ON)
FUNC(void,LINIF_CODE) LinTp_Init
(
	P2CONST(LinTp_ConfigType,AUTOMATIC,LINIF_APPL_CONST) ConfigPtr
);

FUNC(Std_ReturnType,LINIF_CODE) LinTp_Transmit
(
    VAR(PduIdType,AUTOMATIC) TxPduId,
    P2CONST(PduInfoType,AUTOMATIC,LINIF_APPL_CONST) PduInfoPtr
);

#if(LINTP_VERSION_INFO_API == STD_ON)
FUNC(void,LINIF_CODE)LinTp_GetVersionInfo
(
	P2VAR(Std_VersionInfoType, AUTOMATIC, LINIF_APPL_DATA) versioninfo
);
#endif /* LINTP_VERSION_INFO_API == STD_ON */

FUNC(void,LINIF_CODE)LinTp_Shutdown(void);

#if (LINTP_CHANGE_PARAMETER_API == STD_ON)
FUNC(Std_ReturnType,LINIF_CODE)LinTp_ChangeParameter
(
    VAR(PduIdType,AUTOMATIC) id,
    VAR(TPParameterType,AUTOMATIC) parameter,
    VAR(uint16,AUTOMATIC) value
);
#endif /* LINTP_CHANGE_PARAMETER_API == STD_ON */
#endif /* LINIF_TP_SUPPORTED == STD_ON */

FUNC(void,LINIF_CODE) LinIf_MainFunction(void);

#ifdef __cplusplus
}
#endif

#endif /* xxx_H */
/** @} */
