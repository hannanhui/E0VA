/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name        : kf32a158sf_drv_btimer.h
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
#ifndef KF32A158SF_DRV_BTIMER_H
#define KF32A158SF_DRV_BTIMER_H

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
#include "kf_types.h"
#include "kf32a158sf_timer_base.h"
#include "kf32a158sf_reg_btimer.h"

#ifdef KF_DRV_BTIM_ASSERT
#include "dev_assert.h"
#define KF_BTIM_ASSERT(x) KF_DEV_ASSERT(x)
#else
#define KF_BTIM_ASSERT(x) ((void)0U)
#endif
/******************************************************************************
 *                      Macro or Inline
 ******************************************************************************/

/******************************************************************************
 *                      Type definitions
 ******************************************************************************/

/**TxCK引脚选择*/
typedef enum
{
    /**TxCK 引脚*/
    BTIM_TXCK = 0x00U,
    /**GTxCK1 引脚*/
    BTIM_GTXCK1 = 0X01U,
    /**GTxCK2 引脚*/
    BTIM_GTXCK2 = 0X02U,
    /**GTxCK3 引脚*/
    BTIM_GTXCK3 = 0X03U,
} Btimer_TxckPin_t;
/**检查TxCK引脚选择*/
#define CHECK_BTIM_TXCK(SEL) ((uint32_t)(SEL) <= (uint32_t)(BTIM_GTXCK3))

/**基础定时器触发输入 TRIG 选择*/
typedef enum
{
    /**T1*/
    BTIM_TRIG_T1 = 0x0U,
    /**T2*/
    BTIM_TRIG_T2 = 0x1U,
    /**T3*/
    BTIM_TRIG_T3 = 0x2U,
    /**T4*/
    BTIM_TRIG_T4 = 0x3U,
    /**T5*/
    BTIM_TRIG_T5 = 0x4U,
    /**T9*/
    BTIM_TRIG_T9 = 0x5U,
    /**T14*/
    BTIM_TRIG_T14 = 0x6U,
    /**T21*/
    BTIM_TRIG_T21 = 0xBU,
    /**TxCK*/
    BTIM_TRIG_TXCK = 0xCU,
} Btimer_TrigSrc_t;
/**检查基础定时器触发输入*/
#define CHECK_BTIM_TRG_SOURCE(SRC)                                                                                     \
    (((uint32_t)(SRC) == (uint32_t)BTIM_TRIG_T1) || ((uint32_t)(SRC) == (uint32_t)BTIM_TRIG_T2) ||                     \
     ((uint32_t)(SRC) == (uint32_t)BTIM_TRIG_T3) || ((uint32_t)(SRC) == (uint32_t)BTIM_TRIG_T4) ||                     \
     ((uint32_t)(SRC) == (uint32_t)BTIM_TRIG_T5) || ((uint32_t)(SRC) == (uint32_t)BTIM_TRIG_T9) ||                     \
     ((uint32_t)(SRC) == (uint32_t)BTIM_TRIG_T14) || ((uint32_t)(SRC) == (uint32_t)BTIM_TRIG_T21) ||                   \
     ((uint32_t)(SRC) == (uint32_t)BTIM_TRIG_TXCK))

/**基础定时器从模式*/
typedef enum
{
    /**从模式禁止*/
    BTIM_SLAVEMODE_FORBIDDEN = 0x0U,
    /**门控模式*/
    BTIM_SLAVEMODE_GATE = 0x5U,
    /**复位模式*/
    BTIM_SLAVEMODE_RESET = 0x6U,
    /** 计数模式 2*/
    BTIM_SLAVEMODE_COUNT2 = 0x7U,
} Btimer_SlaveMode_t;
/**检查基础定时器从模式*/
#define CHECK_BTIM_SLAVE_MODE(SEL)                                                                                     \
    (((SEL) == BTIM_SLAVEMODE_FORBIDDEN) || ((SEL) == BTIM_SLAVEMODE_GATE) || ((SEL) == BTIM_SLAVEMODE_RESET) ||       \
     ((SEL) == BTIM_SLAVEMODE_COUNT2))

