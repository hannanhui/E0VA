/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Ocu.c
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
/* PRQA S 0488 EOF #KQR000488 */
/* PRQA S 3408 EOF #KQR003408 */
/* PRQA S 4342 EOF #KQR004342 */
/* PRQA S 2814 EOF #KQR002814 */
/* PRQA S 2824 EOF #KQR002824 */
/* PRQA S 2844 EOF #KQR002844 */
/* PRQA S 2201 EOF #KQR002201 */
/* PRQA S 2919 EOF #KQR002919 */
/* PRQA S 4899 EOF #KQR004899 */
/******************************************************************************
 **                        Include Files
 ******************************************************************************/
/** @implements #SWS_Ocu_00006 */
#include "Ocu.h"
#include "Ocu_Im.h"

#if (OCU_DEV_ERROR_DETECT_API == STD_ON)
#include "Det.h"
#endif

/******************************************************************************
 **                      SOURCE FILE VERSION INFORMATION
 ******************************************************************************/

/******************************************************************************
 **                        File Version Check
 ******************************************************************************/

/******************************************************************************
 **                        Macro  Definitions
 ******************************************************************************/

/******************************************************************************
 **                        Typedef  Definitions
 ******************************************************************************/
/**
 * @brief Running information of configured channel by user
 *
 */
typedef struct
{
    /** @brief Function notifies state of user configured channel */
    Ocu_ChannelNotifyStatusType NotificationStatus;
    /** @brief Working state of user configured channel */
    Ocu_ChannelRunStatusType ChannelRunState;
    /** @brief Automatic action (by hardware) to be performed on a pin attached to user configured channel */
    Ocu_PinActionType ChannelPinAction;
    /** @brief Maximum period of the module corresponding to a channel */
    Ocu_ValueType MaxValue;
} Ocu_ChannelRunningInfoType;

/******************************************************************************
 **                      Function declarations
 ******************************************************************************/
FUNC(void, OCU_CODE) Ocu_Isr(VAR(uint8, OCU_VAR) Module);

/******************************************************************************
 **                        Export Variables
 ******************************************************************************/
#if (OCU_PB_FIXED_ADDRESS == STD_ON)
extern CONST(Ocu_ConfigType, OCU_CONST) Ocu_ConfigPredefined;
#endif
/******************************************************************************
 **                        Export Functions
 ******************************************************************************/
/**
 * @brief timer interrupt handle register
 *
 * @param GptTimer timer index
 * @param IrqHandle interrupt handle function
 */
/* PRQA S 1513 2 #KQR001513 */
/* PRQA S 1336 1 #KQR001336 */
extern void Gpt_GeneralTimerRegisterCustomHandler(uint8 GptTimer, void (*const IrqHandle)(uint8));
/******************************************************************************
 **                        Constant Declarations
 ******************************************************************************/
#if (OCU_PB_FIXED_ADDRESS == STD_ON)
/* To store the ocu driver configuration pointer */
CONSTP2CONST(Ocu_ConfigType, OCU_CONST, OCU_APPL_CONST) Ocu_ConfigPtr = &Ocu_ConfigPredefined;
#else
/* To store the ocu driver configuration pointer */
static P2CONST(Ocu_ConfigType, AUTOMATIC, OCU_APPL_CONST) Ocu_ConfigPtr;
#endif
/******************************************************************************
**                     Variable Declarations
******************************************************************************/

/**
 * @brief Ocu Initialized Flag
 *
 */
/* PRQA S 3229 1 #KQR003229 */
static VAR(boolean, OCU_VAR) Ocu_Initialized = FALSE;
/**
 * @brief Record index of configured CCPx hardware and channels by user
 *
 */
/* PRQA S 0686,0694 ++ #KQR100015 */
static VAR(uint8, OCU_VAR) Ocu_assignedHwChannel[OCU_MAX_CCP_UNIT_NUM][OCU_MAX_CCP_CHANNEL_NUM] = {0xFFU};
/* PRQA S 0686,0694 -- #KQR100015 */
/**
 * @brief Record running info of configured channels by user
 *
 */
static VAR(Ocu_ChannelRunningInfoType, OCU_VAR) Ocu_ChanRunInfo[OCU_USER_CFG_CHANNEL_NUM];

/******************************************************************************
 **                      Private Function Declarations
 ******************************************************************************/
#if (OCU_DEV_ERROR_DETECT_API == STD_ON)
/**
 * @brief short for det error function
 * @implements #SWS_Ocu_00021
 * @param ApiId-API specification
 * @param ErrorId-Error code related to function
 */
LOCAL_INLINE FUNC(void, OCU_CODE) Ocu_ReportDetError(VAR(uint8, OCU_VAR) ApiId, VAR(uint8, OCU_VAR) ErrorId)
{
    (void)Det_ReportError((uint16)OCU_MODULE_ID, (uint8)OCU_INSTANCE_ID, ApiId, ErrorId);
}
#endif

/******************************************************************************
 **                      Function definitions
 ******************************************************************************/
/**
 * @brief Check the output status of the channel PIN
 * @param ChannelNumber-channel number
 * @retval Std_ReturnType-Check the output status of the channel PIN result
 * @return E_OK-Output is enabled for this channel
 * E_NOT_OK-Output is not enabled for this channel
 */
#if (OCU_DEV_ERROR_DETECT_API == STD_ON)
static FUNC(Std_ReturnType, OCU_CODE) Ocu_CheckPinState(VAR(Ocu_ChannelType, OCU_VAR) ChannelNumber)
{
    Std_ReturnType status;

    if (Ocu_ConfigPtr->ChannelConfigPtr[ChannelNumber].OutputPinEnabled == FALSE)
    {
        status = E_NOT_OK;
    }
    else
    {
        status = E_OK;
    }

    return status;
}

#if ((OCU_SET_RELATIVE_THRESHOLD_API == STD_ON) || (OCU_SET_ABSOLUTE_THRESHOLD_API == STD_ON))
/**
 * @brief Check whether the set value exceeds the periodic value
 *
 * @param ChannelNumber channel number
 * @param CompareValue check value
 *
 * @return
 * E_OK
 * E_NOT_OK
 */
static FUNC(Std_ReturnType, OCU_CODE)
  Ocu_CheckCompareValue(VAR(Ocu_ChannelType, OCU_VAR) ChannelNumber, VAR(Ocu_ValueType, OCU_VAR) CompareValue)
{
    Std_ReturnType status;

    if (CompareValue > Ocu_ChanRunInfo[ChannelNumber].MaxValue)
    {
        status = E_NOT_OK;
    }
    else
    {
        status = E_OK;
    }

    return status;
}
#endif
#endif

