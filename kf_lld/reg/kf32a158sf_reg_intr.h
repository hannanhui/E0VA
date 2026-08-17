/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a158sf_reg_intr.h
 *  @Date            : 2025-07-03
 *  @Version         : {{VersionDate}}
 *  @Description     : This document describes the register definition of Intr
 ******************************************************************************
 *  Copyright (C) by Shanghai ChipON Micro-Electronic Co.,Ltd
 *  All rights reserved.
 *
 *  This software is copyright protected and proprietary to
 *  Shanghai ChipON Micro-Electronic Co.,Ltd.
 ******************************************************************************/
/*****************************************************************************
 *                              REVISION HISTORY
 ******************************************************************************
 *  |Date        |Version       |Author          |Description
 ******************************************************************************
 *  |2025-07-03  |v1.0          |AE Group        |New create
 *****************************************************************************/
#ifndef KF32A158SF_REG_INTR_H
#define KF32A158SF_REG_INTR_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 **                     QAC Warnings
 ******************************************************************************/
/* PRQA S 0750 EOF #KQR000750 */

/******************************************************************************
 **                     Include Files
 ******************************************************************************/
#include <stdint.h>
#include <stdbool.h>
#include "kf_types.h"

/******************************************************************************
 *                      Macro
 ******************************************************************************/

/******************************************************************************
 **                     Typedef  Definitions
 ******************************************************************************/

