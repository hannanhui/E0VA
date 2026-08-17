/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name        : kf32a158sf_drv_atimer.h
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
#ifndef KF32A158SF_DRV_ATIMER_H
#define KF32A158SF_DRV_ATIMER_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 *                      QAC Warnings
 ******************************************************************************/
/* PRQA S 0288 EOF #KQR000288 */
/* PRQA S 1006,3006 EOF #KQR101006 */
/* PRQA S 3205 EOF #KQR003205 */
/* PRQA S 3219 EOF #KQR003219 */

/******************************************************************************
 *                      Include Files
 ******************************************************************************/
#include <stdint.h>
#include <stdbool.h>
#include "kf_types.h"
#include "kf32a158sf_reg_atimer.h"
#include "kf32a158sf_timer_base.h"
#include "kf32a158sf_drv_intr.h"

#ifdef KF_DRV_ATIM_ASSERT
#include "dev_assert.h"
#define KF_ATIM_ASSERT(x) KF_DEV_ASSERT(x)
#else
#define KF_ATIM_ASSERT(x) ((void)0U)
#endif

/******************************************************************************
 *                      Macro or Inline
 ******************************************************************************/

/******************************************************************************
 *                      Type definitions
 ******************************************************************************/

/**高级定时器后分频系数*/
typedef enum
{
    /**分频比为 1:1*/
    ATIM_POSTSCALE_1DIV1,
    /**分频比为 1:2*/
    ATIM_POSTSCALE_1DIV2,
    /**分频比为 1:3*/
    ATIM_POSTSCALE_1DIV3,
    /**分频比为 1:4*/
    ATIM_POSTSCALE_1DIV4,
    /**分频比为 1:5*/
    ATIM_POSTSCALE_1DIV5,
    /**分频比为 1:6*/
    ATIM_POSTSCALE_1DIV6,
    /**分频比为 1:7*/
    ATIM_POSTSCALE_1DIV7,
    /**分频比为 1:8*/
    ATIM_POSTSCALE_1DIV8,
    /**分频比为 1:9*/
    ATIM_POSTSCALE_1DIV9,
    /**分频比为 1:10*/
    ATIM_POSTSCALE_1DIV10,
    /**分频比为 1:11*/
    ATIM_POSTSCALE_1DIV11,
    /**分频比为 1:12*/
    ATIM_POSTSCALE_1DIV12,
    /**分频比为 1:13*/
    ATIM_POSTSCALE_1DIV13,
    /**分频比为 1:14*/
    ATIM_POSTSCALE_1DIV14,
    /**分频比为 1:15*/
    ATIM_POSTSCALE_1DIV15,
    /**分频比为 1:16*/
    ATIM_POSTSCALE_1DIV16,
} Atimer_PostScale_t;
/**检查高级定时器后分频系数*/
#define CHECK_ATIM_POSTSCALE(VAL) ((uint32_t)(VAL) <= (uint32_t)ATIM_POSTSCALE_1DIV16)

/**TxCK引脚选择*/
typedef enum
{
    /**TxCK 引脚*/
    ATIM_TXCK,
    /**GTxCK1 引脚*/
    ATIM_GTXCK1,
    /**GTxCK2 引脚*/
    ATIM_GTXCK2,
    /**GTxCK3 引脚*/
    ATIM_GTXCK3,
} Atimer_TxckPin_t;
/**检查TxCK引脚选择*/
#define CHECK_ATIM_TXCK(SEL) ((uint32_t)(SEL) <= (uint32_t)(ATIM_GTXCK3))

/**外部时钟输入信号滤波延时*/
typedef enum
{
    /**不延时*/
    ATIM_FILTER_DELAY_0,
    /**延时 1 个滤波时钟*/
    ATIM_FILTER_DELAY_1,
    /**延时 2 个滤波时钟*/
    ATIM_FILTER_DELAY_2,
    /**延时 3 个滤波时钟*/
    ATIM_FILTER_DELAY_3,
    /**延时 4 个滤波时钟*/
    ATIM_FILTER_DELAY_4,
    /**延时 5 个滤波时钟*/
    ATIM_FILTER_DELAY_5,
    /**延时 6 个滤波时钟*/
    ATIM_FILTER_DELAY_6,
    /**延时 7 个滤波时钟*/
    ATIM_FILTER_DELAY_7,
} Atimer_FilterDelay_t;
/**检查外部时钟输入信号滤波延时*/
#define CHECK_ATIM_FILTER_DELAY(DELAY) ((uint32_t)(DELAY) <= (uint32_t)ATIM_FILTER_DELAY_7)

/**滤波时钟分频*/
typedef enum
{
    /**1分频*/
    ATIM_FILTER_CLK_SCALE_1DIV1,
    /**2分频*/
    ATIM_FILTER_CLK_SCALE_1DIV2,
    /**3分频*/
    ATIM_FILTER_CLK_SCALE_1DIV3,
    /**4分频*/
    ATIM_FILTER_CLK_SCALE_1DIV4,
    /**5分频*/
    ATIM_FILTER_CLK_SCALE_1DIV5,
    /**6分频*/
    ATIM_FILTER_CLK_SCALE_1DIV6,
    /**7分频*/
    ATIM_FILTER_CLK_SCALE_1DIV7,
    /**8分频*/
    ATIM_FILTER_CLK_SCALE_1DIV8,
    /**9分频*/
    ATIM_FILTER_CLK_SCALE_1DIV9,
    /**10分频*/
    ATIM_FILTER_CLK_SCALE_1DIV10,
    /**11分频*/
    ATIM_FILTER_CLK_SCALE_1DIV11,
    /**12分频*/
    ATIM_FILTER_CLK_SCALE_1DIV12,
    /**13分频*/
    ATIM_FILTER_CLK_SCALE_1DIV13,
    /**14分频*/
    ATIM_FILTER_CLK_SCALE_1DIV14,
    /**15分频*/
    ATIM_FILTER_CLK_SCALE_1DIV15,
    /**16分频*/
    ATIM_FILTER_CLK_SCALE_1DIV16,
} Atimer_FilterClkScale_t;
/**检查滤波时钟分频*/
#define CHECK_ATIM_FILTER_CLK_SCALE(SEL) ((uint32_t)(SEL) <= (uint32_t)ATIM_FILTER_CLK_SCALE_1DIV16)

