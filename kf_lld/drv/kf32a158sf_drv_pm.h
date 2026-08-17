/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name        : kf32a158sf_drv_pm.h
 *  @Date             : 2025-07-08
 *  @Version          : {{VersionDate}}
 *  @Description      : This file provides PM driver.
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
#ifndef KF32A158SF_DRV_PM_H
#define KF32A158SF_DRV_PM_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 *                      QAC Warnings
 ******************************************************************************/
/* PRQA S 3205 EOF #KQR003205 */
/* PRQA S 3219 EOF #KQR003219 */
/* PRQA S 3473 EOF #KQR003473 */

/******************************************************************************
 *                      Include Files
 ******************************************************************************/
#include "kf32a158sf_reg_pm.h"

/******************************************************************************
 *                      Macro or Inline
 ******************************************************************************/
#ifdef KF_DRV_PM_ASSERT
#include "dev_assert.h"
#define KF_PM_ASSERT(x) KF_DEV_ASSERT(x)
#else
#define KF_PM_ASSERT(x) ((void)0U)
#endif

#define PM_CAL0_BGTRIMMRLDO_POS  (5)
#define PM_CAL0_BGTRIMMRLDO_MASK ((uint32_t)0x1F << (PM_CAL0_BGTRIMMRLDO_POS))

/******************************************************************************
 *                      Type definitions
 ******************************************************************************/

/** @brief 低功耗类型*/
typedef enum
{
    PM_LOW_POWER_STOP_0  = 1U,
    PM_LOW_POWER_STANDBY = 3U,
} Pm_LowPowerMode_t;
#define CHECK_PM_LOWPOWERMODE(x) (((x) == PM_LOW_POWER_STOP_0) || ((x) == PM_LOW_POWER_STANDBY))

typedef enum
{
    POR_DELAY_TIME_2MS  = 0,
    POR_DELAY_TIME_32US = 1
} Pm_PorDelayTime_t;
#define CHECK_PM_POR_DELAY_TIME(x) (((x) == POR_DELAY_TIME_2MS) || ((x) == POR_DELAY_TIME_32US))

typedef enum
{
    BKPPOR_DELAY_TIME_1MS  = 0,
    BKPPOR_DELAY_TIME_32US = 1
} Pm_BkpPorDelayTime_t;
#define CHECK_PM_BKPPOR_DELAY_TIME(x) (((x) == BKPPOR_DELAY_TIME_1MS) || ((x) == BKPPOR_DELAY_TIME_32US))

typedef enum
{
    PM_VOLTAGE_DETECTION_POINT_0,
    PM_VOLTAGE_DETECTION_POINT_1,
    PM_VOLTAGE_DETECTION_POINT_2,
    PM_VOLTAGE_DETECTION_POINT_3,
    PM_VOLTAGE_DETECTION_POINT_4,
    PM_VOLTAGE_DETECTION_POINT_5,
    PM_VOLTAGE_DETECTION_POINT_6,
} Pm_VolDetection_t;
#define CHECK_PM_VOLTAGE_DETECTION(x)                                                                                  \
    (((x) == PM_VOLTAGE_DETECTION_POINT_1) || ((x) == PM_VOLTAGE_DETECTION_POINT_2) ||                                 \
     ((x) == PM_VOLTAGE_DETECTION_POINT_3) || ((x) == PM_VOLTAGE_DETECTION_POINT_4) ||                                 \
     ((x) == PM_VOLTAGE_DETECTION_POINT_5) || ((x) == PM_VOLTAGE_DETECTION_POINT_6) ||                                 \
     ((x) == PM_VOLTAGE_DETECTION_POINT_0))

typedef enum
{
    PM_VREF_VOLTAGE_4P0V,
    PM_VREF_VOLTAGE_1P5V,
    PM_VREF_VOLTAGE_2P0V,
    PM_VREF_VOLTAGE_3P0V
} Pm_VrefVoltage_t;
#define CHECK_PM_VREF_VOLTAGE(x)                                                                                       \
    (((x) == PM_VREF_VOLTAGE_4P0V) || ((x) == PM_VREF_VOLTAGE_1P5V) || ((x) == PM_VREF_VOLTAGE_2P0V) ||                \
     ((x) == PM_VREF_VOLTAGE_3P0V))

typedef enum
{
    PM_OVD_VOLTAGE_5P5V     = 3u,
    PM_OVD_VOLTAGE_5P6V     = 4u,
    PM_OVD_VOLTAGE_5P7V     = 5u,
    PM_OVD_VOLTAGE_SELFTEST = 7u
} Pm_VddOvdVolLv_t;
#define CHECK_PM_OVD_VOLTAGE(x)                                                                                        \
    (((x) == PM_OVD_VOLTAGE_5P5V) || ((x) == PM_OVD_VOLTAGE_5P6V) || ((x) == PM_OVD_VOLTAGE_5P7V) ||                   \
     ((x) == PM_OVD_VOLTAGE_SELFTEST))

/**
 * @brief RTC TT_OUT唤醒分频选择
 * */
typedef enum
{
    PM_TTSEL_DIVISION_2  = 0U,
    PM_TTSEL_DIVISION_4  = 1U,
    PM_TTSEL_DIVISION_8  = 2U,
    PM_TTSEL_DIVISION_16 = 3U,
} Pm_TickTimeDiv_t;
#define CHECK_PM_TTSEL_DIVISION(x)                                                                                     \
    (((x) == PM_TTSEL_DIVISION_2) || ((x) == PM_TTSEL_DIVISION_4) || ((x) == PM_TTSEL_DIVISION_8) ||                   \
     ((x) == PM_TTSEL_DIVISION_16))

