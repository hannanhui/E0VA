/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name        : kf32a158sf_drv_gptimer.h
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
#ifndef KF32A158SF_DRV_GPTIMER_H
#define KF32A158SF_DRV_GPTIMER_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 *                      QAC Warnings
 ******************************************************************************/
/* PRQA S 0288 EOF #KQR000288 */
/* PRQA S 0303,0306 EOF #KQR100303 */
/* PRQA S 1006,3006 EOF #KQR101006 */
/* PRQA S 3205 EOF #KQR003205 */
/* PRQA S 3219 EOF #KQR003219 */
/******************************************************************************
 *                      Include Files
 ******************************************************************************/
#include <stdint.h>
#include <stdbool.h>
#include <kf_types.h>
#include "kf32a158sf_reg_gptimer.h"
#include "kf32a158sf_timer_base.h"
#include "kf32a158sf_drv_intr.h"

#ifdef KF_DRV_GPTIMER_ASSERT
#include "dev_assert.h"
#define KF_GPTIMER_ASSERT(x) KF_DEV_ASSERT(x)
#else
#define KF_GPTIMER_ASSERT(x) ((void)0U)
#endif
/******************************************************************************
 *                      Macro or Inline
 ******************************************************************************/

/******************************************************************************
 *                      Type definitions
 ******************************************************************************/

/**通用定时器触发输入 TRGI 选择*/
typedef enum
{
    /**T1*/
    GPTIM_TRIG_T1 = 0U,
    /**T2*/
    GPTIM_TRIG_T2 = 1U,
    /**T3*/
    GPTIM_TRIG_T3 = 2U,
    /**T4*/
    GPTIM_TRIG_T4 = 3U,
    /**T5*/
    GPTIM_TRIG_T5 = 4U,
    /**T9*/
    GPTIM_TRIG_T9 = 5U,
    /**T14*/
    GPTIM_TRIG_T14 = 6U,
    /**T21*/
    GPTIM_TRIG_T21 = 11U,
    /**TxCK*/
    GPTIM_TRIG_TXCK = 12U,
    /**CCPxCH1*/
    GPTIM_TRIG_CCPXCH1 = 13U,
    /**CCPxCH2*/
    GPTIM_TRIG_CCPXCH2 = 14U,
    /**CCPxCH3*/
    GPTIM_TRIG_CCPXCH3 = 15U,
    /**CCPxCH4*/
    GPTIM_TRIG_CCPXCH4 = 16U
} GPtimer_TrigSrc_t;
/**检查通用定时器触发输入*/
#define CHECK_GPTIM_TRG_SOURCE(SRC)                                                                                    \
    (((uint32_t)(SRC) == (uint32_t)GPTIM_TRIG_T1) || ((uint32_t)(SRC) == (uint32_t)GPTIM_TRIG_T2) ||                   \
     ((uint32_t)(SRC) == (uint32_t)GPTIM_TRIG_T3) || ((uint32_t)(SRC) == (uint32_t)GPTIM_TRIG_T4) ||                   \
     ((uint32_t)(SRC) == (uint32_t)GPTIM_TRIG_T5) || ((uint32_t)(SRC) == (uint32_t)GPTIM_TRIG_T9) ||                   \
     ((uint32_t)(SRC) == (uint32_t)GPTIM_TRIG_T14) || ((uint32_t)(SRC) == (uint32_t)GPTIM_TRIG_T21) ||                 \
     ((uint32_t)(SRC) == (uint32_t)GPTIM_TRIG_TXCK) || ((uint32_t)(SRC) == (uint32_t)GPTIM_TRIG_CCPXCH1) ||            \
     ((uint32_t)(SRC) == (uint32_t)GPTIM_TRIG_CCPXCH2) || ((uint32_t)(SRC) == (uint32_t)GPTIM_TRIG_CCPXCH3) ||         \
     ((uint32_t)(SRC) == (uint32_t)GPTIM_TRIG_CCPXCH4))

