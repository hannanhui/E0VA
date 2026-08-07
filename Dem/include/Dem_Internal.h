/**
 * @file        Dem_Internal.h
 * @brief       AUTOSAR Dem - Dem module internal header file.
 * @details     Dem module internal header file, containing the unofficial API specification and
 *              other variables and functions that are exported by the Dem module.
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

#ifndef DEM_INTERNAL_H
#define DEM_INTERNAL_H

#ifdef __cplusplus
extern "C"{
#endif
/* PRQA S 3453 EOF #
 *
 * 1.3453 -- Violates MISRA 2004 Required Rule 19.7, A function could probably be used instead
 * of this function-like macro.
 *
 * @page misra_violations MISRA-C:2004 violations
 */

/*====================================================================================================*
 *                                           INCLUDE FILES
 *====================================================================================================*/
#include "Dem.h"
#include "NvM.h"
#include "Dem_EventStatus.h"
#include "Dem_DtcStatus.h"
#include "Dem_OperationCycle.h"
#include "Dem_EventConditions.h"
#include "Dem_EventQueue.h"

/*====================================================================================================*
 *                                  HEADER FILE VERSION INFORMATION
 *====================================================================================================*/
#define DEM_INTERNAL_VENDOR_ID             					(0U)
#define DEM_INTERNAL_AR_RELEASE_MAJOR_VERSION      			(4U)
#define DEM_INTERNAL_AR_RELEASE_MINOR_VERSION      			(2U)
#define DEM_INTERNAL_AR_RELEASE_REVISION_VERSION      		(2U)
#define DEM_INTERNAL_SW_MAJOR_VERSION      					(1U)
#define DEM_INTERNAL_SW_MINOR_VERSION      					(2U)
#define DEM_INTERNAL_SW_PATCH_VERSION      					(0U)

/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/
/* Check if current file and Dem.h header file are of the same vendor */
#if(DEM_INTERNAL_VENDOR_ID != DEM_VENDOR_ID )
#error "Dem_Internal.h and Dem.h have different vendor id"
#endif /* #if(DEM_INTERNAL_VENDOR_ID != DEM_VENDOR_ID ) */

/* Check if current file and Dem.h header file are of the same Autosar version */
#if(\
		(DEM_INTERNAL_AR_RELEASE_MAJOR_VERSION != DEM_AR_RELEASE_MAJOR_VERSION) || \
		(DEM_INTERNAL_AR_RELEASE_MINOR_VERSION != DEM_AR_RELEASE_MINOR_VERSION) || \
		(DEM_INTERNAL_AR_RELEASE_REVISION_VERSION != DEM_AR_RELEASE_REVISION_VERSION) \
   )
#error "AutoSar Version Number of Dem_Internal.h and Dem.h are different "
#endif /* #if(\
				(DEM_INTERNAL_AR_RELEASE_MAJOR_VERSION != DEM_AR_RELEASE_MAJOR_VERSION) || \
				(DEM_INTERNAL_AR_RELEASE_MINOR_VERSION != DEM_AR_RELEASE_MINOR_VERSION) || \
				(DEM_INTERNAL_AR_RELEASE_REVISION_VERSION != DEM_AR_RELEASE_REVISION_VERSION) \
   	   	     ) */

/* Check if current file and Dem.h header file are of the same Software version */
#if(\
		(DEM_INTERNAL_SW_MAJOR_VERSION != DEM_SW_MAJOR_VERSION) || \
		(DEM_INTERNAL_SW_MINOR_VERSION != DEM_SW_MINOR_VERSION) || \
		(DEM_INTERNAL_SW_PATCH_VERSION != DEM_SW_PATCH_VERSION) \
   )
#error "Software Version Number of Dem_Internal.h and Dem.h are different "
#endif /* #if(\
				(DEM_INTERNAL_SW_MAJOR_VERSION != DEM_SW_MAJOR_VERSION) || \
				(DEM_INTERNAL_SW_MINOR_VERSION != DEM_SW_MINOR_VERSION) || \
				(DEM_INTERNAL_SW_PATCH_VERSION != DEM_SW_PATCH_VERSION) \
   	   	   	 ) */

