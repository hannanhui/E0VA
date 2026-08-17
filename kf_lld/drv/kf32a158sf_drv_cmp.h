/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name        : kf32a158sf_drv_cmp.h
 *  @Date             : 2025-07-07
 *  @Version          : {{VersionDate}}
 *  @Description      : This file provides the driver functions for the CMP module.
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
#ifndef KF32A158SF_DRV_CMP_H
#define KF32A158SF_DRV_CMP_H

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
/* PRQA S 3469 EOF #KQR003469 */

/******************************************************************************
 *                      Include Files
 ******************************************************************************/
#include <stdint.h>
#include <stdbool.h>
#include "kf_types.h"
#include "kf32a158sf_reg_cmp.h"

#ifdef KF_DRV_CMP_ASSERT
#include "dev_assert.h"
#define KF_CMP_ASSERT(x) KF_DEV_ASSERT(x)
#else
#define KF_CMP_ASSERT(x) ((void)0U)
#endif

/******************************************************************************
 *                      Macro or Inline
 ******************************************************************************/

/******************************************************************************
 *                      Type definitions
 ******************************************************************************/

/*
CMP clock source select
*/
typedef enum
{
    CMP_SCLK,
    CMP_HFCLK,
} Cmp_ClockSource_t;
#define CHECK_CMP_CLOCKSOURCE(x) (((x) == SCLK) || ((x) == HFCLK))

/*
CMP digital out select
*/
typedef enum
{
    CMP0_DIGITALOUT_CMP0,
    CMP1_DIGITALOUT_CMP1,
    CMP2_DIGITALOUT_CMP2,
    CMP3_DIGITALOUT_CMP3,
} Cmp_DigitalOutSelect_t;
#define CHECK_CMP_DIGITALOUTSELECT(x)                                                                                  \
    (((x) == CMP0_DIGITALOUT_CMP0) || ((x) == CMP1_DIGITALOUT_CMP1) || ((x) == CMP2_DIGITALOUT_CMP2) ||                \
     ((x) == CMP3_DIGITALOUT_CMP3))

typedef enum
{
    CMP_PSCAN_CHANNEL0,  /*!< 通道 0(PA0)*/
    CMP_PSCAN_CHANNEL1,  /*!< 通道 1(PA9)*/
    CMP_PSCAN_CHANNEL2,  /*!< 通道 2(PB2)*/
    CMP_PSCAN_CHANNEL3,  /*!< 通道 3(PB9)*/
    CMP_PSCAN_CHANNEL4,  /*!< 通道 4(PC11)*/
    CMP_PSCAN_CHANNEL5,  /*!< 通道 5(AGND)*/
    CMP_PSCAN_CHANNEL6,  /*!< 通道 6(DAC0_OUT)*/
    CMP_PSCAN_CHANNEL7,  /*!< 通道 7(DAC1_OUT)*/
    CMP_PSCAN_CHANNEL8,  /*!< 通道 8(PA3)*/
    CMP_PSCAN_CHANNEL9,  /*!< 通道 9(PA4)*/
    CMP_PSCAN_CHANNEL10, /*!< 通道 10(PA5)*/
    CMP_PSCAN_CHANNEL11, /*!< 通道 11(PD9)*/
    CMP_PSCAN_CHANNEL12, /*!< 通道 12(PG1)*/
    CMP_PSCAN_CHANNEL13, /*!< 通道 13(PG2)*/
    CMP_PSCAN_CHANNEL14, /*!< 通道 14(PD14)*/
    CMP_PSCAN_CHANNEL15, /*!< 通道 15(PE7)*/
} Cmp_PscanChannel_t;
#define CHECK_CMP_PSCANCHANNEL(x) (((x) >= CMP_PSCAN_CHANNEL0) && ((x) <= CMP_PSCAN_CHANNEL15))

typedef enum
{
    CMP_NSCAN_CHANNEL0,  /*!< 通道 0(PA0)*/
    CMP_NSCAN_CHANNEL1,  /*!< 通道 1(PA9)*/
    CMP_NSCAN_CHANNEL2,  /*!< 通道 2(PB2)*/
    CMP_NSCAN_CHANNEL3,  /*!< 通道 3(PB9)*/
    CMP_NSCAN_CHANNEL4,  /*!< 通道 4(PC11)*/
    CMP_NSCAN_CHANNEL5,  /*!< 通道 5(AGND)*/
    CMP_NSCAN_CHANNEL6,  /*!< 通道 6(DAC0_OUT)*/
    CMP_NSCAN_CHANNEL7,  /*!< 通道 7(DAC1_OUT)*/
    CMP_NSCAN_CHANNEL8,  /*!< 通道 8(PA3)*/
    CMP_NSCAN_CHANNEL9,  /*!< 通道 9(PA4)*/
    CMP_NSCAN_CHANNEL10, /*!< 通道 10(PA5)*/
    CMP_NSCAN_CHANNEL11, /*!< 通道 11(PD9)*/
    CMP_NSCAN_CHANNEL12, /*!< 通道 12(PG1)*/
    CMP_NSCAN_CHANNEL13, /*!< 通道 13(PG2)*/
    CMP_NSCAN_CHANNEL14, /*!< 通道 14(PD14)*/
    CMP_NSCAN_CHANNEL15, /*!< 通道 15(PE7)*/
} Cmp_NscanChannel_t;
#define CHECK_CMP_NSCANCHANNEL(x) (((x) >= CMP_NSCAN_CHANNEL0) && ((x) <= CMP_NSCAN_CHANNEL15))

/** 比较结果采样时刻 */
typedef enum
{
    CMP_SAMPLE_IMMEDIATE = 0x0U,
    CMP_SAMPLE_DELAY_1_CLOCK,
    CMP_SAMPLE_DELAY_2_CLOCK,
    CMP_SAMPLE_DELAY_3_CLOCK,
} Cmp_SampleTime_t;
#define CHECK_CMP_SAMPLETIME(x)                                                                                        \
    (((x) == CMP_SAMPLE_IMMEDIATE) || ((x) == CMP_SAMPLE_DELAY_1_CLOCK) || ((x) == CMP_SAMPLE_DELAY_2_CLOCK) ||        \
     ((x) == CMP_SAMPLE_DELAY_3_CLOCK))

/** CMP0 正端输入选择 */
typedef enum
{
    CMP_POSITIVE_INPUT_C0_1 = 0x0U,
    CMP_POSITIVE_INPUT_C0_2,
    CMP_POSITIVE_INPUT_C0_3,
    CMP_POSITIVE_INPUT_PMOD,
} Cmp_PositiveInput_t;
#define CHECK_CMP_POSITIVEINPUT(x)                                                                                     \
    (((x) == CMP_POSITIVE_INPUT_C0_1) || ((x) == CMP_POSITIVE_INPUT_C0_2) || ((x) == CMP_POSITIVE_INPUT_C0_3) ||       \
     ((x) == CMP_POSITIVE_INPUT_PMOD))

/** 滤波脉宽 */
typedef enum
{
    CMP_FILTER_WIDTH_NONE = 0x0U,
    CMP_FILTER_WIDTH_1_CLOCK,
    CMP_FILTER_WIDTH_2_CLOCK,
    CMP_FILTER_WIDTH_3_CLOCK,
    CMP_FILTER_WIDTH_4_CLOCK,
    CMP_FILTER_WIDTH_5_CLOCK,
    CMP_FILTER_WIDTH_6_CLOCK,
    CMP_FILTER_WIDTH_7_CLOCK,
} Cmp_FilterWidth_t;
#define CHECK_CMP_FILTERWIDTH(x) (((x) >= CMP_FILTER_WIDTH_NONE) && ((x) <= CMP_FILTER_WIDTH_7_CLOCK))

/** CMP正端/负端输入 */
#define CHECK_CMP_INPUT(x) (((x) >= 0x0U) && ((x) <= 0xFU))

/** CMP模拟输出 */
typedef enum
{
    CMP_AN_OUTPUT_NONE = 0x0U,
    CMP_AN_OUTPUT_CMP0,
    CMP_AN_OUTPUT_CMP1,
    CMP_AN_OUTPUT_CMP2,
} Cmp_Output2Io_t;
#define CHECK_CMP_OUTPUT2IO(x)                                                                                         \
    (((x) == CMP_AN_OUTPUT_NONE) || ((x) == CMP_AN_OUTPUT_CMP0) || ((x) == CMP_AN_OUTPUT_CMP1) ||                      \
     ((x) == CMP_AN_OUTPUT_CMP2))

/** 比较器初始化延迟系数 */
#define CHECK_CMP_INIT_DELAY(x) (((x) >= 0x0U) && ((x) >= 0x3FU))

/**CMP设置中断序号*/
typedef enum
{
    CMP_INTR_SET_INDEX_C0IE = 12U,
    CMP_INTR_SET_INDEX_C1IE = 13U,
    CMP_INTR_SET_INDEX_C2IE = 14U,
    CMP_INTR_SET_INDEX_C3IE = 15U,
} Cmp_IntrSetIndex_t;
#define CHECK_CMP_INTRSETINDEX(x) (((x) >= CMP_INTR_SET_INDEX_C0IE) && ((x) <= CMP_INTR_SET_INDEX_C0IE))

/**CMP清除中断序号*/
typedef enum
{
    CMP_INTR_CLEAR_INDEX_C0IC = 16U,
    CMP_INTR_CLEAR_INDEX_C1IC = 17U,
    CMP_INTR_CLEAR_INDEX_C2IC = 18U,
    CMP_INTR_CLEAR_INDEX_C3IC = 19U,
} Cmp_IntrClearIndex_t;
#define CHECK_CMP_INTRCLEARINDEX(x) (((x) >= CMP_INTR_CLEAR_INDEX_C0IC) && ((x) <= CMP_INTR_CLEAR_INDEX_C3IC))

/**CMP获取中断序号*/
typedef enum
{
    CMP_INTR_GET_INDEX_C0IF = 24U,
    CMP_INTR_GET_INDEX_C1IF = 25U,
    CMP_INTR_GET_INDEX_C2IF = 26U,
    CMP_INTR_GET_INDEX_C3IF = 27U,
} Cmp_IntrGetIndex_t;
#define CHECK_CMP_INTRGETINDEX(x) (((x) >= CMP_INTR_GET_INDEX_C0IF) && ((x) <= CMP_INTR_GET_INDEX_C3IF))

/**CMP DMA获取标志序号*/
typedef enum
{
    CMP_DMA_GET_INDEX_CMP0DMAIF = 20U,
    CMP_DMA_GET_INDEX_CMP1DMAIF = 21U,
    CMP_DMA_GET_INDEX_CMP2DMAIF = 22U,
    CMP_DMA_GET_INDEX_CMP3DMAIF = 23U,
} Cmp_DmaGetIndex_t;
#define CHECK_CMP_DMAGETINDEX(x) (((x) >= CMP_DMA_GET_INDEX_CMP0DMAIF) && ((x) <= CMP_DMA_GET_INDEX_CMP3DMAIF))

typedef enum
{
    CMP0_POSITIVE_INPUT_PA0  = 0U,
    CMP0_POSITIVE_INPUT_PA9  = 1U,
    CMP0_POSITIVE_INPUT_PC11 = 4U,
    CMP0_POSITIVE_INPUT_AGND = 5U,
    CMP0_POSITIVE_INPUT_PA3  = 8U,
    CMP0_POSITIVE_INPUT_PE8  = 9U,
    CMP0_POSITIVE_INPUT_PE9  = 10U,
    CMP0_POSITIVE_INPUT_PG4  = 11U,
    CMP0_POSITIVE_INPUT_PC0  = 12U,
    CMP0_POSITIVE_INPUT_PC15 = 13U,
    CMP0_POSITIVE_INPUT_PD14 = 14U,
    CMP0_POSITIVE_INPUT_PE7  = 15U,

} Cmp0_PositiveInput_t;

