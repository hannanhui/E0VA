/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Can_Irq.c
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
/* PRQA S 0602 EOF #KQR000602 */
/* PRQA S 2071 EOF #KQR002071 */
/* PRQA S 0602,2888 EOF #KQR100017 */
/******************************************************************************
 **                        Include Files
 ******************************************************************************/
#include "Can_IrqHandler.h"
#include "Canfd_Im.h"
#include "Irq_Cfg.h"
#include "kf_types.h"
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
 * @brief Bus IRQ handler for CANFD6
 */
#if (CANFD6_BUSERR_UNIFIED_INTERRUPT == STD_ON)
#if (IRQ_CAT_CANFD6 == IRQ_CAT1)
/* PRQA S 0602,2888 1 #KQR100017 */
KF_INTERRUPT(CANFD6_BUS)
#else
ISR(CANFD6_BUS)
#endif
{
    Can_Isr_Err(CanHardwareToControllerArray[CANFD6]);
}
#endif

/**
 * @brief General IRQ handler for CANFD6
 */
#if (CANFD6_CANFDGEN_UNIFIED_INTERRUPT == STD_ON)
#if (IRQ_CAT_CANFD6 == IRQ_CAT1)
/* PRQA S 0602,2888 1 #KQR100017 */
KF_INTERRUPT(CANFD6_GEN)
#else
ISR(CANFD6_GEN)
#endif
{
    Can_GeneralIrqHandler(CanHardwareToControllerArray[CANFD6]);
}
#endif

/**
 * @brief CanFd6 Mailbox 0~15 IRQ handler for CANFD
 * @implements
 */
#if (CANFD6MB15TO0_UNIFIED_INTERRUPT == STD_ON)
#if (IRQ_CAT_CANFD6 == IRQ_CAT1)
/* PRQA S 0602,2888 1 #KQR100017 */
KF_INTERRUPT(CANFD6_MB15TO0)
#else
ISR(CANFD6_MB15TO0)
#endif
{
    Can_Isr_Mb(CanHardwareToControllerArray[CANFD6], 0U, 15U);
}
#endif

/**
 * @brief CanFd6 Mailbox 16~31 IRQ handler for CANFD
 * @implements
 */
#if (CANFD6MB31TO16_UNIFIED_INTERRUPT == STD_ON)
#if (IRQ_CAT_CANFD6 == IRQ_CAT1)
/* PRQA S 0602,2888 1 #KQR100017 */
KF_INTERRUPT(CANFD6_MB31TO16)
#else
ISR(CANFD6_MB31TO16)
#endif
{
    Can_Isr_Mb(CanHardwareToControllerArray[CANFD6], 16U, 31U);
}
#endif

/**
 * @brief CanFd6 Mailbox 32~47 IRQ handler for CANFD
 * @implements
 */
#if (CANFD6MB47TO32_UNIFIED_INTERRUPT == STD_ON)
#if (IRQ_CAT_CANFD6 == IRQ_CAT1)
/* PRQA S 0602,2888 1 #KQR100017 */
KF_INTERRUPT(CANFD6_MB47TO32)
#else
ISR(CANFD6_MB47TO32)
#endif
{
    Can_Isr_Mb(CanHardwareToControllerArray[CANFD6], 32U, 47U);
}
#endif

/**
 * @brief CanFd6 Mailbox 48~63 IRQ handler for CANFD
 * @implements
 */
#if (CANFD6MB63TO48_UNIFIED_INTERRUPT == STD_ON)
#if (IRQ_CAT_CANFD6 == IRQ_CAT1)
/* PRQA S 0602,2888 1 #KQR100017 */
KF_INTERRUPT(CANFD6_MB63TO48)
#else
ISR(CANFD6_MB63TO48)
#endif
{
    Can_Isr_Mb(CanHardwareToControllerArray[CANFD6], 48U, 63U);
}
#endif

/**
 * @brief Bus IRQ handler for CANFD7
 */
#if (CANFD7_BUSERR_UNIFIED_INTERRUPT == STD_ON)
#if (IRQ_CAT_CANFD7 == IRQ_CAT1)
KF_INTERRUPT(CANFD7_BUS)
#else
ISR(CANFD7_BUS)
#endif
{
    Can_Isr_Err(CanHardwareToControllerArray[CANFD7]);
}
#endif

