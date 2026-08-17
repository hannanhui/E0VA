/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name        : kf32a158sf_drv_wdt.h
 *  @Date             : 2025-07-10
 *  @Version          : {{VersionDate}}
 *  @Description      : This file provides WDT driver.
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
 *  |2025-07-10  |V1.0     |AE Group     |New create
 ******************************************************************************/
#ifndef KF32A158SF_DRV_WDT_H
#define KF32A158SF_DRV_WDT_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 *                      QAC Warnings
 ******************************************************************************/
/* PRQA S 0288 EOF #KQR000288 */
/* PRQA S 3205 EOF #KQR003205 */
/* PRQA S 3219 EOF #KQR003219 */
/* PRQA S 1006,3006 EOF #KQR101006 */

/******************************************************************************
 *                      Include Files
 ******************************************************************************/
#include "kf32a158sf_reg_iwdt.h"
#include "kf32a158sf_reg_wwdt.h"
#include "kf32a158sf_reg_ewdt.h"

/******************************************************************************
 *                      Macro or Inline
 ******************************************************************************/
#ifdef KF_DRV_WDT_ASSERT
#include "dev_assert.h"
#define KF_WDT_ASSERT(x) KF_DEV_ASSERT(x)
#else
#define KF_WDT_ASSERT(x) ((void)0U)
#endif

/******************************************************************************
 *                      Type definitions
 ******************************************************************************/

/**IWDT预分频系数*/
typedef enum
{
    IWDT_DIVISION_32    = 0x0u,
    IWDT_DIVISION_64    = 0x1u,
    IWDT_DIVISION_128   = 0x2u,
    IWDT_DIVISION_256   = 0x3u,
    IWDT_DIVISION_512   = 0x4u,
    IWDT_DIVISION_1024  = 0x5u,
    IWDT_DIVISION_2048  = 0x6u,
    IWDT_DIVISION_4096  = 0x7u,
    IWDT_DIVISION_8192  = 0x8u,
    IWDT_DIVISION_16384 = 0x9u,
    IWDT_DIVISION_32768 = 0xAu,
    IWDT_DIVISION_65536 = 0xBu,
} Iwdt_Division_t;
#define CHECK_IWDT_DIVISION(x) (((x) >= 0U) && ((x) <= IWDT_DIVISION_65536))

/**WWDT, EWDT预分频系数*/
typedef enum
{
    WDT_DIVISION_1 = 0x0u,
    WDT_DIVISION_2,
    WDT_DIVISION_4,
    WDT_DIVISION_8,
    WDT_DIVISION_16,
    WDT_DIVISION_32,
    WDT_DIVISION_64,
    WDT_DIVISION_128,
    WDT_DIVISION_256,
    WDT_DIVISION_512,
    WDT_DIVISION_1024,
    WDT_DIVISION_2048,
    WDT_DIVISION_4096,
    WDT_DIVISION_8192,
    WDT_DIVISION_16384,
    WDT_DIVISION_32768,
    WDT_DIVISION_65536,
    WDT_DIVISION_131072,
    WDT_DIVISION_262144,
} Wwdt_Division_t, Ewdt_Division_t;
#define CHECK_EWDT_DIVISION(x) (((x) >= 0U) && ((x) <= WDT_DIVISION_262144))
#define CHECK_WWDT_DIVISION(x) (((x) >= 0U) && ((x) <= WDT_DIVISION_262144))

/**WWDT, EWDT 工作时钟*/
typedef enum
{
    WDT_CLKS_INTLF,
    WDT_CLKS_SCLK,
} WWDT_ClockSource_t, EWDT_ClockSource_t;
#define CHECK_EWDT_CLOCKSOURCE(x) (((x) == WDT_CLKS_INTLF) || ((x) == WDT_CLKS_SCLK))
#define CHECK_WWDT_CLOCKSOURCE(x) (((x) == WDT_CLKS_INTLF) || ((x) == WDT_CLKS_SCLK))

