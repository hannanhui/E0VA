/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name        : kf32a158sf_drv_aes.h
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
#ifndef KF32A158SF_DRV_AES_H
#define KF32A158SF_DRV_AES_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 *                      QAC Warnings
 ******************************************************************************/
/* PRQA S 0288 EOF #KQR000288 */
/* PRQA S 3205 EOF #KQR003205 */
/* PRQA S 3219 EOF #KQR003219 */
/******************************************************************************
 *                      Include Files
 ******************************************************************************/
#include <stdint.h>
#include <stdbool.h>
#include "kf_types.h"
#include "kf32a158sf_reg_aes.h"

#ifdef KF_DRV_AES_ASSERT
#include "dev_assert.h"
#define KF_AES_ASSERT(x) KF_DEV_ASSERT(x)
#else
#define KF_AES_ASSERT(x) ((void)0U)
#endif
/******************************************************************************
 *                      Macro or Inline
 ******************************************************************************/

/******************************************************************************
 *                      Type definitions
 ******************************************************************************/

/** 链接模式 */
typedef enum
{
    /** ECB模式 */
    AES_LINK_MODE_ECB = 0x0U,
    /** CTR模式 */
    AES_LINK_MODE_CTR,
    /** CBC_ENC模式 */
    AES_LINK_MODE_CBC_ENC,
    /** CBC_DEC模式 */
    AES_LINK_MODE_CBC_DEC,
    /** GMAC_ENC模式 */
    AES_LINK_MODE_GMAC_ENC,
    /** GMAC_DEC模式 */
    AES_LINK_MODE_GMAC_DEC,
    /** CCM_ENC模式 */
    AES_LINK_MODE_CCM_ENC,
    /** CCM_DEC模式 */
    AES_LINK_MODE_CCM_DEC,
} Aes_LinkMode_t;
#define CHECK_AES_LINKMODE(x) (((x) >= AES_LINK_MODE_ECB) && ((x) <= AES_LINK_MODE_CCM_DEC))

/** GCM,CCM阶段 */
typedef enum
{
    AES_GCMPH_INIT = 0x0U,
    AES_GCMPH_HEADER,
    AES_GCMPH_PAYLOAD,
    AES_GCMPH_FINAL,
} Aes_Phase_t;
#define CHECK_AES_PHASE(x)                                                                                             \
    (((x) == AES_GCMPH_INIT) || ((x) == AES_GCMPH_HEADER) || ((x) == AES_GCMPH_PAYLOAD) || ((x) == AES_GCMPH_FINAL))

/** 数据交换模式 */
typedef enum
{
    /** 无 */
    AES_SWAP_MODE_NONE = 0x0U,
    /** 2字节交换 */
    AES_SWAP_MODE_HALF_WORD,
    /** 1字节交换 */
    AES_SWAP_MODE_BYTE,
    /** 位交换 */
    AES_SWAP_MODE_BIT,
} Aes_DataSwap_t;
#define CHECK_AES_DATASWAP(x)                                                                                          \
    (((x) == AES_SWAP_MODE_NONE) || ((x) == AES_SWAP_MODE_BIT) || ((x) == AES_SWAP_MODE_HALF_WORD) ||                  \
     ((x) == AES_SWAP_MODE_BYTE))

/** AES工作时钟 */
typedef enum
{
    /** 主时钟源 */
    AES_CLK_SRC_SCLK = 0x0U,
    /** HFCLK时钟源 */
    AES_CLK_SRC_HFCLK,
    /** LFCLK时钟源 */
    AES_CLK_SRC_LFCLK,
} Aes_ClkSrc_t;
#define CHECK_AES_CLKSRC(x) (((x) == AES_CLK_SRC_SCLK) || ((x) == AES_CLK_SRC_HFCLK) || ((x) == AES_CLK_SRC_LFCLK))

