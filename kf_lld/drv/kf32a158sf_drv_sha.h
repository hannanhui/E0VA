/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name        : kf32a158sf_drv_sha.h
 *  @Date             : 2025-07-08
 *  @Version          : {{VersionDate}}
 *  @Description      : This file provides SHA driver.
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
#ifndef KF32A158SF_DRV_SHA_H
#define KF32A158SF_DRV_SHA_H

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

/******************************************************************************
 *                      Include Files
 ******************************************************************************/
#include "kf32a158sf_reg_sha.h"

/******************************************************************************
 *                      Macro or Inline
 ******************************************************************************/
#ifdef KF_DRV_SHA_ASSERT
#include "dev_assert.h"
#define KF_SHA_ASSERT(x) KF_DEV_ASSERT(x)
#else
#define KF_SHA_ASSERT(x) ((void)0U)
#endif

/**
 * @defgroup SHA_INTR0_SET_MASK
 * @brief Sha 中断使能掩码
 * @{
 */
/** @brief SHA 压缩完成中断 */
#define SHA_INTR0_SET_MASK_DONE (1UL << 0U)
/** @brief SHA 错误中断 */
#define SHA_INTR0_SET_MASK_ERROR (1UL << 1U)
/** @brief FIFO 为空中断 */
#define SHA_INTR0_SET_MASK_FIFO_EMPTY (1UL << 2U)

/** @brief FIFO 为满中断 */
#define SHA_INTR1_SET_MASK_FIFO_FULL (1UL << 2U)

#define CHECK_SHA_INTR0_SET_MASK(MASK)                                                                                 \
    (((uint32_t)(MASK) == (uint32_t)SHA_INTR0_SET_MASK_DONE) ||                                                        \
     ((uint32_t)(MASK) == (uint32_t)SHA_INTR0_SET_MASK_ERROR) ||                                                       \
     ((uint32_t)(MASK) == (uint32_t)SHA_INTR0_SET_MASK_FIFO_EMPTY))

#define CHECK_SHA_INTR1_SET_MASK(MASK) (((uint32_t)(MASK) == (uint32_t)SHA_INTR1_SET_MASK_FIFO_FULL))
/**@} */

/**
 * @defgroup SHA_INTR_CLEAR_MASK
 * @brief Sha 中断清除掩码
 * @{
 */
/** @brief SHA 压缩完成中断 */
#define SHA_INTR0_CLR_MASK_DONE (1UL << 0U)
/** @brief SHA 错误中断 */
#define SHA_INTR0_CLR_MASK_ERROR (1UL << 1U)

#define CHECK_SHA_INTR0_CLEAR_MASK(MASK)                                                                               \
    (((uint32_t)(MASK) == (uint32_t)SHA_INTR0_CLR_MASK_DONE) ||                                                        \
     ((uint32_t)(MASK) == (uint32_t)SHA_INTR0_CLR_MASK_ERROR))
/**@} */

/**
 * @brief Sha 命令掩码
 */
#define SHA_CMD_MASK (0x1FU)

/******************************************************************************
 *                      Type definitions
 ******************************************************************************/

/**
 * @brief Sha 中断获取索引
 */
typedef enum
{
    /** @brief 压缩完成中断索引 */
    SHA_INTR_GET_INDEX_DONE,
    /** @brief 错误中断索引 */
    SHA_INTR_GET_INDEX_ERROR,
    /** @brief FIFO 为空中断索引 */
    SHA_INTR_GET_INDEX_FIFO_EMPTY,
} Sha_IntrGetIndex_t;
#define CHECK_SHA_INTR_GET_INDEX(INDEX)                                                                                \
    ((uint32_t)(INDEX) == (uint32_t)SHA_INTR_GET_INDEX_DONE ||                                                         \
     (uint32_t)(INDEX) == (uint32_t)SHA_INTR_GET_INDEX_ERROR ||                                                        \
     (uint32_t)(INDEX) == (uint32_t)SHA_INTR_GET_INDEX_FIFO_EMPTY)

/**
 * @brief Sha 命令
 */
typedef enum
{
    /** @brief 启动 hash 运算 */
    SHA_CMD_START,
    /** @brief 处理 hash 运算 */
    SHA_CMD_PROCESS,
    /** @brief 停止 hash 运算 */
    SHA_CMD_STOP,
    /** @brief 继续 hash 运算 */
    SHA_CMD_CONTINUE,
    /** @brief 暂停 hash 运算 */
    SHA_CMD_SUSPEND,
} Sha_Cmd_t;
#define CHECK_SHA_CMD(CMD)                                                                                             \
    (((uint32_t)(CMD) == (uint32_t)SHA_CMD_START) || ((uint32_t)(CMD) == (uint32_t)SHA_CMD_PROCESS) ||                 \
     ((uint32_t)(CMD) == (uint32_t)SHA_CMD_STOP) || ((uint32_t)(CMD) == (uint32_t)SHA_CMD_CONTINUE) ||                 \
     ((uint32_t)(CMD) == (uint32_t)SHA_CMD_SUSPEND))

