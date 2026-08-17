/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Port_Cfg.h
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
 *****************************************************************************/
#ifndef PORT_CFG_H
#define PORT_CFG_H

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
 **                        Function Macro Definitions
 ******************************************************************************/
/**
 * @brief Switches the Det detection and notification ON or OFF
 */
#define PORT_DEV_ERROR_DETECT (STD_OFF)

/**
 * @brief Pre-processor switch to enable / disable the use of the function Port_SetPinDirection()
 */
#define PORT_SET_PIN_DIRECTION_API (STD_ON)

/**
 * @brief Pre-processor switch to enable / disable the use of the function Port_SetPinMode().
 */
#define PORT_SET_PIN_MODE_API (STD_ON)

/**
 * @brief Pre-processor switch to enable / disable the use of the function Port_GetVersionInfo().
 */
#define PORT_VERSION_INFO_API (STD_OFF)

/**
 * @brief Port config fixed address usage
 */
#define PORT_PRECOMPILE_SUPPORT (STD_OFF)

/******************************************************************************
 **                        Configuration Macro Definitions
 ******************************************************************************/
/**
 * @brief Total port defined in the mcu : for KF32A1x8MQV port A~H,J,K all defined
 */
#define PORT_TOTAL_NUMBER (8U)

/**
 * @brief Total pin each port defined in the mcu : for KF32A1x8MQV pin0~pin15
 * all defined
 */
#define PORT_PIN_TOTAL_NUMBER (16U)

/**
 * @brief Definitions to specify the pins available in the port, defined by the MCU serial and package type
 * bitX = 0 - pin X available
 * bitX = 1 - pin X not available
 * For KF32A1x8MQV
 */
/* all available */
#define MASK_PORTA (0x0000U)

/* all available */
#define MASK_PORTB (0x0000U)

/* PC15(DPI_CLK) not available on KF32A1x8MQV */
#define MASK_PORTC (0x8000U)

/* PD0(NRST),PD1(DPI_DAT),not available on KF32A1x8MQV */
#define MASK_PORTD (0x0003U)

/* all available */
#define MASK_PORTE (0x0000U)

/* all available */
#define MASK_PORTF (0x0000U)

/* all available */
#define MASK_PORTG (0x0000U)

/* PH2(OSC_OUT),PH11(OSC_IN) not available on kf32a1x8MQV */
#define MASK_PORTH (0x0804U)

/**
 * @brief Pin_ConfigType PageRemap
 */
#define PAGEMP_PAGE1 ((uint32)0x00U)
#define PAGEMP_PAGE2 ((uint32)0x01U)
#define PAGEMP_PAGE3 ((uint32)0x02U)

/**
 * @brief Pin_ConfigType SlewRate Low Speed
 */
#define SLEWR_LS ((uint32)0x00U)
/**
 * @brief Pin_ConfigType SlewRate High Speed
 */
#define SLEWR_HS ((uint32)0x01U)

/**
 * @brief Pin_ConfigType Push-Pull
 */
#define POD_PP ((uint32)0x00U)
/**
 * @brief Pin_ConfigType Open-Drain
 */
#define POD_OD ((uint32)0x01U)

/**
 * @brief Pin_ConfigType PushStatus
 */
#define PULL_NONE ((uint32)0x00U)
#define PULL_UP   ((uint32)0x01U)
#define PULL_DOWN ((uint32)0x02U)

/**
 * @brief Pin_ConfigType Remap
 */
#define GPIO_REMAP_AF0  ((uint32)0x00U)
#define GPIO_REMAP_AF1  ((uint32)0x01U)
#define GPIO_REMAP_AF2  ((uint32)0x02U)
#define GPIO_REMAP_AF3  ((uint32)0x03U)
#define GPIO_REMAP_AF4  ((uint32)0x04U)
#define GPIO_REMAP_AF5  ((uint32)0x05U)
#define GPIO_REMAP_AF6  ((uint32)0x06U)
#define GPIO_REMAP_AF7  ((uint32)0x07U)
#define GPIO_REMAP_AF8  ((uint32)0x08U)
#define GPIO_REMAP_AF9  ((uint32)0x09U)
#define GPIO_REMAP_AF10 ((uint32)0x0AU)
#define GPIO_REMAP_AF11 ((uint32)0x0BU)
#define GPIO_REMAP_AF12 ((uint32)0x0CU)
#define GPIO_REMAP_AF13 ((uint32)0x0DU)
#define GPIO_REMAP_AF14 ((uint32)0x0EU)
	
