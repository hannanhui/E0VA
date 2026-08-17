/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Port_LCfg.c
 *  @Syntax          : GNU99
 *  @Author          : ChipON AE/FAE Group

 *  @Date            : 2026/4/7 17:23:15
 *  @Version         : V1.0
 *  @Description     : This document describes the C language document template.
 ******************************************************************************
 *  Copyright (C) by Shanghai ChipON Micro-Electronic Co.,Ltd
 *  All rights reserved.
 *
 *  This software is copyright protected and proprietary to
 *  Shanghai ChipON Micro-Electronic Co.,Ltd.
 ******************************************************************************/

/******************************************************************************
 **                        Include Files
 ******************************************************************************/
/**
 * @implements #SWS_Port_00205
 * Port_Lcfg.c shall include Port_MemMap.h and Port.h
 */
#include "Port_LCfg.h"

/******************************************************************************
 **                        File Version Check
 ******************************************************************************/

/******************************************************************************
 **                        Macro Definitions
 ******************************************************************************/

/******************************************************************************
 **                        Typedef Definitions
 ******************************************************************************/

/******************************************************************************
 **                        Export Variables
 ******************************************************************************/
/**
 * @brief all port pins config
 * @details
 */
static const Port_PinConfigType Port_PinInitArr0[85U] = {
  [0U] =
    {
      .PortBase    = GPIO_PORT_A,
      .PinIndex    = GPIO_PIN_0,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF8, MODE_RMP, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [1U] =
    {
      .PortBase    = GPIO_PORT_A,
      .PinIndex    = GPIO_PIN_1,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF8, MODE_RMP, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [2U] =
    {
      .PortBase    = GPIO_PORT_A,
      .PinIndex    = GPIO_PIN_2,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF8, MODE_RMP, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [3U] =
    {
      .PortBase    = GPIO_PORT_A,
      .PinIndex    = GPIO_PIN_3,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF8, MODE_RMP, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [4U] =
    {
      .PortBase    = GPIO_PORT_A,
      .PinIndex    = GPIO_PIN_4,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF2, MODE_RMP, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [5U] =
    {
      .PortBase    = GPIO_PORT_A,
      .PinIndex    = GPIO_PIN_5,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF0, MODE_GPIO_OUT, STD_LOW, PULL_UP, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [6U] =
    {
      .PortBase    = GPIO_PORT_A,
      .PinIndex    = GPIO_PIN_6,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF0, MODE_GPIO_OUT, STD_LOW, PULL_UP, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [7U] =
    {
      .PortBase    = GPIO_PORT_A,
      .PinIndex    = GPIO_PIN_7,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF2, MODE_RMP, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [8U] =
    {
      .PortBase    = GPIO_PORT_A,
      .PinIndex    = GPIO_PIN_8,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF0, MODE_GPIO_OUT, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [9U] =
    {
      .PortBase    = GPIO_PORT_A,
      .PinIndex    = GPIO_PIN_9,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF0, MODE_GPIO_IN, STD_HIGH, PULL_UP, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [10U] =
    {
      .PortBase    = GPIO_PORT_A,
      .PinIndex    = GPIO_PIN_11,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF2, MODE_RMP, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [11U] =
    {
      .PortBase    = GPIO_PORT_A,
      .PinIndex    = GPIO_PIN_13,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF0, MODE_GPIO_OUT, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [12U] =
    {
      .PortBase    = GPIO_PORT_B,
      .PinIndex    = GPIO_PIN_0,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF2, MODE_RMP, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [13U] =
    {
      .PortBase    = GPIO_PORT_B,
      .PinIndex    = GPIO_PIN_1,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF0, MODE_AN, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [14U] =
    {
      .PortBase    = GPIO_PORT_B,
      .PinIndex    = GPIO_PIN_3,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF6, MODE_RMP, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [15U] =
    {
      .PortBase    = GPIO_PORT_B,
      .PinIndex    = GPIO_PIN_4,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF6, MODE_RMP, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [16U] =
    {
      .PortBase    = GPIO_PORT_B,
      .PinIndex    = GPIO_PIN_6,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF3, MODE_RMP, STD_LOW, PULL_UP, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [17U] =
    {
      .PortBase    = GPIO_PORT_B,
      .PinIndex    = GPIO_PIN_8,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF0, MODE_AN, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [18U] =
    {
      .PortBase    = GPIO_PORT_B,
      .PinIndex    = GPIO_PIN_10,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF0, MODE_GPIO_OUT, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [19U] =
    {
      .PortBase    = GPIO_PORT_B,
      .PinIndex    = GPIO_PIN_13,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF0, MODE_GPIO_IN, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [20U] =
    {
      .PortBase    = GPIO_PORT_B,
      .PinIndex    = GPIO_PIN_14,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF0, MODE_GPIO_OUT, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [21U] =
    {
      .PortBase    = GPIO_PORT_B,
      .PinIndex    = GPIO_PIN_15,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF0, MODE_GPIO_OUT, STD_LOW, PULL_DOWN, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [22U] =
    {
      .PortBase    = GPIO_PORT_C,
      .PinIndex    = GPIO_PIN_0,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF0, MODE_AN, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [23U] =
    {
      .PortBase    = GPIO_PORT_C,
      .PinIndex    = GPIO_PIN_2,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF0, MODE_AN, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [24U] =
    {
      .PortBase    = GPIO_PORT_C,
      .PinIndex    = GPIO_PIN_5,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF0, MODE_AN, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [25U] =
    {
      .PortBase    = GPIO_PORT_C,
      .PinIndex    = GPIO_PIN_6,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF2, MODE_RMP, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [26U] =
    {
      .PortBase    = GPIO_PORT_C,
      .PinIndex    = GPIO_PIN_10,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF2, MODE_RMP, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [27U] =
    {
      .PortBase    = GPIO_PORT_C,
      .PinIndex    = GPIO_PIN_11,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF2, MODE_RMP, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [28U] =
    {
      .PortBase    = GPIO_PORT_C,
      .PinIndex    = GPIO_PIN_12,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF9, MODE_RMP, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [29U] =
    {
      .PortBase    = GPIO_PORT_C,
      .PinIndex    = GPIO_PIN_13,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF9, MODE_RMP, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [30U] =
    {
      .PortBase    = GPIO_PORT_C,
      .PinIndex    = GPIO_PIN_14,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF9, MODE_RMP, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [31U] =
    {
      .PortBase    = GPIO_PORT_C,
      .PinIndex    = GPIO_PIN_15,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF0, MODE_AN, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [32U] =
    {
      .PortBase    = GPIO_PORT_D,
      .PinIndex    = GPIO_PIN_2,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF0, MODE_AN, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [33U] =
    {
      .PortBase    = GPIO_PORT_D,
      .PinIndex    = GPIO_PIN_3,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF0, MODE_AN, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [34U] =
    {
      .PortBase    = GPIO_PORT_D,
      .PinIndex    = GPIO_PIN_4,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF0, MODE_GPIO_IN, STD_LOW, PULL_UP, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [35U] =
    {
      .PortBase    = GPIO_PORT_D,
      .PinIndex    = GPIO_PIN_5,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF0, MODE_AN, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [36U] =
    {
      .PortBase    = GPIO_PORT_D,
      .PinIndex    = GPIO_PIN_6,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF2, MODE_RMP, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [37U] =
    {
      .PortBase    = GPIO_PORT_D,
      .PinIndex    = GPIO_PIN_7,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF2, MODE_RMP, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [38U] =
    {
      .PortBase    = GPIO_PORT_D,
      .PinIndex    = GPIO_PIN_8,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF0, MODE_AN, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [39U] =
    {
      .PortBase    = GPIO_PORT_D,
      .PinIndex    = GPIO_PIN_12,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF0, MODE_GPIO_OUT, STD_LOW, PULL_UP, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [40U] =
    {
      .PortBase    = GPIO_PORT_D,
      .PinIndex    = GPIO_PIN_13,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF0, MODE_GPIO_IN, STD_LOW, PULL_UP, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [41U] =
    {
      .PortBase    = GPIO_PORT_D,
      .PinIndex    = GPIO_PIN_14,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF0, MODE_AN, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [42U] =
    {
      .PortBase    = GPIO_PORT_D,
      .PinIndex    = GPIO_PIN_15,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF0, MODE_AN, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [43U] =
    {
      .PortBase    = GPIO_PORT_E,
      .PinIndex    = GPIO_PIN_0,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF9, MODE_RMP, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [44U] =
    {
      .PortBase    = GPIO_PORT_E,
      .PinIndex    = GPIO_PIN_2,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF2, MODE_RMP, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [45U] =
    {
      .PortBase    = GPIO_PORT_E,
      .PinIndex    = GPIO_PIN_3,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF2, MODE_RMP, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [46U] =
    {
      .PortBase    = GPIO_PORT_E,
      .PinIndex    = GPIO_PIN_6,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF0, MODE_GPIO_OUT, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [47U] =
    {
      .PortBase    = GPIO_PORT_E,
      .PinIndex    = GPIO_PIN_7,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF0, MODE_GPIO_OUT, STD_LOW, PULL_UP, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [48U] =
    {
      .PortBase    = GPIO_PORT_E,
      .PinIndex    = GPIO_PIN_8,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF0, MODE_GPIO_OUT, STD_LOW, PULL_UP, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [49U] =
    {
      .PortBase    = GPIO_PORT_E,
      .PinIndex    = GPIO_PIN_9,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF0, MODE_GPIO_OUT, STD_LOW, PULL_UP, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [50U] =
    {
      .PortBase    = GPIO_PORT_E,
      .PinIndex    = GPIO_PIN_10,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF0, MODE_GPIO_OUT, STD_LOW, PULL_UP, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [51U] =
    {
      .PortBase    = GPIO_PORT_E,
      .PinIndex    = GPIO_PIN_11,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF9, MODE_RMP, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [52U] =
    {
      .PortBase    = GPIO_PORT_E,
      .PinIndex    = GPIO_PIN_12,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF9, MODE_RMP, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [53U] =
    {
      .PortBase    = GPIO_PORT_E,
      .PinIndex    = GPIO_PIN_13,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF9, MODE_RMP, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [54U] =
    {
      .PortBase    = GPIO_PORT_F,
      .PinIndex    = GPIO_PIN_0,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF0, MODE_GPIO_OUT, STD_LOW, PULL_DOWN, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [55U] =
    {
      .PortBase    = GPIO_PORT_F,
      .PinIndex    = GPIO_PIN_1,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF0, MODE_GPIO_OUT, STD_LOW, PULL_DOWN, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [56U] =
    {
      .PortBase    = GPIO_PORT_F,
      .PinIndex    = GPIO_PIN_2,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF0, MODE_GPIO_OUT, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [57U] =
    {
      .PortBase    = GPIO_PORT_F,
      .PinIndex    = GPIO_PIN_3,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF0, MODE_AN, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [58U] =
    {
      .PortBase    = GPIO_PORT_F,
      .PinIndex    = GPIO_PIN_5,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF0, MODE_AN, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [59U] =
    {
      .PortBase    = GPIO_PORT_F,
      .PinIndex    = GPIO_PIN_6,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF0, MODE_AN, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [60U] =
    {
      .PortBase    = GPIO_PORT_F,
      .PinIndex    = GPIO_PIN_7,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF3, MODE_RMP, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [61U] =
    {
      .PortBase    = GPIO_PORT_F,
      .PinIndex    = GPIO_PIN_8,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF0, MODE_GPIO_OUT, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [62U] =
    {
      .PortBase    = GPIO_PORT_F,
      .PinIndex    = GPIO_PIN_10,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF3, MODE_RMP, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [63U] =
    {
      .PortBase    = GPIO_PORT_F,
      .PinIndex    = GPIO_PIN_11,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF0, MODE_GPIO_OUT, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [64U] =
    {
      .PortBase    = GPIO_PORT_F,
      .PinIndex    = GPIO_PIN_12,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF3, MODE_RMP, STD_LOW, PULL_UP, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [65U] =
    {
      .PortBase    = GPIO_PORT_F,
      .PinIndex    = GPIO_PIN_14,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF0, MODE_AN, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [66U] =
    {
      .PortBase    = GPIO_PORT_F,
      .PinIndex    = GPIO_PIN_15,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF0, MODE_AN, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [67U] =
    {
      .PortBase    = GPIO_PORT_G,
      .PinIndex    = GPIO_PIN_0,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF0, MODE_AN, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [68U] =
    {
      .PortBase    = GPIO_PORT_G,
      .PinIndex    = GPIO_PIN_2,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF0, MODE_AN, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [69U] =
    {
      .PortBase    = GPIO_PORT_G,
      .PinIndex    = GPIO_PIN_4,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF0, MODE_GPIO_OUT, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [70U] =
    {
      .PortBase    = GPIO_PORT_G,
      .PinIndex    = GPIO_PIN_8,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF2, MODE_RMP, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [71U] =
    {
      .PortBase    = GPIO_PORT_G,
      .PinIndex    = GPIO_PIN_9,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF0, MODE_AN, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [72U] =
    {
      .PortBase    = GPIO_PORT_G,
      .PinIndex    = GPIO_PIN_10,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF0, MODE_AN, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [73U] =
    {
      .PortBase    = GPIO_PORT_G,
      .PinIndex    = GPIO_PIN_11,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF0, MODE_AN, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [74U] =
    {
      .PortBase    = GPIO_PORT_G,
      .PinIndex    = GPIO_PIN_12,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF0, MODE_AN, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [75U] =
    {
      .PortBase    = GPIO_PORT_G,
      .PinIndex    = GPIO_PIN_13,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF0, MODE_AN, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [76U] =
    {
      .PortBase    = GPIO_PORT_G,
      .PinIndex    = GPIO_PIN_14,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF0, MODE_AN, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [77U] =
    {
      .PortBase    = GPIO_PORT_G,
      .PinIndex    = GPIO_PIN_15,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF0, MODE_AN, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [78U] =
    {
      .PortBase    = GPIO_PORT_H,
      .PinIndex    = GPIO_PIN_1,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF0, MODE_GPIO_OUT, STD_LOW, PULL_UP, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [79U] =
    {
      .PortBase    = GPIO_PORT_H,
      .PinIndex    = GPIO_PIN_3,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF0, MODE_GPIO_OUT, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [80U] =
    {
      .PortBase    = GPIO_PORT_H,
      .PinIndex    = GPIO_PIN_4,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF0, MODE_GPIO_OUT, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [81U] =
    {
      .PortBase    = GPIO_PORT_H,
      .PinIndex    = GPIO_PIN_6,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF0, MODE_GPIO_OUT, STD_LOW, PULL_UP, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [82U] =
    {
      .PortBase    = GPIO_PORT_H,
      .PinIndex    = GPIO_PIN_8,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF2, MODE_RMP, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [83U] =
    {
      .PortBase    = GPIO_PORT_H,
      .PinIndex    = GPIO_PIN_9,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF2, MODE_RMP, STD_LOW, PULL_NONE, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
  [84U] =
    {
      .PortBase    = GPIO_PORT_H,
      .PinIndex    = GPIO_PIN_14,
      .PinsControl = PORT_CFG_MACRO(GPIO_REMAP_AF0, MODE_GPIO_OUT, STD_LOW, PULL_UP, POD_PP, SLEWR_LS),
      .IsPinsModeChangeable = MODE_NOT_CHANGEABLE,
      .IsDirChangeable = DIR_NOT_CHANGEABLE,
    },
};

/**
 * @brief This table contains the Configured Port Pin parameters
 */
/* PRQA S 0702 1 #KQR000702 */
const Port_ConfigType Port_ConfigPredefined = {
  /** @brief Number of Configs */
  .NumConfig = 85U,
  /** @brief Pin Config Pointer */
  .PortPinConfigPtr = &Port_PinInitArr0[0U],
};

/******************************************************************************
 **                        Export Functions
 ******************************************************************************/
