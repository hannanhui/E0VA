/**
 * @file        Crc_Cfg.h
 * @brief       AUTOSAR CRC - Precompile configuration file for Crc module.
 * @details     Crc driver header file, containing the Autosar API specification and
 *              other variables and functions that are exported by the Crc driver.
 * @version     1.2.0
 *
 * @addtogroup  CRC
 * @{
 */
/*====================================================================================================*
 * AngHui AUTOSAR BSW.
 *
 * Copyright(C) 2023 GuoKeAngHui Inc.
 *
 * All rights reserved.
 *
 * This file is part of AngHui AUTOSAR BSW, contains proprietary information.
 * Passing on and copying of this document, and communication of its contents
 * is not permitted without prior written authorization.
 *====================================================================================================*/

#ifndef CRC_CFG_H
#define CRC_CFG_H

#ifdef __cplusplus
extern "C" {
#endif

/*====================================================================================================*
 *                                           INCLUDE FILES
 *====================================================================================================*/

/*====================================================================================================*
 *                                  HEADER FILE VERSION INFORMATION
 *====================================================================================================*/

#define CRC_CFG_VENDOR_ID                     0U
#define CRC_CFG_AR_RELEASE_MAJOR_VERSION      4U
#define CRC_CFG_AR_RELEASE_MINOR_VERSION      2U
#define CRC_CFG_AR_RELEASE_REVISION_VERSION   2U
#define CRC_CFG_SW_MAJOR_VERSION              1U
#define CRC_CFG_SW_MINOR_VERSION              2U
#define CRC_CFG_SW_PATCH_VERSION              0U

/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/

/*====================================================================================================*
 *                                             CONSTANTS
 *====================================================================================================*/

/*====================================================================================================*
 *                                         DEFINES AND MACROS
 *====================================================================================================*/

/**
 * @brief calculation method of Crc mode.
 */
#define CRC_HARDWARE  0
#define CRC_RUNTIME   1
#define CRC_TABLE     2

/**
 * @brief calculation method of Crc mode no existent (no Autosar).
 */
#define NO_EXISTENT   3

/**
 * @brief CRC8 (SAE J1850) algorithm calculation switch.
 */
#define CRC8_ALGORITHM             STD_ON

/**
 * @brief CRC8 (2Fh polynomial) algorithm calculation switch.
 */
#define CRC8H2F_ALGORITHM          STD_ON

/**
 * @brief CRC16 (CCITT) algorithm calculation switch. 
 */
#define CRC16_ALGORITHM            STD_ON

/**
 * @brief CRC32 (Ethernet) algorithm calculation switch .
 */
#define CRC32_ALGORITHM            STD_ON

/**
 * @brief CRC32 (0xF4ACFB13 polynomial) algorithm calculation switch .
 */
#define CRC32P4_ALGORITHM          STD_ON

/**
 * @brief Switch to select one of the available CRC 8-bit (SAE J1850) calculation methods.
 */
#define CRC_8_MODE                 CRC_TABLE

/**
 * @brief Switch to select one of the available CRC 8-bit (2Fh polynomial) calculation methods.
 */
#define CRC_8H2F_MODE              CRC_TABLE

/**
 * @brief Switch to select one of the available CRC 16-bit (CCITT) calculation methods.
 */
#define CRC_16_MODE                CRC_TABLE

/**
 * @brief Switch to select one of the available CRC 32-bit (IEEE-802.3 CRC32 Ethernet Standard) 
 *        calculation methods.
 */
#define CRC_32_MODE                CRC_TABLE

/**
 * @brief Switch to select one of the available CRC 32-bit E2E Profile 4 calculation methods.
 */
#define CRC_32P4_MODE              CRC_TABLE

/*====================================================================================================*
 *                                               ENUMS
 *====================================================================================================*/

/*====================================================================================================*
 *                                   STRUCTURES AND OTHER TYPEDEFS
 *====================================================================================================*/

/*====================================================================================================*
 *                                    GLOBAL VARIABLE DECLARATIONS
 *====================================================================================================*/

/*====================================================================================================*
 *                                        FUNCTION PROTOTYPES
 *====================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif



