/* PRQA S 0292 EOF */
/**
 * @file        Dem_Obd.c
 * @brief       AUTOSAR Dem  - Dem module source file.
 * @details     Dem module source file, containing the C implementation of Autosar API specification
 *              and other variables and functions that are provided for Dcm.
 * @version     1.2.0
 *
 * @addtogroup  Dem
 * @{
 */
/*=================================================================================================*
 * AngHui AUTOSAR BSW.
 *
 * Copyright(C) 2023 GuoKeAngHui Inc.
 *
 * All rights reserved.
 *
 * This file is part of AngHui AUTOSAR BSW, contains proprietary information.
 * Passing on and copying of this document, and communication of its contents
 * is not permitted without prior written authorization.
 *=================================================================================================*/

#ifdef __cplusplus
extern "C"{
#endif
/* PRQA S 0292, 0288, 1503, 1505, 0857, 0791, 0828, 0647, 3397,0491 EOF #
 *
 * 1.0292 -- Violates MISRA 2004 Required Rule 3.1, Source file has comments containing one of the
 * characters '$', '@' or '`'.
 *
 * 2.0288 -- Violates MISRA 2004 Required Rule 3.1, Source file has comments containing characters
 * which are not members of the basic source character set.
 *
 * 3.1503 -- Violates MISRA 2004 Required Rule 14.1, The function is defined but is not used within
 * this project.
 *
 * 4.1505 -- Violates MISRA 2004 Required Rule 8.10, The function is only referenced in the translation
 * unit where it is defined.
 *
 * 5.0857 -- Violates MISRA 2004 Required Rule 1.1, Number of macro definitions exceeds 1024 - program
 * does not conform strictly to ISO:C90.
 *
 * 6.0791 -- Violates MISRA 2004 Required Rule 5.1, Macro identifier does not differ from other macro
 * identifier(s) within the specified number of significant characters.
 *
 * 7.0828 -- Violates MISRA 2004 Required Rule 1.1, More than 8 levels of nested conditional inclusion
 * - program does not conform strictly to ISO:C90.
 *
 * 8.0647 -- Violates MISRA 2004 Required Rule 1.1, Number of enumeration constants exceeds 127 -
   program
 * does not conform strictly to ISO:C90.
 *
 * 9.3397 -- Violates MISRA 2004 Required Rule 12.1, Extra parentheses recommended. A binary operation
 * is the operand of a binary operator with different precedence.
 *
 * 10.0491 -- Violates MISRA 2004 Required Rule 17.4, Array subscripting applied to an object of pointer
 * type.
 *
 * @page misra_violations MISRA-C:2004 violations
 */
/*=================================================================================================*
 *                                           INCLUDE FILES										   *
 *=================================================================================================*/
#include "Dem_Internal.h"
#include "Dcm_Types.h"
#if((DEM_RATIO_NUM > 0u) || (DEM_TRIGGER_FIM_REPORTS == STD_ON))
#include "FiM.h"
#endif /* #if((DEM_RATIO_NUM > 0u) || (DEM_TRIGGER_FIM_REPORTS == STD_ON)) */

#ifdef AH_TEST_DEM
#include "TestCode.h"
#endif /* #ifdef AH_TEST_DEM */
/*=================================================================================================*
 * 									SOURCE FILE VERSION INFORMATION								   *
 *=================================================================================================*/

#define DEM_OBD_VENDOR_ID_C               					(0U)
#define DEM_OBD_AR_RELEASE_MAJOR_VERSION_C      			(4U)
#define DEM_OBD_AR_RELEASE_MINOR_VERSION_C      			(2U)
#define DEM_OBD_AR_RELEASE_REVISION_VERSION_C      			(2U)
#define DEM_OBD_SW_MAJOR_VERSION_C      					(1U)
#define DEM_OBD_SW_MINOR_VERSION_C      					(2U)
#define DEM_OBD_SW_PATCH_VERSION_C      					(0U)

/*=================================================================================================*
 * 												FILE VERSION CHECKS								   *
 *=================================================================================================*/

/* Check if current file and Dem_Internal.h header file are of the same vendor */
#if(DEM_OBD_VENDOR_ID_C != DEM_INTERNAL_VENDOR_ID )
#error "Dem_OBD.c and Dem_Internal.h have different vendor id"
#endif /* #if(DEM_VENDOR_ID_C != DEM_INTERNAL_VENDOR_ID ) */

/* Check if current file and Dem_Internal.h header file are of the same Autosar version */
#if(\
		(DEM_OBD_AR_RELEASE_MAJOR_VERSION_C != DEM_INTERNAL_AR_RELEASE_MAJOR_VERSION) || \
		(DEM_OBD_AR_RELEASE_MINOR_VERSION_C != DEM_INTERNAL_AR_RELEASE_MINOR_VERSION) || \
		(DEM_OBD_AR_RELEASE_REVISION_VERSION_C != DEM_INTERNAL_AR_RELEASE_REVISION_VERSION) \
   )
#error "AutoSar Version Number of Dem_OBD.c and Dem_Internal.h are different "
#endif /* #if(\
				(DEM_AR_RELEASE_MAJOR_VERSION_C != DEM_INTERNAL_AR_RELEASE_MAJOR_VERSION) || \
				(DEM_AR_RELEASE_MINOR_VERSION_C != DEM_INTERNAL_AR_RELEASE_MINOR_VERSION) || \
				(DEM_AR_RELEASE_REVISION_VERSION_C != DEM_INTERNAL_AR_RELEASE_REVISION_VERSION) \
   	   	     ) */

/* Check if current file and Dem_Internal.h header file are of the same Software version */
#if(\
		(DEM_OBD_SW_MAJOR_VERSION_C != DEM_INTERNAL_SW_MAJOR_VERSION) || \
		(DEM_OBD_SW_MINOR_VERSION_C != DEM_INTERNAL_SW_MINOR_VERSION) || \
		(DEM_OBD_SW_PATCH_VERSION_C != DEM_INTERNAL_SW_PATCH_VERSION) \
   )
#error "Software Version Number of Dem_OBD.c and Dem_Internal.h are different "
#endif /* #if(\
				(DEM_SW_MAJOR_VERSION_C != DEM_INTERNAL_SW_MAJOR_VERSION) || \
				(DEM_SW_MINOR_VERSION_C != DEM_INTERNAL_SW_MINOR_VERSION) || \
				(DEM_SW_PATCH_VERSION_C != DEM_INTERNAL_SW_PATCH_VERSION) \
   	   	   	 ) */

#ifndef DISABLE_INTERMOD_VERSION_CHECK
/* Check if current file and FiM.h header file are of the same vendor */
#if((DEM_RATIO_NUM > 0u) || (DEM_TRIGGER_FIM_REPORTS == STD_ON))
#if(DEM_OBD_VENDOR_ID_C != FIM_VENDOR_ID )
#error "Dem_OBD.c and Fim.h have different vendor id"
#endif /* #if(DEM_OBD_VENDOR_ID_C != FIM_VENDOR_ID ) */

/* Check if current file and FiM.h header file are of the same Autosar version */
#if(\
		(DEM_OBD_AR_RELEASE_MAJOR_VERSION_C != FIM_AR_RELEASE_MAJOR_VERSION) || \
		(DEM_OBD_AR_RELEASE_MINOR_VERSION_C != FIM_AR_RELEASE_MINOR_VERSION) || \
		(DEM_OBD_AR_RELEASE_REVISION_VERSION_C != FIM_AR_RELEASE_REVISION_VERSION) \
   )
#error "AutoSar Version Number of Dem_OBD.c and Fim.h are different "
#endif /* #if(\
				(DEM_OBD_AR_RELEASE_MAJOR_VERSION_C != FIM_AR_RELEASE_MAJOR_VERSION) || \
				(DEM_OBD_AR_RELEASE_MINOR_VERSION_C != FIM_AR_RELEASE_MINOR_VERSION) || \
				(DEM_OBD_AR_RELEASE_REVISION_VERSION_C != FIM_AR_RELEASE_REVISION_VERSION) \
   	   	     ) */

/* Check if current file and FiM.h header file are of the same Software version */
#if(\
		(DEM_OBD_SW_MAJOR_VERSION_C != FIM_SW_MAJOR_VERSION) || \
		(DEM_OBD_SW_MINOR_VERSION_C != FIM_SW_MINOR_VERSION) || \
		(DEM_OBD_SW_PATCH_VERSION_C != FIM_SW_PATCH_VERSION) \
   )
#error "Software Version Number of Dem_OBD.c and Fim.h are different "
#endif /* #if(\
				(DEM_OBD_SW_MAJOR_VERSION_C != FIM_SW_MAJOR_VERSION) || \
				(DEM_OBD_SW_MINOR_VERSION_C != FIM_SW_MINOR_VERSION) || \
				(DEM_OBD_SW_PATCH_VERSION_C != FIM_SW_PATCH_VERSION) \
   	   	   	 ) */
#endif /* #if((DEM_RATIO_NUM > 0u) || (DEM_TRIGGER_FIM_REPORTS == STD_ON)) */
#endif /* DISABLE_INTERMOD_VERSION_CHECK */

#if(DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT)
/*=================================================================================================*
 *                                            DEFINES AND MACROS								   *
 *=================================================================================================*/

#if defined(AH_DEM_UNITTEST_ENABLED)
#define STATIC
#else
#define STATIC static
#endif /* #if defined(AH_UNITTEST_ENABLED) */

#define DEM_READINESS_GROUP_NUM		(0x0Fu)

#define DEM_HOUR					(3600000u)
/*=================================================================================================*
 *                                   STRUCTURES AND OTHER TYPEDEFS
 *=================================================================================================*/

/*=================================================================================================*
 *									GLOBAL VARIABLE DECLARATIONS
 *=================================================================================================*/
#define DEM_START_SEC_VAR_INIT_32
#include "Dem_MemMap.h"

#if(DEM_OBD_COMPLIANCY == 15u)
/**
 * @brief	Record the time of engine during which a Class B1
 * 			has been Confirmed and TestFailed by DEM_TASK_TIME.(serving B1 counter)
 */
STATIC VAR(uint32,DEM_VAR) Dem_B1Timer;

/**
 * @brief	Record the time of engine during which the MIL was
 * 			continuously commanded to be on by DEM_TASK_TIME.(serving MI counter)
 */
STATIC VAR(uint32,DEM_VAR) Dem_MITimer;
#endif /* #if(DEM_OBD_COMPLIANCY == 15u) */

/**
 * @brief	Record the engine run time while MIL is activated.(serving PID$4D)
 */
STATIC VAR(uint32,DEM_VAR) Dem_EngMILONTimer;

/**
 * @brief	Record the speed while MIL is actived.(serving PID$21)
 */
STATIC VAR(uint32,DEM_VAR) Dem_SpeedMILON;

/**
 * @brief	Record the Speed until clear DTC.(serving PID$31)
 */
STATIC VAR(uint32,DEM_VAR) Dem_SpeedClearDTC;
#define DEM_STOP_SEC_VAR_INIT_32
#include "Dem_MemMap.h"

/**
 * @brief	Class B1 counter.
 */
VAR(uint16,DEM_VAR) Dem_B1Counter = 0u;

/**
 * @brief	Continuous-MI counter.
 */
VAR(uint16,DEM_VAR) Dem_ConMICounter = 0u;

/**
 * @brief	Cumulative Continuous-MI counter.
 */
VAR(uint16,DEM_VAR) Dem_CumConMICounter = 0u;

/**
 * @brief	Ignition cycle counter.
 */
STATIC VAR(uint16,DEM_VAR)	Dem_IgnitionCycleCounter;

/**
 * @brief	Record whether PTO is in an active state.
 */
STATIC VAR(boolean,DEM_VAR) Dem_PtoStatus = (boolean)FALSE;

/**
 * @brief	Record whether the current cycle meets the PFC(Permanent fault code) conditions.
 */
STATIC VAR(boolean,DEM_VAR) Dem_PDCState = (boolean)FALSE;

/**
 * @brief	Record whether PID $21 has been set using API Dem_SetDataOfPID21.
 */
STATIC VAR(boolean,DEM_VAR) Dem_SetPID21 = (boolean)FALSE;

/**
 * @brief	PID$01,monitor status since DTCs cleared (4 byte).
 */
STATIC VAR(uint8,DEM_VAR) Dem_PID01Info[4] = {0u};

/**
 * @brief	PID$41,monitor status this driving cycle (4 byte)
 */
STATIC VAR(uint8,DEM_VAR) Dem_PID41Info[4] = {0u};

/**
 * @brief	PID $21, distance traveled while MIL is activated (2 byte).
 */
STATIC VAR(uint16,DEM_VAR) Dem_DistanceMILON;

/**
 * @brief	PID $30, number of warm-ups (WUC) since DTCs cleared (1 byte).
 */
STATIC VAR(uint8,DEM_VAR) Dem_WUCCounter;

/**
 * @brief	PID $31, distance traveled since DTCs cleared (2 byte).
 */
STATIC VAR(uint16,DEM_VAR) Dem_DistanceClearDTC;

/**
 * @brief	PID $4D, engine run time while MIL is activated (2 byte).
 */
STATIC VAR(uint16,DEM_VAR) Dem_EngRTMILON;

/**
 * @brief	PID $4E, engine run time since DTCs cleared (2 byte).
 */
STATIC VAR(uint16,DEM_VAR) Dem_EngRTSinceClear;

/**
 * @brief	Record the engine run time when clearing DTCs.
 */
STATIC VAR(uint16,DEM_VAR) Dem_EngRTWhenClear;

#if(DEM_OBD_COMPLIANCY == 15u)
/**
 * @brief 	WWH-OBD active mode LV.
 */
STATIC VAR(uint8,DEM_VAR) Dem_ActiveMode = 1u;
#endif /* #if(DEM_OBD_COMPLIANCY == 15u) */
/*=================================================================================================*
 *                                           LOCAL VARIABLES
 *=================================================================================================*/

STATIC VAR(Dem_DtrInfoType,DEM_VAR) Dem_DtrInfo[DEM_DTR_NUM];

/*	Dem_DenomCondStatus[0] -> DEM_IUMPR_GENERAL_DENOMINATOR
 *	Dem_DenomCondStatus[1] -> DEM_IUMPR_DEN_COND_COLDSTART
 *	Dem_DenomCondStatus[2] -> DEM_IUMPR_DEN_COND_EVAP
 *	Dem_DenomCondStatus[3] -> DEM_IUMPR_DEN_COND_500MI */
STATIC VAR(Dem_IumprDenomCondStatusType,DEM_VAR) Dem_DenomCondStatus[4];

STATIC VAR(Dem_IUMPRType,DEM_VAR) Dem_IUMPRInfo[DEM_RATIO_NUM];

#if(DEM_OBD_COMPLIANCY == 15u)
/* Record the number of operation cycle that no Class B1 events have been detected. */
STATIC VAR(uint8,DEM_VAR) Dem_OpCycCounterForB1;

/* Record the number of operation cycle with "continuous-MI" turn off. */
STATIC VAR(uint8,DEM_VAR) Dem_OpCycCounterForMI;

/* Record the Warm-Up-Cycle with "continuous-MI" turn off. */
STATIC VAR(uint8,DEM_VAR) Dem_WUCCounterForMI;
#endif /* #if(DEM_OBD_COMPLIANCY == 15u) */
/*=================================================================================================*
 *                                      LOCAL FUNCTION PROTOTYPES
 *=================================================================================================*/
FUNC(uint16,DEM_CODE) Dem_GetVehicleInfo
(
	Dem_VehicleDataType VehicleData
);

STATIC FUNC(void,DEM_CODE) Dem_IUMPRCalculate
(
	Dem_RatioIdType RatioID
);

STATIC FUNC(void, DEM_CODE) Dem_PIDInfoUpdate
(
	void
);

STATIC FUNC(Dem_MemoryEntryType*, DEM_CODE) Dem_SelectMostImportant
(
	void
);

FUNC(boolean, DEM_CODE) Dem_CauseMILON
(
    Dem_EventIdType InternalId
);

#if(DEM_OBD_COMPLIANCY == 15u)
STATIC FUNC(void, DEM_CODE) Dem_OpCycCounterForB1Handle
(
	uint8   OperationCycleId
);

STATIC FUNC(void, DEM_CODE) Dem_OpCycCounterForMIHandle
(
	uint8   OperationCycleId
);

STATIC FUNC(void, DEM_CODE) Dem_B1CounterHandle
(
	void
);

FUNC(void,DEM_CODE) Dem_OBDMILStatusUpdate
(
	void
);

STATIC FUNC(void, DEM_CODE) Dem_ConMICounterHandle
(
	void
);
#endif /* #if(DEM_OBD_COMPLIANCY == 15u) */
/*=================================================================================================*
 *                                           LOCAL FUNCTIONS
 *=================================================================================================*/
