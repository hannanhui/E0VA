/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Rtc_Im.c
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
/* PRQA S 1006 EOF #KQR101006 */
/* PRQA S 4322 EOF #KQR004322 */
/* PRQA S 4342 EOF #KQR004342 */
/* PRQA S 2814 EOF #KQR002814 */
/* PRQA S 2201 EOF #KQR002201 */
/* PRQA S 4899 EOF #KQR004899 */
/* PRQA S 3383 EOF #KQR003383 */
/******************************************************************************
 **                        Include Files
 ******************************************************************************/
#include <stdint.h>
#include <stdbool.h>
#include "kf_types.h"
#include "dev_assert.h"

#include "kf32a158sf_drv_bkp.h"
#include "kf32a158sf_drv_osc.h"
#include "kf32a158sf_drv_pm.h"
#include "kf32a158sf_drv_intr.h"
#include "kf32a158sf_drv_rtc.h"
#include "Rtc_Im.h"

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
 **                        Export Variables
 ******************************************************************************/

/******************************************************************************
 **                        Export Functions
 ******************************************************************************/

/******************************************************************************
 **                        Variables
 ******************************************************************************/
/**
 * @brief Alarm_A callback
 */
static RTC_InterruptHandler Rtc_AlarmACallback = NULL_PTR;

/**
 * @brief Alarm_B callback
 */
static RTC_InterruptHandler Rtc_AlarmBCallback = NULL_PTR;
/******************************************************************************
 **                      Public Functions
 ******************************************************************************/
/**
 * @brief rtc alarm pre init
 */
void Rtc_AlarmPreInit(void)
{
    Bkp_LL_HandleStart();
    Rtc_LL_SetConfigFlag(RTC_PTR, true);
    Rtc_LL_SetEnabled(RTC_PTR, false);
    Rtc_LL_SetAlarmAEnabled(RTC_PTR, false);
    Rtc_LL_SetAlarmBEnabled(RTC_PTR, false);
    Rtc_LL_ClearIntrFlag(RTC_PTR, RTC_INTR_CLEAR_ALRAIC);
    Rtc_LL_ClearIntrFlag(RTC_PTR, RTC_INTR_CLEAR_ALRBIC);
    Rtc_LL_ClearIntrFlag(RTC_PTR, RTC_INTR_CLEAR_TTIC);
    Rtc_LL_SetIntrEnabled(RTC_PTR, RTC_INTR_SET_TTIE, false);
    Rtc_LL_SetConfigFlag(RTC_PTR, false);
    Bkp_LL_HandleEnd();
}

/**
 * @brief enable or disable rtc
 * @param EnableSta
 * @retval void
 */
void Rtc_Im_Enable(bool EnableSta)
{
    Bkp_LL_HandleStart();
    Rtc_LL_SetEnabled(RTC_PTR, EnableSta);
    Bkp_LL_HandleEnd();
}

/**
 * @brief set rtc data and time
 *
 * @param DateConfig data config pointer
 * @param TimeConfig time config pointer
 */
void Rtc_Im_SetDataTime(const Rtc_DateType *DateConfig, const Rtc_TimeType *TimeConfig)
{
    Bkp_LL_HandleStart();
    Rtc_LL_SetEnabled(RTC_PTR, false);
    Rtc_LL_SetConfigFlag(RTC_PTR, true);

    Rtc_LL_SetYear(RTC_PTR, DateConfig->Year);
    Rtc_LL_SetMonth(RTC_PTR, (Rtc_Month_t)DateConfig->Month);
    Rtc_LL_SetDay(RTC_PTR, (Rtc_Day_t)DateConfig->Day);
    Rtc_LL_SetWeek(RTC_PTR, (Rtc_WeekDay_t)TimeConfig->Week);
    Rtc_LL_SetHours(RTC_PTR, (Rtc_Hour_t)TimeConfig->Hour);
    Rtc_LL_SetMinutes(RTC_PTR, (Rtc_Minute_t)TimeConfig->Minute);
    Rtc_LL_SetSeconds(RTC_PTR, (Rtc_Second_t)TimeConfig->Second);

    Rtc_LL_SetConfigFlag(RTC_PTR, false);
    Rtc_LL_SetEnabled(RTC_PTR, true);
    Bkp_LL_HandleEnd();
}

