/**
 * @file        Dem_EventQueue.h
 * @brief       AUTOSAR Dem - Dem module internal header file.
 * @details     Dem module internal header file, containing the  API specification and
 *              other variables and functions which are about event queue processing.
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

#ifndef DEM_EVENTQUEUE_H
#define DEM_EVENTQUEUE_H

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
#define DEM_EVENTQUEUE_VENDOR_ID             					(0U)
#define DEM_EVENTQUEUE_AR_RELEASE_MAJOR_VERSION      			(4U)
#define DEM_EVENTQUEUE_AR_RELEASE_MINOR_VERSION      			(2U)
#define DEM_EVENTQUEUE_AR_RELEASE_REVISION_VERSION      		(2U)
#define DEM_EVENTQUEUE_SW_MAJOR_VERSION      					(1U)
#define DEM_EVENTQUEUE_SW_MINOR_VERSION      					(2U)
#define DEM_EVENTQUEUE_SW_PATCH_VERSION      					(0U)
/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/
/* Check if current file and Dem_Internal.h header file are of the same vendor */
#if(DEM_EVENTQUEUE_VENDOR_ID != DEM_GENERAL_VENDOR_ID )
#error "Dem_EventQueue.h and Dem_General.h have different vendor id"
#endif /* #if(DEM_EVENTQUEUE_VENDOR_ID != DEM_GENERAL_VENDOR_ID ) */

/* Check if current file and Dem_General.h header file are of the same Autosar version */
#if(\
	(DEM_EVENTQUEUE_AR_RELEASE_MAJOR_VERSION != DEM_GENERAL_AR_RELEASE_MAJOR_VERSION) || \
	(DEM_EVENTQUEUE_AR_RELEASE_MINOR_VERSION != DEM_GENERAL_AR_RELEASE_MINOR_VERSION) || \
	(DEM_EVENTQUEUE_AR_RELEASE_REVISION_VERSION != DEM_GENERAL_AR_RELEASE_REVISION_VERSION) \
   )
#error "AutoSar Version Number of Dem_EventQueue.h and Dem_General.h are different "
#endif /* #if(\
		(DEM_EVENTQUEUE_AR_RELEASE_MAJOR_VERSION != DEM_GENERAL_AR_RELEASE_MAJOR_VERSION) || \
		(DEM_EVENTQUEUE_AR_RELEASE_MINOR_VERSION != DEM_GENERAL_AR_RELEASE_MINOR_VERSION) || \
		(DEM_EVENTQUEUE_AR_RELEASE_REVISION_VERSION != DEM_GENERAL_AR_RELEASE_REVISION_VERSION)\
   	   ) */

/* Check if current file and Dem_General.h header file are of the same Software version */
#if(\
		(DEM_EVENTQUEUE_SW_MAJOR_VERSION != DEM_GENERAL_SW_MAJOR_VERSION) || \
		(DEM_EVENTQUEUE_SW_MINOR_VERSION != DEM_GENERAL_SW_MINOR_VERSION) || \
		(DEM_EVENTQUEUE_SW_PATCH_VERSION != DEM_GENERAL_SW_PATCH_VERSION) \
   )
#error "Software Version Number of Dem_EventQueue.h and Dem_General.h are different "
#endif /* #if(\
				(DEM_EVENTQUEUE_SW_MAJOR_VERSION != DEM_GENERAL_SW_MAJOR_VERSION) || \
				(DEM_EVENTQUEUE_SW_MINOR_VERSION != DEM_GENERAL_SW_MINOR_VERSION) || \
				(DEM_EVENTQUEUE_SW_PATCH_VERSION != DEM_GENERAL_SW_PATCH_VERSION) \
   	   	   	 ) */
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
typedef struct
{
#if(DEM_ENVIRONMENT_DATA_CAPTURE == DEM_CAPTURE_SYNCHRONOUS_TO_REPORTING)
	/**< @brief when configuring synchronous capture,
	 * indicator whether the event has alreadly captured data. */
	boolean captureData;
#endif/* DEM_ENVIRONMENT_DATA_CAPTURE == DEM_CAPTURE_SYNCHRONOUS_TO_REPORTING */

	/**< @brief Dem module status when report this event */
	Dem_StateType reportStatus;

    /**< @brief Event status */
    Dem_EventStatusType status;

	/**< @brief Event identifier */
    Dem_EventIdType     eventId;

#if(DEM_FREEZEFRAME_ENABLE == STD_ON)
    uint8 FFData[DEM_FREEZE_FRAME_MAX_LEN];
#endif /* #if(DEM_FREEZEFRAME_ENABLE == STD_ON) */

#if(DEM_EXTENDED_DATA_CLASS_NUM > 0)
    uint8 ExtData[DEM_EXTENDED_DATA_MAX_LEN];
#endif /* #if(DEM_EXTENDED_DATA_CLASS_NUM > 0) */

#if(DEM_PID_CLASS_NUM > 0)
    uint8 PidData[DEM_PID_CLASS_SIZE];
#endif /* #if(DEM_PID_CLASS_NUM > 0) */
} Dem_EventBufferType;
/*====================================================================================================*
 *                                    GLOBAL VARIABLE DECLARATIONS
 *====================================================================================================*/
/**
 * @brief Event queue,use for store events which is reported
 *        by Dem_ReportErrorStatus or Dem_SetEventAvailable
 */
extern VAR(Dem_EventBufferType,DEM_VAR) Dem_EventQueue[DEM_EVENT_QUEUE_SIZE];
/*====================================================================================================*
 *                                        FUNCTION PROTOTYPES
 *====================================================================================================*/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
DEM_STATIC_INLINE boolean Dem_EventQueue_ISAvailable(Dem_EventBufferType* pQueue)
{
	return (pQueue->eventId) > 0 ? (boolean)TRUE : (boolean)FALSE;
}

DEM_STATIC_INLINE Dem_EventBufferType* Dem_EventQueue_Remove(Dem_EventBufferType* pQueue,uint16* pReadIndex)
{
	Dem_Disable_TFBitChange(pQueue->eventId -1);
	Dem_Disable_TFBitReset(pQueue->eventId -1);
	Dem_Disable_PDTCBitChange(pQueue->eventId -1);
	Dem_Disable_CDTCBitChange(pQueue->eventId -1);
	Dem_Disable_FDCReachThreshold(pQueue->eventId -1);

	pQueue->eventId = 0u;
	pQueue->status = DEM_EVENT_STATUS_PASSED;
#if(DEM_ENVIRONMENT_DATA_CAPTURE == DEM_CAPTURE_SYNCHRONOUS_TO_REPORTING)
	pQueue->captureData = (boolean)FALSE;
#endif /* #if(DEM_ENVIRONMENT_DATA_CAPTURE == DEM_CAPTURE_SYNCHRONOUS_TO_REPORTING) */
	(*pReadIndex)++;

	if(*pReadIndex == DEM_EVENT_QUEUE_SIZE)
	{
		*pReadIndex = 0u;
	}

	return (&Dem_EventQueue[(*pReadIndex)]);
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#ifdef __cplusplus
}
#endif

#endif /* DEM_EVENTQUEUE_H */
/** @} */
