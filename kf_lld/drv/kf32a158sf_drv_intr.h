/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name        : kf32a158sf_drv_intr.h
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
#ifndef KF32A158SF_DRV_INTR_H
#define KF32A158SF_DRV_INTR_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 *                      QAC Warnings
 ******************************************************************************/
/* PRQA S 0306 EOF #KQR000306 */
/* PRQA S 3006 EOF #KQR003006 */
/* PRQA S 3469 EOF #KQR003469 */
/* PRQA S 3473 EOF #KQR003473 */
/* PRQA S 4342 EOF #KQR004342 */
/******************************************************************************
 *                      Include Files
 ******************************************************************************/
#include <stdint.h>
#include <stdbool.h>
#include "kf_types.h"
#include "kf32a158sf_reg_intr.h"

#ifdef KF_DRV_INTR_ASSERT
#include "dev_assert.h"
#define KF_INTR_ASSERT(x) KF_DEV_ASSERT(x)
#else
#define KF_INTR_ASSERT(x) ((void)0U)
#endif
/******************************************************************************
 *                      Macro or Inline
 ******************************************************************************/

/******************************************************************************
 *                      Type definitions
 ******************************************************************************/
typedef enum
{
    NotAvail_IRQn        = 0U,  /* Initial stack pointer */
    Reset_IRQn           = 1U,  /* Reset */
    NMI_IRQn             = 2U,  /* NMI interrupt */
    HardFault_IRQn       = 3U,  /* hard fault exception */
    Reserved4_IRQn       = 4U,  /* Reserved interrupt 4 */
    StackFault_IRQn      = 5U,  /* stack Fault exception */
    AriFault_IRQn        = 6U,  /* arithmetic fault exception */
    Reserved7_IRQn       = 7U,  /* Reserved interrupt 7 */
    Reserved8_IRQn       = 8U,  /* Reserved interrupt 8 */
    Reserved9_IRQn       = 9U,  /* Reserved interrupt 9 */
    Reserved10_IRQn      = 10U, /* Reserved interrupt 10 */
    SVCCall_IRQn         = 11U, /* SVCall interrupt */
    Reserved12_IRQn      = 12U, /* Reserved interrupt 11 */
    Reserved13_IRQn      = 13U, /* Reserved interrupt 12 */
    SoftSV_IRQn          = 14U, /* SoftSV interrupt */
    SysTick_IRQn         = 15U, /* SysTick interrupt */
    WWDT_IRQn            = 16U, /* WWDT interrupt */
    EINT16_IRQn          = 17U, /* EINT16 interrupt */
    PA_IRQn              = 18U, /* PA interrupt */
    PB_IRQn              = 19U, /* PB interrupt */
    PC_IRQn              = 20U, /* PC interrupt */
    PD_IRQn              = 21U, /* PD interrupt */
    PE_IRQn              = 22U, /* PE interrupt */
    PF_IRQn              = 23U, /* PF interrupt */
    PX_IRQn              = 24U, /* PX interrupt */
    T1_IRQn              = 25U, /* T1 interrupt */
    T3_IRQn              = 26U, /* T3 interrupt */
    T5_IRQn              = 27U, /* T5 interrupt */
    T6_IRQn              = 28U, /* T6 interrupt */
    CANFD6_MB15TO0_IRQn  = 29U,
    CANFD6_MB31TO16_IRQn = 30U,
    CANFD6_MB47TO32_IRQn = 31U,
    CANFD6_MB63TO48_IRQn = 32U,
    T14_IRQn             = 33U,
    RNG_IRQn             = 34U,
    CANFD7_MB15TO0_IRQn  = 35U,
    CANFD7_MB31TO16_IRQn = 36U,
    ADC0_IRQn            = 37U,
    ADC1_IRQn            = 38U,
    CANFD6_BUS_IRQn      = 39U,
    T11_IRQn             = 40U,
    T0_IRQn              = 41U,
    DMA0_IRQn            = 42U,
    CMP_IRQn             = 43U,
    USART0_IRQn          = 44U,
    USART1_IRQn          = 45U,
    SPI0_IRQn            = 46U,
    SPI1_IRQn            = 47U,
    DMA1_IRQn            = 48U,
    EINT19TO17_IRQn      = 49U,
    CANFD6_IRQn          = 50U,
    CANFD7_IRQn          = 51U,
    CANFD7_MB47TO32_IRQn = 52U,
    CANFD7_MB63TO48_IRQn = 53U,
    EINT31TO20_IRQn      = 54U,
    CMU_IRQn             = 55U,
    OSC_IRQn             = 56U,
    CLK_IRQn             = OSC_IRQn,
    I2C0_IRQn            = 57U,
    I2C1_IRQn            = 58U,
    I2C2_IRQn            = 59U,
    T12_IRQn             = 60U,
    T2_IRQn              = 61U,
    T4_IRQn              = 62U,
    T13_IRQn             = 63U,
    USART2_IRQn          = 64U,
    T16_IRQn             = 65U,
    USART6_IRQn          = 66U,
    SPI2_IRQn            = 67U,
    CANFD7_BUS_IRQn      = 72U,
    WKP_IRQn             = 73U,
    CANFD8_BUS_IRQn      = 74U,
    T20_IRQn             = 75U,
    USART3_IRQn          = 80U,
    SHA_IRQn             = 82U,
    RSA_IRQn             = 83U,
    FIRSTK_PROG_IRQn     = 84U,
    FIRSTK_SERA_IRQn     = 85U,
    CANFD8_MB15TO0_IRQn  = 86U,
    CANFD8_MB31TO16_IRQn = 87U,
    CANFD8_MB47TO32_IRQn = 88U,
    CANFD8_MB63TO48_IRQn = 89U,
    CANFD8_IRQn          = 90U,
    CANFD9_IRQn          = 91U,
    T31_IRQn             = 96U,
    T32_IRQn             = 97U,
    T33_IRQn             = 98U,
    T36_IRQn             = 99U,
    T9_IRQn              = 100U,
    T10_IRQn             = 101U,
    CANFD9_BUS_IRQn      = 102U,
    STOPWATCHTICK_IRQn   = 103U,
    T21_IRQn             = 104U,
    FLASH_A_BUSY_IRQn    = 105U,
    FLASH_B_BUSY_IRQn    = 106U,
    SRAM_ECC_IRQn        = 107U,
    DRAM_ECC_IRQn        = 108U,
    CACHE_ECC_IRQn       = 109U,
    FLASH_ERR_IRQn       = 110U,
    ISMU_IRQn            = 111U,
    CANFD9_MB15TO0_IRQn  = 112U,
    CANFD9_MB31TO16_IRQn = 113U,
    CANFD9_MB47TO32_IRQn = 114U,
    CANFD9_MB63TO48_IRQn = 115U,
    AES_IRQn             = 117U,
    BUSERR_IRQn          = 118U,

    IRQ_MAX_NUM
} Intr_IRQn_t;

