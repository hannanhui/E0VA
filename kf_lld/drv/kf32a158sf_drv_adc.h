/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name        : kf32a158sf_drv_adc.h
 *  @Date             : 2025-07-07
 *  @Version          : {{VersionDate}}
 *  @Description      : This file provides the driver functions for the ADC module.
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
#ifndef KF32A158SF_DRV_ADC_H
#define KF32A158SF_DRV_ADC_H

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
/* PRQA S 4342 EOF #KQR004342 */

/******************************************************************************
 *                      Include Files
 ******************************************************************************/
#include <stdint.h>
#include <stdbool.h>
#include "kf_types.h"
#include "kf32a158sf_reg_adc.h"

#ifdef KF_DRV_ADC_ASSERT
#include "dev_assert.h"
#define KF_ADC_ASSERT(x) KF_DEV_ASSERT(x)
#else
#define KF_ADC_ASSERT(x) ((void)0U)
#endif

/******************************************************************************
 *                      Macro or Inline
 ******************************************************************************/

/**  ADC清除中断掩码 Adc_IntrMaskClearIndex_t */
#define ADC_INTR_MASK_CLEAR_ENDIC   (1UL << 5U)
#define ADC_INTR_MASK_CLEAR_HPENDIC (1UL << 6U)
#define ADC_INTR_MASK_CLEAR_WDIC    (1UL << 7U)
#define ADC_INTR_MASK_CLEAR_EOCIC   (1UL << 12U)
#define CHECK_ADC_INTRMASKCLEARINDEX(x)                                                                                \
    (((x) == ADC_INTR_MASK_CLEAR_ENDIC) || ((x) == ADC_INTR_MASK_CLEAR_HPENDIC) ||                                     \
     ((x) == ADC_INTR_MASK_CLEAR_WDIC) || ((x) == ADC_INTR_MASK_CLEAR_EOCIC))

/******************************************************************************
 *                      Type definitions
 ******************************************************************************/

/** ADC时钟源 */
typedef enum
{
    ADC_SOURCE_SCLK  = 0U,
    ADC_SOURCE_HFCLK = 1U,
    ADC_SOURCE_LFCLK = 2U,
    ADC_SOURCE_PLL1  = 3U,
} Adc_Source_t;
#define CHECK_ADC_SOURCE(x)                                                                                            \
    (((x) == ADC_SOURCE_SCLK) || ((x) == ADC_SOURCE_HFCLK) || ((x) == ADC_SOURCE_LFCLK) || ((x) == ADC_SOURCE_PLL1))

/** ADC时钟分频 */
typedef enum
{
    ADC_CLK_EXP_DIV_2  = 0U,
    ADC_CLK_EXP_DIV_4  = 1U,
    ADC_CLK_EXP_DIV_8  = 2U,
    ADC_CLK_EXP_DIV_16 = 3U,
    ADC_CLK_EXP_DIV_32 = 4U,
    ADC_CLK_EXP_DIV_64 = 5U,

    ADC_CLK_EVEN_DIV_2  = 0U,
    ADC_CLK_EVEN_DIV_4  = 1U,
    ADC_CLK_EVEN_DIV_6  = 2U,
    ADC_CLK_EVEN_DIV_8  = 3U,
    ADC_CLK_EVEN_DIV_10 = 4U,
    ADC_CLK_EVEN_DIV_12 = 5U,
    ADC_CLK_EVEN_DIV_14 = 6U,
    ADC_CLK_EVEN_DIV_16 = 7U,
    ADC_CLK_EVEN_DIV_32 = 8U,
    ADC_CLK_EVEN_DIV_64 = 9U,
} Adc_ClkDiv_t;
#define CHECK_ADC_CLKDIV(x)                                                                                            \
    (((x) == ADC_CLK_EXP_DIV_2) || ((x) == ADC_CLK_EXP_DIV_4) || ((x) == ADC_CLK_EXP_DIV_8) ||                         \
     ((x) == ADC_CLK_EXP_DIV_16) || ((x) == ADC_CLK_EXP_DIV_32) || ((x) == ADC_CLK_EXP_DIV_64) ||                      \
     ((x) == ADC_CLK_EVEN_DIV_2) || ((x) == ADC_CLK_EVEN_DIV_4) || ((x) == ADC_CLK_EVEN_DIV_6) ||                      \
     ((x) == ADC_CLK_EVEN_DIV_8) || ((x) == ADC_CLK_EVEN_DIV_10) || ((x) == ADC_CLK_EVEN_DIV_12) ||                    \
     ((x) == ADC_CLK_EVEN_DIV_14) || ((x) == ADC_CLK_EVEN_DIV_16) || ((x) == ADC_CLK_EVEN_DIV_32) ||                   \
     ((x) == ADC_CLK_EVEN_DIV_64))

/** 常规通道外部触发事件 */
typedef enum
{
    ADC_EXTERNALTRIG_CCP1_CH1     = 0x0U,
    ADC_EXTERNALTRIG_CCP1_CH2     = 0x1U,
    ADC_EXTERNALTRIG_CCP1_CH3     = 0x2U,
    ADC_EXTERNALTRIG_CCP1_CH4     = 0x3U,
    ADC_EXTERNALTRIG_CCP2_CH1     = 0x4U,
    ADC_EXTERNALTRIG_CCP2_CH2     = 0x5U,
    ADC_EXTERNALTRIG_CCP2_CH3     = 0x6U,
    ADC_EXTERNALTRIG_CCP2_CH4     = 0x7U,
    ADC_EXTERNALTRIG_CCP3_CH1     = 0x8U,
    ADC_EXTERNALTRIG_CCP3_CH2     = 0x9U,
    ADC_EXTERNALTRIG_CCP3_CH3     = 0xAU,
    ADC_EXTERNALTRIG_CCP3_CH4     = 0xBU,
    ADC_EXTERNALTRIG_CCP4_CH1     = 0xCU,
    ADC_EXTERNALTRIG_CCP4_CH2     = 0xDU,
    ADC_EXTERNALTRIG_CCP4_CH3     = 0xEU,
    ADC_EXTERNALTRIG_CCP4_CH4     = 0xFU,
    ADC_EXTERNALTRIG_CCP18_CH1    = 0x10U,
    ADC_EXTERNALTRIG_CCP18_CH2    = 0x11U,
    ADC_EXTERNALTRIG_CCP18_CH3    = 0x12U,
    ADC_EXTERNALTRIG_CCP18_CH4    = 0x13U,
    ADC_EXTERNALTRIG_CCP19_CH1    = 0x14U,
    ADC_EXTERNALTRIG_CCP19_CH2    = 0x15U,
    ADC_EXTERNALTRIG_CCP19_CH3    = 0x16U,
    ADC_EXTERNALTRIG_CCP19_CH4    = 0x17U,
    ADC_EXTERNALTRIG_CCP20_CH1    = 0x18U,
    ADC_EXTERNALTRIG_CCP20_CH2    = 0x19U,
    ADC_EXTERNALTRIG_CCP20_CH3    = 0x1AU,
    ADC_EXTERNALTRIG_CCP20_CH4    = 0x1BU,
    ADC_EXTERNALTRIG_CCP21_CH1    = 0x1CU,
    ADC_EXTERNALTRIG_CCP21_CH2    = 0x1DU,
    ADC_EXTERNALTRIG_CCP21_CH3    = 0x1EU,
    ADC_EXTERNALTRIG_CCP21_CH4    = 0x1FU,
    ADC_EXTERNALTRIG_CCP5_CH1     = 0x20U,
    ADC_EXTERNALTRIG_CCP5_CH2     = 0x21U,
    ADC_EXTERNALTRIG_CCP5_CH3     = 0x22U,
    ADC_EXTERNALTRIG_CCP5_CH4     = 0x23U,
    ADC_EXTERNALTRIG_FDC0         = 0x24U,
    ADC_EXTERNALTRIG_FDC1         = 0x25U,
    ADC_EXTERNALTRIG_FDC2         = 0x26U,
    ADC_EXTERNALTRIG_ECFGL        = 0x27U,
    ADC_EXTERNALTRIG_T1TRGO       = 0x28U,
    ADC_EXTERNALTRIG_T2TRGO       = 0x29U,
    ADC_EXTERNALTRIG_T3TRGO       = 0x2AU,
    ADC_EXTERNALTRIG_T4TRGO       = 0x2BU,
    ADC_EXTERNALTRIG_T18TRGO      = 0x2CU,
    ADC_EXTERNALTRIG_T19TRGO      = 0x2DU,
    ADC_EXTERNALTRIG_T20TRGO      = 0x2EU,
    ADC_EXTERNALTRIG_T21TRGO      = 0x2FU,
    ADC_EXTERNALTRIG_T5TRGO       = 0x30U,
    ADC_EXTERNALTRIG_T9TRGO       = 0x31U,
    ADC_EXTERNALTRIG_T14TRGO      = 0x32U,
    ADC_EXTERNALTRIG_T25TRGO      = 0x33U,
    ADC_EXTERNALTRIG_T5_OVERFLOW  = 0x34U,
    ADC_EXTERNALTRIG_T6_OVERFLOW  = 0x35U,
    ADC_EXTERNALTRIG_EPWM11_AD0   = 0x36U,
    ADC_EXTERNALTRIG_EPWM11_AD1   = 0x37U,
    ADC_EXTERNALTRIG_EPWM12_AD0   = 0x38U,
    ADC_EXTERNALTRIG_EPWM12_AD1   = 0x39U,
    ADC_EXTERNALTRIG_EPWM13_AD0   = 0x3AU,
    ADC_EXTERNALTRIG_EPWM13_AD1   = 0x3BU,
    ADC_EXTERNALTRIG_EPWM16_AD0   = 0x3CU,
    ADC_EXTERNALTRIG_EPWM16_AD1   = 0x3DU,
    ADC_EXTERNALTRIG_CCP0_CH1     = 0x40U,
    ADC_EXTERNALTRIG_CCP0_CH2     = 0x41U,
    ADC_EXTERNALTRIG_CCP0_CH3     = 0x42U,
    ADC_EXTERNALTRIG_CCP0_CH4     = 0x43U,
    ADC_EXTERNALTRIG_CCP9_CH1     = 0x44U,
    ADC_EXTERNALTRIG_CCP9_CH2     = 0x45U,
    ADC_EXTERNALTRIG_CCP9_CH3     = 0x46U,
    ADC_EXTERNALTRIG_CCP9_CH4     = 0x47U,
    ADC_EXTERNALTRIG_CCP25_CH1    = 0x48U,
    ADC_EXTERNALTRIG_CCP25_CH2    = 0x49U,
    ADC_EXTERNALTRIG_CCP25_CH3    = 0x4AU,
    ADC_EXTERNALTRIG_CCP25_CH4    = 0x4BU,
    ADC_EXTERNALTRIG_T9_OVERFLOW  = 0x4CU,
    ADC_EXTERNALTRIG_T10_OVERFLOW = 0x4DU,
    ADC_EXTERNALTRIG_T25_OVERFLOW = 0x4EU,
    ADC_EXTERNALTRIG_T26_OVERFLOW = 0x4FU,
    ADC_EXTERNALTRIG_EPWM31_AD0   = 0x50U,
    ADC_EXTERNALTRIG_EPWM31_AD1   = 0x51U,
    ADC_EXTERNALTRIG_EPWM32_AD0   = 0x52U,
    ADC_EXTERNALTRIG_EPWM32_AD1   = 0x53U,
    ADC_EXTERNALTRIG_EPWM33_AD0   = 0x54U,
    ADC_EXTERNALTRIG_EPWM33_AD1   = 0x55U,
    ADC_EXTERNALTRIG_EPWM36_AD0   = 0x56U,
    ADC_EXTERNALTRIG_EPWM36_AD1   = 0x57U,
    ADC_EXTERNALTRIG_CCP22_CH1    = 0x58U,
    ADC_EXTERNALTRIG_CCP22_CH2    = 0x59U,
    ADC_EXTERNALTRIG_CCP22_CH3    = 0x5AU,
    ADC_EXTERNALTRIG_CCP22_CH4    = 0x5BU,
    ADC_EXTERNALTRIG_CCP23_CH1    = 0x5CU,
    ADC_EXTERNALTRIG_CCP23_CH2    = 0x5DU,
    ADC_EXTERNALTRIG_CCP23_CH3    = 0x5EU,
    ADC_EXTERNALTRIG_CCP23_CH4    = 0x5FU,
    ADC_EXTERNALTRIG_T22TRGO      = 0x60U,
    ADC_EXTERNALTRIG_T23TRGO      = 0x61U,
    /* 7 bit*/
    ADC_EXTERNALTRIG_BIT_MAX = 0x7FU,
} Adc_ExternalTrig_t;
#define CHECK_ADC_EXTERNALTRIG(x)                                                                                      \
    (((x) >= ADC_EXTERNALTRIG_CCP1_CH1) && ((x) <= ADC_EXTERNALTRIG_T23TRGO) && ((x) != 0x3EU) && ((x) != 0x3FU))