/* Check if current file and Dem_EventStatus.h header file are of the same vendor */
#if(DEM_INTERNAL_VENDOR_ID != DEM_EVENTSTATUS_VENDOR_ID )
#error "Dem_Internal.h and Dem_EventStatus.h have different vendor id"
#endif /* #if(DEM_INTERNAL_VENDOR_ID != DEM_EVENTSTATUS_VENDOR_ID ) */

/* Check if current file and Dem_EventStatus.h header file are of the same Autosar version */
#if(\
		(DEM_INTERNAL_AR_RELEASE_MAJOR_VERSION != DEM_EVENTSTATUS_AR_RELEASE_MAJOR_VERSION) || \
		(DEM_INTERNAL_AR_RELEASE_MINOR_VERSION != DEM_EVENTSTATUS_AR_RELEASE_MINOR_VERSION) || \
		(DEM_INTERNAL_AR_RELEASE_REVISION_VERSION != DEM_EVENTSTATUS_AR_RELEASE_REVISION_VERSION) \
   )
#error "AutoSar Version Number of Dem_Internal.h and Dem_EventStatus.h are different "
#endif /* #if(\
				(DEM_INTERNAL_AR_RELEASE_MAJOR_VERSION != DEM_EVENTSTATUS_AR_RELEASE_MAJOR_VERSION) || \
				(DEM_INTERNAL_AR_RELEASE_MINOR_VERSION != DEM_EVENTSTATUS_AR_RELEASE_MINOR_VERSION) || \
				(DEM_INTERNAL_AR_RELEASE_REVISION_VERSION != DEM_EVENTSTATUS_AR_RELEASE_REVISION_VERSION) \
   	   	     ) */

/* Check if current file and Dem_EventStatus.h header file are of the same Software version */
#if(\
		(DEM_INTERNAL_SW_MAJOR_VERSION != DEM_EVENTSTATUS_SW_MAJOR_VERSION) || \
		(DEM_INTERNAL_SW_MINOR_VERSION != DEM_EVENTSTATUS_SW_MINOR_VERSION) || \
		(DEM_INTERNAL_SW_PATCH_VERSION != DEM_EVENTSTATUS_SW_PATCH_VERSION) \
   )
#error "Software Version Number of Dem_Internal.h and Dem_EventStatus.h are different "
#endif /* #if(\
				(DEM_INTERNAL_SW_MAJOR_VERSION != DEM_EVENTSTATUS_SW_MAJOR_VERSION) || \
				(DEM_INTERNAL_SW_MINOR_VERSION != DEM_EVENTSTATUS_SW_MINOR_VERSION) || \
				(DEM_INTERNAL_SW_PATCH_VERSION != DEM_EVENTSTATUS_SW_PATCH_VERSION) \
   	   	   	 ) */

/* Check if current file and Dem_DtcStatus.h header file are of the same vendor */
#if(DEM_INTERNAL_VENDOR_ID != DEM_DTCSTATUS_VENDOR_ID )
#error "Dem_Internal.h and Dem_DtcStatus.h have different vendor id"
#endif /* #if(DEM_INTERNAL_VENDOR_ID != DEM_DTCSTATUS_VENDOR_ID ) */

/* Check if current file and Dem_DtcStatus.h header file are of the same Autosar version */
#if(\
		(DEM_INTERNAL_AR_RELEASE_MAJOR_VERSION != DEM_DTCSTATUS_AR_RELEASE_MAJOR_VERSION) || \
		(DEM_INTERNAL_AR_RELEASE_MINOR_VERSION != DEM_DTCSTATUS_AR_RELEASE_MINOR_VERSION) || \
		(DEM_INTERNAL_AR_RELEASE_REVISION_VERSION != DEM_DTCSTATUS_AR_RELEASE_REVISION_VERSION) \
   )
#error "AutoSar Version Number of Dem_Internal.h and Dem_DtcStatus.h are different "
#endif /* #if(\
				(DEM_INTERNAL_AR_RELEASE_MAJOR_VERSION != DEM_DTCSTATUS_AR_RELEASE_MAJOR_VERSION) || \
				(DEM_INTERNAL_AR_RELEASE_MINOR_VERSION != DEM_DTCSTATUS_AR_RELEASE_MINOR_VERSION) || \
				(DEM_INTERNAL_AR_RELEASE_REVISION_VERSION != DEM_DTCSTATUS_AR_RELEASE_REVISION_VERSION) \
   	   	     ) */

