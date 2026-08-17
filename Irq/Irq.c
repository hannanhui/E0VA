/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Irq.c
 *  @Syntax          : GNU99
 *  @Author          : ChipON AE/FAE Group
 *  @Date            : 2025-08-29
 *  @Version         : V1.0.0_SF
 *  @Description     : This document describes the C language document template.
 ******************************************************************************
 *  Copyright (C) by Shanghai ChipON Micro-Electronic Co.,Ltd
 *  All rights reserved.
 *
 *  This software is copyright protected and proprietary to
 *  Shanghai ChipON Micro-Electronic Co.,Ltd.
 ******************************************************************************
 *                        REVISION HISTORY
 ******************************************************************************
 *  |Date        |Version  |Author       |Description
 ******************************************************************************
 *  |2025-08-29  |V1.0     |Wang Ning    |New creat
 *****************************************************************************/

/******************************************************************************
**                        Include Files
******************************************************************************/
#include "Mcal.h"
#include "kf_types.h"
#include "kf32a158sf_drv_intr.h"
#include "Irq.h"

#ifdef IRQ_INTERNAL_ASSERT
#include "dev_assert.h"
#define IRQ_DEV_ASSERT(x) KF_DEV_ASSERT(x)
#else
#define IRQ_DEV_ASSERT(x) ((void)0)
#endif
/******************************************************************************
**                        Macro Definitions
******************************************************************************/

/******************************************************************************
**                        Constants
******************************************************************************/

/******************************************************************************
**                        Type definitions
******************************************************************************/

/******************************************************************************
**                        Variables
******************************************************************************/

/******************************************************************************
 *                     Local Function Declarations              	           *
 ******************************************************************************/
static void Intr_SetPriority(Intr_IRQn_t IrqNum, PriorityType Priority, uint32 PriorityGroup);
/******************************************************************************
 *                     Local Function definitions                		       *
 ******************************************************************************/
static void Intr_SetPriority(Intr_IRQn_t IrqNum, PriorityType Priority, uint32 PriorityGroup)
{
    IRQ_DEV_ASSERT(PriorityGroup < 4U);

    uint8 priority = 0xFU;
    uint8 preemptionPrio;
    uint8 subPrio;

    switch (PriorityGroup)
    {
    case 0U:
        preemptionPrio = Priority.Preemption_Priority & 0x7U;
        subPrio        = Priority.Sub_Priority & 0x1U;
        priority       = (uint8)((uint8)(preemptionPrio << 1U) | subPrio);
        break;
    case 1U:
        preemptionPrio = Priority.Preemption_Priority & 0x3U;
        subPrio        = Priority.Sub_Priority & 0x3U;
        priority       = (uint8)((uint8)(preemptionPrio << 2U) | subPrio);
        break;
    case 2U:
        preemptionPrio = Priority.Preemption_Priority & 0x1U;
        subPrio        = Priority.Sub_Priority & 0x7U;
        priority       = (uint8)((uint8)(preemptionPrio << 3U) | subPrio);
        break;
    case 3U:
        subPrio  = Priority.Sub_Priority & 0xFU;
        priority = subPrio;
        break;
    default:
        IRQ_DEV_ASSERT(false);
        break;
    }

    Intr_LL_SetPriority((Intr_IRQn_t)IrqNum, priority);
}
/******************************************************************************
**                        Function definitions
******************************************************************************/

/**
 * @brief Peripheral interrupt initialization, enable peripheral interrupt and level 1 interrupt according to
 * configuration
 * @details
 * Service name: Irq_Init
 * Syntax: void Irq_Init(Irq_ConfigType Config)
 * Service ID[hex]:
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * @implements
 * @param Config Interrupt configuration information
 * @retval None
 */