/**比较器模块序号*/
typedef enum
{
    /**比较器 0*/
    ATIM_CMP_INDEX_0,
    /**比较器 1*/
    ATIM_CMP_INDEX_1,
    /**比较器 2*/
    ATIM_CMP_INDEX_2,
    /**比较器 3*/
    ATIM_CMP_INDEX_3,
} Atimer_ComparatorIndex_t;
/**比较器模块序号*/
#define CHECK_ATIM_CMP_INDEX(SEL) ((uint32_t)(SEL) <= (uint32_t)ATIM_CMP_INDEX_3)

/******************************************************************************
 *                      Export Variables
 ******************************************************************************/

/******************************************************************************
 *                      Export Functions
 ******************************************************************************/

/**
 * @brief 设置定时器Tx的计数值
 *
 * @param Module 指向ATimer内存结构的指针 \n
 *              取值为 T5T6_PTR,T9T10_PTR
 * @param Value 计数值,0x0 ~ 0xffff
 * @retval void
 */
KF_INLINE void ATimer_LL_TxSetCounter(AdvancedTimer_RegisterMap_t *const Module, uint16_t Value)
{
    KF_ATIM_ASSERT(CHECK_ATIM_ALL_PERIPH_ADDR(Module));

    Module->Tx_CNT.bits.TXCNT = Value;
}

/**
 * @brief 获取定时器Tx的计数值
 *
 * @param Module 指向ATimer内存结构的指针 \n
 *              取值为 T5T6_PTR,T9T10_PTR
 * @retval uint16_t 当前计数值
 */
KF_INLINE uint16_t ATimer_LL_TxGetCounter(const AdvancedTimer_RegisterMap_t *const Module)
{
    KF_ATIM_ASSERT(CHECK_ATIM_ALL_PERIPH_ADDR(Module));

#if GPT_FEATURE_READ_CNT_CRITICAL
    uint32_t          criticalStatus;
    uint32_t          timerStartStatus;
    volatile uint16_t timerCount;

    criticalStatus   = Intr_LL_EnterCritical();
    timerStartStatus = Module->Tx_CTL.bits.TXEN;
    /* Disable Timer */
    Module->Tx_CTL.bits.TXEN = 0U;
    /* Read timer count */
    timerCount = (uint16_t)Module->Tx_CNT.bits.TXCNT;
    /* Rewrite timer count */
    Module->Tx_CNT.bits.TXCNT = timerCount;
    /* Resume AIE and timer */
    Module->Tx_CTL.bits.TXEN = timerStartStatus;
    Intr_LL_ExitCritical(criticalStatus);

    return timerCount;
#else
    return (uint16_t)Module->Tx_CNT.bits.TXCNT;
#endif
}

/**
 * @brief 设置定时器Tz的计数值
 *
 * @param Module 指向ATimer内存结构的指针 \n
 *              取值为 T5T6_PTR,T9T10_PTR
 * @param Value 计数值,0x0 ~ 0xffff
 * @retval void
 */
KF_INLINE void ATimer_LL_TzSetCounter(AdvancedTimer_RegisterMap_t *const Module, uint16_t Value)
{
    KF_ATIM_ASSERT(CHECK_ATIM_ALL_PERIPH_ADDR(Module));

    Module->Tz_CNT.bits.TZCNT = Value;
}

/**
 * @brief 获取定时器Tz的计数值
 *
 * @param Module 指向ATimer内存结构的指针 \n
 *              取值为 T5T6_PTR,T9T10_PTR
 * @retval uint16_t 当前计数值
 */
KF_INLINE uint16_t ATimer_LL_TzGetCounter(const AdvancedTimer_RegisterMap_t *const Module)
{
    KF_ATIM_ASSERT(CHECK_ATIM_ALL_PERIPH_ADDR(Module));
#if GPT_FEATURE_READ_CNT_CRITICAL
    uint32_t          criticalStatus;
    uint32_t          timerStartStatus;
    volatile uint16_t timerCount;

    criticalStatus   = Intr_LL_EnterCritical();
    timerStartStatus = Module->Tz_CTL.bits.TZEN;
    /* Disable Timer */
    Module->Tz_CTL.bits.TZEN = 0U;
    /* Read timer count */
    timerCount = (uint16_t)Module->Tz_CNT.bits.TZCNT;
    /* Rewrite timer count */
    Module->Tz_CNT.bits.TZCNT = timerCount;
    /* Resume AIE and timer */
    Module->Tz_CTL.bits.TZEN = timerStartStatus;
    Intr_LL_ExitCritical(criticalStatus);

    return timerCount;
#else
    return (uint16_t)Module->Tz_CNT.bits.TZCNT;
#endif
}

/**
 * @brief 设置定时器Tx的周期值
 *
 * @param Module 指向ATimer内存结构的指针 \n
 *              取值为 T5T6_PTR,T9T10_PTR
 * @param Period 周期值,0x0 ~ 0xffff
 * @retval void
 */
KF_INLINE void ATimer_LL_TxSetPeriod(AdvancedTimer_RegisterMap_t *const Module, uint16_t Period)
{
    KF_ATIM_ASSERT(CHECK_ATIM_ALL_PERIPH_ADDR(Module));

    Module->Tx_PPX.bits.PPX = Period;
}

/**
 * @brief 获取定时器Tx的周期值
 *
 * @param Module 指向ATimer内存结构的指针 \n
 *              取值为 T5T6_PTR,T9T10_PTR
 * @retval uint32_t
 */
KF_INLINE uint32_t ATimer_LL_TxGetPeriod(const AdvancedTimer_RegisterMap_t *Module)
{
    KF_ATIM_ASSERT(CHECK_ATIM_ALL_PERIPH_ADDR(Module));

    return Module->Tx_PPX.reg;
}

/**
 * @brief 设置定时器Tz的周期值
 *
 * @param Module 指向ATimer内存结构的指针 \n
 *              取值为 T5T6_PTR,T9T10_PTR
 * @param Period 周期值,0x0 ~ 0xffff
 * @retval void
 */
KF_INLINE void ATimer_LL_TzSetPeriod(AdvancedTimer_RegisterMap_t *const Module, uint16_t Period)
{
    KF_ATIM_ASSERT(CHECK_ATIM_ALL_PERIPH_ADDR(Module));

    Module->Tz_PPZ.bits.PPZ = Period;
}

/**
 * @brief 获取定时器Tz的周期值
 *
 * @param Module 指向ATimer内存结构的指针 \n
 *              取值为 T5T6_PTR,T9T10_PTR
 * @retval uint32_t
 */
KF_INLINE uint32_t ATimer_LL_TzGetPeriod(const AdvancedTimer_RegisterMap_t *Module)
{
    KF_ATIM_ASSERT(CHECK_ATIM_ALL_PERIPH_ADDR(Module));

    return Module->Tz_PPZ.bits.PPZ;
}

