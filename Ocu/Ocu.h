/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Ocu.h
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
#ifndef OCU_H
#define OCU_H

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
/******************************************************************************
 **                        Include Files
 ******************************************************************************/
#include "Std_Types.h"
#include "Ocu_Types.h"
/** @implements #SWS_Ocu_00003 */
/** @implements #SWS_Ocu_00002 */
#include "Ocu_Cfg.h"

/******************************************************************************
 **                        File Version Check
 ******************************************************************************/
#define OCU_VENDOR_ID   (0xCCU)
#define OCU_MODULE_ID   (125U)
#define OCU_INSTANCE_ID ((uint8)0x0U)

/**
 * @brief Ocu module software version
 */
#define OCU_SW_MAJOR_VERSION (1U)
#define OCU_SW_MINOR_VERSION (0U)
#define OCU_SW_PATCH_VERSION (0U)

/******************************************************************************
 **                        Macro  Definitions
 ******************************************************************************/

#if (OCU_DEV_ERROR_DETECT_API == STD_ON)
/** @implements #SWS_Ocu_00015 */
/** @implements #SWS_Ocu_00016 */

/**
 * @brief API services other than Ocu_GetVersionInfo() and Ocu_init() used without module initialization
 */
#define OCU_E_UNINIT (0x02U)

/**
 * @brief API service used with an invalid channel Identifier
 */
#define OCU_E_PARAM_INVALID_CHANNEL (0x03U)

/**
 * @brief API Ocu_SetPinState() called with an invalid pin state or when the channel is in the RUNNING state
 */
#define OCU_E_PARAM_INVALID_STATE (0x04U)

/**
 * @brief API Ocu_SetPinAction() called with an invalid pin action
 */
#define OCU_E_PARAM_INVALID_ACTION (0x05U)

/**
 * @brief Usage of Ocu_DisableNotification() or Ocu_EnableNotification() on a channel where a NULL pointer is configured
 * as the notification function
 */
#define OCU_E_NO_VALID_NOTIF (0x06U)

/**
 * @brief API Ocu_Init() called while the OCU driver has already been initialized
 */
#define OCU_E_ALREADY_INITIALIZED (0x07U)

/**
 * @brief API Ocu_GetVersionInfo() is called with a NULL parameter
 */
#define OCU_E_PARAM_POINTER (0x08U)

/**
 * @brief API Ocu_StartChannel() called on a channel that is in state RUNNING
 */
#define OCU_E_BUSY (0x09U)

/**
 * @brief Ocu_SetPinState() or Ocu_SetPinAction() called for a channel that does not have an associated output pin.
 */
#define OCU_E_PARAM_NO_PIN (0x0AU)

/**
 * @brief OCU initialization has been failed
 */
#define OCU_E_INIT_FAILED (0x0BU)

/**
 * @brief The set value exceeds the module period value
 *
 * @implements Non-AUTOSAR
 */
#define OCU_E_PARAM_INVALID_VALUE (0x0CU)

/** @brief API Service Ids */
/**
 * @brief API Service ID for Ocu_Init
 */
#define OCU_INIT_SERVICE_ID (0x00U)

/**
 * @brief API Service ID for Ocu_DeInit
 */
#define OCU_DEINIT_SERVICE_ID (0x01U)

/**
 * @brief API Service ID for Ocu_StartChannel
 */
#define OCU_STARTCHANNEL_SERVICE_ID (0x02U)

/**
 * @brief API Service ID for Ocu_StopChannel
 */
#define OCU_STOPCHANNEL_SERVICE_ID (0x03U)

/**
 * @brief API Service ID for Ocu_SetPinState
 */
#define OCU_SETPINSTATE_SERVICE_ID (0x04U)

/**
 * @brief API Service ID for Ocu_SetPinAction
 */
#define OCU_SETPINACTION_SERVICE_ID (0x05U)

/**
 * @brief API Service ID for Ocu_GetCounter
 */
#define OCU_GETCOUNTER_SERVICE_ID (0x06U)

/**
 * @brief API Service ID for Ocu_SetAbsoluteThreshold
 */
#define OCU_SETABSOLUTETHRESHOLD_SERVICE_ID (0x07U)

/**
 * @brief API Service ID for Ocu_SetRelativeThreshold
 */
#define OCU_SETRELATIVETHRESHOLD_SERVICE_ID (0x08U)

/**
 * @brief API Service ID for Ocu_GetVersionInfo
 */