/**
 * @brief General IRQ handler for CANFD7
 */
#if (CANFD7_CANFDGEN_UNIFIED_INTERRUPT == STD_ON)
#if (IRQ_CAT_CANFD7 == IRQ_CAT1)
KF_INTERRUPT(CANFD7_GEN)
#else
ISR(CANFD7_GEN)
#endif
{
    Can_GeneralIrqHandler(CanHardwareToControllerArray[CANFD7]);
}
#endif

/**
 * @brief CanFd7 Mailbox 0~15 IRQ handler for CANFD
 * @implements
 */
#if (CANFD7MB15TO0_UNIFIED_INTERRUPT == STD_ON)
#if (IRQ_CAT_CANFD7 == IRQ_CAT1)
KF_INTERRUPT(CANFD7_MB15TO0)
#else
ISR(CANFD7_MB15TO0)
#endif
{
    Can_Isr_Mb(CanHardwareToControllerArray[CANFD7], 0U, 15U);
}
#endif

/**
 * @brief CanFd7 Mailbox 16~31 IRQ handler for CANFD
 * @implements
 */
#if (CANFD7MB31TO16_UNIFIED_INTERRUPT == STD_ON)
#if (IRQ_CAT_CANFD7 == IRQ_CAT1)
KF_INTERRUPT(CANFD7_MB31TO16)
#else
ISR(CANFD7_MB31TO16)
#endif
{
    Can_Isr_Mb(CanHardwareToControllerArray[CANFD7], 16U, 31U);
}
#endif

/**
 * @brief CanFd7 Mailbox 32~47 IRQ handler for CANFD
 * @implements
 */
#if (CANFD7MB47TO32_UNIFIED_INTERRUPT == STD_ON)
#if (IRQ_CAT_CANFD7 == IRQ_CAT1)
KF_INTERRUPT(CANFD7_MB47TO32)
#else
ISR(CANFD7_MB47TO32)
#endif
{
    Can_Isr_Mb(CanHardwareToControllerArray[CANFD7], 32U, 47U);
}
#endif

/**
 * @brief CanFd7 Mailbox 48~63 IRQ handler for CANFD
 * @implements
 */
#if (CANFD7MB63TO48_UNIFIED_INTERRUPT == STD_ON)
#if (IRQ_CAT_CANFD7 == IRQ_CAT1)
KF_INTERRUPT(CANFD7_MB63TO48)
#else
ISR(CANFD7_MB63TO48)
#endif
{
    Can_Isr_Mb(CanHardwareToControllerArray[CANFD7], 48U, 63U);
}
#endif

/**
 * @brief Bus IRQ handler for CANFD8
 */
#if (CANFD8_BUSERR_UNIFIED_INTERRUPT == STD_ON)
#if (IRQ_CAT_CANFD8 == IRQ_CAT1)
KF_INTERRUPT(CANFD8_BUS)
#else
ISR(CANFD8_BUS)
#endif
{
    Can_Isr_Err(CanHardwareToControllerArray[CANFD8]);
}
#endif

/**
 * @brief General IRQ handler for CANFD8
 */
#if (CANFD8_CANFDGEN_UNIFIED_INTERRUPT == STD_ON)
#if (IRQ_CAT_CANFD8 == IRQ_CAT1)
KF_INTERRUPT(CANFD8_GEN)
#else
ISR(CANFD8_GEN)
#endif
{
    Can_GeneralIrqHandler(CanHardwareToControllerArray[CANFD8]);
}
#endif

/**
 * @brief CanFd8 Mailbox 0~15 IRQ handler for CANFD
 * @implements
 */
#if (CANFD8MB15TO0_UNIFIED_INTERRUPT == STD_ON)
#if (IRQ_CAT_CANFD8 == IRQ_CAT1)
KF_INTERRUPT(CANFD8_MB15TO0)
#else
ISR(CANFD8_MB15TO0)
#endif
{
    Can_Isr_Mb(CanHardwareToControllerArray[CANFD8], 0U, 15U);
}
#endif

/**
 * @brief CanFd8 Mailbox 16~31 IRQ handler for CANFD
 * @implements
 */