typedef enum
{
    CMP1_POSITIVE_INPUT_PA0  = 0U,
    CMP1_POSITIVE_INPUT_PA9  = 1U,
    CMP1_POSITIVE_INPUT_AGND = 5U,
    CMP1_POSITIVE_INPUT_PG0  = 8U,
    CMP1_POSITIVE_INPUT_PD7  = 10U,
    CMP1_POSITIVE_INPUT_PC15 = 11U,
    CMP1_POSITIVE_INPUT_PA4  = 13U,
    CMP1_POSITIVE_INPUT_PD14 = 14U,

} Cmp1_PositiveInput_t;

typedef enum
{
    CMP2_POSITIVE_INPUT_PA0  = 0U,
    CMP2_POSITIVE_INPUT_PA9  = 1U,
    CMP2_POSITIVE_INPUT_PB13 = 3U,
    CMP2_POSITIVE_INPUT_PC7  = 4U,
    CMP2_POSITIVE_INPUT_AGND = 5U,
    CMP2_POSITIVE_INPUT_PA5  = 8U,
    CMP2_POSITIVE_INPUT_PC0  = 10U,
    CMP2_POSITIVE_INPUT_PD5  = 11U,
    CMP2_POSITIVE_INPUT_PD14 = 14U,

} Cmp2_PositiveInput_t;

typedef enum
{
    CMP3_POSITIVE_INPUT_PA0  = 0U,
    CMP3_POSITIVE_INPUT_PA9  = 1U,
    CMP3_POSITIVE_INPUT_PB15 = 3U,
    CMP3_POSITIVE_INPUT_PC5  = 4U,
    CMP3_POSITIVE_INPUT_AGND = 5U,
    CMP3_POSITIVE_INPUT_PE8  = 8U,
    CMP3_POSITIVE_INPUT_PG4  = 9U,
    CMP3_POSITIVE_INPUT_PA6  = 10U,
    CMP3_POSITIVE_INPUT_PG2  = 11U,
    CMP3_POSITIVE_INPUT_PD14 = 14U,

} Cmp3_PositiveInput_t;

typedef enum
{
    CMP0_NEGATIVE_INPUT_PA1  = 0U,
    CMP0_NEGATIVE_INPUT_PB3  = 2U,
    CMP0_NEGATIVE_INPUT_PB10 = 3U,
    CMP0_NEGATIVE_INPUT_PC12 = 4U,
    CMP0_NEGATIVE_INPUT_AGND = 5U,
    CMP0_NEGATIVE_INPUT_PA3  = 8U,
    CMP0_NEGATIVE_INPUT_PE8  = 9U,
    CMP0_NEGATIVE_INPUT_PE9  = 10U,
    CMP0_NEGATIVE_INPUT_PG4  = 11U,
    CMP0_NEGATIVE_INPUT_PC0  = 12U,
    CMP0_NEGATIVE_INPUT_PC15 = 13U,
    CMP0_NEGATIVE_INPUT_PD15 = 14U,
    CMP0_NEGATIVE_INPUT_PE7  = 15U,

} Cmp0_NegativeInput_t;

typedef enum
{
    CMP1_NEGATIVE_INPUT_PA1  = 0U,
    CMP1_NEGATIVE_INPUT_PB3  = 2U,
    CMP1_NEGATIVE_INPUT_AGND = 5U,
    CMP1_NEGATIVE_INPUT_PD6  = 10U,
    CMP1_NEGATIVE_INPUT_PC15 = 11U,
    CMP1_NEGATIVE_INPUT_PA4  = 13U,
    CMP1_NEGATIVE_INPUT_PD15 = 14U,

} Cmp1_NegativeInput_t;

typedef enum
{
    CMP2_NEGATIVE_INPUT_PA1  = 0U,
    CMP2_NEGATIVE_INPUT_PB3  = 2U,
    CMP2_NEGATIVE_INPUT_PB14 = 3U,
    CMP2_NEGATIVE_INPUT_AGND = 5U,
    CMP2_NEGATIVE_INPUT_PA5  = 8U,
    CMP2_NEGATIVE_INPUT_PC0  = 10U,
    CMP2_NEGATIVE_INPUT_PD4  = 11U,
    CMP2_NEGATIVE_INPUT_PD15 = 14U,

} Cmp2_NegativeInput_t;

typedef enum
{
    CMP3_NEGATIVE_INPUT_PA1  = 0U,
    CMP3_NEGATIVE_INPUT_PB3  = 2U,
    CMP3_NEGATIVE_INPUT_PF0  = 3U,
    CMP3_NEGATIVE_INPUT_PC6  = 4U,
    CMP3_NEGATIVE_INPUT_AGND = 5U,
    CMP3_NEGATIVE_INPUT_PE9  = 8U,
    CMP3_NEGATIVE_INPUT_PG4  = 9U,
    CMP3_NEGATIVE_INPUT_PA6  = 10U,
    CMP3_NEGATIVE_INPUT_PG2  = 11U,
    CMP3_NEGATIVE_INPUT_PD15 = 14U,

} Cmp3_NegativeInput_t;

typedef enum
{
    CMP_INDEX_0,
    CMP_INDEX_1,
    CMP_INDEX_2,
    CMP_INDEX_3,
} Cmp_Index_t;

/******************************************************************************
 *                      Export Variables
 ******************************************************************************/

/******************************************************************************
 *                      Export Functions
 ******************************************************************************/

/**
 * @brief: 设置模拟比较器输出极性
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 极性转换
 *          false 正常输出
 * @retval 无
 */
KF_INLINE void Cmp_LL_SelectCmp0Polarity(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CTL0.bits.POL = State ? 1U : 0U;
}

/**
 * @brief: 设置比较器范围控制使能
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 使能范围控制
 *          false 禁用范围控制
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetCmp0WinCtrlEnabled(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CTL0.bits.WINEN = State ? 1U : 0U;
}

/**
 * @brief: 设置比较器滤波器使能
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 使能比较器滤波器
 *          false 禁用比较器滤波器
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetCmp0FilterEnabled(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CTL0.bits.FLTEN = State ? 1U : 0U;
}

/**
 * @brief: 设置比较器滤波器取样数量
 * @param Cmpx: CMP寄存器结构体指针
 * @param Count: 滤波脉宽数量
 *          其值为0-7,表示滤除脉宽0-7个FILT_CLK的输入噪声
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetCmp0FilterCount(Cmp_RegisterMap_t *const Cmpx, Cmp_FilterWidth_t Count)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));
    KF_CMP_ASSERT(CHECK_CMP_FILTERWIDTH(Count));

    Cmpx->CTL0.bits.FLTCNT = (uint32_t)Count;
}

/**
 * @brief: 设置window control时钟选择
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          false 选择系统时钟
 * @retval 无
 */
KF_INLINE void Cmp_LL_SelectCmp0WindowClkSrc(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CTL0.bits.WINCLKSEL = State ? 1U : 0U;
}

/**
 * @brief: 设置比较器滤波器滤波时钟分频
 * @param Cmpx: CMP寄存器结构体指针
 * @param Div: 分频系数
 *          其值为0-255,表示分频CLK/(1-256)
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetCmp0FilterClockDiv(Cmp_RegisterMap_t *const Cmpx, uint8_t Div)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CTL0.bits.FLTDIV = Div;
}

/**
 * @brief: 设置比较器滤波器滤波时钟源选择位
 * @param Cmpx: CMP寄存器结构体指针
 * @param Value: 比较器滤波器滤波时钟源选择 Cmp_ClockSource_t
 * @retval 无
 */
KF_INLINE void Cmp_LL_SelectCmp0FilterClkSrc(Cmp_RegisterMap_t *const Cmpx, Cmp_ClockSource_t Value)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));
    KF_CMP_ASSERT(CHECK_CMP_CLOCKSOURCE(Value));

    Cmpx->CTL0.bits.FLTCS = (uint32_t)Value;
}

/**
 * @brief: 设置比较器上升沿触发中断使能位
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 使能中断
 *          false 不使能中断
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetCmp0RiseEdgeIntrEnabled(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CTL0.bits.IFREN = State ? 1U : 0U;
}

/**
 * @brief: 设置比较器下降沿触发中断使能位
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 使能中断
 *          false 不使能中断
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetCmp0FallEdgeIntrEnabled(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CTL0.bits.IFFEN = State ? 1U : 0U;
}

/**
 * @brief: 设置比较器的负端输入选择位
 * @param Cmpx: CMP寄存器结构体指针
 * @param Value: 比较器的负端输入选择位
 * | 配置值  | CMP0 | CMP1 | CMP2 | CMP3 |
 * | ------ | ---- | ---- | ---- | ---- |
 * | b0000  | PA1  | PA1  | PA1  | PA1  |
 * | b0001  |      |      |      |      |
 * | b0010  | PB3  | PB3  | PB3  | PB3  |
 * | b0011  | PB10 |      | PB14 | PF0  |
 * | b0100  | PC12 |      |      | PC6  |
 * | b0101  | AGND | AGND | AGND | AGND |
 * | b0110  |      |      |      |      |
 * | b0111  |      |      |      |      |
 * | b1000  | PA3  |      | PA5  | PE9  |
 * | b1001  | PE8  |      |      | PG4  |
 * | b1010  | PE9  | PD6  | PC0  | PA6  |
 * | b1011  | PG4  | PC15 | PD4  | PG2  |
 * | b1100  | PC0  |      |      |      |
 * | b1101  | PC15 | PA4  |      |      |
 * | b1110  | PD15 | PD15 | PD15 | PD15 |
 * | b1111  | PE7  |      |      |      |
 * @retval 无
 */
KF_INLINE void Cmp_LL_SelectCmp0NegativeInput(Cmp_RegisterMap_t *const Cmpx, Cmp0_NegativeInput_t Value)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));
    KF_CMP_ASSERT(((Value >= 0x0U) && (Value <= 0xFU)));

    Cmpx->CTL0.bits.NMOD = (uint32_t)Value;
}

/**
 * @brief: 设置比较器的正端输入选择位
 * @param Cmpx: CMP寄存器结构体指针
 * @param Value: 比较器的正端输入选择位
 * | 配置值  | CMP0 | CMP1 | CMP2 | CMP3 |
 * | ------ | ---- | ---- | ---- | ---- |
 * | b0000  | PA0  | PA0  | PA0  | PA0  |
 * | b0001  | PA9  | PA9  | PA9  | PA9  |
 * | b0010  |      |      |      |      |
 * | b0011  |      |      | PB13 | PB15 |
 * | b0100  | PC11 |      | PC7  | PC5  |
 * | b0101  | AGND | AGND | AGND | AGND |
 * | b0110  |      |      |      |      |
 * | b0111  |      |      |      |      |
 * | b1000  | PA3  | PG0  | PA5  | PE8  |
 * | b1001  | PE8  |      |      | PG4  |
 * | b1010  | PE9  | PD7  | PC0  | PA6  |
 * | b1011  | PG4  | PC15 | PD5  | PG2  |
 * | b1100  | PC0  |      |      |      |
 * | b1101  | PC15 | PA4  |      |      |
 * | b1110  | PD14 | PD14 | PD14 | PD14 |
 * | b1111  | PE7  |      |      |      |
 * @retval 无
 */
KF_INLINE void Cmp_LL_SelectCmp0PositiveInput(Cmp_RegisterMap_t *const Cmpx, Cmp0_PositiveInput_t Value)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));
    KF_CMP_ASSERT(((Value >= 0x0U) && (Value <= 0xFU)));

    Cmpx->CTL0.bits.PMOD = (uint32_t)Value;
}

