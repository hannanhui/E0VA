/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Ocu_Cfg.h
 *  @Syntax             : GNU99
 *  @Author             : ChipON AE/FAE Group
 *  @Date            : 2022-09-15
 *  @Version         : {{VersionDate}}
 *  @Description     : This document describes the C language document template.
 ******************************************************************************
 *  Copyright (C) by Shanghai ChipON Micro-Electronic Co.,Ltd
 *  All rights reserved.
 *
 *  This software is copyright protected and proprietary to
 *  Shanghai ChipON Micro-Electronic Co.,Ltd.
 *****************************************************************************/
#ifndef OCU_CFG_H
#define OCU_CFG_H

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
 * @brief The detection of development errors is configurable (ON / OFF) at pre-compile time. The switch
 * OcuDevErrorDetectApi shall activate or deactivate the detection of all development errors
 * @implements #SWS_Ocu_00018
 */
#define OCU_DEV_ERROR_DETECT_API (STD_ON)

/**
 * @brief Fixed address configuration
 */
#define OCU_PB_FIXED_ADDRESS (STD_OFF)

/**
 * @brief The function Ocu_DeInit shall be pre compile time configurable On/Off by the configuration parameter:
 * OcuDeInitApi {OCU_DE_INIT_API}
 * @implements #SWS_Ocu_00049
 */
#define OCU_DE_INIT_API (STD_ON)

/**
 * @brief The function Ocu_SetPinState shall be pre compile time configurable On/Off by the configuration parameter:
 * OcuSetPinStateApi {OCU_SET_PIN_STATE_API}
 * @implements #SWS_Ocu_00070
 */
#define OCU_SET_PIN_STATE_API (STD_ON)

/**
 * @brief The function Ocu_SetPinAction shall be pre compile time configurable by the configuration parameter:
 * OcuSetPinActionApi {OCU_SET_PIN_ACTION_API}
 * @implements #SWS_Ocu_00079
 */
#define OCU_SET_PIN_ACTION_API (STD_ON)

/**
 * @brief The function Ocu_GetCounter shall be pre compile time configurable by the configuration parameter:
 * OcuGetCounterApi {OCU_GET_COUNTER_API}
 * @implements #SWS_Ocu_00088
 */
#define OCU_GET_COUNTER_API (STD_ON)

/**
 * @brief The function Ocu_SetAbsoluteThreshold shall be pre compile time configurable On/Off by the configuration
 * parameter: OcuSetAbsoluteThresholdApi {OCU_SET_ABSOLUTE_THRESHOLD_API}
 * @implements #SWS_Ocu_00094
 */
#define OCU_SET_ABSOLUTE_THRESHOLD_API (STD_OFF)

/**
 * @brief The function Ocu_SetRelativeThreshold shall be pre compile time configurable On/Off by the configuration
 * parameter: OcuSetRelativeThresholdApi {OCU_SET_RELATIVE_THRESHOLD_API}
 * @implements #SWS_Ocu_00103
 */
#define OCU_SET_RELATIVE_THRESHOLD_API (STD_OFF)

/**
 * @brief The function Ocu_GetVersionInfo shall be pre compile time configurable On/Off by the configuration parameter:
 * OcuVersionInfoApi {OCU_VERSION_INFO_API}
 * @implements #SWS_Ocu_00124
 */
#define OCU_VERSION_INFO_API (STD_ON)

/**
 * @brief The OCU driver shall allow enabling /disabling notifications for an OCU channel during runtime
 * @implements #SWS_Ocu_00111,#SWS_Ocu_00118
 */
#define OCU_NOTIFICATION_SUPPORTED (STD_ON)

/******************************************************************************
 **                        Hardware Configuration Parameters
 ******************************************************************************/
/**
 * @brief Maximum number of CCP units
 */
#define OCU_MAX_CCP_UNIT_NUM (7U)

/**
 * @brief Maximum number of channels in one CCP unit
 */
#define OCU_MAX_CCP_CHANNEL_NUM (4U)

/******************************************************************************
 **                        user Configuration Parameters
 ******************************************************************************/

/**
 * @brief Number of configured channels
 */
#define OCU_USER_CFG_CHANNEL_NUM (2U)

/**
 * @brief Number of configured hardware unit
 */
#define OCU_USER_CFG_HARDWARE_NUM (2U)

/**
 * @brief Channel Id of the OCU channel. This value will be assigned to the symbolic name derived from the OcuChannel
 * container short name. It defines the assignment of the channel to the physical OCU hardware channel.
 */
#define OcuConf_Channel_0 (0U)
#define OcuConf_Channel_1 (1U)
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
