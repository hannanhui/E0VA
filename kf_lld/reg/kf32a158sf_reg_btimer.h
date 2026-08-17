/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a158sf_reg_btimer.h
 *  @Date            : 2025-07-03
 *  @Version         : {{VersionDate}}
 *  @Description     : This document describes the register definition of Btimer
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
#ifndef KF32A158SF_REG_BTIMER_H
#define KF32A158SF_REG_BTIMER_H

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

    /* Offset:0x0  Btimer_CNT */
    union
    {
        struct
        {
            __IO uint32_t TXCNT    :16;
            __I           uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } CNT;

    /* Offset:0x4  Btimer_CTL1 */
    union
    {
        struct
        {
            __IO uint32_t TXEN     :1;
            __IO uint32_t TXCS     :1;
            __IO uint32_t TXSY     :1;
            __IO uint32_t TXCLK    :2;
            __I uint32_t  TXDIR    :1;
            __IO uint32_t TXCMS    :3;
            __IO uint32_t TRGSEL   :2;
            __IO uint32_t TCKSEL   :2;
            __IO uint32_t READTEN  :1;
            __I           uint32_t :18;
        } bits;
        __IO uint32_t reg;
    } CTL1;

    /* Offset:0x8  Btimer_CTL2 */
    union
    {
        struct
        {
            __IO uint32_t TXUDEN   :1;
            __IO uint32_t TXUDEVT  :1;
            __IO uint32_t TXMMS    :2;
            __IO uint32_t TXSMS    :3;
            __IO uint32_t TXTS     :4;
            __IO uint32_t TXMSSYNC :1;
            __IO uint32_t TXUR     :1;
            __IO uint32_t PXSPMST  :1;
            __IO uint32_t PXSPM    :1;
            __IO uint32_t TXTRG    :1;
            __I           uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } CTL2;

    /* Offset:0xc  Btimer_PRSC */
    union
    {
        struct
        {
            __IO uint32_t TXCKS    :16;
            __I           uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } PRSC;

    /* Offset:0x10  Btimer_PPX */
    union
    {
        struct
        {
            __IO uint32_t PPX      :16;
            __I           uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } PPX;

    /* Offset:0x14  Btimer_DIER */
    union
    {
        struct
        {
            __IO uint32_t TXUIE    :1;
            __IO uint32_t TXTIE    :1;
            __IO uint32_t TXIE     :1;
            __IO uint32_t TXUDE    :1;
            __IO uint32_t TXTDE    :1;
            __I           uint32_t :27;
        } bits;
        __IO uint32_t reg;
    } DIER;

    /* Offset:0x18  Btimer_SR */
    union
    {
        struct
        {
            __I uint32_t TXUIF    :1;
            __I uint32_t TXTIF    :1;
            __I uint32_t TXIF     :1;
            __I uint32_t TXTDF    :1;
            __I uint32_t TXUDF    :1;
            __I          uint32_t :27;
        } bits;
        __IO uint32_t reg;
    } SR;

    /* Offset:0x1c  Btimer_SRIC */
    union
    {
        struct
        {
            __IO uint32_t TXUIC    :1;
            __IO uint32_t TXTIC    :1;
            __IO uint32_t TXIC     :1;
            __I           uint32_t :29;
        } bits;
        __IO uint32_t reg;
    } SRIC;

} Btimer_RegisterMap_t;

/**
 * @brief Address of T register
 */
#define T14_ADDR ((uint32_t)0x40001800U)

/**
 * @brief Pointer to T register
 */
#define T14_PTR ((Btimer_RegisterMap_t *)T14_ADDR)

/**
 * @brief Register map of T
 */
#define T14_RM (*(T14_PTR))

/**
 * @brief Module check assertion
 */
#define CHECK_BTIM_ALL_PERIPH_ADDR(Module) (((uint32_t)(Module) == (uint32_t)(T14_PTR)))

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
#endif /*End of KF32A158SF_BTIMER_REG_H*/
/* EOF */
