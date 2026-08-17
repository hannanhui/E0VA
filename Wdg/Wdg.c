/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Wdg.c
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
 **                      MISRA-C Rules Violations
 ******************************************************************************/
/**
 * @page misra_violations MISRA-C:2004 violations
 *
 * @section
 */

/******************************************************************************
 **                      QAC Warnings
 ******************************************************************************/
/**
 * @page QAC Warnings
 *
 */
/* PRQA S 2814 EOF #KQR002814 */
/* PRQA S 2824 EOF #KQR002824 */
/* PRQA S 2824 EOF #KQR002834 */
/* PRQA S 2844 EOF #KQR002844 */
/* PRQA S 2201 EOF #KQR002201 */
/* PRQA S 2919 EOF #KQR002919 */
/* PRQA S 2834 EOF #KQR002834 */
/******************************************************************************
 **                                             MISRA-C Rules Violations
 ******************************************************************************/
/**
 * @page misra_violations MISRA-C:2004 violations
 *
 * @section
 * MISRA RULE 2.3 - A project should not contain unused type declarations
 */

/******************************************************************************
 **                                                  QAC Warnings
 ******************************************************************************/
/**
 * @page QAC Warnings
 *
 */
/* PRQA S 3205 EOF #KQR003205 */
/* PRQA S 3408 EOF #KQR003408 */
/******************************************************************************
 *                      Include Files *
 ******************************************************************************/
#include "Wdg.h"
#if (WDG_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif
#include "Wdg_Im.h"
#include "SchM_Wdg.h"
#if (WDG_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
#include "Dem.h"
#endif
/******************************************************************************
 **                      SOURCE FILE VERSION INFORMATION
 ******************************************************************************/
/**
 * @brief Parameters that shall be published within the Wdg driver header file
 * and also in the module's description file
 */
#define WDG_VENDOR_ID_C (0xCCU)

/**
 * @brief Wdg module software version,c file ver
 */
#define WDG_SW_MAJOR_VERSION_C (1U)
#define WDG_SW_MINOR_VERSION_C (0U)
#define WDG_SW_PATCH_VERSION_C (0U)
/******************************************************************************
 *                      Version Check                                      *
 ******************************************************************************/
/**
 * @brief Check if source file and Wdg header file are of the same vendor
 *
 */
#if (WDG_VENDOR_ID_C != WDG_VENDOR_ID)
#error "Wdg.c and Wdg.h have different vendor ids"
#endif
/**
 * @implement #SWS_Wdg_00086
 *
 */
#if (WDG_DEV_ERROR_DETECT == STD_ON)
/* Check if source file and Wdg header file are of the same Software version */
#if ((WDG_SW_MAJOR_VERSION_C != WDG_SW_MAJOR_VERSION) || (WDG_SW_MINOR_VERSION_C != WDG_SW_MINOR_VERSION) ||           \
     (WDG_SW_PATCH_VERSION_C != WDG_SW_PATCH_VERSION))
#error "Software Version Numbers of Wdg.c and Wdg.h are different"
#endif
#endif
/******************************************************************************
 **                      Macro Definitions
 ******************************************************************************/

/******************************************************************************
 **                      Type definitions
 ******************************************************************************/

/******************************************************************************
 **                        Export Variables
 ******************************************************************************/
#if (WDG_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
extern const Wdg_DemErrorType Wdg_E_DisableRejected;
extern const Wdg_DemErrorType Wdg_E_ModeFailed;
#endif
#if (WDG_PB_FIXED_ADDRESS == STD_ON)
extern const Wdg_ConfigType Wdg_ConfigPredefined;
#endif
/******************************************************************************
 **                        Export Functions
 ******************************************************************************/

/******************************************************************************
 **                      Constants Declarations
 ******************************************************************************/
#if (WDG_PB_FIXED_ADDRESS == STD_ON)
/* To store the wdg driver configuration pointer */
static const Wdg_ConfigType *const Wdg_ConfigPtr = &Wdg_ConfigPredefined;
#else
/* To store the wdg driver configuration pointer */
static const Wdg_ConfigType *Wdg_ConfigPtr;
#endif
/******************************************************************************
 **                      Variable Declarations
 ******************************************************************************/
