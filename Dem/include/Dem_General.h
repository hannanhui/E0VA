/**
 * @file        Dem_General.h
 * @brief       AUTOSAR Dem - Dem module internal header file.
 * @details     Dem module internal header file, containing the bit expressions and
 *              develop error check expressions.
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

#ifndef DEM_GENERAL_H
#define DEM_GENERAL_H

#ifdef __cplusplus
extern "C"{
#endif

/*====================================================================================================*
 *                                           INCLUDE FILES
 *====================================================================================================*/
#include "Std_Types.h"
#include "Dem_Types.h"

#if(DEM_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif /* #if(DEM_DEV_ERROR_DETECT == STD_ON) */
/*====================================================================================================*
 *                                  HEADER FILE VERSION INFORMATION
 *====================================================================================================*/
#define DEM_GENERAL_VENDOR_ID             					(0U)
#define DEM_GENERAL_AR_RELEASE_MAJOR_VERSION      			(4U)
#define DEM_GENERAL_AR_RELEASE_MINOR_VERSION      			(2U)
#define DEM_GENERAL_AR_RELEASE_REVISION_VERSION      		(2U)
#define DEM_GENERAL_SW_MAJOR_VERSION      					(1U)
#define DEM_GENERAL_SW_MINOR_VERSION      					(2U)
#define DEM_GENERAL_SW_PATCH_VERSION      					(0U)
/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/
#ifndef DISABLE_INTERMOD_VERSION_CHECK
/* Check if current file and Det.h header file are of the same Autosar version */
#if(DEM_DEV_ERROR_DETECT == STD_ON)
#if(\
		(DEM_GENERAL_AR_RELEASE_MAJOR_VERSION != DET_AR_RELEASE_MAJOR_VERSION) || \
		(DEM_GENERAL_AR_RELEASE_MINOR_VERSION != DET_AR_RELEASE_MINOR_VERSION) \
   )
#error "AutoSar Version Number of Dem_General.h and Det.h are different "
#endif /* #if(\
				(DEM_INTERNAL_AR_RELEASE_MAJOR_VERSION != DET_AR_RELEASE_MAJOR_VERSION) || \
				(DEM_INTERNAL_AR_RELEASE_MINOR_VERSION != DET_AR_RELEASE_MINOR_VERSION) \
			 ) */
#endif /* #if(DCM_DEV_ERROR_DETECT == STD_ON) */
#endif /* #ifndef DISABLE_INTERMOD_VERSION_CHECK */
/*====================================================================================================*
 *                                             CONSTANTS
 *====================================================================================================*/

/*====================================================================================================*
 *                                         DEFINES AND MACROS
 *====================================================================================================*/
#define DEM_STATIC_INLINE static inline

#define DEM_U8STATUS_ENABLE(_var,_position)		((uint8)((_var) |= (uint8)(_position)))

#define DEM_U8STATUS_DISABLE(_var,_position)	((uint8)((_var) &= ((uint8)(~(uint8)(_position)))))

#define DEM_U8STATUS_ISENABLE(_var,_position)	((uint8)(_var) & (uint8)(_position))

#define DEM_GET_U8BITVALUE(_var,_index)	(_var[(uint8)((uint8)(_index)>>(uint8)3)])

#define DEM_GET_U8BITPOSITION(_index)	((uint8)((uint8)1<<((uint8)(_index)&(uint8)7)))

#define DEM_U8BIT_ISENABLE(_var,_index)  (DEM_GET_U8BITVALUE(_var,_index) & DEM_GET_U8BITPOSITION(_index))

#define DEM_U8BIT_DISABLE(_var,_index) (DEM_GET_U8BITVALUE(_var,_index) &= (~DEM_GET_U8BITPOSITION(_index)))

#define DEM_U8BIT_ENABLE(_var,_index) (DEM_GET_U8BITVALUE(_var,_index) |= DEM_GET_U8BITPOSITION(_index))
/*====================================================================================================*
 *                                               ENUMS
 *====================================================================================================*/

/*====================================================================================================*
 *                                   STRUCTURES AND OTHER TYPEDEFS
 *====================================================================================================*/
#if(DEM_DEV_ERROR_DETECT == STD_ON)
#define DEM_DET_ERROR_REPORT(ApiId,ErrorId)		\
	do{ \
		(void)Det_ReportError(DEM_MODULE_ID,DEM_INSTANCE_ID,ApiId,ErrorId); \
	}while(0)

#else
#define DEM_DET_ERROR_REPORT(ApiId,ErrorId)	do{ }while(0)
#endif /* #if(DEM_DEV_ERROR_DETECT == STD_ON) */

/* null pointer check */
#define DEM_NULLPOINTER_CHECK(_Pointer) ((_Pointer == NULL_PTR) ? 1u : 0u)

/* module status pre-init check */
#define DEM_PRE_INIT_CHECK(_Status)	((_Status != DEM_STATE_PRE_INIT) ? 1u : 0u)

/* module status init check */
#define DEM_INIT_CHECK(_Status)	((_Status != DEM_STATE_INIT) ? 1u : 0u)

/* check whether event id is valid */
#define DEM_EVENTID_INVALID_CHECK(_Id)	(((_Id > DEM_EVENT_PARAMETER_NUM) || (_Id == 0u)) ? 1u : 0u)

/* check whether operation cycle id is valid */
#define DEM_OPCYCID_INVALID_CHECK(_Id)	((_Id >= DEM_OPERATION_CYCLE_NUM) ? 1u : 0u)

#if(DEM_ENABLE_CONDITION_NUM > 0)
/* check whether enable condition id is valid */
#define DEM_ENBALECONDITIONID_INVALID_CHECK(_Id)	((_Id >= DEM_ENABLE_CONDITION_NUM) ? 1u : 0u)
#endif /* #if(DEM_ENABLE_CONDITION_NUM > 0) */

#if(DEM_STORAGE_CONDITION_NUM > 0)
/* check whether storage condition id is valid */
#define DEM_STORAGECONDITIONID_INVALID_CHECK(_Id)	((_Id >= DEM_STORAGE_CONDITION_NUM) ? 1u: 0u)
#endif /* #if(DEM_STORAGE_CONDITION_NUM > 0) */

#if(DEM_INDICATOR_NUM > 0)
/* check whether indicator id is valid */
#define DEM_INDICATORID_INVALID_CHECK(_Id)	((_Id > (DEM_INDICATOR_NUM - 1u)) ? 1u : 0u)
#endif /* #if(DEM_INDICATOR_NUM > 0) */

