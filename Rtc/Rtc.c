/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Rtc.c
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
/* PRQA S 0303 EOF #KQR000303 */
/* PRQA S 4342 EOF #KQR004342 */
/* PRQA S 4322 EOF #KQR004322 */
/* PRQA S 4391 EOF #KQR004391 */
/* PRQA S 2814 EOF #KQR002814 */
/* PRQA S 2201 EOF #KQR002201 */
/* PRQA S 4899 EOF #KQR004899 */
/* PRQA S 3384 EOF #KQR003384 */
/******************************************************************************
 **                        Include Files
 ******************************************************************************/
#include "Rtc.h"
#include "Rtc_Im.h"

/******************************************************************************
 **                        File Version Check
 ******************************************************************************/

/******************************************************************************
 **                        Macro  Definitions
 ******************************************************************************/
#ifdef RTC_ERROR_DETECT
#include "dev_assert.h"
#define RTC_ASSERT(x) KF_DEV_ASSERT((x))
#else
#define RTC_ASSERT(x) ((void)0U)
#endif
/* PRQA S 3472 1 #KQR003472 */
#define RTC_BCD_TO_DEC(x) ((((x) >> 4U) * 10U) + ((x)&0x0FU))
/******************************************************************************
 **                        Typedef  Definitions
 ******************************************************************************/
/**
 * @brief RTC state
 */
typedef enum
{
    RTC_UNUSED,
    RTC_RUN,
} Rtc_StateType;
/******************************************************************************
 **                        Export Variables
 ******************************************************************************/

/******************************************************************************
 **                        Export Functions
 ******************************************************************************/
/******************************************************************************
 **                        Variables
 ******************************************************************************/

/**
 * @brief RTC module status
 */
static Rtc_StateType Rtc_State = RTC_UNUSED;
/******************************************************************************
 **                        Function definitions
 ******************************************************************************/
/**
 * @brief Check if the inout parameters are valid.
 *
 * @param Time Pointer to RTC time.
 * @return Rtc_StatusType
 * @retval RTC_STATUS_OK param is valid
 * @retval RTC_STATUS_INVALID_PARAM param is invalid
 */
static Rtc_StatusType Rtc_InputTimeCheck(const Rtc_TimeType *Time)
{
    Rtc_StatusType rtcReturn = RTC_STATUS_OK;

    if (NULL_PTR == Time)
    {
        rtcReturn = RTC_STATUS_OK;
    }
    else if (((uint8_t)RTC_IM_SATURDAY < Time->Week))
    {
        rtcReturn = RTC_STATUS_INVALID_PARAM;
    }
    else if ((uint8_t)RTC_IM_HOUR_23 < Time->Hour)
    {
        rtcReturn = RTC_STATUS_INVALID_PARAM;
    }
    else if ((uint8_t)RTC_IM_MIN_59 < Time->Minute)
    {
        rtcReturn = RTC_STATUS_INVALID_PARAM;
    }
    else if ((uint8_t)RTC_IM_SEC_59 < Time->Second)
    {
        rtcReturn = RTC_STATUS_INVALID_PARAM;
    }
    else
    {
        /* Do Nothing */
    }

    return rtcReturn;
}

/**
 * @brief Determine whether a certain year is regular year or leap year.
 *
 * @param Year Year of format BCD.
 * @return bool
 * @retval true leap year
 * @retval false regular year
 */
static bool RTC_IsLeapYear(uint8_t Year)
{
    bool rtcReturn;

    uint32_t CertainYear = 2000U;
    /* PRQA S 3469 1 #KQR003469 */
    CertainYear += (uint32_t)RTC_BCD_TO_DEC(Year);
    if (0U == (CertainYear % 4U))
    {
        rtcReturn = true;
    }
    else
    {
        rtcReturn = false;
    }

    return rtcReturn;
}

/**
 * @brief Check if the inout parameters are valid.
 *
 * @param Date Pointer to RTC date.
 * @return Rtc_StatusType
 * @retval RTC_STATUS_OK
 * @retval RTC_STATUS_INVALID_PARAM param is invalid
 */
