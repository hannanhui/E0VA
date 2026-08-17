/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name        : kf32a158sf_drv_ccp.h
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
#ifndef KF32A158SF_DRV_CCP_H
#define KF32A158SF_DRV_CCP_H

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
/* PRQA S 3473 EOF #KQR003473 */
/******************************************************************************
 *                      Include Files
 ******************************************************************************/
#include <stdint.h>
#include <stdbool.h>
#include "kf_types.h"
#include "kf32a158sf_reg_ccp.h"

#ifdef KF_DRV_CCP_ASSERT
#include "dev_assert.h"
#define KF_CCP_ASSERT(x) KF_DEV_ASSERT(x)
#else
#define KF_CCP_ASSERT(x) ((void)0U)
#endif
/******************************************************************************
 *                      Macro or Inline
 ******************************************************************************/

/******************************************************************************
 *                      Type definitions
 ******************************************************************************/
typedef enum
{
    CCP_CHANNEL_INDEX1,
    CCP_CHANNEL_INDEX2,
    CCP_CHANNEL_INDEX3,
    CCP_CHANNEL_INDEX4
} Ccp_ChannelIndex_t;

/**
 * @brief  ccp channel index check
 */
#define CHECK_CCP_CHANNEL_INDEX(CHANNEL)                                                                               \
    (((CHANNEL) == CCP_CHANNEL_INDEX1) || ((CHANNEL) == CCP_CHANNEL_INDEX2) || ((CHANNEL) == CCP_CHANNEL_INDEX3) ||    \
     ((CHANNEL) == CCP_CHANNEL_INDEX4))

typedef enum
{
    CCP_COMPARE_INDEX_1 = 0x0U,
    CCP_COMPARE_INDEX_2,
    CCP_COMPARE_INDEX_3,
    CCP_COMPARE_INDEX_4,
} Ccp_CompareIndex_t;
#define CHECK_CCP_COMPARE_INDEX(INDEX) ((uint32_t)(INDEX) <= (uint32_t)CCP_COMPARE_INDEX_4)

typedef enum
{
    CCP_TXCK_PIN_TXCK = 0x0U,
    CCP_TXCK_PIN_GTXCK_1,
    CCP_TXCK_PIN_GTXCK_2,
    CCP_TXCK_PIN_GTXCK_3,
} Ccp_TxckPin_t;
#define CHECK_CCP_TXCK_PIN(PIN) ((uint32_t)(PIN) <= (uint32_t)CCP_TXCK_PIN_GTXCK_3)

typedef enum
{
    CCP_OUTPUT_PWM_ACTIVE = 0x0U,
    CCP_OUTPUT_PWM_INACTIVE,
    CCP_OUTPUT_FORCE_INACTIVE,
    CCP_OUTPUT_FORCE_ACTIVE,
} Ccp_PwmOutput_t;
#define CHECK_CCP_PWM_OUTPUT(SEL) ((uint32_t)(SEL) <= (uint32_t)CCP_OUTPUT_FORCE_ACTIVE)

/** CCP工作模式 */
typedef enum
{
    CCP_MODE_CLOSE                = 0x0U,
    CCP_MODE_CMP_TOGGLE           = 0x2U,
    CCP_MODE_CAP_EVERY_FALL_DEDG  = 0x4U,
    CCP_MODE_CAP_EVERY_RAISE_DEDG = 0x5U,
    CCP_MODE_CAP_4_RAISE_DEDG     = 0x6U,
    CCP_MODE_CAP_16_RAISE_DEDG    = 0x7U,
    CCP_MODE_CMP_ACTIVE_LEVEL     = 0x8U,
    CCP_MODE_CMP_INACTIVE_LEVEL   = 0x9U,
    CCP_MODE_CMP_GEN_INT          = 0xAU,
    CCP_MODE_CMP_GEN_EVENT        = 0xBU,
    CCP_MODE_PWM                  = 0xCU,
} Ccp_Mode_t;
#define CHECK_CCP_MODE(CCP)                                                                                            \
    (((CCP) == CCP_MODE_CLOSE) || ((CCP) == CCP_MODE_CMP_TOGGLE) || ((CCP) == CCP_MODE_CAP_EVERY_FALL_DEDG) ||         \
     ((CCP) == CCP_MODE_CAP_EVERY_RAISE_DEDG) || ((CCP) == CCP_MODE_CAP_4_RAISE_DEDG) ||                               \
     ((CCP) == CCP_MODE_CAP_16_RAISE_DEDG) || ((CCP) == CCP_MODE_CMP_ACTIVE_LEVEL) ||                                  \
     ((CCP) == CCP_MODE_CMP_INACTIVE_LEVEL) || ((CCP) == CCP_MODE_CMP_GEN_INT) || ((CCP) == CCP_MODE_CMP_GEN_EVENT) || \
     ((CCP) == CCP_MODE_PWM))

