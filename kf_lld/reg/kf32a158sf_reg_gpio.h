/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a158sf_reg_gpio.h
 *  @Date            : 2025-07-03
 *  @Version         : {{VersionDate}}
 *  @Description     : This document describes the register definition of Gpio
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
#ifndef KF32A158SF_REG_GPIO_H
#define KF32A158SF_REG_GPIO_H

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

    /* Offset:0x0  GPIO_PIR */
    union
    {
        struct
        {
            __I uint32_t PXPIR0   :1;
            __I uint32_t PXPIR1   :1;
            __I uint32_t PXPIR2   :1;
            __I uint32_t PXPIR3   :1;
            __I uint32_t PXPIR4   :1;
            __I uint32_t PXPIR5   :1;
            __I uint32_t PXPIR6   :1;
            __I uint32_t PXPIR7   :1;
            __I uint32_t PXPIR8   :1;
            __I uint32_t PXPIR9   :1;
            __I uint32_t PXPIR10  :1;
            __I uint32_t PXPIR11  :1;
            __I uint32_t PXPIR12  :1;
            __I uint32_t PXPIR13  :1;
            __I uint32_t PXPIR14  :1;
            __I uint32_t PXPIR15  :1;
            __I          uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } PIR;

    /* Offset:0x4  GPIO_POR */
    union
    {
        struct
        {
            __IO uint32_t PXPOR0   :1;
            __IO uint32_t PXPOR1   :1;
            __IO uint32_t PXPOR2   :1;
            __IO uint32_t PXPOR3   :1;
            __IO uint32_t PXPOR4   :1;
            __IO uint32_t PXPOR5   :1;
            __IO uint32_t PXPOR6   :1;
            __IO uint32_t PXPOR7   :1;
            __IO uint32_t PXPOR8   :1;
            __IO uint32_t PXPOR9   :1;
            __IO uint32_t PXPOR10  :1;
            __IO uint32_t PXPOR11  :1;
            __IO uint32_t PXPOR12  :1;
            __IO uint32_t PXPOR13  :1;
            __IO uint32_t PXPOR14  :1;
            __IO uint32_t PXPOR15  :1;
            __I           uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } POR;

    /* Offset:0x8  GPIO_PUR */
    union
    {
        struct
        {
            __IO uint32_t PXPUR0   :1;
            __IO uint32_t PXPUR1   :1;
            __IO uint32_t PXPUR2   :1;
            __IO uint32_t PXPUR3   :1;
            __IO uint32_t PXPUR4   :1;
            __IO uint32_t PXPUR5   :1;
            __IO uint32_t PXPUR6   :1;
            __IO uint32_t PXPUR7   :1;
            __IO uint32_t PXPUR8   :1;
            __IO uint32_t PXPUR9   :1;
            __IO uint32_t PXPUR10  :1;
            __IO uint32_t PXPUR11  :1;
            __IO uint32_t PXPUR12  :1;
            __IO uint32_t PXPUR13  :1;
            __IO uint32_t PXPUR14  :1;
            __IO uint32_t PXPUR15  :1;
            __I           uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } PUR;

    /* Offset:0xc  GPIO_PDR */
    union
    {
        struct
        {
            __IO uint32_t PXPDR0   :1;
            __IO uint32_t PXPDR1   :1;
            __IO uint32_t PXPDR2   :1;
            __IO uint32_t PXPDR3   :1;
            __IO uint32_t PXPDR4   :1;
            __IO uint32_t PXPDR5   :1;
            __IO uint32_t PXPDR6   :1;
            __IO uint32_t PXPDR7   :1;
            __IO uint32_t PXPDR8   :1;
            __IO uint32_t PXPDR9   :1;
            __IO uint32_t PXPDR10  :1;
            __IO uint32_t PXPDR11  :1;
            __IO uint32_t PXPDR12  :1;
            __IO uint32_t PXPDR13  :1;
            __IO uint32_t PXPDR14  :1;
            __IO uint32_t PXPDR15  :1;
            __I           uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } PDR;

    /* Offset:0x10  GPIO_PODR */
    union
    {
        struct
        {
            __IO uint32_t PXPODR0  :1;
            __IO uint32_t PXPODR1  :1;
            __IO uint32_t PXPODR2  :1;
            __IO uint32_t PXPODR3  :1;
            __IO uint32_t PXPODR4  :1;
            __IO uint32_t PXPODR5  :1;
            __IO uint32_t PXPODR6  :1;
            __IO uint32_t PXPODR7  :1;
            __IO uint32_t PXPODR8  :1;
            __IO uint32_t PXPODR9  :1;
            __IO uint32_t PXPODR10 :1;
            __IO uint32_t PXPODR11 :1;
            __IO uint32_t PXPODR12 :1;
            __IO uint32_t PXPODR13 :1;
            __IO uint32_t PXPODR14 :1;
            __IO uint32_t PXPODR15 :1;
            __I           uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } PODR;

    /* Offset:0x14  GPIO_PMOD */
    union
    {
        struct
        {
            __IO uint32_t PXPMD0  :2;
            __IO uint32_t PXPMD1  :2;
            __IO uint32_t PXPMD2  :2;
            __IO uint32_t PXPMD3  :2;
            __IO uint32_t PXPMD4  :2;
            __IO uint32_t PXPMD5  :2;
            __IO uint32_t PXPMD6  :2;
            __IO uint32_t PXPMD7  :2;
            __IO uint32_t PXPMD8  :2;
            __IO uint32_t PXPMD9  :2;
            __IO uint32_t PXPMD10 :2;
            __IO uint32_t PXPMD11 :2;
            __IO uint32_t PXPMD12 :2;
            __IO uint32_t PXPMD13 :2;
            __IO uint32_t PXPMD14 :2;
            __IO uint32_t PXPMD15 :2;
        } bits;
        __IO uint32_t reg;
    } PMOD;

    /* Offset:0x18  GPIO_OMOD */
    union
    {
        struct
        {
            __IO uint32_t PXOMD0   :1;
            __I           uint32_t :1;
            __IO uint32_t PXOMD1   :1;
            __I           uint32_t :1;
            __IO uint32_t PXOMD2   :1;
            __I           uint32_t :1;
            __IO uint32_t PXOMD3   :1;
            __I           uint32_t :1;
            __IO uint32_t PXOMD4   :1;
            __I           uint32_t :1;
            __IO uint32_t PXOMD5   :1;
            __I           uint32_t :1;
            __IO uint32_t PXOMD6   :1;
            __I           uint32_t :1;
            __IO uint32_t PXOMD7   :1;
            __I           uint32_t :1;
            __IO uint32_t PXOMD8   :1;
            __I           uint32_t :1;
            __IO uint32_t PXOMD9   :1;
            __I           uint32_t :1;
            __IO uint32_t PXOMD10  :1;
            __I           uint32_t :1;
            __IO uint32_t PXOMD11  :1;
            __I           uint32_t :1;
            __IO uint32_t PXOMD12  :1;
            __I           uint32_t :1;
            __IO uint32_t PXOMD13  :1;
            __I           uint32_t :1;
            __IO uint32_t PXOMD14  :1;
            __I           uint32_t :1;
            __IO uint32_t PXOMD15  :1;
            __I           uint32_t :1;
        } bits;
        __IO uint32_t reg;
    } OMOD;

    /* Offset:0x1c  GPIO_LOCK */
    union
    {
        struct
        {
            __IO uint32_t PXLCK0   :1;
            __IO uint32_t PXLCK1   :1;
            __IO uint32_t PXLCK2   :1;
            __IO uint32_t PXLCK3   :1;
            __IO uint32_t PXLCK4   :1;
            __IO uint32_t PXLCK5   :1;
            __IO uint32_t PXLCK6   :1;
            __IO uint32_t PXLCK7   :1;
            __IO uint32_t PXLCK8   :1;
            __IO uint32_t PXLCK9   :1;
            __IO uint32_t PXLCK10  :1;
            __IO uint32_t PXLCK11  :1;
            __IO uint32_t PXLCK12  :1;
            __IO uint32_t PXLCK13  :1;
            __IO uint32_t PXLCK14  :1;
            __IO uint32_t PXLCK15  :1;
            __IO uint32_t PXLCKKEY :16;
        } bits;
        __IO uint32_t reg;
    } LOCK;

    /* Offset:0x20  GPIO_RMPL */
    union
    {
        struct
        {
            __IO uint32_t PXRMP0 :4;
            __IO uint32_t PXRMP1 :4;
            __IO uint32_t PXRMP2 :4;
            __IO uint32_t PXRMP3 :4;
            __IO uint32_t PXRMP4 :4;
            __IO uint32_t PXRMP5 :4;
            __IO uint32_t PXRMP6 :4;
            __IO uint32_t PXRMP7 :4;
        } bits;
        __IO uint32_t reg;
    } RMPL;

    /* Offset:0x24  GPIO_RMPH */
    union
    {
        struct
        {
            __IO uint32_t PXRMP8  :4;
            __IO uint32_t PXRMP9  :4;
            __IO uint32_t PXRMP10 :4;
            __IO uint32_t PXRMP11 :4;
            __IO uint32_t PXRMP12 :4;
            __IO uint32_t PXRMP13 :4;
            __IO uint32_t PXRMP14 :4;
            __IO uint32_t PXRMP15 :4;
        } bits;
        __IO uint32_t reg;
    } RMPH;

    __I uint32_t RESERVED_0x28[3];

    /* Offset:0x34  GPIO_RMP_MSB */
    union
    {
        struct
        {
            __IO uint32_t RMPMSB :32;
        } bits;
        __IO uint32_t reg;
    } RMP_MSB;

    /* Offset:0x38  GPIO_SDE */
    union
    {
        struct
        {
            __IO uint32_t SDEN :16;
            __I uint32_t  SDEF :16;
        } bits;
        __IO uint32_t reg;
    } SDE;

    /* Offset:0x3c  GPIO_SDCTL */
    union
    {
        struct
        {
            __IO uint32_t SWSAMCLK :1;
            __IO uint32_t LINKEN   :1;
            __I uint32_t  PSDEF    :1;
            __I           uint32_t :29;
        } bits;
        __IO uint32_t reg;
    } SDCTL;

} Gpio_RegisterMap_t;

/**
 * @brief Address of Gpio register
 */
#define GPIOA_ADDR ((uint32_t)0x50000000U)
#define GPIOB_ADDR ((uint32_t)0x50000040U)
#define GPIOC_ADDR ((uint32_t)0x50000080U)
#define GPIOD_ADDR ((uint32_t)0x500000c0U)
#define GPIOE_ADDR ((uint32_t)0x50000100U)
#define GPIOF_ADDR ((uint32_t)0x50000140U)
#define GPIOG_ADDR ((uint32_t)0x50000180U)
#define GPIOH_ADDR ((uint32_t)0x500001c0U)

/**
 * @brief Pointer to Gpio register
 */
#define GPIOA_PTR ((Gpio_RegisterMap_t *)GPIOA_ADDR)
#define GPIOB_PTR ((Gpio_RegisterMap_t *)GPIOB_ADDR)
#define GPIOC_PTR ((Gpio_RegisterMap_t *)GPIOC_ADDR)
#define GPIOD_PTR ((Gpio_RegisterMap_t *)GPIOD_ADDR)
#define GPIOE_PTR ((Gpio_RegisterMap_t *)GPIOE_ADDR)
#define GPIOF_PTR ((Gpio_RegisterMap_t *)GPIOF_ADDR)
#define GPIOG_PTR ((Gpio_RegisterMap_t *)GPIOG_ADDR)
#define GPIOH_PTR ((Gpio_RegisterMap_t *)GPIOH_ADDR)

/**
 * @brief Register map of Gpio
 */
#define GPIOA_RM (*(GPIOA_PTR))
#define GPIOB_RM (*(GPIOB_PTR))
#define GPIOC_RM (*(GPIOC_PTR))
#define GPIOD_RM (*(GPIOD_PTR))
#define GPIOE_RM (*(GPIOE_PTR))
#define GPIOF_RM (*(GPIOF_PTR))
#define GPIOG_RM (*(GPIOG_PTR))
#define GPIOH_RM (*(GPIOH_PTR))

/**
 * @brief Module check assertion
 */
#define CHECK_GPIO_ALL_PERIPH_ADDR(Module)                                                                             \
    (((uint32_t)(Module) == (uint32_t)(GPIOA_PTR)) || ((uint32_t)(Module) == (uint32_t)(GPIOB_PTR)) ||                 \
     ((uint32_t)(Module) == (uint32_t)(GPIOC_PTR)) || ((uint32_t)(Module) == (uint32_t)(GPIOD_PTR)) ||                 \
     ((uint32_t)(Module) == (uint32_t)(GPIOE_PTR)) || ((uint32_t)(Module) == (uint32_t)(GPIOF_PTR)) ||                 \
     ((uint32_t)(Module) == (uint32_t)(GPIOG_PTR)) || ((uint32_t)(Module) == (uint32_t)(GPIOH_PTR)))

typedef volatile struct
{

    /* Offset:0x0  EXTI_INTMS */
    union
    {
        struct
        {
            __IO uint32_t INTMS    :16;
            __I           uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } INTMS;

    /* Offset:0x4  EXTI_INTRISE */
    union
    {
        struct
        {
            __IO uint32_t INTRISE  :16;
            __I           uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } INTRISE;

    /* Offset:0x8  EXTI_INTFALL */
    union
    {
        struct
        {
            __IO uint32_t INTFALL  :16;
            __I           uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } INTFALL;

    /* Offset:0xc  EXTI_INTIE */
    union
    {
        struct
        {
            __IO uint32_t INTIE    :16;
            __I           uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } INTIE;

    /* Offset:0x10  EXTI_INTIF */
    union
    {
        struct
        {
            __IO uint32_t INTFLAG  :16;
            __I           uint32_t :16;
        } bits;
        __IO uint32_t reg;
    } INTIF;

} Exti_RegisterMap_t;

/**
 * @brief Address of Exti register
 */
#define EXTIA_ADDR ((uint32_t)0x50001000U)
#define EXTIB_ADDR ((uint32_t)0x50001040U)
#define EXTIC_ADDR ((uint32_t)0x50001080U)
#define EXTID_ADDR ((uint32_t)0x500010c0U)
#define EXTIE_ADDR ((uint32_t)0x50001100U)
#define EXTIF_ADDR ((uint32_t)0x50001140U)
#define EXTIG_ADDR ((uint32_t)0x50001180U)
#define EXTIH_ADDR ((uint32_t)0x500011c0U)

/**
 * @brief Pointer to Exti register
 */
#define EXTIA_PTR ((Exti_RegisterMap_t *)EXTIA_ADDR)
#define EXTIB_PTR ((Exti_RegisterMap_t *)EXTIB_ADDR)
#define EXTIC_PTR ((Exti_RegisterMap_t *)EXTIC_ADDR)
#define EXTID_PTR ((Exti_RegisterMap_t *)EXTID_ADDR)
#define EXTIE_PTR ((Exti_RegisterMap_t *)EXTIE_ADDR)
#define EXTIF_PTR ((Exti_RegisterMap_t *)EXTIF_ADDR)
#define EXTIG_PTR ((Exti_RegisterMap_t *)EXTIG_ADDR)
#define EXTIH_PTR ((Exti_RegisterMap_t *)EXTIH_ADDR)

/**
 * @brief Register map of Exti
 */
#define EXTIA_RM (*(EXTIA_PTR))
#define EXTIB_RM (*(EXTIB_PTR))
#define EXTIC_RM (*(EXTIC_PTR))
#define EXTID_RM (*(EXTID_PTR))
#define EXTIE_RM (*(EXTIE_PTR))
#define EXTIF_RM (*(EXTIF_PTR))
#define EXTIG_RM (*(EXTIG_PTR))
#define EXTIH_RM (*(EXTIH_PTR))

/**
 * @brief Module check assertion
 */
#define CHECK_EXTI_ALL_PERIPH_ADDR(Module)                                                                             \
    (((uint32_t)(Module) == (uint32_t)(EXTIA_PTR)) || ((uint32_t)(Module) == (uint32_t)(EXTIB_PTR)) ||                 \
     ((uint32_t)(Module) == (uint32_t)(EXTIC_PTR)) || ((uint32_t)(Module) == (uint32_t)(EXTID_PTR)) ||                 \
     ((uint32_t)(Module) == (uint32_t)(EXTIE_PTR)) || ((uint32_t)(Module) == (uint32_t)(EXTIF_PTR)) ||                 \
     ((uint32_t)(Module) == (uint32_t)(EXTIG_PTR)) || ((uint32_t)(Module) == (uint32_t)(EXTIH_PTR)))

typedef volatile struct
{

    /* Offset:0x0  IONMI_CTL */
    union
    {
        struct
        {
            __IO uint32_t IONMIEN  :1;
            __IO uint32_t FLTWR    :3;
            __IO uint32_t FCKDIV   :3;
            __I           uint32_t :1;
            __IO uint32_t IRQMS    :3;
            __IO uint32_t FLTEN    :1;
            __IO uint32_t FLTCKS   :1;
            __IO uint32_t IONMIIC  :1;
            __I uint32_t  IONMIIF  :1;
            __I           uint32_t :17;
        } bits;
        __IO uint32_t reg;
    } CTL;

} Ionmi_RegisterMap_t;

/**
 * @brief Address of Ionmi register
 */
#define IONMI_ADDR ((uint32_t)0x5000117cU)

/**
 * @brief Pointer to Ionmi register
 */
#define IONMI_PTR ((Ionmi_RegisterMap_t *)IONMI_ADDR)

/**
 * @brief Register map of Ionmi
 */
#define IONMI_RM (*(IONMI_PTR))

/**
 * @brief Module check assertion
 */
#define CHECK_IONMI_ALL_PERIPH_ADDR(Module) (((uint32_t)(Module) == (uint32_t)(IONMI_PTR)))

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
#endif /*End of KF32A158SF_REG_GPIO_H*/
/* EOF */
