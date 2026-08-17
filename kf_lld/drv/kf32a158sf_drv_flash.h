/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name        : kf32a158sf_drv_flash.h
 *  @Date             : 2025-07-07
 *  @Version          : {{VersionDate}}
 *  @Description      : This file provides flash driver.
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
#ifndef KF32A158SF_DRV_FLASH_H
#define KF32A158SF_DRV_FLASH_H

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
#include "kf32a158sf_reg_flash.h"

/******************************************************************************
 *                      Macro or Inline
 ******************************************************************************/
#ifdef KF_DRV_FLASH_ASSERT
#include "dev_assert.h"
#define KF_FLASH_ASSERT(x) KF_DEV_ASSERT(x)
#else
#define KF_FLASH_ASSERT(x) ((void)0U)
#endif

/******************************************************************************
 *                      Type definitions
 ******************************************************************************/
/** @brief FLASH校验和结果寄存器*/
typedef enum
{
    /**校验和结果寄存器0*/
    FLASH_CHECKSUM_RESULT_REG0,
    /**校验和结果寄存器1*/
    FLASH_CHECKSUM_RESULT_REG1,
    /**校验和结果寄存器2*/
    FLASH_CHECKSUM_RESULT_REG2,
    /**校验和结果寄存器3*/
    FLASH_CHECKSUM_RESULT_REG3
} Flash_CheckSumResultReg_t;
/** @brief 检查FLASH校验和结果寄存器*/
#define CHECK_FLASH_REG(REG) ((uint32_t)(REG) <= (uint32_t)FLASH_CHECKSUM_RESULT_REG3)

/******************************************************************************
 *                      Export Variables
 ******************************************************************************/

/******************************************************************************
 *                      Export Functions
 ******************************************************************************/

/**
 * @brief 设置 FLASH_CFG 寄存器
 * @param Value 寄存器值
 * @return void
 */
KF_INLINE void Flash_LL_SetFlashConfig(uint32_t Value)
{
    FLASH_PTR->CFG.reg = Value;
}

/**
 * @brief 设置FLASH访问周期
 *
 * @param AccessCycle 访问周期
 *        0000 = 1 个系统周期
 *        0001 = 2 个系统周期
 *        ...
 *        1110 = 15 个系统周期
 *        1111 = 16 个系统周期
 * @return void
 */
KF_INLINE void Flash_LL_SetAccessCycle(uint8_t AccessCycle)
{
    KF_FLASH_ASSERT(AccessCycle <= 0x0FU);

    FLASH_PTR->CFG.bits.TCFG = AccessCycle;
}

/**
 * @brief 设置FLASH访问周期
 *
 * @param AccessCycle 访问周期
 *        0000 = 1 个系统周期
 *        0001 = 2 个系统周期
 *        ...
 *        1110 = 15 个系统周期
 *        1111 = 16 个系统周期
 * @return void
 */
KF_INLINE uint32_t Flash_LL_GetAccessCycle(void)
{
    return FLASH_PTR->CFG.bits.TCFG;
}

/**
 * @brief 使能线性预取
 *
 * @return void
 */
KF_INLINE void Flash_LL_EnableLinearPrefetch(void)
{
    FLASH_PTR->CFG.bits.PREFETCHEN = 1U;
}

/**
 * @brief 关闭线性预取
 *
 * @return void
 */
KF_INLINE void Flash_LL_DisableLinearPrefetch(void)
{
    FLASH_PTR->CFG.bits.PREFETCHEN = 0U;
}

/**
 * @brief 获取线性预取标志
 *
 * @return bool 线性预取标志位
 * @retval true --  打开状态
 * @retval false --  关闭状态
 */
KF_INLINE bool Flash_LL_GetLinearPrefetchState(void)
{
    return (FLASH_PTR->CFG.bits.PREFETCHEN != 0U);
}

/**
 * @brief 使能ECC校验
 *
 * @return void
 */
KF_INLINE void Flash_LL_EnableECCCheck(void)
{
    FLASH_PTR->CFG.bits.ECCREADEN = 1U;
}

/**
 * @brief 关闭ECC校验
 *
 * @return void
 */
KF_INLINE void Flash_LL_DisableECCCheck(void)
{
    FLASH_PTR->CFG.bits.ECCREADEN = 0U;
}

/**
 * @brief 获取校验和计算完成状态
 *
 * @return bool 校验和计算完成状态位
 * @retval true --  计算完成
 * @retval false --  未计算或者计算中
 */
KF_INLINE bool Flash_LL_GetCheckSumState(void)
{
    return (FLASH_PTR->STATE.bits.SIGDONE != 0U);
}

/**
 * @brief 清除校验和计算完成状态位
 *
 * @return void
 */