/**
 * @brief: 设置模拟比较器输出极性
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 极性转换
 *          false 正常输出
 * @retval 无
 */
KF_INLINE void Cmp_LL_SelectCmp1Polarity(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CTL1.bits.POL = State ? 1U : 0U;
}

/**
 * @brief: 设置比较器范围控制使能
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 使能范围控制
 *          false 禁用范围控制
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetCmp1WinCtrlEnabled(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CTL1.bits.WINEN = State ? 1U : 0U;
}

/**
 * @brief: 设置比较器滤波器使能
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 使能比较器滤波器
 *          false 禁用比较器滤波器
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetCmp1FilterEnabled(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CTL1.bits.FLTEN = State ? 1U : 0U;
}

/**
 * @brief: 设置比较器滤波器取样数量
 * @param Cmpx: CMP寄存器结构体指针
 * @param Count: 滤波脉宽数量
 *          其值为0-7,表示滤除脉宽0-7个FILT_CLK的输入噪声
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetCmp1FilterCount(Cmp_RegisterMap_t *const Cmpx, Cmp_FilterWidth_t Count)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));
    KF_CMP_ASSERT(CHECK_CMP_FILTERWIDTH(Count));

    Cmpx->CTL1.bits.FLTCNT = (uint32_t)Count;
}

/**
 * @brief: 设置window control时钟选择
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 选择FlexMUX输出信号
 *          false 选择系统时钟
 * @retval 无
 */
KF_INLINE void Cmp_LL_SelectCmp1WindowClkSrc(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CTL1.bits.WINCLKSEL = State ? 1U : 0U;
}

/**
 * @brief: 设置比较器滤波器滤波时钟分频
 * @param Cmpx: CMP寄存器结构体指针
 * @param Div: 分频系数
 *          其值为0-255,表示分频CLK/(1-256)
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetCmp1FilterClockDiv(Cmp_RegisterMap_t *const Cmpx, uint8_t Div)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CTL1.bits.FLTDIV = Div;
}

/**
 * @brief: 设置比较器滤波器滤波时钟源选择位
 * @param Cmpx: CMP寄存器结构体指针
 * @param Value: 比较器滤波器滤波时钟源选择 Cmp_ClockSource_t
 * @retval 无
 */
KF_INLINE void Cmp_LL_SelectCmp1FilterClkSrc(Cmp_RegisterMap_t *const Cmpx, Cmp_ClockSource_t Value)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));
    KF_CMP_ASSERT(CHECK_CMP_CLOCKSOURCE(Value));

    Cmpx->CTL1.bits.FLTCS = (uint32_t)Value;
}

/**
 * @brief: 设置比较器上升沿触发中断使能位
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 使能中断
 *          false 不使能中断
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetCmp1RiseEdgeIntrEnabled(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CTL1.bits.IFREN = State ? 1U : 0U;
}

/**
 * @brief: 设置比较器下降沿触发中断使能位
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 使能中断
 *          false 不使能中断
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetCmp1FallEdgeIntrEnabled(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CTL1.bits.IFFEN = State ? 1U : 0U;
}

/**
 * @brief: 设置比较器的负端输入选择位
 * @param Cmpx: CMP寄存器结构体指针
 * @param Value: 比较器的负端输入选择位
 * | 配置值  | CMP0 | CMP1 | CMP2 | CMP3 |
 * | ------ | ---- | ---- | ---- | ---- |
 * | b0000  | PA1  | PA1  | PA1  | PA1  |
 * | b0001  |      |      |      |      |
 * | b0010  | PB3  | PB3  | PB3  | PB3  |
 * | b0011  | PB10 |      | PB14 | PF0  |
 * | b0100  | PC12 |      |      | PC6  |
 * | b0101  | AGND | AGND | AGND | AGND |
 * | b0110  |      |      |      |      |
 * | b0111  |      |      |      |      |
 * | b1000  | PA3  |      | PA5  | PE9  |
 * | b1001  | PE8  |      |      | PG4  |
 * | b1010  | PE9  | PD6  | PC0  | PA6  |
 * | b1011  | PG4  | PC15 | PD4  | PG2  |
 * | b1100  | PC0  |      |      |      |
 * | b1101  | PC15 | PA4  |      |      |
 * | b1110  | PD15 | PD15 | PD15 | PD15 |
 * | b1111  | PE7  |      |      |      |
 * @retval 无
 */
KF_INLINE void Cmp_LL_SelectCmp1NegativeInput(Cmp_RegisterMap_t *const Cmpx, Cmp1_NegativeInput_t Value)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));
    KF_CMP_ASSERT(((Value >= 0x0U) && (Value <= 0xFU)));

    Cmpx->CTL1.bits.NMOD = (uint32_t)Value;
}

/**
 * @brief: 设置比较器的正端输入选择位
 * @param Cmpx: CMP寄存器结构体指针
 * @param Value: 比较器的正端输入选择位
 * | 配置值  | CMP0 | CMP1 | CMP2 | CMP3 |
 * | ------ | ---- | ---- | ---- | ---- |
 * | b0000  | PA0  | PA0  | PA0  | PA0  |
 * | b0001  | PA9  | PA9  | PA9  | PA9  |
 * | b0010  |      |      |      |      |
 * | b0011  |      |      | PB13 | PB15 |
 * | b0100  | PC11 |      | PC7  | PC5  |
 * | b0101  | AGND | AGND | AGND | AGND |
 * | b0110  |      |      |      |      |
 * | b0111  |      |      |      |      |
 * | b1000  | PA3  | PG0  | PA5  | PE8  |
 * | b1001  | PE8  |      |      | PG4  |
 * | b1010  | PE9  | PD7  | PC0  | PA6  |
 * | b1011  | PG4  | PC15 | PD5  | PG2  |
 * | b1100  | PC0  |      |      |      |
 * | b1101  | PC15 | PA4  |      |      |
 * | b1110  | PD14 | PD14 | PD14 | PD14 |
 * | b1111  | PE7  |      |      |      |
 * @retval 无
 */
KF_INLINE void Cmp_LL_SelectCmp1PositiveInput(Cmp_RegisterMap_t *const Cmpx, Cmp1_PositiveInput_t Value)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));
    KF_CMP_ASSERT(((Value >= 0x0U) && (Value <= 0xFU)));

    Cmpx->CTL1.bits.PMOD = (uint32_t)Value;
}

/**
 * @brief: 设置模拟比较器输出极性
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 极性转换
 *          false 正常输出
 * @retval 无
 */
KF_INLINE void Cmp_LL_SelectCmp2Polarity(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CTL2.bits.POL = State ? 1U : 0U;
}

/**
 * @brief: 设置比较器范围控制使能
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 使能范围控制
 *          false 禁用范围控制
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetCmp2WinCtrlEnabled(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CTL2.bits.WINEN = State ? 1U : 0U;
}

/**
 * @brief: 设置比较器滤波器使能
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 使能比较器滤波器
 *          false 禁用比较器滤波器
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetCmp2FilterEnabled(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CTL2.bits.FLTEN = State ? 1U : 0U;
}

/**
 * @brief: 设置比较器滤波器取样数量
 * @param Cmpx: CMP寄存器结构体指针
 * @param Count: 滤波脉宽数量
 *          其值为0-7,表示滤除脉宽0-7个FILT_CLK的输入噪声
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetCmp2FilterCount(Cmp_RegisterMap_t *const Cmpx, Cmp_FilterWidth_t Count)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));
    KF_CMP_ASSERT(CHECK_CMP_FILTERWIDTH(Count));

    Cmpx->CTL2.bits.FLTCNT = (uint32_t)Count;
}

/**
 * @brief: 设置window control时钟选择
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 选择FlexMUX输出信号
 *          false 选择系统时钟
 * @retval 无
 */
KF_INLINE void Cmp_LL_SelectCmp2WindowClkSrc(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CTL2.bits.WINCLKSEL = State ? 1U : 0U;
}

/**
 * @brief: 设置比较器滤波器滤波时钟分频
 * @param Cmpx: CMP寄存器结构体指针
 * @param Div: 分频系数
 *          其值为0-255,表示分频CLK/(1-256)
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetCmp2FilterClockDiv(Cmp_RegisterMap_t *const Cmpx, uint8_t Div)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CTL2.bits.FLTDIV = Div;
}

/**
 * @brief: 设置比较器滤波器滤波时钟源选择位
 * @param Cmpx: CMP寄存器结构体指针
 * @param Value: 比较器滤波器滤波时钟源选择 Cmp_ClockSource_t
 * @retval 无
 */
KF_INLINE void Cmp_LL_SelectCmp2FilterClkSrc(Cmp_RegisterMap_t *const Cmpx, Cmp_ClockSource_t Value)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));
    KF_CMP_ASSERT(CHECK_CMP_CLOCKSOURCE(Value));

    Cmpx->CTL2.bits.FLTCS = (uint32_t)Value;
}

/**
 * @brief: 设置比较器上升沿触发中断使能位
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 使能中断
 *          false 不使能中断
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetCmp2RiseEdgeIntrEnabled(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CTL2.bits.IFREN = State ? 1U : 0U;
}

/**
 * @brief: 设置比较器下降沿触发中断使能位
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 使能中断
 *          false 不使能中断
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetCmp2FallEdgeIntrEnabled(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CTL2.bits.IFFEN = State ? 1U : 0U;
}

/**
 * @brief: 设置比较器的负端输入选择位
 * @param Cmpx: CMP寄存器结构体指针
 * @param Value: 比较器的负端输入选择位
 * | 配置值  | CMP0 | CMP1 | CMP2 | CMP3 |
 * | ------ | ---- | ---- | ---- | ---- |
 * | b0000  | PA1  | PA1  | PA1  | PA1  |
 * | b0001  |      |      |      |      |
 * | b0010  | PB3  | PB3  | PB3  | PB3  |
 * | b0011  | PB10 |      | PB14 | PF0  |
 * | b0100  | PC12 |      |      | PC6  |
 * | b0101  | AGND | AGND | AGND | AGND |
 * | b0110  |      |      |      |      |
 * | b0111  |      |      |      |      |
 * | b1000  | PA3  |      | PA5  | PE9  |
 * | b1001  | PE8  |      |      | PG4  |
 * | b1010  | PE9  | PD6  | PC0  | PA6  |
 * | b1011  | PG4  | PC15 | PD4  | PG2  |
 * | b1100  | PC0  |      |      |      |
 * | b1101  | PC15 | PA4  |      |      |
 * | b1110  | PD15 | PD15 | PD15 | PD15 |
 * | b1111  | PE7  |      |      |      |
 * @retval 无
 */
KF_INLINE void Cmp_LL_SelectCmp2NegativeInput(Cmp_RegisterMap_t *const Cmpx, Cmp2_NegativeInput_t Value)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));
    KF_CMP_ASSERT(((Value >= 0x0U) && (Value <= 0xFU)));

    Cmpx->CTL2.bits.NMOD = (uint32_t)Value;
}

