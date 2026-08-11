/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Fls.h
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
#ifndef FLS_H
#define FLS_H

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
/* PRQA S 3432 EOF #KQR003432 */
/******************************************************************************
 **                        Include Files
 ******************************************************************************/
#include "Fls_Cfg.h"
#include "Fls_Types.h"
/******************************************************************************
 **                        File Version Check
 ******************************************************************************/

/** @brief FLS Vendor ID */
#define FLS_VENDOR_ID (0xCCU)
/** @brief FLS MODULE INSTANCE ID */
#define FLS_MODULE_ID (92U)
/** @brief From AUTOSAR_TR_BSWModuleList */
#define FLS_INSTANCE_ID (0U)

/**
 * @brief fls module software version
 */
#define FLS_SW_MAJOR_VERSION (1U)
#define FLS_SW_MINOR_VERSION (0U)
#define FLS_SW_PATCH_VERSION (0U)

/**
 * @brief sector size
 *
 * @note can not changed
 */
#define FLASH_SECTOR_SIZE (0x400U)
/**
 * @brief page size
 *
 * @note can not changed
 */
#define FLASH_PAGE_SIZE (8U)
/**
 * @brief fast mode fls Fls_MainFunction once write max size
 *
 * @note can not changed
 */
#define FLASH_FAST_WRITE_MAX_SIZE (0x200U)
/******************************************************************************
 **                        Macro  Definitions
 ******************************************************************************/
/**
 * @brief Development Errors
 * @implements SWS_Fls_00004
 */
/** @brief API service called with wrong parameter */
#define FLS_E_PARAM_CONFIG ((uint8)0x01U)
/** @brief API service called with wrong parameter */
#define FLS_E_PARAM_ADDRESS ((uint8)0x02U)
/** @brief API service called with wrong parameter */
#define FLS_E_PARAM_LENGTH ((uint8)0x03U)
/** @brief API service called with wrong parameter */
#define FLS_E_PARAM_DATA ((uint8)0x04U)
/** @brief API service called without module initialization */
#define FLS_E_UNINIT ((uint8)0x05U)
/** @brief API service called with NULL pointer */
#define FLS_E_PARAM_POINTER ((uint8)0x0AU)
/** @brief already initialized */
#define FLS_E_ALREADY_INITIALIZED ((uint8)0x0BU)

/**
 * @brief Runtime Errors
 * @implements SWS_Fls_91001
 */
/** @brief API service called while driver still busy */
#define FLS_E_BUSY ((uint8)0x06U)
/** @brief Erase verification (blank check) failed */
#define FLS_E_VERIFY_ERASE_FAILED ((uint8)0x07U)
/** @brief Write verification (compare) failed */
#define FLS_E_VERIFY_WRITE_FAILED ((uint8)0x08U)
/** @brief Timeout exceeded */
#define FLS_E_TIMEOUT ((uint8)0x09U)

/**
 * @brief Transient Faults
 * @implements SWS_Fls_91002
 */
/** @brief Flash erase failed (HW) */
#define FLS_E_ERASE_FAILED ((uint8)0x01U)
/** @brief Flash write failed (HW) */
#define FLS_E_WRITE_FAILED ((uint8)0x02U)
/** @brief Flash read failed (HW) */
#define FLS_E_READ_FAILED ((uint8)0x03U)
/** @brief Flash compare failed (HW) */
#define FLS_E_COMPARE_FAILED ((uint8)0x04U)
/** Expected hardware ID not matched (see SWS_Fls_00144) */
#define FLS_E_UNEXPECTED_FLASH_ID ((uint8)0x05U)

/**
 * @brief API ID
 */
