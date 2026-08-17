/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a158sf_reg_ismu.h
 *  @Date            : 2025-07-03
 *  @Version         : {{VersionDate}}
 *  @Description     : This document describes the register definition of Ismu
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
#ifndef KF32A158SF_REG_ISMU_H
#define KF32A158SF_REG_ISMU_H

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

/* Typedef of ISMU instruction */
typedef volatile struct
{
    union
    {
        struct
        {
            __IO uint32_t FuncId     :5;
            __IO uint32_t Reserved   :2;
            __IO uint32_t FuncFormat :1;
            /* bit offset: 8 */
            __IO uint32_t CallSequence :8;
            /* bit offset: 16 */
            __IO uint32_t MacLength :8;
            /* bit offset: 24 */
            __IO uint32_t KeyId :8;
        } bits;
        __IO uint32_t reg;
    } Command;
    /* offset: 0x04 */
    __IO uint32_t MsgLength;
    /* offset: 0x08 */
    __IO uint32_t FlashAddr;
    /* offset: 0x0C */
    __IO uint32_t ErrorCode;
} Ismu_Instruction_t;

/* ISMU DPRAM start address */
#define ISMU_RAM_ADDR    ((uint32_t)0x1FFED400U)
#define ISMU_INSTRUCTION (*(Ismu_Instruction_t *)ISMU_RAM_ADDR)

/* ISMU data buffer address */
#define ISMU_BUFFER_ADDR ((uint32_t)0x1FFED410U)
#define ISMU_BUF_PTR     ((uint32_t *)ISMU_BUFFER_ADDR)

typedef volatile struct
{

    /* Offset:0x0  ISMU_STA */
    union
    {
        struct
        {
            __I uint32_t BUSY      :1;
            __I uint32_t BSTA      :1;
            __I uint32_t BINIT     :1;
            __I uint32_t BFN       :1;
            __I uint32_t BOK       :1;
            __I uint32_t RNGINIT   :1;
            __I uint32_t EDB       :1;
            __I uint32_t IDB       :1;
            __I uint32_t INITFIN   :1;
            __I uint32_t DEBCHAFIN :1;
            __I          uint32_t  :22;
        } bits;
        __IO uint32_t reg;
    } STA;

    /* Offset:0x4  ISMU_INT */
    union
    {
        struct
        {
            __I uint32_t  CMDIF    :1;
            __I           uint32_t :7;
            __IO uint32_t CMDIE    :1;
            __I           uint32_t :7;
            __IO uint32_t CMDIC    :1;
            __I           uint32_t :15;
        } bits;
        __IO uint32_t reg;
    } INT;

    /* Offset:0x8  ISMU_SS */
    union
    {
        struct
        {
            __I uint32_t SECFLSLOCK :1;
            __I uint32_t KEYEMP     :1;
            __I          uint32_t   :30;
        } bits;
        __IO uint32_t reg;
    } SS;
} Ismu_RegisterMap_t;

/**
 * @brief Address of Ismu register
 */
#define ISMU_ADDR ((uint32_t)0x40005f00U)

/**
 * @brief Pointer to Ismu register
 */
#define ISMU_PTR ((Ismu_RegisterMap_t *)ISMU_ADDR)

/**
 * @brief Register map of Ismu
 */
#define ISMU_RM (*(ISMU_PTR))

/**
 * @brief Module check assertion
 */
#define CHECK_ISMU_ALL_PERIPH_ADDR(Module) (((uint32_t)(Module) == (uint32_t)(ISMU_PTR)))

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
#endif /*End of KF32A158SF_ISMU_REG_H*/
/* EOF */