/**检查0x3F*/
#define CHECK_WDT_0x3F(x) (((x) <= 0x3FU) && ((x) >= 0x0U))

/**检查0x7F*/
#define CHECK_WDT_0x7F(x) (((x) <= 0x7FU) && ((x) >= 0x0U))

/**检查0xFFF*/
#define CHECK_WDT_0xFFF(x) (((x) <= 0xFFEU) && ((x) >= 0x1U))

/******************************************************************************
 *                      Export Variables
 ******************************************************************************/

/******************************************************************************
 *                      Export Functions
 ******************************************************************************/

/**
 * @brief 设置独立看门狗使能
 *
 * @param Iwdtx: 指向 IWDT 寄存器结构体的指针
 * @param State:
 *        true   使能看门狗
 *        false   禁止看门狗
 * @return void
 */
KF_INLINE void Iwdt_LL_SetEnabled(Iwdt_RegisterMap_t *const Iwdtx, bool State)
{
    KF_WDT_ASSERT(CHECK_IWDT_ALL_PERIPH_ADDR(Iwdtx));

    Iwdtx->CTL.bits.IWDTEN = State ? 1U : 0U;
}

/**
 * @brief 设置独立看门狗的工作时钟
 *
 * @param Iwdtx: 指向 IWDT 寄存器结构体的指针
 * @param ClkSrc:
 *        true   外部低频EXTLF
 *        false   内部低频INTLF
 * @return void
 */
KF_INLINE void Iwdt_LL_SelectClkSource(Iwdt_RegisterMap_t *const Iwdtx, bool ClkSrc)
{
    KF_WDT_ASSERT(CHECK_IWDT_ALL_PERIPH_ADDR(Iwdtx));

    Iwdtx->CTL.bits.CLKS = ClkSrc ? 1U : 0U;
}

/**
 * @brief 独立看门狗喂狗
 *
 * @param Iwdtx: 指向 IWDT 寄存器结构体的指针
 * @return void
 */
KF_INLINE void Iwdt_LL_FeedDog(Iwdt_RegisterMap_t *const Iwdtx)
{
    KF_WDT_ASSERT(CHECK_IWDT_ALL_PERIPH_ADDR(Iwdtx));

    Iwdtx->FD.bits.IWDTFD = 0x55AA55AAU;
}

/**
 * @brief 设置独立看门狗预分频,对立看门狗工作时钟进行分频
 *
 * @param Iwdtx: 指向 IWDT 寄存器结构体的指针
 * @param  Div 预分频值
 * @return void
 */
KF_INLINE void Iwdt_LL_SetClkPrescaler(Iwdt_RegisterMap_t *const Iwdtx, Iwdt_Division_t Div)
{
    KF_WDT_ASSERT(CHECK_IWDT_ALL_PERIPH_ADDR(Iwdtx));
    KF_WDT_ASSERT(CHECK_IWDT_DIVISION(Div));

    Iwdtx->CTL.bits.IWDTPS = (uint32_t)Div;
}

/**
 * @brief 设置独立看门狗溢出值,溢出时复位.
 *
 * @param Iwdtx: 指向 IWDT 寄存器结构体的指针
 * @param  Value 独立看门狗溢出值,取值为1~0xFFE
 * @return void
 */
KF_INLINE void Iwdt_LL_SetOverflowValue(Iwdt_RegisterMap_t *const Iwdtx, uint16_t Value)
{
    KF_WDT_ASSERT(CHECK_IWDT_ALL_PERIPH_ADDR(Iwdtx));
    KF_WDT_ASSERT(CHECK_WDT_0xFFF(Value));

    /**Mantis #4392 */
    volatile uint16_t temp  = (Value < 1U) ? 1U : Value;
    temp                    = (temp > 0xFFEU) ? 0xFFEU : temp;
    Iwdtx->CTL.bits.IWDTOVF = temp;
}

/******************************************************************************
 **                      WWDT
 ******************************************************************************/

