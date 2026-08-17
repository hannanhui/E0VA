/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Gpt.h
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
#ifndef GPT_H
#define GPT_H

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
/* PRQA S 3205 EOF #KQR003205 */
/******************************************************************************
 **                        Include Files
 ******************************************************************************/
#include "Std_Types.h"
#include "Gpt_Cfg.h"
#include "Gpt_Types.h"

#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
#include "EcuM.h"
#endif

/******************************************************************************
 **                        File Version Check
 ******************************************************************************/
/* SWS_BSW_00059 */
#define GPT_VENDOR_ID (0xCCU)
#define GPT_MODULE_ID (100U) /* From AUTOSAR_TR_BSWModuleList */

/* Vendor Specific Version */
#define GPT_SW_MAJOR_VERSION (1U)
#define GPT_SW_MINOR_VERSION (0U)
#define GPT_SW_PATCH_VERSION (0U)
/******************************************************************************
 **                        Macro  Definitions
 ******************************************************************************/
#define GPT_INSTANCE_ID ((uint8)0x00U)

/**
 * @brief API service ID for Gpt GetVersionInfo function.
 * @details Parameters used when raising an error or exception.
 *
 * @implements
 */
#define GPT_GETVERSIONINFO_SID ((uint8)0x00U)
/**
 * @brief API service ID for Gpt Init function.
 * @details Parameters used when raising an error or exception.
 *
 * @implements
 */
#define GPT_INIT_SID ((uint8)0x01U)
/**
 * @brief API service ID for Gpt DeInit function.
 * @details Parameters used when raising an error or exception.
 *
 * @implements
 */
#define GPT_DEINIT_SID ((uint8)0x02U)
/**
 * @brief API service ID for Gpt GetTimeElapsed function.
 * @details Parameters used when raising an error or exception.
 *
 * @implements
 */
#define GPT_GETTIMEELAPSED_SID ((uint8)0x03U)
/**
 * @brief API service ID for Gpt GetTimeRemaining function.
 * @details Parameters used when raising an error or exception.
 *
 * @implements
 */
#define GPT_GETTIMEREMAINING_SID ((uint8)0x04U)
/**
 * @brief API service ID for Gpt StartTimer function.
 * @details Parameters used when raising an error or exception.
 *
 * @implements
 */
#define GPT_STARTTIMER_SID ((uint8)0x05U)
/**
 * @brief API service ID for Gpt StopTimer function.
 * @details Parameters used when raising an error or exception.
 *
 * @implements
 */
#define GPT_STOPTIMER_SID ((uint8)0x06U)
/**
 * @brief API service ID for Gpt EnableNotification function.
 * @details Parameters used when raising an error or exception.
 *
 * @implements
 */
#define GPT_ENABLENOTIFICATION_SID ((uint8)0x07U)
/**
 * @brief API service ID for Gpt DisableNotification function.
 * @details Parameters used when raising an error or exception.
 *
 * @implements
 */
#define GPT_DISABLENOTIFICATION_SID ((uint8)0x08U)
/**
 * @brief API service ID for Gpt SetMode function.
 * @details Parameters used when raising an error or exception.
 *
 * @implements
 */
#define GPT_SETMODE_SID ((uint8)0x09U)
/**
 * @brief API service ID for Gpt DisableWakeup function.
 * @details Parameters used when raising an error or exception.
 *
 * @implements
 */
#define GPT_DISABLEWAKEUP_SID ((uint8)0x0AU)
/**
 * @brief API service ID for Gpt EnableWakeup function.
 * @details Parameters used when raising an error or exception.
 *
 * @implements
 */
#define GPT_ENABLEWAKEUP_SID ((uint8)0x0BU)
/**
 * @brief API service ID for Gpt CheckWakeup function.
 * @details Parameters used when raising an error or exception.
 *
 * @implements
 */
#define GPT_CHECKWAKEUP_SID ((uint8)0x0CU)
/**
 * @brief API service ID for Gpt GetPredefTimerValue function.
 * @details Parameters used when raising an error or exception.
 *
 * @implements
 */
#define GPT_GET_PREDEF_TIMERVALUE_SID ((uint8)0x0DU)

/**
 * @brief API service called without module initialization
 *
 * @implements #SWS_Gpt_00345
 */
#define GPT_E_UNINIT ((uint8)0x0AU)

/**
 * @brief API service called when timer channel is still busy (running)
 *
 * @implements #SWS_Gpt_00346
 */
#define GPT_E_BUSY ((uint8)0x0BU)

/**
 * @brief API service called when driver is in wrong mode
 *
 * @implements #SWS_Gpt_00387
 */
#define GPT_E_MODE ((uint8)0x0CU)

/**
 * @brief API service for initialization called when already initialized
 *
 * @implements #SWS_Gpt_00347
 */