/** ADC参考电压 */
typedef enum
{
    ADC_REF_VOL_NONE = 0U,
    ADC_REF_VOL_VDDA = 1U,
    ADC_REF_VOL_FVR1 = 2U,
    ADC_REF_VOL_VREF = 2U,
    ADC_REF_VOL_FVR  = 3U,
} Adc_RefVol_t;
#define CHECK_ADC_REFVOL(x)                                                                                            \
    (((x) == ADC_REF_VOL_NONE) || ((x) == ADC_REF_VOL_VDDA) || ((x) == ADC_REF_VOL_FVR1) ||                            \
     ((x) == ADC_REF_VOL_VREF) || ((x) == ADC_REF_VOL_FVR))

/** 高优先级通道外部触发事件 */
typedef enum
{
    ADC_HPEXTERNALTRIG_CCP1_CH1     = 0x0U,
    ADC_HPEXTERNALTRIG_CCP1_CH2     = 0x1U,
    ADC_HPEXTERNALTRIG_CCP1_CH3     = 0x2U,
    ADC_HPEXTERNALTRIG_CCP1_CH4     = 0x3U,
    ADC_HPEXTERNALTRIG_CCP2_CH1     = 0x4U,
    ADC_HPEXTERNALTRIG_CCP2_CH2     = 0x5U,
    ADC_HPEXTERNALTRIG_CCP2_CH3     = 0x6U,
    ADC_HPEXTERNALTRIG_CCP2_CH4     = 0x7U,
    ADC_HPEXTERNALTRIG_CCP3_CH1     = 0x8U,
    ADC_HPEXTERNALTRIG_CCP3_CH2     = 0x9U,
    ADC_HPEXTERNALTRIG_CCP3_CH3     = 0xAU,
    ADC_HPEXTERNALTRIG_CCP3_CH4     = 0xBU,
    ADC_HPEXTERNALTRIG_CCP4_CH1     = 0xCU,
    ADC_HPEXTERNALTRIG_CCP4_CH2     = 0xDU,
    ADC_HPEXTERNALTRIG_CCP4_CH3     = 0xEU,
    ADC_HPEXTERNALTRIG_CCP4_CH4     = 0xFU,
    ADC_HPEXTERNALTRIG_CCP18_CH1    = 0x10U,
    ADC_HPEXTERNALTRIG_CCP18_CH2    = 0x11U,
    ADC_HPEXTERNALTRIG_CCP18_CH3    = 0x12U,
    ADC_HPEXTERNALTRIG_CCP18_CH4    = 0x13U,
    ADC_HPEXTERNALTRIG_CCP19_CH1    = 0x14U,
    ADC_HPEXTERNALTRIG_CCP19_CH2    = 0x15U,
    ADC_HPEXTERNALTRIG_CCP19_CH3    = 0x16U,
    ADC_HPEXTERNALTRIG_CCP19_CH4    = 0x17U,
    ADC_HPEXTERNALTRIG_CCP20_CH1    = 0x18U,
    ADC_HPEXTERNALTRIG_CCP20_CH2    = 0x19U,
    ADC_HPEXTERNALTRIG_CCP20_CH3    = 0x1AU,
    ADC_HPEXTERNALTRIG_CCP20_CH4    = 0x1BU,
    ADC_HPEXTERNALTRIG_CCP21_CH1    = 0x1CU,
    ADC_HPEXTERNALTRIG_CCP21_CH2    = 0x1DU,
    ADC_HPEXTERNALTRIG_CCP21_CH3    = 0x1EU,
    ADC_HPEXTERNALTRIG_CCP21_CH4    = 0x1FU,
    ADC_HPEXTERNALTRIG_CCP5_CH1     = 0x20U,
    ADC_HPEXTERNALTRIG_CCP5_CH2     = 0x21U,
    ADC_HPEXTERNALTRIG_CCP5_CH3     = 0x22U,
    ADC_HPEXTERNALTRIG_CCP5_CH4     = 0x23U,
    ADC_HPEXTERNALTRIG_FDC0         = 0x24U,
    ADC_HPEXTERNALTRIG_FDC1         = 0x25U,
    ADC_HPEXTERNALTRIG_FDC2         = 0x26U,
    ADC_HPEXTERNALTRIG_ECFGL        = 0x27U,
    ADC_HPEXTERNALTRIG_T1TRGO       = 0x28U,
    ADC_HPEXTERNALTRIG_T2TRGO       = 0x29U,
    ADC_HPEXTERNALTRIG_T3TRGO       = 0x2AU,
    ADC_HPEXTERNALTRIG_T4TRGO       = 0x2BU,
    ADC_HPEXTERNALTRIG_T18TRGO      = 0x2CU,
    ADC_HPEXTERNALTRIG_T19TRGO      = 0x2DU,
    ADC_HPEXTERNALTRIG_T20TRGO      = 0x2EU,
    ADC_HPEXTERNALTRIG_T21TRGO      = 0x2FU,
    ADC_HPEXTERNALTRIG_T5TRGO       = 0x30U,
    ADC_HPEXTERNALTRIG_T9TRGO       = 0x31U,
    ADC_HPEXTERNALTRIG_T14TRGO      = 0x32U,
    ADC_HPEXTERNALTRIG_T25TRGO      = 0x33U,
    ADC_HPEXTERNALTRIG_T5_OVERFLOW  = 0x34U,
    ADC_HPEXTERNALTRIG_T6_OVERFLOW  = 0x35U,
    ADC_HPEXTERNALTRIG_EPWM11_AD0   = 0x36U,
    ADC_HPEXTERNALTRIG_EPWM11_AD1   = 0x37U,
    ADC_HPEXTERNALTRIG_EPWM12_AD0   = 0x38U,
    ADC_HPEXTERNALTRIG_EPWM12_AD1   = 0x39U,
    ADC_HPEXTERNALTRIG_EPWM13_AD0   = 0x3AU,
    ADC_HPEXTERNALTRIG_EPWM13_AD1   = 0x3BU,
    ADC_HPEXTERNALTRIG_EPWM16_AD0   = 0x3CU,
    ADC_HPEXTERNALTRIG_EPWM16_AD1   = 0x3DU,
    ADC_HPEXTERNALTRIG_CCP0_CH1     = 0x40U,
    ADC_HPEXTERNALTRIG_CCP0_CH2     = 0x41U,
    ADC_HPEXTERNALTRIG_CCP0_CH3     = 0x42U,
    ADC_HPEXTERNALTRIG_CCP0_CH4     = 0x43U,
    ADC_HPEXTERNALTRIG_CCP9_CH1     = 0x44U,
    ADC_HPEXTERNALTRIG_CCP9_CH2     = 0x45U,
    ADC_HPEXTERNALTRIG_CCP9_CH3     = 0x46U,
    ADC_HPEXTERNALTRIG_CCP9_CH4     = 0x47U,
    ADC_HPEXTERNALTRIG_CCP25_CH1    = 0x48U,
    ADC_HPEXTERNALTRIG_CCP25_CH2    = 0x49U,
    ADC_HPEXTERNALTRIG_CCP25_CH3    = 0x4AU,
    ADC_HPEXTERNALTRIG_CCP25_CH4    = 0x4BU,
    ADC_HPEXTERNALTRIG_T9_OVERFLOW  = 0x4CU,
    ADC_HPEXTERNALTRIG_T10_OVERFLOW = 0x4DU,
    ADC_HPEXTERNALTRIG_T25_OVERFLOW = 0x4EU,
    ADC_HPEXTERNALTRIG_T26_OVERFLOW = 0x4FU,
    ADC_HPEXTERNALTRIG_EPWM31_AD0   = 0x50U,
    ADC_HPEXTERNALTRIG_EPWM31_AD1   = 0x51U,
    ADC_HPEXTERNALTRIG_EPWM32_AD0   = 0x52U,
    ADC_HPEXTERNALTRIG_EPWM32_AD1   = 0x53U,
    ADC_HPEXTERNALTRIG_EPWM33_AD0   = 0x54U,
    ADC_HPEXTERNALTRIG_EPWM33_AD1   = 0x55U,
    ADC_HPEXTERNALTRIG_EPWM36_AD0   = 0x56U,
    ADC_HPEXTERNALTRIG_EPWM36_AD1   = 0x57U,
    ADC_HPEXTERNALTRIG_CCP22_CH1    = 0x58U,
    ADC_HPEXTERNALTRIG_CCP22_CH2    = 0x59U,
    ADC_HPEXTERNALTRIG_CCP22_CH3    = 0x5AU,
    ADC_HPEXTERNALTRIG_CCP22_CH4    = 0x5BU,
    ADC_HPEXTERNALTRIG_CCP23_CH1    = 0x5CU,
    ADC_HPEXTERNALTRIG_CCP23_CH2    = 0x5DU,
    ADC_HPEXTERNALTRIG_CCP23_CH3    = 0x5EU,
    ADC_HPEXTERNALTRIG_CCP23_CH4    = 0x5FU,
    ADC_HPEXTERNALTRIG_T22TRGO      = 0x60U,
    ADC_HPEXTERNALTRIG_T23TRGO      = 0x61U,
    /* 7 bit*/
    ADC_HPEXTERNALTRIG_BIT_MAX = 0x7FU,
} Adc_HpExternalTrig_t;
#define CHECK_ADC_HPEXTERNALTRIG(x)                                                                                    \
    (((x) >= ADC_HPEXTERNALTRIG_CCP1_CH1) && ((x) <= ADC_HPEXTERNALTRIG_T23TRGO) && ((x) != 0x3EU) && ((x) != 0x3FU))