/**通用定时器从模式*/
typedef enum
{
    /**从模式禁止*/
    GPTIM_SLAVEMODE_FORBIDDEN = 0x0U,
    /**触发模式*/
    GPTIM_SLAVEMODE_TRIG = 0x4U,
    /**门控模式*/
    GPTIM_SLAVEMODE_GATE = 0x5U,
    /**复位模式*/
    GPTIM_SLAVEMODE_RESET = 0x6U,
    /** 计数模式 2*/
    GPTIM_SLAVEMODE_COUNT2 = 0x7U
} GPtimer_SlaveMode_t;
/**检查通用定时器从模式*/
#define CHECK_GPTIM_SLAVE_MODE(SEL)                                                                                    \
    (((SEL) == GPTIM_SLAVEMODE_FORBIDDEN) || ((SEL) == GPTIM_SLAVEMODE_TRIG) || ((SEL) == GPTIM_SLAVEMODE_GATE) ||     \
     ((SEL) == GPTIM_SLAVEMODE_RESET) || ((SEL) == GPTIM_SLAVEMODE_COUNT2))

/* PRQA S 0779 ++ #KQR000779 */
/**通用定时器主模式*/
typedef enum
{
    /** TXUR 位作为触发输出 TRGO*/
    GPTIM_MASTERMODE_TRIGOUT_TXUR,
    /**使能信号 TXEN 作为触发输出 TRGO*/
    GPTIM_MASTERMODE_TRIGOUT_TXEN,
    /**TXIF 信号作为触发输出 TRGO*/
    GPTIM_MASTERMODE_TRIGOUT_TXIF,
    /**CC1IF 脉冲作为触发输出 TRGO*/
    GPTIM_MASTERMODE_TRIGOUT_CC1IF,
    /** CCPxCH1 作为触发输出 TRGO*/
    GPTIM_MASTERMODE_TRIGOUT_CCPXCH1,
    /** CCPxCH2 作为触发输出 TRGO*/
    GPTIM_MASTERMODE_TRIGOUT_CCPXCH2,
    /** CCPxCH3 作为触发输出 TRGO*/
    GPTIM_MASTERMODE_TRIGOUT_CCPXCH3,
    /** CCPxCH4 作为触发输出 TRGO*/
    GPTIM_MASTERMODE_TRIGOUT_CCPXCH4
} GPtimer_MasterMode_t;
/**检查通用定时器主模式*/
#define CHECK_GPTIM_MASTER_MODE(SEL) ((uint32_t)(SEL) <= (uint32_t)GPTIM_MASTERMODE_TRIGOUT_CCPXCH4)
/* PRQA S 0779 -- #KQR000779 */

/** 通用定时器更新方式 */
typedef enum
{
    /** 周期更新 */
    GPTIM_UPDATE_PERIODIC,
    /** 立即更新 */
    GPTIM_UPDATE_NOW
} GPtimer_UpdateMode_t;
/** 检查通用定时器更新方式 */
#define CHECK_GPTIM_UPDATE_MODE(MOD) ((uint32_t)(MOD) <= (uint32_t)GPTIM_UPDATE_NOW)

/** 触发输入极性选择位 */
typedef enum
{
    /** TRGI高电平/上升沿有效 */
    GPTIM_TRGI_HIGH_RISING_EDGE,
    /** TRGI低电平/下降沿有效  */
    GPTIM_TRGI_LOW_FALLING_EDGE
} GPtimer_InputTriggerPolarity_t;
/** 检查触发输入极性 */
#define CHECK_GPTIM_INPUT_TRIGGER_POLARITY(MOD) ((uint32_t)(MOD) <= (uint32_t)GPTIM_TRGI_LOW_FALLING_EDGE)

/**
 * @brief pointer to Timer/CCP Register Map
 *
 */
typedef GeneralTimer_RegisterMap_t *kpGTRegM;
/******************************************************************************
 *                      Export Variables
 ******************************************************************************/

/******************************************************************************
 *                      Export Functions
 ******************************************************************************/

/**
 * @brief 配置定时/计数的值 \n
 *              除T20,T21为32位取值外,其余均为16位取值,在填入counter值时会将高16位清零
 *
 * @note 为避免不可预知的行为，强烈建议在调用此函数前，先停止目标定时器。
 *
 * @param Module: 指向GPTimer内存结构的指针 \n
 *              取值为 T0_PTR ~ T4_PTR, T20_PTR ~T21_PTR(具体型号可能有差异)
 * @param value: 设置的值 0~0xFFFF
 * @retval 无.
 */
