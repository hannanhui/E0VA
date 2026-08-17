/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name        : kf32a158sf_drv_usart.h
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
#ifndef KF32A158SF_DRV_USART_H
#define KF32A158SF_DRV_USART_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 *                      QAC Warnings
 ******************************************************************************/
/* PRQA S 0288 EOF #KQR000288 */
/* PRQA S 3205 EOF #KQR003205 */
/* PRQA S 3219 EOF #KQR003219 */
/* PRQA S 4342 EOF #KQR004342 */

/******************************************************************************
 *                      Include Files
 ******************************************************************************/
#include <stdint.h>
#include <stdbool.h>
#include "kf_types.h"
#include "kf32a158sf_reg_usart.h"

#ifdef KF_DRV_USART_ASSERT
#include "dev_assert.h"
#define KF_USART_ASSERT(x) KF_DEV_ASSERT(x)
#else
#define KF_USART_ASSERT(x) ((void)0U)
#endif

/******************************************************************************
 *                      Macro or Inline
 ******************************************************************************/

/******************************************************************************
 *                      Type definitions
 ******************************************************************************/

#define USART_OVERTIME 0xFF

/* USART Baud rate clock select bit */
typedef enum
{
    USART_BR_CLK_SCLK  = 0u,
    USART_BR_CLK_HFCLK = 1u,
} Usart_BaudrateClk_t;

#define CHECK_USART_BAUDRATECLK(x) (((x) == USART_BR_CLK_SCLK) || ((x) == USART_BR_CLK_HFCLK))

/**设置中断序号*/
typedef enum
{
    USART_INT_SET_OVFEIE = 0U,
    USART_INT_SET_PAREIE = 1U,
    USART_INT_SET_FREIE  = 2U,
    USART_INT_SET_BRIE   = 3U,
    USART_INT_SET_ABTOIE = 4U,
    USART_INT_SET_WUIE   = 5U,
    USART_INT_SET_RDRIE  = 9U,
    USART_INT_SET_TFEIE  = 10U,
    USART_INT_SET_TXEIE  = 11U,
    USART_INT_SET_IDLEIE = 12U,
    USART_INT_SET_UADMIE = 18U,
} Usart_IntSetIndex_t;

#define CHECK_USART_INTSETINDEX(x)                                                                                     \
    ((((x) >= USART_INT_SET_OVFEIE) && ((x) <= USART_INT_SET_WUIE)) ||                                                 \
     (((x) >= USART_INT_SET_RDRIE) && ((x) <= USART_INT_SET_IDLEIE)) || ((x) == USART_INT_SET_UADMIE))

/**获取中断序号*/
typedef enum
{
    USART_INT_GET_OVFEIF = 0U,
    USART_INT_GET_PAREIF = 1U,
    USART_INT_GET_FREIF  = 2U,
    USART_INT_GET_BRIF   = 3U,
    USART_INT_GET_ABTOIF = 4U,
    USART_INT_GET_WUIF   = 5U,
    USART_INT_GET_RDRIF  = 11U,
    USART_INT_GET_TFEIF  = 12U,
    USART_INT_GET_TXEIF  = 13U,
    USART_INT_GET_IDLEIF = 15U,
    USART_INT_GET_UADMIF = 14U,
    USART_INT_GET_TFEIF1 = 27U,
} Usart_IntGetIndex_t;

#define CHECK_USART_INTGETINDEX(x)                                                                                     \
    ((((x) >= USART_INT_GET_OVFEIF) && ((x) <= USART_INT_GET_WUIF)) ||                                                 \
     (((x) >= USART_INT_GET_RDRIF) && ((x) <= USART_INT_GET_IDLEIF)) || ((x) == USART_INT_GET_TFEIF1))

/**清除中断序号*/
typedef enum
{
    USART_INT_CLEAR_OVFEIC = 16U,
    USART_INT_CLEAR_PAREIC = 17U,
    USART_INT_CLEAR_FREIC  = 18U,
    USART_INT_CLEAR_BRIC   = 19U,
    USART_INT_CLEAR_ABTOIC = 20U,
    USART_INT_CLEAR_WUIC   = 21U,
    USART_INT_CLEAR_IDLEIC = 26U,
    USART_INT_CLEAR_UADMIC = 25U,
} Usart_IntClearIndex_t;
#define CHECK_USART_INTCLEARINDEX(x) (((x) >= USART_INT_CLEAR_OVFEIC) && ((x) <= USART_INT_CLEAR_IDLEIC))

/* error signal width selected */
typedef enum
{
    USART_ERSW_HIGH_ETU = 0u,
    USART_ERSW_MID_ETU  = 2u,
    USART_ERSW_LOW_ETU  = 3u,
} Usart_ErrSignalWidth_t;
#define CHECK_USART_ERRSIGNALWIDTH(x)                                                                                  \
    (((x) == USART_ERSW_HIGH_ETU) || ((x) == USART_ERSW_MID_ETU) || ((x) == USART_ERSW_LOW_ETU))