/**
 * @brief This service returns the version information of this module
 * @details
 * Syntax: void Ocu_GetVersionInfo(Std_VersionInfoType* versioninfo)
 * Service ID[hex]: 0x09
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * @implements #SWS_Ocu_00122,#SWS_Ocu_00123,#SWS_Ocu_00124,#SWS_Ocu_00125,#SWS_Ocu_00126
 * @param versioninfo Pointer to where to store the version information of this module
 * @retval void
 *
 */
#if (OCU_VERSION_INFO_API == STD_ON)
/* PRQA S 3432 2 #KQR003432 */
FUNC(void, OCU_CODE) Ocu_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, OCU_APPL_DATA) Versioninfo)
{
#if (OCU_DEV_ERROR_DETECT_API == STD_ON)
    Std_ReturnType status = E_OK;

    if (Versioninfo == NULL_PTR)
    {
        /** @implements #SWS_Ocu_00126 */
        Ocu_ReportDetError(OCU_GETVERSIONINFO_SERVICE_ID, OCU_E_PARAM_POINTER);
        status = E_NOT_OK;
    }

    if (status == E_OK)
#endif
    {
        /** @implements #SWS_Ocu_00123 */
        Versioninfo->vendorID         = OCU_VENDOR_ID;
        Versioninfo->moduleID         = OCU_MODULE_ID;
        Versioninfo->sw_major_version = OCU_SW_MAJOR_VERSION;
        Versioninfo->sw_minor_version = OCU_SW_MINOR_VERSION;
        Versioninfo->sw_patch_version = OCU_SW_PATCH_VERSION;
    }

    return;
}
#endif

/**
 * @brief This service is used to enable notifications from an OCU channel.
 * @details
 * Syntax: void Ocu_EnableNotification(Ocu_ChannelType ChannelNumber)
 * Service ID[hex]: 0x0b
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant for different channel numbers
 * @implements #SWS_Ocu_00115,#SWS_Ocu_00116,#SWS_Ocu_00117,#SWS_Ocu_00118,#SWS_Ocu_00119,#SWS_Ocu_00120,#SWS_Ocu_00121
 * @param ChannelNumber Numeric identifier of the OCU channel
 * @retval void
 *
 */
#if (OCU_NOTIFICATION_SUPPORTED == STD_ON)
FUNC(void, OCU_CODE) Ocu_EnableNotification(VAR(Ocu_ChannelType, OCU_VAR) ChannelNumber)
{
#if (OCU_DEV_ERROR_DETECT_API == STD_ON)
    Std_ReturnType status = E_OK;

    if (FALSE == Ocu_Initialized)
    {
        /** @implements #SWS_Ocu_00119 */
        Ocu_ReportDetError(OCU_ENABLE_NOTIFICATION_SERVICE_ID, OCU_E_UNINIT);
        status = E_NOT_OK;
    }
    else if (ChannelNumber >= OCU_USER_CFG_CHANNEL_NUM)
    {
        /** @implements #SWS_Ocu_00120 */
        Ocu_ReportDetError(OCU_ENABLE_NOTIFICATION_SERVICE_ID, OCU_E_PARAM_INVALID_CHANNEL);
        status = E_NOT_OK;
    }
    else if (Ocu_ConfigPtr->ChannelConfigPtr[ChannelNumber].NotifyFcn == NULL_PTR)
    {
        /** @implements #SWS_Ocu_00121 */
        Ocu_ReportDetError(OCU_ENABLE_NOTIFICATION_SERVICE_ID, OCU_E_NO_VALID_NOTIF);
        status = E_NOT_OK;
    }
    else
    {
        /* Do nothing */
    }

    if (status == E_OK)
#endif
    {
        /* channel config pointer */
        const Ocu_ChannelConfigType *channelConfig = Ocu_ConfigPtr->ChannelConfigPtr + ChannelNumber;

        /* Enable interrupt */
        Ocu_Im_SetChannelIntrEnabled(
          (uint8)Ocu_ConfigPtr->HwUnitConfigPtr[channelConfig->ModuleIndex].ModuleInstance,
          channelConfig->AssignedHwChannel, TRUE);

        /** @implements #SWS_Ocu_00116 */
        Ocu_ChanRunInfo[ChannelNumber].NotificationStatus = OCU_CHANNEL_NOTIFY_ENABLE;
    }
}
#endif

/**
 * @brief This service is used to disable notifications from an OCU channel.
 * @details
 * Syntax: void Ocu_DisableNotification(Ocu_ChannelType ChannelNumber)
 * Service ID[hex]: 0x0a
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant for different channel numbers
 * @implements #SWS_Ocu_00108,#SWS_Ocu_00109,#SWS_Ocu_00110,#SWS_Ocu_00111,#SWS_Ocu_00112,#SWS_Ocu_00113,#SWS_Ocu_00114
 * @param ChannelNumber Numeric identifier of the OCU channel
 * @retval void
 *
 */
#if (OCU_NOTIFICATION_SUPPORTED == STD_ON)
FUNC(void, OCU_CODE) Ocu_DisableNotification(VAR(Ocu_ChannelType, OCU_VAR) ChannelNumber)
{
#if (OCU_DEV_ERROR_DETECT_API == STD_ON)
    Std_ReturnType status = E_OK;

    if (FALSE == Ocu_Initialized)
    {
        /** @implements #SWS_Ocu_00112 */
        Ocu_ReportDetError(OCU_DISABLE_NOTIFICATION_SERVICE_ID, OCU_E_UNINIT);
        status = E_NOT_OK;
    }
    else if (ChannelNumber >= OCU_USER_CFG_CHANNEL_NUM)
    {
        /** @implements #SWS_Ocu_00113 */
        Ocu_ReportDetError(OCU_DISABLE_NOTIFICATION_SERVICE_ID, OCU_E_PARAM_INVALID_CHANNEL);
        status = E_NOT_OK;
    }
    else if (Ocu_ConfigPtr->ChannelConfigPtr[ChannelNumber].NotifyFcn == NULL_PTR)
    {
        /** @implements #SWS_Ocu_00114 */
        Ocu_ReportDetError(OCU_DISABLE_NOTIFICATION_SERVICE_ID, OCU_E_NO_VALID_NOTIF);
        status = E_NOT_OK;
    }
    else
    {
        /* Do nothing */
    }

    if (status == E_OK)
#endif
    {
        /* channel config pointer */
        const Ocu_ChannelConfigType *channelConfig = Ocu_ConfigPtr->ChannelConfigPtr + ChannelNumber;

        /* Disable interrupt */
        Ocu_Im_SetChannelIntrEnabled(
          (uint8)Ocu_ConfigPtr->HwUnitConfigPtr[channelConfig->ModuleIndex].ModuleInstance,
          channelConfig->AssignedHwChannel, FALSE);

        /** @implements #SWS_Ocu_00109 */
        Ocu_ChanRunInfo[ChannelNumber].NotificationStatus = OCU_CHANNEL_NOTIFY_DISABLE;
    }
}
#endif

