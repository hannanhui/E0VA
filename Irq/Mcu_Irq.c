/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Mcu_Irq.c
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
/* PRQA S 4397 EOF #KQR004397 */
/* PRQA S 0303 EOF #KQR000303 */
/* PRQA S 3408 EOF #KQR003408 */
/* PRQA S 3415 EOF #KQR003415 */
/* PRQA S 0499 EOF #KQR000499 */
/* PRQA S 2071 EOF #KQR002071 */
/******************************************************************************
 **                        Include Files
 ******************************************************************************/
#include "Irq_Cfg.h"
#include "kf_types.h"
#include "kf32a158sf_drv_intr.h"
#include "kf32a158sf_drv_ecc.h"
#include "kf32a158sf_drv_pm.h"
#include "kf32a158sf_drv_bkp.h"
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
 * @brief WKUP Interrupt Course
 *
 */
/* PRQA S 4153 ++ #KQR004153  */
/* PRQA S 0602,2888 1 #KQR100017 */
KF_INTERRUPT(WKP5TO0)
{
    Bkp_LL_HandleStart();
    Pm_LL_ClearAllWakeupPinState();
    Pm_LL_ClearPmcIntrFlag();
    Bkp_LL_HandleEnd();
}
/* PRQA S 4153 -- #KQR004153  */
/**
 * @brief EINT31TO20 Interrupt Course
 *
 */
/* PRQA S 0602,2888 1 #KQR100017 */
KF_INTERRUPT(EINT31TO20)
{
    if (Intr_LL_GetExtiFlag(INTR_EXTI_INDEX_21))
    {
        Intr_LL_ClearExtiFlag(INTR_EXTI_INDEX_21);
        Bkp_LL_HandleStart();
        Pm_LL_ClearPmcIntrFlag();
        Bkp_LL_HandleEnd();
    }
    else
    { /* do nothing */
    }

    if (Intr_LL_GetExtiFlag(INTR_EXTI_INDEX_20))
    {
        Intr_LL_ClearExtiFlag(INTR_EXTI_INDEX_20);
    }
    else
    { /* do nothing */
    }
}
/**
 * @brief SRAM ECC error Interrupt Course
 */

#if (SRAMECC_UNIFIED_INTERRUPT == STD_ON)
#if (IRQ_CAT_SRAMECC == IRQ_CAT1)
KF_INTERRUPT(SRAM_ECC)
#else
ISR(SRAM_ECC)
#endif
{
    Intr_LL_ClearInterruptFlag(SRAM_ECC_IRQn);

    Ecc_LL_ClearIntrFlag(ECC4_PTR, ECC_INTR_CLEAR_MEMERRIC);
    Ecc_LL_ClearIntrFlag(ECC4_PTR, ECC_INTR_CLEAR_MEM2BITERRIC);
}
#endif

#if (FLASHECC_UNIFIED_INTERRUPT == STD_ON)
#if (IRQ_CAT_FLASHECC == IRQ_CAT1)
/**
 * @brief Flash ECC error Interrupt Course
 */
KF_INTERRUPT(FLASH_ECC)
#else
ISR(FLASH_ECC)
#endif
{
    uint32_t errAddr = 0U;

    Intr_LL_ClearInterruptFlag(FLASH_ERR_IRQn);

    if (Ecc_LL_GetIntrFlag(ECC0_PTR, ECC_INTR_GET_MEM2BITERRIF))
    {
        errAddr = Ecc_LL_GetErrorAddress(ECC0_PTR);
        Ecc_LL_ClearIntrFlag(ECC0_PTR, ECC_INTR_CLEAR_MEMERRIC);
        Ecc_LL_ClearIntrFlag(ECC0_PTR, ECC_INTR_CLEAR_MEM2BITERRIC);
    }
    else if (Ecc_LL_GetIntrFlag(ECC1_PTR, ECC_INTR_GET_MEM2BITERRIF))
    {
        errAddr = Ecc_LL_GetErrorAddress(ECC1_PTR);
        Ecc_LL_ClearIntrFlag(ECC1_PTR, ECC_INTR_CLEAR_MEMERRIC);
        Ecc_LL_ClearIntrFlag(ECC1_PTR, ECC_INTR_CLEAR_MEM2BITERRIC);
    }
    else
    { /*Empty*/
    }
}
#endif