/* 重发送、重接收的最大次数 */
typedef enum
{
    USART_MAX_REPEAT_TIMES_0 = 0u,
    USART_MAX_REPEAT_TIMES_1 = 1u,
    USART_MAX_REPEAT_TIMES_2 = 2u,
    USART_MAX_REPEAT_TIMES_3 = 3u,
} Usart_MaxRepeatTimes_t;
#define CHECK_USART_MAXREPEATTIMES(x)                                                                                  \
    (((x) == USART_MAX_REPEAT_TIMES_0) || ((x) == USART_MAX_REPEAT_TIMES_1) || ((x) == USART_MAX_REPEAT_TIMES_2) ||    \
     ((x) == USART_MAX_REPEAT_TIMES_3))

/**检查0xF*/
#define CHECK_USART_0xF(x) (((x) <= 0xFU) && ((x) >= 0x0U))

/******************************************************************************
 *                      Export Variables
 ******************************************************************************/

/******************************************************************************
 *                      Export Functions
 ******************************************************************************/

/**
 * @brief USART 使能
 * @param Module 指向USART内存结构的指针,取值为
 *                          USART0_PTR-USART3_PTR, USART6_PTR
 * @retval void
 */
KF_INLINE void Usart_LL_Enable(Usart_RegisterMap_t *const Module)
{
    KF_USART_ASSERT(CHECK_USART_ALL_PERIPH_ADDR(Module));

    Module->CTL.bits.RESHD   = 1U;
    Module->CTL.bits.USARTEN = 1U;
}

/**
 * @brief USART 禁止
 * @param Module 指向USART内存结构的指针,取值为
 *                          USART0_PTR-USART3_PTR, USART6_PTR
 * @retval void
 */
KF_INLINE void Usart_LL_Disable(Usart_RegisterMap_t *const Module)
{
    KF_USART_ASSERT(CHECK_USART_ALL_PERIPH_ADDR(Module));

    Module->CTL.bits.USARTEN = 0U;
}

/**
 * @brief 选择USART 波特率发生器时钟
 * @param Module 指向USART内存结构的指针,取值为
 *                        USART0_PTR-USART3_PTR, USART6_PTR
 * @param ClkSource USART 波特率发生器时钟, 可见 Usart_BaudrateClk_t
 * @retval void
 */
KF_INLINE void Usart_LL_SelectBaudRateGeneratorClk(Usart_RegisterMap_t *const Module, Usart_BaudrateClk_t ClkSource)
{
    KF_USART_ASSERT(CHECK_USART_ALL_PERIPH_ADDR(Module));
    KF_USART_ASSERT(CHECK_USART_BAUDRATECLK(ClkSource));

    Module->CTL.bits.BRCKS = (uint32_t)ClkSource;
}

/**
 * @brief 半双工同步时钟极性选择
 * @param Module 指向USART内存结构的指针,取值为
 *                          USART0_PTR-USART3_PTR, USART6_PTR
 * @param ClkPolarity 取值为
 *              true     数据在时钟下降沿同步
 *              false     数据在时钟上升沿同步
 * @retval void
 */
KF_INLINE void Usart_LL_SelectSyncClkPolarity(Usart_RegisterMap_t *const Module, bool ClkPolarity)
{
    KF_USART_ASSERT(CHECK_USART_ALL_PERIPH_ADDR(Module));

    Module->CTL.bits.SCKPS = ClkPolarity ? 1U : 0U;
}

/**
 * @brief 发送次序选择
 * @param Module 指向USART内存结构的指针,取值为
 *                          USART0_PTR-USART3_PTR, USART6_PTR
 * @param SendOrder USART发送次序,取值为:
 *                   true   先发送MSB
 *                   false   先发送LSB
 * @retval void
 */
KF_INLINE void Usart_LL_SelectSendOrder(Usart_RegisterMap_t *const Module, bool SendOrder)
{
    KF_USART_ASSERT(CHECK_USART_ALL_PERIPH_ADDR(Module));

    Module->CTL.bits.TCONV = SendOrder ? 1U : 0U;
}

/**
 * @brief 接收次序选择
 * @param Module 指向USART内存结构的指针,取值为
 *                          USART0_PTR-USART3_PTR, USART6_PTR
 * @param RecvOrder USART接收次序,取值为:
 *                   true   先接收MSB
 *                   false   先接收LSB
 * @retval void
 */
KF_INLINE void Usart_LL_SelectRecvOrder(Usart_RegisterMap_t *const Module, bool RecvOrder)
{
    KF_USART_ASSERT(CHECK_USART_ALL_PERIPH_ADDR(Module));

    Module->CTL.bits.RCONV = RecvOrder ? 1U : 0U;
}

/**
 * @brief 唤醒使能
 *
 * @param Module 指向USART内存结构的指针
 * @param EnableSta 使能状态
 *                  true   接收器正在等待接收间隔字符
 *                  false   接收器正常工作
 * @retval void
 */
