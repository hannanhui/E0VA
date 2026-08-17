/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Icu_Cfg.h
 *  @Syntax             : GNU99
 *  @Author             : ChipON AE/FAE Group
 *  @Date            : 2022-05-10
 *  @Version         : {{VersionDate}}
 *  @Description     : This document describes the C language document template.
 ******************************************************************************
 *  Copyright (C) by Shanghai ChipON Micro-Electronic Co.,Ltd
 *  All rights reserved.
 *
 *  This software is copyright protected and proprietary to
 *  Shanghai ChipON Micro-Electronic Co.,Ltd.
 *****************************************************************************/
#ifndef ICU_CFG_H
#define ICU_CFG_H

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
 * @brief Switches the Development Error Detection and Notification on or off.
 * @details
 * STD_ON: Enabled.
 * STD_OFF: Disabled.
 * @implements ICU_DEV_ERROR_DETECT_define
 */
#define ICU_DEV_ERROR_DETECT (STD_ON)

/**
 * @brief Pre-compile configuration constants
 */
#define ICU_PRECOMPILE_SUPPORT (STD_OFF)

/**
 * @brief Adds or removes the service Icu_DeInit() from the code.
 * @details
 * STD_ON: Icu_DeInit() can be used.
 * STD_OFF: Icu_DeInit() can not be used.
 * @implements #SWS_Icu_00092 #SWS_Icu_00301
 */
#define ICU_DE_INIT_API (STD_ON)

/**
 * @brief Adds or removes the service Icu_SetMode() from the code.
 * @details
 * STD_ON: Icu_SetMode() can be used.
 * STD_OFF: Icu_SetMode() can not be used.
 * @implements #SWS_Icu_00095 #SWS_Icu_00303
 */
#define ICU_SET_MODE_API (STD_OFF)

/**
 * @brief Adds or removes the service Icu_DisableWakeup() from the code.
 * @details
 * STD_ON: Icu_DisableWakeup() can be used.
 * STD_OFF: Icu_DisableWakeup() can not be used.
 * @implements #SWS_Icu_00096 #SWS_Icu_00306
 */
#define ICU_DISABLE_WAKEUP_API (STD_OFF)

/**
 * @brief Adds or removes the service Icu_EnableWakeup() from the code.
 * @details
 * STD_ON: Icu_EnableWakeup() can be used.
 * STD_OFF: Icu_EnableWakeup() can not be used.
 * @implements #SWS_Icu_00097 #SWS_Icu_00308
 */
#define ICU_ENABLE_WAKEUP_API (STD_OFF)

/**
 * @brief Adds or removes the service Icu_CheckWakeup() from the code.
 * @details
 * STD_ON: Icu_CheckWakeup() can be used.
 * STD_OFF: Icu_CheckWakeup() can not be used.
 * @implements #SWS_Icu_00362
 */
#define ICU_WAKEUP_FUNCTIONALITY_API (STD_OFF)

/**
 * @brief Adds or removes the service Icu_GetInputState() from the code.
 * @details
 * STD_ON: Icu_GetInputState() can be used.
 * STD_OFF: Icu_GetInputState() can not be used.
 * @implements #SWS_Icu_00122 #SWS_Icu_00315
 */
#define ICU_GET_INPUT_STATE_API (STD_ON)

/**
 * @brief Adds or removes all services related to the time stamping
 * functionality as listed below from the code:
 * Icu_StartTimestamp(), Icu_StopTimestamp(), Icu_GetTimestampIndex().
 * @details
 * STD_ON: The services listed above can be used.
 * STD_OFF: The services listed above can not be used.
 * @implements #SWS_Icu_00098 #SWS_Icu_00321 #SWS_Icu_00099 #SWS_Icu_00323
 * #SWS_Icu_00100 #SWS_Icu_00325
 */
#define ICU_TIMESTAMP_API (STD_OFF)

/**
 * @brief Adds or removes all services related to the edge counting
 * functionality as listed below, from the code:
 * Icu_ResetEdgeCount(), Icu_EnableEdgeCount(), Icu_DisableEdgeCount(), Icu_GetEdgeNumbers().
 * @details
 * STD_ON: The services listed above can be used.
 * STD_OFF: The services listed above can not be used.
 * @implements #SWS_Icu_00101 #SWS_Icu_00327 #SWS_Icu_00102 #SWS_Icu_00329
 * #SWS_Icu_00103 #SWS_Icu_00331 #SWS_Icu_00104 #SWS_Icu_00333
 */
#define ICU_EDGE_COUNT_API (STD_ON)

/**
 * @brief Adds or removes the services Icu_EnableEdgeDetection() and Icu_DisableEdgeDetection() from the code.
 * @details
 * STD_ON: Icu_EnableEdgeDetection() and Icu_DisableEdgeDetection() can be used.
 * STD_OFF: Icu_EnableEdgeDetection() and Icu_DisableEdgeDetection() can not be used.
 * @implements #SWS_Icu_00369 #SWS_Icu_00370 #SWS_Icu_00374 #SWS_Icu_00375
 */
#define ICU_EDGE_DETECT_API (STD_ON)

/**
 * @brief Adds or removes the services Icu_StartSignalMeasurement() and Icu_StopSignalMeasurement() from the code.
 * @details
 * STD_ON: Icu_StartSignalMeasurement() and Icu_StopSignalMeasurement() can be used.
 * STD_OFF: Icu_StartSignalMeasurement() and Icu_StopSignalMeasurement() can not be used.
 * @implements #SWS_Icu_00142 #SWS_Icu_00335 #SWS_Icu_00145 #SWS_Icu_00337
 */
#define ICU_SIGNAL_MEASUREMENT_API (STD_ON)

/**
 * @brief Adds or removes the service Icu_GetTimeElapsed() from the code.
 * @details
 * STD_ON: Icu_GetTimeElapsed() can be used.
 * STD_OFF: Icu_GetTimeElapsed() can not be used.
 * @implements #SWS_Icu_00105 #SWS_Icu_00341
 */
#define ICU_GET_TIME_ELAPSED_API (STD_ON)

/**
 * @brief Adds or removes the service Icu_GetDutyCycleValues() from the code.
 * @details
 * STD_ON: Icu_GetDutyCycleValues() can be used.
 * STD_OFF: Icu_GetDutyCycleValues() can not be used.
 * @implements #SWS_Icu_00106 #SWS_Icu_00345
 */
#define ICU_GET_DUTY_CYCLE_VALUES_API (STD_ON)

/**
 * @brief Adds or removes the service Icu_GetVersionInfo() from the code.
 * @details
 * STD_ON: Icu_GetVersionInfo() can be used.
 * STD_OFF: Icu_GetVersionInfo() can not be used.
 */
#define ICU_VERSION_INFO_API (STD_ON)

/**
 * @brief Number of ICU channels configured by user
 */
#define ICU_CONFIGED_CHANNEL (2U)

/**
 * @brief  Advance  ICU used or not
 * @details ICU does not support advance timer
 */
#define ICU_ADVANCE_USED (STD_OFF)

/**
 * @brief Switch for enabling Wakeup source reporting.
 * @details not supported
 */
#define ICU_REPORT_WAKEUP_SOURCE (STD_OFF)

/**
 * @brief Channel Id of the ICU channel. This value will be assigned to the symbolic name derived of the IcuChannel
 * container short name.
 */
#define IcuConf_IcuChannel_0 (0U)
#define IcuConf_IcuChannel_1 (1U)
#define IcuConf_IcuChannel_2 (2U)
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