#if (WDG_DEV_ERROR_DETECT == STD_ON)
/**
 * @brief Watchdog initialization state
 */
static Wdg_StatusType Wdg_DriverState = WDG_UNINIT;
#endif

/**
 * @brief Record the watchdog's working patterns
 */
static WdgIf_ModeType Wdg_DriverMode;

/**
 * @brief Wdg Counter
 */
static uint16 Wdg_GptTimeOutCounter;
/******************************************************************************
 **                      Local Functions
 ******************************************************************************/

/******************************************************************************
 **                      Function definitions
 ******************************************************************************/

/**
 * @brief To start the timer
 * @param Mode wdg work mode
 *
 * @retval void
 */
static void Wdg_StartTimer(WdgIf_ModeType Mode)
{
    Wdg_ValueType slowTicks;
    Wdg_ValueType fastTicks;

    /* get  ticks  */
    slowTicks = Wdg_ConfigPtr->GptConf.SlowServiceGptCbkTime;
    fastTicks = Wdg_ConfigPtr->GptConf.FastServiceGptCbkTime;

    /* disabled GPT*/
    Wdg_Im_StopGpt();

    switch (Mode)
    {
    case WDGIF_OFF_MODE: {
        break;
    }
    case WDGIF_SLOW_MODE: {
        /* update gpt ticks */
        Wdg_Im_StartGpt(slowTicks);
        break;
    }
    case WDGIF_FAST_MODE: {
        /* update gpt ticks */
        Wdg_Im_StartGpt(fastTicks);
        break;
    }
    default:
        KF_DEV_ASSERT(false);
        break;
    }
}

/**
 * @brief To start watch dog
 * @param Mode wdg work mode
 *
 * @retval void
 */
static void Wdg_StartWdg(WdgIf_ModeType Mode)
{
    if (Mode != WDGIF_OFF_MODE)
    {
        Wdg_Im_StartWdg();
    }
    else
    {
        Wdg_Im_StopWdg();
    }
}

/**
 * @brief Calculate Timeout counter
 * @param Mode work mode
 * @param Timeout time out value
 * @retval void
 */
static void Wdg_CalTimeOutCounter(WdgIf_ModeType Mode, uint16 Timeout)
{
    /* Time elapsed in ms relative to the last notification */
    Wdg_ValueType time2Count;

    if (Timeout == 0U)
    {
        /* Close the feed the dog */
        Wdg_GptTimeOutCounter = 0x00U;
    }
    else
    {
        switch (Mode)
        {
        case WDGIF_OFF_MODE: {
            Wdg_GptTimeOutCounter = 0x00U;
            break;
        }
        case WDGIF_SLOW_MODE: {
            /* Convert the time to feeding the dog */
            time2Count            = Wdg_ConfigPtr->GptConf.SlowServiceGptCbkTime;
            Wdg_GptTimeOutCounter = (uint16)(Timeout / time2Count);
            break;
        }
        case WDGIF_FAST_MODE: {
            /* Convert the time to feeding the dog */
            time2Count            = Wdg_ConfigPtr->GptConf.FastServiceGptCbkTime;
            Wdg_GptTimeOutCounter = (uint16)(Timeout / time2Count);
            break;
        }
        default:
            KF_DEV_ASSERT(false);
            break;
        }
    }
}

#if ((WDG_DEV_ERROR_DETECT == STD_ON) || (WDG_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF))
/**
 * @brief Check whether the configuration parameters are correct
 *
 *
 * @retval E_OK The configuration parameters are correct
 * @retval E_NOT_OK The configuration parameters are incorrect
 */