FUNC(void,DEM_CODE) Dem_OBDInit
(
	void
)
{
	uint16 u16Loop;

	/* PID$30 */
	Dem_WUCCounter = 0u;

	/* PID$21 */
	Dem_DistanceMILON = 0u;
	Dem_SpeedMILON = 0u;
	Dem_SetPID21 = (boolean)FALSE;

	/* PID$31 */
	Dem_DistanceClearDTC = 0u;
	Dem_SpeedClearDTC = 0u;

	/* PID$4D */
	Dem_EngRTMILON = 0u;
	Dem_EngMILONTimer = 0u;

	/* PID$4E */
	Dem_EngRTSinceClear = 0u;
	Dem_EngRTWhenClear = 0u;

	/* status of Permanent fault code - driving cycle (PFC cycle) */
	Dem_PDCState = (boolean)FALSE;

	Dem_PtoStatus = (boolean)FALSE;

	/* IUMPR Init */
	Dem_IgnitionCycleCounter = 0u;

	Dem_DenomCondStatus[0] = 0xFFu;
	Dem_DenomCondStatus[1] = 0xFFu;
	Dem_DenomCondStatus[2] = 0xFFu;
	Dem_DenomCondStatus[3] = 0xFFu;

	for(u16Loop = 0u; u16Loop < DEM_RATIO_NUM; u16Loop++)
	{
		Dem_IUMPRInfo[u16Loop].DemNumerator = 0u;
		Dem_IUMPRInfo[u16Loop].DemDenominator = 0u;
		Dem_IUMPRInfo[u16Loop].DemNumeratorlock = (boolean)TRUE;
		Dem_IUMPRInfo[u16Loop].DemDenominatorlock = (boolean)TRUE;
	}

	/* DTR Init */
	for(u16Loop = 0u; u16Loop < DEM_DTR_NUM; u16Loop++)
	{
		Dem_DtrInfo[u16Loop].LowerLimit = 0u;
		Dem_DtrInfo[u16Loop].TestResult = 0u;
		Dem_DtrInfo[u16Loop].UpperLimit = 0u;
	}

	/* WWH-OBD */
#if(DEM_OBD_COMPLIANCY == 15u)
	Dem_B1Timer = 0u;
	Dem_MITimer = 0u;
	Dem_ActiveMode = 1u;
	Dem_OpCycCounterForB1 = 0u;
	Dem_OpCycCounterForMI = 0u;
	Dem_WUCCounterForMI = 0u;
#endif /* #if(DEM_OBD_COMPLIANCY == 15u) */

	/**
	 * @req [SWS_Dem_00697] Dem shall provide a configuration parameter DemOperationCycleAutoma-
	 *      ticEnd to automatically END the OBD driving cycle at initialization time.The implem-
	 *      entation may either END the cycle either at the beginning of Dem_Shutdown() or during
	 *      Dem_Init(). If the cycle is ENDed at Dem_Init(), any event status change received
	 *      before (after Dem_PreInit()) shall be processed after the cycle is ENDed, i.e., be
	 *      considered for the new cycle.
	 */
/*	for(u16Loop = 0u; u16Loop < DEM_OPERATION_CYCLE_NUM; u16Loop++)
	{
		if(Dem_General.DemOperationCycle[u8Loop].DemOperationCycleAutomaticEnd == (boolean)TRUE)
		{
			Dem_EndOperationCycle(u8Loop);
			Dem_Disable_OperationCycle(u8Loop);
		}
	}*/
}

STATIC FUNC(void,DEM_CODE) Dem_IUMPRCalculate
(
	Dem_RatioIdType RatioID
)
{
	uint8 u8Loop 					= 0u;
	boolean Permission				= (boolean)TRUE;
	const Dem_RatioType* pRatio		= &Dem_General.DemRatio[RatioID];
	const uint8* pSecFuncIdRef		= pRatio->DemSecondaryFunctionIdRef;
	uint16 u16EventRef				= pRatio->DemDiagnosticEventRef;
	uint16 u16DtcRef				= Dem_ConfigPtr->DemEventParameter[u16EventRef].DemDTCRef;

	/**
	* @req [SWS_Dem_00709] Ratios which refer to a Suppressed Event shall not be computed.
	* @req [SWS_Dem_01104] IUMPR ratios referring to an unavailable event shall neither
	* 		be computed nor reported.
	* @req [SWS_Dem_00299] As long as an event has Pending status, the Dem module shall
	* 		stop increasing the numerator and denominator.
	*/
	if((u16DtcRef != 0xFFFFu)\
		&&(!Dem_ISEnable_DTCSuppress(u16DtcRef))\
		&&(Dem_ISEnable_EventAvaliable(u16EventRef))\
		&&(!Dem_ISEnable_UdsStatusBits(u16EventRef,DEM_UDS_STATUS_PDTC)))
	{
		if((Std_ReturnType)E_OK == FiM_GetFunctionPermission(pRatio->DemFunctionIdRef,&Permission))
		{
			if((Permission == (boolean)FALSE) && (pSecFuncIdRef != NULL_PTR))
			{
				for(u8Loop = 0u; u8Loop < pRatio->DemSecFuncIdRefNum; u8Loop++)
				{
					if((Std_ReturnType)E_OK == \
							FiM_GetFunctionPermission(*(pSecFuncIdRef + u8Loop),&Permission))
					{
						if(Permission == (boolean)TRUE)
						{
							break;
						}
					}
				}
			}
		}

		if(Permission == (boolean)FALSE)
		{
/* <Calculate Denominator> */
			/**
			 * @req [SWS_Dem_00712] The ECU internal denominator incrementation(in a
			 * 		Master/Primary ECU) shall be done depended on the IUMPR-Cycle Flag
			 * 		(included in the General Denominator signal).
			 * @req [SWS_Dem_00715] The Dem module shall provide configuration parameter
			 * 		DemIUMPRDenGroup to offer several conditions to be applied to the
			 * 		denominator per RatioId.
			 */
			if(pRatio->DemIUMPRDenGroup == DEM_IUMPR_DEN_PHYS_API)
			{
				if(Dem_IUMPRInfo[RatioID].DemDenominatorlock == (boolean)FALSE)
				{
					if(Dem_IUMPRInfo[RatioID].DemDenominator < 0xFFFFu)
					{
						Dem_IUMPRInfo[RatioID].DemDenominator++;
					}
				}
			}
			else
			{
				if(Dem_DenomCondStatus[pRatio->DemIUMPRDenGroup] == DEM_IUMPR_DEN_STATUS_REACHED)
				{
					if(Dem_IUMPRInfo[RatioID].DemDenominator < 0xFFFFu)
					{
						Dem_IUMPRInfo[RatioID].DemDenominator++;
					}
				}
			}
/* <Calculate Numerator> */
/**
 *  @req [SWS_Dem_00710] The numerator shall be calculated in the ECU (Master and Primary).
 */
#if ((DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU) || (DEM_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
			/**
			* @req [SWS_Dem_01188] The Dem shall increment the ratio-individual IUMPR-numerator
			* 		at maximum of one time per OBD driving cycle.
			* @req [SWS_Dem_00359] Only for monitors being configured with the option “observer“,
			* 		the Dem module shall increment the numerator of the corresponding monitor, if
			* 		the assigned event gets tested/qualified (as passed or failed).
			* @req [SWS_Dem_00361] The Dem module shall provide the configuration parameter
			* 		DemRatioKind, to indicate per RatioId if the numerator is calculated based
			* 		on the TESTED-status or the API call.
			*/
			if(pRatio->DemRatioKind == DEM_RATIO_API)
			{
				if(Dem_IUMPRInfo[RatioID].DemNumeratorlock == (boolean)FALSE)
				{
					if(Dem_IUMPRInfo[RatioID].DemNumerator < 0xFFFFu)
					{
						Dem_IUMPRInfo[RatioID].DemNumerator++;
					}
				}
			}
			/* when find a malffunction, use Dem_RepIUMPRFaultDetect to unlock the DemNumerator,
			* and calculate the DemNumerator here. */
			else /* pRatio->DemRatioKind == DEM_RATIO_OBSERVER */
			{
				if(!(Dem_ISEnable_UdsStatusBits(u16EventRef,DEM_UDS_STATUS_TNCTOC)))
				{
					if(Dem_IUMPRInfo[RatioID].DemNumerator < 0xFFFFu)
					{
						Dem_IUMPRInfo[RatioID].DemNumerator++;
					}
				}
			}
#endif/*#if ((DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU) || (DEM_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))*/
		}
	}
}

FUNC(uint16,DEM_CODE) Dem_GetVehicleInfo
(
	Dem_VehicleDataType VehicleData
)
{
	uint8 Buffer[2] = {0u,0u};
	const Dem_GeneralOBDType* pGeneralOBD = Dem_General.DemGeneralOBD;
	switch(VehicleData)
	{
		case DEM_OBD_TIME_SINCE_ENGINE_START:
			if(pGeneralOBD->DemOBDDataElement[pGeneralOBD->DemOBDTimeSinceEngineStart].\
					DemExternalCSDataElementClass->DemDataElementReadFnc != NULL_PTR)
			{
				pGeneralOBD->DemOBDDataElement[pGeneralOBD->DemOBDTimeSinceEngineStart].\
						DemExternalCSDataElementClass->DemDataElementReadFnc(Buffer);
			}
			break;

		case DEM_OBD_INPUT_VEHICLE_SPEED:
			if(pGeneralOBD->DemOBDDataElement[pGeneralOBD->DemOBDInputVehicleSpeed].\
					DemExternalCSDataElementClass->DemDataElementReadFnc != NULL_PTR)
			{
				pGeneralOBD->DemOBDDataElement[pGeneralOBD->DemOBDInputVehicleSpeed].\
						DemExternalCSDataElementClass->DemDataElementReadFnc(Buffer);
			}
			break;

		case DEM_OBD_INPUT_DISTANCE_INFORMATION:
			if(pGeneralOBD->DemOBDDataElement[pGeneralOBD->DemOBDInputDistanceInformation].\
					DemExternalCSDataElementClass->DemDataElementReadFnc != NULL_PTR)
			{
				pGeneralOBD->DemOBDDataElement[pGeneralOBD->DemOBDInputDistanceInformation].\
						DemExternalCSDataElementClass->DemDataElementReadFnc(Buffer);
			}
			break;

		default:
			break;
	}
	return ((uint16)(Buffer[1] << (uint8)8) | (uint16)(Buffer[0]));
}

/* end operation or restart operation */
FUNC(void, DEM_CODE) Dem_OBDCounterHandle
(
	uint8   OperationCycleId
)
{
#if(DEM_RATIO_NUM > 0)
	uint16 u16Loop = 0u;
#endif /* #if(DEM_RATIO_NUM > 0) */

    switch(Dem_General.DemOperationCycle[OperationCycleId].DemOperationCycleType)
    {
		case DEM_OPCYC_IGNITION:
			Dem_IgnitionCycleCounter++;
			break;

		case DEM_OPCYC_OBD_DCY:
#if(DEM_RATIO_NUM > 0)
			for(u16Loop = 0u; u16Loop < DEM_RATIO_NUM; u16Loop++)
			{
				/* IUMPR is calculating once per OBD cycle. */
				Dem_IUMPRCalculate(u16Loop);
			}
#endif /* #if(DEM_RATIO_NUM > 0) */
			break;

		case DEM_OPCYC_WARMUP:
			if(Dem_WUCCounter < 0xFFu)
			{
				Dem_WUCCounter++;
			}
#if(DEM_OBD_COMPLIANCY == 15u)
#if(DEM_MILINDICATOR_REF != 0xFF)
			if(Dem_IndicatorStatus[DEM_MILINDICATOR_REF] != DEM_INDICATOR_CONTINUOUS)
#endif /* #if(DEM_MILINDICATOR_REF != 0xFF) */
			{
				/**
				 * @req [SWS_Dem_01146] The counter shall reset to zero if the Continuous-MI is
				 * 		not commanded on after more than 40 warm-up cycles or after more than
				 * 		200 engine operating hours or upon a ClearDTC request.
				 */
				if(Dem_WUCCounterForMI < 40u)
				{
					Dem_WUCCounterForMI++;
				}
				if(Dem_WUCCounterForMI >= 40)
				{
					Dem_ConMICounter = 0u;
				}
			}
#endif /* #if(DEM_OBD_COMPLIANCY == 15u) */
			break;

		default:
			break;
    }

#if(DEM_OBD_COMPLIANCY == 15u)
    Dem_OpCycCounterForB1Handle(OperationCycleId);

    Dem_OpCycCounterForMIHandle(OperationCycleId);
#endif /* #if(DEM_OBD_COMPLIANCY == 15u) */
}

STATIC FUNC(void,DEM_CODE) Dem_PIDInfoUpdate
(
	void
)
{
	uint16 u16Speed = 0u;

	if(Dem_General.DemGeneralOBD->DemOBDInputVehicleSpeed != 0xFFu)
	{
		u16Speed = Dem_GetVehicleInfo(DEM_OBD_INPUT_VEHICLE_SPEED);

		Dem_SpeedClearDTC += u16Speed;

		if(Dem_SpeedClearDTC >= (DEM_HOUR / DEM_TASK_TIME))
		{
			Dem_SpeedClearDTC = 0u;
			if(Dem_DistanceClearDTC < 0xFFFFu)
			{
				Dem_DistanceClearDTC++;
			}
		}
	}

#if(DEM_MILINDICATOR_REF != 0xFF)
	if(Dem_IndicatorStatus[DEM_MILINDICATOR_REF] != DEM_INDICATOR_OFF)
	{
		Dem_EngMILONTimer += DEM_TASK_TIME;

		if(Dem_EngMILONTimer >= DEM_HOUR)
		{
			Dem_EngMILONTimer = 0u;
			if(Dem_EngRTMILON < 0xFFFFu)
			{
				Dem_EngRTMILON++;
			}
		}

		/**
		 * @req [SWS_Dem_00346] The Dem module shall use PID $0D (refer to chapter 7.10.8) to
		 * 		calculate PID $21 and PID $31.
		 * @req [SWS_Dem_01096] An OBD Master ECU shall calculate the PID $21 value by its
		 * 		own (considering [SWS_Dem_00346]).
		 */
		Dem_SpeedMILON += u16Speed;

		if(Dem_SpeedMILON >= (DEM_HOUR / DEM_TASK_TIME))
		{
			Dem_SpeedMILON = 0u;
			if(Dem_DistanceMILON < 0xFFFFu)
			{
				Dem_DistanceMILON++;
			}
		}
	}
#endif /* #if(DEM_MILINDICATOR_REF != 0xFF) */
}

/*this function is running in Dem_MainFunction*/
FUNC(void, DEM_CODE) Dem_OBDInfoUpdate
(
	void
)
{
#if(DEM_OBD_COMPLIANCY == 15u)
    /* the calling order can not change. */
	Dem_B1CounterHandle();

	Dem_OBDMILStatusUpdate();

	Dem_ConMICounterHandle();
#endif /* #if(DEM_OBD_COMPLIANCY == 15u) */

	Dem_PIDInfoUpdate();
}

FUNC(void,DEM_CODE) Dem_ClearOBDInfo
(
	void
)
{
#if(DEM_MILINDICATOR_REF != 0xFF)
	Dem_IndicatorStatus[DEM_MILINDICATOR_REF] = DEM_INDICATOR_OFF;
#endif /* #if(DEM_MILINDICATOR_REF != 0xFF) */

	Dem_PID01Info[0] = 0u;
	Dem_PID01Info[1] = 0u;
	Dem_PID01Info[2] = 0u;
	Dem_PID01Info[3] = 0u;

	Dem_DistanceMILON = 0u;
	Dem_SpeedMILON = 0u;

	Dem_WUCCounter = 0u;

	Dem_DistanceClearDTC = 0u;
	Dem_SpeedClearDTC = 0u;

	Dem_PID41Info[0] = 0u;
	Dem_PID41Info[1] = 0u;
	Dem_PID41Info[2] = 0u;
	Dem_PID41Info[3] = 0u;

	Dem_EngRTSinceClear = 0u;
	Dem_EngRTWhenClear = Dem_GetVehicleInfo(DEM_OBD_TIME_SINCE_ENGINE_START);

#if(DEM_OBD_COMPLIANCY == 15u)
	Dem_ActiveMode			= 1u;
	Dem_MITimer				= 0u;
	Dem_ConMICounter 		= 0u;

	Dem_B1Timer				= 0u;
	Dem_B1Counter			= 0u;
#endif /* #if(DEM_OBD_COMPLIANCY == 15u) */
}