KF_INLINE void Usart_LL_SetWakeUpEnabled(Usart_RegisterMap_t *const Module, bool EnableSta)
{
    KF_USART_ASSERT(CHECK_USART_ALL_PERIPH_ADDR(Module));

    Module->CTL.bits.WUEN = EnableSta ? 1U : 0U;
}

KF_INLINE void Usart_LL_EnableWakeUp(Usart_RegisterMap_t *const Module)
{
    KF_USART_ASSERT(CHECK_USART_ALL_PERIPH_ADDR(Module));

    Usart_LL_SetWakeUpEnabled(Module, true);
}

KF_INLINE void Usart_LL_DisableWakeUp(Usart_RegisterMap_t *const Module)
{
    KF_USART_ASSERT(CHECK_USART_ALL_PERIPH_ADDR(Module));

    Usart_LL_SetWakeUpEnabled(Module, false);
}

/**
 * @brief 时钟源选择
 * @param Module 指向USART内存结构的指针,取值为
 *                          USART0_PTR-USART3_PTR, USART6_PTR
 * @param ClockSource
 *                   true   主模式(由BRG内部产生时钟)
 *                   false   从模式(时钟源来自外部)
 * @retval void
 */
KF_INLINE void Usart_LL_SelectClkSrc(Usart_RegisterMap_t *const Module, bool ClockSource)
{
    KF_USART_ASSERT(CHECK_USART_ALL_PERIPH_ADDR(Module));

    Module->CTL.bits.CSRS = ClockSource ? 1U : 0U;
}

/**
 * @brief 地址检测使能
 *
 * @param Module 指向USART内存结构的指针
 * @param EnableSta 使能状态
 *                  true   使能地址检测
 *                  false   禁止地址检测
 * @retval void
 */
KF_INLINE void Usart_LL_SetAddrDetectionEnabled(Usart_RegisterMap_t *const Module, bool EnableSta)
{
    KF_USART_ASSERT(CHECK_USART_ALL_PERIPH_ADDR(Module));

    Module->CTL.bits.ADREN = EnableSta ? 1U : 0U;
}

KF_INLINE void Usart_LL_EnableAddressDetection(Usart_RegisterMap_t *const Module)
{
    KF_USART_ASSERT(CHECK_USART_ALL_PERIPH_ADDR(Module));

    Usart_LL_SetAddrDetectionEnabled(Module, true);
}

KF_INLINE void Usart_LL_DisableAddressDetection(Usart_RegisterMap_t *const Module)
{
    KF_USART_ASSERT(CHECK_USART_ALL_PERIPH_ADDR(Module));

    Usart_LL_SetAddrDetectionEnabled(Module, false);
}

/**
 * @brief 自动波特率检测使能
 *
 * @param Module 指向USART内存结构的指针
 * @param EnableSta 使能状态
 *                  true   使能波特率检测
 *                  false   禁止波特率检测
 * @retval void
 */
KF_INLINE void Usart_LL_SetAutoBaudRateDetectionEnabled(Usart_RegisterMap_t *const Module, bool EnableSta)
{
    KF_USART_ASSERT(CHECK_USART_ALL_PERIPH_ADDR(Module));

    Module->CTL.bits.ABRDEN = EnableSta ? 1U : 0U;
}

KF_INLINE void Usart_LL_EnableAutoBaudRateDetection(Usart_RegisterMap_t *const Module)
{
    KF_USART_ASSERT(CHECK_USART_ALL_PERIPH_ADDR(Module));

    Usart_LL_SetAutoBaudRateDetectionEnabled(Module, true);
}

KF_INLINE void Usart_LL_DisableAutoBaudRateDetection(Usart_RegisterMap_t *const Module)
{
    KF_USART_ASSERT(CHECK_USART_ALL_PERIPH_ADDR(Module));

    Usart_LL_SetAutoBaudRateDetectionEnabled(Module, false);
}

/**
 * @brief 接收空闲帧中断标志产生模式
 * @param Module 指向USART内存结构的指针,取值为
 *                          USART0_PTR-USART3_PTR, USART6_PTR
 * @param IntMode
 *                   true  空闲帧中断标志和RDRIF无关
 *                   false  空闲帧中断标志和RDRIF有关(RDRIF=1时才能置1 IDLEIF)
 * @retval void
 */
KF_INLINE void Usart_LL_SetRecvIdleFrameIntMode(Usart_RegisterMap_t *const Module, bool IntMode)
{
    KF_USART_ASSERT(CHECK_USART_ALL_PERIPH_ADDR(Module));

    Module->CTL.bits.RIDLEIS = IntMode ? 1U : 0U;
}

/**
 * @brief 发送间隔字符
 *
 * @param Module 指向USART内存结构的指针
 * @param EnableSta 使能状态
 *                  true   发送间隔字符使能
 *                  false   未使能发送间隔字符
 * @retval void
 */
KF_INLINE void Usart_LL_SetSendBlankEnabled(Usart_RegisterMap_t *const Module, bool EnableSta)
{
    KF_USART_ASSERT(CHECK_USART_ALL_PERIPH_ADDR(Module));

    Module->CTL.bits.SENDB = EnableSta ? 1U : 0U;
}

