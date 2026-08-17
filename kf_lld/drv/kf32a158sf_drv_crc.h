/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name        : kf32a158sf_drv_crc.h
 *  @Date             : 2025-07-09
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
 *  |2025-07-09  |V1.0     |AE Group     |New create
 ******************************************************************************/
#ifndef KF32A158SF_DRV_CRC_H
#define KF32A158SF_DRV_CRC_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 *                      QAC Warnings
 ******************************************************************************/
/* PRQA S 0288 EOF #KQR000288 */
/* PRQA S 3205 EOF #KQR003205 */
/* PRQA S 3219 EOF #KQR003219 */
/* PRQA S 4342 EOF #KQR004342 */

/******************************************************************************
 *                      Include Files
 ******************************************************************************/
#include <stdint.h>
#include <stdbool.h>
#include "kf_types.h"
#include "dev_assert.h"
#include "kf32a158sf_reg_crc.h"

#ifdef KF_DRV_CRC_ASSERT
#include "dev_assert.h"
#define KF_CRC_ASSERT(x) KF_DEV_ASSERT(x)
#else
#define KF_CRC_ASSERT(x) ((void)0U)
#endif

/******************************************************************************
 *                      Macro or Inline
 ******************************************************************************/

/******************************************************************************
 *                      Type definitions
 ******************************************************************************/

/**
 * CRC reverse control bit
 */

typedef enum
{
    CRC_REVERSE_CTRL_NONE = 0,
    CRC_REVERSE_CTRL_WORD,
    CRC_REVERSE_CTRL_BYTE,
} Crc_ReverseCtrl_t;
#define CHECK_CRC_REVERSE_CTRL(x)                                                                                      \
    (((x) == CRC_REVERSE_CTRL_NONE) || ((x) == CRC_REVERSE_CTRL_WORD) || ((x) == CRC_REVERSE_CTRL_BYTE))

/**
 * CRC inputdata format reverse control bit
 */
typedef enum
{
    CRC_FORMAT_CONTROL_BIT8,
    CRC_FORMAT_CONTROL_BIT16,
    CRC_FORMAT_CONTROL_REV,
    CRC_FORMAT_CONTROL_BIT32,
} Crc_FormatControl_t;
#define CHECK_CRC_FORMATCONTROL(x)                                                                                     \
    (((x) == CRC_FORMAT_CONTROL_BIT8) || ((x) == CRC_FORMAT_CONTROL_BIT16) || ((x) == CRC_FORMAT_CONTROL_REV) ||       \
     ((x) == CRC_FORMAT_CONTROL_BIT32))

/**
 * CRC calculate unit reset control bit
 * TODO: Remove this
 */
typedef enum
{
    CRC_CALRESET_DISABLE,
    CRC_CALRESET_ENABLE,
} Crc_RsetCtrl_t;
#define CHECK_CRC_RESETCTRL(x) (((x) == CRC_CALRESET_DISABLE) || ((x) == CRC_CALRESET_ENABLE))

/******************************************************************************
 *                      Export Variables
 ******************************************************************************/

/******************************************************************************
 *                      Export Functions
 ******************************************************************************/

/**
 * @brief 配置CRC_CTL控制寄存器的输入数据格式控制位
 * @param Module 指向CRC内存结构的指针
 * @param CtrlBit 设置输入数据格式
 * @retval 无
 */
KF_INLINE void Crc_LL_SetDataFormat(Crc_RegisterMap_t *const Module, Crc_FormatControl_t CtrlBit)
{
    KF_CRC_ASSERT(CHECK_CRC_ALL_PERIPH_ADDR(Module));
    KF_CRC_ASSERT(CHECK_CRC_FORMATCONTROL(CtrlBit));

    Module->CTL.bits.DATASIZE = (uint32_t)CtrlBit;
}

/**
 * @brief 配置CRC_CTL控制寄存器的计算单元复位控制位
 * @param Module 指向CRC内存结构的指针
 * @param Bitset 指定外设复位功能位,取值为0表示无作用,取值为1表示复位状态
 * @retval 无
 */
KF_INLINE void Crc_LL_SetResetState(Crc_RegisterMap_t *const Module, Crc_RsetCtrl_t Bitset)

{
    KF_CRC_ASSERT(CHECK_CRC_ALL_PERIPH_ADDR(Module));
    KF_CRC_ASSERT(CHECK_CRC_RESETCTRL(Bitset));

    Module->CTL.bits.RSET = (uint32_t)Bitset;
}

/**
 * @brief 重启CRC计算单元
 *
 * @param Module 指向CRC内存结构的指针
 * @retval void
 */
KF_INLINE void Crc_LL_Restart(Crc_RegisterMap_t *Module)
{
    Module->CTL.bits.RSET = 0x01U;
}

/**
 * @brief 配置CRC_CTL控制寄存器的结果位反序控制位
 * @param Module 指向CRC内存结构的指针
 * @param Select 对CRC结果进行位反序控制
 * @retval 无
 */
KF_INLINE void Crc_LL_SetResultReverseCtrl(Crc_RegisterMap_t *const Module, Crc_ReverseCtrl_t Select)
{
    KF_CRC_ASSERT(CHECK_CRC_ALL_PERIPH_ADDR(Module));
    KF_CRC_ASSERT(CHECK_CRC_REVERSE_CTRL(Select));

    Module->CTL.bits.DATAOUTSWAP = (uint32_t)Select;
}

