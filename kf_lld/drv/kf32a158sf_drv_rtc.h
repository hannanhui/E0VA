/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name        : kf32a158sf_drv_rtc.h
 *  @Date             : 2025-08-08
 *  @Version          : {{VersionDate}}
 *  @Description      : This file provides all the functions prototypes for the RTC driver.
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
 *  |2025-08-08  |V1.0     |AE Group     |New create
 ******************************************************************************/
#ifndef KF32A158SF_DRV_RTC_H
#define KF32A158SF_DRV_RTC_H

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
/* PRQA S 4342 EOF #KQR004342 */

/******************************************************************************
 *                      Include Files
 ******************************************************************************/
#include <stdint.h>
#include <stdbool.h>
#include "kf_types.h"
#include "kf32a158sf_reg_rtc.h"

#ifdef KF_DRV_RTC_ASSERT
#include "dev_assert.h"
#define KF_RTC_ASSERT(x) KF_DEV_ASSERT(x)
#else
#define KF_RTC_ASSERT(x) ((void)0U)
#endif
/******************************************************************************
 *                      Macro or Inline
 ******************************************************************************/

/******************************************************************************
 *                      Type definitions
 ******************************************************************************/

/*时间节拍*/
typedef enum
{
    RTC_TICK_TIME_1S = 0,
    RTC_TICK_TIME_1S_DIV_2,
    RTC_TICK_TIME_1S_DIV_4,
    RTC_TICK_TIME_1S_DIV_8,
    RTC_TICK_TIME_1S_DIV_16,
    RTC_TICK_TIME_1S_DIV_32,
    RTC_TICK_TIME_1S_DIV_64,
    RTC_TICK_TIME_1S_DIV_128,
} Rtc_TickTime_t;
#define CHECK_RTC_TICKTIME(x) (((x) >= RTC_TICK_TIME_1S) && ((x) <= RTC_TICK_TIME_1S_DIV_128))

/*时间戳触发沿*/
typedef enum
{
    RTC_STAMP_TRIG_EDGE_RISE = 0,
    RTC_STAMP_TRIG_EDGE_FALL,
} Rtc_StampTrigEdge_t;
#define CHECK_RTC_STAMPTRIGEDGE(x) (((x) == RTC_STAMP_TRIG_EDGE_RISE) || ((x) == RTC_STAMP_TRIG_EDGE_FALL))

/**RTC星期*/
typedef enum
{
    RTC_WEEKDAY_SUNDAY = 0x00U,
    RTC_WEEKDAY_MONDAY,
    RTC_WEEKDAY_TUESDAY,
    RTC_WEEKDAY_WEDNESDAY,
    RTC_WEEKDAY_THURSDAY,
    RTC_WEEKDAY_FRIDAY,
    RTC_WEEKDAY_SATURDAY,
} Rtc_WeekDay_t;
#define CHECK_RTC_WEEKDAY(x)                                                                                           \
    (((x) == RTC_WEEKDAY_SUNDAY) || ((x) == RTC_WEEKDAY_MONDAY) || ((x) == RTC_WEEKDAY_TUESDAY) ||                     \
     ((x) == RTC_WEEKDAY_WEDNESDAY) || ((x) == RTC_WEEKDAY_THURSDAY) || ((x) == RTC_WEEKDAY_FRIDAY) ||                 \
     ((x) == RTC_WEEKDAY_SATURDAY))

typedef enum
{
    RTC_SEC_0  = 0x00u,
    RTC_SEC_1  = 0x01u,
    RTC_SEC_2  = 0x02u,
    RTC_SEC_3  = 0x03u,
    RTC_SEC_4  = 0x04u,
    RTC_SEC_5  = 0x05u,
    RTC_SEC_6  = 0x06u,
    RTC_SEC_7  = 0x07u,
    RTC_SEC_8  = 0x08u,
    RTC_SEC_9  = 0x09u,
    RTC_SEC_10 = 0x10u,
    RTC_SEC_11 = 0x11u,
    RTC_SEC_12 = 0x12u,
    RTC_SEC_13 = 0x13u,
    RTC_SEC_14 = 0x14u,
    RTC_SEC_15 = 0x15u,
    RTC_SEC_16 = 0x16u,
    RTC_SEC_17 = 0x17u,
    RTC_SEC_18 = 0x18u,
    RTC_SEC_19 = 0x19u,
    RTC_SEC_20 = 0x20u,
    RTC_SEC_21 = 0x21u,
    RTC_SEC_22 = 0x22u,
    RTC_SEC_23 = 0x23u,
    RTC_SEC_24 = 0x24u,
    RTC_SEC_25 = 0x25u,
    RTC_SEC_26 = 0x26u,
    RTC_SEC_27 = 0x27u,
    RTC_SEC_28 = 0x28u,
    RTC_SEC_29 = 0x29u,
    RTC_SEC_30 = 0x30u,
    RTC_SEC_31 = 0x31u,
    RTC_SEC_32 = 0x32u,
    RTC_SEC_33 = 0x33u,
    RTC_SEC_34 = 0x34u,
    RTC_SEC_35 = 0x35u,
    RTC_SEC_36 = 0x36u,
    RTC_SEC_37 = 0x37u,
    RTC_SEC_38 = 0x38u,
    RTC_SEC_39 = 0x39u,
    RTC_SEC_40 = 0x40u,
    RTC_SEC_41 = 0x41u,
    RTC_SEC_42 = 0x42u,
    RTC_SEC_43 = 0x43u,
    RTC_SEC_44 = 0x44u,
    RTC_SEC_45 = 0x45u,
    RTC_SEC_46 = 0x46u,
    RTC_SEC_47 = 0x47u,
    RTC_SEC_48 = 0x48u,
    RTC_SEC_49 = 0x49u,
    RTC_SEC_50 = 0x50u,
    RTC_SEC_51 = 0x51u,
    RTC_SEC_52 = 0x52u,
    RTC_SEC_53 = 0x53u,
    RTC_SEC_54 = 0x54u,
    RTC_SEC_55 = 0x55u,
    RTC_SEC_56 = 0x56u,
    RTC_SEC_57 = 0x57u,
    RTC_SEC_58 = 0x58u,
    RTC_SEC_59 = 0x59u,
} Rtc_Second_t;
#define CHECK_RTC_SECOND(x) (((x) >= RTC_SEC_0) && ((x) <= RTC_SEC_59))

