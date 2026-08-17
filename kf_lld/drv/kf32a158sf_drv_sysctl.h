/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name        : kf32a158sf_drv_sysctl.h
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
#ifndef KF32A158SF_DRV_SYSCTL_H
#define KF32A158SF_DRV_SYSCTL_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 *                      QAC Warnings
 ******************************************************************************/
/* PRQA S 0288 EOF #KQR000288 */
/* PRQA S 0303,0306 EOF #KQR100303 */
/* PRQA S 3205 EOF #KQR003205 */
/* PRQA S 3219 EOF #KQR003219 */

/******************************************************************************
 *                      Include Files
 ******************************************************************************/
#include <stdint.h>
#include <stdbool.h>
#include <kf_types.h>
#include "kf32a158sf_reg_system.h"

#ifdef KF_DRV_SYSCTL_ASSERT
#include "dev_assert.h"
#define KF_SYSCTL_ASSERT(x) KF_DEV_ASSERT(x)
#else
#define KF_SYSCTL_ASSERT(x) ((void)0U)
#endif
/******************************************************************************
 *                      Macro or Inline
 ******************************************************************************/

/**应用和复位控制寄存器写操作 key*/
#define ARCTL_KEY (0x05FA0000U)

#define SYS_ARCTL_SYSTEMRST_POS (2)
#define SYS_ARCTL_CDMAR_POS     (4)
#define SYS_ARCTL_CDMAAM_POS    (5)
#define SYS_ARCTL_CRWDC_POS     (6)
#define SYS_ARCTL_CDBUGBS_POS   (8)
#define SYS_ARCTL_CDMALDC0_POS  (9)
#define SYS_ARCTL_ROMLOCK_POS   (11)

#define UID_LEN_IN_BYTE (16u)
/******************************************************************************
 *                      Type definitions
 ******************************************************************************/

/**FLASH 开始 512 字节空间映射控制*/
typedef enum
{
    SYS_MEMM_ROM_MAP,
    SYS_MEMM_RAM_MAP,
    SYS_MEMM_FLASH_MAP,
    SYS_MEMM_CPU_STOP,
} Sysctl_MemMapControl_t;
#define CHECK_SYSCTL_MEMMAPCONTROL(x)                                                                                  \
    (((x) == SYS_MEMM_ROM_MAP) || ((x) == SYS_MEMM_RAM_MAP) || ((x) == SYS_MEMM_FLASH_MAP) ||                          \
     ((x) == SYS_MEMM_CPU_STOP))

/**CORE 和 DMA 读写 BKP 域加长周期模式控制*/
typedef enum
{
    SYS_CDMA_LDC_16_CYCLE_RW = 0x1,
    SYS_CDMA_LDC_32_CYCLE_RW = 0x2,
    SYS_CDMA_LDC_64_CYCLE_RW = 0x3,
} Sysctl_CdmaLdc_t;
#define CHECK_SYSCTL_CDMALDC(x)                                                                                        \
    (((x) == SYS_CDMA_LDC_16_CYCLE_RW) || ((x) == SYS_CDMA_LDC_32_CYCLE_RW) || ((x) == SYS_CDMA_LDC_64_CYCLE_RW))

/******************************************************************************
 *                      Export Variables
 ******************************************************************************/

/******************************************************************************
 *                      Export Functions
 ******************************************************************************/

/**
 * @brief 获取溢出标志位
 * @param Module 系统寄存器结构体指针
 * @retval true : 溢出
 * @retval false : 未溢出
 */
KF_INLINE bool System_LL_GetOverflowFlag(const System_RegisterMap_t *const Module)
{
    KF_SYSCTL_ASSERT(CHECK_SYSTEM_ALL_PERIPH_ADDR(Module));

    return (Module->PSW.bits.V != 0U);
}

/**
 * @brief 获取进位或借位标志位
 * @param Module 系统寄存器结构体指针
 * @retval true : 进位或无借位
 * @retval false : 未进位或借位
 */
KF_INLINE bool System_LL_GetCarryBorrowFlag(const System_RegisterMap_t *const Module)
{
    KF_SYSCTL_ASSERT(CHECK_SYSTEM_ALL_PERIPH_ADDR(Module));

    return (Module->PSW.bits.C != 0U);
}

/**
 * @brief 获取零值标志位
 * @param Module 系统寄存器结构体指针
 * @retval true : 值为零
 * @retval false : 值不为零
 */
