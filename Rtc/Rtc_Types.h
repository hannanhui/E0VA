/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Rtc_Types.h
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
#ifndef RTC_TYPES_H
#define RTC_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 **                        MISRA-C Rules Violations
 ******************************************************************************/
/**
 * @page misra_violations MISRA-C:2004 violations
 *
 * @section
 */
/* PRQA S 3205 EOF #KQR003205 */
/******************************************************************************
 **                        QAC Warnings
 ******************************************************************************/
/**
 * @page QAC Warnings
 *
 */

/******************************************************************************
 **                        Include Files
 ******************************************************************************/
#include <stdint.h>
#include <stdbool.h>
#include "Std_Types.h"

/******************************************************************************
 **                        File Version Check
 ******************************************************************************/

/******************************************************************************
 **                        Macro  Definitions
 ******************************************************************************/

/******************************************************************************
 **                        Typedef  Definitions
 ******************************************************************************/
typedef void (*RTC_InterruptHandler)(void);

/**
 * @brief time format
 */
typedef enum
{
    RTC_IM_24H,
    RTC_IM_12H,
} Rtc_TimeFormatType;

typedef enum
{
    RTC_ALARM_A         = 1U,
    RTC_ALARM_B         = 2U,
    RTC_ALARM_MAX_INDEX = 3U,
} Rtc_IndexType;

typedef enum
{
    RTC_ALARM_REPEAT_DAY  = 0x7U,
    RTC_ALARM_REPEAT_WEEK = 0xFU
} Rtc_AlarmRepeatType;

typedef enum
{
    RTC_STATUS_OK,
    RTC_STATUS_CLOCK_ERR,
    RTC_STATUS_MODULE_ERR,
    RTC_STATUS_ALREADY_INITIALIZED,
    RTC_STATUS_INVALID_PARAM,
    RTC_STATUS_INVALID_TIME,
} Rtc_StatusType;

/**
 * @brief Rtc clock source.
 */
typedef enum
{
    RTC_EXTLF = 1U,
    RTC_INTLF = 2U,
} Rtc_ClockType;

/**
 * @brief Structure of RTC date and time
 * @attention The values of members should be BCD codes.
 */
/* PRQA S 3630 ++ #KQR003630 */
typedef struct
{
    /**
     * @attention BCD code. Range of values is 0x0~0x99.
     */
    uint8_t Year;
    /**
     * @attention BCD code. Range of values is 0x01~0x12.
     */
    uint8_t Month;
    /**
     * @attention BCD code. Range of values is 0x1~0x31.
     */
    uint8_t Day;
    /**
     * @attention BCD code. Range of values is 0x0~0x6.
     * @attention SUNDAY is 0x0.
     */
    uint8_t Week;
    /**
     * @attention BCD code. Range of values is 0x0~0x23.
     */
    uint8_t Hour;
    /**
     * @attention BCD code. Range of values is 0x0~0x59.
     */
    uint8_t Minute;
    /**
     * @attention BCD code. Range of values is 0x0~0x59.
     */
    uint8_t Second;
} Rtc_DateTimeType;

/**
 * @brief Structure of RTC date.
 * @attention The values of members should be BCD codes.
 */
typedef struct
{
    /**
     * @attention BCD code. Range of values is 0x0~0x99.
     */
    uint8_t Year;
    /**
     * @attention BCD code. Range of values is 0x01~0x12.
     */
    uint8_t Month;
    /**
     * @attention BCD code. Range of values is 0x1~0x31.
     */
    uint8_t Day;
} Rtc_DateType;

/**
 * @brief Structure of RTC time.
 * @attention The values of members should be BCD codes.
 */
typedef struct
{
    /**
     * @attention BCD code. Range of values is 0x0~0x6.
     * @attention SUNDAY is 0x0.
     */
    uint8_t Week;
    /**
     * @attention BCD code. Range of values is 0x0~0x23.
     */
    uint8_t Hour;
    /**
     * @attention BCD code. Range of values is 0x0~0x59.
     */
    uint8_t Minute;
    /**
     * @attention BCD code. Range of values is 0x0~0x59.
     */
    uint8_t Second;
} Rtc_TimeType;
/* PRQA S 3630 -- #KQR003630 */

/**
 * @brief Structure of RTC config.
 */
typedef struct
{
    Rtc_ClockType        Clock;
    Rtc_DateType const  *DateConfig;
    Rtc_TimeType const  *TimeConfig;
    RTC_InterruptHandler AlarmACallback;
    RTC_InterruptHandler AlarmBCallback;
} Rtc_ConfigType;

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