/**
 * @brief 设置窗口看门狗使能
 *
 * @param Wwdtx 窗口看门狗寄存器结构体指针
 * @param State:
 *        true   使能看门狗
 *        false   禁止看门狗
 * @return void
 */
KF_INLINE void Wwdt_LL_SetEnabled(Wwdt_RegisterMap_t *const Wwdtx, bool State)
{
    KF_WDT_ASSERT(CHECK_WWDT_ALL_PERIPH_ADDR(Wwdtx));

    Wwdtx->CTL.bits.WWDTEN = State ? 1U : 0U;
}

/**
 * @brief 设置窗口看门狗中断使能
 *
 * @param Wwdtx 窗口看门狗寄存器结构体指针
 * @param State:
 *        true   使能中断
 *        false   禁止中断
 * @return void
 */
KF_INLINE void Wwdt_LL_SetIntrEnabled(Wwdt_RegisterMap_t *const Wwdtx, bool State)
{
    KF_WDT_ASSERT(CHECK_WWDT_ALL_PERIPH_ADDR(Wwdtx));

    Wwdtx->CTL.bits.WWDTIE = State ? 1U : 0U;
}

/**
 * @brief 获取窗口看门狗中断标志位
 *
 * @param Wwdtx 窗口看门狗寄存器结构体指针
 * @return 窗口看门狗中断状态:
 * @retval true     已发生中断
 * @retval false    未发生中断
 */
KF_INLINE bool Wwdt_LL_GetIntrFlag(const Wwdt_RegisterMap_t *const Wwdtx)
{
    KF_WDT_ASSERT(CHECK_WWDT_ALL_PERIPH_ADDR(Wwdtx));

    return (Wwdtx->CTL.bits.WWDTIF != 0U) ? true : false;
}

/**
 * @brief 设置窗口看门狗计数时钟预分频位
 *
 * @param Wwdtx 窗口看门狗寄存器结构体指针
 * @param Div: 预分频值,取值 Wwdt_Division_t
 * @return void
 */
KF_INLINE void Wwdt_LL_SetPrescaler(Wwdt_RegisterMap_t *const Wwdtx, Wwdt_Division_t Div)
{
    KF_WDT_ASSERT(CHECK_WWDT_ALL_PERIPH_ADDR(Wwdtx));
    KF_WDT_ASSERT(CHECK_WWDT_DIVISION(Div));

    Wwdtx->CTL.bits.WPS = (uint32_t)Div;
}

/**
 * @brief 设置窗口看门狗配置位
 *
 * @param Wwdtx 窗口看门狗寄存器结构体指针
 * @param WinThreshold: 配置值
 * @attention 理论取值范围是0 ~ 127, 实际仅可配置为0x0 ~ 0x3F, 以避免无法进行喂狗操作
 * @return void
 */
KF_INLINE void Wwdt_LL_SetWindowThreshold(Wwdt_RegisterMap_t *const Wwdtx, uint8_t WinThreshold)
{
    KF_WDT_ASSERT(CHECK_WWDT_ALL_PERIPH_ADDR(Wwdtx));
    KF_WDT_ASSERT(CHECK_WDT_0x3F(WinThreshold));

    Wwdtx->CTL.bits.WW = WinThreshold;
}

/**
 * @brief 设置窗口看门狗中断标志位清零位
 *
 * @param Wwdtx 窗口看门狗寄存器结构体指针
 * @return void
 */
KF_INLINE void Wwdt_LL_ClearIntrFlag(Wwdt_RegisterMap_t *const Wwdtx)
{
    KF_WDT_ASSERT(CHECK_WWDT_ALL_PERIPH_ADDR(Wwdtx));

    Wwdtx->CTL.bits.WWDTIC = 1U;
    NOP();
    NOP();
    NOP();
    NOP();
    Wwdtx->CTL.bits.WWDTIC = 0U;
}

/**
 * @brief: 设置窗口看门狗计数位
 *
 * @param Wwdtx: 窗口看门狗寄存器结构体指针
 * @param Val: 窗口看门狗计数位值 0x0 ~ 0x3F
 * @return void
 */