/** @brief API service ID for Fls Init function */
#define FLS_INIT_ID ((uint8)0x00U)
/** @brief API service ID for Fls Erase function */
#define FLS_ERASE_ID ((uint8)0x01U)
/** @brief API service ID for Fls Write function */
#define FLS_WRITE_ID ((uint8)0x02U)
/** @brief API service ID for Fls Cancel function */
#define FLS_CANCEL_ID ((uint8)0x03U)
/** @brief API service ID for Fls Get Status function */
#define FLS_GETSTATUS_ID ((uint8)0x04U)
/** @brief API service ID for Fls Get Job Result function */
#define FLS_GETJOBRESULT_ID ((uint8)0x05U)
/** @brief API service ID for Fls Main Function */
#define FLS_MAINFUNCTION_ID ((uint8)0x06U)
/** @brief API service ID for Fls Read function */
#define FLS_READ_ID ((uint8)0x07U)
/** @brief API service ID for Fls Compare function */
#define FLS_COMPARE_ID ((uint8)0x08U)
/** @brief API service ID for Fls Set Mode function */
#define FLS_SETMODE_ID ((uint8)0x09U)
/** @brief API service ID for Fls Get Version Info function */
#define FLS_GETVERSIONINFO_ID ((uint8)0x10U)
/** @brief API service ID for Fls Blank Check function */
#define FLS_BLANK_CHECK_ID ((uint8)0x0AU)

/******************************************************************************
 **                        Typedef  Definitions
 ******************************************************************************/

/******************************************************************************
 **                        Export Variables
 ******************************************************************************/

/******************************************************************************
 **                        Export Functions
 ******************************************************************************/
/******************************************************************************
 * Function Name   : Fls_Init
 *
 * Service ID   : 0x00
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Not reentrant
 *
 * Parameters(in)   : ConfigPtr - Pointer to flash driver configuration set.
 *
 * Parameters(inout)   :None
 *
 * Parameters(out)   :None
 *
 * Return value   :None
 *
 * Description   : Initializes the Flash Driver
 *
 ******************************************************************************/
FUNC(void, FLS_CODE) Fls_Init(P2CONST(Fls_ConfigType, FLS_VAR, FLS_APPL_CONST) ConfigPtr);

/******************************************************************************
 * Function Name   : Fls_Erase
 *
 * Service ID   : 0x01
 *
 * Sync/Async   : Asynchronous
 *
 * Reentrancy   : Not reentrant
 *
 * Parameters(in)   : TargetAddress - Target address in flash memory. This address offset will be added
 * to the flash memory base address. Min.: 0 Max.: FLS_SIZE - 1
 *
 * Parameters(in)   : Length - Number of bytes to erase Min.: 1 Max.: FLS_SIZE - Target Address
 *
 * Parameters(inout)   :None
 *
 * Parameters(out)   :None
 *
 * Return value   : Std_ReturnType
 * E_OK: erase command has been accepted
 * E_NOT_OK: erase command has not been accepted
 *
 * Description   : Erases flash sector(s)
 *
 ******************************************************************************/
FUNC(Std_ReturnType, FLS_CODE)
Fls_Erase(VAR(Fls_AddressType, AUTOMATIC) TargetAddress, VAR(Fls_LengthType, AUTOMATIC) Length);

/******************************************************************************
 * Function Name   : Fls_Write
 *
 * Service ID   : 0x02
 *
 * Sync/Async   : Asynchronous
 *
 * Reentrancy   : Not reentrant
 *
 * Parameters(in)   : TargetAddress - Target address in flash memory. This address offset will be added
 * to the flash memory base address. Min.: 0 Max.: FLS_SIZE - 1
 *
 * Parameters(in)   : SourceAddressPtr - Pointer to source data buffer
 *
 * Parameters(in)   : Length - Number of bytes to write Min.: 1 Max.: FLS_SIZE - TargetAddress
 *
 * Parameters(inout)   :None
 *
 * Parameters(out)   :None
 *
 * Return value   : Std_ReturnType
 * E_OK: write command has been accepted
 * E_NOT_OK: write command has not been accepted
 *
 * Description   : Writes one or more complete flash pages
 *
 ******************************************************************************/
