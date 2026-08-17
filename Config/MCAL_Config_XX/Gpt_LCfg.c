/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Gpt_LCfg.c
 *  @Syntax             : GNU99
 *  @Author             : ChipON AE/FAE Group
 *  @Date            : 2026/3/10 13:22:24
 *  @Version         : V1.0
 *  @Description     : This document describes the C language document template.
 ******************************************************************************
 *  Copyright (C) by Shanghai ChipON Micro-Electronic Co.,Ltd
 *  All rights reserved.
 *
 *  This software is copyright protected and proprietary to
 *  Shanghai ChipON Micro-Electronic Co.,Ltd.
 *****************************************************************************/

/******************************************************************************
 **                        Include Files
 ******************************************************************************/
#include "Gpt_LCfg.h"

/******************************************************************************
 **                        File Version Check
 ******************************************************************************/

/******************************************************************************
 **                        Macro  Definitions
 ******************************************************************************/

/******************************************************************************
 **                        Typedef  Definitions
 ******************************************************************************/

/******************************************************************************
 **                         Variables
 ******************************************************************************/
extern void SystemTickIf_Irq_Handler(void);

/**
 * @brief Gpt channel config information
 */
static const Gpt_ChannelConfigType g_channel_configs[1U] = {
  [0U] = {
	 /** @brief Specify individual hardware channel index num */
	.ChanHwIndex = (Gpt_TimerEnumType)GPT_GPTIMER_CHAN_T0,
	  /** @brief Specifies the behavior of the timer channel after the target time
	 * is reached. */
	.ChanMode = GPT_MODE_CONTINUOUS, 
	/** @brief Hardware Type of Gpt channel, Current is GPTimer */
	.ChanHwType = 0U,
	/** @brief Maximum value in ticks, the timer channel is able to count. With the next tick, the timer rolls over to
     * zero */
	.ChanTickValueMax = 0xFFFFU,
	 /** @brief Channel Clock Source */
	.ClkSrc = GPT_SCLK,
	/** @brief timer channel prescale */
	.Prescale = (uint16)12000U,
	/** @brief enable channel wakeup */
	.EnableWakeUp = FALSE,
	 /** @brief callback function */
    .NotifyFcn = &SystemTickIf_Irq_Handler
  }
};

/**
 * @brief Gpt Predefined Timer Configuration Type
 *
 */
static const Gpt_PredefTimeConfigType predef_config = {
	/** @brief Clock source */
	.ClockSource = GPT_SCLK,
	/**
	 * 1.T21 is a 32-bit timer, You can use GPT_PREDEF_TIMER_1US_16BIT, GPT_PREDEF_TIMER_1US_24BIT,
	 * GPT_PREDEF_TIMER_1US_32BIT, GPT_PREDEF_TIMER_100US_32BIT, and GPt_predef_timer_100us_32bit. If you configure
	 * other timers, you can only use GPT_PREDEF_TIMER_1US_16BIT
	 * 2.After selecting the clock source and frequency division, one count represents 1us
	 */
	.PredefHwChannel = GPT_GPTIMER_CHAN_T0,
	/** @brief prescaler value*/
	.Prescaler = (uint16)120U
};

const Gpt_ConfigType Gpt_ConfigPredefined= {
  /** @brief Total Timer Count */
  .ChannelCount = 1U,
  /** @brief Pointer to Channel Config Array */
  .ChannelConfigPtr = g_channel_configs,
  /** @brief Pointer to Predef Timer Config  */
  .PredefTimeConfig = &predef_config
};

/******************************************************************************
 **                        Export Variables
 ******************************************************************************/

/******************************************************************************
 **                        Export Functions
 ******************************************************************************/

/* EOF */
