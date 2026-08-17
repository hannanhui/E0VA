/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Gpt.c
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
/* PRQA S 3408 EOF #KQR003408 */
/* PRQA S 4342 EOF #KQR004342 */
/* PRQA S 2814 EOF #KQR002814 */
/* PRQA S 2824 EOF #KQR002824 */
/* PRQA S 2844 EOF #KQR002844 */
/* PRQA S 2201 EOF #KQR002201 */
/* PRQA S 2919 EOF #KQR002919 */
/* PRQA S 2934 EOF #KQR002934 */
/* PRQA S 4899 EOF #KQR004899 */
/******************************************************************************
 **                        Include Files
 ******************************************************************************/
#include "Gpt.h"

/* Hardware Specific */
#include "Gpt_Im.h"
#ifdef GPT_INTERNAL_TRACE_LOGGER
#include "kflog.h"
KF_REG_LOG(GPT, KF_LOG_OPT_LINE);
#endif

/** @implements #SWS_Gpt_00375 */
#if (GPT_DEV_ERROR_DETECT == STD_ON)
/* Included for the declaration of Det_ReportError() */
#include "Det.h"
#endif

#define GPT_C_SW_MAJOR_VERSION (1U)
#define GPT_C_SW_MINOR_VERSION (0U)
#define GPT_C_SW_PATCH_VERSION (0U)

/******************************************************************************
 **                        File Version Check
 ******************************************************************************/
#if (GPT_SW_MAJOR_VERSION != GPT_C_SW_MAJOR_VERSION)
#error "Gpt.c : Mismatch in Software Major Version"
#endif

#if (GPT_SW_MINOR_VERSION != GPT_C_SW_MINOR_VERSION)
#error "Gpt.c : Mismatch in Software Minor Version"
#endif

#if (GPT_SW_PATCH_VERSION != GPT_C_SW_PATCH_VERSION)
#error "Gpt.c : Mismatch in Software Minor Version"
#endif
/******************************************************************************
 **                        Macro  Definitions
 ******************************************************************************/
#define GPT_HW_CHAN_UNUSED ((uint8)0xFFU)
/******************************************************************************
 **                        Typedef  Definitions
 ******************************************************************************/
/**
 * @brief stores information about channel wake up,notification - each on
 * 1 bit
 * @implements
 */
typedef uint8 Gpt_ChannelState_t;
/******************************************************************************
 **                      Variables
 ******************************************************************************/
/**
 * @brief Static variable used for indicating the current GPT driver
 * mode.
 */
/* PRQA S 3229 1 #KQR003229  */
static VAR(Gpt_ModeType, GPT_VAR) Gpt_modeStatus = GPT_MODE_NORMAL;

/**
 * @brief Static variable used for indicating the current GPT driver mode.
 */
static VAR(Gpt_ChannelStatusType, GPT_VAR) Gpt_ChannelStatus[GPT_MAX_CHANNELS];

/**
 * @brief Static variable used for save gpt start timer value.
 */
static VAR(Gpt_ValueType, GPT_VAR) Gpt_ChannelSetTimerValue[GPT_MAX_CHANNELS];

/**
 * @brief  Static variable (pointer) used for storing the GPT driver
 * configuration data.
 */
static P2CONST(Gpt_ConfigType, GPT_VAR, GPT_VAR_FAST) Gpt_configPtr = NULL_PTR;

/**
 * @brief 255 means N/A
 *
 */
static VAR(uint8, GPT_VAR) Gpt_assignedHwChannel[GPT_MAX_CHANNELS];

#if ((GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON) || (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON))
/**
 * @brief Array of data structure elements storing timeout, channel mode, wakeup
 * and notification state
 */
static Gpt_ChannelState_t Gpt_channelState[GPT_MAX_CHANNELS];
#endif

#if (GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
/**
 * @brief predef timer start status
 */
/* PRQA S 3218 1 #KQR003218 */
static VAR(boolean, GPT_VAR) Gpt_PredefTimerStartStatus = FALSE;
#endif

/******************************************************************************
 **                      Function declarations
 ******************************************************************************/
FUNC(void, GPT_CODE) Gpt_Isr(uint8 HwChannel);
/******************************************************************************
 **                        Export Variables
 ******************************************************************************/
#if (GPT_PRECOMPILE_SUPPORT == STD_ON)
extern const Gpt_ConfigType Gpt_ConfigPredefined;
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
 **                      Local Functions
 ******************************************************************************/
#if (GPT_DEV_ERROR_DETECT == STD_ON)
/**
 * @brief short for det error function
 *
 * @param ApiId
 * @param ErrorId
 */
LOCAL_INLINE void Gpt_ReportDetError(uint8 ApiId, uint8 ErrorId)
{
    (void)Det_ReportError((uint16)GPT_MODULE_ID, (uint8)GPT_INSTANCE_ID, ApiId, ErrorId);
}
#endif

