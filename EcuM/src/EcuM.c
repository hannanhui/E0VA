/**
 *  @file     EcuM.c
 *  @brief    AUTOSAR EcuM  - EcuM driver source file.
 *  @details  EcuM driver source file, containing the C implementation of Autosar API specification
 *            and other variables and functions that are exported by the EcuM driver.
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
#if defined(__cplusplus)
extern "C"
{
#endif /* defined(__cplusplus) */

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
 * 4.1505 -- Violates MISRA 2004 Required Rule 8.10, The function is only referenced in the translation
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
 * program does not conform strictly to ISO:C90.
 *
 * @page misra_violations MISRA-C:2004 violations
 */

extern void DisableAllInterrupts();
extern void EnableAllInterrupts();

/*====================================================================================================*
 *                                           INCLUDE FILES
 *====================================================================================================*/
#include "EcuM.h"
//#include "Os.h"
#include "Mcu.h"
#include "SchM_EcuM.h"
/*@todo*/
/*#include "Rte_EcuM.h"*/

#if (STD_ON == ECUM_DEV_ERROR_DETECT)
#include "Det.h"
#endif /* (STD_ON == ECUM_DET_ERROR_REPORT) */

/* Non-AUTOSAR */
#include "Rte_Main.h"
#include "Rte_PBCfg.h"
#include "BswM.h"
#include "BswM_EcuM.h"
#if (STD_ON == ECUM_INCLUDE_COMM)/* PRQA S 3332 EOF # violate MISAR_19.11:Macros are defined */
#include "ComM_EcuMBswM.h"
#endif /* (STD_ON == ECUM_INCLUDE_COMM) */
#ifdef AH_TEST_ECUM
#include "TestCode.h"
#endif
/*====================================================================================================*
 *                                  SOURCE FILE VERSION INFORMATION
 *====================================================================================================*/
#define ECUM_VENDOR_ID_C                           0U
#define ECUM_SW_MAJOR_VERSION_C                    1U
#define ECUM_SW_MINOR_VERSION_C                    2U
#define ECUM_SW_PATCH_VERSION_C                    0U
#define ECUM_AR_RELEASE_MAJOR_VERSION_C            4U
#define ECUM_AR_RELEASE_MINOR_VERSION_C            2U
#define ECUM_AR_RELEASE_REVISION_VERSION_C         2U

/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/
/* Check if current file and EcuM.h file are of the same vendor */
#if(ECUM_VENDOR_ID_C != ECUM_VENDOR_ID )
#error "EcuM.c and EcuM.h have different vendor id"
#endif
/* Check if current file and EcuM.h file are of the same Autosar version */
#if(\
		(ECUM_AR_RELEASE_MAJOR_VERSION_C != ECUM_AR_RELEASE_MAJOR_VERSION) || \
		(ECUM_AR_RELEASE_MINOR_VERSION_C != ECUM_AR_RELEASE_MINOR_VERSION) || \
		(ECUM_AR_RELEASE_REVISION_VERSION_C != ECUM_AR_RELEASE_REVISION_VERSION) \
	)
#error "AutoSar Version Number of EcuM.c and EcuM.h are different "
#endif
/* Check if current file and EcuM.h file are of the same software version */
#if(\
		(ECUM_SW_MAJOR_VERSION_C != ECUM_SW_MAJOR_VERSION) || \
		(ECUM_SW_MINOR_VERSION_C != ECUM_SW_MINOR_VERSION) || \
		(ECUM_SW_PATCH_VERSION_C != ECUM_SW_PATCH_VERSION) \
	)
#error "Software Version Number of EcuM.c and EcuM.h are different "
#endif

#ifndef DISABLE_INTERMOD_VERSION_CHECK
/* Check if current file and Os.h file are of the same Autosar version */
#if(\
		(ECUM_AR_RELEASE_MAJOR_VERSION_C != OS_AR_RELEASE_MAJOR_VERSION) || \
		(ECUM_AR_RELEASE_MINOR_VERSION_C != OS_AR_RELEASE_MINOR_VERSION)  \
	)
#error "AutoSar Version Number of EcuM.c and Os.h are different "
#endif

/* Check if current file and Mcu.h header file are of the same Autosar version */
#if(\
		(ECUM_AR_RELEASE_MAJOR_VERSION_C != MCU_AR_RELEASE_MAJOR_VERSION) || \
		(ECUM_AR_RELEASE_MINOR_VERSION_C != MCU_AR_RELEASE_MINOR_VERSION)  \
	)
#error "AutoSar Version Number of EcuM.c and Mcu.h are different "
#endif

/* Check if current file and SchM_EcuM.h header file are of the same Autosar version */
#if(\
		(ECUM_AR_RELEASE_MAJOR_VERSION_C != SCHM_ECUM_AR_RELEASE_MAJOR_VERSION) || \
		(ECUM_AR_RELEASE_MINOR_VERSION_C != SCHM_ECUM_AR_RELEASE_MINOR_VERSION)  \
	)
/*#error "AutoSar Version Number of EcuM.c and SchM_EcuM.h are different "*/
#endif

/* Check if current file and Rte_EcuM.h header file are of the same Autosar version */
#if(\
		(ECUM_AR_RELEASE_MAJOR_VERSION_C != RTE_ECUM_AR_RELEASE_MAJOR_VERSION) || \
		(ECUM_AR_RELEASE_MINOR_VERSION_C != RTE_ECUM_AR_RELEASE_MINOR_VERSION)  \
	)
/*#error "AutoSar Version Number of EcuM.c and Rte_EcuM.h are different "*/
#endif

#if ( STD_ON == ECUM_DEV_ERROR_DETECT )
/* Check if current file and Det.h header file are of the same Autosar version */
#if(\
		(ECUM_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
		(ECUM_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION)  \
	)
/*#error "AutoSar Version Number of EcuM.c and Det.h are different "*/
#endif
#endif /* (STD_ON == ECUM_DET_ERROR_REPORT) */

/* Check if current file and Rte_Main.h header file are of the same Autosar version */
#if(\
		(ECUM_AR_RELEASE_MAJOR_VERSION_C != RTE_MAIN_AR_RELEASE_MAJOR_VERSION) || \
		(ECUM_AR_RELEASE_MINOR_VERSION_C != RTE_MAIN_AR_RELEASE_MINOR_VERSION)  \
	)
/*#error "AutoSar Version Number of EcuM.c and Rte_Main.h are different "*/
#endif

/* Check if current file and Rte_PBCfg.h header file are of the same Autosar version */
#if(\
		(ECUM_AR_RELEASE_MAJOR_VERSION_C != RTE_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
		(ECUM_AR_RELEASE_MINOR_VERSION_C != RTE_PBCFG_AR_RELEASE_MINOR_VERSION)  \
	)
/*#error "AutoSar Version Number of EcuM.c and Rte_PBCfg.h are different "*/
#endif

/* Check if current file and BswM.h header file are of the same Autosar version */
#if(\
		(ECUM_AR_RELEASE_MAJOR_VERSION_C != BSWM_AR_RELEASE_MAJOR_VERSION) || \
		(ECUM_AR_RELEASE_MINOR_VERSION_C != BSWM_AR_RELEASE_MINOR_VERSION)  \
	)
/*#error "AutoSar Version Number of EcuM.c and BswM.h are different "*/
#endif

/* Check if current file and BswM_EcuM.h header file are of the same Autosar version */
#if(\
		(ECUM_AR_RELEASE_MAJOR_VERSION_C != BSWM_ECUM_AR_RELEASE_MAJOR_VERSION) || \
		(ECUM_AR_RELEASE_MINOR_VERSION_C != BSWM_ECUM_AR_RELEASE_MINOR_VERSION)  \
	)
/*#error "AutoSar Version Number of EcuM.c and BswM_EcuM.h are different "*/
#endif

#if (STD_ON == ECUM_INCLUDE_COMM)
/* Check if current file and ComM_EcuMBswM.h header file are of the same Autosar version */
#if(\
		(ECUM_AR_RELEASE_MAJOR_VERSION_C != COMM_ECUMBSWM_AR_RELEASE_MAJOR_VERSION) || \
		(ECUM_AR_RELEASE_MINOR_VERSION_C != COMM_ECUMBSWM_AR_RELEASE_MINOR_VERSION)  \
	)
/*#error "AutoSar Version Number of EcuM.c and ComM_EcuMBswM.h are different "*/
#endif
#endif
#endif /* #ifndef DISABLE_INTERMOD_VERSION_CHECK */
/*====================================================================================================*
 *                                   EXTERNAL FUNCTION DECLARATIONS
 *====================================================================================================*/

/*====================================================================================================*
 *                                           LOCAL TYPEDEFS
 *====================================================================================================*/
/**
 * @brief EcuM internal user state - The user is in the state of RUN and POSTRUN
 */
typedef struct
{
	/**< @brief AppRun status request status*/
	VAR(boolean, AUTOMATIC) EcuM_AppRunState;
	/**< @brief PostRun status request status*/
	VAR(boolean, AUTOMATIC) EcuM_PostRunState;
} EcuM_InternalUserType;

/**
 * @brief EcuM internal data
 */
typedef struct
{
	/**< @brief The EcuM  shutdown target*/
	VAR(EcuM_ShutdownTargetType, AUTOMATIC) EcuM_ShutdownTarget;
	/**< @brief The EcuM last shutdown target */
	VAR(EcuM_ShutdownTargetType, AUTOMATIC) EcuM_LastShutdownTarget;
	/**< @brief The EcuM shutdown cause*/
	VAR(EcuM_ShutdownCauseType, AUTOMATIC) EcuM_ShutdownCase;
	/**< @brief The EcuM shutdown mode*/
	VAR(EcuM_ShutdownModeType, AUTOMATIC) EcuM_ShutdownMode;
	/**< @brief The EcuM last shutdown mode*/
	VAR(EcuM_ShutdownModeType, AUTOMATIC) EcuM_LastShutdownMode;
	/**< @brief Wake-up events to be verified*/
	VAR(EcuM_WakeupSourceType, AUTOMATIC) EcuM_PendingWakeupEvents;
	/**< @brief Wake-up events that are pending verification but have been turned on*/
	VAR(EcuM_WakeupSourceType, AUTOMATIC) EcuM_StartWakeupEvents;
	/**< @brief Wake-up events that are validated*/
	VAR(EcuM_WakeupSourceType, AUTOMATIC) EcuM_ValidatedWakeupEvents;
	/**< @brief Wake-up events that are timed out */
	VAR(EcuM_WakeupSourceType, AUTOMATIC) EcuM_ExpiredWakeupEvents;
	/**< @brief Enable wake-up events */
	VAR(EcuM_WakeupSourceType, AUTOMATIC) EcuM_EnabledWakeupEvents;
#if (STD_ON == ECUM_ALARM_CLOCK_PRESENT)
	/**< @brief EcuM running time */
	VAR(uint32, AUTOMATIC) EcuM_RunTimer;
	/**< @brief Master alarm clock in EcuM */
	VAR(uint32, AUTOMATIC) EcuM_AlarmTimer;
	/**< @brief User alarm clock in EcuM */
	VAR(uint32, AUTOMATIC) EcuM_UserAlarmTimer[ECUM_ALARM_NUM];
#endif /* STD_ON == ECUM_ALARM_CLOCK_PRESENT */
	/**< @brief Running status of EcuM users*/
	VAR(EcuM_InternalUserType, AUTOMATIC) EcuM_User[ECUM_FLEX_USER_NUM];
	/**< @brief Maximum verification elapsed time of wake-up source to be verified */
	VAR(uint16, AUTOMATIC) EcuM_WakeupExpiredTimer[ECUM_WAKEUP_SOURCE_NUM];
} EcuM_InternalType;

/*====================================================================================================*
 *                                            LOCAL MACROS
 *====================================================================================================*/

/* Unit test Macro */
#ifdef	AH_ECUM_UNITTEST_ENABLED

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

#endif

/**
 * @brief Get the Reset mode
 */
/* PRQA S 3453  EOF# violate MSIAR2004_19.7: The macro definition is valid*/
/* PRQA S 3410  EOF# violate MSIAR2004_19.10: The  macro function processing is valid*/
#define ECUM_GET_RESET_MODE(EcuM_ShutdownMode)\
((EcuM_ResetType)(((EcuM_ShutdownModeType)EcuM_ShutdownMode & (EcuM_ShutdownModeType)0xFF00) >> 8))

/**
 * @brief Get the Mcu mode corresponding to the sleep mode
 */
#define ECUM_GET_MCU_MODE(EcuM_ShutdownMode) \
	(EcuM_ConfigPtr->EcuM_CommonConfigurationPtr->\
	EcuM_SleepModePtr[(uint8)EcuM_ShutdownMode].EcuM_SleepModeMcuModeRef)

/**
 * @brief Get the flags that correspond to sleep patterns, true-Halt, false -Poll
 */
#define ECUM_GET_SLEEP_MODE(EcuM_ShutdownMode) \
	(EcuM_ConfigPtr->EcuM_CommonConfigurationPtr->\
			EcuM_SleepModePtr[(uint8)EcuM_ShutdownMode].EcuM_SleepModeSuspend)

/**
 * @brief When the alarm clock service is turned,check the sign for the alarm clock user
 */
#if (STD_ON == ECUM_ALARM_CLOCK_PRESENT)
#define ECUM_SET_CLOCK_USER_CHECK	((uint8)0U)
#endif /* STD_ON == ECUM_ALARM_CLOCK_PRESENT */

/**
 * @brief Cheak flags against the user who calls the EcuM_GoDown() interface
 */
#define ECUN_GO_DOWN_USER_CHECK		((uint8)1U)

/*====================================================================================================*
 *                                           LOCAL CONSTANTS
 *====================================================================================================*/

/*====================================================================================================*
 *                                           LOCAL VARIABLES
 *====================================================================================================*/

#define ECUM_START_SEC_CONST_UNSPECIFIED
#include "EcuM_MemMap.h"/* PRQA S 5087 EOF # violate MISAR_19.1: This is correct*/

/**
 * @brief  A structure for storing EcuM configurations
 */
STATIC P2CONST(EcuM_ConfigType, ECUM_VAR, ECUM_APPL_CONST) EcuM_ConfigPtr = NULL_PTR;

#define ECUM_STOP_SEC_CONST_UNSPECIFIED
#include "EcuM_MemMap.h"

#define ECUM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "EcuM_MemMap.h"

/**
 * @brief  The structure of EcuM's internal data
 */
STATIC VAR(EcuM_InternalType, ECUM_VAR) EcuM_InternalState;

#define ECUM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "EcuM_MemMap.h"

#define ECUM_START_SEC_VAR_INIT_8
#include "EcuM_MemMap.h"

/**
 * @brief  The boot target of the ECU State Manager
 */
STATIC VAR(EcuM_BootTargetType, ECUM_VAR) EcuM_BootTarget = ECUM_BOOT_TARGET_OEM_BOOTLOADER;

#define ECUM_STOP_SEC_VAR_INIT_8
#include "EcuM_MemMap.h"
/*====================================================================================================*
 *                                      LOCAL FUNCTION PROTOTYPES
 *====================================================================================================*/
#define ECUM_START_SEC_CODE
#include "EcuM_MemMap.h"

STATIC FUNC(Std_ReturnType, ECUM_CODE) EcuM_CheckConf
(
	P2CONST(EcuM_ConfigType, AUTOMATIC, ECUM_APPL_CONST) EcuM_ConfigPion
);

STATIC FUNC(void, ECUM_CODE) EcuM_MapToWakeUp
(
	VAR(Mcu_ResetType, AUTOMATIC) EcuM_Mcu_Reset
);

STATIC FUNC(Std_ReturnType, ECUM_CODE) EcuM_StartPreOS(void);

STATIC FUNC(void, ECUM_CODE) EcuM_OffPreOS(void);

STATIC FUNC(void, ECUM_CODE) EcuM_OffPostOS(void);

STATIC FUNC(void, ECUM_CODE) EcuM_GoSleep
(
	CONST(EcuM_ShutdownModeType, AUTOMATIC) shutdownMode
);

STATIC FUNC(void, ECUM_CODE) EcuM_ReportCurrentStatus
(
	CONST(EcuM_WakeupSourceType, AUTOMATIC) pendingWkSource
);

STATIC FUNC(void, ECUM_CODE) EcuM_Halt(void);

STATIC FUNC(void, ECUM_CODE) EcuM_Polling(void);