KF_INLINE void Usart_LL_EnableSendBlank(Usart_RegisterMap_t *const Module)
{
    KF_USART_ASSERT(CHECK_USART_ALL_PERIPH_ADDR(Module));

    Usart_LL_SetSendBlankEnabled(Module, true);
}

KF_INLINE void Usart_LL_DisableSendBlank(Usart_RegisterMap_t *const Module)
{
    KF_USART_ASSERT(CHECK_USART_ALL_PERIPH_ADDR(Module));

    Usart_LL_SetSendBlankEnabled(Module, false);
}

/**
 * @brief 串行通信模式选择
 * @param Module 指向USART内存结构的指针,取值为
 *                          USART0_PTR-USART3_PTR, USART6_PTR
 * @param NewMode
 *                   true  同步模式(半双工)
 *                   false  异步模式(全双工)
 * @retval void
 */
KF_INLINE void Usart_LL_SelectSerialCommMode(Usart_RegisterMap_t *const Module, bool NewMode)
{
    KF_USART_ASSERT(CHECK_USART_ALL_PERIPH_ADDR(Module));

    Module->CTL.bits.SYNC = NewMode ? 1U : 0U;
}

/**
 * @brief 发送使能
 *
 * @param Module 指向USART内存结构的指针
 * @param EnableSta 使能状态
 *                  true   使能发送
 *                  false   禁止发送
 * @retval void
 */
KF_INLINE void Usart_LL_SetTransmitDataEnabled(Usart_RegisterMap_t *const Module, bool EnableSta)
{
    KF_USART_ASSERT(CHECK_USART_ALL_PERIPH_ADDR(Module));

    Module->CTL.bits.TXEN = EnableSta ? 1U : 0U;
}

KF_INLINE void Usart_LL_EnableTransmitData(Usart_RegisterMap_t *const Module)
{
    KF_USART_ASSERT(CHECK_USART_ALL_PERIPH_ADDR(Module));

    Usart_LL_SetTransmitDataEnabled(Module, true);
}

KF_INLINE void Usart_LL_DisableTransmitData(Usart_RegisterMap_t *const Module)
{
    KF_USART_ASSERT(CHECK_USART_ALL_PERIPH_ADDR(Module));

    Usart_LL_SetTransmitDataEnabled(Module, false);
}

/**
 * @brief 接收使能
 *
 * @param Module 指向USART内存结构的指针
 * @param EnableSta 使能状态
 *                  true   使能接收
 *                  false   禁止接收
 * @retval void
 */
KF_INLINE void Usart_LL_SetReceiveDataEnabled(Usart_RegisterMap_t *const Module, bool EnableSta)
{
    KF_USART_ASSERT(CHECK_USART_ALL_PERIPH_ADDR(Module));

    Module->CTL.bits.RXEN = EnableSta ? 1U : 0U;
}

KF_INLINE void Usart_LL_EnableReceiveData(Usart_RegisterMap_t *const Module)
{
    KF_USART_ASSERT(CHECK_USART_ALL_PERIPH_ADDR(Module));

    Usart_LL_SetReceiveDataEnabled(Module, true);
}

KF_INLINE void Usart_LL_DisableReceiveData(Usart_RegisterMap_t *const Module)
{
    KF_USART_ASSERT(CHECK_USART_ALL_PERIPH_ADDR(Module));

    Usart_LL_SetReceiveDataEnabled(Module, false);
}

/**
 * @brief 全双工模式时发送空闲帧使能
 *
 * @param Module 指向USART内存结构的指针
 * @param EnableSta 使能状态
 *                  true   使能发送器发送空闲帧
 *                  false   禁止发送器发送空闲帧
 * @retval void
 */
KF_INLINE void Usart_LL_SetSendIdleFramesEnabled(Usart_RegisterMap_t *const Module, bool EnableSta)
{
    KF_USART_ASSERT(CHECK_USART_ALL_PERIPH_ADDR(Module));

    Module->CTL.bits.TIDLEEN = EnableSta ? 1U : 0U;
}

KF_INLINE void Usart_LL_EnableSendIdleFrames(Usart_RegisterMap_t *const Module)
{
    KF_USART_ASSERT(CHECK_USART_ALL_PERIPH_ADDR(Module));

    Usart_LL_SetSendIdleFramesEnabled(Module, true);
}

KF_INLINE void Usart_LL_DisableSendIdleFrames(Usart_RegisterMap_t *const Module)
{
    KF_USART_ASSERT(CHECK_USART_ALL_PERIPH_ADDR(Module));

    Usart_LL_SetSendIdleFramesEnabled(Module, false);
}

/**
 * @brief 停止位长度选择
 * @param Module 指向USART内存结构的指针,取值为
 *                          USART0_PTR-USART3_PTR, USART6_PTR
 * @param NewLength
 *                   true  停止位长度为2bit
 *                   false  停止位长度为1bit
 * @retval void
 */
