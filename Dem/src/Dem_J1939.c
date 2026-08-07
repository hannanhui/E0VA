/* PRQA S 0292 EOF */
/**
 * @file        Dem_J1939.c
 * @brief       AUTOSAR Dem  -Dem module source file.
 * @details     Dem module source file, containing the C implementation of Autosar API specification
 *              and other variables and functions that are provided for J1939Dcm.
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
/* PRQA S 0857 EOF #
 * @page misra_violations MISRA-C:2004 violations
 */
/*====================================================================================================*
 *                                           INCLUDE FILES
 *====================================================================================================*/
#include "Dem_Internal.h"

#ifdef AH_TEST_DEM
#include "TestCode.h"
#endif /* #ifdef AH_TEST_DEM */
/*====================================================================================================*
 *                                  SOURCE FILE VERSION INFORMATION
 *====================================================================================================*/
#if(DEM_J1939_SUPPORT == STD_ON)

#define DEM_J1939DCM_VENDOR_ID_C               					(0U)
#define DEM_J1939DCM_AR_RELEASE_MAJOR_VERSION_C      			(4U)
#define DEM_J1939DCM_AR_RELEASE_MINOR_VERSION_C      			(2U)
#define DEM_J1939DCM_AR_RELEASE_REVISION_VERSION_C      		(2U)
#define DEM_J1939DCM_SW_MAJOR_VERSION_C      					(1U)
#define DEM_J1939DCM_SW_MINOR_VERSION_C      					(2U)
#define DEM_J1939DCM_SW_PATCH_VERSION_C      					(0U)

/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/
/* Check if current file and Dem_Internal.h header file are of the same vendor */
#if(DEM_J1939DCM_VENDOR_ID_C != DEM_INTERNAL_VENDOR_ID )
#error "Dem_J1939.c and Dem_Internal.h have different vendor id"
#endif /* #if(DEM_VENDOR_ID_C != DEM_INTERNAL_VENDOR_ID ) */

/* Check if current file and Dem_Internal.h header file are of the same Autosar version */
#if(\
		(DEM_J1939DCM_AR_RELEASE_MAJOR_VERSION_C != DEM_INTERNAL_AR_RELEASE_MAJOR_VERSION) || \
		(DEM_J1939DCM_AR_RELEASE_MINOR_VERSION_C != DEM_INTERNAL_AR_RELEASE_MINOR_VERSION) || \
		(DEM_J1939DCM_AR_RELEASE_REVISION_VERSION_C != DEM_INTERNAL_AR_RELEASE_REVISION_VERSION) \
   )
#error "AutoSar Version Number of Dem_J1939.c and Dem_Internal.h are different "
#endif /* #if(\
				(DEM_AR_RELEASE_MAJOR_VERSION_C != DEM_INTERNAL_AR_RELEASE_MAJOR_VERSION) || \
				(DEM_AR_RELEASE_MINOR_VERSION_C != DEM_INTERNAL_AR_RELEASE_MINOR_VERSION) || \
				(DEM_AR_RELEASE_REVISION_VERSION_C != DEM_INTERNAL_AR_RELEASE_REVISION_VERSION) \
   	   	     ) */

/* Check if current file and Dem_Internal.h header file are of the same Software version */
#if(\
		(DEM_J1939DCM_SW_MAJOR_VERSION_C != DEM_INTERNAL_SW_MAJOR_VERSION) || \
		(DEM_J1939DCM_SW_MINOR_VERSION_C != DEM_INTERNAL_SW_MINOR_VERSION) || \
		(DEM_J1939DCM_SW_PATCH_VERSION_C != DEM_INTERNAL_SW_PATCH_VERSION) \
   )
#error "Software Version Number of Dem_J1939.c and Dem_Internal.h are different "
#endif /* #if(\
				(DEM_SW_MAJOR_VERSION_C != DEM_INTERNAL_SW_MAJOR_VERSION) || \
				(DEM_SW_MINOR_VERSION_C != DEM_INTERNAL_SW_MINOR_VERSION) || \
				(DEM_SW_PATCH_VERSION_C != DEM_INTERNAL_SW_PATCH_VERSION) \
   	   	   	 ) */

/*====================================================================================================*
 *                                   EXTERNAL FUNCTION DECLARATIONS
 *====================================================================================================*/

/* Add code here */

/*====================================================================================================*
 *                                           LOCAL TYPEDEFS
 *====================================================================================================*/

#if(DEM_J1939READINGDTC_SUPPORT == STD_ON)
typedef struct
{
	boolean FilterSet;
	uint8 u8Node;
	uint8 u8FilterIndex;
	Dem_DTCKindType DTCKind;
	Dem_DTCOriginType DTCOrigin;
	Dem_J1939DcmDTCStatusFilterType DTCStatusFilter;
}Dem_J1939DtcFilterType;
#endif /* #if(DEM_J1939READINGDTC_SUPPORT == STD_ON) */

#if(DEM_J1939DM31_SUPPORT == STD_ON)
typedef struct
{
	boolean FilterSet;
	uint8 u8Node;
	uint8 u8FilterIndex;
}Dem_J1939NodeFilterType;
#endif /* #if(DEM_J1939DM31_SUPPORT == STD_ON) */

#if((DEM_J1939FREEZEFRAME_SUPPORT == STD_ON) || (DEM_J1939EXPANDEDFREEZEFRAME_SUPPORT == STD_ON))
typedef struct
{
	boolean FilterSet;
	boolean IsNextFF;
	uint8 u8FilterIndex;
	uint8 u8Node;
	uint8 u8SPNConter;
	uint32 u32SPNIndex;
	Dem_J1939DcmSetFreezeFrameFilterType FFKind;
}Dem_J1939FFFilterType;
#endif /* #if((DEM_J1939FREEZEFRAME_SUPPORT == STD_ON) \
          || (DEM_J1939EXPANDEDFREEZEFRAME_SUPPORT == STD_ON)) */

#if((DEM_RATIO_NUM > 0) && (DEM_J1939RATIO_SUPPORT == STD_ON))
typedef struct
{
	boolean FilterSet;
	uint8 u8Node;
	uint8 u8FilterIndex;
}Dem_J1939RatioFilterType;
#endif /* #if((DEM_RATIO_NUM > 0) && (DEM_J1939RATIO_SUPPORT == STD_ON)) */

typedef struct
{
	Dem_J1939DcmSetClearFilterType DtcType;
	uint8 node;
}Dem_ClearJ1939DtcType;
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
 *                                           LOCAL CONSTANTS
 *====================================================================================================*/
#define DEM_START_SEC_VAR_NO_INIT_8
#include "Dem_MemMap.h"
#if(DEM_INDICATOR_NUM > 0)
VAR(Dem_IndicatorStatusType,DEM_VAR) Dem_OBDMilStatus;
#endif /* #if(DEM_INDICATOR_NUM > 0) */
#define DEM_STOP_SEC_VAR_NO_INIT_8
#include "Dem_MemMap.h"

#define DEM_START_SEC_VAR_NO_INIT_16
#include "Dem_MemMap.h"
VAR(uint16,DEM_VAR) Dem_OBDDistanceMILOn;
VAR(uint16,DEM_VAR) Dem_OBDDistanceMILLastOn;
VAR(uint16,DEM_VAR) Dem_OBDTimeMILOn;
VAR(uint16,DEM_VAR) Dem_OBDTimeMILLastOn;
VAR(uint16,DEM_VAR) Dem_OBDTimeSinceDTCClear;
VAR(uint16,DEM_VAR) Dem_OBDTimeDTCLastClear;
VAR(uint16,DEM_VAR) Dem_OBDDistanceLastDTCClear;
VAR(uint16,DEM_VAR) Dem_DistSinceDtcCleared;
#define DEM_STOP_SEC_VAR_NO_INIT_16
#include "Dem_MemMap.h"
/*====================================================================================================*
 *                                           LOCAL VARIABLES
 *====================================================================================================*/
#define DEM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dem_MemMap.h"
#if(DEM_J1939READINGDTC_SUPPORT == STD_ON)
STATIC VAR(Dem_J1939DtcFilterType,DEM_VAR) Dem_J1939DTCFilter;
#endif /* #if(DEM_J1939READINGDTC_SUPPORT == STD_ON) */

#if(DEM_J1939DM31_SUPPORT == STD_ON)
STATIC VAR(Dem_J1939NodeFilterType,DEM_VAR) Dem_J1939NodeFilter;
#endif /* #if(DEM_J1939DM31_SUPPORT == STD_ON) */

#if((DEM_J1939FREEZEFRAME_SUPPORT == STD_ON) || (DEM_J1939EXPANDEDFREEZEFRAME_SUPPORT == STD_ON))
STATIC VAR(Dem_J1939FFFilterType,DEM_VAR) Dem_J1939FFFilter;
#endif /* #if((DEM_J1939FREEZEFRAME_SUPPORT == STD_ON) \
          || (DEM_J1939EXPANDEDFREEZEFRAME_SUPPORT == STD_ON)) */

#if((DEM_RATIO_NUM > 0) && (DEM_J1939RATIO_SUPPORT == STD_ON))
STATIC VAR(Dem_J1939RatioFilterType,DEM_VAR) Dem_J1939RatioFilter;
#endif /* #if((DEM_RATIO_NUM > 0) && (DEM_J1939RATIO_SUPPORT == STD_ON)) */

#if(DEM_J1939CLEARDTC_SUPPORT == STD_ON)
STATIC VAR(Dem_ClearJ1939DtcType,DEM_VAR) Dem_J1939DtcClearInfo;
#endif /* #if(DEM_J1939CLEARDTC_SUPPORT == STD_ON) */
#define DEM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dem_MemMap.h"

#define DEM_START_SEC_VAR_NO_INIT_16
#include "Dem_MemMap.h"
#if((DEM_RATIO_NUM > 0) && (DEM_J1939RATIO_SUPPORT == STD_ON))
VAR(uint16,DEM_VAR)Dem_IgnitionCycleCounter;

VAR(uint16,DEM_VAR)Dem_GeneralDenominator[DEM_RATIO_NUM];

VAR(uint16,DEM_VAR)Dem_RatioNumerator[DEM_RATIO_NUM];

VAR(uint16,DEM_VAR)Dem_RatioDenominator[DEM_RATIO_NUM];
#endif /* #if((DEM_RATIO_NUM > 0) && (DEM_J1939RATIO_SUPPORT == STD_ON)) */
#define DEM_STOP_SEC_VAR_NO_INIT_16
#include "Dem_MemMap.h"

#define DEM_START_SEC_VAR_NO_INIT_8
#include "Dem_MemMap.h"
#if(DEM_J1939READINESS3_SUPPORT == STD_ON)
VAR(uint8,DEM_VAR) Dem_WarmupsSinceDTCsCleared;
#endif /* #if(DEM_J1939READINESS3_SUPPORT == STD_ON) */
#define DEM_STOP_SEC_VAR_NO_INIT_8
#include "Dem_MemMap.h"
/*====================================================================================================*
 *                                      LOCAL FUNCTION PROTOTYPES
 *====================================================================================================*/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
#if(DEM_J1939READINGDTC_SUPPORT == STD_ON)
STATIC FUNC(boolean, DEM_CODE)Dem_J1939FilterCheck
(
	uint16 DTCIndex
);

STATIC FUNC(void , DEM_CODE) Dem_SetJ1939FilterLampStatus
(
	boolean zeroFaults,
	P2VAR(Dem_J1939DcmLampStatusType,AUTOMATIC,DEM_VAR) pLampStatus
);
#endif /* #if(DEM_J1939READINGDTC_SUPPORT == STD_ON) */

#if(DEM_INDICATOR_ATTRIBUTE_TOTAL_NUM > 0)
STATIC FUNC(boolean, DEM_CODE)Dem_CheckIndicatorStatus
(
	Dem_EventIdType IntId
);

STATIC FUNC(uint8, DEM_CODE)Dem_J1939IndicatorRefCorrespond
(
	Dem_EventIdType IntId,
	uint8 RefType
);
#endif /* #if(DEM_INDICATOR_ATTRIBUTE_TOTAL_NUM > 0) */

STATIC FUNC(boolean , DEM_CODE)Dem_J1939DcmSearchNode
(
	uint16 DtcRef,
	uint8 Node
);

#if((DEM_J1939READINESS2_SUPPORT == STD_ON) || (DEM_J1939READINESS3_SUPPORT == STD_ON))
STATIC FUNC(uint16 , DEM_CODE) Dem_ReadCurrentOBDInfo
(
	boolean isTime
);
#endif /* #if((DEM_J1939READINESS2_SUPPORT == STD_ON) || (DEM_J1939READINESS3_SUPPORT == STD_ON)) */

#if((DEM_J1939READINESS1_SUPPORT == STD_ON) || (DEM_J1939READINESS3_SUPPORT == STD_ON))
STATIC FUNC(void , DEM_CODE)Dem_J1939ReadinessGroupCheck
(
	uint8 node,
	uint8* pSupport,
	uint8* pStatus
);
#endif /* #if((DEM_J1939READINESS1_SUPPORT == STD_ON) || (DEM_J1939READINESS3_SUPPORT == STD_ON)) */

#if(DEM_J1939CLEARDTC_SUPPORT == STD_ON)
STATIC FUNC(void, DEM_CODE)Dem_ClearJ1939DTC
(
	void
);
#endif /* #if(DEM_J1939CLEARDTC_SUPPORT == STD_ON) */
/*====================================================================================================*
 *                                           LOCAL FUNCTIONS
 *====================================================================================================*/
#if(DEM_J1939READINGDTC_SUPPORT == STD_ON)
/**
 * @brief			Dem_J1939FilterCheck
 * @details			The function sets the DTC filter for a specific node and returns the composite
 *                  lamp status of the filtered DTCs.
 *
 * @param[in]		DTCIndex: Index of dtc configuration.
 *
 * @return     		boolean: result of this check.
 * @retval			TRUE: Filter check successfully.
 * @retval			FALSE: Filter check unsuccessfully.
 */
STATIC FUNC(boolean, DEM_CODE)Dem_J1939FilterCheck
(
	uint16 DTCIndex
)
{
	boolean ret = (boolean)FALSE;
	uint8 u8NodeNum;

	uint8 u8NodeIndex;

	uint8 u8Loop = 0u;

	if((Dem_J1939DTCFilter.DTCKind == DEM_DTC_KIND_ALL_DTCS)\
			|| (Dem_ConfigPtr->DemDTC[DTCIndex].DemObdDTCRef != 0xFFFFu))
	{
		if((Dem_ConfigPtr->DemDTC[DTCIndex].DemObdDTCRef != 0xFFFFu)\
				&& (Dem_ConfigPtr->DemObdDTC[Dem_ConfigPtr->DemDTC[DTCIndex].\
											 DemObdDTCRef].DemJ1939DTCValue != 0u))
		{
			u8NodeIndex = Dem_ConfigPtr->DemDTCAttributes[Dem_ConfigPtr->DemDTC[DTCIndex].\
														DemDTCAttributesRef].DemJ1939DTC_J1939NodeRef;

			u8NodeNum = Dem_ConfigPtr->DemJ1939Node[u8NodeIndex].DemJ1939NmNodeNum;

			while(u8Loop < u8NodeNum)
			{
				if(Dem_ConfigPtr->DemJ1939Node[u8NodeIndex].DemJ1939NmNodeRef[u8Loop] \
						== Dem_J1939DTCFilter.u8Node)
				{
					break;
				}
				u8Loop++;
			}
			if(u8Loop != u8NodeNum)
			{
				ret = (boolean)TRUE;
			}
		}
	}
	return ret;
}

