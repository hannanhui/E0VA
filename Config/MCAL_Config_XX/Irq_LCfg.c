/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Irq_LCfg.c
 *  @Syntax          : GNU99
 *  @Author          : ChipON AE/FAE Group
 *  @Date            : 2026/3/20 10:59:48
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
 *                        Include Files
 *****************************************************************************/
#include "Irq_LCfg.h"

/******************************************************************************
 *                        Constant
 ******************************************************************************/

const Irq_ConfigType Irq_ConfigPredefined = {
  .PriorityGroup = IRQ_INTR_PREEMP_3,
  /** @brief WWDT irq priority config */
  .WWDT_Priority = {0U, 0U},
  /** @brief PD irq priority config */
  .PD_Priority = {0U, 0U},
  /** @brief CanFd6MB15TO0 irq priority config */
  .CanFd6MB15TO0_Priority = {0U, 0U},
  /** @brief CanFd6MB31TO16 irq priority config */
  .CanFd6MB31TO16_Priority = {0U, 0U},
  /** @brief CanFd6MB47TO32 irq priority config */
  .CanFd6MB47TO32_Priority = {0U, 0U},
  /** @brief CanFd6MB63TO48 irq priority config */
  .CanFd6MB63TO48_Priority = {0U, 0U},
  /** @brief Timer14 irq priority config */
  .Timer14_Priority = {0U, 0U},
  /** @brief Adc0 irq priority config */
  .Adc0_Priority = {0U, 0U},
  /** @brief CanFd6BusErr irq priority config */
  .CanFd6BusErr_Priority = {0U, 0U},
  /** @brief Timer0 irq priority config */
  .Timer0_Priority = {0U, 0U},
  /** @brief Dma0 irq priority config */
  .Dma0_Priority = {0U, 0U},
  /** @brief Usart0 irq priority config */
  .Usart0_Priority = {0U, 0U},
  /** @brief Usart1 irq priority config */
  .Usart1_Priority = {0U, 0U},
  /** @brief Dma1 irq priority config */
  .Dma1_Priority = {0U, 0U},
  /** @brief CanFd6Gen irq priority config */
  .CanFd6Gen_Priority = {0U, 0U},
};
