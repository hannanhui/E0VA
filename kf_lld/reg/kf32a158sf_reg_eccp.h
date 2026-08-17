/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a158sf_reg_eccp.h
 *  @Date            : 2025-07-03
 *  @Version         : {{VersionDate}}
 *  @Description     : This document describes the register definition of Eccp
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
#ifndef KF32A158SF_REG_ECCP_H
#define KF32A158SF_REG_ECCP_H

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
#include "kf32a158sf_reg_atimer.h"

/******************************************************************************
 *                      Macro
 ******************************************************************************/

/******************************************************************************
 **                     Typedef  Definitions
 ******************************************************************************/
typedef AdvancedTimer_RegisterMap_t Eccp_RegisterMap_t;

/**
 * @brief Pointer to Eccp register
 */
#define ECCP5_PTR ((Eccp_RegisterMap_t *)T5T6_ADDR)
#define ECCP9_PTR ((Eccp_RegisterMap_t *)T9T10_ADDR)

/**
 * @brief Register map of Eccp
 */
#define ECCP5_RM (*(ECCP5_PTR))
#define ECCP9_RM (*(ECCP9_PTR))

/**
 * @brief Module check assertion
 */
#define CHECK_ECCP_ALL_PERIPH_ADDR(Module)                                                                             \
    (((uint32_t)(Module) == (uint32_t)(ECCP5_PTR)) || ((uint32_t)(Module) == (uint32_t)(ECCP9_PTR)))

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
#endif /*End of KF32A158SF_REG_ECCP_H*/
/* EOF */