#define DEM_OPCYCSTATE_INVALID_CHECK(_State)  (((_State != DEM_CYCLE_STATE_START) \
		&& (_State != DEM_CYCLE_STATE_END)) ? 1u : 0u)

/* check whether event which report via api Dem_SetEventStatus is SWC event */
#define DEM_SWC_EVKIND_CHECK(_EvKind)	((_EvKind != DEM_EVENT_KIND_SWC) ? 1u : 0u)

/* check whether event which report via api Dem_ReportErrorStatus is BSW event */
#define DEM_BSW_EVKIND_CHECK(_EvKind)	((_EvKind != DEM_EVENT_KIND_BSW) ? 1u : 0u)

/* check whether ratio id is valid */
#define DEM_RATIOID_INVALID_CHECK(_Id)	((_Id >= DEM_RATIO_NUM) ? 1u : 0u)

/* check whether denominator condition id is valid */
#define DEM_CONDITIONID_INVALID_CHECK(_Id)	((_Id > 4u) ? 1u : 0u)

/* check PID and is valid */
#define DEM_PID_INVALID_CHECK(_Id)	((_Id >= DEM_PID_CLASS_NUM)? 1u : 0u)

/* check ComponentId and is valid */
#define DEM_COMPONENTID_INVALID_CHECK(_Id)	((_Id > DEM_COMPONENT_NUM)? 1u : 0u)

/* check whether event kind which report via Dem_SetEventStatus or Dem_ReportErrorStatus is valid */
#define DEM_EVKIND_INVALID_CHECK(_EvKind,_ApiId)  ((_ApiId == DEM_SID_SETEVENTSTATUS) ? \
		DEM_SWC_EVKIND_CHECK(_EvKind) : DEM_BSW_EVKIND_CHECK(_EvKind))

/* check whether event status which report via Dem_SetEventStatus or Dem_ReportErrorStatus is valid */
#define DEM_EVDEBOUNCE_INVALID_CHECK(_Debounce,_EvStatus) \
	((_Debounce == DEM_DEBOUNCE_MONITOR_INTERNAL) && (_EvStatus != DEM_EVENT_STATUS_FAILED) \
			&& (_EvStatus != DEM_EVENT_STATUS_PASSED) \
			&& (_EvStatus != DEM_EVENT_STATUS_FDC_THRESHOLD_REACHED))


#define DEM_DET_PARA_NULLPOINTER_REPORT(_Pointer,_ApiId,_result)	\
	do{ \
		if((DEM_NULLPOINTER_CHECK(_Pointer) != 0u) && (*(_result) != 0u)){\
			DEM_DET_ERROR_REPORT(_ApiId,DEM_E_PARAM_POINTER);\
			*(_result) = 0u;\
		}\
	}while(0)

#define DEM_DET_PREINIT_REPORT(_Status,_ApiId,_result)	\
	do{ \
		if((DEM_PRE_INIT_CHECK(_Status) != 0u) && (*(_result) != 0u)){\
			DEM_DET_ERROR_REPORT(_ApiId,DEM_E_UNINIT);\
			*(_result) = 0u;\
		}\
	}while(0)


#define DEM_DET_INIT_REPORT(_Status,_ApiId,_result)	\
	do{ \
		if((DEM_INIT_CHECK(_Status) != 0u) && ((*(_result)) != 0u)){\
			DEM_DET_ERROR_REPORT(_ApiId,DEM_E_UNINIT);\
			*(_result) = 0u;\
		}\
	}while(0)


#define DEM_DET_UNINIT_REPORT(_Status,_ApiId,_result)	\
	do{ \
		if((DEM_INIT_CHECK(_Status) != 0u) && (DEM_PRE_INIT_CHECK(_Status) != 0u) && (*(_result) != 0u)){\
			DEM_DET_ERROR_REPORT(_ApiId,DEM_E_UNINIT);\
			*(_result) = 0u;\
		}\
	}while(0)

#define DEM_DET_EVENTID_INVALID_REPORT(_Id,_ApiId,_result)	\
	do{ \
		if((DEM_EVENTID_INVALID_CHECK(_Id) != 0u) && (*(_result) != 0u)){\
			DEM_DET_ERROR_REPORT(_ApiId,DEM_E_WRONG_CONFIGURATION);\
			*(_result) = 0u;\
		}\
	}while(0)

#define DEM_DET_OPCYCID_INVALID_REPORT(_Id,_ApiId,_result)	\
	do{ \
		if((DEM_OPCYCID_INVALID_CHECK(_Id) != 0u) && (*(_result) != 0u)){\
			DEM_DET_ERROR_REPORT(_ApiId,DEM_E_WRONG_CONFIGURATION);\
			*(_result) = 0u;\
		}\
	}while(0)

#define DEM_DET_OPCYCSTATE_INVALID_REPORT(_State,_ApiId,_result)	\
	do{ \
		if((DEM_OPCYCSTATE_INVALID_CHECK(_State) != 0u) && (*(_result) != 0u)){\
			DEM_DET_ERROR_REPORT(_ApiId,DEM_E_WRONG_CONFIGURATION);\
			*(_result) = 0u;\
		}\
	}while(0)

#if(DEM_ENABLE_CONDITION_NUM > 0)
#define DEM_DET_ENBALECONDITIONID_INVALID_REPORT(_Id,_ApiId,_result)	\
	do{ \
		if((DEM_ENBALECONDITIONID_INVALID_CHECK(_Id) != 0u) && (*(_result) != 0u)){\
			DEM_DET_ERROR_REPORT(_ApiId,DEM_E_WRONG_CONFIGURATION);\
			*(_result) = 0u;\
		}\
	}while(0)
#endif /* #if(DEM_ENABLE_CONDITION_NUM > 0) */

#if(DEM_STORAGE_CONDITION_NUM > 0)
#define DEM_DET_STORAGECONDITIONID_INVALID_REPORT(_Id,_ApiId,_result)	\
	do{ \
		if((DEM_STORAGECONDITIONID_INVALID_CHECK(_Id) != 0u) && (*(_result) != 0u)){\
			DEM_DET_ERROR_REPORT(_ApiId,DEM_E_WRONG_CONFIGURATION);\
			*(_result) = 0u;\
		}\
	}while(0)