STATIC FUNC(void, ECUM_CODE) EcuM_WakeupRestart(void);

STATIC FUNC(void, ECUM_CODE) EcuM_WakeupValidation(void);

#if (STD_ON == ECUM_ALARM_CLOCK_PRESENT)
STATIC FUNC(void, ECUM_CODE) EcuM_UpdateEcuMClock(void);
#endif /* STD_ON == ECUM_ALARM_CLOCK_PRESENT */

#if (STD_ON == ECUM_MODE_HANDLING)
STATIC FUNC(void, ECUM_CODE) EcuM_ArbitrateAction(void);
#endif /* STD_ON == ECUM_MODE_HANDLING */

STATIC FUNC(Std_ReturnType, ECUM_CODE) EcuM_CheckShutdownTarget
(
	CONST(EcuM_ShutdownTargetType, AUTOMATIC) shutdownTarget,
	CONST(EcuM_ShutdownModeType,   AUTOMATIC) shutdownMode
);

#if (STD_ON == ECUM_ALARM_CLOCK_PRESENT)
STATIC FUNC(Std_ReturnType, ECUM_CODE) EcuM_SetUserAlarm
(
	CONST(EcuM_UserType, AUTOMATIC) user,
	CONST(EcuM_TimeType, AUTOMATIC) time /* PRQA S 4604  # violate MSIAR2004_20.2: This  valid */
);
#endif /* STD_ON == ECUM_ALARM_CLOCK_PRESENT */

#if (STD_ON == ECUM_ALARM_CLOCK_PRESENT)
STATIC FUNC(Std_ReturnType, ECUM_CODE) EcuM_UpdateGlobalAlarm(void);
#endif /* STD_ON == ECUM_ALARM_CLOCK_PRESENT */

STATIC FUNC(Std_ReturnType, ECUM_CODE) EcuM_CheckUser
(
	CONST(uint8, AUTOMATIC) checkType,
	CONST(EcuM_UserType, AUTOMATIC) user
);

STATIC FUNC(void, ECUM_CODE) EcuM_StartValidationTimer
(
	CONST(EcuM_WakeupSourceType, AUTOMATIC) sources
);

STATIC FUNC(void, ECUM_CODE) EcuM_TimeoutValidation
(
	CONST(EcuM_WakeupSourceType, AUTOMATIC) sources
);

#if (STD_ON == ECUM_ALARM_CLOCK_PRESENT)
STATIC FUNC(void, ECUM_CODE) EcuM_CanCelAllAlarm(void);
#endif /* STD_ON == ECUM_ALARM_CLOCK_PRESENT */

STATIC FUNC(void, ECUM_CODE) EcuM_InternalParametersInit(void);

#define ECUM_STOP_SEC_CODE
#include "EcuM_MemMap.h"

/*====================================================================================================*
 *                                           LOCAL FUNCTIONS
 *====================================================================================================*/

#define ECUM_START_SEC_CODE
#include "EcuM_MemMap.h"

/**
 * @brief          Check to see if the configuration is correct.
 * @return         Std_ReturnType
 * @retval         E_OK - Correct configuration.
 * @retval         E_NOT_OK - Configuration error.
 */
STATIC FUNC(Std_ReturnType, ECUM_CODE) EcuM_CheckConf
(
	P2CONST(EcuM_ConfigType, AUTOMATIC, ECUM_APPL_CONST) EcuM_ConfigPion
)
{
	VAR(Std_ReturnType, AUTOMATIC) ret = (Std_ReturnType)E_OK;
	if(ECUM_CONFIGCONSISTENCY_HASH != EcuM_ConfigPion->EcuM_ConfigConsistencyHash)
	{
		ret = (Std_ReturnType)E_NOT_OK;
	}
	else
	{
		/* Do nothing */
	}
	return ret;
}

/**
 * @brief          The reset reason obtained by MCU is mapped to the wake source
 * @param[in]      EcuM_Mcu_Reset - Cause of reset of MCU acquisition
 */
STATIC FUNC(void, ECUM_CODE) EcuM_MapToWakeUp
(
	VAR(Mcu_ResetType, AUTOMATIC) EcuM_Mcu_Reset
)
{
	VAR(boolean, AUTOMATIC) isFind = (boolean)FALSE;
	VAR(uint8, AUTOMATIC) count1 ;
	VAR(uint8, AUTOMATIC) count2 ;

	for(count1 = (uint8)0; count1 < (uint8)ECUM_WAKEUP_SOURCE_NUM; count1++) 
	{
		/* PRQA S 0491  EOF# violate MSIAR2004_17.4: The processing is valid here */
		VAR(uint8, AUTOMATIC) numberOfResetReason = \
				           EcuM_ConfigPtr->EcuM_CommonConfigurationPtr->\
				                   EcuM_WakeupSourcePtr[count1].EcuM_NumberOfResetReason;
		P2CONST(uint8, AUTOMATIC, ECUM_APPL_CONST) resetReasonPtr = \
				           EcuM_ConfigPtr->EcuM_CommonConfigurationPtr->\
				                     EcuM_WakeupSourcePtr[count1].EcuM_ResetReasonRefPtr;
		for(count2 = (uint8)0; count2 < (uint8)numberOfResetReason; count2++)
		{
			if(resetReasonPtr[count2] == (uint8)EcuM_Mcu_Reset)
			{
				/**
				 * @req [SWS_EcuM_02623] The ECU Manager module shall remember the wakeup source
				 *      resulting from the reset reason translation
				 */
				EcuM_InternalState.EcuM_EnabledWakeupEvents |= \
						                EcuM_ConfigPtr->EcuM_CommonConfigurationPtr->\
						                      EcuM_WakeupSourcePtr[count1].EcuM_WakeupSourceMask;
				EcuM_InternalState.EcuM_PendingWakeupEvents |= \
						                        EcuM_ConfigPtr->EcuM_CommonConfigurationPtr->\
												  EcuM_WakeupSourcePtr[count1].EcuM_WakeupSourceMask;
				if(ECUM_WAKEUP_SOURCE_NONE != (ECUM_WAKEUP_SOURCE_NO_VALIDATION_MASK & \
						                                EcuM_InternalState.EcuM_PendingWakeupEvents))
				{
					EcuM_InternalState.EcuM_ValidatedWakeupEvents |= \
							                          EcuM_InternalState.EcuM_PendingWakeupEvents;
					EcuM_InternalState.EcuM_PendingWakeupEvents = ECUM_WAKEUP_SOURCE_NONE;
				}
				else
				{
					/* Do nothing */
				}
				isFind = (boolean)TRUE;
				break;
			}
			else
			{
				/* Do nothing */
			}
		}
	}

	if((boolean)FALSE == isFind)
	{
		/**
		 * @req [SWS_EcuM_02623] The ECU Manager module shall remember the wakeup source resulting
		 *      from the reset reason translation .
		 * @req [SWS_EcuM_02601] If the EcuM cannot determine the reset reason returned by the
		 *      Mcu driver, then the EcuM set a wakeup event for default wakeup source
		 *      ECUM_WKSOURCE_RESET instead.
		 */
		EcuM_InternalState.EcuM_EnabledWakeupEvents |= ECUM_WKSOURCE_RESET;
		EcuM_InternalState.EcuM_ValidatedWakeupEvents |= ECUM_WKSOURCE_RESET;
	}
	else
	{
		/* Do nothing */
	}
}

/**
 * @brief          Implement of StartPreOS stage.
 * @details        Call EcuM_AL_DriverInitZero, check consistency, get post-build configuration,
 *                 select default shutdown target and initialize internal parameters for EcuM.
 * @return         Std_ReturnType
 * @retval         E_OK - Successful StartPreOS stage.
 * @retval         E_NOT_OK - Failed StartPreOS stage.
 */
STATIC FUNC(Std_ReturnType, ECUM_CODE) EcuM_StartPreOS(void)
{
	VAR(Std_ReturnType, AUTOMATIC) ret = (Std_ReturnType) E_OK;
	VAR(Mcu_ResetType, AUTOMATIC) EcuM_Mcu_Reset;

#if(STD_ON == ECUM_SET_PROGRAMMABLE_INTERRUPTS)
	EcuM_AL_SetProgrammableInterrupts();
#endif /* STD_ON == ECUM_SET_PROGRAMMABLE_INTERRUPTS */

#if(STD_ON == ECUM_DRIVER_INIT_LIST_ZERO)
	EcuM_AL_DriverInitZero();
#endif /* STD_ON == ECUM_DRIVER_INIT_LIST_ZERO */

	/* Obtain the EcuM configuration struct pointer. */
	EcuM_ConfigPtr = EcuM_DeterminePbConfiguration();

	/* Check consistency */
	if((Std_ReturnType)E_OK != EcuM_CheckConf(EcuM_ConfigPtr))
	{
		EcuM_ErrorHook(ECUM_E_CONFIGURATION_DATA_INCONSISTENT);
		ret = (Std_ReturnType)E_NOT_OK;
	}
	else
	{
		/* Do nothing */
	}

	if(ret != (Std_ReturnType)E_NOT_OK)
	{
#if(STD_ON == ECUM_DRIVER_INIT_LIST_ONE)
		EcuM_AL_DriverInitOne(EcuM_ConfigPtr);
#endif /* STD_ON == ECUM_DRIVER_INIT_LIST_ONE */

		/* Initialize internal parameters */
		EcuM_InternalParametersInit();

		EcuM_Mcu_Reset = Mcu_GetResetReason();

		EcuM_MapToWakeUp(EcuM_Mcu_Reset);
		/**
		 * @req [SWS_EcuM_02181] The ECU Manager module shall call EcuM_SelectShutdownTarget with the
		 *      configured default shutdown target
		 */
		ret = EcuM_SelectShutdownTarget(
				EcuM_ConfigPtr->EcuM_CommonConfigurationPtr->
				EcuM_DefaultShutdownTargetPtr->EcuM_DefaultState,
				EcuM_ConfigPtr->EcuM_CommonConfigurationPtr->
				EcuM_DefaultShutdownTargetPtr->EcuM_DefaultShutdownMode);
#if(STD_ON == ECUM_RESET_LOOP_DETECTION)
		EcuM_LoopDetection();
#endif /* STD_ON == ECUM_RESET_LOOP_DETECTION */

	}
	else
	{
		/* Do nothing */
	}

	return ret;
}

/**
 * @brief          Performs pre-close processing
 * @return         NULL
 * @retval         NULL
 */
STATIC FUNC(void, ECUM_CODE) EcuM_OffPreOS(void)
{
	EcuM_InternalState.EcuM_LastShutdownMode = EcuM_InternalState.EcuM_ShutdownMode;
	EcuM_InternalState.EcuM_LastShutdownTarget = EcuM_InternalState.EcuM_ShutdownTarget;
	/* Notify the BswM module of the current status of the EcuM module. */
	BswM_EcuM_CurrentState(ECUM_STATE_SHUTDOWN);
#if(STD_ON == ECUM_ALARM_CLOCK_PRESENT)
	/**
	 * @req [SWS_EcuM_04010] ⌈User alarms and the master alarm shall be cancelled during
	 *      the StartPreOS Sequence, in the WakeupRestart Sequence and the OffPreOS Sequence.
	 */
	EcuM_CanCelAllAlarm();
#endif /* STD_ON == ECUM_ALARM_CLOCK_PRESENT */
	EcuM_OnGoOffOne();
	BswM_Deinit();
	//SchM_Deinit();
	/**
	 * @req [SWS_EcuM_02756] When a wakeup event occurs during the shutdown phase, the
     *      ECU Manager module shall complete the shutdown and restart immediately thereafter.
	 */
	if(ECUM_WAKEUP_SOURCE_NONE != EcuM_GetPendingWakeupEvents())
	{
		/* Set RESET as shutdown target */
		EcuM_SelectShutdownTarget(ECUM_SHUTDOWN_TARGET_RESET, EcuM_InternalState.EcuM_ShutdownMode);/* PRQA S 3200  # violate MSIAR2004_16.10: The return value of the function does not need to be considered*/
	}
	else
	{
		/* Do nothing */
	}
	/**
	 * @req [SWS_EcuM_02952] As its last activity, the ECU Manager module shall call the ShutdownOS function.
	 */
	//ShutdownOS((StatusType)E_OK);
}

/**
 * @brief          The OffPostOS sequence implements the final steps to reach the shutdown target
 *                 after the OS has been shut down
 * @return         NULL
 * @retval         NULL
 */
STATIC FUNC(void, ECUM_CODE) EcuM_OffPostOS(void)
{
	EcuM_OnGoOffTwo();
	/**
	 * @req [SWS_EcuM_03022] The SHUTDOWN phase handles the controlled shutdown of
	 *      basic software modules and finally results in the selected shutdown target OFF or RESET.
	 * @req [SWS_EcuM_04074] When the shutdown target is RESET, the ECU Manager module shall call
	 *      the EcuM_AL_Reset callout. See section 8.6.3.4 EcuM_AL_Reset(SWS_EcuM_04065) for details.
	 */
	if(ECUM_SHUTDOWN_TARGET_RESET == EcuM_InternalState.EcuM_ShutdownTarget)
	{
		EcuM_AL_Reset(ECUM_GET_RESET_MODE(EcuM_InternalState.EcuM_ShutdownMode));
	}
	/**
	 * @req [SWS_EcuM_04075] When the shutdown target is OFF, the ECU Manager module
     *      shall call the EcuM_AL_SwitchOff callout.
	 */
	else if(ECUM_SHUTDOWN_TARGET_OFF == EcuM_InternalState.EcuM_ShutdownTarget)
	{
		EcuM_AL_SwitchOff();
	}
	else
	{
		/* error: Wrong shutdown mode */
		while(1)
		{}
	}
}

/**
 * @brief          In the GoSleep sequence the ECU Manager module configures hardware for the
 *                 upcoming sleep phase and sets the ECU up for the next wakeup event
 * @param[in]      shutdownMode - The shutdown mode for EcuM
 * @return         NULL
 * @retval         NULL
 */
STATIC FUNC(void, ECUM_CODE) EcuM_GoSleep
(
	CONST(EcuM_ShutdownModeType, AUTOMATIC) shutdownMode
)
{
#if defined(OSRESOURCE)
	VAR(uint32, AUTOMATIC) count = 0U;
#endif
	VAR(uint8, AUTOMATIC) sleepMode = (uint8)(shutdownMode & (EcuM_ShutdownModeType)0x00ff);
	VAR(EcuM_WakeupSourceType, AUTOMATIC) source = EcuM_ConfigPtr->EcuM_CommonConfigurationPtr->\
			EcuM_SleepModePtr[sleepMode].EcuM_WakeupSourceMask;

	EcuM_InternalState.EcuM_LastShutdownMode = EcuM_InternalState.EcuM_ShutdownMode;
	EcuM_InternalState.EcuM_LastShutdownTarget = EcuM_InternalState.EcuM_ShutdownTarget;

	/* Notify the BswM module of the current status of the EcuM module. */
	BswM_EcuM_CurrentState(ECUM_STATE_SLEEP);
	/* Non-Autosar: Clear the current wake-up source before reporting the current status to
	 * the BswM module (clear all wakeup sources)*/
	EcuM_ClearWakeupEvent((EcuM_WakeupSourceType)0xffffffffU);
	BswM_EcuM_CurrentWakeup(source, ECUM_WKSTATUS_NONE);
	/**
	 * @req [SWS_EcuM_02389] To set the wakeup sources up for the next sleep mode, the ECU Manager
	 *      module shall execute the EcuM_EnableWakeupSources callout  for each wakeup source that
	 *      is configured in EcuMWakeupSourceMask .
	 */
	EcuM_EnableWakeupSources(source);
	/* Save the enabled wake-up source */
	EcuM_InternalState.EcuM_EnabledWakeupEvents |= source;
	/**
	 * @req [SWS_EcuM_04003] When an ECU Manager action causes the state of a wakeup source to
	 *      change, the ECU Manager module shall issue a mode request to the BswM to change the
	 *      wakeup source’s mode to the new the wakeup source state.
	 */
	BswM_EcuM_CurrentWakeup(source, ECUM_WKSTATUS_ENABLED);
#if defined(OSRESOURCE)
	/**
	 * @req [SWS_EcuM_03010] When operating on a multicore ECU ECUM shall reserve a dedicated
     *      resource (RES_AUTOSAR_ECUM) for each core, which is allocated during GoSleep.
	 */
	for(count = 0; count < ECUM_OS_RESOURCE_NUM; count++)
	{
		GetResource(EcuM_ConfigPtr->EcuM_CommonConfigurationPtr->EcuM_OsResource[count]);
	}
#endif
}

