/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name        : kf32a158sf_drv_pclk.h
 *  @Date             : 2025-07-08
 *  @Version          : {{VersionDate}}
 *  @Description      : This file provides
 ******************************************************************************
 *  Copyright (C) by Shanghai ChipON Micro-Electronic Co.,Ltd
 *  All rights reserved.
 *
 *  This software is copyright protected and proprietary to
 *  Shanghai ChipON Micro-Electronic Co.,Ltd.
 *****************************************************************************/
/******************************************************************************
 *  |Date        |Version  |Author       |Description
 *******************************************************************************
 *  |2025-07-08  |V1.0     |AE Group     |New create
 ******************************************************************************/
#ifndef KF32A158SF_DRV_PCLK_H
#define KF32A158SF_DRV_PCLK_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 *                      QAC Warnings
 ******************************************************************************/
/* PRQA S 0288 EOF #KQR000288 */
/* PRQA S 0303,0306 EOF #KQR100303 */
/* PRQA S 1006,3006 EOF #KQR101006 */
/* PRQA S 1083 EOF #KQR001083 */
/* PRQA S 3205 EOF #KQR003205 */
/* PRQA S 3219 EOF #KQR003219 */
/* PRQA S 3473 EOF #KQR003473 */

/******************************************************************************
 *                      Include Files
 ******************************************************************************/
#include <stdint.h>
#include <stdbool.h>
#include "kf_types.h"
#include "kf32a158sf_reg_pclk.h"

#ifdef KF_DRV_PCLK_ASSERT
#include "dev_assert.h"
#define KF_PCLK_ASSERT(x) KF_DEV_ASSERT(x)
#else
#define KF_PCLK_ASSERT(x) ((void)0U)
#endif

/******************************************************************************
 *                      Macro or Inline
 ******************************************************************************/

/******************************************************************************
 *                      Type definitions
 ******************************************************************************/

typedef enum
{
    PCLK_IDX_GPIOACLKEN = 0U,
    PCLK_IDX_GPIOBCLKEN = 1U,
    PCLK_IDX_GPIOCCLKEN = 2U,
    PCLK_IDX_GPIODCLKEN = 3U,
    PCLK_IDX_GPIOECLKEN = 4U,
    PCLK_IDX_GPIOFCLKEN = 5U,
    PCLK_IDX_GPIOGCLKEN = 6U,
    PCLK_IDX_GPIOHCLKEN = 7U,
} Pclk_Ctl0Index_t;
#define CHECK_PCLK_CTL0INDEX(x) ((uint32_t)(x) <= (uint32_t)PCLK_IDX_GPIOHCLKEN)

typedef enum
{
    PCLK_IDX_T1CLKEN     = 2U,
    PCLK_IDX_T2CLKEN     = 3U,
    PCLK_IDX_T3CLKEN     = 4U,
    PCLK_IDX_T4CLKEN     = 5U,
    PCLK_IDX_T5T6CLKEN   = 6U,
    PCLK_IDX_T9T10CLKEN  = 8U,
    PCLK_IDX_ADC0CLKEN   = 11U,
    PCLK_IDX_ADC1CLKEN   = 12U,
    PCLK_IDX_CMPCLKEN    = 16U,
    PCLK_IDX_T0CLKEN     = 17U,
    PCLK_IDX_USART0CLKEN = 19U,
    PCLK_IDX_USART1CLKEN = 20U,
    PCLK_IDX_USART2CLKEN = 21U,
    PCLK_IDX_USART3CLKEN = 22U,
    PCLK_IDX_USART6CLKEN = 23U,
    PCLK_IDX_SPI0CLKEN   = 24U,
    PCLK_IDX_SPI1CLKEN   = 25U,
    PCLK_IDX_I2C0CLKEN   = 26U,
    PCLK_IDX_I2C1CLKEN   = 27U,
    PCLK_IDX_I2C2CLKEN   = 28U,
    PCLK_IDX_MPUCLKEN    = 30U
} Pclk_Ctl1Index_t;
#define CHECK_PCLK_CTL1INDEX(x)                                                                                        \
    (((x) == PCLK_IDX_T1CLKEN) || ((x) == PCLK_IDX_T2CLKEN) || ((x) == PCLK_IDX_T3CLKEN) ||                            \
     ((x) == PCLK_IDX_T4CLKEN) || ((x) == PCLK_IDX_T5T6CLKEN) || ((x) == PCLK_IDX_T9T10CLKEN) ||                       \
     ((x) == PCLK_IDX_ADC0CLKEN) || ((x) == PCLK_IDX_ADC1CLKEN) || ((x) == PCLK_IDX_CMPCLKEN) ||                       \
     ((x) == PCLK_IDX_T0CLKEN) || ((x) == PCLK_IDX_USART0CLKEN) || ((x) == PCLK_IDX_USART1CLKEN) ||                    \
     ((x) == PCLK_IDX_USART2CLKEN) || ((x) == PCLK_IDX_USART3CLKEN) || ((x) == PCLK_IDX_USART6CLKEN) ||                \
     ((x) == PCLK_IDX_SPI0CLKEN) || ((x) == PCLK_IDX_SPI1CLKEN) || ((x) == PCLK_IDX_I2C0CLKEN) ||                      \
     ((x) == PCLK_IDX_I2C1CLKEN) || ((x) == PCLK_IDX_I2C2CLKEN) || ((x) == PCLK_IDX_MPUCLKEN))

