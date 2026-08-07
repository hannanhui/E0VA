/* PRQA S 0292 EOF */
/**
 * @file        Dem_Dcm.c
 * @brief       AUTOSAR Dem  - Dem module source file.
 * @details     Dem module source file, containing the C implementation of Autosar API specification
 *              and other variables and functions that are provided for Dcm.
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

#ifdef __cplusplus
extern "C"{
#endif
/* PRQA S 5087,0791,0491,1503,0857,0779,1330,2986,2985,2877,0498,1290,0488,2995,0715,4397,2991,2880 EOF #
 *
 * 1.5087 -- Violates MISRA 2004 Required Rule 19.1,#include statements in a file should only
 * be preceded by other preprocessor directives or comments.
 *
 * 2.0791 -- Violates MISRA 2004 Required Rule 5.1, Macro identifier does not differ from other macro
 * identifier(s) within the specified number of significant characters.
 *
 * 3.0491 -- Violates MISRA 2004 Required Rule 17.4, Array subscripting applied to an object of pointer
 * type.
 *
 * 4.1503 -- Violates MISRA 2004 Required Rule 14.1, The function is defined but is not used within
 * this project.
 *
 * @page misra_violations MISRA-C:2004 violations
 */
/*====================================================================================================*
 *                                           INCLUDE FILES
 *====================================================================================================*/
#include "Dem.h"
#include "Dem_Dcm.h"
#include "Dem_Internal.h"
#include "Rte_Dem.h"

#ifdef AH_TEST_DEM
#include "TestCode.h"
#endif /* #ifdef AH_TEST_DEM */
/*====================================================================================================*
 *                                  SOURCE FILE VERSION INFORMATION
 *====================================================================================================*/
#define DEM_DCM_VENDOR_ID_C               					(0U)
#define DEM_DCM_AR_RELEASE_MAJOR_VERSION_C      			(4U)
#define DEM_DCM_AR_RELEASE_MINOR_VERSION_C      			(2U)
#define DEM_DCM_AR_RELEASE_REVISION_VERSION_C      			(2U)
#define DEM_DCM_SW_MAJOR_VERSION_C      					(1U)
#define DEM_DCM_SW_MINOR_VERSION_C      					(2U)
#define DEM_DCM_SW_PATCH_VERSION_C      					(0U)

/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/
/* Check if current file and Dem.h header file are of the same vendor */
#if(DEM_DCM_VENDOR_ID_C != DEM_VENDOR_ID )
#error "Dem_Dcm.c and Dem.h have different vendor id"
#endif /* #if(DEM_DCM_VENDOR_ID_C != DEM_VENDOR_ID ) */

/* Check if current file and Dem.h header file are of the same Autosar version */
#if(\
		(DEM_DCM_AR_RELEASE_MAJOR_VERSION_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
		(DEM_DCM_AR_RELEASE_MINOR_VERSION_C != DEM_AR_RELEASE_MINOR_VERSION) || \
		(DEM_DCM_AR_RELEASE_REVISION_VERSION_C != DEM_AR_RELEASE_REVISION_VERSION) \
   )
#error "AutoSar Version Number of Dem_Dcm.c and Dem.h are different "
#endif /* #if(\
				(DEM_DCM_AR_RELEASE_MAJOR_VERSION_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
				(DEM_DCM_AR_RELEASE_MINOR_VERSION_C != DEM_AR_RELEASE_MINOR_VERSION) || \
				(DEM_DCM_AR_RELEASE_REVISION_VERSION_C != DEM_AR_RELEASE_REVISION_VERSION) \
   	   	     ) */

/* Check if current file and Dem.h header file are of the same Software version */
#if(\
		(DEM_DCM_SW_MAJOR_VERSION_C != DEM_SW_MAJOR_VERSION) || \
		(DEM_DCM_SW_MINOR_VERSION_C != DEM_SW_MINOR_VERSION) || \
		(DEM_DCM_SW_PATCH_VERSION_C != DEM_SW_PATCH_VERSION) \
   )
#error "Software Version Number of Dem_Dcm.c and Dem.h are different "
#endif /* #if(\
				(DEM_DCM_SW_MAJOR_VERSION_C != DEM_SW_MAJOR_VERSION) || \
				(DEM_DCM_SW_MINOR_VERSION_C != DEM_SW_MINOR_VERSION) || \
				(DEM_DCM_SW_PATCH_VERSION_C != DEM_SW_PATCH_VERSION) \
   	   	   	 ) */

/* Check if current file and Dem_Dcm.h header file are of the same vendor */
#if(DEM_DCM_VENDOR_ID_C != DEM_DCM_VENDOR_ID )
#error "Dem_Dcm.c and Dem_Dcm.h have different vendor id"
#endif /* #if(DEM_DCM_VENDOR_ID_C != DEM_DCM_VENDOR_ID ) */

/* Check if current file and Dem_Dcm.h header file are of the same Autosar version */
#if(\
		(DEM_DCM_AR_RELEASE_MAJOR_VERSION_C != DEM_DCM_AR_RELEASE_MAJOR_VERSION) || \
		(DEM_DCM_AR_RELEASE_MINOR_VERSION_C != DEM_DCM_AR_RELEASE_MINOR_VERSION) || \
		(DEM_DCM_AR_RELEASE_REVISION_VERSION_C != DEM_DCM_AR_RELEASE_REVISION_VERSION) \
   )
#error "AutoSar Version Number of Dem_Dcm.c and Dem_Dcm.h are different "
#endif /* #if(\
				(DEM_DCM_AR_RELEASE_MAJOR_VERSION_C != DEM_DCM_AR_RELEASE_MAJOR_VERSION) || \
				(DEM_DCM_AR_RELEASE_MINOR_VERSION_C != DEM_DCM_AR_RELEASE_MINOR_VERSION) || \
				(DEM_DCM_AR_RELEASE_REVISION_VERSION_C != DEM_DCM_AR_RELEASE_REVISION_VERSION) \
   	   	     ) */

/* Check if current file and Dem_Dcm.h header file are of the same Software version */
#if(\
		(DEM_DCM_SW_MAJOR_VERSION_C != DEM_DCM_SW_MAJOR_VERSION) || \
		(DEM_DCM_SW_MINOR_VERSION_C != DEM_DCM_SW_MINOR_VERSION) || \
		(DEM_DCM_SW_PATCH_VERSION_C != DEM_DCM_SW_PATCH_VERSION) \
   )
#error "Software Version Number of Dem_Dcm.c and Dem_Dcm.h are different "
#endif /* #if(\
				(DEM_DCM_SW_MAJOR_VERSION_C != DEM_DCM_SW_MAJOR_VERSION) || \
				(DEM_DCM_SW_MINOR_VERSION_C != DEM_DCM_SW_MINOR_VERSION) || \
				(DEM_DCM_SW_PATCH_VERSION_C != DEM_DCM_SW_PATCH_VERSION) \
   	   	   	 ) */

/* Check if current file and Dem_Internal.h header file are of the same vendor */
#if(DEM_DCM_VENDOR_ID_C != DEM_INTERNAL_VENDOR_ID )
#error "Dem_Dcm.c and Dem_Internal.h have different vendor id"
#endif /* #if(DEM_DCM_VENDOR_ID_C != DEM_INTERNAL_VENDOR_ID ) */

/* Check if current file and Dem_Internal.h header file are of the same Autosar version */
#if(\
		(DEM_DCM_AR_RELEASE_MAJOR_VERSION_C != DEM_INTERNAL_AR_RELEASE_MAJOR_VERSION) || \
		(DEM_DCM_AR_RELEASE_MINOR_VERSION_C != DEM_INTERNAL_AR_RELEASE_MINOR_VERSION) || \
		(DEM_DCM_AR_RELEASE_REVISION_VERSION_C != DEM_INTERNAL_AR_RELEASE_REVISION_VERSION) \
   )
#error "AutoSar Version Number of Dem_Dcm.c and Dem_Internal.h are different "
#endif /* #if(\
				(DEM_DCM_AR_RELEASE_MAJOR_VERSION_C != DEM_INTERNAL_AR_RELEASE_MAJOR_VERSION) || \
				(DEM_DCM_AR_RELEASE_MINOR_VERSION_C != DEM_INTERNAL_AR_RELEASE_MINOR_VERSION) || \
				(DEM_DCM_AR_RELEASE_REVISION_VERSION_C != DEM_INTERNAL_AR_RELEASE_REVISION_VERSION) \
   	   	     ) */

/* Check if current file and Dem_Internal.h header file are of the same Software version */
#if(\
		(DEM_DCM_SW_MAJOR_VERSION_C != DEM_INTERNAL_SW_MAJOR_VERSION) || \
		(DEM_DCM_SW_MINOR_VERSION_C != DEM_INTERNAL_SW_MINOR_VERSION) || \
		(DEM_DCM_SW_PATCH_VERSION_C != DEM_INTERNAL_SW_PATCH_VERSION) \
   )
#error "Software Version Number of Dem_Dcm.c and Dem_Internal.h are different "
#endif /* #if(\
				(DEM_DCM_SW_MAJOR_VERSION_C != DEM_INTERNAL_SW_MAJOR_VERSION) || \
				(DEM_DCM_SW_MINOR_VERSION_C != DEM_INTERNAL_SW_MINOR_VERSION) || \
				(DEM_DCM_SW_PATCH_VERSION_C != DEM_INTERNAL_SW_PATCH_VERSION) \
   	   	   	 ) */

#if(DEM_DCM_ENABLE == STD_ON)
/*====================================================================================================*
 *                                   EXTERNAL FUNCTION DECLARATIONS
 *====================================================================================================*/

/* Add code here */

/*====================================================================================================*
 *                                           LOCAL TYPEDEFS
 *====================================================================================================*/

/* Add code here */

/*====================================================================================================*
 *                                            LOCAL MACROS
 *====================================================================================================*/
#ifdef AH_UNITTEST_ENABLED
	#ifdef STATIC
		#undef STATIC
		#define STATIC
	#else
		#define STATIC
	#endif /* STATIC */

	#ifdef INLINE
		#undef INLINE
		#define INLINE
	#else
		#define STATIC_INLINE
	#endif /* INLINE */

	#ifdef STATIC_INLINE
		#undef STATIC_INLINE
		#define STATIC_INLINE
	#else
		#define STATIC_INLINE
	#endif /* STATIC_INLINE */
#else
	#ifndef STATIC
		#define STATIC static
	#endif /* STATIC */

	#ifndef INLINE
		#define INLINE inline
	#endif /* INLINE */

	#ifndef STATIC_INLINE
		#define STATIC_INLINE static inline
	#endif /* STATIC_INLINE */

#endif /* AH_UNITTEST_ENABLED */
/*====================================================================================================*
 *                                           LOCAL VARIABLES
 *====================================================================================================*/
#if(DEM_DTC_NUM > 0)

#define DEM_START_SEC_VAR_NO_INIT_BOOLEAN
#include "Dem_MemMap.h"
/**
 * @brief 	Indicates which Dtc stop updata now.
 */
STATIC VAR(boolean,DEM_VAR)Dem_DtcUpdateDisabled[DEM_DTC_NUM_BYTE];
#define DEM_STOP_SEC_VAR_NO_INIT_BOOLEAN
#include "Dem_MemMap.h"

#define DEM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dem_MemMap.h"
/**
 * @brief 	Used to record filter information which set by Dem_DcmSetDTCFilter.
 */
STATIC VAR(Dem_DTCFilterTypeType,DEM_VAR) Dem_DTCFilter;

/**
 * @brief Record information about clearing uds dtcs.
 */
STATIC VAR(Dem_ClearUdsDtcType,DEM_VAR)Dem_ClearDtcInfo;
#define DEM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dem_MemMap.h"
#endif /* #if(DEM_DTC_NUM > 0) */

#if(DEM_FREEZE_FRAME_CLASS_NUM > 0)
#define DEM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dem_MemMap.h"
/**
 * @brief 	Used to record filter information which set by Dem_DcmSetFreezeFrameRecordFilter.
 */
STATIC VAR(Dem_FFRecFilterType,DEM_VAR) Dem_FFRecFilter;
#define DEM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dem_MemMap.h"
#endif /* #if(DEM_FREEZE_FRAME_CLASS_NUM > 0) */

/*====================================================================================================*
 *                                      LOCAL FUNCTION PROTOTYPES
 *====================================================================================================*/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
#if(DEM_DTC_NUM > 0)
STATIC FUNC(void, DEM_CODE) Dem_DTCSettingDeal
(
	uint8 DTCSetting,
    Dem_DTCKindType DTCKind
);

STATIC FUNC(Dem_ReturnClearDTCType, DEM_CODE)Dem_DcmClearUDSDtc
(
	uint32 DTC,
	Dem_DTCFormatType DTCFormat,
	Dem_DTCOriginType DTCOrigin
);

STATIC FUNC(boolean,DEM_CODE)Dem_FilterDtcCheck
(
	uint16 u16DtcRef
);

STATIC FUNC(Dem_ReturnGetNextFilteredElementType, DEM_CODE)Dem_GetALLFilteredDTC
(
	P2VAR(uint32, AUTOMATIC, DEM_CODE) pDTC,
	P2VAR(Dem_UdsStatusByteType, AUTOMATIC, DEM_CODE) pDTCStatus
);

#if(DEM_RESSET_CONFIRMEDBIT_ONOVERFLOW == STD_ON)
STATIC FUNC(Dem_ReturnGetNextFilteredElementType, DEM_CODE)Dem_ReportDtcByTimeOrder
(
	P2VAR(uint32, AUTOMATIC, DEM_CODE) pDTC,
	P2VAR(Dem_UdsStatusByteType, AUTOMATIC, DEM_CODE) pDTCStatus
);
#endif /* #if(DEM_RESSET_CONFIRMEDBIT_ONOVERFLOW == STD_ON) */

STATIC FUNC(Dem_ReturnGetNextFilteredElementType, DEM_CODE)Dem_ReportDtcByConfOrder
(
	P2VAR(uint32, AUTOMATIC, DEM_CODE) pDTC,
	P2VAR(Dem_UdsStatusByteType, AUTOMATIC, DEM_CODE) pDTCStatus
);

STATIC FUNC(Dem_ReturnClearDTCType, DEM_CODE) Dem_ClearDTCAll
(
	void
);

#if(DEM_CLEARDTC_LIMITATION == DEM_ALL_SUPPORTED_DTCS)
STATIC FUNC(Dem_ReturnClearDTCType, DEM_CODE) Dem_ClearDTCSingle
(
	uint16 DtcIndex
);
#endif /* #if(DEM_CLEARDTC_LIMITATION == DEM_ALL_SUPPORTED_DTCS) */
#endif /* #if(DEM_DTC_NUM > 0) */

#if(DEM_FREEZE_FRAME_CLASS_NUM > 0)
STATIC FUNC(Dem_ReturnGetFreezeFrameDataByDTCType, DEM_CODE)Dem_DcmGetFreezeFrameDataByDTCSubDeal
(
	uint16 DTCIndex,
	Dem_DTCOriginType DTCOrigin,
	uint8 RecordNumber,
	P2VAR(uint8, AUTOMATIC, DEM_CODE) pDestBuffer,
	P2VAR(uint16, AUTOMATIC, DEM_CODE) pBufSize
);

STATIC FUNC(void, DEM_CODE)Dem_GetSizeOfFFByDTCSubDeal
(
	uint8 RecordNumber,
	uint16 DtcRef,
	Dem_DTCOriginType DTCOrigin,
	P2VAR(uint16,AUTOMATIC,DEM_CODE) pSizeOfFreezeFrame
);
#endif /* #if(DEM_FREEZE_FRAME_CLASS_NUM > 0) */

#if(DEM_EXTENDED_DATA_CLASS_NUM > 0)
STATIC FUNC(Dem_ReturnGetExtendedDataRecordByDTCType, DEM_CODE)Dem_DcmGetExtendedDataRecordByDTCSubDeal
(
	uint16 DTCIndex,
	Dem_DTCOriginType DTCOrigin,
	uint8 ExtendedDataNumber,
	P2VAR(uint8, AUTOMATIC, DEM_CODE) pDestBuffer,
	P2VAR(uint16, AUTOMATIC, DEM_CODE) pBufSize
);

STATIC FUNC(void, DEM_CODE)Dem_DcmGetSizeOfExtendedDataRecordSubDeal
(
	uint16 DtcRef,
	Dem_DTCOriginType DTCOrigin,
	uint8 ExtendedDataNumber,
	P2VAR(uint16, AUTOMATIC, DEM_CODE) pSizeOfExtendedDataRecord
);
#endif /* #if(DEM_EXTENDED_DATA_CLASS_NUM > 0) */

#if(DEM_GROUP_OF_DTC_NUM > 0)
STATIC FUNC(uint8, DEM_CODE) Dem_GetDTCGroupIndex
(
	uint32 DTCGroup
);

#if(DEM_CLEARDTC_LIMITATION == DEM_ALL_SUPPORTED_DTCS)
STATIC FUNC(Dem_ReturnClearDTCType, DEM_CODE) Dem_ClearDTCGroup
(
	uint8 GroupIndex
);
#endif /* #if(DEM_CLEARDTC_LIMITATION == DEM_ALL_SUPPORTED_DTCS) */
#endif /* #if(DEM_GROUP_OF_DTC_NUM > 0u) */

#if((DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT) && (DEM_OBD_DTC_NUM > 0u))
STATIC FUNC(Dem_ReturnClearDTCType,DEM_CODE)Dem_DcmClearOBDDtc
(
	void
);
#endif /* #if((DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT) && (DEM_OBD_DTC_NUM > 0u)) */

#if(DEM_DTC_NUM > 0)
STATIC FUNC(Dem_ReturnClearDTCType,DEM_CODE)Dem_ClearDtcDeal
(
	Dem_DTCOriginType DTCOrigin,
	Dem_EventIdType InternalId
);
#endif /* #if(DEM_DTC_NUM > 0) */

#if(DEM_CLEAR_DTC_BEHAVIOR != DEM_CLRRESP_VOLATILE)
STATIC FUNC(Dem_ReturnClearDTCType, DEM_CODE) Dem_ClearEntryFromNvRAM
(
	Dem_DTCOriginType DTCOrigin,
	Dem_EventIdType EventId
);
#endif /* #if(DEM_CLEAR_DTC_BEHAVIOR != DEM_CLRRESP_VOLATILE) */

#if(DEM_FREEZE_FRAME_CLASS_NUM > 0)
STATIC FUNC(boolean, DEM_CODE) Dem_FFRecNumCheck
(
	uint16 DTCIndex,
	uint8 RecordNumber
);
#endif /* #if(DEM_FREEZE_FRAME_CLASS_NUM > 0) */

#if(DEM_EXTENDED_DATA_CLASS_NUM > 0)
STATIC FUNC(boolean, DEM_CODE) Dem_ExtRecNumCheck
(
	uint16 DTCIndex,
	uint8 RecordNumber
);
#endif /* #if(DEM_EXTENDED_DATA_CLASS_NUM > 0) */
/*====================================================================================================*
 *                                           LOCAL FUNCTIONS
 *====================================================================================================*/
#if(DEM_DTC_NUM > 0)
STATIC FUNC(void, DEM_CODE) Dem_DTCSettingDeal
(
	uint8 DTCSetting,
    Dem_DTCKindType DtcSettingKind
)
{
	uint16 u16Loop;
	uint16 u16DtcRef;

	switch(DTCSetting)
	{
	case 0u:	/* 'all DTC group setting' has not been set*/
#if(DEM_GROUP_OF_DTC_NUM > 0)
		for(u16Loop = 0u; u16Loop < DEM_EVENT_PARAMETER_NUM; u16Loop++)
		{
			u16DtcRef = Dem_ConfigPtr->DemEventParameter[u16Loop].DemDTCRef;

			if((u16DtcRef != 0xFFFFu)\
				&& ((DtcSettingKind == DEM_DTC_KIND_ALL_DTCS)\
					|| (Dem_ConfigPtr->DemDTC[u16DtcRef].DemObdDTCRef != 0xFFFFu)))
			{
				if(Dem_ConfigPtr->DemDTC[u16DtcRef].DemDtcGroupRef != 0xFFu)
				{
					if(!(Dem_ISEnable_GroupDTC(Dem_ConfigPtr->DemDTC[u16DtcRef].DemDtcGroupRef)))
					{
						Dem_Disable_DTCSetting(u16Loop);
						/**
						 * @req [SWS_Dem_00678] If the configuration parameter DemDebounceBehavior
						 * 		is set to DEM_DEBOUNCE_FREEZE, the Dem module shall freeze the
						 * 		internal debounce timer when ControlDTCSetting is set to disabled
						 * 		for the related event.
						 */
						Dem_DebounceFreeze(u16Loop);
					}
					else
					{
						if(!(Dem_ISEnable_DTCSetting(u16Loop)))
						{
							Dem_Enable_DTCSetting(u16Loop);

							/**
							 * @req [SWS_Dem_00682] The API Dem_DcmEnableDTCSetting shall trigger the
							 *      callback function InitMonitorForEvent of the related event(s) in case
							 *      ControlDTCSetting of the event(s) is re-enabled.The InitMonitorReason
							 *      parameter shall be set to DEM_INIT_MONITOR_REENABLED.
							 */
#if(DEM_CALLBACK_INIT_MFOREFNC_TOTALNUM > 0)
							if(Dem_ConfigPtr->DemEventParameter[u16Loop].DemCallbackInitMForE\
									!= NULL_PTR)
							{
								if(Dem_ConfigPtr->DemEventParameter[u16Loop].DemCallbackInitMForE->\
										DemCallbackInitMForEFnc != NULL_PTR)
								{
									/**
									 * @req [SWS_Dem_01046] In case multiple triggers for DemInitMonitor-
									 *      ForEvent occur simultaneously, the InitMforE shall only be
									 *      called once.The reason shall be selected by following priority:
									 *      DEM_INIT_MONITOR_CLEAR (highest priority), DEM_INIT_MONITOR_
									 *      RESTART,DEM_INIT_MONITOR_REENABLED (lowest priority).
									 */
									if(Dem_InitMonitorCbkStatus[u16Loop] == 0u)
									{
										Dem_InitMonitorCbkStatus[u16Loop] = DEM_INIT_MONITOR_REENABLED;
									}
								}
							}
#endif /* #if(DEM_CALLBACK_INIT_MFOREFNC_TOTALNUM > 0) */
						}
					}
				}
			}
		}
#endif /* #if(DEM_GROUP_OF_DTC_NUM > 0) */
		break;

	case 1u: 	/* disable 'all DTC group setting' */
		for(u16Loop = 0u; u16Loop < DEM_EVENT_PARAMETER_NUM; u16Loop++)
		{
			u16DtcRef = Dem_ConfigPtr->DemEventParameter[u16Loop].DemDTCRef;

			if((u16DtcRef != 0xFFFFu)\
				&& ((DtcSettingKind == DEM_DTC_KIND_ALL_DTCS)\
					|| (Dem_ConfigPtr->DemDTC[u16DtcRef].DemObdDTCRef != 0xFFFFu)))
			{
				Dem_Disable_DTCSetting(u16Loop);

#if(DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM > 0)
				if(Dem_ConfigPtr->DemEventParameter[u16Loop].DemDebounceAlgorithmClassType \
						== DEM_DEBOUNCE_COUNTER_BASED)
				{
					if(Dem_ConfigPtr->DemDebounceCounterBasedClass[Dem_ConfigPtr->\
						DemEventParameter[u16Loop].DemDebounceAlgorithmRef].DemDebounceBehavior ==\
							DEM_DEBOUNCE_RESET)
					{
						Dem_DebounceReset(u16Loop,(boolean)FALSE);
					}
					else
					{
						Dem_DebounceFreeze(u16Loop);
					}
				}
#endif /* #if(DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM > 0) */
#if(DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0)
				if(Dem_ConfigPtr->DemEventParameter[u16Loop].DemDebounceAlgorithmClassType \
											== DEM_DEBOUNCE_TIME_BASE)
				{
					if(Dem_ConfigPtr->DemDebounceTimeBaseClass[Dem_ConfigPtr->\
						DemEventParameter[u16Loop].DemDebounceAlgorithmRef].DemDebounceBehavior\
							== DEM_DEBOUNCE_RESET)
					{
						Dem_DebounceReset(u16Loop,(boolean)FALSE);
					}
					else
					{
						Dem_DebounceFreeze(u16Loop);
					}
				}
#endif /* #if(DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0) */
			}
		}
		break;

	case 2u:	/* enable 'all DTC group setting' */
		for(u16Loop = 0u; u16Loop < DEM_EVENT_PARAMETER_NUM; u16Loop++)
		{
			u16DtcRef = Dem_ConfigPtr->DemEventParameter[u16Loop].DemDTCRef;

			if((u16DtcRef != 0xFFFFu)\
				&& ((DtcSettingKind == DEM_DTC_KIND_ALL_DTCS)\
					|| (Dem_ConfigPtr->DemDTC[u16DtcRef].DemObdDTCRef != 0xFFFFu)))
			{
				if(Dem_ISEnable_DTCSetting(u16Loop) == (boolean)FALSE)
				{
					Dem_Enable_DTCSetting(u16Loop);
				}
				/**
				 * @req [SWS_Dem_00682] The API Dem_DcmEnableDTCSetting shall trigger the
				 *      callback function InitMonitorForEvent of the related event(s) in case
				 *      ControlDTCSetting of the event(s) is re-enabled.The InitMonitorReason
				 *      parameter shall be set to DEM_INIT_MONITOR_REENABLED.
				 */
#if(DEM_CALLBACK_INIT_MFOREFNC_TOTALNUM > 0)
				if(Dem_ConfigPtr->DemEventParameter[u16Loop].DemCallbackInitMForE\
						!= NULL_PTR)
				{
					if(Dem_ConfigPtr->DemEventParameter[u16Loop].DemCallbackInitMForE->\
							DemCallbackInitMForEFnc != NULL_PTR)
					{
						/**
						 * @req [SWS_Dem_01046] In case multiple triggers for DemInitMonitorFor-
						 *      Event occur simultaneously,the InitMforE shall only be called once.
						 *      The reason shall be selected by following priority:DEM_INIT_MONITOR
						 *      _CLEAR (highest priority),DEM_INIT_MONITOR_RESTART,DEM_INIT_MONITOR
						 *      _REENABLED (lowest priority).
						 */
						if(Dem_InitMonitorCbkStatus[u16Loop] == 0u)
						{
							Dem_InitMonitorCbkStatus[u16Loop] = DEM_INIT_MONITOR_REENABLED;
						}
					}
				}
#endif /* #if(DEM_CALLBACK_INIT_MFOREFNC_TOTALNUM > 0) */
				}
			}
			break;
		default:
			break;
	}
}

