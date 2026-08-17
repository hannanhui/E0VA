/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Mcu_Im.h
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
#ifndef MCU_IM_H
#define MCU_IM_H

/******************************************************************************
 *                      Include Files *
 ******************************************************************************/
#include "Mcu.h"
/******************************************************************************
 *                      Macro Definitions                                      *
 ******************************************************************************/
#ifdef MCU_INTERNAL_ASSERT
#include "dev_assert.h"
#define MCU_DEV_ASSERT(x) KF_DEV_ASSERT(x)
#else
#define MCU_DEV_ASSERT(x) ((void)0)
#endif
/******************************************************************************
 *                      Export Variables *
 ******************************************************************************/

/******************************************************************************
 *                      Typedef                                          *
 ******************************************************************************/

/******************************************************************************
 *                      Export Functions *
 ******************************************************************************/

/**
 * @brief Internal reference voltage configuration
 * @retval void
 * @return void
 */
FUNC(void, MCU_CODE) Mcu_Im_InternalRefVolConfig(void);

/**
 * @brief
 *
 * @param Mcu_HwConfigPtr
 * @retval void
 */
FUNC(void, MCU_CODE) Mcu_Im_Init(const Mcu_HwConfigType *const Mcu_HwConfigPtr);

/**
 * @brief
 *
 * @param RamConfig
 * @retval void
 *
 */
FUNC(Std_ReturnType, MCU_CODE) Mcu_Im_InitRam(const Mcu_RamConfigType *RamConfig);

#if (MCU_INIT_CLOCK == STD_ON)
/**
 * @brief
 *
 * @param ClockConfigPtr
 * @retval void
 */
FUNC(void, MCU_CODE) Mcu_Im_InitClock(const Mcu_ClockConfigType *const ClockConfigPtr);
#endif

/**
 * @brief
 *
 * @param McuMode
 * @retval void
 */
FUNC(boolean, MCU_CODE) Mcu_Im_SetMode(const Mcu_PowerConfigType *PowerModeConfig);

#if (MCU_INIT_CLOCK == STD_ON)
#if (MCU_NO_PLL == STD_OFF)
/**
 * @brief
 *
 * @param ClockConfigPtr
 * @retval void
 */
FUNC(void, MCU_CODE) Mcu_Im_DistributePllClock(const Mcu_ClockConfigType *const ClockConfigPtr);
#endif
#endif

#if (MCU_NO_PLL == STD_OFF)
/**
 * @brief
 *
 * @retval Mcu_PllStatusType
 */
FUNC(Mcu_PllStatusType, MCU_CODE) Mcu_Im_GetPllStatus(void);
#endif
/**
 * @brief
 *
 * @retval Mcu_ResetType
 */
FUNC(Mcu_ResetType, MCU_CODE) Mcu_Im_GetResetReason(void);

/**
 * @brief
 *
 * @retval Mcu_RawResetType
 */
Mcu_RawResetType Mcu_Im_GetResetRawValue(void);

/**
 * @brief Perform Mcu Reset
 *
 */
void Mcu_Im_Reset(void);

#if (MCU_IO_LATCH_STATE_IN_STANDBY == STD_ON)
/**
 * @brief set io latch state
 */
void Mcu_Im_LatchIO(boolean Enabled);
#endif

FUNC(void, MCU_CODE) Mcu_Im_SetBGMR(void);
FUNC(void, MCU_CODE) Mcu_Im_Delay(uint32 DelayTime);
#endif