#define OCU_GETVERSIONINFO_SERVICE_ID (0x09U)

/**
 * @brief API Service ID for Ocu_GetVersionInfo
 */
#define OCU_DISABLE_NOTIFICATION_SERVICE_ID (0x0AU)

/**
 * @brief API Service ID for Ocu_EnableNotification
 */
#define OCU_ENABLE_NOTIFICATION_SERVICE_ID (0x0BU)
#endif
/******************************************************************************
 **                        Typedef  Definitions
 ******************************************************************************/

/**
 * @brief Gpt channel notification type.  The callback notifications shall be
 * configurable as pointers to user defined functions within the configuration
 * structure.
 *
 * @implements #SWS_GPT_00292
 */
typedef void (*Ocu_NotificationFcnType)(void);

/**
 * @brief Index of Ocu hardware unit
 * @details
 * Type: Enumeration
 */
/*PRQA S 3205 ++ #KQR003205 */
typedef enum
{
    OCU_MODULE_0,
    OCU_MODULE_1,
    OCU_MODULE_2,
    OCU_MODULE_3,
    OCU_MODULE_4,
    OCU_MODULE_20,
    OCU_MODULE_21
} Ocu_ModuleInstanceType;

/**
 * @brief Numeric identifier of an OCU channel
 * @details
 * Type: uint
 * Range: 8 / 16 / 32 bits
 * This is implementation specific but not all values may be valid within the type. This type shall be chosen in order
 * to have the most efficient implementation on a specific micro controller platform
 * @implements #SWS_Ocu_00028
 */
typedef uint8 Ocu_ChannelType;

/**
 * @brief Type for reading the counter and writing the threshold values (in number of ticks)
 * @details
 * Type: uint
 * Range: 8 / 16 / 32 bits
 * This is implementation specific but not all values may be valid within the type. This type shall be chosen in order
 * to have the most efficient implementation on a specific micro controller platform.
 * @implements #SWS_Ocu_00029
 */
typedef uint32 Ocu_ValueType;

/**
 * @brief Output state of the pin linked to an OCU channel
 * @details
 * Type: Enumeration
 * Range:
 * OCU_HIGH-The pin associated to an OCU channel is in high state.
 * OCU_LOW-The pin associated to an OCU channel is in low state
 * @implements #SWS_Ocu_00031
 */
typedef enum
{
    OCU_HIGH,
    OCU_LOW
} Ocu_PinStateType;

/**
 * @brief Automatic action (by hardware) to be performed on a pin attached to an OCU channel
 * @details
 * Type: Enumeration
 * Range:
 * OCU_SET_HIGH-The channel pin will be set HIGH upon compare match.
 * OCU_SET_LOW-The channel pin will be set LOW upon compare match.
 * OCU_TOGGLE-The channel pin will be set to the opposite of its current level HIGH upon compare match.
 * OCU_EVENT_ADC-The channel pin will trigger ADC collection event upon compare match. OCU_DISABLE-The channel pin will
 * remain at its current level upon compare match.
 * @implements #SWS_Ocu_00032
 */
typedef enum
{
    /** @brief Output high level when comparing matches */
    OCU_SET_HIGH,
    /** @brief Output low level when comparing matches */
    OCU_SET_LOW,
    /** @brief Toggle level when comparing matches */
    OCU_TOGGLE,
    /** @brief Close compare mode */
    OCU_DISABLE,
} Ocu_PinActionType;

/**
 * @brief Clock mode
 */
typedef enum
{
    OCU_TXCLOCK_SCLK,
    OCU_TXCLOCK_HFCLK,
    OCU_TXCLOCK_TX_LFCLK
} Ocu_TxClockModeType;

/**
 * @brief Return information after setting a new threshold value
 * @details
 * Type: Enumeration
 * Range:
 * OCU_CM_IN_REF_INTERVAL-The compare match will occur inside the current Reference Interval.
 * OCU_CM_OUT_REF_INTERVAL-The compare match will not occur inside the current Reference Interval
 * @implements #SWS_Ocu_00138
 */
typedef enum
{
    OCU_CM_IN_REF_INTERVAL,
    OCU_CM_OUT_REF_INTERVAL
} Ocu_ReturnType;

/**
 * @brief Ocu Count direction
 * @details
 * This enum specifies the count direction for the whole OCU driver.
 */
