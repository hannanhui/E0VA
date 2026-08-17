/*******************************************************************************
**                  Shanghai ChipON Micro-Electronic Co.,Ltd **
********************************************************************************
*  @File Name       : Platform_Types.h
*  @Syntax          : GNU99
*  @Author          : ChipON AE/FAE Group
*  @Date            : 2025-08-29
*  @Version         : V1.0.0_SF
*  @Description     : This document describes the C language document template.
********************************************************************************
*  Copyright (C) by Shanghai ChipON Micro-Electronic Co.,Ltd
*  All rights reserved.
*
*  This software is copyright protected and proprietary to
*  Shanghai ChipON Micro-Electronic Co.,Ltd.
********************************************************************************
*                        REVISION HISTORY
********************************************************************************
*  |Date        |Version  |Author       |Description
********************************************************************************
*  |2025-08-29  |V1.0     |Zhai Yu     |Initial Version
*******************************************************************************/
#ifndef PLATFORM_TYPES_H
#define PLATFORM_TYPES_H

/******************************************************************************
 *                      Type definitions                                       *
 ******************************************************************************/
typedef signed char sint8; /* -128 .. +127                   */
/* PRQA S 0631 1 #KQR000631 */
typedef unsigned char uint8; /* 0 .. 255                       */
/* PRQA S 0631 1 #KQR000631 */
typedef signed short sint16; /* -32768 .. +32767               */
/* PRQA S 0631 1 #KQR000631 */
typedef unsigned short uint16; /*  0 .. 65535                    */
typedef signed long    sint32; /* -2147483648 .. +2147483647     */
/* PRQA S 0631,0627 1 #KQR100016 */
typedef unsigned long      uint32; /*  0 .. 4294967295               */
typedef unsigned long long uint64;
typedef signed long long   sint64;

typedef unsigned long uint8_least;  /* At least 8 bit                 */
typedef unsigned long uint16_least; /* At least 16 bit                */
typedef unsigned long uint32_least; /* At least 32 bit                */
typedef signed long   sint8_least;  /* At least 7 bit + 1 bit sign    */
typedef signed long   sint16_least; /* At least 15 bit + 1 bit sign   */
typedef signed long   sint32_least; /* At least 31 bit + 1 bit sign   */

typedef float  float32;
typedef double float64;

typedef unsigned char boolean;

/******************************************************************************
 *                      Symbol definitions *
 ******************************************************************************/

/**
 * @brief CPU types pre-definitions
 *
 */
#define CPU_TYPE_8  8
#define CPU_TYPE_16 16
#define CPU_TYPE_32 32
#define CPU_TYPE_64 64

/**
 * @brief CPU Bit Order
 *
 */
#define MSB_FIRST 0 /** @brief Big endian bit ordering        */
#define LSB_FIRST 1 /** @brief Little endian bit ordering     */

/**
 * @brief CPU Byte Order
 *
 */
#define HIGH_BYTE_FIRST 0 /** @brief Big endian byte ordering       */
#define LOW_BYTE_FIRST  1 /** @brief Little endian byte ordering    */

/**
 * @brief KungFu Core is 32bits
 *
 */
#define CPU_TYPE (CPU_TYPE_32)

/**
 * @brief KungFu Core is LSB, Inter Format
 *
 */
#define CPU_BIT_ORDER  (LSB_FIRST)
#define CPU_BYTE_ORDER (LOW_BYTE_FIRST)

#ifndef TRUE /* conditional check */
#define TRUE 1U
#else
#if (TRUE != 1U)
#error "TRUE is not defined as non-zero"
#endif
#endif

#ifndef FALSE /* conditional check */
#define FALSE 0U
#else
#if (FALSE != 0U)
#error "FALSE is not defined as zero"
#endif
#endif

#endif
