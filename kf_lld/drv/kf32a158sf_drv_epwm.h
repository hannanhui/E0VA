/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name        : kf32a158sf_drv_epwm.h
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
#ifndef KF32A158SF_DRV_EPWM_H
#define KF32A158SF_DRV_EPWM_H

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
#include "kf32a158sf_reg_epwm.h"

#ifdef KF_DRV_EPWM_ASSERT
#include "dev_assert.h"
#define KF_EPWM_ASSERT(x) KF_DEV_ASSERT(x)
#else
#define KF_EPWM_ASSERT(x) ((void)0U)
#endif

/******************************************************************************
 *                      Macro or Inline
 ******************************************************************************/

/******************************************************************************
 *                      Type definitions
 ******************************************************************************/

/** EPWM 同步事件输出时刻 */
typedef enum
{
    /**  EPWMxSYNCI 以及 SWFSYNC */
    EPWM_SYNCI_AND_SWFSYNC = 0x0U,
    /** 计数值等于 0 脉冲 */
    EPWM_TX_COUNT_EQU_ZERO = 0x1U,
    /** 计数值等于 EPWMx_RB 脉冲 */
    EPWM_TX_COUNT_EQU_RB = 0x2U,
    /** 禁止 EPWMxSYNCO 输出 */
    EPWM_DISABLE_SYNCO = 0x3U,
} Epwm_SyncEvent_t;
#define CHECK_SYNC_EVENT(EVENT) ((uint32_t)(EVENT) <= 0x3U)

/** EPWM 更新方式 */
typedef enum
{
    /** 周期更新 */
    EPWM_UPDATE_PERIODIC = 0x0U,
    /** 立即更新 */
    EPWM_UPDATE_NOW = 0x1U,
} Epwm_UpdateMode_t;
#define CHECK_UPDATE_MODE(MODE) ((uint32_t)(MODE) <= 0x1U)

/** EPWM 计数模式 */
typedef enum
{
    /** 向下计数,下溢时产生中断标志 */
    EPWM_COUNT_DOWN_UF = 0x0U,
    /** 向上计数,上溢时产生中断标志  \n 初始化默认向上计数 */
    EPWM_COUNT_UP_OF = 0x4U,
    /**  向上-向下计数,上溢时产生中断标志 */
    EPWM_COUNT_UP_DOWN_OF = 0x5U,
    /** 向上-向下计数,下溢时产生中断标志 */
    EPWM_COUNT_UP_DOWN_UF = 0x6U,
    /** 向上-向下计数,上溢和下溢时都产生中断标志 */
    EPWM_COUNT_UP_DOWN_OUF = 0x7U,
} Epwm_CountMode_t;
#define CHECK_EPWM_COUNT_MODE(SEL)                                                                                     \
    (((SEL) == EPWM_COUNT_DOWN_UF) || ((SEL) == EPWM_COUNT_UP_OF) || ((SEL) == EPWM_COUNT_UP_DOWN_OF) ||               \
     ((SEL) == EPWM_COUNT_UP_DOWN_UF) || ((SEL) == EPWM_COUNT_UP_DOWN_OUF))

/** EPWM 工作时钟 */
typedef enum
{
    /** 选择系统时钟作为EPWM工作时钟 */
    EPWM_CLK_SCLK = 0x0U,
    /** 选择高频外设作为EPWM工作时钟 */
    EPWM_CLK_HFCLK = 0x1U,
} Epwm_Clock_t;
#define CHECK_EPWM_CLOCK(CLK) ((uint32_t)(CLK) <= (uint32_t)EPWM_CLK_HFCLK)

/** EPWM 定时器工作模式 */
typedef enum
{
    /** 定时器模式 */
    EPWM_TIMING_MODE = 0x0U,
    /** 计数模式 */
    EPWM_COUNT_MODE = 0x1U,
} Epwm_TimerWorkMode_t;
#define CHECK_EPWM_TIMER_WORK_MODE(MODE) ((uint32_t)(MODE) <= (uint32_t)EPWM_COUNT_MODE)

/** EPWM 输出路径 */
typedef enum
{
    /** EPWM A路输出 */
    EPWM_OUTPUT_A = 0x0U,
    /** EPWM B路输出 */
    EPWM_OUTPUT_B,
    /** EPWM C路输出 */
    EPWM_OUTPUT_C,
    /** EPWM D路输出 */
    EPWM_OUTPUT_D,
} Epwm_Output_t;
#define CHECK_EPWM_OUTPUT(OUTPUT)     ((EPWM_OUTPUT_A == (OUTPUT)) || (EPWM_OUTPUT_B == (OUTPUT)))
#define CHECK_EPWM_ALL_OUTPUT(OUTPUT) ((uint32_t)(OUTPUT) <= (uint32_t)EPWM_OUTPUT_D)
/** EPWM 输出电平模式,适用于强制输出和正常输出两种模式.对于连续强制输出,使用 EPWM_OUTPUT_LEVEL_FORBIDDEN */
typedef enum
{
    /** 对于强制输出:表示无动作,保持电平不变； \n
     *  对于正常输出:表示不触发该事件 */
    EPWM_OUTPUT_LEVEL_NONE = 0x0U,
    /** 输出低电平 */
    EPWM_OUTPUT_LEVEL_LOW = 0x01U,
    /** 输出高电平 */
    EPWM_OUTPUT_LEVEL_HIGH = 0x02U,
    /** 输出时,翻转电平 */
    EPWM_OUTPUT_LEVEL_TOGGLE = 0x03U,
    /** 仅针对连续强制输出使用,表示禁止连续输出 */
    EPWM_OUTPUT_LEVEL_FORBIDDEN = 0x03U,
} Epwm_OutputLevel_t;
#define CHECK_EPWM_OUTPUT_LEVEL(LEVEL) ((uint32_t)(LEVEL) <= (uint32_t)EPWM_OUTPUT_LEVEL_TOGGLE)

/** EPWM 输出事件 */
typedef enum
{
    /** Tx计数值等于0 */
    EPWM_OUTPUT_TX_EQU_ZERO = 0x0U,
    /** Tx计数值等于period */
    EPWM_OUTPUT_TX_EQU_PERIOD,
    /** Tx计数值等于RA,且计数方向向上 */
    EPWM_OUTPUT_TX_EQU_RA_COUNT_UP,
    /** Tx计数值等于RA,且计数方向向下 */
    EPWM_OUTPUT_TX_EQU_RA_COUNT_DOWN,
    /** Tx计数值等于RB,且计数方向向上 */
    EPWM_OUTPUT_TX_EQU_RB_COUNT_UP,
    /** Tx计数值等于RB,且计数方向向下 */
    EPWM_OUTPUT_TX_EQU_RB_COUNT_DOWN,
} Epwm_OutputEvent_t;
#define CHECK_EPWM_OUTPUT_EVENT(EVENT) ((uint32_t)(EVENT) <= (uint32_t)EPWM_OUTPUT_TX_EQU_RB_COUNT_DOWN)

/** EPWM 死区输入 */
typedef enum
{
    /** 波形发生模块的A路输出作为上升沿,下降沿的输入 */
    EPWM_DEAD_IN_A_RISE_A_FALL = 0x0U,
    /** 波形发生模块的B路输出作为上升沿输入,A路输出作为下降沿输入 */
    EPWM_DEAD_IN_B_RISE_A_FALL,
    /** 波形发生模块的A路输出作为上升沿输入,B路输出作为下降沿输入 */
    EPWM_DEAD_IN_A_RISE_B_FALL,
    /** 波形发生模块的B路输出作为上升沿,下降沿的输入 */
    EPWM_DEAD_IN_B_RISE_B_FALL,
} Epwm_DeadInput_t;
#define CHECK_EPWM_DEAD_IN(SEL) ((uint32_t)(SEL) <= (uint32_t)EPWM_DEAD_IN_B_RISE_B_FALL)

/** EPWM 死区输出极性 */
typedef enum
{
    /** 波形发生模块的A,B路输出都不翻转 */
    EPWM_DEAD_A_NONE_B_NONE = 0x0U,
    /** 波形发生模块的A路翻转,B路输出不翻转 */
    EPWM_DEAD_A_TOGGLE_B_NONE,
    /** 波形发生模块的A路不翻转,B路输出翻转 */
    EPWM_DEAD_A_NONE_B_TOGGLE,
    /** 波形发生模块的A,B路输出都翻转 */
    EPWM_DEAD_A_TOGGLE_B_TOGGLE,
} Epwm_DeadPolarity_t;
#define CHECK_EPWM_DEAD_POLAR(SEL) ((uint32_t)(SEL) <= (uint32_t)EPWM_DEAD_A_TOGGLE_B_TOGGLE)

/* PRQA S 0779 ++ #KQR000779 */
/** EPWM 死区输出选择 */
typedef enum
{
    /** 上升/下降沿死区模块都被旁路 */
    EPWM_DEAD_OUT_RISE_PASS_FALL_PASS = 0x0U,
    /** 上升沿死区模块被旁路,下降沿死区模块使能 */
    EPWM_DEAD_OUT_RISE_PASS_FALL_ENABLE,
    /** 下降沿死区模块被旁路,上升沿死区模块使能 */
    EPWM_DEAD_OUT_RISE_ENABLE_FALL_PASS,
    /** 上升/下降沿死区模块都使能 */
    EPWM_DEAD_OUT_RISE_ENABLE_FALL_ENABLE,
} Epwm_DeadOutput_t;
#define CHECK_EPWM_DEAD_OUTPUT(SEL) ((uint32_t)(SEL) <= (uint32_t)EPWM_DEAD_OUT_RISE_ENABLE_FALL_ENABLE)
/* PRQA S 0779 -- #KQR000779 */

/** 检查PCLK频率设置 */
#define CHECK_EPWM_PCLK_FRQ(FRQ) (((uint32_t)(FRQ) < 0x8U && (uint32_t)(FRQ) > 0x0U))

/** 检查 PCLK 占空比 */
#define CHECK_EPWM_PCLK_DUTY(DUTY) ((uint32_t)(DUTY) < 0x7U)

/** 检查斩波第一个脉冲宽度 */
#define CHECK_EPWM_WIDTH_CHOPPER(WIDTH) (((uint32_t)(WIDTH) <= 0xFU && (uint32_t)(WIDTH) > 0x0U))

/** EPWM 自动关断输出电平 */
typedef enum
{
    /** 关断时,输出为低电平 */
    EPWM_SHUTDOWN_LEVEL_LOW = 0x0U,
    /** 关断时,输出为高电平 */
    EPWM_SHUTDOWN_LEVEL_HIGH = 0x1U,
    /** 关断时,输出为高阻态 */
    EPWM_SHUTDOWN_LEVEL_HI_Z = 0x3U,
} Epwm_ShutdownLevel_t;
/** 检查关断时,输出电平状态 */
#define CHECK_EPWM_SHUTDOWN_LEVEL(LEVEL) ((uint32_t)(LEVEL) <= (uint32_t)EPWM_SHUTDOWN_LEVEL_HI_Z)