KF_INLINE void GPTimer_LL_SetCounter(GeneralTimer_RegisterMap_t *const Module, uint32_t Value)
{
    KF_GPTIMER_ASSERT(CHECK_GPTIM_ALL_PERIPH_ADDR(Module));

    /* T20/21  is 32bit, others are 16bit */
    if ((Module == T21_PTR) || (Module == T20_PTR))
    {
        Module->CNT.reg = Value;
    }
    else
    {
        Module->CNT.reg = (Value & 0x0000FFFFU);
    }
}

/**
 * @brief 获取定时/计数的当前值
 *
 * @param Module 指向GPTimer内存结构的指针 \n
 *              取值为 T0_PTR ~ T4_PTR, T20_PTR ~T21_PTR(具体型号可能有差异)
 * @retval uint32_t 当前值
 */
KF_INLINE uint32_t GPTimer_LL_GetCounter(GeneralTimer_RegisterMap_t *const Module)
{
    KF_GPTIMER_ASSERT(CHECK_GPTIM_ALL_PERIPH_ADDR(Module));

#if GPT_FEATURE_READ_CNT_CRITICAL
    uint32_t          criticalStatus;
    uint32_t          timerStartStatus;
    volatile uint32_t timerCount;

    criticalStatus   = Intr_LL_EnterCritical();
    timerStartStatus = Module->CTL1.bits.TXEN;
    /* Disable Timer */
    Module->CTL1.bits.TXEN = 0U;
    /* Read timer count */
    timerCount = Module->CNT2.reg;
    /* Rewrite timer count */
    Module->CNT.reg = timerCount;
    /* Resume AIE and timer */
    Module->CTL1.bits.TXEN = timerStartStatus;
    Intr_LL_ExitCritical(criticalStatus);

    /* T20,T21 is 32bits, others are 16bits */
    return timerCount;
#else
    return Module->CNT.reg;
#endif
}

/**
 * @brief 获取计数溢出中断标志
 *
 * @param Module 指向GPTimer内存结构的指针 \n
 *              取值为 T0_PTR ~ T4_PTR, T20_PTR ~T21_PTR(具体型号可能有差异)
 * @retval bool 溢出标志 \n
 *              true -- Tx溢出标志置位 \n
 *              false -- Tx溢出标志未置位
 */
KF_INLINE bool GPTimer_LL_GetOverflowIntrFlag(const GeneralTimer_RegisterMap_t *const Module)
{
    KF_GPTIMER_ASSERT(CHECK_GPTIM_ALL_PERIPH_ADDR(Module));

    return (Module->CTL1.bits.TXIF != 0U);
}

/**
 * @brief 设置Tx 溢出中断
 *
 * @param Module 指向GPTimer内存结构的指针 \n
 *              取值为 T0_PTR ~ T4_PTR, T20_PTR ~T21_PTR(具体型号可能有差异)
 * @param EnableSta 中断使能状态 \n
 *              true -- 使能中断 \n
 *              false -- 不使能中断
 * @retval void
 */
KF_INLINE void GPTimer_LL_SetOverFlowIntrEnabled(GeneralTimer_RegisterMap_t *const Module, bool EnableSta)
{
    KF_GPTIMER_ASSERT(CHECK_GPTIM_ALL_PERIPH_ADDR(Module));

    Module->CTL1.bits.TXIE = EnableSta ? 1U : 0U;
}

/**
 * @brief 使能Tx 溢出中断
 *
 * @param Module 指向GPTimer内存结构的指针 \n
 *              取值为 T0_PTR ~ T4_PTR, T20_PTR ~T21_PTR(具体型号可能有差异)
 * @retval void
 */
KF_INLINE void GPTimer_LL_EnableOverflowIntr(GeneralTimer_RegisterMap_t *const Module)
{
    KF_GPTIMER_ASSERT(CHECK_GPTIM_ALL_PERIPH_ADDR(Module));

    Module->CTL1.bits.TXIE = 1U;
}

/**
 * @brief 关闭Tx 溢出中断
 *
 * @param Module 指向GPTimer内存结构的指针 \n
 *              取值为 T0_PTR ~ T4_PTR, T20_PTR ~T21_PTR(具体型号可能有差异)
 * @retval void
 */
