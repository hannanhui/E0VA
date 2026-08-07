/**
 * @file        Dem_EventStatus.h
 * @brief       AUTOSAR Dem - Dem module internal header file.
 * @details     Dem module internal header file, containing the  API specification and
 *              other variables and functions which are about event status processing.
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

#ifndef DEM_EVENTSTATUS_H
#define DEM_EVENTSTATUS_H

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
#define DEM_EVENTSTATUS_VENDOR_ID             					(0U)
#define DEM_EVENTSTATUS_AR_RELEASE_MAJOR_VERSION      			(4U)
#define DEM_EVENTSTATUS_AR_RELEASE_MINOR_VERSION      			(2U)
#define DEM_EVENTSTATUS_AR_RELEASE_REVISION_VERSION      		(2U)
#define DEM_EVENTSTATUS_SW_MAJOR_VERSION      					(1U)
#define DEM_EVENTSTATUS_SW_MINOR_VERSION      					(2U)
#define DEM_EVENTSTATUS_SW_PATCH_VERSION      					(0U)
/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/
/* Check if current file and Dem_General.h header file are of the same vendor */
#if(DEM_EVENTSTATUS_VENDOR_ID != DEM_GENERAL_VENDOR_ID )
#error "Dem_EventStatus.h and Dem_General.h have different vendor id"
#endif /* #if(DEM_EVENTSTATUS_VENDOR_ID != DEM_GENERAL_VENDOR_ID ) */

/* Check if current file and Dem_General.h header file are of the same Autosar version */
#if(\
	(DEM_EVENTSTATUS_AR_RELEASE_MAJOR_VERSION != DEM_GENERAL_AR_RELEASE_MAJOR_VERSION) || \
	(DEM_EVENTSTATUS_AR_RELEASE_MINOR_VERSION != DEM_GENERAL_AR_RELEASE_MINOR_VERSION) || \
	(DEM_EVENTSTATUS_AR_RELEASE_REVISION_VERSION != DEM_GENERAL_AR_RELEASE_REVISION_VERSION) \
   )
#error "AutoSar Version Number of Dem_EventStatus.h and Dem_General.h are different "
#endif /* #if(\
		(DEM_EVENTSTATUS_AR_RELEASE_MAJOR_VERSION != DEM_GENERAL_AR_RELEASE_MAJOR_VERSION) || \
		(DEM_EVENTSTATUS_AR_RELEASE_MINOR_VERSION != DEM_GENERAL_AR_RELEASE_MINOR_VERSION) || \
		(DEM_EVENTSTATUS_AR_RELEASE_REVISION_VERSION != DEM_GENERAL_AR_RELEASE_REVISION_VERSION)\
   	   ) */

/* Check if current file and Dem_General.h header file are of the same Software version */
#if(\
		(DEM_EVENTSTATUS_SW_MAJOR_VERSION != DEM_GENERAL_SW_MAJOR_VERSION) || \
		(DEM_EVENTSTATUS_SW_MINOR_VERSION != DEM_GENERAL_SW_MINOR_VERSION) || \
		(DEM_EVENTSTATUS_SW_PATCH_VERSION != DEM_GENERAL_SW_PATCH_VERSION) \
   )
#error "Software Version Number of Dem_EventStatus.h and Dem_General.h are different "
#endif /* #if(\
				(DEM_EVENTSTATUS_SW_MAJOR_VERSION != DEM_GENERAL_SW_MAJOR_VERSION) || \
				(DEM_EVENTSTATUS_SW_MINOR_VERSION != DEM_GENERAL_SW_MINOR_VERSION) || \
				(DEM_EVENTSTATUS_SW_PATCH_VERSION != DEM_GENERAL_SW_PATCH_VERSION) \
   	   	   	 ) */
/*====================================================================================================*
 *                                             CONSTANTS
 *====================================================================================================*/

/*====================================================================================================*
 *                                         DEFINES AND MACROS
 *====================================================================================================*/
