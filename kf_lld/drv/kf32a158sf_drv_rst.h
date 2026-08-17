/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name        : kf32a158sf_drv_rst.h
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
#ifndef KF32A158SF_DRV_RST_H
#define KF32A158SF_DRV_RST_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 *                      QAC Warnings
 ******************************************************************************/
/* PRQA S 0288 EOF #KQR000288 */
/* PRQA S 0303,0306 EOF #KQR100303 */
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
#include "dev_assert.h"
#include "kf32a158sf_reg_rst.h"

#ifdef KF_DRV_RST_ASSERT
#include "dev_assert.h"
#define KF_RST_ASSERT(x) KF_DEV_ASSERT(x)
#else
#define KF_RST_ASSERT(x) ((void)0U)
#endif

/******************************************************************************
 *                      Macro or Inline
 ******************************************************************************/

/******************************************************************************
 *                      Type definitions
 ******************************************************************************/

typedef enum
{
    RST_IDX_GPIOARST = 0U,
    RST_IDX_GPIOBRST = 1U,
    RST_IDX_GPIOCRST = 2U,
    RST_IDX_GPIODRST = 3U,
    RST_IDX_GPIOERST = 4U,
    RST_IDX_GPIOFRST = 5U,
    RST_IDX_GPIOGRST = 6U,
    RST_IDX_GPIOHRST = 7U,
} Rst_Ctl0Index_t;
#define CHECK_RST_CTL0INDEX(x) (((x) >= RST_IDX_GPIOARST) && ((x) <= RST_IDX_GPIOHRST))

typedef enum
{
    RST_IDX_T1RST     = 2U,
    RST_IDX_T2RST     = 3U,
    RST_IDX_T3RST     = 4U,
    RST_IDX_T4RST     = 5U,
    RST_IDX_T5T6RST   = 6U,
    RST_IDX_T9T10RST  = 8U,
    RST_IDX_ADC0RST   = 11U,
    RST_IDX_ADC1RST   = 12U,
    RST_IDX_ADC2RST   = 13U,
    RST_IDX_CMPRST    = 16U,
    RST_IDX_T0RST     = 17U,
    RST_IDX_USART0RST = 19U,
    RST_IDX_USART1RST = 20U,
    RST_IDX_USART2RST = 21U,
    RST_IDX_USART3RST = 22U,
    RST_IDX_USART6RST = 23U,
    RST_IDX_SPI0RST   = 24U,
    RST_IDX_SPI1RST   = 25U,
    RST_IDX_I2C0RST   = 26U,
    RST_IDX_I2C1RST   = 27U,
    RST_IDX_I2C2RST   = 28U,
    RST_IDX_MPURST    = 30U
} Rst_Ctl1Index_t;
#define CHECK_RST_CTL1INDEX(x)                                                                                         \
    (((x) == RST_IDX_T1RST) || ((x) == RST_IDX_T2RST) || ((x) == RST_IDX_T3RST) || ((x) == RST_IDX_T4RST) ||           \
     ((x) == RST_IDX_T5T6RST) || ((x) == RST_IDX_T9T10RST) || ((x) == RST_IDX_ADC0RST) || ((x) == RST_IDX_ADC1RST) ||  \
     ((x) == RST_IDX_ADC2RST) || ((x) == RST_IDX_CMPRST) || ((x) == RST_IDX_T0RST) || ((x) == RST_IDX_USART0RST) ||    \
     ((x) == RST_IDX_USART1RST) || ((x) == RST_IDX_USART2RST) || ((x) == RST_IDX_USART3RST) ||                         \
     ((x) == RST_IDX_USART6RST) || ((x) == RST_IDX_SPI0RST) || ((x) == RST_IDX_SPI1RST) || ((x) == RST_IDX_I2C0RST) || \
     ((x) == RST_IDX_I2C1RST) || ((x) == RST_IDX_I2C2RST) || ((x) == RST_IDX_MPURST))

