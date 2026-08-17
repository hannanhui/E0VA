/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a158sf_reg_gtimer.h
 *  @Date            : 2025-07-03
 *  @Version         : {{VersionDate}}
 *  @Description     : This document describes the register definition of Gtimer
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
#ifndef KF32A158SF_REG_GTIMER_H
#define KF32A158SF_REG_GTIMER_H

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
    /* offset: 0x00 CNT */
    union
    {
        struct
        {
            __IO uint32_t TXCNT    :16;
            __I           uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } CNT;
    /* offset: 0x04 CTL1 */
    union
    {
        struct
        {
            __IO uint32_t TXEN     :1;
            __IO uint32_t TXCS     :1;
            __I           uint32_t :1;
            __IO uint32_t TXSY     :1;
            __I           uint32_t :1;
            __IO uint32_t TXCLK    :2;
            __I uint32_t  TXDIR    :1;
            __IO uint32_t TXCMS    :3;
            __I           uint32_t :1;
            __IO uint32_t TXIE     :1;
            __I uint32_t  TXIF     :1;
            __IO uint32_t READTEN  :1;
            __I           uint32_t :17;
        } bits;
        __IO uint32_t reg;
    } CTL1;
    /* offset: 0x08 CTL2 */
    union
    {
        struct
        {
            __IO uint32_t TXUDEN   :1;
            __IO uint32_t TXUDEVT  :1;
            __IO uint32_t TXMMS    :3;
            __IO uint32_t TXSMS    :3;
            __IO uint32_t TXTS     :4;
            __IO uint32_t TXMSSYNC :1;
            __IO uint32_t TXUR     :1;
            __IO uint32_t TRGSEL   :2;
            __I           uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } CTL2;
    /* offset: 0x0C PRSC */
    union
    {
        struct
        {
            __IO uint32_t TXCKS    :16;
            __I           uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } PRSC;
    /* offset: 0x10 PPX */
    union
    {
        struct
        {
            __IO uint32_t PPX      :16;
            __I           uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } PPX;
    /* offset: 0x14 UDTIM */
    union
    {
        struct
        {
            __IO uint32_t TXUD      :8;
            __IO uint32_t TRGPOL    :1;
            __IO uint32_t CAPDEDEN1 :1;
            __IO uint32_t CAPDEDEN2 :1;
            __IO uint32_t CAPDEDEN3 :1;
            __IO uint32_t CAPDEDEN4 :1;
            __I           uint32_t  :19;
        } bits;
        __IO uint32_t reg;
    } UDTIM;
    /* Offset: 0x18 */
    __I uint32_t RESERVED_0x18;
    /* Offset: 0x1C */
    union
    {
        struct
        {
            __IO uint32_t TXCNT    :16;
            __I           uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } CNT2;
    /* Offset: 0x20 CCP_C1 */
    union
    {
        struct
        {
            __I uint32_t CCPXCY   :16;
            __I          uint32_t :16;
        } bits;
        __I uint32_t reg;
    } CCP_C1;
    /* Offset: 0x24 CCP_C2 */
    union
    {
        struct
        {
            __I uint32_t CCPXCY   :16;
            __I          uint32_t :16;
        } bits;
        __I uint32_t reg;
    } CCP_C2;
    /* Offset: 0x28 CCP_C3 */
    union
    {
        struct
        {
            __I uint32_t CCPXCY   :16;
            __I          uint32_t :16;
        } bits;
        __I uint32_t reg;
    } CCP_C3;
    /* Offset: 0x2C CCP_C4 */
    union
    {
        struct
        {
            __I uint32_t CCPXCY   :16;
            __I          uint32_t :16;
        } bits;
        __I uint32_t reg;
    } CCP_C4;
    /* Offset: 0x30 CCP_SRIC */
    union
    {
        struct
        {
            __IO uint32_t CC1IC    :1;
            __IO uint32_t CC2IC    :1;
            __IO uint32_t CC3IC    :1;
            __IO uint32_t CC4IC    :1;
            __IO uint32_t TXTIC    :1;
            __IO uint32_t TXUIC    :1;
            __IO uint32_t TXIC     :1;
            __IO          uint32_t :25;
        } bits;
        __IO uint32_t reg;
    } CCP_SRIC;
    /* Offset: 0x34 CCP CCP_DF */
    union
    {
        struct
        {
            __I uint32_t CC1DF    :1;
            __I uint32_t CC2DF    :1;
            __I uint32_t CC3DF    :1;
            __I uint32_t CC4DF    :1;
            __I uint32_t TXTDF    :1;
            __I uint32_t TXUDF    :1;
            __I          uint32_t :26;
        } bits;
        __I uint32_t reg;
    } CCP_DF;
    /* Offset: 0x38 CCP CCP_CTL4 */
    union
    {
        struct
        {
            __IO uint32_t CH_SEL1  :2;
            __IO uint32_t CH_SEL2  :2;
            __IO uint32_t PXPWMI1  :1;
            __IO uint32_t CCPXCH4  :1;
            __I           uint32_t :26;
        } bits;
        __I uint32_t reg;
    } CCP_CTL4;
    /* Offset: 0x3C */
    __I uint32_t RESERVED_0x3C;
    /* Offset: 0x40 CCP_CTL1 */
    union
    {
        struct
        {
            __IO uint32_t CH1M     :4;
            __IO uint32_t CH2M     :4;
            __IO uint32_t CH3M     :4;
            __IO uint32_t CH4M     :4;
            __IO          uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } CCP_CTL1;
    /* Offset: 0x44 CCP_R1 */
    union
    {
        struct
        {
            __IO uint32_t CCPXRY   :16;
            __IO          uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } CCP_R1;
    /* Offset: 0x48 CCP_R2 */
    union
    {
        struct
        {
            __IO uint32_t CCPXRY   :16;
            __IO          uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } CCP_R2;
    /* Offset: 0x4C CCP_R3 */
    union
    {
        struct
        {
            __IO uint32_t CCPXRY   :16;
            __IO          uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } CCP_R3;
    /* Offset: 0x50 CCP_R4 */
    union
    {
        struct
        {
            __IO uint32_t CCPXRY   :16;
            __IO          uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } CCP_R4;
    /* Offset: 0x54 CCP_CTL2 */
    union
    {
        struct
        {
            __IO uint32_t PXOC1    :2;
            __IO uint32_t PXOC2    :2;
            __IO uint32_t PXOC3    :2;
            __IO uint32_t PXOC4    :2;
            __IO uint32_t TCKSEL   :2;
            __IO uint32_t PXASS    :2;
            __IO uint32_t PXOC1CE  :1;
            __IO uint32_t PXOC2CE  :1;
            __IO uint32_t PXOC3CE  :1;
            __IO uint32_t PXOC4CE  :1;
            __IO          uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } CCP_CTL2;
    /* Offset: 0x58 CCP_CTL3 */
    union
    {
        struct
        {
            __IO uint32_t CC1IE    :1;
            __IO uint32_t CC2IE    :1;
            __IO uint32_t CC3IE    :1;
            __IO uint32_t CC4IE    :1;
            __IO uint32_t TXTIE    :1;
            __IO uint32_t TXUIE    :1;
            __IO uint32_t TXUDE    :1;
            __IO uint32_t CC1DE    :1;
            __IO uint32_t CC2DE    :1;
            __IO uint32_t CC3DE    :1;
            __IO uint32_t CC4DE    :1;
            __IO uint32_t TXTDE    :1;
            __IO uint32_t PXSPM    :1;
            __IO uint32_t PXXORM   :1;
            __IO uint32_t PXPWMI   :1;
            __IO uint32_t PXSPMST  :1;
            __IO          uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } CCP_CTL3;
    /* Offset: 0x5C CCP_EGIF */
    union
    {
        struct
        {
            __IO uint32_t USARTRXEN :1;
            __IO uint32_t CC1G      :1;
            __IO uint32_t CC2G      :1;
            __IO uint32_t CC3G      :1;
            __IO uint32_t CC4G      :1;
            __IO uint32_t TXTRG     :1;
            __I uint32_t  CC1IF     :1;
            __I uint32_t  CC2IF     :1;
            __I uint32_t  CC3IF     :1;
            __I uint32_t  CC4IF     :1;
            __I uint32_t  TXTIF     :1;
            __I uint32_t  TXUIF     :1;
            __IO uint32_t PXSEL     :1;
            __IO uint32_t POSSEL    :1;
            __IO          uint32_t  :18;
        } bits;
        __IO uint32_t reg;
    } CCP_EGIF;
} GeneralTimer_RegisterMap_t;

/**
 * @brief Address of GeneralTimer register
 */
#define T0_ADDR  ((uint32_t)0x40000880U)
#define T1_ADDR  ((uint32_t)0x40000100U)
#define T2_ADDR  ((uint32_t)0x40000180U)
#define T3_ADDR  ((uint32_t)0x40000200U)
#define T4_ADDR  ((uint32_t)0x40000280U)
#define T20_ADDR ((uint32_t)0x40001b80U)
#define T21_ADDR ((uint32_t)0x40001c00U)

/**
 * @brief Pointer to GeneralTimer register
 */
#define T0_PTR  ((GeneralTimer_RegisterMap_t *)T0_ADDR)
#define T1_PTR  ((GeneralTimer_RegisterMap_t *)T1_ADDR)
#define T2_PTR  ((GeneralTimer_RegisterMap_t *)T2_ADDR)
#define T3_PTR  ((GeneralTimer_RegisterMap_t *)T3_ADDR)
#define T4_PTR  ((GeneralTimer_RegisterMap_t *)T4_ADDR)
#define T20_PTR ((GeneralTimer_RegisterMap_t *)T20_ADDR)
#define T21_PTR ((GeneralTimer_RegisterMap_t *)T21_ADDR)

/**
 * @brief Register map of GeneralTimer
 */
#define T0_RM  (*(T0_PTR))
#define T1_RM  (*(T1_PTR))
#define T2_RM  (*(T2_PTR))
#define T3_RM  (*(T3_PTR))
#define T4_RM  (*(T4_PTR))
#define T20_RM (*(T20_PTR))
#define T21_RM (*(T21_PTR))

/**
 * @brief Module check assertion
 */
#define CHECK_GPTIM_ALL_PERIPH_ADDR(Module)                                                                            \
    (((uint32_t)(Module) == (uint32_t)(T0_PTR)) || ((uint32_t)(Module) == (uint32_t)(T1_PTR)) ||                       \
     ((uint32_t)(Module) == (uint32_t)(T2_PTR)) || ((uint32_t)(Module) == (uint32_t)(T3_PTR)) ||                       \
     ((uint32_t)(Module) == (uint32_t)(T4_PTR)) || ((uint32_t)(Module) == (uint32_t)(T20_PTR)) ||                      \
     ((uint32_t)(Module) == (uint32_t)(T21_PTR)))

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
#endif /*End of KF32A158SF_GTIMER_REG_H*/
/* EOF */
