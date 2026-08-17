/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a158sf_reg_crc.h
 *  @Date            : 2025-07-03
 *  @Version         : {{VersionDate}}
 *  @Description     : This document describes the register definition of Crc
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
#ifndef KF32A158SF_REG_CRC_H
#define KF32A158SF_REG_CRC_H

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

    /* Offset:0x0  CRC_CTL */
    union
    {
        struct
        {
            __IO uint32_t RSET        :1;
            __I           uint32_t    :1;
            __IO uint32_t DATASIZE    :2;
            __IO uint32_t DATAINSWAP  :2;
            __IO uint32_t DATAOUTSWAP :2;
            __I           uint32_t    :24;
        } bits;
        __IO uint32_t reg;
    } CTL;

    /* Offset:0x4  CRC_DATA */
    __IO uint32_t DATA;

    /* Offset:0x8  CRC_RSLT */
    __I uint32_t RSLT;

    /* Offset:0xc  CRC_INIT */
    __IO uint32_t INIT;

    /* Offset:0x10  CRC_PLN */
    __IO uint32_t PLN;

    /* Offset:0x14  CRC_RXOR */
    __IO uint32_t RXOR;

    /* Offset:0x18  CRC_IDATA */
    __IO uint32_t IDATA;

    /* Offset:0x1c  CRC_TEMP */
    __I uint32_t TEMP;

} Crc_RegisterMap_t;

/**
 * @brief Address of Crc register
 */
#define CRC_ADDR ((uint32_t)0x40002680U)

/**
 * @brief Pointer to Crc register
 */
#define CRC_PTR ((Crc_RegisterMap_t *)CRC_ADDR)

/**
 * @brief Register map of Crc
 */
#define CRC_RM (*(CRC_PTR))

/**
 * @brief Module check assertion
 */
#define CHECK_CRC_ALL_PERIPH_ADDR(Module) (((uint32_t)(Module) == (uint32_t)(CRC_PTR)))

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
#endif /*End of KF32A158SF_REG_CRC_H*/
/* EOF */