typedef enum
{
    RTC_MIN_0  = 0x00u,
    RTC_MIN_1  = 0x01u,
    RTC_MIN_2  = 0x02u,
    RTC_MIN_3  = 0x03u,
    RTC_MIN_4  = 0x04u,
    RTC_MIN_5  = 0x05u,
    RTC_MIN_6  = 0x06u,
    RTC_MIN_7  = 0x07u,
    RTC_MIN_8  = 0x08u,
    RTC_MIN_9  = 0x09u,
    RTC_MIN_10 = 0x10u,
    RTC_MIN_11 = 0x11u,
    RTC_MIN_12 = 0x12u,
    RTC_MIN_13 = 0x13u,
    RTC_MIN_14 = 0x14u,
    RTC_MIN_15 = 0x15u,
    RTC_MIN_16 = 0x16u,
    RTC_MIN_17 = 0x17u,
    RTC_MIN_18 = 0x18u,
    RTC_MIN_19 = 0x19u,
    RTC_MIN_20 = 0x20u,
    RTC_MIN_21 = 0x21u,
    RTC_MIN_22 = 0x22u,
    RTC_MIN_23 = 0x23u,
    RTC_MIN_24 = 0x24u,
    RTC_MIN_25 = 0x25u,
    RTC_MIN_26 = 0x26u,
    RTC_MIN_27 = 0x27u,
    RTC_MIN_28 = 0x28u,
    RTC_MIN_29 = 0x29u,
    RTC_MIN_30 = 0x30u,
    RTC_MIN_31 = 0x31u,
    RTC_MIN_32 = 0x32u,
    RTC_MIN_33 = 0x33u,
    RTC_MIN_34 = 0x34u,
    RTC_MIN_35 = 0x35u,
    RTC_MIN_36 = 0x36u,
    RTC_MIN_37 = 0x37u,
    RTC_MIN_38 = 0x38u,
    RTC_MIN_39 = 0x39u,
    RTC_MIN_40 = 0x40u,
    RTC_MIN_41 = 0x41u,
    RTC_MIN_42 = 0x42u,
    RTC_MIN_43 = 0x43u,
    RTC_MIN_44 = 0x44u,
    RTC_MIN_45 = 0x45u,
    RTC_MIN_46 = 0x46u,
    RTC_MIN_47 = 0x47u,
    RTC_MIN_48 = 0x48u,
    RTC_MIN_49 = 0x49u,
    RTC_MIN_50 = 0x50u,
    RTC_MIN_51 = 0x51u,
    RTC_MIN_52 = 0x52u,
    RTC_MIN_53 = 0x53u,
    RTC_MIN_54 = 0x54u,
    RTC_MIN_55 = 0x55u,
    RTC_MIN_56 = 0x56u,
    RTC_MIN_57 = 0x57u,
    RTC_MIN_58 = 0x58u,
    RTC_MIN_59 = 0x59u,
} Rtc_Minute_t;
#define CHECK_RTC_MINUTE(x) (((x) >= RTC_MIN_0) && ((x) <= RTC_MIN_59))

typedef enum
{
    RTC_HOUR_0  = 0x00u,
    RTC_HOUR_1  = 0x01u,
    RTC_HOUR_2  = 0x02u,
    RTC_HOUR_3  = 0x03u,
    RTC_HOUR_4  = 0x04u,
    RTC_HOUR_5  = 0x05u,
    RTC_HOUR_6  = 0x06u,
    RTC_HOUR_7  = 0x07u,
    RTC_HOUR_8  = 0x08u,
    RTC_HOUR_9  = 0x09u,
    RTC_HOUR_10 = 0x10u,
    RTC_HOUR_11 = 0x11u,
    RTC_HOUR_12 = 0x12u,
    RTC_HOUR_13 = 0x13u,
    RTC_HOUR_14 = 0x14u,
    RTC_HOUR_15 = 0x15u,
    RTC_HOUR_16 = 0x16u,
    RTC_HOUR_17 = 0x17u,
    RTC_HOUR_18 = 0x18u,
    RTC_HOUR_19 = 0x19u,
    RTC_HOUR_20 = 0x20u,
    RTC_HOUR_21 = 0x21u,
    RTC_HOUR_22 = 0x22u,
    RTC_HOUR_23 = 0x23u,
} Rtc_Hour_t;
#define CHECK_RTC_HOUR(x) (((x) >= RTC_HOUR_0) && ((x) <= RTC_HOUR_23))

typedef enum
{
    RTC_DAY_1  = 0x00u,
    RTC_DAY_2  = 0x01u,
    RTC_DAY_3  = 0x02u,
    RTC_DAY_4  = 0x03u,
    RTC_DAY_5  = 0x04u,
    RTC_DAY_6  = 0x05u,
    RTC_DAY_7  = 0x06u,
    RTC_DAY_8  = 0x07u,
    RTC_DAY_9  = 0x08u,
    RTC_DAY_10 = 0x09u,
    RTC_DAY_11 = 0x10u,
    RTC_DAY_12 = 0x11u,
    RTC_DAY_13 = 0x12u,
    RTC_DAY_14 = 0x13u,
    RTC_DAY_15 = 0x14u,
    RTC_DAY_16 = 0x15u,
    RTC_DAY_17 = 0x16u,
    RTC_DAY_18 = 0x17u,
    RTC_DAY_19 = 0x18u,
    RTC_DAY_20 = 0x19u,
    RTC_DAY_21 = 0x20u,
    RTC_DAY_22 = 0x21u,
    RTC_DAY_23 = 0x22u,
    RTC_DAY_24 = 0x23u,
    RTC_DAY_25 = 0x24u,
    RTC_DAY_26 = 0x25u,
    RTC_DAY_27 = 0x26u,
    RTC_DAY_28 = 0x27u,
    RTC_DAY_29 = 0x28u,
    RTC_DAY_30 = 0x29u,
    RTC_DAY_31 = 0x30u,
} Rtc_Day_t;
#define CHECK_RTC_DAY(x) (((x) >= RTC_DAY_0) && ((x) <= RTC_DAY_30))

typedef enum
{
    RTC_JANUARY   = 0x00u,
    RTC_FEBRUARY  = 0x01u,
    RTC_MARCH     = 0x02u,
    RTC_APRIL     = 0x03u,
    RTC_MAY       = 0x04u,
    RTC_JUNE      = 0x05u,
    RTC_JULY      = 0x06u,
    RTC_AUGUST    = 0x07u,
    RTC_SEPTEMBER = 0x08u,
    RTC_OCTOBER   = 0x09u,
    RTC_NOVEMBER  = 0x10u,
    RTC_DECEMBER  = 0x11u,
} Rtc_Month_t;
#define CHECK_RTC_MONTH(x) (((x) >= RTC_JANUARY) && ((x) <= RTC_DECEMBER))

/**定时器 0/1 时钟源选择*/
typedef enum
{
    RTC_TIM_CLKSRC_1_DIV_256S = 0x0U,
    RTC_TIM_CLKSRC_1_DIV_64S,
    RTC_TIM_CLKSRC_1_DIV_32S,
    RTC_TIM_CLKSRC_1_DIV_16S,
    RTC_TIM_CLKSRC_1_DIV_4S,
    RTC_TIM_CLKSRC_1S,
    RTC_TIM_CLKSRC_1MINUTES,
    RTC_TIM_CLKSRC_1HOUR,
    RTC_TIM_CLKSRC_COMBINATION,
} Rtc_TimeClkSrc_t;
#define CHECK_RTC_TIMECLKSRC(x)                                                                                        \
    (((x) == RTC_TIM_CLKSRC_1_DIV_256S) || ((x) == RTC_TIM_CLKSRC_1_DIV_64S) || ((x) == RTC_TIM_CLKSRC_1_DIV_32S) ||   \
     ((x) == RTC_TIM_CLKSRC_1_DIV_16S) || ((x) == RTC_TIM_CLKSRC_1_DIV_4S) || ((x) == RTC_TIM_CLKSRC_1S) ||            \
     ((x) == RTC_TIM_CLKSRC_1MINUTES) || ((x) == RTC_TIM_CLKSRC_1HOUR) || ((x) == RTC_TIM_CLKSRC_COMBINATION))

