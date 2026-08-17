/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Lin_LCfg.c
 *  @Syntax          : GNU99
 *  @Author          : ChipON AE/FAE Group
 *  @Date            : 2026/3/12 17:27:53
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
#include "Lin_LCfg.h"

/******************************************************************************
 **                        File Version Check
 ******************************************************************************/

/******************************************************************************
 **                        Macro Definitions
 ******************************************************************************/
/**
 * @brief None EcuMWakeUpSource was referred when
 * LinChannelWakeupSupport is disable
 */
#define LIN_NONE_ECUM_WAKEUP_SOURCE_REF ((uint32)0U)

/******************************************************************************
 **                        Typedef Definitions
 ******************************************************************************/

/******************************************************************************
 **                        Export Functions
 ******************************************************************************/
extern void LinIf_TxConfirmation(NetworkHandleType Channel);
extern void LinIf_RxIndication(NetworkHandleType Channel, uint8 *Lin_SduPtr);
extern Std_ReturnType LinIf_HeaderIndication(NetworkHandleType Channel, Lin_PduType *PduPtr);

/*******************************************************************************
 **                        Global Variable Definitions
 *******************************************************************************/
/**
 * @brief Lin dma source config
 */
static const Lin_DmaSourceConfigType Lin_DmaConfigUsart0 = {
  .ReceiveDmaSwitch = LIN_DMA_ENABLE,
  .SendDmaSwitch    = LIN_DMA_ENABLE,
  .TxDmaSource      = LIN_DMA1_CHANNEL_1,
  .RxDmaSource      = LIN_DMA1_CHANNEL_2,
};
/**
 * @brief Lin dma source config
 */
static const Lin_DmaSourceConfigType Lin_DmaConfigUsart1 = {
  .ReceiveDmaSwitch = LIN_DMA_ENABLE,
  .SendDmaSwitch    = LIN_DMA_ENABLE,
  .TxDmaSource      = LIN_DMA1_CHANNEL_3,
  .RxDmaSource      = LIN_DMA1_CHANNEL_4,
};

/**
 * @brief Lin channel config information
 */
static Lin_ChannelCfgType ChannelCfg[LIN_IM_MODULES] = {
  [0U] =
    {
      /** @brief LIN Hardware Module */
      .HwModule = LIN_MODULE_USART0,
      /** @brief LIN Channel Mode */
      .ChannelMode = LIN_CHANNEL_SLAVE_MODE,
      /*baudrate clock source select */
      .ClockSelect = LIN_CLOCK_SCLK,
      /** @brief Is wake-up supported by the LIN channel */
      .ChannelWakeupSupport = (uint8)STD_OFF,
      /** @brief This parameter contains a reference to the Wakeup Source for
       * this controller as defined in the ECU State Manager.*/
      .ChannelEcuMWakeupSource = (EcuM_WakeupSourceType)LIN_NONE_ECUM_WAKEUP_SOURCE_REF,
      /** @brief baud integer*/
      .BaudInteger = 390U,
      /** @brief baudrate numerator */
      .BaudNumerator = 0U,
      /** @brief baudrate denominator */
      .BaudDenom = 1U,
      /** @brief lin dma source config */
      .DmaConfigPtr = &Lin_DmaConfigUsart0,
    },
  [1U] =
    {
      /** @brief LIN Hardware Module */
      .HwModule = LIN_MODULE_USART1,
      /** @brief LIN Channel Mode */
      .ChannelMode = LIN_CHANNEL_MASTER_MODE,
      /*baudrate clock source select */
      .ClockSelect = LIN_CLOCK_SCLK,
      /** @brief Is wake-up supported by the LIN channel */
      .ChannelWakeupSupport = (uint8)STD_OFF,
      /** @brief This parameter contains a reference to the Wakeup Source for
       * this controller as defined in the ECU State Manager.*/
      .ChannelEcuMWakeupSource = (EcuM_WakeupSourceType)LIN_NONE_ECUM_WAKEUP_SOURCE_REF,
      /** @brief baud integer*/
      .BaudInteger = 390U,
      /** @brief baudrate numerator */
      .BaudNumerator = 0U,
      /** @brief baudrate denominator */
      .BaudDenom = 1U,
      /** @brief lin dma source config */
      .DmaConfigPtr = &Lin_DmaConfigUsart1,
    },
};

/**
 * @brief Lin config information
 */
const Lin_ConfigType Lin_ConfigPredefined = {
  /*all lin module number*/
  .ChannelNum = sizeof(ChannelCfg) / sizeof(Lin_ChannelCfgType),
  /*Configuration for Lin Channel*/
  .ChannelPtr = &ChannelCfg[0U],
  /** @brief Tx confirmation callback */
  .TxConfirmationCallback = &LinIf_TxConfirmation,
  /** @brief rx indication callback */
  .RxIndicationCallback = &LinIf_RxIndication,
  /** @brief receive a frame header callback */
  .HeaderIndicationCallback = &LinIf_HeaderIndication,
};

/******************************************************************************
 **                        Export Variables
 ******************************************************************************/

/******************************************************************************
 **                        Export Functions
 ******************************************************************************/

/* EOF */
