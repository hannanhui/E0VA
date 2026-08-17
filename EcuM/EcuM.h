/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : EcuM.h
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
#ifndef ECU_M_H
#define ECU_M_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 **                                             MISRA-C Rules Violations
 ******************************************************************************/
/**
 * @page misra_violations MISRA-C:2004 violations
 *
 * @section
 */

/******************************************************************************
 **                                                  QAC Warnings
 ******************************************************************************/
/**
 * @page QAC Warnings
 *
 */

/******************************************************************************
 **                                                         Include Files
 ******************************************************************************/
#include "Std_Types.h"
#include "EcuM_Types.h"
#include "EcuM_Cfg.h"
#include "EcuM_Cbk.h"
/******************************************************************************
 **                      File Version Check
 ******************************************************************************/

/******************************************************************************
 **                      Macro  Definitions
 ******************************************************************************/

/******************************************************************************
 **                      Typedef  Definitions
 ******************************************************************************/

/******************************************************************************
 **                      Export Variables
 ******************************************************************************/

/******************************************************************************
 **                      Export Functions
 ******************************************************************************/
/**
 * @brief This function sets the last wakeup event of the ECUM.
 *
 * @param source - last wakeup event
 * @return None
 */
void EcuM_SetWakeupEvent(EcuM_WakeupSourceType source);
/**
 * @brief Check wakeup events.
 *
 * @param source - The wakeup source that needs to be checked.
 * @return None
 */
void EcuM_CheckWakeup(EcuM_WakeupSourceType source);
#ifdef __cplusplus
}
#endif

#endif
/* EOF */
