/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name        : kf32a158sf_drv_eccp.h
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
#ifndef KF32A158SF_DRV_ECCP_H
#define KF32A158SF_DRV_ECCP_H

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
#include "kf32a158sf_reg_eccp.h"

#ifdef KF_DRV_ECCP_ASSERT
#include "dev_assert.h"
#define KF_ECCP_ASSERT(x) KF_DEV_ASSERT(x)
#else
#define KF_ECCP_ASSERT(x) ((void)0U)
#endif

/******************************************************************************
 *                      Macro or Inline
 ******************************************************************************/

/******************************************************************************
 *                      Type definitions
 ******************************************************************************/

/** ECCP通道序号 */
typedef enum
{
    ECCP_CHANNEL_1 = 0x0U,
    ECCP_CHANNEL_2,
    ECCP_CHANNEL_3,
    ECCP_CHANNEL_4,
} Eccp_Channel_t;
#define CHECK_ECCP_CHANNEL(x) (((x) >= ECCP_CHANNEL_1) && ((x) <= ECCP_CHANNEL_4))

/** ECCP工作模式 */
typedef enum
{
    ECCP_MODE_CLOSE                = 0x0U,
    ECCP_MODE_CMP_TOGGLE           = 0x2U,
    ECCP_MODE_CAP_EVERY_FALL_EDGE  = 0x4U,
    ECCP_MODE_CAP_EVERY_RAISE_EDGE = 0x5U,
    ECCP_MODE_CAP_4_RAISE_EDGE     = 0x6U,
    ECCP_MODE_CAP_16_RAISE_EDGE    = 0x7U,
    ECCP_MODE_CMP_ACTIVE_LEVEL     = 0x8U,
    ECCP_MODE_CMP_INACTIVE_LEVEL   = 0x9U,
    ECCP_MODE_CMP_GEN_INT          = 0xAU,
    ECCP_MODE_CMP_GEN_EVENT        = 0xBU,
    ECCP_MODE_PWM_FREEDOM          = 0xCU,
    ECCP_MODE_PWM_COOPERATE        = 0xDU,
    ECCP_MODE_PWM_ONE_TIM          = 0xEU,
} Eccp_Mode_t;
#define CHECK_ECCP_MODE(x) (((x) >= ECCP_MODE_CLOSE) && ((x) <= ECCP_MODE_PWM_ONE_TIM) && ((x) != 1U) && ((x) != 3U))

/** 从模式选择位 */
typedef enum
{
    /**从模式禁止*/
    ECCP_TIM_SLAVE_FORBIDDEN = 0x0U,
    /**触发模式*/
    ECCP_TIM_SLAVE_TRIG = 0x4U,
    /**门控模式*/
    ECCP_TIM_SLAVE_GATE,
    /**复位模式*/
    ECCP_TIM_SLAVE_RESET,
    /**计数模式 2*/
    ECCP_TIM_SLAVE_COUNT_MODE_2,
} Eccp_TimerSlave_t;
#define CHECK_ECCP_TIMERSLAVE(x)                                                                                       \
    (((x) == ECCP_TIM_SLAVE_FORBIDDEN) || ((x) == ECCP_TIM_SLAVE_TRIG) || ((x) == ECCP_TIM_SLAVE_GATE) ||              \
     ((x) == ECCP_TIM_SLAVE_RESET) || ((x) == ECCP_TIM_SLAVE_COUNT_MODE_2))

/** 主模式 */
typedef enum
{
    /**使能信号 TXEN 作为触发输出 TRG*/
    ECCP_TIM_MASTER_TXEN = 0x1U,
    /**TXIF 信号作为触发输出 TRGO*/
    ECCP_TIM_MASTER_TXIF = 0x2U,
    /**ECCPx 的 CC1IF 脉冲作为触发输出 TRGO*/
    ECCP_TIM_MASTER_CC1IF = 0x3U,
    /**ECCPxCH1H 作为触发输出 TRGO*/
    ECCP_TIM_MASTER_CH1H = 0x4U,
    /**ECCPxCH2H 作为触发输出 TRGO*/
    ECCP_TIM_MASTER_CH2H = 0x5U,
    /**ECCPxCH3H 作为触发输出 TRGO*/
    ECCP_TIM_MASTER_CH3H = 0x6U,
    /**ECCPxCH4H 作为触发输出 TRGO*/
    ECCP_TIM_MASTER_CH4H = 0x7U,
} Eccp_TimerMaster_t;
#define CHECK_ECCP_TIMERMASTER(x) (((x) >= ECCP_TIM_MASTER_TXEN) && ((x) <= ECCP_TIM_MASTER_CH4H))

/**输入触发 TRIG 选择位*/
typedef enum
{
    /**定时器 1 触发*/
    ECCP_TRIG_TIM_1 = 0x0U,
    /**定时器 4 触发*/
    ECCP_TRIG_TIM_4 = 0x2U,
    /**定时器 5 触发*/
    ECCP_TRIG_TIM_5,
    /**ECCPxCH1H 的输入*/
    ECCP_TRIG_CH1H,
    /**ECCPxCH2H 的输入*/
    ECCP_TRIG_CH2H,
    /**ECCPxCH3H 的输入*/
    ECCP_TRIG_CH3H,
    /**TxCK 输入*/
    ECCP_TRIG_TXCK,
} Eccp_Trig_t;
#define CHECK_ECCP_TRIG(x) (((x) >= ECCP_TRIG_TIM_1) && ((x) <= ECCP_TRIG_TXCK))

/**通道端口输出控制*/
typedef enum
{
    ECCP_OUT_CTRL_PWM_ACTIVE = 0x0U,
    ECCP_OUT_CTRL_PWM_INACTIVE,
    ECCP_OUT_CTRL_FORCE_INACTIVE,
    ECCP_OUT_CTRL_FORCE_ACTIVE,
} Eccp_OutputCtrl_t;
#define CHECK_ECCP_OUTPUTCTRL(x) (((x) >= ECCP_OUT_CTRL_PWM_ACTIVE) && ((x) <= ECCP_OUT_CTRL_FORCE_ACTIVE))

/**PWM通道输出配置*/
typedef enum
{
    ECCP_PWM_INDEPENDENT_OUT  = 0x0U,
    ECCP_PWM_COMPLEMENTAL_OUT = 0x1U,
} Eccp_PwmOutput_t;
#define CHECK_ECCP_PWMOUTPUT(x) (((x) == ECCP_PWM_INDEPENDENT_OUT) || ((x) == ECCP_PWM_COMPLEMENTAL_OUT))

/**通道引脚*/
typedef enum
{
    /**通道引脚L*/
    ECCP_CH_PIN_LO = 0x0U,
    /**通道引脚H*/
    ECCP_CH_PIN_HI = 0x1U,
} Eccp_ChannelPin_t;
#define CHECK_ECCP_CHANNELPIN(x) (((x) == ECCP_CH_PIN_LO) || ((x) == ECCP_CH_PIN_HI))

/**通道自动关闭源*/
typedef enum
{
    ECCP_SHUTOFF_FORBIDDEN = 0x0U,
    ECCP_SHUTOFF_SRC_CMP_HI,
    ECCP_SHUTOFF_SRC_BKIN_LO,
    ECCP_SHUTOFF_SRC_BOTH,
} Eccp_ShutOffSrc_t;
#define CHECK_ECCP_SHUTOFFSRC(x) (((x) >= ECCP_SHUTOFF_FORBIDDEN) && ((x) <= ECCP_SHUTOFF_SRC_BOTH))

/**引脚关闭状态*/
typedef enum
{
    ECCP_OFF_STA_INACTIVE = 0x0U,
    ECCP_OFF_STA_ACTIVE,
    ECCP_OFF_STA_HI_Z,
} Eccp_OffState_t;
#define CHECK_ECCP_OFFSTATE(x)                                                                                         \
    (((x) == ECCP_OFF_STA_INACTIVE) || ((x) == ECCP_OFF_STA_ACTIVE) || ((x) == ECCP_OFF_STA_HI_Z))

/**ECCP设置中断序号*/
typedef enum
{
    ECCP_INTR_SET_CC1IE = 0U,
    ECCP_INTR_SET_CC2IE,
    ECCP_INTR_SET_CC3IE,
    ECCP_INTR_SET_CC4IE,
    ECCP_INTR_SET_TXTIE,
    ECCP_INTR_SET_TZIE,
    ECCP_INTR_SET_TXIE,
    ECCP_INTR_SET_TZUIE,
    ECCP_INTR_SET_TXUIE,
    ECCP_INTR_SET_CPIE,
    ECCP_INTR_SET_PDIE,
} Eccp_IntrSetIndex_t;
#define CHECK_ECCP_INTRSETINDEX(x) (((x) >= ECCP_INTR_SET_CC1IE) && ((x) <= ECCP_INTR_SET_PDIE))

/**ECCP获取中断序号*/
typedef enum
{
    ECCP_INTR_GET_CC1IF = 6U,
    ECCP_INTR_GET_CC2IF,
    ECCP_INTR_GET_CC3IF,
    ECCP_INTR_GET_CC4IF,
    ECCP_INTR_GET_TXTIF,
    ECCP_INTR_GET_TZIF,
    ECCP_INTR_GET_TXIF,
    ECCP_INTR_GET_TZUIF,
    ECCP_INTR_GET_TXUIF,
    ECCP_INTR_GET_CPIF = 0U,
    ECCP_INTR_GET_PDIF = 15U,
} Eccp_IntrGetIndex_t;
#define CHECK_ECCP_INTRGETINDEX(x)                                                                                     \
    ((((x) >= ECCP_INTR_GET_CC1IF) && ((x) <= ECCP_INTR_GET_TXUIF)) || ((x) == ECCP_INTR_GET_CPIF) ||                  \
     ((x) == ECCP_INTR_GET_PDIF))

/**ECCP清除中断序号*/
typedef enum
{
    ECCP_INTR_CLEAR_CC1IC = 0U,
    ECCP_INTR_CLEAR_CC2IC,
    ECCP_INTR_CLEAR_CC3IC,
    ECCP_INTR_CLEAR_CC4IC,
    ECCP_INTR_CLEAR_TXTIC,
    ECCP_INTR_CLEAR_TZIC,
    ECCP_INTR_CLEAR_TXIC,
    ECCP_INTR_CLEAR_TZUIC,
    ECCP_INTR_CLEAR_TXUIC,
    ECCP_INTR_CLEAR_CPIC,
    ECCP_INTR_CLEAR_PDIC,
} Eccp_IntrClearIndex_t;
#define CHECK_ECCP_INTRCLEARINDEX(x) (((x) >= ECCP_INTR_CLEAR_CC1IC) && ((x) <= ECCP_INTR_CLEAR_PDIC))

/**ECCP DMA请求序号*/
typedef enum
{
    ECCP_DMA_CH1 = 0x0U,
    ECCP_DMA_CH2,
    ECCP_DMA_CH3,
    ECCP_DMA_CH4,
    ECCP_DMA_CLOSE_EVENT,
    ECCP_DMA_TRIG_EVENT,
    ECCP_DMA_TZ_UPDATE_EVENT,
    ECCP_DMA_TX_UPDATE_EVENT,
} Eccp_DmaIndex_t;
#define CHECK_ECCP_DMAINDEX(x) (((x) >= ECCP_DMA_CH1) && ((x) <= ECCP_DMA_TX_UPDATE_EVENT))

/**联合输出信号有效沿*/
typedef enum
{
    ECCP_COM_OUT_PPX_LO = 0x0U,
    ECCP_COM_OUT_PPX_HI,
    ECCP_COM_OUT_COMBH_HI,
    ECCP_COM_OUT_COMBH_LO,
} Eccp_ComOutputEdge_t;
#define CHECK_ECCP_COMOUTPUTEDGE(x) (((x) >= ECCP_COM_OUT_PPX_LO) && ((x) <= ECCP_COM_OUT_COMBH_LO))

typedef enum
{
    ECCP_EDGE_NONE,
    ECCP_EDGE_RISING,
    ECCP_EDGE_FALLING,
    ECCP_EDGE_BOTH,
} Eccp_SignalEdge_t;
#define CHECK_ECCP_SIGNALEDGE(x) (((x) >= ECCP_EDGE_NONE) && ((x) <= ECCP_EDGE_BOTH))

typedef enum
{
    ECCP_PXASS_0, /*!< 选择比较器 0 的输出高电平作为关断源 */
    ECCP_PXASS_1, /*!< 选择比较器 1 的输出高电平作为关断源 */
    ECCP_PXASS_2, /*!< 选择比较器 2 的输出高电平作为关断源 */
    ECCP_PXASS_3, /*!< 选择比较器 3 的输出高电平作为关断源 */
} Eccp_Pxass_t;
#define CHECK_ECCP_PXASS(x) (((x) >= ECCP_PXASS_0) && ((x) <= ECCP_PXASS_3))

typedef enum
{
    ECCP_FCLK_DIV_1,
    ECCP_FCLK_DIV_2,
    ECCP_FCLK_DIV_3,
    ECCP_FCLK_DIV_4,
    ECCP_FCLK_DIV_5,
    ECCP_FCLK_DIV_6,
    ECCP_FCLK_DIV_7,
    ECCP_FCLK_DIV_8,
    ECCP_FCLK_DIV_9,
    ECCP_FCLK_DIV_10,
    ECCP_FCLK_DIV_11,
    ECCP_FCLK_DIV_12,
    ECCP_FCLK_DIV_13,
    ECCP_FCLK_DIV_14,
    ECCP_FCLK_DIV_15,
    ECCP_FCLK_DIV_16,
} Eccp_FilterClkDiv_t;
#define CHECK_ECCP_FILTERCLKDIV(x) (((x) >= ECCP_FCLK_DIV_1) && ((x) <= ECCP_FCLK_DIV_16))