typedef enum
{
    RST_IDX_ISMUTESTRST = 4U,
    RST_IDX_WWDTRST     = 5U,
    RST_IDX_EPWM11RST   = 8U,
    RST_IDX_EPWM12RST   = 9U,
    RST_IDX_EPWM13RST   = 10U,
    RST_IDX_EPWM16RST   = 11U,
    RST_IDX_DMA0RST     = 12U,
    RST_IDX_AES1RST     = 13U,
    RST_IDX_DMA1RST     = 14U,
    RST_IDX_ECC18RST    = 15U,
    RST_IDX_T14RST      = 16U,
    RST_IDX_ECC17RST    = 18U,
    RST_IDX_ECC16RST    = 19U,
    RST_IDX_T20RST      = 23U,
    RST_IDX_T21RST      = 24U,
    RST_IDX_SYSTICK1RST = 25U,
} Rst_Ctl2Index_t;
#define CHECK_RST_CTL2INDEX(x)                                                                                         \
    (((x) == RST_IDX_ISMUTESTRST) || ((x) == RST_IDX_WWDTRST) || ((x) == RST_IDX_EPWM11RST) ||                         \
     ((x) == RST_IDX_EPWM12RST) || ((x) == RST_IDX_EPWM13RST) || ((x) == RST_IDX_EPWM16RST) ||                         \
     ((x) == RST_IDX_DMA0RST) || ((x) == RST_IDX_AES1RST) || ((x) == RST_IDX_DMA1RST) || ((x) == RST_IDX_ECC18RST) ||  \
     ((x) == RST_IDX_T14RST) || ((x) == RST_IDX_ECC17RST) || ((x) == RST_IDX_ECC16RST) || ((x) == RST_IDX_T20RST) ||   \
     ((x) == RST_IDX_T21RST) || ((x) == RST_IDX_SYSTICK1RST))

typedef enum
{
    RST_IDX_SPI2RST      = 1U,
    RST_IDX_REMAPTESTRST = 11U,
    RST_IDX_CMURST       = 12U,
    RST_IDX_CRCRST       = 13U,
    RST_IDX_AESRST       = 14U,
    RST_IDX_FLEXMUXRST   = 21U,
    RST_IDX_FLEXRMRST    = 25U,
    RST_IDX_EWDTRST      = 27U,
    RST_IDX_CANFD6RST    = 29U,
    RST_IDX_CANFD7RST    = 30U,
    RST_IDX_ECC15RST     = 31U
} Rst_Ctl3Index_t;
#define CHECK_RST_CTL3INDEX(x)                                                                                         \
    (((x) == RST_IDX_SPI2RST) || ((x) == RST_IDX_REMAPTESTRST) || ((x) == RST_IDX_CMURST) ||                           \
     ((x) == RST_IDX_CRCRST) || ((x) == RST_IDX_AESRST) || ((x) == RST_IDX_FLEXMUXRST) ||                              \
     ((x) == RST_IDX_FLEXRMRST) || ((x) == RST_IDX_EWDTRST) || ((x) == RST_IDX_CANFD6RST) ||                           \
     ((x) == RST_IDX_CANFD7RST) || ((x) == RST_IDX_ECC15RST))

typedef enum
{
    RST_IDX_CANFD8RST = 0U,
    RST_IDX_CANFD9RST = 1U,
    RST_IDX_SHARST    = 2U,
    RST_IDX_RSARST    = 3U,
    RST_IDX_ECC4RST   = 10U,
    RST_IDX_ECC5RST   = 11U,
    RST_IDX_ECC13RST  = 19U,
    RST_IDX_ECC0RST   = 20U,
    RST_IDX_ECC1RST   = 21U,
    RST_IDX_ECC19RST  = 24U,
    RST_IDX_ECC20RST  = 25U,
    RST_IDX_EPWM31RST = 26U,
    RST_IDX_EPWM32RST = 27U,
    RST_IDX_EPWM33RST = 28U,
    RST_IDX_EPWM36RST = 29U,
} Rst_Ctl4Index_t;
#define CHECK_RST_CTL4INDEX(x)                                                                                         \
    (((x) == RST_IDX_CANFD8RST) || ((x) == RST_IDX_CANFD9RST) || ((x) == RST_IDX_SHARST) || ((x) == RST_IDX_RSARST) || \
     ((x) == RST_IDX_ECC4RST) || ((x) == RST_IDX_ECC5RST) || ((x) == RST_IDX_ECC13RST) || ((x) == RST_IDX_ECC0RST) ||  \
     ((x) == RST_IDX_ECC1RST) || ((x) == RST_IDX_ECC19RST) || ((x) == RST_IDX_ECC20RST) ||                             \
     ((x) == RST_IDX_EPWM31RST) || ((x) == RST_IDX_EPWM32RST) || ((x) == RST_IDX_EPWM33RST) ||                         \
     ((x) == RST_IDX_EPWM36RST))