STATIC FUNC(void , DEM_CODE) Dem_SetJ1939FilterLampStatus
(
	boolean zeroFaults,
	P2VAR(Dem_J1939DcmLampStatusType,AUTOMATIC,DEM_VAR) pLampStatus
)
{
	if(zeroFaults == (boolean)TRUE)
	{
		if(Dem_J1939DTCFilter.DTCStatusFilter == DEM_J1939DTC_ACTIVE)
		{

			if(Dem_J1939DTCFilter.DTCKind == DEM_DTC_KIND_ALL_DTCS)
			{
				*pLampStatus = 0x00FFu;
			}
			else
			{
				*pLampStatus = 0x15FFu;
			}
		}
		else if(Dem_J1939DTCFilter.DTCStatusFilter \
				== DEM_J1939DTC_PREVIOUSLY_ACTIVE)
		{
			if(Dem_J1939DTCFilter.DTCKind == DEM_DTC_KIND_ALL_DTCS)
			{
				*pLampStatus = 0x04FFu;
			}
			else
			{
				*pLampStatus = 0x00FFu;
			}
		}
		else if(Dem_J1939DTCFilter.DTCStatusFilter \
				== DEM_J1939DTC_PENDING)
		{
			*pLampStatus = 0x04FFu;
		}
		else if(Dem_J1939DTCFilter.DTCStatusFilter \
				== DEM_J1939DTC_PERMANENT)
		{
			*pLampStatus = 0x04FFu;
		}
		else if(Dem_J1939DTCFilter.DTCStatusFilter \
				== DEM_J1939DTC_CURRENTLY_ACTIVE)
		{
			if(Dem_J1939DTCFilter.DTCKind == DEM_DTC_KIND_ALL_DTCS)
			{
				*pLampStatus = 0x00FFu;
			}
			else
			{
				*pLampStatus = 0x15FFu;
			}
		}
		else
		{
			;
		}
	}
	else
	{
		/**
		 * @req [SWS_Dem_00857] The function Dem_J1939DcmSetDTCFilter shall
		 *      return the current composite status of the J1939 lamps.
		 */

		/* Each reading of DTC returns a composite lamp status of the following lamps:
		 * 1.Malfunction Indicator Lamp
		 * 2.Red Stop Lamp
		 * 3.Amber Warning Lamp
		 * 4.Protect Lamp
		 */
		*pLampStatus = 0u;
		if(DEM_MILINDICATOR_REF != 0xFFu)
		{
			if(Dem_IndicatorStatus[DEM_MILINDICATOR_REF] != DEM_INDICATOR_OFF)
			{
				/**
				 * @req [SWS_Dem_00858] The composite "Malfunction Indicator Lamp" shall be set
				 *      to "Lamp Off" in case the Indicator referenced by DemMILIndicatorRef has
				 *      an IndicatorStatus DEM_INDICATOR_OFF. All other IndicatorStatus states
				 *      than "DEM_INDICATOR_OFF" shall set the composite Malfunction Indicator
				 *      Lamp to "Lamp On".
				 */
				*pLampStatus |= 0x4000u;
			}

			if((Dem_IndicatorStatus[DEM_MILINDICATOR_REF] == DEM_INDICATOR_OFF)\
					|| (Dem_IndicatorStatus[DEM_MILINDICATOR_REF] == DEM_INDICATOR_CONTINUOUS))
			{
				/**
				 * @req [SWS_Dem_00859] The composite "Flash Malfunction Indicator Lamp" shall
				 *      be set to "Unavailable / Do Not Flash" (0x03) in case the Indicator
				 *      referenced by DemMILIndicatorRef has an IndicatorStatus DEM_INDICATOR_OFF
				 *      or DEM_INDICATOR_CONTINUOUS.
				 */
				*pLampStatus |= 0x00C0u;
			}

			if(Dem_IndicatorStatus[DEM_MILINDICATOR_REF] == DEM_INDICATOR_SLOW_FLASH)
			{
				/**
				 * @req [SWS_Dem_00860] The composite "Flash Malfunction Indicator Lamp" shall be set
				 *      to "Slow Flash" (0x00) in case the Indicator referenced by DemMILIndicatorRef
				 *      has an IndicatorStatus DEM_INDICATOR_SLOW_FLASH.
				 */
				*pLampStatus &= (Dem_J1939DcmLampStatusType)(~(0x00C0u));
			}

			if(Dem_IndicatorStatus[DEM_MILINDICATOR_REF] == DEM_INDICATOR_FAST_FLASH)
			{
				/**
				 * @req [SWS_Dem_00861] The composite "Flash Malfunction Indicator Lamp" shall be set
				 *      to "Fast Flash" (0x01) in case the Indicator referenced by DemMILIndicatorRef
				 *      has an IndicatorStatus DEM_INDICATOR_FAST_FLASH.
				 */
				*pLampStatus &= (Dem_J1939DcmLampStatusType)(~(0x0080u));
			}
		}

		if(DEM_REDSTOPLAMPINDICATOR_REF != 0xFFu)
		{
			if(Dem_IndicatorStatus[DEM_REDSTOPLAMPINDICATOR_REF] != DEM_INDICATOR_OFF)
			{
				/**
				 * @req [SWS_Dem_00862] The composite "Red Stop Lamp" shall be set to "Lamp Off"
				 *      in case the Indicator referenced by DemRedStopLampIndicatorRef has an
				 *      IndicatorStatus DEM_INDICATOR_OFF.All other IndicatorStatus states than
				 *      "DEM_INDICATOR_OFF" shall set the composite Red Stop Lamp to "Lamp On".
				 */
				*pLampStatus |= 0x1000u;
			}

			if((Dem_IndicatorStatus[DEM_REDSTOPLAMPINDICATOR_REF] == DEM_INDICATOR_OFF)\
					|| (Dem_IndicatorStatus[DEM_REDSTOPLAMPINDICATOR_REF] == DEM_INDICATOR_CONTINUOUS))
			{
				/**
				 * @req [SWS_Dem_00863] The composite "Flash Red Stop Lamp" shall be set to
				 *      "Unavailable / Do Not Flash" (0x03) in case the Indicator referenced
				 *      by DemRedStopLampIndicatorRef has an IndicatorStatus DEM_INDICATOR_OFF
				 *      or DEM_INDICATOR_CONTINUOUS.
				 */
				*pLampStatus &= 0x0030u;
			}

			if(Dem_IndicatorStatus[DEM_REDSTOPLAMPINDICATOR_REF] == DEM_INDICATOR_SLOW_FLASH)
			{
				/**
				 * @req [SWS_Dem_00864] The composite "Flash Red Stop Lamp" shall be set to "Slow
				 *      Flash" (0x00) in case the Indicator referenced by DemRedStopLampIndicatorRef
				 *      has an IndicatorStatus DEM_INDICATOR_SLOW_FLASH.
				 */
				*pLampStatus &= (Dem_J1939DcmLampStatusType)(~(0x0030u));
			}

			if(Dem_IndicatorStatus[DEM_REDSTOPLAMPINDICATOR_REF] == DEM_INDICATOR_FAST_FLASH)
			{
				/**
				 * @req [SWS_Dem_00865] The composite "Flash Red Stop Lamp" shall be set to "Fast
				 *      Flash" (0x01) in case the Indicator referenced by DemRedStopLampIndicatorRef
				 *      has an IndicatorStatus DEM_INDICATOR_FAST_FLASH.
				 */
				*pLampStatus &= (Dem_J1939DcmLampStatusType)(~(0x0020u));
			}
		}

		if(DEM_AMBERWARNINGLAMPINDICATOR_REF != 0xFFu)
		{
			if(Dem_IndicatorStatus[DEM_AMBERWARNINGLAMPINDICATOR_REF] != DEM_INDICATOR_OFF)
			{
				/**
				 * @req [SWS_Dem_00866] The composite "Amber Warning Lamp" shall be set to "Lamp
				 *      Off" in case the Indicator referenced by DemAmberWarningLampIndicatorRef
				 *      has an IndicatorStatus DEM_INDICATOR_OFF.All other IndicatorStatus states
				 *      than DEM_INDICATOR_OFF shall set the composite Amber Warning Lamp to "Lamp
				 *      On".
				 */
				*pLampStatus |= 0x0400u;
			}

			if((Dem_IndicatorStatus[DEM_AMBERWARNINGLAMPINDICATOR_REF] == DEM_INDICATOR_OFF)\
					|| (Dem_IndicatorStatus[DEM_AMBERWARNINGLAMPINDICATOR_REF]\
							== DEM_INDICATOR_CONTINUOUS))
			{
				/**
				 * @req [SWS_Dem_00867] The composite "Amber Warning Lamp" shall be set to
				 *      "Unavailable/ Do Not Flash" (0x03) in case the Indicator referenced
				 *      by DemAmberWarningLampIndicatorRef has an IndicatorStatus DEM_INDI-
				 *      CATOR_OFF or DEM_INDICATOR_CONTINUOUS.
				 */
				*pLampStatus &= 0x000Cu;
			}

			if(Dem_IndicatorStatus[DEM_AMBERWARNINGLAMPINDICATOR_REF] == DEM_INDICATOR_SLOW_FLASH)
			{
				/**
				 * @req [SWS_Dem_00868] The composite "Flash Amber Warning Lamp" shall be set to "Slow
				 *      Flash" (0x00) in case the Indicator referenced by DemAmberWarningLampIndicator-
				 *      Ref has an IndicatorStatus DEM_INDICATOR_SLOW_FLASH.
				 */
				*pLampStatus &= (Dem_J1939DcmLampStatusType)(~(0x000Cu));
			}

			if(Dem_IndicatorStatus[DEM_AMBERWARNINGLAMPINDICATOR_REF] == DEM_INDICATOR_FAST_FLASH)
			{
				/**
				 * @req [SWS_Dem_00869] The composite "Flash Amber Warning Lamp" shall be set to "Fast
				 *      Flash" (0x01) in case the Indicator referenced by DemAmberWarningLampIndicator-
				 *      Ref has an IndicatorStatus DEM_INDICATOR_FAST_FLASH.
				 */
				*pLampStatus &= (Dem_J1939DcmLampStatusType)(~(0x0008u));
			}
		}

		if(DEM_PROTECTLAMPINDICATOR_REF != 0xFFu)
		{
			if(Dem_IndicatorStatus[DEM_PROTECTLAMPINDICATOR_REF] != DEM_INDICATOR_OFF)
			{
				/**
				 * @req [SWS_Dem_00870] The composite "Protect Lamp" shall be set to "Lamp Off" in case
				 *      the Indicator referenced by DemProtectLampIndicatorRef has an IndicatorStatus
				 *      DEM_INDICATOR_OFF.All other IndicatorStatus states than DEM_INDICATOR_OFF shall
				 *      set the composite Protect Lamp to "Lamp On".
				 */
				*pLampStatus |= 0x0100u;
			}

			if((Dem_IndicatorStatus[DEM_PROTECTLAMPINDICATOR_REF] == DEM_INDICATOR_OFF)\
					|| (Dem_IndicatorStatus[DEM_PROTECTLAMPINDICATOR_REF]\
							== DEM_INDICATOR_CONTINUOUS))
			{
				/**
				 * @req [SWS_Dem_00871] The composite "Flash Protect Lamp" shall be set to "Unavailable
				 *      / Do Not Flash" (0x03) in case the Indicator referenced by DemProtectLampIndic-
				 *      atorRef has an IndicatorStatus DEM_INDICATOR_OFF or DEM_INDICATOR_CONTINUOUS.
				 */
				*pLampStatus &= 0x0003u;
			}

			if(Dem_IndicatorStatus[DEM_PROTECTLAMPINDICATOR_REF] == DEM_INDICATOR_SLOW_FLASH)
			{
				/**
				 * @req [SWS_Dem_00872] The composite "Flash Protect Lamp" shall be set to "Slow Flash"
				 *      (0x00) in case the Indicator referenced by DemProtectLampIndicatorRef has an
				 *      IndicatorStatus DEM_INDICATOR_SLOW_FLASH.
				 */
				*pLampStatus &= (Dem_J1939DcmLampStatusType)(~(0x0003u));
			}

			if(Dem_IndicatorStatus[DEM_PROTECTLAMPINDICATOR_REF] == DEM_INDICATOR_FAST_FLASH)
			{
				/**
				 * @req [SWS_Dem_00873] The composite "Flash Protect Lamp" shall be set to "Fast Flash"
				 *      (0x01) in case the Indicator referenced by DemProtectLampIndicatorRef has an
				 *      IndicatorStatus DEM_INDICATOR_FAST_FLASH.
				 */
				*pLampStatus &= (Dem_J1939DcmLampStatusType)(~(0x0002u));
			}
		}
	}
}
#endif /* #if(DEM_J1939READINGDTC_SUPPORT == STD_ON) */

#if(DEM_INDICATOR_ATTRIBUTE_TOTAL_NUM > 0)
/**
 * @brief			Dem_CheckIndicatorStatus
 * @details			Check if the indicators of event are on.
 *
 * @param[in]		IntId: Index of event configuration.
 *
 * @return     		boolean: result of this check.
 * @retval			TRUE: One of the indicators' status is on.
 * @retval			FALSE: None of the indicators' status is on.
 */
STATIC FUNC(boolean, DEM_CODE)Dem_CheckIndicatorStatus
(
	Dem_EventIdType IntId
)
{
	boolean ret = (boolean)FALSE;
	uint8 u8Loop = 0u;
	const Dem_EventParameterType* pEventPara = &(Dem_ConfigPtr->DemEventParameter[IntId]);
	const Dem_IndicatorAttributeType* pIndicatorAttr = pEventPara->DemIndicatorAttribute;
	const uint8 u8IndicatorAttrNum = pEventPara->DemIndicatorAttributeNum;

	while(u8Loop < u8IndicatorAttrNum)
	{
		if(Dem_IndicatorStatus[pIndicatorAttr->DemIndicatorRef] != DEM_INDICATOR_OFF)
		{
			/**
			 * @req [SWS_Dem_00909] If more than one indicator is configured for a specific event,
			 *      the Dem module shall use a logical OR operation of all combined warning indicators
			 *      assigned to this event to calculate the UDS DTC status bit 7 (WarningIndicator).
			 */
			ret = (boolean)TRUE;
			break;
		}
		u8Loop++;
		pIndicatorAttr++;
	}
	return ret;
}

STATIC FUNC(uint8, DEM_CODE)Dem_J1939IndicatorRefCorrespond
(
	Dem_EventIdType IntId,
	uint8 RefType
)
{
	uint8 u8Ret = 0xFFu;

	const Dem_IndicatorAttributeType* pIndicatorAttr = Dem_ConfigPtr->\
			DemEventParameter[IntId].DemIndicatorAttribute;

	uint8 u8IndicatorAttrNum = Dem_ConfigPtr->DemEventParameter[IntId].\
			DemIndicatorAttributeNum;

	uint8 u8Loop = 0u;

	while(u8Loop < u8IndicatorAttrNum)
	{
		if(pIndicatorAttr->DemIndicatorRef == RefType)
		{
			u8Ret = u8Loop;
			break;
		}
		u8Loop++;
		pIndicatorAttr++;
	}

	return u8Ret;
}
#endif /* #if(DEM_INDICATOR_ATTRIBUTE_TOTAL_NUM > 0) */

STATIC FUNC(boolean , DEM_CODE)Dem_J1939DcmSearchNode
(
	uint16 DtcRef,
	uint8 Node
)
{
	boolean ret = (boolean)FALSE;
	uint8 u8Loop = 0u;

	const uint8* pNode = Dem_ConfigPtr->DemJ1939Node[Dem_ConfigPtr->DemDTCAttributes[Dem_ConfigPtr->\
														DemDTC[DtcRef].DemDTCAttributesRef].\
													    DemJ1939DTC_J1939NodeRef].DemJ1939NmNodeRef;

	uint8 u8NodeNum = Dem_ConfigPtr->DemJ1939Node[Dem_ConfigPtr->DemDTCAttributes[Dem_ConfigPtr->\
														DemDTC[DtcRef].DemDTCAttributesRef]\
														.DemJ1939DTC_J1939NodeRef].DemJ1939NmNodeNum;

	while(u8Loop < u8NodeNum)
	{
		if(*pNode == Node)
		{
			ret = (boolean)TRUE;
		}
		u8Loop++;
		pNode++;
	}
	return ret;
}

#if((DEM_J1939READINESS2_SUPPORT == STD_ON) || (DEM_J1939READINESS3_SUPPORT == STD_ON))
STATIC FUNC(uint16 , DEM_CODE) Dem_ReadCurrentOBDInfo
(
	boolean isTime
)
{
	uint8 u8Array[2] = {0};

#if(DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT)
	uint8 u8Index;
	if(isTime == (boolean)TRUE)
	{
		u8Index = Dem_General.DemGeneralOBD->DemOBDTimeSinceEngineStart;
	}
	else
	{
		u8Index = Dem_General.DemGeneralOBD->DemOBDInputDistanceInformation;
	}

	if(u8Index != 0xFFu)
	{
		if(Dem_General.DemGeneralOBD->DemOBDDataElement[u8Index].DemExternalCSDataElementClass\
				!= NULL_PTR)
		{
			if(Dem_General.DemGeneralOBD->DemOBDDataElement[u8Index].DemExternalCSDataElementClass\
					->DemDataElementReadFnc != NULL_PTR)
			{
				Dem_General.DemGeneralOBD->DemOBDDataElement[u8Index].\
					DemExternalCSDataElementClass->DemDataElementReadFnc(u8Array);
			}
		}
		else
		{
			; /* DemExternalSRDataElementClass */
		}
	}
#endif /* #if(DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT) */

	return ((uint16)u8Array[0] | (uint16)((uint16)u8Array[1u] << 8u));
}
#endif /* #if((DEM_J1939READINESS2_SUPPORT == STD_ON) || (DEM_J1939READINESS3_SUPPORT == STD_ON)) */