/**
 * @brief Enable Date Register
 */
void Rtc_Im_EnableDateRegister(void)
{
    // Enable backup domain (BKP) data register read and write
    Bkp_LL_EnableDataRegisterReadWrite();
}

/**
 * @brief initialize rtc information
 * @param RtcInitStruct rtc init struct pointer
 * @retval kf_status_t
 */
kf_status_t Rtc_Im_Init(const Rtc_InitStructType *RtcInitStruct)
{
    kf_status_t Ret = STATUS_OK;

    if (NULL_PTR == RtcInitStruct)
    {
        Ret = STATUS_ERROR;
    }
    else
    {
        Bkp_LL_HandleStart();
        Rtc_LL_SetConfigFlag(RTC_PTR, true);

        Rtc_LL_Initialise(RTC_PTR);

        Bkp_LL_SetRtcClkSel(BKP_PTR, (Bkp_RtcClkSrc_t)RtcInitStruct->ClkSrc);
        Rtc_LL_SetHourFormat(RTC_PTR, RtcInitStruct->HourFormat);
        Rtc_LL_SetYear(RTC_PTR, RtcInitStruct->Year);
        Rtc_LL_SetMonth(RTC_PTR, (Rtc_Month_t)RtcInitStruct->Month);
        Rtc_LL_SetDay(RTC_PTR, (Rtc_Day_t)RtcInitStruct->Day);
        Rtc_LL_SetWeek(RTC_PTR, (Rtc_WeekDay_t)RtcInitStruct->Week);
        Rtc_LL_SetHours(RTC_PTR, (Rtc_Hour_t)RtcInitStruct->Hour);
        Rtc_LL_SetMinutes(RTC_PTR, (Rtc_Minute_t)RtcInitStruct->Minute);
        Rtc_LL_SetSeconds(RTC_PTR, (Rtc_Second_t)RtcInitStruct->Second);
        Rtc_LL_SetAmPm(RTC_PTR, RtcInitStruct->AmOrPm);

        Rtc_LL_SetConfigFlag(RTC_PTR, false);

        /* Keep External Low Frequency */
        if (RTC_EXTLF == RtcInitStruct->ClkSrc)
        {
            Pm_LL_SetExternalLowFrequencyEnabled(true);
        }
        else
        {
            /* Do Nothing */
        }

        Bkp_LL_HandleEnd();

        if (!Rtc_Im_CheckAndReWriteDataAndTime(
              RtcInitStruct->Year, (uint8_t)RtcInitStruct->Month, (uint8_t)RtcInitStruct->Day,
              (uint8_t)RtcInitStruct->Week, (uint8_t)RtcInitStruct->Hour, (uint8_t)RtcInitStruct->Minute,
              (uint8_t)RtcInitStruct->Second))
        {
            Ret = STATUS_ERROR;
        }
        else
        {
            /* Do Nothing */
        }
    }

    return Ret;
}

/**
 * @brief check rtc set data and time
 *
 * @retval true:check success
 * @retval false:check and rewrite failed
 */
