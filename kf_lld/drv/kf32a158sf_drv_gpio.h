/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name        : kf32a158sf_drv_gpio.h
 *  @Date             : 2025-07-07
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
 *  |2025-07-07  |V1.0     |AE Group     |New create
 ******************************************************************************/
#ifndef KF32A158SF_DRV_GPIO_H
#define KF32A158SF_DRV_GPIO_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 *                      QAC Warnings
 ******************************************************************************/
/* PRQA S 0288 EOF #KQR000288 */
/* PRQA S 3205 EOF #KQR003205 */
/* PRQA S 3219 EOF #KQR003219 */
/* PRQA S 3469 EOF #KQR003469 */
/* PRQA S 3473 EOF #KQR003473 */
/* PRQA S 4342 EOF #KQR004342 */

/******************************************************************************
 *                      Include Files
 ******************************************************************************/
#include <stdint.h>
#include <stdbool.h>
#include "kf_types.h"
#include "kf32a158sf_reg_gpio.h"

#ifdef KF_DRV_GPIO_ASSERT
#include "dev_assert.h"
#define KF_GPIO_ASSERT(x) KF_DEV_ASSERT(x)
#else
#define KF_GPIO_ASSERT(x) ((void)0U)
#endif
/******************************************************************************
 *                      Macro or Inline
 ******************************************************************************/
#define GPIO_PIN_1BIT_MASK (0x01U)
#define GPIO_PIN_2BIT_MASK (0x03U)
#define GPIO_PIN_4BIT_MASK (0x0FU)
/******************************************************************************
 *                      Type definitions
 ******************************************************************************/
/**
 * GPIO 位域编号
 */
typedef enum
{
    GPIO_PIN_MASK_0  = 1UL << (0x0U),
    GPIO_PIN_MASK_1  = 1UL << (0x1U),
    GPIO_PIN_MASK_2  = 1UL << (0x2U),
    GPIO_PIN_MASK_3  = 1UL << (0x3U),
    GPIO_PIN_MASK_4  = 1UL << (0x4U),
    GPIO_PIN_MASK_5  = 1UL << (0x5U),
    GPIO_PIN_MASK_6  = 1UL << (0x6U),
    GPIO_PIN_MASK_7  = 1UL << (0x7U),
    GPIO_PIN_MASK_8  = 1UL << (0x8U),
    GPIO_PIN_MASK_9  = 1UL << (0x9U),
    GPIO_PIN_MASK_10 = 1UL << (0xAU),
    GPIO_PIN_MASK_11 = 1UL << (0xBU),
    GPIO_PIN_MASK_12 = 1UL << (0xCU),
    GPIO_PIN_MASK_13 = 1UL << (0xDU),
    GPIO_PIN_MASK_14 = 1UL << (0xEU),
    GPIO_PIN_MASK_15 = 1UL << (0xFU),
    /* other combinations of masks ... */
    GPIO_PIN_MASK_All = 0xFFFFU
} Gpio_PinMask_t;
#define CHECK_GPIO_PIN_MASK(PIN_MASK) ((PIN_MASK) <= GPIO_PIN_MASK_15)

/**
 * @brief GPIO PIN 0~15
 */
typedef enum
{
    GPIO_PIN_INDEX_0,
    GPIO_PIN_INDEX_1,
    GPIO_PIN_INDEX_2,
    GPIO_PIN_INDEX_3,
    GPIO_PIN_INDEX_4,
    GPIO_PIN_INDEX_5,
    GPIO_PIN_INDEX_6,
    GPIO_PIN_INDEX_7,
    GPIO_PIN_INDEX_8,
    GPIO_PIN_INDEX_9,
    GPIO_PIN_INDEX_10,
    GPIO_PIN_INDEX_11,
    GPIO_PIN_INDEX_12,
    GPIO_PIN_INDEX_13,
    GPIO_PIN_INDEX_14,
    GPIO_PIN_INDEX_15
} Gpio_PinIndex_t;
#define CHECK_GPIO_PIN_INDEX(PIN_INDEX) ((PIN_INDEX) <= (uint32_t)GPIO_PIN_INDEX_15)

/**
 * GPIO上拉/下拉
 */
typedef enum
{
    GPIO_PIN_NOPULL,
    GPIO_PIN_PULLEN
} GPIO_PinPu_t, GPIO_PinPd_t;

#define CHECK_GPIO_PU(PU) (((PU) == GPIO_NOPULL) || ((PU) == GPIO_PULLEN))
#define CHECK_GPIO_PD(PD) (((PD) == GPIO_NOPULL) || ((PD) == GPIO_PULLEN))

/**
 * @brief GPIO Pull(up/down/none)
 */
typedef enum
{
    GPIO_PULL_NONE,
    GPIO_PULL_UP,
    GPIO_PULL_DOWN,
    GPIO_PULL_BOTH
} Gpio_Pull_t;
#define CHECK_GPIO_PULL(PULL_MODE) ((PULL_MODE) <= (uint32_t)GPIO_PULL_DOWN)

/**
 * GPIO开漏输出类型
 */
typedef enum
{
    GPIO_PIN_POD_PP,
    GPIO_POD_OD
} GPIO_PinOd_t;
#define CHECK_GPIO_POD(OTYPE) (((OTYPE) == GPIO_POD_PP) || ((OTYPE) == GPIO_POD_OD))

/**
 * @brief GPIO模式类型
 */
typedef enum
{
    GPIO_PIN_MODE_IN,
    GPIO_PIN_MODE_OUT,
    GPIO_PIN_MODE_REMAP,
    GPIO_PIN_MODE_AN
} Gpio_PinMode_t;
#define CHECK_GPIO_PIN_MODE(PIN_MODE) ((PIN_MODE) <= GPIO_PIN_MODE_AN)

/**
 * @brief GPIO速度
 */
typedef enum
{
    GPIO_PIN_SPEED_10M,
    GPIO_PIN_SPEED_20M
} Gpio_PinSpeed_t;
#define CHECK_GPIO_PIN_SPEED(PIN_SPEED) (((PIN_SPEED) == GPIO_PIN_SPEED_10M) || ((PIN_SPEED) == GPIO_PIN_SPEED_20M))

/**
 * GPIO引脚重映射
 */