/** EPWM 自动关断源 */
typedef enum
{
    /** 禁止自动关断 */
    EPWM_SHUTDOWN_FORBIDDEN = 0x0U,
    /** CLKIF 振荡器模块错误中断 */
    EPWM_SHUTDOWN_SOURCE_CLKIF = 0x3U,
    /** TZ1 输入高电平 */
    EPWM_SHUTDOWN_SOURCE_TZ1 = 0x4U,
    /** TZ2 输入高电平 */
    EPWM_SHUTDOWN_SOURCE_TZ2 = 0x5U,
    /** TZ3 输入高电平 */
    EPWM_SHUTDOWN_SOURCE_TZ3 = 0x6U,
    /** TZ4 输入高电平 */
    EPWM_SHUTDOWN_SOURCE_TZ4 = 0x7U,
    /** CMP1 比较器 1 的输出作为关断源 */
    EPWM_SHUTDOWN_SOURCE_CMP1 = 0x8U,
    /** CMP2 比较器 2 的输出作为关断源 */
    EPWM_SHUTDOWN_SOURCE_CMP2 = 0x9U,
    /** CMP3 比较器 3 的输出作为关断源 */
    EPWM_SHUTDOWN_SOURCE_CMP3 = 0xAU,
    /** CMP4 比较器 4 的输出作为关断源 */
    EPWM_SHUTDOWN_SOURCE_CMP4 = 0xBU,
} Epwm_ShutdownSource_t;
/** 检查自动关断源 */
#define CHECK_EPWM_SHUTDOWN_SOURCE(SOURCE) ((uint32_t)(SOURCE) <= (uint32_t)EPWM_SHUTDOWN_SOURCE_CMP4)

/** EPWM AD事件触发模式 */
typedef enum
{
    /** 在任意计数方向上都可触发AD */
    EPWM_EVENT_TRIGGER_BOTH = 0x0U,
    /** 在计数方向向上的时候触发AD */
    EPWM_EVENT_TRIGGER_COUNT_UP = 0x1U,
    /** 在计数方向向下的时候触发AD */
    EPWM_EVENT_TRIGGER_COUNT_DOWN = 0x3U,
} Epwm_EventTriggerMode_t;
/** 检查AD事件触发模式 */
#define CHECK_EPWM_EVENT_TRIGGER(SEL) ((uint32_t)(SEL) <= (uint32_t)EPWM_EVENT_TRIGGER_COUNT_DOWN)

/** EPWM 中断,DMA触发事件 */
typedef enum
{
    /** Tx触发AD事件0中断使能位 */
    EPWM_INDEX_TRIGGER_EVENT_ZERO = 0x0U,
    /** Tx触发AD事件1中断使能位 */
    EPWM_INDEX_TRIGGER_EVENT_ONE,
    /** Tx关断事件中断使能位 */
    EPWM_INDEX_SHUTDOWN_EVENT,
    /** Tx更新事件中断使能位 */
    EPWM_INDEX_UPDATE_EVENT,
    /** Tx计数溢出中断使能位 */
    EPWM_INDEX_OVERFLOW_EVENT,
    /** Tx计数值等于RB触发中断使能位 */
    EPWM_INDEX_TX_EQU_RB,
    /** Tx计数值等于RA触发中断使能位 */
    EPWM_INDEX_TX_EQU_RA,
    /** Tx计数值等于RC触发中断使能位 */
    EPWM_INDEX_TX_EQU_RC,
    /** Tx计数值等于RD触发中断使能位 */
    EPWM_INDEX_TX_EQU_RD,
    /** 捕捉事件中断使能位 */
    EPWM_INDEX_CAPTURE_EVENT,
} Epwm_Interrupt_t;

typedef enum
{
    /** Tx触发AD事件0中断使能位 */
    EPWM_INDEX_DMA_TRIGGER_EVENT_ZERO = 0x0U,
    /** Tx触发AD事件1中断使能位 */
    EPWM_INDEX_DMA_TRIGGER_EVENT_ONE,
    /** Tx关断事件中断使能位 */
    EPWM_INDEX_DMA_SHUTDOWN_EVENT,
    /** Tx更新事件中断使能位 */
    EPWM_INDEX_DMA_UPDATE_EVENT,
    /** Tx计数溢出中断使能位 */
    EPWM_INDEX_DMA_OVERFLOW_EVENT,
    /** Tx计数值等于RB触发中断使能位 */
    EPWM_INDEX_DMA_TX_EQU_RB,
    /** Tx计数值等于RA触发中断使能位 */
    EPWM_INDEX_DMA_TX_EQU_RA,
    /** Tx计数值等于RC触发中断使能位 */
    EPWM_INDEX_DMA_TX_EQU_RC,
    /** Tx计数值等于RD触发中断使能位 */
    EPWM_INDEX_DMA_TX_EQU_RD,
} EPWM_DmaTrigger_t;

/** 检查EPWM中断 */
#define CHECK_EPWM_INTERRUPT(INT) ((uint32_t)(INT) <= (uint32_t)EPWM_INDEX_CAPTURE_EVENT)
/** 检查DMA触发事件 */
#define CHECK_EPWM_DMA_TRIGGER(TRG) ((uint32_t)(TRG) <= (uint32_t)EPWM_INDEX_DMA_TX_EQU_RD)

/**触发 AD 事件类型*/
typedef enum
{
    /** 计数器计数值等于0时触发 */
    EPWM_TRIG_EVENT_TX_EQU_ZERO = 0x0U,
    /** 计数器计数值等于PPX值时触发 */
    EPWM_TRIG_EVENT_TX_EQU_PPX,
    /** 计数器计数值等于占空比A时触发 */
    EPWM_TRIG_EVENT_TX_EQU_RA,
    /** 计数器计数值等于占空比B时触发 */
    EPWM_TRIG_EVENT_TX_EQU_RB,
} Epwm_TrigEvent_t;
/**检查触发 AD 事件类型*/
#define CHECK_TRIG_EVENT(MODE) ((uint32_t)(MODE) <= (uint32_t)EPWM_TRIG_EVENT_TX_EQU_RB)

/** 检查触发AD事件周期 */
#define CHECK_TRIG_EVENT_PERIOD(PERIOD) ((PERIOD) <= 3U)

/******************************************************************************
 *                      Export Variables
 ******************************************************************************/

/******************************************************************************
 *                      Export Functions
 ******************************************************************************/

/**
 * @brief  设置EPWM定时器的计数值
 *
 * @param Epwmx: 指向EPWM内存结构的指针 \n
 *                  EPWM11_PTR ~ EPWM13_PTR, EPWM16_PTR, EPWM31_PTR ~ EPWM33_PTR, EPWM36_PTR
 * @param Count: 定时器计数值 \n
 *                  0x0 ~ 0xffffffff
 * @retval void
 */
KF_INLINE void Epwm_LL_WriteTimerCount(Epwm_RegisterMap_t *const Epwmx, uint32_t Count)
{
    KF_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH_ADDR(Epwmx));

    Epwmx->CNT = Count;
}

/**
 * @brief  获取EPWM定时器当前计数值
 *
 * @param Epwmx: 指向EPWM内存结构的指针 \n
 *                  EPWM11_PTR ~ EPWM13_PTR, EPWM16_PTR, EPWM31_PTR ~ EPWM33_PTR, EPWM36_PTR
 * @retval uint32_t: 定时器当前计数值
 */
KF_INLINE uint32_t Epwm_LL_ReadTimerCount(const Epwm_RegisterMap_t *const Epwmx)
{
    KF_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH_ADDR(Epwmx));

    return (Epwmx->CNT);
}

/**
 * @brief  设置EPWM定时器相移值
 *
 * @param Epwmx: 指向EPWM内存结构的指针 \n
 *                  EPWM11_PTR ~ EPWM13_PTR, EPWM16_PTR, EPWM31_PTR ~ EPWM33_PTR, EPWM36_PTR
 * @param Phase: 定时器相移值 \n
 *                  0x0 ~ 0xffffffff
 * @retval void
 */
KF_INLINE void Epwm_LL_WritePhaseValue(Epwm_RegisterMap_t *const Epwmx, uint32_t Phase)
{
    KF_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH_ADDR(Epwmx));

    Epwmx->PHS = Phase;
}

/**
 * @brief  读取EPWM定时器相移值
 *
 * @param Epwmx: 指向EPWM内存结构的指针 \n
 *                  EPWM11_PTR ~ EPWM13_PTR, EPWM16_PTR, EPWM31_PTR ~ EPWM33_PTR, EPWM36_PTR
 * @retval uint32_t: 定时器相移值
 */
KF_INLINE uint32_t Epwm_LL_ReadPhaseValue(const Epwm_RegisterMap_t *const Epwmx)
{
    KF_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH_ADDR(Epwmx));

    return (Epwmx->PHS);
}

/**
 * @brief  设置EPWM定时器周期值
 *
 * @param Epwmx: 指向EPWM内存结构的指针 \n
 *                  EPWM11_PTR ~ EPWM13_PTR, EPWM16_PTR, EPWM31_PTR ~ EPWM33_PTR, EPWM36_PTR
 * @param Period: 定时器周期值 \n
 *                  0x0 ~ 0xffffffff
 * @retval void
 */
KF_INLINE void Epwm_LL_WritePeriodValue(Epwm_RegisterMap_t *const Epwmx, uint32_t Period)
{
    KF_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH_ADDR(Epwmx));

    Epwmx->PPX = Period;
}

/**
 * @brief  读取EPWM定时器周期值
 *
 * @param Epwmx: 指向EPWM内存结构的指针 \n
 *                  EPWM11_PTR ~ EPWM13_PTR, EPWM16_PTR, EPWM31_PTR ~ EPWM33_PTR, EPWM36_PTR
 * @retval uint32_t: 定时器周期值
 */
KF_INLINE uint32_t Epwm_LL_ReadPeriodValue(const Epwm_RegisterMap_t *const Epwmx)
{
    KF_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH_ADDR(Epwmx));

    return (Epwmx->PPX);
}

/**
 * @brief  设置EPWM预分频系数
 *
 * @param Epwmx: 指向EPWM内存结构的指针 \n
 *                  EPWM11_PTR ~ EPWM13_PTR, EPWM16_PTR, EPWM31_PTR ~ EPWM33_PTR, EPWM36_PTR
 * @param Scaler: 预分频系数 \n
 *                  0x0 ~ 0xffffffff
 * @retval void
 */
KF_INLINE void Epwm_LL_WritePrescalerValue(Epwm_RegisterMap_t *const Epwmx, uint32_t Scaler)
{
    KF_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH_ADDR(Epwmx));

    Epwmx->PRSC = Scaler;
}

/**
 * @brief  读取EPWM定时器预分频系数
 *
 * @param Epwmx : 指向EPWM内存结构的指针 \n
 *                  EPWM11_PTR ~ EPWM13_PTR, EPWM16_PTR, EPWM31_PTR ~ EPWM33_PTR, EPWM36_PTR
 * @retval uint32_t: 预分频系数
 */
KF_INLINE uint32_t Epwm_LL_ReadPrescalerValue(const Epwm_RegisterMap_t *const Epwmx)
{
    KF_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH_ADDR(Epwmx));

    return (Epwmx->PRSC);
}

/**
 * @brief  设置响应上一级 EPWM 发送的的 LINK 请求状态
 *
 * @param Epwmx: 指向EPWM内存结构的指针 \n
 *                  EPWM11_PTR ~ EPWM13_PTR, EPWM16_PTR, EPWM31_PTR ~ EPWM33_PTR, EPWM36_PTR
 * @param EnableStatus: 使能状态 \n
 *                  true -- 使能 \n
 *                  false -- 失能
 * @retval void
 */
