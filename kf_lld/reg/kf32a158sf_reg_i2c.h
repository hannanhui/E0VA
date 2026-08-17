/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a158sf_reg_i2c.h
 *  @Date            : 2025-07-03
 *  @Version         : {{VersionDate}}
 *  @Description     : This document describes the register definition of I2c
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
#ifndef KF32A158SF_REG_I2C_H
#define KF32A158SF_REG_I2C_H

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

    /* Offset:0x0  I2C_CTL */
    union
    {
        struct
        {
            __IO uint32_t I2CEN    :1;
            __IO uint32_t BADR10   :1;
            __I           uint32_t :2;
            __IO uint32_t DHCNT    :4;
            __IO uint32_t SEN      :1;
            __I           uint32_t :1;
            __IO uint32_t PEN      :1;
            __IO uint32_t SCLNOSTR :1;
            __IO uint32_t ACKEN    :1;
            __IO uint32_t ACKDT    :1;
            __IO uint32_t GCEN     :1;
            __I           uint32_t :1;
            __IO uint32_t I2CCKS   :2;
            __IO uint32_t I2CCKDIV :2;
            __IO uint32_t MTHALL   :1;
            __IO uint32_t ENASCL   :1;
            __IO uint32_t MENA     :1;
            __I           uint32_t :1;
            __IO uint32_t SMBUS    :1;
            __IO uint32_t SMBT     :1;
            __IO uint32_t ARPEN    :1;
            __IO uint32_t ALERT    :1;
            __I           uint32_t :3;
            __I uint32_t  ADRL     :1;
        } bits;
        __IO uint32_t reg;
    } CTL;

    /* Offset:0x4  I2C_SR */
    union
    {
        struct
        {
            __IO uint32_t SIF      :1;
            __IO uint32_t PIF      :1;
            __I uint32_t  ADDR     :1;
            __I uint32_t  ADD10    :1;
            __I uint32_t  DATA     :1;
            __IO uint32_t AFIF     :1;
            __IO uint32_t ARBLIF   :1;
            __I uint32_t  RNW      :1;
            __IO uint32_t SMBAIF   :1;
            __IO uint32_t SMBHIF   :1;
            __IO uint32_t SMBDIF   :1;
            __IO uint32_t ISIF     :1;
            __I uint32_t  RCBF     :1;
            __I uint32_t  TXBE     :1;
            __I           uint32_t :1;
            __I uint32_t  BLTF     :1;
            __I uint32_t  IRCDF    :1;
            __I uint32_t  ITXDF    :1;
            __IO uint32_t BERRIF   :1;
            __IO uint32_t OVERIF   :1;
            __I uint32_t  BUSY     :1;
            __I           uint32_t :11;
        } bits;
        __IO uint32_t reg;
    } SR;

    /* Offset:0x8  I2C_BUFR */
    union
    {
        struct
        {
            __IO uint32_t I2CBUF   :10;
            __I           uint32_t :22;
        } bits;
        __IO uint32_t reg;
    } BUFR;

    /* Offset:0xc  I2C_ADDR0 */
    union
    {
        struct
        {
            __IO uint32_t I2CADD   :10;
            __I           uint32_t :6;
            __IO uint32_t I2CMSK   :10;
            __I           uint32_t :6;
        } bits;
        __IO uint32_t reg;
    } ADDR0;

    /* Offset:0x10  I2C_BRGR */
    union
    {
        struct
        {
            __IO uint32_t I2CBRGH :16;
            __IO uint32_t I2CBRGL :16;
        } bits;
        __IO uint32_t reg;
    } BRGR;

    /* Offset:0x14  I2C_ADDR1~3 */
    union
    {
        struct
        {
            __IO uint32_t I2CADD   :10;
            __I           uint32_t :6;
            __IO uint32_t I2CMSK   :10;
            __I           uint32_t :6;
        } bits;
        __IO uint32_t reg;
    } ADDR[3];

    /* Offset:0x20  I2C_IER */
    union
    {
        struct
        {
            __IO uint32_t SIE      :1;
            __IO uint32_t PIE      :1;
            __I           uint32_t :2;
            __IO uint32_t BUSYIC   :1;
            __IO uint32_t AFIE     :1;
            __IO uint32_t ARBLIE   :1;
            __I           uint32_t :1;
            __IO uint32_t SMBAIE   :1;
            __IO uint32_t SMBHIE   :1;
            __IO uint32_t SMBDIE   :1;
            __IO uint32_t ISIE     :1;
            __I           uint32_t :2;
            __IO uint32_t SDATEN   :1;
            __IO uint32_t BLTIE    :1;
            __IO uint32_t IRCDE    :1;
            __IO uint32_t ITXDE    :1;
            __IO uint32_t BERRIE   :1;
            __IO uint32_t OVERIE   :1;
            __IO uint32_t BUSLOW   :12;
        } bits;
        __IO uint32_t reg;
    } IER;

    __I uint32_t RESERVED_0x24;

    /* Offset:0x28  I2C_FILTER */
    union
    {
        struct
        {
            __IO uint32_t SDAFEN    :1;
            __IO uint32_t SDAFDIV   :4;
            __IO uint32_t SDAFDELAY :3;
            __IO uint32_t SCLFEN    :1;
            __IO uint32_t SCLFDIV   :4;
            __IO uint32_t SCLFDELAY :3;
            __I           uint32_t  :16;
        } bits;
        __IO uint32_t reg;
    } FILTER;

} I2c_RegisterMap_t;

/**
 * @brief Address of I2c register
 */
#define I2C0_ADDR ((uint32_t)0x40000d00U)
#define I2C1_ADDR ((uint32_t)0x40000d80U)
#define I2C2_ADDR ((uint32_t)0x40000e00U)

/**
 * @brief Pointer to I2c register
 */
#define I2C0_PTR ((I2c_RegisterMap_t *)I2C0_ADDR)
#define I2C1_PTR ((I2c_RegisterMap_t *)I2C1_ADDR)
#define I2C2_PTR ((I2c_RegisterMap_t *)I2C2_ADDR)

/**
 * @brief Register map of I2c
 */
#define I2C0_RM (*(I2C0_PTR))
#define I2C1_RM (*(I2C1_PTR))
#define I2C2_RM (*(I2C2_PTR))

/**
 * @brief Module check assertion
 */
#define CHECK_I2C_ALL_PERIPH_ADDR(Module)                                                                              \
    (((uint32_t)(Module) == (uint32_t)(I2C0_PTR)) || ((uint32_t)(Module) == (uint32_t)(I2C1_PTR)) ||                   \
     ((uint32_t)(Module) == (uint32_t)(I2C2_PTR)))

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
#endif /*End of KF32A158SF_I2C_REG_H*/
/* EOF */
