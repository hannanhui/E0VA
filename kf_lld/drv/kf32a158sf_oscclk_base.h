/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name        : kf32a158sf_oscclk_base.h
 *  @Date             : 2025-07-07
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
 *  |2025-07-07  |V1.0     |AE Group     |New create
 ******************************************************************************/
#ifndef KF32A158SF_OSCCLK_BASE_H
#define KF32A158SF_OSCCLK_BASE_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 *                      QAC Warnings
 ******************************************************************************/

/******************************************************************************
 *                      Include Files
 ******************************************************************************/
#include <stdint.h>
#include <stdbool.h>
#include "kf_types.h"
/******************************************************************************
 *                      Macro or Inline
 ******************************************************************************/
/* In the following line define the common clock frequency values */
#define BASE_FREQ_1KHz     1000U                 /* !<  frequency  1k > */
#define BASE_FREQ_1MHz     1000000U              /* !<  frequency  1M > */
#define INTHF_FREQ_16MHz   (16 * BASE_FREQ_1MHz) /* !< INTHF frequency is 16M > */
#define INTLF_FREQ_32KHz   (32 * BASE_FREQ_1KHz) /* !< INTLF frequency is 32K > */
#define EXTLF_FREQ_32768Hz 32768U                /* !< EXTLF frequency is 32.768K default > */
#define LPLF_FREQ_4MHz     (4 * BASE_FREQ_1MHz)  /* !< LP4M frequency is 4M > */

/* Time out for HSI start up */
#define HSI_STARTUP_TIMEOUT ((uint32_t)0x0070U)
/* Time out for HSE fast start up mode */
#define HSE_FASTSTARTUP_TIMEOUT ((uint32_t)0x0070U)
/* Time out for HSE start up */
#define HSE_STARTUP_TIMEOUT ((uint32_t)0x0A39U)
// Osc_EXTHFInit
#define EXTHF_INIT_OVERTIME (0xffff)
// Osc_EXTLFInit
#define EXTLF_INIT_OVERTIME (0xffffffff)
// Pll_EXTLFInit
#define PLL_INIT_OVERTIME (0xfff)
/******************************************************************************
 *                      Type definitions
 ******************************************************************************/
/* SCLK Oscillation source selection */
typedef enum
{
    OSC_SCLK_SOURCE_INTHF = 0,
    OSC_SCLK_SOURCE_INTLF = 1,
    OSC_SCLK_SOURCE_EXTHF = 2,
    OSC_SCLK_SOURCE_PLL0  = 4,
    OSC_SCLK_SOURCE_PLL1  = 5,
} Osc_SclkSrc_t;
#define CHECK_OSC_SCLK_SRC(SCLK) (((SCLK) >> 0x03) == 0x00)

/* Low frequency peripheral clock source selection bit */
typedef enum
{
    OSC_LFCLK_SOURCE_INTLF = 0,
    OSC_LFCLK_SOURCE_EXTLF = 1,
} Osc_LfclkSrc_t;
#define CHECK_OSC_LFCLK_SRC(LFCLK) (((LFCLK) >> 2) == 0x00)

/* High frequency peripheral clock source selection bit */
typedef enum
{
    OSC_HFCLK_SOURCE_INTHF = 0,
    OSC_HFCLK_SOURCE_EXTHF = 2,
    OSC_HFCLK_SOURCE_PLL0  = 4,
    OSC_HFCLK_SOURCE_PLL1  = 5,
} Osc_HfclkSrc_t;
#define CHECK_OSC_HFCLK_SRC(HFCLK) (((HFCLK) >> 0x03) == 0x00)

/* High frequency peripheral clock source selection bit */
typedef enum
{
    OSC_HF1CLK_SOURCE_INTHF = 0,
    OSC_HF1CLK_SOURCE_EXTHF = 2,
    OSC_HF1CLK_SOURCE_PLL0  = 4,
    OSC_HF1CLK_SOURCE_PLL1  = 5,
    OSC_HF1CLK_SOURCE_LPHF  = 6,
} Osc_Hfclk1Src_t;
#define CHECK_OSC_HF1CLK_SRC(HF1CLK) (((HF1CLK) >> 0x03) == 0x00)

/* SCLK Frequency division coefficient */
typedef enum
{
    OSC_SCLK_DIVISION_1   = 0,
    OSC_SCLK_DIVISION_2   = 1,
    OSC_SCLK_DIVISION_4   = 2,
    OSC_SCLK_DIVISION_8   = 3,
    OSC_SCLK_DIVISION_16  = 4,
    OSC_SCLK_DIVISION_32  = 5,
    OSC_SCLK_DIVISION_64  = 6,
    OSC_SCLK_DIVISION_128 = 7,
} Osc_SclkDivision_t;
#define CHECK_OSC_SCLK_DIVISION(SCLK) ((uint32_t)(SCLK) <= OSC_SCLK_DIVISION_128)