/**
 * @brief Based on three values, the result status is returned
 *
 * @param CurrentValue Current value of the counter
 * @param ReferenceValue Reference Value or Value read on entering the API
 * @param ThresholdValue threshold value
 * @retval Ocu_ReturnType Tells the caller whether the compare match will occur (or has already occurred) during the
 * current Reference Interval,as a result of setting the new threshold value
 * @return  OCU_CM_IN_REF_INTERVAL-The compare match will occur inside the current Reference Interval.
 * OCU_CM_OUT_REF_INTERVAL-The compare match will not occur inside the current Reference Interval
 */
#if ((OCU_SET_ABSOLUTE_THRESHOLD_API == STD_ON) || (OCU_SET_RELATIVE_THRESHOLD_API == STD_ON))
static FUNC(Ocu_ReturnType, OCU_CODE)
  Ocu_CompareMatchResult(VAR(Ocu_ValueType, OCU_VAR) CurrentValue, VAR(Ocu_ValueType, OCU_VAR) ReferenceValue,
                         VAR(Ocu_ValueType, OCU_VAR) ThresholdValue)
{
    Ocu_ReturnType status;

    if (Ocu_ConfigPtr->CountDirection == OCU_UP_COUNTING)
    {
        if (ReferenceValue <= ThresholdValue)
        {
            /* counter is not expected to roll-over */
            /* check if current value is inside the compare match interval*/
            if ((ReferenceValue <= CurrentValue) && (CurrentValue <= ThresholdValue))
            {
                status = OCU_CM_IN_REF_INTERVAL;
            }
            else
            {
                status = OCU_CM_OUT_REF_INTERVAL;
            }
        }
        else
        {
            /* counter is rolled-over */
            /* check if current value is outside the compare match interval */
            if ((CurrentValue < ReferenceValue) && (CurrentValue > ThresholdValue))
            {
                status = OCU_CM_OUT_REF_INTERVAL;
            }
            else
            {
                status = OCU_CM_IN_REF_INTERVAL;
            }
        }
    }
    else
    {
        if (ReferenceValue <= ThresholdValue)
        {
            /* counter is not expected to roll-over */
            /* check if current value is inside the compare match interval*/
            if (CurrentValue >= ThresholdValue)
            {
                status = OCU_CM_IN_REF_INTERVAL;
            }
            else
            {
                status = OCU_CM_OUT_REF_INTERVAL;
            }
        }
        else
        {
            /* counter is rolled-over */
            /* check if current value is outside the compare match interval */
            if ((CurrentValue < ReferenceValue) && (CurrentValue > ThresholdValue))
            {
                status = OCU_CM_IN_REF_INTERVAL;
            }
            else
            {
                status = OCU_CM_OUT_REF_INTERVAL;
            }
        }
    }

    return status;
}
#endif

/**
 * @brief Service to set the value of the channel threshold relative to the current value of the counter.
 * @details
 * Syntax: Ocu_ReturnType Ocu_SetRelativeThreshold(Ocu_ChannelType ChannelNumber,Ocu_ValueType RelativeValue)
 * Service ID[hex]: 0x08
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant for different channel numbers
 * @implements
 * #SWS_Ocu_00100,#SWS_Ocu_00101,#SWS_Ocu_00106,#SWS_Ocu_00107,#SWS_Ocu_00102,#SWS_Ocu_00103,#SWS_Ocu_00104,#SWS_Ocu_00104
 * @param ChannelNumber Numeric identifier of the OCU channel
 * @param RelativeValue Value to use for computing the new threshold.
 * @retval Ocu_ReturnType Tells the caller whether the compare match will occur (or has already occurred) during the
 * current Reference Interval,as a result of setting the new threshold value.
 * @return  OCU_CM_IN_REF_INTERVAL:The compare match will occur inside the current Reference Interval.
 * OCU_CM_OUT_REF_INTERVAL:The compare match will not occur inside the current Reference Interval
 */