typedef enum
{
    GPIO_PIN_RMP_PAGE1_AF0  = 0x0000U,
    GPIO_PIN_RMP_PAGE1_AF1  = 0x0001U,
    GPIO_PIN_RMP_PAGE1_AF2  = 0x0002U,
    GPIO_PIN_RMP_PAGE1_AF3  = 0x0003U,
    GPIO_PIN_RMP_PAGE1_AF4  = 0x0004U,
    GPIO_PIN_RMP_PAGE1_AF5  = 0x0005U,
    GPIO_PIN_RMP_PAGE1_AF6  = 0x0006U,
    GPIO_PIN_RMP_PAGE1_AF7  = 0x0007U,
    GPIO_PIN_RMP_PAGE1_AF8  = 0x0008U,
    GPIO_PIN_RMP_PAGE1_AF9  = 0x0009U,
    GPIO_PIN_RMP_PAGE1_AF10 = 0x000AU,
    GPIO_PIN_RMP_PAGE1_AF11 = 0x000BU,
    GPIO_PIN_RMP_PAGE1_AF12 = 0x000CU,
    GPIO_PIN_RMP_PAGE1_AF13 = 0x000DU,
    GPIO_PIN_RMP_PAGE1_AF14 = 0x000EU,
    GPIO_PIN_RMP_PAGE1_AF15 = 0x000FU,

    GPIO_PIN_RMP_PAGE2_AF0  = 0x0100U,
    GPIO_PIN_RMP_PAGE2_AF1  = 0x0101U,
    GPIO_PIN_RMP_PAGE2_AF2  = 0x0102U,
    GPIO_PIN_RMP_PAGE2_AF3  = 0x0103U,
    GPIO_PIN_RMP_PAGE2_AF4  = 0x0104U,
    GPIO_PIN_RMP_PAGE2_AF5  = 0x0105U,
    GPIO_PIN_RMP_PAGE2_AF6  = 0x0106U,
    GPIO_PIN_RMP_PAGE2_AF7  = 0x0107U,
    GPIO_PIN_RMP_PAGE2_AF8  = 0x0108U,
    GPIO_PIN_RMP_PAGE2_AF9  = 0x0109U,
    GPIO_PIN_RMP_PAGE2_AF10 = 0x010AU,
    GPIO_PIN_RMP_PAGE2_AF11 = 0x010BU,
    GPIO_PIN_RMP_PAGE2_AF12 = 0x010CU,
    GPIO_PIN_RMP_PAGE2_AF13 = 0x010DU,
    GPIO_PIN_RMP_PAGE2_AF14 = 0x010EU,
    GPIO_PIN_RMP_PAGE2_AF15 = 0x010FU,

    GPIO_PIN_RMP_PAGE3_AF0  = 0x0200U,
    GPIO_PIN_RMP_PAGE3_AF1  = 0x0201U,
    GPIO_PIN_RMP_PAGE3_AF2  = 0x0202U,
    GPIO_PIN_RMP_PAGE3_AF3  = 0x0203U,
    GPIO_PIN_RMP_PAGE3_AF4  = 0x0204U,
    GPIO_PIN_RMP_PAGE3_AF5  = 0x0205U,
    GPIO_PIN_RMP_PAGE3_AF6  = 0x0206U,
    GPIO_PIN_RMP_PAGE3_AF7  = 0x0207U,
    GPIO_PIN_RMP_PAGE3_AF8  = 0x0208U,
    GPIO_PIN_RMP_PAGE3_AF9  = 0x0209U,
    GPIO_PIN_RMP_PAGE3_AF10 = 0x020AU,
    GPIO_PIN_RMP_PAGE3_AF11 = 0x020BU,
    GPIO_PIN_RMP_PAGE3_AF12 = 0x020CU,
    GPIO_PIN_RMP_PAGE3_AF13 = 0x020DU,
    GPIO_PIN_RMP_PAGE3_AF14 = 0x020EU,
    GPIO_PIN_RMP_PAGE3_AF15 = 0x020FU,
} Gpio_PinRemap_t;
#define CHECK_GPIO_PAGE1_REMAP(RMP) (((RMP) <= GPIO_PIN_RMP_PAGE1_AF15) && ((RMP) >= GPIO_PIN_RMP_PAGE1_AF0))
#define CHECK_GPIO_PAGE2_REMAP(RMP) (((RMP) <= GPIO_PIN_RMP_PAGE2_AF15) && ((RMP) >= GPIO_PIN_RMP_PAGE2_AF0))
#define CHECK_GPIO_PAGE3_REMAP(RMP) (((RMP) <= GPIO_PIN_RMP_PAGE3_AF15) && ((RMP) >= GPIO_PIN_RMP_PAGE3_AF0))

/*默认开放PAGE3*/
#define GPIO_PIN_RMP_AF0  GPIO_PIN_RMP_PAGE3_AF0
#define GPIO_PIN_RMP_AF1  GPIO_PIN_RMP_PAGE3_AF1
#define GPIO_PIN_RMP_AF2  GPIO_PIN_RMP_PAGE3_AF2
#define GPIO_PIN_RMP_AF3  GPIO_PIN_RMP_PAGE3_AF3
#define GPIO_PIN_RMP_AF4  GPIO_PIN_RMP_PAGE3_AF4
#define GPIO_PIN_RMP_AF5  GPIO_PIN_RMP_PAGE3_AF5
#define GPIO_PIN_RMP_AF6  GPIO_PIN_RMP_PAGE3_AF6
#define GPIO_PIN_RMP_AF7  GPIO_PIN_RMP_PAGE3_AF7
#define GPIO_PIN_RMP_AF8  GPIO_PIN_RMP_PAGE3_AF8
#define GPIO_PIN_RMP_AF9  GPIO_PIN_RMP_PAGE3_AF9
#define GPIO_PIN_RMP_AF10 GPIO_PIN_RMP_PAGE3_AF10
#define GPIO_PIN_RMP_AF11 GPIO_PIN_RMP_PAGE3_AF11
#define GPIO_PIN_RMP_AF12 GPIO_PIN_RMP_PAGE3_AF12
#define GPIO_PIN_RMP_AF13 GPIO_PIN_RMP_PAGE3_AF13
#define GPIO_PIN_RMP_AF14 GPIO_PIN_RMP_PAGE3_AF14

/**
 * @brief Gpio_LL_WriteOutputState_ASM, 带临界保护的GPIO输出函数.

 * @attention PinIndex, 不可传入变量, 只能传入枚举/宏定义等立即数
              使用时, 操作同一组GPIO引脚时, 不可与其他操作POR寄存器的接口混用, 否则会失去临界保护功能.

 * @param Module 指向GPIO寄存器映射的指针
 * @param PinIndex GPIO引脚编号, 取值范围为GPIO_PIN_INDEX_0到GPIO_PIN_INDEX_15
 * @param State true: 输出高, false: 输出低
*/
#define Gpio_LL_WriteOutputState_ASM(Module, PinIndex, State)                                                          \
    do                                                                                                                 \
    {                                                                                                                  \
        if ((State))                                                                                                   \
        {                                                                                                              \
            KF_SET_BIT((Module)->POR.reg, (PinIndex));                                                                 \
        }                                                                                                              \
        else                                                                                                           \
        {                                                                                                              \
            KF_CLR_BIT((Module)->POR.reg, (PinIndex));                                                                 \
        }                                                                                                              \
    } while (0)

