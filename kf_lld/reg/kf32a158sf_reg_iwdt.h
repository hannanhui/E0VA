/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a158sf_reg_iwdt.h
 *  @Date            : 2025-07-03
 *  @Version         : {{VersionDate}}
 *  @Description     : This document describes the register definition of Iwdt
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
#ifndef KF32A158SF_REG_IWDT_H
#define KF32A158SF_REG_IWDT_H

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

    /* Offset:0x0  IWDT_CTL */
    union
    {
        struct
        {
            __IO uint32_t IWDTPS   :4;
            __IO uint32_t IWDTOVF  :12;
            __I           uint32_t :13;
            __IO uint32_t CLKS     :1;
            __IO          uint32_t :1;
            __IO uint32_t IWDTEN   :1;
        } bits;
        __IO uint32_t reg;
    } CTL;

    /* Offset:0x4  IWDT_FD */
    union
    {
        struct
        {
            __O uint32_t IWDTFD :32;
        } bits;
        __IO uint32_t reg;
    } FD;

} Iwdt_RegisterMap_t;

/**
 * @brief Address of Iwdt register
 */
#define IWDT_ADDR ((uint32_t)0x40001200U)

/**
 * @brief Pointer to Iwdt register
 */
#define IWDT_PTR ((Iwdt_RegisterMap_t *)IWDT_ADDR)

/**
 * @brief Register map of Iwdt
 */
#define IWDT_RM (*(IWDT_PTR))

/**
 * @brief Module check assertion
 */
#define CHECK_IWDT_ALL_PERIPH_ADDR(Module) (((uint32_t)(Module) == (uint32_t)(IWDT_PTR)))

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
#endif /*End of KF32A158SF_IWDT_REG_H*/
/* EOF */