typedef enum
{
    OCU_DOWN_COUNTING,
    OCU_UP_COUNTING,
} Ocu_CountDirectionType;

/**
 * @brief TX counting mode
 * @details
 * OCU_TX_COUNTING_TIMER-Timing mode, Tx clock by TXCLK decision
 * OCU_TX_COUNTING_COUNT-
 * SM<2:0> = 111 Count mode 2, the timer clock is the trigger signal TRGI
 * SM<2:0> = 111 Count mode 1, The Tx clock is the external clock TxCK
 */
typedef enum
{
    OCU_TX_COUNTING_TIMER,
    OCU_TX_COUNTING_COUNT
} Ocu_TxCountingModeType;

/**
 * @brief Function notifies state
 */
typedef enum
{
    OCU_CHANNEL_NOTIFY_DISABLE,
    OCU_CHANNEL_NOTIFY_ENABLE,
} Ocu_ChannelNotifyStatusType;

/**
 * @brief channel working state
 */
typedef enum
{
    OCU_CHANNEL_STOPPED,
    OCU_CHANNEL_RUNNING,
} Ocu_ChannelRunStatusType;

/**
 * @brief Hardware configuration information of the channel
 * @implements #SWS_Ocu_00034
 */
typedef struct
{
    /** @brief A maximum of 10 comparison units are supported */
    Ocu_ModuleInstanceType ModuleInstance;
    /** @brief The frequencies */
    Ocu_TxClockModeType ClockSource;
    /** @brief Frequency division coefficient */
    Ocu_ValueType Prescale;
    /** @brief Timer Counter maximum to roll over */
    Ocu_ValueType MaxCounter;
} Ocu_ImConfigType;

/**
 * @brief Configuration information about each OCU channel
 * @implements #SWS_Ocu_00034
 */
typedef struct
{
    /** @brief Module unit configuration index number */
    const uint8 ModuleIndex;
    /** @brief Module's Channel Index */
    const uint8 AssignedHwChannel;
    /** @brief Is there a pin associated with channel */
    boolean OutputPinEnabled;
    /** @brief Default value of the threshold */
    Ocu_ValueType DefaultThreshold;
    /**
     * @brief The match comparison value is, discipline the output state
     * @details
     * 1.count direction
     * 2.Ouput pin (levels, and possible automatic actions)
     * 3.Hardware triggered events (ADC or DMA)
     */
    Ocu_PinActionType PinAction;
    /** @brief Channel Notification Function */
    Ocu_NotificationFcnType NotifyFcn;
} Ocu_ChannelConfigType;

/**
 * @brief This is the type of the data structure containing the initialization data for the OCU driver
 * @details
 * Type: Structure
 * Range:
 * Hardware dependent-The contents of the initialization data structure are hardware specific
 * @implements #SWS_Ocu_00033
 */
/* PRQA S 3630 ++ #KQR003630 */
typedef struct
{
    /**
     * @brief Ocu_ConfigType is a type of data structure containing the initialization data for the OCU driver
     * @details
     * Mandatory parameters:
     * 1.Symbolic name for channel / channel ID
     * 2.maximum value of the counter
     * 3.Time resolution in number of ticks
     * 4.Notification function
     * 5.Default value of the threshold
     * 6.Minimum value of the counter
     * Optional parameters (if supported by hardware):
     * 1.count direction
     * 2.Ouput pin (levels, and possible automatic actions)
     * 3.Hardware triggered events (ADC or DMA)
     * 4.Micro controller OCU-specific HW properties (optional prescaler, clock settings if supported by hardware)
     * @implements #SWS_Ocu_00034
     */
    /** @brief Numbers of assigned channels */
    uint8 NumChannel;
    /** @brief Pointer to Channel Config Array */
    const Ocu_ChannelConfigType *ChannelConfigPtr;
    /** @brief Numbers of assigned Hw Units  */
    uint8 NumHwUnit;
    /** @brief Pointer to HwUnit Config Array */
    const Ocu_ImConfigType *HwUnitConfigPtr;
    /** @brief count direction EcuC_Ocu_00149 */
    Ocu_CountDirectionType CountDirection;
} Ocu_ConfigType;
/* PRQA S 3630 -- #KQR003630 */
/******************************************************************************
 **                        Export Variables
 ******************************************************************************/

/******************************************************************************
 **                        Export Functions
 ******************************************************************************/

