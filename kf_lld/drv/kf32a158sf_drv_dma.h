/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name        : kf32a158sf_drv_dma.h
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
#ifndef KF32A158SF_DRV_DMA_H
#define KF32A158SF_DRV_DMA_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 *                      QAC Warnings
 ******************************************************************************/
/* PRQA S 0288 EOF #KQR000288 */
/* PRQA S 3205 EOF #KQR003205 */
/* PRQA S 3219 EOF #KQR003219 */
/* PRQA S 3473 EOF #KQR003473 */
/******************************************************************************
 *                      Include Files
 ******************************************************************************/
#include <stdint.h>
#include <stdbool.h>
#include "kf_types.h"
#include "kf32a158sf_reg_dma.h"

#ifdef KF_DRV_DMA_ASSERT
#include "dev_assert.h"
#define KF_DMA_ASSERT(x) KF_DEV_ASSERT(x)
#else
#define KF_DMA_ASSERT(x) ((void)0U)
#endif

/******************************************************************************
 *                      Macro or Inline
 ******************************************************************************/

/******************************************************************************
 *                      Type definitions
 ******************************************************************************/
#define DMA_INTR_FULL_BITS        (0x07U)
#define DMA_INTR_OFFSET_CHANNEL_1 (0U)
#define DMA_INTR_BITS_CHANNEL_1   (DMA_INTR_FULL_BITS << DMA_INTR_OFFSET_CHANNEL_1)
#define DMA_INTR_OFFSET_CHANNEL_2 (3U)
#define DMA_INTR_BITS_CHANNEL_2   (DMA_INTR_FULL_BITS << DMA_INTR_OFFSET_CHANNEL_2)
#define DMA_INTR_OFFSET_CHANNEL_3 (6U)
#define DMA_INTR_BITS_CHANNEL_3   (DMA_INTR_FULL_BITS << DMA_INTR_OFFSET_CHANNEL_3)
#define DMA_INTR_OFFSET_CHANNEL_4 (9U)
#define DMA_INTR_BITS_CHANNEL_4   (DMA_INTR_FULL_BITS << DMA_INTR_OFFSET_CHANNEL_4)
#define DMA_INTR_OFFSET_CHANNEL_5 (12U)
#define DMA_INTR_BITS_CHANNEL_5   (DMA_INTR_FULL_BITS << DMA_INTR_OFFSET_CHANNEL_5)
#define DMA_INTR_OFFSET_CHANNEL_6 (15U)
#define DMA_INTR_BITS_CHANNEL_6   (DMA_INTR_FULL_BITS << DMA_INTR_OFFSET_CHANNEL_6)
#define DMA_INTR_OFFSET_CHANNEL_7 (18U)
#define DMA_INTR_BITS_CHANNEL_7   (DMA_INTR_FULL_BITS << DMA_INTR_OFFSET_CHANNEL_7)

/* cma channel check */
typedef enum
{
    DMA_CHANNEL_1,
    DMA_CHANNEL_2,
    DMA_CHANNEL_3,
    DMA_CHANNEL_4,
    DMA_CHANNEL_5,
    DMA_CHANNEL_6,
    DMA_CHANNEL_7
} Dma_Channel_t;
#define CHECK_DMA_CHANNEL(CHANNEL) ((uint32_t)CHANNEL <= DMA_CHANNEL_7)

typedef enum
{
    DMA_DATA_WIDTH_8_BITS = 0x0U,
    DMA_DATA_WIDTH_16_BITS,
    DMA_DATA_WIDTH_32_BITS
} Dma_DataWidth_t;
#define CHECK_DMA_DATAWIDTH(WIDTH) ((uint32_t)WIDTH <= DMA_DATA_WIDTH_32_BITS)

typedef enum
{
    DMA_PRIORITY_LOW,      /*!< 低优先级 */
    DMA_PRIORITY_MEDIUM,   /*!< 中等优先级 */
    DMA_PRIORITY_HIGH,     /*!< 高优先级 */
    DMA_PRIORITY_VERY_HIGH /*!< 非常高优先级 */
} Dma_Priority_t;
#define CHECK_DMA_PRIORITY(PRIORITY) ((uint32_t)PRIORITY <= DMA_PRIORITY_VERY_HIGH)

typedef enum
{
    DMA_LIFR_FTIF_LOGIC_BIT  = 0x1U, /*!< 完成传输中断掩码 */
    DMA_LIFR_HTIF_LOGIC_BIT  = 0x2U, /*!< 半传输中断掩码 */
    DMA_LIFR_ETIF_LOGIC_BIT  = 0x4U, /*!< 错误传输中断掩码 */
    DMA_LIFR_ALLIF_LOGIC_BIT = 0x7U  /*!< 所有中断掩码 */
} Dma_LifrMask_t;

#define CHECK_DMA_LIFRMASK(mask) (((mask) > 0U) && ((mask) <= DMA_LIFR_ALLIF_LOGIC_BIT))
/* Check for functions that only support single bit masks */
#define CHECK_DMA_LIFR_SINGLE_MASK(mask)                                                                               \
    (((mask) == DMA_LIFR_FTIF_LOGIC_BIT) || ((mask) == DMA_LIFR_HTIF_LOGIC_BIT) || ((mask) == DMA_LIFR_ETIF_LOGIC_BIT))