typedef enum
{
    PCLK_IDX_ISMUTESTCLKEN = 4U,
    PCLK_IDX_WWDTCLKEN     = 5U,
    PCLK_IDX_EPWM11CLKEN   = 8U,
    PCLK_IDX_EPWM12CLKEN   = 9U,
    PCLK_IDX_EPWM13CLKEN   = 10U,
    PCLK_IDX_EPWM16CLKEN   = 11U,
    PCLK_IDX_DMA0CLKEN     = 12U,
    PCLK_IDX_AES1CLKEN     = 13U,
    PCLK_IDX_DMA1CLKEN     = 14U,
    PCLK_IDX_ECC18CLKEN    = 15U,
    PCLK_IDX_T14CLKEN      = 16U,
    PCLK_IDX_ECC17CLKEN    = 18U,
    PCLK_IDX_ECC16CLKEN    = 19U,
    PCLK_IDX_T20CLKEN      = 23U,
    PCLK_IDX_T21CLKEN      = 24U,
    PCLK_IDX_SYSTICK1CLKEN = 25U,
} Pclk_Ctl2Index_t;
#define CHECK_PCLK_CTL2INDEX(x)                                                                                        \
    (((x) == PCLK_IDX_ISMUTESTCLKEN) || ((x) == PCLK_IDX_WWDTCLKEN) || ((x) == PCLK_IDX_EPWM11CLKEN) ||                \
     ((x) == PCLK_IDX_EPWM12CLKEN) || ((x) == PCLK_IDX_EPWM13CLKEN) || ((x) == PCLK_IDX_EPWM16CLKEN) ||                \
     ((x) == PCLK_IDX_DMA0CLKEN) || ((x) == PCLK_IDX_AES1CLKEN) || ((x) == PCLK_IDX_DMA1CLKEN) ||                      \
     ((x) == PCLK_IDX_ECC18CLKEN) || ((x) == PCLK_IDX_T14CLKEN) || ((x) == PCLK_IDX_ECC17CLKEN) ||                     \
     ((x) == PCLK_IDX_ECC16CLKEN) || ((x) == PCLK_IDX_T20CLKEN) || ((x) == PCLK_IDX_T21CLKEN) ||                       \
     ((x) == PCLK_IDX_SYSTICK1CLKEN))

typedef enum
{
    PCLK_IDX_SPI2CLKEN      = 1U,
    PCLK_IDX_REMAPTESTCLKEN = 11U,
    PCLK_IDX_CMUCLKEN       = 12U,
    PCLK_IDX_CRCCLKEN       = 13U,
    PCLK_IDX_AESCLKEN       = 14U,
    PCLK_IDX_FLEXRMCLKEN    = 25U,
    PCLK_IDX_EWDTCLKEN      = 27U,
    PCLK_IDX_CANFD6CLKEN    = 29U,
    PCLK_IDX_CANFD7CLKEN    = 30U,
    PCLK_IDX_ECC15CLKEN     = 31U
} Pclk_Ctl3Index_t;
#define CHECK_PCLK_CTL3INDEX(x)                                                                                        \
    (((x) == PCLK_IDX_SPI2CLKEN) || ((x) == PCLK_IDX_REMAPTESTCLKEN) || ((x) == PCLK_IDX_CMUCLKEN) ||                  \
     ((x) == PCLK_IDX_CRCCLKEN) || ((x) == PCLK_IDX_AESCLKEN) || ((x) == PCLK_IDX_FLEXRMCLKEN) ||                      \
     ((x) == PCLK_IDX_EWDTCLKEN) || ((x) == PCLK_IDX_CANFD6CLKEN) || ((x) == PCLK_IDX_CANFD7CLKEN) ||                  \
     ((x) == PCLK_IDX_ECC15CLKEN))

