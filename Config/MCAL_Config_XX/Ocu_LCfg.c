/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Ocu_LCfg.c
 *  @Syntax             : GNU99
 *  @Author             : ChipON AE/FAE Group
 *  @Date            : 2022-09-15
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
/** @implements #SWS_Ocu_00007 */
#include "Ocu_LCfg.h"

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
 **                        Export Variables
 ******************************************************************************/

/******************************************************************************
 **                        Export Functions
 ******************************************************************************/
/**
 * @brief User's hardware Configurations
 */
static CONST(Ocu_ImConfigType, OCU_VAR) Ocu_HwUnitConfigs[OCU_USER_CFG_HARDWARE_NUM] = {
  [0U] = {.ModuleInstance = OCU_MODULE_20, .ClockSource = OCU_TXCLOCK_HFCLK, .Prescale = 16000U, .MaxCounter = 1000U},
  [1U] = {.ModuleInstance = OCU_MODULE_4, .ClockSource = OCU_TXCLOCK_HFCLK, .Prescale = 16U, .MaxCounter = 0xFFFFU}};

/**
 * @brief User's notification function example
 */
FUNC(void, OCU_CODE) Func_1(void) {}

/**
 * @brief User's notification function example
 */
FUNC(void, OCU_CODE) Func_2(void) {}

/**
 * @brief User's channel Configurations
 */
static CONST(Ocu_ChannelConfigType, OCU_VAR) Ocu_ChannelConfigs[OCU_USER_CFG_CHANNEL_NUM] = {
  [0U] =
    {/** @brief Module unit configuration index number */
     .ModuleIndex       = 0U,
     .AssignedHwChannel = OCU_CHANNEL3_CFG_INDEX,
     .OutputPinEnabled  = TRUE,
     .DefaultThreshold  = 50U,
     .PinAction         = OCU_TOGGLE,
     .NotifyFcn         = &Func_1},
  [1U] = {
    /** @brief Module unit configuration index number */
    .ModuleIndex       = 1U,
    .AssignedHwChannel = OCU_CHANNEL1_CFG_INDEX,
    .OutputPinEnabled  = TRUE,
    .DefaultThreshold  = 50U,
    .PinAction         = OCU_TOGGLE,
    .NotifyFcn         = &Func_2}};

/**
 * @brief User's Ocu Configurations
 */
CONST(Ocu_ConfigType, OCU_VAR)
Ocu_ConfigPredefined = {
  .NumChannel       = sizeof(Ocu_ChannelConfigs) / sizeof(Ocu_ChannelConfigType),
  .ChannelConfigPtr = &Ocu_ChannelConfigs[0U],
  .NumHwUnit        = sizeof(Ocu_HwUnitConfigs) / sizeof(Ocu_ImConfigType),
  .HwUnitConfigPtr  = &Ocu_HwUnitConfigs[0U],
  .CountDirection   = OCU_UP_COUNTING};
/* EOF */