KF_INLINE void Epwm_LL_SetLinkToUpperLevel(Epwm_RegisterMap_t *const Epwmx, bool EnableStatus)
{
    KF_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH_ADDR(Epwmx));

    Epwmx->CTL.bits.BLINKEN = EnableStatus ? 1U : 0U;
}

/**
 * @brief  设置向下一级 PEWDT 发送 LINK 请求
 *
 * @param Epwmx: 指向EPWM内存结构的指针 \n
 *                  EPWM11_PTR ~ EPWM13_PTR, EPWM16_PTR, EPWM31_PTR ~ EPWM33_PTR, EPWM36_PTR
 * @param RequestStatus: 请求状态 \n
 *                  true -- 向下一级 PEWDT 发送 LINK 请求 \n
 *                  false -- 不发出 LINK请求
 * @retval void
 */
KF_INLINE void Epwm_LL_SetLinkRequest(Epwm_RegisterMap_t *const Epwmx, bool RequestStatus)
{
    KF_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH_ADDR(Epwmx));

    Epwmx->CTL.bits.LINKEN = RequestStatus ? 1U : 0U;
}

/**
 * @brief 配置同步信号触发更新使能
 *
 * @param Epwmx 指向EPWM内存结构的指针 \n
 *                  EPWM11_PTR ~ EPWM13_PTR, EPWM16_PTR, EPWM31_PTR ~ EPWM33_PTR, EPWM36_PTR
 * @param EnableStatus 使能状态 \n
 *                  true -- 使能 \n
 *                  false -- 失能
 * @retval void
 */
KF_INLINE void Epwm_LL_SetSyncSignalTriggerUpdate(Epwm_RegisterMap_t *const Epwmx, bool EnableStatus)
{
    KF_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH_ADDR(Epwmx));

    Epwmx->CTL.bits.UDSYNEN = EnableStatus ? 1U : 0U;
}

/**
 * @brief 设置捕捉功能使能
 *
 * @param Epwmx 指向EPWM内存结构的指针 \n
 *                  EPWM11_PTR ~ EPWM13_PTR, EPWM16_PTR, EPWM31_PTR ~ EPWM33_PTR, EPWM36_PTR
 * @param EnableStatus 使能状态 \n
 *                  true -- 使能 \n
 *                  false -- 失能
 * @retval void
 */
KF_INLINE void Epwm_LL_SetCaptureEnabled(Epwm_RegisterMap_t *const Epwmx, bool EnableStatus)
{
    KF_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH_ADDR(Epwmx));

    Epwmx->CTL.bits.CAPEN = EnableStatus ? 1U : 0U;
}

/**
 * @brief 选择捕捉事件
 *
 * @param Epwmx 指向EPWM内存结构的指针 \n
 *                  EPWM11_PTR ~ EPWM13_PTR, EPWM16_PTR, EPWM31_PTR ~ EPWM33_PTR, EPWM36_PTR
 * @param CaptureEvent 使能状态 \n
 *                  true -- 选择 EPWMxA 引脚进行捕捉 \n
 *                  false -- 选择捕捉专用引脚 CAPIN 进行捕捉
 * @retval void
 */
KF_INLINE void Epwm_LL_SelectCaptureEvent(Epwm_RegisterMap_t *const Epwmx, bool CaptureEvent)
{
    KF_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH_ADDR(Epwmx));

    Epwmx->CTL.bits.CAPSEL = CaptureEvent ? 1U : 0U;
}

/**
 * @brief  获取计数达到最大值状态
 *
 * @param Epwmx 指向EPWM内存结构的指针 \n
 *                  EPWM11_PTR ~ EPWM13_PTR, EPWM16_PTR, EPWM31_PTR ~ EPWM33_PTR, EPWM36_PTR
 * @retval bool 计数达到最大值状态 \n
 *                  true -- 计数值达到了最大值 \n
 *                  false -- 计数值未达到了最大值
 */
KF_INLINE bool Epwm_LL_GetCountValueMaxState(const Epwm_RegisterMap_t *const Epwmx)
{
    KF_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH_ADDR(Epwmx));

    return ((0U != Epwmx->CTL.bits.TXMAX) ? true : false);
}

/**
 * @brief  清除计数达到最大值状态
 *
 * @param Epwmx 指向EPWM内存结构的指针 \n
 *                  EPWM11_PTR ~ EPWM13_PTR, EPWM16_PTR, EPWM31_PTR ~ EPWM33_PTR, EPWM36_PTR
 * @retval void
 */
KF_INLINE void Epwm_LL_ClearCountValueMaxState(Epwm_RegisterMap_t *const Epwmx)
{
    KF_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH_ADDR(Epwmx));

    Epwmx->CTL.bits.TXMAX = 1U;
}

/**
 * @brief 设置相位方向 \n
 *        只有在向上向下计数模式下才起作用
 *
 * @param Epwmx 指向EPWM内存结构的指针 \n
 *                  EPWM11_PTR ~ EPWM13_PTR, EPWM16_PTR, EPWM31_PTR ~ EPWM33_PTR, EPWM36_PTR
 * @param Direction 相位方向 \n
 *                  true -- 同步事件触发后向上计数 \n
 *                  false -- 同步事件触发后向下计数
 * @retval void
 */
KF_INLINE void Epwm_LL_SetPhaseDirection(Epwm_RegisterMap_t *const Epwmx, bool Direction)
{
    KF_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH_ADDR(Epwmx));

    Epwmx->CTL.bits.PHSDIR = Direction ? 1U : 0U;
}

/**
 * @brief  获取当前相位方向
 *
 * @param Epwmx 指向EPWM内存结构的指针 \n
 *                  EPWM11_PTR ~ EPWM13_PTR, EPWM16_PTR, EPWM31_PTR ~ EPWM33_PTR, EPWM36_PTR
 * @retval bool 相位方向 \n
 *                  true -- 向上计数 \n
 *                  false -- 向下计数
 */
KF_INLINE bool Epwm_LL_GetPhaseDirection(const Epwm_RegisterMap_t *const Epwmx)
{
    KF_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH_ADDR(Epwmx));

    return ((0u != Epwmx->CTL.bits.PHSDIR) ? true : false);
}

/**
 * @brief  软件产生触发同步事件 \n
 *          该位由硬件自动清零
 *
 * @param Epwmx 指向EPWM内存结构的指针 \n
 *                  EPWM11_PTR ~ EPWM13_PTR, EPWM16_PTR, EPWM31_PTR ~ EPWM33_PTR, EPWM36_PTR
 * @retval void
 */
KF_INLINE void Epwm_LL_GenerateSoftwareSyncEvent(Epwm_RegisterMap_t *const Epwmx)
{
    KF_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH_ADDR(Epwmx));

    Epwmx->CTL.bits.SWFSYNC = 1U;
}

/**
 * @brief 选择输出同步事件类型
 *
 * @param Epwmx 指向EPWM内存结构的指针 \n
 *                  EPWM11_PTR ~ EPWM13_PTR, EPWM16_PTR, EPWM31_PTR ~ EPWM33_PTR, EPWM36_PTR
 * @param SelectedEvent 选择需要输出得同步事件类型 \n
 *                  EPWM_SYNCI_AND_SWFSYNC \n
 *                  EPWM_TX_COUNT_EQU_ZERO \n
 *                  EPWM_TX_COUNT_EQU_RB \n
 *                  EPWM_DISABLE_SYNCO
 * @retval void
 */
KF_INLINE void Epwm_LL_SelectSyncOutputEvent(Epwm_RegisterMap_t *const Epwmx, Epwm_SyncEvent_t SelectedEvent)
{
    KF_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH_ADDR(Epwmx));
    KF_EPWM_ASSERT(CHECK_SYNC_EVENT(SelectedEvent));

    Epwmx->CTL.bits.SYNCOSEL = (uint32_t)SelectedEvent;
}

/**
 * @brief 设置相位寄存器载入使能状态 \n
 *          即,设置同步事件发生后相移功能使能状态
 *
 * @param Epwmx 指向EPWM内存结构的指针 \n
 *                  EPWM11_PTR ~ EPWM13_PTR, EPWM16_PTR, EPWM31_PTR ~ EPWM33_PTR, EPWM36_PTR
 * @param EnableStatus 相位寄存器载入使能状态 \n
 *                  true -- 使能相位载入 \n
 *                  false -- 不使能相位载入
 * @retval void
 */
KF_INLINE void Epwm_LL_SetPhaseReloadEnabled(Epwm_RegisterMap_t *const Epwmx, bool EnableStatus)
{
    KF_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH_ADDR(Epwmx));

    Epwmx->CTL.bits.PHSEN = EnableStatus ? 1U : 0U;
}

/**
 * @brief 获取外部同步事件输入状态
 *
 * @param Epwmx 指向EPWM内存结构的指针 \n
 *                  EPWM11_PTR ~ EPWM13_PTR, EPWM16_PTR, EPWM31_PTR ~ EPWM33_PTR, EPWM36_PTR
 * @retval bool 外部同步事件输入状态 \n
 *                  true -- 有外部同步事件输入 \n
 *                  false -- 没有外部同步事件输入
 */
KF_INLINE bool Epwm_LL_GetSyncEventInputState(const Epwm_RegisterMap_t *const Epwmx)
{
    KF_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH_ADDR(Epwmx));

    return ((0u != Epwmx->CTL.bits.SYNCI) ? true : false);
}

/**
 * @brief 清除外部同步事件输入状态
 * @note 写0无效, 写1清除状态位
 *
 * @param Epwmx 指向EPWM内存结构的指针 \n
 *                  EPWM11_PTR ~ EPWM13_PTR, EPWM16_PTR, EPWM31_PTR ~ EPWM33_PTR, EPWM36_PTR
 * @retval void
 */
KF_INLINE void Epwm_LL_ClearSyncEventInputState(Epwm_RegisterMap_t *const Epwmx)
{
    KF_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH_ADDR(Epwmx));

    Epwmx->CTL.bits.SYNCI = 1U;
}

/**
 * @brief 产生更新事件 \n
 *          初始化定时器 Tx 的计数器并更新周期,占空比,预分频器,输出控制寄存器 \n
 *          该位硬件自动清零,不受 TXUDEN 控制
 *
 * @param Epwmx 指向EPWM内存结构的指针 \n
 *                  EPWM11_PTR ~ EPWM13_PTR, EPWM16_PTR, EPWM31_PTR ~ EPWM33_PTR, EPWM36_PTR
 * @retval void
 */
KF_INLINE void Epwm_LL_GenerateUpdateEvent(Epwm_RegisterMap_t *const Epwmx)
{
    KF_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH_ADDR(Epwmx));

    Epwmx->CTL.bits.TXUR = 1U;
}

/**
 * @brief 设置更新事件控制 \n
 *          在 TXUDEN=1 时有效
 *
 * @param Epwmx 指向EPWM内存结构的指针 \n
 *                  EPWM11_PTR ~ EPWM13_PTR, EPWM16_PTR, EPWM31_PTR ~ EPWM33_PTR, EPWM36_PTR
 * @param Mode 更新事件产生模式 \n
 *                  EPWM_UPDATE_PERIODIC -- 周期更新 \n
 *                  EPWM_UPDATE_NOW -- 立即更新
 * @retval void
 */