/**
 * @brief: 设置比较器的正端输入选择位
 * @param Cmpx: CMP寄存器结构体指针
 * @param Value: 比较器的正端输入选择位
 * | 配置值  | CMP0 | CMP1 | CMP2 | CMP3 |
 * | ------ | ---- | ---- | ---- | ---- |
 * | b0000  | PA0  | PA0  | PA0  | PA0  |
 * | b0001  | PA9  | PA9  | PA9  | PA9  |
 * | b0010  |      |      |      |      |
 * | b0011  |      |      | PB13 | PB15 |
 * | b0100  | PC11 |      | PC7  | PC5  |
 * | b0101  | AGND | AGND | AGND | AGND |
 * | b0110  |      |      |      |      |
 * | b0111  |      |      |      |      |
 * | b1000  | PA3  | PG0  | PA5  | PE8  |
 * | b1001  | PE8  |      |      | PG4  |
 * | b1010  | PE9  | PD7  | PC0  | PA6  |
 * | b1011  | PG4  | PC15 | PD5  | PG2  |
 * | b1100  | PC0  |      |      |      |
 * | b1101  | PC15 | PA4  |      |      |
 * | b1110  | PD14 | PD14 | PD14 | PD14 |
 * | b1111  | PE7  |      |      |      |
 * @retval 无
 */
KF_INLINE void Cmp_LL_SelectCmp2PositiveInput(Cmp_RegisterMap_t *const Cmpx, Cmp2_PositiveInput_t Value)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));
    KF_CMP_ASSERT(CHECK_CMP_INPUT(Value));

    Cmpx->CTL2.bits.PMOD = (uint32_t)Value;
}

/**
 * @brief: 设置模拟比较器输出极性
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 极性转换
 *          false 正常输出
 * @retval 无
 */
KF_INLINE void Cmp_LL_SelectCmp3Polarity(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CTL3.bits.POL = State ? 1U : 0U;
}

/**
 * @brief: 设置比较器范围控制使能
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 使能范围控制
 *          false 禁用范围控制
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetCmp3WinCtrlEnabled(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CTL3.bits.WINEN = State ? 1U : 0U;
}

/**
 * @brief: 设置比较器滤波器使能
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 使能比较器滤波器
 *          false 禁用比较器滤波器
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetCmp3FilterEnabled(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CTL3.bits.FLTEN = State ? 1U : 0U;
}

/**
 * @brief: 设置比较器滤波器取样数量
 * @param Cmpx: CMP寄存器结构体指针
 * @param Count: 滤波脉宽数量
 *          其值为0-7,表示滤除脉宽0-7个FILT_CLK的输入噪声
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetCmp3FilterCount(Cmp_RegisterMap_t *const Cmpx, Cmp_FilterWidth_t Count)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));
    KF_CMP_ASSERT(CHECK_CMP_FILTERWIDTH(Count));

    Cmpx->CTL3.bits.FLTCNT = (uint32_t)Count;
}

/**
 * @brief: 设置window control时钟选择
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 选择FlexMUX输出信号
 *          false 选择系统时钟
 * @retval 无
 */
KF_INLINE void Cmp_LL_SelectCmp3WindowClkSrc(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CTL3.bits.WINCLKSEL = State ? 1U : 0U;
}

/**
 * @brief: 设置比较器滤波器滤波时钟分频
 * @param Cmpx: CMP寄存器结构体指针
 * @param Div: 分频系数
 *          其值为0-255,表示分频CLK/(1-256)
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetCmp3FilterClockDiv(Cmp_RegisterMap_t *const Cmpx, uint8_t Div)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CTL3.bits.FLTDIV = Div;
}

/**
 * @brief: 设置比较器滤波器滤波时钟源选择位
 * @param Cmpx: CMP寄存器结构体指针
 * @param Value: 比较器滤波器滤波时钟源选择 Cmp_ClockSource_t
 * @retval 无
 */
KF_INLINE void Cmp_LL_SelectCmp3FilterClkSrc(Cmp_RegisterMap_t *const Cmpx, Cmp_ClockSource_t Value)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));
    KF_CMP_ASSERT(CHECK_CMP_CLOCKSOURCE(Value));

    Cmpx->CTL3.bits.FLTCS = (uint32_t)Value;
}

/**
 * @brief: 设置比较器上升沿触发中断使能位
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 使能中断
 *          false 不使能中断
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetCmp3RiseEdgeIntrEnabled(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CTL3.bits.IFREN = State ? 1U : 0U;
}

/**
 * @brief: 设置比较器下降沿触发中断使能位
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 使能中断
 *          false 不使能中断
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetCmp3FallEdgeIntrEnabled(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CTL3.bits.IFFEN = State ? 1U : 0U;
}

/**
 * @brief: 设置比较器的负端输入选择位
 * @param Cmpx: CMP寄存器结构体指针
 * @param Value: 比较器的负端输入选择位
 * | 配置值  | CMP0 | CMP1 | CMP2 | CMP3 |
 * | ------ | ---- | ---- | ---- | ---- |
 * | b0000  | PA1  | PA1  | PA1  | PA1  |
 * | b0001  |      |      |      |      |
 * | b0010  | PB3  | PB3  | PB3  | PB3  |
 * | b0011  | PB10 |      | PB14 | PF0  |
 * | b0100  | PC12 |      |      | PC6  |
 * | b0101  | AGND | AGND | AGND | AGND |
 * | b0110  |      |      |      |      |
 * | b0111  |      |      |      |      |
 * | b1000  | PA3  |      | PA5  | PE9  |
 * | b1001  | PE8  |      |      | PG4  |
 * | b1010  | PE9  | PD6  | PC0  | PA6  |
 * | b1011  | PG4  | PC15 | PD4  | PG2  |
 * | b1100  | PC0  |      |      |      |
 * | b1101  | PC15 | PA4  |      |      |
 * | b1110  | PD15 | PD15 | PD15 | PD15 |
 * | b1111  | PE7  |      |      |      |
 * @retval 无
 */
KF_INLINE void Cmp_LL_SelectCmp3NegativeInput(Cmp_RegisterMap_t *const Cmpx, Cmp3_NegativeInput_t Value)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));
    KF_CMP_ASSERT(((Value >= 0x0U) && (Value <= 0xFU)));

    Cmpx->CTL3.bits.NMOD = (uint32_t)Value;
}

/**
 * @brief: 设置比较器的正端输入选择位
 * @param Cmpx: CMP寄存器结构体指针
 * @param Value: 比较器的正端输入选择位
 * | 配置值  | CMP0 | CMP1 | CMP2 | CMP3 |
 * | ------ | ---- | ---- | ---- | ---- |
 * | b0000  | PA0  | PA0  | PA0  | PA0  |
 * | b0001  | PA9  | PA9  | PA9  | PA9  |
 * | b0010  |      |      |      |      |
 * | b0011  |      |      | PB13 | PB15 |
 * | b0100  | PC11 |      | PC7  | PC5  |
 * | b0101  | AGND | AGND | AGND | AGND |
 * | b0110  |      |      |      |      |
 * | b0111  |      |      |      |      |
 * | b1000  | PA3  | PG0  | PA5  | PE8  |
 * | b1001  | PE8  |      |      | PG4  |
 * | b1010  | PE9  | PD7  | PC0  | PA6  |
 * | b1011  | PG4  | PC15 | PD5  | PG2  |
 * | b1100  | PC0  |      |      |      |
 * | b1101  | PC15 | PA4  |      |      |
 * | b1110  | PD14 | PD14 | PD14 | PD14 |
 * | b1111  | PE7  |      |      |      |
 * @retval 无
 */
KF_INLINE void Cmp_LL_SelectCmp3PositiveInput(Cmp_RegisterMap_t *const Cmpx, Cmp3_PositiveInput_t Value)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));
    KF_CMP_ASSERT(((Value >= 0x0U) && (Value <= 0xFU)));

    Cmpx->CTL3.bits.PMOD = (uint32_t)Value;
}

/**
 * @brief: 使能比较器3
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 使能
 *          false 禁用
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetComp3Enabled(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CTL3.bits.EN = State ? 1U : 0U;
}

/**
 * @brief: 使能比较器0
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 使能
 *          false 禁用
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetComp0Enabled(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CTL4.bits.C0EN = State ? 1U : 0U;
}

/**
 * @brief: 使能比较器1
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 使能
 *          false 禁用
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetComp1Enabled(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CTL4.bits.C1EN = State ? 1U : 0U;
}

/**
 * @brief: 使能比较器2
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 使能
 *          false 禁用
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetComp2Enabled(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CTL4.bits.C2EN = State ? 1U : 0U;
}

/**
 * @brief: 设置比较器使能位
 * @param Cmpx: CMP寄存器结构体指针
 * @param CmpNum: 比较器编号,取值范围0-3
 * @param State
 *          true 使能
 *          false 禁用
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetCmpEnabled(Cmp_RegisterMap_t *const Cmpx, Cmp_Index_t CmpNum, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));
    KF_CMP_ASSERT(((CmpNum >= 0x0U) && (CmpNum <= 0x3U)));

    switch (CmpNum)
    {
    case CMP_INDEX_0:
        Cmp_LL_SetComp0Enabled(Cmpx, State);
        break;
    case CMP_INDEX_1:
        Cmp_LL_SetComp1Enabled(Cmpx, State);
        break;
    case CMP_INDEX_2:
        Cmp_LL_SetComp2Enabled(Cmpx, State);
        break;
    case CMP_INDEX_3:
        Cmp_LL_SetComp3Enabled(Cmpx, State);
        break;
    default:
        (void)0U;
        break;
    }
}

/**
 * @brief: 设置滤波器输入选择位状态
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true I/O口作为滤波器的输入
 *          false 比较器输出作为滤波器的输入
 * @retval 无
 */
KF_INLINE void Cmp_LL_SelectFilterInput(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CTL4.bits.FLTINSEL = State ? 1U : 0U;
}

/**
 * @brief: 设置反向电动势模式使能位状态
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 反向电动势模式
 *          false 通用模式
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetBemfModeEnabled(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CTL4.bits.BEMFEN = State ? 1U : 0U;
}

/**
 * @brief: HALL模式选择
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 双端选择
 *          false 单端选择
 * @retval 无
 */
KF_INLINE void Cmp_LL_SelectHallMode(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CTL4.bits.HALLSEL = State ? 1U : 0U;
}

/**
 * @brief: 比较器迟滞电压选择
 * @param Cmpx: CMP寄存器结构体指针
 * @param DelayVol: 迟滞电压选择,取值范围0-3
 *              b00 = 无迟滞
 *              b01 = 20mV 迟滞
 *              b10 = 35mV 迟滞
 *              b11 = 45mV 迟滞
 * @retval 无
 */
KF_INLINE void Cmp_LL_SelectCmpDelayVoltage(Cmp_RegisterMap_t *const Cmpx, uint8_t DelayVol)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));
    KF_CMP_ASSERT(((DelayVol >= 0x0U) && (DelayVol <= 0x3U)));

    Cmpx->CTL4.bits.DELAYVOL = DelayVol;
}

/**
 * @brief: 比较器数字输出选择
 * @param Cmpx: CMP寄存器结构体指针
 * @param DOutSel: 数字输出选择,取值范围Cmp_DigitalOutSelect_t
 * @retval 无
 */
KF_INLINE void Cmp_LL_SelectCmpDigitalOutput(Cmp_RegisterMap_t *const Cmpx, Cmp_DigitalOutSelect_t DOutSel)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));
    KF_CMP_ASSERT(CHECK_CMP_DIGITALOUTSELECT(DOutSel));

    Cmpx->CTL4.bits.CMPOUTDSEL = (uint32_t)DOutSel;
}

/**
 * @brief: 设置IO通道使能位状态
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true IO通道使能
 *          false IO通道禁用
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetIoEnabled(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CTL4.bits.IOEN = State ? 1U : 0U;
}

/**
 * @brief 设置CMP中断使能状态
 *
 * @param Cmpx CMP寄存器结构体指针
 * @param IntIndex 设置中断序号, 可见 Cmp_IntrSetIndex_t
 * @param EnableSta 使能状态
 * @retval void
 */
