/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Lin_Cfg.h
 *  @Syntax          : GNU99
 *  @Author          : ChipON AE/FAE Group
 *  @Date            : 2026/3/12 17:27:53
 *  @Version         : V1.0
 *  @Description     : AUTOSAR Lin - High level header of LIN driver.
 ******************************************************************************
 *  Copyright (C) by Shanghai ChipON Micro-Electronic Co.,Ltd
 *  All rights reserved.
 *
 *  This software is copyright protected and proprietary to
 *  Shanghai ChipON Micro-Electronic Co.,Ltd.
 *****************************************************************************/
#ifndef LIN_CFG_H
#define LIN_CFG_H

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
 **                        Macro Definitions
 ******************************************************************************/
/**
 * @brief Switches the Development Error Detection and Notification ON or OFF.
 */
#define LIN_DEV_ERROR_DETECT (STD_OFF)

/**
 * @brief Specifies the InstanceId of this module instance. If only one instance is present it shall have the Id 0.
 */
#define LIN_INDEX (0U)

/**
 * @brief Specifies the maximum number of loops for blocking function until a timeout is raised in short term wait loops
 */
#define LIN_TIMEOUT_DURATION (0U)

/**
 * @brief Switches the Lin_GetVersionInfo function ON or OFF.
 */
#define LIN_VERSION_INFO_API (STD_OFF)

/**
 * @brief Switches Precompile Support
 */
#define LIN_PRECOMPILE_SUPPORT (STD_OFF)

/**
 * @brief after Init channel state
 */
#define LIN_START_UP_SLEEP_STATE (STD_OFF)

/**
 * @brief lin slave mode (default:Master)
 */
#define LIN_SLAVE_MODE_USED (STD_ON)

/**
 * @brief Switches the Production Error Detection and Notification OFF
 */
#define LIN_DISABLE_DEM_REPORT_ERROR_STATUS (STD_ON)

/**
 * @brief Total number of available hardware lin channels.
 */
#define LIN_IM_MODULES (2U)

/**
 * @brief Max data length of the LIN SDU buffer to be returned.
 */
#define LIN_MAX_DATA_LENGTH (8U)

/**
 * @brief Number of loops before returning LIN_E_TIMEOUT.
 *
 * @api
 */
#define LIN_TIMEOUT_LOOPS ((uint32)1000U)

/**
 * @brief Identifies the LIN channel. Replaces LIN_CHANNEL_INDEX_NAME from the LIN SWS.
 */
#define LinConf_LinChannel_0 (0U)
#define LinConf_LinChannel_1 (1U)

/******************************************************************************
 **                        Typedef Definitions
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