#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
/**
 * @brief Turn On Channel Wakeup Functionality
 *
 * @param Channel Gpt nominal channel index
 */
LOCAL_INLINE void Gpt_SetWakeUpFlagOn(uint32 Channel)
{
    Gpt_channelState[Channel] |= (uint8)0x02U;
}

/**
 * @brief Turn off Channel Wakeup Functionality
 *
 * @param Channel Gpt nominal channel index
 */
LOCAL_INLINE void Gpt_SetWakeUpFlagOff(uint32 Channel)
{
    Gpt_channelState[Channel] &= (uint8)(~0x02U);
}

/**
 * @brief Get channel wakeup flag
 *
 * @param Channel Gpt nominal channel index
 * @retval true
 * @retval false
 */
LOCAL_INLINE boolean Gpt_GetWakeUpFlag(uint32 Channel)
{
    return ((Gpt_channelState[(Channel)] & 0x02U) > 0U) ? TRUE : FALSE;
}
#endif

#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
/**
 * @brief
 *
 * @param Channel Gpt nominal channel index
 */
LOCAL_INLINE void Gpt_SetNotificationOn(const uint32 Channel)
{
    Gpt_channelState[Channel] |= (uint8)0x01U;
}

/**
 * @brief
 *
 * @param Channel Gpt nominal channel index
 */
LOCAL_INLINE void Gpt_SetNotificationOff(uint32 Channel)
{
    Gpt_channelState[Channel] &= (uint8)(~0x01U);
}

/**
 * @brief
 *
 * @param Channel Gpt nominal channel index
 */
LOCAL_INLINE boolean Gpt_GetNotificationFlag(const uint32 Channel)
{
    return ((Gpt_channelState[Channel] & ((uint8)0x01U)) > 0U) ? TRUE : FALSE;
}
#endif

#if (GPT_DEV_ERROR_DETECT == STD_ON) && (GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
/**
 * @brief Validate the specific T21 Timer is not used as normal Gpt Channel
 *
 * @param config
 * @retval TRUE: T21 is not occupied
 * @retval FALSE: T21 is occupied
 */
LOCAL_INLINE boolean Gpt_ValidatePredefTimerHwUnit(const Gpt_ConfigType *Config)
{
    uint8   chanCnt;
    boolean status = TRUE;

    for (chanCnt = 0U; chanCnt < Config->ChannelCount; chanCnt++)
    {
        if (Gpt_configPtr->PredefTimeConfig->PredefHwChannel == Config->ChannelConfigPtr[chanCnt].ChanHwIndex)
        {
            status = FALSE;
            break;
        }
        else
        {
            /* Do Nothing */
        }
    }
    return status;
}

LOCAL_INLINE boolean Gpt_ValidatePredefTimer(const Gpt_PredefTimerType TimerType)
{
    boolean retval;
    /*PRQA S 4115,4558 3 #KQR100001 */
    if (((TimerType == GPT_PREDEF_TIMER_1US_16BIT) || (TimerType == GPT_PREDEF_TIMER_1US_24BIT) ||
         (TimerType == GPT_PREDEF_TIMER_1US_32BIT) || (TimerType == GPT_PREDEF_TIMER_100US_32BIT)) &&
        (Gpt_PredefTimerStartStatus))
    {
        retval = TRUE;
    }
    else
    {
        retval = FALSE;
    }
    return retval;
}
#endif

#if (GPT_DEV_ERROR_DETECT == STD_ON)
LOCAL_INLINE Std_ReturnType Gpt_ValidateChannel(Gpt_ChannelType Channel, uint8 ApiId)
{
    Std_ReturnType status = E_NOT_OK;
    if (NULL_PTR == Gpt_configPtr)
    {
        Gpt_ReportDetError(ApiId, (uint8)GPT_E_UNINIT);
    }
    else if (Channel >= Gpt_configPtr->ChannelCount)
    {
        Gpt_ReportDetError(ApiId, (uint8)GPT_E_PARAM_CHANNEL);
    }
    else
    {
        status = E_OK;
    }
    return status;
}
#endif

/******************************************************************************
 **                      Function definitions
 ******************************************************************************/
#if (GPT_VERSION_INFO_API == STD_ON)
/**
 * @brief Returns the version information of this module.
 *
 * @param VersionInfoPtr
 *
 * @implements #SWS_Gpt_00279
 */
FUNC(void, GPT_CODE) Gpt_GetVersionInfo(Std_VersionInfoType *VersionInfoPtr)
{
#if (GPT_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == VersionInfoPtr)
    {
        Gpt_ReportDetError((uint8)GPT_GETVERSIONINFO_SID, (uint8)GPT_E_PARAM_POINTER);
    }
    else
#endif
    {
        VersionInfoPtr->vendorID         = (uint16)GPT_VENDOR_ID;
        VersionInfoPtr->moduleID         = (uint16)GPT_MODULE_ID;
        VersionInfoPtr->sw_major_version = (uint8)GPT_SW_MAJOR_VERSION;
        VersionInfoPtr->sw_minor_version = (uint8)GPT_SW_MINOR_VERSION;
        VersionInfoPtr->sw_patch_version = (uint8)GPT_SW_PATCH_VERSION;
    }
}
#endif

