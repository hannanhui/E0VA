/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a158sf_reg_flexmux.h
 *  @Date            : 2025-07-03
 *  @Version         : {{VersionDate}}
 *  @Description     : This document describes the register definition of Flexmux
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
#ifndef KF32A158SF_REG_FLEXMUX_H
#define KF32A158SF_REG_FLEXMUX_H

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

    /* Offset:0x0  FLEXMUX_SOU */
    union
    {
        struct
        {
            __IO uint32_t SEL1  :7;
            __IO uint32_t CH1EN :1;
            __IO uint32_t SEL2  :7;
            __IO uint32_t CH2EN :1;
            __IO uint32_t SEL3  :7;
            __IO uint32_t CH3EN :1;
            __IO uint32_t SEL4  :7;
            __IO uint32_t CH4EN :1;
        } bits;
        __IO uint32_t reg;
    } SOU;

    /* Offset:0x4  FLEXMUX_TAR */
    union
    {
        struct
        {
            __IO uint32_t FMUXEN   :1;
            __IO uint32_t CH1DE    :1;
            __IO uint32_t CH2DE    :1;
            __IO uint32_t CH3DE    :1;
            __IO uint32_t CH4DE    :1;
            __IO uint32_t CH1DIV   :2;
            __IO uint32_t CH2DIV   :2;
            __IO uint32_t CH3DIV   :2;
            __IO uint32_t CH4DIV   :2;
            __IO uint32_t CH1SEL   :2;
            __IO uint32_t CH2SEL   :2;
            __IO uint32_t CH3SEL   :2;
            __IO uint32_t CH4SEL   :2;
            __IO uint32_t TCKS     :2;
            __I           uint32_t :9;
        } bits;
        __IO uint32_t reg;
    } TAR;

} Flexmux_RegisterMap_t;

/**
 * @brief Address of Flexmux register
 */
#define FLEXMUX_ADDR ((uint32_t)0x40002d00U)

/**
 * @brief Pointer to Flexmux register
 */
#define FLEXMUX_PTR ((Flexmux_RegisterMap_t *)FLEXMUX_ADDR)

/**
 * @brief Register map of Flexmux
 */
#define FLEXMUX_RM (*(FLEXMUX_PTR))

/**
 * @brief Module check assertion
 */
#define CHECK_FLEXMUX_ALL_PERIPH_ADDR(Module) (((uint32_t)(Module) == (uint32_t)(FLEXMUX_PTR)))

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
#endif /*End of KF32A158SF_REG_FLEXMUX_H*/
/* EOF */
