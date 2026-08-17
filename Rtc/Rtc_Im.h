/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Rtc_Im.h
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
#ifndef RTC_IM_H
#define RTC_IM_H

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
#include "kf_types.h"
#include "Rtc_Types.h"

/******************************************************************************
 **                        File Version Check
 ******************************************************************************/

/******************************************************************************
 **                        Macro  Definitions
 ******************************************************************************/

/******************************************************************************
 **                        Typedef  Definitions
 ******************************************************************************/
/**
 * @brief MONTH
 */
typedef enum
{
    RTC_IM_JANUARY   = 0x01u,
    RTC_IM_FEBRUARY  = 0x02u,
    RTC_IM_MARCH     = 0x03u,
    RTC_IM_APRIL     = 0x04u,
    RTC_IM_MAY       = 0x05u,
    RTC_IM_JUNE      = 0x06u,
    RTC_IM_JULY      = 0x07u,
    RTC_IM_AUGUST    = 0x08u,
    RTC_IM_SEPTEMBER = 0x09u,
    RTC_IM_OCTOBER   = 0x10u,
    RTC_IM_NOVEMBER  = 0x11u,
    RTC_IM_DECEMBER  = 0x12u,
} Rtc_MonthEnumType;

/**
 * @brief DAY
 */
typedef enum
{
    RTC_IM_DAY_1  = 0x01u,
    RTC_IM_DAY_2  = 0x02u,
    RTC_IM_DAY_3  = 0x03u,
    RTC_IM_DAY_4  = 0x04u,
    RTC_IM_DAY_5  = 0x05u,
    RTC_IM_DAY_6  = 0x06u,
    RTC_IM_DAY_7  = 0x07u,
    RTC_IM_DAY_8  = 0x08u,
    RTC_IM_DAY_9  = 0x09u,
    RTC_IM_DAY_10 = 0x10u,
    RTC_IM_DAY_11 = 0x11u,
    RTC_IM_DAY_12 = 0x12u,
    RTC_IM_DAY_13 = 0x13u,
    RTC_IM_DAY_14 = 0x14u,
    RTC_IM_DAY_15 = 0x15u,
    RTC_IM_DAY_16 = 0x16u,
    RTC_IM_DAY_17 = 0x17u,
    RTC_IM_DAY_18 = 0x18u,
    RTC_IM_DAY_19 = 0x19u,
    RTC_IM_DAY_20 = 0x20u,
    RTC_IM_DAY_21 = 0x21u,
    RTC_IM_DAY_22 = 0x22u,
    RTC_IM_DAY_23 = 0x23u,
    RTC_IM_DAY_24 = 0x24u,
    RTC_IM_DAY_25 = 0x25u,
    RTC_IM_DAY_26 = 0x26u,
    RTC_IM_DAY_27 = 0x27u,
    RTC_IM_DAY_28 = 0x28u,
    RTC_IM_DAY_29 = 0x29u,
    RTC_IM_DAY_30 = 0x30u,
    RTC_IM_DAY_31 = 0x31u,
} Rtc_DayEnumType;

/**
 * Week
 */
typedef enum
{
    RTC_IM_SUNDAY,
    RTC_IM_MONDAY,
    RTC_IM_TUESDAY,
    RTC_IM_WEDNESDAY,
    RTC_IM_THURSDAY,
    RTC_IM_FRIDAY,
    RTC_IM_SATURDAY,
} Rtc_WeekDayEnumType;

/**
 * Hour
 */
typedef enum
{
    RTC_IM_HOUR_0  = 0x00u,
    RTC_IM_HOUR_1  = 0x01u,
    RTC_IM_HOUR_2  = 0x02u,
    RTC_IM_HOUR_3  = 0x03u,
    RTC_IM_HOUR_4  = 0x04u,
    RTC_IM_HOUR_5  = 0x05u,
    RTC_IM_HOUR_6  = 0x06u,
    RTC_IM_HOUR_7  = 0x07u,
    RTC_IM_HOUR_8  = 0x08u,
    RTC_IM_HOUR_9  = 0x09u,
    RTC_IM_HOUR_10 = 0x10u,
    RTC_IM_HOUR_11 = 0x11u,
    RTC_IM_HOUR_12 = 0x12u,
    RTC_IM_HOUR_13 = 0x13u,
    RTC_IM_HOUR_14 = 0x14u,
    RTC_IM_HOUR_15 = 0x15u,
    RTC_IM_HOUR_16 = 0x16u,
    RTC_IM_HOUR_17 = 0x17u,
    RTC_IM_HOUR_18 = 0x18u,
    RTC_IM_HOUR_19 = 0x19u,
    RTC_IM_HOUR_20 = 0x20u,
    RTC_IM_HOUR_21 = 0x21u,
    RTC_IM_HOUR_22 = 0x22u,
    RTC_IM_HOUR_23 = 0x23u,
} Rtc_HourEnumType;

