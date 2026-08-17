/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Wdg_LCfg.c
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

/******************************************************************************
 *                      Include Files
 ******************************************************************************/
#include "Wdg_LCfg.h"

/******************************************************************************
 *                      Macro Definitions
 ******************************************************************************/

/******************************************************************************
 *                      Constants
 ******************************************************************************/

/******************************************************************************
 *                      Type definitions
 ******************************************************************************/

/******************************************************************************
 *                      Variables
 ******************************************************************************/


/* Wdg Configurations */
const Wdg_ConfigType Wdg_ConfigPredefined = {
  /* GPT Configuration for WDG */
  .GptConf =
    {
      /* GPT timer module */
      .GptModuleForService = GPT_GPTIMER_CHAN_T14,
      /* Fast mode, timer timeout, in milliseconds */
      .FastServiceGptCbkTime = 50U,
      /* Slow mode, timer timeout, in milliseconds */
      .SlowServiceGptCbkTime = 200U,
      /* GPT Prescaler */
      .Prescaler = 8000U,
    },
  /* WDG clock source */
  .WdgClkSource = WDG_CLK_INTLF,
  /* WDG prescale */
  .WdgPrescale = WDG_DIVISION_32,
  /* WDG overflow value */
  .WdgOverflowValue = (uint16)250U,
  /* Fast mode, watchdog timeout,2s */
  .FastModeWdgReloadValue = (uint16)1000U,
  /* Slow mode, watchdog timeout,4s */
  .SlowModeWdgReloadValue = (uint16)3000U,
  /* work mode */
  .WorkMode = WDGIF_SLOW_MODE,
};

/******************************************************************************
 *                      Function definitions                                   *
 ******************************************************************************/