STATIC FUNC(Dem_MemoryEntryType*, DEM_CODE) Dem_SelectMostImportant
(
	void
)
{
	Dem_MemoryEntryType* pEntry = NULL_PTR;
	Dem_MemoryEntryType* RetEntry = NULL_PTR;
	uint16 u16Loop;
	uint16 u16DtcRef;
	uint8 u8NewPriority = 0xFFu;
	uint8 u8OldPriority = 0xFFu;
	uint8 u8NewAbsTime = 0xFFu;
	uint8 u8OldAbsTime = 0xFFu;
	boolean find = (boolean)FALSE;

	for(u16Loop = 0u; u16Loop < DEM_EVENT_PARAMETER_NUM; u16Loop++)
	{
		u16DtcRef = Dem_ConfigPtr->DemEventParameter[u16Loop].DemDTCRef;
		if((u16DtcRef != 0xFFFFu)\
			&&(Dem_ISEnable_EventAvaliable(u16Loop))\
			&&(!Dem_ISEnable_DTCSuppress(u16DtcRef))\
			&&(Dem_ConfigPtr->DemDTC[u16DtcRef].DemObdDTCRef != 0xFFFFu))
		{
			if(Dem_ISEnable_UdsStatusBits(u16Loop,DEM_UDS_STATUS_PDTC))
			{
				if(Dem_ISEnable_UdsStatusBits(u16Loop,DEM_UDS_STATUS_CDTC))
				{
					pEntry = Dem_GetEntryFromMemory(DEM_DTC_ORIGIN_PERMANENT_MEMORY,(u16Loop+1));
					if(pEntry != NULL_PTR)
					{
						if(find == (boolean)FALSE)
						{
							find = (boolean)TRUE;
							u8OldPriority = 0xFFu;
							u8OldAbsTime = 0xFFu;
						}

						u8NewPriority = Dem_ConfigPtr->DemDTCAttributes[Dem_ConfigPtr->\
											DemDTC[u16DtcRef].DemDTCAttributesRef].DemDTCPriority;
						u8NewAbsTime = pEntry->AbsTime;
						if(u8NewPriority < u8OldPriority)
						{
							u8OldPriority = u8NewPriority;
							u8OldAbsTime = u8NewAbsTime;
							RetEntry = pEntry;
						}
						else if(u8NewPriority == u8OldPriority)
						{
							if(u8NewAbsTime < u8OldAbsTime)
							{
								u8OldAbsTime = u8NewAbsTime;
								RetEntry = pEntry;
							}
						}
					}
				}
				else
				{
					if(find == (boolean)FALSE)
					{
						pEntry = Dem_GetEntryFromMemory(DEM_DTC_ORIGIN_PERMANENT_MEMORY,(u16Loop+1));
						if(pEntry != NULL_PTR)
						{
							u8NewPriority = Dem_ConfigPtr->DemDTCAttributes[Dem_ConfigPtr->\
												DemDTC[u16DtcRef].DemDTCAttributesRef].DemDTCPriority;
							u8NewAbsTime = pEntry->AbsTime;
							if(u8NewPriority < u8OldPriority)
							{
								u8OldPriority = u8NewPriority;
								u8OldAbsTime = u8NewAbsTime;
								RetEntry = pEntry;
							}
							else if(u8NewPriority == u8OldPriority)
							{
								if(u8NewAbsTime < u8OldAbsTime)
								{
									u8OldAbsTime = u8NewAbsTime;
									RetEntry = pEntry;
								}
							}
						}
					}
				}
			}
		}
	}

	return RetEntry;
}
/*=================================================================================================*
 *                                           GLOBAL FUNCTIONS									   *
 *=================================================================================================*/
/**
 * @sid				0x6b
 * @brief			Dem_DcmGetInfoTypeValue08
 * @details			Service is used for requesting IUMPR data according to InfoType $08. This
 * 					interface is derived from the prototype <Module>_GetInfotypeValueData() defined
 * 					by the Dcm. Therefore Dcm_OpStatusType and Std_ReturnType are contained.
 * 					API is needed in OBD-relevant ECUs only.
 *
 * @param[in]		OpStatus: Only DCM_INITIAL will appear, because this API behaves synchronous.
 *
 * @param[out]		Iumprdata08: Buffer containing the number of data elements (as defined in
 * 					ISO-15031-5) and contents of InfoType $08. The buffer is provided by the Dcm.
 *
 * @param[inout]	Iumprdata08BufferSize: The maximum number of data bytes that can be written to
 * 					the Iumprdata08 Buffer.
 *
 * @return     		Always E_OK is returned.
 */
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetInfoTypeValue08
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DEM_CODE) Iumprdata08,
    P2VAR(uint8, AUTOMATIC, DEM_CODE) Iumprdata08BufferSize
)
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;
#if(DEM_OBDENGINE_TYPE == DEM_IGNITION_SPARK)
	uint16 u16Loop = 0u;
	uint16 u16Numerator;
	uint16 u16Denominator;
#endif /* #if(DEM_OBDENGINE_TYPE == DEM_IGNITION_SPARK) */

	DEM_DETCHECK_API_DCMGETINFOTYPEVALUE08(Dem_InitState,Iumprdata08BufferSize,&ret);
	if(ret)
	{
#if(DEM_OBDENGINE_TYPE == DEM_IGNITION_SPARK)
/**
 * @req [SWS_Dem_00298] In order to support the data requests in service $09 as described above, the
 * 		Dem shall provide the API Dem_DcmGetInfoTypeValue08 or Dem_DcmGetInfoTypeValue0B to the Dcm.
 */
#if (DEM_RATIO_NUM > 0u)
		if((OpStatus == DCM_INITIAL) && (*Iumprdata08BufferSize >= 40u))
		{
			/**
			 * @req [SWS_Dem_00357] If the DemOBDEngineType is set to DEM_IGNITION_SPARK
			 * 		the Dem module shall provide the API Dem_DcmGetInfoTypeValue08 for
			 * 		InfoType $08 IUMPR data.
			 */
			*Iumprdata08BufferSize = 40u;

			for(u16Loop = 0u; u16Loop < 40u; u16Loop++)
			{
				Iumprdata08[u16Loop] = 0u;
			}

			/* General Denominator */
			Iumprdata08[0] = (uint8)(Dem_DenomCondStatus[0] >> 8u);
			Iumprdata08[1] = (uint8)(Dem_DenomCondStatus[0]);

			/* Ignition cycle counter */
			Iumprdata08[2] = (uint8)(Dem_IgnitionCycleCounter >> 8u);
			Iumprdata08[3] = (uint8)(Dem_IgnitionCycleCounter);

			for(u16Loop = 0u; u16Loop < DEM_RATIO_NUM; u16Loop++)
			{
				u16Numerator	= Dem_IUMPRInfo[u16Loop].DemNumerator;
				u16Denominator	= Dem_IUMPRInfo[u16Loop].DemDenominator;
				switch(Dem_General.DemRatio[u16Loop].DemIUMPRGroup)
				{
					case DEM_IUMPR_CAT1:
						Iumprdata08[4]  = (uint8)(u16Numerator);
						Iumprdata08[5]  = (uint8)(u16Numerator >> 8u);
						Iumprdata08[6]  = (uint8)(u16Denominator);
						Iumprdata08[7]  = (uint8)(u16Denominator >> 8u);
						break;

					case DEM_IUMPR_CAT2:
						Iumprdata08[8]  = (uint8)(u16Numerator);
						Iumprdata08[9]  = (uint8)(u16Numerator >> 8u);
						Iumprdata08[10] = (uint8)(u16Denominator);
						Iumprdata08[11] = (uint8)(u16Denominator >> 8u);
						break;

					case DEM_IUMPR_OXS1:
						Iumprdata08[12] = (uint8)(u16Numerator);
						Iumprdata08[13] = (uint8)(u16Numerator >> 8u);
						Iumprdata08[14] = (uint8)(u16Denominator);
						Iumprdata08[15] = (uint8)(u16Denominator >> 8u);
						break;

					case DEM_IUMPR_OXS2:
						Iumprdata08[16] = (uint8)(u16Numerator);
						Iumprdata08[17] = (uint8)(u16Numerator >> 8u);
						Iumprdata08[18] = (uint8)(u16Denominator);
						Iumprdata08[19] = (uint8)(u16Denominator >> 8u);
						break;

					case DEM_IUMPR_EGR:
						Iumprdata08[20] = (uint8)(u16Numerator);
						Iumprdata08[21] = (uint8)(u16Numerator >> 8u);
						Iumprdata08[22] = (uint8)(u16Denominator);
						Iumprdata08[23] = (uint8)(u16Denominator >> 8u);
						break;

					case DEM_IUMPR_SAIR:
						Iumprdata08[24] = (uint8)(u16Numerator);
						Iumprdata08[25] = (uint8)(u16Numerator >> 8u);
						Iumprdata08[26] = (uint8)(u16Denominator);
						Iumprdata08[27] = (uint8)(u16Denominator >> 8u);
						break;

					case DEM_IUMPR_EVAP:
						Iumprdata08[28] = (uint8)(u16Numerator);
						Iumprdata08[29] = (uint8)(u16Numerator >> 8u);
						Iumprdata08[30] = (uint8)(u16Denominator);
						Iumprdata08[31] = (uint8)(u16Denominator >> 8u);
						break;

					case DEM_IUMPR_SECOXS1:
						Iumprdata08[32] = (uint8)(u16Numerator);
						Iumprdata08[33] = (uint8)(u16Numerator >> 8u);
						Iumprdata08[34] = (uint8)(u16Denominator);
						Iumprdata08[35] = (uint8)(u16Denominator >> 8u);
						break;

					case DEM_IUMPR_SECOXS2:
						Iumprdata08[36] = (uint8)(u16Numerator);
						Iumprdata08[37] = (uint8)(u16Numerator >> 8u);
						Iumprdata08[38] = (uint8)(u16Denominator);
						Iumprdata08[39] = (uint8)(u16Denominator >> 8u);
						break;

					default:
						break;
				}
			}
			ret = (Std_ReturnType)E_OK;
		}
#endif /* #if (DEM_RATIO_NUM > 0u) */
#endif/* #if(DEM_OBDENGINE_TYPE == DEM_IGNITION_SPARK) */
	}
	else
	{
		ret = (Std_ReturnType)E_NOT_OK;
	}
	return ret;
}

/**
 * @sid				0x6c
 * @brief			Dem_DcmGetInfoTypeValue0B
 * @details			Service is used for requesting IUMPR data according to InfoType $0B. This
 * 					interface is derived from the prototype <Module>_GetInfotypeValueData() defined
 * 					by the Dcm. Therefore Dcm_OpStatusType and Std_ReturnType are contained.
 * 					API is needed in OBD-relevant ECUs only.
 *
 * @param[in]		OpStatus: Only DCM_INITIAL will appear, because this API behaves synchronous.
 *
 * @param[out]		Iumprdata0B: Buffer containing the number of data elements (as defined in
 * 					ISO-15031-5) and contents of InfoType $0B. The buffer is provided by the Dcm.
 *
 * @param[inout]	Iumprdata0BBufferSize: The maximum number of data bytes that can be written to
 * 					the Iumprdata0B Buffer.
 *
 * @return     		Always E_OK is returned.
 */
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetInfoTypeValue0B
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DEM_CODE) Iumprdata0B,
    P2VAR(uint8, AUTOMATIC, DEM_CODE) Iumprdata0BBufferSize
)
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;
#if(DEM_OBDENGINE_TYPE == DEM_IGNITION_COMPRESSION)
	uint16 u16Loop = 0u;
	uint16 u16Numerator;
	uint16 u16Denominator;
#endif /* #if(DEM_OBDENGINE_TYPE == DEM_IGNITION_COMPRESSION) */

	DEM_DETCHECK_API_DCMGETINFOTYPEVALUE0B(Dem_InitState,Iumprdata0BBufferSize,&ret);
	if(ret)
	{
#if(DEM_OBDENGINE_TYPE == DEM_IGNITION_COMPRESSION)
/**
 * @req [SWS_Dem_00298] In order to support the data requests in service $09 as described above, the
 * 		Dem shall provide the API Dem_DcmGetInfoTypeValue08 or Dem_DcmGetInfoTypeValue0B to the Dcm.
 */
#if (DEM_RATIO_NUM > 0u)
		if((OpStatus == DCM_INITIAL) && (*Iumprdata0BBufferSize >= 36u))
		{
			/**
			 * @req [SWS_Dem_00358] d If the DemOBDEngineType is set to DEM_IGNITION_COMPRESSION
			 * 		the Dem module shall provide the API Dem_DcmGetInfoTypeValue0B for Info Type
			 * 		$0B IUMPR data.
			 */
			*Iumprdata0BBufferSize = 36u;

			for(u16Loop = 0u; u16Loop < 36u; u16Loop++)
			{
				Iumprdata0B[u16Loop] = 0u;
			}

			/* General Denominator */
			Iumprdata0B[0] = (uint8)(Dem_DenomCondStatus[0] >> 8u);
			Iumprdata0B[1] = (uint8)(Dem_DenomCondStatus[0]);

			/* Ignition cycle counter */
			Iumprdata0B[2] = (uint8)(Dem_IgnitionCycleCounter >> 8u);
			Iumprdata0B[3] = (uint8)(Dem_IgnitionCycleCounter);

			for(u16Loop = 0u; u16Loop < DEM_RATIO_NUM; u16Loop++)
			{
				u16Numerator	= Dem_IUMPRInfo[u16Loop].DemNumerator;
				u16Denominator	= Dem_IUMPRInfo[u16Loop].DemDenominator;
				switch(Dem_General.DemRatio[u16Loop].DemIUMPRGroup)
				{
					case DEM_IUMPR_NMHCCAT:
						Iumprdata0B[4]  = (uint8)(u16Numerator);
						Iumprdata0B[5]  = (uint8)(u16Numerator >> 8u);
						Iumprdata0B[6]  = (uint8)(u16Denominator);
						Iumprdata0B[7]  = (uint8)(u16Denominator >> 8u);
						break;

					case DEM_IUMPR_NOXCAT:
						Iumprdata0B[8]  = (uint8)(u16Numerator);
						Iumprdata0B[9]  = (uint8)(u16Numerator >> 8u);
						Iumprdata0B[10] = (uint8)(u16Denominator);
						Iumprdata0B[11] = (uint8)(u16Denominator >> 8u);
						break;

					case DEM_IUMPR_NOXADSORB:
						Iumprdata0B[12] = (uint8)(u16Numerator);
						Iumprdata0B[13] = (uint8)(u16Numerator >> 8u);
						Iumprdata0B[14] = (uint8)(u16Denominator);
						Iumprdata0B[15] = (uint8)(u16Denominator >> 8u);
						break;

					case DEM_IUMPR_PMFILTER:
						Iumprdata0B[16] = (uint8)(u16Numerator);
						Iumprdata0B[17] = (uint8)(u16Numerator >> 8u);
						Iumprdata0B[18] = (uint8)(u16Denominator);
						Iumprdata0B[19] = (uint8)(u16Denominator >> 8u);
						break;

					case DEM_IUMPR_EGSENSOR:
						Iumprdata0B[20] = (uint8)(u16Numerator);
						Iumprdata0B[21] = (uint8)(u16Numerator >> 8u);
						Iumprdata0B[22] = (uint8)(u16Denominator);
						Iumprdata0B[23] = (uint8)(u16Denominator >> 8u);
						break;

					case DEM_IUMPR_EGR:
						Iumprdata0B[24] = (uint8)(u16Numerator);
						Iumprdata0B[25] = (uint8)(u16Numerator >> 8u);
						Iumprdata0B[26] = (uint8)(u16Denominator);
						Iumprdata0B[27] = (uint8)(u16Denominator >> 8u);
						break;

					case DEM_IUMPR_BOOSTPRS:
						Iumprdata0B[28] = (uint8)(u16Numerator);
						Iumprdata0B[29] = (uint8)(u16Numerator >> 8u);
						Iumprdata0B[30] = (uint8)(u16Denominator);
						Iumprdata0B[31] = (uint8)(u16Denominator >> 8u);
						break;

					case DEM_IUMPR_FLSYS:
						Iumprdata0B[32] = (uint8)(u16Numerator);
						Iumprdata0B[33] = (uint8)(u16Numerator >> 8u);
						Iumprdata0B[34] = (uint8)(u16Denominator);
						Iumprdata0B[35] = (uint8)(u16Denominator >> 8u);
						break;

					default:
						break;
				}
			}
			ret = (Std_ReturnType)E_OK;
		}
#endif /* #if (DEM_RATIO_NUM > 0u) */
#endif /* #if(DEM_OBDENGINE_TYPE == DEM_IGNITION_COMPRESSION) */
	}
	else
	{
		ret = (Std_ReturnType)E_NOT_OK;
	}
	return ret;
}

/**
 * @sid				0x61
 * @brief			Dem_DcmReadDataOfPID01
 * @details			Service to report the value of PID $01 computed by the Dem.
 * 					API is needed in OBD-relevant ECUs only.
 *
 * @param[out]		PID01value: Buffer containing the contents of PID $01 computed by the Dem. The buffer is
 * 					provided by the Dcm with the appropriate size, i.e. during configuration, the
 * 					Dcm identifies the required size from the largest PID in order to configure a
 * 					PIDBuffer.
 *
 * @return     		Always E_OK is returned.
 */
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID01
(
    P2VAR(uint8, AUTOMATIC, DEM_CODE) PID01value
)
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;

	DEM_DETCHECK_API_DCMREADDATDOFPID01(Dem_InitState,PID01value,&ret);
	if(ret)
	{
		PID01value[0] = Dem_PID01Info[0];
		PID01value[1] = Dem_PID01Info[1];
		PID01value[2] = Dem_PID01Info[2];
		PID01value[3] = Dem_PID01Info[3];

		ret = (Std_ReturnType)E_OK;
	}
	else
	{
		ret = (Std_ReturnType)E_NOT_OK;
	}
	return ret;
}