/** CCP中断 */
typedef enum
{
    CCP_INT_CH1 = 0x0U,
    CCP_INT_CH2,
    CCP_INT_CH3,
    CCP_INT_CH4,
    CCP_INT_TX_TRIG_EVENT,
    CCP_INT_TX_UPDATE_EVENT,
} Ccp_IntIndex_t;
#define CHECK_CCP_INT(INT)                                                                                             \
    (((INT) == CCP_INT_CH1) || ((INT) == CCP_INT_CH2) || ((INT) == CCP_INT_CH3) || ((INT) == CCP_INT_CH4) ||           \
     ((INT) == CCP_INT_TX_TRIG_EVENT) || ((INT) == CCP_INT_TX_UPDATE_EVENT))

/** CCP DMA请求 */
typedef enum
{
    CCP_DMA_TX_UPDATE_EVENT = 0x0U,
    CCP_DMA_CH1,
    CCP_DMA_CH2,
    CCP_DMA_CH3,
    CCP_DMA_CH4,
    CCP_DMA_TX_TRIG_EVENT,
} Ccp_DmaIndex_t;
#define CHECK_CCP_DMA(DMA)                                                                                             \
    (((DMA) == CCP_DMA_CH1) || ((DMA) == CCP_DMA_CH2) || ((DMA) == CCP_DMA_CH3) || ((DMA) == CCP_DMA_CH4) ||           \
     ((DMA) == CCP_DMA_TX_TRIG_EVENT) || ((DMA) == CCP_DMA_TX_UPDATE_EVENT))
/******************************************************************************
 *                      Export Variables
 ******************************************************************************/

/******************************************************************************
 *                      Export Functions
 ******************************************************************************/

/**
 * @brief 获取CCP捕捉寄存器的值
 *
 * @param Module 指向CCP内存结构的指针 \n
 *              取值为CCP0_PTR ~ CCP4_PTR, CCP20_PTR ~ CCP21_PTR
 * @param CcpChannel CCP通道序号 \n
 *              取值为CCP_CHANNEL_INDEX1 ~ CCP_CHANNEL_INDEX4
 * @retval uint32_t
 */
KF_INLINE uint32_t Ccp_LL_GetCaptureValue(const Ccp_RegisterMap_t *Module, Ccp_ChannelIndex_t CcpChannel)
{
    KF_CCP_ASSERT(CHECK_CCP_ALL_PERIPH_ADDR(Module));
    KF_CCP_ASSERT(CHECK_CCP_CHANNEL_INDEX(CcpChannel));

    const volatile uint32_t *kpTmpReg = NULL;
    uint32_t                 ret;

    kpTmpReg = (volatile uint32_t *)((uint32_t)&Module->CCP_C1 + (4U * (uint32_t)CcpChannel));
    if ((CCP20_PTR == Module) || (CCP21_PTR == Module))
    {
        ret = *kpTmpReg;
    }
    else
    {
        ret = (*kpTmpReg & 0x0000FFFFU);
    }

    return ret;
}

/**
 * @brief 获取CCP触发DMA请求标志
 *
 * @param Module 指向CCP内存结构的指针 \n
 *              取值为CCP0_PTR ~ CCP4_PTR, CCP20_PTR ~ CCP21_PTR
 * @param DmaIndex DMA请求序号
 * @retval bool 标志状态 \n
 *              true -- 更新事件触发DMA \n
 *              false -- 无更新事件触发DMA
 */
KF_INLINE bool Ccp_LL_GetTrigDmaFlag(const Ccp_RegisterMap_t *Module, Ccp_DmaIndex_t DmaIndex)
{
    uint32_t flag_bit_pos;
    KF_CCP_ASSERT(CHECK_CCP_ALL_PERIPH_ADDR(Module));
    KF_CCP_ASSERT(CHECK_CCP_DMA(DmaIndex));

    /*
     * 注意: DMA标志位(CCPx_DF)与DMA使能位(CCPx_CTL3)的位序不完全对应
     * Ccp_DmaIndex_t       -> CCPx_DF bit
     * CCP_DMA_TX_UPDATE_EVENT (0) -> TXUDF (5)
     * CCP_DMA_CH1             (1) -> CC1DF (0)
     * CCP_DMA_CH2             (2) -> CC2DF (1)
     * CCP_DMA_CH3             (3) -> CC3DF (2)
     * CCP_DMA_CH4             (4) -> CC4DF (3)
     * CCP_DMA_TX_TRIG_EVENT   (5) -> TXTDF (4)
     */
    switch (DmaIndex)
    {
    case CCP_DMA_TX_UPDATE_EVENT:
        flag_bit_pos = 5U;
        break;
    case CCP_DMA_CH1:
    case CCP_DMA_CH2:
    case CCP_DMA_CH3:
    case CCP_DMA_CH4:
        flag_bit_pos = (uint32_t)DmaIndex - 1U;
        break;
    case CCP_DMA_TX_TRIG_EVENT:
        flag_bit_pos = 4U;
        break;
    default:
        flag_bit_pos = 0U; /* Should not happen */
        break;
    }

    /* PRQA S 3469 1 #KQR003469 */
    return (REG_BITS_READ(Module->CCP_DF.reg, (0x1UL << flag_bit_pos), flag_bit_pos) != 0U);
}

