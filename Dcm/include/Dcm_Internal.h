/**
 * @file        Dcm_Internal.h
 * @brief       AUTOSAR 4.2.2 - 4.2.2 driver header file.
 * @details     Dcm driver header file, containing the Autosar API specification and
 *              other variables and functions that are exported by the Dcm driver.
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

#ifndef DCM_INTERNAL_H
#define DCM_INTERNAL_H

#ifdef __cplusplus
extern "C"{
#endif

/* PRQA S 3453, 0750 EOF #
 *
 * 1.3453 -- Violates MISRA 2004 Required Rule 19.7, A function could probably be used instead of this
 * function-like macro.
 *
 * 2.0750 -- Violates MISRA 2004 Required Rule 18.4, A union type specifier has been defined.
 *
 * @page misra_violations MISRA-C:2004 violations
 */

/*====================================================================================================*
 *                                           INCLUDE FILES
 *====================================================================================================*/
#include "Dcm.h"
#include "Dcm_Externals.h"
#include "Dem.h"
#include "NvM.h"
#include "Dem_Dcm.h"
#include "BswM_Dcm.h"
#include "PduR_Dcm.h"
#include "ComM_Dcm.h"
#include "SchM_Dcm.h"
/*====================================================================================================*
 *                                  HEADER FILE VERSION INFORMATION
 *====================================================================================================*/
#define DCM_INTERNAL_VENDOR_ID	                            (0x00U)
#define DCM_INTERNAL_AR_RELEASE_MAJOR_VERSION	            (0x04U)
#define DCM_INTERNAL_AR_RELEASE_MINOR_VERSION	            (0x02U)
#define DCM_INTERNAL_AR_RELEASE_REVISION_VERSION	        (0x02U)
#define DCM_INTERNAL_SW_MAJOR_VERSION	                    (0x01U)
#define DCM_INTERNAL_SW_MINOR_VERSION	                    (0x02U)
#define DCM_INTERNAL_SW_PATCH_VERSION	                    (0x00U)
/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/
/* Check if current file and Dcm header file are of the same vendor */
#if(DCM_INTERNAL_VENDOR_ID != DCM_VENDOR_ID )
#error "Dcm_Internal.h and Dcm.h have different vendor id"
#endif
/* Check if current file and Dcm header file are of the same Autosar version */
#if(\
		(DCM_INTERNAL_AR_RELEASE_MAJOR_VERSION != DCM_AR_RELEASE_MAJOR_VERSION) || \
		(DCM_INTERNAL_AR_RELEASE_MINOR_VERSION != DCM_AR_RELEASE_MINOR_VERSION) || \
		(DCM_INTERNAL_AR_RELEASE_REVISION_VERSION != DCM_AR_RELEASE_REVISION_VERSION) \
)
#error "AutoSar Version Number of Dcm_Internal.h and Dcm.h are different"
#endif
/* Check if current file and Dcm header file are of the same software version */
#if(\
		(DCM_INTERNAL_SW_MAJOR_VERSION != DCM_SW_MAJOR_VERSION) || \
		(DCM_INTERNAL_SW_MINOR_VERSION != DCM_SW_MINOR_VERSION) || \
		(DCM_INTERNAL_SW_PATCH_VERSION != DCM_SW_PATCH_VERSION) \
)
#error "Software Version Number of Dcm_Internal.h and Dcm.h are different"
#endif
/* Check if current file and Dcm_Externals header file are of the same vendor */
#if(DCM_INTERNAL_VENDOR_ID != DCM_EXTERNALS_VENDOR_ID )
#error "Dcm_Internal.h and Dcm_Externals.h have different vendor id"
#endif
/* Check if current file and Dcm_Externals header file are of the same Autosar version */
#if(\
		(DCM_INTERNAL_AR_RELEASE_MAJOR_VERSION != DCM_EXTERNALS_AR_RELEASE_MAJOR_VERSION) || \
		(DCM_INTERNAL_AR_RELEASE_MINOR_VERSION != DCM_EXTERNALS_AR_RELEASE_MINOR_VERSION) || \
		(DCM_INTERNAL_AR_RELEASE_REVISION_VERSION != DCM_EXTERNALS_AR_RELEASE_REVISION_VERSION) \
)
#error "AutoSar Version Number of Dcm_Internal.h and Dcm_Externals.h are different"
#endif
/* Check if current file and Dcm_Externals header file are of the same software version */
#if(\
		(DCM_INTERNAL_SW_MAJOR_VERSION != DCM_EXTERNALS_SW_MAJOR_VERSION) || \
		(DCM_INTERNAL_SW_MINOR_VERSION != DCM_EXTERNALS_SW_MINOR_VERSION) || \
		(DCM_INTERNAL_SW_PATCH_VERSION != DCM_EXTERNALS_SW_PATCH_VERSION) \
)
#error "Software Version Number of Dcm_Internal.h and Dcm_Externals.h are different"
#endif

#ifndef DISABLE_INTERMOD_VERSION_CHECK
/* Check if current file and Dem header file are of the same Autosar version */
#if(\
		(DCM_INTERNAL_AR_RELEASE_MAJOR_VERSION != DEM_AR_RELEASE_MAJOR_VERSION) || \
		(DCM_INTERNAL_AR_RELEASE_MINOR_VERSION != DEM_AR_RELEASE_MINOR_VERSION) \
)
#error "AutoSar Version Number of Dcm_Internal.h and Dem.h are different"
#endif
/* Check if current file and NvM header file are of the same Autosar version */
#if(\
		(DCM_INTERNAL_AR_RELEASE_MAJOR_VERSION != NVM_AR_RELEASE_MAJOR_VERSION) || \
		(DCM_INTERNAL_AR_RELEASE_MINOR_VERSION != NVM_AR_RELEASE_MINOR_VERSION) \
)
#error "AutoSar Version Number of Dcm_Internal.h and NvM.h are different"
#endif
/* Check if current file and Dem_Dcm header file are of the same Autosar version */
#if(\
		(DCM_INTERNAL_AR_RELEASE_MAJOR_VERSION != DEM_DCM_AR_RELEASE_MAJOR_VERSION) || \
		(DCM_INTERNAL_AR_RELEASE_MINOR_VERSION != DEM_DCM_AR_RELEASE_MINOR_VERSION) \
)
#error "AutoSar Version Number of Dcm_Internal.h and Dem_Dcm.h are different"
#endif
/* Check if current file and BswM_Dcm header file are of the same Autosar version */
#if(\
		(DCM_INTERNAL_AR_RELEASE_MAJOR_VERSION != BSWM_DCM_AR_RELEASE_MAJOR_VERSION) || \
		(DCM_INTERNAL_AR_RELEASE_MINOR_VERSION != BSWM_DCM_AR_RELEASE_MINOR_VERSION) \
)
#error "AutoSar Version Number of Dcm_Internal.h and BswM_Dcm.h are different"
#endif
/* Check if current file and PduR_Dcm header file are of the same Autosar version */
#if(\
		(DCM_INTERNAL_AR_RELEASE_MAJOR_VERSION != PDUR_DCM_AR_RELEASE_MAJOR_VERSION) || \
		(DCM_INTERNAL_AR_RELEASE_MINOR_VERSION != PDUR_DCM_AR_RELEASE_MINOR_VERSION) \
)
#error "AutoSar Version Number of Dcm_Internal.h and PduR_Dcm.h are different"
#endif
/* Check if current file and ComM_Dcm header file are of the same Autosar version */
#if(\
		(DCM_INTERNAL_AR_RELEASE_MAJOR_VERSION != COMM_DCM_AR_RELEASE_MAJOR_VERSION) || \
		(DCM_INTERNAL_AR_RELEASE_MINOR_VERSION != COMM_DCM_AR_RELEASE_MINOR_VERSION) \
)
#error "AutoSar Version Number of Dcm_Internal.h and ComM_Dcm.h are different"
#endif
/* Check if current file and SchM_Dcm header file are of the same Autosar version */
#if(\
		(DCM_INTERNAL_AR_RELEASE_MAJOR_VERSION != SCHM_DCM_AR_RELEASE_MAJOR_VERSION) || \
		(DCM_INTERNAL_AR_RELEASE_MINOR_VERSION != SCHM_DCM_AR_RELEASE_MINOR_VERSION) \
)
#error "AutoSar Version Number of Dcm_Internal.h and SchM_Dcm.h are different"
#endif
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
 * @brief	Reception status during the process of receiving a diagnostic request.
 */
