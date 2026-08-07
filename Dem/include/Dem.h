/**
 * @file        Dem.h
 * @brief       AUTOSAR Dem - Dem module header file.
 * @details     Dem module header file, containing the Autosar API specification and
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

#ifndef DEM_H
#define DEM_H

#ifdef __cplusplus
extern "C"{
#endif

/*====================================================================================================*
 *                                           INCLUDE FILES
 *====================================================================================================*/
#include "Dem_Types.h"
#if(DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT)
#include "Rte_Dcm_type.h"
#endif /* #if(DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT) */
/*====================================================================================================*
 *                                  HEADER FILE VERSION INFORMATION
 *====================================================================================================*/
#define DEM_VENDOR_ID               				(0U)
#define DEM_MODULE_ID               				(54U)
#define DEM_INSTANCE_ID             				(0U)
#define DEM_AR_RELEASE_MAJOR_VERSION      			(4U)
#define DEM_AR_RELEASE_MINOR_VERSION      			(2U)
#define DEM_AR_RELEASE_REVISION_VERSION      		(2U)
#define DEM_SW_MAJOR_VERSION      					(1U)
#define DEM_SW_MINOR_VERSION      					(2U)
#define DEM_SW_PATCH_VERSION      					(0U)

/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/
/* Check if current file and Dem_Types.h header file are of the same vendor */
#if(DEM_VENDOR_ID != DEM_TYPES_VENDOR_ID )
#error "Dem.h and Dem_Types.h have different vendor id"
#endif /* #if(DEM_VENDOR_ID != DEM_TYPES_VENDOR_ID ) */

/* Check if current file and Dem_Types.h header file are of the same Autosar version */
#if(\
		(DEM_AR_RELEASE_MAJOR_VERSION != DEM_TYPES_AR_RELEASE_MAJOR_VERSION) || \
		(DEM_AR_RELEASE_MINOR_VERSION != DEM_TYPES_AR_RELEASE_MINOR_VERSION) || \
		(DEM_AR_RELEASE_REVISION_VERSION != DEM_TYPES_AR_RELEASE_REVISION_VERSION) \
   )
#error "AutoSar Version Number of Dem.h and Dem_Types.h are different "
#endif /* #if(\
				(DEM_AR_RELEASE_MAJOR_VERSION != DEM_TYPES_AR_RELEASE_MAJOR_VERSION) || \
				(DEM_AR_RELEASE_MINOR_VERSION != DEM_TYPES_AR_RELEASE_MINOR_VERSION) || \
				(DEM_AR_RELEASE_REVISION_VERSION != DEM_TYPES_AR_RELEASE_REVISION_VERSION) \
   	   	     ) */

/* Check if current file and Dem_Types.h header file are of the same Software version */
#if(\
		(DEM_SW_MAJOR_VERSION != DEM_TYPES_SW_MAJOR_VERSION) || \
		(DEM_SW_MINOR_VERSION != DEM_TYPES_SW_MINOR_VERSION) || \
		(DEM_SW_PATCH_VERSION != DEM_TYPES_SW_PATCH_VERSION) \
   )
#error "Software Version Number of Dem.h and Dem_Types.h are different "
#endif /* #if(\
				(DEM_SW_MAJOR_VERSION != DEM_TYPES_SW_MAJOR_VERSION) || \
				(DEM_SW_MINOR_VERSION != DEM_TYPES_SW_MINOR_VERSION) || \
				(DEM_SW_PATCH_VERSION != DEM_TYPES_SW_PATCH_VERSION) \
   	   	   	 ) */

/*====================================================================================================*
 *                                             CONSTANTS
 *====================================================================================================*/

/* Add code here */

/*====================================================================================================*
 *                                         DEFINES AND MACROS
 *====================================================================================================*/

/*====================================================================================================*
 *                                               ENUMS
 *====================================================================================================*/

/*====================================================================================================*
 *                                   EXTERNAL VARIABLES DECLARATIONS
 *====================================================================================================*/

extern VAR(Dem_UdsStatusByteType,DEM_VAR) Dem_EventUDSBitStatus[DEM_EVENT_PARAMETER_NUM];

#if(DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU)
extern VAR(uint16,DEM_VAR) Dem_B1Counter;

extern VAR(uint16,DEM_VAR) Dem_ConMICounter;

extern VAR(uint16,DEM_VAR) Dem_CumConMICounter;
#endif /* #if(DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU) */