/** 双ADC模式 */
typedef enum
{
    ADC_DMODE_SINGLE                     = 0U,
    ADC_DMODE_REGULAR_HPRIORITY          = 1U,
    ADC_DMODE_REGULAR_ALTERNATELY        = 2U,
    ADC_DMODE_HPRIORITY_FAST_ALTERNATELY = 3U,
    ADC_DMODE_HPRIORITY_SYNC             = 4U,
    ADC_DMODE_REGULAR_SYNC               = 5U,
    ADC_DMODE_FAST_ALTERNATELY_SYNC      = 6U,
    ADC_DMODE_SLOW_ALTERNATELY_SYNC      = 7U,
    ADC_DMODE_ALTERNATELY_TRIGGER        = 8U,
    ADC_DMODE_BIT_MAX                    = 0xFU,
} Adc_DoubleMode_t;
#define CHECK_ADC_DOUBLEMODE(x)                                                                                        \
    (((x) == ADC_DMODE_SINGLE) || ((x) == ADC_DMODE_REGULAR_HPRIORITY) || ((x) == ADC_DMODE_REGULAR_ALTERNATELY) ||    \
     ((x) == ADC_DMODE_HPRIORITY_FAST_ALTERNATELY) || ((x) == ADC_DMODE_HPRIORITY_SYNC) ||                             \
     ((x) == ADC_DMODE_REGULAR_SYNC) || ((x) == ADC_DMODE_FAST_ALTERNATELY_SYNC) ||                                    \
     ((x) == ADC_DMODE_SLOW_ALTERNATELY_SYNC) || ((x) == ADC_DMODE_ALTERNATELY_TRIGGER))

/** ADC通道序号 */
typedef enum
{
    ADC_CHANNEL_0   = 0x00U,
    ADC_CHANNEL_1   = 0x01U,
    ADC_CHANNEL_2   = 0x02U,
    ADC_CHANNEL_3   = 0x03U,
    ADC_CHANNEL_4   = 0x04U,
    ADC_CHANNEL_5   = 0x05U,
    ADC_CHANNEL_6   = 0x06U,
    ADC_CHANNEL_7   = 0x07U,
    ADC_CHANNEL_8   = 0x08U,
    ADC_CHANNEL_9   = 0x09U,
    ADC_CHANNEL_10  = 0x0AU,
    ADC_CHANNEL_11  = 0x0BU,
    ADC_CHANNEL_12  = 0x0CU,
    ADC_CHANNEL_13  = 0x0DU,
    ADC_CHANNEL_14  = 0x0EU,
    ADC_CHANNEL_15  = 0x0FU,
    ADC_CHANNEL_16  = 0x10U,
    ADC_CHANNEL_17  = 0x11U,
    ADC_CHANNEL_18  = 0x12U,
    ADC_CHANNEL_19  = 0x13U,
    ADC_CHANNEL_20  = 0x14U,
    ADC_CHANNEL_21  = 0x15U,
    ADC_CHANNEL_22  = 0x16U,
    ADC_CHANNEL_23  = 0x17U,
    ADC_CHANNEL_24  = 0x18U,
    ADC_CHANNEL_25  = 0x19U,
    ADC_CHANNEL_26  = 0x1AU,
    ADC_CHANNEL_27  = 0x1BU,
    ADC_CHANNEL_28  = 0x1CU,
    ADC_CHANNEL_29  = 0x1DU,
    ADC_CHANNEL_30  = 0x1EU,
    ADC_CHANNEL_31  = 0x1FU,
    ADC_CHANNEL_32  = 0x20U,
    ADC_CHANNEL_33  = 0x21U,
    ADC_CHANNEL_34  = 0x22U,
    ADC_CHANNEL_35  = 0x23U,
    ADC_CHANNEL_36  = 0x24U,
    ADC_CHANNEL_37  = 0x25U,
    ADC_CHANNEL_38  = 0x26U,
    ADC_CHANNEL_39  = 0x27U,
    ADC_CHANNEL_40  = 0x28U,
    ADC_CHANNEL_41  = 0x29U,
    ADC_CHANNEL_42  = 0x2AU,
    ADC_CHANNEL_43  = 0x2BU,
    ADC_CHANNEL_44  = 0x2CU,
    ADC_CHANNEL_45  = 0x2DU,
    ADC_CHANNEL_46  = 0x2EU,
    ADC_CHANNEL_47  = 0x2FU,
    ADC_CHANNEL_48  = 0x30U,
    ADC_CHANNEL_49  = 0x31U,
    ADC_CHANNEL_50  = 0x32U,
    ADC_CHANNEL_51  = 0x33U,
    ADC_CHANNEL_52  = 0x34U,
    ADC_CHANNEL_53  = 0x35U,
    ADC_CHANNEL_54  = 0x36U,
    ADC_CHANNEL_55  = 0x37U,
    ADC_CHANNEL_56  = 0x38U,
    ADC_CHANNEL_57  = 0x39U,
    ADC_CHANNEL_58  = 0x3AU,
    ADC_CHANNEL_59  = 0x3BU,
    ADC_CHANNEL_60  = 0x3CU,
    ADC_CHANNEL_61  = 0x3DU,
    ADC_CHANNEL_62  = 0x3EU,
    ADC_CHANNEL_63  = 0x3FU,
    ADC_CHANNEL_64  = 0x40U,
    ADC_CHANNEL_65  = 0x41U,
    ADC_CHANNEL_66  = 0x42U,
    ADC_CHANNEL_67  = 0x43U,
    ADC_CHANNEL_68  = 0x44U,
    ADC_CHANNEL_69  = 0x45U,
    ADC_CHANNEL_70  = 0x46U,
    ADC_CHANNEL_71  = 0x47U,
    ADC_CHANNEL_72  = 0x48U,
    ADC_CHANNEL_73  = 0x49U,
    ADC_CHANNEL_74  = 0x4AU,
    ADC_CHANNEL_75  = 0x4BU,
    ADC_CHANNEL_76  = 0x4CU,
    ADC_CHANNEL_77  = 0x4DU,
    ADC_CHANNEL_78  = 0x4EU,
    ADC_CHANNEL_79  = 0x4FU,
    ADC_CHANNEL_80  = 0x50U,
    ADC_CHANNEL_81  = 0x51U,
    ADC_CHANNEL_82  = 0x52U,
    ADC_CHANNEL_83  = 0x53U,
    ADC_CHANNEL_84  = 0x54U,
    ADC_CHANNEL_85  = 0x55U,
    ADC_CHANNEL_86  = 0x56U,
    ADC_CHANNEL_87  = 0x57U,
    ADC_CHANNEL_88  = 0x58U,
    ADC_CHANNEL_89  = 0x59U,
    ADC_CHANNEL_90  = 0x5AU,
    ADC_CHANNEL_91  = 0x5BU,
    ADC_CHANNEL_92  = 0x5CU,
    ADC_CHANNEL_93  = 0x5DU,
    ADC_CHANNEL_94  = 0x5EU,
    ADC_CHANNEL_95  = 0x5FU,
    ADC_CHANNEL_96  = 0x60U,
    ADC_CHANNEL_97  = 0x61U,
    ADC_CHANNEL_98  = 0x62U,
    ADC_CHANNEL_99  = 0x63U,
    ADC_CHANNEL_100 = 0x64U,
    ADC_CHANNEL_101 = 0x65U,
    ADC_CHANNEL_102 = 0x66U,
    ADC_CHANNEL_103 = 0x67U,
    ADC_CHANNEL_104 = 0x68U,
    ADC_CHANNEL_105 = 0x69U,
    ADC_CHANNEL_106 = 0x6AU,
    ADC_CHANNEL_107 = 0x6BU,
    ADC_CHANNEL_108 = 0x6CU,
    ADC_CHANNEL_109 = 0x6DU,
    ADC_CHANNEL_110 = 0x6EU,
    ADC_CHANNEL_111 = 0x6FU,
    ADC_CHANNEL_112 = 0x70U,
    ADC_CHANNEL_113 = 0x71U,
    ADC_CHANNEL_114 = 0x72U,
    ADC_CHANNEL_115 = 0x73U,
    ADC_CHANNEL_116 = 0x74U,
    ADC_CHANNEL_117 = 0x75U,
    ADC_CHANNEL_118 = 0x76U,
    ADC_CHANNEL_119 = 0x77U,
    ADC_CHANNEL_120 = 0x78U,
    ADC_CHANNEL_121 = 0x79U,
    ADC_CHANNEL_122 = 0x7AU,
    ADC_CHANNEL_123 = 0x7BU,
    ADC_CHANNEL_124 = 0x7CU,
    ADC_CHANNEL_125 = 0x7DU,
    ADC_CHANNEL_126 = 0x7EU,
    ADC_CHANNEL_127 = 0x7FU,
    ADC_CHANNEL_MAX,
    /* 8 bit*/
    ADC_CHANNEL_BIT_MAX = 0xFFU,
} Adc_Channel_t;
#define CHECK_ADC_CHANNEL(x) (((x) >= ADC_CHANNEL_0) && ((x) <= ADC_CHANNEL_127))

/* 常规通道扫描的转换个数 */
#define CHECK_ADC_REGULAR_SCAN_OFFSET(offset) (((offset) - 1) < 16)

/** 高优先级通道扫描的转换个数 */
#define CHECK_ADC_HP_SCAN_OFFSET(offset) (((offset) >= 0x1) && ((offset) <= 0x4))

/** 高优先级通道 */
typedef enum
{
    ADC_HPCH_0 = 0U,
    ADC_HPCH_1 = 1U,
    ADC_HPCH_2 = 2U,
    ADC_HPCH_3 = 3U,
    ADC_HPCH_4 = 4U,
    ADC_HPCH_5 = 5U,
} Adc_HpChannel_t;
#define CHECK_ADC_HPCHANNEL(x)                                                                                         \
    (((x) == ADC_HPCH_0) || ((x) == ADC_HPCH_1) || ((x) == ADC_HPCH_2) || ((x) == ADC_HPCH_3) ||                       \
     ((x) == ADC_HPCH_4) || ((x) == ADC_HPCH_5))

/** ADC常规通道扫描长度 */
#define CHECK_ADC_REGULAR_LENGTH(LENGTH) ((LENGTH) < 0x10)

/** ADC高优先级通道扫描长度 */
#define CHECK_ADC_HIGH_PRIORITY_LENGTH(LENGTH) (((LENGTH) >= 0x0) && ((LENGTH) <= 0x5))

/** ADC模拟看门狗通道选择 */
#define CHECK_ADC_WDCHANNEL(CHANNEL) ((CHANNEL) <= 0x7FU)

/** ADC额外采样时间 */
typedef enum
{
    ADC_EXTRA_TIME_0   = 0U,
    ADC_EXTRA_TIME_0P5 = 1U,
    ADC_EXTRA_TIME_1   = 2U,
    ADC_EXTRA_TIME_2   = 3U,
    ADC_EXTRA_TIME_4   = 4U,
    ADC_EXTRA_TIME_8   = 5U,
    ADC_EXTRA_TIME_16  = 6U,
    ADC_EXTRA_TIME_32  = 7U,
    ADC_EXTRA_TIME_64  = 8U,
    ADC_EXTRA_TIME_128 = 9U,
    ADC_EXTRA_TIME_256 = 10U
} Adc_ExtraTime_t;
#define CHECK_ADC_EXTRATIME(x) (((x) >= ADC_EXTRA_TIME_0) && ((x) <= ADC_EXTRA_TIME_256))

/** 通道触发 */
typedef enum
{
    ADC_EXTERNTRIG_T5_CCR0    = 0U,
    ADC_EXTERNTRIG_T5_CCR1    = 1U,
    ADC_EXTERNTRIG_T6_CCR0    = 2U,
    ADC_EXTERNTRIG_T9_CCR0    = 3U,
    ADC_EXTERNTRIG_T9_CCR1    = 4U,
    ADC_EXTERNTRIG_T10_CCR0   = 5U,
    ADC_EXTERNTRIG_T25_CCR0   = 6U,
    ADC_EXTERNTRIG_T25_CCR1   = 7U,
    ADC_EXTERNTRIG_T26_CCR0   = 8U,
    ADC_HPEXTERNTRIG_T5_CCR0  = 9U,
    ADC_HPEXTERNTRIG_T5_CCR1  = 10U,
    ADC_HPEXTERNTRIG_T6_CCR0  = 11U,
    ADC_HPEXTERNTRIG_T9_CCR0  = 12U,
    ADC_HPEXTERNTRIG_T9_CCR1  = 13U,
    ADC_HPEXTERNTRIG_T10_CCR0 = 14U,
    ADC_HPEXTERNTRIG_T25_CCR0 = 15U,
    ADC_HPEXTERNTRIG_T25_CCR1 = 16U,
    ADC_HPEXTERNTRIG_T26_CCR0 = 17U,
} Adc_CcrTrig_t;
#define CHECK_ADC_CCRTRIG(x) (((x) >= ADC_EXTERNTRIG_T5_CCR0) && ((x) <= ADC_HPEXTERNTRIG_T26_CCR0))