/**时间戳通道*/
typedef enum
{
    RTC_TSCH_TS = 8U,
    RTC_TSCH_WKUP1,
    RTC_TSCH_WKUP2,
    RTC_TSCH_WKUP3,
    RTC_TSCH_WKUP4,
    RTC_TSCH_WKUP5,
} Rtc_TimeStampChannel_t;
#define CHECK_RTC_TIMESTAMPCHANNEL(x)                                                                                  \
    (((x) == RTC_TSCH_TS) || ((x) == RTC_TSCH_WKUP1) || ((x) == RTC_TSCH_WKUP2) || ((x) == RTC_TSCH_WKUP3) ||          \
     ((x) == RTC_TSCH_WKUP4) || ((x) == RTC_TSCH_WKUP5))

/**定时器时钟源*/
typedef enum
{
    TMR_CLKSRC_RTC_DIV_128 = 0x0U,
    TMR_CLKSRC_RTC_DIV_512,
    TMR_CLKSRC_RTC_DIV_1024,
    TMR_CLKSRC_RTC_DIV_2048,
    TMR_CLKSRC_RTC_DIV_8192,
    TMR_CLKSRC_1S,
    TMR_CLKSRC_1MIN,
    TMR_CLKSRC_1HOUR,
    /**仅用于TIMER0*/
    TMR_CLKSRC_TMR0_TMR1_CASCADE
} Rtc_TmrClkSrc_t;
#define CHECK_RTC_TMRCLKSRC(x) (((x) >= TMR_CLKSRC_RTC_DIV_128) && ((x) <= TMR_CLKSRC_TMR0_TMR1_CASCADE))

/**设置中断序号*/
typedef enum
{
    RTC_INTR_SET_SECIE = 0U,
    RTC_INTR_SET_MINIE,
    RTC_INTR_SET_HOURIE,
    RTC_INTR_SET_DAYIE,
    RTC_INTR_SET_ALRAIE,
    RTC_INTR_SET_ALRBIE,
    RTC_INTR_SET_TTIE,
    RTC_INTR_SET_RTCT0IE = 8U,
    RTC_INTR_SET_RTCT1IE,
    RTC_INTR_SET_WEEKIE = 13U,
    RTC_INTR_SET_MONTHIE,
    RTC_INTR_SET_YEARIE,
} Rtc_IntrSetIndex_t;
#define CHECK_RTC_INTRSETINDEX(x)                                                                                      \
    (((x) >= RTC_INTR_SET_SECIE) && ((x) <= RTC_INTR_SET_YEARIE) && ((x) != 7U) && ((x) != 12U))

/**获取中断序号*/
typedef enum
{
    RTC_INTR_GET_SECIF = 0U,
    RTC_INTR_GET_MINIF,
    RTC_INTR_GET_HOURIF,
    RTC_INTR_GET_DAYIF,
    RTC_INTR_GET_ALRAIF,
    RTC_INTR_GET_ALRBIF,
    RTC_INTR_GET_TTIF,
    RTC_INTR_GET_RTCT0IF = 8U,
    RTC_INTR_GET_RTCT1IF,
    RTC_INTR_GET_WEEKIF = 13U,
    RTC_INTR_GET_MONTHIF,
    RTC_INTR_GET_YEARIF,
} Rtc_IntrGetIndex_t;
#define CHECK_RTC_INTRGETINDEX(x)                                                                                      \
    (((x) >= RTC_INTR_GET_SECIF) && ((x) <= RTC_INTR_GET_YEARIF) && ((x) != 7U) && ((x) != 12U))

/**清除中断序号*/
typedef enum
{
    RTC_INTR_CLEAR_SECIC = 16U,
    RTC_INTR_CLEAR_MINIC,
    RTC_INTR_CLEAR_HOURIC,
    RTC_INTR_CLEAR_DAYIC,
    RTC_INTR_CLEAR_ALRAIC,
    RTC_INTR_CLEAR_ALRBIC,
    RTC_INTR_CLEAR_TTIC,
    RTC_INTR_CLEAR_RTCT0IC = 24U,
    RTC_INTR_CLEAR_RTCT1IC,
    RTC_INTR_CLEAR_WEEKIC = 29U,
    RTC_INTR_CLEAR_MONTHIC,
    RTC_INTR_CLEAR_YEARIC,
} Rtc_IntrClearIndex_t;
#define CHECK_RTC_INTRCLEARINDEX(x)                                                                                    \
    (((x) >= RTC_INTR_CLEAR_SECIC) && ((x) <= RTC_INTR_CLEAR_YEARIC) && ((x) != 23U) && ((x) != 28U))

/******************************************************************************
 *                      Export Variables
 ******************************************************************************/

/******************************************************************************
 *                      Export Functions
 ******************************************************************************/

/**
 * @brief: 设置RTC使能位
 * @param Module: RTC寄存器结构体指针
 * @param State:
 *          true 使能RTC
 *          false 禁止RTC
 * @retval 无
 */
KF_INLINE void Rtc_LL_SetEnabled(Rtc_RegisterMap_t *const Module, bool State)
{
    KF_RTC_ASSERT(CHECK_RTC_ALL_PERIPH_ADDR(Module));

    Module->CR.bits.RTCEN = State ? 1U : 0U;
}

/**
 * @brief: 获取RTC活动状态
 * @param Module: RTC寄存器结构体指针
 * @retval  true RTC处在正常有效状态
 * @retval  false RTC处在复位状态
 */
KF_INLINE bool Rtc_LL_GetState(const Rtc_RegisterMap_t *const Module)
{
    KF_RTC_ASSERT(CHECK_RTC_ALL_PERIPH_ADDR(Module));

    return Module->CR.bits.LD != 0U;
}

/**
 * @brief 配置RTC操作关闭状态
 * @param Module 指向寄存器的指针
 * @retval bool RTC 操作关闭状态
 *          true: 上一次对 RTC 寄存器的写操作已经完成
 *          false: 上一次对 RTC 寄存器的写操作仍在进行
 */
KF_INLINE bool Rtc_LL_GetOperationOffState(const Rtc_RegisterMap_t *const Module)
{
    KF_RTC_ASSERT(CHECK_RTC_ALL_PERIPH_ADDR(Module));

    return Module->CR.bits.RTOFF != 0U;
}

/**
 * @brief: 设置RTC配置标志
 * @param Module: RTC寄存器结构体指针
 * @param State:
 *         true 进入配置模式
 *         false 退出配置模式(开始更新RTC 寄存器)
 * @retval 无
 */
KF_INLINE void Rtc_LL_SetConfigFlag(Rtc_RegisterMap_t *const Module, bool State)
{
    KF_RTC_ASSERT(CHECK_RTC_ALL_PERIPH_ADDR(Module));

    Module->CR.bits.CNF = State ? 1U : 0U;
}