/**输出信号极性选择*/
typedef enum
{
    /**自动模式,信号通过 Fault 控制之后强制输出 0*/
    ECCP_FAULT_CTRL_AUTO_OUTPUT_0 = 0U,
    /**自动模式,信号通过 Fault 控制之后强制输出 1*/
    ECCP_FAULT_CTRL_AUTO_OUTPUT_1,
    /**手动模式,信号通过 Fault 控制之后强制输出 0*/
    ECCP_FAULT_CTRL_MANUAL_OUTPUT_0,
    /**手动模式,信号通过 Fault 控制之后强制输出 1*/
    ECCP_FAULT_CTRL_MANUAL_OUTPUT_1,
} Eccp_FaultOutputPol_t;
#define CHECK_ECCP_FAULTOUTPUTPOL(x)                                                                                   \
    (((x) >= ECCP_FAULT_CTRL_AUTO_OUTPUT_0) && ((x) <= ECCP_FAULT_CTRL_MANUAL_OUTPUT_1))

/** CH1捕捉输入引脚 */
typedef enum
{
    ECCP_CH1_CAP_PIN_CH1H     = 0x0U, /* PXXORM=1，选择异或值作为捕捉输入 */
    ECCP_CH1_CAP_PIN_CH2H     = 0x1U,
    ECCP_CH1_CAP_PIN_CH3H     = 0x2U,
    ECCP_CH1_CAP_PIN_CH4H     = 0x3U,
    ECCP_CH1_CAP_PIN_CMP0_OUT = 0x4U, /* 硬件编码为1xx, 可取值4,5,6,7 */
} Eccp_Ch1CapPin_t;
#define CHECK_ECCP_CH1_CAPPIN(x) ((x) <= 7U)

/** CH2捕捉输入引脚 */
typedef enum
{
    ECCP_CH2_CAP_PIN_CH2H     = 0x0U, /* PXPWMI=1时为CH1H */
    ECCP_CH2_CAP_PIN_CH1H     = 0x1U,
    ECCP_CH2_CAP_PIN_CH3H     = 0x2U,
    ECCP_CH2_CAP_PIN_CH4H     = 0x3U,
    ECCP_CH2_CAP_PIN_CMP1_OUT = 0x4U, /* 硬件编码为1xx, 可取值4,5,6,7 */
} Eccp_Ch2CapPin_t;
#define CHECK_ECCP_CH2_CAPPIN(x) ((x) <= 7U)

/** CH3捕捉输入引脚 */
typedef enum
{
    ECCP_CH3_CAP_PIN_CH3H     = 0x0U,
    ECCP_CH3_CAP_PIN_CH1H     = 0x1U,
    ECCP_CH3_CAP_PIN_CH2H     = 0x2U,
    ECCP_CH3_CAP_PIN_CH4H     = 0x3U,
    ECCP_CH3_CAP_PIN_CMP2_OUT = 0x4U, /* 硬件编码为1xx, 可取值4,5,6,7 */
} Eccp_Ch3CapPin_t;
#define CHECK_ECCP_CH3_CAPPIN(x) ((x) <= 7U)

/** CH4捕捉输入引脚 */
typedef enum
{
    ECCP_CH4_CAP_PIN_CH4H     = 0x0U,
    ECCP_CH4_CAP_PIN_CH1H     = 0x1U,
    ECCP_CH4_CAP_PIN_CH2H     = 0x2U,
    ECCP_CH4_CAP_PIN_CH3H     = 0x3U,
    ECCP_CH4_CAP_PIN_CMP3_OUT = 0x4U, /* 硬件编码为1xx, 可取值4,5,6,7 */
} Eccp_Ch4CapPin_t;
#define CHECK_ECCP_CH4_CAPPIN(x) ((x) <= 7U)

/**相位重载时机*/
typedef enum
{
    /**当计数值匹配 0 时发生 Tx 相位重载*/
    ECCP_PHS_TIM_CNT_EQU_0 = 0x0U,
    /**当计数值匹配周期值时发生 Tx 相位重载*/
    ECCP_PHS_TIM_CNT_EQU_PPX,
    /**选择 TRGI 触发 Tx 相位重载*/
    ECCP_PHS_TIM_TRGI,
    /**选择软件触发 Tx 相位重载*/
    ECCP_PHS_TIM_SOFTWARE,
} Eccp_PhaseShiftTime_t;
#define CHECK_ECCP_PHASESHIFTTIME(x) (((x) >= ECCP_PHS_TIM_CNT_EQU_0) && ((x) <= ECCP_PHS_TIM_SOFTWARE))

/**检查输入范围为0x3*/
#define CHECK_ECCP_INPUT_0X3(x) (((x) >= 0U) && ((x) <= 0x3U))

/**检查输入范围为0x7*/
#define CHECK_ECCP_INPUT_0X7(x) (((x) >= 0U) && ((x) <= 0x7U))

/**检查输入范围为0xF*/
#define CHECK_ECCP_INPUT_0XF(x) (((x) >= 0U) && ((x) <= 0xFU))

/**检查输入范围为0x1F*/
#define CHECK_ECCP_INPUT_0X1F(x) (((x) >= 0U) && ((x) <= 0x1FU))

/******************************************************************************
 *                      Export Variables
 ******************************************************************************/

/******************************************************************************
 *                      Export Functions
 ******************************************************************************/

/**
 * @brief: 设置TI0信号输入检测沿选择位
 * @param Module: 指向Eccp内存结构的指针
 * @param SignalEdge: Eccp_SignalEdge_t
 *          EDGE_RISING    检测上升沿
 *          EDGE_FALLING   检测下降沿
 *          EDGE_BOTH      检测上升和下降沿
 * @retval void
 */
KF_INLINE void Eccp_LL_SetTiSignalEdge(Eccp_RegisterMap_t *const Module, Eccp_SignalEdge_t SignalEdge)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));
    KF_ECCP_ASSERT(CHECK_ECCP_SIGNALEDGE(SignalEdge));

    Module->PDCTL.bits.CPE = (uint32_t)SignalEdge;
}

/**
 * @brief: 使能/禁止位置检测比较
 * @param Module: 指向Eccp内存结构的指针
 * @param State:
 *          true   使能位置检测比较
 *          false   禁止位置检测比较
 * @retval void
 */
KF_INLINE void Eccp_LL_SetPositionCompareEnabled(Eccp_RegisterMap_t *const Module, bool State)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->PDCTL.bits.CMPE = State ? 1U : 0U;
}

/**
 * @brief: 使能/禁止TI0输入检测
 * @param Module: 指向Eccp内存结构的指针
 * @param State:
 *          true   使能TI0输入检测
 *          false   禁止TI0输入检测
 * @retval void
 */
KF_INLINE void Eccp_LL_SetTi0Enabled(Eccp_RegisterMap_t *const Module, bool State)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->PDCTL.bits.TI0EN = State ? 1U : 0U;
}

/**
 * @brief: 使能/禁止TI1输入检测
 * @param Module: 指向Eccp内存结构的指针
 * @param State:
 *          true   使能TI1输入检测
 *          false   禁止TI1输入检测
 * @retval void
 */
KF_INLINE void Eccp_LL_SetTi1Enabled(Eccp_RegisterMap_t *const Module, bool State)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->PDCTL.bits.TI1EN = State ? 1U : 0U;
}

/**
 * @brief: 使能/禁止TI2输入检测
 * @param Module: 指向Eccp内存结构的指针
 * @param State:
 *          true   使能TI2输入检测
 *          false   禁止TI2输入检测
 * @retval void
 */
KF_INLINE void Eccp_LL_SetTi2Enabled(Eccp_RegisterMap_t *const Module, bool State)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->PDCTL.bits.TI2EN = State ? 1U : 0U;
}

/**
 * @brief: 使能/禁止输入采样功能
 * @param Module: 指向Eccp内存结构的指针
 * @param State:
 *          true   使能输入采样功能
 *          false   禁止输入采样功能
 * @retval void
 */
KF_INLINE void Eccp_LL_SetSampleEnabled(Eccp_RegisterMap_t *const Module, bool State)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->PDCTL.bits.SMPEN = State ? 1U : 0U;
}

/**
 * @brief: 配置位置检测输入信号 TI0/TI1/TI2 与输入捕获信号 TIx 比较位
 * @param Module: 指向Eccp内存结构的指针
 * @param RdaValue: 位置检测比较值
 *          [0-7] 分别对应 TI2/TI1/TI0 的比较位
 * @retval void
 */
KF_INLINE void Eccp_LL_SetRdaValue(Eccp_RegisterMap_t *const Module, uint8_t RdaValue)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));
    KF_ECCP_ASSERT(CHECK_ECCP_INPUT_0X3(RdaValue));

    Module->PDCTL.bits.RDA = RdaValue;
}

/**
 * @brief: 获取 TI<2:0> 信号状态位
 * @param Module: 指向Eccp内存结构的指针
 * @retval uint8_t TI<2:0>信号状态值,由高到低分别对应 TI2/TI1/TI0
 */
KF_INLINE uint8_t Eccp_LL_GetSignalState(const Eccp_RegisterMap_t *const Module)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    return Module->PDCTL.bits.CPD;
}

/**
 * @brief: 设置CH1/2/3的比较器关断源选择位
 * @param Module: 指向Eccp内存结构的指针
 * @param Value: CH1/2/3的比较器关断源选择位值(0~3)
 * @retval void
 */
KF_INLINE void Eccp_LL_SelectTxComparatorShutOffSource(Eccp_RegisterMap_t *const Module, Eccp_Pxass_t Value)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));
    KF_ECCP_ASSERT(CHECK_ECCP_PXASS(Value));

    Module->PXASCTL.bits.TXPXASS = (uint32_t)Value;
}

/**
 * @brief: 设置CH4的比较器关断源选择位
 * @param Module: 指向Eccp内存结构的指针
 * @param Value: CH4的比较器关断源选择位值(0~3)
 * @retval void
 */
KF_INLINE void Eccp_LL_SelectTzComparatorShutOffSource(Eccp_RegisterMap_t *const Module, Eccp_Pxass_t Value)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));
    KF_ECCP_ASSERT(CHECK_ECCP_PXASS(Value));

    Module->PXASCTL.bits.TZPXASS = (uint32_t)Value;
}

/**
 * @brief: 设置TX关断控制源BKIN选择位
 * @param Module: 指向Eccp内存结构的指针
 * @param State:
 *          true   选择FLTI2的低电平作为关断源
 *          false  选择BKIN的低电平作为关断源
 * @retval void
 */
KF_INLINE void Eccp_LL_SelectTxShutOffSource(Eccp_RegisterMap_t *const Module, bool State)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->PXASCTL.bits.TXBKINS = State ? 1U : 0U;
}

/**
 * @brief: 设置TZ关断控制源BKIN选择位
 * @param Module: 指向Eccp内存结构的指针
 * @param State:
 *          true   选择FLTI2的低电平作为关断源
 *          false  选择BKIN的低电平作为关断源
 * @retval void
 */
KF_INLINE void Eccp_LL_SelectTzShutOffSource(Eccp_RegisterMap_t *const Module, bool State)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->PXASCTL.bits.TZBKINS = State ? 1U : 0U;
}

/**
 * @brief: 设置抖动计数器增量值
 * @param Module: 指向Eccp内存结构的指针
 * @param Value: 抖动计数器增量值,范围为0-31
 * @retval void
 */
KF_INLINE void Eccp_LL_SetDitherCounterIncValue(Eccp_RegisterMap_t *const Module, uint32_t Value)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));
    KF_ECCP_ASSERT(CHECK_ECCP_INPUT_0X1F(Value));

    Module->DITCTL.bits.FRCVAL = Value;
}

/**
 * @brief: 设置边沿抖动使能状态
 * @param Module: 指向Eccp内存结构的指针
 * @param State:
 *          true   使能边沿抖动
 *          false   禁止边沿抖动
 * @retval void
 */
KF_INLINE void Eccp_LL_SetEdgeDitherEnabled(Eccp_RegisterMap_t *const Module, bool State)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->DITCTL.bits.DEDEN = State ? 1U : 0U;
}

/**
 * @brief: 设置周期抖动使能状态
 * @param Module: 指向Eccp内存结构的指针
 * @param State:
 *          true   使能周期抖动
 *          false   禁止周期抖动
 * @retval void
 */
KF_INLINE void Eccp_LL_SetPeriodicDitherEnabled(Eccp_RegisterMap_t *const Module, bool State)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->DITCTL.bits.DPEEN = State ? 1U : 0U;
}

/**
 * @brief: 设置联合输出抖动使能状态
 * @param Module: 指向Eccp内存结构的指针
 * @param State:
 *          true   使能联合输出抖动
 *          false   禁止联合输出抖动
 * @retval void
 */
KF_INLINE void Eccp_LL_SetCombineOutputDitherEnabled(Eccp_RegisterMap_t *const Module, bool State)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->DITCTL.bits.DCOMEN = State ? 1U : 0U;
}

/**
 * @brief: 设置通道1 COMH控制寄存器H的值
 *          当定时器计数值与该寄存器的写入值匹配时,控制 PWM 波形输出翻转
 * @param Module: 指向Eccp内存结构的指针
 * @param Value: 设置的值
 * @retval void
 */
KF_INLINE void Eccp_LL_SetComH1Value(Eccp_RegisterMap_t *const Module, uint16_t Value)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->COMH1.bits.COMH = Value;
}

/**
 * @brief: 获取通道1 COMH控制寄存器H的值
 * @param Module: 指向Eccp内存结构的指针
 * @retval 返回COMH控制寄存器H的值
 */