/******************************************************************************
 *                      Export Variables
 ******************************************************************************/

/******************************************************************************
 *                      Export Functions
 ******************************************************************************/

/**
 * @brief 获取GPIO端口指定引脚的输入数据
 *
 * @param Module 指向GPIO内存结构的指针,取值为GPIOA_PTR~GPIOH_PTR
 * @param PinIndex 端口引脚编号
 * @retval bool:
 *         true
 *         false
 */
KF_INLINE bool Gpio_LL_ReadInputState(const Gpio_RegisterMap_t *const Module, Gpio_PinIndex_t PinIndex)
{
    /* Extra parentheses recommended */
    KF_GPIO_ASSERT(CHECK_GPIO_ALL_PERIPH_ADDR(Module));
    KF_GPIO_ASSERT(CHECK_GPIO_PIN_INDEX(PinIndex));
    const uint32_t pinIdx = (uint32_t)PinIndex;
    return (REG_BITS_READ(Module->PIR.reg, ((uint32_t)GPIO_PIN_1BIT_MASK << pinIdx), pinIdx) != 0U);
}

/**
 * @brief 获取GPIO端口指定引脚的输出数据
 *
 * @param Module 指向GPIO内存结构的指针,取值为GPIOA_PTR~GPIOH_PTR
 * @param PinIndex 端口引脚编号
 * @retval bool:
 *         true
 *         false
 */
KF_INLINE bool Gpio_LL_ReadOutputState(const Gpio_RegisterMap_t *const Module, Gpio_PinIndex_t PinIndex)
{
    /* Extra parentheses recommended */
    KF_GPIO_ASSERT(CHECK_GPIO_ALL_PERIPH_ADDR(Module));
    KF_GPIO_ASSERT(CHECK_GPIO_PIN_INDEX(PinIndex));
    const uint32_t pinIdx = (uint32_t)PinIndex;
    return (REG_BITS_READ(Module->POR.reg, ((uint32_t)GPIO_PIN_1BIT_MASK << pinIdx), pinIdx) != 0U);
}

/**
 * @brief 配置GPIO端口指定引脚的输出数据
 *
 * @param Module 指向GPIO内存结构的指针,取值为 GPIOA_PTR~GPIOH_PTR
 * @param PinIndex 端口引脚编号,取值为 GPIO_PIN_INDEX_0~GPIO_PIN_INDEX_15
 * @param State 设置状态,取值为 false true
 * @retval 无
 */
KF_INLINE void Gpio_LL_WriteOutputState(Gpio_RegisterMap_t *const Module, Gpio_PinIndex_t PinIndex, bool State)
{
    /* Extra parentheses recommended */
    KF_GPIO_ASSERT(CHECK_GPIO_ALL_PERIPH_ADDR(Module));
    KF_GPIO_ASSERT(CHECK_GPIO_PIN_INDEX(PinIndex));

    const uint32_t pinIdx = (uint32_t)PinIndex;

    REG_BITS_WRITE(Module->POR.reg, ((uint32_t)GPIO_PIN_1BIT_MASK << pinIdx), ((State ? 1UL : 0UL) << pinIdx));
}

/**
 * @brief 配置GPIO端口指定引脚的输出数据取反
 *
 * @param Module 指向GPIO内存结构的指针,取值为 GPIOA_PTR~GPIOH_PTR
 * @param PinIndex 端口引脚编号,取值为 GPIO_PIN_INDEX_0~GPIO_PIN_INDEX_15
 * @retval 无
 */
KF_INLINE void Gpio_LL_ToggleOutputState(Gpio_RegisterMap_t *const Module, Gpio_PinIndex_t PinIndex)
{
    uint32_t PinMask;
    /* Extra parentheses recommended */
    KF_GPIO_ASSERT(CHECK_GPIO_ALL_PERIPH_ADDR(Module));
    KF_GPIO_ASSERT(CHECK_GPIO_PIN_INDEX(PinIndex));

    PinMask = (0x01UL << (uint32_t)PinIndex);

    Module->POR.reg ^= PinMask;
}

/**
 * @brief 获取GPIO端口指定引脚的上拉使能状态
 *
 * @param Module 指向GPIO内存结构的指针,取值为GPIOA_PTR~GPIOH_PTR
 * @param PinIndex 端口引脚编号
 * @retval bool:
 *         true
 *         false
 */
KF_INLINE bool Gpio_LL_ReadPullUpState(const Gpio_RegisterMap_t *const Module, Gpio_PinIndex_t PinIndex)
{
    /* Extra parentheses recommended */
    KF_GPIO_ASSERT(CHECK_GPIO_ALL_PERIPH_ADDR(Module));
    KF_GPIO_ASSERT(CHECK_GPIO_PIN_INDEX(PinIndex));

    const uint32_t pinIdx = (uint32_t)PinIndex;
    return (REG_BITS_READ(Module->PUR.reg, ((uint32_t)GPIO_PIN_1BIT_MASK << pinIdx), pinIdx) != 0U);
}

/**
 * @brief 配置GPIO端口指定引脚上拉使能设置
 *
 * @param Module 指向GPIO内存结构的指针,取值为 GPIOA_PTR~GPIOH_PTR
 * @param PinIndex 端口引脚编号,取值为 GPIO_PIN_INDEX_0~GPIO_PIN_INDEX_15
 * @param State 设置状态,取值为 false true
 * @retval 无
 */
KF_INLINE void Gpio_LL_WritePullUpState(Gpio_RegisterMap_t *const Module, Gpio_PinIndex_t PinIndex, bool State)
{
    /* Extra parentheses recommended */
    KF_GPIO_ASSERT(CHECK_GPIO_ALL_PERIPH_ADDR(Module));
    KF_GPIO_ASSERT(CHECK_GPIO_PIN_INDEX(PinIndex));

    const uint32_t pinIdx = (uint32_t)PinIndex;
    /* contains more than one access to volatile */
    REG_BITS_WRITE(Module->PUR.reg, ((uint32_t)GPIO_PIN_1BIT_MASK << pinIdx), ((State ? 1UL : 0UL) << pinIdx));
}

/**
 * @brief 获取GPIO端口指定引脚的下拉使能状态
 *
 * @param Module 指向GPIO内存结构的指针,取值为GPIOA_PTR~GPIOH_PTR
 * @param PinIndex 端口引脚编号
 * @retval bool:
 *         true
 *         false
 */