/**
 * @brief          Reports the status of the current wake-up source
 * @param[in]      pendingWkSource - The currently suspended wake source
 * @return         NULL
 * @retval         NULL
 */
STATIC FUNC(void, ECUM_CODE) EcuM_ReportCurrentStatus
(
	CONST(EcuM_WakeupSourceType, AUTOMATIC) pendingWkSource
)
{
	VAR(EcuM_WakeupSourceType, AUTOMATIC) validatedSource = \
			pendingWkSource & ECUM_WAKEUP_SOURCE_NO_VALIDATION_MASK;
	VAR(EcuM_WakeupSourceType, AUTOMATIC) pendingSource = \
			pendingWkSource & (~validatedSource);

	/* Update the PENDING event (Culling wake-up sources that don't require validation) */
	EcuM_InternalState.EcuM_PendingWakeupEvents = pendingSource;
	/**
	 * @req [SWS_EcuM_02566] The ECU Manager module shall only invoke wakeup validation on
	 * 		those wakeup sources where it is required by configuration. If the validation protocol
	 * 		is not configured (see EcuMValidationTimeout ECUC_EcuM_00150), then a call to
	 * 		EcuM_SetWakeupEvent (see SWS_EcuM_02826) shall also imply a call to
	 * 		EcuM_ValidateWakeupEvent (see SWS_EcuM_02829).
     * @req [SWS_EcuM_02976] If a wakeup event does not require validation, the ECU Manager
     *      module shall issue a mode switch request to set the event’s mode to
     *      ECUM_WKSTATUS_VALIDATED.
	 */
	if(ECUM_WAKEUP_SOURCE_NONE != validatedSource)
	{
		EcuM_ValidateWakeupEvent(validatedSource);
	}
	else
	{
		/* Do nothing */
	}

	if(ECUM_WAKEUP_SOURCE_NONE != pendingSource)
	{
		BswM_EcuM_CurrentWakeup(pendingSource, ECUM_WKSTATUS_PENDING);
	}
	else
	{
		/* Do nothing */
	}

}

/**
 * @brief          The ECU Manager module shall execute the Halt Sequence in sleep modes
 *                 that halt the microcontroller
 * @return         NULL
 * @retval         NULL
 */
STATIC FUNC(void, ECUM_CODE) EcuM_Halt(void)
{
#if (ECUM_ALARM_CLOCK_PRESENT == STD_ON)
	VAR(boolean, AUTOMATIC) alarmTimeout = (boolean)FALSE;
#endif /* ECUM_ALARM_CLOCK_PRESENT == STD_ON */

	VAR(EcuM_WakeupSourceType, AUTOMATIC) pendingWkup = EcuM_GetPendingWakeupEvents();
	/**
	 * @req [SWS_EcuM_02963] If a wakeup event  occurs while the ECU is in Halt or Poll, then the
	 *      ECU Manager Specification of ECU State Manager module shall regain control and exit the
	 *      SLEEP phase by executing the WakeupRestart sequence.
	 */
	if(ECUM_WAKEUP_SOURCE_NONE == pendingWkup)
	{
#if (ECUM_ALARM_CLOCK_PRESENT == STD_ON)
		while
		(
			((boolean)FALSE == alarmTimeout)
		)
		{
#endif /* ECUM_ALARM_CLOCK_PRESENT == STD_ON */
			DisableAllInterrupts();
			/**
			 * @req [SWS_EcuM_02863] The ECU Manager module shall invoke the EcuM_GenerateRamHash
			 *      callout before halting the microcontroller the EcuM_CheckRamHash callout after
			 *      the processor returns from halt.
			 */
			EcuM_GenerateRamHash();
			/**
			 * @req [SWS_EcuM_02960] The ECU Manager module shall execute the Halt Sequence in
             *      sleep modes that halt the microcontroller. In these sleep modes the ECU Manager
             *      module does not execute any code.
			 */
			Mcu_SetMode((Mcu_ModeType)ECUM_GET_MCU_MODE(EcuM_InternalState.EcuM_ShutdownMode));
#if (ECUM_ALARM_CLOCK_PRESENT == STD_ON)
			if((EcuM_GetPendingWakeupEvents() & (~(EcuM_WakeupSourceType)ECUM_ALARM_WAKEUP_SOURCE)) != \
					                                                         ECUM_WAKEUP_SOURCE_NONE)
			{
				/* Be awakened by other sources of arousal */
				alarmTimeout = (boolean)TRUE;
			}
			else
			{
				if(EcuM_InternalState.EcuM_RunTimer >= EcuM_InternalState.EcuM_AlarmTimer)
				{
					/* The alarm has expired */
					alarmTimeout = (boolean)TRUE;
					/* Set an alarm wake-up event */
					EcuM_SetWakeupEvent(ECUM_ALARM_WAKEUP_SOURCE);
				}
				else
				{
					/* Do nothing */
				}
			}
		}
#endif /* ECUM_ALARM_CLOCK_PRESENT == STD_ON */
	}
	else
	{
		/* Do nothing */
	}

	EnableAllInterrupts();
	if((uint8)E_OK != EcuM_CheckRamHash())
	{
		EcuM_ErrorHook(ECUM_E_RAM_CHECK_FAILED);
	}
	else
	{
		/* Do nothing */
	}

	pendingWkup = EcuM_GetPendingWakeupEvents();

	EcuM_ReportCurrentStatus(pendingWkup);
}

/**
 * @brief          The ECU Manager module shall execute the Poll Sequence in sleep modes that reduce
 *                 the power consumption of the microcontroller but still execute code
 * @return         NULL
 * @retval         NULL
 */
STATIC FUNC(void, ECUM_CODE) EcuM_Polling(void)
{
	VAR(uint8, AUTOMATIC) count ;
	VAR(EcuM_WakeupSourceType, AUTOMATIC) pendingWkup = EcuM_GetPendingWakeupEvents();
	/**
	 * @req [SWS_EcuM_02963] If a wakeup event  occurs while the ECU is in Halt or Poll, then the
	 *      ECU Manager Specification of ECU State Manager module shall regain control and exit the
	 *      SLEEP phase by executing the WakeupRestart sequence.
	 */
	if(ECUM_WAKEUP_SOURCE_NONE == pendingWkup)
	{
		DisableAllInterrupts();
		/**
		 * @req [SWS_EcuM_02962] The ECU Manager module shall execute the Poll Sequence in sleep
		 *      modes that reduce the power consumption of the microcontroller but still execute code.
		 */
		Mcu_SetMode((Mcu_ModeType)(Mcu_ModeType)ECUM_GET_MCU_MODE(\
				                                             EcuM_InternalState.EcuM_ShutdownMode));
		EnableAllInterrupts();
		while
		(
			(ECUM_WAKEUP_SOURCE_NONE == pendingWkup)
		)
		{
			/* Update the clock */
			EcuM_SleepActivity();
			for(count = 0U; count < ECUM_WAKEUP_SOURCE_NUM; count++)
			{
				if(ECUM_WAKEUP_SOURCE_NONE != (( EcuM_InternalState.EcuM_EnabledWakeupEvents & \
						                 ECUM_WAKEUP_SOURCE_NEED_POLL_MASK) & ((uint32)1u << count) ))/* PRQA S 2984  EOF# violate MSIAR2004_21.1: This operaion is valid. */
				{
					EcuM_CheckWakeup((EcuM_WakeupSourceType)((uint32)1u << count));
				}
				else
				{
					/* Do nothing */
				}
			}

#if(ECUM_ALARM_CLOCK_PRESENT == STD_ON)
			/* PRQA S 2992  EOF# violate MSIAR2004_13.7: This operation is valid. */
			/* PRQA S 2996  EOF# violate MSIAR2004_13.7: This operation is valid. */
			if((pendingWkup & (~(EcuM_WakeupSourceType)ECUM_ALARM_WAKEUP_SOURCE)) != \
					                                                       ECUM_WAKEUP_SOURCE_NONE)
			{
				/* Do nothing */
			}
			else
			{
				if(EcuM_InternalState.EcuM_RunTimer >= EcuM_InternalState.EcuM_AlarmTimer)
				{
					EcuM_SetWakeupEvent(ECUM_ALARM_WAKEUP_SOURCE);
				}
				else
				{
					EcuM_InternalState.EcuM_PendingWakeupEvents &= \
							                        ~(EcuM_WakeupSourceType)ECUM_ALARM_WAKEUP_SOURCE;
				}
			}
#endif /* ECUM_ALARM_CLOCK_PRESENT == STD_ON */
			pendingWkup = EcuM_GetPendingWakeupEvents();
		}
	}
	else
	{
		/* Do nothing */
	}

	EcuM_ReportCurrentStatus(pendingWkup);
}

/**
 * @brief         Implement of WakeupRestart stage.
 * @details       Set normal Mcu mode, disable pending wakeup sources, and call EcuM_AL_DriverRestart
 *                to restart stopped drivers.
 * @return        NULL
 * @retval        NULL
 */
STATIC FUNC(void, ECUM_CODE) EcuM_WakeupRestart(void)
{
#if defined(OSRESOURCE)
	VAR(uint32, AUTOMATIC) count = 0U;
#endif
	VAR(EcuM_WakeupSourceType, AUTOMATIC) disableWkSources;
	DisableAllInterrupts();
	Mcu_SetMode((Mcu_ModeType)EcuM_ConfigPtr->EcuM_FlexConfigurationPtr->EcuM_NormalMcuModeRef);
	EnableAllInterrupts();

	/* Disable events that have already woken up */
	disableWkSources = EcuM_GetPendingWakeupEvents();
	disableWkSources |= EcuM_GetValidatedWakeupEvents();
	EcuM_InternalState.EcuM_EnabledWakeupEvents &= ~disableWkSources;
	EcuM_DisableWakeupSources(disableWkSources);

	EcuM_AL_DriverRestart(EcuM_ConfigPtr);

#if(STD_ON == ECUM_ALARM_CLOCK_PRESENT)
	/**
	 * @req [SWS_EcuM_04010] Cancel all alarms
	 */
	EcuM_CanCelAllAlarm();
#endif /* STD_ON == ECUM_ALARM_CLOCK_PRESENT */

#if defined(OSRESOURCE)
	/* Unlock Scheduler : From this point on ,all other tasks may run again */
	for(count = ECUM_OS_RESOURCE_NUM; count > 0; count--)
	{
		ReleaseResource(EcuM_ConfigPtr->EcuM_CommonConfigurationPtr->EcuM_OsResource[count-1]);
	}
#endif

}

/**
 * @brief         Implement of WakeupValidation stage.
 * @details       Loop to validate pending wakeup events.
 * @return         NULL
 * @retval         NULL
 */
STATIC FUNC(void, ECUM_CODE) EcuM_WakeupValidation(void)
{
	/* Get the wake-up events that are pending but not start */
	VAR(EcuM_WakeupSourceType, AUTOMATIC) startWkSources =\
		  EcuM_InternalState.EcuM_PendingWakeupEvents & (~EcuM_InternalState.EcuM_StartWakeupEvents);
	/* Get the wake-up events that are pending but not notified to the BswM */
	VAR(EcuM_WakeupSourceType, AUTOMATIC) newPendingWkSources =\
		  EcuM_InternalState.EcuM_PendingWakeupEvents & EcuM_InternalState.EcuM_EnabledWakeupEvents;
	/* Get the wake-up events that have been verified but are still enabled */
	VAR(EcuM_WakeupSourceType, AUTOMATIC) newValidatedWkSources =\
		EcuM_InternalState.EcuM_ValidatedWakeupEvents & EcuM_InternalState.EcuM_EnabledWakeupEvents;

	/* Check if there is a wake-up source verification timeout */
	EcuM_TimeoutValidation(EcuM_InternalState.EcuM_StartWakeupEvents);

	/* Disable events that have already woken up */
	if(ECUM_WAKEUP_SOURCE_NONE != (newPendingWkSources | newValidatedWkSources))
	{
		/* Check for any new wake-up events that need to be verified */
		if(ECUM_WAKEUP_SOURCE_NONE != newPendingWkSources)
		{
			BswM_EcuM_CurrentWakeup(newPendingWkSources, ECUM_WKSTATUS_PENDING);
		}
		else
		{
			/* Do nothing */
		}
		EcuM_InternalState.EcuM_EnabledWakeupEvents &= ~(newPendingWkSources | newValidatedWkSources);
		/* Disable the wake source that has already occurred */
		EcuM_DisableWakeupSources(newPendingWkSources | newValidatedWkSources);
	}
	else
	{
		/* Do nothing */
	}

	/* Enable the wake source for the PENDING event for which the wake source is not enabled */
	if(ECUM_WAKEUP_SOURCE_NONE != startWkSources)
	{
		/* Start wake-up verification */
		EcuM_StartWakeupSources(startWkSources);
		/* Start the wake-up verification timeout timer */
		EcuM_StartValidationTimer(startWkSources);
		EcuM_InternalState.EcuM_StartWakeupEvents |= startWkSources;
	}
	else
	{
		/* Do nothing */
	}

	EcuM_CheckValidation(EcuM_GetPendingWakeupEvents());

}

#if (STD_ON == ECUM_ALARM_CLOCK_PRESENT)
/**
 * @brief          Update EcuMClock.
 * @return         NULL
 * @retval         NULL
 */
STATIC FUNC(void, ECUM_CODE) EcuM_UpdateEcuMClock(void)
{
	/* Update the internal clock (ms) */
	static uint32 runTimer_ms = (uint32)0;
	runTimer_ms += ECUM_MAIN_FUNCTION_PERIOD;
	if(runTimer_ms >= (uint32) 1000)
	{
		EcuM_InternalState.EcuM_RunTimer++;
		runTimer_ms -= (uint32)1000;
	}
	else
	{
		/* Do nothing */
	}
}
#endif /* STD_ON == ECUM_ALARM_CLOCK_PRESENT */

#if (STD_ON == ECUM_MODE_HANDLING)
/**
 * @brief        Arbitrate RUN and POST_RUN requests and releases.
 * @return         NULL
 * @retval         NULL
 */
STATIC FUNC(void, ECUM_CODE) EcuM_ArbitrateAction(void)
{
	VAR(uint8, AUTOMATIC) count;
	VAR(boolean, AUTOMATIC) isAppRunExist = (boolean)FALSE;
	VAR(boolean, AUTOMATIC) isPostRunExist = (boolean)FALSE;
	static VAR(boolean, AUTOMATIC) isAppRunReq = (boolean)FALSE;
	static VAR(boolean, AUTOMATIC) isPostRunReq = (boolean)FALSE;

	for(count = 0U; count < ECUM_FLEX_USER_NUM; count++)
	{
		if((boolean)TRUE == EcuM_InternalState.EcuM_User[count].EcuM_AppRunState)
		{
			isAppRunExist = (boolean)TRUE;
		}
		else
		{
			/* Do nothing */
		}
		if((boolean)TRUE == EcuM_InternalState.EcuM_User[count].EcuM_PostRunState)
		{
			isPostRunExist = (boolean)TRUE;
		}
		else
		{
			/* Do nothing */
		}
	}

	if(((boolean)FALSE == isAppRunReq) && ((boolean)FALSE == isPostRunReq))
	{
		if((boolean)TRUE == isAppRunExist)
		{
			BswM_EcuM_RequestedState(ECUM_STATE_APP_RUN,ECUM_RUNSTATUS_REQUESTED);
			isAppRunReq = (boolean)TRUE;
		}
		else if((boolean)TRUE == isPostRunExist)
		{
			BswM_EcuM_RequestedState(ECUM_STATE_APP_POST_RUN,ECUM_RUNSTATUS_REQUESTED);
			isPostRunReq = (boolean)TRUE;
		}
		else
		{
			/* Do nothing */
		}
	}
	/* APP_RUN Handling */
	else if((boolean)TRUE == isAppRunReq)
	{
		if((boolean)TRUE == isAppRunExist)
		{
			/* Do nothing */
		}
		else
		{
			if((boolean)TRUE == isPostRunExist)
			{
				BswM_EcuM_RequestedState(ECUM_STATE_APP_POST_RUN,ECUM_RUNSTATUS_REQUESTED);
				isPostRunReq = (boolean)TRUE;
			}
			else
			{
				/* Do nothing */
			}

			BswM_EcuM_RequestedState(ECUM_STATE_APP_RUN,ECUM_RUNSTATUS_RELEASED);
			isAppRunReq = (boolean)FALSE;
		}
	}
	/* POST_RUN Handling */
	else if((boolean)TRUE == isPostRunReq)
	{
		if((boolean)TRUE == isAppRunExist)
		{
			BswM_EcuM_RequestedState(ECUM_STATE_APP_RUN,ECUM_RUNSTATUS_REQUESTED);
			isAppRunReq = (boolean)TRUE;

			isPostRunReq = (boolean)FALSE;
		}
		else if((boolean)TRUE == isPostRunExist)
		{
			/* Do nothing */
		}
		else
		{
			BswM_EcuM_RequestedState(ECUM_STATE_APP_POST_RUN,ECUM_RUNSTATUS_RELEASED);
			isPostRunReq = (boolean)FALSE;
		}
	}
	else
	{
		/* Do nothing */
	}

}
#endif /* STD_ON == ECUM_MODE_HANDLING */

