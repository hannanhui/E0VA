/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a158sf_reg_bkp.h
 *  @Date            : 2025-07-03
 *  @Version         : {{VersionDate}}
 *  @Description     : This document describes the register definition of Bkp
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
#ifndef KF32A158SF_REG_BKP_H
#define KF32A158SF_REG_BKP_H

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

    /* Offset:0x0  BKP_CTL */
    union
    {
        struct
        {
            __I           uint32_t :1;
            __IO uint32_t EXTHFBYP :1;
            __IO uint32_t EXTLFBYP :1;
            __IO uint32_t TAMPCLKS :1;
            __IO uint32_t SYNC     :1;
            __I           uint32_t :3;
            __IO uint32_t RTCCLKS  :2;
            __IO uint32_t RTCCLKTP :2;
            __I           uint32_t :4;
            __IO uint32_t TAMP1EN  :1;
            __IO uint32_t TAMP2EN  :1;
            __IO uint32_t TAMP3EN  :1;
            __I           uint32_t :1;
            __IO uint32_t TAMP1LVL :1;
            __IO uint32_t TAMP2LVL :1;
            __IO uint32_t TAMP3LVL :1;
            __I           uint32_t :8;
            __IO uint32_t BKPRST   :1;
        } bits;
        __IO uint32_t reg;
    } CTL;

    /* Offset:0x4  BKP_INT */
    union
    {
        struct
        {
            __IO uint32_t TAMP1IC  :1;
            __IO uint32_t TAMP2IC  :1;
            __IO uint32_t TAMP3IC  :1;
            __I           uint32_t :5;
            __IO uint32_t TAMP1IE  :1;
            __IO uint32_t TAMP2IE  :1;
            __IO uint32_t TAMP3IE  :1;
            __I           uint32_t :5;
            __I uint32_t  TAMP1IF  :1;
            __I uint32_t  TAMP2IF  :1;
            __I uint32_t  TAMP3IF  :1;
            __I           uint32_t :13;
        } bits;
        __IO uint32_t reg;
    } INT;

    __I uint32_t RESERVED_0x8[14];

    /* Offset:0x40  BKP_DATA */
    __IO uint32_t BKPDATA[16];

} Bkp_RegisterMap_t;

/**
 * @brief Address of Bkp register
 */
#define BKP_ADDR ((uint32_t)0x40001400U)

/**
 * @brief Pointer to Bkp register
 */
#define BKP_PTR ((Bkp_RegisterMap_t *)BKP_ADDR)

/**
 * @brief Register map of Bkp
 */
#define BKP_RM (*(BKP_PTR))

/**
 * @brief Module check assertion
 */
#define CHECK_BKP_ALL_PERIPH_ADDR(Module) (((uint32_t)(Module) == (uint32_t)(BKP_PTR)))

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
#endif /*End of KF32A158SF_REG_BKP_H*/
/* EOF */