/* Check if current file and Dem_DtcStatus.h header file are of the same Software version */
#if(\
		(DEM_INTERNAL_SW_MAJOR_VERSION != DEM_DTCSTATUS_SW_MAJOR_VERSION) || \
		(DEM_INTERNAL_SW_MINOR_VERSION != DEM_DTCSTATUS_SW_MINOR_VERSION) || \
		(DEM_INTERNAL_SW_PATCH_VERSION != DEM_DTCSTATUS_SW_PATCH_VERSION) \
   )
#error "Software Version Number of Dem_Internal.h and Dem_DtcStatus.h are different "
#endif /* #if(\
				(DEM_INTERNAL_SW_MAJOR_VERSION != DEM_DTCSTATUS_SW_MAJOR_VERSION) || \
				(DEM_INTERNAL_SW_MINOR_VERSION != DEM_DTCSTATUS_SW_MINOR_VERSION) || \
				(DEM_INTERNAL_SW_PATCH_VERSION != DEM_DTCSTATUS_SW_PATCH_VERSION) \
   	   	   	 ) */

/* Check if current file and Dem_OperationCycle.h header file are of the same vendor */
#if(DEM_INTERNAL_VENDOR_ID != DEM_OPERATIONCYCLE_VENDOR_ID )
#error "Dem_Internal.h and Dem_OperationCycle.h have different vendor id"
#endif /* #if(DEM_INTERNAL_VENDOR_ID != DEM_OPERATIONCYCLE_VENDOR_ID ) */

/* Check if current file and Dem_OperationCycle.h header file are of the same Autosar version */
#if(\
		(DEM_INTERNAL_AR_RELEASE_MAJOR_VERSION != DEM_OPERATIONCYCLE_AR_RELEASE_MAJOR_VERSION) || \
		(DEM_INTERNAL_AR_RELEASE_MINOR_VERSION != DEM_OPERATIONCYCLE_AR_RELEASE_MINOR_VERSION) || \
		(DEM_INTERNAL_AR_RELEASE_REVISION_VERSION != DEM_OPERATIONCYCLE_AR_RELEASE_REVISION_VERSION) \
   )
#error "AutoSar Version Number of Dem_Internal.h and Dem_OperationCycle.h are different "
#endif /* #if(\
				(DEM_INTERNAL_AR_RELEASE_MAJOR_VERSION != DEM_OPERATIONCYCLE_AR_RELEASE_MAJOR_VERSION) || \
				(DEM_INTERNAL_AR_RELEASE_MINOR_VERSION != DEM_OPERATIONCYCLE_AR_RELEASE_MINOR_VERSION) || \
				(DEM_INTERNAL_AR_RELEASE_REVISION_VERSION != DEM_OPERATIONCYCLE_AR_RELEASE_REVISION_VERSION) \
   	   	     ) */

/* Check if current file and Dem_OperationCycle.h header file are of the same Software version */
#if(\
		(DEM_INTERNAL_SW_MAJOR_VERSION != DEM_OPERATIONCYCLE_SW_MAJOR_VERSION) || \
		(DEM_INTERNAL_SW_MINOR_VERSION != DEM_OPERATIONCYCLE_SW_MINOR_VERSION) || \
		(DEM_INTERNAL_SW_PATCH_VERSION != DEM_OPERATIONCYCLE_SW_PATCH_VERSION) \
   )
#error "Software Version Number of Dem_Internal.h and Dem_OperationCycle.h are different "
#endif /* #if(\
				(DEM_INTERNAL_SW_MAJOR_VERSION != DEM_OPERATIONCYCLE_SW_MAJOR_VERSION) || \
				(DEM_INTERNAL_SW_MINOR_VERSION != DEM_OPERATIONCYCLE_SW_MINOR_VERSION) || \
				(DEM_INTERNAL_SW_PATCH_VERSION != DEM_OPERATIONCYCLE_SW_PATCH_VERSION) \
   	   	   	 ) */

/* Check if current file and Dem_EventConditions.h header file are of the same vendor */
#if(DEM_INTERNAL_VENDOR_ID != DEM_EVENTCONDITIONS_VENDOR_ID )
#error "Dem_Internal.h and Dem_EventConditions.h have different vendor id"
#endif /* #if(DEM_INTERNAL_VENDOR_ID != DEM_EVENTCONDITIONS_VENDOR_ID ) */

