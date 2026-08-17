/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Mcu_Cfg.h
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
#ifndef MCU_CFG_H
#define MCU_CFG_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 **                        Include Files
 ******************************************************************************/
#include "Std_Types.h"

/******************************************************************************
 **                        File Version Check
 ******************************************************************************/

/******************************************************************************
 **                        Macro Definitions
 ******************************************************************************/
/**
 * @brief Frequency of MCU clock source
 */
#define MCU_CFG_CLK_SRC_FREQ_8M  (8U)
#define MCU_CFG_CLK_SRC_FREQ_16M (16U)
#define MCU_CFG_CLK_SRC_FREQ_20M (20U)
#define MCU_CFG_CLK_SRC_FREQ_24M (24U)
#define MCU_CFG_CLK_SRC_FREQ_32M (32U)
#define MCU_CFG_CLK_SRC_FREQ_40M (40U)

/** @brief Select frequency of clock */
#define MCU_CFG_CLK_FREQ (MCU_CFG_CLK_SRC_FREQ_8M)

/** @brief Frequency of SCLK*/
#define MCU_CFG_SYSCLK_FREQ (120U)

/**
 * @brief Internal RefVol value
 */
#define MCU_REF_VOLTAGE_4V      ((uint8)0U)
#define MCU_REF_VOLTAGE_3V      ((uint8)1U)
#define MCU_REF_VOLTAGE_2V      ((uint8)2U)
#define MCU_REF_VOLTAGE_1P5V    ((uint8)3U)
#define MCU_REF_VOLTAGE_NOT_USE ((uint8)4U)

/**
 * @brief internal reference voltage
 */
#define MCU_CFG_INTERNAL_REF_VOLTAGE (MCU_REF_VOLTAGE_NOT_USE)

/**
 * @brief Normal Sleep,Standby. This is a Fixed value as to specific chip.
 *
 */
#define MCU_MAX_SUPPORTED_MODE (2U)

/**
 * @brief Pre-processor switch for enabling the development error
 * detection and reporting to the DET. The detection of development errors is
 * configurable (ON / OFF) at pre-compile time.
 *
 * @implements #ECUC_Mcu_00166
 */
#define MCU_DEV_ERROR_DETECT (STD_OFF)

/**
 * @brief Pre-processor switch to enable/disable the API to read out
 * the modules version information.
 *
 * @implements #ECUC_Mcu_00168
 */
#define MCU_VERSION_INFO_API (STD_OFF)

/**
 * @brief Pre-processor switch to enable/disable the API Mcu_GetRamState.
 * @details Not Supported
 *
 * @implements #SWS_Mcu_00209
 */
#define MCU_GET_RAM_STATE_API (STD_OFF)

/**
 * @brief If this parameter is set to FALSE, the clock initialization
 * has to be disabled from the MCU driver.
 *
 * @implements #SWS_Mcu_00210
 */
#define MCU_INIT_CLOCK (STD_ON)

/**
 * @brief This parameter shall be set True, if the H/W does not have
 * a PLL or the PLL circuitry is enabled after the power on without S/W
 * intervention.
 *
 * @implements #SWS_Mcu_00205
 */
#define MCU_NO_PLL (STD_OFF)

/**
 * @brief The function Mcu_PerformReset is only available if the
 * runtime parameter McuPerformResetApi is set to TRUE.
 *
 * @implements #SWS_Mcu_00146
 */
#define MCU_PERFORM_RESET_API (STD_ON)

/**
 * @brief Maximum number of MCU Clock configurations.
 */
#define MCU_MAX_CLOCKCONFIGS ((uint32)1U)

/**
 * @brief Maximum number of MCU Ram configurations.
 */
#define MCU_MAX_RAMCONFIGS ((uint32)0U)

/**
 * @brief Pre-compile Support.
 */
#define MCU_PRECOMPILE_SUPPORT (STD_OFF)

/**
 * @brief Enable/Disable Internal Low Frequency Oscillator in Low-Power Mode
 *
 * @note If internal low-frequency oscillator is used in low-power mode, this macro should be switched to  STD_ON
 * @ref Page 86
 */
#define MCU_INNER_LOW_FREQ_IN_LOW_POWER_MODE (STD_OFF)

/**
 * @brief Enable/Disable Internal High Frequency Oscillator in Low-Power Mode
 *
 * @ref Page 609
 */
#define MCU_INNER_HIGH_FREQ_IN_LOW_POWER_MODE (STD_OFF)

/**
 * @brief Enable/Disable External Low Frequency Oscillator in Low-Power Mode
 *
 * @note If external low-frequency oscillator is used in low-power mode, this macro should be switched to  STD_ON
 */
#define MCU_OUTER_LOW_FREQ_IN_LOW_POWER_MODE (STD_OFF)

/**
 * @brief Retain or not retain LPRAM data in Low-Power Mode
 */
#define MCU_KEEP_LPRAM_STATE_IN_STANDBY (STD_OFF)

/**
 * @brief Pre-processor switch to enable/disable the API Mcu_LatchIO
 */
#define MCU_IO_LATCH_STATE_IN_STANDBY (STD_OFF)

/**
 * @brief Clock Output Function complete macro definition
 * @details Need config CLKOUT pin
 */
#define MCU_CLOCK_OUTPUT_FUNCTION (STD_OFF)

/**
 * @brief This is Flash Module predefined value. Recommended is 0xC5 running at 120MHz.
 * It is affected by Clock frequency and other things when CPU access flash holding for certain clock cycles
 *
 */
