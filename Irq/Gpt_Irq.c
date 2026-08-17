/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Gpt_Irq.c
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
/* PRQA S 0602 EOF #KQR000602 */
/* PRQA S 3408 EOF #KQR003408 */
/* PRQA S 0686 EOF #KQR000686 */
/* PRQA S 2000 EOF #KQR002000 */
/* PRQA S 1290 EOF #KQR001290 */
/* PRQA S 3109 EOF #KQR003109 */
/* PRQA S 2071 EOF #KQR002071 */
/* PRQA S 2814 EOF #KQR002814 */
/* PRQA S 2824 EOF #KQR002824 */
/* PRQA S 2844 EOF #KQR002844 */
/* PRQA S 2201 EOF #KQR002201 */
/* PRQA S 3383 EOF #KQR003383 */
/* PRQA S 2984 EOF #KQR002984 */
/* PRQA S 0602,2888 EOF #KQR100017 */

/******************************************************************************
 **                        Include Files
 ******************************************************************************/
#include "Irq_Cfg.h"
#include "Mcal.h"
#include "kf32a158sf_drv_gptimer.h"
#include "kf32a158sf_drv_intr.h"
#include "kf_types.h"
#include "Mcal.h"
#if (IRQ_DEV_ERROR_DETECT_API == STD_ON)
#include "Det.h"
#endif

/******************************************************************************
 **                        File Version Check
 ******************************************************************************/

/******************************************************************************
 **                        Macro  Definitions
 ******************************************************************************/
#if (IRQ_DEV_ERROR_DETECT_API == STD_ON)
#define IRQ_DET_CHECK(_exp, apiId)                                                                                     \
    if (!(_exp))                                                                                                       \
    {                                                                                                                  \
        (void)Det_ReportError(IRQ_MODULE_ID, IRQ_INSTANCE_ID, apiId, IRQ_E_INTERRUPT_NOT_USE);                         \
    }
#endif
/******************************************************************************
 **                        Typedef  Definitions
 ******************************************************************************/
/**
 * @brief interrupt handle
 */
/* PRQA S 1336 1 #KQR001336 */
typedef void (*Timer_IntrHandleFcnType)(uint8);
/******************************************************************************
 *                      Variables
 ******************************************************************************/
/**
 * @brief general timer pointer
 */
/* PRQA S 3672 1 #KQR003672 */
static Timer_IntrHandleFcnType Gpt_GeneralTimerTriggerHandle[7U] = {NULL_PTR};

/**
 * @brief advance timer pointer
 */
/* PRQA S 3218 1 #KQR003218 */
static Timer_IntrHandleFcnType Gpt_AdvanceTimerTriggerHandle[3U] = {NULL_PTR};

/**
 * @brief advance timer pointer
 */
/* PRQA S 3218 1 #KQR003218 */
static Timer_IntrHandleFcnType Gpt_EnhanceTimerTriggerHandle[8U] = {NULL_PTR};
/******************************************************************************
 **                        Export Variables
 ******************************************************************************/

/******************************************************************************
 **                        Export Functions
 ******************************************************************************/
#if ((T14_UNIFIED_INTERRUPT == STD_ON) && (T14_WDG_USED == STD_ON))
/* PRQA S 1513 2 #KQR001513 */
extern void Wdg_Isr(void);
#endif
/******************************************************************************
 **                      Function definitions
 ******************************************************************************/
/**
 * @brief general timer interrupt handle register
 *
 * @param GptTimer timer index
 * @param IrqHandle interrupt handle function
 */
/* PRQA S 1336 1 #KQR001336 */
void Gpt_GeneralTimerRegisterCustomHandler(uint8 GptTimer, void (*const IrqHandle)(uint8))
{
    Gpt_GeneralTimerTriggerHandle[GptTimer] = (Timer_IntrHandleFcnType)IrqHandle;
}

/**
 * @brief advance timer interrupt handle register
 *
 * @param GptTimer timer index
 * @param IrqHandle interrupt handle function
 */
/* PRQA S 1336 1 #KQR001336 */
void Gpt_AdvanceTimerRegisterCustomHandler(uint8 GptTimer, void (*const IrqHandle)(uint8))
{
    Gpt_AdvanceTimerTriggerHandle[GptTimer] = (Timer_IntrHandleFcnType)IrqHandle;
}

/**
 * @brief advance timer interrupt handle register
 *
 * @param GptTimer timer index
 * @param IrqHandle interrupt handle function
 */
/* PRQA S 1336 1 #KQR001336 */
void Gpt_EnhanceTimerRegisterCustomHandler(uint8 GptTimer, void (*const IrqHandle)(uint8))
{
    Gpt_EnhanceTimerTriggerHandle[GptTimer] = (Timer_IntrHandleFcnType)IrqHandle;
}

