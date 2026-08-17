/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a158sf_reg_epwm.h
 *  @Date            : 2025-07-03
 *  @Version         : {{VersionDate}}
 *  @Description     : This document describes the register definition of Epwm
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
#ifndef KF32A158SF_REG_EPWM_H
#define KF32A158SF_REG_EPWM_H

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

    /* Offset:0x0  EPWM_CNT */
    __IO uint32_t CNT;

    /* Offset:0x4  EPWM_PHS */
    __IO uint32_t PHS;

    /* Offset:0x8  EPWM_PPX */
    __IO uint32_t PPX;

    /* Offset:0xc  EPWM_PRSC */
    __IO uint32_t PRSC;

    /* Offset:0x10  EPWM_CTL */
    union
    {
        struct
        {
            __IO uint32_t TXEN     :1;
            __IO uint32_t TXCS     :1;
            __IO uint32_t TXGATE   :1;
            __IO uint32_t TXSY     :1;
            __IO uint32_t TXCLK    :2;
            __I uint32_t  TXDIR    :1;
            __IO uint32_t TXCMS    :3;
            __IO uint32_t TXUDEN   :1;
            __IO uint32_t TXUDEVT  :1;
            __IO uint32_t TXUR     :1;
            __IO uint32_t SYNCI    :1;
            __IO uint32_t PHSEN    :1;
            __IO uint32_t SYNCOSEL :2;
            __IO uint32_t SWFSYNC  :1;
            __IO uint32_t PHSDIR   :1;
            __IO uint32_t TXMAX    :1;
            __IO          uint32_t :1;
            __IO uint32_t CAPSEL   :1;
            __IO uint32_t CAPEN    :1;
            __IO uint32_t AQLOCKA  :1;
            __IO uint32_t AQLOCKB  :1;
            __IO uint32_t DBLOCK   :1;
            __IO uint32_t PCLOCK   :1;
            __IO uint32_t ETLOCK   :1;
            __IO          uint32_t :1;
            __IO uint32_t UDSYNEN  :1;
            __IO uint32_t LINKEN   :1;
            __IO uint32_t BLINKEN  :1;
        } bits;
        __IO uint32_t reg;
    } CTL;

    /* Offset:0x14  EPWM_RA */
    __IO uint32_t RA;

    /* Offset:0x18  EPWM_RB */
    __IO uint32_t RB;

    /* Offset:0x1c  EPWM_CTLA */
    union
    {
        struct
        {
            __IO uint32_t AZRO     :2;
            __IO uint32_t APRD     :2;
            __IO uint32_t ACAU     :2;
            __IO uint32_t ACAD     :2;
            __IO uint32_t ACBU     :2;
            __IO uint32_t ACBD     :2;
            __IO uint32_t CSFA     :2;
            __IO uint32_t ACTSFA   :2;
            __IO uint32_t OTSFA    :1;
            __I           uint32_t :15;
        } bits;
        __IO uint32_t reg;
    } CTLA;

    /* Offset:0x20  EPWM_CTLB */
    union
    {
        struct
        {
            __IO uint32_t BZRO     :2;
            __IO uint32_t BPRD     :2;
            __IO uint32_t BCAU     :2;
            __IO uint32_t BCAD     :2;
            __IO uint32_t BCBU     :2;
            __IO uint32_t BCBD     :2;
            __IO uint32_t CSFB     :2;
            __IO uint32_t ACTSFB   :2;
            __IO uint32_t OTSFB    :1;
            __I           uint32_t :15;
        } bits;
        __IO uint32_t reg;
    } CTLB;

    /* Offset:0x24  EPWM_DBCTL */
    union
    {
        struct
        {
            __IO uint32_t OUTMODE  :2;
            __IO uint32_t POLSEL   :2;
            __IO uint32_t INMODE   :2;
            __I           uint32_t :26;
        } bits;
        __IO uint32_t reg;
    } DBCTL;

    /* Offset:0x28  EPWM_DBT */
    union
    {
        struct
        {
            __IO uint32_t FDBT :16;
            __IO uint32_t RDBT :16;
        } bits;
        __IO uint32_t reg;
    } DBT;

    /* Offset:0x2c  EPWM_PCCTL */
    union
    {
        struct
        {
            __IO uint32_t CHPEN    :1;
            __IO uint32_t OSHTWTH  :4;
            __IO uint32_t CHPDUTY  :3;
            __IO uint32_t CHPFREQ  :3;
            __I           uint32_t :21;
        } bits;
        __IO uint32_t reg;
    } PCCTL;

    /* Offset:0x30  EPWM_PXASCTL */
    union
    {
        struct
        {
            __IO uint32_t PXASS    :4;
            __IO uint32_t PXSSB    :2;
            __IO uint32_t PXSSA    :2;
            __IO uint32_t PXRSEN   :1;
            __IO uint32_t PXASE    :1;
            __IO uint32_t PXAVNEG  :1;
            __I           uint32_t :21;
        } bits;
        __IO uint32_t reg;
    } PXASCTL;

    /* Offset:0x34  EPWM_ETCTL */
    union
    {
        struct
        {
            __IO uint32_t TOADENA  :1;
            __IO uint32_t SELA     :2;
            __IO uint32_t FRCA     :1;
            __IO uint32_t APP      :2;
            __I uint32_t  AT       :2;
            __IO uint32_t ATSEL    :2;
            __I           uint32_t :6;
            __IO uint32_t TOADENB  :1;
            __IO uint32_t SELB     :2;
            __IO uint32_t FRCB     :1;
            __IO uint32_t BPP      :2;
            __I uint32_t  BT       :2;
            __IO uint32_t BTSEL    :2;
            __I           uint32_t :6;
        } bits;
        __IO uint32_t reg;
    } ETCTL;

    /* Offset:0x38  EPWM_IE */
    union
    {
        struct
        {
            __IO uint32_t TXTIE0   :1;
            __IO uint32_t TXTIE1   :1;
            __IO uint32_t TXGIE    :1;
            __IO uint32_t TXUIE    :1;
            __IO uint32_t TXIE     :1;
            __IO uint32_t TXBIE    :1;
            __IO uint32_t TXAIE    :1;
            __IO uint32_t TXCIE    :1;
            __IO uint32_t TXDIE    :1;
            __I           uint32_t :23;
        } bits;
        __IO uint32_t reg;
    } IE;

    /* Offset:0x3c  EPWM_IF */
    union
    {
        struct
        {
            __I uint32_t TXTIF0   :1;
            __I uint32_t TXTIF1   :1;
            __I uint32_t TXGIF    :1;
            __I uint32_t TXUIF    :1;
            __I uint32_t TXIF     :1;
            __I uint32_t TXBIF    :1;
            __I uint32_t TXAIF    :1;
            __I uint32_t TXCIF    :1;
            __I uint32_t TXDIF    :1;
            __I          uint32_t :23;
        } bits;
        __IO uint32_t reg;
    } IF;

    /* Offset:0x40  EPWM_IC */
    union
    {
        struct
        {
            __IO uint32_t TXTIC0   :1;
            __IO uint32_t TXTIC1   :1;
            __IO uint32_t TXGIC    :1;
            __IO uint32_t TXUIC    :1;
            __IO uint32_t TXIC     :1;
            __IO uint32_t TXBIC    :1;
            __IO uint32_t TXAIC    :1;
            __IO uint32_t TXCIC    :1;
            __IO uint32_t TXDIC    :1;
            __I           uint32_t :23;
        } bits;
        __IO uint32_t reg;
    } IC;

    /* Offset:0x44  EPWM_DE */
    union
    {
        struct
        {
            __IO uint32_t TXTDE0   :1;
            __IO uint32_t TXTDE1   :1;
            __IO uint32_t TXGDE    :1;
            __IO uint32_t TXUDE    :1;
            __IO uint32_t TXDE     :1;
            __IO uint32_t TXBDE    :1;
            __IO uint32_t TXADE    :1;
            __IO uint32_t TXCDE    :1;
            __IO uint32_t TXDDE    :1;
            __I           uint32_t :23;
        } bits;
        __IO uint32_t reg;
    } DE;

    /* Offset:0x48  EPWM_DF */
    union
    {
        struct
        {
            __I uint32_t TXTDF0   :1;
            __I uint32_t TXTDF1   :1;
            __I uint32_t TXGDF    :1;
            __I uint32_t TXUDF    :1;
            __I uint32_t TXDF     :1;
            __I uint32_t TXBDF    :1;
            __I uint32_t TXADF    :1;
            __I uint32_t TXCDF    :1;
            __I uint32_t TXDDF    :1;
            __I          uint32_t :23;
        } bits;
        __IO uint32_t reg;
    } DF;

    __I uint32_t RESERVED_0x4c[3];

    /* Offset:0x58  Epwm_CAP */
    __I uint32_t CAP;

    /* Offset:0x5C  EPWM_RC */
    __IO uint32_t RC;

    /* Offset:0x60  EPWM_RD */
    __IO uint32_t RD;

    /* Offset:0x64  EPWM_UDCTL */
    union
    {
        struct
        {
            __I           uint32_t :27;
            __IO uint32_t GBUDEN   :1;
            __I           uint32_t :4;
        } bits;
        __IO uint32_t reg;
    } UDCTL;

} Epwm_RegisterMap_t;

