/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : SchM_Dio.c
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
 **                        QAC Warnings Suppression
 ******************************************************************************/
/**
 * @page QAC Warnings
 *
 */
/* PRQA S 0791 EOF #KOR000791 */
/* PRQA S 1534 EOF #KOR001534 */
/* PRQA S 3408 EOF #KQR003408 */
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
 **                        Local Variables
 ******************************************************************************/
static VOLATILE(uint32, Volatile, CAN_VAR) kvInt_DioCriticalLevel = 0U;
static VOLATILE(uint32, Volatile, CAN_VAR) kvInt_DioCriticalCount = 0U;
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

void SchM_Enter_Dio_DIO_EXCLUSIVE_AREA_00(void)
{
    if (kvInt_DioCriticalCount > 0U)
    {
        /* Avoid QAC 2000 Warning */
    }
    else
    {
        kvInt_DioCriticalLevel = Intr_LL_EnterCritical();
    }
    kvInt_DioCriticalCount++;
}

void SchM_Exit_Dio_DIO_EXCLUSIVE_AREA_00(void)
{
    kvInt_DioCriticalCount--;
    if (kvInt_DioCriticalCount == 0U)
    {
        Intr_LL_ExitCritical(kvInt_DioCriticalLevel);
    }
    else
    {
        /* Avoid QAC 2000 Warning */
    }
}

/* EOF */
