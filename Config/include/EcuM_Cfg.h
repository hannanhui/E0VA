/**
 *  @file     EcuM_Cfg.h
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
#ifndef EcuM_CFG_H
#define EcuM_CFG_H

#ifdef __cplusplus
extern "C"{
#endif

/*====================================================================================================*
 *                                           INCLUDE FILES                                          
 *====================================================================================================*/

#include "Mcu_Cfg.h"

/*====================================================================================================*
 *                                  HEADER FILE VERSION INFORMATION                                 
 *====================================================================================================*/

#define ECUM_CFG_VENDOR_ID                           0U
#define ECUM_CFG_SW_MAJOR_VERSION                    1U
#define ECUM_CFG_SW_MINOR_VERSION                    2U
#define ECUM_CFG_SW_PATCH_VERSION                    0U
#define ECUM_CFG_AR_RELEASE_MAJOR_VERSION            4U
#define ECUM_CFG_AR_RELEASE_MINOR_VERSION            2U
#define ECUM_CFG_AR_RELEASE_REVISION_VERSION         2U

/*====================================================================================================*
 *                                         FILE VERSION CHECKS                                      
 *====================================================================================================*/

#ifndef DISABLE_INTERMOD_VERSION_CHECK
/* Check if current file and Mcu_Cfg header file are of the same Autosar version */
#if(\
        (ECUM_CFG_AR_RELEASE_MAJOR_VERSION != MCU_CFG_AR_RELEASE_MAJOR_VERSION) || \
        (ECUM_CFG_AR_RELEASE_MINOR_VERSION != MCU_CFG_AR_RELEASE_MINOR_VERSION)  \
    )
#error "AutoSar Version Number of EcuM_Cfg.h and Mcu_Cfg.h are different "
#endif
#endif /* #ifndef DISABLE_INTERMOD_VERSION_CHECK */
/*====================================================================================================*
 *                                             CONSTANTS                                            
 *====================================================================================================*/

/*====================================================================================================*
 *                                         DEFINES AND MACROS                                       
 *====================================================================================================*/

/**
 * @{
 * @brief         EcuMGeneral
 */

/**
 * @brief         EcuMDevErrorDetect
 * @details       STD_ON  - Enable default error detect.
 *                STD_OFF - Disable default error detect.
 * @req           ECUC_EcuM_00108
 */
#define ECUM_DEV_ERROR_DETECT                (STD_OFF)


/**
 * @brief         EcuMIncludeDet
 * @details       STD_ON  - Det will be initialized by the ECU State Manager.
 *                STD_OFF - Det will not be initialized by the ECU State Manager.
 * @req           ECUC_EcuM_00118
 */
#define ECUM_INCLUDE_DET                     (STD_OFF)
 

/**
 * @brief         EcuMMainFunctionPeriod
 * @details       This parameter defines the schedule period of EcuM_MainFunction. Unit: [ms]
 * @range         [0, INF]
 * @req           ECUC_EcuM_00121
 */                                        
#define ECUM_MAIN_FUNCTION_PERIOD            (10U)

/**
 * @brief         EcuMVersionInfoApi
 * @details       STD_ON  - Enable version info API.
 *                STD_OFF - Disable version info API.
 * @req           ECUC_EcuM_00149
 */
#define ECUM_VERSION_INFO_API                (STD_OFF)

/** @} */

/**
 * @{
 * @brief         EcuMFlexGeneral
 */

/**
 * @brief         This flag indicates whether the optional AlarmClock feature is present.
 * @req           ECUC_EcuM_00199
 */
#define ECUM_ALARM_CLOCK_PRESENT             (STD_OFF)



/**
 * @brief         If false, Run Request Protocol is not performed.
 * @req           ECUC_EcuM_00221
 */
#define ECUM_MODE_HANDLING                   (STD_OFF)

/**
 * @brief         If false, no reset loop detection is performed. If this configuration
 *                parameter exists and is set to true, the callout "EcuM_LoopDetection" is
 *                called during startup of EcuM (during StartPreOS).
 * @req           ECUC_EcuM_00171
 */

#define ECUM_RESET_LOOP_DETECTION            (STD_OFF)

/**
 * @brief         If this configuration parameter exists and is to true, the callout
 *                "EcuM_AL_SetProgrammableInterrupts" is called during startup of EcuM
 *                (during StartPreOS).
 * @req           ECUC_EcuM_00210
 */
#define ECUM_SET_PROGRAMMABLE_INTERRUPTS     (STD_OFF)

/**
 * @brief         This parameter describes the reference to the EcuMWakeupSource being
 *                used for the EcuM AlarmClock.
 * @req           ECUC_EcuM_00200
 */
#define ECUM_ALARM_WAKEUP_SOURCE             (0U)

/** @} */

/**
 * @brief          Hash values of all BSW modules parameters.
 */
#define ECUM_CONFIGCONSISTENCY_HASH	         (0U)

/**
 * @brief         Number of wakeup sources.  
 */
#define ECUM_WAKEUP_SOURCE_NUM               (6U)