/** AES工作时钟分频 */
typedef enum
{
    /** 不分频 */
    AES_CLK_SCALER_1 = 0x0U,
    AES_CLK_SCALER_2,
    AES_CLK_SCALER_4,
    AES_CLK_SCALER_8,
    AES_CLK_SCALER_16,
    AES_CLK_SCALER_32,
    AES_CLK_SCALER_64,
    /** 128分频 */
    AES_CLK_SCALER_128,

} Aes_ClkScaler_t;
#define CHECK_AES_CLKSCALER(x) (((x) >= AES_CLK_SCALER_1) && ((x) <= AES_CLK_SCALER_128))

/** AES密钥长度 */
typedef enum
{
    /** 128bit */
    AES_KEY_LEN_128 = 0x3U,
    /** 192bit */
    AES_KEY_LEN_192 = 0x5U,
    /** 256bit */
    AES_KEY_LEN_256 = 0x7U,
} Aes_KeyLen_t;
#define CHECK_AES_KEYLEN(x) (((x) == AES_KEY_LEN_128) || ((x) == AES_KEY_LEN_192) || ((x) == AES_KEY_LEN_256))

/** 密钥扩展轮数 */
#define CHECK_AES_KEY_EXPANSION_NUM(x) ((x) <= 31U)
/******************************************************************************
 *                      Export Variables
 ******************************************************************************/

/******************************************************************************
 *                      Export Functions
 ******************************************************************************/

/**
 * @brief: 设置AES使能位
 * @param Aesx 指向AES寄存器结构的指针
 * @param State
 *              true 使能
 *              false 禁止
 * @retval None
 */
KF_INLINE void Aes_LL_SetEnabled(Aes_RegisterMap_t *const Aesx, bool State)
{
    KF_AES_ASSERT(CHECK_AES_ALL_PERIPH_ADDR(Aesx));

    Aesx->CTL.bits.AESEN = State ? 1U : 0U;
}

/**
 * @brief: 设置算法自定义使能位
 * @param Aesx 指向AES寄存器结构的指针
 * @param State
 *              true AES采用自定义算法
 *              false AES采用标准算法
 * @retval None
 */
KF_INLINE void Aes_LL_SetUnStandardEnabled(Aes_RegisterMap_t *const Aesx, bool State)
{
    KF_AES_ASSERT(CHECK_AES_ALL_PERIPH_ADDR(Aesx));

    Aesx->CTL.bits.UNSTDAES = State ? 1U : 0U;
}

/**
 * @brief: 设置加密功能使能位
 * @param Aesx 指向AES寄存器结构的指针
 * @param State
 *              true 加密
 *              false 解密
 * @retval None
 */
KF_INLINE void Aes_LL_SetEncryptEnabled(Aes_RegisterMap_t *const Aesx, bool State)
{
    KF_AES_ASSERT(CHECK_AES_ALL_PERIPH_ADDR(Aesx));

    Aesx->CTL.bits.ENCRYPT = State ? 1U : 0U;
}

/**
 * @brief: 设置S盒子逆替换使能位,UNSTDAES置1时有效
 * @param Aesx 指向AES寄存器结构的指针
 * @param State
 *              true 正常替换
 *              false 逆替换
 * @retval None
 */
KF_INLINE void Aes_LL_SetSboxInversion(Aes_RegisterMap_t *const Aesx, bool State)
{
    KF_AES_ASSERT(CHECK_AES_ALL_PERIPH_ADDR(Aesx));

    Aesx->CTL.bits.SBOXINV = State ? 1U : 0U;
}

/**
 * @brief: 设置密钥长度选择位
 * @param Aesx 指向AES寄存器结构的指针
 * @param KeyLen 密钥长度
 *              b011 128bit
 *              b101 192bit
 *              b111 256bit
 * @retval None
 */
KF_INLINE void Aes_LL_SetKeyLength(Aes_RegisterMap_t *const Aesx, Aes_KeyLen_t KeyLen)
{
    KF_AES_ASSERT(CHECK_AES_ALL_PERIPH_ADDR(Aesx));
    KF_AES_ASSERT(CHECK_AES_KEYLEN(KeyLen));

    Aesx->CTL.bits.KEYLEN = (uint32_t)KeyLen;
}