/*外部中断序号*/
typedef enum
{
    INTR_EXTI_INDEX_16 = 16U,
    INTR_EXTI_INDEX_17,
    INTR_EXTI_INDEX_18,
    INTR_EXTI_INDEX_19,
    INTR_EXTI_INDEX_20,
    INTR_EXTI_INDEX_21,
    INTR_EXTI_INDEX_22,
    INTR_EXTI_INDEX_23,
    INTR_EXTI_INDEX_24,
    INTR_EXTI_INDEX_25,
    INTR_EXTI_INDEX_26,
    INTR_EXTI_INDEX_27,
    INTR_EXTI_INDEX_28,
    INTR_EXTI_INDEX_29,
    INTR_EXTI_INDEX_30,
    INTR_EXTI_INDEX_31,
} Intr_ExtiIndex_t;
#define CHECK_INTR_EXTI_INDEX(x) (((x) >= INTR_EXTI_INDEX_16) && ((x) <= INTR_EXTI_INDEX_31))
/******************************************************************************
 *                      Export Variables
 ******************************************************************************/

/******************************************************************************
 *                      Export Functions
 ******************************************************************************/

/**
 * @brief 进入临界区并返回当前当前中断状态
 *
 * @param 无
 * @retval uint32_t 中断状态
 */
KF_INLINE uint32_t Intr_LL_EnterCritical(void)
{
    uint32_t r = INTR_RM.CTL0.bits.AIE;
    DISABLE_INTERRUPT();
    return r;
}

/**
 * @brief 根据中断状态是否使能中断
 *
 * @param v 中断状态值
 * @retval none
 */