/**
 * @brief Initializes the GPT driver.
 *
 * @param ConfigPtr
 *
 * @implements #SWS_Gpt_00280
 */
FUNC(void, GPT_CODE) Gpt_Init(const Gpt_ConfigType *ConfigPtr)
{
    Gpt_ChannelType channelIndex;
    uint8           maxChannelCount;
    uint8           index;
#if (GPT_DEV_ERROR_DETECT == STD_ON)
    /** @implements #SWS_Gpt_00307 */
    if (NULL_PTR != Gpt_configPtr)
    {
        Gpt_ReportDetError((uint8)GPT_INIT_SID, (uint8)GPT_E_ALREADY_INITIALIZED);
    }
#if (GPT_PRECOMPILE_SUPPORT == STD_OFF)
    else if (NULL_PTR == ConfigPtr)
    {
        Gpt_ReportDetError((uint8)GPT_INIT_SID, (uint8)GPT_E_PARAM_POINTER);
    }
#else
    else if (NULL_PTR != ConfigPtr)
    {
        Gpt_ReportDetError((uint8)GPT_INIT_SID, (uint8)GPT_E_PARAM_POINTER);
    }
#endif
    else
    {
#endif
        /** @implements #SWS_Gpt_00006 */
#if (GPT_PRECOMPILE_SUPPORT == STD_ON)
        (void)ConfigPtr;
        Gpt_configPtr = &Gpt_ConfigPredefined;
#else
    Gpt_configPtr = ConfigPtr;
#endif
/** @implements #SWS_Gpt_00390 - The function Gpt_Init shall start all enabled GPT Predef
 * Timers at value 0 */
#if (GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
#if (GPT_DEV_ERROR_DETECT == STD_ON)
        /* Check Timer Source */
        if ((NULL_PTR == Gpt_configPtr->PredefTimeConfig) || (FALSE == Gpt_ValidatePredefTimerHwUnit(Gpt_configPtr)))
        {
            Gpt_ReportDetError((uint8)GPT_INIT_SID, (uint8)GPT_E_PARAM_PREDEF_TIMER);
            Gpt_PredefTimerStartStatus = FALSE;
        }
        else
#endif
        {
            /* Initialize and Start Predef Timers.*/
            Gpt_Im_StartPredefTimer(Gpt_configPtr->PredefTimeConfig);
            Gpt_PredefTimerStartStatus = TRUE;
        }
#endif
        for (index = 0U; index < GPT_MAX_CHANNELS; index++)
        {
            Gpt_assignedHwChannel[index] = GPT_HW_CHAN_UNUSED;
        }

        maxChannelCount = Gpt_configPtr->ChannelCount;
        /* Reset Channel STATUS */
        for (channelIndex = 0U; channelIndex < maxChannelCount; channelIndex++)
        {
            Gpt_ChannelConfigType channelConfig = Gpt_configPtr->ChannelConfigPtr[channelIndex];

            /* Init Channel  */
            Gpt_Im_Init(channelConfig.ChanHwIndex, channelConfig.ClkSrc, channelConfig.Prescale);
            /** @implements #SWS_Gpt_00107 */
            Gpt_Im_DisableInterrupt(channelConfig.ChanHwIndex);
#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
            /* Disable Channel Notification */
            Gpt_SetNotificationOff(channelIndex);
#endif
#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
            /* Disable Channel WakeUp */
            Gpt_SetWakeUpFlagOff(channelIndex);
#endif
            /* register interrupt handler */
            Gpt_GeneralTimerRegisterCustomHandler((uint8)channelConfig.ChanHwIndex, &Gpt_Isr);

            /* Set assigned Hw Chan */
            Gpt_assignedHwChannel[(uint8)channelConfig.ChanHwIndex] = channelIndex;
            Gpt_ChannelStatus[channelIndex]                         = GPT_CHANNEL_INITIALIZED;
            /* clear save timer value */
            Gpt_ChannelSetTimerValue[channelIndex] = 0U;
        }

        /** @implements #SWS_Gpt_00339 - The function Gpt_Init shall set the operation mode
         * of the GPT driver to "normal mode". */
        Gpt_modeStatus = GPT_MODE_NORMAL;

#if (GPT_DEV_ERROR_DETECT == STD_ON)
    }
#endif
}

#if (GPT_DEINIT_API == STD_ON)
/**
 * @brief De-initializes the GPT driver.
 *
 * @implements #SWS_Gpt_00281
 */
