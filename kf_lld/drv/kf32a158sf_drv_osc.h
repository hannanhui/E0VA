/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name        : kf32a158sf_drv_osc.h
 *  @Date             : 2025-07-07
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
 *  |2025-07-07  |V1.0     |AE Group     |New create
 ******************************************************************************/
#ifndef KF32A158SF_DRV_OSC_H
#define KF32A158SF_DRV_OSC_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 *                      QAC Warnings
 ******************************************************************************/
/* PRQA S 3205 EOF #KQR003205 */
/* PRQA S 3219 EOF #KQR003219 */
/* PRQA S 4342 EOF #KQR004342 */
/******************************************************************************
 *                      Include Files
 ******************************************************************************/
#include "kf32a158sf_oscclk_base.h"
#include "kf32a158sf_reg_osc.h"
#include "kf_types.h"
#include <stdbool.h>
#include <stdint.h>

#ifdef KF_DRV_OSC_ASSERT
#include "dev_assert.h"
#define KF_OSC_ASSERT(x) KF_DEV_ASSERT(x)
#else
#define KF_OSC_ASSERT(x) ((void)0U)
#endif
/******************************************************************************
 *                      Macro or Inline
 ******************************************************************************/

/******************************************************************************
 *                      Type definitions
 ******************************************************************************/

/**OSC设置中断序号*/
typedef enum
{
    OSC_INTR_SET_ILFIE  = 8U,
    OSC_INTR_SET_IHFIE  = 9U,
    OSC_INTR_SET_ELFIE  = 10U,
    OSC_INTR_SET_EHFIE  = 11U,
    OSC_INTR_SET_PLL0IE = 12U,
    OSC_INTR_SET_PLL1IE = 13U,
    OSC_INTR_SET_LPHFIE = 14U,
    OSC_INTR_SET_LPLFIE = 24U,
} Osc_IntrSetIndex_t;
#define CHECK_OSC_INTRSETINDEX(x)                                                                                      \
    ((((x) >= OSC_INTR_SET_ILFIE) && ((x) <= OSC_INTR_SET_LPHFIE)) || ((x) == OSC_INTR_SET_LPLFIE))

/**OSC获取中断序号*/
typedef enum
{
    OSC_INTR_GET_ILFIF  = 0U,
    OSC_INTR_GET_IHFIF  = 1U,
    OSC_INTR_GET_ELFIF  = 2U,
    OSC_INTR_GET_EHFIF  = 3U,
    OSC_INTR_GET_PLL0IF = 4U,
    OSC_INTR_GET_PLL1IF = 5U,
    OSC_INTR_GET_LPHFIF = 6U,
    OSC_INTR_GET_CKFIF  = 7U,
    OSC_INTR_GET_LPLFIF = 16U,
} Osc_IntrGetIndex_t;
#define CHECK_OSC_INTRGETINDEX(x)                                                                                      \
    ((((x) >= OSC_INTR_GET_ILFIF) && ((x) <= OSC_INTR_GET_CKFIF)) || ((x) == OSC_INTR_GET_LPLFIF))

/**OSC清除中断序号*/
typedef enum
{
    OSC_INTR_CLEAR_ILFIF  = 0U,
    OSC_INTR_CLEAR_IHFIF  = 1U,
    OSC_INTR_CLEAR_ELFIF  = 2U,
    OSC_INTR_CLEAR_EHFIF  = 3U,
    OSC_INTR_CLEAR_PLL0IF = 4U,
    OSC_INTR_CLEAR_PLL1IF = 5U,
    OSC_INTR_CLEAR_LPHFIF = 6U,
    OSC_INTR_CLEAR_CKFIF  = 7U,
    OSC_INTR_CLEAR_LPLFIF = 16U,
} Osc_IntrClearIndex_t;
#define CHECK_OSC_INTRCLEARINDEX(x)                                                                                    \
    ((((x) >= OSC_INTR_CLEAR_ILFIF) && ((x) <= OSC_INTR_CLEAR_CKFIF)) || ((x) == OSC_INTR_CLEAR_LPLFIF))

/* PMC Frequency division coefficient */
typedef enum
{
    OSC_PMC_DIVISION_1  = 0,
    OSC_PMC_DIVISION_4  = 1,
    OSC_PMC_DIVISION_8  = 2,
    OSC_PMC_DIVISION_16 = 3,
} Osc_PmcDivision_t;
#define CHECK_OSC_PMC_DIVISION(DIV) ((uint32_t)(DIV) <= (uint32_t)OSC_PMC_DIVISION_16)
/******************************************************************************
 *                      Export Variables
 ******************************************************************************/

