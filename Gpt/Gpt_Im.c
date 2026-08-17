/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Gpt_Im.c
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
/* PRQA S 2814 EOF #KQR002814 */
/* PRQA S 2824 EOF #KQR002824 */
/* PRQA S 2844 EOF #KQR002844 */
/* PRQA S 2201 EOF #KQR002201 */
/* PRQA S 4899 EOF #KQR004899 */
/* PRQA S 3383 EOF #KQR003383 */
/******************************************************************************
 **                        Include Files
 ******************************************************************************/
#include "Gpt_Im.h"
#include "dev_assert.h"
#include "kf32a158sf_drv_gptimer.h"
#include "kf32a158sf_drv_pclk.h"
#include "kf32a158sf_drv_intr.h"
#include "kf32a158sf_drv_rst.h"
#ifdef GPT_INTERNAL_TRACE_LOGGER
#include "kflog.h"
KF_REG_LOG(GPT_IM, KF_LOG_OPT_LINE);
#endif

/******************************************************************************
 **                        File Version Check
 ******************************************************************************/

/******************************************************************************
 **                        Macro  Definitions
 ******************************************************************************/

/******************************************************************************
 **                        Typedef  Definitions
 ******************************************************************************/
typedef struct
{
    /** @brief Timer Base Ptr */
    kpGTRegM BasePtr;
} Gpt_HwDesc_t;
/******************************************************************************
 **                      Variables
 ******************************************************************************/

/**
 * @brief Array of data structure storing logic channel mapped hardware timer
 * channel address
 */
/* PRQA S 2203 ++ #KQR002203 */
static const Gpt_HwDesc_t Gpt_Hw_Info[GPT_MAX_CHANNELS] = {
  /* T0 */
  {T0_PTR},
  /* T1 */
  {T1_PTR},
  /* T2 */
  {T2_PTR},
  /* T3 */
  {T3_PTR},
  /* T4 */
  {T4_PTR},
  /* T20 */
  {T20_PTR},
  /* T21 */
  {T21_PTR}};
/* PRQA S 2203 -- #KQR002203 */
/******************************************************************************
 **                        Export Variables
 ******************************************************************************/

/******************************************************************************
 **                        Export Functions
 ******************************************************************************/

/******************************************************************************
 **                      Function definitions
 ******************************************************************************/

/**
 * @brief
 *
 * @param ChanIdx
 * @retval void
 */
static void Gpt_Im_ExitFromResetMode(const Gpt_TimerEnumType ChanIdx)
{
    switch (ChanIdx)
    {
    case GPT_GPTIMER_CHAN_T0: {
        Rst_LL_SetTimerEnabled(RST_T0, false);
        Rst_LL_SetTimerEnabled(RST_T0, true);
        Pclk_LL_SetTimerEnabled(PCLK_T0, true);
    }
    break;
    case GPT_GPTIMER_CHAN_T1: {
        Rst_LL_SetTimerEnabled(RST_T1, false);
        Rst_LL_SetTimerEnabled(RST_T1, true);
        Pclk_LL_SetTimerEnabled(PCLK_T1, true);
    }
    break;
    case GPT_GPTIMER_CHAN_T2: {
        Rst_LL_SetTimerEnabled(RST_T2, false);
        Rst_LL_SetTimerEnabled(RST_T2, true);
        Pclk_LL_SetTimerEnabled(PCLK_T2, true);
    }
    break;
    case GPT_GPTIMER_CHAN_T3: {
        Rst_LL_SetTimerEnabled(RST_T3, false);
        Rst_LL_SetTimerEnabled(RST_T3, true);
        Pclk_LL_SetTimerEnabled(PCLK_T3, true);
    }
    break;
    case GPT_GPTIMER_CHAN_T4: {
        Rst_LL_SetTimerEnabled(RST_T4, false);
        Rst_LL_SetTimerEnabled(RST_T4, true);
        Pclk_LL_SetTimerEnabled(PCLK_T4, true);
    }
    break;
    case GPT_GPTIMER_CHAN_T20: {
        Rst_LL_SetTimerEnabled(RST_T20, false);
        Rst_LL_SetTimerEnabled(RST_T20, true);
        Pclk_LL_SetTimerEnabled(PCLK_T20, true);
    }
    break;
    case GPT_GPTIMER_CHAN_T21: {
        Rst_LL_SetTimerEnabled(RST_T21, false);
        Rst_LL_SetTimerEnabled(RST_T21, true);
        Pclk_LL_SetTimerEnabled(PCLK_T21, true);
    }
    break;
    default:
        GPT_DEV_ASSERT(false);
        break;
    }
}