/**
 * @brief 设置CCP通道模式
 *
 * @param Module 指向CCP内存结构的指针 \n
 *              取值为CCP0_PTR ~ CCP4_PTR, CCP20_PTR ~ CCP21_PTR
 * @param CcpChannel CCP通道序号
 * @param Mode CCP模式
 * @retval void
 */
KF_INLINE void Ccp_LL_SetChannelMode(Ccp_RegisterMap_t *Module, Ccp_ChannelIndex_t CcpChannel, Ccp_Mode_t Mode)
{
    uint32_t Mask;
    uint32_t Value;

    KF_CCP_ASSERT(CHECK_CCP_ALL_PERIPH_ADDR(Module));
    KF_CCP_ASSERT(CHECK_CCP_CHANNEL_INDEX(CcpChannel));
    KF_CCP_ASSERT(CHECK_CCP_MODE(Mode));

    Mask  = (uint32_t)0x0FUL << ((uint32_t)CcpChannel << 2U);
    Value = (uint32_t)Mode << ((uint32_t)CcpChannel << 2U);

    REG_BITS_WRITE(Module->CCP_CTL1.reg, Mask, Value);
}

/**
 * @brief 获取CCP通道模式
 *
 * @param Module 指向CCP内存结构的指针 \n
 *              取值为CCP0_PTR ~ CCP4_PTR, CCP20_PTR ~ CCP21_PTR
 * @param CcpChannel CCP通道序号
 * @retval uint32_t CCP通道模式(CHyM)
 */
KF_INLINE uint32_t Ccp_LL_ReadChannelMode(const Ccp_RegisterMap_t *Module, Ccp_ChannelIndex_t CcpChannel)
{
    uint32_t Mask;
    uint32_t Value;

    KF_CCP_ASSERT(CHECK_CCP_ALL_PERIPH_ADDR(Module));
    KF_CCP_ASSERT(CHECK_CCP_CHANNEL_INDEX(CcpChannel));

    Mask  = (uint32_t)0x0FUL << ((uint32_t)CcpChannel * 4U);
    Value = (uint32_t)CcpChannel * 4U;

    /* PRQA S 3469 1 #KQR003469 */
    return REG_BITS_READ(Module->CCP_CTL1.reg, Mask, Value);
}

/**
 * @brief 设置比较/PWM占空比寄存器
 *
 * @param Module 指向CCP内存结构的指针 \n
 *              取值为CCP0_PTR ~ CCP4_PTR, CCP20_PTR ~ CCP21_PTR
 * @param CcpChannel CCP通道
 * @param CompareValue 比较指
 * @retval void
 */
KF_INLINE void Ccp_LL_SetCompareResult(Ccp_RegisterMap_t *Module, Ccp_ChannelIndex_t CcpChannel, uint32_t CompareValue)
{
    KF_CCP_ASSERT(CHECK_CCP_ALL_PERIPH_ADDR(Module));
    KF_CCP_ASSERT(CHECK_CCP_CHANNEL_INDEX(CcpChannel));

    switch (CcpChannel)
    {
    case CCP_CHANNEL_INDEX1: {
        if ((CCP20_PTR == Module) || (CCP21_PTR == Module))
        {
            REG_WRITE(Module->CCP_R1.reg, CompareValue);
        }
        else
        {
            REG_WRITE(Module->CCP_R1.bits.CCPXRY, CompareValue);
        }
        break;
    }
    case CCP_CHANNEL_INDEX2: {
        if ((CCP20_PTR == Module) || (CCP21_PTR == Module))
        {
            REG_WRITE(Module->CCP_R2.reg, CompareValue);
        }
        else
        {
            REG_WRITE(Module->CCP_R2.bits.CCPXRY, CompareValue);
        }
        break;
    }
    case CCP_CHANNEL_INDEX3: {
        if ((CCP20_PTR == Module) || (CCP21_PTR == Module))
        {
            REG_WRITE(Module->CCP_R3.reg, CompareValue);
        }
        else
        {
            REG_WRITE(Module->CCP_R3.bits.CCPXRY, CompareValue);
        }
        break;
    }
    case CCP_CHANNEL_INDEX4: {
        if ((CCP20_PTR == Module) || (CCP21_PTR == Module))
        {
            REG_WRITE(Module->CCP_R4.reg, CompareValue);
        }
        else
        {
            REG_WRITE(Module->CCP_R4.bits.CCPXRY, CompareValue);
        }
        break;
    }
    default:
        KF_CCP_ASSERT(false);
        break;
    }
}

/**
 * @brief 设置输出比较/PWM信号清零使能状态
 *
 * @param Module 指向CCP内存结构的指针 \n
 *              取值为CCP0_PTR ~ CCP4_PTR, CCP20_PTR ~ CCP21_PTR
 * @param CcpChannel CCP通道序号 \n
 *              取值为CCP_CHANNEL_INDEX1 ~ CCP_CHANNEL_INDEX4
 * @param EnableSta 使能状态 \n
 *              true -- 使能 \n
 *              false -- 禁止
 * @retval void
 */
