/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a158sf_reg_osc.h
 *  @Date            : 2025-07-03
 *  @Version         : {{VersionDate}}
 *  @Description     : This document describes the register definition of Osc
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
#ifndef KF32A158SF_REG_OSC_H
#define KF32A158SF_REG_OSC_H

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

    /* Offset:0x0  OSC_CTL0 */
    union
    {
        struct
        {
            __IO uint32_t PMWREN   :1;
            __IO uint32_t SCKS     :3;
            __IO uint32_t LFCKEN   :1;
            __I           uint32_t :1;
            __IO uint32_t LFCKS    :2;
            __IO uint32_t HFCKEN   :1;
            __IO uint32_t HFCKS    :3;
            __IO uint32_t PLL0CKS  :1;
            __IO uint32_t PLL1CKS  :1;
            __I           uint32_t :2;
            __IO uint32_t SCKDIV   :3;
            __I           uint32_t :1;
            __IO uint32_t HFCKDIV  :4;
            __IO uint32_t LFCKDIV  :3;
            __I           uint32_t :1;
            __IO uint32_t PLL0DIV  :1;
            __IO uint32_t PLL1DIV  :1;
            __IO uint32_t LKDT0EN  :1;
            __IO uint32_t LKDT1EN  :1;
        } bits;
        __IO uint32_t reg;
    } CTL0;

    /* Offset:0x4  OSC_CTL1 */
    union
    {
        struct
        {
            __IO uint32_t LPHFDLY     :4;
            __IO uint32_t TESTEN_STOP :1;
            __IO uint32_t HSEHYEN     :1;
            __IO uint32_t HF1CKEN     :1;
            __IO uint32_t HF1CKS      :3;
            __IO uint32_t HF1CKDIV    :4;
            __IO uint32_t SCLKPMCDIV  :2;
            __IO uint32_t FSCM        :1;
            __IO uint32_t FSCMGAP     :3;
            __I           uint32_t    :1;
            __IO uint32_t FSCMS       :3;
            __IO uint32_t CLKOUTS     :4;
            __IO uint32_t CLKOE       :1;
            __IO uint32_t CLKOUTDIV   :3;
        } bits;
        __IO uint32_t reg;
    } CTL1;

    /* Offset:0x8  OSC_INT */
    union
    {
        struct
        {
            __IO uint32_t ILFIF    :1;
            __IO uint32_t IHFIF    :1;
            __IO uint32_t ELFIF    :1;
            __IO uint32_t EHFIF    :1;
            __IO uint32_t PLL0IF   :1;
            __IO uint32_t PLL1IF   :1;
            __IO uint32_t LPHFIF   :1;
            __IO uint32_t CKFIF    :1;
            __IO uint32_t ILFIE    :1;
            __IO uint32_t IHFIE    :1;
            __IO uint32_t ELFIE    :1;
            __IO uint32_t EHFIE    :1;
            __IO uint32_t PLL0IE   :1;
            __IO uint32_t PLL1IE   :1;
            __IO uint32_t LPHFIE   :1;
            __I           uint32_t :1;
            __IO uint32_t LPLFIF   :1;
            __I           uint32_t :7;
            __IO uint32_t LPLFIE   :1;
            __I           uint32_t :7;
        } bits;
        __IO uint32_t reg;
    } INT;

    /* Offset:0xc  OSC_CTL2 */
    union
    {
        struct
        {
            __IO uint32_t INTLFSWEN :1;
            __IO uint32_t INTHFSWEN :1;
            __IO uint32_t EXTLFSWEN :1;
            __IO uint32_t EXTHFSWEN :1;
            __IO uint32_t PLL0SWEN  :1;
            __IO uint32_t PLL1SWEN  :1;
            __I           uint32_t  :2;
            __IO uint32_t ILFDLY    :4;
            __IO uint32_t IHFDLY    :4;
            __IO uint32_t ELFDLY    :4;
            __IO uint32_t EHFDLY    :4;
            __IO uint32_t PLL0DLY   :4;
            __IO uint32_t PLL1DLY   :4;
        } bits;
        __IO uint32_t reg;
    } CTL2;

    /* Offset:0x10  OSC_HFOSCCAL0 */
    union
    {
        struct
        {
            __IO uint32_t CTAT        :5;
            __IO uint32_t PTAT        :5;
            __IO uint32_t OSCLVBGTRIM :3;
            __IO uint32_t HSIHIGRADE  :1;
            __IO uint32_t HISLDO      :3;
            __IO uint32_t SCALEDIV32  :1;
            __IO uint32_t SCALEDIV16  :1;
            __IO uint32_t SCALEDIV8   :1;
            __IO uint32_t SCALEDIV4   :1;
            __IO uint32_t SCALEDIV2   :1;
            __IO uint32_t SCALE1X     :1;
            __IO uint32_t SCALE2X     :1;
            __IO uint32_t SCALE4X     :1;
            __IO uint32_t SCALE8X     :1;
            __IO uint32_t SCALE16X    :5;
            __IO uint32_t SCALE32X    :1;
        } bits;
        __IO uint32_t reg;
    } HFOSCCAL0;

    /* Offset:0x14  OSC_HFOSCCAL1 */
    union
    {
        struct
        {
            __I           uint32_t  :24;
            __IO uint32_t OSCBGOE   :1;
            __IO uint32_t HSILDOOE  :1;
            __IO uint32_t MORE      :1;
            __IO uint32_t PLL0LDOOE :1;
            __IO uint32_t ZVTOE     :1;
            __IO uint32_t DEBUGRWOP :1;
            __IO uint32_t OSCFMOD0  :1;
            __IO uint32_t OSCFMOD1  :1;
        } bits;
        __IO uint32_t reg;
    } HFOSCCAL1;

    /* Offset:0x18  OSC_CTL3 */
    union
    {
        struct
        {
            __IO uint32_t HSXTALEXEN :1;
            __IO uint32_t HSEMODESEL :1;
            __IO uint32_t GMBOOST    :4;
            __I           uint32_t   :3;
            __IO uint32_t XTHR2M     :1;
            __IO uint32_t XTHR470K   :1;
            __IO uint32_t XTHR200K   :1;
            __I           uint32_t   :1;
            __IO uint32_t XTHCOMPEN  :1;
            __IO uint32_t XTHCOMPI   :2;
            __I           uint32_t   :16;
        } bits;
        __IO uint32_t reg;
    } CTL3;

    __I uint32_t RESERVED_0x1c;

    /* Offset:0x20  OSC_HF2CTL */
    union
    {
        struct
        {
            __IO uint32_t PMCTL_LOCK          :1;
            __IO uint32_t PMCAL_LOCK          :1;
            __IO uint32_t IWDTCTL_LOCK        :1;
            __IO uint32_t WWDTCTL_LOCK        :1;
            __IO uint32_t EWDTCTL_LOCK        :1;
            __I           uint32_t            :23;
            __IO uint32_t FLASH_STANDBY_DELAY :2;
            __IO uint32_t USER_PMCTL_LOCK     :1;
            __IO uint32_t USER_PMCAL_LOCK     :1;
        } bits;
        __IO uint32_t reg;
    } HF2CTL;

    /* Offset:0x24  OSC_HF2OSCCAL */
    union
    {
        struct
        {
            __IO uint32_t OSC2VREFTRIM :8;
            __IO uint32_t OSC2PROCTRIM :3;
            __I           uint32_t     :21;
        } bits;
        __IO uint32_t reg;
    } HF2OSCCAL;

    __I uint32_t RESERVED_0x28[2];

    /* Offset:0x30  OSC_HF3CTL */
    union
    {
        struct
        {
            __IO uint32_t OSC3EN          :1;
            __IO uint32_t ZVT3TS          :1;
            __IO uint32_t BGTS            :1;
            __IO uint32_t LDO12TS         :1;
            __IO uint32_t LDO15TS         :1;
            __IO uint32_t ZVTTS           :1;
            __IO uint32_t VCOREOEN        :1;
            __IO uint32_t FLASHPOWOEN     :1;
            __IO uint32_t LPPHERIOEN      :1;
            __IO uint32_t RAMAPOWOEN      :1;
            __IO uint32_t RAMBPOWOEN      :1;
            __IO uint32_t FVRCAPMONEN     :1;
            __IO uint32_t FVRCAPLESSMONEN :1;
            __IO uint32_t FVRCAPLESSOEN   :1;
            __IO uint32_t FVRCAPOEN       :1;
            __IO uint32_t FLASHV12OEN     :1;
            __IO uint32_t VREF1VOEN       :1;
            __I           uint32_t        :11;
            __IO uint32_t PROCMONEN       :1;
            __IO uint32_t TEMPMONEN       :1;
            __IO uint32_t PROCMONTS       :1;
            __IO uint32_t TEMPMONTS       :1;
        } bits;
        __IO uint32_t reg;
    } HF3CTL;

    /* Offset:0x34  OSC_HF3OSCCAL */
    union
    {
        struct
        {
            __IO uint32_t CTAT        :5;
            __IO uint32_t PTAT        :5;
            __IO uint32_t HISBG12TRIM :3;
            __IO uint32_t HISCURX2EN  :1;
            __IO uint32_t HISLDO15    :3;
            __IO uint32_t SCALEDIV32  :1;
            __IO uint32_t SCALEDIV16  :1;
            __IO uint32_t SCALEDIV8   :1;
            __IO uint32_t SCALEDIV4   :1;
            __IO uint32_t SCALEDIV2   :1;
            __IO uint32_t SCALE1X     :1;
            __IO uint32_t SCALE2X     :1;
            __IO uint32_t SCALE4X     :1;
            __IO uint32_t SCALE8X     :1;
            __IO uint32_t SCALE16X    :5;
            __IO uint32_t SCALE32X    :1;
        } bits;
        __IO uint32_t reg;
    } HF3OSCCAL;

} Osc_RegisterMap_t;