/**
 * @brief        Check that the closing target and closing mode meet the specification.
 * @param[in]    shutdownTarget - closing target.
 * 				 shutdownMode -   closing mode.
 * @return       Std_ReturnType
 * @retval       E_OK: The shutdown target and shutdown mode match
 * @retval       E_NOT_OK: The shutdown target does not match or the shutdown mode does not match
 */
STATIC FUNC(Std_ReturnType, ECUM_CODE) EcuM_CheckShutdownTarget
(
	CONST(EcuM_ShutdownTargetType, AUTOMATIC) shutdownTarget,
	CONST(EcuM_ShutdownModeType,   AUTOMATIC) shutdownMode
)
{
	VAR(Std_ReturnType, AUTOMATIC) ret = (Std_ReturnType) E_OK;
	VAR(uint8, AUTOMATIC) sleepMode = (uint8)(shutdownMode & (EcuM_ShutdownModeType)0x00ff);
	VAR(uint8, AUTOMATIC) resetMode = (uint8)((shutdownMode & (EcuM_ShutdownModeType)0xff00) >> 8);
	if
	(
		(ECUM_SHUTDOWN_TARGET_SLEEP != shutdownTarget) &&
		(ECUM_SHUTDOWN_TARGET_RESET != shutdownTarget) &&
		(ECUM_SHUTDOWN_TARGET_OFF != shutdownTarget)
	)
	{
		ret = (Std_ReturnType) E_NOT_OK;
	}
	else if(ECUM_SHUTDOWN_TARGET_SLEEP == shutdownTarget)
	{
		if(sleepMode >= ECUM_SLEEP_MODE_NUM)
		{
			ret = (Std_ReturnType) E_NOT_OK;
		}
	}
	else if(ECUM_SHUTDOWN_TARGET_RESET == shutdownTarget)
	{
		if(resetMode >= ECUM_RESET_MODE_NUM)
		{
			ret = (Std_ReturnType) E_NOT_OK;
		}
	}
	else
	{
		/* Do nothing */
	}

	return ret;
}

#if (STD_ON == ECUM_ALARM_CLOCK_PRESENT)
/**
 * @brief         Sets the alarm time for the specified useer alarm clock
 * @param[in]     user: One of these values is returned
 *                time: The alarm time to be set
 *
 * @return        Std_ReturnType
 * @retval        E_OK: The service has successed
 * @retval        E_NOT_OK: The service failed
 * @retval        ECUM_E_PAST: The alarm time set has passed,The service has failed
 */
STATIC FUNC(Std_ReturnType, ECUM_CODE) EcuM_SetUserAlarm
(
	CONST(EcuM_UserType, AUTOMATIC) user,
	CONST(EcuM_TimeType, AUTOMATIC) time/* PRQA S 4603  EOF# violate MSIAR2004_20.2: The input is valid */
)
{
	VAR(Std_ReturnType, AUTOMATIC) ret = (Std_ReturnType) E_OK;
	if(time < EcuM_InternalState.EcuM_RunTimer)
	{
		ret = (Std_ReturnType)ECUM_E_PAST;
	}
	else
	{
		VAR(uint8, AUTOMATIC) count;
		VAR(uint8, AUTOMATIC) flag = (uint8)0;
		for(count = 0U; count < ECUM_ALARM_NUM; count++)
		{
			if(EcuM_ConfigPtr->EcuM_FlexConfigurationPtr->EcuM_AlarmClockPtr[count].\
					                                                    EcuM_AlarmClockUser == user)
			{
				EcuM_InternalState.EcuM_UserAlarmTimer[count] = time;
				flag = (uint8)1;
				break;
			}
			else
			{
                /* Do nothing */
			}
		}
		if(flag == (uint8) 0)
		{
			ret = (Std_ReturnType)E_NOT_OK;
		}else{ /* Do nothing */}
	}

	return ret;
}
#endif /* STD_ON == ECUM_ALARM_CLOCK_PRESENT */

#if (STD_ON == ECUM_ALARM_CLOCK_PRESENT)
/**
 * @brief         Update the main alarm when the alarm service exists.
 * @return        Std_ReturnType
 * @retval        E_OK: The service has successed
 * @retval        ECUM_E_EARLIER_ACTIVE:  An earlier alarm is already set
 */
STATIC FUNC(Std_ReturnType, ECUM_CODE) EcuM_UpdateGlobalAlarm(void)
{
	VAR(Std_ReturnType, AUTOMATIC) ret ;
	VAR(uint8, AUTOMATIC) count ;
	VAR(uint32, AUTOMATIC) currentAlarm = ECUM_INVALID_ALARM;
	for(count = (uint8)0; count < (uint8)ECUM_ALARM_NUM; count++)
	{
		if
		(
			(EcuM_InternalState.EcuM_UserAlarmTimer[count] > EcuM_InternalState.EcuM_RunTimer) &&
			(currentAlarm > EcuM_InternalState.EcuM_UserAlarmTimer[count])
		)
		{
			currentAlarm = EcuM_InternalState.EcuM_UserAlarmTimer[count];
		}
		else
		{
			/* Do nothing */
		}
	}

	if(currentAlarm >= EcuM_InternalState.EcuM_AlarmTimer)
	{
		EcuM_InternalState.EcuM_AlarmTimer = currentAlarm;
		ret = (Std_ReturnType)E_OK;
	}
	else
	{
		EcuM_InternalState.EcuM_AlarmTimer = currentAlarm;
		ret = ECUM_E_EARLIER_ACTIVE;
	}

	return ret;
}
#endif /* STD_ON == ECUM_ALARM_CLOCK_PRESENT */

/**
 * @brief         Check that the user performing the service is compliant.
 * @param[in]     checkType - Checking the service type.
 * 				  user - ID of the user.
 * @return        Std_ReturnType
 * @retval        E_OK: Check user compliance
 * @retval        E_NOT_OK:  Check for user non-conformance
 */
STATIC FUNC(Std_ReturnType, ECUM_CODE) EcuM_CheckUser
(
	CONST(uint8, AUTOMATIC) checkType,
	CONST(EcuM_UserType, AUTOMATIC) user
)
{
	VAR(Std_ReturnType, AUTOMATIC) ret = (Std_ReturnType) E_NOT_OK;
	VAR(uint8, AUTOMATIC) count ;
    if(ECUN_GO_DOWN_USER_CHECK == checkType)
	{
		for(count = (uint8)0; count < (uint8)ECUM_GO_DOWN_ALLOWED_USERS_NUM; count++)/* PRQA S 2877  #
		                           violate MSIAR2004_21.1: This loop will be executed more than once. */
		{
			if(EcuM_ConfigPtr->EcuM_FlexConfigurationPtr->EcuM_GoDownAllowedUsersPtr[count] == user)
			{
				ret = (Std_ReturnType)E_OK;
				break;
			}
			else
			{
				/* Do nothing */
			}
		}
	}
#if (STD_ON == ECUM_ALARM_CLOCK_PRESENT)
	else if(ECUM_SET_CLOCK_USER_CHECK == checkType)
	{
		for(count = (uint8)0; count < (uint8)ECUM_SET_CLOCK_ALLOWED_USERS_NUM; count++)
		{
			if(EcuM_ConfigPtr->EcuM_FlexConfigurationPtr->EcuM_SetClockAllowedUsersPtr[count] == user)
			{
				ret = (Std_ReturnType)E_OK;
				break;
			}
			else
			{
				/* Do nothing */
			}
		}
	}
#endif /* STD_ON == ECUM_ALARM_CLOCK_PRESENT */
	else
	{
		/* Do nothing */
	}
	return ret;
}

/**
 * @brief         Assign a validation timeout value to each wake-up source
 * @param[in]     sources - The wake-up source to verify
 * @return        NULL
 * @retval        NULL
 */
STATIC FUNC(void, ECUM_CODE) EcuM_StartValidationTimer
(
	CONST(EcuM_WakeupSourceType, AUTOMATIC) sources
)
{
	VAR(uint8, AUTOMATIC) count ;
	for(count = 0U; count < ECUM_WAKEUP_SOURCE_NUM; count++)
	{
		if(ECUM_WAKEUP_SOURCE_NONE != ((sources >> count) & (EcuM_WakeupSourceType)1U ))
		{
			VAR(uint16, AUTOMATIC) validationTimeout = EcuM_ConfigPtr->EcuM_CommonConfigurationPtr->\
					EcuM_WakeupSourcePtr[count].EcuM_ValidationTimeout;

			EcuM_InternalState.EcuM_WakeupExpiredTimer[count] = validationTimeout;
		}
		else
		{
			/* Do nothing */
		}

	}
}

/**
 * @brief         Wake-up source validation ,update the wake-up source validation timeout,
 * 				  get the timeout validation wake-up event
 * @param[in]     sources - The wake-up source being verified
 * @return        NULL
 * @retval        NULL
 */
STATIC FUNC(void, ECUM_CODE) EcuM_TimeoutValidation
(
	CONST(EcuM_WakeupSourceType, AUTOMATIC) sources
)
{
	VAR(uint8, AUTOMATIC) count;
	VAR(EcuM_WakeupSourceType, AUTOMATIC) expiredWkSources = ECUM_WAKEUP_SOURCE_NONE;

	/* Calculates the current verification time of the wake-up source */
	for(count = 0U; count < ECUM_WAKEUP_SOURCE_NUM; count++)
	{
		if(ECUM_WAKEUP_SOURCE_NONE != ((sources >> count) & (EcuM_WakeupSourceType)1U))
		{
			/**
			 * @req [SWS_EcuM_04004] The ECU Manager Module shall either provide a single wakeup
			 *      validation timeout timer or one timer per wakeup source.
			 */
			if(EcuM_InternalState.EcuM_WakeupExpiredTimer[count] > ECUM_MAIN_FUNCTION_PERIOD)
			{
				EcuM_InternalState.EcuM_WakeupExpiredTimer[count] -= ECUM_MAIN_FUNCTION_PERIOD;
			}
			else
			{
				/* Wake up verification timed out */
				EcuM_InternalState.EcuM_WakeupExpiredTimer[count] = (uint16)0;
				expiredWkSources |= (uint32)((EcuM_WakeupSourceType)1U << count);
			}
		}
		else
		{
			/* Do nothing */
		}
	}

	/**
	 * @req [SWS_EcuM_04081] When the validation timeout expires for a pending wakeup event, the
	 *                       EcuM_MainFunction sets (OR-operation) set the bit in the internal
	 *                       expired wakeup events variable.
	 */
	if(ECUM_WAKEUP_SOURCE_NONE != expiredWkSources)
	{
		EcuM_InternalState.EcuM_ExpiredWakeupEvents |= expiredWkSources;
		EcuM_InternalState.EcuM_PendingWakeupEvents &= ~expiredWkSources;
		EcuM_InternalState.EcuM_StartWakeupEvents &= ~expiredWkSources;
		/**
		 * @req [SWS_EcuM_04082] When the validation timeout expires for a pending wakeup event, the
		 *      EcuM_MainFunction shall invoke BswM_EcuM_CurrentWakeup with an EcuM_WakeupSourceType
		 *      bitmask parameter with the bit corresponding to the wakeup event set and state value
		 *      parameter set to ECUM_WKSTATUS_EXPIRED.
		 */
		BswM_EcuM_CurrentWakeup(expiredWkSources, ECUM_WKSTATUS_EXPIRED);
		EcuM_StopWakeupSources(expiredWkSources);
	}
	else
	{
		/* Do nothing */
	}

}

#if(STD_ON == ECUM_ALARM_CLOCK_PRESENT)
/**
 * @brief    Cancel all alarm clocks
 * @return   NULL
 * @retval   NULL
 */
STATIC FUNC(void, ECUM_CODE) EcuM_CanCelAllAlarm(void)
{
	VAR(uint8, AUTOMATIC) count;
	EcuM_InternalState.EcuM_AlarmTimer = ECUM_INVALID_ALARM;
	for(count = 0U; count < ECUM_ALARM_NUM; count++)
	{
		EcuM_InternalState.EcuM_UserAlarmTimer[count] = ECUM_INVALID_ALARM;
	}
}
#endif /* STD_ON == ECUM_ALARM_CLOCK_PRESENT */

/**
 * @brief    Initializes the intenal member parameters of the EcuM module
 * @return   NULL
 * @retval   NULL
 */
STATIC FUNC(void, ECUM_CODE) EcuM_InternalParametersInit(void)
{
	VAR(uint8, AUTOMATIC) count ;

#if(STD_ON == ECUM_ALARM_CLOCK_PRESENT)
	/**
	 * @req [SWS_EcuM_04010] Cancel all alarms
	 */
	EcuM_CanCelAllAlarm();
#endif /* STD_ON == ECUM_ALARM_CLOCK_PRESENT */

	/* Clear all wake-up events */
	EcuM_ClearWakeupEvent((EcuM_WakeupSourceType)0xffffffffU);
#if(STD_ON == ECUM_ALARM_CLOCK_PRESENT)
	/* Clear the run time */
	EcuM_InternalState.EcuM_RunTimer = 0U;
#endif /* STD_ON == ECUM_ALARM_CLOCK_PRESENT */

	/* @todo SWS_EcuM_02157 Power-off storage has not been realized yet */
	EcuM_InternalState.EcuM_LastShutdownMode = (EcuM_ShutdownModeType)0;
	EcuM_InternalState.EcuM_LastShutdownTarget = ECUM_SHUTDOWN_TARGET_OFF;

	EcuM_InternalState.EcuM_ShutdownCase = ECUM_CAUSE_UNKNOWN;
	EcuM_InternalState.EcuM_ShutdownMode = EcuM_ConfigPtr->EcuM_CommonConfigurationPtr->\
			EcuM_DefaultShutdownTargetPtr->EcuM_DefaultShutdownMode;
	EcuM_InternalState.EcuM_ShutdownTarget = EcuM_ConfigPtr->EcuM_CommonConfigurationPtr->\
			EcuM_DefaultShutdownTargetPtr->EcuM_DefaultState;

	for(count = 0U; count < ECUM_FLEX_USER_NUM; count++)
	{
		EcuM_InternalState.EcuM_User[count].EcuM_AppRunState = (boolean)FALSE;
		EcuM_InternalState.EcuM_User[count].EcuM_PostRunState = (boolean)FALSE;
	}

	for(count = 0U; count < ECUM_WAKEUP_SOURCE_NUM; count++)
	{
		EcuM_InternalState.EcuM_WakeupExpiredTimer[count] = 0xffffU;
	}

}

/*====================================================================================================*
 *                                          GLOBAL FUNCTIONS
 *====================================================================================================*/

#if(STD_ON == ECUM_VERSION_INFO_API)
/**
 * @sid           0x00
 * @brief         Returns the version information of this module.
 * @param[out]    pVersioninfo - Pointer to where to store the version information of this module.
 * @return        NULL
 * @retval        NULL
 */