/******************************************************************************
 *                      Export Functions
 ******************************************************************************/

/*  OSC_CTL0 */

/**
 * @brief PM相关寄存器读写使能配置
 * @param State:
 *          true   备份区可读写
 *          false   备份区不可读写
 * @retval void
 */
KF_INLINE void Osc_LL_SetBackupWriteAndReadEnabled(bool State)
{

    OSC_PTR->CTL0.bits.PMWREN = (State ? 1U : 0U);
}

/**
 * @brief 配置SCLK主时钟选择
 * @param SclkSource: SCLK主时钟选择,取值范围为 Osc_SclkSrc_t
 * @retval void
 */
KF_INLINE void Osc_LL_SelectSclkClockSource(Osc_SclkSrc_t SclkSource)
{
    KF_OSC_ASSERT(CHECK_OSC_SCLK_SRC(SclkSource));

    OSC_PTR->CTL0.bits.SCKS = (uint32_t)SclkSource;
}

/**
 * @brief 获取SCLK主时钟
 * @param void
 * @retval SclkSource: SCLK主时钟
 */
KF_INLINE Osc_SclkSrc_t Osc_LL_GetSclkSourceClock(void)
{
    return (Osc_SclkSrc_t)OSC_PTR->CTL0.bits.SCKS;
}

/**
 * @brief 低频外设时钟使能配置
 * @param State:
 *          true   LFCLK使能
 *          false   LFCLK失能
 * @retval void
 */
KF_INLINE void Osc_LL_SetLfclkEnabled(bool State)
{

    OSC_PTR->CTL0.bits.LFCKEN = (State ? 1U : 0U);
}

/**
 * @brief 配置高频外设时钟源选择
 * @param LFSource: 低频外设时钟源选择,取值范围为 Osc_LfclkSrc_t
 * @retval void
 */
KF_INLINE void Osc_LL_SelectLfclkClockSource(Osc_LfclkSrc_t LfclkSource)
{
    KF_OSC_ASSERT(CHECK_OSC_LFCLK_SRC(LfclkSource));

    OSC_PTR->CTL0.bits.LFCKS = (uint32_t)LfclkSource;
}

/**
 * @brief 高频外设时钟使能配置
 * @param State:
 *          true   HFCLK使能
 *          false   HFCLK不使能
 * @retval void
 */
KF_INLINE void Osc_LL_SetHfclkEnabled(bool State)
{

    OSC_PTR->CTL0.bits.HFCKEN = (State ? 1U : 0U);
}

/**
 * @brief 配置高频外设时钟源选择
 * @param HFSource: 高频外设时钟源选择,取值范围为 Osc_HfclkSrc_t
 * @retval void
 */
KF_INLINE void Osc_LL_SelectHfclkClockSource(Osc_HfclkSrc_t HfclkSource)
{
    KF_OSC_ASSERT(CHECK_OSC_HFCLK_SRC(HfclkSource));

    OSC_PTR->CTL0.bits.HFCKS = (uint32_t)HfclkSource;
}

/**
 * @brief 配置PLL0输入时钟源选择
 * @param Source: PLL0输入时钟源选择,取值范围为 Osc_PllInput_t
 * @retval void
 */
KF_INLINE void Osc_LL_SelectPll0ClockSource(Osc_PllInput_t Source)
{
    KF_OSC_ASSERT(CHECK_OSC_PLL_INPUT(Source));

    OSC_PTR->CTL0.bits.PLL0CKS = (uint32_t)Source;
}

/**
 * @brief 配置PLL1输入时钟源选择
 * @param Source: PLL1输入时钟源选择,取值范围为 Osc_PllInput_t
 * @retval void
 */
KF_INLINE void Osc_LL_SelectPll1ClockSource(Osc_PllInput_t Source)
{
    KF_OSC_ASSERT(CHECK_OSC_PLL_INPUT(Source));

    OSC_PTR->CTL0.bits.PLL1CKS = (uint32_t)Source;
}

/**
 * @brief 配置主时钟SCLK分频选择
 * @param SclkDiv: 主时钟SCLK分频选择,取值范围为 Osc_SclkDivision_t
 * @retval void
 */
KF_INLINE void Osc_LL_SetSclkDivision(Osc_SclkDivision_t SclkDiv)
{
    KF_OSC_ASSERT(CHECK_OSC_SCLK_DIVISION(SclkDiv));

    OSC_PTR->CTL0.bits.SCKDIV = (uint32_t)SclkDiv;
}

/**
 * @brief 配置主时钟SCLK分频选择
 * @param void
 * @retval void
 */