/**  ADC设置中断序号 */
typedef enum
{
    ADC_INTR_SET_ENDIE   = 8U,
    ADC_INTR_SET_HPENDIE = 9U,
    ADC_INTR_SET_WDIE    = 10U,
    ADC_INTR_SET_EOCIE   = 13U,
    ADC_INTR_SET_NOVIE   = 0x10FU,
} Adc_IntrSetIndex_t;
#define CHECK_ADC_INTRSETINDEX(x)                                                                                      \
    (((x) == ADC_INTR_SET_ENDIE) || ((x) == ADC_INTR_SET_HPENDIE) || ((x) == ADC_INTR_SET_WDIE) ||                     \
     ((x) == ADC_INTR_SET_EOCIE) || ((x) == ADC_INTR_SET_NOVIE))

/**  ADC获取中断序号 */
typedef enum
{
    ADC_INTR_GET_STARTIF        = 0U,
    ADC_INTR_GET_HPSTARTIF      = 1U,
    ADC_INTR_GET_ENDIF          = 2U,
    ADC_INTR_GET_HPENDIF        = 3U,
    ADC_INTR_GET_WDIF           = 4U,
    ADC_INTR_GET_EOCIF          = 11U,
    ADC_INTR_GET_STRIG_ERR_IF   = 14U,
    ADC_INTR_GET_HPSTRIG_ERR_IF = 16U,
    ADC_INTR_GET_NOVIF          = 0x10DU,
} Adc_IntrGetIndex_t;
#define CHECK_ADC_INTRGETINDEX(x)                                                                                      \
    (((x) == ADC_INTR_GET_STARTIF) || ((x) == ADC_INTR_GET_HPSTARTIF) || ((x) == ADC_INTR_GET_ENDIF) ||                \
     ((x) == ADC_INTR_GET_HPENDIF) || ((x) == ADC_INTR_GET_WDIF) || ((x) == ADC_INTR_GET_EOCIF) ||                     \
     ((x) == ADC_INTR_GET_STRIG_ERR_IF) || ((x) == ADC_INTR_GET_HPSTRIG_ERR_IF) || ((x) == ADC_INTR_GET_NOVIF))

/**  ADC清除中断序号 */
typedef enum
{
    ADC_INTR_CLEAR_ENDIC          = 5U,
    ADC_INTR_CLEAR_HPENDIC        = 6U,
    ADC_INTR_CLEAR_WDIC           = 7U,
    ADC_INTR_CLEAR_EOCIC          = 12U,
    ADC_INTR_CLEAR_STRIG_ERR_IC   = 15U,
    ADC_INTR_CLEAR_HPSTRIG_ERR_IC = 17U,
    ADC_INTR_CLEAR_NOVIC          = 0x10EU,
} Adc_IntrClearIndex_t;
#define CHECK_ADC_INTRCLEARINDEX(x)                                                                                    \
    (((x) == ADC_INTR_CLEAR_ENDIC) || ((x) == ADC_INTR_CLEAR_HPENDIC) || ((x) == ADC_INTR_CLEAR_WDIC) ||               \
     ((x) == ADC_INTR_CLEAR_EOCIC) || ((x) == ADC_INTR_CLEAR_EOCIC) || ((x) == ADC_INTR_CLEAR_STRIG_ERR_IC) ||         \
     ((x) == ADC_INTR_CLEAR_HPSTRIG_ERR_IC) || ((x) == ADC_INTR_CLEAR_NOVIC))

/** 模拟看门狗高低阈值 */
#define CHECK_ADC_AN_WATCH_DOG_THRESHOLD(x) (((x) >= 0U) && ((x) <= 0xFFFU))

/** 间隔模式通道计数 */
typedef enum
{
    ADC_DISC_NUMBER_1 = 0x0U,
    ADC_DISC_NUMBER_2,
    ADC_DISC_NUMBER_3,
    ADC_DISC_NUMBER_4,
    ADC_DISC_NUMBER_5,
    ADC_DISC_NUMBER_6,
    ADC_DISC_NUMBER_7,
    ADC_DISC_NUMBER_8,
} Adc_DiscNum_t;
#define CHECK_ADC_DISCNUM(x) (((x) >= ADC_DISC_NUMBER_1) && ((x) <= ADC_DISC_NUMBER_8))

/**  常规通道序列 */
typedef enum
{
    ADC_REGULAR_CH_0 = 0x0U,
    ADC_REGULAR_CH_1,
    ADC_REGULAR_CH_2,
    ADC_REGULAR_CH_3,
    ADC_REGULAR_CH_4,
    ADC_REGULAR_CH_5,
    ADC_REGULAR_CH_6,
    ADC_REGULAR_CH_7,
    ADC_REGULAR_CH_8,
    ADC_REGULAR_CH_9,
    ADC_REGULAR_CH_10,
    ADC_REGULAR_CH_11,
    ADC_REGULAR_CH_12,
    ADC_REGULAR_CH_13,
    ADC_REGULAR_CH_14,
    ADC_REGULAR_CH_15,
} Adc_RegularChannel_t;
#define CHECK_ADC_REGULARCHANNEL(x) (((x) >= ADC_REGULAR_CH_0) && ((x) <= ADC_REGULAR_CH_15))

/******************************************************************************
 *                      Export Variables
 ******************************************************************************/

/******************************************************************************
 *                      Export Functions
 ******************************************************************************/
/**
 * @brief 配置ADC工作使能.
 * @param Adcx: 指向ADC内存结构的指针
 *                  ADC0_PTR
 *                  ADC1_PTR
 * @param State:
 *          true   使能A/D 转换模块工作
 *          false   A/D 转换器关闭且不消耗工作电流
 * @retval void
 */
KF_INLINE void Adc_LL_SetEnabled(Adc_RegisterMap_t *Adcx, bool Enabled)
{
    KF_ADC_ASSERT(CHECK_ADC_ALL_PERIPH_ADDR(Adcx));

    Adcx->CTL0.bits.EN = Enabled ? 1U : 0U;
}

/**
 * @brief 配置A/D工作时钟源.
 * @param ADCx: 指向ADC内存结构的指针,取值为ADC0_PTR/ADC1_PTR.
 * @param ClockSource: ADC工作时钟源,取值范围为:
 *                      ADC_SCLK: 选用SCLK作为A/D数字模块工作时钟
 *                      ADC_HFCLK: 选用HFCLK作为A/D数字模块工作时钟
 *                      ADC_LFCLK: 选用LFCLK作为A/D数字模块工作时钟
 *                      ADC_PLL1: 选用PLL1作为A/D数字模块工作时钟
 * @retval void
 */
KF_INLINE void Adc_LL_SetClockSource(Adc_RegisterMap_t *const Adcx, Adc_Source_t ClockSource)
{
    KF_ADC_ASSERT(CHECK_ADC_ALL_PERIPH_ADDR(Adcx));
    KF_ADC_ASSERT(CHECK_ADC_SOURCE(ClockSource));

    Adcx->CTL0.bits.CLKS = (uint32_t)ClockSource;
}

/**
 * @brief 配置A/D转换结果输出格式.
 * @param ADCx: 指向ADC内存结构的指针,取值为ADC0_PTR/ADC1_PTR.
 * @param State:
 *          true   转换结果存储时右对齐
 *          false   转换结果存储时左对齐
 * @retval void
 */
KF_INLINE void Adc_LL_SetDataOutputFormat(Adc_RegisterMap_t *const Adcx, bool State)
{
    KF_ADC_ASSERT(CHECK_ADC_ALL_PERIPH_ADDR(Adcx));

    Adcx->CTL0.bits.LR = State ? 1U : 0U;
}

/**
 * @brief 配置A/D转换时钟挡位模式
 * @param ADCx: 指向ADC内存结构的指针,取值为ADC0_PTR/ADC1_PTR.
 * @param State:
 *          true   偶数分频挡位模式
 *          false   指数分频挡位模式
 * @retval void
 */
KF_INLINE void Adc_LL_SetAnalogClockMode(Adc_RegisterMap_t *const Adcx, bool State)
{
    KF_ADC_ASSERT(CHECK_ADC_ALL_PERIPH_ADDR(Adcx));

    Adcx->CTL0.bits.DIV_SEL = State ? 1U : 0U;
}

/**
 * @brief 配置ADC模拟部分时钟分频比选择.
 * @param ADCx: 指向ADC内存结构的指针,取值为ADC0_PTR/ADC1_PTR.
 * @param ClockSelect: ADC模拟部分时钟分频比,取值范围为:
 *                      指数分频档位模式：
 *                      ADC_CLK_DIV_2: T/2
 *                      ADC_CLK_DIV_4: 1/4T
 *                      ADC_CLK_DIV_8: 1/8T
 *                      ADC_CLK_DIV_16: 1/16T
 *                      ADC_CLK_DIV_32: 1/32T
 *                      ADC_CLK_DIV_64: 1/64T
 *                      偶数分频档位模式：
 *                      ADC_CLK_EVEN_DIV_2: T/2
 *                      ADC_CLK_EVEN_DIV_4: 1/4T
 *                      ADC_CLK_EVEN_DIV_6: 1/6T
 *                      ADC_CLK_EVEN_DIV_8: 1/8T
 *                      ADC_CLK_EVEN_DIV_10: 1/10T
 *                      ADC_CLK_EVEN_DIV_12: 1/12T
 *                      ADC_CLK_EVEN_DIV_14: 1/14T
 *                      ADC_CLK_EVEN_DIV_16: 1/16T
 *                      ADC_CLK_EVEN_DIV_32: 1/32T
 *                      ADC_CLK_EVEN_DIV_64: 1/64T
 * @retval void
 */
KF_INLINE void Adc_LL_SetAnalogClockDivision(Adc_RegisterMap_t *const Adcx, Adc_ClkDiv_t ClockDiv)
{
    KF_ADC_ASSERT(CHECK_ADC_ALL_PERIPH_ADDR(Adcx));
    KF_ADC_ASSERT(CHECK_ADC_CLKDIV(ClockDiv));

    Adcx->CTL0.bits.ADCCLKS = (uint32_t)ClockDiv;
}

/**
 * @brief 配置常规通道直接存储器访问模式使能.
 * @param ADCx: 指向ADC内存结构的指针,取值为ADC0_PTR/ADC1_PTR.
 * @param State:
 *          true   使用DMA模式
 *          false   不使用DMA模式
 * @retval void
 */
KF_INLINE void Adc_LL_SetRegularChannelDmaEnabled(Adc_RegisterMap_t *const Adcx, bool State)
{
    KF_ADC_ASSERT(CHECK_ADC_ALL_PERIPH_ADDR(Adcx));

    Adcx->CTL0.bits.NDMAEN = State ? 1U : 0U;
}

/**
 * @brief 配置偏置电流校准.
 * @param ADCx: 指向ADC内存结构的指针,取值为ADC0_PTR/ADC1_PTR.
 * @param State:
 *          true   校准,偏置电流变大
 *          false   不校准
 * @retval void
 */