/**
 * @sid				0x63
 * @brief			Dem_DcmReadDataOfPID1C
 * @details			Service to report the value of PID $1C computed by the Dem.
 * 					API is needed in OBD-relevant ECUs only.
 *
 * @param[out]		PID1Cvalue: Buffer containing the contents of PID $1C computed by the Dem.
 * 					The value of PID$1C is configuration within DemOBDCompliancy. The buffer is
 * 					provided by the Dcm with the appropriate size, i.e. during configuration, the
 * 					Dcm identifies the required size from the largest PID in order to configure
 * 					a PIDBuffer.
 *
 * @return     		Always E_OK is returned.
 */
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID1C
(
    P2VAR(uint8, AUTOMATIC, DEM_CODE) PID1Cvalue
)
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;

	DEM_DETCHECK_API_DCMREADDATDOFPID1C(Dem_InitState,PID1Cvalue,&ret);
	if(ret)
	{
		/**
		 * @req [SWS_Dem_00748] The function Dem_DcmReadDataOfPID1C shall return the appropriate
		 * 		value “OBD requirements to which vehicle or engine is certified.“ according to
		 * 		the respective standards [13], e.g. OBD, OBDII, JOBD etc. The value PID1Cvalue to
		 * 		return is in configuration parameter DemOBDCompliancy defined.
		 */
		*PID1Cvalue = DEM_OBD_COMPLIANCY;
		ret = (Std_ReturnType)E_OK;
	}
	else
	{
		ret = (Std_ReturnType)E_NOT_OK;
	}
	return ret;
}

/**
 * @sid				0x64
 * @brief			Dem_DcmReadDataOfPID21
 * @details			Service to report the value of PID $21 computed by the Dem.
 * 					API is needed in OBD-relevant ECUs only.
 *
 * @param[out]		PID21value: Buffer containing the contents of PID $21 computed by the Dem.
 * 					The buffer is provided by the Dcm with the appropriate size, i.e. during
 * 					configuration, the Dcm identifies the required size from the largest PID in
 * 					order to configure a PIDBuffer.
 *
 * @return     		Always E_OK is returned, as E_NOT_OK will never appear.
 */
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID21
(
    P2VAR(uint8, AUTOMATIC, DEM_CODE) PID21value
)
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;

	DEM_DETCHECK_API_DCMREADDATDOFPID21(Dem_InitState,PID21value,&ret);
	if(ret)
	{
#if(DEM_OBDCENTRALIZED_PID21HANDLING == TRUE)
		if(Dem_SetPID21 == (boolean)TRUE)
		{
			/**
			 * @req [SWS_Dem_01098] On invocation of Dem_DcmReadDataOfPID21 the Dem shall return
			 * 		the current value of PID $21.
			 */
			PID21value[0] = (uint8)Dem_DistanceMILON;
			PID21value[1] = (uint8)(Dem_DistanceMILON >> (uint8)8);
		}
		else
		{
			/**
			 * @req [SWS_Dem_01099] If Dem_DcmReadDataOfPID21 is called before Dem_SetDataOfPID21,
			 * 		the Dem shall return 0xFFFF as PID $21 value.
			 */
			PID21value[0] = 0xFFu;
			PID21value[1] = 0xFFu;
		}
		Dem_SetPID21 = (boolean)FALSE;
		ret = (Std_ReturnType)E_OK;
#endif /* #if(DEM_OBDCENTRALIZED_PID21HANDLING == TRUE) */
	}
	else
	{
		ret = (Std_ReturnType)E_NOT_OK;
	}
	return ret;
}

/**
 * @sid				0x65
 * @brief			Dem_DcmReadDataOfPID30
 * @details			Service to report the value of PID $30 computed by the Dem.
 * 					API is needed in OBD-relevant ECUs only.
 *
 * @param[out]		PID30value: Buffer containing the contents of PID $30 computed by the Dem.
 * 					The buffer is provided by the Dcm with the appropriate size, i.e. during
 * 					configuration, the Dcm identifies the required size from the largest PID in
 * 					order to configure a PIDBuffer.
 *
 * @return     		Always E_OK is returned, as E_NOT_OK will never appear.
 */
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID30
(
    P2VAR(uint8, AUTOMATIC, DEM_CODE) PID30value
)
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;

	DEM_DETCHECK_API_DCMREADDATDOFPID30(Dem_InitState,PID30value,&ret);
	if(ret)
	{
		*PID30value = Dem_WUCCounter;
		ret = (Std_ReturnType)E_OK;
	}
	else
	{
		ret = (Std_ReturnType)E_NOT_OK;
	}
	return ret;
}

/**
 * @sid				0x67
 * @brief			Dem_DcmReadDataOfPID41
 * @details			Service to report the value of PID $41 computed by the Dem.
 * 					API is needed in OBD-relevant ECUs only.
 *
 * @param[out]		PID41value: Buffer containing the contents of PID $41 computed by the Dem.
 * 					The buffer is provided by the Dcm with the appropriate size, i.e. during
 * 					configuration, the Dcm identifies the required size from the largest PID in
 * 					order to configure a PIDBuffer.
 *
 * @return     		Always E_OK is returned, as E_NOT_OK will never appear.
 */
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID41
(
    P2VAR(uint8, AUTOMATIC, DEM_CODE) PID41value
)
{

	uint8 	u8Loop 					= 0u;
	uint16 	u16Loop 				= 0u;
	uint16 	u16DtcRef 				= 0u;
	uint16 	u16ObdDTCRef 			= 0u;
	uint16	u16SupportedReadiness	= 0u;
	uint16	u16DisabledReadiness 	= 0u;
	uint16 	u16ReadinessStatus 		= 0u;
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;

	DEM_DETCHECK_API_DCMREADDATDOFPID41(Dem_InitState,PID41value,&ret);
	if(ret)
	{
		for(u8Loop = 0u; u8Loop < DEM_READINESS_GROUP_NUM; u8Loop++)
		{
			for(u16Loop = 0u; u16Loop < DEM_EVENT_PARAMETER_NUM; u16Loop++)
			{
				u16DtcRef = Dem_ConfigPtr->DemEventParameter[u16Loop].DemDTCRef;
				if((Dem_ISEnable_EventAvaliable(u16Loop))\
					&&(u16DtcRef != 0xFFFFu)\
					&&(!Dem_ISEnable_DTCSuppress(u16DtcRef)))
				{
					u16ObdDTCRef = Dem_ConfigPtr->DemDTC[u16DtcRef].DemObdDTCRef;
					if(u16ObdDTCRef != 0xFFFFu)
					{
						if(Dem_ConfigPtr->DemObdDTC[u16ObdDTCRef].DemEventOBDReadinessGroup == u8Loop)
						{
							/**
							 * @req [SWS_Dem_00356] The Dem module shall compute the readiness group
							 * 		disabled(if the disabled status is reported by the monitor for
							 * 		any event of a group). OBD Events Suppression (refer to chapter
							 * 		7.4.8) shall be ignored for this computation.
							 */
							if(Dem_IsEnable_ObdDisableEvent(u16Loop))
							{
								u16DisabledReadiness |= ((uint16)1 << u8Loop);
							}
							else
							{
								u16SupportedReadiness |= ((uint16)1 << u8Loop);
							}
							/**
							 * @req [SWS_Dem_00355] The Dem module shall compute for PID $41 the readiness
							 * 		group complete for current driving cycle (if all events of a group are
							 * 		tested in the current driving cycle).
							 */
							if(Dem_ISEnable_UdsStatusBits(u16Loop,DEM_UDS_STATUS_TNCTOC))
							{
								u16ReadinessStatus |= ((uint16)1 << u8Loop);
							}
						}
					}
				}
			}
		}

		/* Refer SAE J1979DA,the byteA(bit0~bit7) of PID$41 shall be reported as $00(reserved).  */
		Dem_PID41Info[0] = 0x00u;

		Dem_PID41Info[1] = ((u16ReadinessStatus & 0x07u) << 4u) | (u16SupportedReadiness & 0x07u);

		Dem_PID41Info[1] |= 0x04u;/* Refer J1979-DA,Byte B bit 2 always set to '1',(CMPRCMPT)*/

		u16SupportedReadiness &= u16DisabledReadiness;

#if (DEM_OBDENGINE_TYPE == DEM_IGNITION_COMPRESSION)
		Dem_PID41Info[1] |= 0x08u;
		Dem_PID41Info[2] = ((u16SupportedReadiness & 0x0200u) >> 2u) | \
						((u16SupportedReadiness & 0x6000u) >> 8u) | \
						((u16SupportedReadiness & 0x1000u) >> 9u) | \
						((u16SupportedReadiness & 0x0c00u) >> 10u);
		Dem_PID41Info[3] = ((u16ReadinessStatus & 0x0200u) >> 2u) | \
						((u16ReadinessStatus & 0x6000u) >> 8u) | \
						((u16ReadinessStatus & 0x1000u) >> 9u) | \
						((u16ReadinessStatus & 0x0c00u) >> 10u);
#endif /* #if (DEM_OBDENGINE_TYPE == DEM_IGNITION_COMPRESSION) */
#if(DEM_OBDENGINE_TYPE == DEM_IGNITION_SPARK)
		Dem_PID41Info[2] = ((u16SupportedReadiness & 0x0380u) >> 2u) | \
						((u16SupportedReadiness & 0x0078u) >> 3u);
		Dem_PID41Info[3] = ((u16ReadinessStatus & 0x0380u) >> 2u) | \
						((u16ReadinessStatus & 0x0078u) >> 3u);
#endif /* #if (DEM_OBDENGINE_TYPE == DEM_IGNITION_COMPRESSION) */

		PID41value[0] = Dem_PID41Info[0];
		PID41value[1] = Dem_PID41Info[1];
		PID41value[2] = Dem_PID41Info[2];
		PID41value[3] = Dem_PID41Info[3];

		/* Note:refer J1979 DA,the completion status show by PID41 will
		 * synchronize with the value of PID01.*/
		Dem_PID01Info[1] = (Dem_PID01Info[1] & 0xF0u) | (Dem_PID41Info[1] & 0x0Fu);
		Dem_PID01Info[3] = Dem_PID41Info[3];

		ret = (Std_ReturnType)E_OK;
	}
	else
	{
		ret = (Std_ReturnType)E_NOT_OK;
	}
	return ret;
}

/**
 * @sid				0x66
 * @brief			Dem_DcmReadDataOfPID31
 * @details			Service to report the value of PID $31 computed by the Dem.
 * 					API is needed in OBD-relevant ECUs only.
 *
 * @param[out]		PID31value: Buffer containing the contents of PID $31 computed by the Dem.
 * 					The buffer is provided by the Dcm with the appropriate size, i.e. during
 * 					configuration, the Dcm identifies the required size from the largest PID in
 * 					order to configure a PIDBuffer.
 *
 * @return     		Always E_OK is returned, as E_NOT_OK will never appear.
 */
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID31
(
    P2VAR(uint8, AUTOMATIC, DEM_CODE) PID31value
)
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;

	DEM_DETCHECK_API_DCMREADDATDOFPID31(Dem_InitState,PID31value,&ret);
	if(ret)
	{
/* @req [SWS_Dem_00703] and [SWS_Dem_00704] */
#if(DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU)
#if(DEM_OBDCENTRALIZED_PID31HANDLING == TRUE)
		/**
		 * @req [SWS_Dem_00346] The Dem module shall use PID $0D(speed) (refer to chapter 7.10.8)
		 * 		to calculate PID $21 and PID $31.
		 */
		PID31value[0] = (uint8)Dem_DistanceClearDTC;
		PID31value[1] = (uint8)(Dem_DistanceClearDTC >> (uint8)8);
		ret = (Std_ReturnType)E_OK;
#endif /* #if(DEM_OBDCENTRALIZED_PID31HANDLING == TRUE) */
#endif /* #if(DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU) */
	}
	else
	{
		ret = (Std_ReturnType)E_NOT_OK;
	}
	return ret;
}

/**
 * @sid				0x68
 * @brief			Dem_DcmReadDataOfPID4D
 * @details			Service to report the value of PID $4D computed by the Dem.
 * 					API is needed in OBD-relevant ECUs only.
 *
 * @param[out]		PID4Dvalue: Buffer containing the contents of PID $4D computed by the Dem.
 * 					The buffer is provided by the Dcm with the appropriate size, i.e. during
 * 					configuration, the Dcm identifies the required size from the largest PID in
 * 					order to configure a PIDBuffer.
 *
 * @return     		Always E_OK is returned, as E_NOT_OK will never appear.
 */
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID4D
(
    P2VAR(uint8, AUTOMATIC, DEM_CODE) PID4Dvalue
)
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;

	DEM_DETCHECK_API_DCMREADDATDOFPID4D(Dem_InitState,PID4Dvalue,&ret);
	if(ret)
	{
#if(DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU)

		PID4Dvalue[0] = (uint8)Dem_EngRTMILON;
		PID4Dvalue[1] = (uint8)(Dem_EngRTMILON >> 8u);

		ret = (Std_ReturnType)E_OK;
#endif /* #if(DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU) */
	}
	else
	{
		ret = (Std_ReturnType)E_NOT_OK;
	}
	return ret;
}

/**
 * @sid				0x69
 * @brief			Dem_DcmReadDataOfPID4E
 * @details			Service to report the value of PID $4E computed by the Dem.
 * 					API is needed in OBD-relevant ECUs only.
 *
 * @param[out]		PID4Evalue: Buffer containing the contents of PID $4E computed by the Dem.
 * 					The buffer is provided by the Dcm with the appropriate size, i.e. during
 * 					configuration, the Dcm identifies the required size from the largest PID in
 * 					order to configure a PIDBuffer.
 *
 * @return     		Always E_OK is returned, as E_NOT_OK will never appear.
 */
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID4E
(
    P2VAR(uint8, AUTOMATIC, DEM_CODE) PID4Evalue
)
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;
	uint16	u16CurrentTime = 0;

	DEM_DETCHECK_API_DCMREADDATDOFPID4E(Dem_InitState,PID4Evalue,&ret);
	if(ret)
	{
#if(DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU)
		u16CurrentTime = Dem_GetVehicleInfo(DEM_OBD_TIME_SINCE_ENGINE_START);

		if(u16CurrentTime > Dem_EngRTWhenClear)
		{
			Dem_EngRTSinceClear = u16CurrentTime - Dem_EngRTWhenClear;
		}

		PID4Evalue[0] = (uint8)Dem_EngRTSinceClear;
		PID4Evalue[1] = (uint8)(Dem_EngRTSinceClear >> 8u);
		ret = (Std_ReturnType)E_OK;
#endif /* #if(DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU) */
	}
	else
	{
		ret = (Std_ReturnType)E_NOT_OK;
	}
	return ret;
}

/**
 * @sid				0x6a
 * @brief			Dem_DcmReadDataOfPID91
 * @details			Service to report the value of PID $91 computed by the Dem.
 * 					API is needed in OBD-relevant ECUs only.
 *
 * @param[out]		PID91value: Buffer containing the contents of PID $91 computed by the Dem.
 * 					The buffer is provided by the Dcm with the appropriate size, i.e. during
 * 					configuration, the Dcm identifies the required size from the largest PID in
 * 					order to configure a PIDBuffer.
 *
 * @return     		Always E_OK is returned, as E_NOT_OK will never appear.
 */
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID91
(
    P2VAR(uint8, AUTOMATIC, DEM_CODE) PID91value
)
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;

	DEM_DETCHECK_API_DCMREADDATDOFPID91(Dem_InitState,PID91value,&ret);
	if(ret)
	{
#if (DEM_OBD_SUPPORT != DEM_OBD_DEP_SEC_ECU)
		if(DEM_MILINDICATOR_REF == 0xFFu)
		{
			PID91value[0] = 0x0Eu;/* Error */
		}
		else
		{
#if(DEM_MILINDICATOR_REF != 0xFF)
			switch(Dem_IndicatorStatus[DEM_MILINDICATOR_REF])
			{
				case DEM_INDICATOR_OFF:
					PID91value[0] = 0x00u;
					break;

				case DEM_INDICATOR_ON_DEMAND:
					PID91value[0] = 0x01u;
					break;

				case DEM_INDICATOR_SHORT:
					PID91value[0] = 0x02u;
					break;

				case DEM_INDICATOR_CONTINUOUS:
					PID91value[0] = 0x03u;
					break;

				default:
					PID91value[0] = 0x0Fu;/* not available/not required of this ECU */
					break;
			}
#else
			PID91value[0] = 0x00u;
#endif /* #if(DEM_MILINDICATOR_REF != 0xFF) */
		}

		PID91value[1] = (uint8)(Dem_ConMICounter);
		PID91value[2] = (uint8)(Dem_ConMICounter >> 8u);

		PID91value[3] = (uint8)(Dem_B1Counter);
		PID91value[4] = (uint8)(Dem_B1Counter >> 8u);

		ret = (Std_ReturnType)E_OK;
#endif /* #if (DEM_OBD_SUPPORT != DEM_OBD_DEP_SEC_ECU) */
	}
	else
	{
		ret = (Std_ReturnType)E_NOT_OK;
	}
	return ret;
}

