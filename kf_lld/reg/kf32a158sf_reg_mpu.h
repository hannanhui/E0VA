/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a158sf_reg_mpu.h
 *  @Date            : 2025-07-03
 *  @Version         : {{VersionDate}}
 *  @Description     : This document describes the register definition of Mpu
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
#ifndef KF32A158SF_REG_MPU_H
#define KF32A158SF_REG_MPU_H

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

    /* Offset:0x0  MPU_CTLESR */
    union
    {
        struct
        {
            __IO uint32_t MPUEN    :1;
            __I           uint32_t :7;
            __I uint32_t  NRGD     :4;
            __I uint32_t  NSP      :4;
            __I uint32_t  HREV     :4;
            __I uint32_t  SPERIF0  :1;
            __I uint32_t  SPERIF1  :1;
            __I uint32_t  SPERIF2  :1;
            __I uint32_t  SPERIF3  :1;
            __I           uint32_t :8;
        } bits;
        __IO uint32_t reg;
    } CTLESR;

    /* Offset:0x4  MPU_IER */
    union
    {
        struct
        {
            __I           uint32_t :16;
            __IO uint32_t SPERIC0  :1;
            __IO uint32_t SPERIC1  :1;
            __IO uint32_t SPERIC2  :1;
            __IO uint32_t SPERIC3  :1;
            __I           uint32_t :12;
        } bits;
        __IO uint32_t reg;
    } IER;

    /* Offset:0x8  MPU_RESERVED */
    __I uint32_t RESERVED_0x1[2];

    /* Offset:0x10  MPU_ERRARS0 */
    __I uint32_t ERRARS0;

    /* Offset:0x14  MPU_ERRDRS0 */
    union
    {
        struct
        {
            __I uint32_t ERRRW  :1;
            __I uint32_t ERRATR :3;
            __I uint32_t ERRMNU :4;
            __I uint32_t ERRPID :8;
            __I uint32_t ERRACD :16;
        } bits;
        __IO uint32_t reg;
    } ERRDRS0;

    /* Offset:0x18  MPU_ERRARS1 */
    __I uint32_t ERRARS1;

    /* Offset:0x1c  MPU_ERRDRS1 */
    union
    {
        struct
        {
            __I uint32_t ERRRW  :1;
            __I uint32_t ERRATR :3;
            __I uint32_t ERRMNU :4;
            __I uint32_t ERRPID :8;
            __I uint32_t ERRACD :16;
        } bits;
        __IO uint32_t reg;
    } ERRDRS1;

    /* Offset:0x20  MPU_ERRARS2 */
    __I uint32_t ERRARS2;

    /* Offset:0x24  MPU_ERRDRS2 */
    union
    {
        struct
        {
            __I uint32_t ERRRW  :1;
            __I uint32_t ERRATR :3;
            __I uint32_t ERRMNU :4;
            __I uint32_t ERRPID :8;
            __I uint32_t ERRACD :16;
        } bits;
        __IO uint32_t reg;
    } ERRDRS2;

    /* Offset:0x28  MPU_ERRARS3 */
    __I uint32_t ERRARS3;

    /* Offset:0x2c  MPU_ERRDRS3 */
    union
    {
        struct
        {
            __I uint32_t ERRRW  :1;
            __I uint32_t ERRATR :3;
            __I uint32_t ERRMNU :4;
            __I uint32_t ERRPID :8;
            __I uint32_t ERRACD :16;
        } bits;
        __IO uint32_t reg;
    } ERRDRS3;

    __I uint32_t RESERVED_0x30[52];

    /* Offset:0x100  MPU_RGDE0W0 */
    union
    {
        struct
        {
            __I           uint32_t :5;
            __IO uint32_t STRADDR  :27;
        } bits;
        __IO uint32_t reg;
    } RGDE0W0;

    /* Offset:0x104  MPU_RGDE0W1 */
    union
    {
        struct
        {
            __I           uint32_t :5;
            __IO uint32_t ENDADDR  :27;
        } bits;
        __IO uint32_t reg;
    } RGDE0W1;

    /* Offset:0x108  MPU_RGDE0W2 */
    union
    {
        struct
        {
            __IO uint32_t M0UMAC   :3;
            __IO uint32_t M0SMAC   :2;
            __IO uint32_t M0PEN    :1;
            __IO uint32_t M1UMAC   :3;
            __IO uint32_t M1SMAC   :2;
            __IO uint32_t M1PEN    :1;
            __IO uint32_t M2UMAC   :3;
            __IO uint32_t M2SMAC   :2;
            __I           uint32_t :15;
        } bits;
        __IO uint32_t reg;
    } RGDE0W2;

    /* Offset:0x10c  MPU_RGDE0W3 */
    union
    {
        struct
        {
            __IO uint32_t RGDEVLD  :1;
            __I           uint32_t :15;
            __IO uint32_t PIDMSK   :8;
            __IO uint32_t PID      :8;
        } bits;
        __IO uint32_t reg;
    } RGDE0W3;

    /* Offset:0x110  MPU_RGDE1W0 */
    union
    {
        struct
        {
            __I           uint32_t :5;
            __IO uint32_t STRADDR  :27;
        } bits;
        __IO uint32_t reg;
    } RGDE1W0;

    /* Offset:0x114  MPU_RGDE1W1 */
    union
    {
        struct
        {
            __I           uint32_t :5;
            __IO uint32_t ENDADDR  :27;
        } bits;
        __IO uint32_t reg;
    } RGDE1W1;

    /* Offset:0x118  MPU_RGDE1W2 */
    union
    {
        struct
        {
            __IO uint32_t M0UMAC   :3;
            __IO uint32_t M0SMAC   :2;
            __IO uint32_t M0PEN    :1;
            __IO uint32_t M1UMAC   :3;
            __IO uint32_t M1SMAC   :2;
            __IO uint32_t M1PEN    :1;
            __IO uint32_t M2UMAC   :3;
            __IO uint32_t M2SMAC   :2;
            __I           uint32_t :15;
        } bits;
        __IO uint32_t reg;
    } RGDE1W2;

    /* Offset:0x11c  MPU_RGDE1W3 */
    union
    {
        struct
        {
            __IO uint32_t RGDEVLD  :1;
            __I           uint32_t :15;
            __IO uint32_t PIDMSK   :8;
            __IO uint32_t PID      :8;
        } bits;
        __IO uint32_t reg;
    } RGDE1W3;

    /* Offset:0x120  MPU_RGDE2W0 */
    union
    {
        struct
        {
            __I           uint32_t :5;
            __IO uint32_t STRADDR  :27;
        } bits;
        __IO uint32_t reg;
    } RGDE2W0;

    /* Offset:0x124  MPU_RGDE2W1 */
    union
    {
        struct
        {
            __I           uint32_t :5;
            __IO uint32_t ENDADDR  :27;
        } bits;
        __IO uint32_t reg;
    } RGDE2W1;

    /* Offset:0x128  MPU_RGDE2W2 */
    union
    {
        struct
        {
            __IO uint32_t M0UMAC   :3;
            __IO uint32_t M0SMAC   :2;
            __IO uint32_t M0PEN    :1;
            __IO uint32_t M1UMAC   :3;
            __IO uint32_t M1SMAC   :2;
            __IO uint32_t M1PEN    :1;
            __IO uint32_t M2UMAC   :3;
            __IO uint32_t M2SMAC   :2;
            __I           uint32_t :15;
        } bits;
        __IO uint32_t reg;
    } RGDE2W2;

    /* Offset:0x12c  MPU_RGDE2W3 */
    union
    {
        struct
        {
            __IO uint32_t RGDEVLD  :1;
            __I           uint32_t :15;
            __IO uint32_t PIDMSK   :8;
            __IO uint32_t PID      :8;
        } bits;
        __IO uint32_t reg;
    } RGDE2W3;

    /* Offset:0x130  MPU_RGDE3W0 */
    union
    {
        struct
        {
            __I           uint32_t :5;
            __IO uint32_t STRADDR  :27;
        } bits;
        __IO uint32_t reg;
    } RGDE3W0;

    /* Offset:0x134  MPU_RGDE3W1 */
    union
    {
        struct
        {
            __I           uint32_t :5;
            __IO uint32_t ENDADDR  :27;
        } bits;
        __IO uint32_t reg;
    } RGDE3W1;

    /* Offset:0x138  MPU_RGDE3W2 */
    union
    {
        struct
        {
            __IO uint32_t M0UMAC   :3;
            __IO uint32_t M0SMAC   :2;
            __IO uint32_t M0PEN    :1;
            __IO uint32_t M1UMAC   :3;
            __IO uint32_t M1SMAC   :2;
            __IO uint32_t M1PEN    :1;
            __IO uint32_t M2UMAC   :3;
            __IO uint32_t M2SMAC   :2;
            __I           uint32_t :15;
        } bits;
        __IO uint32_t reg;
    } RGDE3W2;

    /* Offset:0x13c  MPU_RGDE3W3 */
    union
    {
        struct
        {
            __IO uint32_t RGDEVLD  :1;
            __I           uint32_t :15;
            __IO uint32_t PIDMSK   :8;
            __IO uint32_t PID      :8;
        } bits;
        __IO uint32_t reg;
    } RGDE3W3;

    /* Offset:0x140  MPU_RGDE4W0 */
    union
    {
        struct
        {
            __I           uint32_t :5;
            __IO uint32_t STRADDR  :27;
        } bits;
        __IO uint32_t reg;
    } RGDE4W0;

    /* Offset:0x144  MPU_RGDE4W1 */
    union
    {
        struct
        {
            __I           uint32_t :5;
            __IO uint32_t ENDADDR  :27;
        } bits;
        __IO uint32_t reg;
    } RGDE4W1;

    /* Offset:0x148  MPU_RGDE4W2 */
    union
    {
        struct
        {
            __IO uint32_t M0UMAC   :3;
            __IO uint32_t M0SMAC   :2;
            __IO uint32_t M0PEN    :1;
            __IO uint32_t M1UMAC   :3;
            __IO uint32_t M1SMAC   :2;
            __IO uint32_t M1PEN    :1;
            __IO uint32_t M2UMAC   :3;
            __IO uint32_t M2SMAC   :2;
            __I           uint32_t :15;
        } bits;
        __IO uint32_t reg;
    } RGDE4W2;

    /* Offset:0x14c  MPU_RGDE4W3 */
    union
    {
        struct
        {
            __IO uint32_t RGDEVLD  :1;
            __I           uint32_t :15;
            __IO uint32_t PIDMSK   :8;
            __IO uint32_t PID      :8;
        } bits;
        __IO uint32_t reg;
    } RGDE4W3;

    /* Offset:0x150  MPU_RGDE5W0 */
    union
    {
        struct
        {
            __I           uint32_t :5;
            __IO uint32_t STRADDR  :27;
        } bits;
        __IO uint32_t reg;
    } RGDE5W0;

    /* Offset:0x154  MPU_RGDE5W1 */
    union
    {
        struct
        {
            __I           uint32_t :5;
            __IO uint32_t ENDADDR  :27;
        } bits;
        __IO uint32_t reg;
    } RGDE5W1;

    /* Offset:0x158  MPU_RGDE5W2 */
    union
    {
        struct
        {
            __IO uint32_t M0UMAC   :3;
            __IO uint32_t M0SMAC   :2;
            __IO uint32_t M0PEN    :1;
            __IO uint32_t M1UMAC   :3;
            __IO uint32_t M1SMAC   :2;
            __IO uint32_t M1PEN    :1;
            __IO uint32_t M2UMAC   :3;
            __IO uint32_t M2SMAC   :2;
            __I           uint32_t :15;
        } bits;
        __IO uint32_t reg;
    } RGDE5W2;

    /* Offset:0x15c  MPU_RGDE5W3 */
    union
    {
        struct
        {
            __IO uint32_t RGDEVLD  :1;
            __I           uint32_t :15;
            __IO uint32_t PIDMSK   :8;
            __IO uint32_t PID      :8;
        } bits;
        __IO uint32_t reg;
    } RGDE5W3;

    /* Offset:0x160  MPU_RGDE6W0 */
    union
    {
        struct
        {
            __I           uint32_t :5;
            __IO uint32_t STRADDR  :27;
        } bits;
        __IO uint32_t reg;
    } RGDE6W0;

    /* Offset:0x164  MPU_RGDE6W1 */
    union
    {
        struct
        {
            __I           uint32_t :5;
            __IO uint32_t ENDADDR  :27;
        } bits;
        __IO uint32_t reg;
    } RGDE6W1;

    /* Offset:0x168  MPU_RGDE6W2 */
    union
    {
        struct
        {
            __IO uint32_t M0UMAC   :3;
            __IO uint32_t M0SMAC   :2;
            __IO uint32_t M0PEN    :1;
            __IO uint32_t M1UMAC   :3;
            __IO uint32_t M1SMAC   :2;
            __IO uint32_t M1PEN    :1;
            __IO uint32_t M2UMAC   :3;
            __IO uint32_t M2SMAC   :2;
            __I           uint32_t :15;
        } bits;
        __IO uint32_t reg;
    } RGDE6W2;

    /* Offset:0x16c  MPU_RGDE6W3 */
    union
    {
        struct
        {
            __IO uint32_t RGDEVLD  :1;
            __I           uint32_t :15;
            __IO uint32_t PIDMSK   :8;
            __IO uint32_t PID      :8;
        } bits;
        __IO uint32_t reg;
    } RGDE6W3;

    /* Offset:0x170  MPU_RGDE7W0 */
    union
    {
        struct
        {
            __I           uint32_t :5;
            __IO uint32_t STRADDR  :27;
        } bits;
        __IO uint32_t reg;
    } RGDE7W0;

    /* Offset:0x174  MPU_RGDE7W1 */
    union
    {
        struct
        {
            __I           uint32_t :5;
            __IO uint32_t ENDADDR  :27;
        } bits;
        __IO uint32_t reg;
    } RGDE7W1;

    /* Offset:0x178  MPU_RGDE7W2 */
    union
    {
        struct
        {
            __IO uint32_t M0UMAC   :3;
            __IO uint32_t M0SMAC   :2;
            __IO uint32_t M0PEN    :1;
            __IO uint32_t M1UMAC   :3;
            __IO uint32_t M1SMAC   :2;
            __IO uint32_t M1PEN    :1;
            __IO uint32_t M2UMAC   :3;
            __IO uint32_t M2SMAC   :2;
            __I           uint32_t :15;
        } bits;
        __IO uint32_t reg;
    } RGDE7W2;

    /* Offset:0x17c  MPU_RGDE7W3 */
    union
    {
        struct
        {
            __IO uint32_t RGDEVLD  :1;
            __I           uint32_t :15;
            __IO uint32_t PIDMSK   :8;
            __IO uint32_t PID      :8;
        } bits;
        __IO uint32_t reg;
    } RGDE7W3;

    /* Offset:0x180  MPU_RGDE8W0 */
    union
    {
        struct
        {
            __I           uint32_t :5;
            __IO uint32_t STRADDR  :27;
        } bits;
        __IO uint32_t reg;
    } RGDE8W0;

    /* Offset:0x184  MPU_RGDE8W1 */
    union
    {
        struct
        {
            __I           uint32_t :5;
            __IO uint32_t ENDADDR  :27;
        } bits;
        __IO uint32_t reg;
    } RGDE8W1;

    /* Offset:0x188  MPU_RGDE8W2 */
    union
    {
        struct
        {
            __IO uint32_t M0UMAC   :3;
            __IO uint32_t M0SMAC   :2;
            __IO uint32_t M0PEN    :1;
            __IO uint32_t M1UMAC   :3;
            __IO uint32_t M1SMAC   :2;
            __IO uint32_t M1PEN    :1;
            __IO uint32_t M2UMAC   :3;
            __IO uint32_t M2SMAC   :2;
            __I           uint32_t :15;
        } bits;
        __IO uint32_t reg;
    } RGDE8W2;

    /* Offset:0x18c  MPU_RGDE8W3 */
    union
    {
        struct
        {
            __IO uint32_t RGDEVLD  :1;
            __I           uint32_t :15;
            __IO uint32_t PIDMSK   :8;
            __IO uint32_t PID      :8;
        } bits;
        __IO uint32_t reg;
    } RGDE8W3;

    /* Offset:0x190  MPU_RGDE9W0 */
    union
    {
        struct
        {
            __I           uint32_t :5;
            __IO uint32_t STRADDR  :27;
        } bits;
        __IO uint32_t reg;
    } RGDE9W0;

    /* Offset:0x194  MPU_RGDE9W1 */
    union
    {
        struct
        {
            __I           uint32_t :5;
            __IO uint32_t ENDADDR  :27;
        } bits;
        __IO uint32_t reg;
    } RGDE9W1;

    /* Offset:0x198  MPU_RGDE9W2 */
    union
    {
        struct
        {
            __IO uint32_t M0UMAC   :3;
            __IO uint32_t M0SMAC   :2;
            __IO uint32_t M0PEN    :1;
            __IO uint32_t M1UMAC   :3;
            __IO uint32_t M1SMAC   :2;
            __IO uint32_t M1PEN    :1;
            __IO uint32_t M2UMAC   :3;
            __IO uint32_t M2SMAC   :2;
            __I           uint32_t :15;
        } bits;
        __IO uint32_t reg;
    } RGDE9W2;

    /* Offset:0x19c  MPU_RGDE9W3 */
    union
    {
        struct
        {
            __IO uint32_t RGDEVLD  :1;
            __I           uint32_t :15;
            __IO uint32_t PIDMSK   :8;
            __IO uint32_t PID      :8;
        } bits;
        __IO uint32_t reg;
    } RGDE9W3;

    /* Offset:0x1a0  MPU_RGDE10W0 */
    union
    {
        struct
        {
            __I           uint32_t :5;
            __IO uint32_t STRADDR  :27;
        } bits;
        __IO uint32_t reg;
    } RGDE10W0;

    /* Offset:0x1a4  MPU_RGDE10W1 */
    union
    {
        struct
        {
            __I           uint32_t :5;
            __IO uint32_t ENDADDR  :27;
        } bits;
        __IO uint32_t reg;
    } RGDE10W1;

    /* Offset:0x1a8  MPU_RGDE10W2 */
    union
    {
        struct
        {
            __IO uint32_t M0UMAC   :3;
            __IO uint32_t M0SMAC   :2;
            __IO uint32_t M0PEN    :1;
            __IO uint32_t M1UMAC   :3;
            __IO uint32_t M1SMAC   :2;
            __IO uint32_t M1PEN    :1;
            __IO uint32_t M2UMAC   :3;
            __IO uint32_t M2SMAC   :2;
            __I           uint32_t :15;
        } bits;
        __IO uint32_t reg;
    } RGDE10W2;

    /* Offset:0x1ac  MPU_RGDE10W3 */
    union
    {
        struct
        {
            __IO uint32_t RGDEVLD  :1;
            __I           uint32_t :15;
            __IO uint32_t PIDMSK   :8;
            __IO uint32_t PID      :8;
        } bits;
        __IO uint32_t reg;
    } RGDE10W3;

    /* Offset:0x1b0  MPU_RGDE11W0 */
    union
    {
        struct
        {
            __I           uint32_t :5;
            __IO uint32_t STRADDR  :27;
        } bits;
        __IO uint32_t reg;
    } RGDE11W0;

    /* Offset:0x1b4  MPU_RGDE11W1 */
    union
    {
        struct
        {
            __I           uint32_t :5;
            __IO uint32_t ENDADDR  :27;
        } bits;
        __IO uint32_t reg;
    } RGDE11W1;

    /* Offset:0x1b8  MPU_RGDE11W2 */
    union
    {
        struct
        {
            __IO uint32_t M0UMAC   :3;
            __IO uint32_t M0SMAC   :2;
            __IO uint32_t M0PEN    :1;
            __IO uint32_t M1UMAC   :3;
            __IO uint32_t M1SMAC   :2;
            __IO uint32_t M1PEN    :1;
            __IO uint32_t M2UMAC   :3;
            __IO uint32_t M2SMAC   :2;
            __I           uint32_t :15;
        } bits;
        __IO uint32_t reg;
    } RGDE11W2;

    /* Offset:0x1bc  MPU_RGDE11W3 */
    union
    {
        struct
        {
            __IO uint32_t RGDEVLD  :1;
            __I           uint32_t :15;
            __IO uint32_t PIDMSK   :8;
            __IO uint32_t PID      :8;
        } bits;
        __IO uint32_t reg;
    } RGDE11W3;

    /* Offset:0x1c0  MPU_RGDE12W0 */
    union
    {
        struct
        {
            __I           uint32_t :5;
            __IO uint32_t STRADDR  :27;
        } bits;
        __IO uint32_t reg;
    } RGDE12W0;

    /* Offset:0x1c4  MPU_RGDE12W1 */
    union
    {
        struct
        {
            __I           uint32_t :5;
            __IO uint32_t ENDADDR  :27;
        } bits;
        __IO uint32_t reg;
    } RGDE12W1;

    /* Offset:0x1c8  MPU_RGDE12W2 */
    union
    {
        struct
        {
            __IO uint32_t M0UMAC   :3;
            __IO uint32_t M0SMAC   :2;
            __IO uint32_t M0PEN    :1;
            __IO uint32_t M1UMAC   :3;
            __IO uint32_t M1SMAC   :2;
            __IO uint32_t M1PEN    :1;
            __IO uint32_t M2UMAC   :3;
            __IO uint32_t M2SMAC   :2;
            __I           uint32_t :15;
        } bits;
        __IO uint32_t reg;
    } RGDE12W2;

    /* Offset:0x1cc  MPU_RGDE12W3 */
    union
    {
        struct
        {
            __IO uint32_t RGDEVLD  :1;
            __I           uint32_t :15;
            __IO uint32_t PIDMSK   :8;
            __IO uint32_t PID      :8;
        } bits;
        __IO uint32_t reg;
    } RGDE12W3;

    /* Offset:0x1d0  MPU_RGDE13W0 */
    union
    {
        struct
        {
            __I           uint32_t :5;
            __IO uint32_t STRADDR  :27;
        } bits;
        __IO uint32_t reg;
    } RGDE13W0;

    /* Offset:0x1d4  MPU_RGDE13W1 */
    union
    {
        struct
        {
            __I           uint32_t :5;
            __IO uint32_t ENDADDR  :27;
        } bits;
        __IO uint32_t reg;
    } RGDE13W1;

    /* Offset:0x1d8  MPU_RGDE13W2 */
    union
    {
        struct
        {
            __IO uint32_t M0UMAC   :3;
            __IO uint32_t M0SMAC   :2;
            __IO uint32_t M0PEN    :1;
            __IO uint32_t M1UMAC   :3;
            __IO uint32_t M1SMAC   :2;
            __IO uint32_t M1PEN    :1;
            __IO uint32_t M2UMAC   :3;
            __IO uint32_t M2SMAC   :2;
            __I           uint32_t :15;
        } bits;
        __IO uint32_t reg;
    } RGDE13W2;

    /* Offset:0x1dc  MPU_RGDE13W3 */
    union
    {
        struct
        {
            __IO uint32_t RGDEVLD  :1;
            __I           uint32_t :15;
            __IO uint32_t PIDMSK   :8;
            __IO uint32_t PID      :8;
        } bits;
        __IO uint32_t reg;
    } RGDE13W3;

    /* Offset:0x1e0  MPU_RGDE14W0 */
    union
    {
        struct
        {
            __I           uint32_t :5;
            __IO uint32_t STRADDR  :27;
        } bits;
        __IO uint32_t reg;
    } RGDE14W0;

    /* Offset:0x1e4  MPU_RGDE14W1 */
    union
    {
        struct
        {
            __I           uint32_t :5;
            __IO uint32_t ENDADDR  :27;
        } bits;
        __IO uint32_t reg;
    } RGDE14W1;

    /* Offset:0x1e8  MPU_RGDE14W2 */
    union
    {
        struct
        {
            __IO uint32_t M0UMAC   :3;
            __IO uint32_t M0SMAC   :2;
            __IO uint32_t M0PEN    :1;
            __IO uint32_t M1UMAC   :3;
            __IO uint32_t M1SMAC   :2;
            __IO uint32_t M1PEN    :1;
            __IO uint32_t M2UMAC   :3;
            __IO uint32_t M2SMAC   :2;
            __I           uint32_t :15;
        } bits;
        __IO uint32_t reg;
    } RGDE14W2;

    /* Offset:0x1ec  MPU_RGDE14W3 */
    union
    {
        struct
        {
            __IO uint32_t RGDEVLD  :1;
            __I           uint32_t :15;
            __IO uint32_t PIDMSK   :8;
            __IO uint32_t PID      :8;
        } bits;
        __IO uint32_t reg;
    } RGDE14W3;

    /* Offset:0x1f0  MPU_RGDE15W0 */
    union
    {
        struct
        {
            __I           uint32_t :5;
            __IO uint32_t STRADDR  :27;
        } bits;
        __IO uint32_t reg;
    } RGDE15W0;

    /* Offset:0x1f4  MPU_RGDE15W1 */
    union
    {
        struct
        {
            __I           uint32_t :5;
            __IO uint32_t ENDADDR  :27;
        } bits;
        __IO uint32_t reg;
    } RGDE15W1;

    /* Offset:0x1f8  MPU_RGDE15W2 */
    union
    {
        struct
        {
            __IO uint32_t M0UMAC   :3;
            __IO uint32_t M0SMAC   :2;
            __IO uint32_t M0PEN    :1;
            __IO uint32_t M1UMAC   :3;
            __IO uint32_t M1SMAC   :2;
            __IO uint32_t M1PEN    :1;
            __IO uint32_t M2UMAC   :3;
            __IO uint32_t M2SMAC   :2;
            __I           uint32_t :15;
        } bits;
        __IO uint32_t reg;
    } RGDE15W2;

    /* Offset:0x1fc  MPU_RGDE15W3 */
    union
    {
        struct
        {
            __IO uint32_t RGDEVLD  :1;
            __I           uint32_t :15;
            __IO uint32_t PIDMSK   :8;
            __IO uint32_t PID      :8;
        } bits;
        __IO uint32_t reg;
    } RGDE15W3;

    __I uint32_t RESERVED_0x200[64];

    /* Offset:0x300  MPU_RGDEACC0 */
    union
    {
        struct
        {
            __IO uint32_t M0UMAC   :3;
            __IO uint32_t M0SMAC   :2;
            __IO uint32_t M0PEN    :1;
            __IO uint32_t M1UMAC   :3;
            __IO uint32_t M1SMAC   :2;
            __IO uint32_t M1PEN    :1;
            __IO uint32_t M2UMAC   :3;
            __IO uint32_t M2SMAC   :2;
            __I           uint32_t :15;
        } bits;
        __IO uint32_t reg;
    } RGDEACC0;

    /* Offset:0x304  MPU_RGDEACC1 */
    union
    {
        struct
        {
            __IO uint32_t M0UMAC   :3;
            __IO uint32_t M0SMAC   :2;
            __IO uint32_t M0PEN    :1;
            __IO uint32_t M1UMAC   :3;
            __IO uint32_t M1SMAC   :2;
            __IO uint32_t M1PEN    :1;
            __IO uint32_t M2UMAC   :3;
            __IO uint32_t M2SMAC   :2;
            __I           uint32_t :15;
        } bits;
        __IO uint32_t reg;
    } RGDEACC1;

    /* Offset:0x308  MPU_RGDEACC2 */
    union
    {
        struct
        {
            __IO uint32_t M0UMAC   :3;
            __IO uint32_t M0SMAC   :2;
            __IO uint32_t M0PEN    :1;
            __IO uint32_t M1UMAC   :3;
            __IO uint32_t M1SMAC   :2;
            __IO uint32_t M1PEN    :1;
            __IO uint32_t M2UMAC   :3;
            __IO uint32_t M2SMAC   :2;
            __I           uint32_t :15;
        } bits;
        __IO uint32_t reg;
    } RGDEACC2;

    /* Offset:0x30c  MPU_RGDEACC3 */
    union
    {
        struct
        {
            __IO uint32_t M0UMAC   :3;
            __IO uint32_t M0SMAC   :2;
            __IO uint32_t M0PEN    :1;
            __IO uint32_t M1UMAC   :3;
            __IO uint32_t M1SMAC   :2;
            __IO uint32_t M1PEN    :1;
            __IO uint32_t M2UMAC   :3;
            __IO uint32_t M2SMAC   :2;
            __I           uint32_t :15;
        } bits;
        __IO uint32_t reg;
    } RGDEACC3;

    /* Offset:0x310  MPU_RGDEACC4 */
    union
    {
        struct
        {
            __IO uint32_t M0UMAC   :3;
            __IO uint32_t M0SMAC   :2;
            __IO uint32_t M0PEN    :1;
            __IO uint32_t M1UMAC   :3;
            __IO uint32_t M1SMAC   :2;
            __IO uint32_t M1PEN    :1;
            __IO uint32_t M2UMAC   :3;
            __IO uint32_t M2SMAC   :2;
            __I           uint32_t :15;
        } bits;
        __IO uint32_t reg;
    } RGDEACC4;

    /* Offset:0x314  MPU_RGDEACC5 */
    union
    {
        struct
        {
            __IO uint32_t M0UMAC   :3;
            __IO uint32_t M0SMAC   :2;
            __IO uint32_t M0PEN    :1;
            __IO uint32_t M1UMAC   :3;
            __IO uint32_t M1SMAC   :2;
            __IO uint32_t M1PEN    :1;
            __IO uint32_t M2UMAC   :3;
            __IO uint32_t M2SMAC   :2;
            __I           uint32_t :15;
        } bits;
        __IO uint32_t reg;
    } RGDEACC5;

    /* Offset:0x318  MPU_RGDEACC6 */
    union
    {
        struct
        {
            __IO uint32_t M0UMAC   :3;
            __IO uint32_t M0SMAC   :2;
            __IO uint32_t M0PEN    :1;
            __IO uint32_t M1UMAC   :3;
            __IO uint32_t M1SMAC   :2;
            __IO uint32_t M1PEN    :1;
            __IO uint32_t M2UMAC   :3;
            __IO uint32_t M2SMAC   :2;
            __I           uint32_t :15;
        } bits;
        __IO uint32_t reg;
    } RGDEACC6;

    /* Offset:0x31c  MPU_RGDEACC7 */
    union
    {
        struct
        {
            __IO uint32_t M0UMAC   :3;
            __IO uint32_t M0SMAC   :2;
            __IO uint32_t M0PEN    :1;
            __IO uint32_t M1UMAC   :3;
            __IO uint32_t M1SMAC   :2;
            __IO uint32_t M1PEN    :1;
            __IO uint32_t M2UMAC   :3;
            __IO uint32_t M2SMAC   :2;
            __I           uint32_t :15;
        } bits;
        __IO uint32_t reg;
    } RGDEACC7;

    /* Offset:0x320  MPU_RGDEACC8 */
    union
    {
        struct
        {
            __IO uint32_t M0UMAC   :3;
            __IO uint32_t M0SMAC   :2;
            __IO uint32_t M0PEN    :1;
            __IO uint32_t M1UMAC   :3;
            __IO uint32_t M1SMAC   :2;
            __IO uint32_t M1PEN    :1;
            __IO uint32_t M2UMAC   :3;
            __IO uint32_t M2SMAC   :2;
            __I           uint32_t :15;
        } bits;
        __IO uint32_t reg;
    } RGDEACC8;

    /* Offset:0x324  MPU_RGDEACC9 */
    union
    {
        struct
        {
            __IO uint32_t M0UMAC   :3;
            __IO uint32_t M0SMAC   :2;
            __IO uint32_t M0PEN    :1;
            __IO uint32_t M1UMAC   :3;
            __IO uint32_t M1SMAC   :2;
            __IO uint32_t M1PEN    :1;
            __IO uint32_t M2UMAC   :3;
            __IO uint32_t M2SMAC   :2;
            __I           uint32_t :15;
        } bits;
        __IO uint32_t reg;
    } RGDEACC9;

    /* Offset:0x328  MPU_RGDEACC10 */
    union
    {
        struct
        {
            __IO uint32_t M0UMAC   :3;
            __IO uint32_t M0SMAC   :2;
            __IO uint32_t M0PEN    :1;
            __IO uint32_t M1UMAC   :3;
            __IO uint32_t M1SMAC   :2;
            __IO uint32_t M1PEN    :1;
            __IO uint32_t M2UMAC   :3;
            __IO uint32_t M2SMAC   :2;
            __I           uint32_t :15;
        } bits;
        __IO uint32_t reg;
    } RGDEACC10;

    /* Offset:0x32c  MPU_RGDEACC11 */
    union
    {
        struct
        {
            __IO uint32_t M0UMAC   :3;
            __IO uint32_t M0SMAC   :2;
            __IO uint32_t M0PEN    :1;
            __IO uint32_t M1UMAC   :3;
            __IO uint32_t M1SMAC   :2;
            __IO uint32_t M1PEN    :1;
            __IO uint32_t M2UMAC   :3;
            __IO uint32_t M2SMAC   :2;
            __I           uint32_t :15;
        } bits;
        __IO uint32_t reg;
    } RGDEACC11;

    /* Offset:0x330  MPU_RGDEACC12 */
    union
    {
        struct
        {
            __IO uint32_t M0UMAC   :3;
            __IO uint32_t M0SMAC   :2;
            __IO uint32_t M0PEN    :1;
            __IO uint32_t M1UMAC   :3;
            __IO uint32_t M1SMAC   :2;
            __IO uint32_t M1PEN    :1;
            __IO uint32_t M2UMAC   :3;
            __IO uint32_t M2SMAC   :2;
            __I           uint32_t :15;
        } bits;
        __IO uint32_t reg;
    } RGDEACC12;

    /* Offset:0x334  MPU_RGDEACC13 */
    union
    {
        struct
        {
            __IO uint32_t M0UMAC   :3;
            __IO uint32_t M0SMAC   :2;
            __IO uint32_t M0PEN    :1;
            __IO uint32_t M1UMAC   :3;
            __IO uint32_t M1SMAC   :2;
            __IO uint32_t M1PEN    :1;
            __IO uint32_t M2UMAC   :3;
            __IO uint32_t M2SMAC   :2;
            __I           uint32_t :15;
        } bits;
        __IO uint32_t reg;
    } RGDEACC13;

    /* Offset:0x338  MPU_RGDEACC14 */
    union
    {
        struct
        {
            __IO uint32_t M0UMAC   :3;
            __IO uint32_t M0SMAC   :2;
            __IO uint32_t M0PEN    :1;
            __IO uint32_t M1UMAC   :3;
            __IO uint32_t M1SMAC   :2;
            __IO uint32_t M1PEN    :1;
            __IO uint32_t M2UMAC   :3;
            __IO uint32_t M2SMAC   :2;
            __I           uint32_t :15;
        } bits;
        __IO uint32_t reg;
    } RGDEACC14;

    /* Offset:0x33c  MPU_RGDEACC15 */
    union
    {
        struct
        {
            __IO uint32_t M0UMAC   :3;
            __IO uint32_t M0SMAC   :2;
            __IO uint32_t M0PEN    :1;
            __IO uint32_t M1UMAC   :3;
            __IO uint32_t M1SMAC   :2;
            __IO uint32_t M1PEN    :1;
            __IO uint32_t M2UMAC   :3;
            __IO uint32_t M2SMAC   :2;
            __I           uint32_t :15;
        } bits;
        __IO uint32_t reg;
    } RGDEACC15;

} Mpu_RegisterMap_t;

/**
 * @brief Address of Mpu register
 */
#define MPU_ADDR ((uint32_t)0x40005a00U)

/**
 * @brief Pointer to Mpu register
 */
#define MPU_PTR ((Mpu_RegisterMap_t *)MPU_ADDR)

/**
 * @brief Register map of Mpu
 */
#define MPU_RM (*(MPU_PTR))

/**
 * @brief Module check assertion
 */
#define CHECK_MPU_ALL_PERIPH_ADDR(Module) (((uint32_t)(Module) == (uint32_t)(MPU_PTR)))

typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t CPID :8; /*!< CPID of MPU (for processing number comparisons) */
            /*bit offset 8*/
            __I uint32_t :24;
        } bits;
        __IO uint32_t reg;
    } IDR;
} Mpu_IDR_RegisterMap_t;
#define MPU_IDR_ADDR ((uint32_t)0x40004608)
#define MPU_IDR_PTR  ((Mpu_IDR_RegisterMap_t *)MPU_IDR_ADDR)
#define MPU_IDR_RM   (*(Mpu_IDR_RegisterMap_t *)MPU_IDR_ADDR)

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
#endif /*End of KF32A158SF_MPU_REG_H*/
/* EOF */
