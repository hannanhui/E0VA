/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name        : kf32a158sf_drv_mpu.h
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
#ifndef KF32A158SF_DRV_MPU_H
#define KF32A158SF_DRV_MPU_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 *                      QAC Warnings
 ******************************************************************************/
/* PRQA S 0288 EOF #KQR000288 */
/* PRQA S 0303,0306 EOF #KQR100303 */
/* PRQA S 0306 EOF #KQR000306 */
/* PRQA S 1006,3006 EOF #KQR101006 */
/* PRQA S 3205 EOF #KQR003205 */
/* PRQA S 3219 EOF #KQR003219 */
/* PRQA S 3473 EOF #KQR003473 */
/* PRQA S 4342 EOF #KQR004342 */

/******************************************************************************
 *                      Include Files
 ******************************************************************************/
#include <stdint.h>
#include <stdbool.h>
#include "kf_types.h"
#include "kf32a158sf_reg_mpu.h"

#ifdef KF_DRV_MPU_ASSERT
#include "dev_assert.h"
#define KF_MPU_ASSERT(x) KF_DEV_ASSERT(x)
#else
#define KF_MPU_ASSERT(x) ((void)0U)
#endif

/******************************************************************************
 *                      Macro or Inline
 ******************************************************************************/

/******************************************************************************
 *                      Type definitions
 ******************************************************************************/

/**从端口序号*/
typedef enum
{
    /**从端口0*/
    MPU_INDEX_SLAVE_0,
    /**从端口1*/
    MPU_INDEX_SLAVE_1,
    /**从端口2*/
    MPU_INDEX_SLAVE_2,
    /**从端口3*/
    MPU_INDEX_SLAVE_3,
} Mpu_Slave_t, Mpu_Interrupt_t;
/**检查从端口序号*/
#define CHECK_MPU_SLAVE_INDEX(SLV) ((uint32_t)(SLV) <= (uint32_t)MPU_SLAVE_3)

/**主机编号*/
typedef enum
{
    /**Master 0(Core)*/
    MPU_MASTER_0    = 0x0U,
    MPU_MASTER_CORE = 0x0U,
    /**Master 1(Debugger)*/
    MPU_MASTER_1        = 0x1U,
    MPU_MASTER_DEBUGGER = 0x1U,
    /**Master 2(DMA)*/
    MPU_MASTER_2   = 0x2U,
    MPU_MASTER_DMA = 0x2U,
} Mpu_Master_t;
/**检查主机编号*/
#define CHECK_MPU_MASTER(MASTER)         ((uint32_t)(MASTER) <= (uint32_t)MPU_MASTER_2)
#define CHECK_MPU_MASTER_FOR_PID(MASTER) ((uint32_t)(MASTER) <= (uint32_t)MPU_MASTER_1)

/**MPU范围*/
typedef enum
{
    /**范围0*/
    MPU_REGION_0,
    /**范围1*/
    MPU_REGION_1,
    /**范围2*/
    MPU_REGION_2,
    /**范围3*/
    MPU_REGION_3,
    /**范围4*/
    MPU_REGION_4,
    /**范围5*/
    MPU_REGION_5,
    /**范围6*/
    MPU_REGION_6,
    /**范围7*/
    MPU_REGION_7,
    /**范围8*/
    MPU_REGION_8,
    /**范围9*/
    MPU_REGION_9,
    /**范围10*/
    MPU_REGION_10,
    /**范围11*/
    MPU_REGION_11,
    /**范围12*/
    MPU_REGION_12,
    /**范围13*/
    MPU_REGION_13,
    /**范围14*/
    MPU_REGION_14,
    /**范围15*/
    MPU_REGION_15,
} Mpu_Region_t;
/**检查范围序号*/
#define CHECK_MPU_REGION(SEL) ((uint32_t)(SEL) <= (uint32_t)MPU_REGION_15)

/**检查内存起始地址*/
#define CHECK_MPU_START_ADDR(ADDR) (((uint32_t)(ADDR) & 0x1FU) == 0U)
/**检查内存终止地址*/
#define CHECK_MPU_END_ADDR(ADDR) (((uint32_t)(ADDR) & 0x1FU) == 0x1FU)