/**
 * @brief Initialize Chip Hardware Timer Channel
 *
 * @param ChanHwIdx HW Channel Index
 * @param ClkSrc HW Channel Clock Source
 * @param ClkPrescale HW Channel Clock Prescaler
 *
 */
void Gpt_Im_Init(const Gpt_TimerEnumType ChanHwIdx, const Gpt_ClkSourceType ClkSrc, const uint32 ClkPrescale)
{
    Gpt_HwDesc_t hwDesc = Gpt_Hw_Info[(uint32)ChanHwIdx];

    /* Module Exit Reset Mode */
    Gpt_Im_ExitFromResetMode(ChanHwIdx);
    /* Set Module Clock Source */
    /* PRQA S 4322 1 #KQR004322 */
    GPTimer_LL_SetClkSrc(hwDesc.BasePtr, (Timer_ClockSource_t)ClkSrc);
    /* Set Module Prescaler */
    if (ClkPrescale > 0U)
    {
        GPTimer_LL_SetPrescaler(hwDesc.BasePtr, ClkPrescale - 1U);
    }
    else
    {
        GPTimer_LL_SetPrescaler(hwDesc.BasePtr, 0U);
    }
    /* Set Module to Clocking Mode */
    GPTimer_LL_SetWorkingMode(hwDesc.BasePtr, TIMING_MODE);
    /* Configure the synchronous reading counter to make the ability bit */
    GPTimer_LL_SetSyncReadTimerEnabled(hwDesc.BasePtr, true);
#ifdef GPT_INTERNAL_TRACE_LOGGER
    KFLOG_D(GPT_IM, "Gpt Timer %d is Started.\n", ChanHwIdx);
#endif
}

/**
 * @brief Deinit Hardware Channel, Release Resources
 *
 * @param chanHwIdx Hw Channel ID
 */
void Gpt_Im_Deinit(const Gpt_TimerEnumType ChanHwIdx)
{
    Gpt_HwDesc_t hwDesc = Gpt_Hw_Info[(uint32)ChanHwIdx];

    /* Stop Module */
    GPTimer_LL_Stop(hwDesc.BasePtr);
    /* Disable Module Interrupt */
    GPTimer_LL_SetOverFlowIntrEnabled(hwDesc.BasePtr, false);
    /* Clear Module Interrupt Flag */
    GPTimer_LL_ClearOverflowIntrFlag(hwDesc.BasePtr);
#ifdef GPT_INTERNAL_TRACE_LOGGER
    KFLOG_D(GPT_IM, "Gpt Timer %d is Stopped.\n", ChanHwIdx);
#endif
}

/**
 * @brief Enable Module Overflow Interrupt
 *
 * @param ChanHwIdx
 */
void Gpt_Im_EnableInterrupt(const Gpt_TimerEnumType ChanHwIdx)
{
    Gpt_HwDesc_t hwDesc = Gpt_Hw_Info[(uint32)ChanHwIdx];

    /* Disable Interrupt first to avoid being set incorrectly after clearing the interrupt flag */
    GPTimer_LL_SetOverFlowIntrEnabled(hwDesc.BasePtr, false);
    /* then Clear the interrupt flag bit */
    GPTimer_LL_ClearOverflowIntrFlag(hwDesc.BasePtr);
    /* Reenable Interrupt in the end */
    GPTimer_LL_SetOverFlowIntrEnabled(hwDesc.BasePtr, true);
}

