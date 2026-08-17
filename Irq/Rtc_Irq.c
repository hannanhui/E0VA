/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Rtc_Irq.c
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
/* PRQA S 3408 EOF #KQR003408 */
/* PRQA S 2071 EOF #KQR002071 */
/******************************************************************************
 **                        Include Files
 ******************************************************************************/
#include "kf_types.h"
#include "Irq_Cfg.h"
#include "Rtc_Im.h"
#include "Mcal.h"
#include "kf32a158sf_drv_intr.h"
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
 * @brief EINT19TO17 Exception Handler
 *
 */
#if (EINT19_17_UNIFIED_INTERRUPT == STD_ON)
#if (IRQ_CAT_EINT19TO17 == IRQ_CAT1)
/* PRQA S 0602,2888 1 #KQR100017 */
KF_INTERRUPT(EINT19TO17)
#else
ISR(EINT19TO17)
#endif
{
    Intr_LL_ClearInterruptFlag(EINT19TO17_IRQn);

    /** EWDT */
    if (Intr_LL_GetExtiFlag(INTR_EXTI_INDEX_19))
    {
        Intr_LL_ClearExtiFlag(INTR_EXTI_INDEX_19);
    }
    else
    {
    }

    /** RTC */
    if (Rtc_Im_IntrGetExtiFlag(INTR_EXTI_IM_INDEX_17))
    {
        Rtc_Im_IntrClearExtiFlag(INTR_EXTI_IM_INDEX_17);
        Rtc_Im_Isr();
    }
    else
    {
        /* do nothing */
    }
}
#endif
/* EOF */
