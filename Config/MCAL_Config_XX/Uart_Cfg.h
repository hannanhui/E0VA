/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Uart_Cfg.h
 *  @Syntax             : GNU99
 *  @Author             : ChipON AE/FAE Group
 *  @Date            : 2024-06-20
 *  @Version         : {{VersionDate}}
 *  @Description     : This document describes the C language document template.
 ******************************************************************************
 *  Copyright (C) by Shanghai ChipON Micro-Electronic Co.,Ltd
 *  All rights reserved.
 *
 *  This software is copyright protected and proprietary to
 *  Shanghai ChipON Micro-Electronic Co.,Ltd.
 *****************************************************************************/
#ifndef UART_CFG_H
#define UART_CFG_H

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
/** @brief Enables / Disables PreCompile support when there is a single configuration */
#define UART_PRECOMPILE_SUPPORT (STD_OFF)

/** @brief Enables / Disables DET development errors detection and reporting */
#define UART_DEV_ERROR_DETECT (STD_ON)

/** @brief Enables / Disables Runtime errors detection and reporting */
#define UART_RUNTIME_ERROR_DETECT (STD_OFF)

/** @brief Switches the Uart_GetVersionInfo() API ON or OFF. Support for version info API. */
#define UART_VERSION_INFO_API (STD_ON)

/** @brief Uart max receive size */
#define UART_RX_DATA_MAX_SIZE ((uint16)4096U)
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