FUNC(void, ECUM_CODE) EcuM_GetVersionInfo
(
	P2VAR(Std_VersionInfoType, AUTOMATIC, ECUM_APPL_DATA) pVersioninfo
)
{
	if(NULL_PTR == pVersioninfo)
	{
#if (STD_ON == ECUM_DEV_ERROR_DETECT)
		(void)Det_ReportError
		(
			ECUM_MODULE_ID,
			ECUM_INSTANCE_ID,
			ECUM_SID_GETVERSIONINFO,
			ECUM_E_NULL_POINTER
		);
#endif /* (STD_ON == ECUM_DEV_ERROR_DETECT) */
	}
	else
	{
		pVersioninfo->vendorID = ECUM_VENDOR_ID;
		pVersioninfo->moduleID = ECUM_MODULE_ID;
		pVersioninfo->sw_major_version = ECUM_SW_MAJOR_VERSION;
		pVersioninfo->sw_minor_version = ECUM_SW_MINOR_VERSION;
		pVersioninfo->sw_patch_version = ECUM_SW_PATCH_VERSION;
	}
}
#endif /* STD_ON == ECUM_VERSION_INFO_API */

/**
 * @sid          0x1F
 * @brief        Instructs the ECU State Manager module to perform a power off or a reset
 *               depending on the selected shutdown target.
 * @param[in]    caller: Module ID of the calling module. Only special modules are
 *                       allowed to call this function.
 * @return       Std_ReturnType:Service result.
 * @retval       E_OK: This cannot occur because if the request was accepted ,this call will not return.
 *               E_NOT_OK: The shutdown request was not accepted.
 */
FUNC(Std_ReturnType, ECUM_CODE) EcuM_GoDown
(
	CONST(EcuM_UserType, AUTOMATIC) caller
)
{
	VAR(Std_ReturnType, AUTOMATIC) ret = (Std_ReturnType) E_OK;

	if(NULL_PTR == EcuM_ConfigPtr)
	{
#if (STD_ON == ECUM_DEV_ERROR_DETECT)
		(void)Det_ReportError
		(
			ECUM_MODULE_ID,
			ECUM_INSTANCE_ID,
			ECUM_SID_GODOWN,
			ECUM_E_UNINIT
		);
#endif /* (STD_ON == ECUM_DEV_ERROR_DETECT) */
		ret = (Std_ReturnType) E_NOT_OK;
	}
	else if(caller >= ECUM_FLEX_USER_NUM)
	{
#if (STD_ON == ECUM_DEV_ERROR_DETECT)
		(void)Det_ReportError
		(
			ECUM_MODULE_ID,
			ECUM_INSTANCE_ID,
			ECUM_SID_GODOWN,
			ECUM_E_INVALID_PAR
		);
#endif /* (STD_ON == ECUM_DEV_ERROR_DETECT) */
		ret = (Std_ReturnType) E_NOT_OK;
	}
	else
	{
		if((Std_ReturnType)E_NOT_OK == EcuM_CheckUser(ECUN_GO_DOWN_USER_CHECK,caller))
		{
#if (STD_ON == ECUM_DEV_ERROR_DETECT)
			(void)Det_ReportError
			(
				ECUM_MODULE_ID,
				ECUM_INSTANCE_ID,
				ECUM_SID_GODOWN,
				ECUM_E_INVALID_PAR
			);
#endif /* (STD_ON == ECUM_DEV_ERROR_DETECT) */
			ret = (Std_ReturnType) E_NOT_OK;
		}
		else
		{
			if((EcuM_InternalState.EcuM_ShutdownTarget == ECUM_SHUTDOWN_TARGET_OFF) || \
					               (EcuM_InternalState.EcuM_ShutdownTarget == ECUM_SHUTDOWN_TARGET_RESET))
			{
				EcuM_OffPreOS();
			}
			else
			{
				ret = (Std_ReturnType) E_NOT_OK;
			}
		}
	}

	return ret;
}

/**
 * @sid          0x20
 * @brief        Instructs the ECU State Manager module to go into a sleep mode where the
 *               microcontroller is halted, depending on the selected shutdown target.
 * @return       Std_ReturnType:Service result.
 * @retval       E_OK: If the call successfully returns, the ECU has left the
 *                     sleep again.
 *               E_NOT_OK: The request was not accepted, e.g. due to a
 *                         wrong shutdown target.
 */
FUNC(Std_ReturnType, ECUM_CODE) EcuM_GoHalt
(
	void
)
{
	VAR(Std_ReturnType, AUTOMATIC) ret = (Std_ReturnType) E_OK;
	if(NULL_PTR == EcuM_ConfigPtr)
	{
#if (STD_ON == ECUM_DEV_ERROR_DETECT)
		(void)Det_ReportError
		(
			ECUM_MODULE_ID,
			ECUM_INSTANCE_ID,
			ECUM_SID_GOHALT,
			ECUM_E_UNINIT
		);
#endif /* (STD_ON == ECUM_DEV_ERROR_DETECT) */
		ret = (Std_ReturnType) E_NOT_OK;
	}
	else
	{
		if((ECUM_SHUTDOWN_TARGET_SLEEP == EcuM_InternalState.EcuM_ShutdownTarget) && \
				    ( (boolean)TRUE == ECUM_GET_SLEEP_MODE(EcuM_InternalState.EcuM_ShutdownMode)))
		{
			EcuM_GoSleep(EcuM_InternalState.EcuM_ShutdownMode);
			EcuM_Halt();
			EcuM_WakeupRestart();
		}
		else
		{
			ret = (Std_ReturnType) E_NOT_OK;
		}
	}


	return ret;
}

/**
 * @sid          0x21
 * @brief        Instructs the ECU State Manager module to go into a polling sleep mode
 *               depending on the selected shutdown target.
 * @return       Std_ReturnType:Service result.
 * @retval       E_OK: If the call successfully returns, the ECU has left the
 *                     sleep again.
 * @retval       E_NOT_OK: The request was not accepted, e.g. due to a
 *                         wrong shutdown target.
 */
FUNC(Std_ReturnType, ECUM_CODE) EcuM_GoPoll
(
	void
)
{
	VAR(Std_ReturnType, AUTOMATIC) ret = (Std_ReturnType) E_OK;

	if(NULL_PTR == EcuM_ConfigPtr)
	{
#if (STD_ON == ECUM_DEV_ERROR_DETECT)
		(void)Det_ReportError
		(
			ECUM_MODULE_ID,
			ECUM_INSTANCE_ID,
			ECUM_SID_GOPOLL,
			ECUM_E_UNINIT
		);
#endif /* (STD_ON == ECUM_DEV_ERROR_DETECT) */
		ret = (Std_ReturnType) E_NOT_OK;
	}
	else
	{
		if((ECUM_SHUTDOWN_TARGET_SLEEP == EcuM_InternalState.EcuM_ShutdownTarget) &&\
				((boolean)FALSE == ECUM_GET_SLEEP_MODE(EcuM_InternalState.EcuM_ShutdownMode)))
		{
			EcuM_GoSleep(EcuM_InternalState.EcuM_ShutdownMode);
			EcuM_Polling();
			EcuM_WakeupRestart();
		}
		else
		{
			ret = (Std_ReturnType) E_NOT_OK;
		}
	}
	return ret;
}

/**
 * @sid           0x01
 * @brief         Initializes the ECU state manager and carries out the startup procedure. The
 *                function will never return (it calls StartOS)
 * @return        NULL
 * @retval        NULL
 */
FUNC(void, ECUM_CODE) EcuM_Init
(
	void
)
{
	/* StartPreOS Sequence */
	if((Std_ReturnType)E_OK == EcuM_StartPreOS())
	{
		/* Start Os */
		//StartOS((AppModeType)EcuM_ConfigPtr->EcuM_CommonConfigurationPtr->EcuM_DefaultAppMode);
	}
	else
	{
#if (STD_ON == ECUM_DEV_ERROR_DETECT)
		(void)Det_ReportError
		(
			ECUM_MODULE_ID,
			ECUM_INSTANCE_ID,
			ECUM_SID_INIT,
			ECUM_E_INIT_FAILED
		);
#endif /* (STD_ON == ECUM_DEV_ERROR_DETECT) */
	}
}

/**
 * @sid           0x1A
 * @brief         This function implements the STARTUP II state(StartPostOS Sequence).
 * @details       This function must be called from a task which is started directly as a
 *                consequence of StartOS. I.e. either it must be called from an autostart
 *                task or it must be called from a task which is explicitely started.
 * @return        NULL
 * @retval        NULL
 */
FUNC(void, ECUM_CODE) EcuM_StartupTwo
(
	void
)
{
	if(NULL_PTR == EcuM_ConfigPtr)
	{
#if (STD_ON == ECUM_DEV_ERROR_DETECT)
		(void)Det_ReportError
		(
			ECUM_MODULE_ID,
			ECUM_INSTANCE_ID,
			ECUM_SID_STARTUP_TWO,
			ECUM_E_UNINIT
		);
#endif /* (STD_ON == ECUM_DEV_ERROR_DETECT) */
	}
	else
	{
		/* Initialize the semaphores for critical sections used by BSW modules */
		//SchM_Init(&SchM_Config);
		/* Initialize the BswM module */
		BswM_Init(&BswM_Config);
		/* Notify the BswM module of the current status of the EcuM module. */
		BswM_EcuM_CurrentState(ECUM_STATE_RUN);
	}
}

/**
 * @sid            0x02
 * @brief          Typically called from the shutdown hook,the function takes over execution control
 * 				   and will carry out GO OFF II activities.
 * @return         NULL
 * @retval         NULL
 */
FUNC(void, ECUM_CODE) EcuM_Shutdown
(
	void
)
{
	if(NULL_PTR == EcuM_ConfigPtr)
	{
#if (STD_ON == ECUM_DEV_ERROR_DETECT)
		(void)Det_ReportError
		(
			ECUM_MODULE_ID,
			ECUM_INSTANCE_ID,
			ECUM_SID_SHUTDOWN,
			ECUM_E_UNINIT
		);
#endif /* (STD_ON == ECUM_DEV_ERROR_DETECT) */
	}
	else
	{
		EcuM_OffPostOS();
	}

}

/**
 * @sid           0x2B
 * @brief         Function called by BswM to notify about State Switch.
 * @param[in]     state: State indicated by BswM.
 * @return        NULL
 * @retval        NULL
 */
FUNC(void, ECUM_CODE) EcuM_SetState
(
	CONST(EcuM_StateType, AUTOMATIC) state
)
{

	if(NULL_PTR == EcuM_ConfigPtr)
	{
#if (STD_ON == ECUM_DEV_ERROR_DETECT)
		(void)Det_ReportError
		(
			ECUM_MODULE_ID,
			ECUM_INSTANCE_ID,
			ECUM_SID_SETSTATE,
			ECUM_E_UNINIT
		);
#endif /* (STD_ON == ECUM_DEV_ERROR_DETECT) */
	}
	else
	{
		/* @todo When the BswM sets a state of the EcuM by EcuM_SetState(), the EcuM shall
		 * indicate the corresponding mode to the RTE. */
		switch(state)
		{
			case ECUM_STATE_STARTUP:
                /*Rte_StatusType Rte_Switch_currentMode_currentMode(Rte_ModeType_EcuM_Mode mode);*/
				break;
			case ECUM_STATE_APP_RUN:
				/*Rte_StatusType Rte_Switch_currentMode_currentMode(Rte_ModeType_EcuM_Mode mode);*/
				break;
			case ECUM_STATE_APP_POST_RUN:
				/*Rte_StatusType Rte_Switch_currentMode_currentMode(Rte_ModeType_EcuM_Mode mode);*/
				break;
			case ECUM_STATE_SHUTDOWN:
				/*Rte_StatusType Rte_Switch_currentMode_currentMode(Rte_ModeType_EcuM_Mode mode);*/
				break;
			case ECUM_STATE_SLEEP:
				/*Rte_StatusType Rte_Switch_currentMode_currentMode(Rte_ModeType_EcuM_Mode mode);*/
				break;
			default :
				/**
				 * @req [SWS_EcuM_04123] If the State parameter is not a valid value, the EcuM_SetState
				 *      function shall not change the State and if Development Error Reporting is
				 *      turned on, the EcuM_SetState function shall additionally send an
				 *      ECUM_E_STATE_PAR_OUT_OF_RANGE error message to the DET module.
				 */
#if (STD_ON == ECUM_DEV_ERROR_DETECT)
				(void)Det_ReportError
				(
					ECUM_MODULE_ID,
					ECUM_INSTANCE_ID,
					ECUM_SID_SETSTATE,
					ECUM_E_STATE_PAR_OUT_OF_RANGE
				);
#endif /* (STD_ON == ECUM_DEV_ERROR_DETECT) */
				break;
		}
	}
}

/**
 * @sid            0x03
 * @brief          Places a request for the RUN state.
 * @param          user: ID of the entity requesting the RUN state.
 * @return         Std_ReturnType:Service result.
 * @retval         E_OK: The request was accepted by EcuM.
 *                 E_NOT_OK: The request was not accepted by EcuM.
 */
FUNC(Std_ReturnType, ECUM_CODE) EcuM_RequestRUN
(
	CONST(EcuM_UserType, AUTOMATIC) user
)
{
	VAR(Std_ReturnType, AUTOMATIC) ret = (Std_ReturnType) E_OK;

	if(NULL_PTR == EcuM_ConfigPtr)
	{
#if (STD_ON == ECUM_DEV_ERROR_DETECT)
		(void)Det_ReportError
		(
			ECUM_MODULE_ID,
			ECUM_INSTANCE_ID,
			ECUM_SID_REQUESTRUN,
			ECUM_E_UNINIT
		);
#endif /* (STD_ON == ECUM_DEV_ERROR_DETECT) */
		ret = (Std_ReturnType) E_NOT_OK;
	}
	else
	{
		/**
		* @req [SWS_EcuM_04126] An implementation must track requests for each user
		*      known on the ECU. Run requests are specific to the user.
		*/
		if((boolean)TRUE != EcuM_InternalState.EcuM_User[user].EcuM_AppRunState)
		{
			EcuM_InternalState.EcuM_User[user].EcuM_AppRunState = (boolean)TRUE;
		}
		else
		{
			/**
			 * @req [SWS_EcuM_04125] Requests of EcuM_RequestRUN cannot be nested, i.e. one
			 *      user can only place one request but not more. Additional or duplicate user
			 *      requests by the same user shall be reported to DET. Of course the DET will
			 *      only be notified under development conditions.
			 */
#if (STD_ON == ECUM_DEV_ERROR_DETECT)
			(void)Det_ReportError
			(
				ECUM_MODULE_ID,
				ECUM_INSTANCE_ID,
				ECUM_SID_REQUESTRUN,
				ECUM_E_MULTIPLE_RUN_REQUESTS
			);
#endif /* (STD_ON == ECUM_DEV_ERROR_DETECT) */
			ret = (Std_ReturnType) E_NOT_OK;
		}
	}

	return ret;
}

/**
 * @sid            0x04
 * @brief          Releases a RUN request previously done with a call to EcuM_RequestRUN.
 * @param[in]      user: ID of the entity releasing the RUN state.
 * @return         E_OK: The release request was accepted by EcuM.
 *                 E_NOT_OK: The release request was not accepted by EcuM.
 */
FUNC(Std_ReturnType, ECUM_CODE) EcuM_ReleaseRUN
(
	CONST(EcuM_UserType, AUTOMATIC) user
)
{
	VAR(Std_ReturnType, AUTOMATIC) ret = (Std_ReturnType) E_OK;

	if(NULL_PTR == EcuM_ConfigPtr)
	{
#if (STD_ON == ECUM_DEV_ERROR_DETECT)
		(void)Det_ReportError
		(
			ECUM_MODULE_ID,
			ECUM_INSTANCE_ID,
			ECUM_SID_RELEASERUN,
			ECUM_E_UNINIT
		);
#endif /* (STD_ON == ECUM_DEV_ERROR_DETECT) */
		ret = (Std_ReturnType) E_NOT_OK;
	}
	else
	{
		if((boolean)FALSE != EcuM_InternalState.EcuM_User[user].EcuM_AppRunState)
		{
			EcuM_InternalState.EcuM_User[user].EcuM_AppRunState = (boolean)FALSE;
		}
		else
		{
	#if (STD_ON == ECUM_DEV_ERROR_DETECT)
			(void)Det_ReportError
			(
				ECUM_MODULE_ID,
				ECUM_INSTANCE_ID,
				ECUM_SID_RELEASERUN,
				ECUM_E_MISMATCHED_RUN_RELEASE
			);
	#endif /* (STD_ON == ECUM_DEV_ERROR_DETECT) */
			ret = (Std_ReturnType) E_NOT_OK;
		}
	}
	return ret;
}