KF_INLINE void GPTimer_LL_DisableOverflowIntr(GeneralTimer_RegisterMap_t *const Module)
{
    KF_GPTIMER_ASSERT(CHECK_GPTIM_ALL_PERIPH_ADDR(Module));

    Module->CTL1.bits.TXIE = 0U;
}

/**
 * @brief 获取 Tx 溢出中断
 *
 * @param Module 指向GPTimer内存结构的指针 \n
 *              取值为 T0_PTR ~ T4_PTR, T20_PTR ~T21_PTR(具体型号可能有差异)
 * @retval bool 中断使能状态 \n
 *              true -- 使能中断 \n
 *              false -- 不使能中断
 */
KF_INLINE bool GPTimer_LL_GetOverFlowIntrEnableState(const GeneralTimer_RegisterMap_t *const Module)
{
    KF_GPTIMER_ASSERT(CHECK_GPTIM_ALL_PERIPH_ADDR(Module));

    return (Module->CTL1.bits.TXIE != 0U);
}

/**
 * @brief 更新定时器计数模式
 *
 * @param Module 指向GPTimer内存结构的指针 \n
 *              取值为 T0_PTR ~ T4_PTR, T20_PTR ~T21_PTR(具体型号可能有差异)
 * @param  Manner 计数方式,具体见枚举类型 @ref Timer_CountingManner_t
 * @retval 无
 */
KF_INLINE void GPTimer_LL_SetCounterManner(GeneralTimer_RegisterMap_t *const Module, Timer_CountingManner_t Manner)
{
    KF_GPTIMER_ASSERT(CHECK_GPTIM_ALL_PERIPH_ADDR(Module));
    KF_GPTIMER_ASSERT(CHECK_TIM_COUNT_MANNER(Manner));

    Module->CTL1.bits.TXCMS = (uint32_t)Manner;
}

/**
 * @brief 读取计数方向标志位
 *
 * @param Module 指向GPTimer内存结构的指针 \n
 *              取值为 T0_PTR ~ T4_PTR, T20_PTR ~T21_PTR(具体型号可能有差异)
 * @retval Timer_CountingDir_t 计数方式 \n
 *          UP_COUNTING   -- 当前计数方向为向上计数 \n
 *          DOWN_COUNTING -- 当前计数方向为向下计数
 */
KF_INLINE Timer_CountingDir_t GPTimer_LL_GetCountingDir(const GeneralTimer_RegisterMap_t *const Module)
{
    KF_GPTIMER_ASSERT(CHECK_GPTIM_ALL_PERIPH_ADDR(Module));

    return ((Module->CTL1.bits.TXDIR != 0U) ? (UP_COUNTING) : (DOWN_COUNTING));
}

/**
 * @brief 配置Tx工作时钟选择位
 *
 * @param Module 指向GPTimer内存结构的指针 \n
 *              取值为 T0_PTR ~ T4_PTR, T20_PTR ~T21_PTR(具体型号可能有差异)
 * @param ClockSrc 定时器工作时钟,具体见枚举类型 @ref Timer_ClockSource_t
 * @retval void
 */
KF_INLINE void GPTimer_LL_SetClkSrc(GeneralTimer_RegisterMap_t *const Module, Timer_ClockSource_t ClockSrc)
{
    KF_GPTIMER_ASSERT(CHECK_GPTIM_ALL_PERIPH_ADDR(Module));
    KF_GPTIMER_ASSERT(CHECK_TIM_CLK(ClockSrc));
    KF_GPTIMER_ASSERT((ClockSrc == TIM_INTLF_T0) && (Module == T0_PTR));

    Module->CTL1.bits.TXCLK = (uint32_t)ClockSrc;
}

/**
 * @brief Tx计数模式外部触发脉冲输入同步控制 \n
 *              当定时器为定时模式时(TXCS = 0),该位被忽略
 *
 * @param Module 指向GPTimer内存结构的指针 \n
 *              取值为 T0_PTR ~ T4_PTR, T20_PTR ~T21_PTR(具体型号可能有差异)
 * @param SyncStatus 外部触发脉冲输入同步状态 \n
 *              true -- 外部触发脉冲与工作时钟同步后作为计数时钟 \n
 *              false -- 外部触发脉冲作为计数时钟
 * @retval void
 */