KF_INLINE Osc_SclkDivision_t Osc_LL_GetSclkDivision(void)
{
    return (Osc_SclkDivision_t)OSC_PTR->CTL0.bits.SCKDIV;
}

/**
 * @brief 配置高频外设时钟分频选择
 * @param HfclkDiv: 高频外设时钟分频选择,取值范围为 Osc_HfclkDivision_t
 * @retval void
 */
KF_INLINE void Osc_LL_SetHfclkDivision(Osc_HfclkDivision_t HfclkDiv)
{
    KF_OSC_ASSERT(CHECK_OSC_HFCLK_DIVISION(HfclkDiv));

    OSC_PTR->CTL0.bits.HFCKDIV = (uint32_t)HfclkDiv;
}

/**
 * @brief 配置低频外设时钟分频选择
 * @param LfclkDiv: 低频外设时钟分频选择,取值范围为 Osc_LfclkDivision_t
 * @retval void
 */
KF_INLINE void Osc_LL_SetLfclkDivision(Osc_LfclkDivision_t LfclkDiv)
{
    KF_OSC_ASSERT(CHECK_OSC_LFCLK_DIVISION(LfclkDiv));

    OSC_PTR->CTL0.bits.LFCKDIV = (uint32_t)LfclkDiv;
}

/**
 * @brief 配置PLL0输入时钟源2分频使能
 * @param State:
 *          true   PLL1输入时钟源2分频
 *          false   PLL1输入时钟源不分频
 * @retval void
 */
KF_INLINE void Osc_LL_SetPll0Division(bool State)
{

    OSC_PTR->CTL0.bits.PLL0DIV = (State ? 1U : 0U);
}

/**
 * @brief 配置PLL1输入时钟源2分频使能
 * @param State:
 *          true   PLL1输入时钟源2分频
 *          false   PLL1输入时钟源不分频
 * @retval void
 */
KF_INLINE void Osc_LL_SetPll1Division(bool State)
{

    OSC_PTR->CTL0.bits.PLL1DIV = (State ? 1U : 0U);
}

/**
 * @brief 配置PLL0锁定检测使能
 * @param State:
 *          true   使能 PLL0 锁定检测
 *          false   不使能 PLL0 锁定检测
 * @retval void
 */
KF_INLINE void Osc_LL_SetPll0LockDetectEnabled(bool State)
{

    OSC_PTR->CTL0.bits.LKDT0EN = (State ? 1U : 0U);
}

/**
 * @brief 配置PLL1锁定检测使能
 * @param State:
 *          true   使能 PLL1 锁定检测
 *          false   不使能 PLL1 锁定检测
 * @retval void
 */
KF_INLINE void Osc_LL_SetPll1LockDetectEnabled(bool State)
{

    OSC_PTR->CTL0.bits.LKDT1EN = (State ? 1U : 0U);
}

/*  OSC_CTL1 */

/**
 * @brief 配置LPHF启动延迟控制
 * @param LphfDelay: LPHF启动延迟控制,取值范围为 OSC_LphfStartDelay_t
 * @retval void
 */
KF_INLINE void Osc_LL_SetLphfStartDelay(OSC_LphfStartDelay_t LphfDelay)
{
    KF_OSC_ASSERT(CHECK_OSC_LPHF_START_DELAY(LphfDelay));

    OSC_PTR->CTL1.bits.LPHFDLY = (uint32_t)LphfDelay;
}

/**
 * @brief 允许/禁止 STOP0 模式清零时钟稳定标志位
 * @param State:
 *          true   允许 STOP0 模式清零时钟稳定标志位
 *          false  禁止 STOP0 模式清零时钟稳定标志位
 * @retval void
 */
KF_INLINE void Osc_LL_SetStop0ClearClockStableFlagEnabled(bool State)
{

    OSC_PTR->CTL1.bits.TESTEN_STOP = (State ? 1U : 0U);
}

/**
 * @brief 配置 外部高频时钟输出迟滞整形模式 使能状态
 * @param State:
 *  true   使能
 *  false  禁止
 * @retval void
 */
KF_INLINE void Osc_LL_SetHseOutputHysteresisEnabled(bool State)
{
    OSC_PTR->CTL1.bits.HSEHYEN = (State ? 1U : 0U);
}

/**
 * @brief 高频外设时钟使能配置
 * @param State:
 *          true   HFCLK1使能
 *          false   HFCLK1不使能
 * @retval void
 */
KF_INLINE void Osc_LL_SetHfclk1Enabled(bool State)
{

    OSC_PTR->CTL1.bits.HF1CKEN = (State ? 1U : 0U);
}

