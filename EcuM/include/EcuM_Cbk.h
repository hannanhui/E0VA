/** 
 *  @file     EcuM_Cbk.h
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
#ifndef ECUM_CBK_H
#define ECUM_CBK_H

#if defined(__cplusplus)
extern "C" 
{
#endif /* defined(__cplusplus) */

/*====================================================================================================*
 *                                           INCLUDE FILES
 *====================================================================================================*/
#include "EcuM_Types.h"/* PRQA S 0810  # violate MSIAR2004_1.1: This file needs to be included */

/*====================================================================================================*
 *                                  HEADER FILE VERSION INFORMATION
 *====================================================================================================*/

#define ECUM_CBK_VENDOR_ID                       0U
#define ECUM_CBK_AR_RELEASE_MAJOR_VERSION        4U
#define ECUM_CBK_AR_RELEASE_MINOR_VERSION        2U
#define ECUM_CBK_AR_RELEASE_REVISION_VERSION     2U
#define ECUM_CBK_SW_MAJOR_VERSION                1U
#define ECUM_CBK_SW_MINOR_VERSION                2U
#define ECUM_CBK_SW_PATCH_VERSION                0U

/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/
/* Check if current file and EcuM_Types.h file are of the same vendor */
#if(ECUM_CBK_VENDOR_ID != ECUM_TYPES_VENDOR_ID )
#error "EcuM_Cbk.h and EcuM_Types.h have different vendor id"
#endif
/* Check if current file and EcuM_Types.h header file are of the same Autosar version */
#if(\
		(ECUM_CBK_AR_RELEASE_MAJOR_VERSION != ECUM_TYPES_AR_RELEASE_MAJOR_VERSION) || \
		(ECUM_CBK_AR_RELEASE_MINOR_VERSION != ECUM_TYPES_AR_RELEASE_MINOR_VERSION) || \
		(ECUM_CBK_AR_RELEASE_REVISION_VERSION != ECUM_TYPES_AR_RELEASE_REVISION_VERSION) \
	)
#error "AutoSar Version Number of EcuM_Cbk.h and EcuM_Types.h are different "
#endif
/* Check if current file and EcuM_Types.h header file are of the same software version */
#if(\
		(ECUM_CBK_SW_MAJOR_VERSION != ECUM_TYPES_SW_MAJOR_VERSION) || \
		(ECUM_CBK_SW_MINOR_VERSION != ECUM_TYPES_SW_MINOR_VERSION) || \
		(ECUM_CBK_SW_PATCH_VERSION != ECUM_TYPES_SW_PATCH_VERSION) \
	)
#error "Software Version Number of EcuM_Cbk.h and EcuM_Types.h are different "
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

/*====================================================================================================*
 *                                   STRUCTURES AND OTHER TYPEDEFS
 *====================================================================================================*/

/**
 * @brief          The default shutdown targete of EcuM
 */
typedef struct
{
	/**< @brief Defult shutdown target for EcuM*/
	VAR(EcuM_ShutdownTargetType, ECUM_VAR) EcuM_DefaultState;
	/**< @brief Defult shutdown mode of EcuM*/
	VAR(EcuM_ShutdownModeType, ECUM_VAR) EcuM_DefaultShutdownMode;
} EcuM_DefaultShutdownTargetType;

/**
 * @brief          The Sleep Mode of EcuM
 * @req            SWS_ECUM_00131
 */
typedef struct
{
	/**< @brief Identification of sleep mode of EcuM*/
	VAR(uint8, ECUM_VAR) EcuM_SleepModeId;
	/**< @brief The symbol of EcuM's sleep mode : ture-Halt ,false-Poll*/
	VAR(boolean, ECUM_VAR) EcuM_SleepModeSuspend;
	/**< @brief The Mcu mode corresponding to this sleep mode.Mcu module type: Mcu_ModeType*/
	VAR(uint8, ECUM_VAR) EcuM_SleepModeMcuModeRef;
	/**< @brief Wake-up sources that can be enabled for this sleep mode*/
	VAR(EcuM_WakeupSourceType, ECUM_VAR) EcuM_WakeupSourceMask;
} EcuM_SleepModeType;

