/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name        : kf32a158sf_drv_i2c.h
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
#ifndef KF32A158SF_DRV_I2C_H
#define KF32A158SF_DRV_I2C_H

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
/* PRQA S 3473 EOF #KQR003473 */

/******************************************************************************
 *                      Include Files
 ******************************************************************************/
#include <stdint.h>
#include <stdbool.h>
#include "kf_types.h"
#include "kf32a158sf_reg_i2c.h"

#ifdef KF_DRV_I2C_ASSERT
#include "dev_assert.h"
#define KF_I2C_ASSERT(x) KF_DEV_ASSERT(x)
#else
#define KF_I2C_ASSERT(x) ((void)0U)
#endif

/******************************************************************************
 *                      Macro or Inline
 ******************************************************************************/

/******************************************************************************
 *                      Type definitions
 ******************************************************************************/

typedef enum
{
    I2C_STATE_SIF    = (1UL << 0U),  /*!< 起始信号标志位*/
    I2C_STATE_PIF    = (1UL << 1U),  /*!< 停止信号标志位*/
    I2C_STATE_ADDR   = (1UL << 2U),  /*!< 地址匹配状态位*/
    I2C_STATE_ADD10  = (1UL << 3U),  /*!< 高位地址状态位*/
    I2C_STATE_DATA   = (1UL << 4U),  /*!< 数据内容状态位*/
    I2C_STATE_AFIF   = (1UL << 5U),  /*!< 应答错误标志位*/
    I2C_STATE_ARBLIF = (1UL << 6U),  /*!< 失去仲裁标志位*/
    I2C_STATE_RNW    = (1UL << 7U),  /*!< 读写信息状态位*/
    I2C_STATE_ISIF   = (1UL << 11U), /*!< I2C 中断信号标志位*/
    I2C_STATE_RCBF   = (1UL << 12U), /*!< 接收 BUFF 为满标志位*/
    I2C_STATE_TXBE   = (1UL << 13U), /*!< 发送 BUFF 状态位*/
    I2C_STATE_BLTF   = (1UL << 15U), /*!< 总线低电平超时标志位*/
    I2C_STATE_BERRIF = (1UL << 18U), /*!< 总线错误标志位*/
    I2C_STATE_OVERIF = (1UL << 19U), /*!< I2C 接收或发送数据溢出标志位*/
    I2C_STATE_BUSY   = (1UL << 20U)  /*!< I2C 总线忙标志*/
} I2c_StateMask_t;

typedef enum
{
    I2C_IE_SIE    = (1UL << 0U),  /*!< 起始信号中断使能*/
    I2C_IE_PIE    = (1UL << 1U),  /*!< 停止信号中断使能*/
    I2C_IE_AFIE   = (1UL << 5U),  /*!< 应答错误中断使能位*/
    I2C_IE_ARBLIE = (1UL << 6U),  /*!< 失去仲裁中断使能位*/
    I2C_IE_ISIE   = (1UL << 11U), /*!< I2C 中断信号使能位*/
    I2C_IE_BLTIE  = (1UL << 15U), /*!< 总线低电平超时中断使能位*/
    I2C_IE_BERRIE = (1UL << 18U), /*!< 总线错误中断使能位*/
    I2C_IE_OVERIE = (1UL << 19U)  /*!< I2C 接收或发送数据溢出使能位*/
} I2c_IntrMask_t;

typedef enum
{
    I2C_INTR_SIF    = (1UL << 0U),  /*!< 起始信号中断标志*/
    I2C_INTR_PIF    = (1UL << 1U),  /*!< 停止信号中断标志*/
    I2C_INTR_AFIF   = (1UL << 5U),  /*!< 应答错误中断标志位*/
    I2C_INTR_ARBLIF = (1UL << 6U),  /*!< 失去仲裁中断标志位*/
    I2C_INTR_ISIF   = (1UL << 11U), /*!< I2C 中断信号标志位*/
    I2C_INTR_BLTIF  = (1UL << 15U), /*!< 总线低电平超时中断标志位*/
    I2C_INTR_BERRIF = (1UL << 18U), /*!< 总线错误中断标志位*/
    I2C_INTR_OVERIF = (1UL << 19U)  /*!< I2C 接收或发送数据溢出标志位*/
} I2c_IntrState_t;

#define I2C_INTR_ENABLE(module, intbit) I2c_LL_SetInterruptEnable(module, intbit)

