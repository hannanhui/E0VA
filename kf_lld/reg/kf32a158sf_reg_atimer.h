/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a158sf_reg_atimer.h
 *  @Date            : 2025-07-03
 *  @Version         : {{VersionDate}}
 *  @Description     : This document describes the register definition of Atimer
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
#ifndef KF32A158SF_REG_ATIMER_H
#define KF32A158SF_REG_ATIMER_H

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
    /* Offset: 0x00  Tx_CNT */
    union
    {
        struct
        {
            __IO uint32_t TXCNT    :16;
            __I           uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } Tx_CNT;
    /* Offset: 0x04  Tz_CNT */
    union
    {
        struct
        {
            __IO uint32_t TZCNT    :16;
            __I           uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } Tz_CNT;
    /* Offset: 0x08  Tx_PPX */
    union
    {
        struct
        {
            __IO uint32_t PPX      :16;
            __I           uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } Tx_PPX;
    /* Offset: 0x0C   Tz_PPZ */
    union
    {
        struct
        {
            __IO uint32_t PPZ      :16;
            __I           uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } Tz_PPZ;
    /* Offset: 0x10 Tx_PRSC */
    union
    {
        struct
        {
            __IO uint32_t TXCKS    :16;
            __I           uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } Tx_PRSC;
    /* Offset: 0x14  Tz_PRSC */
    union
    {
        struct
        {
            __IO uint32_t TZCKS    :16;
            __I           uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } Tz_PRSC;
    /* Offset: 0x18 Tx_CCR0 */
    union
    {
        struct
        {
            __IO uint32_t TXCCR0   :16;
            __I           uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } Tx_CCR0;
    /* Offset: 0x1C  Tx_CCR1  */
    union
    {
        struct
        {
            __IO uint32_t TXCCR1   :16;
            __I           uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } Tx_CCR1;
    /* Offset: 0x20  Tz_CCR0 */
    union
    {
        struct
        {
            __IO uint32_t TZCCR    :16;
            __I           uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } Tz_CCR0;
    /* Offset: 0x24  Tx_CTL */
    union
    {
        struct
        {
            __IO uint32_t TXCS     :1;
            __IO uint32_t TXSY     :1;
            __IO uint32_t TXEN     :1;
            __IO uint32_t TXCKBS   :4;
            __I uint32_t  TXDIR    :1;
            __IO uint32_t TXCLK    :2;
            __IO uint32_t TXADAUTO :1;
            __IO uint32_t TXOFS0   :1;
            __IO uint32_t TXOFS1   :1;
            __IO uint32_t TXCMS    :3;
            __I           uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } Tx_CTL;
    /* Offset: 0x28  Tz_CTL */
    union
    {
        struct
        {
            __IO uint32_t TZCS     :1;
            __IO uint32_t TZSY     :1;
            __IO uint32_t TZEN     :1;
            __IO uint32_t TZCKBS   :4;
            __I uint32_t  TZDIR    :1;
            __IO uint32_t TZCLK    :2;
            __IO uint32_t TZADAUTO :1;
            __IO uint32_t TZOFS0   :1;
            __IO uint32_t TZOFS1   :1;
            __IO uint32_t TZCMS    :3;
            __I           uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } Tz_CTL;
    /*Offset: 0x2C PDCTL */
    union
    {
        struct
        {
            __IO uint32_t CPE      :2;
            __IO uint32_t CMPE     :1;
            __IO uint32_t TI0EN    :1;
            __IO uint32_t TI1EN    :1;
            __IO uint32_t TI2EN    :1;
            __I           uint32_t :1;
            __IO uint32_t SMPEN    :1;
            __IO uint32_t RDA      :3;
            __I           uint32_t :1;
            __I uint32_t  CPD      :3;
            __I           uint32_t :17;
        } bits;
        __IO uint32_t reg;
    } PDCTL;
    /*Offset: 0x30 PXASCTL */
    union
    {
        struct
        {
            __IO uint32_t TXPXASS  :2;
            __IO uint32_t TZPXASS  :2;
            __IO uint32_t TXBKINS  :1;
            __IO uint32_t TZBKINS  :1;
            __I           uint32_t :26;
        } bits;
        __IO uint32_t reg;
    } PXASCTL;
    /* Offset: 0x34  Tx_CCTCTL */
    union
    {
        struct
        {
            __IO uint32_t CCTEN    :1;
            __IO uint32_t CRSET    :1;
            __IO uint32_t CCTSEL   :2;
            __IO uint32_t TCKFEN   :1;
            __IO uint32_t TCKDIV   :4;
            __IO uint32_t TCKDELAY :3;
            __IO uint32_t TXCKSEL  :2;
            __I           uint32_t :18;
        } bits;
        __IO uint32_t reg;
    } Tx_CCTCTL;
    /* Offset: 0x38 Tz_CCTCTL */
    union
    {
        struct
        {
            __IO uint32_t CCTEN    :1;
            __IO uint32_t CRSET    :1;
            __IO uint32_t CCTSEL   :2;
            __IO uint32_t TCKFEN   :1;
            __IO uint32_t TCKDIV   :4;
            __IO uint32_t TCKDELAY :3;
            __IO uint32_t TZCKSEL  :2;
            __I           uint32_t :18;
        } bits;
        __IO uint32_t reg;
    } Tz_CCTCTL;
    /* Offset: 0x3C */
    __IO uint32_t RESERVED_0x3c;
    /*Offset: 0x40  COMH1 */
    union
    {
        struct
        {
            __IO uint32_t COMH     :16;
            __I           uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } COMH1;
    /*Offset: 0x44 COML1 */
    union
    {
        struct
        {
            __IO uint32_t COML     :16;
            __I           uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } COML1;
    /*Offset: 0x48 FAUCTL1 */
    union
    {
        struct
        {
            __IO uint32_t FAUEN    :1;
            __IO uint32_t FLTP     :4;
            __IO uint32_t FLTEN    :1;
            __IO uint32_t FAUIE    :1;
            __IO uint32_t FAUIC    :1;
            __I uint32_t  FAUIF    :1;
            __IO uint32_t FVAL     :3;
            __IO uint32_t FINV     :2;
            __IO uint32_t TRST     :1;
            __I           uint32_t :17;
        } bits;
        __IO uint32_t reg;
    } FAUCTL1;
    /*Offset: 0x4C DITCTL */
    union
    {
        struct
        {
            __IO uint32_t FRCVAL   :5;
            __IO uint32_t DEDEN    :1;
            __IO uint32_t DPEEN    :1;
            __IO uint32_t DCOMEN   :1;
            __I           uint32_t :24;
        } bits;
        __IO uint32_t reg;
    } DITCTL;
    /*Offset: 0x50 COMH2 */
    union
    {
        struct
        {
            __IO uint32_t COMH     :16;
            __I           uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } COMH2;
    /*Offset: 0x54 COML2 */
    union
    {
        struct
        {
            __IO uint32_t COML     :16;
            __I           uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } COML2;
    /*Offset: 0x58 FAUCTL2 */
    union
    {
        struct
        {
            __IO uint32_t FAUEN    :1;
            __IO uint32_t FLTP     :4;
            __IO uint32_t FLTEN    :1;
            __IO uint32_t FAUIE    :1;
            __IO uint32_t FAUIC    :1;
            __I uint32_t  FAUIF    :1;
            __IO uint32_t FVAL     :3;
            __IO uint32_t FINV     :2;
            __IO uint32_t TRST     :1;
            __I           uint32_t :17;
        } bits;
        __IO uint32_t reg;
    } FAUCTL2;
    /*Offset: 0x5C CCRCTL */
    union
    {
        struct
        {
            __IO uint32_t TXCCR0SEN :1;
            __IO uint32_t TXCCR1SEN :1;
            __IO uint32_t TZCCR0SEN :1;
            __IO uint32_t TXCCR0SEL :1;
            __IO uint32_t TXCCR1SEL :1;
            __IO uint32_t TZCCR0SEL :1;
            __I           uint32_t  :26;
        } bits;
        __IO uint32_t reg;
    } CCRCTL;
    /*Offset: 0x60 COMH3 */
    union
    {
        struct
        {
            __IO uint32_t COMH     :16;
            __I           uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } COMH3;
    /*Offset: 0x64 COML3 */
    union
    {
        struct
        {
            __IO uint32_t COML     :16;
            __I           uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } COML3;
    /*Offset: 0x68 FAUCTL3 */
    union
    {
        struct
        {
            __IO uint32_t FAUEN    :1;
            __IO uint32_t FLTP     :4;
            __IO uint32_t FLTEN    :1;
            __IO uint32_t FAUIE    :1;
            __IO uint32_t FAUIC    :1;
            __I uint32_t  FAUIF    :1;
            __IO uint32_t FVAL     :3;
            __IO uint32_t FINV     :2;
            __IO uint32_t TRST     :1;
            __I           uint32_t :17;
        } bits;
        __IO uint32_t reg;
    } FAUCTL3;
    /*offset: 0x6c*/
    __IO uint32_t RESERVED_0x6c;
    /*Offset: 0x70 COMH4 */
    union
    {
        struct
        {
            __IO uint32_t COMH     :16;
            __I           uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } COMH4;
    /*Offset: 0x74 COML4  */
    union
    {
        struct
        {
            __IO uint32_t COML     :16;
            __I           uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } COML4;
    /*Offset: 0x78 FAUCTL4 */
    union
    {
        struct
        {
            __IO uint32_t FAUEN    :1;
            __IO uint32_t FLTP     :4;
            __IO uint32_t FLTEN    :1;
            __IO uint32_t FAUIE    :1;
            __IO uint32_t FAUIC    :1;
            __I uint32_t  FAUIF    :1;
            __IO uint32_t FVAL     :3;
            __IO uint32_t FINV     :2;
            __IO uint32_t TRST     :1;
            __I           uint32_t :17;
        } bits;
        __IO uint32_t reg;
    } FAUCTL4;
    /*offset: 0x7c*/
    __IO uint32_t RESERVED_0x7c;
    /*Offset: 0x080 CTL1 */
    union
    {
        struct
        {
            __IO uint32_t CH1M     :4;
            __IO uint32_t CH2M     :4;
            __IO uint32_t CH3M     :4;
            __IO uint32_t CH4M     :4;
            __I           uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } CTL1;
    /*Offset: 0x084 R1 */
    union
    {
        struct
        {
            __IO uint32_t ECCPXRY  :16;
            __I           uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } R1;
    /*Offset: 0x088 R2 */
    union
    {
        struct
        {
            __IO uint32_t ECCPXRY  :16;
            __I           uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } R2;
    /*Offset: 0x08C R3 */
    union
    {
        struct
        {
            __IO uint32_t ECCPXRY  :16;
            __I           uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } R3;
    /*Offset: 0x090  R4 */
    union
    {
        struct
        {
            __IO uint32_t ECCPXRY  :16;
            __I           uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } R4;
    /*Offset: 0x094 PXUDCTL */
    union
    {
        struct
        {
            __IO uint32_t PXUDEN0   :1;
            __IO uint32_t PXUDEN1   :1;
            __IO uint32_t PXUDEVT0  :1;
            __IO uint32_t PXUDEVT1  :1;
            __IO uint32_t PXUDEVT2  :1;
            __IO uint32_t PXUDEVT3  :1;
            __IO uint32_t PXMPEN    :1;
            __IO uint32_t TXUDR     :1;
            __IO uint32_t TXIFUDREN :1;
            __IO uint32_t TZUDR     :1;
            __IO uint32_t TZIFUDREN :1;
            __IO uint32_t DBUDEN    :1;
            __IO uint32_t READTEN   :1;
            __I           uint32_t  :19;
        } bits;
        __IO uint32_t reg;
    } PXUDCTL;
    /*Offset: 0x098 CTL2 */
    union
    {
        struct
        {
            __IO uint32_t TXMMS    :3;
            __IO uint32_t TXSMS    :3;
            __IO uint32_t TXTS     :3;
            __IO uint32_t TXMSSYNC :1;
            __IO uint32_t PXSPM    :1;
            __IO uint32_t PXXORM   :1;
            __IO uint32_t PXPWMI   :1;
            __IO uint32_t TZSMS    :3;
            __I           uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } CTL2;
    /*Offset: 0x09C PXDTCTL */
    union
    {
        struct
        {
            __IO uint32_t PXDC     :8;
            __IO uint32_t PZDC     :8;
            __I           uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } PXDTCTL;
    /*Offset: 0x0A0 PWMXOC */
    union
    {
        struct
        {
            __IO uint32_t PXOC1L   :2;
            __IO uint32_t PXOC1H   :2;
            __IO uint32_t PXOC2L   :2;
            __IO uint32_t PXOC2H   :2;
            __IO uint32_t PXOC3L   :2;
            __IO uint32_t PXOC3H   :2;
            __IO uint32_t PXOC4L   :2;
            __IO uint32_t PXOC4H   :2;
            __I           uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } PWMXOC;
    /*Offset: 0x0A4 PXATRCTL */
    union
    {
        struct
        {
            __I           uint32_t :8;
            __IO uint32_t PXCH1MOD :1;
            __IO uint32_t PXCH2MOD :1;
            __IO uint32_t PXCH3MOD :1;
            __IO uint32_t PXCH4MOD :1;
            __I           uint32_t :20;
        } bits;
        __IO uint32_t reg;
    } PXATRCTL;
    /*Offset: 0x0A8 PXASCTL0 */
    union
    {
        struct
        {
            __IO uint32_t PXASS1   :2;
            __IO uint32_t PXASS2   :2;
            __IO uint32_t PXASS3   :2;
            __IO uint32_t PXASS4   :2;
            __IO uint32_t PXASE1   :1;
            __IO uint32_t PXASE2   :1;
            __IO uint32_t PXASE3   :1;
            __IO uint32_t PXASE4   :1;
            __I           uint32_t :20;
        } bits;
        __IO uint32_t reg;
    } PXASCTL0;
    /*Offset: 0x0AC PXASCTL1 */
    union
    {
        struct
        {
            __IO uint32_t PXSS1L   :2;
            __IO uint32_t PXSS1H   :2;
            __IO uint32_t PXSS2L   :2;
            __IO uint32_t PXSS2H   :2;
            __IO uint32_t PXSS3L   :2;
            __IO uint32_t PXSS3H   :2;
            __IO uint32_t PXSS4L   :2;
            __IO uint32_t PXSS4H   :2;
            __I           uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } PXASCTL1;
    /*Offset: 0x0B0 */
    __IO uint32_t RESERVED_0xb0[2];
    /*Offset: 0x0B8 ZPDPORT */
    union
    {
        struct
        {
            __IO uint32_t ZPORT0   :1;
            __IO uint32_t ZPORT1   :1;
            __IO uint32_t ZPORT2   :1;
            __IO uint32_t ZPORT3   :1;
            __IO uint32_t ZPORT4   :1;
            __IO uint32_t ZPORT5   :1;
            __IO uint32_t ZPORT6   :1;
            __IO uint32_t ZPORT7   :1;
            __I           uint32_t :24;
        } bits;
        __IO uint32_t reg;
    } ZPDPORT;
    /*Offset: 0x0BC IE */
    union
    {
        struct
        {
            __IO uint32_t CC1IE    :1;
            __IO uint32_t CC2IE    :1;
            __IO uint32_t CC3IE    :1;
            __IO uint32_t CC4IE    :1;
            __IO uint32_t TXTIE    :1;
            __IO uint32_t TZIE     :1;
            __IO uint32_t TXIE     :1;
            __IO uint32_t TZUIE    :1;
            __IO uint32_t TXUIE    :1;
            __IO uint32_t CPIE     :1;
            __IO uint32_t PDIE     :1;
            __I           uint32_t :21;
        } bits;
        __IO uint32_t reg;
    } IE;
    /*Offset: 0x0C0  EGIF */
    union
    {
        struct
        {
            __IO uint32_t CPIF     :1;
            __IO uint32_t CC1G     :1;
            __IO uint32_t CC2G     :1;
            __IO uint32_t CC3G     :1;
            __IO uint32_t CC4G     :1;
            __IO uint32_t TXTRG    :1;
            __I uint32_t  CC1IF    :1;
            __I uint32_t  CC2IF    :1;
            __I uint32_t  CC3IF    :1;
            __I uint32_t  CC4IF    :1;
            __I uint32_t  TXTIF    :1;
            __I uint32_t  TZIF     :1;
            __I uint32_t  TXIF     :1;
            __I uint32_t  TZUIF    :1;
            __I uint32_t  TXUIF    :1;
            __I uint32_t  PDIF     :1;
            __I           uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } EGIF;
    /*Offset: 0x0C4 UDTIMX */
    union
    {
        struct
        {
            __IO uint32_t UDCNT    :8;
            __I           uint32_t :24;
        } bits;
        __IO uint32_t reg;
    } UDTIMX;
    /*Offset: 0x0C8 UDTIMZ */
    union
    {
        struct
        {
            __IO uint32_t UDCNT    :8;
            __I           uint32_t :24;
        } bits;
        __IO uint32_t reg;
    } UDTIMZ;
    /*Offset: 0x0CC DF */
    union
    {
        struct
        {
            __I uint32_t CH1DF    :1;
            __I uint32_t CH2DF    :1;
            __I uint32_t CH3DF    :1;
            __I uint32_t CH4DF    :1;
            __I uint32_t CLSDF    :1;
            __I uint32_t TRIGDF   :1;
            __I uint32_t TZUDF    :1;
            __I uint32_t TXUDF    :1;
            __I          uint32_t :24;
        } bits;
        __IO uint32_t reg;
    } DF;
    /*Offset: 0x0D0 C1 */
    union
    {
        struct
        {
            __I uint32_t ECCPXCY  :16;
            __I          uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } C1;
    /*Offset: 0x0D4 C2 */
    union
    {
        struct
        {
            __I uint32_t ECCPXCY  :16;
            __I          uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } C2;
    /*Offset: 0x0D8 C3 */
    union
    {
        struct
        {
            __I uint32_t ECCPXCY  :16;
            __I          uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } C3;
    /*Offset: 0x0DC C4 */
    union
    {
        struct
        {
            __I uint32_t ECCPXCY  :16;
            __I          uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } C4;
    /*offset: 0xE0*/
    __IO uint32_t RESERVED_0xe0;
    /*Offset: 0x0E4  DE */
    union
    {
        struct
        {
            __IO uint32_t CH1DE    :1;
            __IO uint32_t CH2DE    :1;
            __IO uint32_t CH3DE    :1;
            __IO uint32_t CH4DE    :1;
            __IO uint32_t CLSDE    :1;
            __IO uint32_t TXTDE    :1;
            __IO uint32_t TZUDE    :1;
            __IO uint32_t TXUDE    :1;
            __I           uint32_t :24;
        } bits;
        __IO uint32_t reg;
    } DE;
    /*Offset: 0x0E8 SRIC */
    union
    {
        struct
        {
            __IO uint32_t CC1IC    :1;
            __IO uint32_t CC2IC    :1;
            __IO uint32_t CC3IC    :1;
            __IO uint32_t CC4IC    :1;
            __IO uint32_t TXTIC    :1;
            __IO uint32_t TZIC     :1;
            __IO uint32_t TXIC     :1;
            __IO uint32_t TZUIC    :1;
            __IO uint32_t TXUIC    :1;
            __IO uint32_t CPIC     :1;
            __IO uint32_t PDIC     :1;
            __I           uint32_t :21;
        } bits;
        __IO uint32_t reg;
    } SRIC;
    /*Offset: 0x0EC  CTL3 */
    union
    {
        struct
        {
            __IO uint32_t PXSPMST  :1;
            __IO uint32_t TUNITE   :1;
            __IO uint32_t PXRSEN   :1;
            __IO uint32_t COMBEN   :1;
            __IO uint32_t COMINV   :2;
            __IO uint32_t CAPTST   :1;
            __IO uint32_t GTBEN    :1;
            __IO uint32_t GTBEOUT  :1;
            __IO uint32_t CH0HM    :1;
            __IO uint32_t CH1HM    :1;
            __IO uint32_t CH2HM    :1;
            __IO uint32_t CH3HM    :1;
            __IO uint32_t TRGSEL   :2;
            __I           uint32_t :17;
        } bits;
        __IO uint32_t reg;
    } CTL3;
    /*Offset: 0x0F0*/
    __IO uint32_t RESERVED_0xf0[4];
    /*Offset: 0x100 CAPPRSC */
    union
    {
        struct
        {
            __IO uint32_t CH1CAPPR :4;
            __IO uint32_t CH2CAPPR :4;
            __IO uint32_t CH3CAPPR :4;
            __IO uint32_t CH4CAPPR :4;
            __I           uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } CAPPRSC;
    /*Offset: 0x104 CAPTIME */
    union
    {
        struct
        {
            __IO uint32_t CH1CAPTIME :4;
            __IO uint32_t CH2CAPTIME :4;
            __IO uint32_t CH3CAPTIME :4;
            __IO uint32_t CH4CAPTIME :4;
            __I           uint32_t   :16;
        } bits;
        __IO uint32_t reg;
    } CAPTIME;
    /*Offset: 0x108 CAPCTL1 */
    union
    {
        struct
        {
            __IO uint32_t CH1CAPEN :1;
            __IO uint32_t CH2CAPEN :1;
            __IO uint32_t CH3CAPEN :1;
            __IO uint32_t CH4CAPEN :1;
            __IO uint32_t CH1CAPED :1;
            __IO uint32_t CH2CAPED :1;
            __IO uint32_t CH3CAPED :1;
            __IO uint32_t CH4CAPED :1;
            __IO uint32_t CH1CMODE :1;
            __IO uint32_t CH2CMODE :1;
            __IO uint32_t CH3CMODE :1;
            __IO uint32_t CH4CMODE :1;
            __IO uint32_t CH1TIEN  :1;
            __IO uint32_t CH2TIEN  :1;
            __IO uint32_t CH3TIEN  :1;
            __IO uint32_t CH4TIEN  :1;
            __I           uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } CAPCTL1;
    /*Offset: 0x10C CAPCTL2*/
    union
    {
        struct
        {
            __IO uint32_t CH1CAPPIN :3;
            __IO uint32_t CH2CAPPIN :3;
            __IO uint32_t CH3CAPPIN :3;
            __IO uint32_t CH4CAPPIN :3;
            __I           uint32_t  :20;
        } bits;
        __IO uint32_t reg;
    } CAPCTL2;
    /*Offset: 0x110 FLCLKP */
    union
    {
        struct
        {
            __IO uint32_t CH1FLCLKP :4;
            __IO uint32_t CH2FLCLKP :4;
            __IO uint32_t CH3FLCLKP :4;
            __IO uint32_t CH4FLCLKP :4;
            __I           uint32_t  :16;
        } bits;
        __IO uint32_t reg;
    } FLCLKP;
    /*Offset: 0x114 FILTER */
    union
    {
        struct
        {
            __IO uint32_t CH1FILTER :3;
            __IO uint32_t CH2FILTER :3;
            __IO uint32_t CH3FILTER :3;
            __IO uint32_t CH4FILTER :3;
            __I           uint32_t  :20;
        } bits;
        __IO uint32_t reg;
    } FILTER;
    /*Offset: 0x118 PHSCTLX */
    union
    {
        struct
        {
            __IO uint32_t PHSENX   :1;
            __IO uint32_t PHSXMODE :1;
            __IO uint32_t PHSWTX   :1;
            __IO uint32_t PHSXSEL  :3;
            __IO uint32_t PHSXPRSC :4;
            __IO uint32_t PHSXTIME :4;
            __IO uint32_t PHSXTIEN :1;
            __IO uint32_t PHSXDIR  :1;
            __I           uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } PHSCTLX;
    /*Offset: 0x11C PHSCTLZ */
    union
    {
        struct
        {
            __IO uint32_t PHSENZ   :1;
            __IO uint32_t PHSZMODE :1;
            __IO uint32_t PHSWTZ   :1;
            __IO uint32_t PHSZSEL  :3;
            __IO uint32_t PHSZPRSC :4;
            __IO uint32_t PHSZTIME :4;
            __IO uint32_t PHSZTIEN :1;
            __IO uint32_t PHSZDIR  :1;
            __I           uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } PHSCTLZ;
    /*Offset: 0x120 TX_PHS */
    union
    {
        struct
        {
            __IO uint32_t PHSX     :16;
            __I           uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } TX_PHS;
    /*Offset: 0x124*/
    union
    {
        struct
        {
            __IO uint32_t PHSZ     :16;
            __I           uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } TZ_PHS;
    /*Offset: 0x128*/
    union
    {
        struct
        {
            __IO uint32_t UDREN      :1;
            __IO uint32_t TRGUDEN0   :1;
            __IO uint32_t TRGUDEN1   :1;
            __IO uint32_t TUDMODE0   :1;
            __IO uint32_t TUDMODE1   :1;
            __IO uint32_t CAPDEDEN1  :1;
            __IO uint32_t CAPDEDEN2  :1;
            __IO uint32_t CAPDEDEN3  :1;
            __IO uint32_t CAPDEDEN4  :1;
            __IO uint32_t CAPFILTEN1 :1;
            __IO uint32_t CAPFILTEN2 :1;
            __IO uint32_t CAPFILTEN3 :1;
            __IO uint32_t CAPFILTEN4 :1;
            __IO uint32_t TRGPOLX    :1;
            __IO uint32_t TRGPOLZ    :1;
            __I           uint32_t   :17;
        } bits;
        __IO uint32_t reg;
    } CTL4;
    /*Offset: 0x12C*/
    union
    {
        struct
        {
            __IO uint32_t CH1PXDC  :8;
            __IO uint32_t CH2PXDC  :8;
            __I           uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } PXDTCTL2;
    /*Offset: 0x130*/
    union
    {
        struct
        {
            __IO uint32_t CH1DTCLK :4;
            __IO uint32_t CH2DTCLK :4;
            __IO uint32_t CH3DTCLK :4;
            __IO uint32_t CH4DTCLK :4;
            __I           uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } PXDTCFG;
} AdvancedTimer_RegisterMap_t;

/**
 * @brief Address of AdvancedTimer register
 */
#define T5_ADDR    ((uint32_t)0x40003480U)
#define T6_ADDR    ((uint32_t)0x40003480U)
#define T5T6_ADDR  ((uint32_t)0x40003480U)
#define T9_ADDR    ((uint32_t)0x40003600U)
#define T10_ADDR   ((uint32_t)0x40003600U)
#define T9T10_ADDR ((uint32_t)0x40003600U)

/**
 * @brief Pointer to AdvancedTimer register
 */
#define T5_PTR    ((AdvancedTimer_RegisterMap_t *)T5_ADDR)
#define T6_PTR    ((AdvancedTimer_RegisterMap_t *)T6_ADDR)
#define T5T6_PTR  ((AdvancedTimer_RegisterMap_t *)T5T6_ADDR)
#define T9_PTR    ((AdvancedTimer_RegisterMap_t *)T9_ADDR)
#define T10_PTR   ((AdvancedTimer_RegisterMap_t *)T10_ADDR)
#define T9T10_PTR ((AdvancedTimer_RegisterMap_t *)T9T10_ADDR)

/**
 * @brief Register map of AdvancedTimer
 */
#define T5_RM    (*(T5_PTR))
#define T6_RM    (*(T6_PTR))
#define T5T6_RM  (*(T5T6_PTR))
#define T9_RM    (*(T9_PTR))
#define T10_RM   (*(T10_PTR))
#define T9T10_RM (*(T9T10_PTR))

/**
 * @brief Module check assertion
 */
#define CHECK_ATIM_ALL_PERIPH_ADDR(Module)                                                                             \
    (((uint32_t)(Module) == (uint32_t)(T5_PTR)) || ((uint32_t)(Module) == (uint32_t)(T6_PTR)) ||                       \
     ((uint32_t)(Module) == (uint32_t)(T9_PTR)) || ((uint32_t)(Module) == (uint32_t)(T10_PTR)) ||                      \
     ((uint32_t)(Module) == (uint32_t)(T5T6_PTR)) || ((uint32_t)(Module) == (uint32_t)(T9T10_PTR)))

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
#endif /*End of KF32A158SF_ATIMER_REG_H*/
/* EOF */