KF_INLINE void Wwdt_LL_SetWindowCount(Wwdt_RegisterMap_t *const Wwdtx, uint32_t Val)
{
    KF_WDT_ASSERT(CHECK_WWDT_ALL_PERIPH_ADDR(Wwdtx));
    KF_WDT_ASSERT(CHECK_WDT_0x3F(Val));

    Wwdtx->CNT.bits.WT = Val;
}

/**
 * @brief: 获取窗口看门狗计数位当前值
 *
 * @param Wwdtx: 窗口看门狗寄存器结构体指针
 * @return 窗口看门狗计数位当前值 (0-127)
 */
KF_INLINE uint32_t Wwdt_LL_GetWindowCount(const Wwdt_RegisterMap_t *const Wwdtx)
{
    KF_WDT_ASSERT(CHECK_WWDT_ALL_PERIPH_ADDR(Wwdtx));

    return (uint32_t)Wwdtx->CNT.bits.WT;
}

/**
 * @brief: 设置看门狗工作时钟源
 *
 * @param Wwdtx: 看门狗寄存器结构体指针
 * @param Select WWDT_ClockSource_t
 * @return void
 */
KF_INLINE void Wwdt_LL_SelectClkSource(Wwdt_RegisterMap_t *const Wwdtx, WWDT_ClockSource_t Select)
{
    KF_WDT_ASSERT(CHECK_WWDT_ALL_PERIPH_ADDR(Wwdtx));
    KF_WDT_ASSERT(CHECK_WWDT_CLOCKSOURCE(Select));

    Wwdtx->CTL1.bits.CLKS = (uint32_t)Select;
}

/**
 * @brief WWDT喂狗操作
 * @attention 喂狗前未判断计数值是否在窗口内,需要用户自行判断
 *
 * @param Wwdtx 看门狗寄存器结构体指针
 * @return void
 */
KF_INLINE void Wwdt_LL_FeedDog(Wwdt_RegisterMap_t *const Wwdtx)
{
    KF_WDT_ASSERT(CHECK_WWDT_ALL_PERIPH_ADDR(Wwdtx));

    Wwdt_LL_SetWindowCount(Wwdtx, 0x0U);
}

/******************************************************************************
 **                      EWDT
 ******************************************************************************/

/**
 * @brief: 设置外围看门狗使能位
 *
 * @param Ewdtx: 外围看门狗寄存器结构体指针
 * @param State
 *        true 使能外围看门狗
 *        false 关闭外围看门狗
 * @return void
 */
KF_INLINE void Ewdt_LL_SetEnabled(Ewdt_RegisterMap_t *const Ewdtx, bool State)
{
    KF_WDT_ASSERT(CHECK_EWDT_ALL_PERIPH_ADDR(Ewdtx));

    Ewdtx->CTL.bits.EWDTEN = State ? 1U : 0U;
}

/**
 * @brief: 设置计数器计数到40时中断使能位
 * @param Ewdtx: 外围看门狗寄存器结构体指针
 * @param State
 *        true 使能计数器计数到40时中断
 *        false 关闭计数器计数到40时中断
 * @return void
 */
KF_INLINE void Ewdt_LL_SetCounterIntrEnabled(Ewdt_RegisterMap_t *const Ewdtx, bool State)
{
    KF_WDT_ASSERT(CHECK_EWDT_ALL_PERIPH_ADDR(Ewdtx));

    Ewdtx->CTL.bits.WT40IE = State ? 1U : 0U;
}

/**
 * @brief 获取计数器计数到40时中断标志
 *
 * @param Ewdtx 外围看门狗寄存器结构体指针
 * @return bool
 * @retval true 产生了计数器计数到40时中断
 * @retval false 未产生计数器计数到40时中断
 */
