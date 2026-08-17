/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Wdg_Cfg.h
 *  @Syntax          : GNU99
 *  @Author          : ChipON AE/FAE Group
 *  @Date            : 2026/3/26 10:58:41
 *  @Version         : V1.0
 *  @Description     : This document describes the C language document template.
 ******************************************************************************
 *  Copyright (C) by Shanghai ChipON Micro-Electronic Co.,Ltd
 *  All rights reserved.
 *
 *  This software is copyright protected and proprietary to
 *  Shanghai ChipON Micro-Electronic Co.,Ltd.
 *****************************************************************************/
#ifndef WDG_CFG_H
#define WDG_CFG_H

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
 * @brief Compile switch to allow / forbid disabling the watchdog driver during
 * runtime.
 * True: Disabling the watchdog driver at runtime is allowed.
 * False: Disabling the watchdog driver at runtime is not allowed.
 * @implements #EcuC_Wdg_00116
 */
#define WDG_DISABLE_ALLOWED (STD_ON)

/**
 * @brief Switches the development error detection and notification on or off
 * true: detection and notification is enabled
 * false: detection and notification is disabled
 * @implements #EcuC_Wdg_00115
 */
#define WDG_DEV_ERROR_DETECT (STD_OFF)

/**
 * @brief Specifies the InstanceId of this module instance. If only one instance is present it shall have the Id 0.
 */
#define WDG_INDEX (0U)

/**
 * @brief The initial timeout (sec) for the trigger condition to be initialized during Init function. It shall be not
 * larger than WdgMaxTimeout
 */
#define WDG_INITIAL_TIMEOUT (1U)

/**
 * @brief The maximum timeout (sec) to which the watchdog trigger condition can be initialized.
 */
#define WDG_MAX_TIMEOUT (1U)

/**
 * @brief Represents the watchdog driver execution area is either from ROM(Flash) or RAM as required with the particular
 * microcontroller.
 */
#define WDG_RUN_ON_ROM (STD_ON)

/**
 * @brief Compile switch to enable / disable the version information API
 * True: API enabled
 * False: API disabled
 * @implements #EcuC_Wdg_00119
 */
#define WDG_VERSION_INFO_API (STD_ON)

/**
 * @brief Fixed address configuration
 */
#define WDG_PB_FIXED_ADDRESS (STD_OFF)

/**
 * @brief Switches the Production Error Detection and Notification OFF
 */
#define WDG_DISABLE_DEM_REPORT_ERROR_STATUS (STD_ON)

/******************************************************************************
 **                        Hardware Configuration Parameters
 ******************************************************************************/
/**
 * @brief Use the base timer T14 as the feed timer for the dog
 */
#define GPT_GPTIMER_CHAN_T14 ((uint8)0U)

/**
 * @brief  Max Reload Value for IWDT
 */
#define WDG_MAX_RELOAD ((uint16)0xFFFU)

/******************************************************************************
 **                        User Configuration Parameters
 ******************************************************************************/

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