#define DEM_DTCSETTING_ISENABLE  	  		DEM_U8STATUS_ISENABLE
#define DEM_DTCSETTING_ENABLE	  	  		DEM_U8STATUS_ENABLE
#define DEM_DTCSETTING_DISABLE	  	  		DEM_U8STATUS_DISABLE

#define DEM_FDCTRIGGER_ISENABLE  	  		DEM_U8STATUS_ISENABLE
#define DEM_FDCTRIGGER_ENABLE	  	  		DEM_U8STATUS_ENABLE
#define DEM_FDCTRIGGER_DISABLE	  	  		DEM_U8STATUS_DISABLE

#define DEM_ENABLECONDITION_ISENABLE  	  	DEM_U8STATUS_ISENABLE
#define DEM_ENABLECONDITION_ENABLE	  	  	DEM_U8STATUS_ENABLE
#define DEM_ENABLECONDITION_DISABLE	  	  	DEM_U8STATUS_DISABLE

#define DEM_STORAGECONDITION_ISENABLE  	  	DEM_U8STATUS_ISENABLE
#define DEM_STORAGECONDITION_ENABLE	  	  	DEM_U8STATUS_ENABLE
#define DEM_STORAGECONDITION_DISABLE	  	DEM_U8STATUS_DISABLE

#define DEM_EVENTAVALIABLE_ISENABLE  	 	DEM_U8STATUS_ISENABLE
#define DEM_EVENTAVALIABLE_ENABLE	  	 	DEM_U8STATUS_ENABLE
#define DEM_EVENTAVALIABLE_DISABLE	  	  	DEM_U8STATUS_DISABLE

#define DEM_TFBITCHANGE_ISENABLE  	 		DEM_U8STATUS_ISENABLE
#define DEM_TFBITCHANGE_ENABLE	  	 		DEM_U8STATUS_ENABLE
#define DEM_TFBITCHANGE_DISABLE	  	  		DEM_U8STATUS_DISABLE

#define DEM_CONSECUTIVEFAULT_ISENABLE  	 	DEM_U8STATUS_ISENABLE
#define DEM_CONSECUTIVEFAULT_ENABLE	  	 	DEM_U8STATUS_ENABLE
#define DEM_CONSECUTIVEFAULT_DISABLE	  	DEM_U8STATUS_DISABLE

#define DEM_EVENTACTIVE_ISENABLE  	 		DEM_U8STATUS_ISENABLE
#define DEM_EVENTACTIVE_ENABLE	  	 		DEM_U8STATUS_ENABLE
#define DEM_EVENTACTIVE_DISABLE	  			DEM_U8STATUS_DISABLE

#define DEM_UDSSTATUSBIT_ISENABLE  	 		DEM_U8STATUS_ISENABLE
#define DEM_UDSSTATUSBIT_ENABLE	  	 		DEM_U8STATUS_ENABLE
#define DEM_UDSSTATUSBIT_DISABLE	  		DEM_U8STATUS_DISABLE

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
 * @brief Record event uds status bits
 */
extern VAR(Dem_UdsStatusByteType,DEM_VAR)Dem_EventUDSBitStatus[DEM_EVENT_PARAMETER_NUM];

 /**
  * @brief Record event internal status
  */
extern VAR(Dem_InternalEventStatusType,DEM_VAR)Dem_InternalEventStatus[DEM_EVENT_PARAMETER_NUM];

/**
 * @brief Record event bit change status and reach FDC threshold and transfer mirror memory,used to
 *        allocate event memory entry,and used to trigger capture freeze frame or extended data.
 */
extern VAR(Dem_EventTriggerConditionType,DEM_VAR)Dem_EventTriggerCondition[DEM_EVENT_PARAMETER_NUM];

#if(DEM_COMPONENT_NUM > 0)
extern VAR(uint8,DEM_VAR) Dem_ComponentStatus[DEM_COMPONENT_NUM_BYTE];

extern VAR(uint8,DEM_VAR) Dem_ComponentAvailable[DEM_COMPONENT_NUM_BYTE];
#endif /* #if(DEM_COMPONENT_NUM > 0) */
/*====================================================================================================*
 *                                        FUNCTION PROTOTYPES
 *====================================================================================================*/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
