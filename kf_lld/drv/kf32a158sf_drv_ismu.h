/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name        : kf32a158sf_drv_ismu.h
 *  @Date             : 2025-07-07
 *  @Version          : {{VersionDate}}
 *  @Description      : This file provides ISMU driver.
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
#ifndef KF32A158SF_DRV_ISMU_H
#define KF32A158SF_DRV_ISMU_H

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
#include "kf32a158sf_reg_ismu.h"

/******************************************************************************
 *                      Macro or Inline
 ******************************************************************************/
#ifdef KF_DRV_ISMU_ASSERT
#include "dev_assert.h"
#define KF_ISMU_ASSERT(x) KF_DEV_ASSERT(x)
#else
#define KF_ISMU_ASSERT(x) ((void)0U)
#endif

/** @brief 安全存储状态寄存器位索引 */
#define ISMU_SS_SECFLSLOCK_INDEX (0U)

/******************************************************************************
 *                      Type definitions
 ******************************************************************************/

/* enum of ISMU command */
typedef enum
{
    ISMU_ENC_ECB        = 0x01U,
    ISMU_ENC_CBC        = 0x02U,
    ISMU_DEC_ECB        = 0x03U,
    ISMU_DEC_CBC        = 0x04U,
    ISMU_GENERATE_MAC   = 0x05U,
    ISMU_VERIFY_MAC     = 0x06U,
    ISMU_LOAD_KEY       = 0x07U,
    ISMU_LOAD_PLAIN_KEY = 0x08U,
    ISMU_EXPORT_RAM_KEY = 0x09U,
    ISMU_INIT_RNG       = 0x0AU,
    ISMU_EXTEND_SEED    = 0x0BU,
    ISMU_RNG            = 0x0CU,
    ISMU_SECURE_BOOT    = 0x0DU,
    ISMU_BOOT_FAILURE   = 0x0EU,
    ISMU_BOOT_OK        = 0x0FU,
    ISMU_GET_ID         = 0x10U,
    ISMU_CANCEL         = 0x11U,
    ISMU_DEBUG_CHAL     = 0x12U,
    ISMU_DEBUG_AUTH     = 0x13U,
    ISMU_INIT           = 0x15U,
    ISMU_VERIFY_SECFLS  = 0x16U
} Ismu_Cmd_t;
#define CHECK_ISMU_CMD(CMD) (((uint32_t)(CMD) <= (uint32_t)ISMU_VERIFY_SECFLS) && ((uint32_t)0x14U != (uint32_t)(CMD)))

/* enum of ISMU key */
typedef enum
{
    ISMU_SECRET_KEY,
    ISMU_MASTER_ECU_KEY,
    ISMU_BOOT_MAC_KEY,
    ISMU_BOOT_MAC,
    ISMU_KEY01,
    ISMU_KEY02,
    ISMU_KEY03,
    ISMU_KEY04,
    ISMU_KEY05,
    ISMU_KEY06,
    ISMU_KEY07,
    ISMU_KEY08,
    ISMU_KEY09,
    ISMU_KEY10,
    ISMU_KEY11,
    ISMU_RAM_KEY,
    ISMU_KEY_INDEX
} Ismu_Key_id_t;
#define CHECK_ISMU_KEY(KEY) ((uint32_t)(KEY) < (uint32_t)ISMU_KEY_INDEX)

/* enum of ISMU error code */
typedef enum
{
    ISMU_NO_ERR,
    ISMU_SEQUENCE_ERR,
    ISMU_KEY_NOT_AVAILABLE,
    ISMU_KEY_INVALID,
    ISMU_KEY_KEY_EMPTY,
    ISMU_SECURE_BOOT_FAILURE,
    ISMU_KEY_WRITE_PROTECTED,
    ISMU_KEY_UPDATE_ERR,
    ISMU_RNG_NOT_INIT,
    ISMU_AUTH_FAILURE,
    ISMU_BUSY,
    ISMU_MEM_FAILURE,
    ISMU_RNG_ERR,
    ISMU_PARAMETER_ERR,
    ISMU_UNINITIALIZED,
    ISMU_UNKOWN_ERR
} Ismu_Err_t;
#define CHECK_ISMU_ERR(ERR) ((uint32_t)(ERR) <= (uint32_t)ISMU_UNKOWN_ERR)

/******************************************************************************
 *                      Export Variables
 ******************************************************************************/

/******************************************************************************
 *                      Export Functions
 ******************************************************************************/

/**
 * @brief  获取ISMU指令执行状态
 *
 * @return bool 指令执行状态
 * @retval true -- 指令未完成执行
 * @retval false -- 指令完成执行
 */
KF_INLINE bool Ismu_LL_GetRunState(void)
{
    return ((0U != ISMU_PTR->STA.bits.BUSY) ? true : false);
}

/**
 * @brief  获取安全引导状态
 *
 * @return bool 安全引导状态
 * @retval true -- 安全引导被激活
 * @retval false -- 安全引导未被激活
 */
KF_INLINE bool Ismu_LL_GetSecureBootState(void)
{
    return ((0U != ISMU_PTR->STA.bits.BSTA) ? true : false);
}

/**
 * @brief  获取安全引导初始化状态
 *
 * @return bool 安全引导初始化状态
 * @retval true -- 安全引导初始化已完成
 * @retval false -- 安全引导初始化未完成
 */