/**
 * @brief T14 Exception Handler
 *
 */
/*PRQA S 4558,4116 ++ #KQR100003 */
#if (T14_UNIFIED_INTERRUPT == STD_ON)
#if (IRQ_CAT_T14 == IRQ_CAT1)
/* PRQA S 0602,2888 1 #KQR100017 */
KF_INTERRUPT(T14)
#else
ISR(T14)
#endif
{
#if (IRQ_DEV_ERROR_DETECT_API == STD_ON)
    /* PRQA S 2981 1 #KQR002981 */
    uint8 DetCheckValue = 0U;
#endif
#if (T14_WDG_USED == STD_ON)
    Wdg_Isr();
#if (IRQ_DEV_ERROR_DETECT_API == STD_ON)
    DetCheckValue = 1U;
#endif
#endif
/*PRQA S 2992,2996 4 #KQR002992 */
#if (IRQ_DEV_ERROR_DETECT_API == STD_ON)
    /* PRQA S 2880 1 #KQR002880 */
    IRQ_DET_CHECK(DetCheckValue, (uint8)T14_IRQn);
#endif
}
#endif

/**
 * @brief T0 Exception Handler
 *
 */
#if (T0_UNIFIED_INTERRUPT == STD_ON)
#if (IRQ_CAT_T0 == IRQ_CAT1)
KF_INTERRUPT(T0)
#else
ISR(T0)
#endif
{
#if (IRQ_DEV_ERROR_DETECT_API == STD_ON)
    uint8 DetCheckValue = 0U;
#endif
    if (Gpt_GeneralTimerTriggerHandle[0U] != NULL_PTR)
    {
        Gpt_GeneralTimerTriggerHandle[0U](0U);
#if (IRQ_DEV_ERROR_DETECT_API == STD_ON)
        DetCheckValue++;
#endif
    }

#if (IRQ_DEV_ERROR_DETECT_API == STD_ON)
    IRQ_DET_CHECK(DetCheckValue, T0_IRQn);
#endif
}
#endif

/**
 * @brief T1 Exception Handler
 *
 */
#if (T1_UNIFIED_INTERRUPT == STD_ON)
#if (IRQ_CAT_T1 == IRQ_CAT1)
/* PRQA S 0602,2888 1 #KQR100017 */
KF_INTERRUPT(T1)
#else
ISR(T1)
#endif
{
#if (IRQ_DEV_ERROR_DETECT_API == STD_ON)
    uint8 DetCheckValue = 0U;
#endif
    if (Gpt_GeneralTimerTriggerHandle[1U] != NULL_PTR)
    {
        Gpt_GeneralTimerTriggerHandle[1U](1U);
#if (IRQ_DEV_ERROR_DETECT_API == STD_ON)
        DetCheckValue = 1U;
#endif
    }
    else
    {
        /* do nothing */
    }
#if (IRQ_DEV_ERROR_DETECT_API == STD_ON)

    IRQ_DET_CHECK(DetCheckValue, (uint8)T1_IRQn);
#endif
}
#endif

/**
 * @brief T2 Exception Handler
 *
 */
#if (T2_UNIFIED_INTERRUPT == STD_ON)
#if (IRQ_CAT_T2 == IRQ_CAT1)
KF_INTERRUPT(T2)
#else
ISR(T2)
#endif
{
#if (IRQ_DEV_ERROR_DETECT_API == STD_ON)
    uint8 DetCheckValue = 0U;
#endif
    if (Gpt_GeneralTimerTriggerHandle[2U] != NULL_PTR)
    {
        Gpt_GeneralTimerTriggerHandle[2U](2U);
#if (IRQ_DEV_ERROR_DETECT_API == STD_ON)
        DetCheckValue++;
#endif
    }
    else
    {
        /* do nothing */
    }

#if (IRQ_DEV_ERROR_DETECT_API == STD_ON)
    IRQ_DET_CHECK(DetCheckValue, (uint8)T2_IRQn);
#endif
}
#endif

/**
 * @brief T3 Exception Handler
 *
 */
#if (T3_UNIFIED_INTERRUPT == STD_ON)
#if (IRQ_CAT_T3 == IRQ_CAT1)
KF_INTERRUPT(T3)
#else
ISR(T3)
#endif
{
#if (IRQ_DEV_ERROR_DETECT_API == STD_ON)
    uint8 DetCheckValue = 0U;
#endif
    if (Gpt_GeneralTimerTriggerHandle[3U] != NULL_PTR)
    {
        Gpt_GeneralTimerTriggerHandle[3U](3U);
#if (IRQ_DEV_ERROR_DETECT_API == STD_ON)
        DetCheckValue++;
#endif
    }

#if (IRQ_DEV_ERROR_DETECT_API == STD_ON)
    IRQ_DET_CHECK(DetCheckValue, T3_IRQn);
#endif
}
#endif