/*====================================================================================================*
 *                                   STRUCTURES AND OTHER TYPEDEFS
 *====================================================================================================*/

typedef struct
{
	boolean OverFlow;
	uint8 EntryNum;
}Dem_MemoryInfoType;
/*====================================================================================================*
 *                                   GLOBAL FUNCTION DECLARATIONS
 *====================================================================================================*/
#if(DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT)
FUNC(void,DEM_CODE) Dem_OBDInit
(
	void
);

FUNC(void,DEM_CODE) Dem_ClearOBDInfo
(
	void
);

#if((DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU) || (DEM_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
FUNC(void, DEM_CODE) Dem_OBDInfoUpdate
(
	void
);

FUNC(void, DEM_CODE) Dem_OBDCounterHandle
(
	uint8   OperationCycleId
);

FUNC(void,DEM_CODE) Dem_OBDMILStatusUpdate
(
	void
);
#endif /* #if((DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU) || (DEM_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU)) */
#endif /* #if(DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT) */
/*====================================================================================================*
 *                                    GLOBAL VARIABLE DECLARATIONS
 *====================================================================================================*/
DEM_CONF_PB

#if(DEM_CALLBACK_EVENT_STATUS_CHANGED_NUM > 0)
extern CONST(Dem_CallbackEventStatusChangedsType,DEM_CONST)  \
		Dem_CallbackEventStatusChangeds[DEM_CALLBACK_EVENT_STATUS_CHANGED_NUM];
#endif /* #if(DEM_CALLBACK_EVENT_STATUS_CHANGED_NUM > 0) */

extern CONST(Dem_GeneralType,DEM_CONST)Dem_General;

extern VAR(Dem_MemoryEntryType,DEM_VAR) DemPrimaryMemory[DEM_MAX_NUMBER_EVENTENTRY_PRIMARY];

#if((DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU) || (DEM_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
extern VAR(Dem_MemoryEntryType, DEM_VAR) DemPermanentMemory[DEM_MAX_NUMBER_EVENTENTRY_PERMANENT];
#endif /* #if((DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU) || (DEM_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU)) */

#if(DEM_DEBOUNCE_MONITOR_INTERNAL_EVENT_NUM > 0)
extern CONST(Dem_GetFDCFncType,DEM_CONST) Dem_CallbackGetFDCFncs[DEM_DEBOUNCE_MONITOR_INTERNAL_EVENT_NUM];
#endif /* #if(DEM_DEBOUNCE_MONITOR_INTERNAL_EVENT_NUM > 0) */

#if(DEM_NVRAM_DEBOUNCE_INFO_NUM > 0)
extern CONST(uint16,AUTOMATIC)Dem_NvRAMDebounceInfo[DEM_NVRAM_DEBOUNCE_INFO_NUM];
#endif /* #if(DEM_NVRAM_DEBOUNCE_INFO_NUM > 0) */

/*====================================================================================================*
 *                                        FUNCTION PROTOTYPES
 *====================================================================================================*/

FUNC(void, DEM_CODE)Dem_MainFunction
(
	void
);

#if (DEM_VERSION_INFO_API == STD_ON)
FUNC(void, DEM_CODE) Dem_GetVersionInfo
(
	P2VAR(Std_VersionInfoType,AUTOMATIC,DEM_VAR)pVersioninfo
);
#endif /* #if (DEM_VERSION_INFO_API == STD_ON) */

FUNC(void, DEM_CODE) Dem_PreInit
(
	void
);

FUNC(void, DEM_CODE) Dem_Init
(
	P2CONST(Dem_ConfigType,AUTOMATIC,DEM_CONST)pConfigPtr
);

FUNC(void, DEM_CODE) Dem_Shutdown
(
	void
);

FUNC(void, DEM_CODE) Dem_ReportErrorStatus
(
    Dem_EventIdType EventId,
    Dem_EventStatusType EventStatus
);

FUNC(Std_ReturnType, DEM_CODE) Dem_SetEventAvailable
(
    Dem_EventIdType EventId,
    boolean AvailableStatus
);

FUNC(Std_ReturnType, DEM_CODE) Dem_ResetEventDebounceStatus
(
    Dem_EventIdType EventId,
    Dem_DebounceResetStatusType DebounceResetStatus
);

FUNC(Std_ReturnType, DEM_CODE) Dem_GetComponentFailed
(
    Dem_ComponentIdType ComponentId,
    P2VAR(boolean, AUTOMATIC, DEM_CODE) pComponentFailed
);