/**
 * @brief 配置高频外设时钟源选择
 * @param HfclkSource: 高频外设时钟源选择,取值范围为 Osc_HfclkSrc_t
 * @retval void
 */
KF_INLINE void Osc_LL_SelectHfclk1ClockSource(Osc_HfclkSrc_t HfclkSource)
{
    KF_OSC_ASSERT(CHECK_OSC_HFCLK_SRC(HfclkSource));

    OSC_PTR->CTL1.bits.HF1CKS = (uint32_t)HfclkSource;
}

/**
 * @brief 配置高频外设时钟1分频选择
 * @param HfclkDiv: 高频外设时钟分频选择,取值范围为 Osc_HfclkDivision_t
 * @retval void
 */
KF_INLINE void Osc_LL_SetHfclk1Division(Osc_HfclkDivision_t HfclkDiv)
{
    KF_OSC_ASSERT(CHECK_OSC_HFCLK_DIVISION(HfclkDiv));

    OSC_PTR->CTL1.bits.HF1CKDIV = (uint32_t)HfclkDiv;
}

/**
 * @brief 选择PMC 工作时钟分频
 * @param PmcDiv: PMC 工作时钟分频,取值范围为 Osc_PmcDivision_t
 * @retval void
 */
KF_INLINE void Osc_LL_SetPmcDivision(Osc_PmcDivision_t PmcDiv)
{
    KF_OSC_ASSERT(CHECK_OSC_PMC_DIVISION(PmcDiv));

    OSC_PTR->CTL1.bits.SCLKPMCDIV = (uint32_t)PmcDiv;
}

/**
 * @brief 配置时钟故障检测使能
 * @param State:
 *          true   时钟故障检测使能
 *          false   时钟故障检测使能不使能
 * @retval void
 */
KF_INLINE void Osc_LL_SetFscmEnabled(bool State)
{

    OSC_PTR->CTL1.bits.FSCM = (State ? 1U : 0U);
}

/**
 * @brief 配置时钟故障检测间隔
 * @param FscmGap: 时钟故障检测间隔选择,取值范围为 Osc_FscmGap_t
 * @retval void
 */
KF_INLINE void Osc_LL_SetFscmGap(Osc_FscmGap_t FscmGap)
{
    KF_OSC_ASSERT(CHECK_OSC_FSCM_GAP(FscmGap));

    OSC_PTR->CTL1.bits.FSCMGAP = (uint32_t)FscmGap;
}

/**
 * @brief 配置时钟故障检测源
 * @param FscmClkSrc: 时钟故障检测使能状态,取值范围为 Osc_FscmSrc_t
 * @retval void
 */
KF_INLINE void Osc_LL_SelectFscmClockSource(Osc_FscmSrc_t FscmClkSrc)
{
    KF_OSC_ASSERT(CHECK_OSC_FSCM_SOURCE(FscmClkSrc));

    OSC_PTR->CTL1.bits.FSCMS = (uint32_t)FscmClkSrc;
}

/**
 * @brief 配置从引脚 CLKOUT 输出时钟选择
 * @param OutputSrc: 输出时钟选择,可见 Osc_ClkOutSrc_t
 * @retval void
 */
KF_INLINE void Osc_LL_SelectClkOutClockSource(Osc_ClkOutSrc_t OutputSrc)
{
    KF_OSC_ASSERT(CHECK_OSC_CLKOUT_SOURCE(OutputSrc));

    OSC_PTR->CTL1.bits.CLKOUTS = (uint32_t)OutputSrc;
}

/**
 * @brief 配置时钟输出使能
 * @param State:
 *          true   允许CLKOUT引脚输出时钟
 *          false   禁止CLKOUT引脚输出时钟
 * @retval void
 */
KF_INLINE void Osc_LL_SetClkOutEnabled(bool State)
{

    OSC_PTR->CTL1.bits.CLKOE = (State ? 1U : 0U);
}

/**
 * @brief 配置输出时钟分频选择
 * @param OutputDiv: CLK输出时钟分频选择位,取值范围为 Osc_ClkoutDivision_t
 * @retval void
 */
KF_INLINE void Osc_LL_SetClkOutDivision(Osc_ClkOutDivision_t OutputDiv)
{
    KF_OSC_ASSERT(CHECK_OSC_CLKOUT_DIVISION(OutputDiv));

    OSC_PTR->CTL1.bits.CLKOUTDIV = (uint32_t)OutputDiv;
}

/*  OSC_INT */

/**
 * @brief 设置OSC中断使能状态
 *
 * @param IntIndex 设置中断序号, 可见 Osc_IntrSetIndex_t
 * @param State 使能状态
 * @retval void
 */