typedef enum
{
    DMA_TRISRC_0_USART0_TX = 0x0,
    DMA_TRISRC_0_USART0_RX = 0x0,
    DMA_TRISRC_0_USART1_TX = 0x0,
    DMA_TRISRC_0_USART1_RX = 0x0,
    DMA_TRISRC_0_USART2_TX = 0x0,
    DMA_TRISRC_0_USART2_RX = 0x0,

    DMA_TRISRC_1_USART3_RX = 0x1,
    DMA_TRISRC_1_USART6_TX = 0x1,
    DMA_TRISRC_1_USART6_RX = 0x1,
    DMA_TRISRC_1_USART3_TX = 0x1,

    DMA_TRISRC_2_USART6_TX = 0x2,
    DMA_TRISRC_2_USART6_RX = 0x2,

    DMA_TRISRC_4_I2C2_TX = 0x4,
    DMA_TRISRC_4_I2C2_RX = 0x4,

    DMA_TRISRC_5_I2C0_TX = 0x5,
    DMA_TRISRC_5_I2C0_RX = 0x5,
    DMA_TRISRC_5_I2C1_TX = 0x5,
    DMA_TRISRC_5_I2C1_RX = 0x5,

    DMA_TRISRC_6_ADC0H0 = 0x6,
    DMA_TRISRC_6_ADC0H1 = 0x6,
    DMA_TRISRC_6_ADC0H2 = 0x6,
    DMA_TRISRC_6_ADC0H3 = 0x6,
    DMA_TRISRC_6_ADC0N  = 0x6,

    DMA_TRISRC_7_ADC1H0 = 0x7,
    DMA_TRISRC_7_ADC1H1 = 0x7,
    DMA_TRISRC_7_ADC1H2 = 0x7,
    DMA_TRISRC_7_ADC1H3 = 0x7,
    DMA_TRISRC_7_ADC1N  = 0x7,

    DMA_TRISRC_8_ADC0H4 = 0x8,
    DMA_TRISRC_8_ADC0H5 = 0x8,

    DMA_TRISRC_9_SPI0_TX = 0x9,
    DMA_TRISRC_9_SPI0_RX = 0x9,
    DMA_TRISRC_9_SPI1_TX = 0x9,
    DMA_TRISRC_9_SPI1_RX = 0x9,
    DMA_TRISRC_9_SPI2_TX = 0x9,
    DMA_TRISRC_9_SPI2_RX = 0x9,

    DMA_TRISRC_11_ADC1H4 = 0xb,
    DMA_TRISRC_11_SHA    = 0xb,
    DMA_TRISRC_11_ADC1H5 = 0xb,

    DMA_TRISRC_14_TM14TRGI = 0xe,
    DMA_TRISRC_14_CCP23CH2 = 0xe,
    DMA_TRISRC_14_TM22UP   = 0xe,
    DMA_TRISRC_14_TM14UP   = 0xe,

    DMA_TRISRC_15_TM0UP   = 0xf,
    DMA_TRISRC_15_TM0TRIG = 0xf,
    DMA_TRISRC_15_CCP0CH1 = 0xf,
    DMA_TRISRC_15_CCP0CH2 = 0xf,
    DMA_TRISRC_15_CCP0CH3 = 0xf,
    DMA_TRISRC_15_CCP0CH4 = 0xf,

    DMA_TRISRC_16_TM1UP   = 0x10,
    DMA_TRISRC_16_TM1TRIG = 0x10,
    DMA_TRISRC_16_CCP1CH1 = 0x10,
    DMA_TRISRC_16_CCP1CH2 = 0x10,
    DMA_TRISRC_16_CCP1CH3 = 0x10,
    DMA_TRISRC_16_CCP1CH4 = 0x10,

    DMA_TRISRC_17_CCP2CH3 = 0x11,
    DMA_TRISRC_17_CCP2CH4 = 0x11,
    DMA_TRISRC_17_TM2UP   = 0x11,
    DMA_TRISRC_17_TM2TRIG = 0x11,
    DMA_TRISRC_17_CCP2CH1 = 0x11,
    DMA_TRISRC_17_CCP2CH2 = 0x11,

    DMA_TRISRC_18_CCP3CH4 = 0x12,
    DMA_TRISRC_18_TM3UP   = 0x12,
    DMA_TRISRC_18_TM3TRIG = 0x12,
    DMA_TRISRC_18_CCP3CH1 = 0x12,
    DMA_TRISRC_18_CCP3CH2 = 0x12,
    DMA_TRISRC_18_CCP3CH3 = 0x12,

    DMA_TRISRC_19_TM4TRIG = 0x13,
    DMA_TRISRC_19_CCP4CH1 = 0x13,
    DMA_TRISRC_19_CCP4CH2 = 0x13,
    DMA_TRISRC_19_CCP4CH3 = 0x13,
    DMA_TRISRC_19_CCP4CH4 = 0x13,
    DMA_TRISRC_19_TM4UP   = 0x13,

    DMA_TRISRC_20_CMP3 = 0x14,

    DMA_TRISRC_21_TM19TRIG = 0x15,

    DMA_TRISRC_22_CCP5CH2 = 0x16,
    DMA_TRISRC_22_CCP5CH3 = 0x16,
    DMA_TRISRC_22_CCP5CH4 = 0x16,
    DMA_TRISRC_22_CCP5CLS = 0x16,
    DMA_TRISRC_22_TM5UP   = 0x16,
    DMA_TRISRC_22_TM5TRIG = 0x16,
    DMA_TRISRC_22_CCP5CH1 = 0x16,

    DMA_TRISRC_23_TM9TRIG = 0x17,
    DMA_TRISRC_23_CCP9CH1 = 0x17,
    DMA_TRISRC_23_CCP9CH2 = 0x17,
    DMA_TRISRC_23_CCP9CH3 = 0x17,
    DMA_TRISRC_23_CCP9CH4 = 0x17,
    DMA_TRISRC_23_CCP9CLS = 0x17,
    DMA_TRISRC_23_TM9UP   = 0x17,

    DMA_TRISRC_25_TM10UP = 0x19,
    DMA_TRISRC_25_AES_RD = 0x19,
    DMA_TRISRC_25_TM26UP = 0x19,
    DMA_TRISRC_25_TM6UP  = 0x19,
    DMA_TRISRC_25_AES_WR = 0x19,

    DMA_TRISRC_26_CCP20CH4 = 0x1a,
    DMA_TRISRC_26_TM20UP   = 0x1a,
    DMA_TRISRC_26_TM20TRIG = 0x1a,
    DMA_TRISRC_26_CCP20CH1 = 0x1a,
    DMA_TRISRC_26_CCP20CH2 = 0x1a,
    DMA_TRISRC_26_CCP20CH3 = 0x1a,

    DMA_TRISRC_27_CCP21CH3 = 0x1b,
    DMA_TRISRC_27_CCP21CH4 = 0x1b,
    DMA_TRISRC_27_TM21UP   = 0x1b,
    DMA_TRISRC_27_TM21TRIG = 0x1b,
    DMA_TRISRC_27_CCP21CH1 = 0x1b,
    DMA_TRISRC_27_CCP21CH2 = 0x1b,

    DMA_TRISRC_28_T11ADF = 0x1c,
    DMA_TRISRC_28_T11BDF = 0x1c,
    DMA_TRISRC_28_T11CDF = 0x1c,
    DMA_TRISRC_28_T11DDF = 0x1c,
    DMA_TRISRC_28_T11GDF = 0x1c,
    DMA_TRISRC_28_T11DF  = 0x1c,
    DMA_TRISRC_28_T11UDF = 0x1c,

    DMA_TRISRC_29_T11TDF0 = 0x1d,
    DMA_TRISRC_29_T11TDF1 = 0x1d,
    DMA_TRISRC_29_T31ADF  = 0x1d,
    DMA_TRISRC_29_T31BDF  = 0x1d,
    DMA_TRISRC_29_T31CDF  = 0x1d,
    DMA_TRISRC_29_T31DDF  = 0x1d,
    DMA_TRISRC_29_T31GDF  = 0x1d,

    DMA_TRISRC_30_T12ADF = 0x1e,
    DMA_TRISRC_30_T12BDF = 0x1e,
    DMA_TRISRC_30_T12CDF = 0x1e,
    DMA_TRISRC_30_T12DDF = 0x1e,
    DMA_TRISRC_30_T12GDF = 0x1e,
    DMA_TRISRC_30_T12DF  = 0x1e,
    DMA_TRISRC_30_T12UDF = 0x1e,

    DMA_TRISRC_31_T12TDF0 = 0x1f,
    DMA_TRISRC_31_T12TDF1 = 0x1f,
    DMA_TRISRC_31_T31DF   = 0x1f,
    DMA_TRISRC_31_T31UDF  = 0x1f,
    DMA_TRISRC_31_T31TDF0 = 0x1f,
    DMA_TRISRC_31_T31TDF1 = 0x1f,
    DMA_TRISRC_31_T32ADF  = 0x1f,

    DMA_TRISRC_32_T13ADF = 0x20,
    DMA_TRISRC_32_T13BDF = 0x20,
    DMA_TRISRC_32_T13CDF = 0x20,
    DMA_TRISRC_32_T13DDF = 0x20,
    DMA_TRISRC_32_T13GDF = 0x20,
    DMA_TRISRC_32_T13DF  = 0x20,
    DMA_TRISRC_32_T13UDF = 0x20,

    DMA_TRISRC_33_T13TDF0 = 0x21,
    DMA_TRISRC_33_T13TDF1 = 0x21,
    DMA_TRISRC_33_T32BDF  = 0x21,
    DMA_TRISRC_33_T32CDF  = 0x21,
    DMA_TRISRC_33_T32DDF  = 0x21,
    DMA_TRISRC_33_T32GDF  = 0x21,
    DMA_TRISRC_33_T32DF   = 0x21,

    DMA_TRISRC_34_T16ADF = 0x22,
    DMA_TRISRC_34_T16BDF = 0x22,
    DMA_TRISRC_34_T16CDF = 0x22,
    DMA_TRISRC_34_T16DDF = 0x22,
    DMA_TRISRC_34_T16GDF = 0x22,
    DMA_TRISRC_34_T16DF  = 0x22,
    DMA_TRISRC_34_T16UDF = 0x22,

    DMA_TRISRC_35_T16TDF0 = 0x23,
    DMA_TRISRC_35_T16TDF1 = 0x23,
    DMA_TRISRC_35_T32UDF  = 0x23,
    DMA_TRISRC_35_T32TDF0 = 0x23,
    DMA_TRISRC_35_T32TDF1 = 0x23,
    DMA_TRISRC_35_T33ADF  = 0x23,
    DMA_TRISRC_35_T33BDF  = 0x23,

    DMA_TRISRC_36_FlexMUX_CH1OUT = 0x24,
    DMA_TRISRC_36_FlexMUX_CH2OUT = 0x24,
    DMA_TRISRC_36_FlexMUX_CH3OUT = 0x24,
    DMA_TRISRC_36_FlexMUX_CH4OUT = 0x24,
    DMA_TRISRC_36_T33CDF         = 0x24,
    DMA_TRISRC_36_T33DDF         = 0x24,
    DMA_TRISRC_36_T33GDF         = 0x24,

    DMA_TRISRC_37_T33DF   = 0x25,
    DMA_TRISRC_37_T33UDF  = 0x25,
    DMA_TRISRC_37_T33TDF0 = 0x25,
    DMA_TRISRC_37_T33TDF1 = 0x25,

    DMA_TRISRC_38_T36ADF = 0x26,
    DMA_TRISRC_38_T36BDF = 0x26,
    DMA_TRISRC_38_T36CDF = 0x26,
    DMA_TRISRC_38_T36DDF = 0x26,
    DMA_TRISRC_38_T36GDF = 0x26,
    DMA_TRISRC_38_T36DF  = 0x26,
    DMA_TRISRC_38_T36UDF = 0x26,

    DMA_TRISRC_39_CMP0    = 0x27,
    DMA_TRISRC_39_CMP1    = 0x27,
    DMA_TRISRC_39_CMP2    = 0x27,
    DMA_TRISRC_39_T36TDF0 = 0x27,
    DMA_TRISRC_39_T36TDF1 = 0x27,

    DMA_TRISRC_NONE = 0x28,
} Dma_TriggerSource_t;
#define CHECK_DMA_TRIGGERSOURCE(x) ((x) <= 0x3FU)