/**超级用户访问权限*/
typedef enum
{
    /**读/写/运行(r/w/x)允许*/
    MPU_ACCESS_SU_RWX,
    /**读/运行(r/x)允许,写(w)不允许*/
    MPU_ACCESS_SU_RX,
    /**读/写(r/w)允许,运行(x)不允许*/
    MPU_ACCESS_SU_RW,
    /**由普通用户模式定义*/
    MPU_ACCESS_SU_SAMETONORMAL,
} Mpu_SuAccess_t;
/**检查超级用户访问权限*/
#define CHECK_MPU_SU_ACCESS(SEL) ((uint32_t)(SEL) <= (uint32_t)MPU_ACCESS_SU_SAMETONORMAL)

/**普通用户访问权限*/
typedef enum
{
    /**无权限*/
    MPU_ACCESS_NORMAL_NONE,
    /**仅可执行权限*/
    MPU_ACCESS_NORMAL_X,
    /**仅可写权限*/
    MPU_ACCESS_NORMAL_W,
    /**写,执行权限*/
    MPU_ACCESS_NORMAL_WX,
    /**仅可读权限*/
    MPU_ACCESS_NORMAL_R,
    /**读,可执行权限*/
    MPU_ACCESS_NORMAL_RX,
    /**读,写权限*/
    MPU_ACCESS_NORMAL_RW,
    /**读,写,可执行权限*/
    MPU_ACCESS_NORMAL_RWX,
} Mpu_NormalAccess_t;
/**检查普通用户访问权限*/
#define CHECK_MPU_NORMAL_ACCESS(SEL) ((uint32_t)(SEL) <= (uint32_t)MPU_ACCESS_NORMAL_RWX)
/******************************************************************************
 *                      Export Variables
 ******************************************************************************/

/******************************************************************************
 *                      Export Functions
 ******************************************************************************/

/**
 * @brief 设置MPU使能状态
 *
 * @param EnableStatus 使能状态 \n
 *                  true -- 使能MPU \n
 *                  false -- 不使能MPU
 * @retval void
 */
KF_INLINE void Mpu_LL_SetEnabled(bool EnableStatus)
{
    MPU_PTR->CTLESR.bits.MPUEN = (EnableStatus ? 1U : 0U);
}

/**
 * @brief 获取从端口错误中断标志
 *
 * @param SlaveIndex 从端口序号 \n
 *                  MPU_INDEX_SLAVE_0 -- 从端口0 \n
 *                  MPU_INDEX_SLAVE_1 -- 从端口1 \n
 *                  MPU_INDEX_SLAVE_2 -- 从端口2 \n
 *                  MPU_INDEX_SLAVE_3 -- 从端口3
 * @retval void
 */
KF_INLINE bool Mpu_LL_GetSlaveErrorFlag(Mpu_Slave_t SlaveIndex)
{
    uint32_t Mask;

    KF_MPU_ASSERT(CHECK_MPU_SLAVE_INDEX(SlaveIndex));

    Mask = (uint32_t)SlaveIndex + 20U;
    /* PRQA S 3469 1 #KQR003469 */
    return (REG_BITS_READ(MPU_PTR->CTLESR.reg, 0x1UL << Mask, Mask) != 0U);
}

/**
 * @brief 清除从端口错误中断标志
 *
 * @param IntIndex 从端口序号 \n
 *                  MPU_INDEX_SLAVE_0 -- 从端口0 \n
 *                  MPU_INDEX_SLAVE_1 -- 从端口1 \n
 *                  MPU_INDEX_SLAVE_2 -- 从端口2 \n
 *                  MPU_INDEX_SLAVE_3 -- 从端口3
 * @retval void
 */
KF_INLINE void Mpu_LL_ClearIntrFlag(Mpu_Interrupt_t IntIndex)
{
    uint32_t Mask;

    KF_MPU_ASSERT(CHECK_MPU_SLAVE_INDEX(IntIndex));

    Mask = (uint32_t)IntIndex + 16U;
    REG_BIT_SET(MPU_PTR->IER.reg, 0x1UL << Mask);
    NOP();
    NOP();
    NOP();
    NOP();
    REG_BIT_CLR(MPU_PTR->IER.reg, 0x1UL << Mask);
}