KF_INLINE void Rtc_LL_EnterConfigMode(Rtc_RegisterMap_t *const Module)
{
    KF_RTC_ASSERT(CHECK_RTC_ALL_PERIPH_ADDR(Module));

    Rtc_LL_SetConfigFlag(Module, true);
}

KF_INLINE void Rtc_LL_ExitConfigMode(Rtc_RegisterMap_t *const Module)
{
    KF_RTC_ASSERT(CHECK_RTC_ALL_PERIPH_ADDR(Module));

    Rtc_LL_SetConfigFlag(Module, false);
}

/**
 * @brief 配置RTC的小时显示的类型
 * @param Module 指向寄存器的指针
 * @param Type 设置小时显示的类型,取值为
 *               true 小时显示为12小时制
 *               false 小时显示为24小时制
 * @retval void
 */
KF_INLINE void Rtc_LL_SetHourFormat(Rtc_RegisterMap_t *const Module, bool Type)
{
    KF_RTC_ASSERT(CHECK_RTC_ALL_PERIPH_ADDR(Module));

    Module->CR.bits.HT = Type ? 1U : 0U;
}

/**
 * @brief 获取RTC的闰年指示标志
 * @param Module 指向寄存器的指针
 * @retval  true 当前年份为闰年
 * @retval  false 当前年份为平年
 */
KF_INLINE bool Rtc_LL_GetLeapYearFlag(const Rtc_RegisterMap_t *const Module)
{
    KF_RTC_ASSERT(CHECK_RTC_ALL_PERIPH_ADDR(Module));

    return Module->CR.bits.LIF != 0U;
}

/**
 * @brief RTC初始化
 * @param Module 指向寄存器的指针
 * @retval void
 */
KF_INLINE void Rtc_LL_Initialise(Rtc_RegisterMap_t *const Module)
{
    KF_RTC_ASSERT(CHECK_RTC_ALL_PERIPH_ADDR(Module));

    Module->CR.bits.RTC_RESET = 1U;
    NOP();
    NOP();
    NOP();
    NOP();
    Module->CR.bits.RTC_RESET = 0U;
}

/**
 * @brief: 设置时间戳通道
 * @param Module: RTC寄存器结构体指针
 * @param Channel: 时间戳通道(0~5)
 * @param State:
 *         true 使能时间戳通道
 *         false 禁止时间戳通道
 * @retval 无
 */
KF_INLINE void
Rtc_LL_SetTimeStampChannelEnabled(Rtc_RegisterMap_t *const Module, Rtc_TimeStampChannel_t Channel, bool State)
{
    KF_RTC_ASSERT(CHECK_RTC_ALL_PERIPH_ADDR(Module));
    KF_RTC_ASSERT(CHECK_RTC_TIMESTAMPCHANNEL(Channel));

    /* PRQA S 3473 2 #KQR003473 */
    REG_BITS_WRITE(
        Module->CR.reg, (uint32_t)0x1U << (uint32_t)Channel, (uint32_t)(State ? 1U : 0U) << (uint32_t)Channel);
}

/**
 * @brief RTC的时间节拍设置位
 * @param Module 指向寄存器的指针
 * @param Set 设置时间节拍
 * @retval void
 */
KF_INLINE void Rtc_LL_SetTickTime(Rtc_RegisterMap_t *const Module, Rtc_TickTime_t Set)
{
    KF_RTC_ASSERT(CHECK_RTC_ALL_PERIPH_ADDR(Module));
    KF_RTC_ASSERT(CHECK_RTC_TICKTIME(Set));

    Module->CR.bits.RTCTT = (uint32_t)Set;
}

/**
 * @brief 配置RTC减少计时
 * @param Module 指向寄存器的指针
 * @param Option 设置状态
 *               true RTC时间减少1小时
 *               false 正常计时
 * @retval void
 */
KF_INLINE void Rtc_LL_SubtractOneHour(Rtc_RegisterMap_t *const Module, bool Option)
{
    KF_RTC_ASSERT(CHECK_RTC_ALL_PERIPH_ADDR(Module));

    Module->CR.bits.SUB1H = Option ? 1U : 0U;
}

/**
 * @brief 配置RTC增加计时
 * @param Module 指向寄存器的指针
 * @param Option 设置状态
 *               true RTC时间增加1小时
 *               false 正常计时
 * @retval void
 */
KF_INLINE void Rtc_LL_IncreaseOneHour(Rtc_RegisterMap_t *const Module, bool Option)
{
    KF_RTC_ASSERT(CHECK_RTC_ALL_PERIPH_ADDR(Module));

    Module->CR.bits.ADD1H = Option ? 1U : 0U;
}

/**
 *
 * @brief 配置RTC时钟校正位
 * @param Module 指向寄存器的指针
 * @param Num 设置时钟校正位的数值, 0x0 ~0xff
 * @retval void
 */
KF_INLINE void Rtc_LL_SetClockCalibration(Rtc_RegisterMap_t *Module, uint8_t Num)
{
    KF_RTC_ASSERT(CHECK_RTC_ALL_PERIPH_ADDR(Module));

    Module->CR.bits.RTCCAL = (uint32_t)Num;
}
/*ALARM A*/

/**
 * @brief 配置RTC闹钟中断秒时间
 * @param Module 指向寄存器的指针
 * @param Seconds 传入参数设置时间
 * @retval void
 */
KF_INLINE void Rtc_LL_SetAlarmASecondTime(Rtc_RegisterMap_t *const Module, Rtc_Second_t Seconds)
{
    KF_RTC_ASSERT(CHECK_RTC_ALL_PERIPH_ADDR(Module));
    KF_RTC_ASSERT(CHECK_RTC_SECOND(Seconds));

    Module->ALRA.bits.ALRSA = (uint32_t)Seconds;
}

/**
 * @brief: 闹钟使能/禁止设置
 * @param Module: RTC寄存器结构体指针
 * @param State
 *          true 使能闹钟
 *          false 禁止闹钟
 * @retval 无
 */
KF_INLINE void Rtc_LL_SetAlarmASecondEnabled(Rtc_RegisterMap_t *const Module, bool State)
{
    KF_RTC_ASSERT(CHECK_RTC_ALL_PERIPH_ADDR(Module));

    Module->ALRA.bits.ASENA = State ? 1U : 0U;
}

/**
 * @brief 配置RTC闹钟中断分钟时间
 * @param Module 指向寄存器的指针
 * @param time 传入参数设置时间
 * @retval void
 */
KF_INLINE void Rtc_LL_SetAlarmAMinutesTime(Rtc_RegisterMap_t *const Module, Rtc_Minute_t Minutes)
{
    KF_RTC_ASSERT(CHECK_RTC_ALL_PERIPH_ADDR(Module));
    KF_RTC_ASSERT(CHECK_RTC_MINUTE(Minutes));

    Module->ALRA.bits.ALRMA = (uint32_t)Minutes;
}

/**
 * @brief: 闹钟分钟使能/禁止设置
 * @param Module: RTC寄存器结构体指针
 * @param State
 *          true 使能闹钟分钟
 *          false 禁止闹钟分钟
 * @retval 无
 */