FUNC(void, GPT_CODE) Gpt_DeInit(void)
{
    Gpt_ChannelType   channelIndex;
    Gpt_TimerEnumType hwChannel;
    uint8             index;

#if (GPT_DEV_ERROR_DETECT == STD_ON)
    StatusType tempExit = E_OK;
    /** @implements #SWS_Gpt_00220 */
    if (NULL_PTR == Gpt_configPtr)
    {
        /* Call Det_ReportError */
        Gpt_ReportDetError((uint8)GPT_DEINIT_SID, (uint8)GPT_E_UNINIT);
        tempExit = E_NOT_OK;
    }
    else
    {
        for (channelIndex = 0U; channelIndex < Gpt_configPtr->ChannelCount; channelIndex++)
        {
            /** @implements #SWS_Gpt_00234 */
            if (GPT_CHANNEL_RUNNING == Gpt_ChannelStatus[channelIndex])
            {
                Gpt_ReportDetError((uint8)GPT_DEINIT_SID, (uint8)GPT_E_BUSY);
                tempExit = E_NOT_OK;
            }
            else
            {
                /* Do Nothing */
            }
        }
    }
    if (E_OK == tempExit)
    {
#endif
#if (GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
        /* Deinitialize and stop Predef timers.*/
        Gpt_Im_StopPredefTimer(Gpt_configPtr->PredefTimeConfig);
#endif
        /** @implements #SWS_Gpt_00391 */
        for (channelIndex = 0U; channelIndex < Gpt_configPtr->ChannelCount; channelIndex++)
        {
            hwChannel = Gpt_configPtr->ChannelConfigPtr[channelIndex].ChanHwIndex;

            /** @implements #SWS_Gpt_00008 */
            /* Deinit Hardware Channel */
            Gpt_Im_Deinit(hwChannel);

            /* Reset Channel STATUS */
            Gpt_ChannelStatus[channelIndex] = GPT_CHANNEL_UNINITIALIZED;
            /* clear save timer value */
            Gpt_ChannelSetTimerValue[channelIndex] = 0U;
#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
            /* Close Channel Notify */
            Gpt_SetNotificationOff(channelIndex);
#endif
#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
            /* Disable Channel WakeUp */
            Gpt_SetWakeUpFlagOff(channelIndex);
#endif
        }

        /* Reset All Assigned HwChannel */
        for (index = 0U; index < GPT_MAX_CHANNELS; index++)
        {
            Gpt_assignedHwChannel[index] = GPT_HW_CHAN_UNUSED;
        }

        /** @implements #SWS_Gpt_00363 */
        /* Reset Local ChannelConfig pointer */
        Gpt_configPtr = NULL_PTR;
        /* Reset Gpt Module Statue */
        Gpt_modeStatus = GPT_MODE_NORMAL;

#if (GPT_DEV_ERROR_DETECT == STD_ON)
    }
    else
    {
        /* Do Nothing */
    }
#endif
}
#endif

#if (GPT_TIME_ELAPSED_API == STD_ON)
/**
 * @brief Returns the time already elapsed.
 *
 * @param Channel
 * @return Gpt_ValueType
 *
 * @implements #SWS_Gpt_00282
 */
FUNC(Gpt_ValueType, GPT_CODE) Gpt_GetTimeElapsed(Gpt_ChannelType Channel)
{
    Gpt_ValueType     tempReturn;
    Gpt_TimerEnumType hwChannel;
#if (GPT_DEV_ERROR_DETECT == STD_ON)
    /** @implements #SWS_Gpt_00222,#SWS_Gpt_00210 */
    if (E_OK == Gpt_ValidateChannel(Channel, GPT_GETTIMEELAPSED_SID))
    {
#endif
        /** @implements #SWS_Gpt_00295,#SWS_Gpt_00210 */
        if (GPT_CHANNEL_INITIALIZED != Gpt_ChannelStatus[Channel])
        {
            if (GPT_CHANNEL_EXPIRED == Gpt_ChannelStatus[Channel])
            {
                /** @implements #SWS_Gpt_00299 */
                tempReturn = Gpt_ChannelSetTimerValue[Channel];
            }
            else
            {
                /** @implements #SWS_Gpt_00297 */
                /* Get Channel Hw Index */
                hwChannel  = Gpt_configPtr->ChannelConfigPtr[Channel].ChanHwIndex;
                tempReturn = Gpt_Im_GetTimeElapsed(hwChannel);
            }
        }
        else
        {
            tempReturn = 0U;
        }

#if (GPT_DEV_ERROR_DETECT == STD_ON)
    }
    else
    {
        /* Do Nothing */
    }
#endif
    return (tempReturn);
}
#endif

#if (GPT_TIME_REMAINING_API == STD_ON)
/**
 * @brief Returns the time remaining until the target time is reached.
 *
 * @param Channel
 * @return Gpt_ValueType
 *
 * @implements #SWS_Gpt_00283, #SWS_Gpt_00083
 */
