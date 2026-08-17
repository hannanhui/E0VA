/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a158sf_reg_flash.h
 *  @Date            : 2025-07-03
 *  @Version         : {{VersionDate}}
 *  @Description     : This document describes the register definition of Flash
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
#ifndef KF32A158SF_REG_FLASH_H
#define KF32A158SF_REG_FLASH_H

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

    /* Offset:0x0  FLASH_ISPCON0 */
    union
    {
        struct
        {
            __IO uint32_t NVMLOCK   :1;
            __IO uint32_t FLASHLOCK :1;
            __IO uint32_t CFGLOCK   :1;
            __I           uint32_t  :1;
            __IO uint32_t IFEN      :1;
            __IO uint32_t STANDBY1  :1;
            __I           uint32_t  :1;
            __IO uint32_t USERLOCK  :1;
            __IO uint32_t DFLOCK    :1;
            __IO uint32_t PFLOCK    :1;
            __IO uint32_t PF2LOCK   :1;
            __I           uint32_t  :1;
            __IO uint32_t KEYLOCK   :1;
            __I           uint32_t  :3;
            __IO uint32_t Lock      :16;
        } bits;
        __IO uint32_t reg;
    } ISPCON0;

    /* Offset:0x4  FLASH_ISPCON1 */
    union
    {
        struct
        {
            __IO uint32_t IPSEL    :1;
            __IO uint32_t RECALLEN :1;
            __IO uint32_t CONFEN   :1;
            __I           uint32_t :7;
            __IO uint32_t MASE_EN  :1;
            __I           uint32_t :4;
            __IO uint32_t CHIPONEN :1;
            __IO uint32_t Lock     :16;
        } bits;
        __IO uint32_t reg;
    } ISPCON1;

    /* Offset:0x8  FLASH_ISPCMD */
    union
    {
        struct
        {
            __IO uint32_t CMD      :5;
            __IO uint32_t WSIZE    :6;
            __I           uint32_t :21;
        } bits;
        __IO uint32_t reg;
    } ISPCMD;

    /* Offset:0xc  FLASH_ISPTRG */
    union
    {
        struct
        {
            __IO uint32_t ISPGO    :1;
            __I           uint32_t :15;
            __IO uint32_t Lock     :16;
        } bits;
        __IO uint32_t reg;
    } ISPTRG;

    __I uint32_t RESERVED_0x10;

    /* Offset:0x14  FLASH_CFG */
    union
    {
        struct
        {
            __IO uint32_t TCFG       :4;
            __I           uint32_t   :2;
            __IO uint32_t PREFETCHEN :1;
            __IO uint32_t ECCREADEN  :1;
            __IO uint32_t FPREAEDEN  :1;
            __I           uint32_t   :23;
        } bits;
        __IO uint32_t reg;
    } CFG;

    /* Offset:0x18  FLASH_USERUNLOCK */
    __IO uint32_t USERUNLOCK;

    /* Offset:0x1c  FLASH_ISPADDR */
    union
    {
        struct
        {
            __I           uint32_t :3;
            __IO uint32_t SADDR    :19;
            __I           uint32_t :2;
            __IO uint32_t FLCS     :1;
            __IO          uint32_t :7;
        } bits;
        __IO uint32_t reg;
    } ISPADDR;

    /* Offset:0x20  FLASH_STATE */
    union
    {
        struct
        {
            __IO uint32_t CFGERROR :1;
            __IO uint32_t SIGDONE  :1;
            __IO uint32_t TBIT     :1;
            __IO uint32_t TBUSY    :1;
            __I uint32_t  A_BUSY   :1;
            __I uint32_t  B_BUSY   :1;
            __I uint32_t  D_BUSY   :1;
            __IO uint32_t ABUSY_IE :1;
            __IO uint32_t BBUSY_IE :1;
            __IO uint32_t ABUSY_IC :1;
            __IO uint32_t BBUSY_IC :1;
            __I           uint32_t :1;
            __IO uint32_t DDBG     :1;
            __IO uint32_t BDBGREM  :1;
            __I           uint32_t :18;
        } bits;
        __IO uint32_t reg;
    } STATE;

    __I uint32_t RESERVED_0x24;

    /* Offset:0x28  FLASH_NVMUNLOCK */
    __IO uint32_t NVMUNLOCK;

    /* Offset:0x2c  FLASH_PROUNLOCK */
    __IO uint32_t PROUNLOCK;

    /* Offset:0x30  FLASH_KEYUNLOCK */
    __IO uint32_t KEYUNLOCK;

    /* Offset:0x31  FLASH_CHIPONLOCK */
    __IO uint32_t CHIPONLOCK;

    /* Offset:0x38  FLASH_CSSTART */
    union
    {
        struct
        {
            __I           uint32_t :4;
            __IO uint32_t CKSTADDR :17;
            __I           uint32_t :11;
        } bits;
        __IO uint32_t reg;
    } CSSTART;

    /* Offset:0x3c  FLASH_CSSTOP */
    union
    {
        struct
        {
            __I           uint32_t :4;
            __IO uint32_t CKSPADDR :17;
            __I           uint32_t :10;
            __IO uint32_t SIGGO    :1;
        } bits;
        __IO uint32_t reg;
    } CSSTOP;

    /* Offset:0x40  FLASH_CSRES0 */
    __IO uint32_t CSRES0;

    /* Offset:0x44  FLASH_CSRES1 */
    __IO uint32_t CSRES1;

    /* Offset:0x48  FLASH_CSRES2 */
    __IO uint32_t CSRES2;

    /* Offset:0x4c  FLASH_CSRES3 */
    __IO uint32_t CSRES3;

    /* Offset:0x50  FLASH_DEBUG */
    union
    {
        struct
        {
            __I uint32_t  SERA_CNT    :11;
            __IO uint32_t EN_SERACNT  :1;
            __I uint32_t  NOSERA      :1;
            __I uint32_t  PROG_CNT    :11;
            __IO uint32_t EN_PROGCNT  :1;
            __I uint32_t  NOPROG      :1;
            __I uint32_t  SERAFKIC    :1;
            __I uint32_t  PROGFKIC    :1;
            __I uint32_t  SERAFKIE    :1;
            __I uint32_t  PROGFKIE    :1;
            __I uint32_t  SERA_FIRSTK :1;
            __I uint32_t  PROG_FIRSTK :1;
        } bits;
        __IO uint32_t reg;
    } DEBUG;

} Flash_RegisterMap_t;