#if(DEM_CLEAR_DTC_BEHAVIOR != DEM_CLRRESP_VOLATILE)
STATIC FUNC(Dem_ReturnClearDTCType, DEM_CODE) Dem_ClearEntryFromNvRAM
(
	Dem_DTCOriginType DTCOrigin,
	Dem_EventIdType EventId
)
{
	Dem_ReturnClearDTCType ret = (Dem_ReturnClearDTCType)DEM_CLEAR_OK;
	NvM_RequestResultType result;
	uint16 u16BlockRef;
	uint16 u16Index = 0u;
	uint8 u8EntryNum;
	Dem_MemoryEntryType* pEntry = Dem_GetMemoryConf(DTCOrigin,&u8EntryNum);

#if(DEM_MAX_NUMBER_EVENTENTRY_PERMANENT > 0)
	u16BlockRef = Dem_General.DemNvRamBlockId\
			[DEM_MAX_NUMBER_EVENTENTRY_PRIMARY + DEM_MAX_NUMBER_EVENTENTRY_PERMANENT];
#else
	u16BlockRef = Dem_General.DemNvRamBlockId[DEM_MAX_NUMBER_EVENTENTRY_PRIMARY];
#endif /* #if(DEM_MAX_NUMBER_EVENTENTRY_PERMANENT > 0) */
	(void)NvM_GetErrorStatus(u16BlockRef,&result);
	if(result != NVM_REQ_PENDING)
	{
		(void)NvM_WriteBlock(u16BlockRef,Dem_EventUDSBitStatus);
	}
	else
	{
		Dem_NvMPending = (boolean)TRUE;
		ret = (Dem_ReturnClearDTCType)DEM_CLEAR_MEMORY_ERROR;
	}

	while(u16Index < u8EntryNum)
	{
		if(pEntry->EventId == EventId)
		{
			if(DTCOrigin == DEM_DTC_ORIGIN_PRIMARY_MEMORY)
			{
				u16BlockRef = Dem_General.DemNvRamBlockId[u16Index];
				(void)NvM_GetErrorStatus(u16BlockRef,&result);
				if(result != NVM_REQ_PENDING)
				{
					(void)NvM_WriteBlock(u16BlockRef,&DemPrimaryMemory[u16Index]);
				}
				else
				{
					Dem_NvMPending = (boolean)TRUE;
					ret = (Dem_ReturnClearDTCType)DEM_CLEAR_MEMORY_ERROR;
				}
			}
			else
			{
				/* others DTCOrigin */
			}

		}
		u16Index++;
		pEntry++;
	}

	return ret;
}
#endif /* #if(DEM_CLEAR_DTC_BEHAVIOR != DEM_CLRRESP_VOLATILE) */

STATIC FUNC(Dem_ReturnClearDTCType, DEM_CODE)Dem_DcmClearUDSDtc
(
	uint32 DTC,
	Dem_DTCFormatType DTCFormat,
	Dem_DTCOriginType DTCOrigin
)
{
	Dem_ReturnClearDTCType ret = DEM_CLEAR_WRONG_DTC;

#if(DEM_CLEARDTC_LIMITATION == DEM_ALL_SUPPORTED_DTCS)
#if(DEM_GROUP_OF_DTC_NUM > 0)
	uint8 u8DtcGroupIndex;
#endif /* #if(DEM_GROUP_OF_DTC_NUM > 0) */
	uint16 u16DtcRef;
#endif /* #if(DEM_CLEARDTC_LIMITATION == DEM_ALL_SUPPORTED_DTCS) */

	if ((DTC & 0xFFFFFFu) == 0xFFFFFFu)
	{
		ret = Dem_ClearDTCAll();
	}
#if(DEM_CLEARDTC_LIMITATION == DEM_ALL_SUPPORTED_DTCS)
	else
	{
#if(DEM_GROUP_OF_DTC_NUM > 0)
		u8DtcGroupIndex = Dem_GetDTCGroupIndex(DTC);

		if(u8DtcGroupIndex != DEM_GROUP_OF_DTC_NUM)
		{
			ret = Dem_ClearDTCGroup(u8DtcGroupIndex);
		}
		else
#endif /* #if(DEM_GROUP_OF_DTC_NUM > 0) */
		{
			u16DtcRef = Dem_GetDtcIndexByDtc(DTC,DTCFormat);

			if(u16DtcRef != 0xFFFFu)
			{
				ret = Dem_ClearDTCSingle(u16DtcRef);
			}
		}
	}
#endif /* #if(DEM_CLEARDTC_LIMITATION == DEM_ALL_SUPPORTED_DTCS) */
	return ret;
}

STATIC FUNC(Dem_ReturnClearDTCType,DEM_CODE)Dem_ClearDtcDeal
(
	Dem_DTCOriginType DTCOrigin,
	Dem_EventIdType InternalId
)
{
	Dem_ReturnClearDTCType ret = (Dem_ReturnClearDTCType)DEM_CLEAR_FAILED;
	Dem_MemoryEntryType* pEntry;
	uint16 u16DtcRef = Dem_ConfigPtr->DemEventParameter[InternalId].DemDTCRef;

	if(Dem_ISEnable_DTCSuppress(u16DtcRef) == (boolean)FALSE)
	{
		if(Dem_ClearDtcStatus(InternalId) == (boolean)TRUE)
		{
			pEntry = Dem_GetEntryFromMemory(DTCOrigin,(InternalId + 1u));
			if(pEntry != NULL_PTR)
			{
				Dem_DeleMemoryEntry(DTCOrigin,pEntry);

#if(DEM_CLEAR_DTC_BEHAVIOR == DEM_CLRRESP_NONVOLATILE_FINISH)
			/**
			 * @req [SWS_Dem_01057] If the Dem module is requested to clear diagnostic information
			 * 		and the configuration parameter DemClearDTCBehavior is set to
			 * 		DEM_CLRRESP_NONVOLATILE_FINISH, the Dem module shall return DEM_CLEAR_MEMORY_ERROR
			 * 		(refer to Dem_ReturnClearDTCType) if the clearing of the non-volatile memory fails.
			 * @req [SWS_Dem_00572] If the Dem module is requested to clear diagnostic information
			 *      and the configuration parameter DemClearDTCBehavior is set to DEM_CLRRESP_NON-
			 *      VOLATILE_FINISH, the Dem module shall return DEM_CLEAR_OK after the volatile
			 *      memory and the non-volatile memory is cleared.
			 */
			ret = Dem_ClearEntryFromNvRAM(DTCOrigin,(InternalId + 1u));
#else
#if(DEM_CLEAR_DTC_BEHAVIOR == DEM_CLRRESP_NONVOLATILE_TRIGGER)
			/**
			 * @req [SWS_Dem_00571] If the Dem module is requested to clear diagnostic information
			 * 		and the configuration parameter DemClearDTCBehavior is set to
			 * 		DEM_CLRRESP_NONVOLATILE_TRIGGER, the Dem module shall return DEM_CLEAR_OK (refer
			 * 		to chapter 8.2.2.12) after the volatile memory is cleared and clearing of the
			 * 		non-volatile memory is triggered.
			 */
			Dem_ClearEntryFromNvRAM(DTCOrigin,(InternalId + 1u));
#endif /* #if(DEM_CLEAR_DTC_BEHAVIOR == DEM_CLRRESP_NONVOLATILE_TRIGGER) */
			/**
			 * @req [SWS_Dem_00570] If the Dem module is requested to clear diagnostic information
			 * 		and the configuration parameter DemClearDTCBehavior is set to DEM_CLRRESP_VOLATILE,
			 * 		the Dem module shall return DEM_CLEAR_OK after the volatile memory is cleared.
			 */
			ret =(Dem_ReturnClearDTCType)DEM_CLEAR_OK;
#endif /* #if(DEM_CLEAR_DTC_BEHAVIOR == DEM_CLRRESP_NONVOLATILE_FINISH) */
			}
			else
			{
				/* the entry does not exist,so do not need to clear NvM,return DEM_CLEAR_OK. */
				ret = (Dem_ReturnClearDTCType)DEM_CLEAR_OK;
			}
		}
	}
	return ret;
}

#if((DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT) && (DEM_OBD_DTC_NUM > 0u))
STATIC FUNC(Dem_ReturnClearDTCType,DEM_CODE)Dem_DcmClearOBDDtc
(
	void
)
{
	Dem_ReturnClearDTCType ret = (Dem_ReturnClearDTCType)DEM_CLEAR_FAILED;
	uint16 u16Loop;
	uint16 u16DtcRef;
	Dem_MemoryInfoType* pMemInfo = Dem_GetMemInfoByOrigin(Dem_ClearDtcInfo.DTCOrigin);
#if(DEM_GROUP_OF_DTC_NUM > 0)
	uint8 u8GroupIndex;
#endif /* #if(DEM_GROUP_OF_DTC_NUM > 0) */

#if(DEM_OBD_SUPPORT == DEM_OBD_DEP_SEC_ECU)
	/**
	 * @req [SWS_Dem_00723] In Dependent / Secondary ECU service $04 execution shall lead to
	 * 		reset / erase to all (non emissionrelated and emission-related) DTCs in primary
	 * 		and all user defined event memories (if configured).
	 */
	for(u16Loop = 0u; u16Loop < DEM_EVENT_PARAMETER_NUM; u16Loop++)
	{
		u16DtcRef = Dem_ConfigPtr->DemEventParameter[u16Loop].DemDTCRef;
		if(u16DtcRef != 0xFFFFu)
		{
			ret = Dem_ClearDtcDeal(Dem_ClearDtcInfo.DTCOrigin,u16Loop);
		}

		Dem_ClearOBDInfo();
	}
#if(DEM_USERDEFINE_MEMORY_NUM > 0)
	/* clear user define memory. */
#endif /* #if(DEM_USERDEFINE_MEMORY_NUM > 0) */
#else /* <DEM_OBD_SUPPORT = DEM_OBD_MASTER_ECU or DEM_OBD_PRIMARY_ECU> */
#if(DEM_OBD_COMPLIANCY == 15u)
	/*
	 * @req [SWS_Dem_01179] Service $14 FFFF33 shall clear all DTCs (WWH-OBD DTCs and
	 * 		UDS DTCs)
	 */
	if(Dem_ClearDtcInfo.DTC == 0xFFFF33u)
	{
		for(u16Loop = 0u; u16Loop < DEM_EVENT_PARAMETER_NUM; u16Loop++)
		{
			u16DtcRef = Dem_ConfigPtr->DemEventParameter[u16Loop].DemDTCRef;
			if(u16DtcRef != 0xFFFFu)
			{
				if(Dem_ConfigPtr->DemDTC[u16DtcRef].DemDtcValue != 0u)
				{
					ret = Dem_ClearDtcDeal(Dem_ClearDtcInfo.DTCOrigin,u16Loop);
				}
			}
		}

		Dem_ClearOBDInfo();
	}
	else
#endif /* #if(DEM_OBD_COMPLIANCY == 15u) */
	{
#if(DEM_GROUP_OF_DTC_NUM > 0)
		u8GroupIndex = Dem_GetDTCGroupIndex(Dem_ClearDtcInfo.DTC);

		if(u8GroupIndex != DEM_GROUP_OF_DTC_NUM)
		{
			for(u16Loop = 0u; u16Loop < DEM_EVENT_PARAMETER_NUM; u16Loop++)
			{
				u16DtcRef = Dem_ConfigPtr->DemEventParameter[u16Loop].DemDTCRef;
				if(Dem_ConfigPtr->DemDTC[u16DtcRef].DemDtcGroupRef == u8GroupIndex)
				{
					ret = Dem_ClearDtcDeal(Dem_ClearDtcInfo.DTCOrigin,u16Loop);
				}
			}
		}
		else
#endif /* #if(DEM_GROUP_OF_DTC_NUM > 0) */
		{
			for(u16Loop = 0u; u16Loop < DEM_EVENT_PARAMETER_NUM; u16Loop++)
			{
				u16DtcRef = Dem_ConfigPtr->DemEventParameter[u16Loop].DemDTCRef;
				if((u16DtcRef != 0xFFFFu)\
					&&(Dem_ConfigPtr->DemDTC[u16DtcRef].DemObdDTCRef != 0xFFFFu))
				{
					if(Dem_ConfigPtr->DemDTC[u16DtcRef].DemDtcValue == 0u)/* OBD2 DTC */
					{
						if(Dem_ConfigPtr->DemObdDTC[Dem_ConfigPtr->DemDTC[u16DtcRef].\
								DemObdDTCRef].DemDtcValue == Dem_ClearDtcInfo.DTC)
						{
							ret = Dem_ClearDtcDeal(Dem_ClearDtcInfo.DTCOrigin,u16Loop);
						}
					}
					else/* WWH-OBD DTC */
					{
						if(Dem_ConfigPtr->DemDTC[u16DtcRef].DemDtcValue == Dem_ClearDtcInfo.DTC)
						{
							ret = Dem_ClearDtcDeal(Dem_ClearDtcInfo.DTCOrigin,u16Loop);
						}
					}
				}
			}
		}
	}

	if(pMemInfo->EntryNum == 0u)
	{
		pMemInfo->OverFlow = (boolean)FALSE;
	}
#endif /* #if(DEM_OBD_SUPPORT == DEM_OBD_DEP_SEC_ECU) */
	return ret;
}
#endif /* #if((DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT) && (DEM_OBD_DTC_NUM > 0u)) */

STATIC FUNC(boolean,DEM_CODE)Dem_FilterDtcCheck
(
	uint16 u16DtcRef
)
{
	boolean ret = (boolean)TRUE;

	if((Dem_DTCFilter.DTCStatusMask != 0u) && ((DEM_DTCSTATUS_AVAILABILITY_MASK & \
			Dem_DTCFilter.DTCStatusMask & Dem_DtcUdsStatus[u16DtcRef]) == 0u))
	{
		ret = (boolean)FALSE;
	}
	else if((Dem_DTCFilter.DTCKind == DEM_DTC_KIND_EMISSION_REL_DTCS)
		&& (Dem_ConfigPtr->DemDTC[u16DtcRef].DemObdDTCRef != 0xFFFFu))
	{
		ret = (boolean)FALSE;
	}
	else if(((Dem_DTCFilter.DTCFormat == DEM_DTC_FORMAT_UDS) \
			&& ((Dem_ConfigPtr->DemDTC[u16DtcRef].DemDTCFormat & 0x01u) == 0u))
		|| ((Dem_DTCFilter.DTCFormat == DEM_DTC_FORMAT_OBD) \
			&& ((Dem_ConfigPtr->DemDTC[u16DtcRef].DemDTCFormat & 0x02u) == 0u))
		|| ((Dem_DTCFilter.DTCFormat == DEM_DTC_FORMAT_J1939) \
			&& ((Dem_ConfigPtr->DemDTC[u16DtcRef].DemDTCFormat & 0x04u) == 0u)))
	{
		ret = (boolean)FALSE;
	}
	else if(Dem_ConfigPtr->DemDTCAttributes[Dem_ConfigPtr->DemDTC[u16DtcRef].DemDTCAttributesRef].\
			DemMemoryDestinationRef != Dem_DTCFilter.DTCOrigin)
	{
		ret = (boolean)FALSE;
	}
	else if((Dem_DTCFilter.FilterWithSeverity == (boolean)TRUE)
		&& ((Dem_DTCFilter.DTCSeverityMask & Dem_ConfigPtr->DemDTC[u16DtcRef].DemDTCSeverity) == 0u))
	{
		ret = (boolean)FALSE;
	}
	else if((Dem_DTCFilter.FilterForFaultDetectionCounter == (boolean)TRUE)
		&& (Dem_InternalFDC[u16DtcRef] <= (sint8)0))
	{
		ret = (boolean)FALSE;
	}
	else
	{
		;
	}

	return ret;
}

STATIC FUNC(Dem_ReturnGetNextFilteredElementType, DEM_CODE)Dem_GetALLFilteredDTC
(
	P2VAR(uint32, AUTOMATIC, DEM_CODE) pDTC,
	P2VAR(Dem_UdsStatusByteType, AUTOMATIC, DEM_CODE) pDTCStatus
)
{
	Dem_ReturnGetNextFilteredElementType ret = DEM_FILTERED_NO_MATCHING_ELEMENT;

	do
	{
		/**
		 * @req [SWS_Dem_01101] A suppressed DTC shall not be visible for Dem_DcmGetNextFilteredDTC.
		 */
		if(Dem_ISEnable_DTCSuppress(Dem_DTCFilter.ReadIndex) == (boolean)FALSE)
		{
			*pDTC = Dem_ConfigPtr->DemDTC[Dem_DTCFilter.ReadIndex].DemDtcValue;
			*pDTCStatus = (Dem_DtcUdsStatus[Dem_DTCFilter.ReadIndex] & DEM_DTCSTATUS_AVAILABILITY_MASK);
			Dem_DTCFilter.ReadIndex++;
			ret = DEM_FILTERED_OK;
			break;
		}
		Dem_DTCFilter.ReadIndex++;
	}while(Dem_DTCFilter.ReadIndex < DEM_DTC_NUM);

	if(ret == DEM_FILTERED_NO_MATCHING_ELEMENT)
	{
		Dem_DTCFilter.ReadIndex = 0u;
	}

	return ret;
}

STATIC FUNC(Dem_ReturnGetNextFilteredElementType, DEM_CODE)Dem_ReportDtcByConfOrder
(
	P2VAR(uint32, AUTOMATIC, DEM_CODE) pDTC,
	P2VAR(Dem_UdsStatusByteType, AUTOMATIC, DEM_CODE) pDTCStatus
)
{
	Dem_ReturnGetNextFilteredElementType ret = DEM_FILTERED_NO_MATCHING_ELEMENT;

	do
	{
		if((Dem_ISEnable_DTCSuppress(Dem_DTCFilter.ReadIndex) == (boolean)FALSE)
			&& ((boolean)TRUE == Dem_FilterDtcCheck(Dem_DTCFilter.ReadIndex)))
		{
			*pDTC = Dem_ConfigPtr->DemDTC[Dem_DTCFilter.ReadIndex].DemDtcValue;
			*pDTCStatus = (Dem_DtcUdsStatus[Dem_DTCFilter.ReadIndex] & DEM_DTCSTATUS_AVAILABILITY_MASK);
			Dem_DTCFilter.ReadIndex++;
			ret = DEM_FILTERED_OK;
			break;
		}
		Dem_DTCFilter.ReadIndex++;
	}while(Dem_DTCFilter.ReadIndex < DEM_DTC_NUM);

	if(ret == DEM_FILTERED_NO_MATCHING_ELEMENT)
	{
		Dem_DTCFilter.ReadIndex = 0u;
	}

	return ret;
}

