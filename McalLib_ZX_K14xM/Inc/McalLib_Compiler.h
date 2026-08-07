/**************************************************************************************************/
/**
 * @file      : McalLib_Compiler.h
 * @brief     : It provides compiler abstraction for AUTOSAR MCAL
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 2.0.0
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2025 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef MCALLIB_COMPILER_H
#define MCALLIB_COMPILER_H

/** @addtogroup  McalLib_Module
 *  @{
 */

/** @defgroup Mcal_Compiler
 *  @brief It provides compiler abstraction for AUTOSAR MCAL
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

#include "Std_Types.h"
#include "McalLib_Cfg.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */

#define MCALLIB_COMPILER_H_VENDOR_ID                   0x00B3U
#define MCALLIB_COMPILER_H_AR_RELEASE_MAJOR_VERSION    4U
#define MCALLIB_COMPILER_H_AR_RELEASE_MINOR_VERSION    6U
#define MCALLIB_COMPILER_H_AR_RELEASE_REVISION_VERSION 0U
#define MCALLIB_COMPILER_H_SW_MAJOR_VERSION            2U
#define MCALLIB_COMPILER_H_SW_MINOR_VERSION            0U
#define MCALLIB_COMPILER_H_SW_PATCH_VERSION            0U

/* Check if current file and McalLib_Cfg.h are the same vendor */
#if (MCALLIB_COMPILER_H_VENDOR_ID != MCALLIB_CFG_H_VENDOR_ID)
    #error "Vendor ID of McalLib_Compiler.h and McalLib_Cfg.h are different"
#endif

/* Check if current file and McalLib_Cfg.h are the same Autosar version */
#if ((MCALLIB_COMPILER_H_AR_RELEASE_MAJOR_VERSION != MCALLIB_CFG_H_AR_RELEASE_MAJOR_VERSION) ||    \
     (MCALLIB_COMPILER_H_AR_RELEASE_MINOR_VERSION != MCALLIB_CFG_H_AR_RELEASE_MINOR_VERSION) ||    \
     (MCALLIB_COMPILER_H_AR_RELEASE_REVISION_VERSION != MCALLIB_CFG_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of McalLib_Compiler.h and McalLib_Cfg.h are different"
#endif

/* Check if current file and McalLib_Cfg.h are the same Software version */
#if ((MCALLIB_COMPILER_H_SW_MAJOR_VERSION != MCALLIB_CFG_H_SW_MAJOR_VERSION) ||                    \
     (MCALLIB_COMPILER_H_SW_MINOR_VERSION != MCALLIB_CFG_H_SW_MINOR_VERSION) ||                    \
     (MCALLIB_COMPILER_H_SW_PATCH_VERSION != MCALLIB_CFG_H_SW_PATCH_VERSION))
    #error "Software Version of McalLib_Compiler.h and McalLib_Cfg.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if current file and Std_Types.h are the same Autosar version */
    #if((MCALLIB_COMPILER_H_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
        (MCALLIB_COMPILER_H_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version of McalLib_Compiler.h and Std_Types.h are different"
    #endif
#endif

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */

/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */

/** @} end of group Public_FunctionDeclaration */

/**************************************** IAR *********************************************/
#ifdef _IAR_C_Z20K14XM_
/**
 * @brief Compiler abstraction for specifying an interrupt handler.
 */
#define INTERRUPT_FUNC
/**
 * @brief Compiler abstraction for "Put in Quotes".
 */
#define MCAL_PUT_IN_QUOTES(x) #x

/**
 * @brief Compiler abstraction for the asm keyword.
 */
#define ASM_KEYWORD  __asm

/**
 * @brief Compiler abstraction for the asm keyword.
 */
#define ASMV_KEYWORD  __asm volatile

/**
 * @brief Compiler abstraction for the wait for interrupt instruction.
 */
#define EXECUTE_WAIT()  {\
                            ResumeAllInterrupts();\
                            ASM_KEYWORD("  wfi");\
                            SuspendAllInterrupts();\
                        } 

/**
 * @brief Compiler abstraction for the data alignment
 */
#define ALIGNED_VARS_START(sec_name, align) 
#define VAR_ALIGN(v, size)  _Pragma(MCAL_PUT_IN_QUOTES(data_alignment=size)) v;
#define ALIGNED_VARS_STOP() 

/**
 * @brief Compiler abstraction for packed
 */
#define PACKED __packed 

/**
 * @brief Compiler abstraction for MCAL Fault Injection tests 
 */
#if(MCAL_FAULT_INJECTION == STD_ON)
    #define MCAL_FAULT_INJECTION_POINT(label)   ASM_KEYWORD(MCAL_PUT_IN_QUOTES(label:))
#else
    #define MCAL_FAULT_INJECTION_POINT(label)
#endif

/**
 * @brief     Read the value of CONTROL register of the core
 *
 * @param[in] none
 *
 * @return    the value of CONTROL register
 *
 */
LOCAL_INLINE uint32 McalLib_ReadControlReg(void)
{
    uint32 res;

    ASM_KEYWORD("MRS %0,CONTROL" : "=r" (res));

    return res;
}

/**
 * @brief     Read the value of IPSR register of the core
 *
 * @param[in] none
 *
 * @return    the value of IPSR register
 *
 */
LOCAL_INLINE uint32 McalLib_ReadIpsrReg(void)
{
    uint32 res;
    ASM_KEYWORD("MRS %0,IPSR" : "=r" (res));
    return res;
}

/**
 * @brief     Read the value of PRIMASK register of the core
 *
 * @param[in] none
 *
 * @return    the value of PRIMASK register
 *
 */
LOCAL_INLINE uint32 McalLib_ReadPriMaskReg(void)
{
    uint32 res;
    ASMV_KEYWORD("MRS %0,PRIMASK" : "=r" (res));
    return res;
}