#if((DEM_J1939READINESS1_SUPPORT == STD_ON) || (DEM_J1939READINESS3_SUPPORT == STD_ON))
STATIC FUNC(void , DEM_CODE)Dem_J1939ReadinessGroupCheck
(
	uint8 node,
	uint8* pSupport,
	uint8* pStatus
)
{
	uint16 u16Loop = 0u;
	uint16 u16DtcRef;
	uint32 u32J1939Dtc = 0u;

	do
	{
		(void)Dem_GetDTCOfEvent((u16Loop + 1u),\
							    DEM_DTC_FORMAT_J1939,\
								&u32J1939Dtc);

		if(u32J1939Dtc != 0u)
		{
			u16DtcRef = Dem_ConfigPtr->DemEventParameter[u16Loop].DemDTCRef;

			if((!(Dem_ISEnable_DTCSuppress(u16DtcRef)))\
					&& ((boolean)TRUE == Dem_J1939DcmSearchNode(u16DtcRef,node)))
			{
				u16DtcRef = Dem_ConfigPtr->DemDTC[u16DtcRef].DemObdDTCRef;
				if(Dem_ConfigPtr->DemObdDTC[u16DtcRef].DemEventOBDReadinessGroup\
						== DEM_OBD_RDY_AC)
				{
					DEM_U8BIT_ENABLE(pSupport, DEM_OBD_RDY_AC);

					if(Dem_ISEnable_UdsStatusBits(u16Loop,DEM_UDS_STATUS_TNCSLC))
					{
						DEM_U8BIT_ENABLE(pStatus, DEM_OBD_RDY_AC);
					}
				}
				else if(Dem_ConfigPtr->DemObdDTC[u16DtcRef].DemEventOBDReadinessGroup\
						== DEM_OBD_RDY_BOOSTPR)
				{
					DEM_U8BIT_ENABLE(pSupport, DEM_OBD_RDY_BOOSTPR);

					if(Dem_ISEnable_UdsStatusBits(u16Loop,DEM_UDS_STATUS_TNCSLC))
					{
						DEM_U8BIT_ENABLE(pStatus, DEM_OBD_RDY_BOOSTPR);
					}
				}
				else if(Dem_ConfigPtr->DemObdDTC[u16DtcRef].DemEventOBDReadinessGroup\
						== DEM_OBD_RDY_CAT)
				{
					DEM_U8BIT_ENABLE(pSupport, DEM_OBD_RDY_CAT);

					if(Dem_ISEnable_UdsStatusBits(u16Loop,DEM_UDS_STATUS_TNCSLC))
					{
						DEM_U8BIT_ENABLE(pStatus, DEM_OBD_RDY_CAT);
					}
				}
				else if(Dem_ConfigPtr->DemObdDTC[u16DtcRef].DemEventOBDReadinessGroup\
						== DEM_OBD_RDY_CMPRCMPT)
				{
					DEM_U8BIT_ENABLE(pSupport, DEM_OBD_RDY_CMPRCMPT);

					if(Dem_ISEnable_UdsStatusBits(u16Loop,DEM_UDS_STATUS_TNCSLC))
					{
						DEM_U8BIT_ENABLE(pStatus, DEM_OBD_RDY_CMPRCMPT);
					}
				}
				else if(Dem_ConfigPtr->DemObdDTC[u16DtcRef].DemEventOBDReadinessGroup\
						== DEM_OBD_RDY_EGSENS)
				{
					DEM_U8BIT_ENABLE(pSupport, DEM_OBD_RDY_EGSENS);

					if(Dem_ISEnable_UdsStatusBits(u16Loop,DEM_UDS_STATUS_TNCSLC))
					{
						DEM_U8BIT_ENABLE(pStatus, DEM_OBD_RDY_EGSENS);
					}
				}
				else if(Dem_ConfigPtr->DemObdDTC[u16DtcRef].DemEventOBDReadinessGroup\
						== DEM_OBD_RDY_ERG)
				{
					DEM_U8BIT_ENABLE(pSupport, DEM_OBD_RDY_ERG);

					if(Dem_ISEnable_UdsStatusBits(u16Loop,DEM_UDS_STATUS_TNCSLC))
					{
						DEM_U8BIT_ENABLE(pStatus, DEM_OBD_RDY_ERG);
					}
				}
				else if(Dem_ConfigPtr->DemObdDTC[u16DtcRef].DemEventOBDReadinessGroup\
						== DEM_OBD_RDY_EVAP)
				{
					DEM_U8BIT_ENABLE(pSupport, DEM_OBD_RDY_EVAP);

					if(Dem_ISEnable_UdsStatusBits(u16Loop,DEM_UDS_STATUS_TNCSLC))
					{
						DEM_U8BIT_ENABLE(pStatus, DEM_OBD_RDY_EVAP);
					}
				}
				else if(Dem_ConfigPtr->DemObdDTC[u16DtcRef].DemEventOBDReadinessGroup\
						== DEM_OBD_RDY_FLSYS)
				{
					DEM_U8BIT_ENABLE(pSupport, DEM_OBD_RDY_FLSYS);

					if(Dem_ISEnable_UdsStatusBits(u16Loop,DEM_UDS_STATUS_TNCSLC))
					{
						DEM_U8BIT_ENABLE(pStatus, DEM_OBD_RDY_FLSYS);
					}
				}
				else if(Dem_ConfigPtr->DemObdDTC[u16DtcRef].DemEventOBDReadinessGroup\
						== DEM_OBD_RDY_FLSYS_NONCONT)
				{
					DEM_U8BIT_ENABLE(pSupport, DEM_OBD_RDY_FLSYS_NONCONT);

					if(Dem_ISEnable_UdsStatusBits(u16Loop,DEM_UDS_STATUS_TNCSLC))
					{
						DEM_U8BIT_ENABLE(pStatus, DEM_OBD_RDY_FLSYS_NONCONT);
					}
				}
				else if(Dem_ConfigPtr->DemObdDTC[u16DtcRef].DemEventOBDReadinessGroup\
						== DEM_OBD_RDY_HCCAT)
				{
					DEM_U8BIT_ENABLE(pSupport, DEM_OBD_RDY_HCCAT);

					if(Dem_ISEnable_UdsStatusBits(u16Loop,DEM_UDS_STATUS_TNCSLC))
					{
						DEM_U8BIT_ENABLE(pStatus, DEM_OBD_RDY_HCCAT);
					}
				}
				else if(Dem_ConfigPtr->DemObdDTC[u16DtcRef].DemEventOBDReadinessGroup\
						== DEM_OBD_RDY_HTCAT)
				{
					DEM_U8BIT_ENABLE(pSupport, DEM_OBD_RDY_HTCAT);

					if(Dem_ISEnable_UdsStatusBits(u16Loop,DEM_UDS_STATUS_TNCSLC))
					{
						DEM_U8BIT_ENABLE(pStatus, DEM_OBD_RDY_HTCAT);
					}
				}
				else if(Dem_ConfigPtr->DemObdDTC[u16DtcRef].DemEventOBDReadinessGroup\
						== DEM_OBD_RDY_MISF)
				{
					DEM_U8BIT_ENABLE(pSupport, DEM_OBD_RDY_MISF);

					if(Dem_ISEnable_UdsStatusBits(u16Loop,DEM_UDS_STATUS_TNCSLC))
					{
						DEM_U8BIT_ENABLE(pStatus, DEM_OBD_RDY_MISF);
					}
				}
				else if(Dem_ConfigPtr->DemObdDTC[u16DtcRef].DemEventOBDReadinessGroup\
						== DEM_OBD_RDY_NONE)
				{
					DEM_U8BIT_ENABLE(pSupport, DEM_OBD_RDY_NONE);

					if(Dem_ISEnable_UdsStatusBits(u16Loop,DEM_UDS_STATUS_TNCSLC))
					{
						DEM_U8BIT_ENABLE(pStatus, DEM_OBD_RDY_NONE);
					}
				}
				else if(Dem_ConfigPtr->DemObdDTC[u16DtcRef].DemEventOBDReadinessGroup\
						== DEM_OBD_RDY_NOXCAT)
				{
					DEM_U8BIT_ENABLE(pSupport, DEM_OBD_RDY_NOXCAT);

					if(Dem_ISEnable_UdsStatusBits(u16Loop,DEM_UDS_STATUS_TNCSLC))
					{
						DEM_U8BIT_ENABLE(pStatus, DEM_OBD_RDY_NOXCAT);
					}
				}
				else if(Dem_ConfigPtr->DemObdDTC[u16DtcRef].DemEventOBDReadinessGroup\
						== DEM_OBD_RDY_O2SENS)
				{
					DEM_U8BIT_ENABLE(pSupport, DEM_OBD_RDY_O2SENS);

					if(Dem_ISEnable_UdsStatusBits(u16Loop,DEM_UDS_STATUS_TNCSLC))
					{
						DEM_U8BIT_ENABLE(pStatus, DEM_OBD_RDY_O2SENS);
					}
				}
				else if(Dem_ConfigPtr->DemObdDTC[u16DtcRef].DemEventOBDReadinessGroup\
						== DEM_OBD_RDY_O2SENSHT)
				{
					DEM_U8BIT_ENABLE(pSupport, DEM_OBD_RDY_O2SENSHT);

					if(Dem_ISEnable_UdsStatusBits(u16Loop,DEM_UDS_STATUS_TNCSLC))
					{
						DEM_U8BIT_ENABLE(pStatus, DEM_OBD_RDY_O2SENSHT);
					}
				}
				else if(Dem_ConfigPtr->DemObdDTC[u16DtcRef].DemEventOBDReadinessGroup\
						== DEM_OBD_RDY_PMFLT)
				{
					DEM_U8BIT_ENABLE(pSupport, DEM_OBD_RDY_PMFLT);

					if(Dem_ISEnable_UdsStatusBits(u16Loop,DEM_UDS_STATUS_TNCSLC))
					{
						DEM_U8BIT_ENABLE(pStatus, DEM_OBD_RDY_PMFLT);
					}
				}
				else if(Dem_ConfigPtr->DemObdDTC[u16DtcRef].DemEventOBDReadinessGroup\
						== DEM_OBD_RDY_SECAIR)
				{
					DEM_U8BIT_ENABLE(pSupport, DEM_OBD_RDY_SECAIR);

					if(Dem_ISEnable_UdsStatusBits(u16Loop,DEM_UDS_STATUS_TNCSLC))
					{
						DEM_U8BIT_ENABLE(pStatus, DEM_OBD_RDY_SECAIR);
					}
				}
				else
				{

				}
			}
		}
		u16Loop++;
	}while(u16Loop < DEM_EVENT_PARAMETER_NUM);
}
#endif /* #if((DEM_J1939READINESS1_SUPPORT == STD_ON) || (DEM_J1939READINESS3_SUPPORT == STD_ON)) */

#if(DEM_J1939CLEARDTC_SUPPORT == STD_ON)
STATIC FUNC(void, DEM_CODE)Dem_ClearJ1939DTC
(
	void
)
{
	uint16 u16DtcIndex;
	uint16 u16Loop = 0u;
	Dem_MemoryEntryType* pEntry;
	Dem_MemoryInfoType* pMemInfo = Dem_GetMemInfoByOrigin(DEM_DTC_ORIGIN_PRIMARY_MEMORY);

	do
	{
		u16DtcIndex = Dem_ConfigPtr->DemEventParameter[u16Loop].DemDTCRef;
		if((u16DtcIndex != 0xFFFFu) && (!(Dem_ISEnable_DTCSuppress(u16DtcIndex))))
		{
			u16DtcIndex = Dem_ConfigPtr->DemDTC[u16DtcIndex].DemObdDTCRef;

			if((u16DtcIndex != 0xFFFFu)\
					&&( Dem_ConfigPtr->DemObdDTC[u16DtcIndex].DemJ1939DTCValue != 0u))
			{
				if(((Dem_J1939DtcClearInfo.DtcType == DEM_J1939DTC_CLEAR_ALL)\
						&&(Dem_ISEnable_UdsStatusBits(u16Loop,DEM_UDS_STATUS_TF)))\
						||((Dem_J1939DtcClearInfo.DtcType == DEM_J1939DTC_CLEAR_PREVIOUSLY_ACTIVE)\
						&&(!(Dem_ISEnable_UdsStatusBits(u16Loop,DEM_UDS_STATUS_TF)))\
						&&(Dem_ISEnable_UdsStatusBits(u16Loop,DEM_UDS_STATUS_CDTC))\
						))
				{
					if((boolean)TRUE == Dem_J1939DcmSearchNode(u16DtcIndex,Dem_J1939DtcClearInfo.node))
					{
			#if(DEM_ENABLE_CONDITION_NUM > 0)
						if (Dem_ISEnable_EnableCondition(u16Loop))
						{
			#endif /* #if(DEM_ENABLE_CONDITION_NUM > 0) */

							Dem_ClearDtcStatus(u16Loop);

			#if(DEM_ENABLE_CONDITION_NUM > 0)
						}
			#endif /* #if(DEM_ENABLE_CONDITION_NUM > 0) */

						pEntry = Dem_GetEntryFromMemory(DEM_DTC_ORIGIN_PRIMARY_MEMORY,(u16Loop + 1u));

						if(pEntry != NULL_PTR)
						{
							Dem_DeleMemoryEntry(DEM_DTC_ORIGIN_PRIMARY_MEMORY,pEntry);
						}
					}
				}
			}
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
}
#endif /* #if(DEM_J1939CLEARDTC_SUPPORT == STD_ON) */
/*====================================================================================================*
 *                                          GLOBAL FUNCTIONS
 *====================================================================================================*/
#if(DEM_J1939READINGDTC_SUPPORT == STD_ON)
/**
 * @sid				0x90
 * @brief			Dem_J1939DcmSetDTCFilter
 * @details			The function sets the DTC filter for a specific node and returns the composite
 *                  lamp status of the filtered DTCs.
 *
 * @param[in]		DTCStatusFilter: The following types are available:
 * 									 DEM_J1939DTC_ACTIVE
 * 									 DEM_J1939DTC_PREVIOUSLY_ACTIVE
 * 									 DEM_J1939DTC_PENDING
 * 									 DEM_J1939DTC_PERMANENT
 * 									 DEM_J1939DTC_CURRENTLY_ACTIVE
 * @param[in]       DTCKind: Defines the functional group of DTCs to be reported
 *                           (e.g. all DTC, OBD-relevant DTC).
 * @param[in]       node: Nm node Id.
 *
 * @param[out]		LampStatus: Receives the commulated lamp status.
 *
 * @return     		Dem_ReturnSetFilterType: Status of the operation to (re-)set a DTC filter.
 * @retval			DEM_FILTER_ACCEPTED: Filter was accepted.
 * @retval			DEM_WRONG_FILTER: Wrong filter selected.
 */
FUNC(Dem_ReturnSetFilterType , DEM_CODE)Dem_J1939DcmSetDTCFilter
(
	Dem_J1939DcmDTCStatusFilterType DTCStatusFilter,
    Dem_DTCKindType DTCKind,
    uint8 node,
    P2VAR(Dem_J1939DcmLampStatusType,AUTOMATIC,DEM_VAR) pLampStatus
)
{
	Dem_ReturnSetFilterType ret = DEM_WRONG_FILTER;
	uint8 u8EntryNum = 0u;
	uint16 u16DtcRef;
	Dem_EventIdType u16IntId;
	Dem_MemoryEntryType* pEntry;


#if (DEM_DEV_ERROR_DETECT == STD_ON)
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
    	DEM_DET_ERROR_REPORT(DEM_SID_J1939DCMSETDTCFILTER,DEM_E_UNINIT);
    }
    else if (pLampStatus == NULL_PTR)
    {
    	DEM_DET_ERROR_REPORT(DEM_SID_J1939DCMSETDTCFILTER,DEM_E_PARAM_POINTER);
    }
    else
#endif /* #if (DEM_DEV_ERROR_DETECT == STD_ON) */
    {
    	ret = DEM_FILTER_ACCEPTED;

    	/**
    	 * @req [SWS_Dem_00855] The function Dem_J1939DcmSetDTCFilter shall set the filter mask
    	 *      attributes to be used for the subsequent calls of Dem_J1939DcmGetNumberOfFilteredDTC
    	 *      and Dem_J1939DcmGetNextFilteredDTC,and reset an internal counter to the first event.
    	 *
    	 * @req [SWS_Dem_00856] The filter mask attributes set via Dem_J1939DcmSetDTCFilter shall be
    	 *      used until the next call of Dem_J1939DcmSetDTCFilter or Dem initialization.
    	 */
    	Dem_J1939DTCFilter.DTCKind = DTCKind;
    	Dem_J1939DTCFilter.u8Node = node;
    	Dem_J1939DTCFilter.DTCStatusFilter = DTCStatusFilter;

    	if(DTCStatusFilter == DEM_J1939DTC_PERMANENT)
    	{
    		Dem_J1939DTCFilter.DTCOrigin = DEM_DTC_ORIGIN_PERMANENT_MEMORY;
    	}
    	else
    	{
    		Dem_J1939DTCFilter.DTCOrigin = DEM_DTC_ORIGIN_PRIMARY_MEMORY;
    	}

    	Dem_J1939DTCFilter.u8FilterIndex = 0u;
    	Dem_J1939DTCFilter.FilterSet = (boolean)TRUE;

    	pEntry = Dem_GetMemoryConf(DEM_DTC_ORIGIN_PRIMARY_MEMORY,&u8EntryNum);

    	while(Dem_J1939DTCFilter.u8FilterIndex < u8EntryNum)
		{
			if(pEntry[Dem_J1939DTCFilter.u8FilterIndex].EventId != 0u)
			{
				u16IntId = pEntry[Dem_J1939DTCFilter.u8FilterIndex].EventId - 1u;

				u16DtcRef = Dem_ConfigPtr->DemEventParameter[u16IntId].DemDTCRef;

				if(u16DtcRef != 0xFFFFu)
				{
					/**
					 * @req [SWS_Dem_01101] A suppressed DTC shall not be visible for the following
					 *      Dcm query-functions; therefore the Dem_J1939DcmGetNextFilteredDTC shall
					 *      treat the DTC as if filter is not matching.
					 */
					if(!(Dem_ISEnable_DTCSuppress(u16DtcRef)))
					{
						if((boolean)TRUE == Dem_J1939FilterCheck(u16DtcRef))
						{
							/* In case the function has calculated the total number of
							 * matching DTCs,the return value shall be DEM_NUMBER_OK. */
							if(Dem_J1939DTCFilter.DTCStatusFilter == DEM_J1939DTC_ACTIVE)
							{
								if((Dem_ISEnable_UdsStatusBits(u16IntId,DEM_UDS_STATUS_CDTC))\
										&&(Dem_ISEnable_UdsStatusBits(u16IntId,DEM_UDS_STATUS_TF)))
								{
									break;
								}
								else
								{
#if(DEM_INDICATOR_ATTRIBUTE_TOTAL_NUM > 0)
									if((boolean)TRUE == Dem_CheckIndicatorStatus(u16IntId))
									{
#endif /* #if(DEM_INDICATOR_ATTRIBUTE_TOTAL_NUM > 0) */
										break;
#if(DEM_INDICATOR_ATTRIBUTE_TOTAL_NUM > 0)
									}
#endif /* #if(DEM_INDICATOR_ATTRIBUTE_TOTAL_NUM > 0) */
								}
							}
							else if(Dem_J1939DTCFilter.DTCStatusFilter \
									== DEM_J1939DTC_PREVIOUSLY_ACTIVE)
							{
								if(((Dem_ISEnable_UdsStatusBits(u16IntId,DEM_UDS_STATUS_CDTC))\
										&&(!(Dem_ISEnable_UdsStatusBits(u16IntId,DEM_UDS_STATUS_TF))))
#if(DEM_INDICATOR_ATTRIBUTE_TOTAL_NUM > 0)
										&&((boolean)FALSE == Dem_CheckIndicatorStatus(u16IntId))
#endif /* #if(DEM_INDICATOR_ATTRIBUTE_TOTAL_NUM > 0) */
										)
								{
									break;
								}
							}
							else if(Dem_J1939DTCFilter.DTCStatusFilter \
									== DEM_J1939DTC_PENDING)
							{
								if(Dem_ISEnable_UdsStatusBits(u16IntId,DEM_UDS_STATUS_PDTC))
								{
									break;
								}
							}
							else if(Dem_J1939DTCFilter.DTCStatusFilter \
									== DEM_J1939DTC_PERMANENT)
							{
								break;
							}
							else if(Dem_J1939DTCFilter.DTCStatusFilter \
									== DEM_J1939DTC_CURRENTLY_ACTIVE)
							{
								if(Dem_ISEnable_UdsStatusBits(u16IntId,DEM_UDS_STATUS_TF))
								{
									break;
								}
							}
							else
							{
								ret = DEM_WRONG_FILTER;
								break;
							}
						}
					}
				}
			}
			Dem_J1939DTCFilter.u8FilterIndex++;
		}

    	if(Dem_J1939DTCFilter.u8FilterIndex == u8EntryNum)
    	{
    		Dem_SetJ1939FilterLampStatus((boolean)TRUE,pLampStatus);
    	}
    	else
    	{
    		if(ret == DEM_FILTER_ACCEPTED)
    		{
    			Dem_SetJ1939FilterLampStatus((boolean)FALSE,pLampStatus);
    		}
    	}
    }
    return ret;
}

/**
 * @sid				0x91
 * @brief			Dem_J1939DcmGetNumberOfFilteredDTC
 * @details			Gets the number of currently filtered DTCs set by the function
 *                  Dem_J1939DcmSetDTCFilter.
 *
 * @param[out]		NumberOfFilteredDTC: The number of DTCs matching the defined status mask.
 *
 * @return     		Dem_ReturnGetNumberOfFilteredDTCType: Status of the operation to retrieve a
 *                  number of DTC from the Dem.
 * @retval			DEM_NUMBER_OK: Getting number of filtered DTCs was successful.
 * @retval			DEM_NUMBER_FAILED: Getting number of filtered DTCs failed.
 * @retval			DEM_NUMBER_PENDING: The requested value is calculated asynchronously and
 *                  currently not available.The caller can retry later.
 */
FUNC(Dem_ReturnGetNumberOfFilteredDTCType , DEM_CODE)Dem_J1939DcmGetNumberOfFilteredDTC
(
	P2VAR(uint16,AUTOMATIC,DEM_VAR) pNumberOfFilteredDTC
)
{
	uint8 u8EntryNum = 0u;
	uint8 u8Loop = 0u;
	uint16 u16DtcRef;
	Dem_EventIdType u16IntId;
	uint8 u8DtcRecord[DEM_DTC_NUM_BYTE] = {0u};
	Dem_ReturnGetNumberOfFilteredDTCType ret = DEM_NUMBER_FAILED;

	Dem_MemoryEntryType* pEntry;

#if (DEM_DEV_ERROR_DETECT == STD_ON)
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
    	DEM_DET_ERROR_REPORT(DEM_SID_J1939DCMGETNUMBEROFFILTEREDDTC,DEM_E_UNINIT);
    }
    else if (pNumberOfFilteredDTC == NULL_PTR)
    {
    	DEM_DET_ERROR_REPORT(DEM_SID_J1939DCMGETNUMBEROFFILTEREDDTC,DEM_E_PARAM_POINTER);
    }
    else
#endif /* #if (DEM_DEV_ERROR_DETECT == STD_ON) */
    {
    	/**
    	 * @req [SWS_Dem_00874] The function Dem_J1939DcmGetNumberOfFilteredDTC shall return the number
    	 *      of J1939 DTCs matching the defined filter criteria for a specific node defined by the
    	 *      function call of Dem_J1939DcmSetDTCFilter.
    	 */
    	if(Dem_J1939DTCFilter.FilterSet == (boolean)TRUE)
    	{
    		pEntry = Dem_GetMemoryConf(Dem_J1939DTCFilter.DTCOrigin,&u8EntryNum);

    		while(u8Loop < u8EntryNum)
    		{
    			if(pEntry->EventId != 0u)
    			{
    				u16IntId = pEntry->EventId - 1u;

    				u16DtcRef = Dem_ConfigPtr->DemEventParameter[u16IntId].DemDTCRef;

    				if(u16DtcRef != 0xFFFFu)
    				{
    					if(DEM_U8BIT_ISENABLE(u8DtcRecord,u16DtcRef) == 0u)
    					{
							if((boolean)TRUE == Dem_J1939FilterCheck(u16DtcRef))
							{
								/* In case the function has calculated the total number of
								 * matching DTCs,the return value shall be DEM_NUMBER_OK. */
								if(Dem_J1939DTCFilter.DTCStatusFilter == DEM_J1939DTC_ACTIVE)
								{
									if((Dem_ISEnable_UdsStatusBits(u16IntId,DEM_UDS_STATUS_CDTC) \
											!= 0u)\
											&&(Dem_ISEnable_UdsStatusBits(u16IntId,DEM_UDS_STATUS_TF)))
									{
										DEM_U8BIT_ENABLE(u8DtcRecord,u16DtcRef);
										(*pNumberOfFilteredDTC)++;
										ret = DEM_NUMBER_OK;
									}
									else
									{
#if(DEM_INDICATOR_ATTRIBUTE_TOTAL_NUM > 0)
										if((boolean)TRUE == Dem_CheckIndicatorStatus(u16IntId))
										{
#endif /* #if(DEM_INDICATOR_ATTRIBUTE_TOTAL_NUM > 0) */
											DEM_U8BIT_ENABLE(u8DtcRecord,u16DtcRef);
											(*pNumberOfFilteredDTC)++;
											ret = DEM_NUMBER_OK;
#if(DEM_INDICATOR_ATTRIBUTE_TOTAL_NUM > 0)
										}
#endif /* #if(DEM_INDICATOR_ATTRIBUTE_TOTAL_NUM > 0) */
									}
								}
								else if(Dem_J1939DTCFilter.DTCStatusFilter \
										== DEM_J1939DTC_PREVIOUSLY_ACTIVE)
								{
									if(((Dem_ISEnable_UdsStatusBits(u16IntId,DEM_UDS_STATUS_CDTC))\
											&&(!(Dem_ISEnable_UdsStatusBits(u16IntId,DEM_UDS_STATUS_TF))))
#if(DEM_INDICATOR_ATTRIBUTE_TOTAL_NUM > 0)
											&&((boolean)FALSE == Dem_CheckIndicatorStatus(u16IntId))
#endif /* #if(DEM_INDICATOR_ATTRIBUTE_TOTAL_NUM > 0) */
											)
									{
										DEM_U8BIT_ENABLE(u8DtcRecord,u16DtcRef);
										(*pNumberOfFilteredDTC)++;
										ret = DEM_NUMBER_OK;
									}
								}
								else if(Dem_J1939DTCFilter.DTCStatusFilter \
										== DEM_J1939DTC_PENDING)
								{
									if(Dem_ISEnable_UdsStatusBits(u16IntId,DEM_UDS_STATUS_PDTC))
									{
										DEM_U8BIT_ENABLE(u8DtcRecord,u16DtcRef);
										(*pNumberOfFilteredDTC)++;
										ret = DEM_NUMBER_OK;
									}
								}
								else if(Dem_J1939DTCFilter.DTCStatusFilter \
										== DEM_J1939DTC_PERMANENT)
								{
									DEM_U8BIT_ENABLE(u8DtcRecord,u16DtcRef);
									(*pNumberOfFilteredDTC)++;
									ret = DEM_NUMBER_OK;
								}
								else if(Dem_J1939DTCFilter.DTCStatusFilter \
										== DEM_J1939DTC_CURRENTLY_ACTIVE)
								{
									if(Dem_ISEnable_UdsStatusBits(u16IntId,DEM_UDS_STATUS_TF))
									{
										DEM_U8BIT_ENABLE(u8DtcRecord,u16DtcRef);
										(*pNumberOfFilteredDTC)++;
										ret = DEM_NUMBER_OK;
									}
								}
								else
								{

								}
							}
    					}
    				}
    			}
    			u8Loop++;
    			pEntry++;
    		}
    	}
    }
    return ret;
}


