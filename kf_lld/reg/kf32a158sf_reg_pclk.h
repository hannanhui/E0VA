/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : kf32a158sf_reg_pclk.h
 *  @Date            : 2025-07-03
 *  @Version         : {{VersionDate}}
 *  @Description     : This document describes the register definition of Pclk
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
#ifndef KF32A158SF_REG_PCLK_H
#define KF32A158SF_REG_PCLK_H

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

    /* Offset:0x0  PCLK_CTL0 */
    union
    {
        struct
        {
            __IO uint32_t GPIOACLKEN :1;
            __IO uint32_t GPIOBCLKEN :1;
            __IO uint32_t GPIOCCLKEN :1;
            __IO uint32_t GPIODCLKEN :1;
            __IO uint32_t GPIOECLKEN :1;
            __IO uint32_t GPIOFCLKEN :1;
            __IO uint32_t GPIOGCLKEN :1;
            __IO uint32_t GPIOHCLKEN :1;
            __IO          uint32_t   :24;
        } bits;
        __IO uint32_t reg;
    } CTL0;

    /* Offset:0x4  PCLK_CTL1 */
    union
    {
        struct
        {
            __IO          uint32_t    :2;
            __IO uint32_t T1CLKEN     :1;
            __IO uint32_t T2CLKEN     :1;
            __IO uint32_t T3CLKEN     :1;
            __IO uint32_t T4CLKEN     :1;
            __IO uint32_t T5T6CLKEN   :1;
            __IO          uint32_t    :1;
            __IO uint32_t T9T10CLKEN  :1;
            __IO          uint32_t    :2;
            __IO uint32_t ADC0CLKEN   :1;
            __IO uint32_t ADC1CLKEN   :1;
            __IO          uint32_t    :3;
            __IO uint32_t CMPCLKEN    :1;
            __IO uint32_t T0CLKEN     :1;
            __IO          uint32_t    :1;
            __IO uint32_t USART0CLKEN :1;
            __IO uint32_t USART1CLKEN :1;
            __IO uint32_t USART2CLKEN :1;
            __IO uint32_t USART3CLKEN :1;
            __IO uint32_t USART6CLKEN :1;
            __IO uint32_t SPI0CLKEN   :1;
            __IO uint32_t SPI1CLKEN   :1;
            __IO uint32_t I2C0CLKEN   :1;
            __IO uint32_t I2C1CLKEN   :1;
            __IO uint32_t I2C2CLKEN   :1;
            __IO          uint32_t    :1;
            __IO uint32_t MPUCLKEN    :1;
            __IO          uint32_t    :1;
        } bits;
        __IO uint32_t reg;
    } CTL1;

    /* Offset:0x8  PCLK_CTL2 */
    union
    {
        struct
        {
            __IO          uint32_t      :4;
            __IO uint32_t ISMUTESTCLKEN :1;
            __IO uint32_t WWDTCLKEN     :1;
            __IO          uint32_t      :2;
            __IO uint32_t EPWM11CLKEN   :1;
            __IO uint32_t EPWM12CLKEN   :1;
            __IO uint32_t EPWM13CLKEN   :1;
            __IO uint32_t EPWM16CLKEN   :1;
            __IO uint32_t DMA0CLKEN     :1;
            __IO uint32_t AES1CLKEN     :1;
            __IO uint32_t DMA1CLKEN     :1;
            __IO uint32_t ECC18CLKEN    :1;
            __IO uint32_t T14CLKEN      :1;
            __IO          uint32_t      :1;
            __IO uint32_t ECC17CLKEN    :1;
            __IO uint32_t ECC16CLKEN    :1;
            __IO          uint32_t      :3;
            __IO uint32_t T20CLKEN      :1;
            __IO uint32_t T21CLKEN      :1;
            __IO uint32_t SYSTICK1CLKEN :1;
            __IO          uint32_t      :6;
        } bits;
        __IO uint32_t reg;
    } CTL2;

    /* Offset:0xc  PCLK_CTL3 */
    union
    {
        struct
        {
            __IO          uint32_t       :1;
            __IO uint32_t SPI2CLKEN      :1;
            __IO          uint32_t       :9;
            __IO uint32_t REMAPTESTCLKEN :1;
            __IO uint32_t CMUCLKEN       :1;
            __IO uint32_t CRCCLKEN       :1;
            __IO uint32_t AESCLKEN       :1;
            __IO          uint32_t       :6;
            __IO uint32_t FLEXMUXCLKEN   :1;
            __IO          uint32_t       :3;
            __IO uint32_t FLEXRMCLKEN    :1;
            __IO          uint32_t       :1;
            __IO uint32_t EWDTCLKEN      :1;
            __IO uint32_t RNGCLKEN       :1;
            __IO uint32_t CANFD6CLKEN    :1;
            __IO uint32_t CANFD7CLKEN    :1;
            __IO uint32_t ECC15CLKEN     :1;
        } bits;
        __IO uint32_t reg;
    } CTL3;

    /* Offset:0x10  PCLK_CTL4 */
    union
    {
        struct
        {
            __IO uint32_t CANFD8CLKEN :1;
            __IO uint32_t CANFD9CLKEN :1;
            __IO uint32_t SHACLKEN    :1;
            __IO uint32_t RSACLKEN    :1;
            __IO          uint32_t    :6;
            __IO uint32_t ECC4CLKEN   :1;
            __IO uint32_t ECC5CLKEN   :1;
            __IO          uint32_t    :7;
            __IO uint32_t ECC13CLKEN  :1;
            __IO uint32_t ECC0CLKEN   :1;
            __IO uint32_t ECC1CLKEN   :1;
            __IO          uint32_t    :2;
            __IO uint32_t ECC19CLKEN  :1;
            __IO uint32_t ECC20CLKEN  :1;
            __IO uint32_t EPWM31CLKEN :1;
            __IO uint32_t EPWM32CLKEN :1;
            __IO uint32_t EPWM33CLKEN :1;
            __IO uint32_t EPWM36CLKEN :1;
            __IO          uint32_t    :2;
        } bits;
        __IO uint32_t reg;
    } CTL4;

} Pclk_RegisterMap_t;

/**
 * @brief Address of Pclk register
 */
#define PCLK_ADDR ((uint32_t)0x40002640U)

/**
 * @brief Pointer to Pclk register
 */
#define PCLK_PTR ((Pclk_RegisterMap_t *)PCLK_ADDR)

/**
 * @brief Register map of Pclk
 */
#define PCLK_RM (*(PCLK_PTR))

/**
 * @brief Module check assertion
 */
#define CHECK_PCLK_ALL_PERIPH_ADDR(Module) (((uint32_t)(Module) == (uint32_t)(PCLK_PTR)))

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
#endif /*End of KF32A158SF_PCLK_REG_H*/
/* EOF */