/**
 * @brief: 设置密钥扩展轮数选择位,UNSTDAES置1时有效
 * @param Aesx 指向AES寄存器结构的指针
 * @param RoundNum 扩展轮数,可选范围为0~31
 * @retval None
 */
KF_INLINE void Aes_LL_SetRoundNumber(Aes_RegisterMap_t *const Aesx, uint8_t RoundNum)
{
    KF_AES_ASSERT(CHECK_AES_ALL_PERIPH_ADDR(Aesx));
    KF_AES_ASSERT(CHECK_AES_KEY_EXPANSION_NUM(RoundNum));

    Aesx->CTL.bits.RNDNUM = (uint32_t)RoundNum;
}

/**
 * @brief: 设置AES工作时钟分频选择位
 * @param Aesx 指向AES寄存器结构的指针
 * @param Div 时钟分频,可选范围为0~7
 * @retval None
 */
KF_INLINE void Aes_LL_SetClockDivision(Aes_RegisterMap_t *const Aesx, Aes_ClkScaler_t Div)
{
    KF_AES_ASSERT(CHECK_AES_ALL_PERIPH_ADDR(Aesx));
    KF_AES_ASSERT(CHECK_AES_CLKSCALER(Div));

    Aesx->CTL.bits.DIV = (uint32_t)Div;
}

/**
 * @brief: 设置工作时钟源选择寄存器
 * @param Aesx 指向AES寄存器结构的指针
 * @param ClkSrc 时钟源选择
 *              AES_CLK_SRC_SCKL: 主时钟源
 *              AES_CLK_SRC_HFCLK: HFCLK时钟源
 *              AES_CLK_SRC_LFCLK: LFCLK时钟源
 * @retval None
 */
KF_INLINE void Aes_LL_SetClockSource(Aes_RegisterMap_t *const Aesx, Aes_ClkSrc_t ClkSrc)
{
    KF_AES_ASSERT(CHECK_AES_ALL_PERIPH_ADDR(Aesx));
    KF_AES_ASSERT(CHECK_AES_CLKSRC(ClkSrc));

    Aesx->CTL.bits.CKS = (uint32_t)ClkSrc;
}

/**
 * @brief: 设置数据交换模式选择
 * @param Aesx 指向AES寄存器结构的指针
 * @param SwapMode 数据交换模式
 *              AES_SWAP_MODE_NONE: 无
 *              AES_SWAP_MODE_HALF_WORD: 2字节交换
 *              AES_SWAP_MODE_BYTE: 1字节交换
 *              AES_SWAP_MODE_BIT: 位交换
 * @retval None
 */
KF_INLINE void Aes_LL_SetDataSwapMode(Aes_RegisterMap_t *const Aesx, Aes_DataSwap_t SwapMode)
{
    KF_AES_ASSERT(CHECK_AES_ALL_PERIPH_ADDR(Aesx));
    KF_AES_ASSERT(CHECK_AES_DATASWAP(SwapMode));

    Aesx->CTL.bits.DATASWAP = (uint32_t)SwapMode;
}

/**
 * @brief: 设置链接模式选择
 * @param Aesx 指向AES寄存器结构的指针
 * @param LinkMode 链接模式
 *              AES_LINK_MODE_ECB: ECB模式
 *              AES_LINK_MODE_CTR: CTR模式
 *              AES_LINK_MODE_CBC_ENC: CBC_ENC模式
 *              AES_LINK_MODE_CBC_DEC: CBC_DEC模式
 *              AES_LINK_MODE_GMAC_ENC: GMAC_ENC模式
 *              AES_LINK_MODE_GMAC_DEC: GMAC_DEC模式
 *              AES_LINK_MODE_CCM_ENC: CCM_ENC模式
 *              AES_LINK_MODE_CCM_DEC: CCM_DEC模式
 * @retval None
 */
KF_INLINE void Aes_LL_SetLinkMode(Aes_RegisterMap_t *const Aesx, Aes_LinkMode_t LinkMode)
{
    KF_AES_ASSERT(CHECK_AES_ALL_PERIPH_ADDR(Aesx));
    KF_AES_ASSERT(CHECK_AES_LINKMODE(LinkMode));

    Aesx->CTL.bits.AESMOD = (uint32_t)LinkMode;
}