#if (OCU_SET_RELATIVE_THRESHOLD_API == STD_ON)
FUNC(Ocu_ReturnType, OCU_CODE)
Ocu_SetRelativeThreshold(VAR(Ocu_ChannelType, OCU_VAR) ChannelNumber, VAR(Ocu_ValueType, OCU_VAR) RelativeValue)
{
    Ocu_ReturnType retValue = OCU_CM_OUT_REF_INTERVAL;

#if (OCU_DEV_ERROR_DETECT_API == STD_ON)
    Std_ReturnType status = E_OK;

    if (FALSE == Ocu_Initialized)
    {
        /** @implements #SWS_Ocu_00104 */
        Ocu_ReportDetError(OCU_SETRELATIVETHRESHOLD_SERVICE_ID, OCU_E_UNINIT);
        status = E_NOT_OK;
    }
    else if (ChannelNumber >= OCU_USER_CFG_CHANNEL_NUM)
    {
        /** @implements #SWS_Ocu_00105 */
        Ocu_ReportDetError(OCU_SETRELATIVETHRESHOLD_SERVICE_ID, OCU_E_PARAM_INVALID_CHANNEL);
        status = E_NOT_OK;
    }
    else if (Ocu_CheckCompareValue(ChannelNumber, RelativeValue) == E_NOT_OK)
    {
        /* The value cannot exceed the period of the module */
        Ocu_ReportDetError(OCU_SETRELATIVETHRESHOLD_SERVICE_ID, OCU_E_PARAM_INVALID_VALUE);
        status = E_NOT_OK;
    }
    else
    {
        /* Do Nothing */
    }

    if (status == E_OK)
#endif
    {
        Ocu_ValueType maxValue;
        Ocu_ValueType currentValue;
        Ocu_ValueType targetValue;
        Ocu_ValueType startValue;

        /* channel config pointer */
        const Ocu_ChannelConfigType *channelConfig = Ocu_ConfigPtr->ChannelConfigPtr + ChannelNumber;
        maxValue = Ocu_ConfigPtr->HwUnitConfigPtr[channelConfig->ModuleIndex].MaxCounter;

        /** @implements #SWS_Ocu_00101 */
        /* Read counter on entering function and calculate new threshold */
        startValue =
          Ocu_Im_GetCounter((uint8)Ocu_ConfigPtr->HwUnitConfigPtr[channelConfig->ModuleIndex].ModuleInstance);

        if (Ocu_ConfigPtr->CountDirection == OCU_UP_COUNTING)
        {
            targetValue = (startValue + RelativeValue) % maxValue;
        }
        else
        {
            if (startValue >= RelativeValue)
            {
                targetValue = (startValue - RelativeValue);
            }
            else
            {
                targetValue = (maxValue - (RelativeValue - startValue)) % maxValue;
            }
        }

        /* Set threshold */
        Ocu_Im_SetChannelThreshold(
          Ocu_ConfigPtr->HwUnitConfigPtr[channelConfig->ModuleIndex].ModuleInstance, channelConfig->AssignedHwChannel,
          targetValue);

        /* Re-read counter from corresponding CCPx_CNT register */
        currentValue =
          Ocu_Im_GetCounter((uint8)Ocu_ConfigPtr->HwUnitConfigPtr[channelConfig->ModuleIndex].ModuleInstance);

        /** @implements #SWS_Ocu_00106 */
        /* Calculate the comparison occurred in the reference interval or beyond */
        retValue = Ocu_CompareMatchResult(currentValue, startValue, targetValue);
    }

    return retValue;
}
#endif

/**
 * @brief Service to set the value of the channel threshold using an absolute input data
 * @details
 * Syntax: Ocu_ReturnType Ocu_SetAbsoluteThreshold(Ocu_ChannelType ChannelNumber,Ocu_ValueType
 * ReferenceValue,Ocu_ValueType AbsoluteValue)
 * Service ID[hex]: 0x07
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant for different channel numbers
 * @implements
 * #SWS_Ocu_00091,#SWS_Ocu_00092,#SWS_Ocu_00093,#SWS_Ocu_00094,#SWS_Ocu_00095,#SWS_Ocu_00096,#SWS_Ocu_00098,#SWS_Ocu_00097
 * @param ChannelNumber Ocu channel id
 * @param ReferenceValue Value given by the upper layer and used as a base to determine whether to call the notification
 * before the function exits or not
 * @param AbsoluteValue Value to compare with the content of the counter. This value is in ticks
 * @retval Ocu_ReturnType Tells the caller whether the compare match will occur (or has already occurred) during the
 * current Reference Interval, as a result of setting the new threshold value
 * @return  OCU_CM_IN_REF_INTERVAL:The compare match will occur inside the current Reference Interval
 * OCU_CM_OUT_REF_INTERVAL:The compare match will not occur inside the current Reference Interval
 */
#if (OCU_SET_ABSOLUTE_THRESHOLD_API == STD_ON)
FUNC(Ocu_ReturnType, OCU_CODE)
Ocu_SetAbsoluteThreshold(VAR(Ocu_ChannelType, OCU_VAR) ChannelNumber, VAR(Ocu_ValueType, OCU_VAR) ReferenceValue,
                         VAR(Ocu_ValueType, OCU_VAR) AbsoluteValue)
{
    Ocu_ReturnType retValue = OCU_CM_OUT_REF_INTERVAL;
#if (OCU_DEV_ERROR_DETECT_API == STD_ON)
    Std_ReturnType status = E_OK;

    if (FALSE == Ocu_Initialized)
    {
        /** @implements #SWS_Ocu_00095 */
        Ocu_ReportDetError(OCU_SETABSOLUTETHRESHOLD_SERVICE_ID, OCU_E_UNINIT);
        status = E_NOT_OK;
    }
    else if (ChannelNumber >= OCU_USER_CFG_CHANNEL_NUM)
    {
        /** @implements #SWS_Ocu_00096 */
        Ocu_ReportDetError(OCU_SETABSOLUTETHRESHOLD_SERVICE_ID, OCU_E_PARAM_INVALID_CHANNEL);
        status = E_NOT_OK;
    }
    else if ((Ocu_CheckCompareValue(ChannelNumber, ReferenceValue) == E_NOT_OK) ||
             (Ocu_CheckCompareValue(ChannelNumber, AbsoluteValue) == E_NOT_OK))
    {
        /* The value cannot exceed the period of the module */
        Ocu_ReportDetError(OCU_SETABSOLUTETHRESHOLD_SERVICE_ID, OCU_E_PARAM_INVALID_VALUE);
        status = E_NOT_OK;
    }
    else
    {
        /* Do Nothing */
    }

    if (status == E_OK)
#endif
    {
        Ocu_ValueType currentValue;

        /* channel config pointer */
        const Ocu_ChannelConfigType *channelConfig = Ocu_ConfigPtr->ChannelConfigPtr + ChannelNumber;

        /* Set threshold */
        /** @implements #SWS_Ocu_00092 */
        Ocu_Im_SetChannelThreshold(
          Ocu_ConfigPtr->HwUnitConfigPtr[channelConfig->ModuleIndex].ModuleInstance, channelConfig->AssignedHwChannel,
          AbsoluteValue);

        /* Read counter from corresponding CCPx_CNT register */
        currentValue =
          Ocu_Im_GetCounter((uint8)Ocu_ConfigPtr->HwUnitConfigPtr[channelConfig->ModuleIndex].ModuleInstance);

        /** @implements #SWS_Ocu_00098 */
        /* Calculate the comparison occurred in the reference interval or beyond */
        retValue = Ocu_CompareMatchResult(currentValue, ReferenceValue, AbsoluteValue);
    }

    return retValue;
}
#endif

/**
 * @brief Service to read the current value of the counter
 * @details
 * Syntax: Ocu_ValueType Ocu_GetCounter(Ocu_ChannelType ChannelNumber)
 * Service ID[hex]: 0x06
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * @implements #SWS_Ocu_00085,#SWS_Ocu_00086,#SWS_Ocu_00087,#SWS_Ocu_00088,#SWS_Ocu_00089,#SWS_Ocu_00090
 * @param ChannelNumber Ocu channel id
 * @retval void
 *
 */