/**
 * @brief Sha 错误码
 */
typedef enum
{
    SHA_ERR_NONE,
    SHA_ERR_START_BEFORE_ENABLE,
    SHA_ERR_REPEAT_START,
    SHA_ERR_INPUT_MSG_AT_WRONG_TIME,
    SHA_ERR_PROCESS_AT_WRONG_TIME,
    SHA_ERR_STOP_BUT_MSG_NOT_ALIGN_512,
    SHA_ERR_INPUT_MSG_WHEN_FIFO_IS_FULL,
} Sha_ErrCode_t;
#define CHECK_SHA_ERR_CODE(CODE) ((uint32_t)(CODE) <= (uint32_t)SHA_ERR_INPUT_MSG_WHEN_FIFO_IS_FULL)

/**
 * @brief Sha 时钟源
 */
typedef enum
{
    SHA_CLK_SCLK,
    SHA_CLK_HFCLK,
    SHA_CLK_LFCLK,
} Sha_ClockSource_t;
#define CHECK_SHA_CLK_SOURCE(SOURCE) ((uint32_t)(SOURCE) <= (uint32_t)SHA_CLK_LFCLK)

/******************************************************************************
 *                      Export Variables
 ******************************************************************************/

/******************************************************************************
 *                      Export Functions
 ******************************************************************************/

/**
 * @brief 获取 Sha 中断状态
 *
 * @param IntrIndex 中断索引
 * @return bool
 * @retval true: 中断触发
 * @retval false: 中断未触发
 */
KF_INLINE bool Sha_LL_GetIntrFlag(Sha_IntrGetIndex_t IntrIndex)
{
    KF_SHA_ASSERT(CHECK_SHA_INTR_GET_INDEX(IntrIndex));

    /* PRQA S 3469 1 #KQR003469 */
    return (REG_BIT_BOOLED(SHA_PTR->STA.reg, (1UL << (uint32_t)IntrIndex)));
}

/**
 * @brief 清除 Sha 中断0标志位
 *
 * @param IntrMask 中断0标志位掩码, 可选值见 SHA_INTR0_CLEAR_MASK
 * @return void
 */
KF_INLINE void Sha_LL_ClearIntr0Flag(uint32_t IntrMask)
{
    KF_SHA_ASSERT(CHECK_SHA_INTR0_CLEAR_MASK(IntrMask));

    SHA_PTR->STA.reg = IntrMask;
}

/**
 * @brief 设置 SHA 中断0使能状态
 *
 * @param IntrMask 中断0使能掩码, 可选值见 SHA_INTR0_SET_MASK
 * @return void
 */
KF_INLINE void Sha_LL_SetIntr0Enabled(uint32_t IntrMask, bool State)
{
    KF_SHA_ASSERT(CHECK_SHA_INTR0_SET_MASK(IntrMask));

    /* PRQA S 3473 ++ #KQR003473 */
    if (State)
    {
        REG_BIT_SET(SHA_PTR->ENABLE0.reg, IntrMask);
    }
    else
    {
        REG_BIT_CLR(SHA_PTR->ENABLE0.reg, IntrMask);
    }
    /* PRQA S 3473 -- #KQR003473 */
}

/**
 * @brief 设置 SHA 使能状态
 *
 * @param State 使能状态
 *        true: 使能
 *        false: 关闭
 * @return void
 */
KF_INLINE void Sha_LL_SetEnabled(bool State)
{
    SHA_PTR->CFG.bits.SHA_EN = (true == State) ? 1U : 0U;
}

/**
 * @brief 设置消息输入字节序交换使能
 *
 * @param State 使能状态
 *        true: 使能
 *        false: 关闭
 * @return void
 */
KF_INLINE void Sha_LL_SetMessageInputEndianSwapEnabled(bool State)
{
    SHA_PTR->CFG.bits.ENDIAN_SWAP = (true == State) ? 1U : 0U;
}

/**
 * @brief 设置摘要输出字节序交换使能
 *
 * @param State 使能状态
 *        true: 使能
 *        false: 关闭
 * @return void
 */
KF_INLINE void Sha_LL_SetDigestOutputEndianSwapEnabled(bool State)
{
    SHA_PTR->CFG.bits.DIGEST_ENDIAN = (true == State) ? 1U : 0U;
}

