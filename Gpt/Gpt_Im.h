/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Gpt_Im.h
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
#ifndef GPT_IM_H
#define GPT_IM_H

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
#include "Gpt.h"
/******************************************************************************
 **                      File Version Check
 ******************************************************************************/

/******************************************************************************
 **                      Macro  Definitions
 ******************************************************************************/

#ifdef GPT_INTERNAL_ASSERT
#include "dev_assert.h"
#define GPT_DEV_ASSERT(x) KF_DEV_ASSERT(x)
#else
#define GPT_DEV_ASSERT(x) ((void)0)
#endif

#define KF_BASIC_TIMER   ((uint8)0x00U)
#define KF_GENERAL_TIMER ((uint8)0x01U)

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
 * @brief Initiate Specific Timer Channel
 *
 * @param chanHwIdx Index for hardware channel
 * @param clkSrc Clock Source
 * @param clkPrescale Clock Prescale
 */
void Gpt_Im_Init(const Gpt_TimerEnumType ChanHwIdx, const Gpt_ClkSourceType ClkSrc, const uint32 ClkPrescale);

/**
 * @brief Deinit Specific Timer Channel
 *
 * @param chanHwIdx Timer Hardware  Base Address
 */
void Gpt_Im_Deinit(const Gpt_TimerEnumType ChanHwIdx);

/**
 * @brief Start Timer Channel
 *
 * @param ChanHwIdx
 * @param TimeoutValue Time Out Counter
 * @param ChanMode
 */
void Gpt_Im_StartTimer(const Gpt_TimerEnumType ChanHwIdx, const uint32 TimeoutValue, Gpt_ChannelModeType ChanMode);

/**
 * @brief Stop the specific Timer Channel
 *
 * @param chanHwIdx
 */
void Gpt_Im_StopTimer(const Gpt_TimerEnumType ChanHwIdx);

/**
 * @brief Get Timer Channel Elapsed Time
 *
 * @param chanHwIdx
 * @return Gpt_ValueType
 */
Gpt_ValueType Gpt_Im_GetTimeElapsed(const Gpt_TimerEnumType ChanHwIdx);

/**
 * @brief Get Timer Channel Remaining Time
 *
 * @param chanHwIdx
 * @return Gpt_ValueType
 */
Gpt_ValueType Gpt_Im_GetTimeRemaining(const Gpt_TimerEnumType ChanHwIdx);

/**
 * @brief Disable Hardware Channel Interrupt Bit
 *
 * @param chanHwIdx
 */
void Gpt_Im_DisableInterrupt(const Gpt_TimerEnumType ChanHwIdx);

/**
 * @brief Enable Hardware Channel Interrupt Bit
 *
 * @param chanHwIdx
 */
void Gpt_Im_EnableInterrupt(const Gpt_TimerEnumType ChanHwIdx);

/**
 * @brief Clear Hardware Channel Interrupt Bit
 *
 * @param chanHwIdx
 */
void Gpt_Im_ClearInterrupt(const Gpt_TimerEnumType ChanHwIdx);

#if (GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)

/**
 * @brief Start Pre-defined Timer, Only T21 Available
 *
 * @param predefConfig
 */
void Gpt_Im_StartPredefTimer(const Gpt_PredefTimeConfigType *const PredefConfig);

/**
 * @brief Stop Pre-defined Timer, Only T21 Available
 *
 * @param predefConfig
 */
void Gpt_Im_StopPredefTimer(const Gpt_PredefTimeConfigType *const PredefConfig);

/**
 * @brief Get Pre-defined Timer Current Counter Value, Only T21 Available
 *
 * @param predefConfig
 * @param predefTimer
 * @retval uint32 T21 Counter Value
 */
uint32
Gpt_Im_GetPredefTimerValue(const Gpt_PredefTimeConfigType *const PredefConfig, const Gpt_PredefTimerType PredefTimer);
#endif

#ifdef __cplusplus
}
#endif

#endif
/* EOF */