/**
 * @brief 设置定时器Tx的预分频系数
 *
 * @param Module 指向ATimer内存结构的指针 \n
 *              取值为 T5T6_PTR,T9T10_PTR
 * @param Period 预分频系数,0x0 ~ 0xffff
 * @retval void
 */
KF_INLINE void ATimer_LL_TxSetPrescaler(AdvancedTimer_RegisterMap_t *const Module, uint16_t Prescaler)
{
    KF_ATIM_ASSERT(CHECK_ATIM_ALL_PERIPH_ADDR(Module));

    Module->Tx_PRSC.bits.TXCKS = Prescaler;
}

/**
 * @brief 设置定时器Tz的预分频系数
 *
 * @param Module 指向ATimer内存结构的指针 \n
 *              取值为 T5T6_PTR,T9T10_PTR
 * @param Period 预分频系数,0x0 ~ 0xffff
 * @retval void
 */
KF_INLINE void ATimer_LL_TzSetPrescaler(AdvancedTimer_RegisterMap_t *const Module, uint16_t Prescaler)
{
    KF_ATIM_ASSERT(CHECK_ATIM_ALL_PERIPH_ADDR(Module));

    Module->Tz_PRSC.bits.TZCKS = Prescaler;
}

/**
 * @brief 设置Tx触发ADC寄存器值 \n
 *              Tx 计数值等于TXCCR0时,产生脉冲信号去触发ADC
 *
 * @param Module 指向ATimer内存结构的指针 \n
 *              取值为 T5T6_PTR,T9T10_PTR
 * @param Value Tx触发ADC预设值,0x0 ~ 0xffff
 * @retval void
 */
KF_INLINE void ATimer_LL_TxSetTrigAdcReg0(AdvancedTimer_RegisterMap_t *const Module, uint16_t Value)
{
    KF_ATIM_ASSERT(CHECK_ATIM_ALL_PERIPH_ADDR(Module));

    Module->Tx_CCR0.bits.TXCCR0 = Value;
}

/**
 * @brief 设置Tx触发ADC寄存器值 \n
 *              Tx 计数值等于TXCCR1时,产生脉冲信号去触发ADC
 *
 * @param Module 指向ATimer内存结构的指针 \n
 *              取值为 T5T6_PTR,T9T10_PTR
 * @param Value Tx触发ADC预设值,0x0 ~ 0xffff
 * @retval void
 */
KF_INLINE void ATimer_LL_TxSetTrigAdcReg1(AdvancedTimer_RegisterMap_t *const Module, uint16_t Value)
{
    KF_ATIM_ASSERT(CHECK_ATIM_ALL_PERIPH_ADDR(Module));

    Module->Tx_CCR1.bits.TXCCR1 = Value;
}

/**
 * @brief 设置Tz触发ADC寄存器值 \n
 *              Tz 计数值等于TZCCR0时,产生脉冲信号去触发ADC
 *
 * @param Module 指向ATimer内存结构的指针 \n
 *              取值为 T5T6_PTR,T9T10_PTR
 * @param Value Tx触发ADC预设值,0x0 ~ 0xffff
 * @retval void
 */
KF_INLINE void ATimer_LL_TzSetTrigAdcReg0(AdvancedTimer_RegisterMap_t *const Module, uint16_t Value)
{
    KF_ATIM_ASSERT(CHECK_ATIM_ALL_PERIPH_ADDR(Module));

    Module->Tz_CCR0.bits.TZCCR = Value;
}

/**
 * @brief 更新Tx定时器计数模式
 * @param Module 指向ATimer内存结构的指针 \n
 *              取值为 T5T6_PTR,T9T10_PTR
 * @param  Manner 计数方式,具体见枚举类型 @ref Timer_CountingManner_t
 * @retval 无
 */
KF_INLINE void ATimer_LL_TxSetCounterManner(AdvancedTimer_RegisterMap_t *const Module, Timer_CountingManner_t Manner)
{
    KF_ATIM_ASSERT(CHECK_ATIM_ALL_PERIPH_ADDR(Module));
    KF_ATIM_ASSERT(CHECK_TIM_COUNT_MANNER(Manner));

    Module->Tx_CTL.bits.TXCMS = (uint32_t)Manner;
}

/**
 * @brief 更新Tz定时器计数模式
 * @param Module 指向ATimer内存结构的指针 \n
 *              取值为 T5T6_PTR,T9T10_PTR
 * @param  Manner 计数方式,具体见枚举类型 @ref Timer_CountingManner_t
 * @retval 无
 */
KF_INLINE void ATimer_LL_TzSetCounterManner(AdvancedTimer_RegisterMap_t *const Module, Timer_CountingManner_t Manner)
{
    KF_ATIM_ASSERT(CHECK_ATIM_ALL_PERIPH_ADDR(Module));
    KF_ATIM_ASSERT(CHECK_TIM_COUNT_MANNER(Manner));

    Module->Tz_CTL.bits.TZCMS = (uint32_t)Manner;
}

/**
 * @brief Tx 向上溢出中断触发 AD
 *
 * @param Module 指向ATimer内存结构的指针 \n
 *              取值为 T5T6_PTR,T9T10_PTR
 * @param EnableSta 使能状态 \n
 *              true -- 使能上溢中断触发 AD
 *              false -- 禁止上溢中断触发 AD
 * @retval void
 */
KF_INLINE void ATimer_LL_TxSetOverflowTrigAdcEnabled(AdvancedTimer_RegisterMap_t *const Module, bool EnableSta)
{
    KF_ATIM_ASSERT(CHECK_ATIM_ALL_PERIPH_ADDR(Module));

    Module->Tx_CTL.bits.TXOFS1 = EnableSta ? 1U : 0U;
}

/**
 * @brief Tz 向上溢出中断触发 AD
 *
 * @param Module 指向ATimer内存结构的指针 \n
 *              取值为 T5T6_PTR,T9T10_PTR
 * @param EnableSta 使能状态 \n
 *              true -- 使能上溢中断触发 AD
 *              false -- 禁止上溢中断触发 AD
 * @retval void
 */
KF_INLINE void ATimer_LL_TzSetOverflowTrigAdcEnabled(AdvancedTimer_RegisterMap_t *const Module, bool EnableSta)
{
    KF_ATIM_ASSERT(CHECK_ATIM_ALL_PERIPH_ADDR(Module));

    Module->Tz_CTL.bits.TZOFS1 = EnableSta ? 1U : 0U;
}