bool Rtc_Im_CheckAndReWriteDataAndTime(
  uint8_t Year, uint8_t Month, uint8_t Day, uint8_t Week, uint8_t Hour, uint8_t Minute, uint8_t Second)
{
    bool    RetValue    = true;
    uint8_t retryNumber = 3U;

    Bkp_LL_HandleStart();
    do
    {
        if ((RTC_PTR->DTR.bits.YEAR != Year) || (RTC_PTR->DTR.bits.MTH != Month) || (RTC_PTR->DTR.bits.DAY != Day) ||
            (RTC_PTR->TMR.bits.WEK != Week) || (RTC_PTR->TMR.bits.HOUR != Hour) || (RTC_PTR->TMR.bits.MIN != Minute) ||
            (RTC_PTR->TMR.bits.SEC != Second))
        {
            retryNumber--;
            Rtc_LL_SetEnabled(RTC_PTR, false);
            Rtc_LL_SetConfigFlag(RTC_PTR, true);
            Rtc_LL_SetYear(RTC_PTR, Year);
            Rtc_LL_SetMonth(RTC_PTR, (Rtc_Month_t)Month);
            Rtc_LL_SetDay(RTC_PTR, (Rtc_Day_t)Day);
            Rtc_LL_SetWeek(RTC_PTR, (Rtc_WeekDay_t)Week);
            Rtc_LL_SetHours(RTC_PTR, (Rtc_Hour_t)Hour);
            Rtc_LL_SetMinutes(RTC_PTR, (Rtc_Minute_t)Minute);
            Rtc_LL_SetSeconds(RTC_PTR, (Rtc_Second_t)Second);
            Rtc_LL_SetConfigFlag(RTC_PTR, false);
            Rtc_LL_SetEnabled(RTC_PTR, true);
            /* delay for update */
            /* PRQA S 3387 1 #KQR003387 */
            for (volatile uint32_t i = 0U; i < 3750U; i++)
            {
                NOP();
            }
        }
        else
        {
            break;
        }

    } while (retryNumber > 0U);
    Bkp_LL_HandleEnd();

    if (retryNumber == 0U)
    {
        RetValue = false;
    }
    else
    {
        /* Do Nothing */
    }

    return RetValue;
}

/**
 * @brief get rtc data and time
 *
 * @param RtcDate data pointer
 */
void Rtc_Im_GetDateAndTime(Rtc_DateTimeType *RtcDate)
{
    Bkp_LL_HandleStart();
    RtcDate->Year   = RTC_PTR->DTR.bits.YEAR;
    RtcDate->Month  = RTC_PTR->DTR.bits.MTH;
    RtcDate->Day    = RTC_PTR->DTR.bits.DAY;
    RtcDate->Week   = RTC_PTR->TMR.bits.WEK;
    RtcDate->Hour   = RTC_PTR->TMR.bits.HOUR;
    RtcDate->Minute = RTC_PTR->TMR.bits.MIN;
    RtcDate->Second = RTC_PTR->TMR.bits.SEC;
    Bkp_LL_HandleEnd();
}

/**
 * @brief set rtc alarm time
 * @param AlarmStruct alarm information pointer
 * @retval kf_status_t
 */
