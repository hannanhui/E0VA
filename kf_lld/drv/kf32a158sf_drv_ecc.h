/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name        : kf32a158sf_drv_ecc.h
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
#ifndef KF32A158SF_DRV_ECC_H
#define KF32A158SF_DRV_ECC_H

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

/******************************************************************************
 *                      Include Files
 ******************************************************************************/
#include <stdint.h>
#include <stdbool.h>
#include "kf_types.h"
#include "dev_assert.h"
#include "kf32a158sf_reg_ecc.h"

#ifdef KF_DRV_ECC_ASSERT
#include "dev_assert.h"
#define KF_ECC_ASSERT(x) KF_DEV_ASSERT(x)
#else
#define KF_ECC_ASSERT(x) ((void)0U)
#endif

/******************************************************************************
 *                      Macro or Inline
 ******************************************************************************/

/******************************************************************************
 *                      Type definitions
 ******************************************************************************/

typedef enum
{
    ECC_EBR_OFFSET_0,
    ECC_EBR_OFFSET_1,
    ECC_EBR_OFFSET_2,
} Ecc_ErrorInjectionOffset_t;
#define CHECK_ECC_ERRORINJECTIONOFFSET(x)                                                                              \
    (((x) == ECC_EBR_OFFSET_0) || ((x) == ECC_EBR_OFFSET_1) || ((x) == ECC_EBR_OFFSET_2))

/*获取中断序号*/
typedef enum
{
    ECC_INTR_GET_MEMERRIF     = 0U, /*!< ECC错误中断标志 */
    ECC_INTR_GET_MEM1BITERRIF = 1U, /*!< ECC 1bit错误中断标志 */
    ECC_INTR_GET_MEM2BITERRIF = 2U, /*!< ECC 2bit错误中断标志 */
} Ecc_IntrGetIndex_t;
#define CHECK_ECC_INTRGETINDEX(x)                                                                                      \
    (((x) == ECC_INTR_GET_MEMERRIF) || ((x) == ECC_INTR_GET_MEM1BITERRIF) || ((x) == ECC_INTR_GET_MEM2BITERRIF))

/**设置中断序号*/
typedef enum
{
    ECC_INTR_SET_MEMERRIE     = 8U,  /*!< ECC 错误中断使能位 */
    ECC_INTR_SET_MEM1BITERRIE = 9U,  /*!< ECC 1bit 错误中断使能位 */
    ECC_INTR_SET_MEM2BITERRIE = 10U, /*!< ECC 2bit 错误中断使能位  */
} Ecc_IntrSetIndex_t;
#define CHECK_ECC_INTRSETINDEX(x) (((x) >= ECC_INTR_SET_MEMERRIE) && ((x) <= ECC_INTR_SET_MEM2BITERRIE))

/**清除中断序号*/
typedef enum
{
    ECC_INTR_CLEAR_MEMERRIC     = 12U, /*!< ECC 错误中断清零 */
    ECC_INTR_CLEAR_MEM1BITERRIC = 13U, /*!< ECC 1bit 错误中断清零 */
    ECC_INTR_CLEAR_MEM2BITERRIC = 14U, /*!< ECC 2bit 错误中断清零 */
} Ecc_IntrClearIndex_t;
#define CHECK_ECC_INTRCLEARINDEX(x)                                                                                    \
    (((x) == ECC_INTR_CLEAR_MEMERRIC) || ((x) == ECC_INTR_CLEAR_MEM1BITERRIC) || ((x) == ECC_INTR_CLEAR_MEM2BITERRIC))

/******************************************************************************
 *                      Export Variables
 ******************************************************************************/

/******************************************************************************
 *                      Export Functions
 ******************************************************************************/

/**
 * @brief 设置ECC错误注入使能位
 * @param Module: Ecc寄存器结构体指针
 * @param State
 *          true 使能ECC错误注入
 *          false 禁止ECC错误注入
 * @retval 无
 */
KF_INLINE void Ecc_LL_SetEccTestEnabled(Ecc_RegisterMap_t *const Module, bool State)
{
    KF_ECC_ASSERT(CHECK_ECC_ALL_PERIPH_ADDR(Module));
    Module->CTL.bits.ECCTESTEN = State ? 1U : 0U;
}

/**
 * @brief 设置Ecc中断使能
 * @param Module 指向ECC寄存器结构的指针
 * @param IntIndex 设置中断序号, Ecc_IntrSetIndex_t
 * @param State 使能状态
 * @retval None
 */