#endif /* #if(DEM_STORAGE_CONDITION_NUM > 0) */

#if(DEM_INDICATOR_NUM > 0)
#define DEM_DET_INDICATORID_INVALID_REPORT(_Id,_ApiId,_result)	\
	do{ \
		if(DEM_INDICATORID_INVALID_CHECK(_Id) && (*(_result))){\
			DEM_DET_ERROR_REPORT(_ApiId,DEM_E_WRONG_CONFIGURATION);\
			*(_result) = 0u;\
		}\
	}while(0)
#endif /* #if(DEM_INDICATOR_NUM > 0) */

#define DEM_DET_EVKIND_INVALID_REPORT(_EvKind,_ApiId,_result)	\
	do{ \
		if((DEM_EVKIND_INVALID_CHECK(_EvKind,_ApiId) != 0u) && ((*(_result)) != 0u)){\
			DEM_DET_ERROR_REPORT(_ApiId,DEM_E_WRONG_CONFIGURATION);\
			*(_result) = 0u;\
		}\
	}while(0)


#define DEM_DET_EVDEBOUNCE_INVALID_REPORT(_Debounce,_EvStatus,_ApiId,_result)	\
	do{ \
		if(DEM_EVDEBOUNCE_INVALID_CHECK(_Debounce,_EvStatus) && ((*(_result)) != 0u)){\
			DEM_DET_ERROR_REPORT(_ApiId,DEM_E_WRONG_CONFIGURATION);\
			*(_result) = 0u;\
		}\
	}while(0)

#define DEM_DET_RATIOID_INVALID_REPORT(_Id,_ApiId,_result)	\
	do{	\
		if(DEM_RATIOID_INVALID_CHECK(_Id) && (*(_result))){\
			DEM_DET_ERROR_REPORT(_ApiId,DEM_E_WRONG_CONFIGURATION);\
			*(_result) = 0u;\
		}\
	}while(0)

#define DEM_DET_CONDITIONID_INVALID_REPORT(_Id,_ApiId,_result)	\
	do{	\
		if((DEM_CONDITIONID_INVALID_CHECK(_Id) != 0u) && (*(_result) != 0u)){\
			DEM_DET_ERROR_REPORT(_ApiId,DEM_E_PARAM_DATA);\
			*(_result) = 0u;\
		}\
	}while(0)

#define DEM_DET_PID_INVALID_REPORT(_Id,_ApiId,_result)	\
	do{	\
		if((DEM_PID_INVALID_CHECK(_Id) != 0u) && (*(_result) != 0u)){\
			DEM_DET_ERROR_REPORT(_ApiId,DEM_E_WRONG_CONFIGURATION);\
			*(_result) = 0u;\
		}\
	}while(0)

#define DEM_DET_COMPONENTID_INVALID_REPORT(_Id,_ApiId,_result)	\
		do{	\
			if((DEM_COMPONENTID_INVALID_CHECK(_Id) != 0u) && (*(_result) != 0u)){\
				DEM_DET_ERROR_REPORT(_ApiId,DEM_E_WRONG_CONFIGURATION);\
				*(_result) = 0u;\
			}\
		}while(0)

/* API Dem_GetVersionInfo develop errors check */
#define DEM_DETCHECK_API_GETVERSIONINFO(_Pointer,_result) 	\
	do{ \
		DEM_DET_PARA_NULLPOINTER_REPORT(_Pointer,DEM_SID_GETVERSIONINFO,_result);\
	}while(0);

/* API Dem_Init develop errors check */
#define DEM_DETCHECK_API_INIT(_Pointer,_Status,_result) \
	do{ \
		DEM_DET_PREINIT_REPORT(_Status,DEM_SID_INIT,_result);\
		DEM_DET_PARA_NULLPOINTER_REPORT(_Pointer,DEM_SID_INIT,_result);\
	}while(0);

/* API Dem_Shutdown develop errors check */
#define DEM_DETCHECK_API_SHUTDOWN(_Status,_result) \
	do{ \
		DEM_DET_INIT_REPORT(_Status,DEM_SID_SHUTDOWN,_result);\
	}while(0);

/* API Dem_ReportErrorStatus develop errors check */
#define DEM_DETCHECK_API_REPORTERRORSTATUS(_Status,_Id,_result) \
	do{ \
		DEM_DET_UNINIT_REPORT(_Status,DEM_SID_REPORTERRORSTATUS,_result);\
		DEM_DET_EVENTID_INVALID_REPORT(_Id,DEM_SID_REPORTERRORSTATUS,_result);\
	}while(0);

/* API Dem_SetEventStatus develop errors check */
#define DEM_DETCHECK_API_SETEVENTSTATUS(_Status,_Id,_result) \
	do{ \
		DEM_DET_INIT_REPORT(_Status,DEM_SID_SETEVENTSTATUS,_result);\
		DEM_DET_EVENTID_INVALID_REPORT(_Id,DEM_SID_SETEVENTSTATUS,_result);\
	}while(0);

#define DEM_DETCHECK_REPORTEVENT_INVALID(_EvKind,_Debounce,_EvStatus,_ApiId,_result)	\
	do{ \
		DEM_DET_EVKIND_INVALID_REPORT(_EvKind,_ApiId,_result);\
		DEM_DET_EVDEBOUNCE_INVALID_REPORT(_Debounce,_EvStatus,_ApiId,_result);\
	}while(0)

#if (DEM_AVAILABILITY_SUPPORT == DEM_EVENT_AVAILABILITY)
/* API Dem_SetEventAvailable develop errors check */
#define DEM_DETCHECK_API_SETEVENTABAILABLE(_Status,_Id,_result) \
	do{ \
		DEM_DET_INIT_REPORT(_Status,DEM_SID_SETEVENTAVAILABLE,_result);\
		DEM_DET_EVENTID_INVALID_REPORT(_Id,DEM_SID_SETEVENTAVAILABLE,_result);\
	}while(0)
#endif /* #if (DEM_AVAILABILITY_SUPPORT == DEM_EVENT_AVAILABILITY) */