KF_INLINE bool System_LL_GetZeroValueFlag(const System_RegisterMap_t *const Module)
{
    KF_SYSCTL_ASSERT(CHECK_SYSTEM_ALL_PERIPH_ADDR(Module));

    return (Module->PSW.bits.Z != 0U);
}

/**
 * @brief 获取负值标志位
 * @param Module 系统寄存器结构体指针
 * @retval true : 值为负
 * @retval false : 值不为负
 */
KF_INLINE bool System_LL_GetNegativeValueFlag(const System_RegisterMap_t *const Module)
{
    KF_SYSCTL_ASSERT(CHECK_SYSTEM_ALL_PERIPH_ADDR(Module));

    return (Module->PSW.bits.N != 0U);
}

/**
 * @brief 获取当前有效堆栈指针
 * @param Module 系统寄存器结构体指针
 * @retval true : 当前有效堆栈指针为PSP
 * @retval false : 当前有效堆栈指针为MSP
 */
KF_INLINE bool System_LL_GetStackPointerState(const System_RegisterMap_t *const Module)
{
    KF_SYSCTL_ASSERT(CHECK_SYSTEM_ALL_PERIPH_ADDR(Module));

    return (Module->MCTL.bits.SPSEL != 0U);
}

/**
 * @brief 设置当前有效堆栈指针
 *
 * @param Module 系统寄存器结构体指针
 * @param State 当前有效指针
 *          true  当前有效堆栈指针为PSP
 *          false  当前有效堆栈指针为MSP
 * @retval void
 */
KF_INLINE void System_LL_SetStackPointerState(System_RegisterMap_t *const Module, bool State)
{
    KF_SYSCTL_ASSERT(CHECK_SYSTEM_ALL_PERIPH_ADDR(Module));

    Module->MCTL.bits.SPSEL = State ? 1U : 0U;
}

/**
 * @brief 设置超级用户控制位
 * @param Module 系统寄存器结构体指针
 * @param State:
 *          true   开启超级用户模式
 *          false   禁止超级用户模式
 * @retval none
 */
KF_INLINE void System_LL_SetSuperUserState(System_RegisterMap_t *const Module, bool State)
{
    KF_SYSCTL_ASSERT(CHECK_SYSTEM_ALL_PERIPH_ADDR(Module));

    Module->MCTL.bits.SUSTA = State ? 1U : 0U;
}

/**
 * @brief 获取堆栈对齐状态
 *
 * @param Module 系统寄存器结构体指针
 * @retval bool
 *          true   堆栈空间由系统自动处理成 8 字节对齐
 *          false   堆栈空间已经是 8 字节对齐或双字对齐未使能
 */
KF_INLINE bool System_LL_GetStackAlignState(const System_RegisterMap_t *const Module)
{
    KF_SYSCTL_ASSERT(CHECK_SYSTEM_ALL_PERIPH_ADDR(Module));

    return (Module->MCTL.bits.STACKALIGN != 0U) ? true : false;
}

/**
 * @brief 设置唤醒模式选择
 * @param Module 系统寄存器结构体指针
 * @param State:
 *          true   任意挂起的中断都能唤醒CPU
 *          false   只有当挂起的中断优先级比当前优先级高时才能唤醒CPU
 * @retval none
 */
KF_INLINE void System_LL_SetWakeupMode(System_RegisterMap_t *const Module, bool State)
{
    KF_SYSCTL_ASSERT(CHECK_SYSTEM_ALL_PERIPH_ADDR(Module));

    Module->MCTL.bits.SLPONMOD = State ? 1U : 0U;
}

/**
 * @brief 中断处理返回进入休眠模式
 *
 * @param Module 系统寄存器结构体指针
 * @param State
 *          true   中断返回时进入休眠模式
 *          false   无影响
 * @retval void
 */
KF_INLINE void System_LL_SetSleepOnExit(System_RegisterMap_t *const Module, bool State)
{
    KF_SYSCTL_ASSERT(CHECK_SYSTEM_ALL_PERIPH_ADDR(Module));

    Module->MCTL.bits.SLEEPONEXIT = State ? 1U : 0U;
}

/**
 * @brief: 设置系统复位请求
 * @param Module 系统寄存器结构体指针
 * @param State
 *          true   请求系统复位
 *          false   无影响
 * @retval none
 */