FUNC(Gpt_ValueType, GPT_CODE) Gpt_GetTimeRemaining(Gpt_ChannelType Channel)
{
    Gpt_ValueType     tempReturn;
    Gpt_TimerEnumType hwChannel;
#if (GPT_DEV_ERROR_DETECT == STD_ON)
    /** @implements #SWS_Gpt_00223,#SWS_Gpt_00211 */
    if (E_OK == Gpt_ValidateChannel(Channel, GPT_GETTIMEREMAINING_SID))
    {
#endif
        if (GPT_CHANNEL_INITIALIZED != Gpt_ChannelStatus[Channel])
        {
            if (GPT_CHANNEL_EXPIRED == Gpt_ChannelStatus[Channel])
            {
                /** @implements #SWS_Gpt_00305 */
                tempReturn = 0U;
            }
            else
            {
                /** @implements #SWS_Gpt_00083,#SWS_Gpt_00303 */
                hwChannel  = Gpt_configPtr->ChannelConfigPtr[Channel].ChanHwIndex;
                tempReturn = Gpt_Im_GetTimeRemaining(hwChannel);
            }
        }
        else
        {
            /** @implements #SWS_Gpt_00301 */
            tempReturn = 0U;
        }

#if (GPT_DEV_ERROR_DETECT == STD_ON)
    }
    else
    {
        /* Do Nothing */
    }
#endif
    return (tempReturn);
}
#endif

/**
 * @brief Starts a timer channel.
 *
 * @param Channel
 * @param Value
 *
 * @implements #SWS_Gpt_00284
 */
FUNC(void, GPT_CODE) Gpt_StartTimer(Gpt_ChannelType Channel, Gpt_ValueType Value)
{
    Gpt_TimerEnumType hwChannel;
#if (GPT_DEV_ERROR_DETECT == STD_ON)
    /** @implements #SWS_Gpt_00212,#SWS_Gpt_00224  */
    if (E_NOT_OK == Gpt_ValidateChannel(Channel, GPT_STARTTIMER_SID))
    {
        /* Do Nothing */
    }
    else if ((Value == 0U) || (Value > Gpt_configPtr->ChannelConfigPtr[Channel].ChanTickValueMax))
    {
        /** @implements #SWS_Gpt_00218 */
        Gpt_ReportDetError((uint8)GPT_STARTTIMER_SID, (uint8)GPT_E_PARAM_VALUE);
    }
    else if (GPT_CHANNEL_RUNNING == Gpt_ChannelStatus[Channel])
    {
        /** @implements #SWS_Gpt_00084 */
        Gpt_ReportDetError((uint8)GPT_STARTTIMER_SID, (uint8)GPT_E_BUSY);
    }
    else
#endif
    {

        /** @implements #SWS_Gpt_00274 */
        hwChannel = Gpt_configPtr->ChannelConfigPtr[Channel].ChanHwIndex;

        /* Call low level start timer */
        /** @implements #SWS_Gpt_00274  */
        Gpt_Im_StartTimer(hwChannel, Value, Gpt_configPtr->ChannelConfigPtr[Channel].ChanMode);
        /** @implements #SWS_Gpt_00364 */
        /* Change GPT status */
        Gpt_ChannelStatus[Channel]        = GPT_CHANNEL_RUNNING;
        Gpt_ChannelSetTimerValue[Channel] = Value;
#ifdef GPT_INTERNAL_TRACE_LOGGER
        kf_printf("Gpt Channel %d is Started", Channel);
#endif
    }
}

/**
 * @brief Stops a timer channel.
 *
 * @param Channel
 *
 * @implements #SWS_Gpt_00285
 */
FUNC(void, GPT_CODE) Gpt_StopTimer(Gpt_ChannelType Channel)
{
    Gpt_TimerEnumType hwChannel;
#if (GPT_DEV_ERROR_DETECT == STD_ON)
    /** @implements #SWS_Gpt_00213,#SWS_Gpt_00225 */
    if (E_OK == Gpt_ValidateChannel(Channel, GPT_STOPTIMER_SID))
    {
#endif
        if (GPT_CHANNEL_RUNNING == Gpt_ChannelStatus[Channel])
        {
            hwChannel = Gpt_configPtr->ChannelConfigPtr[Channel].ChanHwIndex;

            /** @implements #SWS_Gpt_00013 */
            Gpt_Im_StopTimer(hwChannel);
            /** @implements #SWS_Gpt_00343 */
            Gpt_ChannelStatus[Channel] = GPT_CHANNEL_STOPPED;

#ifdef GPT_INTERNAL_TRACE_LOGGER
            kf_printf("Gpt Channel %d is Stopped", Channel);
#endif
        }
        else
        {
            /** @implements #SWS_Gpt_00099,#SWS_Gpt_00344 */
        }
#if (GPT_DEV_ERROR_DETECT == STD_ON)
    }
    else
    {
        /* Do Nothing */
    }
#endif
}