/* API Dem_ResetEventDebounceStatus develop errors check */
#define DEM_DETCHECK_API_RESETEVENTDEBOUNCESTATUS(_Status,_Id,_result,_flag) \
	do{ \
		if(_flag){\
			DEM_DET_ERROR_REPORT(DEM_SID_RESETEVENTDEBOUNCESTATUS,DEM_E_WRONG_CONFIGURATION);\
		}else{\
			DEM_DET_INIT_REPORT(_Status,DEM_SID_RESETEVENTDEBOUNCESTATUS,_result);\
			DEM_DET_EVENTID_INVALID_REPORT(_Id,DEM_SID_RESETEVENTDEBOUNCESTATUS,_result);\
		}\
	}while(0)

/* API Dem_ResetEventStatus develop errors check */
#define DEM_DETCHECK_API_RESETEVENTSTATUS(_Id,_result) \
	do{ \
		DEM_DET_EVENTID_INVALID_REPORT(_Id,DEM_SID_RESETEVENTSTATUS,_result);\
	}while(0)

#if(DEM_MAXNUMBER_PRESTORED_FF > 0)
/* API Dem_PrestoreFreezeFrame develop errors check */
#define DEM_DETCHECK_API_PRESTOREFREEZEFRAME(_Status,_Id,_result,_flag) \
	do{ \
		if(_flag){\
			DEM_DET_ERROR_REPORT(DEM_SID_PRESTOREFREEZEFRAME,DEM_E_WRONG_CONFIGURATION);\
		}else{\
			DEM_DET_INIT_REPORT(_Status,DEM_SID_PRESTOREFREEZEFRAME,_result);\
			DEM_DET_EVENTID_INVALID_REPORT(_Id,DEM_SID_PRESTOREFREEZEFRAME,_result);\
		}\
	}while(0)

/* API Dem_ClearPrestoredFreezeFrame develop errors check */
#define DEM_DETCHECK_API_CLEARPRESTOREDFREEZEFRAME(_Status,_Id,_result) \
	do{\
		DEM_DET_INIT_REPORT(_Status,DEM_SID_CLEARPRESTOREDFREEZEFRAME,_result);\
		DEM_DET_EVENTID_INVALID_REPORT(_Id,DEM_SID_CLEARPRESTOREDFREEZEFRAME,_result);\
	}while(0)
#endif /* #if(DEM_MAXNUMBER_PRESTORED_FF > 0) */

/* API Dem_SetOperationCycleState develop errors check */
#define DEM_DETCHECK_API_SETOPERATIONCYCLESTATE(_Status,_Id,_State,_result) \
	do{ \
		DEM_DET_INIT_REPORT(_Status,DEM_SID_SETOPERATIONCYCLESTATE,_result);\
		DEM_DET_OPCYCID_INVALID_REPORT(_Id,DEM_SID_SETOPERATIONCYCLESTATE,_result);\
		DEM_DET_OPCYCSTATE_INVALID_REPORT(_State,DEM_SID_SETOPERATIONCYCLESTATE,_result);\
	}while(0)

/* API Dem_GetOperationCycleState develop errors check */
#define DEM_DETCHECK_API_GETOPERATIONCYCLESTATE(_Status,_Id,_Ptr,_result) \
	do{ \
		DEM_DET_INIT_REPORT(_Status,DEM_SID_GETOPERATIONCYCLESTATE,_result);\
		DEM_DET_OPCYCID_INVALID_REPORT(_Id,DEM_SID_GETOPERATIONCYCLESTATE,_result);\
		DEM_DET_PARA_NULLPOINTER_REPORT(_Ptr,DEM_SID_GETOPERATIONCYCLESTATE,_result);\
	}while(0)

/* API Dem_SetAgingCycleState develop errors check */
#define DEM_DETCHECK_API_SETAGINGCYCLESTATE(_Status,_Id,_result) \
	do{ \
		DEM_DET_INIT_REPORT(_Status,DEM_SID_SETAGINGCYCLESTATE,_result);\
		DEM_DET_OPCYCID_INVALID_REPORT(_Id,DEM_SID_SETAGINGCYCLESTATE,_result);\
	}while(0)

/* API Dem_SetWIRStatus develop errors check */
#define DEM_DETCHECK_API_SETWIRSTATUS(_Status,_Id,_result) \
	do{ \
		DEM_DET_INIT_REPORT(_Status,DEM_SID_SETWIRSTATUS,_result);\
		DEM_DET_EVENTID_INVALID_REPORT(_Id,DEM_SID_SETWIRSTATUS,_result);\
	}while(0)

/* API Dem_GetComponentFailed develop errors check */
#define DEM_DETCHECK_API_GETCOMPONENTFAILED(_Status,_Id,_Ptr,_result) \
	do{ \
		DEM_DET_INIT_REPORT(_Status,DEM_SID_GETCOMPONENTFAILED,_result);\
		DEM_DET_COMPONENTID_INVALID_REPORT(_Id,DEM_SID_GETCOMPONENTFAILED,_result);\
		DEM_DET_PARA_NULLPOINTER_REPORT(_Ptr,DEM_SID_GETCOMPONENTFAILED,_result);\
	}while(0)

/* API Dem_GetEventStatus develop errors check */
#define DEM_DETCHECK_API_GETEVENTSTATUS(_Status,_Id,_Ptr,_result) \
	do{ \
		DEM_DET_INIT_REPORT(_Status,DEM_SID_GETEVENTSTATUS,_result);\
		DEM_DET_EVENTID_INVALID_REPORT(_Id,DEM_SID_GETEVENTSTATUS,_result);\
		DEM_DET_PARA_NULLPOINTER_REPORT(_Ptr,DEM_SID_GETEVENTSTATUS,_result);\
	}while(0)

/* API Dem_GetEventFailed develop errors check */
#define DEM_DETCHECK_API_GETEVENTFAILED(_Status,_Id,_Ptr,_result) \
	do{ \
		DEM_DET_INIT_REPORT(_Status,DEM_SID_GETEVENTFAILED,_result);\
		DEM_DET_EVENTID_INVALID_REPORT(_Id,DEM_SID_GETEVENTFAILED,_result);\
		DEM_DET_PARA_NULLPOINTER_REPORT(_Ptr,DEM_SID_GETEVENTFAILED,_result);\
	}while(0)

/* API Dem_GetEventTested develop errors check */
#define DEM_DETCHECK_API_GETEVENTTESTED(_Status,_Id,_Ptr,_result) \
	do{ \
		DEM_DET_INIT_REPORT(_Status,DEM_SID_GETEVENTTESTED,_result);\
		DEM_DET_EVENTID_INVALID_REPORT(_Id,DEM_SID_GETEVENTTESTED,_result);\
		DEM_DET_PARA_NULLPOINTER_REPORT(_Ptr,DEM_SID_GETEVENTTESTED,_result);\
	}while(0)