/* HFCLK Frequency division coefficient */
typedef enum
{
    OSC_HFCLK_DIVISION_1   = 0,
    OSC_HFCLK_DIVISION_2   = 1,
    OSC_HFCLK_DIVISION_4   = 2,
    OSC_HFCLK_DIVISION_8   = 3,
    OSC_HFCLK_DIVISION_16  = 4,
    OSC_HFCLK_DIVISION_32  = 5,
    OSC_HFCLK_DIVISION_64  = 6,
    OSC_HFCLK_DIVISION_128 = 7,
    OSC_HFCLK_DIVISION_256 = 8,
    OSC_HFCLK_DIVISION_512 = 9,
} Osc_HfclkDivision_t;
#define CHECK_OSC_HFCLK_DIVISION(DIV) (((DIV) >> 0x04) == 0x00)

/* HF1CLK Frequency division coefficient */
typedef enum
{
    OSC_HF1CLK_DIVISION_1   = 0,
    OSC_HF1CLK_DIVISION_2   = 1,
    OSC_HF1CLK_DIVISION_4   = 2,
    OSC_HF1CLK_DIVISION_8   = 3,
    OSC_HF1CLK_DIVISION_16  = 4,
    OSC_HF1CLK_DIVISION_32  = 5,
    OSC_HF1CLK_DIVISION_64  = 6,
    OSC_HF1CLK_DIVISION_128 = 7,
    OSC_HF1CLK_DIVISION_256 = 8,
    OSC_HF1CLK_DIVISION_512 = 9,
} Osc_Hfclk1Division_t;
#define CHECK_OSC_HF1CLK_DIVISION(DIV) (((DIV) >> 0x04) == 0x00)

/* LFCLK Frequency division coefficient */
typedef enum
{
    OSC_LFCLK_DIVISION_1   = 0,
    OSC_LFCLK_DIVISION_2   = 1,
    OSC_LFCLK_DIVISION_4   = 2,
    OSC_LFCLK_DIVISION_8   = 3,
    OSC_LFCLK_DIVISION_16  = 4,
    OSC_LFCLK_DIVISION_32  = 5,
    OSC_LFCLK_DIVISION_64  = 6,
    OSC_LFCLK_DIVISION_128 = 7,
} Osc_LfclkDivision_t;
#define CHECK_OSC_LFCLK_DIVISION(LFCLK) ((uint32_t)(LFCLK) <= OSC_LFCLK_DIVISION_128)

/* CLKOUT Output clock selection */
typedef enum
{
    OSC_CLKOUT_SCLK  = 0,
    OSC_CLKOUT_OSC3  = 2,
    OSC_CLKOUT_EXTLF = 3,
    OSC_CLKOUT_EXTHF = 4,
    OSC_CLKOUT_INTLF = 6,
    OSC_CLKOUT_INTHF = 8,
    OSC_CLKOUT_PLL0  = 0xAU,
    OSC_CLKOUT_PLL1  = 0xCU,
} Osc_ClkOutSrc_t;
#define CHECK_OSC_CLKOUT_SOURCE(CLKOUT) (((CLKOUT) >> 0x04) == 0x00)

/* CLKOUT Output clock frequency division */
typedef enum
{
    OSC_CLKOUT_DIVISION_1   = 0,
    OSC_CLKOUT_DIVISION_2   = 1,
    OSC_CLKOUT_DIVISION_4   = 2,
    OSC_CLKOUT_DIVISION_8   = 3,
    OSC_CLKOUT_DIVISION_16  = 4,
    OSC_CLKOUT_DIVISION_32  = 5,
    OSC_CLKOUT_DIVISION_64  = 6,
    OSC_CLKOUT_DIVISION_128 = 7,
} Osc_ClkOutDivision_t;
#define CHECK_OSC_CLKOUT_DIVISION(CLKOUT) ((uint32_t)(CLKOUT) <= OSC_CLKOUT_DIVISION_128)