KF_INLINE bool Ewdt_LL_GetCounterIntrFlag(const Ewdt_RegisterMap_t *const Ewdtx)
{
    KF_WDT_ASSERT(CHECK_EWDT_ALL_PERIPH_ADDR(Ewdtx));

    return (Ewdtx->CTL.bits.WT40IF != 0U) ? true : false;
}

/**
 * @brief: 设置外围看门狗计数时钟预分频位
 *
 * @param Ewdtx: 外围看门狗寄存器结构体指针
 * @param Prescaler: 预分频值 Ewdt_Division_t
 * @return void
 */
KF_INLINE void Ewdt_LL_SetPrescaler(Ewdt_RegisterMap_t *const Ewdtx, Ewdt_Division_t Prescaler)
{
    KF_WDT_ASSERT(CHECK_EWDT_ALL_PERIPH_ADDR(Ewdtx));
    KF_WDT_ASSERT(CHECK_EWDT_DIVISION(Prescaler));

    Ewdtx->CTL.bits.WPS = (uint32_t)Prescaler;
}

/**
 * @brief: 设置外围看门狗配置位
 *
 * @param Ewdtx: 外围看门狗寄存器结构体指针
 * @param Config: 配置值,取值范围为0x0 ~ 0x3F
 * @return void
 */
KF_INLINE void Ewdt_LL_SetWindowThreshold(Ewdt_RegisterMap_t *const Ewdtx, uint32_t Config)
{
    KF_WDT_ASSERT(CHECK_EWDT_ALL_PERIPH_ADDR(Ewdtx));
    KF_WDT_ASSERT(CHECK_WDT_0x3F(Config));

    Ewdtx->CTL.bits.WW = Config;
}

/**
 * @brief: 计数器计数到40时中断标志位清零位,需要软件置位和清零
 *
 * @param Ewdtx: 外围看门狗寄存器结构体指针
 * @return void
 */
KF_INLINE void Ewdt_LL_ClearCounterIntrFlag(Ewdt_RegisterMap_t *const Ewdtx)
{
    KF_WDT_ASSERT(CHECK_EWDT_ALL_PERIPH_ADDR(Ewdtx));

    Ewdtx->CTL.bits.WT40IC = 1U;
    NOP();
    NOP();
    NOP();
    NOP();
    Ewdtx->CTL.bits.WT40IC = 0U;
}

/**
 * @brief: 设置EWDTIN输入信号使能
 *
 * @param Ewdtx: 外围看门狗寄存器结构体指针
 * @param State
 *        true 使能EWDTIN输入信号
 *        false 关闭EWDTIN输入信号
 * @return void
 */
KF_INLINE void Ewdt_LL_SetInputEnabled(Ewdt_RegisterMap_t *const Ewdtx, bool State)
{
    KF_WDT_ASSERT(CHECK_EWDT_ALL_PERIPH_ADDR(Ewdtx));

    Ewdtx->CTL.bits.EWDTINEN = State ? 1U : 0U;
}

/**
 * @brief: 设置EWDTIN输入信号极性选择
 *
 * @param Ewdtx: 外围看门狗寄存器结构体指针
 * @param Polarity
 *        true EWDTIN输入信号为高电平有效
 *        false EWDTIN输入信号为低电平有效
 * @return void
 */
KF_INLINE void Ewdt_LL_SetInputPolarity(Ewdt_RegisterMap_t *const Ewdtx, bool Polarity)
{
    KF_WDT_ASSERT(CHECK_EWDT_ALL_PERIPH_ADDR(Ewdtx));

    Ewdtx->CTL.bits.EWDTINPOL = Polarity ? 1U : 0U;
}

/**
 * @brief: 看门狗工作时钟源选择使能位
 *
 * @param Ewdtx: 外围看门狗寄存器结构体指针
 * @param ClockSource: 时钟源选择, 取值可见 EWDT_ClockSource_t
 * @return void
 */