/* API Dem_GetDebouncingOfEvent develop errors check */
#define DEM_DETCHECK_API_GETDEBOUNCINGOFEVENT(_Status,_Id,_Ptr,_result) \
	do{ \
		DEM_DET_INIT_REPORT(_Status,DEM_SID_GETDEBOUNCINGOFEVENT,_result);\
		DEM_DET_EVENTID_INVALID_REPORT(_Id,DEM_SID_GETDEBOUNCINGOFEVENT,_result);\
		DEM_DET_PARA_NULLPOINTER_REPORT(_Ptr,DEM_SID_GETDEBOUNCINGOFEVENT,_result);\
	}while(0)

/* API Dem_GetDTCOfEvent develop errors check */
#define DEM_DETCHECK_API_GETDTCOFEVENT(_Status,_Id,_Ptr,_result) \
	do{ \
		DEM_DET_INIT_REPORT(_Status,DEM_SID_GETDTCOFEVENT,_result);\
		DEM_DET_EVENTID_INVALID_REPORT(_Id,DEM_SID_GETDTCOFEVENT,_result);\
		DEM_DET_PARA_NULLPOINTER_REPORT(_Ptr,DEM_SID_GETDTCOFEVENT,_result);\
	}while(0)

#if(DEM_ENABLE_CONDITION_NUM > 0)
/* API Dem_SetEnableCondition develop errors check */
#define DEM_DETCHECK_API_SETENABLECONDITION(_Status,_Id,_result) \
	do{ \
		DEM_DET_INIT_REPORT(_Status,DEM_SID_SETENABLECONDITION,_result);\
		DEM_DET_ENBALECONDITIONID_INVALID_REPORT(_Id,DEM_SID_SETENABLECONDITION,_result);\
	}while(0)
#endif /* #if(DEM_ENABLE_CONDITION_NUM > 0) */

#if(DEM_STORAGE_CONDITION_NUM > 0)
/* API Dem_SetStorageCondition develop errors check */
#define DEM_DETCHECK_API_SETSTORAGECONDITION(_Status,_Id,_result) \
	do{ \
		DEM_DET_INIT_REPORT(_Status,DEM_SID_SETSTORAGECONDITION,_result);\
		DEM_DET_STORAGECONDITIONID_INVALID_REPORT(_Id,DEM_SID_SETSTORAGECONDITION,_result);\
	}while(0)
#endif /* #if(DEM_STORAGE_CONDITION_NUM > 0) */

/* API Dem_GetFaultDetectionCounter develop errors check */
#define DEM_DETCHECK_API_GETFAULTDETECTIONCOUNTER(_Status,_Id,_Ptr,_result) \
	do{ \
		DEM_DET_INIT_REPORT(_Status,DEM_SID_GETFAULTDETECTIONCOUNTER,_result);\
		DEM_DET_EVENTID_INVALID_REPORT(_Id,DEM_SID_GETFAULTDETECTIONCOUNTER,_result);\
		DEM_DET_PARA_NULLPOINTER_REPORT(_Ptr,DEM_SID_GETFAULTDETECTIONCOUNTER,_result);\
	}while(0)

#if(DEM_INDICATOR_NUM > 0)
/* API Dem_GetIndicatorStatus develop errors check */
#define DEM_DETCHECK_API_GETINDICATORSTATUS(_Status,_Id,_Ptr,_result) \
	do{ \
		DEM_DET_INIT_REPORT(_Status,DEM_SID_GETINDICATORSTATUS,_result);\
		DEM_DET_INDICATORID_INVALID_REPORT(_Id,DEM_SID_GETINDICATORSTATUS,_result);\
		DEM_DET_PARA_NULLPOINTER_REPORT(_Ptr,DEM_SID_GETINDICATORSTATUS,_result);\
	}while(0)
#endif /* #if(DEM_INDICATOR_NUM > 0) */

/*#if(DEM_FREEZEFRAME_ENABLE == STD_ON)*/
/* API Dem_GetEventFreezeFrameDataEx develop errors check */
#define DEM_DETCHECK_API_GETEVENTFREEZEFRAMEDATAEX(_Status,_Id,_Ptr1,_Ptr2,_result) \
	do{ \
		DEM_DET_INIT_REPORT(_Status,DEM_SID_GETEVENTFREEZEFRAMEDATAEX,_result);\
		DEM_DET_EVENTID_INVALID_REPORT(_Id,DEM_SID_GETEVENTFREEZEFRAMEDATAEX,_result);\
		DEM_DET_PARA_NULLPOINTER_REPORT(_Ptr1,DEM_SID_GETEVENTFREEZEFRAMEDATAEX,_result);\
		DEM_DET_PARA_NULLPOINTER_REPORT(_Ptr2,DEM_SID_GETEVENTFREEZEFRAMEDATAEX,_result);\
	}while(0)
/* #endif #if(DEM_FREEZEFRAME_ENABLE == STD_ON) */

// #if(DEM_EXTENDED_DATA_CLASS_NUM > 0)
/* API Dem_GetEventExtendedDataRecordEx develop errors check */
#define DEM_DETCHECK_API_GETEVENTEXTENDEDDATARECORDEX(_Status,_Id,_Ptr,_result) \
	do{ \
		DEM_DET_INIT_REPORT(_Status,DEM_SID_GETEVENTEXTENDEDDATARECORDEX,_result);\
		DEM_DET_EVENTID_INVALID_REPORT(_Id,DEM_SID_GETEVENTEXTENDEDDATARECORDEX,_result);\
		DEM_DET_PARA_NULLPOINTER_REPORT(_Ptr,DEM_SID_GETEVENTEXTENDEDDATARECORDEX,_result);\
	}while(0)
// #endif /* #if(DEM_EXTENDED_DATA_CLASS_NUM > 0) */

/* API Dem_GetEventMemoryOverflow develop errors check */
#define DEM_DETCHECK_API_GETEVENTMEMORYOVERFLOW(_Status,_Ptr,_result) \
	do{\
		DEM_DET_INIT_REPORT(_Status,DEM_SID_GETEVENTMEMORYOVERFLOW,_result);\
		DEM_DET_PARA_NULLPOINTER_REPORT(_Ptr,DEM_SID_GETEVENTMEMORYOVERFLOW,_result);\
	}while(0)

