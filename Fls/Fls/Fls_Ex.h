/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Fls_Ex.h
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
#ifndef FLS_EX_H
#define FLS_EX_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 **                        MISRA-C Rules Violations
 ******************************************************************************/
/**
 * @page misra_violations MISRA-C:2004 violations
 *
 * @section
 */

/******************************************************************************
 **                        QAC Warnings
 ******************************************************************************/
/**
 * @page QAC Warnings
 *
 */

/******************************************************************************
 **                        Include Files
 ******************************************************************************/
#include "Std_Types.h"
/******************************************************************************
 **                        File Version Check
 ******************************************************************************/

/******************************************************************************
 **                        Macro  Definitions
 ******************************************************************************/

/******************************************************************************
 **                        Typedef  Definitions
 ******************************************************************************/
/**
 * @brief Whether to enable AB swap
 */
#define FLS_FEATURE_AB_SWAP_ENABLE (STD_OFF)

/**
 * @brief DFLASH function enable configuration
 */
#define FLS_DFLASH_FUNCTION_ENABLE (STD_ON)

/**
 * @brief PFLASH function enable configuration
 */
#define FLS_PFLASH_FUNCTION_ENABLE (STD_ON)
/******************************************************************************
 **                        Export Variables
 ******************************************************************************/

/******************************************************************************
 **                        Export Functions
 ******************************************************************************/

/******************************************************************************
 * Function Name   : Fls_Ex_Read
 *
 * Service ID   :
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Not reentrant
 *
 * Parameters(in)   : SourceAddress Source address in flash memory.flash absolute address
 *
 * Parameters(in)   : TargetAddressPtr Pointer to target data buffer
 *
 * Parameters(in)   : Length Number of bytes to read
 *
 * Parameters(inout)   :
 *
 * Parameters(out)   :
 *
 * Return value   : Std_ReturnType
 *
 * Description   : flash extended Reads from flash memory
 *
 ******************************************************************************/
Std_ReturnType Fls_Ex_Read(const uint32 SourceAddress, uint8 *TargetAddressPtr, const uint32 Length);

/******************************************************************************
 * Function Name   : Fls_Ex_PFlashWrite
 *
 * Service ID   :
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Not reentrant
 *
 * Parameters(in)   : TargetAddress Target address in flash memory.flash absolute address
 *
 * Parameters(in)   : SourceAddressPtr Pointer to source data buffer
 *
 * Parameters(in)   : Length Number of bytes to write
 *
 * Parameters(inout)   :
 *
 * Parameters(out)   :
 *
 * Return value   : Std_ReturnType
 *
 * Description   : PFlash extended Writes one or more complete flash pages.
 *
 ******************************************************************************/
#if (FLS_PFLASH_FUNCTION_ENABLE == STD_ON)
Std_ReturnType Fls_Ex_PFlashWrite(const uint32 TargetAddress, const uint8 *SourceAddressPtr, const uint32 Length);
#endif

/******************************************************************************
 * Function Name   : Fls_Ex_PFlashErase
 *
 * Service ID   :
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Not reentrant
 *
 * Parameters(in)   : TargetAddress Target address in flash memory.flash absolute address
 *
 * Parameters(in)   : Length Number of bytes to erase
 *
 * Parameters(inout)   :
 *
 * Parameters(out)   :
 *
 * Return value   : Std_ReturnType
 *
 * Description   : PFlash extended Erases flash sector(s).
 *
 ******************************************************************************/
#if (FLS_PFLASH_FUNCTION_ENABLE == STD_ON)
Std_ReturnType Fls_Ex_PFlashErase(const uint32 TargetAddress, const uint32 Length);
#endif

/******************************************************************************
 * Function Name   : Fls_Ex_DFlashWrite
 *
 * Service ID   :
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Not reentrant
 *
 * Parameters(in)   : TargetAddress Target address in flash memory.flash absolute address
 *
 * Parameters(in)   : SourceAddressPtr Pointer to source data buffer
 *
 * Parameters(in)   : Length Number of bytes to write
 *
 * Parameters(inout)   :
 *
 * Parameters(out)   :
 *
 * Return value   : Std_ReturnType
 *
 * Description   : DFlash extended Writes one or more complete flash pages.
 *
 ******************************************************************************/
#if (FLS_DFLASH_FUNCTION_ENABLE == STD_ON)
Std_ReturnType Fls_Ex_DFlashWrite(const uint32 TargetAddress, const uint8 *SourceAddressPtr, const uint32 Length);
#endif

/******************************************************************************
 * Function Name   : Fls_Ex_PFlashErase
 *
 * Service ID   :
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Not reentrant
 *
 * Parameters(in)   : TargetAddress Target address in flash memory.flash absolute address
 *
 * Parameters(in)   : Length Number of bytes to erase
 *
 * Parameters(inout)   :
 *
 * Parameters(out)   :
 *
 * Return value   : Std_ReturnType
 *
 * Description   : DFlash extended Erases flash sector(s).
 *
 ******************************************************************************/
#if (FLS_DFLASH_FUNCTION_ENABLE == STD_ON)
Std_ReturnType Fls_Ex_DFlashErase(const uint32 TargetAddress, const uint32 Length);
#endif

/******************************************************************************
 * Function Name   : Fls_Ex_Init
 *
 * Service ID   :
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Not reentrant
 *
 * Parameters(in)   : None
 *
 * Parameters(in)   : None
 *
 * Parameters(inout)   :
 *
 * Parameters(out)   :
 *
 * Return value   : None
 *
 * Description   : Initialize A/B partition swap function
 *
 ******************************************************************************/
void Fls_Ex_Init(void);

#ifdef __cplusplus
}
#endif

#endif
/* EOF */
