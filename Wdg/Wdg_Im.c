/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Wdg_Im.c
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
/* PRQA S 4899 EOF #KQR004899 */
/* PRQA S 3383 EOF #KQR003383 */
/******************************************************************************
 **                        Include Files
 ******************************************************************************/
#include "Wdg_Im.h"
#include "kf32a158sf_drv_wdt.h"
#include "kf32a158sf_drv_btimer.h"
#include "kf32a158sf_drv_pclk.h"
#include "kf32a158sf_drv_intr.h"
#include "kf32a158sf_drv_rst.h"
#include "kf32a158sf_drv_bkp.h"
#include "kf32a158sf_drv_pm.h"
#include "kf32a158sf_drv_osc.h"
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

/**
 * @brief feed dog
 *
 *
 * @retval void
 */
void Wdg_Im_FeedDog(void)
{
    /* Prepare to read and write backup domain data*/
    Bkp_LL_HandleStart();
    Iwdt_LL_FeedDog(IWDT_PTR);
    /* The backup domain data is read or written */
    Bkp_LL_HandleEnd();
}

/**
 * @brief start watch dog
 *
 *
 * @retval void
 */
void Wdg_Im_StartWdg(void)
{
    /* Prepare to read and write backup domain data*/
    Bkp_LL_HandleStart();
    /* Unlock the IWDT control register */
    Osc_LL_SetIwdtControlRegisterLocked(false);
    /*Enable wdg */
    Iwdt_LL_SetEnabled(IWDT_PTR, (bool)true);
    /* Lock the IWDT control register */
    Osc_LL_SetIwdtControlRegisterLocked(true);
    /* The backup domain data is read or written */
    Bkp_LL_HandleEnd();
}

/**
 * @brief stop watch dog
 *
 *
 * @retval void
 */
void Wdg_Im_StopWdg(void)
{
    /* Prepare to read and write backup domain data*/
    Bkp_LL_HandleStart();
    /* Unlock the IWDT control register */
    Osc_LL_SetIwdtControlRegisterLocked(false);
    /*Enable wdg */
    Iwdt_LL_SetEnabled(IWDT_PTR, (bool)false);
    /* Lock the IWDT control register */
    Osc_LL_SetIwdtControlRegisterLocked(true);
    /* The backup domain data is read or written */
    Bkp_LL_HandleEnd();
}

/**
 * @brief Start the Timer
 * @param Ticks the cycle value
 *
 * @retval void
 */
void Wdg_Im_StartGpt(Wdg_ValueType Ticks)
{
    /*set timer count */
    BTimer_LL_SetCounter(0U);
    /*set timer period*/
    BTimer_LL_SetPeriod(Ticks);
    /*  clear interrupt flag*/
    BTimer_LL_ClearIntrFlag(BTIM_INT_OVERFLOW);
    /* interrupt enable */
    BTimer_LL_SetIntrEnabled(BTIM_INT_OVERFLOW, (bool)true);
    /*enable timer */
    BTimer_LL_Start();
}

/**
 * @brief Turn off the timer
 *
 *
 * @retval void
 */
void Wdg_Im_StopGpt(void)
{
    /* disable timer */
    BTimer_LL_Stop();
    /* Turn off channel interrupts */
    BTimer_LL_SetIntrEnabled(BTIM_INT_OVERFLOW, (bool)false);
    /* Clear the interrupt flag bit of the channel */
    BTimer_LL_ClearIntrFlag(BTIM_INT_OVERFLOW);
}

/**
 * @brief clear timer isr flag
 *
 *
 * @retval void
 */
void Wdg_Im_ClearIsrFlag(void)
{
    /* clear tx update isr flag */
    BTimer_LL_ClearIntrFlag(BTIM_INT_UPDATE_EVENT);
    /*  clear over flow flag*/
    BTimer_LL_ClearIntrFlag(BTIM_INT_OVERFLOW);
}

/**
 * @brief Preinitialize configuration of the watchdog timer
 * @note  1tick equals 1ms
 *
 * @retval void
 */