typedef enum
{
    RST_GPIO_A = 0U,
    RST_GPIO_B = 1U,
    RST_GPIO_C = 2U,
    RST_GPIO_D = 3U,
    RST_GPIO_E = 4U,
    RST_GPIO_F = 5U,
    RST_GPIO_G = 6U,
    RST_GPIO_H = 7U,
} Rst_Gpio_t;
#define CHECK_RST_GPIO(x)                                                                                              \
    (((x) == RST_GPIO_A) || ((x) == RST_GPIO_B) || ((x) == RST_GPIO_C) || ((x) == RST_GPIO_D) ||                       \
     ((x) == RST_GPIO_E) || ((x) == RST_GPIO_F) || ((x) == RST_GPIO_G) || ((x) == RST_GPIO_H))

typedef enum
{
    RST_T1    = 2U,
    RST_T2    = 3U,
    RST_T3    = 4U,
    RST_T4    = 5U,
    RST_T5T6  = 6U,
    RST_T9T10 = 8U,
    RST_T0    = 17U,

    RST_T14 = 0x100U + 16U,
    RST_T20 = 0x100U + 23U,
    RST_T21 = 0x100U + 24U,
} Rst_Tim_t;
#define CHECK_RST_TIM(x)                                                                                               \
    (((x) == RST_T1) || ((x) == RST_T2) || ((x) == RST_T3) || ((x) == RST_T4) || ((x) == RST_T5T6) ||                  \
     ((x) == RST_T9T10) || ((x) == RST_T0) || ((x) == RST_T14) || ((x) == RST_T20) || ((x) == RST_T21))

typedef enum
{
    RST_CANFD6 = 29U,
    RST_CANFD7 = 30U,

    RST_CANFD8 = 0x100U + 0U,
    RST_CANFD9 = 0x100U + 1U,
} Rst_Can_t;
#define CHECK_RST_CAN(x) (((x) == RST_CANFD6) || ((x) == RST_CANFD7) || ((x) == RST_CANFD8) || ((x) == RST_CANFD9))

typedef enum
{
    RST_ADC0 = 11U,
    RST_ADC1 = 12U,
} Rst_Adc_t;
#define CHECK_RST_ADC(x) (((x) == RST_ADC0) || ((x) == RST_ADC1))

typedef enum
{
    RST_DMA0 = 12U,
    RST_DMA1 = 14U,
} Rst_Dma_t;
#define CHECK_RST_DMA(x) (((x) == RST_DMA0) || ((x) == RST_DMA1))

typedef enum
{
    RST_I2C0 = 26U,
    RST_I2C1 = 27U,
    RST_I2C2 = 28U,
} Rst_I2c_t;
#define CHECK_RST_I2C(x) (((x) == RST_I2C0) || ((x) == RST_I2C1) || ((x) == RST_I2C2))

typedef enum
{
    RST_USART0 = 19U,
    RST_USART1 = 20U,
    RST_USART2 = 21U,
    RST_USART3 = 22U,
    RST_USART6 = 23U,
} Rst_Usart_t;
#define CHECK_RST_USART(x)                                                                                             \
    (((x) == RST_USART0) || ((x) == RST_USART1) || ((x) == RST_USART2) || ((x) == RST_USART3) || ((x) == RST_USART6))

typedef enum
{
    RST_SPI0 = 24U,
    RST_SPI1 = 25U,

    RST_SPI2 = 0x100U + 1U,

} Rst_Spi_t;
#define CHECK_RST_SPI(x) (((x) == RST_SPI0) || ((x) == RST_SPI1) || ((x) == RST_SPI2))

typedef enum
{
    RST_SPI_0,
    RST_SPI_1,
    RST_SPI_2,
} Rst_SpiEnum_t;
KF_STATIC_ASSERT((uint32_t)RST_SPI_2 == 2UL, "Rst_SpiEnum_t Integrity Broken");
#define CHECK_RST_INDEX_SPI(x) (((x) == RST_SPI_0) || ((x) == RST_SPI_1) || ((x) == RST_SPI_2))