typedef enum
{
    PM_PIN_WKP1 = 0u,
    PM_PIN_WKP2 = 1u,
    PM_PIN_WKP3 = 2u,
    PM_PIN_WKP4 = 3u,
    PM_PIN_WKP5 = 4u
} Pm_WakeUp_t;
typedef enum
{
    PM_PIN_WKP6  = 5u,
    PM_PIN_WKP8  = 7u,
    PM_PIN_WKP10 = 9u,
    PM_PIN_WKP11 = 10u,
    PM_PIN_WKP12 = 11u
} Pm_WakeUp6To12_t;
#define CHECK_PM_WAKEUP_PIN(x)                                                                                         \
    (((x) == PM_PIN_WKP1) || ((x) == PM_PIN_WKP2) || ((x) == PM_PIN_WKP3) || ((x) == PM_PIN_WKP4) ||                   \
     ((x) == PM_PIN_WKP5))
#define CHECK_PM_WAKEUP6TO12_PIN(x)                                                                                    \
    (((x) == PM_PIN_WKP6) || ((x) == PM_PIN_WKP8) || ((x) == PM_PIN_WKP10) || ((x) == PM_PIN_WKP11) ||                 \
     ((x) == PM_PIN_WKP12))

typedef enum
{
    PM_TRIGGER_EDGE_RISE = 0u,
    PM_TRIGGER_EDGE_FALL = 1u,
} Pm_TrigEdge_t;
#define CHECK_PM_TRIGGER_EDGE(x) (((x) == PM_TRIGGER_EDGE_RISE) || ((x) == PM_TRIGGER_EDGE_FALL))

/**
 * @brief BOR电压点选择位
 * */
typedef enum
{
    PM_BOR_VOLTAGE_POINT_1 = 0U,
    PM_BOR_VOLTAGE_POINT_2 = 1U,
    PM_BOR_VOLTAGE_POINT_3 = 2U,
    PM_BOR_VOLTAGE_POINT_4 = 3U,
} Pm_BorVoltage_t;
#define CHECK_PM_BOR_VOLTAGE_SELECT(x)                                                                                 \
    (((x) == PM_BOR_VOLTAGE_POINT_1) || ((x) == PM_BOR_VOLTAGE_POINT_2) || ((x) == PM_BOR_VOLTAGE_POINT_3) ||          \
     ((x) == PM_BOR_VOLTAGE_POINT_4))

/**
 * @brief FVR参考电压
 */
typedef enum
{
    PM_FVR_VOLTAGE_4V,
    PM_FVR_VOLTAGE_3V,
    PM_FVR_VOLTAGE_2V,
    PM_FVR_VOLTAGE_1P5V,
} Pm_FvrVoltage_t;
#define CHECK_PM_FVR_VOLTAGE(x)                                                                                        \
    (((x) == PM_FVR_VOLTAGE_4V) || ((x) == PM_FVR_VOLTAGE_3V) || ((x) == PM_FVR_VOLTAGE_2V) ||                         \
     ((x) == PM_FVR_VOLTAGE_1P5V))

/**
 * @brief RTC TT_OUT 唤醒分频选择
 */
typedef enum
{
    PM_RTC_TICK_TIME_DIV_1,
    PM_RTC_TICK_TIME_DIV_2,
    PM_RTC_TICK_TIME_DIV_8,
    PM_RTC_TICK_TIME_DIV_16,
} Pm_RtcTickTimeDivision_t;
#define CHECK_PM_RTC_TICK_TIME_DIV(x)                                                                                  \
    (((x) == PM_RTC_TICK_TIME_DIV_1) || ((x) == PM_RTC_TICK_TIME_DIV_2) || ((x) == PM_RTC_TICK_TIME_DIV_8) ||          \
     ((x) == PM_RTC_TICK_TIME_DIV_16))

/******************************************************************************
 *                      Export Variables
 ******************************************************************************/

/******************************************************************************
 *                      Export Functions
 ******************************************************************************/

/**
 * @brief 低功耗模式选择
 *
 * @param LowPowerMode 低功耗模式, 可见 Pm_LowPowerMode_t
 * @retval void
 */
KF_INLINE void Pm_LL_SelectLowPowerMode(Pm_LowPowerMode_t LowPowerMode)
{
    KF_PM_ASSERT(CHECK_PM_LOWPOWERMODE(LowPowerMode));

    PM_PTR->CTL0.bits.LPMS = (uint32_t)LowPowerMode;
}

/**
 * @brief PMC模式下软件唤醒选择
 *
 * @param State PMC模式下软件唤醒使能状态, true 软件唤醒信号有效, false 软件唤醒信号无效
 * @retval void
 */
KF_INLINE void Pm_LL_SetSoftwareWakeupEnabled(bool State)
{
    PM_PTR->CTL0.bits.PMCWKPTESTSEL = State ? 1U : 0U;
}

/**
 * @brief 设置BOR电压点选择.
 * @param  Voltage: BOR电压点选择,取值为 Pm_BorVoltage_t
 * @retval void.
 */
KF_INLINE void Pm_LL_SelectBorVoltage(Pm_BorVoltage_t Voltage)
{
    KF_PM_ASSERT(CHECK_PM_BOR_VOLTAGE_SELECT(Voltage));

    PM_PTR->CTL0.bits.BORSEL = (uint32_t)Voltage;
}