/**
 * @sid				0x52
 * @brief			Dem_DcmReadDataOfOBDFreezeFrame
 * @details			Gets data element per PID and index of the most important freeze frame being
 *					selected for the output of service $02. The function stores the data in the
 *					provided DestBuffer.API is needed in OBD-relevant ECUs only.
 *
 * @param[in]		PID: This parameter is an identifier for a PID as defined in ISO15031-5.
 * @param[in]		DataElementIndexOfPID: Data element index of this PID according to the Dcm
 * 					configuration of service $02. It is zero-based and consecutive, and ordered
 * 					by the data element positions (configured in Dcm, refer to SWS_Dem_00597).
 *
 * @param[inout]	DestBuffer: This parameter contains a byte pointer that points to the buffer,
 * 					to which the data element of the PID shall be written to. The format is raw
 * 					hexadecimal values and contains no header-information.
 * @param[inout]	BufSize: When the function is called this parameter contains the maximum number
 * 					of data bytes that can be written to the buffer. The function returns the
 * 					actual number of written data bytes in this parameter.
 *
 * @return     		The result of reporting Freeze frame data.
 * @retval			E_OK: Freeze frame data was successfully reported.
 * @retval			E_NOT_OK: Freeze frame data was not successfully reported.
 */
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfOBDFreezeFrame
(
    uint8 PID,
    uint8 DataElementIndexOfPID,
    P2VAR(uint8, AUTOMATIC, DEM_CODE) DestBuffer,
    P2VAR(uint16, AUTOMATIC, DEM_CODE) BufSize
)
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;
#if(DEM_PID_CLASS_NUM > 0)
	Dem_MemoryEntryType* pEntry = NULL_PTR;
	uint8 u8DataSize = 0u;
	uint8 u8Loop;
#endif /* #if(DEM_PID_CLASS_NUM > 0) */

	DEM_DETCHECK_API_DCMREADDATAOFOBDFREEZEFRAME(Dem_InitState,PID,DestBuffer,BufSize,&ret);
	if(ret)
	{
#if(DEM_PID_CLASS_NUM > 0)
		/**
		 * @req [SWS_Dem_00291] The Dem module shall support only the legislative freeze
		 * 		frame(record number 0).This will be a single list of PIDs assigned to this
		 * 		freeze frame (refer to DemPIDClass).
		 * @req [SWS_Dem_00596] The Dem module shall provide access on PID data elements
		 * 		of the most important freeze frame being selected for the output of service
		 * 		$02(OBD freeze frame of the event which caused MIL on) to the Dcm module
		 * 		(refer to Dem_DcmReadDataOfOBDFreezeFrame).
		 * @req [SWS_Dem_00623] The function Dem_DcmGetDTCOfOBDFreezeFrame shall return
		 * 		the DTC associated with the most important freeze frame being selected
		 * 		for the output of service $02 (PID $02).
		 */
		for(u8Loop = 0u; u8Loop < DEM_PID_CLASS_NUM; u8Loop++)
		{
			if(Dem_ConfigPtr->DemPidClass[u8Loop].DemPidIdentifier == PID)
			{
				if(DataElementIndexOfPID < Dem_ConfigPtr->DemPidClass[u8Loop].DemPidDataElementClassRefNum)
				{
					u8DataSize = Dem_ConfigPtr->DemPidClass[u8Loop].DemPidDataElementRef\
									[DataElementIndexOfPID].DemPidDataElementClassRefSize;
					if(*BufSize >= u8DataSize)
					{
						pEntry = Dem_SelectMostImportant();

						if(pEntry != NULL_PTR)
						{
							*BufSize = u8DataSize;
							DEM_VALUE_COPY(DestBuffer,\
										   &(pEntry->PidInfo[u8Loop].PidData[DataElementIndexOfPID]),\
										   u8DataSize);
							ret = (Std_ReturnType)E_OK;
						}
					}
				}
			}
		}
#endif /* #if(DEM_PID_CLASS_NUM > 0) */
	}
	else
	{
		ret = (Std_ReturnType)E_NOT_OK;
	}
	return ret;
}

/**
 * @sid				0x53
 * @brief			Dem_DcmGetDTCOfOBDFreezeFrame
 * @details			Gets DTC by freeze frame record number.API is needed in OBD-relevant ECUs only.
 *
 * @param[in]		FrameNumber: Unique identifier for a freeze frame record as defined in ISO
 * 					15031-5. The value 0x00 indicates the complete OBD freeze frame. Other values
 * 					are reserved for future functionality.
 * @param[in]		DTCFormat: Output format of the DTC value.
 *
 * @param[out]		DTC: Diagnostic Trouble Code in ODB format. If the return value of the
 * 					function is other than E_OK this parameter does not contain valid data.
 *
 * @return     		The result of getting Freeze frame data.
 * @retval			E_OK: operation was successful.
 * @retval			E_NOT_OK: no DTC available.
 */
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetDTCOfOBDFreezeFrame
(
    uint8 FrameNumber,
    uint32* DTC,
    Dem_DTCFormatType DTCFormat
)
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;
	Dem_MemoryEntryType* pEntry = NULL_PTR;

	DEM_DETCHECK_API_DCMGETDTCOFOBDFREEZEFRAME(Dem_InitState,DTC,&ret);
	if(ret)
	{
		/** @req [SWS_Dem_00624] Unique identifier for a freeze frame record as defined in
		 *  	 ISO 15031-5. The value 0x00 indicates the complete OBD freeze frame. Other
		 *  	 values are reserved for future functionality.
		 */
		if((DTCFormat == DEM_DTC_FORMAT_OBD) && (FrameNumber == 0x00u))
		{
			pEntry = Dem_SelectMostImportant();

			if(pEntry != NULL_PTR)
			{
#if(DEM_OBD_COMPLIANCY == 15u)
				*DTC = Dem_ConfigPtr->DemDTC[Dem_ConfigPtr->DemEventParameter\
									[pEntry->EventId - 1u].DemDTCRef].DemDtcValue;
#else
				*DTC = Dem_ConfigPtr->DemObdDTC[Dem_ConfigPtr->DemDTC[Dem_ConfigPtr->\
						DemEventParameter[pEntry->EventId - 1u].DemDTCRef].DemObdDTCRef].DemDtcValue;
#endif /* #if(DEM_OBD_COMPLIANCY == 15u) */
				ret = (Std_ReturnType)E_OK;
			}
		}
	}
	else
	{
		ret = (Std_ReturnType)E_NOT_OK;
	}
	return ret;
}

/**
 * @sid				0xa3
 * @brief			Dem_DcmGetAvailableOBDMIDs
 * @details			Reports the value of a requested "availability-OBDMID" to the DCM upon a
 * 					Service $06 request. Derived from that the tester displays the supported
 * 					tests a mechanic can select from.API is needed in OBD-relevant ECUs only.
 *
 * @param[in]		Obdmid: Availability OBDMID ($00,$20, $40...$E0)
 *
 * @param[out]		Obdmidvalue: Bit coded information on the support of OBDMIDs.
 *
 * @return     		The result of reporting DTR result.
 * @retval			E_OK: Report of DTR result successful.
 * @retval			E_NOT_OK: Report of DTR result failed.
 */
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetAvailableOBDMIDs
(
    uint8 Obdmid,
    uint32* Obdmidvalue
)
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;
    const Dem_DtrsType* pDtr = Dem_ConfigPtr->DemDtrs;
	uint16 u16Loop = 0u;

	DEM_DETCHECK_API_DCMGETAVAILABLEOBDMIDS(Dem_InitState,Obdmidvalue,&ret);
	if(ret)
	{
		/**
		 * @req [SWS_Dem_00760] Upon request by the Dcm, the Dem shall compute “Supported-OBDMID”
		 * 		information, i.e. the “availability OBDMIDs”. Since the Dem_DcmGetAvailableOBDMIDs
		 * 		reports only value per standardized OBDMID ($00, $20, $40...),the Dcm has to call
		 * 		this API iteratively until no further availability OBDMID is supported.
		 */
		*Obdmidvalue = 0u;
		while(u16Loop < DEM_DTR_NUM)
		{
			if((pDtr->DemDtrEventRef != 0xFFFFu)&&(Dem_ISEnable_EventAvaliable(pDtr->DemDtrEventRef)))
			{
				if((pDtr[u16Loop].DemDtrMid > Obdmid) && (pDtr[u16Loop].DemDtrMid < (Obdmid + 0x20u)))
				{
					*Obdmidvalue |= (uint32)1u << (pDtr[u16Loop].DemDtrMid - Obdmid - 1u);
				}
			}
			u16Loop++;
		}

		if(*Obdmidvalue != 0u)
		{
			ret = (Std_ReturnType)E_OK;
		}
	}
	else
	{
		ret = (Std_ReturnType)E_NOT_OK;
	}
	return ret;
}

/**
 * @sid				0xa4
 * @brief			Dem_DcmGetNumTIDsOfOBDMID
 * @details			Gets the number of TIDs per (functional) OBDMID. This can be used by the DCM to
 * 					iteratively request for OBD/TID result data within a loop from
 * 					0. . . numberOfTIDs-1.API is needed in OBD-relevant ECUs only.
 *
 * @param[in]		Obdmid: OBDMID subject of the request to identify the number of assigned TIDs.
 *
 * @param[out]		Obdmidvalue: Number of assigned TIDs for the requested OBDMID. Used as loop
 * 					value for the DCM to retrieve all OBD/TID result data.
 *
 * @return     		The result of getting number of TIDs.
 * @retval			E_OK: get number of TIDs successful.
 * @retval			E_NOT_OK: get number of TIDs failed.
 */
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetNumTIDsOfOBDMID
(
    uint8 Obdmid,
    P2VAR(uint8, AUTOMATIC, DEM_CODE) numberOfTIDs
)
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;
	uint16 u16Loop = 0u;
	Dem_EventIdType DtrEventRef = 0xFFFFu;
	DEM_DETCHECK_API_DCMGETNUMTIDSOFOBDMID(Dem_InitState,numberOfTIDs,&ret);
	if(ret)
	{
		/**
		 * @req [SWS_Dem_00761] Upon request by the Dcm, the Dem shall repond with the
		 * 		number of TIDs per requested OBDMID using the API Dem_DcmGetNumTIDsOfOBDMID.
		 * 		This value can be used by the Dcm to iteratively request for the DTR data per
		 * 		OBDMID/TIDindex whereas the TID-index loops from 0 to number-of-TIDs minus one.
		 */
		*numberOfTIDs = 0u;
		while(u16Loop < DEM_DTR_NUM)
		{
			DtrEventRef = Dem_ConfigPtr->DemDtrs[u16Loop].DemDtrEventRef;
			if((DtrEventRef != 0xFFFFu) && (Dem_ISEnable_EventAvaliable(DtrEventRef)))
			{
				if(Dem_ConfigPtr->DemDtrs[u16Loop].DemDtrMid == Obdmid)
				{
					*numberOfTIDs += 1u;
				}
			}
			u16Loop++;
		}

		if(*numberOfTIDs != 0u)
		{
			ret = (Std_ReturnType)E_OK;
		}
	}
	else
	{
		ret = (Std_ReturnType)E_NOT_OK;
	}
	return ret;
}

/**
 * @sid				0xa5
 * @brief			Dem_DcmGetDTRData
 * @details			Reports a DTR data along with TID-value, UaSID, test result with lower and
 * 					upper limit. API is needed in OBD-relevant ECUs only.
 *
 * @param[in]		Obdmid: Identification of a DTR element by assigned DTRId.
 * @param[in]		TIDindex: Index of the TID within the DEM. Runs from 0 to "numberOfTIDs"
 * 					obtained in the call to Dem_DcmGetNumTIDsOfOBDMID().
 *
 * @param[out]		TIDvalue: TID to be put on the tester reponse.
 * @param[out]		UaSID: UaSID to be put on the tester reponse.
 * @param[out]		Testvalue: Latest test result.
 * @param[out]		Lowlimvalue: Lower limit value associated to the latest test result.
 * @param[out]		Upplimvalue: Upper limit value associated to the latest test result.
 *
 * @return     		The result of reporting DTR result.
 * @retval			E_OK: Report of DTR result successful.
 * @retval			E_NOT_OK: Report of DTR result failed.
 */
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetDTRData
(
    uint8 Obdmid,
    uint8 TIDindex,
    P2VAR(uint8, AUTOMATIC, DEM_CODE) TIDvalue,
    P2VAR(uint8, AUTOMATIC, DEM_CODE) UaSID,
    P2VAR(uint16, AUTOMATIC, DEM_CODE) Testvalue,
    P2VAR(uint16, AUTOMATIC, DEM_CODE) Lowlimvalue,
    P2VAR(uint16, AUTOMATIC, DEM_CODE) Upplimvalue
)
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;
	uint16 u16Loop = 0u;
	Dem_EventIdType DtrEventRef = 0xFFFFu;
	uint8 u8Index = 0u;
	DEM_DETCHECK_API_DCMGETDTRDATA(Dem_InitState,\
							TIDvalue,UaSID,Testvalue,Lowlimvalue,Upplimvalue,&ret);
	if(ret)
	{
		/**
		 * @req [SWS_Dem_00762] Upon request by the Dcm, the Dem shall respond with the data
		 * 		available for a particular OBDMID / TIDindex per requested OBDMID using the API
		 * 		Dem_DcmGetDTRData. This value can be used by the Dcm to iteratively request for
		 * 		the DTR data per OBDMID / TIDindex starting from 0 to numberofTIDs minus one.
		 */
		while(u16Loop < DEM_DTR_NUM)
		{
			DtrEventRef = Dem_ConfigPtr->DemDtrs[u16Loop].DemDtrEventRef;
			if((DtrEventRef != 0xFFFFu) && (Dem_ISEnable_EventAvaliable(DtrEventRef)))
			{
				if(!(Dem_ISEnable_DTCSuppress(\
						Dem_ConfigPtr->DemEventParameter[DtrEventRef].DemDTCRef)))
				{
					if(Dem_ConfigPtr->DemDtrs[u16Loop].DemDtrMid == Obdmid)
					{
						if(u8Index == TIDindex)
						{
							*TIDvalue = Dem_ConfigPtr->DemDtrs[u16Loop].DemDtrTid;
							*UaSID = Dem_ConfigPtr->DemDtrs[u16Loop].DemDtrUasid;
							*Testvalue = Dem_DtrInfo[u16Loop].TestResult;
							*Lowlimvalue = Dem_DtrInfo[u16Loop].LowerLimit;
							*Upplimvalue = Dem_DtrInfo[u16Loop].UpperLimit;
							ret = (Std_ReturnType)E_OK;
							break;
						}
						u8Index++;
					}
				}
			}
			u16Loop++;
		}
	}
	else
	{
		ret = (Std_ReturnType)E_NOT_OK;
	}
	return ret;
}

/**
 * @sid				0x51
 * @brief			Dem_SetEventDisabled
 * @details			Service for reporting the event as disabled to the Dem for the PID $41
 *					computation. API is needed in OBD-relevant ECUs only.
 *
 * @param[in]		EventId: Identification of an event by assigned EventId.
 *
 * @return     		The result of setting event to disabled.
 * @retval			E_OK: set of event to disabled was successfull.
 * @retval			E_NOT_OK: set of event disabled failed.
 */
FUNC(Std_ReturnType, DEM_CODE) Dem_SetEventDisabled
(
    Dem_EventIdType EventId
)
{
    Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;

    DEM_DETCHECK_API_SETEVENTDISABLED(Dem_InitState,EventId,&ret);
    if(ret)
    {
		/**
		 * @req [SWS_Dem_00348] d The Dem module shall provide the disabling of events (refer to
		 * 		chapter 8.3.8.1). OBD Events Suppression (refer to chapter 7.4.8) shall be ignored
		 * 		for this computation.
		 * @req [SWS_Dem_00294] In order to allow a monitor to report that the event cannot be
		 * 		computed in the driving cycle (aborted e.g. due to physical reasons), the Dem shall
		 * 		provide the API Dem_SetEventDisabled.
		 * 		Note: For the computation of PID $41, the monitor has to report its event as disabled,
		 * 		if the test cannot be carried out anymore until the end of this driving cycle.
		 * 		Note: SetEventDisabled does report an Event as “uncompletable“ during the current
		 * 		driving cycle. It does not turn the Event into a Events Suppression according to
		 * 		chapter 7.4.8
		 */
    	Dem_Enable_ObdDisableEvent(EventId-1);
		ret = (Std_ReturnType)E_OK;
    }
	else
	{
		ret = (Std_ReturnType)E_NOT_OK;
	}
    return ret;
}