KF_INLINE void Rtc_LL_SetAlarmAMinuteEnabled(Rtc_RegisterMap_t *const Module, bool State)
{
    KF_RTC_ASSERT(CHECK_RTC_ALL_PERIPH_ADDR(Module));

    Module->ALRA.bits.AMENA = State ? 1U : 0U;
}

/**
 * @brief 配置RTC闹钟中断小时时间
 * @param Module 指向寄存器的指针
 * @param Hour 传入参数设置时间, 0 ~ 23
 * @retval void
 */
KF_INLINE void Rtc_LL_SetAlarmAHourTime(Rtc_RegisterMap_t *const Module, Rtc_Hour_t Hour)
{
    KF_RTC_ASSERT(CHECK_RTC_ALL_PERIPH_ADDR(Module));
    KF_RTC_ASSERT(CHECK_RTC_HOUR(Hour));

    Module->ALRA.bits.ALRHA = (uint32_t)Hour;
}

/**
 * @brief 配置RTC 12小时制闹钟A的上午下午选择
 * @param Module 指向寄存器的指针
 * @param Option 选择参数
 *          true 选择下午时间
 *          false 选择上午时间
 * @retval void
 */
KF_INLINE void Rtc_LL_SelectAlarmAAmPm(Rtc_RegisterMap_t *const Module, bool Option)
{
    KF_RTC_ASSERT(CHECK_RTC_ALL_PERIPH_ADDR(Module));

    Module->ALRA.bits.AMPMA = Option ? 1U : 0U;
}

/**
 * @brief: 闹钟小时使能/禁止设置
 * @param Module: RTC寄存器结构体指针
 * @param State
 *          true 使能闹钟小时
 *          false 禁止闹钟小时
 * @retval 无
 */
KF_INLINE void Rtc_LL_SetAlarmAHourEnabled(Rtc_RegisterMap_t *const Module, bool State)
{
    KF_RTC_ASSERT(CHECK_RTC_ALL_PERIPH_ADDR(Module));

    Module->ALRA.bits.AHENA = State ? 1U : 0U;
}

/**
 * @brief 配置RTC闹钟使能
 * @param Module 指向寄存器的指针
 * @param WeekDay 设置闹钟中断星期时间,具体值见枚举$RTC_WeekDay_t$
 * @retval void
 */
KF_INLINE void Rtc_LL_SetAlarmAWeekTime(Rtc_RegisterMap_t *const Module, Rtc_WeekDay_t WeekDay)
{
    KF_RTC_ASSERT(CHECK_RTC_ALL_PERIPH_ADDR(Module));
    KF_RTC_ASSERT(CHECK_RTC_WEEKDAY(WeekDay));

    Module->ALRA.bits.ALRWA = (uint32_t)WeekDay;
}

/**
 * @brief: 闹钟星期使能/禁止设置
 * @param Module: RTC寄存器结构体指针
 * @param State
 *          true 使能闹钟星期
 *          false 禁止闹钟星期
 * @retval 无
 */
KF_INLINE void Rtc_LL_SetAlarmAWeekdayEnabled(Rtc_RegisterMap_t *const Module, bool State)
{
    KF_RTC_ASSERT(CHECK_RTC_ALL_PERIPH_ADDR(Module));

    Module->ALRA.bits.AWENA = State ? 1U : 0U;
}

/**
 * @brief: 闹钟使能/禁止设置
 * @param Module: RTC寄存器结构体指针
 * @param State
 *          true 使能闹钟秒钟位
 *          false 禁止闹钟秒钟位
 * @retval 无
 */
KF_INLINE void Rtc_LL_SetAlarmAEnabled(Rtc_RegisterMap_t *const Module, bool State)
{
    KF_RTC_ASSERT(CHECK_RTC_ALL_PERIPH_ADDR(Module));

    Module->ALRA.bits.ALRENA = State ? 1U : 0U;
}

/*ALARM B*/

/**
 * @brief 配置RTC闹钟中断秒时间
 * @param Module 指向寄存器的指针
 * @param Seconds 传入参数设置时间
 * @retval void
 */
KF_INLINE void Rtc_LL_SetAlarmBSecondTime(Rtc_RegisterMap_t *const Module, Rtc_Second_t Seconds)
{
    KF_RTC_ASSERT(CHECK_RTC_ALL_PERIPH_ADDR(Module));
    KF_RTC_ASSERT(CHECK_RTC_SECOND(Seconds));

    Module->ALRB.bits.ALRSB = (uint32_t)Seconds;
}

/**
 * @brief: 闹钟使能/禁止设置
 * @param Module: RTC寄存器结构体指针
 * @param State
 *          true 使能闹钟
 *          false 禁止闹钟
 * @retval 无
 */
KF_INLINE void Rtc_LL_SetAlarmBSecondEnabled(Rtc_RegisterMap_t *const Module, bool State)
{
    KF_RTC_ASSERT(CHECK_RTC_ALL_PERIPH_ADDR(Module));

    Module->ALRB.bits.ASENB = State ? 1U : 0U;
}

/**
 * @brief 配置RTC闹钟中断分钟时间
 * @param Module 指向寄存器的指针
 * @param time 传入参数设置时间
 * @retval void
 */
KF_INLINE void Rtc_LL_SetAlarmBMinutesTime(Rtc_RegisterMap_t *const Module, Rtc_Minute_t Minutes)
{
    KF_RTC_ASSERT(CHECK_RTC_ALL_PERIPH_ADDR(Module));
    KF_RTC_ASSERT(CHECK_RTC_MINUTE(Minutes));

    Module->ALRB.bits.ALRMB = (uint32_t)Minutes;
}

/**
 * @brief: 闹钟分钟使能/禁止设置
 * @param Module: RTC寄存器结构体指针
 * @param State
 *          true 使能闹钟分钟
 *          false 禁止闹钟分钟
 * @retval 无
 */
KF_INLINE void Rtc_LL_SetAlarmBMinuteEnabled(Rtc_RegisterMap_t *const Module, bool State)
{
    KF_RTC_ASSERT(CHECK_RTC_ALL_PERIPH_ADDR(Module));

    Module->ALRB.bits.AMENB = State ? 1U : 0U;
}

/**
 * @brief 配置RTC闹钟中断小时时间
 * @param Module 指向寄存器的指针
 * @param Hour 传入参数设置时间, 0 ~ 23
 * @retval void
 */
KF_INLINE void Rtc_LL_SetAlarmBHourTime(Rtc_RegisterMap_t *const Module, Rtc_Hour_t Hour)
{
    KF_RTC_ASSERT(CHECK_RTC_ALL_PERIPH_ADDR(Module));
    KF_RTC_ASSERT(CHECK_RTC_HOUR(Hour));

    Module->ALRB.bits.ALRHB = (uint32_t)Hour;
}

/**
 * @brief 配置RTC 12小时制闹钟A的上午下午选择
 * @param Module 指向寄存器的指针
 * @param Option 选择参数
 *          true 选择下午时间
 *          false 选择上午时间
 * @retval void
 */