typedef enum
{
    PCLK_IDX_CANFD8CLKEN = 0U,
    PCLK_IDX_CANFD9CLKEN = 1U,
    PCLK_IDX_SHACLKEN    = 2U,
    PCLK_IDX_RSACLKEN    = 3U,
    PCLK_IDX_ECC4CLKEN   = 10U,
    PCLK_IDX_ECC5CLKEN   = 11U,
    PCLK_IDX_ECC13CLKEN  = 19U,
    PCLK_IDX_ECC0CLKEN   = 20U,
    PCLK_IDX_ECC1CLKEN   = 21U,
    PCLK_IDX_ECC19CLKEN  = 24U,
    PCLK_IDX_ECC20CLKEN  = 25U,
    PCLK_IDX_EPWM31CLKEN = 26U,
    PCLK_IDX_EPWM32CLKEN = 27U,
    PCLK_IDX_EPWM33CLKEN = 28U,
    PCLK_IDX_EPWM36CLKEN = 29U,
} Pclk_Ctl4Index_t;
#define CHECK_PCLK_CTL4INDEX(x)                                                                                        \
    (((x) == PCLK_IDX_CANFD8CLKEN) || ((x) == PCLK_IDX_CANFD9CLKEN) || ((x) == PCLK_IDX_SHACLKEN) ||                   \
     ((x) == PCLK_IDX_RSACLKEN) || ((x) == PCLK_IDX_ECC4CLKEN) || ((x) == PCLK_IDX_ECC5CLKEN) ||                       \
     ((x) == PCLK_IDX_ECC13CLKEN) || ((x) == PCLK_IDX_ECC0CLKEN) || ((x) == PCLK_IDX_ECC1CLKEN) ||                     \
     ((x) == PCLK_IDX_ECC19CLKEN) || ((x) == PCLK_IDX_ECC20CLKEN) || ((x) == PCLK_IDX_EPWM31CLKEN) ||                  \
     ((x) == PCLK_IDX_EPWM32CLKEN) || ((x) == PCLK_IDX_EPWM33CLKEN) || ((x) == PCLK_IDX_EPWM36CLKEN))

typedef enum
{
    PCLK_GPIO_A,
    PCLK_GPIO_B,
    PCLK_GPIO_C,
    PCLK_GPIO_D,
    PCLK_GPIO_E,
    PCLK_GPIO_F,
    PCLK_GPIO_G,
    PCLK_GPIO_H,
} Pclk_Gpio_t;
#define CHECK_PCLK_GPIO(x) ((uint32_t)(x) <= (uint32_t)PCLK_GPIO_H)

typedef enum
{
    PCLK_T1    = 2U,
    PCLK_T2    = 3U,
    PCLK_T3    = 4U,
    PCLK_T4    = 5U,
    PCLK_T5T6  = 6U,
    PCLK_T9T10 = 8U,
    PCLK_T0    = 17U,

    PCLK_T14 = 0x100U + 16U,
    PCLK_T20 = 0x100U + 23U,
    PCLK_T21 = 0x100U + 24U,
} Pclk_Tim_t;
#define CHECK_PCLK_TIM(x)                                                                                              \
    (((x) == PCLK_T1) || ((x) == PCLK_T2) || ((x) == PCLK_T3) || ((x) == PCLK_T4) || ((x) == PCLK_T5T6) ||             \
     ((x) == PCLK_T9T10) || ((x) == PCLK_T0) || ((x) == PCLK_T14) || ((x) == PCLK_T20) || ((x) == PCLK_T21))

typedef enum
{
    PCLK_CANFD6 = 29U,
    PCLK_CANFD7 = 30U,

    PCLK_CANFD8 = 0x100U + 0U,
    PCLK_CANFD9 = 0x100U + 1U,
} Pclk_Can_t;
#define CHECK_PCLK_CAN(x) (((x) == PCLK_CANFD6) || ((x) == PCLK_CANFD7) || ((x) == PCLK_CANFD8) || ((x) == PCLK_CANFD9))

typedef enum
{
    PCLK_ADC0 = 11U,
    PCLK_ADC1 = 12U,
} Pclk_Adc_t;
#define CHECK_PCLK_ADC(x) (((x) == PCLK_ADC0) || ((x) == PCLK_ADC1))