/**
 * @brief 配置CRC_CTL控制寄存器的计算单元复位控制位
 * @param Module 指向CRC内存结构的指针
 * @param Set 对CRC输入数据位进行反序控制
 * @retval 无
 */
KF_INLINE void Crc_LL_InputDataReverseCtrl(Crc_RegisterMap_t *const Module, Crc_ReverseCtrl_t Set)
{
    KF_CRC_ASSERT(CHECK_CRC_ALL_PERIPH_ADDR(Module));
    KF_CRC_ASSERT(CHECK_CRC_REVERSE_CTRL(Set));

    Module->CTL.bits.DATAINSWAP = (uint32_t)Set;
}

/**
 * @brief: 设置crc输入数据
 * @param Module 指向CRC内存结构的指针
 * @param Data 数据
 * @retval void
 */
KF_INLINE void Crc_LL_SetData(Crc_RegisterMap_t *const Module, uint32_t Data)
{
    KF_CRC_ASSERT(CHECK_CRC_ALL_PERIPH_ADDR(Module));

    Module->DATA = Data;
}

/**
 * @brief: 获取crc计算结果
 * @param Module 指向CRC内存结构的指针
 * @retval uint32_t 结果值
 */
KF_INLINE uint32_t Crc_LL_GetResult(const Crc_RegisterMap_t *const Module)
{
    KF_CRC_ASSERT(CHECK_CRC_ALL_PERIPH_ADDR(Module));

    return Module->RSLT;
}

/**
 * @brief 设置CRC初始值
 *
 * @param Module 指向CRC内存结构的指针
 * @param Val 初始值
 * @retval void
 */
KF_INLINE void Crc_LL_SetInitialVal(Crc_RegisterMap_t *const Module, uint32_t Val)
{
    KF_CRC_ASSERT(CHECK_CRC_ALL_PERIPH_ADDR(Module));

    Module->INIT = Val;
}

/**
 * @brief 设置CRC多项式
 *
 * @param Module 指向CRC内存结构的指针
 * @param Polynomial 多项式
 * @retval void
 */
KF_INLINE void Crc_LL_SetPolynomial(Crc_RegisterMap_t *const Module, uint32_t Polynomial)
{
    KF_CRC_ASSERT(CHECK_CRC_ALL_PERIPH_ADDR(Module));

    Module->PLN = Polynomial;
}

/**
 * @brief 设置CRC结果异或值
 *
 * @param Module 指向CRC内存结构的指针
 * @param Val 结果异或值
 * @retval void
 */
KF_INLINE void Crc_LL_SetResultXorVal(Crc_RegisterMap_t *const Module, uint32_t Val)
{
    KF_CRC_ASSERT(CHECK_CRC_ALL_PERIPH_ADDR(Module));

    Module->RXOR = Val;
}

/**
 * @brief 设置CRC独立数据寄存器
 *              该寄存器可用于临时存放 32 位的数据. CRC_CTL寄存器中的 RSET 位的复位不会影响该寄存器的值.
 *
 * @param Module 指向CRC内存结构的指针
 * @param Val 独立数据值
 * @retval void
 */
KF_INLINE void Crc_LL_SetIndependentData(Crc_RegisterMap_t *const Module, uint32_t Val)
{
    KF_CRC_ASSERT(CHECK_CRC_ALL_PERIPH_ADDR(Module));

    Module->IDATA = Val;
}

/**
 * @brief 获取CRC独立数据寄存器
 *
 * @param Module 指向CRC内存结构的指针
 * @retval uint32_t 独立数据寄存器值
 */
KF_INLINE uint32_t Crc_LL_GetIndependentData(const Crc_RegisterMap_t *const Module)
{
    KF_CRC_ASSERT(CHECK_CRC_ALL_PERIPH_ADDR(Module));

    return Module->IDATA;
}

/**
 * @brief 读取CRC缓存寄存器
 *
 * @param Module 指向CRC内存结构的指针
 * @retval uint32_t 缓存寄存器数据
 */
KF_INLINE uint32_t Crc_LL_GetTempData(const Crc_RegisterMap_t *const Module)
{
    KF_CRC_ASSERT(CHECK_CRC_ALL_PERIPH_ADDR(Module));

    return Module->TEMP;
}

/**
 * @brief 获取CRC输出反序状态
 *
 * @param Module
 * @retval Crc_ReverseCtrl_t
 */
KF_INLINE Crc_ReverseCtrl_t Crc_LL_GetResultReverseCtrl(const Crc_RegisterMap_t *const Module)
{
    KF_CRC_ASSERT(CHECK_CRC_ALL_PERIPH_ADDR(Module));

    return (Crc_ReverseCtrl_t)(Module->CTL.bits.DATAOUTSWAP);
}

/**
 * @brief 获取CRC字节格式状态
 *
 * @param Module
 * @retval Crc_FormatControl_t
 */
KF_INLINE Crc_FormatControl_t Crc_LL_GetFormatBits(const Crc_RegisterMap_t *const Module)
{
    KF_CRC_ASSERT(CHECK_CRC_ALL_PERIPH_ADDR(Module));

    return (Crc_FormatControl_t)(Module->CTL.bits.DATASIZE);
}

#ifdef __cplusplus
}
#endif /*End of __cplusplus*/
#endif /*End of KF32A158SF_DRV_CRC_H*/
/* EOF */