/**
 * @brief 设置备份区读写操作允许使能.
 * @param State:
 *          true   允许CPU对备份区内寄存器进行读写
 *          false 禁止CPU对备份区内寄存器进行读写
 * @retval void.
 */
KF_INLINE void Pm_LL_SetBackupWriteAndReadEnabled(bool State)
{
    PM_PTR->CTL0.bits.BKPWR = State ? 1U : 0U;
}

/**
 * @brief 设置内部高振荡器软件使能.
 * @param State:
 *          true   软件使能内部高频振荡器
 *          false 软件未使能内部高频振荡器
 * @retval void.
 */
KF_INLINE void Pm_LL_SetInternalHighFrequencyEnabled(bool State)
{
    PM_PTR->CTL0.bits.HSIEN = State ? 1U : 0U;
}

/**
 * @brief BOR高速检测使能位
 * @param State:
 *          true   高速BOR检测
 *          false 低速BOR检测
 * @retval void
 */
KF_INLINE void Pm_LL_SetBorHiSpeedDetectionEnabled(bool State)
{
    PM_PTR->CTL0.bits.BORHSEN = State ? 1U : 0U;
}

/**
 * @brief FVR CAPLESS使能位
 * @param State:
 *          true   FVR CAPLESS使能
 *          false   FVR CAPLESS不使能
 * @retval void
 */
KF_INLINE void Pm_LL_SetFvrCaplessEnabled(bool State)
{
    PM_PTR->CTL0.bits.FVRCAPLESSEN = State ? 1U : 0U;
}

/**
 * @brief 获取 FVR CAPLESS使能状态
 *
 * @retval bool
 */
KF_INLINE bool Pm_LL_GetFvrCaplessEnabledState(void)
{

    return (PM_PTR->CTL0.bits.FVRCAPLESSEN != 0u);
}

/**
 * @brief FVR CAPLESS模式选择位
 * @param State:
 *          true   BUFFER模式
 *          false LDO模式
 * @retval void
 */
KF_INLINE void Pm_LL_SetFvrCaplessMode(bool State)
{

    PM_PTR->CTL0.bits.FVRCAPLESSMODE = State ? 1U : 0U;
}

/**
 * @brief 设置低功耗BOR唤醒使能位
 * @param State:
 *          true   使能低功耗BOR唤醒
 *          false  禁止低功耗BOR唤醒
 * @retval void
 */
KF_INLINE void Pm_LL_SetBORLowPowerWakeEnabled(bool State)
{
    PM_PTR->CTL0.bits.BORWKPEN = State ? 1U : 0U;
}

/**
 * @brief 设置IWDT模块产生复位后的工作模式.
 * @param State:
 *          true   发生IWDT复位时,IWDT模块不复位,继续保持工作状态
 *          false   发生IWDT复位时,将复位IWDT模块自身
 * @retval void.
 */
KF_INLINE void Pm_LL_SelectIwdgResetMode(bool State)
{
    PM_PTR->CTL0.bits.IWDTRMSEL = State ? 1U : 0U;
}

/**
 * @brief 设置LPRAM在在stop1和standby模式下工作配置.
 * @param Mode:
 *          0x0 LPRAM 在stop1和standby模式下掉电
 *          0x1 LPRAM0 在stop1和standby模式下保持数据
 *          0x2 LPRAM0/1 在stop1和standby模式下保持数据
 *          0x3 LPRAM0/1/2/3 在stop1和standby模式下保持数据
 * @retval void.
 */
KF_INLINE void Pm_LL_SetLpramWorkMode(uint32_t Mode)
{
    PM_PTR->CTL0.bits.LPRAMSEL = Mode & 0x3U;
}

/**
 * @brief 设置IWDT模块软件复位.
 * @param State:
 *          true   IWDT退出复位
 *          false IWDT处于复位状态
 * @retval void.
 */
KF_INLINE void Pm_LL_ExitIwdgReset(bool State)
{
    PM_PTR->CTL0.bits.IWDTCLR = State ? 1U : 0U;
}

/**
 * @brief 设置备份区寄存器模块软件复位.
 * @param State:
 *          true   备份区寄存器模块退出复位
 *          false 备份区寄存器模块处于复位状态
 * @retval void.
 */
KF_INLINE void Pm_LL_ExitBkpReset(bool State)
{
    PM_PTR->CTL0.bits.BKPREGCLR = State ? 1U : 0U;
}

/**
 * @brief 设置外部低频振荡器软件使能.
 * @param State:
 *          true   软件使能外部低频振荡器
 *          false 软件未使能外部低频振荡器
 * @retval void.
 */
KF_INLINE void Pm_LL_SetExternalLowFrequencyEnabled(bool State)
{
    PM_PTR->CTL0.bits.LSEEN = State ? 1U : 0U;
}

/**
 * @brief 设置内部低频振荡器软件使能.
 * @param State:
 *          true   软件使能内部低频振荡器
 *          false 软件未使能内部低频振荡器
 * @retval void.
 */
KF_INLINE void Pm_LL_SetInternalLowFrequencyEnabled(bool State)
{
    PM_PTR->CTL0.bits.LSIEN = State ? 1U : 0U;
}

/**
 * @brief 设置IO口状态锁存使能.
 * @param State:
 *          true   IO口状态被锁存
 *          false IO口状态未被锁存
 * @retval void.
 */