typedef enum
{
    PCLK_DMA0 = 12U,
    PCLK_DMA1 = 14U
} Pclk_Dma_t;
#define CHECK_PCLK_DMA(x) (((x) == PCLK_DMA0) || ((x) == PCLK_DMA1))

typedef enum
{
    PCLK_I2C0 = 26U,
    PCLK_I2C1 = 27U,
    PCLK_I2C2 = 28U,
} Pclk_I2c_t;
#define CHECK_PCLK_I2C(x) (((x) == PCLK_I2C0) || ((x) == PCLK_I2C1) || ((x) == PCLK_I2C2))

typedef enum
{
    PCLK_USART0 = 19U,
    PCLK_USART1 = 20U,
    PCLK_USART2 = 21U,
    PCLK_USART3 = 22U,
    PCLK_USART6 = 23U,
} Pclk_Usart_t;
#define CHECK_PCLK_USART(x)                                                                                            \
    (((x) == PCLK_USART0) || ((x) == PCLK_USART1) || ((x) == PCLK_USART2) || ((x) == PCLK_USART3) ||                   \
     ((x) == PCLK_USART6))

typedef enum
{
    PCLK_SPI0 = 24U,
    PCLK_SPI1 = 25U,
    PCLK_SPI2 = 0x100U + 1U,
} Pclk_Spi_t;
#define CHECK_PCLK_SPI(x) (((x) == PCLK_SPI0) || ((x) == PCLK_SPI1) || ((x) == PCLK_SPI2))

typedef enum
{
    PCLK_EPWM11 = 8U,
    PCLK_EPWM12 = 9U,
    PCLK_EPWM13 = 10U,
    PCLK_EPWM16 = 11U,
    PCLK_EPWM31 = 0x100U + 26U,
    PCLK_EPWM32 = 0x100U + 27U,
    PCLK_EPWM33 = 0x100U + 28U,
    PCLK_EPWM36 = 0x100U + 29U,
} Pclk_Epwm_t;
#define CHECK_PCLK_EPWM(x)                                                                                             \
    (((x) == PCLK_EPWM11) || ((x) == PCLK_EPWM12) || ((x) == PCLK_EPWM13) || ((x) == PCLK_EPWM16) ||                   \
     ((x) == PCLK_EPWM31) || ((x) == PCLK_EPWM32) || ((x) == PCLK_EPWM33) || ((x) == PCLK_EPWM36))

typedef enum
{
    PCLK_TIMER_0,
    PCLK_TIMER_1,
    PCLK_TIMER_2,
    PCLK_TIMER_3,
    PCLK_TIMER_4,
    PCLK_TIMER_5_6,
    PCLK_TIMER_9_10,
    PCLK_TIMER_14,
    PCLK_TIMER_20,
    PCLK_TIMER_21,
} Pclk_TimerEnum_t;
KF_STATIC_ASSERT((uint32_t)PCLK_TIMER_21 == 9U, "Pclk_TimerEnum_t Integrity Broken");
#define CHECK_PCLK_TIMER(x)                                                                                            \
    (((x) == PCLK_TIMER_0) || ((x) == PCLK_TIMER_1) || ((x) == PCLK_TIMER_2) || ((x) == PCLK_TIMER_3) ||               \
     ((x) == PCLK_TIMER_4) || ((x) == PCLK_TIMER_5_6) || ((x) == PCLK_TIMER_9_10) || ((x) == PCLK_TIMER_14) ||         \
     ((x) == PCLK_TIMER_20) || ((x) == PCLK_TIMER_21))

/******************************************************************************
 *                      Export Variables
 ******************************************************************************/

/******************************************************************************
 *                      Export Functions
 ******************************************************************************/

/**
 * @brief 配置GPIO的外设时钟使能
 *
 * @param GpioIdx 指定Gpio ,取值为 Pclk_Gpio_t
 * @param State 设置状态,取值为
 *               true 模块时钟使能
 *               false 模块时钟禁止
 * @retval 无
 */
KF_INLINE void Pclk_LL_SetGpioEnabled(Pclk_Gpio_t GpioIdx, bool State)
{
    KF_PCLK_ASSERT(CHECK_PCLK_GPIO(GpioIdx));

    REG_BITS_WRITE(PCLK_PTR->CTL0.reg, (1UL << (uint32_t)GpioIdx), ((State ? 1UL : 0UL) << (uint32_t)GpioIdx));
}