kf_status_t Rtc_Im_SetAlarm(const Rtc_AlarmStructType *AlarmStruct)
{
    kf_status_t Ret = STATUS_OK;

    if (NULL_PTR == AlarmStruct)
    {
        Ret = STATUS_ERROR;
    }
    else
    {
        Bkp_LL_HandleStart();
        Rtc_LL_SetConfigFlag(RTC_PTR, true);

        switch (AlarmStruct->AlarmIndex)
        {
        case (uint8_t)RTC_ALARM_A:
            /* Set alarm repeat mode */
            Rtc_LL_SetAlarmASecondEnabled(RTC_PTR, (0U != ((uint32_t)AlarmStruct->RepeatType & 0x1U)));
            Rtc_LL_SetAlarmAMinuteEnabled(RTC_PTR, (0U != ((uint32_t)AlarmStruct->RepeatType & 0x2U)));
            Rtc_LL_SetAlarmAHourEnabled(RTC_PTR, (0U != ((uint32_t)AlarmStruct->RepeatType & 0x4U)));
            Rtc_LL_SetAlarmAWeekdayEnabled(RTC_PTR, (0U != ((uint32_t)AlarmStruct->RepeatType & 0x8U)));
            /* Set alarm time */
            Rtc_LL_SetAlarmAWeekTime(RTC_PTR, (Rtc_WeekDay_t)AlarmStruct->Week);
            Rtc_LL_SetAlarmAHourTime(RTC_PTR, (Rtc_Hour_t)AlarmStruct->Hour);
            Rtc_LL_SetAlarmAMinutesTime(RTC_PTR, (Rtc_Minute_t)AlarmStruct->Minute);
            Rtc_LL_SetAlarmASecondTime(RTC_PTR, (Rtc_Second_t)AlarmStruct->Second);
            Rtc_LL_SelectAlarmAAmPm(RTC_PTR, AlarmStruct->AmOrPm);
            break;
        case (uint8_t)RTC_ALARM_B:
            /* Set alarm repeat mode */
            Rtc_LL_SetAlarmBSecondEnabled(RTC_PTR, (0U != ((uint32_t)AlarmStruct->RepeatType & 0x1U)));
            Rtc_LL_SetAlarmBMinuteEnabled(RTC_PTR, (0U != ((uint32_t)AlarmStruct->RepeatType & 0x2U)));
            Rtc_LL_SetAlarmBHourEnabled(RTC_PTR, (0U != ((uint32_t)AlarmStruct->RepeatType & 0x4U)));
            Rtc_LL_SetAlarmBWeekdayEnabled(RTC_PTR, (0U != ((uint32_t)AlarmStruct->RepeatType & 0x8U)));
            /* Set alarm time */
            Rtc_LL_SetAlarmBWeekTime(RTC_PTR, (Rtc_WeekDay_t)AlarmStruct->Week);
            Rtc_LL_SetAlarmBHourTime(RTC_PTR, (Rtc_Hour_t)AlarmStruct->Hour);
            Rtc_LL_SetAlarmBMinutesTime(RTC_PTR, (Rtc_Minute_t)AlarmStruct->Minute);
            Rtc_LL_SetAlarmBSecondTime(RTC_PTR, (Rtc_Second_t)AlarmStruct->Second);
            Rtc_LL_SelectAlarmBAmPm(RTC_PTR, AlarmStruct->AmOrPm);
            break;

        default:
            Ret = STATUS_ERROR;
            break;
        }

        Rtc_LL_SetConfigFlag(RTC_PTR, false);
        Bkp_LL_HandleEnd();
    }

    return Ret;
}

/**
 * @brief enable or disable alarm
 * @param AlarmIndex alarm index
 * @param EnableSta enable or disable
 * @retval void
 */
void Rtc_Im_AlarmEnable(Rtc_IndexType AlarmIndex, bool EnableSta)
{
    Bkp_LL_HandleStart();

    switch (AlarmIndex)
    {
    case RTC_ALARM_A:
        Rtc_LL_SetAlarmAEnabled(RTC_PTR, EnableSta);
        Rtc_LL_ClearIntrFlag(RTC_PTR, RTC_INTR_CLEAR_ALRAIC);
        Rtc_LL_SetIntrEnabled(RTC_PTR, RTC_INTR_SET_ALRAIE, EnableSta);
        break;
    case RTC_ALARM_B:
        Rtc_LL_SetAlarmBEnabled(RTC_PTR, EnableSta);
        Rtc_LL_ClearIntrFlag(RTC_PTR, RTC_INTR_CLEAR_ALRBIC);
        Rtc_LL_SetIntrEnabled(RTC_PTR, RTC_INTR_SET_ALRBIE, EnableSta);
        break;

    default:
        (void)0U;
        break;
    }
    Bkp_LL_HandleEnd();
}

/**
 * @brief clear Rtc interrupt flag
 * @param IntrIndex rtc interrupt index
 * @retval void
 */
