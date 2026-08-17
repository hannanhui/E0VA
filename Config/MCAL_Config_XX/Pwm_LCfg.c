/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Pwm_LCfg.c
 *  @Syntax          : GNU99
 *  @Author          : ChipON AE/FAE Group
 *  @Date            : 2026/4/15 09:39:52
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
#include "Pwm_LCfg.h"

/******************************************************************************
 **                        File Version Check
 ******************************************************************************/

/******************************************************************************
 **                        Macro Definitions
 ******************************************************************************/
/**
 * @brief Number of configured enhance module
 */
#define PWM_ENHANCE_MOD_NUMBER ((uint8)3U)

/**
 * @brief Number of configured advance module
 */
#define PWM_ADVANCE_MOD_NUMBER ((uint8)0U)

/**
 * @brief Number of configured general module
 */
#define PWM_GENERAL_MOD_NUMBER ((uint8)6U)

/**
 * @brief Number of configured Pwm channels
 */
#define PWM_CONF_CHANNELS_NUMBER (25U)

/**
 * @brief module number and channel number config
 */
#define PWM_CONF_CHANNEL_AND_MODULE                                                                                    \
    ((PWM_CONF_CHANNELS_NUMBER << 12U) | (PWM_GENERAL_MOD_NUMBER) << 8U | (PWM_ADVANCE_MOD_NUMBER << 4U) |             \
     PWM_ENHANCE_MOD_NUMBER)

/**
 * @brief channel type and module index config
 */
#define PWM_CHANNEL_TYPE_AND_MODULE_INDEX(ChannelType, ModuleIndex) ((ChannelType << 4U) | ModuleIndex)

/******************************************************************************
 **                        Typedef Definitions
 ******************************************************************************/

/******************************************************************************
 **                        Export Variables
 ******************************************************************************/

/******************************************************************************
 **                        Export Functions
 ******************************************************************************/

/******************************************************************************
 **                        Variables
 ******************************************************************************/
/**
 * @brief Configurations for all Enhance module
 *
 */
static CONST(Pwm_EnhanceModuleConfigType, PWM_CONST) Pwm_EnhanceModuleConfig[PWM_ENHANCE_MOD_NUMBER] = {
  [0U] =
    {
      /* Id value of the configured Enhance module */
      .ModuleId = PWM_MODULE_16,
      /** @brief Timer period value */
      .TimePeriod = 2000U,
      /** @brief Timer prescaler value */
      .TimePrescaler = 1U,
      /** @brief The post-divider ratio */
      .TimePostscaler = 0U,
      /** @brief Up and down counting mode, that is, center-aligned PWM signal */
      .TxUpDownCountMode = PWM_UP_FLAG,
      /** @brief Configure working clock */
      .WorkingClock = PWM_SCLK,
    },
  [1U] =
    {
      /* Id value of the configured Enhance module */
      .ModuleId = PWM_MODULE_13,
      /** @brief Timer period value */
      .TimePeriod = 2000U,
      /** @brief Timer prescaler value */
      .TimePrescaler = 1U,
      /** @brief The post-divider ratio */
      .TimePostscaler = 0U,
      /** @brief Up and down counting mode, that is, center-aligned PWM signal */
      .TxUpDownCountMode = PWM_UP_FLAG,
      /** @brief Configure working clock */
      .WorkingClock = PWM_SCLK,
    },
  [2U] =
    {
      /* Id value of the configured Enhance module */
      .ModuleId = PWM_MODULE_12,
      /** @brief Timer period value */
      .TimePeriod = 2000U,
      /** @brief Timer prescaler value */
      .TimePrescaler = 1U,
      /** @brief The post-divider ratio */
      .TimePostscaler = 0U,
      /** @brief Up and down counting mode, that is, center-aligned PWM signal */
      .TxUpDownCountMode = PWM_UP_FLAG,
      /** @brief Configure working clock */
      .WorkingClock = PWM_SCLK,
    },
};