KF_INLINE void System_LL_SetSystemReset(System_RegisterMap_t *const Module, bool State)
{
    KF_SYSCTL_ASSERT(CHECK_SYSTEM_ALL_PERIPH_ADDR(Module));

    uint32_t Mask = 0xFFFF0000U | (1UL << SYS_ARCTL_SYSTEMRST_POS);
    uint32_t Reg  = ARCTL_KEY | ((State ? 1UL : 0UL) << SYS_ARCTL_SYSTEMRST_POS);

    /* PRQA S 3473 1 #KQR003473 */
    REG_BITS_WRITE(Module->ARCTL.reg, Mask, Reg);
}

/**
 * @brief: 设置内核DMA控制状态清零控制
 * @param Module 系统寄存器结构体指针
 * @param State
 *          true   无作用
 *          false   清零内核DMA控制状态
 * @retval none
 */
KF_INLINE void System_LL_ClearCoreDMAState(System_RegisterMap_t *const Module, bool State)
{
    KF_SYSCTL_ASSERT(CHECK_SYSTEM_ALL_PERIPH_ADDR(Module));

    uint32_t Mask = 0xFFFF0000U | (1UL << SYS_ARCTL_CDMAR_POS);
    uint32_t Reg  = ARCTL_KEY | ((State ? 1UL : 0UL) << SYS_ARCTL_CDMAR_POS);

    /* PRQA S 3473 1 #KQR003473 */
    REG_BITS_WRITE(Module->ARCTL.reg, Mask, Reg);
}

/**
 * @brief: 设置内核DMA与CPU读写冲突仲裁模式选择
 * @param Module 系统寄存器结构体指针
 * @param State
 *          true   保留
 *          false   高速模式,DMA 与CPU 同时读写则判断为冲突
 * @retval none
 */
KF_INLINE void System_LL_SetCoreDMAArbitrationMode(System_RegisterMap_t *const Module, bool State)
{
    KF_SYSCTL_ASSERT(CHECK_SYSTEM_ALL_PERIPH_ADDR(Module));

    uint32_t Mask = 0xFFFF0000U | (1UL << SYS_ARCTL_CDMAAM_POS);
    uint32_t Reg  = ARCTL_KEY | ((State ? 1UL : 0UL) << SYS_ARCTL_CDMAAM_POS);

    /* PRQA S 3473 1 #KQR003473 */
    REG_BITS_WRITE(Module->ARCTL.reg, Mask, Reg);
}

/**
 * @brief: 设置CORE读写外设长周期模式控制
 * @param Module 系统寄存器结构体指针
 * @param State
 *          true   CORE 对外设所有区域读/写分别为1 个周期
 *          false   CORE 对外设读/写分别为2 周期,对RAM 读/写为分别1 周期
 * @retval none
 */
KF_INLINE void System_LL_SetCorePeripheralExtendedCycleMode(System_RegisterMap_t *const Module, bool State)
{
    KF_SYSCTL_ASSERT(CHECK_SYSTEM_ALL_PERIPH_ADDR(Module));

    uint32_t Mask = 0xFFFF0000U | (1UL << SYS_ARCTL_CRWDC_POS);
    uint32_t Reg  = ARCTL_KEY | ((State ? 1UL : 0UL) << SYS_ARCTL_CRWDC_POS);

    /* PRQA S 3473 1 #KQR003473 */
    REG_BITS_WRITE(Module->ARCTL.reg, Mask, Reg);
}

/**
 * @brief: 设置内核DEBUG模式断点与单步模式控制
 * @param Module 系统寄存器结构体指针
 * @param State
 *          true   单步模式下与断点同时响应
 *          false   单步模式下忽略断点响应
 * @retval none
 */
KF_INLINE void System_LL_SetCoreDebugControl(System_RegisterMap_t *const Module, bool State)
{
    KF_SYSCTL_ASSERT(CHECK_SYSTEM_ALL_PERIPH_ADDR(Module));

    uint32_t Mask = 0xFFFF0000U | (1UL << SYS_ARCTL_CDBUGBS_POS);
    uint32_t Reg  = ARCTL_KEY | ((State ? 1UL : 0UL) << SYS_ARCTL_CDBUGBS_POS);

    /* PRQA S 3473 1 #KQR003473 */
    REG_BITS_WRITE(Module->ARCTL.reg, Mask, Reg);
}

/**
 * @brief: 设置CORE和DMA读写BKP域加长周期模式控制
 * @param Module 系统寄存器结构体指针
 * @param State  Sysctl_CdmaLdc_t
 * @retval none
 */