/**
 * @brief Disable Channel Interrupt
 *
 * @param ChanHwIdx
 */
void Gpt_Im_DisableInterrupt(const Gpt_TimerEnumType ChanHwIdx)
{
    Gpt_HwDesc_t hwDesc = Gpt_Hw_Info[(uint32)ChanHwIdx];

    GPTimer_LL_ClearOverflowIntrFlag(hwDesc.BasePtr);
    GPTimer_LL_SetOverFlowIntrEnabled(hwDesc.BasePtr, false);
}

/**
 * @brief Clear Channel Interrupt Flag
 *
 * @param ChanHwIdx
 */
void Gpt_Im_ClearInterrupt(const Gpt_TimerEnumType ChanHwIdx)
{
    Gpt_HwDesc_t hwDesc = Gpt_Hw_Info[(uint32)ChanHwIdx];

    GPTimer_LL_ClearOverflowIntrFlag(hwDesc.BasePtr);
}

/**
 * @brief Start Timer Channel
 *
 * @param ChanHwIdx
 * @param TimeoutValue Time Out Counter
 * @param ChanMode
 */
void Gpt_Im_StartTimer(const Gpt_TimerEnumType ChanHwIdx, const uint32 TimeoutValue, Gpt_ChannelModeType ChanMode)
{
    Gpt_HwDesc_t hwDesc = Gpt_Hw_Info[(uint32)ChanHwIdx];

    /* Set the counting method of the channel, Up-Counting, Overflow-Interrupt */
    GPTimer_LL_SetCounterManner(hwDesc.BasePtr, TIM_MANNER_UP_FLAG);
    /* Clear channel Counter */
    /* SWS_Gpt_00329 */
    GPTimer_LL_SetCounter(hwDesc.BasePtr, 0U);
    /* Set Period Value, Compensate the count value of one Tick. refer to UM 12.4 */
    if (TimeoutValue > 1U)
    {
        GPTimer_LL_SetPeriod(hwDesc.BasePtr, (TimeoutValue - 1U));
    }
    else
    {
        GPTimer_LL_SetPeriod(hwDesc.BasePtr, 1U);
    }
    /* Clear Flag and Enable Interrupt */
    GPTimer_LL_ClearOverflowIntrFlag(hwDesc.BasePtr);

    if (ChanMode == GPT_MODE_ONE_SHOT)
    {
        GPTimer_LL_SetOverFlowIntrEnabled(hwDesc.BasePtr, true);
    }
    else
    {
        /* Do Nothing */
    }

    /* Enable Timer Channel */
    GPTimer_LL_Start(hwDesc.BasePtr);
}

/**
 * @brief Stop Timer Channel
 *
 * @param ChanHwIdx
 */
void Gpt_Im_StopTimer(const Gpt_TimerEnumType ChanHwIdx)
{
    Gpt_HwDesc_t hwDesc = Gpt_Hw_Info[(uint32)ChanHwIdx];

    /* Stop Timer Channel */
    GPTimer_LL_Stop(hwDesc.BasePtr);
    GPTimer_LL_SetOverFlowIntrEnabled(hwDesc.BasePtr, false);
    /* Clear Interrupt Flag */
    GPTimer_LL_ClearOverflowIntrFlag(hwDesc.BasePtr);
}

/**
 * @brief
 *
 * @param ChanHwIdx
 * @return Gpt_ValueType
 */
Gpt_ValueType Gpt_Im_GetTimeElapsed(const Gpt_TimerEnumType ChanHwIdx)
{
    Gpt_HwDesc_t hwDesc = Gpt_Hw_Info[(uint32)ChanHwIdx];

    uint32 value = GPTimer_LL_GetCounter(hwDesc.BasePtr);
    return (Gpt_ValueType)value;
}
/**
 * @brief
 *
 * @param ChanHwIdx
 * @return Gpt_ValueType
 */
