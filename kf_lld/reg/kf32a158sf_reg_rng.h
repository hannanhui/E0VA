/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a158sf_reg_rng.h
 *  @Date            : 2025-07-03
 *  @Version         : {{VersionDate}}
 *  @Description     : This document describes the register definition of Rng
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
#ifndef KF32A158SF_REG_RNG_H
#define KF32A158SF_REG_RNG_H

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

    /* Offset:0x0  RNG_CTL1 */
    union
    {
        struct
        {
            __IO uint32_t WINDOW_SEL    :2;
            __IO uint32_t DROP_BIT_SEL  :2;
            __IO uint32_t VN_EN         :1;
            __IO uint32_t SEED_SEL      :2;
            __IO uint32_t XOR_CHAIN_SEL :3;
            __IO uint32_t HT_REPCNT_SEL :3;
            __IO uint32_t HT_ADAPT_SEL  :2;
            __IO uint32_t HT_MARK_SEL   :2;
            __I           uint32_t      :15;
        } bits;
        __IO uint32_t reg;
    } CTL1;

    /* Offset:0x4  RNG_ESRCLR */
    union
    {
        struct
        {
            __IO uint32_t DEIC     :1;
            __IO uint32_t DRIC     :1;
            __I           uint32_t :30;
        } bits;
        __IO uint32_t reg;
    } ESRCLR;

    /* Offset:0x8  RNG_CTL2 */
    union
    {
        struct
        {
            __IO uint32_t TRNG_EN  :1;
            __IO uint32_t DRIE     :1;
            __IO uint32_t DEIE     :1;
            __I           uint32_t :29;
        } bits;
        __IO uint32_t reg;
    } CTL2;

    /* Offset:0xc  RNG_ESR */
    union
    {
        struct
        {
            __I uint32_t ERR_FLAG    :1;
            __I uint32_t ERR_INFO    :5;
            __I uint32_t FIFO_R_FLAG :1;
            __I          uint32_t    :25;
        } bits;
        __IO uint32_t reg;
    } ESR;

    __I uint32_t RESERVED_0x10;

    /* Offset:0x14  RNG_ERR1 */
    union
    {
        struct
        {
            __I uint32_t REPCNTS_ERR :11;
            __I          uint32_t    :21;
        } bits;
        __IO uint32_t reg;
    } ERR1;

    /* Offset:0x18  RNG_ERR2 */
    union
    {
        struct
        {
            __I uint32_t ADAPTP_ERR :11;
            __I          uint32_t   :21;
        } bits;
        __IO uint32_t reg;
    } ERR2;

    /* Offset:0x1c  RNG_ERR3 */
    union
    {
        struct
        {
            __I uint32_t MARKOV_ERR :11;
            __I          uint32_t   :21;
        } bits;
        __IO uint32_t reg;
    } ERR3;

    /* Offset:0x20  RNG_RDATA */
    __I uint32_t RDATA;

    /* Offset:0x24  RNG_FIFODEPTH */
    union
    {
        struct
        {
            __I uint32_t FIFO_DEPTH :6;
            __I          uint32_t   :26;
        } bits;
        __IO uint32_t reg;
    } FIFODEPTH;

    /* Offset:0x28  RNG_TESTPIN */
    union
    {
        struct
        {
            __IO uint32_t TESTPIN1    :2;
            __IO uint32_t TESTPIN2    :2;
            __IO uint32_t TESTPIN3    :2;
            __IO uint32_t TESTPIN4    :2;
            __IO uint32_t TESTPIN5    :2;
            __IO uint32_t TESTPIN1_EN :1;
            __IO uint32_t TESTPIN2_EN :1;
            __IO uint32_t TESTPIN3_EN :1;
            __IO uint32_t TESTPIN4_EN :1;
            __IO uint32_t TESTPIN5_EN :1;
            __I           uint32_t    :17;
        } bits;
        __IO uint32_t reg;
    } TESTPIN;

} Rng_RegisterMap_t;

/**
 * @brief Address of Rng register
 */
#define RNG_ADDR ((uint32_t)0x40003200U)

/**
 * @brief Pointer to Rng register
 */
#define RNG_PTR ((Rng_RegisterMap_t *)RNG_ADDR)

/**
 * @brief Register map of Rng
 */
#define RNG_RM (*(RNG_PTR))

/**
 * @brief Module check assertion
 */
#define CHECK_RNG_ALL_PERIPH_ADDR(Module) (((uint32_t)(Module) == (uint32_t)(RNG_PTR)))

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
#endif /*End of KF32A158SF_RNG_REG_H*/
/* EOF */