/**基础定时器主模式*/
typedef enum
{
    /** TXUR 位作为触发输出 TRGO*/
    BTIM_MASTERMODE_TRIGOUT_TXUR = 0x0U,
    /**使能信号 TXEN 作为触发输出 TRGO*/
    BTIM_MASTERMODE_TRIGOUT_TXEN = 0x1U,
    /**TXIF 信号作为触发输出 TRGO*/
    BTIM_MASTERMODE_TRIGOUT_TXIF = 0x2U,
} Btimer_MasterMode_t;
/**检查基础定时器主模式*/
#define CHECK_BTIM_MASTER_MODE(SEL) ((uint32_t)(SEL) <= (uint32_t)BTIM_MASTERMODE_TRIGOUT_TXIF)

/** 基础定时器更新方式 */
typedef enum
{
    /** 周期更新 */
    BTIM_UPDATE_PERIODIC = 0x0U,
    /** 立即更新 */
    BTIM_UPDATE_NOW = 0x1U,
} Btimer_UpdateMode_t;
#define CHECK_BTIM_UPDATE_MODE(MOD) ((uint32_t)(MOD) <= (uint32_t)BTIM_UPDATE_NOW)

/**基础定时器中断序号*/
typedef enum
{
    /**Tx 更新事件*/
    BTIM_INT_UPDATE_EVENT = 0x0U,
    /**Tx 触发事件*/
    BTIM_INT_TRIG_EVENT = 0x1U,
    /**Tx 计数溢出中断*/
    BTIM_INT_OVERFLOW = 0x2U,
} Btimer_Interrupt_t;
/**检查中断类型*/
#define CHECK_BTIM_INT(INT) ((uint32_t)(INT) <= (uint32_t)BTIM_INT_OVERFLOW)
/**基础定时器DMA序号*/
typedef enum
{
    /**更新事件的 DMA*/
    BTIM_DMA_UPDATE_EVENT = 0x3U,
    /**触发事件的 DMA*/
    BTIM_DMA_TRIG_EVENT = 0x4U,
} Btimer_DmaTrigger_t;
/**检查DMA类型*/
#define CHECK_BTIM_DMA(DMA) (((DMA) == BTIM_DMA_UPDATE_EVENT) || ((DMA) == BTIM_DMA_TRIG_EVENT))

/******************************************************************************
 *                      Export Variables
 ******************************************************************************/

/******************************************************************************
 *                      Export Functions
 ******************************************************************************/

/**
 * @brief 获取Tim定时/计数的当前值
 * @param  无
 * @retval uint16_t 当前值
 */
KF_INLINE uint16_t BTimer_LL_GetCounter(void)
{
    return (uint16_t)T14_PTR->CNT.bits.TXCNT;
}

/**
 * @brief 设置定时器Tx的计数值
 * @param Value 计数值,0x0 ~ 0xffff
 * @retval void
 */
KF_INLINE void BTimer_LL_SetCounter(uint16_t Value)
{
    T14_PTR->CNT.bits.TXCNT = (uint32_t)Value;
}

/**
 * @brief 选择TXCK引脚
 *
 * @param TxckPin 选择的TxCK引脚 \n
 *              BTIM_TXCK -- TxCK 引脚 \n
 *              BTIM_GTXCK1 -- GTxCK1 引脚 \n
 *              BTIM_GTXCK2 -- GTxCK2 引脚 \n
 *              BTIM_GTXCK3 -- GTxCK3 引脚
 * @retval void
 */
KF_INLINE void BTimer_LL_SelectTxckPin(Btimer_TxckPin_t TxckPin)
{
    KF_BTIM_ASSERT(CHECK_BTIM_TXCK(TxckPin));

    T14_PTR->CTL1.bits.TCKSEL = (uint32_t)TxckPin;
}