#define I2C_INTR_DISENABLE(module, intbit) I2c_LL_SetInterruptDisable(module, intbit)

/* bit mode */
typedef enum
{
    BADR10_7BITS,
    BADR10_10BITS
} I2c_Addr_t;

/* bit mode check */
#define CHECK_I2C_BADR_TYPE(TYPE) (((TYPE) == BADR10_7BITS) || ((TYPE) == BADR10_10BITS))

/* clock source select */
typedef enum
{
    CLOCK_SELECT_SCLK,
    CLOCK_SELECT_HFCLK,
} I2c_ClkSrc_t;

/* clock source check */
#define CHECK_I2C_CLOCK_TYPE(TYPE) (((TYPE) == CLOCK_SELECT_SCLK) || ((TYPE) == CLOCK_SELECT_HFCLK))

/* clock division */
typedef enum
{
    CLOCK_DIVISION_1,
    CLOCK_DIVISION_2,
    CLOCK_DIVISION_4
} I2c_ClkDiv_t;

/* clock division check */
#define CHECK_I2C_CLOCK_DIVISION(DIVISION)                                                                             \
    (((DIVISION) == CLOCK_DIVISION_1) || ((DIVISION) == CLOCK_DIVISION_2) || ((DIVISION) == CLOCK_DIVISION_4))

/* bit mode */
typedef enum
{
    MODE_I2C,
    MODE_SMBUS
} I2c_Mode_t;
/* bit mode check */
#define CHECK_I2C_MODE(MODE) (((MODE) == MODE_I2C) || ((MODE) == MODE_SMBUS))

typedef enum
{
    ADDRESS_INDEX0,
    ADDRESS_INDEX1,
    ADDRESS_INDEX2,
    ADDRESS_INDEX3
} I2c_AddrIndex_t;
/* addr index check */
#define CHECK_I2C_ADDR_INDEX(ADDR)                                                                                     \
    (((ADDR) == ADDRESS_INDEX0) || ((ADDR) == ADDRESS_INDEX1) || ((ADDR) == ADDRESS_INDEX2) ||                         \
     ((ADDR) == ADDRESS_INDEX3))

/******************************************************************************
 *                      Export Variables
 ******************************************************************************/

/******************************************************************************
 *                      Export Functions
 ******************************************************************************/

KF_INLINE void I2c_LL_ClearState(I2c_RegisterMap_t *const Module, I2c_StateMask_t StateMask);

/**
 * @brief 设置I2C使能位
 *
 * @param Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param State 使能状态 \n
 *                  true -- 使能I2C \n
 *                  false -- 不使能I2C
 * @retval void
 */
KF_INLINE void I2c_LL_SetEnabled(I2c_RegisterMap_t *const Module, bool State)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

    REG_WRITE(Module->CTL.bits.I2CEN, State ? 1U : 0U);
}

/**
 * @brief 设置I2C地址类型
 *
 * @param Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param BitsMode 选择位 \n
 *                  BADR10_7BITS \n
 *                  BADR10_10BITS
 * @retval void
 */
KF_INLINE void I2c_LL_SetBandAddrMode(I2c_RegisterMap_t *const Module, I2c_Addr_t BitsMode)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));
    KF_I2C_ASSERT(CHECK_I2C_BADR_TYPE(BitsMode));

    REG_WRITE(Module->CTL.bits.BADR10, (uint32_t)BitsMode);
}

/**
 * @brief 设置I2C数据保持时间
 *
 * @param Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param ClockNum 时钟个数 \n
 *                      0000 --  3 个 I2C 工作时钟 \n
 *                      0001 --  4 个 I2C 工作时钟 \n
 *                      ... \n
 *                      0111 --  10 个 I2C 工作时钟 \n
 *                      1000 --  11 个 I2C 工作时钟 \n
 *                      ...
 *                      1110 --  17 个 I2C 工作时钟 \n
 *                      1111 --  18 个 I2C 工作时钟
 * @retval void
 */
KF_INLINE void I2c_LL_SetDataHoldCount(I2c_RegisterMap_t *const Module, uint8_t ClockNum)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));
    KF_I2C_ASSERT(ClockNum < 16U);

    REG_WRITE(Module->CTL.bits.DHCNT, ClockNum);
}