#define GPT_E_ALREADY_INITIALIZED ((uint8)0x0DU)

/**
 * @brief API error return code: Init function failed
 *
 * @implements #SWS_Gpt_00404
 */
#define GPT_E_INIT_FAILED ((uint8)0x0EU)

/**
 * @brief API parameter checking: invalid channel
 *
 * @implements #SWS_Gpt_00348
 */
#define GPT_E_PARAM_CHANNEL ((uint8)0x14U)

/**
 * @brief API parameter checking: invalid value
 *
 * @implements #SWS_Gpt_00349
 */
#define GPT_E_PARAM_VALUE ((uint8)0x15U)

/**
 * @brief API parameter checking: invalid pointer
 *
 * @implements #SWS_Gpt_00350
 */
#define GPT_E_PARAM_POINTER ((uint8)0x16U)

/**
 * @brief API parameter checking: invalid Predef Timer
 *
 * @implements #SWS_Gpt_00388
 */
#define GPT_E_PARAM_PREDEF_TIMER ((uint8)0x17U)

/**
 * @brief API parameter checking: invalid mode
 *
 * @implements #SWS_Gpt_00351
 */
#define GPT_E_PARAM_MODE ((uint8)0x1FU)

/**
 * @brief Max Number configurable channels. used for pre-compile time
 *
 */
#define GPT_MAX_CHANNELS ((uint8)7U)
/******************************************************************************
 **                        Typedef  Definitions
 ******************************************************************************/
/**
 * @brief This enumerated type allows the selection of different power modes.
 *
 * @implements Gpt_ModeType_enumeration
 */
typedef enum
{
    GPT_MODE_NORMAL, /** @brief GPT Normal operation mode of the GPT */
    GPT_MODE_SLEEP   /**  @brief GPT sleep mode */
} Gpt_ModeType;

/**
 * @brief
 *
 * @implements #SWS_Gpt_00383
 */
typedef enum
{
    GPT_PREDEF_TIMER_1US_16BIT,
    GPT_PREDEF_TIMER_1US_24BIT,
    GPT_PREDEF_TIMER_1US_32BIT,
    GPT_PREDEF_TIMER_100US_32BIT
} Gpt_PredefTimerType;

/**
 * @brief Numeric ID of a GPT channel.
 *
 * @implements #SWS_Gpt_00358
 */
typedef uint8 Gpt_ChannelType;

/**
 * @brief Type for reading and setting the timer values (in number of ticks).
 *
 * @implements #SWS_Gpt_00359
 */
typedef uint32 Gpt_ValueType;

#if (GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
/**
 * @brief Gpt Predefined Timer Configuration Type
 *
 */
/* PRQA S 3630 ++ #KQR003630 */
typedef struct
{
    /** @brief GPT hw channel ID for Predef Timer */
    /**
     * 1.T21 is a 32-bit timer, You can use GPT_PREDEF_TIMER_1US_16BIT, GPT_PREDEF_TIMER_1US_24BIT,
     * GPT_PREDEF_TIMER_1US_32BIT, GPT_PREDEF_TIMER_100US_32BIT, and GPt_predef_timer_100us_32bit. If you configure
     * other timers, you can only use GPT_PREDEF_TIMER_1US_16BIT
     * 2.After selecting the clock source and frequency division, one count represents 1us
     */
    Gpt_TimerEnumType PredefHwChannel;
    /** @brief prescaler value*/
    uint32 Prescaler;
    /** @brief Clock source */
    Gpt_ClkSourceType ClockSource;
} Gpt_PredefTimeConfigType;
#endif

typedef struct
{
    /** @brief Specify individual hardware channel index num */
    Gpt_TimerEnumType ChanHwIndex;
    /** @brief Specifies the behavior of the timer channel after the target time
     * is reached. */
    Gpt_ChannelModeType ChanMode;
    /** @brief Hardware Type of Gpt channel, Current is GPTimer */
    uint8 ChanHwType;
    /** @brief Maximum value in ticks, the timer channel is able to count. With the next tick, the timer rolls over to
     * zero */
    uint32 ChanTickValueMax;
    /** @brief Channel Clock Source */
    Gpt_ClkSourceType ClkSrc;
    /** @brief timer channel prescale */
    uint32 Prescale;
    /** @brief enable channel wakeup */
    boolean EnableWakeUp;
#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
    Gpt_NotificationFcnType NotifyFcn;
#endif
#if ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
    /** @brief channel wakeup source  */
    EcuM_WakeupSourceType WakeupSource;
#endif
} Gpt_ChannelConfigType;

/**
 * @brief
 * @implements #SWS_Gpt_00357
 */