/**
 * @brief 更新定时器计数模式
 * @param  Manner : 取值: \n
 *              TIM_MANNER_DOWN_FLAG \n
 *              TIM_MANNER_UP_FLAG \n
 *              TIM_MANNER_UPDOWN_UP_FLAG \n
 *              TIM_MANNER_UPDOWN_DOWN_FLAG \n
 *              TIM_MANNER_UPDOWN_BOTH_FLAG
 * @retval 无
 */
KF_INLINE void BTimer_LL_SetCounterManner(Timer_CountingManner_t Manner)
{
    KF_BTIM_ASSERT(CHECK_TIM_COUNT_MANNER(Manner));

    T14_PTR->CTL1.bits.TXCMS = (uint32_t)Manner;
}

/**
 * @brief 获取计数方向标志位
 * @param  void
 * @retval Timer_CountingDir_t \n
 *          UP_COUNTING   当前计数方向为向上计数 \n
 *          DOWN_COUNTING 当前计数方向为向下计数 \n
 */
KF_INLINE Timer_CountingDir_t BTimer_LL_GetCountingDir(void)
{
    return (T14_PTR->CTL1.bits.TXDIR != 0U) ? (UP_COUNTING) : (DOWN_COUNTING);
}

/**
 * @brief 配置Tx工作时钟选择位
 * @param  src : 取值: \n
 *              TIM_SCLK \n
 *              TIM_HFCLK \n
 *              TIM_LFCLK \n
 * @retval 无
 */
KF_INLINE void BTimer_LL_SetClkSrc(Timer_ClockSource_t Src)
{
    KF_BTIM_ASSERT(CHECK_TIM_CLK(Src));

    T14_PTR->CTL1.bits.TXCLK = (uint32_t)Src;
}

/**
 * @brief Tx计数模式外部触发脉冲输入同步控制 \n
 *              当定时器为定时模式时(TXCS = 0),该位被忽略
 *
 * @param SyncStatus 外部触发脉冲输入同步状态 \n
 *              true -- 外部触发脉冲与工作时钟同步后作为计数时钟 \n
 *              false -- 外部触发脉冲作为计数时钟
 * @retval void
 */
KF_INLINE void BTimer_LL_SetExternalPulseSyncWithClk(bool SyncStatus)
{

    T14_PTR->CTL1.bits.TXSY = SyncStatus ? 1U : 0U;
}

/**
 * @brief 定时/计数模式选择
 * @param  mode
 *           TIMING_MODE
 *           COUNTING_MODE
 * @retval void
 */
KF_INLINE void BTimer_LL_SetMode(Timer_Mode_t Mode)
{
    KF_BTIM_ASSERT(CHECK_TIM_WORK_MODE(Mode));

    T14_PTR->CTL1.bits.TXCS = (uint32_t)Mode;
}

/**
 * @brief 设置定时器使能状态
 *
 * @param EnableSta 使能状态
 * @retval void
 */
KF_INLINE void BTimer_LL_SetEnabled(bool EnableSta)
{
    T14_PTR->CTL1.bits.TXEN = EnableSta ? 1U : 0U;
}

/**
 * @brief 启动BTimer
 * @param  void
 * @retval void
 */
KF_INLINE void BTimer_LL_Start(void)
{
    BTimer_LL_SetEnabled(true);
}

/**
 * @brief 停止BTimer
 * @param  void
 * @retval void
 */
KF_INLINE void BTimer_LL_Stop(void)
{
    BTimer_LL_SetEnabled(false);
}

/**
 * @brief 产生触发事件 \n
 *              该位由软件置‘1’,用于产生一个触发事件,定时器停止计数后由硬件自动清‘0’
 *
 * @retval void
 */