/**
 * @brief 设置I2C启动条件使能位(仅限 I2C 主控模式)
 *
 * @param Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param State 使能位 \n
 *                      false -- 启动条件空闲 \n
 *                      true --  在 SDA 和 SCL 引脚启动启动条件。由硬件自动清零
 * @retval void
 */
KF_INLINE void I2c_LL_SetStartConditionState(I2c_RegisterMap_t *const Module, bool State)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

    REG_WRITE(Module->CTL.bits.SEN, State ? 1U : 0U);
}

/**
 * @brief 设置I2C1停止条件使能位(仅限 I2C 主控模式)
 *
 * @param Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param State 停止状态 \n
 *                      false -- 停止条件空闲 \n
 *                      true --  在 SDA 和 SCL 引脚启动停止条件。由硬件自动清零
 * @retval void
 */
KF_INLINE void I2c_LL_SetStopConditionState(I2c_RegisterMap_t *const Module, bool State)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

    REG_WRITE(Module->CTL.bits.PEN, State ? 1U : 0U);
}

/**
 * @brief 设置时钟延长禁止使能
 *
 * @param Module  指向I2C内存结构的指针
 * @param EnableSta 使能状态
 *                      false -- 使能时钟延长 \n
 *                      true -- 禁止时钟延长
 * @retval void
 */
KF_INLINE void I2c_LL_SetSclDelayDisabled(I2c_RegisterMap_t *const Module, bool EnableSta)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

    REG_WRITE(Module->CTL.bits.SCLNOSTR, EnableSta ? 1U : 0U);
}

/**
 * @brief 设置I2C应答序列使能位
 *
 * @param Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param State 应答状态 \n
 *                      false -- 应答序列空闲 \n
 *                      true --  在 SDA 和 SCL 引脚启动应答序列，发送 ACKDT 数据位
 * @retval void
 */
KF_INLINE void I2c_LL_SetAckState(I2c_RegisterMap_t *const Module, bool State)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

    REG_WRITE(Module->CTL.bits.ACKEN, State ? 1U : 0U);
}

/**
 * @brief 设置I2C应答数据位
 *
 * @param Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param State 应答状态 \n
 *                      false -- 应答 \n
 *                      true --  不应答
 * @retval void
 */
KF_INLINE void I2c_LL_SetAckDataState(I2c_RegisterMap_t *const Module, bool State)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

    REG_WRITE(Module->CTL.bits.ACKDT, State ? 1U : 0U);
}

/**
 * @brief 设置I2C广播呼叫使能位(仅限 I2C 从动模式)
 *
 * @param Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param State 广播状态 \n
 *                      false -- 禁止广播呼叫地址 \n
 *                      true --  允许在 I2C 移位寄存器中接收到广播呼叫地址（0000h）时产生中断 \n
 *                      注：需要注意的是，当 I2Cx_ADDRy 寄存器未被设置时，它们的复位值为 \n
 *                          0x0000，也会使 I2C 模块对广播呼叫地址产生响应
 * @retval void
 */
KF_INLINE void I2c_LL_SetBroadCastCallState(I2c_RegisterMap_t *const Module, bool State)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

    REG_WRITE(Module->CTL.bits.GCEN, State ? 1U : 0U);
}

/**
 * @brief I2C 工作时钟选择寄存器
 *
 * @param Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param ClockSelect 时钟类型 \n
 *                      00 --  选用 SCLK 为 I2C 工作时钟 \n
 *                      01 --  选用 HFCLK 为 I2C 工作时钟 \n
 * @retval void
 */
KF_INLINE void I2c_LL_SetClockSelect(I2c_RegisterMap_t *const Module, I2c_ClkSrc_t ClockSelect)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));
    KF_I2C_ASSERT(CHECK_I2C_CLOCK_TYPE(ClockSelect));

    REG_WRITE(Module->CTL.bits.I2CCKS, (uint32_t)ClockSelect);
}

/**
 * @brief I2C 工作时钟分频比选择
 *
 * @param Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param ClockDivision 分频比 \n
 *                      00 --  I2C 工作时钟分频比为 1:1 \n
 *                      00 --  I2C 工作时钟分频比为 1:1 \n
 *                      1x --  I2C 工作时钟分频比为 1:4
 * @retval void
 */
