/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Adc_Cfg.h
 *  @Syntax             : GNU99
 *  @Author             : ChipON AE/FAE Group
 *  @Date             : 2026/4/7 17:54:25
 *  @Version         : V1.0
 *  @Description     : This document describes the C language document template.
 ******************************************************************************
 *  Copyright (C) by Shanghai ChipON Micro-Electronic Co.,Ltd
 *  All rights reserved.
 *
 *  This software is copyright protected and proprietary to
 *  Shanghai ChipON Micro-Electronic Co.,Ltd.
 *****************************************************************************/
#ifndef ADC_CFG_H
#define ADC_CFG_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 **                        Include Files
 ******************************************************************************/
#include "Std_Types.h"
/******************************************************************************
 **                        File Version Check
 ******************************************************************************/

/******************************************************************************
 **                        Macro  Definitions
 ******************************************************************************/

/**
 * @brief Determines the type of prioritization mechanism
 * @implements #SWS_Adc_00315,#SWS_Adc_00340,#SWS_Adc_00341
 */
#define ADC_PRIORITY_IMPLEMENTATION (ADC_PRIORITY_NONE)

/**
 * @brief The function Adc_DeInit shall be pre compile time configurable On/Off by the configuration parameter:
 * AdcDeInitApi
 * @implements #SWS_Adc_00228
 * @details
 * STD_ON:DeInit API is Enabled
 * STD_OFF:DeInit API is Disabled
 */
#define ADC_DEINIT_API (STD_ON)

/**
 * @brief Enables or disables limit checking feature in the ADC driver.
 * @details not supported
 */
#define ADC_ENABLE_LIMIT_CHECK (STD_OFF)

/**
 * @brief The function Adc_EnableGroupNotification shall be pre-compile time configurable On/Off by the configuration
 * parameter AdcGrpNotifCapability
 * The function Adc_DisableGroupNotification shall be pre-compile time configurable
 * On/Off by the configuration parameter AdcGrpNotifCapability
 * @implements #SWS_Adc_00501,#SWS_Adc_00101,#SWS_Adc_00100
 * @details
 * STD_ON:Adc Notification capability is Enabled
 * STD_OFF:Adc Notification capability is Disabled
 */
#define ADC_GRP_NOTIFY_CAPABILITY (STD_ON)

/**
 * @brief The function Adc_EnableHardwareTrigger shall be pre-compile time configurable On/Off by the configuration
 * parameter AdcHwTriggerApi
 * The function Adc_DisableHardwareTrigger shall be pre-compile time configurable On/Off by
 * the configuration parameter AdcHwTriggerApi
 * @implements #SWS_Adc_00265,#SWS_Adc_00266
 * @details
 * STD_ON:Adc HW Trigger API is Enabled
 * STD_OFF:Adc HW Trigger API is Disabled
 */
#define ADC_HW_TRIGGER_API (STD_OFF)

/**
 * @brief Adds / removes all power state management related APIs (ADC_SetPowerState, ADC_GetCurrentPowerState,
 * ADC_GetTargetPowerState, ADC_PreparePowerState, ADC_Main_PowerTransitionManager), indicating if the HW offers low
 * power state management.
 * @details not supported
 */
#define ADC_LOW_POWER_STATES_SUPPORT (STD_OFF)

/**
 * @brief Enables / disables support of the ADCDriver to the asynchronous power state transition.
 * @details not supported
 */
#define ADC_POWER_STATE_ASYNCH_TRANSITION_MODE (STD_OFF)

/**
 * @brief Version Information API configuration
 * @implements #ECUC_Adc_00409
 * @details
 * STD_ON:VersionInfo API is Enabled
 * STD_OFF:VersionInfo API is Disabled
 */
#define ADC_VERSION_INFO_API (STD_OFF)

/**
 * @brief The function Adc_StartGroupConversion shall be pre-compile time configurable On/Off by the configuration
 * parameter AdcEnableStartStopGroupApi
 * The function Adc_StopGroupConversion shall be pre compile time configurable On/Off by the configuration parameter
 * AdcEnableStartStopGroupApi.
 * @implements #SWS_Adc_00259,#SWS_Adc_00260
 * @details
 * STD_ON:Start/Stop Group conversion API is Enabled
 * STD_OFF:Start/Stop Group conversion API is Disabled
 */
#define ADC_ENABLE_START_STOP_GROUP_API (STD_ON)

/**
 * @brief Preprocessor switch for enabling the development error detection and reporting
 * @implements #SWS_Adc_00344
 * @details
 * STD_ON:DET is Enabled
 * STD_OFF:DET is Disabled
 */
#define ADC_DEV_ERROR_DETECT (STD_OFF)

/**
 * @brief Fixed address configuration as per HIS recommendations
 * @implements #ECUC_Adc_00411
 * @details
 * STD_ON:ConfigRoot[0] is used by default as the fixed configuration
 * STD_OFF:Dynamic usage of the selected configurations according to AUTOSAR
 */
#define ADC_PB_FIXED_ADDRESS (STD_ON)

/**
 * @brief The function Adc_ReadGroup shall be pre-compile configurable On/Off by the configuration parameter
 * AdcReadGroupApi
 * @implements #SWS_Adc_00359
 * @details
 * STD_ON:Adc_ReadGroup API is Enabled
 * STD_OFF:Adc_ReadGroup API is Disabled
 */
#define ADC_READ_GROUP_API (STD_ON)

#if ((ADC_ENABLE_START_STOP_GROUP_API == STD_ON) && (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE))
/**
 * @brief Determines, if the queuing mechanism is active in case of priority mechanism disabled.
 * Note: If priority mechanism is enabled, queuing mechanism is always active and the parameter ADC_ENABLE_QUEUING is
 * not evaluated
 * @implements #ECUC_Adc_00391
 * @details
 * true:Enabled
 * false: Disabled
 */
#define ADC_ENABLE_QUEUING (STD_ON)
#endif

/**
 * @brief Resetting SFR to its reset value
 * @details
 * STD_ON:resetting of SFRs to its reset value in the Adc_Init() is Enabled
 * STD_OFF:resetting of SFRs to its reset value in the Adc_Init() is Disabled
 */
#define ADC_RESET_SFR_INIT (STD_ON)

/**
 * @brief Result Alignment
 */
#define ADC_RESULT_ALIGNMENT ADC_ALIGN_RIGHT

/**
 *@brief Numeric ID of the group. This parameter is the symbolic name to be used on the API. This symbolic name allows
 *accessing Channel Group data. This value will be assigned to the symbolic name derived of the AdcGroup container
 *shortName.
 */
#define AdcConf0_AdcConfigSet_Group_0 (0x0U)

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