/**
 * @brief Address of Epwm register
 */
#define EPWM11_ADDR ((uint32_t)0x40000300U)
#define EPWM12_ADDR ((uint32_t)0x40000400U)
#define EPWM13_ADDR ((uint32_t)0x40001000U)
#define EPWM16_ADDR ((uint32_t)0x40003380U)
#define EPWM31_ADDR ((uint32_t)0x40005200U)
#define EPWM32_ADDR ((uint32_t)0x40005300U)
#define EPWM33_ADDR ((uint32_t)0x40005400U)
#define EPWM36_ADDR ((uint32_t)0x40005500U)

/**
 * @brief Pointer to Epwm register
 */
#define EPWM11_PTR ((Epwm_RegisterMap_t *)EPWM11_ADDR)
#define EPWM12_PTR ((Epwm_RegisterMap_t *)EPWM12_ADDR)
#define EPWM13_PTR ((Epwm_RegisterMap_t *)EPWM13_ADDR)
#define EPWM16_PTR ((Epwm_RegisterMap_t *)EPWM16_ADDR)
#define EPWM31_PTR ((Epwm_RegisterMap_t *)EPWM31_ADDR)
#define EPWM32_PTR ((Epwm_RegisterMap_t *)EPWM32_ADDR)
#define EPWM33_PTR ((Epwm_RegisterMap_t *)EPWM33_ADDR)
#define EPWM36_PTR ((Epwm_RegisterMap_t *)EPWM36_ADDR)