/**************************************** ARM clang *********************************************/
#elif defined _ARMCLANG_C_Z20K14XM_
/**
 * @brief Compiler abstraction for specifying an interrupt handler.
 */
#define INTERRUPT_FUNC
/**
 * @brief Compiler abstraction for "Put in Quotes".
 */
#define MCAL_PUT_IN_QUOTES(x) #x
 
/**
 * @brief Compiler abstraction for the asm keyword.
 */    
#define ASM_KEYWORD  __asm

/**
 * @brief Compiler abstraction for the asm keyword.
 */
#define ASMV_KEYWORD  __asm volatile

/**
 * @brief Compiler abstraction for the wait for interrupt instruction.
 */
#define EXECUTE_WAIT()  {\
                            ResumeAllInterrupts();\
                            ASM_KEYWORD("  wfi");\
                            SuspendAllInterrupts();\
                        } 

/**
 * @brief Compiler abstraction for the data alignment
 */
#define ALIGNED_VARS_START(sec_name, align) 
#define VAR_ALIGN(v, size) __attribute__(( aligned(size) )) v;
#define ALIGNED_VARS_STOP() 

/**
 * @brief Compiler abstraction for packed
 */
#define PACKED __attribute__((__packed__))

/**
 * @brief Compiler abstraction for MCAL Fault Injection tests 
 */
#if(MCAL_FAULT_INJECTION == STD_ON) 
    #define MCAL_FAULT_INJECTION_POINT(label)   ASM_KEYWORD(MCAL_PUT_IN_QUOTES(label:))
#else
    #define MCAL_FAULT_INJECTION_POINT(label)
#endif

/**
 * @brief     Read the value of CONTROL register of the core
 *
 * @param[in] none
 *
 * @return    the value of CONTROL register
 *
 */
LOCAL_INLINE uint32 McalLib_ReadControlReg(void)
{
    uint32 res;
    
    ASM_KEYWORD("MRS %0,CONTROL" : "=r" (res));
    
    return res;
}

/**
 * @brief     Read the value of IPSR register of the core
 *
 * @param[in] none
 *
 * @return    the value of IPSR register
 *
 */
LOCAL_INLINE uint32 McalLib_ReadIpsrReg(void)
{
    uint32 res;
    ASM_KEYWORD("MRS %0,IPSR" : "=r" (res));
    return res;
}

/**
 * @brief     Read the value of PRIMASK register of the core
 *
 * @param[in] none
 *
 * @return    the value of PRIMASK register
 *
 */
LOCAL_INLINE uint32 McalLib_ReadPriMaskReg(void)
{
    uint32 res;
    ASMV_KEYWORD("MRS %0,PRIMASK" : "=r" (res));
    return res;
}

/************************************* Green Hills ******************************************/
#elif defined(_GHS_C_Z20K14XM_)
/**
 * @brief Compiler abstraction for specifying an interrupt handler.
 */
#define INTERRUPT_FUNC
/**
 * @brief Compiler abstraction for "Put in Quotes".
 */
#define MCAL_PUT_IN_QUOTES(x) #x
 
/**
 * @brief Compiler abstraction for the asm keyword.
 */    
#define ASM_KEYWORD  __asm

/**
 * @brief Compiler abstraction for the asm keyword.
 */
#define ASMV_KEYWORD  __asm volatile

/**
 * @brief Compiler abstraction for the wait for interrupt instruction.
 */
#define EXECUTE_WAIT()  {\
                            ResumeAllInterrupts();\
                            ASM_KEYWORD("  wfi");\
                            SuspendAllInterrupts();\
                        } 

/**
 * @brief Compiler abstraction for the data alignment
 */
#define ALIGNED_VARS_START(sec_name, align) 
#define VAR_ALIGN(v, size) __attribute__(( aligned(size) )) v;
#define ALIGNED_VARS_STOP() 

/**
 * @brief Compiler abstraction for packed
 */
#define PACKED __packed

/**
 * @brief Compiler abstraction for MCAL Fault Injection tests 
 */
#if(MCAL_FAULT_INJECTION == STD_ON)
    #define MCAL_FAULT_INJECTION_POINT(label)   ASM_KEYWORD(MCAL_PUT_IN_QUOTES(label:))
#else
    #define MCAL_FAULT_INJECTION_POINT(label)
#endif

/**
 * @brief     Read the value of CONTROL register of the core
 *
 * @param[in] none
 *
 * @return    the value of CONTROL register
 *
 */
LOCAL_INLINE uint32 McalLib_ReadControlReg(void)
{
    uint32 res;
    
    ASM_KEYWORD("MRS %0,CONTROL" : "=r" (res));
    
    return res;
}

/**
 * @brief     Read the value of IPSR register of the core
 *
 * @param[in] none
 *
 * @return    the value of IPSR register
 *
 */
LOCAL_INLINE uint32 McalLib_ReadIpsrReg(void)
{
    uint32 res;
    ASM_KEYWORD("MRS %0,IPSR" : "=r" (res));
    return res;
}

/**
 * @brief     Read the value of PRIMASK register of the core
 *
 * @param[in] none
 *
 * @return    the value of PRIMASK register
 *
 */
LOCAL_INLINE uint32 McalLib_ReadPriMaskReg(void)
{
    uint32 res;
    ASMV_KEYWORD("MRS %0,PRIMASK" : "=r" (res));
    return res;
}

#else
    #error "Unsupported compiler."
#endif /* _IAR_C_Z20K14XM_ */

#ifdef __cplusplus
}
#endif

/** @} end of group Mcal_Compiler */

/** @} end of group McalLib_Module */

#endif /* MCALLIB_COMPILER_H */