typedef enum
{
	/**< @brief Idle reception state: No diagnostic request is currently being received. */
	DCM_RX_STATE_IDLE = 0u,
	/**< @brief Diagnostic request should be copied or is being copied. */
	DCM_RX_STATE_COPY,
	/**< @brief Diagnostic request reception is complete. */
	DCM_RX_STATE_RECEIVED,
	/**< @brief Diagnostic request need to process. */
	DCM_RX_STATE_PROCESS,
	/**< @brief Diagnostic request is processing. */
	DCM_RX_STATE_PROCESSING
}Dcm_RxStatusType;

/**
 * @brief	Transmission status during the process of sending a diagnostic response.
 */
typedef enum
{
	/**< @brief Idle transmission state: No diagnostic response is currently being sent. */
	DCM_TX_STATE_IDLE = 0u,
	/**< @brief Diagnostic response should be copied or is being copied. */
	DCM_TX_STATE_COPY,
	/**< @brief Diagnostic response transmission should be confirmation. */
	DCM_TX_STATE_CONFIRM,
	/**< @brief Waiting for the communication mode to switch to full-communication mode. */
	DCM_TX_STATE_WAITING
}Dcm_TxStatusType;

/**
 * @brief	Diagnostic active status of the connection.
 */
typedef enum
{
	/**< @brief Active diagnostic state. */
	DCM_COMM_ACTIVE = 0u,
	/**< @brief Inactive diagnostic state. */
	DCM_COMM_NOT_ACTIVE
}DCM_DiagnositcStatusType;

/**
 * @brief	Connection communication status.
 */
typedef enum
{
	/**< @brief No-Communication mode. */
	DCM_COMM_NO_COMMUNICATION = 0u,
	/**< @brief Silent-Communication mode. */
	DCM_COMM_SILENT_COMMUNICATION,
	/**< @brief Full-Communication mode. */
	DCM_COMM_FULL_COMMUNICATION
}Dcm_CommunicationStatusType;

/**
 * @brief	User type for performing permission checks.
 */
typedef enum
{
	/**< @brief Service execution permission check. */
	DCM_PERMISSION_CHECK_USER_SERVICE = 0u,
	/**< @brief Sub-Service execution permission check. */
	DCM_PERMISSION_CHECK_USER_SUBSERVICE,
	/**< @brief Read Did data execution permission check. */
	DCM_PERMISSION_CHECK_USER_READ_DID,
	/**< @brief Write Did data execution permission check. */
	DCM_PERMISSION_CHECK_USER_WRITE_DID,
	/**< @brief Control I/O state via Did execution permission check. */
	DCM_PERMISSION_CHECK_USER_CONTROL_DID,
	/**< @brief Dynamically define Did execution permission check. */
	DCM_PERMISSION_CHECK_USER_DYNAMICALLY_DEFINE_DID,
	/**< @brief Dynamically define Did execution permission check. */
	DCM_PERMISSION_CHECK_USER_SCALING_DID,
	/**< @brief Routine execution permission check. */
	DCM_PERMISSION_CHECK_USER_ROUTINE,
	/**< @brief Read or write memory execution permission check. */
	DCM_PERMISSION_CHECK_USER_MEMORY
}Dcm_PermissionCheckUserType;

#if((STD_ON == DCM_UDS0x34_ENABLE) || (STD_ON == DCM_UDS0x35_ENABLE))
/**
 * @brief	Status during the download and upload processes.
 */
typedef enum
{
	/**< @brief Download and upload idle. */
	DCM_TRANSFER_IDLE = 0u,
#if(STD_ON == DCM_UDS0x34_ENABLE)
	/**< @brief Download state. */
	DCM_TRANSFER_DOWNLOAD,
#endif /* #if(STD_ON == DCM_UDS0x34_ENABLE) */
#if(STD_ON == DCM_UDS0x35_ENABLE)
	/**< @brief Upload state. */
	DCM_TRANSFER_UPLOAD,
#endif /* #if(STD_ON == DCM_UDS0x35_ENABLE) */
	/**< @brief Download or upload execution completed, exiting data transfer. */
	DCM_TRANSFER_EXIT
}Dcm_TransferProcessType;
#endif /* #if((STD_ON == DCM_UDS0x34_ENABLE) || (STD_ON == DCM_UDS0x35_ENABLE)) */
/*====================================================================================================*
 *                                   STRUCTURES AND OTHER TYPEDEFS
 *====================================================================================================*/
/**
 * @brief	S3 timer status.
 */
typedef struct
{
	/**< @brief Whether the timer is enabled. */
	boolean TimerEnable;
	/**< @brief Current timer value. */
	uint16 CurrentTime;
}Dcm_S3TimerStatusType;

/**
 * @brief	P2 timer status.
 */
typedef struct
{
	/**< @brief Whether the timer is enabled. */
	boolean TimerEnable;
	/**< @brief Current timer value. */
	uint16 CurrentTime;
	/**< @brief Timer timeout value. */
	uint16 TimeoutTime;
#if(STD_ON == DCM_DSP_SESSION_TIM_P2_PENDING_WINDOW)
	/**< @brief Pending timer timeout value. */
	uint16 PendingThreshold;
#endif /* #if(STD_ON == DCM_DSP_SESSION_TIM_P2_PENDING_WINDOW) */
}Dcm_P2TimerStatusType;

#if(0u != DCM_DSL_DIAG_RESP_MAX_NUM_RESP_PEND)
/**
 * @brief	P2* timer status.
 */
typedef struct
{
	/**< @brief Whether the timer is enabled. */
	boolean TimerEnable;
	/**< @brief Whether it is permissible to send a pending message. */
	boolean PendingNRCSendState;
	/**< @brief Whether the pending service can be executed. */
	boolean PendingProcessState;
	/**< @brief Current number of pending instances. */
	uint8 PendingCnt;
	/**< @brief Current timer value. */
	uint32 CurrentTime;
	/**< @brief Timer timeout value. */
	uint32 TimeoutTime;
}Dcm_P2StarTimerStatusType;
#endif /* #if(0u != DCM_DSL_DIAG_RESP_MAX_NUM_RESP_PEND) */

#if((STD_ON == DCM_DSD_SERVICE_P4_TIMER_ENABLE) || (STD_ON == DCM_DSD_SUB_SERVICE_P4_TIMER_ENABLE))
/**
 * @brief	P4 timer status.
 */