KF_INLINE void I2c_LL_SetClockDivision(I2c_RegisterMap_t *const Module, I2c_ClkDiv_t ClockDivision)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));
    KF_I2C_ASSERT(CHECK_I2C_CLOCK_DIVISION(ClockDivision));

    REG_WRITE(Module->CTL.bits.I2CCKDIV, (uint32_t)ClockDivision);
}

/**
 * @brief 地址寄存器匹配位
 *
 * @param Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param State 匹配模式 \n
 *                      false -- 只有在 I2CADDR 地址匹配时才会接收数据 \n
 *                      true --  可在任意接受的地址上产生中断，将使器件监控总线上的所有通信量 \n
 *                      注：在监控模式下使能全地址匹配时，禁止将 I2C 设成十位地址模式，否则可能导致错误
 * @retval void
 */
KF_INLINE void I2c_LL_SetMatchAllAddr(I2c_RegisterMap_t *const Module, bool State)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

    REG_WRITE(Module->CTL.bits.MTHALL, State ? 1U : 0U);
}

/**
 * @brief 设置I2C的SCL 输出使能。当模块处于监控模式下，清零该位则 SCL 输出将被强制为高电平
 *
 * @param Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param State 时钟电平状态 \n
 *                      false -- SCL 被强制为高 \n
 *                      true --  正常使用 SCL 线
 * @retval void
 */
KF_INLINE void I2c_LL_SetSclState(I2c_RegisterMap_t *const Module, bool State)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

    REG_WRITE(Module->CTL.bits.ENASCL, State ? 1U : 0U);
}

/**
 * @brief 设置I2C监控模式使能位
 *
 * @param Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param State 监控状态 \n
 *                      false -- 不使能监控模式 \n
 *                      true --  使能监控模式
 * @retval void
 */
KF_INLINE void I2c_LL_SetMonitorModeState(I2c_RegisterMap_t *const Module, bool State)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

    REG_WRITE(Module->CTL.bits.MENA, State ? 1U : 0U);
}

/**
 * @brief 获取10 位地址的低位标志位
 *
 * @param Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @retval 标志位 \n
 *                      false -- 无效 \n
 *                      true -- 10 位地址低位有效
 */
KF_INLINE uint8_t I2c_LL_GetAddressLowState(const I2c_RegisterMap_t *const Module)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

    return Module->CTL.bits.ADRL;
}

/**
 * @brief 配置监控模式使能位
 *
 * @param Module I2C寄存器结构体指针
 * @param State \n
 *          true  -- 任意地址接收数据 \n
 *          false  -- 地址匹配接收数据
 * @retval void
 */
KF_INLINE void I2c_LL_SetMatchAll(I2c_RegisterMap_t *const Module, bool State)
{
    Module->CTL.bits.MENA = State ? 1U : 0U;
}

/**
 * @brief 清除I2C起始信号标志位
 *
 * @param Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @retval void
 */
KF_INLINE void I2c_LL_ClearStartSignalFlag(I2c_RegisterMap_t *const Module)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

    I2c_LL_ClearState(Module, I2C_STATE_SIF);
}

/**
 * @brief 获取起始信号标志位
 *
 * @param Module I2C寄存器结构体指针
 * @retval bool 起始信号标志位 \n
 *                      false -- 总线上未出现起始位 \n
 *                      true -- 总线上出现了起始位
 */
KF_INLINE bool I2c_LL_GetStartSignalFlag(const I2c_RegisterMap_t *const Module)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

    return Module->SR.bits.SIF != 0U;
}

/**
 * @brief 清除I2C停止信号标志位
 *
 * @param Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @retval void
 */
KF_INLINE void I2c_LL_ClearStopSignalFlag(I2c_RegisterMap_t *const Module)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

    I2c_LL_ClearState(Module, I2C_STATE_PIF);
}

/**
 * @brief 获取停止信号标志位
 *
 * @param Module I2C寄存器结构体指针
 * @retval 停止信号标志位 \n
 *                      false -- 总线上未出现停止位 \n
 *                      true -- 总线上出现了停止位
 */
KF_INLINE bool I2c_LL_GetStopSignalFlag(const I2c_RegisterMap_t *const Module)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

    return Module->SR.bits.PIF != 0U;
}

/**
 * @brief 获取地址匹配状态位
 *
 * @param Module I2C寄存器结构体指针
 * @retval 地址匹配状态位 \n
 *                      false -- 从机未收到对应地址 \n
 *                      true -- 从机收到匹配地址且应答
 */