#define GPIO_PAGE2_REMAP_AF0  ((uint32)0x0100U)
#define GPIO_PAGE2_REMAP_AF1  ((uint32)0x0101U)
#define GPIO_PAGE2_REMAP_AF2  ((uint32)0x0102U)
#define GPIO_PAGE2_REMAP_AF3  ((uint32)0x0103U)
#define GPIO_PAGE2_REMAP_AF4  ((uint32)0x0104U)
#define GPIO_PAGE2_REMAP_AF5  ((uint32)0x0105U)
#define GPIO_PAGE2_REMAP_AF6  ((uint32)0x0106U)
#define GPIO_PAGE2_REMAP_AF7  ((uint32)0x0107U)
#define GPIO_PAGE2_REMAP_AF8  ((uint32)0x0108U)
#define GPIO_PAGE2_REMAP_AF9  ((uint32)0x0109U)
#define GPIO_PAGE2_REMAP_AF10 ((uint32)0x010AU)
#define GPIO_PAGE2_REMAP_AF11 ((uint32)0x010BU)
#define GPIO_PAGE2_REMAP_AF12 ((uint32)0x010CU)
#define GPIO_PAGE2_REMAP_AF13 ((uint32)0x010DU)
#define GPIO_PAGE2_REMAP_AF14 ((uint32)0x010EU)

#define GPIO_PAGE3_REMAP_AF0  ((uint32)0x0200U)
#define GPIO_PAGE3_REMAP_AF1  ((uint32)0x0201U)
#define GPIO_PAGE3_REMAP_AF2  ((uint32)0x0202U)
#define GPIO_PAGE3_REMAP_AF3  ((uint32)0x0203U)
#define GPIO_PAGE3_REMAP_AF4  ((uint32)0x0204U)
#define GPIO_PAGE3_REMAP_AF5  ((uint32)0x0205U)
#define GPIO_PAGE3_REMAP_AF6  ((uint32)0x0206U)
#define GPIO_PAGE3_REMAP_AF7  ((uint32)0x0207U)
#define GPIO_PAGE3_REMAP_AF8  ((uint32)0x0208U)
#define GPIO_PAGE3_REMAP_AF9  ((uint32)0x0209U)
#define GPIO_PAGE3_REMAP_AF10 ((uint32)0x020AU)
#define GPIO_PAGE3_REMAP_AF11 ((uint32)0x020BU)
#define GPIO_PAGE3_REMAP_AF12 ((uint32)0x020CU)
#define GPIO_PAGE3_REMAP_AF13 ((uint32)0x020DU)
#define GPIO_PAGE3_REMAP_AF14 ((uint32)0x020EU)

/**
 * @brief PIN Index
 */
#define GPIO_PIN_0  ((uint8)0x00U)
#define GPIO_PIN_1  ((uint8)0x01U)
#define GPIO_PIN_2  ((uint8)0x02U)
#define GPIO_PIN_3  ((uint8)0x03U)
#define GPIO_PIN_4  ((uint8)0x04U)
#define GPIO_PIN_5  ((uint8)0x05U)
#define GPIO_PIN_6  ((uint8)0x06U)
#define GPIO_PIN_7  ((uint8)0x07U)
#define GPIO_PIN_8  ((uint8)0x08U)
#define GPIO_PIN_9  ((uint8)0x09U)
#define GPIO_PIN_10 ((uint8)0x0AU)
#define GPIO_PIN_11 ((uint8)0x0BU)
#define GPIO_PIN_12 ((uint8)0x0CU)
#define GPIO_PIN_13 ((uint8)0x0DU)
#define GPIO_PIN_14 ((uint8)0x0EU)
#define GPIO_PIN_15 ((uint8)0x0FU)

/**
 * @brief PORT Index
 */
#define GPIO_PORT_A ((uint8)0x00U)
#define GPIO_PORT_B ((uint8)0x01U)
#define GPIO_PORT_C ((uint8)0x02U)
#define GPIO_PORT_D ((uint8)0x03U)
#define GPIO_PORT_E ((uint8)0x04U)
#define GPIO_PORT_F ((uint8)0x05U)
#define GPIO_PORT_G ((uint8)0x06U)
#define GPIO_PORT_H ((uint8)0x07U)

/** @brief Pin Mode Gpio In */
#define MODE_GPIO_IN ((uint32)0x00U)
/** @brief Pin Mode Gpio Out */
#define MODE_GPIO_OUT ((uint32)0x01U)
/** @brief Pin Mode Gpio Remap */
#define MODE_RMP ((uint32)0x02U)
/** @brief Pin Mode Gpio Analog */
#define MODE_AN ((uint32)0x03U)

/**
 * @brief Port_ConfigType IsDirChangeable,Pin direction changeable define.
 */
#define DIR_NOT_CHANGEABLE (0x00U)
#define DIR_CHANGEABLE     (0x01U)

/**
 * @brief Port_ConfigType PinsLevel Type definition-port pin level value from Port pin list
 */
#define LEVEL_HIGH (0x01U)
#define LEVEL_LOW  (0x00U)

/**
 * @brief Port_ConfigType IsPinsModeChangeable,pin during runtime
 */
#define MODE_NOT_CHANGEABLE (0x00U)
#define MODE_CHANGEABLE     (0x01U)

/**
 * @brief Port_ConfigType PinsLockSts
 */
#define GPIO_UNLOCK (0x00U)
#define GPIO_LOCK   (0x01U)

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
