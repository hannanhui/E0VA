/**
 * @file        Dem_EventConditions.h
 * @brief       AUTOSAR Dem - Dem module internal header file.
 * @details     Dem module internal header file, containing the  API specification and
 *              other variables and functions which are about event enable conditions
 *              and storage conditions processing.
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

#ifndef DEM_EVENTCONDITIONS_H
#define DEM_EVENTCONDITIONS_H

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
#define DEM_EVENTCONDITIONS_VENDOR_ID             					(0U)
#define DEM_EVENTCONDITIONS_AR_RELEASE_MAJOR_VERSION      			(4U)
#define DEM_EVENTCONDITIONS_AR_RELEASE_MINOR_VERSION      			(2U)
#define DEM_EVENTCONDITIONS_AR_RELEASE_REVISION_VERSION      		(2U)
#define DEM_EVENTCONDITIONS_SW_MAJOR_VERSION      					(1U)
#define DEM_EVENTCONDITIONS_SW_MINOR_VERSION      					(2U)
#define DEM_EVENTCONDITIONS_SW_PATCH_VERSION      					(0U)
/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/
/* Check if current file and Dem_Internal.h header file are of the same vendor */
#if(DEM_EVENTCONDITIONS_VENDOR_ID != DEM_GENERAL_VENDOR_ID )
#error "Dem_EventConditions.h and Dem_General.h have different vendor id"
#endif /* #if(DEM_EVENTCONDITIONS_VENDOR_ID != DEM_GENERAL_VENDOR_ID ) */

/* Check if current file and Dem_General.h header file are of the same Autosar version */
#if(\
	(DEM_EVENTCONDITIONS_AR_RELEASE_MAJOR_VERSION != DEM_GENERAL_AR_RELEASE_MAJOR_VERSION) || \
	(DEM_EVENTCONDITIONS_AR_RELEASE_MINOR_VERSION != DEM_GENERAL_AR_RELEASE_MINOR_VERSION) || \
	(DEM_EVENTCONDITIONS_AR_RELEASE_REVISION_VERSION != DEM_GENERAL_AR_RELEASE_REVISION_VERSION) \
   )
#error "AutoSar Version Number of Dem_EventConditions.h and Dem_General.h are different "
#endif /* #if(\
		(DEM_EVENTCONDITIONS_AR_RELEASE_MAJOR_VERSION != DEM_GENERAL_AR_RELEASE_MAJOR_VERSION) || \
		(DEM_EVENTCONDITIONS_AR_RELEASE_MINOR_VERSION != DEM_GENERAL_AR_RELEASE_MINOR_VERSION) || \
		(DEM_EVENTCONDITIONS_AR_RELEASE_REVISION_VERSION != DEM_GENERAL_AR_RELEASE_REVISION_VERSION)\
   	   ) */

/* Check if current file and Dem_General.h header file are of the same Software version */
#if(\
		(DEM_EVENTCONDITIONS_SW_MAJOR_VERSION != DEM_GENERAL_SW_MAJOR_VERSION) || \
		(DEM_EVENTCONDITIONS_SW_MINOR_VERSION != DEM_GENERAL_SW_MINOR_VERSION) || \
		(DEM_EVENTCONDITIONS_SW_PATCH_VERSION != DEM_GENERAL_SW_PATCH_VERSION) \
   )
#error "Software Version Number of Dem_EventConditions.h and Dem_General.h are different "
#endif /* #if(\
				(DEM_EVENTCONDITIONS_SW_MAJOR_VERSION != DEM_GENERAL_SW_MAJOR_VERSION) || \
				(DEM_EVENTCONDITIONS_SW_MINOR_VERSION != DEM_GENERAL_SW_MINOR_VERSION) || \
				(DEM_EVENTCONDITIONS_SW_PATCH_VERSION != DEM_GENERAL_SW_PATCH_VERSION) \
   	   	   	 ) */
/*====================================================================================================*
 *                                             CONSTANTS
 *====================================================================================================*/
#if((DEM_ENABLE_CONDITION_NUM > 0) || (DEM_STORAGE_CONDITION_NUM > 0))
/*====================================================================================================*
 *                                         DEFINES AND MACROS
 *====================================================================================================*/