KF_INLINE void Rtc_LL_SelectAlarmBAmPm(Rtc_RegisterMap_t *const Module, bool Option)
{
    KF_RTC_ASSERT(CHECK_RTC_ALL_PERIPH_ADDR(Module));

    Module->ALRB.bits.AMPMB = Option ? 1U : 0U;
}

/**
 * @brief: 闹钟小时使能/禁止设置
 * @param Module: RTC寄存器结构体指针
 * @param State
 *          true 使能闹钟小时
 *          false 禁止闹钟小时
 * @retval 无
 */
KF_INLINE void Rtc_LL_SetAlarmBHourEnabled(Rtc_RegisterMap_t *const Module, bool State)
{
    KF_RTC_ASSERT(CHECK_RTC_ALL_PERIPH_ADDR(Module));

    Module->ALRB.bits.AHENB = State ? 1U : 0U;
}

/**
 * @brief 配置RTC闹钟使能
 * @param Module 指向寄存器的指针
 * @param WeekDay 设置闹钟中断星期时间,具体值见枚举$RTC_WeekDay_t$
 * @retval void
 */
KF_INLINE void Rtc_LL_SetAlarmBWeekTime(Rtc_RegisterMap_t *const Module, Rtc_WeekDay_t WeekDay)
{
    KF_RTC_ASSERT(CHECK_RTC_ALL_PERIPH_ADDR(Module));
    KF_RTC_ASSERT(CHECK_RTC_WEEKDAY(WeekDay));

    Module->ALRB.bits.ALRWB = (uint32_t)WeekDay;
}

/**
 * @brief: 闹钟星期使能/禁止设置
 * @param Module: RTC寄存器结构体指针
 * @param State
 *          true 使能闹钟星期
 *          false 禁止闹钟星期
 * @retval 无
 */
KF_INLINE void Rtc_LL_SetAlarmBWeekdayEnabled(Rtc_RegisterMap_t *const Module, bool State)
{
    KF_RTC_ASSERT(CHECK_RTC_ALL_PERIPH_ADDR(Module));

    Module->ALRB.bits.AWENB = State ? 1U : 0U;
}

/**
 * @brief: 闹钟使能/禁止设置
 * @param Module: RTC寄存器结构体指针
 * @param State
 *          true 使能闹钟秒钟位
 *          false 禁止闹钟秒钟位
 * @retval 无
 */
KF_INLINE void Rtc_LL_SetAlarmBEnabled(Rtc_RegisterMap_t *const Module, bool State)
{
    KF_RTC_ASSERT(CHECK_RTC_ALL_PERIPH_ADDR(Module));

    Module->ALRB.bits.ALRENB = State ? 1U : 0U;
}

/**
 * @brief: 设置RTC时钟秒钟
 * @param Module: RTC寄存器结构体指针
 * @param Second: 秒钟值(0~59)
 * @retval 无
 */
KF_INLINE void Rtc_LL_SetSeconds(Rtc_RegisterMap_t *const Module, Rtc_Second_t Second)
{
    KF_RTC_ASSERT(CHECK_RTC_ALL_PERIPH_ADDR(Module));
    KF_RTC_ASSERT(CHECK_RTC_SECOND(Second));

    Module->TMR.bits.SEC = (uint32_t)Second;
}

/**
 * @brief: 设置RTC时钟分钟
 * @param Module: RTC寄存器结构体指针
 * @param Minute: 分钟值(0~59)
 * @retval 无
 */
KF_INLINE void Rtc_LL_SetMinutes(Rtc_RegisterMap_t *const Module, Rtc_Minute_t Minute)
{
    KF_RTC_ASSERT(CHECK_RTC_ALL_PERIPH_ADDR(Module));
    KF_RTC_ASSERT(CHECK_RTC_MINUTE(Minute));

    Module->TMR.bits.MIN = (uint32_t)Minute;
}

/**
 * @brief: 设置RTC时钟小时
 * @param Module: RTC寄存器结构体指针
 * @param Hour: 小时值(0~23)
 * @retval 无
 */

KF_INLINE void Rtc_LL_SetHours(Rtc_RegisterMap_t *const Module, Rtc_Hour_t Hour)
{
    KF_RTC_ASSERT(CHECK_RTC_ALL_PERIPH_ADDR(Module));
    KF_RTC_ASSERT(CHECK_RTC_HOUR(Hour));

    Module->TMR.bits.HOUR = (uint32_t)Hour;
}
/**
 * @brief: 设置RTC时钟星期
 * @param Module: RTC寄存器结构体指针
 * @param Week: 星期值(1~7)
 * @retval 无
 */
KF_INLINE void Rtc_LL_SetWeek(Rtc_RegisterMap_t *const Module, Rtc_WeekDay_t Week)
{
    KF_RTC_ASSERT(CHECK_RTC_ALL_PERIPH_ADDR(Module));
    KF_RTC_ASSERT(CHECK_RTC_WEEKDAY(Week));

    Module->TMR.bits.WEK = (uint32_t)Week;
}

/**
 * @brief 配置RTC闹钟为AM/PM
 * @param Module 指向寄存器的指针
 * @param Option 传入参数设置24小时制或12小时制
 *          true -- PM,下午
 *          false -- AM,上午
 * @retval void
 */
KF_INLINE void Rtc_LL_SetAmPm(Rtc_RegisterMap_t *const Module, bool Option)
{
    KF_RTC_ASSERT(CHECK_RTC_ALL_PERIPH_ADDR(Module));

    Module->TMR.bits.AMPM = Option ? 1U : 0U;
}

/**
 * @brief: 设置RTC时钟日期
 * @param Module: RTC寄存器结构体指针
 * @param Day: RTC时钟日期(0-30)
 * @retval 无
 */
KF_INLINE void Rtc_LL_SetDay(Rtc_RegisterMap_t *const Module, Rtc_Day_t Day)
{
    KF_RTC_ASSERT(CHECK_RTC_ALL_PERIPH_ADDR(Module));
    KF_RTC_ASSERT(CHECK_RTC_DAY(Day));

    Module->DTR.bits.DAY = (uint32_t)Day;
}

/**
 * @brief: 设置RTC时钟月份
 * @param Module: RTC寄存器结构体指针
 * @param Month: RTC时钟月份(0-11)
 * @retval 无
 */
KF_INLINE void Rtc_LL_SetMonth(Rtc_RegisterMap_t *const Module, Rtc_Month_t Month)
{
    KF_RTC_ASSERT(CHECK_RTC_ALL_PERIPH_ADDR(Module));
    KF_RTC_ASSERT(CHECK_RTC_MONTH(Month));

    Module->DTR.bits.MTH = (uint32_t)Month;
}

/**
 * @brief: 设置RTC时钟年份
 * @param Module: RTC寄存器结构体指针
 * @param Year: RTC时钟年份
 * @retval 无
 */
KF_INLINE void Rtc_LL_SetYear(Rtc_RegisterMap_t *const Module, uint8_t Year)
{
    KF_RTC_ASSERT(CHECK_RTC_ALL_PERIPH_ADDR(Module));

    Module->DTR.bits.YEAR = Year;
}