KF_INLINE void Epwm_LL_SetUpdateEventMode(Epwm_RegisterMap_t *const Epwmx, Epwm_UpdateMode_t Mode)
{
    KF_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH_ADDR(Epwmx));
    KF_EPWM_ASSERT(CHECK_UPDATE_MODE(Mode));

    Epwmx->CTL.bits.TXUDEVT = (uint32_t)Mode;
}

/**
 * @brief 设置更新使能
 *
 * @param Epwmx 指向EPWM内存结构的指针 \n
 *                  EPWM11_PTR ~ EPWM13_PTR, EPWM16_PTR, EPWM31_PTR ~ EPWM33_PTR, EPWM36_PTR
 * @param EnableStatus 更新使能状态 \n
 *                  true -- 使能更新 \n
 *                  false -- 不使能更新
 * @retval void
 */
KF_INLINE void Epwm_LL_SetUpdateEventEnabled(Epwm_RegisterMap_t *const Epwmx, bool EnableStatus)
{
    KF_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH_ADDR(Epwmx));

    Epwmx->CTL.bits.TXUDEN = EnableStatus ? 1U : 0U;
}

/**
 * @brief 选择 Tx 计数模式
 *
 * @param Epwmx 指向EPWM内存结构的指针 \n
 *                  EPWM11_PTR ~ EPWM13_PTR, EPWM16_PTR, EPWM31_PTR ~ EPWM33_PTR, EPWM36_PTR
 * @param CountMode 计数模式 \n
 *                  EPWM_COUNT_DOWN_UF -- 向下计数,下溢时产生中断标志  \n
 *                  EPWM_COUNT_UP_OF -- 向上计数,上溢时产生中断标志 \n
 *                  EPWM_COUNT_UP_DOWN_OF -- 向上-向下计数,上溢时产生中断标志 \n
 *                  EPWM_COUNT_UP_DOWN_UF -- 向上-向下计数,下溢时产生中断标志 \n
 *                  EPWM_COUNT_UP_DOWN_OUF -- 向上-向下计数,上溢和下溢时都产生中断标志
 * @retval void
 */
KF_INLINE void Epwm_LL_SelectCountMode(Epwm_RegisterMap_t *const Epwmx, Epwm_CountMode_t CountMode)
{
    KF_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH_ADDR(Epwmx));
    KF_EPWM_ASSERT(CHECK_EPWM_COUNT_MODE(CountMode));

    Epwmx->CTL.bits.TXCMS = (uint32_t)CountMode;
}

/**
 * @brief 获取 Tx 计数方向
 *
 * @param Epwmx 指向EPWM内存结构的指针 \n
 *                  EPWM11_PTR ~ EPWM13_PTR, EPWM16_PTR, EPWM31_PTR ~ EPWM33_PTR, EPWM36_PTR
 * @retval bool  计数方向 \n
 *                  true -- 当前计数方向为向上计数 \n
 *                  false -- 当前计数方向为向下计数
 */
KF_INLINE bool Epwm_LL_GetCountDirection(const Epwm_RegisterMap_t *const Epwmx)
{
    KF_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH_ADDR(Epwmx));

    return ((0U != Epwmx->CTL.bits.TXDIR) ? true : false);
}

/**
 * @brief 选择EPWM工作时钟
 *
 * @param Epwmx 指向EPWM内存结构的指针 \n
 *                  EPWM11_PTR ~ EPWM13_PTR, EPWM16_PTR, EPWM31_PTR ~ EPWM33_PTR, EPWM36_PTR
 * @param WorkClock EPWM工作时钟 \n
 *                  EPWM_CLK_SCLK -- 系统时钟 \n
 *                  EPWM_CLK_HFCLK -- 高频外设时钟 \n
 *                  EPWM_CLK_LFCLK -- 低频外设时钟
 * @retval void
 */
KF_INLINE void Epwm_LL_SelectClock(Epwm_RegisterMap_t *const Epwmx, Epwm_Clock_t WorkClock)
{
    KF_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH_ADDR(Epwmx));
    KF_EPWM_ASSERT(CHECK_EPWM_CLOCK(WorkClock));

    Epwmx->CTL.bits.TXCLK = (uint32_t)WorkClock;
}

/**
 * @brief Tx 外部触发脉冲输入同步控制位 \n
 *          仅计数模式有效
 *
 * @param Epwmx 指向EPWM内存结构的指针 \n
 *                  EPWM11_PTR ~ EPWM13_PTR, EPWM16_PTR, EPWM31_PTR ~ EPWM33_PTR, EPWM36_PTR
 * @param EnableStatus 同步使能状态 \n
 *                  true  -- 使能,外部触发脉冲与工作时钟同步后作为计数时钟 \n
 *                  false -- 不使能,外部触发脉冲作为计数时钟
 * @retval void
 */
KF_INLINE void Epwm_LL_SetExternalPulseSyncEnabled(Epwm_RegisterMap_t *const Epwmx, bool EnableStatus)
{
    KF_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH_ADDR(Epwmx));

    Epwmx->CTL.bits.TXSY = EnableStatus ? 1U : 0U;
}

/**
 * @brief Tx 门控使能
 *
 * @param Epwmx 指向EPWM内存结构的指针 \n
 *                  EPWM11_PTR ~ EPWM13_PTR, EPWM16_PTR, EPWM31_PTR ~ EPWM33_PTR, EPWM36_PTR
 * @param EnableStatus 门控使能状态 \n
 *                  true -- 使能 Tx 门控，门控信号为 EPWMx_CLK \n
 *                  false -- 禁止 Tx 门控
 * @retval void
 */
KF_INLINE void Epwm_LL_SetGatingEnabled(Epwm_RegisterMap_t *const Epwmx, bool EnableStatus)
{
    KF_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH_ADDR(Epwmx));

    Epwmx->CTL.bits.TXGATE = EnableStatus ? 1U : 0U;
}

/**
 * @brief 设置EPWM定时器工作模式
 *
 * @param Epwmx 指向EPWM内存结构的指针 \n
 *                  EPWM11_PTR ~ EPWM13_PTR, EPWM16_PTR, EPWM31_PTR ~ EPWM33_PTR, EPWM36_PTR
 * @param Mode 定时器工作模式 \n
 *                  EPWM_TIMING_MODE -- 定时器模式 \n
 *                  EPWM_COUNT_MODE -- 计数模式
 * @retval void
 */
KF_INLINE void Epwm_LL_SetTimerWorkMode(Epwm_RegisterMap_t *const Epwmx, Epwm_TimerWorkMode_t Mode)
{
    KF_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH_ADDR(Epwmx));
    KF_EPWM_ASSERT(CHECK_EPWM_TIMER_WORK_MODE(Mode));

    Epwmx->CTL.bits.TXCS = (uint32_t)Mode;
}

/**
 * @brief 设置EPWM模块使能状态
 *
 * @param Epwmx 指向EPWM内存结构的指针 \n
 *                  EPWM11_PTR ~ EPWM13_PTR, EPWM16_PTR, EPWM31_PTR ~ EPWM33_PTR, EPWM36_PTR
 * @param EnableStatus 模块使能状态 \n
 *                  true -- 使能 \n
 *                  false -- 不使能
 * @retval void
 */
KF_INLINE void Epwm_LL_SetEnabled(Epwm_RegisterMap_t *const Epwmx, bool EnableStatus)
{
    KF_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH_ADDR(Epwmx));

    Epwmx->CTL.bits.TXEN = EnableStatus ? 1U : 0U;
    Epwmx->CTL.bits.TXUR = 1U;
}

/**
 * @brief 设置EPWMxA输出AQ波形发生控制子模块寄存器锁状态
 *
 * @param Epwmx 指向EPWM内存结构的指针 \n
 *                  EPWM11_PTR ~ EPWM13_PTR, EPWM16_PTR, EPWM31_PTR ~ EPWM33_PTR, EPWM36_PTR
 * @param LockStatus 锁定状态 \n
 *                  true -- 禁止通道A输出AQ子模块寄存器写操作 \n
 *                  false -- 允许通道A输出AQ子模块寄存器写操作
 * @retval void
 */
KF_INLINE void Epwm_LL_SetAqLockA(Epwm_RegisterMap_t *const Epwmx, bool LockStatus)
{
    KF_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH_ADDR(Epwmx));

    Epwmx->CTL.bits.AQLOCKA = LockStatus ? 1U : 0U;
}

/**
 * @brief 设置EPWMxB输出AQ波形发生控制子模块寄存器锁状态
 *
 * @param Epwmx 指向EPWM内存结构的指针 \n
 *                  EPWM11_PTR ~ EPWM13_PTR, EPWM16_PTR, EPWM31_PTR ~ EPWM33_PTR, EPWM36_PTR
 * @param LockStatus 锁定状态 \n
 *                  true -- 禁止通道B输出AQ子模块寄存器写操作 \n
 *                  false -- 允许通道B输出AQ子模块寄存器写操作
 * @retval void
 */
KF_INLINE void Epwm_LL_SetAqLockB(Epwm_RegisterMap_t *const Epwmx, bool LockStatus)
{
    KF_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH_ADDR(Epwmx));

    Epwmx->CTL.bits.AQLOCKB = LockStatus ? 1U : 0U;
}

/**
 * @brief 设置DB死区控制子模块寄存器锁状态
 *
 * @param Epwmx 指向EPWM内存结构的指针 \n
 *                  EPWM11_PTR ~ EPWM13_PTR, EPWM16_PTR, EPWM31_PTR ~ EPWM33_PTR, EPWM36_PTR
 * @param LockStatus 锁定状态 \n
 *                  true -- 禁止DB子模块寄存器写操作 \n
 *                  false -- 允许DB子模块寄存器写操作
 * @retval void
 */
KF_INLINE void Epwm_LL_SetDbLock(Epwm_RegisterMap_t *const Epwmx, bool LockStatus)
{
    KF_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH_ADDR(Epwmx));

    Epwmx->CTL.bits.DBLOCK = LockStatus ? 1U : 0U;
}

/**
 * @brief 设置ET事件管理子模块寄存器锁状态
 *
 * @param Epwmx 指向EPWM内存结构的指针 \n
 *                  EPWM11_PTR ~ EPWM13_PTR, EPWM16_PTR, EPWM31_PTR ~ EPWM33_PTR, EPWM36_PTR
 * @param LockStatus 锁定状态 \n
 *                  true -- 禁止ET子模块寄存器写操作 \n
 *                  false -- 允许ET子模块寄存器写操作
 * @retval void
 */
KF_INLINE void Epwm_LL_SetEtLock(Epwm_RegisterMap_t *const Epwmx, bool LockStatus)
{
    KF_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH_ADDR(Epwmx));

    Epwmx->CTL.bits.ETLOCK = LockStatus ? 1U : 0U;
}

/**
 * @brief 设置 EPWM 占空比 \n 仅包括RA和RB两路
 *
 * @param Epwmx 指向EPWM内存结构的指针 \n
 *                  EPWM11_PTR ~ EPWM13_PTR, EPWM16_PTR, EPWM31_PTR ~ EPWM33_PTR, EPWM36_PTR
 * @param Output 需要设置的输出 \n
 *                  EPWM_OUTPUT_A -- EPWM的A路输出 \n
 *                  EPWM_OUTPUT_B -- EPWM的B路输出
 * @param Value 占空比值
 *                  0x0 ~ 0xffffffff
 * @retval void
 */