KF_INLINE bool I2c_LL_GetAddrMatchState(const I2c_RegisterMap_t *const Module)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

    return Module->SR.bits.ADDR != 0U;
}

/**
 * @brief 获取高位地址状态位
 *
 * @param Module I2C寄存器结构体指针
 * @retval 高位地址状态位 \n
 *                      false -- 上次接收或发送的字节不是高位地址 \n
 *                      true -- 上次接收或发送的字节是高位地址
 */
KF_INLINE bool I2c_LL_GetHighAddrState(const I2c_RegisterMap_t *const Module)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

    return Module->SR.bits.ADD10 != 0U;
}

/**
 * @brief 获取数据内容状态位
 *
 * @param Module I2C寄存器结构体指针
 * @retval 数据内容状态位，总线上出现起始位将清零该状态位(仅限 I2C 从动模式) \n
 *                      false -- 表示上次接收或发送的字节是地址 \n
 *                      true -- 表示上次接收或发送的字节是数据 \n
 *                      7 位地址下默认为起始位后接收的第 2 个字节开始。十位地址下默认为起始位后接收的第 3 个字节开始
 */
KF_INLINE bool I2c_LL_GetDataState(const I2c_RegisterMap_t *const Module)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

    return Module->SR.bits.DATA != 0U;
}

/**
 * @brief 清除应答错误标志位(该位只对发送方有效)
 *
 * @param Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @retval void
 */
KF_INLINE void I2c_LL_ClearAckFaultFlag(I2c_RegisterMap_t *const Module)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

    I2c_LL_ClearState(Module, I2C_STATE_AFIF);
}

/**
 * @brief 获取应答错误标志位
 *
 * @param Module I2C寄存器结构体指针
 * @retval 应答错误标志位 \n
 *                      false -- 未发生应答错误 \n
 *                      true -- 发生了应答错误 \n
 */
KF_INLINE bool I2c_LL_GetAckFaultFlag(const I2c_RegisterMap_t *const Module)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

    return Module->SR.bits.AFIF != 0U;
}

/**
 * @brief 清除失去仲裁标志位
 *
 * @param Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @retval void
 */
KF_INLINE void I2c_LL_ClearArbitrationLostFlag(I2c_RegisterMap_t *const Module)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

    I2c_LL_ClearState(Module, I2C_STATE_ARBLIF);
}

/**
 * @brief 获取失去仲裁标志位
 *
 * @param Module I2C寄存器结构体指针
 * @retval 仲裁标志位 \n
 *                      false -- 发送数据过程中未失去仲裁 \n
 *                      true -- 发送数据过程中失去仲裁
 */
KF_INLINE bool I2c_LL_GetArbitrationLostFlag(const I2c_RegisterMap_t *const Module)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

    return Module->SR.bits.ARBLIF != 0U;
}

/**
 * @brief 获取读/ 写信息状态位(仅从机) \n
 *                      该位用来保存在上次地址匹配后的 RNW 位信息。此位仅在地址匹配与遇到下一个启动位或停止位之间有效
 *
 * @param Module I2C寄存器结构体指针
 * @retval 信息状态位 \n
 *                      false -- 写 \n
 *                      true -- 读
 */
KF_INLINE bool I2c_LL_GetReadOrWriteState(const I2c_RegisterMap_t *const Module)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

    return Module->SR.bits.RNW != 0U;
}

/**
 * @brief 清除I2C 中断信号标志位，该信号由硬件自动置 1，需要手动清零来继续 I2C 操作
 *
 * @param Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @retval void
 */
KF_INLINE void I2c_LL_ClearIntrSignalFlag(I2c_RegisterMap_t *const Module)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

    I2c_LL_ClearState(Module, I2C_STATE_ISIF);
}

/**
 * @brief 获取I2C 中断信号标志位
 *
 * @param Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @retval 中断信号标志位 \n
 *                      false -- 未产生 I2C 中断信号标志位 \n
 *                      true -- 产生了 I2C 中断信号标志位 \n
 *                       注：需要发送的数据需在 ISIF 置 1 之后写入 I2Cx_BUFR，否则可能导致 TXBE信号错误
 */
KF_INLINE uint8_t I2c_LL_GetIntrSignalFlag(const I2c_RegisterMap_t *const Module)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

    return Module->SR.bits.ISIF;
}