/**
 * @brief 配置Timer的外设时钟使能
 *
 * @param TimIdx 指定Timer ,取值为 Pclk_Tim_t
 * @param State 设置状态,取值为
 *               true 模块时钟使能
 *               false 模块时钟禁止
 * @retval 无
 */
KF_INLINE void Pclk_LL_SetTimerEnabled(Pclk_Tim_t TimIdx, bool State)
{
    KF_PCLK_ASSERT(CHECK_PCLK_TIM(TimIdx));

    if ((uint32_t)TimIdx < 0x100U)
    {
        REG_BITS_WRITE(PCLK_PTR->CTL1.reg, (1UL << (uint32_t)TimIdx), ((State ? 1UL : 0UL) << (uint32_t)TimIdx));
    }
    else
    {
        REG_BITS_WRITE(PCLK_PTR->CTL2.reg, (1UL << ((uint32_t)TimIdx & 0x0FFU)),
                       ((State ? 1UL : 0UL) << ((uint32_t)TimIdx & 0x0FFU)));
    }
}

/**
 * @brief 配置Can/Canfd的外设时钟使能
 *
 * @param CanIdx 指定Can/Canfd ,取值为 Pclk_Can_t
 * @param State 设置状态,取值为
 *               true 模块时钟使能
 *               false 模块时钟禁止
 * @retval 无
 */
KF_INLINE void Pclk_LL_SetCanEnabled(Pclk_Can_t CanIdx, bool State)
{
    KF_PCLK_ASSERT(CHECK_PCLK_CAN(CanIdx));

    if ((uint32_t)CanIdx < 0x100U)
    {
        REG_BITS_WRITE(PCLK_PTR->CTL3.reg, (1UL << (uint32_t)CanIdx), ((State ? 1UL : 0UL) << (uint32_t)CanIdx));
    }
    else
    {
        REG_BITS_WRITE(PCLK_PTR->CTL4.reg, (1UL << ((uint32_t)CanIdx & 0x0FFU)),
                       ((State ? 1UL : 0UL) << ((uint32_t)CanIdx & 0x0FFU)));
    }
}

/**
 * @brief 配置ADC的外设时钟使能
 *
 * @param AdcIdx 指定Adc ,取值为 Pclk_Adc_t
 * @param State 设置状态,取值为
 *               true 模块时钟使能
 *               false 模块时钟禁止
 * @retval 无
 */
KF_INLINE void Pclk_LL_SetAdcEnabled(Pclk_Adc_t AdcIdx, bool State)
{
    KF_PCLK_ASSERT(CHECK_PCLK_ADC(AdcIdx));

    REG_BITS_WRITE(PCLK_PTR->CTL1.reg, (1UL << (uint32_t)AdcIdx), ((State ? 1UL : 0UL) << (uint32_t)AdcIdx));
}

/**
 * @brief 配置DMA的外设复时钟使能
 *
 * @param DmaIdx 指定DmaIdx ,取值为 Pclk_Dma_t
 * @param State 设置状态,取值为
 *               true 模块时钟使能
 *               false 模块时钟禁止
 * @retval 无
 */
KF_INLINE void Pclk_LL_SetDmaEnabled(Pclk_Dma_t DmaIdx, bool State)
{
    KF_PCLK_ASSERT(CHECK_PCLK_DMA(DmaIdx));

    REG_BITS_WRITE(PCLK_PTR->CTL2.reg, (1UL << (uint32_t)DmaIdx), ((State ? 1UL : 0UL) << (uint32_t)DmaIdx));
}

/**
 * @brief 配置I2C的外设时钟使能
 *
 * @param I2cIdx 指定I2c ,取值为 Pclk_I2c_t
 * @param State 设置状态,取值为
 *               true 模块时钟使能
 *               false 模块时钟禁止
 * @retval 无
 */
KF_INLINE void Pclk_LL_SetI2cEnabled(Pclk_I2c_t I2cIdx, bool State)
{
    KF_PCLK_ASSERT(CHECK_PCLK_I2C(I2cIdx));

    REG_BITS_WRITE(PCLK_PTR->CTL1.reg, (1UL << (uint32_t)I2cIdx), ((State ? 1UL : 0UL) << (uint32_t)I2cIdx));
}

/**
 * @brief 配置USART的外设时钟使能
 *
 * @param UsartIdx 指定Usart ,取值为 Pclk_Usart_t
 * @param State 设置状态,取值为
 *               true 模块时钟使能
 *               false 模块时钟禁止
 * @retval 无
 */