#if(DEM_RESSET_CONFIRMEDBIT_ONOVERFLOW == STD_ON)
STATIC FUNC(Dem_ReturnGetNextFilteredElementType, DEM_CODE)Dem_ReportDtcByTimeOrder
(
	P2VAR(uint32, AUTOMATIC, DEM_CODE) pDTC,
	P2VAR(Dem_UdsStatusByteType, AUTOMATIC, DEM_CODE) pDTCStatus
)
{
	Dem_ReturnGetNextFilteredElementType ret = DEM_FILTERED_NO_MATCHING_ELEMENT;
	uint8 u8Loop;
	uint8 u8EntryNum = 0u;
	uint16 u16DtcRef;
	Dem_MemoryEntryType* pEntry;

	if(Dem_DTCFilter.AbsTime > 0u)
	{
		pEntry = Dem_GetMemoryConf(Dem_DTCFilter.DTCOrigin,&u8EntryNum);
		if(pEntry != NULL_PTR)
		{
			for(u8Loop = 0u; u8Loop < u8EntryNum; u8Loop++)
			{
				if((pEntry[u8Loop].EventId != 0u) && (pEntry[u8Loop].AbsTime == Dem_DTCFilter.AbsTime))
				{
					Dem_DTCFilter.AbsTime--;

					u16DtcRef = Dem_ConfigPtr->DemEventParameter[pEntry[u8Loop].EventId-1u].DemDTCRef;

					if((Dem_ISEnable_DTCSuppress(u16DtcRef) == (boolean)FALSE)
						&& ((boolean)TRUE == Dem_FilterDtcCheck(u16DtcRef))
						&& (0u == DEM_U8BIT_ISENABLE(Dem_DTCFilter.DTCFilterRecord,u16DtcRef)))
					{
						*pDTC = Dem_ConfigPtr->DemDTC[u16DtcRef].DemDtcValue;
						*pDTCStatus = (Dem_DtcUdsStatus[u16DtcRef] & DEM_DTCSTATUS_AVAILABILITY_MASK);

						DEM_U8BIT_ENABLE(Dem_DTCFilter.DTCFilterRecord,u16DtcRef);
						ret = DEM_FILTERED_OK;
						break;
					}
				}
			}
		}
	}

	if((Dem_DTCFilter.AbsTime == 0u) && (ret == DEM_FILTERED_NO_MATCHING_ELEMENT))
	{
		while(Dem_DTCFilter.ReadIndex < DEM_DTC_NUM)
		{
			if(((boolean)FALSE == Dem_ISEnable_DTCSuppress(Dem_DTCFilter.ReadIndex))
				&& ((boolean)TRUE == Dem_FilterDtcCheck(Dem_DTCFilter.ReadIndex))
				&& (0u == DEM_U8BIT_ISENABLE(Dem_DTCFilter.DTCFilterRecord,Dem_DTCFilter.ReadIndex)))
			{
				*pDTC = Dem_ConfigPtr->DemDTC[Dem_DTCFilter.ReadIndex].DemDtcValue;
				*pDTCStatus = (Dem_DtcUdsStatus[Dem_DTCFilter.ReadIndex] & DEM_DTCSTATUS_AVAILABILITY_MASK);

				DEM_U8BIT_ENABLE(Dem_DTCFilter.DTCFilterRecord,Dem_DTCFilter.ReadIndex);
				Dem_DTCFilter.ReadIndex++;
				ret = DEM_FILTERED_OK;
				break;
			}
			Dem_DTCFilter.ReadIndex++;
		}
	}

	if(ret == DEM_FILTERED_NO_MATCHING_ELEMENT)
	{
		Dem_DTCFilter.ReadIndex = 0u;
		Dem_DTCFilter.TimeOrder = (boolean)FALSE;
		Dem_DTCFilter.AbsTime = 0u;
		DEM_VALUE_SET(Dem_DTCFilter.DTCFilterRecord,0u,DEM_DTC_NUM_BYTE);
	}

	return ret;
}
#endif /* #if(DEM_RESSET_CONFIRMEDBIT_ONOVERFLOW == STD_ON) */
#endif /* #if(DEM_DTC_NUM > 0) */


#if((DEM_FREEZE_FRAME_CLASS_NUM > 0) && (DEM_MAX_NUMBER_FF_RECORDS > 0))
STATIC FUNC(Dem_ReturnGetFreezeFrameDataByDTCType, DEM_CODE)Dem_DcmGetFreezeFrameDataByDTCSubDeal
(
	uint16 DTCIndex,
	Dem_DTCOriginType DTCOrigin,
	uint8 RecordNumber,
	P2VAR(uint8, AUTOMATIC, DEM_CODE) pDestBuffer,
	P2VAR(uint16, AUTOMATIC, DEM_CODE) pBufSize
)
{
	Dem_ReturnGetFreezeFrameDataByDTCType ret = DEM_GET_FFDATABYDTC_OK;
	uint8 u8iLoop;
	uint8 u8jLoop;
	uint8 u8Flag = 0u;
	Dem_MemoryEntryType* pEntry = Dem_GetMemoryConf(DTCOrigin,&u8Flag);
	uint8* pFFData = NULL_PTR;
	const Dem_DidClassType* pDidClass;
	const Dem_FreezeFrameClassType* pFFClass = &Dem_General.DemFreezeFrameClass[Dem_ConfigPtr->\
												DemDTCAttributes[Dem_ConfigPtr->DemDTC[DTCIndex].\
												DemDTCAttributesRef].DemFreezeFrameClassRef];
	const Dem_DataElementClassType* pDataElemClass;

	if(pEntry != NULL_PTR)
	{
		for(u8iLoop = 0u; u8iLoop < u8Flag; u8iLoop++)
		{
			if((pEntry->EventId != 0u) && (Dem_ConfigPtr->\
					DemEventParameter[pEntry->EventId-1u].DemDTCRef == DTCIndex))
			{
				for(u8jLoop = 0u; u8jLoop < DEM_MAX_NUMBER_FF_RECORDS; u8jLoop++)
				{
					if(pEntry->FFInfo[u8jLoop].RecNum == RecordNumber)
					{
						pFFData = pEntry->FFInfo[u8jLoop].FFData;
						break;
					}
				}
				break;
			}
			pEntry++;
		}
	}

	if(pFFData != NULL_PTR)
	{
		/* RecordNum(1 byte) + Num of DIDs(1 byte) + 1st DID(2 byte) + Data #1(x byte) + ... */
		if((*pBufSize) >= (uint16)(2u + (2u * (uint16)pFFClass->DemDidClassRefNum) + pFFClass->DemRefDidDataSize))
		{
			*pBufSize = (uint16)(2u + (2u * (uint16)pFFClass->DemDidClassRefNum) + pFFClass->DemRefDidDataSize);

			*pDestBuffer = RecordNumber;
			pDestBuffer++;

			*pDestBuffer = pFFClass->DemDidClassRefNum;
			pDestBuffer++;

			for(u8iLoop = 0u; u8iLoop < pFFClass->DemDidClassRefNum; u8iLoop++)
			{
				pDidClass = &Dem_General.DemDidClass[pFFClass->DemDidClassRefStartIndex[u8iLoop]];

				*pDestBuffer = (uint8)(pDidClass->DemDidIdentifier >> 8u);
				pDestBuffer++;
				*pDestBuffer = (uint8)(pDidClass->DemDidIdentifier);
				pDestBuffer++;

				for(u8jLoop = 0u; u8jLoop < pDidClass->DemDidDataElementClassRefNum; u8jLoop++)
				{
					pDataElemClass = &Dem_General.DemDataElementClass[pDidClass->\
										DemDidDataElementClassRefStartIndex[u8jLoop]];

#if(DEM_EXTERNALCSDATA_ELEMENT_NUM > 0)
					if(pDataElemClass->DemExternalCSDataElementClass != NULL_PTR)
					{
						u8Flag = pDataElemClass->DemExternalCSDataElementClass->DemDataElementDataSize;
						DEM_VALUE_COPY(pDestBuffer, pFFData, u8Flag);
						pDestBuffer += u8Flag;
						pFFData += u8Flag;
					}
#endif /* #if(DEM_EXTERNALCSDATA_ELEMENT_NUM > 0) */
#if(DEM_INTERNAL_DATA_ELEMENT_NUM > 0)
					if(pDataElemClass->DemInternalDataElementClass != NULL_PTR)
					{
						u8Flag = pDataElemClass->DemInternalDataElementClass->DemDataElementDataSize;
						Dem_CaptureInternalDataElement(\
								(pEntry->EventId - 1u),\
								pDestBuffer,\
								pDataElemClass->DemInternalDataElementClass);
						pDestBuffer += u8Flag;
						pFFData += u8Flag;
					}
#endif /* #if(DEM_INTERNAL_DATA_ELEMENT_NUM > 0) */
#if(DEM_EXTERNALSRDATA_ELEMENT_NUM > 0)
					if(0){/* SRData */}
#endif /* #if(DEM_EXTERNALSRDATA_ELEMENT_NUM > 0) */
				}
			}
		}
		else
		{
			ret = DEM_GET_FFDATABYDTC_WRONG_BUFFERSIZE;
		}
	}
	else
	{	/* @req [SWS_Dem_00630] */
		*pBufSize = 0u;
	}
	return ret;
}

STATIC FUNC(void, DEM_CODE)Dem_GetSizeOfFFByDTCSubDeal
(
	uint8 RecordNumber,
	uint16 DtcRef,
	Dem_DTCOriginType DTCOrigin,
	P2VAR(uint16,AUTOMATIC,DEM_CODE) pSizeOfFreezeFrame
)
{
	uint8 u8Loop;
	uint8 u8LoopFF;
	uint8 u8EntryNum = 0u;
	uint16 u16DataSize;
	uint8 u8DidNum;
	Dem_MemoryEntryType* pEntry = Dem_GetMemoryConf(DTCOrigin,&u8EntryNum);
	const Dem_DTCAttributesType* pDTCAttr = &(Dem_ConfigPtr->DemDTCAttributes[Dem_ConfigPtr->\
														   DemDTC[DtcRef].DemDTCAttributesRef]);
	*pSizeOfFreezeFrame = 0u;

	if(pEntry != NULL_PTR)
	{
		for(u8Loop = 0u; u8Loop < u8EntryNum; u8Loop++)
		{
			if(Dem_ConfigPtr->DemEventParameter[pEntry[u8Loop].EventId-1u].DemDTCRef == DtcRef)
			{
				for(u8LoopFF = 0u; u8LoopFF < DEM_MAX_NUMBER_FF_RECORDS; u8LoopFF++)
				{
					if(RecordNumber == 0xFFu)
					{
						if(pEntry[u8Loop].FFInfo[u8LoopFF].RecNum != 0xFFu)
						{
							u16DataSize = Dem_General.DemFreezeFrameClass[pDTCAttr->\
											DemFreezeFrameClassRef].DemRefDidDataSize;

							u8DidNum = Dem_General.DemFreezeFrameClass[pDTCAttr->\
											DemFreezeFrameClassRef].DemDidClassRefNum;

							*pSizeOfFreezeFrame += (uint16)(2u + (uint16)(u8DidNum * (uint16)2) + u16DataSize);
						}
					}
					else
					{
						if(pEntry[u8Loop].FFInfo[u8LoopFF].RecNum == RecordNumber)
						{
							u16DataSize = Dem_General.DemFreezeFrameClass[pDTCAttr->\
											DemFreezeFrameClassRef].DemRefDidDataSize;

							u8DidNum = Dem_General.DemFreezeFrameClass[pDTCAttr->\
											DemFreezeFrameClassRef].DemDidClassRefNum;

							*pSizeOfFreezeFrame += (uint16)(2u + (uint16)(u8DidNum * (uint16)2) + u16DataSize);

							break;
						}
					}
				}
				break;
			}
		}
	}
}
#endif /* #if((DEM_FREEZE_FRAME_CLASS_NUM > 0) && (DEM_MAX_NUMBER_FF_RECORDS > 0)) */

#if(DEM_EXTENDED_DATA_CLASS_NUM > 0)
STATIC FUNC(Dem_ReturnGetExtendedDataRecordByDTCType, DEM_CODE)Dem_DcmGetExtendedDataRecordByDTCSubDeal
(
	uint16 DTCIndex,
	Dem_DTCOriginType DTCOrigin,
	uint8 ExtendedDataNumber,
	P2VAR(uint8, AUTOMATIC, DEM_CODE) pDestBuffer,
	P2VAR(uint16, AUTOMATIC, DEM_CODE) pBufSize
)
{
	Dem_ReturnGetExtendedDataRecordByDTCType ret = DEM_RECORD_OK;
	uint8 u8Flag;
	Dem_MemoryEntryType* pEntry = Dem_GetMemoryConf(DTCOrigin,&u8Flag);
	uint8 u8Loop;
	uint8 u8LoopExt;
	uint16 u16Ref;
	const Dem_ExtendedDataRecordClassType* pExtDataRecClass = NULL_PTR;
	const Dem_DataElementClassType* pDataElemClass;
	uint8* pExtData = NULL_PTR;

	if(pEntry != NULL_PTR)
	{
		for(u8Loop = 0u; u8Loop < u8Flag; u8Loop++)
		{
			if((pEntry[u8Loop].EventId != 0u) && (Dem_ConfigPtr->\
					DemEventParameter[pEntry[u8Loop].EventId-1u].DemDTCRef == DTCIndex))
			{
				for(u8LoopExt = 0u; u8LoopExt < DEM_MAX_NUMBER_EXT_REC; u8LoopExt++)
				{
					if(pEntry[u8Loop].ExtInfo[u8LoopExt].RecNum == ExtendedDataNumber)
					{
						u16Ref = Dem_ConfigPtr->DemEventParameter[pEntry->EventId-1u].DemDTCRef;
						u16Ref = Dem_ConfigPtr->DemDTC[u16Ref].DemDTCAttributesRef;
						u16Ref = Dem_ConfigPtr->DemDTCAttributes[u16Ref].DemExtendedDataClassRef;
						pExtDataRecClass = &Dem_General.DemExtendedDataRecordClass[Dem_General.\
											DemExtendedDataClass[u16Ref].\
											DemExtendedDataRecordClassRefStartIndex[u8LoopExt]];

						if(*pBufSize >= pExtDataRecClass->DemDataElementClassRefDataSize)
						{
							pExtData = pEntry->ExtInfo[u8LoopExt].ExtData;

							*pBufSize = pExtDataRecClass->DemDataElementClassRefDataSize;
						}
						else
						{
							ret = DEM_RECORD_WRONG_BUFFERSIZE;
						}
						break;
					}
				}
				break;
			}
		}
	}

	if(pExtData != NULL_PTR)
	{
		for(u8Loop = 0u; u8Loop < pExtDataRecClass->DemDataElementClassRefNum; u8Loop++)
		{
			pDataElemClass = &Dem_General.DemDataElementClass[pExtDataRecClass->\
								DemDataElementClassRefStartIndex[u8Loop]];

#if(DEM_EXTERNALCSDATA_ELEMENT_NUM > 0)
			if(pDataElemClass->DemExternalCSDataElementClass != NULL_PTR)
			{
				u8Flag = pDataElemClass->DemExternalCSDataElementClass->DemDataElementDataSize;
				DEM_VALUE_COPY(pDestBuffer, pExtData, u8Flag);
				pDestBuffer += u8Flag;
				pExtData += u8Flag;
			}
#endif /* #if(DEM_EXTERNALCSDATA_ELEMENT_NUM > 0) */
#if(DEM_INTERNAL_DATA_ELEMENT_NUM > 0)
			if(pDataElemClass->DemInternalDataElementClass != NULL_PTR)
			{
				u8Flag = pDataElemClass->DemInternalDataElementClass->DemDataElementDataSize;
				Dem_CaptureInternalDataElement(\
						(pEntry->EventId - 1u),\
						pDestBuffer,\
						pDataElemClass->DemInternalDataElementClass);
				pDestBuffer += u8Flag;
				pExtData += u8Flag;
			}
#endif /* #if(DEM_INTERNAL_DATA_ELEMENT_NUM > 0) */
#if(DEM_EXTERNALSRDATA_ELEMENT_NUM > 0)
			if(0){/* SRData */}
#endif /* #if(DEM_EXTERNALSRDATA_ELEMENT_NUM > 0) */
		}
	}
	else
	{	/* @req [SWS_Dem_00631] */
		*pBufSize = 0u;
	}

	return ret;
}

STATIC FUNC(void, DEM_CODE)Dem_DcmGetSizeOfExtendedDataRecordSubDeal
(
	uint16 DtcRef,
	Dem_DTCOriginType DTCOrigin,
	uint8 ExtendedDataNumber,
	P2VAR(uint16, AUTOMATIC, DEM_CODE) pSizeOfExtendedDataRecord
)
{
	uint8 u8Loop;
	uint8 u8LoopExt;
	uint8 u8EntryNum = 0u;
	Dem_MemoryEntryType* pEntry = Dem_GetMemoryConf(DTCOrigin,&u8EntryNum);
	const Dem_DTCAttributesType* pDTCAttr = \
			&Dem_ConfigPtr->DemDTCAttributes[Dem_ConfigPtr->DemDTC[DtcRef].DemDTCAttributesRef];
	const Dem_ExtendedDataClassType* pExtDataClass;
	const Dem_ExtendedDataRecordClassType* pExtDataRecClass;

	*pSizeOfExtendedDataRecord = 0u;

	if((pEntry != NULL_PTR) && (pDTCAttr->DemExtendedDataClassRef != 0xFFFFu))
	{
		for(u8Loop = 0u; u8Loop < u8EntryNum; u8Loop++)
		{
			if(Dem_ConfigPtr->DemEventParameter[pEntry[u8Loop].EventId-1u].DemDTCRef == DtcRef)
			{
				pExtDataClass = &Dem_General.DemExtendedDataClass[pDTCAttr->DemExtendedDataClassRef];

				for(u8LoopExt = 0u;
					u8LoopExt < pExtDataClass->DemExtendedDataRecordClassRefNum;
					u8LoopExt++)
				{
					pExtDataRecClass = &Dem_General.DemExtendedDataRecordClass[pExtDataClass->\
										DemExtendedDataRecordClassRefStartIndex[u8LoopExt]];
					if(ExtendedDataNumber == 0xFFu)
					{
						/* If the record number value 0xFF is requested, the Dem considers the size
						 * of all stored extended data records (in the range of 0x01 to 0xEF) */
						if(pEntry[u8Loop].ExtInfo[u8LoopExt].RecNum != 0xFFu)
						{
							*pSizeOfExtendedDataRecord += pExtDataRecClass->DemDataElementClassRefDataSize;
						}
					}
#if(DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT)
					else if(ExtendedDataNumber == 0xFEu)
					{
						/* If the record number value 0xFE is requested, the Dem considers the size
						 * of all OBD stored extended data records in the range of 0x90 to 0xEF */
						if(pEntry[u8Loop].ExtInfo[u8LoopExt].RecNum >= 0x90u)
						{
							*pSizeOfExtendedDataRecord += pExtDataRecClass->DemDataElementClassRefDataSize;
						}
					}
#endif /* #if(DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT) */
					else /* find single ExtendedData */
					{
						if(pEntry[u8Loop].ExtInfo[u8LoopExt].RecNum == ExtendedDataNumber)
						{
							*pSizeOfExtendedDataRecord += pExtDataRecClass->DemDataElementClassRefDataSize;
							break;
						}
					}
				}
				break;
			}
		}
	}
}
#endif /* #if(DEM_EXTENDED_DATA_CLASS_NUM > 0) */

#if(DEM_GROUP_OF_DTC_NUM > 0)
STATIC FUNC(uint8, DEM_CODE) Dem_GetDTCGroupIndex
(
	uint32 DTCGroup
)
{
    uint8 u8Loop = 0u;

    do
    {
    	if (Dem_General.DemGroupOfDTC[u8Loop] == DTCGroup)
		{
			break;
		}
    	u8Loop++;
    }while(u8Loop < DEM_GROUP_OF_DTC_NUM);

    return u8Loop;
}
#endif /* #if(DEM_GROUP_OF_DTC_NUM > 0) */

#if(DEM_DTC_NUM > 0)

STATIC FUNC(Dem_ReturnClearDTCType, DEM_CODE) Dem_ClearDTCAll
(
	void
)
{
	uint16 u16Loop = 0u;
	Dem_MemoryInfoType* pMemInfo = Dem_GetMemInfoByOrigin(Dem_ClearDtcInfo.DTCOrigin);

	do
	{
		if(Dem_ConfigPtr->DemEventParameter[u16Loop].DemDTCRef != 0xFFFFu)
		{
			(void)Dem_ClearDtcDeal(Dem_ClearDtcInfo.DTCOrigin,u16Loop);
		}
		u16Loop++;
	}while(u16Loop < DEM_EVENT_PARAMETER_NUM);

	/**
	 * @req [SWS_Dem_00399] The event memory overflow indication of the respective event memory
	 *      shall be reset, if all DTCs of this memory are deleted by Dem_<...>ClearDTC.
	 */
	if((pMemInfo != NULL_PTR) && (pMemInfo->EntryNum == 0u))
	{
		pMemInfo->OverFlow = (boolean)FALSE;
	}
	return (Dem_ReturnClearDTCType)DEM_CLEAR_OK;
}

#if(DEM_CLEARDTC_LIMITATION == DEM_ALL_SUPPORTED_DTCS)
STATIC FUNC(Dem_ReturnClearDTCType, DEM_CODE) Dem_ClearDTCSingle
(
	uint16 DtcIndex
)
{
	Dem_ReturnClearDTCType ret = (Dem_ReturnClearDTCType)DEM_CLEAR_FAILED;
	uint16 u16Loop = 0u;
	Dem_MemoryInfoType* pMemInfo = Dem_GetMemInfoByOrigin(Dem_ClearDtcInfo.DTCOrigin);

	do
	{
		if(Dem_ConfigPtr->DemEventParameter[u16Loop].DemDTCRef == DtcIndex)
		{
			ret = Dem_ClearDtcDeal(Dem_ClearDtcInfo.DTCOrigin,u16Loop);
		}
		u16Loop++;
	}while(u16Loop < DEM_EVENT_PARAMETER_NUM);

	/**
	 * @req [SWS_Dem_00399] The event memory overflow indication of the respective event memory
	 *      shall be reset, if all DTCs of this memory are deleted by Dem_<...>ClearDTC.
	 */
	if((pMemInfo != NULL_PTR) && (pMemInfo->EntryNum == 0u))
	{
		pMemInfo->OverFlow = (boolean)FALSE;
	}
	return ret;
}
#endif /* #if(DEM_CLEARDTC_LIMITATION == DEM_ALL_SUPPORTED_DTCS) */
#endif /* #if(DEM_DTC_NUM > 0) */

#if(DEM_CLEARDTC_LIMITATION == DEM_ALL_SUPPORTED_DTCS)
#if(DEM_GROUP_OF_DTC_NUM > 0u)
STATIC FUNC(Dem_ReturnClearDTCType, DEM_CODE) Dem_ClearDTCGroup
(
	uint8 GroupIndex
)
{
	uint16 u16Loop = 0u;
	uint16 u16DtcRef;
	Dem_MemoryInfoType* pMemInfo = Dem_GetMemInfoByOrigin(Dem_ClearDtcInfo.DTCOrigin);

	do
	{
		u16DtcRef = Dem_ConfigPtr->DemEventParameter[u16Loop].DemDTCRef;

		if((u16DtcRef != 0xFFFFu) && (Dem_ConfigPtr->DemDTC[u16DtcRef].DemDtcGroupRef == GroupIndex))
		{
			Dem_ClearDtcDeal(Dem_ClearDtcInfo.DTCOrigin,u16Loop);
		}
		u16Loop++;
	}while(u16Loop < DEM_EVENT_PARAMETER_NUM);

	/**
	 * @req [SWS_Dem_00399] The event memory overflow indication of the respective event memory
	 *      shall be reset, if all DTCs of this memory are deleted by Dem_<...>ClearDTC.
	 */
	if((pMemInfo != NULL_PTR) && (pMemInfo->EntryNum == 0u))
	{
		pMemInfo->OverFlow = (boolean)TRUE;
	}
	return (Dem_ReturnClearDTCType)DEM_CLEAR_OK;
}
#endif /* #if(DEM_GROUP_OF_DTC_NUM > 0u) */
#endif /* #if(DEM_CLEARDTC_LIMITATION == DEM_ALL_SUPPORTED_DTCS) */