KF_INLINE void Cmp_LL_SetIntrEnabled(Cmp_RegisterMap_t *const Cmpx, Cmp_IntrSetIndex_t IntIndex, bool EnableSta)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));
    KF_CMP_ASSERT(CHECK_CMP_INTRSETINDEX(IntIndex));

    /* PRQA S 3473 1 #KQR003473 */
    REG_BITS_WRITE(Cmpx->CTL4.reg, (1UL << (uint32_t)IntIndex), ((EnableSta ? 1UL : 0UL) << (uint32_t)IntIndex));
}

/**
 * @brief 清除CMP中断标志位
 *
 * @param Cmpx CMP寄存器结构体指针
 * @param IntIndex 清除中断序号, 可见 Cmp_IntrClearIndex_t
 * @retval void
 */
KF_INLINE void Cmp_LL_ClearIntrFlag(Cmp_RegisterMap_t *const Cmpx, Cmp_IntrClearIndex_t IntIndex)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));
    KF_CMP_ASSERT(CHECK_CMP_INTRCLEARINDEX(IntIndex));

    /* PRQA S 3473 ++ #KQR003473 */
    REG_BIT_SET(Cmpx->CTL4.reg, 1UL << (uint32_t)IntIndex);
    NOP();
    NOP();
    NOP();
    NOP();
    REG_BIT_CLR(Cmpx->CTL4.reg, 1UL << (uint32_t)IntIndex);
    /* PRQA S 3473 -- #KQR003473 */
}

/**
 * @brief 获取中断标志状态
 *
 * @param Cmpx CMP寄存器结构体指针
 * @param IntIndex 获取中断序号, 可见 Cmp_IntrGetIndex_t
 * @retval bool 中断标志状态
 */
KF_INLINE bool Cmp_LL_GetIntrFlag(const Cmp_RegisterMap_t *const Cmpx, Cmp_IntrGetIndex_t IntIndex)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));
    KF_CMP_ASSERT(CHECK_CMP_INTRGETINDEX(IntIndex));

    return (REG_BITS_READ(Cmpx->CTL4.reg, (1UL << (uint32_t)IntIndex), (uint32_t)IntIndex) != 0U);
}

/**
 * @brief: 设置CMP的模拟输出到IO口使能
 * @param Cmpx: CMP寄存器结构体指针
 * @param Cmpoutasel: CMP的模拟输出到IO口使能
 *          取值范围: 0~3
 *              0: 关闭模拟输出
 *              1: CMP0输出IO口PC2
 *              2: CMP1输出IO口PC2
 *              3: CMP2输出IO口PC2
 * @retval 无
 */
KF_INLINE void Cmp_LL_SelectCmpAnalogOutput(Cmp_RegisterMap_t *const Cmpx, Cmp_Output2Io_t Cmpoutasel)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));
    KF_CMP_ASSERT(CHECK_CMP_OUTPUT2IO(Cmpoutasel));

    Cmpx->CTL4.bits.CMPOUTASEL = (uint32_t)Cmpoutasel;
}

/**
 * @brief: 设置CMP0/1/2下拉5K使能
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 使能下拉5K
 *          false 不使能下拉5K
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetPwmCompEnabled(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CTL4.bits.PWMCMP = State ? 1U : 0U;
}

/**
 * @brief: 比较器中断标志位触发模式选择位
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 通过检测比较器输出变化沿触发中断标志
 *          false 通过比较器输出与锁存状态比较触发中断标志
 * @retval 无
 */
KF_INLINE void Cmp_LL_SelectIntrFlagMode(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CTL4.bits.CIFMS = State ? 1U : 0U;
}

/**
 * @brief: CMP3的模拟输出到IO口使能
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 使能
 *          false 不使能
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetCmp3AnalogOutputEnabled(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CTL4.bits.CMP3ANALOGOUTEN = State ? 1U : 0U;
}

/**
 * @brief: 获取比较器0输出状态位
 * @param Cmpx 指向CMP寄存器结构的指针
 * @retval bool:
 *         true
 *         BIT_RESET
 */
KF_INLINE bool Cmp_LL_GetCmp0Output(const Cmp_RegisterMap_t *const Cmpx)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    return Cmpx->CTL4.bits.C0OUT != 0U;
}

/**
 * @brief: 获取比较器1输出状态位
 * @param Cmpx 指向CMP寄存器结构的指针
 * @retval bool:
 *         true
 *         BIT_RESET
 */
KF_INLINE bool Cmp_LL_GetCmp1Output(const Cmp_RegisterMap_t *const Cmpx)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    return Cmpx->CTL4.bits.C1OUT != 0U;
}

/**
 * @brief: 获取比较器2输出状态位
 * @param Cmpx 指向CMP寄存器结构的指针
 * @retval bool:
 *         true
 *         BIT_RESET
 */
KF_INLINE bool Cmp_LL_GetCmp2Output(const Cmp_RegisterMap_t *const Cmpx)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    return Cmpx->CTL4.bits.C2OUT != 0U;
}

/**
 * @brief: 获取比较器3输出状态位
 * @param Cmpx 指向CMP寄存器结构的指针
 * @retval bool:
 *         true
 *         BIT_RESET
 */
KF_INLINE bool Cmp_LL_GetCmp3Output(const Cmp_RegisterMap_t *const Cmpx)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    return Cmpx->CTL4.bits.C3OUT != 0U;
}

/**
 * @brief: 设置CMP0/1/2/3低功耗使能
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 低功耗使能
 *          false 低功耗关闭
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetCmpLowPowerEnabled(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CTL5.bits.CMPLPEN = State ? 1U : 0U;
}

/**
 * @brief: 设置CMP0正端输入选择
 * @param Cmpx: CMP寄存器结构体指针
 * @param Select
 *          b00 = 选择 C0_1(PF6)作为正端输入
 *          b01 = 选择 C0_2(PF10)作为正端输入
 *          b10 = 选择 C0_3(PF12)作为正端输入
 *          b11 = 由 CMP_CTL0 的 PMOD<3:0>配置正端输入
 * @retval 无
 */
KF_INLINE void Cmp_LL_PreSelectCmp0PositiveInput(Cmp_RegisterMap_t *const Cmpx, Cmp_PositiveInput_t Select)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));
    KF_CMP_ASSERT(CHECK_CMP_POSITIVEINPUT(Select));

    Cmpx->CTL5.bits.C0PSEL = (uint32_t)Select;
}

/**
 * @brief: 设置MOTOR参考选择位
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 选择 GND 作为 MOTOR 参考
 *          false 选择 1/3 的 AVDD 作为 MOTOR 参考
 * @retval 无
 */
KF_INLINE void Cmp_LL_SelectMotorRef(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CTL5.bits.MOTORSEL = State ? 1U : 0U;
}

/**
 * @brief: 设置内电阻单比较器模式使能位
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 启用单比较器模式
 *          false 禁用单比较器模式
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetInscmEnabled(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CTL5.bits.INSCM = State ? 1U : 0U;
}

/**
 * @brief 获取CMP通道触发DMA中断标志
 *
 * @param Cmpx CMP寄存器结构体指针
 * @retval bool 触发DMA中断标志
 *          true 通道未触发DMA
 *          false 通道触发DMA
 */
KF_INLINE bool Cmp_LL_GetDmaFlag(const Cmp_RegisterMap_t *const Cmpx, Cmp_DmaGetIndex_t DmaIndex)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));
    KF_CMP_ASSERT(CHECK_CMP_DMAGETINDEX(DmaIndex));

    return (REG_BITS_READ(Cmpx->CTL5.reg, (1UL << (uint32_t)DmaIndex), (uint32_t)DmaIndex) != 0U);
}

/**
 * @brief: 设置CMP0 NMOS管失调校准方向选择位
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 管选择正向校准
 *          false 管选择负向校准
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetCmp0TrimNPol(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->TRIM0.bits.C0TRIMNPOL = State ? 1U : 0U;
}

/**
 * @brief: 设置CMP0 NMOS管失调校准位
 * @param Cmpx: CMP寄存器结构体指针
 * @param Val 失调校准值,范围0~63
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetCmp0TrimN(Cmp_RegisterMap_t *const Cmpx, uint32_t Val)
{
    Cmpx->TRIM0.bits.C0TRIMN = Val & 0x3fU;
}

/**
 * @brief: 设置CMP0 PMOS管失调校准方向选择位
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 管选择正向校准
 *          false 管选择负向校准
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetCmp0TrimPPol(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->TRIM0.bits.C0TRIMPPOL = State ? 1U : 0U;
}

/**
 * @brief: 设置CMP0 PMOS管失调校准位
 * @param Cmpx: CMP寄存器结构体指针
 * @param Val 失调校准值,范围0~63
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetCmp0TrimP(Cmp_RegisterMap_t *const Cmpx, uint32_t Val)
{
    Cmpx->TRIM0.bits.C0TRIMP = Val & 0x3fU;
}

/**
 * @brief: 设置CMP校准NMOS管总使能位
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 使能
 *          false 禁止
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetCmpTrimHiEnabled(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->TRIM0.bits.CMPTRIMHIGHEN = State ? 1U : 0U;
}

/**
 * @brief: 设置CMP校准PMOS管总使能位
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 使能
 *          false 禁止
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetCmpTrimLoEnabled(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->TRIM0.bits.CMPTRIMLOWEN = State ? 1U : 0U;
}

/**
 * @brief: 设置CMP1 NMOS管失调校准方向选择位
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 管选择正向校准
 *          false 管选择负向校准
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetCmp1TrimNPol(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->TRIM1.bits.CxTRIMNPOL = State ? 1U : 0U;
}

/**
 * @brief: 设置CMP1 NMOS管失调校准位
 * @param Cmpx: CMP寄存器结构体指针
 * @param TrimVal: 失调校准值
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetCmp1TrimN(Cmp_RegisterMap_t *const Cmpx, uint32_t TrimVal)
{
    Cmpx->TRIM1.bits.CxTRIMN = TrimVal;
}

/**
 * @brief: 设置CMP1 PMOS管失调校准方向选择位
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 管选择正向校准
 *          false 管选择负向校准
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetCmp1TrimPPol(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->TRIM1.bits.CxTRIMPPOL = State ? 1U : 0U;
}

/**
 * @brief: 设置CMP1 PMOS管失调校准位
 * @param Cmpx: CMP寄存器结构体指针
 * @param TrimVal: 失调校准值
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetCmp1TrimP(Cmp_RegisterMap_t *const Cmpx, uint32_t TrimVal)
{
    Cmpx->TRIM1.bits.CxTRIMP = TrimVal;
}

/**
 * @brief: 设置CMP2 NMOS管失调校准方向选择位
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 管选择正向校准
 *          false 管选择负向校准
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetCmp2TrimNPol(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->TRIM2.bits.CxTRIMNPOL = State ? 1U : 0U;
}

/**
 * @brief: 设置CMP2 NMOS管失调校准位
 * @param Cmpx: CMP寄存器结构体指针
 * @param TrimVal: 失调校准值
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetCmp2TrimN(Cmp_RegisterMap_t *const Cmpx, uint32_t TrimVal)
{
    Cmpx->TRIM2.bits.CxTRIMN = TrimVal;
}

/**
 * @brief: 设置CMP2 PMOS管失调校准方向选择位
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 管选择正向校准
 *          false 管选择负向校准
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetCmp2TrimPPol(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->TRIM2.bits.CxTRIMPPOL = State ? 1U : 0U;
}

/**
 * @brief: 设置CMP2 PMOS管失调校准位
 * @param Cmpx: CMP寄存器结构体指针
 * @param TrimVal: 失调校准值
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetCmp2TrimP(Cmp_RegisterMap_t *const Cmpx, uint32_t TrimVal)
{
    Cmpx->TRIM2.bits.CxTRIMP = TrimVal;
}

/**
 * @brief: 设置CMP3 NMOS管失调校准方向选择位
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 管选择正向校准
 *          false 管选择负向校准
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetCmp3TrimNPol(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->TRIM3.bits.C3TRIMNPOL = State ? 1U : 0U;
}

/**
 * @brief: 设置CMP3 NMOS管失调校准位
 * @param Cmpx: CMP寄存器结构体指针
 * @param TrimVal: 失调校准值
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetCmp3TrimN(Cmp_RegisterMap_t *const Cmpx, uint32_t TrimVal)
{
    Cmpx->TRIM3.bits.C3TRIMN = TrimVal;
}

/**
 * @brief: 设置CMP3 PMOS管失调校准方向选择位
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 管选择正向校准
 *          false 管选择负向校准
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetCmp3TrimPPol(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->TRIM3.bits.C3TRIMPPOL = State ? 1U : 0U;
}

/**
 * @brief: 设置CMP3 PMOS管失调校准位
 * @param Cmpx: CMP寄存器结构体指针
 * @param TrimVal: 失调校准值
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetCmp3TrimP(Cmp_RegisterMap_t *const Cmpx, uint32_t TrimVal)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));
    KF_CMP_ASSERT(((TrimVal >= 0x0U) && (TrimVal <= 0x3FU)));

    Cmpx->TRIM3.bits.C3TRIMP = TrimVal;
}

/**
 * @brief: 设置CMP3内部1V参考电压使能位
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 内部1V参考电压使能
 *          false 内部1V参考电压禁用
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetCmp3Vref1vEnabled(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->TRIM3.bits.ENCMP3VREF1V = State ? 1U : 0U;
}

/**
 * @brief: 设置CMP通道扫描长度选择
 * @param Cmpx: CMP寄存器结构体指针
 * @param Len: 通道扫描长度选择,0x0 ~ 0xF,对应扫描1-16个转换
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetChannelScanLength(Cmp_RegisterMap_t *const Cmpx, uint32_t Len)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));
    KF_CMP_ASSERT(((Len >= 0x0U) && (Len <= 0xFU)));

    Cmpx->CTL6.bits.LEN = Len & 0xfU;
}

/**
 * @brief: 设置CMP被扫描通道扫描使能
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 通道扫描使能
 *          false 通道扫描禁止
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetChannelScanEnabled(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CTL6.bits.SCAN = State ? 1U : 0U;
}

/**
 * @brief: 设置CMP比较器初始化延迟系数
 * @param Cmpx: CMP寄存器结构体指针
 * @param DlyMod: 初始化延迟系数,取值范围为0-63
 *              模块初始化延迟时间/轮询模式的时钟频率
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetCmpInitDelayMode(Cmp_RegisterMap_t *const Cmpx, uint32_t DlyMod)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));
    KF_CMP_ASSERT(CHECK_CMP_INIT_DELAY(DlyMod));

    Cmpx->CTL6.bits.INITIALDLYMOD = DlyMod & 0x3fU;
}

/**
 * @brief: 设置CMP比较结果采样时刻
 * @param Cmpx: CMP寄存器结构体指针
 * @param SampTime: 采样时刻设置,取值范围为0-3
 *          b00 = 被扫描通道结束后,比较结果立即被采样时
 *          b01 = 1 个时钟后比较结果被采样
 *          b10 = 2 时钟后比较结果被采样
 *          b11 = 3 个时钟后比较结果被采样
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetCmpSampleTime(Cmp_RegisterMap_t *const Cmpx, Cmp_SampleTime_t SampTime)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));
    KF_CMP_ASSERT(CHECK_CMP_SAMPLETIME(SampTime));

    Cmpx->CTL6.bits.NASM = (uint32_t)SampTime & 0x3U;
}

/**
 * @brief: 设置CMP比较器轮询模式下固定(参考)通道选择
 * @param Cmpx: CMP寄存器结构体指针
 * @param Sel: 参考通道选择,取值范围为0-15, 可见 Cmp_NscanChannel_t
 * @retval 无
 */