KF_INLINE bool Ismu_LL_GetSecureBootInitialState(void)
{
    return ((0U != ISMU_PTR->STA.bits.BINIT) ? true : false);
}

/**
 * @brief  获取安全引导完成状态
 *
 * @return bool 安全引导完成状态
 * @retval true -- 安全引导已完成
 * @retval false -- 安全引导未完成
 */
KF_INLINE bool Ismu_LL_GetSecureBootFinishState(void)
{
    return ((0U != ISMU_PTR->STA.bits.BFN) ? true : false);
}

/**
 * @brief  获取安全启动OK状态
 *
 * @return bool 安全启动OK状态
 * @retval true -- 安全启动成功
 * @retval false -- 安全启动失败
 */
KF_INLINE bool Ismu_LL_GetSecureBootOkState(void)
{
    return ((0U != ISMU_PTR->STA.bits.BOK) ? true : false);
}

/**
 * @brief  获取随机数生成器初始化状态
 *
 * @return bool 随机数生成器初始化状态
 * @retval true -- 随机数生成器已初始化
 * @retval false -- 随机数生成器未初始化
 */
KF_INLINE bool Ismu_LL_GetRngInitialState(void)
{
    return ((0U != ISMU_PTR->STA.bits.RNGINIT) ? true : false);
}

/**
 * @brief  获取外部 debug 功能工作状态位
 *
 * @return bool 外部 debug 功能工作状态位
 * @retval true -- 内部 debugger 已连接
 * @retval false -- 外部 debugger 未连接
 */
KF_INLINE bool Ismu_LL_GetExternalDebugState(void)
{
    return ((0U != ISMU_PTR->STA.bits.EDB) ? true : false);
}

/**
 * @brief  获取内部 debug 功能工作状态
 *
 * @return bool 内部 debug 功能工作状态
 * @retval true -- 内部 debug 功能被使能
 * @retval false -- 内部 debug 功能未使能
 */
KF_INLINE bool Ismu_LL_GetInternalDebugState(void)
{
    return ((0U != ISMU_PTR->STA.bits.IDB) ? true : false);
}

/**
 * @brief  获取 ISMU 初始化完成状态
 *
 * @return bool ISMU初始化完成状态
 * @retval true -- ISMU 初始化已完成
 * @retval false -- ISMU 初始化未完成
 */
KF_INLINE bool Ismu_LL_GetIsmuInitialState(void)
{
    return ((0U != ISMU_PTR->STA.bits.INITFIN) ? true : false);
}

/**
 * @brief  获取调试准备完成状态
 *
 * @return bool 调试准备完成状态
 * @retval true -- 调试随机码已生成
 * @retval false -- 调试随机码未生成
 */
KF_INLINE bool Ismu_LL_GetDebugReadyState(void)
{
    return ((0U != ISMU_PTR->STA.bits.DEBCHAFIN) ? true : false);
}

/**
 * @brief 设置ISMU中断使能位
 * @param State
 *        true
 *        false
 * @retval void
 */
KF_INLINE void Ismu_LL_SetIntrEnabled(bool State)
{
    ISMU_PTR->INT.bits.CMDIE = State ? 1U : 0U;
}

/**
 * @brief 清零ISMU中断标志
 *
 * @return void
 */
KF_INLINE void Ismu_LL_ClearIntrFlag(void)
{
    ISMU_PTR->INT.bits.CMDIC = BIT_SET;
    NOP();
    NOP();
    NOP();
    NOP();
    ISMU_PTR->INT.bits.CMDIC = BIT_CLR;
}

/**
 * @brief 获取ISMU中断标志
 *
 * @return bool ISMU中断标志
 * @retval true
 * @retval false
 */
KF_INLINE bool Ismu_LL_GetIntrFlag(void)
{
    return ((0U != ISMU_PTR->INT.bits.CMDIF) ? true : false);
}

/**
 * @brief 获取ISMU安全存储密钥状态
 *
 * @return bool ISMU安全存储密钥状态
 * @retval true -- 安全存储密钥为空
 * @retval false -- 安全存储密钥非空
 */
KF_INLINE bool Ismu_LL_GetSecureMemoryKeyEmptyState(void)
{
    return ((0U != ISMU_PTR->SS.bits.KEYEMP) ? true : false);
}

/**
 * @brief 获取ISMU安全存储上锁状态
 *
 * @return bool ISMU安全存储上锁状态
 * @retval true -- 安全存储区为上锁状态
 * @retval false -- 安全存储区为解锁状态
 */
KF_INLINE bool Ismu_LL_GetSecureMemoryLockState(void)
{
    return ((0U != ISMU_PTR->SS.bits.SECFLSLOCK) ? true : false);
}

/**
 * @brief 清除ISMU安全存储上锁状态
 *
 * @return void
 */
KF_INLINE void Ismu_LL_ClearSecureMemoryLockState(void)
{
    KF_SET_BIT(ISMU_PTR->SS.reg, ISMU_SS_SECFLSLOCK_INDEX);
}

#ifdef __cplusplus
}
#endif /*End of __cplusplus*/
#endif /*End of KF32A158SF_DRV_ISMU_H*/
/* EOF */