#define MCU_FLASH_CFG_PREDEF_VALUE (0xC5U)

/**
 * @brief Enable Safety Startup procedure. when enabled, WatchDog will set up before Mcu Init. Ready Flags will not wait
 * for timeout. Once Init process is stuck, watchdog will restart the Init Process.
 * TODO implement this requirement
 *
 */
#define MCU_ENABLE_SAFETY_STARTUP (STD_OFF)

/* Peripheral Module Enabled */
#define GPIOAPCLKEN ((uint32)1U)
#define GPIOBPCLKEN ((uint32)1U)
#define GPIOCPCLKEN ((uint32)1U)
#define GPIODPCLKEN ((uint32)1U)
#define GPIOEPCLKEN ((uint32)1U)
#define GPIOFPCLKEN ((uint32)1U)
#define GPIOGPCLKEN ((uint32)1U)
#define GPIOHPCLKEN ((uint32)1U)

#define T1PCLKEN     ((uint32)1U)
#define T2PCLKEN     ((uint32)1U)
#define T3PCLKEN     ((uint32)1U)
#define T4PCLKEN     ((uint32)1U)
#define T5T6PCLKEN   ((uint32)1U)
#define T9T10PCLKEN  ((uint32)1U)
#define ADC0PCLKEN   ((uint32)1U)
#define ADC1PCLKEN   ((uint32)1U)
#define CMPPCLKEN    ((uint32)1U)
#define T0PCLKEN     ((uint32)1U)
#define USART0PCLKEN ((uint32)1U)
#define USART1PCLKEN ((uint32)1U)
#define USART2PCLKEN ((uint32)1U)
#define USART3PCLKEN ((uint32)1U)
#define USART6PCLKEN ((uint32)1U)
#define SPI0PCLKEN   ((uint32)1U)
#define SPI1PCLKEN   ((uint32)1U)
#define I2C0PCLKEN   ((uint32)1U)
#define I2C1PCLKEN   ((uint32)1U)
#define I2C2PCLKEN   ((uint32)1U)
#define MPUPCLKEN    ((uint32)1U)

#define ISMUTESTPCLKEN      ((uint32)1U)
#define WWDTPCLKEN          ((uint32)1U)
#define EPWM11PCLKEN        ((uint32)1U)
#define EPWM12PCLKEN        ((uint32)1U)
#define EPWM13PCLKEN        ((uint32)1U)
#define EPWM16PCLKEN        ((uint32)1U)
#define DMA0PCLKEN          ((uint32)1U)
#define AES1PCLKEN          ((uint32)1U)
#define DMA1PCLKEN          ((uint32)1U)
#define ECC18PCLKEN         ((uint32)1U)
#define T14PCLKEN           ((uint32)1U)
#define ECC17PCLKEN         ((uint32)1U)
#define ECC16PCLKEN         ((uint32)1U)
#define T20PCLKEN           ((uint32)1U)
#define T21PCLKEN           ((uint32)1U)
#define STOPWATCHTICKPCLKEN ((uint32)1U)

#define SPI2PCLKEN   ((uint32)1U)
#define CMUPCLKEN    ((uint32)1U)
#define CRCPCLKEN    ((uint32)1U)
#define AESPCLKEN    ((uint32)1U)
#define FLEXRMPCLKEN ((uint32)1U)
#define EWDTPCLKEN   ((uint32)1U)
#define RNGPCLKEN    ((uint32)1U)
#define CANFD6PCLKEN ((uint32)1U)
#define CANFD7PCLKEN ((uint32)1U)
#define ECC15PCLKEN  ((uint32)1U)

#define CANFD8PCLKEN ((uint32)1U)
#define CANFD9PCLKEN ((uint32)1U)
#define SHAPCLKEN    ((uint32)1U)
#define RSAPCLKEN    ((uint32)1U)
#define ECC4PCLKEN   ((uint32)1U)
#define ECC5PCLKEN   ((uint32)1U)
#define ECC13PCLKEN  ((uint32)1U)
#define ECC0PCLKEN   ((uint32)1U)
#define ECC1PCLKEN   ((uint32)1U)
#define ECC19PCLKEN  ((uint32)1U)
#define ECC20PCLKEN  ((uint32)1U)
#define EPWM31PCLKEN ((uint32)1U)
#define EPWM32PCLKEN ((uint32)1U)
#define EPWM33PCLKEN ((uint32)1U)
#define EPWM36PCLKEN ((uint32)1U)

/**
 * @brief Times of PVD detect vdd higher than 2.9V.
 */
#define PVD_DETECT_VDD_TIMES ((uint32)30U)

/**
 * @brief Time for waiting vdd higher than 2.9V, in us.
 */
#define WAIT_VDD_TIME ((uint32)1000U)

/**
 * @brief Mcu config Clock Id
 */
#define MCU_CLOCK_SETTING_ID_0 (0U)

/**
 * @brief Enable FSCM or not
 */
#define MCU_FEATURE_FSCM_ENABLE (STD_ON)

/**
 * @brief STOP0 mode: Flash sleep enabled
 */
#define MCU_FEATURE_KEEP_FLASH_IN_STOP0_ENABLE (STD_OFF)


/******************************************************************************
 **                        Typedef Definitions
 ******************************************************************************/

/******************************************************************************
 **                        Export Variables
 ******************************************************************************/

/******************************************************************************
 **                        Export Functions
 ******************************************************************************/

#ifdef __cplusplus
}
#endif

#endif
/* EOF */