#if (OCU_GET_COUNTER_API == STD_ON)
FUNC(Ocu_ValueType, OCU_CODE) Ocu_GetCounter(VAR(Ocu_ChannelType, OCU_VAR) ChannelNumber)
{
    Ocu_ValueType value;
#if (OCU_DEV_ERROR_DETECT_API == STD_ON)
    if (FALSE == Ocu_Initialized)
    {
        /** @implements #SWS_Ocu_00090 */
        Ocu_ReportDetError(OCU_GETCOUNTER_SERVICE_ID, OCU_E_UNINIT);
    }
    else if (ChannelNumber >= OCU_USER_CFG_CHANNEL_NUM)
    {
        /** @implements #SWS_Ocu_00089 */
        Ocu_ReportDetError(OCU_GETCOUNTER_SERVICE_ID, OCU_E_PARAM_INVALID_CHANNEL);
    }
    else
    {
#endif
        /* channel config pointer */
        const Ocu_ChannelConfigType *channelConfig = Ocu_ConfigPtr->ChannelConfigPtr + ChannelNumber;
        /** @implements #SWS_Ocu_00086 */
        /* Read counter from CNT register */
        value = Ocu_Im_GetCounter((uint8)Ocu_ConfigPtr->HwUnitConfigPtr[channelConfig->ModuleIndex].ModuleInstance);
#if (OCU_DEV_ERROR_DETECT_API == STD_ON)
    }
#endif

    return value;
}
#endif

/**
 * @brief Service to indicate the driver what shall be done automatically by hardware (if supported) upon compare match
 * @details
 * Syntax: void Ocu_SetPinAction(Ocu_ChannelType ChannelNumber,Ocu_PinActionType PinAction)
 * Service ID[hex]: 0x05
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant for different channel numbers
 * @implements
 * #SWS_Ocu_00076,#SWS_Ocu_00077,#SWS_Ocu_00078,#SWS_Ocu_00079,#SWS_Ocu_00080,#SWS_Ocu_00081,#SWS_Ocu_00082,#SWS_Ocu_00083,#SWS_Ocu_00084
 * @param ChannelNumber Numeric identifier of the OCU channel
 * @param PinAction OCU_SET_HIGH,OCU_SET_LOW,OCU_TOGGLE,OCU_EVENT_ADC
 * @retval void
 *
 */
#if (OCU_SET_PIN_ACTION_API == STD_ON)
FUNC(void, OCU_CODE)
Ocu_SetPinAction(VAR(Ocu_ChannelType, OCU_VAR) ChannelNumber, VAR(Ocu_PinActionType, OCU_VAR) PinAction)
{
#if (OCU_DEV_ERROR_DETECT_API == STD_ON)
    Std_ReturnType status = E_OK;

    if (FALSE == Ocu_Initialized)
    {
        /** @implements #SWS_Ocu_00083 */
        Ocu_ReportDetError(OCU_SETPINACTION_SERVICE_ID, OCU_E_UNINIT);
        status = E_NOT_OK;
    }
    else if (ChannelNumber >= OCU_USER_CFG_CHANNEL_NUM)
    {
        /** @implements #SWS_Ocu_00080 */
        Ocu_ReportDetError(OCU_SETPINACTION_SERVICE_ID, OCU_E_PARAM_INVALID_CHANNEL);
        status = E_NOT_OK;
    }
    else if (Ocu_CheckPinState(ChannelNumber) == E_NOT_OK)
    {
        /** @implements #SWS_Ocu_00081 */
        Ocu_ReportDetError(OCU_SETPINACTION_SERVICE_ID, OCU_E_PARAM_NO_PIN);
        status = E_NOT_OK;
    }
    else if ((PinAction != OCU_DISABLE) && (PinAction != OCU_TOGGLE) && (PinAction != OCU_SET_LOW) &&
             (PinAction != OCU_SET_HIGH))
    {
        /** @implements #SWS_Ocu_00082 */
        Ocu_ReportDetError(OCU_SETPINACTION_SERVICE_ID, OCU_E_PARAM_INVALID_ACTION);
        status = E_NOT_OK;
    }
    else
    {
        /* Do nothing */
    }

    if (E_OK == status)
#endif
    {
        /* channel config pointer */
        const Ocu_ChannelConfigType *channelConfig = Ocu_ConfigPtr->ChannelConfigPtr + ChannelNumber;

        /** @implements #SWS_Ocu_00077,#SWS_Ocu_00084 */
        Ocu_Im_SetPinAction((uint8)Ocu_ConfigPtr->HwUnitConfigPtr[channelConfig->ModuleIndex].ModuleInstance,
                            channelConfig->AssignedHwChannel, (uint8)PinAction);
        /* update pin action */
        Ocu_ChanRunInfo[ChannelNumber].ChannelPinAction = PinAction;
    }
}
#endif

/**
 * @brief Service to set immediately the level of the pin associated to an OCU channel
 * @details
 * Syntax: void Ocu_SetPinState(Ocu_ChannelType ChannelNumber,Ocu_PinStateType PinState)
 * Service ID[hex]: 0x04
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant for different channel numbers
 * @implements
 * #SWS_Ocu_00066,#SWS_Ocu_00067,#SWS_Ocu_00068,#SWS_Ocu_00069,#SWS_Ocu_00070,#SWS_Ocu_00071,#SWS_Ocu_00072,#SWS_Ocu_00073,#SWS_Ocu_00074,#SWS_Ocu_00075
 * @param ChannelNumber Numeric identifier of the OCU channel
 * @param PinState OCU_LOW, OCU_HIGH
 * @retval void
 *
 */