KF_INLINE void Pclk_LL_SetUsartEnabled(Pclk_Usart_t UsartIdx, bool State)
{
    KF_PCLK_ASSERT(CHECK_PCLK_USART(UsartIdx));

    REG_BITS_WRITE(PCLK_PTR->CTL1.reg, (1UL << (uint32_t)UsartIdx), ((State ? 1UL : 0UL) << (uint32_t)UsartIdx));
}

/**
 * @brief 配置Spi的外设时钟使能
 *
 * @param SpiIdx 指定Spi ,取值为 Pclk_Spi_t
 * @param State 设置状态,取值为
 *               true 模块时钟使能
 *               false 模块时钟禁止
 * @retval 无
 */
KF_INLINE void Pclk_LL_SetSpiEnabled(Pclk_Spi_t SpiIdx, bool State)
{
    KF_PCLK_ASSERT(CHECK_PCLK_SPI(SpiIdx));

    if ((uint32_t)SpiIdx < 0x100U)
    {
        REG_BITS_WRITE(PCLK_PTR->CTL1.reg, (1UL << (uint32_t)SpiIdx), ((State ? 1UL : 0UL) << (uint32_t)SpiIdx));
    }
    else
    {
        REG_BITS_WRITE(PCLK_PTR->CTL3.reg, (1UL << ((uint32_t)SpiIdx & 0x0FFU)),
                       ((State ? 1UL : 0UL) << ((uint32_t)SpiIdx & 0x0FFU)));
    }
}

/**
 * @brief 配置Epwm的外设时钟使能
 *
 * @param EpwmIdx 指定Epwm ,取值为 Pclk_Epwm_t
 * @param State 设置状态,取值为
 *               true 模块时钟使能
 *               false 模块时钟禁止
 * @retval 无
 */
KF_INLINE void Pclk_LL_SetEpwmEnabled(Pclk_Epwm_t EpwmIdx, bool State)
{
    KF_PCLK_ASSERT(CHECK_PCLK_EPWM(EpwmIdx));

    if ((uint32_t)EpwmIdx < 0x100U)
    {
        REG_BITS_WRITE(PCLK_PTR->CTL2.reg, (1UL << (uint32_t)EpwmIdx), ((State ? 1UL : 0UL) << (uint32_t)EpwmIdx));
    }
    else
    {
        REG_BITS_WRITE(PCLK_PTR->CTL4.reg, (1UL << ((uint32_t)EpwmIdx & 0x0FFU)),
                       ((State ? 1UL : 0UL) << ((uint32_t)EpwmIdx & 0x0FFU)));
    }
}

/**
 * @brief 配置PCLK_CTL0控制的外设时钟状态
 *
 * @param PclkCtl0Index 指定外设时钟功能位,取值为 Pclk_Ctl0Index_t
 * @param State 设置状态,取值为
 *               true 模块时钟使能
 *               false 模块时钟禁止
 * @retval 无
 */
KF_INLINE void Pclk_LL_SetCtl0Clock(Pclk_Ctl0Index_t PclkCtl0Index, bool State)
{
    KF_PCLK_ASSERT(CHECK_PCLK_CTL0INDEX(PclkCtl0Index));

    REG_BITS_WRITE(
        PCLK_PTR->CTL0.reg, (1UL << (uint32_t)PclkCtl0Index), ((State ? 1UL : 0UL) << (uint32_t)PclkCtl0Index));
}

/**
 * @brief 配置PCLK_CTL1控制的外设时钟状态
 *
 * @param PclkCtl1Index 指定外设时钟功能位,取值为 Pclk_Ctl1Index_t
 * @param State 设置状态,取值为
 *               true 模块时钟使能
 *               false 模块时钟禁止
 * @retval 无
 */
KF_INLINE void Pclk_LL_SetCtl1Clock(Pclk_Ctl1Index_t PclkCtl1Index, bool State)
{
    KF_PCLK_ASSERT(CHECK_PCLK_CTL1INDEX(PclkCtl1Index));

    REG_BITS_WRITE(
        PCLK_PTR->CTL1.reg, (1UL << (uint32_t)PclkCtl1Index), ((State ? 1UL : 0UL) << (uint32_t)PclkCtl1Index));
}

/**
 * @brief 配置PCLK_CTL2控制的外设时钟状态
 *
 * @param PclkCtl2Index 指定外设时钟功能位,取值为 Pclk_Ctl2Index_t
 * @param State 设置状态,取值为
 *               true 模块时钟使能
 *               false 模块时钟禁止
 * @retval 无
 */