/**
 * Minute
 */
typedef enum
{
    RTC_IM_MIN_0  = 0x00u,
    RTC_IM_MIN_1  = 0x01u,
    RTC_IM_MIN_2  = 0x02u,
    RTC_IM_MIN_3  = 0x03u,
    RTC_IM_MIN_4  = 0x04u,
    RTC_IM_MIN_5  = 0x05u,
    RTC_IM_MIN_6  = 0x06u,
    RTC_IM_MIN_7  = 0x07u,
    RTC_IM_MIN_8  = 0x08u,
    RTC_IM_MIN_9  = 0x09u,
    RTC_IM_MIN_10 = 0x10u,
    RTC_IM_MIN_11 = 0x11u,
    RTC_IM_MIN_12 = 0x12u,
    RTC_IM_MIN_13 = 0x13u,
    RTC_IM_MIN_14 = 0x14u,
    RTC_IM_MIN_15 = 0x15u,
    RTC_IM_MIN_16 = 0x16u,
    RTC_IM_MIN_17 = 0x17u,
    RTC_IM_MIN_18 = 0x18u,
    RTC_IM_MIN_19 = 0x19u,
    RTC_IM_MIN_20 = 0x20u,
    RTC_IM_MIN_21 = 0x21u,
    RTC_IM_MIN_22 = 0x22u,
    RTC_IM_MIN_23 = 0x23u,
    RTC_IM_MIN_24 = 0x24u,
    RTC_IM_MIN_25 = 0x25u,
    RTC_IM_MIN_26 = 0x26u,
    RTC_IM_MIN_27 = 0x27u,
    RTC_IM_MIN_28 = 0x28u,
    RTC_IM_MIN_29 = 0x29u,
    RTC_IM_MIN_30 = 0x30u,
    RTC_IM_MIN_31 = 0x31u,
    RTC_IM_MIN_32 = 0x32u,
    RTC_IM_MIN_33 = 0x33u,
    RTC_IM_MIN_34 = 0x34u,
    RTC_IM_MIN_35 = 0x35u,
    RTC_IM_MIN_36 = 0x36u,
    RTC_IM_MIN_37 = 0x37u,
    RTC_IM_MIN_38 = 0x38u,
    RTC_IM_MIN_39 = 0x39u,
    RTC_IM_MIN_40 = 0x40u,
    RTC_IM_MIN_41 = 0x41u,
    RTC_IM_MIN_42 = 0x42u,
    RTC_IM_MIN_43 = 0x43u,
    RTC_IM_MIN_44 = 0x44u,
    RTC_IM_MIN_45 = 0x45u,
    RTC_IM_MIN_46 = 0x46u,
    RTC_IM_MIN_47 = 0x47u,
    RTC_IM_MIN_48 = 0x48u,
    RTC_IM_MIN_49 = 0x49u,
    RTC_IM_MIN_50 = 0x50u,
    RTC_IM_MIN_51 = 0x51u,
    RTC_IM_MIN_52 = 0x52u,
    RTC_IM_MIN_53 = 0x53u,
    RTC_IM_MIN_54 = 0x54u,
    RTC_IM_MIN_55 = 0x55u,
    RTC_IM_MIN_56 = 0x56u,
    RTC_IM_MIN_57 = 0x57u,
    RTC_IM_MIN_58 = 0x58u,
    RTC_IM_MIN_59 = 0x59u,
} Rtc_MinuteEnumType;

/**
 * Second
 */