KF_INLINE void BTimer_LL_GenerateSoftwareTrigEvent(void)
{
    T14_PTR->CTL2.bits.TXTRG = 1U;
}

/**
 * @brief 设置单脉冲输出使能
 *
 * @param EnableSta 单脉冲输出使能状态 \n
 *              true -- 使能单脉冲输出模式 \n
 *              false -- 单脉冲输出模式未使能
 * @retval void
 */
KF_INLINE void BTimer_LL_SetOnePulseOutputEnabled(bool EnableSta)
{

    T14_PTR->CTL2.bits.PXSPM = EnableSta ? 1U : 0U;
}

/**
 * @brief 单脉冲输出模式选择
 *
 * @param EnableSta 单脉冲输出后定时器关闭状态 \n
 *              true -- 使能定时器关闭 \n
 *              false -- 不使能定时器关闭
 * @retval void
 */
KF_INLINE void BTimer_LL_CloseTimerAfterOnePulseOutput(bool EnableSta)
{

    T14_PTR->CTL2.bits.PXSPMST = EnableSta ? 1U : 0U;
}

/**
 * @brief 使能更新事件生成位
 * @param  无
 * @retval 无
 */
KF_INLINE void BTimer_LL_SetUpdateImmediately(void)
{
    T14_PTR->CTL2.bits.TXUR = 1U;
}

/**
 * @brief 选择基础定时器触发输入TRIG
 *
 * @param TrigSrcInput 定时器触发输入源 \n
 *              BTIM_TRG_T1 -- T1 \n
 *              BTIM_TRG_FLEXMUX -- FlexMUX输出 \n
 *              BTIM_TRG_TXCK -- 定时器TxCK引脚 \n
 *              ...
 *              其余见,枚举类型 Btimer_TrigSrc_t 定义
 * @retval void
 */
KF_INLINE void BTimer_LL_SelectTimerTrigSrc(Btimer_TrigSrc_t TrigSrcInput)
{
    KF_BTIM_ASSERT(CHECK_BTIM_TRG_SOURCE(TrigSrcInput));

    T14_PTR->CTL2.bits.TXTS = (uint32_t)TrigSrcInput;
}

/**
 * @brief 从模式选择
 *
 * @param SlaveMode 定时器从模式 \n
 *              BTIM_SLAVEMODE_FORBIDDEN -- 从模式禁止 \n
 *              BTIM_SLAVEMODE_GATE -- 门控模式 \n
 *              BTIM_SLAVEMODE_RESET -- 复位模式 \n
 *              BTIM_SLAVEMODE_COUNT2 -- 计数模式 2
 * @retval void
 */
KF_INLINE void BTimer_LL_SelectSlaveMode(Btimer_SlaveMode_t SlaveMode)
{
    KF_BTIM_ASSERT(CHECK_BTIM_SLAVE_MODE(SlaveMode));

    T14_PTR->CTL2.bits.TXSMS = (uint32_t)SlaveMode;
}

/**
 * @brief 主模式选择
 *
 * @param MasterMode 基础定时器主模式 \n
 *              BTIM_MASTERMODE_TRIGOUT_TXUR -- TXUR 位作为触发输出 TRGO \n
 *              BTIM_MASTERMODE_TRIGOUT_TXEN -- 使能信号 TXEN 作为触发输出 TRGO \n
 *              BTIM_MASTERMODE_TRIGOUT_TXIF -- TXIF 信号作为触发输出 TRGO
 * @retval void
 */
KF_INLINE void BTimer_LL_SelectMasterMode(Btimer_MasterMode_t MasterMode)
{
    KF_BTIM_ASSERT(CHECK_BTIM_MASTER_MODE(MasterMode));

    T14_PTR->CTL2.bits.TXMMS = (uint32_t)MasterMode;
}