/**
 * @brief 设置MPU的ID(用于处理编号比较)
 *
 * @param MpuId MPU ID \n
 *                  0x0 ~ 0xff
 * @retval void
 */
KF_INLINE void Mpu_LL_WriteMpuId(uint8_t MpuId)
{
    MPU_IDR_PTR->IDR.bits.CPID = MpuId;
}

/**
 * @brief 获取从端口访问错误时的地址(访问错误时捕捉的当前地址)
 *
 * @param SlaveIndex 从端口序号 \n
 *                  MPU_INDEX_SLAVE_0 -- 从端口0 \n
 *                  MPU_INDEX_SLAVE_1 -- 从端口1 \n
 *                  MPU_INDEX_SLAVE_2 -- 从端口2 \n
 *                  MPU_INDEX_SLAVE_3 -- 从端口3
 * @retval uint32_t 错误地址
 */
KF_INLINE uint32_t Mpu_LL_ReadAccessDenyAddr(Mpu_Slave_t SlaveIndex)
{
    const uint32_t *kpTmpReg = NULL;

    KF_MPU_ASSERT(CHECK_MPU_SLAVE_INDEX(SlaveIndex));

    kpTmpReg = (uint32_t *)((uint32_t)&MPU_PTR->ERRARS0 + (8U * (uint32_t)SlaveIndex));
    return (*kpTmpReg);
}

/**
 * @brief 获取访问错误信息 \n
 *                  ERRDRSn 有捕捉错误且ERRACD为全零 --> 访问未命中 \n
 *                  ERRACD 中只有一位为1 --> 单一非重叠的地址范围访问错误 \n
 *                  ERRACD 中有两位以上1 --> 重叠的地址范围访问错误
 *
 * @param SlaveIndex 从端口序号 \n
 *                  MPU_INDEX_SLAVE_0 -- 从端口0 \n
 *                  MPU_INDEX_SLAVE_1 -- 从端口1 \n
 *                  MPU_INDEX_SLAVE_2 -- 从端口2 \n
 *                  MPU_INDEX_SLAVE_3 -- 从端口3
 * @retval uint16_t 访问错误信息
 */
KF_INLINE uint16_t Mpu_LL_GetAccessDenyMessage(Mpu_Slave_t SlaveIndex)
{
    const uint32_t *kpTmpReg = NULL;

    KF_MPU_ASSERT(CHECK_MPU_SLAVE_INDEX(SlaveIndex));

    kpTmpReg = (uint32_t *)((uint32_t)&MPU_PTR->ERRDRS0 + (8U * (uint32_t)SlaveIndex));
    return (uint16_t)(*kpTmpReg >> 16U);
}

/**
 * @brief 获取处理编号(PID)错误信息 \n
 *                  记录错误时的处理编号
 *
 * @param SlaveIndex 从端口序号 \n
 *                  MPU_INDEX_SLAVE_0 -- 从端口0 \n
 *                  MPU_INDEX_SLAVE_1 -- 从端口1 \n
 *                  MPU_INDEX_SLAVE_2 -- 从端口2 \n
 *                  MPU_INDEX_SLAVE_3 -- 从端口3
 * @retval uint8_t 处理编号(PID)
 */
KF_INLINE uint8_t Mpu_LL_GetAccessDenyPid(Mpu_Slave_t SlaveIndex)
{
    const uint32_t *kpTmpReg = NULL;

    KF_MPU_ASSERT(CHECK_MPU_SLAVE_INDEX(SlaveIndex));

    kpTmpReg = (uint32_t *)((uint32_t)&MPU_PTR->ERRDRS0 + (8U * (uint32_t)SlaveIndex));
    return (uint8_t)((*kpTmpReg >> 8U) & 0x000000FFU);
}