KF_INLINE void Osc_LL_SetIntrEnabled(Osc_IntrSetIndex_t IntIndex, bool State)
{
    KF_OSC_ASSERT(CHECK_OSC_INTRSETINDEX(IntIndex));

    /* PRQA S 3473 1 #KQR003473 */
    REG_BITS_WRITE(OSC_PTR->INT.reg, (1UL << (uint32_t)IntIndex), ((State ? 1UL : 0UL) << (uint32_t)IntIndex));
}

/**
 * @brief 获取中断标志
 *
 * @param IntIndex 获取中断序号, 见 Osc_IntrGetIndex_t
 * @return bool 中断标志状态
 */
KF_INLINE bool Osc_LL_GetIntrFlag(Osc_IntrGetIndex_t IntIndex)
{
    KF_OSC_ASSERT(CHECK_OSC_INTRGETINDEX(IntIndex));

    /* PRQA S 3469 1 #KQR003469 */
    return (REG_BITS_READ(OSC_PTR->INT.reg, (1UL << (uint32_t)IntIndex), (uint32_t)IntIndex) != 0U);
}

/**
 * @brief 清除OSC中断标志
 *
 * @param IntIndex 清除中断序号, 见 Osc_IntrClearIndex_t
 * @return void
 */
KF_INLINE void Osc_LL_ClearIntrFlag(Osc_IntrClearIndex_t IntIndex)
{
    KF_OSC_ASSERT(CHECK_OSC_INTRCLEARINDEX(IntIndex));

    /* PRQA S 3473 1 #KQR003473 */
    REG_BIT_CLR(OSC_PTR->INT.reg, (1UL << (uint32_t)IntIndex));
}

/*  OSC_CTL2 */
/**
 * @brief 配置INTLF软件使能
 * @param State:
 *          true   内部低频振荡器工作使能
 *          false   内部低频振荡器工作禁止
 * @retval void
 */
KF_INLINE void Osc_LL_SetIntlfSoftwareEnabled(bool State)
{

    OSC_PTR->CTL2.bits.INTLFSWEN = (State ? 1U : 0U);
}

/**
 * @brief 配置INTHF软件使能
 * @param State:
 *          true   内部高频振荡器工作使能
 *          false   内部高频振荡器工作禁止
 * @retval void
 */
KF_INLINE void Osc_LL_SetInthfSoftwareEnabled(bool State)
{

    OSC_PTR->CTL2.bits.INTHFSWEN = (State ? 1U : 0U);
}

/**
 * @brief 配置EXTLF软件使能
 * @param State:
 *          true   外部低频振荡器工作使能
 *          false   外部低频振荡器工作禁止
 * @retval void
 */
KF_INLINE void Osc_LL_SetExtlfSoftwareEnabled(bool State)
{

    OSC_PTR->CTL2.bits.EXTLFSWEN = (State ? 1U : 0U);
}

/**
 * @brief 配置EXTHF软件使能
 * @param State:
 *          true   外部高频振荡器工作使能
 *          false   外部高频振荡器工作禁止
 * @retval void
 */
KF_INLINE void Osc_LL_SetExthfSoftwareEnabled(bool State)
{

    OSC_PTR->CTL2.bits.EXTHFSWEN = (State ? 1U : 0U);
}

/**
 * @brief 配置PLL0软件使能
 * @param State:
 *          true   PLL0 工作使能
 *          false   PLL0 工作禁止
 * @retval void
 */
KF_INLINE void Osc_LL_SetPll0SoftwareEnabled(bool State)
{

    OSC_PTR->CTL2.bits.PLL0SWEN = (State ? 1U : 0U);
}

/**
 * @brief 获取PLL0软件使能配置
 * @param void
 * @retval bool
 *          true   PLL0 工作使能
 *          false   PLL0 工作禁止
 */
KF_INLINE bool Osc_LL_GetPll0SoftwareEnableState(void)
{
    return (OSC_PTR->CTL2.bits.PLL0SWEN != 0U);
}

/**
 * @brief 配置PLL1软件使能
 * @param State:
 *          true   PLL1 工作使能
 *          false   PLL1 工作禁止
 * @retval void
 */
KF_INLINE void Osc_LL_SetPll1SoftwareEnabled(bool State)
{

    OSC_PTR->CTL2.bits.PLL1SWEN = (State ? 1U : 0U);
}

/**
 * @brief 获取PLL1软件使能配置
 * @param State:
 *          true   PLL1 工作使能
 *          false   PLL1 工作禁止
 * @retval void
 */