KF_INLINE void Intr_LL_ExitCritical(uint32_t v)
{
    if (v > 0U)
    {
        ENABLE_INTERRUPT();
    }
    else
    {
        NOP();
    }
}

/**
 * @brief 获取当前正在处理的IRQ编号
 *
 * @param 无
 * @retval Intr_IRQn_t 中断向量编号值
 */
KF_INLINE Intr_IRQn_t Intr_LL_GetCurrentProcessingIRQ(void)
{
    return (Intr_IRQn_t)INTR_PTR->CTL0.bits.INTACT;
}

/**
 * @brief 设置中断优先级组
 *
 * @param prioGroup 优先级分组 0~3
 *           0 : 抢占优先级为3位 子优先级为1位
 *           1 : 抢占优先级为2位 子优先级为2位
 *           2 : 抢占优先级为1位 子优先级为3位
 *           3 : 抢占优先级为0位 子优先级为4位
 * @retval none
 */
KF_INLINE void Intr_LL_SetPriorityGroup(uint32_t prioGroup)
{
    KF_INTR_ASSERT(prioGroup < 4U);
    INTR_PTR->CTL0.bits.PRIGROUP = prioGroup;
}

/**
 * @brief 设置中断优先级
 *
 * @param irqNum IRQ编号
 * @param prio 优先级 0~15
 * @retval none
 */
KF_INLINE void Intr_LL_SetPriority(Intr_IRQn_t irqNum, uint8_t prio)
{
    KF_INTR_ASSERT(prio < 16U);
    KF_INTR_ASSERT(irqNum > 4U);
    KF_INTR_ASSERT(irqNum < IRQ_MAX_NUM);

    volatile uint8_t *kptr = NULL;

    if ((uint32_t)irqNum < 80U)
    {
        kptr = (uint8_t *)((uint32_t)&(INTR_PTR->IP0.reg) + ((uint32_t)irqNum - 4U));
    }
    else if ((uint32_t)irqNum < 112U)
    {
        kptr = (uint8_t *)((uint32_t)&(INTR_PTR->IP19.reg) + ((uint32_t)irqNum - 80U));
    }
    else
    {
        kptr = (uint8_t *)((uint32_t)&(INTR_PTR->IP27.reg) + ((uint32_t)irqNum - 112U));
    }

    *kptr = 0U;
    *kptr = (uint8_t)(prio << 4U);
}

/**
 * @brief 获取优先级分组
 *
 * @param 无
 * @retval uint32_t 优先级分组设置值
 */
KF_INLINE uint32_t Intr_LL_GetPriorityGroup(void)
{
    return (uint32_t)INTR_PTR->CTL0.bits.PRIGROUP;
}

/**
 * @brief 开总中断
 *
 * @param none
 * @retval none
 */
KF_INLINE void Intr_LL_EnableAIE(void)
{
    ENABLE_INTERRUPT();
}

/**
 * @brief 关总中断
 *
 * @param none
 * @retval none
 */
KF_INLINE void Intr_LL_DisableAIE(void)
{
    DISABLE_INTERRUPT();
}

/**
 * @brief 获取总中断
 *
 * @param none
 * @retval bool
 */
KF_INLINE bool Intr_LL_GetAIEState(void)
{
    return (INTR_PTR->CTL0.bits.AIE != 0U);
}

/**
 * @brief 外设或内核中断使能控制,对于用户未定义的保留区中断向量,可能出现未知结果.
 *
 * @param Peripheral 外设或内核中断向量编号 取值范围 Intr_IRQn_t
 * @param State
 * @retval void
 */
