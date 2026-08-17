/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a158sf_reg_rsa.h
 *  @Date            : 2025-07-03
 *  @Version         : {{VersionDate}}
 *  @Description     : This document describes the register definition of Rsa
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
#ifndef KF32A158SF_REG_RSA_H
#define KF32A158SF_REG_RSA_H

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

    /* Offset:0x0  RSA_CTL0 */
    union
    {
        struct
        {
            __IO uint32_t START_ECC   :1;
            __IO uint32_t START_RSA   :1;
            __IO uint32_t CLK_SEL     :2;
            __IO uint32_t LOCK_EN     :1;
            __I           uint32_t    :1;
            __IO uint32_t ENDIAN_SWAP :1;
            __IO uint32_t READ_SWAP   :1;
            __IO uint32_t SEL_RSA_LEN :2;
            __I           uint32_t    :22;
        } bits;
        __IO uint32_t reg;
    } CTL0;

    /* Offset:0x4  RSA_STATE */
    union
    {
        struct
        {
            __IO uint32_t ECC_DONE  :1;
            __IO uint32_t RSA_DONE  :1;
            __IO uint32_t ERROR     :2;
            __IO uint32_t LOCK_FLAG :1;
            __I           uint32_t  :27;
        } bits;
        __IO uint32_t reg;
    } STATE;

    /* Offset:0x8  RSA_ENABLE */
    union
    {
        struct
        {
            __IO uint32_t ECC_DONE_EN :1;
            __IO uint32_t RSA_DONE_EN :1;
            __IO uint32_t ERROR_EN    :2;
            __I           uint32_t    :28;
        } bits;
        __IO uint32_t reg;
    } ENABLE;

    /* Offset:0xc  RSA_CLR */
    union
    {
        struct
        {
            __IO uint32_t ECC_DONE_CLR :1;
            __IO uint32_t RSA_DONE_CLR :1;
            __IO uint32_t ERROR_CLR    :2;
            __I           uint32_t     :28;
        } bits;
        __IO uint32_t reg;
    } CLR;

    /* Offset:0x10  RSA_K0 */
    __IO uint32_t KVALUE[8];

    /* Offset:0x30  RSA_ADDR */
    union
    {
        struct
        {
            __IO uint32_t ADDRESS_REP :9;
            __I           uint32_t    :23;
        } bits;
        __IO uint32_t reg;
    } ADDR;

    /* Offset:0x34  RSA_DEBUG */
    union
    {
        struct
        {
            __IO uint32_t DEBUG    :1;
            __I           uint32_t :31;
        } bits;
        __IO uint32_t reg;
    } DEBUG;

    /* Offset:0x38  RSA_TESTEN */
    union
    {
        struct
        {
            __IO uint32_t ECC_RSA_TEST :1;
            __IO uint32_t TEST_EN      :1;
            __I           uint32_t     :30;
        } bits;
        __IO uint32_t reg;
    } TESTEN;
} Rsa_RegisterMap_t;

/**
 * @brief Address of Rsa register
 */
#define RSA_ADDR ((uint32_t)0x40008800U)

/**
 * @brief RAM Address of RSA input and output
 */
#define RSA_MODULUS_ADDR  ((uint32_t)0x40008180U)
#define RSA_MESSAGE_ADDR  ((uint32_t)0x40008400U)
#define RSA_EXPONENT_ADDR ((uint32_t)0x40008580U)
#define RSA_RESULT_ADDR   ((uint32_t)0x40008000U)

/**
 * @brief RAM Address of ECC input and output
 */
#define ECC_MODULUS_ADDR      ((uint32_t)0x40008420U)
#define ECC_CONSTANT_A_ADDR   ((uint32_t)0x400084A0U)
#define ECC_COORDINATE_X_ADDR ((uint32_t)0x40008440U)
#define ECC_COORDINATE_Y_ADDR ((uint32_t)0x40008460U)
#define ECC_COORDINATE_Z_ADDR ((uint32_t)0x40008480U)

/**
 * @brief Pointer to Rsa register
 */
#define RSA_PTR ((Rsa_RegisterMap_t *)RSA_ADDR)

/**
 * @brief Register map of Rsa
 */
#define RSA_RM (*(RSA_PTR))

/**
 * @brief Module check assertion
 */
#define CHECK_RSA_ALL_PERIPH_ADDR(Module) (((uint32_t)(Module) == (uint32_t)(RSA_PTR)))

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
#endif /*End of KF32A158SF_RSA_REG_H*/
/* EOF */