/**
 * @brief: 设置GCM或CCM阶段选择
 * @param Aesx 指向AES寄存器结构的指针
 * @param Value
 *              AES_GCMPH_INIT
 *              AES_GCMPH_HEADER
 *              AES_GCMPH_PAYLOAD
 *              AES_GCMPH_FINAL
 * @retval None
 */
KF_INLINE void Aes_LL_SetGcmCcmPhase(Aes_RegisterMap_t *const Aesx, Aes_Phase_t Value)
{
    KF_AES_ASSERT(CHECK_AES_ALL_PERIPH_ADDR(Aesx));
    KF_AES_ASSERT(CHECK_AES_PHASE(Value));

    Aesx->CTL.bits.GCMPH = (uint32_t)Value;
}

/**
 * @brief: 设置密钥扩展使能位
 * @param Aesx 指向AES寄存器结构的指针
 * @param State
 *              true
 *              false
 * @retval None
 */
KF_INLINE void Aes_LL_SetKeyExpansionEnabled(Aes_RegisterMap_t *const Aesx, bool State)
{
    KF_AES_ASSERT(CHECK_AES_ALL_PERIPH_ADDR(Aesx));

    Aesx->CTL.bits.KEYRUN = State ? 1U : 0U;
}

/**
 * @brief: 设置AES运行使能位
 * @param Aesx 指向AES寄存器结构的指针
 * @param State
 *              true
 *              false
 * @retval None
 */
KF_INLINE void Aes_LL_SetAesRunningEnabled(Aes_RegisterMap_t *const Aesx, bool State)
{
    KF_AES_ASSERT(CHECK_AES_ALL_PERIPH_ADDR(Aesx));

    Aesx->CTL.bits.AESRUN = State ? 1U : 0U;
}

/**
 * @brief: 设置AES加/解密完成中断使能位
 * @param Aesx 指向AES寄存器结构的指针
 * @param State
 *              true
 *              false
 * @retval None
 */
KF_INLINE void Aes_LL_SetAesJobFinishIntrEnabled(Aes_RegisterMap_t *const Aesx, bool State)
{
    KF_AES_ASSERT(CHECK_AES_ALL_PERIPH_ADDR(Aesx));

    Aesx->INT.bits.AESIE = State ? 1U : 0U;
}

/**
 * @brief: 设置AES密钥扩展完成中断使能位
 * @param Aesx 指向AES寄存器结构的指针
 * @param State
 *              true
 *              false
 * @retval None
 */
KF_INLINE void Aes_LL_SetKeyExpansionIntrEnabled(Aes_RegisterMap_t *const Aesx, bool State)
{
    KF_AES_ASSERT(CHECK_AES_ALL_PERIPH_ADDR(Aesx));

    Aesx->INT.bits.KEYIE = State ? 1U : 0U;
}

/**
 * @brief: 获取AES加/解密完成中断使能位
 * @param Aesx 指向AES寄存器结构的指针
 * @retval bool:
 *         true
 *         false
 */
KF_INLINE bool Aes_LL_GetAesJobFinishIntrEnabled(const Aes_RegisterMap_t *const Aesx)
{
    KF_AES_ASSERT(CHECK_AES_ALL_PERIPH_ADDR(Aesx));

    return (Aesx->INT.bits.AESIE != 0U);
}

/**
 * @brief: 获取AES密钥扩展完成中断使能位
 * @param Aesx 指向AES寄存器结构的指针
 * @retval bool:
 *         true
 *         false
 */
KF_INLINE bool Aes_LL_GetKeyExpansionIntrEnabled(const Aes_RegisterMap_t *const Aesx)
{
    KF_AES_ASSERT(CHECK_AES_ALL_PERIPH_ADDR(Aesx));

    return (Aesx->INT.bits.KEYIE != 0U);
}

/**
 * @brief: 获取AES加/解密完成中断标志位
 * @param Aesx 指向AES寄存器结构的指针
 * @retval bool:
 *         true
 *         false
 */