/**
 * @sid            0x0A
 * @brief          Places a request for the POST RUN state
 * @param[in]      user: ID of the entity requesting the POST RUN state.
 * @return         E_OK: The request was accepted by EcuM.
 *                 E_NOT_OK: The request was not accepted by EcuM.
 */
FUNC(Std_ReturnType, ECUM_CODE) EcuM_RequestPOST_RUN
(
	CONST(EcuM_UserType, AUTOMATIC) user
)
{
	VAR(Std_ReturnType, AUTOMATIC) ret = (Std_ReturnType) E_OK;

	if(NULL_PTR == EcuM_ConfigPtr)
	{
#if (STD_ON == ECUM_DEV_ERROR_DETECT)
		(void)Det_ReportError
		(
			ECUM_MODULE_ID,
			ECUM_INSTANCE_ID,
			ECUM_SID_REQUESTPOST_RUN,
			ECUM_E_UNINIT
		);
#endif /* (STD_ON == ECUM_DEV_ERROR_DETECT) */
		ret = (Std_ReturnType) E_NOT_OK;
	}
	else
	{
		if((boolean)TRUE != EcuM_InternalState.EcuM_User[user].EcuM_PostRunState)
		{
			EcuM_InternalState.EcuM_User[user].EcuM_PostRunState = (boolean)TRUE;
		}
		else
		{
	#if (STD_ON == ECUM_DEV_ERROR_DETECT)
			(void)Det_ReportError
			(
				ECUM_MODULE_ID,
				ECUM_INSTANCE_ID,
				ECUM_SID_REQUESTPOST_RUN,
				ECUM_E_MULTIPLE_RUN_REQUESTS
			);
	#endif /* (STD_ON == ECUM_DEV_ERROR_DETECT) */
			ret = (Std_ReturnType) E_NOT_OK;
		}
	}
	return ret;
}

/**
 * @sid            0x0B
 * @brief          Releases a POST RUN request previously done with a call to EcuM_RequestPOST_RUN.
 * @param[in]      user: ID of the entity releasing the POST RUN state.
 * @return         E_OK: The release request was accepted by EcuM.
 *                 E_NOT_OK: The release request was not accepted by EcuM.
 */
FUNC(Std_ReturnType, ECUM_CODE) EcuM_ReleasePOST_RUN
(
	CONST(EcuM_UserType, AUTOMATIC) user
)
{
	VAR(Std_ReturnType, AUTOMATIC) ret = (Std_ReturnType) E_OK;

	if(NULL_PTR == EcuM_ConfigPtr)
	{
#if (STD_ON == ECUM_DEV_ERROR_DETECT)
		(void)Det_ReportError
		(
			ECUM_MODULE_ID,
			ECUM_INSTANCE_ID,
			ECUM_SID_RELEASEPOST_RUN,
			ECUM_E_UNINIT
		);
#endif /* (STD_ON == ECUM_DEV_ERROR_DETECT) */
		ret = (Std_ReturnType) E_NOT_OK;
	}
	else
	{
		if((boolean)FALSE != EcuM_InternalState.EcuM_User[user].EcuM_PostRunState)
		{
			EcuM_InternalState.EcuM_User[user].EcuM_PostRunState = (boolean)FALSE;
		}
		else
		{
	#if (STD_ON == ECUM_DEV_ERROR_DETECT)
			(void)Det_ReportError
			(
				ECUM_MODULE_ID,
				ECUM_INSTANCE_ID,
				ECUM_SID_RELEASEPOST_RUN,
				ECUM_E_MISMATCHED_RUN_RELEASE
			);
	#endif /* (STD_ON == ECUM_DEV_ERROR_DETECT) */
			ret = (Std_ReturnType) E_NOT_OK;
		}
	}
	return ret;
}

/**
 * @sid           0x06
 * @brief         EcuM_SelectShutdownTarget selects the shutdown target.
 * @param[in]     shutdownTarget: The selected shutdown target.
 *                shutdownMode:The identfier of a sleep mode (if target is ECUM_STATE_SLEEP)
 *                             or a reset mechanism (if target is ECUM_STATE_RESET) asdefined by configuration.
 * @return        E_OK: The new shutdown target was set
 *                E_NOT_OK: The new shutdown target was not set
 */
FUNC(Std_ReturnType, ECUM_CODE) EcuM_SelectShutdownTarget
(
	CONST(EcuM_ShutdownTargetType, AUTOMATIC) shutdownTarget,
	CONST(EcuM_ShutdownModeType,   AUTOMATIC) shutdownMode
)
{
	VAR(Std_ReturnType, AUTOMATIC) ret = (Std_ReturnType) E_OK;

	if(NULL_PTR == EcuM_ConfigPtr)
	{
#if (STD_ON == ECUM_DEV_ERROR_DETECT)
		(void)Det_ReportError
		(
			ECUM_MODULE_ID,
			ECUM_INSTANCE_ID,
			ECUM_SID_SELECTSHUTDOWNTARGET,
			ECUM_E_UNINIT
		);
#endif /* (STD_ON == ECUM_DEV_ERROR_DETECT) */
		ret = (Std_ReturnType) E_NOT_OK;
	}
	else
	{
		/**
		 * @req [SWS_EcuM_00624] The EcuM_SelectShutdownTarget function shall set the shutdown target
		 *      to the value of the shutdownTarget parameter.
		 * @req [SWS_EcuM_02185] The parameter mode of the function EcuM_SelectShutdownTarget shall
		 *      be the identifier of a sleep or reset mode. The mode parameter shall only be used if
		 *      the target parameter equals ECUM_STATE_SLEEP or ECUM_STATE_RESET. In all other cases,
		 *      it shall be ignored. Only sleep or reset modes that are defined at configuration time
		 *      and are stored in the EcuMCommonConfiguration container (see ECUC_EcuM_00181) are
		 *      allowed as parameters.
		 */
		if((Std_ReturnType) E_OK == EcuM_CheckShutdownTarget(shutdownTarget,shutdownMode))
		{
			EcuM_InternalState.EcuM_ShutdownTarget = shutdownTarget;
			if(ECUM_SHUTDOWN_TARGET_SLEEP == shutdownTarget)
			{
				EcuM_InternalState.EcuM_ShutdownMode = (shutdownMode & (EcuM_ShutdownModeType)0x00ff);
			}
			else if(ECUM_SHUTDOWN_TARGET_RESET == shutdownTarget)
			{
				EcuM_InternalState.EcuM_ShutdownMode = (shutdownMode & (EcuM_ShutdownModeType)0xff00);
			}
			else
			{
				/* Do nothing */
			}
		}
		else
		{
#if (STD_ON == ECUM_DEV_ERROR_DETECT)
			(void)Det_ReportError
			(
				ECUM_MODULE_ID,
				ECUM_INSTANCE_ID,
				ECUM_SID_SELECTSHUTDOWNTARGET,
				ECUM_E_INVALID_PAR
			);
#endif /* (STD_ON == ECUM_DEV_ERROR_DETECT) */
			ret = (Std_ReturnType) E_NOT_OK;
		}
	}
	return ret;
}

/**
 * @sid           0x09
 * @brief         Returns the currently selected shutdown target as set
 *                by EcuM_SelectShutdownTarget.
 * @param[out]    pShutdownTarget: One of these values is returned
 *                - ECUM_STATE_SLEEP
 *                - ECUM_STATE_SLEEP
 *                - ECUM_STATE_OFF
 * @param[out]    pSleepModeCfg:
 *                - If the out parameter "shutdownTarget" is ECUM_STATE_SLEEP,
 *                sleepMode tells which of the configured sleep modes was actually chosen.
 *                - If "shutdownTarget" is ECUM_STATE_RESET,
 *                sleepMode tells which of the configured reset modes was actually chosen.
 * @return        Std_ReturnType
 * @retval        E_OK: The service has successed
 *                E_NOT_OK: The service has failed
 */
FUNC(Std_ReturnType, ECUM_CODE) EcuM_GetShutdownTarget
(
	P2VAR(EcuM_ShutdownTargetType, AUTOMATIC, ECUM_APPL_DATA) pShutdownTarget,
	P2VAR(EcuM_ShutdownModeType,  AUTOMATIC, ECUM_APPL_DATA) pSleepMode
)
{
	VAR(Std_ReturnType, AUTOMATIC) ret = (Std_ReturnType) E_OK;

	if(NULL_PTR == EcuM_ConfigPtr)
	{
#if (STD_ON == ECUM_DEV_ERROR_DETECT)
		(void)Det_ReportError
		(
			ECUM_MODULE_ID,
			ECUM_INSTANCE_ID,
			ECUM_SID_GETSHUTDOWNTARGET,
			ECUM_E_UNINIT
		);
#endif /* (STD_ON == ECUM_DEV_ERROR_DETECT) */
		ret = (Std_ReturnType) E_NOT_OK;
	}
	else if(NULL_PTR == pShutdownTarget)
	{
#if (STD_ON == ECUM_DEV_ERROR_DETECT)
		(void)Det_ReportError
		(
			ECUM_MODULE_ID,
			ECUM_INSTANCE_ID,
			ECUM_SID_GETSHUTDOWNTARGET,
			ECUM_E_PARAM_POINTER
		);
#endif /* (STD_ON == ECUM_DEV_ERROR_DETECT) */
		ret = (Std_ReturnType) E_NOT_OK;
	}
	else
	{
		(*pShutdownTarget) = EcuM_InternalState.EcuM_ShutdownTarget;
		/**
		 * @req [SWS_EcuM_02788] If the pointer to the shutdownMode parameter is NULL, If Default Error
		 *      Detection is activated, EcuM_GetShutdownTarget shall send the ECUM_E_PARAM_POINTER
		 *      development error to the DET module.
		 */
		if(NULL_PTR == pSleepMode)
		{
#if (STD_ON == ECUM_DEV_ERROR_DETECT)
			(void)Det_ReportError
			(
				ECUM_MODULE_ID,
				ECUM_INSTANCE_ID,
				ECUM_SID_GETSHUTDOWNTARGET,
				ECUM_E_PARAM_POINTER
			);
#endif /* (STD_ON == ECUM_DEV_ERROR_DETECT) */
			ret = (Std_ReturnType) E_NOT_OK;
		}
		else if(ECUM_SHUTDOWN_TARGET_SLEEP == EcuM_InternalState.EcuM_ShutdownTarget)
		{
			(*pSleepMode) = EcuM_InternalState.EcuM_ShutdownMode & (EcuM_ShutdownModeType)0x00ff;
		}
		else if(ECUM_SHUTDOWN_TARGET_RESET == EcuM_InternalState.EcuM_ShutdownTarget)
		{
			(*pSleepMode) = EcuM_InternalState.EcuM_ShutdownMode & (EcuM_ShutdownModeType)0xff00;
		}
		else
		{
			/* Do nothing */
		}
	}
	return ret;
}

/**
 * @sid           0x08
 * @brief         Returns the shutdown target of the previous shutdown process.
 * @param[out]    pShutdownTarget: One of these values is returned
 *                - ECUM_STATE_SLEEP
 *                - ECUM_STATE_RESET
 *                - ECUM_STATE_OFF
 * @param[out]    pSleepModeCfg: If the out parameter "shutdownTarget" is ECUM_STATE_SLEEP,
 *                sleepMode tells which of the configured sleep modes was
 *                actually chosen. If "shutdownTarget" is ECUM_STATE_RESET,
 *                sleepMode tells which of the configured reset modes was actually chosen.
 * @return        Std_ReturnType:Service result.
 * @retval        E_OK: The service has successed.
 *                E_NOT_OK: The service has failed.
 */
FUNC(Std_ReturnType, ECUM_CODE) EcuM_GetLastShutdownTarget
(
	P2VAR(EcuM_ShutdownTargetType, AUTOMATIC, ECUM_APPL_DATA) pShutdownTarget,
	P2VAR(EcuM_ShutdownModeType,  AUTOMATIC, ECUM_APPL_DATA) pSleepMode
)
{
	VAR(Std_ReturnType, AUTOMATIC) ret = (Std_ReturnType) E_NOT_OK;

	if(NULL_PTR == EcuM_ConfigPtr)
	{
#if (STD_ON == ECUM_DEV_ERROR_DETECT)
		(void)Det_ReportError
		(
			ECUM_MODULE_ID,
			ECUM_INSTANCE_ID,
			ECUM_SID_GETLASTSHUTDOWNTARGET,
			ECUM_E_UNINIT
		);
#endif /* (STD_ON == ECUM_DEV_ERROR_DETECT) */
		ret = (Std_ReturnType) E_NOT_OK;
	}
	else if(NULL_PTR == pShutdownTarget)
	{
#if (STD_ON == ECUM_DEV_ERROR_DETECT)
		(void)Det_ReportError
		(
			ECUM_MODULE_ID,
			ECUM_INSTANCE_ID,
			ECUM_SID_GETLASTSHUTDOWNTARGET,
			ECUM_E_PARAM_POINTER
		);
#endif /* (STD_ON == ECUM_DEV_ERROR_DETECT) */
		ret = (Std_ReturnType) E_NOT_OK;
	}
	else
	{
		(*pShutdownTarget) = EcuM_InternalState.EcuM_LastShutdownTarget;

		if(NULL_PTR == pSleepMode)
		{
#if (STD_ON == ECUM_DEV_ERROR_DETECT)
			(void)Det_ReportError
			(
				ECUM_MODULE_ID,
				ECUM_INSTANCE_ID,
				ECUM_SID_GETLASTSHUTDOWNTARGET,
				ECUM_E_PARAM_POINTER
			);
#endif /* (STD_ON == ECUM_DEV_ERROR_DETECT) */
		}
		else if(ECUM_SHUTDOWN_TARGET_SLEEP == EcuM_InternalState.EcuM_LastShutdownTarget)
		{
			(*pSleepMode) = EcuM_InternalState.EcuM_LastShutdownMode & (EcuM_ShutdownModeType)0x00ff;
		}
		else if(ECUM_SHUTDOWN_TARGET_RESET == EcuM_InternalState.EcuM_LastShutdownTarget)
		{
			(*pSleepMode) = EcuM_InternalState.EcuM_LastShutdownMode & (EcuM_ShutdownModeType)0xff00;
		}
		else
		{
			/* Do nothing */
		}
	}
	return ret;
}

/**
 * @sid           0x1B
 * @brief         EcuM_SelectShutdownCause selects the shutdown cause.
 * @param[in]     target: The selected shutdown target.
 * @return        E_OK: The new shutdown cause was set
 *                E_NOT_OK: The new shutdown cause was not set
 */
FUNC(Std_ReturnType, ECUM_CODE) EcuM_SelectShutdownCause
(
	CONST(EcuM_ShutdownCauseType, AUTOMATIC) target
)
{
	VAR(Std_ReturnType, AUTOMATIC) ret = (Std_ReturnType) E_OK;

	if(NULL_PTR == EcuM_ConfigPtr)
	{
#if (STD_ON == ECUM_DEV_ERROR_DETECT)
		(void)Det_ReportError
		(
			ECUM_MODULE_ID,
			ECUM_INSTANCE_ID,
			ECUM_SID_SELECTSHUTDOWNCAUSE,
			ECUM_E_UNINIT
		);
#endif /* (STD_ON == ECUM_DEV_ERROR_DETECT) */
		ret = (Std_ReturnType) E_NOT_OK;
	}
	else
	{
		if(target >= ECUM_SHUTDOWN_CAUSE_NUM)
		{
#if (STD_ON == ECUM_DEV_ERROR_DETECT)
			(void)Det_ReportError
			(
				ECUM_MODULE_ID,
				ECUM_INSTANCE_ID,
				ECUM_SID_SELECTSHUTDOWNCAUSE,
				ECUM_E_INVALID_PAR
			);
#endif /* (STD_ON == ECUM_DEV_ERROR_DETECT) */
			ret = (Std_ReturnType) E_NOT_OK;
		}
		else
		{
			EcuM_InternalState.EcuM_ShutdownCase = target;
		}
	}
	return ret;
}

/**
 * @sid           0x1C
 * @brief         EcuM_GetShutdownCause returns the selected shutdown
 *                cause as set by EcuM_SelectShutdownCause.
 * @param[out]    pShutdownCause: The selected cause of the next shutdown.
 * @return        Std_ReturnType
 * @retval        E_OK: The service has successed
 *                E_NOT_OK: The service has failed
 */