/**
 * @sid				0x92
 * @brief			Dem_J1939DcmGetNextFilteredDTC
 * @details			Gets the next filtered J1939 DTC.
 *
 * @param[out]		J1939DTC: Receives the J1939DTC value. If the return value of the function
 *                  is other than DEM_FILTERED_OK this parameter does not contain valid data.
 *
 * @param[out]      OccurenceCounter: This parameter receives the corresponding occurrence counter.
 *                  If the return value of the function call is other than DEM_FILTERED_OK this
 *                  parameter does not contain valid data.
 *
 * @return     		Dem_ReturnGetNextFilteredElementType: Status of the operation to retrieve a
 *                  DTC from the Dem.
 * @retval			DEM_FILTERED_OK: Returned next filtered element.
 * @retval			DEM_FILTERED_NO_MATCHING_ELEMENT: No further element(matching the filter criteria)
 *                  found.
 * @retval			DEM_FILTERED_PENDING: The requested value is calculated asynchronously and
 *                  currently not available.The caller can retry later.Only used by asynchronous
 *                  interfaces.
 * @retval	        DEM_FILTERED_BUFFER_TOO_SMALL: Buffer in the BufSize parameter is not huge enough.
 */
FUNC(Dem_ReturnGetNextFilteredElementType , DEM_CODE)Dem_J1939DcmGetNextFilteredDTC
(
	uint32* pJ1939DTC,
	uint8* pOccurenceCounter
)
{
	uint8 u8EntryNum = 0u;
	uint16 u16DtcRef;
	Dem_EventIdType u16IntId;
	uint8 u8DtcRecord[DEM_DTC_NUM_BYTE] = {0u};
	Dem_MemoryEntryType* pEntry;

	Dem_ReturnGetNextFilteredElementType ret = DEM_FILTERED_NO_MATCHING_ELEMENT;
#if (DEM_DEV_ERROR_DETECT == STD_ON)
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
    	DEM_DET_ERROR_REPORT(DEM_SID_J1939DCMGETNEXTFILTEREDDTC,DEM_E_UNINIT);
    }
    else if ((pJ1939DTC == NULL_PTR) || (pOccurenceCounter == NULL_PTR))
    {
    	DEM_DET_ERROR_REPORT(DEM_SID_J1939DCMGETNEXTFILTEREDDTC,DEM_E_PARAM_POINTER);
    }
    else
#endif /* #if (DEM_DEV_ERROR_DETECT == STD_ON) */
    {
    	if(Dem_J1939DTCFilter.FilterSet == (boolean)TRUE)
		{
			pEntry = Dem_GetMemoryConf(Dem_J1939DTCFilter.DTCOrigin,&u8EntryNum);

			while((ret != DEM_FILTERED_OK) && (Dem_J1939DTCFilter.u8FilterIndex < u8EntryNum))
			{
				if(pEntry[Dem_J1939DTCFilter.u8FilterIndex].EventId != 0u)
				{
					u16IntId = pEntry[Dem_J1939DTCFilter.u8FilterIndex].EventId - 1u;

					u16DtcRef = Dem_ConfigPtr->DemEventParameter[u16IntId].DemDTCRef;

					if(u16DtcRef != 0xFFFFu)
					{
						/**
						 * @req [SWS_Dem_01101] A suppressed DTC shall not be visible for the following
						 *      Dcm query-functions; therefore the Dem_J1939DcmGetNextFilteredDTC shall
						 *      treat the DTC as if filter is not matching.
						 */
						if((!(Dem_ISEnable_DTCSuppress(u16DtcRef)))\
								&&(DEM_U8BIT_ISENABLE(u8DtcRecord,u16DtcRef) == 0u))
						{
							if((boolean)TRUE == Dem_J1939FilterCheck(u16DtcRef))
							{
								/* In case the function has calculated the total number of
								 * matching DTCs,the return value shall be DEM_NUMBER_OK. */
								if(Dem_J1939DTCFilter.DTCStatusFilter == DEM_J1939DTC_ACTIVE)
								{
									if((Dem_ISEnable_UdsStatusBits(u16IntId,DEM_UDS_STATUS_CDTC))\
										&&(Dem_ISEnable_UdsStatusBits(u16IntId,DEM_UDS_STATUS_TF)))
									{
										DEM_U8BIT_ENABLE(u8DtcRecord,u16DtcRef);

										Dem_GetDTCOfEvent((u16IntId + 1u),\
												DEM_DTC_FORMAT_J1939,\
												pJ1939DTC);

										*pOccurenceCounter = Dem_EventInternalData[u16IntId].occurCnt;
										ret = DEM_FILTERED_OK;
									}
									else
									{
#if(DEM_INDICATOR_ATTRIBUTE_TOTAL_NUM > 0)
										if((boolean)TRUE == Dem_CheckIndicatorStatus(u16IntId))
										{
#endif /* #if(DEM_INDICATOR_ATTRIBUTE_TOTAL_NUM > 0) */
											DEM_U8BIT_ENABLE(u8DtcRecord,u16DtcRef);
											Dem_GetDTCOfEvent((u16IntId + 1u),\
													DEM_DTC_FORMAT_J1939,\
													pJ1939DTC);

											*pOccurenceCounter = \
													Dem_EventInternalData[u16IntId].occurCnt;

											ret = DEM_FILTERED_OK;
#if(DEM_INDICATOR_ATTRIBUTE_TOTAL_NUM > 0)
										}
#endif /* #if(DEM_INDICATOR_ATTRIBUTE_TOTAL_NUM > 0) */
									}
								}
								else if(Dem_J1939DTCFilter.DTCStatusFilter \
										== DEM_J1939DTC_PREVIOUSLY_ACTIVE)
								{
									if(((Dem_ISEnable_UdsStatusBits(u16IntId,DEM_UDS_STATUS_CDTC))\
											&&(!(Dem_ISEnable_UdsStatusBits(u16IntId,\
													DEM_UDS_STATUS_TF))))
#if(DEM_INDICATOR_ATTRIBUTE_TOTAL_NUM > 0)
											&&((boolean)FALSE == Dem_CheckIndicatorStatus(u16IntId))
#endif /* #if(DEM_INDICATOR_ATTRIBUTE_TOTAL_NUM > 0) */
											)
									{
										DEM_U8BIT_ENABLE(u8DtcRecord,u16DtcRef);
										Dem_GetDTCOfEvent((u16IntId + 1u),\
												DEM_DTC_FORMAT_J1939,\
												pJ1939DTC);

										*pOccurenceCounter = Dem_EventInternalData[u16IntId].occurCnt;
										ret = DEM_FILTERED_OK;
									}
								}
								else if(Dem_J1939DTCFilter.DTCStatusFilter \
										== DEM_J1939DTC_PENDING)
								{
									if(Dem_ISEnable_UdsStatusBits(u16IntId,DEM_UDS_STATUS_PDTC))
									{
										DEM_U8BIT_ENABLE(u8DtcRecord,u16DtcRef);
										Dem_GetDTCOfEvent((u16IntId + 1u),\
												DEM_DTC_FORMAT_J1939,\
												pJ1939DTC);

										*pOccurenceCounter = Dem_EventInternalData[u16IntId].occurCnt;
										ret = DEM_FILTERED_OK;
									}
								}
								else if(Dem_J1939DTCFilter.DTCStatusFilter \
										== DEM_J1939DTC_PERMANENT)
								{
									DEM_U8BIT_ENABLE(u8DtcRecord,u16DtcRef);
									Dem_GetDTCOfEvent((u16IntId + 1u),\
											DEM_DTC_FORMAT_J1939,\
											pJ1939DTC);

									*pOccurenceCounter = Dem_EventInternalData[u16IntId].occurCnt;
									ret = DEM_FILTERED_OK;
								}
								else if(Dem_J1939DTCFilter.DTCStatusFilter \
										== DEM_J1939DTC_CURRENTLY_ACTIVE)
								{
									if(Dem_ISEnable_UdsStatusBits(u16IntId,DEM_UDS_STATUS_TF))
									{
										DEM_U8BIT_ENABLE(u8DtcRecord,u16DtcRef);
										Dem_GetDTCOfEvent((u16IntId + 1u),\
												DEM_DTC_FORMAT_J1939,\
												pJ1939DTC);

										*pOccurenceCounter = Dem_EventInternalData[u16IntId].occurCnt;
										ret = DEM_FILTERED_OK;
									}
								}
								else
								{

								}

								/**
								 * @req [SWS_Dem_00877] In case the occurrence counter is above +126
								 *      (0x7F),the returned values shall be set to +126 (0x7F).
								 */
								if((ret == DEM_FILTERED_OK) && (*pOccurenceCounter > 0x7Fu))
								{
									*pOccurenceCounter = 0x7Fu;
								}
							}
						}
					}
				}
				Dem_J1939DTCFilter.u8FilterIndex++;
			}
		}
    }
    return ret;
}
#endif /* #if(DEM_J1939READINGDTC_SUPPORT == STD_ON) */


#if(DEM_J1939DM31_SUPPORT == STD_ON)
/**
 * @sid				0x93
 * @brief			Dem_J1939DcmFirstDTCwithLampStatus
 * @details			The function sets the filter to the first applicable DTC for the DM31 response
 *                  for a specific node.
 *
 * @param[in]		node: Nm node Id of requesting client.
 */
FUNC(void , DEM_CODE) Dem_J1939DcmFirstDTCwithLampStatus
(
	uint8 node
)
{
#if (DEM_DEV_ERROR_DETECT == STD_ON)
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
    	DEM_DET_ERROR_REPORT(DEM_SID_J1939DCMFIRSTDTCWITHLAMPSTATUS,DEM_E_UNINIT);
    }
    else
#endif /* #if (DEM_DEV_ERROR_DETECT == STD_ON) */
    {
    	Dem_J1939NodeFilter.u8Node = node;
    	Dem_J1939NodeFilter.u8FilterIndex = 0u;
    	Dem_J1939NodeFilter.FilterSet = (boolean)TRUE;
    }
}


/**
 * @sid				0x94
 * @brief			Dem_J1939DcmGetNextDTCwithLampStatus
 * @details			Gets the next filtered J1939 DTC for DM31 including current LampStatus.
 *
 * @param[out]		LampStatus: Receives the lamp status returned by this function.If the return
 *                  value of the function is other than DEM_FILTERED_OK this parameter does not
 *                  contain valid data.
 *
 * @param[out]		J1939DTC: Receives the J1939DTC value. If the return value of the function is
 *                  other than DEM_FILTERED_OK this parameter does not contain valid data.
 *
 * @param[out]      OccurenceCounter: This parameter receives the corresponding occurrence counter.
 *                  If the return value of the function call is other than DEM_FILTERED_OK this
 *                  parameter does not contain valid data.
 *
 * @return     		Dem_ReturnGetNextFilteredElementType: Status of the operation to retrieve a
 *                  DTC from the Dem.
 * @retval			DEM_FILTERED_OK: Returned next filtered element.
 * @retval			DEM_FILTERED_NO_MATCHING_ELEMENT: No further element(matching the filter criteria)
 *                  found.
 * @retval			DEM_FILTERED_PENDING: The requested value is calculated asynchronously and
 *                  currently not available.The caller can retry later.Only used by asynchronous
 *                  interfaces.
 * @retval	        DEM_FILTERED_BUFFER_TOO_SMALL: Buffer in the BufSize parameter is not huge enough.
 */
FUNC(Dem_ReturnGetNextFilteredElementType , DEM_CODE)Dem_J1939DcmGetNextDTCwithLampStatus
(
		Dem_J1939DcmLampStatusType* LampStatus,
        uint32* J1939DTC,
        uint8* OccurenceCounter
)
{
	/**
	 * @req [SWS_Dem_00881] Each call to Dem_J1939DcmGetNextDTCwithLampStatus shall
	 *      search for the next event having a J1939DTC assigned for "node" set by
	 *      the function Dem_J1939DcmFirstDTCwithLampStatus.In case no more events
	 *      are available that have a J1939DTC assigend, the function return value
	 *      shall be DEM_FILTERED_NO_MATCHING_ELEMENT. The out parameter needs not
	 *      to be valid in this case.
	 */
	Dem_ReturnGetNextFilteredElementType ret = DEM_FILTERED_NO_MATCHING_ELEMENT;
	uint8 u8EntryNum = 0u;
	uint8 u8Loop = 0u;
	uint8 u8NodeNum;

#if(DEM_INDICATOR_ATTRIBUTE_TOTAL_NUM > 0)
	uint8 u8IndicatorAttrIndex;
#endif /* #if(DEM_INDICATOR_ATTRIBUTE_TOTAL_NUM > 0) */

	Dem_EventIdType u16IntId;
	uint16 u16DtcIndex;
	Dem_MemoryEntryType* pEntry;
	const uint8* pNode;

#if (DEM_DEV_ERROR_DETECT == STD_ON)
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
    	DEM_DET_ERROR_REPORT(DEM_SID_J1939DCMGETNEXTDTCWITHLAMPSTATUS,DEM_E_UNINIT);
    }
    else if((LampStatus == NULL_PTR) || (J1939DTC == NULL_PTR) || (OccurenceCounter == NULL_PTR))
    {
    	DEM_DET_ERROR_REPORT(DEM_SID_J1939DCMGETNEXTDTCWITHLAMPSTATUS,DEM_E_PARAM_POINTER);
    }
    else
