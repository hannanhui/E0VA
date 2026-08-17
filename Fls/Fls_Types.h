/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Fls_Types.h
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
#ifndef FLS_TYPES_H
#define FLS_TYPES_H

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
/* PRQA S 3205 EOF #KQR003205 */
/* PRQA S 3432 EOF #KQR003432 */
/******************************************************************************
 **                        Include Files
 ******************************************************************************/
#include "Compiler.h"
#include "Fls_Cfg.h"
#include "MemIf_Types.h"
#include "Platform_Types.h"

/******************************************************************************
 **                        File Version Check
 ******************************************************************************/

/******************************************************************************
 **                        Macro  Definitions
 ******************************************************************************/

/******************************************************************************
 **                        Typedef  Definitions
 ******************************************************************************/
typedef uint32 Fls_InterFuncType;
typedef uint32 Fls_DataBusWidthType;
typedef uint32 Fls_SectorIdType;
typedef uint64 Fls_DataAccWidthType;

/**
 * @brief Logical sector index.
 */
typedef uint32 Fls_SectorIndexType;

/**
 * @brief Used as address offset from the configured flash base address to access a certain flash memory area.
 * @implements #SWS_Fls_00369
 */
typedef uint32 Fls_AddressType;

/**
 * @brief Specifies the number of bytes to read/write/erase/compare.
 * @implements #SWS_Fls_00370
 */
typedef uint32 Fls_LengthType;

/**
 * @brief Fls Sector Count Type
 */
typedef uint32 Fls_SectorCountType;

/**
 * @brief Pointer type of Fls_AC_Callback function
 */
typedef P2FUNC(void, FLS_CODE, Fls_ACCallbackPtrType)(void);

/**
 * @brief Fls Job End Notification Pointer Type
 */
typedef P2FUNC(void, FLS_CODE, Fls_NotificationPtrType)(void);

/**
 * @brief feed dog operate
 */
typedef P2FUNC(void, FLS_CODE, Fls_FeedWdgProcessPtrType)(void);

/**
 * @brief Define pointer type of erase function
 */
typedef P2FUNC(Fls_InterFuncType, FLS_CODE,
               Fls_ErasePtrType)(volatile const uint32 *const KeyPtr, volatile uint32 WriteAddr);

/**
 * @brief Define pointer type of write function
 */
typedef P2FUNC(Fls_InterFuncType, FLS_CODE,
               Fls_WritePtrType)(volatile const uint32 *const KeyPtr, uint32 WriteAddr, const uint32 *const WriteData);

/**
 * @brief Type of job currently executed by Fls_MainFunction.
 */
typedef enum
{
    /** @brief erase one or more complete flash sectors */
    FLS_JOB_ERASE,
    /** @brief write one or more complete flash pages */
    FLS_JOB_WRITE,
    /** @brief read one or more bytes from flash memory */
    FLS_JOB_READ,
    /** @brief compare data buffer with content of flash memory */
    FLS_JOB_COMPARE,
    /** @brief check content of erased flash memory area */
    FLS_JOB_BLANK_CHECK
} Fls_JobOperateType;

/**
 * @brief flash operate result
 */
typedef enum
{
    /** @brief internal flash operation succeeded */
    FLS_INTER_E_OK,
    /** @brief internal flash operation failed */
    FLS_INTER_E_FAILED,
    /**  @brief internal flash data buffer doesn't match with content of flash memory */
    FLS_INTER_E_INCONSISTENT,
    /** @brief internal flash operation is pending */
    FLS_INTER_E_PENDING
} Fls_InterReturnType;

/**
 * @brief A pointer to such a structure is provided to the flash driver initialization routine for configuration of the
 * driver and flash memory hardware.
 * @implements #SWS_Fls_00368
 */
/* PRQA S 3630 ++ #KQR003630 */
typedef struct
{
    /** @brief pointer to erase function */
    Fls_ErasePtrType EraseProcessPtr;
    /** @brief pointer to write page function */
    Fls_WritePtrType WritePageProcessPtr;
    /** @brief pointer to write sector function */
    Fls_WritePtrType WriteSectorProcessPtr;
    /** @brief function pointer for JobEndNotification */
    Fls_NotificationPtrType JobEndNotificationPtr;
    /** @brief function pointer for JobErrorNotification */
    Fls_NotificationPtrType JobErrorNotificationPtr;
    /** @brief function pointer for StartFlashAccessNotification */
    Fls_NotificationPtrType StartFlashAccessNotificationPtr;
    /** @brief function pointer for FinishedFlashAccessNotification */
    Fls_NotificationPtrType FinishedFlashAccessNotificationPtr;
    /** @brief function pointer for feed dog */
    Fls_FeedWdgProcessPtrType FeedDogProcessPtr;
    /** @brief default fls device mode */
    MemIf_ModeType DefaultMode;
    /** @brief fast read size */
    Fls_LengthType ReadFastSize;
    /** @brief fast write size */
    Fls_LengthType WriteFastSize;
    /** @brief normal read size */
    Fls_LengthType ReadNormalSize;
    /** @brief normal write size */
    Fls_LengthType WriteNormalSize;
    /** @brief physical start address */
    Fls_LengthType PhysicalStartAddr;
    /** @brief flash total size */
    Fls_LengthType FlashTotalSize;
} Fls_ConfigType;
/* PRQA S 3630 -- #KQR003630 */
/******************************************************************************
 **                        Export Variables
 ******************************************************************************/

/******************************************************************************
 **                        Export Functions
 ******************************************************************************/

#ifdef __cplusplus
}
#endif

#endif
