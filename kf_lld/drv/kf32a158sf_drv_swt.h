/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name        : kf32a158sf_drv_swt.h
 *  @Date             : 2025-07-08
 *  @Version          : {{VersionDate}}
 *  @Description      : This file provides
 ******************************************************************************
 *  Copyright (C) by Shanghai ChipON Micro-Electronic Co.,Ltd
 *  All rights reserved.
 *
 *  This software is copyright protected and proprietary to
 *  Shanghai ChipON Micro-Electronic Co.,Ltd.
 *****************************************************************************/
/******************************************************************************
 *  |Date        |Version  |Author       |Description
 *******************************************************************************
 *  |2025-07-08  |V1.0     |AE Group     |New create
 ******************************************************************************/
#ifndef KF32A158SF_DRV_SWT_H
#define KF32A158SF_DRV_SWT_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 *                      QAC Warnings
 ******************************************************************************/
/* PRQA S 0288 EOF #KQR000288 */
/* PRQA S 0303,0306 EOF #KQR100303 */
/* PRQA S 3219 EOF #KQR003219 */
/******************************************************************************
 *                      Include Files
 ******************************************************************************/
#include <stdint.h>
#include <stdbool.h>
#include "kf_types.h"
#include "kf32a158sf_reg_swt.h"

#ifdef KF_DRV_SWT_ASSERT
#include "dev_assert.h"
#define KF_SWT_ASSERT(x) KF_DEV_ASSERT(x)
#else
#define KF_SWT_ASSERT(x) ((void)0U)
#endif
/******************************************************************************
 *                      Macro or Inline
 ******************************************************************************/

/******************************************************************************
 *                      Type definitions
 ******************************************************************************/

/**
 * SWT秒定时器重加载寄存器的值
 */
#define CHECK_SWT_RELOAD(SYS) (((SYS) >> 24U) == 0U)

/******************************************************************************
 *                      Export Variables
 ******************************************************************************/

/******************************************************************************
 *                      Export Functions
 ******************************************************************************/

/**
 * @brief 秒定时器(SWT)启动控制使能
 * @param State:
 *          true   使能系统节拍定时器
 *          false   禁止系统节拍定时器
 * @retval void
 */
KF_INLINE void Swt_LL_SetEnabled(bool State)
{
    SWT_RM.CTL.bits.SWTEN = State ? 1U : 0U;
}

/**
 * @brief 秒定时器(SWT)中断使能配置.
 * @param State:
 *          true   计数到0发送SWT中断请求
 *          false   计数到0不发送SWT中断请求
 * @retval void
 */
KF_INLINE void Swt_LL_SetIntrEnabled(bool State)
{

    SWT_RM.CTL.bits.TICKINTEN = State ? 1U : 0U;
}

/**
 * @brief 秒定时器(SWT)时钟源配置.
 * @param State:
 *          true   SCLK 作为时钟
 *          false   SCLK/2 作为时钟
 * @retval void
 * 注:如果ST_CALI寄存器的SWTCLKREF位为1,SWT配置SCLK/2作为时钟是配置不成功的
 */
KF_INLINE void Swt_LL_SetClockDivision(bool State)
{

    SWT_PTR->CTL.bits.SWTCLKS = State ? 1U : 0U;
}

/**
 * @brief 读取节拍定时器计数零标志.
 * @param void
 * @retval bool 节拍定时器计数到零的标志,0:计数未到零,1:计数到零.
 */
KF_INLINE bool Swt_LL_GetCountZeroFlag(void)
{
    return (SWT_PTR->CTL.bits.COUNTSET != 0U);
}

/**
 * @brief 秒定时器(SWT)重加载寄存器配置.
 * @param Reload: 系统节拍定时器重加载值,节拍定时器的周期值为重加载值加1.
 *                取值为24位数据.
 * @retval void
 */
KF_INLINE void Swt_LL_SetReloadValue(uint32_t ReloadValue)
{
    /* 参数校验 */
    KF_SWT_ASSERT(CHECK_SWT_RELOAD(ReloadValue));
    SWT_PTR->SETNUM = ReloadValue;
}

/**
 * @brief 读取系统节拍定时器计数器.
 * @param void
 * @retval uint32_t 当前计数值,24位有效数据.
 */
KF_INLINE uint32_t Swt_LL_GetCounter(void)
{
    return SWT_RM.CV;
}

/**
 * @brief 计数器值清零
 * @param void
 * @retval void
 */
KF_INLINE void Swt_LL_UpdateCounter(void)
{
    SWT_PTR->CV = 0U;
}

/**
 * @brief 系统时钟选择控制，该位与校验值配合使用.
 * @param State:
 *          true   选择 SCLK 作为节拍定时器的时钟
 *          false   无作用(由 SWTCLKS 确定选择结果)
 * @retval void
 * 注:该位与 CTL 寄存器的 SWTCLKS位共同控制选择结果，两者任意一位值为1时选择 SCLK 作为时钟
 */
KF_INLINE void Swt_LL_SetSystemClock(bool State)
{
    SWT_PTR->CALI.bits.SWTCLKREF = State ? 1U : 0U;
}

#ifdef __cplusplus
}
#endif /*End of __cplusplus*/
#endif /*End of KF32A158SF_DRV_SWT_H*/
/* EOF */