KF_INLINE void Adc_LL_SetTrimCurrentIntensityBias(Adc_RegisterMap_t *const Adcx, bool State)
{
    KF_ADC_ASSERT(CHECK_ADC_ALL_PERIPH_ADDR(Adcx));

    Adcx->CTL0.bits.TRIMIBIAS = State ? 1U : 0U;
}

/**
 * @brief 配置参考电压二分之一运放电压校准.
 * @param ADCx: 指向ADC内存结构的指针,取值为ADC0_PTR/ADC1_PTR.
 * @param State:
 *          true   校准,运放输出电压更准确
 *          false   不校准
 * @retval void
 */
KF_INLINE void Adc_LL_SetBossselCalibration(Adc_RegisterMap_t *const Adcx, bool State)
{
    KF_ADC_ASSERT(CHECK_ADC_ALL_PERIPH_ADDR(Adcx));

    Adcx->CTL0.bits.BOSSSEL = State ? 1U : 0U;
}

/**
 * @brief 配置比较器的运放输入参考电压二分之一校准.
 * @param ADCx: 指向ADC内存结构的指针,取值为ADC0_PTR/ADC1_PTR.
 * @param State:
 *          true   校准,比较器输入端电压更准确
 *          false   不校准
 * @retval void
 */
KF_INLINE void Adc_LL_SetBossselComparatorCalibration(Adc_RegisterMap_t *const Adcx, bool State)
{
    KF_ADC_ASSERT(CHECK_ADC_ALL_PERIPH_ADDR(Adcx));

    Adcx->CTL0.bits.BOSSSELCOMP = State ? 1U : 0U;
}

/**
 * @brief 配置扫描模式使能.
 * @param ADCx: 指向ADC内存结构的指针,取值为ADC0_PTR/ADC1_PTR.
 * @param State:
 *          true   使能扫描模式
 *          false   禁止扫描模式
 * @retval void
 */
KF_INLINE void Adc_LL_SetScanModeEnabled(Adc_RegisterMap_t *Adcx, bool State)
{
    KF_ADC_ASSERT(CHECK_ADC_ALL_PERIPH_ADDR(Adcx));

    Adcx->CTL0.bits.SCANEN = State ? 1U : 0U;
}

/**
 * @brief 配置单次/连续模式.
 * @param ADCx: 指向ADC内存结构的指针,取值为ADC0_PTR/ADC1_PTR.
 * @param State:
 *          true   连续转换模式
 *          false   单次转换模式
 * @retval void
 */
KF_INLINE void Adc_LL_SetContinuousMode(Adc_RegisterMap_t *const Adcx, bool State)
{
    KF_ADC_ASSERT(CHECK_ADC_ALL_PERIPH_ADDR(Adcx));

    Adcx->CTL0.bits.CONT = State ? 1U : 0U;
}

/**
 * @brief 配置自动高优先级通道组转换使能.
 * @param ADCx: 指向ADC内存结构的指针,取值为ADC0_PTR/ADC1_PTR.
 * @param State:
 *          true   使能自动的高优先级通道转换
 *          false   禁止自动的高优先级通道转换
 * @retval void
 */
KF_INLINE void Adc_LL_SetHighPriorityAutoConversion(Adc_RegisterMap_t *Adcx, bool State)
{
    KF_ADC_ASSERT(CHECK_ADC_ALL_PERIPH_ADDR(Adcx));

    Adcx->CTL0.bits.HPAUTO = State ? 1U : 0U;
}

/**
 * @brief 配置常规通道上的间隔模式使能.
 * @param ADCx: 指向ADC内存结构的指针,取值为ADC0_PTR/ADC1_PTR.
 * @param State:
 *          true   使能常规通道上的间隔模式
 *          false   禁止常规通道上的间隔模式
 * @retval void
 */
KF_INLINE void Adc_LL_SetDiscModeEnabled(Adc_RegisterMap_t *const Adcx, bool State)
{
    KF_ADC_ASSERT(CHECK_ADC_ALL_PERIPH_ADDR(Adcx));

    Adcx->CTL0.bits.DSEN = State ? 1U : 0U;
}

/**
 * @brief 配置高优先级通道上的间隔模式使能.
 * @param ADCx: 指向ADC内存结构的指针,取值为ADC0_PTR/ADC1_PTR.
 * @param State:
 *          true   使能高优先级通道上的间隔模式
 *          false   禁止高优先级通道上的间隔模式
 * @retval void
 */
KF_INLINE void Adc_LL_SetHpDiscModeEnabled(Adc_RegisterMap_t *Adcx, bool State)
{
    KF_ADC_ASSERT(CHECK_ADC_ALL_PERIPH_ADDR(Adcx));

    Adcx->CTL0.bits.HPDSEN = State ? 1U : 0U;
}

/**
 * @brief 配置高优先级通道0DMA传输使能.
 * @param ADCx: 指向ADC内存结构的指针
 * @param State:
 *          true   使能高优先级DMA传输
 *          false   禁止高优先级DMA传输
 * @retval void
 */
KF_INLINE void Adc_LL_SetHighPriorityCh0DmaEnabled(Adc_RegisterMap_t *Adcx, bool State)
{
    KF_ADC_ASSERT(CHECK_ADC_ALL_PERIPH_ADDR(Adcx));

    Adcx->CTL0.bits.HP0DMAEN = State ? 1U : 0U;
}

/**
 * @brief 配置高优先级通道1DMA传输使能.
 * @param ADCx: 指向ADC内存结构的指针
 * @param State:
 *          true   使能高优先级DMA传输
 *          false   禁止高优先级DMA传输
 * @retval void
 */
KF_INLINE void Adc_LL_SetHighPriorityCh1DmaEnabled(Adc_RegisterMap_t *Adcx, bool State)
{
    KF_ADC_ASSERT(CHECK_ADC_ALL_PERIPH_ADDR(Adcx));

    Adcx->CTL0.bits.HP1DMAEN = State ? 1U : 0U;
}
/**
 * @brief 配置高优先级通道2DMA传输使能.
 * @param ADCx: 指向ADC内存结构的指针
 * @param State:
 *          true   使能高优先级DMA传输
 *          false   禁止高优先级DMA传输
 * @retval void
 */
KF_INLINE void Adc_LL_SetHighPriorityCh2DmaEnabled(Adc_RegisterMap_t *Adcx, bool State)
{
    KF_ADC_ASSERT(CHECK_ADC_ALL_PERIPH_ADDR(Adcx));

    Adcx->CTL0.bits.HP2DMAEN = State ? 1U : 0U;
}

/**
 * @brief 配置高优先级通道3DMA传输使能.
 * @param ADCx: 指向ADC内存结构的指针
 * @param State:
 *          true   使能高优先级DMA传输
 *          false   禁止高优先级DMA传输
 * @retval void
 */
KF_INLINE void Adc_LL_SetHighPriorityCh3DmaEnabled(Adc_RegisterMap_t *Adcx, bool State)
{
    KF_ADC_ASSERT(CHECK_ADC_ALL_PERIPH_ADDR(Adcx));

    Adcx->CTL0.bits.HP3DMAEN = State ? 1U : 0U;
}

/**
 * @brief 配置额外采样时间时钟分频模式.
 * @param ADCx: 指向ADC内存结构的指针
 * @param State:
 *          true   使用指数分频模式
 *          false   使用偶数分频模式
 * @retval void
 */
KF_INLINE void Adc_LL_SetExtraSamplingTimeClockDivisionMode(Adc_RegisterMap_t *Adcx, bool State)
{
    KF_ADC_ASSERT(CHECK_ADC_ALL_PERIPH_ADDR(Adcx));

    Adcx->CTL2.bits.ADCLK_SEL = State ? 1U : 0U;
}

/**
 * @brief 配置高优先级通道上的DMA传输使能.
 * @param ADCx: 指向ADC内存结构的指针,取值为ADC0_PTR/ADC1_PTR.
 * @param HPChannel: 取值为 Adc_HpChannel_t
 *                    ADC_HPCH_0
 *                    ADC_HPCH_1
 *                    ADC_HPCH_2
 *                    ADC_HPCH_3
 *                    ADC_HPCH_4
 *                    ADC_HPCH_5
 * @param State:
 *          true   使能高优先级通道上的DMA传输模式
 *          false   禁止高优先级通道上的DMA传输模式
 * @retval void
 */
KF_INLINE void Adc_LL_SetHpChannelDmaEnabled(Adc_RegisterMap_t *Adcx, Adc_HpChannel_t HpChannel, bool State)
{
    KF_ADC_ASSERT(CHECK_ADC_ALL_PERIPH_ADDR(Adcx));
    KF_ADC_ASSERT(CHECK_ADC_HPCHANNEL(HpChannel));
    if (HpChannel < ADC_HPCH_4)
    {
        REG_BITS_WRITE(
            Adcx->CTL0.reg, (1UL << ((uint32_t)HpChannel + 22U)), ((State ? 1UL : 0UL) << ((uint32_t)HpChannel + 22U)));
    }
    else
    {
        REG_BITS_WRITE(
            Adcx->CTL2.reg, (1UL << ((uint32_t)HpChannel - 4U)), ((State ? 1UL : 0UL) << ((uint32_t)HpChannel - 4U)));
    }
}

/**
 * @brief 配置间隔模式通道计数.
 * @param ADCx: 指向ADC内存结构的指针,取值为ADC0_PTR/ADC1_PTR.
 * @param Number: 间隔模式通道计数,取值范围为0~7.
 * @retval void
 */
KF_INLINE void Adc_LL_SetDiscModeChannelNumber(Adc_RegisterMap_t *const Adcx, Adc_DiscNum_t Number)
{
    KF_ADC_ASSERT(CHECK_ADC_ALL_PERIPH_ADDR(Adcx));
    KF_ADC_ASSERT(CHECK_ADC_DISCNUM(Number));

    Adcx->CTL0.bits.DSNUM = (uint32_t)Number;
}

/**
 * @brief 配置常规通道上看门狗使能.
 * @param ADCx: 指向ADC内存结构的指针
 * @param State:
 *          true   使能常规通道上模拟看门狗
 *          false   禁止常规通道上模拟看门狗
 * @retval void
 */
KF_INLINE void Adc_LL_SetRegularChannelWatchdogEnabled(Adc_RegisterMap_t *Adcx, bool State)
{
    KF_ADC_ASSERT(CHECK_ADC_ALL_PERIPH_ADDR(Adcx));

    Adcx->CTL0.bits.WDEN = State ? 1U : 0U;
}

/**
 * @brief 配置高优先级通道上看门狗使能.
 * @param ADCx: 指向ADC内存结构的指针,取值为ADC0_PTR/ADC1_PTR.
 * @param State:
 *          true   使能高优先级通道上模拟看门狗
 *          false   禁止高优先级通道上模拟看门狗
 * @retval void
 */
KF_INLINE void Adc_LL_SetHighPriorityWatchdogEnabled(Adc_RegisterMap_t *Adcx, bool State)
{
    KF_ADC_ASSERT(CHECK_ADC_ALL_PERIPH_ADDR(Adcx));

    Adcx->CTL0.bits.HPWDEN = State ? 1U : 0U;
}

/**
 * @brief 配置扫描模式中模拟看门狗单一通道使能.
 * @param ADCx: 指向ADC内存结构的指针,取值为ADC0_PTR/ADC1_PTR.
 * @param State:
 *          true   使能单一通道
 *          false   使能所有通道
 * @retval void
 */
KF_INLINE void Adc_LL_SetWatchdogSingleChannel(Adc_RegisterMap_t *Adcx, bool State)
{
    KF_ADC_ASSERT(CHECK_ADC_ALL_PERIPH_ADDR(Adcx));

    Adcx->CTL0.bits.WDSCH = State ? 1U : 0U;
}