/* Check if current file and Dem_EventConditions.h header file are of the same Autosar version */
#if(\
		(DEM_INTERNAL_AR_RELEASE_MAJOR_VERSION != DEM_EVENTCONDITIONS_AR_RELEASE_MAJOR_VERSION) || \
		(DEM_INTERNAL_AR_RELEASE_MINOR_VERSION != DEM_EVENTCONDITIONS_AR_RELEASE_MINOR_VERSION) || \
		(DEM_INTERNAL_AR_RELEASE_REVISION_VERSION != DEM_EVENTCONDITIONS_AR_RELEASE_REVISION_VERSION) \
   )
#error "AutoSar Version Number of Dem_Internal.h and Dem_EventConditions.h are different "
#endif /* #if(\
				(DEM_INTERNAL_AR_RELEASE_MAJOR_VERSION != DEM_EVENTCONDITIONS_AR_RELEASE_MAJOR_VERSION) || \
				(DEM_INTERNAL_AR_RELEASE_MINOR_VERSION != DEM_EVENTCONDITIONS_AR_RELEASE_MINOR_VERSION) || \
				(DEM_INTERNAL_AR_RELEASE_REVISION_VERSION != DEM_EVENTCONDITIONS_AR_RELEASE_REVISION_VERSION) \
   	   	     ) */

/* Check if current file and Dem_EventConditions.h header file are of the same Software version */
#if(\
		(DEM_INTERNAL_SW_MAJOR_VERSION != DEM_EVENTCONDITIONS_SW_MAJOR_VERSION) || \
		(DEM_INTERNAL_SW_MINOR_VERSION != DEM_EVENTCONDITIONS_SW_MINOR_VERSION) || \
		(DEM_INTERNAL_SW_PATCH_VERSION != DEM_EVENTCONDITIONS_SW_PATCH_VERSION) \
   )
#error "Software Version Number of Dem_Internal.h and Dem_EventConditions.h are different "
#endif /* #if(\
				(DEM_INTERNAL_SW_MAJOR_VERSION != DEM_EVENTCONDITIONS_SW_MAJOR_VERSION) || \
				(DEM_INTERNAL_SW_MINOR_VERSION != DEM_EVENTCONDITIONS_SW_MINOR_VERSION) || \
				(DEM_INTERNAL_SW_PATCH_VERSION != DEM_EVENTCONDITIONS_SW_PATCH_VERSION) \
   	   	   	 ) */

/* Check if current file and Dem_EventQueue.h header file are of the same vendor */
#if(DEM_INTERNAL_VENDOR_ID != DEM_EVENTQUEUE_VENDOR_ID )
#error "Dem_Internal.h and Dem_EventQueue.h have different vendor id"
#endif /* #if(DEM_INTERNAL_VENDOR_ID != DEM_EVENTQUEUE_VENDOR_ID ) */

/* Check if current file and Dem_EventQueue.h header file are of the same Autosar version */
#if(\
		(DEM_INTERNAL_AR_RELEASE_MAJOR_VERSION != DEM_EVENTQUEUE_AR_RELEASE_MAJOR_VERSION) || \
		(DEM_INTERNAL_AR_RELEASE_MINOR_VERSION != DEM_EVENTQUEUE_AR_RELEASE_MINOR_VERSION) || \
		(DEM_INTERNAL_AR_RELEASE_REVISION_VERSION != DEM_EVENTQUEUE_AR_RELEASE_REVISION_VERSION) \
   )
#error "AutoSar Version Number of Dem_Internal.h and Dem_EventQueue.h are different "
#endif /* #if(\
				(DEM_INTERNAL_AR_RELEASE_MAJOR_VERSION != DEM_EVENTQUEUE_AR_RELEASE_MAJOR_VERSION) || \
				(DEM_INTERNAL_AR_RELEASE_MINOR_VERSION != DEM_EVENTQUEUE_AR_RELEASE_MINOR_VERSION) || \
				(DEM_INTERNAL_AR_RELEASE_REVISION_VERSION != DEM_EVENTQUEUE_AR_RELEASE_REVISION_VERSION) \
   	   	     ) */

/* Check if current file and Dem_EventQueue.h header file are of the same Software version */
#if(\
		(DEM_INTERNAL_SW_MAJOR_VERSION != DEM_EVENTQUEUE_SW_MAJOR_VERSION) || \
		(DEM_INTERNAL_SW_MINOR_VERSION != DEM_EVENTQUEUE_SW_MINOR_VERSION) || \
		(DEM_INTERNAL_SW_PATCH_VERSION != DEM_EVENTQUEUE_SW_PATCH_VERSION) \
   )