KF_INLINE bool Osc_LL_GetPll1SoftwareEnableState(void)
{

    return (OSC_PTR->CTL2.bits.PLL1SWEN != 0U);
}

/**
 * @brief 配置INTLF启动延迟控制
 * @param IntlfDelay: 内部低频启动延迟控制,取值范围为 Osc_IntlfStartDelay_t
 * @retval void
 */
KF_INLINE void Osc_LL_SetIntlfStartDelay(Osc_IntlfStartDelay_t IntlfDelay)
{
    KF_OSC_ASSERT(CHECK_OSC_INTLF_START_DELAY(IntlfDelay));

    OSC_PTR->CTL2.bits.ILFDLY = (uint32_t)IntlfDelay;
}

/**
 * @brief 配置INTHF启动延迟控制
 * @param InthfDelay: 内部高频启动延迟控制,取值范围为 Osc_InthfStartDelay_t
 * @retval void
 */
KF_INLINE void Osc_LL_SetInthfStartDelay(Osc_InthfStartDelay_t InthfDelay)
{
    KF_OSC_ASSERT(CHECK_OSC_INTHF_START_DELAY(InthfDelay));

    OSC_PTR->CTL2.bits.IHFDLY = (uint32_t)InthfDelay;
}

/**
 * @brief 配置EXTLF启动延迟控制
 * @param ExternalDelay: 外部低频启动延迟控制,取值范围为 Osc_ExtStartDelay_t
 * @retval void
 */
KF_INLINE void Osc_LL_SetExtlfStartDelay(Osc_ExtStartDelay_t ExternalDelay)
{
    KF_OSC_ASSERT(CHECK_OSC_EXT_START_DELAY(ExternalDelay));

    OSC_PTR->CTL2.bits.ELFDLY = (uint32_t)ExternalDelay;
}

/**
 * @brief 配置EXTHF启动延迟控制
 * @param ExternalDelay: 外部高频启动延迟控制,取值范围为 Osc_ExtStartDelay_t
 * @retval void
 */
KF_INLINE void Osc_LL_SetExthfStartDelay(Osc_ExtStartDelay_t ExternalDelay)
{
    KF_OSC_ASSERT(CHECK_OSC_EXT_START_DELAY(ExternalDelay));

    OSC_PTR->CTL2.bits.EHFDLY = (uint32_t)ExternalDelay;
}

/**
 * @brief 配置PLL0启动延迟控制
 * @param PllDelay: PLL启动延迟控制,取值范围为 Osc_PllStartDelay_t
 * @retval void
 */
KF_INLINE void Osc_LL_SetPll0StartDelay(Osc_PllStartDelay_t PllDelay)
{
    KF_OSC_ASSERT(CHECK_OSC_PLL_START_DELAY(PllDelay));

    OSC_PTR->CTL2.bits.PLL0DLY = (uint32_t)PllDelay;
}

/**
 * @brief 配置PLL1启动延迟控制
 * @param PllDelay: PLL启动延迟控制,取值范围为 Osc_PllStartDelay_t
 * @retval void
 */
KF_INLINE void Osc_LL_SetPll1StartDelay(Osc_PllStartDelay_t PllDelay)
{
    KF_OSC_ASSERT(CHECK_OSC_PLL_START_DELAY(PllDelay));

    OSC_PTR->CTL2.bits.PLL1DLY = (uint32_t)PllDelay;
}

/**
 * @brief 外部高频外部输入时钟使能，实际寄存器写入值与传入值相反，见用户手册5.3.5
 * @param State:
 *          true   外部高频晶振可以从XTH_IN输入时钟源
 *          false   外部高频晶振不可以从XTH_IN输入时钟源
 * @retval void
 */
KF_INLINE void Osc_LL_SetExthfExternalInputEnabled(bool State)
{

    OSC_PTR->CTL3.bits.HSXTALEXEN = (State ? 0U : 1U);
}

/**
 * @brief 外部高频的驱动模式配置
 * @param State:
 *          true   外部高频晶振使用反相器驱动模式
 *          false   保留
 * @retval void
 */
KF_INLINE void Osc_LL_SetExthfDriveMode(bool State)
{

    OSC_PTR->CTL3.bits.HSEMODESEL = (State ? 1U : 0U);
}

/**
 * @brief 外部高频晶振驱动调节档位选择
 * @param Value: 外部高频晶振驱动调节档位, 可见 Osc_ExthfDriveWeights_t
 * @retval void
 */