static Rtc_StatusType Rtc_InputDateCheck(const Rtc_DateType *Date)
{
    Rtc_StatusType rtcReturn = RTC_STATUS_OK;

    if (NULL_PTR == Date)
    {
        rtcReturn = RTC_STATUS_OK;
    }
    else if (0x99U < Date->Year)
    {
        /** @brief Format BCD, using 4-digit binary numbers to represent a decimal number. */
        rtcReturn = RTC_STATUS_INVALID_PARAM;
    }
    else if (((uint8_t)RTC_IM_DECEMBER < Date->Month) || ((uint8_t)RTC_IM_JANUARY > Date->Month))
    {
        rtcReturn = RTC_STATUS_INVALID_PARAM;
    }
    else
    {
        /** @brief The number of days included in different months is inconsistent. */
        switch ((Rtc_MonthEnumType)Date->Month)
        {
        case RTC_IM_FEBRUARY: {
            if (RTC_IsLeapYear(Date->Year))
            {
                if (((uint8_t)RTC_IM_DAY_29 < Date->Day) || ((uint8_t)RTC_IM_DAY_1 > Date->Day))
                {
                    rtcReturn = RTC_STATUS_INVALID_PARAM;
                }
                else
                {
                    /* Do Nothing */
                }
            }
            else
            {
                if (((uint8_t)RTC_IM_DAY_28 < Date->Day) || ((uint8_t)RTC_IM_DAY_1 > Date->Day))
                {
                    rtcReturn = RTC_STATUS_INVALID_PARAM;
                }
                else
                {
                    /* Do Nothing */
                }
            }
            break;
        }
        case RTC_IM_APRIL:
        case RTC_IM_JUNE:
        case RTC_IM_SEPTEMBER:
        case RTC_IM_NOVEMBER: {
            if (((uint8_t)RTC_IM_DAY_30 < Date->Day) || ((uint8_t)RTC_IM_DAY_1 > Date->Day))
            {
                rtcReturn = RTC_STATUS_INVALID_PARAM;
            }
            else
            {
                /* Do Nothing */
            }
            break;
        }
        default: {
            if (((uint8_t)RTC_IM_DAY_31 < Date->Day) || ((uint8_t)RTC_IM_DAY_1 > Date->Day))
            {
                rtcReturn = RTC_STATUS_INVALID_PARAM;
            }
            else
            {
                /* Do Nothing */
            }
            break;
        }
        }
    }

    return rtcReturn;
}

/**
 * @brief Check if the inout parameters are valid.
 *
 * @param RtcConfig Pointer to RTC configure.
 * @return Rtc_StatusType
 * @retval RTC_STATUS_OK check success
 * @retval RTC_STATUS_INVALID_PARAM param is invalid
 */
static Rtc_StatusType Rtc_InputParamCheck(const Rtc_ConfigType *RtcConfig)
{
    Rtc_StatusType rtcReturn = RTC_STATUS_OK;

    if (NULL_PTR == RtcConfig)
    {
        rtcReturn = RTC_STATUS_INVALID_PARAM;
    }
    else if (RTC_STATUS_OK != Rtc_InputDateCheck(RtcConfig->DateConfig))
    {
        rtcReturn = RTC_STATUS_INVALID_PARAM;
    }
    else if (RTC_STATUS_OK != Rtc_InputTimeCheck(RtcConfig->TimeConfig))
    {
        rtcReturn = RTC_STATUS_INVALID_PARAM;
    }
    else
    {
        /* Do Nothing */
    }

    return rtcReturn;
}

/**
 * @brief Initialise config time
 *
 * @param RtcConfig Pointer to RTC configure.
 * @param InitTimeStatus
 * true : Initialize time
 * false: Do not initialize time
 * @return Rtc_StatusType
 * @retval RTC_STATUS_OK Set time successfully
 * @retval RTC_STATUS_INVALID_TIME Pointer to time or date is a null pointer, set default time
 * @retval RTC_STATUS_CLOCK_ERR failed to active EXTLF
 */
static Rtc_StatusType Rtc_InitConfigTime(const Rtc_ConfigType *RtcConfig, boolean InitTimeStatus)
{
    Rtc_StatusType rtcReturn = RTC_STATUS_OK;
    /* PRQA S 4320,4895 5 #KQR004320 */
    Rtc_InitStructType rtcInitConfig = {
      /* 24 hour in default */
      .HourFormat = (bool)RTC_IM_24H,
      .ClkSrc     = RtcConfig->Clock,
    };
    if (NULL_PTR == RtcConfig->DateConfig)
    {
        rtcReturn = RTC_STATUS_INVALID_TIME;
    }
    else
    {
        rtcInitConfig.Year  = RtcConfig->DateConfig->Year;
        rtcInitConfig.Month = (Rtc_MonthEnumType)RtcConfig->DateConfig->Month;
        rtcInitConfig.Day   = (Rtc_DayEnumType)RtcConfig->DateConfig->Day;
    }

    if (NULL_PTR == RtcConfig->TimeConfig)
    {
        rtcReturn = RTC_STATUS_INVALID_TIME;
    }
    else
    {
        rtcInitConfig.Week   = (Rtc_WeekDayEnumType)RtcConfig->TimeConfig->Week;
        rtcInitConfig.Hour   = (Rtc_HourEnumType)RtcConfig->TimeConfig->Hour;
        rtcInitConfig.Minute = (Rtc_MinuteEnumType)RtcConfig->TimeConfig->Minute;
        rtcInitConfig.Second = (Rtc_SecondEnumType)RtcConfig->TimeConfig->Second;
    }

    if (RTC_EXTLF == rtcInitConfig.ClkSrc)
    {
        if (STATUS_OK != Rtc_Im_OscExtlfInit(0x2600000U))
        {
            rtcReturn = RTC_STATUS_CLOCK_ERR;
        }
        else
        {
            /* Do Nothing */
        }
    }
    else
    {
        /* Do Nothing */
    }

    if (RTC_STATUS_OK == rtcReturn)
    {
        Rtc_Im_EnableDateRegister();

        /* PRQA S 4340 1 #KQR004340 */
        if ((bool)InitTimeStatus)
        {
            if (Rtc_Im_Init(&rtcInitConfig) != STATUS_OK)
            {
                rtcReturn = RTC_STATUS_INVALID_PARAM;
            }
            else
            {
                /* Do Nothing */
            }
        }
        else
        {
            /* Do Nothing */
        }
    }
    else
    {
        /* Do Nothing */
    }

    return rtcReturn;
}

