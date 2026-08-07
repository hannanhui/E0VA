/** 
 *  @file     EcuM_Types.h
 *  @brief    AUTOSAR EcuM - EcuM driver header file.
 *  @details  EcuM driver header file, containing the Autosar API specification and
 * 			  other variables and functions that are exported by the EcuM  driver.
 *  @version  1.2.0
 *
 * @addtogroup  EcuM
 * @{
 */
/*====================================================================================================*
 * AngHui AUTOSAR BSW.
 *
 * Copyright(C) 2026 GuoKeAngHui Inc.
 *
 * All rights reserved.
 *
 * This file is part of AngHui AUTOSAR BSW, contains proprietary information.
 * Passing on and copying of this document, and communication of its contents
 * is not permitted without prior written authorization.
 *====================================================================================================*/
#ifndef ECUM_TYPES_H
#define ECUM_TYPES_H

#if defined(__cplusplus)
extern "C" 
{
#endif /* defined(__cplusplus) */

/*====================================================================================================*
 *                                           INCLUDE FILES
 *====================================================================================================*/
#include "Std_Types.h"/* PRQA S 0810  # violate MSIAR2004_1.1: This file needs to be included */
/*@todo*/
/*#include "Rte_EcuM_Types.h"*/

/*====================================================================================================*
 *                                  HEADER FILE VERSION INFORMATION
 *====================================================================================================*/
#define ECUM_TYPES_VENDOR_ID                       0U
#define ECUM_TYPES_AR_RELEASE_MAJOR_VERSION        4U
#define ECUM_TYPES_AR_RELEASE_MINOR_VERSION        2U
#define ECUM_TYPES_AR_RELEASE_REVISION_VERSION     2U
#define ECUM_TYPES_SW_MAJOR_VERSION                1U
#define ECUM_TYPES_SW_MINOR_VERSION                2U
#define ECUM_TYPES_SW_PATCH_VERSION                0U
/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/
#ifndef DISABLE_INTERMOD_VERSION_CHECK
/* Check if current file and Std_Types.h header file are of the same Autosar version */
#if(\
		(ECUM_TYPES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
		(ECUM_TYPES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION)  \
	)
#error "AutoSar Version Number of EcuM_Types.h and Std_Types.h are different "
#endif

/* Check if current file and Rte_EcuM_Types.h header file are of the same Autosar version */
#if(\
		(ECUM_TYPES_AR_RELEASE_MAJOR_VERSION != RTE_ECUM_TYPES_AR_RELEASE_MAJOR_VERSION) || \
		(ECUM_TYPES_AR_RELEASE_MINOR_VERSION != RTE_ECUM_TYPES_AR_RELEASE_MINOR_VERSION)  \
	)
/*#error "AutoSar Version Number of Rte_EcuM_Types.h and Rte_EcuM_Types.h are different "*/
#endif
#endif /* #ifndef DISABLE_INTERMOD_VERSION_CHECK */

/*====================================================================================================*
 *                                             CONSTANTS
 *====================================================================================================*/

/*====================================================================================================*
 *                                         DEFINES AND MACROS
 *====================================================================================================*/

/*====================================================================================================*
 *                                               ENUMS
 *====================================================================================================*/

/*====================================================================================================*
 *                                   STRUCTURES AND OTHER TYPEDEFS
 *====================================================================================================*/
typedef uint8 EcuM_StateType;
typedef uint8 EcuM_RunStatusType;
typedef uint8 EcuM_UserType;
typedef uint8 EcuM_WakeupStatusType;
typedef uint8 EcuM_BootTargetType;
typedef uint8 EcuM_ShutdownCauseType;
typedef uint32 EcuM_TimeType;
typedef uint32 EcuM_WakeupSourceType;
typedef uint8 EcuM_ResetType;
typedef uint8 EcuM_ShutdownTargetType;
typedef uint16 EcuM_ShutdownModeType;

/*====================================================================================================*
 *                                    GLOBAL VARIABLE DECLARATIONS
 *====================================================================================================*/

/*====================================================================================================*
 *                                        FUNCTION PROTOTYPES
 *====================================================================================================*/

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* !defined ECUM_TYPES_H */
/** @} */
