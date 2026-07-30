/**
*   @file    EcuM_Cfg.h
*   @version 1.0.6
*
*   @brief   AUTOSAR EcuM - module configuration parameters file
*   @details This file contains the generated configuration parameters for the AUTOSAR EcuM.
*            This file contains sample code only. It is not part of the production code deliverables
*
*   @addtogroup ECUM_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : 
*   Dependencies         : 
*
*   Autosar Version      : 4.2.2
*   Autosar Revision     : ASR_REL_4_2_REV_0002
*   Autosar Conf.Variant :
*   SW Version           : 1.0.6
*   Build Version        : S32K1XX_MCAL_1_0_6_RTM_ASR_REL_4_2_REV_0002_07-Jun-23
*
*   (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*   Copyright 2017-2023 NXP
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be 
*   used strictly in accordance with the applicable license terms.  By expressly 
*   accepting such terms or by downloading, installing, activating and/or otherwise 
*   using the software, you are agreeing that you have read, and that you agree to 
*   comply with and are bound by, such license terms.  If you do not agree to be 
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/
#ifndef ECUM_CFG_H
#define ECUM_CFG_H

#ifdef __cplusplus
extern "C" {
#endif
/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Std_Types.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ECUM_CFG_VENDOR_ID 43
#define ECUM_CFG_MODULE_ID 10

#define ECUM_CFG_AR_RELEASE_MAJOR_VERSION 4
#define ECUM_CFG_AR_RELEASE_MINOR_VERSION 2
#define ECUM_CFG_AR_RELEASE_REVISION_VERSION 2
#define ECUM_CFG_SW_MAJOR_VERSION 1
#define ECUM_CFG_SW_MINOR_VERSION 0
#define ECUM_CFG_SW_PATCH_VERSION 6

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/


/*==================================================================================================
 *                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
/* ========= user defined wakeup sources ========= */


#if (defined EcuMConf_EcuMWakeupSource_EcuMWakeupSource_Can) /* to prevent double declaration */
#error EcuMConf_EcuMWakeupSource_EcuMWakeupSource_Can already defined
#endif
/** @brief Identifier for wakeup source EcuMWakeupSource_Can*/
#define EcuMConf_EcuMWakeupSource_EcuMWakeupSource_Can ((uint32)((uint32)1U<<5))

#if (defined EcuMConf_EcuMWakeupSource_EcuMWakeupSource_Icu) /* to prevent double declaration */
#error EcuMConf_EcuMWakeupSource_EcuMWakeupSource_Icu already defined
#endif
/** @brief Identifier for wakeup source EcuMWakeupSource_Icu*/
#define EcuMConf_EcuMWakeupSource_EcuMWakeupSource_Icu ((uint32)((uint32)1U<<6))

#if (defined EcuMConf_EcuMWakeupSource_EcuMWakeupSource_Lin) /* to prevent double declaration */
#error EcuMConf_EcuMWakeupSource_EcuMWakeupSource_Lin already defined
#endif
/** @brief Identifier for wakeup source EcuMWakeupSource_Lin*/
#define EcuMConf_EcuMWakeupSource_EcuMWakeupSource_Lin ((uint32)((uint32)1U<<7))

#if (defined EcuMConf_EcuMWakeupSource_EcuMWakeupSource_Gpt) /* to prevent double declaration */
#error EcuMConf_EcuMWakeupSource_EcuMWakeupSource_Gpt already defined
#endif
/** @brief Identifier for wakeup source EcuMWakeupSource_Gpt*/
#define EcuMConf_EcuMWakeupSource_EcuMWakeupSource_Gpt ((uint32)((uint32)1U<<8))



/* ======== Sleep modes ======== */


#if (defined EcuMConf_EcuMSleepMode_EcuMSleepMode_0) /* to prevent double declaration */
#error EcuMConf_EcuMSleepMode_EcuMSleepMode_0 already defined
#endif
/** @brief Identifier for wakeup source EcuMSleepMode_0*/
#define EcuMConf_EcuMSleepMode_EcuMSleepMode_0 0x0U


/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
typedef uint32 EcuM_WakeupSourceType; /**< @brief variable type for ECU Manager wakeup sources*/

/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* ECUM_CFG_H */

/** @} */
