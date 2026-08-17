/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Compiler_Cfg.h
 *  @Syntax          : GNU99
 *  @Author          : ChipON AE/FAE Group
 *  @Date            : 2025-08-29
 *  @Version         : V1.0.0_SF
 *  @Description     : This document describes the C language document template.
 ******************************************************************************
 *  Copyright (C) by Shanghai ChipON Micro-Electronic Co.,Ltd
 *  All rights reserved.
 *
 *  This software is copyright protected and proprietary to
 *  Shanghai ChipON Micro-Electronic Co.,Ltd.
 ******************************************************************************
 *                        REVISION HISTORY
 ******************************************************************************
 *  |Date        |Version  |Author       |Description
 ******************************************************************************
 *  |2025-08-29  |V1.0     |Wang Ning    |New creat
 *****************************************************************************/
#ifndef COMPILER_CFG_H
#define COMPILER_CFG_H

/* Compiler symbols definition */
/* PRQA S 0603 1 #KQR000603 */
#define _CHIPON_GCC_KF32_

/**
 * @brief GPT memory and pointer classes.
 *
 */
#define GPT_CODE
#define GPT_CONST
#define GPT_CONFIG_DATA
#define GPT_APPL_DATA
#define GPT_APPL_CONST
#define GPT_APPL_CODE
#define GPT_CALLOUT_CODE
#define GPT_VAR_NOINIT
#define GPT_VAR_CLEARED
#define GPT_VAR_POWER_ON_CLEARED
#define GPT_VAR_POWER_INIT
#define GPT_VAR_POWER_ON_INIT
#define GPT_VAR_FAST
#define GPT_VAR

/**
 * @brief CAN memory and pointer classes.
 *
 */
#define CAN_CODE
#define CAN_CONST
#define CAN_CONFIG_DATA
#define CAN_APPL_DATA
#define CAN_APPL_CONST
#define CAN_CALLOUT_CODE
#define CAN_VAR_NOINIT
#define CAN_VAR_CLEARED
#define CAN_VAR_POWER_ON_CLEARED
#define CAN_VAR_POWER_INIT
#define CAN_VAR_POWER_ON_INIT
#define CAN_VAR_FAST
#define CAN_VAR

/**
 * @brief MCU memory and pointer classes.
 */
#define MCU_CODE
#define MCU_CONST
#define MCU_CONFIG_DATA
#define MCU_APPL_DATA
#define MCU_APPL_CONST
#define MCU_CALLOUT_CODE
#define MCU_VAR_NOINIT
#define MCU_VAR_CLEARED
#define MCU_VAR_POWER_ON_CLEARED
#define MCU_VAR_POWER_INIT
#define MCU_VAR_POWER_ON_INIT
#define MCU_VAR_FAST
#define MCU_VAR

/**
 * @brief LinIf memory and pointer classes.
 */
#define LINIF_CODE
#define LINIF_CONST
#define LINIF_CONFIG_DATA
#define LINIF_APPL_DATA
#define LINIF_APPL_CONST
#define LINIF_CALLOUT_CODE
#define LINIF_VAR_NOINIT
#define LINIF_VAR_CLEARED
#define LINIF_VAR_POWER_ON_CLEARED
#define LINIF_VAR_POWER_INIT
#define LINIF_VAR_POWER_ON_INIT
#define LINIF_VAR_FAST
#define LINIF_VAR

/**
 * @brief Adc memory and pointer classes.
 */
#define ADC_CODE
#define ADC_CONST
#define ADC_CONFIG_DATA
#define ADC_APPL_DATA
#define ADC_APPL_CONST
#define ADC_CALLOUT_CODE
#define ADC_VAR_NOINIT
#define ADC_VAR_CLEARED
#define ADC_VAR_POWER_ON_CLEARED
#define ADC_VAR_POWER_INIT
#define ADC_VAR_POWER_ON_INIT
#define ADC_VAR_FAST
#define ADC_VAR

/**
 * @brief Det memory and pointer classes.
 */
#define DET_CODE
#define DET_CONST
#define DET_CONFIG_DATA
#define DET_APPL_DATA
#define DET_APPL_CONST
#define DET_CALLOUT_CODE
#define DET_VAR_NOINIT
#define DET_VAR_CLEARED
#define DET_VAR_POWER_ON_CLEARED
#define DET_VAR_POWER_INIT
#define DET_VAR_POWER_ON_INIT
#define DET_VAR_FAST
#define DET_VAR

/**
 * @brief WDG memory and pointer classes.
 */
#define WDG_CODE
#define WDG_CONST
#define WDG_CONFIG_DATA
#define WDG_APPL_DATA
#define WDG_APPL_CONST
#define WDG_CALLOUT_CODE
#define WDG_VAR_NOINIT
#define WDG_VAR_CLEARED
#define WDG_VAR_POWER_ON_CLEARED
#define WDG_VAR_POWER_INIT
#define WDG_VAR_POWER_ON_INIT
#define WDG_VAR_FAST
#define WDG_VAR

/**
 * @brief SPI memory and pointer classes.
 */
#define SPI_CODE
#define SPI_CONST
#define SPI_APPL_DATA
#define SPI_APPL_CONST
#define SPI_APPL_CODE
#define SPI_CALLOUT_CODE
#define SPI_VAR_NOINIT
#define SPI_VAR_POWER_ON_INIT
#define SPI_VAR_FAST
#define SPI_VAR

/**
 * @brief ICU memory and pointer classes.
 */
#define ICU_CODE
#define ICU_CONST
#define ICU_APPL_DATA
#define ICU_APPL_CONST
#define ICU_APPL_CODE
#define ICU_CALLOUT_CODE
#define ICU_VAR_NOINIT
#define ICU_VAR_POWER_ON_INIT
#define ICU_VAR_FAST
#define ICU_VAR