/**
 * @brief 获取接收BUFF为满的标志位
 *
 * @param Module I2C寄存器结构体指针
 * @retval buff状态 \n
 *                      false -- 接收 BUFF 为空 \n
 *                      true -- 接收 BUFF 为满 \n
 *                      注：如果之前接收 BUFF 中有数据没有读出，而此时去写 I2Cx_BUFR 寄存器的话，将清零该位
 */
KF_INLINE bool I2c_LL_GetReceiveBuffFullState(const I2c_RegisterMap_t *const Module)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

    return Module->SR.bits.RCBF != 0U;
}

/**
 * @brief 获取发送 BUFF 状态位，写 I2Cx_BUFR 清零该位
 *
 * @param Module I2C寄存器结构体指针
 * @retval BUFF状态位 \n
 *                      false -- 不需要写 I2Cx_BUFR \n
 *                      true -- 等待写 I2Cx_BUFR \n
 *                      该位只在发送情况下置 1，且需要使能发送或者应答成功
 */
KF_INLINE bool I2c_LL_GetTransmitBuffFullState(const I2c_RegisterMap_t *const Module)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

    return Module->SR.bits.TXBE != 0U;
}

/**
 * @brief 清除I2C 总线错误标志位
 *
 * @param Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @retval void
 */
KF_INLINE void I2c_LL_ClearBusErrorSignalFlag(I2c_RegisterMap_t *const Module)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

    I2c_LL_ClearState(Module, I2C_STATE_BERRIF);
}

/**
 * @brief 获取I2C总线错误标志位
 *
 * @param Module I2C寄存器结构体指针
 * @retval 总线错误标记位 \n
 *                      false -- 未产生 I2C 总线错误 \n
 *                      true -- 产生了 I2C 总线错误
 */
KF_INLINE bool I2c_LL_GetBusErrorSignalFlag(const I2c_RegisterMap_t *const Module)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

    return Module->SR.bits.BERRIF != 0U;
}

/**
 * @brief 获取I2C接收或发送数据溢出标志位(仅限 I2C 从机)
 *
 * @param Module I2C寄存器结构体指针
 * @retval 接收或发送数据溢出标志位 \n
 *                      false -- 未产生 I2C 从机接收或发送数据溢出 \n
 *                      true -- 产生了 I2C 从机接收或发送数据溢出
 */
KF_INLINE bool I2c_LL_GetDataOverflowFlag(const I2c_RegisterMap_t *const Module)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

    return Module->SR.bits.OVERIF != 0U;
}

/**
 * @brief 设置I2C缓存寄存器数据
 *
 * @param Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param Data 发送数据
 * @retval void
 */
KF_INLINE void I2c_LL_SetBufferRegValue(I2c_RegisterMap_t *const Module, uint16_t Data)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));
    KF_I2C_ASSERT(Data < 1024U);

    REG_WRITE(Module->BUFR.bits.I2CBUF, Data);
}

/**
 * @brief 获取I2C接收数据
 *
 * @param Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @retval uint16_t 接收值
 */
KF_INLINE uint16_t I2c_LL_GetBufferRegValue(const I2c_RegisterMap_t *const Module)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

    /* PRQA S 3469 1 #KQR003469 */
    return REG_READ(Module->BUFR.bits.I2CBUF);
}

/**
 * @brief 设置I2C从机地址
 *
 * @param Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param AddrIndex I2C序号 \n
 *                      ADDRESS_INDEX0 \n
 *                      ADDRESS_INDEX1 \n
 *                      ADDRESS_INDEX2 \n
 *                      ADDRESS_INDEX3
 * @param Addr I2C地址值
 * @retval void
 */
KF_INLINE void I2c_LL_SetCompareAddr(I2c_RegisterMap_t *const Module, I2c_AddrIndex_t AddrIndex, uint16_t Addr)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));
    KF_I2C_ASSERT(CHECK_I2C_ADDR_INDEX(AddrIndex));
    KF_I2C_ASSERT(Addr < 1024U);

    if (ADDRESS_INDEX0 == AddrIndex)
    {
        REG_WRITE(Module->ADDR0.bits.I2CADD, Addr);
    }
    else
    {
        REG_WRITE(Module->ADDR[(uint32_t)AddrIndex - (uint32_t)ADDRESS_INDEX1].bits.I2CADD, Addr);
    }
}