DEM_STATIC_INLINE boolean Dem_ISEnable_EventAvaliable
(
	Dem_EventIdType u16Index
)
{
	return ((DEM_EVENTAVALIABLE_ISENABLE(Dem_InternalEventStatus[u16Index],\
			DEM_EVENT_STATUS_AVAILABLE) != 0) ? (boolean)TRUE : (boolean)FALSE);
}

DEM_STATIC_INLINE void Dem_Enable_EventAvaliable
(
	Dem_EventIdType u16Index
)
{
	DEM_EVENTAVALIABLE_ENABLE(Dem_InternalEventStatus[u16Index],DEM_EVENT_STATUS_AVAILABLE);
}

DEM_STATIC_INLINE void Dem_Disable_EventAvaliable
(
	Dem_EventIdType u16Index
)
{
	DEM_EVENTAVALIABLE_DISABLE(Dem_InternalEventStatus[u16Index],DEM_EVENT_STATUS_AVAILABLE);
}

DEM_STATIC_INLINE boolean Dem_ISEnable_DTCSetting
(
	Dem_EventIdType u16Index
)
{
	return ((DEM_EVENTAVALIABLE_ISENABLE(Dem_InternalEventStatus[u16Index],\
			DEM_EVENT_STATUS_DTC_SETTING) != 0) ? (boolean)TRUE : (boolean)FALSE);
}

DEM_STATIC_INLINE void Dem_Enable_DTCSetting
(
	Dem_EventIdType u16Index
)
{
	DEM_EVENTAVALIABLE_ENABLE(Dem_InternalEventStatus[u16Index],DEM_EVENT_STATUS_DTC_SETTING);
}

DEM_STATIC_INLINE void Dem_Disable_DTCSetting
(
	Dem_EventIdType u16Index
)
{
	DEM_EVENTAVALIABLE_DISABLE(Dem_InternalEventStatus[u16Index],DEM_EVENT_STATUS_DTC_SETTING);
}

DEM_STATIC_INLINE boolean Dem_ISEnable_FDCTrigger
(
	Dem_EventIdType u16Index
)
{
	return ((DEM_EVENTAVALIABLE_ISENABLE(Dem_InternalEventStatus[u16Index],\
			DEM_EVENT_STATUS_FDC_TRIGGERED) != 0) ? (boolean)TRUE : (boolean)FALSE);
}

DEM_STATIC_INLINE void Dem_Enable_FDCTrigger
(
	Dem_EventIdType u16Index
)
{
	DEM_EVENTAVALIABLE_ENABLE(Dem_InternalEventStatus[u16Index],DEM_EVENT_STATUS_FDC_TRIGGERED);
}

DEM_STATIC_INLINE void Dem_Disable_FDCTrigger
(
	Dem_EventIdType u16Index
)
{
	DEM_EVENTAVALIABLE_DISABLE(Dem_InternalEventStatus[u16Index],DEM_EVENT_STATUS_FDC_TRIGGERED);
}

DEM_STATIC_INLINE boolean Dem_ISEnable_EnableCondition
(
	Dem_EventIdType u16Index
)
{
	return ((DEM_EVENTAVALIABLE_ISENABLE(Dem_InternalEventStatus[u16Index],\
			DEM_EVENT_STATUS_ENABLED_CONDICTION) != 0) ? (boolean)TRUE : (boolean)FALSE);
}

DEM_STATIC_INLINE void Dem_Enable_EnableCondition
(
	Dem_EventIdType u16Index
)
{
	DEM_EVENTAVALIABLE_ENABLE(Dem_InternalEventStatus[u16Index],DEM_EVENT_STATUS_ENABLED_CONDICTION);
}

DEM_STATIC_INLINE void Dem_Disable_EnableCondition
(
	Dem_EventIdType u16Index
)
{
	DEM_EVENTAVALIABLE_DISABLE(Dem_InternalEventStatus[u16Index],DEM_EVENT_STATUS_ENABLED_CONDICTION);
}