/**
 * @brief OCU memory and pointer classes.
 */
#define OCU_CODE
#define OCU_CONST
#define OCU_APPL_DATA
#define OCU_APPL_CONST
#define OCU_APPL_CODE
#define OCU_CALLOUT_CODE
#define OCU_VAR_NOINIT
#define OCU_VAR_POWER_ON_INIT
#define OCU_VAR_FAST
#define OCU_VAR

/**
 * @brief PWM memory and pointer classes.
 */
#define PWM_CODE
#define PWM_CONST
#define PWM_APPL_DATA
#define PWM_APPL_CONST
#define PWM_APPL_CODE
#define PWM_CALLOUT_CODE
#define PWM_VAR_NOINIT
#define PWM_VAR_POWER_ON_INIT
#define PWM_VAR_FAST
#define PWM_VAR

/**
 * @brief CanIf memory and pointer classes.
 */
#define CANIF_CODE
#define CANIF_CONST
#define CANIF_APPL_DATA
#define CANIF_APPL_CONST
#define CANIF_APPL_CODE
#define CANIF_CALLOUT_CODE
#define CANIF_VAR_NOINIT
#define CANIF_VAR_POWER_ON_INIT
#define CANIF_VAR_FAST
#define CANIF_VAR

/**
 * @brief Dio memory and pointer classes.
 */
#define DIO_CODE
#define DIO_CONST
#define DIO_APPL_DATA
#define DIO_APPL_CONST
#define DIO_APPL_CODE
#define DIO_CALLOUT_CODE
#define DIO_VAR_NOINIT
#define DIO_VAR_POWER_ON_INIT
#define DIO_VAR_FAST
#define DIO_VAR

/**
 * @brief Fls memory and pointer classes.
 */
#define FLS_CODE
#define FLS_CONST
#define FLS_APPL_DATA
#define FLS_APPL_CONST
#define FLS_APPL_CODE
#define FLS_CALLOUT_CODE
#define FLS_VAR_NOINIT
#define FLS_VAR_POWER_ON_INIT
#define FLS_VAR_FAST
#define FLS_VAR

/**
 * @brief Fee memory and pointer classes.
 */
#define FEE_CODE
#define FEE_CONST
#define FEE_APPL_DATA
#define FEE_APPL_CONST
#define FEE_APPL_CODE
#define FEE_CALLOUT_CODE
#define FEE_VAR_NOINIT
#define FEE_VAR_POWER_ON_INIT
#define FEE_VAR_FAST
#define FEE_VAR

/**
 * @brief Port memory and pointer classes.
 */
#define PORT_CODE
#define PORT_CONST
#define PORT_APPL_DATA
#define PORT_APPL_CONST
#define PORT_APPL_CODE
#define PORT_CALLOUT_CODE
#define PORT_VAR_NOINIT
#define PORT_VAR_POWER_ON_INIT
#define PORT_VAR_FAST
#define PORT_VAR

/**
 * @brief WdgIf memory and pointer classes.
 */
#define WDGIF_CODE
#define WDGIF_CONST
#define WDGIF_CONFIG_DATA
#define WDGIF_APPL_DATA
#define WDGIF_APPL_CONST
#define WDGIF_CALLOUT_CODE
#define WDGIF_VAR_NOINIT
#define WDGIF_VAR_CLEARED
#define WDGIF_VAR_POWER_ON_CLEARED
#define WDGIF_VAR_POWER_INIT
#define WDGIF_VAR_POWER_ON_INIT
#define WDGIF_VAR_FAST
#define WDGIF_VAR

/**
 * @brief I2c memory and pointer classes.
 */
#define I2C_CODE
#define I2C_CONST
#define I2C_CONFIG_DATA
#define I2C_APPL_DATA
#define I2C_APPL_CONST
#define I2C_CALLOUT_CODE
#define I2C_VAR_NOINIT
#define I2C_VAR_CLEARED
#define I2C_VAR_POWER_ON_CLEARED
#define I2C_VAR_POWER_INIT
#define I2C_VAR_POWER_ON_INIT
#define I2C_VAR_FAST
#define I2C_VAR

/**
 * @brief Lin memory and pointer classes.
 */
#define LIN_CODE
#define LIN_CONST
#define LIN_CONFIG_DATA
#define LIN_APPL_DATA
#define LIN_APPL_CONST
#define LIN_CALLOUT_CODE
#define LIN_VAR_NOINIT
#define LIN_VAR_CLEARED
#define LIN_VAR_POWER_ON_CLEARED
#define LIN_VAR_POWER_INIT
#define LIN_VAR_POWER_ON_INIT
#define LIN_VAR_FAST
#define LIN_VAR

/**
 * @brief RTC memory and pointer classes.
 */
#define RTC_CODE
#define RTC_CONST
#define RTC_APPL_DATA
#define RTC_APPL_CONST
#define RTC_APPL_CODE
#define RTC_CALLOUT_CODE
#define RTC_VAR_NOINIT
#define RTC_VAR_POWER_ON_INIT
#define RTC_VAR_FAST
#define RTC_VAR

typedef enum
{
    _AR_GPT,
    _AR_CAN,
    _AR_MCU,
    _AR_LINIF,
    _AR_ADC,
    _AR_DET,
    _AR_WDG,
    _AR_SPI,
    _AR_ICU,
    _AR_OCU,
    _AR_PWM,
    _AR_CANIF,
    _AR_DIO,
    _AR_FLS,
    _AR_FEE,
    _AR_PORT,
    _AR_WDGIF,
    _AR_TOTAL_MODULE_NUM
} AR_ModuleType;

#endif
