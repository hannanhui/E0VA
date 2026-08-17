/*******************************************************************************
**                  Shanghai ChipON Micro-Electronic Co.,Ltd **
********************************************************************************
*  @File Name       : Wdg.h
*  @Syntax          : GNU99
*  @Author          : ChipON AE/FAE Group
*  @Date            : 2025-08-29
*  @Version         : V1.0.0_SF
*  @Description     : This document describes the C language document template.
********************************************************************************
*  Copyright (C) by Shanghai ChipON Micro-Electronic Co.,Ltd
*  All rights reserved.
*
*  This software is copyright protected and proprietary to
*  Shanghai ChipON Micro-Electronic Co.,Ltd.
********************************************************************************
*                         REVISION HISTORY
********************************************************************************
*  |Date        |Version  |Author       |Description
********************************************************************************
*  |2025-08-29  |V1.0     |Wang Ning    |New creat
*******************************************************************************/
#ifndef WDG_H
#define WDG_H

#ifdef __cplusplus
extern "C" {
#endif

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
/* PRQA S 3630 EOF #KQR003630 */
/******************************************************************************
 **                      Include Files
 ******************************************************************************/
#include "Std_Types.h"
#include "Wdg_Cfg.h"
#include "WdgIf.h"
#include "EcuM.h"
/*******************************************************************************
 **                      File Version Check
 ******************************************************************************/
#define WDG_VENDOR_ID   (0xCCU)
#define WDG_MODULE_ID   (102U)
#define WDG_INSTANCE_ID ((uint8)0x00U)

/**
 * @brief Wdg module software version
 */
#define WDG_SW_MAJOR_VERSION (1U)
#define WDG_SW_MINOR_VERSION (0U)
#define WDG_SW_PATCH_VERSION (0U)
/******************************************************************************
 **                      Macro  Definitions
 ******************************************************************************/
/**
 * @brief The Wdg module shall detect the following development errors and
 * exceptions depending on its configuration (development/production mode
 * @implements #SWS_Wdg_00010
 */
#if (WDG_DEV_ERROR_DETECT == STD_ON)
/**
 * @brief API service used in wrong context (e.g.module not initialized)
 */
#define WDG_E_DRIVER_STATE ((uint8)0x10U)

/**
 * @brief API service called with wrong / inconsistent parameter(s)
 */
#define WDG_E_PARAM_MODE   ((uint8)0X11U)
#define WDG_E_PARAM_CONFIG ((uint8)0X12U)

/**
 * @brief The passed timeout value is higher than the maximum timeout value
 */
#define WDG_E_PARAM_TIMEOUT ((uint8)0X13U)

/**
 * @brief API is called with wrong pointer value (e.g.NULL pointer)
 */
#define WDG_E_PARAM_POINTER ((uint8)0X14U)

/**
 * @brief Invalid configuration set selection
 */
#define WDG_E_INIT_FALED ((uint8)0X15U)

/**
 * @brief Setting a watchdog mode failed (during initialization or mode switch)
 * @implements #SWS_Wdg_00178
 */
#define WDG_E_MODE_FAILED ((uint8)0X16U)

/**
 * @brief Initialization or watchdog mode switch failed because it would disable
 * the watchdog though this is not allowed in this configuration
 * @implements #SWS_Wdg_00179
 */
#define WDG_E_DISABLE_REJECTED ((uint8)0X17U)

/**
 * @brief API Service ID for Wdg_Init
 */
#define WDG_INIT_ID ((uint8)0X00U)

/**
 * @brief API Service ID for Wdg_SetMode
 */
#define WDG_SETMODE_ID ((uint8)0X01U)

/**
 * @brief API Service ID for SetTriggerCondition
 */
#define WDG_SETTRIGGERCONDITION_ID ((uint8)0X03U)

/**
 * @brief API Service ID for Wdg_GetVersionInfo
 */
#define WDG_GETVERSION_ID ((uint8)0X04U)

/**
 * @brief API Service ID for notify
 */
#define WDG_GPTNOTIF ((uint8)0X05U)
#endif

/******************************************************************************
 **                        Typedef  Definitions
 ******************************************************************************/
#if (WDG_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
/**
 * @brief Typedef for DEM error management implemented by Wdg drivers
 */
typedef struct
{
    /** @brief Dem event ID */
    uint32 id;
    /** @brief Dem event Status */
    uint8 state;
} Wdg_DemErrorType;
#endif

typedef uint16 Wdg_ValueType;

/**
 * @brief Watchdog setting state
 * @details Status values naming convention
 * @implements #SRS_BSW_00335
 */
typedef enum
{
    WDG_UNINIT,
    WDG_IDLE,
    WDG_BUSY
} Wdg_StatusType;

/**
 * @brief Watchdog clock source
 */
typedef enum
{
    WDG_CLK_INTLF,
    WDG_CLK_EXTLF
} Wdg_ClkSourceType;

/**
 * @brief Watchdog division factor
 */
typedef enum
{
    WDG_DIVISION_32,
    WDG_DIVISION_64,
    WDG_DIVISION_128,
    WDG_DIVISION_256,
    WDG_DIVISION_512,
    WDG_DIVISION_1024,
    WDG_DIVISION_2048,
    WDG_DIVISION_4096,
    WDG_DIVISION_8192,
    WDG_DIVISION_16384,
    WDG_DIVISION_32768,
    WDG_DIVISION_65536
} Wdg_DivisionType;

typedef struct
{
    /*Gtm timer module shortname that services H/W Wdg,only config T14 */
    uint8 GptModuleForService;
    /* Fast callback period in time ms */
    Wdg_ValueType FastServiceGptCbkTime;
    /* Slow callback period in time ms */
    Wdg_ValueType SlowServiceGptCbkTime;
    Wdg_ValueType Prescaler;
} Wdg_GptSettingsType;

/**
 * @brief Used for pointers to structures holding configuration data provided to
 * the Wdg module initialization routine for configuration of the module and
 * watchdog hardware
 * @details
 * Type: Structure
 * Range: Structure to hold the watchdog driver configuration set
 * @implements #SWS_Wdg_00171
 */
/* PRQA S 1536 ++ #KQR001536 */
/* PRQA S 3213 1 #KQR003213 */
typedef struct Wdg_ConfigType
{
    /* Gpt related settings */
    Wdg_GptSettingsType GptConf;
    /* WDG clock source */
    Wdg_ClkSourceType WdgClkSource;
    /* WDG prescale */
    Wdg_DivisionType WdgPrescale;
    /* WDG overflow value */
    Wdg_ValueType WdgOverflowValue;
    /* Reload value for fast mode,Watchdog timeout, in milliseconds */
    Wdg_ValueType FastModeWdgReloadValue;
    /* Reload value for slow mode,Watchdog timeout, in milliseconds */
    Wdg_ValueType SlowModeWdgReloadValue;
    /* Default mode for watchdog initialization */
    WdgIf_ModeType WorkMode;
} Wdg_ConfigType;
/* PRQA S 1536 -- #KQR001536 */
/******************************************************************************
 **                      Export Variables
 ******************************************************************************/

/******************************************************************************
 **                      Export Functions
 ******************************************************************************/

/******************************************************************************
 * Function Name   : Wdg_GetVersionInfo
 *
 * Service ID   : 0x04
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Reentrant
 *
 * Parameters(in)   : None
 *
 * Parameters(inout)   : None
 *
 * Parameters(out)   : versioninfo-Pointer to where to store the version
 *information of this module
 *
 * Return value   : None
 *
 * Description   : Returns the version information of the module.
 *
 ******************************************************************************/
#if (WDG_VERSION_INFO_API == STD_ON)
FUNC(void, WDG_CODE) Wdg_GetVersionInfo(Std_VersionInfoType *Versioninfo);
#endif

/******************************************************************************
 * Function Name   : Wdg_SetTriggerCondition
 *
 * Service ID   : 0x03
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Non Reentrant
 *
 * Parameters(in)   : timeout-Timeout value (milliseconds) for setting the
 *trigger
 *
 * Parameters(inout)   : None
 *
 * Parameters(out)   : None
 *
 * Return value   : None
 *
 * Description   : Sets the timeout value for the trigger counter.
 *
 ******************************************************************************/
FUNC(void, WDG_CODE) Wdg_SetTriggerCondition(uint16 Timeout);

/******************************************************************************
 * Function Name   : Wdg_SetMode
 *
 * Service ID   : 0x01
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Non Reentrant
 *
 * Parameters(in)   : Mode-One of the following statically configured modes:
 * 1. WDGIF_OFF_MODE
 * 2. WDGIF_SLOW_MODE
 * 3. WDGIF_FAST_MODE
 *
 * Parameters(inout)   : None
 *
 * Parameters(out)   : None
 *
 * Return value   : Std_ReturnType
 *
 * Description   : Initializes the module
 *
 ******************************************************************************/
FUNC(Std_ReturnType, WDG_CODE) Wdg_SetMode(WdgIf_ModeType Mode);

/******************************************************************************
 * Function Name   : Wdg_Init
 *
 * Service ID   : 0x00
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Non Reentrant
 *
 * Parameters(in)   : ConfigPtr Pointer to configuration set
 *
 * Parameters(inout)   : None
 *
 * Parameters(out)   : None
 *
 * Return value   : None
 *
 * Description   : Initializes the module
 *
 ******************************************************************************/
FUNC(void, WDG_CODE) Wdg_Init(const Wdg_ConfigType *ConfigPtr);

#ifdef __cplusplus
}
#endif

#endif /* EOF */