KF_INLINE void Cmp_LL_SelectNegativeFixedRefInput(Cmp_RegisterMap_t *const Cmpx, Cmp_NscanChannel_t Sel)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));
    KF_CMP_ASSERT(CHECK_CMP_NSCANCHANNEL(Sel));

    Cmpx->CTL6.bits.FXNCHSEL = (uint32_t)Sel & 0xfU;
}

/**
 * @brief: 设置CMP比较器轮询模式下固定(参考)通道选择
 * @param Cmpx: CMP寄存器结构体指针
 * @param channel: 参考通道选择,取值范围0~15, 可见 Cmp_PscanChannel_t
 * @retval 无
 */
KF_INLINE void Cmp_LL_SelectPositiveFixedRefInput(Cmp_RegisterMap_t *const Cmpx, Cmp_PscanChannel_t Channel)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));
    KF_CMP_ASSERT(CHECK_CMP_PSCANCHANNEL(Channel));

    Cmpx->CTL6.bits.FXPCHSEL = (uint32_t)Channel & 0xFU;
}

/**
 * @brief: 设置比较器轮询模式固定端口选择
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 正端输入端口被固定
 *          false 负端输入端口被固定
 * @retval 无
 */
KF_INLINE void Cmp_LL_SelectCmpFixedPort(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CTL6.bits.FXPORTSEL = State ? 1U : 0U;
}