KF_INLINE void Intr_LL_SetInterruptEnabled(Intr_IRQn_t Peripheral, bool State)
{

    uint32_t kvOffset = 0U;

    if (Peripheral <= SysTick_IRQn)
    {
        kvOffset = (uint32_t)Peripheral;
        REG_BITS_WRITE(INTR_PTR->EIE0.reg, (1UL << kvOffset), ((State ? 1UL : 0UL) << kvOffset));
    }
    else if (Peripheral <= SPI1_IRQn)
    {
        kvOffset = (uint32_t)Peripheral - (uint32_t)WWDT_IRQn;
        REG_BITS_WRITE(INTR_PTR->EIE1.reg, (1UL << kvOffset), ((State ? 1UL : 0UL) << kvOffset));
    }
    else if (Peripheral <= T20_IRQn)
    {
        kvOffset = (uint32_t)Peripheral - (uint32_t)DMA1_IRQn;
        REG_BITS_WRITE(INTR_PTR->EIE2.reg, (1UL << kvOffset), ((State ? 1UL : 0UL) << kvOffset));
    }
    else if (Peripheral <= ISMU_IRQn)
    {
        kvOffset = (uint32_t)Peripheral - (uint32_t)USART3_IRQn;
        REG_BITS_WRITE(INTR_PTR->EIE3.reg, (1UL << kvOffset), ((State ? 1UL : 0UL) << kvOffset));
    }
    else if (Peripheral <= BUSERR_IRQn)
    {
        kvOffset = (uint32_t)Peripheral - (uint32_t)CANFD9_MB15TO0_IRQn;
        REG_BITS_WRITE(INTR_PTR->EIE4.reg, (1UL << kvOffset), ((State ? 1UL : 0UL) << kvOffset));
    }
    else
    {
        /* Empty */
    }
}

/**
 * @brief 获取中断标志位
 *
 * @param Peripheral 中断编号
 * @retval bool
 *                  true -- 中断挂起 \n
 *                  false -- 无中断挂起
 */
KF_INLINE bool Intr_LL_GetInterruptFlag(Intr_IRQn_t Peripheral)
{
    uint32_t kvOffset = 0U;
    bool     kvRet;

    if (Peripheral <= SysTick_IRQn)
    {
        kvOffset = (uint32_t)Peripheral;
        kvRet    = REG_BITS_READ(INTR_PTR->EIF0.reg, (1UL << kvOffset), kvOffset) != 0U;
    }
    else if (Peripheral <= SPI1_IRQn)
    {
        kvOffset = (uint32_t)Peripheral - (uint32_t)WWDT_IRQn;
        kvRet    = REG_BITS_READ(INTR_PTR->EIF1.reg, (1UL << kvOffset), kvOffset) != 0U;
    }
    else if (Peripheral <= T20_IRQn)
    {
        kvOffset = (uint32_t)Peripheral - (uint32_t)DMA1_IRQn;
        kvRet    = REG_BITS_READ(INTR_PTR->EIF2.reg, (1UL << kvOffset), kvOffset) != 0U;
    }
    else if (Peripheral <= ISMU_IRQn)
    {
        kvOffset = (uint32_t)Peripheral - (uint32_t)USART3_IRQn;
        kvRet    = REG_BITS_READ(INTR_PTR->EIF3.reg, (1UL << kvOffset), kvOffset) != 0U;
    }
    else if (Peripheral <= BUSERR_IRQn)
    {
        kvOffset = (uint32_t)Peripheral - (uint32_t)CANFD9_MB15TO0_IRQn;
        kvRet    = REG_BITS_READ(INTR_PTR->EIF4.reg, (1UL << kvOffset), kvOffset) != 0U;
    }
    else
    {
        kvRet = false;
    }

    return kvRet;
}

/**
 * @brief 清除中断标志位
 *
 * @param Peripheral 中断编号
 * @retval None
 */
KF_INLINE void Intr_LL_ClearInterruptFlag(Intr_IRQn_t Peripheral)
{
    uint32_t kvOffset = 0U;

    if (Peripheral <= SysTick_IRQn)
    {
        kvOffset = (uint32_t)Peripheral;
        REG_BITS_WRITE(INTR_PTR->EIF0.reg, (1UL << kvOffset), (0UL << kvOffset));
    }
    else if (Peripheral <= SPI1_IRQn)
    {
        kvOffset = (uint32_t)Peripheral - (uint32_t)WWDT_IRQn;
        REG_BITS_WRITE(INTR_PTR->EIF1.reg, (1UL << kvOffset), (0UL << kvOffset));
    }
    else if (Peripheral <= T20_IRQn)
    {
        kvOffset = (uint32_t)Peripheral - (uint32_t)DMA1_IRQn;
        REG_BITS_WRITE(INTR_PTR->EIF2.reg, (1UL << kvOffset), (0UL << kvOffset));
    }
    else if (Peripheral <= ISMU_IRQn)
    {
        kvOffset = (uint32_t)Peripheral - (uint32_t)USART3_IRQn;
        REG_BITS_WRITE(INTR_PTR->EIF3.reg, (1UL << kvOffset), (0UL << kvOffset));
    }
    else if (Peripheral <= BUSERR_IRQn)
    {
        kvOffset = (uint32_t)Peripheral - (uint32_t)CANFD9_MB15TO0_IRQn;
        REG_BITS_WRITE(INTR_PTR->EIF4.reg, (1UL << kvOffset), (0UL << kvOffset));
    }
    else
    {
        /* Empty */
    }
}