/* API Dem_GetNumberOfEventMemoryEntries develop errors check */
#define DEM_DETCHECK_API_GETNUMBEROFEVENTMEMORYENTRIES(_Status,_Ptr,_result,_flag) \
	do{ \
		if(_flag){\
			DEM_DET_ERROR_REPORT(DEM_SID_GETNUMBEROFEVENTMEMORYENTRIES,DEM_E_WRONG_CONFIGURATION);\
		}else{\
			DEM_DET_INIT_REPORT(_Status,DEM_SID_GETNUMBEROFEVENTMEMORYENTRIES,_result);\
			DEM_DET_PARA_NULLPOINTER_REPORT(_Ptr,DEM_SID_GETNUMBEROFEVENTMEMORYENTRIES,_result);\
		}\
	}while(0)

/* API Dem_SetComponentAvailable develop errors check */
#define DEM_DETCHECK_API_SETCOMPONENTAVAILABLE(_Status,_Id,_result) \
	do{ \
		DEM_DET_INIT_REPORT(_Status,DEM_SID_SETCOMPONENTAVAILABLE,_result);\
		DEM_DET_COMPONENTID_INVALID_REPORT(_Id,DEM_SID_SETCOMPONENTAVAILABLE,_result);\
	}while(0)

#if(DEM_SUPPRESSION_SUPPORT == DEM_DTC_SUPPRESSION)
/* API Dem_SetDTCSuppression develop errors check */
#define DEM_DETCHECK_API_SETDTCSUPPRESSION(_Status,_result) \
	do{ \
		DEM_DET_INIT_REPORT(_Status,DEM_SID_SETDTCSUPPRESSION,_result);\
	}while(0)
#endif /* #if(DEM_SUPPRESSION_SUPPORT == DEM_DTC_SUPPRESSION) */

/* API Dem_SetEventDisabled develop errors check */
#define DEM_DETCHECK_API_SETEVENTDISABLED(_Status,_Id,_result) \
	do{ \
		DEM_DET_INIT_REPORT(_Status,DEM_SID_SETEVENTDISABLED,_result);\
		DEM_DET_EVENTID_INVALID_REPORT(_Id,DEM_SID_SETEVENTDISABLED,_result);\
	}while(0)

/* API Dem_RepIUMPRFaultDetect develop errors check */
#define DEM_DETCHECK_API_REPIUMPRFAULTDETECT(_Status,_Id,_result) \
	do{ \
		DEM_DET_INIT_REPORT(_Status,DEM_SID_REPIUMPRFAULTDETECT,_result);\
		DEM_DET_RATIOID_INVALID_REPORT(_Id,DEM_SID_REPIUMPRFAULTDETECT,_result);\
	}while(0)

/* API Dem_SetIUMPRDenCondition develop errors check */
#define DEM_DETCHECK_API_SETIUMPRDENCONDITION(_Status,_Id,_result) \
	do{ \
		DEM_DET_INIT_REPORT(_Status,DEM_SID_SETIUMPRDENCONDITION,_result);\
		DEM_DET_CONDITIONID_INVALID_REPORT(_Id,DEM_SID_SETIUMPRDENCONDITION,_result);\
	}while(0)

/* API Dem_GetIUMPRDenCondition develop errors check */
#define DEM_DETCHECK_API_GETIUMPRDENCONDITION(_Status,_Id,_result) \
	do{ \
		DEM_DET_INIT_REPORT(_Status,DEM_SID_GETIUMPRDENCONDITION,_result);\
		DEM_DET_CONDITIONID_INVALID_REPORT(_Id,DEM_SID_GETIUMPRDENCONDITION,_result);\
	}while(0)

/* API Dem_RepIUMPRDenLock develop errors check */
#define DEM_DETCHECK_API_REPIUMPRDENLOCK(_Status,_Id,_result) \
	do{ \
		DEM_DET_INIT_REPORT(_Status,DEM_SID_REPIUMPRDENLOCK,_result);\
		DEM_DET_RATIOID_INVALID_REPORT(_Id,DEM_SID_REPIUMPRDENLOCK,_result);\
	}while(0)

/* API Dem_RepIUMPRDenRelease develop errors check */
#define DEM_DETCHECK_API_REPIUMPRDENRELEASE(_Status,_Id,_result) \
	do{ \
		DEM_DET_INIT_REPORT(_Status,DEM_SID_REPIUMPRDENRELEASE,_result);\
		DEM_DET_RATIOID_INVALID_REPORT(_Id,DEM_SID_REPIUMPRDENRELEASE,_result);\
	}while(0)

/* API Dem_SetPtoStatus develop errors check */
#define DEM_DETCHECK_API_SETPTOSTATUS(_Status,_result) \
	do{ \
		DEM_DET_INIT_REPORT(_Status,DEM_SID_SETPTOSTATUS,_result);\
	}while(0)

/* API Dem_ReadDataOfPID01 develop errors check */
#define DEM_DETCHECK_API_READDATAOFPID01(_Status,_Ptr,_result) \
	do{ \
		DEM_DET_INIT_REPORT(_Status,DEM_SID_READDATAOFPID01,_result);\
		DEM_DET_PARA_NULLPOINTER_REPORT(_Ptr,DEM_SID_READDATAOFPID01,_result);\
	}while(0)


/* API Dem_GetDataOfPID21 develop errors check */
#define DEM_DETCHECK_API_GETDATAOFPID21(_Status,_Ptr,_result) \
	do{ \
		DEM_DET_INIT_REPORT(_Status,DEM_SID_GETDATAOFPID21,_result);\
		DEM_DET_PARA_NULLPOINTER_REPORT(_Ptr,DEM_SID_GETDATAOFPID21,_result);\
	}while(0)

/* API Dem_SetDataOfPID21 develop errors check */
#define DEM_DETCHECK_API_SETDATAOFPID21(_Status,_Ptr,_result) \
	do{ \
		DEM_DET_INIT_REPORT(_Status,DEM_SID_SETDATAOFPID21,_result);\
		DEM_DET_PARA_NULLPOINTER_REPORT(_Ptr,DEM_SID_SETDATAOFPID21,_result);\
	}while(0)