/* PRQA S 0303,0605,3006 ++ #KQR100018 */
FUNC(void, BSWM_CODE) Irq_Init(P2CONST(Irq_ConfigType, AUTOMATIC, INT_APPL_DATA) Config)
{
    /* PRQA S 2814 1 #KQR002814 */
    INTR_RM.CTL0.bits.PRIGROUP = Config->PriorityGroup;
#if (SYSTICK_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(SysTick_IRQn, Config->Systick_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(SysTick_IRQn);
    INTR_RM.EIE0.bits.SYSTICKIE = STD_ON;
#endif
#if (WWDT_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(WWDT_IRQn, Config->WWDT_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(WWDT_IRQn);
    INTR_RM.EIE1.bits.WWDTIE = STD_ON;
#endif
#if (EINT16_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(EINT16_IRQn, Config->Eint16_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(EINT16_IRQn);
    INTR_RM.EIE1.bits.EINT16IE = STD_ON;
#endif
#if (PA_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(PA_IRQn, Config->PA_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(PA_IRQn);
    INTR_RM.EIE1.bits.PAIE = STD_ON;
#endif
#if (PB_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(PB_IRQn, Config->PB_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(PB_IRQn);
    INTR_RM.EIE1.bits.PBIE = STD_ON;
#endif
#if (PC_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(PC_IRQn, Config->PC_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(PC_IRQn);
    INTR_RM.EIE1.bits.PCIE = STD_ON;
#endif
#if (PD_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(PD_IRQn, Config->PD_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(PD_IRQn);
    INTR_RM.EIE1.bits.PDIE = STD_ON;
#endif
#if (PE_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(PE_IRQn, Config->PE_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(PE_IRQn);
    INTR_RM.EIE1.bits.PEIE = STD_ON;
#endif
#if (PF_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(PF_IRQn, Config->PF_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(PF_IRQn);
    INTR_RM.EIE1.bits.PFIE = STD_ON;
#endif
#if (PX_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(PX_IRQn, Config->PX_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(PX_IRQn);
    INTR_RM.EIE1.bits.PXIE = STD_ON;
#endif
#if (T1_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(T1_IRQn, Config->Timer1_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(T1_IRQn);
    INTR_RM.EIE1.bits.T1IE = STD_ON;
#endif
#if (T3_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(T3_IRQn, Config->Timer3_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(T3_IRQn);
    INTR_RM.EIE1.bits.T3IE = STD_ON;
#endif
#if (T5_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(T5_IRQn, Config->Timer5_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(T5_IRQn);
    INTR_RM.EIE1.bits.T5IE = STD_ON;
#endif
#if (T6_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(T6_IRQn, Config->Timer6_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(T6_IRQn);
    INTR_RM.EIE1.bits.T6IE = STD_ON;
#endif
#if (CANFD6MB15TO0_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(CANFD6_MB15TO0_IRQn, Config->CanFd6MB15TO0_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(CANFD6_MB15TO0_IRQn);
    INTR_RM.EIE1.bits.CANFD6_MB_15_0_IE = STD_ON;
#endif
#if (CANFD6MB31TO16_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(CANFD6_MB31TO16_IRQn, Config->CanFd6MB31TO16_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(CANFD6_MB31TO16_IRQn);
    INTR_RM.EIE1.bits.CANFD6_MB_31_16_IE = STD_ON;
#endif
#if (CANFD6MB47TO32_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(CANFD6_MB47TO32_IRQn, Config->CanFd6MB47TO32_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(CANFD6_MB47TO32_IRQn);
    INTR_RM.EIE1.bits.CANFD6_MB_47_32_IE = STD_ON;
#endif
#if (CANFD6MB63TO48_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(CANFD6_MB63TO48_IRQn, Config->CanFd6MB63TO48_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(CANFD6_MB63TO48_IRQn);
    INTR_RM.EIE1.bits.CANFD6_MB_63_48_IE = STD_ON;
#endif
#if (T14_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(T14_IRQn, Config->Timer14_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(T14_IRQn);
    INTR_RM.EIE1.bits.T14IE = STD_ON;
#endif
#if (RNG_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(RNG_IRQn, Config->Rng_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(RNG_IRQn);
    INTR_RM.EIE1.bits.RNGIE = STD_ON;
#endif
#if (CANFD7MB15TO0_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(CANFD7_MB15TO0_IRQn, Config->CanFd7MB15TO0_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(CANFD7_MB15TO0_IRQn);
    INTR_RM.EIE1.bits.CANFD7_MB_15_0_IE = STD_ON;
#endif
#if (CANFD7MB31TO16_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(CANFD7_MB31TO16_IRQn, Config->CanFd7MB31TO16_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(CANFD7_MB31TO16_IRQn);
    INTR_RM.EIE1.bits.CANFD7_MB_31_16_IE = STD_ON;
#endif
#if (ADC0_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(ADC0_IRQn, Config->Adc0_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(ADC0_IRQn);
    INTR_RM.EIE1.bits.ADC0IE = STD_ON;
#endif
#if (ADC1_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(ADC1_IRQn, Config->Adc1_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(ADC1_IRQn);
    INTR_RM.EIE1.bits.ADC1IE = STD_ON;
#endif
#if (CANFD6_BUSERR_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(CANFD6_BUS_IRQn, Config->CanFd6BusErr_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(CANFD6_BUS_IRQn);
    INTR_RM.EIE1.bits.CANFD6_BUS_IE = STD_ON;
#endif
#if (T11_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(T11_IRQn, Config->Timer11_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(T11_IRQn);
    INTR_RM.EIE1.bits.T11IE = STD_ON;
#endif
#if (T0_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(T0_IRQn, Config->Timer0_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(T0_IRQn);
    INTR_RM.EIE1.bits.T0IE = STD_ON;
#endif
#if (DMA0_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(DMA0_IRQn, Config->Dma0_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(DMA0_IRQn);
    INTR_RM.EIE1.bits.DMA0IE = STD_ON;
#endif
#if (CMP_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(CMP_IRQn, Config->Cmp_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(CMP_IRQn);
    INTR_RM.EIE1.bits.CMPIE = STD_ON;
#endif
#if (USART0_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(USART0_IRQn, Config->Usart0_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(USART0_IRQn);
    INTR_RM.EIE1.bits.USART0IE = STD_ON;
#endif
#if (USART1_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(USART1_IRQn, Config->Usart1_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(USART1_IRQn);
    INTR_RM.EIE1.bits.USART1IE = STD_ON;
#endif
#if (SPI0_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(SPI0_IRQn, Config->Spi0_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(SPI0_IRQn);
    INTR_RM.EIE1.bits.SPI0IE = STD_ON;
#endif
#if (SPI1_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(SPI1_IRQn, Config->Spi1_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(SPI1_IRQn);
    INTR_RM.EIE1.bits.SPI1IE = STD_ON;
#endif
#if (DMA1_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(DMA1_IRQn, Config->Dma1_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(DMA1_IRQn);
    INTR_RM.EIE2.bits.DMA1IE = STD_ON;
#endif
#if (EINT19_17_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(EINT19TO17_IRQn, Config->Eint19_17_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(EINT19TO17_IRQn);
    INTR_RM.EIE2.bits.EINT19TO17IE = STD_ON;
#endif
#if (CANFD6_CANFDGEN_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(CANFD6_IRQn, Config->CanFd6Gen_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(CANFD6_IRQn);
    INTR_RM.EIE2.bits.CANFD6_GEN_IE = STD_ON;
#endif
#if (CANFD7_CANFDGEN_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(CANFD7_IRQn, Config->CanFd7Gen_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(CANFD7_IRQn);
    INTR_RM.EIE2.bits.CANFD7_GEN_IE = STD_ON;
#endif
#if (CANFD7MB47TO32_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(CANFD7_MB47TO32_IRQn, Config->CanFd7MB47TO32_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(CANFD7_MB47TO32_IRQn);
    INTR_RM.EIE2.bits.CANFD7_MB_47_32_IE = STD_ON;
#endif
#if (CANFD7MB63TO48_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(CANFD7_MB63TO48_IRQn, Config->CanFd7MB63TO48_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(CANFD7_MB63TO48_IRQn);
    INTR_RM.EIE2.bits.CANFD7_MB_63_48_IE = STD_ON;
#endif
#if (EINT31_20_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(EINT31TO20_IRQn, Config->Eint31_20_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(EINT31TO20_IRQn);
    INTR_RM.EIE2.bits.EINT31TO20IE = STD_ON;
#endif
#if (CMU_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(CMU_IRQn, Config->Cmu_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(CMU_IRQn);
    INTR_RM.EIE2.bits.CMUIE = STD_ON;
#endif
#if (OSC_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(OSC_IRQn, Config->Osc_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(OSC_IRQn);
    INTR_RM.EIE2.bits.OSCIE = STD_ON;
#endif
#if (CLK_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(CLK_IRQn, Config->Clk_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(CLK_IRQn);
    INTR_RM.EIE2.bits.OSCIE = STD_ON;
#endif
#if (IIC0_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(I2C0_IRQn, Config->IIC0_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(I2C0_IRQn);
    INTR_RM.EIE2.bits.I2C0IE = STD_ON;
#endif
#if (IIC1_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(I2C1_IRQn, Config->IIC1_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(I2C1_IRQn);
    INTR_RM.EIE2.bits.I2C1IE = STD_ON;
#endif
#if (IIC2_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(I2C2_IRQn, Config->IIC2_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(I2C2_IRQn);
    INTR_RM.EIE2.bits.I2C2IE = STD_ON;
#endif
#if (T12_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(T12_IRQn, Config->Timer12_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(T12_IRQn);
    INTR_RM.EIE2.bits.T12IE = STD_ON;
#endif
#if (T2_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(T2_IRQn, Config->Timer2_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(T2_IRQn);
    INTR_RM.EIE2.bits.T2IE = STD_ON;
#endif
#if (T4_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(T4_IRQn, Config->Timer4_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(T4_IRQn);
    INTR_RM.EIE2.bits.T4IE = STD_ON;
#endif
#if (T13_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(T13_IRQn, Config->Timer13_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(T13_IRQn);
    INTR_RM.EIE2.bits.T13IE = STD_ON;
#endif
#if (USART2_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(USART2_IRQn, Config->Usart2_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(USART2_IRQn);
    INTR_RM.EIE2.bits.USART2IE = STD_ON;
#endif
#if (T16_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(T16_IRQn, Config->Timer16_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(T16_IRQn);
    INTR_RM.EIE2.bits.T16IE = STD_ON;
#endif
#if (USART6_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(USART6_IRQn, Config->Usart6_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(USART6_IRQn);
    INTR_RM.EIE2.bits.USART6IE = STD_ON;
#endif
#if (SPI2_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(SPI2_IRQn, Config->Spi2_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(SPI2_IRQn);
    INTR_RM.EIE2.bits.SPI2IE = STD_ON;
#endif
#if (CANFD7_BUSERR_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(CANFD7_BUS_IRQn, Config->CanFd7BusErr_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(CANFD7_BUS_IRQn);
    INTR_RM.EIE2.bits.CANFD7_BUS_IE = STD_ON;
#endif
#if (WKP_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(WKP_IRQn, Config->Wkp_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(WKP_IRQn);
    INTR_RM.EIE2.bits.WKPIE = STD_ON;
#endif
#if (CANFD8_BUSERR_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(CANFD8_BUS_IRQn, Config->CanFd8BusErr_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(CANFD8_BUS_IRQn);
    INTR_RM.EIE2.bits.CANFD8_BUS_IE = STD_ON;
#endif
#if (T20_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(T20_IRQn, Config->Timer20_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(T20_IRQn);
    INTR_RM.EIE2.bits.T20IE = STD_ON;
#endif
#if (USART3_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(USART3_IRQn, Config->Usart3_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(USART3_IRQn);
    INTR_RM.EIE3.bits.USART3IE = STD_ON;
#endif
#if (SHA_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(SHA_IRQn, Config->Sha_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(SHA_IRQn);
    INTR_RM.EIE3.bits.SHA_IE = STD_ON;
#endif
#if (RSA_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(RSA_IRQn, Config->Rsa_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(RSA_IRQn);
    INTR_RM.EIE3.bits.RSA_IE = STD_ON;
#endif
#if (FIRSTK_PROG_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(FIRSTK_PROG_IRQn, Config->Firstk_Prog_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(FIRSTK_PROG_IRQn);
    INTR_RM.EIE3.bits.FIRSTK_PROG_IE = STD_ON;
#endif
#if (FIRSTK_SERA_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(FIRSTK_SERA_IRQn, Config->Firstk_Sera_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(FIRSTK_SERA_IRQn);
    INTR_RM.EIE3.bits.FIRSTK_SERA_IE = STD_ON;
#endif
#if (CANFD8MB15TO0_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(CANFD8_MB15TO0_IRQn, Config->CanFd8MB15TO0_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(CANFD8_MB15TO0_IRQn);
    INTR_RM.EIE3.bits.CANFD8_MB_15_0_IE = STD_ON;
#endif
#if (CANFD8MB31TO16_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(CANFD8_MB31TO16_IRQn, Config->CanFd8MB31TO16_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(CANFD8_MB31TO16_IRQn);
    INTR_RM.EIE3.bits.CANFD8_MB_31_16_IE = STD_ON;
#endif
#if (CANFD8MB47TO32_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(CANFD8_MB47TO32_IRQn, Config->CanFd8MB47TO32_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(CANFD8_MB47TO32_IRQn);
    INTR_RM.EIE3.bits.CANFD8_MB_47_32_IE = STD_ON;
#endif
#if (CANFD8MB63TO48_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(CANFD8_MB63TO48_IRQn, Config->CanFd8MB63TO48_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(CANFD8_MB63TO48_IRQn);
    INTR_RM.EIE3.bits.CANFD8_MB_63_48_IE = STD_ON;
#endif
#if (CANFD8_CANFDGEN_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(CANFD8_IRQn, Config->CanFd8Gen_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(CANFD8_IRQn);
    INTR_RM.EIE3.bits.CANFD8_GEN_IE = STD_ON;
#endif
#if (CANFD9_CANFDGEN_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(CANFD9_IRQn, Config->CanFd9Gen_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(CANFD9_IRQn);
    INTR_RM.EIE3.bits.CANFD9_GEN_IE = STD_ON;
#endif
#if (T31_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(T31_IRQn, Config->Timer31_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(T31_IRQn);
    INTR_RM.EIE3.bits.T31IE = STD_ON;
#endif
#if (T32_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(T32_IRQn, Config->Timer32_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(T32_IRQn);
    INTR_RM.EIE3.bits.T32IE = STD_ON;
#endif
#if (T33_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(T33_IRQn, Config->Timer33_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(T33_IRQn);
    INTR_RM.EIE3.bits.T33IE = STD_ON;
#endif
#if (T36_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(T36_IRQn, Config->Timer36_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(T36_IRQn);
    INTR_RM.EIE3.bits.T36IE = STD_ON;
#endif
#if (T9_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(T9_IRQn, Config->Timer9_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(T9_IRQn);
    INTR_RM.EIE3.bits.T9IE = STD_ON;
#endif
#if (T10_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(T10_IRQn, Config->Timer10_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(T10_IRQn);
    INTR_RM.EIE3.bits.T10IE = STD_ON;
#endif
#if (CANFD9_BUSERR_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(CANFD9_BUS_IRQn, Config->CanFd9BusErr_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(CANFD9_BUS_IRQn);
    INTR_RM.EIE3.bits.CANFD9_BUS_IE = STD_ON;
#endif
#if (STOPWATCHTICK_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(STOPWATCHTICK_IRQn, Config->StopWatchTick_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(STOPWATCHTICK_IRQn);
    INTR_RM.EIE3.bits.TICKTIMER_IE = STD_ON;
#endif
#if (T21_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(T21_IRQn, Config->Timer21_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(T21_IRQn);
    INTR_RM.EIE3.bits.T21IE = STD_ON;
#endif
#if (A_BUSY_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(FLASH_A_BUSY_IRQn, Config->FlashABusy_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(FLASH_A_BUSY_IRQn);
    INTR_RM.EIE3.bits.A_BUSY_IE = STD_ON;
#endif
#if (B_BUSY_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(FLASH_B_BUSY_IRQn, Config->FlashBBusy_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(FLASH_B_BUSY_IRQn);
    INTR_RM.EIE3.bits.B_BUSY_IE = STD_ON;
#endif
#if (SRAMECC_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(SRAM_ECC_IRQn, Config->SramEcc_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(SRAM_ECC_IRQn);
    INTR_RM.EIE3.bits.SRAMECCIE = STD_ON;
#endif
#if (DRAMECC_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(DRAM_ECC_IRQn, Config->DramEcc_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(DRAM_ECC_IRQn);
    INTR_RM.EIE3.bits.DRAMECCIE = STD_ON;
#endif
#if (CACHEECC_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(CACHE_ECC_IRQn, Config->CacheEcc_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(CACHE_ECC_IRQn);
    INTR_RM.EIE3.bits.CACHEECCIE = STD_ON;
#endif
#if (FLASHECC_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(FLASH_ERR_IRQn, Config->FlashEcc_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(FLASH_ERR_IRQn);
    INTR_RM.EIE3.bits.FLASHECCIE = STD_ON;
#endif
#if (ISMU_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(ISMU_IRQn, Config->Mpu_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(ISMU_IRQn);
    INTR_RM.EIE3.bits.ISMUIE = STD_ON;
#endif
#if (CANFD9MB15TO0_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(CANFD9_MB15TO0_IRQn, Config->CanFd9MB15TO0_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(CANFD9_MB15TO0_IRQn);
    INTR_RM.EIE4.bits.CANFD9_MB_15_0_IE = STD_ON;
#endif
#if (CANFD9MB31TO16_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(CANFD9_MB31TO16_IRQn, Config->CanFd9MB31TO16_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(CANFD9_MB31TO16_IRQn);
    INTR_RM.EIE4.bits.CANFD9_MB_31_16_IE = STD_ON;
#endif
#if (CANFD9MB47TO32_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(CANFD9_MB47TO32_IRQn, Config->CanFd9MB47TO32_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(CANFD9_MB47TO32_IRQn);
    INTR_RM.EIE4.bits.CANFD9_MB_47_32_IE = STD_ON;
#endif
#if (CANFD9MB63TO48_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(CANFD9_MB63TO48_IRQn, Config->CanFd9MB63TO48_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(CANFD9_MB63TO48_IRQn);
    INTR_RM.EIE4.bits.CANFD9_MB_63_48_IE = STD_ON;
#endif
#if (AES_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(AES_IRQn, Config->CanFd9MB63TO48_Priority, Config->PriorityGroup);
    Intr_LL_ClearInterruptFlag(AES_IRQn);
    INTR_RM.EIE4.bits.AESIE = STD_ON;
#endif
/* PRQA S 3332 1 #KQR003332 */
#if (IRQ_UNIFIED_INTERRUPT == STD_ON)
    /* PRQA S 1006 2 #KQR101006 */
    /* PRQA S 2743 1 #KQR002743 */
    ENABLE_INTERRUPT();
#else
    DISABLE_INTERRUPT();
#endif
};