/**
 * @brief         Number of sleep modes.
 */
#define ECUM_SLEEP_MODE_NUM                  (1U)

/**
 * @brief         Number of flex users.
 */
#define ECUM_FLEX_USER_NUM                   (1U)

/**
 * @brief         Number of sleep modes.
 */
#define ECUM_RESET_MODE_NUM                  (3U)

/**
 * @brief         Number of alarm.
 */
#define ECUM_ALARM_NUM                       (0U)

/**
 * @brief         Number of Shutdown cause.
 */
#define ECUM_SHUTDOWN_CAUSE_NUM				 (4U)

/**
* @brief         Number of Os resource which is used to bring the ECU into sleep mode.
*/
#define ECUM_OS_RESOURCE_NUM				 (1U)

/**
 * @brief         Number of user who allows setting alarm.
 */
#define ECUM_SET_CLOCK_ALLOWED_USERS_NUM	 (0U)

/**
 * @brief         Number of user who allows to call godown.
 */
#define ECUM_GO_DOWN_ALLOWED_USERS_NUM		(1U)

/**
 * @brief         Whether to configure initialization block 0
 * @details       STD_ON  - Initialization block 0 is configured .
 *                STD_OFF - Initialization block 0 is not configured .
 * @req           ECUC_EcuM_00149
 */
#define ECUM_DRIVER_INIT_LIST_ZERO			(STD_ON)

/**
 * @brief         Whether to configure initialization block 1
 * @details       STD_ON  - Initialization block 1 is configured .
 *                STD_OFF - Initialization block 1 is not configured .
 * @req           ECUC_EcuM_00149
 */
#define ECUM_DRIVER_INIT_LIST_ONE			(STD_ON)

/**
 * @brief         Mask for the configured wake-up source.
 */
#define ECUM_WAKEUP_SOURCE_MASK					(63U)

/**
 * @brief         The mask required to verify the wake-up source source is configured.
 */
#define ECUM_WAKEUP_SOURCE_NEED_VALIDATION_MASK	(32U)


/**
 * @brief         The configured wake-up source is the communication channel.
 */
#define ECUM_WAKEUP_SOURCE_COMM_CHANNEL_MASK	(32U)

/**
 * @brief         Configured mask that does not need verify the wake-up source.
 */
#define ECUM_WAKEUP_SOURCE_NO_VALIDATION_MASK	(31U)

/**
* @brief         A wake source in the configured wake source that requires cyclic verification.
*/
#define ECUM_WAKEUP_SOURCE_NEED_POLL_MASK	    (33U)

/**
 * @brief         Invalid communication channel.
 */
#define	ECUM_INVALID_COMM_CHANNEL			 (0xFFU)

/**
 * @brief         Invalid partition.
 */
#define ECUM_INVALID_PARTITION				 (0xFFFFFFFFU)


/* The time when the wake-up verification is invalid */
#define ECUM_INVALID_TIME					 (0xFFFFU)

#define ECUM_INSTANCE_ID				     (0U)

 
 
 
 
 
 
 
/* Does EcuM need to use ComM channels */
#define ECUM_INCLUDE_COMM (STD_ON)

#define EcuMConf_EcuMResetMode_EcuMResetMode_Mcu 		 (0U)
#define EcuMConf_EcuMResetMode_EcuMResetMode_Wgd 		 (1U)
#define EcuMConf_EcuMResetMode_EcuMResetMode_IO 		 (2U)

#define EcuMConf_EcuMFlexUserConfig_EcuMFlexUserConfig_0 		 (0U)

#define EcuMConf_EcuMWakeupSource_EcuMWakeupSource_Power 		 (1U)
#define EcuMConf_EcuMWakeupSource_EcuMWakeupSource_Reset 		 (2U)
#define EcuMConf_EcuMWakeupSource_EcuMWakeupSource_Internal 		 (4U)
#define EcuMConf_EcuMWakeupSource_EcuMWakeupSource_Internal_Wdg 		 (8U)
#define EcuMConf_EcuMWakeupSource_EcuMWakeupSource_External_Wdg 		 (16U)
#define EcuMConf_EcuMWakeupSource_EcuMWakeupSource_SW_Wake_Up 		 (32U)

#define EcuMConf_EcuMSleepMode_EcuMSleepMode_0 		 (0U)


#define EcuMConf_EcuMShutdownCause_EcuMShutdownCause_UNKNOWN 		 (0U)
#define EcuMConf_EcuMShutdownCause_EcuMShutdownCause_STATE 		 (1U)
#define EcuMConf_EcuMShutdownCause_EcuMShutdownCause_WDGE 		 (2U)
#define EcuMConf_EcuMShutdownCause_EcuMShutdownCause_DCM 		 (3U)




/*====================================================================================================*
 *                                               ENUMS                                              
 *====================================================================================================*/

/*====================================================================================================*
 *                                   STRUCTURES AND OTHER TYPEDEFS                                  
 *====================================================================================================*/

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

#endif /* !defined (ECUM_CFG_H) */