KF_INLINE void Pclk_LL_SetCtl2Clock(Pclk_Ctl2Index_t PclkCtl2Index, bool State)
{
    KF_PCLK_ASSERT(CHECK_PCLK_CTL2INDEX(PclkCtl2Index));

    REG_BITS_WRITE(
        PCLK_PTR->CTL2.reg, (1UL << (uint32_t)PclkCtl2Index), ((State ? 1UL : 0UL) << (uint32_t)PclkCtl2Index));
}

/**
 * @brief 配置PCLK_CTL3控制的外设时钟状态
 *
 * @param PclkCtl3Index 指定外设时钟功能位,取值为 Pclk_Ctl3Index_t
 * @param State 设置状态,取值为
 *               true 模块时钟使能
 *               false 模块时钟禁止
 * @retval 无
 */
KF_INLINE void Pclk_LL_SetCtl3Clock(Pclk_Ctl3Index_t PclkCtl3Index, bool State)
{
    KF_PCLK_ASSERT(CHECK_PCLK_CTL3INDEX(PclkCtl3Index));

    REG_BITS_WRITE(
        PCLK_PTR->CTL3.reg, (1UL << (uint32_t)PclkCtl3Index), ((State ? 1UL : 0UL) << (uint32_t)PclkCtl3Index));
}

/**
 * @brief 配置PCLK_CTL4控制的外设时钟状态
 *
 * @param PclkCtl3Index 指定外设时钟功能位,取值为 Pclk_Ctl4Index_t
 * @param State 设置状态,取值为
 *               true 模块时钟使能
 *               false 模块时钟禁止
 * @retval 无
 */
KF_INLINE void Pclk_LL_SetCtl4Clock(Pclk_Ctl4Index_t PclkCtl4Index, bool State)
{
    KF_PCLK_ASSERT(CHECK_PCLK_CTL4INDEX(PclkCtl4Index));

    REG_BITS_WRITE(
        PCLK_PTR->CTL4.reg, (1UL << (uint32_t)PclkCtl4Index), ((State ? 1UL : 0UL) << (uint32_t)PclkCtl4Index));
}

/**
 * @brief 获取GPIO的外设时钟使能状态
 *
 * @param GpioIdx 指定Gpio ,取值为 Pclk_Gpio_t
 * @retval bool 时钟使能状态
 *               true 模块时钟已使能
 *               false 模块时钟已禁止
 */
KF_INLINE bool Pclk_LL_GetGpioEnabledState(Pclk_Gpio_t GpioIdx)
{
    KF_PCLK_ASSERT(CHECK_PCLK_GPIO(GpioIdx));

    return ((PCLK_PTR->CTL0.reg >> (uint32_t)GpioIdx) & 1U) != 0U;
}

/**
 * @brief 获取Timer的外设时钟使能状态
 *
 * @param TimIdx 指定Timer ,取值为 Pclk_Tim_t
 * @retval bool 时钟使能状态
 *               true 模块时钟已使能
 *               false 模块时钟已禁止
 */
KF_INLINE bool Pclk_LL_GetTimerEnabledState(Pclk_Tim_t TimIdx)
{
    KF_PCLK_ASSERT(CHECK_PCLK_TIM(TimIdx));

    bool ret = false;

    if ((uint32_t)TimIdx < 0x100U)
    {
        ret = ((PCLK_PTR->CTL1.reg >> ((uint32_t)TimIdx)) & 1U) != 0U;
    }
    else
    {
        ret = ((PCLK_PTR->CTL2.reg >> ((uint32_t)TimIdx & 0x0FFU)) & 1U) != 0U;
    }

    return ret;
}

/**
 * @brief 获取Can/Canfd的外设时钟使能状态
 *
 * @param CanIdx 指定Can/Canfd ,取值为 Pclk_Can_t
 * @retval bool 时钟使能状态
 *               true 模块时钟已使能
 *               false 模块时钟已禁止
 */
KF_INLINE bool Pclk_LL_GetCanEnabledState(Pclk_Can_t CanIdx)
{
    KF_PCLK_ASSERT(CHECK_PCLK_CAN(CanIdx));

    bool ret = false;

    if ((uint32_t)CanIdx < 0x100U)
    {
        ret = ((PCLK_PTR->CTL3.reg >> ((uint32_t)CanIdx)) & 1U) != 0U;
    }
    else
    {
        ret = ((PCLK_PTR->CTL4.reg >> ((uint32_t)CanIdx & 0x0FFU)) & 1U) != 0U;
    }

    return ret;
}