/**
 * @brief T4 Exception Handler
 *
 */
#if (T4_UNIFIED_INTERRUPT == STD_ON)
#if (IRQ_CAT_T4 == IRQ_CAT1)
KF_INTERRUPT(T4)
#else
ISR(T4)
#endif
{
#if (IRQ_DEV_ERROR_DETECT_API == STD_ON)
    uint8 DetCheckValue = 0U;
#endif
    if (Gpt_GeneralTimerTriggerHandle[4U] != NULL_PTR)
    {
        Gpt_GeneralTimerTriggerHandle[4U](4U);
#if (IRQ_DEV_ERROR_DETECT_API == STD_ON)
        DetCheckValue++;
#endif
    }

#if (IRQ_DEV_ERROR_DETECT_API == STD_ON)
    IRQ_DET_CHECK(DetCheckValue, T4_IRQn);
#endif
}
#endif

/**
 * @brief T20 Exception Handler
 *
 */
#if (T20_UNIFIED_INTERRUPT == STD_ON)
#if (IRQ_CAT_T20 == IRQ_CAT1)
KF_INTERRUPT(T20)
#else
ISR(T20)
#endif
{
#if (IRQ_DEV_ERROR_DETECT_API == STD_ON)
    uint8 DetCheckValue = 0U;
#endif
    if (Gpt_GeneralTimerTriggerHandle[5U] != NULL_PTR)
    {
        Gpt_GeneralTimerTriggerHandle[5U](5U);
#if (IRQ_DEV_ERROR_DETECT_API == STD_ON)
        DetCheckValue++;
#endif
    }
    else
    {
        /* do nothing */
    }

#if (IRQ_DEV_ERROR_DETECT_API == STD_ON)

    IRQ_DET_CHECK(DetCheckValue, (uint8)T21_IRQn);
#endif
}
#endif

/**
 * @brief T21 Exception Handler
 *
 */
#if (T21_UNIFIED_INTERRUPT == STD_ON)
#if (IRQ_CAT_T21 == IRQ_CAT1)
KF_INTERRUPT(T21)
#else
ISR(T21)
#endif
{
#if (IRQ_DEV_ERROR_DETECT_API == STD_ON)
    uint8 DetCheckValue = 0U;
#endif
    if (Gpt_GeneralTimerTriggerHandle[6U] != NULL_PTR)
    {
        Gpt_GeneralTimerTriggerHandle[6U](6U);
#if (IRQ_DEV_ERROR_DETECT_API == STD_ON)
        DetCheckValue++;
#endif
    }
    else
    {
        /* do nothing */
    }

#if (IRQ_DEV_ERROR_DETECT_API == STD_ON)

    IRQ_DET_CHECK(DetCheckValue, (uint8)T21_IRQn);
#endif
}
#endif

/**
 * @brief T5 Exception Handler
 *
 */
#if (T5_UNIFIED_INTERRUPT == STD_ON)
#if (IRQ_CAT_T5 == IRQ_CAT1)
KF_INTERRUPT(T5)
#else
ISR(T5)
#endif
{
#if (IRQ_DEV_ERROR_DETECT_API == STD_ON)
    uint8 DetCheckValue = 0U;
#endif
    if (Gpt_AdvanceTimerTriggerHandle[0U] != NULL_PTR)
    {
        Gpt_AdvanceTimerTriggerHandle[0U](0U);
#if (IRQ_DEV_ERROR_DETECT_API == STD_ON)
        DetCheckValue++;
#endif
    }

#if (IRQ_DEV_ERROR_DETECT_API == STD_ON)
    IRQ_DET_CHECK(DetCheckValue, T5_IRQn);
#endif
}
#endif

/**
 * @brief T6 Exception Handler
 *
 */
#if (T6_UNIFIED_INTERRUPT == STD_ON)
#if (IRQ_CAT_T6 == IRQ_CAT1)
KF_INTERRUPT(T6)
#else
ISR(T6)
#endif
{
#if (IRQ_DEV_ERROR_DETECT_API == STD_ON)
    uint8 DetCheckValue = 0U;
#endif
    if (Gpt_AdvanceTimerTriggerHandle[0U] != NULL_PTR)
    {
        Gpt_AdvanceTimerTriggerHandle[0U](0U);
#if (IRQ_DEV_ERROR_DETECT_API == STD_ON)
        DetCheckValue++;
#endif
    }

#if (IRQ_DEV_ERROR_DETECT_API == STD_ON)
    IRQ_DET_CHECK(DetCheckValue, T6_IRQn);
#endif
}
#endif

