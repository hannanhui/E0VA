/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Mcu_LCfg.c
 *  @Syntax          : GNU99
 *  @Author          : ChipON AE/FAE Group
 *  @Date            : 2026/5/7 18:12:46
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
 *                      Include Files                                          *
 ******************************************************************************/
#include "Mcu_LCfg.h"

/******************************************************************************
 *                      Macro Implementation                                   *
 ******************************************************************************/
#define PCLK_CTRL0_VALUE                                                                                               \
    ((uint32)((0U) | (GPIOAPCLKEN << 0U) | (GPIOBPCLKEN << 1U) | (GPIOCPCLKEN << 2U) | (GPIODPCLKEN << 3U) |           \
              (GPIOEPCLKEN << 4U) | (GPIOFPCLKEN << 5U) | (GPIOGPCLKEN << 6U) | (GPIOHPCLKEN << 7U)))

#define PCLK_CTRL1_VALUE                                                                                               \
    (uint32)(                                                                                                          \
      (0U) | (T1PCLKEN << 2U) | (T2PCLKEN << 3U) | (T3PCLKEN << 4U) | (T4PCLKEN << 5U) | (T5T6PCLKEN << 6U) |          \
      (T9T10PCLKEN << 8U) | (ADC0PCLKEN << 11U) | (ADC1PCLKEN << 12U) | (CMPPCLKEN << 16U) | (T0PCLKEN << 17U) |       \
      (USART0PCLKEN << 19U) | (USART1PCLKEN << 20U) | (USART2PCLKEN << 21U) | (USART3PCLKEN << 22U) |                  \
      (USART6PCLKEN << 23U) | (SPI0PCLKEN << 24U) | (SPI1PCLKEN << 25U) | (I2C0PCLKEN << 26U) | (I2C1PCLKEN << 27U) |  \
      (I2C2PCLKEN << 28U) | (MPUPCLKEN << 30U))

#define PCLK_CTRL2_VALUE                                                                                               \
    (uint32)(                                                                                                          \
      (0U) | (ISMUTESTPCLKEN << 4U) | (WWDTPCLKEN << 5U) | (EPWM11PCLKEN << 8U) | (EPWM12PCLKEN << 9U) |               \
      (EPWM13PCLKEN << 10U) | (EPWM16PCLKEN << 11U) | (DMA0PCLKEN << 12U) | (AES1PCLKEN << 13U) |                      \
      (DMA1PCLKEN << 14U) | (ECC18PCLKEN << 15U) | (T14PCLKEN << 16U) | (ECC17PCLKEN << 18U) | (ECC16PCLKEN << 19U) |  \
      (T20PCLKEN << 23U) | (T21PCLKEN << 24U) | (STOPWATCHTICKPCLKEN << 25U))

#define PCLK_CTRL3_VALUE                                                                                               \
    (uint32)((0U) | (SPI2PCLKEN << 1U) | (CMUPCLKEN << 12U) | (CRCPCLKEN << 13U) | (AESPCLKEN << 14U) |                \
             (FLEXRMPCLKEN << 25U) | (EWDTPCLKEN << 27U) | (RNGPCLKEN << 28U) | (CANFD6PCLKEN << 29U) |                \
             (CANFD7PCLKEN << 30U) | (ECC15PCLKEN << 31U))

#define PCLK_CTRL4_VALUE                                                                                               \
    (uint32)(                                                                                                          \
      (CANFD8PCLKEN << 0U) | (CANFD9PCLKEN << 1U) | (SHAPCLKEN << 2U) | (RSAPCLKEN << 3U) | (ECC4PCLKEN << 10U) |      \
      (ECC5PCLKEN << 11U) | (ECC13PCLKEN << 19U) | (ECC0PCLKEN << 20U) | (ECC1PCLKEN << 21U) | (ECC19PCLKEN << 24U) |  \
      (ECC20PCLKEN << 25U) | (EPWM31PCLKEN << 26U) | (EPWM32PCLKEN << 27U) | (EPWM33PCLKEN << 28U) |                   \
      (EPWM36PCLKEN << 29U))

/******************************************************************************
 *                      Constant                                               *
 ******************************************************************************/
/**
 * @brief wake up pin configuration
 */
static const Mcu_WakeupPinConfig Standby_WakeupPinConfig1[3U] = {
  [0U] = {
    .WakeupIndex       = MCU_WKUP3,
    .WakeupEdge        = MCU_WAKEUP_EDGE_FALL,
    .WakeupFixLvEnable = TRUE,
  },
  [1U] = {
    .WakeupIndex       = MCU_WKUP6,
    .WakeupEdge        = MCU_WAKEUP_EDGE_FALL,
    .WakeupFixLvEnable = TRUE,
  },
  [2U] = {
    .WakeupIndex       = MCU_WKUP10,
    .WakeupEdge        = MCU_WAKEUP_EDGE_FALL,
    .WakeupFixLvEnable = TRUE,
  },
};

/**
 * @brief wake up configuration
 */