FUNC(Std_ReturnType, DEM_CODE) Dem_GetEventStatus
(
    Dem_EventIdType EventId,
    P2VAR(Dem_UdsStatusByteType, AUTOMATIC, DEM_CODE) pEventStatusByte
);

FUNC(Std_ReturnType, DEM_CODE) Dem_GetEventFailed
(
    Dem_EventIdType EventId,
    P2VAR(boolean,AUTOMATIC,DEM_CODE) pEventFailed
);

FUNC(Std_ReturnType, DEM_CODE) Dem_GetEventTested
(
    Dem_EventIdType EventId,
    P2VAR(boolean, AUTOMATIC, DEM_CODE) pEventTested
);

FUNC(Std_ReturnType, DEM_CODE) Dem_GetDebouncingOfEvent
(
    Dem_EventIdType EventId,
    P2VAR(Dem_DebouncingStateType, AUTOMATIC, DEM_CODE) pDebouncingState
);

FUNC(Std_ReturnType, DEM_CODE) Dem_GetDTCOfEvent
(
    Dem_EventIdType EventId,
    Dem_DTCFormatType DTCFormat,
    P2VAR(uint32, AUTOMATIC, DEM_CODE) pDTCOfEvent
);

FUNC(Std_ReturnType, DEM_CODE) Dem_SetEnableCondition
(
    uint8 EnableConditionID,
    boolean ConditionFulfilled
);

FUNC(Std_ReturnType, DEM_CODE) Dem_SetStorageCondition
(
    uint8 StorageConditionID,
    boolean ConditionFulfilled
);

FUNC(Std_ReturnType, DEM_CODE) Dem_GetIndicatorStatus
(
    uint8 IndicatorId,
    P2VAR(Dem_IndicatorStatusType, AUTOMATIC, DEM_CODE) pIndicatorStatus
);

FUNC(Std_ReturnType, DEM_CODE) Dem_GetEventFreezeFrameDataEx
(
    Dem_EventIdType EventId,
    uint8 RecordNumber,
    uint16 DataId,
    P2VAR(uint8, AUTOMATIC, DEM_CODE) pDestBuffer,
	P2VAR(uint16, AUTOMATIC, DEM_CODE) pBufSize
);

FUNC(Std_ReturnType, DEM_CODE) Dem_GetEventExtendedDataRecordEx
(
    Dem_EventIdType EventId,
    uint8 RecordNumber,
    P2VAR(uint8, AUTOMATIC, DEM_CODE) pDestBuffer,
	P2VAR(uint16, AUTOMATIC, DEM_CODE) pBufSize
);

FUNC(Std_ReturnType, DEM_CODE) Dem_GetEventMemoryOverflow
(
    Dem_DTCOriginType DTCOrigin,
    P2VAR(boolean, AUTOMATIC, DEM_VAR) pOverflowIndication
);

FUNC(Std_ReturnType, DEM_CODE) Dem_GetNumberOfEventMemoryEntries
(
    Dem_DTCOriginType DTCOrigin,
    P2VAR(uint8, AUTOMATIC, DEM_CODE) pNumberOfEventMemoryEntries
);

FUNC(Std_ReturnType, DEM_CODE) Dem_SetComponentAvailable
(
	Dem_ComponentIdType ComponentId,
	boolean AvailableStatus
);

#if(DEM_SUPPRESSION_SUPPORT == DEM_DTC_SUPPRESSION)
FUNC(Std_ReturnType, DEM_CODE) Dem_SetDTCSuppression
(
    uint32 DTC,
    Dem_DTCFormatType DTCFormat,
    boolean SuppressionStatus
);
#endif /* #if(DEM_SUPPRESSION_SUPPORT == DEM_DTC_SUPPRESSION) */

#if(DEM_J1939_SUPPORT == STD_ON)
FUNC(Dem_ReturnSetFilterType , DEM_CODE)Dem_J1939DcmSetDTCFilter
(
	Dem_J1939DcmDTCStatusFilterType DTCStatusFilter,
    Dem_DTCKindType DemJ1939DTCFilterInfo,
    uint8 node,
    Dem_J1939DcmLampStatusType* LampStatus
);

FUNC(Dem_ReturnGetNumberOfFilteredDTCType , DEM_CODE)Dem_J1939DcmGetNumberOfFilteredDTC
(
	uint16* NumberOfFilteredDTC
);

FUNC(Dem_ReturnGetNextFilteredElementType , DEM_CODE)Dem_J1939DcmGetNextFilteredDTC
(
	uint32* J1939DTC,
	uint8* OccurenceCounter
);