/**
 * @brief 配置RTC定时器0计数值
 * @param Module 指向寄存器的指针
 * @param Count 传入参数设置定时器0计数值
 * @retval void
 */
KF_INLINE void Rtc_LL_SetTimer0Count(Rtc_RegisterMap_t *const Module, uint16_t Count)
{
    KF_RTC_ASSERT(CHECK_RTC_ALL_PERIPH_ADDR(Module));

    Module->TMER.bits.TMR0 = (uint32_t)Count;
}

/**
 * @brief 配置RTC定时器1计数值
 * @param Module 指向寄存器的指针
 * @param Count 传入参数设置定时器1计数值
 * @retval void
 */
KF_INLINE void Rtc_LL_SetTimer1Count(Rtc_RegisterMap_t *const Module, uint16_t Count)
{
    KF_RTC_ASSERT(CHECK_RTC_ALL_PERIPH_ADDR(Module));

    Module->TMER.bits.TMR1 = (uint32_t)Count;
}

/**
 * @brief: 设置定时器 0 使能位
 * @param Module: RTC寄存器结构体指针
 * @param State: 定时器 0 使能位
 *                   true 使能TMR0
 *                   false 禁止TMR0
 * @retval 无
 */
KF_INLINE void Rtc_LL_SetTimer0Enabled(Rtc_RegisterMap_t *const Module, bool State)
{
    KF_RTC_ASSERT(CHECK_RTC_ALL_PERIPH_ADDR(Module));

    Module->TCR.bits.TMR0EN = State ? 1U : 0U;
}

/**
 * @brief: 设置定时器 1 使能位
 * @param Module: RTC寄存器结构体指针
 * @param State: 定时器 1 使能位
 *                   true 使能TMR1
 *                   false 禁止TMR1
 * @retval 无
 */
KF_INLINE void Rtc_LL_SetTimer1Enabled(Rtc_RegisterMap_t *const Module, bool State)
{
    KF_RTC_ASSERT(CHECK_RTC_ALL_PERIPH_ADDR(Module));

    Module->TCR.bits.TMR1EN = State ? 1U : 0U;
}

/**
 * @brief: 设置定时器 0 时钟源选择位
 * @param Module: RTC寄存器结构体指针
 * @param TimerClkSrc: 定时器 0 时钟源选择位, 可见 Rtc_TmrClkSrc_t
 * @retval 无
 */
KF_INLINE void Rtc_LL_SetTimer0ClockSource(Rtc_RegisterMap_t *const Module, Rtc_TmrClkSrc_t TimerClkSrc)
{
    KF_RTC_ASSERT(CHECK_RTC_ALL_PERIPH_ADDR(Module));
    KF_RTC_ASSERT(CHECK_RTC_TMRCLKSRC(TimerClkSrc));

    Module->TCR.bits.TMR0C = (uint32_t)TimerClkSrc;
}

/**
 * @brief: 设置定时器 1 时钟源选择位
 * @param Module: RTC寄存器结构体指针
 * @param TimerClkSrc: 定时器 1 时钟源选择位, 可见 Rtc_TmrClkSrc_t
 * @retval 无
 */
KF_INLINE void Rtc_LL_SetTimer1ClockSource(Rtc_RegisterMap_t *const Module, Rtc_TmrClkSrc_t TimerClkSrc)
{
    KF_RTC_ASSERT(CHECK_RTC_ALL_PERIPH_ADDR(Module));
    KF_RTC_ASSERT(CHECK_RTC_TMRCLKSRC(TimerClkSrc));

    Module->TCR.bits.TMR1C = (uint32_t)TimerClkSrc;
}

/**
 * @brief 设置Rtc中断使能
 * @param Module RTC寄存器结构体指针
 * @param IntIndex 设置中断序号, 可见 Rtc_IntrSetIndex_t
 * @retval None
 */
KF_INLINE void Rtc_LL_SetIntrEnabled(Rtc_RegisterMap_t *const Module, Rtc_IntrSetIndex_t IntIndex, bool State)
{
    KF_RTC_ASSERT(CHECK_RTC_ALL_PERIPH_ADDR(Module));
    KF_RTC_ASSERT(CHECK_RTC_INTRSETINDEX(IntIndex));

    /* PRQA S 3473 2 #KQR003473 */
    REG_BITS_WRITE(
        Module->IER.reg, ((uint32_t)1U << ((uint32_t)IntIndex)), (uint32_t)(State ? 1U : 0U) << (uint32_t)IntIndex);
}

/**
 * @brief 获取RTC中断使能状态
 * @param Module RTC寄存器结构体指针
 * @param IntIndex Rtc_IntrSetIndex_t
 * @retval
 */
KF_INLINE bool Rtc_LL_GetIntrEnabledState(const Rtc_RegisterMap_t *const Module, Rtc_IntrSetIndex_t IntIndex)
{
    KF_RTC_ASSERT(CHECK_RTC_ALL_PERIPH_ADDR(Module));
    KF_RTC_ASSERT(CHECK_RTC_INTRSETINDEX(IntIndex));

    /* PRQA S 3469 1 #KQR003469 */
    return (REG_BITS_READ(Module->IER.reg, ((uint32_t)1U << (uint32_t)IntIndex), (uint32_t)IntIndex) != 0U);
}

/**
 * @brief 清零Rtc中断
 * @param Module RTC寄存器结构体指针
 * @param IntIndex 清除中断序号, 可见 Rtc_IntrClearIndex_t
 * @retval None
 */
KF_INLINE void Rtc_LL_ClearIntrFlag(Rtc_RegisterMap_t *const Module, Rtc_IntrClearIndex_t IntIndex)
{
    KF_RTC_ASSERT(CHECK_RTC_ALL_PERIPH_ADDR(Module));
    KF_RTC_ASSERT(CHECK_RTC_INTRCLEARINDEX(IntIndex));

    /* PRQA S 3473 ++ #KQR003473 */
    REG_BIT_SET(Module->IFR.reg, (uint32_t)1U << (uint32_t)IntIndex);
    NOP();
    NOP();
    NOP();
    NOP();
    REG_BIT_CLR(Module->IFR.reg, (uint32_t)1U << (uint32_t)IntIndex);
    /* PRQA S 3473 -- #KQR003473 */
}

/**
 * @brief Get Rtc Module Flag Status
 * @param Module 指向SPI寄存器结构的指针
 * @param FlagOffset Rtc_IntFlag_t
 * @retval
 */
KF_INLINE bool Rtc_LL_GetIntrFlag(const Rtc_RegisterMap_t *const Module, Rtc_IntrGetIndex_t IntIndex)
{
    KF_RTC_ASSERT(CHECK_RTC_ALL_PERIPH_ADDR(Module));
    KF_RTC_ASSERT(CHECK_RTC_INTRGETINDEX(IntIndex));

    /* PRQA S 3469 1 #KQR003469 */
    return (REG_BITS_READ(Module->IFR.reg, ((uint32_t)1U << (uint32_t)IntIndex), (uint32_t)IntIndex) != 0U);
}

/**
 * @brief 获取时钟星期备份
 * @param Module 指向寄存器的地址
 * @retval Rtc_WeekDay_t 周
 */