#if (OCU_SET_PIN_STATE_API == STD_ON)
FUNC(void, OCU_CODE)
Ocu_SetPinState(VAR(Ocu_ChannelType, OCU_VAR) ChannelNumber, VAR(Ocu_PinStateType, OCU_VAR) PinState)
{
#if (OCU_DEV_ERROR_DETECT_API == STD_ON)
    Std_ReturnType status = E_OK;

    if (FALSE == Ocu_Initialized)
    {
        /** @implements #SWS_Ocu_00074 */
        Ocu_ReportDetError(OCU_SETPINSTATE_SERVICE_ID, OCU_E_UNINIT);
        status = E_NOT_OK;
    }
    else if (ChannelNumber >= OCU_USER_CFG_CHANNEL_NUM)
    {
        /** @implements #SWS_Ocu_00071 */
        Ocu_ReportDetError(OCU_SETPINSTATE_SERVICE_ID, OCU_E_PARAM_INVALID_CHANNEL);
        status = E_NOT_OK;
    }
    else if (Ocu_CheckPinState(ChannelNumber) == E_NOT_OK)
    {
        /** @implements #SWS_Ocu_00072 */
        Ocu_ReportDetError(OCU_SETPINSTATE_SERVICE_ID, OCU_E_PARAM_NO_PIN);
        status = E_NOT_OK;
    }
    else if (PinState > OCU_LOW)
    {
        /** @implements #SWS_Ocu_00073 */
        Ocu_ReportDetError(OCU_SETPINSTATE_SERVICE_ID, OCU_E_PARAM_INVALID_STATE);
        status = E_NOT_OK;
    }
    else if (Ocu_ChanRunInfo[ChannelNumber].ChannelRunState == OCU_CHANNEL_RUNNING)
    {
        /** @implements #SWS_Ocu_00075,#SWS_Ocu_00069 */
        Ocu_ReportDetError(OCU_SETPINSTATE_SERVICE_ID, OCU_E_PARAM_INVALID_STATE);
        status = E_NOT_OK;
    }
    else
    {
        /* Do nothing */
    }

    if (E_OK == status)
#endif
    {
        /* channel config pointer */
        const Ocu_ChannelConfigType *channelConfig = Ocu_ConfigPtr->ChannelConfigPtr + ChannelNumber;

        /** @implements #SWS_Ocu_00067 */
        Ocu_Im_SetPinOutPutState(
          (uint8)Ocu_ConfigPtr->HwUnitConfigPtr[channelConfig->ModuleIndex].ModuleInstance,
          channelConfig->AssignedHwChannel, PinState);
    }
}
#endif

/**
 * @brief Service to stop an OCU channel
 * @details
 * Syntax: void Ocu_StopChannel(Ocu_ChannelType ChannelNumber)
 * Service ID[hex]: 0x03
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant for different channel numbers
 * @implements
 * #SWS_Ocu_00058,#SWS_Ocu_00059,#SWS_Ocu_00060,#SWS_Ocu_00061,#SWS_Ocu_00062,#SWS_Ocu_00063,#SWS_Ocu_00064,#SWS_Ocu_00065
 * @param ChannelNumber Numeric identifier of the OCU channel
 * @todo #SWS_Ocu_00059 The current is immediate stop, not end of cycle stop
 * @retval void
 */
FUNC(void, OCU_CODE) Ocu_StopChannel(VAR(Ocu_ChannelType, OCU_VAR) ChannelNumber)
{
#if (OCU_DEV_ERROR_DETECT_API == STD_ON)
    Std_ReturnType status = E_OK;

    if (FALSE == Ocu_Initialized)
    {
        /** @implements #SWS_Ocu_00065 */
        Ocu_ReportDetError(OCU_STOPCHANNEL_SERVICE_ID, OCU_E_UNINIT);
        status = E_NOT_OK;
    }
    else if (ChannelNumber >= OCU_USER_CFG_CHANNEL_NUM)
    {
        /** @implements #SWS_Ocu_00064 */
        Ocu_ReportDetError(OCU_STOPCHANNEL_SERVICE_ID, OCU_E_PARAM_INVALID_CHANNEL);
        status = E_NOT_OK;
    }
    else
    {
        /* Do nothing */
    }

    if (E_OK == status)
#endif
    {
        /* channel config pointer */
        const Ocu_ChannelConfigType *channelConfig;

        if (Ocu_ChanRunInfo[ChannelNumber].ChannelRunState == OCU_CHANNEL_RUNNING)
        {
            channelConfig = Ocu_ConfigPtr->ChannelConfigPtr + ChannelNumber;

            /** @implements #SWS_Ocu_00060 */
            Ocu_Im_StopChannelProcess(
              (uint8)Ocu_ConfigPtr->HwUnitConfigPtr[channelConfig->ModuleIndex].ModuleInstance,
              channelConfig->AssignedHwChannel);

            /** @implements #SWS_Ocu_00109 */
            Ocu_ChanRunInfo[ChannelNumber].NotificationStatus = OCU_CHANNEL_NOTIFY_DISABLE;
            /** @implements #SWS_Ocu_00062 */
            Ocu_ChanRunInfo[ChannelNumber].ChannelRunState = OCU_CHANNEL_STOPPED;
        }
        else
        {
            /** @implements #SWS_Ocu_00063 */
        }
    }
}

/**
 * @brief Service to start an OCU channel
 * @details
 * Syntax: void Ocu_StartChannel(Ocu_ChannelType ChannelNumber)
 * Service ID[hex]: 0x02
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant for different channel numbers
 * @implements #SWS_Ocu_00051,#SWS_Ocu_00052,#SWS_Ocu_00053,#SWS_Ocu_00054,#SWS_Ocu_00055,#SWS_Ocu_00056,#SWS_Ocu_00057
 * @param ChannelNumber Numeric identifier of the OCU channel
 * @retval void
 *
 */
FUNC(void, OCU_CODE) Ocu_StartChannel(VAR(Ocu_ChannelType, OCU_VAR) ChannelNumber)
{
#if (OCU_DEV_ERROR_DETECT_API == STD_ON)
    Std_ReturnType status = E_OK;

    if (FALSE == Ocu_Initialized)
    {
        /** @implements #SWS_Ocu_00057 */
        Ocu_ReportDetError(OCU_STARTCHANNEL_SERVICE_ID, OCU_E_UNINIT);
        status = E_NOT_OK;
    }
    else if (ChannelNumber >= OCU_USER_CFG_CHANNEL_NUM)
    {
        /** @implements #SWS_Ocu_00056 */
        Ocu_ReportDetError(OCU_STARTCHANNEL_SERVICE_ID, OCU_E_PARAM_INVALID_CHANNEL);
        status = E_NOT_OK;
    }
    else if (Ocu_ChanRunInfo[ChannelNumber].ChannelRunState == OCU_CHANNEL_RUNNING)
    {
        /** @implements #SWS_Ocu_00055 */
        Ocu_ReportDetError(OCU_STARTCHANNEL_SERVICE_ID, OCU_E_BUSY);
        status = E_NOT_OK;
    }
    else
    {
        /* Do nothing */
    }

    if (E_OK == status)
#endif
    {
        /* channel config pointer */
        const Ocu_ChannelConfigType *channelConfig = Ocu_ConfigPtr->ChannelConfigPtr + ChannelNumber;
        /** @implements #SWS_Ocu_00052 */
        /* PRQA S 4322 3 #KQR004322 */
        Ocu_Im_StartChannelProcess(
          (uint8)Ocu_ConfigPtr->HwUnitConfigPtr[channelConfig->ModuleIndex].ModuleInstance,
          channelConfig->AssignedHwChannel, (Ocu_PinStateType)Ocu_ChanRunInfo[ChannelNumber].ChannelPinAction);

        /** @implements #SWS_Ocu_00054 */
        Ocu_ChanRunInfo[ChannelNumber].ChannelRunState = OCU_CHANNEL_RUNNING;
    }
}

