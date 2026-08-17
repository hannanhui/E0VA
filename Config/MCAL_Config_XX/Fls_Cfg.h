/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Fls_Cfg.h
 *  @Syntax             : GNU99
 *  @Author             : ChipON AE/FAE Group
 *  @Date            : 2026/3/31 17:03:45
 *  @Version         : V1.0
 *  @Description     : This document describes the C language document template.
 ******************************************************************************
 *  Copyright (C) by Shanghai ChipON Micro-Electronic Co.,Ltd
 *  All rights reserved.
 *
 *  This software is copyright protected and proprietary to
 *  Shanghai ChipON Micro-Electronic Co.,Ltd.
 *****************************************************************************/
#ifndef FLS_CFG_H
#define FLS_CFG_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 **                        Include Files
 ******************************************************************************/

/******************************************************************************
 **                        File Version Check
 ******************************************************************************/

/******************************************************************************
 **                        Macro  Definitions
 ******************************************************************************/
/**
 * @brief fixed config
 */
#define FLS_PRECOMPILE_SUPPORT (STD_ON)

/**
 * @brief The flash driver shall load the flash access code to RAM whenever an erase or write job is started and unload
 * (overwrite) it after that job has been finished or canceled.
 * @implements #ECUC_Fls_00284
 * @details not support
 */
#define FLS_AC_LOAD_ON_JOB_START (STD_OFF)

/**
 * @brief Compile switch to enable and disable the Fls_Cancel function.
 * true: API supported / function provided. false: API not supported / function not provided
 * @implements #ECUC_Fls_00285
 * @details not support
 */
#define FLS_CANCEL_API (STD_OFF)

/**
 * @brief Compile switch to enable and disable the Fls_Compare function.
 * true: API supported / function provided. false: API not supported / function not provided
 * @implements #ECUC_Fls_00286
 */
#define FLS_COMPARE_API (STD_ON)

/**
 * @brief Switches the development error detection and notification on or off.
 * true: detection and notification is enabled.
 * false: detection and notification is disabled.
 * @implements #ECUC_Fls_00287
 */
#define FLS_DEV_ERROR_DETECT (STD_OFF)

/**
 * @brief Index of the driver, used by FEE.
 * @implements #ECUC_Fls_00288
 */
#define FLS_DRIVER_INDEX (0x00U)

/**
 * @brief Compile switch to enable and disable the Fls_GetJobResult function.
 * true: API supported / function provided. false: API not supported / function not provided
 * @implements #ECUC_Fls_00289
 */
#define FLS_GET_JOB_RESULT_API (STD_ON)

/**
 * @brief Compile switch to enable and disable the Fls_GetStatus function.
 * true: API supported / function provided. false: API not supported / function not provided
 * @implements #ECUC_Fls_00290
 */
#define FLS_GET_STATUS_API (STD_ON)

/**
 * @brief Compile switch to enable and disable the Fls_SetMode function.
 * true: API supported / function provided. false: API not supported / function not provided
 * @implements #ECUC_Fls_00291
 */
#define FLS_SET_MODE_API (STD_ON)

/**
 * @brief Pre-processor switch to enable / disable the API to read out the modules version information.
 * true: Version info API enabled. false: Version info API disabled.
 * @implements #ECUC_Fls_00293
 */
#define FLS_VERSION_INFO_API (STD_ON)

/**
 * @brief Compile switch to enable/disable the Fls_BlankCheck function.
 * true: API supported / function provided. false: API not supported / function not provided
 * @implements #ECUC_Fls_00319
 */
#define FLS_BLANK_CHECK_API (STD_ON)

/**
 * @brief Compile switch to enable write verification.
 * true: written data is compared directly after write. false: written date is not compared directly after write.
 * @implements #ECUC_Fls_00320
 */
#define FLS_WRITE_VERIFICATION_ENABLED (STD_ON)

/**
 * @brief flash operate running check
 */
#define FLS_RUNTIME_ERROR_DETECT (STD_ON)

/**
 * @brief Pre-write verification of whether the flash has been erased
 */