static const Mcu_WakeupConfig Standby_WakeupConfig1 = {
  .WakeupPinConfig = (Mcu_WakeupPinConfig *)Standby_WakeupPinConfig1,
  .WakeupNumber    = (sizeof(Standby_WakeupPinConfig1) / sizeof(Mcu_WakeupPinConfig)),
};

/**
 * @brief Initialization mcu pmc register.
 * @details Static configuration realized by calling Mcu_Init() API.
 *
 */
static const Mcu_PowerConfigType Mcu_PmcConfigData[MCU_MAX_SUPPORTED_MODE] = {
  [0U] =
    {
      /** @brief normal\standby\stop0 */
      .Mcu_SleepType = MCU_SLEEP_NORMAL,
    },
  [1U] =
    {
      /** @brief EN state of WKUP pin wake up MCU */
      .Mcu_PinWkupEnableSta = FALSE,
      /** @brief WKUP pin index */ 
      .Mcu_WkupConfig = (Mcu_WakeupConfig *)&Standby_WakeupConfig1,
      /** @brief normal\standby\stop0 */
      .Mcu_SleepType = MCU_SLEEP_STANDBY,
    },
};

/**
 * @brief Initialization mcu Cache register.
 * @details Static configuration realized by calling Mcu_Init() API.
 *
 */
static const Mcu_SystemConfigType Mcu_SystemConfigData = {
  .EnableCache        = STD_OFF,
  .EnableRamEcc       = STD_OFF,
  .EnableCacheEccIntr = STD_OFF,
  .EnableFlashEccIntr = STD_OFF,
  .EnableRamEccIntr   = STD_OFF,
};

/**
 * @brief Initialization clock data.
 * @details Static configuration realized by calling Mcu_InitClock() API.
 *
 */
static const Mcu_ClockConfigType Mcu_ClockConfigData[MCU_MAX_CLOCKCONFIGS] = {
  [0U] =
    {
      .InnerLFConfig =
        {
          .AllowIntr = STD_OFF,
          .Delay     = 0U,
          .Enabled   = STD_ON,
        },
      .InnerHFConfig =
        {
          .AllowIntr = STD_OFF,
          .Delay     = 0U,
          .Enabled   = STD_OFF,
        },
      .OuterLFConfig =
        {
          .AllowIntr = STD_OFF,
          .Delay     = 0U,
          .Enabled   = STD_OFF,
        },
      .OuterHFConfig =
        {
          .AllowIntr = STD_OFF,
          .Delay     = 8U,
          .Enabled   = STD_ON,
        },
      .SclkConfig =
        {
          .ClockSource = SCLK_SOURCE_PLL,
          .Division    = SCLK_DIVISION_1,
        },
      .LSPclkConfig =
        {
          .ClockSource = LFCLK_INPUT_INTLF,
          .Division    = 0U,
          .Enabled     = STD_OFF,
        },
      .HSPclkConfig =
        {
          .ClockSource = HFCLK_SOURCE_EXTHF,
          .Division    = 0U,
          .Enabled     = STD_ON,
        },
      .PllConfig =
        {
          /* clock source */
          .ClockSource   = PLL_SOURCE_EXTHF,
          .IsClockDivBy2 = (boolean)FALSE,
          .Control =
            {
              .M  = 30U,
              .N  = 1U,
              .OD = 1U,
            },
          /** @brief delay clock */
          .Delay = 8U,
        },
      .PclkEnConfig =
        {
          .PclkCtrlGroup_0 = (uint32)PCLK_CTRL0_VALUE,
          .PclkCtrlGroup_1 = (uint32)PCLK_CTRL1_VALUE,
          .PclkCtrlGroup_2 = (uint32)PCLK_CTRL2_VALUE,
          .PclkCtrlGroup_3 = (uint32)PCLK_CTRL3_VALUE,
          .PclkCtrlGroup_4 = (uint32)PCLK_CTRL4_VALUE,
        },
    },
};

/**
 * @brief Initialization data for different hw IPs.
 * @details Static configuration realized at startup by calling Mcu_Init()
 * API.
 *
 */
static const Mcu_HwConfigType Mcu_HwConfig = {
  /* Configuration for PMC. */
  .PMConfig = &Mcu_PmcConfigData[0U],
  /*Configuration for CACHE . */
  .SMConfig = &Mcu_SystemConfigData,
};

/**
 * @brief Initialization data for the MCU driver.
 * @details A pointer to such a structure is provided to the MCU
 * initialization routines for configuration.
 *
 */
const Mcu_ConfigType Mcu_ConfigPredefined = {
  .ClkSrcFailureNotification = MCU_CLK_NOTIF_DISABLE,
  /* Number of RAM Sections configurations. */
  .NumOfRamConfigs = (uint8)0U,
  /* Number of Clock Setting configurations. */
  .NumOfClkConfigs = (uint8)1U,
  /* ram data configuration */
  .RamConfigPtr = NULL_PTR,
  /* Pointer to Clock configurations. */
  .ClockConfigPtr = &Mcu_ClockConfigData,
  /* Pointer to Low Level Mcu driver configuration. */
  .HwConfigPtr = &Mcu_HwConfig,
};