KF_INLINE bool Gpio_LL_ReadPullDownState(const Gpio_RegisterMap_t *const Module, Gpio_PinIndex_t PinIndex)
{
    KF_GPIO_ASSERT(CHECK_GPIO_ALL_PERIPH_ADDR(Module));
    KF_GPIO_ASSERT(CHECK_GPIO_PIN_INDEX(PinIndex));

    const uint32_t pinIdx = (uint32_t)PinIndex;
    return (REG_BITS_READ(Module->PDR.reg, ((uint32_t)GPIO_PIN_1BIT_MASK << pinIdx), pinIdx) != 0U);
}

/**
 * @brief 配置GPIO端口指定引脚下拉使能设置
 *
 * @param Module 指向GPIO内存结构的指针,取值为 GPIOA_PTR~GPIOH_PTR
 * @param PinIndex 端口引脚编号,取值为 GPIO_PIN_INDEX_0~GPIO_PIN_INDEX_15
 * @param State 设置状态,取值为 false true
 * @retval 无
 */
KF_INLINE void Gpio_LL_WritePullDownState(Gpio_RegisterMap_t *const Module, Gpio_PinIndex_t PinIndex, bool State)
{
    /* Extra parentheses recommended */
    KF_GPIO_ASSERT(CHECK_GPIO_ALL_PERIPH_ADDR(Module));
    KF_GPIO_ASSERT(CHECK_GPIO_PIN_INDEX(PinIndex));

    const uint32_t pinIdx = (uint32_t)PinIndex;
    /* contains more than one access to volatile
     */
    REG_BITS_WRITE(Module->PDR.reg, ((uint32_t)GPIO_PIN_1BIT_MASK << pinIdx), ((State ? 1UL : 0UL) << pinIdx));
}

/**
 * @brief 配置GPIO端口上下拉
 *
 * @param Module 指向GPIO内存结构的指针,取值为 GPIOA_PTR~GPIOH_PTR
 * @param PinIndex 端口引脚编号,取值为 GPIO_PIN_INDEX_0~GPIO_PIN_INDEX_15
 * @param PullMode 设置状态,取值为 Gpio_Pull_t
 * @retval None
 */
KF_INLINE void Gpio_LL_WritePullState(Gpio_RegisterMap_t *const Module, Gpio_PinIndex_t PinIndex, Gpio_Pull_t PullMode)
{
    /* Extra parentheses recommended */
    KF_GPIO_ASSERT(CHECK_GPIO_ALL_PERIPH_ADDR(Module));
    KF_GPIO_ASSERT(CHECK_GPIO_PIN_INDEX(PinIndex));
    KF_GPIO_ASSERT(CHECK_GPIO_PULL(PullMode));

    /* contains more than one access to volatile */
    if (PullMode == GPIO_PULL_NONE)
    {
        Gpio_LL_WritePullUpState(Module, PinIndex, false);
        Gpio_LL_WritePullDownState(Module, PinIndex, false);
    }
    else if (PullMode == GPIO_PULL_UP)
    {
        Gpio_LL_WritePullUpState(Module, PinIndex, true);
        Gpio_LL_WritePullDownState(Module, PinIndex, false);
    }
    else if (PullMode == GPIO_PULL_DOWN)
    {
        Gpio_LL_WritePullUpState(Module, PinIndex, false);
        Gpio_LL_WritePullDownState(Module, PinIndex, true);
    }
    else
    {
        Gpio_LL_WritePullUpState(Module, PinIndex, true);
        Gpio_LL_WritePullDownState(Module, PinIndex, true);
    }
}

/**
 * @brief 获取GPIO端口指定引脚的开漏输出控制寄存器状态
 *
 * @param Module 指向GPIO内存结构的指针,取值为GPIOA_PTR~GPIOH_PTR
 * @param PinIndex 端口引脚编号
 * @retval bool:
 *         true
 *         false
 */
KF_INLINE bool Gpio_LL_ReadOpenDrainState(const Gpio_RegisterMap_t *const Module, Gpio_PinIndex_t PinIndex)
{
    /* Extra parentheses recommended */
    KF_GPIO_ASSERT(CHECK_GPIO_ALL_PERIPH_ADDR(Module));
    KF_GPIO_ASSERT(CHECK_GPIO_PIN_INDEX(PinIndex));
    const uint32_t pinIdx = (uint32_t)PinIndex;

    return (REG_BITS_READ(Module->PODR.reg, ((uint32_t)GPIO_PIN_1BIT_MASK << pinIdx), pinIdx) != 0U);
}

/**
 * @brief 配置GPIO端口指定引脚开漏输出控制寄存器设置
 *
 * @param Module 指向GPIO内存结构的指针,取值为 GPIOA_PTR~GPIOH_PTR
 * @param PinIndex 端口引脚编号,取值为 GPIO_PIN_INDEX_0~GPIO_PIN_INDEX_15
 * @param State 设置状态,取值为 false true
 * @retval 无
 */
KF_INLINE void Gpio_LL_WriteOpenDrainState(Gpio_RegisterMap_t *const Module, Gpio_PinIndex_t PinIndex, bool State)
{
    /* Extra parentheses recommended */
    KF_GPIO_ASSERT(CHECK_GPIO_ALL_PERIPH_ADDR(Module));
    KF_GPIO_ASSERT(CHECK_GPIO_PIN_INDEX(PinIndex));

    const uint32_t pinIdx = (uint32_t)PinIndex;
    /* contains more than one access to volatile
     */
    REG_BITS_WRITE(Module->PODR.reg, ((uint32_t)GPIO_PIN_1BIT_MASK << pinIdx), ((State ? 1UL : 0UL) << pinIdx));
}

/**
 * @brief 获取GPIO端口指定引脚的输出模式控制寄存器状态
 *
 * @param Module 指向GPIO内存结构的指针,取值为GPIOA_PTR~GPIOH_PTR
 * @param PinIndex 端口引脚编号
 * @retval bool:
 *         true
 *         false
 */
KF_INLINE Gpio_PinMode_t
Gpio_LL_ReadModeDirectionState(const Gpio_RegisterMap_t *const Module, Gpio_PinIndex_t PinIndex)
{
    /* Extra parentheses recommended */
    KF_GPIO_ASSERT(CHECK_GPIO_ALL_PERIPH_ADDR(Module));
    KF_GPIO_ASSERT(CHECK_GPIO_PIN_INDEX(PinIndex));
    const uint32_t pinIdx = (uint32_t)PinIndex;
    uint32_t       tmpMode =
        REG_BITS_READ(Module->PMOD.reg, ((uint32_t)GPIO_PIN_2BIT_MASK << (pinIdx << 1U)), (pinIdx << 1U));
    return (Gpio_PinMode_t)tmpMode;
}