/* PLL Start delay time configuration */
typedef enum
{
    OSC_PLL_START_DELAY_64    = 0,
    OSC_PLL_START_DELAY_128   = 1,
    OSC_PLL_START_DELAY_256   = 2,
    OSC_PLL_START_DELAY_512   = 3,
    OSC_PLL_START_DELAY_1024  = 4,
    OSC_PLL_START_DELAY_2048  = 5,
    OSC_PLL_START_DELAY_4096  = 6,
    OSC_PLL_START_DELAY_8192  = 7,
    OSC_PLL_START_DELAY_16384 = 8,
    OSC_PLL_START_DELAY_32768 = 9,
} Osc_PllStartDelay_t;
#define CHECK_OSC_PLL_START_DELAY(DELAY) (((DELAY) >> 0x04) == 0x00)

/* The external high-frequency oscillator starts the delay time configuration */
typedef enum
{
    OSC_EXT_START_DELAY_256    = 0,
    OSC_EXT_START_DELAY_512    = 1,
    OSC_EXT_START_DELAY_1024   = 2,
    OSC_EXT_START_DELAY_2048   = 3,
    OSC_EXT_START_DELAY_4096   = 4,
    OSC_EXT_START_DELAY_8192   = 5,
    OSC_EXT_START_DELAY_16384  = 6,
    OSC_EXT_START_DELAY_32768  = 7,
    OSC_EXT_START_DELAY_65536  = 8,
    OSC_EXT_START_DELAY_131072 = 9,
} Osc_ExtStartDelay_t;
#define CHECK_OSC_EXT_START_DELAY(DELAY) (((DELAY) >> 0x04) == 0x00)

/**
 * PLL输入时钟源选择
 * */
typedef enum
{
    OSC_PLL_INPUT_INTHF = 0,
    OSC_PLL_INPUT_EXTHF = 1,
} Osc_PllInput_t;
#define CHECK_OSC_PLL_INPUT(PLLINPUT) ((uint32_t)(PLLINPUT) <= OSC_PLL_INPUT_EXTHF)

/* PLL Input the clock division factor */
typedef enum
{
    OSC_PLL_DIVISION_1,
    OSC_PLL_DIVISION_2
} Osc_PllDivision_t;
#define CHECK_OSC_PLL_DIVISION(SCLK) ((uint32_t)(SCLK) <= OSC_PLL_DIVISION_2)

/**
 * LPHF启动延时时间配置
 * */
typedef enum
{
    OSC_LPHF_START_DELAY_0      = 0,
    OSC_LPHF_START_DELAY_512    = 1,
    OSC_LPHF_START_DELAY_1024   = 2,
    OSC_LPHF_START_DELAY_2048   = 3,
    OSC_LPHF_START_DELAY_4096   = 4,
    OSC_LPHF_START_DELAY_8192   = 5,
    OSC_LPHF_START_DELAY_16384  = 6,
    OSC_LPHF_START_DELAY_32768  = 7,
    OSC_LPHF_START_DELAY_65536  = 8,
    OSC_LPHF_START_DELAY_131072 = 9,
} OSC_LphfStartDelay_t;
#define CHECK_OSC_LPHF_START_DELAY(DELAY) (((DELAY) >> 0x04) == 0x00)

/**
 * FSCM_GAP时钟故障检测间隔
 * */
typedef enum
{
    OSC_FSCM_GAP_INTLF16  = 4,
    OSC_FSCM_GAP_INTLF32  = 5,
    OSC_FSCM_GAP_INTLF64  = 6,
    OSC_FSCM_GAP_INTLF128 = 7,
} Osc_FscmGap_t;
#define CHECK_OSC_FSCM_GAP(SEL) (((SEL) <= OSC_FSCM_GAP_INTLF128) && ((SEL) >= OSC_FSCM_GAP_INTLF16))

/**
 * FSCM_SOURCE时钟故障检测源
 * */
typedef enum
{
    OSC_FSCM_SOURCE_EXTHF = 0,
    OSC_FSCM_SOURCE_EXTLF = 1,
    OSC_FSCM_SOURCE_SCLK  = 2,
    OSC_FSCM_SOURCE_INTLF = 3,
    OSC_FSCM_SOURCE_INTHF = 4,
    OSC_FSCM_SOURCE_PLL0  = 5,
    OSC_FSCM_SOURCE_PLL1  = 7,
} Osc_FscmSrc_t;
#define CHECK_OSC_FSCM_SOURCE(SOURCE) (((SOURCE) >> 0x03) == 0x00)

/**
 * INTLF启动延时时间配置
 */
