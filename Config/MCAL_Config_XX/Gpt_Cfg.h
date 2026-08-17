/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Gpt_Cfg.h
 *  @Syntax             : GNU99
 *  @Author             : ChipON AE/FAE Group
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
#ifndef GPT_CFG_H
#define GPT_CFG_H

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
 **                        Macro  Definitions
 ******************************************************************************/
/**
 * @brief Switches the development error detection and notification on or off
 * true: detection and notification is enabled.
 * false: detection and notification is disabled.
 *
 * @implements #SWS_Gpt_00332,#ECUC_Gpt_00321
 */
#define GPT_DEV_ERROR_DETECT (STD_OFF)

/**
 * @brief Enable or disable GPT_PRECOMPILE_SUPPORT
 */
#define GPT_PRECOMPILE_SUPPORT (STD_OFF)

/**
 * @brief Adds / removes the services Gpt_EnableNotification() and Gpt_DisableNotification from the code.
 *
 * @implements #SWS_Gpt_00199,#SWS_Gpt_00200,#ECUC_Gpt_00315
 */
#define GPT_ENABLE_DISABLE_NOTIFICATION_API (STD_ON)

/**
 * @brief Enables/Disables wakeup source reporting.
 *
 * @implements #SWS_Gpt_00255,#ECUC_Gpt_00322
 */
#define GPT_REPORT_WAKEUP_SOURCE (STD_OFF)

/**
 * @brief Adds / removes the services Gpt_SetMode(), Gpt_EnableWakeup() Gpt_DisableWakeup() and Gpt_CheckWakeup() from
 * the code.
 *
 * @implements #SWS_Gpt_00201,#ECUC_Gpt_00320
 */
#define GPT_WAKEUP_FUNCTIONALITY_API (STD_OFF)

/**
 * @brief Adds / removes the service Gpt_GetVersionInfo() from the code.
 *
 * @implements #ECUC_Gpt_00319
 */
#define GPT_VERSION_INFO_API (STD_OFF)

/**
 * @brief Adds / removes the service Gpt_DeInit() from the code.
 *
 * @implements #SWS_Gpt_00194,#ECUC_Gpt_00314
 */
#define GPT_DEINIT_API (STD_ON)

/**
 * @brief Enable or disable GPT_PREDEFTIMER_FUNCTIONALITY_API
 */
#define GPT_PREDEFTIMER_FUNCTIONALITY_API (STD_ON)

/**
 * @brief Adds / removes the service Gpt_GetTimeRemaining() from the code.
 *
 * @implements #SWS_Gpt_00196,#ECUC_Gpt_00318
 */
#define GPT_TIME_REMAINING_API (STD_OFF)

/**
 * @brief Adds / removes the service Gpt_GetTimeElapsed() from the code
 *
 * @implements #SWS_Gpt_00195,#ECUC_Gpt_00317
 */
#define GPT_TIME_ELAPSED_API (STD_ON)
/******************************************************************************
 **                        Typedef  Definitions
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
