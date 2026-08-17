/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a158sf_reg_ccp.h
 *  @Date            : 2025-07-03
 *  @Version         : {{VersionDate}}
 *  @Description     : This document describes the register definition of Gtimer
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
#ifndef KF32A158SF_REG_CCP_H
#define KF32A158SF_REG_CCP_H

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
#include "kf32a158sf_reg_gptimer.h"

/******************************************************************************
 *                      Macro
 ******************************************************************************/

/******************************************************************************
 **                     Typedef  Definitions
 ******************************************************************************/
typedef GeneralTimer_RegisterMap_t Ccp_RegisterMap_t;

/**
 * @brief Pointer to GeneralTimer register
 */
#define CCP0_PTR  ((Ccp_RegisterMap_t *)T0_ADDR)
#define CCP1_PTR  ((Ccp_RegisterMap_t *)T1_ADDR)
#define CCP2_PTR  ((Ccp_RegisterMap_t *)T2_ADDR)
#define CCP3_PTR  ((Ccp_RegisterMap_t *)T3_ADDR)
#define CCP4_PTR  ((Ccp_RegisterMap_t *)T4_ADDR)
#define CCP20_PTR ((Ccp_RegisterMap_t *)T20_ADDR)
#define CCP21_PTR ((Ccp_RegisterMap_t *)T21_ADDR)

/**
 * @brief Register map of GeneralTimer
 */
#define CCP0_RM  (*(T0_PTR))
#define CCP1_RM  (*(T1_PTR))
#define CCP2_RM  (*(T2_PTR))
#define CCP3_RM  (*(T3_PTR))
#define CCP4_RM  (*(T4_PTR))
#define CCP20_RM (*(T20_PTR))
#define CCP21_RM (*(T21_PTR))

/**
 * @brief Module check assertion
 */
#define CHECK_CCP_ALL_PERIPH_ADDR(Module)                                                                              \
    (((uint32_t)(Module) == (uint32_t)(CCP0_PTR)) || ((uint32_t)(Module) == (uint32_t)(CCP1_PTR)) ||                   \
     ((uint32_t)(Module) == (uint32_t)(CCP2_PTR)) || ((uint32_t)(Module) == (uint32_t)(CCP3_PTR)) ||                   \
     ((uint32_t)(Module) == (uint32_t)(CCP4_PTR)) || ((uint32_t)(Module) == (uint32_t)(CCP20_PTR)) ||                  \
     ((uint32_t)(Module) == (uint32_t)(CCP21_PTR)))

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
#endif /*End of KF32A158SF_REG_CCP_H*/
/* EOF */