KF_INLINE void
System_LL_SetCoreDMABackupExtendedCyclePlusControl(System_RegisterMap_t *const Module, Sysctl_CdmaLdc_t State)
{
    KF_SYSCTL_ASSERT(CHECK_SYSTEM_ALL_PERIPH_ADDR(Module));
    KF_SYSCTL_ASSERT(CHECK_SYSCTL_CDMALDC(State));

    uint32_t Mask = 0xFFFF0000U | (3UL << SYS_ARCTL_CDMALDC0_POS);
    uint32_t Reg  = ARCTL_KEY | ((uint32_t)State << SYS_ARCTL_CDMALDC0_POS);

    /* PRQA S 3473 1 #KQR003473 */
    REG_BITS_WRITE(Module->ARCTL.reg, Mask, Reg);
}

/**
 * @brief: 设置中断向量表重映射偏移地址
 * @param Module 系统寄存器结构体指针
 * @param Offset 中断向量表重映射偏移地址
 * @retval none
 */
KF_INLINE void System_LL_SetVectorTableOffset(System_RegisterMap_t *const Module, uint32_t Offset)
{
    KF_SYSCTL_ASSERT(CHECK_SYSTEM_ALL_PERIPH_ADDR(Module));

    Module->VECTOFF.bits.TBLOFF = Offset;
}

/**
 * @brief: 设置RAM堆栈空间上限地址指示
 * @param Module 系统寄存器结构体指针
 * @param Address RAM堆栈空间上限地址指示
 * @retval none
 */
KF_INLINE void System_LL_SetRAMSPA(System_RegisterMap_t *const Module, uint32_t Address)
{
    KF_SYSCTL_ASSERT(CHECK_SYSTEM_ALL_PERIPH_ADDR(Module));

    Module->RAMSPA.bits.RAMSPA = Address;
}

/**
 * @brief: 获取RAM堆栈空间上限地址指示
 * @param Module 系统寄存器结构体指针
 * @retval uint32_t RAM堆栈空间上限地址指示
 */
KF_INLINE uint32_t System_LL_GetRAMSPA(const System_RegisterMap_t *const Module)
{
    KF_SYSCTL_ASSERT(CHECK_SYSTEM_ALL_PERIPH_ADDR(Module));

    return Module->RAMSPA.bits.RAMSPA;
}

/**
 * @brief: 设置FLASH开始512字节空间映射控制
 * @param Module 系统寄存器结构体指针
 * @param Mem Sysctl_MemMapControl_t
 * @retval none
 */
KF_INLINE void System_LL_SetMemControl(System_RegisterMap_t *const Module, Sysctl_MemMapControl_t Mem)
{
    KF_SYSCTL_ASSERT(CHECK_SYSTEM_ALL_PERIPH_ADDR(Module));
    KF_SYSCTL_ASSERT(CHECK_SYSCTL_MEMMAPCONTROL(Mem));

    Module->MEMCTL.bits.MEMM = (uint32_t)Mem;
}

/**
 * @brief: 设置堆栈指针MSP空间下限值指示
 * @param Module 系统寄存器结构体指针
 * @param Value 堆栈指针MSP空间下限值
 * @retval none
 */
KF_INLINE void System_LL_SetMspSpaceLoThreshold(System_RegisterMap_t *const Module, uint16_t Value)
{
    KF_SYSCTL_ASSERT(CHECK_SYSTEM_ALL_PERIPH_ADDR(Module));

    Module->MSPSPA.bits.MSPSPAL = Value;
}

/**
 * @brief: 设置堆栈指针MSP空间上限值指示
 * @param Module 系统寄存器结构体指针
 * @param Value 堆栈指针MSP空间上限值
 * @retval none
 */
KF_INLINE void System_LL_SetMspSpaceHiThreshold(System_RegisterMap_t *const Module, uint16_t Value)
{
    KF_SYSCTL_ASSERT(CHECK_SYSTEM_ALL_PERIPH_ADDR(Module));

    Module->MSPSPA.bits.MSPSPAH = Value;
}

/**
 * @brief: 设置堆栈指针PSP空间下限值
 * @param Module 系统寄存器结构体指针
 * @param Value 堆栈指针PSP空间下限值
 * @retval none
 */
KF_INLINE void System_LL_SetPspSpaceLoThreshold(System_RegisterMap_t *const Module, uint16_t Value)
{
    KF_SYSCTL_ASSERT(CHECK_SYSTEM_ALL_PERIPH_ADDR(Module));

    Module->PSPSPA.bits.PSPSPAL = Value;
}