KF_INLINE Rtc_WeekDay_t Rtc_LL_GetWeekBackup(Rtc_RegisterMap_t const *const Module)
{
    KF_RTC_ASSERT(CHECK_RTC_ALL_PERIPH_ADDR(Module));

    return (Rtc_WeekDay_t)Module->TMBR.bits.WEKB;
}

/**
 * @brief 获取时钟AM/PM备份
 * @param Module 指向寄存器的地址
 * @retval bool AM/PM备份
 */
KF_INLINE bool Rtc_LL_GetAmPmBackup(Rtc_RegisterMap_t const *const Module)
{
    KF_RTC_ASSERT(CHECK_RTC_ALL_PERIPH_ADDR(Module));

    return (Module->TMBR.bits.AMPMB != 0U);
}

/**
 * @brief 获取RTC时钟时钟备份
 * @param Module 指向寄存器的地址
 * @retval Rtc_Hour_t 小时
 */
KF_INLINE Rtc_Hour_t Rtc_LL_GetHourBackup(Rtc_RegisterMap_t const *const Module)
{
    KF_RTC_ASSERT(CHECK_RTC_ALL_PERIPH_ADDR(Module));

    return (Rtc_Hour_t)Module->TMBR.bits.HOURB;
}

/**
 * @brief 获取RTC时钟分钟备份
 * @param Module 指向寄存器的地址
 * @retval Rtc_Minute_t 分
 */

KF_INLINE Rtc_Minute_t Rtc_LL_GetMinutesBackup(Rtc_RegisterMap_t const *const Module)
{
    KF_RTC_ASSERT(CHECK_RTC_ALL_PERIPH_ADDR(Module));

    return (Rtc_Minute_t)Module->TMBR.bits.MINB;
}
/**
 * @brief 获取RTC时钟秒钟百分
 * @param Module 指向寄存器的指针
 * @retval Rtc_Second_t 秒钟
 */
KF_INLINE Rtc_Second_t Rtc_LL_GetSecondBackup(Rtc_RegisterMap_t const *const Module)
{
    KF_RTC_ASSERT(CHECK_RTC_ALL_PERIPH_ADDR(Module));

    return (Rtc_Second_t)Module->TMBR.bits.SECB;
}

/**
 * @brief 获取RTC时钟年份备份
 * @param Module 指向寄存器的地址
 * @retval uint8_t 年份
 */
KF_INLINE uint8_t Rtc_LL_GetYearBackup(Rtc_RegisterMap_t const *const Module)
{
    KF_RTC_ASSERT(CHECK_RTC_ALL_PERIPH_ADDR(Module));

    return (uint8_t)Module->DTBR.bits.YEARB;
}

/**
 * @brief 获取RTC时钟月份备份
 * @param Module 指向寄存器的地址
 * @retval Rtc_Month_t 月
 */
KF_INLINE Rtc_Month_t Rtc_LL_GetMonthBackup(Rtc_RegisterMap_t const *const Module)
{
    KF_RTC_ASSERT(CHECK_RTC_ALL_PERIPH_ADDR(Module));

    return (Rtc_Month_t)Module->DTBR.bits.MTHB;
}

/**
 * @brief RTC时钟日期备份
 * @param Module 指向寄存器的地址
 * @retval Rtc_Day_t 天
 */
KF_INLINE Rtc_Day_t Rtc_LL_GetDayBackup(Rtc_RegisterMap_t const *const Module)
{
    KF_RTC_ASSERT(CHECK_RTC_ALL_PERIPH_ADDR(Module));

    return (Rtc_Day_t)Module->DTBR.bits.DAYB;
}

/**
 * @brief RTC年快速测试使能位
 *
 * @param Module 指向寄存器的指针
 * @param State 使能状态
 * @retval void
 */
KF_INLINE void Rtc_LL_SetYearFastTestEnabled(Rtc_RegisterMap_t *const Module, bool State)
{
    KF_RTC_ASSERT(CHECK_RTC_ALL_PERIPH_ADDR(Module));

    Module->FASTTEST.bits.YEARTESTEN = State ? 1U : 0U;
}

/**
 * @brief RTC月快速测试使能位
 *
 * @param Module 指向寄存器的指针
 * @param State 使能状态
 * @retval void
 */
KF_INLINE void Rtc_LL_SetMonthFastTestEnabled(Rtc_RegisterMap_t *const Module, bool State)
{
    KF_RTC_ASSERT(CHECK_RTC_ALL_PERIPH_ADDR(Module));

    Module->FASTTEST.bits.MONTHTESTEN = State ? 1U : 0U;
}

/**
 * @brief RTC周快速测试使能位
 *
 * @param Module 指向寄存器的指针
 * @param State 使能状态
 * @retval void
 */
KF_INLINE void Rtc_LL_SetWeekFastTestEnabled(Rtc_RegisterMap_t *const Module, bool State)
{
    KF_RTC_ASSERT(CHECK_RTC_ALL_PERIPH_ADDR(Module));

    Module->FASTTEST.bits.WEEKTESTEN = State ? 1U : 0U;
}

/**
 * @brief RTC天快速测试使能位
 *
 * @param Module 指向寄存器的指针
 * @param State 使能状态
 * @retval void
 */
KF_INLINE void Rtc_LL_SetDayFastTestEnabled(Rtc_RegisterMap_t *const Module, bool State)
{
    KF_RTC_ASSERT(CHECK_RTC_ALL_PERIPH_ADDR(Module));

    Module->FASTTEST.bits.DAYTESTEN = State ? 1U : 0U;
}

/**
 * @brief RTC小时快速测试使能位
 *
 * @param Module 指向寄存器的指针
 * @param State 使能状态
 * @retval void
 */
KF_INLINE void Rtc_LL_SetHourFastTestEnabled(Rtc_RegisterMap_t *const Module, bool State)
{
    KF_RTC_ASSERT(CHECK_RTC_ALL_PERIPH_ADDR(Module));

    Module->FASTTEST.bits.HOURTESTEN = State ? 1U : 0U;
}

/**
 * @brief RTC分钟快速测试使能位
 *
 * @param Module 指向寄存器的指针
 * @param State 使能状态
 * @retval void
 */
KF_INLINE void Rtc_LL_SetMinutesFastTestEnabled(Rtc_RegisterMap_t *const Module, bool State)
{
    KF_RTC_ASSERT(CHECK_RTC_ALL_PERIPH_ADDR(Module));

    Module->FASTTEST.bits.MINTESTEN = State ? 1U : 0U;
}

/**
 * @brief RTC快速测试总使能位
 *
 * @param Module 指向寄存器的指针
 * @param State 使能状态
 * @retval void
 */
KF_INLINE void Rtc_LL_SetFastTestEnabled(Rtc_RegisterMap_t *const Module, bool State)
{
    KF_RTC_ASSERT(CHECK_RTC_ALL_PERIPH_ADDR(Module));

    Module->FASTTEST.bits.FASTTESTEN = State ? 1U : 0U;
}

#ifdef __cplusplus
}
#endif /*End of __cplusplus*/
#endif /*End of KF32A158SF_DRV_RTC_H*/
/* EOF */