typedef enum
{
    RST_EPWM11 = 8U,
    RST_EPWM12 = 9U,
    RST_EPWM13 = 10U,
    RST_EPWM16 = 11U,
    RST_EPWM31 = 0x100U + 26U,
    RST_EPWM32 = 0x100U + 27U,
    RST_EPWM33 = 0x100U + 28U,
    RST_EPWM36 = 0x100U + 29U,
} Rst_Epwm_t;
#define CHECK_RST_EPWM(x)                                                                                              \
    (((x) == RST_EPWM11) || ((x) == RST_EPWM12) || ((x) == RST_EPWM13) || ((x) == RST_EPWM16) ||                       \
     ((x) == RST_EPWM31) || ((x) == RST_EPWM32) || ((x) == RST_EPWM33) || ((x) == RST_EPWM36))

typedef enum
{
    RST_TIMER_0,
    RST_TIMER_1,
    RST_TIMER_2,
    RST_TIMER_3,
    RST_TIMER_4,
    RST_TIMER_5_6,
    RST_TIMER_9_10,
    RST_TIMER_14,
    RST_TIMER_20,
    RST_TIMER_21,
} Rst_TimerEnum_t;
KF_STATIC_ASSERT((uint32_t)RST_TIMER_21 == 9UL, "Rst_TimerEnum_t Integrity Broken");
#define CHECK_RST_TIMER(x)                                                                                             \
    (((x) == RST_TIMER_0) || ((x) == RST_TIMER_1) || ((x) == RST_TIMER_2) || ((x) == RST_TIMER_3) ||                   \
     ((x) == RST_TIMER_4) || ((x) == RST_TIMER_5_6) || ((x) == RST_TIMER_9_10) || ((x) == RST_TIMER_14) ||             \
     ((x) == RST_TIMER_20) || ((x) == RST_TIMER_21))
/******************************************************************************
 *                      Export Variables
 ******************************************************************************/

/******************************************************************************
 *                      Export Functions
 ******************************************************************************/

/**
 * @brief 配置GPIO的外设复位状态
 *
 * @param GpioIdx 指定Gpio ,取值为 Rst_Gpio_t
 * @param State 设置状态
 *               true  使能, 退出复位状态
 *               false 不使能, 进入复位状态
 * @return void
 */
KF_INLINE void Rst_LL_SetGpioEnabled(Rst_Gpio_t GpioIdx, bool State)
{
    KF_RST_ASSERT(CHECK_RST_GPIO(GpioIdx));

    REG_BITS_WRITE(RESET_PTR->CTL0.reg, (1UL << (uint32_t)GpioIdx), ((State ? 0UL : 1UL) << (uint32_t)GpioIdx));
}

/**
 * @brief 配置Timer的外设复位状态
 *
 * @param TimIdx 指定Timer ,取值为 Rst_Tim_t
 * @param State 设置状态
 *               true  使能, 退出复位状态
 *               false 不使能, 进入复位状态
 * @return void
 */
KF_INLINE void Rst_LL_SetTimerEnabled(Rst_Tim_t TimIdx, bool State)
{
    KF_RST_ASSERT(CHECK_RST_TIM(TimIdx));

    if ((uint32_t)TimIdx < 0x100U)
    {
        REG_BITS_WRITE(RESET_PTR->CTL1.reg, (1UL << (uint32_t)TimIdx), ((State ? 0UL : 1UL) << (uint32_t)TimIdx));
    }
    else
    {
        REG_BITS_WRITE(RESET_PTR->CTL2.reg, (1UL << ((uint32_t)TimIdx & 0x0FFU)),
                       ((State ? 0UL : 1UL) << ((uint32_t)TimIdx & 0x0FFU)));
    }
}

/**
 * @brief 配置Can/Canfd的外设复位状态
 *
 * @param CanIdx 指定Can/Canfd ,取值为 Rst_Can_t
 * @param State 设置状态
 *               true  使能, 退出复位状态
 *               false 不使能, 进入复位状态
 * @return void
 */
KF_INLINE void Rst_LL_SetCanEnabled(Rst_Can_t CanIdx, bool State)
{
    KF_RST_ASSERT(CHECK_RST_CAN(CanIdx));

    if ((uint32_t)CanIdx < 0x100U)
    {
        REG_BITS_WRITE(RESET_PTR->CTL3.reg, (1UL << (uint32_t)CanIdx), ((State ? 0UL : 1UL) << (uint32_t)CanIdx));
    }
    else
    {
        REG_BITS_WRITE(RESET_PTR->CTL4.reg, (1UL << ((uint32_t)CanIdx & 0x0FFU)),
                       ((State ? 0UL : 1UL) << ((uint32_t)CanIdx & 0x0FFU)));
    }
}