/**
 * @brief 获取访问错误时的总线主机编号
 *
 * @param SlaveIndex 从端口序号 \n
 *                  MPU_INDEX_SLAVE_0 -- 从端口0 \n
 *                  MPU_INDEX_SLAVE_1 -- 从端口1 \n
 *                  MPU_INDEX_SLAVE_2 -- 从端口2 \n
 *                  MPU_INDEX_SLAVE_3 -- 从端口3
 * @retval Mpu_Master_t 主机序号 \n
 *                  MPU_MASTER_0 -- Master 0(Core) \n
 *                  MPU_MASTER_1 -- Master 1(Debugger) \n
 *                  MPU_MASTER_2 -- Master 2(DMA)
 */
KF_INLINE Mpu_Master_t Mpu_LL_GetAccessDenyMaster(Mpu_Slave_t SlaveIndex)
{
    KF_MPU_ASSERT(CHECK_MPU_SLAVE_INDEX(SlaveIndex));
    const uint32_t *kpTmpReg = NULL;
    uint32_t        tmpAccessDeny;

    kpTmpReg      = (uint32_t *)((uint32_t)&MPU_PTR->ERRDRS0 + (8U * (uint32_t)SlaveIndex));
    tmpAccessDeny = ((*kpTmpReg >> 4U) & 0xFU);
    return (Mpu_Master_t)tmpAccessDeny;
}

/**
 * @brief 获取访问错误时的错误类型
 *
 * @param SlaveIndex 从端口序号 \n
 *                  MPU_INDEX_SLAVE_0 -- 从端口0 \n
 *                  MPU_INDEX_SLAVE_1 -- 从端口1 \n
 *                  MPU_INDEX_SLAVE_2 -- 从端口2 \n
 *                  MPU_INDEX_SLAVE_3 -- 从端口3
 * @retval uint8_t 错误类型(低3位有效) \n
 *                  000 = 普通用户模式,指令访问 \n
 *                  001 = 普通用户模式,数据访问 \n
 *                  010 = 超级用户模式,指令访问 \n
 *                  011 = 超级用户模式,数据访问
 */
KF_INLINE uint8_t Mpu_LL_GetAccessDenyErrorType(Mpu_Slave_t SlaveIndex)
{
    const uint32_t *kpTmpReg = NULL;

    KF_MPU_ASSERT(CHECK_MPU_SLAVE_INDEX(SlaveIndex));

    kpTmpReg = (uint32_t *)((uint32_t)&MPU_PTR->ERRDRS0 + (8U * (uint32_t)SlaveIndex));
    return (uint8_t)((*kpTmpReg >> 1U) & 0x7U);
}

/**
 * @brief 获取访问失败时的访问类型
 *
 * @param SlaveIndex 从端口序号 \n
 *                  MPU_INDEX_SLAVE_0 -- 从端口0 \n
 *                  MPU_INDEX_SLAVE_1 -- 从端口1 \n
 *                  MPU_INDEX_SLAVE_2 -- 从端口2 \n
 *                  MPU_INDEX_SLAVE_3 -- 从端口3
 * @retval bool 访问类型 \n
 *                  true -- 写 \n
 *                  false -- 读
 */
KF_INLINE bool Mpu_LL_GetAccessDenyType(Mpu_Slave_t SlaveIndex)
{
    const uint32_t *kpTmpReg = NULL;

    KF_MPU_ASSERT(CHECK_MPU_SLAVE_INDEX(SlaveIndex));

    kpTmpReg = (uint32_t *)((uint32_t)&MPU_PTR->ERRDRS0 + (8U * (uint32_t)SlaveIndex));
    return ((*kpTmpReg & 0x01U) != 0U);
}

/**
 * @brief 设置内存范围描述所定义的起始地址,低5位为 00000
 *
 * @param RegionIndex 范围序号 \n
 *                      MPU_REGION_0 ~ MPU_REGION_15
 * @param StartAddr 起始地址 \n
 *                      低5位需要为0, 0x0 ~ 0xffffffff
 * @retval void
 */
KF_INLINE void Mpu_LL_WriteRegionStartAddr(Mpu_Region_t RegionIndex, uint32_t StartAddr)
{
    uint32_t *kpTmpReg = NULL;

    KF_MPU_ASSERT(CHECK_MPU_REGION(RegionIndex));

    kpTmpReg  = (uint32_t *)((uint32_t)&MPU_PTR->RGDE0W0.reg + (16U * (uint32_t)RegionIndex));
    *kpTmpReg = StartAddr & (~0x1FU);
}