FUNC(void , DEM_CODE) Dem_J1939DcmFirstDTCwithLampStatus
(
	uint8 node
);

FUNC(Dem_ReturnGetNextFilteredElementType , DEM_CODE)Dem_J1939DcmGetNextDTCwithLampStatus
(
		Dem_J1939DcmLampStatusType* LampStatus,
        uint32* J1939DTC,
        uint8* OccurenceCounter
);

FUNC(Dem_ReturnClearDTCType, DEM_CODE)Dem_J1939DcmClearDTC
(
    Dem_J1939DcmSetClearFilterType DTCTypeFilter,
    uint8 node
);

FUNC(Dem_ReturnSetFilterType , DEM_CODE)Dem_J1939DcmSetFreezeFrameFilter
(
	Dem_J1939DcmSetFreezeFrameFilterType FreezeFrameKind,
	uint8 node
);

FUNC(Dem_ReturnGetNextFilteredElementType , DEM_CODE)Dem_J1939DcmGetNextFreezeFrame
(
	uint32* J1939DTC,
    uint8* OccurenceCounter,
    uint8* DestBuffer,
    uint16* BufSize
);

FUNC(Dem_ReturnGetNextFilteredElementType , DEM_CODE)Dem_J1939DcmGetNextSPNInFreezeFrame
(
	uint32* SPNSupported,
	uint8* SPNDataLength
);

FUNC(Dem_ReturnSetFilterType , DEM_CODE)Dem_J1939DcmSetRatioFilter
(
	uint16* IgnitionCycleCounter,
    uint16* OBDMonitoringConditionsEncountered,
    uint8 node
);

FUNC(Dem_ReturnGetNextFilteredElementType , DEM_CODE)Dem_J1939DcmGetNextFilteredRatio
(
	uint16* SPN,
    uint16* Numerator,
    uint16* Denominator
);

FUNC(Std_ReturnType , DEM_CODE)Dem_J1939DcmReadDiagnosticReadiness1
(
	Dem_J1939DcmDiagnosticReadiness1Type* DataValue,
	uint8 node
);

FUNC(Std_ReturnType , DEM_CODE)Dem_J1939DcmReadDiagnosticReadiness2
(
	Dem_J1939DcmDiagnosticReadiness2Type* DataValue,
	uint8 node
);

FUNC(Std_ReturnType , DEM_CODE)Dem_J1939DcmReadDiagnosticReadiness3
(
	Dem_J1939DcmDiagnosticReadiness3Type* DataValue,
	uint8 node
);
#endif /* #if(DEM_J1939_SUPPORT == STD_ON) */

#if(DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT)
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetInfoTypeValue08
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DEM_CODE) Iumprdata08,
    P2VAR(uint8, AUTOMATIC, DEM_CODE) Iumprdata08BufferSize
);

FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetInfoTypeValue0B
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DEM_CODE) Iumprdata0B,
    P2VAR(uint8, AUTOMATIC, DEM_CODE) Iumprdata0BBufferSize
);

FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID01
(
    P2VAR(uint8, AUTOMATIC, DEM_CODE) PID01value
);

FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID1C
(
    P2VAR(uint8, AUTOMATIC, DEM_CODE) PID1Cvalue
);

FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID21
(
    P2VAR(uint8, AUTOMATIC, DEM_CODE) PID21value
);

FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID30
(
    P2VAR(uint8, AUTOMATIC, DEM_CODE) PID30value
);

FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID31
(
    P2VAR(uint8, AUTOMATIC, DEM_CODE) PID31value
);

FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID4D
(
    P2VAR(uint8, AUTOMATIC, DEM_CODE) PID4Dvalue
);

FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID4E
(
    P2VAR(uint8, AUTOMATIC, DEM_CODE) PID4Evalue
);

FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID41
(
    P2VAR(uint8, AUTOMATIC, DEM_CODE) PID41value
);

FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID91
(
    P2VAR(uint8, AUTOMATIC, DEM_CODE) PID91value
);

FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfOBDFreezeFrame
(
    uint8 PID,
    uint8 DataElementIndexOfPID,
    P2VAR(uint8, AUTOMATIC, DEM_CODE) DestBuffer,
    P2VAR(uint16, AUTOMATIC, DEM_CODE) BufSize
);

FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetDTCOfOBDFreezeFrame
(
    uint8 FrameNumber,
    uint32* DTC,
    Dem_DTCFormatType DTCFormat
);

FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetAvailableOBDMIDs
(
    uint8 Obdmid,
    uint32* Obdmidvalue
);

FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetNumTIDsOfOBDMID
(
    uint8 Obdmid,
    P2VAR(uint8, AUTOMATIC, DEM_CODE) numberOfTIDs
);

FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetDTRData
(
    uint8 Obdmid,
    uint8 TIDindex,
    P2VAR(uint8, AUTOMATIC, DEM_CODE) TIDvalue,
    P2VAR(uint8, AUTOMATIC, DEM_CODE) UaSID,
    P2VAR(uint16, AUTOMATIC, DEM_CODE) Testvalue,
    P2VAR(uint16, AUTOMATIC, DEM_CODE) Lowlimvalue,
    P2VAR(uint16, AUTOMATIC, DEM_CODE) Upplimvalue
);

FUNC(Std_ReturnType, DEM_CODE) Dem_SetEventDisabled
(
    Dem_EventIdType EventId
);

FUNC(Std_ReturnType, DEM_CODE) Dem_RepIUMPRFaultDetect
(
    Dem_RatioIdType RatioID
);

FUNC(Std_ReturnType, DEM_CODE) Dem_SetIUMPRDenCondition
(
    Dem_IumprDenomCondIdType ConditionId,
    Dem_IumprDenomCondStatusType ConditionStatus
);

FUNC(Std_ReturnType, DEM_CODE) Dem_GetIUMPRDenCondition
(
    Dem_IumprDenomCondIdType ConditionId,
    Dem_IumprDenomCondStatusType* ConditionStatus
);

FUNC(Std_ReturnType, DEM_CODE) Dem_RepIUMPRDenLock
(
    Dem_RatioIdType RatioID
);

FUNC(Std_ReturnType, DEM_CODE) Dem_RepIUMPRDenRelease
(
    Dem_RatioIdType RatioID
);

FUNC(Std_ReturnType, DEM_CODE) Dem_SetPtoStatus
(
    boolean PtoStatus
);

FUNC(Std_ReturnType, DEM_CODE) Dem_ReadDataOfPID01
(
    P2VAR(uint8, AUTOMATIC, DEM_CODE) PID01value
);

FUNC(Std_ReturnType, DEM_CODE) Dem_GetDataOfPID21
(
    P2VAR(uint8, AUTOMATIC, DEM_CODE) PID21value
);

FUNC(Std_ReturnType, DEM_CODE) Dem_SetDataOfPID21
(
    P2VAR(uint8, AUTOMATIC, DEM_CODE) PID21value
);

FUNC(Std_ReturnType, DEM_CODE) Dem_SetDataOfPID31
(
    P2VAR(uint8, AUTOMATIC, DEM_CODE) PID31value
);

FUNC(Std_ReturnType, DEM_CODE) Dem_SetDataOfPID4D
(
    P2VAR(uint8, AUTOMATIC, DEM_CODE) PID4Dvalue
);

FUNC(Std_ReturnType, DEM_CODE) Dem_SetDataOfPID4E
(
    P2VAR(uint8, AUTOMATIC, DEM_CODE) PID4Evalue
);

FUNC(Std_ReturnType, DEM_CODE) Dem_SetPfcCycleQualified
(
    void
);

FUNC(Std_ReturnType, DEM_CODE) Dem_GetPfcCycleQualified
(
    P2VAR(boolean, AUTOMATIC, DEM_VAR) isqualified
);

#if(DEM_OBD_SUPPORT == DEM_OBD_DEP_SEC_ECU)
FUNC(Std_ReturnType, DEM_CODE) Dem_SetClearDTC
(
    uint32 DTC,
    Dem_DTCFormatType DTCFormat,
    Dem_DTCOriginType DTCOrigin
);
#endif /* #if(DEM_OBD_SUPPORT == DEM_OBD_DEP_SEC_ECU) */

FUNC(Std_ReturnType, DEM_CODE) Dem_GetB1Counter
(
    P2VAR(uint16, AUTOMATIC, DEM_CODE) B1Counter
);

FUNC(Std_ReturnType, DEM_CODE) Dem_SetDTR
(
    uint16 DTRId,
    sint32 TestResult,
    sint32 LowerLimit,
    sint32 UpperLimit,
    Dem_DTRControlType Ctrlval
);
#endif /* #if(DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT) */

#ifdef __cplusplus
}
#endif

#endif /* DEM_H */
/** @} */