/**
 * @sid				0x73
 * @brief			Dem_RepIUMPRFaultDetect
 * @details			Service for reporting that faults are possibly found because all conditions are
 * 					fullfilled. API is needed in OBD-relevant ECUs only.
 *
 * @param[in]		RatioID: Ratio Identifier reporting that a respective monitor could have found
 * 					a fault - only used when interface option "API" is selected.
 *
 * @return     		Always return E_OK.
 * @retval			E_OK: report of IUMPR result was successfully reported.
 */
FUNC(Std_ReturnType, DEM_CODE) Dem_RepIUMPRFaultDetect
(
    Dem_RatioIdType RatioID
)
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;

	DEM_DETCHECK_API_REPIUMPRFAULTDETECT(Dem_InitState,RatioID,&ret);
	if(ret)
	{
#if (DEM_RATIO_NUM > 0)
		/**
		 * @req [SWS_Dem_00360] For OBD relevant systems the Dem module shall provide the
		 * 		API Dem_RepIUMPRFaultDetect.
		 * @req [SWS_Dem_00296] d The Dem module shall provide the API Dem_RepIUMPRFaultDetect
		 * 		for the asymmetric monitor to report that a malfunction could have been found.
		 */
		if(Dem_General.DemRatio[RatioID].DemRatioKind == DEM_RATIO_API)
		{
			Dem_IUMPRInfo[RatioID].DemNumeratorlock = (boolean)FALSE;
		}
#endif /* #if (DEM_RATIO_NUM > 0) */
		ret = (Std_ReturnType)E_OK;
	}
	else
	{
		ret = (Std_ReturnType)E_NOT_OK;
	}

	return ret;
}

/**
 * @sid				0xae
 * @brief			Dem_SetIUMPRDenCondition
 * @details			Service for reporting that faults are possibly found because all conditions are
 * 					fullfilled. API is needed in OBD-relevant ECUs only.
 *
 * @param[in]		ConditionId: Identification of a IUMPR denominator condition ID
 * 					(General Denominator, Cold start, EVAP, 500mi).
 * @param[in]		ConditionStatus: Status of the IUMPR denominator condition (Notreached,
 * 					reached, not reachable / inhibited).
 *
 * @return     		The result of setting IUMPR denominator condition.
 * @retval			E_OK: set of IUMPR denominator condition was successful.
 * @retval			E_NOT_OK: set of IUMPR denominator condition failed or could not be accepted.
 */
FUNC(Std_ReturnType, DEM_CODE) Dem_SetIUMPRDenCondition
(
    Dem_IumprDenomCondIdType ConditionId,
    Dem_IumprDenomCondStatusType ConditionStatus
)
{
    Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;

    DEM_DETCHECK_API_SETIUMPRDENCONDITION(Dem_InitState,ConditionId,&ret);
    if(ret)
    {
    	/**
    	 * @req [SWS_Dem_00717] The Dem shall provide the API Dem_SetIUMPRDenCondition
    	 * 		(refer to chapter 8.3.8.3) to set the status of a particular condition
    	 * 		(mainly in depending ECUs).
    	 * @req [SWS_Dem_00714] The Dem shall provide an API Dem_SetIUMPRDenCondition to
    	 * 		get informed about the IUMPR-Cycle Flag status by a software component.
    	 */
		Dem_DenomCondStatus[ConditionId-1] = ConditionStatus;
		ret = (Std_ReturnType)E_OK;
    }
	else
	{
		ret = (Std_ReturnType)E_NOT_OK;
	}
    return ret;
}

/**
 * @sid				0xaf
 * @brief			Dem_GetIUMPRDenCondition
 * @details			In order to communicate the status of the (additional) denominator conditions
 * 					among the OBD relevant ECUs, the API is used to retrieve the condition status
 * 					from the Dem of the ECU where the conditions are computed.
 * 					API is needed in OBD-relevant ECUs only.
 *
 * @param[in]		ConditionId: Identification of a IUMPR denominator condition ID
 * 					(General Denominator, Cold start, EVAP, 500mi).
 *
 * @param[out]		ConditionStatus: Status of the IUMPR denominator condition (Notreached,
 * 					reached, not reachable / inhibited).
 *
 * @return     		The result of getting IUMPR denominator condition.
 * @retval			E_OK: get of IUMPR denominator condition was successful.
 * @retval			E_NOT_OK: get of IUMPR denominator condition failed.
 */
FUNC(Std_ReturnType, DEM_CODE) Dem_GetIUMPRDenCondition
(
    Dem_IumprDenomCondIdType ConditionId,
    Dem_IumprDenomCondStatusType* ConditionStatus
)
{
    Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;

    DEM_DETCHECK_API_GETIUMPRDENCONDITION(Dem_InitState,ConditionId,&ret);
    if(ret)
    {
    	/**
    	 * @req [SWS_Dem_00716] The Dem shall provide the API Dem_GetIUMPRDenCondition
    	 * 		to read out the status of a particular condition.
    	 * @req [SWS_Dem_00966] The Dem shall provide an API Dem_GetIUMPRDenCondition
    	 * 		to give a software component the possibility to get the General
    	 * 		Denominator status information.
    	 */
    	if(Dem_DenomCondStatus[ConditionId-1] != 0xFFu)
    	{
    		*ConditionStatus = Dem_DenomCondStatus[ConditionId-1];
    		ret = (Std_ReturnType)E_OK;
    	}
    }
	else
	{
		ret = (Std_ReturnType)E_NOT_OK;
	}
    return ret;
}

/**
 * @sid				0x71
 * @brief			Dem_RepIUMPRDenLock
 * @details			Service is used to lock a denominator of a specific monitor.
 * 					API is needed in OBD-relevant ECUs only.
 *
 * @param[in]		RatioID: Ratio Identifier reporting that specific denominator is locked (for
 * 					physical reasons - e.g. temperature conditions or minimum activity).
 *
 * @return     		The result of reporting IUMPR denominator condition.
 * @retval			E_OK: report of IUMPR denominator status was successfully reported.
 * @retval			E_NOT_OK: report of IUMPR denominator status was not successfully reported.
 */
FUNC(Std_ReturnType, DEM_CODE) Dem_RepIUMPRDenLock
(
    Dem_RatioIdType RatioID
)
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;

	DEM_DETCHECK_API_REPIUMPRDENLOCK(Dem_InitState,RatioID,&ret);
	if(ret)
	{
#if (DEM_RATIO_NUM > 0)
		/**
		 * @req [SWS_Dem_00362] The Dem module shall provide the APIs for locking (refer to chapter
		 *  	8.3.8.5) and unlocking (refer to chapter 8.3.8.6) of the denominator under special
		 *  	conditions if the DemIUMPRDenGroup is configured as DEM_IUMPR_DEN_PHYS_API.
		 * @req [SWS_Dem_00297] The Dem shall provide the API Dem_RepIUMPRDenLock to IUMPR-relevant
		 * 		SWC, to control the denominator specific to the respective RatioId.
		 */
		if(Dem_General.DemRatio[RatioID].DemRatioKind == DEM_RATIO_API)
		{
			Dem_IUMPRInfo[RatioID].DemDenominatorlock = (boolean)TRUE;
			ret = (Std_ReturnType)E_OK;
		}
#endif /* #if (DEM_RATIO_NUM > 0) */
	}
	else
	{
		ret = (Std_ReturnType)E_NOT_OK;
	}
	return ret;
}

/**
 * @sid				0x72
 * @brief			Dem_RepIUMPRDenRelease
 * @details			Service is used to release a denominator of a specific monitor.
 * 					API is needed in OBD-relevant ECUs only.
 *
 * @param[in]		RatioID: Ratio Identifier reporting that specific denominator is locked (for
 * 					physical reasons - e.g. temperature conditions or minimum activity).
 *
 * @return     		The result of reporting IUMPR denominator condition.
 * @retval			E_OK: report of IUMPR denominator status was successfully reported.
 * @retval			E_NOT_OK: report of IUMPR denominator status was not successfully reported.
 */
FUNC(Std_ReturnType, DEM_CODE) Dem_RepIUMPRDenRelease
(
    Dem_RatioIdType RatioID
)
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;

	DEM_DETCHECK_API_REPIUMPRDENRELEASE(Dem_InitState,RatioID,&ret);
	if(ret)
	{
#if (DEM_RATIO_NUM > 0)
		/**
		 * @req [SWS_Dem_00362] The Dem module shall provide the APIs for locking (refer to chapter
		 *  	8.3.8.5) and unlocking (refer to chapter 8.3.8.6) of the denominator under special
		 *  	conditions if the DemIUMPRDenGroup is configured as DEM_IUMPR_DEN_PHYS_API.
		 * @req [SWS_Dem_00308] The Dem shall provide the API Dem_RepIUMPRDenRelease to
		 * 		IUMPRrelevant SW-C, to control the denominator specific to the respective RatioId.
		 */
		if(Dem_General.DemRatio[RatioID].DemRatioKind == DEM_RATIO_API)
		{
			Dem_IUMPRInfo[RatioID].DemDenominatorlock = (boolean)FALSE;
			ret = (Std_ReturnType)E_OK;
		}
#endif /* #if (DEM_RATIO_NUM > 0) */
    }
	else
	{
		ret = (Std_ReturnType)E_NOT_OK;
	}
	return ret;
}

/**
 * @sid				0x79
 * @brief			Dem_SetPtoStatus
 * @details			Service is used to set PTO status. API is needed in OBD-relevant ECUs only.
 *
 * @param[in]		PtoStatus: sets the status of the PTO (TRUE==active; FALSE==inactive).
 *
 * @return     		The result of setting PTO status.
 * @retval			E_OK: return E_OK when the new PTO-status has been adopted by the Dem.
 * @retval			E_NOT_OK: return E_NOT_OK in all other cases.
 */
FUNC(Std_ReturnType, DEM_CODE) Dem_SetPtoStatus
(
    boolean PtoStatus
)
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;

	DEM_DETCHECK_API_SETPTOSTATUS(Dem_InitState,&ret);
	if(ret)
	{
		Dem_PtoStatus = PtoStatus;
		ret = (Std_ReturnType)E_OK;
	}
	else
	{
		ret = (Std_ReturnType)E_NOT_OK;
	}
	return ret;
}

FUNC(boolean, DEM_CODE) Dem_CauseMILON
(
    Dem_EventIdType InternalId
)
{
	boolean ret = (boolean)FALSE;
#if(DEM_MILINDICATOR_REF != 0xFF)
	uint8 u8Loop;

	if(Dem_IndicatorStatus[DEM_MILINDICATOR_REF] != DEM_INDICATOR_OFF)
	{
		if(Dem_ISEnable_UdsStatusBits(InternalId,DEM_UDS_STATUS_WIR))
		{
			for(u8Loop = 0u;
				u8Loop < Dem_ConfigPtr->DemEventParameter[InternalId].DemIndicatorAttributeNum;
				u8Loop++)
			{
				if(Dem_ConfigPtr->DemEventParameter[InternalId].DemIndicatorAttribute[u8Loop].DemIndicatorRef\
						== DEM_MILINDICATOR_REF)
				{
					ret = (boolean)TRUE;
					break;
				}
			}
		}
	}
#endif /* #if(DEM_MILINDICATOR_REF != 0xFF) */
	return ret;
}

/**
 * @sid				0xb3
 * @brief			Dem_ReadDataOfPID01
 * @details			Service to report the value of PID $01 computed by the Dem.
 * 					API is needed in OBD-relevant ECUs only.
 *
 * @param[out]		PID01value: Buffer containing the contents of PID $01 computed by the Dem.
 * 					The buffer is provided by the application with the size of 4 bytes.
 *
 * @return     		Always E_OK is returned, as E_NOT_OK will never appear.
 */
FUNC(Std_ReturnType, DEM_CODE) Dem_ReadDataOfPID01
(
    P2VAR(uint8, AUTOMATIC, DEM_CODE) PID01value
)
{
	uint8	u8Loop					= 0u;
	uint8 	u8Obd2DtcNum 			= 0u;
	uint16 	u16Loop 				= 0u;
	uint16 	u16DtcRef 				= 0u;
	uint16 	u16ObdDTCRef 			= 0u;
	uint16	u16SupportedReadiness	= 0u;
	uint16 	u16ReadinessStatus		= 0u;
	uint16	u16ReadinessMILON		= 0u;
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;

	DEM_DETCHECK_API_READDATAOFPID01(Dem_InitState,PID01value,&ret);
	if(ret)
	{
		for(u16Loop = 0u; u16Loop < DEM_EVENT_PARAMETER_NUM; u16Loop++)
		{
			/**
			 * @req [SWS_Dem_01101] A suppressed DTC shall not be visible for the following Dcm
			 * 		query-functions;
			 * @req [SWS_Dem_01103] Unavailable events shall not be considered for computation of
			 * 		service $01 PID $41.
			 */
			u16DtcRef = Dem_ConfigPtr->DemEventParameter[u16Loop].DemDTCRef;
			if((u16DtcRef != 0xFFFFu)\
				&&(Dem_ISEnable_EventAvaliable(u16Loop))\
				&&(!Dem_ISEnable_DTCSuppress(u16DtcRef))\
				&&(Dem_ConfigPtr->DemDTC[u16DtcRef].DemObdDTCRef != 0xFFFFu))
			{
				/**
				 * @req [SWS_Dem_00351] The Dem module shall compute and provide the number
				 *	  	of confirmed faults (PID $01, Byte A).
				 * @req [SWS_Dem_01137] For WWH-OBD PID$01 shall not provide the number of
				 * 		confirmed faults.
				 */
				if(Dem_ISEnable_UdsStatusBits(u16Loop,DEM_UDS_STATUS_CDTC))
				{
					if(u8Obd2DtcNum < 0x7Fu)
					{
						u8Obd2DtcNum++;
					}
				}
			}
		}

		for(u8Loop = 0u; u8Loop < DEM_READINESS_GROUP_NUM; u8Loop++)
		{
			for(u16Loop = 0u; u16Loop < DEM_EVENT_PARAMETER_NUM; u16Loop++)
			{
				u16DtcRef = Dem_ConfigPtr->DemEventParameter[u16Loop].DemDTCRef;
				if((Dem_ISEnable_EventAvaliable(u16Loop))\
					&&(u16DtcRef != 0xFFFFu)\
					&&(!Dem_ISEnable_DTCSuppress(u16DtcRef)))
				{
					u16ObdDTCRef = Dem_ConfigPtr->DemDTC[u16DtcRef].DemObdDTCRef;
					if(u16ObdDTCRef != 0xFFFFu)
					{
						if(Dem_ConfigPtr->DemObdDTC[u16ObdDTCRef].DemEventOBDReadinessGroup == u8Loop)
						{
							u16SupportedReadiness |= ((uint16)1 << u8Loop);

							/**
							 * @req [SWS_Dem_00354] d The Dem module shall compute for PID $01
							 * 		the readiness status(if all events of a
							 * 		DemEventOBDReadinessGroup are reported as OK tested since
							 * 		last clear, or the event has caused MIL on).Suppressed Events
							 * 		(refer to chapter 7.4.8)shall be ignored for this computation.
							 */
							if((!Dem_ISEnable_UdsStatusBits(u16Loop,DEM_UDS_STATUS_TF))\
									&&(!Dem_ISEnable_UdsStatusBits(u16Loop,DEM_UDS_STATUS_TNCSLC)))
							{
								/* 0: monitor complete(YES) / monitor not appilcable(N/A)
								 * 1: monitor not complete(NO)*/
							}
							else
							{
								u16ReadinessStatus |= ((uint16)1 << u8Loop);
							}

							if((boolean)TRUE == Dem_CauseMILON(u16Loop))
							{
								u16ReadinessMILON |= ((uint16)1 << u8Loop);
							}
						}
					}
				}
			}
		}

		/**
		 * @req [SWS_Dem_01138] The Dem module shall compute and provide the ECU MIL status(PID $01, Byte A).
		 * 		PID01 - bit0~bit6:	the number of confirmed(CDTC==1) OBD DTC,
		 * 		PID01 - bit7:		the status of MIL(1:MIL ON,0:MIL OFF).
		 * @req [SWS_Dem_01139] For WWH-OBD PID$01 shall not provide the ECU MIL status.
		 * note: "DEM_OBD_COMPLIANCY == 15" means tha the ECU conform to WWH OBD agreement.
		 */
#if(DEM_OBD_COMPLIANCY == 15u)
		Dem_PID01Info[0] = u8Obd2DtcNum;
#else
#if(DEM_MILINDICATOR_REF != 0xFF)
		if(Dem_IndicatorStatus[DEM_MILINDICATOR_REF] != DEM_INDICATOR_OFF)
		{
			Dem_PID01Info[0] = u8Obd2DtcNum | 0x80u;
		}
		else
#endif /* #if(DEM_MILINDICATOR_REF != 0xFF) */
		{
			Dem_PID01Info[0] = u8Obd2DtcNum;
		}
#endif /* #if(DEM_OBD_COMPLIANCY == 15u) */

		u16ReadinessStatus &= (~u16ReadinessMILON);

		Dem_PID01Info[1] = ((u16ReadinessStatus & 0x07u) << 4u) | (u16SupportedReadiness & 0x07u);

#if (DEM_OBDENGINE_TYPE == DEM_IGNITION_COMPRESSION)
		Dem_PID01Info[1] |= 0x08u;
		Dem_PID01Info[2] = ((u16SupportedReadiness & 0x0200u) >> 2u) | \
						((u16SupportedReadiness & 0x6000u) >> 8u) | \
						((u16SupportedReadiness & 0x1000u) >> 9u) | \
						((u16SupportedReadiness & 0x0c00u) >> 10u);
		Dem_PID01Info[3] = ((u16ReadinessStatus & 0x0200u) >> 2u) | \
						((u16ReadinessStatus & 0x6000u) >> 8u) | \
						((u16ReadinessStatus & 0x1000u) >> 9u) | \
						((u16ReadinessStatus & 0x0c00u) >> 10u);
#endif /* #if (DEM_OBDENGINE_TYPE == DEM_IGNITION_COMPRESSION) */
#if(DEM_OBDENGINE_TYPE == DEM_IGNITION_SPARK)
		Dem_PID01Info[2] = ((u16SupportedReadiness & 0x0380u) >> 2u) | \
						((u16SupportedReadiness & 0x0078u) >> 3u);
		Dem_PID01Info[3] = ((u16ReadinessStatus & 0x0380u) >> 2u) | \
						((u16ReadinessStatus & 0x0078u) >> 3u);
#endif /* #if (DEM_OBDENGINE_TYPE == DEM_IGNITION_COMPRESSION) */

		PID01value[0] = Dem_PID01Info[0];
		PID01value[1] = Dem_PID01Info[1];
		PID01value[2] = Dem_PID01Info[2];
		PID01value[3] = Dem_PID01Info[3];

		ret = (Std_ReturnType)E_OK;
	}
	else
	{
		ret = (Std_ReturnType)E_NOT_OK;
	}
	return ret;
}

