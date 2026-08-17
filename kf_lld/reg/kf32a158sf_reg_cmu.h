/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a158sf_reg_cmu.h
 *  @Date            : 2025-07-03
 *  @Version         : {{VersionDate}}
 *  @Description     : This document describes the register definition of Cmu
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
#ifndef KF32A158SF_REG_CMU_H
#define KF32A158SF_REG_CMU_H

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

    /* Offset:0x0  CMU_CTL */
    union
    {
        struct
        {
            __IO uint32_t CMUEN1   :1;
            __IO uint32_t CMUEN2   :1;
            __IO uint32_t CMUEN3   :1;
            __IO uint32_t CMUEN4   :1;
            __IO uint32_t FHHIC1   :1;
            __IO uint32_t FLLIC1   :1;
            __IO uint32_t FHHIC2   :1;
            __IO uint32_t FLLIC2   :1;
            __IO uint32_t FHHIC3   :1;
            __IO uint32_t FLLIC3   :1;
            __IO uint32_t FHHIC4   :1;
            __IO uint32_t FLLIC4   :1;
            __IO uint32_t CH1REFIC :1;
            __IO uint32_t CH2REFIC :1;
            __IO uint32_t CH3REFIC :1;
            __IO uint32_t CH4REFIC :1;
            __I           uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } CTL;

    /* Offset:0x4  CMU_INT */
    union
    {
        struct
        {
            __I uint32_t  FHHIF1   :1;
            __I uint32_t  FLLIF1   :1;
            __I uint32_t  FHHIF2   :1;
            __I uint32_t  FLLIF2   :1;
            __I uint32_t  FHHIF3   :1;
            __I uint32_t  FLLIF3   :1;
            __I uint32_t  FHHIF4   :1;
            __I uint32_t  FLLIF4   :1;
            __IO uint32_t FHHIE1   :1;
            __IO uint32_t FLLIE1   :1;
            __IO uint32_t FHHIE2   :1;
            __IO uint32_t FLLIE2   :1;
            __IO uint32_t FHHIE3   :1;
            __IO uint32_t FLLIE3   :1;
            __IO uint32_t FHHIE4   :1;
            __IO uint32_t FLLIE4   :1;
            __IO uint32_t CH1REFIE :1;
            __IO uint32_t CH2REFIE :1;
            __IO uint32_t CH3REFIE :1;
            __IO uint32_t CH4REFIE :1;
            __I uint32_t  CH1REFIF :1;
            __I uint32_t  CH2REFIF :1;
            __I uint32_t  CH3REFIF :1;
            __I uint32_t  CH4REFIF :1;
            __I           uint32_t :8;
        } bits;
        __IO uint32_t reg;
    } INT;

    /* Offset:0x8  CMU_REFCNT1 */
    union
    {
        struct
        {
            __IO uint32_t REFCNT   :16;
            __I           uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } REFCNT1;

    /* Offset:0xc  CMU_HTC1 */
    union
    {
        struct
        {
            __IO uint32_t HFREF    :24;
            __I           uint32_t :8;
        } bits;
        __IO uint32_t reg;
    } HTC1;

    /* Offset:0x10  CMU_LTC1 */
    union
    {
        struct
        {
            __IO uint32_t LFREF    :24;
            __I           uint32_t :8;
        } bits;
        __IO uint32_t reg;
    } LTC1;

    /* Offset:0x14  CMU_REFCNT2 */
    union
    {
        struct
        {
            __IO uint32_t REFCNT   :16;
            __I           uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } REFCNT2;

    /* Offset:0x18  CMU_HTC2 */
    union
    {
        struct
        {
            __IO uint32_t HFREF    :24;
            __I           uint32_t :8;
        } bits;
        __IO uint32_t reg;
    } HTC2;

    /* Offset:0x1c  CMU_LTC2 */
    union
    {
        struct
        {
            __IO uint32_t LFREF    :24;
            __I           uint32_t :8;
        } bits;
        __IO uint32_t reg;
    } LTC2;

    /* Offset:0x20  CMU_REFCNT3 */
    union
    {
        struct
        {
            __IO uint32_t REFCNT   :16;
            __I           uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } REFCNT3;

    /* Offset:0x24  CMU_HTC3 */
    union
    {
        struct
        {
            __IO uint32_t HFREF    :24;
            __I           uint32_t :8;
        } bits;
        __IO uint32_t reg;
    } HTC3;

    /* Offset:0x28  CMU_LTC3 */
    union
    {
        struct
        {
            __IO uint32_t LFREF    :24;
            __I           uint32_t :8;
        } bits;
        __IO uint32_t reg;
    } LTC3;

    /* Offset:0x2c  CMU_REFCNT4 */
    union
    {
        struct
        {
            __IO uint32_t REFCNT   :16;
            __I           uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } REFCNT4;

    /* Offset:0x30  CMU_HTC4 */
    union
    {
        struct
        {
            __IO uint32_t HFREF    :24;
            __I           uint32_t :8;
        } bits;
        __IO uint32_t reg;
    } HTC4;

    /* Offset:0x34  CMU_LTC4 */
    union
    {
        struct
        {
            __IO uint32_t LFREF    :24;
            __I           uint32_t :8;
        } bits;
        __IO uint32_t reg;
    } LTC4;

    /* Offset:0x38  CMU_INTFLAG */
    union
    {
        struct
        {
            __IO uint32_t CH1INTREF :1;
            __IO uint32_t CH2INTREF :1;
            __IO uint32_t CH3INTREF :1;
            __IO uint32_t CH4INTREF :1;
            __I           uint32_t  :28;
        } bits;
        __IO uint32_t reg;
    } INTFLAG;
} Cmu_RegisterMap_t;

/**
 * @brief Address of Cmu register
 */
#define CMU_ADDR ((uint32_t)0x40003980U)

/**
 * @brief Pointer to Cmu register
 */
#define CMU_PTR ((Cmu_RegisterMap_t *)CMU_ADDR)

/**
 * @brief Register map of Cmu
 */
#define CMU_RM (*(CMU_PTR))

/**
 * @brief Module check assertion
 */
#define CHECK_CMU_ALL_PERIPH_ADDR(Module) (((uint32_t)(Module) == (uint32_t)(CMU_PTR)))

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
#endif /*End of KF32A158SF_REG_CMU_H*/
/* EOF */