void Rtc_Im_ClearIntrFlag(Rtc_IntrIndexEnumType IntrIndex)
{
    uint32_t IntrClearIndex;

    Bkp_LL_HandleStart();
    IntrClearIndex = (uint32_t)IntrIndex + 16U;
    Rtc_LL_ClearIntrFlag(RTC_PTR, (Rtc_IntrClearIndex_t)IntrClearIndex);
    Bkp_LL_HandleEnd();
}

/**
 * @brief get Rtc interrupt flag
 * @param IntrIndex rtc interrupt index
 * @retval void
 */
bool Rtc_Im_GetIntrFlag(Rtc_IntrIndexEnumType IntrIndex)
{
    bool Ret;

    Bkp_LL_HandleStart();
    Ret = Rtc_LL_GetIntrFlag(RTC_PTR, (Rtc_IntrGetIndex_t)IntrIndex);
    Bkp_LL_HandleEnd();

    return Ret;
}

/**
 * @brief set rtc tick time
 *
 * @param TickTime
 * @retval void
 */
void Rtc_Im_SetTickTime(Rtc_TickTimeEnumType TickTime)
{
    Bkp_LL_HandleStart();
    Rtc_LL_SetConfigFlag(RTC_PTR, true);
    Rtc_LL_SetTickTime(RTC_PTR, (Rtc_TickTime_t)TickTime);
    Rtc_LL_SetConfigFlag(RTC_PTR, false);
    Bkp_LL_HandleEnd();
}

/**
 * @brief set alarm callback function
 *
 * @param AlarmIndex alarm index
 * @param callbackFnc callback function
 */
void Rtc_Im_SetAlarmCallBack(Rtc_IndexType AlarmIndex, RTC_InterruptHandler callbackFnc)
{
    if (AlarmIndex == RTC_ALARM_A)
    {
        Rtc_AlarmACallback = callbackFnc;
    }
    else if (AlarmIndex == RTC_ALARM_B)
    {
        Rtc_AlarmBCallback = callbackFnc;
    }
    else
    {
        /* Do Nothing */
    }
}

/**
 * @brief external low frequency oscillator init
 * @param Timeout
 * @retval kf_status_t
 */
kf_status_t Rtc_Im_OscExtlfInit(uint32_t Timeout)
{
    uint32_t    kvTimeCount = 0;
    kf_status_t kvRet       = STATUS_ERROR;

    if (Osc_LL_GetIntrFlag(OSC_INTR_GET_ELFIF) == true)
    {
        kvRet = STATUS_OK;
    }

    if (kvRet != STATUS_OK)
    {
        Osc_LL_SetExtlfStartDelay(OSC_EXT_START_DELAY_65536);
        Osc_LL_ClearIntrFlag(OSC_INTR_CLEAR_ELFIF);
        Osc_LL_SetExtlfSoftwareEnabled(true);

        kvRet = STATUS_OK;

        while (Osc_LL_GetIntrFlag(OSC_INTR_GET_ELFIF) != true)
        {
            /* If Timeout is 0, no timeout will be executed. */
            if (Timeout == 0U)
            {
                continue;
            }
            /* PRQA S 3440 1 #KQR003440 */
            if (kvTimeCount++ >= Timeout)
            {
                kvRet = STATUS_ERROR;
                break;
            }
        }
    }

    return kvRet;
}

/**
 * @brief Initialization of External Interrupt Line
 *
 * @param ExtiInitStruct
 * @retval kf_status_t
 */
