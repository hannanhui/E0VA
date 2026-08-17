/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : WdgIf.h
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
#ifndef WDGIF_H
#define WDGIF_H

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
/******************************************************************************
 **                        File Version Check
 ******************************************************************************/

/******************************************************************************
 **                        Macro  Definitions
 ******************************************************************************/

#define WDGIF_VENDOR_ID (0xCCU)
#define WDGIF_MODULE_ID (43U)

#define WDGIF_SW_MAJOR_VERSION (1U)
#define WDGIF_SW_MINOR_VERSION (0U)
#define WDGIF_SW_PATCH_VERSION (0U)

/**
 * @brief API service called with wrong device index parameter
 */
#define WDGIF_E_PARAM_DEVICE ((uint8)0x01U)
/**
 * @brief NULL pointer checking
 */
#define WDGIF_E_PARAM_POINTER ((uint8)0x03U)

/**
 * @brief API Service ID for WdgIf_SetMode
 */
#define WDGIF_SETMODE_ID ((uint8)0X01U)

/**
 * @brief API Service ID for WdgIf_SetTriggerCondition
 */
#define WDGIF_SETTRIGGERCONDITION_ID ((uint8)0X02U)

/**
 * @brief API Service ID for WdgIf_GetVersionInfo
 */
#define WDGIF_GETVERSIONINFO_ID ((uint8)0X03U)
/******************************************************************************
 **                        Typedef  Definitions
 ******************************************************************************/
/**
 * @brief Definations of WdgIf Mode Type
 * @implements #SWS_Wdg_00105,#SWS_WdgIf_00061
 */
typedef enum
{
    /**< @brief In this mode, the watchdog driver is disabled (switched off). */
    WDGIF_OFF_MODE,
    /**< @brief In this mode, the watchdog driver is set up for a long timeout period (slow triggering). */
    WDGIF_SLOW_MODE,
    /**< @brief In this mode, the watchdog driver is set up for a short timeout period (fast triggering). */
    WDGIF_FAST_MODE
} WdgIf_ModeType;
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
