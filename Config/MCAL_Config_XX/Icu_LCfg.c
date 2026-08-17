/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Icu_LCfg.c
 *  @Syntax             : GNU99
 *  @Author             : ChipON AE/FAE Group
 *  @Date            : 2021-12-23
 *  @Version         : {{VersionDate}}
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
#include "Icu_LCfg.h"

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
 **                      Private Function Declarations
 ******************************************************************************/
static FUNC(void, ICU_CALLOUT_CODE) Icu_Notification_0(void);
/******************************************************************************
 **                        Variable Declarations
 ******************************************************************************/
/**
 * @brief Pwm channels IP related configuration array
 */
static CONST(Icu_ChannelConfigType, ICU_VAR) Icu_ChannelConfig[] = {
  [0U] =
    {
      .HwUnitIndex          = 0U,
      .PhysicalChannelIndex = ICU_MODULECHANNEL_1,
      .WakeupCapable        = 0U,
      .DefaultEdge          = ICU_RISING_EDGE,
#if (ICU_WAKEUP_FUNCTIONALITY_API == STD_ON)
      .WakeupValue = 0U,
#endif
      .MeasurementMode = ICU_MODE_SIGNAL_MEASUREMENT,
      .SignalProperty  = ICU_DUTY_CYCLE,
      .NotifyFcn       = &Icu_Notification_0,
    },
  [1U] = {
    .HwUnitIndex          = 1U,
    .PhysicalChannelIndex = ICU_MODULECHANNEL_4,
    .WakeupCapable        = 0U,
    .DefaultEdge          = ICU_RISING_EDGE,
#if (ICU_WAKEUP_FUNCTIONALITY_API == STD_ON)
    .WakeupValue = 0U,
#endif
    .MeasurementMode = ICU_MODE_EDGE_COUNTER,
    .SignalProperty  = ICU_LOW_TIME,
    .NotifyFcn       = NULL_PTR,
  }};

/**
 * @brief User's hardware Configurations
 */
static CONST(Icu_ImUnitConfigType, ICU_VAR) Icu_Base_ModuleConfig[] = {
  [0U] =
    {
      .HwModuleType     = 0U,
      .HwModule         = ICU_MODULE_4,
      .ClockSource      = CCP_HFCLK,
      .Prescaler        = 16000U,
      .MaxPeriodCounter = 0xFFFFU,
    },
  [1U] = {
    .HwModuleType     = 0U,
    .HwModule         = ICU_MODULE_21,
    .ClockSource      = CCP_HFCLK,
    .Prescaler        = 16U,
    .MaxPeriodCounter = 0xFFFFU,
  }};

/**
 * @brief User's ICU Configurations
 */
CONST(Icu_ConfigType, ICU_VAR)
Icu_ConfigPredefined = {
  .NumChannels        = sizeof(Icu_ChannelConfig) / sizeof(Icu_ChannelConfigType),
  .ChannelConfigArray = &Icu_ChannelConfig[0U],
  .NumHwUnits         = sizeof(Icu_Base_ModuleConfig) / sizeof(Icu_ImUnitConfigType),
  .HwUnitConfigArray  = &Icu_Base_ModuleConfig[0U],
};
/******************************************************************************
 **                        Export Variables
 ******************************************************************************/

/******************************************************************************
 **                        Export Functions
 ******************************************************************************/

/******************************************************************************
 **                      Function definitions
 ******************************************************************************/
static FUNC(void, ICU_CALLOUT_CODE) Icu_Notification_0(void)
{
    ;
}
/* EOF */