KF_INLINE uint16_t Eccp_LL_GetComH1Value(const Eccp_RegisterMap_t *const Module)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    return Module->COMH1.bits.COMH;
}

/**
 * @brief: 设置通道1 联合控制寄存器L的值
 * @param Module: 指向Eccp内存结构的指针
 * @param Value: 联合控制寄存器L的值
 * @retval void
 */
KF_INLINE void Eccp_LL_SetComL1Value(Eccp_RegisterMap_t *const Module, uint16_t Value)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->COML1.bits.COML = Value;
}

/**
 * @brief: 读取联合控制寄存器L的值
 * @param Module: 指向Eccp内存结构的指针
 * @retval 联合控制寄存器L的值
 */
KF_INLINE uint16_t Eccp_LL_GetComL1Value(const Eccp_RegisterMap_t *const Module)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    return Module->COML1.bits.COML;
}

/**
 * @brief: 配置通道1 Fault控制功能使能
 * @param Module: 指向Eccp内存结构的指针
 * @param Enable:
 *          true   使能Fault控制功能
 *          false   禁止Fault控制功能
 * @retval void
 */
KF_INLINE void Eccp_LL_SetCh1FaultControlEnabled(Eccp_RegisterMap_t *const Module, bool Enable)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->FAUCTL1.bits.FAUEN = Enable ? 1U : 0U;
}

/**
 * @brief: 配置通道1 Filter CLK分频比选择
 * @param Module: 指向Eccp内存结构的指针
 * @param Div: CLK分频比选择值,范围:0~15
 * @retval void
 */
KF_INLINE void Eccp_LL_SetCh1FilterClkDivision(Eccp_RegisterMap_t *const Module, Eccp_FilterClkDiv_t Div)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));
    KF_ECCP_ASSERT(CHECK_ECCP_FILTERCLKDIV(Div));

    Module->FAUCTL1.bits.FLTP = (uint32_t)Div;
}

/**
 * @brief: 配置通道1 Fault in 信号滤波使能位
 * @param Module: 指向Eccp内存结构的指针
 * @param Enable:
 *          true   使能故障信号滤波功能
 *          false   禁止故障信号滤波功能
 * @retval void
 */
KF_INLINE void Eccp_LL_SetCh1FaultFilterEnabled(Eccp_RegisterMap_t *const Module, bool Enable)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->FAUCTL1.bits.FLTEN = Enable ? 1U : 0U;
}

/**
 * @brief: 配置通道1 Fault控制触发中断使能位
 * @param Module: 指向Eccp内存结构的指针
 * @param Enable:
 *          true   使能Fault控制触发中断
 *          false   禁止Fault控制触发中断
 * @retval void
 */
KF_INLINE void Eccp_LL_SetCh1FaultControlIntrEnabled(Eccp_RegisterMap_t *const Module, bool Enable)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->FAUCTL1.bits.FAUIE = Enable ? 1U : 0U;
}

/**
 * @brief: 清除通道1 Fault 控制中断标志
 * @param Module: 指向Eccp内存结构的指针
 * @retval void
 */
KF_INLINE void Eccp_LL_ClearCh1FaultControlIntrFlag(Eccp_RegisterMap_t *const Module)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->FAUCTL1.bits.FAUIC = 1U;
    NOP();
    NOP();
    NOP();
    NOP();
    Module->FAUCTL1.bits.FAUIC = 0U;
}

/**
 * @brief: 获取通道1 Fault 控制中断事件发生标志
 * @param Module: 指向Eccp内存结构的指针
 * @retval 中断事件发生标志
 *         true   事件已发生
 *         false   事件未发生
 */
KF_INLINE bool Eccp_LL_GetCh1FaultControlIntrFlag(const Eccp_RegisterMap_t *const Module)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    return Module->FAUCTL1.bits.FAUIF != 0U;
}

/**
 * @brief:配置通道1 滤波脉宽选择位
 * @param Module: 指向Eccp内存结构的指针
 * @param Width: 滤波脉宽选择值,范围:0~7
 *              滤除持续周期FVAL<2:0>+1
 * @retval void
 */
KF_INLINE void Eccp_LL_SetCh1FilterWidth(Eccp_RegisterMap_t *const Module, uint32_t Width)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));
    KF_ECCP_ASSERT(CHECK_ECCP_INPUT_0X7(Width));

    Module->FAUCTL1.bits.FVAL = Width;
}

/**
 * @brief:配置通道1 输出信号极性选择位
 * @param Module: 指向Eccp内存结构的指针
 * @param Polarity: 输出信号极性选择值, 可见 Eccp_FaultOutputPol_t
 * @retval void
 */
KF_INLINE void Eccp_LL_SetCh1OutputPolarity(Eccp_RegisterMap_t *const Module, Eccp_FaultOutputPol_t Polarity)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));
    KF_ECCP_ASSERT(CHECK_ECCP_FAULTOUTPUTPOL(Polarity));

    Module->FAUCTL1.bits.FINV = (uint32_t)Polarity;
}

/**
 * @brief:配置通道1 Fault控制高阻使能位
 * @param Module: 指向Eccp内存结构的指针
 * @param Enable:
 *          true   使能Fault控制输出高阻
 *          false   禁止Fault控制输出高阻
 * @retval void
 */
KF_INLINE void Eccp_LL_SetCh1FaultOutputHiZEnabled(Eccp_RegisterMap_t *const Module, bool Enable)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->FAUCTL1.bits.TRST = Enable ? 1U : 0U;
}

/**
 * @brief: 设置通道2 COMH控制寄存器H的值
 *          当定时器计数值与该寄存器的写入值匹配时,控制 PWM 波形输出翻转
 * @param Module: 指向Eccp内存结构的指针
 * @param Value: 设置的值
 * @retval void
 */
KF_INLINE void Eccp_LL_SetComH2Value(Eccp_RegisterMap_t *const Module, uint16_t Value)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->COMH2.bits.COMH = Value;
}

/**
 * @brief: 获取通道2 COMH控制寄存器H的值
 * @param Module: 指向Eccp内存结构的指针
 * @retval 返回COMH控制寄存器H的值
 */
KF_INLINE uint16_t Eccp_LL_GetComH2Value(const Eccp_RegisterMap_t *const Module)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    return Module->COMH2.bits.COMH;
}

/**
 * @brief: 设置通道2 联合控制寄存器L的值
 * @param Module: 指向Eccp内存结构的指针
 * @param Value: 联合控制寄存器L的值
 * @retval void
 */
KF_INLINE void Eccp_LL_SetComL2Value(Eccp_RegisterMap_t *const Module, uint16_t Value)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->COML2.bits.COML = Value;
}

/**
 * @brief: 读取联合控制寄存器L的值
 * @param Module: 指向Eccp内存结构的指针
 * @retval 联合控制寄存器L的值
 */
KF_INLINE uint16_t Eccp_LL_GetComL2Value(const Eccp_RegisterMap_t *const Module)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    return Module->COML2.bits.COML;
}

/**
 * @brief: 配置通道2 Fault控制功能使能
 * @param Module: 指向Eccp内存结构的指针
 * @param Enable:
 *          true   使能Fault控制功能
 *          false   禁止Fault控制功能
 * @retval void
 */
KF_INLINE void Eccp_LL_SetCh2FaultControlEnabled(Eccp_RegisterMap_t *const Module, bool Enable)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->FAUCTL2.bits.FAUEN = Enable ? 1U : 0U;
}

/**
 * @brief: 配置通道2 Filter CLK分频比选择
 * @param Module: 指向Eccp内存结构的指针
 * @param Div: CLK分频比选择值,范围:0~15
 * @retval void
 */
KF_INLINE void Eccp_LL_SetCh2FilterClkDivision(Eccp_RegisterMap_t *const Module, Eccp_FilterClkDiv_t Div)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));
    KF_ECCP_ASSERT(CHECK_ECCP_FILTERCLKDIV(Div));

    Module->FAUCTL2.bits.FLTP = (uint32_t)Div;
}

/**
 * @brief: 配置通道2 Fault in 信号滤波使能位
 * @param Module: 指向Eccp内存结构的指针
 * @param Enable:
 *          true   使能故障信号滤波功能
 *          false   禁止故障信号滤波功能
 * @retval void
 */
KF_INLINE void Eccp_LL_SetCh2FaultFilterEnabled(Eccp_RegisterMap_t *const Module, bool Enable)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->FAUCTL2.bits.FLTEN = Enable ? 1U : 0U;
}

/**
 * @brief: 配置通道2 Fault控制触发中断使能位
 * @param Module: 指向Eccp内存结构的指针
 * @param Enable:
 *          true   使能Fault控制触发中断
 *          false   禁止Fault控制触发中断
 * @retval void
 */
KF_INLINE void Eccp_LL_SetCh2FaultControlIntrEnabled(Eccp_RegisterMap_t *const Module, bool Enable)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->FAUCTL2.bits.FAUIE = Enable ? 1U : 0U;
}

/**
 * @brief: 清除通道2 Fault 控制中断标志
 * @param Module: 指向Eccp内存结构的指针
 * @retval void
 */
KF_INLINE void Eccp_LL_ClearCh2FaultControlIntrFlag(Eccp_RegisterMap_t *const Module)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->FAUCTL2.bits.FAUIC = 1U;
    NOP();
    NOP();
    NOP();
    NOP();
    Module->FAUCTL2.bits.FAUIC = 0U;
}

/**
 * @brief: 获取通道2 Fault 控制中断事件发生标志
 * @param Module: 指向Eccp内存结构的指针
 * @retval 中断事件发生标志
 *         true   事件已发生
 *         false   事件未发生
 */
KF_INLINE bool Eccp_LL_GetCh2FaultControlIntrFlag(const Eccp_RegisterMap_t *const Module)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    return Module->FAUCTL2.bits.FAUIF != 0U;
}

/**
 * @brief:配置通道2 滤波脉宽选择位
 * @param Module: 指向Eccp内存结构的指针
 * @param Width: 滤波脉宽选择值,范围:0~7
 *              滤除持续周期FVAL<2:0>+1
 * @retval void
 */
KF_INLINE void Eccp_LL_SetCh2FilterWidth(Eccp_RegisterMap_t *const Module, uint32_t Width)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));
    KF_ECCP_ASSERT(CHECK_ECCP_INPUT_0X7(Width));

    Module->FAUCTL2.bits.FVAL = Width;
}

/**
 * @brief:配置通道2 输出信号极性选择位
 * @param Module: 指向Eccp内存结构的指针
 * @param Polarity: 输出信号极性选择值, 可见 Eccp_FaultOutputPol_t
 * @retval void
 */
KF_INLINE void Eccp_LL_SetCh2OutputPolarity(Eccp_RegisterMap_t *const Module, Eccp_FaultOutputPol_t Polarity)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));
    KF_ECCP_ASSERT(CHECK_ECCP_FAULTOUTPUTPOL(Polarity));

    Module->FAUCTL2.bits.FINV = (uint32_t)Polarity;
}

/**
 * @brief:配置通道2 Fault控制高阻使能位
 * @param Module: 指向Eccp内存结构的指针
 * @param Enable:
 *          true   使能Fault控制输出高阻
 *          false   禁止Fault控制输出高阻
 * @retval void
 */
KF_INLINE void Eccp_LL_SetCh2FaultOutputHiZEnabled(Eccp_RegisterMap_t *const Module, bool Enable)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->FAUCTL2.bits.TRST = Enable ? 1U : 0U;
}

/**
 * @brief: 设置通道3 COMH控制寄存器H的值
 *          当定时器计数值与该寄存器的写入值匹配时,控制 PWM 波形输出翻转
 * @param Module: 指向Eccp内存结构的指针
 * @param Value: 设置的值
 * @retval void
 */
KF_INLINE void Eccp_LL_SetComH3Value(Eccp_RegisterMap_t *const Module, uint16_t Value)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->COMH3.bits.COMH = Value;
}

/**
 * @brief: 获取通道3 COMH控制寄存器H的值
 * @param Module: 指向Eccp内存结构的指针
 * @retval 返回COMH控制寄存器H的值
 */
KF_INLINE uint16_t Eccp_LL_GetComH3Value(const Eccp_RegisterMap_t *const Module)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    return Module->COMH3.bits.COMH;
}

/**
 * @brief: 设置通道3 联合控制寄存器L的值
 * @param Module: 指向Eccp内存结构的指针
 * @param Value: 联合控制寄存器L的值
 * @retval void
 */
KF_INLINE void Eccp_LL_SetComL3Value(Eccp_RegisterMap_t *const Module, uint16_t Value)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->COML3.bits.COML = Value;
}

/**
 * @brief: 读取联合控制寄存器L的值
 * @param Module: 指向Eccp内存结构的指针
 * @retval 联合控制寄存器L的值
 */
KF_INLINE uint16_t Eccp_LL_GetComL3Value(const Eccp_RegisterMap_t *const Module)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    return Module->COML3.bits.COML;
}

/**
 * @brief: 配置通道3 Fault控制功能使能
 * @param Module: 指向Eccp内存结构的指针
 * @param Enable:
 *          true   使能Fault控制功能
 *          false   禁止Fault控制功能
 * @retval void
 */
KF_INLINE void Eccp_LL_SetCh3FaultControlEnabled(Eccp_RegisterMap_t *const Module, bool Enable)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->FAUCTL3.bits.FAUEN = Enable ? 1U : 0U;
}

/**
 * @brief: 配置通道3 Filter CLK分频比选择
 * @param Module: 指向Eccp内存结构的指针
 * @param Div: CLK分频比选择值,范围:0~15
 * @retval void
 */