/**
 * @brief          The Wake-up Source of EcuM
 * @req            SWS_ECUM_00150
 */
typedef struct
{
	/**< @brief This parameter describes if the wakeup source needs polling*/
	VAR(boolean, ECUM_VAR) EcuM_WakeupSourcePolling;
	/**< @brief This parameter is a reference to a Network (channel) defined in the
	 *          Communication Manager.Com module type: NetworkHandleType */
	VAR(uint8, ECUM_VAR) EcuM_ComMChannelRef;
	/**< @brief The number of reset maps detected by Mcu to wake-up sources */
	VAR(uint8, ECUM_VAR) EcuM_NumberOfResetReason;
	/**< @brief This Parameter is the initial Value for the Time of the EcuM to delay shut down of
	 *          the ECU if the check of the Wakeup Source is done asynchronously . Unit: [ms]*/
	VAR(uint16, ECUM_VAR) EcuM_CheckWakeupTimeout;
	/**< @brief Period for which the ECU State Manager will wait for the validation of a wakeup
	 *          event. Unit: [ms]*/
	VAR(uint16, ECUM_VAR) EcuM_ValidationTimeout;
	/**< @brief This parameter defines the identifier of this wakeup source*/
	VAR(EcuM_WakeupSourceType, ECUM_VAR) EcuM_WakeupSourceMask;
	/**< @brief  This parameter describes the mapping of reset reasons detected by the
                 MCU driver into wakeup sources*/
	P2CONST(uint8, ECUM_VAR, ECUM_APPL_CONST) EcuM_ResetReasonRefPtr;
} EcuM_WakeupSourceCfgType;

/**
 * @brief          The common configuration (parameters) of the ECU State Manager
 * @req            SWS_ECUM_00181
 */
typedef struct
{
	/**< @brief The default application mode loaded when the ECU comes out of reset.
	 *          Os module type: AppModeType */
	VAR(uint8, ECUM_VAR) EcuM_DefaultAppMode;
	/**< @brief This parameter is a reference to a OS resource which is used to bring the
                ECU into sleep mode. Os module type: ResourceType*/
	P2CONST(uint32, ECUM_VAR, ECUM_APPL_CONST) EcuM_OsResource;
	/**< @brief This container describes the default shutdown target to be selected by EcuM.*/
	P2CONST(EcuM_DefaultShutdownTargetType, ECUM_VAR, ECUM_APPL_CONST) EcuM_DefaultShutdownTargetPtr;
	/**< @brief These containers describe the configured sleep modes.*/
	P2CONST(EcuM_SleepModeType, ECUM_VAR, ECUM_APPL_CONST) EcuM_SleepModePtr;
	/**< @brief These containers describe the configured wakeup sources*/
	P2CONST(EcuM_WakeupSourceCfgType, ECUM_VAR, ECUM_APPL_CONST) EcuM_WakeupSourcePtr;
} EcuM_CommonConfigurationType;

/* Obsolete */
typedef struct
{
	VAR(uint8, ECUM_VAR) Obsolete;
} EcuM_FixedConfigurationType;

/**
 * @brief          Alarm clock related information of the ECU State Manager
 * @req            SWS_ECUM_00184
 */
typedef struct
{
	/**< @brief This ID identifies this alarmclock*/
	VAR(uint8, ECUM_VAR) EcuM_AlarmClockId;
	/**< @brief This parameter allows an alarm to be assigned to a user*/
	VAR(uint8, ECUM_VAR) EcuM_AlarmClockUser;
	/**< @brief This parameter allows to define a timeout for this alarm clock*/
	VAR(uint32, ECUM_VAR) EcuM_AlarmClockTimeOut;
} EcuM_AlarmClockType;

/**
 * @brief          the identifiers that are needed to refer to a software component or another
 *                 appropriate entity in the system which uses the EcuMFlex Interfaces
 * @req            SWS_ECUM_00201
 */