/**
 * @brief 设置外部中断线中断屏蔽位
 *
 * @param ExtiIndex 外部中断序号, 可见 Intr_ExtiIndex_t
 * @param Mask 屏蔽掩码
 *          true -- 使能对应外部中断线上的中断请求
 *          false -- 禁止对应外部中断线上的中断请求
 * @retval void
 */
KF_INLINE void Intr_LL_SetExtiMaskValue(Intr_ExtiIndex_t ExtiIndex, bool Mask)
{
    KF_INTR_ASSERT(CHECK_INTR_EXTI_INDEX(ExtiIndex));

    REG_BITS_WRITE(INTR_PTR->EINTMASK.reg, (1UL << (uint32_t)ExtiIndex), ((Mask ? 1UL : 0UL) << (uint32_t)ExtiIndex));
}

/**
 * @brief 设置外部中断线上升沿选择位
 *
 * @param ExtiIndex 外部中断序号, 可见 Intr_ExtiIndex_t
 * @param Enable 使能状态
 *          true -- 使能外部中断线上的上升沿中断
 *          false -- 禁止外部中断线上的上升沿中断
 * @retval void
 */
KF_INLINE void Intr_LL_SetExtiRiseEdgeEnabled(Intr_ExtiIndex_t ExtiIndex, bool Enable)
{
    KF_INTR_ASSERT(CHECK_INTR_EXTI_INDEX(ExtiIndex));

    REG_BITS_WRITE(INTR_PTR->EINTRISE.reg, (1UL << (uint32_t)ExtiIndex), ((Enable ? 1UL : 0UL) << (uint32_t)ExtiIndex));
}

/**
 * @brief 设置外部中断线下降沿选择位
 *
 * @param ExtiIndex 外部中断序号, 可见 Intr_ExtiIndex_t
 * @param Enable 使能状态
 *          true -- 使能外部中断线上的下降沿中断
 *          false -- 禁止外部中断线上的下降沿中断
 * @retval void
 */
KF_INLINE void Intr_LL_SetExtiFallEdgeEnabled(Intr_ExtiIndex_t ExtiIndex, bool Enable)
{
    KF_INTR_ASSERT(CHECK_INTR_EXTI_INDEX(ExtiIndex));

    REG_BITS_WRITE(INTR_PTR->EINTFALL.reg, (1UL << (uint32_t)ExtiIndex), ((Enable ? 1UL : 0UL) << (uint32_t)ExtiIndex));
}

/**
 * @brief 设置外部中断高电平触发
 *
 * @param ExtiIndex 外部中断序号, 可见 Intr_ExtiIndex_t
 * @param Enable 使能状态
 *          true -- 使能外部中断高电平触发模式
 *          false -- 禁止外部中断高电平触发模式
 * @retval void
 */
KF_INLINE void Intr_LL_SetExtiHiLevelEnabled(Intr_ExtiIndex_t ExtiIndex, bool Enable)
{
    KF_INTR_ASSERT(CHECK_INTR_EXTI_INDEX(ExtiIndex));

    REG_BITS_WRITE(INTR_PTR->EINTEL.reg, (1UL << (uint32_t)ExtiIndex), ((Enable ? 1UL : 0UL) << (uint32_t)ExtiIndex));
}

/**
 * @brief 获取外部中断线中断标志位
 *
 * @param ExtiIndex 外部中断序号, 可见 Intr_ExtiIndex_t
 * @retval bool  中断状态
 *          true -- 产生了中断
 *          false -- 未产生中断
 */
KF_INLINE bool Intr_LL_GetExtiFlag(Intr_ExtiIndex_t ExtiIndex)
{
    KF_INTR_ASSERT(CHECK_INTR_EXTI_INDEX(ExtiIndex));

    return (0U != (REG_BITS_READ(INTR_PTR->EINTF.reg, (1UL << (uint32_t)ExtiIndex), (uint32_t)ExtiIndex)));
}

