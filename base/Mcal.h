/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Mcal.h
 *  @Syntax          : GNU99
 *  @Author          : ChipON AE/FAE Group
 *  @Date            : 2025-08-29
 *  @Version         : V1.0.0_SF
 *  @Description     : This document describes the C language document template.
 ******************************************************************************
 *  Copyright (C) by Shanghai ChipON Micro-Electronic Co.,Ltd
 *  All rights reserved.
 *
 *  This software is copyright protected and proprietary to
 *  Shanghai ChipON Micro-Electronic Co.,Ltd.
 ******************************************************************************
 *                        REVISION HISTORY
 ******************************************************************************
 *  |Date        |Version  |Author       |Description
 ******************************************************************************
 *  |2025-08-29  |V1.0     |Wang Ning    |New creat
 *****************************************************************************/
#ifndef MCAL_H
#define MCAL_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 **                                             MISRA-C Rules Violations
 ******************************************************************************/
/**
 * @page misra_violations MISRA-C:2004 violations
 *
 * @section
 */

/******************************************************************************
 **                                                  QAC Warnings
 ******************************************************************************/
/**
 * @page QAC Warnings
 *
 */

/******************************************************************************
 **                                                         Include Files
 ******************************************************************************/
#include "Std_Types.h"

/******************************************************************************
 **                      File Version Check
 ******************************************************************************/

/******************************************************************************
 **                      Macro  Definitions
 ******************************************************************************/
#ifdef _CHIPON_GCC_KF32_
/**
 * @brief Compiler abstraction for the asm keyword.
 */
#define ASM_KEYWORD __asm volatile

#define ResumeAllInterrupts()                                                                                          \
    do                                                                                                                 \
    {                                                                                                                  \
        ASM_KEYWORD("ENI");                                                                                            \
        ASM_KEYWORD("NOP");                                                                                            \
    } while (0)

#define SuspendAllInterrupts()                                                                                         \
    do                                                                                                                 \
    {                                                                                                                  \
        ASM_KEYWORD("DSI");                                                                                            \
        ASM_KEYWORD("NOP");                                                                                            \
    } while (0)

/**
 * @brief Compiler abstraction for the intrinsic wait instruction.
 */
#define EXECUTE_WAIT()                                                                                                 \
    do                                                                                                                 \
    {                                                                                                                  \
        ResumeAllInterrupts();                                                                                         \
        ASM_KEYWORD(" sleep ");                                                                                        \
        SuspendAllInterrupts();                                                                                        \
    } while (0)
/**
 * @brief Compiler abstraction for the data alignment
 */
#define ALIGNED_VARS_START(sec_name, align)
/**
 * @brief Compiler abstraction for the data alignment
 */
#define VAR_ALIGN(v, size) v __attribute__((aligned(size)))
/**
 * @brief Compiler abstraction for the data alignment
 */
#define ALIGNED_VARS_STOP()

/**
 * @brief Compiler abstraction for the packed qualifier
 */
#define PACKED __packed

#endif

/**
 * @brief Compiler abstraction for creating an interrupt handler if no OS is
 * present.
 */
#define ISR(IsrName) void IsrName(void)

/**
 * @brief Compiler abstraction for returning from an ISR if no OS is present.
 */
#define EXIT_INTERRUPT()
/******************************************************************************
 **                      Typedef  Definitions
 ******************************************************************************/

/******************************************************************************
 **                      Export Variables
 ******************************************************************************/

/******************************************************************************
 **                      Export Functions
 ******************************************************************************/

#ifdef __cplusplus
}
#endif

#endif
/* EOF */