/**
 * @brief 设置更新事件控制方式
 *
 * @param UpdateMode 定时器更新方式 \n
 *              BTIM_UPDATE_PERIODIC -- 周期更新 \n
 *              BTIM_UPDATE_NOW -- 立即更新
 * @retval void
 */
KF_INLINE void BTimer_LL_SetUpdateEventMode(Btimer_UpdateMode_t UpdateMode)
{
    KF_BTIM_ASSERT(CHECK_BTIM_UPDATE_MODE(UpdateMode));

    T14_PTR->CTL2.bits.TXUDEVT = (uint32_t)UpdateMode;
}

/**
 * @brief 配置更新使能
 * @param State:
 *          true   使能更新
 *          false   禁止更新
 * @retval 无
 */
KF_INLINE void BTimer_LL_SetUpdateEnabled(bool State)
{

    T14_PTR->CTL2.bits.TXUDEN = State ? 1U : 0U;
}

/**
 * @brief 配置Tim预分频值
 * @param  PreScaler : 预分频值,分频值为 pres
 * @retval void
 */
KF_INLINE void BTimer_LL_SetPrescaler(uint16_t PreScaler)
{
    T14_PTR->PRSC.bits.TXCKS = PreScaler;
}

/**
 * @brief 配置定时器的周期寄存器
 * @param  Period 周期值
 * @retval void
 */
KF_INLINE void BTimer_LL_SetPeriod(uint16_t Period)
{
    T14_PTR->PPX.bits.PPX = Period;
}

/**
 * @brief 设置基础定时器中断状态
 *
 * @param IntIndex 中断类型 \n
 *              BTIM_INT_UPDATE_EVENT -- Tx更新事件 \n
 *              BTIM_INT_TRIG_EVENT -- Tx触发事件 \n
 *              BTIM_INT_OVERFLOW -- Tx计数溢出中断
 * @param EnableSta 使能状态 \n
 *              true -- 使能中断 \n
 *              false -- 不使能中断
 * @retval void
 */
KF_INLINE void BTimer_LL_SetIntrEnabled(Btimer_Interrupt_t IntIndex, bool EnableSta)
{
    KF_BTIM_ASSERT((CHECK_BTIM_INT(IntIndex)));

    /* PRQA S 3473 1 #KQR003473 */
    REG_BITS_WRITE(T14_PTR->DIER.reg, 0x1UL << (uint32_t)IntIndex, (EnableSta ? 1UL : 0UL) << (uint32_t)IntIndex);
}

/**
 * @brief 获取基础定时器中断状态
 *
 * @param IntIndex 中断类型 \n
 *              BTIM_INT_UPDATE_EVENT -- Tx更新事件 \n
 *              BTIM_INT_TRIG_EVENT -- Tx触发事件 \n
 *              BTIM_INT_OVERFLOW -- Tx计数溢出中断
 * @retval bool 中断状态 \n
 *              true -- 产生中断标志 \n
 *              false -- 未产生中断标志
 */
KF_INLINE bool BTimer_LL_GetIntrFlag(Btimer_Interrupt_t IntIndex)
{
    KF_BTIM_ASSERT(CHECK_BTIM_INT(IntIndex));

    /* PRQA S 3469 1 #KQR003469 */
    return ((REG_BITS_READ(T14_PTR->SR.reg, 0x1UL << (uint32_t)IntIndex, (uint32_t)IntIndex)) != 0U);
}

/**
 * @brief 清除基础定时中断标志
 *
 * @param IntIndex 中断类型 \n
 *              BTIM_INT_UPDATE_EVENT -- Tx更新事件 \n
 *              BTIM_INT_TRIG_EVENT -- Tx触发事件 \n
 *              BTIM_INT_OVERFLOW -- Tx计数溢出中断
 * @retval void
 */