/**
 * @brief Register map of Epwm
 */
#define EPWM11_RM (*(EPWM11_PTR))
#define EPWM12_RM (*(EPWM12_PTR))
#define EPWM13_RM (*(EPWM13_PTR))
#define EPWM16_RM (*(EPWM16_PTR))
#define EPWM31_RM (*(EPWM31_PTR))
#define EPWM32_RM (*(EPWM32_PTR))
#define EPWM33_RM (*(EPWM33_PTR))
#define EPWM36_RM (*(EPWM36_PTR))

/**
 * @brief Module check assertion
 */
#define CHECK_EPWM_ALL_PERIPH_ADDR(Module)                                                                             \
    (((uint32_t)(Module) == (uint32_t)(EPWM11_PTR)) || ((uint32_t)(Module) == (uint32_t)(EPWM12_PTR)) ||               \
     ((uint32_t)(Module) == (uint32_t)(EPWM13_PTR)) || ((uint32_t)(Module) == (uint32_t)(EPWM16_PTR)) ||               \
     ((uint32_t)(Module) == (uint32_t)(EPWM31_PTR)) || ((uint32_t)(Module) == (uint32_t)(EPWM32_PTR)) ||               \
     ((uint32_t)(Module) == (uint32_t)(EPWM33_PTR)) || ((uint32_t)(Module) == (uint32_t)(EPWM36_PTR)))

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
#endif /*End of KF32A158SF_REG_EPWM_H*/
/* EOF */