#if(DEM_FREEZE_FRAME_CLASS_NUM > 0)
STATIC FUNC(boolean, DEM_CODE) Dem_FFRecNumCheck
(
	uint16 DTCIndex,
	uint8 RecordNumber
)
{
	boolean ret = (boolean)FALSE;
	const Dem_DTCAttributesType* pDtcAttr = &Dem_ConfigPtr->\
			DemDTCAttributes[Dem_ConfigPtr->DemDTC[DTCIndex].DemDTCAttributesRef];

#if(DEM_TYPEOFFF_RECORD_NUMERATION == DEM_FF_RECNUM_CONFIGURED)
#if(DEM_FREEZE_FRAME_REC_NUM_CLASS_NUM > 0)
	uint8 u8Loop;
	uint8 u8FFRecordClassRef;
	const Dem_FreezeFrameRecNumClassType* pFFRecNumClass;
#endif /* #if(DEM_FREEZE_FRAME_REC_NUM_CLASS_NUM > 0) */
#endif /* #if(DEM_TYPEOFFF_RECORD_NUMERATION == DEM_FF_RECNUM_CONFIGURED) */

	if(pDtcAttr->DemFreezeFrameClassRef != 0xFFFFu)
	{
#if(DEM_TYPEOFFF_RECORD_NUMERATION == DEM_FF_RECNUM_CONFIGURED)
#if(DEM_FREEZE_FRAME_REC_NUM_CLASS_NUM > 0)
		if(pDtcAttr->DemFreezeFrameRecNumClassRef != 0xFFu)
		{
			pFFRecNumClass = &Dem_General.DemFreezeFrameRecNumClass[pDtcAttr->\
																	DemFreezeFrameRecNumClassRef];

			for(u8Loop = 0u; u8Loop < pFFRecNumClass->DemFreezeFrameRecordClassRefNum; u8Loop++)
			{
				u8FFRecordClassRef = pFFRecNumClass->DemFreezeFrameRecordClassRefStartIndex[u8Loop];
				if(Dem_General.DemFreezeFrameRecordClass[u8FFRecordClassRef].\
						DemFreezeFrameRecordNumber == RecordNumber)
				{
					ret = (boolean)TRUE;
					break;
				}
			}
		}
#endif /* #if(DEM_FREEZE_FRAME_REC_NUM_CLASS_NUM > 0) */
#else /* (DEM_TYPEOFFF_RECORD_NUMERATION == DEM_FF_RECNUM_CALCULATED) */
		if(pDtcAttr->DemMaxNumberFreezeFrameRecords >= RecordNumber)
		{
			ret = (boolean)TRUE;
		}
#endif /* #if(DEM_TYPEOFFF_RECORD_NUMERATION == DEM_FF_RECNUM_CONFIGURED) */
	}
	return ret;
}
#endif /* #if(DEM_FREEZE_FRAME_CLASS_NUM > 0) */

#if(DEM_EXTENDED_DATA_CLASS_NUM > 0)
STATIC FUNC(boolean, DEM_CODE) Dem_ExtRecNumCheck
(
	uint16 DTCIndex,
	uint8 RecordNumber
)
{
	boolean ret = (boolean)FALSE;
	uint8 u8Loop;
	uint8 u8ExtDataRecClassRef;
	const Dem_DTCAttributesType* pDtcAttr = &Dem_ConfigPtr->\
			DemDTCAttributes[Dem_ConfigPtr->DemDTC[DTCIndex].DemDTCAttributesRef];
	const Dem_ExtendedDataClassType* pExtDataClass;

	if(pDtcAttr->DemExtendedDataClassRef != 0xFFFFu)
	{
		pExtDataClass = &Dem_General.DemExtendedDataClass[pDtcAttr->DemExtendedDataClassRef];

		for(u8Loop = 0u; u8Loop < pExtDataClass->DemExtendedDataRecordClassRefNum; u8Loop++)
		{
			u8ExtDataRecClassRef = pExtDataClass->DemExtendedDataRecordClassRefStartIndex[u8Loop];
			if(Dem_General.DemExtendedDataRecordClass[u8ExtDataRecClassRef].\
					DemExtendedDataRecordNumber == RecordNumber)
			{
				ret = (boolean)TRUE;
				break;
			}
		}
	}
	return ret;
}
#endif /* #if(DEM_EXTENDED_DATA_CLASS_NUM > 0) */
/*====================================================================================================*
 *                                          GLOBAL FUNCTIONS
 *====================================================================================================*/
/**
 * @sid         	0x3c
 * @brief       	Dem_DcmGetTranslationType
 * @details     	Gets the supported DTC formats of the ECU. The supported formats are configured
 *                  via DemTypeOfDTCSupported.
 *
 * @return     	 	The supported formats are configured via DemTypeOfDTCSupported.
 * @retval      	DEM_DTC_TRANSLATION_ISO15031_6               0x00
 * @retval      	DEM_DTC_TRANSLATION_ISO14229_1               0x01
 * @retval			DEM_DTC_TRANSLATION_SAEJ1939_73              0x02
 * @retval			DEM_DTC_TRANSLATION_ISO11992_4               0x03
 * @retval			DEM_DTC_TRANSLATION_J2012DA_FORMAT_04        0x04
 */
FUNC(Dem_DTCTranslationFormatType, DEM_CODE)Dem_DcmGetTranslationType
(
	void
)
{
	/**
	 * @req [SWS_Dem_00231] The function Dem_DcmGetTranslationType shall provide
	 *      the capability to get the configured translation format of the ECU.
	 */
	Dem_DTCTranslationFormatType ret = 0xFFu;
#if (STD_ON == DEM_DEV_ERROR_DETECT)
	if (Dem_InitState != DEM_STATE_INIT)
	{
		/**
		 * @req [SWS_Dem_00124] If development error detection is enabled and any instance calls
		 *      any Dem API, excluding Dem_ReportErrorStatus, Dem_ResetEventDebounceStatus and
		 *      Dem_GetVersionInfo, before the Dem was fully initialized, the Dem module shall set
		 *      the error code DEM_E_UNINIT.
		 *
		 * @req [SWS_Dem_00368] If development error detection is enabled and any instance calls
		 *      any Dem API, excluding Dem_ReportErrorStatus, Dem_ResetEventDebounceStatus and
		 *      Dem_GetVersionInfo, after Dem_Shutdown (refer to chapter 8.3.2.3) has been called,
		 *      the Dem module shall set the error code DEM_E_UNINIT until Dem_Init is called again.
		 */
    	DEM_DET_ERROR_REPORT(DEM_SID_DCMGETTRANSLATIONTYPE,DEM_E_UNINIT);
    }
    else
#endif /* #if (STD_ON == DEM_DEV_ERROR_DETECT) */
    {
    	ret = DEM_TYPEOFDTC_SUPPORTED;
    }
    return ret;
}

/**
 * @sid         	0x16
 * @brief       	Dem_DcmGetDTCStatusAvailabilityMask
 * @details     	Gets the DTC Status availability mask.
 *
 * @param[out]		pDTCStatusMask: The value DTCStatusMask indicates the supported DTC status bits
 *                  from the Dem.
 *
 * @return      	Result of getting operation.
 * @retval      	E_OK: get of DTC status mask was successful.
 * @retval      	E_NOT_OK: get of DTC status mask failed.
 */
FUNC(Std_ReturnType, DEM_CODE)Dem_DcmGetDTCStatusAvailabilityMask
(
	P2VAR(Dem_UdsStatusByteType, AUTOMATIC, DEM_CODE) pDTCStatusMask
)
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;
	if (Dem_InitState != DEM_STATE_INIT)
	{
#if (STD_ON == DEM_DEV_ERROR_DETECT)
		/**
		 * @req [SWS_Dem_00124] If development error detection is enabled and any instance calls
		 *      any Dem API, excluding Dem_ReportErrorStatus, Dem_ResetEventDebounceStatus and
		 *      Dem_GetVersionInfo, before the Dem was fully initialized, the Dem module shall set
		 *      the error code DEM_E_UNINIT.
		 *
		 * @req [SWS_Dem_00368] If development error detection is enabled and any instance calls
		 *      any Dem API, excluding Dem_ReportErrorStatus, Dem_ResetEventDebounceStatus and
		 *      Dem_GetVersionInfo, after Dem_Shutdown (refer to chapter 8.3.2.3) has been called,
		 *      the Dem module shall set the error code DEM_E_UNINIT until Dem_Init is called again.
		 */
    	DEM_DET_ERROR_REPORT(DEM_SID_DCMGETDTCSTATUSAVAILABILITYMASK,DEM_E_UNINIT);
#endif /* #if (STD_ON == DEM_DEV_ERROR_DETECT) */
    }
    else if (pDTCStatusMask == NULL_PTR)
    {
#if (STD_ON == DEM_DEV_ERROR_DETECT)
    	DEM_DET_ERROR_REPORT(DEM_SID_DCMGETDTCSTATUSAVAILABILITYMASK,DEM_E_PARAM_POINTER);
#endif /* #if (STD_ON == DEM_DEV_ERROR_DETECT) */
    }
    else
    {
    	*pDTCStatusMask = DEM_DTCSTATUS_AVAILABILITY_MASK;
    	ret = (Std_ReturnType)E_OK;
    }

    return ret;
}

/**
 * @sid				0xb2
 * @brief			Dem_DcmGetDTCSeverityAvailabilityMask
 * @details			Gets the DTC Severity availability mask.
 *
 * @param[out]		DTCSeverityMask: The value DTCSeverityMask indicates the supported DTC
 * 					severity bits from the Dem. All supported information is indicated by
 * 					setting the corresponding status bit to 1. See ISO14229-1.
 */
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetDTCSeverityAvailabilityMask
(
    P2VAR(Dem_DTCSeverityType, AUTOMATIC, DEM_CODE) DTCSeverityMask
)
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;

	DEM_DETCHECK_API_DCMGETDTCSEVERITYAVAILABILITYMASK(Dem_InitState,DTCSeverityMask,&ret);
	if(ret == 1u)
	{
#if(DEM_DTC_NUM > 0)
		*DTCSeverityMask = Dem_DTCFilter.DTCSeverityMask;
		ret = (Std_ReturnType)E_OK;
#endif /* #if(DEM_DTC_NUM > 0) */
	}
	return ret;
}

/**
 * @sid         	0x15
 * @brief      		Dem_DcmGetStatusOfDTC
 * @details     	Gets the DTC Status availability mask.
 *
 * @param[in]   	DTC:Diagnostic Trouble Code in UDS format.
 * @param[in]		DTCOrigin: If the Dem supports more than one event memory this parameter is used
 *                  to select the source memory the DTCs shall be read from.
 *
 * @param[out]		pDTCStatus: This parameter receives the status information of the requested DTC.If
 *                  the return value of the function is other than DEM_STATUS_OK this parameter does
 *                  not contain valid data.0x00...0xFF match DTCStatusMask as defined in ISO14229-1.
 *
 * @return      	Result of getting operation.
 * @retval      	E_OK: get of DTC status mask was successful.
 * @retval      	E_NOT_OK: get of DTC status mask failed.
 */
FUNC(Dem_ReturnGetStatusOfDTCType, DEM_CODE) Dem_DcmGetStatusOfDTC
(
    uint32 DTC,
    Dem_DTCOriginType DTCOrigin,
    P2VAR(uint8, AUTOMATIC, DEM_CODE) pDTCStatus
)
{
    Dem_ReturnGetStatusOfDTCType ret = DEM_STATUS_FAILED;
#if(DEM_DTC_NUM > 0)
	uint16 u16DtcIndex;

    if (Dem_InitState != DEM_STATE_INIT)
	{
#if(STD_ON == DEM_DEV_ERROR_DETECT)
		/**
		 * @req [SWS_Dem_00124] If development error detection is enabled and any instance calls
		 *      any Dem API, excluding Dem_ReportErrorStatus, Dem_ResetEventDebounceStatus and
		 *      Dem_GetVersionInfo, before the Dem was fully initialized, the Dem module shall set
		 *      the error code DEM_E_UNINIT.
		 *
		 * @req [SWS_Dem_00368] If development error detection is enabled and any instance calls
		 *      any Dem API, excluding Dem_ReportErrorStatus, Dem_ResetEventDebounceStatus and
		 *      Dem_GetVersionInfo, after Dem_Shutdown (refer to chapter 8.3.2.3) has been called,
		 *      the Dem module shall set the error code DEM_E_UNINIT until Dem_Init is called again.
		 */
    	DEM_DET_ERROR_REPORT(DEM_SID_DCMGETSTATUSOFDTC,DEM_E_UNINIT);
#endif /* #if (STD_ON == DEM_DEV_ERROR_DETECT) */
    }
    else if(pDTCStatus == NULL_PTR)
    {
#if(STD_ON == DEM_DEV_ERROR_DETECT)
    	DEM_DET_ERROR_REPORT(DEM_SID_DCMGETSTATUSOFDTC,DEM_E_PARAM_POINTER);
#endif /* #if (STD_ON == DEM_DEV_ERROR_DETECT) */
    }
    else
    {
    	u16DtcIndex = Dem_GetDtcIndexByDtc(DTC,DEM_DTC_FORMAT_UDS);

		/**
		 * @req [SWS_Dem_01100] A suppressed DTC shall not be visible for Dem_DcmGetStatusOfDTC
		 */
    	if((u16DtcIndex == 0xFFFFu) || (Dem_ISEnable_DTCSuppress(u16DtcIndex) == (boolean)TRUE))
    	{
    		ret = DEM_STATUS_WRONG_DTC;
    	}
    	else
    	{
			if(NULL_PTR == Dem_GetMemInfoByOrigin(DTCOrigin))
			{
				ret = DEM_STATUS_WRONG_DTCORIGIN;
			}
			else
			{
				*pDTCStatus = (Dem_DtcUdsStatus[u16DtcIndex] & DEM_DTCSTATUS_AVAILABILITY_MASK);
				ret = DEM_STATUS_OK;
			}
		}
    }
#endif /* #if(DEM_DTC_NUM > 0) */
    return ret;
}

/**
 * @sid         	0x0e
 * @brief      		Dem_DcmGetSeverityOfDTC
 * @details     	Gets the severity of the requested DTC.
 *
 * @param[in]   	DTC:Diagnostic Trouble Code in UDS format.
 *
 * @param[out]		pDTCSeverity: This parameter contains the DTCSeverity according to ISO 14229-1.
 *
 * @return      	Result of getting operation.
 * @retval      	DEM_GET_SEVERITYOFDTC_OK      				0x00
 * @retval      	DEM_GET_SEVERITYOFDTC_WRONG_DTC             0x01
 * @retval			DEM_GET_SEVERITYOFDTC_NOSEVERITY            0x02
 * @retval			DEM_GET_SEVERITYOFDTC_PENDING               0x03
 */
FUNC(Dem_ReturnGetSeverityOfDTCType, DEM_CODE) Dem_DcmGetSeverityOfDTC
(
    uint32 DTC,
    P2VAR(Dem_DTCSeverityType, AUTOMATIC, DEM_CODE) pDTCSeverity
)
{
	Dem_ReturnGetSeverityOfDTCType ret = DEM_GET_SEVERITYOFDTC_WRONG_DTC;
#if(DEM_DTC_NUM > 0)
	uint16 u16DtcIndex;

	if (Dem_InitState != DEM_STATE_INIT)
	{
#if (STD_ON == DEM_DEV_ERROR_DETECT)
		/**
		 * @req [SWS_Dem_00124] If development error detection is enabled and any instance calls
		 *      any Dem API, excluding Dem_ReportErrorStatus, Dem_ResetEventDebounceStatus and
		 *      Dem_GetVersionInfo, before the Dem was fully initialized, the Dem module shall set
		 *      the error code DEM_E_UNINIT.
		 *
		 * @req [SWS_Dem_00368] If development error detection is enabled and any instance calls
		 *      any Dem API, excluding Dem_ReportErrorStatus, Dem_ResetEventDebounceStatus and
		 *      Dem_GetVersionInfo, after Dem_Shutdown (refer to chapter 8.3.2.3) has been called,
		 *      the Dem module shall set the error code DEM_E_UNINIT until Dem_Init is called again.
		 */
    	DEM_DET_ERROR_REPORT(DEM_SID_DCMGETSEVERITYOFDTC,DEM_E_UNINIT);
#endif /* #if (STD_ON == DEM_DEV_ERROR_DETECT) */
    }
    else if (pDTCSeverity == NULL_PTR)
    {
#if (STD_ON == DEM_DEV_ERROR_DETECT)
    	DEM_DET_ERROR_REPORT(DEM_SID_DCMGETSEVERITYOFDTC,DEM_E_PARAM_POINTER);
#endif /* #if (STD_ON == DEM_DEV_ERROR_DETECT) */
    }
    else
    {
    	u16DtcIndex = Dem_GetDtcIndexByDtc(DTC,DEM_DTC_FORMAT_UDS);
    	if((u16DtcIndex == 0xFFFFu) || (Dem_ISEnable_DTCSuppress(u16DtcIndex) == (boolean)TRUE))
    	{
    		/**
			 * @req [SWS_Dem_01100] A suppressed DTC shall not be visible for
			 *      Dem_DcmGetSeverityOfDTC,it shall return DEM_GET_SE-VERIT-
			 *      YOFDTC_WRONG_DTC
			 */
    		ret = DEM_GET_SEVERITYOFDTC_WRONG_DTC;
    	}
    	else
    	{
    		*pDTCSeverity = Dem_ConfigPtr->DemDTC[u16DtcIndex].DemDTCSeverity;
    		ret = DEM_GET_SEVERITYOFDTC_OK;
    	}
    }
#endif /* #if(DEM_DTC_NUM > 0) */
    return ret;
}

/**
 * @sid         	0x34
 * @brief      		Dem_DcmGetFunctionalUnitOfDTC
 * @details     	Gets the severity of the requested DTC.
 *
 * @param[in]   	DTC:Diagnostic Trouble Code in UDS format.
 *
 * @param[out]		pDTCFunctionalUnit: Functional unit value of this DTC.
 *
 * @return      	Result of getting operation.
 * @retval      	DEM_GET_FUNCTIONALUNITOFDTC_OK              0x00
 * @retval      	DEM_GET_FUNCTIONALUNITOFDTC_WRONG_DTC       0x01
 */
FUNC(Dem_ReturnGetFunctionalUnitOfDTCType, DEM_CODE) Dem_DcmGetFunctionalUnitOfDTC
(
    uint32 DTC,
    P2VAR(uint8, AUTOMATIC, DEM_CODE) pDTCFunctionalUnit
)
{
	Dem_ReturnGetFunctionalUnitOfDTCType ret = DEM_GET_FUNCTIONALUNITOFDTC_WRONG_DTC;
#if(DEM_DTC_NUM > 0)
	uint16 u16DtcIndex;

	if (Dem_InitState != DEM_STATE_INIT)
	{
#if (STD_ON == DEM_DEV_ERROR_DETECT)
		/**
		 * @req [SWS_Dem_00124] If development error detection is enabled and any instance calls
		 *      any Dem API, excluding Dem_ReportErrorStatus, Dem_ResetEventDebounceStatus and
		 *      Dem_GetVersionInfo, before the Dem was fully initialized, the Dem module shall set
		 *      the error code DEM_E_UNINIT.
		 *
		 * @req [SWS_Dem_00368] If development error detection is enabled and any instance calls
		 *      any Dem API, excluding Dem_ReportErrorStatus, Dem_ResetEventDebounceStatus and
		 *      Dem_GetVersionInfo, after Dem_Shutdown (refer to chapter 8.3.2.3) has been called,
		 *      the Dem module shall set the error code DEM_E_UNINIT until Dem_Init is called again.
		 */
    	DEM_DET_ERROR_REPORT(DEM_SID_DCMGETFUNCTIONALUNITOFDTC,DEM_E_UNINIT);
#endif /* #if (STD_ON == DEM_DEV_ERROR_DETECT) */
    }
    else if (pDTCFunctionalUnit == NULL_PTR)
    {
#if (STD_ON == DEM_DEV_ERROR_DETECT)
    	DEM_DET_ERROR_REPORT(DEM_SID_DCMGETFUNCTIONALUNITOFDTC,DEM_E_PARAM_POINTER);
#endif /* #if (STD_ON == DEM_DEV_ERROR_DETECT) */
    }
    else
    {
    	u16DtcIndex = Dem_GetDtcIndexByDtc(DTC,DEM_DTC_FORMAT_UDS);
		if((u16DtcIndex == 0xFFFFu) || (Dem_ISEnable_DTCSuppress(u16DtcIndex) == (boolean)TRUE))
		{
			/**
			 * @req [SWS_Dem_01100] A suppressed DTC shall not be visible for
			 *      Dem_DcmGetFunctionalUnitOfDTC,it shall return DEM_GET_FU-
			 *      NCTIONALUNITOFDTC_WRONG_DTC
			 *
			 * @req [SWS_Dem_00593] The Dem module shall provide a functional
			 *      unit value per DTC (refer to Dem_DcmGetFunctionalUnitOfDTC),
			 *      only if configured for at least one DTC.
			 *
			 */
			ret = DEM_GET_FUNCTIONALUNITOFDTC_WRONG_DTC;
		}
		else
		{
			*pDTCFunctionalUnit = Dem_ConfigPtr->DemDTC[u16DtcIndex].DemDTCFunctionalUnit;
			ret = DEM_GET_FUNCTIONALUNITOFDTC_OK;
		}
    }
#endif /* #if(DEM_DTC_NUM > 0) */
    return ret;
}

/**
 * @sid         	0x13
 * @brief      		Dem_DcmSetDTCFilter
 * @details     	Sets the DTC Filter.The server shall perform a bit-wise logical AND-ing
 *                  operation between the parameter DTCStatusMask and the current DTC status
 *                  in the server. In addition to the DTCStatusAvailabilityMask, the server
 *                  shall return all DTCs for which the result of the AND-ing operation is
 *                  non-zero[i.e. (statusOfDTC & DTCStatusMask) != 0].The server shall process
 *                  only the DTC Status bits that it is supporting. OBD Events Suppression
 *                  shall be ignored for this computation. If no DTCs within the server match
 *                  the masking criteria specified in the client's request, no DTC or status
 *                  information shall be provided following the DTCStatusAvailabilityMask byte
 *                  in the positive response message (((statusOfDTC & DTCStatusMask) != 0) &&
 *                  ((severity & DTCSeverityMask) != 0)) == TRUE.
 *
 * @param[in]   	DTCStatusMask: Status-byte mask for DTC status-byte filtering. Autosar-specific
 * 					value to deactivate the status-byte filtering (different meaning than in ISO
 * 					14229-1) to report all supported DTCs (used for service 0x19 sub-functions 0x0A/0x15)
 * @param[in] 		DTCKind: Defines the functional group of DTCs to be reported(e.g. all DTC,
 * 					OBD-relevant DTC).
 * @param[in] 		DTCFormat: Defines the output-format of the requested DTC values for the
 * 					subsequent API calls.
 * @param[in]		DTCOrigin: If the Dem supports more than one event memory this parameter
 * 					is used to select the source memory the DTCs shall be read from.
 * @param[in]		FilterWithSeverity:This flag defines whether severity information shall be
 * 					used for filtering.
 * @param[in] 		FilterForFaultDetectionCounter: This flag defines whether the fault detection
 * 					counter information shall be used for filtering.
 *
 * @return      	Result of the operation to (re-)set a DTC filter.
 * @retval      	DEM_FILTER_ACCEPTED: Filter was accepted.
 * @retval      	DEM_WRONG_FILTER: Wrong filter selected.
 */