typedef struct
{
	/**< @brief Whether the timer is enabled. */
	boolean TimerEnable;
	/**< @brief Current timer value. */
	uint32 CurrentTime;
	/**< @brief Timer timeout value. */
	uint32 TimeoutTime;
}Dcm_P4TimerStatusType;
#endif /* #if((STD_ON == DCM_DSD_SERVICE_P4_TIMER_ENABLE) || (STD_ON == DCM_DSD_SUB_SERVICE_P4_TIMER_ENABLE)) */

/**
 * @brief	Connection status.
 */
typedef struct
{
	/**< @brief Whether concurrent "TesterPresent" is triggered.  */
	boolean Concurrent3E;
	/**< @brief Index of the currently executing service. */
	uint8 ServiceIdx;
	/**< @brief ID of the currently executing service. */
	uint8 ServiceId;
	/**< @brief Reception state. */
	Dcm_RxStatusType RxState;
	/**< @brief Transmission state. */
	Dcm_TxStatusType TxState;
	/**< @brief Remaining length of data to be received or transmitted. */
	PduLengthType RemainLen;
	/**< @brief Buffer offset during reception or transmission. */
	PduLengthType CopyOffset;
	/**< @brief NRC when an error occurs. */
	Dcm_NegativeResponseCodeType NRC;
	/**< @brief Service processing interface. */
	Dcm_DsdServiceFncType ServiceFnc;
}Dcm_ConnectionStatusType;

/**
 * @brief	Connection communication status.
 */
typedef struct
{
	/**< @brief Diagnostic active state. */
	DCM_DiagnositcStatusType DiagnosticState;
	/**< @brief Communication mode. */
	Dcm_CommunicationStatusType CommunicationState;
}Dcm_ComMStatusType;

#if(STD_ON == DCM_UDS0x19_ENABLE)
/**
 * @brief	Status during the process of reading DTC information.
 */
typedef struct
{
	/**< @brief Whether DTC updates are disabled. */
	boolean DisableDTCUpdate;
	/**< @brief Whether requested the single record data. */
	boolean SingleRecordNum;
	/**< @brief Sub-Function ID. */
	uint8 SubId;
	/**< @brief Record number. */
	uint8 RecordNum;
#if((STD_ON == DCM_UDS0x19_SUB0x19_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x18_ENABLE))
	/**< @brief DTC origin. */
	Dem_DTCOriginType DTCOrigin;
#endif /* #if((STD_ON == DCM_UDS0x19_SUB0x19_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x18_ENABLE)) */
	/**< @brief Each bit represents a calling step, where setting 1 indicates being pending at that
	 * 			step. the steps represented by each bit are as follows:
	 * 			Bit0: Dem_DcmGetNumberOfFilteredDTC().
	 * 			Bit1: Dem_DcmGetNextFilteredDTC().
	 * 			Bit2: Dem_DcmGetNextFilteredDTCAndSeverity().
	 * 			Bit3: Dem_DcmGetSeverityOfDTC().
	 * 			Bit4: Dem_DcmGetFunctionalUnitOfDTC().
	 * 			Bit5: Dem_DcmGetStatusOfDTC().
	 * 			Bit6: Dem_DcmDisableDTCRecordUpdate().
	 * 			Bit7: Dem_DcmGetSizeOfExtendedDataRecordSelection().
	 * 			Bit8: Dem_DcmGetNextExtendedDataRecord().
	 * 			Bit9: Dem_DcmGetSizeOfFreezeFrameSelection().
	 * 			Bit10: Dem_DcmGetNextFreezeFrameData().
	 * 			Bit11: Dem_DcmGetNextFilteredRecord().  */
	uint16 PendStep;
	/**< @brief Number of remaining DTCs to be read. */
	uint16 RemainDTCNum;
	/**< @brief Remaining length of data to be read. */
	uint16 RemainDataSize;
	/**< @brief Request DTC. */
	uint32 DTC;
}Dcm_ReadDTCInfoStatusType;
#endif /* #if(STD_ON == DCM_UDS0x19_ENABLE) */

#if(STD_ON == DCM_UDS0x22_ENABLE)
/**
 * @brief	Status during the process of reading Did data.
 */
typedef struct
{
#if(0u != DCM_DSP_DATA_BLOCK_USED_NUM)
	/**< @brief Whether the NvM_ReadBlock() has been called. */
	boolean ReadBlock;
#endif /* #if(0u != DCM_DSP_DATA_BLOCK_USED_NUM) */
	/**< @brief Index of the Did currently being read. */
	uint8 ReqDidIndex;
	/**< @brief Index of the signal for the Did currently being read. */
	uint8 ReqSignalIndex;
#if(STD_ON == DCM_UDS0x2C_ENABLE)
	/**< @brief Signal index of the DDDid currently being processed. */
	uint8 ReqElementIndex;
#endif /* #if(STD_ON == DCM_UDS0x2C_ENABLE) */
	/**< @brief Number of Dids successfully read. */
	uint8 ReadDidNum;
	/**< @brief Identifier of the Did currently being read. */
	uint16 ReqDid;
	/**< @brief Actual length of the Did data read. */
	uint32 DidDataLen;
	/**< @brief Total data length of all Dids to read. */
	uint32 DataTotalLen;
	/**< @brief Data of the Did currently being read. */
	uint8 DidData[DCM_DSP_DID_DATA_MAX_SIZE];
}Dcm_ReadDataByDidStatusType;
#endif /* #if(STD_ON == DCM_UDS0x22_ENABLE) */

#if(STD_ON == DCM_UDS0x2E_ENABLE)
/**
 * @brief	Status during the process of writing Did data.
 */
typedef struct
{
#if(0u != DCM_DSP_DATA_BLOCK_USED_NUM)
	/**< @brief Whether the NvM_WriteBlock() has been called. */
	boolean WriteBlock;
#endif /* #if(0u != DCM_DSP_DATA_BLOCK_USED_NUM) */
	/**< @brief Index of the signal for the Did currently being write. */
	uint8 ReqSignalIndex;
	/**< @brief Identifier of the Did currently being write. */
	uint16 ReqDid;
	/**< @brief Dynamic data Length of the signal. */
	uint16 SignalDynLen;
}Dcm_WriteDataByDidStatusType;
#endif /* #if(STD_ON == DCM_UDS0x2E_ENABLE) */

#if(STD_ON == DCM_UDS0x2F_ENABLE)
/**
 * @brief	Status during the process of controlling Did.
 */
typedef struct
{
	/**< @brief Each bit represents a calling step. */
	uint8 PendStep;
	/**< @brief Control parameter type. */
	uint8 ControlType;
	/**< @brief Index of the signal for the Did currently being control. */
	uint8 ReqSignalIndex;
	/**< @brief Identifier of the Did currently being control. */
	uint16 ReqDid;
	/**< @brief Control mask. */
	uint32 ReqMask;
	/**< @brief Total data length of all Dids to control. */
	uint32 DataTotalLen;
}Dcm_InputOutputControlByDidStatusType;
#endif /* #if(STD_ON == DCM_UDS0x2F_ENABLE) */

#if((STD_ON == DCM_UDS0x23_ENABLE) || (STD_ON == DCM_UDS0x3D_ENABLE))
/**
 * @brief	Status during the process of reading form or writing to memory.
 */
