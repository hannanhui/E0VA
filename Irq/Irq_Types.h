/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Irq_Types.h
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
#ifndef IRQ_TYPES_H
#define IRQ_TYPES_H
/******************************************************************************
**                        Include Files
******************************************************************************/
#include "Mcal.h"
#include "Irq_Cfg.h"
/******************************************************************************
**                        Macro Definitions
******************************************************************************/

/**
 * @brief interrupt priority define
 */
#define IRQ_INTR_PREEMP_0 (3U)
#define IRQ_INTR_PREEMP_1 (2U)
#define IRQ_INTR_PREEMP_2 (1U)
#define IRQ_INTR_PREEMP_3 (0U)
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
**                        Function definitions
******************************************************************************/
typedef struct
{
    VAR(uint8, AUTOMATIC) Preemption_Priority;
    VAR(uint8, AUTOMATIC) Sub_Priority;
} PriorityType;

/* PRQA S 3630 ++ #KQR003630 */
typedef struct
{
    uint32 PriorityGroup;
#if (SYSTICK_UNIFIED_INTERRUPT == STD_ON)
    PriorityType Systick_Priority;
#endif
#if (WWDT_UNIFIED_INTERRUPT == STD_ON)
    PriorityType WWDT_Priority;
#endif
#if (EINT16_UNIFIED_INTERRUPT == STD_ON)
    PriorityType Eint16_Priority;
#endif
#if (PA_UNIFIED_INTERRUPT == STD_ON)
    PriorityType PA_Priority;
#endif
#if (PB_UNIFIED_INTERRUPT == STD_ON)
    PriorityType PB_Priority;
#endif
#if (PC_UNIFIED_INTERRUPT == STD_ON)
    PriorityType PC_Priority;
#endif
#if (PD_UNIFIED_INTERRUPT == STD_ON)
    PriorityType PD_Priority;
#endif
#if (PE_UNIFIED_INTERRUPT == STD_ON)
    PriorityType PE_Priority;
#endif
#if (PF_UNIFIED_INTERRUPT == STD_ON)
    PriorityType PF_Priority;
#endif
#if (PX_UNIFIED_INTERRUPT == STD_ON)
    PriorityType PX_Priority;
#endif
#if (T1_UNIFIED_INTERRUPT == STD_ON)
    PriorityType Timer1_Priority;
#endif
#if (T3_UNIFIED_INTERRUPT == STD_ON)
    PriorityType Timer3_Priority;
#endif
#if (T5_UNIFIED_INTERRUPT == STD_ON)
    PriorityType Timer5_Priority;
#endif
#if (T6_UNIFIED_INTERRUPT == STD_ON)
    PriorityType Timer6_Priority;
#endif
#if (CANFD6MB15TO0_UNIFIED_INTERRUPT == STD_ON)
    PriorityType CanFd6MB15TO0_Priority;
#endif
#if (CANFD6MB31TO16_UNIFIED_INTERRUPT == STD_ON)
    PriorityType CanFd6MB31TO16_Priority;
#endif
#if (CANFD6MB47TO32_UNIFIED_INTERRUPT == STD_ON)
    PriorityType CanFd6MB47TO32_Priority;
#endif
#if (CANFD6MB63TO48_UNIFIED_INTERRUPT == STD_ON)
    PriorityType CanFd6MB63TO48_Priority;
#endif
#if (T14_UNIFIED_INTERRUPT == STD_ON)
    PriorityType Timer14_Priority;
#endif
#if (RNG_UNIFIED_INTERRUPT == STD_ON)
    PriorityType Rng_Priority;
#endif
#if (CANFD7MB15TO0_UNIFIED_INTERRUPT == STD_ON)
    PriorityType CanFd7MB15TO0_Priority;
#endif
#if (CANFD7MB31TO16_UNIFIED_INTERRUPT == STD_ON)
    PriorityType CanFd7MB31TO16_Priority;
#endif
#if (ADC0_UNIFIED_INTERRUPT == STD_ON)
    PriorityType Adc0_Priority;
#endif
#if (ADC1_UNIFIED_INTERRUPT == STD_ON)
    PriorityType Adc1_Priority;
#endif
#if (CANFD6_BUSERR_UNIFIED_INTERRUPT == STD_ON)
    PriorityType CanFd6BusErr_Priority;
#endif
#if (T11_UNIFIED_INTERRUPT == STD_ON)
    PriorityType Timer11_Priority;
#endif
#if (T0_UNIFIED_INTERRUPT == STD_ON)
    PriorityType Timer0_Priority;
#endif
#if (DMA0_UNIFIED_INTERRUPT == STD_ON)
    PriorityType Dma0_Priority;
#endif
#if (CMP_UNIFIED_INTERRUPT == STD_ON)
    PriorityType Cmp_Priority;
#endif
#if (USART0_UNIFIED_INTERRUPT == STD_ON)
    PriorityType Usart0_Priority;
#endif
#if (USART1_UNIFIED_INTERRUPT == STD_ON)
    PriorityType Usart1_Priority;
#endif
#if (SPI0_UNIFIED_INTERRUPT == STD_ON)
    PriorityType Spi0_Priority;
#endif
#if (SPI1_UNIFIED_INTERRUPT == STD_ON)
    PriorityType Spi1_Priority;
#endif
#if (DMA1_UNIFIED_INTERRUPT == STD_ON)
    PriorityType Dma1_Priority;
#endif
#if (EINT19_17_UNIFIED_INTERRUPT == STD_ON)
    PriorityType Eint19_17_Priority;
#endif
#if (CANFD6_CANFDGEN_UNIFIED_INTERRUPT == STD_ON)
    PriorityType CanFd6Gen_Priority;
#endif
#if (CANFD7_CANFDGEN_UNIFIED_INTERRUPT == STD_ON)
    PriorityType CanFd7Gen_Priority;
#endif
#if (CANFD7MB47TO32_UNIFIED_INTERRUPT == STD_ON)
    PriorityType CanFd7MB47TO32_Priority;
#endif
#if (CANFD7MB63TO48_UNIFIED_INTERRUPT == STD_ON)
    PriorityType CanFd7MB63TO48_Priority;
#endif
#if (EINT31_20_UNIFIED_INTERRUPT == STD_ON)
    PriorityType Eint31_20_Priority;
#endif
#if (CMU_UNIFIED_INTERRUPT == STD_ON)
    PriorityType Cmu_Priority;
#endif
#if (OSC_UNIFIED_INTERRUPT == STD_ON)
    PriorityType Osc_Priority;
#endif
#if (CLK_UNIFIED_INTERRUPT == STD_ON)
    PriorityType Clk_Priority;
#endif
#if (IIC0_UNIFIED_INTERRUPT == STD_ON)
    PriorityType IIC0_Priority;
#endif
#if (IIC1_UNIFIED_INTERRUPT == STD_ON)
    PriorityType IIC1_Priority;
#endif
#if (IIC2_UNIFIED_INTERRUPT == STD_ON)
    PriorityType IIC2_Priority;
#endif
#if (T12_UNIFIED_INTERRUPT == STD_ON)
    PriorityType Timer12_Priority;
#endif
#if (T2_UNIFIED_INTERRUPT == STD_ON)
    PriorityType Timer2_Priority;
#endif
#if (T4_UNIFIED_INTERRUPT == STD_ON)
    PriorityType Timer4_Priority;
#endif
#if (T13_UNIFIED_INTERRUPT == STD_ON)
    PriorityType Timer13_Priority;
#endif
#if (USART2_UNIFIED_INTERRUPT == STD_ON)
    PriorityType Usart2_Priority;
#endif
#if (T16_UNIFIED_INTERRUPT == STD_ON)
    PriorityType Timer16_Priority;
#endif
#if (USART6_UNIFIED_INTERRUPT == STD_ON)
    PriorityType Usart6_Priority;
#endif
#if (SPI2_UNIFIED_INTERRUPT == STD_ON)
    PriorityType Spi2_Priority;
#endif
#if (CANFD7_BUSERR_UNIFIED_INTERRUPT == STD_ON)
    PriorityType CanFd7BusErr_Priority;
#endif
#if (WKP_UNIFIED_INTERRUPT == STD_ON)
    PriorityType Wkp_Priority;
#endif
#if (CANFD8_BUSERR_UNIFIED_INTERRUPT == STD_ON)
    PriorityType CanFd8BusErr_Priority;
#endif
#if (T20_UNIFIED_INTERRUPT == STD_ON)
    PriorityType Timer20_Priority;
#endif
#if (USART3_UNIFIED_INTERRUPT == STD_ON)
    PriorityType Usart3_Priority;
#endif
#if (SHA_UNIFIED_INTERRUPT == STD_ON)
    PriorityType Sha_Priority;
#endif
#if (RSA_UNIFIED_INTERRUPT == STD_ON)
    PriorityType Rsa_Priority;
#endif
#if (FIRSTK_PROG_UNIFIED_INTERRUPT == STD_ON)
    PriorityType Firstk_Prog_Priority;
#endif
#if (FIRSTK_SERA_UNIFIED_INTERRUPT == STD_ON)
    PriorityType Firstk_Sera_Priority;
#endif
#if (CANFD8MB15TO0_UNIFIED_INTERRUPT == STD_ON)
    PriorityType CanFd8MB15TO0_Priority;
#endif
#if (CANFD8MB31TO16_UNIFIED_INTERRUPT == STD_ON)
    PriorityType CanFd8MB31TO16_Priority;
#endif
#if (CANFD8MB47TO32_UNIFIED_INTERRUPT == STD_ON)
    PriorityType CanFd8MB47TO32_Priority;
#endif
#if (CANFD8MB63TO48_UNIFIED_INTERRUPT == STD_ON)
    PriorityType CanFd8MB63TO48_Priority;
#endif
#if (CANFD8_CANFDGEN_UNIFIED_INTERRUPT == STD_ON)
    PriorityType CanFd8Gen_Priority;
#endif
#if (CANFD9_CANFDGEN_UNIFIED_INTERRUPT == STD_ON)
    PriorityType CanFd9Gen_Priority;
#endif
#if (T31_UNIFIED_INTERRUPT == STD_ON)
    PriorityType Timer31_Priority;
#endif
#if (T32_UNIFIED_INTERRUPT == STD_ON)
    PriorityType Timer32_Priority;
#endif
#if (T33_UNIFIED_INTERRUPT == STD_ON)
    PriorityType Timer33_Priority;
#endif
#if (T36_UNIFIED_INTERRUPT == STD_ON)
    PriorityType Timer36_Priority;
#endif
#if (T9_UNIFIED_INTERRUPT == STD_ON)
    PriorityType Timer9_Priority;
#endif
#if (T10_UNIFIED_INTERRUPT == STD_ON)
    PriorityType Timer10_Priority;
#endif
#if (CANFD9_BUSERR_UNIFIED_INTERRUPT == STD_ON)
    PriorityType CanFd9BusErr_Priority;
#endif
#if (STOPWATCHTICK_UNIFIED_INTERRUPT == STD_ON)
    PriorityType StopWatchTick_Priority;
#endif
#if (T21_UNIFIED_INTERRUPT == STD_ON)
    PriorityType Timer21_Priority;
#endif
#if (A_BUSY_UNIFIED_INTERRUPT == STD_ON)
    PriorityType FlashABusy_Priority;
#endif
#if (B_BUSY_UNIFIED_INTERRUPT == STD_ON)
    PriorityType FlashBBusy_Priority;
#endif

#if (SRAMECC_UNIFIED_INTERRUPT == STD_ON)
    PriorityType SramEcc_Priority;
#endif
#if (DRAMECC_UNIFIED_INTERRUPT == STD_ON)
    PriorityType DramEcc_Priority;
#endif
#if (CACHEECC_UNIFIED_INTERRUPT == STD_ON)
    PriorityType CacheEcc_Priority;
#endif
#if (FLASHECC_UNIFIED_INTERRUPT == STD_ON)
    PriorityType FlashEcc_Priority;
#endif
#if (ISMU_UNIFIED_INTERRUPT == STD_ON)
    PriorityType Mpu_Priority;
#endif
#if (CANFD9MB15TO0_UNIFIED_INTERRUPT == STD_ON)
    PriorityType CanFd9MB15TO0_Priority;
#endif
#if (CANFD9MB31TO16_UNIFIED_INTERRUPT == STD_ON)
    PriorityType CanFd9MB31TO16_Priority;
#endif
#if (CANFD9MB47TO32_UNIFIED_INTERRUPT == STD_ON)
    PriorityType CanFd9MB47TO32_Priority;
#endif
#if (CANFD9MB63TO48_UNIFIED_INTERRUPT == STD_ON)
    PriorityType CanFd9MB63TO48_Priority;
#endif
#if (AES_UNIFIED_INTERRUPT == STD_ON)
    PriorityType Aes;
#endif
    /* PRQA S 3205 1 #KQR003205 */
} Irq_ConfigType;
/* PRQA S 3630 -- #KQR003630 */

#ifdef __cplusplus
}
#endif

#endif