KF_INLINE void Usart_LL_SelectStopBitLen(Usart_RegisterMap_t *const Module, bool NewLength)
{
    KF_USART_ASSERT(CHECK_USART_ALL_PERIPH_ADDR(Module));

    Module->CTL.bits.STPW = NewLength ? 1U : 0U;
}

/**
 * @brief 发送数据第 9 位数据选择
 * @param Module 指向USART内存结构的指针,取值为
 *                          USART0_PTR-USART3_PTR, USART6_PTR
 * @param NewMode
 *                   true  RS-485模式
 *                   false  奇偶校验
 * @retval void
 */
KF_INLINE void Usart_LL_SelectDataOfBit9(Usart_RegisterMap_t *const Module, bool NewMode)
{
    KF_USART_ASSERT(CHECK_USART_ALL_PERIPH_ADDR(Module));

    Module->CTL.bits.TX9SEL = NewMode ? 1U : 0U;
}

/**
 * @brief 奇偶校验选择
 * @param Module 指向USART内存结构的指针,取值为
 *                          USART0_PTR-USART3_PTR, USART6_PTR
 * @param NewState
 *                   TX9SEL 为 0:
 *                   true  偶校验
 *                   false  奇校验
 *                   TX9SEL 为 1:
 *                   true  发送/接收的为地址
 *                   false  发送/接收的为数据
 * @retval void
 */
KF_INLINE void Usart_LL_SelectParityCheck(Usart_RegisterMap_t *const Module, bool NewState)
{
    KF_USART_ASSERT(CHECK_USART_ALL_PERIPH_ADDR(Module));

    Module->CTL.bits.PARM = NewState ? 1U : 0U;
}

/**
 * @brief 第 9 位数据使能
 *
 * @param Module 指向USART内存结构的指针
 * @param EnableSta 使能状态
 *                  true   使能第 9 位数据发送和接收
 *                  false   未使能第 9 位数据发送和接收
 * @retval void
 */
KF_INLINE void Usart_LL_SetBit9Enabled(Usart_RegisterMap_t *const Module, bool EnableSta)
{
    KF_USART_ASSERT(CHECK_USART_ALL_PERIPH_ADDR(Module));

    Module->CTL.bits.DT9EN = EnableSta ? 1U : 0U;
}

KF_INLINE void Usart_LL_Enable9Data(Usart_RegisterMap_t *const Module)
{
    KF_USART_ASSERT(CHECK_USART_ALL_PERIPH_ADDR(Module));

    Module->CTL.bits.DT9EN = 1U;
    Usart_LL_SetBit9Enabled(Module, true);
}

KF_INLINE void Usart_LL_Disable9Data(Usart_RegisterMap_t *const Module)
{
    KF_USART_ASSERT(CHECK_USART_ALL_PERIPH_ADDR(Module));

    Usart_LL_SetBit9Enabled(Module, false);
}

/**
 * @brief 间隔字符长度选择
 * @param Module 指向USART内存结构的指针,取值为
 *                          USART0_PTR-USART3_PTR, USART6_PTR
 * @param BlankLen
 *                   true  间隔字符为16个bit长度
 *                   false  间隔字符为13个bit长度
 * @retval void
 */
KF_INLINE void Usart_LL_SelectBlankLength(Usart_RegisterMap_t *const Module, bool BlankLen)
{
    KF_USART_ASSERT(CHECK_USART_ALL_PERIPH_ADDR(Module));

    Module->CTL.bits.BKPWS = BlankLen ? 1U : 0U;
}

/**
 * @brief 使用 USART 时,请在 USARTEN 位使能之前将该位置 1
 *
 * @param Module 指向USART内存结构的指针
 * @param EnableSta 使能状态
 *                  true   使能
 *                  false   禁止
 * @retval void
 */
KF_INLINE void Usart_LL_SetReshdEnabled(Usart_RegisterMap_t *const Module, bool EnableSta)
{
    KF_USART_ASSERT(CHECK_USART_ALL_PERIPH_ADDR(Module));

    Module->CTL.bits.RESHD = EnableSta ? 1U : 0U;
}

/**
 * @brief 配置USART USARTDIV的整数部分
 * @param Module 指向USART内存结构的指针,取值为
 *                          USART0_PTR-USART3_PTR, USART6_PTR
 * @param Integer 0~65535
 * @retval void
 */
KF_INLINE void Usart_LL_SetBaudRateInteger(Usart_RegisterMap_t *const Module, uint16_t Integer)
{
    KF_USART_ASSERT(CHECK_USART_ALL_PERIPH_ADDR(Module));

    Module->BRGR.bits.BRGM = Integer;
}

/**
 * @brief 配置USART 小数波特率分子
 * @param Module 指向USART内存结构的指针,取值为
 *                          USART0_PTR-USART3_PTR, USART6_PTR
 * @param Molecular 0~15
 * @retval void
 */