/** 数据块传输模式 */
typedef enum
{
    DMA_BLOCK_TRANSFER_BYTE  = 0x0U,
    DMA_BLOCK_TRANSFER_BLOCK = 0x1U,
} Dma_Block_t;
#define CHECK_DMA_BLOCK(x) (((x) == DMA_BLOCK_TRANSFER_BYTE) || ((x) == DMA_BLOCK_TRANSFER_BLOCK))

/** 数据方向 */
typedef enum
{
    DMA_DATA_DIR_PERIPH_TO_MEM = 0x0U,
    DMA_DATA_DIR_MEM_TO_PERIPH = 0x1U,
} Dma_DataDir_t;
#define CHECK_DMA_DATADIR(x) (((x) == DMA_DATA_DIR_PERIPH_TO_MEM) || ((x) == DMA_DATA_DIR_MEM_TO_PERIPH))

/******************************************************************************
 *                      Export Variables
 ******************************************************************************/
typedef Dma_RegisterMap_t *kpDmaRegM;
/******************************************************************************
 *                      Export Functions
 ******************************************************************************/

/**
 * @brief 设置DMA通道n使能位
 * @param Module DMA 寄存器结构体指针
 * @param DmaChannel DMA通道 Dma_Channel_t
 * @param State
 *          true 使能DMA通道
 *          false 禁止DMA通道
 * @retval void
 */