typedef struct
{
#if(STD_ON == DCM_UDS0x3D_ENABLE)
	/**< @brief Offset in the reuqest buffer during memory write oprations. */
	uint8 DataOffset;
#endif /* #if(STD_ON == DCM_UDS0x3D_ENABLE) */
	/**< @brief Memory ID. */
	uint8 MemoryId;
	/**< @brief Memory address. */
	uint32 MemoryAddr;
	/**< @brief Memory size. */
	uint32 MemorySize;
}Dcm_RwMemoryStatusType;
#endif /* #if((STD_ON == DCM_UDS0x23_ENABLE) || ((STD_ON == DCM_UDS0x3D_ENABLE))) */

#if(STD_ON == DCM_UDS0x27_ENABLE)
/**
 * @brief	Status during the security access initialization process.
 */
typedef struct
{
	/**< @brief Whether security access initialization is completed. */
	boolean InitState;
	/**< @brief Whether the timer is enabled. */
	boolean TimerEnable;
#if(STD_ON == DCM_DSP_SECURITY_ATTEMPT_COUNTER_ENABLED)
	/**< @brief Number of security access instances that have completed initialization. */
	uint8 AlreadyInitNum;
#endif /* #if(STD_ON == DCM_DSP_SECURITY_ATTEMPT_COUNTER_ENABLED) */
	/**< @brief Current timer value. */
	uint32 CurrentTime;
}Dcm_SecurityInitStatusType;

/**
 * @brief	Security access status.
 */
typedef struct
{
	/**< @brief Whether delay is enabled. */
	boolean DelayState;
	/**< @brief Whether the timer is enabled. */
	boolean TimerEnable;
	/**< @brief Number of failed attempts. */
	uint8 AttemptCnt;
	/**< @brief Current timer value. */
	uint32 CurrentTime;
	/**< @brief Timer timeout value. */
	uint32 TimeoutTime;
}Dcm_SecurityStatusType;
#endif /* #if(STD_ON == DCM_UDS0x27_ENABLE) */

#if(STD_ON == DCM_UDS0x2A_ENABLE)
/**
 * @brief	Status of each DID in the scheduler table.
 */
typedef struct
{
	/**< @brief MainConnection index. */
	uint8 MainConIndex;
	/**< @brief Periodic transmission rate of this DID. */
	uint8 Rate;
	/**< @brief Periodic transmission timer. */
	uint8 Timer;
	/**< @brief Periodic transmission DID. */
	uint8 PDid;
#if(STD_ON == DCM_UDS0x2C_ENABLE)
	/**< @brief Whether is DDDid or not. */
	uint8 PDidType;
	/**< @brief Index of the periodic transmission DDDid. */
	uint8 PDDDidIndex;
#endif /* #if(STD_ON == DCM_UDS0x2C_ENABLE) */
	/**< @brief Index of Periodic transmission DID. */
	uint8 PDidIndex;
	/**< @brief Diagnostic session permission for this Periodic transmission DID. */
	Dcm_SessionDataType SesLevelRef;
	/**< @brief Diagnostic security permission for this Periodic transmission DID. */
	Dcm_SecurityDataType SecLevelRef;
	/**< @brief Data for this Periodic transmission DID. */
	uint8 DidData[8];
	/**< @brief Data length of this Periodic transmission DID. */
	uint16 DataLen;
#if(STD_ON == DCM_DSP_DATA_READ_DATA_LENGTH_FNC_ENABLED)
	/**< @brief Dynamic data length of this Periodic transmission DID. */
	uint16 DynDataLen;
#endif /* #if(STD_ON == DCM_DSP_DATA_READ_DATA_LENGTH_FNC_ENABLED) */
}Dcm_SchedulerTableType;

/**
 * @brief	Periodic transmission status.
 */
typedef struct
{
	/**< @brief Number of valid DIDs in the scheduler table. */
	uint8 PDidNum;
	/**< @brief Number of valid DIDs in the scheduler table. */
	uint8 PDidInsertIndex;
	/**< @brief Each bit represents a channel, where a set bit (1) indicates that the channel is
	 * 			currently in use. */
	uint16 ChannelStatus;
	/**< @brief Scheduler table. */
	Dcm_SchedulerTableType SchedulerTable[DCM_DSP_MAX_PERIODIC_DID_SCHEDULER];
}Dcm_PeriodicTransStatusType;

typedef struct
{
	/**< @brief Periodic transmission DID. */
	uint8 PDid;
#if(STD_ON == DCM_UDS0x2C_ENABLE)
	/**< @brief Whether is DDDid or not. */
	uint8 PDidType;
	/**< @brief Index of the periodic transmission DDDid. */
	uint8 PDDDidIndex;
#endif /* #if(STD_ON == DCM_UDS0x2C_ENABLE) */
	/**< @brief Index of Periodic transmission DID. */
	uint8 PDidIndex;
	/**< @brief Diagnostic session permission for this Periodic transmission DID. */
	Dcm_SessionDataType SesLevelRef;
	/**< @brief Diagnostic security permission for this Periodic transmission DID. */
	Dcm_SecurityDataType SecLevelRef;
	/**< @brief Data length of this Periodic transmission DID. */
	uint16 DataLen;
#if(STD_ON == DCM_DSP_DATA_READ_DATA_LENGTH_FNC_ENABLED)
	/**< @brief Dynamic data length of this Periodic transmission DID. */
	uint16 DynDataLen;
#endif /* #if(STD_ON == DCM_DSP_DATA_READ_DATA_LENGTH_FNC_ENABLED) */
}Dcm_TruncSchedulerTableType;

/**
 * @brief	Status during the process of reading data by periodic Did.
 */
typedef struct
{
	/**< @brief Whether it is pending. */
	boolean PendState;
	/**< @brief Requested rate. */
	uint8 ReqRate;
	/**< @brief Actual number of DIDs requested. */
	uint8 ReqDidNum;
	/**< @brief Index of the Did currently being process. */
	uint8 ReqDidIndex;
#if(STD_ON == DCM_UDS0x2C_ENABLE)
	/**< @brief Whether is DDDid or not. */
	uint8 ReqDidType;
	/**< @brief Index of DDDid. */
	uint8 ReqDDDidIndex;
#endif /* #if(STD_ON == DCM_UDS0x2C_ENABLE) */
	/**< @brief Index of the signal for the Did currently being process. */
	uint8 ReqSignalIndex;
#if(STD_ON == DCM_UDS0x2C_ENABLE)
	/**< @brief Signal index of the DDDid currently being processed. */
	uint8 ReqElementIndex;
#endif /* #if(STD_ON == DCM_UDS0x2C_ENABLE) */
	/**< @brief Index of the pending Did. */
	uint8 PendDidIndex;
	/**< @brief Number of valid periodic Dids. */
	uint8 ValidPDidNum;
	/**< @brief Scheduler table free size. */
	uint8 FreeSize;
	/**< @brief Diagnostic session mode permission for the Did currently being processed. */
	Dcm_SessionDataType ReqDidSesLevelRef;
	/**< @brief Diagnostic security mode permission for the Did currently being processed. */
	Dcm_SecurityDataType ReqDidSecLevelRef;
	/**< @brief Requested Did's data length. */
	uint16 ReqDidDataLen;
#if(STD_ON == DCM_DSP_DATA_READ_DATA_LENGTH_FNC_ENABLED)
	/**< @brief Requested Did's dynamic data length. */
	uint16 ReqDidDynDataLen;
#endif /* #if(STD_ON == DCM_DSP_DATA_READ_DATA_LENGTH_FNC_ENABLED) */
	/**< @brief Valid periodic Did's information. */
	Dcm_TruncSchedulerTableType NewPDidInfo[DCM_DSP_MAX_PERIODIC_DID_SCHEDULER];
}Dcm_ReadDataByPDidStatusType;
#endif /* #if(STD_ON == DCM_UDS0x2A_ENABLE) */