/**
 * @brief: 设置轮询中断使能
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 使能
 *          false 关闭
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetPollingIntrEnabled(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CTL6.bits.RRIE = State ? 1U : 0U;
}

/**
 * @brief: 设置轮询模式使能位
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 使能
 *          false 关闭
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetPollingEnabled(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CTL6.bits.RREN = State ? 1U : 0U;
}

/**
 * @brief: 设置CMP0的被扫描的第0通道选择位
 * @param Cmpx: CMP寄存器结构体指针
 * @param Channel: 被扫描的通道选择
 *          取值范围: Cmp_PscanChannel_t
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetPscan0(Cmp_RegisterMap_t *const Cmpx, Cmp_PscanChannel_t Channel)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));
    KF_CMP_ASSERT(CHECK_CMP_PSCANCHANNEL(Channel));

    Cmpx->PSCANSQ0.bits.PSCAN0 = (uint32_t)Channel;
}

/**
 * @brief: 设置CMP0的被扫描的第1通道选择位
 * @param Cmpx: CMP寄存器结构体指针
 * @param Channel: 被扫描的通道选择
 *          取值范围: Cmp_PscanChannel_t
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetPscan1(Cmp_RegisterMap_t *const Cmpx, Cmp_PscanChannel_t Channel)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));
    KF_CMP_ASSERT(CHECK_CMP_PSCANCHANNEL(Channel));

    Cmpx->PSCANSQ0.bits.PSCAN1 = (uint32_t)Channel;
}

/**
 * @brief: 设置CMP0的被扫描的第2通道选择位
 * @param Cmpx: CMP寄存器结构体指针
 * @param Channel: 被扫描的通道选择
 *          取值范围: Cmp_PscanChannel_t
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetPscan2(Cmp_RegisterMap_t *const Cmpx, Cmp_PscanChannel_t Channel)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));
    KF_CMP_ASSERT(CHECK_CMP_PSCANCHANNEL(Channel));

    Cmpx->PSCANSQ0.bits.PSCAN2 = (uint32_t)Channel;
}

/**
 * @brief: 设置CMP0的被扫描的第3通道选择位
 * @param Cmpx: CMP寄存器结构体指针
 * @param Channel: 被扫描的通道选择
 *          取值范围: Cmp_PscanChannel_t
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetPscan3(Cmp_RegisterMap_t *const Cmpx, Cmp_PscanChannel_t Channel)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));
    KF_CMP_ASSERT(CHECK_CMP_PSCANCHANNEL(Channel));

    Cmpx->PSCANSQ0.bits.PSCAN3 = (uint32_t)Channel;
}

/**
 * @brief: 设置CMP0的被扫描的第4通道选择位
 * @param Cmpx: CMP寄存器结构体指针
 * @param Channel: 被扫描的通道选择
 *          取值范围: Cmp_PscanChannel_t
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetPscan4(Cmp_RegisterMap_t *const Cmpx, Cmp_PscanChannel_t Channel)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));
    KF_CMP_ASSERT(CHECK_CMP_PSCANCHANNEL(Channel));

    Cmpx->PSCANSQ0.bits.PSCAN4 = (uint32_t)Channel;
}

/**
 * @brief: 设置CMP0的被扫描的第5通道选择位
 * @param Cmpx: CMP寄存器结构体指针
 * @param Channel: 被扫描的通道选择
 *          取值范围: Cmp_PscanChannel_t
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetPscan5(Cmp_RegisterMap_t *const Cmpx, Cmp_PscanChannel_t Channel)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));
    KF_CMP_ASSERT(CHECK_CMP_PSCANCHANNEL(Channel));

    Cmpx->PSCANSQ0.bits.PSCAN5 = (uint32_t)Channel;
}

/**
 * @brief: 设置CMP0的被扫描的第6通道选择位
 * @param Cmpx: CMP寄存器结构体指针
 * @param Channel: 被扫描的通道选择
 *          取值范围: Cmp_PscanChannel_t
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetPscan6(Cmp_RegisterMap_t *const Cmpx, Cmp_PscanChannel_t Channel)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));
    KF_CMP_ASSERT(CHECK_CMP_PSCANCHANNEL(Channel));

    Cmpx->PSCANSQ0.bits.PSCAN6 = (uint32_t)Channel;
}

/**
 * @brief: 设置CMP0的被扫描的第7通道选择位
 * @param Cmpx: CMP寄存器结构体指针
 * @param Channel: 被扫描的通道选择
 *          取值范围: Cmp_PscanChannel_t
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetPscan7(Cmp_RegisterMap_t *const Cmpx, Cmp_PscanChannel_t Channel)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));
    KF_CMP_ASSERT(CHECK_CMP_PSCANCHANNEL(Channel));

    Cmpx->PSCANSQ0.bits.PSCAN7 = (uint32_t)Channel;
}

/**
 * @brief: 设置CMP0的被扫描的第8通道选择位
 * @param Cmpx: CMP寄存器结构体指针
 * @param Channel: 被扫描的通道选择
 *          取值范围: Cmp_PscanChannel_t
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetPscan8(Cmp_RegisterMap_t *const Cmpx, Cmp_PscanChannel_t Channel)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));
    KF_CMP_ASSERT(CHECK_CMP_PSCANCHANNEL(Channel));

    Cmpx->PSCANSQ1.bits.PSCAN8 = (uint32_t)Channel;
}

/**
 * @brief: 设置CMP0的被扫描的第9通道选择位
 * @param Cmpx: CMP寄存器结构体指针
 * @param Channel: 被扫描的通道选择
 *          取值范围: Cmp_PscanChannel_t
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetPscan9(Cmp_RegisterMap_t *const Cmpx, Cmp_PscanChannel_t Channel)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));
    KF_CMP_ASSERT(CHECK_CMP_PSCANCHANNEL(Channel));

    Cmpx->PSCANSQ1.bits.PSCAN9 = (uint32_t)Channel;
}

/**
 * @brief: 设置CMP0的被扫描的第10通道选择位
 * @param Cmpx: CMP寄存器结构体指针
 * @param Channel: 被扫描的通道选择
 *          取值范围: Cmp_PscanChannel_t
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetPscan10(Cmp_RegisterMap_t *const Cmpx, Cmp_PscanChannel_t Channel)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));
    KF_CMP_ASSERT(CHECK_CMP_PSCANCHANNEL(Channel));

    Cmpx->PSCANSQ1.bits.PSCAN10 = (uint32_t)Channel;
}

/**
 * @brief: 设置CMP0的被扫描的第11通道选择位
 * @param Cmpx: CMP寄存器结构体指针
 * @param Channel: 被扫描的通道选择
 *          取值范围: Cmp_PscanChannel_t
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetPscan11(Cmp_RegisterMap_t *const Cmpx, Cmp_PscanChannel_t Channel)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));
    KF_CMP_ASSERT(CHECK_CMP_PSCANCHANNEL(Channel));

    Cmpx->PSCANSQ1.bits.PSCAN11 = (uint32_t)Channel;
}

/**
 * @brief: 设置CMP0的被扫描的第12通道选择位
 * @param Cmpx: CMP寄存器结构体指针
 * @param Channel: 被扫描的通道选择
 *          取值范围: Cmp_PscanChannel_t
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetPscan12(Cmp_RegisterMap_t *const Cmpx, Cmp_PscanChannel_t Channel)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));
    KF_CMP_ASSERT(CHECK_CMP_PSCANCHANNEL(Channel));

    Cmpx->PSCANSQ1.bits.PSCAN12 = (uint32_t)Channel;
}

/**
 * @brief: 设置CMP0的被扫描的第13通道选择位
 * @param Cmpx: CMP寄存器结构体指针
 * @param Channel: 被扫描的通道选择
 *          取值范围: Cmp_PscanChannel_t
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetPscan13(Cmp_RegisterMap_t *const Cmpx, Cmp_PscanChannel_t Channel)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));
    KF_CMP_ASSERT(CHECK_CMP_PSCANCHANNEL(Channel));

    Cmpx->PSCANSQ1.bits.PSCAN13 = (uint32_t)Channel;
}

/**
 * @brief: 设置CMP0的被扫描的第14通道选择位
 * @param Cmpx: CMP寄存器结构体指针
 * @param Channel: 被扫描的通道选择
 *          取值范围: Cmp_PscanChannel_t
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetPscan14(Cmp_RegisterMap_t *const Cmpx, Cmp_PscanChannel_t Channel)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));
    KF_CMP_ASSERT(CHECK_CMP_PSCANCHANNEL(Channel));

    Cmpx->PSCANSQ1.bits.PSCAN14 = (uint32_t)Channel;
}

/**
 * @brief: 设置CMP0的被扫描的第15通道选择位
 * @param Cmpx: CMP寄存器结构体指针
 * @param Channel: 被扫描的通道选择
 *          取值范围: Cmp_PscanChannel_t
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetPscan15(Cmp_RegisterMap_t *const Cmpx, Cmp_PscanChannel_t Channel)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));
    KF_CMP_ASSERT(CHECK_CMP_PSCANCHANNEL(Channel));

    Cmpx->PSCANSQ1.bits.PSCAN15 = (uint32_t)Channel;
}

/**
 * @brief: 设置CMP0的被扫描的第0通道选择位
 * @param Cmpx: CMP寄存器结构体指针
 * @param Channel: 被扫描的通道选择
 *          取值范围: Cmp_NscanChannel_t
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetNscan0(Cmp_RegisterMap_t *const Cmpx, Cmp_NscanChannel_t Channel)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));
    KF_CMP_ASSERT(CHECK_CMP_NSCANCHANNEL(Channel));

    Cmpx->NSCANSQ0.bits.NSCAN0 = (uint32_t)Channel;
}

/**
 * @brief: 设置CMP0的被扫描的第1通道选择位
 * @param Cmpx: CMP寄存器结构体指针
 * @param Channel: 被扫描的通道选择
 *          取值范围: Cmp_NscanChannel_t
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetNscan1(Cmp_RegisterMap_t *const Cmpx, Cmp_NscanChannel_t Channel)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));
    KF_CMP_ASSERT(CHECK_CMP_NSCANCHANNEL(Channel));

    Cmpx->NSCANSQ0.bits.NSCAN1 = (uint32_t)Channel;
}

/**
 * @brief: 设置CMP0的被扫描的第2通道选择位
 * @param Cmpx: CMP寄存器结构体指针
 * @param Channel: 被扫描的通道选择
 *          取值范围: Cmp_NscanChannel_t
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetNscan2(Cmp_RegisterMap_t *const Cmpx, Cmp_NscanChannel_t Channel)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));
    KF_CMP_ASSERT(CHECK_CMP_NSCANCHANNEL(Channel));

    Cmpx->NSCANSQ0.bits.NSCAN2 = (uint32_t)Channel;
}

/**
 * @brief: 设置CMP0的被扫描的第3通道选择位
 * @param Cmpx: CMP寄存器结构体指针
 * @param Channel: 被扫描的通道选择
 *          取值范围: Cmp_NscanChannel_t
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetNscan3(Cmp_RegisterMap_t *const Cmpx, Cmp_NscanChannel_t Channel)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));
    KF_CMP_ASSERT(CHECK_CMP_NSCANCHANNEL(Channel));

    Cmpx->NSCANSQ0.bits.NSCAN3 = (uint32_t)Channel;
}

/**
 * @brief: 设置CMP0的被扫描的第4通道选择位
 * @param Cmpx: CMP寄存器结构体指针
 * @param Channel: 被扫描的通道选择
 *          取值范围: Cmp_NscanChannel_t
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetNscan4(Cmp_RegisterMap_t *const Cmpx, Cmp_NscanChannel_t Channel)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));
    KF_CMP_ASSERT(CHECK_CMP_NSCANCHANNEL(Channel));

    Cmpx->NSCANSQ0.bits.NSCAN4 = (uint32_t)Channel;
}

/**
 * @brief: 设置CMP0的被扫描的第5通道选择位
 * @param Cmpx: CMP寄存器结构体指针
 * @param Channel: 被扫描的通道选择
 *          取值范围: Cmp_NscanChannel_t
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetNscan5(Cmp_RegisterMap_t *const Cmpx, Cmp_NscanChannel_t Channel)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));
    KF_CMP_ASSERT(CHECK_CMP_NSCANCHANNEL(Channel));

    Cmpx->NSCANSQ0.bits.NSCAN5 = (uint32_t)Channel;
}

/**
 * @brief: 设置CMP0的被扫描的第6通道选择位
 * @param Cmpx: CMP寄存器结构体指针
 * @param Channel: 被扫描的通道选择
 *          取值范围: Cmp_NscanChannel_t
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetNscan6(Cmp_RegisterMap_t *const Cmpx, Cmp_NscanChannel_t Channel)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));
    KF_CMP_ASSERT(CHECK_CMP_NSCANCHANNEL(Channel));

    Cmpx->NSCANSQ0.bits.NSCAN6 = (uint32_t)Channel;
}

/**
 * @brief: 设置CMP0的被扫描的第7通道选择位
 * @param Cmpx: CMP寄存器结构体指针
 * @param Channel: 被扫描的通道选择
 *          取值范围: Cmp_NscanChannel_t
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetNscan7(Cmp_RegisterMap_t *const Cmpx, Cmp_NscanChannel_t Channel)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));
    KF_CMP_ASSERT(CHECK_CMP_NSCANCHANNEL(Channel));

    Cmpx->NSCANSQ0.bits.NSCAN7 = (uint32_t)Channel;
}

/**
 * @brief: 设置CMP0的被扫描的第8通道选择位
 * @param Cmpx: CMP寄存器结构体指针
 * @param Channel: 被扫描的通道选择
 *          取值范围: Cmp_NscanChannel_t
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetNscan8(Cmp_RegisterMap_t *const Cmpx, Cmp_NscanChannel_t Channel)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));
    KF_CMP_ASSERT(CHECK_CMP_NSCANCHANNEL(Channel));

    Cmpx->NSCANSQ1.bits.NSCAN8 = (uint32_t)Channel;
}

/**
 * @brief: 设置CMP0的被扫描的第9通道选择位
 * @param Cmpx: CMP寄存器结构体指针
 * @param Channel: 被扫描的通道选择
 *          取值范围: Cmp_NscanChannel_t
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetNscan9(Cmp_RegisterMap_t *const Cmpx, Cmp_NscanChannel_t Channel)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));
    KF_CMP_ASSERT(CHECK_CMP_NSCANCHANNEL(Channel));

    Cmpx->NSCANSQ1.bits.NSCAN9 = (uint32_t)Channel;
}

/**
 * @brief: 设置CMP0的被扫描的第10通道选择位
 * @param Cmpx: CMP寄存器结构体指针
 * @param Channel: 被扫描的通道选择
 *          取值范围: Cmp_NscanChannel_t
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetNscan10(Cmp_RegisterMap_t *const Cmpx, Cmp_NscanChannel_t Channel)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));
    KF_CMP_ASSERT(CHECK_CMP_NSCANCHANNEL(Channel));

    Cmpx->NSCANSQ1.bits.NSCAN10 = (uint32_t)Channel;
}

/**
 * @brief: 设置CMP0的被扫描的第11通道选择位
 * @param Cmpx: CMP寄存器结构体指针
 * @param Channel: 被扫描的通道选择
 *          取值范围: Cmp_NscanChannel_t
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetNscan11(Cmp_RegisterMap_t *const Cmpx, Cmp_NscanChannel_t Channel)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));
    KF_CMP_ASSERT(CHECK_CMP_NSCANCHANNEL(Channel));

    Cmpx->NSCANSQ1.bits.NSCAN11 = (uint32_t)Channel;
}

/**
 * @brief: 设置CMP0的被扫描的第12通道选择位
 * @param Cmpx: CMP寄存器结构体指针
 * @param Channel: 被扫描的通道选择
 *          取值范围: Cmp_NscanChannel_t
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetNscan12(Cmp_RegisterMap_t *const Cmpx, Cmp_NscanChannel_t Channel)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));
    KF_CMP_ASSERT(CHECK_CMP_NSCANCHANNEL(Channel));

    Cmpx->NSCANSQ1.bits.NSCAN12 = (uint32_t)Channel;
}

/**
 * @brief: 设置CMP0的被扫描的第13通道选择位
 * @param Cmpx: CMP寄存器结构体指针
 * @param Channel: 被扫描的通道选择
 *          取值范围: Cmp_NscanChannel_t
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetNscan13(Cmp_RegisterMap_t *const Cmpx, Cmp_NscanChannel_t Channel)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));
    KF_CMP_ASSERT(CHECK_CMP_NSCANCHANNEL(Channel));

    Cmpx->NSCANSQ1.bits.NSCAN13 = (uint32_t)Channel;
}

/**
 * @brief: 设置CMP0的被扫描的第14通道选择位
 * @param Cmpx: CMP寄存器结构体指针
 * @param Channel: 被扫描的通道选择
 *          取值范围: Cmp_NscanChannel_t
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetNscan14(Cmp_RegisterMap_t *const Cmpx, Cmp_NscanChannel_t Channel)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));
    KF_CMP_ASSERT(CHECK_CMP_NSCANCHANNEL(Channel));

    Cmpx->NSCANSQ1.bits.NSCAN14 = (uint32_t)Channel;
}

/**
 * @brief: 设置CMP0的被扫描的第15通道选择位
 * @param Cmpx: CMP寄存器结构体指针
 * @param Channel: 被扫描的通道选择
 *          取值范围: Cmp_NscanChannel_t
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetNscan15(Cmp_RegisterMap_t *const Cmpx, Cmp_NscanChannel_t Channel)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));
    KF_CMP_ASSERT(CHECK_CMP_NSCANCHANNEL(Channel));

    Cmpx->NSCANSQ1.bits.NSCAN15 = (uint32_t)Channel;
}

/**
 * @brief: 获取正端配置的被扫描的通道比较结果
 * @param Cmpx: CMP寄存器结构体指针
 * @param Offset: 对应的序列 0-15
 * @retval BitStatus_t:
 *         true
 *         BIT_RESET
 */