/**
 * @brief Address of Osc register
 */
#define OSC_ADDR ((uint32_t)0x40003900U)

/**
 * @brief Pointer to Osc register
 */
#define OSC_PTR ((Osc_RegisterMap_t *)OSC_ADDR)

/**
 * @brief Register map of Osc
 */
#define OSC_RM (*(OSC_PTR))

/**
 * @brief Module check assertion
 */
#define CHECK_OSC_ALL_PERIPH_ADDR(Module) (((uint32_t)(Module) == (uint32_t)(OSC_PTR)))

typedef volatile struct
{

    /* Offset:0x0  PLL_CTL */
    union
    {
        struct
        {
            __IO uint32_t PDRST    :1;
            __I           uint32_t :1;
            __IO uint32_t M        :14;
            __IO uint32_t N        :4;
            __IO uint32_t OD       :2;
            __I           uint32_t :10;
        } bits;
        __IO uint32_t reg;
    } CTL;

} Pll_RegisterMap_t;

/**
 * @brief Address of Pll register
 */
#define PLL0_ADDR ((uint32_t)0x40002580U)
#define PLL1_ADDR ((uint32_t)0x40002584U)

/**
 * @brief Pointer to Pll register
 */
#define PLL0_PTR ((Pll_RegisterMap_t *)PLL0_ADDR)
#define PLL1_PTR ((Pll_RegisterMap_t *)PLL1_ADDR)

/**
 * @brief Register map of Pll
 */
#define PLL0_RM (*(PLL0_PTR))
#define PLL1_RM (*(PLL1_PTR))

/**
 * @brief Module check assertion
 */
#define CHECK_PLL_ALL_PERIPH_ADDR(Module)                                                                              \
    (((uint32_t)(Module) == (uint32_t)(PLL0_PTR)) || ((uint32_t)(Module) == (uint32_t)(PLL1_PTR)))

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
#endif /*End of KF32A158SF_OSC_REG_H*/
/* EOF */