/* API Dem_SetDataOfPID31 develop errors check */
#define DEM_DETCHECK_API_SETDATAOFPID31(_Status,_Ptr,_result) \
	do{ \
		DEM_DET_INIT_REPORT(_Status,DEM_SID_SETDATAOFPID31,_result);\
		DEM_DET_PARA_NULLPOINTER_REPORT(_Ptr,DEM_SID_SETDATAOFPID31,_result);\
	}while(0)

/* API Dem_SetDataOfPID4D develop errors check */
#define DEM_DETCHECK_API_SETDATAOFPID4D(_Status,_Ptr,_result) \
	do{ \
		DEM_DET_INIT_REPORT(_Status,DEM_SID_SETDATAOFPID4D,_result);\
		DEM_DET_PARA_NULLPOINTER_REPORT(_Ptr,DEM_SID_SETDATAOFPID4D,_result);\
	}while(0)

/* API Dem_SetDataOfPID4E develop errors check */
#define DEM_DETCHECK_API_SETDATAOFPID4E(_Status,_Ptr,_result) \
	do{ \
		DEM_DET_INIT_REPORT(_Status,DEM_SID_SETDATAOFPID4E,_result);\
		DEM_DET_PARA_NULLPOINTER_REPORT(_Ptr,DEM_SID_SETDATAOFPID4E,_result);\
	}while(0)

/* API Dem_SetPfcCycleQualified develop errors check */
#define DEM_DETCHECK_API_SETPFCCYCLEQUALIFIED(_Status,_result) \
	do{ \
		DEM_DET_INIT_REPORT(_Status,DEM_SID_SETPFCCYCLEQUALIFIED,_result);\
	}while(0)

/* API Dem_GetPfcCycleQualified develop errors check */
#define DEM_DETCHECK_API_GETPFCCYCLEQUALIFIED(_Status,_Ptr,_result) \
	do{ \
		DEM_DET_INIT_REPORT(_Status,DEM_SID_GETPFCCYCLEQUALIFIED,_result);\
		DEM_DET_PARA_NULLPOINTER_REPORT(_Ptr,DEM_SID_GETPFCCYCLEQUALIFIED,_result);\
	}while(0)

/* API Dem_SetClearDTC develop errors check */
#define DEM_DETCHECK_API_SETCLEARDTC(_Status,_result) \
	do{ \
		DEM_DET_INIT_REPORT(_Status,DEM_SID_SETCLEARDTC,_result);\
	}while(0)

/* API Dem_DcmGetDTCSeverityAvailabilityMask develop errors check */
#define DEM_DETCHECK_API_DCMGETDTCSEVERITYAVAILABILITYMASK(_Status,_Ptr,_result) \
	do{ \
		DEM_DET_INIT_REPORT(_Status,DEM_SID_DCMGETDTCSEVERITYAVAILABILITYMASK,_result);\
		DEM_DET_PARA_NULLPOINTER_REPORT(_Ptr,DEM_SID_DCMGETDTCSEVERITYAVAILABILITYMASK,_result);\
	}while(0)

/* API Dem_GetB1Counter develop errors check */
#define DEM_DETCHECK_API_GETB1COUNTER(_Status,_result) \
	do{ \
		DEM_DET_INIT_REPORT(_Status,DEM_SID_GETB1COUNTER,_result);\
	}while(0)

/* API Dem_SetDTR develop errors check */
#define DEM_DETCHECK_API_SETDTR(_Status,_result) \
	do{ \
		DEM_DET_INIT_REPORT(_Status,DEM_SID_SETDTR,_result);\
	}while(0)

/* API Dem_DcmGetInfoTypeValue08 develop errors check */
#define DEM_DETCHECK_API_DCMGETINFOTYPEVALUE08(_Status,_Ptr,_result) \
	do{ \
		DEM_DET_INIT_REPORT(_Status,DEM_SID_DCMGETINFOTYPEVALUE08,_result);\
		DEM_DET_PARA_NULLPOINTER_REPORT(_Ptr,DEM_SID_DCMGETINFOTYPEVALUE08,_result);\
	}while(0)

/* API Dem_DcmGetInfoTypeValue0B develop errors check */
#define DEM_DETCHECK_API_DCMGETINFOTYPEVALUE0B(_Status,_Ptr,_result) \
	do{ \
		DEM_DET_INIT_REPORT(_Status,DEM_SID_DCMGETINFOTYPEVALUE0B,_result);\
		DEM_DET_PARA_NULLPOINTER_REPORT(_Ptr,DEM_SID_DCMGETINFOTYPEVALUE0B,_result);\
	}while(0)

/* API Dem_DcmReadDataOfPID01 develop errors check */
#define DEM_DETCHECK_API_DCMREADDATDOFPID01(_Status,_Ptr,_result) \
	do{ \
		DEM_DET_INIT_REPORT(_Status,DEM_SID_DCMREADDATDOFPID01,_result);\
		DEM_DET_PARA_NULLPOINTER_REPORT(_Ptr,DEM_SID_DCMREADDATDOFPID01,_result);\
	}while(0)

/* API Dem_DcmReadDataOfPID1C develop errors check */
#define DEM_DETCHECK_API_DCMREADDATDOFPID1C(_Status,_Ptr,_result) \
	do{ \
		DEM_DET_INIT_REPORT(_Status,DEM_SID_DCMREADDATDOFPID1C,_result);\
		DEM_DET_PARA_NULLPOINTER_REPORT(_Ptr,DEM_SID_DCMREADDATDOFPID1C,_result);\
	}while(0)

/* API Dem_DcmReadDataOfPID21 develop errors check */
#define DEM_DETCHECK_API_DCMREADDATDOFPID21(_Status,_Ptr,_result) \
	do{ \
		DEM_DET_INIT_REPORT(_Status,DEM_SID_DCMREADDATDOFPID21,_result);\
		DEM_DET_PARA_NULLPOINTER_REPORT(_Ptr,DEM_SID_DCMREADDATDOFPID21,_result);\
	}while(0)

/* API Dem_DcmReadDataOfPID30 develop errors check */
#define DEM_DETCHECK_API_DCMREADDATDOFPID30(_Status,_Ptr,_result) \
	do{ \
		DEM_DET_INIT_REPORT(_Status,DEM_SID_DCMREADDATDOFPID30,_result);\
		DEM_DET_PARA_NULLPOINTER_REPORT(_Ptr,DEM_SID_DCMREADDATDOFPID30,_result);\
	}while(0)