#endif /* #if (DEM_DEV_ERROR_DETECT == STD_ON) */
    {
		pEntry = Dem_GetMemoryConf(DEM_DTC_ORIGIN_PRIMARY_MEMORY,&u8EntryNum);
    	while((ret != DEM_FILTERED_OK) && (Dem_J1939NodeFilter.u8FilterIndex < u8EntryNum))
    	{
    		if(pEntry[Dem_J1939NodeFilter.u8FilterIndex].EventId > 0u)
    		{
    			*J1939DTC = 0u;
    			u16IntId = pEntry[Dem_J1939NodeFilter.u8FilterIndex].EventId - 1u;
    			(void)Dem_GetDTCOfEvent(pEntry[Dem_J1939NodeFilter.u8FilterIndex].EventId,\
    					DEM_DTC_FORMAT_J1939,\
						J1939DTC);

    			if(*J1939DTC != 0)
    			{
    				u16DtcIndex = Dem_ConfigPtr->DemEventParameter[u16IntId].DemDTCRef;

    				pNode = Dem_ConfigPtr->DemJ1939Node[Dem_ConfigPtr->DemDTCAttributes\
										[Dem_ConfigPtr->DemDTC[u16DtcIndex].DemDTCAttributesRef]\
										.DemJ1939DTC_J1939NodeRef].DemJ1939NmNodeRef;

    				u8NodeNum = Dem_ConfigPtr->DemJ1939Node[Dem_ConfigPtr->DemDTCAttributes\
										[Dem_ConfigPtr->DemDTC[u16DtcIndex].DemDTCAttributesRef]\
										.DemJ1939DTC_J1939NodeRef].DemJ1939NmNodeNum;

    				while(u8Loop < u8NodeNum)
    				{
    					/**
    					 * @req [SWS_Dem_00880] Each call to Dem_J1939DcmFirstDTCwithLampStatus shall
    					 *      set the internal counter to the first event having a J1939DTC for this
    					 *      particular "node" assiged.
    					 */
    					if(*pNode == Dem_J1939NodeFilter.u8Node)
    					{
    						*OccurenceCounter = Dem_EventInternalData[u16IntId].occurCnt;

    						/**
    						 * @req [SWS_Dem_00882] In case the occurrence counter is above +126
    						 *      (0x7F),the returned values shall be set to +126 (0x7F).
    						 */
    						if(*OccurenceCounter > 0x7Fu)
							{
								*OccurenceCounter = 0x7Fu;
							}
    						ret = DEM_FILTERED_OK;
    						break;
    					}
    					u8Loop++;
    					pNode++;
    				}
    			}
    		}
    		Dem_J1939NodeFilter.u8FilterIndex++;
    	}

		*LampStatus = 0u;
#if(DEM_INDICATOR_ATTRIBUTE_TOTAL_NUM > 0)
    	if(ret == DEM_FILTERED_OK)
    	{
    		u8IndicatorAttrIndex = Dem_J1939IndicatorRefCorrespond(u16IntId,DEM_MILINDICATOR_REF);

    		if(u8IndicatorAttrIndex != 0xFFu)
    		{
    			if(Dem_ISEnable_UdsStatusBits(u16IntId,DEM_UDS_STATUS_WIR))
    			{
    				/**
    				 * @req [SWS_Dem_00883] The DTCspecific "Malfunction Indicator Lamp" returned in
    				 *      the function Dem_J1939DcmGetNextDTCwithLampStatus shall be set to "Lamp On"
    				 *      in case the corresponding event has assigned the Indicator referenced by
    				 *      DemMILIndicatorRef and the UDS DTC status bit 7(WarningIndicator) is active
    				 *      (set to 1), otherwise it shall be set to 'Lamp Off'.
    				 */
    				*LampStatus |= 0x4000u;
    			}

    			if((Dem_IndicatorStatus[DEM_MILINDICATOR_REF] != DEM_INDICATOR_OFF)\
    					&&(Dem_ConfigPtr->DemEventParameter[u16IntId].DemIndicatorAttribute\
    						[u8IndicatorAttrIndex].DemIndicatorBehaviour == DEM_INDICATOR_CONTINUOUS))
    			{
    				/**
    				 * @req [SWS_Dem_00884] The DTC-specific "Flash Malfunction Indicator Lamp" shall
    				 *      be set to "Unavailable / Do Not Flash" (0x03) in case the corresponding
    				 *      event has set "Lamp On" and the DemIndicatorBehaviour of the Indicator
    				 *      referenced by DemMILIndicatorRef is set to DEM_INDICATOR_CONTINUOUS.
    				 */
    				*LampStatus |= 0x00C0u;
    			}

    			if((Dem_IndicatorStatus[DEM_MILINDICATOR_REF] != DEM_INDICATOR_OFF)\
						&&(Dem_ConfigPtr->DemEventParameter[u16IntId].DemIndicatorAttribute\
							[u8IndicatorAttrIndex].DemIndicatorBehaviour == DEM_INDICATOR_SLOW_FLASH))
				{
					/**
					 * @req [SWS_Dem_00885] The DTC-specific "Flash Malfunction Indicator Lamp"
					 *      shall be set to "Slow Flash" (0x00) in case the corresponding event
					 *      has set "Lamp On" and the DemIndicatorBehaviour of the Indicator
					 *      referenced by DemMILIndicatorRef is set to DEM_INDICATOR_SLOW_FLASH.
					 */
					*LampStatus &= (uint8)(~(uint8)(0xC000));
				}

    			if((Dem_IndicatorStatus[DEM_MILINDICATOR_REF] != DEM_INDICATOR_OFF)\
						&&(Dem_ConfigPtr->DemEventParameter[u16IntId].DemIndicatorAttribute\
							[u8IndicatorAttrIndex].DemIndicatorBehaviour == DEM_INDICATOR_FAST_FLASH))
				{
					/**
					 * @req [SWS_Dem_00886] The DTC-specific "Flash Malfunction Indicator Lamp"
					 *      shall be set to "Fast Flash" (0x01) in case the corresponding event
					 *      has set "Lamp On" and the DemIndicatorBehaviour of the Indicator
					 *      referenced by DemMILIndicatorRef is set to DEM_INDICATOR_FAST_FLASH.
					 */
    				*LampStatus &= (uint8)(~(uint8)(0x0080));
				}
    		}

    		u8IndicatorAttrIndex = 0xFFu;
    		u8IndicatorAttrIndex = Dem_J1939IndicatorRefCorrespond(\
												u16IntId,\
												DEM_REDSTOPLAMPINDICATOR_REF);

			if(u8IndicatorAttrIndex != 0xFFu)
			{
				if(Dem_ISEnable_UdsStatusBits(u16IntId,DEM_UDS_STATUS_WIR))
				{
					/**
					 * @req [SWS_Dem_00887] The DTC-specific "Red Stop Lamp" returned in the function
					 *      Dem_J1939DcmGetNextDTCwithLampStatus shall be set to "Lamp On" in case the
					 *      corresponding event has assigned the Indicator referenced by DemRedStop-
					 *      IndicatorRef and the UDS DTC status bit 7 (WarningIndicator) is active (set
					 *      to 1), otherwise it shall be set to "Lamp Off".
					 */
					*LampStatus |= 0x0100u;
				}

				if((Dem_IndicatorStatus[DEM_REDSTOPLAMPINDICATOR_REF] != DEM_INDICATOR_OFF)\
						&&(Dem_ConfigPtr->DemEventParameter[u16IntId].DemIndicatorAttribute\
							[u8IndicatorAttrIndex].DemIndicatorBehaviour == DEM_INDICATOR_CONTINUOUS))
				{
					/**
					 * @req [SWS_Dem_00888] The DTC-specific "Flash Red Stop Lamp" shall be set to
					 *      "Unavailable / Do Not Flash" (0x03) in case the corresponding event has
					 *      set "Lamp On" and the DemIndicatorBehaviour of the Indicator referenced
					 *      by DemRedStopIndicatorRef is set to DEM_INDICATOR_CONTINUOUS.
					 */
					*LampStatus |= 0x0030u;
				}

				if((Dem_IndicatorStatus[DEM_REDSTOPLAMPINDICATOR_REF] != DEM_INDICATOR_OFF)\
						&&(Dem_ConfigPtr->DemEventParameter[u16IntId].DemIndicatorAttribute\
							[u8IndicatorAttrIndex].DemIndicatorBehaviour == DEM_INDICATOR_SLOW_FLASH))
				{
					/**
					 * @req [SWS_Dem_00889] The DTC-specific "Flash Red Stop Lamp" shall be set to
					 *      "Slow Flash" (0x00) in case the corresponding event has set "Lamp On"
					 *      and the DemIndicatorBehaviour of the Indicator referenced by DemRedStop-
					 *      IndicatorRef is set to DEM_INDICATOR_SLOW_FLASH.
					 */
					*LampStatus &= (uint8)(~(uint8)(0x0300));
				}

				if((Dem_IndicatorStatus[DEM_MILINDICATOR_REF] != DEM_INDICATOR_OFF)\
						&&(Dem_ConfigPtr->DemEventParameter[u16IntId].DemIndicatorAttribute\
							[u8IndicatorAttrIndex].DemIndicatorBehaviour == DEM_INDICATOR_FAST_FLASH))
				{
					/**
					 * @req [SWS_Dem_00890] The DTC-specific "Flash Red Stop Lamp" shall be set to
					 *      "Fast Flash" (0x01) in case the corresponding event has set "Lamp On"
					 *      and the DemIndicatorBehaviour of the Indicator referenced by DemRedStop-
					 *      IndicatorRef is set to DEM_INDICATOR_FAST_FLASH.
					 */
					*LampStatus &= (uint8)(~(uint8)(0x0020));
				}
			}

			u8IndicatorAttrIndex = 0xFFu;
			u8IndicatorAttrIndex = Dem_J1939IndicatorRefCorrespond(\
												u16IntId,\
												DEM_AMBERWARNINGLAMPINDICATOR_REF);

			if(u8IndicatorAttrIndex != 0xFFu)
			{
				if(Dem_ISEnable_UdsStatusBits(u16IntId,DEM_UDS_STATUS_WIR))
				{
					/**
					 * @req [SWS_Dem_00891] The DTC-specific "Amber Warning Lamp" returned in the
					 *      function Dem_J1939DcmGetNextDTCwithLampStatus shall be set to "Lamp On"
					 *      in case the corresponding event has assigned the Indicator referenced
					 *      by DemAmberWarningIndicatorRef and the UDS DTC status bit 7 (Warning-
					 *      Indicator) is active (set to 1),otherwise it shall be set to "Lamp Off".
					 */
					*LampStatus |= 0x0400u;
				}

				if((Dem_IndicatorStatus[DEM_REDSTOPLAMPINDICATOR_REF] != DEM_INDICATOR_OFF)\
						&&(Dem_ConfigPtr->DemEventParameter[u16IntId].DemIndicatorAttribute\
							[u8IndicatorAttrIndex].DemIndicatorBehaviour == DEM_INDICATOR_CONTINUOUS))
				{
					/**
					 * @req [SWS_Dem_00892] The DTC-specific "Flash Amber Warning Lamp" shall be set
					 *      to "Unavailable / Do Not Flash" (0x03) in case the corresponding event has
					 *      set "Lamp On" and the DemIndicatorBehaviour of the Indicator referenced
					 *      by DemAmberWarningIndicatorRef is set to DEM_INDICATOR_CONTINUOUS.
					 */
					*LampStatus |= 0x000Cu;
				}

				if((Dem_IndicatorStatus[DEM_REDSTOPLAMPINDICATOR_REF] != DEM_INDICATOR_OFF)\
						&&(Dem_ConfigPtr->DemEventParameter[u16IntId].DemIndicatorAttribute\
							[u8IndicatorAttrIndex].DemIndicatorBehaviour == DEM_INDICATOR_SLOW_FLASH))
				{
					/**
					 * @req [SWS_Dem_00893] The DTC-specific "Flash Amber Warning Lamp" shall be set
					 *      to "Slow Flash" (0x00) in case the corresponding event has set "Lamp On"
					 *      and the DemIndicatorBehaviour of the Indicator referenced by DemAmber-
					 *      WarningIndicatorRef is set to DEM_INDICATOR_SLOW_FLASH.
					 */
					*LampStatus &= (uint8)(~(uint8)(0x000C));
				}

				if((Dem_IndicatorStatus[DEM_REDSTOPLAMPINDICATOR_REF] != DEM_INDICATOR_OFF)\
						&&(Dem_ConfigPtr->DemEventParameter[u16IntId].DemIndicatorAttribute\
							[u8IndicatorAttrIndex].DemIndicatorBehaviour == DEM_INDICATOR_FAST_FLASH))
				{
					/**
					 * @req [SWS_Dem_00894] The DTC-specific "Flash Amber Warning Lamp" shall be set
					 *      to "Fast Flash" (0x01) in case the corresponding event has set "Lamp On"
					 *      and the DemIndicatorBehaviour of the Indicator referenced by DemAmber-
					 *      WarningIndicatorRef is set to DEM_INDICATOR_FAST_FLASH.
					 */
					*LampStatus &= (uint8)(~(uint8)(0x0008));
				}
			}

			u8IndicatorAttrIndex = 0xFFu;
			u8IndicatorAttrIndex = Dem_J1939IndicatorRefCorrespond(\
												u16IntId,\
												DEM_PROTECTLAMPINDICATOR_REF);

			if(u8IndicatorAttrIndex != 0xFFu)
			{
				if(Dem_ISEnable_UdsStatusBits(u16IntId,DEM_UDS_STATUS_WIR))
				{
					/**
					 * @req [SWS_Dem_00895] The DTC-specific "Protect Lamp" returned in the function
					 *      Dem_J1939DcmGetNextDTCwithLampStatus shall be set to "Lamp On" in case
					 *      the corresponding event has assigned the Indicator referenced by Dem-
					 *      ProtectLampIndicatorRef and the UDS DTC status bit 7 (WarningIndicator)
					 *      is active (set to 1),otherwise it shall be set to "Lamp Off".
					 */
					*LampStatus |= 0x0100u;
				}

				if((Dem_IndicatorStatus[DEM_PROTECTLAMPINDICATOR_REF] != DEM_INDICATOR_OFF)\
						&&(Dem_ConfigPtr->DemEventParameter[u16IntId].DemIndicatorAttribute\
							[u8IndicatorAttrIndex].DemIndicatorBehaviour == DEM_INDICATOR_CONTINUOUS))
				{
					/**
					 * @req [SWS_Dem_00896] The DTC-specific "Flash Protect Lamp" shall be set to
					 *      "Unavailable / Do Not Flash" (0x03) in case the corresponding event has
					 *      set "Lamp On" and the DemIndicatorBehaviour of the Indicator referenced
					 *      by DemProtectLampIndicatorRef is set to DEM_INDICATOR_CONTINUOUS.
					 */
					*LampStatus |= 0x0003u;
				}

				if((Dem_IndicatorStatus[DEM_PROTECTLAMPINDICATOR_REF] != DEM_INDICATOR_OFF)\
						&&(Dem_ConfigPtr->DemEventParameter[u16IntId].DemIndicatorAttribute\
							[u8IndicatorAttrIndex].DemIndicatorBehaviour == DEM_INDICATOR_SLOW_FLASH))
				{
					/**
					 * @req [SWS_Dem_00897] The DTC-specific "Flash Protect Lamp" shall be set to
					 *      "Slow Flash" (0x00) in case the corresponding event has set "Lamp On"
					 *      and the DemIndicatorBehaviour of the Indicator referenced by DemProtect-
					 *      LampIndicatorRef is set to DEM_INDICATOR_SLOW_FLASH.
					 */
					*LampStatus &= (uint8)(~(uint8)(0x0003));
				}

				if((Dem_IndicatorStatus[DEM_PROTECTLAMPINDICATOR_REF] != DEM_INDICATOR_OFF)\
						&&(Dem_ConfigPtr->DemEventParameter[u16IntId].DemIndicatorAttribute\
							[u8IndicatorAttrIndex].DemIndicatorBehaviour == DEM_INDICATOR_FAST_FLASH))
				{
					/**
					 * @req [SWS_Dem_00898] The DTC-specific "Flash Protect Lamp" shall be set to
					 *      "Fast Flash" (0x01) in case the corresponding event has set "Lamp On"
					 *      and the DemIndicatorBehaviour of the Indicator referenced by DemProtect-
					 *      LampIndicatorRef is set to DEM_INDICATOR_FAST_FLASH.
					 */
					*LampStatus &= (uint8)(~(uint8)(0x0002));
				}
			}
    	}
#endif /* #if(DEM_INDICATOR_ATTRIBUTE_TOTAL_NUM > 0) */
    }
    return ret;
}
#endif /* #if(DEM_J1939DM31_SUPPORT == STD_ON) */

#if(DEM_J1939CLEARDTC_SUPPORT == STD_ON)
/**
 * @sid				0x95
 * @brief			Dem_J1939DcmClearDTC
 * @details			Clears active DTCs as well as previously active DTCs.
 *
 * @param[in]		DTCTypeFilter: The following types are available: DEM_J1939DTC_CLEAR_ALL,
 *                  DEM_J1939DTC_CLEAR_PREVIOUSLY_ACTIVE.
 *
 * @param[in]       node: Nm node Id of requesting client.
 *
 * @return     		Dem_ReturnClearDTCType: Status of the operation of type Dem_ReturnClearDTCType.
 * @retval			DEM_CLEAR_OK: DTC successfully cleared.
 * @retval			DEM_CLEAR_WRONG_DTC: DTC value not existing (in this format).
 * @retval			DEM_CLEAR_WRONG_DTCORIGIN: Wrong DTC origin.
 * @retval	        DEM_CLEAR_FAILED: DTC clearing failed.
 * @retval			DEM_CLEAR_PENDING: The DTC clearing is performed asynchronously and still
 *                  pending. The caller can retry later.
 * @retval			DEM_CLEAR_BUSY: DTC not cleared, as another clearing process is in progress.
 *                  The caller can retry later.
 * @retval			DEM_CLEAR_MEMORY_ERROR: An error occurred during erasing a memory location.
 */
