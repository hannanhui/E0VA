/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a158sf_reg_cmp.h
 *  @Date            : 2025-07-03
 *  @Version         : {{VersionDate}}
 *  @Description     : This document describes the register definition of Cmp
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
#ifndef KF32A158SF_REG_CMP_H
#define KF32A158SF_REG_CMP_H

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

    /* Offset:0x0  CMP_CTL0 */
    union
    {
        struct
        {
            __I           uint32_t  :1;
            __IO uint32_t POL       :1;
            __IO uint32_t WINEN     :1;
            __IO uint32_t FLTEN     :1;
            __IO uint32_t FLTCNT    :3;
            __IO uint32_t WINCLKSEL :1;
            __IO uint32_t FLTDIV    :8;
            __IO uint32_t FLTCS     :2;
            __IO uint32_t IFREN     :1;
            __IO uint32_t IFFEN     :1;
            __I           uint32_t  :4;
            __IO uint32_t NMOD      :4;
            __IO uint32_t PMOD      :4;
        } bits;
        __IO uint32_t reg;
    } CTL0;

    /* Offset:0x4  CMP_CTL1 */
    union
    {
        struct
        {
            __I           uint32_t  :1;
            __IO uint32_t POL       :1;
            __IO uint32_t WINEN     :1;
            __IO uint32_t FLTEN     :1;
            __IO uint32_t FLTCNT    :3;
            __IO uint32_t WINCLKSEL :1;
            __IO uint32_t FLTDIV    :8;
            __IO uint32_t FLTCS     :2;
            __IO uint32_t IFREN     :1;
            __IO uint32_t IFFEN     :1;
            __I           uint32_t  :4;
            __IO uint32_t NMOD      :4;
            __IO uint32_t PMOD      :4;
        } bits;
        __IO uint32_t reg;
    } CTL1;

    /* Offset:0x8  CMP_CTL2 */
    union
    {
        struct
        {
            __I           uint32_t  :1;
            __IO uint32_t POL       :1;
            __IO uint32_t WINEN     :1;
            __IO uint32_t FLTEN     :1;
            __IO uint32_t FLTCNT    :3;
            __IO uint32_t WINCLKSEL :1;
            __IO uint32_t FLTDIV    :8;
            __IO uint32_t FLTCS     :2;
            __IO uint32_t IFREN     :1;
            __IO uint32_t IFFEN     :1;
            __I           uint32_t  :4;
            __IO uint32_t NMOD      :4;
            __IO uint32_t PMOD      :4;
        } bits;
        __IO uint32_t reg;
    } CTL2;

    /* Offset:0xc  CMP_CTL3 */
    union
    {
        struct
        {
            __IO uint32_t EN        :1;
            __IO uint32_t POL       :1;
            __IO uint32_t WINEN     :1;
            __IO uint32_t FLTEN     :1;
            __IO uint32_t FLTCNT    :3;
            __IO uint32_t WINCLKSEL :1;
            __IO uint32_t FLTDIV    :8;
            __IO uint32_t FLTCS     :2;
            __IO uint32_t IFREN     :1;
            __IO uint32_t IFFEN     :1;
            __I           uint32_t  :4;
            __IO uint32_t NMOD      :4;
            __IO uint32_t PMOD      :4;
        } bits;
        __IO uint32_t reg;
    } CTL3;

    /* Offset:0x10  CMP_CTL4 */
    union
    {
        struct
        {
            __IO uint32_t C0EN            :1;
            __IO uint32_t C1EN            :1;
            __IO uint32_t C2EN            :1;
            __IO uint32_t FLTINSEL        :1;
            __IO uint32_t BEMFEN          :1;
            __IO uint32_t HALLSEL         :1;
            __IO uint32_t DELAYVOL        :2;
            __IO uint32_t CMPOUTDSEL      :2;
            __IO uint32_t IOEN            :1;
            __IO uint32_t CMP3ANALOGOUTEN :1;
            __IO uint32_t C0IE            :1;
            __IO uint32_t C1IE            :1;
            __IO uint32_t C2IE            :1;
            __IO uint32_t C3IE            :1;
            __IO uint32_t C0IC            :1;
            __IO uint32_t C1IC            :1;
            __IO uint32_t C2IC            :1;
            __IO uint32_t C3IC            :1;
            __IO uint32_t CMPOUTASEL      :2;
            __IO uint32_t PWMCMP          :1;
            __IO uint32_t CIFMS           :1;
            __I uint32_t  C0IF            :1;
            __I uint32_t  C1IF            :1;
            __I uint32_t  C2IF            :1;
            __I uint32_t  C3IF            :1;
            __I uint32_t  C0OUT           :1;
            __I uint32_t  C1OUT           :1;
            __I uint32_t  C2OUT           :1;
            __I uint32_t  C3OUT           :1;
        } bits;
        __IO uint32_t reg;
    } CTL4;

    /* Offset:0x14  CMP_CTL5 */
    union
    {
        struct
        {
            __IO uint32_t C0TRGSEL  :2;
            __IO uint32_t C1TRGSEL  :2;
            __IO uint32_t C2TRGSEL  :2;
            __IO uint32_t C3TRGSEL  :2;
            __IO uint32_t CMPLPEN   :1;
            __I           uint32_t  :11;
            __IO uint32_t CMP0DMAIF :1;
            __IO uint32_t CMP1DMAIF :1;
            __IO uint32_t CMP2DMAIF :1;
            __IO uint32_t CMP3DMAIF :1;
            __IO uint32_t CMP0DMAEN :1;
            __IO uint32_t CMP1DMAEN :1;
            __IO uint32_t CMP2DMAEN :1;
            __IO uint32_t CMP3DMAEN :1;
            __IO uint32_t C0PSEL    :2;
            __IO uint32_t MOTORSEL  :1;
            __IO uint32_t INSCM     :1;
        } bits;
        __IO uint32_t reg;
    } CTL5;

    /* Offset:0x18  CMP_TRIM0 */
    union
    {
        struct
        {
            __IO uint32_t C0TRIMNPOL    :1;
            __IO uint32_t C0TRIMN       :6;
            __IO uint32_t C0TRIMPPOL    :1;
            __IO uint32_t C0TRIMP       :6;
            __I           uint32_t      :16;
            __IO uint32_t CMPTRIMLOWEN  :1;
            __IO uint32_t CMPTRIMHIGHEN :1;
        } bits;
        __IO uint32_t reg;
    } TRIM0;

    /* Offset:0x1c  CMP_TRIM1 */
    union
    {
        struct
        {
            __IO uint32_t CxTRIMNPOL :1;
            __IO uint32_t CxTRIMN    :6;
            __IO uint32_t CxTRIMPPOL :1;
            __IO uint32_t CxTRIMP    :6;
            __I           uint32_t   :18;
        } bits;
        __IO uint32_t reg;
    } TRIM1;

    /* Offset:0x20  CMP_TRIM2 */
    union
    {
        struct
        {
            __IO uint32_t CxTRIMNPOL :1;
            __IO uint32_t CxTRIMN    :6;
            __IO uint32_t CxTRIMPPOL :1;
            __IO uint32_t CxTRIMP    :6;
            __I           uint32_t   :18;
        } bits;
        __IO uint32_t reg;
    } TRIM2;

    /* Offset:0x24  CMP_TRIM3 */
    union
    {
        struct
        {
            __IO uint32_t C3TRIMNPOL   :1;
            __IO uint32_t C3TRIMN      :6;
            __IO uint32_t C3TRIMPPOL   :1;
            __IO uint32_t C3TRIMP      :6;
            __I           uint32_t     :17;
            __IO uint32_t ENCMP3VREF1V :1;
        } bits;
        __IO uint32_t reg;
    } TRIM3;

    /* Offset:0x28  CMP_CTL6 */
    union
    {
        struct
        {
            __IO uint32_t LEN           :4;
            __IO uint32_t SCAN          :1;
            __I           uint32_t      :8;
            __IO uint32_t INITIALDLYMOD :6;
            __IO uint32_t NASM          :2;
            __IO uint32_t FXNCHSEL      :4;
            __IO uint32_t FXPCHSEL      :4;
            __IO uint32_t FXPORTSEL     :1;
            __IO uint32_t RRIE          :1;
            __IO uint32_t RREN          :1;
        } bits;
        __IO uint32_t reg;
    } CTL6;

    /* Offset:0x2c  CMP_PSCANSQ0 */
    union
    {
        struct
        {
            __IO uint32_t PSCAN0 :4;
            __IO uint32_t PSCAN1 :4;
            __IO uint32_t PSCAN2 :4;
            __IO uint32_t PSCAN3 :4;
            __IO uint32_t PSCAN4 :4;
            __IO uint32_t PSCAN5 :4;
            __IO uint32_t PSCAN6 :4;
            __IO uint32_t PSCAN7 :4;
        } bits;
        __IO uint32_t reg;
    } PSCANSQ0;

    /* Offset:0x30  CMP_PSCANSQ1 */
    union
    {
        struct
        {
            __IO uint32_t PSCAN8  :4;
            __IO uint32_t PSCAN9  :4;
            __IO uint32_t PSCAN10 :4;
            __IO uint32_t PSCAN11 :4;
            __IO uint32_t PSCAN12 :4;
            __IO uint32_t PSCAN13 :4;
            __IO uint32_t PSCAN14 :4;
            __IO uint32_t PSCAN15 :4;
        } bits;
        __IO uint32_t reg;
    } PSCANSQ1;

    /* Offset:0x34  CMP_NSCANSQ0 */
    union
    {
        struct
        {
            __IO uint32_t NSCAN0 :4;
            __IO uint32_t NSCAN1 :4;
            __IO uint32_t NSCAN2 :4;
            __IO uint32_t NSCAN3 :4;
            __IO uint32_t NSCAN4 :4;
            __IO uint32_t NSCAN5 :4;
            __IO uint32_t NSCAN6 :4;
            __IO uint32_t NSCAN7 :4;
        } bits;
        __IO uint32_t reg;
    } NSCANSQ0;

    /* Offset:0x38  CMP_NSCANSQ1 */
    union
    {
        struct
        {
            __IO uint32_t NSCAN8  :4;
            __IO uint32_t NSCAN9  :4;
            __IO uint32_t NSCAN10 :4;
            __IO uint32_t NSCAN11 :4;
            __IO uint32_t NSCAN12 :4;
            __IO uint32_t NSCAN13 :4;
            __IO uint32_t NSCAN14 :4;
            __IO uint32_t NSCAN15 :4;
        } bits;
        __IO uint32_t reg;
    } NSCANSQ1;

    /* Offset:0x3c  CMP_SR */
    union
    {
        struct
        {
            __IO uint32_t PCHOUT :16;
            __IO uint32_t NCHOUT :16;
        } bits;
        __IO uint32_t reg;
    } SR;

    /* Offset:0x40  CMP_CHFLAG */
    union
    {
        struct
        {
            __I uint32_t PCHFLAG :16;
            __I uint32_t NCHFLAG :16;
        } bits;
        __IO uint32_t reg;
    } CHFLAG;

    /* Offset:0x44  CMP_CHIC */
    union
    {
        struct
        {
            __IO uint32_t PCH0IC  :1;
            __IO uint32_t PCH1IC  :1;
            __IO uint32_t PCH2IC  :1;
            __IO uint32_t PCH3IC  :1;
            __IO uint32_t PCH4IC  :1;
            __IO uint32_t PCH5IC  :1;
            __IO uint32_t PCH6IC  :1;
            __IO uint32_t PCH7IC  :1;
            __IO uint32_t PCH8IC  :1;
            __IO uint32_t PCH9IC  :1;
            __IO uint32_t PCH10IC :1;
            __IO uint32_t PCH11IC :1;
            __IO uint32_t PCH12IC :1;
            __IO uint32_t PCH13IC :1;
            __IO uint32_t PCH14IC :1;
            __IO uint32_t PCH15IC :1;
            __IO uint32_t NCH0IC  :1;
            __IO uint32_t NCH1IC  :1;
            __IO uint32_t NCH2IC  :1;
            __IO uint32_t NCH3IC  :1;
            __IO uint32_t NCH4IC  :1;
            __IO uint32_t NCH5IC  :1;
            __IO uint32_t NCH6IC  :1;
            __IO uint32_t NCH7IC  :1;
            __IO uint32_t NCH8IC  :1;
            __IO uint32_t NCH9IC  :1;
            __IO uint32_t NCH10IC :1;
            __IO uint32_t NCH11IC :1;
            __IO uint32_t NCH12IC :1;
            __IO uint32_t NCH13IC :1;
            __IO uint32_t NCH14IC :1;
            __IO uint32_t NCH15IC :1;
        } bits;
        __IO uint32_t reg;
    } CHIC;

} Cmp_RegisterMap_t;

/**
 * @brief Address of Cmp register
 */
#define CMP_ADDR ((uint32_t)0x40000800U)

/**
 * @brief Pointer to Cmp register
 */
#define CMP_PTR ((Cmp_RegisterMap_t *)CMP_ADDR)

/**
 * @brief Register map of Cmp
 */
#define CMP_RM (*(CMP_PTR))

/**
 * @brief Module check assertion
 */
#define CHECK_CMP_ALL_PERIPH_ADDR(Module) (((uint32_t)(Module) == (uint32_t)(CMP_PTR)))

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
#endif /*End of KF32A158SF_REG_CMP_H*/
/* EOF */