KF_INLINE void GPTimer_LL_SetExternalPulseSyncWithClk(GeneralTimer_RegisterMap_t *const Module, bool SyncStatus)
{
    KF_GPTIMER_ASSERT(CHECK_GPTIM_ALL_PERIPH_ADDR(Module));

    Module->CTL1.bits.TXSY = SyncStatus ? 1U : 0U;
}

/**
 * @brief 定时/计数模式选择
 *
 * @param Module 指向GPTimer内存结构的指针 \n
 *              取值为 T0_PTR ~ T4_PTR, T20_PTR ~T21_PTR(具体型号可能有差异)
 * @param  Mode 计数模式,具体见枚举类型 @ref Timer_Mode_t
 * @retval void
 */
KF_INLINE void GPTimer_LL_SetWorkingMode(GeneralTimer_RegisterMap_t *const Module, Timer_Mode_t Mode)
{
    KF_GPTIMER_ASSERT(CHECK_GPTIM_ALL_PERIPH_ADDR(Module));
    KF_GPTIMER_ASSERT(CHECK_TIM_WORK_MODE(Mode));

    Module->CTL1.bits.TXCS = (uint32_t)Mode;
}

/**
 * @brief 使能Timer
 *
 * @param Module 指向GPTimer内存结构的指针 \n
 *              取值为 T0_PTR ~ T4_PTR, T20_PTR ~T21_PTR(具体型号可能有差异)
 * @retval none
 */
KF_INLINE void GPTimer_LL_Start(GeneralTimer_RegisterMap_t *const Module)
{
    KF_GPTIMER_ASSERT(CHECK_GPTIM_ALL_PERIPH_ADDR(Module));

    Module->CTL1.bits.TXEN = 1U;
}

/**
 * @brief 禁止Timer
 *
 * @param Module 指向GPTimer内存结构的指针 \n
 *              取值为 T0_PTR ~ T4_PTR, T20_PTR ~T21_PTR(具体型号可能有差异)
 * @retval none
 */
KF_INLINE void GPTimer_LL_Stop(GeneralTimer_RegisterMap_t *const Module)
{
    KF_GPTIMER_ASSERT(CHECK_GPTIM_ALL_PERIPH_ADDR(Module));

    Module->CTL1.bits.TXEN = 0U;
}

/**
 * @brief 配置Timer使能
 *
 * @param Module 指向GPTimer内存结构的指针 \n
 *              取值为 T0_PTR ~ T4_PTR, T20_PTR ~T21_PTR(具体型号可能有差异)
 * @retval none
 */
KF_INLINE void GPTimer_LL_SetEnabled(GeneralTimer_RegisterMap_t *const Module, bool EnableSta)
{
    KF_GPTIMER_ASSERT(CHECK_GPTIM_ALL_PERIPH_ADDR(Module));

    Module->CTL1.bits.TXEN = EnableSta ? 1U : 0U;
}

/**
 * @brief 使能更新事件生成位 \n
 *              该位硬件自动清零,此位不受 TXUDEN 控制
 *
 * @param Module 指向GPTimer内存结构的指针 \n
 *              取值为 T0_PTR ~ T4_PTR, T20_PTR ~T21_PTR(具体型号可能有差异)
 * @retval void
 */
KF_INLINE void GPTimer_LL_SetUpdateImmediately(GeneralTimer_RegisterMap_t *const Module)
{
    KF_GPTIMER_ASSERT(CHECK_GPTIM_ALL_PERIPH_ADDR(Module));

    Module->CTL2.bits.TXUR = 1U;
}

/**
 * @brief 设置主从模式同步
 *
 * @param Module 指向GPTimer内存结构的指针 \n
 *              取值为 T0_PTR ~ T4_PTR, T20_PTR ~T21_PTR(具体型号可能有差异)
 * @param EnableSta 主从模式同步状态 \n
 *              true -- 使能主从模式同步 \n
 *              false -- 不使能主从模式同步
 * @retval void
 */
KF_INLINE void GPTimer_LL_SetMasterSlaveSync(GeneralTimer_RegisterMap_t *const Module, bool EnableSta)
{
    KF_GPTIMER_ASSERT(CHECK_GPTIM_ALL_PERIPH_ADDR(Module));

    Module->CTL2.bits.TXMSSYNC = EnableSta ? 1U : 0U;
}