/**
 * @brief 设置I2C地址屏蔽位
 *
 * @param Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param AddrIndex I2C序号 \n
 *                      ADDRESS_INDEX0 \n
 *                      ADDRESS_INDEX1 \n
 *                      ADDRESS_INDEX2 \n
 *                      ADDRESS_INDEX3
 * @param Mask 掩码值 \n
 *                      I2CMSK<n> = 0：接收到的地址的第 n 位与 I2CADD<n>比较以检测 I2C 的地址匹配情况 \n
 *                      I2CMSK<n> = 1：接收到的地址的第 n 位不用于检测 I2C 的地址匹配情况
 * @retval void
 */
KF_INLINE void I2c_LL_SetCompareMask(I2c_RegisterMap_t *const Module, I2c_AddrIndex_t AddrIndex, uint16_t Mask)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));
    KF_I2C_ASSERT(CHECK_I2C_ADDR_INDEX(AddrIndex));
    KF_I2C_ASSERT(Mask < 1024U);

    if (ADDRESS_INDEX0 == AddrIndex)
    {
        REG_WRITE(Module->ADDR0.bits.I2CMSK, Mask);
    }
    else
    {
        REG_WRITE(Module->ADDR[(uint32_t)AddrIndex - (uint32_t)ADDRESS_INDEX1].bits.I2CMSK, Mask);
    }
}

/**
 * @brief 设置I2C波特率
 *
 * @param Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param BrandRateLow SCL 低电平占用的时钟周期数
 * @param BrandRateHigh SCL 高电平占用的时钟周期数
 * @retval void
 */
KF_INLINE void I2c_LL_SetBaudRate(I2c_RegisterMap_t *const Module, uint16_t BrandRateLow, uint16_t BrandRateHigh)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

    REG_WRITE(Module->BRGR.bits.I2CBRGL, BrandRateLow);
    REG_WRITE(Module->BRGR.bits.I2CBRGH, BrandRateHigh);
}

/**
 * @brief 使能I2C中断
 * @param Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param IEMask I2c_IntrMask_t \n
 *                      I2C_IE_SIE \n
 *                      I2C_IE_PIE \n
 *                      I2C_IE_AFIE \n
 *                      I2C_IE_ARBLIE \n
 *                      I2C_IE_ISIE \n
 *                      I2C_IE_BLTIE \n
 *                      I2C_IE_BERRIE \n
 *                      I2C_IE_OVERIE
 * @retval void
 */
KF_INLINE void I2c_LL_SetIntrEnabled(I2c_RegisterMap_t *const Module, I2c_IntrMask_t IEMask)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

    REG_BIT_SET(Module->IER.reg, (uint32_t)IEMask);
}

/**
 * @brief 获取I2C中断使能状态
 * @param Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param IEMask I2c_IntrMask_t
 * @retval void
 */
KF_INLINE bool I2c_LL_GetIntrEnabledState(const I2c_RegisterMap_t *const Module, I2c_IntrMask_t IEMask)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

    /* PRQA S 3469 1 #KQR003469 */
    return REG_BIT_BOOLED(Module->IER.reg, (uint32_t)IEMask);
}

/**
 * @brief 关闭I2C中断
 * @param Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param IEMask I2c_IntrMask_t \n
 *                      I2C_IE_SIE \n
 *                      I2C_IE_PIE \n
 *                      I2C_IE_AFIE \n
 *                      I2C_IE_ARBLIE \n
 *                      I2C_IE_SMBAIE \n
 *                      I2C_IE_SMBHIE \n
 *                      I2C_IE_SMBDIE \n
 *                      I2C_IE_ISIE \n
 *                      I2C_IE_BLTIE \n
 *                      I2C_IE_BERRIE \n
 *                      I2C_IE_OVERIE
 * @retval void
 */
KF_INLINE void I2c_LL_SetIntrDisable(I2c_RegisterMap_t *const Module, I2c_IntrMask_t IEMask)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

    REG_BIT_CLR(Module->IER.reg, (uint32_t)IEMask);
}

