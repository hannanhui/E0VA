/** 
 *  @file     EcuM.h
 *  @brief    AUTOSAR EcuM - EcuM driver header file.
 *  @details  EcuM driver header file, containing the Autosar API specification and
 * 			  other variables and functions that are exported by the EcuM  driver.
 *  @version  1.2.0
 *
 * @addtogroup  EcuM
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
#ifndef ECUM_H  /* PRQA S 0828  EOF# violate MSIAR2004_1.1: It works*/
#define ECUM_H

#if defined(__cplusplus)
extern "C" 
{
#endif /* defined(__cplusplus) */

/*====================================================================================================*
 *                                           INCLUDE FILES
 *====================================================================================================*/
#include "EcuM_Generated_Types.h"
#include "EcuM_Cfg.h"
#include "EcuM_Cbk.h"

/*====================================================================================================*
 *                                  HEADER FILE VERSION INFORMATION
 *====================================================================================================*/

#define ECUM_VENDOR_ID                           0U
#define ECUM_MODULE_ID                           10U
#define ECUM_SW_MAJOR_VERSION                    1U
#define ECUM_SW_MINOR_VERSION                    2U
#define ECUM_SW_PATCH_VERSION                    0U
#define ECUM_AR_RELEASE_MAJOR_VERSION            4U
#define ECUM_AR_RELEASE_MINOR_VERSION            2U
#define ECUM_AR_RELEASE_REVISION_VERSION         2U

/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/
/* Check if current file and EcuM_Generated_Types.h file are of the same vendor */
#if(ECUM_VENDOR_ID != ECUM_GENERATED_TYPES_VENDOR_ID )
#error "EcuM.h and EcuM_Generated_Types.h have different vendor id"
#endif
/* Check if current file and EcuM_Generated_Types.h header file are of the same Autosar version */
#if(\
		(ECUM_AR_RELEASE_MAJOR_VERSION != ECUM_GENERATED_TYPES_AR_RELEASE_MAJOR_VERSION) || \
		(ECUM_AR_RELEASE_MINOR_VERSION != ECUM_GENERATED_TYPES_AR_RELEASE_MINOR_VERSION) || \
		(ECUM_AR_RELEASE_REVISION_VERSION != ECUM_GENERATED_TYPES_AR_RELEASE_REVISION_VERSION) \
	)
#error "AutoSar Version Number of EcuM.h and EcuM_Generated_Types.h are different "
#endif
/* Check if current file and EcuM_Generated_Types.h header file are of the same software version */
#if(\
		(ECUM_SW_MAJOR_VERSION != ECUM_GENERATED_TYPES_SW_MAJOR_VERSION) || \
		(ECUM_SW_MINOR_VERSION != ECUM_GENERATED_TYPES_SW_MINOR_VERSION) || \
		(ECUM_SW_PATCH_VERSION != ECUM_GENERATED_TYPES_SW_PATCH_VERSION) \
	)
#error "Software Version Number of EcuM.h and EcuM_Generated_Types.h are different "
#endif

/* Check if current file and EcuM_Cfg.h file are of the same vendor */
#if(ECUM_VENDOR_ID != ECUM_CFG_VENDOR_ID )
#error "EcuM.h and EcuM_Cfg.h have different vendor id"
#endif
/* Check if current file and EcuM_Cfg.h header file are of the same Autosar version */
#if(\
		(ECUM_AR_RELEASE_MAJOR_VERSION != ECUM_CFG_AR_RELEASE_MAJOR_VERSION) || \
		(ECUM_AR_RELEASE_MINOR_VERSION != ECUM_CFG_AR_RELEASE_MINOR_VERSION) || \
		(ECUM_AR_RELEASE_REVISION_VERSION != ECUM_CFG_AR_RELEASE_REVISION_VERSION) \
	)
#error "AutoSar Version Number of EcuM.h and EcuM_Cfg.h are different "
#endif
/* Check if current file and EcuM_Cfg.h header file are of the same software version */
#if(\
		(ECUM_SW_MAJOR_VERSION != ECUM_CFG_SW_MAJOR_VERSION) || \
		(ECUM_SW_MINOR_VERSION != ECUM_CFG_SW_MINOR_VERSION) || \
		(ECUM_SW_PATCH_VERSION != ECUM_CFG_SW_PATCH_VERSION) \
	)
#error "Software Version Number of EcuM.h and EcuM_Cfg.h are different "
#endif