FUNC(Dem_ReturnSetFilterType, DEM_CODE) Dem_DcmSetDTCFilter
(
    Dem_UdsStatusByteType DTCStatusMask,
    Dem_DTCKindType DTCKind,
    Dem_DTCFormatType DTCFormat,
    Dem_DTCOriginType DTCOrigin,
    boolean FilterWithSeverity,
    Dem_DTCSeverityType DTCSeverityMask,
    boolean FilterForFaultDetectionCounter
)
{
	Dem_ReturnSetFilterType ret = DEM_WRONG_FILTER;
#if(DEM_DTC_NUM > 0)
#if(DEM_RESSET_CONFIRMEDBIT_ONOVERFLOW == STD_ON)
	Dem_MemoryEntryType* pEntry;
	uint8 u8EntryNum = 0u;
	uint8 u8Loop;
#endif /* #if(DEM_RESSET_CONFIRMEDBIT_ONOVERFLOW == STD_ON) */
#endif /* #if(DEM_DTC_NUM > 0) */

	if (Dem_InitState != DEM_STATE_INIT)
	{
#if(STD_ON == DEM_DEV_ERROR_DETECT)
		/**
		 * @req [SWS_Dem_00124] If development error detection is enabled and any instance calls
		 *      any Dem API, excluding Dem_ReportErrorStatus, Dem_ResetEventDebounceStatus and
		 *      Dem_GetVersionInfo, before the Dem was fully initialized, the Dem module shall set
		 *      the error code DEM_E_UNINIT.
		 *
		 * @req [SWS_Dem_00368] If development error detection is enabled and any instance calls
		 *      any Dem API, excluding Dem_ReportErrorStatus, Dem_ResetEventDebounceStatus and
		 *      Dem_GetVersionInfo, after Dem_Shutdown (refer to chapter 8.3.2.3) has been called,
		 *      the Dem module shall set the error code DEM_E_UNINIT until Dem_Init is called again.
		 */
    	DEM_DET_ERROR_REPORT(DEM_SID_DCMSETDTCFILTER,DEM_E_UNINIT);
#endif /* #if(STD_ON == DEM_DEV_ERROR_DETECT) */
    }
    else if (((DEM_DTC_FORMAT_OBD == DTCFormat) && (DEM_OBD_SUPPORT == DEM_OBD_NO_OBD_SUPPORT))\
    		|| ((DEM_DTC_FORMAT_J1939 == DTCFormat) && (STD_OFF == DEM_J1939_SUPPORT)))
    {
#if(STD_ON == DEM_DEV_ERROR_DETECT)
    	/**
    	 * @req [SWS_Dem_01066] The Det error DEM_E_WRONG_CONFIGURATION shall be reported if the
    	 *      function Dem_DcmSetDTCFilter is called with a value of the parameter DTCFormat
    	 *      that is not supported per configuration (e.g. if DTCFormat "DEM_DTC_FORMAT_OBD"
    	 *      is passed, but OBD is not supported per configuration).
    	 */
    	DEM_DET_ERROR_REPORT(DEM_SID_DCMSETDTCFILTER,DEM_E_WRONG_CONFIGURATION);
#endif /* #if(STD_ON == DEM_DEV_ERROR_DETECT) */
    }
	else if((DTCOrigin == 0xFFu)\
			|| ((DTCOrigin == DEM_DTC_ORIGIN_PERMANENT_MEMORY) &&(DEM_DTC_EMISSION_REL_NUM == 0u))\
			|| ((DTCOrigin > DEM_DTC_ORIGIN_PERMANENT_MEMORY) &&(DEM_USERDEFINE_MEMORY_NUM == 0u))
#if(DEM_MIRROR_MEMORY_NUM == 0)
			|| (DTCOrigin == DEM_DTC_ORIGIN_MIRROR_MEMORY)
#endif /* #if(DEM_MIRROR_MEMORY_NUM == 0) */
			)
	{
#if(STD_ON == DEM_DEV_ERROR_DETECT)
		/**
		 * @req [SWS_Dem_01067] The Det error DEM_E_WRONG_CONFIGURATION shall be reported if the
		 *      function Dem_DcmSetDTCFilter is called with a value of the parameter DTCOrigin
		 *      that is not supported per configuration (e.g. if DTCOrigin "DEM_DTC_ORIGIN_MIRR-
		 *      OR_MEMORY" is passed, but no mirror memory is configured).
		 */
		DEM_DET_ERROR_REPORT(DEM_SID_DCMSETDTCFILTER,DEM_E_WRONG_CONFIGURATION);
#endif /* #if(STD_ON == DEM_DEV_ERROR_DETECT) */
	}
	else if(((DTCKind == DEM_DTC_KIND_EMISSION_REL_DTCS) && (DEM_DTC_EMISSION_REL_NUM == 0u))\
			|| ((DTCKind == DEM_DTC_KIND_ALL_DTCS) && (DEM_DTC_NUM == 0u)))
	{
#if(STD_ON == DEM_DEV_ERROR_DETECT)
		/**
		 * @req [SWS_Dem_01065] The Det error DEM_E_WRONG_CONFIGURATION shall be reported if the
		 *      function Dem_DcmSetDTCFilter is called with a value of the parameter DTCKind that
		 *      is not supported per configuration(e.g if DEM_DTC_KIND_EMISSION_REL_DTCS is passed
		 *      in DTCKind, but no emission related DTCs are configured).
		 */
		DEM_DET_ERROR_REPORT(DEM_SID_DCMSETDTCFILTER,DEM_E_WRONG_CONFIGURATION);
#endif /* #if(STD_ON == DEM_DEV_ERROR_DETECT) */
	}
    else
    {
#if(DEM_DTC_NUM > 0)
    	/**
    	 * @req [SWS_Dem_01058] The function Dem_DcmSetDTCFilter shall ignore unsupported bits
    	 *      (refer to configuration parameter DemDtcStatusAvailabilityMask) retrieved in
    	 *      DTCStatusMask.
    	 */
		Dem_DTCFilter.DTCStatusMask						= DTCStatusMask;
		Dem_DTCFilter.DTCKind							= DTCKind;
    	Dem_DTCFilter.DTCFormat							= DTCFormat;
		Dem_DTCFilter.DTCOrigin							= DTCOrigin;
		Dem_DTCFilter.FilterWithSeverity				= FilterWithSeverity;
		Dem_DTCFilter.DTCSeverityMask					= DTCSeverityMask;
		Dem_DTCFilter.FilterForFaultDetectionCounter	= FilterForFaultDetectionCounter;
		Dem_DTCFilter.FilterSet							= (boolean)TRUE;
		Dem_DTCFilter.ReadIndex 						= 0u;
#if(DEM_RESSET_CONFIRMEDBIT_ONOVERFLOW == STD_ON)
		Dem_DTCFilter.TimeOrder							= (boolean)FALSE;
		Dem_DTCFilter.AbsTime							= 0u;
#endif /* #if(DEM_RESSET_CONFIRMEDBIT_ONOVERFLOW == STD_ON) */

#if(DEM_RESSET_CONFIRMEDBIT_ONOVERFLOW == STD_ON)
    	/**
    	 * @req [SWS_Dem_00410] The Dem module shall report DTCs in the chronological order of the
    	 *      event storage (refer to API Dem_DcmGetNextFilteredDTC),if:
    	 *      1.the DTCStatus parameter has the "pending DTC" or "confirmed DTC" bit or both bits
    	 *        set
    	 *      2.all other bits of the DTCStatus parameter are set to false
    	 *      3.DemResetConfirmedBitOnOverflow is set to true
    	 */
    	if(((DTCStatusMask & 0x0Cu) != 0u) && ((DTCStatusMask & 0xF3u) == 0u))
    	{
    		pEntry = Dem_GetMemoryConf(DTCOrigin,&u8EntryNum);

    		if(pEntry != NULL_PTR)
    		{
    			for(u8Loop = 0u; u8Loop < u8EntryNum; u8Loop++)
    			{
    				if(pEntry[u8Loop].EventId != 0u)
    				{
        				if(pEntry[u8Loop].AbsTime > Dem_DTCFilter.AbsTime)
        				{	/* @req [SWS_Dem_00411] */
        					Dem_DTCFilter.AbsTime = pEntry[u8Loop].AbsTime;

        					if(Dem_DTCFilter.TimeOrder != (boolean)TRUE)
        					{
            					Dem_DTCFilter.TimeOrder = (boolean)TRUE;
            					DEM_VALUE_SET(Dem_DTCFilter.DTCFilterRecord,0u,DEM_DTC_NUM_BYTE);
        					}
        				}
    				}
    			}
    		}
    	}
#endif /* #if(DEM_RESSET_CONFIRMEDBIT_ONOVERFLOW == STD_ON) */
#endif /* #if(DEM_DTC_NUM > 0) */
		ret = DEM_FILTER_ACCEPTED;
    }
    return ret;
}

/**
 * @sid         	0x17
 * @brief      		Dem_DcmGetNumberOfFilteredDTC
 * @details     	Gets the number of a filtered DTC.
 *
 * @param[out]		pNumberOfFilteredDTC: The number of DTCs matching the defined status mask.
 *
 * @return      	Result of getting operation.
 * @retval      	DEM_NUMBER_OK    	Getting number of filtered DTCs was successful.
 * @retval      	DEM_NUMBER_FAILED	Getting number of filtered DTCs failed.
 * @retval			DEM_NUMBER_PENDING	The requested value is calculated asynchronously and
 *                  currently not available.The caller can retry later.
 */
FUNC(Dem_ReturnGetNumberOfFilteredDTCType,DEM_CODE)Dem_DcmGetNumberOfFilteredDTC
(
	P2VAR(uint16, AUTOMATIC, DEM_CODE) pNumberOfFilteredDTC
)
{
	Dem_ReturnGetNumberOfFilteredDTCType ret = DEM_NUMBER_FAILED;
#if(DEM_DTC_NUM > 0)
	uint16 u16Loop;
	uint16 u16DtcRef;

#if(STD_ON == DEM_DEV_ERROR_DETECT)
	if (Dem_InitState != DEM_STATE_INIT)
	{
		/**
		 * @req [SWS_Dem_00124] If development error detection is enabled and any instance calls
		 *      any Dem API, excluding Dem_ReportErrorStatus, Dem_ResetEventDebounceStatus and
		 *      Dem_GetVersionInfo, before the Dem was fully initialized, the Dem module shall set
		 *      the error code DEM_E_UNINIT.
		 *
		 * @req [SWS_Dem_00368] If development error detection is enabled and any instance calls
		 *      any Dem API, excluding Dem_ReportErrorStatus, Dem_ResetEventDebounceStatus and
		 *      Dem_GetVersionInfo, after Dem_Shutdown (refer to chapter 8.3.2.3) has been called,
		 *      the Dem module shall set the error code DEM_E_UNINIT until Dem_Init is called again.
		 */
    	DEM_DET_ERROR_REPORT(DEM_SID_DCMGETNUMBEROFFILTEREDDTC,DEM_E_UNINIT);
    }
    else if (pNumberOfFilteredDTC == NULL_PTR)
    {
    	DEM_DET_ERROR_REPORT(DEM_SID_DCMGETNUMBEROFFILTEREDDTC,DEM_E_PARAM_POINTER);
    }
    else
#endif /* #if(STD_ON == DEM_DEV_ERROR_DETECT) */
    {
    	*pNumberOfFilteredDTC = 0u;
    	/**
    	 * @req [SWS_Dem_00061] The function Dem_DcmGetNumberOfFilteredDTC shall get the number of DTCs
    	 *      matching the filter criteria defined by the function call of Dem_DcmSetDTCFilter. The
    	 *      Dem_DcmSetDTCFilter has to be called prior to Dem_DcmGetNumberOfFilteredDTC.
    	 */
    	if(Dem_DTCFilter.FilterSet == (boolean)TRUE)
    	{
    		ret = DEM_NUMBER_OK;

    		if(Dem_DTCFilter.DTCStatusMask == 0u)
    		{
    			for(u16Loop = 0u; u16Loop < DEM_DTC_NUM; u16Loop++)
    			{
    				if(Dem_ISEnable_DTCSuppress(u16Loop) == (boolean)FALSE)
    				{
    					(*pNumberOfFilteredDTC)++;
    				}
    			}
    		}
    		else
    		{
    			for(u16Loop = 0u; u16Loop < DEM_DTC_NUM; u16Loop++)
    			{
    				u16DtcRef = Dem_ConfigPtr->DemEventParameter[u16Loop].DemDTCRef;
    				if(Dem_ISEnable_DTCSuppress(u16DtcRef) == (boolean)FALSE)
    				{
        				if((boolean)TRUE == Dem_FilterDtcCheck(u16DtcRef))
        				{
        					(*pNumberOfFilteredDTC)++;
        				}
    				}
    			}
    		}
    	}
    }
#endif /* #if(DEM_DTC_NUM > 0) */
    return ret;
}

/**
 * @sid         	0x18
 * @brief      		Dem_DcmGetNextFilteredDTC
 * @details     	Gets the next filtered DTC matching the filter criteria.
 *
 * @param[out]		pDTC: Receives the DTC value in respective format of the filter
 *                  returned by this function.
 * @param[out]  	pDTCStatus: This parameter receives the status information of the
 *                  requested DTC.
 *
 * @return      	Result of the operation to retrieve a DTC from the Dem.
 * @retval      	DEM_FILTERED_OK: Returned next filtered element.
 * @retval      	DEM_FILTERED_NO_MATCHING_ELEMENT: No further element found.
 * @retval			DEM_FILTERED_PENDING: The requested value is calculated asynchronously
 *                  and currently not available. The caller can retry later. Only used by
 *                  asynchronous interfaces.
 * @retval			DEM_FILTERED_BUFFER_TOO_SMALL:Buffer in the BufSize parameter is not
 *                  huge enough.
 */
FUNC(Dem_ReturnGetNextFilteredElementType, DEM_CODE)Dem_DcmGetNextFilteredDTC
(
	P2VAR(uint32, AUTOMATIC, DEM_CODE) pDTC,
	P2VAR(Dem_UdsStatusByteType, AUTOMATIC, DEM_CODE) pDTCStatus
)
{
	Dem_ReturnGetNextFilteredElementType ret = DEM_FILTERED_NO_MATCHING_ELEMENT;
#if(DEM_DTC_NUM > 0)

#if (STD_ON == DEM_DEV_ERROR_DETECT)
	if (Dem_InitState != DEM_STATE_INIT)
	{
		/**
		 * @req [SWS_Dem_00124] If development error detection is enabled and any instance calls
		 *      any Dem API, excluding Dem_ReportErrorStatus, Dem_ResetEventDebounceStatus and
		 *      Dem_GetVersionInfo, before the Dem was fully initialized, the Dem module shall set
		 *      the error code DEM_E_UNINIT.
		 *
		 * @req [SWS_Dem_00368] If development error detection is enabled and any instance calls
		 *      any Dem API, excluding Dem_ReportErrorStatus, Dem_ResetEventDebounceStatus and
		 *      Dem_GetVersionInfo, after Dem_Shutdown (refer to chapter 8.3.2.3) has been called,
		 *      the Dem module shall set the error code DEM_E_UNINIT until Dem_Init is called again.
		 */
    	DEM_DET_ERROR_REPORT(DEM_SID_DCMGETNEXTFILTEREDDTC,DEM_E_UNINIT);
    }
    else if((pDTCStatus == NULL_PTR) || (pDTC == NULL_PTR))
    {
    	DEM_DET_ERROR_REPORT(DEM_SID_DCMGETNEXTFILTEREDDTC,DEM_E_PARAM_POINTER);
    }
    else
#endif /* #if (STD_ON == DEM_DEV_ERROR_DETECT) */
    {
    	if(Dem_DTCFilter.FilterSet == (boolean)TRUE)
    	{
			/* report all supported DTCs */
			if(Dem_DTCFilter.DTCStatusMask == 0u)
			{
				ret = Dem_GetALLFilteredDTC(pDTC,pDTCStatus);
			}
			else
			{
#if(DEM_RESSET_CONFIRMEDBIT_ONOVERFLOW == STD_ON)
				if(Dem_DTCFilter.TimeOrder == (boolean)TRUE)
				{
					ret = Dem_ReportDtcByTimeOrder(pDTC,pDTCStatus);
				}
				else
#endif /* #if(DEM_RESSET_CONFIRMEDBIT_ONOVERFLOW == STD_ON) */
				{
					ret = Dem_ReportDtcByConfOrder(pDTC,pDTCStatus);
				}
			}
    	}
    }
#endif /* #if(DEM_DTC_NUM > 0) */
    return ret;
}

/**
 * @sid         	0x3b
 * @brief      		Dem_DcmGetNextFilteredDTCAndFDC
 * @details     	Gets the next filtered DTC and its associated Fault Detection Counter(FDC)
 *                  matching the filter criteria.
 *
 * @param[out]		pDTC: Receives the DTC value in respective format of the filter returned by
 *                  this function.
 * @param[out]		pDTCFaultDetectionCounter: This parameter receives the Fault Detection Counter
 * 					information of the requested DTC.
 *
 * @return      	Result of the operation to retrieve a DTC from the Dem.
 * @retval      	DEM_FILTERED_OK: Returned next filtered element.
 * @retval      	DEM_FILTERED_NO_MATCHING_ELEMENT: No further element found
 * @retval			DEM_FILTERED_PENDING: The requested value is calculated asynchronously and
 *                  currently not available.The caller can retry later.Only used by asynchronous
 * 					interfaces.
 * @retval			DEM_FILTERED_BUFFER_TOO_SMALL:Buffer in the BufSize parameter is not huge enough.
 */
FUNC(Dem_ReturnGetNextFilteredElementType, DEM_CODE)Dem_DcmGetNextFilteredDTCAndFDC
(
	P2VAR(uint32, AUTOMATIC, DEM_CODE) pDTC,
	P2VAR(sint8, AUTOMATIC, DEM_CODE) pDTCFaultDetectionCounter
)
{
	Dem_ReturnGetNextFilteredElementType ret = DEM_FILTERED_NO_MATCHING_ELEMENT;

#if(DEM_DTC_NUM > 0)
	uint8 u8EntryNum = 0u;
	uint16 u16DtcRef;
	Dem_MemoryEntryType* pEntry;

#if (STD_ON == DEM_DEV_ERROR_DETECT)
	if (Dem_InitState != DEM_STATE_INIT)
	{
		/**
		 * @req [SWS_Dem_00124] If development error detection is enabled and any instance calls
		 *      any Dem API, excluding Dem_ReportErrorStatus, Dem_ResetEventDebounceStatus and
		 *      Dem_GetVersionInfo, before the Dem was fully initialized, the Dem module shall set
		 *      the error code DEM_E_UNINIT.
		 *
		 * @req [SWS_Dem_00368] If development error detection is enabled and any instance calls
		 *      any Dem API, excluding Dem_ReportErrorStatus, Dem_ResetEventDebounceStatus and
		 *      Dem_GetVersionInfo, after Dem_Shutdown (refer to chapter 8.3.2.3) has been called,
		 *      the Dem module shall set the error code DEM_E_UNINIT until Dem_Init is called again.
		 */
    	DEM_DET_ERROR_REPORT(DEM_SID_DCMGETNEXTFILTEREDDTCANDFDC,DEM_E_UNINIT);
    }
    else if ((pDTCFaultDetectionCounter == NULL_PTR) || (pDTC == NULL_PTR))
    {
    	DEM_DET_ERROR_REPORT(DEM_SID_DCMGETNEXTFILTEREDDTCANDFDC,DEM_E_PARAM_POINTER);
    }
    else
#endif /* #if (STD_ON == DEM_DEV_ERROR_DETECT) */
    {
    	pEntry = Dem_GetMemoryConf(Dem_DTCFilter.DTCOrigin,&u8EntryNum);

		if(pEntry != NULL_PTR)
		{
			do
			{
				if(pEntry[Dem_DTCFilter.ReadIndex].EventId != 0u)
				{
					u16DtcRef = Dem_ConfigPtr->DemEventParameter[(pEntry[Dem_DTCFilter.ReadIndex].\
							EventId - 1u)].DemDTCRef;

					if((u16DtcRef != 0xFFFFu)
						&& (Dem_ISEnable_DTCSuppress(u16DtcRef) == (boolean)FALSE)
						&& ((boolean)TRUE == Dem_FilterDtcCheck(u16DtcRef)))
					{
						*pDTC = Dem_ConfigPtr->DemDTC[u16DtcRef].DemDtcValue;
						*pDTCFaultDetectionCounter = Dem_InternalFDC[u16DtcRef];
						ret = DEM_FILTERED_OK;
						Dem_DTCFilter.ReadIndex++;
						break;
					}
				}
				Dem_DTCFilter.ReadIndex++;
			}while(Dem_DTCFilter.ReadIndex < u8EntryNum);
		}
    }
#endif /* #if(DEM_DTC_NUM > 0) */

    return ret;
}

/**
 * @sid         	0x3d
 * @brief      		Dem_DcmGetNextFilteredDTCAndSeverity
 *
 * @details     	Gets the next filtered DTC and its associated Severity matching the filter
 *                  criteria.
 *
 * @param[out]		pDTC: Receives the DTC value in respective format of the filter returned by
 *                  this function.
 * @param[out]		pDTCStatus: This parameter receives the status information of the requested DTC.
 * @param[out]		pDTCSeverity: Receives the severity value returned by the function.
 * @param[out]		pDTCFunctionalUnit: Receives the functional unit value returned by the function.
 *
 * @return      	Result of the operation to retrieve a DTC from the Dem.
 * @retval      	DEM_FILTERED_OK: Returned next filtered element.
 * @retval      	DEM_FILTERED_NO_MATCHING_ELEMENT: No further element found
 * @retval			DEM_FILTERED_PENDING: The requested value is calculated asynchronously and
 *                  currently not available.The caller can retry later.Only used by asynchronous
 * 					interfaces.
 * @retval			DEM_FILTERED_BUFFER_TOO_SMALL:Buffer in the BufSize parameter is not huge enough.
 */
FUNC(Dem_ReturnGetNextFilteredElementType, DEM_CODE)Dem_DcmGetNextFilteredDTCAndSeverity
(
	P2VAR(uint32, AUTOMATIC, DEM_CODE) pDTC,
	P2VAR(Dem_UdsStatusByteType, AUTOMATIC, DEM_CODE) pDTCStatus,
	P2VAR(Dem_DTCSeverityType, AUTOMATIC, DEM_CODE) pDTCSeverity,
	P2VAR(uint8, AUTOMATIC, DEM_CODE) pDTCFunctionalUnit
)
{
	Dem_ReturnGetNextFilteredElementType ret = DEM_FILTERED_NO_MATCHING_ELEMENT;

#if(DEM_DTC_NUM > 0)
	uint8 u8EntryNum = 0u;
	uint16 u16DtcRef;
	Dem_MemoryEntryType* pEntry;

#if(STD_ON == DEM_DEV_ERROR_DETECT)
	if (Dem_InitState != DEM_STATE_INIT)
	{
		/**
		 * @req [SWS_Dem_00124] If development error detection is enabled and any instance calls
		 *      any Dem API, excluding Dem_ReportErrorStatus, Dem_ResetEventDebounceStatus and
		 *      Dem_GetVersionInfo, before the Dem was fully initialized, the Dem module shall set
		 *      the error code DEM_E_UNINIT.
		 *
		 * @req [SWS_Dem_00368] If development error detection is enabled and any instance calls
		 *      any Dem API, excluding Dem_ReportErrorStatus, Dem_ResetEventDebounceStatus and
		 *      Dem_GetVersionInfo, after Dem_Shutdown (refer to chapter 8.3.2.3) has been called,
		 *      the Dem module shall set the error code DEM_E_UNINIT until Dem_Init is called again.
		 */
    	DEM_DET_ERROR_REPORT(DEM_SID_DCMGETNEXTFILTEREDDTCANDSEVERITY,DEM_E_UNINIT);
    }
    else if((pDTC == NULL_PTR) \
    		|| (pDTCStatus == NULL_PTR) \
			|| (pDTCSeverity == NULL_PTR) \
			|| (pDTCFunctionalUnit == NULL_PTR))
    {
    	DEM_DET_ERROR_REPORT(DEM_SID_DCMGETNEXTFILTEREDDTCANDSEVERITY,DEM_E_PARAM_POINTER);
    }
    else
#endif /* #if(STD_ON == DEM_DEV_ERROR_DETECT) */
    {
    	pEntry = Dem_GetMemoryConf(Dem_DTCFilter.DTCOrigin,&u8EntryNum);

		if(pEntry != NULL_PTR)
		{
			do
			{
				if(pEntry[Dem_DTCFilter.ReadIndex].EventId != 0u)
				{
					u16DtcRef = Dem_ConfigPtr->DemEventParameter[(pEntry[Dem_DTCFilter.ReadIndex].\
							EventId - 1u)].DemDTCRef;

					if((u16DtcRef != 0xFFFFu)
						&& (Dem_ISEnable_DTCSuppress(u16DtcRef) == (boolean)FALSE)
						&& ((boolean)TRUE == Dem_FilterDtcCheck(u16DtcRef)))
					{
						*pDTC = Dem_ConfigPtr->DemDTC[u16DtcRef].DemDtcValue;
						*pDTCStatus = (Dem_DtcUdsStatus[u16DtcRef] & DEM_DTCSTATUS_AVAILABILITY_MASK); /* PRQA S 2985 #violate MISAR2004_21.1: The value of the result will be different with left-hand operand if DEM_DTCSTATUS_AVAILABILITY_MASK is not 255 */
						*pDTCSeverity = Dem_ConfigPtr->DemDTC[u16DtcRef].DemDTCSeverity;
						*pDTCFunctionalUnit = Dem_ConfigPtr->DemDTC[u16DtcRef].DemDTCFunctionalUnit;
						ret = DEM_FILTERED_OK;
						Dem_DTCFilter.ReadIndex++;
						break;
					}
				}
				Dem_DTCFilter.ReadIndex++;
			}while(Dem_DTCFilter.ReadIndex < u8EntryNum);
		}
    }
#endif /* #if(DEM_DTC_NUM > 0) */
    return ret;
}