KF_INLINE void Dma_LL_SetChannelEnabled(Dma_RegisterMap_t *const Module, Dma_Channel_t DmaChannel, bool Enabled)
{
    KF_DMA_ASSERT(CHECK_DMA_ALL_PERIPH_ADDR(Module));
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL(DmaChannel));

    Module->CTL[(uint32_t)DmaChannel].bits.DMAEN = Enabled ? BIT_SET : BIT_CLR;
}

/**
 * @brief: 使能DMA通道n
 * @param Module DMA 寄存器结构体指针
 * @param DmaChannel DMA通道 Dma_Channel_t
 * @retval void
 */
KF_INLINE void Dma_LL_EnableChannel(Dma_RegisterMap_t *const Module, Dma_Channel_t DmaChannel)
{
    Dma_LL_SetChannelEnabled(Module, DmaChannel, true);
}
/**
 * @brief: 禁止DMA通道n
 * @param Module DMA 寄存器结构体指针
 * @param DmaChannel DMA通道 Dma_Channel_t
 * @retval void
 */
KF_INLINE void Dma_LL_DisableChannel(Dma_RegisterMap_t *const Module, Dma_Channel_t DmaChannel)
{
    Dma_LL_SetChannelEnabled(Module, DmaChannel, false);
}

/**
 * @brief 设置DMA通道n暂停控制
 * @param Module DMA 寄存器结构体指针
 * @param DmaChannel DMA通道 Dma_Channel_t
 * @param State
 *          true 暂停DMA通道
 *          false 恢复DMA通道传输
 * @retval void
 */
KF_INLINE void Dma_LL_SetChannelHalt(Dma_RegisterMap_t *const Module, Dma_Channel_t DmaChannel, bool State)
{
    KF_DMA_ASSERT(CHECK_DMA_ALL_PERIPH_ADDR(Module));
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL(DmaChannel));

    Module->CTL[(uint32_t)DmaChannel].bits.DMAHALT = State ? 1U : 0U;
}

/**
 * @brief 设置DMA通道n数据块传输模式
 * @param Module DMA 寄存器结构体指针
 * @param DmaChannel DMA通道 Dma_Channel_t
 * @param State 数据块传输模式, 具体取值见 Dma_Block_t
 * @retval void
 */
KF_INLINE void Dma_LL_SetBlockMode(Dma_RegisterMap_t *const Module, Dma_Channel_t DmaChannel, Dma_Block_t State)
{
    KF_DMA_ASSERT(CHECK_DMA_ALL_PERIPH_ADDR(Module));
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL(DmaChannel));
    KF_DMA_ASSERT(CHECK_DMA_BLOCK(State));

    Module->CTL[(uint32_t)DmaChannel].bits.BLKM = (uint32_t)State;
}

/**
 * @brief 设置DMA通道n数据方向控制
 * @param Module DMA 寄存器结构体指针
 * @param DmaChannel DMA通道 Dma_Channel_t
 * @param State 数据传输方向, 具体取值见 Dma_DataDir_t
 * @retval void
 */
KF_INLINE void Dma_LL_SetDataDirection(Dma_RegisterMap_t *const Module, Dma_Channel_t DmaChannel, Dma_DataDir_t State)
{
    KF_DMA_ASSERT(CHECK_DMA_ALL_PERIPH_ADDR(Module));
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL(DmaChannel));
    KF_DMA_ASSERT(CHECK_DMA_DATADIR(State));

    Module->CTL[(uint32_t)DmaChannel].bits.DDIR = (uint32_t)State;
}

/**
 * @brief 设置DMA通道n循环模式
 * @param Module DMA 寄存器结构体指针
 * @param DmaChannel DMA通道 Dma_Channel_t
 * @param State
 *          true 循环传输
 *          false 单次传输
 * @retval void
 */
KF_INLINE void Dma_LL_SetLoopModeEnabled(Dma_RegisterMap_t *const Module, Dma_Channel_t DmaChannel, bool State)
{
    KF_DMA_ASSERT(CHECK_DMA_ALL_PERIPH_ADDR(Module));
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL(DmaChannel));

    Module->CTL[(uint32_t)DmaChannel].bits.LPM = State ? 1U : 0U;
}

/**
 * @brief 设置DMA通道n存储器地址增量模式
 * @param Module DMA 寄存器结构体指针
 * @param DmaChannel DMA通道 Dma_Channel_t
 * @param State
 *          true 存储器地址自动增量
 *          false 存储器地址不自动增量
 * @retval void
 */
KF_INLINE void Dma_LL_SetMemAddrIncrement(Dma_RegisterMap_t *const Module, Dma_Channel_t DmaChannel, bool State)
{
    KF_DMA_ASSERT(CHECK_DMA_ALL_PERIPH_ADDR(Module));
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL(DmaChannel));

    Module->CTL[(uint32_t)DmaChannel].bits.MINC = State ? 1U : 0U;
}

