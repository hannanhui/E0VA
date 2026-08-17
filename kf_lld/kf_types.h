/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name        : kf_types.h
 *  @Date             : 2021-12-23
 *  @Version          : {{VersionDate}}
 *  @Description      : This file provides basic type and macro.
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
 *  |2021-12-23  |V1.0     |Zhai yu      |New create
 ******************************************************************************/
#ifndef KF_TYPES_H
#define KF_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 *                      QAC Warnings
 ******************************************************************************/
/* PRQA S 0602,0603 EOF #KQR100602 */
/* PRQA S 3472 EOF #KQR003472 */

/******************************************************************************
 *                      Include Files
 ******************************************************************************/
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

/******************************************************************************
 *                      Macro or Inline
 ******************************************************************************/
#define REG_BIT_SET(reg, mask)           ((reg) |= (mask))
#define REG_BIT_CLR(reg, mask)           ((reg) &= ~(mask))
#define REG_BITS_WRITE(reg, mask, value) ((reg) = ((reg) & ~(mask)) | (value))
#define REG_BITS_READ(reg, mask, pos)    (((reg) & (mask)) >> (pos))
#define REG_BIT_BOOLED(reg, mask)        (((reg) & (mask)) > 0U)
#define REG_WRITE(reg, value)            ((reg) = (value))
#define REG_READ(reg)                    (reg)

#ifndef KF_CLR_BIT
#define KF_CLR_BIT(reg, offset) __asm volatile("CLR [%0], #%1" ::"r"(&(reg)), "i"(offset) : "memory")
#endif
#ifndef KF_SET_BIT
#define KF_SET_BIT(reg, offset) __asm volatile("SET [%0], #%1" ::"r"(&(reg)), "i"(offset) : "memory")
#endif

#ifndef STD_ON
#define STD_ON 1U
#endif
#ifndef STD_OFF
#define STD_OFF 0U
#endif

#ifndef BIT_SET
#define BIT_SET 0x1U
#endif
#ifndef BIT_CLR
#define BIT_CLR 0x0U
#endif

#ifndef NULL_PTR
#define NULL_PTR ((void *)0U)
#endif

#ifndef __I
/** @brief Defines 'read only' permissions */
#define __I volatile const
#endif
#ifndef __O
/** @brief Defines 'write only' permissions */
#define __O volatile
#endif
#ifndef __IO
/** @brief Defines 'read / write' permissions */
#define __IO volatile
#endif

#ifndef KF_INLINE
#define KF_INLINE static inline
#endif

#ifndef KF_FORCE_INLINE
#define KF_FORCE_INLINE __attribute__((always_inline)) static inline
#endif

#ifndef KF_INTERRUPT
/* PRQA S 0342 1 #KQR000342 */
#define KF_INTERRUPT(isrName) void __attribute__((interrupt)) _##isrName##_exception(void)
#endif

/**
 * @brief Enable interrupt.
 */
#ifndef ENABLE_INTERRUPT
#define ENABLE_INTERRUPT()                                                                                             \
    do                                                                                                                 \
    {                                                                                                                  \
        __asm volatile("ENI");                                                                                         \
        __asm volatile("NOP");                                                                                         \
    } while (0)
#endif

/**
 * @brief Disable interrupt.
 */
#ifndef DISABLE_INTERRUPT
#define DISABLE_INTERRUPT()                                                                                            \
    do                                                                                                                 \
    {                                                                                                                  \
        __asm volatile("DSI");                                                                                         \
        __asm volatile("NOP");                                                                                         \
    } while (0)
#endif

#ifndef NOP
#define NOP() __asm volatile("NOP")
#endif

/**
 * @brief Reset the device.
 */
#ifndef RESET
#define RESET()                                                                                                        \
    do                                                                                                                 \
    {                                                                                                                  \
        __asm volatile("RESET");                                                                                       \
        for (;;)                                                                                                       \
        { /**Empty */                                                                                                  \
        }                                                                                                              \
    } while (0)
#endif

#if 0
/* It should be noted that macro parameters that contain '#' or '##' in macro definitions will not be expanded. so we
 * need additional intermediate  macro */

#define KF_STATIC_ASSERT(x, msg)    typedef char KF_STATIC_COMBO(msg, __LINE__)[(x) ? 1 : -1]
#define KF_STATIC_COMBO(msg, line)  KF_STATIC_COMBO_(msg, line)
#define KF_STATIC_COMBO_(msg, line) ASSERT_##msg##_##line##_Failed
#define KF_STATIC_ASSERT(x, msg)    typedef char ASSERT_##msg##_Failed[(x) ? 1 : -1]
#else
/* static assert is build-in kf32-gcc */
#define KF_STATIC_ASSERT(cond, msg) _Static_assert((cond), msg)
#endif

/******************************************************************************
 *                      Type definitions
 ******************************************************************************/
typedef enum
{
    /* Generic error codes */
    /** @brief Generic operation success status */
    STATUS_OK = 0x000U,
    /** @brief Generic operation failure status */
    STATUS_ERROR = 0x001U,
    /** @brief Generic operation busy status */
    STATUS_BUSY = 0x002U,
    /** @brief Generic operation timeout status */
    STATUS_TIMEOUT = 0x003U,
    /** @brief Generic operation unsupported status */
    STATUS_UNSUPPORTED = 0x004U,
} kf_status_t;

/******************************************************************************
 *                      Export Variables
 ******************************************************************************/

/******************************************************************************
 *                      Export Functions
 ******************************************************************************/

#ifdef __cplusplus
}
#endif /*End of __cplusplus*/
#endif /*End of KF_TYPES_H*/
/* EOF */
