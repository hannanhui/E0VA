/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Irq_Cfg.h
 *  @Syntax          : GNU99
 *  @Author          : ChipON AE/FAE Group
 *  @Date            : 2026/3/26 10:58:41
 *  @Version         : V1.0
 *  @Description     : This document describes the C language document template.
 ******************************************************************************
 *  Copyright (C) by Shanghai ChipON Micro-Electronic Co.,Ltd
 *  All rights reserved.
 *
 *  This software is copyright protected and proprietary to
 *  Shanghai ChipON Micro-Electronic Co.,Ltd.
 *****************************************************************************/
#ifndef IRQ_CFG_H
#define IRQ_CFG_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 **                        Include Files
 ******************************************************************************/
#include "Std_Types.h"

/******************************************************************************
 **                        File Version Check
 ******************************************************************************/

/******************************************************************************
 **                        Macro Definitions
 ******************************************************************************/
/**
 * @brief:The detection of development errors is configurable (ON / OFF) at
 * pre-compile time. The switch IrqDevErrorDetectApi shall activate or
 * deactivate the detection of all development errors
 */
#define IRQ_DEV_ERROR_DETECT_API (STD_OFF)
/** IRQ Module ID */
#define IRQ_MODULE_ID (188)
/** IRQ MODULE INSTANCE ID */
#define IRQ_INSTANCE_ID ((uint8_t)0U)
/** An interrupt is generated, but no module is used */
#define IRQ_E_INTERRUPT_NOT_USE ((uint8_t)16U)

#define IRQ_CAT1  (0U)
#define IRQ_CAT23 (1U)

#define IRQ_CAT_T0         (IRQ_CAT1)
#define IRQ_CAT_T1         (IRQ_CAT1)
#define IRQ_CAT_T2         (IRQ_CAT1)
#define IRQ_CAT_T3         (IRQ_CAT1)
#define IRQ_CAT_T4         (IRQ_CAT1)
#define IRQ_CAT_T5         (IRQ_CAT1)
#define IRQ_CAT_T6         (IRQ_CAT1)
#define IRQ_CAT_T9         (IRQ_CAT1)
#define IRQ_CAT_T10        (IRQ_CAT1)
#define IRQ_CAT_T11        (IRQ_CAT1)
#define IRQ_CAT_T12        (IRQ_CAT1)
#define IRQ_CAT_T13        (IRQ_CAT1)
#define IRQ_CAT_T14        (IRQ_CAT1)
#define IRQ_CAT_T16        (IRQ_CAT1)
#define IRQ_CAT_T20        (IRQ_CAT1)
#define IRQ_CAT_T21        (IRQ_CAT1)
#define IRQ_CAT_T31        (IRQ_CAT1)
#define IRQ_CAT_T32        (IRQ_CAT1)
#define IRQ_CAT_T33        (IRQ_CAT1)
#define IRQ_CAT_T36        (IRQ_CAT1)
#define IRQ_CAT_DMA0       (IRQ_CAT1)
#define IRQ_CAT_DMA1       (IRQ_CAT1)
#define IRQ_CAT_I2C0       (IRQ_CAT1)
#define IRQ_CAT_I2C1       (IRQ_CAT1)
#define IRQ_CAT_I2C2       (IRQ_CAT1)
#define IRQ_CAT_USART0     (IRQ_CAT1)
#define IRQ_CAT_USART1     (IRQ_CAT1)
#define IRQ_CAT_USART2     (IRQ_CAT1)
#define IRQ_CAT_USART3     (IRQ_CAT1)
#define IRQ_CAT_USART6     (IRQ_CAT1)
#define IRQ_CAT_SPI0       (IRQ_CAT1)
#define IRQ_CAT_SPI1       (IRQ_CAT1)
#define IRQ_CAT_SPI2       (IRQ_CAT1)
#define IRQ_CAT_ADC0       (IRQ_CAT1)
#define IRQ_CAT_ADC1       (IRQ_CAT1)
#define IRQ_CAT_EINTA      (IRQ_CAT1)
#define IRQ_CAT_EINTB      (IRQ_CAT1)
#define IRQ_CAT_EINTC      (IRQ_CAT1)
#define IRQ_CAT_EINTD      (IRQ_CAT1)
#define IRQ_CAT_EINTE      (IRQ_CAT1)
#define IRQ_CAT_EINTF      (IRQ_CAT1)
#define IRQ_CAT_EINTX      (IRQ_CAT1)
#define IRQ_CAT_SRAMECC    (IRQ_CAT1)
#define IRQ_CAT_FLASHECC   (IRQ_CAT1)
#define IRQ_CAT_EINT19TO17 (IRQ_CAT1)
#define IRQ_CAT_CANFD6     (IRQ_CAT1)
#define IRQ_CAT_CANFD7     (IRQ_CAT1)
#define IRQ_CAT_CANFD8     (IRQ_CAT1)
#define IRQ_CAT_CANFD9     (IRQ_CAT1)