/**
 * @brief 设置内存范围描述所定义的结束地址,低5位为 11111
 *
 * @param RegionIndex 范围序号 \n
 *                      MPU_REGION_0 ~ MPU_REGION_15
 * @param EndAddr 结束地址 \n
 *                      低5位需要为1, 0x0 ~ 0xffffffff
 * @retval void
 */
KF_INLINE void Mpu_LL_WriteRegionEndAddr(Mpu_Region_t RegionIndex, uint32_t EndAddr)
{
    uint32_t *kpTmpReg = NULL;

    KF_MPU_ASSERT(CHECK_MPU_REGION(RegionIndex));

    kpTmpReg  = (uint32_t *)((uint32_t)&MPU_PTR->RGDE0W1.reg + (16U * (uint32_t)RegionIndex));
    *kpTmpReg = EndAddr | 0x1FU;
}

/**
 * @brief 设置普通用户模式访问权限
 *
 * @param RegionIndex 范围序号 \n
 *                      MPU_REGION_0 ~ MPU_REGION_15
 * @param MasterIndex 主机序号 \n
 *                  MPU_MASTER_0 -- Master 0(Core) \n
 *                  MPU_MASTER_1 -- Master 1(Debugger) \n
 *                  MPU_MASTER_2 -- Master 2(DMA)
 * @param Access 普通用户访问权限 \n
 *                  MPU_ACCESS_NORMAL_NONE -- 无权限 \n
 *                  MPU_ACCESS_NORMAL_X -- 仅可执行权限 \n
 *                  MPU_ACCESS_NORMAL_W -- 仅可写权限 \n
 *                  MPU_ACCESS_NORMAL_WX -- 写,执行权限 \n
 *                  MPU_ACCESS_NORMAL_R -- 仅可读权限 \n
 *                  MPU_ACCESS_NORMAL_RX -- 读,可执行权限 \n
 *                  MPU_ACCESS_NORMAL_RW -- 读,写权限 \n
 *                  MPU_ACCESS_NORMAL_RWX -- 读,写,可执行权限
 * @retval void
 */
KF_INLINE void
Mpu_LL_SetAccessOfNormalUser(Mpu_Region_t RegionIndex, Mpu_Master_t MasterIndex, Mpu_NormalAccess_t Access)
{
    uint32_t *kpTmpReg = NULL;
    uint32_t  Mask;

    KF_MPU_ASSERT(CHECK_MPU_REGION(RegionIndex));
    KF_MPU_ASSERT(CHECK_MPU_MASTER(MasterIndex));
    KF_MPU_ASSERT(CHECK_MPU_NORMAL_ACCESS(Access));

    kpTmpReg = (uint32_t *)((uint32_t)&MPU_PTR->RGDE0W2.reg + (16U * (uint32_t)RegionIndex));
    Mask     = (uint32_t)MasterIndex * 6U;
    REG_BITS_WRITE(*kpTmpReg, 0x7UL << Mask, (uint32_t)Access << Mask);
}

/**
 * @brief 设置超级用户模式访问权限
 *
 * @param RegionIndex 范围序号 \n
 *                      MPU_REGION_0 ~ MPU_REGION_15
 * @param MasterIndex 主机序号 \n
 *                  MPU_MASTER_0 -- Master 0(Core) \n
 *                  MPU_MASTER_1 -- Master 1(Debugger) \n
 *                  MPU_MASTER_2 -- Master 2(DMA)
 * @param Access 超级用户访问权限 \n
 *                  MPU_ACCESS_SU_RWX -- 读/写/运行(r/w/x)允许 \n
 *                  MPU_ACCESS_SU_RX -- 读/运行(r/x)允许,写(w)不允许 \n
 *                  MPU_ACCESS_SU_RW -- 读/写(r/w)允许,运行(x)不允许 \n
 *                  MPU_ACCESS_SU_SAMETONORMAL -- 由普通用户模式定义
 * @retval void
 */