/* Check if current file and EcuM_Cbk.h file are of the same vendor */
#if(ECUM_VENDOR_ID != ECUM_CBK_VENDOR_ID )
#error "EcuM.h and EcuM_Cbk.h have different vendor id"
#endif
/* Check if current file and EcuM_Cbk.h header file are of the same Autosar version */
#if(\
		(ECUM_AR_RELEASE_MAJOR_VERSION != ECUM_CBK_AR_RELEASE_MAJOR_VERSION) || \
		(ECUM_AR_RELEASE_MINOR_VERSION != ECUM_CBK_AR_RELEASE_MINOR_VERSION) || \
		(ECUM_AR_RELEASE_REVISION_VERSION != ECUM_CBK_AR_RELEASE_REVISION_VERSION) \
	)
#error "AutoSar Version Number of EcuM.h and EcuM_Cbk.h are different "
#endif
/* Check if current file and EcuM_Cbk.h header file are of the same software version */
#if(\
		(ECUM_SW_MAJOR_VERSION != ECUM_CBK_SW_MAJOR_VERSION) || \
		(ECUM_SW_MINOR_VERSION != ECUM_CBK_SW_MINOR_VERSION) || \
		(ECUM_SW_PATCH_VERSION != ECUM_CBK_SW_PATCH_VERSION) \
	)
#error "Software Version Number of EcuM.h and EcuM_Cbk.h are different "
#endif

/*====================================================================================================*
 *                                             CONSTANTS
 *====================================================================================================*/

/*====================================================================================================*
 *                                         DEFINES AND MACROS
 *====================================================================================================*/

/**
 * @brief         Service ID
 */
#define ECUM_SID_GETVERSIONINFO           ((uint8)0x00U)
#define ECUM_SID_INIT                     ((uint8)0x01U)
#define ECUM_SID_STARTUP_TWO              ((uint8)0x1AU)
#define ECUM_SID_SHUTDOWN                 ((uint8)0x02U)
#define ECUM_SID_REQUESTRUN               ((uint8)0x03U)
#define ECUM_SID_RELEASERUN               ((uint8)0x04U)
#define ECUM_SID_REQUESTPOST_RUN          ((uint8)0x0AU)
#define ECUM_SID_RELEASEPOST_RUN          ((uint8)0x0BU)
#define ECUM_SID_SELECTSHUTDOWNTARGET     ((uint8)0x06U)
#define ECUM_SID_GETSHUTDOWNTARGET        ((uint8)0x09U)
#define ECUM_SID_GETLASTSHUTDOWNTARGET    ((uint8)0x08U)
#define ECUM_SID_SELECTSHUTDOWNCAUSE      ((uint8)0x1BU)
#define ECUM_SID_GETSHUTDOWNCAUSE         ((uint8)0x1CU)
#define ECUM_SID_GETPENDINGWAKEUPEVENTS   ((uint8)0x0DU)
#define ECUM_SID_CLEARWAKEUPEVENT         ((uint8)0x16U)
#define ECUM_SID_GETVALIDATEDWAKEUPEVENTS ((uint8)0x15U)
#define ECUM_SID_GETEXPIREDWAKEUPEVENTS   ((uint8)0x19U)
#define ECUM_SID_GETSTATUSOFWAKEUPSOURCE  ((uint8)0x17U)
#define ECUM_SID_STARTCHECKWAKEUP         ((uint8)0x28U)
#define ECUM_SID_ENDCHECKWAKEUP           ((uint8)0x29U)
#define ECUM_SID_SELECTBOOTTARGET         ((uint8)0x12U)
#define ECUM_SID_GETBOOTTARGET            ((uint8)0x13U)
#define ECUM_SID_MAINFUNCTION             ((uint8)0x18U)
#define ECUM_SID_SETWAKEUPEVENT           ((uint8)0x0CU)
#define ECUM_SID_VALIDATEWAKEUPEVENT      ((uint8)0x14U)
#define ECUM_SID_SETCLOCK                 ((uint8)0x27U)
#define ECUM_SID_SETABSWAKEUPALARM        ((uint8)0x23U)
#define ECUM_SID_SETRELWAKEUPALARM        ((uint8)0x22U)
#define ECUM_SID_SETSTATE                 ((uint8)0x2BU)
#define ECUM_SID_GODOWN                   ((uint8)0x1FU)
#define ECUM_SID_GOHALT                   ((uint8)0x20U)
#define ECUM_SID_GOPOLL                   ((uint8)0x21U)
#define ECUM_SID_GETWAKEUPTIME            ((uint8)0x26U)
#define ECUM_SID_GETCURRENTTIME           ((uint8)0x25U)
#define ECUM_SID_ABORTWAKEUPALARM         ((uint8)0x24U)

