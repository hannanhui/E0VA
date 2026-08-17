/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name        : kf32a158sf_drv_rsa.h
 *  @Date             : 2025-07-09
 *  @Version          : {{VersionDate}}
 *  @Description      : This file provides RSA driver.
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
 *  |2025-07-09  |V1.0     |AE Group     |New create
 ******************************************************************************/
#ifndef KF32A158SF_DRV_RSA_H
#define KF32A158SF_DRV_RSA_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 *                      QAC Warnings
 ******************************************************************************/
/* PRQA S 0288 EOF #KQR000288 */
/* PRQA S 3205 EOF #KQR003205 */
/* PRQA S 3219 EOF #KQR003219 */
/* PRQA S 0303,0306 EOF #KQR100303 */
/* PRQA S 1006,3006 EOF #KQR101006 */

/******************************************************************************
 *                      Include Files
 ******************************************************************************/
#include "kf32a158sf_reg_rsa.h"

/******************************************************************************
 *                      Macro or Inline
 ******************************************************************************/
#ifdef KF_DRV_RSA_ASSERT
#include "dev_assert.h"
#define KF_RSA_ASSERT(x) KF_DEV_ASSERT(x)
#else
#define KF_RSA_ASSERT(x) ((void)0U)
#endif

/**
 * @defgroup RSA_INTR_SET_MASK
 * @brief Rsa 中断使能掩码
 * @{
 */
/** @brief ECC 运算结束中断 */
#define RSA_INTR_SET_MASK_ECC_DONE (1UL << 0U)
/** @brief RSA 运算结束中断 */
#define RSA_INTR_SET_MASK_RSA_DONE (1UL << 1U)
/** @brief ECC 运算错误中断 */
#define RSA_INTR_SET_MASK_ECC_ERR (1UL << 3U)
/** @brief RSA 运算错误中断 */
#define RSA_INTR_SET_MASK_RSA_ERR (1UL << 2U)

#define CHECK_RSA_INTR_SET_MASK(MASK)                                                                                  \
    (((uint32_t)(MASK) == (uint32_t)RSA_INTR_SET_MASK_ECC_DONE) ||                                                     \
     ((uint32_t)(MASK) == (uint32_t)RSA_INTR_SET_MASK_RSA_DONE) ||                                                     \
     ((uint32_t)(MASK) == (uint32_t)RSA_INTR_SET_MASK_ECC_ERR) ||                                                      \
     ((uint32_t)(MASK) == (uint32_t)RSA_INTR_SET_MASK_RSA_ERR))
/**@} */

/**
 * @defgroup RSA_INTR_CLEAR_MASK
 * @brief Rsa 中断清除掩码
 * @{
 */
/** @brief ECC 运算结束中断 */
#define RSA_INTR_CLR_MASK_ECC_DONE (1UL << 0U)
/** @brief RSA 运算结束中断 */
#define RSA_INTR_CLR_MASK_RSA_DONE (1UL << 1U)
/** @brief ECC 运算错误中断 */
#define RSA_INTR_CLR_MASK_ECC_ERR (1UL << 3U)
/** @brief RSA 运算错误中断 */
#define RSA_INTR_CLR_MASK_RSA_ERR (1UL << 2U)

#define CHECK_RSA_INTR_CLR_MASK(MASK)                                                                                  \
    (((uint32_t)(MASK) == (uint32_t)RSA_INTR_CLR_MASK_ECC_DONE) ||                                                     \
     ((uint32_t)(MASK) == (uint32_t)RSA_INTR_CLR_MASK_RSA_DONE) ||                                                     \
     ((uint32_t)(MASK) == (uint32_t)RSA_INTR_CLR_MASK_ECC_ERR) ||                                                      \
     ((uint32_t)(MASK) == (uint32_t)RSA_INTR_CLR_MASK_RSA_ERR))
/**@} */