static Std_ReturnType Wdg_ValidateInitParamRange(const Wdg_ConfigType *const ConfigPtr)
{
    Std_ReturnType status = E_OK;
    WdgIf_ModeType mode;

    /* Check whether the configuration parameters are in the range */
    if (NULL_PTR == ConfigPtr)
    {
        status = E_NOT_OK;
    }
    else
    {
        if (ConfigPtr->GptConf.GptModuleForService == GPT_GPTIMER_CHAN_T14)
        {
            /* The Wdg_Init function shall check that the (hardware specific) contents of the given configuration set is
             * within the allowed boundaries */
            if ((ConfigPtr->FastModeWdgReloadValue > WDG_MAX_RELOAD) ||
                (ConfigPtr->SlowModeWdgReloadValue > WDG_MAX_RELOAD))
            {
                status = E_NOT_OK;
            }
            else
            {
                /* Do Nothing */
            }
        }
        else
        {
            status = E_NOT_OK;
        }
    }

    if (status == E_OK)
    {
        /* check config wdg work mode */
        mode = ConfigPtr->WorkMode;
        if (!((mode == WDGIF_SLOW_MODE) || (mode == WDGIF_FAST_MODE) || (mode == WDGIF_OFF_MODE)))
        {
            status = E_NOT_OK;
        }
        else
        {
            /* Do Nothing */
        }
    }
    else
    {
        /* Do Nothing */
    }

    if (status == E_NOT_OK)
    {
#if (WDG_DEV_ERROR_DETECT == STD_ON)
        /** @implements #SWS_Wdg_00090 */
        Det_ReportError(WDG_MODULE_ID, WDG_INSTANCE_ID, WDG_INIT_ID, WDG_E_PARAM_CONFIG);
#endif
    }
    else
    {
        /* Do Nothing */
    }

#if (WDG_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    if (STD_ON == Wdg_E_ModeFailed.state)
    {
        if (E_NOT_OK == status)
        {
            (void)Dem_SetEventStatus((Dem_EventIdType)Wdg_E_ModeFailed.id, DEM_EVENT_STATUS_FAILED);
        }
        else
        {
            (void)Dem_SetEventStatus((Dem_EventIdType)Wdg_E_ModeFailed.id, DEM_EVENT_STATUS_PASSED);
        }
    }
    else
    {
        /* Do Nothing */
    }
#if (WDG_DISABLE_ALLOWED == STD_OFF)
    if (STD_ON == Wdg_E_DisableRejected.state)
    {
        if (E_NOT_OK == status)
        {
            (void)Dem_SetEventStatus((Dem_EventIdType)Wdg_E_DisableRejected.id, DEM_EVENT_STATUS_FAILED);
        }
        else
        {
            (void)Dem_SetEventStatus((Dem_EventIdType)Wdg_E_DisableRejected.id, DEM_EVENT_STATUS_PASSED);
        }
    }
    else
    {
        /* Do Nothing */
    }
#endif
#endif

    return (status);
}
#endif

#if ((WDG_DEV_ERROR_DETECT == STD_ON) || (WDG_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF))
/**
 * @brief Set watchdog mode parameters and watchdog status detection
 * @param Mode work mode
 *
 * @retval E_OK Mode parameters are normal
 * @retval E_NOT_OK The mode parameter is incorrectly set
 */
static Std_ReturnType Wdg_ValidateMode(WdgIf_ModeType Mode)
{
    Std_ReturnType returnValue = E_OK;
#if (WDG_DEV_ERROR_DETECT == STD_ON)
    if (Wdg_DriverState != WDG_IDLE)
    {
        /** @implements #SWS_Wdg_00018 */
        /** @implements #SWS_Wdg_00017  */
        Det_ReportError(WDG_MODULE_ID, WDG_INSTANCE_ID, WDG_SETMODE_ID, WDG_E_DRIVER_STATE);
        returnValue = E_NOT_OK;
    }
    else
#endif
      if (!((Mode == WDGIF_SLOW_MODE) || (Mode == WDGIF_FAST_MODE) || (Mode == WDGIF_OFF_MODE)))
    {
#if (WDG_DEV_ERROR_DETECT == STD_ON)
        /** @implements #SWS_Wdg_00091 */
        Det_ReportError(WDG_MODULE_ID, WDG_INSTANCE_ID, WDG_SETMODE_ID, WDG_E_PARAM_MODE);
#endif
        returnValue = E_NOT_OK;
    }
    else
    {
        /* Do Nothing */
    }
#if (WDG_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    if (STD_ON == Wdg_E_ModeFailed.state)
    {
        if (E_NOT_OK == returnValue)
        {
            (void)Dem_SetEventStatus((Dem_EventIdType)Wdg_E_ModeFailed.id, DEM_EVENT_STATUS_FAILED);
        }
        else
        {
            (void)Dem_SetEventStatus((Dem_EventIdType)Wdg_E_ModeFailed.id, DEM_EVENT_STATUS_PASSED);
        }
    }
    else
    {
        /* Do Nothing */
    }
#endif
    return (returnValue);
}
#endif