KF_INLINE void
Ccp_LL_SetOutputSignalClearEnabled(Ccp_RegisterMap_t *Module, Ccp_ChannelIndex_t CcpChannel, bool EnableSta)
{
    uint32_t Mask;
    KF_CCP_ASSERT(CHECK_CCP_ALL_PERIPH_ADDR(Module));

    Mask = 12U + (uint32_t)CcpChannel;
    REG_BITS_WRITE(Module->CCP_CTL2.reg, 0x1UL << Mask, (EnableSta ? 1UL : 0UL) << Mask);
}

/**
 * @brief 选择比较器检测
 *
 * @param Module 指向CCP内存结构的指针 \n
 *              取值为CCP0_PTR ~ CCP4_PTR, CCP20_PTR ~ CCP21_PTR
 * @param CompareIndex 比较器序号 \n
 *              取值为 CCP_COMPARE_INDEX_1 ~ CCP_COMPARE_INDEX_4
 * @retval void
 */
KF_INLINE void Ccp_LL_SelectCompareDetect(Ccp_RegisterMap_t *Module, Ccp_CompareIndex_t CompareIndex)
{
    KF_CCP_ASSERT(CHECK_CCP_ALL_PERIPH_ADDR(Module));
    KF_CCP_ASSERT(CHECK_CCP_COMPARE_INDEX(CompareIndex));

    Module->CCP_CTL2.bits.PXASS = (uint32_t)CompareIndex;
}

/**
 * @brief 选择TXCK引脚
 *
 * @param Module 指向CCP内存结构的指针 \n
 *              取值为CCP0_PTR ~ CCP4_PTR, CCP20_PTR ~ CCP21_PTR
 * @param TxckPin TxCK引脚 \n
 *              取值为  \n
 *              CCP_TXCK_PIN_TXCK \n
 *              CCP_TXCK_PIN_GTXCK_1 \n
 *              CCP_TXCK_PIN_GTXCK_2 \n
 *              CCP_TXCK_PIN_GTXCK_3
 * @retval void
 */
KF_INLINE void Ccp_LL_SelectTxckPin(Ccp_RegisterMap_t *Module, Ccp_TxckPin_t TxckPin)
{
    KF_CCP_ASSERT(CHECK_CCP_ALL_PERIPH_ADDR(Module));
    KF_CCP_ASSERT(CHECK_CCP_TXCK_PIN(TxckPin));

    Module->CCP_CTL2.bits.TCKSEL = (uint32_t)TxckPin;
}

/**
 * @brief 设置CCP输出控制
 *
 * @param Module 指向CCP内存结构的指针 \n
 *              取值为CCP0_PTR ~ CCP4_PTR, CCP20_PTR ~ CCP21_PTR
 * @param CcpChannel  CCP通道序号 \n
 *              取值为CCP_CHANNEL_INDEX1 ~ CCP_CHANNEL_INDEX4
 * @param PwmOutput CCP输出 \n
 *              取值为 \n
 *              CCP_OUTPUT_PWM_ACTIVE \n
 *              CCP_OUTPUT_PWM_INACTIVE \n
 *              CCP_OUTPUT_FORCE_INACTIVE \n
 *              CCP_OUTPUT_FORCE_ACTIVE
 * @retval void
 */
KF_INLINE void Ccp_LL_SetOutputCtrl(Ccp_RegisterMap_t *Module, Ccp_ChannelIndex_t CcpChannel, Ccp_PwmOutput_t PwmOutput)
{
    uint32_t Mask;
    KF_CCP_ASSERT(CHECK_CCP_ALL_PERIPH_ADDR(Module));
    KF_CCP_ASSERT(CHECK_CCP_CHANNEL_INDEX(CcpChannel));
    KF_CCP_ASSERT(CHECK_CCP_PWM_OUTPUT(PwmOutput));

    Mask = 2U * (uint32_t)CcpChannel;
    REG_BITS_WRITE(Module->CCP_CTL2.reg, (0x3UL << Mask), ((uint32_t)PwmOutput << Mask));
}

/**
 * @brief 清除CCP中断标志
 *
 * @param Module 指向CCP内存结构的指针 \n
 *              取值为CCP0_PTR ~ CCP4_PTR, CCP20_PTR ~ CCP21_PTR
 * @param IntIndex 中断序号
 * @retval void
 */
KF_INLINE void Ccp_LL_ClearIntrFlag(Ccp_RegisterMap_t *Module, Ccp_IntIndex_t IntIndex)
{
    KF_CCP_ASSERT(CHECK_CCP_ALL_PERIPH_ADDR(Module));
    KF_CCP_ASSERT(CHECK_CCP_INT(IntIndex));

    REG_BIT_SET(Module->CCP_SRIC.reg, (0x1UL << (uint32_t)IntIndex));
    NOP();
    NOP();
    NOP();
    NOP();
    REG_BIT_CLR(Module->CCP_SRIC.reg, (0x1UL << (uint32_t)IntIndex));
}