#error "Software Version Number of Dem_Internal.h and Dem_EventQueue.h are different "
#endif /* #if(\
				(DEM_INTERNAL_SW_MAJOR_VERSION != DEM_EVENTQUEUE_SW_MAJOR_VERSION) || \
				(DEM_INTERNAL_SW_MINOR_VERSION != DEM_EVENTQUEUE_SW_MINOR_VERSION) || \
				(DEM_INTERNAL_SW_PATCH_VERSION != DEM_EVENTQUEUE_SW_PATCH_VERSION) \
   	   	   	 ) */

#ifndef DISABLE_INTERMOD_VERSION_CHECK
/* Check if current file and NvM.h header file are of the same Autosar version */
#if(\
		(DEM_INTERNAL_AR_RELEASE_MAJOR_VERSION != NVM_AR_RELEASE_MAJOR_VERSION) || \
		(DEM_INTERNAL_AR_RELEASE_MINOR_VERSION != NVM_AR_RELEASE_MINOR_VERSION) \
   )
#error "AutoSar Version Number of Dem_Internal.h and NvM.h are different "
#endif /* #if(\
				(DEM_INTERNAL_AR_RELEASE_MAJOR_VERSION != NVM_AR_RELEASE_MAJOR_VERSION) || \
				(DEM_INTERNAL_AR_RELEASE_MINOR_VERSION != NVM_AR_RELEASE_MINOR_VERSION) \
			 ) */
#endif /* #ifndef DISABLE_INTERMOD_VERSION_CHECK */
/*====================================================================================================*
 *                                             CONSTANTS
 *====================================================================================================*/


/*====================================================================================================*
 *                                         DEFINES AND MACROS
 *====================================================================================================*/

#define DEM_VALUE_COPY(_dest,_sr,_size)      do\
{\
	uint8 * pDest = (uint8*)(_dest);\
	const uint8 * pSrc = (const uint8*)(_sr);\
	uint32 _loop;\
	for(_loop = 0; _loop < (_size); _loop++)\
	{\
		pDest[_loop] = pSrc[_loop];\
	}\
}while(0)

#define DEM_VALUE_SET(_buffer, _value, _size)		do\
{\
	uint32 _loop;\
	for(_loop = 0u; _loop < (_size); _loop++)\
	{\
		_buffer[_loop] = (_value);\
	}\
}while(0)

/*====================================================================================================*
 *                                               ENUMS
 *====================================================================================================*/

/*====================================================================================================*
 *                                   STRUCTURES AND OTHER TYPEDEFS
 *====================================================================================================*/
#if(DEM_DEBOUNCE_COUNTER_BASED_SUPPORT == STD_ON)
#if(DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM > 0)
typedef struct
{
	/**< @brief Debounce counter freeze */
	boolean 				isFreeze;

	/**< @brief Current event status */
	Dem_EventStatusType 	status;

	/**< @brief Current debounce counter */
	sint16 					counter;
}Dem_DebounceCounterType;
#endif /* #if(DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM > 0) */
#endif /* #if(DEM_DEBOUNCE_COUNTER_BASED_SUPPORT == STD_ON) */

#if(DEM_DEBOUNCE_TIME_BASED_SUPPORT == STD_ON)
#if(DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0)
typedef struct
{
	/**< @brief Indicate the debounce timer whether freeze or not */
    boolean 				isFreeze;

    /**< @brief Indicate whether debounce timer has started or not */
    boolean 				triggered;

    /**< @brief Current event status */
    Dem_EventStatusType 	status;

    /**< @brief Internal event id,used for subscript */
    Dem_EventIdType 		IntId;

    /**< @brief Record timer value */
    uint32 					timeout;
} Dem_DebounceTimeType;
#endif /* #if(DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0) */
#endif /* #if(DEM_DEBOUNCE_TIME_BASED_SUPPORT == STD_ON) */