/**
 * @brief Tx 向下溢出中断触发 AD
 *
 * @param Module 指向ATimer内存结构的指针 \n
 *              取值为 T5T6_PTR,T9T10_PTR
 * @param EnableSta 使能状态 \n
 *              true -- 使能下溢中断触发 AD
 *              false -- 禁止下溢中断触发 AD
 * @retval void
 */
KF_INLINE void ATimer_LL_TxSetUnderflowTrigAdcEnabled(AdvancedTimer_RegisterMap_t *const Module, bool EnableSta)
{
    KF_ATIM_ASSERT(CHECK_ATIM_ALL_PERIPH_ADDR(Module));

    Module->Tx_CTL.bits.TXOFS0 = EnableSta ? 1U : 0U;
}

/**
 * @brief Tz 向下溢出中断触发 AD
 *
 * @param Module 指向ATimer内存结构的指针 \n
 *              取值为 T5T6_PTR,T9T10_PTR
 * @param EnableSta 使能状态 \n
 *              true -- 使能下溢中断触发 AD
 *              false -- 禁止下溢中断触发 AD
 * @retval void
 */
KF_INLINE void ATimer_LL_TzSetUnderflowTrigAdcEnabled(AdvancedTimer_RegisterMap_t *const Module, bool EnableSta)
{
    KF_ATIM_ASSERT(CHECK_ATIM_ALL_PERIPH_ADDR(Module));

    Module->Tz_CTL.bits.TZOFS0 = EnableSta ? 1U : 0U;
}

/**
 * @brief 设置Tx溢出中断自动触发 AD \n
 *              当 AD 转换结束后自动清零
 *
 * @param Module 指向ATimer内存结构的指针 \n
 *              取值为 T5T6_PTR,T9T10_PTR
 * @param EnableSta 使能状态 \n
 *              true -- 使能溢出中断自动触发 AD
 *              false -- 禁止溢出中断自动触发 AD
 * @retval void
 */
KF_INLINE void ATimer_LL_TxSetOverflowAutoTrigAdc(AdvancedTimer_RegisterMap_t *const Module, bool EnableSta)
{
    KF_ATIM_ASSERT(CHECK_ATIM_ALL_PERIPH_ADDR(Module));

    Module->Tx_CTL.bits.TXADAUTO = EnableSta ? 1U : 0U;
}

/**
 * @brief 设置Tz溢出中断自动触发 AD \n
 *              当 AD 转换结束后自动清零
 *
 * @param Module 指向ATimer内存结构的指针 \n
 *              取值为 T5T6_PTR,T9T10_PTR
 * @param EnableSta 使能状态 \n
 *              true -- 使能溢出中断自动触发 AD
 *              false -- 禁止溢出中断自动触发 AD
 * @retval void
 */
KF_INLINE void ATimer_LL_TzSetOverflowAutoTrigAdc(AdvancedTimer_RegisterMap_t *const Module, bool EnableSta)
{
    KF_ATIM_ASSERT(CHECK_ATIM_ALL_PERIPH_ADDR(Module));

    Module->Tz_CTL.bits.TZADAUTO = EnableSta ? 1U : 0U;
}

/**
 * @brief 配置Tx工作时钟选择位
 *
 * @param Module 指向ATimer内存结构的指针 \n
 *              取值为 T5T6_PTR,T9T10_PTR
 * @param ClockSrc 定时器工作时钟,具体见枚举类型 @ref Timer_ClockSource_t
 * @retval void
 */
KF_INLINE void ATimer_LL_TxSetClkSrc(AdvancedTimer_RegisterMap_t *const Module, Timer_ClockSource_t ClockSrc)
{
    KF_ATIM_ASSERT(CHECK_ATIM_ALL_PERIPH_ADDR(Module));
    KF_ATIM_ASSERT(CHECK_TIM_CLK(ClockSrc));

    Module->Tx_CTL.bits.TXCLK = (uint32_t)ClockSrc;
}

/**
 * @brief 配置Tz工作时钟选择位
 *
 * @param Module 指向ATimer内存结构的指针 \n
 *              取值为 T5T6_PTR,T9T10_PTR
 * @param ClockSrc 定时器工作时钟,具体见枚举类型 @ref Timer_ClockSource_t
 * @retval void
 */
KF_INLINE void ATimer_LL_TzSetClkSrc(AdvancedTimer_RegisterMap_t *const Module, Timer_ClockSource_t ClockSrc)
{
    KF_ATIM_ASSERT(CHECK_ATIM_ALL_PERIPH_ADDR(Module));
    KF_ATIM_ASSERT(CHECK_TIM_CLK(ClockSrc));

    Module->Tz_CTL.bits.TZCLK = (uint32_t)ClockSrc;
}

/**
 * @brief 获取Tx计数方向标志位
 *
 * @param Module 指向ATimer内存结构的指针 \n
 *              取值为 T5T6_PTR,T9T10_PTR
 * @retval Timer_CountingDir_t 计数方式 \n
 *          UP_COUNTING   -- 当前计数方向为向上计数 \n
 *          DOWN_COUNTING -- 当前计数方向为向下计数
 */
KF_INLINE Timer_CountingDir_t ATimer_LL_TxGetCountingDir(const AdvancedTimer_RegisterMap_t *const Module)
{
    KF_ATIM_ASSERT(CHECK_ATIM_ALL_PERIPH_ADDR(Module));

    return ((Module->Tx_CTL.bits.TXDIR != 0U) ? (UP_COUNTING) : (DOWN_COUNTING));
}

/**
 * @brief 获取Tz计数方向标志位
 *
 * @param Module 指向ATimer内存结构的指针 \n
 *              取值为 T5T6_PTR,T9T10_PTR
 * @retval Timer_CountingDir_t 计数方式 \n
 *          UP_COUNTING   -- 当前计数方向为向上计数 \n
 *          DOWN_COUNTING -- 当前计数方向为向下计数
 */
KF_INLINE Timer_CountingDir_t ATimer_LL_TzGetCountingDir(const AdvancedTimer_RegisterMap_t *const Module)
{
    KF_ATIM_ASSERT(CHECK_ATIM_ALL_PERIPH_ADDR(Module));

    return ((Module->Tz_CTL.bits.TZDIR != 0U) ? (UP_COUNTING) : (DOWN_COUNTING));
}

/**
 * @brief 设置Tx 后分频器(分频器 2)分频比
 *
 * @param Module 指向ATimer内存结构的指针 \n
 *              取值为 T5T6_PTR,T9T10_PTR
 * @param PostScale 后分频比,具体见枚举类型 @ref Atimer_PostScale_t
 * @retval void
 */