#if (WDG_DEV_ERROR_DETECT == STD_ON)
/**
 * @brief watchdog status detection
 *
 * @retval E_OK    Watchdog idle state
 * @retval E_NOT_OK Watchdog  is not idle state
 */
static Std_ReturnType Wdg_ValidateSetTriggerCondition(void)
{
    Std_ReturnType returnValue = E_OK;

    if (Wdg_DriverState != WDG_IDLE)
    {
        /** @implements #SWS_Wdg_00018 */
        /** @implements #SWS_Wdg_00017  */
        Det_ReportError(WDG_MODULE_ID, WDG_INSTANCE_ID, WDG_SETTRIGGERCONDITION_ID, WDG_E_DRIVER_STATE);
        returnValue = E_NOT_OK;
    }
    return (returnValue);
}
#endif

/**
 * @brief After the timer is interrupted, the feeding calculation is performed
 *
 *
 * @retval void
 */
void Wdg_GptNotifyProcess(void)
{
#if (WDG_DEV_ERROR_DETECT == STD_ON)
    if (Wdg_DriverState != WDG_IDLE)
    {
        /** @implements #SWS_Wdg_00035 */
        Det_ReportError(WDG_MODULE_ID, WDG_INSTANCE_ID, WDG_GPTNOTIF, WDG_E_DRIVER_STATE);
    }
    else
#endif
    {
        /* Enter the critical section */
        SchM_Enter_Wdg_WDG_EXCLUSIVE_AREA_00();
#if (WDG_DEV_ERROR_DETECT == STD_ON)
        Wdg_DriverState = WDG_BUSY;
#endif

        if (Wdg_GptTimeOutCounter > 0x00U)
        {
            /* Decrement the Gpt Timeout Counter */
            Wdg_GptTimeOutCounter = Wdg_GptTimeOutCounter - 0x01U;
            /* feed dog */
            Wdg_Im_FeedDog();
        }
        else
        {
            /* Disable channel */
            Wdg_Im_StopGpt();
        }

        /* Exit the critical section */
        SchM_Exit_Wdg_WDG_EXCLUSIVE_AREA_00();
#if (WDG_DEV_ERROR_DETECT == STD_ON)
        Wdg_DriverState = WDG_IDLE;
#endif
    }
}

/**
 * @brief Returns the version information of the module
 * @details
 * Syntax: void Wdg_GetVersionInfo(Std_VersionInfoType* versioninfo)
 * Service ID[hex]: 0x04
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * @implements #SWS_Wdg_00109,# SWS_Wdg_00174
 *
 * @param Versioninfo Pointer to where to store the version information of
 * this module
 * @retval void
 */
#if (WDG_VERSION_INFO_API == STD_ON)
FUNC(void, WDG_CODE) Wdg_GetVersionInfo(Std_VersionInfoType *Versioninfo)
{
#if (WDG_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Versioninfo)
    {
        /** @implements #SWS_Wdg_00174 */
        Det_ReportError(WDG_MODULE_ID, WDG_INSTANCE_ID, WDG_GETVERSION_ID, WDG_E_PARAM_POINTER);
    }
    else
#endif
    {
        Versioninfo->vendorID         = WDG_VENDOR_ID;
        Versioninfo->moduleID         = WDG_MODULE_ID;
        Versioninfo->sw_major_version = WDG_SW_MAJOR_VERSION;
        Versioninfo->sw_minor_version = WDG_SW_MINOR_VERSION;
        Versioninfo->sw_patch_version = WDG_SW_PATCH_VERSION;
    }
}
#endif

