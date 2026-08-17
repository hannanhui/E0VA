/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Compiler.h
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
#ifndef COMPILER_H
#define COMPILER_H

/******************************************************************************
 *                      Include Files *
 ******************************************************************************/
#include "Compiler_Cfg.h"

/******************************************************************************
 *                      Macro definitions *
 ******************************************************************************/
/**
 * @brief AUTOMATIC used for the declaration of local pointers
 * @implements #SWS_COMPILER_00046
 */
#define AUTOMATIC
/**
 * @brief CONSTANT used for the declaration of CONST pointers
 * @implements #SWS_COMPILER_00046
 */
#define CONSTANT
/**
 * @brief This memory class shall be used within type definitions, where no
 * memory qualifier can be specified. This can be necessary for defining
 * pointer types, with e.g. P2VAR, where the macros require two parameters.
 * First parameter can be specified in the type definition (distance to the
 * memory location referenced by the pointer), but the second one (memory
 * allocation of the pointer itself) cannot be defined at this time. Hence,
 * memory class TYPEDEF shall be applied.
 * @implements #SWS_COMPILER_00059
 */
#define TYPEDEF

#ifndef NULL_PTR
#define NULL_PTR ((void *)0)
#endif

/**
 * @brief
 *
 * @implements #SWS_COMPILER_00057
 */
#ifdef _CHIPON_GCC_KF32_
#ifdef KF_FORCE_INLINE
#define INLINE       __attribute__((always_inline)) inline
#define LOCAL_INLINE __attribute__((always_inline)) static inline
#else
/* PRQA S 3414 1 #KQR003414 */
#define INLINE       inline
#define LOCAL_INLINE static inline
#endif
#define INTERRUPT_FUNC __attribute__((interrupt))
#else
#define INLINE         inline
#define LOCAL_INLINE   static inline
#define INTERRUPT_FUNC __interrupt
#endif

/* The compiler abstraction shall define the FUNC macro for the declaration and
   definition of functions, that ensures correct syntax of function
   declarations as required by a specific compiler. - used for API functions
   rettype      : return type of the function
   memclass     : classification of the function itself
 */
#define FUNC(type, memclass) type

/* The compiler abstraction shall define the FUNC_P2CONST macro for the
   declaration and definition of functions returning a pointer to a
   constant. This shall ensure the correct syntax of function declarations
   as required by a specific compiler.
   rettype      : return type of the function
   ptrclass     : defines the classification of the pointer's distance
   memclass     : classification of the function itself
 */
/* PRQA S 3409 ++ #KQR003409 */
#define FUNC_P2CONST(rettype, ptrclass, memclass) const ptrclass rettype *memclass

/* The compiler abstraction shall define the FUNC_P2VAR macro for the
   declaration and definition of functions returning a pointer to a variable.
   This shall ensure the correct syntax of function declarations as required by
   a specific compiler. rettype      : return type of the function ptrclass :
   defines the classification of the pointer's distance memclass     :
   classification of the function itself
*/
#define FUNC_P2VAR(rettype, ptrclass, memclass) ptrclass rettype *memclass

/* Pointer to variable data
   ptrtype      : type of the referenced data
   memclass     : classification of the pointer's variable itself
   ptrclass     : defines the classification of the pointer's distance
 */
#define P2VAR(ptrtype, memclass, ptrclass) ptrtype *

/**
 * @brief   Pointer to constant data
 *
 * @param   ptrtype      : type of the referenced data
 * @param   memclass     : classification of the pointer's variable itself
 * @param   ptrclass     : defines the classification of the pointer's distance
 */
#define P2CONST(ptrtype, memclass, ptrclass) const ptrtype *

#define P2VOLATILE(ptrtype, memclass, ptrclass) volatile ptrtype *

#define VOLATILE(ptrtype, memclass, ptrclass) volatile ptrtype

/* Const pointer to variable data
   ptrtype      : type of the referenced data
   memclass     : classification of the pointer's variable itself
   ptrclass     : defines the classification of the pointer's distance
 */
#define CONSTP2VAR(ptrtype, memclass, ptrclass) ptrtype *const

/* Const pointer to constant data
   ptrtype      : type of the referenced data
   memclass     : classification of the pointer's variable itself
   ptrclass     : defines the classification of the pointer's distance
 */
#define CONSTP2CONST(ptrtype, memclass, ptrclass) const ptrtype *const

/* Type definition of pointers to functions
   rettype      : return type of the function
   ptrclass     : defines the classification of the pointer's distance
   fctname      : function name respectively name of the defined type
 */
#define P2FUNC(rettype, ptrclass, fctname) rettype(*fctname)

/* Type definition of const pointers to functions
   rettype      : return type of the function
   ptrclass     : defines the classification of the pointer's distance
   fctname      : function name respectively name of the defined type
 */
#define CONSTP2FUNC(rettype, ptrclass, fctname) rettype(*const fctname)

/* The compiler abstraction shall define the CONST macro for the declaration
   and definition of constants.
   consttype    : type of the constant
   memclass     : classification of the constant itself
*/
#define CONST(type, memclass) const type

/* The compiler abstraction shall define the VAR macro for the declaration
   and definition of variables.
   type        type of the variable
   memclass    classification of the variable
 */
#define VAR(type, memclass) type

#endif