/**
 * @brief         State of the ECU Manager module
 */
#define ECUM_SUBSTATE_MASK 			((EcuM_StateType)0x0fU)
#define ECUM_STATE_STARTUP 			((EcuM_StateType)0x10U)
#define ECUM_STATE_RUN 				((EcuM_StateType)0x30U)
#define ECUM_STATE_APP_RUN 			((EcuM_StateType)0x32U)
#define ECUM_STATE_APP_POST_RUN 	((EcuM_StateType)0x33U)
#define ECUM_STATE_SHUTDOWN 		((EcuM_StateType)0x40U)
#define ECUM_STATE_SLEEP 			((EcuM_StateType)0x50U)

/**
 * @brief         State of the Run Request Protocol
 */
#define ECUM_RUNSTATUS_UNKNOWN 				((EcuM_RunStatusType)0x00U)
#define ECUM_RUNSTATUS_REQUESTED 			((EcuM_RunStatusType)0x01U)
#define ECUM_RUNSTATUS_RELEASED 			((EcuM_RunStatusType)0x02U)

/**
 * @brief         There must be five unvaliant source of arousal
 */
#define ECUM_WKSOURCE_POWER					((EcuM_WakeupSourceType)0x00000001U)
#define ECUM_WKSOURCE_RESET					((EcuM_WakeupSourceType)0x00000002U)
#define ECUM_WKSOURCE_INTERNAL_RESET		((EcuM_WakeupSourceType)0x00000004U)
#define ECUM_WKSOURCE_INTERNAL_WDG			((EcuM_WakeupSourceType)0x00000008U)
#define ECUM_WKSOURCE_EXTERNAL_WDG			((EcuM_WakeupSourceType)0x00000010U)

/**
 * @brief         State of the wake-up source
 */
#define ECUM_WKSTATUS_NONE			((EcuM_WakeupStatusType)0x00U)
#define ECUM_WKSTATUS_PENDING		((EcuM_WakeupStatusType)0x01U)
#define ECUM_WKSTATUS_VALIDATED		((EcuM_WakeupStatusType)0x02U)
#define ECUM_WKSTATUS_EXPIRED		((EcuM_WakeupStatusType)0x03U)
#define ECUM_WKSTATUS_ENABLED		((EcuM_WakeupStatusType)0x06U)

/**
 * @brief         This type represents the boot targets the ECU Manager module can be
 *                configured with
 */
#define ECUM_BOOT_TARGET_APP				((EcuM_BootTargetType)0x00U)
#define ECUM_BOOT_TARGET_OEM_BOOTLOADER		((EcuM_BootTargetType)0x01U)
#define ECUM_BOOT_TARGET_SYS_BOOTLOADER		((EcuM_BootTargetType)0x02U)

/**
 * @brief         This type describes the reset mechanisms supported by the ECU State Manager
 */
#define ECUM_RESET_MCU		((EcuM_ResetType)0x00U)
#define ECUM_RESET_WDG		((EcuM_ResetType)0x01U)
#define ECUM_RESET_IO		((EcuM_ResetType)0x02U)

/**
 * @brief         This type describes the cause for a shutdown by the ECU State Manager
 */
#define ECUM_CAUSE_UNKNOWN		((EcuM_ShutdownCauseType)0x00U)
#define ECUM_CAUSE_ECU_STATE	((EcuM_ShutdownCauseType)0x01U)
#define ECUM_CAUSE_WDGM			((EcuM_ShutdownCauseType)0x02U)
#define ECUM_CAUSE_DCM			((EcuM_ShutdownCauseType)0x03U)

/**
 * @brief         Shutdown target of the ECU Manager module
 */
#define ECUM_SHUTDOWN_TARGET_SLEEP	((EcuM_ShutdownTargetType)0x00U)
#define ECUM_SHUTDOWN_TARGET_RESET	((EcuM_ShutdownTargetType)0x01U)
#define ECUM_SHUTDOWN_TARGET_OFF	((EcuM_ShutdownTargetType)0x02U)

/**
 * @{
 * @brief         Error code
 */