#if(STD_ON == DCM_UDS0x2C_ENABLE)
/**
 * @brief	Element status of DDDid.
 */
typedef struct
{
	/**< @brief Element type. */
	boolean IsDidType;
	/**< @brief Element session reference. */
	Dcm_SessionDataType SesLevelRef;
	/**< @brief Element security reference. */
	Dcm_SecurityDataType SecLevelRef;
	/**< @brief Element status. */
	union{
#if(STD_ON == DCM_UDS0x2C_SUB0x01_ENABLE)
		struct{
			/**< @brief Source Did index. */
			uint8 SrcDidIndex;
			/**< @brief Source Did data offset. */
			uint8 SrcDidDataPos;
			/**< @brief Source Did data length. */
			uint8 SrcDidDataLen;
			/**< @brief Source Did identifier. */
			uint16 Identifier;
		}SrcDid;
#endif /* #if(STD_ON == DCM_UDS0x2C_SUB0x01_ENABLE) */
#if(STD_ON == DCM_UDS0x2C_SUB0x02_ENABLE)
		struct{
			/**< @brief Memory block identifier. */
			uint8 MemoryId;
			/**< @brief Memory block size. */
			uint32 MemorySize;
			/**< @brief Memory block start address. */
			uint32 MemoryAddress;
		}Memory;
#endif /* #if(STD_ON == DCM_UDS0x2C_SUB0x02_ENABLE) */
	}Element;
}Dcm_DDDIdElementStatus;

/**
 * @brief	DDDID status.
 */
typedef struct
{
	/**< @brief Dynamically defined state. */
	boolean DefinedState;
	/**< @brief The number of elements contained in this dynamically defined Did. */
	uint8 ElementNum;
	/**< @brief The array of elements contained in this dynamically defined Did. */
	Dcm_DDDIdElementStatus ElementStatus[DCM_DSP_DDDID_ELEMENT_MAX_NUM];
}Dcm_DDDidStatusType;
#endif /* #if(STD_ON == DCM_UDS0x2C_ENABLE) */

#if(STD_ON == DCM_UDS0x31_ENABLE)
/**
 * @brief	Status during the routine control process.
 */
typedef struct
{
	/**< @brief Dynamic data length of the input signal. */
	uint16 InSignalDynLen;
	/**< @brief Dynamic data length of the output signal. */
	uint16 OutSignalDynLen;
	/**< @brief Total data length of the output signal. */
	uint16 DataTotalLen;
	/**< @brief Pointer to the dynamically sized input signal data. */
	P2VAR(uint8, AUTOMATIC, DCM_CONST)DataInVarPtr;
	/**< @brief Pointer to the dynamically sized output signal data. */
	P2VAR(uint8, AUTOMATIC, DCM_CONST)DataOutVarPtr;
	/**< @brief Pointer to the requested routine configuration. */
	P2CONST(Dcm_DspRoutineType, AUTOMATIC, DCM_CONST)RoutinePtr;
}Dcm_RoutineControlStatusType;
#endif /* #if(STD_ON == DCM_UDS0x31_ENABLE) */

#if((STD_ON == DCM_UDS0x34_ENABLE) || (STD_ON == DCM_UDS0x35_ENABLE))
/**
 * @brief	Status during the download/upload process.
 */
typedef struct
{
	/**< @brief Whether it is the first data block. */
	boolean IsFirstBlock;
#if(STD_ON == DCM_UDS0x34_ENABLE)
	/**< @brief Whether it is the last data block. */
	boolean IsLastBlock;
#endif /* #if(STD_ON == DCM_UDS0x34_ENABLE) */
	/**< @brief Block ID counter. */
	uint8 BlockSeqCnt;
	/**< @brief Memory ID. */
	uint8 MemoryId;
	/**< @brief Memory address. */
	uint32 MemoryAddr;
	/**< @brief Memory size. */
	uint32 MemorySize;
	/**< @brief Data block length. */
	uint32 BlockLength;
	/**< @brief Execution state. */
	Dcm_TransferProcessType Process;
}Dcm_TransferStatusType;
#endif /* #if((STD_ON == DCM_UDS0x34_ENABLE) || (STD_ON == DCM_UDS0x35_ENABLE)) */
/*====================================================================================================*
 *                                    GLOBAL VARIABLE DECLARATIONS
 *====================================================================================================*/
/**
 * @brief 	Store the usage status of the configured protocols. Each bit represents a configured
 * 			protocol, and a set bit (1) indicates that the protocol is currently in use.
 */
extern VAR(uint8, DCM_VAR)Dcm_ProtocolStartState;

/**
 * @brief 	Store the current operating state of the Dcm module.
 */
extern VAR(Dcm_OpStatusType, DCM_VAR)Dcm_OpState;

/**
 * @brief  	Store the index of the currently used connection within the configuration.
 */
extern VAR(uint8, DCM_VAR)Dcm_ActiveConIdx;

/**
 * @brief  	Store the index of the currently used protocol within the configuration.
 */
extern VAR(uint8, DCM_VAR)Dcm_ActiveProRowIdx;

/**
 * @brief	Store the index of the currently active diagnostic session mode within the configuration.
 */
extern VAR(Dcm_SessionDataType, DCM_VAR)Dcm_ActiveSessionIdx;

/**
 * @brief  	Store the index of the currently active diagnostic session mode.
 */
extern VAR(Dcm_SesCtrlType, DCM_VAR)Dcm_ActiveSession;

#if(STD_ON == DCM_UDS0x10_ENABLE)
/**
 * @brief	Store the index of the diagnostic session mode requested for transition within the
 * 			configuration.
 */
extern VAR(Dcm_SessionDataType, DCM_VAR)Dcm_NewActiveSessionIdx;

/**
 * @brief	Store the diagnostic session mode requested for transition.
 */
extern VAR(Dcm_SesCtrlType, DCM_VAR)Dcm_NewActiveSession;
#endif /* #if(STD_ON == DCM_UDS0x10_ENABLE) */

/**
 * @brief  	Store the currently active security access level.
 */
extern VAR(Dcm_SecLevelType, DCM_VAR)Dcm_ActiveSecurity;

#if(STD_ON == DCM_UDS0x27_ENABLE)
/**
 * @brief	Store the index of the security access level requested for unlocking.
 */
extern VAR(Dcm_SecurityDataType, DCM_VAR)Dcm_NewActiveSecurityIdx;

/**
 * @brief	Store the security access level requested for unlocking.
 */
extern VAR(Dcm_SecLevelType, DCM_VAR)Dcm_NewActiveSecurity;
#endif /* #if(STD_ON == DCM_UDS0x27_ENABLE) */

/**
 * @brief  Store the configuration pointer.
 */
extern P2CONST(Dcm_ConfigType, AUTOMATIC, DCM_CONST)Dcm_ConfigPtr;

/**
 * @brief	Store the diagnostic active state and communication state of the channel.
 */
extern VAR(Dcm_ComMStatusType, DCM_VAR)Dcm_ComMStatus[DCM_DSL_MAIN_CONNECTION_NUM];

/**
 * @brief  	Store all relevant information from the receipt of the request to the confirmation of the
 * 			response.
 */
extern VAR(Dcm_MsgContextType, DCM_VAR)Dcm_MsgContext[DCM_DSL_PROTOCOLROW_NUM];

/**
 * @brief 	Store the relevant connection status during the process form receiving the request to
 * 			confirming the response.
 */