Gpt_ValueType Gpt_Im_GetTimeRemaining(const Gpt_TimerEnumType ChanHwIdx)
{
    Gpt_HwDesc_t hwDesc = Gpt_Hw_Info[(uint32)ChanHwIdx];

    uint32 value;
    uint32 period  = GPTimer_LL_GetPeriod(hwDesc.BasePtr);
    uint32 counter = GPTimer_LL_GetCounter(hwDesc.BasePtr);
    /* TODO: Check Value Range and Effectiveness */
    if (period > counter)
    {
        value = (period - counter) + 1U;
    }
    else
    {
        value = 0U;
    }
    return (Gpt_ValueType)value;
}

#if (GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)

/**
 * @brief Start Pre-defined Timer, Only T21 Available
 *
 * @param PredefConfig
 */
void Gpt_Im_StartPredefTimer(const Gpt_PredefTimeConfigType *const PredefConfig)
{
    Gpt_HwDesc_t hwDesc = Gpt_Hw_Info[(uint32)PredefConfig->PredefHwChannel];

    /* Enable T21 Module */
    Gpt_Im_ExitFromResetMode(PredefConfig->PredefHwChannel);
    /* Set Timer Clock Source */
    /* PRQA S 4322 3 #KQR004322 */
    GPTimer_LL_SetClkSrc(hwDesc.BasePtr, (Timer_ClockSource_t)PredefConfig->ClockSource);
    /* Set Timer Clock Prescaler */
    if (PredefConfig->Prescaler > 0U)
    {
        GPTimer_LL_SetPrescaler(hwDesc.BasePtr, PredefConfig->Prescaler - 1U);
    }
    else
    {
        GPTimer_LL_SetPrescaler(hwDesc.BasePtr, 0U);
    }
    /* Set Timer to Clock Mode */
    GPTimer_LL_SetWorkingMode(hwDesc.BasePtr, TIMING_MODE);
    GPTimer_LL_SetCounterManner(hwDesc.BasePtr, TIM_MANNER_UP_FLAG);
    GPTimer_LL_SetCounter(hwDesc.BasePtr, 0U);
    GPTimer_LL_Start(hwDesc.BasePtr);
#ifdef GPT_INTERNAL_TRACE_LOGGER
    KFLOG_D(GPT_IM, "Predef Timer is Started\n");
#endif
}

/**
 * @brief Stop Predef Timer Channel, Only T21 is used
 *
 * @param PredefConfig
 */
void Gpt_Im_StopPredefTimer(const Gpt_PredefTimeConfigType *const PredefConfig)
{
    Gpt_HwDesc_t hwDesc = Gpt_Hw_Info[(uint32)PredefConfig->PredefHwChannel];
    GPTimer_LL_Stop(hwDesc.BasePtr);
}

/**
 * @brief Get current counter value of Pre-defined timer, Only T21 is used
 *
 * @param PredefConfig
 * @param PredefTimer
 * @retval uint32 T21 Counter value
 */
uint32
Gpt_Im_GetPredefTimerValue(const Gpt_PredefTimeConfigType *const PredefConfig, const Gpt_PredefTimerType PredefTimer)
{
    Gpt_HwDesc_t hwDesc = Gpt_Hw_Info[(uint32)PredefConfig->PredefHwChannel];

    uint32 retValue  = 0U;
    uint32 tempValue = GPTimer_LL_GetCounter(hwDesc.BasePtr);
    switch (PredefTimer)
    {
    case GPT_PREDEF_TIMER_1US_16BIT:
        retValue = (0x0000FFFFU & tempValue);
        break;
    case GPT_PREDEF_TIMER_1US_24BIT:
        retValue = (0x00FFFFFFU & tempValue);
        break;
    case GPT_PREDEF_TIMER_1US_32BIT:
        retValue = tempValue;
        break;
    case GPT_PREDEF_TIMER_100US_32BIT:
        retValue = tempValue / 100U;
        break;
    default:
        GPT_DEV_ASSERT(false);
        break;
    }
    return retValue;
}
#endif

/* EOF */