/**
 * @brief 清除CCP所有中断标志
 *
 * @param Module 指向CCP内存结构的指针 \n
 *              取值为CCP0_PTR ~ CCP4_PTR, CCP20_PTR ~ CCP21_PTR
 */
KF_INLINE void Ccp_LL_ClearAllIntrFlag(Ccp_RegisterMap_t *Module)
{
    uint32_t Mask = (uint32_t)0x0FU;

    KF_CCP_ASSERT(CHECK_CCP_ALL_PERIPH_ADDR(Module));

    REG_BIT_SET(Module->CCP_SRIC.reg, Mask);
    NOP();
    NOP();
    NOP();
    NOP();
    REG_BIT_CLR(Module->CCP_SRIC.reg, Mask);
}

/**
 * @brief 清除Tx溢出中断标志
 *
 * @param Module 指向CCP内存结构的指针 \n
 *              取值为CCP0_PTR ~ CCP4_PTR, CCP20_PTR ~ CCP21_PTR
 * @retval void
 */
KF_INLINE void Ccp_LL_ClearTxOverFlowIntrFlag(Ccp_RegisterMap_t *Module)
{
    KF_CCP_ASSERT(CHECK_CCP_ALL_PERIPH_ADDR(Module));

    Module->CCP_SRIC.bits.TXIC = 1U;
    NOP();
    NOP();
    NOP();
    NOP();
    Module->CCP_SRIC.bits.TXIC = 0U;
}

/**
 * @brief 设置Tx溢出中断标志
 *
 * @param Module 指向CCP内存结构的指针 \n
 *              取值为CCP0_PTR ~ CCP4_PTR, CCP20_PTR ~ CCP21_PTR
 * @retval void
 */
KF_INLINE void Ccp_LL_SetTxOverFlowIntrFlag(Ccp_RegisterMap_t *Module)
{
    KF_CCP_ASSERT(CHECK_CCP_ALL_PERIPH_ADDR(Module));

    Module->CCP_SRIC.bits.TXIC = 1U;
}

/**
 * @brief 选择1/2通道作为PWM测量时输入信号
 *
 * @param Module 指向CCP内存结构的指针 \n
 *              取值为CCP0_PTR ~ CCP4_PTR, CCP20_PTR ~ CCP21_PTR
 * @param CcpChannel CCP通道序号 \n
 * @return void
 */
KF_INLINE void Ccp_LL_SelectChannel12InputSignal(Ccp_RegisterMap_t *Module, Ccp_ChannelIndex_t CcpChannel)
{
    KF_CCP_ASSERT(CHECK_CCP_ALL_PERIPH_ADDR(Module));
    KF_CCP_ASSERT(CHECK_CCP_CHANNEL_INDEX(CcpChannel));

    Module->CCP_CTL4.bits.CH_SEL1 = (uint32_t)CcpChannel;
}

/**
 * @brief 选择3/4通道作为PWM测量时输入信号
 *
 * @param Module 指向CCP内存结构的指针 \n
 *              取值为CCP0_PTR ~ CCP4_PTR, CCP20_PTR ~ CCP21_PTR
 * @param CcpChannel CCP通道序号 \n
 * @return void
 */
KF_INLINE void Ccp_LL_SelectChannel34InputSignal(Ccp_RegisterMap_t *Module, Ccp_ChannelIndex_t CcpChannel)
{
    KF_CCP_ASSERT(CHECK_CCP_ALL_PERIPH_ADDR(Module));
    KF_CCP_ASSERT(CHECK_CCP_CHANNEL_INDEX(CcpChannel));

    uint32_t tempChannel = (uint32_t)CcpChannel;

    if (CcpChannel <= CCP_CHANNEL_INDEX2)
    {
        tempChannel += 1U;
    }
    else if (CcpChannel == CCP_CHANNEL_INDEX3)
    {
        tempChannel = 0U;
    }
    else
    { /**Empty */
    }

    Module->CCP_CTL4.bits.CH_SEL2 = tempChannel;
}

/**
 * @brief 设置PWM输入测量模式(CH3/4)使能状态
 *
 * @param Module 指向CCP内存结构的指针 \n
 *              取值为CCP0_PTR ~ CCP4_PTR, CCP20_PTR ~ CCP21_PTR
 * @param EnableSta 使能状态 \n
 *              true -- 使能 PWM 输入测量模式 \n
 *              false -- 不使能
 * @retval void
 */
KF_INLINE void Ccp_LL_SetPwmMeasurement1Enabled(Ccp_RegisterMap_t *Module, bool EnableSta)
{
    KF_CCP_ASSERT(CHECK_CCP_ALL_PERIPH_ADDR(Module));

    Module->CCP_CTL4.bits.PXPWMI1 = EnableSta ? 1U : 0U;
}