#define ECUM_E_UNINIT								((uint8)0x00U)
#define ECUM_E_SERVICE_DISABLED						((uint8)0x01U)
#define ECUM_E_NULL_POINTER							((uint8)0x02U)
#define ECUM_E_INVALID_PAR							((uint8)0x03U)
#define ECUM_E_STATE_PAR_OUT_OF_RANGE				((uint8)0x04U)
#define ECUM_E_UNKNOWN_WAKEUP_SOURCE				((uint8)0x05U)
#define ECUM_E_INIT_FAILED							((uint8)0x06U)
#define ECUM_E_RAM_CHECK_FAILED						((uint8)0x07U)
#define ECUM_E_CONFIGURATION_DATA_INCONSISTENT		((uint8)0x08U)
#define ECUM_E_MULTIPLE_RUN_REQUESTS				((uint8)0x09U)
#define ECUM_E_MISMATCHED_RUN_RELEASE				((uint8)0x0AU)
#define ECUM_E_PARAM_POINTER				        ((uint8)0x0BU)

#ifndef ECUM_E_EARLIER_ACTIVE
#define ECUM_E_EARLIER_ACTIVE ((Std_ReturnType)3)
#endif
#ifndef ECUM_E_PAST
#define ECUM_E_PAST ((Std_ReturnType)4)
#endif

#ifndef ECUM_E_NOT_ACTIVE
#define ECUM_E_NOT_ACTIVE ((Std_ReturnType)5)
#endif
/** @} */

/**
 * @brief         Alarm error
 */
#define ECUM_INVALID_ALARM	((uint32)0xFFFFFFFFU)

/**
 * @brief         No wake-up source
 */
#define ECUM_WAKEUP_SOURCE_NONE		((EcuM_WakeupSourceType)0x0)
/*====================================================================================================*
 *                                               ENUMS
 *====================================================================================================*/

/*====================================================================================================*
 *                                   STRUCTURES AND OTHER TYPEDEFS
 *====================================================================================================*/

/*====================================================================================================*
 *                                    GLOBAL VARIABLE DECLARATIONS
 *====================================================================================================*/
extern CONST(EcuM_ConfigType, ECUM_CONST) EcuM_Config; /* PRQA S 3451  EOF# violate MSIAR2004_8.8:
															This variable needs to be declared here*/

/*====================================================================================================*
 *                                        FUNCTION PROTOTYPES
 *====================================================================================================*/
#define ECUM_START_SEC_CODE
#include "EcuM_MemMap.h"

#if(STD_ON == ECUM_VERSION_INFO_API)
FUNC(void, ECUM_CODE) EcuM_GetVersionInfo
(
	P2VAR(Std_VersionInfoType, AUTOMATIC, ECUM_APPL_DATA) pVersioninfo
);
#endif /* STD_ON == ECUM_VERSION_INFO_API */

FUNC(Std_ReturnType, ECUM_CODE) EcuM_GoDown
(
	CONST(EcuM_UserType, AUTOMATIC) caller
);

FUNC(Std_ReturnType, ECUM_CODE) EcuM_GoHalt
(
	void
);

FUNC(Std_ReturnType, ECUM_CODE) EcuM_GoPoll
(
	void
);

FUNC(void, ECUM_CODE) EcuM_Init
(
	void
);

FUNC(void, ECUM_CODE) EcuM_StartupTwo
(
	void
);

FUNC(void, ECUM_CODE) EcuM_Shutdown
(
	void
);

FUNC(void, ECUM_CODE) EcuM_SetState
(
	CONST(EcuM_StateType, AUTOMATIC) state
);

FUNC(Std_ReturnType, ECUM_CODE) EcuM_RequestRUN
(
	CONST(EcuM_UserType, AUTOMATIC) user
);

FUNC(Std_ReturnType, ECUM_CODE) EcuM_ReleaseRUN
(
	CONST(EcuM_UserType, AUTOMATIC) user
);

FUNC(Std_ReturnType, ECUM_CODE) EcuM_RequestPOST_RUN
(
	CONST(EcuM_UserType, AUTOMATIC) user
);

FUNC(Std_ReturnType, ECUM_CODE) EcuM_ReleasePOST_RUN
(
	CONST(EcuM_UserType, AUTOMATIC) user
);

FUNC(Std_ReturnType, ECUM_CODE) EcuM_SelectShutdownTarget
(
	CONST(EcuM_ShutdownTargetType, AUTOMATIC) shutdownTarget,
	CONST(EcuM_ShutdownModeType,   AUTOMATIC) shutdownMode
);

FUNC(Std_ReturnType, ECUM_CODE) EcuM_GetShutdownTarget
(
	P2VAR(EcuM_ShutdownTargetType,AUTOMATIC, ECUM_APPL_DATA) pShutdownTarget,
	P2VAR(EcuM_ShutdownModeType,  AUTOMATIC, ECUM_APPL_DATA) pSleepMode
);