KF_INLINE void Epwm_LL_WriteDutyCycleValue(Epwm_RegisterMap_t *const Epwmx, Epwm_Output_t Output, uint32_t Value)
{
    KF_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH_ADDR(Epwmx));
    KF_EPWM_ASSERT(CHECK_EPWM_ALL_OUTPUT(Output));

    if (EPWM_OUTPUT_A == Output)
    {
        Epwmx->RA = Value;
    }
    else if (EPWM_OUTPUT_B == Output)
    {
        Epwmx->RB = Value;
    }
    else if (EPWM_OUTPUT_C == Output)
    {
        Epwmx->RC = Value;
    }
    else if (EPWM_OUTPUT_D == Output)
    {
        Epwmx->RD = Value;
    }
    else
    {
        /* do nothing */
    }
}

/**
 * @brief 设置 EPWM 单次强制输出使能状态 \n
 *                  写一后,产生一个计数周期的脉冲,然后该位硬件自动清零,且该位不需要等待更新信号
 *
 * @param Epwmx 指向EPWM内存结构的指针 \n
 *                  EPWM11_PTR ~ EPWM13_PTR, EPWM16_PTR, EPWM31_PTR ~ EPWM33_PTR, EPWM36_PTR
 * @param Output 需要设置的输出 \n
 *                  EPWM_OUTPUT_A -- EPWM的A路输出 \n
 *                  EPWM_OUTPUT_B -- EPWM的B路输出
 * @param EnableStatus 使能状态 \n
 *                  true -- 使能 \n
 *                  false -- 不使能
 * @retval void
 */
KF_INLINE void
Epwm_LL_SetOneShotForceOutputEnabled(Epwm_RegisterMap_t *const Epwmx, Epwm_Output_t Output, bool EnableStatus)
{
    KF_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH_ADDR(Epwmx));
    KF_EPWM_ASSERT(CHECK_EPWM_OUTPUT(Output));

    if (EPWM_OUTPUT_A == Output)
    {
        Epwmx->CTLA.bits.OTSFA = EnableStatus ? 1U : 0U;
    }
    else if (EPWM_OUTPUT_B == Output)
    {
        Epwmx->CTLB.bits.OTSFB = EnableStatus ? 1U : 0U;
    }
    else
    {
        /* do nothing */
    }
}

/**
 * @brief 设置 EPWM 单次强制输出电平
 *
 * @param Epwmx 指向EPWM内存结构的指针 \n
 *                  EPWM11_PTR ~ EPWM13_PTR, EPWM16_PTR, EPWM31_PTR ~ EPWM33_PTR, EPWM36_PTR
 * @param Output 需要设置的输出 \n
 *                  EPWM_OUTPUT_A -- EPWM的A路输出 \n
 *                  EPWM_OUTPUT_B -- EPWM的B路输出
 * @param Level 单次强制输出电平 \n
 *                  EPWM_OUTPUT_LEVEL_NONE -- 无动作 \n
 *                  EPWM_OUTPUT_LEVEL_LOW -- 输出低电平 \n
 *                  EPWM_OUTPUT_LEVEL_HIGH -- 输出高电平 \n
 *                  EPWM_OUTPUT_LEVEL_TOGGLE -- 翻转电平
 * @retval void
 */
KF_INLINE void
Epwm_LL_SetForceOutputSingle(Epwm_RegisterMap_t *const Epwmx, Epwm_Output_t Output, Epwm_OutputLevel_t Level)
{
    KF_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH_ADDR(Epwmx));
    KF_EPWM_ASSERT(CHECK_EPWM_OUTPUT(Output));
    KF_EPWM_ASSERT(CHECK_EPWM_OUTPUT_LEVEL(Level));

    if (EPWM_OUTPUT_A == Output)
    {
        Epwmx->CTLA.bits.ACTSFA = (uint32_t)Level;
    }
    else if (EPWM_OUTPUT_B == Output)
    {
        Epwmx->CTLB.bits.ACTSFB = (uint32_t)Level;
    }
    else
    {
        /* do nothing */
    }
}

/**
 * @brief 设置 EPWM 连续强制输出电平
 *
 * @param Epwmx 指向EPWM内存结构的指针 \n
 *                  EPWM11_PTR ~ EPWM13_PTR, EPWM16_PTR, EPWM31_PTR ~ EPWM33_PTR, EPWM36_PTR
 * @param Output 需要设置的输出 \n
 *                  EPWM_OUTPUT_A -- EPWM的A路输出 \n
 *                  EPWM_OUTPUT_B -- EPWM的B路输出
 * @param Level 连续强制输出电平 \n
 *                  EPWM_OUTPUT_LEVEL_NONE -- 无动作 \n
 *                  EPWM_OUTPUT_LEVEL_LOW -- 输出低电平 \n
 *                  EPWM_OUTPUT_LEVEL_HIGH -- 输出高电平 \n
 *                  EPWM_OUTPUT_LEVEL_FORBIDDEN -- 禁止连续强制输出
 * @retval void
 */
KF_INLINE void
Epwm_LL_SetForceOutputContinuous(Epwm_RegisterMap_t *const Epwmx, Epwm_Output_t Output, Epwm_OutputLevel_t Level)
{
    KF_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH_ADDR(Epwmx));
    KF_EPWM_ASSERT(CHECK_EPWM_OUTPUT(Output));
    KF_EPWM_ASSERT(CHECK_EPWM_OUTPUT_LEVEL(Level));

    if (EPWM_OUTPUT_A == Output)
    {
        Epwmx->CTLA.bits.CSFA = (uint32_t)Level;
    }
    else if (EPWM_OUTPUT_B == Output)
    {
        Epwmx->CTLB.bits.CSFB = (uint32_t)Level;
    }
    else
    {
        /* do nothing */
    }
}

/**
 * @brief 设置 EPWM 正常输出电平
 *
 * @param Epwmx 指向EPWM内存结构的指针 \n
 *                  EPWM11_PTR ~ EPWM13_PTR, EPWM16_PTR, EPWM31_PTR ~ EPWM33_PTR, EPWM36_PTR
 * @param Output 需要设置的输出 \n
 *                  EPWM_OUTPUT_A -- EPWM的A路输出 \n
 *                  EPWM_OUTPUT_B -- EPWM的B路输出
 * @param Level 正常输出电平 \n
 *                  EPWM_OUTPUT_LEVEL_NONE -- 不触发该事件 \n
 *                  EPWM_OUTPUT_LEVEL_LOW -- 输出低电平 \n
 *                  EPWM_OUTPUT_LEVEL_HIGH -- 输出高电平 \n
 *                  EPWM_OUTPUT_LEVEL_TOGGLE -- 翻转电平
 * @param Event EPWM 输出事件 \n
 *                  EPWM_OUTPUT_TX_EQU_ZERO -- Tx计数值等于0 \n
 *                  EPWM_OUTPUT_TX_EQU_PERIOD -- Tx计数值等于period \n
 *                  EPWM_OUTPUT_TX_EQU_RA_COUNT_UP -- Tx计数值等于RA,且计数方向向上 \n
 *                  EPWM_OUTPUT_TX_EQU_RA_COUNT_DOWN -- Tx计数值等于RA,且计数方向向下 \n
 *                  EPWM_OUTPUT_TX_EQU_RB_COUNT_UP -- Tx计数值等于RB,且计数方向向上 \n
 *                  EPWM_OUTPUT_TX_EQU_RB_COUNT_DOWN -- Tx计数值等于RB,且计数方向向下
 * @retval void
 */
KF_INLINE void Epwm_LL_SetOutput(
    Epwm_RegisterMap_t *const Epwmx, Epwm_Output_t Output, Epwm_OutputLevel_t Level, Epwm_OutputEvent_t Event)
{
    uint32_t Mask;

    KF_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH_ADDR(Epwmx));
    KF_EPWM_ASSERT(CHECK_EPWM_OUTPUT(Output));
    KF_EPWM_ASSERT(CHECK_EPWM_OUTPUT_LEVEL(Level));
    KF_EPWM_ASSERT(CHECK_EPWM_OUTPUT_EVENT(Event));

    Mask = 2U * (uint32_t)Event;
    if (EPWM_OUTPUT_A == Output)
    {
        /* PRQA S 3473 1 #KQR003473 */
        REG_BITS_WRITE(Epwmx->CTLA.reg, 0x3UL << Mask, (uint32_t)Level << Mask);
    }
    else if (EPWM_OUTPUT_B == Output)
    {
        /* PRQA S 3473 1 #KQR003473 */
        REG_BITS_WRITE(Epwmx->CTLB.reg, 0x3UL << Mask, (uint32_t)Level << Mask);
    }
    else
    {
        /* do nothing */
    }
}

/**
 * @brief 选择死区模块输入
 *
 * @param Epwmx 指向EPWM内存结构的指针 \n
 *                  EPWM11_PTR ~ EPWM13_PTR, EPWM16_PTR, EPWM31_PTR ~ EPWM33_PTR, EPWM36_PTR
 * @param DeadInput 死区模块输入 \n
 *                  EPWM_DEAD_IN_A_RISE_A_FALL -- 波形发生模块的A路输出作为上升沿,下降沿的输入 \n
 *                  EPWM_DEAD_IN_B_RISE_A_FALL -- 波形发生模块的B路输出作为上升沿输入,A路输出作为下降沿输入 \n
 *                  EPWM_DEAD_IN_A_RISE_B_FALL -- 波形发生模块的A路输出作为上升沿输入,B路输出作为下降沿输入 \n
 *                  EPWM_DEAD_IN_B_RISE_B_FALL -- 波形发生模块的B路输出作为上升沿,下降沿的输入
 * @retval void
 */
KF_INLINE void Epwm_LL_SetDeadZoneInput(Epwm_RegisterMap_t *const Epwmx, Epwm_DeadInput_t DeadInput)
{
    KF_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH_ADDR(Epwmx));
    KF_EPWM_ASSERT(CHECK_EPWM_DEAD_IN(DeadInput));

    Epwmx->DBCTL.bits.INMODE = (uint32_t)DeadInput;
}

/**
 * @brief 选择死区模块输入极性
 *
 * @param Epwmx 指向EPWM内存结构的指针 \n
 *                  EPWM11_PTR ~ EPWM13_PTR, EPWM16_PTR, EPWM31_PTR ~ EPWM33_PTR, EPWM36_PTR
 * @param DeadPolarity 死区模块输入极性 \n
 *                  EPWM_DEAD_A_NONE_B_NONE -- 波形发生模块的A,B路输出都不翻转 \n
 *                  EPWM_DEAD_A_TOGGLE_B_NONE -- 波形发生模块的A路翻转,B路输出不翻转 \n
 *                  EPWM_DEAD_A_NONE_B_TOGGLE -- 波形发生模块的A路不翻转,B路输出翻转 \n
 *                  EPWM_DEAD_A_TOGGLE_B_TOGGLE -- 波形发生模块的A,B路输出都翻转
 * @retval void
 */
KF_INLINE void Epwm_LL_SetDeadZonePolarity(Epwm_RegisterMap_t *const Epwmx, Epwm_DeadPolarity_t DeadPolarity)
{
    KF_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH_ADDR(Epwmx));
    KF_EPWM_ASSERT(CHECK_EPWM_DEAD_POLAR(DeadPolarity));

    Epwmx->DBCTL.bits.POLSEL = (uint32_t)DeadPolarity;
}