DEM_STATIC_INLINE boolean Dem_ISEnable_StorageCondition
(
	Dem_EventIdType u16Index
)
{
	return ((DEM_EVENTAVALIABLE_ISENABLE(Dem_InternalEventStatus[u16Index],\
			DEM_EVENT_STATUS_STORAGE_CONDICTION) != 0) ? (boolean)TRUE : (boolean)FALSE);
}

DEM_STATIC_INLINE void Dem_Enable_StorageCondition
(
	Dem_EventIdType u16Index
)
{
	DEM_EVENTAVALIABLE_ENABLE(Dem_InternalEventStatus[u16Index],DEM_EVENT_STATUS_STORAGE_CONDICTION);
}

DEM_STATIC_INLINE void Dem_Disable_StorageCondition
(
	Dem_EventIdType u16Index
)
{
	DEM_EVENTAVALIABLE_DISABLE(Dem_InternalEventStatus[u16Index],DEM_EVENT_STATUS_STORAGE_CONDICTION);
}

DEM_STATIC_INLINE boolean Dem_ISEnable_TFBitChange
(
	Dem_EventIdType u16Index
)
{
	return ((DEM_EVENTAVALIABLE_ISENABLE(Dem_InternalEventStatus[u16Index],\
			DEM_EVENT_STATUS_TFBITCHANGE) != 0) ? (boolean)TRUE : (boolean)FALSE);
}

DEM_STATIC_INLINE void Dem_Enable_TFBitChange
(
	Dem_EventIdType u16Index
)
{
	DEM_EVENTAVALIABLE_ENABLE(Dem_InternalEventStatus[u16Index],DEM_EVENT_STATUS_TFBITCHANGE);
}

DEM_STATIC_INLINE void Dem_Disable_TFBitChange
(
	Dem_EventIdType u16Index
)
{
	DEM_EVENTAVALIABLE_DISABLE(Dem_InternalEventStatus[u16Index],DEM_EVENT_STATUS_TFBITCHANGE);
}

DEM_STATIC_INLINE boolean Dem_ISEnable_ConsecutiveFault
(
	Dem_EventIdType u16Index
)
{
	return ((DEM_EVENTAVALIABLE_ISENABLE(Dem_InternalEventStatus[u16Index],\
			DEM_EVENT_STATUS_CONSECUTIVE_FAULT) != 0) ? (boolean)TRUE : (boolean)FALSE);
}

DEM_STATIC_INLINE void Dem_Enable_ConsecutiveFault
(
	Dem_EventIdType u16Index
)
{
	DEM_EVENTAVALIABLE_ENABLE(Dem_InternalEventStatus[u16Index],DEM_EVENT_STATUS_CONSECUTIVE_FAULT);
}

DEM_STATIC_INLINE void Dem_Disable_ConsecutiveFault
(
	Dem_EventIdType u16Index
)
{
	DEM_EVENTAVALIABLE_DISABLE(Dem_InternalEventStatus[u16Index],DEM_EVENT_STATUS_CONSECUTIVE_FAULT);
}

DEM_STATIC_INLINE boolean Dem_ISEnable_EventActive
(
	Dem_EventIdType u16Index
)
{
	return ((DEM_EVENTAVALIABLE_ISENABLE(Dem_InternalEventStatus[u16Index],\
			DEM_EVENT_STATUS_ACTIVE) != 0) ? (boolean)TRUE : (boolean)FALSE);
}

DEM_STATIC_INLINE void Dem_Enable_EventActive
(
	Dem_EventIdType u16Index
)
{
	DEM_EVENTAVALIABLE_ENABLE(Dem_InternalEventStatus[u16Index],DEM_EVENT_STATUS_ACTIVE);
}

DEM_STATIC_INLINE void Dem_Disable_EventActive
(
	Dem_EventIdType u16Index
)
{
	DEM_EVENTAVALIABLE_DISABLE(Dem_InternalEventStatus[u16Index],DEM_EVENT_STATUS_ACTIVE);
}