/**
 * @brief 设置DMA通道n外设地址增量模式
 * @param Module DMA 寄存器结构体指针
 * @param DmaChannel DMA通道 Dma_Channel_t
 * @param State
 *          true 外设地址自动增量
 *          false 外设地址不自动增量
 * @retval void
 */
KF_INLINE void Dma_LL_SetPeriphAddrIncrement(Dma_RegisterMap_t *const Module, Dma_Channel_t DmaChannel, bool State)
{
    KF_DMA_ASSERT(CHECK_DMA_ALL_PERIPH_ADDR(Module));
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL(DmaChannel));

    Module->CTL[(uint32_t)DmaChannel].bits.PINC = State ? 1U : 0U;
}

/**
 * @brief 设置DMA通道n存储器传输数据宽度
 * @param Module DMA 寄存器结构体指针
 * @param DmaChannel DMA通道 Dma_Channel_t
 * @param Width Dma_DataWidth_t
 * @retval void
 */
KF_INLINE void Dma_LL_SetMemDataWidth(Dma_RegisterMap_t *const Module, Dma_Channel_t DmaChannel, Dma_DataWidth_t Width)
{
    KF_DMA_ASSERT(CHECK_DMA_ALL_PERIPH_ADDR(Module));
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL(DmaChannel));
    KF_DMA_ASSERT(CHECK_DMA_DATAWIDTH(Width));

    Module->CTL[(uint32_t)DmaChannel].bits.MDS = (uint32_t)Width;
}

/**
 * @brief 设置DMA通道n外设传输数据宽度
 * @param Module DMA 寄存器结构体指针
 * @param DmaChannel DMA通道 Dma_Channel_t
 * @param Width Dma_DataWidth_t
 * @retval void
 */
KF_INLINE void
Dma_LL_SetPeriphDataWidth(Dma_RegisterMap_t *const Module, Dma_Channel_t DmaChannel, Dma_DataWidth_t Width)
{
    KF_DMA_ASSERT(CHECK_DMA_ALL_PERIPH_ADDR(Module));
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL(DmaChannel));
    KF_DMA_ASSERT(CHECK_DMA_DATAWIDTH(Width));

    Module->CTL[(uint32_t)DmaChannel].bits.PDS = (uint32_t)Width;
}

/**
 * @brief 设置DMA通道n单次触发模式使能状态
 * @param Module DMA 寄存器结构体指针
 * @param DmaChannel DMA通道 Dma_Channel_t
 * @param State
 *          true 使能单次触发模式
 *          false 禁止单次触发模式
 * @retval void
 */
KF_INLINE void Dma_LL_SetOneShotEnabled(Dma_RegisterMap_t *const Module, Dma_Channel_t DmaChannel, bool State)
{
    KF_DMA_ASSERT(CHECK_DMA_ALL_PERIPH_ADDR(Module));
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL(DmaChannel));

    Module->CTL[(uint32_t)DmaChannel].bits.ONESHOT = State ? 1U : 0U;
}

/**
 * @brief 设置DMA通道n通道优先级
 * @param Module DMA 寄存器结构体指针
 * @param DmaChannel DMA通道 Dma_Channel_t
 * @param Priority 优先级 Dma_Priority_t
 * @retval void
 */
KF_INLINE void
Dma_LL_SetChannelPriority(Dma_RegisterMap_t *const Module, Dma_Channel_t DmaChannel, Dma_Priority_t Priority)
{
    KF_DMA_ASSERT(CHECK_DMA_ALL_PERIPH_ADDR(Module));
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL(DmaChannel));
    KF_DMA_ASSERT(CHECK_DMA_PRIORITY(Priority));

    Module->CTL[(uint32_t)DmaChannel].bits.CPL = (uint32_t)Priority;
}

/**
 * @brief 设置DMA通道n存储器到存储器传输使能状态
 * @param Module DMA 寄存器结构体指针
 * @param DmaChannel DMA通道 Dma_Channel_t
 * @param State
 *          true 使能存储器到存储器传输
 *          false 禁止存储器到存储器传输
 * @retval void
 */
KF_INLINE void Dma_LL_SetMemToMemEnabled(Dma_RegisterMap_t *const Module, Dma_Channel_t DmaChannel, bool State)
{
    KF_DMA_ASSERT(CHECK_DMA_ALL_PERIPH_ADDR(Module));
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL(DmaChannel));

    Module->CTL[(uint32_t)DmaChannel].bits.M2M = State ? 1U : 0U;
}

/**
 * @brief 设置DMA通道n传输数据个数
 * @param Module DMA 寄存器结构体指针
 * @param DmaChannel DMA通道 Dma_Channel_t
 * @param Number 数据个数,取值范围为 0x0000 ~ 0xFFFF
 * @retval void
 */
KF_INLINE void Dma_LL_SetNumberOfData(Dma_RegisterMap_t *const Module, Dma_Channel_t DmaChannel, uint16_t Number)
{
    KF_DMA_ASSERT(CHECK_DMA_ALL_PERIPH_ADDR(Module));
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL(DmaChannel));

    Module->CTL[(uint32_t)DmaChannel].bits.NUMODT = Number;
}

/**
 * @brief 设置DMA通道n外设地址
 * @param Module DMA 寄存器结构体指针
 * @param DmaChannel DMA通道 Dma_Channel_t
 * @param PeripheralAddr 外设地址
 * @retval void
 */
KF_INLINE void Dma_LL_SetPeriphAddr(Dma_RegisterMap_t *const Module, Dma_Channel_t DmaChannel, uint32_t PeripheralAddr)
{
    Module->PADDR[(uint32_t)DmaChannel] = PeripheralAddr;
}

/**
 * @brief 设置DMA通道n内存地址
 * @param Module DMA 寄存器结构体指针
 * @param DmaChannel DMA通道 Dma_Channel_t
 * @param MemoryAddr 内存地址
 * @retval void
 */
KF_INLINE void Dma_LL_SetMemAddr(Dma_RegisterMap_t *const Module, Dma_Channel_t DmaChannel, uint32_t MemoryAddr)
{
    Module->MADDR[(uint32_t)DmaChannel] = MemoryAddr;
}