#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
/**
 * @brief Service for setting the mode of the operation.
 *
 * @param Mode
 *
 * @implements #SWS_Gpt_00288 #SWS_Gpt_00201, #SWS_Gpt_00255
 */
FUNC(void, GPT_CODE) Gpt_SetMode(Gpt_ModeType Mode)
{
    uint32            channelIndex;
    Gpt_TimerEnumType hwChannel;
#if (GPT_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Gpt_configPtr)
    {
        /* Call Det_ReportError */
        Gpt_ReportDetError((uint8)GPT_SETMODE_SID, (uint8)GPT_E_UNINIT);
    }
    else if ((GPT_MODE_NORMAL != Mode) && (GPT_MODE_SLEEP != Mode))
    {
        Gpt_ReportDetError((uint8)GPT_SETMODE_SID, (uint8)GPT_E_PARAM_MODE);
    }
    else
    {
#endif
        /* TODO: Enter critical section */
        if (GPT_MODE_SLEEP == Mode)
        {
            for (channelIndex = 0U; channelIndex < Gpt_configPtr->ChannelCount; channelIndex++)
            {
                if (Gpt_ChannelStatus[channelIndex] == GPT_CHANNEL_RUNNING)
                {
                    /* Check channel wakeup capability, if not then stop the
                     * running channel */
                    if ((Gpt_GetWakeUpFlag(channelIndex)) == FALSE)
                    {
                        hwChannel = Gpt_configPtr->ChannelConfigPtr[channelIndex].ChanHwIndex;
                        Gpt_Im_StopTimer(hwChannel);
                        Gpt_ChannelStatus[channelIndex] = GPT_CHANNEL_STOPPED;
                    }
                }
            }
            /* Update driver status to GPT_MODE_SLEEP */
            Gpt_modeStatus = GPT_MODE_SLEEP;
        }
        else
        {
            /* Update driver status to GPT_MODE_NORMAL */
            Gpt_modeStatus = GPT_MODE_NORMAL;
        }
        /* TODO: Exit critical section */

#if (GPT_DEV_ERROR_DETECT == STD_ON)
    }
#endif
}
#endif

#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
/**
 * @brief Service for enabling the notification for a channel during runtime
 *
 * @param Channel - channel used
 *
 * @implements #SWS_Gpt_00331
 */
FUNC(void, GPT_CODE) Gpt_EnableNotification(Gpt_ChannelType Channel)
{
    const Gpt_ChannelConfigType *localChannelPtr;
#if (GPT_DEV_ERROR_DETECT == STD_ON)
    /** @implements #SWS_Gpt_00226,#SWS_Gpt_00214 */
    if (E_OK == Gpt_ValidateChannel(Channel, GPT_ENABLENOTIFICATION_SID))
    {
#endif
        /* PRQA S 0488 1 #KQR000488  */
        localChannelPtr = Gpt_configPtr->ChannelConfigPtr + Channel;

        if (localChannelPtr->NotifyFcn != NULL_PTR)
        {
            /** @implements #SWS_Gpt_00014 */
            /* Set the Notification flag */
            Gpt_SetNotificationOn(Channel);
#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
            if (Gpt_GetWakeUpFlag(Channel) == FALSE)
#endif
            {
                Gpt_Im_EnableInterrupt(localChannelPtr->ChanHwIndex);
            }
#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
            else
            {
                /* Do Nothing */
            }
#endif

#ifdef GPT_INTERNAL_TRACE_LOGGER
            kf_printf("GPT Channel %d Notification On", Channel);
#endif
        }
        else
        {
#if (GPT_DEV_ERROR_DETECT == STD_ON)
            /** @implements #SWS_Gpt_00337 */
            Gpt_ReportDetError((uint8)GPT_ENABLENOTIFICATION_SID, (uint8)GPT_E_PARAM_CHANNEL);
#endif
        }

#if (GPT_DEV_ERROR_DETECT == STD_ON)
    }
    else
    {
        /* Do Nothing */
    }
#endif
}

/**
 * @brief Disables the interrupt notification for a channel (relevant in normal mode)
 *
 * @param Channel - channel used
 *
 * @implements #SWS_Gpt_00331
 */