FUNC(Dem_ReturnClearDTCType, DEM_CODE)Dem_J1939DcmClearDTC
(
    Dem_J1939DcmSetClearFilterType DTCTypeFilter,
    uint8 node
)
{
	Dem_ReturnClearDTCType ret = DEM_CLEAR_WRONG_DTC;

#if (DEM_DEV_ERROR_DETECT == STD_ON)
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
    	DEM_DET_ERROR_REPORT(DEM_SID_J1939DCMCLEARDTC,DEM_E_UNINIT);
    }
    else
#endif /* #if (DEM_DEV_ERROR_DETECT == STD_ON) */
    {
    	if(Dem_ClearDtcLock == (boolean)FALSE)
    	{
    		Dem_J1939DtcClearInfo.DtcType = DTCTypeFilter;
    		Dem_J1939DtcClearInfo.node = node;
    		Dem_ClearDtcLock = (boolean)TRUE;

    		Dem_ClearJ1939DTC();
    		Dem_ClearDtcLock = (boolean)FALSE;
    		ret = DEM_CLEAR_OK;
    	}
    	else
    	{
    		if((Dem_J1939DtcClearInfo.DtcType == DTCTypeFilter)\
    				&&(Dem_J1939DtcClearInfo.node == node))
    		{
    			ret = DEM_CLEAR_PENDING;

    		}
    		else
    		{
    			ret = DEM_CLEAR_BUSY;
    		}
    	}
    }

    return ret;
}
#endif /* #if(DEM_J1939CLEARDTC_SUPPORT == STD_ON) */

#if((DEM_J1939FREEZEFRAME_SUPPORT == STD_ON) || (DEM_J1939EXPANDEDFREEZEFRAME_SUPPORT == STD_ON))
/**
 * @sid				0x96
 * @brief			Dem_J1939DcmSetFreezeFrameFilter
 * @details			The function sets the FreezeFrame filter for a specific node.
 *
 * @param[in]		FreezeFrameKind: The following types are available: DEM_J1939DCM_FREEZEFRAME,
 *                  DEM_J1939DCM_EXPANDED_FREEZEFRAME, DEM_J1939DCM_SPNS_IN_EXPANDED_FREEZEFRAME.
 *
 * @param[in]       node: Nm node Id of requesting client.
 *
 * @return     		Dem_ReturnSetFilterType: Status of the operation to (re-)set a FreezeFrame filter.
 * @retval			DEM_FILTER_ACCEPTED: Filter was accepted.
 * @retval			DEM_WRONG_FILTER: Wrong filter selected.
 */
FUNC(Dem_ReturnSetFilterType , DEM_CODE)Dem_J1939DcmSetFreezeFrameFilter
(
	Dem_J1939DcmSetFreezeFrameFilterType FreezeFrameKind,
	uint8 node
)
{
	Dem_ReturnSetFilterType ret = DEM_WRONG_FILTER;

#if (DEM_DEV_ERROR_DETECT == STD_ON)
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
    	DEM_DET_ERROR_REPORT(DEM_SID_J1939DCMSETFREEZEFRAMEFILTER,DEM_E_UNINIT);
    }
    else
#endif /* #if (DEM_DEV_ERROR_DETECT == STD_ON) */
    {
    	Dem_J1939FFFilter.FilterSet = (boolean)TRUE;
    	Dem_J1939FFFilter.FFKind = FreezeFrameKind;
    	Dem_J1939FFFilter.u8Node = node;
    	Dem_J1939FFFilter.u8FilterIndex = 0u;
    	ret = DEM_FILTER_ACCEPTED;
    }
    return ret;
}

/**
 * @sid				0x97
 * @brief			Dem_J1939DcmGetNextFreezeFrame
 * @details			Gets next freeze frame data. The function stores the data in the provided
 *                  DestBuffer.
 *
 * @param[in-out]	DestBuffer: This parameter contains a byte pointer that points to the buffer,
 *                  to which the freeze frame data record shall be written to.
 *
 * @param[in-out]	BufSize: When the function is called this parameter contains the maximum number
 *                  of data bytes that can be written to the buffer.The function returns the actual
 *                  number of written data bytes in DestBuffer.
 *
 * @param[out]      J1939DTC: Receives the J1939DTC value. If the return value of the function is
 *                  other than DEM_FILTERED_OK this parameter does not contain valid data.
 *
 * @param[out]      OccurenceCounter: This parameter receives the corresponding occurrence counter.
 *                  If the return value of the function call is other than DEM_FILTERED_OK this
 *                  parameter does not contain valid data.
 *
 * @return     		Dem_ReturnGetNextFilteredElementType: Status of the operation to retrieve freeze
 *                  frame data by DTC.
 * @retval			DEM_FILTERED_OK: Returned next filtered element.
 * @retval			DEM_FILTERED_NO_MATCHING_ELEMENT: No further element (matching the filter criteria)
 *                  found.
 * @retval			DEM_FILTERED_PENDING: The requested value is calculated asynchronously and
 *                  currently not available.The caller can retry later.Only used by asynchronous
 *                  interfaces.
 * @retval			DEM_FILTERED_BUFFER_TOO_SMALL: Buffer in the BufSize parameter is not huge enough.
 */
FUNC(Dem_ReturnGetNextFilteredElementType , DEM_CODE)Dem_J1939DcmGetNextFreezeFrame
(
	uint32* J1939DTC,
    uint8* OccurenceCounter,
    uint8* DestBuffer,
    uint16* BufSize
)
{
	Dem_ReturnGetNextFilteredElementType ret = DEM_FILTERED_NO_MATCHING_ELEMENT;

	uint8 u8EntryNum = 0u;
	Dem_EventIdType u16IntId;
	uint8 u8Index = 0u;
	uint16 u16DtcIndex;
	uint16 u16DateSize;
	uint8 u8FFIndex;
	Dem_MemoryEntryType* pEntry;

#if (DEM_DEV_ERROR_DETECT == STD_ON)
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
    	DEM_DET_ERROR_REPORT(DEM_SID_J1939DCMGETNEXTFREEZEFRAME,DEM_E_UNINIT);
    }
    else if((J1939DTC == NULL_PTR) || (OccurenceCounter == NULL_PTR) \
    		|| (DestBuffer == NULL_PTR) || (BufSize == NULL_PTR))
    {
    	DEM_DET_ERROR_REPORT(DEM_SID_J1939DCMGETNEXTFREEZEFRAME,DEM_E_PARAM_POINTER);
    }
    else
#endif /* #if (DEM_DEV_ERROR_DETECT == STD_ON) */
    {
    	if(Dem_J1939FFFilter.FilterSet == (boolean)TRUE)
    	{
    		pEntry = Dem_GetMemoryConf(DEM_DTC_ORIGIN_PRIMARY_MEMORY,&u8EntryNum);

    		while((ret != DEM_FILTERED_OK)\
    				&&(Dem_J1939FFFilter.u8FilterIndex < u8EntryNum))
    		{
    			if(pEntry[Dem_J1939FFFilter.u8FilterIndex].EventId != 0u)
    			{
    				u16IntId = pEntry[Dem_J1939FFFilter.u8FilterIndex].EventId - 1u;
    				*J1939DTC = 0u;

    				/**
    				 * @req [SWS_Dem_00901] Set the parameter J1939DTC to the corresponding J1939DTC
    				 *      value (refer DemDTCAttributes for details) and the parameter Occurrence-
    				 *      Counter to the corresponding occurrence counter value.
    				 */
    				(void)Dem_GetDTCOfEvent(pEntry[Dem_J1939FFFilter.u8FilterIndex].EventId,\
    				    					DEM_DTC_FORMAT_J1939,\
											J1939DTC);

    				if(J1939DTC != 0u)
    				{
    					u16DtcIndex = Dem_ConfigPtr->DemEventParameter[u16IntId].DemDTCRef;

						if((boolean)TRUE == Dem_J1939DcmSearchNode(u16DtcIndex,\
								Dem_J1939FFFilter.u8Node))
						{
							*OccurenceCounter = Dem_EventInternalData[u16IntId].occurCnt;

							if(*OccurenceCounter > 0x7Fu)
							{
								/**
								 * @req [SWS_Dem_00901] Return with DEM_FILTERED_OK. In case the
								 *      occurrence counter is above +126 (0x7F), the returned
								 *      value shall be set to +126 (0x7F).
								 */
								*OccurenceCounter = 0x7Fu;
							}
							if(Dem_J1939FFFilter.FFKind == DEM_J1939DCM_FREEZEFRAME)
							{
								u8FFIndex = Dem_ConfigPtr->DemDTCAttributes[Dem_ConfigPtr->\
													   DemDTC[u16DtcIndex].DemDTCAttributesRef].\
														  DemJ1939FreezeFrameClassRef;

								ret = DEM_FILTERED_OK;
							}
							else if (Dem_J1939FFFilter.FFKind == DEM_J1939DCM_EXPANDED_FREEZEFRAME)
							{
								u8FFIndex = Dem_ConfigPtr->DemDTCAttributes[Dem_ConfigPtr->\
													   DemDTC[u16DtcIndex].DemDTCAttributesRef].\
															   DemJ1939ExpandedFreezeFrameClassRef;
								ret = DEM_FILTERED_OK;
							}
							else
							{
								/**
								 * @req [SWS_Dem_00901] The function Dem_J1939DcmGetNextFreezeFrame
								 *      shall trigger the Det error DEM_E_WRONG_CONDITION in case
								 *      of not supported FreezeFrameKind.Valid values are DEM_J1939
								 *      DCM_FREEZEFRAME and DEM_J1939DCM_EXPANDED_FREEZE-FRAME.
								 */
#if (DEM_DEV_ERROR_DETECT == STD_ON)
								DEM_DET_ERROR_REPORT(\
										DEM_SID_J1939DCMGETNEXTFREEZEFRAME,\
										DEM_E_WRONG_CONFIGURATION);
#endif /* #if (DEM_DEV_ERROR_DETECT == STD_ON) */
							}

							if(ret == DEM_FILTERED_OK)
							{
								if(u8FFIndex != 0xFFu)
								{
									while((u8Index < DEM_MAX_NUMBER_FF_RECORDS) &&(ret == DEM_FILTERED_OK))
									{
										if(*BufSize < Dem_General.DemGeneralJ1939->\
												DemJ1939FreezeFrameClasses[u8FFIndex].FFDataSize)
										{
											/**
											 * @req [SWS_Dem_00903] Check if the buffer in the BufSize
											 *      parameter is big enough to hold the (Expanded-)
											 *      FreezeFrame. If not, DEM_FILTERED_BUFFER_TOO_SMALL
											 *      shall be returned without any further actions. The
											 *      out parameters need not to be valid in this case.
											 */
											ret = DEM_FILTERED_BUFFER_TOO_SMALL;
										}
										else
										{
											u16DateSize = Dem_General.DemGeneralJ1939->\
												DemJ1939FreezeFrameClasses[u8FFIndex].FFDataSize;
											/**
											 * @req [SWS_Dem_00903]Copy the (Expanded-)FreezeFrame data
											 *      into the buffer provided by the parameter DestBuffer
											 *      (in case of Expanded FreezeFrames without any SPN
											 *      informations).Unused bits shall be filled with "0".
											 */
											DEM_VALUE_COPY(\
													DestBuffer,\
													pEntry->FFInfo[0].FFData,
													u16DateSize);

											*BufSize = Dem_General.DemGeneralJ1939->\
												DemJ1939FreezeFrameClasses[u8FFIndex].FFDataSize;
										}
										u8Index++;
									}
								}
								else
								{
									ret = DEM_FILTERED_NO_MATCHING_ELEMENT;
								}
							}
						}
    				}
    			}
    			Dem_J1939FFFilter.u8FilterIndex++;
    		}
    	}
    }
    return ret;
}
#endif /* #if((DEM_J1939FREEZEFRAME_SUPPORT == STD_ON) \
          || (DEM_J1939EXPANDEDFREEZEFRAME_SUPPORT == STD_ON)) */

#if(DEM_J1939EXPANDEDFREEZEFRAME_SUPPORT == STD_ON)
/**
 * @sid				0x98
 * @brief			Dem_J1939DcmGetNextSPNInFreezeFrame
 * @details			Gets next SPN.
 *
 * @param[out]      SPNSupported: This parameter contains the next SPN in the ExpandedFreezeFrame.
 *
 * @param[out]      SPNDataLength: This parameter contains the corresponding dataLength of the SPN.
 *
 * @return     		Dem_ReturnGetNextFilteredElementType: Status of the operation to retrieve freeze
 *                  frame data by DTC.
 * @retval			DEM_FILTERED_OK: Returned next filtered element.
 * @retval			DEM_FILTERED_NO_MATCHING_ELEMENT: No further element (matching the filter criteria)
 *                  found.
 * @retval			DEM_FILTERED_PENDING: The requested value is calculated asynchronously and
 *                  currently not available.The caller can retry later.Only used by asynchronous
 *                  interfaces.
 * @retval			DEM_FILTERED_BUFFER_TOO_SMALL: Buffer in the BufSize parameter is not huge enough.
 */
FUNC(Dem_ReturnGetNextFilteredElementType , DEM_CODE)Dem_J1939DcmGetNextSPNInFreezeFrame
(
	uint32* SPNSupported,
	uint8* SPNDataLength
)
{
	Dem_ReturnGetNextFilteredElementType ret = DEM_FILTERED_NO_MATCHING_ELEMENT;

	uint8 u8EntryNum = 0u;
	uint8 u8Loop = 0u;
	uint8 u8FFIndex;
	uint16 u16DtcIndex;
	uint32 u32J1939Dtc = 0u;
	Dem_EventIdType u16IntId;
	Dem_MemoryEntryType* pEntry;

#if (DEM_DEV_ERROR_DETECT == STD_ON)
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
    	DEM_DET_ERROR_REPORT(DEM_SID_J1939DCMGETNEXTSPNINFREEZEFRAME,DEM_E_UNINIT);
    }
    else if((SPNSupported == NULL_PTR) || (SPNDataLength == NULL_PTR))
    {
    	DEM_DET_ERROR_REPORT(DEM_SID_J1939DCMGETNEXTSPNINFREEZEFRAME,DEM_E_PARAM_POINTER);
    }
    else
#endif /* #if (DEM_DEV_ERROR_DETECT == STD_ON) */
    {
    	if(Dem_J1939FFFilter.FilterSet == (boolean)TRUE)
		{
			pEntry = Dem_GetMemoryConf(DEM_DTC_ORIGIN_PRIMARY_MEMORY,&u8EntryNum);

			while((ret != DEM_FILTERED_OK)\
					&&(Dem_J1939FFFilter.u8FilterIndex < u8EntryNum))
			{
				if(pEntry[Dem_J1939FFFilter.u8FilterIndex].EventId != 0u)
				{
					u16IntId = pEntry[Dem_J1939FFFilter.u8FilterIndex].EventId - 1u;

					(void)Dem_GetDTCOfEvent(pEntry[Dem_J1939FFFilter.u8FilterIndex].EventId,\
											DEM_DTC_FORMAT_J1939,\
											&u32J1939Dtc);

					if(u32J1939Dtc != 0u)
					{
						u16DtcIndex = Dem_ConfigPtr->DemEventParameter[u16IntId].DemDTCRef;

						if((boolean)TRUE == Dem_J1939DcmSearchNode(u16DtcIndex,\
								Dem_J1939FFFilter.u8Node))
						{
							if(Dem_J1939FFFilter.FFKind \
									== DEM_J1939DCM_SPNS_IN_EXPANDED_FREEZEFRAME)
							{
								u8FFIndex = Dem_ConfigPtr->DemDTCAttributes[Dem_ConfigPtr->\
													   DemDTC[u16DtcIndex].DemDTCAttributesRef].\
															   DemJ1939ExpandedFreezeFrameClassRef;
								if(u8FFIndex != 0xFFu)
								{
									ret = DEM_FILTERED_OK;

									if(Dem_J1939FFFilter.IsNextFF == (boolean)TRUE)
									{
										Dem_J1939FFFilter.u8SPNConter = 0u;
										Dem_J1939FFFilter.IsNextFF = (boolean)FALSE;
									}

									if(Dem_J1939FFFilter.u8SPNConter < Dem_General.DemGeneralJ1939\
											->DemJ1939FreezeFrameClasses[u8FFIndex].SPNClassRefNum)
									{
										Dem_J1939FFFilter.u32SPNIndex = Dem_General.DemGeneralJ1939->\
												DemJ1939FreezeFrameClasses[u8FFIndex].SPNClassStart[u8Loop];

										*SPNSupported = Dem_General.DemGeneralJ1939->DemSPNClasses\
												[Dem_J1939FFFilter.u32SPNIndex].DemSPNId;

										*SPNDataLength = Dem_General.DemGeneralJ1939->DemSPNClasses\
												[Dem_J1939FFFilter.u32SPNIndex].SPNDataSize;

										Dem_J1939FFFilter.u8SPNConter++;
									}

									if(Dem_J1939FFFilter.u8SPNConter == Dem_General.DemGeneralJ1939
											->DemJ1939FreezeFrameClasses[u8FFIndex].SPNClassRefNum)
									{
										Dem_J1939FFFilter.IsNextFF = (boolean)TRUE;
									}
								}
								else
								{
									ret = DEM_FILTERED_NO_MATCHING_ELEMENT;
								}

							}
							else
							{
								/**
								 * @req [SWS_Dem_00906] The function Dem_J1939DcmGetNextSPNIn-
								 *      FreezeFrame shall trigger the Det error DEM_E_WRONG_CO
								 *      NDITION in case of not supported FreezeFrameKind.Valid
								 *      value is Dem_SPNsInExpandedFreezeFrame.
								 */
#if (DEM_DEV_ERROR_DETECT == STD_ON)
								DEM_DET_ERROR_REPORT(\
										DEM_SID_J1939DCMGETNEXTSPNINFREEZEFRAME,\
										DEM_E_WRONG_CONFIGURATION);
#endif /* #if (DEM_DEV_ERROR_DETECT == STD_ON) */
							}
						}
					}
				}
				Dem_J1939FFFilter.u8FilterIndex++;
			}
		}
    }

    return ret;
}
#endif /* (DEM_J1939EXPANDEDFREEZEFRAME_SUPPORT == STD_ON) */