extern VAR(Dcm_ConnectionStatusType, DCM_VAR)Dcm_ConnectionStatus[DCM_DSL_MAIN_CONNECTION_NUM];

/**
 * @brief 	Store the relevant status of the S3 timer.
 */
extern VAR(Dcm_S3TimerStatusType, DCM_VAR)Dcm_S3TimerStatus;

/**
 * @brief 	Store the relevant status of the P2 timer.
 */
extern VAR(Dcm_P2TimerStatusType, DCM_VAR)Dcm_P2TimerStatus;

#if(STD_ON == DCM_UDS0x2A_ENABLE)
/**
 * @brief 	Store the periodic transmission internal status.
 */
extern VAR(Dcm_PeriodicTransStatusType, DCM_VAR)Dcm_PeriodicTransStatus;
#endif /* #if(STD_ON == DCM_UDS0x2A_ENABLE) */

#if(STD_ON == DCM_UDS0x2C_ENABLE)
/**
 * @brief 	Store the DDDid internal status.
 */
extern VAR(Dcm_DDDidStatusType, DCM_VAR)Dcm_DDDidStatus[DCM_DSP_DDDID_NUM];
#endif /* #if(STD_ON == DCM_UDS0x34_ENABLE) */

#if((STD_ON == DCM_UDS0x34_ENABLE) || (STD_ON == DCM_UDS0x35_ENABLE))
/**
 * @brief 	Store the relevant status during the process of downloading or uploading data.
 */
extern VAR(Dcm_TransferStatusType, DCM_VAR)Dcm_TransferStatus;
#endif /* #if((STD_ON == DCM_UDS0x34_ENABLE) || (STD_ON == DCM_UDS0x35_ENABLE)) */

#if((STD_ON == DCM_DSL_DIAG_RESP_ON_SECOND_DECLINED_REQUEST) ||\
	(STD_ON == DCM_DSL_CALLBACK_DCM_REQUEST_SERVICE_ENABLED))
/**
 * @brief 	Independent NRC buffer.
 */
extern VAR(uint8, DCM_VAR)Dcm_NRCBuffer[3];
#endif /* #if((STD_ON == DCM_DSL_DIAG_RESP_ON_SECOND_DECLINED_REQUEST) ||\
			  (STD_ON == DCM_DSL_CALLBACK_DCM_REQUEST_SERVICE_ENABLED)) */

#if(STD_ON == DCM_UDS0x27_ENABLE)
/**
 * @brief	Store the security access initialization status.
 */
extern VAR(Dcm_SecurityInitStatusType, DCM_VAR)Dcm_SecurityInitStatus;

/**
 * @brief	Store the timer, counter and delay state during the security access.
 */
extern VAR(Dcm_SecurityStatusType, DCM_VAR)Dcm_SecurityStatus[DCM_DSP_SECURITY_ROW_NUM];
#endif /* #if(STD_ON == DCM_UDS0x27_ENABLE) */

#if(STD_ON == DCM_UDS0x28_ENABLE)
/**
 * @brief 	Each bit represents a channel, and set to 0 indicates that the channel is disabled for
 * 			application messages and network management messages.
 */
extern VAR(uint32, DCM_VAR)Dcm_CommunicationState;
#endif /* #if(STD_ON == DCM_UDS0x28_ENABLE) */

#if(STD_ON == DCM_UDS0x85_ENABLE)
/**
 * @brief 	Whether DTC has been disabled before.
 */
extern VAR(boolean, DCM_VAR)Dcm_DisableDTCState;
#endif /* #if(STD_ON == DCM_UDS0x85_ENABLE) */

#define DCM_GET_SERVICE_PTR(Idx)	 (&Dcm_ConfigPtr->DcmDsl->DcmDslProtocolRow[Dcm_ActiveProRowIdx].DcmDslProtocolSIDTable->DcmDsdService[(Idx)])
/*====================================================================================================*
 *                                        FUNCTION PROTOTYPES
 *====================================================================================================*/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"

FUNC(void, DCM_CODE)DslInternal_InitInternalStatus
(
	void
);

FUNC(void, DCM_CODE)DslInternal_ResetConnectionStatus
(
	void
);

FUNC(void, DCM_CODE)DslInternal_SetSesCtrlType
(
	Dcm_SesCtrlType SesCtrlType
);

FUNC(void, DCM_CODE)DslInternal_SetSecurityLevel
(
	Dcm_SecLevelType SecurityLevel
);

FUNC(void, DCM_CODE)DslInternal_TimerProcess
(
	void
);

#if(0u != DCM_DSL_DIAG_RESP_MAX_NUM_RESP_PEND)
FUNC(void, DCM_CODE)DslInternal_PendingProcess
(
	void
);
#endif /* #if(0u != DCM_DSL_DIAG_RESP_MAX_NUM_RESP_PEND) */

#if((STD_ON == DCM_DSL_DIAG_RESP_ON_SECOND_DECLINED_REQUEST) || (STD_ON == DCM_DSL_CALLBACK_DCM_REQUEST_SERVICE_ENABLED))
FUNC(BufReq_ReturnType, DCM_CODE)DslInternal_SetNRCAndTransmit
(
	uint8 u8Sid,
	uint8 u8ProConIdx,
	uint8 u8ProRowIdx,
	Dcm_NegativeResponseCodeType NRC,
	boolean isResetStatus
);
#endif /* #if((STD_ON == DCM_DSL_DIAG_RESP_ON_SECOND_DECLINED_REQUEST) || (STD_ON == DCM_DSL_CALLBACK_DCM_REQUEST_SERVICE_ENABLED)) */

FUNC(BufReq_ReturnType, DCM_CODE)DslInternal_NoProtocolPreemption
(
	P2CONST(PduInfoType, AUTOMATIC, DCM_CONST)Info,
	PduLengthType TpSduLength,
	P2VAR(PduLengthType, AUTOMATIC, DCM_VAR)BufferSizePtr,
	P2CONST(Dcm_DslProtocolRxType, AUTOMATIC, DCM_CONST)pProtocolRx,
	P2CONST(Dcm_DslProtocolRowType, AUTOMATIC, DCM_CONST)pProtocolRow
);

#if(0u != DCM_DSL_PROTOCOLROW_NUM)
FUNC(BufReq_ReturnType, DCM_CODE)DslInternal_ProtocolPreemption
(
	PduIdType Id,
	P2CONST(PduInfoType, AUTOMATIC, DCM_CONST)Info,
	PduLengthType TpSduLength,
	P2VAR(PduLengthType, AUTOMATIC, DCM_VAR)BufferSizePtr,
	P2CONST(Dcm_DslProtocolRxType, AUTOMATIC, DCM_CONST)pProtocolRx,
	P2CONST(Dcm_DslProtocolRowType, AUTOMATIC, DCM_CONST)pProtocolRow
);
#endif /* #if(0u != DCM_DSL_PROTOCOLROW_NUM) */

#if(STD_ON == DCM_DSL_CALLBACK_DCM_REQUEST_SERVICE_ENABLED)
FUNC(boolean, DCM_CODE)DslInternal_StartProtocol
(
	P2CONST(Dcm_DslProtocolRowType, AUTOMATIC, DCM_CONST)pProtocolRow
);
#else
FUNC(void, DCM_CODE)DslInternal_StartProtocol
(
	void
);
#endif /* #if(STD_ON == DCM_DSL_CALLBACK_DCM_REQUEST_SERVICE_ENABLED) */