FUNC(void, GPT_CODE) Gpt_DisableNotification(Gpt_ChannelType Channel)
{
    const Gpt_ChannelConfigType *localChannelPtr;
#if (GPT_DEV_ERROR_DETECT == STD_ON)
    /** @implements #SWS_Gpt_00227,#SWS_Gpt_00217 */
    if (E_OK == Gpt_ValidateChannel(Channel, GPT_DISABLENOTIFICATION_SID))
    {
#endif
        /* PRQA S 0488 1 #KQR000488  */
        localChannelPtr = (Gpt_configPtr->ChannelConfigPtr + Channel);

        if (localChannelPtr->NotifyFcn != NULL_PTR)
        {
            /** @implements #SWS_Gpt_00015 */
            /* Clear the Notification flag */
            Gpt_SetNotificationOff(Channel);

#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
            if (Gpt_GetWakeUpFlag(Channel) == FALSE)
#endif
            {
                if (localChannelPtr->ChanMode == GPT_MODE_CONTINUOUS)
                {
                    Gpt_Im_DisableInterrupt(localChannelPtr->ChanHwIndex);
#ifdef GPT_INTERNAL_TRACE_LOGGER
                    kf_printf("GPT Channel %d Notification Off", Channel);
#endif
                }
                else
                {
                    /* one shot mode cannot disable interrupt */
                }
            }
        }
        else
        {
#if (GPT_DEV_ERROR_DETECT == STD_ON)
            /** @implements #SWS_Gpt_00379 */
            Gpt_ReportDetError((uint8)GPT_DISABLENOTIFICATION_SID, (uint8)GPT_E_PARAM_POINTER);
#endif
        }

#if (GPT_DEV_ERROR_DETECT == STD_ON)
    }
    else
    {
        /* Do Nothing */
    }
#endif
}
#endif

#if ((GPT_REPORT_WAKEUP_SOURCE == STD_ON) && (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON))
/* SWS_Gpt_00127 */

/**
 * @brief
 *
 * @param Channel
 *
 * @implements #SWS_Gpt_00289
 */
FUNC(void, GPT_CODE) Gpt_DisableWakeup(Gpt_ChannelType Channel)
{
    const Gpt_ChannelConfigType *localChannelPtr;
#if (GPT_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Gpt_configPtr)
    {
        /* Call Det_ReportError */
        Gpt_ReportDetError((uint8)GPT_DISABLEWAKEUP_SID, (uint8)GPT_E_UNINIT);
    }
    else if (Channel >= Gpt_configPtr->ChannelCount)
    {
        Gpt_ReportDetError((uint8)GPT_DISABLEWAKEUP_SID, (uint8)GPT_E_PARAM_CHANNEL);
    }
    else
    {
#endif
        localChannelPtr = (Gpt_configPtr->ChannelConfigPtr + Channel);
        if (localChannelPtr->EnableWakeUp == (boolean)FALSE)
        {
#if (GPT_DEV_ERROR_DETECT == STD_ON)
            Gpt_ReportDetError((uint8)GPT_DISABLEWAKEUP_SID, (uint8)GPT_E_PARAM_CHANNEL);
#endif
        }
        else
        {
#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
            if (GPT_GET_NOTIFICATION(Channel) == 0U)
#endif
            {
                if (localChannelPtr->ChanMode == GPT_MODE_CONTINUOUS)
                {
                    Gpt_Im_DisableInterrupt(localChannelPtr->ChanHwIndex);
                }
            }
        }
#if (GPT_DEV_ERROR_DETECT == STD_ON)
    }
#endif
}

/**
 * @brief
 *
 * @param Channel
 *
 * @implements #SWS_Gpt_00290
 */
FUNC(void, GPT_CODE) Gpt_EnableWakeup(Gpt_ChannelType Channel)
{
    const Gpt_ChannelConfigType *localChannelPtr;
#if (GPT_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Gpt_configPtr)
    {
        /* Call Det_ReportError */
        Gpt_ReportDetError((uint8)GPT_ENABLEWAKEUP_SID, (uint8)GPT_E_UNINIT);
    }
    /* @violates @ref GPT_C_REF_5 Violates MISRA 2004 Required Rule 17.4,
     * pointer arithmetic other than array indexing used */
    else if (Channel >= Gpt_configPtr->ChannelCount)
    {
        Gpt_ReportDetError((uint8)GPT_ENABLEWAKEUP_SID, (uint8)GPT_E_PARAM_CHANNEL);
    }
    else
    {
#endif
        localChannelPtr = (Gpt_configPtr->ChannelConfigPtr + Channel);
        if (localChannelPtr->EnableWakeUp == (boolean)FALSE)
        {
#if (GPT_DEV_ERROR_DETECT == STD_ON)
            Gpt_ReportDetError((uint8)GPT_DISABLEWAKEUP_SID, (uint8)GPT_E_PARAM_CHANNEL);
#endif
        }
        else
        {
            GPT_SET_WAKE_UP(Channel, TRUE);
#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
            if (GPT_GET_NOTIFICATION(Channel) == 0U)
#endif
            {
                Gpt_Im_EnableInterrupt(localChannelPtr->ChanHwIndex);
            }
        }

#if (GPT_DEV_ERROR_DETECT == STD_ON)
    }
#endif
}

/**
 * @brief Checks if a wake capable GPT Channel is the source for a wakeup event
 * and calls the ECU state manager service EcuM_SetWakeupEvent in case of a
 * valid event
 *
 * @param WakeupSource
 *
 * @implements #SWS_Gpt_00328
 */