typedef struct
{
	/**< @brief Parameter used to identify one user*/
	VAR(uint8, ECUM_VAR) EcuM_FlexUser;
	/**< @brief Denotes in which "EcucPartition" the user of the EcuM is executed*/
	P2CONST(uint32, ECUM_VAR, ECUM_APPL_CONST) EcuM_FlexEcucPartitionRefPtr;
} EcuM_FlexUserConfigType;

/**
 * @brief          Contains the configuration (parameters) of the EcuMFlex.
 * @req            SWS_ECUM_00167
 */
typedef struct
{
	/**< @brief This parameter is a reference to the normal MCU mode to be restored
                after a sleep.Mcu module type: Mcu_ModeType*/
	VAR(uint8, ECUM_VAR) EcuM_NormalMcuModeRef;
	/**< @brief Reference denotes the partition a EcuM shall run inside*/
	P2CONST(uint32, ECUM_VAR, ECUM_APPL_CONST) EcuM_PartitionRefPtr;
	/**< @brief These containers describe the configured alarm clocks*/
	P2CONST(EcuM_AlarmClockType, ECUM_VAR, ECUM_APPL_CONST) EcuM_AlarmClockPtr;
	/**< @brief These containers describe the identifiers that are needed to refer to a software
	 *          component or another appropriate entity in the system which uses the EcuMFlex
	 *          Interfaces*/
	P2CONST(EcuM_FlexUserConfigType, ECUM_VAR, ECUM_APPL_CONST) EcuM_FlexUserConfigPtr;
	/**< @brief This container describes the collection of allowed users which are allowed to call
	 *          the EcuM_GoDown API*/
	P2CONST(uint8, ECUM_VAR, ECUM_APPL_CONST) EcuM_GoDownAllowedUsersPtr;
	/**< @brief This container describes the collection of allowed users which are allowed to call
	 *          the EcuM_SetClock API*/
	P2CONST(uint8, ECUM_VAR, ECUM_APPL_CONST) EcuM_SetClockAllowedUsersPtr;
} EcuM_FlexConfigurationType;

/**
 * @brief         Type of configuration structure of EcuM.
 * @details       A pointer to such a structure shall be provided to the ECU State Manager
 *                initialization routine for configuration.
 * @req           SWS_ECUM_00046
 */
typedef struct
{
	/**< @brief A hash value generated across all pre-compile and link-time parameters of
	 *          all BSW modules.*/
	CONST(uint16, ECUM_VAR) EcuM_ConfigConsistencyHash;
	/**< @brief This container contains the common configuration (parameters) of the
	 *          ECU State Manager*/
	P2CONST(EcuM_CommonConfigurationType, ECUM_VAR, ECUM_APPL_CONST) EcuM_CommonConfigurationPtr;
	/**< @brief This container contains the configuration (parameters) of the EcuMFixed.unused*/
	P2CONST(EcuM_FixedConfigurationType, ECUM_VAR, ECUM_APPL_CONST) EcuM_FixedConfigurationPtr;
	/**< @brief This container contains the configuration (parameters) of the EcuMFlex*/
	P2CONST(EcuM_FlexConfigurationType, ECUM_VAR, ECUM_APPL_CONST) EcuM_FlexConfigurationPtr;
} EcuM_ConfigType;
/*====================================================================================================*
 *                                    GLOBAL VARIABLE DECLARATIONS
 *====================================================================================================*/

/*====================================================================================================*
 *                                        FUNCTION PROTOTYPES
 *====================================================================================================*/
#define ECUM_START_SEC_CODE
#include "EcuM_MemMap.h"

FUNC(void, ECUM_CODE) EcuM_CheckWakeup
(
	CONST(EcuM_WakeupSourceType, AUTOMATIC) wakeupSource
);

FUNC(void, ECUM_CODE) EcuM_SetWakeupEvent/* PRQA S 3451  # violate MSIAR2004_8.8: Need to declare here */
(
	CONST(EcuM_WakeupSourceType, AUTOMATIC) sources
);