/******************************************************************************
 *                      Type definitions
 ******************************************************************************/

/**
 * @brief RSA 密钥长度
 */
typedef enum
{
    SHA_KEY_LENGTH_1024,
    SHA_KEY_LENGTH_2048,
    SHA_KEY_LENGTH_3072,
} Rsa_KeyLength_t;
#define CHECK_RSA_KEY_LENGTH(LEN) (((uint32_t)(LEN) <= (uint32_t)SHA_KEY_LENGTH_1024))

/**
 * @brief RSA 时钟源
 */
typedef enum
{
    RSA_CLK_SCLK,
    RSA_CLK_PLL1,
    RSA_CLK_LFCLK,
} Rsa_ClockSource_t;
#define CHECK_RSA_CLK_SOURCE(SOURCE) ((uint32_t)(SOURCE) <= (uint32_t)RSA_CLK_LFCLK)

/**
 * @brief Rsa 中断获取索引
 */
typedef enum
{
    /** @brief ECC 运算结束中断 */
    RSA_INTR_GET_INDEX_ECC_DONE = 0U,
    /** @brief RSA 运算结束中断 */
    RSA_INTR_GET_INDEX_RSA_DONE = 1U,
    /** @brief RSA 运算错误中断 */
    RSA_INTR_GET_INDEX_RSA_ERR = 2U,
    /** @brief ECC 运算错误中断 */
    RSA_INTR_GET_INDEX_ECC_ERR = 3U,
} Rsa_IntrGetIndex_t;
#define CHECK_RSA_INTR_GET_INDEX(INDEX) (((uint32_t)(INDEX) <= (uint32_t)RSA_INTR_GET_INDEX_ECC_ERR))

/******************************************************************************
 *                      Export Variables
 ******************************************************************************/

/******************************************************************************
 *                      Export Functions
 ******************************************************************************/

/**
 * @brief 选择密钥长度
 *
 * @param KeyLen 密钥长度, 见 Rsa_KeyLength_t
 * @return void
 */
KF_INLINE void Rsa_LL_SetKeyLength(Rsa_KeyLength_t KeyLen)
{
    KF_RSA_ASSERT(CHECK_RSA_KEY_LENGTH(KeyLen));

    RSA_PTR->CTL0.bits.SEL_RSA_LEN = (uint32_t)KeyLen;
}

/**
 * @brief 设置输入字节序交换使能
 *
 * @param State 使能状态
 *        true: 使能
 *        false: 关闭
 * @return void
 */
KF_INLINE void Rsa_LL_SetInputEndianSwapEnabled(bool State)
{
    RSA_PTR->CTL0.bits.ENDIAN_SWAP = (true == State) ? 1U : 0U;
}

/**
 * @brief 设置输出字节序交换使能
 *
 * @param State 使能状态
 *        true: 使能
 *        false: 关闭
 * @return void
 */
KF_INLINE void Rsa_LL_SetOutputEndianSwapEnabled(bool State)
{
    RSA_PTR->CTL0.bits.READ_SWAP = (true == State) ? 1U : 0U;
}

/**
 * @brief 设置 ECC/RSA 锁功能使能
 *
 * @param State 使能状态
 *        true: 使能
 *        false: 关闭
 * @return void
 */
KF_INLINE void Rsa_LL_SetLockEnabled(bool State)
{
    RSA_PTR->CTL0.bits.LOCK_EN = (true == State) ? 1U : 0U;
}

/**
 * @brief 设置时钟源
 *
 * @param Clock 时钟源, 见 Rsa_ClockSource_t
 * @return void
 */
KF_INLINE void Rsa_LL_SelectClockSource(Rsa_ClockSource_t Clock)
{
    KF_RSA_ASSERT(CHECK_RSA_CLK_SOURCE(Clock));

    RSA_PTR->CTL0.bits.CLK_SEL = (uint32_t)Clock;
}