/**
 * @brief 常规通道缓存溢出模式选择
 * @param Adcx: 指向ADC内存结构的指针
 * @param State:
 *          true   溢出后更新常规通道缓存
 *          false  溢出后不更新常规通道缓存
 * @retval void
 */
KF_INLINE void Adc_LL_SetUpdateBufferAfterOverflowEnabled(Adc_RegisterMap_t *Adcx, bool State)
{
    KF_ADC_ASSERT(CHECK_ADC_ALL_PERIPH_ADDR(Adcx));

    Adcx->CTL1.bits.NOVMODEN = (State ? 0UL : 1UL);
}

/**
 * @brief 设置转换规则通道标志位
 * @param Adcx: 指向ADC内存结构的指针
 * @param State:
 *          true   开始转换规则通道
 *          false   void作
 * @retval KF_INLINE
 */
KF_INLINE void Adc_LL_SetSoftwareConvStartState(Adc_RegisterMap_t *Adcx, bool State)
{
    KF_ADC_ASSERT(CHECK_ADC_ALL_PERIPH_ADDR(Adcx));

    Adcx->CTL1.bits.START = State ? 1U : 0U;
    /* Mantis #2809 */
    if (State)
    {
        NOP();
        NOP();
        Adcx->CTL1.bits.START = 0U;
    }
}

/**
 * @brief 软件启动A/D常规通道转换
 * @param Adcx: 指向ADC内存结构的指针
 * @retval KF_INLINE
 */
KF_INLINE void Adc_LL_StartSoftwareConv(Adc_RegisterMap_t *Adcx)
{
    KF_ADC_ASSERT(CHECK_ADC_ALL_PERIPH_ADDR(Adcx));

    Adc_LL_SetSoftwareConvStartState(Adcx, true);
}

/**
 * @brief 设置转换高优先通道标志位
 * @param ADCx: 指向ADC内存结构的指针,取值为ADC0_PTR/ADC1_PTR.
 * @param State:
 *          true   开始转换高优先级通道
 *          false   void作
 * @retval void
 */
KF_INLINE void Adc_LL_SetSoftwareHpConvStartState(Adc_RegisterMap_t *Adcx, bool State)
{
    KF_ADC_ASSERT(CHECK_ADC_ALL_PERIPH_ADDR(Adcx));

    Adcx->CTL1.bits.HPSTART = State ? 1U : 0U;
    /* Mantis #2809 */
    if (State)
    {
        NOP();
        NOP();
        Adcx->CTL1.bits.HPSTART = 0U;
    }
}

/**
 * @brief 软件启动A/D高优先级通通道转换
 * @param Adcx: 指向ADC内存结构的指针
 * @retval KF_INLINE
 */
KF_INLINE void Adc_LL_StartHpSoftwareConv(Adc_RegisterMap_t *Adcx)
{
    KF_ADC_ASSERT(CHECK_ADC_ALL_PERIPH_ADDR(Adcx));

    Adc_LL_SetSoftwareHpConvStartState(Adcx, true);
}

/**
 * @brief 配置常规通道外部触发事件.
 * @param ADCx: 指向ADC内存结构的指针,取值为ADC0_PTR/ADC1_PTR.
 * @param ExternalTrigEvent: 常规通道外部触发事件选择,取值为
 *                  Adc_ExternalTrig_t
 *
 * @retval void
 */
KF_INLINE void Adc_LL_SetExternalTrigEvent(Adc_RegisterMap_t *const Adcx, Adc_ExternalTrig_t ExternalTrigEvent)
{
    KF_ADC_ASSERT(CHECK_ADC_ALL_PERIPH_ADDR(Adcx));
    KF_ADC_ASSERT(CHECK_ADC_EXTERNALTRIG(ExternalTrigEvent));

    Adcx->CTL1.bits.NCH = (uint32_t)ExternalTrigEvent;
}

/**
 * @brief 配置常规通道外部触发转换模式使能.
 * @param ADCx: 指向ADC内存结构的指针,取值为ADC0_PTR/ADC1_PTR.
 * @param State:
 *          true   使能外部事件触发转换
 *          false   禁止外部事件触发转换
 * @retval void
 */
KF_INLINE void Adc_LL_SetExternalTrigConvEnabled(Adc_RegisterMap_t *Adcx, bool State)
{
    KF_ADC_ASSERT(CHECK_ADC_ALL_PERIPH_ADDR(Adcx));

    Adcx->CTL1.bits.EXTEN = State ? 1U : 0U;
}

/**
 * @brief 配置ADC参考电压选择.
 * @param ADCx: 指向ADC内存结构的指针,取值为ADC0_PTR/ADC1_PTR.
 * @param RefVoltage: ADC_REF_VOL_t
 *              ADC_REF_VOL_NONE
 *              ADC_REF_VOL_VDDA
 *              ADC_REF_VOL_FVR1
 *              ADC_REF_VOL_VREF
 *              ADC_REF_VOL_FVR
 * @retval void
 */
KF_INLINE void Adc_LL_SetReferenceVoltage(Adc_RegisterMap_t *const Adcx, Adc_RefVol_t RefVoltage)
{
    KF_ADC_ASSERT(CHECK_ADC_ALL_PERIPH_ADDR(Adcx));
    KF_ADC_ASSERT(CHECK_ADC_REFVOL(RefVoltage));

    Adcx->CTL1.bits.REFSEL = (uint32_t)RefVoltage;
}

/**
 * @brief 配置高优先级通道外部触发事件.
 * @param ADCx: 指向ADC内存结构的指针,取值为ADC0_PTR/ADC1_PTR.
 * @param HPExternalTrigEvent: 高优先级通道外部触发事件选择,取值为:
 *                           ADC_HPEXTERNALTRIG_t
 *
 * @retval void
 */
KF_INLINE void
Adc_LL_SetHPExternalTrigConvEvent(Adc_RegisterMap_t *const Adcx, Adc_HpExternalTrig_t HPExternalTrigEvent)
{
    KF_ADC_ASSERT(CHECK_ADC_ALL_PERIPH_ADDR(Adcx));
    KF_ADC_ASSERT(CHECK_ADC_HPEXTERNALTRIG(HPExternalTrigEvent));

    Adcx->CTL1.bits.HCH = (uint32_t)HPExternalTrigEvent;
}

/**
 * @brief 配置高优先级通道外部触发转换模式使能.
 * @param ADCx: 指向ADC内存结构的指针,取值为ADC0_PTR/ADC1_PTR.
 * @param State:
 *          true   使能外部事件触发转换
 *          false   禁止外部事件触发转换
 * @retval void
 */
KF_INLINE void Adc_LL_SetHPExternalTrigConvEnabled(Adc_RegisterMap_t *Adcx, bool State)
{
    KF_ADC_ASSERT(CHECK_ADC_ALL_PERIPH_ADDR(Adcx));

    Adcx->CTL1.bits.HPEXTEN = State ? 1U : 0U;
}

/**
 * @brief 配置常规通道扫描序列.
 * @param ADCx: 指向ADC内存结构的指针,取值为ADC0_PTR/ADC1_PTR.
 * @param Channel: ADC通道选择,取值范围为:
 *                  ADC_CHANNEL_0    通道0
 *                     .....
 *                  ADC_CHANNEL_127  通道127
 * @param ScanOffset: 常规通道扫描AD输入的转换位置,取值为Adc_RegularChannel_t.
 * @retval void
 */
KF_INLINE void
Adc_LL_SetRegularScanChannel(Adc_RegisterMap_t *const Adcx, Adc_Channel_t Channel, Adc_RegularChannel_t ScanOffset)
{
    KF_ADC_ASSERT(CHECK_ADC_ALL_PERIPH_ADDR(Adcx));
    KF_ADC_ASSERT(CHECK_ADC_CHANNEL(Channel));
    KF_ADC_ASSERT(CHECK_ADC_REGULARCHANNEL(ScanOffset));

    uint32_t kvTmpReg  = 0U;
    uint32_t kvTmpMask = 0U;

    switch (ScanOffset)
    {
    case ADC_REGULAR_CH_0:
    case ADC_REGULAR_CH_1:
    case ADC_REGULAR_CH_2:
    case ADC_REGULAR_CH_3:
        kvTmpReg  = (uint32_t)Channel << (8U * (uint32_t)ScanOffset);
        kvTmpMask = 0xFFUL << (8U * (uint32_t)ScanOffset);
        REG_BITS_WRITE(Adcx->SCANSQ0.reg, kvTmpMask, kvTmpReg);
        break;
    case ADC_REGULAR_CH_4:
    case ADC_REGULAR_CH_5:
    case ADC_REGULAR_CH_6:
    case ADC_REGULAR_CH_7:
        kvTmpReg  = (uint32_t)Channel << (8U * ((uint32_t)ScanOffset - 4U));
        kvTmpMask = 0xFFUL << (8U * ((uint32_t)ScanOffset - 4U));
        REG_BITS_WRITE(Adcx->SCANSQ1.reg, kvTmpMask, kvTmpReg);
        break;
    case ADC_REGULAR_CH_8:
    case ADC_REGULAR_CH_9:
    case ADC_REGULAR_CH_10:
    case ADC_REGULAR_CH_11:
        kvTmpReg  = (uint32_t)Channel << (8U * ((uint32_t)ScanOffset - 8U));
        kvTmpMask = 0xFFUL << (8U * ((uint32_t)ScanOffset - 8U));
        REG_BITS_WRITE(Adcx->SCANSQ2.reg, kvTmpMask, kvTmpReg);
        break;
    case ADC_REGULAR_CH_12:
    case ADC_REGULAR_CH_13:
    case ADC_REGULAR_CH_14:
    case ADC_REGULAR_CH_15:
        kvTmpReg  = (uint32_t)Channel << (8U * ((uint32_t)ScanOffset - 12U));
        kvTmpMask = 0xFFUL << (8U * ((uint32_t)ScanOffset - 12U));
        REG_BITS_WRITE(Adcx->SCANSQ3.reg, kvTmpMask, kvTmpReg);
        break;
    default:
        (void)0U;
        break;
    }
}

/**
 * @brief 配置高优先级通道扫描序列.
 * @param ADCx: 指向ADC内存结构的指针,取值为ADC0_PTR/ADC1_PTR.
 * @param Channel: ADC通道选择,取值范围为:
 *                  ADC_CHANNEL_0    通道0
 *                     .....
 *                  ADC_CHANNEL_127  通道127
 * @param HPChannel: 取值为 Adc_HpChannel_t
 *                  ADC_HPCH_0
 *                  ADC_HPCH_1
 *                  ADC_HPCH_2
 *                  ADC_HPCH_3
 *                  ADC_HPCH_4
 *                  ADC_HPCH_5
 * @retval void
 */
KF_INLINE void
Adc_LL_SetHighPriorityScanChannel(Adc_RegisterMap_t *const Adcx, Adc_Channel_t Channel, Adc_HpChannel_t ScanOffset)
{
    KF_ADC_ASSERT(CHECK_ADC_ALL_PERIPH_ADDR(Adcx));
    KF_ADC_ASSERT(CHECK_ADC_CHANNEL(Channel));
    KF_ADC_ASSERT(CHECK_ADC_HPCHANNEL(ScanOffset));

    uint32_t kvTmpReg  = 0U;
    uint32_t kvTmpMask = 0U;
    if (ScanOffset < ADC_HPCH_4)
    {
        /* 配置第1次转换~第4次转换 */
        kvTmpReg  = (uint32_t)Channel << (8U * (uint32_t)ScanOffset);
        kvTmpMask = 0xFFUL << (8U * (uint32_t)ScanOffset);
        REG_BITS_WRITE(Adcx->HSCANSQ.reg, kvTmpMask, kvTmpReg);
    }
    else
    {
        /* 配置第5次转换~第6次转换 */
        uint32_t tmpScanOffset = (uint32_t)ScanOffset;
        tmpScanOffset -= (uint32_t)ADC_HPCH_4;
        kvTmpReg  = (uint32_t)Channel << (8U * (uint32_t)tmpScanOffset);
        kvTmpMask = 0xFFUL << (8U * tmpScanOffset);
        REG_BITS_WRITE(Adcx->HSCANSQ1.reg, kvTmpMask, kvTmpReg);
    }
}