/**
 * @brief Sets the Timeout value for the trigger counter.
 * @details
 * Syntax: void Wdg_SetTriggerCondition(uint16 Timeout)
 * Service ID[hex]: 0x03
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * @implements #SWS_Wdg_00155 #SWS_Wdg_00136 #SWS_Wdg_00138 #SWS_Wdg_00139 #SWS_Wdg_00140
 * #SWS_Wdg_00146
 * @param Timeout Timeout value (milliseconds) for setting the trigger
 * counter
 *
 * @retval void
 */
FUNC(void, WDG_CODE) Wdg_SetTriggerCondition(uint16 Timeout)
{
#if (WDG_DEV_ERROR_DETECT == STD_ON)
    Std_ReturnType returnValue = E_OK;

    returnValue = Wdg_ValidateSetTriggerCondition();
    if (returnValue == E_OK)
    {
        /** @implements #SWS_Wdg_00146 */
        if (Timeout > (uint16)(WDG_MAX_TIMEOUT * 1000))
        {
            Det_ReportError(WDG_MODULE_ID, WDG_INSTANCE_ID, WDG_SETTRIGGERCONDITION_ID, WDG_E_PARAM_TIMEOUT);
        }
        else if (Timeout < Wdg_ConfigPtr->GptConf.SlowServiceGptCbkTime)
        {
            Wdg_CalTimeOutCounter(Wdg_DriverMode, 0);
        }
        else
        {
#endif
            /* Enter Critical Section */
            SchM_Enter_Wdg_WDG_EXCLUSIVE_AREA_00();
            /** @implements #SWS_Wdg_00140 */
            if (Wdg_GptTimeOutCounter == 0x00U)
            {
                /* In case the counter value stored inside watchdog has the value "0",
                 * the service Wdg_SetTriggerCondition shall do nothing */
            }
            else
            {
                if (WDGIF_OFF_MODE != Wdg_DriverMode)
                {
                    /* feed dog */
                    Wdg_Im_FeedDog();
                    /* Calculate timeout counter */
                    Wdg_CalTimeOutCounter(Wdg_DriverMode, Timeout);
                    Wdg_StartWdg(Wdg_DriverMode);
                    Wdg_StartTimer(Wdg_DriverMode);
                }
                else
                {
                    /* Do Nothing */
                }
            }
            /* Exit Critical Section */
            SchM_Exit_Wdg_WDG_EXCLUSIVE_AREA_00();
#if (WDG_DEV_ERROR_DETECT == STD_ON)
        }
    }
#endif
}

/**
 * @brief Switches the watchdog into the mode Mode
 * @details
 * Syntax: Std_ReturnType Wdg_SetMode(WdgIf_ModeType Mode)
 * Service ID[hex]: 0x01
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * @implements #SWS_Wdg_00107 #SWS_Wdg_00160 #SWS_Wdg_00051 #SWS_Wdg_00145 #SWS_Wdg_00103
 * #SWS_Wdg_00016 #SWS_Wdg_00026 #SWS_Wdg_00091 #SWS_Wdg_00092 #SWS_Wdg_00017
 * #SWS_Wdg_00018
 * @param Mode One of the following statically configured modes:
 * 1. WDGIF_OFF_MODE
 * 2. WDGIF_SLOW_MODE
 * 3. WDGIF_FAST_MODE
 *
 * @retval E_OK Succeeded in changing the mode
 * @retval E_NOT_OK Failed to change the mode
 */