/* watch dog unit config */
#define T14_WDG_USED (STD_ON)

#define SYSTICK_UNIFIED_INTERRUPT         (STD_OFF)
#define WWDT_UNIFIED_INTERRUPT            (STD_ON)
#define EINT16_UNIFIED_INTERRUPT          (STD_OFF)
#define PA_UNIFIED_INTERRUPT              (STD_OFF)
#define PB_UNIFIED_INTERRUPT              (STD_OFF)
#define PC_UNIFIED_INTERRUPT              (STD_OFF)
#define PD_UNIFIED_INTERRUPT              (STD_ON)
#define PE_UNIFIED_INTERRUPT              (STD_OFF)
#define PF_UNIFIED_INTERRUPT              (STD_OFF)
#define PX_UNIFIED_INTERRUPT              (STD_OFF)
#define T1_UNIFIED_INTERRUPT              (STD_OFF)
#define T3_UNIFIED_INTERRUPT              (STD_OFF)
#define T5_UNIFIED_INTERRUPT              (STD_OFF)
#define T6_UNIFIED_INTERRUPT              (STD_OFF)
#define CANFD6MB15TO0_UNIFIED_INTERRUPT   (STD_ON)
#define CANFD6MB31TO16_UNIFIED_INTERRUPT  (STD_ON)
#define CANFD6MB47TO32_UNIFIED_INTERRUPT  (STD_ON)
#define CANFD6MB63TO48_UNIFIED_INTERRUPT  (STD_ON)
#define T14_UNIFIED_INTERRUPT             (STD_ON)
#define RNG_UNIFIED_INTERRUPT             (STD_OFF)
#define CANFD7MB15TO0_UNIFIED_INTERRUPT   (STD_OFF)
#define CANFD7MB31TO16_UNIFIED_INTERRUPT  (STD_OFF)
#define ADC0_UNIFIED_INTERRUPT            (STD_ON)
#define ADC1_UNIFIED_INTERRUPT            (STD_OFF)
#define CANFD6_BUSERR_UNIFIED_INTERRUPT   (STD_ON)
#define T11_UNIFIED_INTERRUPT             (STD_OFF)
#define T0_UNIFIED_INTERRUPT              (STD_ON)
#define DMA0_UNIFIED_INTERRUPT            (STD_ON)
#define CMP_UNIFIED_INTERRUPT             (STD_OFF)
#define USART0_UNIFIED_INTERRUPT          (STD_ON)
#define USART1_UNIFIED_INTERRUPT          (STD_ON)
#define SPI0_UNIFIED_INTERRUPT            (STD_OFF)
#define SPI1_UNIFIED_INTERRUPT            (STD_OFF)
#define DMA1_UNIFIED_INTERRUPT            (STD_ON)
#define EINT19_17_UNIFIED_INTERRUPT       (STD_OFF)
#define CANFD6_CANFDGEN_UNIFIED_INTERRUPT (STD_ON)
#define CANFD7_CANFDGEN_UNIFIED_INTERRUPT (STD_OFF)
#define CANFD7MB47TO32_UNIFIED_INTERRUPT  (STD_OFF)
#define CANFD7MB63TO48_UNIFIED_INTERRUPT  (STD_OFF)
#define EINT31_20_UNIFIED_INTERRUPT       (STD_OFF)
#define CMU_UNIFIED_INTERRUPT             (STD_OFF)
#define OSC_UNIFIED_INTERRUPT             (STD_OFF)
#define CLK_UNIFIED_INTERRUPT             (STD_OFF)
#define IIC0_UNIFIED_INTERRUPT            (STD_OFF)
#define IIC1_UNIFIED_INTERRUPT            (STD_OFF)
#define IIC2_UNIFIED_INTERRUPT            (STD_OFF)
#define T12_UNIFIED_INTERRUPT             (STD_OFF)
#define T2_UNIFIED_INTERRUPT              (STD_OFF)
#define T4_UNIFIED_INTERRUPT              (STD_OFF)
#define T13_UNIFIED_INTERRUPT             (STD_OFF)
#define USART2_UNIFIED_INTERRUPT          (STD_OFF)
#define T16_UNIFIED_INTERRUPT             (STD_OFF)
#define USART6_UNIFIED_INTERRUPT          (STD_OFF)
#define SPI2_UNIFIED_INTERRUPT            (STD_OFF)
#define CANFD7_BUSERR_UNIFIED_INTERRUPT   (STD_OFF)
#define WKP_UNIFIED_INTERRUPT             (STD_OFF)
#define CANFD8_BUSERR_UNIFIED_INTERRUPT   (STD_OFF)
#define T20_UNIFIED_INTERRUPT             (STD_OFF)
#define USART3_UNIFIED_INTERRUPT          (STD_OFF)
#define SHA_UNIFIED_INTERRUPT             (STD_OFF)
#define RSA_UNIFIED_INTERRUPT             (STD_OFF)
#define FIRSTK_PROG_UNIFIED_INTERRUPT     (STD_OFF)
#define FIRSTK_SERA_UNIFIED_INTERRUPT     (STD_OFF)
#define CANFD8MB15TO0_UNIFIED_INTERRUPT   (STD_OFF)
#define CANFD8MB31TO16_UNIFIED_INTERRUPT  (STD_OFF)
#define CANFD8MB47TO32_UNIFIED_INTERRUPT  (STD_OFF)
#define CANFD8MB63TO48_UNIFIED_INTERRUPT  (STD_OFF)
#define CANFD8_CANFDGEN_UNIFIED_INTERRUPT (STD_OFF)
#define CANFD9_CANFDGEN_UNIFIED_INTERRUPT (STD_OFF)
#define T31_UNIFIED_INTERRUPT             (STD_OFF)
#define T32_UNIFIED_INTERRUPT             (STD_OFF)
#define T33_UNIFIED_INTERRUPT             (STD_OFF)
#define T36_UNIFIED_INTERRUPT             (STD_OFF)
#define T9_UNIFIED_INTERRUPT              (STD_OFF)
#define T10_UNIFIED_INTERRUPT             (STD_OFF)
#define CANFD9_BUSERR_UNIFIED_INTERRUPT   (STD_OFF)
#define STOPWATCHTICK_UNIFIED_INTERRUPT   (STD_OFF)
#define T21_UNIFIED_INTERRUPT             (STD_OFF)
#define A_BUSY_UNIFIED_INTERRUPT          (STD_OFF)
#define B_BUSY_UNIFIED_INTERRUPT          (STD_OFF)
#define SRAMECC_UNIFIED_INTERRUPT         (STD_OFF)
#define DRAMECC_UNIFIED_INTERRUPT         (STD_OFF)
#define CACHEECC_UNIFIED_INTERRUPT        (STD_OFF)
#define FLASHECC_UNIFIED_INTERRUPT        (STD_OFF)
#define ISMU_UNIFIED_INTERRUPT            (STD_OFF)
#define CANFD9MB15TO0_UNIFIED_INTERRUPT   (STD_OFF)
#define CANFD9MB31TO16_UNIFIED_INTERRUPT  (STD_OFF)
#define CANFD9MB47TO32_UNIFIED_INTERRUPT  (STD_OFF)
#define CANFD9MB63TO48_UNIFIED_INTERRUPT  (STD_OFF)
#define AES_UNIFIED_INTERRUPT             (STD_OFF)