KF_INLINE void Mpu_LL_SetAccessOfSuperUser(Mpu_Region_t RegionIndex, Mpu_Master_t MasterIndex, Mpu_SuAccess_t Access)
{
    uint32_t *kpTmpReg = NULL;
    uint32_t  Mask;

    KF_MPU_ASSERT(CHECK_MPU_REGION(RegionIndex));
    KF_MPU_ASSERT(CHECK_MPU_MASTER(MasterIndex));
    KF_MPU_ASSERT(CHECK_MPU_SU_ACCESS(Access));

    kpTmpReg = (uint32_t *)((uint32_t)&MPU_PTR->RGDE0W2.reg + (16U * (uint32_t)RegionIndex));
    Mask     = ((uint32_t)MasterIndex * 6U) + 3U;
    REG_BITS_WRITE(*kpTmpReg, 0x3UL << Mask, (uint32_t)Access << Mask);
}

/**
 * @brief 设置主机处理编号使能状态
 *
 * @param RegionIndex 范围序号 \n
 *                      MPU_REGION_0 ~ MPU_REGION_15
 * @param MasterIndex 主机序号 \n
 *                  MPU_MASTER_0 -- Master 0(Core) \n
 *                  MPU_MASTER_1 -- Master 1(Debugger)
 * @param EnableStatus 使能状态 \n
 *                  true -- 主机处理编号使能 \n
 *                  false -- 主机处理编号不使能
 * @retval void
 */
KF_INLINE void Mpu_LL_SetProcessPidEnabled(Mpu_Region_t RegionIndex, Mpu_Master_t MasterIndex, bool EnableStatus)
{
    uint32_t *kpTmpReg = NULL;
    uint32_t  Mask;

    KF_MPU_ASSERT(CHECK_MPU_REGION(RegionIndex));
    KF_MPU_ASSERT(CHECK_MPU_MASTER_FOR_PID(MasterIndex));

    kpTmpReg = (uint32_t *)((uint32_t)&MPU_PTR->RGDE0W2.reg + (16U * (uint32_t)RegionIndex));
    Mask     = ((uint32_t)MasterIndex * 6U) + 5U;
    REG_BITS_WRITE(*kpTmpReg, 0x1UL << Mask, (EnableStatus ? 1UL : 0UL) << Mask);
}

/**
 * @brief 设置处理编号
 *
 * @param RegionIndex 范围序号 \n
 *                      MPU_REGION_0 ~ MPU_REGION_15
 * @param Pid 处理编号 \n
 *                      0x0 ~ 0xff
 * @retval void
 */
KF_INLINE void Mpu_LL_SetProcessPid(Mpu_Region_t RegionIndex, uint8_t Pid)
{
    uint32_t *kpTmpReg = NULL;

    KF_MPU_ASSERT(CHECK_MPU_REGION(RegionIndex));

    kpTmpReg = (uint32_t *)((uint32_t)&MPU_PTR->RGDE0W3.reg + (16U * (uint32_t)RegionIndex));
    REG_BITS_WRITE(*kpTmpReg, 0xFFUL << 24U, (uint32_t)Pid << 24U);
}

/**
 * @brief 设置处理编号掩码
 *
 * @param RegionIndex 范围序号 \n
 *                      MPU_REGION_0 ~ MPU_REGION_15
 * @param PidMask 处理编号掩码 \n
 *                      0x0 ~ 0xff
 * @retval void
 */
KF_INLINE void Mpu_LL_SetProcessPidMask(Mpu_Region_t RegionIndex, uint8_t PidMask)
{
    uint32_t *kpTmpReg = NULL;

    KF_MPU_ASSERT(CHECK_MPU_REGION(RegionIndex));

    kpTmpReg = (uint32_t *)((uint32_t)&MPU_PTR->RGDE0W3.reg + (16U * (uint32_t)RegionIndex));
    REG_BITS_WRITE(*kpTmpReg, 0xFFUL << 16U, (uint32_t)PidMask << 16U);
}