KF_INLINE void Flash_LL_ClearCheckSumStatus(void)
{
    FLASH_PTR->STATE.bits.SIGDONE = 1U;
    NOP();
    NOP();
    NOP();
    NOP();
    FLASH_PTR->STATE.bits.SIGDONE = 0U;
}

/**
 * @brief 设置FLASH检验和起始地址
 *
 * @param StartAddr 校验和起始地址
 * @return void
 */
KF_INLINE void Flash_LL_SetCheckSumStartAddr(uint32_t StartAddr)
{
    KF_FLASH_ASSERT(StartAddr <= 0x1FFFFU);

    FLASH_PTR->CSSTART.bits.CKSTADDR = StartAddr >> 4U;
}

/**
 * @brief 设置FLASH检验和结束地址
 *
 * @param StopAddr 校验和结束地址
 * @return void
 */
KF_INLINE void Flash_LL_SetCheckSumStopAddr(uint32_t StopAddr)
{
    KF_FLASH_ASSERT(StopAddr <= 0x1FFFFU);

    FLASH_PTR->CSSTOP.bits.CKSPADDR = StopAddr >> 4U;
}

/**
 * @brief 使能FLASH检验和计算
 *
 * @return void
 */
KF_INLINE void Flash_LL_EnableCheckSum(void)
{
    FLASH_PTR->CSSTOP.bits.SIGGO = 1U;
}

/**
 * @brief 关闭FLASH检验和计算
 *
 * @return void
 */
KF_INLINE void Flash_LL_DisableCheckSum(void)
{
    FLASH_PTR->CSSTOP.bits.SIGGO = 0U;
}

/**
 * @brief 获取FLASH校验和结果寄存器
 *
 * @param ResultNum 结果寄存器序号
 *        FLASH_CHECKSUM_RESULT_REG0 -- 校验和结果寄存器0
 *        FLASH_CHECKSUM_RESULT_REG1 -- 校验和结果寄存器1
 *        FLASH_CHECKSUM_RESULT_REG2 -- 校验和结果寄存器2
 *        FLASH_CHECKSUM_RESULT_REG3 -- 校验和结果寄存器3
 * @return uint32_t 校验和结果
 */
KF_INLINE uint32_t Flash_LL_GetCheckSumResult(Flash_CheckSumResultReg_t ResultNum)
{
    uint32_t const *kpTmpReg = NULL;
    KF_FLASH_ASSERT(CHECK_FLASH_REG(ResultNum));

    kpTmpReg = (uint32_t const *)(((uint32_t)&FLASH_PTR->CSRES0) + ((uint32_t)4U * (uint32_t)ResultNum));

    return *kpTmpReg;
}

/**
 * @brief 获取当前分区区域
 *
 * @param void
 * @return uint32_t 当前分区区域 0-A区 1-B区
 */
KF_INLINE uint32_t Flash_LL_GetBankArea(void)
{
    return FLASH_REDUNDANT_PTR->SWCTL.bits.FBSWS;
}

/**
 * @brief 解锁FLASH冗余寄存器访问权限
 *
 * @return void
 */
KF_INLINE void Flash_LL_UnlockRedundantReg(void)
{
    FLASH_REDUNDANT_PTR->FRMKEY = 0x8272C2A2U;
    FLASH_REDUNDANT_PTR->FRMKEY = 0x3635343EU;
}

/**
 * @brief 锁定FLASH冗余寄存器访问权限
 *
 * @return void
 */
KF_INLINE void Flash_LL_LockRedundantReg(void)
{
    FLASH_REDUNDANT_PTR->FRMLOCK = 0xBA540001U;
}

/**
 * @brief FLASH编程时使能CPU运行程序
 *
 * @return void
 */
KF_INLINE void Flash_LL_EnableReadWhileWrite(void)
{
    uint32_t temp = FLASH_REDUNDANT_PTR->FRMCTL.reg;
    temp &= 0x0000FFFFU;
    temp |= 0x00000100U;
    FLASH_REDUNDANT_PTR->FRMCTL.reg = 0x13CE0000U | temp;
}

/**
 * @brief FLASH编程时静止CPU运行程序
 *
 * @return void
 */
KF_INLINE void Flash_LL_DisableReadWhileWrite(void)
{
    uint32_t temp = FLASH_REDUNDANT_PTR->FRMCTL.reg;
    temp &= 0x0000FFFFU;
    temp &= ~0x00000100U;
    FLASH_REDUNDANT_PTR->FRMCTL.reg = 0x13CE0000U | temp;
}

#ifdef __cplusplus
}
#endif /*End of __cplusplus*/
#endif /*End of KF32A158SF_DRV_FLASH_H*/
/* EOF */