#if(DEM_ENABLE_CONDITION_NUM > 0)
#define DEM_EVENABLECONDITION_CHECK			DEM_U8BIT_ISENABLE
#define DEM_EVENABLECONDITION_ENABLE		DEM_U8BIT_ENABLE
#define DEM_EVENABLECONDITION_DISABLE		DEM_U8BIT_DISABLE
#endif /* #if(DEM_ENABLE_CONDITION_NUM > 0) */

#if(DEM_STORAGE_CONDITION_NUM > 0)
#define DEM_EVSTORAGECONDITION_CHECK		DEM_U8BIT_ISENABLE
#define DEM_EVSTORAGECONDITION_ENABLE		DEM_U8BIT_ENABLE
#define DEM_EVSTORAGECONDITION_DISABLE		DEM_U8BIT_DISABLE
#endif /* #if(DEM_STORAGE_CONDITION_NUM > 0) */
/*====================================================================================================*
 *                                               ENUMS
 *====================================================================================================*/

/*====================================================================================================*
 *                                   STRUCTURES AND OTHER TYPEDEFS
 *====================================================================================================*/

/*====================================================================================================*
 *                                    GLOBAL VARIABLE DECLARATIONS
 *====================================================================================================*/
#if(DEM_ENABLE_CONDITION_NUM > 0)
/**
 * @brief 	Enable condition status
 */
extern VAR(uint8,DEM_VAR) Dem_EnableConditionStatus[DEM_ENABLE_CONDITION_NUM_BYTE];
#endif /* #if(DEM_ENABLE_CONDITION_NUM > 0) */

#if(DEM_STORAGE_CONDITION_NUM > 0)
/**
 * @brief 	Storage condition status
 */
extern VAR(uint8,DEM_VAR) Dem_StorageConditionStatus[DEM_STORAGE_CONDITION_NUM_BYTE];
#endif /* #if(DEM_STORAGE_CONDITION_NUM > 0) */
/*====================================================================================================*
 *                                        FUNCTION PROTOTYPES
 *====================================================================================================*/
#if(DEM_ENABLE_CONDITION_NUM > 0)
DEM_STATIC_INLINE boolean Dem_ISEnable_EvEnableCondition
(
	uint8 u8ConIndex
)
{
	return ((DEM_EVENABLECONDITION_CHECK(Dem_EnableConditionStatus,u8ConIndex) != 0) ? \
			(boolean)TRUE : (boolean)FALSE);
}


DEM_STATIC_INLINE void Dem_Enable_EvEnableCondition
(
	uint8 u8ConIndex
)
{
	DEM_EVENABLECONDITION_ENABLE(Dem_EnableConditionStatus,u8ConIndex);
}

DEM_STATIC_INLINE void Dem_Disable_EvEnableCondition
(
	uint8 u8ConIndex
)
{
	DEM_EVENABLECONDITION_DISABLE(Dem_EnableConditionStatus,u8ConIndex);
}
#endif /* #if(DEM_ENABLE_CONDITION_NUM > 0) */

#if(DEM_STORAGE_CONDITION_NUM > 0)
DEM_STATIC_INLINE boolean Dem_ISEnable_EvStorageCondition
(
	uint8 u8ConIndex
)
{
	return ((DEM_EVSTORAGECONDITION_CHECK(Dem_StorageConditionStatus,u8ConIndex) != 0) ? \
			(boolean)TRUE : (boolean)FALSE);
}

DEM_STATIC_INLINE void Dem_Enable_EvStorageCondition
(
	uint8 u8ConIndex
)
{
	DEM_EVSTORAGECONDITION_ENABLE(Dem_StorageConditionStatus,u8ConIndex);
}

DEM_STATIC_INLINE void Dem_Disable_EvStorageCondition
(
	uint8 u8ConIndex
)
{
	DEM_EVSTORAGECONDITION_DISABLE(Dem_StorageConditionStatus,u8ConIndex);
}
#endif /* #if(DEM_STORAGE_CONDITION_NUM > 0) */

#endif /* #if((DEM_ENABLE_CONDITION_NUM > 0) || (DEM_STORAGE_CONDITION_NUM > 0)) */

#ifdef __cplusplus
}
#endif

#endif /* DEM_EVENTCONDITIONS_H */
/** @} */