DEM_STATIC_INLINE boolean Dem_ISEnable_UdsStatusBits
(
	Dem_EventIdType u16Index,
	Dem_UdsStatusByteType status
)
{
	return ((DEM_UDSSTATUSBIT_ISENABLE(Dem_EventUDSBitStatus[u16Index],status) != 0) ? \
			(boolean)TRUE : (boolean)FALSE);
}

DEM_STATIC_INLINE void Dem_Enable_UdsStatusBits
(
	Dem_EventIdType u16Index,
	Dem_UdsStatusByteType status
)
{
	DEM_UDSSTATUSBIT_ENABLE(Dem_EventUDSBitStatus[u16Index],status);
}

DEM_STATIC_INLINE void Dem_Disable_UdsStatusBits
(
	Dem_EventIdType u16Index,
	Dem_UdsStatusByteType status
)
{
	DEM_UDSSTATUSBIT_DISABLE(Dem_EventUDSBitStatus[u16Index],status);
}

DEM_STATIC_INLINE boolean Dem_IsEnable_TFBitReset
(
	Dem_EventIdType u16Index
)
{
	return ((DEM_U8STATUS_ISENABLE(Dem_EventTriggerCondition[u16Index],\
			DEM_EVENT_TF_RESET) != 0) ? (boolean)TRUE : (boolean)FALSE);
}

DEM_STATIC_INLINE void Dem_Enable_TFBitReset
(
	Dem_EventIdType u16Index
)
{
	DEM_U8STATUS_ENABLE(Dem_EventTriggerCondition[u16Index],DEM_EVENT_TF_RESET);
}

DEM_STATIC_INLINE void Dem_Disable_TFBitReset
(
	Dem_EventIdType u16Index
)
{
	DEM_U8STATUS_DISABLE(Dem_EventTriggerCondition[u16Index],DEM_EVENT_TF_RESET);
}

DEM_STATIC_INLINE boolean Dem_IsEnable_PDTCBitChange
(
	Dem_EventIdType u16Index
)
{
	return ((DEM_U8STATUS_ISENABLE(Dem_EventTriggerCondition[u16Index],\
			DEM_EVENT_PDTC_CHANGE) != 0) ? (boolean)TRUE : (boolean)FALSE);
}

DEM_STATIC_INLINE void Dem_Enable_PDTCBitChange
(
	Dem_EventIdType u16Index
)
{
	DEM_U8STATUS_ENABLE(Dem_EventTriggerCondition[u16Index],DEM_EVENT_PDTC_CHANGE);
}

DEM_STATIC_INLINE void Dem_Disable_PDTCBitChange
(
	Dem_EventIdType u16Index
)
{
	DEM_U8STATUS_DISABLE(Dem_EventTriggerCondition[u16Index],DEM_EVENT_PDTC_CHANGE);
}

DEM_STATIC_INLINE boolean Dem_IsEnable_CDTCBitChange
(
	Dem_EventIdType u16Index
)
{
	return ((DEM_U8STATUS_ISENABLE(Dem_EventTriggerCondition[u16Index],\
			DEM_EVENT_CDTC_CHANGE) != 0) ? (boolean)TRUE : (boolean)FALSE);
}

DEM_STATIC_INLINE void Dem_Enable_CDTCBitChange
(
	Dem_EventIdType u16Index
)
{
	DEM_U8STATUS_ENABLE(Dem_EventTriggerCondition[u16Index],DEM_EVENT_CDTC_CHANGE);
}

DEM_STATIC_INLINE void Dem_Disable_CDTCBitChange
(
	Dem_EventIdType u16Index
)
{
	DEM_U8STATUS_DISABLE(Dem_EventTriggerCondition[u16Index],DEM_EVENT_CDTC_CHANGE);
}

DEM_STATIC_INLINE boolean Dem_IsEnable_FDCReachThreshold
(
	Dem_EventIdType u16Index
)
{
	return ((DEM_U8STATUS_ISENABLE(Dem_EventTriggerCondition[u16Index],\
			DEM_EVENT_FDC_REACH_THRESHOLD) != 0) ? (boolean)TRUE : (boolean)FALSE);
}