FUNC(Std_ReturnType, WDG_CODE) Wdg_SetMode(WdgIf_ModeType Mode)
{
    Wdg_ValueType  gptTimeOutValue;
    WdgIf_ModeType previousMode;
    Std_ReturnType returnValue = E_OK;

#if ((WDG_DEV_ERROR_DETECT == STD_ON) || (WDG_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF))
    returnValue = Wdg_ValidateMode(Mode);
    if (returnValue == E_OK)
    {
#if (WDG_DEV_ERROR_DETECT == STD_ON)
        /** @implements #SWS_Wdg_00018 */
        Wdg_DriverState = WDG_BUSY;
#endif
#endif
#if (WDG_DISABLE_ALLOWED == STD_OFF)
        /* check whether the settings for the requested mode would disable the watchdog */
        if (Mode == WDGIF_OFF_MODE)
        {
#if (WDG_DEV_ERROR_DETECT == STD_ON)
            /** @implements #SWS_Wdg_00026 */
            Det_ReportError(WDG_MODULE_ID, WDG_INSTANCE_ID, WDG_SETMODE_ID, WDG_E_DISABLE_REJECTED);
#endif
            returnValue = E_NOT_OK;
        }
        else
        {
            returnValue = E_OK;
        }
#if (WDG_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
        if (STD_ON == Wdg_E_ModeFailed.state)
        {
            if (E_NOT_OK == returnValue)
            {
                (void)Dem_SetEventStatus((Dem_EventIdType)Wdg_E_ModeFailed.id, DEM_EVENT_STATUS_FAILED);
            }
            else
            {
                (void)Dem_SetEventStatus((Dem_EventIdType)Wdg_E_ModeFailed.id, DEM_EVENT_STATUS_PASSED);
            }
        }
        else
        {
            /* Do Nothing */
        }
#endif
        if (returnValue == E_OK)
        {
#endif
            /* Enter Critical Section */
            SchM_Enter_Wdg_WDG_EXCLUSIVE_AREA_00();
            /* check whether the parameter is valid */
            if (Mode != Wdg_DriverMode)
            {
                /* save previous mode */
                previousMode = Wdg_DriverMode;
                /* update driver mode */
                Wdg_DriverMode = Mode;

                if (previousMode == WDGIF_OFF_MODE)
                {
                    if (Wdg_DriverMode == WDGIF_SLOW_MODE)
                    {
                        gptTimeOutValue = Wdg_ConfigPtr->SlowModeWdgReloadValue;
                    }
                    else
                    {
                        gptTimeOutValue = Wdg_ConfigPtr->FastModeWdgReloadValue;
                    }
                }
                else if (previousMode == WDGIF_SLOW_MODE)
                {
                    gptTimeOutValue = Wdg_GptTimeOutCounter * Wdg_ConfigPtr->GptConf.SlowServiceGptCbkTime;
                }
                else
                {
                    gptTimeOutValue = Wdg_GptTimeOutCounter * Wdg_ConfigPtr->GptConf.FastServiceGptCbkTime;
                }

                /* Calculate the Timeout counter for the remaining Timeout time */
                Wdg_CalTimeOutCounter(Wdg_DriverMode, gptTimeOutValue);
                /* Start watchdog and GPT */
                Wdg_StartWdg(Wdg_DriverMode);
                Wdg_StartTimer(Wdg_DriverMode);
            }
            else
            {
                /* do nothing */
            }
            /* Exit Critical Section */
            SchM_Exit_Wdg_WDG_EXCLUSIVE_AREA_00();
#if (WDG_DISABLE_ALLOWED == STD_OFF)
        }
#endif
#if ((WDG_DEV_ERROR_DETECT == STD_ON) || (WDG_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF))
#if (WDG_DEV_ERROR_DETECT == STD_ON)
        /** @implements #SWS_Wdg_00018 */
        Wdg_DriverState = WDG_IDLE;
#endif
    }
#endif

    return (returnValue);
}