#define IRQ_UNIFIED_INTERRUPT                                                                                          \
    (SYSTICK_UNIFIED_INTERRUPT || WWDT_UNIFIED_INTERRUPT || EINT16_UNIFIED_INTERRUPT || PA_UNIFIED_INTERRUPT ||        \
     PB_UNIFIED_INTERRUPT || PC_UNIFIED_INTERRUPT || PD_UNIFIED_INTERRUPT || PE_UNIFIED_INTERRUPT ||                   \
     PF_UNIFIED_INTERRUPT || PX_UNIFIED_INTERRUPT || T1_UNIFIED_INTERRUPT || T3_UNIFIED_INTERRUPT ||                   \
     T5_UNIFIED_INTERRUPT || T6_UNIFIED_INTERRUPT || CANFD6MB15TO0_UNIFIED_INTERRUPT ||                                \
     CANFD6MB31TO16_UNIFIED_INTERRUPT || CANFD6MB47TO32_UNIFIED_INTERRUPT || CANFD6MB63TO48_UNIFIED_INTERRUPT ||       \
     T14_UNIFIED_INTERRUPT || RNG_UNIFIED_INTERRUPT || CANFD7MB15TO0_UNIFIED_INTERRUPT ||                              \
     CANFD7MB31TO16_UNIFIED_INTERRUPT || ADC0_UNIFIED_INTERRUPT || ADC1_UNIFIED_INTERRUPT ||                           \
     CANFD6_BUSERR_UNIFIED_INTERRUPT || T11_UNIFIED_INTERRUPT || T0_UNIFIED_INTERRUPT || DMA0_UNIFIED_INTERRUPT ||     \
     CMP_UNIFIED_INTERRUPT || USART0_UNIFIED_INTERRUPT || USART1_UNIFIED_INTERRUPT || SPI0_UNIFIED_INTERRUPT ||        \
     SPI1_UNIFIED_INTERRUPT || DMA1_UNIFIED_INTERRUPT || EINT19_17_UNIFIED_INTERRUPT ||                                \
     CANFD6_CANFDGEN_UNIFIED_INTERRUPT || CANFD7_CANFDGEN_UNIFIED_INTERRUPT || CANFD7MB47TO32_UNIFIED_INTERRUPT ||     \
     CANFD7MB63TO48_UNIFIED_INTERRUPT || EINT31_20_UNIFIED_INTERRUPT || CMU_UNIFIED_INTERRUPT ||                       \
     OSC_UNIFIED_INTERRUPT || CLK_UNIFIED_INTERRUPT || IIC0_UNIFIED_INTERRUPT || IIC1_UNIFIED_INTERRUPT ||             \
     IIC2_UNIFIED_INTERRUPT || T12_UNIFIED_INTERRUPT || T2_UNIFIED_INTERRUPT || T4_UNIFIED_INTERRUPT ||                \
     T13_UNIFIED_INTERRUPT || USART2_UNIFIED_INTERRUPT || T16_UNIFIED_INTERRUPT || USART6_UNIFIED_INTERRUPT ||         \
     SPI2_UNIFIED_INTERRUPT || CANFD7_BUSERR_UNIFIED_INTERRUPT || WKP_UNIFIED_INTERRUPT ||                             \
     CANFD8_BUSERR_UNIFIED_INTERRUPT || T20_UNIFIED_INTERRUPT || USART3_UNIFIED_INTERRUPT || SHA_UNIFIED_INTERRUPT ||  \
     RSA_UNIFIED_INTERRUPT || FIRSTK_PROG_UNIFIED_INTERRUPT || FIRSTK_SERA_UNIFIED_INTERRUPT ||                        \
     CANFD8MB15TO0_UNIFIED_INTERRUPT || CANFD8MB31TO16_UNIFIED_INTERRUPT || CANFD8MB47TO32_UNIFIED_INTERRUPT ||        \
     CANFD8MB63TO48_UNIFIED_INTERRUPT || CANFD8_CANFDGEN_UNIFIED_INTERRUPT || CANFD9_CANFDGEN_UNIFIED_INTERRUPT ||     \
     T31_UNIFIED_INTERRUPT || T32_UNIFIED_INTERRUPT || T33_UNIFIED_INTERRUPT || T36_UNIFIED_INTERRUPT ||               \
     T9_UNIFIED_INTERRUPT || T10_UNIFIED_INTERRUPT || CANFD9_BUSERR_UNIFIED_INTERRUPT ||                               \
     STOPWATCHTICK_UNIFIED_INTERRUPT || T21_UNIFIED_INTERRUPT || A_BUSY_UNIFIED_INTERRUPT ||                           \
     B_BUSY_UNIFIED_INTERRUPT || SRAMECC_UNIFIED_INTERRUPT || DRAMECC_UNIFIED_INTERRUPT ||                             \
     CACHEECC_UNIFIED_INTERRUPT || FLASHECC_UNIFIED_INTERRUPT || ISMU_UNIFIED_INTERRUPT ||                             \
     CANFD9MB15TO0_UNIFIED_INTERRUPT || CANFD9MB31TO16_UNIFIED_INTERRUPT || CANFD9MB47TO32_UNIFIED_INTERRUPT ||        \
     CANFD9MB63TO48_UNIFIED_INTERRUPT || AES_UNIFIED_INTERRUPT)

/******************************************************************************
 **                        Typedef Definitions
 ******************************************************************************/

/******************************************************************************
 **                        Export Variables
 ******************************************************************************/

/******************************************************************************
 **                        Export Functions
 ******************************************************************************/

#ifdef __cplusplus
}
#endif

#endif
/* EOF */