/**
 * @brief T9 Exception Handler
 *
 */
#if (T9_UNIFIED_INTERRUPT == STD_ON)
#if (IRQ_CAT_T9 == IRQ_CAT1)
KF_INTERRUPT(T9)
#else
ISR(T9)
#endif
{
#if (IRQ_DEV_ERROR_DETECT_API == STD_ON)
    uint8 DetCheckValue = 0U;
#endif
    if (Gpt_AdvanceTimerTriggerHandle[1U] != NULL_PTR)
    {
        Gpt_AdvanceTimerTriggerHandle[1U](1U);
#if (IRQ_DEV_ERROR_DETECT_API == STD_ON)
        DetCheckValue++;
#endif
    }

#if (IRQ_DEV_ERROR_DETECT_API == STD_ON)
    IRQ_DET_CHECK(DetCheckValue, T9_IRQn);
#endif
}
#endif

/**
 * @brief T10 Exception Handler
 *
 */
#if (T10_UNIFIED_INTERRUPT == STD_ON)
#if (IRQ_CAT_T10 == IRQ_CAT1)
KF_INTERRUPT(T10)
#else
ISR(T10)
#endif
{
#if (IRQ_DEV_ERROR_DETECT_API == STD_ON)
    uint8 DetCheckValue = 0U;
#endif
    if (Gpt_AdvanceTimerTriggerHandle[1U] != NULL_PTR)
    {
        Gpt_AdvanceTimerTriggerHandle[1U](1U);
#if (IRQ_DEV_ERROR_DETECT_API == STD_ON)
        DetCheckValue++;
#endif
    }

#if (IRQ_DEV_ERROR_DETECT_API == STD_ON)
    IRQ_DET_CHECK(DetCheckValue, T10_IRQn);
#endif
}
#endif

/**
 * @brief T11 Exception Handler
 *
 */
#if (T11_UNIFIED_INTERRUPT == STD_ON)
#if (IRQ_CAT_T11 == IRQ_CAT1)
KF_INTERRUPT(T11)
#else
ISR(T11)
#endif
{
#if (IRQ_DEV_ERROR_DETECT_API == STD_ON)
    uint8 DetCheckValue = 0U;
#endif
    if (Gpt_EnhanceTimerTriggerHandle[0U] != NULL_PTR)
    {
        Gpt_EnhanceTimerTriggerHandle[0U](0U);
#if (IRQ_DEV_ERROR_DETECT_API == STD_ON)
        DetCheckValue++;
#endif
    }

#if (IRQ_DEV_ERROR_DETECT_API == STD_ON)
    IRQ_DET_CHECK(DetCheckValue, T11_IRQn);
#endif
}
#endif

/**
 * @brief T12 Exception Handler
 *
 */
#if (T12_UNIFIED_INTERRUPT == STD_ON)
#if (IRQ_CAT_T12 == IRQ_CAT1)
KF_INTERRUPT(T12)
#else
ISR(T12)
#endif
{
#if (IRQ_DEV_ERROR_DETECT_API == STD_ON)
    uint8 DetCheckValue = 0U;
#endif
    if (Gpt_EnhanceTimerTriggerHandle[1U] != NULL_PTR)
    {
        Gpt_EnhanceTimerTriggerHandle[1U](1U);
#if (IRQ_DEV_ERROR_DETECT_API == STD_ON)
        DetCheckValue++;
#endif
    }

#if (IRQ_DEV_ERROR_DETECT_API == STD_ON)
    IRQ_DET_CHECK(DetCheckValue, T12_IRQn);
#endif
}
#endif

/**
 * @brief T13 Exception Handler
 *
 */
#if (T13_UNIFIED_INTERRUPT == STD_ON)
#if (IRQ_CAT_T13 == IRQ_CAT1)
KF_INTERRUPT(T13)
#else
ISR(T13)
#endif
{
#if (IRQ_DEV_ERROR_DETECT_API == STD_ON)
    uint8 DetCheckValue = 0U;
#endif
    if (Gpt_EnhanceTimerTriggerHandle[2U] != NULL_PTR)
    {
        Gpt_EnhanceTimerTriggerHandle[2U](2U);
#if (IRQ_DEV_ERROR_DETECT_API == STD_ON)
        DetCheckValue++;
#endif
    }

#if (IRQ_DEV_ERROR_DETECT_API == STD_ON)
    IRQ_DET_CHECK(DetCheckValue, T13_IRQn);
#endif
}
#endif