/**
 * @sid         	0x3f
 * @brief      		Dem_DcmSetFreezeFrameRecordFilter
 * @details     	Sets a freeze frame record filter.
 *
 * @param[in]   	DTCFormat: Defines the output-format of the requested DTC values for the
 *                  subsequent API calls.
 *
 * @param[out]		pNumberOfFilteredRecords: Number of freeze frame records currently stored
 *                  in the event memory.
 *
 * @return      	Result of the operation to (re-)set a freeze frame record filter.
 * @retval      	DEM_FILTER_ACCEPTED: Filter was accepted.
 * @retval      	DEM_WRONG_FILTER: Wrong filter selected.
 */
FUNC(Dem_ReturnSetFilterType, DEM_CODE)Dem_DcmSetFreezeFrameRecordFilter
(
    Dem_DTCFormatType DTCFormat,
    P2VAR(uint16, AUTOMATIC, DEM_CODE) pNumberOfFilteredRecords
)
{
	Dem_ReturnSetFilterType ret = DEM_WRONG_FILTER;

#if(DEM_FREEZE_FRAME_CLASS_NUM > 0)
	uint8 u8EntryNum = 0u;
	uint8 u8Loop = 0u;
	Dem_MemoryEntryType* pEntry;

	if (Dem_InitState != DEM_STATE_INIT)
	{
#if (STD_ON == DEM_DEV_ERROR_DETECT)
		/**
		 * @req [SWS_Dem_00124] If development error detection is enabled and any instance calls
		 *      any Dem API, excluding Dem_ReportErrorStatus, Dem_ResetEventDebounceStatus and
		 *      Dem_GetVersionInfo, before the Dem was fully initialized, the Dem module shall set
		 *      the error code DEM_E_UNINIT.
		 *
		 * @req [SWS_Dem_00368] If development error detection is enabled and any instance calls
		 *      any Dem API, excluding Dem_ReportErrorStatus, Dem_ResetEventDebounceStatus and
		 *      Dem_GetVersionInfo, after Dem_Shutdown (refer to chapter 8.3.2.3) has been called,
		 *      the Dem module shall set the error code DEM_E_UNINIT until Dem_Init is called again.
		 */
    	DEM_DET_ERROR_REPORT(DEM_SID_DCMSETFREEZEFRAMERECORDFILTER,DEM_E_UNINIT);
#endif  /* #if(STD_ON == DEM_DEV_ERROR_DETECT) */
	}
    else if (DEM_DTC_FORMAT_UDS != DTCFormat)
    {
#if (STD_ON == DEM_DEV_ERROR_DETECT)
    	DEM_DET_ERROR_REPORT(DEM_SID_DCMSETFREEZEFRAMERECORDFILTER,DEM_E_WRONG_CONFIGURATION);
#endif  /* #if(STD_ON == DEM_DEV_ERROR_DETECT) */
    }
    else if (pNumberOfFilteredRecords == NULL_PTR)
    {
#if (STD_ON == DEM_DEV_ERROR_DETECT)
    	DEM_DET_ERROR_REPORT(DEM_SID_DCMSETFREEZEFRAMERECORDFILTER,DEM_E_PARAM_POINTER);
#endif  /* #if(STD_ON == DEM_DEV_ERROR_DETECT) */
    }
    else
    {
    	Dem_FFRecFilter.DTCFormat = DTCFormat;
    	*pNumberOfFilteredRecords = 0u;

    	/**
    	 * @req [SWS_Dem_00210] The function Dem_DcmSetFreezeFrameRecordFilter shall retrieve the number
    	 *      of filtered freeze frame records. This filter always belongs to primary memory.
    	 */
    	pEntry = Dem_GetMemoryConf(DEM_DTC_ORIGIN_PRIMARY_MEMORY,&u8EntryNum);

    	do
    	{
    		if(pEntry->EventId != 0u)
    		{
    			*pNumberOfFilteredRecords += pEntry->FFStoreNum;
    		}
    		u8Loop++;
    		pEntry++;
    	}while(u8Loop < u8EntryNum);
    	Dem_FFRecFilter.AlreadyGetNum = 0u;
    	Dem_FFRecFilter.CurrentEntry = 0u;
    	Dem_FFRecFilter.CurrentFF = 0u;
    	Dem_FFRecFilter.NumberOfFilteredRecords = *pNumberOfFilteredRecords;
    	ret = DEM_FILTER_ACCEPTED;
    }
#endif /* #if(DEM_FREEZE_FRAME_CLASS_NUM > 0) */
    return ret;
}

/**
 * @sid         	0x3a
 * @brief      		Dem_DcmGetNextFilteredRecord
 *
 * @details     	Gets the next freeze frame record number and its associated DTC stored
 *                  in the event memory.
 *
 * @param[out]		pDTC: Receives the DTC value in respective format of the filter returned
 *                  by this function.
 * @param[out]		pRecordNumber: Freeze frame record number of the reported DTC(relative
 *                  addressing).
 *
 * @return      	Result of the operation to retrieve a DTC and its associated snapshot
 *                  record number from the Dem.
 * @retval      	DEM_FILTERED_OK: Returned next filtered element.
 * @retval      	DEM_FILTERED_NO_MATCHING_ELEMENT: No further element found.
 * @retval			DEM_FILTERED_PENDING: The requested value is calculated asynchronously and
 *                  currently not available.The caller can retry later.Only used by asynchronous
 * 					interfaces.
 * @retval			DEM_FILTERED_BUFFER_TOO_SMALL:Buffer in the BufSize parameter is not huge
 *                  enough.
 */
FUNC(Dem_ReturnGetNextFilteredElementType, DEM_CODE)Dem_DcmGetNextFilteredRecord
(
	P2VAR(uint32, AUTOMATIC, DEM_CODE) pDTC,
	P2VAR(uint8, AUTOMATIC, DEM_CODE) pRecordNumber
)
{
	Dem_ReturnGetNextFilteredElementType ret = DEM_FILTERED_NO_MATCHING_ELEMENT;
#if(DEM_FREEZE_FRAME_CLASS_NUM > 0)
	uint16 u16DtcRef;
	Dem_MemoryEntryType* pEntry;

	if (Dem_InitState != DEM_STATE_INIT)
	{
#if (STD_ON == DEM_DEV_ERROR_DETECT)
		/**
		 * @req [SWS_Dem_00124] If development error detection is enabled and any instance calls
		 *      any Dem API, excluding Dem_ReportErrorStatus, Dem_ResetEventDebounceStatus and
		 *      Dem_GetVersionInfo, before the Dem was fully initialized, the Dem module shall set
		 *      the error code DEM_E_UNINIT.
		 *
		 * @req [SWS_Dem_00368] If development error detection is enabled and any instance calls
		 *      any Dem API, excluding Dem_ReportErrorStatus, Dem_ResetEventDebounceStatus and
		 *      Dem_GetVersionInfo, after Dem_Shutdown (refer to chapter 8.3.2.3) has been called,
		 *      the Dem module shall set the error code DEM_E_UNINIT until Dem_Init is called again.
		 */
    	DEM_DET_ERROR_REPORT(DEM_SID_DCMGETNEXTFILTEREDRECORD,DEM_E_UNINIT);
#endif /* #if (STD_ON == DEM_DEV_ERROR_DETECT) */
    }
    else if (pDTC == NULL_PTR)
    {
#if (STD_ON == DEM_DEV_ERROR_DETECT)
    	DEM_DET_ERROR_REPORT(DEM_SID_DCMGETNEXTFILTEREDRECORD,DEM_E_PARAM_POINTER);
#endif /* #if (STD_ON == DEM_DEV_ERROR_DETECT) */
    }
    else if (pRecordNumber == NULL_PTR)
    {
#if (STD_ON == DEM_DEV_ERROR_DETECT)
    	DEM_DET_ERROR_REPORT(DEM_SID_DCMGETNEXTFILTEREDRECORD,DEM_E_PARAM_POINTER);
#endif /* #if (STD_ON == DEM_DEV_ERROR_DETECT) */
    }
    else
    {
		/* PRQA S 0771 EOF # ignore this warning */
		while(Dem_FFRecFilter.AlreadyGetNum < Dem_FFRecFilter.NumberOfFilteredRecords)
		{
			if(Dem_FFRecFilter.CurrentEntry >= DEM_MAX_NUMBER_EVENTENTRY_PRIMARY)
			{
				Dem_FFRecFilter.CurrentEntry = 0u;
				Dem_FFRecFilter.CurrentFF = 0u;
				break;
			}
			else
			{
				pEntry = &(DemPrimaryMemory[Dem_FFRecFilter.CurrentEntry]);

				if(Dem_FFRecFilter.CurrentFF >= pEntry->FFStoreNum)
				{
					Dem_FFRecFilter.CurrentFF = 0u;
					Dem_FFRecFilter.CurrentEntry++;
				}
				else
				{
					u16DtcRef = Dem_ConfigPtr->DemEventParameter[(pEntry->EventId - 1u)].DemDTCRef;
					if(Dem_ISEnable_DTCSuppress(u16DtcRef) == (boolean)TRUE)
					{
						Dem_FFRecFilter.CurrentFF = 0u;
						Dem_FFRecFilter.CurrentEntry++;
					}
					else
					{
#if(DEM_MAX_NUMBER_FF_RECORDS > 0)
						if(pEntry->FFInfo[Dem_FFRecFilter.CurrentFF].RecNum != 0xFFu)
						{
							*pDTC = Dem_ConfigPtr->DemDTC[u16DtcRef].DemDtcValue;
							*pRecordNumber = pEntry->FFInfo[Dem_FFRecFilter.CurrentFF].RecNum;
							ret = DEM_FILTERED_OK;
							Dem_FFRecFilter.AlreadyGetNum++;
							Dem_FFRecFilter.CurrentFF++;
							break;
						}
#endif  /* #if((DEM_MAX_NUMBER_FF_RECORDS > 0) */
						Dem_FFRecFilter.CurrentFF++;
					}
				}
			}
		}
    }
#endif /* #if(DEM_FREEZE_FRAME_CLASS_NUM > 0) */
    return ret;
}

/**
 * @sid         	0x19
 * @brief      		Dem_DcmGetDTCByOccurrenceTime
 * @details     	Gets the DTC by occurrence time.There is no explicit parameter for the
 *                  DTC-origin as the origin always is DEM_DTC_ORIGIN_PRIMARY_MEMORY.
 *
 * @param[in]   	DTCRequest: This parameter defines the request type of the DTC.
 *
 * @param[out]		pDTC: Receives the DTC value in respective format of the filter returned
 *                  by this function.
 *
 * @return      	Status of the operation of type Dem_ReturnGetDTCByOccurrenceTimeType.
 * @retval      	DEM_OCCURR_OK: matching DTC available
 * @retval      	DEM_OCCURR_NOT_AVAILABLE: no DTC is matching the requested occurrence time.
 */
FUNC(Dem_ReturnGetDTCByOccurrenceTimeType, DEM_CODE)Dem_DcmGetDTCByOccurrenceTime
(
    Dem_DTCRequestType DTCRequest,
    P2VAR(uint32, AUTOMATIC, DEM_CODE) pDTC
)
{
	Dem_ReturnGetDTCByOccurrenceTimeType ret = DEM_OCCURR_NOT_AVAILABLE;
#if(DEM_DTC_NUM > 0)
	Dem_EventIdType InternalId;
	uint16 u16DtcRef;

	if (Dem_InitState != DEM_STATE_INIT)
	{
#if (STD_ON == DEM_DEV_ERROR_DETECT)
		/**
		 * @req [SWS_Dem_00124] If development error detection is enabled and any instance calls
		 *      any Dem API, excluding Dem_ReportErrorStatus, Dem_ResetEventDebounceStatus and
		 *      Dem_GetVersionInfo, before the Dem was fully initialized, the Dem module shall set
		 *      the error code DEM_E_UNINIT.
		 *
		 * @req [SWS_Dem_00368] If development error detection is enabled and any instance calls
		 *      any Dem API, excluding Dem_ReportErrorStatus, Dem_ResetEventDebounceStatus and
		 *      Dem_GetVersionInfo, after Dem_Shutdown (refer to chapter 8.3.2.3) has been called,
		 *      the Dem module shall set the error code DEM_E_UNINIT until Dem_Init is called again.
		 */
    	DEM_DET_ERROR_REPORT(DEM_SID_DCMGETDTCBYOCCURRENCETIME,DEM_E_UNINIT);
#endif /* #if (STD_ON == DEM_DEV_ERROR_DETECT) */
    }
    else if (pDTC == NULL_PTR)
    {
#if (STD_ON == DEM_DEV_ERROR_DETECT)
    	DEM_DET_ERROR_REPORT(DEM_SID_DCMGETDTCBYOCCURRENCETIME,DEM_E_PARAM_POINTER);
#endif /* #if (STD_ON == DEM_DEV_ERROR_DETECT) */
    }
    else
    {
    	ret = DEM_OCCURR_OK;

    	if(DTCRequest == DEM_FIRST_FAILED_DTC)
    	{
    		InternalId = Dem_EventOccTime.firstFailEvent;
    	}
    	else if(DTCRequest == DEM_MOST_RECENT_FAILED_DTC)
    	{
    		InternalId = Dem_EventOccTime.mostFailEvent;
    	}
    	else if(DTCRequest == DEM_FIRST_DET_CONFIRMED_DTC)
		{
    		InternalId = Dem_EventOccTime.firstConfEvent;
		}
    	else if(DTCRequest == DEM_MOST_REC_DET_CONFIRMED_DTC)
		{
    		InternalId = Dem_EventOccTime.mostConfEvent;
		}
    	else
    	{
#if (STD_ON == DEM_DEV_ERROR_DETECT)
    		DEM_DET_ERROR_REPORT(DEM_SID_DCMGETDTCBYOCCURRENCETIME,DEM_E_WRONG_CONDITION);
#endif /* #if (STD_ON == DEM_DEV_ERROR_DETECT) */
    		ret = DEM_OCCURR_NOT_AVAILABLE;
    	}

    	/**
    	 * @req [SWS_Dem_00221] The function Dem_DcmGetDTCByOccurrenceTime shall return
    	 *      DEM_OCCURR_NOT_AVAILABLE, if no DTC is matching the requested occurrence
    	 *      time (DTCRequest).
    	 */
    	if((ret == DEM_OCCURR_OK) && (InternalId != 0xFFFFu))
    	{
    		u16DtcRef = Dem_ConfigPtr->DemEventParameter[InternalId].DemDTCRef;
    		if((u16DtcRef != 0xFFFFu) && (Dem_ISEnable_DTCSuppress(u16DtcRef) == (boolean)FALSE))
    		{
    			/**
    			 * @req [SWS_Dem_00219] The function Dem_DcmGetDTCByOccurrenceTime shall provide the
    			 *      capability to get one DTC stored in the primary event memory according to the
    			 *      API parameter DTCRequest, which specifies the relevant occurrence time.
    			 */
    			*pDTC = Dem_ConfigPtr->DemDTC[u16DtcRef].DemDtcValue;
    		}
    		else
    		{
    			ret = DEM_OCCURR_NOT_AVAILABLE;
    		}
    	}
    	else
		{
    		ret = DEM_OCCURR_NOT_AVAILABLE;
		}
    }
#endif /* #if(DEM_DTC_NUM > 0) */
    return ret;
}


/**
 * @sid         	0xb0
 * @brief      		Dem_DcmControlDTCStatusChangedNotification
 * @details     	Controls the triggering of Dcm_DemTriggerOnDTCStatus.
 *
 * @param[in]   	TriggerNotification: This parameter specifies whether the triggering of the
 *                  notification shall be enabled (TRUE) or disabled(FALSE).
 */
FUNC(void, DEM_CODE) Dem_DcmControlDTCStatusChangedNotification
(
    boolean TriggerNotification
)
{
	/**
	 * @req [SWS_Dem_00827] The Dem shall provide the API Dem_DcmControlDTCStatusChangedNotification.
	 */
#if (STD_ON == DEM_DEV_ERROR_DETECT)
	if (Dem_InitState != DEM_STATE_INIT)
	{
		/**
		 * @req [SWS_Dem_00124] If development error detection is enabled and any instance calls
		 *      any Dem API, excluding Dem_ReportErrorStatus, Dem_ResetEventDebounceStatus and
		 *      Dem_GetVersionInfo, before the Dem was fully initialized, the Dem module shall set
		 *      the error code DEM_E_UNINIT.
		 *
		 * @req [SWS_Dem_00368] If development error detection is enabled and any instance calls
		 *      any Dem API, excluding Dem_ReportErrorStatus, Dem_ResetEventDebounceStatus and
		 *      Dem_GetVersionInfo, after Dem_Shutdown (refer to chapter 8.3.2.3) has been called,
		 *      the Dem module shall set the error code DEM_E_UNINIT until Dem_Init is called again.
		 */
    	DEM_DET_ERROR_REPORT(DEM_SID_DCMCONTROLDTCSTATUSCHANGEDNOTIFICATION,DEM_E_UNINIT);
    }
    else
#endif /* #if (STD_ON == DEM_DEV_ERROR_DETECT) */
    {
    	Dem_DcmTriggerEnable = TriggerNotification;
    }
}

/**
 * @sid         	0x1a
 * @brief      		Dem_DcmDisableDTCRecordUpdate
 *
 * @details     	Disables the event memory update of a specific DTC (only one at one time).
 *
 * @param[in]   	DTC: Selects the DTC in UDS format, for which DTC record update shall be disabled.
 * @param[in] 		DTCOrigin: If the Dem supports more than one event memory, this parameter is used
 *                  to select the source memory for which DTC record update shall be disabled.
 *
 * @return      	Status of the operation to disable the event memory update of a specific DTC.
 * @retval			DEM_DISABLE_DTCRECUP_OK: Event memory update of DTC successfully disabled
 * @retval			DEM_DISABLE_DTCRECUP_WRONG_DTC: DTC value not existing (in UDS format)
 * @retval			DEM_DISABLE_DTCRECUP_WRONG_DTCORIGIN: Wrong DTC origin
 * @retval			DEM_DISABLE_DTCRECUP_PENDING: Disabling is currently not possible. The caller can
 *                  retry later.
 */
FUNC(Dem_ReturnDisableDTCRecordUpdateType, DEM_CODE)Dem_DcmDisableDTCRecordUpdate
(
    uint32 DTC,
    Dem_DTCOriginType DTCOrigin
)
{
	Dem_ReturnDisableDTCRecordUpdateType ret = DEM_DISABLE_DTCRECUP_WRONG_DTC;

#if(DEM_DTC_NUM > 0)
	uint16 u16DtcRef;

#if (STD_ON == DEM_DEV_ERROR_DETECT)
	if (Dem_InitState != DEM_STATE_INIT)
	{
		/**
		 * @req [SWS_Dem_00124] If development error detection is enabled and any instance calls
		 *      any Dem API, excluding Dem_ReportErrorStatus, Dem_ResetEventDebounceStatus and
		 *      Dem_GetVersionInfo, before the Dem was fully initialized, the Dem module shall set
		 *      the error code DEM_E_UNINIT.
		 *
		 * @req [SWS_Dem_00368] If development error detection is enabled and any instance calls
		 *      any Dem API, excluding Dem_ReportErrorStatus, Dem_ResetEventDebounceStatus and
		 *      Dem_GetVersionInfo, after Dem_Shutdown (refer to chapter 8.3.2.3) has been called,
		 *      the Dem module shall set the error code DEM_E_UNINIT until Dem_Init is called again.
		 */
    	DEM_DET_ERROR_REPORT(DEM_SID_DCMDISABLEDTCRECORDUPDATE,DEM_E_UNINIT);
    }
    else if (Dem_DTCRecordUpdateInfo.DTCOrigin != 0xFFu)
    {
    	/**
    	 * @req [SWS_Dem_00648] If development error detection is enabled and the function
    	 *      Dem_DcmDisableDTCRecordUpdate is called while another DTC is locked, the
    	 *      Dem module shall set the error code DEM_E_WRONG_CONDITION
    	 */
    	DEM_DET_ERROR_REPORT(DEM_SID_DCMDISABLEDTCRECORDUPDATE,DEM_E_WRONG_CONDITION);
    }
    else
#endif /* #if (STD_ON == DEM_DEV_ERROR_DETECT) */
    {
    	u16DtcRef = Dem_GetDtcIndexByDtc(DTC,DEM_DTC_FORMAT_UDS);

    	if(u16DtcRef != 0xFFFFu)
    	{
    		DEM_U8BIT_ENABLE(Dem_DtcUpdateDisabled,u16DtcRef);
    		Dem_DTCRecordUpdateInfo.DTCOrigin = DTCOrigin;
    		Dem_DTCRecordUpdateInfo.DtcRef = u16DtcRef;
    		ret = DEM_DISABLE_DTCRECUP_OK;
    	}
    }
#endif /* #if(DEM_DTC_NUM > 0) */
    return ret;
}

/**
 * @sid         	0x1b
 * @brief      		Dem_DcmEnableDTCRecordUpdate
 *
 * @details     	Enables the event memory update of the DTC disabled by
 *                  Dem_DcmDisableDTCRecordUpdate() before.
 *
 * @return      	Result of enable DTC update,it shall always E_OK is returned.
 */
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmEnableDTCRecordUpdate
(
	void
)
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;

#if(DEM_DTC_NUM > 0)
	if (Dem_InitState != DEM_STATE_INIT)
	{
#if (STD_ON == DEM_DEV_ERROR_DETECT)
		/**
		 * @req [SWS_Dem_00124] If development error detection is enabled and any instance calls
		 *      any Dem API, excluding Dem_ReportErrorStatus, Dem_ResetEventDebounceStatus and
		 *      Dem_GetVersionInfo, before the Dem was fully initialized, the Dem module shall set
		 *      the error code DEM_E_UNINIT.
		 *
		 * @req [SWS_Dem_00368] If development error detection is enabled and any instance calls
		 *      any Dem API, excluding Dem_ReportErrorStatus, Dem_ResetEventDebounceStatus and
		 *      Dem_GetVersionInfo, after Dem_Shutdown (refer to chapter 8.3.2.3) has been called,
		 *      the Dem module shall set the error code DEM_E_UNINIT until Dem_Init is called again.
		 */
    	DEM_DET_ERROR_REPORT(DEM_SID_DCMENABLEDTCRECORDUPDATE,DEM_E_UNINIT);
#endif /* #if (STD_ON == DEM_DEV_ERROR_DETECT) */
    }
    else
    {
    	/**
		 * @req [SWS_Dem_00271] The function Dem_DcmEnableDTCRecordUpdate shall release the currently
		 *      disabled DTC which has been protected by the function Dem_DcmDisableDTCRecordUpdate,
		 *      so that the data can be updated again.
		 */
    	DEM_U8BIT_DISABLE(Dem_DtcUpdateDisabled,Dem_DTCRecordUpdateInfo.DtcRef);
    	Dem_DTCRecordUpdateInfo.DTCOrigin = 0xFFu;
    	ret = (Std_ReturnType)E_OK;
    }