/**
 * @brief 设置 SHA 命令
 * @note 此函数会清除 CMD 寄存器的其他位
 *
 * @param Cmd 命令
 * @return void
 */
KF_INLINE void Sha_LL_SetCommand(Sha_Cmd_t Cmd)
{
    KF_SHA_ASSERT(CHECK_SHA_CMD(Cmd));

    SHA_PTR->CMD.reg = (1UL << (uint32_t)Cmd);
}

/**
 * @brief 获取 SHA 运算状态
 *
 * @return bool
 * @retval true: 加密运算中
 * @retval false: 未加密运算
 */
KF_INLINE bool Sha_LL_GetRunState(void)
{
    return (SHA_PTR->STATUS.bits.HASH_RUNING != 0U);
}

/**
 * @brief 获取 SHA 空闲状态
 *
 * @return bool
 * @retval true: 空闲
 * @retval false: 忙
 */
KF_INLINE bool Sha_LL_GetIdleState(void)
{
    return (SHA_PTR->STATUS.bits.HASH_IDLE != 0U);
}

/**
 * @brief 获取 FIFO 空状态
 *
 * @return bool
 * @retval true: 空
 * @retval false: 非空
 */
KF_INLINE bool Sha_LL_GetFifoEmptyState(void)
{
    return (SHA_PTR->STATUS.bits.FIFO_EMPTY != 0U);
}

/**
 * @brief 获取 FIFO 满状态
 *
 * @return  bool
 * @retval true: 满
 * @retval false: 非满
 */
KF_INLINE bool Sha_LL_GetFifoFullState(void)
{
    return (SHA_PTR->STATUS.bits.FIFO_FULL != 0U);
}

/**
 * @brief 获取 FIFO 深度
 *
 * @return uint32_t
 */
KF_INLINE uint32_t Sha_LL_GetFifoDepth(void)
{
    return (SHA_PTR->STATUS.bits.FIFO_DEPTH);
}

/**
 * @brief 获取错误码
 *
 * @return Sha_ErrCode_t, 见 Sha_ErrCode_t
 */
KF_INLINE Sha_ErrCode_t Sha_LL_GetErrCode(void)
{
    /* PRQA S 4342 1 #KQR004342 */
    return (Sha_ErrCode_t)(SHA_PTR->ERRCODE.bits.CODE);
}

/**
 * @brief 获取摘要值
 *
 * @param DigestBuffer 指向存储摘要值的缓冲区的指针, 必须非 NULL
 * @return void
 */
KF_INLINE void Sha_LL_GetDigest(uint32_t *DigestBuffer)
{
    KF_SHA_ASSERT((NULL != DigestBuffer));

    for (uint32_t i = 0U; i < 8U; i++)
    {
        DigestBuffer[i] = SHA_PTR->DIGEST[i];
    }
}

/**
 * @brief 设置摘要值
 *
 * @param DigestBuffer 指向存储摘要值的缓冲区的指针, 必须非 NULL
 * @return void
 */
KF_INLINE void Sha_LL_SetDigest(uint32_t const *DigestBuffer)
{
    KF_SHA_ASSERT((NULL != DigestBuffer));

    for (uint32_t i = 0U; i < 8U; i++)
    {
        SHA_PTR->DIGEST[i] = DigestBuffer[i];
    }
}

/**
 * @brief 设置消息长度
 *
 * @param MsgLen 消息长度, 单位 Byte
 * @return void
 */
KF_INLINE void Sha_LL_SetMessageLength(uint32_t MsgLen)
{
    KF_SHA_ASSERT((MsgLen > 0U));

    SHA_PTR->MSGH = (MsgLen & 0xE0000000U) >> 29U;
    SHA_PTR->MSGL = MsgLen << 3U;
}

/**
 * @brief 设置清除数据
 * @note 内部状态和 digest 被置为 WIPE 输入值
 *       SHA 未使能时可配置
 *
 * @param Data 清除数据
 * @return void
 */
KF_INLINE void Sha_LL_SetWipeData(uint32_t Data)
{
    SHA_PTR->WIPE = Data;
}

/**
 * @brief 输入消息
 *
 * @param Data 消息数据
 * @return void
 */
KF_INLINE void Sha_LL_InputMessage(uint32_t Data)
{
    SHA_PTR->FIFO = Data;
}

/**
 * @brief 选择时钟源
 *
 * @param Clock 时钟源, 见 Sha_ClockSource_t
 * @return void
 */