/**
 * @brief 设置范围描述字有效状态
 *
 * @param RegionIndex 范围序号 \n
 *                      MPU_REGION_0 ~ MPU_REGION_15
 * @param EnableStatus 有效状态 \n
 *                  true -- 范围描述字有效 \n
 *                  false -- 范围描述字无效
 * @retval void
 */
KF_INLINE void Mpu_LL_SetRegionEnabled(Mpu_Region_t RegionIndex, bool EnableStatus)
{
    uint32_t *kpTmpReg = NULL;

    KF_MPU_ASSERT(CHECK_MPU_REGION(RegionIndex));

    kpTmpReg = (uint32_t *)((uint32_t)&MPU_PTR->RGDE0W3.reg + (16U * (uint32_t)RegionIndex));
    REG_BITS_WRITE(*kpTmpReg, 0x1U, EnableStatus ? 1U : 0U);
}

/**
 * @brief 设置替换访问控制寄存器普通用户模式访问权限
 *
 * @param RegionIndex 范围序号 \n
 *                      MPU_REGION_0 ~ MPU_REGION_15
 * @param MasterIndex 主机序号 \n
 *                  MPU_MASTER_0 -- Master 0(Core) \n
 *                  MPU_MASTER_1 -- Master 1(Debugger) \n
 *                  MPU_MASTER_2 -- Master 2(DMA)
 * @param Access 普通用户访问权限 \n
 *                  MPU_ACCESS_NORMAL_NONE -- 无权限 \n
 *                  MPU_ACCESS_NORMAL_X -- 仅可执行权限 \n
 *                  MPU_ACCESS_NORMAL_W -- 仅可写权限 \n
 *                  MPU_ACCESS_NORMAL_WX -- 写,执行权限 \n
 *                  MPU_ACCESS_NORMAL_R -- 仅可读权限 \n
 *                  MPU_ACCESS_NORMAL_RX -- 读,可执行权限 \n
 *                  MPU_ACCESS_NORMAL_RW -- 读,写权限 \n
 *                  MPU_ACCESS_NORMAL_RWX -- 读,写,可执行权限
 * @retval void
 */
KF_INLINE void
Mpu_LL_SetReplaceAccessOfNormalUser(Mpu_Region_t RegionIndex, Mpu_Master_t MasterIndex, Mpu_NormalAccess_t Access)
{
    uint32_t *kpTmpReg = NULL;
    uint32_t  Mask;

    KF_MPU_ASSERT(CHECK_MPU_REGION(RegionIndex));
    KF_MPU_ASSERT(CHECK_MPU_MASTER(MasterIndex));
    KF_MPU_ASSERT(CHECK_MPU_NORMAL_ACCESS(Access));

    kpTmpReg = (uint32_t *)((uint32_t)&MPU_PTR->RGDEACC0.reg + (4U * (uint32_t)RegionIndex));
    Mask     = (uint32_t)MasterIndex * 6U;
    REG_BITS_WRITE(*kpTmpReg, 0x7UL << Mask, (uint32_t)Access << Mask);
}

/**
 * @brief 设置替换访问控制寄存器超级用户模式访问权限
 *
 * @param RegionIndex 范围序号 \n
 *                      MPU_REGION_0 ~ MPU_REGION_15
 * @param MasterIndex 主机序号 \n
 *                  MPU_MASTER_0 -- Master 0(Core) \n
 *                  MPU_MASTER_1 -- Master 1(Debugger) \n
 *                  MPU_MASTER_2 -- Master 2(DMA)
 * @param Access 超级用户访问权限 \n
 *                  MPU_ACCESS_SU_RWX -- 读/写/运行(r/w/x)允许 \n
 *                  MPU_ACCESS_SU_RX -- 读/运行(r/x)允许,写(w)不允许 \n
 *                  MPU_ACCESS_SU_RW -- 读/写(r/w)允许,运行(x)不允许 \n
 *                  MPU_ACCESS_SU_SAMETONORMAL -- 由普通用户模式定义
 * @retval void
 */
