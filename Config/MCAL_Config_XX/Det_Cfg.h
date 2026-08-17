/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Det_Cfg.h
 *  @Syntax             : GNU99
 *  @Author             : ChipON AE/FAE Group
 *  @Date            : 2022-09-10
 *  @Version         : {{VersionDate}}
 *  @Description     : This document describes the C language document template.
 ******************************************************************************
 *  Copyright (C) by Shanghai ChipON Micro-Electronic Co.,Ltd
 *  All rights reserved.
 *
 *  This software is copyright protected and proprietary to
 *  Shanghai ChipON Micro-Electronic Co.,Ltd.
 *****************************************************************************/

#ifndef DET_CFG_H
#define DET_CFG_H

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
 * @brief Preprocessor switch to enable/disable the API to read driver version information
 * @details
 * STD_ON:VersionInfo API is Enabled
 * STD_OFF:VersionInfo API is Disabled
 */
#define DET_VERSION_INFO_API (STD_ON)

/**
 * @brief Error reporting switch to enable/disable the API to determine if an error is reported
 */
#define DET_DEV_ERROR_DETECT (STD_ON)

/**
 * @brief Configuration status of transient fault callout
 */
#define DET_CFG_TRANSIENTCALLOUT_SUPPORTED (STD_OFF)

/**
 * @brief Configuration status of runtime error callout
 */
#define DET_CFG_RUNTIMECALLOUT_SUPPORTED (STD_OFF)

/**
 * @brief Configuration status of Error Hooks
 */
#define DET_CFG_HOOKCOUNT (0U)

/**
 * @brief Configuration status of reset Buffer
 */
#define DET_CFG_RSSETBUFFER (STD_OFF)

/**
 * @brief Configuration status of Error Buffer
 */
#define DET_CFG_ERRORBUFFER_ENABLE    (STD_ON)
#define DET_CFG_ERRORBUFFER_SUPPORTED (STD_ON)

/**
 * @brief Preprocessor switch to enable/disable the API to read driver version information
 * @details
 * STD_ON:VersionInfo API is Enabled
 * STD_OFF:VersionInfo API is Disabled
 */
#define DET_CFG_ERRORBUFFERSIZE (100U)

#define DET_CFG_CALLERRORHOOKS(ModuleId, InstanceId, ApiId, ErrorId)    ((void)0U)
#define DET_CFG_CALLTRANSIENTHOOK(ModuleId, InstanceId, ApiId, ErrorId) ((void)0U)
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