/**
 * @brief 获取DMA通道n当前外设地址
 * @param Module DMA 寄存器结构体指针
 * @param DmaChannel DMA通道 Dma_Channel_t
 * @retval uint32_t 当前外设地址
 */
KF_INLINE uint32_t Dma_LL_GetCurrentPeriphAddr(const Dma_RegisterMap_t *const Module, Dma_Channel_t DmaChannel)
{
    KF_DMA_ASSERT(CHECK_DMA_ALL_PERIPH_ADDR(Module));
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL(DmaChannel));

    return Module->CPAR[(uint32_t)DmaChannel];
}

/**
 * @brief 获取DMA通道n当前内存地址
 * @param Module DMA 寄存器结构体指针
 * @param DmaChannel DMA通道 Dma_Channel_t
 * @retval uint32_t 当前内存地址
 */
KF_INLINE uint32_t Dma_LL_GetCurrentMemAddr(const Dma_RegisterMap_t *const Module, Dma_Channel_t DmaChannel)
{
    KF_DMA_ASSERT(CHECK_DMA_ALL_PERIPH_ADDR(Module));
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL(DmaChannel));

    return Module->CMAR[(uint32_t)DmaChannel];
}

/**
 * @brief 获取DMA通道n的当前剩余数据量
 * @param Module  DMA 寄存器结构体指针
 * @param DmaChannel DMA通道 Dma_Channel_t
 * @retval remain number
 */
KF_INLINE uint16_t Dma_LL_GetRemainingTransNum(const Dma_RegisterMap_t *const Module, Dma_Channel_t DmaChannel)
{
    KF_DMA_ASSERT(CHECK_DMA_ALL_PERIPH_ADDR(Module));
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL(DmaChannel));

    return (uint16_t)Module->NCT[(uint32_t)DmaChannel].bits.NCT;
}

/**
 * @brief 获取DMA通道n的完成传输中断标志位
 * @param Module DMA 寄存器结构体指针
 * @param DmaChannel DMA通道 Dma_Channel_t
 * @retval true 完成传输中断标志位被置位
 * @retval false 完成传输中断标志位未被置位
 */
KF_INLINE bool Dma_LL_GetFinishTransIntrFlag(const Dma_RegisterMap_t *const Module, Dma_Channel_t DmaChannel)
{
    KF_DMA_ASSERT(CHECK_DMA_ALL_PERIPH_ADDR(Module));
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL(DmaChannel));

    uint32_t Mask;

    Mask = 3U * (uint32_t)DmaChannel;
    /* PRQA S 3469 1 #KQR003469 */
    return (REG_BITS_READ(Module->LIFR.reg, 0x1UL << Mask, Mask) != 0U);
}

/**
 * @brief 清除DMA完成传输中断标志
 *
 * @param Module 寄存器结构体指针
 * @param DmaChannel DMA通道 Dma_Channel_t
 * @retval void
 */
KF_INLINE void Dma_LL_ClearFinishTransIntrFlag(Dma_RegisterMap_t *const Module, Dma_Channel_t DmaChannel)
{
    KF_DMA_ASSERT(CHECK_DMA_ALL_PERIPH_ADDR(Module));
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL(DmaChannel));

    uint32_t Pos;

    Pos              = 3U * (uint32_t)DmaChannel;
    Module->LIFR.reg = ~(1UL << Pos);
}

/**
 * @brief 获取DMA通道n的半传输中断标志位
 * @param Module DMA 寄存器结构体指针
 * @param DmaChannel DMA通道 Dma_Channel_t
 * @retval true 半传输中断标志位被置位
 * @retval false 半传输中断标志位未被置位
 */
KF_INLINE bool Dma_LL_GetHalfTransIntrFlag(const Dma_RegisterMap_t *const Module, Dma_Channel_t DmaChannel)
{
    KF_DMA_ASSERT(CHECK_DMA_ALL_PERIPH_ADDR(Module));
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL(DmaChannel));

    uint32_t Mask;

    Mask = (3U * (uint32_t)DmaChannel) + 1U;
    /* PRQA S 3469 1 #KQR003469 */
    return (REG_BITS_READ(Module->LIFR.reg, 0x1UL << Mask, Mask) != 0U);
}

/**
 * @brief 清除半传输中断标志位
 *
 * @param Module DMA 寄存器结构体指针
 * @param DmaChannel DMA通道 Dma_Channel_t
 * @retval void
 */
KF_INLINE void Dma_LL_ClearHalfTransIntrFlag(Dma_RegisterMap_t *const Module, Dma_Channel_t DmaChannel)
{
    KF_DMA_ASSERT(CHECK_DMA_ALL_PERIPH_ADDR(Module));
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL(DmaChannel));

    uint32_t Pos;

    Pos              = (3U * (uint32_t)DmaChannel) + 1U;
    Module->LIFR.reg = ~(1UL << Pos);
}

/**
 * @brief 获取DMA通道n的错误传输中断标志位
 * @param Module DMA 寄存器结构体指针
 * @param DmaChannel DMA通道 Dma_Channel_t
 * @retval true 错误传输中断标志位被置位
 * @retval false 错误传输中断标志位未被置位
 */
KF_INLINE bool Dma_LL_GetErrorTransIntrFlag(const Dma_RegisterMap_t *const Module, Dma_Channel_t DmaChannel)
{
    KF_DMA_ASSERT(CHECK_DMA_ALL_PERIPH_ADDR(Module));
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL(DmaChannel));

    uint32_t Mask;

    Mask = (3U * (uint32_t)DmaChannel) + 2U;
    /* PRQA S 3469 1 #KQR003469 */
    return (REG_BITS_READ(Module->LIFR.reg, 0x1UL << Mask, Mask) != 0U);
}

/**
 * @brief 清除错误传输中断标志位
 *
 * @param Module DMA 寄存器结构体指针
 * @param DmaChannel DMA通道 Dma_Channel_t
 * @retval void
 */
