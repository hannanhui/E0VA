/**
 * @file        Dem_OperationCycle.h
 * @brief       AUTOSAR Dem - Dem module internal header file.
 * @details     Dem module internal header file, containing the  API specification and
 *              other variables and functions which are about operation cycle status.
 * @version     1.2.0
 *
 * @addtogroup  Dem
 * @{
 */
/*====================================================================================================*
 * AngHui AUTOSAR BSW.
 *
 * Copyright(C) 2023 GuoKeAngHui Inc.
 *
 * All rights reserved.
 *
 * This file is part of AngHui AUTOSAR BSW, contains proprietary information.
 * Passing on and copying of this document, and communication of its contents
 * is not permitted without prior written authorization.
 *====================================================================================================*/

#ifndef DEM_OPERATIONCYCLE_H
#define DEM_OPERATIONCYCLE_H

#ifdef __cplusplus
extern "C"{
#endif

/*====================================================================================================*
 *                                           INCLUDE FILES
 *====================================================================================================*/
#include "Dem_General.h"

/*====================================================================================================*
 *                                  HEADER FILE VERSION INFORMATION
 *====================================================================================================*/
#define DEM_OPERATIONCYCLE_VENDOR_ID             					(0U)
#define DEM_OPERATIONCYCLE_AR_RELEASE_MAJOR_VERSION      			(4U)
#define DEM_OPERATIONCYCLE_AR_RELEASE_MINOR_VERSION      			(2U)
#define DEM_OPERATIONCYCLE_AR_RELEASE_REVISION_VERSION      		(2U)
#define DEM_OPERATIONCYCLE_SW_MAJOR_VERSION      					(1U)
#define DEM_OPERATIONCYCLE_SW_MINOR_VERSION      					(2U)
#define DEM_OPERATIONCYCLE_SW_PATCH_VERSION      					(0U)
/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/
/* Check if current file and Dem_General.h header file are of the same vendor */
#if(DEM_OPERATIONCYCLE_VENDOR_ID != DEM_GENERAL_VENDOR_ID )
#error "Dem_OperationCycle.h and Dem_General.h have different vendor id"
#endif /* #if(DEM_OPERATIONCYCLE_VENDOR_ID != DEM_GENERAL_VENDOR_ID ) */

/* Check if current file and Dem_General.h header file are of the same Autosar version */
#if(\
	(DEM_OPERATIONCYCLE_AR_RELEASE_MAJOR_VERSION != DEM_GENERAL_AR_RELEASE_MAJOR_VERSION) || \
	(DEM_OPERATIONCYCLE_AR_RELEASE_MINOR_VERSION != DEM_GENERAL_AR_RELEASE_MINOR_VERSION) || \
	(DEM_OPERATIONCYCLE_AR_RELEASE_REVISION_VERSION != DEM_GENERAL_AR_RELEASE_REVISION_VERSION) \
   )
#error "AutoSar Version Number of Dem_OperationCycle.h and Dem_General.h are different "
#endif /* #if(\
		(DEM_OPERATIONCYCLE_AR_RELEASE_MAJOR_VERSION != DEM_GENERAL_AR_RELEASE_MAJOR_VERSION) || \
		(DEM_OPERATIONCYCLE_AR_RELEASE_MINOR_VERSION != DEM_GENERAL_AR_RELEASE_MINOR_VERSION) || \
		(DEM_OPERATIONCYCLE_AR_RELEASE_REVISION_VERSION != DEM_GENERAL_AR_RELEASE_REVISION_VERSION)\
   	   ) */

/* Check if current file and Dem_General.h header file are of the same Software version */
#if(\
		(DEM_OPERATIONCYCLE_SW_MAJOR_VERSION != DEM_GENERAL_SW_MAJOR_VERSION) || \
		(DEM_OPERATIONCYCLE_SW_MINOR_VERSION != DEM_GENERAL_SW_MINOR_VERSION) || \
		(DEM_OPERATIONCYCLE_SW_PATCH_VERSION != DEM_GENERAL_SW_PATCH_VERSION) \
   )
#error "Software Version Number of Dem_OperationCycle.h and Dem_General.h are different "
#endif /* #if(\
				(DEM_OPERATIONCYCLE_SW_MAJOR_VERSION != DEM_GENERAL_SW_MAJOR_VERSION) || \
				(DEM_OPERATIONCYCLE_SW_MINOR_VERSION != DEM_GENERAL_SW_MINOR_VERSION) || \
				(DEM_OPERATIONCYCLE_SW_PATCH_VERSION != DEM_GENERAL_SW_PATCH_VERSION) \
   	   	   	 ) */
/*====================================================================================================*
 *                                             CONSTANTS
 *====================================================================================================*/

/*====================================================================================================*
 *                                         DEFINES AND MACROS
 *====================================================================================================*/
#define DEM_OPERATIONCYCLE_CHECK		DEM_U8BIT_ISENABLE
#define DEM_OPERATIONCYCLE_ENABLE		DEM_U8BIT_ENABLE
#define DEM_OPERATIONCYCLE_DISABLE		DEM_U8BIT_DISABLE
/*====================================================================================================*
 *                                               ENUMS
 *====================================================================================================*/

/*====================================================================================================*
 *                                   STRUCTURES AND OTHER TYPEDEFS
 *====================================================================================================*/

/*====================================================================================================*
 *                                    GLOBAL VARIABLE DECLARATIONS
 *====================================================================================================*/
/**
 * @brief Record operation cycles status,whether start or not,it use bit storage
 */
extern VAR(uint8,DEM_VAR) Dem_OperationCycleStatus[DEM_OPERATION_CYCLE_NUM_BYTE];

/*====================================================================================================*
 *                                        FUNCTION PROTOTYPES
 *====================================================================================================*/
DEM_STATIC_INLINE boolean Dem_ISEnable_OperationCycle
(
	uint8 u8OpId
)
{
	return ((DEM_OPERATIONCYCLE_CHECK(Dem_OperationCycleStatus,u8OpId) != 0) ? \
			(boolean)TRUE : (boolean)FALSE);
}

DEM_STATIC_INLINE void Dem_Enable_OperationCycle
(
	uint8 u8OpId
)
{
	DEM_OPERATIONCYCLE_ENABLE(Dem_OperationCycleStatus,u8OpId);
}

DEM_STATIC_INLINE void Dem_Disable_OperationCycle
(
	uint8 u8OpId
)
{
	DEM_OPERATIONCYCLE_DISABLE(Dem_OperationCycleStatus,u8OpId);
}

#ifdef __cplusplus
}
#endif

#endif /* DEM_OPERATIONCYCLE_H */
/** @} */
