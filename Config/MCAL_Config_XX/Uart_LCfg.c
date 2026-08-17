/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Uart_LCfg.c
 *  @Syntax             : GNU99
 *  @Author             : ChipON AE/FAE Group
 *  @Date            : 2024-06-20
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
#include "Uart_LCfg.h"

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
 **                      Variables
 ******************************************************************************/
static const Uart_DmaSourceConfigType Uart_DmaConfig0 = {
  .ReceiveDmaSwitch = UART_DMA_ENABLE,
  .SendDmaSwitch    = UART_DMA_ENABLE,
  .TxDmaSource      = UART_DMA1_CHANNEL_1,
  .RxDmaSource      = UART_DMA1_CHANNEL_2,
};

static const Uart_DmaSourceConfigType Uart_DmaConfig1 = {
  .ReceiveDmaSwitch = UART_DMA_ENABLE,
  .SendDmaSwitch    = UART_DMA_ENABLE,
  .TxDmaSource      = UART_DMA1_CHANNEL_3,
  .RxDmaSource      = UART_DMA1_CHANNEL_4,
};

/**
 * @brief uart channel config information
 */
static const Uart_ChannelConfigType Uart_ChannelConfig[2U] = {
  {
    .Module = UART_MODULE_0,
    /** @brief clock source */
    .BaudRateClkSrc = UART_CLOCK_SCLK,
    /** @brief BaudRate = 115200 */
    /** @brief BRGM */
    .BaudRateInteger = 0x41U,
    /** @brief BRGF1 */
    .BaudRateNumerator = 0U,
    /** @brief BRGF2 */
    .BaudRateDenominator     = 1U,
    .StopBit                 = UART_STOP_BIT_1,
    .ParityMode              = UART_PARITY_NONE,
    .ReceiveOrder            = UART_LSB_FIRST,
    .SendOrder               = UART_LSB_FIRST,
    .TxSelect                = UART_TX0,
    .DmaConfigPtr            = &Uart_DmaConfig0,
    .ReceiveCompleteCallback = NULL_PTR,
    .SendCompleteCallback    = NULL_PTR,
  },
  {
    .Module = UART_MODULE_1,
    /** @brief clock source */
    .BaudRateClkSrc = UART_CLOCK_SCLK,
    /** @brief BaudRate = 115200 */
    /** @brief BRGM */
    .BaudRateInteger = 0x41U,
    /** @brief BRGF1 */
    .BaudRateNumerator = 0U,
    /** @brief BRGF2 */
    .BaudRateDenominator     = 1U,
    .StopBit                 = UART_STOP_BIT_1,
    .ParityMode              = UART_PARITY_NONE,
    .ReceiveOrder            = UART_LSB_FIRST,
    .SendOrder               = UART_LSB_FIRST,
    .TxSelect                = UART_TX0,
    .DmaConfigPtr            = &Uart_DmaConfig1,
    .ReceiveCompleteCallback = NULL_PTR,
    .SendCompleteCallback    = NULL_PTR,
  },
};

/**
 * @brief Uart config information
 */
const Uart_ConfigType Uart_ConfigPredefined = {
  /** @brief UART number */
  .UartChannelNum = 2U,
  /** @brief UART configuration */
  .UartChannelConfigPtr = Uart_ChannelConfig};
/******************************************************************************
 **                        Export Variables
 ******************************************************************************/

/******************************************************************************
 **                        Export Functions
 ******************************************************************************/

/* EOF */