KF_INLINE void Eccp_LL_SetCh3FilterClkDivision(Eccp_RegisterMap_t *const Module, Eccp_FilterClkDiv_t Div)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));
    KF_ECCP_ASSERT(CHECK_ECCP_FILTERCLKDIV(Div));

    Module->FAUCTL3.bits.FLTP = (uint32_t)Div;
}

/**
 * @brief: 配置通道3 Fault in 信号滤波使能位
 * @param Module: 指向Eccp内存结构的指针
 * @param Enable:
 *          true   使能故障信号滤波功能
 *          false   禁止故障信号滤波功能
 * @retval void
 */
KF_INLINE void Eccp_LL_SetCh3FaultFilterEnabled(Eccp_RegisterMap_t *const Module, bool Enable)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->FAUCTL3.bits.FLTEN = Enable ? 1U : 0U;
}

/**
 * @brief: 配置通道3 Fault控制触发中断使能位
 * @param Module: 指向Eccp内存结构的指针
 * @param Enable:
 *          true   使能Fault控制触发中断
 *          false   禁止Fault控制触发中断
 * @retval void
 */
KF_INLINE void Eccp_LL_SetCh3FaultControlIntrEnabled(Eccp_RegisterMap_t *const Module, bool Enable)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->FAUCTL3.bits.FAUIE = Enable ? 1U : 0U;
}

/**
 * @brief: 清除通道3 Fault 控制中断标志
 * @param Module: 指向Eccp内存结构的指针
 * @retval void
 */
KF_INLINE void Eccp_LL_ClearCh3FaultControlIntrFlag(Eccp_RegisterMap_t *const Module)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->FAUCTL3.bits.FAUIC = 1U;
    NOP();
    NOP();
    NOP();
    NOP();
    Module->FAUCTL3.bits.FAUIC = 0U;
}

/**
 * @brief: 获取通道3 Fault 控制中断事件发生标志
 * @param Module: 指向Eccp内存结构的指针
 * @retval 中断事件发生标志
 *         true   事件已发生
 *         false   事件未发生
 */
KF_INLINE bool Eccp_LL_GetCh3FaultControlIntrFlag(const Eccp_RegisterMap_t *const Module)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    return Module->FAUCTL3.bits.FAUIF != 0U;
}

/**
 * @brief:配置通道3 滤波脉宽选择位
 * @param Module: 指向Eccp内存结构的指针
 * @param Width: 滤波脉宽选择值,范围:0~7
 *              滤除持续周期FVAL<2:0>+1
 * @retval void
 */
KF_INLINE void Eccp_LL_SetCh3FilterWidth(Eccp_RegisterMap_t *const Module, uint32_t Width)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));
    KF_ECCP_ASSERT(CHECK_ECCP_INPUT_0X7(Width));

    Module->FAUCTL3.bits.FVAL = Width;
}

/**
 * @brief:配置通道3 输出信号极性选择位
 * @param Module: 指向Eccp内存结构的指针
 * @param Polarity: 输出信号极性选择值, 可见 Eccp_FaultOutputPol_t
 * @retval void
 */
KF_INLINE void Eccp_LL_SetCh3OutputPolarity(Eccp_RegisterMap_t *const Module, Eccp_FaultOutputPol_t Polarity)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));
    KF_ECCP_ASSERT(CHECK_ECCP_FAULTOUTPUTPOL(Polarity));

    Module->FAUCTL3.bits.FINV = (uint32_t)Polarity;
}

/**
 * @brief:配置通道3 Fault控制高阻使能位
 * @param Module: 指向Eccp内存结构的指针
 * @param Enable:
 *          true   使能Fault控制输出高阻
 *          false   禁止Fault控制输出高阻
 * @retval void
 */
KF_INLINE void Eccp_LL_SetCh3FaultOutputHiZEnabled(Eccp_RegisterMap_t *const Module, bool Enable)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->FAUCTL3.bits.TRST = Enable ? 1U : 0U;
}

/**
 * @brief: 设置通道4 COMH控制寄存器H的值
 *          当定时器计数值与该寄存器的写入值匹配时,控制 PWM 波形输出翻转
 * @param Module: 指向Eccp内存结构的指针
 * @param Value: 设置的值
 * @retval void
 */
KF_INLINE void Eccp_LL_SetComH4Value(Eccp_RegisterMap_t *const Module, uint16_t Value)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->COMH4.reg = Value;
}

/**
 * @brief: 获取通道4 COMH控制寄存器H的值
 * @param Module: 指向Eccp内存结构的指针
 * @retval 返回COMH控制寄存器H的值
 */
KF_INLINE uint16_t Eccp_LL_GetComH4Value(const Eccp_RegisterMap_t *const Module)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    return Module->COMH4.bits.COMH;
}

/**
 * @brief: 设置通道4 联合控制寄存器L的值
 * @param Module: 指向Eccp内存结构的指针
 * @param Value: 联合控制寄存器L的值
 * @retval void
 */
KF_INLINE void Eccp_LL_SetComL4Value(Eccp_RegisterMap_t *const Module, uint16_t Value)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->COML4.reg = Value;
}

/**
 * @brief: 读取联合控制寄存器L的值
 * @param Module: 指向Eccp内存结构的指针
 * @retval 联合控制寄存器L的值
 */
KF_INLINE uint32_t Eccp_LL_GetComL4Value(const Eccp_RegisterMap_t *const Module)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    return Module->COML4.bits.COML;
}

/**
 * @brief: 配置通道4 Fault控制功能使能
 * @param Module: 指向Eccp内存结构的指针
 * @param Enable:
 *          true   使能Fault控制功能
 *          false   禁止Fault控制功能
 * @retval void
 */
KF_INLINE void Eccp_LL_SetCh4FaultControlEnabled(Eccp_RegisterMap_t *const Module, bool Enable)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->FAUCTL4.bits.FAUEN = Enable ? 1U : 0U;
}

/**
 * @brief: 配置通道4 Filter CLK分频比选择
 * @param Module: 指向Eccp内存结构的指针
 * @param Div: CLK分频比选择值,范围:0~15
 * @retval void
 */
KF_INLINE void Eccp_LL_SetCh4FilterClkDivision(Eccp_RegisterMap_t *const Module, Eccp_FilterClkDiv_t Div)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));
    KF_ECCP_ASSERT(CHECK_ECCP_FILTERCLKDIV(Div));

    Module->FAUCTL4.bits.FLTP = (uint32_t)Div;
}

/**
 * @brief: 配置通道4 Fault in 信号滤波使能位
 * @param Module: 指向Eccp内存结构的指针
 * @param Enable:
 *          true   使能故障信号滤波功能
 *          false   禁止故障信号滤波功能
 * @retval void
 */
KF_INLINE void Eccp_LL_SetCh4FaultFilterEnabled(Eccp_RegisterMap_t *const Module, bool Enable)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->FAUCTL4.bits.FLTEN = Enable ? 1U : 0U;
}

/**
 * @brief: 配置通道4 Fault控制触发中断使能位
 * @param Module: 指向Eccp内存结构的指针
 * @param Enable:
 *          true   使能Fault控制触发中断
 *          false   禁止Fault控制触发中断
 * @retval void
 */
KF_INLINE void Eccp_LL_SetCh4FaultControlIntrEnabled(Eccp_RegisterMap_t *const Module, bool Enable)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->FAUCTL4.bits.FAUIE = Enable ? 1U : 0U;
}

/**
 * @brief: 清除通道4 Fault 控制中断标志
 * @param Module: 指向Eccp内存结构的指针
 * @retval void
 */
KF_INLINE void Eccp_LL_ClearCh4FaultControlIntrFlag(Eccp_RegisterMap_t *const Module)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->FAUCTL4.bits.FAUIC = 1U;
    NOP();
    NOP();
    NOP();
    NOP();
    Module->FAUCTL4.bits.FAUIC = 0U;
}

/**
 * @brief: 获取通道4 Fault 控制中断事件发生标志
 * @param Module: 指向Eccp内存结构的指针
 * @retval 中断事件发生标志
 *         true   事件已发生
 *         false   事件未发生
 */
KF_INLINE bool Eccp_LL_GetCh4FaultControlIntrFlag(const Eccp_RegisterMap_t *const Module)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    return Module->FAUCTL4.bits.FAUIF != 0U;
}

/**
 * @brief:配置通道4 滤波脉宽选择位
 * @param Module: 指向Eccp内存结构的指针
 * @param Width: 滤波脉宽选择值,范围:0~7
 *              滤除持续周期FVAL<2:0>+1
 * @retval void
 */
KF_INLINE void Eccp_LL_SetCh4FilterWidth(Eccp_RegisterMap_t *const Module, uint32_t Width)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));
    KF_ECCP_ASSERT(CHECK_ECCP_INPUT_0X7(Width));

    Module->FAUCTL4.bits.FVAL = Width;
}

/**
 * @brief:配置通道4 输出信号极性选择位
 * @param Module: 指向Eccp内存结构的指针
 * @param Polarity: 输出信号极性选择值, 可见 Eccp_FaultOutputPol_t
 * @retval void
 */
KF_INLINE void Eccp_LL_SetCh4OutputPolarity(Eccp_RegisterMap_t *const Module, Eccp_FaultOutputPol_t Polarity)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));
    KF_ECCP_ASSERT(CHECK_ECCP_FAULTOUTPUTPOL(Polarity));

    Module->FAUCTL4.bits.FINV = (uint32_t)Polarity;
}

/**
 * @brief:配置通道4 Fault控制高阻使能位
 * @param Module: 指向Eccp内存结构的指针
 * @param Enable:
 *          true   使能Fault控制输出高阻
 *          false   禁止Fault控制输出高阻
 * @retval void
 */
KF_INLINE void Eccp_LL_SetCh4FaultOutputHiZEnabled(Eccp_RegisterMap_t *const Module, bool Enable)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->FAUCTL4.bits.TRST = Enable ? 1U : 0U;
}

/**
 * @brief 选择ECCP通道工作模式
 *
 * @param Module 指向Eccp内存结构的指针
 * @param Channel Eccp通道, 具体值可见枚举 Eccp_Channel_t
 * @param Mode Eccp工作模式, 具体可见枚举 Eccp_Mode_t \n
 *          @attention PWM相关枚举量仅用于通道1
 * @retval void
 */
KF_INLINE void Eccp_LL_SelectMode(Eccp_RegisterMap_t *const Module, Eccp_Channel_t Channel, Eccp_Mode_t Mode)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));
    KF_ECCP_ASSERT(CHECK_ECCP_CHANNEL(Channel));
    KF_ECCP_ASSERT(CHECK_ECCP_MODE(Mode));

    REG_BITS_WRITE(
        Module->CTL1.reg, (uint32_t)0xFUL << ((uint32_t)Channel * 4U), (uint32_t)Mode << ((uint32_t)Channel * 4U));
}

/**
 * @brief 设置ECCP比较/PWM占空比寄存器
 *
 * @param Module 指向Eccp内存结构的指针
 * @param Channel Eccp通道, 具体值可见枚举 Eccp_Channel_t
 * @param Value 比较值
 * @retval void
 */
KF_INLINE void Eccp_LL_SetCompareResult(Eccp_RegisterMap_t *const Module, Eccp_Channel_t Channel, uint16_t Value)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));
    KF_ECCP_ASSERT(CHECK_ECCP_CHANNEL(Channel));

    switch (Channel)
    {
    case ECCP_CHANNEL_1:
        Module->R1.bits.ECCPXRY = Value;
        break;
    case ECCP_CHANNEL_2:
        Module->R2.bits.ECCPXRY = Value;
        break;
    case ECCP_CHANNEL_3:
        Module->R3.bits.ECCPXRY = Value;
        break;
    case ECCP_CHANNEL_4:
        Module->R4.bits.ECCPXRY = Value;
        break;
    default:
        (void)0U;
        break;
    }
}

/**
 * @brief: 设置更新使能0(控制 Tx)
 * @param Module: 指向Eccp内存结构的指针
 * @param State:
 *          true   更新使能0
 *          false   禁止更新使能0
 * @retval void
 */
KF_INLINE void Eccp_LL_SetTxUpdateEnabled(Eccp_RegisterMap_t *const Module, bool State)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->PXUDCTL.bits.PXUDEN0 = State ? 1U : 0U;
}

/**
 * @brief: 设置更新使能1(控制 Tz)
 * @param Module: 指向Eccp内存结构的指针
 * @param State:
 *          true   更新使能1
 *          false   禁止更新使能1
 * @retval void
 */
KF_INLINE void Eccp_LL_SetTzUpdateEnabled(Eccp_RegisterMap_t *const Module, bool State)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->PXUDCTL.bits.PXUDEN1 = State ? 1U : 0U;
}

/**
 * @brief: 设置更新事件控制0
 * @param Module: 指向Eccp内存结构的指针
 * @param State:
 *          true   立即更新以 Tx 为时基的输出控制寄存器
 *          false   当定时器 UDTIMX 为 0 时更新
 * @retval void
 */
KF_INLINE void Eccp_LL_SetUpdateEvent0State(Eccp_RegisterMap_t *const Module, bool State)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->PXUDCTL.bits.PXUDEVT0 = State ? 1U : 0U;
}

/**
 * @brief: 设置更新事件控制1
 * @param Module: 指向Eccp内存结构的指针
 * @param State:
 *          true   立即更新
 *          false   当定时器 UDTIMX 为 0 时更新
 * @retval void
 */
KF_INLINE void Eccp_LL_SetUpdateEvent1State(Eccp_RegisterMap_t *const Module, bool State)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->PXUDCTL.bits.PXUDEVT1 = State ? 1U : 0U;
}