KF_INLINE void Usart_LL_SetBaudRateMolecular(Usart_RegisterMap_t *const Module, uint8_t Molecular)
{
    KF_USART_ASSERT(CHECK_USART_ALL_PERIPH_ADDR(Module));
    KF_USART_ASSERT(CHECK_USART_0xF(Molecular));

    Module->BRGR.bits.BRGF1 = Molecular;
}

/**
 * @brief 配置USART 小数波特率分母
 * @param Module 指向USART内存结构的指针,取值为
 *                          USART0_PTR-USART3_PTR, USART6_PTR
 * @param Denominator 0~15
 * @retval void
 */
KF_INLINE void Usart_LL_SetBaudRateDenominator(Usart_RegisterMap_t *const Module, uint8_t Denominator)
{
    KF_USART_ASSERT(CHECK_USART_ALL_PERIPH_ADDR(Module));
    KF_USART_ASSERT(CHECK_USART_0xF(Denominator));

    Module->BRGR.bits.BRGF2 = Denominator;
}

/**
 * @brief 配置USART波特率
 *                          Fck
 *          BaudRate = -----------------------
 *                                    BRGF1
 *                      16*BRGM*(1 + -------)
 *                                    BRGF2
 *
 * @param Module 指向USART内存结构的指针,取值为
 *                          USART0_PTR-USART3_PTR, USART6_PTR
 * @param Integer 波特率整数部分, 0~65535
 * @param Molecular 小数波特率分子, 0~15
 * @param Denominator 小数波特率分母, 0~15
 * @retval void
 */
KF_INLINE void
Usart_LL_SetBaudRate(Usart_RegisterMap_t *const Module, uint16_t Integer, uint8_t Molecular, uint8_t Denominator)
{
    KF_USART_ASSERT(CHECK_USART_ALL_PERIPH_ADDR(Module));
    KF_USART_ASSERT(CHECK_USART_0xF(Molecular));
    KF_USART_ASSERT(CHECK_USART_0xF(Denominator));

    Module->BRGR.bits.BRGM  = Integer;
    Module->BRGR.bits.BRGF1 = Molecular;
    Module->BRGR.bits.BRGF2 = Denominator;
}

/**
 * @brief 获取中断标志位
 *
 * @param Module 指向USART内存结构的指针
 * @param IntIndex 获取中断序号, 可见 Usart_IntGetIndex_t
 * @retval bool
 */
KF_INLINE bool Usart_LL_GetIntrFlag(const Usart_RegisterMap_t *const Module, Usart_IntGetIndex_t IntIndex)
{
    KF_USART_ASSERT(CHECK_USART_ALL_PERIPH_ADDR(Module));
    KF_USART_ASSERT(CHECK_USART_INTGETINDEX(IntIndex));

    /* PRQA S 3469 1 #KQR003469 */
    return (REG_BITS_READ(Module->STR.reg, (0x1UL << (uint32_t)IntIndex), (uint32_t)IntIndex) != 0U);
}

/**
 * @brief 接收 BUF 清零
 *
 * @param Module 指向USART内存结构的指针
 * @param ClearSta 清零状态
 *                   true  清空接收 BUF
 *                   false  接收 BUF 正常工作
 * @retval void
 */
KF_INLINE void Usart_LL_SetClearRecvBufferSta(Usart_RegisterMap_t *const Module, bool ClearSta)
{
    Module->STR.bits.RCFR = ClearSta ? 1U : 0U;
}

/**
 * @brief 发送 BUF 清零
 *
 * @param Module 指向USART内存结构的指针
 * @param ClearSta 清零状态
 *                   true  清空接收 BUF
 *                   false  接收 BUF 正常工作
 * @retval void
 */
KF_INLINE void Usart_LL_SetClearTransBufferSta(Usart_RegisterMap_t *const Module, bool ClearSta)
{
    Module->STR.bits.TXFR = ClearSta ? 1U : 0U;
}

/**
 * @brief 清除中断标志
 *
 * @param Module 指向USART内存结构的指针
 * @param IntIndex 清除中断序号, 可见 Usart_IntClearIndex_t
 * @retval void
 */
KF_INLINE void Usart_LL_ClearIntrFlag(Usart_RegisterMap_t *const Module, Usart_IntClearIndex_t IntIndex)
{
    KF_USART_ASSERT(CHECK_USART_ALL_PERIPH_ADDR(Module));
    KF_USART_ASSERT(CHECK_USART_INTCLEARINDEX(IntIndex));

    /* PRQA S 3473 1 #KQR003473 */
    REG_BIT_SET(Module->STR.reg, (0x1UL << (uint32_t)IntIndex));
    uint32_t tmpIndex = 0;
    uint32_t timeout  = 0;

    if (IntIndex <= USART_INT_CLEAR_WUIC)
    {
        tmpIndex = (uint32_t)IntIndex - ((uint32_t)USART_INT_CLEAR_OVFEIC - (uint32_t)USART_INT_GET_OVFEIF);
    }
    else
    {
        tmpIndex = (uint32_t)IntIndex - ((uint32_t)USART_INT_CLEAR_UADMIC - (uint32_t)USART_INT_GET_UADMIF);
    }

    while (Usart_LL_GetIntrFlag(Module, (Usart_IntGetIndex_t)tmpIndex) && (timeout < (uint32_t)USART_OVERTIME))
    {
        timeout++;
    }

    /* PRQA S 3473 1 #KQR003473 */
    REG_BIT_CLR(Module->STR.reg, (0x1UL << (uint32_t)IntIndex));
}

