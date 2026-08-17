/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : SchM_Can.c
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
 ******************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 **                        MISRA-C Rules Violations
 ******************************************************************************/
/**
 * @page misra_violations MISRA-C:2004 violations
 *
 * @section
 */

/******************************************************************************
 **                        QAC Warnings Suppression
 ******************************************************************************/
/**
 * @page QAC Warnings
 *
 */
/* PRQA S 3408 EOF #KQR003408 */
/* PRQA S 1503 EOF #KQR001503 */
/* PRQA S 3387 EOF #KQR003387 */
/* PRQA S 3383 EOF #KQR003383 */
/* PRQA S 3384 EOF #KQR003384 */
/******************************************************************************
 **                        Include Files
 ******************************************************************************/
#include "Compiler.h"
#include "Platform_Types.h"
#include "kf32a158sf_drv_intr.h"
/******************************************************************************
 **                        File Version Check
 ******************************************************************************/

/******************************************************************************
 *                         Local Variables
 ******************************************************************************/
static VOLATILE(uint32, Volatile, CAN_VAR) kvInt_CanCriticalLevel = 0U;
static VOLATILE(uint32, Volatile, CAN_VAR) kvInt_CanCriticalCount = 0U;
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
 *                         Global Function definitions
 ******************************************************************************/
void SchM_Enter_Can_CAN_EXCLUSIVE_AREA_00(void)
{
    if (kvInt_CanCriticalCount > 0U)
    {
        /* Avoid QAC 2000 Warning */
    }
    else
    {
        kvInt_CanCriticalLevel = Intr_LL_EnterCritical();
    }
    kvInt_CanCriticalCount++;
}

void SchM_Exit_Can_CAN_EXCLUSIVE_AREA_00(void)
{
    kvInt_CanCriticalCount--;
    if (kvInt_CanCriticalCount == 0U)
    {
        Intr_LL_ExitCritical(kvInt_CanCriticalLevel);
    }
    else
    {
        /* Avoid QAC 2000 Warning */
    }
}

#ifdef __cplusplus
}
#endif

/* EOF */