/**
 * @brief Check the channel running status
 * @param None
 * @retval Std_ReturnType check channel running status result
 * @return E_OK:All channels configured are stopped
 * E_NOT_OK:There is a running channel in the configured channel
 */
#if (OCU_DEV_ERROR_DETECT_API == STD_ON)
static FUNC(Std_ReturnType, OCU_CODE) Ocu_CheckChannelRunningStatus(void)
{
    Std_ReturnType status = E_OK;
    Ocu_ValueType  loop;

    for (loop = 0U; loop < Ocu_ConfigPtr->NumChannel; loop++)
    {
        if (Ocu_ChanRunInfo[loop].ChannelRunState == OCU_CHANNEL_RUNNING)
        {
            status = E_NOT_OK;
        }
    }

    return status;
}
#endif

/**
 * @brief Init Global Variables
 *
 */
static FUNC(void, OCU_CODE) Ocu_InitGlobalVariables(void)
{
    uint8 i;
    uint8 j;

    for (i = 0U; i < OCU_MAX_CCP_UNIT_NUM; ++i)
    {
        for (j = 0U; j < OCU_MAX_CCP_CHANNEL_NUM; ++j)
        {
            Ocu_assignedHwChannel[i][j] = 0xFFU;
        }
    }

    for (i = 0U; i < OCU_USER_CFG_CHANNEL_NUM; i++)
    {
        Ocu_ChanRunInfo[i].ChannelPinAction   = OCU_DISABLE;
        Ocu_ChanRunInfo[i].ChannelRunState    = OCU_CHANNEL_STOPPED;
        Ocu_ChanRunInfo[i].NotificationStatus = OCU_CHANNEL_NOTIFY_DISABLE;
    }
}

/**
 * @brief This function de-initializes the OCU module
 * @details
 * Syntax: void Ocu_DeInit(void)
 * Service ID[hex]: 0x01
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * @implements
 * #SWS_Ocu_00045,#SWS_Ocu_00046,#SWS_Ocu_00047,#SWS_Ocu_00048,#SWS_Ocu_00136,#SWS_Ocu_00137,#SWS_Ocu_00049,#SWS_Ocu_00050
 * @param None
 * @retval None
 *
 */
#if (OCU_DE_INIT_API == STD_ON)
FUNC(void, OCU_CODE) Ocu_DeInit(void)
{
#if (OCU_DEV_ERROR_DETECT_API == STD_ON)
    Std_ReturnType status = E_OK;

    if (FALSE == Ocu_Initialized)
    {
        /** @implements #SWS_Ocu_00050 */
        Ocu_ReportDetError(OCU_DEINIT_SERVICE_ID, OCU_E_UNINIT);
        status = E_NOT_OK;
    }
    else if (Ocu_CheckChannelRunningStatus() == E_NOT_OK)
    {
        /** @implements #SWS_Ocu_00137 */
        Ocu_ReportDetError(OCU_DEINIT_SERVICE_ID, OCU_E_PARAM_INVALID_STATE);
        status = E_NOT_OK;
    }
    else
    {
        /* Do nothing */
    }

    if (status == E_OK)
#endif
    {
        Ocu_ValueType loop;
        /* channel config pointer */
        const Ocu_ChannelConfigType *channelConfig;

        /* Deinit Hw Module */
        for (loop = 0U; loop < Ocu_ConfigPtr->NumHwUnit; loop++)
        {
            /** @implements #SWS_Ocu_00046,#SWS_Ocu_00136 */
            Ocu_Im_DeInitModule(Ocu_ConfigPtr->HwUnitConfigPtr + loop);
        }

        /* Deinit Hw Channels */
        /* PRQA S 1290 1 #KQR001290 */
        for (loop = 0; loop < Ocu_ConfigPtr->NumChannel; loop++)
        {
            channelConfig = Ocu_ConfigPtr->ChannelConfigPtr + loop;

            /** @implements #SWS_Ocu_00046 */
            /** @implements #SWS_Ocu_00048 */
            Ocu_Im_DeInitChannel((uint8)Ocu_ConfigPtr->HwUnitConfigPtr[channelConfig->ModuleIndex].ModuleInstance,
                                 channelConfig->AssignedHwChannel);
            /** @implements #SWS_Ocu_00047 */
            Ocu_ChanRunInfo[loop].NotificationStatus = OCU_CHANNEL_NOTIFY_DISABLE;
        }

        /* Initialize channel mapping to the state of power-on */
        Ocu_InitGlobalVariables();

#if (OCU_PB_FIXED_ADDRESS == STD_OFF)
        /* ConfigPtr points to NULL_PTR or the status is uninitialized */
        Ocu_ConfigPtr = NULL_PTR;
#endif
        Ocu_Initialized = FALSE;
    }
}
#endif

/**
 * @brief Service for OCU initialization
 * @details
 * Syntax: void Ocu_Init(const Ocu_ConfigType* ConfigPtr)
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * @implements
 * #SWS_Ocu_00035,#SWS_Ocu_00036,#SWS_Ocu_00010,#SWS_Ocu_00011,#SWS_Ocu_00037,#SWS_Ocu_00038,#SWS_Ocu_00039,#SWS_Ocu_00040,#SWS_Ocu_00043,#SWS_Ocu_00044
 * @param ConfigPtr Pointer to the configuration set
 * @retval void
 *
 */
