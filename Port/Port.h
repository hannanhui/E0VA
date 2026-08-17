/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Port.h
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
 *  |Date        |Version  |Author         |Description
 ******************************************************************************
 *  |2025-08-29  |V1.0     |Wang Ning    |New creat
 *****************************************************************************/
#ifndef PORT_H
#define PORT_H
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
/* PRQA S 3205 EOF  #KQR003205 */
/* PRQA S 3630 EOF  #KQR003630 */
/******************************************************************************
 **                        Include Files
 ******************************************************************************/
/**
 * @brief Port.h shall include Port_Cfg.h for the API pre-compiler switches
 * and Std_Types.h
 * @implements #SWS_Port_00130
 */
#include "Std_Types.h"
#include "Mcal.h"
#include "Port_Cfg.h"

/**
 * @brief Conditional Inclusion of Development Error Tracer File
 */
#if (PORT_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif

/******************************************************************************
 **                        Version infomation
 ******************************************************************************/

/** @brief PORT Vendor ID */
#define PORT_VENDOR_ID (0xCCU)
/** @brief PORT Module ID */
#define PORT_MODULE_ID (124U)
/** @brief PORT MODULE INSTANCE ID */
#define PORT_INSTANCE_ID (0U)

/**
 * @brief port module software version
 */
/** @brief Port module Software major version information */
#define PORT_SW_MAJOR_VERSION (1U)
/** @brief Port module Software minor version information */
#define PORT_SW_MINOR_VERSION (0U)
/** @brief Port module Software patch version information */
#define PORT_SW_PATCH_VERSION (0U)

/******************************************************************************
 **                        Macro  Definitions
 ******************************************************************************/
#if (PORT_DEV_ERROR_DETECT == STD_ON)
/**
 * @brief The following errors and exceptions shall be detectable by the
 * PORT driver depending on its build version (development/production)
 * @implements #SWS_Port_00051
 */
/** @brief Invalid Port Pin ID requested */
#define PORT_E_PARAM_PIN ((uint8)0x0AU)
/** @brief Port Pin not configured as changeable */
#define PORT_E_DIRECTION_UNCHANGEABLE ((uint8)0x0BU)
/** @brief API Port_Init service called with wrong parameter */
/* BugFix: #259 #292 issue. Replace PORT_E_PARAM_CONFIG by PORT_E_INIT_FAILED */
#define PORT_E_INIT_FAILED ((uint8)0x0CU)
/** @brief API Port_SetPinMode service called when paramater invalid mode */
#define PORT_E_PARAM_INVALID_MODE ((uint8)0x0DU)
/** @brief API Port_SetPinMode service called when mode unchangeable */
#define PORT_E_MODE_UNCHANGEABLE ((uint8)0x0EU)
/** @brief API service called without module initialization */
#define PORT_E_UNINIT ((uint8)0x0FU)
/** @brief APIs called with a Null Pointer */
#define PORT_E_PARAM_POINTER ((uint8)0x10U)
/** @brief APIs called with a invalid range */
#define PORT_E_PARAM_INVALID_RANGE ((uint8)0x20U)

/**
 * @brief Service ID number for all PORT driver services
 */
/** @brief API Service ID for Port_Init */
#define PORT_INIT_SID ((uint8)0U)
/** @brief API Service ID for Port_SetPinDirection */
#define PORT_SETPINDIRECTION_SID ((uint8)1U)
/** @brief API Service ID for Port_RefreshPortDirection */
#define PORT_REFRESHPORTDIR_SID ((uint8)2U)
/** @brief API Service ID for Port_GetVersionInfo */
#define PORT_GETVERSIONINFO_SID ((uint8)3U)
/** @brief API Service ID for Port_SetPinMode  */
#define PORT_SETPINMODE_SID ((uint8)4)
#endif

#define PORT_CFG_MACRO(Remap, Mode, Level, PullStatus, OpenDrain, SlewRate)                                            \
    ((Remap) << 16U | (Mode) << 14U | (Level) << 13U | (PullStatus) << 11U | (OpenDrain) << 10U | (SlewRate) << 9U)
/******************************************************************************
 **                        Typedef  Definitions
 ******************************************************************************/

/**
 * @brief Data type for the symbolic name of a port pin
 * @details
 * @implements #SWS_Port_00229,#SWS_Port_00219
 */
typedef uint8 Port_PinType;

/**
 * @brief Possible directions of a port pin
 * @details Set Port Pin Direction
 * @implements #SWS_Port_00230,#SWS_Port_00220
 */
