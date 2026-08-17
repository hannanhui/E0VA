/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a158sf_reg_ecc.h
 *  @Date            : 2025-07-03
 *  @Version         : {{VersionDate}}
 *  @Description     : This document describes the register definition of Ecc
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
#ifndef KF32A158SF_REG_ECC_H
#define KF32A158SF_REG_ECC_H

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
    /* Offset:0x0  ECC_CTL */
    union
    {
        struct
        {
            __IO uint32_t ECCTESTEN    :1;
            __I           uint32_t     :7;
            __IO uint32_t MEMERRIE     :1;
            __IO uint32_t MEM1BITERRIE :1;
            __IO uint32_t MEM2BITERRIE :1;
            __I           uint32_t     :1;
            __IO uint32_t MEMERRIC     :1;
            __IO uint32_t MEM1BITERRIC :1;
            __IO uint32_t MEM2BITERRIC :1;
            __I           uint32_t     :17;
        } bits;
        __IO uint32_t reg;
    } CTL;

    /* Offset:0x4  ECC_INT */
    union
    {
        struct
        {
            __I uint32_t MEMERRIF     :1;
            __I uint32_t MEM1BITERRIF :1;
            __I uint32_t MEM2BITERRIF :1;
            __I          uint32_t     :29;
        } bits;
        __IO uint32_t reg;
    } INT;

    /* Offset:0x8  ECC_ERRADDR */
    __I uint32_t ERRADDR;

    __I uint32_t RESERVED_0xc;

    /* Offset:0x10  ECC_EBR0 */
    __IO uint32_t EBR[3];

} Ecc_RegisterMap_t;

/**
 * @brief Address of Ecc register
 */
#define ECC0_ADDR  ((uint32_t)0x40004f00U)
#define ECC1_ADDR  ((uint32_t)0x40004f80U)
#define ECC4_ADDR  ((uint32_t)0x40004a00U)
#define ECC5_ADDR  ((uint32_t)0x40004a80U)
#define ECC14_ADDR ((uint32_t)0x40005780U)
#define ECC19_ADDR ((uint32_t)0x40005100U)

/**
 * @brief Pointer to Ecc register
 */
#define ECC0_PTR  ((Ecc_RegisterMap_t *)ECC0_ADDR)
#define ECC1_PTR  ((Ecc_RegisterMap_t *)ECC1_ADDR)
#define ECC4_PTR  ((Ecc_RegisterMap_t *)ECC4_ADDR)
#define ECC5_PTR  ((Ecc_RegisterMap_t *)ECC5_ADDR)
#define ECC14_PTR ((Ecc_RegisterMap_t *)ECC14_ADDR)
#define ECC19_PTR ((Ecc_RegisterMap_t *)ECC19_ADDR)

/**
 * @brief Register map of Ecc
 */
#define ECC0_RM  (*(ECC0_PTR))
#define ECC1_RM  (*(ECC1_PTR))
#define ECC4_RM  (*(ECC4_PTR))
#define ECC5_RM  (*(ECC5_PTR))
#define ECC14_RM (*(ECC14_PTR))
#define ECC19_RM (*(ECC19_PTR))

/**
 * @brief Module check assertion
 */
#define CHECK_ECC_ALL_PERIPH_ADDR(Module)                                                                              \
    (((uint32_t)(Module) == (uint32_t)(ECC0_PTR)) || ((uint32_t)(Module) == (uint32_t)(ECC1_PTR)) ||                   \
     ((uint32_t)(Module) == (uint32_t)(ECC4_PTR)) || ((uint32_t)(Module) == (uint32_t)(ECC5_PTR)) ||                   \
     ((uint32_t)(Module) == (uint32_t)(ECC14_PTR)) || ((uint32_t)(Module) == (uint32_t)(ECC19_PTR)))

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
#endif /*End of KF32A158SF_REG_ECC_H*/
/* EOF */