/**
 * @brief Initializes the module
 * @details
 * Syntax: void Wdg_Init(const Wdg_ConfigType* ConfigPtr)
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * @implements #SWS_Wdg_00106 #SWS_Wdg_00001 #SWS_Wdg_00100 #SWS_Wdg_00101 #SWS_Wdg_00025
 * #SWS_Wdg_00173 #SWS_Wdg_00090 #SWS_Wdg_00019
 * @param ConfigPtr Pointer to configuration set
 *
 * @retval void
 */
FUNC(void, WDG_CODE) Wdg_Init(const Wdg_ConfigType *ConfigPtr)
{
#if ((WDG_DEV_ERROR_DETECT == STD_ON) || (WDG_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF))
    Std_ReturnType checkValue = E_OK;
#endif
#if (WDG_DEV_ERROR_DETECT == STD_ON)
#if (WDG_PB_FIXED_ADDRESS == STD_OFF)
    if (ConfigPtr == NULL_PTR)
#else
    if ((void *)ConfigPtr != NULL_PTR)
#endif
    {
        /* Report to  DET */
        Det_ReportError(WDG_MODULE_ID, WDG_INSTANCE_ID, WDG_INIT_ID, WDG_E_PARAM_CONFIG);
        checkValue = E_NOT_OK;
    }

    if (checkValue != E_NOT_OK)
#endif
    {
#if (WDG_PB_FIXED_ADDRESS == STD_OFF)
        Wdg_ConfigPtr = ConfigPtr;
#else
        (void)(ConfigPtr);
#endif

#if ((WDG_DEV_ERROR_DETECT == STD_ON) || (WDG_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF))
        checkValue = Wdg_ValidateInitParamRange(Wdg_ConfigPtr);
        if (checkValue != E_NOT_OK)
#endif
        {
            /** @implements #SWS_Wdg_00025 */
            /* if the default mode is STD_OFF and Disabling the watchdog driver at
             * runtime is not allowed */
#if (WDG_DISABLE_ALLOWED == STD_OFF)
#if (WDG_DEV_ERROR_DETECT == STD_ON)
            if (Wdg_ConfigPtr->WorkMode == WDGIF_OFF_MODE)
            {
                Det_ReportError(WDG_MODULE_ID, WDG_INSTANCE_ID, WDG_INIT_ID, WDG_E_DISABLE_REJECTED);
                checkValue = E_NOT_OK;
            }
            else
            {
                /* do nothing */
            }
#endif
#endif
#if (WDG_DEV_ERROR_DETECT == STD_ON)
            if (checkValue != E_NOT_OK)
            {
#endif
                /* Preinit IWDT */
                Wdg_Im_PreInitIwdt(Wdg_ConfigPtr);
                /* Preinit BTIMER */
                Wdg_Im_PreInitGpt(Wdg_ConfigPtr->GptConf.Prescaler);
                /* Update wdg driver mode */
                Wdg_DriverMode = Wdg_ConfigPtr->WorkMode;
                if (Wdg_DriverMode != WDGIF_OFF_MODE)
                {
                    /* Calculate GPT Timeout counter */
                    if (Wdg_DriverMode == WDGIF_SLOW_MODE)
                    {
                        Wdg_CalTimeOutCounter(WDGIF_SLOW_MODE, Wdg_ConfigPtr->SlowModeWdgReloadValue);
                    }
                    else if (Wdg_DriverMode == WDGIF_FAST_MODE)
                    {
                        Wdg_CalTimeOutCounter(WDGIF_FAST_MODE, Wdg_ConfigPtr->FastModeWdgReloadValue);
                    }
                    else
                    {
                        /* do nothing */
                    }
                }
                else
                {
                    /* do nothing */
                }
                /* Start watchdog and GPT */
                Wdg_StartWdg(Wdg_DriverMode);
                Wdg_StartTimer(Wdg_DriverMode);
#if (WDG_DEV_ERROR_DETECT == STD_ON)
                /** @implements #SWS_Wdg_00019 */
                Wdg_DriverState = WDG_IDLE;
#endif
#if (WDG_DEV_ERROR_DETECT == STD_ON)
            }
            else
            {
                /* do nothing */
            }
#endif
        }
    }
}