KF_INLINE bool Aes_LL_GetAesJobFinishIntrFlag(const Aes_RegisterMap_t *const Aesx)
{
    KF_AES_ASSERT(CHECK_AES_ALL_PERIPH_ADDR(Aesx));

    return (Aesx->INT.bits.AESIF != 0U);
}

/**
 * @brief: 设置AES加/解密完成中断清零位
 * @param Aesx 指向AES寄存器结构的指针
 * @retval None
 */
KF_INLINE void Aes_LL_ClearAesJobFinishIntrFlag(Aes_RegisterMap_t *const Aesx)
{
    KF_AES_ASSERT(CHECK_AES_ALL_PERIPH_ADDR(Aesx));
    uint32_t kvTimeCount = 0x1FFFFFu;

    Aesx->INT.bits.AESIC = 1U;
    while ((false != Aes_LL_GetAesJobFinishIntrFlag(Aesx)) && (kvTimeCount != 0U))
    {
        kvTimeCount -= 1U;
    }

    Aesx->INT.bits.AESIC = 0U;
}

/**
 * @brief: 获取AES密钥扩展完成中断标志位
 * @param Aesx 指向AES寄存器结构的指针
 * @retval bool:
 *         true
 *         false
 */
KF_INLINE bool Aes_LL_GetKeyExpansionIntrFlag(const Aes_RegisterMap_t *const Aesx)
{
    KF_AES_ASSERT(CHECK_AES_ALL_PERIPH_ADDR(Aesx));

    return (Aesx->INT.bits.KEYIF != 0U);
}

/**
 * @brief: 设置AES密钥扩展完成中断清零位
 * @param Aesx 指向AES寄存器结构的指针
 * @retval None
 */
KF_INLINE void Aes_LL_ClearKeyExpansionIntrFlag(Aes_RegisterMap_t *const Aesx)
{
    KF_AES_ASSERT(CHECK_AES_ALL_PERIPH_ADDR(Aesx));
    uint32_t kvTimeCount = 0x1FFFFFu;

    Aesx->INT.bits.KEYIC = 1U;
    while ((false != Aes_LL_GetKeyExpansionIntrFlag(Aesx)) && (kvTimeCount != 0U))
    {
        kvTimeCount -= 1U;
    }

    Aesx->INT.bits.KEYIC = 0U;
}

/**
 * @brief: 设置输入寄存器
 * @param Aesx 指向AES寄存器结构的指针
 * @param Offset 输入寄存器0-3
 * @param Value 要设置的值
 * @retval void
 */
KF_INLINE void Aes_LL_SetInputRegister(Aes_RegisterMap_t *const Aesx, uint8_t Offset, uint32_t Value)
{
    KF_AES_ASSERT(CHECK_AES_ALL_PERIPH_ADDR(Aesx));
    KF_AES_ASSERT(Offset < 4U);

    Aesx->INPUT[Offset] = (uint32_t)Value;
}

/**
 * @brief: 获取输出寄存器
 * @param Aesx 指向AES寄存器结构的指针
 * @param Offset 输出寄存器0-3
 * @retval uint32_t 输出寄存器0的值
 */
KF_INLINE uint32_t Aes_LL_GetOutputRegister(const Aes_RegisterMap_t *const Aesx, uint8_t Offset)
{
    KF_AES_ASSERT(CHECK_AES_ALL_PERIPH_ADDR(Aesx));
    KF_AES_ASSERT(Offset < 4U);

    return Aesx->OUTPUT[Offset];
}

/**
 * @brief: 设置输入密钥寄存器
 * @param Aesx 指向AES寄存器结构的指针
 * @param Offset 密钥寄存器0-7
 * @param Value 要设置的值
 * @retval void
 */
KF_INLINE void Aes_LL_SetInputKeyRegister(Aes_RegisterMap_t *const Aesx, uint8_t Offset, uint32_t Value)
{
    KF_AES_ASSERT(CHECK_AES_ALL_PERIPH_ADDR(Aesx));
    KF_AES_ASSERT(Offset < 8U);

    Aesx->KEYR[Offset] = (uint32_t)Value;
}