/**
 * @brief T16 Exception Handler
 *
 */
#if (T16_UNIFIED_INTERRUPT == STD_ON)
#if (IRQ_CAT_T16 == IRQ_CAT1)
KF_INTERRUPT(T16)
#else
ISR(T16)
#endif
{
#if (IRQ_DEV_ERROR_DETECT_API == STD_ON)
    uint8 DetCheckValue = 0U;
#endif
    if (Gpt_EnhanceTimerTriggerHandle[3U] != NULL_PTR)
    {
        Gpt_EnhanceTimerTriggerHandle[3U](3U);
#if (IRQ_DEV_ERROR_DETECT_API == STD_ON)
        DetCheckValue++;
#endif
    }

#if (IRQ_DEV_ERROR_DETECT_API == STD_ON)
    IRQ_DET_CHECK(DetCheckValue, T16_IRQn);
#endif
}
#endif

/**
 * @brief T31 Exception Handler
 *
 */
#if (T31_UNIFIED_INTERRUPT == STD_ON)
#if (IRQ_CAT_T31 == IRQ_CAT1)
KF_INTERRUPT(T31)
#else
ISR(T31)
#endif
{
#if (IRQ_DEV_ERROR_DETECT_API == STD_ON)
    uint8 DetCheckValue = 0U;
#endif
    if (Gpt_EnhanceTimerTriggerHandle[4U] != NULL_PTR)
    {
        Gpt_EnhanceTimerTriggerHandle[4U](4U);
#if (IRQ_DEV_ERROR_DETECT_API == STD_ON)
        DetCheckValue++;
#endif
    }

#if (IRQ_DEV_ERROR_DETECT_API == STD_ON)
    IRQ_DET_CHECK(DetCheckValue, T31_IRQn);
#endif
}
#endif

/**
 * @brief T32 Exception Handler
 *
 */
#if (T32_UNIFIED_INTERRUPT == STD_ON)
#if (IRQ_CAT_T32 == IRQ_CAT1)
KF_INTERRUPT(T32)
#else
ISR(T32)
#endif
{
#if (IRQ_DEV_ERROR_DETECT_API == STD_ON)
    uint8 DetCheckValue = 0U;
#endif
    if (Gpt_EnhanceTimerTriggerHandle[5U] != NULL_PTR)
    {
        Gpt_EnhanceTimerTriggerHandle[5U](5U);
#if (IRQ_DEV_ERROR_DETECT_API == STD_ON)
        DetCheckValue++;
#endif
    }

#if (IRQ_DEV_ERROR_DETECT_API == STD_ON)
    IRQ_DET_CHECK(DetCheckValue, T32_IRQn);
#endif
}
#endif

/**
 * @brief T33 Exception Handler
 *
 */
#if (T33_UNIFIED_INTERRUPT == STD_ON)
#if (IRQ_CAT_T33 == IRQ_CAT1)
KF_INTERRUPT(T33)
#else
ISR(T33)
#endif
{
#if (IRQ_DEV_ERROR_DETECT_API == STD_ON)
    uint8 DetCheckValue = 0U;
#endif
    if (Gpt_EnhanceTimerTriggerHandle[6U] != NULL_PTR)
    {
        Gpt_EnhanceTimerTriggerHandle[6U](6U);
#if (IRQ_DEV_ERROR_DETECT_API == STD_ON)
        DetCheckValue++;
#endif
    }

#if (IRQ_DEV_ERROR_DETECT_API == STD_ON)
    IRQ_DET_CHECK(DetCheckValue, T33_IRQn);
#endif
}
#endif

/**
 * @brief T36 Exception Handler
 *
 */
#if (T36_UNIFIED_INTERRUPT == STD_ON)
#if (IRQ_CAT_T36 == IRQ_CAT1)
KF_INTERRUPT(T36)
#else
ISR(T36)
#endif
{
#if (IRQ_DEV_ERROR_DETECT_API == STD_ON)
    uint8 DetCheckValue = 0U;
#endif
    if (Gpt_EnhanceTimerTriggerHandle[7U] != NULL_PTR)
    {
        Gpt_EnhanceTimerTriggerHandle[7U](7U);
#if (IRQ_DEV_ERROR_DETECT_API == STD_ON)
        DetCheckValue++;
#endif
    }

#if (IRQ_DEV_ERROR_DETECT_API == STD_ON)
    IRQ_DET_CHECK(DetCheckValue, T36_IRQn);
#endif
}
#endif

/* EOF */