/**
 * @brief RX input selection
 * @param Module 指向USART内存结构的指针,取值为
 *                          USART0_PTR-USART3_PTR, USART6_PTR
 * @param NewState
 *                   false  RX
 * @retval void
 */
KF_INLINE void Usart_LL_SelectRxInput(Usart_RegisterMap_t *const Module, bool NewState)
{
    KF_USART_ASSERT(CHECK_USART_ALL_PERIPH_ADDR(Module));

    Module->STR.bits.RXDSEL = NewState ? 1U : 0U;
}

/**
 * @brief TX input selection
 * @param Module 指向USART内存结构的指针,取值为
 *                          USART0_PTR-USART3_PTR, USART6_PTR
 * @param NewState
 *                   false  TX
 * @retval void
 */
KF_INLINE void Usart_LL_SelectTxInput(Usart_RegisterMap_t *const Module, bool NewState)
{
    KF_USART_ASSERT(CHECK_USART_ALL_PERIPH_ADDR(Module));

    Module->STR.bits.TXSEL = NewState ? 1U : 0U;
}

/**
 * @brief 发送数据寄存器
 * @param Module 指向USART内存结构的指针,取值为
 *                          USART0_PTR-USART3_PTR, USART6_PTR
 * @param Data
 * @retval void
 */
KF_INLINE void Usart_LL_SetTxBufferData(Usart_RegisterMap_t *const Module, uint8_t Data)
{
    KF_USART_ASSERT(CHECK_USART_ALL_PERIPH_ADDR(Module));

    Module->BUFR.TBUFR.TBUF = Data;
}

/**
 * @brief 接收数据寄存器
 * @param Module 指向USART内存结构的指针,取值为
 *                          USART0_PTR-USART3_PTR, USART6_PTR
 * @retval rx data
 */
KF_INLINE uint16_t Usart_LL_GetRxBufferData(const Usart_RegisterMap_t *const Module)
{
    KF_USART_ASSERT(CHECK_USART_ALL_PERIPH_ADDR(Module));

    return (uint16_t)Module->BUFR.RBUFR.RBUF;
}

/**
 * @brief 数据通道选择
 * @param Module 指向USART内存结构的指针,取值为
 *                          USART0_PTR-USART3_PTR, USART6_PTR
 * @param NewState
 *                   true  选择通道1(TX1)
 *                   false  选择通道0(TX0)
 * @retval void
 */
KF_INLINE void Usart_LL_SelectPassageWay(Usart_RegisterMap_t *const Module, bool NewState)
{
    KF_USART_ASSERT(CHECK_USART_ALL_PERIPH_ADDR(Module));

    Module->CONFIG.bits.PSEL = NewState ? 1U : 0U;
}

/**
 * @brief 使能USART中断
 *
 * @param Module 指向USART内存结构的指针
 * @param IntIndex 使能中断序号, 可见 Usart_IntSetIndex_t
 * @param EnableSta 使能状态
 *                  true   使能
 *                  false   禁止
 * @retval void
 */
KF_INLINE void Usart_LL_SetIntrEnabled(Usart_RegisterMap_t *const Module, Usart_IntSetIndex_t IntIndex, bool EnableSta)
{
    KF_USART_ASSERT(CHECK_USART_ALL_PERIPH_ADDR(Module));
    KF_USART_ASSERT(CHECK_USART_INTSETINDEX(IntIndex));

    /* PRQA S 3473 1 #KQR003473 */
    REG_BITS_WRITE(Module->IER.reg, (0x1UL << (uint32_t)IntIndex), ((EnableSta ? 1UL : 0UL) << (uint32_t)IntIndex));
}

/**
 * @brief 获取中断使能状态
 *
 * @param Module 指向USART内存结构的指针
 * @param IntIndex 中断序号, 可见 Usart_IntSetIndex_t
 * @retval bool
 */
KF_INLINE bool Usart_LL_GetIntrEnabledState(const Usart_RegisterMap_t *const Module, Usart_IntSetIndex_t IntIndex)
{
    KF_USART_ASSERT(CHECK_USART_ALL_PERIPH_ADDR(Module));
    KF_USART_ASSERT(CHECK_USART_INTSETINDEX(IntIndex));

    /* PRQA S 3469 1 #KQR003469 */
    return (REG_BITS_READ(Module->IER.reg, (0x1UL << (uint32_t)IntIndex), (uint32_t)IntIndex) != 0U);
}

/**
 * @brief DMA 读串口接收数据寄存器使能
 *
 * @param Module 指向USART内存结构的指针
 * @param EnableSta 使能状态
 *                  true   使能
 *                  false   禁止
 * @retval void
 */
