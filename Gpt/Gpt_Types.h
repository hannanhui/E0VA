/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Gpt_Types.h
 *  @Syntax          : GNU99
 *  @Author          : ChipON AE/FAE Group
 *  @Date            : 2025-08-29
 *  @Version         : V1.0.0_SF
 *  @Description     : This document describes the C language document template.
 ******************************************************************************
 *  Copyright (C) by Shanghai ChipON Micro-Electronic Co.,Ltd
 *  All rights reserved.
 *
 *  This software is copyright protected and proprietary to
 *  Shanghai ChipON Micro-Electronic Co.,Ltd.
 ******************************************************************************
 *                        REVISION HISTORY
 ******************************************************************************
 *  |Date        |Version  |Author       |Description
 ******************************************************************************
 *  |2025-08-29  |V1.0     |Wang Ning    |New creat
 *****************************************************************************/
#ifndef GPT_TYPES_H
#define GPT_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 **                        MISRA-C Rules Violations
 ******************************************************************************/
/**
 * @page misra_violations MISRA-C:2004 violations
 *
 * @section
 */

/******************************************************************************
 **                        QAC Warnings Suppression
 ******************************************************************************/
/**
 * @page QAC Warnings
 *
 */
/******************************************************************************
 **                        Include Files
 ******************************************************************************/
#include "Std_Types.h"
#include "Gpt_Cfg.h"
/******************************************************************************
 **                        File Version Check
 ******************************************************************************/

/******************************************************************************
 **                        Macro  Definitions
 ******************************************************************************/

/******************************************************************************
 **                        Typedef  Definitions
 ******************************************************************************/
/**
 * @brief Gpt Channel Timer Clock Source
 *
 */
typedef enum
{
    GPT_SCLK,
    GPT_HFCLK,
} Gpt_ClkSourceType;

/**
 * @brief channel id
 *
 */
typedef enum
{
    GPT_GPTIMER_CHAN_T0,
    GPT_GPTIMER_CHAN_T1,
    GPT_GPTIMER_CHAN_T2,
    GPT_GPTIMER_CHAN_T3,
    GPT_GPTIMER_CHAN_T4,
    GPT_GPTIMER_CHAN_T20,
    GPT_GPTIMER_CHAN_T21,
} Gpt_TimerEnumType;

/**
 * @brief This enumerated type allows the selection of channel status type.
 *
 * @implements Timer Channel Status #SWS_Gpt_00210,
 * #SWS_Gpt_00211,#SWS_Gpt_00344
 */
typedef enum
{
    GPT_CHANNEL_UNINITIALIZED, /**< @brief GPT channel status - uninitialized */
    GPT_CHANNEL_INITIALIZED,   /**< @brief GPT channel status - initialized */
    GPT_CHANNEL_STOPPED,       /**< @brief GPT channel status - stopped */
    GPT_CHANNEL_EXPIRED,       /**< @brief GPT channel status - expired */
    GPT_CHANNEL_RUNNING        /**< @brief GPT channel status - running */
} Gpt_ChannelStatusType;

typedef enum
{
    GPT_MODE_CONTINUOUS,
    GPT_MODE_ONE_SHOT
} Gpt_ChannelModeType;

/**
 * @brief Gpt channel notification type.  The callback notifications shall be
 * configurable as pointers to user defined functions within the configuration
 * structure.
 *
 * @implements #SWS_GPT_00292
 */
typedef void (*Gpt_NotificationFcnType)(void);
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