/**
 * @brief 配置ADC的外设复位状态
 *
 * @param AdcIdx 指定Adc ,取值为 Rst_Adc_t
 * @param State 设置状态
 *               true  使能, 退出复位状态
 *               false 不使能, 进入复位状态
 * @return void
 */
KF_INLINE void Rst_LL_SetAdcEnabled(Rst_Adc_t AdcIdx, bool State)
{
    KF_RST_ASSERT(CHECK_RST_ADC(AdcIdx));

    REG_BITS_WRITE(RESET_PTR->CTL1.reg, (1UL << (uint32_t)AdcIdx), ((State ? 0UL : 1UL) << (uint32_t)AdcIdx));
}

/**
 * @brief  配置DMA的外设复位状态
 *
 * @param DmaIdx 指定DmaIdx ,取值为 Rst_Dma_t
 * @param State 设置状态
 *               true  使能, 退出复位状态
 *               false 不使能, 进入复位状态
 * @return void
 */
KF_INLINE void Rst_LL_SetDmaEnabled(Rst_Dma_t DmaIdx, bool State)
{
    KF_RST_ASSERT(CHECK_RST_DMA(DmaIdx));

    REG_BITS_WRITE(RESET_PTR->CTL2.reg, (1UL << (uint32_t)DmaIdx), ((State ? 0UL : 1UL) << (uint32_t)DmaIdx));
}

/**
 * @brief 配置I2C的外设复位状态
 *
 * @param I2cIdx 指定I2c ,取值为 Rst_I2c_t
 * @param State 设置状态
 *               true  使能, 退出复位状态
 *               false 不使能, 进入复位状态
 * @return void
 */
KF_INLINE void Rst_LL_SetI2cEnabled(Rst_I2c_t I2cIdx, bool State)
{
    KF_RST_ASSERT(CHECK_RST_I2C(I2cIdx));

    REG_BITS_WRITE(RESET_PTR->CTL1.reg, (1UL << ((uint32_t)I2cIdx & 0x0FFU)),
                   ((State ? 0UL : 1UL) << ((uint32_t)I2cIdx & 0x0FFU)));
}

/**
 * @brief 配置USART的外设复位状态
 *
 * @param UsartIdx 指定Usart ,取值为 Rst_Usart_t
 * @param State 设置状态
 *               true  使能, 退出复位状态
 *               false 不使能, 进入复位状态
 * @return void
 */
KF_INLINE void Rst_LL_SetUsartEnabled(Rst_Usart_t UsartIdx, bool State)
{
    KF_RST_ASSERT(CHECK_RST_USART(UsartIdx));

    REG_BITS_WRITE(RESET_PTR->CTL1.reg, (1UL << ((uint32_t)UsartIdx & 0x0FFU)),
                   ((State ? 0UL : 1UL) << ((uint32_t)UsartIdx & 0x0FFU)));
}

/**
 * @brief 配置SPI的外设复位状态
 * @param SpiIdx 指定Spi ,取值为 Rst_Spi_t
 * @param State 设置状态
 *               true  使能, 退出复位状态
 *               false 不使能, 进入复位状态
 * @retval 无
 */
KF_INLINE void Rst_LL_SetSpiEnabled(Rst_Spi_t SpiIdx, bool State)
{
    KF_RST_ASSERT(CHECK_RST_SPI(SpiIdx));

    if ((uint32_t)SpiIdx < 0x100U)
    {
        REG_BITS_WRITE(RESET_PTR->CTL1.reg, (1UL << (uint32_t)SpiIdx), ((State ? 0UL : 1UL) << (uint32_t)SpiIdx));
    }
    else
    {
        REG_BITS_WRITE(RESET_PTR->CTL3.reg, (1UL << ((uint32_t)SpiIdx & 0x0FFU)),
                       ((State ? 0UL : 1UL) << ((uint32_t)SpiIdx & 0x0FFU)));
    }
}

/**
 * @brief 配置EPWM的外设复位状态
 *
 * @param EpwmIdx 指定Epwm ,取值为 Rst_Epwm_t
 * @param State 设置状态
 *               true  使能, 退出复位状态
 *               false 不使能, 进入复位状态
 * @return void
 */