KF_INLINE void Usart_LL_SetRecvDmaEnabled(Usart_RegisterMap_t *const Module, bool EnableSta)
{
    KF_USART_ASSERT(CHECK_USART_ALL_PERIPH_ADDR(Module));

    Module->IER.bits.URCDE = EnableSta ? 1U : 0U;
}

KF_INLINE void Usart_LL_EnableDMAReadReceive(Usart_RegisterMap_t *const Module)
{
    KF_USART_ASSERT(CHECK_USART_ALL_PERIPH_ADDR(Module));

    Usart_LL_SetRecvDmaEnabled(Module, true);
}

KF_INLINE void Usart_LL_DisableDMAReadReceive(Usart_RegisterMap_t *const Module)
{
    KF_USART_ASSERT(CHECK_USART_ALL_PERIPH_ADDR(Module));

    Usart_LL_SetRecvDmaEnabled(Module, false);
}

/**
 * @brief DMA 写串口发送数据寄存器使能
 *
 * @param Module 指向USART内存结构的指针
 * @param EnableSta 使能状态
 *                  true   使能
 *                  false   禁止
 * @retval void
 */
KF_INLINE void Usart_LL_SetTransDmaEnabled(Usart_RegisterMap_t *const Module, bool EnableSta)
{
    KF_USART_ASSERT(CHECK_USART_ALL_PERIPH_ADDR(Module));

    Module->IER.bits.UTXDE = EnableSta ? 1U : 0U;
}

KF_INLINE void Usart_LL_EnableDMAWriteTransmit(Usart_RegisterMap_t *const Module)
{
    KF_USART_ASSERT(CHECK_USART_ALL_PERIPH_ADDR(Module));

    Usart_LL_SetTransDmaEnabled(Module, true);
}

KF_INLINE void Usart_LL_DisableDMAWriteTransmit(Usart_RegisterMap_t *const Module)
{
    KF_USART_ASSERT(CHECK_USART_ALL_PERIPH_ADDR(Module));

    Usart_LL_SetTransDmaEnabled(Module, false);
}

/**
 * @brief 设置地址匹配值
 * @param Module 指向USART内存结构的指针,取值为
 *                          USART0_PTR-USART3_PTR, USART6_PTR
 * @param Address 8位地址值
 * @retval void
 */
KF_INLINE void Usart_LL_SetAddressMatchValue(Usart_RegisterMap_t *const Module, uint8_t Address)
{
    KF_USART_ASSERT(CHECK_USART_ALL_PERIPH_ADDR(Module));

    Module->ADM.reg = Address;
}

/**
 * @brief 获取中断发生状态
 *
 * @param Module 指向USART内存结构的指针
 * @param IntIndex 获取中断序号, 可见 Usart_IntGetIndex_t
 * @retval bool 中断发生状态
 *         true    发生了中断，且已使能
 *         false    未发生中断，或未使能
 */
KF_INLINE bool Usart_LL_GetIntrState(const Usart_RegisterMap_t *const Module, Usart_IntGetIndex_t IntIndex)
{
    KF_USART_ASSERT(CHECK_USART_ALL_PERIPH_ADDR(Module));
    KF_USART_ASSERT(CHECK_USART_INTGETINDEX(IntIndex));
    /* PRQA S 3469 ++ #KQR003469 */
    uint32_t mask = (uint32_t)IntIndex;
    bool     flag =
        (REG_BITS_READ(Module->STR.reg, (0x1UL << (uint32_t)IntIndex), (uint32_t)IntIndex) != 0U) ? true : false;
    bool state = false;
    if ((uint32_t)IntIndex <= (uint32_t)USART_INT_GET_WUIF)
    {
        state = (REG_BITS_READ(Module->IER.reg, (0x1UL << mask), mask) != 0U) ? true : false;
    }
    else if ((uint32_t)IntIndex <= (uint32_t)USART_INT_GET_TXEIF)
    {
        mask  = (uint32_t)IntIndex + (uint32_t)USART_INT_SET_RDRIE - (uint32_t)USART_INT_GET_RDRIF;
        state = (REG_BITS_READ(Module->IER.reg, (0x1UL << mask), mask) != 0U) ? true : false;
    }
    else if (IntIndex == USART_INT_GET_UADMIF)
    {
        state = (Module->IER.bits.UADMIE != 0U) ? true : false;
    }
    else if (IntIndex == USART_INT_GET_IDLEIF)
    {
        state = (Module->IER.bits.IDLEIE != 0U) ? true : false;
    }
    else if (IntIndex == USART_INT_GET_TFEIF1)
    {
        state = true;
    }
    else
    {
        /* do nothing */
    }
    /* PRQA S 3469 -- #KQR003469 */

    return flag && state;
}

#ifdef __cplusplus
}
#endif /*End of __cplusplus*/
#endif /*End of KF32A158SF_DRV_USART_H*/
/* EOF */
