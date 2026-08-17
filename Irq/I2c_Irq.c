/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : I2c_Irq.c
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
/* PRQA S 2071 EOF #KQR002071 */
/* PRQA S 3408 EOF #KQR003408 */
/******************************************************************************
 **                        Include Files
 ******************************************************************************/
#include "Irq_Cfg.h"
#include "I2c_IrqProtocol.h"
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
/**
 * @brief I2CO Exception Handler
 *
 */
#if (IIC0_UNIFIED_INTERRUPT == STD_ON)
#if (IRQ_CAT_I2C0 == IRQ_CAT1)
/* PRQA S 0602,2888 1 #KQR100017 */
KF_INTERRUPT(I2C0)
#else
ISR(I2C0)
#endif
{
    I2c_IsrProtocol(0U);
}
#endif

/**
 * @brief I2C1 Exception Handler
 *
 */
#if (IIC1_UNIFIED_INTERRUPT == STD_ON)
#if (IRQ_CAT_I2C1 == IRQ_CAT1)
KF_INTERRUPT(I2C1)
#else
ISR(I2C1)
#endif
{
    I2c_IsrProtocol(1U);
}
#endif

/**
 * @brief I2C2 Exception Handler
 *
 */
#if (IIC2_UNIFIED_INTERRUPT == STD_ON)
#if (IRQ_CAT_I2C2 == IRQ_CAT1)
KF_INTERRUPT(I2C2)
#else
ISR(I2C2)
#endif
{
    I2c_IsrProtocol(2U);
}
#endif