KF_INLINE void Dma_LL_ClearErrorTransIntrFlag(Dma_RegisterMap_t *const Module, Dma_Channel_t DmaChannel)
{
    KF_DMA_ASSERT(CHECK_DMA_ALL_PERIPH_ADDR(Module));
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL(DmaChannel));

    uint32_t Pos;

    Pos              = (3U * (uint32_t)DmaChannel) + 2U;
    Module->LIFR.reg = ~(1UL << Pos);
}

/**
 * @brief 设置DMA通道n的完成传输中断使能位
 * @param Module DMA 寄存器结构体指针
 * @param DmaChannel DMA通道 Dma_Channel_t
 * @param State
 *          true 使能完成传输中断使能
 *          false 禁止完成传输中断使能
 *
 */
KF_INLINE void Dma_LL_SetFinishTransIntrEnabled(Dma_RegisterMap_t *const Module, Dma_Channel_t DmaChannel, bool State)
{
    KF_DMA_ASSERT(CHECK_DMA_ALL_PERIPH_ADDR(Module));
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL(DmaChannel));

    uint32_t Mask;

    Mask = 3U * (uint32_t)DmaChannel;
    REG_BITS_WRITE(Module->LIER.reg, 0x1UL << Mask, (State ? 1UL : 0UL) << Mask);
}

/**
 * @brief 设置DMA通道n的半传输中断使能位
 * @param Module DMA 寄存器结构体指针
 * @param DmaChannel DMA通道 Dma_Channel_t
 * @param State
 *          true 使能半传输中断使能
 *          false 禁止半传输中断使能
 */
KF_INLINE void Dma_LL_SetHalfTransIntrEnabled(Dma_RegisterMap_t *const Module, Dma_Channel_t DmaChannel, bool State)
{
    KF_DMA_ASSERT(CHECK_DMA_ALL_PERIPH_ADDR(Module));
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL(DmaChannel));

    uint32_t Mask;

    Mask = (3U * (uint32_t)DmaChannel) + 1U;
    REG_BITS_WRITE(Module->LIER.reg, 0x1UL << Mask, (State ? 1UL : 0UL) << Mask);
}

/**
 * @brief 设置DMA通道n的错误传输中断使能位
 * @param Module DMA 寄存器结构体指针
 * @param DmaChannel DMA通道 Dma_Channel_t
 * @param State
 *          true 使能错误传输中断使能
 *          false 禁止错误传输中断使能
 */
KF_INLINE void Dma_LL_SetErrorTransIntrEnabled(Dma_RegisterMap_t *const Module, Dma_Channel_t DmaChannel, bool State)
{
    KF_DMA_ASSERT(CHECK_DMA_ALL_PERIPH_ADDR(Module));
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL(DmaChannel));

    uint32_t Mask;

    Mask = (3U * (uint32_t)DmaChannel) + 2U;
    REG_BITS_WRITE(Module->LIER.reg, 0x1UL << Mask, (State ? 1UL : 0UL) << Mask);
}

/**
 * @brief set dma channel half finish\finish\error interrupt enable
 * @param Module DMA 寄存器结构体指针
 * @param DmaChannel DMA通道 Dma_Channel_t
 * @param Type Dma_LifrMask_t
 * @retval void
 */
KF_INLINE void Dma_LL_EnableIntr(Dma_RegisterMap_t *const Module, Dma_Channel_t DmaChannel, Dma_LifrMask_t Type)
{
    KF_DMA_ASSERT(CHECK_DMA_ALL_PERIPH_ADDR(Module));
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL(DmaChannel));
    KF_DMA_ASSERT(CHECK_DMA_LIFRMASK(Type));

    uint32_t Mask = 0U;

    Mask = (uint32_t)Type << ((uint32_t)DmaChannel * 3U);

    REG_BIT_SET(Module->LIER.reg, Mask);
}

/**
 * @brief set dma channel half finish\finish\error interrupt disable
 * @param Module DMA 寄存器结构体指针
 * @param DmaChannel DMA通道 Dma_Channel_t
 * @param Type Dma_LifrMask_t
 * @retval void
 */
KF_INLINE void Dma_LL_DisableIntr(Dma_RegisterMap_t *const Module, Dma_Channel_t DmaChannel, Dma_LifrMask_t Type)
{
    KF_DMA_ASSERT(CHECK_DMA_ALL_PERIPH_ADDR(Module));
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL(DmaChannel));
    KF_DMA_ASSERT(CHECK_DMA_LIFRMASK(Type));

    uint32_t Mask = 0U;

    Mask = (uint32_t)Type << ((uint32_t)DmaChannel * 3U);

    REG_BIT_CLR(Module->LIER.reg, Mask);
}

/**
 * @brief 获取DMA中断使能状态
 *
 * @param Module DMA 寄存器结构体指针
 * @param DmaChannel DMA通道 Dma_Channel_t
 * @param Type 中断类型, 见 Dma_LifrMask_t, 必须为单比特掩码(FINISH/HALF/ERROR)
 * @retval bool 中断状态
 */
KF_INLINE bool
Dma_LL_GetIntrEnabledState(const Dma_RegisterMap_t *const Module, Dma_Channel_t DmaChannel, Dma_LifrMask_t Type)
{
    KF_DMA_ASSERT(CHECK_DMA_ALL_PERIPH_ADDR(Module));
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL(DmaChannel));
    KF_DMA_ASSERT(CHECK_DMA_LIFR_SINGLE_MASK(Type));

    uint32_t Pos;
    uint32_t Mask;

    Pos  = (uint32_t)DmaChannel * 3U;
    Mask = (uint32_t)Type << Pos;
    /* PRQA S 3469 1 #KQR003469 */
    return (REG_BITS_READ(Module->LIER.reg, Mask, Pos) != 0U);
}

/**
 * @brief clear dma channel half finish\finish\error flag
 * @param Module DMA 寄存器结构体指针
 * @param DmaChannel DMA通道 Dma_Channel_t
 * @param Type Dma_LifrMask_t
 * @retval void
 */