/**
 * @brief 设置启动 RSA 运算使能
 *
 * @param State 使能状态
 *        true: 使能
 *        false: 关闭
 * @return void
 */
KF_INLINE void Rsa_LL_StartRsaProcess(bool State)
{
    RSA_PTR->CTL0.bits.START_RSA = (true == State) ? 1U : 0U;
}

/**
 * @brief 设置启动 ECC 运算使能
 *
 * @param State 使能状态
 *        true: 使能
 *        false: 关闭
 * @return void
 */
KF_INLINE void Rsa_LL_StartEccProcess(bool State)
{
    RSA_PTR->CTL0.bits.START_ECC = (true == State) ? 1U : 0U;
}

/**
 * @brief 获取中断标志位
 *
 * @param IntrIndex 中断索引, 见 Rsa_IntrGetIndex_t
 * @return bool 中断标志位状态
 * @retval true: 中断触发
 * @retval false: 中断未触发
 */
KF_INLINE bool Rsa_LL_GetIntrFlag(Rsa_IntrGetIndex_t IntrIndex)
{
    KF_RSA_ASSERT(CHECK_RSA_INTR_GET_INDEX(IntrIndex));

    /* PRQA S 3469 1 #KQR003469 */
    return (REG_BIT_BOOLED(RSA_PTR->STATE.reg, (1UL << (uint32_t)IntrIndex)));
}

/**
 * @brief 获取 ECC/RSA 锁状态
 *
 * @return bool 锁状态
 * @retval true: 锁功能有效
 * @retval false: 锁功能失效
 */
KF_INLINE bool Rsa_LL_GetLockState(void)
{
    return (RSA_PTR->STATE.bits.LOCK_FLAG != 0U);
}

/**
 * @brief 设置中断使能
 *
 * @param IntrMask 中断使能掩码, 见 RSA_INTR_SET_MASK
 * @return void
 */
KF_INLINE void Rsa_LL_SetIntrEnabled(uint32_t IntrMask, bool State)
{
    KF_RSA_ASSERT(CHECK_RSA_INTR_SET_MASK(IntrMask));

    /* PRQA S 3473 ++ #KQR003473 */
    if (State)
    {
        REG_BIT_SET(RSA_PTR->ENABLE.reg, IntrMask);
    }
    else
    {
        REG_BIT_CLR(RSA_PTR->ENABLE.reg, IntrMask);
    }
    /* PRQA S 3473 -- #KQR003473 */
}

/**
 * @brief 清除中断使能
 *
 * @param IntrMask 中断使能掩码, 见 RSA_INTR_CLEAR_MASK
 * @return void
 */
KF_INLINE void Rsa_LL_ClearIntrFlag(uint32_t IntrMask)
{
    KF_RSA_ASSERT(CHECK_RSA_INTR_CLR_MASK(IntrMask));

    /* PRQA S 3473 ++ #KQR003473 */
    REG_BIT_SET(RSA_PTR->CLR.reg, IntrMask);
    /* PRQA S 3473 -- #KQR003473 */
}

/**
 * @brief 设置 K 值寄存器
 *
 * @param Buffer 指向 K 值数组的指针, 必须非 NULL
 * @return void
 */
KF_INLINE void Rsa_LL_SetKValue(uint32_t const *Buffer)
{
    KF_RSA_ASSERT((NULL != Buffer));

    for (uint32_t i = 0U; i < 8U; i++)
    {
        RSA_PTR->KVALUE[i] = Buffer[7U - i];
    }
}

/**
 * @brief 输入 RSA 模数
 *
 * @param Buffer 指向 RSA 模数数组的指针, 必须非 NULL
 * @param Length RSA 模数长度, 单位为字, 最大 96 字
 * @return void
 */
