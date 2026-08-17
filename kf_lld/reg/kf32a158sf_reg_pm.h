/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a158sf_reg_pm.h
 *  @Date            : 2025-07-03
 *  @Version         : {{VersionDate}}
 *  @Description     : This document describes the register definition of Pm
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
#ifndef KF32A158SF_REG_PM_H
#define KF32A158SF_REG_PM_H

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

    /* Offset:0x0  PM_CTL0 */
    union
    {
        struct
        {
            __IO uint32_t LPMS           :3;
            __IO uint32_t PMCWKPTESTSEL  :1;
            __IO          uint32_t       :1;
            __IO uint32_t BORSEL         :2;
            __IO uint32_t BKPWR          :1;
            __IO uint32_t HSIEN          :1;
            __IO uint32_t BORHSEN        :1;
            __IO uint32_t FVRCAPLESSEN   :1;
            __IO uint32_t FVRCAPLESSMODE :1;
            __IO uint32_t BORWKPEN       :1;
            __IO uint32_t PHERIIOSEL     :1;
            __IO          uint32_t       :1;
            __IO uint32_t PMIWDTEN       :1;
            __IO uint32_t IWDTRMSEL      :1;
            __I uint32_t  LSECONF        :1;
            __IO          uint32_t       :1;
            __IO uint32_t LPRAMSEL       :2;
            __IO uint32_t IWDTCLR        :1;
            __IO uint32_t BKPREGCLR      :1;
            __IO          uint32_t       :4;
            __IO uint32_t LSEEXEN        :1;
            __IO uint32_t LSEEN          :1;
            __IO uint32_t LSIEN          :1;
            __IO          uint32_t       :1;
            __IO uint32_t IOLATCH        :1;
        } bits;
        __IO uint32_t reg;
    } CTL0;

    /* Offset:0x4  PM_CTL1 */
    union
    {
        struct
        {
            __IO uint32_t PVDEN      :1;
            __IO          uint32_t   :1;
            __IO uint32_t PVDS       :3;
            __IO          uint32_t   :1;
            __IO uint32_t FVRMS      :2;
            __IO          uint32_t   :1;
            __IO uint32_t P18LVLSENB :1;
            __IO uint32_t RAMECCEN   :1;
            __IO uint32_t OVDIE      :1;
            __IO uint32_t VDDOVDSEL  :3;
            __IO uint32_t VDDOVDEN   :1;
            __IO uint32_t MONV12EN   :1;
            __IO uint32_t MONV18EN   :1;
            __IO          uint32_t   :1;
            __IO uint32_t MONV24EN   :1;
            __IO          uint32_t   :6;
            __IO uint32_t INTBUFEN   :1;
            __IO          uint32_t   :1;
            __IO uint32_t TSOE       :1;
            __IO uint32_t TSEN       :1;
            __IO uint32_t PVDWKEN    :1;
            __IO uint32_t BOREN      :1;
        } bits;
        __IO uint32_t reg;
    } CTL1;

    /* Offset:0x8  PM_STA0 */
    union
    {
        struct
        {
            __I uint32_t  LPRSTA   :1;
            __I uint32_t  LPRUNF   :1;
            __I           uint32_t :19;
            __I uint32_t  WWDTF    :1;
            __IO uint32_t BKPPORIF :1;
            __I uint32_t  NRSTIF   :1;
            __IO uint32_t PORIF    :1;
            __I uint32_t  WSRSTF   :1;
            __I uint32_t  BORF     :1;
            __I uint32_t  PORF     :1;
            __I uint32_t  WKPPINF  :1;
            __I uint32_t  RTCALRF  :1;
            __I uint32_t  IWDTF    :1;
            __IO uint32_t RSTFC    :1;
        } bits;
        __IO uint32_t reg;
    } STA0;

    /* Offset:0xc  PM_STA1 */
    union
    {
        struct
        {
            __I uint32_t PVDSTA      :1;
            __I          uint32_t    :10;
            __I uint32_t WKP6STA     :1;
            __I          uint32_t    :1;
            __I uint32_t WKP8STA     :1;
            __I          uint32_t    :1;
            __I uint32_t WKP10STA    :1;
            __I uint32_t WKP11STA    :1;
            __I uint32_t WKP12STA    :1;
            __I uint32_t STOPERROR   :1;
            __I uint32_t PMCERROR    :1;
            __I          uint32_t    :2;
            __I uint32_t POR18FINISH :1;
            __I uint32_t OVDIF       :1;
            __I          uint32_t    :2;
            __I uint32_t PMCIF       :1;
            __I uint32_t WKP1STA     :1;
            __I uint32_t WKP2STA     :1;
            __I uint32_t WKP3STA     :1;
            __I uint32_t WKP4STA     :1;
            __I uint32_t WKP5STA     :1;
        } bits;
        __IO uint32_t reg;
    } STA1;

    /* Offset:0x10  PM_STAC */
    union
    {
        struct
        {
            __IO          uint32_t :2;
            __IO uint32_t WKP6EN   :1;
            __IO          uint32_t :1;
            __IO uint32_t WKP8EN   :1;
            __IO          uint32_t :1;
            __IO uint32_t WKP10EN  :1;
            __IO uint32_t WKP11EN  :1;
            __IO uint32_t WKP12EN  :1;
            __IO uint32_t WKP6P    :1;
            __IO          uint32_t :1;
            __IO uint32_t WKP8P    :1;
            __IO          uint32_t :1;
            __IO uint32_t WKP10P   :1;
            __IO uint32_t WKP11P   :1;
            __IO uint32_t WKP12P   :1;
            __IO uint32_t WKP6SC   :1;
            __IO          uint32_t :1;
            __IO uint32_t WKP8SC   :1;
            __IO          uint32_t :1;
            __IO uint32_t WKP10SC  :1;
            __IO uint32_t WKP11SC  :1;
            __IO uint32_t WKP12SC  :1;
            __IO          uint32_t :2;
            __IO uint32_t OVDIC    :1;
            __IO uint32_t PMCIC    :1;
            __IO uint32_t WKP1SC   :1;
            __IO uint32_t WKP2SC   :1;
            __IO uint32_t WKP3SC   :1;
            __IO uint32_t WKP4SC   :1;
            __IO uint32_t WKP5SC   :1;
        } bits;
        __IO uint32_t reg;
    } STAC;

    /* Offset:0x14  PM_CTL2 */
    union
    {
        struct
        {
            __IO          uint32_t      :1;
            __IO uint32_t T0LPEN        :1;
            __IO uint32_t EWDTLPEN      :1;
            __IO uint32_t USART0LPEN    :1;
            __IO          uint32_t      :1;
            __IO uint32_t T0CLKLPEN     :1;
            __IO uint32_t EWDTCLKLPEN   :1;
            __IO uint32_t USART0CLKLPEN :1;
            __I           uint32_t      :4;
            __IO uint32_t TTSEL         :2;
            __IO uint32_t TTPRESEN      :1;
            __IO uint32_t TTWKPEN       :1;
            __IO          uint32_t      :1;
            __IO uint32_t GPIOALPEN     :1;
            __IO          uint32_t      :1;
            __IO uint32_t PMCIE         :1;
            __I           uint32_t      :2;
            __IO uint32_t WKP1P         :1;
            __IO uint32_t WKP2P         :1;
            __IO uint32_t WKP3P         :1;
            __IO uint32_t WKP4P         :1;
            __IO uint32_t WKP5P         :1;
            __IO uint32_t WKP1EN        :1;
            __IO uint32_t WKP2EN        :1;
            __IO uint32_t WKP3EN        :1;
            __IO uint32_t WKP4EN        :1;
            __IO uint32_t WKP5EN        :1;
        } bits;
        __IO uint32_t reg;
    } CTL2;

    /* Offset:0x18  PM_CAL0 */
    union
    {
        struct
        {
            __IO uint32_t STOP0_FLASH_SEL       :1;
            __IO uint32_t STOP0_FLASH_EN        :1;
            __IO          uint32_t              :3;
            __IO uint32_t BGTRIMMRLDO           :5;
            __IO uint32_t NRST0EN               :1;
            __IO          uint32_t              :19;
            __IO uint32_t ISMU_START_KEY_OUT_EN :2;
        } bits;
        __IO uint32_t reg;
    } CAL0;

    /* Offset:0x1c  PM_CAL1 */
    union
    {
        struct
        {
            __IO uint32_t LSETRIMNBIAS    :2;
            __IO uint32_t LSETRIMBIAS     :3;
            __IO          uint32_t        :1;
            __IO uint32_t TESTEN_KEY      :1;
            __IO uint32_t TEXT_EN         :1;
            __IO uint32_t SWAP_CAL        :1;
            __IO uint32_t MRTRIM          :2;
            __IO uint32_t FLASH_LDO_V_SEL :2;
            __IO uint32_t VDD_MON_EN      :1;
            __IO uint32_t VDD18_MON_EN    :1;
            __IO uint32_t HSESEL          :1;
            __IO uint32_t FLBGEN          :1;
            __IO uint32_t ZEROTISTRIM     :2;
            __IO uint32_t LSESEL          :1;
            __IO uint32_t LPTRIMBIAS      :3;
            __IO uint32_t SPCPUR          :1;
            __IO uint32_t LSITRIMCAP      :5;
            __IO uint32_t LSITRIMBIAS     :3;
        } bits;
        __IO uint32_t reg;
    } CAL1;

    /* Offset:0x20  PM_CAL2 */
    union
    {
        struct
        {
            __IO uint32_t MRDELAS              :2;
            __IO uint32_t VCOREDELAS           :2;
            __IO uint32_t LPRDELAS             :2;
            __IO uint32_t PMCOSCOFFTIMINGSEL   :1;
            __IO uint32_t PDMSEL               :1;
            __IO uint32_t STOPTEST             :1;
            __IO uint32_t POR12NODELAY         :1;
            __IO uint32_t DELAYUSEHSI          :1;
            __IO uint32_t PDM_LOAD_CLR_SEL     :1;
            __IO uint32_t ICSPCAL12EN          :1;
            __IO uint32_t ICSPCAL13EN          :1;
            __IO uint32_t NRST1EN              :1;
            __IO uint32_t IWDT_RST_FLASH_EN    :1;
            __IO uint32_t FlexCAN_RAM_SEL      :2;
            __IO uint32_t DPI_TESTEN           :1;
            __IO uint32_t STOP0PLL             :1;
            __IO uint32_t STANDBY0STOP1WAKEEN  :1;
            __IO uint32_t STANDBY0STOP1WAKESEL :1;
            __IO uint32_t CAPFREELDOIS         :2;
            __IO uint32_t LPR12CAPLESSI        :5;
            __IO uint32_t BORVREFSEL           :1;
            __IO uint32_t PMCWKPSEL            :1;
            __IO          uint32_t             :1;
        } bits;
        __IO uint32_t reg;
    } CAL2;

    /* Offset:0x24  PM_CAL3 */
    union
    {
        struct
        {
            __IO uint32_t FVRCLTTRIM       :8;
            __IO uint32_t BGTRIMFLLDO      :5;
            __IO uint32_t TRIM_BOR         :3;
            __IO uint32_t CRP_ADDR_SEL     :1;
            __IO uint32_t AES_RAM_WRITE_EN :1;
            __IO uint32_t VREF1VTRIM       :6;
            __IO uint32_t FLASHBGTRIM      :8;
        } bits;
        __IO uint32_t reg;
    } CAL3;

    /* Offset:0x28  PM_CAL4 */
    union
    {
        struct
        {
            __IO uint32_t WINDOW_SEL       :2;
            __IO uint32_t DROP_BIT_SEL     :2;
            __IO uint32_t VN_EN            :1;
            __IO uint32_t SEEED_SEL        :2;
            __IO uint32_t XOR_CHAIN_SEL    :3;
            __IO uint32_t HT_REPCNT_SEL    :3;
            __IO uint32_t HT_ADAPT_SEL     :2;
            __IO uint32_t HT_MARK_SEL      :2;
            __IO uint32_t TESTEN_RD_DFLASH :1;
            __IO uint32_t TESTEN_BUS       :1;
            __IO uint32_t StartupFlashLock :1;
            __IO uint32_t TESTEN_DMAREDO   :1;
            __IO uint32_t TESTEN_BKP       :1;
            __IO uint32_t TESTEN_USER      :1;
            __IO uint32_t TESTEN_ROMINT    :1;
            __IO uint32_t TESTEN_DMA       :1;
            __IO uint32_t TESTEN_RUNOUT    :1;
            __IO uint32_t TESTEN_FETCHOUT  :1;
            __IO uint32_t TESTEN_DFLASH    :1;
            __IO uint32_t IAP64MAK         :1;
            __IO uint32_t CACHEMAK         :1;
            __IO uint32_t DEBUGMASK        :1;
            __IO uint32_t STOP0SLEEPSEL    :1;
        } bits;
        __IO uint32_t reg;
    } CAL4;

    /* Offset:0x2c  PM_CTL3 */
    union
    {
        struct
        {
            __IO uint32_t ISMU_START_KEY :8;
            __IO uint32_t MODE_B         :1;
            __IO uint32_t MODE_A         :1;
            __IO uint32_t EN_COMP_VREF1V :1;
            __IO uint32_t POR18SHD       :1;
            __IO uint32_t VF12INF0       :1;
            __IO uint32_t VF12INF1       :1;
            __IO uint32_t VF12EN         :1;
            __IO uint32_t IWDTDBGEN      :1;
            __I uint32_t  LPRTYPE        :1;
            __IO uint32_t LPDEBUG        :1;
            __IO uint32_t BUFLVL18EN     :1;
            __IO uint32_t P18OE          :1;
            __IO uint32_t MEMSEL         :1;
            __IO uint32_t LPREN          :1;
            __IO uint32_t OCALLOCK       :1;
            __IO uint32_t REP_EN         :1;
            __IO uint32_t PDMDELAY       :2;
            __IO uint32_t ECC_RSA_DEBUG  :1;
            __IO uint32_t VCOREPD12SELB  :1;
            __IO uint32_t PORDELAYSEL    :1;
            __IO uint32_t LPBGON         :1;
            __IO uint32_t LDO18EN        :1;
            __IO uint32_t MRBGEN         :1;
        } bits;
        __IO uint32_t reg;
    } CTL3;

} Pm_RegisterMap_t;

/**
 * @brief Address of Pm register
 */
#define PM_ADDR ((uint32_t)0x40001580U)

/**
 * @brief Pointer to Pm register
 */
#define PM_PTR ((Pm_RegisterMap_t *)PM_ADDR)

/**
 * @brief Register map of Pm
 */
#define PM_RM (*(PM_PTR))

/**
 * @brief Module check assertion
 */
#define CHECK_PM_ALL_PERIPH_ADDR(Module) (((uint32_t)(Module) == (uint32_t)(PM_PTR)))

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
#endif /*End of KF32A158SF_PM_REG_H*/
/* EOF */