/**
 * @brief 获取I2c状态
 *
 * @param Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param StateMask I2c_StateMask_t \n
 *                      I2C_STATE_SIE \n
 *                      I2C_STATE_PIE \n
 *                      I2C_STATE_ADDR \n
 *                      I2C_STATE_ADD10 \n
 *                      I2C_STATE_DATA \n
 *                      I2C_STATE_AFIE \n
 *                      I2C_STATE_ARBLIE \n
 *                      I2C_STATE_RW \n
 *                      I2C_STATE_SMBAIE \n
 *                      I2C_STATE_SMBHIE \n
 *                      I2C_STATE_SMBDIE \n
 *                      I2C_STATE_ISIE \n
 *                      I2C_STATE_RCBF \n
 *                      I2C_STATE_TXBE \n
 *                      I2C_STATE_BLTF \n
 *                      I2C_STATE_BERRIF \n
 *                      I2C_STATE_OVERIF
 *                      I2C_STATE_BUSY
 * @retval 状态位 \n
 *                      false -- 未产生标记位 \n
 *                      true -- 产生标记位
 */
KF_INLINE bool I2c_LL_GetState(const I2c_RegisterMap_t *const Module, I2c_StateMask_t StateMask)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

    /* PRQA S 3469 1 #KQR003469 */
    return (REG_BIT_BOOLED(Module->SR.reg, (uint32_t)StateMask));
}

/**
 * @brief 清除SR状态寄存器
 *
 * @param Module 指向I2C内存结构的指针
 * @param StateMask 标志寄存器掩码
 * @retval void
 */
KF_INLINE void I2c_LL_ClearState(I2c_RegisterMap_t *const Module, I2c_StateMask_t StateMask)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

    Module->SR.reg = ~((uint32_t)StateMask ^ (uint32_t)I2C_STATE_BLTF);
    NOP();
    NOP();
    NOP();
    NOP();
}

/**
 * @brief 设置 SDA 引脚低电平超时检测使能状态
 *
 * @param Module I2C寄存器结构体指针
 * @param Enable 使能状态
 * @retval void
 */
KF_INLINE void I2c_LL_SetSdaLowLevelDetectionEnabled(I2c_RegisterMap_t *const Module, bool Enable)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

    Module->IER.bits.SDATEN = Enable ? 1U : 0U;
}

/**
 * @brief 设置I2C总线低电平持续时间
 *
 * @param Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param TimeOut 超时时间
 * @retval void
 */
KF_INLINE void I2c_LL_SetBusLowLevelTimeOut(I2c_RegisterMap_t *const Module, uint16_t TimeOut)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));
    KF_I2C_ASSERT(TimeOut < 4096U);

    REG_WRITE(Module->IER.bits.BUSLOW, TimeOut);
}

/**
 * @brief 获取I2c中断发生状态
 *
 * @param Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 * @param StateMask I2c_StateMask_t \n
 *                      I2C_INTR_SIE    \n
 *                      I2C_INTR_PIE    \n
 *                      I2C_INTR_AFIE   \n
 *                      I2C_INTR_ARBLIE \n
 *                      I2C_INTR_ISIE   \n
 *                      I2C_INTR_BLTIE  \n
 *                      I2C_INTR_BERRIE \n
 *                      I2C_INTR_OVERIE \n
 * @retval bool 中断发生状态
 *         true    发生了中断, 且已使能
 *         false    未发生中断, 或未使能
 */
KF_INLINE bool I2c_LL_GetIntrState(const I2c_RegisterMap_t *const Module, I2c_IntrState_t StateMask)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

    /* PRQA S 3469 ++ #KQR003469 */
    bool flag  = REG_BIT_BOOLED(Module->SR.reg, (uint32_t)StateMask) ? true : false;
    bool state = REG_BIT_BOOLED(Module->IER.reg, (uint32_t)StateMask) ? true : false;
    /* PRQA S 3469 -- #KQR003469 */
    return flag && state;
}

/**
 * @brief 获取I2C停止条件使能位(仅限 I2C 主控模式)
 *
 * @param Module 指向I2C内存结构的指针,取值为I2C0~I2C3
 *
 * @retval bool 停止状态 \n
 *                      false -- 停止条件空闲 \n
 *                      true --  在 SDA 和 SCL 引脚启动停止条件。
 */
KF_INLINE bool I2c_LL_GetStopConditionState(const I2c_RegisterMap_t *const Module)
{
    KF_I2C_ASSERT(CHECK_I2C_ALL_PERIPH_ADDR(Module));

    return Module->CTL.bits.PEN != 0U;
}

#ifdef __cplusplus
}
#endif /*End of __cplusplus*/
#endif /*End of KF32A158SF_DRV_I2C_H*/
/* EOF */