KF_INLINE void Rsa_LL_InputRsaModulus(uint32_t const *Buffer, uint32_t Length)
{
    KF_RSA_ASSERT((NULL != Buffer));
    KF_RSA_ASSERT((Length <= 96U) && (Length != 0U));

    uint32_t volatile *pModulusU32 = (uint32_t volatile *)RSA_MODULUS_ADDR;

    for (uint32_t i = 0U; i < Length; i++)
    {
        /* @attention big endian */
        pModulusU32[i] = Buffer[Length - i - 1U];
    }
}

/**
 * @brief 输入 RSA 指数
 *
 * @param Buffer 指向 RSA 指数数组的指针, 必须非 NULL
 * @param Length RSA 指数长度, 单位为字, 最大 96 字
 * @return void
 */
KF_INLINE void Rsa_LL_InputRsaExponent(uint32_t const *Buffer, uint32_t Length)
{
    KF_RSA_ASSERT((NULL != Buffer));
    KF_RSA_ASSERT((Length <= 96U) && (Length != 0U));

    uint32_t volatile *pExponentU32 = (uint32_t volatile *)RSA_EXPONENT_ADDR;

    for (uint32_t i = 0U; i < Length; i++)
    {
        /* @attention big endian */
        pExponentU32[i] = Buffer[Length - i - 1U];
    }
}

/**
 * @brief 输入 RSA 消息
 *
 * @param Buffer 指向 RSA 消息数组的指针, 必须非 NULL
 * @param Length RSA 消息长度, 单位为字, 最大 96 字
 * @return void
 */
KF_INLINE void Rsa_LL_InputRsaMessage(uint32_t const *Buffer, uint32_t Length)
{
    KF_RSA_ASSERT((NULL != Buffer));
    KF_RSA_ASSERT((Length <= 96U) && (Length != 0U));

    uint32_t volatile *pMessageU32 = (uint32_t volatile *)RSA_MESSAGE_ADDR;

    for (uint32_t i = 0U; i < Length; i++)
    {
        /* @attention big endian */
        pMessageU32[i] = Buffer[Length - i - 1U];
    }
}

/**
 * @brief 获取 RSA 处理结果
 *
 * @param Buffer 指向 RSA 处理结果数组的指针, 必须非 NULL
 * @param Length RSA 处理结果长度, 单位为字, 最大 96 字
 * @return void
 */
KF_INLINE void Rsa_LL_GetRsaProcessResult(volatile uint32_t *Buffer, uint32_t Length)
{
    KF_RSA_ASSERT((NULL != Buffer));
    KF_RSA_ASSERT((Length <= 96U) && (Length != 0U));

    uint32_t const *pMessageU32 = (uint32_t const *)RSA_RESULT_ADDR;

    for (uint32_t i = 0U; i < Length; i++)
    {
        /* @attention big endian */
        Buffer[i] = pMessageU32[Length - i - 1U];
    }
}

/**
 * @brief 输入 ECC 模数
 *
 * @param Buffer 指向 ECC 模数数组的指针, 必须非 NULL
 * @return void
 */
KF_INLINE void Rsa_LL_InputEccModulus(uint32_t const *Buffer)
{
    KF_RSA_ASSERT((NULL != Buffer));

    uint32_t *pModulusU32 = (uint32_t *)ECC_MODULUS_ADDR;

    for (uint32_t i = 0U; i < 8U; i++)
    {
        pModulusU32[i] = Buffer[7U - i];
    }
}

/**
 * @brief 输入 ECC 常量 A
 *
 * @param Buffer 指向 ECC 常量 A 数组的指针, 必须非 NULL
 * @return void
 */
KF_INLINE void Rsa_LL_InputEccConstantA(uint32_t const *Buffer)
{
    KF_RSA_ASSERT((NULL != Buffer));

    uint32_t *pConstantAU32 = (uint32_t *)ECC_CONSTANT_A_ADDR;

    for (uint32_t i = 0U; i < 8U; i++)
    {
        pConstantAU32[i] = Buffer[7U - i];
    }
}

