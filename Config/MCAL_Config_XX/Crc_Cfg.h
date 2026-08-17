/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Crc_Cfg.h
 *  @Syntax             : GNU99
 *  @Author             : ChipON AE/FAE Group
 *  @Date            : 2024-07-17
 *  @Version         : {{VersionDate}}
 *  @Description     : This document describes the C language document template.
 ******************************************************************************
 *  Copyright (C) by Shanghai ChipON Micro-Electronic Co.,Ltd
 *  All rights reserved.
 *
 *  This software is copyright protected and proprietary to
 *  Shanghai ChipON Micro-Electronic Co.,Ltd.
 *****************************************************************************/
#ifndef CRC_CFG_H
#define CRC_CFG_H

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
 * @brief Version Information API configuration
 * @implements #SWS_Crc_00017
 * @details
 * STD_ON:VersionInfo API is Enabled
 * STD_OFF:VersionInfo API is Disabled
 */
#define CRC_VERSION_INFO_API (STD_ON)

#define CRC_8_HARDWARE (0x01)
#define CRC_8_RUNTIME  (0x02)
#define CRC_8_TABLE    (0x04)
#define CRC_8_NONE     (0xFF)
/**
 * @brief Switch to select one of the available CRC 8-bit (SAE J1850) calculation methods
 */
#define CRC_8_MODE (CRC_8_HARDWARE)

#define CRC_8H2F_HARDWARE (0x01)
#define CRC_8H2F_RUNTIME  (0x02)
#define CRC_8H2F_TABLE    (0x04)
#define CRC_8H2F_NONE     (0xFF)
/**
 * @brief Switch to select one of the available CRC 8-bit (2Fh polynomial) calculation methods
 */
#define CRC_8H2F_MODE (CRC_8H2F_HARDWARE)

#define CRC_16_HARDWARE (0x01)
#define CRC_16_RUNTIME  (0x02)
#define CRC_16_TABLE    (0x04)
#define CRC_16_NONE     (0xFF)
/**
 * @brief Switch to select one of the available CRC 16-bit (CCITT) calculation methods
 */
#define CRC_16_MODE (CRC_16_HARDWARE)

#define CRC_16_ARC_HARDWARE (0x01)
#define CRC_16_ARC_RUNTIME  (0x02)
#define CRC_16_ARC_TABLE    (0x04)
#define CRC_16_ARC_NONE     (0xFF)
/**
 * @brief Switch to select one of the available CRC-16/ARC (polynomial 8005) calculation methods
 */
#define CRC_16ARC_MODE (CRC_16_ARC_HARDWARE)

#define CRC_32P4_HARDWARE (0x01)
#define CRC_32P4_RUNTIME  (0x02)
#define CRC_32P4_TABLE    (0x04)
#define CRC_32P4_NONE     (0xFF)
/**
 * @brief Switch to select one of the available CRC 32-bit E2E Profile 4 calculation methods
 */
#define CRC_32P4_MODE (CRC_32P4_HARDWARE)

#define CRC_32_HARDWARE (0x01)
#define CRC_32_RUNTIME  (0x02)
#define CRC_32_TABLE    (0x04)
#define CRC_32_NONE     (0xFF)
/**
 * @brief Switch to select one of the available CRC 32-bit (IEEE-802.3 CRC32 Ethernet Standard) calculation methods
 */
#define CRC_32_MODE (CRC_32_HARDWARE)

#define CRC_64_HARDWARE (0x01)
#define CRC_64_RUNTIME  (0x02)
#define CRC_64_TABLE    (0x04)
#define CRC_64_NONE     (0xFF)
/**
 * @brief Switch to select one of the available CRC 64-bit calculation methods
 */
#define CRC_64_MODE (CRC_64_NONE)
/******************************************************************************
 **                        Typedef  Definitions
 ******************************************************************************/

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
/* EOF */