/**
 * @brief: 设置更新事件控制2
 * @param Module: 指向Eccp内存结构的指针
 * @param State:
 *          true   立即更新
 *          false   当定时器 UDTIMX 为 0 时更新
 * @retval void
 */
KF_INLINE void Eccp_LL_SetUpdateEvent2State(Eccp_RegisterMap_t *const Module, bool State)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->PXUDCTL.bits.PXUDEVT2 = State ? 1U : 0U;
}

/**
 * @brief: 设置更新事件控制3
 * @param Module: 指向Eccp内存结构的指针
 * @param State:
 *          true   立即更新
 *          false   当定时器 UDTIMX 为 0 时更新
 * @retval void
 */
KF_INLINE void Eccp_LL_SetUpdateEvent3State(Eccp_RegisterMap_t *const Module, bool State)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->PXUDCTL.bits.PXUDEVT3 = State ? 1U : 0U;
}

/**
 * @brief: 配置相位移动使能位
 * @param Module: 指向Eccp内存结构的指针
 * @param State:
 *          true   开启PWM自动相移功能
 *          false   禁止
 * @retval void
 */
KF_INLINE void Eccp_LL_SetPhaseShiftEnabled(Eccp_RegisterMap_t *const Module, bool State)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->PXUDCTL.bits.PXMPEN = State ? 1U : 0U;
}

/**
 * @brief: 配置Tx 占空比和输出控制更新软件触发位
 * @param Module: 指向Eccp内存结构的指针
 * @param State:
 *          true   立即触发
 *          false   无
 * @retval void
 */
KF_INLINE void Eccp_LL_SetTxUpdateSoftware(Eccp_RegisterMap_t *const Module, bool State)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->PXUDCTL.bits.TXUDR = State ? 1U : 0U;
}

/**
 * @brief: 配置Tx 溢出脉冲更新占空比和输出控制功能使能位
 * @param Module: 指向Eccp内存结构的指针
 * @param State:
 *          true   开启 Tx 溢出脉冲更新占空比和输出控制功能
 *          false   关闭 Tx 溢出脉冲更新占空比和输出控制功能
 * @retval void
 */
KF_INLINE void Eccp_LL_SetTxOverflowUpdateEnabled(Eccp_RegisterMap_t *const Module, bool State)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->PXUDCTL.bits.TXIFUDREN = State ? 1U : 0U;
}

/**
 * @brief: 配置Tz 占空比和输出控制更新软件触发位
 * @param Module: 指向Eccp内存结构的指针
 * @param State:
 *          true   立即触发一次占空比和输出控制的更新
 *          false   无
 * @retval void
 */
KF_INLINE void Eccp_LL_SetTzUpdateSoftware(Eccp_RegisterMap_t *const Module, bool State)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->PXUDCTL.bits.TZUDR = State ? 1U : 0U;
}

/**
 * @brief: 配置Tz 溢出脉冲更新占空比和输出控制功能使能位
 * @param Module: 指向Eccp内存结构的指针
 * @param State:
 *          true   使能
 *          false   禁止
 * @retval void
 */
KF_INLINE void Eccp_LL_SetTzOverflowUpdateEnabled(Eccp_RegisterMap_t *const Module, bool State)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->PXUDCTL.bits.TZIFUDREN = State ? 1U : 0U;
}

/**
 * @brief 设置主模式选择位
 *
 * @param Module 指向Eccp内存结构的指针
 * @param MasterMode 主模式, 具体可见 Eccp_TimerMaster_t
 * @retval void
 */
KF_INLINE void Eccp_LL_SelectTxMasterMode(Eccp_RegisterMap_t *const Module, Eccp_TimerMaster_t MasterMode)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));
    KF_ECCP_ASSERT(CHECK_ECCP_TIMERMASTER(MasterMode));

    Module->CTL2.bits.TXMMS = (uint32_t)MasterMode;
}

/**
 * @brief 设置从模式选择位
 *
 * @param Module 指向Eccp内存结构的指针
 * @param Value 从模式, 具体可见 Eccp_TimerSlave_t
 * @retval void
 */
KF_INLINE void Eccp_LL_SelectTxSlaveMode(Eccp_RegisterMap_t *const Module, Eccp_TimerSlave_t SlaveMode)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));
    KF_ECCP_ASSERT(CHECK_ECCP_TIMERSLAVE(SlaveMode));

    Module->CTL2.bits.TXSMS = (uint32_t)SlaveMode;
}

/**
 * @brief: 设置触发输入TRGI选择位
 * @param Module: 指向Eccp内存结构的指针
 * @param Value: 触发输入TRGI选择位的值, 可见 Eccp_Trig_t
 * @retval void
 */
KF_INLINE void Eccp_LL_SelectTxInputTrigger(Eccp_RegisterMap_t *const Module, Eccp_Trig_t Value)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));
    KF_ECCP_ASSERT(CHECK_ECCP_TRIG(Value));

    Module->CTL2.bits.TXTS = (uint32_t)Value;
}

/**
 * @brief: 设置主从模式同步位
 * @param Module: 指向Eccp内存结构的指针
 * @param State:
 *          true   触发输入上的事件将被延迟
 *          false   未使能
 * @retval void
 */
KF_INLINE void Eccp_LL_SetMasterSlaveSyncEnabled(Eccp_RegisterMap_t *const Module, bool State)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->CTL2.bits.TXMSSYNC = State ? 1U : 0U;
}

/**
 * @brief: 设置单脉冲输出模式
 * @param Module: 指向Eccp内存结构的指针
 * @param State:
 *          true   使能单脉冲输出模式
 *          false   未使能
 * @retval void
 */
KF_INLINE void Eccp_LL_SetSinglePluseOutputEnabled(Eccp_RegisterMap_t *const Module, bool State)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->CTL2.bits.PXSPM = State ? 1U : 0U;
}

/**
 * @brief: 设置输入异或使能位
 * @param Module: 指向Eccp内存结构的指针
 * @param State:
 *          true   使能输入异或
 *          false   未使能
 * @retval void
 */
KF_INLINE void Eccp_LL_SetInputXorEnabled(Eccp_RegisterMap_t *const Module, bool State)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->CTL2.bits.PXXORM = State ? 1U : 0U;
}

/**
 * @brief: 设置PWM输入测量模式使能位
 * @param Module: 指向Eccp内存结构的指针
 * @param State:
 *          true   使能 PWM 输入测量模式
 *          false   未使能
 * @retval void
 */
KF_INLINE void Eccp_LL_SetPwmMeasurementEnabled(Eccp_RegisterMap_t *const Module, bool State)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->CTL2.bits.PXPWMI = State ? 1U : 0U;
}

/**
 * @brief: 设置Tz(z=6)从模式选择位
 * @param Module: 指向Eccp内存结构的指针
 * @param Value: Tz(z=6)从模式选择位的值, 具体可见 Eccp_TimerSlave_t
 * @retval void
 */
KF_INLINE void Eccp_LL_SelectTzSlaveMode(Eccp_RegisterMap_t *const Module, Eccp_TimerSlave_t SlaveMode)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));
    KF_ECCP_ASSERT(CHECK_ECCP_TIMERSLAVE(SlaveMode));

    Module->CTL2.bits.TZSMS = (uint32_t)SlaveMode;
}

/**
 * @brief: 设置Tz为时基的PWM死区延时时间
 * @param Module: 指向Eccp内存结构的指针
 * @param Time: 设置通道 4 的死区延时时间,取值范围0~255
 * @retval void
 */
KF_INLINE void Eccp_LL_SetTzDeadZoneDelayTime(Eccp_RegisterMap_t *const Module, uint8_t Time)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->PXDTCTL.bits.PZDC = Time;
}

/**
 * @brief: 设置Tx为时基的PWM死区延时时间
 * @param Module: 指向Eccp内存结构的指针
 * @param Time: 设置通道 3 的死区延时的时间,取值范围0~255
 * @retval void
 */
KF_INLINE void Eccp_LL_SetTxDeadZoneDelayTime(Eccp_RegisterMap_t *const Module, uint8_t Time)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->PXDTCTL.bits.PXDC = Time;
}

/**
 * @brief 设置通道端口输出控制
 *
 * @param Module 指向Eccp内存结构的指针
 * @param Channel Eccp通道, 可见 Eccp_Channel_t
 * @param ChPin Eccp通道端口, 可见 Eccp_ChannelPin_t
 * @param Output 输出控制, 可见 Eccp_OutputCtrl_t
 * @retval void
 */
KF_INLINE void Eccp_LL_SetOutputCtrl(
    Eccp_RegisterMap_t *const Module, Eccp_Channel_t Channel, Eccp_ChannelPin_t ChPin, Eccp_OutputCtrl_t Output)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));
    KF_ECCP_ASSERT(CHECK_ECCP_CHANNEL(Channel));
    KF_ECCP_ASSERT(CHECK_ECCP_CHANNELPIN(ChPin));
    KF_ECCP_ASSERT(CHECK_ECCP_OUTPUTCTRL(Output));

    uint32_t Mask;

    Mask = ((uint32_t)Channel << 2U) + ((uint32_t)ChPin << 1U);
    REG_BITS_WRITE(Module->PWMXOC.reg, 0x3UL << Mask, (uint32_t)Output << Mask);
}

/**
 * @brief 获取通道端口输出控制
 *
 * @param Module 指向Eccp内存结构的指针
 * @param Channel Eccp通道, 可见 Eccp_Channel_t
 * @retval void
 */
KF_INLINE Eccp_OutputCtrl_t
Eccp_LL_GetOutputCtrl(const Eccp_RegisterMap_t *const Module, Eccp_Channel_t Channel, Eccp_ChannelPin_t ChPin)
{
    uint32_t Mask = ((uint32_t)Channel << 2U) + ((uint32_t)ChPin << 1U);
    /* PRQA S 3469 1 #KQR003469 */
    uint32_t tmpOutputControl = REG_BITS_READ(Module->PWMXOC.reg, 0x3UL << Mask, Mask);
    return (Eccp_OutputCtrl_t)tmpOutputControl;
}

/**
 * @brief PWM通道输出配置
 *
 * @param Module 指向Eccp内存结构的指针
 * @param Channel Eccp通道, 可见 Eccp_Channel_t
 * @param PwmOutput 通道输出模式, 可见 Eccp_PwmOutput_t
 * @retval void
 */
KF_INLINE void
Eccp_LL_SetPwmOutputMode(Eccp_RegisterMap_t *const Module, Eccp_Channel_t Channel, Eccp_PwmOutput_t PwmOutput)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));
    KF_ECCP_ASSERT(CHECK_ECCP_CHANNEL(Channel));
    KF_ECCP_ASSERT(CHECK_ECCP_PWMOUTPUT(PwmOutput));

    uint32_t Mask;

    Mask = (uint32_t)Channel + 8U;
    REG_BITS_WRITE(Module->PXATRCTL.reg, 0x1UL << Mask, (uint32_t)PwmOutput << Mask);
}

/**
 * @brief 选择通道自动关闭源
 *
 * @param Module 指向Eccp内存结构的指针
 * @param Channel Eccp通道, 可见 Eccp_Channel_t
 * @param Source 自动关断源, 可见 Eccp_ShutOffSrc_t
 * @retval void
 */
KF_INLINE void
Eccp_LL_SelectShutOffSource(Eccp_RegisterMap_t *const Module, Eccp_Channel_t Channel, Eccp_ShutOffSrc_t Source)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));
    KF_ECCP_ASSERT(CHECK_ECCP_CHANNEL(Channel));
    KF_ECCP_ASSERT(CHECK_ECCP_SHUTOFFSRC(Source));

    uint32_t Mask;

    Mask = (uint32_t)Channel << 0x1U;
    REG_BITS_WRITE(Module->PXASCTL0.reg, 0x3UL << Mask, (uint32_t)Source << Mask);
}

/**
 * @brief 获取通道自动关闭事件状态
 *
 * @param Module 指向Eccp内存结构的指针
 * @param Channel Eccp通道, 可见 Eccp_Channel_t
 * @retval bool 自动关闭事件状态 \n
 *          true -- 发生了关闭事件 \n
 *          false -- 正常工作
 */
KF_INLINE bool Eccp_LL_GetShutOffState(const Eccp_RegisterMap_t *const Module, Eccp_Channel_t Channel)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));
    KF_ECCP_ASSERT(CHECK_ECCP_CHANNEL(Channel));

    uint32_t Mask;

    Mask = (uint32_t)Channel + 0x8U;
    /* PRQA S 3469 1 #KQR003469 */
    return (REG_BITS_READ(Module->PXASCTL0.reg, 0x1UL << Mask, Mask) != 0U);
}

/**
 * @brief 设置引脚关闭状态
 *
 * @param Module 指向Eccp内存结构的指针
 * @param Channel Eccp通道, 可见 Eccp_Channel_t
 * @param ChPin Eccp通道端口, 可见 Eccp_ChannelPin_t
 * @param State 引脚关闭状态, 可见 Eccp_OffState_t
 * @retval void
 */
KF_INLINE void Eccp_LL_SetPinOutputShutOffState(
    Eccp_RegisterMap_t *const Module, Eccp_Channel_t Channel, Eccp_ChannelPin_t ChPin, Eccp_OffState_t State)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));
    KF_ECCP_ASSERT(CHECK_ECCP_CHANNEL(Channel));
    KF_ECCP_ASSERT(CHECK_ECCP_CHANNELPIN(ChPin));
    KF_ECCP_ASSERT(CHECK_ECCP_OFFSTATE(State));

    uint32_t Mask;

    Mask = ((uint32_t)Channel << 2U) + ((uint32_t)ChPin << 1U);
    REG_BITS_WRITE(Module->PXASCTL1.reg, 0x3UL << Mask, (uint32_t)State << Mask);
}