KF_INLINE void
Mpu_LL_SetReplaceAccessOfSuperUser(Mpu_Region_t RegionIndex, Mpu_Master_t MasterIndex, Mpu_SuAccess_t Access)
{
    uint32_t *kpTmpReg = NULL;
    uint32_t  Mask;

    KF_MPU_ASSERT(CHECK_MPU_REGION(RegionIndex));
    KF_MPU_ASSERT(CHECK_MPU_MASTER(MasterIndex));
    KF_MPU_ASSERT(CHECK_MPU_SU_ACCESS(Access));

    kpTmpReg = (uint32_t *)((uint32_t)&MPU_PTR->RGDEACC0.reg + (4U * (uint32_t)RegionIndex));
    Mask     = ((uint32_t)MasterIndex * 6U) + 3U;
    REG_BITS_WRITE(*kpTmpReg, 0x3UL << Mask, (uint32_t)Access << Mask);
}

/**
 * @brief 设置替换访问控制寄存器主机处理编号使能状态
 *
 * @param RegionIndex 范围序号 \n
 *                      MPU_REGION_0 ~ MPU_REGION_15
 * @param MasterIndex 主机序号 \n
 *                  MPU_MASTER_0 -- Master 0(Core) \n
 *                  MPU_MASTER_1 -- Master 1(Debugger)
 * @param EnableStatus 使能状态 \n
 *                  true -- 主机处理编号使能 \n
 *                  false -- 主机处理编号不使能
 * @retval void
 */
KF_INLINE void Mpu_LL_SetReplaceProcessPidEnabled(Mpu_Region_t RegionIndex, Mpu_Master_t MasterIndex, bool EnableStatus)
{
    uint32_t *kpTmpReg = NULL;
    uint32_t  Mask;

    KF_MPU_ASSERT(CHECK_MPU_REGION(RegionIndex));
    KF_MPU_ASSERT(CHECK_MPU_MASTER_FOR_PID(MasterIndex));

    kpTmpReg = (uint32_t *)((uint32_t)&MPU_PTR->RGDEACC0.reg + (4U * (uint32_t)RegionIndex));
    Mask     = ((uint32_t)MasterIndex * 6U) + 5U;
    REG_BITS_WRITE(*kpTmpReg, 0x1UL << Mask, (EnableStatus ? 1UL : 0UL) << Mask);
}

/**
 * @brief: 更新replace寄存器
 *
 * @retval void
 */
KF_INLINE void Mpu_LL_SetSyncReplaceRegister(void)
{
    MPU_PTR->RGDEACC0.reg  = MPU_PTR->RGDE0W2.reg;
    MPU_PTR->RGDEACC1.reg  = MPU_PTR->RGDE1W2.reg;
    MPU_PTR->RGDEACC2.reg  = MPU_PTR->RGDE2W2.reg;
    MPU_PTR->RGDEACC3.reg  = MPU_PTR->RGDE3W2.reg;
    MPU_PTR->RGDEACC4.reg  = MPU_PTR->RGDE4W2.reg;
    MPU_PTR->RGDEACC5.reg  = MPU_PTR->RGDE5W2.reg;
    MPU_PTR->RGDEACC6.reg  = MPU_PTR->RGDE6W2.reg;
    MPU_PTR->RGDEACC7.reg  = MPU_PTR->RGDE7W2.reg;
    MPU_PTR->RGDEACC8.reg  = MPU_PTR->RGDE8W2.reg;
    MPU_PTR->RGDEACC9.reg  = MPU_PTR->RGDE9W2.reg;
    MPU_PTR->RGDEACC10.reg = MPU_PTR->RGDE10W2.reg;
    MPU_PTR->RGDEACC11.reg = MPU_PTR->RGDE11W2.reg;
    MPU_PTR->RGDEACC12.reg = MPU_PTR->RGDE12W2.reg;
    MPU_PTR->RGDEACC13.reg = MPU_PTR->RGDE13W2.reg;
    MPU_PTR->RGDEACC14.reg = MPU_PTR->RGDE14W2.reg;
    MPU_PTR->RGDEACC15.reg = MPU_PTR->RGDE15W2.reg;
}

#ifdef __cplusplus
}
#endif /*End of __cplusplus*/
#endif /*End of KF32A158SF_DRV_MPU_H*/
/* EOF */