FUNC(void, OCU_CODE) Ocu_Init(P2CONST(Ocu_ConfigType, AUTOMATIC, OCU_APPL_CONST) ConfigPtr)
{
#if (OCU_DEV_ERROR_DETECT_API == STD_ON)
    Std_ReturnType status = E_OK;

    if (TRUE == Ocu_Initialized)
    {
        /** @implements #SWS_Ocu_00043 */
        /** @implements #SWS_Ocu_00044 */
        Ocu_ReportDetError(OCU_INIT_SERVICE_ID, OCU_E_ALREADY_INITIALIZED);
        status = E_NOT_OK;
    }
    else
    {
#if (OCU_PB_FIXED_ADDRESS == STD_OFF)
        if (NULL_PTR == ConfigPtr)
#else
        if (NULL_PTR != ConfigPtr)
#endif
        {
            Ocu_ReportDetError(OCU_INIT_SERVICE_ID, OCU_E_INIT_FAILED);
            status = E_NOT_OK;
        }
    }

    if (E_OK == status)
#endif
    {
        uint8 hwUnit;
        uint8 loop;
        /* channel config pointer */
        const Ocu_ChannelConfigType *channelConfig;

#if (OCU_PB_FIXED_ADDRESS == STD_OFF)
        /* Store ConfigPtr to use any other APIs */
        Ocu_ConfigPtr = ConfigPtr;
#else
        (void)(ConfigPtr);
#endif
        /** Initialize logical channel mapping */
        Ocu_InitGlobalVariables();

        /** Initialise Ocu Module */
        for (loop = 0U; loop < Ocu_ConfigPtr->NumHwUnit; loop++)
        {
            Ocu_Im_InitModule(Ocu_ConfigPtr->HwUnitConfigPtr + loop, Ocu_ConfigPtr->CountDirection);
            /* register interrupt handler */
            Gpt_GeneralTimerRegisterCustomHandler((uint8)Ocu_ConfigPtr->HwUnitConfigPtr[loop].ModuleInstance, &Ocu_Isr);
        }
        /** @implements #SWS_Ocu_00036 */
        /** @implements #SWS_Ocu_00037 */
        /** @implements #SWS_Ocu_00038 */
        /* PRQA S 1290 1 #KQR001290 */
        for (loop = 0; loop < Ocu_ConfigPtr->NumChannel; loop++)
        {
            channelConfig = Ocu_ConfigPtr->ChannelConfigPtr + loop;
            /* Initialise Ocu channel */
            Ocu_Im_InitChannel(
              (uint8)Ocu_ConfigPtr->HwUnitConfigPtr[channelConfig->ModuleIndex].ModuleInstance, channelConfig);

            /* Restore Pin Action of Channel */
            Ocu_ChanRunInfo[loop].ChannelPinAction = channelConfig->PinAction;

            /** @implements #SWS_Ocu_00039 */
            Ocu_ChanRunInfo[loop].ChannelRunState = OCU_CHANNEL_STOPPED;

            /** @implements #SWS_Ocu_00040 */
            Ocu_ChanRunInfo[loop].NotificationStatus = OCU_CHANNEL_NOTIFY_DISABLE;

            hwUnit = (uint8)Ocu_ConfigPtr->HwUnitConfigPtr[channelConfig->ModuleIndex].ModuleInstance;

            /* save Maximum period of the module */
            Ocu_ChanRunInfo[loop].MaxValue = Ocu_ConfigPtr->HwUnitConfigPtr[channelConfig->ModuleIndex].MaxCounter;
            /* Mapping hardware units and physical channels (user configured) to logical channels */
            Ocu_assignedHwChannel[hwUnit][channelConfig->AssignedHwChannel] = loop;
        }
        Ocu_Initialized = TRUE;
    }
}

/**
 * @brief Compare unit interrupt handling
 * @param Module-Comparison of unit
 * @param ChannelNumber-OCU channel which has generated an interrupt
 */
FUNC(void, OCU_CODE)
Ocu_ProcessIsr(VAR(Ocu_ModuleInstanceType, OCU_VAR) Module, VAR(Ocu_ChannelType, OCU_VAR) ChannelNumber)
{
#if (OCU_NOTIFICATION_SUPPORTED == STD_ON)
    /* From Module and Physical Channel reversely query LogicChannel */
    uint8 AssignedChaIndex = Ocu_assignedHwChannel[Module][ChannelNumber];

    if ((NULL_PTR != Ocu_ConfigPtr->ChannelConfigPtr[AssignedChaIndex].NotifyFcn) &&
        (OCU_CHANNEL_NOTIFY_ENABLE == Ocu_ChanRunInfo[AssignedChaIndex].NotificationStatus))
    {
        Ocu_ConfigPtr->ChannelConfigPtr[AssignedChaIndex].NotifyFcn();
    }
    else
    {
        /* Do nothing */
    }
#endif
}

/**
 * @brief Compare unit interrupt handling
 * @param Module-Comparison of unit
 */
FUNC(void, OCU_CODE) Ocu_Isr(VAR(uint8, OCU_VAR) Module)
{
    uint32 flags = Ocu_Im_GetAllIntrFlags(Module);

    /* Obtain whether channel1 had generated an interrupt */
    if ((flags & (uint32)0x01U) > 0U)
    {
        /* Process interrupt */
        Ocu_ProcessIsr((Ocu_ModuleInstanceType)Module, OCU_CHANNEL1_CFG_INDEX);
    }
    else
    {
        /* Do nothing */
    }

    /* Obtain whether channel2 had generated an interrupt */
    if ((flags & (uint32)0x02U) > 0U)
    {
        /* Process interrupt */
        Ocu_ProcessIsr((Ocu_ModuleInstanceType)Module, OCU_CHANNEL2_CFG_INDEX);
    }
    else
    {
        /* Do nothing */
    }

    /* Obtain whether channel3 had generated an interrupt */
    if ((flags & (uint32)0x04U) > 0U)
    {
        /* Process interrupt */
        Ocu_ProcessIsr((Ocu_ModuleInstanceType)Module, OCU_CHANNEL3_CFG_INDEX);
    }
    else
    {
        /* Do nothing */
    }

    /* Obtain whether channel4 had generated an interrupt */
    if ((flags & (uint32)0x08U) > 0U)
    {
        /* Process interrupt */
        Ocu_ProcessIsr((Ocu_ModuleInstanceType)Module, OCU_CHANNEL4_CFG_INDEX);
    }
    else
    {
        /* Do nothing */
    }

    /*  Clear interrupt flags of HwModule */
    Ocu_Im_ClearAllInterFlags(Module);
}

/* EOF */