/**
 * @brief 设置ECCP中断
 *
 * @param Module 指向Eccp内存结构的指针
 * @param IntIndex 设置中断序号, 可见 Eccp_IntrSetIndex_t
 * @param State 中断使能状态
 * @retval void
 */
KF_INLINE void Eccp_LL_SetIntrEnabled(Eccp_RegisterMap_t *const Module, Eccp_IntrSetIndex_t IntIndex, bool State)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));
    KF_ECCP_ASSERT(CHECK_ECCP_INTRSETINDEX(IntIndex));

    REG_BITS_WRITE(Module->IE.reg, 0x1UL << (uint32_t)IntIndex, (State ? 1UL : 0UL) << (uint32_t)IntIndex);
}

/**
 * @brief 获取ECCP中断状态
 *
 * @param Module 指向Eccp内存结构的指针
 * @param IntIndex 获取中断序号, 可见 Eccp_IntrGetIndex_t
 * @retval bool 中断状态
 */
KF_INLINE bool Eccp_LL_GetIntrFlag(const Eccp_RegisterMap_t *const Module, Eccp_IntrGetIndex_t IntIndex)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));
    KF_ECCP_ASSERT(CHECK_ECCP_INTRGETINDEX(IntIndex));

    /* PRQA S 3469 1 #KQR003469 */
    return (REG_BITS_READ(Module->EGIF.reg, 0x1UL << (uint32_t)IntIndex, (uint32_t)IntIndex) != 0U);
}

/**
 * @brief 产生通道捕捉/比较事件
 *
 * @param Module 指向Eccp内存结构的指针
 * @param Channel Eccp通道, 可见 Eccp_Channel_t
 * @retval void
 */
KF_INLINE void Eccp_LL_GenerateCapOrCmpEvent(Eccp_RegisterMap_t *const Module, Eccp_Channel_t Channel)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));
    KF_ECCP_ASSERT(CHECK_ECCP_CHANNEL(Channel));

    uint32_t Mask;

    Mask = 1U + (uint32_t)Channel;
    REG_BIT_SET(Module->EGIF.reg, (0x1UL << Mask));
}

/**
 * @brief 产生触发事件
 *
 * @param Module
 * @retval void
 */
KF_INLINE void Eccp_LL_GenerateTxSoftwareTrigEvent(Eccp_RegisterMap_t *const Module)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->EGIF.bits.TXTRG = 1U;
}

/**
 * @brief:  设置UDTIMX寄存器的Tx更新计数器的值
 * @param Module: 指向Eccp内存结构的指针
 * @param Value: 要写入UDTIMX的Tx更新计数器的值
 * @retval void
 */
KF_INLINE void Eccp_LL_SetTxUpdateCounter(Eccp_RegisterMap_t *const Module, uint8_t Value)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->UDTIMX.bits.UDCNT = Value;
}

/**
 * @brief:  设置UDTIMZ寄存器的Tz更新计数器的值
 * @param Module: 指向Eccp内存结构的指针
 * @param Value: 要写入UDTIMZ的Tz更新计数器的值
 * @retval void
 */
KF_INLINE void Eccp_LL_SetTzUpdateCounter(Eccp_RegisterMap_t *const Module, uint8_t Value)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->UDTIMZ.bits.UDCNT = Value;
}

/**
 * @brief 获取DMA请求标志
 *
 * @param Module 指向Eccp内存结构的指针
 * @param DmaIndex Dma请求序号, 可见 Eccp_DmaIndex_t
 * @retval bool Dma请求标志状态
 */
KF_INLINE bool Eccp_LL_GetDmaRequestFlag(const Eccp_RegisterMap_t *const Module, Eccp_DmaIndex_t DmaIndex)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));
    KF_ECCP_ASSERT(CHECK_ECCP_DMAINDEX(DmaIndex));

    /* PRQA S 3469 1 #KQR003469 */
    return (REG_BITS_READ(Module->DF.reg, 0x1UL << (uint32_t)DmaIndex, (uint32_t)DmaIndex) != 0U);
}

/**
 * @brief 获取通道的ECCP捕捉寄存器的值
 *
 * @param Module 指向Eccp内存结构的指针
 * @param Channel Eccp通道, 可见 Eccp_Channel_t
 * @retval uint16_t 捕捉值, 0x0 ~ 0xFFFF
 */
KF_INLINE uint16_t Eccp_LL_GetCaptureValue(const Eccp_RegisterMap_t *const Module, Eccp_Channel_t Channel)
{
    volatile uint16_t CaptureValue = 0;
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));
    KF_ECCP_ASSERT(CHECK_ECCP_CHANNEL(Channel));

    switch (Channel)
    {
    case ECCP_CHANNEL_1:
        CaptureValue = (uint16_t)Module->C1.bits.ECCPXCY;
        break;
    case ECCP_CHANNEL_2:
        CaptureValue = (uint16_t)Module->C2.bits.ECCPXCY;
        break;
    case ECCP_CHANNEL_3:
        CaptureValue = (uint16_t)Module->C3.bits.ECCPXCY;
        break;
    case ECCP_CHANNEL_4:
        CaptureValue = (uint16_t)Module->C4.bits.ECCPXCY;
        break;

    default:
        CaptureValue = (uint16_t)0U;
        break;
    }
    return CaptureValue;
}

/**
 * @brief 设置DMA请求使能状态
 *
 * @param Module 指向Eccp内存结构的指针
 * @param DmaIndex Dma请求序号, 可见 Eccp_DmaIndex_t
 * @param State 使能状态
 * @retval void
 */
KF_INLINE void Eccp_LL_SetDmaRequestEnabled(Eccp_RegisterMap_t *const Module, Eccp_DmaIndex_t DmaIndex, bool State)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));
    KF_ECCP_ASSERT(CHECK_ECCP_DMAINDEX(DmaIndex));

    REG_BITS_WRITE(Module->DE.reg, 0x1UL << (uint32_t)DmaIndex, (State ? 1UL : 0UL) << (uint32_t)DmaIndex);
}

/**
 * @brief 清除中断标志
 *
 * @param Module 指向Eccp内存结构的指针
 * @param IntIndex 中断序号, 可见 Eccp_IntIndex_t
 * @retval void
 */
KF_INLINE void Eccp_LL_ClearIntrFlag(Eccp_RegisterMap_t *const Module, Eccp_IntrClearIndex_t IntIndex)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));
    KF_ECCP_ASSERT(CHECK_ECCP_INTRCLEARINDEX(IntIndex));

    REG_BIT_SET(Module->SRIC.reg, 0x1UL << (uint32_t)IntIndex);
    NOP();
    NOP();
    NOP();
    NOP();
    REG_BIT_CLR(Module->SRIC.reg, 0x1UL << (uint32_t)IntIndex);
}

/**
 * @brief:  设置单脉冲输出模式选择
 * @param Module: 指向Eccp内存结构的指针
 * @param State:
 *          true   单脉冲输出后关闭定时器使能位
 *          false   单脉冲输出后不关闭定时器使能位
 * @retval void
 */
KF_INLINE void Eccp_LL_SelectSinglePluseOutputMode(Eccp_RegisterMap_t *const Module, bool State)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->CTL3.bits.PXSPMST = State ? 1U : 0U;
}

/**
 * @brief:  设置Tx,Tz联立使能位
 * @param Module: 指向Eccp内存结构的指针
 * @param State:
 *          true   使能联立
 *          false   不使能联立
 * @retval void
 */
KF_INLINE void Eccp_LL_SetTxTzCombineEnabled(Eccp_RegisterMap_t *const Module, bool State)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->CTL3.bits.TUNITE = State ? 1U : 0U;
}

/**
 * @brief:  设置PWMx通道1/2/3/4重启使能位
 * @param Module: 指向Eccp内存结构的指针
 * @param State:
 *          true   自动关闭时,当关闭事件消失,PXASE 位将自动清零,EPWM 自动重启
 *          false   自动关闭时,PXASE 由软件清零,以重启 EPWM
 * @retval void
 */
KF_INLINE void Eccp_LL_SetPwmRestartEnabled(Eccp_RegisterMap_t *const Module, bool State)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->CTL3.bits.PXRSEN = State ? 1U : 0U;
}

/**
 * @brief:  设置联合输出使能位
 * @param Module: 指向Eccp内存结构的指针
 * @param State:
 *          true   联合输出使能
 *          false   联合输出禁用
 * @retval void
 */
KF_INLINE void Eccp_LL_SetCombineOutputEnabled(Eccp_RegisterMap_t *const Module, bool State)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->CTL3.bits.COMBEN = State ? 1U : 0U;
}

/**
 * @brief:  设置联合输出信号有效沿选择
 * @param Module: 指向Eccp内存结构的指针
 * @param Mode: 联合输出信号有效沿选择, 具体可见 Eccp_ComOutputEdge_t
 * @retval void
 */
KF_INLINE void Eccp_LL_SelectCombineOutputEdge(Eccp_RegisterMap_t *const Module, Eccp_ComOutputEdge_t Mode)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));
    KF_ECCP_ASSERT(CHECK_ECCP_COMOUTPUTEDGE(Mode));

    Module->CTL3.bits.COMINV = (uint32_t)Mode;
}

/**
 * @brief:  设置捕捉测试模式触发信号
 * @param Module: 指向Eccp内存结构的指针
 * @param State:
 *          true   触发捕捉测试模式
 *          false   计数器正常工作
 * @retval void
 */
KF_INLINE void Eccp_LL_SetCapTestState(Eccp_RegisterMap_t *const Module, bool State)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->CTL3.bits.CAPTST = State ? 1U : 0U;
}

/**
 * @brief:  设置 GTB 模式使能位
 * @param Module: 指向Eccp内存结构的指针
 * @param State:
 *          true   使能 GTB 模式
 *          false   禁用 GTB 模式
 * @retval void
 */
KF_INLINE void Eccp_LL_SetGtbModeEnabled(Eccp_RegisterMap_t *const Module, bool State)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->CTL3.bits.GTBEN = State ? 1U : 0U;
}

/**
 * @brief:  设置 GTB 模式输出位
 * @param Module: 指向Eccp内存结构的指针
 * @param State:
 * @retval void
 */
KF_INLINE void Eccp_LL_SetGtbOutput(Eccp_RegisterMap_t *const Module, bool State)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->CTL3.bits.GTBEOUT = State ? 1U : 0U;
}

/**
 * @brief 择通道调制模式选
 *
 * @param Module 指向Eccp内存结构的指针
 * @param Channel Eccp通道, 可见 Eccp_Channel_t
 * @param State 调制模式
 *          true   输出调制后得到最终输出波形
 *          false   正常输出 PWM/比较结果波形
 * @retval void
 */
KF_INLINE void Eccp_LL_SelectModulateMode(Eccp_RegisterMap_t *const Module, Eccp_Channel_t Channel, bool State)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));
    KF_ECCP_ASSERT(CHECK_ECCP_CHANNEL(Channel));

    uint32_t Mask;

    Mask = 9U + (uint32_t)Channel;
    REG_BITS_WRITE(Module->CTL3.reg, 0x1UL << Mask, (State ? 1UL : 0UL) << Mask);
}

/**
 * @brief 设置通道捕捉事件预分频
 *
 * @param Module 指向Eccp内存结构的指针
 * @param Channel Eccp通道, 可见 Eccp_Channel_t
 * @param Scaler 预分频值, 0x0 ~ 0xF
 * @retval void
 */
KF_INLINE void Eccp_LL_SetCapturePrescaler(Eccp_RegisterMap_t *const Module, Eccp_Channel_t Channel, uint32_t Scaler)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));
    KF_ECCP_ASSERT(CHECK_ECCP_CHANNEL(Channel));
    KF_ECCP_ASSERT(CHECK_ECCP_INPUT_0XF(Scaler));

    uint32_t Mask;

    Mask = (uint32_t)Channel << 2U;
    REG_BITS_WRITE(Module->CAPPRSC.reg, 0xFUL << Mask, Scaler << Mask);
}

/**
 * @brief 设置通道捕捉次数
 *
 * @param Module 指向Eccp内存结构的指针
 * @param Channel Eccp通道, 可见 Eccp_Channel_t
 * @param Value 捕捉次数, 0x0 ~ 0xF
 * @retval void
 */
KF_INLINE void Eccp_LL_SetCaptureTimes(Eccp_RegisterMap_t *const Module, Eccp_Channel_t Channel, uint32_t Value)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));
    KF_ECCP_ASSERT(CHECK_ECCP_CHANNEL(Channel));
    KF_ECCP_ASSERT(CHECK_ECCP_INPUT_0XF(Value));

    uint32_t Mask;

    Mask = (uint32_t)Channel << 2U;
    REG_BITS_WRITE(Module->CAPTIME.reg, 0xFUL << Mask, Value << Mask);
}

/**
 * @brief 设置通道的捕捉使能位
 *
 * @param Module 指向Eccp内存结构的指针
 * @param Channel Eccp通道, 可见 Eccp_Channel_t
 * @param State 使能状态
 * @retval void
 */
KF_INLINE void Eccp_LL_SetCaptureEnabled(Eccp_RegisterMap_t *const Module, Eccp_Channel_t Channel, bool State)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));
    KF_ECCP_ASSERT(CHECK_ECCP_CHANNEL(Channel));

    REG_BITS_WRITE(Module->CAPCTL1.reg, 0x1UL << (uint32_t)Channel, (State ? 1UL : 0UL) << (uint32_t)Channel);
}

/**
 * @brief 设置通道捕捉有效沿
 *
 * @param Module 指向Eccp内存结构的指针
 * @param Channel Eccp通道, 可见 Eccp_Channel_t
 * @param Edge 有效边沿
 *          true -- 下降沿捕捉
 *          false -- 上升沿捕捉
 * @retval void
 */