KF_INLINE void Pm_LL_SetIoLatchEnabled(bool State)
{
    PM_PTR->CTL0.bits.IOLATCH = State ? 1U : 0U;
}

/**
 * @brief 获取IO口状态锁存
 * @param  void
 * @retval true   IO口状态被锁存
 * @retval false IO口状态未被锁存
 */
KF_INLINE bool Pm_LL_GetIoLatchState(void)
{
    return (PM_PTR->CTL0.bits.IOLATCH == 1U);
}

/**
 * @brief 设置电压检测功能使能.
 * @param State:
 *        true   使能电压检测功能
 *        false 禁止电压检测功能
 * @retval void
 */
KF_INLINE void Pm_LL_SetVoltageDetectionEnabled(bool State)
{
    PM_PTR->CTL1.bits.PVDEN = State ? 1U : 0U;
}

/**
 * @brief 设置电压检测点选择.
 * @param Voltage: 电压检测点选择,取值为 Pm_VolDetection_t
 * @retval void.
 */
KF_INLINE void Pm_LL_SelectVoltageDetection(Pm_VolDetection_t Voltage)
{
    KF_PM_ASSERT(CHECK_PM_VOLTAGE_DETECTION(Voltage));

    PM_PTR->CTL1.bits.PVDS = (uint32_t)Voltage;
}

/**
 * @brief 设置内部固定参考电压 FVR2 电压值
 * @param Voltage: 内部FVR参考电压
 * @retval void
 */
KF_INLINE void Pm_LL_SelectFvr2Voltage(Pm_FvrVoltage_t Voltage)
{
    KF_PM_ASSERT(CHECK_PM_FVR_VOLTAGE(Voltage));

    PM_PTR->CTL1.bits.FVRMS = (uint32_t)Voltage;
}

/**
 * @brief 配置RAM 的 ECC 功能使能使能.
 * @param State:
 *        true   使能RAM的ECC功能
 *        false 禁止RAM的ECC功能
 * @retval void.
 */
KF_INLINE void Pm_LL_SetRamEccEnabled(bool State)
{
    PM_PTR->CTL1.bits.RAMECCEN = State ? 1U : 0U;
}

/**
 * @brief VDD_OVD输出中断使能
 * @param State:
 *        true   使能VDD_OVD中断
 *        false  禁止VDD_OVD中断
 * @retval void.
 */
KF_INLINE void Pm_LL_SetVddOvdIntrEnabled(bool State)
{

    PM_PTR->CTL1.bits.OVDIE = State ? 1U : 0U;
}

/**
 * @brief 设置VDD_OVD电压点选择.
 * @param Voltage: VDD_OVD电压点选择,取值为 Pm_VddOvdVolLv_t
 * @retval void.
 */
KF_INLINE void Pm_LL_SelectVddOvdVolLevel(Pm_VddOvdVolLv_t Voltage)
{
    KF_PM_ASSERT(CHECK_PM_OVD_VOLTAGE(Voltage));

    PM_PTR->CTL1.bits.VDDOVDSEL = (uint32_t)Voltage;
}

/**
 * @brief 设置VDD_OVD使能.
 * @param State:
 *          true   使能VDD_OVD
 *          false 禁止VDD_OVD
 * @retval void.
 */
KF_INLINE void Pm_LL_SetVddOvdEnabled(bool State)
{
    PM_PTR->CTL1.bits.VDDOVDEN = State ? 1U : 0U;
}

/**
 * @brief 内核电源监控使能
 * @param State:
 *        true   使能
 *        false 不使能
 * @retval void
 */
KF_INLINE void Pm_LL_SetCorePowerMonitorEnabled(bool State)
{
    PM_PTR->CTL1.bits.MONV12EN = State ? 1U : 0U;
}

/**
 * @brief FLASH电源监控使能
 * @param State:
 *        true   使能
 *        false 不使能
 * @retval void
 */
KF_INLINE void Pm_LL_SetFlashPowerMonitorEnabled(bool State)
{
    PM_PTR->CTL1.bits.MONV18EN = State ? 1U : 0U;
}

/**
 * @brief 内部测试输出 BUFFER 使能
 *
 * @param State 使能状态
 *        true   使能
 *        false 不使能
 * @return void
 */
KF_INLINE void Pm_LL_SetInternalBufferEnabled(bool State)
{
    PM_PTR->CTL1.bits.INTBUFEN = State ? 1U : 0U;
}

/**
 * @brief 温度传感器输出使能
 *
 * @param State 使能状态
 *        true   使能
 *        false 不使能
 * @return void
 */
KF_INLINE void Pm_LL_SetTemperatureSensorOutputEnabled(bool State)
{
    PM_PTR->CTL1.bits.TSOE = State ? 1U : 0U;
}

/**
 * @brief 温度传感器使能
 *
 * @param State 使能状态
 *        true   使能
 *        false 不使能
 * @return void
 */
KF_INLINE void Pm_LL_SetTemperatureSensorEnabled(bool State)
{
    PM_PTR->CTL1.bits.TSEN = State ? 1U : 0U;
}

/**
 * @brief 设置电压检测唤醒使能.
 * @param State:
 *        true   使能电压检测唤醒功能
 *        false  禁止电压检测唤醒功能
 * @retval void.
 */
KF_INLINE void Pm_LL_SetVoltageDetectionWakeUpEnabled(bool State)
{
    PM_PTR->CTL1.bits.PVDWKEN = State ? 1U : 0U;
}