DEM_STATIC_INLINE void Dem_Enable_FDCReachThreshold
(
	Dem_EventIdType u16Index
)
{
	DEM_U8STATUS_ENABLE(Dem_EventTriggerCondition[u16Index],DEM_EVENT_FDC_REACH_THRESHOLD);
}

DEM_STATIC_INLINE void Dem_Disable_FDCReachThreshold
(
	Dem_EventIdType u16Index
)
{
	DEM_U8STATUS_DISABLE(Dem_EventTriggerCondition[u16Index],DEM_EVENT_FDC_REACH_THRESHOLD);
}

DEM_STATIC_INLINE boolean Dem_IsEnable_TransferMirror
(
	Dem_EventIdType u16Index
)
{
	return ((DEM_U8STATUS_ISENABLE(Dem_EventTriggerCondition[u16Index],\
			DEM_EVENT_TRANSFER_MIRROR) != 0) ? (boolean)TRUE : (boolean)FALSE);
}

DEM_STATIC_INLINE void Dem_Enable_TransferMirror
(
	Dem_EventIdType u16Index
)
{
	DEM_U8STATUS_ENABLE(Dem_EventTriggerCondition[u16Index],DEM_EVENT_TRANSFER_MIRROR);
}

DEM_STATIC_INLINE void Dem_Disable_TransferMirror
(
	Dem_EventIdType u16Index
)
{
	DEM_U8STATUS_DISABLE(Dem_EventTriggerCondition[u16Index],DEM_EVENT_TRANSFER_MIRROR);
}

DEM_STATIC_INLINE boolean Dem_IsEnable_ObdDisableEvent
(
	Dem_EventIdType u16Index
)
{
	return ((DEM_U8STATUS_ISENABLE(Dem_EventTriggerCondition[u16Index],\
			DEM_OBD_DISABLE_EVENT) != 0) ? (boolean)TRUE : (boolean)FALSE);
}

DEM_STATIC_INLINE void Dem_Enable_ObdDisableEvent
(
	Dem_EventIdType u16Index
)
{
	DEM_U8STATUS_ENABLE(Dem_EventTriggerCondition[u16Index],DEM_OBD_DISABLE_EVENT);
}

DEM_STATIC_INLINE void Dem_Disable_ObdDisableEvent
(
	Dem_EventIdType u16Index
)
{
	DEM_U8STATUS_DISABLE(Dem_EventTriggerCondition[u16Index],DEM_OBD_DISABLE_EVENT);
}

#if(DEM_COMPONENT_NUM > 0)
DEM_STATIC_INLINE boolean Dem_IsEnable_ComponentStatus
(
	uint16 u16Index
)
{
	return ((DEM_U8BIT_ISENABLE(Dem_ComponentStatus,u16Index) != 0) ? \
			(boolean)TRUE : (boolean)FALSE);
}

DEM_STATIC_INLINE void Dem_Enable_ComponentStatus
(
	uint16 u16Index
)
{
	DEM_U8BIT_ENABLE(Dem_ComponentStatus,u16Index);
}

DEM_STATIC_INLINE void Dem_Disable_ComponentStatus
(
	uint16 u16Index
)
{
	DEM_U8BIT_DISABLE(Dem_ComponentStatus,u16Index);
}

DEM_STATIC_INLINE boolean Dem_IsEnable_ComponentAvailable
(
	uint16 u16Index
)
{
	return ((DEM_U8BIT_ISENABLE(Dem_ComponentAvailable,u16Index) != 0) ? \
			(boolean)TRUE : (boolean)FALSE);
}

DEM_STATIC_INLINE void Dem_Enable_ComponentAvailable
(
	uint16 u16Index
)
{
	DEM_U8BIT_ENABLE(Dem_ComponentAvailable,u16Index);
}

DEM_STATIC_INLINE void Dem_Disable_ComponentAvailable
(
	uint16 u16Index
)
{
	DEM_U8BIT_DISABLE(Dem_ComponentAvailable,u16Index);
}
#endif /* #if(DEM_COMPONENT_NUM > 0) */

#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#ifdef __cplusplus
}
#endif

#endif /* DEM_EVENTSTATUS_H */
/** @} */