KF_INLINE void Eccp_LL_SetCaptureEdge(Eccp_RegisterMap_t *const Module, Eccp_Channel_t Channel, bool Edge)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));
    KF_ECCP_ASSERT(CHECK_ECCP_CHANNEL(Channel));

    uint32_t Mask;

    Mask = 4U + (uint32_t)Channel;
    REG_BITS_WRITE(Module->CAPCTL1.reg, 0x1UL << Mask, (Edge ? 1UL : 0UL) << Mask);
}

/**
 * @brief 设置通道捕捉模式
 *
 * @param Module 指向Eccp内存结构的指针
 * @param Channel Eccp通道, 可见 Eccp_Channel_t
 * @param Mode 捕捉模式
 *          true -- 单次捕捉
 *          false -- 连续捕捉
 * @retval void
 */
KF_INLINE void Eccp_LL_SetCaptureMode(Eccp_RegisterMap_t *const Module, Eccp_Channel_t Channel, bool Mode)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));
    KF_ECCP_ASSERT(CHECK_ECCP_CHANNEL(Channel));

    uint32_t Mask;

    Mask = 8U + (uint32_t)Channel;
    REG_BITS_WRITE(Module->CAPCTL1.reg, 0x1UL << Mask, (Mode ? 1UL : 0UL) << Mask);
}

/**
 * @brief 设置通道捕捉次数控制位
 *
 * @param Module 指向Eccp内存结构的指针
 * @param Channel Eccp通道, 可见 Eccp_Channel_t
 * @param State 通道捕捉次数状态
 *          true -- 捕捉次数由 CAPTIME 寄存器决定
 *          false -- 不控制捕捉次数
 * @retval void
 */
KF_INLINE void Eccp_LL_SetCaptureTimesControllable(Eccp_RegisterMap_t *const Module, Eccp_Channel_t Channel, bool State)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));
    KF_ECCP_ASSERT(CHECK_ECCP_CHANNEL(Channel));

    uint32_t Mask;

    Mask = 12U + (uint32_t)Channel;
    REG_BITS_WRITE(Module->CAPCTL1.reg, 0x1UL << Mask, (State ? 1UL : 0UL) << Mask);
}

/**
 * @brief 选择通道1的捕捉输入引脚
 *
 * @param Module 指向Eccp内存结构的指针
 * @param Pin 捕捉输入引脚, 可见Eccp_Ch1CapPin_t
 * @retval void
 */
KF_INLINE void Eccp_LL_SelectCh1CapturePin(Eccp_RegisterMap_t *const Module, Eccp_Ch1CapPin_t Pin)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));
    KF_ECCP_ASSERT(CHECK_ECCP_CH1_CAPPIN(Pin));

    Module->CAPCTL2.bits.CH1CAPPIN = (uint32_t)Pin;
}

/**
 * @brief 选择通道2的捕捉输入引脚
 *
 * @param Module 指向Eccp内存结构的指针
 * @param Pin 捕捉输入引脚, 可见Eccp_Ch2CapPin_t
 * @retval void
 */
KF_INLINE void Eccp_LL_SelectCh2CapturePin(Eccp_RegisterMap_t *const Module, Eccp_Ch2CapPin_t Pin)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));
    KF_ECCP_ASSERT(CHECK_ECCP_CH2_CAPPIN(Pin));

    Module->CAPCTL2.bits.CH2CAPPIN = (uint32_t)Pin;
}

/**
 * @brief 选择通道3的捕捉输入引脚
 *
 * @param Module 指向Eccp内存结构的指针
 * @param Pin 捕捉输入引脚, 可见Eccp_Ch3CapPin_t
 * @retval void
 */
KF_INLINE void Eccp_LL_SelectCh3CapturePin(Eccp_RegisterMap_t *const Module, Eccp_Ch3CapPin_t Pin)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));
    KF_ECCP_ASSERT(CHECK_ECCP_CH3_CAPPIN(Pin));

    Module->CAPCTL2.bits.CH3CAPPIN = (uint32_t)Pin;
}

/**
 * @brief 选择通道4的捕捉输入引脚
 *
 * @param Module 指向Eccp内存结构的指针
 * @param Pin 捕捉输入引脚, 可见Eccp_Ch4CapPin_t
 * @retval void
 */
KF_INLINE void Eccp_LL_SelectCh4CapturePin(Eccp_RegisterMap_t *const Module, Eccp_Ch4CapPin_t Pin)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));
    KF_ECCP_ASSERT(CHECK_ECCP_CH4_CAPPIN(Pin));

    Module->CAPCTL2.bits.CH4CAPPIN = (uint32_t)Pin;
}

/**
 * @brief 设置通道捕捉输入滤波时钟分频
 *
 * @param Module 指向Eccp内存结构的指针
 * @param Channel Eccp通道, 可见 Eccp_Channel_t
 * @param Scaler 滤波时钟分频, 0x0 ~ 0xF
 * @retval void
 */
KF_INLINE void Eccp_LL_SetFilterClkScaler(Eccp_RegisterMap_t *const Module, Eccp_Channel_t Channel, uint32_t Scaler)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));
    KF_ECCP_ASSERT(CHECK_ECCP_CHANNEL(Channel));
    KF_ECCP_ASSERT(CHECK_ECCP_INPUT_0XF(Scaler));

    uint32_t Mask;

    Mask = (uint32_t)Channel << 2U;
    REG_BITS_WRITE(Module->FLCLKP.reg, 0xFUL << Mask, (uint32_t)Scaler << Mask);
}

/**
 * @brief 设置捕捉输入滤波次数
 *
 * @param Module 指向Eccp内存结构的指针
 * @param Channel Eccp通道, 可见 Eccp_Channel_t
 * @param Times 滤波次数, 0x0 ~ 0x7
 * @retval void
 */
KF_INLINE void Eccp_LL_SetFilterTimes(Eccp_RegisterMap_t *const Module, Eccp_Channel_t Channel, uint32_t Times)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));
    KF_ECCP_ASSERT(CHECK_ECCP_CHANNEL(Channel));
    KF_ECCP_ASSERT(CHECK_ECCP_INPUT_0X7(Times));

    uint32_t Mask;

    Mask = (uint32_t)Channel * 3U;
    REG_BITS_WRITE(Module->FILTER.reg, 0x7UL << Mask, (uint32_t)Times << Mask);
}

/**
 * @brief: 设置Tx相位重载使能位
 * @param Module: 指向Eccp内存结构的指针
 * @param State:
 *          true   使能Tx相位重载
 *          false   禁用Tx相位重载
 * @retval void
 */
KF_INLINE void Eccp_LL_SetTxPhaseShiftEnabled(Eccp_RegisterMap_t *const Module, bool State)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->PHSCTLX.bits.PHSENX = State ? 1U : 0U;
}

/**
 * @brief: 设置Tx相位重载模式选择
 * @param Module: 指向Eccp内存结构的指针
 * @param Mode:
 *          true   配置为单次模式
 *          false   配置为连续模式
 * @retval void
 */
KF_INLINE void Eccp_LL_SetTxPhaseShiftMode(Eccp_RegisterMap_t *const Module, bool Mode)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->PHSCTLX.bits.PHSXMODE = Mode ? 1U : 0U;
}

/**
 * @brief: 设置Tx相位重载软件触发位
 * @param Module: 指向Eccp内存结构的指针
 * @param State:
 *          true   软件触发Tx相位重载
 *          false   无动作
 * @retval void
 */
KF_INLINE void Eccp_LL_TrigTxPhaseShiftSoftware(Eccp_RegisterMap_t *const Module, bool State)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->PHSCTLX.bits.PHSWTX = State ? 1U : 0U;
}

/**
 * @brief: 设置Tx相位重载时机选择位
 * @param Module: 指向Eccp内存结构的指针
 * @param Sel: 相位重载时机, 可见 Eccp_PhaseShiftTime_t
 * @retval void
 */
KF_INLINE void Eccp_LL_SelectTxPhaseShiftTime(Eccp_RegisterMap_t *const Module, Eccp_PhaseShiftTime_t Sel)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));
    KF_ECCP_ASSERT(CHECK_ECCP_PHASESHIFTTIME(Sel));

    Module->PHSCTLX.bits.PHSXSEL = (uint32_t)Sel;
}

/**
 * @brief: 设置Tx相位重载事件预分频
 * @param Module: 指向Eccp内存结构的指针
 * @param Scaler: 分频系数, 0x0 ~ 0xF
 * @retval void
 */
KF_INLINE void Eccp_LL_SetTxPhaseShiftPrescaler(Eccp_RegisterMap_t *const Module, uint8_t Scaler)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));
    KF_ECCP_ASSERT(CHECK_ECCP_INPUT_0XF(Scaler));

    Module->PHSCTLX.bits.PHSXPRSC = Scaler;
}

/**
 * @brief: 设置Tx相位重载次数
 * @param Module: 指向Eccp内存结构的指针
 * @param Times: 相应的次数, 0x1 ~ 0xF
 * @retval void
 */
KF_INLINE void Eccp_LL_SetTxPhaseShiftTimes(Eccp_RegisterMap_t *const Module, uint8_t Times)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));
    KF_ECCP_ASSERT(CHECK_ECCP_INPUT_0X7(Times));

    Module->PHSCTLX.bits.PHSXTIME = ((0U == Times) ? 1U : Times);
}

/**
 * @brief: 设置Tx相位重载次数控制位
 * @param Module: 指向Eccp内存结构的指针
 * @param State:
 *          true   重载次数由PHSXTIME<3:0>决定
 *          false   禁用自动重载模式
 * @retval void
 */
KF_INLINE void Eccp_LL_SetTxPhaseShiftTimesControllable(Eccp_RegisterMap_t *const Module, bool State)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->PHSCTLX.bits.PHSXTIEN = State ? 1U : 0U;
}

/**
 * @brief: 设置Tx相位重载发生后的计数方向
 * @param Module: 指向Eccp内存结构的指针
 * @param Dir:
 *          true   相位重载之后向上计数
 *          false   相位重载之后向下计数
 * @retval void
 */
KF_INLINE void Eccp_LL_SetTxPhaseShiftDirection(Eccp_RegisterMap_t *const Module, bool Dir)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->PHSCTLX.bits.PHSXDIR = Dir ? 1U : 0U;
}

/**
 * @brief: 设置Tz相位重载使能位
 * @param Module: 指向Eccp内存结构的指针
 * @param State:
 *          true   使能Tz相位重载
 *          false   禁用Tz相位重载
 * @retval void
 */
KF_INLINE void Eccp_LL_SetTzPhaseShiftEnabled(Eccp_RegisterMap_t *const Module, bool State)
{
    Module->PHSCTLZ.bits.PHSENZ = State ? 1U : 0U;
}

/**
 * @brief: 设置Tz相位重载模式选择
 * @param Module: 指向Eccp内存结构的指针
 * @param State:
 *          true   配置为单次模式
 *          false   配置为连续模式
 * @retval void
 */
KF_INLINE void Eccp_LL_SetTzPhaseShiftMode(Eccp_RegisterMap_t *const Module, bool State)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->PHSCTLZ.bits.PHSZMODE = State ? 1U : 0U;
}

/**
 * @brief: 设置Tz相位重载软件触发位
 * @param Module: 指向Eccp内存结构的指针
 * @param State:
 *          true   软件触发Tx相位重载
 *          false   无动作
 * @retval void
 */
KF_INLINE void Eccp_LL_TrigTzPhaseShiftSoftware(Eccp_RegisterMap_t *const Module, bool State)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->PHSCTLZ.bits.PHSWTZ = State ? 1U : 0U;
}

/**
 * @brief: 设置Tz相位重载时机选择位
 * @param Module: 指向Eccp内存结构的指针
 * @param Sel: 相位重载时机, 可见 Eccp_PhaseShiftTime_t
 * @retval void
 */
KF_INLINE void Eccp_LL_SelectTzPhaseShiftTime(Eccp_RegisterMap_t *const Module, Eccp_PhaseShiftTime_t Sel)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));
    KF_ECCP_ASSERT(CHECK_ECCP_PHASESHIFTTIME(Sel));

    Module->PHSCTLZ.bits.PHSZSEL = (uint32_t)Sel;
}

/**
 * @brief: 设置Tz相位重载事件预分频
 * @param Module: 指向Eccp内存结构的指针
 * @param Scaler: 分频系数, 0x0 ~ 0xF
 * @retval void
 */
KF_INLINE void Eccp_LL_SetTzPhaseShiftPrescaler(Eccp_RegisterMap_t *const Module, uint8_t Scaler)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));
    KF_ECCP_ASSERT(CHECK_ECCP_INPUT_0XF(Scaler));

    Module->PHSCTLZ.bits.PHSZPRSC = Scaler;
}

/**
 * @brief: 设置Tz相位重载次数
 * @param Module: 指向Eccp内存结构的指针
 * @param Times: Tz相位重载次数,范围 0x1 ~ 0xF
 * @retval void
 */
KF_INLINE void Eccp_LL_SetTzPhaseShiftTimes(Eccp_RegisterMap_t *const Module, uint8_t Times)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));
    KF_ECCP_ASSERT(CHECK_ECCP_INPUT_0XF(Times));

    Module->PHSCTLZ.bits.PHSZTIME = ((0U == Times) ? 1U : Times);
}

/**
 * @brief: 设置Tz相位重载次数控制位
 * @param Module: 指向Eccp内存结构的指针
 * @param State:
 *          true   重载次数由PHSZTIME<3:0>决定
 *          false   不限重载次数
 * @retval void
 */
