/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name        : kf32a158sf_timer_base.h
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
#ifndef KF32A158SF_TIMER_BASE_H
#define KF32A158SF_TIMER_BASE_H

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

/******************************************************************************
 *                      Type definitions
 ******************************************************************************/

/**定时器工作时钟*/
typedef enum
{
    /** @brief System Clock */
    TIM_SCLK = 0U,
    /** @brief High Frequency Peripheral Clock  */
    TIM_HFCLK = 1U,
    /** @brief Low Frequency Peripheral Clock */
    TIM_LFCLK = 2U,
    /** @brief Low Frequency Internal Clock For T0 Only  */
    TIM_INTLF_T0 = 3U,
    /** @brief High Frequency Peripheral 1 Clock For T5T6 Only  */
    TIM_HF1CLK_T5T6 = 3U,
} Timer_ClockSource_t;
/**检查定时器工作时钟*/
#define CHECK_TIM_CLK(CLK) ((uint32_t)(CLK) <= (uint32_t)TIM_HF1CLK_T5T6)

/**定时器计数方向*/
typedef enum
{
    /** @brief Counting Down */
    DOWN_COUNTING,
    /** @brief Count Up */
    UP_COUNTING
} Timer_CountingDir_t;
/**检查定时器计数方向*/
#define CHECK_TIM_COUNT_DIR(DIR) ((uint32_t)(DIR) <= (uint32_t)UP_COUNTING)

/**定时器计数方式*/
typedef enum
{
    /** @brief Count down, interrupt occurs at underflow  */
    TIM_MANNER_DOWN_FLAG = 0,
    /** @brief Count up , interrupt occurs at overflow  */
    TIM_MANNER_UP_FLAG = 4,
    /** @brief Count up then down, interrupt occurs   at overflow */
    TIM_MANNER_UPDOWN_UP_FLAG = 5,
    /** @brief Count up then down, interrupt occurs at  underflow  */
    TIM_MANNER_UPDOWN_DOWN_FLAG = 6,
    /** @brief Count up then down, interrupt occurs at overflow or underflow  */
    TIM_MANNER_UPDOWN_BOTH_FLAG = 7,
} Timer_CountingManner_t;
/**检查定时器计数方式*/
#define CHECK_TIM_COUNT_MANNER(SEL)                                                                                    \
    (((SEL) == TIM_MANNER_DOWN_FLAG) || ((SEL) == TIM_MANNER_UP_FLAG) || ((SEL) == TIM_MANNER_UPDOWN_UP_FLAG) ||       \
     ((SEL) == TIM_MANNER_UPDOWN_DOWN_FLAG) || ((SEL) == TIM_MANNER_UPDOWN_BOTH_FLAG))

/**定时器工作模式*/
typedef enum
{
    /** @brief Work in Timing */
    TIMING_MODE,
    /** @brief Work in Counting */
    COUNTING_MODE
} Timer_Mode_t;
/**检查定时器工作模式*/
#define CHECK_TIM_WORK_MODE(MOD) ((uint32_t)(MOD) <= (uint32_t)COUNTING_MODE)

/**FlexMUX输出触发定时器*/
typedef enum
{
    /**FlexMUX CH1 触发定时器*/
    TIM_FLEXMUX_CH1 = 0x0U,
    /**FlexMUX CH2 触发定时器*/
    TIM_FLEXMUX_CH2,
    /**FlexMUX CH3 触发定时器*/
    TIM_FLEXMUX_CH3,
    /**FlexMUX CH4 触发定时器*/
    TIM_FLEXMUX_CH4,
} Timer_FlexmuxTriggerSource_t;
/**检查FlexMUX输出触发定时器*/
#define CHECK_TIM_FLEXMUX_SOURCE(SEL) ((uint32_t)(SEL) <= (uint32_t)TIM_FLEXMUX_CH4)

/******************************************************************************
 *                      Export Variables
 ******************************************************************************/

/******************************************************************************
 *                      Export Functions
 ******************************************************************************/

#ifdef __cplusplus
}
#endif /*End of __cplusplus*/
#endif /*End of KF32A158SF_TIMER_BASE_H*/
/* EOF */