#if((DEM_RATIO_NUM > 0) && (DEM_J1939RATIO_SUPPORT == STD_ON))
/**
 * @sid				0x99
 * @brief			Dem_J1939DcmSetRatioFilter
 * @details			The function sets the Ratio filter for a specific node and returns the
 *                  corresponding Ignition Cycle Counter and General Denominator.
 *
 * @param[out]      IgnitionCycleCounter: Ignition Cycle Counter.
 *
 * @param[out]      OBDMonitoringConditionsEncountered: OBD Monitoring Conditions Encountered.
 *
 * @return     		Dem_ReturnSetFilterType: Status of the operation to (re-)set a DTC filter.
 * @retval			DEM_FILTER_ACCEPTED: Filter was accepted.
 * @retval			DEM_WRONG_FILTER: Wrong filter selected.
 */
FUNC(Dem_ReturnSetFilterType , DEM_CODE)Dem_J1939DcmSetRatioFilter
(
	uint16* IgnitionCycleCounter,
    uint16* OBDMonitoringConditionsEncountered,
    uint8 node
)
{
	Dem_ReturnSetFilterType ret = DEM_WRONG_FILTER;
	uint16 u16Loop = 0u;
	uint8 u8EntryNum = 0u;
	uint16 u16DtcIndex;
	uint32 u32J1939Dtc = 0u;
	Dem_EventIdType u16IntId;
	Dem_MemoryEntryType* pEntry;

#if (DEM_DEV_ERROR_DETECT == STD_ON)
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
    	DEM_DET_ERROR_REPORT(DEM_SID_J1939DCMSETRATIOFILTER,DEM_E_UNINIT);
    }
    else if((IgnitionCycleCounter == NULL_PTR) || (OBDMonitoringConditionsEncountered == NULL_PTR))
    {
    	DEM_DET_ERROR_REPORT(DEM_SID_J1939DCMSETRATIOFILTER,DEM_E_PARAM_POINTER);
    }
    else
#endif /* #if (DEM_DEV_ERROR_DETECT == STD_ON) */
    {

    	pEntry = Dem_GetMemoryConf(DEM_DTC_ORIGIN_PRIMARY_MEMORY,&u8EntryNum);

    	Dem_J1939RatioFilter.FilterSet = (boolean)TRUE;
    	Dem_J1939RatioFilter.u8FilterIndex = 0u;
    	Dem_J1939RatioFilter.u8Node = node;

    	/**
    	 * @req [SWS_Dem_00912] The function Dem_J1939DcmSetRatioFilter shall reset an internal
    	 *      counter to the first valid SPN with DemRatioId defined to be used for the sub-
    	 *      sequent calls of Dem_J1939DcmGetNextFilteredRatio.It shall return the "Ignition
    	 *      Cycle Counter" according SAEJ193973 chapter 5.7.20.1,as well as "OBD Monitoring
    	 *      Conditions Encountered" according SAEJ193973 chapter 5.7.20.2 (CARB defines this
    	 *      as the general denominator).
    	 */
    	*IgnitionCycleCounter = Dem_IgnitionCycleCounter;
    	*OBDMonitoringConditionsEncountered = Dem_GeneralDenominator[0];

    	while(Dem_J1939RatioFilter.u8FilterIndex < u8EntryNum)
    	{
    		if(pEntry[Dem_J1939RatioFilter.u8FilterIndex].EventId != 0u)
    		{
    			u16IntId = pEntry[Dem_J1939RatioFilter.u8FilterIndex].EventId - 1u;

				(void)Dem_GetDTCOfEvent(pEntry[Dem_J1939RatioFilter.u8FilterIndex].EventId,\
										DEM_DTC_FORMAT_J1939,\
										&u32J1939Dtc);

				if(u32J1939Dtc != 0u)
				{
					u16DtcIndex = Dem_ConfigPtr->DemEventParameter[u16IntId].DemDTCRef;

					/**
					 * @req [SWS_Dem_01101] A suppressed DTC shall not be visible for the following Dcm
					 *      query-functions; therefore this functions shall treat the DTC as if filter
					 *      is not matching.
					 */
					if((!(Dem_ISEnable_DTCSuppress(u16DtcIndex)))\
							&& ((boolean)TRUE == Dem_J1939DcmSearchNode(u16DtcIndex,node)))
					{
						while(u16Loop < DEM_RATIO_NUM)
						{
							if(Dem_General.DemRatio[u16Loop].DemDiagnosticEventRef == u16IntId)
							{
								ret = DEM_FILTER_ACCEPTED;
								break;
							}
							u16Loop++;
						}
						if(ret == DEM_FILTER_ACCEPTED)
						{
							break;
						}
					}
				}
    		}
    		Dem_J1939RatioFilter.u8FilterIndex++;
    	}
    }
    return ret;
}

/**
 * @sid				0x9a
 * @brief			Dem_J1939DcmGetNextFilteredRatio
 * @details			Gets the next filtered Ratio.
 *
 * @param[out]      SPN: Receives the SPN of the applicaple system monitor. If the return value
 *                  of the function is other than DEM_FILTERED_OK this parameter does not contain
 *                  valid data.
 *
 * @param[out]      Numerator: Receives the Numerator of the applicable system monitor. If the
 *                  return value of the function is other than DEM_FILTERED_OK this parameter
 *                  does not contain valid data.
 *
 * @param[out]		Denominator: Receives the Denominator of the applicable system monitor. If the
 *                  return value of the function is other than DEM_FILTERED_OK this parameter does
 *                  not contain valid data.
 *
 * @return     		Dem_ReturnGetNextFilteredElementType: Status of the operation to (re-)get a DTC
 *                  filter.
 * @retval			DEM_FILTERED_OK: Ratio available in out parameter.
 * @retval			DEM_FILTERED_NO_FURTHERELEMENT: No further element available.
 */
FUNC(Dem_ReturnGetNextFilteredElementType , DEM_CODE)Dem_J1939DcmGetNextFilteredRatio
(
	uint16* SPN,
    uint16* Numerator,
    uint16* Denominator
)
{
	Dem_ReturnGetNextFilteredElementType ret = DEM_FILTERED_NO_MATCHING_ELEMENT;
	uint16 u16Loop = 0u;
	uint8 u8EntryNum = 0u;
	uint16 u16DtcIndex;
	uint32 u32J1939Dtc = 0u;
	Dem_EventIdType u16IntId;
	Dem_MemoryEntryType* pEntry;

#if (DEM_DEV_ERROR_DETECT == STD_ON)
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
    	DEM_DET_ERROR_REPORT(DEM_SID_J1939DCMSETRATIOFILTER,DEM_E_UNINIT);
    }
    else if((SPN == NULL_PTR) || (Numerator == NULL_PTR) || (Denominator == NULL_PTR))
    {
    	DEM_DET_ERROR_REPORT(DEM_SID_J1939DCMSETRATIOFILTER,DEM_E_PARAM_POINTER);
    }
    else
#endif /* #if (DEM_DEV_ERROR_DETECT == STD_ON) */
    {
    	if(Dem_J1939RatioFilter.FilterSet == (boolean)TRUE)
    	{
			pEntry = Dem_GetMemoryConf(DEM_DTC_ORIGIN_PRIMARY_MEMORY,&u8EntryNum);
			while((Dem_J1939RatioFilter.u8FilterIndex < u8EntryNum))
			{
				if(pEntry[Dem_J1939RatioFilter.u8FilterIndex].EventId != 0u)
				{
					u16IntId = pEntry[Dem_J1939RatioFilter.u8FilterIndex].EventId - 1u;

					(void)Dem_GetDTCOfEvent(pEntry[Dem_J1939RatioFilter.u8FilterIndex].EventId,\
											DEM_DTC_FORMAT_J1939,\
											&u32J1939Dtc);

					if(u32J1939Dtc != 0u)
					{
						u16DtcIndex = Dem_ConfigPtr->DemEventParameter[u16IntId].DemDTCRef;

						/**
						 * @req [SWS_Dem_01101] A suppressed DTC shall not be visible for the following
						 *      Dcm query-functions; therefore this functions shall treat the DTC as if
						 *      filter is not matching.
						 */
						if((!(Dem_ISEnable_DTCSuppress(u16DtcIndex)))\
								&& ((boolean)TRUE == Dem_J1939DcmSearchNode(u16DtcIndex,\
										Dem_J1939RatioFilter.u8Node)))
						{
							while(u16Loop < DEM_RATIO_NUM)
							{
								if((Dem_General.DemRatio[u16Loop].DemDiagnosticEventRef == u16IntId)\
										&&(Dem_ISEnable_EventAvaliable(u16IntId)))
								{
									/* todo:version 4 shall be used,but SPN in 1939-73 is 19 bits,
									 * and there only 16 bits to reported. */
									*SPN = 0u;
									*SPN |= (uint16)((u32J1939Dtc & 0xFFFF00u) >> 8u);

									*Numerator = Dem_RatioNumerator[u16Loop];
									*Denominator = Dem_RatioDenominator[u16Loop];
									ret = DEM_FILTERED_OK;
									break;
								}
								u16Loop++;
							}
						}
					}
				}
				Dem_J1939RatioFilter.u8FilterIndex++;
				if(ret == DEM_FILTERED_OK)
				{
					break;
				}
				else
				{
					u16Loop = 0;
				}
			}
    	}
    }
    return ret;
}
#endif /* #if((DEM_RATIO_NUM > 0) && (DEM_J1939RATIO_SUPPORT == STD_ON)) */

#if(DEM_J1939READINESS1_SUPPORT == STD_ON)
/**
 * @sid				0x9b
 * @brief			Dem_J1939DcmReadDiagnosticReadiness1
 * @details			Service to report the value of Diagnostic Readiness 1 (DM05) computed by the Dem.
 *
 * @param[in]       node: Nm node Id of requesting client.
 *
 * @param[out]      DataValue: Buffer of 8 bytes containing the contents of Diagnostic Readiness 1
 *                  (DM05) computed by the Dem.
 *
 * @return     		Std_ReturnType: Status of the operation.
 * @retval			E_OK: Operation was successful.
 * @retval			E_NOT_OK: Operation failed.
 */
FUNC(Std_ReturnType ,DEM_CODE)Dem_J1939DcmReadDiagnosticReadiness1
(
	Dem_J1939DcmDiagnosticReadiness1Type* DataValue,
	uint8 node
)
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;
	uint8 u8EntryNum = 0u;
	uint8 u8Loop = 0u;
	uint16 u16DtcIndex;
	uint32 u32J1939Dtc = 0u;
	Dem_EventIdType u16IntId;
	Dem_MemoryEntryType* pEntry;

	uint8  u8SupportedSysArray[3] = {0};
	uint8  u8SystemStatusArray[3] = {0};

#if (DEM_DEV_ERROR_DETECT == STD_ON)
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
    	DEM_DET_ERROR_REPORT(DEM_SID_J1939DCMREADDIAGNOSTICREADINESS1,DEM_E_UNINIT);
    }
    else if(DataValue == NULL_PTR)
    {
    	DEM_DET_ERROR_REPORT(DEM_SID_J1939DCMREADDIAGNOSTICREADINESS1,DEM_E_PARAM_POINTER);
    }
    else
#endif /* #if (DEM_DEV_ERROR_DETECT == STD_ON) */
    {
    	pEntry = Dem_GetMemoryConf(DEM_DTC_ORIGIN_PRIMARY_MEMORY,&u8EntryNum);

    	DataValue->ActiveTroubleCodes = 0u;
    	DataValue->ContinuouslyMonitoredSystemsSupport_Status = 0u;
    	DataValue->NonContinuouslyMonitoredSystemsStatus = 0u;
    	DataValue->NonContinuouslyMonitoredSystemsSupport = 0u;
    	DataValue->OBDCompliance = DEM_OBD_COMPLIANCY;
    	DataValue->PreviouslyActiveDiagnosticTroubleCodes = 0u;

    	do
    	{
    		if(pEntry[u8Loop].EventId != 0u)
			{
				u16IntId = pEntry[u8Loop].EventId - 1u;
				(void)Dem_GetDTCOfEvent(pEntry[u8Loop].EventId,\
										DEM_DTC_FORMAT_J1939,\
										&u32J1939Dtc);

				if(u32J1939Dtc != 0u)
				{
					u16DtcIndex = Dem_ConfigPtr->DemEventParameter[u16IntId].DemDTCRef;

					/**
					 * @req [SWS_Dem_01101] A suppressed DTC shall not be visible for the following
					 *      Dcm query-functions; therefore this functions shall treat the DTC as if
					 *      filter is not matching.
					 */
					if((!(Dem_ISEnable_DTCSuppress(u16DtcIndex)))\
							&& ((boolean)TRUE == Dem_J1939DcmSearchNode(u16DtcIndex,node)))
					{
						if(((Dem_ISEnable_UdsStatusBits(u16IntId,DEM_UDS_STATUS_CDTC))\
								&&(Dem_ISEnable_UdsStatusBits(u16IntId,DEM_UDS_STATUS_TF)))
#if(DEM_INDICATOR_ATTRIBUTE_TOTAL_NUM > 0)
								||((boolean)TRUE == Dem_CheckIndicatorStatus(u16IntId))
#endif /* #if(DEM_INDICATOR_ATTRIBUTE_TOTAL_NUM > 0) */
						)
						{
							DataValue->ActiveTroubleCodes++;
						}

						if((Dem_ISEnable_UdsStatusBits(u16IntId,DEM_UDS_STATUS_CDTC))\
								&&(!(Dem_ISEnable_UdsStatusBits(u16IntId,DEM_UDS_STATUS_TF)))
#if(DEM_INDICATOR_ATTRIBUTE_TOTAL_NUM > 0)
								&&((boolean)FALSE == Dem_CheckIndicatorStatus(u16IntId))
#endif /* #if(DEM_INDICATOR_ATTRIBUTE_TOTAL_NUM > 0) */
								)
						{
							DataValue->PreviouslyActiveDiagnosticTroubleCodes++;
						}
					}
				}
			}
    		u8Loop++;
    	}while(u8Loop < u8EntryNum);

    	Dem_J1939ReadinessGroupCheck(node,u8SupportedSysArray,u8SystemStatusArray);

    	/*
    	 * Byte 4 Continuously Monitored system support and status:
		 * status:
		 * bit 8: Reserved
		 * bit 7: DEM_OBD_RDY_CMPRCMPT			((u8SystemStatusArray[0] & 0x08) << 3)
		 * bit 6: DEM_OBD_RDY_FLSYS				((u8SystemStatusArray[0] & 0x80) >> 2)
		 * bit 5: DEM_OBD_RDY_MISF				((u8SystemStatusArray[1] & 0x08) << 1)
		 * supported:
		 * bit 4: Reserved
		 * bit 3: DEM_OBD_RDY_CMPRCMPT			((u8SupportedSysArray[0] & 0x08) >> 1)
		 * bit 2: DEM_OBD_RDY_FLSYS				((u8SupportedSysArray[0] & 0x80) >> 6)
		 * bit 1: DEM_OBD_RDY_MISF				((u8SupportedSysArray[1] & 0x08) >> 3)
		 */
		DataValue->ContinuouslyMonitoredSystemsSupport_Status =  (uint8)(((u8SupportedSysArray[1] \
				& (uint8)0x08) >> (uint8)3)\
				| ((u8SupportedSysArray[0] & (uint8)0x80) >> (uint8)6)\
				| ((u8SupportedSysArray[0] & (uint8)0x08) >> (uint8)1)) \
				| (uint8)(((u8SystemStatusArray[1] & (uint8)0x08) << (uint8)1)\
						| ((u8SystemStatusArray[0] & (uint8)0x80) >> (uint8)2)\
						| ((u8SystemStatusArray[0] & (uint8)0x08) << (uint8)3));

		/*
		 * Byte 5 Non-continuously Monitored system support:
		 * bit 8: DEM_OBD_RDY_ERG				((u8SupportedSysArray[0] & 0x20) << 2)
		 * bit 7: DEM_OBD_RDY_O2SENSHT			((u8SupportedSysArray[1] & 0x80) >> 1)
		 * bit 6: DEM_OBD_RDY_O2SENS			((u8SupportedSysArray[1] & 0x40) >> 1)
		 * bit 5: DEM_OBD_RDY_AC				((u8SupportedSysArray[0] & 0x01) << 4)
		 * bit 4: DEM_OBD_RDY_SECAIR			((u8SupportedSysArray[2] & 0x02) << 2)
		 * bit 3: DEM_OBD_RDY_EVAP				((u8SupportedSysArray[0] & 0x40) >> 4)
		 * bit 2: DEM_OBD_RDY_HTCAT				((u8SupportedSysArray[1] & 0x04) >> 1)
		 * bit 1: DEM_OBD_RDY_CAT				((u8SupportedSysArray[0] & 0x04) >> 2)
		 */
		DataValue->NonContinuouslyMonitoredSystemsSupport = (uint16)(((uint16)(u8SupportedSysArray[0] \
				& (uint8)0x20) << (uint16)2)\
				| ((uint16)(u8SupportedSysArray[1] & (uint8)0x80) >> (uint16)1)\
				| ((uint16)(u8SupportedSysArray[1] & (uint8)0x40) >> (uint16)1)\
				| ((uint16)(u8SupportedSysArray[0] & (uint8)0x01) << (uint16)4)\
				| ((uint16)(u8SupportedSysArray[2] & (uint8)0x02) << (uint16)2)\
				| ((uint16)(u8SupportedSysArray[0] & (uint8)0x40) >> (uint16)4)\
				| ((uint16)(u8SupportedSysArray[1] & (uint8)0x04) >> (uint16)1)\
				| ((uint16)(u8SupportedSysArray[0] & (uint8)0x04) >> (uint16)2));


		/*
		 * Byte 6 Non-continuously Monitored system support:
		 * bit 8: Reserved
		 * bit 7: Reserved
		 * bit 6: Reserved
		 * bit 5: DEM_OBD_RDY_HCCAT			((u8SupportedSysArray[1] & 0x02) << 3))
		 * bit 4: DEM_OBD_RDY_NOXCAT		((u8SupportedSysArray[1] & 0x20) >> 2)
		 * bit 3: DEM_OBD_RDY_PMFLT			((u8SupportedSysArray[2] & 0x01) << 2)
		 * bit 2: DEM_OBD_RDY_BOOSTPR		(u8SupportedSysArray[0] & 0x02)
		 * bit 1: DEM_OBD_RDY_NONE			todo Do not find matched byte in AUTOSAR.
		 */
		DataValue->NonContinuouslyMonitoredSystemsSupport |= ((uint16)((uint16)(u8SupportedSysArray[0]\
				& (uint8)0x02)\
				| ((uint16)(u8SupportedSysArray[2] & (uint8)0x01) << (uint16)2)\
				| ((uint16)(u8SupportedSysArray[1] & (uint8)0x20) >> (uint16)2)\
				| ((uint16)(u8SupportedSysArray[1] & (uint8)0x02) << (uint16)3)) << (uint16)8);


		/*
		 * Byte 7 Non-continuously Monitored system status:
		 * bit 8: DEM_OBD_RDY_ERG				((u8SystemStatusArray[0] & 0x20) << 2)
		 * bit 7: DEM_OBD_RDY_O2SENSHT			((u8SystemStatusArray[1] & 0x80) >> 1)
		 * bit 6: DEM_OBD_RDY_O2SENS			((u8SystemStatusArray[1] & 0x40) >> 1)
		 * bit 5: DEM_OBD_RDY_AC				((u8SystemStatusArray[0] & 0x01) << 4)
		 * bit 4: DEM_OBD_RDY_SECAIR			((u8SystemStatusArray[2] & 0x02) << 2)
		 * bit 3: DEM_OBD_RDY_EVAP				((u8SystemStatusArray[0] & 0x40) >> 4)
		 * bit 2: DEM_OBD_RDY_HTCAT				((u8SystemStatusArray[1] & 0x04) >> 1)
		 * bit 1: DEM_OBD_RDY_CAT				((u8SystemStatusArray[0] & 0x04) >> 2)
		 */
		DataValue->NonContinuouslyMonitoredSystemsStatus = (uint16)((uint16)((u8SystemStatusArray[0]\
				& (uint8)0x20) << (uint16)2)\
				| ((uint16)(u8SystemStatusArray[1] & (uint8)0x80) >> (uint16)1)\
				| ((uint16)(u8SystemStatusArray[1] & (uint8)0x40) >> (uint16)1)\
				| ((uint16)(u8SystemStatusArray[0] & (uint8)0x01) << (uint16)4)\
				| ((uint16)(u8SystemStatusArray[2] & (uint8)0x02) << (uint16)2)\
				| ((uint16)(u8SystemStatusArray[0] & (uint8)0x40) >> (uint16)4)\
				| ((uint16)(u8SystemStatusArray[1] & (uint8)0x04) >> (uint16)1)\
				| ((uint16)(u8SystemStatusArray[0] & (uint8)0x04) >> (uint16)2));

		/*
		 * Byte 8 Non-continuously Monitored system status:
		 * bit 8: Reserved
		 * bit 7: Reserved
		 * bit 6: Reserved
		 * bit 5: DEM_OBD_RDY_HCCAT			((u8SystemStatusArray[1] & 0x02) << 3))
		 * bit 4: DEM_OBD_RDY_NOXCAT		((u8SystemStatusArray[1] & 0x20) >> 2)
		 * bit 3: DEM_OBD_RDY_PMFLT			((u8SystemStatusArray[2] & 0x01) << 2)
		 * bit 2: DEM_OBD_RDY_BOOSTPR		(u8SystemStatusArray[0] & 0x02)
		 * bit 1: DEM_OBD_RDY_NONE			todo Do not find matched byte in AUTOSAR.
		 */
		DataValue->NonContinuouslyMonitoredSystemsStatus |= ((uint16)((uint16)(u8SystemStatusArray[0]\
				& (uint16)0x02)\
				| ((uint16)(u8SystemStatusArray[2] & (uint8)0x01) << (uint16)2)\
				| ((uint16)(u8SystemStatusArray[1] & (uint8)0x20) >> (uint16)2)\
				| ((uint16)(u8SystemStatusArray[1] & (uint8)0x02) << (uint16)3)) << (uint16)8);

		ret = (Std_ReturnType)E_OK;
    }
    return ret;
}
#endif /* #if(DEM_J1939READINESS1_SUPPORT == STD_ON) */