/**
 * @brief 配置GPIO端口指定引脚输出模式控制设置
 *
 * @param Module 指向GPIO内存结构的指针,取值为 GPIOA_PTR~GPIOH_PTR
 * @param PinIndex 端口引脚编号,取值为 GPIO_PIN_INDEX_0~GPIO_PIN_INDEX_15
 * @param PinMode 设置模式,取值为 GPIO_PIN_MODE_IN
 *                                GPIO_PIN_MODE_OUT
 *                                GPIO_PIN_MODE_REMAP
 *                                GPIO_PIN_MODE_AN
 * @retval 无
 */
KF_INLINE void
Gpio_LL_WriteModeDirectionState(Gpio_RegisterMap_t *const Module, Gpio_PinIndex_t PinIndex, Gpio_PinMode_t PinMode)
{
    KF_GPIO_ASSERT(CHECK_GPIO_ALL_PERIPH_ADDR(Module));
    KF_GPIO_ASSERT(CHECK_GPIO_PIN_INDEX(PinIndex));
    KF_GPIO_ASSERT(CHECK_GPIO_PIN_MODE(PinMode));

    const uint32_t pinIdx  = (uint32_t)PinIndex;
    const uint32_t pinMode = (uint32_t)PinMode;
    /* Arithmetic won't wraparound */
    REG_BITS_WRITE(
        Module->PMOD.reg, ((uint32_t)GPIO_PIN_2BIT_MASK << (pinIdx * 2U)), ((uint32_t)pinMode << (pinIdx * 2U)));
}

/**
 * @brief 获取GPIO端口指定引脚的速度控制寄存器状态
 *
 * @param Module 指向GPIO内存结构的指针,取值为GPIOA_PTR~GPIOH_PTR
 * @param PinIndex 端口引脚编号
 * @retval bool:
 *         true
 *         false
 */
KF_INLINE bool Gpio_LL_ReadSpeedCtrlState(const Gpio_RegisterMap_t *const Module, Gpio_PinIndex_t PinIndex)
{
    KF_GPIO_ASSERT(CHECK_GPIO_ALL_PERIPH_ADDR(Module));
    KF_GPIO_ASSERT(CHECK_GPIO_PIN_INDEX(PinIndex));

    const uint32_t pinIdx = (uint32_t)PinIndex;
    /* Arithmetic won't wraparound */
    return (REG_BITS_READ(Module->OMOD.reg, ((uint32_t)GPIO_PIN_2BIT_MASK << (pinIdx * 2U)), (pinIdx * 2U)) != 0U);
}

/**
 * @brief 配置GPIO端口指定引脚速度控制设置
 *
 * @param Module 指向GPIO内存结构的指针,取值为 GPIOA_PTR~GPIOH_PTR
 * @param PinIndex 端口引脚编号,取值为 GPIO_PIN_INDEX_0~GPIO_PIN_INDEX_15
 * @param Speed 设置模式,取值为 GPIO_PIN_SPEED_10M
 *                                 GPIO_PIN_SPEED_20M
 * @retval 无
 */
KF_INLINE void
Gpio_LL_WriteSpeedCtrlState(Gpio_RegisterMap_t *const Module, Gpio_PinIndex_t PinIndex, Gpio_PinSpeed_t Speed)
{
    KF_GPIO_ASSERT(CHECK_GPIO_ALL_PERIPH_ADDR(Module));
    KF_GPIO_ASSERT(CHECK_GPIO_PIN_INDEX(PinIndex));
    KF_GPIO_ASSERT(CHECK_GPIO_PIN_SPEED(Speed));

    const uint32_t pinIdx   = (uint32_t)PinIndex;
    const uint32_t pinSpeed = (uint32_t)Speed;
    /* contains more than one access to volatile */
    REG_BITS_WRITE(Module->OMOD.reg, ((uint32_t)GPIO_PIN_2BIT_MASK << (pinIdx * 2U)), (pinSpeed << (pinIdx * 2U)));
}

/**
 * @brief 获取GPIO端口指定引脚的配置锁定寄存器状态
 *
 * @param Module 指向GPIO内存结构的指针,取值为GPIOA_PTR~GPIOH_PTR
 * @param PinIndex 端口引脚编号
 * @retval bool:
 *         true
 *         false
 */
KF_INLINE bool Gpio_LL_ReadLockConfigState(const Gpio_RegisterMap_t *const Module, Gpio_PinIndex_t PinIndex)
{
    /* Extra parentheses recommended */
    KF_GPIO_ASSERT(CHECK_GPIO_ALL_PERIPH_ADDR(Module));
    KF_GPIO_ASSERT(CHECK_GPIO_PIN_INDEX(PinIndex));

    const uint32_t pinIdx = (uint32_t)PinIndex;
    return (REG_BITS_READ(Module->LOCK.reg, ((uint32_t)GPIO_PIN_1BIT_MASK << pinIdx), pinIdx) != 0U);
}

/**
 * @brief 配置GPIO端口指定引脚配置锁定寄存器设置
 *
 * @param Module 指向GPIO内存结构的指针,取值为 GPIOA_PTR~GPIOH_PTR
 * @param PinIndex 端口引脚编号,取值为 GPIO_PIN_INDEX_0~GPIO_PIN_INDEX_15
 * @param State 设置状态,取值为 false true
 * @retval 无
 */
KF_INLINE void Gpio_LL_WriteLockConfigState(Gpio_RegisterMap_t *const Module, Gpio_PinIndex_t PinIndex, bool State)
{
    /* Extra parentheses recommended */
    KF_GPIO_ASSERT(CHECK_GPIO_ALL_PERIPH_ADDR(Module));
    KF_GPIO_ASSERT(CHECK_GPIO_PIN_INDEX(PinIndex));

    const uint32_t pinIdx = (uint32_t)PinIndex;
    /* contains more than one access to volatile */
    REG_BITS_WRITE(Module->LOCK.reg, ((uint32_t)GPIO_PIN_1BIT_MASK << pinIdx), ((State ? 1UL : 0UL) << pinIdx));
}

/**
 * @brief 配置GPIO端口指定引脚重映射控制寄存器
 *
 * @param Module 指向GPIO内存结构的指针,取值为 GPIOA_PTR~GPIOH_PTR
 * @param PinIndex 端口引脚编号,取值为 GPIO_PIN_INDEX_0~GPIO_PIN_INDEX_15
 * @param PinRemapAf 设置状态,取值为 GPIO_PIN_REMAP_AF0~GPIO_PIN_REMAP_AF15
 * @retval 无
 */