FUNC(Std_ReturnType, ECUM_CODE) EcuM_GetShutdownCause
(
	P2VAR(EcuM_ShutdownCauseType, AUTOMATIC, ECUM_APPL_DATA) pShutdownCause
)
{
	VAR(Std_ReturnType, AUTOMATIC) ret = (Std_ReturnType) E_OK;
	if(NULL_PTR == EcuM_ConfigPtr)
	{
#if (STD_ON == ECUM_DEV_ERROR_DETECT)
		(void)Det_ReportError
		(
			ECUM_MODULE_ID,
			ECUM_INSTANCE_ID,
			ECUM_SID_GETSHUTDOWNCAUSE,
			ECUM_E_UNINIT
		);
#endif /* (STD_ON == ECUM_DEV_ERROR_DETECT) */
		ret = (Std_ReturnType) E_NOT_OK;
	}
	else if(NULL_PTR == pShutdownCause)
	{
#if (STD_ON == ECUM_DEV_ERROR_DETECT)
		(void)Det_ReportError
		(
			ECUM_MODULE_ID,
			ECUM_INSTANCE_ID,
			ECUM_SID_GETSHUTDOWNCAUSE,
			ECUM_E_NULL_POINTER
		);
#endif /* (STD_ON == ECUM_DEV_ERROR_DETECT) */
		ret = (Std_ReturnType) E_NOT_OK;
	}
	else
	{
		(*pShutdownCause) = EcuM_InternalState.EcuM_ShutdownCase;
	}
	return ret;
}

/**
 * @sid           0x0D
 * @brief         Gets pending wakeup events.
 * @return        EcuM_WakeupSourceType: Wake up events which have been set
 *                but not yet validated.
 */
FUNC(EcuM_WakeupSourceType, ECUM_CODE) EcuM_GetPendingWakeupEvents
(
	void
)
{
	VAR(EcuM_WakeupSourceType, AUTOMATIC) ret = 0u;
	if(NULL_PTR == EcuM_ConfigPtr)
	{
#if (STD_ON == ECUM_DEV_ERROR_DETECT)
		(void)Det_ReportError
		(
			ECUM_MODULE_ID,
			ECUM_INSTANCE_ID,
			ECUM_SID_GETPENDINGWAKEUPEVENTS,
			ECUM_E_UNINIT
		);
#endif /* (STD_ON == ECUM_DEV_ERROR_DETECT) */
	}
	else
	{
		ret = EcuM_InternalState.EcuM_PendingWakeupEvents;
	}

	return ret;
}

/**
 * @sid            0x16
 * @brief          Clear wakeup events.
 * @param[in]      sources: Event to be cleared
 */
FUNC(void, ECUM_CODE) EcuM_ClearWakeupEvent
(
	CONST(EcuM_WakeupSourceType, AUTOMATIC) sources
)
{
	VAR(EcuM_WakeupSourceType, AUTOMATIC) clearEvents = (sources & ECUM_WAKEUP_SOURCE_MASK);
	if(NULL_PTR == EcuM_ConfigPtr)
	{
#if (STD_ON == ECUM_DEV_ERROR_DETECT)
		(void)Det_ReportError
		(
			ECUM_MODULE_ID,
			ECUM_INSTANCE_ID,
			ECUM_SID_CLEARWAKEUPEVENT,
			ECUM_E_UNINIT
		);
#endif /* (STD_ON == ECUM_DEV_ERROR_DETECT) */
	}
	else if(ECUM_WAKEUP_SOURCE_NONE == clearEvents)
	{
#if (STD_ON == ECUM_DEV_ERROR_DETECT)
		(void)Det_ReportError
		(
			ECUM_MODULE_ID,
			ECUM_INSTANCE_ID,
			ECUM_SID_CLEARWAKEUPEVENT,
			ECUM_E_UNKNOWN_WAKEUP_SOURCE
		);
#endif /* (STD_ON == ECUM_DEV_ERROR_DETECT) */
	}
	else
	{
		EcuM_InternalState.EcuM_ExpiredWakeupEvents &= ~clearEvents;
		EcuM_InternalState.EcuM_PendingWakeupEvents &= ~clearEvents;
		EcuM_InternalState.EcuM_ValidatedWakeupEvents &= ~clearEvents;
		EcuM_InternalState.EcuM_EnabledWakeupEvents &= ~clearEvents;
		EcuM_InternalState.EcuM_StartWakeupEvents &= ~clearEvents;
	}
}

/**
 * @sid           0x15
 * @brief         Gets validated wakeup events.
 * @return        EcuM_WakeupSourceType:All wakeup events.
 */
FUNC(EcuM_WakeupSourceType, ECUM_CODE) EcuM_GetValidatedWakeupEvents
(
	void
)
{
	VAR(EcuM_WakeupSourceType, AUTOMATIC) ret = 0u;
	if(NULL_PTR == EcuM_ConfigPtr)
	{
#if (STD_ON == ECUM_DEV_ERROR_DETECT)
		(void)Det_ReportError
		(
			ECUM_MODULE_ID,
			ECUM_INSTANCE_ID,
			ECUM_SID_GETVALIDATEDWAKEUPEVENTS,
			ECUM_E_UNINIT
		);
#endif /* (STD_ON == ECUM_DEV_ERROR_DETECT) */
	}
	else
	{
		ret = EcuM_InternalState.EcuM_ValidatedWakeupEvents;
	}

	return ret;
}

/**
 * @sid           0x19
 * @brief         Gets expired wakeup events.
 * @return        EcuM_WakeupSourceType:Returns all events that have been set and for
 *                which validation has failed.
 */
FUNC(EcuM_WakeupSourceType, ECUM_CODE) EcuM_GetExpiredWakeupEvents
(
	void
)
{
	VAR(EcuM_WakeupSourceType, AUTOMATIC) ret = 0u;
	if(NULL_PTR == EcuM_ConfigPtr)
	{
#if (STD_ON == ECUM_DEV_ERROR_DETECT)
		(void)Det_ReportError
		(
			ECUM_MODULE_ID,
			ECUM_INSTANCE_ID,
			ECUM_SID_GETEXPIREDWAKEUPEVENTS,
			ECUM_E_UNINIT
		);
#endif /* (STD_ON == ECUM_DEV_ERROR_DETECT) */
	}
	else
	{
		ret = EcuM_InternalState.EcuM_ExpiredWakeupEvents;
	}

	return ret;
}

#if (STD_ON == ECUM_ALARM_CLOCK_PRESENT)
/**
 * @sid           0x22
 * @brief         EcuM_SetRelWakeupAlarm sets a user's wakeup alarm relative to the current
 * 				  point in time.
 * @param[in]     user: The user that wants to set the wakeup alarm.
 *                time: Relative time from now in seconds.
 * @return        Std_ReturnType:Service result.
 * @retval        E_OK: The service has succeeded
 *                E_NOT_OK: The service failed
 *                ECUM_E_EARLIER_ACTIVE: An earlier alarm is already set
 */
FUNC(Std_ReturnType, ECUM_CODE) EcuM_SetRelWakeupAlarm
(
	CONST(EcuM_UserType, AUTOMATIC) user,
	CONST(EcuM_TimeType, AUTOMATIC) time
)
{
	VAR(Std_ReturnType, AUTOMATIC) ret;
	if(NULL_PTR == EcuM_ConfigPtr)
	{
#if (STD_ON == ECUM_DEV_ERROR_DETECT)
		(void)Det_ReportError
		(
			ECUM_MODULE_ID,
			ECUM_INSTANCE_ID,
			ECUM_SID_SETRELWAKEUPALARM,
			ECUM_E_UNINIT
		);
#endif /* (STD_ON == ECUM_DEV_ERROR_DETECT) */
		ret = (Std_ReturnType) E_NOT_OK;
	}
	else if(user >= ECUM_FLEX_USER_NUM)
	{
#if (STD_ON == ECUM_DEV_ERROR_DETECT)
		(void)Det_ReportError
		(
			ECUM_MODULE_ID,
			ECUM_INSTANCE_ID,
			ECUM_SID_SETRELWAKEUPALARM,
			ECUM_E_INVALID_PAR
		);
#endif /* (STD_ON == ECUM_DEV_ERROR_DETECT) */
		ret = (Std_ReturnType) E_NOT_OK;
	}
	else
	{
		ret = EcuM_SetUserAlarm(user,EcuM_InternalState.EcuM_RunTimer+time);
		/* Set User Alarm */
		if((Std_ReturnType)E_OK == ret)
		{
			/* Update Global Alarm */
			ret = EcuM_UpdateGlobalAlarm();
		}
	}

	return ret;
}
#endif /* STD_ON == ECUM_ALARM_CLOCK_PRESENT */

#if (STD_ON == ECUM_ALARM_CLOCK_PRESENT)
/**
 * @sid           0x23
 * @brief         EcuM_SetAbsWakeupAlarm sets the user's wakeup alarm to
 * 				  an absolute point in time.
 * @param[in]     user: The user that wants to set the wakeup alarm.
 *                time: Absolute time in seconds. Note that, absolute alarms use
 *                      knowledge of the current time.
 * @return        Std_ReturnType:Service result.
 * @retval        E_OK: The service has succeeded
 *                E_NOT_OK: The service failed
 *                ECUM_E_EARLIER_ACTIVE: An earlier alarm is already set
 *                ECUM_E_PAST: The given point in time has already passed
 */
FUNC(Std_ReturnType, ECUM_CODE) EcuM_SetAbsWakeupAlarm
(
	CONST(EcuM_UserType, AUTOMATIC) user,
	CONST(EcuM_TimeType, AUTOMATIC) time
)
{
	VAR(Std_ReturnType, AUTOMATIC) ret ;
	if(NULL_PTR == EcuM_ConfigPtr)
	{
#if (STD_ON == ECUM_DEV_ERROR_DETECT)
		(void)Det_ReportError
		(
			ECUM_MODULE_ID,
			ECUM_INSTANCE_ID,
			ECUM_SID_SETABSWAKEUPALARM,
			ECUM_E_UNINIT
		);
#endif /* (STD_ON == ECUM_DEV_ERROR_DETECT) */
		ret = (Std_ReturnType) E_NOT_OK;
	}
	else if(user >= ECUM_FLEX_USER_NUM)
	{
#if (STD_ON == ECUM_DEV_ERROR_DETECT)
		(void)Det_ReportError
		(
			ECUM_MODULE_ID,
			ECUM_INSTANCE_ID,
			ECUM_SID_SETABSWAKEUPALARM,
			ECUM_E_INVALID_PAR
		);
#endif /* (STD_ON == ECUM_DEV_ERROR_DETECT) */
		ret = (Std_ReturnType) E_NOT_OK;
	}
	else
	{
		ret = EcuM_SetUserAlarm(user,time);
		/* Set User Alarm */
		if((Std_ReturnType)E_OK == ret)
		{
			/* Update Global Alarm */
			ret = EcuM_UpdateGlobalAlarm();
		}
	}
	return ret;
}
#endif /* STD_ON == ECUM_ALARM_CLOCK_PRESENT */

#if (STD_ON == ECUM_ALARM_CLOCK_PRESENT)
/**
 * @sid           0x24
 * @brief         Ecum_AbortWakeupAlarm aborts the wakeup alarm previously set by this user.
 * @param[in]     user: The user that wants to cancel the wakeup alarm.
 * @return        Std_ReturnType:Service result.
 * @retval        E_OK: The service has succeeded
 *                E_NOT_OK: The service failed
 *                ECUM_E_NOT_ACTIVE:  No active alarm found
 */
FUNC(Std_ReturnType, ECUM_CODE) EcuM_AbortWakeupAlarm
(
	CONST(EcuM_UserType, AUTOMATIC) user
)
{
	VAR(Std_ReturnType, AUTOMATIC) ret = (Std_ReturnType) E_OK;
	VAR(uint8, AUTOMATIC) count ;
	VAR(boolean, AUTOMATIC) flag = (boolean) FALSE;
	if(NULL_PTR == EcuM_ConfigPtr)
	{
#if (STD_ON == ECUM_DEV_ERROR_DETECT)
		(void)Det_ReportError
		(
			ECUM_MODULE_ID,
			ECUM_INSTANCE_ID,
			ECUM_SID_ABORTWAKEUPALARM,
			ECUM_E_UNINIT
		);
#endif /* (STD_ON == ECUM_DEV_ERROR_DETECT) */
		ret = (Std_ReturnType) E_NOT_OK;
	}
	else if(user >= ECUM_FLEX_USER_NUM)
	{
#if (STD_ON == ECUM_DEV_ERROR_DETECT)
		(void)Det_ReportError
		(
			ECUM_MODULE_ID,
			ECUM_INSTANCE_ID,
			ECUM_SID_ABORTWAKEUPALARM,
			ECUM_E_INVALID_PAR
		);
#endif /* (STD_ON == ECUM_DEV_ERROR_DETECT) */
		ret = (Std_ReturnType) E_NOT_OK;
	}
	else
	{
		for(count = 0U; count < ECUM_ALARM_NUM; count++)
		{
			if(EcuM_ConfigPtr->EcuM_FlexConfigurationPtr->EcuM_AlarmClockPtr[count].\
																		EcuM_AlarmClockUser == user)
			{
				if(EcuM_InternalState.EcuM_UserAlarmTimer[count] != ECUM_INVALID_ALARM)
				{
					flag = (boolean)TRUE;
				}
				else
				{
					ret = (Std_ReturnType)ECUM_E_NOT_ACTIVE;
				}
				break;
			}
			else
			{
				ret = (Std_ReturnType)ECUM_E_NOT_ACTIVE;
			}
		}
		if(flag == (boolean)TRUE)
		{
			EcuM_InternalState.EcuM_UserAlarmTimer[count] = ECUM_INVALID_ALARM;
			/* Update Global Alarm */
			(void)EcuM_UpdateGlobalAlarm();
		}
		else
		{
			/* Do nothing */
		}

	}

	return ret;
}
#endif /* STD_ON == ECUM_ALARM_CLOCK_PRESENT */

#if (STD_ON == ECUM_ALARM_CLOCK_PRESENT)
/**
 * @sid           0x25
 * @brief         EcuM_GetCurrentTime returns the current value of the EcuM clock.
 * @param[out]    time: Absolute time in seconds since battery connect.
 * @return        Std_ReturnType:Service result.
 * @retval        E_OK: The service has succeeded
 *                E_NOT_OK: The service failed
 */
FUNC(Std_ReturnType, ECUM_CODE) EcuM_GetCurrentTime
(
	P2VAR(EcuM_TimeType, AUTOMATIC, ECUM_APPL_DATA) ptime
)
{
	VAR(Std_ReturnType, AUTOMATIC) ret = (Std_ReturnType) E_OK;
	if(NULL_PTR == EcuM_ConfigPtr)
	{
#if (STD_ON == ECUM_DEV_ERROR_DETECT)
		(void)Det_ReportError
		(
			ECUM_MODULE_ID,
			ECUM_INSTANCE_ID,
			ECUM_SID_GETCURRENTTIME,
			ECUM_E_UNINIT
		);
#endif /* (STD_ON == ECUM_DEV_ERROR_DETECT) */
		ret = (Std_ReturnType) E_NOT_OK;
	}
	else if(NULL_PTR == ptime)
	{
#if (STD_ON == ECUM_DEV_ERROR_DETECT)
		(void)Det_ReportError
		(
			ECUM_MODULE_ID,
			ECUM_INSTANCE_ID,
			ECUM_SID_GETCURRENTTIME,
			ECUM_E_NULL_POINTER
		);
#endif /* (STD_ON == ECUM_DEV_ERROR_DETECT) */
		ret = (Std_ReturnType) E_NOT_OK;
	}
	else
	{
		(*ptime) = EcuM_InternalState.EcuM_RunTimer;
	}

	return ret;
}
#endif /* STD_ON == ECUM_ALARM_CLOCK_PRESENT */

#if (STD_ON == ECUM_ALARM_CLOCK_PRESENT)
/**
 * @sid           0x26
 * @brief         EcuM_GetWakeupTime returns the current value of the master alarm clock.
 * @param[out]    time: Absolute time in seconds since battery connect.
 * @return        Std_ReturnType:Service result.
 * @retval        E_OK: The service has succeeded
 *                E_NOT_OK: time points to NULL or the module is not initialized
 */