/**
 * @brief 选择死区模块输出
 *
 * @param Epwmx 指向EPWM内存结构的指针 \n
 *                  EPWM11_PTR ~ EPWM13_PTR, EPWM16_PTR, EPWM31_PTR ~ EPWM33_PTR, EPWM36_PTR
 * @param DeadInput 死区模块输出模式 \n
 *                  EPWM_DEAD_OUT_RISE_PASS_FALL_PASS -- 上升/下降沿死区模块都被旁路 \n
 *                  EPWM_DEAD_OUT_RISE_PASS_FALL_ENABLE -- 上升沿死区模块被旁路,下降沿死区模块使能 \n
 *                  EPWM_DEAD_OUT_RISE_ENABLE_FALL_PASS -- 下降沿死区模块被旁路,上升沿死区模块使能 \n
 *                  EPWM_DEAD_OUT_RISE_ENABLE_FALL_ENABLE -- 上升/下降沿死区模块都使能
 * @retval void
 */
KF_INLINE void Epwm_LL_SetDeadZoneOutput(Epwm_RegisterMap_t *const Epwmx, Epwm_DeadOutput_t DeadOutput)
{
    KF_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH_ADDR(Epwmx));
    KF_EPWM_ASSERT(CHECK_EPWM_DEAD_OUTPUT(DeadOutput));

    Epwmx->DBCTL.bits.OUTMODE = (uint32_t)DeadOutput;
}

/**
 * @brief 设置上升沿死区延时时间
 *
 * @param Epwmx 指向EPWM内存结构的指针 \n
 *                  EPWM11_PTR ~ EPWM13_PTR, EPWM16_PTR, EPWM31_PTR ~ EPWM33_PTR, EPWM36_PTR
 * @param DelayTime 死区延时时间 \n
 *                  0x0 ~ 0xffffff
 * @retval void
 */
KF_INLINE void Epwm_LL_SetDeadDelayTimeRise(Epwm_RegisterMap_t *const Epwmx, uint16_t DelayTime)
{
    KF_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH_ADDR(Epwmx));

    Epwmx->DBT.bits.RDBT = DelayTime;
}

/**
 * @brief 设置下降沿死区延时时间
 *
 * @param Epwmx 指向EPWM内存结构的指针 \n
 *                  EPWM11_PTR ~ EPWM13_PTR, EPWM16_PTR, EPWM31_PTR ~ EPWM33_PTR, EPWM36_PTR
 * @param DelayTime 死区延时时间 \n
 *                  0x0 ~ 0xffffff
 * @retval void
 */
KF_INLINE void Epwm_LL_SetDeadDelayTimeFall(Epwm_RegisterMap_t *const Epwmx, uint16_t DelayTime)
{
    KF_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH_ADDR(Epwmx));

    Epwmx->DBT.bits.FDBT = DelayTime;
}

/**
 * @brief 设置 EPWM 自动重启使能状态
 *
 * @param Epwmx 指向EPWM内存结构的指针 \n
 *                  EPWM11_PTR ~ EPWM13_PTR, EPWM16_PTR, EPWM31_PTR ~ EPWM33_PTR, EPWM36_PTR
 * @param EnableStatus 使能状态 \n
 *                  true -- 使能自动重启 \n
 *                  false -- 不使能自动重启
 * @retval void
 */
KF_INLINE void Epwm_LL_SetAutoRestartEnabled(Epwm_RegisterMap_t *const Epwmx, bool EnableStatus)
{
    KF_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH_ADDR(Epwmx));

    Epwmx->PXASCTL.bits.PXRSEN = EnableStatus ? 1U : 0U;
}

/**
 * @brief 设置自动关断时,输出引脚状态
 *
 * @param Epwmx 指向EPWM内存结构的指针 \n
 *                  EPWM11_PTR ~ EPWM13_PTR, EPWM16_PTR, EPWM31_PTR ~ EPWM33_PTR, EPWM36_PTR
 * @param Output 需要设置的输出 \n
 *                  EPWM_OUTPUT_A -- EPWM的A路输出 \n
 *                  EPWM_OUTPUT_B -- EPWM的B路输出
 * @param ShutdownLevel 关断时的引脚状态 \n
 *                  EPWM_SHUTDOWN_LEVEL_LOW -- 输出为低电平 \n
 *                  EPWM_SHUTDOWN_LEVEL_HIGH -- 输出为高电平 \n
 *                  EPWM_SHUTDOWN_LEVEL_HI_Z -- 输出为高阻态
 * @retval void
 */
KF_INLINE void
Epwm_LL_SetShutdownOutput(Epwm_RegisterMap_t *const Epwmx, Epwm_Output_t Output, Epwm_ShutdownLevel_t ShutdownLevel)
{
    KF_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH_ADDR(Epwmx));
    KF_EPWM_ASSERT(CHECK_EPWM_OUTPUT(Output));
    KF_EPWM_ASSERT(CHECK_EPWM_SHUTDOWN_LEVEL(ShutdownLevel));

    if (EPWM_OUTPUT_A == Output)
    {
        Epwmx->PXASCTL.bits.PXSSA = (uint32_t)ShutdownLevel;
    }
    else if (EPWM_OUTPUT_B == Output)
    {
        Epwmx->PXASCTL.bits.PXSSB = (uint32_t)ShutdownLevel;
    }
    else
    {
        /* do nothing */
    }
}

/**
 * @brief 获取自动关断状态
 *
 * @param Epwmx 指向EPWM内存结构的指针 \n
 *                  EPWM11_PTR ~ EPWM13_PTR, EPWM16_PTR, EPWM31_PTR ~ EPWM33_PTR, EPWM36_PTR
 * @retval bool 自动关断状态 \n
 *                  true -- 发生了关闭事件 \n
 *                  false -- EPWMx 正常工作
 */
KF_INLINE bool Epwm_LL_GetShutdownState(const Epwm_RegisterMap_t *const Epwmx)
{
    KF_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH_ADDR(Epwmx));

    return ((0u != Epwmx->PXASCTL.bits.PXASE) ? true : false);
}

/**
 * @brief 设置自动关断触发源
 *
 * @param Epwmx 指向EPWM内存结构的指针 \n
 *                  EPWM11_PTR ~ EPWM13_PTR, EPWM16_PTR, EPWM31_PTR ~ EPWM33_PTR, EPWM36_PTR
 * @param Source 自动关断触发源 \n
 *                  EPWM_SHUTDOWN_FORBIDDEN -- 禁止自动关断 \n
 *                  EPWM_SHUTDOWN_SOURCE_TZ1 -- TZ1输入高电平  \n
 *                  EPWM_SHUTDOWN_SOURCE_TZ2 -- TZ2输入高电平 \n
 *                  EPWM_SHUTDOWN_SOURCE_TZ3 -- TZ3输入高电平 \n
 *                  EPWM_SHUTDOWN_SOURCE_TZ4 -- TZ4输入高电平 \n
 *                  EPWM_SHUTDOWN_SOURCE_CLK_ERR -- 振荡器模块错误中断 \n
 * @retval void
 */
KF_INLINE void Epwm_LL_SetShutdownSource(Epwm_RegisterMap_t *const Epwmx, Epwm_ShutdownSource_t Source)
{
    KF_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH_ADDR(Epwmx));
    KF_EPWM_ASSERT(CHECK_EPWM_SHUTDOWN_SOURCE(Source));

    Epwmx->PXASCTL.bits.PXASS = (uint32_t)Source;
}

/**
 * @brief 获取自动关断触发源
 *
 * @param Epwmx 指向EPWM内存结构的指针 \n
 *                  EPWM11_PTR ~ EPWM13_PTR, EPWM16_PTR, EPWM31_PTR ~ EPWM33_PTR, EPWM36_PTR
 * @retval uint32_t 自动关断触发源
 */
KF_INLINE uint32_t Epwm_LL_GetShutdownSource(const Epwm_RegisterMap_t *const Epwmx)
{
    KF_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH_ADDR(Epwmx));

    return (uint32_t)(Epwmx->PXASCTL.bits.PXASS);
}

/**
 * @brief 设置事件触发模式
 *
 * @param Epwmx 指向EPWM内存结构的指针 \n
 *                  EPWM11_PTR ~ EPWM13_PTR, EPWM16_PTR, EPWM31_PTR ~ EPWM33_PTR, EPWM36_PTR
 * @param Event 事件序号 \n
 *                  false -- 事件0 \n
 *                  true -- 事件1
 * @param Mode 触发模式 \n
 *                  EPWM_EVENT_TRIGGER_BOTH -- 在任意计数方向上都可触发AD \n
 *                  EPWM_EVENT_TRIGGER_COUNT_UP -- 在计数方向向上的时候触发AD \n
 *                  EPWM_EVENT_TRIGGER_COUNT_DOWN -- 在计数方向向下的时候触发AD
 * @retval void
 */
KF_INLINE void
Epwm_LL_SelectTriggerModeOfEvent(Epwm_RegisterMap_t *const Epwmx, bool Event, Epwm_EventTriggerMode_t Mode)
{
    KF_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH_ADDR(Epwmx));

    KF_EPWM_ASSERT(CHECK_EPWM_EVENT_TRIGGER(Mode));

    if (false == Event)
    {
        Epwmx->ETCTL.bits.ATSEL = (uint32_t)Mode;
    }
    else
    {
        Epwmx->ETCTL.bits.BTSEL = (uint32_t)Mode;
    }
}

/**
 * @brief 软件触发事件 \n
 *                  产生一次触发AD事件脉冲,该位由硬件自动清零
 *
 * @param Epwmx 指向EPWM内存结构的指针 \n
 *                  EPWM11_PTR ~ EPWM13_PTR, EPWM16_PTR, EPWM31_PTR ~ EPWM33_PTR, EPWM36_PTR
 * @param Event 事件序号 \n
 *                  false -- 事件0 \n
 *                  true -- 事件1
 * @retval void
 */
KF_INLINE void Epwm_LL_TriggerEventBySoftware(Epwm_RegisterMap_t *const Epwmx, bool Event)
{
    uint32_t Mask;

    KF_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH_ADDR(Epwmx));

    Mask = ((Event ? 1UL : 0UL) * 16UL) + 3UL;
    /* PRQA S 3473 1 #KQR003473 */
    REG_BIT_SET(Epwmx->ETCTL.reg, 0x1UL << Mask);
}

/**
 * @brief 设置触发 AD 事件类型
 *
 * @param Epwmx 指向EPWM内存结构的指针 \n
 *                  EPWM11_PTR ~ EPWM13_PTR, EPWM16_PTR, EPWM31_PTR ~ EPWM33_PTR, EPWM36_PTR
 * @param Event 事件序号 \n
 *                  false -- 事件0 \n
 *                  true -- 事件1
 * @param TrigEvent 事件类型 \n
 *                  EPWM_TRIG_EVENT_TX_EQU_ZERO -- 计数值等于0触发
 *                  EPWM_TRIG_EVENT_TX_EQU_PPX -- 计数值等于PPX触发
 *                  EPWM_TRIG_EVENT_TX_EQU_RA -- 计数值等于RA触发
 *                  EPWM_TRIG_EVENT_TX_EQU_RB -- 计数值等于B触发
 * @retval void
 */