KF_INLINE void ATimer_LL_TxSetPostscaler(AdvancedTimer_RegisterMap_t *const Module, Atimer_PostScale_t PostScaler)
{
    KF_ATIM_ASSERT(CHECK_ATIM_ALL_PERIPH_ADDR(Module));
    KF_ATIM_ASSERT(CHECK_ATIM_POSTSCALE(PostScaler));

    Module->Tx_CTL.bits.TXCKBS = (uint32_t)PostScaler;
}

/**
 * @brief 设置Tz 后分频器(分频器 2)分频比
 *
 * @param Module 指向ATimer内存结构的指针 \n
 *              取值为 T5T6_PTR,T9T10_PTR
 * @param PostScale 后分频比,具体见枚举类型 @ref Atimer_PostScale_t
 * @retval void
 */
KF_INLINE void ATimer_LL_TzSetPostScaler(AdvancedTimer_RegisterMap_t *const Module, Atimer_PostScale_t PostScaler)
{
    KF_ATIM_ASSERT(CHECK_ATIM_ALL_PERIPH_ADDR(Module));
    KF_ATIM_ASSERT(CHECK_ATIM_POSTSCALE(PostScaler));

    Module->Tz_CTL.bits.TZCKBS = (uint32_t)PostScaler;
}

/**
 * @brief 设置Tx使能状态
 *
 * @param Module 指向ATimer内存结构的指针 \n
 *              取值为 T5T6_PTR,T9T10_PTR
 * @param EnableSta 使能状态 \n
 *              true -- 使能Tx \n
 *              false -- 禁止使能Tx
 * @return void
 */
KF_INLINE void ATimer_LL_SetTxEnabled(AdvancedTimer_RegisterMap_t *const Module, bool EnableSta)
{
    KF_ATIM_ASSERT(CHECK_ATIM_ALL_PERIPH_ADDR(Module));

    Module->Tx_CTL.bits.TXEN = EnableSta ? 1U : 0U;
}

/**
 * @brief 使能Tx
 *
 * @param Module 指向ATimer内存结构的指针 \n
 *              取值为 T5T6_PTR,T9T10_PTR
 * @retval void
 */
KF_INLINE void ATimer_LL_TxStart(AdvancedTimer_RegisterMap_t *const Module)
{
    KF_ATIM_ASSERT(CHECK_ATIM_ALL_PERIPH_ADDR(Module));

    ATimer_LL_SetTxEnabled(Module, true);
}

/**
 * @brief 禁止Tx
 *
 * @param Module 指向ATimer内存结构的指针 \n
 *              取值为 T5T6_PTR,T9T10_PTR
 * @retval void
 */
KF_INLINE void ATimer_LL_TxStop(AdvancedTimer_RegisterMap_t *const Module)
{
    KF_ATIM_ASSERT(CHECK_ATIM_ALL_PERIPH_ADDR(Module));

    ATimer_LL_SetTxEnabled(Module, false);
}

/**
 * @brief 设置Tz使能状态
 *
 * @param Module 指向ATimer内存结构的指针 \n
 *              取值为 T5T6_PTR,T9T10_PTR
 * @param EnableSta 使能状态 \n
 *              true -- 使能Tz \n
 *              false -- 禁止使能Tz
 * @return void
 */
KF_INLINE void ATimer_LL_SetTzEnabled(AdvancedTimer_RegisterMap_t *const Module, bool EnableSta)
{
    KF_ATIM_ASSERT(CHECK_ATIM_ALL_PERIPH_ADDR(Module));

    Module->Tz_CTL.bits.TZEN = EnableSta ? 1U : 0U;
}

/**
 * @brief 使能Tz
 *
 * @param Module 指向ATimer内存结构的指针 \n
 *              取值为 T5T6_PTR,T9T10_PTR
 * @retval void
 */
KF_INLINE void ATimer_LL_TzStart(AdvancedTimer_RegisterMap_t *const Module)
{
    KF_ATIM_ASSERT(CHECK_ATIM_ALL_PERIPH_ADDR(Module));

    ATimer_LL_SetTzEnabled(Module, true);
}

/**
 * @brief 禁止Tz
 *
 * @param Module 指向ATimer内存结构的指针 \n
 *              取值为 T5T6_PTR,T9T10_PTR
 * @retval void
 */
KF_INLINE void ATimer_LL_TzStop(AdvancedTimer_RegisterMap_t *const Module)
{
    KF_ATIM_ASSERT(CHECK_ATIM_ALL_PERIPH_ADDR(Module));

    ATimer_LL_SetTzEnabled(Module, false);
}

/**
 * @brief Tx计数模式外部触发脉冲输入同步控制 \n
 *              当定时器为定时模式时(TXCS = 0),该位被忽略
 *
 * @param Module 指向ATimer内存结构的指针 \n
 *              取值为 T5T6_PTR,T9T10_PTR
 * @param SyncStatus 外部触发脉冲输入同步状态 \n
 *              true -- 外部触发脉冲与工作时钟同步后作为计数时钟 \n
 *              false -- 外部触发脉冲作为计数时钟
 * @retval void
 */
KF_INLINE void ATimer_LL_TxSetExternalPulseSyncWithClk(AdvancedTimer_RegisterMap_t *const Module, bool SyncStatus)
{
    KF_ATIM_ASSERT(CHECK_ATIM_ALL_PERIPH_ADDR(Module));

    Module->Tx_CTL.bits.TXSY = SyncStatus ? 1U : 0U;
}

/**
 * @brief Tz计数模式外部触发脉冲输入同步控制 \n
 *              当定时器为定时模式时(TZCS = 0),该位被忽略
 *
 * @param Module 指向ATimer内存结构的指针 \n
 *              取值为 T5T6_PTR,T9T10_PTR
 * @param SyncStatus 外部触发脉冲输入同步状态 \n
 *              true -- 外部触发脉冲与工作时钟同步后作为计数时钟 \n
 *              false -- 外部触发脉冲作为计数时钟
 * @retval void
 */
KF_INLINE void ATimer_LL_TzSetExternalPulseSyncWithClk(AdvancedTimer_RegisterMap_t *const Module, bool SyncStatus)
{
    KF_ATIM_ASSERT(CHECK_ATIM_ALL_PERIPH_ADDR(Module));

    Module->Tz_CTL.bits.TZSY = SyncStatus ? 1U : 0U;
}

/**
 * @brief Tx定时/计数模式选择
 *
 * @param Module 指向ATimer内存结构的指针 \n
 *              取值为 T5T6_PTR,T9T10_PTR
 * @param  Mode 计数模式,具体见枚举类型 @ref Timer_Mode_t
 * @retval void
 */