KF_INLINE void Osc_LL_SelectExthfDriverWeightsAdjust(Osc_ExthfDriveWeights_t Value)
{
    KF_OSC_ASSERT(CHECK_OSC_EXTHF_DRIVE_WEIGHTS(Value));

    OSC_PTR->CTL3.bits.GMBOOST = (uint32_t)Value;
}

/**
 * @brief 外部高频晶振内部并联2M使能
 * @param State:
 *          true   内部并联2M开启
 *          false   内部并联2M关闭
 * @retval void
 */
KF_INLINE void Osc_LL_SetXthr2mEnabled(bool State)
{

    OSC_PTR->CTL3.bits.XTHR2M = (State ? 1U : 0U);
}

/**
 * @brief 外部高频晶振内部并联470K使能
 * @param State:
 *          true   内部并联470K开启
 *          false   内部并联470K关闭
 * @retval void
 */
KF_INLINE void Osc_LL_SetXthr470kEnabled(bool State)
{

    OSC_PTR->CTL3.bits.XTHR470K = (State ? 1U : 0U);
}

/**
 * @brief 外部高频晶振内部并联200K使能
 * @param State:
 *          true   内部并联200K开启
 *          false   内部并联200K关闭
 * @retval void
 */
KF_INLINE void Osc_LL_SetXthr200kEnabled(bool State)
{

    OSC_PTR->CTL3.bits.XTHR200K = (State ? 1U : 0U);
}

/**
 * @brief 外部高频晶振的比较器时钟整形使能控制
 * @param State:
 *          true   外部高频晶振比较器时钟整形开启
 *          false   外部高频晶振比较器时钟整形关闭
 * @retval void
 */
KF_INLINE void Osc_LL_SetExthfCmpClkShapingEnabled(bool State)
{

    OSC_PTR->CTL3.bits.XTHCOMPEN = (State ? 1U : 0U);
}

/**
 * @brief 外部高频晶振的比较器电流调整
 * @param Value 比较器电流, Osc_ExthfCmpBiasCurrent_t
 * @retval void
 */
KF_INLINE void Osc_LL_SelectExthfCmpBiasCurrentAdjust(Osc_ExthfCmpBiasCurrent_t Value)
{
    KF_OSC_ASSERT(CHECK_OSC_EXTHF_CMP_BIAS_CURRENDT(Value));

    OSC_PTR->CTL3.bits.XTHCOMPI = (uint32_t)Value;
}

/*  PLL_PLL0CTRL */

/**
 * @brief PLL0复位控制
 * @param  void
 * @retval void
 */
KF_INLINE void Osc_LL_SetPll0Reset(void)
{
    PLL0_PTR->CTL.bits.PDRST = 1U;
}

/**
 * @brief PLL1复位控制
 * @param  void
 * @retval void
 */
KF_INLINE void Osc_LL_SetPll1Reset(void)
{
    PLL1_PTR->CTL.bits.PDRST = 1U;
}

/**
 * @brief 配置PLL0倍频选择
 *         放大倍数=PLLmultiple_M/(PLLmultiple_N*PLLmultiple_NO)
 * @param
 *   PLLmultiple_M:  0X04-0X3FFF(M要大于等于4,并且满足200MHZ<(M*输入参考频率/N<400MHZ))
 *   PLLmultiple_N:  0X01-0XF(满足1MHZ<(输入参考频率/N)<50MHZ)
 *   PLLmultiple_OD: 1/2/4/8选其中1个
 * @retval void
 */

KF_INLINE void Osc_LL_SetPll0MultipleValue(uint32_t PLLmultiple_M, uint32_t PLLmultiple_N, uint32_t PLLmultiple_OD)
{
    KF_OSC_ASSERT(CHECK_PLL_MULTIPLE_MValue(PLLmultiple_M));
    KF_OSC_ASSERT(CHECK_PLL_MULTIPLE_NValue(PLLmultiple_N));
    KF_OSC_ASSERT(CHECK_PLL_MULTIPLE_NOValue(PLLmultiple_OD));

    PLL0_PTR->CTL.bits.M  = PLLmultiple_M;
    PLL0_PTR->CTL.bits.N  = PLLmultiple_N;
    PLL0_PTR->CTL.bits.OD = PLLmultiple_OD;
}

/**
 * @brief 配置PLL1倍频选择
 *         放大倍数=PLLmultiple_M/(PLLmultiple_N*PLLmultiple_NO)
 * @param
 *   PLLmultiple_M:  0X04-0X3FFF(M要大于等于4,并且满足200MHZ<(M*输入参考频率/N<400MHZ))
 *   PLLmultiple_N:  0X01-0XF(满足1MHZ<(输入参考频率/N)<50MHZ)
 *   PLLmultiple_NO: 1/2/4/8选其中1个
 * @retval void
 */