KF_INLINE void Eccp_LL_SetTzPhaseShiftTimesControllable(Eccp_RegisterMap_t *const Module, bool State)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->PHSCTLZ.bits.PHSZTIEN = State ? 1U : 0U;
}

/**
 * @brief 设置 Tz 相位重载后的计数方向
 *
 * @param Module: 指向Eccp内存结构的指针
 * @param Direction 计数方向 \n
 *              false - 相位重载之后向下计数 \n
 *              true  - 相位重载之后向上计数
 * @retval void
 */
KF_INLINE void Eccp_LL_SetTzPhaseReloadDirection(Eccp_RegisterMap_t *const Module, bool Direction)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->PHSCTLZ.bits.PHSZDIR = Direction ? 1U : 0U;
}

/**
 * @brief: 设置ECCP模块通道Tx相位值
 * @param Module: 指向Eccp内存结构的指针
 * @param Value: 相位值,取值范围为0-65535
 * @retval void
 */
KF_INLINE void Eccp_LL_SetTxPhaseShiftValue(Eccp_RegisterMap_t *const Module, uint16_t Value)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->TX_PHS.bits.PHSX = Value;
}

/**
 * @brief: 设置ECCP模块通道Tz相位值
 * @param Module: 指向Eccp内存结构的指针
 * @param Value: 相位值,取值范围为0-65535
 * @retval void
 */
KF_INLINE void Eccp_LL_SetTzPhaseShiftValue(Eccp_RegisterMap_t *const Module, uint16_t Value)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->TZ_PHS.bits.PHSZ = Value;
}

/**
 * @brief:  设置立即更新事件重载计数器使能位
 * @param Module: 指向Eccp内存结构的指针
 * @param State:
 *          true   更新事件发生时,将相位值加载到计数器中
 *          false   更新事件发生时,将计数器复位
 * @retval void
 */
KF_INLINE void Eccp_LL_SetReloadPhaseShiftValEnabled(Eccp_RegisterMap_t *const Module, bool State)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->CTL4.bits.UDREN = State ? 1U : 0U;
}

/**
 * @brief:  设置TRGI触发更新使能位0
 * @param Module: 指向Eccp内存结构的指针
 * @param State:
 *          true   TRGI触发更新使能
 *          false   TRGI触发更新禁止
 * @retval void
 */
KF_INLINE void Eccp_LL_SetTrigUpdateEnabled0(Eccp_RegisterMap_t *const Module, bool State)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->CTL4.bits.TRGUDEN0 = State ? 1U : 0U;
}

/**
 * @brief:  设置TRGI触发更新使能位1
 * @param Module: 指向Eccp内存结构的指针
 * @param State:
 *          true   TRGI触发更新使能
 *          false   TRGI触发更新禁止
 * @retval void
 */
KF_INLINE void Eccp_LL_SetTrigUpdateEnabled1(Eccp_RegisterMap_t *const Module, bool State)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->CTL4.bits.TRGUDEN1 = State ? 1U : 0U;
}

/**
 * @brief:  设置TRGI触发更新模式选择位0
 * @param Module: 指向Eccp内存结构的指针
 * @param State:
 *          true   TRGI 发生后,再等到周期匹配时才更新输出控制寄存器
 *          false   TRGI 发生时立即更新输出控制寄存器
 * @retval void
 */
KF_INLINE void Eccp_LL_SetTrigUpdateMode0(Eccp_RegisterMap_t *const Module, bool State)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->CTL4.bits.TUDMODE0 = State ? 1U : 0U;
}

/**
 * @brief:  设置TRGI触发更新模式选择位1
 * @param Module: 指向Eccp内存结构的指针
 * @param State:
 *          true   TRGI 发生后,再等到周期匹配时才更新输出控制寄存器
 *          false   TRGI 发生时立即更新输出控制寄存器
 * @retval void
 */
KF_INLINE void Eccp_LL_SetTrigUpdateMode1(Eccp_RegisterMap_t *const Module, bool State)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->CTL4.bits.TUDMODE1 = State ? 1U : 0U;
}

/**
 * @brief 设置通道的双边沿捕捉功能使能
 *
 * @param Module 指向Eccp内存结构的指针
 * @param Channel Eccp通道, 可见 Eccp_Channel_t
 * @param State 使能状态
 *          true   使能双边沿捕捉
 *          false  禁止使能双边沿捕捉
 * @retval void
 */
KF_INLINE void Eccp_LL_SetCaptureDoubleEdgeEnabled(Eccp_RegisterMap_t *const Module, Eccp_Channel_t Channel, bool State)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));
    KF_ECCP_ASSERT(CHECK_ECCP_CHANNEL(Channel));

    uint32_t Mask;

    Mask = 5U + (uint32_t)Channel;
    REG_BITS_WRITE(Module->CTL4.reg, 0x1UL << Mask, (State ? 1UL : 0UL) << Mask);
}

/**
 * @brief 设置通道的捕捉输入滤波使能
 *
 * @param Module 指向Eccp内存结构的指针
 * @param Channel Eccp通道, 可见 Eccp_Channel_t
 * @param State 使能状态
 *          true   使能捕捉输入滤波
 *          false   禁止使能捕捉输入滤波
 * @retval void
 */
KF_INLINE void Eccp_LL_SetCaptureFilterEnabled(Eccp_RegisterMap_t *const Module, Eccp_Channel_t Channel, bool State)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));
    KF_ECCP_ASSERT(CHECK_ECCP_CHANNEL(Channel));

    uint32_t Mask;

    Mask = 9U + (uint32_t)Channel;
    REG_BITS_WRITE(Module->CTL4.reg, 0x1UL << Mask, (State ? 1UL : 0UL) << Mask);
}

/**
 * @brief 选择Tx触发输入极性
 *
 * @param Module 指向Eccp内存结构的指针
 * @param State 使能状态
 *          true   TRGI 低电平/下降沿有效
 *          false  TRGI 高电平/上升沿有效
 * @retval void
 */
KF_INLINE void Eccp_LL_SelectTxTriggerInputPolarity(Eccp_RegisterMap_t *const Module, bool State)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->CTL4.bits.TRGPOLX = State ? 1U : 0U;
}

/**
 * @brief 选择Tz触发输入极性
 *
 * @param Module 指向Eccp内存结构的指针
 * @param State 使能状态
 *          true   TRGI 低电平/下降沿有效
 *          false  TRGI 高电平/上升沿有效
 * @retval void
 */
KF_INLINE void Eccp_LL_SelectTzTriggerInputPolarity(Eccp_RegisterMap_t *const Module, bool State)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->CTL4.bits.TRGPOLZ = State ? 1U : 0U;
}

/**
 * @brief: 设置通道1死区延时
 * @param Module: 指向Eccp内存结构的指针
 * @param Value: 延时值(0-255)
 * @retval void
 */
KF_INLINE void Eccp_LL_SetCh1DeadZoneDelayTime(Eccp_RegisterMap_t *const Module, uint8_t Value)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->PXDTCTL2.bits.CH1PXDC = Value;
}

/**
 * @brief: 设置通道2死区延时
 * @param Module: 指向Eccp内存结构的指针
 * @param Value: 延时值(0-255)
 * @retval void
 */
KF_INLINE void Eccp_LL_SetCh2DeadZoneDelayTime(Eccp_RegisterMap_t *const Module, uint8_t Value)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->PXDTCTL2.bits.CH2PXDC = Value;
}

/**
 * @brief: 设置通道的死区计数时钟分频
 * @param Module: 指向Eccp内存结构的指针
 * @param Value: 分频设置值, 取值范围为0-15
 * @retval void
 */
KF_INLINE void Eccp_LL_SetDeadZoneClkScaler(Eccp_RegisterMap_t *const Module, Eccp_Channel_t Channel, uint32_t Scaler)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));
    KF_ECCP_ASSERT(CHECK_ECCP_CHANNEL(Channel));
    KF_ECCP_ASSERT(CHECK_ECCP_INPUT_0XF(Scaler));

    uint32_t Mask;

    Mask = (uint32_t)Channel << 2U;
    REG_BITS_WRITE(Module->PXDTCFG.reg, 0xFUL << Mask, (uint32_t)Scaler << Mask);
}

/**
 * @brief Tx_CCR0 触发AD计数方向选择使能
 *
 * @param Module 指向Eccp内存结构的指针
 * @param EnableSta 使能状态
 * @retval void
 */
KF_INLINE void Eccp_LL_SetTxCcr0TrigAdEnabled(Eccp_RegisterMap_t *const Module, bool EnableSta)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->CCRCTL.bits.TXCCR0SEN = EnableSta ? 1U : 0U;
}

/**
 * @brief Tx_CCR1 触发AD计数方向选择使能
 *
 * @param Module 指向Eccp内存结构的指针
 * @param EnableSta 使能状态
 * @retval void
 */
KF_INLINE void Eccp_LL_SetTxCcr1TrigAdEnabled(Eccp_RegisterMap_t *const Module, bool EnableSta)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->CCRCTL.bits.TXCCR1SEN = EnableSta ? 1U : 0U;
}

/**
 * @brief Tz_CCR0 触发AD计数方向选择使能
 *
 * @param Module 指向Eccp内存结构的指针
 * @param EnableSta 使能状态
 * @retval void
 */
KF_INLINE void Eccp_LL_SetTzCcr0TrigAdEnabled(Eccp_RegisterMap_t *const Module, bool EnableSta)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->CCRCTL.bits.TZCCR0SEN = EnableSta ? 1U : 0U;
}

/**
 * @brief Tx_CCR0 触发 AD 计数方向选择
 *          true  向下计数且计数值等于 Tx_CCR0 寄存器值时，触发 AD
 *          false  向上计数且计数值等于 Tx_CCR0 寄存器值时，触发 AD
 * @param Module 指向Eccp内存结构的指针
 * @param Dir 计数方向
 *
 * @retval void
 */
KF_INLINE void Eccp_LL_SelectTxCcr0TrigAdCountDirection(Eccp_RegisterMap_t *const Module, bool Dir)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->CCRCTL.bits.TXCCR0SEL = Dir ? 1U : 0U;
}

/**
 * @brief Tx_CCR1 触发 AD 计数方向选择
 *          true  向下计数且计数值等于 Tx_CCR1 寄存器值时，触发 AD
 *          false  向上计数且计数值等于 Tx_CCR1 寄存器值时，触发 AD
 * @param Module 指向Eccp内存结构的指针
 * @param Dir 计数方向
 *
 * @retval void
 */
KF_INLINE void Eccp_LL_SelectTxCcr1TrigAdCountDirection(Eccp_RegisterMap_t *const Module, bool Dir)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->CCRCTL.bits.TXCCR1SEL = Dir ? 1U : 0U;
}

/**
 * @brief Tz_CCR0 触发 AD 计数方向选择
 *          true  向下计数且计数值等于 Tz_CCR0 寄存器值时，触发 AD
 *          false  向上计数且计数值等于 Tz_CCR0 寄存器值时，触发 AD
 * @param Module 指向Eccp内存结构的指针
 * @param Dir 计数方向
 *
 * @retval void
 */
KF_INLINE void Eccp_LL_SelectTzCcr0TrigAdCountDirection(Eccp_RegisterMap_t *const Module, bool Dir)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));

    Module->CCRCTL.bits.TZCCR0SEL = Dir ? 1U : 0U;
}

/**
 * @brief 获取ECCP中断使能状态
 *
 * @param Module 指向Eccp内存结构的指针
 * @param IntIndex 设置中断序号, 可见 Eccp_IntrSetIndex_t
 * @retval void
 */
KF_INLINE bool Eccp_LL_GetIntrEnabledState(const Eccp_RegisterMap_t *const Module, Eccp_IntrSetIndex_t IntIndex)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));
    KF_ECCP_ASSERT(CHECK_ECCP_INTRSETINDEX(IntIndex));

    /* PRQA S 3469 1 #KQR003469 */
    return (REG_BITS_READ(Module->IE.reg, 0x1UL << (uint32_t)IntIndex, (uint32_t)IntIndex)) != 0U;
}

/**
 * @brief 获取ECCP中断发生状态
 *
 * @param Module 指向Eccp内存结构的指针
 * @param IntIndex 获取中断序号, 可见 Eccp_IntrGetIndex_t
 * @retval bool 中断发生状态
 *         true    发生了中断，且已使能
 *         false    未发生中断，或未使能
 */
KF_INLINE bool Eccp_LL_GetIntrState(const Eccp_RegisterMap_t *const Module, Eccp_IntrGetIndex_t IntIndex)
{
    KF_ECCP_ASSERT(CHECK_ECCP_ALL_PERIPH_ADDR(Module));
    KF_ECCP_ASSERT(CHECK_ECCP_INTRGETINDEX(IntIndex));

    /* PRQA S 3469 1 #KQR003469 */
    bool     flag  = (REG_BITS_READ(Module->EGIF.reg, 0x1UL << (uint32_t)IntIndex, (uint32_t)IntIndex) != 0U);
    bool     state = false;
    uint32_t setIndex;
    if (IntIndex == ECCP_INTR_GET_CPIF)
    {
        setIndex = (uint32_t)ECCP_INTR_SET_CPIE;
    }
    else if (IntIndex <= ECCP_INTR_GET_TXUIF)
    {
        setIndex = ((uint32_t)IntIndex - (uint32_t)ECCP_INTR_GET_CC1IF);
    }
    else
    {
        setIndex = (uint32_t)ECCP_INTR_SET_PDIE;
    }
    state = Eccp_LL_GetIntrEnabledState(Module, (Eccp_IntrSetIndex_t)setIndex);
    return flag && state;
}

#ifdef __cplusplus
}
#endif /*End of __cplusplus*/
#endif /*End of KF32A158SF_DRV_ECCP_H*/
/* EOF */