/* contains more than one access to volatile */
KF_INLINE void
Gpio_LL_WriteRemapCtrlState(Gpio_RegisterMap_t *const Module, Gpio_PinIndex_t PinIndex, Gpio_PinRemap_t PinRemapAf)
{
    /* Extra parentheses recommended */
    KF_GPIO_ASSERT(CHECK_GPIO_ALL_PERIPH_ADDR(Module));
    KF_GPIO_ASSERT(CHECK_GPIO_PIN_INDEX(PinIndex));

    const uint32_t pinIdx  = (uint32_t)PinIndex;
    const uint32_t PageNum = ((uint32_t)PinRemapAf & 0x300U) >> 8U;
    switch (PageNum)
    {
    case 0x00U:
        KF_GPIO_ASSERT(CHECK_GPIO_PAGE1_REMAP(PinRemapAf));
        break;
    case 0x01U:
        KF_GPIO_ASSERT(CHECK_GPIO_PAGE2_REMAP(PinRemapAf));
        break;
    case 0x02U:
        KF_GPIO_ASSERT(CHECK_GPIO_PAGE3_REMAP(PinRemapAf));
        break;
    default:
        /* Avoid QAC warning, it will be optimized by compiler */
        KF_GPIO_ASSERT(false);
        break;
    }

    if (PinIndex < GPIO_PIN_INDEX_8)
    {
        /* Arithmetic won't wraparound */
        REG_BITS_WRITE(Module->RMPL.reg, ((uint32_t)GPIO_PIN_4BIT_MASK << (pinIdx * 4U)),
                       (((uint32_t)PinRemapAf & 0xFU) << (pinIdx * 4U)));
    }
    else
    {

        REG_BITS_WRITE(Module->RMPH.reg, ((uint32_t)GPIO_PIN_4BIT_MASK << ((pinIdx - (uint32_t)GPIO_PIN_INDEX_8) * 4U)),
                       (((uint32_t)PinRemapAf & 0xFU) << ((pinIdx - (uint32_t)GPIO_PIN_INDEX_8) * 4U)));
    }
}

/**
 * @brief 配置GPIO端口指定引脚重映射端口模块选择
 *
 * @param Module 指向GPIO内存结构的指针,取值为 GPIOA_PTR~GPIOH_PTR
 * @param PinIndex 端口引脚编号,取值为 GPIO_PIN_INDEX_0~GPIO_PIN_INDEX_15
 * @param PinRemapAf 设置状态,取值为 GPIO_PIN_REMAP_AF0~GPIO_PIN_REMAP_AF15
 * @retval 无
 */
KF_INLINE void
Gpio_LL_WriteRemapMsbState(Gpio_RegisterMap_t *const Module, Gpio_PinIndex_t PinIndex, Gpio_PinRemap_t PinRemapAf)
{
    /* Extra parentheses recommended */
    KF_GPIO_ASSERT(CHECK_GPIO_ALL_PERIPH_ADDR(Module));
    KF_GPIO_ASSERT(CHECK_GPIO_PIN_INDEX(PinIndex));

    const uint32_t PageNum = ((uint32_t)PinRemapAf & 0x300U) >> 8U;
    bool           State   = false;
    bool           State1  = true;
    uint32_t       pinIdx  = 0U;

    switch (PageNum)
    {
    case 0x00U:
        KF_GPIO_ASSERT(CHECK_GPIO_PAGE1_REMAP(PinRemapAf));
        State  = false;
        State1 = false;
        break;
    case 0x01U:
        KF_GPIO_ASSERT(CHECK_GPIO_PAGE2_REMAP(PinRemapAf));
        State  = true;
        State1 = false;
        break;
    case 0x02U:
        KF_GPIO_ASSERT(CHECK_GPIO_PAGE3_REMAP(PinRemapAf));
        State  = false;
        State1 = true;
        break;
    default:
        /* Avoid QAC warning, it will be optimized by compiler */
        (void)0;
        break;
    }
    /* contains more than one access to volatile */
    pinIdx = (uint32_t)PinIndex + 16U;
    REG_BITS_WRITE(Module->RMP_MSB.reg, ((uint32_t)GPIO_PIN_1BIT_MASK << pinIdx), ((State1 ? 1UL : 0UL) << pinIdx));
    pinIdx = (uint32_t)PinIndex;
    REG_BITS_WRITE(Module->RMP_MSB.reg, ((uint32_t)GPIO_PIN_1BIT_MASK << pinIdx), ((State ? 1UL : 0UL) << pinIdx));
}

/**
 * @brief 掩码形式设置GPIO端口输出数据
 *
 * @param Module 指向GPIO内存结构的指针,取值为GPIOA_SFR~GPIOH_SFR
 * @param PinMask 端口引脚掩码,取值为GPIO_PIN_MASK_0~GPIO_PIN_MASK_15中的
 *                一个或多个组合
 * @param State 设置状态,取值为 false true
 * @retval 无
 */
KF_INLINE void Gpio_LL_WriteMaskOutputState(Gpio_RegisterMap_t *const Module, uint32_t PinMask, bool State)
{
    KF_GPIO_ASSERT(CHECK_GPIO_ALL_PERIPH_ADDR(Module));
    KF_GPIO_ASSERT(CHECK_GPIO_PIN_MASK(PinMask));

    if (State != false)
    {
        Module->POR.reg |= (uint32_t)PinMask;
    }
    else
    {
        Module->POR.reg &= (~(uint32_t)PinMask);
    }
}

/**
 * @brief 掩码形式设置GPIO端口上拉使能
 *
 * @param Module 指向GPIO内存结构的指针,取值为GPIOA_SFR~GPIOH_SFR
 * @param PinMask 端口引脚掩码,取值为GPIO_PIN_MASK_0~GPIO_PIN_MASK_15中的
 *                一个或多个组合
 * @param State 设置状态,取值为 false true
 * @retval 无
 */
KF_INLINE void Gpio_LL_WriteMaskPullUpState(Gpio_RegisterMap_t *const Module, uint32_t PinMask, bool State)
{
    KF_GPIO_ASSERT(CHECK_GPIO_ALL_PERIPH_ADDR(Module));
    KF_GPIO_ASSERT(CHECK_GPIO_PIN_MASK(PinMask));

    if (State != false)
    {
        Module->PUR.reg |= (uint32_t)PinMask;
    }
    else
    {
        Module->PUR.reg &= (~(uint32_t)PinMask);
    }
}

/**
 * @brief 掩码形式设置GPIO端口下拉使能
 *
 * @param Module 指向GPIO内存结构的指针,取值为GPIOA_SFR~GPIOH_SFR
 * @param PinMask 端口引脚掩码,取值为GPIO_PIN_MASK_0~GPIO_PIN_MASK_15中的
 *                一个或多个组合
 * @param State 设置状态,取值为 false true
 * @retval 无
 */