KF_INLINE void BTimer_LL_ClearIntrFlag(Btimer_Interrupt_t IntIndex)
{
    KF_BTIM_ASSERT(CHECK_BTIM_INT(IntIndex));

    /* PRQA S 3473 ++ #KQR003473 */
    REG_BIT_SET(T14_PTR->SRIC.reg, 0x1UL << (uint32_t)IntIndex);
    NOP();
    NOP();
    NOP();
    NOP();
    REG_BIT_CLR(T14_PTR->SRIC.reg, 0x1UL << (uint32_t)IntIndex);
    /* PRQA S 3473 -- #KQR003473 */
}

/**
 * @brief 设置DMA请求使能
 *
 * @param DmaTrig DMA请求类型 \n
 *              BTIM_DMA_UPDATE_EVENT -- 更新事件的 DMA \n
 *              BTIM_DMA_TRIG_EVENT -- 触发事件的 DMA
 * @param EnableSta 使能状态 \n
 *              true -- 使能事件请求DMA \n
 *              false -- 不使能事件请求DMA
 * @retval void
 */
KF_INLINE void BTimer_LL_SetRequestDmaEnabled(Btimer_DmaTrigger_t DmaTrig, bool EnableSta)
{
    KF_BTIM_ASSERT((CHECK_BTIM_DMA(DmaTrig)));

    /* PRQA S 3473 1 #KQR003473 */
    REG_BITS_WRITE(T14_PTR->DIER.reg, 0x1UL << (uint32_t)DmaTrig, (EnableSta ? 1UL : 0UL) << (uint32_t)DmaTrig);
}

/**
 * @brief 获取DMA请求标志
 *
 * @param DmaTrig DMA请求类型 \n
 *              BTIM_DMA_UPDATE_EVENT -- 更新事件的 DMA \n
 *              BTIM_DMA_TRIG_EVENT -- 触发事件的 DMA
 * @retval bool DMA请求状态 \n
 *              true -- 已产生事件请求DMA标志 \n
 *              false -- 未产生事件请求DMA标志
 */
KF_INLINE bool BTimer_LL_GetRequestDmaFlag(Btimer_DmaTrigger_t DmaTrig)
{
    uint32_t flag = (uint32_t)BTIM_DMA_UPDATE_EVENT + (uint32_t)BTIM_DMA_TRIG_EVENT - (uint32_t)DmaTrig;

    KF_BTIM_ASSERT((CHECK_BTIM_DMA(DmaTrig)));

    /* PRQA S 3469 1 #KQR003469 */
    return ((REG_BITS_READ(T14_PTR->SR.reg, 0x1UL << (uint32_t)flag, (uint32_t)flag)) != 0U);
}

/**
 * @brief 获取基础定时器中断状态
 *
 * @param IntIndex 中断类型 \n
 *              BTIM_INT_UPDATE_EVENT -- Tx更新事件 \n
 *              BTIM_INT_TRIG_EVENT -- Tx触发事件 \n
 *              BTIM_INT_OVERFLOW -- Tx计数溢出中断
 * @retval bool 中断状态 \n
 *              true -- 产生中断标志，且已使能 \n
 *              false -- 未产生中断标志，且已使能
 */
KF_INLINE bool BTimer_LL_GetIntrState(Btimer_Interrupt_t IntIndex)
{
    KF_BTIM_ASSERT(CHECK_BTIM_INT(IntIndex));

    /* PRQA S 3469 ++ #KQR003469 */
    bool flag = (0U != REG_BITS_READ(T14_PTR->SR.reg, (1UL << (uint32_t)IntIndex), (uint32_t)IntIndex)) ? true : false;
    bool state =
        (0U != REG_BITS_READ(T14_PTR->DIER.reg, (1UL << (uint32_t)IntIndex), (uint32_t)IntIndex)) ? true : false;
    /* PRQA S 3469 -- #KQR003469 */

    return flag && state;
}

#ifdef __cplusplus
}
#endif /*End of __cplusplus*/
#endif /*End of KF32A158SF_DRV_BTIMER_H*/
/* EOF */