#endif /* #if(DEM_DTC_NUM > 0) */
	return ret;
}

/**
 * @sid         	0x1d
 * @brief      		Dem_DcmGetFreezeFrameDataByDTC
 *
 * @details     	Gets freeze frame data by DTC.The function stores the data in the provided
 *                  DestBuffer.
 *
 * @param[in]   	DTC: Diagnostic Trouble Code in UDS format.
 * @param[in]		DTCOrigin: If the Dem supports more than one event memory,this parameter is
 *                  used to select the source memory the DTCs shall be read from.
 * @param[in]		RecordNumber: This parameter is a unique identifier for a freeze frame record
 *                  as defined in ISO 15031-5 and ISO 14229-1.
 *
 * @param[out]		pDestBuffer: This parameter contains a byte pointer that points to the buffer,
 *                  to which the freeze frame data record shall be written to.
 *
 * @Param[inout]	pBufSize: When the function is called this parameter contains the maximum number
 *                  of data bytes that can be written to the buffer.The function returns the actual
 *                  number of written data bytes in this parameter.
 *
 * @return      	Status of the operation to retrieve freeze frame data by DTC.
 * @retval			DEM_GET_FFDATABYDTC_OK: Size successfully returned.
 * @retval			DEM_GET_FFDATABYDTC_WRONG_DTC: DTC value not existing (in UDS format).
 * @retval			DEM_GET_FFDATABYDTC_WRONG_DTCORIGIN: Wrong DTC origin.
 * @retval			DEM_GET_FFDATABYDTC_WRONG_RECORDNUMBER: Record number is not supported by
 *                  configuration and therefore invalid.
 * @retval			DEM_GET_FFDATABYDTC_WRONG_BUFFERSIZE: provided buffer size to small.
 * @retval			DEM_GET_FFDATABYDTC_PENDING: The requested value is calculated asynchronously and
 *                  currently not available.The caller can retry later.
 */
FUNC(Dem_ReturnGetFreezeFrameDataByDTCType, DEM_CODE)Dem_DcmGetFreezeFrameDataByDTC
(
    uint32 DTC,
    Dem_DTCOriginType DTCOrigin,
    uint8 RecordNumber,
    P2VAR(uint8, AUTOMATIC, DEM_CODE) pDestBuffer,
	P2VAR(uint16, AUTOMATIC, DEM_CODE) pBufSize
)
{
	Dem_ReturnGetFreezeFrameDataByDTCType ret = DEM_GET_FFDATABYDTC_WRONG_DTC;

#if(DEM_FREEZE_FRAME_CLASS_NUM > 0)
	uint16 u16DtcRef;

	if (Dem_InitState != DEM_STATE_INIT)
	{
#if (STD_ON == DEM_DEV_ERROR_DETECT)
		/**
		 * @req [SWS_Dem_00124] If development error detection is enabled and any instance calls
		 *      any Dem API, excluding Dem_ReportErrorStatus, Dem_ResetEventDebounceStatus and
		 *      Dem_GetVersionInfo, before the Dem was fully initialized, the Dem module shall set
		 *      the error code DEM_E_UNINIT.
		 *
		 * @req [SWS_Dem_00368] If development error detection is enabled and any instance calls
		 *      any Dem API, excluding Dem_ReportErrorStatus, Dem_ResetEventDebounceStatus and
		 *      Dem_GetVersionInfo, after Dem_Shutdown (refer to chapter 8.3.2.3) has been called,
		 *      the Dem module shall set the error code DEM_E_UNINIT until Dem_Init is called again.
		 */
    	DEM_DET_ERROR_REPORT(DEM_SID_DCMGETFREEZEFRAMEDATABYDTC,DEM_E_UNINIT);
#endif /* #if (STD_ON == DEM_DEV_ERROR_DETECT) */
    }
    else if((pDestBuffer == NULL_PTR) || (pBufSize == NULL_PTR))
    {
#if (STD_ON == DEM_DEV_ERROR_DETECT)
    	DEM_DET_ERROR_REPORT(DEM_SID_DCMGETFREEZEFRAMEDATABYDTC,DEM_E_PARAM_POINTER);
#endif /* #if (STD_ON == DEM_DEV_ERROR_DETECT) */
    	ret = DEM_GET_FFDATABYDTC_WRONG_BUFFERSIZE;
    }
    else if(RecordNumber == 0xFFu)
    {
#if (STD_ON == DEM_DEV_ERROR_DETECT)
    	DEM_DET_ERROR_REPORT(DEM_SID_DCMGETFREEZEFRAMEDATABYDTC,DEM_E_PARAM_DATA);
#endif /* #if (STD_ON == DEM_DEV_ERROR_DETECT) */
    	ret = DEM_GET_FFDATABYDTC_WRONG_RECORDNUMBER;
    }
#if(DEM_OBD_SUPPORT == DEM_OBD_NO_OBD_SUPPORT)
    else if(RecordNumber == 0x00u)
    {
#if (STD_ON == DEM_DEV_ERROR_DETECT)
    	DEM_DET_ERROR_REPORT(DEM_SID_DCMGETFREEZEFRAMEDATABYDTC,DEM_E_PARAM_DATA);
#endif /* #if (STD_ON == DEM_DEV_ERROR_DETECT) */
    	ret = DEM_GET_FFDATABYDTC_WRONG_RECORDNUMBER;
    }
#endif /* #if(DEM_OBD_SUPPORT == DEM_OBD_NO_OBD_SUPPORT) */
    else
    {
    	u16DtcRef = Dem_GetDtcIndexByDtc(DTC,DEM_DTC_FORMAT_UDS);

    	if((u16DtcRef == 0xFFFFu) || (Dem_ISEnable_DTCSuppress(u16DtcRef) == (boolean)TRUE))
    	{
    		ret = DEM_GET_FFDATABYDTC_WRONG_DTC;
    	}
    	else if(NULL_PTR == Dem_GetMemInfoByOrigin(DTCOrigin))
    	{
    		ret = DEM_GET_FFDATABYDTC_WRONG_DTCORIGIN;
    	}
    	else if((boolean)FALSE == Dem_FFRecNumCheck(u16DtcRef,RecordNumber))
    	{
    		ret = DEM_GET_FFDATABYDTC_WRONG_RECORDNUMBER;
    	}
    	else
    	{
    		ret = Dem_DcmGetFreezeFrameDataByDTCSubDeal(\
    				u16DtcRef,\
					DTCOrigin,\
					RecordNumber,\
					pDestBuffer,\
					pBufSize);
    	}
    }
#endif /* #if(DEM_FREEZE_FRAME_CLASS_NUM > 0) */
    return ret;
}

/**
 * @sid         	0x1f
 * @brief      		Dem_DcmGetSizeOfFreezeFrameByDTC
 * @details     	Gets the size of freeze frame data by DTC.
 *
 * @param[in]   	DTC: Diagnostic Trouble Code in UDS format.
 * @param[in]		DTCOrigin: If the Dem supports more than one event memory,this parameter is
 *                  used to select the source memory the DTCs shall be read from.
 * @param[in]		RecordNumber: This parameter is a unique identifier for a freeze frame record
 *                  as defined in ISO 15031-5 and ISO 14229-1.
 *
 * @param[out]		pSizeOfFreezeFrame: Number of bytes in the requested freeze frame record.
 *
 * @return      	Status of the operation to retrieve the size of freeze frame data.
 * @retval			DEM_GETSIZEBYDTC_OK: Size successfully returned.
 * @retval			DEM_GETSIZEBYDTC_WRONG_DTC: DTC value not existing (in UDS format).
 * @retval			DEM_GETSIZEBYDTC_WRONG_DTCORIGIN: Wrong DTC origin.
 * @retval			DEM_GET_GETSIZEBYDTC_WRONG_RECNUM: Record number is not supported by configuration
 *                  and therefore invalid.
 * @retval			DEM_GET_GETSIZEBYDTC_PENDING: The requested value is calculated asynchronously
 *                  and currently not available.The caller can retry later.
 */
FUNC(Dem_ReturnGetSizeOfDataByDTCType, DEM_CODE)Dem_DcmGetSizeOfFreezeFrameByDTC
(
    uint32 DTC,
    Dem_DTCOriginType DTCOrigin,
    uint8 RecordNumber,
    P2VAR(uint16,AUTOMATIC,DEM_CODE) pSizeOfFreezeFrame
)
{
	Dem_ReturnGetSizeOfDataByDTCType ret = DEM_GETSIZEBYDTC_WRONG_DTC;

#if(DEM_DTC_NUM > 0)
	uint16 u16DtcRef;

	if (Dem_InitState != DEM_STATE_INIT)
	{
#if (STD_ON == DEM_DEV_ERROR_DETECT)
		/**
		 * @req [SWS_Dem_00124] If development error detection is enabled and any instance calls
		 *      any Dem API, excluding Dem_ReportErrorStatus, Dem_ResetEventDebounceStatus and
		 *      Dem_GetVersionInfo, before the Dem was fully initialized, the Dem module shall set
		 *      the error code DEM_E_UNINIT.
		 *
		 * @req [SWS_Dem_00368] If development error detection is enabled and any instance calls
		 *      any Dem API, excluding Dem_ReportErrorStatus, Dem_ResetEventDebounceStatus and
		 *      Dem_GetVersionInfo, after Dem_Shutdown (refer to chapter 8.3.2.3) has been called,
		 *      the Dem module shall set the error code DEM_E_UNINIT until Dem_Init is called again.
		 */
    	DEM_DET_ERROR_REPORT(DEM_SID_DCMGETSIZEOFFREEZEFRAMEBYDTC,DEM_E_UNINIT);
#endif /* #if (STD_ON == DEM_DEV_ERROR_DETECT) */
    }
    else if (pSizeOfFreezeFrame == NULL_PTR)
    {
#if (STD_ON == DEM_DEV_ERROR_DETECT)
    	DEM_DET_ERROR_REPORT(DEM_SID_DCMGETSIZEOFFREEZEFRAMEBYDTC,DEM_E_PARAM_POINTER);
#endif /* #if (STD_ON == DEM_DEV_ERROR_DETECT) */
    }
#if(DEM_OBD_SUPPORT == DEM_OBD_NO_OBD_SUPPORT)
    else if(RecordNumber == 0x00u)
    {
#if (STD_ON == DEM_DEV_ERROR_DETECT)
    	DEM_DET_ERROR_REPORT(DEM_SID_DCMGETSIZEOFFREEZEFRAMEBYDTC,DEM_E_PARAM_POINTER);
#endif /* #if (STD_ON == DEM_DEV_ERROR_DETECT) */
    	ret = DEM_GET_FFDATABYDTC_WRONG_RECORDNUMBER;
    }
#endif /* #if(DEM_OBD_SUPPORT == DEM_OBD_NO_OBD_SUPPORT) */
    else
    {
    	u16DtcRef = Dem_GetDtcIndexByDtc(DTC,DEM_DTC_FORMAT_UDS);

    	if((u16DtcRef == 0xFFFFu) || (Dem_ISEnable_DTCSuppress(u16DtcRef) == (boolean)TRUE))
    	{
    		ret = DEM_GET_FFDATABYDTC_WRONG_DTC;
    	}
    	else if(NULL_PTR == Dem_GetMemInfoByOrigin(DTCOrigin))
    	{
    		ret = DEM_GET_FFDATABYDTC_WRONG_DTCORIGIN;
    	}
    	else if((RecordNumber != 0xFFu)
    			&&((boolean)FALSE == Dem_FFRecNumCheck(u16DtcRef,RecordNumber)))
    	{
    		ret = DEM_GET_FFDATABYDTC_WRONG_RECORDNUMBER;
    	}
    	else
    	{
#if((DEM_FREEZE_FRAME_CLASS_NUM > 0) && (DEM_MAX_NUMBER_FF_RECORDS > 0))

    		Dem_GetSizeOfFFByDTCSubDeal(RecordNumber,u16DtcRef,DTCOrigin,pSizeOfFreezeFrame);
			ret = DEM_GETSIZEBYDTC_OK;

#endif /* #if((DEM_FREEZE_FRAME_CLASS_NUM > 0) && (DEM_MAX_NUMBER_FF_RECORDS > 0)) */
    	}
    }
#endif /* #if(DEM_DTC_NUM > 0) */

    return ret;
}

/**
 * @sid         	0x20
 * @brief      		Dem_DcmGetExtendedDataRecordByDTC
 * @details     	Gets extended data by DTC.The function stores the data in the provided DestBuffer.
 *
 * @param[in]   	DTC: Diagnostic Trouble Code in UDS format.
 * @param[in] 		DTCOrigin: If the Dem supports more than one event memory,this parameter is used
 *                  to select the source memory the DTCs shall be read from.
 * @param[in] 		ExtendedDataNumber: Identification/Number of requested extended data record.The
 *                  values 0xFE and 0xFF are not allowed.
 *
 * @param[out]		pDestBuffer: This parameter contains a byte pointer that points to the buffer,to
 *                  which the extended data record shall be written to.
 *
 * @Param[inout]	pBufSize: When the function is called this parameter contains the maximum number
 *                  of data bytes that can be written to the buffer.
 *
 * @return      	Status of the operation to retrieve extended data by DTC.
 * @retval			DEM_RECORD_WRONG_DTC: DTC value not existing (in UDS format).
 * @retval			DEM_RECORD_WRONG_DTCORIGIN: Origin wrong.
 * @retval			DEM_RECORD_WRONG_NUMBER: Record number is not supported by configuration and
 *                  therefore invalid.
 * @retval			DEM_RECORD_WRONG_BUFFERSIZE: Provided buffer to small.
 * @retval			DEM_RECORD_PENDING: The requested value is calculated asynchronously and currently
 *                  not available.The caller can retry later.
 */
FUNC(Dem_ReturnGetExtendedDataRecordByDTCType, DEM_CODE)Dem_DcmGetExtendedDataRecordByDTC
(
    uint32 DTC,
    Dem_DTCOriginType DTCOrigin,
    uint8 ExtendedDataNumber,
    P2VAR(uint8, AUTOMATIC, DEM_CODE) pDestBuffer,
	P2VAR(uint16, AUTOMATIC, DEM_CODE) pBufSize
)
{
#if(DEM_EXTENDED_DATA_CLASS_NUM > 0)
	uint16 u16DtcRef;
	Dem_ReturnGetExtendedDataRecordByDTCType ret = DEM_RECORD_WRONG_DTC;

    if (Dem_InitState != DEM_STATE_INIT)
    {
#if (STD_ON == DEM_DEV_ERROR_DETECT)
    	/**
		 * @req [SWS_Dem_00124] If development error detection is enabled and any instance calls
		 *      any Dem API, excluding Dem_ReportErrorStatus, Dem_ResetEventDebounceStatus and
		 *      Dem_GetVersionInfo, before the Dem was fully initialized, the Dem module shall set
		 *      the error code DEM_E_UNINIT.
		 *
		 * @req [SWS_Dem_00368] If development error detection is enabled and any instance calls
		 *      any Dem API, excluding Dem_ReportErrorStatus, Dem_ResetEventDebounceStatus and
		 *      Dem_GetVersionInfo, after Dem_Shutdown (refer to chapter 8.3.2.3) has been called,
		 *      the Dem module shall set the error code DEM_E_UNINIT until Dem_Init is called again.
		 */
    	DEM_DET_ERROR_REPORT(DEM_SID_DCMGETEXTENDEDDATARECORDBYDTC,DEM_E_UNINIT);
#endif /* #if (STD_ON == DEM_DEV_ERROR_DETECT) */
    }
    else if ((pDestBuffer == NULL_PTR) || (pBufSize == NULL_PTR))
    {
#if (STD_ON == DEM_DEV_ERROR_DETECT)
    	DEM_DET_ERROR_REPORT(DEM_SID_DCMGETEXTENDEDDATARECORDBYDTC,DEM_E_PARAM_POINTER);
#endif /* #if (STD_ON == DEM_DEV_ERROR_DETECT) */
    }
    else if (ExtendedDataNumber >= 0xFEu)
    {
#if (STD_ON == DEM_DEV_ERROR_DETECT)
    	/*The values 0xFE and 0xFF are not allowed.*/
    	DEM_DET_ERROR_REPORT(DEM_SID_DCMGETEXTENDEDDATARECORDBYDTC,DEM_E_PARAM_DATA);
#endif /* #if (STD_ON == DEM_DEV_ERROR_DETECT) */
    	ret = DEM_RECORD_WRONG_NUMBER;
    }
    else
    {
    	u16DtcRef = Dem_GetDtcIndexByDtc(DTC,DEM_DTC_FORMAT_UDS);

    	if((u16DtcRef == 0xFFFFu) || (Dem_ISEnable_DTCSuppress(u16DtcRef) == (boolean)TRUE))
    	{
    		ret = DEM_GET_FFDATABYDTC_WRONG_DTC;
    	}
    	else if(NULL_PTR == Dem_GetMemInfoByOrigin(DTCOrigin))
    	{
    		ret = DEM_GET_FFDATABYDTC_WRONG_DTCORIGIN;
    	}
    	else if((boolean)FALSE == Dem_ExtRecNumCheck(u16DtcRef,ExtendedDataNumber))
    	{
    		ret = DEM_GETSIZEBYDTC_WRONG_RECNUM;
    	}
    	else
    	{
			ret = Dem_DcmGetExtendedDataRecordByDTCSubDeal(\
					u16DtcRef,\
					DTCOrigin,\
					ExtendedDataNumber,\
					pDestBuffer,\
					pBufSize);
    	}
    }
    return ret;
#else
    return DEM_RECORD_OK;
#endif
}

/**
 * @sid         	0x21
 * @brief      		Dem_DcmGetSizeOfExtendedDataRecordByDTC
 * @details     	Gets the size of extended data by DTC.
 *
 * @param[in]   	DTC: Diagnostic Trouble Code in UDS format.
 * @param[in]		DTCOrigin: If the Dem supports more than one event memory, this parameter is used
 *                  to select the source memory the DTCs shall be read from.
 * @param[in]		ExtendedDataNumber: Identification/Number of requested extended data record.
 *
 * @param[out]		pSizeOfExtendedDataRecord: Size of the requested extended data record(s) including
 *                  record number size.
 *
 * @return      	Status of the operation to retrieve the size of extended data.
 * @retval			DEM_GETSIZEBYDTC_OK: Size successfully returned
 * @retval			DEM_GETSIZEBYDTC_WRONG_DTC: DTC value not existing (in UDS format)
 * @retval			DEM_GETSIZEBYDTC_WRONG_DTCORIGIN: Wrong DTC origin
 * @retval			DEM_GETSIZEBYDTC_WRONG_RECNUM: Record number is not supported by configuration
 *                  and therefore invalid.
 * @retval			DEM_GETSIZEBYDTC_PENDING: The requested value is calculated asynchronously and
 *                  currently not available.The caller can retry later.
 */
FUNC(Dem_ReturnGetSizeOfDataByDTCType, DEM_CODE)Dem_DcmGetSizeOfExtendedDataRecordByDTC
(
    uint32 DTC,
    Dem_DTCOriginType DTCOrigin,
    uint8 ExtendedDataNumber,
    P2VAR(uint16, AUTOMATIC, DEM_CODE) pSizeOfExtendedDataRecord
)
{
#if(DEM_EXTENDED_DATA_CLASS_NUM > 0)
	uint16 u16DtcRef;

	Dem_ReturnGetSizeOfDataByDTCType ret = DEM_GETSIZEBYDTC_WRONG_DTC;

    if (Dem_InitState != DEM_STATE_INIT)
    {
#if (STD_ON == DEM_DEV_ERROR_DETECT)
    	/**
		 * @req [SWS_Dem_00124] If development error detection is enabled and any instance calls
		 *      any Dem API, excluding Dem_ReportErrorStatus, Dem_ResetEventDebounceStatus and
		 *      Dem_GetVersionInfo, before the Dem was fully initialized, the Dem module shall set
		 *      the error code DEM_E_UNINIT.
		 *
		 * @req [SWS_Dem_00368] If development error detection is enabled and any instance calls
		 *      any Dem API, excluding Dem_ReportErrorStatus, Dem_ResetEventDebounceStatus and
		 *      Dem_GetVersionInfo, after Dem_Shutdown (refer to chapter 8.3.2.3) has been called,
		 *      the Dem module shall set the error code DEM_E_UNINIT until Dem_Init is called again.
		 */
    	DEM_DET_ERROR_REPORT(DEM_SID_DCMGETSIZEOFEXTENDEDDATARECORDBYDTC,DEM_E_UNINIT);
#endif /* #if (STD_ON == DEM_DEV_ERROR_DETECT) */
    }
    else if (pSizeOfExtendedDataRecord == NULL_PTR)
    {
#if (STD_ON == DEM_DEV_ERROR_DETECT)
    	DEM_DET_ERROR_REPORT(DEM_SID_DCMGETSIZEOFEXTENDEDDATARECORDBYDTC,DEM_E_PARAM_POINTER);
#endif /* #if (STD_ON == DEM_DEV_ERROR_DETECT) */
    }
    else
    {
    	u16DtcRef = Dem_GetDtcIndexByDtc(DTC,DEM_DTC_FORMAT_UDS);

    	if((u16DtcRef == 0xFFFFu) || (Dem_ISEnable_DTCSuppress(u16DtcRef) == (boolean)TRUE))
    	{
    		ret = DEM_GET_FFDATABYDTC_WRONG_DTC;
    	}
    	else if(NULL_PTR == Dem_GetMemInfoByOrigin(DTCOrigin))
    	{
    		ret = DEM_GET_FFDATABYDTC_WRONG_DTCORIGIN;
    	}
    	else if((ExtendedDataNumber < 0xFEu)
    			&&((boolean)FALSE == Dem_ExtRecNumCheck(u16DtcRef,ExtendedDataNumber)))
    	{
    		ret = DEM_GETSIZEBYDTC_WRONG_RECNUM;
    	}
    	else
    	{
			Dem_DcmGetSizeOfExtendedDataRecordSubDeal(\
					u16DtcRef,\
					DTCOrigin,\
					ExtendedDataNumber,\
					pSizeOfExtendedDataRecord);
			ret = DEM_GETSIZEBYDTC_OK;
		}
	}
    return ret;
#else
    return DEM_GETSIZEBYDTC_OK;
#endif
}

/**
 * @sid         	0x7b
 * @brief      		Dem_DcmCheckClearParameter
 * @details     	Performs a parameter check and gives the result which would also be returned by
 *                  calling clear with same parameters.
 *
 * @param[in]   	DTC: Diagnostic Trouble Code in UDS format.
 * @param[in] 		DTCOrigin: If the Dem supports more than one event memory, this parameter is used
 * 					to select the source memory the DTCs shall be read from.
 * @param[in] 		DTCFormat: Defines the input-format of the provided DTC value.
 *
 * @return      	Returns the result of the parameter check when performing a clear command with
 *                  same parameters (refer to Dem_DcmClearDTC).
 * @retval			DEM_CLEAR_OK: DTC successfully cleared.
 * @retval			DEM_CLEAR_WRONG_DTC: DTC value not existing (in this format).
 * @retval			DEM_CLEAR_WRONG_DTCORIGIN: Wrong DTC origin.
 * @retval			DEM_CLEAR_FAILED: In case of general errors with clear parameters.
 * @retval			DEM_CLEAR_PENDING: The DTC clearing is performed asynchronously and still pending.
 *                  The caller can retry later.
 * @retval			DEM_CLEAR_BUSY: DTC not cleared, as another clearing process is in progress. The
 *                  caller can retry later.
 * @retval			DEM_CLEAR_MEMORY_ERROR: An error occurred during erasing a memory location.
 */