/**
 * @sid				0xb1
 * @brief			Dem_GetDataOfPID21
 * @details			Service to get the value of PID $21 from the Dem by a software component.
 * 					API is needed in OBD-relevant ECUs only.
 *
 * @param[out]		PID21value: Content of PID $21 as raw hex value.
 *
 * @return     		Always E_OK is returned, as E_NOT_OK will never appear.
 */
FUNC(Std_ReturnType, DEM_CODE) Dem_GetDataOfPID21
(
    P2VAR(uint8, AUTOMATIC, DEM_CODE) PID21value
)
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;

	DEM_DETCHECK_API_GETDATAOFPID21(Dem_InitState,PID21value,&ret);
	if(ret)
	{
/* @req [SWC_Dem_01094] */
#if((DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU)&&(DEM_OBDCENTRALIZED_PID21HANDLING == STD_ON))
		/**
		 * @req [SWS_Dem_01097] On invocation of Dem_GetDataOfPID21 the internal calculated
		 * 		PID $21 value shall be returned.
		 * 		Note: AUTOSAR defines that OBD Primary ECUs do not calculate the PID $21 value
		 * 		by its own.
		 */
		PID21value[0] = (uint8)Dem_DistanceMILON;
		PID21value[1] = (uint8)(Dem_DistanceMILON >> (uint8)8);
#endif/*#if((DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU)&&(DEM_OBDCENTRALIZED_PID21HANDLING == STD_ON))*/
		ret = (Std_ReturnType)E_OK;
	}
	else
	{
		ret = (Std_ReturnType)E_NOT_OK;
	}

	return ret;
}

/**
 * @sid				0xa6
 * @brief			Dem_SetDataOfPID21
 * @details			Service to set the value of PID $21 from the Dem by a software component.
 * 					API is needed in OBD-relevant ECUs only.
 *
 * @param[in]		PID21value: Buffer containing the contents of PID $21.
 * 					The buffer is provided by the Dcm with the appropriate size, i.e. during
 * 					configuration, the Dcm identifies the required size from the largest PID
 * 					in order to configure a PIDBuffer.
 *
 * @return     		Always E_OK is returned, as E_NOT_OK will never appear.
 */
FUNC(Std_ReturnType, DEM_CODE) Dem_SetDataOfPID21
(
    P2VAR(uint8, AUTOMATIC, DEM_CODE) PID21value
)
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;

	DEM_DETCHECK_API_SETDATAOFPID21(Dem_InitState,PID21value,&ret);
	if(ret)
	{
/* @req [SWS_Dem_00703] and [SWS_Dem_00704] and [SWC_Dem_01017]*/
#if((DEM_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU) && (DEM_OBDCENTRALIZED_PID21HANDLING == TRUE))
		/**
		 * @req [SWS_Dem_01095] On invocation of Dem_SetDataOfPID21 the internal PID $21 value
		 * 		shall be updated.
		 * 		Note: AUTOSAR defines that OBD Primary ECUs do not calculate the PID $21 value
		 * 		by its own.
		 */
		Dem_DistanceMILON = (uint16)(PID21value[0]) | (uint16)(PID21value[1] << (uint8)8);
		Dem_SetPID21 = (boolean)TRUE;
		ret = (Std_ReturnType)E_OK;
#endif /* #if((DEM_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU) && (DEM_OBDCENTRALIZED_PID21HANDLING == TRUE)) */
	}
	else
	{
		ret = (Std_ReturnType)E_NOT_OK;
	}
	return ret;
}

/**
 * @sid				0xa7
 * @brief			Dem_SetDataOfPID31
 * @details			Service to set the value of PID $31 from the Dem by a software component.
 * 					API is needed in OBD-relevant ECUs only.
 *
 * @param[in]		PID31value: Buffer containing the contents of PID $31.
 * 					The buffer is provided by the Dcm with the appropriate size, i.e. during
 * 					configuration, the Dcm identifies the required size from the largest PID
 * 					in order to configure a PIDBuffer.
 *
 * @return     		Always E_OK is returned, as E_NOT_OK will never appear.
 */
FUNC(Std_ReturnType, DEM_CODE) Dem_SetDataOfPID31
(
    P2VAR(uint8, AUTOMATIC, DEM_CODE) PID31value
)
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;

	DEM_DETCHECK_API_SETDATAOFPID31(Dem_InitState,PID31value,&ret);
	if(ret)
	{
/* @req [SWS_Dem_01016] */
#if((DEM_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU) && (DEM_OBDCENTRALIZED_PID31HANDLING == TRUE))

		Dem_DistanceClearDTC = (uint16)(PID31value[0]) | (uint16)(PID31value[1] << (uint8)8);

		ret = (Std_ReturnType)E_OK;
#endif /* #if((DEM_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU) && (DEM_OBDCENTRALIZED_PID31HANDLING == TRUE)) */
	}
	else
	{
		ret = (Std_ReturnType)E_NOT_OK;
	}
	return ret;
}

/**
 * @sid				0xa8
 * @brief			Dem_SetDataOfPID4D
 * @details			Service to set the value of PID $4D from the Dem by a software component.
 * 					API is needed in OBD-relevant ECUs only.
 *
 * @param[in]		PID4Dvalue: Buffer containing the contents of PID $4D.
 * 					The buffer is provided by the Dcm with the appropriate size, i.e. during
 * 					configuration, the Dcm identifies the required size from the largest PID
 * 					in order to configure a PIDBuffer.
 *
 * @return     		Always E_OK is returned, as E_NOT_OK will never appear.
 */
FUNC(Std_ReturnType, DEM_CODE) Dem_SetDataOfPID4D
(
    P2VAR(uint8, AUTOMATIC, DEM_CODE) PID4Dvalue
)
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;

	DEM_DETCHECK_API_SETDATAOFPID4D(Dem_InitState,PID4Dvalue,&ret);
	if(ret)
	{
#if(DEM_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU)

		Dem_EngRTMILON = ((uint16)PID4Dvalue[1] << (uint8)8) | (uint16)PID4Dvalue[0];

		ret = (Std_ReturnType)E_OK;
#endif /* #if(DEM_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU) */
	}
	else
	{
		ret = (Std_ReturnType)E_NOT_OK;
	}
	return ret;
}

/**
 * @sid				0xa9
 * @brief			Dem_SetDataOfPID4E
 * @details			Service to set the value of PID $4E from the Dem by a software component.
 * 					API is needed in OBD-relevant ECUs only.
 *
 * @param[in]		PID4Evalue: Buffer containing the contents of PID $4E.
 * 					The buffer is provided by the Dcm with the appropriate size, i.e. during
 * 					configuration, the Dcm identifies the required size from the largest PID
 * 					in order to configure a PIDBuffer.
 *
 * @return     		Always E_OK is returned, as E_NOT_OK will never appear.
 */
FUNC(Std_ReturnType, DEM_CODE) Dem_SetDataOfPID4E
(
    P2VAR(uint8, AUTOMATIC, DEM_CODE) PID4Evalue
)
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;

	DEM_DETCHECK_API_SETDATAOFPID4E(Dem_InitState,PID4Evalue,&ret);
	if(ret)
	{
#if(DEM_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU)

		Dem_EngRTSinceClear = ((uint16)PID4Evalue[1] << 8u) | (uint16)PID4Evalue[0];

		ret = (Std_ReturnType)E_OK;
#endif /* #if(DEM_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU) */
	}
	else
	{
		ret = (Std_ReturnType)E_NOT_OK;
	}
	return ret;
}

/**
 * @sid				0xaa
 * @brief			Dem_SetPfcCycleQualified
 * @details			Marks the current OBD driving cycle as having met the criteria for the PFC
 * 					cycle. API is needed in OBD-relevant ECUs only.
 *
 * @return     		Always E_OK is returned, as E_NOT_OK will never appear.
 */
FUNC(Std_ReturnType, DEM_CODE) Dem_SetPfcCycleQualified
(
    void
)
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;
	uint8 u8Loop = 0u;
	const Dem_OperationCycleType* 	pDemOpCyc = Dem_General.DemOperationCycle;

	DEM_DETCHECK_API_SETPFCCYCLEQUALIFIED(Dem_InitState,&ret);
	if(ret)
	{
		do
		{
			if((pDemOpCyc[u8Loop].DemOperationCycleType == DEM_OPCYC_OBD_DCY)\
					&&(Dem_ISEnable_OperationCycle(pDemOpCyc[u8Loop].DemOperationCycleId)))
			{
				Dem_PDCState = (boolean)TRUE;
				break;
			}
			u8Loop++;
		}while(u8Loop < DEM_OPERATION_CYCLE_NUM);
		ret = (Std_ReturnType)E_OK;
	}
	else
	{
		ret = (Std_ReturnType)E_NOT_OK;
	}
	return ret;
}

/**
 * @sid				0xab
 * @brief			Dem_GetPfcCycleQualified
 * @details			Returns TRUE if the criteria for the PFC cycle have been met during the current
 *  				OBD driving cycle. API is needed in OBD-relevant ECUs only.
 *
 * @param[out]		TRUE: During the current OBD driving cycle the criteria for the PFC cycle have
 * 					been met.
 * 					FALSE: During the current OBD driving cycle the criteria for the PFC cycle
 * 					have not been met.
 *
 * @return     		Always E_OK is returned, as E_NOT_OK will never appear.
 */
FUNC(Std_ReturnType, DEM_CODE) Dem_GetPfcCycleQualified
(
    P2VAR(boolean, AUTOMATIC, DEM_VAR) isqualified
)
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;
#if(DEM_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU)
	uint8 u8Loop = 0u;
	const Dem_OperationCycleType* pDemOpCyc = Dem_General.DemOperationCycle;
#endif /* #if(DEM_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU) */

	DEM_DETCHECK_API_GETPFCCYCLEQUALIFIED(Dem_InitState,isqualified,&ret);
	if(ret)
	{
		*isqualified = (boolean)FALSE;
		/**
		 * @req [SWS_Dem_00728] The Dem (of a Primary ECU) shall provide the interface
		 * 		Dem_GetPfcCycleQualified to get informed that the current OBD driving
		 * 		cycle has met the criteria for the PFC cycle by a software component.
		 */
#if(DEM_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU)
		/**
		 * @req [SWS_Dem_00725] The Dem of the MIL Master ECU shall provide the interface
		 * 		Dem_GetPfcCycleQualified (returning a boolean) (refer to chapter 8.3.8.15)
		 * 		to read the current state of the PFC cycle. TRUE indicates that during the
		 * 		current OBD driving cycle the conditions for the PFC cycle have been met.
		 */
#if(DEM_MILINDICATOR_REF != 0xFF)
		if(Dem_IndicatorStatus[DEM_MILINDICATOR_REF] != DEM_INDICATOR_OFF)
		{
			while(u8Loop < DEM_OPERATION_CYCLE_NUM)
			{
				if((pDemOpCyc[u8Loop].DemOperationCycleType == DEM_OPCYC_OBD_DCY) && \
						(Dem_ISEnable_OperationCycle(pDemOpCyc[u8Loop].DemOperationCycleId)))
				{
					Dem_PDCState = (boolean)TRUE;
				}
				u8Loop++;
			}

			*isqualified = Dem_PDCState;
		}
#endif /* #if(DEM_MILINDICATOR_REF != 0xFF) */
#endif /* #if(DEM_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU) */
		ret = (Std_ReturnType)E_OK;

	}
	else
	{
		ret = (Std_ReturnType)E_NOT_OK;
	}
	return ret;
}

#if(DEM_OBD_SUPPORT == DEM_OBD_DEP_SEC_ECU)
/**
 * @sid				0xac
 * @brief			Dem_SetClearDTC
 * @details			API to inform the Dem (of a Dependend / Secondary ECU) about the reception of
 * 					service $04 execution by a software component.
 * 					API is needed in OBD-relevant ECUs only.
 *
 * @param[in]		DTC: Defines the DTC in respective format, that has been cleared from the event
 * 					memory.
 * @param[in]		DTCFormat: Format of the provided DTC value.
 * @param[in]		DTCOrigin: Event memory (e.g. MIRROR).
 *
 * @return     		Return value unused - only for compatibility with according RTE operation.
 */

FUNC(Std_ReturnType, DEM_CODE) Dem_SetClearDTC
(
    uint32 DTC,
    Dem_DTCFormatType DTCFormat,
    Dem_DTCOriginType DTCOrigin
)
{
	Std_ReturnType ret = E_NOT_OK;

	DEM_DETCHECK_API_SETCLEARDTC(Dem_InitState,&ret);
	if(ret)
	{

	}
	return ret;
}
#endif /* #if(DEM_OBD_SUPPORT == DEM_OBD_DEP_SEC_ECU) */

/**
 * @sid				0xb4
 * @brief			Dem_GetB1Counter
 * @details			Service to report the value of the B1 counter computed by the Dem.
 * 					API is needed in OBD-relevant ECUs only.
 *
 * @param[out]		B1Counter: Buffer containing the B1 counter.
 * 					The buffer is provided by the application with the size of 2 bytes.
 *
 * @return     		Always E_OK is returned, as E_NOT_OK will never appear.
 */
FUNC(Std_ReturnType, DEM_CODE) Dem_GetB1Counter
(
    P2VAR(uint16, AUTOMATIC, DEM_CODE) B1Counter
)
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;

	DEM_DETCHECK_API_GETB1COUNTER(Dem_InitState,&ret);
	if(ret)
	{
		*B1Counter = Dem_B1Counter;
		ret = (Std_ReturnType)E_OK;
	}
	else
	{
		ret = (Std_ReturnType)E_NOT_OK;
	}
	return ret;
}

/**
 * @sid				0xa2
 * @brief			Dem_SetDTR
 * @details			Reports a DTR result with lower and upper limit. The internal eventstatus
 * 					serves as master whether the DTR values are forwarded or ignored, also taking
 * 					the DTRUpdateKind into account. The EventId that is related to the DTR is
 * 					assigned per configuration(and derived from ServiceNeeds). Processing takes
 * 					enable/storage conditions into account.API is needed in OBD-relevant ECUs only.
 *
 * @param[in]		DTRId: Identification of a DTR element by assigned DTRId.
 * @param[in]		TestResult: Test result of DTR.
 * @param[in]		LowerLimit: Lower limit of DTR.
 * @param[in]		UpperLimit: Upper limit of DTR.
 * @param[in]		Ctrlval: Control value of the DTR to support its interpretation Dem-internally.
 *
 * @return     		The result of reporting DTR result.
 * @retval			E_OK: Report of DTR result successful.
 * @retval			E_NOT_OK: Report of DTR result failed.
 */