KF_INLINE void Gpio_LL_WriteMaskPullDownState(Gpio_RegisterMap_t *const Module, uint32_t PinMask, bool State)
{
    KF_GPIO_ASSERT(CHECK_GPIO_ALL_PERIPH_ADDR(Module));
    KF_GPIO_ASSERT(CHECK_GPIO_PIN_MASK(PinMask));

    if (State != false)
    {
        Module->PDR.reg |= (uint32_t)PinMask;
    }
    else
    {
        Module->PDR.reg &= (~(uint32_t)PinMask);
    }
}

/**
 * @brief 掩码形式设置GPIO端口开漏输出
 *
 * @param Module 指向GPIO内存结构的指针,取值为GPIOA_SFR~GPIOH_SFR
 * @param PinMask 端口引脚掩码,取值为GPIO_PIN_MASK_0~GPIO_PIN_MASK_15中的
 *                一个或多个组合
 * @param State 设置状态,取值为 false true
 * @retval 无
 */
KF_INLINE void Gpio_LL_WriteMaskOpenDrainState(Gpio_RegisterMap_t *const Module, uint32_t PinMask, bool State)
{
    KF_GPIO_ASSERT(CHECK_GPIO_ALL_PERIPH_ADDR(Module));
    KF_GPIO_ASSERT(CHECK_GPIO_PIN_MASK(PinMask));

    if (State != false)
    {
        Module->PODR.reg |= (uint32_t)PinMask;
    }
    else
    {
        Module->PODR.reg &= (~(uint32_t)PinMask);
    }
}

/**
 * @brief 掩码形式设置GPIO端口锁定寄存器
 *
 * @param Module 指向GPIO内存结构的指针,取值为GPIOA_SFR~GPIOH_SFR
 * @param PinMask 端口引脚掩码,取值为GPIO_PIN_MASK_0~GPIO_PIN_MASK_15中的
 *                一个或多个组合
 * @param State 设置状态,取值为 false true
 * @retval 无
 */
KF_INLINE void Gpio_LL_WriteMaskLockConfigState(Gpio_RegisterMap_t *const Module, uint32_t PinMask, bool State)
{
    KF_GPIO_ASSERT(CHECK_GPIO_ALL_PERIPH_ADDR(Module));
    KF_GPIO_ASSERT(CHECK_GPIO_PIN_MASK(PinMask));

    if (State != false)
    {
        Module->LOCK.reg |= (uint32_t)PinMask;
    }
    else
    {
        Module->LOCK.reg &= (~(uint32_t)PinMask);
    }
}

/**
 * @brief 使能自检功能
 *
 * @param Module 指向GPIO内存结构的指针,取值为GPIOA_SFR~GPIOH_SFR
 * @retval 无
 */
KF_INLINE void Gpio_LL_SetSelfDetectionEnabled(Gpio_RegisterMap_t *const Module, bool Enable)
{
    KF_GPIO_ASSERT(CHECK_GPIO_ALL_PERIPH_ADDR(Module));

    Module->SDE.bits.SDEN = Enable ? 1U : 0U;
}

/**
 * @brief 获取GPIO自检标记位
 *
 * @param Module 指向GPIO内存结构的指针,取值为GPIOA_SFR~GPIOH_SFR
 * @retval bool:
 *         true 自检成功
 *         false 自检失败
 */
KF_INLINE bool Gpio_LL_GetSelfDetectionFlag(const Gpio_RegisterMap_t *const Module)
{
    KF_GPIO_ASSERT(CHECK_GPIO_ALL_PERIPH_ADDR(Module));

    return (Module->SDE.bits.SDEF != 0U);
}

/**
 * @brief 配置GPIO端口自检LINK功能
 * @param module 指向GPIO内存结构的指针,取值为GPIOB_SFR~GPIOK_SFR
 * @param State 使能状态,取值范围为TRUE 或 FALSE
 * @retval 无
 */
KF_INLINE void Gpio_LL_SetLinkEnabled(Gpio_RegisterMap_t *module, bool State)
{
    KF_GPIO_ASSERT(CHECK_GPIO_ALL_PERIPH_ADDR(module));

    module->SDCTL.bits.LINKEN = State ? 1U : 0U;
}

/**
 * @brief 配置软件采样触发使能
 * @param module: 指向GPIO内存结构的指针,取值为GPIOA_PTR~GPIOH_PTR
 * @param State: 使能状态,取值范围为TRUE 或 FALSE
 * @retval 无
 */
KF_INLINE void Gpio_LL_SetSoftwareSampleEnabled(Gpio_RegisterMap_t *module, bool State)
{
    KF_GPIO_ASSERT(CHECK_GPIO_ALL_PERIPH_ADDR(module));

    module->SDCTL.bits.SWSAMCLK = State ? 1U : 0U;
}

/**
 * @brief 获取GPIO断口自检结果
 * @param module: 指向GPIO内存结构的指针,取值为GPIOA_PTR~GPIOH_PTR
 * @retval true:
 *         false
 */
KF_INLINE bool Gpio_LL_GetPortSelfDetectionFlag(const Gpio_RegisterMap_t *module)
{
    KF_GPIO_ASSERT(CHECK_GPIO_ALL_PERIPH_ADDR(module));

    return (module->SDCTL.bits.PSDEF != 0U);
}

/*============================== GPIO EXTI INTERRUPT ===================================*/
/**
 * @brief 设置GPIO中断电平模式
 *
 * @param Module 指向GPIO中断内存结构的指针, GPIOEXTIA_PTR等
 * @param Index GPIO引脚序号, 可见 Gpio_PinIndex_t
 * @param Status 掩码状态
 *          true -- 边沿中断模式
 *          false -- 电平中断模式
 * @retval void
 */

KF_INLINE void GpioExti_LL_SetMode(Exti_RegisterMap_t *const Module, Gpio_PinIndex_t Index, bool Status)
{
    KF_GPIO_ASSERT(CHECK_GPIO_EXTI_ALL_PERIPH_ADDR(Module));
    KF_GPIO_ASSERT(CHECK_GPIO_PIN_INDEX(Index));

    REG_BITS_WRITE(Module->INTMS.reg, (1UL << (uint32_t)Index), ((Status ? 1UL : 0UL) << (uint32_t)Index));
}

/**
 * @brief 设置GPIO上升沿中断使能状态
 *
 * @param Module 指向GPIO中断内存结构的指针, GPIOEXTIA_PTR等
 * @param Index GPIO引脚序号, 可见 Gpio_PinIndex_t
 * @param Status 上升沿中断使能状态
 *          true -- 使能对应端口的上升沿中断
 *          false -- 禁止对应端口的上升沿中断
 * @retval void
 */