KF_INLINE void ATimer_LL_TxSetWorkingMode(AdvancedTimer_RegisterMap_t *const Module, Timer_Mode_t Mode)
{
    KF_ATIM_ASSERT(CHECK_ATIM_ALL_PERIPH_ADDR(Module));

    Module->Tx_CTL.bits.TXCS = (uint32_t)Mode;
}

/**
 * @brief Tz定时/计数模式选择
 *
 * @param Module 指向ATimer内存结构的指针 \n
 *              取值为 T5T6_PTR,T9T10_PTR
 * @param  Mode 计数模式,具体见枚举类型 @ref Timer_Mode_t
 * @retval void
 */
KF_INLINE void ATimer_LL_TzSetWorkingMode(AdvancedTimer_RegisterMap_t *const Module, Timer_Mode_t Mode)
{
    KF_ATIM_ASSERT(CHECK_ATIM_ALL_PERIPH_ADDR(Module));
    KF_ATIM_ASSERT(CHECK_TIM_WORK_MODE(Mode));

    Module->Tz_CTL.bits.TZCS = (uint32_t)Mode;
}

/**
 * @brief Tx选择TXCK引脚
 *
 * @param Module 指向ATimer内存结构的指针 \n
 *              取值为 T5T6_PTR,T9T10_PTR
 * @param TxckPin 选择的TxCK引脚 \n
 *              ATIM_TXCK -- TxCK 引脚 \n
 *              ATIM_GTXCK1 -- GTxCK1 引脚 \n
 *              ATIM_GTXCK2 -- GTxCK2 引脚 \n
 *              ATIM_GTXCK3 -- GTxCK3 引脚
 * @retval void
 */
KF_INLINE void ATimer_LL_TxSelectTxckPin(AdvancedTimer_RegisterMap_t *const Module, Atimer_TxckPin_t TxckPin)
{
    KF_ATIM_ASSERT(CHECK_ATIM_ALL_PERIPH_ADDR(Module));
    KF_ATIM_ASSERT(CHECK_ATIM_TXCK(TxckPin));

    Module->Tx_CCTCTL.bits.TXCKSEL = (uint32_t)TxckPin;
}

/**
 * @brief Tz选择TXCK引脚
 *
 * @param Module 指向ATimer内存结构的指针 \n
 *              取值为 T5T6_PTR,T9T10_PTR
 * @param TxckPin 选择的TxCK引脚 \n
 *              ATIM_TXCK -- TxCK 引脚 \n
 *              ATIM_GTXCK1 -- GTxCK1 引脚 \n
 *              ATIM_GTXCK2 -- GTxCK2 引脚 \n
 *              ATIM_GTXCK3 -- GTxCK3 引脚
 * @retval void
 */
KF_INLINE void ATimer_LL_TzSelectTxckPin(AdvancedTimer_RegisterMap_t *const Module, Atimer_TxckPin_t TxckPin)
{
    KF_ATIM_ASSERT(CHECK_ATIM_ALL_PERIPH_ADDR(Module));
    KF_ATIM_ASSERT(CHECK_ATIM_TXCK(TxckPin));

    Module->Tz_CCTCTL.bits.TZCKSEL = (uint32_t)TxckPin;
}

/**
 * @brief Tz设置外部时钟输入信号滤波延时
 *
 * @param Module 指向ATimer内存结构的指针 \n
 *              取值为 T5T6_PTR,T9T10_PTR
 * @param Delay 滤波延时,具体可见枚举类型 @ref Atimer_FilterDelay_t
 * @retval void
 */
KF_INLINE void
ATimer_LL_TzSetExternalSignalFilterDelay(AdvancedTimer_RegisterMap_t *const Module, Atimer_FilterDelay_t Delay)
{
    KF_ATIM_ASSERT(CHECK_ATIM_ALL_PERIPH_ADDR(Module));
    KF_ATIM_ASSERT(CHECK_ATIM_FILTER_DELAY(Delay));

    Module->Tz_CCTCTL.bits.TCKDELAY = (uint32_t)Delay;
}

/**
 * @brief Tz设置外部时钟输入滤波时钟分频
 *
 * @param Module 指向ATimer内存结构的指针 \n
 *              取值为 T5T6_PTR,T9T10_PTR
 * @param Scale 分频系数,具体可见枚举类型 @ref Atimer_FilterClkScale_t
 * @retval void
 */
KF_INLINE void ATimer_LL_TzSetFilterClkScaler(AdvancedTimer_RegisterMap_t *const Module, Atimer_FilterClkScale_t Scaler)
{
    KF_ATIM_ASSERT(CHECK_ATIM_ALL_PERIPH_ADDR(Module));
    KF_ATIM_ASSERT(CHECK_ATIM_FILTER_CLK_SCALE(Scaler));

    Module->Tz_CCTCTL.bits.TCKDIV = (uint32_t)Scaler;
}

/**
 * @brief Tz设置外部时钟输入滤波使能位
 *
 * @param Module 指向ATimer内存结构的指针 \n
 *              取值为 T5T6_PTR,T9T10_PTR
 * @param EnableSta 使能状态 \n
 *              true -- 使能外部时钟引脚输入滤波
 *              false -- 禁止外部时钟引脚输入滤波
 * @retval void
 */
KF_INLINE void ATimer_LL_TzSetExternalSignalFilterEnabled(AdvancedTimer_RegisterMap_t *const Module, bool EnableSta)
{
    KF_ATIM_ASSERT(CHECK_ATIM_ALL_PERIPH_ADDR(Module));

    Module->Tz_CCTCTL.bits.TCKFEN = EnableSta ? 1U : 0U;
}

/**
 * @brief Tx选择用于清零定时器的比较器模块
 *
 * @param Module 指向ATimer内存结构的指针 \n
 *              取值为 T5T6_PTR,T9T10_PTR
 * @param CmpIndex 比较器序号,具体见枚举类型 @ref Atimer_ComparatorIndex_t
 * @retval void
 */
KF_INLINE void
ATimer_LL_TxSelectCompareModule(AdvancedTimer_RegisterMap_t *const Module, Atimer_ComparatorIndex_t CmpIndex)
{
    KF_ATIM_ASSERT(CHECK_ATIM_ALL_PERIPH_ADDR(Module));
    KF_ATIM_ASSERT(CHECK_ATIM_CMP_INDEX(CmpIndex));

    Module->Tx_CCTCTL.bits.CCTSEL = (uint32_t)CmpIndex;
}