FUNC(Std_ReturnType, DEM_CODE) Dem_SetDTR
(
    uint16 DTRId,
    sint32 TestResult,
    sint32 LowerLimit,
    sint32 UpperLimit,
    Dem_DTRControlType Ctrlval
)
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;
	uint16 u16Loop = 0u;
    Dem_EventIdType DtrEventRef = 0xFFFFu;
	boolean isFailed = (boolean)FALSE;
	boolean isTested = (boolean)FALSE;

	DEM_DETCHECK_API_SETDTR(Dem_InitState,&ret);
	if(ret)
	{
#if(DEM_DTR_NUM > 0)
		do
		{
			if(Dem_ConfigPtr->DemDtrs[u16Loop].DemDtrId == DTRId)
			{
                DtrEventRef = Dem_ConfigPtr->DemDtrs[u16Loop].DemDtrEventRef;
                if((DtrEventRef != 0xFFFFu) && (Dem_ISEnable_EventAvaliable(DtrEventRef)))
                {
                    isTested = !(Dem_ISEnable_UdsStatusBits(DtrEventRef,DEM_UDS_STATUS_TNCTOC));
                    isFailed = Dem_ISEnable_UdsStatusBits(DtrEventRef,DEM_UDS_STATUS_TF);

                    switch(Ctrlval)
    			    {
    					case DEM_DTR_CTL_NORMAL:
    						/**
    						 * @req [SWS_Dem_00757] d Based on DemDtrUpdateKind and the status of the
    						 * 		associated event (taking enable/storage conditions into account),
    						 * 		the Dem shall either process or ignore the reported DTR values.
    						 */
    						if((Dem_ConfigPtr->DemDtrs[u16Loop].DemDtrUpdateKind == DEM_DTR_UPDATE_ALWAYS)\
    							|| ((isTested == (boolean)TRUE) && ((isFailed == (boolean)TRUE)\
    								|| ((TestResult >= LowerLimit) && (TestResult <= UpperLimit)))))
    						{
    							Dem_DtrInfo[u16Loop].TestResult = TestResult;
    							Dem_DtrInfo[u16Loop].LowerLimit = LowerLimit;
    							Dem_DtrInfo[u16Loop].UpperLimit = UpperLimit;
    							ret = (Std_ReturnType)E_OK;
    						}
    						break;
    					case DEM_DTR_CTL_NO_MAX:
    						if((Dem_ConfigPtr->DemDtrs[u16Loop].DemDtrUpdateKind == DEM_DTR_UPDATE_ALWAYS)\
    							|| ((isTested == (boolean)TRUE) && \
    									((isFailed == (boolean)TRUE) || (TestResult >= LowerLimit))))
    						{
    							Dem_DtrInfo[u16Loop].TestResult = TestResult;
    							Dem_DtrInfo[u16Loop].LowerLimit = LowerLimit;
    							ret = (Std_ReturnType)E_OK;
    						}
    						break;
    					case DEM_DTR_CTL_NO_MIN:
    						if((Dem_ConfigPtr->DemDtrs[u16Loop].DemDtrUpdateKind == DEM_DTR_UPDATE_ALWAYS)\
    							|| ((isTested == (boolean)TRUE) && \
    									((isFailed == (boolean)TRUE) || (TestResult <= UpperLimit))))
    						{
    							Dem_DtrInfo[u16Loop].TestResult = TestResult;
    							Dem_DtrInfo[u16Loop].UpperLimit = UpperLimit;
    							ret = (Std_ReturnType)E_OK;
    						}
    						break;
    					case DEM_DTR_CTL_RESET:
    						if((Dem_ConfigPtr->DemDtrs[u16Loop].DemDtrUpdateKind == DEM_DTR_UPDATE_ALWAYS)\
    							|| ((isTested == (boolean)TRUE) && (isFailed == (boolean)TRUE)))
    						{
    							Dem_DtrInfo[u16Loop].TestResult = 0u;
    							Dem_DtrInfo[u16Loop].LowerLimit = 0u;
    							Dem_DtrInfo[u16Loop].UpperLimit = 0u;
    							ret = (Std_ReturnType)E_OK;
    						}
    							break;
    					default:
    						break;
                    }
    				break;

                }
			}
			u16Loop++;
		}while(u16Loop < DEM_DTR_NUM);

#endif /* #if(DEM_DTR_NUM > 0) */
	}
	else
	{
		ret = (Std_ReturnType)E_NOT_OK;
	}
	return ret;
}

#if(DEM_OBD_COMPLIANCY == 15u)
STATIC FUNC(void, DEM_CODE) Dem_OpCycCounterForB1Handle
(
	uint8   OperationCycleId
)
{
    const Dem_EventParameterType* pEvent 	= Dem_ConfigPtr->DemEventParameter;
    const Dem_DTCType* pDTC 				= Dem_ConfigPtr->DemDTC;
	uint16 u16Loop 							= 0u;

    do
    {
    	if(pEvent[u16Loop].DemDTCRef != 0xFFFFu)
    	{
    		if(pDTC[pEvent[u16Loop].DemDTCRef].DemWWHOBDDTCClass == DEM_DTC_WWHOBD_CLASS_B1)
			{
				if(pEvent[u16Loop].DemOperationCycleRef == OperationCycleId)
				{
					if((Dem_ISEnable_UdsStatusBits(u16Loop,DEM_UDS_STATUS_CDTC))\
							&& (Dem_ISEnable_UdsStatusBits(u16Loop,DEM_UDS_STATUS_TF)))
					{
						Dem_OpCycCounterForB1 = 0u;
						break;
					}
				}
			}
    	}
    	u16Loop++;
    }while(u16Loop < DEM_EVENT_PARAMETER_NUM);

    if(u16Loop >= DEM_EVENT_PARAMETER_NUM)
    {
    	if(Dem_OpCycCounterForB1 < 0xFFu)
    	{
        	Dem_OpCycCounterForB1++;
    	}
    }
    /**
     * @req [SWS_Dem_01156] d The B1 counter shall reset to zero after three consecutive
     * 		operating sequences where no Class B1 event have been detected.
     */
    if(Dem_OpCycCounterForB1 > 3u)
    {
    	Dem_B1Counter = 0u;
    }
}

STATIC FUNC(void, DEM_CODE) Dem_OpCycCounterForMIHandle
(
	uint8   OperationCycleId
)
{
    const Dem_EventParameterType* pEvent 	= Dem_ConfigPtr->DemEventParameter;
    const Dem_DTCType* pDTC 				= Dem_ConfigPtr->DemDTC;
	uint16 u16Loop 							= 0u;

	do
	{
		if(pEvent[u16Loop].DemDTCRef != 0xFFFFu)
		{
			if(pDTC[pEvent[u16Loop].DemDTCRef].DemWWHOBDDTCClass == DEM_DTC_WWHOBD_CLASS_B1)
			{
				if(pEvent[u16Loop].DemOperationCycleRef == OperationCycleId)
				{
					if(Dem_B1Counter >= 200u)
					{
						Dem_OpCycCounterForMI = 0u;
						break;
					}
				}
			}
			else if(pDTC[pEvent[u16Loop].DemDTCRef].DemWWHOBDDTCClass == DEM_DTC_WWHOBD_CLASS_A)
			{
				if(pEvent[u16Loop].DemOperationCycleRef == OperationCycleId)
				{
					if((Dem_ISEnable_UdsStatusBits(u16Loop,DEM_UDS_STATUS_CDTC))\
							&& (Dem_ISEnable_UdsStatusBits(u16Loop,DEM_UDS_STATUS_TF)))
					{
						Dem_OpCycCounterForMI = 0u;
						break;
					}
				}
			}
		}
		u16Loop++;
	}while(u16Loop < DEM_EVENT_PARAMETER_NUM);

	if(u16Loop >= DEM_EVENT_PARAMETER_NUM)
	{
		if(Dem_OpCycCounterForMI < 0xFFu)
		{
			Dem_OpCycCounterForMI++;
		}
	}
	/**
	 * @req [SWS_Dem_01144] The counter shall continue its incrementation if the Continuous-MI
	 * 		is again commanded on within three operation sequences.
	 * @req [SWS_Dem_01145] d The counter shall reset to zero and start incrementing its value
	 * 		if the Continuous-MI is again commanded on after more than three operation sequences.
	 */
	if(Dem_OpCycCounterForMI > 3u)
	{
		Dem_ConMICounter = 0u;
	}
}

STATIC FUNC(void, DEM_CODE) Dem_B1CounterHandle
(
	void
)
{
	const Dem_EventParameterType* pEvent = Dem_ConfigPtr->DemEventParameter;
    const Dem_DTCType* pDTC				 = Dem_ConfigPtr->DemDTC;
    uint16 u16Loop						 = 0u;

	do
	{
		/**
		 * @req [SWS_Dem_01154] The B1 counter shall increment for each 1 hour engine operating hour
		 * 		during which at least one Class B1 event is detected as Confirmed and TestFailed.
		 * @req [SWS_Dem_01155] The B1 counter shall latch its value when no Class B1 event is no
		 * 		longer detected as Confirmed and TestFailed or after a ClearDTC request.
		 * 		The B1 counter continue its incrementation if a Class B1 event is again detected as
		 * 		Confirmed and TestFailed.
		 */
		if(pEvent[u16Loop].DemDTCRef != 0xFFFFu)
		{
			if((pDTC[pEvent[u16Loop].DemDTCRef].DemWWHOBDDTCClass == DEM_DTC_WWHOBD_CLASS_B1)\
						&& (Dem_ISEnable_UdsStatusBits(u16Loop,DEM_UDS_STATUS_CDTC)\
							&& Dem_ISEnable_UdsStatusBits(u16Loop,DEM_UDS_STATUS_TF)))
			{
				Dem_OpCycCounterForB1 = 0u;

				Dem_B1Timer += DEM_TASK_TIME;

				if(Dem_B1Timer >= DEM_HOUR)
				{
					Dem_B1Timer = 0u;
					/**
					 * @req [SWS_Dem_01158] The B1 counter shall be reported as a two byte value.
					 * 		If any count operation occurs which would cause a counter to roll over
					 * 		past 0x00FF then the count value shall instead be latched at 0x00FF.
					 */
					if(Dem_B1Counter < 0xFFu)
					{
						Dem_B1Counter++;
					}
				}
				break;
			}
		}
		u16Loop++;
	}while(u16Loop < DEM_EVENT_PARAMETER_NUM);
	/**
	 * @req [SWS_Dem_01157] If B1 Counter exceeds 200 engine operating hours and no Class
	 * 		B1 event have been detected the counter shall be set to 190.
	 */
    if((Dem_B1Counter > 200u) && (u16Loop >= DEM_EVENT_PARAMETER_NUM))
    {
		Dem_B1Counter = 190u;
    }
}

FUNC(void,DEM_CODE) Dem_OBDMILStatusUpdate
(
	void
)
{
	const Dem_EventParameterType* pEvent = NULL_PTR;
	uint8 u8Class;
	uint16 u16Loop;
	uint8 u8Loop;

	/**
	 * @req [SWS_Dem_01160] If the B1 counter exceeds 200 engine operating hours the
	 * 		Activation Mode 4 shall be active.
	 */
	if(Dem_B1Counter >= 200u)
	{
		Dem_ActiveMode = 4u;
	}
#if(DEM_INDICATOR_ATTRIBUTE_TOTAL_NUM > 0)
	else
	{
		for(u16Loop = 0u; u16Loop < DEM_EVENT_PARAMETER_NUM; u16Loop++)
		{
			pEvent = &Dem_ConfigPtr->DemEventParameter[u16Loop];
			if(pEvent->DemDTCRef != 0xFFFFu)
			{
				u8Class = Dem_ConfigPtr->DemDTC[pEvent->DemDTCRef].DemWWHOBDDTCClass;
				/* check whether the event has been activated. */
				if((Dem_ISEnable_UdsStatusBits(u16Loop,DEM_UDS_STATUS_CDTC)) \
						&& (Dem_ISEnable_UdsStatusBits(u16Loop,DEM_UDS_STATUS_TF)))
				{
					/* check whether the event is related to MIL.*/
					for(u8Loop = 0u; u8Loop < pEvent->DemIndicatorAttributeNum; u8Loop++)
					{
						if(pEvent->DemIndicatorAttribute[u8Loop].DemIndicatorRef == DEM_MILINDICATOR_REF)
						{
							/**
							 * @req [SWS_Dem_01161] If at least one Class A event is Confirmed
							 * 		and TestFailed the Activation Mode 4 shall be active.
							 */
							if(u8Class == DEM_DTC_WWHOBD_CLASS_A)
							{
								/**
								 * @req [SWS_Dem_01141] If Activation Mode 4 becomes
								 * 		active the counter shall be reset to 0.
								 */
								if(Dem_ActiveMode != 4u)
								{
									Dem_ConMICounter = 0u;
								}
								Dem_ActiveMode = 4u;
								break;
							}
							else if((u8Class == DEM_DTC_WWHOBD_CLASS_B1)\
									||(u8Class == DEM_DTC_WWHOBD_CLASS_B2))
							{
								Dem_ActiveMode = 3u;
							}
							else if(u8Class == DEM_DTC_WWHOBD_CLASS_C)
							{
								if(Dem_ActiveMode < 3u)
								{
									Dem_ActiveMode = 2u;
								}
							}
						}
					}
					if(Dem_ActiveMode == 4u)
					{
						break;
					}
				}
			}
		}
	}
#endif /* #if(DEM_INDICATOR_ATTRIBUTE_TOTAL_NUM > 0) */

#if(DEM_MILINDICATOR_REF != 0xFF)
	switch(Dem_ActiveMode)
	{
		case 4u:
			Dem_IndicatorStatus[DEM_MILINDICATOR_REF] = DEM_INDICATOR_CONTINUOUS;
			break;
		case 3u:
			Dem_IndicatorStatus[DEM_MILINDICATOR_REF] = DEM_INDICATOR_SHORT;
			break;
		case 2u:
			Dem_IndicatorStatus[DEM_MILINDICATOR_REF] = DEM_INDICATOR_ON_DEMAND;
			break;
		case 1u:
			Dem_IndicatorStatus[DEM_MILINDICATOR_REF] = DEM_INDICATOR_OFF;
			break;
		default:
			break;
	}
#endif /* #if(DEM_MILINDICATOR_REF != 0xFF) */
}

STATIC FUNC(void, DEM_CODE) Dem_ConMICounterHandle
(
	void
)
{
    /**
     * @req [SWS_Dem_01142] The counter shall increment for each engine operating hour
     * 		during which the event is detected and the Continuous-MI is commanded to be on.
     * @req [SWS_Dem_01143] The counter shall halt its value when the Continuous-MI is no
     * 		longer commanded to be on.
     * @req [SWS_Dem_01150] The counter shall halt its value when the Continuous-MI is no
     * 		longer commanded to be on.
     */
#if(DEM_MILINDICATOR_REF != 0xFF)
    if(Dem_IndicatorStatus[DEM_MILINDICATOR_REF] == DEM_INDICATOR_CONTINUOUS)
    {
		Dem_OpCycCounterForMI = 0u;
		Dem_WUCCounterForMI = 0u;

		Dem_MITimer += DEM_TASK_TIME;
		if(Dem_MITimer >= DEM_HOUR)
		{
			Dem_MITimer = 0u;
			/**
			 * @req [SWS_Dem_01147] The counter shall be reported as a two byte value.
			 * 		If any count operation occurs which would cause a counter to roll
			 * 		over past 0x00FF then the count value shall instead be maintained
			 * 		at 0x00FF.
			 */
			if(Dem_ConMICounter < 0x00FFu)
			{
				Dem_ConMICounter++;
			}

			/**
			 * @req [SWS_Dem_01149] The counter shall increment for each engine
			 * 		operating hour during which the event is detected and the
			 * 		Continuous-MI is commanded to be on.
			 * @req [SWS_Dem_01152] The counter shall be reported as a two byte value.
			 * 		If any count operation occurs which would cause a counter to roll
			 * 		over past 0x00FF then the count value shall instead be maintained
			 * 		at 0x00FF.
			 */
			if(Dem_CumConMICounter < 0x00FFu)
			{
				Dem_CumConMICounter++;
			}
		}
    }
#endif /* #if(DEM_MILINDICATOR_REF != 0xFF) */

	/**
	 * @req [SWS_Dem_01146] The counter shall reset to zero if the Continuous-MI
	 *  	is not commanded on after more than 40 warm-up cycles or after more
	 *  	than 200 engine operating hours or upon a ClearDTC request.
	 */
    if(200u < Dem_GetVehicleInfo(DEM_OBD_TIME_SINCE_ENGINE_START))
    {
		Dem_ConMICounter = 0u;
    }
}
#endif /* #if(DEM_OBD_COMPLIANCY == 15u) */

#endif /* (DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT) */

#ifdef __cplusplus
}
#endif
/** @} */