/**
 * @brief 选择通用定时器触发输入TRGI
 *
 * @param Module 指向GPTimer内存结构的指针 \n
 *              取值为 T0_PTR ~ T4_PTR, T20_PTR ~T21_PTR(具体型号可能有差异)
 * @param TrigSrcInput 定时器触发输入源,具体见枚举类型 @ref GPtimer_TrigSrc_t
 * @retval void
 */
KF_INLINE void GPTimer_LL_SelectTimerTrigSrc(GeneralTimer_RegisterMap_t *const Module, GPtimer_TrigSrc_t TrigSrcInput)
{
    KF_GPTIMER_ASSERT(CHECK_GPTIM_ALL_PERIPH_ADDR(Module));
    KF_GPTIMER_ASSERT(CHECK_GPTIM_TRG_SOURCE(TrigSrcInput));

    if (TrigSrcInput != GPTIM_TRIG_CCPXCH4)
    {
        Module->CCP_CTL4.bits.CCPXCH4 = 0U;
        Module->CTL2.bits.TXTS        = (uint32_t)TrigSrcInput;
    }
    else
    {
        Module->CTL2.bits.TXTS        = (uint32_t)GPTIM_TRIG_CCPXCH1;
        Module->CCP_CTL4.bits.CCPXCH4 = 1U;
    }
}

/**
 * @brief 从模式选择
 *
 * @param Module 指向GPTimer内存结构的指针 \n
 *              取值为 T0_PTR ~ T4_PTR, T20_PTR ~T21_PTR(具体型号可能有差异)
 * @param SlaveMode 定时器从模式,具体见枚举类型 @ref GPtimer_SlaveMode_t
 * @retval void
 */
KF_INLINE void GPTimer_LL_SelectSlaveMode(GeneralTimer_RegisterMap_t *const Module, GPtimer_SlaveMode_t SlaveMode)
{
    KF_GPTIMER_ASSERT(CHECK_GPTIM_ALL_PERIPH_ADDR(Module));
    KF_GPTIMER_ASSERT(CHECK_GPTIM_SLAVE_MODE(SlaveMode));

    Module->CTL2.bits.TXSMS = (uint32_t)SlaveMode;
}

/**
 * @brief 主模式选择
 *
 * @param Module 指向GPTimer内存结构的指针 \n
 *              取值为 T0_PTR ~ T4_PTR, T20_PTR ~T21_PTR(具体型号可能有差异)
 * @param MasterMode 基础定时器主模式,具体见枚举类型 @ref GPtimer_MasterMode_t
 * @retval void
 */
KF_INLINE void GPTimer_LL_SelectMasterMode(GeneralTimer_RegisterMap_t *const Module, GPtimer_MasterMode_t MasterMode)
{
    KF_GPTIMER_ASSERT(CHECK_GPTIM_ALL_PERIPH_ADDR(Module));
    KF_GPTIMER_ASSERT(CHECK_GPTIM_MASTER_MODE(MasterMode));

    Module->CTL2.bits.TXMMS = (uint32_t)MasterMode;
}

/**
 * @brief 设置更新事件控制方式
 *
 * @param Module 指向GPTimer内存结构的指针 \n
 *              取值为 T0_PTR ~ T4_PTR, T20_PTR ~T21_PTR(具体型号可能有差异)
 * @param UpdateMode 定时器更新方式 \n
 *              GPTIM_UPDATE_PERIODIC -- 周期更新 \n
 *              GPTIM_UPDATE_NOW -- 立即更新
 * @retval void
 */
KF_INLINE void GPTimer_LL_SetUpdateEventMode(GeneralTimer_RegisterMap_t *const Module, GPtimer_UpdateMode_t UpdateMode)
{
    KF_GPTIMER_ASSERT(CHECK_GPTIM_ALL_PERIPH_ADDR(Module));
    KF_GPTIMER_ASSERT(CHECK_GPTIM_UPDATE_MODE(UpdateMode));

    Module->CTL2.bits.TXUDEVT = (uint32_t)UpdateMode;
}

/**
 * @brief 配置更新使能
 *
 * @param Module 指向GPTimer内存结构的指针 \n
 *              取值为 T0_PTR ~ T4_PTR, T20_PTR ~T21_PTR(具体型号可能有差异)
 * @param EnableSta 更新使能状态 \n
 *          true  -- 使能更新 \n
 *          false  -- 禁止更新
 * @retval void
 */