/**
 * @brief 配置模拟看门狗高阈值寄存器
 * @param ADCx: 指向ADC内存结构的指针,取值为ADC0_PTR/ADC1_PTR.
 * @param HighValue: 模拟看门狗高阈值设置值
 * @retval void
 */
KF_INLINE void Adc_LL_SetWatchDogThresholdHighValue(Adc_RegisterMap_t *const Adcx, uint16_t HighValue)
{
    KF_ADC_ASSERT(CHECK_ADC_ALL_PERIPH_ADDR(Adcx));
    KF_ADC_ASSERT(CHECK_ADC_AN_WATCH_DOG_THRESHOLD(HighValue));

    Adcx->WDH.bits.WDH = HighValue;
}

/**
 * @brief 配置模拟看门狗低阈值寄存器
 * @param ADCx: 指向ADC内存结构的指针,取值为ADC0_PTR/ADC1_PTR.
 * @param HighValue: 模拟看门狗高阈值设置值
 * @retval void
 */
KF_INLINE void Adc_LL_SetWatchDogThresholdLowValue(Adc_RegisterMap_t *const Adcx, uint16_t LowValue)
{
    KF_ADC_ASSERT(CHECK_ADC_ALL_PERIPH_ADDR(Adcx));
    KF_ADC_ASSERT(CHECK_ADC_AN_WATCH_DOG_THRESHOLD(LowValue));

    Adcx->WDL.bits.WDL = LowValue;
}

/**
 * @brief 获取常规通道转换结果数据.
 * @param ADCx: 指向ADC内存结构的指针,取值为ADC0_PTR/ADC1_PTR.
 * @retval uint16_t 常规通道转换结果数据,16位有效数据.
 */
KF_INLINE uint16_t Adc_LL_GetRegularChannelConversionData(const Adc_RegisterMap_t *const Adcx)
{
    KF_ADC_ASSERT(CHECK_ADC_ALL_PERIPH_ADDR(Adcx));

    return (uint16_t)Adcx->DATA.bits.DATA;
}

/**
 * @brief 获取高优先级通道转换结果数据.
 * @param ADCx: 指向ADC内存结构的指针,取值为ADC0_PTR/ADC1_PTR.
 * @param HPChannel: 高优先级通道选择,取值为:
 *                        ADC_HPCH_0: 高优先级通道0
 *                        ADC_HPCH_1: 高优先级通道1
 *                        ADC_HPCH_2: 高优先级通道2
 *                        ADC_HPCH_3: 高优先级通道3
 *                        ADC_HPCH_4: 高优先级通道4
 *                        ADC_HPCH_5: 高优先级通道5
 * @retval 高优先级通道转换结果数据,16位有效数据.
 */
KF_INLINE uint16_t
Adc_LL_GetHighPrioChannelConversionData(const Adc_RegisterMap_t *const Adcx, Adc_HpChannel_t HpChannel)
{
    uint16_t kvTmpValue = 0U;

    switch (HpChannel)
    {
    case ADC_HPCH_0:
        kvTmpValue = (uint16_t)Adcx->HPDATA0.bits.HPDATA;
        break;
    case ADC_HPCH_1:
        kvTmpValue = (uint16_t)Adcx->HPDATA1.bits.HPDATA;
        break;
    case ADC_HPCH_2:
        kvTmpValue = (uint16_t)Adcx->HPDATA2.bits.HPDATA;
        break;
    case ADC_HPCH_3:
        kvTmpValue = (uint16_t)Adcx->HPDATA3.bits.HPDATA;
        break;
    case ADC_HPCH_4:
        kvTmpValue = (uint16_t)Adcx->HPDATA4.bits.HPDATA;
        break;
    case ADC_HPCH_5:
        kvTmpValue = (uint16_t)Adcx->HPDATA5.bits.HPDATA;
        break;

    default:
        KF_ADC_ASSERT(false);
        break;
    }
    return kvTmpValue;
}

/**
 * @brief  高优先级通道0/1/2/3 转换结果数据偏移
 * @param  Adcx: 指向ADC内存结构的指针,取值为ADC0_PTR/ADC1_PTR.
 * @param  HPChannel: 高优先级通道选择,取值为:
 *                        ADC_HPCH_0: 高优先级通道0
 *                        ADC_HPCH_1: 高优先级通道1
 *                        ADC_HPCH_2: 高优先级通道2
 *                        ADC_HPCH_3: 高优先级通道3
 *                        ADC_HPCH_4: 高优先级通道4
 *                        ADC_HPCH_5: 高优先级通道5
 * @param   Value:        Value <= 0xFFF
 * @retval  void
 */
KF_INLINE void Adc_LL_SetHpConversionDisorder(Adc_RegisterMap_t *Adcx, Adc_HpChannel_t HpChannel, uint16_t Value)
{

    switch (HpChannel)
    {
    case ADC_HPCH_0:
        Adcx->HPDOFF0.bits.HPDOFF = Value;
        break;
    case ADC_HPCH_1:
        Adcx->HPDOFF1.bits.HPDOFF = Value;
        break;
    case ADC_HPCH_2:
        Adcx->HPDOFF2.bits.HPDOFF = Value;
        break;
    case ADC_HPCH_3:
        Adcx->HPDOFF3.bits.HPDOFF = Value;
        break;
    case ADC_HPCH_4:
        Adcx->HPDOFF4.bits.HPDOFF = Value;
        break;
    case ADC_HPCH_5:
        Adcx->HPDOFF5.bits.HPDOFF = Value;
        break;

    default:
        KF_ADC_ASSERT(false);
        break;
    }
}

/**
 * @brief 配置常规通道扫描长度.
 * @param ADCx: 指向ADC内存结构的指针,取值为ADC0_PTR/ADC1_PTR.
 * @param Length: 常规通道扫描长度,取值为0~15.
 * @retval void
 */
KF_INLINE void Adc_LL_SetRegularSequencerLength(Adc_RegisterMap_t *const Adcx, uint32_t Length)
{
    KF_ADC_ASSERT(CHECK_ADC_ALL_PERIPH_ADDR(Adcx));
    KF_ADC_ASSERT(CHECK_ADC_REGULAR_LENGTH(Length));

    Adcx->SCANCTL.bits.SLEN = Length;
}

/**
 * @brief 获取常规通道溢出时的转换通道号.
 * @param ADCx: 指向ADC内存结构的指针,取值为ADC0_PTR/ADC1_PTR.
 * @retval Adc_RegularChannel_t 常规通道溢出时的转换通道号.
 */
KF_INLINE Adc_RegularChannel_t Adc_LL_GetOverflowChannelIndex(const Adc_RegisterMap_t *const Adcx)
{
    KF_ADC_ASSERT(CHECK_ADC_ALL_PERIPH_ADDR(Adcx));
    uint32_t tmpChannel = Adcx->SCANCTL.bits.NCHNUB & (uint32_t)0xFU;

    return (Adc_RegularChannel_t)tmpChannel;
}

/**
 * @brief 配置高优先级通道扫描长度.
 * @param ADCx: 指向ADC内存结构的指针,取值为ADC0_PTR/ADC1_PTR.
 * @param Length: 高优先级通道扫描长度,取值范围为0~5.
 * @retval void
 */
KF_INLINE void Adc_LL_SetHighPrioritySequencerLength(Adc_RegisterMap_t *const Adcx, uint32_t Length)
{
    KF_ADC_ASSERT(CHECK_ADC_ALL_PERIPH_ADDR(Adcx));
    KF_ADC_ASSERT(CHECK_ADC_HIGH_PRIORITY_LENGTH(Length));

    Adcx->SCANCTL.bits.HSLEN = Length;
}

/**
 * @brief 配置ADC模拟看门狗通道选择.
 * @param ADCx: 指向ADC内存结构的指针,取值为ADC0_PTR/ADC1_PTR.
 * @param  Channel: ADC模拟看门狗通道,取值
 *                    0 : ADC_CHANNEL_0
 *                    1 : ADC_CHANNEL_1
 *                    ...
 *                    0x7F : ADC_CHANNEL_127
 * @retval void
 */
KF_INLINE void Adc_LL_SetAnalogWatchdogChannel(Adc_RegisterMap_t *const Adcx, Adc_Channel_t Channel)
{
    KF_ADC_ASSERT(CHECK_ADC_ALL_PERIPH_ADDR(Adcx));
    KF_ADC_ASSERT(CHECK_ADC_CHANNEL(Channel));

    Adcx->SCANCTL.bits.WDCH = (uint32_t)Channel;
}

/**
 * @brief 配置ADC额外采样时间.
 * @param ADCx: 指向ADC内存结构的指针,取值为ADC0_PTR/ADC1_PTR.
 * @param ExTime: ADC额外采样时间,取值为:
 *                   ADC_EXTRA_TIME_0
 *                   ADC_EXTRA_TIME_0P5
 *                   ADC_EXTRA_TIME_1
 *                   ADC_EXTRA_TIME_2
 *                   ADC_EXTRA_TIME_4
 *                   ADC_EXTRA_TIME_8
 *                   ADC_EXTRA_TIME_16
 *                   ADC_EXTRA_TIME_32
 *                   ADC_EXTRA_TIME_64
 *                   ADC_EXTRA_TIME_128
 *                   ADC_EXTRA_TIME_256
 * @retval void
 */
KF_INLINE void Adc_LL_SetExtraSamplingTime(Adc_RegisterMap_t *const Adcx, Adc_ExtraTime_t ExTime)
{
    KF_ADC_ASSERT(CHECK_ADC_ALL_PERIPH_ADDR(Adcx));
    KF_ADC_ASSERT(CHECK_ADC_EXTRATIME(ExTime));

    Adcx->SCANCTL.bits.SAMSEL = (uint32_t)ExTime;
}

/**
 * @brief 配置通道CCR触发事件使能.
 * @param ADCx: 指向ADC内存结构的指针,取值为ADC0_PTR/ADC1_PTR
 * @param CCRTrigEvent: CCR触发事件选择,取值为:
 *              ADC_EXTERNTRIG_T5_CCR0   :T5_CCR0触发常规通道
 *              ADC_EXTERNTRIG_T5_CCR1   :T5_CCR1触发常规通道
 *              ADC_EXTERNTRIG_T6_CCR0   :T6_CCR0触发常规通道
 *              ADC_EXTERNTRIG_T9_CCR0   :T9_CCR0触发常规通道
 *              ADC_EXTERNTRIG_T9_CCR1   :T9_CCR1触发常规通道
 *              ADC_EXTERNTRIG_T10_CCR0  :T10_CCR0触发常规通道
 *              ADC_EXTERNTRIG_T25_CCR0  :T25_CCR0触发常规通道
 *              ADC_EXTERNTRIG_T25_CCR1  :T25_CCR1触发常规通道
 *              ADC_EXTERNTRIG_T26_CCR0  :T26_CCR0触发常规通道
 *              ADC_HPEXTERNTRIG_T5_CCR0 :T5_CCR0触发高优先级通道
 *              ADC_HPEXTERNTRIG_T5_CCR1 :T5_CCR1触发高优先级通道
 *              ADC_HPEXTERNTRIG_T6_CCR0 :T6_CCR0触发高优先级通道
 *              ADC_HPEXTERNTRIG_T9_CCR0 :T9_CCR0触发高优先级通道
 *              ADC_HPEXTERNTRIG_T9_CCR1 :T9_CCR1触发高优先级通道
 *              ADC_HPEXTERNTRIG_T10_CCR0:T10_CCR0触发高优先级通道
 *              ADC_HPEXTERNTRIG_T25_CCR0:T25_CCR0触发高优先级通道
 *              ADC_HPEXTERNTRIG_T25_CCR1:T25_CCR1触发高优先级通道
 *              ADC_HPEXTERNTRIG_T26_CCR0:T26_CCR0触发高优先级通道
 * @param State:
 *          true   高优先级通道触发使能打开
 *          false   高优先级通道触发使能关闭
 * @retval void
 */