/**
 * @brief Configurations for all general module
 *
 */
static CONST(Pwm_GeneralModuleConfigType, PWM_CONST) Pwm_GeneralModuleConfig[PWM_GENERAL_MOD_NUMBER] = {
  [0U] =
    {
      /** @brief Id value of the configured general module */
      .ModuleId = PWM_MODULE_1,
      /** @brief Timer period value */
      .TimePeriod = 2000U,
      /** @brief Timer prescaler value */
      .TimePrescaler = 1U,
      /** @brief Up and down counting mode, that is, center-aligned PWM signal */
      .TxUpDownCountMode = PWM_UP_FLAG,
      /** @brief Configure working clock */
      .WorkingClock = PWM_SCLK,
    },
  [1U] =
    {
      /** @brief Id value of the configured general module */
      .ModuleId = PWM_MODULE_2,
      /** @brief Timer period value */
      .TimePeriod = 2000U,
      /** @brief Timer prescaler value */
      .TimePrescaler = 1U,
      /** @brief Up and down counting mode, that is, center-aligned PWM signal */
      .TxUpDownCountMode = PWM_UP_FLAG,
      /** @brief Configure working clock */
      .WorkingClock = PWM_SCLK,
    },
  [2U] =
    {
      /** @brief Id value of the configured general module */
      .ModuleId = PWM_MODULE_3,
      /** @brief Timer period value */
      .TimePeriod = 2000U,
      /** @brief Timer prescaler value */
      .TimePrescaler = 1U,
      /** @brief Up and down counting mode, that is, center-aligned PWM signal */
      .TxUpDownCountMode = PWM_UP_FLAG,
      /** @brief Configure working clock */
      .WorkingClock = PWM_SCLK,
    },
  [3U] =
    {
      /** @brief Id value of the configured general module */
      .ModuleId = PWM_MODULE_4,
      /** @brief Timer period value */
      .TimePeriod = 2000U,
      /** @brief Timer prescaler value */
      .TimePrescaler = 1U,
      /** @brief Up and down counting mode, that is, center-aligned PWM signal */
      .TxUpDownCountMode = PWM_UP_FLAG,
      /** @brief Configure working clock */
      .WorkingClock = PWM_SCLK,
    },
  [4U] =
    {
      /** @brief Id value of the configured general module */
      .ModuleId = PWM_MODULE_20,
      /** @brief Timer period value */
      .TimePeriod = 2000U,
      /** @brief Timer prescaler value */
      .TimePrescaler = 1U,
      /** @brief Up and down counting mode, that is, center-aligned PWM signal */
      .TxUpDownCountMode = PWM_UP_FLAG,
      /** @brief Configure working clock */
      .WorkingClock = PWM_SCLK,
    },
  [5U] =
    {
      /** @brief Id value of the configured general module */
      .ModuleId = PWM_MODULE_21,
      /** @brief Timer period value */
      .TimePeriod = 2000U,
      /** @brief Timer prescaler value */
      .TimePrescaler = 1U,
      /** @brief Up and down counting mode, that is, center-aligned PWM signal */
      .TxUpDownCountMode = PWM_UP_FLAG,
      /** @brief Configure working clock */
      .WorkingClock = PWM_SCLK,
    },
};

/**
 * @brief Pwm channels configuration array
 */