typedef enum
{
    RTC_IM_SEC_0  = 0x00u,
    RTC_IM_SEC_1  = 0x01u,
    RTC_IM_SEC_2  = 0x02u,
    RTC_IM_SEC_3  = 0x03u,
    RTC_IM_SEC_4  = 0x04u,
    RTC_IM_SEC_5  = 0x05u,
    RTC_IM_SEC_6  = 0x06u,
    RTC_IM_SEC_7  = 0x07u,
    RTC_IM_SEC_8  = 0x08u,
    RTC_IM_SEC_9  = 0x09u,
    RTC_IM_SEC_10 = 0x10u,
    RTC_IM_SEC_11 = 0x11u,
    RTC_IM_SEC_12 = 0x12u,
    RTC_IM_SEC_13 = 0x13u,
    RTC_IM_SEC_14 = 0x14u,
    RTC_IM_SEC_15 = 0x15u,
    RTC_IM_SEC_16 = 0x16u,
    RTC_IM_SEC_17 = 0x17u,
    RTC_IM_SEC_18 = 0x18u,
    RTC_IM_SEC_19 = 0x19u,
    RTC_IM_SEC_20 = 0x20u,
    RTC_IM_SEC_21 = 0x21u,
    RTC_IM_SEC_22 = 0x22u,
    RTC_IM_SEC_23 = 0x23u,
    RTC_IM_SEC_24 = 0x24u,
    RTC_IM_SEC_25 = 0x25u,
    RTC_IM_SEC_26 = 0x26u,
    RTC_IM_SEC_27 = 0x27u,
    RTC_IM_SEC_28 = 0x28u,
    RTC_IM_SEC_29 = 0x29u,
    RTC_IM_SEC_30 = 0x30u,
    RTC_IM_SEC_31 = 0x31u,
    RTC_IM_SEC_32 = 0x32u,
    RTC_IM_SEC_33 = 0x33u,
    RTC_IM_SEC_34 = 0x34u,
    RTC_IM_SEC_35 = 0x35u,
    RTC_IM_SEC_36 = 0x36u,
    RTC_IM_SEC_37 = 0x37u,
    RTC_IM_SEC_38 = 0x38u,
    RTC_IM_SEC_39 = 0x39u,
    RTC_IM_SEC_40 = 0x40u,
    RTC_IM_SEC_41 = 0x41u,
    RTC_IM_SEC_42 = 0x42u,
    RTC_IM_SEC_43 = 0x43u,
    RTC_IM_SEC_44 = 0x44u,
    RTC_IM_SEC_45 = 0x45u,
    RTC_IM_SEC_46 = 0x46u,
    RTC_IM_SEC_47 = 0x47u,
    RTC_IM_SEC_48 = 0x48u,
    RTC_IM_SEC_49 = 0x49u,
    RTC_IM_SEC_50 = 0x50u,
    RTC_IM_SEC_51 = 0x51u,
    RTC_IM_SEC_52 = 0x52u,
    RTC_IM_SEC_53 = 0x53u,
    RTC_IM_SEC_54 = 0x54u,
    RTC_IM_SEC_55 = 0x55u,
    RTC_IM_SEC_56 = 0x56u,
    RTC_IM_SEC_57 = 0x57u,
    RTC_IM_SEC_58 = 0x58u,
    RTC_IM_SEC_59 = 0x59u,
} Rtc_SecondEnumType;

/**
 * @brief RTC Initialization Structure
 */
/* PRQA S 3630 ++ #KQR003630 */
typedef struct
{
    /* Clock Source */
    Rtc_ClockType ClkSrc;
    /**
     * Year, @attention BCD code
     */
    uint8_t Year;
    /* Month */
    Rtc_MonthEnumType Month;
    /* Day */
    Rtc_DayEnumType Day;
    /* Weekday */
    Rtc_WeekDayEnumType Week;
    /* Hour */
    Rtc_HourEnumType Hour;
    /* Minute */
    Rtc_MinuteEnumType Minute;
    /* Second */
    Rtc_SecondEnumType Second;
    /**
     * Time Format, 12-hour/24-hour. See macro definitions for Time Format.
     */
    bool HourFormat;
    /**
     * AM/PM, see macro definitions for AM/PM.
     */
    bool AmOrPm;
} Rtc_InitStructType;

/**
 * @brief Alarm Repeat Type
 */
typedef enum
{
    RTC_ALARM_REPEAT_EVERY_MINUTE = 0x1U,
    RTC_ALARM_REPEAT_EVERY_HOUR   = 0x3U,
    RTC_ALARM_REPEAT_EVERY_DAY    = 0x7U,
    RTC_ALARM_REPEAT_EVERY_WEEK   = 0xFU,
} Rtc_AlarmRepeatEnumType;

/**
 * @brief Alarm structure
 */