KF_INLINE void Adc_LL_SetCcrTrigConvEnabled(Adc_RegisterMap_t *const Adcx, Adc_CcrTrig_t CcrTrigEventIdx, bool State)
{
    KF_ADC_ASSERT(CHECK_ADC_ALL_PERIPH_ADDR(Adcx));
    KF_ADC_ASSERT(CHECK_ADC_CCRTRIG(CcrTrigEventIdx));

    REG_BITS_WRITE(
        Adcx->CCR.reg, (0x1UL << (uint32_t)CcrTrigEventIdx), ((State ? 1UL : 0UL) << (uint32_t)CcrTrigEventIdx));
}

/**
 * @brief 配置ADC中断使能.
 * @param ADCx: 指向ADC内存结构的指针,取值为ADC0_PTR/ADC1_PTR.
 * @param InterruptType: ADC中断类型,取值为 Adc_IntrSetIndex_t
 * @param State:
 *          true   使能中断
 *          false   禁止中断
 * @retval void
 */
KF_INLINE void Adc_LL_SetIntrEnabled(Adc_RegisterMap_t *const Adcx, Adc_IntrSetIndex_t InterruptType, bool State)
{
    KF_ADC_ASSERT(CHECK_ADC_ALL_PERIPH_ADDR(Adcx));
    KF_ADC_ASSERT(CHECK_ADC_INTRSETINDEX(InterruptType));

    if ((uint32_t)InterruptType < 0x100U)
    {
        REG_BITS_WRITE(
            Adcx->STATE.reg, (0x1UL << (uint32_t)InterruptType), ((State ? 1UL : 0UL) << (uint32_t)InterruptType));
    }
    else
    {
        uint32_t regBit = (uint32_t)InterruptType - 0x100U;
        REG_BITS_WRITE(Adcx->CTL1.reg, (0x1UL << regBit), ((State ? 1UL : 0UL) << regBit));
    }
}

/**
 * @brief 获取ADC中断使能状态.
 * @param ADCx: 指向ADC内存结构的指针.
 * @param InterruptType: ADC中断类型,取值为 Adc_IntrSetIndex_t
 * @return bool
 */
KF_INLINE bool Adc_LL_GetIntrEnabledState(const Adc_RegisterMap_t *const Adcx, Adc_IntrSetIndex_t InterruptType)
{
    KF_ADC_ASSERT(CHECK_ADC_ALL_PERIPH_ADDR(Adcx));
    KF_ADC_ASSERT(CHECK_ADC_INTRSETINDEX(InterruptType));

    bool ret = false;

    if ((uint32_t)InterruptType < 0x100U)
    {
        /* PRQA S 3469 1 #KQR003469 */
        ret = REG_BIT_BOOLED(Adcx->STATE.reg, (0x1UL << (uint32_t)InterruptType));
    }
    else
    {
        uint32_t regBit = (uint32_t)InterruptType - 0x100U;
        /* PRQA S 3469 1 #KQR003469 */
        ret = REG_BIT_BOOLED(Adcx->CTL1.reg, (0x1UL << regBit));
    }

    return ret;
}

/**
 * @brief 获取ADC中断标志.
 * @param ADCx: 指向ADC内存结构的指针,取值为ADC0_PTR/ADC1_PTR.
 * @param InterruptType: ADC中断类型,取值为 Adc_IntrGetIndex_t
 * @retval bool:
 *         true    发生了中断
 *         false    未发生中断
 */
KF_INLINE bool Adc_LL_GetIntrFlag(const Adc_RegisterMap_t *const Adcx, Adc_IntrGetIndex_t InterruptType)
{
    KF_ADC_ASSERT(CHECK_ADC_ALL_PERIPH_ADDR(Adcx));
    KF_ADC_ASSERT(CHECK_ADC_INTRGETINDEX(InterruptType));

    bool ret = false;

    if ((uint32_t)InterruptType < 0x100U)
    {
        /* PRQA S 3469 1 #KQR003469 */
        ret = REG_BIT_BOOLED(Adcx->STATE.reg, (0x1UL << (uint32_t)InterruptType));
    }
    else
    {
        uint32_t regBit = (uint32_t)InterruptType - 0x100U;
        /* PRQA S 3469 1 #KQR003469 */
        ret = REG_BIT_BOOLED(Adcx->CTL1.reg, (0x1UL << regBit));
    }

    return ret;
}

/**
 * @brief 清除ADC中断标志.
 * @param ADCx: 指向ADC内存结构的指针,取值为ADC0_PTR/ADC1_PTR.
 * @param InterruptType: ADC中断类型,取值为 Adc_IntrClearIndex_t
 * @retval void
 */
KF_INLINE void Adc_LL_ClearIntrFlag(Adc_RegisterMap_t *const Adcx, Adc_IntrClearIndex_t InterruptType)
{
    KF_ADC_ASSERT(CHECK_ADC_ALL_PERIPH_ADDR(Adcx));
    KF_ADC_ASSERT(CHECK_ADC_INTRCLEARINDEX(InterruptType));

    if ((uint32_t)InterruptType < 0x100U)
    {
        REG_BIT_SET(Adcx->STATE.reg, (1UL << (uint32_t)InterruptType));
        NOP();
        NOP();
        NOP();
        NOP();
        REG_BIT_CLR(Adcx->STATE.reg, (1UL << (uint32_t)InterruptType));
    }
    else
    {
        uint32_t regBit = (uint32_t)InterruptType - 0x100U;

        REG_BIT_SET(Adcx->CTL1.reg, (1UL << regBit));
        NOP();
        NOP();
        NOP();
        NOP();
        REG_BIT_CLR(Adcx->CTL1.reg, (1UL << regBit));
    }
}

/**
 * @brief 清除ADC中断标志.
 * @param ADCx: 指向ADC内存结构的指针,取值为ADC0_PTR/ADC1_PTR.
 * @param InterruptType: ADC中断类型掩码,取值为 Adc_IntrMaskClearIndex_t
 * @retval void
 */
KF_INLINE void Adc_LL_ClearMaskIntrFlag(Adc_RegisterMap_t *const Adcx, uint32_t InterruptMask)
{
    KF_ADC_ASSERT(CHECK_ADC_ALL_PERIPH_ADDR(Adcx));
    KF_ADC_ASSERT(CHECK_ADC_INTRMASKCLEARINDEX(InterruptMask));

    REG_BIT_SET(Adcx->STATE.reg, (uint32_t)InterruptMask);
    NOP();
    NOP();
    NOP();
    NOP();
    REG_BIT_CLR(Adcx->STATE.reg, (uint32_t)InterruptMask);
}

/**
 * @brief: 获取常规通道组转换开始状态
 * @param Adcx      指向ADC内存结构的指针
 * @retval true      常规通道组转换已开始
 * @retval false      常规通道组转换未开始
 */
KF_INLINE bool Adc_LL_GetStartState(const Adc_RegisterMap_t *Adcx)
{
    KF_ADC_ASSERT(CHECK_ADC_ALL_PERIPH_ADDR(Adcx));

    return Adcx->STATE.bits.STARTIF != 0U;
}

/**
 * @brief: 获取高优先通道组转换开始状态
 * @param Adcx      指向ADC内存结构的指针
 * @retval true      高优先通道组转换已开始
 * @retval false      高优先通道组转换未开始
 */
KF_INLINE bool Adc_LL_GetHpStartState(const Adc_RegisterMap_t *Adcx)
{
    KF_ADC_ASSERT(CHECK_ADC_ALL_PERIPH_ADDR(Adcx));

    return Adcx->STATE.bits.HPSTARTIF != 0U;
}

/**
 * @brief 配置模拟运放输出级驱动调节档.
 * @param ADCx: 指向ADC内存结构的指针
 * @param State:
 *          true   打开
 *          false   关闭
 * @retval void
 */
KF_INLINE void Adc_LL_SetAnalogOutputLevelDriveAdjustment(Adc_RegisterMap_t *Adcx, bool State)
{
    KF_ADC_ASSERT(CHECK_ADC_ALL_PERIPH_ADDR(Adcx));

    Adcx->STATE.bits.TRIMIBIASOPA = State ? 1U : 0U;
}

/**
 * @brief 配置增加正offset调节位.
 * @param ADCx: 指向ADC内存结构的指针
 * @param Trim: TRIMERROR调节值 (0~3)
 * @retval void
 */
KF_INLINE void Adc_LL_SetPositiveOffsetAdjustment(Adc_RegisterMap_t *Adcx, uint32_t Trim)
{
    KF_ADC_ASSERT(CHECK_ADC_ALL_PERIPH_ADDR(Adcx));

    Adcx->STATE.bits.TRIMERROR = Trim & 0x3U;
}

/**
 * @brief 获取ADC中断发生状态.
 * @param ADCx: 指向ADC内存结构的指针,取值为ADC_SFR.
 * @param InterruptType: ADC中断类型,取值为 Adc_IntrGetIndex_t
 * @retval bool 中断发生状态
 *         true    发生了中断，且已使能
 *         false    未发生中断，或未使能
 */
KF_INLINE bool Adc_LL_GetIntrState(const Adc_RegisterMap_t *const Adcx, Adc_IntrGetIndex_t InterruptType)
{
    KF_ADC_ASSERT(CHECK_ADC_ALL_PERIPH_ADDR(Adcx));
    KF_ADC_ASSERT(CHECK_ADC_INTRGETINDEX(InterruptType));

    bool     flag  = Adc_LL_GetIntrFlag(Adcx, InterruptType);
    bool     state = false;
    uint32_t tmpIndex;
    if ((InterruptType <= ADC_INTR_GET_HPSTARTIF) || (InterruptType == ADC_INTR_GET_STRIG_ERR_IF) ||
        (InterruptType == ADC_INTR_GET_HPSTRIG_ERR_IF))
    {
        state = true;
    }
    else if (InterruptType <= ADC_INTR_GET_WDIF)
    {
        tmpIndex = ((uint32_t)InterruptType + (uint32_t)ADC_INTR_SET_ENDIE - (uint32_t)ADC_INTR_GET_ENDIF);
        state    = Adc_LL_GetIntrEnabledState(Adcx, (Adc_IntrSetIndex_t)tmpIndex);
    }
    else if (InterruptType == ADC_INTR_GET_EOCIF)
    {
        state = Adc_LL_GetIntrEnabledState(Adcx, ADC_INTR_SET_EOCIE);
    }
    else if (InterruptType == ADC_INTR_GET_NOVIF)
    {
        state = Adc_LL_GetIntrEnabledState(Adcx, ADC_INTR_SET_NOVIE);
    }
    else
    {
        /* do nothing */
    }

    return flag && state;
}

#ifdef __cplusplus
}
#endif /*End of __cplusplus*/
#endif /*End of KF32A158SF_DRV_ADC_H*/
/* EOF */