#if(DEM_MAXNUMBER_PRESTORED_FF > 0)
typedef struct
{
	/**< @brief Event identifier */
	Dem_EventIdType     eventId;

#if(DEM_FREEZEFRAME_ENABLE == STD_ON)
	/**< @brief Array which store the freeze frame data of relate event */
    uint8 FFData[DEM_FREEZE_FRAME_MAX_LEN];
#endif /* #if(DEM_FREEZEFRAME_ENABLE == STD_ON) */
}Dem_PreFFInfoType;
#endif /* #if(DEM_MAXNUMBER_PRESTORED_FF > 0) */

typedef struct
{
	/**< @brief The DemInternalDataElement of DEM_AGINGCTR_DOWNCNT */
	uint8 agingDownCnt;

	/**< @brief The DemInternalDataElement of DEM_AGINGCTR_UPCNT,also used to record aging counter */
	uint8 agingUpCnt;

	/**< @brief The DemInternalDataElement of DEM_CYCLES_SINCE_FIRST_FAILED */
	uint8 cyclesSinceFirstFailed;

	/**< @brief The DemInternalDataElement of DEM_CYCLES_SINCE_LAST_FAILED */
	uint8 cyclesSinceLastFailed;

	/**< @brief The DemInternalDataElement of DEM_FAILED_CYCLES */
	uint8 failedCycles;

	/**< @brief The DemInternalDataElement of DEM_OCCCTR */
	uint8 occurCnt;

	/**< @brief The DemInternalDataElement of DEM_OVFLIND */
	uint8 overflowIndication;

	/**< @brief The DemInternalDataElement of DEM_SIGNIFICANCE */
	uint8 significance;

	/**< @brief The DemInternalDataElement of DEM_CURRENT_FDC */
	sint8 currentFDC;

	/**< @brief Record healing counter for relate event */
	uint8 healingCnt;
}Dem_InternalDataType;

#if(DEM_DTC_NUM > 0)
typedef struct
{
	Dem_UdsStatusByteType DTCStatusMask;
	Dem_DTCKindType DTCKind;
	Dem_DTCOriginType DTCOrigin;
	Dem_DTCFormatType DTCFormat;
	boolean FilterWithSeverity;
	Dem_DTCSeverityType DTCSeverityMask;
	boolean FilterForFaultDetectionCounter;
	boolean FilterSet;
	uint16 ReadIndex;
#if(DEM_RESSET_CONFIRMEDBIT_ONOVERFLOW == STD_ON)
	boolean TimeOrder;
	uint8 AbsTime;
	/**< @brief Record whether DTC has been filtered out. */
	uint8 DTCFilterRecord[DEM_DTC_NUM_BYTE];
#endif /* #if(DEM_RESSET_CONFIRMEDBIT_ONOVERFLOW == STD_ON) */
}Dem_DTCFilterTypeType;
#endif /* #if(DEM_DTC_NUM > 0) */

#if(DEM_FREEZE_FRAME_CLASS_NUM > 0)
typedef struct
{
	uint8 CurrentEntry;
	uint8 CurrentFF;
	Dem_DTCFormatType DTCFormat;
	uint16 NumberOfFilteredRecords;
	uint16 AlreadyGetNum;
}Dem_FFRecFilterType;
#endif /* #if(DEM_FREEZE_FRAME_CLASS_NUM > 0) */

typedef struct
{
	uint16 DtcRef;
	Dem_DTCOriginType DTCOrigin;
}Dem_DTCRecordUpdateType;

/**
 * @req [SWS_Dem_00219] provide to Dem_DcmGetDTCByOccurrenceTime
 *      get event by relevant occurrence time.
 */
typedef struct
{
	/**< @brief Record event which is first get failed */
	Dem_EventIdType firstFailEvent;

	/**< @brief Record event which is latest get failed */
	Dem_EventIdType mostFailEvent;

	/**< @brief Record event which is first get confirmed */
	Dem_EventIdType firstConfEvent;

	/**< @brief Record event which is latest get confirmed */
	Dem_EventIdType mostConfEvent;
}Dem_EventOccurTimeType;

#if(DEM_DTC_NUM > 0)
typedef struct
{
	Dem_DTCFormatType DTCFormat;
	Dem_DTCOriginType DTCOrigin;
	uint32 DTC;
}Dem_ClearUdsDtcType;
#endif /* #if(DEM_DTC_NUM > 0) */

#if(DEM_DTR_NUM > 0)
typedef struct
{
    uint16 TestResult;
    uint16 LowerLimit;
    uint16 UpperLimit;
}Dem_DtrInfoType;
#endif /* #if(DEM_DTR_NUM > 0) */

