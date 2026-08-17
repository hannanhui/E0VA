/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Usart_Irq.c
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
/* PRQA S 3408 EOF  #KQR003408 */
/* PRQA S 2071 EOF #KQR002071 */
/* PRQA S 2814 EOF #KQR002814 */
/* PRQA S 2844 EOF #KQR002844 */
/******************************************************************************
 **                        Include Files
 ******************************************************************************/
#include "kf_types.h"
#include "Irq_Cfg.h"
#include "Mcal.h"
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
 * @brief interrupt handle
 */
typedef void (*Usart_IntrHandleFcnType)(uint8 UsartIndex);
/******************************************************************************
 **                      Variables
 ******************************************************************************/

/**
 * @brief usart interrupt handle
 */
/*PRQA S 0686 1 #KQR000686 */
static Usart_IntrHandleFcnType UsartInterruptHandle[5U] = {NULL_PTR};
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
 * @brief usart interrupt handle register
 *
 * @param UsartIndex usart index
 * @param IrqHandle interrupt handle function
 */
void Usart_RegisterCustomHandler(uint8 UsartIndex, void (*IrqHandle)(uint8 UsartIndex))
{
    UsartInterruptHandle[UsartIndex] = (Usart_IntrHandleFcnType)IrqHandle;
}

/**
 * @brief USART0 Exception Handler
 *
 */
#if (USART0_UNIFIED_INTERRUPT == STD_ON)
#if (IRQ_CAT_USART0 == IRQ_CAT1)
KF_INTERRUPT(USART0)
#else
ISR(USART0)
#endif
{
    if (UsartInterruptHandle[0U] != NULL_PTR)
    {
        UsartInterruptHandle[0U](0U);
    }
    else
    {
        /* do nothing */
    }
}
#endif

/**
 * @brief USART1 Exception Handler
 *
 */
#if (USART1_UNIFIED_INTERRUPT == STD_ON)
#if (IRQ_CAT_USART1 == IRQ_CAT1)
/* PRQA S 0602,2888 1 #KQR100017 */
KF_INTERRUPT(USART1)
#else
ISR(USART1)
#endif
{
    if (UsartInterruptHandle[1U] != NULL_PTR)
    {
        UsartInterruptHandle[1U](1U);
    }
    else
    {
        /* do nothing */
    }
}
#endif

/**
 * @brief USART2 Exception Handler
 *
 */
#if (USART2_UNIFIED_INTERRUPT == STD_ON)
#if (IRQ_CAT_USART2 == IRQ_CAT1)
/* PRQA S 0602,2888 1 #KQR100017 */
KF_INTERRUPT(USART2)
#else
ISR(USART2)
#endif
{
    if (UsartInterruptHandle[2U] != NULL_PTR)
    {
        UsartInterruptHandle[2U](2U);
    }
    else
    {
        /* do nothing */
    }
}
#endif

/**
 * @brief USART3 Exception Handler
 *
 */
#if (USART3_UNIFIED_INTERRUPT == STD_ON)
#if (IRQ_CAT_USART3 == IRQ_CAT1)
/* PRQA S 0602,2888 1 #KQR100017 */
KF_INTERRUPT(USART3)
#else
ISR(USART3)
#endif
{
    if (UsartInterruptHandle[3U] != NULL_PTR)
    {
        UsartInterruptHandle[3U](3U);
    }
    else
    {
        /* do nothing */
    }
}
#endif

/**
 * @brief USART6 Exception Handler
 *
 */
#if (USART6_UNIFIED_INTERRUPT == STD_ON)
#if (IRQ_CAT_USART6 == IRQ_CAT1)
/* PRQA S 0602,2888 1 #KQR100017 */
KF_INTERRUPT(USART6)
#else
ISR(USART6)
#endif
{
    if (UsartInterruptHandle[4U] != NULL_PTR)
    {
        UsartInterruptHandle[4U](4U);
    }
    else
    {
        /* do nothing */
    }
}
#endif
/* EOF */