/**
 * @brief 获取ADC的外设时钟使能状态
 *
 * @param AdcIdx 指定Adc ,取值为 Pclk_Adc_t
 * @retval bool 时钟使能状态
 *               true 模块时钟已使能
 *               false 模块时钟已禁止
 */
KF_INLINE bool Pclk_LL_GetAdcEnabledState(Pclk_Adc_t AdcIdx)
{
    KF_PCLK_ASSERT(CHECK_PCLK_ADC(AdcIdx));

    return ((PCLK_PTR->CTL1.reg >> (uint32_t)AdcIdx) & 1U) != 0U;
}

/**
 * @brief 获取DMA的外设时钟使能状态
 *
 * @param DmaIdx 指定DmaIdx ,取值为 Pclk_Dma_t
 * @retval bool 时钟使能状态
 *               true 模块时钟已使能
 *               false 模块时钟已禁止
 */
KF_INLINE bool Pclk_LL_GetDmaEnabledState(Pclk_Dma_t DmaIdx)
{
    KF_PCLK_ASSERT(CHECK_PCLK_DMA(DmaIdx));

    return ((PCLK_PTR->CTL2.reg >> (uint32_t)DmaIdx) & 1U) != 0U;
}

/**
 * @brief 获取I2C的外设时钟使能状态
 *
 * @param I2cIdx 指定I2c ,取值为 Pclk_I2c_t
 * @retval bool 时钟使能状态
 *               true 模块时钟已使能
 *               false 模块时钟已禁止
 */
KF_INLINE bool Pclk_LL_GetI2cEnabledState(Pclk_I2c_t I2cIdx)
{
    KF_PCLK_ASSERT(CHECK_PCLK_I2C(I2cIdx));

    return ((PCLK_PTR->CTL1.reg >> ((uint32_t)I2cIdx & 0x0FFU)) & 1U) != 0U;
}

/**
 * @brief 获取USART的外设时钟使能状态
 *
 * @param UsartIdx 指定Usart ,取值为 Pclk_Usart_t
 * @retval bool 时钟使能状态
 *               true 模块时钟已使能
 *               false 模块时钟已禁止
 */
KF_INLINE bool Pclk_LL_GetUsartEnabledState(Pclk_Usart_t UsartIdx)
{
    KF_PCLK_ASSERT(CHECK_PCLK_USART(UsartIdx));

    return ((PCLK_PTR->CTL1.reg >> ((uint32_t)UsartIdx & 0x0FFU)) & 1U) != 0U;
}

/**
 * @brief 获取Spi的外设时钟使能状态
 *
 * @param SpiIdx 指定Spi ,取值为 Pclk_Spi_t
 * @retval bool 时钟使能状态
 *               true 模块时钟已使能
 *               false 模块时钟已禁止
 */
KF_INLINE bool Pclk_LL_GetSpiEnabledState(Pclk_Spi_t SpiIdx)
{
    KF_PCLK_ASSERT(CHECK_PCLK_SPI(SpiIdx));

    bool ret = false;

    if ((uint32_t)SpiIdx < 0x100U)
    {
        ret = ((PCLK_PTR->CTL1.reg >> ((uint32_t)SpiIdx)) & 1U) != 0U;
    }
    else
    {
        ret = ((PCLK_PTR->CTL3.reg >> ((uint32_t)SpiIdx & 0x0FFU)) & 1U) != 0U;
    }

    return ret;
}

/**
 * @brief 获取Epwm的外设时钟使能状态
 *
 * @param EpwmIdx 指定Epwm ,取值为 Pclk_Epwm_t
 * @retval bool 时钟使能状态
 *               true 模块时钟已使能
 *               false 模块时钟已禁止
 */
KF_INLINE bool Pclk_LL_GetEpwmEnabledState(Pclk_Epwm_t EpwmIdx)
{
    KF_PCLK_ASSERT(CHECK_PCLK_EPWM(EpwmIdx));

    bool ret = false;

    if ((uint32_t)EpwmIdx < 0x100U)
    {
        ret = ((PCLK_PTR->CTL2.reg >> ((uint32_t)EpwmIdx)) & 1U) != 0U;
    }
    else
    {
        ret = ((PCLK_PTR->CTL4.reg >> ((uint32_t)EpwmIdx & 0x0FFU)) & 1U) != 0U;
    }

    return ret;
}
#ifdef __cplusplus
}
#endif /*End of __cplusplus*/
#endif /*End of KF32A158SF_DRV_PCLK_H*/
/* EOF */