typedef volatile struct
{
    /* Offset:0x00  FRMCTLR */
    union
    {
        struct
        {
            __IO uint32_t FRMPEN   :1;
            __IO          uint32_t :7;
            __IO uint32_t FPRUNEN  :1;
            __IO          uint32_t :23;
        } bits;
        __IO uint32_t reg;
    } FRMCTL;

    /* Offset:0x04  FRMLOCKR */
    __IO uint32_t FRMLOCK;

    /* Offset:0x08  FRMKEY */
    __IO uint32_t FRMKEY;

    __I uint32_t RESERVED_0x0C[53];

    /* Offset:0xE0  FBSWCTLR */
    union
    {
        struct
        {
            __IO uint32_t FBSWS    :1;
            __IO          uint32_t :31;
        } bits;
        __IO uint32_t reg;
    } SWCTL;

} FlashRedundant_RegisterMap_t;

/**
 * @brief Address of Flash register
 */
#define FLASH_ADDR ((uint32_t)0x40200100U)

/**
 * @brief Pointer to Flash register
 */
#define FLASH_PTR ((Flash_RegisterMap_t *)FLASH_ADDR)

/**
 * @brief Register map of Flash
 */
#define FLASH_RM (*(FLASH_PTR))

/**
 * @brief Module check assertion
 */
#define CHECK_FLASH_ALL_PERIPH_ADDR(Module) (((uint32_t)(Module) == (uint32_t)(FLASH_PTR)))

/**
 * @brief Address of Flash register
 */
#define FLASH_REDUNDANT_ADDR ((uint32_t)0x40005900U)

/**
 * @brief Pointer to Flash register
 */
#define FLASH_REDUNDANT_PTR ((FlashRedundant_RegisterMap_t *)FLASH_REDUNDANT_ADDR)

/**
 * @brief Register map of Flash
 */
#define FLASH_REDUNDANT_RM (*(FLASH_REDUNDANT_PTR))

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
#endif /*End of KF32A158SF_REG_FLASH_H*/
/* EOF */