KF_INLINE void Ewdt_LL_SelectClkSource(Ewdt_RegisterMap_t *const Ewdtx, EWDT_ClockSource_t ClockSource)
{
    KF_WDT_ASSERT(CHECK_EWDT_ALL_PERIPH_ADDR(Ewdtx));
    KF_WDT_ASSERT(CHECK_EWDT_CLOCKSOURCE(ClockSource));

    Ewdtx->CTL.bits.CLK = (uint32_t)ClockSource;
}

/**
 * @brief: EWDT产生复位信号中断使能位
 *
 * @param Ewdtx: 外围看门狗寄存器结构体指针
 * @param State
 *        true 使能EWDT产生复位信号中断
 *        false 关闭EWDT产生复位信号中断
 * @return void
 */
KF_INLINE void Ewdt_LL_SetResetIntrEnabled(Ewdt_RegisterMap_t *const Ewdtx, bool State)
{
    KF_WDT_ASSERT(CHECK_EWDT_ALL_PERIPH_ADDR(Ewdtx));

    Ewdtx->CTL.bits.EWDTRSTIE = State ? 1U : 0U;
}

/**
 * @brief: EWDT产生复位时中断标志位清零位,需要软件置位和清零
 *
 * @param Ewdtx: 外围看门狗寄存器结构体指针
 * @return void
 */
KF_INLINE void Ewdt_LL_ClearResetIntrFlag(Ewdt_RegisterMap_t *const Ewdtx)
{
    KF_WDT_ASSERT(CHECK_EWDT_ALL_PERIPH_ADDR(Ewdtx));

    Ewdtx->CTL.bits.EWDTRSTIC = 1U;
    NOP();
    NOP();
    NOP();
    NOP();
    Ewdtx->CTL.bits.EWDTRSTIC = 0U;
}

/**
 * @brief: EWDT 发生复位时的中断标志位
 *
 * @param Ewdtx: 外围看门狗寄存器结构体指针
 * @return bool EWDT 发生复位时的中断标志位
 */
KF_INLINE bool Ewdt_LL_GetResetIntrFlag(const Ewdt_RegisterMap_t *const Ewdtx)
{
    KF_WDT_ASSERT(CHECK_EWDT_ALL_PERIPH_ADDR(Ewdtx));

    return (Ewdtx->CTL.bits.EWDTRSTIF != 0U) ? true : false;
}

/**
 * @brief: EWDT的输出有效信号极性选择
 *
 * @param Ewdtx: 外围看门狗寄存器结构体指针
 * @param Polarity
 *        true EWDT输出有效信号为高电平有效
 *        false EWDT输出有效信号为低电平有效
 * @return void
 */
KF_INLINE void Ewdt_LL_SetOutputPolarity(Ewdt_RegisterMap_t *const Ewdtx, bool Polarity)
{
    KF_WDT_ASSERT(CHECK_EWDT_ALL_PERIPH_ADDR(Ewdtx));

    Ewdtx->CTL.bits.OUTSEL = Polarity ? 1U : 0U;
}

/**
 * @brief: 设置窗口看门狗计数位
 * @param Ewdtx: 窗口看门狗寄存器结构体指针
 * @param value: 窗口看门狗计数值,取值范围0~127
 * @return void
 */
KF_INLINE void Ewdt_LL_SetCount(Ewdt_RegisterMap_t *const Ewdtx, uint32_t value)
{
    KF_WDT_ASSERT(CHECK_EWDT_ALL_PERIPH_ADDR(Ewdtx));

    Ewdtx->CNT.bits.WT = value;
}

/**
 * @brief EWDT喂狗操作
 *
 * @param Ewdtx 窗口看门狗寄存器结构体指针
 * @return void
 */
KF_INLINE void Ewdt_LL_FeedDog(Ewdt_RegisterMap_t *const Ewdtx)
{
    KF_WDT_ASSERT(CHECK_EWDT_ALL_PERIPH_ADDR(Ewdtx));

    Ewdt_LL_SetCount(Ewdtx, 0x0U);
}

#ifdef __cplusplus
}
#endif /*End of __cplusplus*/
#endif /*End of KF32A158SF_DRV_WDT_H*/
/* EOF */