KF_INLINE void GpioExti_LL_SetRaiseEdgeIntrEnabled(Exti_RegisterMap_t *const Module, Gpio_PinIndex_t Index, bool Status)
{
    KF_GPIO_ASSERT(CHECK_GPIO_EXTI_ALL_PERIPH_ADDR(Module));
    KF_GPIO_ASSERT(CHECK_GPIO_PIN_INDEX(Index));

    REG_BITS_WRITE(Module->INTRISE.reg, (1UL << (uint32_t)Index), ((Status ? 1UL : 0UL) << (uint32_t)Index));
}

/**
 * @brief 设置GPIO下降沿中断使能状态
 *
 * @param Module 指向GPIO中断内存结构的指针, GPIOEXTIA_PTR等
 * @param Index GPIO引脚序号, 可见 Gpio_PinIndex_t
 * @param Status 下降沿中断使能状态
 *          true -- 使能对应端口的上升沿中断
 *          false -- 禁止对应端口的上升沿中断
 * @retval void
 */
KF_INLINE void GpioExti_LL_SetFallEdgeIntrEnabled(Exti_RegisterMap_t *const Module, Gpio_PinIndex_t Index, bool Status)
{
    KF_GPIO_ASSERT(CHECK_GPIO_EXTI_ALL_PERIPH_ADDR(Module));
    KF_GPIO_ASSERT(CHECK_GPIO_PIN_INDEX(Index));

    REG_BITS_WRITE(Module->INTFALL.reg, (1UL << (uint32_t)Index), ((Status ? 1UL : 0UL) << (uint32_t)Index));
}

/**
 * @brief 端口Px端口中断源选择
 *
 * @param Module 指向GPIO中断内存结构的指针, GPIOEXTIA_PTR等
 * @param Index GPIO引脚序号, 可见 Gpio_PinIndex_t
 * @param Status 下降沿中断使能状态
 *          true -- 使能对应端口的中断源
 *          false -- 禁止对应端口的中断源
 * @retval void
 */
KF_INLINE void GpioExti_LL_SetIntrEnabled(Exti_RegisterMap_t *const Module, Gpio_PinIndex_t Index, bool Status)
{
    KF_GPIO_ASSERT(CHECK_GPIO_EXTI_ALL_PERIPH_ADDR(Module));
    KF_GPIO_ASSERT(CHECK_GPIO_PIN_INDEX(Index));

    REG_BITS_WRITE(Module->INTIE.reg, (1UL << (uint32_t)Index), ((Status ? 1UL : 0UL) << (uint32_t)Index));
}

/**
 * @brief 获取端口Px端口中断标志
 *
 * @param Module 指向GPIO中断内存结构的指针, GPIOEXTIA_PTR等
 * @param Index GPIO引脚序号, 可见 Gpio_PinIndex_t
 * @retval bool 中断标志
 *          true -- 没有产生对应端口的中断标志
 *          false -- 禁止对应端口的中断源
 */
KF_INLINE bool GpioExti_LL_GetIntrFlag(const Exti_RegisterMap_t *const Module, Gpio_PinIndex_t Index)
{
    KF_GPIO_ASSERT(CHECK_GPIO_EXTI_ALL_PERIPH_ADDR(Module));
    KF_GPIO_ASSERT(CHECK_GPIO_PIN_INDEX(Index));

    return (REG_BITS_READ(Module->INTIF.reg, (1UL << (uint32_t)Index), (uint32_t)Index) != 0U);
}

/**
 * @brief 清除端口Px端口中断标志
 *
 * @param Module 指向GPIO中断内存结构的指针, GPIOEXTIA_PTR等
 * @param Index GPIO引脚序号, 可见 Gpio_PinIndex_t
 * @retval void
 */
KF_INLINE void GpioExti_LL_ClearIntrFlag(Exti_RegisterMap_t *const Module, Gpio_PinIndex_t Index)
{
    KF_GPIO_ASSERT(CHECK_GPIO_EXTI_ALL_PERIPH_ADDR(Module));
    KF_GPIO_ASSERT(CHECK_GPIO_PIN_INDEX(Index));

    REG_BIT_CLR(Module->INTIF.reg, (1UL << (uint32_t)Index));
}

/**
 * @brief 获取GPIO端口输入数据
 *
 * @param Module 指向GPIO内存结构的指针,取值为GPIOA_PTR~GPIOH_PTR
 * @retval 读取的值
 */
KF_INLINE uint16_t Port_LL_ReadInputState(const Gpio_RegisterMap_t *const Module)
{
    /* Extra parentheses recommended */
    KF_GPIO_ASSERT(CHECK_GPIO_EXTI_ALL_PERIPH_ADDR(Module));

    return (uint16_t)REG_READ(Module->PIR.reg);
}

/**
 * @brief 设置输出状态寄存器值
 *
 * @param Module 指向GPIO内存结构的指针,取值为GPIOA_PTR~GPIOH_PTR
 * @param Value 端口px输出状态 \n
 *                  0~0xFFFF
 * @retval none
 */
KF_INLINE void Gpio_LL_SetOutputStatus(Gpio_RegisterMap_t *const Module, uint32_t Value)
{
    KF_GPIO_ASSERT(CHECK_GPIO_ALL_PERIPH_ADDR(Module));
    KF_GPIO_ASSERT(Value <= 0xFFFFU);

    Module->POR.reg = Value;
}

/**
 * @brief 获取端口Px端口中断发生状态
 *
 * @param Module 指向GPIO中断内存结构的指针, GPIOEXTIA_PTR等
 * @param Index GPIO引脚序号, 可见 Gpio_PinIndex_t
 * @retval bool 中断发生状态
 *         true    发生了中断，且已使能
 *         false    未发生中断，或未使能
 */
KF_INLINE bool GpioExti_LL_GetIntrState(const Exti_RegisterMap_t *const Module, Gpio_PinIndex_t Index)
{
    KF_GPIO_ASSERT(CHECK_GPIO_EXTI_ALL_PERIPH_ADDR(Module));
    KF_GPIO_ASSERT(CHECK_GPIO_PIN_INDEX(Index));

    bool flag  = (0U != REG_BITS_READ(Module->INTIF.reg, (1UL << (uint32_t)Index), (uint32_t)Index)) ? true : false;
    bool state = (0U != REG_BITS_READ(Module->INTIE.reg, (1UL << (uint32_t)Index), (uint32_t)Index)) ? true : false;

    return flag && state;
}

#ifdef __cplusplus
}
#endif /*End of __cplusplus*/
#endif /*End of KF32A158SF_DRV_GPIO_H*/
/* EOF */