FUNC(void, ECUM_CODE) EcuM_ValidateWakeupEvent
(
	CONST(EcuM_WakeupSourceType, AUTOMATIC) sources
);

FUNC(void, ECUM_CODE) EcuM_ErrorHook
(
	CONST(uint16, AUTOMATIC) reason
);
#if(STD_ON == ECUM_SET_PROGRAMMABLE_INTERRUPTS) /* PRQA S 3332  EOF# violate MSIAR2004_21.1:
 	 	 	 	 	 	 	 	 	 	 	No operation is required when the macro switch is off.*/
FUNC(void, ECUM_CODE) EcuM_AL_SetProgrammableInterrupts
(
	void
);
#endif /* STD_ON == ECUM_SET_PROGRAMMABLE_INTERRUPTS */

#if(STD_ON == ECUM_DRIVER_INIT_LIST_ZERO)
FUNC(void, ECUM_CODE) EcuM_AL_DriverInitZero
(
	void
);
#endif /* STD_ON == ECUM_DRIVER_INIT_LIST_ZERO */

FUNC(const EcuM_ConfigType*, ECUM_CODE) EcuM_DeterminePbConfiguration
(
	void
);

#if(STD_ON == ECUM_DRIVER_INIT_LIST_ONE)
FUNC(void, ECUM_CODE) EcuM_AL_DriverInitOne
(
	P2CONST(EcuM_ConfigType, AUTOMATIC, ECUM_APPL_CODE) ConfigPtr
);
#endif /* STD_ON == ECUM_DRIVER_INIT_LIST_ONE */

#if(STD_ON == ECUM_RESET_LOOP_DETECTION)
FUNC(boolean, ECUM_CODE) EcuM_LoopDetection
(
	void
);
#endif /* STD_ON == ECUM_RESET_LOOP_DETECTION */
FUNC(void, ECUM_CODE) EcuM_OnGoOffOne
(
	void
);

FUNC(void, ECUM_CODE) EcuM_OnGoOffTwo
(
	void
);

FUNC(void, ECUM_CODE) EcuM_AL_SwitchOff
(
	void
);

FUNC(void, ECUM_CODE) EcuM_AL_Reset
(
	CONST(EcuM_ResetType, AUTOMATIC) reset
);

FUNC(void, ECUM_CODE) EcuM_EnableWakeupSources
(
	CONST(EcuM_WakeupSourceType, AUTOMATIC) wakeupSource
);

FUNC(void, ECUM_CODE) EcuM_GenerateRamHash
(
	void
);

FUNC(void, ECUM_CODE) EcuM_SleepActivity
(
	void
);

FUNC(void, ECUM_CODE) EcuM_StartCheckWakeup
(
	CONST(EcuM_WakeupSourceType, AUTOMATIC) WakeupSource
);

FUNC(void, ECUM_CODE) EcuM_EndCheckWakeup
(
	CONST(EcuM_WakeupSourceType, AUTOMATIC) WakeupSource
);

FUNC(uint8, ECUM_CODE) EcuM_CheckRamHash
(
	void
);

FUNC(void, ECUM_CODE) EcuM_DisableWakeupSources
(
	CONST(EcuM_WakeupSourceType, AUTOMATIC) wakeupSource
);

FUNC(void, ECUM_CODE) EcuM_AL_DriverRestart
(
	P2CONST(EcuM_ConfigType, AUTOMATIC, ECUM_APPL_DATA) ConfigPtr
);

FUNC(void, ECUM_CODE) EcuM_StartWakeupSources
(
	CONST(EcuM_WakeupSourceType, AUTOMATIC) wakeupSource
);

FUNC(void, ECUM_CODE) EcuM_CheckValidation
(
	CONST(EcuM_WakeupSourceType, AUTOMATIC) wakeupSource
);

FUNC(void, ECUM_CODE) EcuM_StopWakeupSources
(
	CONST(EcuM_WakeupSourceType, AUTOMATIC) wakeupSource
);

#define ECUM_STOP_SEC_CODE
#include "EcuM_MemMap.h"

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* !defined ECUM_CBK_H */
/** @} */