/**
 * @brief: 设置向量初始化寄存器
 * @param Aesx 指向AES寄存器结构的指针
 * @param Offset 向量寄存器0-3
 * @param Value 要设置的值
 * @retval void
 */
KF_INLINE void Aes_LL_SetInitializationVectorRegister(Aes_RegisterMap_t *const Aesx, uint8_t Offset, uint32_t Value)
{
    KF_AES_ASSERT(CHECK_AES_ALL_PERIPH_ADDR(Aesx));
    KF_AES_ASSERT(Offset < 4U);

    Aesx->IVR[Offset] = (uint32_t)Value;
}

/**
 * @brief: 挂起恢复过程中获取向量
 * @param Aesx 指向AES寄存器结构的指针
 * @param Addr 指向向量存储的地址
 * @retval none
 */
KF_INLINE void Aes_LL_GetInitializationVector(const Aes_RegisterMap_t *const Aesx, uint32_t *const Addr)
{
    KF_AES_ASSERT(CHECK_AES_ALL_PERIPH_ADDR(Aesx));

    Addr[0] = Aesx->IVR[3];
    Addr[1] = Aesx->IVR[2];
    Addr[2] = Aesx->IVR[1];
    Addr[3] = Aesx->IVR[0];
}

/**
 * @brief: 设置挂起寄存器
 * @param Aesx 指向AES寄存器结构的指针
 * @param Offset 挂起寄存器0-7
 * @param Value 要设置的值
 * @retval void
 */
KF_INLINE void Aes_LL_SetSuspendRegister(Aes_RegisterMap_t *const Aesx, uint8_t Offset, uint32_t Value)
{
    KF_AES_ASSERT(CHECK_AES_ALL_PERIPH_ADDR(Aesx));
    KF_AES_ASSERT(Offset < 8U);

    Aesx->SUSR[Offset] = (uint32_t)Value;
}

/**
 * @brief: 设置屏蔽寄存器
 * @param Aesx 指向AES寄存器结构的指针
 * @param Offset 挂起寄存器0-3
 * @param Value
 * @retval void
 */
KF_INLINE void Aes_LL_SetMaskRegister(Aes_RegisterMap_t *const Aesx, uint8_t Offset, uint32_t Value)
{
    KF_AES_ASSERT(CHECK_AES_ALL_PERIPH_ADDR(Aesx));
    KF_AES_ASSERT(Offset < 4U);

    Aesx->MASK[Offset] = (uint32_t)Value;
}

/**
 * @brief: 获取AES加/解密完成中断状态
 * @param Aesx 指向AES寄存器结构的指针
 * @retval bool 中断发生状态
 *         true    发生了中断，且已使能
 *         false    未发生中断，或未使能
 */
KF_INLINE bool Aes_LL_GetAesJobFinishIntrState(const Aes_RegisterMap_t *const Aesx)
{
    KF_AES_ASSERT(CHECK_AES_ALL_PERIPH_ADDR(Aesx));

    bool flag  = (Aesx->INT.bits.AESIF != 0U) ? true : false;
    bool state = (Aesx->INT.bits.AESIE != 0U) ? true : false;
    return flag && state;
}

/**
 * @brief: 获取AES密钥扩展完成中断状态
 * @param Aesx 指向AES寄存器结构的指针
 * @retval bool 中断发生状态
 *         true    发生了中断，且已使能
 *         false    未发生中断，或未使能
 */
KF_INLINE bool Aes_LL_GetKeyExpansionIntrState(const Aes_RegisterMap_t *const Aesx)
{
    KF_AES_ASSERT(CHECK_AES_ALL_PERIPH_ADDR(Aesx));

    bool flag  = (Aesx->INT.bits.KEYIF != 0U) ? true : false;
    bool state = (Aesx->INT.bits.KEYIE != 0U) ? true : false;
    return flag && state;
}

#ifdef __cplusplus
}
#endif /*End of __cplusplus*/
#endif /*End of KF32A158SF_DRV_AES_H*/
/* EOF */
