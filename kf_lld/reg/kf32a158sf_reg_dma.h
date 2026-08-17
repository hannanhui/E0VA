/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a158sf_reg_dma.h
 *  @Date            : 2025-07-03
 *  @Version         : {{VersionDate}}
 *  @Description     : This document describes the register definition of Dma
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
#ifndef KF32A158SF_REG_DMA_H
#define KF32A158SF_REG_DMA_H

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

    /* Offset:0x0  DMA_CTL1 */
    union
    {
        struct
        {
            __IO uint32_t DMAEN    :1;
            __IO uint32_t DMAHALT  :1;
            __I           uint32_t :1;
            __IO uint32_t BLKM     :1;
            __IO uint32_t DDIR     :1;
            __IO uint32_t LPM      :1;
            __IO uint32_t MINC     :1;
            __IO uint32_t PINC     :1;
            __IO uint32_t MDS      :2;
            __IO uint32_t PDS      :2;
            __IO uint32_t ONESHOT  :1;
            __IO uint32_t CPL      :2;
            __IO uint32_t M2M      :1;
            __IO uint32_t NUMODT   :16;
        } bits;
        __IO uint32_t reg;
    } CTL[7];

    __I uint32_t RESERVED_0x1c;

    /* Offset:0x20  DMA_PADDR1 */
    __IO uint32_t PADDR[7];

    __I uint32_t RESERVED_0x3c;

    /* Offset:0x40  DMA_MADDR1 */
    __IO uint32_t MADDR[7];

    __I uint32_t RESERVED_0x5c;

    /* Offset:0x60  DMA_CPAR1 */
    __I uint32_t CPAR[7];

    __I uint32_t RESERVED_0x7c;

    /* Offset:0x80  DMA_CMAR1 */
    __I uint32_t CMAR[7];

    __I uint32_t RESERVED_0x9c;

    /* Offset:0xa0  DMA_NCT1 */
    union
    {
        struct
        {
            __I          uint32_t :16;
            __I uint32_t NCT      :16;
        } bits;
        __I uint32_t reg;
    } NCT[7];

    __I uint32_t RESERVED_0xbc;

    /* Offset:0xc0  DMA_LIFR */
    union
    {
        struct
        {
            __IO uint32_t FTIF1    :1;
            __IO uint32_t HTIF1    :1;
            __IO uint32_t ETIF1    :1;
            __IO uint32_t FTIF2    :1;
            __IO uint32_t HTIF2    :1;
            __IO uint32_t ETIF2    :1;
            __IO uint32_t FTIF3    :1;
            __IO uint32_t HTIF3    :1;
            __IO uint32_t ETIF3    :1;
            __IO uint32_t FTIF4    :1;
            __IO uint32_t HTIF4    :1;
            __IO uint32_t ETIF4    :1;
            __IO uint32_t FTIF5    :1;
            __IO uint32_t HTIF5    :1;
            __IO uint32_t ETIF5    :1;
            __IO uint32_t FTIF6    :1;
            __IO uint32_t HTIF6    :1;
            __IO uint32_t ETIF6    :1;
            __IO uint32_t FTIF7    :1;
            __IO uint32_t HTIF7    :1;
            __IO uint32_t ETIF7    :1;
            __I           uint32_t :11;
        } bits;
        __IO uint32_t reg;
    } LIFR;

    /* Offset:0xc4  DMA_LIER */
    union
    {
        struct
        {
            __IO uint32_t FTIE1    :1;
            __IO uint32_t HTIE1    :1;
            __IO uint32_t ETIE1    :1;
            __IO uint32_t FTIE2    :1;
            __IO uint32_t HTIE2    :1;
            __IO uint32_t ETIE2    :1;
            __IO uint32_t FTIE3    :1;
            __IO uint32_t HTIE3    :1;
            __IO uint32_t ETIE3    :1;
            __IO uint32_t FTIE4    :1;
            __IO uint32_t HTIE4    :1;
            __IO uint32_t ETIE4    :1;
            __IO uint32_t FTIE5    :1;
            __IO uint32_t HTIE5    :1;
            __IO uint32_t ETIE5    :1;
            __IO uint32_t FTIE6    :1;
            __IO uint32_t HTIE6    :1;
            __IO uint32_t ETIE6    :1;
            __IO uint32_t FTIE7    :1;
            __IO uint32_t HTIE7    :1;
            __IO uint32_t ETIE7    :1;
            __I           uint32_t :11;
        } bits;
        __IO uint32_t reg;
    } LIER;

    /* Offset:0xc8  DMA_MUXL */
    union
    {
        struct
        {
            __IO uint32_t SOURCE1  :6;
            __I           uint32_t :1;
            __IO uint32_t TRGEN1   :1;
            __IO uint32_t SOURCE2  :6;
            __I           uint32_t :1;
            __IO uint32_t TRGEN2   :1;
            __IO uint32_t SOURCE3  :6;
            __I           uint32_t :1;
            __IO uint32_t TRGEN3   :1;
            __IO uint32_t SOURCE4  :6;
            __I           uint32_t :1;
            __IO uint32_t TRGEN4   :1;
        } bits;
        __IO uint32_t reg;
    } MUXL;

    /* Offset:0xcc  DMA_MUXH */
    union
    {
        struct
        {
            __IO uint32_t SOURCE5  :6;
            __I           uint32_t :1;
            __IO uint32_t TRGEN5   :1;
            __IO uint32_t SOURCE6  :6;
            __I           uint32_t :1;
            __IO uint32_t TRGEN6   :1;
            __IO uint32_t SOURCE7  :6;
            __I           uint32_t :1;
            __IO uint32_t TRGEN7   :1;
            __I           uint32_t :8;
        } bits;
        __IO uint32_t reg;
    } MUXH;

} Dma_RegisterMap_t;

/**
 * @brief Address of Dma register
 */
#define DMA0_ADDR ((uint32_t)0x40001600U)
#define DMA1_ADDR ((uint32_t)0x40001700U)

/**
 * @brief Pointer to Dma register
 */
#define DMA0_PTR ((Dma_RegisterMap_t *)DMA0_ADDR)
#define DMA1_PTR ((Dma_RegisterMap_t *)DMA1_ADDR)

/**
 * @brief Register map of Dma
 */
#define DMA0_RM (*(DMA0_PTR))
#define DMA1_RM (*(DMA1_PTR))

/**
 * @brief Module check assertion
 */
#define CHECK_DMA_ALL_PERIPH_ADDR(Module)                                                                              \
    (((uint32_t)(Module) == (uint32_t)(DMA0_PTR)) || ((uint32_t)(Module) == (uint32_t)(DMA1_PTR)))

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
#endif /*End of KF32A158SF_REG_DMA_H*/
/* EOF */