FUNC(Std_ReturnType, FLS_CODE)
Fls_Write(VAR(Fls_AddressType, AUTOMATIC) TargetAddress, P2CONST(uint8, FLS_VAR, FLS_APPL_CONST) SourceAddressPtr,
          VAR(Fls_LengthType, AUTOMATIC) Length);

#if (FLS_CANCEL_API == STD_ON)
/******************************************************************************
 * Function Name   : Fls_Cancel
 *
 * Service ID   : 0x03
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Not reentrant
 *
 * Parameters(in)   :None
 *
 * Parameters(inout)   :None
 *
 * Parameters(out)   :None
 *
 * Return value   :None
 *
 * Description   : Cancels an ongoing job
 *
 ******************************************************************************/
FUNC(void, FLS_CODE) Fls_Cancel(void);
#endif

/******************************************************************************
 * Function Name   : Fls_GetStatus
 *
 * Service ID   : 0x04
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Reentrant
 *
 * Parameters(in)   :None
 *
 * Parameters(inout)   :None
 *
 * Parameters(out)   :None
 *
 * Return value   : MemIf_StatusType
 *
 * Description   : Returns the driver state.
 *
 ******************************************************************************/
FUNC(MemIf_StatusType, FLS_CODE) Fls_GetStatus(void);

#if (FLS_GET_JOB_RESULT_API == STD_ON)
/******************************************************************************
 * Function Name   : Fls_GetJobResult
 *
 * Service ID   : 0x05
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Reentrant
 *
 * Parameters(in)   :None
 *
 * Parameters(inout)   :None
 *
 * Parameters(out)   :None
 *
 * Return value   : MemIf_JobResultType
 *
 * Description   : Returns the result of the last job.
 *
 ******************************************************************************/
FUNC(MemIf_JobResultType, FLS_CODE) Fls_GetJobResult(void);
#endif

/******************************************************************************
 * Function Name   : Fls_Read
 *
 * Service ID   : 0x07
 *
 * Sync/Async   : Asynchronous
 *
 * Reentrancy   : Not reentrant
 *
 * Parameters(in)   : SourceAddress - Source address in flash memory. This address offset will be added to the flash
 *memory base address. Min.: 0 Max.: FLS_SIZE - 1
 *
 * Parameters(in)   : Length - Number of bytes to read Min.: 1 Max.: FLS_SIZE - Source Address
 *
 * Parameters(inout)   :None
 *
 * Parameters(out)   : TargetAddressPtr - Pointer to target data buffer
 *
 * Return value   : Std_ReturnType
 * E_OK: read command has been accepted
 * E_NOT_OK: read command has not been accepted
 *
 * Description   : Reads from flash memory
 *
 ******************************************************************************/
FUNC(Std_ReturnType, FLS_CODE)
Fls_Read(VAR(Fls_AddressType, AUTOMATIC) SourceAddress, P2VAR(uint8, FLS_VAR, FLS_APPL_DATA) TargetAddressPtr,
         VAR(Fls_LengthType, AUTOMATIC) Length);

#if (FLS_COMPARE_API == STD_ON)
/******************************************************************************
 * Function Name   : Fls_Compare
 *
 * Service ID   : 0x08
 *
 * Sync/Async   : Asynchronous
 *
 * Reentrancy   : Not reentrant
 *
 * Parameters(in)   : SourceAddress - Source address in flash memory. This address offset will be added to the flash
 *memory base address. Min.: 0 Max.: FLS_SIZE - 1
 *
 * Parameters(in)   : TargetAddressPtr - Pointer to target data buffer
 *
 * Parameters(in)   : Length - Number of bytes to compare Min.: 1 Max.: FLS_SIZE - Source Address
 *
 * Parameters(inout)   :None
 *
 * Parameters(out)   :None
 *
 * Return value   : Std_ReturnType
 * E_OK: compare command has been accepted
 * E_NOT_OK: compare command has not been accepted
 *
 * Description   : Compares the contents of an area of flash memory with that of an application data buffer
 *
 ******************************************************************************/