/**
 * @brief Tz选择用于清零定时器的比较器模块
 *
 * @param Module 指向ATimer内存结构的指针 \n
 *              取值为 T5T6_PTR,T9T10_PTR
 * @param CmpIndex 比较器序号,具体见枚举类型 @ref Atimer_ComparatorIndex_t
 * @retval void
 */
KF_INLINE void
ATimer_LL_TzSelectCctCompareModule(AdvancedTimer_RegisterMap_t *const Module, Atimer_ComparatorIndex_t CmpIndex)
{
    KF_ATIM_ASSERT(CHECK_ATIM_ALL_PERIPH_ADDR(Module));
    KF_ATIM_ASSERT(CHECK_ATIM_CMP_INDEX(CmpIndex));

    Module->Tz_CCTCTL.bits.CCTSEL = (uint32_t)CmpIndex;
}

/**
 * @brief Tx CCT清零信号上升/下降沿选择
 *
 * @param Module 指向ATimer内存结构的指针 \n
 *              取值为 T5T6_PTR,T9T10_PTR
 * @param CctEdge 清零信号边沿 \n
 *              true -- 比较器输出信号检测到下降沿时,清零定时器
 *              false -- 比较器输出信号检测到上升沿时,清零定时器
 * @retval void
 */
KF_INLINE void ATimer_LL_TxSelectCctEdge(AdvancedTimer_RegisterMap_t *const Module, bool CctEdge)
{
    KF_ATIM_ASSERT(CHECK_ATIM_ALL_PERIPH_ADDR(Module));

    Module->Tx_CCTCTL.bits.CRSET = CctEdge ? 1U : 0U;
}

/**
 * @brief Tz CCT清零信号上升/下降沿选择
 *
 * @param Module 指向ATimer内存结构的指针 \n
 *              取值为 T5T6_PTR,T9T10_PTR
 * @param CctEdge 清零信号边沿 \n
 *              true -- 比较器输出信号检测到下降沿时,清零定时器
 *              false -- 比较器输出信号检测到上升沿时,清零定时器
 * @retval void
 */
KF_INLINE void ATimer_LL_TzSelectCctEdge(AdvancedTimer_RegisterMap_t *const Module, bool CctEdge)
{
    KF_ATIM_ASSERT(CHECK_ATIM_ALL_PERIPH_ADDR(Module));

    Module->Tz_CCTCTL.bits.CRSET = CctEdge ? 1U : 0U;
}

/**
 * @brief 使能Tx比较器清零定时器功能
 *
 * @param Module 指向ATimer内存结构的指针 \n
 *              取值为 T5T6_PTR,T9T10_PTR
 * @param EnableSta 使能状态 \n
 *              true -- 使能比较器清零定时器功能
 *              false -- 禁止比较器清零定时器功能
 * @retval void
 */
KF_INLINE void ATimer_LL_TxSetCctEnabled(AdvancedTimer_RegisterMap_t *const Module, bool EnableSta)
{
    KF_ATIM_ASSERT(CHECK_ATIM_ALL_PERIPH_ADDR(Module));

    Module->Tx_CCTCTL.bits.CCTEN = EnableSta ? 1U : 0U;
}

/**
 * @brief 使能Tz比较器清零定时器功能
 *
 * @param Module 指向ATimer内存结构的指针 \n
 *              取值为 T5T6_PTR,T9T10_PTR
 * @param EnableSta 使能状态 \n
 *              true -- 使能比较器清零定时器功能
 *              false -- 禁止比较器清零定时器功能
 * @retval void
 */
KF_INLINE void ATimer_LL_TzSetCctEnabled(AdvancedTimer_RegisterMap_t *const Module, bool EnableSta)
{
    KF_ATIM_ASSERT(CHECK_ATIM_ALL_PERIPH_ADDR(Module));

    Module->Tz_CCTCTL.bits.CCTEN = EnableSta ? 1U : 0U;
}

/**
 * @brief 设置TIMER Tx计数溢出中断
 *
 * @param Module 指向ATimer内存结构的指针 \n
 *              取值为 T5T6_PTR,T9T10_PTR
 * @param EnableStatus 使能状态 \n
 *                  false -- 不使能对应中断 \n
 *                  true -- 使能对应中断
 * @retval void
 */
KF_INLINE void ATimer_LL_SetTxOverFlowIntrEnabled(AdvancedTimer_RegisterMap_t *const Module, bool EnableSta)
{
    KF_ATIM_ASSERT(CHECK_ATIM_ALL_PERIPH_ADDR(Module));

    Module->IE.bits.TXIE = EnableSta ? 1U : 0U;
}

/**
 * @brief 设置TIMER Tz计数溢出中断
 *
 * @param Module 指向ATimer内存结构的指针 \n
 *              取值为 T5T6_PTR,T9T10_PTR
 * @param EnableStatus 使能状态 \n
 *                  false -- 不使能对应中断 \n
 *                  true -- 使能对应中断
 * @retval void
 */
KF_INLINE void ATimer_LL_SetTzOverFlowIntrEnabled(AdvancedTimer_RegisterMap_t *const Module, bool EnableSta)
{
    KF_ATIM_ASSERT(CHECK_ATIM_ALL_PERIPH_ADDR(Module));

    Module->IE.bits.TZIE = EnableSta ? 1U : 0U;
}

/**
 * @brief 设置TIMER Tx更新事件中断
 *
 * @param Module 指向ATimer内存结构的指针 \n
 *              取值为 T5T6_PTR,T9T10_PTR
 * @param EnableStatus 使能状态 \n
 *                  false -- 不使能对应中断 \n
 *                  true -- 使能对应中断
 * @retval void
 */
KF_INLINE void ATimer_LL_SetTxUpdateEventIntrEnabled(AdvancedTimer_RegisterMap_t *const Module, bool EnableSta)
{
    KF_ATIM_ASSERT(CHECK_ATIM_ALL_PERIPH_ADDR(Module));

    Module->IE.bits.TXUIE = EnableSta ? 1U : 0U;
}

/**
 * @brief 设置TIMER Tz更新事件中断
 *
 * @param Module 指向ATimer内存结构的指针 \n
 *              取值为 T5T6_PTR,T9T10_PTR
 * @param EnableStatus 使能状态 \n
 *                  false -- 不使能对应中断 \n
 *                  true -- 使能对应中断
 * @retval void
 */
KF_INLINE void ATimer_LL_SetTzUpdateEventIntrEnabled(AdvancedTimer_RegisterMap_t *const Module, bool EnableSta)
{
    KF_ATIM_ASSERT(CHECK_ATIM_ALL_PERIPH_ADDR(Module));

    Module->IE.bits.TZUIE = EnableSta ? 1U : 0U;
}