/**
 * @brief Initializes the Rtc hardware units and driver
 *
 * @param ConfigPtr Pointer to RTC configure.
 * @param InitTimeStatus
 * true : Initialize time
 * false: Do not initialize time
 */
FUNC(Rtc_StatusType, RTC_CODE)
Rtc_Init(P2CONST(Rtc_ConfigType, AUTOMATIC, RTC_APPL_CONST) ConfigPtr, VAR(boolean, RTC_VAR) InitTimeStatus)
{
    RTC_ASSERT(ConfigPtr != NULL_PTR);

    Rtc_StatusType rtcReturn;

    if (RTC_UNUSED != Rtc_State)
    {
        rtcReturn = RTC_STATUS_ALREADY_INITIALIZED;
    }
    else
    {
        rtcReturn = Rtc_InputParamCheck(ConfigPtr);

        if (RTC_STATUS_OK == rtcReturn)
        {
            rtcReturn = Rtc_InitConfigTime(ConfigPtr, InitTimeStatus);

            if (RTC_STATUS_CLOCK_ERR != rtcReturn)
            {
                Intr_ExitInitStructType RtcExitIntrInit = {
                  .Index          = INTR_EXTI_IM_INDEX_17,
                  .Mask           = true,
                  .FallEdgeEnable = false,
                  .RiseEdgeEnable = true,
                };
                (void)Rtc_Im_IntrExtiInit(&RtcExitIntrInit);

                Rtc_AlarmPreInit();
                Rtc_Im_SetAlarmCallBack(RTC_ALARM_A, ConfigPtr->AlarmACallback);
                Rtc_Im_SetAlarmCallBack(RTC_ALARM_B, ConfigPtr->AlarmBCallback);

                Rtc_Im_Enable(true);
                Rtc_State = RTC_RUN;
            }
            else
            {
                /* Do Nothing */
            }
        }
        else
        {
            /* Do Nothing */
        }
    }

    return rtcReturn;
}

/**
 * @brief De-initialize RTC
 */
FUNC(void, RTC_CODE) Rtc_DeInit(VAR(void, RTC_VAR))
{
    Rtc_AlarmPreInit();

    Rtc_State = RTC_UNUSED;
}

/**
 * @brief Set RTC time.
 *
 * @param DateTimePtr Pointer to RTC time.
 * @return Std_ReturnType
 */
FUNC(Std_ReturnType, RTC_CODE) Rtc_SetDateTime(P2CONST(Rtc_DateTimeType, RTC_VAR, RTC_APPL_CONST) DateTimePtr)
{
    RTC_ASSERT(DateTimePtr != NULL_PTR);

    Std_ReturnType rtcReturn = E_NOT_OK;
    /* PRQA S 2203 ++ #KQR002203 */
    Rtc_DateType DateConfig = {.Year = DateTimePtr->Year, .Month = DateTimePtr->Month, .Day = DateTimePtr->Day};
    Rtc_TimeType TimeConfig = {
      .Week   = DateTimePtr->Week,
      .Hour   = DateTimePtr->Hour,
      .Minute = DateTimePtr->Minute,
      .Second = DateTimePtr->Second};
    /* PRQA S 2203 -- #KQR002203 */
    if ((RTC_STATUS_OK == Rtc_InputDateCheck(&DateConfig)) && (RTC_STATUS_OK == Rtc_InputTimeCheck(&TimeConfig)))
    {
        if (RTC_UNUSED != Rtc_State)
        {
            Rtc_Im_SetDataTime(&DateConfig, &TimeConfig);

            /* delay for update */
            /* PRQA S 3387 1 #KQR003387 */
            for (volatile uint32_t i = 0U; i < 3750U; i++)
            {
                /* PRQA S 1006 1 #KQR101006 */
                NOP();
            }

            if (Rtc_Im_CheckAndReWriteDataAndTime(
                  DateConfig.Year, DateConfig.Month, DateConfig.Day, TimeConfig.Week, TimeConfig.Hour,
                  TimeConfig.Minute, TimeConfig.Second))
            {
                rtcReturn = E_OK;
            }
            else
            {
                /* Do Nothing */
            }
        }
        else
        {
            /* Do Nothing */
        }
    }
    else
    {
        /* Do Nothing */
    }

    return rtcReturn;
}

