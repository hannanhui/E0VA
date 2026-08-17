/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a158sf_reg_aes.h
 *  @Date            : 2025-07-03
 *  @Version         : {{VersionDate}}
 *  @Description     : This document describes the register definition of Aes
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
#ifndef KF32A158SF_REG_AES_H
#define KF32A158SF_REG_AES_H

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

    /* Offset:0x0  AES_CTL */
    union
    {
        struct
        {
            __IO uint32_t AESEN    :1;
            __IO uint32_t UNSTDAES :1;
            __IO uint32_t ENCRYPT  :1;
            __IO uint32_t SBOXINV  :1;
            __IO uint32_t KEYLEN   :3;
            __I           uint32_t :1;
            __IO uint32_t RNDNUM   :5;
            __IO uint32_t DIV      :3;
            __IO uint32_t CKS      :2;
            __IO uint32_t DATASWAP :2;
            __IO uint32_t AESMOD   :3;
            __IO uint32_t GCMPH    :2;
            __I           uint32_t :5;
            __IO uint32_t KEYRUN   :1;
            __IO uint32_t AESRUN   :1;
        } bits;
        __IO uint32_t reg;
    } CTL;

    /* Offset:0x4  AES_INT */
    union
    {
        struct
        {
            __IO uint32_t AESIE    :1;
            __IO uint32_t KEYIE    :1;
            __I           uint32_t :2;
            __O uint32_t  AESIC    :1;
            __O uint32_t  KEYIC    :1;
            __I           uint32_t :2;
            __I uint32_t  AESIF    :1;
            __I uint32_t  KEYIF    :1;
            __I           uint32_t :22;
        } bits;
        __IO uint32_t reg;
    } INT;

    __I uint32_t RESERVED_0x8[2];

    /* Offset:0x10  AES_INPUT */
    __IO uint32_t INPUT[4];

    /* Offset:0x20  AES_OUTPUT */
    __I uint32_t OUTPUT[4];

    /* Offset:0x30  AES_KEYR */
    __O uint32_t KEYR[8];

    /* Offset:0x50  AES_IVR */
    __IO uint32_t IVR[4];

    /* Offset:0x60  AES_SUSR */
    __IO uint32_t SUSR[8];

    /* Offset:0x80  AES_MASK */
    __IO uint32_t MASK[4];

} Aes_RegisterMap_t;

/**
 * @brief Address of Aes register
 */
#define AES_ADDR ((uint32_t)0x40002700U)

/**
 * @brief Pointer to Aes register
 */
#define AES_PTR ((Aes_RegisterMap_t *)AES_ADDR)

/**
 * @brief Register map of Aes
 */
#define AES_RM (*(AES_PTR))

/**
 * @brief Module check assertion
 */
#define CHECK_AES_ALL_PERIPH_ADDR(Module) (((uint32_t)(Module) == (uint32_t)(AES_PTR)))

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
#endif /*End of KF32A158SF_REG_AES_H*/
/* EOF */