FUNC(void, DCM_CODE)DslInternal_TransmitHandle
(
	PduIdType id
);

FUNC(void, DCM_CODE)DsdInternal_ServiceProcess
(
	void
);

FUNC(boolean, DCM_CODE)DsdInternal_TpTxConfirmation
(
	void
);

#if(0u != DCM_DSP_DID_NUM)
#if((STD_ON == DCM_UDS0x2C_ENABLE) || (STD_ON == DCM_UDS0x2A_ENABLE))
FUNC(Std_ReturnType, DCM_CODE)DspInternal_CheckDidValid
(
	uint16 checkDid,
	Dcm_PermissionCheckUserType userType,
	P2VAR(uint8, AUTOMATIC, DCM_VAR)pDidIdx,
	P2VAR(Dcm_SessionDataType, AUTOMATIC, DCM_VAR)pSesLevelRef,
	P2VAR(Dcm_SecurityDataType, AUTOMATIC, DCM_VAR)pSecLevelRef,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
);
#else
FUNC(Std_ReturnType, DCM_CODE)DspInternal_CheckDidValid
(
	uint16 checkDid,
	Dcm_PermissionCheckUserType userType,
	P2VAR(uint8, AUTOMATIC, DCM_VAR)pDidIdx,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
);
#endif /* #if((STD_ON == DCM_UDS0x2C_ENABLE) || (STD_ON == DCM_UDS0x2A_ENABLE)) */
#endif /* #if(0u != DCM_DSP_DID_NUM) */

#if(0u != DCM_DSP_DID_RANGE_NUM)
FUNC(Std_ReturnType, DCM_CODE)DspInternal_CheckRangeDidValid
(
	uint16 checkRangeDid,
	Dcm_OpStatusType opState,
	Dcm_PermissionCheckUserType userType,
	P2VAR(uint8, AUTOMATIC, DCM_VAR)pRangeDidIdx,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
);
#endif /* #if(0u != DCM_DSP_DID_RANGE_NUM) */

#if(STD_ON == DCM_UDS0x2C_ENABLE)
FUNC(void, DCM_CODE)DspInternal_DDDidStatusInit
(
	uint8 u8DDDidIdx
);

FUNC(Std_ReturnType, DCM_CODE)DspInternal_CheckDDDidReadValid
(
	uint8 u8ReqDidIdx,
	P2VAR(uint8, AUTOMATIC, DCM_VAR)pDidType,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
);
#endif /* #if(STD_ON == DCM_UDS0x2C_ENABLE) */

FUNC(void, DCM_CODE)DspInternal_JumpFromHandle
(
	void
);

#if(STD_ON == DCM_UDS0x27_ENABLE)
FUNC(void, DCM_CODE)DspInternal_SecurityTimerHandle
(
	void
);
#endif /* #if(STD_ON == DCM_UDS0x27_ENABLE) */

#if((STD_ON == DCM_UDS0x34_ENABLE) || (STD_ON == DCM_UDS0x35_ENABLE))
FUNC(void, DCM_CODE)DspInternal_TransferInit
(
	void
);
#endif /* #if((STD_ON == DCM_UDS0x34_ENABLE) || (STD_ON == DCM_UDS0x35_ENABLE)) */

FUNC(Std_ReturnType, DCM_CODE)DspInternal_PermissionCheck
(
	Dcm_SessionDataType sesLevelRef,
	Dcm_SecurityDataType secLevelRef,
	Dcm_PermissionCheckUserType userType,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
);

FUNC(Std_ReturnType, DCM_CODE)DspInternal_SubServiceCheck
(
	uint8 u8AddrType,
	uint8 u8SubServiceId,
	P2CONST(Dcm_DsdServiceType, AUTOMATIC, DCM_CONST)pService,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
);

#if((STD_ON == DCM_UDS0x23_ENABLE) || (STD_ON == DCM_UDS0x2C_ENABLE) ||\
	(STD_ON == DCM_UDS0x3D_ENABLE) || (STD_ON == DCM_UDS0x34_ENABLE) ||\
	(STD_ON == DCM_UDS0x35_ENABLE))
#if(STD_ON != DCM_UDS0x2C_ENABLE)
FUNC(Std_ReturnType, DCM_CODE)DspInternal_MemoryAddrCheck
(
	uint32 u32MemoryAddr,
	uint32 u32MemorySize,
	boolean isReadProcess,
	P2VAR(uint8, AUTOMATIC, DCM_VAR)pMemoryId,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
);
#else
FUNC(Std_ReturnType, DCM_CODE)DspInternal_MemoryAddrCheck
(
	uint32 u32MemoryAddr,
	uint32 u32MemorySize,
	boolean isReadProcess,
	P2VAR(uint8, AUTOMATIC, DCM_VAR)pMemoryId,
	P2VAR(Dcm_SessionDataType, AUTOMATIC, DCM_VAR)pSesLevelRef,
	P2VAR(Dcm_SecurityDataType, AUTOMATIC, DCM_VAR)pSecLevelRef,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
);
#endif /* #if(STD_ON != DCM_UDS0x2C_ENABLE) */
#endif /* #if((STD_ON == DCM_UDS0x23_ENABLE) || (STD_ON == DCM_UDS0x2C_ENABLE) ||\
			  (STD_ON == DCM_UDS0x3D_ENABLE) || (STD_ON == DCM_UDS0x34_ENABLE) ||\
			  (STD_ON == DCM_UDS0x35_ENABLE)) */

#if(STD_ON == DCM_UDS0x2A_ENABLE)
FUNC(void, DCM_CODE)DspInternal_DeletePeriodicDid
(
	uint8 u8PDidIndex
);

FUNC(void, DCM_CODE)DspInternal_PeriodicTransmission
(
	void
);
#endif /* #if(STD_ON == DCM_UDS0x2A_ENABLE) */

#if(STD_ON == DCM_UDS0x10_ENABLE)
#if(STD_ON == DCM_UDS0x10_INTERNAL_FNC_ENABLE)
FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x10
(
	Dcm_OpStatusType OpStatus,
	P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
);
#endif /* #if(STD_ON == DCM_UDS0x10_INTERNAL_FNC_ENABLE) */
#endif /* #if(STD_ON == DCM_UDS0x10_ENABLE) */

#if(STD_ON == DCM_UDS0x11_ENABLE)
#if(STD_ON == DCM_UDS0x11_INTERNAL_FNC_ENABLE)
FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x11
(
	Dcm_OpStatusType OpStatus,
	P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
);
#endif /* #if(STD_ON == DCM_UDS0x11_INTERNAL_FNC_ENABLE) */
#endif /* #if(STD_ON == DCM_UDS0x11_ENABLE) */

#if(STD_ON == DCM_UDS0x14_ENABLE)
#if(STD_ON == DCM_UDS0x14_INTERNAL_FNC_ENABLE)
FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x14
(
	Dcm_OpStatusType OpStatus,
	P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
);
#endif /* #if(STD_ON == DCM_UDS0x14_INTERNAL_FNC_ENABLE) */
#endif /* #if(STD_ON == DCM_UDS0x14_ENABLE) */

#if(STD_ON == DCM_UDS0x19_ENABLE)
#if(STD_ON == DCM_UDS0x19_INTERNAL_FNC_ENABLE)
FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x19
(
	Dcm_OpStatusType OpStatus,
	P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
);
#endif /* #if(STD_ON == DCM_UDS0x19_INTERNAL_FNC_ENABLE) */
#endif /* #if(STD_ON == DCM_UDS0x19_ENABLE) */