#if(DEM_J1939READINESS2_SUPPORT == STD_ON)
/**
 * @sid				0x9c
 * @brief			Dem_J1939DcmReadDiagnosticReadiness2
 * @details			Service to report the value of Diagnostic Readiness 2 (DM21) computed by the Dem.
 *
 * @param[in]       node: Nm node Id of requesting client.
 *
 * @param[out]      DataValue: Buffer of 8 bytes containing the contents of Diagnostic Readiness 2
 *                  (DM21) computed by the Dem.
 *
 * @return     		Std_ReturnType: Status of the operation.
 * @retval			E_OK: Operation was successful.
 * @retval			E_NOT_OK: Operation failed.
 */
FUNC(Std_ReturnType , DEM_CODE)Dem_J1939DcmReadDiagnosticReadiness2
(
	Dem_J1939DcmDiagnosticReadiness2Type* DataValue,
	uint8 node
)
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;
	uint16 u16CurrentDistance;
	uint16 u16CurrentTimer;

#if (DEM_DEV_ERROR_DETECT == STD_ON)
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
    	DEM_DET_ERROR_REPORT(DEM_SID_J1939DCMREADDIAGNOSTICREADINESS2,DEM_E_UNINIT);
    }
    else if(DataValue == NULL_PTR)
    {
    	DEM_DET_ERROR_REPORT(DEM_SID_J1939DCMREADDIAGNOSTICREADINESS2,DEM_E_PARAM_POINTER);
    }
    else
#endif /* #if (DEM_DEV_ERROR_DETECT == STD_ON) */
    {
    	DataValue->DistanceSinceDTCsCleared 			  = 0u;
    	DataValue->DistanceTraveledWhileMILisActivated    = 0u;
    	DataValue->MinutesRunbyEngineWhileMILisActivated  = 0u;
    	DataValue->TimeSinceDiagnosticTroubleCodesCleared = 0u;

    	u16CurrentDistance = Dem_ReadCurrentOBDInfo((boolean)FALSE);
    	u16CurrentTimer = Dem_ReadCurrentOBDInfo((boolean)TRUE);

    	if((DEM_MILINDICATOR_REF != 0xFFu)\
    			&&(Dem_IndicatorStatus[DEM_MILINDICATOR_REF] != DEM_INDICATOR_OFF))
    	{
    		if (u16CurrentDistance >= Dem_OBDDistanceMILLastOn)
			{
				if((u16CurrentDistance - Dem_OBDDistanceMILLastOn) < (0xFAFFu - Dem_OBDDistanceMILOn))
				{
					Dem_OBDDistanceMILOn = Dem_OBDDistanceMILOn +\
							u16CurrentDistance - Dem_OBDDistanceMILLastOn;
				}
				else
				{
					Dem_OBDDistanceMILOn = 0xFAFFu;
				}

				Dem_OBDDistanceMILLastOn = u16CurrentDistance;
			}

    		if (u16CurrentTimer >= Dem_OBDTimeMILLastOn)
			{
    			if((u16CurrentTimer - Dem_OBDTimeMILLastOn) < (0xFAFFu - Dem_OBDTimeMILOn))
				{
    				Dem_OBDTimeMILOn = Dem_OBDTimeMILOn + u16CurrentTimer - Dem_OBDTimeMILLastOn;
				}
				else
				{
					Dem_OBDTimeMILOn = 0xFAFFu;
				}

    			Dem_OBDTimeMILLastOn = u16CurrentTimer;
			}
    	}

    	DataValue->DistanceTraveledWhileMILisActivated = Dem_OBDDistanceMILOn;

		DataValue->MinutesRunbyEngineWhileMILisActivated = Dem_OBDTimeMILOn;

    	if (u16CurrentDistance >= Dem_OBDDistanceLastDTCClear)
		{
			Dem_DistSinceDtcCleared = u16CurrentDistance - Dem_OBDDistanceLastDTCClear;
		}
		DataValue->DistanceSinceDTCsCleared = (Dem_DistSinceDtcCleared < 0xFAFFu) ? \
				Dem_DistSinceDtcCleared : (0xFAFFu);

    	if (u16CurrentTimer >= Dem_OBDTimeDTCLastClear)
		{
    		Dem_OBDTimeSinceDTCClear = u16CurrentTimer - Dem_OBDTimeDTCLastClear;
		}
		DataValue->TimeSinceDiagnosticTroubleCodesCleared = (Dem_OBDTimeSinceDTCClear < 0xFAFFu)\
				? Dem_OBDTimeSinceDTCClear : (0xFAFFu);

		ret = (Std_ReturnType)E_OK;
    }

    return ret;
}
#endif /* #if(DEM_J1939READINESS2_SUPPORT == STD_ON) */


#if(DEM_J1939READINESS3_SUPPORT == STD_ON)
/**
 * @sid				0x9d
 * @brief			Dem_J1939DcmReadDiagnosticReadiness3
 * @details			Service to report the value of Diagnostic Readiness 3 (DM26) computed by the Dem.
 *
 * @param[in]       node: Nm node Id of requesting client.
 *
 * @param[out]      DataValue: Buffer of 8 bytes containing the contents of Diagnostic Readiness 3
 *                  (DM26) computed by the Dem.
 *
 * @return     		Std_ReturnType: Status of the operation.
 * @retval			E_OK: Operation was successful.
 * @retval			E_NOT_OK: Operation failed.
 */
FUNC(Std_ReturnType , DEM_CODE)Dem_J1939DcmReadDiagnosticReadiness3
(
	Dem_J1939DcmDiagnosticReadiness3Type* DataValue,
	uint8 node
)
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;
	uint8  u8SupportedSysArray[3] = {0};
	uint8  u8SystemStatusArray[3] = {0};

#if (STD_ON == DEM_DEV_ERROR_DETECT)
    if (Dem_InitState != DEM_STATE_INIT)
    {
    	DEM_DET_ERROR_REPORT(DEM_SID_J1939DCMREADDIAGNOSTICREADINESS3, DEM_E_UNINIT);
    }
    else if (DataValue == NULL_PTR)
    {
    	DEM_DET_ERROR_REPORT(DEM_SID_J1939DCMREADDIAGNOSTICREADINESS3, DEM_E_PARAM_POINTER);
    }
    else
#endif /* STD_ON == DEM_DEV_ERROR_DETECT */
    {

    	DataValue->TimeSinceEngineStart = Dem_ReadCurrentOBDInfo((boolean)TRUE);
    	DataValue->NumberofWarmupsSinceDTCsCleared = Dem_WarmupsSinceDTCsCleared;

    	Dem_J1939ReadinessGroupCheck(node,u8SupportedSysArray,u8SystemStatusArray);

    	/*
		 * Byte 4 Continuously Monitored system support and status:
		 * status:
		 * bit 8: Reserved
		 * bit 7: DEM_OBD_RDY_CMPRCMPT			((u8SystemStatusArray[0] & 0x08) << 3)
		 * bit 6: DEM_OBD_RDY_FLSYS				((u8SystemStatusArray[0] & 0x80) >> 2)
		 * bit 5: DEM_OBD_RDY_MISF				((u8SystemStatusArray[1] & 0x08) << 1)
		 * supported:
		 * bit 4: Reserved
		 * bit 3: DEM_OBD_RDY_CMPRCMPT			((u8SupportedSysArray[0] & 0x08) >> 1)
		 * bit 2: DEM_OBD_RDY_FLSYS				((u8SupportedSysArray[0] & 0x80) >> 6)
		 * bit 1: DEM_OBD_RDY_MISF				((u8SupportedSysArray[1] & 0x08) >> 3)
		 */
		DataValue->ContinuouslyMonitoredSystemsEnableCompletedStatus =  \
				(uint8)(((u8SupportedSysArray[1] & (uint8)0x08) >> (uint8)3)\
				| ((u8SupportedSysArray[0] & (uint8)0x80) >> (uint8)6)\
				| ((u8SupportedSysArray[0] & (uint8)0x08) >> (uint8)1)) \
				| (uint8)(((u8SystemStatusArray[1] & (uint8)0x08) << (uint8)1)\
						| ((u8SystemStatusArray[0] & (uint8)0x80) >> (uint8)2)\
						| ((u8SystemStatusArray[0] & (uint8)0x08) << (uint8)3));

		/*
		 * Byte 5 Non-continuously Monitored system support:
		 * bit 8: DEM_OBD_RDY_ERG				((u8SupportedSysArray[0] & 0x20) << 2)
		 * bit 7: DEM_OBD_RDY_O2SENSHT			((u8SupportedSysArray[1] & 0x80) >> 1)
		 * bit 6: DEM_OBD_RDY_O2SENS			((u8SupportedSysArray[1] & 0x40) >> 1)
		 * bit 5: DEM_OBD_RDY_AC				((u8SupportedSysArray[0] & 0x01) << 4)
		 * bit 4: DEM_OBD_RDY_SECAIR			((u8SupportedSysArray[2] & 0x02) << 2)
		 * bit 3: DEM_OBD_RDY_EVAP				((u8SupportedSysArray[0] & 0x40) >> 4)
		 * bit 2: DEM_OBD_RDY_HTCAT				((u8SupportedSysArray[1] & 0x04) >> 1)
		 * bit 1: DEM_OBD_RDY_CAT				((u8SupportedSysArray[0] & 0x04) >> 2)
		 */
		DataValue->NonContinuouslyMonitoredSystemsEnableStatus = \
				(uint16)(((uint16)(u8SupportedSysArray[0] & (uint8)0x20) << (uint16)2)\
				| ((uint16)(u8SupportedSysArray[1] & (uint8)0x80) >> (uint16)1)\
				| ((uint16)(u8SupportedSysArray[1] & (uint8)0x40) >> (uint16)1)\
				| ((uint16)(u8SupportedSysArray[0] & (uint8)0x01) << (uint16)4)\
				| ((uint16)(u8SupportedSysArray[2] & (uint8)0x02) << (uint16)2)\
				| ((uint16)(u8SupportedSysArray[0] & (uint8)0x40) >> (uint16)4)\
				| ((uint16)(u8SupportedSysArray[1] & (uint8)0x04) >> (uint16)1)\
				| ((uint16)(u8SupportedSysArray[0] & (uint8)0x04) >> (uint16)2));


		/*
		 * Byte 6 Non-continuously Monitored system support:
		 * bit 8: Reserved
		 * bit 7: Reserved
		 * bit 6: Reserved
		 * bit 5: DEM_OBD_RDY_HCCAT			((u8SupportedSysArray[1] & 0x02) << 3))
		 * bit 4: DEM_OBD_RDY_NOXCAT		((u8SupportedSysArray[1] & 0x20) >> 2)
		 * bit 3: DEM_OBD_RDY_PMFLT			((u8SupportedSysArray[2] & 0x01) << 2)
		 * bit 2: DEM_OBD_RDY_BOOSTPR		(u8SupportedSysArray[0] & 0x02)
		 * bit 1: DEM_OBD_RDY_NONE			todo Do not find matched byte in AUTOSAR.
		 */
		DataValue->NonContinuouslyMonitoredSystemsEnableStatus |= \
				((uint16)((uint16)(u8SupportedSysArray[0] & (uint8)0x02)\
				| ((uint16)(u8SupportedSysArray[2] & (uint8)0x01) << (uint16)2)\
				| ((uint16)(u8SupportedSysArray[1] & (uint8)0x20) >> (uint16)2)\
				| ((uint16)(u8SupportedSysArray[1] & (uint8)0x02) << (uint16)3)) << (uint16)8);


		/*
		 * Byte 7 Non-continuously Monitored system status:
		 * bit 8: DEM_OBD_RDY_ERG				((u8SystemStatusArray[0] & 0x20) << 2)
		 * bit 7: DEM_OBD_RDY_O2SENSHT			((u8SystemStatusArray[1] & 0x80) >> 1)
		 * bit 6: DEM_OBD_RDY_O2SENS			((u8SystemStatusArray[1] & 0x40) >> 1)
		 * bit 5: DEM_OBD_RDY_AC				((u8SystemStatusArray[0] & 0x01) << 4)
		 * bit 4: DEM_OBD_RDY_SECAIR			((u8SystemStatusArray[2] & 0x02) << 2)
		 * bit 3: DEM_OBD_RDY_EVAP				((u8SystemStatusArray[0] & 0x40) >> 4)
		 * bit 2: DEM_OBD_RDY_HTCAT				((u8SystemStatusArray[1] & 0x04) >> 1)
		 * bit 1: DEM_OBD_RDY_CAT				((u8SystemStatusArray[0] & 0x04) >> 2)
		 */
		DataValue->NonContinuouslyMonitoredSystems = \
				(uint16)((uint16)((u8SystemStatusArray[0] & (uint8)0x20) << (uint16)2)\
				| ((uint16)(u8SystemStatusArray[1] & (uint8)0x80) >> (uint16)1)\
				| ((uint16)(u8SystemStatusArray[1] & (uint8)0x40) >> (uint16)1)\
				| ((uint16)(u8SystemStatusArray[0] & (uint8)0x01) << (uint16)4)\
				| ((uint16)(u8SystemStatusArray[2] & (uint8)0x02) << (uint16)2)\
				| ((uint16)(u8SystemStatusArray[0] & (uint8)0x40) >> (uint16)4)\
				| ((uint16)(u8SystemStatusArray[1] & (uint8)0x04) >> (uint16)1)\
				| ((uint16)(u8SystemStatusArray[0] & (uint8)0x04) >> (uint16)2));

		/*
		 * Byte 8 Non-continuously Monitored system status:
		 * bit 8: Reserved
		 * bit 7: Reserved
		 * bit 6: Reserved
		 * bit 5: DEM_OBD_RDY_HCCAT			((u8SystemStatusArray[1] & 0x02) << 3))
		 * bit 4: DEM_OBD_RDY_NOXCAT		((u8SystemStatusArray[1] & 0x20) >> 2)
		 * bit 3: DEM_OBD_RDY_PMFLT			((u8SystemStatusArray[2] & 0x01) << 2)
		 * bit 2: DEM_OBD_RDY_BOOSTPR		(u8SystemStatusArray[0] & 0x02)
		 * bit 1: DEM_OBD_RDY_NONE			todo Do not find matched byte in AUTOSAR.
		 */
		DataValue->NonContinuouslyMonitoredSystems |= \
				((uint16)((uint16)(u8SystemStatusArray[0] & (uint16)0x02)\
				| ((uint16)(u8SystemStatusArray[2] & (uint8)0x01) << (uint16)2)\
				| ((uint16)(u8SystemStatusArray[1] & (uint8)0x20) >> (uint16)2)\
				| ((uint16)(u8SystemStatusArray[1] & (uint8)0x02) << (uint16)3)) << (uint16)8);

		ret = (Std_ReturnType)E_OK;
    }

    return ret;
}
#endif /* #if(DEM_J1939READINESS3_SUPPORT == STD_ON) */

#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

#endif /* #if(DEM_J1939_SUPPORT == STD_ON) */

#ifdef __cplusplus
}
#endif
/** @} */