KF_INLINE void Ecc_LL_SetIntrEnabled(Ecc_RegisterMap_t *const Module, Ecc_IntrSetIndex_t IntIndex, bool State)
{
    KF_ECC_ASSERT(CHECK_ECC_ALL_PERIPH_ADDR(Module));
    KF_ECC_ASSERT(CHECK_ECC_INTRSETINDEX(IntIndex));

    /* PRQA S 3473 1 #KQR003473 */
    REG_BITS_WRITE(Module->CTL.reg, (1UL << (uint32_t)IntIndex), ((State ? 1UL : 0UL) << (uint32_t)IntIndex));
}

/**
 * @brief 清零Ecc中断
 * @param Module 指向ECC寄存器结构的指针
 * @param IntIndex 清除中断序号, 可见 Ecc_IntrClearIndex_t
 * @retval None
 */
KF_INLINE void Ecc_LL_ClearIntrFlag(Ecc_RegisterMap_t *const Module, Ecc_IntrClearIndex_t IntIndex)
{
    KF_ECC_ASSERT(CHECK_ECC_ALL_PERIPH_ADDR(Module));
    KF_ECC_ASSERT(CHECK_ECC_INTRCLEARINDEX(IntIndex));

    /* PRQA S 3473 1 #KQR003473 */
    REG_BITS_WRITE(Module->CTL.reg, (1UL << (uint32_t)IntIndex), (0x1UL << (uint32_t)IntIndex));
}

/**
 * @brief Get Ecc Module Flag Status
 * @param Module 指向ECC寄存器结构的指针
 * @param flag
 * @retval true/false
 */
KF_INLINE bool Ecc_LL_GetIntrFlag(const Ecc_RegisterMap_t *const Module, Ecc_IntrGetIndex_t IntIndex)
{
    KF_ECC_ASSERT(CHECK_ECC_ALL_PERIPH_ADDR(Module));
    KF_ECC_ASSERT(CHECK_ECC_INTRGETINDEX(IntIndex));

    return (REG_BITS_READ(Module->INT.reg, (0x1UL << (uint32_t)IntIndex), (uint32_t)IntIndex) != 0U);
}

/**
 * @brief 获取出现错误的地址
 * @param Module: Ecc寄存器结构体指针
 * @retval 无
 */
KF_INLINE uint32_t Ecc_LL_GetErrorAddress(const Ecc_RegisterMap_t *const Module)
{
    KF_ECC_ASSERT(CHECK_ECC_ALL_PERIPH_ADDR(Module));
    return Module->ERRADDR;
}

/**
 * @brief: ECC错误注入使能
 * @param Module Ecc寄存器结构体指针
 * @param Offset 错误注入寄存器偏移
 * @param Mask 操作的bit位
 * @param State
 *          true 使能数据错误产生
 *          false 无动作
 * @retval void
 */
KF_INLINE void Ecc_LL_SetErrorBitInjectionEnabled(
    Ecc_RegisterMap_t *const Module, Ecc_ErrorInjectionOffset_t Offset, uint32_t Mask, bool State)
{
    KF_ECC_ASSERT(CHECK_ECC_ALL_PERIPH_ADDR(Module));

    if (State == true)
    {
        /* PRQA S 3473 1 #KQR003473 */
        REG_BIT_SET(Module->EBR[Offset], Mask);
    }
    else
    {
        /* PRQA S 3473 1 #KQR003473 */
        REG_BIT_CLR(Module->EBR[Offset], Mask);
    }
}

/**
 * @brief 获取ECC中断发生状态
 * @param Module 指向ECC寄存器结构的指针
 * @param flag
 * @retval bool 中断发生状态
 *         true    发生了中断，且已使能
 *         false    未发生中断，或未使能
 */
KF_INLINE bool Ecc_LL_GetIntrState(const Ecc_RegisterMap_t *const Module, Ecc_IntrGetIndex_t IntIndex)
{
    KF_ECC_ASSERT(CHECK_ECC_ALL_PERIPH_ADDR(Module));
    KF_ECC_ASSERT(CHECK_ECC_INTRGETINDEX(IntIndex));
    uint32_t mask  = (uint32_t)IntIndex + ((uint32_t)ECC_INTR_SET_MEMERRIE - (uint32_t)ECC_INTR_GET_MEMERRIF);
    bool     flag  = (REG_BITS_READ(Module->INT.reg, (0x1UL << (uint32_t)IntIndex), (uint32_t)IntIndex) != 0U);
    bool     state = (REG_BITS_READ(Module->CTL.reg, (0x1UL << mask), mask) != 0U);
    return flag && state;
}

#ifdef __cplusplus
}
#endif /*End of __cplusplus*/
#endif /*End of KF32A158SF_DRV_ECC_H*/
/* EOF */