#if (OCU_VERSION_INFO_API == STD_ON)
/******************************************************************************
 * Function Name   : Ocu_GetVersionInfo
 *
 * Service ID   : 0x09
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Reentrant
 *
 * Parameters(in)   : None
 *
 * Parameters(inout)   : None
 *
 * Parameters(out)   : versioninfo-Pointer to where to store the version information of this module
 *
 * Return value   : None
 *
 * Description   : This service returns the version information of this module
 *
 ******************************************************************************/
/*PRQA S 3432 ++ #KQR003432 */
FUNC(void, OCU_CODE) Ocu_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, OCU_APPL_DATA) Versioninfo);
#endif

#if (OCU_NOTIFICATION_SUPPORTED == STD_ON)
/******************************************************************************
 * Function Name   : Ocu_EnableNotification
 *
 * Service ID   : 0x0b
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Reentrant for different channel numbers
 *
 * Parameters(in)   : ChannelNumber Numeric identifier of the OCU channel
 *
 * Parameters(inout)   : None
 *
 * Parameters(out)   : None
 *
 * Return value   : None
 *
 * Description   : This service is used to enable notifications from an OCU channel.
 *
 ******************************************************************************/
FUNC(void, OCU_CODE) Ocu_EnableNotification(VAR(Ocu_ChannelType, OCU_VAR) ChannelNumber);

/******************************************************************************
 * Function Name   : Ocu_DisableNotification
 *
 * Service ID   : 0x0a
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Reentrant for different channel numbers
 *
 * Parameters(in)   : ChannelNumber-Numeric identifier of the OCU channel
 *
 * Parameters(inout)   : None
 *
 * Parameters(out)   : None
 *
 * Return value   : None
 *
 * Description   : This service is used to disable notifications from an OCU channel.
 *
 ******************************************************************************/
FUNC(void, OCU_CODE) Ocu_DisableNotification(VAR(Ocu_ChannelType, OCU_VAR) ChannelNumber);
#endif

#if (OCU_SET_RELATIVE_THRESHOLD_API == STD_ON)
/******************************************************************************
 * Function Name   : Ocu_SetRelativeThreshold
 *
 * Service ID   : 0x08
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Reentrant for different channel numbers
 *
 * Parameters(in)   : ChannelNumber-Numeric identifier of the OCU channel
 * RelativeValue-Value to use for computing the new threshold.
 *
 * Parameters(inout)   : None
 *
 * Parameters(out)   : None
 *
 * Return value   : Tells the caller whether the compare match will occur (or has already occurred) during the current
 * Reference Interval,as a result of setting the new threshold value.
 *
 * Description   : Service to set the value of the channel threshold relative to the current value of the counter.
 *
 ******************************************************************************/
FUNC(Ocu_ReturnType, OCU_CODE)
Ocu_SetRelativeThreshold(VAR(Ocu_ChannelType, OCU_VAR) ChannelNumber, VAR(Ocu_ValueType, OCU_VAR) RelativeValue);
#endif

#if (OCU_SET_ABSOLUTE_THRESHOLD_API == STD_ON)
/******************************************************************************
 * Function Name   : Ocu_SetAbsoluteThreshold
 *
 * Service ID   : 0x07
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Reentrant for different channel numbers
 *
 * Parameters(in)   : ChannelNumber-Ocu channel id
 * ReferenceValue-Value given by the upper layer and used as a base to determine whether to call the notification before
 * the function exits or not.
 * AbsoluteValue-Value to compare with the content of the counter. This value is in ticks.
 *
 * Parameters(inout)   : None
 *
 * Parameters(out)   : None
 *
 * Return value   : Tells the caller whether the compare match will occur (or has already occurred) during the current
 * Reference Interval, as a result of setting the new threshold value.
 *
 * Description   : Service to set the value of the channel threshold using an absolute input data.
 *
 ******************************************************************************/
FUNC(Ocu_ReturnType, OCU_CODE)
Ocu_SetAbsoluteThreshold(VAR(Ocu_ChannelType, OCU_VAR) ChannelNumber, VAR(Ocu_ValueType, OCU_VAR) ReferenceValue,
                         VAR(Ocu_ValueType, OCU_VAR) AbsoluteValue);
#endif

#if (OCU_GET_COUNTER_API == STD_ON)
/******************************************************************************
 * Function Name   : Ocu_GetCounter
 *
 * Service ID   : 0x06
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Reentrant
 *
 * Parameters(in)   : ChannelNumber  Ocu channel id
 *
 * Parameters(inout)   : None
 *
 * Parameters(out)   : None
 *
 * Return value   : None
 *
 * Description   : Service to read the current value of the counter
 *
 ******************************************************************************/