KF_INLINE void GPTimer_LL_SetUpdateEnabled(GeneralTimer_RegisterMap_t *const Module, bool EnableSta)
{
    KF_GPTIMER_ASSERT(CHECK_GPTIM_ALL_PERIPH_ADDR(Module));

    Module->CTL2.bits.TXUDEN = EnableSta ? 1U : 0U;
}

/**
 * @brief 配置Tim预分频值 \n
 *              除T20,T21为32位取值外,其余均为16位取值,在填入预分频系数时会将高16位清零
 *
 * @param Module 指向GPTimer内存结构的指针 \n
 *              取值为 T0_PTR ~ T4_PTR, T20_PTR ~T21_PTR(具体型号可能有差异)
 * @param Prescale 预分频值, 0x0 ~ 0xffff
 * @retval void
 */
KF_INLINE void GPTimer_LL_SetPrescaler(GeneralTimer_RegisterMap_t *const Module, uint32_t Prescale)
{
    KF_GPTIMER_ASSERT(CHECK_GPTIM_ALL_PERIPH_ADDR(Module));

    /* T20/21  is 32bit, others are 16bit */
    if ((Module == T21_PTR) || (Module == T20_PTR))
    {
        Module->PRSC.reg = Prescale;
    }
    else
    {
        Module->PRSC.reg = (Prescale & 0x0000FFFFU);
    }
}

/**
 * @brief 获取Tim定时/计数周期寄存器
 *
 * @param Module 指向GPTimer内存结构的指针 \n
 *              取值为 T0_PTR ~ T4_PTR, T20_PTR ~T21_PTR(具体型号可能有差异)
 * @retval uint32_t 当前周期值
 */
KF_INLINE uint32_t GPTimer_LL_GetPeriod(const GeneralTimer_RegisterMap_t *const Module)
{
    KF_GPTIMER_ASSERT(CHECK_GPTIM_ALL_PERIPH_ADDR(Module));

    return Module->PPX.reg;
}

/**
 * @brief 设置Tim定时/计数周期寄存器
 *
 * @param Module 指向GPTimer内存结构的指针 \n
 *              取值为 T0_PTR ~ T4_PTR, T20_PTR ~T21_PTR(具体型号可能有差异)
 * @param Period 需要设置的周期值,0x0 ~ 0xffff
 * @retval void
 */
KF_INLINE void GPTimer_LL_SetPeriod(GeneralTimer_RegisterMap_t *const Module, uint32_t Period)
{
    KF_GPTIMER_ASSERT(CHECK_GPTIM_ALL_PERIPH_ADDR(Module));

    /* T20/21  is 32bit, others are 16bit */
    if ((Module == T21_PTR) || (Module == T20_PTR))
    {
        Module->PPX.reg = Period;
    }
    else
    {
        Module->PPX.reg = (Period & 0x0000FFFFU);
    }
}

/**
 * @brief 设置更新计数器 \n
 *              TXUDEN=1,TXUDEVT=0时,只有在 Tx_UDTIM 的值向下计数到 0 时才会 \n
 *              更新 Tx 为时基的预分频器,周期,占空比,输出控制,输出配置寄存器
 *
 * @param Module 指向GPTimer内存结构的指针 \n
 *              取值为 T0_PTR ~ T4_PTR, T20_PTR ~T21_PTR(具体型号可能有差异)
 * @param UpdateCounter 更新计数器值,0x0 ~ 0xff
 * @retval void
 */
KF_INLINE void GPTimer_LL_SetUpdateCounter(GeneralTimer_RegisterMap_t *const Module, uint8_t UpdateCounter)
{
    KF_GPTIMER_ASSERT(CHECK_GPTIM_ALL_PERIPH_ADDR(Module));

    Module->UDTIM.bits.TXUD = UpdateCounter;
}

/**
 * @brief 清除计数溢出中断标志
 *
 * @param Module 指向GPTimer内存结构的指针 \n
 *              取值为 T0_PTR ~ T4_PTR, T20_PTR ~T21_PTR(具体型号可能有差异)
 * @retval void
 */