/**
 * @brief 设置CCP中断使能状态
 *
 * @param Module 指向CCP内存结构的指针 \n
 *              取值为CCP0_PTR ~ CCP4_PTR, CCP20_PTR ~ CCP21_PTR
 * @param IntIndex 中断序号, 取值见枚举 Ccp_IntIndex_t
 * @param EnableSta 使能状态
 * @retval void
 */
KF_INLINE void Ccp_LL_SetIntrEnabled(Ccp_RegisterMap_t *Module, Ccp_IntIndex_t IntIndex, bool EnableSta)
{
    KF_CCP_ASSERT(CHECK_CCP_ALL_PERIPH_ADDR(Module));
    KF_CCP_ASSERT(CHECK_CCP_INT(IntIndex));

    REG_BITS_WRITE(
        Module->CCP_CTL3.reg, (0x1UL << (uint32_t)IntIndex), ((EnableSta ? 1UL : 0UL) << (uint32_t)IntIndex));
}

/**
 * @brief 获取CCP中断使能状态
 *
 * @param Module 指向CCP内存结构的指针 \n
 *              取值为CCP0_PTR ~ CCP4_PTR, CCP20_PTR ~ CCP21_PTR
 * @param IntIndex 中断序号, 取值见枚举 Ccp_IntIndex_t
 * @retval bool
 */
KF_INLINE bool Ccp_LL_GetIntrEnabledState(const Ccp_RegisterMap_t *Module, Ccp_IntIndex_t IntIndex)
{
    KF_CCP_ASSERT(CHECK_CCP_ALL_PERIPH_ADDR(Module));
    KF_CCP_ASSERT(CHECK_CCP_INT(IntIndex));

    /* PRQA S 3469 1 #KQR003469 */
    return (REG_BITS_READ(Module->CCP_CTL3.reg, (0x1UL << (uint32_t)IntIndex), (uint32_t)IntIndex) != 0U);
}

/**
 * @brief 选择单脉冲输出模式
 *
 * @param Module 指向CCP内存结构的指针 \n
 *              取值为CCP0_PTR ~ CCP4_PTR, CCP20_PTR ~ CCP21_PTR
 * @param EnableSta 使能状态 \n
 *              true -- 单脉冲输出后关闭定时器使能位 \n
 *              false -- 单脉冲输出后不关闭定时器使能位
 * @retval void
 */
KF_INLINE void Ccp_LL_SelectSinglePluseOutputMode(Ccp_RegisterMap_t *Module, bool SelectSta)
{
    KF_CCP_ASSERT(CHECK_CCP_ALL_PERIPH_ADDR(Module));

    Module->CCP_CTL3.bits.PXSPMST = SelectSta ? 1U : 0U;
}

/**
 * @brief 设置PWM输入测量模式使能状态
 *
 * @param Module 指向CCP内存结构的指针 \n
 *              取值为CCP0_PTR ~ CCP4_PTR, CCP20_PTR ~ CCP21_PTR
 * @param EnableSta 使能状态 \n
 *              true -- 使能 PWM 输入测量模式 \n
 *              false -- 不使能
 * @retval void
 */
KF_INLINE void Ccp_LL_SetPwmMeasurementEnabled(Ccp_RegisterMap_t *Module, bool EnableSta)
{
    KF_CCP_ASSERT(CHECK_CCP_ALL_PERIPH_ADDR(Module));

    Module->CCP_CTL3.bits.PXPWMI = EnableSta ? 1U : 0U;
}

/**
 * @brief 设置输入异或使能状态
 *
 * @param Module 指向CCP内存结构的指针 \n
 *              取值为CCP0_PTR ~ CCP4_PTR, CCP20_PTR ~ CCP21_PTR
 * @param EnableSta 使能状态 \n
 *              true -- 使能输入异或 \n
 *              false -- 不使能
 * @retval void
 */
KF_INLINE void Ccp_LL_SetInputXorEnabled(Ccp_RegisterMap_t *Module, bool EnableSta)
{
    KF_CCP_ASSERT(CHECK_CCP_ALL_PERIPH_ADDR(Module));

    Module->CCP_CTL3.bits.PXXORM = EnableSta ? 1U : 0U;
}

/**
 * @brief 单脉冲输出模式
 *
 * @param Module 指向CCP内存结构的指针 \n
 *              取值为CCP0_PTR ~ CCP4_PTR, CCP20_PTR ~ CCP21_PTR
 * @param EnableSta 使能状态 \n
 *              true -- 使能单脉冲输出模式 \n
 *              false -- 不使能
 * @retval void
 */
KF_INLINE void Ccp_LL_SetSinglePluseOutputEnabled(Ccp_RegisterMap_t *Module, bool EnableSta)
{
    KF_CCP_ASSERT(CHECK_CCP_ALL_PERIPH_ADDR(Module));

    Module->CCP_CTL3.bits.PXSPM = EnableSta ? 1U : 0U;
}