FUNC(Ocu_ValueType, OCU_CODE) Ocu_GetCounter(VAR(Ocu_ChannelType, OCU_VAR) ChannelNumber);
#endif

#if (OCU_SET_PIN_ACTION_API == STD_ON)
/******************************************************************************
 * Function Name   : Ocu_SetPinAction
 *
 * Service ID   : 0x05
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Reentrant for different channel numbers
 *
 * Parameters(in)   : ChannelNumber-Numeric identifier of the OCU
 * PinAction-OCU_SET_HIGH,OCU_SET_LOW,OCU_TOGGLE,OCU_EVENT_ADC,OCU_DISABLE
 *
 * Parameters(inout)   : None
 *
 * Parameters(out)   : None
 *
 * Return value   : None
 *
 * Description   : Service to indicate the driver what shall be done automatically by hardware (if supported) upon
 *compare match
 *
 ******************************************************************************/
FUNC(void, OCU_CODE)
Ocu_SetPinAction(VAR(Ocu_ChannelType, OCU_VAR) ChannelNumber, VAR(Ocu_PinActionType, OCU_VAR) PinAction);
#endif

#if (OCU_SET_PIN_STATE_API == STD_ON)
/******************************************************************************
 * Function Name   : Ocu_SetPinState
 *
 * Service ID   : 0x04
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Reentrant for different channel numbers
 *
 * Parameters(in)   : ChannelNumber-Numeric identifier of the OCU
 * PinState-OCU_LOW, OCU_HIGH
 *
 * Parameters(inout)   : None
 *
 * Parameters(out)   : None
 *
 * Return value   : None
 *
 * Description   : Service to stop an OCU channel
 *
 ******************************************************************************/
FUNC(void, OCU_CODE)
Ocu_SetPinState(VAR(Ocu_ChannelType, OCU_VAR) ChannelNumber, VAR(Ocu_PinStateType, OCU_VAR) PinState);
#endif

/******************************************************************************
 * Function Name   : Ocu_StopChannel
 *
 * Service ID   : 0x03
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Reentrant for different channel numbers
 *
 * Parameters(in)   : Channel-Number Numeric identifier of the OCU
 *
 * Parameters(inout)   : None
 *
 * Parameters(out)   : None
 *
 * Return value   : None
 *
 * Description   : Service to stop an OCU channel
 *
 ******************************************************************************/
FUNC(void, OCU_CODE) Ocu_StopChannel(VAR(Ocu_ChannelType, OCU_VAR) ChannelNumber);

/******************************************************************************
 * Function Name   : Ocu_StartChannel
 *
 * Service ID   : 0x02
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Reentrant for different channel numbers
 *
 * Parameters(in)   : ChannelNumber-Numeric identifier of the OCU
 *
 * Parameters(inout)   : None
 *
 * Parameters(out)   : None
 *
 * Return value   : None
 *
 * Description   : Service to start an OCU channel
 *
 ******************************************************************************/
FUNC(void, OCU_CODE) Ocu_StartChannel(VAR(Ocu_ChannelType, OCU_VAR) ChannelNumber);

#if (OCU_DE_INIT_API == STD_ON)
/******************************************************************************
 * Function Name   : Ocu_DeInit
 *
 * Service ID   : 0x01
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Non Reentrant
 *
 * Parameters(in)   : None
 *
 * Parameters(inout)   : None
 *
 * Parameters(out)   : None
 *
 * Return value   : None
 *
 * Description   : This function de-initializes the OCU module
 *
 ******************************************************************************/
FUNC(void, OCU_CODE) Ocu_DeInit(void);
#endif

/******************************************************************************
 * Function Name   : Ocu_Init
 *
 * Service ID   : 0x00
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Non Reentrant
 *
 * Parameters(in)   : ConfigPtr-Pointer to the configuration set
 *
 * Parameters(inout)   : None
 *
 * Parameters(out)   : None
 *
 * Return value   : None
 *
 * Description   : Service for OCU initialization
 *
 ******************************************************************************/
FUNC(void, OCU_CODE) Ocu_Init(P2CONST(Ocu_ConfigType, AUTOMATIC, OCU_APPL_CONST) ConfigPtr);
#ifdef __cplusplus
}
#endif
#endif
