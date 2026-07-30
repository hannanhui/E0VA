/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      H source file                                                            */
/*   Name         :      lin_types.h                                                              */
/*   Instance     :                                                                               */
/*   Author       :      Ed                                                                       */
/*   Modify date  :      2025-12-22 14:00:05 PM                                                   */
/*   Description  :                                                                               */
/*                                                                                                */
/*                                                                                                */
/*   Compiler    :       KungFu32 IDE  [Version: V1.0.20.3]                                       */
/*   Hardware    :       ChipOn microcontroller KF32A Family [KF32A156MQV]                        */
/*   Version     :       V1.0                                                                     */
/*                                                                                                */
/*                                                                                                */
/*   All rights reserved. Distribution or duplication without previous written agreement of the   */
/*   owner prohibited.                                                                            */
/*                                                                                                */
/**************************************************************************************************/
/*
 * Copyright (c) 2015-2016, Freescale Semiconductor, Inc.
 * Copyright 2016 NXP
 * All rights reserved.
 *
 * THIS SOFTWARE IS PROVIDED BY NXP "AS IS" AND ANY EXPRESSED OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL NXP OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef LIN_TYPES_H
#define LIN_TYPES_H
#include "Type_Define.h"

#if 0
#include <stdbool.h>
/* *****************************************************************************
 * Definitions
 ******************************************************************************/
/*!
 * @brief Unsigned 8 bit integer
 * Implements : uint8_t_Class
 */
typedef unsigned char uint8_t;

/*!
 * @brief Unsigned 16 bit integer
 * Implements : uint16_t_Class
 */
typedef unsigned short int uint16_t;

/*!
 * @brief Unsigned 32 bit integer
 * Implements : uint32_t_Class
 */
typedef unsigned long uint32_t;

/*!
 * @brief 0 is false, and non-zero (>0) is true
 * Implements : BOOL_Class
 */
typedef bool BOOL;
#endif
/* *****************************************************************************
 * General
 ******************************************************************************/
/*!
 * @brief Product id structure
 * Implements : lin_product_id_t_Class
 */
typedef struct
{
    uint16_t   supplier_id;        /*!< Supplier ID */
    uint16_t   function_id;        /*!< Function ID */
    uint8_t    variant;            /*!< Variant value */
} lin_product_id_t;

#endif /* LIN_TYPES_H */


/* ****************************************************************************/
/* EOF */
/* ****************************************************************************/