#if(STD_ON == DCM_UDS0x22_ENABLE)
#if(STD_ON == DCM_UDS0x22_INTERNAL_FNC_ENABLE)
FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x22
(
	Dcm_OpStatusType OpStatus,
	P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
);
#endif /* #if(STD_ON == DCM_UDS0x22_INTERNAL_FNC_ENABLE) */
#endif /* #if(STD_ON == DCM_UDS0x22_ENABLE) */

#if(STD_ON == DCM_UDS0x23_ENABLE)
#if(STD_ON == DCM_UDS0x23_INTERNAL_FNC_ENABLE)
FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x23
(
	Dcm_OpStatusType OpStatus,
	P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
);
#endif /* #if(STD_ON == DCM_UDS0x23_INTERNAL_FNC_ENABLE) */
#endif /* #if(STD_ON == DCM_UDS0x23_ENABLE) */

#if(STD_ON == DCM_UDS0x24_ENABLE)
#if(STD_ON == DCM_UDS0x24_INTERNAL_FNC_ENABLE)
FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x24
(
	Dcm_OpStatusType OpStatus,
	P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
);
#endif /* #if(STD_ON == DCM_UDS0x24_INTERNAL_FNC_ENABLE) */
#endif /* #if(STD_ON == DCM_UDS0x24_ENABLE) */

#if(STD_ON == DCM_UDS0x27_ENABLE)
#if(STD_ON == DCM_UDS0x27_INTERNAL_FNC_ENABLE)
FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x27
(
	Dcm_OpStatusType OpStatus,
	P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
);
#endif /* #if(STD_ON == DCM_UDS0x27_INTERNAL_FNC_ENABLE) */
#endif /* #if(STD_ON == DCM_UDS0x27_ENABLE) */

#if(STD_ON == DCM_UDS0x28_ENABLE)
#if(STD_ON == DCM_UDS0x28_INTERNAL_FNC_ENABLE)
FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x28
(
	Dcm_OpStatusType OpStatus,
	P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
);
#endif /* #if(STD_ON == DCM_UDS0x28_INTERNAL_FNC_ENABLE) */
#endif /* #if(STD_ON == DCM_UDS0x28_ENABLE) */

#if(STD_ON == DCM_UDS0x2A_ENABLE)
#if(STD_ON == DCM_UDS0x2A_INTERNAL_FNC_ENABLE)
FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x2A
(
	Dcm_OpStatusType OpStatus,
	P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
);
#endif /* #if(STD_ON == DCM_UDS0x2A_INTERNAL_FNC_ENABLE) */
#endif /* #if(STD_ON == DCM_UDS0x2A_ENABLE) */

#if(STD_ON == DCM_UDS0x2C_ENABLE)
#if(STD_ON == DCM_UDS0x2C_INTERNAL_FNC_ENABLE)
FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x2C
(
	Dcm_OpStatusType OpStatus,
	P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
);
#endif /* #if(STD_ON == DCM_UDS0x2C_INTERNAL_FNC_ENABLE) */
#endif /* #if(STD_ON == DCM_UDS0x2C_ENABLE) */

#if(STD_ON == DCM_UDS0x2E_ENABLE)
#if(STD_ON == DCM_UDS0x2E_INTERNAL_FNC_ENABLE)
FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x2E
(
	Dcm_OpStatusType OpStatus,
	P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
);
#endif /* #if(STD_ON == DCM_UDS0x2E_INTERNAL_FNC_ENABLE) */
#endif /* #if(STD_ON == DCM_UDS0x2E_ENABLE) */

#if(STD_ON == DCM_UDS0x2F_ENABLE)
#if(STD_ON == DCM_UDS0x2F_INTERNAL_FNC_ENABLE)
FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x2F
(
	Dcm_OpStatusType OpStatus,
	P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
);
#endif /* #if(STD_ON == DCM_UDS0x2F_INTERNAL_FNC_ENABLE) */
#endif /* #if(STD_ON == DCM_UDS0x2F_ENABLE) */

#if(STD_ON == DCM_UDS0x31_ENABLE)
#if(STD_ON == DCM_UDS0x31_INTERNAL_FNC_ENABLE)
FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x31
(
	Dcm_OpStatusType OpStatus,
	P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
);
#endif /* #if(STD_ON == DCM_UDS0x31_INTERNAL_FNC_ENABLE) */
#endif /* #if(STD_ON == DCM_UDS0x31_ENABLE) */

#if(STD_ON == DCM_UDS0x34_ENABLE)
#if(STD_ON == DCM_UDS0x34_INTERNAL_FNC_ENABLE)
FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x34
(
	Dcm_OpStatusType OpStatus,
	P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
);
#endif /* #if(STD_ON == DCM_UDS0x34_INTERNAL_FNC_ENABLE) */
#endif /* #if(STD_ON == DCM_UDS0x34_ENABLE) */

#if(STD_ON == DCM_UDS0x35_ENABLE)
#if(STD_ON == DCM_UDS0x35_INTERNAL_FNC_ENABLE)
FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x35
(
	Dcm_OpStatusType OpStatus,
	P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
);
#endif /* #if(STD_ON == DCM_UDS0x35_INTERNAL_FNC_ENABLE) */
#endif /* #if(STD_ON == DCM_UDS0x35_ENABLE) */

#if(STD_ON == DCM_UDS0x36_ENABLE)
#if(STD_ON == DCM_UDS0x36_INTERNAL_FNC_ENABLE)
FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x36
(
	Dcm_OpStatusType OpStatus,
	P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
);
#endif /* #if(STD_ON == DCM_UDS0x36_INTERNAL_FNC_ENABLE) */
#endif /* #if(STD_ON == DCM_UDS0x36_ENABLE) */

#if(STD_ON == DCM_UDS0x37_ENABLE)
#if(STD_ON == DCM_UDS0x37_INTERNAL_FNC_ENABLE)
FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x37
(
	Dcm_OpStatusType OpStatus,
	P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
);
#endif /* #if(STD_ON == DCM_UDS0x37_INTERNAL_FNC_ENABLE) */
#endif /* #if(STD_ON == DCM_UDS0x37_ENABLE) */

#if(STD_ON == DCM_UDS0x3D_ENABLE)
#if(STD_ON == DCM_UDS0x3D_INTERNAL_FNC_ENABLE)
FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x3D
(
	Dcm_OpStatusType OpStatus,
	P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
);
#endif /* #if(STD_ON == DCM_UDS0x3D_INTERNAL_FNC_ENABLE) */
#endif /* #if(STD_ON == DCM_UDS0x3D_ENABLE) */

#if(STD_ON == DCM_UDS0x3E_ENABLE)
#if(STD_ON == DCM_UDS0x3E_INTERNAL_FNC_ENABLE)
FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x3E
(
	Dcm_OpStatusType OpStatus,
	P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
);
#endif /* #if(STD_ON == DCM_UDS0x3E_INTERNAL_FNC_ENABLE) */
#endif /* #if(STD_ON == DCM_UDS0x3E_ENABLE) */

#if(STD_ON == DCM_UDS0x85_ENABLE)
#if(STD_ON == DCM_UDS0x85_INTERNAL_FNC_ENABLE)
FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x85
(
	Dcm_OpStatusType OpStatus,
	P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
);
#endif /* #if(STD_ON == DCM_UDS0x85_INTERNAL_FNC_ENABLE) */
#endif /* #if(STD_ON == DCM_UDS0x85_ENABLE) */

#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* DCM_INTERNAL_H */
/** @} */