/**
 * @brief 设置BOR使能,并同时使能BOR唤醒.
 * @param State:
 *          true   使能BOR
 *          false 禁止BOR
 * @retval void.
 */
KF_INLINE void Pm_LL_SetBorEnabled(bool State)
{
    PM_PTR->CTL1.bits.BOREN    = State ? 1U : 0U;
    PM_PTR->CTL0.bits.BORWKPEN = State ? 1U : 0U;
}

/**
 * @brief 配置低功耗 T0 复位控制
 * @param State:
 *        true   使能T0(退出复位)
 *        false 失能T0(处于复位状态)
 * @retval void.
 */
KF_INLINE void Pm_LL_SetLowPowerT0Enabled(bool State)
{
    PM_PTR->CTL2.bits.T0LPEN = State ? 1U : 0U;
}

/**
 * @brief 配置低功耗 T0 时钟控制
 * @param State:
 *        true   使能T0时钟
 *        false 失能T0时钟
 * @retval void.
 */
KF_INLINE void Pm_LL_SetLowPowerT0ClockEnabled(bool State)
{
    PM_PTR->CTL2.bits.T0CLKLPEN = State ? 1U : 0U;
}

/**
 * @brief 配置RTC TT_OUT 唤醒分频
 * @param Division: 分频系数
 *        Pm_RtcTickTimeDivision_t
 * @retval void.
 */
KF_INLINE void Pm_LL_SetRtcTickTimeOutputDivision(Pm_RtcTickTimeDivision_t Division)
{
    PM_PTR->CTL2.bits.TTSEL = (uint32_t)Division;
}

/**
 * @brief 配置RTC TT_OUT 唤醒分频使能
 * @param State: 使能状态
 *         true: 使能
 *         false: 禁止
 * @retval void.
 */
KF_INLINE void Pm_LL_SetRtcTickTimeOutputDivisionEnabled(bool State)
{
    PM_PTR->CTL2.bits.TTPRESEN = State ? 1U : 0U;
}

/**
 * @brief 配置RTC TT_OUT 唤醒使能
 * @param State: 使能状态
 *         true: 使能
 *         false: 禁止
 * @retval void.
 */
KF_INLINE void Pm_LL_SetRtcTickTimeOutputWakeup(bool State)
{
    PM_PTR->CTL2.bits.TTWKPEN = State ? 1U : 0U;
}

/**
 * @brief 配置低功耗 Gpio 复位控制
 * @param State:
 *        true   使能Gpio(退出复位)
 *        false 失能Gpio(处于复位状态)
 * @retval void.
 */
KF_INLINE void Pm_LL_SetLowPowerGpioEnabled(bool State)
{
    PM_PTR->CTL2.bits.GPIOALPEN = State ? 1U : 0U;
}

/**
 * @brief 设置PMC错误状态中断使能
 * @param State:
 *          true   使能PMC错误状态中断
 *          false 禁止PMC错误状态中断
 * @retval void.
 */
KF_INLINE void Pm_LL_SetPmcErrorIntrEnabled(bool State)
{

    PM_PTR->CTL2.bits.PMCIE = State ? 1U : 0U;
}

/**
 * @brief 设置外部唤醒引脚WKPx唤醒触发沿.
 * @param PinIndex: 唤醒引脚,取值为 Pm_WakeUp_t
 * @param TriggerEdge: 外部唤醒引脚WKPx唤醒触发沿,取值为 Pm_TrigEdge_t
 * @retval void.
 */
KF_INLINE void Pm_LL_SetExternalWakeupEdge(Pm_WakeUp_t PinIndex, Pm_TrigEdge_t TriggerEdge)
{
    KF_PM_ASSERT(CHECK_PM_WAKEUP_PIN(PinIndex));
    KF_PM_ASSERT(CHECK_PM_TRIGGER_EDGE(TriggerEdge));

    uint32_t TargetIndex;

    TargetIndex = (uint32_t)PinIndex + 22U;
    REG_BITS_WRITE(
        PM_PTR->CTL2.reg, (1UL << (uint32_t)TargetIndex), (uint32_t)((uint32_t)TriggerEdge << (uint32_t)TargetIndex));
}

/**
 * @brief 设置外部唤醒引脚WKPx使能.
 * @param PinSelIdx: 唤醒引脚,取值为 Pm_WakeUp_t
 * @param State:
 *          true   使能WKUPx电平变化唤醒
 *          false 禁止WKUPx电平变化唤醒
 * @retval void.
 */
KF_INLINE void Pm_LL_SetExternalWakeupPinEnabled(Pm_WakeUp_t PinIndex, bool State)
{
    KF_PM_ASSERT(CHECK_PM_WAKEUP_PIN(PinIndex));

    uint32_t TargetIndex;

    TargetIndex = (uint32_t)PinIndex + 27U;
    REG_BITS_WRITE(PM_PTR->CTL2.reg, (1UL << (uint32_t)TargetIndex), ((State ? 1UL : 0UL) << (uint32_t)TargetIndex));
}

/**
 * @brief 获取低功耗电压调制器LPR状态.
 * @param  void
 * @retval true   低功耗电压调制器LPR已使能完成
 * @retval false 低功耗电压调制器LPR未使能完成
 */
KF_INLINE bool Pm_LL_GetLprState(void)
{
    return (PM_PTR->STA0.bits.LPRSTA != 0U);
}

/**
 * @brief 获取低功耗运行模式状态标志.
 * @param void.
 * @retval true   电压调制器切换至LPR
 * @retval false 主电压调制器MR已使能完成
 */
