/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Pwm_Cfg.h
 *  @Syntax          : GNU99
 *  @Author          : ChipON AE/FAE Group
 *  @Date            : 2026/4/15 09:39:52
 *  @Version         : V1.0
 *  @Description     : AUTOSAR Pwm - Pwm configuration file.
 ******************************************************************************
 *  Copyright (C) by Shanghai ChipON Micro-Electronic Co.,Ltd
 *  All rights reserved.
 *
 *  This software is copyright protected and proprietary to
 *  Shanghai ChipON Micro-Electronic Co.,Ltd.
 *****************************************************************************/
#ifndef PWM_CFG_H
#define PWM_CFG_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 **                        Include Files
 ******************************************************************************/

/******************************************************************************
 **                        File Version Check
 ******************************************************************************/

/******************************************************************************
 **                        Macro Definitions
 ******************************************************************************/
/**
 * @brief Symbolic name for general channels
 */
#define PWM_GENERAL_CHANNEL (0U)

/**
 * @brief Symbolic name for Advance channels
 */
#define PWM_ADVANCE_CHANNEL (1U)

/**
 * @brief Symbolic name for Enhance channels
 */
#define PWM_ENHANCE_CHANNEL (2U)

/**
 * @brief Maximum number of advance timer modules
 */
#define PWM_MAX_ADVANCE_TIMER_NUM (2U)

/**
 * @brief Maximum number of general timer modules
 */
#define PWM_MAX_GENERAL_TIMER_NUM (7U)

/**
 * @brief Maximum number of enhance timer modules
 */
#define PWM_MAX_ENHANCE_TIMER_NUM (8U)

/**
 * @brief channel information
 */
#define PWM_CONFIG_CHANNEL_1 ((uint8)0x00U)
#define PWM_CONFIG_CHANNEL_2 ((uint8)0x01U)
#define PWM_CONFIG_CHANNEL_3 ((uint8)0x02U)
#define PWM_CONFIG_CHANNEL_4 ((uint8)0x03U)

/**
 * @brief Specifies the InstanceId of this module instance.
 * @details Specifies the InstanceId of this module instance. If only one instance is present it shall have the Id 0.
 * Not used in the current implementation
 */
#define PWM_INDEX (0U)

/**
 * @brief Define to indicate general is used(T0,T1,T2,T3,T4,T18,T19,T21,T22,T23)
 */
#define PWM_GENERAL_USED (STD_ON)

/**
 * @brief Define to indicate advanced is used(T5\T6,T9\T10,T25\T26)
 */
#define PWM_ADVANCE_USED (STD_OFF)

/**
 * @brief Define to indicate enhance is used(T11,T12,T13,T16)
 * @details not support
 */
#define PWM_ENHANCE_USED (STD_ON)

/**
 * @brief Switch for enabling the development error detection.
 */
#define PWM_DEV_ERROR_DETECT (STD_OFF)

/**
 * @brief Switch for enabling the update of the duty cycle parameter at the end of the current period.
 */
#define PWM_DUTYCYCLE_UPDATED_ENDPERIOD (STD_ON)

/**
 * @brief Adds / removes all power state management related APIs (PWM_SetPowerState, PWM_GetCurrentPowerState,
 * PWM_GetTargetPowerState, PWM_PreparePowerState, PWM_Main_PowerTransitionManager), indicating if the HW offers low
 * power state management.
 */
#define PWM_LOW_POWER_STATES_SUPPORT (STD_OFF)

/**
 * @brief Switch for enabling the update of the period parameter at the end of the current period.
 */
#define PWM_PERIOD_UPDATED_ENDPERIOD (STD_ON)

/**
 * @brief Switch to indicate that Pwm_DeInit API is supported
 */
#define PWM_DE_INIT_API (STD_ON)

/**
 * @brief Switch to indicate that Pwm_SetDutyCycle API is supported
 */
#define PWM_SET_DUTY_CYCLE_API (STD_ON)

/**
 ** @brief Switch to indicate that Pwm_SetPeriodAndDuty API is supported
 */
#define PWM_SET_PERIOD_AND_DUTY_API (STD_ON)

/**
 * @brief Switch to indicate that Pwm_SetOutputToIdle API is supported
 */
#define PWM_SET_OUTPUT_TO_IDLE_API (STD_ON)

/**
 * @brief Switch to indicate that Pwm_GetOutputState API is supported
 *
 * @note hardware not support
 */
#define PWM_GET_OUTPUT_STATE_API (STD_OFF)

/**
 * @brief Switch to indicate that the notifications are supported
 * @details
 * 1.general and advance timer not support edge select,only support timer overflow interrupt
 * 2.
 */
#define PWM_NOTIFICATION_SUPPORTED (STD_OFF)

/**
 * @brief Switch to indicate that Pwm_GetVersionInfo API is supported
 */
#define PWM_VERSION_INFO_API (STD_OFF)

/**
 * @brief Pre-compile configuration constants
 */
#define PWM_PRECOMPILE_SUPPORT (STD_OFF)

/**
 * @brief Switch to enable that power state mode is supported
 *
 * @note not support
 */
#define PWM_POWER_STATE_SUPPORTED (STD_OFF)

/**
 * @brief Channel Id of the PWM channel. This value will be assigned to the symbolic name derived of the PwmChannel
 * container short name.
 */
#define PwmConf_Channel_0 (0U)
#define PwmConf_Channel_1 (1U)
#define PwmConf_Channel_2 (2U)
#define PwmConf_Channel_3 (3U)
#define PwmConf_Channel_4 (4U)
#define PwmConf_Channel_5 (5U)
#define PwmConf_Channel_6 (6U)
#define PwmConf_Channel_7 (7U)
#define PwmConf_Channel_8 (8U)
#define PwmConf_Channel_9 (9U)
#define PwmConf_Channel_10 (10U)
#define PwmConf_Channel_11 (11U)
#define PwmConf_Channel_12 (12U)
#define PwmConf_Channel_13 (13U)
#define PwmConf_Channel_14 (14U)
#define PwmConf_Channel_15 (15U)
#define PwmConf_Channel_16 (16U)
#define PwmConf_Channel_17 (17U)
#define PwmConf_Channel_18 (18U)
#define PwmConf_Channel_19 (19U)
#define PwmConf_Channel_20 (20U)
#define PwmConf_Channel_21 (21U)
#define PwmConf_Channel_22 (22U)
#define PwmConf_Channel_23 (23U)
#define PwmConf_Channel_24 (24U)

/******************************************************************************
 **                        Typedef Definitions
 ******************************************************************************/

/******************************************************************************
 **                        Export Variables
 ******************************************************************************/

/******************************************************************************
 **                        Export Functions
 ******************************************************************************/

#ifdef __cplusplus
}
#endif

#endif
/* EOF */