/**
 * @brief 输入 ECC 坐标 X
 *
 * @param Buffer 指向 ECC 坐标 X 数组的指针, 必须非 NULL
 * @return void
 */
KF_INLINE void Rsa_LL_InputEccCoordinateX(uint32_t const *Buffer)
{
    KF_RSA_ASSERT((NULL != Buffer));

    uint32_t *pCoordinateXU32 = (uint32_t *)ECC_COORDINATE_X_ADDR;

    for (uint32_t i = 0U; i < 8U; i++)
    {
        pCoordinateXU32[i] = Buffer[7U - i];
    }
}

/**
 * @brief 输入 ECC 坐标 Y
 *
 * @param Buffer 指向 ECC 坐标 Y 数组的指针, 必须非 NULL
 * @return void
 */
KF_INLINE void Rsa_LL_InputEccCoordinateY(uint32_t const *Buffer)
{
    KF_RSA_ASSERT((NULL != Buffer));

    uint32_t *pCoordinateYU32 = (uint32_t *)ECC_COORDINATE_Y_ADDR;

    for (uint32_t i = 0U; i < 8U; i++)
    {
        pCoordinateYU32[i] = Buffer[7U - i];
    }
}

/**
 * @brief 输入 ECC 坐标 Z
 *
 * @param Buffer 指向 ECC 坐标 Z 数组的指针, 必须非 NULL
 * @return void
 */
KF_INLINE void Rsa_LL_InputEccCoordinateZ(uint32_t const *Buffer)
{
    KF_RSA_ASSERT((NULL != Buffer));

    uint32_t *pCoordinateZU32 = (uint32_t *)ECC_COORDINATE_Z_ADDR;

    for (uint32_t i = 0U; i < 8U; i++)
    {
        pCoordinateZU32[i] = Buffer[7U - i];
    }
}

/**
 * @brief 获取 ECC 处理后的坐标 X
 *
 * @param Buffer 指向 ECC 坐标 X 数组的指针, 必须非 NULL
 * @return void
 */
KF_INLINE void Rsa_LL_GetEccProcessResultCoordinateX(volatile uint32_t *Buffer)
{
    KF_RSA_ASSERT((NULL != Buffer));

    uint32_t const *pCoordinateXU32 = (uint32_t const *)ECC_COORDINATE_X_ADDR;

    for (uint32_t i = 0U; i < 8U; i++)
    {
        Buffer[i] = pCoordinateXU32[7U - i];
    }
}

/**
 * @brief 获取 ECC 处理后的坐标 Y
 *
 * @param Buffer 指向 ECC 坐标 Y 数组的指针, 必须非 NULL
 * @return void
 */
KF_INLINE void Rsa_LL_GetEccProcessResultCoordinateY(volatile uint32_t *Buffer)
{
    KF_RSA_ASSERT((NULL != Buffer));

    uint32_t const *pCoordinateYU32 = (uint32_t const *)ECC_COORDINATE_Y_ADDR;

    for (uint32_t i = 0U; i < 8U; i++)
    {
        Buffer[i] = pCoordinateYU32[7U - i];
    }
}

/**
 * @brief 获取 ECC 处理后的坐标 Z
 *
 * @param Buffer 指向 ECC 坐标 Z 数组的指针, 必须非 NULL
 * @return void
 */
KF_INLINE void Rsa_LL_GetEccProcessResultCoordinateZ(volatile uint32_t *Buffer)
{
    KF_RSA_ASSERT((NULL != Buffer));

    uint32_t const *pCoordinateZU32 = (uint32_t const *)ECC_COORDINATE_Z_ADDR;

    for (uint32_t i = 0U; i < 8U; i++)
    {
        Buffer[i] = pCoordinateZU32[7U - i];
    }
}

#ifdef __cplusplus
}
#endif /*End of __cplusplus*/
#endif /*End of KF32A158SF_DRV_RSA_H*/
       /* EOF */