/* API Dem_DcmReadDataOfPID31 develop errors check */
#define DEM_DETCHECK_API_DCMREADDATDOFPID31(_Status,_Ptr,_result) \
	do{ \
		DEM_DET_INIT_REPORT(_Status,DEM_SID_DCMREADDATDOFPID31,_result);\
		DEM_DET_PARA_NULLPOINTER_REPORT(_Ptr,DEM_SID_DCMREADDATDOFPID31,_result);\
	}while(0)

/* API Dem_DcmReadDataOfPID41 develop errors check */
#define DEM_DETCHECK_API_DCMREADDATDOFPID41(_Status,_Ptr,_result) \
	do{ \
		DEM_DET_INIT_REPORT(_Status,DEM_SID_DCMREADDATDOFPID41,_result);\
		DEM_DET_PARA_NULLPOINTER_REPORT(_Ptr,DEM_SID_DCMREADDATDOFPID41,_result);\
	}while(0)

/* API Dem_DcmReadDataOfPID4D develop errors check */
#define DEM_DETCHECK_API_DCMREADDATDOFPID4D(_Status,_Ptr,_result) \
	do{ \
		DEM_DET_INIT_REPORT(_Status,DEM_SID_DCMREADDATDOFPID4D,_result);\
		DEM_DET_PARA_NULLPOINTER_REPORT(_Ptr,DEM_SID_DCMREADDATDOFPID4D,_result);\
	}while(0)

/* API Dem_DcmReadDataOfPID4E develop errors check */
#define DEM_DETCHECK_API_DCMREADDATDOFPID4E(_Status,_Ptr,_result) \
	do{ \
		DEM_DET_INIT_REPORT(_Status,DEM_SID_DCMREADDATDOFPID4E,_result);\
		DEM_DET_PARA_NULLPOINTER_REPORT(_Ptr,DEM_SID_DCMREADDATDOFPID4E,_result);\
	}while(0)

/* API Dem_DcmReadDataOfPID01 develop errors check */
#define DEM_DETCHECK_API_DCMREADDATDOFPID91(_Status,_Ptr,_result) \
	do{ \
		DEM_DET_INIT_REPORT(_Status,DEM_SID_DCMREADDATDOFPID91,_result);\
		DEM_DET_PARA_NULLPOINTER_REPORT(_Ptr,DEM_SID_DCMREADDATDOFPID91,_result);\
	}while(0)

/* API Dem_DcmReadDataOfOBDFreezeFrame develop errors check */
#define DEM_DETCHECK_API_DCMREADDATAOFOBDFREEZEFRAME(_Status,_Pid,_Ptr1,_Ptr2,_result) \
	do{ \
		DEM_DET_INIT_REPORT(_Status,DEM_SID_DCMREADDATAOFOBDFREEZEFRAME,_result);\
		DEM_DET_PID_INVALID_REPORT(_Pid,DEM_SID_DCMREADDATAOFOBDFREEZEFRAME,_result);\
		DEM_DET_PARA_NULLPOINTER_REPORT(_Ptr1,DEM_SID_DCMREADDATAOFOBDFREEZEFRAME,_result);\
		DEM_DET_PARA_NULLPOINTER_REPORT(_Ptr2,DEM_SID_DCMREADDATAOFOBDFREEZEFRAME,_result);\
	}while(0)

/* API Dem_DcmGetDTCOfOBDFreezeFrame develop errors check */
#define DEM_DETCHECK_API_DCMGETDTCOFOBDFREEZEFRAME(_Status,_Ptr,_result) \
	do{ \
		DEM_DET_INIT_REPORT(_Status,DEM_SID_DCMGETDTCOFOBDFREEZEFRAME,_result);\
		DEM_DET_PARA_NULLPOINTER_REPORT(_Ptr,DEM_SID_DCMGETDTCOFOBDFREEZEFRAME,_result);\
	}while(0)

/* API Dem_DcmGetAvailableOBDMIDs develop errors check */
#define DEM_DETCHECK_API_DCMGETAVAILABLEOBDMIDS(_Status,_Ptr,_result) \
	do{ \
		DEM_DET_INIT_REPORT(_Status,DEM_SID_DCMGETAVAILABLEOBDMIDS,_result);\
		DEM_DET_PARA_NULLPOINTER_REPORT(_Ptr,DEM_SID_DCMGETAVAILABLEOBDMIDS,_result);\
	}while(0)

/* API Dem_DcmGetNumTIDsOfOBDMID develop errors check */
#define DEM_DETCHECK_API_DCMGETNUMTIDSOFOBDMID(_Status,_Ptr,_result) \
	do{ \
		DEM_DET_INIT_REPORT(_Status,DEM_SID_DCMGETNUMTIDSOFOBDMID,_result);\
		DEM_DET_PARA_NULLPOINTER_REPORT(_Ptr,DEM_SID_DCMGETNUMTIDSOFOBDMID,_result);\
	}while(0)

/* API Dem_DcmGetDTRData develop errors check */
#define DEM_DETCHECK_API_DCMGETDTRDATA(_Status,_Ptr1,_Ptr2,_Ptr3,_Ptr4,_Ptr5,_result) \
	do{ \
		DEM_DET_INIT_REPORT(_Status,DEM_SID_DCMGETDTRDATA,_result);\
		DEM_DET_PARA_NULLPOINTER_REPORT(_Ptr1,DEM_SID_DCMGETDTRDATA,_result);\
		DEM_DET_PARA_NULLPOINTER_REPORT(_Ptr2,DEM_SID_DCMGETDTRDATA,_result);\
		DEM_DET_PARA_NULLPOINTER_REPORT(_Ptr3,DEM_SID_DCMGETDTRDATA,_result);\
		DEM_DET_PARA_NULLPOINTER_REPORT(_Ptr4,DEM_SID_DCMGETDTRDATA,_result);\
		DEM_DET_PARA_NULLPOINTER_REPORT(_Ptr5,DEM_SID_DCMGETDTRDATA,_result);\
	}while(0)



/*====================================================================================================*
 *                                    GLOBAL VARIABLE DECLARATIONS
 *====================================================================================================*/

/*====================================================================================================*
 *                                        FUNCTION PROTOTYPES
 *====================================================================================================*/




#ifdef __cplusplus
}
#endif

#endif /* DEM_GENERAL_H */
/** @} */