/**
 * @brief The interrupt deinitialization and closes the interrupt according to the configuration
 * @details
 * Service name: Irq_Deinit
 * Syntax: void Irq_Deinit(void)
 * Service ID[hex]:
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * @implements
 * @param None
 * @retval None
 */
FUNC(void, BSWM_CODE) Irq_Deinit(void)
{
    PriorityType Priority;
    /*PRQA S 2983 2 #KQR002983 */
    Priority.Preemption_Priority = 0U;
    Priority.Sub_Priority        = 0U;

    INTR_RM.CTL0.bits.PRIGROUP = 0U;
#if (SYSTICK_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(SysTick_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(SysTick_IRQn);
    INTR_RM.EIE0.bits.SYSTICKIE = STD_OFF;
#endif
#if (WWDT_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(WWDT_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(WWDT_IRQn);
    INTR_RM.EIE1.bits.WWDTIE = STD_OFF;
#endif
#if (EINT16_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(EINT16_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(EINT16_IRQn);
    INTR_RM.EIE1.bits.EINT16IE = STD_OFF;
#endif
#if (PA_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(PA_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(PA_IRQn);
    INTR_RM.EIE1.bits.PAIE = STD_OFF;
#endif
#if (PB_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(PB_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(PB_IRQn);
    INTR_RM.EIE1.bits.PBIE = STD_OFF;
#endif
#if (PC_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(PC_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(PC_IRQn);
    INTR_RM.EIE1.bits.PCIE = STD_OFF;
#endif
#if (PD_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(PD_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(PD_IRQn);
    INTR_RM.EIE1.bits.PDIE = STD_OFF;
#endif
#if (PE_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(PE_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(PE_IRQn);
    INTR_RM.EIE1.bits.PEIE = STD_OFF;
#endif
#if (PF_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(PF_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(PF_IRQn);
    INTR_RM.EIE1.bits.PFIE = STD_OFF;
#endif
#if (PX_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(PX_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(PX_IRQn);
    INTR_RM.EIE1.bits.PXIE = STD_OFF;
#endif
#if (T1_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(T1_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(T1_IRQn);
    INTR_RM.EIE1.bits.T1IE = STD_OFF;
#endif
#if (T3_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(T3_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(T3_IRQn);
    INTR_RM.EIE1.bits.T3IE = STD_OFF;
#endif
#if (T5_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(T5_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(T5_IRQn);
    INTR_RM.EIE1.bits.T5IE = STD_OFF;
#endif
#if (T6_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(T6_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(T6_IRQn);
    INTR_RM.EIE1.bits.T6IE = STD_OFF;
#endif
#if (CANFD6MB15TO0_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(CANFD6_MB15TO0_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(CANFD6_MB15TO0_IRQn);
    INTR_RM.EIE1.bits.CANFD6_MB_15_0_IE = STD_OFF;
#endif
#if (CANFD6MB31TO16_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(CANFD6_MB31TO16_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(CANFD6_MB31TO16_IRQn);
    INTR_RM.EIE1.bits.CANFD6_MB_31_16_IE = STD_OFF;
#endif
#if (CANFD6MB47TO32_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(CANFD6_MB47TO32_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(CANFD6_MB47TO32_IRQn);
    INTR_RM.EIE1.bits.CANFD6_MB_47_32_IE = STD_OFF;
#endif
#if (CANFD6MB63TO48_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(CANFD6_MB63TO48_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(CANFD6_MB63TO48_IRQn);
    INTR_RM.EIE1.bits.CANFD6_MB_63_48_IE = STD_OFF;
#endif
#if (T14_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(T14_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(T14_IRQn);
    INTR_RM.EIE1.bits.T14IE = STD_OFF;
#endif
#if (RNG_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(RNG_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(RNG_IRQn);
    INTR_RM.EIE1.bits.RNGIE = STD_OFF;
#endif
#if (CANFD7MB15TO0_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(CANFD7_MB15TO0_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(CANFD7_MB15TO0_IRQn);
    INTR_RM.EIE1.bits.CANFD7_MB_15_0_IE = STD_OFF;
#endif
#if (CANFD7MB31TO16_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(CANFD7_MB31TO16_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(CANFD7_MB31TO16_IRQn);
    INTR_RM.EIE1.bits.CANFD7_MB_31_16_IE = STD_OFF;
#endif
#if (ADC0_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(ADC0_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(ADC0_IRQn);
    INTR_RM.EIE1.bits.ADC0IE = STD_OFF;
#endif
#if (ADC1_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(ADC1_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(ADC1_IRQn);
    INTR_RM.EIE1.bits.ADC1IE = STD_OFF;
#endif
#if (CANFD6_BUSERR_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(CANFD6_BUS_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(CANFD6_BUS_IRQn);
    INTR_RM.EIE1.bits.CANFD6_BUS_IE = STD_OFF;
#endif
#if (T11_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(T11_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(T11_IRQn);
    INTR_RM.EIE1.bits.T11IE = STD_OFF;
#endif
#if (T0_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(T0_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(T0_IRQn);
    INTR_RM.EIE1.bits.T0IE = STD_OFF;
#endif
#if (DMA0_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(DMA0_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(DMA0_IRQn);
    INTR_RM.EIE1.bits.DMA0IE = STD_OFF;
#endif
#if (CMP_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(CMP_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(CMP_IRQn);
    INTR_RM.EIE1.bits.CMPIE = STD_OFF;
#endif
#if (USART0_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(USART0_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(USART0_IRQn);
    INTR_RM.EIE1.bits.USART0IE = STD_OFF;
#endif
#if (USART1_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(USART1_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(USART1_IRQn);
    INTR_RM.EIE1.bits.USART1IE = STD_OFF;
#endif
#if (SPI0_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(SPI0_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(SPI0_IRQn);
    INTR_RM.EIE1.bits.SPI0IE = STD_OFF;
#endif
#if (SPI1_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(SPI1_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(SPI1_IRQn);
    INTR_RM.EIE1.bits.SPI1IE = STD_OFF;
#endif
#if (DMA1_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(DMA1_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(DMA1_IRQn);
    INTR_RM.EIE2.bits.DMA1IE = STD_OFF;
#endif
#if (EINT19_17_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(EINT19TO17_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(EINT19TO17_IRQn);
    INTR_RM.EIE2.bits.EINT19TO17IE = STD_OFF;
#endif
#if (CANFD6_CANFDGEN_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(CANFD6_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(CANFD6_IRQn);
    INTR_RM.EIE2.bits.CANFD6_GEN_IE = STD_OFF;
#endif
#if (CANFD7_CANFDGEN_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(CANFD7_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(CANFD7_IRQn);
    INTR_RM.EIE2.bits.CANFD7_GEN_IE = STD_OFF;
#endif
#if (CANFD7MB47TO32_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(CANFD7_MB47TO32_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(CANFD7_MB47TO32_IRQn);
    INTR_RM.EIE2.bits.CANFD7_MB_47_32_IE = STD_OFF;
#endif
#if (CANFD7MB63TO48_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(CANFD7_MB63TO48_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(CANFD7_MB63TO48_IRQn);
    INTR_RM.EIE2.bits.CANFD7_MB_63_48_IE = STD_OFF;
#endif
#if (EINT31_20_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(EINT31TO20_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(EINT31TO20_IRQn);
    INTR_RM.EIE2.bits.EINT31TO20IE = STD_OFF;
#endif
#if (CMU_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(CMU_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(CMU_IRQn);
    INTR_RM.EIE2.bits.CMUIE = STD_OFF;
#endif
#if (OSC_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(OSC_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(OSC_IRQn);
    INTR_RM.EIE2.bits.OSCIE = STD_OFF;
#endif
#if (CLK_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(CLK_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(CLK_IRQn);
    INTR_RM.EIE2.bits.OSCIE = STD_OFF;
#endif
#if (IIC0_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(I2C0_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(I2C0_IRQn);
    INTR_RM.EIE2.bits.I2C0IE = STD_OFF;
#endif
#if (IIC1_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(I2C1_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(I2C1_IRQn);
    INTR_RM.EIE2.bits.I2C1IE = STD_OFF;
#endif
#if (IIC2_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(I2C2_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(I2C2_IRQn);
    INTR_RM.EIE2.bits.I2C2IE = STD_OFF;
#endif
#if (T12_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(T12_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(T12_IRQn);
    INTR_RM.EIE2.bits.T12IE = STD_OFF;
#endif
#if (T2_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(T2_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(T2_IRQn);
    INTR_RM.EIE2.bits.T2IE = STD_OFF;
#endif
#if (T4_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(T4_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(T4_IRQn);
    INTR_RM.EIE2.bits.T4IE = STD_OFF;
#endif
#if (T13_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(T13_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(T13_IRQn);
    INTR_RM.EIE2.bits.T13IE = STD_OFF;
#endif
#if (USART2_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(USART2_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(USART2_IRQn);
    INTR_RM.EIE2.bits.USART2IE = STD_OFF;
#endif
#if (T16_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(T16_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(T16_IRQn);
    INTR_RM.EIE2.bits.T16IE = STD_OFF;
#endif
#if (USART6_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(USART6_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(USART6_IRQn);
    INTR_RM.EIE2.bits.USART6IE = STD_OFF;
#endif
#if (SPI2_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(SPI2_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(SPI2_IRQn);
    INTR_RM.EIE2.bits.SPI2IE = STD_OFF;
#endif
#if (CANFD7_BUSERR_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(CANFD7_BUS_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(CANFD7_BUS_IRQn);
    INTR_RM.EIE2.bits.CANFD7_BUS_IE = STD_OFF;
#endif
#if (WKP_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(WKP_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(WKP_IRQn);
    INTR_RM.EIE2.bits.WKPIE = STD_OFF;
#endif
#if (CANFD8_BUSERR_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(CANFD8_BUS_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(CANFD8_BUS_IRQn);
    INTR_RM.EIE2.bits.CANFD8_BUS_IE = STD_OFF;
#endif
#if (T20_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(T20_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(T20_IRQn);
    INTR_RM.EIE2.bits.T20IE = STD_OFF;
#endif
#if (USART3_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(USART3_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(USART3_IRQn);
    INTR_RM.EIE3.bits.USART3IE = STD_OFF;
#endif
#if (SHA_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(SHA_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(SHA_IRQn);
    INTR_RM.EIE3.bits.SHA_IE = STD_OFF;
#endif
#if (RSA_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(RSA_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(RSA_IRQn);
    INTR_RM.EIE3.bits.RSA_IE = STD_OFF;
#endif
#if (FIRSTK_PROG_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(FIRSTK_PROG_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(FIRSTK_PROG_IRQn);
    INTR_RM.EIE3.bits.FIRSTK_PROG_IE = STD_OFF;
#endif
#if (FIRSTK_SERA_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(FIRSTK_SERA_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(FIRSTK_SERA_IRQn);
    INTR_RM.EIE3.bits.FIRSTK_SERA_IE = STD_OFF;
#endif
#if (CANFD8MB15TO0_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(CANFD8_MB15TO0_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(CANFD8_MB15TO0_IRQn);
    INTR_RM.EIE3.bits.CANFD8_MB_15_0_IE = STD_OFF;
#endif
#if (CANFD8MB31TO16_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(CANFD8_MB31TO16_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(CANFD8_MB31TO16_IRQn);
    INTR_RM.EIE3.bits.CANFD8_MB_31_16_IE = STD_OFF;
#endif
#if (CANFD8MB47TO32_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(CANFD8_MB47TO32_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(CANFD8_MB47TO32_IRQn);
    INTR_RM.EIE3.bits.CANFD8_MB_47_32_IE = STD_OFF;
#endif
#if (CANFD8MB63TO48_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(CANFD8_MB63TO48_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(CANFD8_MB63TO48_IRQn);
    INTR_RM.EIE3.bits.CANFD8_MB_63_48_IE = STD_OFF;
#endif
#if (CANFD8_CANFDGEN_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(CANFD8_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(CANFD8_IRQn);
    INTR_RM.EIE3.bits.CANFD8_GEN_IE = STD_OFF;
#endif
#if (CANFD9_CANFDGEN_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(CANFD9_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(CANFD9_IRQn);
    INTR_RM.EIE3.bits.CANFD9_GEN_IE = STD_OFF;
#endif
#if (T31_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(T31_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(T31_IRQn);
    INTR_RM.EIE3.bits.T31IE = STD_OFF;
#endif
#if (T32_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(T32_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(T32_IRQn);
    INTR_RM.EIE3.bits.T32IE = STD_OFF;
#endif
#if (T33_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(T33_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(T33_IRQn);
    INTR_RM.EIE3.bits.T33IE = STD_OFF;
#endif
#if (T36_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(T36_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(T36_IRQn);
    INTR_RM.EIE3.bits.T36IE = STD_OFF;
#endif
#if (T9_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(T9_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(T9_IRQn);
    INTR_RM.EIE3.bits.T9IE = STD_OFF;
#endif
#if (T10_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(T10_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(T10_IRQn);
    INTR_RM.EIE3.bits.T10IE = STD_OFF;
#endif
#if (CANFD9_BUSERR_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(CANFD9_BUS_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(CANFD9_BUS_IRQn);
    INTR_RM.EIE3.bits.CANFD9_BUS_IE = STD_OFF;
#endif
#if (STOPWATCHTICK_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(STOPWATCHTICK_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(STOPWATCHTICK_IRQn);
    INTR_RM.EIE3.bits.TICKTIMER_IE = STD_OFF;
#endif
#if (T21_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(T21_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(T21_IRQn);
    INTR_RM.EIE3.bits.T21IE = STD_OFF;
#endif
#if (A_BUSY_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(FLASH_A_BUSY_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(FLASH_A_BUSY_IRQn);
    INTR_RM.EIE3.bits.A_BUSY_IE = STD_OFF;
#endif
#if (B_BUSY_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(FLASH_B_BUSY_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(FLASH_B_BUSY_IRQn);
    INTR_RM.EIE3.bits.B_BUSY_IE = STD_OFF;
#endif
#if (SRAMECC_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(SRAM_ECC_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(SRAM_ECC_IRQn);
    INTR_RM.EIE3.bits.SRAMECCIE = STD_OFF;
#endif
#if (DRAMECC_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(DRAM_ECC_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(DRAM_ECC_IRQn);
    INTR_RM.EIE3.bits.DRAMECCIE = STD_OFF;
#endif
#if (CACHEECC_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(CACHE_ECC_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(CACHE_ECC_IRQn);
    INTR_RM.EIE3.bits.CACHEECCIE = STD_OFF;
#endif
#if (FLASHECC_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(FLASH_ERR_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(FLASH_ERR_IRQn);
    INTR_RM.EIE3.bits.FLASHECCIE = STD_OFF;
#endif
#if (ISMU_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(ISMU_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(ISMU_IRQn);
    INTR_RM.EIE3.bits.ISMUIE = STD_OFF;
#endif
#if (CANFD9MB15TO0_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(CANFD9_MB15TO0_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(CANFD9_MB15TO0_IRQn);
    INTR_RM.EIE4.bits.CANFD9_MB_15_0_IE = STD_OFF;
#endif
#if (CANFD9MB31TO16_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(CANFD9_MB31TO16_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(CANFD9_MB31TO16_IRQn);
    INTR_RM.EIE4.bits.CANFD9_MB_31_16_IE = STD_OFF;
#endif
#if (CANFD9MB47TO32_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(CANFD9_MB47TO32_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(CANFD9_MB47TO32_IRQn);
    INTR_RM.EIE4.bits.CANFD9_MB_47_32_IE = STD_OFF;
#endif
#if (CANFD9MB63TO48_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(CANFD9_MB63TO48_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(CANFD9_MB63TO48_IRQn);
    INTR_RM.EIE4.bits.CANFD9_MB_63_48_IE = STD_OFF;
#endif
#if (AES_UNIFIED_INTERRUPT == STD_ON)
    Intr_SetPriority(AES_IRQn, Priority, 0U);
    Intr_LL_ClearInterruptFlag(AES_IRQn);
    INTR_RM.EIE4.bits.AESIE = STD_OFF;
#endif
/* PRQA S 3332 1 #KQR003332 */
#if (IRQ_UNIFIED_INTERRUPT == STD_ON)
    /* PRQA S 1006 2 #KQR101006 */
    /* PRQA S 2743 1 #KQR002743 */
    DISABLE_INTERRUPT();
#endif
};