/**
 * @brief 清除外部中断线中断标志位
 *
 * @param ExtiIndex 外部中断序号, 可见 Intr_ExtiIndex_t
 * @retval void
 */
KF_INLINE void Intr_LL_ClearExtiFlag(Intr_ExtiIndex_t ExtiIndex)
{
    KF_INTR_ASSERT(CHECK_INTR_EXTI_INDEX(ExtiIndex));

    REG_BIT_CLR(INTR_PTR->EINTF.reg, (1UL << (uint32_t)ExtiIndex));
}

/**
 * @brief 清除所有中断标志位
 *
 * @param void
 * @retval void
 */
KF_INLINE void Intr_LL_ClearAllInterruptFlag(void)
{
    INTR_PTR->EIF4.reg = 0U;
    INTR_PTR->EIF3.reg = 0U;
    INTR_PTR->EIF2.reg = 0U;
    INTR_PTR->EIF1.reg = 0U;
    INTR_PTR->EIF0.reg = 0U;
}

/**
 * @brief 获取中断发生状态
 *
 * @param Peripheral 中断编号
 * @retval bool 中断发生状态
 *         true    发生了中断，且已使能
 *         false    未发生中断，或未使能
 */
KF_INLINE bool Intr_LL_GetInterruptState(Intr_IRQn_t Peripheral)
{
    uint32_t kvOffset = 0U;
    bool     flag     = false;
    bool     state    = false;

    if (Peripheral <= SysTick_IRQn)
    {
        kvOffset = (uint32_t)Peripheral;
        flag     = (REG_BITS_READ(INTR_PTR->EIF0.reg, (uint32_t)(1UL << kvOffset), kvOffset) != 0U) ? true : false;
        state    = (REG_BITS_READ(INTR_PTR->EIE0.reg, (uint32_t)(1UL << kvOffset), kvOffset) != 0U) ? true : false;
    }
    else if (Peripheral <= SPI1_IRQn)
    {
        kvOffset = (uint32_t)Peripheral - (uint32_t)WWDT_IRQn;
        flag     = (REG_BITS_READ(INTR_PTR->EIF1.reg, (uint32_t)(1UL << kvOffset), kvOffset) != 0U) ? true : false;
        state    = (REG_BITS_READ(INTR_PTR->EIE1.reg, (uint32_t)(1UL << kvOffset), kvOffset) != 0U) ? true : false;
    }
    else if (Peripheral <= T20_IRQn)
    {
        kvOffset = (uint32_t)Peripheral - (uint32_t)DMA1_IRQn;
        flag     = (REG_BITS_READ(INTR_PTR->EIF2.reg, (uint32_t)(1UL << kvOffset), kvOffset) != 0U) ? true : false;
        state    = (REG_BITS_READ(INTR_PTR->EIE2.reg, (uint32_t)(1UL << kvOffset), kvOffset) != 0U) ? true : false;
    }
    else if (Peripheral <= ISMU_IRQn)
    {
        kvOffset = (uint32_t)Peripheral - (uint32_t)USART3_IRQn;
        flag     = (REG_BITS_READ(INTR_PTR->EIF3.reg, (uint32_t)(1UL << kvOffset), kvOffset) != 0U) ? true : false;
        state    = (REG_BITS_READ(INTR_PTR->EIE3.reg, (uint32_t)(1UL << kvOffset), kvOffset) != 0U) ? true : false;
    }
    else if (Peripheral <= BUSERR_IRQn)
    {
        kvOffset = (uint32_t)Peripheral - (uint32_t)CANFD9_MB15TO0_IRQn;
        flag     = (REG_BITS_READ(INTR_PTR->EIF4.reg, (uint32_t)(1UL << kvOffset), kvOffset) != 0U) ? true : false;
        state    = (REG_BITS_READ(INTR_PTR->EIE4.reg, (uint32_t)(1UL << kvOffset), kvOffset) != 0U) ? true : false;
    }
    else
    {
        /* Intentionally Empty */
    }

    return flag && state;
}

#ifdef __cplusplus
}
#endif /*End of __cplusplus*/
#endif /*End of KF32A158SF_DRV_INTR_H*/
/* EOF */
