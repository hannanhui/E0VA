/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Spi_LCfg.c
 *  @Syntax          : GNU99
 *  @Author          : ChipON AE/FAE Group
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
#include "Spi_LCfg.h"

/******************************************************************************
 **                        Macro Definitions
 ******************************************************************************/

/******************************************************************************
 **                        Master Config Information
 ******************************************************************************/

/**
 * @brief channel config information
 */
static Spi_ChannelConfigType Spi_ChannelConfig[1U] = {
  [0U] =
    {
      .BufferType           = SPI_BUFFER_EB,
      .DataWidth            = 8U,
      .BitOrder             = SPI_BIT_MSB,
      .DefaultTransmitValue = 0xAAU,
      .Length               = 32U,
      .BufferDescriptor =
        &(Spi_BufferDescriptorType){
          .BufferTX = NULL_PTR,
          .BufferRX = NULL_PTR,
        },
    },
};

/**
 * @brief job config information
 */
static const Spi_JobConfigType Spi_JobConfig[1U] = {
  [0U] =
    {
      .NumChannels        = 1U,
      .ChannelIndexList   = (Spi_ChannelType[]){0U},
      .JobEndNotification = NULL_PTR,
      .Priority           = 0U,
      .HwUnit             = (Spi_HWUnitType)SPI_HW_UNIT_1,
      .ExtDeviceConfig =
        &(Spi_ExternalDeviceConfigType){
          .BaudRatePrescaler = 14U,
          .ClkMode           = SPI_CPOL_0_CPHA_0,
          .CsSelection       = SPI_CSS_VIA_GPIO,
          .CsPin             = SPI_CS_PIN_SS0,
          .DisableCSFcn      = NULL_PTR,
          .EnableCSFcn       = NULL_PTR,
        },
    },
};

/**
 * @brief sequence config information
 */
static const Spi_SequenceConfigType Spi_SeqConfig[1U] = {
  [0U] =
    {
      .Interruptable      = FALSE,
      .JobIndexList       = (Spi_JobType[]){0U},
      .NumJobs            = 1,
      .SeqEndNotification = NULL_PTR,
    },
};

/**
 * @brief Spi master config information
 */
const Spi_ConfigType Spi_ConfigPredefined = {
  .NumOfChannel   = 1U,
  .NumOfJob       = 1U,
  .NumOfSequence  = 1U,
  .ChannelConfig  = Spi_ChannelConfig,
  .JobConfig      = Spi_JobConfig,
  .SequenceConfig = Spi_SeqConfig,
  .NumOfHwUnit    = 1U,
  .HwUnitConfig =
    (Spi_HwUnitConfigType[]){
      [0U].HwUnitID   = SPI_HW_UNIT_1,
      [0U].HwClkSrc   = SPI_HW_SCLK,
      [0U].HwClkDiv   = SPI_CLK_DIV_4,
      [0U].HwLineMode = SPI_LINE_MODE_DIRECT,
      [0U].DmaConfig =
        {
          .RxPriority  = 1U,
          .TxPriority  = 1U,
          .RxDmaSource = SPI_DMA0_CHANNEL_4,
          .TxDmaSource = SPI_DMA0_CHANNEL_3,
        },
    },
};

/******************************************************************************
 **                        Slave Config Information
 ******************************************************************************/