FUNC(Std_ReturnType, FLS_CODE)
Fls_Compare(VAR(Fls_AddressType, AUTOMATIC) SourceAddress, P2CONST(uint8, FLS_VAR, FLS_APPL_CONST) TargetAddressPtr,
            VAR(Fls_LengthType, AUTOMATIC) Length);
#endif

#if (FLS_SET_MODE_API == STD_ON)
/******************************************************************************
 * Function Name   : Fls_SetMode
 *
 * Service ID   : 0x09
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Not reentrant
 *
 * Parameters(in)   : Mode
 * MEMIF_MODE_FAST: Fast read access / SPI burst access.
 * MEMIF_MODE_SLOW: Slow read access / normal SPI access.
 *
 * Parameters(inout)   :None
 *
 * Parameters(out)   :None
 *
 * Return value   :None
 *
 * Description   : Sets the flash driver's operation mode
 *
 ******************************************************************************/
FUNC(void, FLS_CODE) Fls_SetMode(VAR(MemIf_ModeType, AUTOMATIC) Mode);
#endif

#if (FLS_VERSION_INFO_API == STD_ON)
/******************************************************************************
 * Function Name   : Fls_GetVersionInfo
 *
 * Service ID   : 0x10
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Reentrant
 *
 * Parameters(in)   :None
 *
 * Parameters(inout)   :None
 *
 * Parameters(out)   : VersioninfoPtr - Pointer to where to store the version information of this module.
 *
 * Return value   :None
 *
 * Description   : Returns the version information of this module
 *
 ******************************************************************************/
FUNC(void, FLS_CODE) Fls_GetVersionInfo(P2VAR(Std_VersionInfoType, FLS_VAR, FLS_APPL_DATA) VersionInfoPtr);
#endif

#if (FLS_BLANK_CHECK_API == STD_ON)
/******************************************************************************
 * Function Name   : Fls_BlankCheck
 *
 * Service ID   : 0x0a
 *
 * Sync/Async   : Asynchronous
 *
 * Reentrancy   : Not reentrant
 *
 * Parameters(in)   : TargetAddress - Address in flash memory from which the blank check should be started. Min.: 0
 *Max.: FLS_SIZE - 1
 *
 * Parameters(in)   : Length - Number of bytes to be checked for erase pattern. Min.: 1 Max.:FLS_SIZE - TargetAddress
 *
 * Parameters(inout)   :None
 *
 * Parameters(out)   :None
 *
 * Return value   : Std_ReturnType
 * E_OK: request for blank checking has been accepted by the module
 * E_NOT_OK: request for blank checking has not been accepted by the module
 *
 * Description   : The function Fls_BlankCheck shall verify whether a given memory area has been erased but not(yet)
 *programmed. The function shall limit the maximum number of checked flash cells per main function cycle to the
 *configured value FlsMaxReadNormalMode or FlsMaxReadFastMode respectively
 *
 ******************************************************************************/
FUNC(Std_ReturnType, FLS_CODE)
Fls_BlankCheck(VAR(Fls_AddressType, AUTOMATIC) TargetAddress, VAR(Fls_LengthType, AUTOMATIC) Length);
#endif

/******************************************************************************
 * Function Name   : Fls_MainFunction
 *
 * Service ID   : 0x06
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Not reentrant
 *
 * Parameters(in)   :None
 *
 * Parameters(inout)   :None
 *
 * Parameters(out)   :None
 *
 * Return value   :None
 *
 * Description   : Performs the processing of jobs
 *
 ******************************************************************************/
FUNC(void, FLS_CODE) Fls_MainFunction(void);

#ifdef __cplusplus
}
#endif

#endif
/* EOF */