KF_INLINE void Epwm_LL_SetTriggerEventMode(Epwm_RegisterMap_t *const Epwmx, bool Event, Epwm_TrigEvent_t TrigEvent)
{
    KF_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH_ADDR(Epwmx));
    KF_EPWM_ASSERT(CHECK_TRIG_EVENT(TrigEvent));

    if (false == Event)
    {
        Epwmx->ETCTL.bits.SELA = (uint32_t)TrigEvent;
    }
    else
    {
        Epwmx->ETCTL.bits.SELB = (uint32_t)TrigEvent;
    }
}

/**
 * @brief 设置事件触发使能状态 \n
 *                  产生一次触发AD事件脉冲,该位由硬件自动清零
 *
 * @param Epwmx 指向EPWM内存结构的指针 \n
 *                  EPWM11_PTR ~ EPWM13_PTR, EPWM16_PTR, EPWM31_PTR ~ EPWM33_PTR, EPWM36_PTR
 * @param Event 事件序号 \n
 *                  false -- 事件0 \n
 *                  true -- 事件1
 * @param EnableStatus 事件触发使能状态 \n
 *                  false -- 不使能触发事件 \n
 *                  true -- 使能触发事件
 * @retval void
 */
KF_INLINE void Epwm_LL_SetTriggerEventEnabled(Epwm_RegisterMap_t *const Epwmx, bool Event, bool EnableStatus)
{
    uint32_t Mask;

    KF_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH_ADDR(Epwmx));

    Mask = (Event ? 1UL : 0UL) * 16UL;
    /* PRQA S 3473 1 #KQR003473 */
    REG_BITS_WRITE(Epwmx->ETCTL.reg, 0x1UL << Mask, (EnableStatus ? 1UL : 0UL) << Mask);
}

/**
 * @brief 设置触发信号产生触发AD事件周期
 *
 * @param Epwmx 指向EPWM内存结构的指针 \n
 *                  EPWM11_PTR ~ EPWM13_PTR, EPWM16_PTR, EPWM31_PTR ~ EPWM33_PTR, EPWM36_PTR
 * @param Event 事件序号 \n
 *                  false -- 事件0 \n
 *                  true -- 事件1
 * @param Period 触发周期 \n
 *                  0 -- 每一次触发信号都能产生触发 AD 事件（其中包括软件触发） \n
 *                  1 -- 每两次触发信号产生触发 AD 事件
 *                  2 -- 每三次触发信号产生触发 AD 事件
 *                  3 -- 每四次触发信号产生触发 AD 事件
 * @retval void
 */
KF_INLINE void Epwm_LL_SetTriggerSignalPeriod(Epwm_RegisterMap_t *const Epwmx, bool Event, uint32_t Period)
{
    KF_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH_ADDR(Epwmx));
    KF_EPWM_ASSERT(CHECK_TRIG_EVENT_PERIOD(Period));

    if (false == Event)
    {
        Epwmx->ETCTL.bits.APP = Period;
    }
    else
    {
        Epwmx->ETCTL.bits.BPP = Period;
    }
}

/**
 * @brief 获取触发AD事件的触发信号计数值
 *
 * @param Epwmx 指向EPWM内存结构的指针 \n
 *                  EPWM11_PTR ~ EPWM13_PTR, EPWM16_PTR, EPWM31_PTR ~ EPWM33_PTR, EPWM36_PTR
 * @param Event 事件序号 \n
 *                  false -- 事件0 \n
 *                  true -- 事件1
 * @retval uint32_t 触发信号计数值
 */
KF_INLINE uint32_t Epwm_LL_GetTriggerSignalCount(const Epwm_RegisterMap_t *const Epwmx, bool Event)
{
    KF_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH_ADDR(Epwmx));
    uint8_t count = 0U;

    if (false == Event)
    {
        count = Epwmx->ETCTL.bits.AT;
    }
    else
    {
        count = Epwmx->ETCTL.bits.BT;
    }
    return count;
}

/**
 * @brief 设置EPWM中断使能状态
 *
 * @param Epwmx 指向EPWM内存结构的指针 \n
 *                  EPWM11_PTR ~ EPWM13_PTR, EPWM16_PTR, EPWM31_PTR ~ EPWM33_PTR, EPWM36_PTR
 * @param IntIndex EPWM中断 \n
 *                  EPWM_INDEX_TRIGGER_EVENT_ZERO -- Tx触发AD事件0中断使能位 \n
 *                  EPWM_INDEX_TRIGGER_EVENT_ONE -- Tx触发AD事件1中断使能位 \n
 *                  EPWM_INDEX_SHUTDOWN_EVENT -- Tx关断事件中断使能位 \n
 *                  EPWM_INDEX_UPDATE_EVENT -- Tx更新事件中断使能位 \n
 *                  EPWM_INDEX_OVERFLOW_EVENT -- Tx计数溢出中断使能位 \n
 *                  EPWM_INDEX_TX_EQU_RB -- Tx计数值等于RB触发中断使能位 \n
 *                  EPWM_INDEX_TX_EQU_RA -- Tx计数值等于RA触发中断使能位 \n
 *                  EPWM_INDEX_TX_EQU_RC -- Tx计数值等于RC触发中断使能位 \n
 *                  EPWM_INDEX_TX_EQU_RD -- Tx计数值等于RD触发中断使能位 \n
 *                  EPWM_INDEX_CAPTURE_EVENT -- 捕捉事件中断使能位
 * @param EnableStatus 使能状态 \n
 *                  false -- 不使能对应中断 \n
 *                  true -- 使能对应中断
 * @retval void
 */
KF_INLINE void Epwm_LL_SetIntrEnabled(Epwm_RegisterMap_t *const Epwmx, Epwm_Interrupt_t IntIndex, bool EnableStatus)
{
    KF_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH_ADDR(Epwmx));
    KF_EPWM_ASSERT(CHECK_EPWM_INTERRUPT(IntIndex));

    /* PRQA S 3473 1 #KQR003473 */
    REG_BITS_WRITE(Epwmx->IE.reg, 0x1UL << (uint32_t)IntIndex, (EnableStatus ? 1UL : 0UL) << (uint32_t)IntIndex);
}

/**
 * @brief 获取EPWM中断标志
 *
 * @param Epwmx 指向EPWM内存结构的指针 \n
 *                  EPWM11_PTR ~ EPWM13_PTR, EPWM16_PTR, EPWM31_PTR ~ EPWM33_PTR, EPWM36_PTR
 * @param IntIndex EPWM中断 \n
 *                  EPWM_INDEX_TRIGGER_EVENT_ZERO -- Tx触发AD事件0中断使能位 \n
 *                  EPWM_INDEX_TRIGGER_EVENT_ONE -- Tx触发AD事件1中断使能位 \n
 *                  EPWM_INDEX_SHUTDOWN_EVENT -- Tx关断事件中断使能位 \n
 *                  EPWM_INDEX_UPDATE_EVENT -- Tx更新事件中断使能位 \n
 *                  EPWM_INDEX_OVERFLOW_EVENT -- Tx计数溢出中断使能位 \n
 *                  EPWM_INDEX_TX_EQU_RB -- Tx计数值等于RB触发中断使能位 \n
 *                  EPWM_INDEX_TX_EQU_RA -- Tx计数值等于RA触发中断使能位 \n
 *                  EPWM_INDEX_TX_EQU_RC -- Tx计数值等于RC触发中断使能位 \n
 *                  EPWM_INDEX_TX_EQU_RD -- Tx计数值等于RD触发中断使能位 \n
 *                  EPWM_INDEX_CAPTURE_EVENT -- 捕捉事件中断使能位
 * @retval bool 中断状态 \n
 *                  false -- 不使能对应中断 \n
 *                  true -- 使能对应中断
 */
KF_INLINE bool Epwm_LL_GetIntrFlag(const Epwm_RegisterMap_t *const Epwmx, Epwm_Interrupt_t IntIndex)
{
    KF_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH_ADDR(Epwmx));
    KF_EPWM_ASSERT(CHECK_EPWM_INTERRUPT(IntIndex));

    /* PRQA S 3469 1 #KQR003469 */
    return ((0u != REG_BITS_READ(Epwmx->IF.reg, 0x1UL << (uint32_t)IntIndex, (uint32_t)IntIndex)) ? true : false);
}

/**
 * @brief 清除EPWM中断标志
 *
 * @param Epwmx 指向EPWM内存结构的指针 \n
 *                  EPWM11_PTR ~ EPWM13_PTR, EPWM16_PTR, EPWM31_PTR ~ EPWM33_PTR, EPWM36_PTR
 * @param IntIndex EPWM中断 \n
 *                  EPWM_INDEX_TRIGGER_EVENT_ZERO -- Tx触发AD事件0中断使能位 \n
 *                  EPWM_INDEX_TRIGGER_EVENT_ONE -- Tx触发AD事件1中断使能位 \n
 *                  EPWM_INDEX_SHUTDOWN_EVENT -- Tx关断事件中断使能位 \n
 *                  EPWM_INDEX_UPDATE_EVENT -- Tx更新事件中断使能位 \n
 *                  EPWM_INDEX_OVERFLOW_EVENT -- Tx计数溢出中断使能位 \n
 *                  EPWM_INDEX_TX_EQU_RB -- Tx计数值等于RB触发中断使能位 \n
 *                  EPWM_INDEX_TX_EQU_RA -- Tx计数值等于RA触发中断使能位 \n
 *                  EPWM_INDEX_TX_EQU_RC -- Tx计数值等于RC触发中断使能位 \n
 *                  EPWM_INDEX_TX_EQU_RD -- Tx计数值等于RD触发中断使能位 \n
 *                  EPWM_INDEX_CAPTURE_EVENT -- 捕捉事件中断使能位
 * @retval void
 */
KF_INLINE void Epwm_LL_ClearIntrFlag(Epwm_RegisterMap_t *const Epwmx, Epwm_Interrupt_t IntIndex)
{
    KF_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH_ADDR(Epwmx));
    KF_EPWM_ASSERT(CHECK_EPWM_INTERRUPT(IntIndex));

    volatile uint32_t timeout = Epwmx->PRSC + 1U;

    /* PRQA S 3473 ++ #KQR003473 */
    /* PRQA S 3415 ++ #KQR003415 */
    REG_BIT_SET(Epwmx->IC.reg, 0x1UL << (uint32_t)IntIndex);
    /* Mantis #4339 */
    do
    {
        timeout -= 1U;
    } while ((((Epwmx->IF.reg >> (uint32_t)IntIndex) & 0x1U) != 0U) && (timeout > 0U));

    REG_BIT_CLR(Epwmx->IC.reg, 0x1UL << (uint32_t)IntIndex);
    /* PRQA S 3415 -- #KQR003415 */
    /* PRQA S 3473 -- #KQR003473 */
}