typedef enum
{
    OSC_INTLF_START_DELAY_0    = 0,
    OSC_INTLF_START_DELAY_32   = 1,
    OSC_INTLF_START_DELAY_64   = 2,
    OSC_INTLF_START_DELAY_128  = 3,
    OSC_INTLF_START_DELAY_256  = 4,
    OSC_INTLF_START_DELAY_512  = 5,
    OSC_INTLF_START_DELAY_1024 = 6,
    OSC_INTLF_START_DELAY_2048 = 7,
    OSC_INTLF_START_DELAY_4096 = 8,
    OSC_INTLF_START_DELAY_8192 = 9,
} Osc_IntlfStartDelay_t;
#define CHECK_OSC_INTLF_START_DELAY(DELAY) (((DELAY) >> 0x04) == 0x00)

/**
 * INTHF启动延时时间配置
 */
typedef enum
{
    OSC_INTHF_START_DELAY_0      = 0,
    OSC_INTHF_START_DELAY_512    = 1,
    OSC_INTHF_START_DELAY_1024   = 2,
    OSC_INTHF_START_DELAY_2048   = 3,
    OSC_INTHF_START_DELAY_4096   = 4,
    OSC_INTHF_START_DELAY_8192   = 5,
    OSC_INTHF_START_DELAY_16384  = 6,
    OSC_INTHF_START_DELAY_32768  = 7,
    OSC_INTHF_START_DELAY_65536  = 8,
    OSC_INTHF_START_DELAY_131072 = 9,
} Osc_InthfStartDelay_t;
#define CHECK_OSC_INTHF_START_DELAY(DELAY) (((DELAY) >> 0x04) == 0x00)

/**
 * EXTHF驱动调节档位
 */
typedef enum
{
    OSC_EXTHF_DRIVE_WEIGHTS_0_4  = 0,
    OSC_EXTHF_DRIVE_WEIGHTS_2_4  = 1,
    OSC_EXTHF_DRIVE_WEIGHTS_4_4  = 2,
    OSC_EXTHF_DRIVE_WEIGHTS_6_4  = 3,
    OSC_EXTHF_DRIVE_WEIGHTS_8_4  = 4,
    OSC_EXTHF_DRIVE_WEIGHTS_10_4 = 5,
    OSC_EXTHF_DRIVE_WEIGHTS_12_4 = 6,
    OSC_EXTHF_DRIVE_WEIGHTS_14_4 = 7,
    OSC_EXTHF_DRIVE_WEIGHTS_16_4 = 8,
    OSC_EXTHF_DRIVE_WEIGHTS_18_4 = 9,
    OSC_EXTHF_DRIVE_WEIGHTS_20_4 = 10,
    OSC_EXTHF_DRIVE_WEIGHTS_22_4 = 11,
    OSC_EXTHF_DRIVE_WEIGHTS_24_4 = 12,
    OSC_EXTHF_DRIVE_WEIGHTS_26_4 = 13,
    OSC_EXTHF_DRIVE_WEIGHTS_28_4 = 14,
    OSC_EXTHF_DRIVE_WEIGHTS_30_4 = 15,
} Osc_ExthfDriveWeights_t;
#define CHECK_OSC_EXTHF_DRIVE_WEIGHTS(SEL) ((uint32_t)(SEL) <= EXTHF_DRIVE_WEIGHTS_30_4)

/**
 * EXTHF比较器电流调整
 */
typedef enum
{
    EXTHF_CMP_BIAS_CURRENDT_12P5 = 0,
    EXTHF_CMP_BIAS_CURRENDT_25   = 1,
    EXTHF_CMP_BIAS_CURRENDT_37P5 = 2,
    EXTHF_CMP_BIAS_CURRENDT_50   = 3,
} Osc_ExthfCmpBiasCurrent_t;
#define CHECK_OSC_EXTHF_CMP_BIAS_CURRENDT(SEL) ((uint32_t)(SEL) <= EXTHF_CMP_BIAS_CURRENDT_50)

/**
 * PLL输入参数的校验
 */
#define CHECK_PLL_MULTIPLE_NValue(MUL)  (((uint32_t)(MUL) <= 0xF) && ((uint32_t)(MUL) >= 0x1))
#define CHECK_PLL_MULTIPLE_MValue(MUL)  (((uint32_t)(MUL) <= 0x3FFF) && ((uint32_t)(MUL) >= 0x4))
#define CHECK_PLL_MULTIPLE_NOValue(MUL) (((MUL) == 1) || ((MUL) == 2) || ((MUL) == 4) || ((MUL) == 8))
/******************************************************************************
 *                      Export Variables
 ******************************************************************************/

/******************************************************************************
 *                      Export Functions
 ******************************************************************************/

#ifdef __cplusplus
}
#endif /*End of __cplusplus*/
#endif /*End of KF32A158SF_OSCCLK_BASE_H*/
/* EOF */
