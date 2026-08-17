/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a158sf_reg_cache.h
 *  @Date            : 2025-07-03
 *  @Version         : {{VersionDate}}
 *  @Description     : This document describes the register definition of CACHE
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
#ifndef KF32A158SF_REG_CACHE_H
#define KF32A158SF_REG_CACHE_H

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

/**
 * @brief Cache register map
 */
typedef volatile struct
{

    /* Offset:0x0  CACHE_CTL */
    union
    {
        struct
        {
            __IO uint32_t CACHEEN   :1;
            __IO uint32_t CACHERST  :1;
            __IO uint32_t ICWR2LEN  :1;
            __IO uint32_t ICRD2LEN  :1;
            __IO uint32_t CECCEN    :1;
            __I           uint32_t  :6;
            __IO uint32_t CACHETEN  :1;
            __IO uint32_t BUSTEN    :1;
            __IO uint32_t BUSTSTART :1;
            __IO uint32_t BUSTMODE  :1;
            __IO uint32_t BUSTD0    :1;
            __IO uint32_t BUSTD1    :1;
            __I uint32_t  BUSRERR   :1;
            __I uint32_t  BUSWERR   :1;
            __I           uint32_t  :13;
        } bits;
        __IO uint32_t reg;
    } CTL;

} Cache_RegisterMap_t;

/**
 * @brief Address of Cache register
 */
#define CACHE_ADDR ((uint32_t)0x402000c0U)

/**
 * @brief Pointer to Cache register
 */
#define CACHE_PTR ((Cache_RegisterMap_t *)CACHE_ADDR)

/**
 * @brief Register map of Cache
 */
#define CACHE_RM (*(CACHE_PTR))

/**
 * @brief Module check assertion
 */
#define CHECK_CACHE_ALL_PERIPH_ADDR(Module) (((uint32_t)(Module) == (uint32_t)(CACHE_PTR)))

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
#endif /*End of KF32A158SF_REG_CACHE_H*/
/* EOF */
