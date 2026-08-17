/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a158sf_reg_ewdt.h
 *  @Date            : 2025-07-03
 *  @Version         : {{VersionDate}}
 *  @Description     : This document describes the register definition of Ewdt
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
#ifndef KF32A158SF_REG_EWDT_H
#define KF32A158SF_REG_EWDT_H

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

    /* Offset:0x0  EWDT_CTL */
    union
    {
        struct
        {
            __IO uint32_t EWDTEN    :1;
            __IO uint32_t WT40IE    :1;
            __I uint32_t  WT40IF    :1;
            __IO uint32_t WPS       :5;
            __IO uint32_t WW        :7;
            __IO uint32_t WT40IC    :1;
            __IO uint32_t EWDTINEN  :1;
            __IO uint32_t EWDTINPOL :1;
            __IO uint32_t CLK       :2;
            __I           uint32_t  :1;
            __IO uint32_t EWDTRSTIE :1;
            __IO uint32_t EWDTRSTIC :1;
            __I uint32_t  EWDTRSTIF :1;
            __IO uint32_t OUTSEL    :1;
            __I           uint32_t  :7;
        } bits;
        __IO uint32_t reg;
    } CTL;

    /* Offset:0x4  EWDT_CNT */
    union
    {
        struct
        {
            __IO uint32_t WT       :7;
            __I           uint32_t :25;
        } bits;
        __IO uint32_t reg;
    } CNT;

} Ewdt_RegisterMap_t;

/**
 * @brief Address of Ewdt register
 */
#define EWDT_ADDR ((uint32_t)0x40002b00U)

/**
 * @brief Pointer to Ewdt register
 */
#define EWDT_PTR ((Ewdt_RegisterMap_t *)EWDT_ADDR)

/**
 * @brief Register map of Ewdt
 */
#define EWDT_RM (*(EWDT_PTR))

/**
 * @brief Module check assertion
 */
#define CHECK_EWDT_ALL_PERIPH_ADDR(Module) (((uint32_t)(Module) == (uint32_t)(EWDT_PTR)))

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
#endif /*End of KF32A158SF_REG_EWDT_H*/
/* EOF */