kf_status_t Rtc_Im_IntrExtiInit(const Intr_ExitInitStructType *const ExtiInitStruct)
{
    kf_status_t Ret = STATUS_OK;

    if (NULL_PTR == ExtiInitStruct)
    {
        Ret = STATUS_ERROR;
    }
    else
    {
        if (ExtiInitStruct->HiLevelEnable)
        {
            Intr_LL_SetExtiHiLevelEnabled((Intr_ExtiIndex_t)ExtiInitStruct->Index, true);
            Intr_LL_SetExtiMaskValue((Intr_ExtiIndex_t)ExtiInitStruct->Index, ExtiInitStruct->Mask);
        }
        else
        {
            Intr_LL_SetExtiHiLevelEnabled((Intr_ExtiIndex_t)ExtiInitStruct->Index, false);
            Intr_LL_SetExtiMaskValue((Intr_ExtiIndex_t)ExtiInitStruct->Index, ExtiInitStruct->Mask);
            Intr_LL_SetExtiRiseEdgeEnabled((Intr_ExtiIndex_t)ExtiInitStruct->Index, ExtiInitStruct->RiseEdgeEnable);
            Intr_LL_SetExtiFallEdgeEnabled((Intr_ExtiIndex_t)ExtiInitStruct->Index, ExtiInitStruct->FallEdgeEnable);
        }

        Intr_LL_ClearExtiFlag((Intr_ExtiIndex_t)ExtiInitStruct->Index);
    }

    return Ret;
}

/**
 * @brief RTC interrupt handler
 *
 * @param void
 * @return void
 */
void Rtc_Im_Isr(void)
{
    uint32_t rtcIntrReg;

    Bkp_LL_HandleStart();
    rtcIntrReg = RTC_PTR->IER.reg;
    Bkp_LL_HandleEnd();

#if 0
    /** Tick Time */
    /* PRQA S 3415 2 #KQR003415 */
    if (((rtcIntrReg & ((uint32_t)1U << (uint32_t)RTC_INTR_SET_TTIE)) != 0U) &&
        (Rtc_Im_GetIntrFlag(RTC_INTR_INDEX_TICK_TIME)))
    {
        Rtc_Im_ClearIntrFlag(RTC_INTR_INDEX_TICK_TIME);
        Rtc_TickTimeCallback();
    }
    else
    {
        /* Do Nothing */
    }
#endif
    /** ALARM_A */
    /* PRQA S 3415 2 #KQR003415 */
    if (((rtcIntrReg & ((uint32_t)1U << (uint32_t)RTC_INTR_SET_ALRAIE)) != 0U) &&
        (Rtc_Im_GetIntrFlag(RTC_INTR_INDEX_ALARM_A)))
    {
        Rtc_Im_ClearIntrFlag(RTC_INTR_INDEX_ALARM_A);
        if (NULL_PTR != Rtc_AlarmACallback)
        {
            Rtc_AlarmACallback();
        }
    }
    else
    {
        /* Do Nothing */
    }
    /** ALARM_B */
    /* PRQA S 3415 2 #KQR003415 */
    if (((rtcIntrReg & ((uint32_t)1U << (uint32_t)RTC_INTR_SET_ALRBIE)) != 0U) &&
        (Rtc_Im_GetIntrFlag(RTC_INTR_INDEX_ALARM_B)))
    {
        Rtc_Im_ClearIntrFlag(RTC_INTR_INDEX_ALARM_B);
        if (NULL_PTR != Rtc_AlarmBCallback)
        {
            Rtc_AlarmBCallback();
        }
    }
    else
    {
        /* Do Nothing */
    }
}

/**
 * @brief Get the interrupt flag for an external interrupt line.
 *
 * @param Index The index of the external interrupt, see Intr_ExtiIndexEnumType for details.
 * @retval bool
 */
bool Rtc_Im_IntrGetExtiFlag(Intr_ExtiIndexEnumType Index)
{
    return Intr_LL_GetExtiFlag((Intr_ExtiIndex_t)Index);
}

/**
 * @brief Clear the interrupt flag for an external interrupt line.
 *
 * @param Index The index of the external interrupt, see Intr_ExtiIndexEnumType for details.
 * @retval void
 */
void Rtc_Im_IntrClearExtiFlag(Intr_ExtiIndexEnumType Index)
{
    Intr_LL_ClearExtiFlag((Intr_ExtiIndex_t)Index);
}
/* EOF */