/**
 * @brief Get RTC time.
 *
 * @param TimePtr Pointer to where store the time
 * @return void
 */
/* PRQA S 3432 1 #KQR003432 */
FUNC(void, RTC_CODE) Rtc_GetDateTime(P2VAR(Rtc_DateTimeType, AUTOMATIC, OCU_APPL_DATA) TimePtr)
{
    RTC_ASSERT(TimePtr != NULL_PTR);
    Rtc_Im_GetDateAndTime(TimePtr);
}

/**
 * @brief Config alarm. Repeat every day.
 *
 * @param AlarmIndex Index of alarm.
 * @param AlarmTimePtr Pointer to structure of alarm.
 * @param AlarmRepeatType alarm type
 * @return Std_ReturnType
 */
FUNC(Std_ReturnType, RTC_CODE)
Rtc_SetAlarm(VAR(Rtc_IndexType, RTC_VAR) AlarmIndex, VAR(Rtc_AlarmRepeatType, RTC_VAR) AlarmRepeatType,
             P2CONST(Rtc_TimeType, RTC_VAR, RTC_APPL_CONST) AlarmTimePtr)
{
    RTC_ASSERT(AlarmTimePtr != NULL_PTR);
    RTC_ASSERT(AlarmIndex < RTC_ALARM_MAX_INDEX);
    RTC_ASSERT((AlarmRepeatType == RTC_ALARM_REPEAT_DAY) || (AlarmRepeatType == RTC_ALARM_REPEAT_WEEK));

    Std_ReturnType rtcReturn = E_NOT_OK;

    if (RTC_STATUS_OK == Rtc_InputTimeCheck(AlarmTimePtr))
    {
        Rtc_AlarmStructType alarmConfig = {
          .AlarmIndex = (uint8_t)AlarmIndex,
          .Week       = (Rtc_WeekDayEnumType)AlarmTimePtr->Week,
          .Hour       = (Rtc_HourEnumType)AlarmTimePtr->Hour,
          .Minute     = (Rtc_MinuteEnumType)AlarmTimePtr->Minute,
          .Second     = (Rtc_SecondEnumType)AlarmTimePtr->Second,
          .RepeatType = (Rtc_AlarmRepeatEnumType)AlarmRepeatType,
        };

        if (RTC_UNUSED != Rtc_State)
        {
            if (Rtc_Im_SetAlarm(&alarmConfig) != STATUS_OK)
            {
                /* Do Nothing */
            }
            else
            {
                rtcReturn = E_OK;
            }
        }
        else
        {
            /* Do Nothing */
        }
    }
    else
    {
        /* Do Nothing */
    }

    return rtcReturn;
}

/**
 * @brief Enable alarm.
 *
 * @param AlarmIndex Index of alarm.
 * @return Std_ReturnType
 */
FUNC(Std_ReturnType, RTC_CODE) Rtc_EnableAlarm(VAR(Rtc_IndexType, RTC_VAR) AlarmIndex)
{
    RTC_ASSERT(AlarmIndex < RTC_ALARM_MAX_INDEX);

    Std_ReturnType rtcReturn = E_OK;

    if (RTC_UNUSED != Rtc_State)
    {
        Rtc_Im_AlarmEnable(AlarmIndex, true);
    }
    else
    {
        rtcReturn = E_NOT_OK;
    }
    return rtcReturn;
}

/**
 * @brief Disable alarm.
 *
 * @param AlarmIndex Index of alarm.
 * @return Std_ReturnType
 */
FUNC(Std_ReturnType, RTC_CODE) Rtc_DisableAlarm(VAR(Rtc_IndexType, RTC_VAR) AlarmIndex)
{
    RTC_ASSERT(AlarmIndex < RTC_ALARM_MAX_INDEX);

    Std_ReturnType rtcReturn = E_OK;

    if (RTC_UNUSED != Rtc_State)
    {
        Rtc_Im_AlarmEnable(AlarmIndex, false);
    }
    else
    {
        rtcReturn = E_NOT_OK;
    }
    return rtcReturn;
}
/* EOF */