FUNC(Std_ReturnType, ECUM_CODE) EcuM_GetWakeupTime
(
	P2VAR(EcuM_TimeType, AUTOMATIC, ECUM_APPL_DATA) ptime
)
{
	VAR(Std_ReturnType, AUTOMATIC) ret = (Std_ReturnType) E_OK;
	if(NULL_PTR == EcuM_ConfigPtr)
	{
#if (STD_ON == ECUM_DEV_ERROR_DETECT)
		(void)Det_ReportError
		(
			ECUM_MODULE_ID,
			ECUM_INSTANCE_ID,
			ECUM_SID_GETWAKEUPTIME,
			ECUM_E_UNINIT
		);
#endif /* (STD_ON == ECUM_DEV_ERROR_DETECT) */
		ret = (Std_ReturnType) E_NOT_OK;
	}
	else if(NULL_PTR == ptime)
	{
#if (STD_ON == ECUM_DEV_ERROR_DETECT)
		(void)Det_ReportError
		(
			ECUM_MODULE_ID,
			ECUM_INSTANCE_ID,
			ECUM_SID_GETWAKEUPTIME,
			ECUM_E_NULL_POINTER
		);
#endif /* (STD_ON == ECUM_DEV_ERROR_DETECT) */
		ret = (Std_ReturnType) E_NOT_OK;
	}
	else
	{
		(*ptime) = EcuM_InternalState.EcuM_AlarmTimer;
	}
	return ret;
}
#endif /* STD_ON == ECUM_ALARM_CLOCK_PRESENT */

#if (STD_ON == ECUM_ALARM_CLOCK_PRESENT)
/**
 * @sid           0x27
 * @brief         EcuM_SetClock sets the EcuM clock time to the provided value.
 * @details       This API is useful for testing the alarm services; Alarms that take days to expire can be tested.
 * @param[in]     user: The user that wants to cancel the wakeup alarm.
 *                time: Absolute time in seconds since battery connect.
 * @return        Std_ReturnType:Service result.
 * @retval        E_OK: The service has succeeded
 *                E_NOT_OK: The service failed
 */
FUNC(Std_ReturnType, ECUM_CODE) EcuM_SetClock
(
	CONST(EcuM_UserType, AUTOMATIC) user,
	CONST(EcuM_TimeType, AUTOMATIC) time
)
{
	VAR(Std_ReturnType, AUTOMATIC) ret = (Std_ReturnType) E_OK;
	if(NULL_PTR == EcuM_ConfigPtr)
	{
#if (STD_ON == ECUM_DEV_ERROR_DETECT)
		(void)Det_ReportError
		(
			ECUM_MODULE_ID,
			ECUM_INSTANCE_ID,
			ECUM_SID_SETCLOCK,
			ECUM_E_UNINIT
		);
#endif /* (STD_ON == ECUM_DEV_ERROR_DETECT) */
		ret = (Std_ReturnType) E_NOT_OK;
	}
	else if((user >= ECUM_FLEX_USER_NUM) || (time < EcuM_InternalState.EcuM_RunTimer))
	{
#if (STD_ON == ECUM_DEV_ERROR_DETECT)
		(void)Det_ReportError
		(
			ECUM_MODULE_ID,
			ECUM_INSTANCE_ID,
			ECUM_SID_SETCLOCK,
			ECUM_E_INVALID_PAR
		);
#endif /* (STD_ON == ECUM_DEV_ERROR_DETECT) */
		ret = (Std_ReturnType) E_NOT_OK;
	}
	else
	{
		/* Check user */
		if(ECUM_SET_CLOCK_ALLOWED_USERS_NUM == 0U) /* PRQA S 2742 # violate MSIAR2004_14.1: The macros here are generated by the configuration */
		{
#if (STD_ON == ECUM_DEV_ERROR_DETECT)
			(void)Det_ReportError  /* PRQA S 2880 # violate MSIAR2004_14.1: The error condition can occur */
			(
				ECUM_MODULE_ID,
				ECUM_INSTANCE_ID,
				ECUM_SID_SETCLOCK,
				ECUM_E_SERVICE_DISABLED
			);
#endif /* (STD_ON == ECUM_DEV_ERROR_DETECT) */
			ret = (Std_ReturnType) E_NOT_OK;
		}
		else
		{
			if((Std_ReturnType)E_OK == EcuM_CheckUser(ECUM_SET_CLOCK_USER_CHECK,user))
			{
				EcuM_InternalState.EcuM_RunTimer = time;
			}
			else
			{
				ret = (Std_ReturnType) E_NOT_OK;
			}
		}
	}
	return ret;
}
#endif /* STD_ON == ECUM_ALARM_CLOCK_PRESENT */

/**
 * @sid            0x12
 * @brief          Selects a boot target.
 * @param[in]      target: The selected boot target.
 * @return         E_OK: The new boot target was accepted by EcuM
 *                 E_NOT_OK: The new boot target was not accepted by EcuM
 */
FUNC(Std_ReturnType, ECUM_CODE) EcuM_SelectBootTarget
(
	CONST(EcuM_BootTargetType, AUTOMATIC) target
)
{
	VAR(Std_ReturnType, AUTOMATIC) ret = (Std_ReturnType) E_OK;
	if(NULL_PTR == EcuM_ConfigPtr)
	{
#if (STD_ON == ECUM_DEV_ERROR_DETECT)
		(void)Det_ReportError
		(
			ECUM_MODULE_ID,
			ECUM_INSTANCE_ID,
			ECUM_SID_SELECTBOOTTARGET,
			ECUM_E_UNINIT
		);
#endif /* (STD_ON == ECUM_DEV_ERROR_DETECT) */
		ret = (Std_ReturnType) E_NOT_OK;
	}
	else if
	(
		(target != ECUM_BOOT_TARGET_APP) &&
		(target != ECUM_BOOT_TARGET_OEM_BOOTLOADER) &&
		(target != ECUM_BOOT_TARGET_SYS_BOOTLOADER)
	)
	{
#if (STD_ON == ECUM_DEV_ERROR_DETECT)
		(void)Det_ReportError
		(
			ECUM_MODULE_ID,
			ECUM_INSTANCE_ID,
			ECUM_SID_SELECTBOOTTARGET,
			ECUM_E_INVALID_PAR
		);
#endif /* (STD_ON == ECUM_DEV_ERROR_DETECT) */
		ret = (Std_ReturnType) E_NOT_OK;
	}
	else
	{
		EcuM_BootTarget = target;
	}

	return ret;
}

/**
 * @sid            0x13
 * @brief          Returns the current boot target
 * @param[out]     pTarget: The currently selected boot target.
 * @return         E_OK: The service always succeeds.
 */
FUNC(Std_ReturnType, ECUM_CODE) EcuM_GetBootTarget
(
	P2VAR(EcuM_BootTargetType, AUTOMATIC, ECUM_APPL_DATA) pTarget
)
{
	VAR(Std_ReturnType, AUTOMATIC) ret = (Std_ReturnType) E_OK;
	if(NULL_PTR == EcuM_ConfigPtr)
	{
#if (STD_ON == ECUM_DEV_ERROR_DETECT)
		(void)Det_ReportError
		(
			ECUM_MODULE_ID,
			ECUM_INSTANCE_ID,
			ECUM_SID_GETBOOTTARGET,
			ECUM_E_UNINIT
		);
#endif /* (STD_ON == ECUM_DEV_ERROR_DETECT) */
		ret = (Std_ReturnType) E_NOT_OK;
	}
	else if(NULL_PTR == pTarget)
	{
#if (STD_ON == ECUM_DEV_ERROR_DETECT)
		(void)Det_ReportError
		(
			ECUM_MODULE_ID,
			ECUM_INSTANCE_ID,
			ECUM_SID_GETBOOTTARGET,
			ECUM_E_NULL_POINTER
		);
#endif /* (STD_ON == ECUM_DEV_ERROR_DETECT) */
		ret = (Std_ReturnType) E_NOT_OK;
	}
	else
	{
		(*pTarget) = EcuM_BootTarget;
	}

	return ret;
}

/**
 * @sid           0x18
 * @brief         The purpose of this service is to implement all activities of the ECU State Manager
 *                while the OS is up and running.
 */
FUNC(void, ECUM_CODE) EcuM_MainFunction
(
	void
)
{
	/**
	 * @req [SWS_EcuM_04002] When the Alarm Clock service is present the EcuM_MainFunction shall
     *      update the Alarm Clock Timer.
	 */
#if (STD_ON == ECUM_ALARM_CLOCK_PRESENT)
	EcuM_UpdateEcuMClock();
#endif /* STD_ON == ECUM_ALARM_CLOCK_PRESENT */

#if (STD_ON == ECUM_MODE_HANDLING)
	/* After waking up and verifying, the run action is executed */
	if(ECUM_WAKEUP_SOURCE_NONE != EcuM_GetValidatedWakeupEvents())
	{
		EcuM_ArbitrateAction();
	}
	else
	{
		/* Do nothing */
	}
#endif /* STD_ON == ECUM_MODE_HANDLING */

	/* If there are no pending events, wake-up verification is not performed */
	if(ECUM_WAKEUP_SOURCE_NONE != EcuM_GetPendingWakeupEvents())
	{
		EcuM_WakeupValidation();
	}
	else
	{
		/* Do nothing */
	}

}

/**
 * @sid            0x0C
 * @brief          Sets the wakeup event.
 * @details        Takes the value and stores it in an internal variable.
 * @param[in]      sources: Wakeup source.
 */
FUNC(void, ECUM_CODE) EcuM_SetWakeupEvent
(
	CONST(EcuM_WakeupSourceType, AUTOMATIC) sources
)
{
	VAR(EcuM_WakeupSourceType, AUTOMATIC) pendingEvents = (sources & ECUM_WAKEUP_SOURCE_MASK);
	if(NULL_PTR == EcuM_ConfigPtr)
	{
#if (STD_ON == ECUM_DEV_ERROR_DETECT)
		(void)Det_ReportError
		(
			ECUM_MODULE_ID,
			ECUM_INSTANCE_ID,
			ECUM_SID_SETWAKEUPEVENT,
			ECUM_E_UNINIT
		);
#endif /* (STD_ON == ECUM_DEV_ERROR_DETECT) */
	}
	else if((ECUM_WAKEUP_SOURCE_NONE == pendingEvents) || (pendingEvents != sources ))
	{
		/**
		 * @req [SWS_EcuM_02867] If Development Error Reporting is turned on and parameter
         *      “sources” contains an unknown (unconfigured) wakeup source, EcuM_SetWakeupEvent
         *      shall not update its internal variable and shall send the ECUM_E_UNKNOWN_WAKEUP_SOURCE
         *      error message to the DET module instead.
		 */
#if (STD_ON == ECUM_DEV_ERROR_DETECT)
		(void)Det_ReportError
		(
			ECUM_MODULE_ID,
			ECUM_INSTANCE_ID,
			ECUM_SID_SETWAKEUPEVENT,
			ECUM_E_UNKNOWN_WAKEUP_SOURCE
		);
#endif /* (STD_ON == ECUM_DEV_ERROR_DETECT) */
	}
	else
	{
		/**
		 * @req [SWS_EcuM_04138]  EcuM_SetWakeupEvent shall ignore all events passed in the
         *      sources parameter that are not associated to the selected sleep mode..
		 * @req [SWS_EcuM_01117] EcuM_SetWakeupEvent sets (OR-operation) all events passed
		 *      as a bit set in the sources in parameter (EcuM_WakeupSourceType bitmask) in
		 *      the internal pending wakeup events variable (see section 7.6.3 Internal
		 *      Representation of Wakeup States).
		 */
		EcuM_InternalState.EcuM_PendingWakeupEvents |= pendingEvents & \
													EcuM_InternalState.EcuM_EnabledWakeupEvents;
	}
}

/**
 * @sid            0x14
 * @brief          Indicate to the ECU Manager module that the wakeup events indicated in the
 *                 sources parameter have been validated.
 * @param[in]      sources: Wakeup sources.
 */
FUNC(void, ECUM_CODE) EcuM_ValidateWakeupEvent
(
	CONST(EcuM_WakeupSourceType, AUTOMATIC) sources
)
{
	VAR(EcuM_WakeupSourceType, AUTOMATIC) validateEvents = (sources & ECUM_WAKEUP_SOURCE_MASK);
	if(NULL_PTR == EcuM_ConfigPtr)
	{
#if (STD_ON == ECUM_DEV_ERROR_DETECT)
		(void)Det_ReportError
		(
			ECUM_MODULE_ID,
			ECUM_INSTANCE_ID,
			ECUM_SID_VALIDATEWAKEUPEVENT,
			ECUM_E_UNINIT
		);
#endif /* (STD_ON == ECUM_DEV_ERROR_DETECT) */
	}
	else if((ECUM_WAKEUP_SOURCE_NONE == validateEvents) || (validateEvents != sources ))
	{
		/**
		 * @req [SWS_EcuM_02868] If Development Error Reporting is turned on and sources
         *      parameter contains an unknown (unconfigured) wakeup source, EcuM_ValidateWakeupEvent
         *      shall  ignore the call and send the ECUM_E_UNKNOWN_WAKEUP_SOURCE error message to the
         *      DET module instead.
		 */
#if (STD_ON == ECUM_DEV_ERROR_DETECT)
		(void)Det_ReportError
		(
			ECUM_MODULE_ID,
			ECUM_INSTANCE_ID,
			ECUM_SID_VALIDATEWAKEUPEVENT,
			ECUM_E_UNKNOWN_WAKEUP_SOURCE
		);
#endif /* (STD_ON == ECUM_DEV_ERROR_DETECT) */
	}
	else
	{
		VAR(uint8, AUTOMATIC) count ;
		/**
		 * @req [SWS_EcuM_02790]  EcuM_ValidateWakeupEvent shall return without effect for
         *      all sources except communication channels when called while the ECU Manager
         *      module is in the RUN state.
		 * @req [SWS_EcuM_02791] EcuM_ValidateWakeupEvent shall have full effect in any ECU
		 *      Phase for those sources that correspond to a communication channel
		 *      (see SWS_EcuM_02645).
		 */
		if	(
				(ECUM_WAKEUP_SOURCE_NONE == EcuM_GetValidatedWakeupEvents()) ||
				(ECUM_WAKEUP_SOURCE_NONE != (ECUM_WAKEUP_SOURCE_COMM_CHANNEL_MASK & validateEvents))
			)
		{
			/* Update the internal state of the wake-up sources */
			EcuM_InternalState.EcuM_ValidatedWakeupEvents |= validateEvents;
			EcuM_InternalState.EcuM_PendingWakeupEvents &= ~validateEvents;
			EcuM_InternalState.EcuM_StartWakeupEvents &= ~validateEvents;
			/**
			 * @req [SWS_EcuM_04079] EcuMValidateWakeupEvent shall invoke BswM_EcuM_CurrentWakeup
			 *      with its sources parameter and state value ECUM_WKSTATUS_VALIDATED.
			 */
			BswM_EcuM_CurrentWakeup(validateEvents, ECUM_WKSTATUS_VALIDATED);
			for(count = 0U; count < ECUM_WAKEUP_SOURCE_NUM; count++)
			{
				if((EcuM_WakeupSourceType)1 == ((validateEvents >> count) & 1U))
				{
					/**
					 * @req [SWS_EcuM_02645] EcuM_ValidateWakeupEvent shall invoke
			         *      ComM_EcuM_WakeUpIndication for each wakeup event if the EcuMComMChannelRef
			         *      parameter in the EcuMWakeupSource configuration container for the
			         *      corresponding wakeup source is configured.
					 */
					if(ECUM_INVALID_COMM_CHANNEL != EcuM_ConfigPtr->EcuM_CommonConfigurationPtr->EcuM_WakeupSourcePtr[count].EcuM_ComMChannelRef)
					{
					#if (STD_ON == ECUM_INCLUDE_COMM)
						ComM_EcuM_WakeUpIndication(EcuM_ConfigPtr->EcuM_CommonConfigurationPtr->EcuM_WakeupSourcePtr[count].EcuM_ComMChannelRef);
					#endif
					}
					else
					{
						/* Do nothing */
					}
				}
				else if(ECUM_WAKEUP_SOURCE_NONE == (validateEvents >> count))
				{
					break;
				}
				else
				{
					/* Do nothing */
				}
			}
		}
		else
		{
			/* Do nothing */
		}
	}
}

#define ECUM_STOP_SEC_CODE
#include "EcuM_MemMap.h"

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */
/** @} */