KF_INLINE bool Pm_LL_GetLowPowerRunningState(void)
{
    return (PM_PTR->STA0.bits.LPRUNF != 0U);
}

/**
 * @brief 窗口看门狗 复位状态标志位
 * @param  void
 * @retval true   发生了复位事件
 * @retval false 未发生复位事件
 */
KF_INLINE bool Pm_LL_GetWwdgResetFlag(void)
{
    return (PM_PTR->STA0.bits.WWDTF != 0U);
}

/**
 * @brief 获取BKP电源上电复位标志位1.
 * @param  void
 * @retval true   产生了BKP电源上电复位
 * @retval false 未产生BKP电源上电复位
 */
KF_INLINE bool Pm_LL_GetBkpPorResetFlag(void)
{
    return (PM_PTR->STA0.bits.BKPPORIF != 0U);
}

/**
 * @brief 清零BKPPORIF标志
 * @param  void
 * @retval void
 */
KF_INLINE void Pm_LL_ClearBkpPorResetFlag(void)
{
    PM_PTR->STA0.bits.BKPPORIF = 0U;
}

/**
 * @brief 获取外部复位引脚复位标志位.
 * @param  void
 * @retval true   产生了复位
 * @retval false 未产生复位
 */
KF_INLINE bool Pm_LL_GetNrstIntrFlag(void)
{
    return (PM_PTR->STA0.bits.NRSTIF != 0U);
}

/**
 * @brief 获取上电复位标志位1.
 * @param  void
 * @retval true   产生了上电复位
 * @retval false 未产生上电复位
 */
KF_INLINE bool Pm_LL_GetPowerOnResetFlag(void)
{
    return (PM_PTR->STA0.bits.PORIF != 0U);
}

/**
 * @brief 清零PORIF标志
 * @param  void
 * @retval void
 */
KF_INLINE void Pm_LL_ClearPowerOnResetFlag(void)
{
    PM_PTR->STA0.bits.PORIF = 0U;
}

/**
 * @brief 软件复位状态标志位
 * @param  void
 * @retval true   发生了复位事件
 * @retval false 未发生复位事件
 */
KF_INLINE bool Pm_LL_GetSoftwareResetFlag(void)
{
    return (PM_PTR->STA0.bits.WSRSTF != 0U);
}

/**
 * @brief BOR复位状态标志位
 * @param  void
 * @retval true   发生了复位事件
 * @retval false 未发生复位事件
 */
KF_INLINE bool Pm_LL_GetBorResetFlag(void)
{
    return (PM_PTR->STA0.bits.BORF != 0U);
}

/**
 * @brief POR复位状态标志位
 * @param  void
 * @retval true   发生了复位事件
 * @retval false 未发生复位事件
 */
KF_INLINE bool Pm_LL_GetPorResetFlag(void)
{
    return (PM_PTR->STA0.bits.PORF == 1U);
}

/**
 * @brief WKUP PIN复位状态标志位
 * @param  void
 * @retval true   发生了复位事件
 * @retval false 未发生复位事件
 */
KF_INLINE bool Pm_LL_GetWkupPinWakeupFlag(void)
{
    return (PM_PTR->STA0.bits.WKPPINF == 1U);
}

/**
 * @brief RTC闹钟复位状态标志位
 * @param  void
 * @retval true   发生了复位事件
 * @retval false 未发生复位事件
 */
KF_INLINE bool Pm_LL_GetRtcAlarmWakeupFlag(void)
{
    return (PM_PTR->STA0.bits.RTCALRF == 1U);
}

/**
 * @brief 独立看门狗 复位状态标志位
 * @param  void
 * @retval true   发生了复位事件
 * @retval false 未发生复位事件
 */
KF_INLINE bool Pm_LL_GetIwdgResetFlag(void)
{
    return (PM_PTR->STA0.bits.IWDTF == 1U);
}

/**
 * @brief 复位/唤醒状态标志位清零
 * @param void
 * @retval void
 */
KF_INLINE void Pm_LL_ClearRstAndWakeupFlag(void)
{
    PM_PTR->STA0.bits.RSTFC = 1U;
    NOP();
    NOP();
    NOP();
    NOP();
    PM_PTR->STA0.bits.RSTFC = 0U;
}

/**
 * @brief 获取电压检测状态.
 * @param  void
 * @retval true  VDD电压低于PVD电压点
 * @retval false VDD电压高于PVD电压点
 */
KF_INLINE bool Pm_LL_GetPvdState(void)
{
    return (PM_PTR->STA1.bits.PVDSTA == 1U);
}

/**
 * @brief 获取WakeUp唤醒引脚标志.
 * @param PinSelIdx: 唤醒引脚,取值为 Pm_WakeUp6To12_t
 * @retval true   引脚发生唤醒事件
 * @retval false 引脚未发生唤醒事件
 */
KF_INLINE bool Pm_LL_GetWakeup6To12PinState(Pm_WakeUp6To12_t PinIndex)
{
    KF_PM_ASSERT(CHECK_PM_WAKEUP6TO12_PIN(PinIndex));
    uint32_t Pos;

    Pos = ((uint32_t)PinIndex - (uint32_t)PM_PIN_WKP6) + 11U;
    /* PRQA S 3469 1 #KQR003469 */
    return (REG_BITS_READ(PM_PTR->STA1.reg, (1UL << Pos), Pos) != 0U);
}