KF_INLINE void Dma_LL_ClearIntrFlag(Dma_RegisterMap_t *const Module, Dma_Channel_t DmaChannel, Dma_LifrMask_t Type)
{
    KF_DMA_ASSERT(CHECK_DMA_ALL_PERIPH_ADDR(Module));
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL(DmaChannel));
    KF_DMA_ASSERT(CHECK_DMA_LIFRMASK(Type));

    uint32_t Mask;

    Mask             = (uint32_t)Type << ((uint32_t)DmaChannel * 3U);
    Module->LIFR.reg = ~Mask;
}

/**
 * @brief 获取DMA中断标志
 *
 * @param Module DMA 寄存器结构体指针
 * @param DmaChannel DMA通道 Dma_Channel_t
 * @param Type 中断类型, 见 Dma_LifrMask_t, 必须为单比特掩码(FINISH/HALF/ERROR)
 * @retval bool 中断状态
 */
KF_INLINE bool Dma_LL_GetIntrFlag(const Dma_RegisterMap_t *const Module, Dma_Channel_t DmaChannel, Dma_LifrMask_t Type)
{
    KF_DMA_ASSERT(CHECK_DMA_ALL_PERIPH_ADDR(Module));
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL(DmaChannel));
    KF_DMA_ASSERT(CHECK_DMA_LIFR_SINGLE_MASK(Type));

    uint32_t Pos;
    uint32_t Mask;

    Pos  = (uint32_t)DmaChannel * 3U;
    Mask = (uint32_t)Type << Pos;
    /* PRQA S 3469 1 #KQR003469 */
    return (REG_BITS_READ(Module->LIFR.reg, Mask, Pos) != 0U);
}

/**
 * @brief:配置DMA通道触发源
 * @param Module 指向DMA内存结构的指针
 * @param DmaChannel DMA通道 Dma_Channel_t
 * @param TrigSource 触发源选择,Dma_TriggerSource_t
 * @retval void
 */
KF_INLINE void
Dma_LL_SelectTrigSource(Dma_RegisterMap_t *const Module, Dma_Channel_t DmaChannel, Dma_TriggerSource_t TrigSource)
{
    KF_DMA_ASSERT(CHECK_DMA_ALL_PERIPH_ADDR(Module));
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL(DmaChannel));
    KF_DMA_ASSERT(CHECK_DMA_TRIGGERSOURCE(TrigSource));

    uint32_t Pos = 0U;

    if (DmaChannel < DMA_CHANNEL_5)
    {
        Pos = (uint32_t)DmaChannel << 3U;
        REG_BITS_WRITE(Module->MUXL.reg, (0x3FUL << Pos), ((uint32_t)TrigSource << Pos));
    }
    else
    {
        Pos = ((uint32_t)DmaChannel - (uint32_t)DMA_CHANNEL_5) << 3U;
        REG_BITS_WRITE(Module->MUXH.reg, (0x3FUL << Pos), ((uint32_t)TrigSource << Pos));
    }
}

/**
 * @brief: 配置DMA通道触发使能.
 * @param Module 指向DMA内存结构的指针
 * @param DmaChannel DMA通道 Dma_Channel_t
 * @param State
 * @retval void
 */
KF_INLINE void Dma_LL_SetTriggerEnabled(Dma_RegisterMap_t *const Module, Dma_Channel_t DmaChannel, bool State)
{
    KF_DMA_ASSERT(CHECK_DMA_ALL_PERIPH_ADDR(Module));
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL(DmaChannel));

    uint32_t Pos = 0U;

    if (DmaChannel < DMA_CHANNEL_5)
    {
        Pos = (((uint32_t)DmaChannel << 3U) + 7U);
        REG_BITS_WRITE(Module->MUXL.reg, (0x1UL << Pos), ((State ? 1UL : 0UL) << Pos));
    }
    else
    {
        Pos = ((((uint32_t)DmaChannel - (uint32_t)DMA_CHANNEL_5) << 3U) + 7U);
        REG_BITS_WRITE(Module->MUXH.reg, (0x1UL << Pos), ((State ? 1UL : 0UL) << Pos));
    }
}

/**
 * @brief: 获取中断标志位.
 * @param Module 指向DMA内存结构的指针
 * @retval uint32_t 中断标志位
 */
KF_INLINE uint32_t Dma_LL_GetAllActiveIntrBits(const Dma_RegisterMap_t *const Module)
{
    uint32_t tmpLIER = Module->LIER.reg;
    uint32_t tmpLIFR = Module->LIFR.reg;
    return ((tmpLIER & tmpLIFR) & 0x001FFFFFU);
}

/**
 * @brief 获取DMA中断发生状态
 *
 * @param Module DMA 寄存器结构体指针
 * @param DmaChannel DMA通道 Dma_Channel_t
 * @param Type 中断类型, 见 Dma_LifrMask_t, 不包括 DMA_LIFR_ALLIF_LOGIC_BIT
 * @retval bool 中断发生状态
 *         true    发生了中断，且已使能
 *         false    未发生中断，或未使能
 */
KF_INLINE bool Dma_LL_GetIntrState(const Dma_RegisterMap_t *const Module, Dma_Channel_t DmaChannel, Dma_LifrMask_t Type)
{
    KF_DMA_ASSERT(CHECK_DMA_ALL_PERIPH_ADDR(Module));
    KF_DMA_ASSERT(CHECK_DMA_CHANNEL(DmaChannel));
    KF_DMA_ASSERT(CHECK_DMA_LIFRMASK(Type));

    uint32_t Pos;
    uint32_t Mask;
    uint32_t flag;
    uint32_t state;

    Pos  = (uint32_t)DmaChannel * 3U;
    Mask = (uint32_t)Type << Pos;
    /* PRQA S 3469 ++ #KQR003469 */
    flag  = REG_BITS_READ(Module->LIFR.reg, Mask, Pos);
    state = REG_BITS_READ(Module->LIER.reg, Mask, Pos);
    /* PRQA S 3469 -- #KQR003469 */
    return (flag & state) != 0U;
}

#ifdef __cplusplus
}
#endif /*End of __cplusplus*/
#endif /*End of KF32A158SF_DRV_DMA_H*/
/* EOF */