FUNC(Std_ReturnType, ECUM_CODE) EcuM_GetLastShutdownTarget
(
	P2VAR(EcuM_ShutdownTargetType,AUTOMATIC, ECUM_APPL_DATA) pShutdownTarget,
	P2VAR(EcuM_ShutdownModeType,  AUTOMATIC, ECUM_APPL_DATA) pSleepMode
);

FUNC(Std_ReturnType, ECUM_CODE) EcuM_SelectShutdownCause
(
	CONST(EcuM_ShutdownCauseType, AUTOMATIC) target
);

FUNC(Std_ReturnType, ECUM_CODE) EcuM_GetShutdownCause
(
	P2VAR(EcuM_ShutdownCauseType, AUTOMATIC, ECUM_APPL_DATA) pShutdownCause
);

FUNC(EcuM_WakeupSourceType, ECUM_CODE) EcuM_GetPendingWakeupEvents
(
	void
);

FUNC(void, ECUM_CODE) EcuM_ClearWakeupEvent
(
	CONST(EcuM_WakeupSourceType, AUTOMATIC) sources
);

FUNC(EcuM_WakeupSourceType, ECUM_CODE) EcuM_GetValidatedWakeupEvents
(
	void
);

FUNC(EcuM_WakeupSourceType, ECUM_CODE) EcuM_GetExpiredWakeupEvents
(
	void
);

#if (STD_ON == ECUM_ALARM_CLOCK_PRESENT)
FUNC(Std_ReturnType, ECUM_CODE) EcuM_SetRelWakeupAlarm
(
	CONST(EcuM_UserType, AUTOMATIC) user,
	CONST(EcuM_TimeType, AUTOMATIC) time/* PRQA S 4604 EOF# violate MISRA2004_20.2: useful*/
);
#endif /* STD_ON == ECUM_ALARM_CLOCK_PRESENT */

#if (STD_ON == ECUM_ALARM_CLOCK_PRESENT)
FUNC(Std_ReturnType, ECUM_CODE) EcuM_SetAbsWakeupAlarm
(
	CONST(EcuM_UserType, AUTOMATIC) user,
	CONST(EcuM_TimeType, AUTOMATIC) time
);
#endif /* STD_ON == ECUM_ALARM_CLOCK_PRESENT */

#if (STD_ON == ECUM_ALARM_CLOCK_PRESENT)
FUNC(Std_ReturnType, ECUM_CODE) EcuM_AbortWakeupAlarm
(
	CONST(EcuM_UserType, AUTOMATIC) user
);
#endif /* STD_ON == ECUM_ALARM_CLOCK_PRESENT */

#if (STD_ON == ECUM_ALARM_CLOCK_PRESENT)
FUNC(Std_ReturnType, ECUM_CODE) EcuM_GetCurrentTime
(
	P2VAR(EcuM_TimeType, AUTOMATIC, ECUM_APPL_DATA) ptime
);
#endif /* STD_ON == ECUM_ALARM_CLOCK_PRESENT */

#if (STD_ON == ECUM_ALARM_CLOCK_PRESENT)
FUNC(Std_ReturnType, ECUM_CODE) EcuM_GetWakeupTime
(
	P2VAR(EcuM_TimeType, AUTOMATIC, ECUM_APPL_DATA) ptime
);
#endif /* STD_ON == ECUM_ALARM_CLOCK_PRESENT */

#if (STD_ON == ECUM_ALARM_CLOCK_PRESENT)
FUNC(Std_ReturnType, ECUM_CODE) EcuM_SetClock
(
	CONST(EcuM_UserType, AUTOMATIC) user,
	CONST(EcuM_TimeType, AUTOMATIC) time
);
#endif /* STD_ON == ECUM_ALARM_CLOCK_PRESENT */

FUNC(Std_ReturnType, ECUM_CODE) EcuM_SelectBootTarget
(
	CONST(EcuM_BootTargetType, AUTOMATIC) target
);

FUNC(Std_ReturnType, ECUM_CODE) EcuM_GetBootTarget
(
	P2VAR(EcuM_BootTargetType, AUTOMATIC, ECUM_APPL_DATA) pTarget
);

FUNC(void, ECUM_CODE) EcuM_MainFunction
(
	void
);

#define ECUM_STOP_SEC_CODE
#include "EcuM_MemMap.h"

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* !defined ECUM_H */
/** @} */