/**
 * @brief 获取STOP 模式进进入错误中断标志
 * @param  void
 * @retval true  进入 STOP 模式时存在唤醒条件
 * @retval false 正常进入了STOP 模式
 */
KF_INLINE bool Pm_LL_GetStopErrorState(void)
{
    return (PM_PTR->STA1.bits.STOPERROR == 1U);
}

/**
 * @brief 获取掉电模式进入错误中断标志
 * @param  void
 * @retval true  掉电动作完成前发生了唤醒条件
 * @retval false 正常进入了掉电模式
 */
KF_INLINE bool Pm_LL_GetPmcErrorState(void)
{
    return (PM_PTR->STA1.bits.PMCERROR == 1U);
}

/**
 * @brief VDD_OVD输出中断标志.
 * @param  void
 * @retval true   VDD电压高于过压监控点
 * @retval false  VDD电压低于过压监控点
 */
KF_INLINE bool Pm_LL_GetVddOvdIntrFlag(void)
{
    return (PM_PTR->STA1.bits.OVDIF != 0U);
}

/**
 * @brief VDD_OVD输出中断清零位.
 * @param void
 * @retval void.
 */
KF_INLINE void Pm_LL_ClearVddOvdIntrFlag(void)
{
    PM_PTR->STAC.bits.OVDIC = 1U;
    NOP();
    NOP();
    NOP();
    NOP();
    PM_PTR->STAC.bits.OVDIC = 0U;
}

/**
 * @brief 获取PMC错误中断标志.
 * @param  void
 * @retval true   发生了PMC错误中断(STOPERROR/PMCERROR)
 * @retval false 无作用
 */
KF_INLINE bool Pm_LL_GetPmcIntrFlag(void)
{
    return (PM_PTR->STA1.bits.PMCIF != 0U);
}

/**
 * @brief 获取PMC错误中断标志.
 * @param PinSelIdx: 唤醒引脚,取值为 Pm_WakeUp_t
 * @retval true   引脚发生唤醒事件
 * @retval false 引脚未发生唤醒事件
 */
KF_INLINE bool Pm_LL_GetWakeupPinState(Pm_WakeUp_t PinIndex)
{
    KF_PM_ASSERT(CHECK_PM_WAKEUP_PIN(PinIndex));
    uint32_t Pos;

    Pos = 27U + (uint32_t)PinIndex;
    /* PRQA S 3469 1 #KQR003469 */
    return (REG_BITS_READ(PM_PTR->STA1.reg, (1UL << Pos), Pos) != 0U);
}

/**
 * @brief 获取所有WakeUp唤醒引脚标志.
 *
 * @return 唤醒引脚状态
 * @retval true   引脚发生唤醒事件
 * @retval false 引脚未发生唤醒事件
 */
KF_INLINE uint32_t Pm_LL_GetAllWakeupPinState(void)
{
    uint32_t Mask_1_5  = 0xF8000000U;
    uint32_t Mask_6_12 = 0x3A800U;
    uint32_t State     = 0U;

    State = PM_PTR->STA1.reg;
    State = ((State & Mask_1_5) >> 27U) | ((State & Mask_6_12) >> 6U);

    return State;
}

/**
 * @brief 设置外部唤醒引脚WKP6-12使能.
 * @param PinSelIdx: 唤醒引脚,取值为 Pm_WakeUp6To12_t
 * @param State:
 *          true   使能WKUPx电平变化唤醒
 *          false 禁止WKUPx电平变化唤醒
 * @retval void.
 */
KF_INLINE void Pm_LL_SetExternalWakeup6To12PinEnabled(Pm_WakeUp6To12_t PinIndex, bool State)
{
    KF_PM_ASSERT(CHECK_PM_WAKEUP6TO12_PIN(PinIndex));

    uint32_t TargetIndex;

    TargetIndex = ((uint32_t)PinIndex - (uint32_t)PM_PIN_WKP6) + 2U;
    REG_BITS_WRITE(PM_PTR->STAC.reg, (1UL << (uint32_t)TargetIndex), ((State ? 1UL : 0UL) << (uint32_t)TargetIndex));
}

/**
 * @brief 设置外部唤醒引脚WKP6-12唤醒触发沿.
 * @param PinIndex: 唤醒引脚,取值为 Pm_WakeUp6To12_t
 * @param TriggerEdge: 外部唤醒引脚WKPx唤醒触发沿,取值为 Pm_TrigEdge_t
 * @retval void.
 */
KF_INLINE void Pm_LL_SetExternalWakeup6To12Edge(Pm_WakeUp6To12_t PinIndex, Pm_TrigEdge_t TriggerEdge)
{
    KF_PM_ASSERT(CHECK_PM_WAKEUP6TO12_PIN(PinIndex));
    KF_PM_ASSERT(CHECK_PM_TRIGGER_EDGE(TriggerEdge));

    uint32_t TargetIndex;

    TargetIndex = ((uint32_t)PinIndex - (uint32_t)PM_PIN_WKP6) + 9U;
    REG_BITS_WRITE(PM_PTR->STAC.reg, (1UL << (uint32_t)TargetIndex), ((uint32_t)TriggerEdge << (uint32_t)TargetIndex));
}

/**
 * @brief 清零WKP6-12标志.
 * @param PinSelIdx: 唤醒引脚,取值为 Pm_WakeUp6To12_t
 * @retval void.
 */