/**
 * @brief: 设置堆栈指针PSP空间上限值
 * @param Module 系统寄存器结构体指针
 * @param Value 堆栈指针PSP空间上限值
 * @retval none
 */
KF_INLINE void System_LL_SetPspSpaceHiThreshold(System_RegisterMap_t *const Module, uint16_t Value)
{
    KF_SYSCTL_ASSERT(CHECK_SYSTEM_ALL_PERIPH_ADDR(Module));

    Module->PSPSPA.bits.PSPSPAH = Value;
}

/**
 * @brief 获取未定义指令运行标志位
 * @param Module 系统寄存器结构体指针
 * @retval true : 程序运行了未定义的指令
 * @retval false : 无未定义指令运行
 */
KF_INLINE bool System_LL_GetUndefinedInstructionFlag(const System_RegisterMap_t *const Module)
{
    KF_SYSCTL_ASSERT(CHECK_SYSTEM_ALL_PERIPH_ADDR(Module));

    return (Module->MCTL.bits.FETCHOUT != 0U);
}

/**
 * @brief 获取程序跑飞标志位
 * @param Module 系统寄存器结构体指针
 * @retval true : 程序运行到非法的地址空间
 * @retval false : 程序运行在合法的地址空间
 */
KF_INLINE bool System_LL_GetIllegalOperationFlag(const System_RegisterMap_t *const Module)
{
    KF_SYSCTL_ASSERT(CHECK_SYSTEM_ALL_PERIPH_ADDR(Module));

    return (Module->MCTL.bits.RUNOUT != 0U);
}

/**
 * @brief: 设置ROM锁状态
 * @param Module 系统寄存器结构体指针
 * @param State
 *          true   上锁
 *          false  解锁
 * @retval none
 */
KF_INLINE void System_LL_SetRomLockState(System_RegisterMap_t *const Module, bool State)
{
    KF_SYSCTL_ASSERT(CHECK_SYSTEM_ALL_PERIPH_ADDR(Module));

    uint32_t Mask = 0xFFFF0000U | (1UL << SYS_ARCTL_ROMLOCK_POS);
    uint32_t Reg  = ARCTL_KEY | ((State ? 1UL : 0UL) << SYS_ARCTL_ROMLOCK_POS);

    /* PRQA S 3473 1 #KQR003473 */
    REG_BITS_WRITE(Module->ARCTL.reg, Mask, Reg);
}

/**
 * @brief: 读取芯片代码名称
 * @details 上电加载 0xF321_3000
 * @param Module 系统寄存器结构体指针
 * @retval uint32_t 芯片代码名称
 */
KF_INLINE uint32_t System_LL_GetCodeName(const System_RegisterMap_t *const Module)
{
    KF_SYSCTL_ASSERT(CHECK_SYSTEM_ALL_PERIPH_ADDR(Module));

    return Module->CODE_NAME;
}

/**
 * @brief: 读取跑飞时上一条正常运行地址
 * @param Module 系统寄存器结构体指针
 * @retval uint32_t 跑飞时的PC值
 */
KF_INLINE uint32_t System_LL_GetRunoutPC(const System_RegisterMap_t *const Module)
{
    KF_SYSCTL_ASSERT(CHECK_SYSTEM_ALL_PERIPH_ADDR(Module));

    return Module->RUNOUT_PC;
}

/**
 * @brief: 读取跑飞时上一条正常运行指令
 * @param Module 系统寄存器结构体指针
 * @retval uint32_t 跑飞时的指令
 */
KF_INLINE uint32_t System_LL_GetRunoutPD(const System_RegisterMap_t *const Module)
{
    KF_SYSCTL_ASSERT(CHECK_SYSTEM_ALL_PERIPH_ADDR(Module));

    return Module->RUNOUT_PD;
}

/**
 * @brief: 读取UID
 * @param UidBuffer 指向读取UID的数组
 * @retval void
 */
KF_INLINE void System_LL_ReadChipUid(uint8_t *const UidBuffer)
{
    const volatile uint8_t *UidPtr = (volatile uint8_t *)UID_ADDR;

    for (uint32_t i = 0u; i < UID_LEN_IN_BYTE; i++)
    {
        UidBuffer[i] = UidPtr[i];
    }
}

#ifdef __cplusplus
}
#endif /*End of __cplusplus*/
#endif /*End of KF32A158SF_DRV_SYSCTL_H*/
/* EOF */