typedef volatile struct
{

    /* Offset:0x0  INTR_CTL0 */
    union
    {
        struct
        {
            __IO uint32_t AIE        :1;
            __IO uint32_t PRIGROUP   :2;
            __I           uint32_t   :1;
            __I uint32_t  INTPENDING :1;
            __I uint32_t  INTPREEMPT :1;
            __IO uint32_t FAULTMASK  :1;
            __IO uint32_t DSALIGN    :1;
            __I           uint32_t   :4;
            __IO uint32_t PRIBASE    :4;
            __I uint32_t  INTPEND    :7;
            __I           uint32_t   :1;
            __I uint32_t  INTACT     :7;
            __I           uint32_t   :1;
        } bits;
        __IO uint32_t reg;
    } CTL0;

    /* Offset:0x4  INTR_EIE0 */
    union
    {
        struct
        {
            __I           uint32_t    :3;
            __IO uint32_t HARDFAULTIE :1;
            __IO          uint32_t    :1;
            __IO uint32_t STACKIE     :1;
            __IO uint32_t ARIFAULTIE  :1;
            __I           uint32_t    :4;
            __IO uint32_t SVCIE       :1;
            __IO          uint32_t    :2;
            __IO uint32_t SOFTSVIE    :1;
            __IO uint32_t SYSTICKIE   :1;
            __I           uint32_t    :16;
        } bits;
        __IO uint32_t reg;
    } EIE0;

    __I uint32_t RESERVED_0x8;

    /* Offset:0xc  INTR_EIE1 */
    union
    {
        struct
        {
            __IO uint32_t WWDTIE             :1;
            __IO uint32_t EINT16IE           :1;
            __IO uint32_t PAIE               :1;
            __IO uint32_t PBIE               :1;
            __IO uint32_t PCIE               :1;
            __IO uint32_t PDIE               :1;
            __IO uint32_t PEIE               :1;
            __IO uint32_t PFIE               :1;
            __IO uint32_t PXIE               :1;
            __IO uint32_t T1IE               :1;
            __IO uint32_t T3IE               :1;
            __IO uint32_t T5IE               :1;
            __IO uint32_t T6IE               :1;
            __IO uint32_t CANFD6_MB_15_0_IE  :1;
            __IO uint32_t CANFD6_MB_31_16_IE :1;
            __IO uint32_t CANFD6_MB_47_32_IE :1;
            __IO uint32_t CANFD6_MB_63_48_IE :1;
            __IO uint32_t T14IE              :1;
            __IO uint32_t RNGIE              :1;
            __IO uint32_t CANFD7_MB_15_0_IE  :1;
            __IO uint32_t CANFD7_MB_31_16_IE :1;
            __IO uint32_t ADC0IE             :1;
            __IO uint32_t ADC1IE             :1;
            __IO uint32_t CANFD6_BUS_IE      :1;
            __IO uint32_t T11IE              :1;
            __IO uint32_t T0IE               :1;
            __IO uint32_t DMA0IE             :1;
            __IO uint32_t CMPIE              :1;
            __IO uint32_t USART0IE           :1;
            __IO uint32_t USART1IE           :1;
            __IO uint32_t SPI0IE             :1;
            __IO uint32_t SPI1IE             :1;
        } bits;
        __IO uint32_t reg;
    } EIE1;

    __I uint32_t RESERVED_0x10;

    /* Offset:0x14  INTR_EIE2 */
    union
    {
        struct
        {
            __IO uint32_t DMA1IE             :1;
            __IO uint32_t EINT19TO17IE       :1;
            __IO uint32_t CANFD6_GEN_IE      :1;
            __IO uint32_t CANFD7_GEN_IE      :1;
            __IO uint32_t CANFD7_MB_47_32_IE :1;
            __IO uint32_t CANFD7_MB_63_48_IE :1;
            __IO uint32_t EINT31TO20IE       :1;
            __IO uint32_t CMUIE              :1;
            __IO uint32_t OSCIE              :1;
            __IO uint32_t I2C0IE             :1;
            __IO uint32_t I2C1IE             :1;
            __IO uint32_t I2C2IE             :1;
            __IO uint32_t T12IE              :1;
            __IO uint32_t T2IE               :1;
            __IO uint32_t T4IE               :1;
            __IO uint32_t T13IE              :1;
            __IO uint32_t USART2IE           :1;
            __IO uint32_t T16IE              :1;
            __IO uint32_t USART6IE           :1;
            __IO uint32_t SPI2IE             :1;
            __IO          uint32_t           :4;
            __IO uint32_t CANFD7_BUS_IE      :1;
            __IO uint32_t WKPIE              :1;
            __IO uint32_t CANFD8_BUS_IE      :1;
            __IO uint32_t T20IE              :1;
            __IO          uint32_t           :4;
        } bits;
        __IO uint32_t reg;
    } EIE2;

    /* Offset:0x18  INTR_EIE3 */
    union
    {
        struct
        {
            __IO uint32_t USART3IE           :1;
            __IO          uint32_t           :1;
            __IO uint32_t SHA_IE             :1;
            __IO uint32_t RSA_IE             :1;
            __IO uint32_t FIRSTK_PROG_IE     :1;
            __IO uint32_t FIRSTK_SERA_IE     :1;
            __IO uint32_t CANFD8_MB_15_0_IE  :1;
            __IO uint32_t CANFD8_MB_31_16_IE :1;
            __IO uint32_t CANFD8_MB_47_32_IE :1;
            __IO uint32_t CANFD8_MB_63_48_IE :1;
            __IO uint32_t CANFD8_GEN_IE      :1;
            __IO uint32_t CANFD9_GEN_IE      :1;
            __IO          uint32_t           :4;
            __IO uint32_t T31IE              :1;
            __IO uint32_t T32IE              :1;
            __IO uint32_t T33IE              :1;
            __IO uint32_t T36IE              :1;
            __IO uint32_t T9IE               :1;
            __IO uint32_t T10IE              :1;
            __IO uint32_t CANFD9_BUS_IE      :1;
            __IO uint32_t TICKTIMER_IE       :1;
            __IO uint32_t T21IE              :1;
            __IO uint32_t A_BUSY_IE          :1;
            __IO uint32_t B_BUSY_IE          :1;
            __IO uint32_t SRAMECCIE          :1;
            __IO uint32_t DRAMECCIE          :1;
            __IO uint32_t CACHEECCIE         :1;
            __IO uint32_t FLASHECCIE         :1;
            __IO uint32_t ISMUIE             :1;
        } bits;
        __IO uint32_t reg;
    } EIE3;

    /* Offset:0x1c  INTR_EIF0 */
    union
    {
        struct
        {
            __I           uint32_t    :2;
            __IO uint32_t NMIIF       :1;
            __IO uint32_t HARDFAULTIF :1;
            __IO          uint32_t    :1;
            __IO uint32_t STACKIF     :1;
            __IO uint32_t ARIFAULTIF  :1;
            __I           uint32_t    :4;
            __IO uint32_t SVCIF       :1;
            __IO          uint32_t    :2;
            __IO uint32_t SOFTSVIF    :1;
            __IO uint32_t SYSTICKIF   :1;
            __I           uint32_t    :16;
        } bits;
        __IO uint32_t reg;
    } EIF0;

    __I uint32_t RESERVED_0x20;

    /* Offset:0x24  INTR_EIF1 */
    union
    {
        struct
        {
            __IO uint32_t WWDTIF             :1;
            __IO uint32_t EINT16IF           :1;
            __IO uint32_t PAIF               :1;
            __IO uint32_t PBIF               :1;
            __IO uint32_t PCIF               :1;
            __IO uint32_t PDIF               :1;
            __IO uint32_t PEIF               :1;
            __IO uint32_t PFIF               :1;
            __IO uint32_t PXIF               :1;
            __IO uint32_t T1IF               :1;
            __IO uint32_t T3IF               :1;
            __IO uint32_t T5IF               :1;
            __IO uint32_t T6IF               :1;
            __IO uint32_t CANFD6_MB_15_0_IF  :1;
            __IO uint32_t CANFD6_MB_31_16_IF :1;
            __IO uint32_t CANFD6_MB_47_32_IF :1;
            __IO uint32_t CANFD6_MB_63_48_IF :1;
            __IO uint32_t T14IF              :1;
            __IO uint32_t RNGIF              :1;
            __IO uint32_t CANFD7_MB_15_0_IF  :1;
            __IO uint32_t CANFD7_MB_31_16_IF :1;
            __IO uint32_t ADC0IF             :1;
            __IO uint32_t ADC1IF             :1;
            __IO uint32_t CANFD6_BUS_IF      :1;
            __IO uint32_t T11IF              :1;
            __IO uint32_t T0IF               :1;
            __IO uint32_t DMA0IF             :1;
            __IO uint32_t CMPIF              :1;
            __IO uint32_t USART0IF           :1;
            __IO uint32_t USART1IF           :1;
            __IO uint32_t SPI0IF             :1;
            __IO uint32_t SPI1IF             :1;
        } bits;
        __IO uint32_t reg;
    } EIF1;

    __I uint32_t RESERVED_0x28;

    /* Offset:0x2c  INTR_EIF2 */
    union
    {
        struct
        {
            __IO uint32_t DMA1IF             :1;
            __IO uint32_t EINT19TO17IF       :1;
            __IO uint32_t CANFD6_GEN_IF      :1;
            __IO uint32_t CANFD7_GEN_IF      :1;
            __IO uint32_t CANFD7_MB_47_32_IF :1;
            __IO uint32_t CANFD7_MB_63_48_IF :1;
            __IO uint32_t EINT31TO20IF       :1;
            __IO uint32_t CMUIE              :1;
            __IO uint32_t OSCIF              :1;
            __IO uint32_t I2C0IF             :1;
            __IO uint32_t I2C1IF             :1;
            __IO uint32_t I2C2IF             :1;
            __IO uint32_t T12IF              :1;
            __IO uint32_t T2IF               :1;
            __IO uint32_t T4IF               :1;
            __IO uint32_t T13IF              :1;
            __IO uint32_t USART2IF           :1;
            __IO uint32_t T16IF              :1;
            __IO uint32_t USART6IF           :1;
            __IO uint32_t SPI2IF             :1;
            __IO          uint32_t           :4;
            __IO uint32_t CANFD7_BUS_IF      :1;
            __IO uint32_t WKPIF              :1;
            __IO uint32_t CANFD8_BUS_IF      :1;
            __IO uint32_t T20IF              :1;
            __IO          uint32_t           :4;
        } bits;
        __IO uint32_t reg;
    } EIF2;

    /* Offset:0x30  INTR_EIF3 */
    union
    {
        struct
        {
            __IO uint32_t USART3IF           :1;
            __IO          uint32_t           :1;
            __IO uint32_t SHA_IF             :1;
            __IO uint32_t RSA_IF             :1;
            __IO uint32_t FIRSTK_PROG_IF     :1;
            __IO uint32_t FIRSTK_SERA_IF     :1;
            __IO uint32_t CANFD8_MB_15_0_IF  :1;
            __IO uint32_t CANFD8_MB_31_16_IF :1;
            __IO uint32_t CANFD8_MB_47_32_IF :1;
            __IO uint32_t CANFD8_MB_63_48_IF :1;
            __IO uint32_t CANFD8_GEN_IF      :1;
            __IO uint32_t CANFD9_GEN_IF      :1;
            __IO          uint32_t           :4;
            __IO uint32_t T31IF              :1;
            __IO uint32_t T32IF              :1;
            __IO uint32_t T33IF              :1;
            __IO uint32_t T36IF              :1;
            __IO uint32_t T9IF               :1;
            __IO uint32_t T10IF              :1;
            __IO uint32_t CANFD9_BUS_IF      :1;
            __IO uint32_t SYSTICK1_IF        :1;
            __IO uint32_t T21IF              :1;
            __IO uint32_t A_BUSY_IF          :1;
            __IO uint32_t B_BUSY_IF          :1;
            __IO uint32_t SRAMECCIF          :1;
            __IO uint32_t DRAMECCIF          :1;
            __IO uint32_t CACHEECCIF         :1;
            __IO uint32_t FLASHECCIF         :1;
            __IO uint32_t ISMUIF             :1;
        } bits;
        __IO uint32_t reg;
    } EIF3;

    /* Offset:0x34  INTR_IP0 */
    union
    {
        struct
        {
            __IO uint32_t PRI4 :8;
            __IO uint32_t PRI5 :8;
            __IO uint32_t PRI6 :8;
            __IO uint32_t PRI7 :8;
        } bits;
        __IO uint32_t reg;
    } IP0;

    /* Offset:0x38  INTR_IP1 */
    union
    {
        struct
        {
            __IO uint32_t PRI8  :8;
            __IO uint32_t PRI9  :8;
            __IO uint32_t PRI10 :8;
            __IO uint32_t PRI11 :8;
        } bits;
        __IO uint32_t reg;
    } IP1;

    /* Offset:0x3c  INTR_IP2 */
    union
    {
        struct
        {
            __IO uint32_t PRI12 :8;
            __IO uint32_t PRI13 :8;
            __IO uint32_t PRI14 :8;
            __IO uint32_t PRI15 :8;
        } bits;
        __IO uint32_t reg;
    } IP2;

    /* Offset:0x40  INTR_IP3 */
    union
    {
        struct
        {
            __IO uint32_t PRI16 :8;
            __IO uint32_t PRI17 :8;
            __IO uint32_t PRI18 :8;
            __IO uint32_t PRI19 :8;
        } bits;
        __IO uint32_t reg;
    } IP3;

    /* Offset:0x44  INTR_IP4 */
    union
    {
        struct
        {
            __IO uint32_t PRI20 :8;
            __IO uint32_t PRI21 :8;
            __IO uint32_t PRI22 :8;
            __IO uint32_t PRI23 :8;
        } bits;
        __IO uint32_t reg;
    } IP4;

    /* Offset:0x48  INTR_IP5 */
    union
    {
        struct
        {
            __IO uint32_t PRI24 :8;
            __IO uint32_t PRI25 :8;
            __IO uint32_t PRI26 :8;
            __IO uint32_t PRI27 :8;
        } bits;
        __IO uint32_t reg;
    } IP5;

    /* Offset:0x4c  INTR_IP6 */
    union
    {
        struct
        {
            __IO uint32_t PRI28 :8;
            __IO uint32_t PRI29 :8;
            __IO uint32_t PRI30 :8;
            __IO uint32_t PRI31 :8;
        } bits;
        __IO uint32_t reg;
    } IP6;

    /* Offset:0x50  INTR_IP7 */
    union
    {
        struct
        {
            __IO uint32_t PRI32 :8;
            __IO uint32_t PRI33 :8;
            __IO uint32_t PRI34 :8;
            __IO uint32_t PRI35 :8;
        } bits;
        __IO uint32_t reg;
    } IP7;

    /* Offset:0x54  INTR_IP8 */
    union
    {
        struct
        {
            __IO uint32_t PRI36 :8;
            __IO uint32_t PRI37 :8;
            __IO uint32_t PRI38 :8;
            __IO uint32_t PRI39 :8;
        } bits;
        __IO uint32_t reg;
    } IP8;

    /* Offset:0x58  INTR_IP9 */
    union
    {
        struct
        {
            __IO uint32_t PRI40 :8;
            __IO uint32_t PRI41 :8;
            __IO uint32_t PRI42 :8;
            __IO uint32_t PRI43 :8;
        } bits;
        __IO uint32_t reg;
    } IP9;

    /* Offset:0x5c  INTR_IP10 */
    union
    {
        struct
        {
            __IO uint32_t PRI44 :8;
            __IO uint32_t PRI45 :8;
            __IO uint32_t PRI46 :8;
            __IO uint32_t PRI47 :8;
        } bits;
        __IO uint32_t reg;
    } IP10;

    /* Offset:0x60  INTR_IP11 */
    union
    {
        struct
        {
            __IO uint32_t PRI48 :8;
            __IO uint32_t PRI49 :8;
            __IO uint32_t PRI50 :8;
            __IO uint32_t PRI51 :8;
        } bits;
        __IO uint32_t reg;
    } IP11;

    /* Offset:0x64  INTR_IP12 */
    union
    {
        struct
        {
            __IO uint32_t PRI52 :8;
            __IO uint32_t PRI53 :8;
            __IO uint32_t PRI54 :8;
            __IO uint32_t PRI55 :8;
        } bits;
        __IO uint32_t reg;
    } IP12;

    /* Offset:0x68  INTR_IP13 */
    union
    {
        struct
        {
            __IO uint32_t PRI56 :8;
            __IO uint32_t PRI57 :8;
            __IO uint32_t PRI58 :8;
            __IO uint32_t PRI59 :8;
        } bits;
        __IO uint32_t reg;
    } IP13;

    /* Offset:0x6c  INTR_IP14 */
    union
    {
        struct
        {
            __IO uint32_t PRI60 :8;
            __IO uint32_t PRI61 :8;
            __IO uint32_t PRI62 :8;
            __IO uint32_t PRI63 :8;
        } bits;
        __IO uint32_t reg;
    } IP14;

    /* Offset:0x70  INTR_IP15 */
    union
    {
        struct
        {
            __IO uint32_t PRI64 :8;
            __IO uint32_t PRI65 :8;
            __IO uint32_t PRI66 :8;
            __IO uint32_t PRI67 :8;
        } bits;
        __IO uint32_t reg;
    } IP15;

    /* Offset:0x74  INTR_IP16 */
    union
    {
        struct
        {
            __IO uint32_t PRI68 :8;
            __IO uint32_t PRI69 :8;
            __IO uint32_t PRI70 :8;
            __IO uint32_t PRI71 :8;
        } bits;
        __IO uint32_t reg;
    } IP16;

    /* Offset:0x78  INTR_IP17 */
    union
    {
        struct
        {
            __IO uint32_t PRI72 :8;
            __IO uint32_t PRI73 :8;
            __IO uint32_t PRI74 :8;
            __IO uint32_t PRI75 :8;
        } bits;
        __IO uint32_t reg;
    } IP17;

    /* Offset:0x7c  INTR_IP18 */
    union
    {
        struct
        {
            __IO uint32_t PRI76 :8;
            __IO uint32_t PRI77 :8;
            __IO uint32_t PRI78 :8;
            __IO uint32_t PRI79 :8;
        } bits;
        __IO uint32_t reg;
    } IP18;

    /* Offset:0x80  INTR_EINTMASK */
    union
    {
        struct
        {
            __I           uint32_t :16;
            __IO uint32_t EINTM    :16;
        } bits;
        __IO uint32_t reg;
    } EINTMASK;

    /* Offset:0x84  INTR_EINTRISE */
    union
    {
        struct
        {
            __I           uint32_t :16;
            __IO uint32_t EINTRI   :16;
        } bits;
        __IO uint32_t reg;
    } EINTRISE;

    /* Offset:0x88  INTR_EINTFALL */
    union
    {
        struct
        {
            __I           uint32_t :16;
            __IO uint32_t EINTFA   :16;
        } bits;
        __IO uint32_t reg;
    } EINTFALL;

    /* Offset:0x8C  INTR_EINTF */
    union
    {
        struct
        {
            __I           uint32_t :16;
            __IO uint32_t EINTIF   :16;
        } bits;
        __IO uint32_t reg;
    } EINTF;

    /* Offset:0x90  INTR_EINTEL */
    union
    {
        struct
        {
            __I           uint32_t :16;
            __IO uint32_t EINTEL   :16;
        } bits;
        __IO uint32_t reg;
    } EINTEL;

    __I uint32_t RESERVED_0x94[2];

    /* Offset:0x9c  INTR_CTL1 */
    union
    {
        struct
        {
            __IO uint32_t INTDELY  :8;
            __I           uint32_t :24;
        } bits;
        __IO uint32_t reg;
    } CTL1;

    __I uint32_t RESERVED_0xa0[16];

    /* Offset:0xe0  INTR_IP19 */
    union
    {
        struct
        {
            __IO uint32_t PRI80 :8;
            __IO uint32_t PRI81 :8;
            __IO uint32_t PRI82 :8;
            __IO uint32_t PRI83 :8;
        } bits;
        __IO uint32_t reg;
    } IP19;

    /* Offset:0xe4  INTR_IP20 */
    union
    {
        struct
        {
            __IO uint32_t PRI84 :8;
            __IO uint32_t PRI85 :8;
            __IO uint32_t PRI86 :8;
            __IO uint32_t PRI87 :8;
        } bits;
        __IO uint32_t reg;
    } IP20;

    /* Offset:0xe8  INTR_IP21 */
    union
    {
        struct
        {
            __IO uint32_t PRI88 :8;
            __IO uint32_t PRI89 :8;
            __IO uint32_t PRI90 :8;
            __IO uint32_t PRI91 :8;
        } bits;
        __IO uint32_t reg;
    } IP21;

    /* Offset:0xec  INTR_IP22 */
    union
    {
        struct
        {
            __IO uint32_t PRI92 :8;
            __IO uint32_t PRI93 :8;
            __IO uint32_t PRI94 :8;
            __IO uint32_t PRI95 :8;
        } bits;
        __IO uint32_t reg;
    } IP22;

    /* Offset:0xf0  INTR_IP23 */
    union
    {
        struct
        {
            __IO uint32_t PRI96 :8;
            __IO uint32_t PRI97 :8;
            __IO uint32_t PRI98 :8;
            __IO uint32_t PRI99 :8;
        } bits;
        __IO uint32_t reg;
    } IP23;

    /* Offset:0xf4  INTR_IP24 */
    union
    {
        struct
        {
            __IO uint32_t PRI100 :8;
            __IO uint32_t PRI101 :8;
            __IO uint32_t PRI102 :8;
            __IO uint32_t PRI103 :8;
        } bits;
        __IO uint32_t reg;
    } IP24;

    /* Offset:0xf8  INTR_IP25 */
    union
    {
        struct
        {
            __IO uint32_t PRI104 :8;
            __IO uint32_t PRI105 :8;
            __IO uint32_t PRI106 :8;
            __IO uint32_t PRI107 :8;
        } bits;
        __IO uint32_t reg;
    } IP25;

    /* Offset:0xfc  INTR_IP26 */
    union
    {
        struct
        {
            __IO uint32_t PRI108 :8;
            __IO uint32_t PRI109 :8;
            __IO uint32_t PRI110 :8;
            __IO uint32_t PRI111 :8;
        } bits;
        __IO uint32_t reg;
    } IP26;

    __I uint32_t RESERVED_0x100[128];

    /* Offset:0x300  INTR_EIE4 */
    union
    {
        struct
        {
            __IO uint32_t CANFD9_MB_15_0_IE  :1;
            __IO uint32_t CANFD9_MB_31_16_IE :1;
            __IO uint32_t CANFD9_MB_47_32_IE :1;
            __IO uint32_t CANFD9_MB_63_48_IE :1;
            __IO          uint32_t           :1;
            __IO uint32_t AESIE              :1;
            __IO uint32_t BUSERRIE           :1;
            __I           uint32_t           :25;
        } bits;
        __IO uint32_t reg;
    } EIE4;

    /* Offset:0x304  INTR_EIF4 */
    union
    {
        struct
        {
            __IO uint32_t CANFD9_MB_15_0_IF  :1;
            __IO uint32_t CANFD9_MB_31_16_IF :1;
            __IO uint32_t CANFD9_MB_47_32_IF :1;
            __IO uint32_t CANFD9_MB_63_48_IF :1;
            __IO          uint32_t           :1;
            __IO uint32_t AESIF              :1;
            __IO uint32_t BUSERRIF           :1;
            __I           uint32_t           :25;
        } bits;
        __IO uint32_t reg;
    } EIF4;

    /* Offset:0x308  INTR_IP27 */
    union
    {
        struct
        {
            __IO uint32_t PRI112 :8;
            __IO uint32_t PRI113 :8;
            __IO uint32_t PRI114 :8;
            __IO uint32_t PRI115 :8;
        } bits;
        __IO uint32_t reg;
    } IP27;

    /* Offset:0x30c  INTR_IP28 */
    union
    {
        struct
        {
            __IO uint32_t PRI116 :8;
            __IO uint32_t PRI117 :8;
            __IO uint32_t PRI118 :8;
            __IO uint32_t PRI119 :8;
        } bits;
        __IO uint32_t reg;
    } IP28;

    /* Offset:0x310  INTR_IP29 */
    union
    {
        struct
        {
            __IO uint32_t PRI120 :8;
            __IO uint32_t PRI121 :8;
            __IO uint32_t PRI122 :8;
            __IO uint32_t PRI123 :8;
        } bits;
        __IO uint32_t reg;
    } IP29;

    /* Offset:0x314  INTR_IP30 */
    union
    {
        struct
        {
            __IO uint32_t PRI124 :8;
            __IO uint32_t PRI125 :8;
            __IO uint32_t PRI126 :8;
            __IO uint32_t PRI127 :8;
        } bits;
        __IO uint32_t reg;
    } IP30;

} Intr_RegisterMap_t;

/**
 * @brief Address of Intr register
 */
#define INTR_ADDR ((uint32_t)0x40200000U)

/**
 * @brief Pointer to Intr register
 */
#define INTR_PTR ((Intr_RegisterMap_t *)INTR_ADDR)

/**
 * @brief Register map of Intr
 */
#define INTR_RM (*(INTR_PTR))

/**
 * @brief Module check assertion
 */
#define CHECK_INTR_ALL_PERIPH_ADDR(Module) (((uint32_t)(Module) == (uint32_t)(INTR_PTR)))

/******************************************************************************
 *                      Export Variables
 ******************************************************************************/

/******************************************************************************
 *                      Export Functions
 ******************************************************************************/
#ifdef LLD_TEST_INJECTION
#include "kf32_reg_test.h"
#endif
#ifdef __cplusplus
}
#endif /*End of __cplusplus*/
#endif /*End of KF32A158SF_INTR_REG_H*/
/* EOF */