KF_INLINE void Pm_LL_ClearWakeup6To12PinState(Pm_WakeUp6To12_t PinIndex)
{
    KF_PM_ASSERT(CHECK_PM_WAKEUP6TO12_PIN(PinIndex));
    uint32_t Pos;

    Pos = ((uint32_t)PinIndex - (uint32_t)PM_PIN_WKP6) + 16U;
    REG_BIT_SET(PM_PTR->STAC.reg, (1UL << Pos));
    NOP();
    NOP();
    NOP();
    NOP();
    REG_BIT_CLR(PM_PTR->STAC.reg, (1UL << Pos));
}

/**
 * @brief 清零WKPxSTA标志.
 * @param PinSelIdx: 唤醒引脚,取值为 Pm_WakeUp_t
 * @retval void.
 */
KF_INLINE void Pm_LL_ClearWakeupPinState(Pm_WakeUp_t PinIndex)
{
    KF_PM_ASSERT(CHECK_PM_WAKEUP_PIN(PinIndex));
    uint32_t Pos;

    Pos = 27U + (uint32_t)PinIndex;
    REG_BIT_SET(PM_PTR->STAC.reg, (1UL << Pos));
    NOP();
    NOP();
    NOP();
    NOP();
    REG_BIT_CLR(PM_PTR->STAC.reg, (1UL << Pos));
}

/**
 * @brief 清零所有WKPxSTA标志.
 * @retval void.
 */
KF_INLINE void Pm_LL_ClearAllWakeupPinState(void)
{
    uint32_t mask = 0xF87F0000U;

    REG_BIT_SET(PM_PTR->STAC.reg, mask);
    NOP();
    NOP();
    NOP();
    NOP();
    REG_BIT_CLR(PM_PTR->STAC.reg, mask);
}

/**
 * @brief 清零PMCIF 标志.
 * @param void
 * @retval void.
 */
KF_INLINE void Pm_LL_ClearPmcIntrFlag(void)
{
    PM_PTR->STAC.bits.PMCIC = 1U;
    NOP();
    NOP();
    NOP();
    NOP();
    PM_PTR->STAC.bits.PMCIC = 0U;
}

/**
 * @brief 设置 BGTRIMMRLDO 值
 * @param State:
 *          true   禁止NRST1
 *          false 使能NRST1
 * @retval void
 */
KF_INLINE void Pm_LL_SetBGTRIMMRLDOValue(uint8_t Value)
{
    uint32_t kvRegValue = PM_PTR->CAL0.reg;
    uint32_t tmpValue   = (uint32_t)Value;

    if (tmpValue > 0x1FU)
    {
        tmpValue = 0x1FU;
    }
    else
    { /*Empty*/
    }
    REG_BITS_WRITE(kvRegValue, PM_CAL0_BGTRIMMRLDO_MASK, tmpValue << PM_CAL0_BGTRIMMRLDO_POS);

    PM_PTR->CAL0.reg = kvRegValue;
}

/**
 * @brief 获取 BGTRIMMRLDO 值
 * @retval void.
 */
KF_INLINE uint32_t Pm_LL_GetBGTRIMMRLDOValue(void)
{
    /* PRQA S 3469 1 #KQR003469 */
    uint32_t kvRegValue = REG_BITS_READ(PM_PTR->CAL0.reg, PM_CAL0_BGTRIMMRLDO_MASK, PM_CAL0_BGTRIMMRLDO_POS);

    return kvRegValue;
}

/**
 * @brief 设置外部复位引脚 NRST0 软件使能状态
 *
 * @param State 状态
 *        true: 使能
 *        false: 禁止
 * @return void
 */
KF_INLINE void Pm_LL_SetNrst0Enabled(bool State)
{
    PM_PTR->CAL0.bits.NRST0EN = State ? 1U : 0U;
}
/**
 * @brief STOP0 模式下 Flash 休眠延时使能
 * @note 延时配置参考 OSC_HF2CTL 寄存器
 *
 * @param State 使能状态
 *         true: 使能
 *         false: 禁止
 * @return void
 */
KF_INLINE void Pm_LL_SetStop0FlashDelayEnabled(bool State)
{
    PM_PTR->CAL0.bits.STOP0_FLASH_SEL = State ? 0U : 1U;
}

/**
 * @brief VDD_OVD输出中断发生状态.
 * @param  void
 * @retval bool 中断发生状态
 *         true    发生了中断，且已使能
 *         false    未发生中断，或未使能
 */
KF_INLINE bool Pm_LL_GetVddOvdIntrState(void)
{
    bool flag  = (PM_PTR->STA1.bits.OVDIF != 0U) ? true : false;
    bool state = (PM_PTR->CTL1.bits.OVDIE != 0U) ? true : false;
    return flag && state;
}

/**
 * @brief 获取PMC错误中断发生状态.
 * @param  void
 * @retval bool 中断发生状态
 *         true    发生了中断，且已使能
 *         false    未发生中断，或未使能
 */
KF_INLINE bool Pm_LL_GetPmcIntrState(void)
{
    bool flag  = (PM_PTR->STA1.bits.PMCIF != 0U) ? true : false;
    bool state = (PM_PTR->CTL2.bits.PMCIE != 0U) ? true : false;
    return flag && state;
}

/**
 * @brief 设置FVR2
 *
 * @param FvrVoltage FVR电压
 */
void Pm_LL_SetFvr2(Pm_FvrVoltage_t FvrVoltage, bool EnableState);

#ifdef __cplusplus
}
#endif /*End of __cplusplus*/
#endif /*End of KF32A158SF_DRV_PM_H*/
/* EOF */