/*====================================================================================================*
 *                                    GLOBAL VARIABLE DECLARATIONS
 *====================================================================================================*/
extern VAR(boolean,DEM_VAR) Dem_ClearDtcLock;

extern P2CONST(Dem_ConfigType, AUTOMATIC, DEM_CONST) Dem_ConfigPtr;

extern VAR(boolean,DEM_VAR)Dem_DcmTriggerEnable;

extern VAR(Dem_DTCRecordUpdateType,DEM_VAR) Dem_DTCRecordUpdateInfo;

extern VAR(Dem_StateType,DEM_VAR) Dem_InitState;

#if(DEM_DTC_NUM > 0)
extern VAR(sint8,DEM_VAR)Dem_InternalFDC[DEM_DTC_NUM];

#endif /* #if(DEM_DTC_NUM > 0) */

extern VAR(Dem_EventOccurTimeType,DEM_VAR)Dem_EventOccTime;

#if(DEM_CALLBACK_INIT_MFOREFNC_TOTALNUM > 0)
extern VAR(Dem_InitMonitorReasonType,DEM_VAR) Dem_InitMonitorCbkStatus[DEM_EVENT_PARAMETER_NUM];
#endif /* #if(DEM_CALLBACK_INIT_MFOREFNC_TOTALNUM > 0) */

#if(DEM_J1939_SUPPORT == STD_ON)
extern VAR(Dem_InternalDataType,DEM_VAR)Dem_EventInternalData[DEM_EVENT_PARAMETER_NUM];
#endif /* #if(DEM_J1939_SUPPORT == STD_ON) */

#if(DEM_INDICATOR_NUM > 0)
#if((DEM_J1939_SUPPORT == STD_ON) || (DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT))
extern VAR(Dem_IndicatorStatusType,DEM_VAR) Dem_IndicatorStatus[DEM_INDICATOR_NUM];
#endif /* #if((DEM_J1939_SUPPORT == STD_ON) || (DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT)) */
#endif /* #if(DEM_INDICATOR_NUM > 0) */

/*====================================================================================================*
 *                                        FUNCTION PROTOTYPES
 *====================================================================================================*/
FUNC(void, DEM_CODE)Dem_DebounceFreeze
(
	Dem_EventIdType InternalEventId
);

FUNC(void, DEM_CODE)Dem_DebounceReset
(
	Dem_EventIdType InternalEventId,
	boolean IsResetAll
);

FUNC(uint16, DEM_CODE) Dem_GetDtcIndexByDtc
(
	uint32 DTC,
    Dem_DTCFormatType DTCFormat
);

FUNC(Dem_MemoryEntryType*, DEM_CODE)Dem_GetEntryFromMemory
(
	Dem_DTCOriginType MemDest,
	Dem_EventIdType EventId
);

FUNC(Dem_MemoryInfoType*, DEM_CODE)Dem_GetMemInfoByOrigin
(
	Dem_DTCOriginType DTCOrigin
);

FUNC(Dem_MemoryEntryType*, DEM_CODE)Dem_GetMemoryConf
(
	Dem_DTCOriginType DTCOrigin,
	P2VAR(uint8,AUTOMATIC,DEM_CONST) pEntryNum
);

FUNC(void, DEM_CODE) Dem_DcmInit
(
	void
);

FUNC(void, DEM_CODE) Dem_DeleMemoryEntry
(
	Dem_DTCOriginType MemDest,
	Dem_MemoryEntryType* EntryPtr
);

FUNC(boolean, DEM_CODE)Dem_ClearDtcStatus
(
	Dem_EventIdType InternalId
);

#if(DEM_INTERNAL_DATA_ELEMENT_NUM > 0)
FUNC(void, DEM_CODE)Dem_CaptureInternalDataElement
(
	Dem_EventIdType InternalEventId,
	P2VAR(uint8,AUTOMATIC,DEM_VAR) pBuffer,
	P2CONST(Dem_InternalDataElementClassType,AUTOMATIC,DEM_CONST)pInternalDataElementClass
);
#endif /* #if(DEM_INTERNAL_DATA_ELEMENT_NUM > 0) */

#ifdef __cplusplus
}
#endif

#endif /* DEM_INTERNAL_H */
/** @} */