KF_INLINE void GPTimer_LL_ClearOverflowIntrFlag(GeneralTimer_RegisterMap_t *const Module)
{
    Module->CCP_SRIC.bits.TXIC = 1U;
    NOP();
    NOP();
    NOP();
    NOP();
    Module->CCP_SRIC.bits.TXIC = 0U;
}

/**
 * @brief 清除更新事件中断标志
 *
 * @param Module 指向GPTimer内存结构的指针 \n
 *              取值为 T0_PTR ~ T4_PTR, T20_PTR ~T21_PTR(具体型号可能有差异)
 * @retval void
 */
KF_INLINE void GPTimer_LL_ClearUpdateIntrFlag(GeneralTimer_RegisterMap_t *const Module)
{
    Module->CCP_SRIC.bits.TXUIC = 1U;
    NOP();
    NOP();
    NOP();
    NOP();
    Module->CCP_SRIC.bits.TXUIC = 0U;
}

/**
 * @brief 清除触发中断标志
 *
 * @param Module 指向GPTimer内存结构的指针 \n
 *              取值为 T0_PTR ~ T4_PTR, T20_PTR ~T21_PTR(具体型号可能有差异)
 * @retval void
 */
KF_INLINE void GPTimer_LL_ClearTriggerIntrFlag(GeneralTimer_RegisterMap_t *const Module)
{
    Module->CCP_SRIC.bits.TXTIC = 1U;
    NOP();
    NOP();
    NOP();
    NOP();
    Module->CCP_SRIC.bits.TXTIC = 0U;
}

/**
 * @brief 配置同步读计数器使能位
 *
 * @param Module 指向GPTimer内存结构的指针 \n
 *              取值为 T0_PTR ~ T4_PTR, T20_PTR ~T21_PTR(具体型号可能有差异)
 * @param EnableSta 使能状态 \n
 *          true  -- 使能 \n
 *          false  -- 禁止
 * @retval void
 */
KF_INLINE void GPTimer_LL_SetSyncReadTimerEnabled(GeneralTimer_RegisterMap_t *const Module, bool EnableSta)
{
    KF_GPTIMER_ASSERT(CHECK_GPTIM_ALL_PERIPH_ADDR(Module));

    Module->CTL1.bits.READTEN = EnableSta ? 1U : 0U;
}

/**
 * @brief 设置触发输入极性选择位
 *
 * @param Module 指向GPTimer内存结构的指针 \n
 *              取值为 T0_PTR ~ T4_PTR, T20_PTR ~T21_PTR(具体型号可能有差异)
 * @param Polarity 触发输入极性选择 \n
 *              GPTIM_TRGI_HIGH_RISING_EDGE -- TRGI高电平/上升沿有效 \n
 *              GPTIM_TRGI_LOW_FALLING_EDGE -- TRGI低电平/下降沿有效
 * @retval void
 */
KF_INLINE void
GPTimer_LL_SetInputTriggerPolarity(GeneralTimer_RegisterMap_t *const Module, GPtimer_InputTriggerPolarity_t Polarity)
{
    KF_GPTIMER_ASSERT(CHECK_GPTIM_ALL_PERIPH_ADDR(Module));
    KF_GPTIMER_ASSERT(CHECK_GPTIM_INPUT_TRIGGER_POLARITY(Polarity));

    Module->UDTIM.bits.TRGPOL = (uint32_t)Polarity;
}

/**
 * @brief 获取计数溢出中断发生状态
 *
 * @param Module 指向GPTimer内存结构的指针 \n
 *              取值为 T0_PTR ~ T4_PTR, T18_PTR ~T23_PTR(具体型号可能有差异)
 * @retval bool 中断发生状态
 *         true    发生了中断，且已使能
 *         false    未发生中断，或未使能
 */
KF_INLINE bool GPTimer_LL_GetOverflowIntrState(const GeneralTimer_RegisterMap_t *const Module)
{
    KF_GPTIMER_ASSERT(CHECK_GPTIM_ALL_PERIPH_ADDR(Module));

    bool flag  = (Module->CTL1.bits.TXIF != 0U) ? true : false;
    bool state = (Module->CTL1.bits.TXIE != 0U) ? true : false;
    return flag && state;
}

#ifdef __cplusplus
}
#endif /*End of __cplusplus*/
#endif /*End of KF32A158SF_DRV_GPTIMER_H*/
/* EOF */