typedef struct
{
    /**
     * Day of the week
     */
    Rtc_WeekDayEnumType Week;
    /**
     * Hour of the day
     */
    Rtc_HourEnumType Hour;
    /**
     * Minute of the hour
     */
    Rtc_MinuteEnumType Minute;
    /**
     * Second of the minute
     */
    Rtc_SecondEnumType Second;
    /**
     * Alarm repeat type (e.g., daily, weekly, etc.)
     */
    Rtc_AlarmRepeatEnumType RepeatType;
    /**
     * Alarm index, see macro definitions for alarm indexes
     */
    uint8_t AlarmIndex;
    /**
     * AM/PM, see macro definitions for AM/PM
     */
    bool AmOrPm;
} Rtc_AlarmStructType;

/**
 * @brief Interrupt Index Enumeration for RTC
 */
typedef enum
{
    /* Second interrupt index */
    RTC_INTR_INDEX_SECOND = 0U,
    /* Minute interrupt index */
    RTC_INTR_INDEX_MINUTE = 1U,
    /* Hour interrupt index */
    RTC_INTR_INDEX_HOUR = 2U,
    /* Day interrupt index */
    RTC_INTR_INDEX_DAY = 3U,
    /* Alarm A interrupt index */
    RTC_INTR_INDEX_ALARM_A = 4U,
    /* Alarm B interrupt index */
    RTC_INTR_INDEX_ALARM_B = 5U,
    /* Time tick interrupt index */
    RTC_INTR_INDEX_TICK_TIME = 6U,
    /* RTC Timer 0 interrupt index */
    RTC_INTR_INDEX_RTC_TIM0 = 8U,
    /* RTC Timer 1 interrupt index */
    RTC_INTR_INDEX_RTC_TIM1 = 9U,
    /* Timestamp overflow interrupt index */
    RTC_INTR_INDEX_TIM_STAMP_OVERFLOW = 10U,
    /* Timestamp interrupt index */
    RTC_INTR_INDEX_TIM_STAMP = 11U,
    RTC_INTR_INDEX_WEEK      = 13U,
    RTC_INTR_INDEX_MONTH     = 14U,
    RTC_INTR_INDEX_YEAR      = 15U,
} Rtc_IntrIndexEnumType;

/**
 * @brief Time Tick
 */
typedef enum
{
    RTC_IM_TICK_TIME_1S,
    RTC_IM_TICK_TIME_1S_DIV_2,
    RTC_IM_TICK_TIME_1S_DIV_4,
    RTC_IM_TICK_TIME_1S_DIV_8,
    RTC_IM_TICK_TIME_1S_DIV_16,
    RTC_IM_TICK_TIME_1S_DIV_32,
    RTC_IM_TICK_TIME_1S_DIV_64,
    RTC_IM_TICK_TIME_1S_DIV_128,
} Rtc_TickTimeEnumType;

/**
 * @brief External Interrupt Index
 */
typedef enum
{
    INTR_EXTI_IM_INDEX_16 = 16U,
    INTR_EXTI_IM_INDEX_17 = 17U,
    INTR_EXTI_IM_INDEX_18 = 18U,
    INTR_EXTI_IM_INDEX_19 = 19U,
    INTR_EXTI_IM_INDEX_20 = 20U,
    INTR_EXTI_IM_INDEX_21 = 21U,
    INTR_EXTI_IM_INDEX_22 = 22U,
    INTR_EXTI_IM_INDEX_23 = 23U,
    INTR_EXTI_IM_INDEX_24 = 24U,
    INTR_EXTI_IM_INDEX_25 = 25U,
    INTR_EXTI_IM_INDEX_26 = 26U,
    INTR_EXTI_IM_INDEX_27 = 27U,
    INTR_EXTI_IM_INDEX_28 = 28U,
    INTR_EXTI_IM_INDEX_29 = 29U,
    INTR_EXTI_IM_INDEX_30 = 30U,
    INTR_EXTI_IM_INDEX_31 = 31U,
} Intr_ExtiIndexEnumType;

/**
 * @brief External Interrupt Initialization Structure
 */
typedef struct
{
    /* External interrupt index (number or identifier) */
    Intr_ExtiIndexEnumType Index;
    /* External interrupt mask (enable/disable) */
    bool Mask;
    /* Enable state for rising edge trigger of external interrupt */
    bool RiseEdgeEnable;
    /* Enable state for falling edge trigger of external interrupt */
    bool FallEdgeEnable;
    /* Enable state for high-level trigger of external interrupt */
    bool HiLevelEnable;
} Intr_ExitInitStructType;
/* PRQA S 3630 -- #KQR003630 */
/******************************************************************************
 **                        Export Variables
 ******************************************************************************/