KF_INLINE void Osc_LL_SetPll1MultipleValue(uint32_t PLLmultiple_M, uint32_t PLLmultiple_N, uint32_t PLLmultiple_OD)
{
    KF_OSC_ASSERT(CHECK_PLL_MULTIPLE_MValue(PLLmultiple_M));
    KF_OSC_ASSERT(CHECK_PLL_MULTIPLE_NValue(PLLmultiple_N));
    KF_OSC_ASSERT(CHECK_PLL_MULTIPLE_NOValue(PLLmultiple_OD));

    PLL1_PTR->CTL.bits.M  = PLLmultiple_M;
    PLL1_PTR->CTL.bits.N  = PLLmultiple_N;
    PLL1_PTR->CTL.bits.OD = PLLmultiple_OD;
}

/**
 * @brief 配置PM_CTL 寄存器写使能
 * @param State:
 *          true   锁定
 *          false   解锁
 * @retval void
 */
KF_INLINE void Osc_LL_SetPmControlRegisterLocked(bool State)
{
    OSC_PTR->HF2CTL.bits.PMCTL_LOCK = State ? 1U : 0U;
}

/**
 * @brief 配置PM_CAL 寄存器写使能
 * @param State:
 *          true   锁定
 *          false   解锁
 * @retval void
 */
KF_INLINE void Osc_LL_SetPmCalibrationRegisterLocked(bool State)
{
    OSC_PTR->HF2CTL.bits.PMCAL_LOCK = State ? 1U : 0U;
}

/**
 * @brief 配置IWDT_CTL 寄存器写使能
 * @param State:
 *          true   锁定
 *          false   解锁
 * @retval void
 */
KF_INLINE void Osc_LL_SetIwdtControlRegisterLocked(bool State)
{
    OSC_PTR->HF2CTL.bits.IWDTCTL_LOCK = State ? 1U : 0U;
}

/**
 * @brief 配置WWDT_CTL 寄存器写使能
 * @param State:
 *          true   锁定
 *          false   解锁
 * @retval void
 */
KF_INLINE void Osc_LL_SetWwdtControlRegisterLocked(bool State)
{
    OSC_PTR->HF2CTL.bits.WWDTCTL_LOCK = State ? 1U : 0U;
}

/**
 * @brief 配置EWDT_CTL 寄存器写使能
 * @param State:
 *          true   锁定
 *          false   解锁
 * @retval void
 */
KF_INLINE void Osc_LL_SetEwdtControlRegisterLocked(bool State)
{
    OSC_PTR->HF2CTL.bits.EWDTCTL_LOCK = State ? 1U : 0U;
}

/**
 * @brief 配置高频振荡器3使能位
 * @param State:
 *          true   使能
 *          false   禁止
 * @retval void
 */
KF_INLINE void Osc_LL_SetOsc3Enabled(bool State)
{

    OSC_PTR->HF3CTL.bits.OSC3EN = (State ? 1U : 0U);
}

/**
 * @brief 获取中断发生状态
 *
 * @param IntIndex 获取中断序号, 见 Osc_IntrGetIndex_t
 * @retval bool 中断发生状态
 *         true    发生了中断，且已使能
 *         false    未发生中断，或未使能
 */
KF_INLINE bool Osc_LL_GetIntrState(Osc_IntrGetIndex_t IntIndex)
{
    KF_OSC_ASSERT(CHECK_OSC_INTRGETINDEX(IntIndex));
    /* PRQA S 3469 1 #KQR003469 */
    bool flag = (REG_BITS_READ(OSC_PTR->INT.reg, (1UL << (uint32_t)IntIndex), (uint32_t)IntIndex) != 0U) ? true : false;
    bool state = false;

    if ((IntIndex <= OSC_INTR_GET_LPHFIF) || (IntIndex == OSC_INTR_GET_LPLFIF))
    {
        uint32_t mask = (uint32_t)IntIndex + ((uint32_t)OSC_INTR_SET_ILFIE - (uint32_t)OSC_INTR_GET_ILFIF);
        /* PRQA S 3469 1 #KQR003469 */
        state = (REG_BITS_READ(OSC_PTR->INT.reg, (1UL << mask), mask) != 0U) ? true : false;
    }
    else if (IntIndex == OSC_INTR_GET_CKFIF)
    {
        state = true;
    }
    else
    {
        /* do nothing */
    }
    return flag && state;
}

#ifdef __cplusplus
}
#endif /*End of __cplusplus*/
#endif /*End of KF32A158SF_DRV_OSC_H*/
/* EOF */