typedef struct
{
    /** @brief Total Timer Count */
    uint8 ChannelCount;
    /** @brief Pointer to Channel Config Array */
    const Gpt_ChannelConfigType *ChannelConfigPtr;
#if (GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
    /** @brief Pointer to Predef Timer Config  */
    const Gpt_PredefTimeConfigType *PredefTimeConfig;
#endif
} Gpt_ConfigType;
/* PRQA S 3630 -- #KQR003630 */
/******************************************************************************
 **                        Export Variables
 ******************************************************************************/

/******************************************************************************
 **                        Export Functions
 ******************************************************************************/
#if (GPT_VERSION_INFO_API == STD_ON)
/******************************************************************************
 * Function Name   : Gpt_GetVersionInfo
 *
 * Service ID   : 0x00
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Reentrant
 *
 * Parameters(in)   :   None
 *
 * Parameters(inout)   : None
 *
 * Parameters(out)   : VersionInfoPtr : Pointer to where to store the version information of this module.
 *
 * Return value   : None
 *
 * Description   : Returns the version information of this module.
 *
 ******************************************************************************/
FUNC(void, GPT_CODE) Gpt_GetVersionInfo(Std_VersionInfoType *VersionInfoPtr);
#endif

/******************************************************************************
 * Function Name   : Gpt_Init
 *
 * Service ID   : 0x01
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Not reentrant
 *
 * Parameters(in)   :   configPtr : Pointer to a selected configuration structure
 *
 * Parameters(inout)   : None
 *
 * Parameters(out)   : None
 *
 * Return value   : None
 *
 * Description   :  Initializes the GPT driver.
 *
 ******************************************************************************/
FUNC(void, GPT_CODE) Gpt_Init(const Gpt_ConfigType *ConfigPtr);

#if (GPT_DEINIT_API == STD_ON)
/******************************************************************************
 * Function Name   : Gpt_DeInit
 *
 * Service ID   : 0x02
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Not reentrant
 *
 * Parameters(in)   : None
 *
 * Parameters(inout)   : None
 *
 * Parameters(out)   : None
 *
 * Return value   : None
 *
 * Description   :   De-initializes the GPT driver.
 *
 ******************************************************************************/
FUNC(void, GPT_CODE) Gpt_DeInit(void);
#endif

#if (GPT_TIME_ELAPSED_API == STD_ON)
/******************************************************************************
 * Function Name   : Gpt_GetTimeElapsed
 *
 * Service ID   : 0x03
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Reentrant
 *
 * Parameters(in)   :   channel : Numeric identifier of the GPT channel.
 *
 * Parameters(inout)   :
 *
 * Parameters(out)   :
 *
 * Return value   :     Gpt_ValueType : Elapsed timer value (in number of ticks)
 *
 * Description   :  Returns the time already elapsed.
 *
 ******************************************************************************/
FUNC(Gpt_ValueType, GPT_CODE) Gpt_GetTimeElapsed(Gpt_ChannelType Channel);
#endif

#if (GPT_TIME_REMAINING_API == STD_ON)
/******************************************************************************
 * Function Name   : Gpt_GetTimeRemaining
 *
 * Service ID   : 0x04
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Reentrant
 *
 * Parameters(in)   :   channel : Numeric identifier of the GPT channel.
 *
 * Parameters(inout)   :  None
 *
 * Parameters(out)   : None
 *
 * Return value   :     Gpt_ValueType : Elapsed timer value (in number of ticks)
 *
 * Description   :  Returns the time already elapsed.
 *
 ******************************************************************************/
FUNC(Gpt_ValueType, GPT_CODE) Gpt_GetTimeRemaining(Gpt_ChannelType Channel);
#endif

/******************************************************************************
 * Function Name   : Gpt_StartTimer
 *
 * Service ID   : 0x05
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Reentrant
 *
 * Parameters(in)   :   channel : Numeric identifier of the GPT channel.
 *
 * Parameters(in)   :   value : Target time in number of ticks.
 *
 * Parameters(inout)   : None
 *
 * Parameters(out)   : None
 *
 * Return value   : None
 *
 * Description   :  Starts a timer channel.
 *
 ******************************************************************************/
FUNC(void, GPT_CODE) Gpt_StartTimer(Gpt_ChannelType Channel, Gpt_ValueType Value);

/******************************************************************************
 * Function Name   : Gpt_StopTimer
 *
 * Service ID   : 0x06
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Reentrant (but not for the same timer channel)
 *
 * Parameters(in)   :   channel : Numeric identifier of the GPT channel.
 *
 * Parameters(inout)   : None
 *
 * Parameters(out)   : None
 *
 * Return value   : None
 *
 * Description   :  Stops a timer channel.
 *
 ******************************************************************************/
FUNC(void, GPT_CODE) Gpt_StopTimer(Gpt_ChannelType Channel);