/**
 * @brief 设置TIMER Tx触发事件中断
 *
 * @param Module 指向ATimer内存结构的指针 \n
 *              取值为 T5T6_PTR,T9T10_PTR
 * @param EnableStatus 使能状态 \n
 *                  false -- 不使能对应中断 \n
 *                  true -- 使能对应中断
 * @retval void
 */
KF_INLINE void ATimer_LL_SetTxTriggerEventIntrEnabled(AdvancedTimer_RegisterMap_t *const Module, bool EnableSta)
{
    KF_ATIM_ASSERT(CHECK_ATIM_ALL_PERIPH_ADDR(Module));

    Module->IE.bits.TXTIE = EnableSta ? 1U : 0U;
}

/**
 * @brief 设置TIMER RDA 和 CPD 比较中断使能位
 *
 * @param Module 指向ATimer内存结构的指针 \n
 *              取值为 T5T6_PTR,T9T10_PTR
 * @param EnableStatus 使能状态 \n
 *                  false -- 不使能对应中断 \n
 *                  true -- 使能对应中断
 * @retval void
 */
KF_INLINE void ATimer_LL_SetRDAAndCPDCmpIntrEnabled(AdvancedTimer_RegisterMap_t *const Module, bool EnableSta)
{
    KF_ATIM_ASSERT(CHECK_ATIM_ALL_PERIPH_ADDR(Module));

    Module->IE.bits.CPIE = EnableSta ? 1U : 0U;
}

/**
 * @brief 设置TIMER 位置检测事件中断
 *
 * @param Module 指向ATimer内存结构的指针 \n
 *              取值为 T5T6_PTR,T9T10_PTR
 * @param EnableStatus 使能状态 \n
 *                  false -- 不使能对应中断 \n
 *                  true -- 使能对应中断
 * @retval void
 */
KF_INLINE void ATimer_LL_SetPositionDetectionIntrEnabled(AdvancedTimer_RegisterMap_t *const Module, bool EnableSta)
{
    KF_ATIM_ASSERT(CHECK_ATIM_ALL_PERIPH_ADDR(Module));

    Module->IE.bits.PDIE = EnableSta ? 1U : 0U;
}

/**
 * @brief 清除Tz溢出中断标记位
 *
 * @param Module 指向ATimer内存结构的指针 \n
 *              取值为 T5T6_PTR,T9T10_PTR
 * @retval void
 */
KF_INLINE void ATimer_LL_ClearTzOverFlowIntrFlag(AdvancedTimer_RegisterMap_t *const Module)
{
    KF_ATIM_ASSERT(CHECK_ATIM_ALL_PERIPH_ADDR(Module));

    Module->SRIC.bits.TZIC = 1U;
    NOP();
    NOP();
    NOP();
    NOP();
    Module->SRIC.bits.TZIC = 0U;
}

/**
 * @brief 设置Tz溢出中断标记位
 *
 * @param Module 指向ATimer内存结构的指针 \n
 *              取值为 T5T6_PTR,T9T10_PTR
 * @retval void
 */
KF_INLINE void ATimer_LL_SetTzOverFlowIntrFlag(AdvancedTimer_RegisterMap_t *const Module)
{
    KF_ATIM_ASSERT(CHECK_ATIM_ALL_PERIPH_ADDR(Module));

    Module->SRIC.bits.TZIC = 1U;
}

/**
 * @brief 清除Tx溢出中断标记位
 *
 * @param Module 指向ATimer内存结构的指针 \n
 *              取值为 T5T6_PTR,T9T10_PTR
 * @retval void
 */
KF_INLINE void ATimer_LL_ClearTxOverFlowIntrFlag(AdvancedTimer_RegisterMap_t *const Module)
{
    KF_ATIM_ASSERT(CHECK_ATIM_ALL_PERIPH_ADDR(Module));

    Module->SRIC.bits.TXIC = 1U;
    NOP();
    NOP();
    NOP();
    NOP();
    Module->SRIC.bits.TXIC = 0U;
}

/**
 * @brief 设置Tx溢出中断标记位
 *
 * @param Module 指向ATimer内存结构的指针 \n
 *              取值为 T5T6_PTR,T9T10_PTR
 * @retval void
 */
KF_INLINE void ATimer_LL_SetTxOverFlowIntrFlag(AdvancedTimer_RegisterMap_t *const Module)
{
    KF_ATIM_ASSERT(CHECK_ATIM_ALL_PERIPH_ADDR(Module));

    Module->SRIC.bits.TXIC = 1U;
}

/**
 * @brief 清除Tx触发AD事件中断标志
 *
 * @param Module 指向ATimer内存结构的指针 \n
 *              取值为 T5T6_PTR,T9T10_PTR
 * @retval void
 */
KF_INLINE void ATimer_LL_ClearTxTriggerAdIntrFlag(AdvancedTimer_RegisterMap_t *const Module)
{
    KF_ATIM_ASSERT(CHECK_ATIM_ALL_PERIPH_ADDR(Module));

    Module->SRIC.bits.TXTIC = 1U;
    NOP();
    NOP();
    NOP();
    NOP();
    Module->SRIC.bits.TXTIC = 0U;
}

/**
 * @brief 清除Tx更新事件中断标志位
 *
 * @param Module 指向ATimer内存结构的指针 \n
 *              取值为 T5T6_PTR,T9T10_PTR
 * @retval void
 */
KF_INLINE void ATimer_LL_ClearTxUpdateEventIntrFlag(AdvancedTimer_RegisterMap_t *const Module)
{
    KF_ATIM_ASSERT(CHECK_ATIM_ALL_PERIPH_ADDR(Module));

    Module->SRIC.bits.TXUIC = 1U;
    NOP();
    NOP();
    NOP();
    NOP();
    Module->SRIC.bits.TXUIC = 0U;
}

/**
 * @brief 清除Tz更新事件中断标志位
 *
 * @param Module 指向ATimer内存结构的指针 \n
 *              取值为 T5T6_PTR,T9T10_PTR
 * @retval void
 */
KF_INLINE void ATimer_LL_ClearTzUpdateEventIntrFlag(AdvancedTimer_RegisterMap_t *const Module)
{
    KF_ATIM_ASSERT(CHECK_ATIM_ALL_PERIPH_ADDR(Module));

    Module->SRIC.bits.TZUIC = 1U;
    NOP();
    NOP();
    NOP();
    NOP();
    Module->SRIC.bits.TZUIC = 0U;
}

#ifdef __cplusplus
}
#endif /*End of __cplusplus*/
#endif /*End of KF32A158SF_DRV_ATIMER_H*/
/* EOF */