/******************************************************************************
 **                        Export Functions
 ******************************************************************************/
/**
 * @brief rtc alarm pre init
 */
void Rtc_AlarmPreInit(void);
/**
 * @brief enable or disable rtc
 * @param EnableSta
 * @retval void
 */
void Rtc_Im_Enable(bool EnableSta);
/**
 * @brief set rtc data and time
 *
 * @param DateConfig data config pointer
 * @param TimeConfig time config pointer
 */
void Rtc_Im_SetDataTime(const Rtc_DateType *DateConfig, const Rtc_TimeType *TimeConfig);
/**
 * @brief check rtc set data and time
 *
 * @retval true:check success
 * @retval false:check and rewrite failed
 */
bool Rtc_Im_CheckAndReWriteDataAndTime(
  uint8_t Year, uint8_t Month, uint8_t Day, uint8_t Week, uint8_t Hour, uint8_t Minute, uint8_t Second);
/**
 * @brief get rtc data and time
 *
 * @param RtcDate data pointer
 */
void Rtc_Im_GetDateAndTime(Rtc_DateTimeType *RtcDate);
/**
 * @brief set rtc alarm time
 * @param AlarmStruct alarm information pointer
 * @retval kf_status_t
 */
kf_status_t Rtc_Im_SetAlarm(const Rtc_AlarmStructType *AlarmStruct);
/**
 * @brief enable or disable alarm
 * @param AlarmIndex alarm index
 * @param EnableSta enable or disable
 * @retval void
 */
void Rtc_Im_AlarmEnable(Rtc_IndexType AlarmIndex, bool EnableSta);
/**
 * @brief clear Rtc interrupt flag
 * @param IntrIndex rtc interrupt index
 * @retval void
 */
void Rtc_Im_ClearIntrFlag(Rtc_IntrIndexEnumType IntrIndex);
/**
 * @brief get Rtc interrupt flag
 * @param IntrIndex rtc interrupt index
 * @retval void
 */
bool Rtc_Im_GetIntrFlag(Rtc_IntrIndexEnumType IntrIndex);
/**
 * @brief Enable Date Register
 */
void Rtc_Im_EnableDateRegister(void);
/**
 * @brief initialize rtc information
 * @param RtcInitStruct rtc init struct pointer
 * @retval kf_status_t
 */
kf_status_t Rtc_Im_Init(const Rtc_InitStructType *RtcInitStruct);
/**
 * @brief set rtc tick time
 *
 * @param TickTime
 * @retval void
 */
void Rtc_Im_SetTickTime(Rtc_TickTimeEnumType TickTime);
/**
 * @brief set alarm callback function
 *
 * @param AlarmIndex alarm index
 * @param callbackFnc callback function
 */
void Rtc_Im_SetAlarmCallBack(Rtc_IndexType AlarmIndex, RTC_InterruptHandler callbackFnc);
/**
 * @brief external low frequency oscillator init
 * @param Timeout
 * @retval kf_status_t
 */
kf_status_t Rtc_Im_OscExtlfInit(uint32_t Timeout);
/**
 * @brief Initialization of External Interrupt Line
 *
 * @param ExtiInitStruct
 * @retval kf_status_t
 */
kf_status_t Rtc_Im_IntrExtiInit(const Intr_ExitInitStructType *const ExtiInitStruct);
/**
 * @brief RTC interrupt handler
 *
 * @param void
 * @return void
 */
void Rtc_Im_Isr(void);
/**
 * @brief Get the interrupt flag for an external interrupt line.
 *
 * @param Index The index of the external interrupt, see Intr_ExtiIndexEnumType for details.
 * @retval bool
 */
bool Rtc_Im_IntrGetExtiFlag(Intr_ExtiIndexEnumType Index);
/**
 * @brief Clear the interrupt flag for an external interrupt line.
 *
 * @param Index The index of the external interrupt, see Intr_ExtiIndexEnumType for details.
 * @retval void
 */
void Rtc_Im_IntrClearExtiFlag(Intr_ExtiIndexEnumType Index);
#ifdef __cplusplus
}
#endif

#endif
/* EOF */