KF_INLINE void Rst_LL_SetEpwmEnabled(Rst_Epwm_t EpwmIdx, bool State)
{
    KF_RST_ASSERT(CHECK_RST_EPWM(EpwmIdx));

    if ((uint32_t)EpwmIdx < 0x100U)
    {
        REG_BITS_WRITE(RESET_PTR->CTL2.reg, (1UL << (uint32_t)EpwmIdx), ((State ? 0UL : 1UL) << (uint32_t)EpwmIdx));
    }
    else
    {
        REG_BITS_WRITE(RESET_PTR->CTL4.reg, (1UL << ((uint32_t)EpwmIdx & 0x0FFU)),
                       ((State ? 0UL : 1UL) << ((uint32_t)EpwmIdx & 0x0FFU)));
    }
}

/**
 * @brief 配置RST_CTL0控制的外设复位状态
 * @param RstCtl0Index 指定外设复位功能位,取值为
 * @param State 设置状态,取值为
 *               true 复位
 *               false 无作用
 * @retval 无
 */
KF_INLINE void Rst_LL_SetCtl0State(Rst_Ctl0Index_t RstCtl0Index, bool State)
{
    KF_RST_ASSERT(CHECK_RST_CTL0INDEX(RstCtl0Index));

    REG_BITS_WRITE(
        RESET_PTR->CTL0.reg, (1UL << (uint32_t)RstCtl0Index), ((State ? 1UL : 0UL) << (uint32_t)RstCtl0Index));
}

/**
 * @brief 配置RST_CTL1控制的外设复位状态
 * @param RstCtl1Index 指定外设复位功能位,取值为 Rst_Ctl1Index_t
 * @param State 设置状态,取值为
 *               true 复位
 *               false 无作用
 * @retval 无
 */
KF_INLINE void Rst_LL_SetCtl1State(Rst_Ctl1Index_t RstCtl1Index, bool State)
{
    KF_RST_ASSERT(CHECK_RST_CTL1INDEX(RstCtl1Index));

    REG_BITS_WRITE(
        RESET_PTR->CTL1.reg, (1UL << (uint32_t)RstCtl1Index), ((State ? 1UL : 0UL) << (uint32_t)RstCtl1Index));
}

/**
 * @brief 配置RST_CTL2控制的外设复位状态
 * @param RstCtl2Index 指定外设复位功能位,取值为 Rst_Ctl2Index_t
 * @param State 设置状态,取值为
 *               true 复位
 *               false 无作用
 * @retval 无
 */
KF_INLINE void Rst_LL_SetCtl2State(Rst_Ctl2Index_t RstCtl2Index, bool State)
{
    KF_RST_ASSERT(CHECK_RST_CTL2INDEX(RstCtl2Index));

    REG_BITS_WRITE(
        RESET_PTR->CTL2.reg, (1UL << (uint32_t)RstCtl2Index), ((State ? 1UL : 0UL) << (uint32_t)RstCtl2Index));
}

/**
 * @brief 配置RST_CTL3控制的外设复位状态
 * @param RstCtl3Index 指定外设复位功能位,取值为 Rst_Ctl3Index_t
 * @param State 设置状态,取值为
 *               true 复位
 *               false 无作用
 * @retval 无
 */
KF_INLINE void Rst_LL_SetCtl3State(Rst_Ctl3Index_t RstCtl3Index, bool State)
{
    KF_RST_ASSERT(CHECK_RST_CTL3INDEX(RstCtl3Index));

    REG_BITS_WRITE(
        RESET_PTR->CTL3.reg, (1UL << (uint32_t)RstCtl3Index), ((State ? 1UL : 0UL) << (uint32_t)RstCtl3Index));
}

/**
 * @brief 配置RST_CTL4控制的外设复位状态
 * @param RstCtl3Index 指定外设复位功能位,取值为 Rst_Ctl4Index_t
 * @param State 设置状态,取值为
 *               true 复位
 *               false 无作用
 * @retval 无
 */
KF_INLINE void Rst_LL_SetCtl4State(Rst_Ctl4Index_t RstCtl4Index, bool State)
{
    KF_RST_ASSERT(CHECK_RST_CTL4INDEX(RstCtl4Index));

    REG_BITS_WRITE(
        RESET_PTR->CTL4.reg, (1UL << (uint32_t)RstCtl4Index), ((State ? 1UL : 0UL) << (uint32_t)RstCtl4Index));
}

#ifdef __cplusplus
}
#endif /*End of __cplusplus*/
#endif /*End of KF32A158SF_DRV_RST_H*/
/* EOF */