#if (CANFD8MB31TO16_UNIFIED_INTERRUPT == STD_ON)
#if (IRQ_CAT_CANFD8 == IRQ_CAT1)
KF_INTERRUPT(CANFD8_MB31TO16)
#else
ISR(CANFD8_MB31TO16)
#endif
{
    Can_Isr_Mb(CanHardwareToControllerArray[CANFD8], 16U, 31U);
}
#endif

/**
 * @brief CanFd8 Mailbox 32~47 IRQ handler for CANFD
 * @implements
 */
#if (CANFD8MB47TO32_UNIFIED_INTERRUPT == STD_ON)
#if (IRQ_CAT_CANFD8 == IRQ_CAT1)
KF_INTERRUPT(CANFD8_MB47TO32)
#else
ISR(CANFD8_MB47TO32)
#endif
{
    Can_Isr_Mb(CanHardwareToControllerArray[CANFD8], 32U, 47U);
}
#endif

/**
 * @brief CanFd8 Mailbox 32~47 IRQ handler for CANFD
 * @implements
 */
#if (CANFD8MB63TO48_UNIFIED_INTERRUPT == STD_ON)
#if (IRQ_CAT_CANFD8 == IRQ_CAT1)
KF_INTERRUPT(CANFD8_MB63TO48)
#else
ISR(CANFD8_MB63TO48)
#endif
{
    Can_Isr_Mb(CanHardwareToControllerArray[CANFD8], 48U, 63U);
}
#endif

/*
 * @brief Bus IRQ handler for CANFD9
 */
#if (CANFD9_BUSERR_UNIFIED_INTERRUPT == STD_ON)
#if (IRQ_CAT_CANFD9 == IRQ_CAT1)
KF_INTERRUPT(CANFD9_BUS)
#else
ISR(CANFD9_BUS)
#endif
{
    Can_Isr_Err(CanHardwareToControllerArray[CANFD9]);
}
#endif

/**
 * @brief General IRQ handler for CANFD9
 */
#if (CANFD9_CANFDGEN_UNIFIED_INTERRUPT == STD_ON)
#if (IRQ_CAT_CANFD9 == IRQ_CAT1)
KF_INTERRUPT(CANFD9_GEN)
#else
ISR(CANFD9_GEN)
#endif
{
    Can_GeneralIrqHandler(CanHardwareToControllerArray[CANFD9]);
}
#endif

/**
 * @brief CanFd9 Mailbox 0~15 IRQ handler for CANFD
 * @implements
 */
#if (CANFD9MB15TO0_UNIFIED_INTERRUPT == STD_ON)
#if (IRQ_CAT_CANFD9 == IRQ_CAT1)
KF_INTERRUPT(CANFD9_MB15TO0)
#else
ISR(CANFD9_MB15TO0)
#endif
{
    Can_Isr_Mb(CanHardwareToControllerArray[CANFD9], 0U, 15U);
}
#endif

/**
 * @brief CanFd9 Mailbox 16~31 IRQ handler for CANFD
 * @implements
 */
#if (CANFD9MB31TO16_UNIFIED_INTERRUPT == STD_ON)
#if (IRQ_CAT_CANFD9 == IRQ_CAT1)
KF_INTERRUPT(CANFD9_MB31TO16)
#else
ISR(CANFD9_MB31TO16)
#endif
{
    Can_Isr_Mb(CanHardwareToControllerArray[CANFD9], 16U, 31U);
}
#endif

/**
 * @brief CanFd9 Mailbox 32~47 IRQ handler for CANFD
 * @implements
 */
#if (CANFD9MB47TO32_UNIFIED_INTERRUPT == STD_ON)
#if (IRQ_CAT_CANFD9 == IRQ_CAT1)
KF_INTERRUPT(CANFD9_MB47TO32)
#else
ISR(CANFD9_MB47TO32)
#endif
{
    Can_Isr_Mb(CanHardwareToControllerArray[CANFD9], 32U, 47U);
}
#endif

/**
 * @brief CanFd9 Mailbox 48~63 IRQ handler for CANFD
 * @implements
 */
#if (CANFD9MB63TO48_UNIFIED_INTERRUPT == STD_ON)
#if (IRQ_CAT_CANFD9 == IRQ_CAT1)
KF_INTERRUPT(CANFD9_MB63TO48)
#else
ISR(CANFD9_MB63TO48)
#endif
{
    Can_Isr_Mb(CanHardwareToControllerArray[CANFD9], 48U, 63U);
}
#endif
/* EOF */