typedef enum
{
    /** @brief Set Pin as Input */
    PORT_PIN_IN,
    /** @brief Set Pin as Output */
    PORT_PIN_OUT
} Port_PinDirectionType;

/**
 * @brief Different port pin modes
 * @details As several port pin modes shall be configurable on one pin,the range shall be determined by the
 * implementation
 * @implements #SWS_Port_00212,#SWS_Port_00221
 */
typedef uint32 Port_PinModeType;

/**
 * @brief pin config
 */
typedef struct
{
    /** @brief Port Class  */
    Port_PinType PortBase;
    /** @brief Pin Index  */
    Port_PinType PinIndex;
    /** @brief pins control : refer to Type definition - one port pins control type */
    uint32 PinsControl;
#if (PORT_SET_PIN_MODE_API == STD_ON)
    /** @brief Pins mode changeable set */
    uint8 IsPinsModeChangeable;
#endif
    /** @brief Pin direction set */
    uint8 IsDirChangeable;
} Port_PinConfigType;

/**
 * @brief port config typedef
 * @details The contents of the initialization data structure are specific to the micro-controller
 * @implements #SWS_Port_00228
 */
typedef struct
{
    /** @brief Number of Configs */
    uint8 NumConfig;
    /** @brief Pin Config Pointer  */
    const Port_PinConfigType *PortPinConfigPtr;
} Port_ConfigType;

/******************************************************************************
 **                        Export Variables
 ******************************************************************************/

/******************************************************************************
 **                        Export Functions
 ******************************************************************************/
/******************************************************************************
 * Function Name   : Port_Init
 *
 * Service ID   : 0x00
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Non Reentrant
 *
 * Parameters(in)   : ConfigPtr - Pointer to configuration set
 *
 * Parameters(inout)   : None
 *
 * Parameters(out)   : None
 *
 * Return value   : None
 *
 * Description   : Initializes the Port Driver module
 *
 ******************************************************************************/
FUNC(void, PORT_CODE) Port_Init(const Port_ConfigType *ConfigPtr);

#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
/******************************************************************************
 * Function Name   : Port_SetPinDirection
 *
 * Service ID   : 0x01
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Reentrant
 *
 * Parameters(in)   : Pin - Port Pin ID number(high 4bit represent port num,low 4bit represent pin num)
 * Direction - Port Pin Direction
 *
 * Parameters(inout)   : None
 *
 * Parameters(out)   : None
 *
 * Return value   : None
 *
 * Description   : Sets the port pin direction
 *
 ******************************************************************************/
FUNC(void, PORT_CODE) Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction);
#endif

/******************************************************************************
 * Function Name   : Port_RefreshPortDirection
 *
 * Service ID   : 0x02
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Non Reentrant
 *
 * Parameters(in)   : Refreshes port direction
 *
 * Parameters(inout)   : None
 *
 * Parameters(out)   : None
 *
 * Return value   : None
 *
 * Description   : Refreshes port direction
 *
 ******************************************************************************/
FUNC(void, PORT_CODE) Port_RefreshPortDirection(void);

#if (STD_ON == PORT_VERSION_INFO_API)
/******************************************************************************
 * Function Name   : Port_GetVersionInfo
 *
 * Service ID   : 0x03
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Reentrant
 *
 * Parameters(in)   : None
 *
 * Parameters(inout)   : None
 *
 * Parameters(out)   : versioninfo,Pointer to where to store the version
 *information of this module
 *
 * Return value   : None
 *
 * Description   : Returns the version information of this module.
 *
 ******************************************************************************/
FUNC(void, PORT_CODE) Port_GetVersionInfo(Std_VersionInfoType *Versioninfo);
#endif

#if (PORT_SET_PIN_MODE_API == STD_ON)
/******************************************************************************
 * Function Name   : Port_SetPinMode
 *
 * Service ID   : 0x04
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Reentrant
 *
 * Parameters(in)   : Pin - Port Pin ID number(high 4bit represent port num,low 4bit represent pin num)
 * Mode - New Port Pin mode to be set on port pin.
 *
 * Parameters(inout)   : None
 *
 * Parameters(out)   : None
 *
 * Return value   : None
 *
 * Description   : Sets the port pin mode
 *
 ******************************************************************************/
FUNC(void, PORT_CODE) Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode);
#endif

#ifdef __cplusplus
}
#endif

#endif
/* EOF */