FUNC(void, GPT_CODE) Gpt_CheckWakeup(EcuM_WakeupSourceType WakeupSource)
{
    Gpt_ChannelType channelIndex;
#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
#if (GPT_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Gpt_configPtr)
    {
        /* Call Det_ReportError */
        Gpt_ReportDetError((uint8)GPT_CHECKWAKEUP_SID, (uint8)GPT_E_UNINIT);
    }
    else
    {
#endif

        for (channelIndex = 0U; channelIndex < Gpt_configPtr->ChannelCount; channelIndex++)
        {
            if ((TRUE == Gpt_GetWakeUpFlag(channelIndex)) &&
                (Gpt_configPtr->ChannelConfigPtr[channelIndex].WakeupSource == WakeupSource))
            {
                if (TRUE == GPT_GET_WAKEUP_GEN(channelIndex))
                {
                    /* SWS_Gpt_00321 */
                    /* Calling EcuM_SetWakeupEvent */
                    EcuM_SetWakeupEvent(WakeupSource);
                    GPT_SET_WAKEUP_GEN(channelIndex, FALSE);
                    break;
                }
            }
        }

#if (GPT_DEV_ERROR_DETECT == STD_ON)
    }
#endif
#endif
}
#endif

#if (GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
/**
 * @brief Delivers the current value of the desired GPT Predef Timer.
 *
 * @param PredefTimer
 * @param TimeValuePtr
 * @return Std_ReturnType
 */
FUNC(Std_ReturnType, GPT_CODE) Gpt_GetPredefTimerValue(Gpt_PredefTimerType PredefTimer, uint32 *TimeValuePtr)
{
    Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;
#if (GPT_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Gpt_configPtr)
    {
        /** @implements #SWS_Gpt_00402,#SWS_Gpt_00398 */
        Gpt_ReportDetError((uint8)GPT_GET_PREDEF_TIMERVALUE_SID, (uint8)GPT_E_UNINIT);
    }
    else if (NULL_PTR == TimeValuePtr)
    {
        /** @implements #SWS_Gpt_00403 */
        Gpt_ReportDetError((uint8)GPT_GET_PREDEF_TIMERVALUE_SID, (uint8)GPT_E_PARAM_POINTER);
    }
    else if (FALSE == Gpt_ValidatePredefTimer(PredefTimer))
    {
        /** @implements #SWS_Gpt_00399,#SWS_Gpt_00400 */
        Gpt_ReportDetError((uint8)GPT_GET_PREDEF_TIMERVALUE_SID, (uint8)GPT_E_PARAM_PREDEF_TIMER);
    }
    else if (GPT_MODE_SLEEP == Gpt_modeStatus)
    {
        /** @implements #SWS_Gpt_00401 */
        Gpt_ReportDetError((uint8)GPT_GET_PREDEF_TIMERVALUE_SID, (uint8)GPT_E_MODE);
    }
    else
    {
#endif
        /** @implements #SWS_Gpt_00395,#SWS_Gpt_00396 */
        *TimeValuePtr = Gpt_Im_GetPredefTimerValue(Gpt_configPtr->PredefTimeConfig, PredefTimer);
        ret           = (Std_ReturnType)E_OK;
#if (GPT_DEV_ERROR_DETECT == STD_ON)
    }
#endif
    return ret;
}

#endif

/**
 * @brief
 *
 * @param HwChannel General Timer Channel
 */
FUNC(void, GPT_CODE) Gpt_Isr(uint8 HwChannel)
{
    uint8                        gptChannel;
    const Gpt_ChannelConfigType *gptChanConfigPtr;

    /* Find Hw Channel related Gpt Channel */
    gptChannel = Gpt_assignedHwChannel[HwChannel];
    if (gptChannel == GPT_HW_CHAN_UNUSED)
    {
        /* Unintended interrupt call */
        /* Disable Channel Interrupt */
        Gpt_Im_DisableInterrupt((Gpt_TimerEnumType)HwChannel);
    }
    else
    {
        /* First Clear Interrupt Flag */
        Gpt_Im_ClearInterrupt((Gpt_TimerEnumType)HwChannel);

        /* Get Gpt Channel Config */
        /* PRQA S 0488 1 #KQR000488  */
        gptChanConfigPtr = Gpt_configPtr->ChannelConfigPtr + gptChannel;
#if ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) || (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
#endif
        /* One-Shot Mode */
        if (GPT_MODE_ONE_SHOT == gptChanConfigPtr->ChanMode)
        {
            /* Stop Timer Channel */
            Gpt_Im_StopTimer((Gpt_TimerEnumType)HwChannel);
            Gpt_ChannelStatus[gptChannel] = GPT_CHANNEL_EXPIRED;
        }
        else
        {
            /* Do Nothing */
        }
#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
        if ((TRUE == Gpt_GetNotificationFlag(gptChannel)) && (NULL_PTR != gptChanConfigPtr->NotifyFcn))
        {
            gptChanConfigPtr->NotifyFcn();
        }
        else
        {
            /* Do Noting */
        }
#endif
    }
}

/* EOF */
