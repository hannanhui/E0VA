/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name        : dev_assert.h
 *  @Date             : 2021-12-23
 *  @Version          : {{VersionDate}}
 *  @Description      : This file provides the macro and inline function
 *                      definitions for the assert.
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
#ifndef DEV_ASSERT_H
#define DEV_ASSERT_H

#ifdef __cplusplus
extern "C" {
#endif
/******************************************************************************
 *                      QAC Warnings
 ******************************************************************************/

/******************************************************************************
 *                      Include Files
 ******************************************************************************/
#include <stdint.h>
#include <stdbool.h>
#if defined(KF_DEV_ERROR_DETECT)
#include "kflog.h"
#endif
/******************************************************************************
 *                      Macro or Inline
 ******************************************************************************/

/******************************************************************************
 *                      Type definitions
 ******************************************************************************/

/******************************************************************************
 *                      Export Variables
 ******************************************************************************/

/******************************************************************************
 *                      Export Functions
 ******************************************************************************/
#if defined(KF_DEV_ERROR_DETECT)
/**
 * @brief Implement default assert macro
 *
 * @param x
 * @param file
 * @param line
 */
static inline void DevAssert(bool x, const char *const file, uint32_t line)
{
    if (!x)
    {
        kf_printf("%s,%d\r\n", file, line);
        __asm volatile("DSI");
        __asm volatile("NOP");
        for (;;)
        {
        }
    }
    else
    {
    }
}
#define KF_DEV_ASSERT(x) DevAssert((bool)(x), __FILE__, __LINE__)
#else
/* Assert macro does nothing */
#define KF_DEV_ASSERT(x) ((void)0U)
#endif

#ifdef __cplusplus
}
#endif /*End of __cplusplus*/
#endif /*End of DEV_ASSERT_H*/
/* EOF */