KF_INLINE bool Cmp_LL_GetPositiveChannelOutput(const Cmp_RegisterMap_t *const Cmpx, uint32_t Offset)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));
    KF_CMP_ASSERT(((Offset >= 0x0U) && (Offset <= 0xFU)));

    return ((Cmpx->SR.bits.PCHOUT >> Offset) & 0x0001U) != 0U;
}

/**
 * @brief: 获取负端配置的被扫描的通道比较结果
 * @param Cmpx: CMP寄存器结构体指针
 * @param Offset: 对应的序列 0-15
 * @retval BitStatus_t:
 *         true
 *         BIT_RESET
 */
KF_INLINE bool Cmp_LL_GetNegativeChannelOutput(const Cmp_RegisterMap_t *const Cmpx, uint32_t Offset)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));
    KF_CMP_ASSERT(((Offset >= 0x0U) && (Offset <= 0xFU)));

    return ((Cmpx->SR.bits.NCHOUT >> Offset) & 0x0001U) != 0U;
}

/**
 * @brief: 获取正端配置的被扫描的通道标志位
 * @param Cmpx: CMP寄存器结构体指针
 * @param Offset: 对应的序列 0-15
 * @retval BitStatus_t:
 *         true
 *         BIT_RESET
 */
KF_INLINE bool Cmp_LL_GetPositiveChannelFlag(const Cmp_RegisterMap_t *const Cmpx, uint32_t Offset)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));
    KF_CMP_ASSERT(((Offset >= 0x0U) && (Offset <= 0xFU)));

    return ((Cmpx->CHFLAG.bits.PCHFLAG >> Offset) & 0x0001U) != 0U;
}

/**
 * @brief: 获取负端配置的被扫描的通道标志位
 * @param Cmpx: CMP寄存器结构体指针
 * @param Offset: 对应的序列 0-15
 * @retval BitStatus_t:
 *         true
 *         BIT_RESET
 */
KF_INLINE bool Cmp_LL_GetNegativeChannelFlag(const Cmp_RegisterMap_t *const Cmpx, uint32_t Offset)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));
    KF_CMP_ASSERT(((Offset >= 0x0U) && (Offset <= 0xFU)));

    return ((Cmpx->CHFLAG.bits.NCHFLAG >> Offset) & 0x0001U) != 0U;
}

/**
 * @brief: 设置正端通道0标志位清零
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 清零操作
 *          false 无
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetPCH0IC(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CHIC.bits.PCH0IC = State ? 1U : 0U;
}

/**
 * @brief: 设置正端通道1标志位清零
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 清零操作
 *          false 无
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetPCH1IC(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CHIC.bits.PCH1IC = State ? 1U : 0U;
}

/**
 * @brief: 设置正端通道2标志位清零
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 清零操作
 *          false 无
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetPCH2IC(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CHIC.bits.PCH2IC = State ? 1U : 0U;
}

/**
 * @brief: 设置正端通道3标志位清零
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 清零操作
 *          false 无
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetPCH3IC(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CHIC.bits.PCH3IC = State ? 1U : 0U;
}

/**
 * @brief: 设置正端通道4标志位清零
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 清零操作
 *          false 无
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetPCH4IC(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CHIC.bits.PCH4IC = State ? 1U : 0U;
}

/**
 * @brief: 设置正端通道5标志位清零
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 清零操作
 *          false 无
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetPCH5IC(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CHIC.bits.PCH5IC = State ? 1U : 0U;
}

/**
 * @brief: 设置正端通道6标志位清零
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 清零操作
 *          false 无
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetPCH6IC(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CHIC.bits.PCH6IC = State ? 1U : 0U;
}

/**
 * @brief: 设置正端通道7标志位清零
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 清零操作
 *          false 无
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetPCH7IC(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CHIC.bits.PCH7IC = State ? 1U : 0U;
}

/**
 * @brief: 设置正端通道8标志位清零
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 清零操作
 *          false 无
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetPCH8IC(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CHIC.bits.PCH8IC = State ? 1U : 0U;
}

/**
 * @brief: 设置正端通道9中断标志清零位
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 清零操作
 *          false 无
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetPCH9IC(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CHIC.bits.PCH9IC = State ? 1U : 0U;
}

/**
 * @brief: 设置正端通道10中断标志清零位
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 清零操作
 *          false 无
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetPCH10IC(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CHIC.bits.PCH10IC = State ? 1U : 0U;
}

/**
 * @brief: 设置正端通道11中断标志清零位
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 清零操作
 *          false 无
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetPCH11IC(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CHIC.bits.PCH11IC = State ? 1U : 0U;
}

/**
 * @brief: 设置正端通道12中断标志清零位
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 清零操作
 *          false 无
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetPCH12IC(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CHIC.bits.PCH12IC = State ? 1U : 0U;
}

/**
 * @brief: 设置正端通道13中断标志清零位
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 清零操作
 *          false 无
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetPCH13IC(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CHIC.bits.PCH13IC = State ? 1U : 0U;
}

/**
 * @brief: 设置正端通道14中断标志清零位
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 清零操作
 *          false 无
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetPCH14IC(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CHIC.bits.PCH14IC = State ? 1U : 0U;
}

/**
 * @brief: 设置正端通道15中断标志清零位
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 清零操作
 *          false 无
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetPCH15IC(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CHIC.bits.PCH15IC = State ? 1U : 0U;
}

/**
 * @brief: 设置负端通道0标志位清零
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 清零操作
 *          false 无
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetNCH0IC(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CHIC.bits.NCH0IC = State ? 1U : 0U;
}

/**
 * @brief: 设置负端通道1标志位清零
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 清零操作
 *          false 无
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetNCH1IC(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CHIC.bits.NCH1IC = State ? 1U : 0U;
}

/**
 * @brief: 设置负端通道2标志位清零
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 清零操作
 *          false 无
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetNCH2IC(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CHIC.bits.NCH2IC = State ? 1U : 0U;
}

/**
 * @brief: 设置负端通道3标志位清零
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 清零操作
 *          false 无
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetNCH3IC(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CHIC.bits.NCH3IC = State ? 1U : 0U;
}

/**
 * @brief: 设置负端通道4标志位清零
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 清零操作
 *          false 无
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetNCH4IC(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CHIC.bits.NCH4IC = State ? 1U : 0U;
}

/**
 * @brief: 设置负端通道5标志位清零
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 清零操作
 *          false 无
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetNCH5IC(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CHIC.bits.NCH5IC = State ? 1U : 0U;
}

/**
 * @brief: 设置负端通道6标志位清零
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 清零操作
 *          false 无
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetNCH6IC(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CHIC.bits.NCH6IC = State ? 1U : 0U;
}

/**
 * @brief: 设置负端通道7标志位清零
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 清零操作
 *          false 无
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetNCH7IC(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CHIC.bits.NCH7IC = State ? 1U : 0U;
}

/**
 * @brief: 设置负端通道8清零标志位
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 清零操作
 *          false 无
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetNCH8IC(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CHIC.bits.NCH8IC = State ? 1U : 0U;
}

/**
 * @brief: 设置负端通道9清零标志位
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 清零操作
 *          false 无
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetNCH9IC(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CHIC.bits.NCH9IC = State ? 1U : 0U;
}

/**
 * @brief: 设置负端通道10清零标志位
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 清零操作
 *          false 无
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetNCH10IC(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CHIC.bits.NCH10IC = State ? 1U : 0U;
}

/**
 * @brief: 设置负端通道11清零标志位
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 清零操作
 *          false 无
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetNCH11IC(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CHIC.bits.NCH11IC = State ? 1U : 0U;
}

/**
 * @brief: 设置负端通道12清零标志位
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 清零操作
 *          false 无
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetNCH12IC(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CHIC.bits.NCH12IC = State ? 1U : 0U;
}

/**
 * @brief: 设置负端通道13清零标志位
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 清零操作
 *          false 无
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetNCH13IC(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CHIC.bits.NCH13IC = State ? 1U : 0U;
}

/**
 * @brief: 设置负端通道14清零标志位
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 清零操作
 *          false 无
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetNCH14IC(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CHIC.bits.NCH14IC = State ? 1U : 0U;
}

/**
 * @brief: 设置负端通道15清零标志位
 * @param Cmpx: CMP寄存器结构体指针
 * @param State
 *          true 清零操作
 *          false 无
 * @retval 无
 */
KF_INLINE void Cmp_LL_SetNCH15IC(Cmp_RegisterMap_t *const Cmpx, bool State)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));

    Cmpx->CHIC.bits.NCH15IC = State ? 1U : 0U;
}

/**
 * @brief 清除负端通道标志
 *
 * @param Cmpx CMP寄存器结构体指针
 * @param Offset 通道序号, 0x0 ~ 0xF
 * @retval void
 */
KF_INLINE void Cmp_LL_ClearNegativeChannelIntrFlag(Cmp_RegisterMap_t *const Cmpx, uint32_t Offset)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));
    KF_CMP_ASSERT(((Offset >= 0x0U) && (Offset <= 0xFU)));

    uint32_t Pos;

    Pos = Offset + 16U;
    /* PRQA S 3473 ++ #KQR003473 */
    REG_BIT_SET(Cmpx->CHIC.reg, 1UL << Pos);
    NOP();
    NOP();
    NOP();
    NOP();
    REG_BIT_CLR(Cmpx->CHIC.reg, 1UL << Pos);
    /* PRQA S 3473 -- #KQR003473 */
}

/**
 * @brief 清除正端通道标志
 *
 * @param Cmpx CMP寄存器结构体指针
 * @param Offset 通道序号, 0x0 ~ 0xF
 * @retval void
 */
KF_INLINE void Cmp_LL_ClearPositiveChannelIntrFlag(Cmp_RegisterMap_t *const Cmpx, uint32_t Offset)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));
    KF_CMP_ASSERT(((Offset >= 0x0U) && (Offset <= 0xFU)));

    /* PRQA S 3473 ++ #KQR003473 */
    REG_BIT_SET(Cmpx->CHIC.reg, 1UL << Offset);
    NOP();
    NOP();
    NOP();
    NOP();
    REG_BIT_CLR(Cmpx->CHIC.reg, 1UL << Offset);
    /* PRQA S 3473 -- #KQR003473 */
}

/**
 * @brief 获取中断发生状态
 *
 * @param Cmpx CMP寄存器结构体指针
 * @param IntIndex 获取中断序号, 可见 Cmp_IntrGetIndex_t
 * @retval bool 中断发生状态
 *         true    发生了中断，且已使能
 *         false    未发生中断，或未使能
 */
KF_INLINE bool Cmp_LL_GetIntrState(const Cmp_RegisterMap_t *const Cmpx, Cmp_IntrGetIndex_t IntIndex)
{
    KF_CMP_ASSERT(CHECK_CMP_ALL_PERIPH_ADDR(Cmpx));
    KF_CMP_ASSERT(CHECK_CMP_INTRGETINDEX(IntIndex));
    uint32_t mask = (uint32_t)IntIndex - (uint32_t)CMP_INTR_GET_INDEX_C0IF + (uint32_t)CMP_INTR_SET_INDEX_C0IE;
    bool flag  = (REG_BITS_READ(Cmpx->CTL4.reg, (1UL << (uint32_t)IntIndex), (uint32_t)IntIndex) != 0U) ? true : false;
    bool state = (REG_BITS_READ(Cmpx->CTL4.reg, (1UL << mask), mask) != 0U) ? true : false;
    return flag && state;
}

#ifdef __cplusplus
}
#endif /*End of __cplusplus*/
#endif /*End of KF32A158SF_DRV_CMP_H*/
/* EOF */