/**
 * @brief 设置CCP请求DMA使能状态
 *
 * @param Module 指向CCP内存结构的指针 \n
 *              取值为CCP0_PTR ~ CCP4_PTR, CCP20_PTR ~ CCP21_PTR
 * @param DmaIndex CCP DMA请求序号,取值见枚举 Ccp_DmaIndex_t
 * @param EnableSta 使能状态 \n
 *              true -- 使能 \n
 *              false -- 禁止
 * @retval void
 */
KF_INLINE void Ccp_LL_SetDmaRequestEnabled(Ccp_RegisterMap_t *Module, Ccp_DmaIndex_t DmaIndex, bool EnableSta)
{
    uint32_t Mask = 0U;
    KF_CCP_ASSERT(CHECK_CCP_ALL_PERIPH_ADDR(Module));
    KF_CCP_ASSERT(CHECK_CCP_DMA(DmaIndex));

    Mask = 6U + (uint32_t)DmaIndex;
    REG_BITS_WRITE(Module->CCP_CTL3.reg, (0x1UL << Mask), ((EnableSta ? 1UL : 0UL) << Mask));
}

/**
 * @brief 获取CCP中断状态
 *
 * @param Module 指向CCP内存结构的指针 \n
 *              取值为CCP0_PTR ~ CCP4_PTR, CCP20_PTR ~ CCP21_PTR
 * @param IntIndex CCP 中断序号,取值见枚举 Ccp_IntIndex_t
 * @retval bool 中断发生状态
 */
KF_INLINE bool Ccp_LL_GetIntrFlag(const Ccp_RegisterMap_t *Module, Ccp_IntIndex_t IntIndex)
{
    uint32_t Mask;
    KF_CCP_ASSERT(CHECK_CCP_ALL_PERIPH_ADDR(Module));
    KF_CCP_ASSERT(CHECK_CCP_INT(IntIndex));

    Mask = 6U + (uint32_t)IntIndex;
    /* PRQA S 3469 1 #KQR003469 */
    return (REG_BITS_READ(Module->CCP_EGIF.reg, (0x1UL << Mask), Mask) != 0U);
}

/**
 * @brief 获取中断标志位
 *
 * @param Module 指向CCP内存结构的指针 \n
 *              取值为CCP0_PTR ~ CCP4_PTR, CCP20_PTR ~ CCP21_PTR
 * @retval uint32_t 所有通道中断标志位
 */
KF_INLINE uint32_t Ccp_LL_GetAllIntrFlag(const Ccp_RegisterMap_t *Module)
{
    uint32_t offset = (uint32_t)6U;
    uint32_t mask   = (uint32_t)0x0FUL << offset;

    KF_CCP_ASSERT(CHECK_CCP_ALL_PERIPH_ADDR(Module));

    /* PRQA S 3469 1 #KQR003469 */
    return REG_BITS_READ(Module->CCP_EGIF.reg, mask, offset);
}

/**
 * @brief 产生通道捕捉/比较事件
 *
 * @param Module 指向CCP内存结构的指针 \n
 *              取值为CCP0_PTR ~ CCP4_PTR, CCP20_PTR ~ CCP21_PTR
 * @param CcpChannel CCP通道序号
 * @retval void
 */
KF_INLINE void Ccp_LL_GenerateCapOrCmpEvent(Ccp_RegisterMap_t *Module, Ccp_ChannelIndex_t CcpChannel)
{
    uint32_t Mask;
    KF_CCP_ASSERT(CHECK_CCP_ALL_PERIPH_ADDR(Module));
    KF_CCP_ASSERT(CHECK_CCP_CHANNEL_INDEX(CcpChannel));

    Mask = 1U + (uint32_t)CcpChannel;
    REG_BIT_SET(Module->CCP_EGIF.reg, (0x1UL << Mask));
}

/**
 * @brief 选择关断引脚 BKIN 极性
 *
 * @param Module 指向CCP内存结构的指针 \n
 *              取值为CCP0_PTR ~ CCP4_PTR, CCP20_PTR ~ CCP21_PTR
 * @param Select 关断引脚 BKIN 极性 \n
 *              true -- BKIN 高电平有效 \n
 *              false -- BKIN 低电平有效
 * @retval void
 */
KF_INLINE void Ccp_LL_SelectBkinPolarity(Ccp_RegisterMap_t *Module, bool Select)
{
    KF_CCP_ASSERT(CHECK_CCP_ALL_PERIPH_ADDR(Module));

    Module->CCP_EGIF.bits.POSSEL = Select ? 1U : 0U;
}

/**
 * @brief 选择关断源
 *
 * @param Module 指向CCP内存结构的指针 \n
 *              取值为CCP0_PTR ~ CCP4_PTR, CCP20_PTR ~ CCP21_PTR
 * @param SelectSrc 关断源 \n
 *              true -- 关断引脚 BKIN 输入 \n
 *              false -- 比较器输出
 * @retval void
 */
KF_INLINE void Ccp_LL_SelectShutOffSource(Ccp_RegisterMap_t *Module, bool SelectSrc)
{
    KF_CCP_ASSERT(CHECK_CCP_ALL_PERIPH_ADDR(Module));

    Module->CCP_EGIF.bits.PXSEL = SelectSrc ? 1U : 0U;
}