KF_INLINE void Sha_LL_SelectClockSource(Sha_ClockSource_t Clock)
{
    KF_SHA_ASSERT(CHECK_SHA_CLK_SOURCE(Clock));

    SHA_PTR->CTL0.bits.CLK_SEL = (uint32_t)Clock;
}

/**
 * @brief 设置 DMA 请求使能
 *
 * @param State 使能状态
 *        true: 使能
 *        false: 关闭
 * @return void
 */
KF_INLINE void Sha_LL_SetDmaRequestEnabled(bool State)
{
    SHA_PTR->CTL0.bits.DMA_EN = (true == State) ? 1U : 0U;
}

/**
 * @brief 设置掩码使能
 *
 * @param State 使能状态
 *        true: 使能掩码写入功能
 *        false: 禁止掩码写入功能
 * @return void
 */
KF_INLINE void Sha_LL_SetMaskEnabled(bool State)
{
    SHA_PTR->CTL0.bits.MASK_EN = (true == State) ? 1U : 0U;
}

/**
 * @brief 设置掩码
 *
 * @param Mask 掩码值, 取值范围 0x0 ~ 0xFU
 * @return void
 */
KF_INLINE void Sha_LL_SetMask(uint32_t Mask)
{
    KF_SHA_ASSERT(Mask < 0xFU);

    SHA_PTR->CTL0.bits.MASK = Mask;
}

/**
 * @brief 获取 DMA 请求状态
 *
 * @return bool
 * @retval true: DMA 正在请求
 * @retval false: DMA 未请求
 */
KF_INLINE bool Sha_LL_GetDmaRequestState(void)
{
    return (SHA_PTR->CTL0.bits.DMA_REQ_FLAG != 0U);
}

/**
 * @brief 获取已处理消息长度
 *
 * @return uint32_t, 单位 Byte
 */
KF_INLINE uint32_t Sha_LL_GetProcessedMessageLength(void)
{
    uint32_t tmpLen = (SHA_PTR->COUNT1 & 0x7U) << 29U;
    tmpLen += (SHA_PTR->COUNT0 >> 3U);

    return tmpLen;
}

/**
 * @brief 设置已处理消息长度
 *
 * @param Length 已处理消息长度, 单位 Byte

 * @return void
 */
KF_INLINE void Sha_LL_SetProcessedMessageLength(uint32_t Length)
{
    SHA_PTR->COUNT1 = (Length & 0xE0000000U) >> 29U;
    SHA_PTR->COUNT0 = Length << 3U;
}

/**
 * @brief 获取扩展已处理消息长度, 单位 0xFFFFFFFF Bytes
 * @note 当消息长度大于 0xFFFFFFFF 时, 扩展已处理消息长度才有效
 *
 * @return uint32_t
 */
KF_INLINE uint32_t Sha_LL_GetExtendProcessedMessageLength(void)
{
    uint32_t tmpLen = (SHA_PTR->COUNT1 & 0xFFFFFFF8U) >> 3U;
    return tmpLen;
}

/**
 * @brief 设置扩展已处理消息长度
 *
 * @param Length 扩展已处理消息长度, 单位 0xFFFFFFFF Bytes
 * @return void
 */
KF_INLINE void Sha_LL_SetExtendProcessedMessageLength(uint32_t Length)
{
    SHA_PTR->COUNT1 = (SHA_PTR->COUNT1 & 0x7U) | (Length << 3U);
}

/**
 * @brief 获取剩余消息长度, 单位: 字
 *
 * @return uint32_t
 */
KF_INLINE uint32_t Sha_LL_GetLeftMessageLength(void)
{
    return SHA_PTR->LENGTH;
}

/**
 * @brief 设置剩余消息长度, 单位: 字
 *
 * @return void
 */
KF_INLINE void Sha_LL_SetLeftMessageLength(uint32_t Length)
{
    SHA_PTR->LENGTH = Length;
}

/**
 * @brief 获取中断状态及使能状态
 *
 * @param IntrIndex 中断索引
 * @return bool
 */
KF_INLINE bool Sha_LL_GetIntr0State(Sha_IntrGetIndex_t IntrIndex)
{
    KF_SHA_ASSERT(CHECK_SHA_INTR_GET_INDEX(IntrIndex));

    uint32_t mask = (1UL << (uint32_t)IntrIndex);

    bool status = ((SHA_PTR->ENABLE0.reg & mask) != 0U);
    bool flag   = ((SHA_PTR->STA.reg & mask) != 0U);

    return (status && flag);
}

#ifdef __cplusplus
}
#endif /*End of __cplusplus*/
#endif /*End of KF32A158SF_DRV_SHA_H*/
/* EOF */