static CONST(Pwm_ChannelConfigType, PWM_CONST) Pwm_ChannelConfig[PWM_CONF_CHANNELS_NUMBER] = {
  [0U] =
    {
      /** @brief Module Index */
      .ModuleLp = PWM_CHANNEL_TYPE_AND_MODULE_INDEX(PWM_GENERAL_CHANNEL, 4U),
      /** @brief channel id */
      .HwChannelId = PWM_CONFIG_CHANNEL_4,
      /** @brief Channel class type: Variable/Fixed period */
      .ChannelClass = PWM_FIXED_PERIOD,
      /** @brief Configure PWM channel output State */
      .ChannelPolarity = PWM_HIGH,
      /** @brief Configure PWM channel Idle State PWM_HIGH or PWM_LOW */
      .IdleStatus = PWM_HIGH,
      /** @brief PWM duty cycle */
      .DefaultDutyCycle = 0x0U,
    },
  [1U] =
    {
      /** @brief Module Index */
      .ModuleLp = PWM_CHANNEL_TYPE_AND_MODULE_INDEX(PWM_GENERAL_CHANNEL, 2U),
      /** @brief channel id */
      .HwChannelId = PWM_CONFIG_CHANNEL_1,
      /** @brief Channel class type: Variable/Fixed period */
      .ChannelClass = PWM_FIXED_PERIOD,
      /** @brief Configure PWM channel output State */
      .ChannelPolarity = PWM_HIGH,
      /** @brief Configure PWM channel Idle State PWM_HIGH or PWM_LOW */
      .IdleStatus = PWM_HIGH,
      /** @brief PWM duty cycle */
      .DefaultDutyCycle = 0x0U,
    },
  [2U] =
    {
      /** @brief Module Index */
      .ModuleLp = PWM_CHANNEL_TYPE_AND_MODULE_INDEX(PWM_GENERAL_CHANNEL, 3U),
      /** @brief channel id */
      .HwChannelId = PWM_CONFIG_CHANNEL_2,
      /** @brief Channel class type: Variable/Fixed period */
      .ChannelClass = PWM_FIXED_PERIOD,
      /** @brief Configure PWM channel output State */
      .ChannelPolarity = PWM_HIGH,
      /** @brief Configure PWM channel Idle State PWM_HIGH or PWM_LOW */
      .IdleStatus = PWM_HIGH,
      /** @brief PWM duty cycle */
      .DefaultDutyCycle = 0x0U,
    },
  [3U] =
    {
      /** @brief Module Index */
      .ModuleLp = PWM_CHANNEL_TYPE_AND_MODULE_INDEX(PWM_GENERAL_CHANNEL, 3U),
      /** @brief channel id */
      .HwChannelId = PWM_CONFIG_CHANNEL_1,
      /** @brief Channel class type: Variable/Fixed period */
      .ChannelClass = PWM_FIXED_PERIOD,
      /** @brief Configure PWM channel output State */
      .ChannelPolarity = PWM_HIGH,
      /** @brief Configure PWM channel Idle State PWM_HIGH or PWM_LOW */
      .IdleStatus = PWM_HIGH,
      /** @brief PWM duty cycle */
      .DefaultDutyCycle = 0x0U,
    },
  [4U] =
    {
      /** @brief Module Index */
      .ModuleLp = PWM_CHANNEL_TYPE_AND_MODULE_INDEX(PWM_GENERAL_CHANNEL, 2U),
      /** @brief channel id */
      .HwChannelId = PWM_CONFIG_CHANNEL_4,
      /** @brief Channel class type: Variable/Fixed period */
      .ChannelClass = PWM_FIXED_PERIOD,
      /** @brief Configure PWM channel output State */
      .ChannelPolarity = PWM_HIGH,
      /** @brief Configure PWM channel Idle State PWM_HIGH or PWM_LOW */
      .IdleStatus = PWM_HIGH,
      /** @brief PWM duty cycle */
      .DefaultDutyCycle = 0x0U,
    },
  [5U] =
    {
      /** @brief Module Index */
      .ModuleLp = PWM_CHANNEL_TYPE_AND_MODULE_INDEX(PWM_GENERAL_CHANNEL, 2U),
      /** @brief channel id */
      .HwChannelId = PWM_CONFIG_CHANNEL_3,
      /** @brief Channel class type: Variable/Fixed period */
      .ChannelClass = PWM_FIXED_PERIOD,
      /** @brief Configure PWM channel output State */
      .ChannelPolarity = PWM_HIGH,
      /** @brief Configure PWM channel Idle State PWM_HIGH or PWM_LOW */
      .IdleStatus = PWM_HIGH,
      /** @brief PWM duty cycle */
      .DefaultDutyCycle = 0x0U,
    },
  [6U] =
    {
      /** @brief Module Index */
      .ModuleLp = PWM_CHANNEL_TYPE_AND_MODULE_INDEX(PWM_ENHANCE_CHANNEL, 0U),
      /** @brief channel id */
      .HwChannelId = PWM_CONFIG_CHANNEL_1,
      /** @brief Channel class type: Variable/Fixed period */
      .ChannelClass = PWM_FIXED_PERIOD,
      /** @brief Configure PWM channel output State */
      .ChannelPolarity = PWM_HIGH,
      /** @brief Configure PWM channel Idle State PWM_HIGH or PWM_LOW */
      .IdleStatus = PWM_HIGH,
      /** @brief PWM duty cycle */
      .DefaultDutyCycle = 0x0U,
    },
  [7U] =
    {
      /** @brief Module Index */
      .ModuleLp = PWM_CHANNEL_TYPE_AND_MODULE_INDEX(PWM_ENHANCE_CHANNEL, 1U),
      /** @brief channel id */
      .HwChannelId = PWM_CONFIG_CHANNEL_2,
      /** @brief Channel class type: Variable/Fixed period */
      .ChannelClass = PWM_FIXED_PERIOD,
      /** @brief Configure PWM channel output State */
      .ChannelPolarity = PWM_HIGH,
      /** @brief Configure PWM channel Idle State PWM_HIGH or PWM_LOW */
      .IdleStatus = PWM_HIGH,
      /** @brief PWM duty cycle */
      .DefaultDutyCycle = 0x0U,
    },
  [8U] =
    {
      /** @brief Module Index */
      .ModuleLp = PWM_CHANNEL_TYPE_AND_MODULE_INDEX(PWM_ENHANCE_CHANNEL, 1U),
      /** @brief channel id */
      .HwChannelId = PWM_CONFIG_CHANNEL_1,
      /** @brief Channel class type: Variable/Fixed period */
      .ChannelClass = PWM_FIXED_PERIOD,
      /** @brief Configure PWM channel output State */
      .ChannelPolarity = PWM_HIGH,
      /** @brief Configure PWM channel Idle State PWM_HIGH or PWM_LOW */
      .IdleStatus = PWM_HIGH,
      /** @brief PWM duty cycle */
      .DefaultDutyCycle = 0x0U,
    },
  [9U] =
    {
      /** @brief Module Index */
      .ModuleLp = PWM_CHANNEL_TYPE_AND_MODULE_INDEX(PWM_ENHANCE_CHANNEL, 2U),
      /** @brief channel id */
      .HwChannelId = PWM_CONFIG_CHANNEL_2,
      /** @brief Channel class type: Variable/Fixed period */
      .ChannelClass = PWM_FIXED_PERIOD,
      /** @brief Configure PWM channel output State */
      .ChannelPolarity = PWM_HIGH,
      /** @brief Configure PWM channel Idle State PWM_HIGH or PWM_LOW */
      .IdleStatus = PWM_HIGH,
      /** @brief PWM duty cycle */
      .DefaultDutyCycle = 0x0U,
    },
  [10U] =
    {
      /** @brief Module Index */
      .ModuleLp = PWM_CHANNEL_TYPE_AND_MODULE_INDEX(PWM_GENERAL_CHANNEL, 5U),
      /** @brief channel id */
      .HwChannelId = PWM_CONFIG_CHANNEL_3,
      /** @brief Channel class type: Variable/Fixed period */
      .ChannelClass = PWM_FIXED_PERIOD,
      /** @brief Configure PWM channel output State */
      .ChannelPolarity = PWM_HIGH,
      /** @brief Configure PWM channel Idle State PWM_HIGH or PWM_LOW */
      .IdleStatus = PWM_HIGH,
      /** @brief PWM duty cycle */
      .DefaultDutyCycle = 0x0U,
    },
  [11U] =
    {
      /** @brief Module Index */
      .ModuleLp = PWM_CHANNEL_TYPE_AND_MODULE_INDEX(PWM_GENERAL_CHANNEL, 5U),
      /** @brief channel id */
      .HwChannelId = PWM_CONFIG_CHANNEL_2,
      /** @brief Channel class type: Variable/Fixed period */
      .ChannelClass = PWM_FIXED_PERIOD,
      /** @brief Configure PWM channel output State */
      .ChannelPolarity = PWM_HIGH,
      /** @brief Configure PWM channel Idle State PWM_HIGH or PWM_LOW */
      .IdleStatus = PWM_HIGH,
      /** @brief PWM duty cycle */
      .DefaultDutyCycle = 0x0U,
    },
  [12U] =
    {
      /** @brief Module Index */
      .ModuleLp = PWM_CHANNEL_TYPE_AND_MODULE_INDEX(PWM_GENERAL_CHANNEL, 5U),
      /** @brief channel id */
      .HwChannelId = PWM_CONFIG_CHANNEL_1,
      /** @brief Channel class type: Variable/Fixed period */
      .ChannelClass = PWM_FIXED_PERIOD,
      /** @brief Configure PWM channel output State */
      .ChannelPolarity = PWM_HIGH,
      /** @brief Configure PWM channel Idle State PWM_HIGH or PWM_LOW */
      .IdleStatus = PWM_HIGH,
      /** @brief PWM duty cycle */
      .DefaultDutyCycle = 0x0U,
    },
  [13U] =
    {
      /** @brief Module Index */
      .ModuleLp = PWM_CHANNEL_TYPE_AND_MODULE_INDEX(PWM_GENERAL_CHANNEL, 1U),
      /** @brief channel id */
      .HwChannelId = PWM_CONFIG_CHANNEL_4,
      /** @brief Channel class type: Variable/Fixed period */
      .ChannelClass = PWM_FIXED_PERIOD,
      /** @brief Configure PWM channel output State */
      .ChannelPolarity = PWM_HIGH,
      /** @brief Configure PWM channel Idle State PWM_HIGH or PWM_LOW */
      .IdleStatus = PWM_HIGH,
      /** @brief PWM duty cycle */
      .DefaultDutyCycle = 0x0U,
    },
  [14U] =
    {
      /** @brief Module Index */
      .ModuleLp = PWM_CHANNEL_TYPE_AND_MODULE_INDEX(PWM_GENERAL_CHANNEL, 1U),
      /** @brief channel id */
      .HwChannelId = PWM_CONFIG_CHANNEL_1,
      /** @brief Channel class type: Variable/Fixed period */
      .ChannelClass = PWM_FIXED_PERIOD,
      /** @brief Configure PWM channel output State */
      .ChannelPolarity = PWM_HIGH,
      /** @brief Configure PWM channel Idle State PWM_HIGH or PWM_LOW */
      .IdleStatus = PWM_HIGH,
      /** @brief PWM duty cycle */
      .DefaultDutyCycle = 0x0U,
    },
  [15U] =
    {
      /** @brief Module Index */
      .ModuleLp = PWM_CHANNEL_TYPE_AND_MODULE_INDEX(PWM_GENERAL_CHANNEL, 5U),
      /** @brief channel id */
      .HwChannelId = PWM_CONFIG_CHANNEL_4,
      /** @brief Channel class type: Variable/Fixed period */
      .ChannelClass = PWM_FIXED_PERIOD,
      /** @brief Configure PWM channel output State */
      .ChannelPolarity = PWM_HIGH,
      /** @brief Configure PWM channel Idle State PWM_HIGH or PWM_LOW */
      .IdleStatus = PWM_HIGH,
      /** @brief PWM duty cycle */
      .DefaultDutyCycle = 0x0U,
    },
  [16U] =
    {
      /** @brief Module Index */
      .ModuleLp = PWM_CHANNEL_TYPE_AND_MODULE_INDEX(PWM_GENERAL_CHANNEL, 3U),
      /** @brief channel id */
      .HwChannelId = PWM_CONFIG_CHANNEL_4,
      /** @brief Channel class type: Variable/Fixed period */
      .ChannelClass = PWM_FIXED_PERIOD,
      /** @brief Configure PWM channel output State */
      .ChannelPolarity = PWM_HIGH,
      /** @brief Configure PWM channel Idle State PWM_HIGH or PWM_LOW */
      .IdleStatus = PWM_HIGH,
      /** @brief PWM duty cycle */
      .DefaultDutyCycle = 0x0U,
    },
  [17U] =
    {
      /** @brief Module Index */
      .ModuleLp = PWM_CHANNEL_TYPE_AND_MODULE_INDEX(PWM_GENERAL_CHANNEL, 3U),
      /** @brief channel id */
      .HwChannelId = PWM_CONFIG_CHANNEL_3,
      /** @brief Channel class type: Variable/Fixed period */
      .ChannelClass = PWM_FIXED_PERIOD,
      /** @brief Configure PWM channel output State */
      .ChannelPolarity = PWM_HIGH,
      /** @brief Configure PWM channel Idle State PWM_HIGH or PWM_LOW */
      .IdleStatus = PWM_HIGH,
      /** @brief PWM duty cycle */
      .DefaultDutyCycle = 0x0U,
    },
  [18U] =
    {
      /** @brief Module Index */
      .ModuleLp = PWM_CHANNEL_TYPE_AND_MODULE_INDEX(PWM_GENERAL_CHANNEL, 0U),
      /** @brief channel id */
      .HwChannelId = PWM_CONFIG_CHANNEL_4,
      /** @brief Channel class type: Variable/Fixed period */
      .ChannelClass = PWM_FIXED_PERIOD,
      /** @brief Configure PWM channel output State */
      .ChannelPolarity = PWM_HIGH,
      /** @brief Configure PWM channel Idle State PWM_HIGH or PWM_LOW */
      .IdleStatus = PWM_HIGH,
      /** @brief PWM duty cycle */
      .DefaultDutyCycle = 0x0U,
    },
  [19U] =
    {
      /** @brief Module Index */
      .ModuleLp = PWM_CHANNEL_TYPE_AND_MODULE_INDEX(PWM_GENERAL_CHANNEL, 4U),
      /** @brief channel id */
      .HwChannelId = PWM_CONFIG_CHANNEL_3,
      /** @brief Channel class type: Variable/Fixed period */
      .ChannelClass = PWM_FIXED_PERIOD,
      /** @brief Configure PWM channel output State */
      .ChannelPolarity = PWM_HIGH,
      /** @brief Configure PWM channel Idle State PWM_HIGH or PWM_LOW */
      .IdleStatus = PWM_HIGH,
      /** @brief PWM duty cycle */
      .DefaultDutyCycle = 0x0U,
    },
  [20U] =
    {
      /** @brief Module Index */
      .ModuleLp = PWM_CHANNEL_TYPE_AND_MODULE_INDEX(PWM_GENERAL_CHANNEL, 0U),
      /** @brief channel id */
      .HwChannelId = PWM_CONFIG_CHANNEL_3,
      /** @brief Channel class type: Variable/Fixed period */
      .ChannelClass = PWM_FIXED_PERIOD,
      /** @brief Configure PWM channel output State */
      .ChannelPolarity = PWM_HIGH,
      /** @brief Configure PWM channel Idle State PWM_HIGH or PWM_LOW */
      .IdleStatus = PWM_HIGH,
      /** @brief PWM duty cycle */
      .DefaultDutyCycle = 0x0U,
    },
  [21U] =
    {
      /** @brief Module Index */
      .ModuleLp = PWM_CHANNEL_TYPE_AND_MODULE_INDEX(PWM_GENERAL_CHANNEL, 0U),
      /** @brief channel id */
      .HwChannelId = PWM_CONFIG_CHANNEL_2,
      /** @brief Channel class type: Variable/Fixed period */
      .ChannelClass = PWM_FIXED_PERIOD,
      /** @brief Configure PWM channel output State */
      .ChannelPolarity = PWM_HIGH,
      /** @brief Configure PWM channel Idle State PWM_HIGH or PWM_LOW */
      .IdleStatus = PWM_HIGH,
      /** @brief PWM duty cycle */
      .DefaultDutyCycle = 0x0U,
    },
  [22U] =
    {
      /** @brief Module Index */
      .ModuleLp = PWM_CHANNEL_TYPE_AND_MODULE_INDEX(PWM_GENERAL_CHANNEL, 1U),
      /** @brief channel id */
      .HwChannelId = PWM_CONFIG_CHANNEL_3,
      /** @brief Channel class type: Variable/Fixed period */
      .ChannelClass = PWM_FIXED_PERIOD,
      /** @brief Configure PWM channel output State */
      .ChannelPolarity = PWM_HIGH,
      /** @brief Configure PWM channel Idle State PWM_HIGH or PWM_LOW */
      .IdleStatus = PWM_HIGH,
      /** @brief PWM duty cycle */
      .DefaultDutyCycle = 0x0U,
    },
  [23U] =
    {
      /** @brief Module Index */
      .ModuleLp = PWM_CHANNEL_TYPE_AND_MODULE_INDEX(PWM_GENERAL_CHANNEL, 1U),
      /** @brief channel id */
      .HwChannelId = PWM_CONFIG_CHANNEL_2,
      /** @brief Channel class type: Variable/Fixed period */
      .ChannelClass = PWM_FIXED_PERIOD,
      /** @brief Configure PWM channel output State */
      .ChannelPolarity = PWM_HIGH,
      /** @brief Configure PWM channel Idle State PWM_HIGH or PWM_LOW */
      .IdleStatus = PWM_HIGH,
      /** @brief PWM duty cycle */
      .DefaultDutyCycle = 0x0U,
    },
  [24U] =
    {
      /** @brief Module Index */
      .ModuleLp = PWM_CHANNEL_TYPE_AND_MODULE_INDEX(PWM_GENERAL_CHANNEL, 4U),
      /** @brief channel id */
      .HwChannelId = PWM_CONFIG_CHANNEL_2,
      /** @brief Channel class type: Variable/Fixed period */
      .ChannelClass = PWM_FIXED_PERIOD,
      /** @brief Configure PWM channel output State */
      .ChannelPolarity = PWM_HIGH,
      /** @brief Configure PWM channel Idle State PWM_HIGH or PWM_LOW */
      .IdleStatus = PWM_HIGH,
      /** @brief PWM duty cycle */
      .DefaultDutyCycle = 0x0U,
    },
};

/**
 * @brief pwm module and channel config
 */
static const Pwm_ModuleAndChannelConfigType Pwm_ModuleAndChannelConfigSet = {
  /** @brief Channel Module Number */
  .NumChannelAndModule = PWM_CONF_CHANNEL_AND_MODULE,
  /** @brief Pointer to array containing IP type and index in the configuration table for each PWM channel */
  .ChannelConfigPtr = &Pwm_ChannelConfig[0U],
  /** @brief Pointer to the structure containing general configuration */
  .GeneralConfigPtr = &Pwm_GeneralModuleConfig[0U],
  /** @brief Pointer to the structure containing Enhance configuration */
  .EnhanceConfigPtr = &Pwm_EnhanceModuleConfig[0U],
};

/**
 * @brief pwm config information
 */
const Pwm_ConfigType Pwm_ConfigPredefined = {
  /** @brief Number of PWM configured channels */
  .NumChannels = PWM_CONF_CHANNELS_NUMBER,
  /** @brief Combined IP specific configuration structure */
  .ModuleAndChannelPtr = &Pwm_ModuleAndChannelConfigSet,
};

/******************************************************************************
 **                        Function definitions
 ******************************************************************************/