/**
 * @brief 产生触发事件
 *
 * @param Module 指向CCP内存结构的指针 \n
 *              取值为CCP0_PTR ~ CCP4_PTR, CCP20_PTR ~ CCP21_PTR
 * @retval void
 */
KF_INLINE void Ccp_LL_GenerateTxSoftwareTrigEvent(Ccp_RegisterMap_t *Module)
{
    KF_CCP_ASSERT(CHECK_CCP_ALL_PERIPH_ADDR(Module));

    Module->CCP_EGIF.bits.TXTRG = 1U;
}

/**
 * @brief 产生串口接收信号测量事件
 *
 * @param Module 指向CCP内存结构的指针 \n
 *              取值为CCP0_PTR ~ CCP4_PTR, CCP20_PTR ~ CCP21_PTR
 * @param EnableSta 使能状态 \n
 *              true -- 使能测量串口接收信号 \n
 *              false -- 禁止测量串口接收信号
 * @retval void
 */
KF_INLINE void Ccp_LL_SetUsartRecvMeasurementEnabled(Ccp_RegisterMap_t *Module, bool EnableSta)
{
    KF_CCP_ASSERT(CHECK_CCP_ALL_PERIPH_ADDR(Module));

    Module->CCP_EGIF.bits.USARTRXEN = EnableSta ? 1U : 0U;
}

/**
 * @brief 设置通道 y 的双边沿捕捉功能使能位
 *
 * @param Module 指向CCP内存结构的指针 \n
 *              取值为CCP0_PTR ~ CCP4_PTR, CCP20_PTR ~ CCP21_PTR
 * @param CcpChannel CCP通道序号 \n
 *              取值为CCP_CHANNEL_INDEX1 ~ CCP_CHANNEL_INDEX4
 * @param EnableSta 使能状态 \n
 *              true -- 使能 \n
 *              false -- 禁止
 * @retval void
 */
KF_INLINE void
Ccp_LL_SetDualEdgeCaptureEnabled(Ccp_RegisterMap_t *Module, Ccp_ChannelIndex_t CcpChannel, bool EnableSta)
{
    uint32_t Mask;
    KF_CCP_ASSERT(CHECK_CCP_ALL_PERIPH_ADDR(Module));
    KF_CCP_ASSERT(CHECK_CCP_CHANNEL_INDEX(CcpChannel));

    Mask = 9U + (uint32_t)CcpChannel;
    REG_BITS_WRITE(Module->UDTIM.reg, 0x1UL << Mask, (EnableSta ? 1UL : 0UL) << Mask);
}

/**
 * @brief 获取PWM输出控制寄存器的信息
 *
 * @param Module 指向寄存器的地址
 * @param Channel  PWM通道
 * @retval 无
 */
KF_INLINE uint32_t Ccp_LL_GetOutputCtrl(const Ccp_RegisterMap_t *const Module, Ccp_ChannelIndex_t Channel)
{
    KF_CCP_ASSERT(CHECK_CCP_ALL_PERIPH_ADDR(Module));
    KF_CCP_ASSERT(CHECK_CCP_CHANNEL_INDEX(Channel));

    uint32_t offset = (uint32_t)Channel << 1U;
    uint32_t mask   = 0x03UL << offset;
    /* PRQA S 3469 1 #KQR003469 */
    return (uint32_t)REG_BITS_READ(Module->CCP_CTL2.reg, mask, offset);
}

/**
 * @brief 获取CCP中断发生状态
 *
 * @param Module 指向CCP内存结构的指针 \n
 *              取值为CCP0_PTR ~ CCP4_PTR, CCP20_PTR ~ CCP21_PTR
 * @param IntIndex CCP 中断序号,取值见枚举 Ccp_IntIndex_t
 * @retval bool 中断发生状态
 *         true    发生了中断，且已使能
 *         false    未发生中断，或未使能
 */
KF_INLINE bool Ccp_LL_GetIntrState(const Ccp_RegisterMap_t *Module, Ccp_IntIndex_t IntIndex)
{
    KF_CCP_ASSERT(CHECK_CCP_ALL_PERIPH_ADDR(Module));
    KF_CCP_ASSERT(CHECK_CCP_INT(IntIndex));

    /* PRQA S 3469 ++ #KQR003469 */
    uint32_t Mask = 6U + (uint32_t)IntIndex;
    bool     flag = (REG_BITS_READ(Module->CCP_EGIF.reg, (0x1UL << (uint32_t)Mask), Mask) != 0U) ? true : false;
    bool     state =
        (REG_BITS_READ(Module->CCP_CTL3.reg, (0x1UL << (uint32_t)IntIndex), (uint32_t)IntIndex) != 0U) ? true : false;
    /* PRQA S 3469 -- #KQR003469 */
    return flag && state;
}

#ifdef __cplusplus
}
#endif /*End of __cplusplus*/
#endif /*End of KF32A158SF_DRV_CCP_H*/
/* EOF */
