/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Wdg_Im.h
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
#ifndef WDG_IM_H
#define WDG_IM_H

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
 **                        QAC Warnings
 ******************************************************************************/
/**
 * @page QAC Warnings
 *
 */

/******************************************************************************
 **                        Include Files
 ******************************************************************************/
#include "Wdg.h"
#include "dev_assert.h"
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
 * @brief start watch dog
 *
 *
 * @retval void
 */
void Wdg_Im_StartWdg(void);

/**
 * @brief stop watch dog
 *
 *
 * @retval void
 */
void Wdg_Im_StopWdg(void);

/**
 * @brief feed dog
 *
 *
 * @retval void
 */
void Wdg_Im_FeedDog(void);

/**
 * @brief Start the Timer
 * @param Ticks the cycle value
 *
 * @retval void
 */
void Wdg_Im_StartGpt(Wdg_ValueType Ticks);

/**
 * @brief Turn off the timer
 *
 *
 * @retval void
 */
void Wdg_Im_StopGpt(void);

/**
 * @brief clear timer isr flag
 *
 *
 * @retval void
 */
void Wdg_Im_ClearIsrFlag(void);

/**
 * @brief Set the overflow value of the watchdog
 * @param ReloadValue over flow value
 *
 * @retval void
 */
void Wdg_Im_SetOverFlowValue(Wdg_ValueType ReloadValue);

/**
 * @brief Preinit basic timer
 *
 *
 * @retval void
 */
void Wdg_Im_PreInitGpt(Wdg_ValueType Prescaler);

/**
 * @brief Preinit Iwdt
 *
 *
 * @retval void
 */
void Wdg_Im_PreInitIwdt(const Wdg_ConfigType *ConfigPtr);

/**
 * @brief Shut down the watchdog
 *
 *
 * @retval void
 */
void Wdg_Im_DeInit(void);

#ifdef __cplusplus
}
#endif

#endif
/* EOF */