#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
/******************************************************************************
 * Function Name   : Gpt_SetMode
 *
 * Service ID   : 0x09
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Not reentrant
 *
 * Parameters(in)   :   Mode
 * GPT_MODE_NORMAL: Normal operation mode of the GPT driver.
 * GPT_MODE_SLEEP: Sleep mode of the GPT driver (wakeup capable).
 * See also Gpt_ModeType.
 *
 * Parameters(inout)   : None
 *
 * Parameters(out)   : None
 *
 * Return value   : None
 *
 * Description   : Sets the operation mode of the GPT.
 *
 ******************************************************************************/
FUNC(void, GPT_CODE) Gpt_SetMode(Gpt_ModeType Mode);
#endif

#if (GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
/******************************************************************************
 * Function Name   : Gpt_GetPredefTimerValue
 *
 * Service ID   : 0x0d
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Reentrant
 *
 * Parameters(in)   :   predefTimer : GPT Predef Timer
 *
 * Parameters(inout)   :
 *
 * Parameters(out)   :   timeValuePtr : Pointer to time value destination data in RAM
 *
 * Return value   :   Std_ReturnType
 * E_OK: no error has been detected
 * E_NOT_OK: aborted due to errors
 *
 * Description   : Delivers the current value of the desired GPT Predef Timer.
 *
 ******************************************************************************/
FUNC(Std_ReturnType, GPT_CODE) Gpt_GetPredefTimerValue(Gpt_PredefTimerType PredefTimer, uint32 *TimeValuePtr);
#endif

#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
/******************************************************************************
 * Function Name   : Gpt_EnableNotification
 *
 * Service ID   : 0x07
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Reentrant (but not for the same timer channel)
 *
 * Parameters(in)   :   channel : Numeric identifier of the GPT channel.
 *
 * Parameters(inout)   : None
 *
 * Parameters(out)   : None
 *
 * Return value   : None
 *
 * Description   :   Enables the interrupt notification for a channel (relevant in normal mode).
 *
 ******************************************************************************/
FUNC(void, GPT_CODE) Gpt_EnableNotification(Gpt_ChannelType Channel);

/******************************************************************************
 * Function Name   : Gpt_DisableNotification
 *
 * Service ID   : 0x08
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Reentrant (but not for the same timer channel)
 *
 * Parameters(in)   :   channel : Numeric identifier of the GPT channel.
 *
 * Parameters(inout)   : None
 *
 * Parameters(out)   : None
 *
 * Return value   : None
 *
 * Description   :   Disables the interrupt notification for a channel (relevant in normal mode).
 *
 ******************************************************************************/
FUNC(void, GPT_CODE) Gpt_DisableNotification(Gpt_ChannelType Channel);
#endif

#if ((GPT_REPORT_WAKEUP_SOURCE == STD_ON) && (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON))
/******************************************************************************
 * Function Name   : Gpt_DisableWakeup
 *
 * Service ID   : 0x0a
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Reentrant (but not for the same timer channel)
 *
 * Parameters(in)   :   channel : Numeric identifier of the GPT channel.
 *
 * Parameters(inout)   : None
 *
 * Parameters(out)   : None
 *
 * Return value   : None
 *
 * Description   :   Disables the wakeup interrupt of a channel (relevant in sleep mode).
 *
 ******************************************************************************/
FUNC(void, GPT_CODE) Gpt_DisableWakeup(Gpt_ChannelType Channel);

/******************************************************************************
 * Function Name   : Gpt_EnableWakeup
 *
 * Service ID   : 0x0b
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Reentrant (but not for the same timer channel)
 *
 * Parameters(in)   :   channel : Numeric identifier of the GPT channel.
 *
 * Parameters(inout)   : None
 *
 * Parameters(out)   : None
 *
 * Return value   : None
 *
 * Description   :   Enables the wakeup interrupt of a channel (relevant in sleep mode).
 *
 ******************************************************************************/
FUNC(void, GPT_CODE) Gpt_EnableWakeup(Gpt_ChannelType Channel);

/******************************************************************************
 * Function Name   : Gpt_CheckWakeup
 *
 * Service ID   : 0x0c
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Reentrant
 *
 * Parameters(in)   :   wakeupSource : Information on wakeup source to be checked
 *
 * Parameters(inout)   : None
 *
 * Parameters(out)   : None
 *
 * Return value   : None
 *
 * Description   :   Checks if a wakeup capable GPT channel is the source for a wakeup event and calls the ECU state
 *manager service EcuM_SetWakeupEvent in case of a valid GPT channel wakeup event.
 *
 ******************************************************************************/
FUNC(void, GPT_CODE) Gpt_CheckWakeup(EcuM_WakeupSourceType WakeupSource);
#endif

#ifdef __cplusplus
}
#endif

#endif
/* EOF */