FUNC(Dem_ReturnClearDTCType, DEM_CODE)Dem_DcmCheckClearParameter
(
	uint32 DTC,
    Dem_DTCFormatType DTCFormat,
    Dem_DTCOriginType DTCOrigin
)
{
    Dem_ReturnClearDTCType ret = DEM_CLEAR_FAILED;
#if(DEM_DTC_NUM > 0)
    uint16 u16Loop;
#endif /* #if(DEM_DTC_NUM > 0) */

#if (STD_ON == DEM_DEV_ERROR_DETECT)
    if (Dem_InitState != DEM_STATE_INIT)
    {
    	/**
		 * @req [SWS_Dem_00124] If development error detection is enabled and any instance calls
		 *      any Dem API, excluding Dem_ReportErrorStatus, Dem_ResetEventDebounceStatus and
		 *      Dem_GetVersionInfo, before the Dem was fully initialized, the Dem module shall set
		 *      the error code DEM_E_UNINIT.
		 *
		 * @req [SWS_Dem_00368] If development error detection is enabled and any instance calls
		 *      any Dem API, excluding Dem_ReportErrorStatus, Dem_ResetEventDebounceStatus and
		 *      Dem_GetVersionInfo, after Dem_Shutdown (refer to chapter 8.3.2.3) has been called,
		 *      the Dem module shall set the error code DEM_E_UNINIT until Dem_Init is called again.
		 */
    	DEM_DET_ERROR_REPORT(DEM_SID_DCMCHECKCLEARPARAMETER,DEM_E_UNINIT);
    }
    else
#endif /* #if (STD_ON == DEM_DEV_ERROR_DETECT) */
    {
    	if((DTCOrigin == DEM_DTC_ORIGIN_PRIMARY_MEMORY)
#if(DEM_MIRROR_MEMORY_NUM > 0)
    		|| (DTCOrigin == DEM_DTC_ORIGIN_MIRROR_MEMORY)
#endif /* #if(DEM_MIRROR_MEMORY_NUM > 0) */
		)
    	{
    		if((DTC == 0xFFFFFFu)
#if(DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT)
    			|| (DTC == 0xFFFF33u)
#endif /* #if(DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT) */
    		)
    		{
    			ret = (Dem_ReturnClearDTCType)DEM_CLEAR_OK;
    		}
    		else
    		{
    			ret = (Dem_ReturnClearDTCType)DEM_CLEAR_WRONG_DTC;
#if(DEM_DTC_NUM > 0)
				for(u16Loop = 0u; u16Loop < DEM_DTC_NUM; u16Loop++)
				{
					if(DTCFormat == DEM_DTC_FORMAT_UDS)
					{
						if(Dem_ConfigPtr->DemDTC[u16Loop].DemDtcValue == DTC)
						{
							ret = (Dem_ReturnClearDTCType)DEM_CLEAR_OK;
							break;
						}
					}
#if(DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT)
					else if(DTCFormat == DEM_DTC_FORMAT_OBD)
					{
						if(Dem_ConfigPtr->DemDTC[u16Loop].DemObdDTCRef != 0xFFFFu)
						{
							if(Dem_ConfigPtr->DemObdDTC[Dem_ConfigPtr->DemDTC[u16Loop].DemObdDTCRef].\
									DemDtcValue == DTC)
							{
								ret = (Dem_ReturnClearDTCType)DEM_CLEAR_OK;
								break;
							}
						}
					}
#endif /* #if(DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT) */
#if(DEM_J1939_SUPPORT == STD_ON)
					else if(DTCFormat == DEM_DTC_FORMAT_J1939)/* DEM_DTC_FORMAT_J1939 */
					{
						if(Dem_ConfigPtr->DemObdDTC[Dem_ConfigPtr->DemDTC[u16Loop].DemObdDTCRef].\
								DemJ1939DTCValue == DTC)
						{
							ret = (Dem_ReturnClearDTCType)DEM_CLEAR_OK;
							break;
						}
					}
#endif /* #if(DEM_J1939_SUPPORT == STD_ON) */
				}
#endif /* #if(DEM_DTC_NUM > 0) */
    		}
    	}
    	else
    	{
    		if(DTCOrigin == DEM_DTC_ORIGIN_PERMANENT_MEMORY)
    		{
    			ret = (Dem_ReturnClearDTCType)DEM_CLEAR_WRONG_DTCORIGIN;
    		}
    	}
    }
    return ret;
}

/**
 * @sid         	0x22
 * @brief      		Dem_DcmClearDTC
 * @details     	Clears single DTCs, as well as groups of DTCs.This API is intended for the Dcm.
 *                  It can only be used through the RTE,and therefore no declaration is exported via
 *                  Dem_Dcm.h.
 *
 * @param[in]   	DTC: Diagnostic Trouble Code in UDS format.
 * @param[in]		DTCOrigin: If the Dem supports more than one event memory, this parameter is used
 *                  to select the source memory the DTCs shall be read from.
 * @param[in]		DTCFormat: Defines the input-format of the provided DTC value.
 *
 * @return      	Status of the operation of type Dem_ReturnClearDTCType.
 * @retval			DEM_CLEAR_OK: DTC successfully cleared.
 * @retval			DEM_CLEAR_WRONG_DTC: DTC value not existing (in this format).
 * @retval			DEM_CLEAR_WRONG_DTCORIGIN: Wrong DTC origin.
 * @retval			DEM_CLEAR_FAILED: In case of general errors with clear parameters.
 * @retval			DEM_CLEAR_PENDING: The DTC clearing is performed asynchronously and still pending.
 *                  The caller can retry later.
 * @retval			DEM_CLEAR_BUSY: DTC not cleared, as another clearing process is in progress.
 *                  The caller can retry later.
 * @retval			DEM_CLEAR_MEMORY_ERROR: An error occurred during erasing a memory location.
 */
FUNC(Dem_ReturnClearDTCType, DEM_CODE)Dem_DcmClearDTC
(
    uint32 DTC,
    Dem_DTCFormatType DTCFormat,
    Dem_DTCOriginType DTCOrigin
)
{
#if(DEM_DTC_NUM > 0)
    Dem_ReturnClearDTCType ret = DEM_CLEAR_PENDING;

    if (Dem_InitState != DEM_STATE_INIT)
    {
#if (STD_ON == DEM_DEV_ERROR_DETECT)
    	/**
		 * @req [SWS_Dem_00124] If development error detection is enabled and any instance calls
		 *      any Dem API, excluding Dem_ReportErrorStatus, Dem_ResetEventDebounceStatus and
		 *      Dem_GetVersionInfo, before the Dem was fully initialized, the Dem module shall set
		 *      the error code DEM_E_UNINIT.
		 *
		 * @req [SWS_Dem_00368] If development error detection is enabled and any instance calls
		 *      any Dem API, excluding Dem_ReportErrorStatus, Dem_ResetEventDebounceStatus and
		 *      Dem_GetVersionInfo, after Dem_Shutdown (refer to chapter 8.3.2.3) has been called,
		 *      the Dem module shall set the error code DEM_E_UNINIT until Dem_Init is called again.
		 */
    	DEM_DET_ERROR_REPORT(DEM_SID_DCMCLEARDTC,DEM_E_UNINIT);
#endif /* #if (STD_ON == DEM_DEV_ERROR_DETECT) */
    }
    else
    {
#if(DEM_CLEARDTC_LIMITATION == DEM_ONLY_CLEAR_ALL_DTCS)
    	if((DTCFormat != DEM_DTC_FORMAT_UDS) || ((DTC & 0xFFFFFFu) != 0xFFFFFFu))
    	{
    		/**
    		 * @req [SWS_Dem_00670] If the configuration parameter DemClearDTCLimitation
    		 *      is set to DEM_ONLY_CLEAR_ALL_DTCS, the APIs Dem_<...>ClearDTC shall
    		 *      only accept the DTC group DEM_DTC_GROUP_ALL_DTCS for UDS (DTCFormat
    		 *      equals DEM_DTC_FORMAT_UDS) and shall return DEM_CLEAR_WRONG_DTC in
    		 *      case any other DTC group or DTC value is requested.
    		 */
    		ret =  DEM_CLEAR_WRONG_DTC;
    	}
    	else
#endif /* #if(DEM_CLEARDTC_LIMITATION == DEM_ONLY_CLEAR_ALL_DTCS) */
    	{
			if((NULL_PTR != Dem_GetMemInfoByOrigin(DTCOrigin)) \
					&& (DTCOrigin != DEM_DTC_ORIGIN_PERMANENT_MEMORY))
			{
				if(Dem_ClearDtcLock == (boolean)FALSE)
				{
					/**
					 * @req [SWS_Dem_00661] The first call of any Dem_<...>ClearDTC API
					 *      (e.g. Dem_ClearDTC) while the clearing process is not locked
					 *      shall lock the clearing process for all other callers.
					 */
					Dem_ClearDtcLock = (boolean)TRUE;
					Dem_ClearDtcInfo.DTC = DTC;
					Dem_ClearDtcInfo.DTCOrigin = DTCOrigin;
					Dem_ClearDtcInfo.DTCFormat = DTCFormat;

					if(DTCFormat == DEM_DTC_FORMAT_UDS)
					{
						ret = Dem_DcmClearUDSDtc(DTC,DTCFormat,DTCOrigin);
						Dem_ClearDtcLock = (boolean)FALSE;
					}
#if((DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT) && (DEM_OBD_DTC_NUM > 0u))
					else if(DTCFormat == DEM_DTC_FORMAT_OBD)
					{
						ret = Dem_DcmClearOBDDtc();
						Dem_ClearDtcLock = (boolean)FALSE;
					}
#endif /* #if((DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT) && (DEM_OBD_DTC_NUM > 0u)) */
					else
					{
						ret = DEM_CLEAR_FAILED;
					}
				}
				else
				{
					if((Dem_ClearDtcInfo.DTC == DTC)\
							&&(Dem_ClearDtcInfo.DTCOrigin == DTCOrigin)\
							&&(Dem_ClearDtcInfo.DTCFormat == DTCFormat))
					{
						/**
						 * @req [SWS_Dem_00663] If the clearing process is locked, any subsequent call
						 *      of the same Dem_<...>ClearDTC API with the same set of parameters shall
						 *      either return DEM_CLEAR_PENDING while DTC clearing is in progress, or
						 *      return DEM_CLEAR_OK in case DTC clearing has finished with no errors.
						 */
						ret = DEM_CLEAR_PENDING;
					}
					else
					{
						/**
						 * @req [SWS_Dem_00662] Any call of a Dem_<...>ClearDTC API while the clearing
						 *      process is locked by another instance shall return DEM_CLEAR_BUSY.
						 *
						 * @req [SWS_Dem_00664] If the clearing process is locked, any subsequent call
						 *      of any Dem_<...>ClearDTC API with a different set of parameters shall
						 *      return DEM_CLEAR_BUSY.
						 */
						ret = DEM_CLEAR_BUSY;
					}
				}
			}
			else
			{
				/**
				 * @req [SWS_Dem_00171] If the Dcm has requested an unavailable event memory/DTC
				 *      origin, the Dem module functions with the respective return value shall
				 *      return DEM_<...>_WRONG_DTCORIGIN.
				 */
				ret = DEM_CLEAR_WRONG_DTCORIGIN;
			}
    	}
    }
    return ret;
#else /* #if(DEM_DTC_NUM > 0) */
    return DEM_CLEAR_OK;
#endif /* #if(DEM_DTC_NUM > 0) */
}

/**
 * @sid         	0x24
 * @brief      		Dem_DcmDisableDTCSetting
 * @details     	Disables the DTC setting for a DTC group.
 *
 * @param[in]   	DTCGroup: Defines the group of DTC that shall be disabled to store in event memory.
 * @param[in]		DTCKind: This parameter defines the requested DTC kind, either only OBD-relevant
 *                  DTCs or all DTCs
 *
 * @return      	Returns status of the operation.
 * @retval			DEM_CONTROL_DTC_SETTING_OK: DTC setting control successful.
 * @retval			DEM_CONTROL_DTC_SETTING_N_OK: DTC setting control not successful.
 * @retval			DEM_CONTROL_DTC_WRONG_DTCGROUP: DTC setting control not successful because group
 *                  of DTC was wrong.
 */
FUNC(Dem_ReturnControlDTCSettingType, DEM_CODE)Dem_DcmDisableDTCSetting
(
    uint32 DTCGroup,
    Dem_DTCKindType DTCKind
)
{
	Dem_ReturnControlDTCSettingType ret = DEM_CONTROL_DTC_SETTING_N_OK;

#if(DEM_DTC_NUM > 0)
	uint8 u8DTCSetting;
#if(DEM_GROUP_OF_DTC_NUM > 0)
	uint8 u8DtcGroupIndex;
#endif /* #if(DEM_GROUP_OF_DTC_NUM > 0) */

    if (Dem_InitState != DEM_STATE_INIT)
    {
#if (STD_ON == DEM_DEV_ERROR_DETECT)
    	/**
		 * @req [SWS_Dem_00124] If development error detection is enabled and any instance calls
		 *      any Dem API, excluding Dem_ReportErrorStatus, Dem_ResetEventDebounceStatus and
		 *      Dem_GetVersionInfo, before the Dem was fully initialized, the Dem module shall set
		 *      the error code DEM_E_UNINIT.
		 *
		 * @req [SWS_Dem_00368] If development error detection is enabled and any instance calls
		 *      any Dem API, excluding Dem_ReportErrorStatus, Dem_ResetEventDebounceStatus and
		 *      Dem_GetVersionInfo, after Dem_Shutdown (refer to chapter 8.3.2.3) has been called,
		 *      the Dem module shall set the error code DEM_E_UNINIT until Dem_Init is called again.
		 */
    	DEM_DET_ERROR_REPORT(DEM_SID_DCMDISABLEDTCSETTING,DEM_E_UNINIT);
#endif /* #if (STD_ON == DEM_DEV_ERROR_DETECT) */
    }
    else
    {
    	ret = DEM_CONTROL_DTC_SETTING_OK;

    	if((DTCGroup & 0xFFFFFFu) == 0xFFFFFFu)
    	{
    		u8DTCSetting = 1u;

#if(DEM_GROUP_OF_DTC_NUM > 0)
    		DEM_VALUE_SET(Dem_DtcGroupSettingStatus,0x00u,DEM_GROUP_OF_DTC_NUM_BYTE);
#endif /* #if(DEM_GROUP_OF_DTC_NUM > 0) */

    	}
#if(DEM_GROUP_OF_DTC_NUM > 0)
    	else
    	{
    		u8DtcGroupIndex = Dem_GetDTCGroupIndex(DTCGroup);

    		if(u8DtcGroupIndex == DEM_GROUP_OF_DTC_NUM)
    		{
    			ret = DEM_CONTROL_DTC_WRONG_DTCGROUP;
    		}
    		else
    		{
    			Dem_Disable_GroupDTC(u8DtcGroupIndex);
    		}
    	}
#else
    	else
    	{
#if (STD_ON == DEM_DEV_ERROR_DETECT)
    		DEM_DET_ERROR_REPORT(DEM_SID_DCMDISABLEDTCSETTING,DEM_E_WRONG_CONFIGURATION);
#endif /* #if (STD_ON == DEM_DEV_ERROR_DETECT) */
    		ret = DEM_CONTROL_DTC_SETTING_N_OK;
    	}
#endif /* #if(DEM_GROUP_OF_DTC_NUM > 0) */

    	if(ret == DEM_CONTROL_DTC_SETTING_OK)
    	{
    		Dem_DTCSettingDeal(u8DTCSetting,DTCKind);
    	}
    }
#else
	ret = DEM_CONTROL_DTC_SETTING_OK;
#endif /* #if(DEM_DTC_NUM > 0) */
    return ret;
}

/**
 * @sid         	0x25
 * @brief      		Dem_DcmEnableDTCSetting
 * @details     	Enables the DTC setting for a DTC group.
 *
 * @param[in]   	DTCGroup: Defines the group of DTC that shall be enable to store in event memory.
 * @param[in]		DTCKind: This parameter defines the requested DTC kind, either only OBD-relevant
 *                  DTCs or all DTCs.
 *
 * @return      	Returns status of the operation
 * @retval			DEM_CONTROL_DTC_SETTING_OK: DTC setting control successful.
 * @retval			DEM_CONTROL_DTC_SETTING_N_OK: DTC setting control not successful.
 * @retval			DEM_CONTROL_DTC_WRONG_DTCGROUP: DTC setting control not successful because group
 *                  of DTC was wrong.
 */
FUNC(Dem_ReturnControlDTCSettingType, DEM_CODE)Dem_DcmEnableDTCSetting
(
    uint32 DTCGroup,
    Dem_DTCKindType DTCKind
)
{
	Dem_ReturnControlDTCSettingType ret = DEM_CONTROL_DTC_SETTING_N_OK;

#if(DEM_DTC_NUM > 0)
	uint8 u8DTCSetting;
#if(DEM_GROUP_OF_DTC_NUM > 0)
	uint8 u8DtcGroupIndex;
#endif /* #if(DEM_GROUP_OF_DTC_NUM > 0) */

    if (Dem_InitState != DEM_STATE_INIT)
    {
#if (STD_ON == DEM_DEV_ERROR_DETECT)
    	/**
		 * @req [SWS_Dem_00124] If development error detection is enabled and any instance calls
		 *      any Dem API, excluding Dem_ReportErrorStatus, Dem_ResetEventDebounceStatus and
		 *      Dem_GetVersionInfo, before the Dem was fully initialized, the Dem module shall set
		 *      the error code DEM_E_UNINIT.
		 *
		 * @req [SWS_Dem_00368] If development error detection is enabled and any instance calls
		 *      any Dem API, excluding Dem_ReportErrorStatus, Dem_ResetEventDebounceStatus and
		 *      Dem_GetVersionInfo, after Dem_Shutdown (refer to chapter 8.3.2.3) has been called,
		 *      the Dem module shall set the error code DEM_E_UNINIT until Dem_Init is called again.
		 */
    	DEM_DET_ERROR_REPORT(DEM_SID_DCMENABLEDTCSETTING,DEM_E_UNINIT);
#endif /* #if (STD_ON == DEM_DEV_ERROR_DETECT) */
    }
    else
    {
    	ret = DEM_CONTROL_DTC_SETTING_OK;

    	if((DTCGroup & 0xFFFFFFu) == 0xFFFFFFu)
    	{
    		u8DTCSetting = 2u;

#if(DEM_GROUP_OF_DTC_NUM > 0)
    		DEM_VALUE_SET(Dem_DtcGroupSettingStatus,0xFFu,DEM_GROUP_OF_DTC_NUM_BYTE);
#endif /* #if(DEM_GROUP_OF_DTC_NUM > 0) */

    	}
#if(DEM_GROUP_OF_DTC_NUM > 0)
    	else
    	{
    		u8DtcGroupIndex = Dem_GetDTCGroupIndex(DTCGroup);

    		if(u8DtcGroupIndex == DEM_GROUP_OF_DTC_NUM)
    		{
    			ret = DEM_CONTROL_DTC_WRONG_DTCGROUP;
    		}
    		else
    		{
    			Dem_Enable_GroupDTC(u8DtcGroupIndex);
    		}
    	}
#else
    	else
    	{
#if (STD_ON == DEM_DEV_ERROR_DETECT)
    		DEM_DET_ERROR_REPORT(DEM_SID_DCMENABLEDTCSETTING,DEM_E_WRONG_CONFIGURATION);
#endif /* #if (STD_ON == DEM_DEV_ERROR_DETECT) */
    		ret = DEM_CONTROL_DTC_SETTING_N_OK;
    	}
#endif /* #if(DEM_GROUP_OF_DTC_NUM > 0) */

    	if(ret == DEM_CONTROL_DTC_SETTING_OK)
    	{
    		Dem_DTCSettingDeal(u8DTCSetting,DTCKind);
    	}
    }
#else
	ret = DEM_CONTROL_DTC_SETTING_OK;
#endif /* #if(DEM_DTC_NUM > 0) */
    return ret;
}

FUNC(void, DEM_CODE) Dem_DcmInit
(
	void
)
{
#if(DEM_DTC_NUM > 0)
	Dem_ClearDtcInfo.DTC 					 = 0xFFFFFFFFu;
	Dem_ClearDtcInfo.DTCFormat 				 = 0xFFu;
	Dem_ClearDtcInfo.DTCOrigin 				 = 0xFFu;
#endif /* #if(DEM_DTC_NUM > 0) */

#if(DEM_FREEZE_FRAME_CLASS_NUM > 0)
	Dem_FFRecFilter.AlreadyGetNum    			 = 0u;
	Dem_FFRecFilter.CurrentEntry     			 = 0u;
	Dem_FFRecFilter.CurrentFF        			 = 0u;
	Dem_FFRecFilter.DTCFormat        			 = 0xFFu;
	Dem_FFRecFilter.NumberOfFilteredRecords      = 0u;
#endif /* #if(DEM_FREEZE_FRAME_CLASS_NUM > 0) */

#if(DEM_DTC_NUM > 0)
	Dem_DTCFilter.DTCFormat						 = 0xFFu;
	Dem_DTCFilter.DTCKind					 	 = 0xFFu;
	Dem_DTCFilter.DTCOrigin						 = 0xFFu;
	Dem_DTCFilter.DTCSeverityMask				 = 0xFFu;
	Dem_DTCFilter.DTCStatusMask					 = 0xFFu;
	Dem_DTCFilter.FilterForFaultDetectionCounter = (boolean)FALSE;
	Dem_DTCFilter.FilterSet						 = (boolean)FALSE;
	Dem_DTCFilter.FilterWithSeverity			 = (boolean)FALSE;
	Dem_DTCFilter.ReadIndex						 = 0xFFFFu;
#if(DEM_RESSET_CONFIRMEDBIT_ONOVERFLOW == STD_ON)
	Dem_DTCFilter.TimeOrder						 = (boolean)FALSE;
	Dem_DTCFilter.AbsTime						 = 0xFFu;

	/* PRQA S 2877 ++ #violate MISAR2004_21.1: If DEM_ENABLE_CONDITION_NUM_BYTE
	 * is bigger than 1 this loop will be executed more than once. */
	DEM_VALUE_SET(Dem_DTCFilter.DTCFilterRecord,0u,DEM_DTC_NUM_BYTE);
	/* PRQA S 2877 -- */

#endif /* #if(DEM_RESSET_CONFIRMEDBIT_ONOVERFLOW == STD_ON) */
#endif /* #if(DEM_DTC_NUM > 0) */

	Dem_EventOccTime.firstConfEvent				 = 0xFFFFu;
	Dem_EventOccTime.firstFailEvent 			 = 0xFFFFu;
	Dem_EventOccTime.mostConfEvent 				 = 0xFFFFu;
	Dem_EventOccTime.mostFailEvent 				 = 0xFFFFu;

#if(DEM_GROUP_OF_DTC_NUM > 0)
	DEM_VALUE_SET(Dem_DtcGroupSettingStatus,0xFFu,DEM_GROUP_OF_DTC_NUM_BYTE);
#endif /* #if(DEM_GROUP_OF_DTC_NUM > 0) */
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

#endif /* #if(DEM_DCM_ENABLE == STD_ON) */

#ifdef __cplusplus
}
#endif
/** @} */