/**
 * @brief 设置EPWM触发DMA使能状态
 *
 * @param Epwmx 指向EPWM内存结构的指针 \n
 *                  EPWM11_PTR ~ EPWM13_PTR, EPWM16_PTR, EPWM31_PTR ~ EPWM33_PTR, EPWM36_PTR
 * @param Index EPWM触发DMA事件 \n
 *                  EPWM_INDEX_TRIGGER_EVENT_ZERO -- Tx触发AD事件0中断使能位 \n
 *                  EPWM_INDEX_TRIGGER_EVENT_ONE -- Tx触发AD事件1中断使能位 \n
 *                  EPWM_INDEX_SHUTDOWN_EVENT -- Tx关断事件中断使能位 \n
 *                  EPWM_INDEX_UPDATE_EVENT -- Tx更新事件中断使能位 \n
 *                  EPWM_INDEX_OVERFLOW_EVENT -- Tx计数溢出中断使能位 \n
 *                  EPWM_INDEX_TX_EQU_RB -- Tx计数值等于RB触发中断使能位 \n
 *                  EPWM_INDEX_TX_EQU_RA -- Tx计数值等于RA触发中断使能位 \n
 *                  EPWM_INDEX_TX_EQU_RC -- Tx计数值等于RC触发中断使能位 \n
 *                  EPWM_INDEX_TX_EQU_RD -- Tx计数值等于RD触发中断使能位
 * @param EnableStatus 使能状态 \n
 *                  false -- 该事件不可触发DMA \n
 *                  true -- 该事件可触发DMA
 * @retval void
 */
KF_INLINE void Epwm_LL_SetTriggerDmaEnabled(Epwm_RegisterMap_t *const Epwmx, EPWM_DmaTrigger_t Index, bool EnableStatus)
{
    KF_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH_ADDR(Epwmx));
    KF_EPWM_ASSERT(CHECK_EPWM_DMA_TRIGGER(Index));

    /* PRQA S 3473 1 #KQR003473 */
    REG_BITS_WRITE(Epwmx->DE.reg, 0x1UL << (uint32_t)Index, (EnableStatus ? 1UL : 0UL) << (uint32_t)Index);
}

/**
 * @brief 获取EPWM触发DMA标志位
 *
 * @param Epwmx 指向EPWM内存结构的指针 \n
 *                  EPWM11_PTR ~ EPWM13_PTR, EPWM16_PTR, EPWM31_PTR ~ EPWM33_PTR, EPWM36_PTR
 * @param Index EPWM触发DMA事件 \n
 *                  EPWM_INDEX_TRIGGER_EVENT_ZERO -- Tx触发AD事件0中断使能位 \n
 *                  EPWM_INDEX_TRIGGER_EVENT_ONE -- Tx触发AD事件1中断使能位 \n
 *                  EPWM_INDEX_SHUTDOWN_EVENT -- Tx关断事件中断使能位 \n
 *                  EPWM_INDEX_UPDATE_EVENT -- Tx更新事件中断使能位 \n
 *                  EPWM_INDEX_OVERFLOW_EVENT -- Tx计数溢出中断使能位 \n
 *                  EPWM_INDEX_TX_EQU_RB -- Tx计数值等于RB触发中断使能位 \n
 *                  EPWM_INDEX_TX_EQU_RA -- Tx计数值等于RA触发中断使能位 \n
 *                  EPWM_INDEX_TX_EQU_RC -- Tx计数值等于RC触发中断使能位 \n
 *                  EPWM_INDEX_TX_EQU_RD -- Tx计数值等于RD触发中断使能位 \n
 *                  EPWM_INDEX_CAPTURE_EVENT -- 捕捉事件中断使能位
 * @retval bool DMA触发状态 \n
 *                  false -- 该事件未触发了DMA \n
 *                  true -- 该事件触发了DMA
 */
KF_INLINE bool Epwm_LL_GetDmaTriggeredFlag(const Epwm_RegisterMap_t *const Epwmx, EPWM_DmaTrigger_t Index)
{
    KF_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH_ADDR(Epwmx));
    KF_EPWM_ASSERT(CHECK_EPWM_DMA_TRIGGER(Index));

    /* PRQA S 3469 1 #KQR003469 */
    return ((0u != REG_BITS_READ(Epwmx->DF.reg, 0x1UL << (uint32_t)Index, (uint32_t)Index)) ? true : false);
}

/**
 * @brief 获取EPWM捕捉寄存器的值
 *
 * @param Epwmx 指向EPWM内存结构的指针 \n
 *                  EPWM11_PTR ~ EPWM13_PTR, EPWM16_PTR, EPWM31_PTR ~ EPWM33_PTR, EPWM36_PTR
 * @retval uint32_t EPWM捕捉值
 */
KF_INLINE uint32_t Epwm_LL_ReadCaptureValue(const Epwm_RegisterMap_t *const Epwmx)
{
    KF_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH_ADDR(Epwmx));

    return (Epwmx->CAP);
}

/**
 * @brief 设置占空比RC寄存器的值
 *
 * @param Epwmx 指向EPWM内存结构的指针 \n
 *                  EPWM11_PTR ~ EPWM13_PTR, EPWM16_PTR, EPWM31_PTR ~ EPWM33_PTR, EPWM36_PTR
 * @param Value 占空比 \n
 *                  0x0 ~ 0xffffffff
 * @retval void
 */
KF_INLINE void Epwm_LL_WriteDutyCycleValueRc(Epwm_RegisterMap_t *const Epwmx, uint32_t Value)
{
    KF_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH_ADDR(Epwmx));

    Epwmx->RC = Value;
}

/**
 * @brief 设置占空比RD寄存器的值
 *
 * @param Epwmx 指向EPWM内存结构的指针 \n
 *                  EPWM11_PTR ~ EPWM13_PTR, EPWM16_PTR, EPWM31_PTR ~ EPWM33_PTR, EPWM36_PTR
 * @param Value 占空比 \n
 *                  0x0 ~ 0xffffffff
 * @retval void
 */
KF_INLINE void Epwm_LL_WriteDutyCycleValueRd(Epwm_RegisterMap_t *const Epwmx, uint32_t Value)
{
    KF_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH_ADDR(Epwmx));

    Epwmx->RD = Value;
}

/**
 * @brief 设置EPWM全局更新使能
 *
 * @param Epwmx 指向EPWM内存结构的指针 \n
 *                  EPWM11_PTR ~ EPWM13_PTR, EPWM16_PTR, EPWM31_PTR ~ EPWM33_PTR, EPWM36_PTR
 * @param EnableStatus 全局更新使能状态 \n
 *                  true  -- 独立更新寄存器 \n
 *                  false -- 全局更新寄存器
 * @retval void
 */
KF_INLINE void Epwm_LL_SetIndependentUpdateEnabled(Epwm_RegisterMap_t *const Epwmx, bool EnableStatus)
{
    KF_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH_ADDR(Epwmx));

    Epwmx->UDCTL.bits.GBUDEN = EnableStatus ? 1U : 0U;
}

/**
 * @brief 获取计数溢出中断标志
 *
 * @param Epwmx 指向EPWM内存结构的指针 \n
 *                  EPWM11_PTR ~ EPWM13_PTR, EPWM16_PTR, EPWM31_PTR ~ EPWM33_PTR, EPWM36_PTR
 * @retval bool 溢出标志 \n
 *              true  -- Tx溢出标志置位 \n
 *              false -- Tx溢出标志未置位
 */
KF_INLINE bool Epwm_LL_GetOverflowFlag(const Epwm_RegisterMap_t *const Epwmx)
{
    KF_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH_ADDR(Epwmx));

    return (Epwmx->IF.bits.TXIF != 0U);
}

/**
 * @brief 清除计数溢出中断标志
 *
 * @param Epwmx 指向EPWM内存结构的指针 \n
 *                  EPWM11_PTR ~ EPWM13_PTR, EPWM16_PTR, EPWM31_PTR ~ EPWM33_PTR, EPWM36_PTR
 * @retval void
 */
KF_INLINE void Epwm_LL_ClearOverflowFlag(Epwm_RegisterMap_t *const Epwmx)
{
    KF_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH_ADDR(Epwmx));

    volatile uint32_t timeout = Epwmx->PRSC + 1U;

    Epwmx->IC.bits.TXIC = 1U;
    /* PRQA S 3415 ++ #KQR003415 */
    /* Mantis #4339 */
    do
    {
        timeout -= 1U;
    } while ((((Epwmx->IF.reg >> 4U) & 0x1U) != 0U) && (timeout > 0U));
    /* PRQA S 3415 -- #KQR003415 */

    Epwmx->IC.bits.TXIC = 0U;
}

/**
 * @brief 设置Tx 溢出中断
 *
 * @param Epwmx 指向EPWM内存结构的指针 \n
 *                  EPWM11_PTR ~ EPWM13_PTR, EPWM16_PTR, EPWM31_PTR ~ EPWM33_PTR, EPWM36_PTR
 * @param EnableSta 中断使能状态 \n
 *              true  -- 使能中断 \n
 *              false -- 不使能中断
 * @retval void
 */
KF_INLINE void Epwm_LL_SetOverFlowIntrEnabled(Epwm_RegisterMap_t *const Epwmx, bool EnableSta)
{
    KF_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH_ADDR(Epwmx));

    Epwmx->IE.bits.TXIE = EnableSta ? 1U : 0U;
}

/**
 * @brief 获取EPWM中断发生状态
 *
 * @param Epwmx 指向EPWM内存结构的指针 \n
 *                  EPWM11_PTR ~ EPWM13_PTR, EPWM16_PTR, EPWM31_PTR ~ EPWM33_PTR, EPWM36_PTR
 * @param IntIndex EPWM中断 \n
 *                  EPWM_INDEX_TRIGGER_EVENT_ZERO -- Tx触发AD事件0中断使能位 \n
 *                  EPWM_INDEX_TRIGGER_EVENT_ONE -- Tx触发AD事件1中断使能位 \n
 *                  EPWM_INDEX_SHUTDOWN_EVENT -- Tx关断事件中断使能位 \n
 *                  EPWM_INDEX_UPDATE_EVENT -- Tx更新事件中断使能位 \n
 *                  EPWM_INDEX_OVERFLOW_EVENT -- Tx计数溢出中断使能位 \n
 *                  EPWM_INDEX_TX_EQU_RB -- Tx计数值等于RB触发中断使能位 \n
 *                  EPWM_INDEX_TX_EQU_RA -- Tx计数值等于RA触发中断使能位 \n
 *                  EPWM_INDEX_TX_EQU_RC -- Tx计数值等于RC触发中断使能位 \n
 *                  EPWM_INDEX_TX_EQU_RD -- Tx计数值等于RD触发中断使能位 \n
 *                  EPWM_INDEX_CAPTURE_EVENT -- 捕捉事件中断使能位
 * @retval bool 中断发生状态
 *         true    发生了中断，且已使能
 *         false    未发生中断，或未使能
 */
KF_INLINE bool Epwm_LL_GetIntrState(const Epwm_RegisterMap_t *const Epwmx, Epwm_Interrupt_t IntIndex)
{
    KF_EPWM_ASSERT(CHECK_EPWM_ALL_PERIPH_ADDR(Epwmx));
    KF_EPWM_ASSERT(CHECK_EPWM_INTERRUPT(IntIndex));
    /* PRQA S 3469 ++ #KQR003469 */
    bool flag  = (0U != REG_BITS_READ(Epwmx->IF.reg, 0x1UL << (uint32_t)IntIndex, (uint32_t)IntIndex)) ? true : false;
    bool state = (0U != REG_BITS_READ(Epwmx->IE.reg, 0x1UL << (uint32_t)IntIndex, (uint32_t)IntIndex)) ? true : false;
    /* PRQA S 3469 -- #KQR003469 */

    return flag && state;
}

#ifdef __cplusplus
}
#endif /*End of __cplusplus*/
#endif /*End of KF32A158SF_DRV_EPWM_H*/
/* EOF */