void Wdg_Im_PreInitGpt(Wdg_ValueType Prescaler)
{
    /* reset T14*/
    Rst_LL_SetTimerEnabled(RST_T14, false);
    /* T14 exit reset*/
    Rst_LL_SetTimerEnabled(RST_T14, true);
    /* Peripheral Clock Enable */
    Pclk_LL_SetTimerEnabled(PCLK_T14, true);
    /*clock selection*/
    BTimer_LL_SetClkSrc(TIM_HFCLK);
    /* Set to timed mode */
    BTimer_LL_SetMode(TIMING_MODE);
    /*set timer count */
    BTimer_LL_SetCounter(0U);
    /*Set timer Prescaler */
    BTimer_LL_SetPrescaler(Prescaler - 1U);
    /*counting method */
    BTimer_LL_SetCounterManner(TIM_MANNER_UP_FLAG);
}

/**
 * @brief Set the overflow value of the watchdog
 * @param ReloadValue over flow value
 *
 * @retval void
 */
void Wdg_Im_SetOverFlowValue(Wdg_ValueType ReloadValue)
{
    /* Prepare to read and write backup domain data*/
    Bkp_LL_HandleStart();
    /*config Iwdt ReloadValue (0x00-0xFFF) */
    Iwdt_LL_SetOverflowValue(IWDT_PTR, ReloadValue);
    /* The backup domain data is read or written */
    Bkp_LL_HandleEnd();
}

/**
 * @brief Shut down the watchdog
 *
 *
 * @retval void
 */
void Wdg_Im_DeInit(void)
{
    /* enable read and write  operation for bkp data register*/
    Bkp_LL_PmRegisterHandleStart();
    /* Unlock the IWDT control register */
    Osc_LL_SetIwdtControlRegisterLocked(false);
    /* disable wdg*/
    Iwdt_LL_SetEnabled(IWDT_PTR, (bool)false);
    /* The backup domain data is read or written */
    Bkp_LL_HandleEnd();
    /* Lock the IWDT control register */
    Osc_LL_SetIwdtControlRegisterLocked(true);
    /* Turn off the timer */
    Bkp_LL_PmRegisterHandleEnd();
}

/**
 * @brief Preinitialize IWDT
 * @details set the frequency divider and clock source
 *
 *
 * @retval void
 */
void Wdg_Im_PreInitIwdt(const Wdg_ConfigType *ConfigPtr)
{
    /* enable read and write  operation for bkp data register*/
    Bkp_LL_PmRegisterHandleStart();
    /* Unlock the IWDT control register */
    Osc_LL_SetIwdtControlRegisterLocked(false);
    /* Exit reset state */
    Pm_LL_ExitIwdgReset(true);

    if (ConfigPtr->WdgClkSource == WDG_CLK_INTLF)
    {
        /* Enable INTLF */
        Pm_LL_SetInternalLowFrequencyEnabled(true);
        /*Select working clock source */
        Iwdt_LL_SelectClkSource(IWDT_PTR, (bool)false);
    }
    else
    {
        /* Enable EXTLF */
        Pm_LL_SetExternalLowFrequencyEnabled(true);
        /*Select working clock source */
        Iwdt_LL_SelectClkSource(IWDT_PTR, (bool)true);
    }
    /*set  frequency division factor */
    /* PRQA S 4322 1 #KQR004322 */
    Iwdt_LL_SetClkPrescaler(IWDT_PTR, (Iwdt_Division_t)(ConfigPtr->WdgPrescale));
    /*config Iwdt ReloadValue (0x00-0xFFF) */
    Iwdt_LL_SetOverflowValue(IWDT_PTR, (uint16_t)(ConfigPtr->WdgOverflowValue));
    /* Lock the IWDT control register */
    Osc_LL_SetIwdtControlRegisterLocked(true);
    /* The backup domain data is read or written */
    Bkp_LL_PmRegisterHandleEnd();
}
