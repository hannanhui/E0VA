/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a158sf_reg_adc.h
 *  @Date            : 2025-07-03
 *  @Version         : {{VersionDate}}
 *  @Description     : This document describes the register definition of Adc
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
#ifndef KF32A158SF_REG_ADC_H
#define KF32A158SF_REG_ADC_H

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

    /* Offset:0x0  ADC_CTL0 */
    union
    {
        struct
        {
            __IO uint32_t EN          :1;
            __IO uint32_t CLKS        :2;
            __IO uint32_t LR          :1;
            __I           uint32_t    :3;
            __IO uint32_t DIV_SEL     :1;
            __IO uint32_t ADCCLKS     :4;
            __I           uint32_t    :1;
            __IO uint32_t NDMAEN      :1;
            __IO uint32_t TRIMIBIAS   :1;
            __IO uint32_t BOSSSEL     :1;
            __IO uint32_t BOSSSELCOMP :1;
            __IO uint32_t SCANEN      :1;
            __IO uint32_t CONT        :1;
            __IO uint32_t HPAUTO      :1;
            __IO uint32_t DSEN        :1;
            __IO uint32_t HPDSEN      :1;
            __IO uint32_t HP0DMAEN    :1;
            __IO uint32_t HP1DMAEN    :1;
            __IO uint32_t HP2DMAEN    :1;
            __IO uint32_t HP3DMAEN    :1;
            __IO uint32_t DSNUM       :3;
            __IO uint32_t WDEN        :1;
            __IO uint32_t HPWDEN      :1;
            __IO uint32_t WDSCH       :1;
        } bits;
        __IO uint32_t reg;
    } CTL0;

    /* Offset:0x4  ADC_CTL1 */
    union
    {
        struct
        {
            __IO uint32_t NOVMODEN    :1;
            __I           uint32_t    :1;
            __IO uint32_t START       :1;
            __IO uint32_t HPSTART     :1;
            __IO uint32_t NCH         :7;
            __IO uint32_t EXTEN       :1;
            __IO uint32_t DOUMODCALEN :1;
            __I uint32_t  NOVIF       :1;
            __IO uint32_t NOVIC       :1;
            __IO uint32_t NOVIE       :1;
            __I           uint32_t    :1;
            __IO uint32_t REFSEL      :2;
            __I           uint32_t    :1;
            __IO uint32_t HCH         :7;
            __IO uint32_t HPEXTEN     :1;
            __IO uint32_t DOUMOD      :4;
        } bits;
        __IO uint32_t reg;
    } CTL1;

    /* Offset:0x8  ADC_SCANSQ0 */
    union
    {
        struct
        {
            __IO uint32_t SSQ0 :8;
            __IO uint32_t SSQ1 :8;
            __IO uint32_t SSQ2 :8;
            __IO uint32_t SSQ3 :8;
        } bits;
        __IO uint32_t reg;
    } SCANSQ0;

    /* Offset:0xc  ADC_SCANSQ1 */
    union
    {
        struct
        {
            __IO uint32_t SSQ4 :8;
            __IO uint32_t SSQ5 :8;
            __IO uint32_t SSQ6 :8;
            __IO uint32_t SSQ7 :8;
        } bits;
        __IO uint32_t reg;
    } SCANSQ1;

    /* Offset:0x10  ADC_SCANSQ2 */
    union
    {
        struct
        {
            __IO uint32_t SSQ8  :8;
            __IO uint32_t SSQ9  :8;
            __IO uint32_t SSQ10 :8;
            __IO uint32_t SSQ11 :8;
        } bits;
        __IO uint32_t reg;
    } SCANSQ2;

    /* Offset:0x14  ADC_HSCANSQ */
    union
    {
        struct
        {
            __IO uint32_t HSSQ0 :8;
            __IO uint32_t HSSQ1 :8;
            __IO uint32_t HSSQ2 :8;
            __IO uint32_t HSSQ3 :8;
        } bits;
        __IO uint32_t reg;
    } HSCANSQ;

    /* Offset:0x18  ADC_WDH */
    union
    {
        struct
        {
            __IO uint32_t WDH      :12;
            __I           uint32_t :20;
        } bits;
        __IO uint32_t reg;
    } WDH;

    /* Offset:0x1c  ADC_WDL */
    union
    {
        struct
        {
            __IO uint32_t WDL      :12;
            __I           uint32_t :20;
        } bits;
        __IO uint32_t reg;
    } WDL;

    /* Offset:0x20  ADC_DATA */
    union
    {
        struct
        {
            __I uint32_t DATA     :16;
            __I          uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } DATA;

    /* Offset:0x24  ADC_HPDATA0 */
    union
    {
        struct
        {
            __I uint32_t HPDATA   :16;
            __I          uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } HPDATA0;

    /* Offset:0x28  ADC_HPDATA1 */
    union
    {
        struct
        {
            __I uint32_t HPDATA   :16;
            __I          uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } HPDATA1;

    /* Offset:0x2c  ADC_HPDATA2 */
    union
    {
        struct
        {
            __I uint32_t HPDATA   :16;
            __I          uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } HPDATA2;

    /* Offset:0x30  ADC_HPDATA3 */
    union
    {
        struct
        {
            __I uint32_t HPDATA   :16;
            __I          uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } HPDATA3;

    /* Offset:0x34  ADC_HPDOFF0 */
    union
    {
        struct
        {
            __IO uint32_t HPDOFF   :12;
            __I           uint32_t :20;
        } bits;
        __IO uint32_t reg;
    } HPDOFF0;

    /* Offset:0x38  ADC_HPDOFF1 */
    union
    {
        struct
        {
            __IO uint32_t HPDOFF   :12;
            __I           uint32_t :20;
        } bits;
        __IO uint32_t reg;
    } HPDOFF1;

    /* Offset:0x3c  ADC_HPDOFF2 */
    union
    {
        struct
        {
            __IO uint32_t HPDOFF   :12;
            __I           uint32_t :20;
        } bits;
        __IO uint32_t reg;
    } HPDOFF2;

    /* Offset:0x40  ADC_HPDOFF3 */
    union
    {
        struct
        {
            __IO uint32_t HPDOFF   :12;
            __I           uint32_t :20;
        } bits;
        __IO uint32_t reg;
    } HPDOFF3;

    /* Offset:0x44  ADC_SCANSQ3 */
    union
    {
        struct
        {
            __IO uint32_t SSQ12 :8;
            __IO uint32_t SSQ13 :8;
            __IO uint32_t SSQ14 :8;
            __IO uint32_t SSQ15 :8;
        } bits;
        __IO uint32_t reg;
    } SCANSQ3;

    __I uint32_t RESERVED_0x48[2];

    /* Offset:0x50  ADC_STATE */
    union
    {
        struct
        {
            __I uint32_t  STARTIF        :1;
            __I uint32_t  HPSTARTIF      :1;
            __I uint32_t  ENDIF          :1;
            __I uint32_t  HPENDIF        :1;
            __I uint32_t  WDIF           :1;
            __IO uint32_t ENDIC          :1;
            __IO uint32_t HPENDIC        :1;
            __IO uint32_t WDIC           :1;
            __IO uint32_t ENDIE          :1;
            __IO uint32_t HPENDIE        :1;
            __IO uint32_t WDIE           :1;
            __I uint32_t  EOCIF          :1;
            __IO uint32_t EOCIC          :1;
            __IO uint32_t EOCIE          :1;
            __I uint32_t  STRIG_ERR_IF   :1;
            __IO uint32_t STRIG_ERR_IC   :1;
            __I uint32_t  HPSTRIG_ERR_IF :1;
            __IO uint32_t HPSTRIG_ERR_IC :1;
            __I           uint32_t       :8;
            __IO uint32_t TSSELTOADCIS0  :1;
            __IO uint32_t TRIMIBIASOPA   :1;
            __IO uint32_t TSSELTOADCIS1  :1;
            __IO uint32_t TSSELTOADCIS2  :1;
            __IO uint32_t TRIMERROR      :2;
        } bits;
        __IO uint32_t reg;
    } STATE;

    /* Offset:0x54  ADC_DELAY */
    union
    {
        struct
        {
            __IO uint32_t FDELAY   :6;
            __I           uint32_t :26;
        } bits;
        __IO uint32_t reg;
    } DELAY;

    /* Offset:0x58  ADC_SCANCTL */
    union
    {
        struct
        {
            __IO uint32_t SLEN     :4;
            __IO uint32_t HSLEN    :3;
            __I           uint32_t :1;
            __I uint32_t  NCHNUB   :5;
            __I           uint32_t :3;
            __IO uint32_t WDCH     :7;
            __I           uint32_t :1;
            __IO uint32_t SAMSEL   :4;
            __I           uint32_t :4;
        } bits;
        __IO uint32_t reg;
    } SCANCTL;

    /* Offset:0x5c  ADC_CCR */
    union
    {
        struct
        {
            __IO uint32_t CCR0N    :1;
            __IO uint32_t CCR0H    :1;
            __IO uint32_t CCR1N    :1;
            __IO uint32_t CCR1H    :1;
            __IO uint32_t CCR2N    :1;
            __IO uint32_t CCR2H    :1;
            __IO uint32_t CCR3N    :1;
            __IO uint32_t CCR3H    :1;
            __IO uint32_t CCR4N    :1;
            __IO uint32_t CCR4H    :1;
            __IO uint32_t CCR5N    :1;
            __IO uint32_t CCR5H    :1;
            __IO uint32_t CCR6N    :1;
            __IO uint32_t CCR6H    :1;
            __IO uint32_t CCR7N    :1;
            __IO uint32_t CCR7H    :1;
            __IO uint32_t CCR8N    :1;
            __IO uint32_t CCR8H    :1;
            __I           uint32_t :14;
        } bits;
        __IO uint32_t reg;
    } CCR;

    /* Offset:0x60  ADC_HPDATA4 */
    union
    {
        struct
        {
            __I uint32_t HPDATA   :16;
            __I          uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } HPDATA4;

    /* Offset:0x64  ADC_HPDATA5 */
    union
    {
        struct
        {
            __I uint32_t HPDATA   :16;
            __I          uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } HPDATA5;

    /* Offset:0x68  ADC_HPDOFF4 */
    union
    {
        struct
        {
            __IO uint32_t HPDOFF   :12;
            __I           uint32_t :20;
        } bits;
        __IO uint32_t reg;
    } HPDOFF4;

    /* Offset:0x6c  ADC_HPDOFF5 */
    union
    {
        struct
        {
            __IO uint32_t HPDOFF   :12;
            __I           uint32_t :20;
        } bits;
        __IO uint32_t reg;
    } HPDOFF5;

    /* Offset:0x70  ADC_HSCANSQ1 */
    union
    {
        struct
        {
            __IO uint32_t HSSQ4    :8;
            __IO uint32_t HSSQ5    :8;
            __IO          uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } HSCANSQ1;

    /* Offset:0x74  ADC_CTL2 */
    union
    {
        struct
        {
            __IO uint32_t HP4DMAEN  :1;
            __IO uint32_t HP5DMAEN  :1;
            __IO          uint32_t  :1;
            __IO uint32_t ADCLK_SEL :1;
            __I           uint32_t  :28;
        } bits;
        __IO uint32_t reg;
    } CTL2;

} Adc_RegisterMap_t;

/**
 * @brief Address of Adc register
 */
#define ADC0_ADDR ((uint32_t)0x40000580U)
#define ADC1_ADDR ((uint32_t)0x40000600U)

/**
 * @brief Pointer to Adc register
 */
#define ADC0_PTR ((Adc_RegisterMap_t *)ADC0_ADDR)
#define ADC1_PTR ((Adc_RegisterMap_t *)ADC1_ADDR)

/**
 * @brief Register map of Adc
 */
#define ADC0_RM (*(ADC0_PTR))
#define ADC1_RM (*(ADC1_PTR))

/**
 * @brief Module check assertion
 */
#define CHECK_ADC_ALL_PERIPH_ADDR(Module)                                                                              \
    (((uint32_t)(Module) == (uint32_t)(ADC0_PTR)) || ((uint32_t)(Module) == (uint32_t)(ADC1_PTR)))

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
#endif /*End of KF32A158SF_REG_ADC_H*/
/* EOF */