#define FLS_WRITE_BLANK_CHECK (STD_ON)

/**
 * @brief Compile switch to enable erase verification.
 */
#define FLS_ERASE_BLANK_CHECK (STD_ON)

/**
 * @brief Timeout enabled status
 */
#define FLS_TIMEOUT_ENABLED (STD_ON)

/**
 * @brief Job processing triggered by hardware interrupt.
 *
 * @details not support
 */
#define FLS_USE_INTERRUPTS (STD_OFF)

/**
 * @brief Timeout value for Erase and Write operation - internal flash operations
 */
#define FLS_SYNC_ERASE_TIMEOUT_VALUE (0xFFU)
#define FLS_ABT_TIMEOUT_VALUE        (0xFFU)

/**
 * @brief The min address of flash can be operated
 *
 * @note The minimum address unit is in bytes
 * @note "(1u << 10u)" means 1KB
 */
#define FLS_MIN_OPERABLE_ADDRESS (1U << 10U)

/**
 * @brief flash base address
 */
#define FLASH_BASE_ADDR (0x0U) //0x00200000U

/**
 * @brief The total amount of flash memory in bytes (see also SWS_Fls_00208 and SWS_Fls_00209).
 * This parameter in conjunction with FLS_BASE_ADDRESS defines the upper boundary
 * for read / write / erase and compare jobs.
 *
 * @note The size must be an integer multiple of the sector(2048)
 *
 * @details Page Size 16Byte;Sector Size 2048Byte;
 *
 * @implements #ECUC_Fls_00170
 */
#define FLASH_TOTAL_SIZE (32U * 1024U)

/**
 * @brief Position in RAM, to which the erase flash access code has to be loaded.
 *
 * @details not supported
 */
#define FLS_AC_LOCATION_ERASE (0x0U)

/**
 * @brief Position in RAM, to which the write flash access code has to be loaded.
 *
 * @details not supported
 */
#define FLS_AC_LOCATION_WRITE (0x0U)

/**
 * @brief Number of bytes in RAM needed for the erase flash access code.
 *
 * @details not supported
 */
#define FLS_AC_SIZE_ERASE (0x0U)

/**
 * @brief Number of bytes in RAM needed for the write flash access code.
 *
 * @details not supported
 */
#define FLS_AC_SIZE_WRITE (0x0U)

/**
 * @brief The contents of an erased flash memory cell.
 *
 * @details not supported
 */
#define FLS_ERASED_DEFAULT_VALUE (0xFFU)

/**
 * @brief Maximum time to erase one complete flash sector.
 *
 * @details not supported
 */
#define FLS_ERASE_TIME (5.0F)

/**
 * @brief Unique identifier of the hardware device that is expected by this driver (the device for which this driver has
 * been implemented).
 *
 * @details not supported
 */
#define FLS_EXPECTED_HW_ID (0x0U)

/**
 * @brief Number of erase cycles specified for the flash device (usually given in the device data sheet).
 *
 * @details not supported
 */
#define FLS_SPECIFIED_ERASE_CYCLES (0x0U)

/**
 * @brief Maximum time to program one complete flash page.
 *
 * @details not supported
 */
#define FLS_WRITE_TIME (0.04F)
/******************************************************************************
 **                        Typedef  Definitions
 ******************************************************************************/

/******************************************************************************
 **                        Export Variables
 ******************************************************************************/

/******************************************************************************
 **                        Export Functions
 ******************************************************************************/

/* Assertion: Use to check config parameter  */
//#if (FLASH_BASE_ADDR < FLS_MIN_OPERABLE_ADDRESS)
//#error "Fls_Cfg.h :Flash The base address must be greater than the minimum operating address"
//#endif
#if ((FLASH_BASE_ADDR + FLASH_TOTAL_SIZE) > 0x208000U)
#error                                                                                                                 \
  "Fls_Cfg.h :The flash configuration base address(FLASH_BASE_ADDR) plus the flash size(FLASH_TOTAL_SIZE) must be smaller than the total flash value(2M)"
#endif
#ifdef __cplusplus
}
#endif

#endif
/* EOF */
