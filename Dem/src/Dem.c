/* PRQA S 0292 EOF */
/**
 * @file        Dem.c
 * @brief       AUTOSAR Dem  - Dem module source file.
 * @details     Dem module source file, containing the C implementation of Autosar API specification
 *              and other variables and functions that are exported by the Dem module.
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

/* PRQA S 5087,0781,0791,0491,0498,0492,2981,4558,1503,2993,2996,2877,2880,2995,2984,2985,4394 EOF #
 *
 * 1.5087 -- Violates MISRA 2004 Required Rule 19.1,#include statements in a file should only
 * be preceded by other preprocessor directives or comments.
 *
 * 2.0781 -- Violates MISRA 2004 Required Rule 5.6,'%1s' is being used as a structure/union
 * member as well as being a label, tag or ordinary identifier.
 *
 * 3.0791 -- Violates MISRA 2004 Required Rule 5.1, Macro identifier does not differ from
 *  other macro identifier(s) within the specified number of significant characters.
 *
 * 4.0491 -- Violates MISRA 2004 Required Rule 17.4, Array subscripting applied to an object
 * of pointer type.
 *
 * 5.0498 -- Violates MISRA 2004 Required Rule 17.4, A unary increment or decrement operator
 * is being applied to a pointer.
 *
 * 6.0492 -- Violates MISRA 2004 Required Rule 17.4, Array subscripting applied to a function
 * parameter declared as a pointer.
 *
 * 7.2981 -- Violates MISRA 2004 Required Rule 21.1, This initialization is redundant. The
 * value of this object is never used before being modified.
 *
 * 8.4558 -- Violates MISRA 2004 Required Rule 13.2, An expression of 'essentially unsigned'
 * type (%1s) is being used as the %2s operand of this logical operator(%3s).
 *
 * 9.1503 -- Violates MISRA 2004 Required Rule 14.1, The function '%1s' is defined but is not
 * used within this project.
 *
 * @page misra_violations MISRA-C:2004 violations
 */
/* PRQA S 0857,1290,0751,3415,1842,1843,0715,1863,2742,3673,4115,0488 EOF #
 * @page misra_violations MISRA-C:2004 violations
 */
/*====================================================================================================*
 *                                           INCLUDE FILES
 *====================================================================================================*/
#include "Dem.h"
#include "Dem_Dcm.h"
#include "SchM_Dem.h"
#include "Rte_Dem.h"
#include "Dcm.h"
#if(DEM_TRIGGER_FIM_REPORTS == STD_ON)
#include "FiM.h"
#endif /* #if(DEM_TRIGGER_FIM_REPORTS == STD_ON) */

#if(DEM_TRIGGER_DLT_REPORTS == STD_ON)
#include "Dlt.h"
#endif /* #if(DEM_TRIGGER_DLT_REPORTS == STD_ON) */

#if(DEM_J1939_SUPPORT == STD_ON)
#include "J1939Dcm_Types.h"
#endif /* #if(DEM_J1939_SUPPORT == STD_ON) */

#include "NvM.h"

#include "Dem_Internal.h"

#ifdef AH_TEST_DEM
#include "TestCode.h"
#endif /* #ifdef AH_TEST_DEM */
/*====================================================================================================*
 *                                  SOURCE FILE VERSION INFORMATION
 *====================================================================================================*/
#define DEM_VENDOR_ID_C               					(0U)
#define DEM_AR_RELEASE_MAJOR_VERSION_C      			(4U)
#define DEM_AR_RELEASE_MINOR_VERSION_C      			(2U)
#define DEM_AR_RELEASE_REVISION_VERSION_C      			(2U)
#define DEM_SW_MAJOR_VERSION_C      					(1U)
#define DEM_SW_MINOR_VERSION_C      					(2U)
#define DEM_SW_PATCH_VERSION_C      					(0U)

/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/
/* Check if current file and Dem.h header file are of the same vendor */
#if(DEM_VENDOR_ID_C != DEM_VENDOR_ID )
#error "Dem.c and Dem.h have different vendor id"
#endif /* #if(DEM_VENDOR_ID_C != DEM_VENDOR_ID ) */

/* Check if current file and Dem.h header file are of the same Autosar version */
#if(\
		(DEM_AR_RELEASE_MAJOR_VERSION_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
		(DEM_AR_RELEASE_MINOR_VERSION_C != DEM_AR_RELEASE_MINOR_VERSION) || \
		(DEM_AR_RELEASE_REVISION_VERSION_C != DEM_AR_RELEASE_REVISION_VERSION) \
   )
#error "AutoSar Version Number of Dem.c and Dem.h are different "
#endif /* #if(\
				(DEM_AR_RELEASE_MAJOR_VERSION_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
				(DEM_AR_RELEASE_MINOR_VERSION_C != DEM_AR_RELEASE_MINOR_VERSION) || \
				(DEM_AR_RELEASE_REVISION_VERSION_C != DEM_AR_RELEASE_REVISION_VERSION) \
   	   	     ) */

/* Check if current file and Dem.h header file are of the same Software version */
#if(\
		(DEM_SW_MAJOR_VERSION_C != DEM_SW_MAJOR_VERSION) || \
		(DEM_SW_MINOR_VERSION_C != DEM_SW_MINOR_VERSION) || \
		(DEM_SW_PATCH_VERSION_C != DEM_SW_PATCH_VERSION) \
   )
#error "Software Version Number of Dem.c and Dem.h are different "
#endif /* #if(\
				(DEM_SW_MAJOR_VERSION_C != DEM_SW_MAJOR_VERSION) || \
				(DEM_SW_MINOR_VERSION_C != DEM_SW_MINOR_VERSION) || \
				(DEM_SW_PATCH_VERSION_C != DEM_SW_PATCH_VERSION) \
   	   	   	 ) */

/* Check if current file and Dem_Dcm.h header file are of the same vendor */
#if(DEM_VENDOR_ID_C != DEM_DCM_VENDOR_ID )
#error "Dem.c and Dem_Dcm.h have different vendor id"
#endif /* #if(DEM_VENDOR_ID_C != DEM_DCM_VENDOR_ID ) */

/* Check if current file and Dem.h header file are of the same Autosar version */
#if(\
		(DEM_AR_RELEASE_MAJOR_VERSION_C != DEM_DCM_AR_RELEASE_MAJOR_VERSION) || \
		(DEM_AR_RELEASE_MINOR_VERSION_C != DEM_DCM_AR_RELEASE_MINOR_VERSION) || \
		(DEM_AR_RELEASE_REVISION_VERSION_C != DEM_DCM_AR_RELEASE_REVISION_VERSION) \
   )
#error "AutoSar Version Number of Dem.c and Dem_Dcm.h are different "
#endif /* #if(\
				(DEM_AR_RELEASE_MAJOR_VERSION_C != DEM_DCM_AR_RELEASE_MAJOR_VERSION) || \
				(DEM_AR_RELEASE_MINOR_VERSION_C != DEM_DCM_AR_RELEASE_MINOR_VERSION) || \
				(DEM_AR_RELEASE_REVISION_VERSION_C != DEM_DCM_AR_RELEASE_REVISION_VERSION) \
   	   	     ) */

/* Check if current file and Dem_Dcm.h header file are of the same Software version */
#if(\
		(DEM_SW_MAJOR_VERSION_C != DEM_DCM_SW_MAJOR_VERSION) || \
		(DEM_SW_MINOR_VERSION_C != DEM_DCM_SW_MINOR_VERSION) || \
		(DEM_SW_PATCH_VERSION_C != DEM_DCM_SW_PATCH_VERSION) \
   )
#error "Software Version Number of Dem.c and Dem_Dcm.h are different "
#endif /* #if(\
				(DEM_SW_MAJOR_VERSION_C != DEM_DCM_SW_MAJOR_VERSION) || \
				(DEM_SW_MINOR_VERSION_C != DEM_DCM_SW_MINOR_VERSION) || \
				(DEM_SW_PATCH_VERSION_C != DEM_DCM_SW_PATCH_VERSION) \
   	   	   	 ) */

/* Check if current file and Dem_Internal.h header file are of the same vendor */
#if(DEM_VENDOR_ID_C != DEM_INTERNAL_VENDOR_ID )
#error "Dem.c and Dem_Internal.h have different vendor id"
#endif /* #if(DEM_VENDOR_ID_C != DEM_INTERNAL_VENDOR_ID ) */

/* Check if current file and Dem_Internal.h header file are of the same Autosar version */
#if(\
		(DEM_AR_RELEASE_MAJOR_VERSION_C != DEM_INTERNAL_AR_RELEASE_MAJOR_VERSION) || \
		(DEM_AR_RELEASE_MINOR_VERSION_C != DEM_INTERNAL_AR_RELEASE_MINOR_VERSION) || \
		(DEM_AR_RELEASE_REVISION_VERSION_C != DEM_INTERNAL_AR_RELEASE_REVISION_VERSION) \
   )
#error "AutoSar Version Number of Dem.c and Dem_Internal.h are different "
#endif /* #if(\
				(DEM_AR_RELEASE_MAJOR_VERSION_C != DEM_INTERNAL_AR_RELEASE_MAJOR_VERSION) || \
				(DEM_AR_RELEASE_MINOR_VERSION_C != DEM_INTERNAL_AR_RELEASE_MINOR_VERSION) || \
				(DEM_AR_RELEASE_REVISION_VERSION_C != DEM_INTERNAL_AR_RELEASE_REVISION_VERSION) \
   	   	     ) */

/* Check if current file and Dem_Internal.h header file are of the same Software version */
#if(\
		(DEM_SW_MAJOR_VERSION_C != DEM_INTERNAL_SW_MAJOR_VERSION) || \
		(DEM_SW_MINOR_VERSION_C != DEM_INTERNAL_SW_MINOR_VERSION) || \
		(DEM_SW_PATCH_VERSION_C != DEM_INTERNAL_SW_PATCH_VERSION) \
   )
#error "Software Version Number of Dem.c and Dem_Internal.h are different "
#endif /* #if(\
				(DEM_SW_MAJOR_VERSION_C != DEM_INTERNAL_SW_MAJOR_VERSION) || \
				(DEM_SW_MINOR_VERSION_C != DEM_INTERNAL_SW_MINOR_VERSION) || \
				(DEM_SW_PATCH_VERSION_C != DEM_INTERNAL_SW_PATCH_VERSION) \
   	   	   	 ) */

#ifndef DISABLE_INTERMOD_VERSION_CHECK

/* Check if current file and SchM_Dem.h header file are of the same Autosar version */
#if(\
		(DEM_AR_RELEASE_MAJOR_VERSION_C != SCHM_DEM_AR_RELEASE_MAJOR_VERSION) || \
		(DEM_AR_RELEASE_MINOR_VERSION_C != SCHM_DEM_AR_RELEASE_MINOR_VERSION) \
   )
#error "AutoSar Version Number of Dem.c and SchM_Dem.h are different "
#endif /* #if(\
				(DEM_AR_RELEASE_MAJOR_VERSION_C != SCHM_DEM_AR_RELEASE_MAJOR_VERSION) || \
				(DEM_AR_RELEASE_MINOR_VERSION_C != SCHM_DEM_AR_RELEASE_MINOR_VERSION) \
			 ) */

#if(DEM_TRIGGER_FIM_REPORTS == STD_ON)
/* Check if current file and Fim.h header file are of the same Autosar version */
#if(\
		(DEM_AR_RELEASE_MAJOR_VERSION_C != FIM_AR_RELEASE_MAJOR_VERSION) || \
		(DEM_AR_RELEASE_MINOR_VERSION_C != FIM_AR_RELEASE_MINOR_VERSION) \
   )
#error "AutoSar Version Number of Dem.c and Fim.h are different "
#endif /* #if(\
				(DEM_AR_RELEASE_MAJOR_VERSION_C != FIM_AR_RELEASE_MAJOR_VERSION) || \
				(DEM_AR_RELEASE_MINOR_VERSION_C != FIM_AR_RELEASE_MINOR_VERSION) \
			 ) */
#endif /* #if(DEM_TRIGGER_FIM_REPORTS == STD_ON) */

#if(DEM_TRIGGER_DLT_REPORTS == STD_ON)
/* Check if current file and Dlt.h header file are of the same Autosar version */
#if(\
		(DEM_AR_RELEASE_MAJOR_VERSION_C != DLT_AR_RELEASE_MAJOR_VERSION) || \
		(DEM_AR_RELEASE_MINOR_VERSION_C != DLT_AR_RELEASE_MINOR_VERSION) \
   )
#error "AutoSar Version Number of Dem.c and Dlt.h are different "
#endif /* #if(\
				(DEM_AR_RELEASE_MAJOR_VERSION_C != DLT_AR_RELEASE_MAJOR_VERSION) || \
				(DEM_AR_RELEASE_MINOR_VERSION_C != DLT_AR_RELEASE_MINOR_VERSION) \
			 ) */
#endif /* #if(DEM_TRIGGER_DLT_REPORTS == STD_ON) */


/* Check if current file and NvM.h header file are of the same Autosar version */
#if(\
		(DEM_AR_RELEASE_MAJOR_VERSION_C != NVM_AR_RELEASE_MAJOR_VERSION) || \
		(DEM_AR_RELEASE_MINOR_VERSION_C != NVM_AR_RELEASE_MINOR_VERSION) \
   )
#error "AutoSar Version Number of Dem.c and NvM.h are different "
#endif /* #if(\
				(DEM_AR_RELEASE_MAJOR_VERSION_C != NVM_AR_RELEASE_MAJOR_VERSION) || \
				(DEM_AR_RELEASE_MINOR_VERSION_C != NVM_AR_RELEASE_MINOR_VERSION) \
			 ) */

#if(DEM_J1939_SUPPORT == STD_ON)
/* Check if current file and J1939Dcm_Types.h header file are of the same Autosar version */
#if(\
		(DEM_AR_RELEASE_MAJOR_VERSION_C != J1939DCM_TYPES_AR_RELEASE_MAJOR_VERSION) || \
		(DEM_AR_RELEASE_MINOR_VERSION_C != J1939DCM_TYPES_AR_RELEASE_MINOR_VERSION) \
   )
#error "AutoSar Version Number of Dem.c and J1939Dcm_Types.h are different "
#endif /* #if(\
				(DEM_AR_RELEASE_MAJOR_VERSION_C != J1939DCM_TYPES_AR_RELEASE_MAJOR_VERSION) || \
				(DEM_AR_RELEASE_MINOR_VERSION_C != J1939DCM_TYPES_AR_RELEASE_MINOR_VERSION) \
			 ) */
#endif /* #if(DEM_J1939_SUPPORT == STD_ON) */

/* Check if current file and Rte_Dem.h header file are of the same Autosar version */
#if(\
		(DEM_AR_RELEASE_MAJOR_VERSION_C != RTE_DEM_AR_RELEASE_MAJOR_VERSION) || \
		(DEM_AR_RELEASE_MINOR_VERSION_C != RTE_DEM_AR_RELEASE_MINOR_VERSION) \
   )
#error "AutoSar Version Number of Dem.c and Rte_Dem.h are different "
#endif /* #if(\
				(DEM_AR_RELEASE_MAJOR_VERSION_C != RTE_DEM_AR_RELEASE_MAJOR_VERSION) || \
				(DEM_AR_RELEASE_MINOR_VERSION_C != RTE_DEM_AR_RELEASE_MINOR_VERSION) \
			 ) */
#endif /* DISABLE_INTERMOD_VERSION_CHECK */
/*====================================================================================================*
 *                                           LOCAL TYPEDEFS
 *====================================================================================================*/

/*====================================================================================================*
 *                                            LOCAL MACROS
 *====================================================================================================*/

/*====================================================================================================*
 *                                           LOCAL CONSTANTS
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
#define DEM_START_SEC_VAR_NO_INIT_8
#include "Dem_MemMap.h"
/**
 * @brief Matching to DEM_MAX_FDC_DURING_CURRENT_CYCLE of DemInternalDataElement
 */
STATIC VAR(uint8,DEM_VAR)Dem_MaxFDCDurCurCycles[DEM_DTC_NUM];

/**
 * @brief	[SWS_Dem_00799]and[SWS_Dem_01068]and[SWS_Dem_00811]and[SWS_Dem_01069],
 * 			Record whether the DTC has captured freeze frame or extended data by
 * 			reaching the FDC threshold during this opreation cycle.
 */
#if(DEM_FREEZEFRAME_ENABLE == STD_ON)
STATIC VAR(uint8,DEM_VAR) Dem_CaptureFFOnFDC[DEM_DTC_NUM_BYTE];
#endif /* #if(DEM_FREEZEFRAME_ENABLE == STD_ON) */

#if(DEM_EXTENDED_DATA_CLASS_NUM > 0)
STATIC VAR(uint8,DEM_VAR) Dem_CaptureExtOnFDC[DEM_DTC_NUM_BYTE];
#endif /* #if(DEM_EXTENDED_DATA_CLASS_NUM > 0) */

/**
 * @brief Matching to DEM_MAX_FDC_SINCE_LAST_CLEAR of DemInternalDataElement
 */
STATIC VAR(uint8,DEM_VAR)Dem_MaxFDCSinceLastClear[DEM_DTC_NUM];
#define DEM_STOP_SEC_VAR_NO_INIT_8
#include "Dem_MemMap.h"
#endif /* #if(DEM_DTC_NUM > 0) */

#define DEM_START_SEC_VAR_NO_INIT_16
#include "Dem_MemMap.h"
/**
 * @brief Indicate the offset of event queue which will be read
 */
STATIC VAR(uint16,DEM_VAR)Dem_EventQueueRead = 0u;

/**
 * @brief Indicate the offset of event queue which will be write
 */
STATIC VAR(uint16,DEM_VAR)Dem_EventQueueWrite = 0u;

#if(DEM_NVRAM_BLOCKID_NUM > 0)
#if(DEM_NVRAM_DEBOUNCE_INFO_NUM > 0)
STATIC VAR(sint16,DEM_VAR)Dem_NvRAMDebounceCnt[DEM_NVRAM_DEBOUNCE_INFO_NUM];
#endif /* #if(DEM_NVRAM_DEBOUNCE_INFO_NUM > 0) */
#endif /* #if(DEM_NVRAM_BLOCKID_NUM > 0) */
#define DEM_STOP_SEC_VAR_NO_INIT_16
#include "Dem_MemMap.h"

#define DEM_START_SEC_VAR_NO_INIT_BOOLEAN
#include "Dem_MemMap.h"
#if(DEM_NVRAM_BLOCKID_NUM > 0)
#if(DEM_CLEAR_DTC_BEHAVIOR != DEM_CLRRESP_VOLATILE)
VAR(boolean,DEM_VAR) Dem_NvMPending = (boolean)FALSE;
#else
STATIC VAR(boolean,DEM_VAR) Dem_NvMPending = (boolean)FALSE;
#endif /* #if(DEM_CLEAR_DTC_BEHAVIOR != DEM_CLRRESP_VOLATILE) */
#endif /* #if(DEM_NVRAM_BLOCKID_NUM > 0) */
#define DEM_STOP_SEC_VAR_NO_INIT_BOOLEAN
#include "Dem_MemMap.h"

#define DEM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dem_MemMap.h"
/**
 * @brief Dem internal data,matching to DemInternalDataElement.
 */
#if(DEM_J1939_SUPPORT == STD_ON)
VAR(Dem_InternalDataType,DEM_VAR)Dem_EventInternalData[DEM_EVENT_PARAMETER_NUM];
#else
STATIC VAR(Dem_InternalDataType,DEM_VAR)Dem_EventInternalData[DEM_EVENT_PARAMETER_NUM];
#endif

#if(DEM_DEBOUNCE_COUNTER_BASED_SUPPORT == STD_ON)
#if(DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM > 0)
/**
 * @brief Dem Internal debounce counter variable
 */
STATIC VAR(Dem_DebounceCounterType,DEM_VAR) Dem_InternalDebounceCounter[DEM_DEBOUNCE_COUNTER_BASED_EVENT_NUM];
#endif /* #if(DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM > 0) */
#endif /* #if(DEM_DEBOUNCE_COUNTER_BASED_SUPPORT == STD_ON) */

#if(DEM_DEBOUNCE_TIME_BASED_SUPPORT == STD_ON)
#if(DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0)
/**
 * @brief Dem Internal debounce timer variable
 */
STATIC VAR(Dem_DebounceTimeType,DEM_VAR) DemInternalDebounceTimer[DEM_DEBOUNCE_TIME_BASED_EVENT_NUM];
#endif /* #if(DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0) */
#endif /* #if(DEM_DEBOUNCE_TIME_BASED_SUPPORT == STD_ON) */

#if(DEM_COMBINA_DTC_NUM > 0)
STATIC VAR(Dem_EventBufferType,DEM_VAR) Dem_CombinaDtcInfo[DEM_COMBINA_DTC_NUM];
#endif /* DEM_COMBINA_DTC_NUM */

#if(DEM_MAXNUMBER_PRESTORED_FF > 0)
/**
 * @brief Record PreFF information
 */
STATIC VAR(Dem_PreFFInfoType,DEM_VAR)Dem_PreFFInfos[DEM_MAXNUMBER_PRESTORED_FF];
#endif /* #if(DEM_MAXNUMBER_PRESTORED_FF > 0) */

/**
 * @brief 	Record informations of primary memory which include indication of
 *          over flow and how many entry stored in.
 */
STATIC VAR(Dem_MemoryInfoType,DEM_VAR) Dem_PrimaryMemoryInfo;

#if((DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU) || (DEM_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
/**
 * @brief 	Record informations of permanent memory which include indication of
 *          over flow and how many entry stored in.
 */
STATIC VAR(Dem_MemoryInfoType,DEM_VAR) Dem_PermanentMemoryInfo;
#endif /* #if((DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU) || (DEM_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU)) */
#define DEM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dem_MemMap.h"

#define DEM_START_SEC_VAR_INIT_8
#include "Dem_MemMap.h"
/**
 * @brief Indicate an aging cycle state.
 */
STATIC VAR(uint8,DEM_VAR) Dem_AgingCycle = 0xFFu;
#define DEM_STOP_SEC_VAR_INIT_8
#include "Dem_MemMap.h"
/*====================================================================================================*
 *                                           GLOBAL VARIABLES
 *====================================================================================================*/
#define DEM_START_SEC_VAR_NO_INIT_8
#include "Dem_MemMap.h"
/**
 * @brief Status of Dem initialization
 */
VAR(Dem_StateType,DEM_VAR) Dem_InitState = DEM_STATE_UNINIT;

#if(DEM_DTC_NUM > 0u)
/**
 * @brief Fault detection counter of dtcs
 */
VAR(sint8,DEM_VAR)Dem_InternalFDC[DEM_DTC_NUM];
#endif /* #if(DEM_DTC_NUM > 0u) */

#if(DEM_CALLBACK_INIT_MFOREFNC_TOTALNUM > 0)
VAR(Dem_InitMonitorReasonType,DEM_VAR) Dem_InitMonitorCbkStatus[DEM_EVENT_PARAMETER_NUM] = {0};
#endif /* #if(DEM_CALLBACK_INIT_MFOREFNC_TOTALNUM > 0) */

#if(DEM_GROUP_OF_DTC_NUM > 0)
/**
 * @brief Record dtc group status which used for Dem_DcmDisableDTCSetting and Dem_DcmEnableDTCSetting.
 */
VAR(uint8,DEM_VAR)Dem_DtcGroupSettingStatus[DEM_GROUP_OF_DTC_NUM_BYTE];
#endif /* #if(DEM_GROUP_OF_DTC_NUM > 0) */

/**
 * @brief Record uds status bits of relate dtc
 */
VAR(Dem_UdsStatusByteType,DEM_VAR)Dem_DtcUdsStatus[DEM_DTC_NUM];

#if(DEM_ENABLE_CONDITION_NUM > 0)
/**
 * @brief 	Enable condition status
 */
VAR(uint8,DEM_VAR) Dem_EnableConditionStatus[DEM_ENABLE_CONDITION_NUM_BYTE];
#endif /* #if(DEM_ENABLE_CONDITION_NUM > 0) */

#if(DEM_STORAGE_CONDITION_NUM > 0)
/**
 * @brief 	Storage condition status
 */
VAR(uint8,DEM_VAR) Dem_StorageConditionStatus[DEM_STORAGE_CONDITION_NUM_BYTE];
#endif /* #if(DEM_STORAGE_CONDITION_NUM > 0) */

/**
 * @brief Record event uds status bits
 */
VAR(Dem_UdsStatusByteType,DEM_VAR)Dem_EventUDSBitStatus[DEM_EVENT_PARAMETER_NUM];

 /**
  * @brief Record event internal status
  */
VAR(Dem_InternalEventStatusType,DEM_VAR)Dem_InternalEventStatus[DEM_EVENT_PARAMETER_NUM];

/**
 * @brief Record event bit change status and reach FDC threshold and transfer mirror memory,used to
 *        allocate event memory entry,and used to trigger capture freeze frame or extended data.
 */
VAR(Dem_EventTriggerConditionType,DEM_VAR)Dem_EventTriggerCondition[DEM_EVENT_PARAMETER_NUM];

/**
 * @brief Record operation cycles status,whether start or not,it use bit storage
 */
VAR(uint8,DEM_VAR) Dem_OperationCycleStatus[DEM_OPERATION_CYCLE_NUM_BYTE];

#if(DEM_COMPONENT_NUM > 0)
/**
 * @brief Record component status,it use bit storage(0:passed,1:failed)
 */
VAR(uint8,DEM_VAR) Dem_ComponentStatus[DEM_COMPONENT_NUM_BYTE];

/**
 * @brief Record component availability,it use bit storage(0:not available,1:available)
 */
VAR(uint8,DEM_VAR) Dem_ComponentAvailable[DEM_COMPONENT_NUM_BYTE];
#endif /* #if(DEM_COMPONENT_NUM > 0) */

#define DEM_STOP_SEC_VAR_NO_INIT_8
#include "Dem_MemMap.h"

#define DEM_START_SEC_VAR_NO_INIT_BOOLEAN
#include "Dem_MemMap.h"

/**
 * @brief 	Indicates whether a clear dtc operation is processing.
 */
VAR(boolean,DEM_VAR) Dem_ClearDtcLock = (boolean)FALSE;

/**
 * @brief Whether the triggering of the notification of Dcm shall be enabled
 */
VAR(boolean,DEM_VAR)Dem_DcmTriggerEnable = (boolean)FALSE;

/**
 * @brief Indicate relate dtc is suppressed or not. 0:DTC is suppressed; 1:DTC is available.
 */
VAR(uint8,DEM_VAR)Dem_DtcSuppress[DEM_DTC_NUM_BYTE];

#define DEM_STOP_SEC_VAR_NO_INIT_BOOLEAN
#include "Dem_MemMap.h"

#define DEM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dem_MemMap.h"

/**
 * @brief Global pointer which point to DemConfig configuration.
 */
P2CONST(Dem_ConfigType, AUTOMATIC, DEM_CONST) Dem_ConfigPtr = NULL_PTR;

#if(DEM_INDICATOR_NUM > 0)
#if((DEM_J1939_SUPPORT == STD_ON) || (DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT))
VAR(Dem_IndicatorStatusType,DEM_VAR) Dem_IndicatorStatus[DEM_INDICATOR_NUM];
#else
STATIC VAR(Dem_IndicatorStatusType,DEM_VAR) Dem_IndicatorStatus[DEM_INDICATOR_NUM];
#endif /* #if((DEM_J1939_SUPPORT == STD_ON) || (DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT)) */
#endif /* #if(DEM_INDICATOR_NUM > 0) */

/**
 * @brief Record the occur time of relate events,provide for Dem_DcmGetDTCByOccurrenceTime
 *        to obtain this information
 */
VAR(Dem_EventOccurTimeType,DEM_VAR)Dem_EventOccTime;

/**
 * @brief 	Record informations which are reported by Dem_DcmDisableDTCRecordUpdate.
 */
VAR(Dem_DTCRecordUpdateType,DEM_VAR) Dem_DTCRecordUpdateInfo;

/**
 * @brief Event queue,use for store events which is reported
 *        by Dem_ReportErrorStatus or Dem_SetEventAvailable
 */
VAR(Dem_EventBufferType,DEM_VAR) Dem_EventQueue[DEM_EVENT_QUEUE_SIZE];

#define DEM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dem_MemMap.h"
/*====================================================================================================*
 *                                      LOCAL FUNCTION PROTOTYPES
 *====================================================================================================*/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
#if(DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT)
extern FUNC(uint16,DEM_CODE) Dem_GetVehicleInfo
(
	Dem_VehicleDataType VehicleData
);

extern FUNC(boolean, DEM_CODE) Dem_CauseMILON
(
    Dem_EventIdType InternalId
);
#endif /* #if(DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT) */

#if(DEM_NVRAM_BLOCKID_NUM > 0)
STATIC FUNC(void, DEM_CODE)Dem_WriteToNvRAM
(
	void
);

STATIC FUNC(void, DEM_CODE) Dem_ReadFromNvRAM
(
	void
);
#endif /* #if(DEM_NVRAM_BLOCKID_NUM > 0) */

STATIC FUNC(boolean, DEM_CODE)Dem_ReplacementEventCheck
(
	P2CONST(Dem_EventParameterType,AUTOMATIC,DEM_CONST) pEventParameter
);

STATIC FUNC(void,DEM_CODE)Dem_InternalDebounceHandle
(
	Dem_EventIdType InternalEventId
);

#if(DEM_EXTERNALCSDATA_ELEMENT_NUM > 0)
STATIC FUNC(void, DEM_CODE)Dem_CaptureExternalCSDataElement
(
	P2VAR(uint8,AUTOMATIC,DEM_VAR) pBuffer,
	P2CONST(Dem_ExternalCSDataElementClassType,AUTOMATIC,DEM_CONST)pExterbalCSDataElementClass
);
#endif /* #if(DEM_EXTERNALCSDATA_ELEMENT_NUM > 0) */

#if((DEM_DID_CLASS_NUM > 0) && (DEM_FREEZE_FRAME_CLASS_NUM > 0))
STATIC FUNC(void, DEM_CODE)Dem_CaptureFFData
(
	Dem_EventIdType InternalEventId,
	uint16 FFIndex,
	P2VAR(uint8,AUTOMATIC,DEM_VAR) pBuffer
);
#endif /* #if((DEM_DID_CLASS_NUM > 0) && (DEM_FREEZE_FRAME_CLASS_NUM > 0)) */

#if(DEM_FREEZEFRAME_ENABLE == STD_ON)
STATIC FUNC(void, DEM_CODE)Dem_CaptureFreezeFrame
(
	Dem_EventIdType InternalEventId,
	P2VAR(uint8,AUTOMATIC,DEM_VAR) pBuffer
);
#endif /* #if(DEM_FREEZEFRAME_ENABLE == STD_ON) */

#if(DEM_EXTENDED_DATA_CLASS_NUM > 0)
STATIC FUNC(void, DEM_CODE)Dem_CaptureExtendedData
(
	Dem_EventIdType InternalEventId,
	P2VAR(uint8,AUTOMATIC,DEM_VAR) pBuffer
);
#endif /* #if(DEM_EXTENDED_DATA_CLASS_NUM > 0) */

#if(DEM_PID_CLASS_NUM >0)
STATIC FUNC(void, DEM_CODE)Dem_CapturePidClass
(
	Dem_EventIdType InternalEventId,
	P2VAR(uint8,AUTOMATIC,DEM_VAR) pBuffer
);
#endif /* #if(DEM_PID_CLASS_NUM >0) */

STATIC FUNC(Std_ReturnType, DEM_CODE) Dem_EventEnterQueue
(
	Dem_EventIdType InternalEventId,
	Dem_EventStatusType Status
);

STATIC FUNC(boolean, DEM_CODE) Dem_EventConditionCheck
(
	Dem_EventStatusType EventStatus,
	P2VAR(Dem_EventIdType,AUTOMATIC,DEM_VAR)pInternalEventId
);

STATIC FUNC(Std_ReturnType, DEM_CODE)Dem_InternalFDCCal
(
	Dem_EventIdType InternalEventId
);

#if(DEM_DTC_NUM > 0)
#if(DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_DISABLED)
STATIC FUNC(void, DEM_CODE) Dem_TriggerOnEventStatus
(
	Dem_EventIdType InternalEventId,
    Dem_UdsStatusByteType OldStatus,
    Dem_UdsStatusByteType NewStatus
);
#endif /* #if(DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_DISABLED) */

STATIC FUNC(void, DEM_CODE)Dem_InternalDataUpdata
(
	Dem_EventIdType InternalId
);

#if (DEM_AVAILABILITY_SUPPORT == DEM_EVENT_AVAILABILITY)
STATIC FUNC(void, DEM_CODE)Dem_DTCSuppressUpdata
(
	Dem_EventIdType InternalEventId
);
#endif /* #if (DEM_AVAILABILITY_SUPPORT == DEM_EVENT_AVAILABILITY) */

#if(DEM_RESSET_CONFIRMEDBIT_ONOVERFLOW == STD_OFF)
STATIC FUNC(void, DEM_CODE) Dem_AllocateAgingCounter
(
	Dem_DTCOriginType DTCOrigin
);
#endif /* #if(DEM_RESSET_CONFIRMEDBIT_ONOVERFLOW == STD_OFF) */

STATIC FUNC(boolean, DEM_CODE)Dem_EntryAllocateConditionCheck
(
	Dem_EventIdType InternalId
);

STATIC FUNC(void, DEM_CODE)Dem_TriggerEventMemory
(
	Dem_EventIdType InternalId,
	P2VAR(Dem_EventBufferType,AUTOMATIC,DEM_VAR)pBuffer
);


#if((DEM_FREEZE_FRAME_CLASS_NUM > 0)||(DEM_EXTENDED_DATA_CLASS_NUM > 0))
STATIC FUNC(boolean, DEM_CODE)Dem_TriggerConditionCheck
(
	Dem_EventIdType InternalId,
	uint8 TriggerType,
	boolean CaptureFF
);
#endif /* #if((DEM_FREEZE_FRAME_CLASS_NUM > 0)||(DEM_EXTENDED_DATA_CLASS_NUM > 0)) */

STATIC FUNC(void, DEM_CODE)Dem_TriggerCaptureData
(
	Dem_EventIdType InternalId,
	P2VAR(Dem_MemoryEntryType,AUTOMATIC,DEM_VAR) pEntry,
	P2VAR(Dem_EventBufferType,AUTOMATIC,DEM_VAR)pBuffer
);
#endif /* #if(DEM_DTC_NUM > 0) */

STATIC FUNC(void, DEM_CODE) Dem_DtcSuppressInit
(
	Dem_EventIdType internalId,
	P2VAR(uint8,AUTOMATIC,DEM_VAR)flag
);

#if(DEM_MAXNUMBER_PRESTORED_FF > 0)
STATIC FUNC(Std_ReturnType, DEM_CODE)Dem_PreStoreFFDeal
(
	Dem_EventIdType EventId
);
#endif /* #if(DEM_MAXNUMBER_PRESTORED_FF > 0) */

#if(DEM_INDICATOR_ATTRIBUTE_TOTAL_NUM > 0)
STATIC FUNC(void, DEM_CODE) Dem_EventHealingDeal
(
	void
);
#endif /* #if(DEM_INDICATOR_ATTRIBUTE_TOTAL_NUM > 0) */

#if(DEM_DTC_NUM > 0)
STATIC FUNC(void, DEM_CODE) Dem_EventAgingSubDeal
(
	Dem_MemoryEntryType* Entry,
	Dem_DTCOriginType MemDest,
	Dem_EventIdType InternalId
);

STATIC FUNC(void, DEM_CODE) Dem_EventAgingDeal
(
	Dem_EventIdType InternalId,
	uint8 OperationCycleId
);
#endif /* #if(DEM_DTC_NUM > 0) */

STATIC FUNC(void, DEM_CODE) Dem_CycleCounterDeal
(
	Dem_EventIdType InternalId
);

STATIC FUNC(void, DEM_CODE) Dem_StartOperationCycle
(
	uint8 OperationCycleId,
	boolean reStart
);

STATIC FUNC(void, DEM_CODE) Dem_EndOperationCycle
(
	uint8 OperationCycleId
);

#if((DEM_ENABLE_CONDITION_NUM > 0) || (DEM_STORAGE_CONDITION_GROUP_NUM > 0))
STATIC FUNC(boolean, DEM_CODE) Dem_ConditionIsFulFilled
(
    P2CONST(uint8,AUTOMATIC,DEM_VAR) pCondition,
    P2CONST(uint8,AUTOMATIC,DEM_VAR) pGroup,
    uint16 len
);
#endif /* #if((DEM_ENABLE_CONDITION_NUM > 0) || (DEM_STORAGE_CONDITION_GROUP_NUM > 0)) */

#if((DEM_DEBOUNCE_TIME_BASED_SUPPORT == STD_ON) && (DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0u))
STATIC FUNC(void, DEM_CODE)Dem_DebounceTimerDeal
(
	void
);

STATIC FUNC(void,DEM_CODE)Dem_EventDebounceCounterTimer
(
	P2CONST(Dem_EventBufferType,AUTOMATIC,DEM_VAR)pBuffer
);
#endif /* #if((DEM_DEBOUNCE_TIME_BASED_SUPPORT == STD_ON)
				&& (DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0u)) */

#if(DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM > 0)
STATIC FUNC(Dem_EventStatusType,DEM_CODE)Dem_EventDebounceCounterDeal
(
	P2CONST(Dem_EventBufferType,AUTOMATIC,DEM_VAR) pBuffer
);
#endif /* #if(DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM > 0) */


STATIC FUNC(Dem_EventStatusType,DEM_CODE)Dem_EventDebounceDeal
(
	P2CONST(Dem_EventBufferType,AUTOMATIC,DEM_VAR) pBuffer
);

STATIC FUNC(boolean, DEM_CODE)Dem_ReportStatusCheck
(
	Dem_EventIdType InternalId,
	P2CONST(Dem_EventBufferType,AUTOMATIC,DEM_VAR) pEventQueue
);

STATIC FUNC(void, DEM_CODE)Dem_EventQueueDeal
(
	void
);

STATIC FUNC(void, DEM_CODE)Dem_PendingDeal
(
	void
);

#if((DEM_DEBOUNCE_COUNTER_BASED_EVENT_NUM > 0) || (DEM_DEBOUNCE_TIME_BASED_EVENT_NUM > 0))
STATIC FUNC(boolean, DEM_CODE)Dem_RecoverFreezeCheck
(
	Dem_EventIdType IntId
);

STATIC FUNC(void, DEM_CODE)Dem_RecoverFreeze
(
	void
);
#endif /* #if((DEM_DEBOUNCE_COUNTER_BASED_EVENT_NUM > 0) || (DEM_DEBOUNCE_TIME_BASED_EVENT_NUM > 0)) */

#if(DEM_CALLBACK_INIT_MFOREFNC_TOTALNUM > 0)
STATIC FUNC(void, DEM_CODE)Dem_InitMonitorCbkDeal
(
	void
);
#endif /* #if(DEM_CALLBACK_INIT_MFOREFNC_TOTALNUM > 0) */


STATIC FUNC(void, DEM_CODE) Dem_EventMemoryInit
(
	void
);

#if((DEM_ENABLE_CONDITION_GROUP_NUM > 0) || (DEM_STORAGE_CONDITION_GROUP_NUM > 0))
STATIC FUNC(void, DEM_CODE) Dem_EventConditionInit
(
	Dem_EventIdType internalId
);
#endif /* #if((DEM_ENABLE_CONDITION_GROUP_NUM > 0) || (DEM_STORAGE_CONDITION_GROUP_NUM > 0)) */


STATIC FUNC(void, DEM_CODE) Dem_EventInfoInit
(
	void
);

#if(DEM_MAXNUMBER_PRESTORED_FF > 0)
STATIC FUNC(void, DEM_CODE) Dem_PreFFInit
(
	void
);

STATIC FUNC(void, DEM_CODE)Dem_ClearPreFF
(
	Dem_EventIdType EventId
);
#endif /* #if(DEM_MAXNUMBER_PRESTORED_FF > 0) */

#if(DEM_FREEZEFRAME_ENABLE == STD_ON)
STATIC FUNC(void, DEM_CODE)Dem_StoreFreezeFrame
(
	uint8 Trigger,
	P2CONST(uint8,AUTOMATIC,DEM_VAR) pFFData,
	P2VAR(Dem_MemoryEntryType,AUTOMATIC,DEM_VAR) pEntry
);

STATIC FUNC(void, DEM_CODE)Dem_UpdateEntryFFContent
(
	uint8 Trigger,
	P2VAR(Dem_EventBufferType,AUTOMATIC,DEM_VAR)pBuffer,
	P2VAR(Dem_MemoryEntryType,AUTOMATIC,DEM_VAR) pEntry
);
#endif /* #if(DEM_FREEZEFRAME_ENABLE == STD_ON) */

#if(DEM_EXTENDED_DATA_CLASS_NUM > 0)
STATIC FUNC(void, DEM_CODE)Dem_StoreExtRecord
(
	uint8 Trigger,
	P2CONST(Dem_EventBufferType,AUTOMATIC,DEM_VAR)pBuffer,
	P2VAR(Dem_MemoryEntryType,AUTOMATIC,DEM_VAR) pEntry
);

STATIC FUNC(void, DEM_CODE)Dem_UpdataEntryExtContent
(
	uint8 Trigger,
	P2VAR(Dem_EventBufferType,AUTOMATIC,DEM_VAR)pBuffer,
	P2VAR(Dem_MemoryEntryType,AUTOMATIC,DEM_VAR) pEntry
);
#endif /* #if(DEM_EXTENDED_DATA_CLASS_NUM > 0) */

#if(DEM_DTC_NUM > 0)
#if(DEM_EVENT_DISPLACEMENT_STRATEGY != DEM_DISPLACEMENT_NONE)
STATIC FUNC(Dem_MemoryEntryType*,DEM_CODE)Dem_EventDisplacement
(
	Dem_EventIdType InternalId,
	Dem_DTCOriginType DtcOrigin
);

STATIC FUNC(Dem_MemoryEntryType*,DEM_CODE)Dem_EventDisplacementHandle
(
	Dem_EventIdType InternalId,
	Dem_DTCOriginType DtcOrigin
);

#if((DEM_OBDEVENT_DISPLACEMENT == STD_ON) && (DEM_INDICATOR_NUM > 0))
STATIC FUNC(boolean,DEM_CODE)Dem_CheckMILByEvent
(
	Dem_EventIdType InternalId
);
#endif /* #if((DEM_OBDEVENT_DISPLACEMENT == STD_ON) && (DEM_INDICATOR_NUM > 0)) */
#endif /* #if(DEM_EVENT_DISPLACEMENT_STRATEGY != DEM_DISPLACEMENT_NONE) */

STATIC FUNC(Dem_MemoryEntryType*,DEM_CODE)Dem_AllocateNewEntry
(
	Dem_EventIdType InternalId,
	Dem_DTCOriginType DtcOrigin
);

STATIC FUNC(void,DEM_CODE)Dem_EventAlreadyStored
(
	Dem_EventIdType InternalId,
	Dem_DTCOriginType DtcOrigin,
	P2VAR(Dem_MemoryEntryType,AUTOMATIC,DEM_VAR) pEntry
);

STATIC FUNC(Dem_MemoryEntryType*,DEM_CODE)Dem_EntryAllocate
(
	Dem_EventIdType InternalId,
	Dem_DTCOriginType DtcOrigin
);
#endif /* #if(DEM_DTC_NUM > 0) */

STATIC FUNC(void, DEM_CODE)Dem_EventConfirmedDeal
(
	Dem_EventIdType InternalId
);

STATIC FUNC(void, DEM_CODE)Dem_FailedEventHandle
(
	Dem_EventIdType InternalId
);

STATIC FUNC(void, DEM_CODE)Dem_PassedEventHandle
(
	Dem_EventIdType InternalId
);

#if(DEM_INDICATOR_ATTRIBUTE_TOTAL_NUM > 0)
STATIC FUNC(boolean, DEM_CODE)Dem_CheckWIROn
(
	Dem_EventIdType InternalId
);
#endif /* #if(DEM_INDICATOR_ATTRIBUTE_TOTAL_NUM > 0) */

#if(DEM_J1939_SUPPORT == STD_ON)
STATIC FUNC(void, DEM_CODE)Dem_CaptureJ1939FFData
(
	Dem_EventIdType InternalEventId,
	uint16 FFIndex,
	P2VAR(uint8,AUTOMATIC,DEM_VAR) pBuffer
);
#endif /* #if(DEM_J1939_SUPPORT == STD_ON) */

#if((DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU) || (DEM_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
STATIC FUNC(boolean, DEM_CODE) Dem_IsWarmUpOpCyc
(
	uint8 OperationCycleId
);

STATIC FUNC(void, DEM_CODE)Dem_MemoryTransfer
(
	Dem_MemoryEntryType* pDestEntry,
	Dem_MemoryEntryType* pSrcEntry
);
#endif /* #if(((DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU) || (DEM_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU)) */

#if(DEM_COMPONENT_NUM > 0)
STATIC FUNC(void, DEM_CODE)Dem_ComponentHandle
(
	Dem_EventIdType	InternalId
);
#endif

#if(DEM_DTC_NUM > 0)
STATIC FUNC(void, DEM_CODE)Dem_SetCombineDtcStatus
(
	Dem_EventIdType InternalEventId
);
#endif /* #if(DEM_DTC_NUM > 0) */
/*====================================================================================================*
 *                                           LOCAL FUNCTIONS
 *====================================================================================================*/
#if(DEM_DTC_NUM > 0)
/*
 * @brief        	Dem_SetCombineDtcStatus
 * @details			Update combine dtc status bits if one dtc relate to multiple events.
 *
 * @param[in]       InternalEventId:  Internal event identifier which value is equal to EventId - 1,
 *                  used to retrieve configurations.
 */
STATIC FUNC(void, DEM_CODE)Dem_SetCombineDtcStatus
(
	Dem_EventIdType InternalEventId
)
{
#if(DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_DISABLED)
	uint8 u8Flag = 0u;
#endif /* #if(DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_DISABLED) */
	uint16 u16Loop = 0u;
	Dem_UdsStatusByteType  newDtcStatus = 0u;
	uint16 u16DtcRef = Dem_ConfigPtr->DemEventParameter[InternalEventId].DemDTCRef;

	if(u16DtcRef != 0xFFFFu)
	{
		do
		{
			if(Dem_ConfigPtr->DemEventParameter[u16Loop].DemDTCRef == u16DtcRef)
			{
				/**
				 * @req [SWS_Dem_00441] bit0 - bit7 or-operation
				 */
#if(DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_DISABLED)
				newDtcStatus |= Dem_EventUDSBitStatus[u16Loop];
				u8Flag++;
#else
				newDtcStatus = Dem_EventUDSBitStatus[u16Loop];
				break;
#endif /* #if(DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_DISABLED) */
			}
			u16Loop++;
		}while(u16Loop < DEM_EVENT_PARAMETER_NUM);

#if(DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_DISABLED)
		if(u8Flag > 1u)
		{
			/* bit4 calculation: bit4 & (!bit5) */
			newDtcStatus &= (Dem_UdsStatusByteType)(~((newDtcStatus & DEM_UDS_STATUS_TFSLC) >> 1u));

			/* bit6 calculation: bit4 & (!bit1) */
			newDtcStatus &= (Dem_UdsStatusByteType)(~(Dem_UdsStatusByteType)((newDtcStatus & DEM_UDS_STATUS_TFTOC) << 5u));
		}
#endif /* #if(DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_DISABLED) */
		if(newDtcStatus != Dem_DtcUdsStatus[u16DtcRef])
		{
#if(DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_DISABLED)
			/**
			 * @req [SWS_Dem_01050] Each time the status of an event is updated, the combined
			 *      DTC status shall be calculated. If the combined DTC status has changed the
			 *      relevant call-backs shall be invoked
			 */
			Dem_TriggerOnEventStatus(InternalEventId,Dem_DtcUdsStatus[u16DtcRef],newDtcStatus);
#endif /* #if(DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_DISABLED) */
			Dem_DtcUdsStatus[u16DtcRef] = newDtcStatus;
		}
	}
}
#endif /* #if(DEM_DTC_NUM > 0) */

/*
 * @brief        	Dem_ReplacementEventCheck
 * @details			Check event is a replacement event or not.
 *
 * @param[in]    	pEventParameter: Configure parameter of relate event.
 *
 * @return          Result of this check.
 * @retval          TRUE: Relate event is a replacement event.
 * @retval          FALSE: Relate event is not a replacement event.
 */
STATIC FUNC(boolean, DEM_CODE)Dem_ReplacementEventCheck
(
	P2CONST(Dem_EventParameterType,AUTOMATIC,DEM_CONST) pEventParameter
)
{

	boolean retVal = (boolean)FALSE;
	/**
	 * @req [SWS_Dem_01090] constraints for the replacement event:
	 *      must not be mapped to an storage condition
	 * 	    must not be configured to use debouncing
	 * 		must not have an InitMForE callback/ clearEventAllowed
	 * 		must not be configured for enableConditions
	 * 		must be configured as DEM_EVENT_KIND_BSW
	 */
#if(DEM_ENABLE_CONDITION_GROUP_NUM > 0)
	if(pEventParameter->DemEnableConditionGroupRef == 0xFFu)
#endif /* #if(DEM_ENABLE_CONDITION_GROUP_NUM > 0) */
	{
#if(DEM_STORAGE_CONDITION_GROUP_NUM > 0)
		if(pEventParameter->DemStorageConditionGroupRef == 0xFFu)
#endif /* #if(DEM_STORAGE_CONDITION_GROUP_NUM > 0) */
		{
#if(DEM_CALLBACK_CLEAR_EVENT_ALLOWED_NUM > 0)
			if(pEventParameter->DemCallbackClearEventAllowed == NULL_PTR)
#endif /* #if(DEM_CALLBACK_CLEAR_EVENT_ALLOWED_NUM > 0) */
			{
#if(DEM_CALLBACK_INIT_MFOREFNC_TOTALNUM > 0)
				if(pEventParameter->DemCallbackInitMForE == NULL_PTR)
#endif /* #if(DEM_CALLBACK_INIT_MFOREFNC_TOTALNUM > 0) */
				{
					if((pEventParameter->DemDebounceAlgorithmRef == 0xFFFFu)\
							&&(pEventParameter->DemEventKind == DEM_EVENT_KIND_BSW))
					{
						retVal = (boolean)TRUE;
					}
				}
			}
		}
	}
	return retVal;
}

/*
 * @brief        	Dem_InternalDebounceHandle
 * @details			Handle reset or freeze operation of debounce timer and counter.
 *
 * @param[in]    	InternalEventId: Internal event identifier which value is equal to EventId - 1,
 *                  used to retrieve configurations.
 */
STATIC FUNC(void,DEM_CODE)Dem_InternalDebounceHandle
(
	Dem_EventIdType InternalEventId
)
{
#if((DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0) || (DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM > 0))
	const Dem_EventParameterType* pEventParameter = \
			&(Dem_ConfigPtr->DemEventParameter[InternalEventId]);
#endif /* #if((DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0) || (DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM > 0)) */

#if(DEM_DEBOUNCE_TIME_BASED_SUPPORT == STD_ON)
#if(DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0)
	if((pEventParameter->DemDebounceAlgorithmClassType == DEM_DEBOUNCE_TIME_BASE)\
			&&(pEventParameter->DemDebounceAlgorithmRef < DEM_DEBOUNCE_TIME_BASE_CLASS_NUM)\
			&&(pEventParameter->DemDebounceInfoIndex < DEM_DEBOUNCE_TIME_BASED_EVENT_NUM))
	{
		if(Dem_ConfigPtr->DemDebounceTimeBaseClass[pEventParameter->DemDebounceInfoIndex].\
				DemDebounceBehavior == DEM_DEBOUNCE_FREEZE)
		{
			/* set timer freeze flag */
			DemInternalDebounceTimer[pEventParameter->DemDebounceInfoIndex].isFreeze = (boolean)TRUE;
		}
		else
		{
			/* reset timer parameters */
			DemInternalDebounceTimer[pEventParameter->DemDebounceInfoIndex].timeout = 0u;
			DemInternalDebounceTimer[pEventParameter->DemDebounceInfoIndex].triggered = (boolean)FALSE;
			DemInternalDebounceTimer[pEventParameter->DemDebounceInfoIndex].status = \
					DEM_EVENT_STATUS_PREPASSED;
		}
	}
#endif /* #if(DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0) */
#endif /* #if(DEM_DEBOUNCE_TIME_BASED_SUPPORT == STD_ON) */

#if(DEM_DEBOUNCE_COUNTER_BASED_SUPPORT == STD_ON)
#if(DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM > 0)
	if((pEventParameter->DemDebounceAlgorithmClassType == DEM_DEBOUNCE_COUNTER_BASED)\
			&&(pEventParameter->DemDebounceAlgorithmRef < DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM)\
			&&(pEventParameter->DemDebounceInfoIndex < DEM_DEBOUNCE_COUNTER_BASED_EVENT_NUM))
	{
		if(Dem_ConfigPtr->DemDebounceCounterBasedClass[pEventParameter->DemDebounceInfoIndex].\
				DemDebounceBehavior == DEM_DEBOUNCE_FREEZE)
		{
			Dem_InternalDebounceCounter[pEventParameter->DemDebounceInfoIndex].isFreeze = (boolean)TRUE;
		}
		else
		{
			/* reset counter */
			Dem_InternalDebounceCounter[pEventParameter->DemDebounceInfoIndex].counter = 0;
		}
	}
#endif /* #if(DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM > 0) */
#endif /* #if(DEM_DEBOUNCE_COUNTER_BASED_SUPPORT == STD_ON) */
}


#if(DEM_EXTERNALCSDATA_ELEMENT_NUM > 0)
/*
 * @brief        	Dem_CaptureExternalCSDataElement
 * @details			Capture external CS data element.
 *
 * @param[in]    	pExterbalCSDataElementClass: Configuration of DemExternalCSDataElementClass.
 *
 * @param[out]      pBuffer: Buffer to store the freeze frame data.
 */
STATIC FUNC(void, DEM_CODE)Dem_CaptureExternalCSDataElement
(
	P2VAR(uint8,AUTOMATIC,DEM_VAR) pBuffer,
	P2CONST(Dem_ExternalCSDataElementClassType,AUTOMATIC,DEM_CONST)pExterbalCSDataElementClass
)
{
	uint8 u8Loop = 0u;
	boolean error = (boolean)FALSE;
	if(pExterbalCSDataElementClass->DemDataElementUsePort == (boolean)FALSE)
	{
		if(pExterbalCSDataElementClass->DemDataElementReadFnc == NULL_PTR)
		{
			error = (boolean)TRUE;
		}
		else
		{
			if(pExterbalCSDataElementClass->DemDataElementReadFnc(pBuffer) != (Std_ReturnType)E_OK)
			{
				error = (boolean)TRUE;
			}
		}

		if(error == (boolean)TRUE)
		{
			do
			{
				*pBuffer = 0xFFu;
				pBuffer++;
				u8Loop++;
			}while(u8Loop < pExterbalCSDataElementClass->DemDataElementDataSize);

#if (DEM_DEV_ERROR_DETECT == STD_ON)
			/**
			 * @req [SWS_Dem_00463] If the SW-C or BSW module cannot not provide the requested data
			 *      (ReadDataElement returns other than E_OK), the Dem shall fill the missing data
			 *      with the padding value 0xFF,reports the development error DEM_E_NODATAAVAILABLE
			 *      to the Det and continues its normal operation.
			 */
			DEM_DET_ERROR_REPORT(DEM_SID_MAINFUNCTION, DEM_E_NODATAAVAILABLE);
#endif /* #if (DEM_DEV_ERROR_DETECT == STD_ON) */
		}
	}
	else
	{
		/* a R-Port is generated, to obtain the data element */
	}
}
#endif /* #if(DEM_EXTERNALCSDATA_ELEMENT_NUM > 0) */

#if(DEM_INTERNAL_DATA_ELEMENT_NUM > 0)
/*
 * @brief        	Dem_CaptureInternalDataElement
 * @details			Capture internal data element.
 *
 * @param[in]    	pInternalDataElementClass: Configuration of DemInternalDataElementClass.
 * @param[in]       InternalEventId: Internal event identifier which value is equal to EventId - 1,
 *                  used to retrieve configurations.
 *
 * @param[out]      pBuffer: Buffer to store the freeze frame data.
 */
FUNC(void, DEM_CODE)Dem_CaptureInternalDataElement
(
	Dem_EventIdType InternalEventId,
	P2VAR(uint8,AUTOMATIC,DEM_VAR) pBuffer,
	P2CONST(Dem_InternalDataElementClassType,AUTOMATIC,DEM_CONST)pInternalDataElementClass
)
{
#if(DEM_DTC_NUM > 0)
	uint16 u16DtcRef = Dem_ConfigPtr->DemEventParameter[InternalEventId].DemDTCRef;
#endif /* #if(DEM_DTC_NUM > 0) */

	/**
	 * @req [SWS_Dem_00817] Internal data elements (refer to DemInternalDataElementClass)
            shall not be stored, but the current value shall be used instead.
	 */
	const Dem_InternalDataElementType internalDataElement = \
			pInternalDataElementClass->DemInternalDataElement;

	if(internalDataElement == DEM_AGINGCTR_DOWNCNT)
	{
		/**
		 * @req [SWS_Dem_00472] If the configuration parameter DemInternalDataElement is set
		 *      to DEM_AGINGCTR_UPCNT or to DEM_AGINGCTR_DOWNCNT,then the Dem internal value
		 *      of the aging counter shall be mapped to the respective data element.
		 */
		*pBuffer = Dem_EventInternalData[InternalEventId].agingDownCnt;
	}
	else if(internalDataElement == DEM_AGINGCTR_UPCNT)
	{
		/**
		 * @req [SWS_Dem_00472] If the configuration parameter DemInternalDataElement is set
		 *      to DEM_AGINGCTR_UPCNT or to DEM_AGINGCTR_DOWNCNT,then the Dem internal value
		 *      of the aging counter shall be mapped to the respective data element.
		 */
		*pBuffer = Dem_EventInternalData[InternalEventId].agingUpCnt;
	}
	else if(internalDataElement == DEM_CURRENT_FDC)
	{
		/**
		 * @req [SWS_Dem_01084] If the configuration parameter DemInternalDataElement is set
		 *      to DEM_CURRENT_FDC,then the Dem-internal value of the current fault detection
		 *      counter shall be mapped to the respective data element with the following value
		 *      translation: [0..127]->[0x00..0x7F] and [-1..-128]->[0xFF..0x80].
		 */
		*pBuffer = (uint8)Dem_EventInternalData[InternalEventId].currentFDC;
	}
	else if(internalDataElement == DEM_CYCLES_SINCE_FIRST_FAILED)
	{
		/**
		 * @req [SWS_Dem_00821]  If the configuration parameter DemInternalDataElement is set
		 *      to DEM_CYCLES_SINCE_FIRST_FAILED, then the Dem-internal value of the operation
		 *      cycle counter since first failed shall be mapped to the respective data element.
		 */
		*pBuffer = Dem_EventInternalData[InternalEventId].cyclesSinceFirstFailed;
	}
	else if(internalDataElement == DEM_CYCLES_SINCE_LAST_FAILED)
	{
		/**
		 * @req [SWS_Dem_00820] If the configuration parameter DemInternalDataElement is set
		 *      to DEM_CYCLES_SINCE_LAST_FAILED, then the Dem-internal value of the operation
		 *      cycle counter since last failed shall be mapped to the respective data element.
		 */
		*pBuffer = Dem_EventInternalData[InternalEventId].cyclesSinceLastFailed;
	}
	else if(internalDataElement == DEM_FAILED_CYCLES)
	{
		/**
		 * @req [SWS_Dem_00822] If the configuration parameter DemInternalDataElement is set
		 *      to DEM_FAILED_CYCLES,then the Dem-internal value of the failed operation cycle
		 *      counter shall be mapped to the respective data element.
		 */
		*pBuffer = Dem_EventInternalData[InternalEventId].failedCycles;
	}
	else if(internalDataElement == DEM_MAX_FDC_DURING_CURRENT_CYCLE)
	{
		/**
		 * @req [SWS_Dem_00819] If the configuration parameter DemInternalDataElement is set
		 *      to DEM_MAX_FDC_DURING_CURRENT_CYCLE,then the Dem-internal value of the maximum
		 *      Fault Detection Counter during current operation cycle shall be mapped to the
		 *      respective data element.
		 */
#if(DEM_DTC_NUM > 0)
		if (u16DtcRef != 0xFFFFu)
		{
			*pBuffer = Dem_MaxFDCDurCurCycles[u16DtcRef];
		}
		else
		{
			*pBuffer = 0u;
		}
#else
		*pBuffer = 0u;
#endif /* #if(DEM_DTC_NUM > 0) */
	}
	else if(internalDataElement == DEM_MAX_FDC_SINCE_LAST_CLEAR)
	{
		/**
		 * @req [SWS_Dem_00818]  If the configuration parameter DemInternalDataElement is set
		 *      to DEM_MAX_FDC_SINCE_LAST_CLEAR, then the Dem-internal value of the maximum
		 *      Fault Detection Counter sincle last clear (refer to chapter 7.6.3.7) shall be
		 *      mapped to the respective data element.
		 */
#if(DEM_DTC_NUM > 0)
		if (u16DtcRef != 0xFFFFu)
		{
			*pBuffer = Dem_MaxFDCSinceLastClear[u16DtcRef];
		}
		else
		{
			*pBuffer = 0u;
		}
#else
		*pBuffer = 0;
#endif /* #if(DEM_DTC_NUM > 0) */
	}
	else if(internalDataElement == DEM_OCCCTR)
	{
		/**
		 * @req [SWS_Dem_00471] If the configuration parameter DemInternalDataElement is set
		 *      to DEM_OCCCTR,then the Dem-internal value of the occurrence counter shall be
		 *      mapped to the respective data element.
		 */
		*pBuffer = Dem_EventInternalData[InternalEventId].occurCnt;
	}
	else if(internalDataElement == DEM_OVFLIND)
	{
		/**
		 * @req [SWS_Dem_00473] If the configuration parameter DemInternalDataElement is set
		 *      to DEM_OVFLIND,then the Dem-internal value of the overflow indication shall
		 *      be mapped to the respective data element as boolean.
		 */
		*pBuffer = Dem_EventInternalData[InternalEventId].overflowIndication;
	}
	else if(internalDataElement == DEM_SIGNIFICANCE)
	{
		/**
		 * @req [SWS_Dem_00592] If the configuration parameter DemInternalDataElement is set to
		 *      DEM_SIGNIFICANCE, then the (static) Dem-internal value of the DTC significance
		 *      shall be mapped to the respective data element with 0 = OCCURRENCE and 1 = FAULT
		 */
		*pBuffer = Dem_EventInternalData[InternalEventId].significance;
	}
	else
	{
#if (DEM_DEV_ERROR_DETECT == STD_ON)
		DEM_DET_ERROR_REPORT(DEM_SID_MAINFUNCTION, DEM_E_NODATAAVAILABLE);
#endif /* #if (DEM_DEV_ERROR_DETECT == STD_ON) */
	}
}
#endif /* #if(DEM_INTERNAL_DATA_ELEMENT_NUM > 0) */

#if((DEM_DID_CLASS_NUM > 0) && (DEM_FREEZE_FRAME_CLASS_NUM > 0))
/*
 * @brief        	Dem_CaptureFFData
 * @details			Capture UDS or WWH-OBD freeze frame data to event queue when DemEnvironment-
 *                  DataCapture is equal to DEM_CAPTURE_SYNCHRONOUS_TO_REPORTING.
 *
 * @param[in]    	InternalEventId: Internal event identifier which value is equal to EventId - 1,
 *                  used to retrieve configurations.
 * @param[in]       FFIndex: Index of DemFreezeFrameClass.
 *
 * @param[out]      pBuffer: Buffer to store the freeze frame data.
 */
STATIC FUNC(void, DEM_CODE)Dem_CaptureFFData
(
	Dem_EventIdType InternalEventId,
	uint16 FFIndex,
	P2VAR(uint8,AUTOMATIC,DEM_VAR) pBuffer
)
{
	uint16 u16Loop = 0u;
	uint16 u16DataLoop = 0u;
	uint16 u16Offset = 0u;
	const Dem_FreezeFrameClassType* pFFClass = Dem_General.DemFreezeFrameClass;
	const uint16* pDidRef = pFFClass[FFIndex].DemDidClassRefStartIndex;
	const Dem_DidClassType* pDidClass;
	const uint16* pDataElementClassRef;

	do
	{
		u16Loop++;
		pDidClass = &(Dem_General.DemDidClass[(*pDidRef)]);
		pDataElementClassRef = pDidClass->DemDidDataElementClassRefStartIndex;
		do
		{
			u16DataLoop++;
#if(DEM_EXTERNALCSDATA_ELEMENT_NUM > 0)
			if(Dem_General.DemDataElementClass[*pDataElementClassRef].DemExternalCSDataElementClass \
					!= NULL_PTR)
			{
				Dem_CaptureExternalCSDataElement(
						(&pBuffer[u16Offset]),
						(Dem_General.DemDataElementClass[*pDataElementClassRef].\
						DemExternalCSDataElementClass));

				u16Offset += Dem_General.DemDataElementClass[*pDataElementClassRef].\
						DemExternalCSDataElementClass->DemDataElementDataSize;
			}
			else
#endif /* #if(DEM_EXTERNALCSDATA_ELEMENT_NUM > 0) */
			{
#if(DEM_EXTERNALSRDATA_ELEMENT_NUM > 0)
				 if(Dem_General.DemDataElementClass[pDataElementClassRef].DemExternalSRDataElementClass\
						!= NULL_PTR)
				 {
					 Dem_CaptureExternalSRDataElement();
				 }
				 else
#endif /* #if(DEM_EXTERNALSRDATA_ELEMENT_NUM > 0) */
				 {
#if(DEM_INTERNAL_DATA_ELEMENT_NUM > 0)
					 if(Dem_General.DemDataElementClass[*pDataElementClassRef].\
							 DemInternalDataElementClass != NULL_PTR)
					 {
						 Dem_CaptureInternalDataElement(
								 InternalEventId,
								 (&pBuffer[u16Offset]),
								 (Dem_General.DemDataElementClass[*pDataElementClassRef].\
								 DemInternalDataElementClass));

						 u16Offset += Dem_General.DemDataElementClass[*pDataElementClassRef].\
								 DemInternalDataElementClass->DemDataElementDataSize;
					 }
#endif /* #if(DEM_INTERNAL_DATA_ELEMENT_NUM > 0) */
				 }
			}
			pDataElementClassRef++;
		}while(u16DataLoop < pDidClass->DemDidDataElementClassRefNum);

		pDidRef++;
	}while(u16Loop < pFFClass[FFIndex].DemDidClassRefNum);
}
#endif /* #if((DEM_DID_CLASS_NUM > 0) && (DEM_FREEZE_FRAME_CLASS_NUM > 0)) */

#if(DEM_FREEZEFRAME_ENABLE == STD_ON)

#if(DEM_J1939_SUPPORT == STD_ON)
STATIC FUNC(void, DEM_CODE)Dem_CaptureJ1939FFData
(
	Dem_EventIdType InternalEventId,
	uint16 FFIndex,
	P2VAR(uint8,AUTOMATIC,DEM_VAR) pBuffer
)
{
	const Dem_J1939FreezeFrameType* pJ1939FF = &(Dem_General.DemGeneralJ1939->\
			DemJ1939FreezeFrameClasses[FFIndex]);

	const uint8* pSPNClassStart = pJ1939FF->SPNClassStart;

	const Dem_SPNClassType* pSPNClass;

	uint8 u8Loop = 0u;

	uint16 u16Offset = 0u;

	do
	{
		pSPNClass = &(Dem_General.DemGeneralJ1939->DemSPNClasses[*pSPNClassStart]);

#if(DEM_EXTERNALCSDATA_ELEMENT_NUM > 0)
		if(Dem_General.DemDataElementClass[pSPNClass->DemSPNDataElementClassRef].\
				DemExternalCSDataElementClass != NULL_PTR)
		{
			Dem_CaptureExternalCSDataElement(
					(pBuffer + u16Offset),
					(Dem_General.DemDataElementClass[pSPNClass->DemSPNDataElementClassRef].\
					DemExternalCSDataElementClass));

			u16Offset += Dem_General.DemDataElementClass[pSPNClass->DemSPNDataElementClassRef].\
					DemExternalCSDataElementClass->DemDataElementDataSize;
		}
		else
#endif /* #if(DEM_EXTERNALCSDATA_ELEMENT_NUM > 0) */
		{
#if(DEM_EXTERNALSRDATA_ELEMENT_NUM > 0)
			 if(Dem_General.DemDataElementClass[pSPNClass->DemSPNDataElementClassRef].\
					 DemExternalSRDataElementClass != NULL_PTR)
			 {
				 Dem_CaptureExternalSRDataElement();
			 }
			 else
#endif /* #if(DEM_EXTERNALSRDATA_ELEMENT_NUM > 0) */
			 {
#if(DEM_INTERNAL_DATA_ELEMENT_NUM > 0)
				 Dem_CaptureInternalDataElement(
						 InternalEventId,
						 (pBuffer + u16Offset),
						 (Dem_General.DemDataElementClass[pSPNClass->DemSPNDataElementClassRef].\
						 DemInternalDataElementClass));

				 u16Offset += Dem_General.DemDataElementClass[pSPNClass->DemSPNDataElementClassRef].\
						 DemInternalDataElementClass->DemDataElementDataSize;
#endif /* #if(DEM_INTERNAL_DATA_ELEMENT_NUM > 0) */
			 }
		}
		pSPNClassStart++;
		u8Loop++;
	}while(u8Loop < pJ1939FF->SPNClassRefNum);
}
#endif /* #if(DEM_J1939_SUPPORT == STD_ON) */

/*
 * @brief        	Dem_CaptureFreezeFrame
 * @details			Capture freeze frame data to event queue when DemEnvironmentDataCapture is
 *                  equal to DEM_CAPTURE_SYNCHRONOUS_TO_REPORTING.
 *
 * @param[in]    	InternalEventId: Internal event identifier which value is equal to EventId - 1,
 *                  used to retrieve configurations.
 *
 * @param[out]      pBuffer: Buffer to store the freeze frame data.
 */
STATIC FUNC(void, DEM_CODE)Dem_CaptureFreezeFrame
(
	Dem_EventIdType InternalEventId,
	P2VAR(uint8,AUTOMATIC,DEM_VAR) pBuffer
)
{
	uint16 u16DTCAttrRef;
	uint16 u16FFRef;
	uint16 u16DtcRef;

	u16DtcRef = Dem_ConfigPtr->DemEventParameter[InternalEventId].DemDTCRef;

	if(u16DtcRef != 0xFFFFu)
	{
		u16DTCAttrRef = Dem_ConfigPtr->DemDTC[u16DtcRef].DemDTCAttributesRef;

#if((DEM_DID_CLASS_NUM > 0) && (DEM_FREEZE_FRAME_CLASS_NUM > 0))
		u16FFRef = Dem_ConfigPtr->DemDTCAttributes[u16DTCAttrRef].DemFreezeFrameClassRef;

		if(u16FFRef != 0xFFFFu)
		{
			/* capture general freeze frame data */
			Dem_CaptureFFData(InternalEventId,u16FFRef,pBuffer);
		}
		else
		{
#if(DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT)
			u16FFRef = Dem_ConfigPtr->DemDTCAttributes[u16DTCAttrRef].DemWWHOBDFreezeFrameClassRef;
			if(u16FFRef != 0xFFu)
			{
				/* capture WWH-OBD freeze frame data */
				Dem_CaptureFFData(InternalEventId,u16FFRef,pBuffer);
			}
			else
#endif /* #if(DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT) */
#endif /* #if((DEM_DID_CLASS_NUM > 0) && (DEM_FREEZE_FRAME_CLASS_NUM > 0)) */
			{
#if(DEM_J1939_SUPPORT == STD_ON)
				u16FFRef = Dem_ConfigPtr->DemDTCAttributes[u16DTCAttrRef].DemJ1939FreezeFrameClassRef;
				if(u16FFRef != 0xFFu)
				{
					/* capture J1939 freeze frame data */
					Dem_CaptureJ1939FFData(InternalEventId,u16FFRef,pBuffer);
				}
				else
				{
					u16FFRef = Dem_ConfigPtr->DemDTCAttributes[u16DTCAttrRef].\
							DemJ1939ExpandedFreezeFrameClassRef;
					if(u16FFRef != 0xFFu)
					{
						/* capture J1939 freeze frame data */
						Dem_CaptureJ1939FFData(InternalEventId,u16FFRef,pBuffer);
					}
				}
#endif /* #if(DEM_J1939_SUPPORT == STD_ON) */
			}
#if((DEM_DID_CLASS_NUM > 0) && (DEM_FREEZE_FRAME_CLASS_NUM > 0))
		}
#endif /* #if((DEM_DID_CLASS_NUM > 0) && (DEM_FREEZE_FRAME_CLASS_NUM > 0)) */
	}
}
#endif /* #if(DEM_FREEZEFRAME_ENABLE == STD_ON) */

#if(DEM_PID_CLASS_NUM > 0)
/*
 * @brief        	Dem_CapturePidClass
 * @details			Capture PidClass data to event queue when DemEnvironmentDataCapture is
 *                  equal to DEM_CAPTURE_SYNCHRONOUS_TO_REPORTING.
 *
 * @param[in]      pBuffer: Buffer to store the PidClass data.
 */
STATIC FUNC(void, DEM_CODE)Dem_CapturePidClass
(
	Dem_EventIdType InternalEventId,
	P2VAR(uint8,AUTOMATIC,DEM_VAR) pBuffer
)
{
	uint8 	u8ClassLoop		= 0u;
	uint8 	u8ElementLoop	= 0u;
	uint16	u16Offset		= 0u;
	const Dem_PidClassType* pPidClass = Dem_ConfigPtr->DemPidClass;
	const Dem_PidDataElementType* pPidDataElementRef = NULL_PTR;

	while(u8ClassLoop < DEM_PID_CLASS_NUM)
	{
		pPidDataElementRef = pPidClass[u8ClassLoop].DemPidDataElementRef;
		for(u8ElementLoop = 0u;\
			u8ElementLoop < pPidClass[u8ClassLoop].DemPidDataElementClassRefNum;\
			u8ElementLoop++)
		{
#if(DEM_EXTERNALCSDATA_ELEMENT_NUM > 0)
			if(pPidDataElementRef->DemPidDataElementClassRef->DemExternalCSDataElementClass\
					!= NULL_PTR)
			{
				Dem_CaptureExternalCSDataElement(\
						(pBuffer + u16Offset),\
						(pPidDataElementRef->DemPidDataElementClassRef->\
						 DemExternalCSDataElementClass));

				pPidDataElementRef++;
				u16Offset += pPidClass[u8ClassLoop].DemPidDataElementRef[u8ElementLoop].\
								DemPidDataElementClassRefSize;
				continue;
			}
#endif /* #if(DEM_EXTERNALCSDATA_ELEMENT_NUM > 0) */
#if(DEM_INTERNAL_DATA_ELEMENT_NUM > 0)
			if(pPidDataElementRef->DemPidDataElementClassRef->DemInternalDataElementClass\
					!= NULL_PTR)
			{
				Dem_CaptureInternalDataElement(\
						(InternalEventId),\
						(pBuffer + u16Offset),\
						(pPidDataElementRef->DemPidDataElementClassRef->\
						 DemInternalDataElementClass));

				pPidDataElementRef++;
				u16Offset += pPidClass[u8ClassLoop].DemPidDataElementRef[u8ElementLoop].\
								DemPidDataElementClassRefSize;
				continue;
			}
#endif /* #if(DEM_INTERNAL_DATA_ELEMENT_NUM > 0) */
#if(DEM_EXTERNALSRDATA_ELEMENT_NUM > 0)
			if(pPidClass[u8ClassLoop].DemPidDataElementRef[u8ElementLoop].\
					DemPidDataElementClassRef->DemExternalSRDataElementClass != NULL_PTR)
			{
				Dem_CaptureExternalSRDataElement();
				continue;
			}
#endif /* #if(DEM_EXTERNALSRDATA_ELEMENT_NUM > 0) */
		}
		u8ClassLoop++;
	}
}
#endif /* #if(DEM_PID_CLASS_NUM > 0) */

#if(DEM_EXTENDED_DATA_CLASS_NUM > 0)
/*
 * @brief        	Dem_CaptureExtendedData
 * @details			Capture extended data to event queue when DemEnvironmentDataCapture is
 *                  equal to DEM_CAPTURE_SYNCHRONOUS_TO_REPORTING.
 *
 * @param[in]    	InternalEventId: Internal event identifier which value is equal to EventId - 1,
 *                  used to retrieve configurations.
 *
 * @param[out]      pBuffer: Buffer to store the freeze frame data.
 */
STATIC FUNC(void, DEM_CODE)Dem_CaptureExtendedData
(
	Dem_EventIdType InternalEventId,
	P2VAR(uint8,AUTOMATIC,DEM_VAR) pBuffer
)
{
	uint8  u8Loop	       = 0u;
	uint8  u8ElementLoop   = 0u;
	uint16 u16Offset       = 0u;
	uint8  u8RecordNum;
	uint8  u8ElementRefNum;
	uint16 u16DTCAttrRef;
	uint16 u16ExtRef;
	uint16 u16DtcRef;
	const uint8* pRecordClassIndex;
	const uint16* pElementClassIndex;
	const Dem_ExtendedDataRecordClassType* 	pExtDataRecClass;
	const Dem_DataElementClassType* pElementClass;

	u16DtcRef = Dem_ConfigPtr->DemEventParameter[InternalEventId].DemDTCRef;

	if(u16DtcRef != 0xFFFFu)
	{
		u16DTCAttrRef = Dem_ConfigPtr->DemDTC[u16DtcRef].DemDTCAttributesRef;
		u16ExtRef = Dem_ConfigPtr->DemDTCAttributes[u16DTCAttrRef].DemExtendedDataClassRef;
		if(u16ExtRef != 0xFFFFu)
		{
			u8RecordNum = Dem_General.DemExtendedDataClass[u16ExtRef].DemExtendedDataRecordClassRefNum;

			pRecordClassIndex = Dem_General.DemExtendedDataClass[u16ExtRef].\
					DemExtendedDataRecordClassRefStartIndex;

			do
			{
				u8Loop++;
				pExtDataRecClass = &(Dem_General.DemExtendedDataRecordClass[*pRecordClassIndex]);
				u8ElementRefNum    = pExtDataRecClass->DemDataElementClassRefNum;
				pElementClassIndex = pExtDataRecClass->DemDataElementClassRefStartIndex;
				do
				{
					u8ElementLoop++;
					pElementClass = &(Dem_General.DemDataElementClass[*pElementClassIndex]);

#if(DEM_EXTERNALCSDATA_ELEMENT_NUM > 0)
					if(pElementClass->DemExternalCSDataElementClass != NULL_PTR)
					{
						Dem_CaptureExternalCSDataElement(\
								(&pBuffer[u16Offset]),\
								pElementClass->DemExternalCSDataElementClass);

						u16Offset += pElementClass->DemExternalCSDataElementClass->\
								DemDataElementDataSize;
					}
					else
					{
#endif /* #if(DEM_EXTERNALCSDATA_ELEMENT_NUM > 0) */
#if(DEM_EXTERNALSRDATA_ELEMENT_NUM > 0)
						if(pElementClass->DemExternalSRDataElementClass != NULL_PTR)
						{
							 Dem_CaptureExternalSRDataElement();
						}
						else
						{
#endif /* #if(DEM_EXTERNALSRDATA_ELEMENT_NUM > 0) */

#if(DEM_INTERNAL_DATA_ELEMENT_NUM > 0)
							Dem_CaptureInternalDataElement(\
									InternalEventId,\
									(&pBuffer[u16Offset]),\
									pElementClass->DemInternalDataElementClass);

							u16Offset += pElementClass->DemInternalDataElementClass->\
									DemDataElementDataSize;

#endif /* #if(DEM_INTERNAL_DATA_ELEMENT_NUM > 0) */
#if(DEM_EXTERNALSRDATA_ELEMENT_NUM > 0)
							}
#endif /* #if(DEM_EXTERNALSRDATA_ELEMENT_NUM > 0) */
#if(DEM_EXTERNALCSDATA_ELEMENT_NUM > 0)
						}
#endif /* #if(DEM_EXTERNALCSDATA_ELEMENT_NUM > 0) */
						pElementClassIndex++;
					}while(u8ElementLoop < u8ElementRefNum);

				pRecordClassIndex++;
			}while(u8Loop < u8RecordNum);
		}
	}
}
#endif	/* #if(DEM_EXTENDED_DATA_CLASS_NUM > 0) */

/*
 * @brief        	Dem_EventEnterQueue
 * @details			Add event to queue which is reported by Dem_ReportErrorStatus
 *                  and Dem_SetEventStatus.
 *
 * @param[in]    	InternalEventId: Internal event identifier which value is equal to EventId - 1,
 *                  used to retrieve configurations.
 * @param[in]    	Status: Event test result.
 *
 * @return          Result of this check.
 * @retval          E_OK: Event add successfully.
 * @retval          E_NOT_OK: Event add unsuccessfully.
 */
STATIC FUNC(Std_ReturnType, DEM_CODE) Dem_EventEnterQueue
(
	Dem_EventIdType InternalEventId,
	Dem_EventStatusType Status
)
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;
	Dem_EventBufferType* pQueueNode = &(Dem_EventQueue[Dem_EventQueueWrite]);

	if(pQueueNode->eventId == 0u)
	{
		pQueueNode->eventId = InternalEventId + 1u;
		pQueueNode->status = Status;
		pQueueNode->reportStatus = Dem_InitState;

#if(DEM_ENVIRONMENT_DATA_CAPTURE == DEM_CAPTURE_SYNCHRONOUS_TO_REPORTING)
		if (Dem_InitState == DEM_STATE_INIT)
		{
			if(pQueueNode->captureData == (boolean)FALSE)
			{
#if(DEM_FREEZEFRAME_ENABLE == STD_ON)
			/**
			 * @req [SWS_Dem_00805] If the configuration parameter DemEnvironmentDataCapture is set
			 *      to DEM_CAPTURE_SYNCHRONOUS_TO_REPORTING, event-specific freeze frame data shall
			 *      be captured within the reporting function
			 */
				Dem_CaptureFreezeFrame(InternalEventId,pQueueNode->FFData);
#endif /* #if(DEM_FREEZEFRAME_ENABLE == STD_ON) */
#if(DEM_EXTENDED_DATA_CLASS_NUM > 0)
			/**
			 * @req [SWS_Dem_01082] If the configuration parameter DemEnvironmentDataCapture is set
			 *      to DEM_CAPTURE_SYNCHRONOUS_TO_REPORTING, event-specific extended data shall be
			 *      captured within the reporting function
			 */
				Dem_CaptureExtendedData(InternalEventId,pQueueNode->ExtData);
#endif	/* #if(DEM_EXTENDED_DATA_CLASS_NUM > 0) */
#if(DEM_PID_CLASS_NUM > 0)
				Dem_CapturePidClass(InternalEventId,pQueueNode->PidData);
#endif /* #if(DEM_PID_CLASS_NUM > 0) */

				pQueueNode->captureData = (boolean)TRUE;
			}
		}
#endif /* #if(DEM_ENVIRONMENT_DATA_CAPTURE == DEM_CAPTURE_SYNCHRONOUS_TO_REPORTING) */

		Dem_EventQueueWrite++;
		if(Dem_EventQueueWrite >= DEM_EVENT_QUEUE_SIZE)
		{
			Dem_EventQueueWrite = 0u;
		}
		ret = (Std_ReturnType)E_OK;
	}
	return ret;
}

/*
 * @brief        	Dem_EventConditionCheck
 * @details			Check whether enable conditions and storage conditions are full filled or not.
 *
 * @param[in]    	EventStatus: Test result of relate event.
 *
 * @param[in-out]   pInternalEventId:  Internal event identifier which value is equal to EventId - 1,
 *                  used to retrieve configurations.If replacement event is used and storage conditions
 *                  are full filled,this id shall be updated to internal id of replacement event.
 *
 * @return          Result of this check.
 * @retval          E_OK: Conditions are full filled.
 * @retval          E_NOT_OK: Conditions are not full filled.
 */
STATIC FUNC(boolean, DEM_CODE) Dem_EventConditionCheck
(
	Dem_EventStatusType EventStatus,
	P2VAR(Dem_EventIdType,AUTOMATIC,DEM_VAR)pInternalEventId
)
{
#if(DEM_STORAGE_CONDITION_NUM > 0)
	uint8 u8Loop			= 0u;
	uint8  u8GroupRef		= 0u;
	const uint8* pGroup		= NULL_PTR;
#endif /* #if(DEM_STORAGE_CONDITION_NUM > 0) */

	boolean ret = (boolean)TRUE;

#if(DEM_ENABLE_CONDITION_NUM > 0)
	if((boolean)FALSE == (Dem_ISEnable_EnableCondition(*pInternalEventId)))
	{
		/**
		 * @req [SWS_Dem_00447] If the Dem module is requested to support
		 *      enable conditions,the Dem module shall check the assigned
		 *      enable conditions after the diagnostic monitor reports an
		 *      event.
		 * @req [SWS_Dem_00449] If one enable condition is not fulfilled,
		 *      all status reports from SWCs (Dem_SetEventStatus) and BSW
		 *      modules (Dem_ReportErrorStatus) for those events being
		 *      assigned to this condition shall be ignored (no change of
		 *      UDS DTC status byte) by the Dem.
		 */
		Dem_InternalDebounceHandle(*pInternalEventId);
		ret = (boolean)FALSE;
	}
	else
#endif /* #if(DEM_ENABLE_CONDITION_NUM > 0) */
	{
#if(DEM_STORAGE_CONDITION_NUM > 0)
		if((boolean)FALSE == Dem_ISEnable_StorageCondition(*pInternalEventId))
		{
			u8GroupRef = Dem_ConfigPtr->DemEventParameter[*pInternalEventId].\
					DemStorageConditionGroupRef;

			if(u8GroupRef != 0xFFu)
			{
				pGroup = Dem_General.DemStorageConditionGroup[u8GroupRef];
				do
				{
					if(((pGroup[(u8Loop >> 3u)] & (uint8)(1u << (u8Loop & 0x07u))) != 0u) \
							&& ((boolean)FALSE == Dem_ISEnable_EvStorageCondition(u8Loop))\
							&& (Dem_General.DemStorageCondition[u8Loop].\
									DemStorageConditionReplacementEventRef != 0xFFFFu)\
							&&(EventStatus == DEM_EVENT_STATUS_FAILED))
					{
						*pInternalEventId = Dem_General.DemStorageCondition[u8Loop].\
								DemStorageConditionReplacementEventRef;
						break;
					}
					u8Loop++;
				}while(u8Loop < DEM_STORAGE_CONDITION_NUM);
			}
		}
#endif /* #if(DEM_STORAGE_CONDITION_NUM > 0) */
	}
	return ret;
}

#if(DEM_DTC_NUM > 0)
#if(DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_DISABLED)
/*
 * @brief        	Dem_TriggerOnEventStatus
 * @details			If the combined DTC status has changed the relevant call-backs shall be invoked.
 *
 * @param[in]       InternalEventId:  Internal event identifier which value is equal to EventId - 1,
 *                  used to retrieve configurations.
 * @param[in]		OldStatus: Old dtc status.
 * @param[in]		NewStatus: New dtc status.
 */
STATIC FUNC(void, DEM_CODE) Dem_TriggerOnEventStatus
(
	Dem_EventIdType InternalEventId,
    Dem_UdsStatusByteType OldStatus,
    Dem_UdsStatusByteType NewStatus
)
{
#if ((DEM_CALLBACK_OBD_DTC_STATUS_CHANGED_NUM > 0) || (DEM_CALLBACK_EVENT_STATUS_CHANGED_NUM > 0) \
		|| (DEM_CALLBACK_J1939_DTC_STATUS_CHANGED_NUM > 0))
    uint8 u8loop = 0u;
#endif /* #if ((DEM_CALLBACK_OBD_DTC_STATUS_CHANGED_NUM > 0) || (DEM_CALLBACK_EVENT_STATUS_CHANGED_NUM > 0) \
		|| (DEM_CALLBACK_J1939_DTC_STATUS_CHANGED_NUM > 0)) */

    uint32 u32Dtc = 0u;

#if(DEM_CALLBACK_EVENT_STATUS_CHANGED_NUM > 0)
    const Dem_EventParameterType* pEventParameter = &(Dem_ConfigPtr->DemEventParameter[InternalEventId]);

    const Dem_CallbackEventStatusChangedsType* pCbk = pEventParameter->DemCallbackEventStatusChanged;
#endif /* #if(DEM_CALLBACK_DTC_STATUS_CHANGED_NUM > 0) */

    /**
     * @req [SWS_Dem_00828] If the API Dem_DcmControlDTCStatusChangedNotification with state value TRUE
     *      and the parameter DemTriggerDcmReports is enable,the Dem starts to report changes of the DTC
     *      status to the Dcm via Dcm_DemTriggerOnDTCStatus.
     */
	(void)Dem_GetDTCOfEvent((InternalEventId + 1u),DEM_DTC_FORMAT_UDS,&u32Dtc);
	if(u32Dtc != 0u)
	{
#if (DEM_TRIGGER_DCM_REPORTS == STD_ON)
		if(Dem_DcmTriggerEnable == (boolean)TRUE)
		{
			(void)Dcm_DemTriggerOnDTCStatus(u32Dtc,OldStatus,NewStatus);
		}
#endif /* #if (DEM_TRIGGER_DCM_REPORTS == STD_ON) */

#if(DEM_CALLBACK_EVENT_STATUS_CHANGED_NUM > 0)
		do
		{
			if(Dem_CallbackEventStatusChangeds[u8loop].DemCallbackEventStatusChangedFnc != NULL_PTR)
			{
				(void)(Dem_CallbackEventStatusChangeds[u8loop].DemCallbackEventStatusChangedFnc)(\
					        (InternalEventId + 1u),\
							OldStatus,\
							NewStatus);
			}
			u8loop++;
		}while(u8loop < DEM_CALLBACK_EVENT_STATUS_CHANGED_NUM);
#endif /* #if(DEM_CALLBACK_EVENT_STATUS_CHANGED_NUM > 0) */
	}
	else
	{
		(void)Dem_GetDTCOfEvent((InternalEventId + 1u),DEM_DTC_FORMAT_OBD,&u32Dtc);
		if(u32Dtc != 0u)
		{
#if(DEM_CALLBACK_OBD_DTC_STATUS_CHANGED_NUM > 0)
			do
			{
				if(Dem_General.DemGeneralOBD->Dem_CallbackOBDDTCStatusChangeds[u8loop].\
						DemCallbackDTCStatusChangedFnc != NULL_PTR)
				{
					(void)(Dem_General.DemGeneralOBD->Dem_CallbackOBDDTCStatusChangeds[u8loop].\
							DemCallbackDTCStatusChangedFnc)(u32Dtc, OldStatus, NewStatus);
				}
				u8loop++;
			}while(u8loop < DEM_CALLBACK_OBD_DTC_STATUS_CHANGED_NUM);
#endif /* #if(DEM_CALLBACK_OBD_DTC_STATUS_CHANGED_NUM > 0) */
		}
		else
		{
			(void)Dem_GetDTCOfEvent((InternalEventId + 1u),DEM_DTC_FORMAT_J1939,&u32Dtc);
			if(u32Dtc != 0u)
			{
#if(DEM_CALLBACK_J1939_DTC_STATUS_CHANGED_NUM > 0)
				do
				{
					(void)Dem_CallbackJ1939DTCStatusChangeds(u32Dtc,OldStatus,NewStatus);
					u8loop++;
				}while(u8loop < DEM_CALLBACK_J1939_DTC_STATUS_CHANGED_NUM);
#endif /* #if(DEM_CALLBACK_J1939_DTC_STATUS_CHANGED_NUM > 0) */
			}
			else
			{
				;
			}
		}
	}

#if(DEM_CALLBACK_EVENT_STATUS_CHANGED_NUM > 0)
	u8loop = 0u;
	do
	{
		if(pCbk != NULL_PTR)
		{
			if(pCbk->DemCallbackEventStatusChangedFnc != NULL_PTR)
			{
				(void)(*pCbk->DemCallbackEventStatusChangedFnc)(\
						(InternalEventId + 1u),\
						OldStatus,NewStatus);
			}
			pCbk++;
		}
		u8loop++;
	}while(u8loop < pEventParameter->DemStatusChangedCbkNum);
#endif /* #if(DEM_CALLBACK_EVENT_STATUS_CHANGED_NUM > 0) */
	return;
}
#endif /* #if(DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_DISABLED) */
#endif /* #if(DEM_DTC_NUM > 0) */

/*
 * @brief        	Dem_InternalFDCCal
 * @details			Update internal data information which relate to DemInternalDataElementClass.
 *
 * @param[in]       InternalEventId:  Internal event identifier which value is equal to EventId - 1,
 *                  used to retrieve configurations.
 *
 * @param[out]      pFDC:FDC of reported event.If the event use monitor debounce,the value of FDC shall
 *                  obtain via DemCallbackGetFDCFncs.
 *
 * @return          Result of getting event FDC.
 * @retval          E_OK:Get FDC successfully.
 * @retval          DEM_E_NO_FDC_AVAILABLE:Get FDC un-successfully.
 */
STATIC FUNC(Std_ReturnType, DEM_CODE)Dem_InternalFDCCal
(
	Dem_EventIdType InternalEventId
)
{
	Std_ReturnType ret = (Std_ReturnType)DEM_E_NO_FDC_AVAILABLE;
	const Dem_EventParameterType * pEventPara = &(Dem_ConfigPtr->DemEventParameter[InternalEventId]);
	sint8 s8FDC = (sint8)0;
	
	/* PRQA S 2981 ++ #violate MISAR2004_21.1:This initialization is 
       redundant. The value of this object is never used before being
       modified.  */
#if(DEM_DEBOUNCE_COUNTER_BASED_SUPPORT == STD_ON)
#if(DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM > 0)
	Dem_DebounceCounterType* pDebounceCntInfo = NULL_PTR;
	const Dem_DebounceCounterBasedClassType* pDebounceCnt = NULL_PTR;
#endif /* #if(DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM > 0) */
#endif /* #if(DEM_DEBOUNCE_COUNTER_BASED_SUPPORT == STD_ON) */

#if(DEM_DEBOUNCE_TIME_BASED_SUPPORT == STD_ON)
#if(DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0)
	Dem_DebounceTimeType* pDebounceTimerInfo = NULL_PTR;
	const Dem_DebounceTimeBaseClassType* pDebounceTimer = NULL_PTR;
#endif /* #if(DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0) */
#endif /* #if(DEM_DEBOUNCE_TIME_BASED_SUPPORT == STD_ON) */
       /* PRQA S 2981 -- */
#if(DEM_DEBOUNCE_MONITOR_INTERNAL_EVENT_NUM > 0)
	Dem_GetFDCFncType pGetFDCFnc;
#endif /* #if(DEM_DEBOUNCE_MONITOR_INTERNAL_EVENT_NUM > 0) */

	switch(pEventPara->DemDebounceAlgorithmClassType)
	{
#if(DEM_DEBOUNCE_COUNTER_BASED_SUPPORT == STD_ON)
#if(DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM > 0)
	case DEM_DEBOUNCE_COUNTER_BASED:
		if((pEventPara->DemDebounceAlgorithmRef < DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM)\
				&&(pEventPara->DemDebounceInfoIndex < DEM_DEBOUNCE_COUNTER_BASED_EVENT_NUM))
		{
			pDebounceCnt = &(Dem_ConfigPtr->DemDebounceCounterBasedClass\
								[pEventPara->DemDebounceAlgorithmRef]);

			pDebounceCntInfo = &(Dem_InternalDebounceCounter[pEventPara->DemDebounceInfoIndex]);

			if(pDebounceCntInfo->counter == (sint16)0)
			{
				s8FDC = 0;
			}
			else if(pDebounceCntInfo->counter > (sint16)0)
			{
				if(pDebounceCntInfo->counter >= pDebounceCnt->DemDebounceCounterFailedThreshold)
				{
					s8FDC = (sint8)127;
				}
				else
				{
					s8FDC = (sint8)((pDebounceCntInfo->counter * (sint16)127) \
							/ pDebounceCnt->DemDebounceCounterFailedThreshold);
				}
			}
			else
			{
				if(pDebounceCntInfo->counter <= pDebounceCnt->DemDebounceCounterPassedThreshold)
				{
					s8FDC = (sint8)-128;
				}
				else
				{
					s8FDC = (sint8)((pDebounceCntInfo->counter * (sint16)(-128)) \
							/ pDebounceCnt->DemDebounceCounterPassedThreshold);
				}
			}
			ret = (Std_ReturnType)E_OK;
		}
		break;
#endif /* #if(DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM > 0) */
#endif /* #if(DEM_DEBOUNCE_COUNTER_BASED_SUPPORT == STD_ON) */

#if(DEM_DEBOUNCE_TIME_BASED_SUPPORT == STD_ON)
#if(DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0)
	case DEM_DEBOUNCE_TIME_BASE:
		if((pEventPara->DemDebounceAlgorithmRef < DEM_DEBOUNCE_TIME_BASE_CLASS_NUM)\
				&&(pEventPara->DemDebounceInfoIndex < \
						(uint16)DEM_DEBOUNCE_TIME_BASED_EVENT_NUM ))
		{
			pDebounceTimer = &(Dem_ConfigPtr->DemDebounceTimeBaseClass\
					[pEventPara->DemDebounceAlgorithmRef]);

			pDebounceTimerInfo = &(DemInternalDebounceTimer[pEventPara->DemDebounceInfoIndex]);

			if(pDebounceTimerInfo->status == DEM_EVENT_STATUS_PASSED)
			{
				s8FDC = (sint8)-128;
			}
			else if(pDebounceTimerInfo->status == DEM_EVENT_STATUS_FAILED)
			{
				s8FDC = (sint8)127;
			}
			else if(pDebounceTimerInfo->status == DEM_EVENT_STATUS_PREFAILED)
			{
				if(pDebounceTimerInfo->timeout >= pDebounceTimer->DemDebounceTimeFailedThreshold)
				{
					s8FDC = (sint8)127;
				}
				else
				{
					s8FDC = (sint8)((pDebounceTimerInfo->timeout * 127u) \
							/ pDebounceTimer->DemDebounceTimeFailedThreshold);
				}
			}
			else
			{
				s8FDC = (sint8)(-1)*((sint8)((pDebounceTimerInfo->timeout * 128u)\
						/pDebounceTimer->DemDebounceTimePassedThreshold));
			}
			ret = (Std_ReturnType)E_OK;
		}
		break;
#endif /* #if(DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0) */
#endif /* #if(DEM_DEBOUNCE_TIME_BASED_SUPPORT == STD_ON) */

#if(DEM_DEBOUNCE_MONITOR_INTERNAL_EVENT_NUM > 0)
	case DEM_DEBOUNCE_MONITOR_INTERNAL:
		/**
		 * @req [SWS_Dem_00264] If debouncing is performed by a SW-C (not handled Dem internally),
		 *      the Dem module shall retrieve the current value of the fault detection counter for
		 *      the requested event by using the method defined in DemCallbackGetFDC container.
		 */
		pGetFDCFnc = Dem_CallbackGetFDCFncs[pEventPara->DemDebounceInfoIndex];

		if(pGetFDCFnc != NULL_PTR)
		{
			ret = pGetFDCFnc(&s8FDC);
			if(ret != (Std_ReturnType)E_OK)
			{
				s8FDC = (sint8)0;
			}
		}
		else
		{
			s8FDC = (sint8)0;
			/**
			 * @req [SWS_Dem_00671] If the callback-function GetFaultDetectionCounter is not
			 *      configured(refer to configuration container DemCallbackGetFDC) for a given
			 *      event,the API Dem_GetFaultDetectionCounter shall return DEM_E_NO_FDC_AVAILABLE.
			 */
			ret = (Std_ReturnType)DEM_E_NO_FDC_AVAILABLE;
		}
		break;
#endif /* #if(DEM_DEBOUNCE_MONITOR_INTERNAL_EVENT_NUM > 0) */

	default:
		break;
	}

	/**
	 * @req [SWS_Dem_01084] If the configuration parameter DemInternalDataElement is set to
	 *      DEM_CURRENT_FDC,then the Dem-internal value of the current fault detection counter
	 *      shall be mapped to the respective data element with the following value-translation:
	 *      [0..127]->[0x00..0x7F] and [-1..-128]->[0xFF..0x80]
	 */
	Dem_EventInternalData[InternalEventId].currentFDC = s8FDC;

#if(DEM_DTC_NUM > 0)
	if(pEventPara->DemDTCRef != 0xFFFFu)
	{
		if(s8FDC > (sint8)0)
		{
			if((uint8)s8FDC > Dem_MaxFDCSinceLastClear[pEventPara->DemDTCRef])
			{
				Dem_MaxFDCSinceLastClear[pEventPara->DemDTCRef] = (uint8)s8FDC;
			}
			if((uint8)s8FDC > Dem_MaxFDCDurCurCycles[pEventPara->DemDTCRef])
			{
				Dem_MaxFDCDurCurCycles[pEventPara->DemDTCRef] = (uint8)s8FDC;
			}
		}

#if(DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_DISABLED)
		Dem_InternalFDC[pEventPara->DemDTCRef] = s8FDC;
#else /* (DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_DISABLED) */
		if(s8FDC > Dem_InternalFDC[pEventPara->DemDTCRef])
		{
			Dem_InternalFDC[pEventPara->DemDTCRef] = s8FDC;
		}
#endif /* #if(DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_DISABLED) */
	}
#endif /* #if(DEM_DTC_NUM > 0) */

	return ret;
}

#if(DEM_DTC_NUM > 0)
/*
 * @brief        	Dem_InternalDataUpdata
 * @details			Update internal data information which relate to DemInternalDataElementClass.
 *
 * @param[in]       InternalEventId: Internal event identifier which value is equal to EventId - 1,
 *                  used to retrieve configurations.
 */
STATIC FUNC(void, DEM_CODE)Dem_InternalDataUpdata
(
	Dem_EventIdType InternalId
)
{
	const Dem_EventParameterType * pEventPara = &(Dem_ConfigPtr->DemEventParameter[InternalId]);

	uint16 u16DtcRef = pEventPara->DemDTCRef;

	const Dem_DTCAttributesType * pDtcAttr;

	Dem_MemoryInfoType* pMemInfo;

	Dem_MemoryEntryType* pEntry = NULL_PTR;

	if(u16DtcRef != 0xFFFFu)
	{
		pDtcAttr = &(Dem_ConfigPtr->DemDTCAttributes[Dem_ConfigPtr->\
					DemDTC[pEventPara->DemDTCRef].DemDTCAttributesRef]);

		if(pDtcAttr->DemAgingAllowed == (boolean)FALSE)
		{
			/**
			 * @req [SWS_Dem_01044]  If Dem DemAgingAllowed is set to 'false' the internal
			 *      data element DEM_AGINGCTR_UPCNT shall be '0'.
			 */
			Dem_EventInternalData[InternalId].agingUpCnt = 0u;

			/**
			 * @req [SWS_Dem_01043] If DemAgingAllowed is set to 'false' the internal data element
			 *      DEM_AGINGCTR_DOWNCNT shall be DemAgingCycleCounterThreshold if configured or '255'.
			 */
			Dem_EventInternalData[InternalId].agingDownCnt = 255u;
		}
		else
		{
			/**
			 * @req [SWS_Dem_00673] If the data element DEM_AGINGCTR_DOWNCNT is configured,
			 *      the aging counter mapping shall be based on a count-down mechanism from
			 *      DemAgingCycleCounterThreshold to 0.
			 */
			Dem_EventInternalData[InternalId].agingDownCnt = \
								(uint8)(pDtcAttr->DemAgingCycleCounterThreshold - \
								Dem_EventInternalData[InternalId].agingUpCnt);
		}

		pEntry = Dem_GetEntryFromMemory(pDtcAttr->DemMemoryDestinationRef,(InternalId + 1u));

		if(pEntry != NULL_PTR)
		{
			pMemInfo = Dem_GetMemInfoByOrigin(pDtcAttr->DemMemoryDestinationRef);
			if((pMemInfo != NULL_PTR) && (pMemInfo->OverFlow == (boolean)TRUE))
			{
				Dem_EventInternalData[InternalId].overflowIndication = (uint8)TRUE;
			}
		}

#if((DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU) || (DEM_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
		if((Dem_ConfigPtr->DemDTC[Dem_ConfigPtr->DemEventParameter[InternalId].DemDTCRef].\
			DemObdDTCRef != 0xFFFFu) && (pEntry == NULL_PTR))
		{
			pEntry = Dem_GetEntryFromMemory(DEM_DTC_ORIGIN_PERMANENT_MEMORY,(InternalId + 1u));
			if(pEntry != NULL_PTR)
			{
				pMemInfo = Dem_GetMemInfoByOrigin(DEM_DTC_ORIGIN_PERMANENT_MEMORY);
				if((pMemInfo != NULL_PTR) && (pMemInfo->OverFlow == (boolean)TRUE))
				{
					Dem_EventInternalData[InternalId].overflowIndication = (uint8)TRUE;
				}
			}
		}
#endif /* #if((DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU) || (DEM_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU)) */

		Dem_EventInternalData[InternalId].significance = pDtcAttr->DemDTCSignificance;

		(void)Dem_InternalFDCCal(InternalId);

		if(pEntry != NULL_PTR)
		{
			pEntry->AgingCounter = Dem_EventInternalData[InternalId].agingUpCnt;
			pEntry->FailureCounter = Dem_EventInternalData[InternalId].failedCycles;
			pEntry->HealingCounter = Dem_EventInternalData[InternalId].healingCnt;
			pEntry->OccurrenceCounter = Dem_EventInternalData[InternalId].occurCnt;
			pEntry->CyclesSinceLastFailed = Dem_EventInternalData[InternalId].cyclesSinceLastFailed;
			pEntry->CyclesSinceFirstFailed = Dem_EventInternalData[InternalId].cyclesSinceFirstFailed;
			pEntry->UdsStatus = Dem_EventUDSBitStatus[InternalId];
		}
	}
}

#if (DEM_AVAILABILITY_SUPPORT == DEM_EVENT_AVAILABILITY)
/*
 * @brief        	Dem_DTCSuppressUpdata
 * @details			Update dtc suppress information,if one dtc match multiple events,only suppress
 *                  this dtc when all relate events are invalid.
 *
 * @param[in]       InternalEventId: Internal event identifier which value is equal to EventId - 1,
 *                  used to retrieve configurations.
 */
STATIC FUNC(void, DEM_CODE)Dem_DTCSuppressUpdata
(
	Dem_EventIdType InternalEventId
)
{
	boolean dtcSuppress = (boolean)TRUE;
	uint16 u16Loop      = 0u;
	uint16 u16DtcRef    = Dem_ConfigPtr->DemEventParameter[InternalEventId].DemDTCRef;

	if(u16DtcRef != 0xFFFFu)
	{
		do
		{
			if((u16DtcRef == Dem_ConfigPtr->DemEventParameter[u16Loop].DemDTCRef)\
				&& (Dem_ISEnable_EventAvaliable(u16Loop) == (boolean)TRUE))
			{
				dtcSuppress = (boolean)FALSE;
				break;
			}
			u16Loop++;
		}while(u16Loop < DEM_EVENT_PARAMETER_NUM);

		if(dtcSuppress == (boolean)TRUE)
		{
			/* all relate events are non-available */
			Dem_Enable_DTCSuppress(u16DtcRef);
		}
	}
}
#endif /* #if (DEM_AVAILABILITY_SUPPORT == DEM_EVENT_AVAILABILITY) */
#endif /* #if(DEM_DTC_NUM > 0) */

#if(DEM_MAXNUMBER_PRESTORED_FF > 0)
/*
 * @brief        	Dem_PreStoreFFDeal
 * @details			If pre freeze frame data has not stored,find an empty info to store it and
 *                  then get the freeze frame data;Otherwise directly get the freeze frame data.
 *
 * @param[in]       EventId: Event identifier.
 */
STATIC FUNC(Std_ReturnType, DEM_CODE)Dem_PreStoreFFDeal
(
	Dem_EventIdType EventId
)
{
	boolean emptyFind = (boolean)FALSE;
	uint16 u16Loop = 0u;
	uint16 u16EmptyPreFFInfo = 0u;
	Std_ReturnType ret = (Std_ReturnType)E_OK;

	do
	{
		if(Dem_PreFFInfos[u16Loop].eventId == EventId)
		{
			break;
		}
		else if(Dem_PreFFInfos[u16Loop].eventId == 0u)
		{
			emptyFind = (boolean)TRUE;
			u16EmptyPreFFInfo = u16Loop;
			u16Loop++;
		}
		else
		{
			u16Loop++;
		}
	}while(u16Loop < DEM_MAXNUMBER_PRESTORED_FF);

	if(u16Loop == DEM_MAXNUMBER_PRESTORED_FF)
	{
		if(emptyFind == (boolean)TRUE)
		{
			Dem_PreFFInfos[u16EmptyPreFFInfo].eventId = EventId;
			Dem_CaptureFreezeFrame((EventId - 1u),Dem_PreFFInfos[u16EmptyPreFFInfo].FFData);
		}
		else
		{
			/**
			 * @req [SWS_Dem_00808] The API Dem_PrestoreFreezeFrame shall return E_NOT_OK
			 *      if no memory is available
			 */
			ret = (Std_ReturnType)E_NOT_OK;
		}
	}
	else
	{
		Dem_CaptureFreezeFrame((EventId - 1u),Dem_PreFFInfos[u16Loop].FFData);
	}
	return ret;
}
#endif /* #if(DEM_MAXNUMBER_PRESTORED_FF > 0) */

#if(DEM_DTC_NUM > 0)
#if((DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU) || (DEM_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
/*
 * @brief        	Dem_IsWarmUpOpCyc
 * @details			Check if request operation cycle is warm up cycle or not.
 *
 * @param[in]		OperationCycleId: operation cycle identifier.
 *
 * @return          If this cycle is warm up operation cycle return true,otherwise return false.
 * @retval          TRUE: this is a warm up operation cycle.
 * @retval          FALSE: this is not a warm up operation cycle.
 */
STATIC FUNC(boolean, DEM_CODE) Dem_IsWarmUpOpCyc
(
	uint8 OperationCycleId
)
{
	uint8 u8Loop = 0u;
	boolean retVal = (boolean)FALSE;

	do
	{
		if((Dem_General.DemOperationCycle[u8Loop].DemOperationCycleId == OperationCycleId)\
				&&(Dem_General.DemOperationCycle[u8Loop].DemOperationCycleType == DEM_OPCYC_WARMUP))
		{
			retVal = (boolean)TRUE;
			break;
		} 
		u8Loop++;  /* PRQA S 2984 #violate MISAR2004_21.1:The value of the result is variable */
	}while(u8Loop < DEM_OPERATION_CYCLE_NUM);  /* PRQA S 2996,2993 #violate MISAR2004_13.7:The result of this logical 
                                                      operation is variable,and this loop will excute more than onece when 
						      DEM_OPERATION_CYCLE_NUM is bigger than zero */

	return retVal;
}
#endif /* #if((DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU) || (DEM_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU)) */

#if(DEM_RESSET_CONFIRMEDBIT_ONOVERFLOW == STD_OFF)
STATIC FUNC(void, DEM_CODE) Dem_AllocateAgingCounter
(
	Dem_DTCOriginType DTCOrigin
)
{
	uint8 u8Loop;
	uint8 u8AbsTime = 0u;
	uint8 u8EntryNum = 0u;
	uint16 u16Loop = 0u;
	const Dem_DTCAttributesType* pDtcAttr;
	Dem_MemoryEntryType* pEntry;
	Dem_MemoryInfoType* pMemInfo;
	Dem_MemoryEntryType* entryPtr;

	do
	{
		if((Dem_ISEnable_UdsStatusBits(u16Loop,DEM_UDS_STATUS_CDTC))\
				&& (!(Dem_ISEnable_UdsStatusBits(u16Loop,DEM_UDS_STATUS_TF))))
		{
			if(NULL_PTR == Dem_GetEntryFromMemory(DTCOrigin,(u16Loop + 1u)))
			{
				pEntry = Dem_GetEntryFromMemory(DTCOrigin,0x00u);
				if(pEntry != NULL_PTR)
				{
					pDtcAttr = &(Dem_ConfigPtr->DemDTCAttributes[Dem_ConfigPtr->DemDTC[Dem_ConfigPtr->\
									DemEventParameter[u16Loop].DemDTCRef].DemDTCAttributesRef]);
	
					if(pDtcAttr->DemMemoryDestinationRef == DTCOrigin)
					{
						entryPtr = Dem_GetMemoryConf(DTCOrigin,&u8EntryNum);
						pMemInfo = Dem_GetMemInfoByOrigin(DTCOrigin);

						if(pMemInfo->OverFlow == (boolean)FALSE)
						{
							if(pMemInfo->EntryNum < u8EntryNum)
							{
								pMemInfo->EntryNum++;
								if(pMemInfo->EntryNum == u8EntryNum)
								{
									pMemInfo->OverFlow = (boolean)TRUE;
								}
							}
						}

						pEntry->EventId = u16Loop + 1u;

						for(u8Loop = 0u; u8Loop < u8EntryNum; u8Loop++)
						{
							if(u8AbsTime < entryPtr[u8Loop].AbsTime)
							{
								u8AbsTime = entryPtr[u8Loop].AbsTime;
							}
						}
	
						pEntry->AbsTime = u8AbsTime + 1u;
#if(DEM_MAX_NUMBER_FF_RECORDS > 0)
						pEntry->FFStoreNum = 0u;
						pEntry->LastestFF = 0u;
#endif /* #if(DEM_MAX_NUMBER_FF_RECORDS > 0) */
						pEntry->AgingCounter = 0u;
						pEntry->HealingCounter = 0u;
						pEntry->FailureCounter = 0u;
						pEntry->CyclesSinceLastFailed = 0u;
						pEntry->CyclesSinceFirstFailed = 0u;
						pEntry->OccurrenceCounter = 1u;
						pEntry->UdsStatus = Dem_EventUDSBitStatus[u16Loop];
					}
				}
			}
		}
		u16Loop++;
	}while(u16Loop < DEM_EVENT_PARAMETER_NUM);
}
#endif /* #if(DEM_RESSET_CONFIRMEDBIT_ONOVERFLOW == STD_OFF) */
#endif /* #if(DEM_DTC_NUM > 0) */

#if(DEM_INDICATOR_ATTRIBUTE_TOTAL_NUM > 0)
/*
 * @brief        	Dem_EventHealingDeal
 * @details			Event healing process,if healing counter reaches to threshold,
 *                  then clear uds status bit7.
 *
 * @param[in]		InternalEventId: Internal event identifier which value is equal to EventId - 1,
 *                  used to retrieve configurations.
 */
STATIC FUNC(void, DEM_CODE) Dem_EventHealingDeal
(
	void
)
{
	uint16 u16Loop;
	uint8 u8Loop;
	uint8 IndicatorIndex;
	boolean Sign;
	const Dem_IndicatorAttributeType* pIndicatorAttr = NULL_PTR;
#if((DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU) || (DEM_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
	Dem_MemoryEntryType* pEntry = NULL_PTR;
#endif /* #if((DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU) || (DEM_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU)) */

	/**
	 * @req [SWS_Dem_00502] The Dem module shall provide the configuration parameter
	 *      DemIndicatorHealingCycleCounterThreshold per indicator per event (refer
	 *      to DemIndicatorAttribute) to define the maximum number of tested and
	 *      passed healing cycles, before the respective indicator is deactivated.
	 */
	for(IndicatorIndex = 0u; IndicatorIndex < DEM_INDICATOR_NUM; IndicatorIndex++)
	{
		if((Dem_IndicatorStatus[IndicatorIndex] != DEM_INDICATOR_OFF)
#if((DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU) || (DEM_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
#if(DEM_OBD_COMPLIANCY == 15u)/* the MIL of WWH OBD is contorlled by active mode.*/
					&& (IndicatorIndex != DEM_MILINDICATOR_REF)
#endif /* #if(DEM_OBD_COMPLIANCY == 15u) */
#endif /* #if((DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU) || (DEM_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU)) */
			)
		{
			Sign = (boolean)FALSE;
			for(u16Loop = 0u; u16Loop < DEM_EVENT_PARAMETER_NUM; u16Loop++)
			{
				for(u8Loop = 0u;\
					u8Loop < Dem_ConfigPtr->DemEventParameter[u16Loop].DemIndicatorAttributeNum;\
					u8Loop++)
				{
					pIndicatorAttr = &Dem_ConfigPtr->DemEventParameter[u16Loop].DemIndicatorAttribute[u8Loop];
					if(pIndicatorAttr->DemIndicatorRef == IndicatorIndex)
					{
						if(Dem_EventInternalData[u16Loop].healingCnt < \
								pIndicatorAttr->DemIndicatorHealingCycleCounterThreshold)
						{
							Sign = (boolean)TRUE;
							break;
						}
					}
				}
				if(Sign == (boolean)TRUE)
				{
					break;
				}
			}
			if(Sign == (boolean)FALSE)
			{
				Dem_IndicatorStatus[IndicatorIndex] = DEM_INDICATOR_OFF;
			}
		}
	}
	/**
	 * @req [SWS_Dem_00503] The Dem module shall generate the condition WarningIndicator-
	 *      OffCriteriaFulfilled specific for the assigned warning indicator,if the respective
	 *      indicator healing counter of the event entry has been processed (counted further)
	 *      DemIndicatorHealingCycleCounterThreshold times.
	 *
	 * @req [SWS_Dem_00533] If more than one indicator is configured for a specific event
	 *      and each assigned indicator healing counter has been processed (counted further)
	 *      DemIndicatorHealingCycleCounterThreshold times,the Dem module shall reset the
	 *      UDS DTC status bit 7 (WarningIndicatorRequested)
	 *
	 * @req [SWS_Dem_00835] The WIR-bit of the corresponding event shall be set to "0" if
	 *      all referenced Dem Indicator(s) are not active and WIRbit is not controlled by
	 *      the API Dem_SetWIRStatus.
	 */
	for(u16Loop = 0u; u16Loop < DEM_EVENT_PARAMETER_NUM; u16Loop++)
	{
		/* @req [SWS_Dem_00698] */
		if(((boolean)FALSE == Dem_ISEnable_UdsStatusBits(u16Loop,DEM_UDS_STATUS_PDTC))
			&& ((boolean)TRUE == Dem_ISEnable_UdsStatusBits(u16Loop,DEM_UDS_STATUS_WIR)))
		{
			Sign = (boolean)FALSE;
			for(u8Loop = 0u;\
				u8Loop < Dem_ConfigPtr->DemEventParameter[u16Loop].DemIndicatorAttributeNum;\
				u8Loop++)
			{
				pIndicatorAttr = &Dem_ConfigPtr->DemEventParameter[u16Loop].DemIndicatorAttribute[u8Loop];
				if(Dem_IndicatorStatus[pIndicatorAttr->DemIndicatorRef] != DEM_INDICATOR_OFF)
				{
					Sign = (boolean)TRUE;
					break;
				}
			}
			if(Sign == (boolean)FALSE)
			{
				Dem_Disable_UdsStatusBits(u16Loop,DEM_UDS_STATUS_WIR);
			}
		}
	}

#if((DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU) || (DEM_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
	for(u16Loop = 0u; u16Loop < DEM_EVENT_PARAMETER_NUM; u16Loop++)
	{
		if((boolean)FALSE == Dem_CauseMILON(u16Loop))
		{
			pEntry = Dem_GetEntryFromMemory(DEM_DTC_ORIGIN_PERMANENT_MEMORY,(u16Loop+1u));
			if(pEntry != NULL_PTR)
			{
				Dem_DeleMemoryEntry(DEM_DTC_ORIGIN_PERMANENT_MEMORY,pEntry);
			}
		}
	}
#endif /* #if((DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU) || (DEM_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU)) */
}
#endif /* #if(DEM_INDICATOR_ATTRIBUTE_TOTAL_NUM > 0) */

#if(DEM_DTC_NUM > 0)
/*
 * @brief        	Dem_EventAgingSubDeal
 * @details			Event aging sub process,if aging counter reaches to threshold,then delete this entry
 *                  from event memory.
 *
 * @param[in]		InternalEventId: Internal event identifier which value is equal to EventId - 1,
 *                  used to retrieve configurations.
 */
STATIC FUNC(void, DEM_CODE) Dem_EventAgingSubDeal
(
	Dem_MemoryEntryType* Entry,
	Dem_DTCOriginType MemDest,
	Dem_EventIdType InternalId
)
{
	const Dem_EventParameterType* pEventPara = &Dem_ConfigPtr->DemEventParameter[InternalId];
	const Dem_DTCAttributesType* pDtcAttr = &(Dem_ConfigPtr->DemDTCAttributes[Dem_ConfigPtr->DemDTC\
					  [pEventPara->DemDTCRef].DemDTCAttributesRef]);
#if(DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONSTORAGE)
	uint16 u16Loop = 0u;
#endif /* #if(DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONSTORAGE) */
	/**
	 * @req [SWS_Dem_00490] If the configuration parameter DemAgingRequieresTestedCycle
	 *      set to False,the Dem module shall process (count further) the aging counter
	 *      value,if the respective aging cycle ends/restarts
	 *
	 * @req [SWS_Dem_00826] If the configuration parameter DemAgingRequieresTestedCycle
	 *      set to True,the Dem module shall process the aging cycle counter value, if
	 *      the respective aging cycle ends/restarts and the UDS status bit 6 is set to
	 *      zero.
	 */
#if(DEM_AGING_REQUIERES_TESTED_CYCLE == STD_ON)
	if(!(Dem_ISEnable_UdsStatusBits(InternalId,DEM_UDS_STATUS_TNCTOC)))
#endif /* #if(DEM_AGING_REQUIERES_TESTED_CYCLE == STD_ON) */
	{
#if(DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONSTORAGE)
		/**
		 * @req [SWS_Dem_01053] If the Dem module is requested to support combination on
		 *  	storage, the aging shall be calculated based on the combined DTC status
		 *  	(refer to[SWS_Dem_00408]).
		 */
		Dem_SetCombineDtcStatus(InternalId);
		if((!(Dem_ISEnable_DtcStatusBits(pEventPara->DemDTCRef,DEM_UDS_STATUS_WIR)))
			&&(!(Dem_ISEnable_DtcStatusBits(pEventPara->DemDTCRef,DEM_UDS_STATUS_TFTOC)))
#if(DEM_AGING_REQUIERES_TESTED_CYCLE == STD_ON)
			&&(!(Dem_ISEnable_DtcStatusBits(pEventPara->DemDTCRef,DEM_UDS_STATUS_TNCTOC) == 0))
#endif /* #if(DEM_AGING_REQUIERES_TESTED_CYCLE == STD_ON) */
				)
#endif /* #if(DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONSTORAGE) */
		{
			/**
			 * @req [SWS_Dem_00985] The aging counter shall be calculated based on the
			 *      referenced aging/operation cycle (refer to configuration parameter
			 *      DemAgingCycleRef), if aging is enabled (refer to DemAgingAllowed)
			 *      for this event.
			 */
			if(Dem_EventInternalData[InternalId].agingUpCnt < 0xFFu)
			{
				Dem_EventInternalData[InternalId].agingUpCnt++;
			}
			Entry->AgingCounter = Dem_EventInternalData[InternalId].agingUpCnt;
		}

		/**
		 * @req [SWS_Dem_00493] DemAgingCycleCounterThreshold or DemAgingCycleCounter-
		 *      ThresholdForTFSLC(depending on which value is higher)defines the number
		 *      of completed aging cycles, after which the event memory entry shall be
		 *      deleted(aged) from the event memory
		 * @req [SWS_Dem_01176] Additional to event aging described in chapter 7.6.10 the event
		 * 		shall be aged after 200 hours of engine operation while the aging conditions are met.
		 */
		if(((Entry->AgingCounter >= pDtcAttr->DemAgingCycleCounterThreshold)
#if(DEM_STATUS_BIT_HANDLING_TEST_FAILED_SINCE_LAST_CLEAR == DEM_STATUS_BIT_AGING_AND_DISPLACEMENT)
				&& (Entry->AgingCounter >= pDtcAttr->DemAgingCycleCounterThresholdForTFSLC)
#endif /* #if(DEM_STATUS_BIT_HANDLING_TEST_FAILED_SINCE_LAST_CLEAR == DEM_STATUS_BIT_AGING_AND_DISPLACEMENT) */
			)
#if((DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU) || (DEM_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
			|| (((boolean)FALSE == Dem_CauseMILON(InternalId)) \
				&& (200u < Dem_GetVehicleInfo(DEM_OBD_TIME_SINCE_ENGINE_START)))
#endif /* #if((DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU) || (DEM_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU)) */
		)
		{
#if(DEM_STATUS_BIT_HANDLING_TEST_FAILED_SINCE_LAST_CLEAR == DEM_STATUS_BIT_AGING_AND_DISPLACEMENT)
			/**
			 * @req [SWS_Dem_01054] Upon event aging counter reach threshold Dem-
			 *      AgingCycleCounterThresholdForTFSLC,the UDS status bit 5 (Test-
			 *      FailedSinceLastClear) shall be set to 0 if DemStatusBitHandling-
			 *      TestFailedSinceLastClear is set to DEM_STATUS_BIT_AGING_AND_
			 *      DISPLACEMENT
			 */
			Dem_Disable_UdsStatusBits(InternalId,DEM_UDS_STATUS_TFSLC);
#endif /* #if(DEM_STATUS_BIT_HANDLING_TEST_FAILED_SINCE_LAST_CLEAR
	 == DEM_STATUS_BIT_AGING_AND_DISPLACEMENT) */
#if(DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONSTORAGE)
			/**
			 * @req [SWS_Dem_00442] If a combined DTC (combination on storage) is aged,
			 * 		the Dem module shall remove this event memory entry and reset the
			 * 		status bytes of all sub-events according to [SWS_Dem_00823],
			 * 		[SWS_Dem_00824] and [SWS_Dem_00498].
			 */
			for(u16Loop = 0u; u16Loop < DEM_EVENT_PARAMETER_NUM; u16Loop++)
			{
				if(pEventPara->DemDTCRef == Dem_ConfigPtr->DemEventParameter[u16Loop].DemDTCRef)
				{
					Dem_Disable_UdsStatusBits(u16Loop,DEM_UDS_STATUS_CDTC);
					Dem_Disable_CDTCBitChange(u16Loop);
				}
			}
#else /* #if(DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONSTORAGE) */
			/**
			 * @req [SWS_Dem_00498] Upon event aging counter reach threshold
			 *      DemAgingCycleCounterThreshold,the UDS status bit 3 shall
			 *      be set to 0
			 */
			Dem_Disable_UdsStatusBits(InternalId,DEM_UDS_STATUS_CDTC);
			Dem_Disable_CDTCBitChange(InternalId);
#endif /* #if(DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONSTORAGE) */

			Dem_DeleMemoryEntry(MemDest,Entry);

#if(DEM_RESSET_CONFIRMEDBIT_ONOVERFLOW == STD_OFF)
			/**
			 * @req [SWS_Dem_00824] If configuration parameter DemResetConfirmedBit-
			 *      OnOverflow is set to false and an event memory entry aging occurs
			 *      the Dem module shall check for other events having UDS status bit
			 *      3 (ConfirmedDTC) set to 1 and UDS status bit 0 (TestFailed) set to
			 *      0. If such an event is found,the Dem shall allocate an event memory
			 *      location to get an aging counter.
			 */

			Dem_AllocateAgingCounter(MemDest);
#endif /* DEM_RESSET_CONFIRMEDBIT_ONOVERFLOW == STD_OFF */

			Dem_EventInternalData[InternalId].agingUpCnt             = 0u;
			Dem_EventInternalData[InternalId].failedCycles			 = 0u;
			Dem_EventInternalData[InternalId].healingCnt			 = 0u;
			Dem_EventInternalData[InternalId].occurCnt				 = 0u;
			Dem_EventInternalData[InternalId].cyclesSinceFirstFailed = 0u;
			Dem_EventInternalData[InternalId].cyclesSinceLastFailed  = 0u;
			Dem_DebounceReset(InternalId,(boolean)TRUE);
		}
	}
}

/*
 * @brief        	Dem_EventAgingDeal
 * @details			Event aging process,if aging counter reaches to threshold,then delete this entry
 *                  from event memory.
 *
 * @param[in]		InternalEventId: Internal event identifier which value is equal to EventId - 1,
 *                  used to retrieve configurations.
 *
 * @param[in]		OperationCycleId: Identification of operation cycle,like power cycle,driving cycle.
 */
STATIC FUNC(void, DEM_CODE) Dem_EventAgingDeal
(
	Dem_EventIdType InternalId,
	uint8 OperationCycleId
)
{
	Dem_DTCOriginType u8MemDest = DEM_DTC_ORIGIN_PRIMARY_MEMORY;
	const Dem_EventParameterType* pEventPara = &(Dem_ConfigPtr->DemEventParameter[InternalId]);
	const Dem_DTCAttributesType* pDtcAttr;
	Dem_MemoryEntryType* pEntry = NULL_PTR;

	if(pEventPara->DemDTCRef != 0xFFFFu)
	{
		pDtcAttr = &(Dem_ConfigPtr->DemDTCAttributes[Dem_ConfigPtr->\
										DemDTC[pEventPara->DemDTCRef].DemDTCAttributesRef]);

		pEntry = Dem_GetEntryFromMemory(pDtcAttr->DemMemoryDestinationRef,(InternalId + 1u));

		if(pEntry != NULL_PTR)
		{
			if(pDtcAttr->DemAgingAllowed == (boolean)TRUE)
			{
				if((Dem_General.DemOperationCycle[pDtcAttr->DemAgingCycleRef].\
					DemOperationCycleId == OperationCycleId) || (Dem_AgingCycle == OperationCycleId))
				{
					Dem_EventAgingSubDeal(pEntry,u8MemDest,InternalId);
				}
			}
		}
	}
}
#endif /* #if(DEM_DTC_NUM > 0) */

/*
 * @brief        	Dem_CycleCounterDeal
 * @details			Operation counter process,include internal data element such as failed cycles.
 *
 * @param[in]		InternalEventId: Internal event identifier which value is equal to EventId - 1,
 *                  used to retrieve configurations.
 */
STATIC FUNC(void, DEM_CODE) Dem_CycleCounterDeal
(
	Dem_EventIdType InternalId
)
{
	/**
	 * @req [SWS_Dem_00781] In case the counter is available and started, it shall be incremented
	 *      at the end of the referenced operation cycle (refer to DemOperationCycleRef) in case
	 *      the UDS DTC status bit 1 (TestFailedThisOperationCycle) is set to 1
	 */
	if(Dem_ISEnable_UdsStatusBits(InternalId,DEM_UDS_STATUS_TFTOC) == (boolean)TRUE)
	{
		/**
		 * @req [SWS_Dem_00782] The counter shall be implemented as one byte. If any count operation
		 *      occurs which would cause a counter to roll over past 0xFF then the count value shall
		 *      instead be maintained at 0xFF
		 */
		if(Dem_EventInternalData[InternalId].failedCycles < 0xFFu)
		{
			Dem_EventInternalData[InternalId].failedCycles++;
		}

		if(Dem_EventInternalData[InternalId].cyclesSinceLastFailed < 0xFFu)
		{
			/**
			 * @req [SWS_Dem_00773] In case the counter is available and started,it shall be
			 *      incremented at the end of the referenced operation cycle
			 *
			 * @req [SWS_Dem_00774] The counter shall be implemented as one byte.If any count
			 *      operation occurs which would cause a counter to roll over past 0xFF then
			 *      the count value shall instead be maintained at 0xFF.
			 */
			Dem_EventInternalData[InternalId].cyclesSinceLastFailed++;
		}

		if(Dem_EventInternalData[InternalId].cyclesSinceFirstFailed < 0xFFu)
		{
			/**
			 * @req [SWS_Dem_00777] In case the counter is available and started, it shall be
			 *      incremented at the end of the referenced operation cycle.
			 *
			 * @req [SWS_Dem_00778] The counter shall be implemented as one byte.If any count
			 *      operation occurs which would cause a counter to roll over past 0xFF then
			 *      the count value shall instead be maintained at 0xFF.
			 */
			Dem_EventInternalData[InternalId].cyclesSinceFirstFailed++;
		}

	}
	else
	{
		if((Dem_EventInternalData[InternalId].cyclesSinceFirstFailed > 0u)\
				&&(Dem_EventInternalData[InternalId].cyclesSinceFirstFailed < 0xFFu))
		{
			Dem_EventInternalData[InternalId].cyclesSinceFirstFailed++;
		}

		if((Dem_EventInternalData[InternalId].cyclesSinceLastFailed > 0u)\
				&&(Dem_EventInternalData[InternalId].cyclesSinceLastFailed < 0xFFu))
		{
			Dem_EventInternalData[InternalId].cyclesSinceLastFailed++;
		}
	}
}

/*
 * @brief        	Dem_StartOperationCycle
 * @details			Process event healing and aging when start a operation cycle,and
 *                  update uds status bits.
 *
 * @param[in]		OperationCycleId: Identification of operation cycle,like power cycle,driving cycle.
 * @param[in]       reStart: Whether the operation cycle has been started.
 */
STATIC FUNC(void, DEM_CODE) Dem_StartOperationCycle
(
	uint8 OperationCycleId,
	boolean reStart
)
{
	uint16 u16Loop = 0u;
	const Dem_EventParameterType * pEventPara = Dem_ConfigPtr->DemEventParameter;

	if(reStart == (boolean)TRUE)
	{
		Dem_EndOperationCycle(OperationCycleId);
	}

	do
	{
		if(Dem_General.DemOperationCycle[pEventPara->DemOperationCycleRef].DemOperationCycleId\
				== OperationCycleId)
		{
#if(DEM_CALLBACK_INIT_MFOREFNC_TOTALNUM > 0)
			/**
			 * @req [SWS_Dem_00679]	The API Dem_SetOperationCycleState shall trigger the callback
			 *      function InitMonitorForEvent of the related event(s) in case of starting or
			 *      restarting the operation cycle of the event(s).The InitMonitorReason parameter
			 *      shall be set to DEM_INIT_MONITOR_RESTART.
			 */
            if ((pEventPara->DemCallbackInitMForE != NULL_PTR)\
            		&&(pEventPara->DemCallbackInitMForE->DemCallbackInitMForEFnc != NULL_PTR))
            {
            	/**
            	 * @req [SWS_Dem_01046]  In case multiple triggers for DemInitMonitorForEvent occur
            	 *      simultaneously, the InitMforE shall only be called once.The reason shall be
            	 *      selected by following priority: DEM_INIT_MONITOR_CLEAR (highest priority),
            	 *      DEM_INIT_MONITOR_RESTART, DEM_INIT_MONITOR_REENABLED (lowest priority).
            	 */
            	if((Dem_InitMonitorCbkStatus[u16Loop] == 0u)\
            			|| (Dem_InitMonitorCbkStatus[u16Loop] == DEM_INIT_MONITOR_REENABLED)\
						|| (Dem_InitMonitorCbkStatus[u16Loop] == DEM_INIT_MONITOR_STORAGE_REENABLED))
            	{
            		Dem_InitMonitorCbkStatus[u16Loop] = DEM_INIT_MONITOR_RESTART;
            	}
            }
#endif /* #if(DEM_CALLBACK_INIT_MFOREFNC_TOTALNUM > 0) */

            Dem_Disable_FDCTrigger(u16Loop);
            /**
             * @req [SWS_Dem_00389] The Dem module shall clear UDS DTC status bit 1 in case
             *      Dem_SetOperationCycleState(OperationCycleId, CycleState = DEM_CYCLE_STATE_START)
             */
            Dem_Disable_UdsStatusBits(u16Loop,DEM_UDS_STATUS_TFTOC);

			/**
			 * @req [SWS_Dem_00394] The Dem module shall clear UDS DTC status bit 6 in case
			 *      Dem_SetOperationCycleState(OperationCycleId, CycleState = DEM_CYCLE_STATE_START)
			 */
            Dem_Enable_UdsStatusBits(u16Loop,DEM_UDS_STATUS_TNCTOC);

            /**
             * @req [SWS_Dem_00344] d If Dem-internal debouncing is configured, the Dem module shall
             *      reset the Dem-internal debounce algorithm upon starting a new operation cycle
             */
            Dem_DebounceReset(u16Loop,(boolean)TRUE);

#if(DEM_DTC_NUM > 0)
            if(pEventPara->DemDTCRef != 0xFFFFu)
            {
            	/**
            	 * @req [SWS_Dem_00790] The maximum FDC during current operation cycle shall be reset
            	 *      to zero with each (re-)start operation cycle
            	 */
            	Dem_MaxFDCDurCurCycles[pEventPara->DemDTCRef] = 0u;
            }
#endif /* #if(DEM_DTC_NUM > 0) */
		}

#if(DEM_DTC_NUM > 0)
		Dem_SetCombineDtcStatus(u16Loop);
		Dem_InternalDataUpdata(u16Loop);
#endif /* #if(DEM_DTC_NUM > 0) */

		pEventPara++;
		u16Loop++;
	}while(u16Loop < DEM_EVENT_PARAMETER_NUM);

#if(DEM_FREEZEFRAME_ENABLE == STD_ON)
	DEM_VALUE_SET(Dem_CaptureFFOnFDC,0u,DEM_DTC_NUM_BYTE);
#endif /* #if(DEM_FREEZEFRAME_ENABLE == STD_ON) */

#if(DEM_EXTENDED_DATA_CLASS_NUM > 0)
	DEM_VALUE_SET(Dem_CaptureExtOnFDC,0u,DEM_DTC_NUM_BYTE);
#endif /* #if(DEM_EXTENDED_DATA_CLASS_NUM > 0) */

	if (Dem_AgingCycle == OperationCycleId)
	{
		Dem_AgingCycle = 0xFFu;
	}
}

/*
 * @brief        	Dem_EndOperationCycle
 * @details			Process event healing and aging when end a operation cycle,and
 *                  update uds status bits.
 *
 * @param[in]		OperationCycleId: Identification of operation cycle,like power cycle,driving cycle.
 */
STATIC FUNC(void, DEM_CODE) Dem_EndOperationCycle
(
	uint8 OperationCycleId
)
{
	uint16 u16Loop = 0u;
	const Dem_EventParameterType * pEventPara = Dem_ConfigPtr->DemEventParameter;

	do
	{
		if(Dem_General.DemOperationCycle[pEventPara->DemOperationCycleRef].DemOperationCycleId\
				== OperationCycleId)
		{
			Dem_CycleCounterDeal(u16Loop);
		}

		if(Dem_ISEnable_UdsStatusBits(u16Loop,DEM_UDS_STATUS_TFTOC) == (boolean)FALSE)
		{
			if(Dem_ISEnable_UdsStatusBits(u16Loop,DEM_UDS_STATUS_TNCTOC) == (boolean)FALSE)
			{
				if(Dem_ISEnable_UdsStatusBits(u16Loop,DEM_UDS_STATUS_PDTC) == (boolean)TRUE)
				{
					Dem_Disable_UdsStatusBits(u16Loop,DEM_UDS_STATUS_PDTC);
				}

				if(Dem_ISEnable_UdsStatusBits(u16Loop,DEM_UDS_STATUS_WIR) == (boolean)TRUE)
				{
					Dem_EventInternalData[u16Loop].healingCnt++;
				}
			}
		}
		else
		{
			Dem_EventInternalData[u16Loop].agingUpCnt = 0u;
			Dem_EventInternalData[u16Loop].healingCnt = 0u;
		}
		u16Loop++;
		pEventPara++;
	}while(u16Loop < DEM_EVENT_PARAMETER_NUM);

#if(DEM_INDICATOR_ATTRIBUTE_TOTAL_NUM > 0)
	/* execute event healing:close indicators and reset bit7. */
	Dem_EventHealingDeal();
#endif /* #if(DEM_INDICATOR_ATTRIBUTE_TOTAL_NUM > 0) */

	/**
	 * @req [SWS_Dem_00698] The process of aging (counting of aging counter)
	 * 		starts when healing is completed.
	 */
#if(DEM_DTC_NUM > 0)
	for(u16Loop = 0u; u16Loop < DEM_EVENT_PARAMETER_NUM; u16Loop++)
	{
		/* aging process refer to autosar dem figure 7.43 */
		if((Dem_ISEnable_UdsStatusBits(u16Loop,DEM_UDS_STATUS_PDTC) == (boolean)FALSE)
			&& (Dem_ISEnable_UdsStatusBits(u16Loop,DEM_UDS_STATUS_WIR) == (boolean)FALSE))
		{
#if((DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU) || (DEM_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
			/**
			 * @req [constr_6112] An OBD related DTC shall have the Warm-Up cycle as aging cycle.
			 */
			if(((boolean)TRUE == Dem_IsWarmUpOpCyc(OperationCycleId))&&\
				(Dem_ConfigPtr->DemDTC[Dem_ConfigPtr->DemEventParameter[u16Loop].DemDTCRef].\
						DemObdDTCRef != 0xFFFFu))
#endif /* #if((DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU) || (DEM_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU)) */
			{
				Dem_EventAgingDeal(u16Loop,OperationCycleId);
			}
		}

		Dem_SetCombineDtcStatus(u16Loop);
		Dem_InternalDataUpdata(u16Loop);
	}
#endif /* #if(DEM_DTC_NUM > 0) */

#if((DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU) || (DEM_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
	Dem_OBDCounterHandle(OperationCycleId);
#endif /* #if((DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU) || (DEM_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU)) */

	if (Dem_AgingCycle == OperationCycleId)
	{
		Dem_AgingCycle = 0xFFu;
	}
}

#if((DEM_ENABLE_CONDITION_NUM > 0) || (DEM_STORAGE_CONDITION_GROUP_NUM > 0))
/*
 * @brief        	Dem_ConditionIsFulFilled
 * @details			Check if event enable conditions or storage conditions are fulfilled or not.
 *
 * @param[in]		pCondition: Condition status.
 * @param[in]		pGroup: Condition group.
 * @param[in]		len: length of Condition status.
 *
 * @return 			If conditions are fulfilled,it shall return true.
 * @retval          TRUE: Conditions are fulfilled.
 * @retval          FALSE: Conditions are not fulfilled.
 */
STATIC FUNC(boolean, DEM_CODE) Dem_ConditionIsFulFilled
(
    P2CONST(uint8,AUTOMATIC,DEM_VAR) pCondition,
    P2CONST(uint8,AUTOMATIC,DEM_VAR) pGroup,
    uint16 len
)
{
    boolean ret = (boolean)TRUE;
    uint8 u8Loop;
    uint16 u16Loop;

    for(u16Loop = 0u; u16Loop < len; u16Loop++)
    {
    	if(pGroup[u16Loop] != 0U)
    	{
        	for(u8Loop = 0u; u8Loop < 8u; u8Loop++)
        	{
        		/* "bit=1" means the Conidtion Group references this Condition. */
        		if((pGroup[u16Loop] & (uint8)(1u << u8Loop)) != 0U)
        		{
        			/* "bit=0" means this Condition is disabled. */
        			if((pCondition[u16Loop] & (uint8)(1u << u8Loop)) == 0U)
        			{
        				ret = (boolean)FALSE;
        				break;
        			}
        		}
        	}
    	}
    }

    return ret;
}
#endif /* #if((DEM_ENABLE_CONDITION_NUM > 0) || (DEM_STORAGE_CONDITION_GROUP_NUM > 0)) */

#if((DEM_DEBOUNCE_TIME_BASED_SUPPORT == STD_ON) && (DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0u))
/*
 * @brief        	Dem_DebounceTimerDeal
 * @details			Deal debounce timers in  Dem_MainfFunction when timer has reached its threshold.
 */
STATIC FUNC(void, DEM_CODE)Dem_DebounceTimerDeal
(
	void
)
{
	uint16 u16Loop = 0u;
	sint8 s8FdcThreshold = (sint8)0;
	const Dem_DebounceTimeBaseClassType* pDebounceTimer = NULL_PTR;

	while(u16Loop < DEM_DEBOUNCE_TIME_BASED_EVENT_NUM)
	{
		if((DemInternalDebounceTimer[u16Loop].triggered == (boolean)TRUE)\
				&&(DemInternalDebounceTimer[u16Loop].isFreeze == (boolean)FALSE))
		{
			if((DemInternalDebounceTimer[u16Loop].status != DEM_EVENT_STATUS_FAILED)\
					&&(DemInternalDebounceTimer[u16Loop].status != DEM_EVENT_STATUS_PASSED))
			{
				DemInternalDebounceTimer[u16Loop].timeout += DEM_TASK_TIME;
			}
			pDebounceTimer = &(Dem_ConfigPtr->DemDebounceTimeBaseClass[Dem_ConfigPtr->DemEventParameter\
									[DemInternalDebounceTimer[u16Loop].IntId].DemDebounceAlgorithmRef]);

			if((DemInternalDebounceTimer[u16Loop].timeout >= \
					pDebounceTimer->DemDebounceTimeFailedThreshold)\
				&& (DemInternalDebounceTimer[u16Loop].status == DEM_EVENT_STATUS_PREFAILED))
			{
				DemInternalDebounceTimer[u16Loop].status = DEM_EVENT_STATUS_FAILED;
				Dem_FailedEventHandle(DemInternalDebounceTimer[u16Loop].IntId);
				DemInternalDebounceTimer[u16Loop].triggered = (boolean)FALSE;
			}
			else if((DemInternalDebounceTimer[u16Loop].timeout >= \
					pDebounceTimer->DemDebounceTimePassedThreshold)\
				&& (DemInternalDebounceTimer[u16Loop].status == DEM_EVENT_STATUS_PREPASSED))
			{
				DemInternalDebounceTimer[u16Loop].status = DEM_EVENT_STATUS_PASSED;
				Dem_PassedEventHandle(DemInternalDebounceTimer[u16Loop].IntId);
				DemInternalDebounceTimer[u16Loop].triggered = (boolean)FALSE;
			}
			else
			{
				;
			}

			(void)Dem_InternalFDCCal(DemInternalDebounceTimer[u16Loop].IntId);

			if(Dem_ConfigPtr->DemEventParameter[DemInternalDebounceTimer[u16Loop].IntId].\
					DemDTCRef != 0xFFFFu)
			{
				s8FdcThreshold = (sint8)Dem_ConfigPtr->DemDTCAttributes[Dem_ConfigPtr->\
					DemDTC[Dem_ConfigPtr->DemEventParameter[DemInternalDebounceTimer[u16Loop].IntId].\
					DemDTCRef].DemDTCAttributesRef].DemEventMemoryEntryFdcThresholdStorageValue;
			}
			else
			{
				s8FdcThreshold = (sint8)127;
			}
			if(Dem_EventInternalData[DemInternalDebounceTimer[u16Loop].IntId].currentFDC >= s8FdcThreshold)
			{
				Dem_Enable_FDCReachThreshold(DemInternalDebounceTimer[u16Loop].IntId);
			}

#if(DEM_COMPONENT_NUM > 0)
			Dem_ComponentHandle(DemInternalDebounceTimer[u16Loop].IntId);
#endif /* #if(DEM_COMPONENT_NUM > 0) */

			Dem_TriggerEventMemory(DemInternalDebounceTimer[u16Loop].IntId,NULL_PTR);

			Dem_Disable_TFBitChange(DemInternalDebounceTimer[u16Loop].IntId);
			Dem_Disable_TFBitReset(DemInternalDebounceTimer[u16Loop].IntId);
			Dem_Disable_PDTCBitChange(DemInternalDebounceTimer[u16Loop].IntId);
			Dem_Disable_CDTCBitChange(DemInternalDebounceTimer[u16Loop].IntId);
			Dem_Disable_FDCReachThreshold(DemInternalDebounceTimer[u16Loop].IntId);
#if(DEM_DTC_NUM > 0)
			Dem_InternalDataUpdata(DemInternalDebounceTimer[u16Loop].IntId);
#endif /* #if(DEM_DTC_NUM > 0) */
		}
		u16Loop++;
	}
}
#endif /*#if((DEM_DEBOUNCE_TIME_BASED_SUPPORT == STD_ON) && (DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0u))*/

#if(DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM > 0)
/*
 * @brief        	Dem_EventDebounceCounterDeal
 * @details			Deal debounce counters in  Dem_MainfFunction
 */
STATIC FUNC(Dem_EventStatusType,DEM_CODE)Dem_EventDebounceCounterDeal
(
	P2CONST(Dem_EventBufferType,AUTOMATIC,DEM_VAR) pBuffer
)
{
	Dem_EventStatusType status = pBuffer->status; /* PRQA S 0781 #violate MISAR2004_5.6:'%1s' is being used as a 
                                                       * structure/union member as well as being a label,tag or ordinary 
                                                       * identifier. */

	Dem_DebounceCounterType* pDebounceCounter = &(Dem_InternalDebounceCounter[Dem_ConfigPtr->\
							   DemEventParameter[(pBuffer->eventId - 1u)].DemDebounceInfoIndex]);

	const Dem_DebounceCounterBasedClassType* pDebounceClass = &(Dem_ConfigPtr->\
			DemDebounceCounterBasedClass[Dem_ConfigPtr->DemEventParameter[(pBuffer->eventId - 1u)].\
										 DemDebounceAlgorithmRef]);

	if(status == DEM_EVENT_STATUS_PASSED)
	{
		/**
		 * @req [SWS_Dem_00421]  If the monitor reports DEM_EVENT_STATUS_PASSED,the Dem module shall
		 *      set the internal debounce counter value to its configured threshold being the passed
		 *      criteria.
		 */
		pDebounceCounter->counter = pDebounceClass->DemDebounceCounterPassedThreshold;
	}
	else if(status == DEM_EVENT_STATUS_FAILED)
	{
		/**
		 * @req [SWS_Dem_00420]	 If the monitor reports DEM_EVENT_STATUS_FAILED, the Dem module shall
		 *      set the internal debounce counter value to its configured threshold being the failed
		 *      criteria.
		 */
		pDebounceCounter->counter = pDebounceClass->DemDebounceCounterFailedThreshold;
	}
	else if(status == DEM_EVENT_STATUS_PREPASSED)
	{
		if((pDebounceCounter->status == DEM_EVENT_STATUS_FAILED) \
				|| (pDebounceCounter->status == DEM_EVENT_STATUS_PREFAILED)\
				|| (pDebounceCounter->status == DEM_EVENT_STATUS_PREPASSED))
		{
			if(pDebounceCounter->status != DEM_EVENT_STATUS_PREPASSED)
			{
				/**
				 * @req [SWS_Dem_00423] If the jump-down behavior is enabled, the Dem module shall
				 *      provide the configuration parameter DemDebounceCounterJumpDownValue defining
				 *      the new internal debounce counter init value. Each reporting of a pre-passed
				 *      value while the current debounce counter value is greater than the DemDebou-
				 *      nceCounterJumpDownValue shall first reset the debounce counter to DemDeboun-
				 *      ceCounterJumpDownValue before performing the pre-passed debounce event.
				 */
				if(pDebounceClass->DemDebounceCounterJumpDown == (boolean)TRUE)
				{
					if(pDebounceCounter->counter > pDebounceClass->DemDebounceCounterJumpDownValue)
					{
						pDebounceCounter->counter  = pDebounceClass->DemDebounceCounterJumpDownValue;
					}
				}
			}

			if((pDebounceClass->DemDebounceCounterPassedThreshold + ((sint16)pDebounceClass->\
					DemDebounceCounterDecrementStepSize)) >= pDebounceCounter->counter)
			{
				pDebounceCounter->counter = pDebounceClass->DemDebounceCounterPassedThreshold;
			}
			else
			{
				/**
				 * @req [SWS_Dem_00419] The Dem module shall decrement the internal debounce counter
				 *      with its configured step-size (refer to DemDebounceCounterDecrementStepSize),
				 *      when the monitor reports DEM_EVENT_STATUS_PREPASSED.
				 */
				pDebounceCounter->counter -= (sint16)pDebounceClass->\
						DemDebounceCounterDecrementStepSize;
			}
		}
		else
		{
			;
		}
	}
	else if(status == DEM_EVENT_STATUS_PREFAILED)
	{
		if((pDebounceCounter->status == DEM_EVENT_STATUS_PASSED) \
				|| (pDebounceCounter->status == DEM_EVENT_STATUS_PREFAILED)\
				|| (pDebounceCounter->status == DEM_EVENT_STATUS_PREPASSED))
		{
			if(pDebounceCounter->status != DEM_EVENT_STATUS_PREFAILED)
			{
				/**
				 * @req [SWS_Dem_00425] If the jump-up behavior is enabled,the Dem module
				 *      shall provide the configuration parameter DemDebounceCounterJump-
				 *      UpValue defining the new internal debounce counter init value.Each
				 *      reporting of a pre-failed value while the current debounce counter
				 *      value is smaller than the DemDebounceCounterJumpUpValue shall first
				 *      reset the debounce counter to DemDebounceCounterJumpUpValue before
				 *      performing the pre-failed debounce event.
				 */
				if(pDebounceClass->DemDebounceCounterJumpUp == (boolean)TRUE)
				{
					if(pDebounceCounter->counter < pDebounceClass->DemDebounceCounterJumpUpValue)
					{
						pDebounceCounter->counter  = pDebounceClass->DemDebounceCounterJumpUpValue;
					}
				}
			}

			if((pDebounceClass->DemDebounceCounterFailedThreshold - (sint16)pDebounceClass->\
					DemDebounceCounterIncrementStepSize) <= pDebounceCounter->counter)
			{
				pDebounceCounter->counter = pDebounceClass->DemDebounceCounterFailedThreshold;
			}
			else
			{
				/**
				 * @req [SWS_Dem_00419] The Dem module shall decrement the internal debounce counter
				 *      with its configured step-size (refer to DemDebounceCounterDecrementStepSize),
				 *      when the monitor reports DEM_EVENT_STATUS_PREPASSED.
				 */
				pDebounceCounter->counter += (sint16)pDebounceClass->\
						DemDebounceCounterIncrementStepSize;
			}
		}
	}
	else
	{
		;
	}

	if(pDebounceCounter->counter >= pDebounceClass->DemDebounceCounterFailedThreshold)
	{
		pDebounceCounter->counter = pDebounceClass->DemDebounceCounterFailedThreshold;
		pDebounceCounter->status = DEM_EVENT_STATUS_FAILED;
		status = DEM_EVENT_STATUS_FAILED;

	}
	else if(pDebounceCounter->counter <= pDebounceClass->DemDebounceCounterPassedThreshold)
	{
		pDebounceCounter->counter = pDebounceClass->DemDebounceCounterPassedThreshold;
		pDebounceCounter->status = DEM_EVENT_STATUS_PASSED;
		status = DEM_EVENT_STATUS_PASSED;
	}
	else
	{
		pDebounceCounter->status = status;
	}
	return status;
}
#endif /* #if(DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM > 0) */

#if(DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0)
/*
 * @brief        	Dem_EventDebounceCounterTimer
 * @details			Deal debounce timers in  Dem_MainfFunction
 */
STATIC FUNC(void,DEM_CODE)Dem_EventDebounceCounterTimer
(
	P2CONST(Dem_EventBufferType,AUTOMATIC,DEM_VAR)pBuffer
)
{
	Dem_EventIdType internalId = pBuffer->eventId - 1u;
	Dem_EventStatusType status = pBuffer->status;

	Dem_DebounceTimeType* pDebounceTimer = &(DemInternalDebounceTimer[Dem_ConfigPtr->\
							   DemEventParameter[internalId].DemDebounceInfoIndex]);

	const Dem_DebounceTimeBaseClassType* pDebounceClass = &(Dem_ConfigPtr->DemDebounceTimeBaseClass\
			[Dem_ConfigPtr->DemEventParameter[internalId].DemDebounceAlgorithmRef]);

	if(pDebounceTimer->isFreeze != (boolean)FALSE)
	{
		/**
		 * @req [SWS_Dem_00656] If an internal debounce timer is frozen and a new (valid) result is
		 *      reported for this event (as per [SWS_Dem_00428] / [SWS_Dem_00432]), the Dem module
		 *      shall continue running the internal debounce timer (from current value).
		 */
		if((Dem_ISEnable_EnableCondition(internalId) == (boolean)TRUE)\
				&& (Dem_ISEnable_DTCSetting(internalId) == (boolean)TRUE))
		{
			pDebounceTimer->isFreeze = (boolean)FALSE;
		}
	}

	if(status == DEM_EVENT_STATUS_PASSED)
	{
		/**
		 * @req [SWS_Dem_00435] If the monitor reports DEM_EVENT_STATUS_PASSED the Dem module shall set
		 *      the internal debounce timer value to its configured threshold being the passed criteria
		 *      (refer to DemDebounceTimePassedThreshold).
		 */
		pDebounceTimer->status =  DEM_EVENT_STATUS_PASSED;
		pDebounceTimer->timeout = pDebounceClass->DemDebounceTimePassedThreshold;
	}
	else if(status == DEM_EVENT_STATUS_FAILED)
	{
		/**
		 * @req [SWS_Dem_00431] If the monitor reports DEM_EVENT_STATUS_FAILED,the Dem module shall set
		 *      the internal debounce timer value to its configured threshold being the failed criteria
		 *      (refer to DemDebounceTimeFailedThreshold).
		 */
		pDebounceTimer->status =  DEM_EVENT_STATUS_FAILED;
		pDebounceTimer->timeout = pDebounceClass->DemDebounceTimeFailedThreshold;
	}
	else if(status == DEM_EVENT_STATUS_PREPASSED)
	{
		/**
		 * @req [SWS_Dem_00432] The Dem module shall start the internal debounce timer to qualify the
		 *      reported event as passed when the monitor reports DEM_EVENT_STATUS_PREPASSED.
		 *
		 * @req [SWS_Dem_00433] If the internal debounce timer of a specific event was already trigger-
		 *      ed as pre-passed or the event is qualified as passed,and the monitor reports consecuti-
		 *      vely DEM_EVENT_STATUS_PREPASSED again, the Dem module shall not restart the internal
		 *      debounce timer.
		 */
		if((pDebounceTimer->status == DEM_EVENT_STATUS_FAILED)\
				|| (pDebounceTimer->status == DEM_EVENT_STATUS_PREFAILED)\
				|| (pDebounceTimer->status == DEM_EVENT_STATUS_FDC_THRESHOLD_REACHED)\
				|| (pDebounceTimer->triggered == (boolean)FALSE))
		{
			pDebounceTimer->status = DEM_EVENT_STATUS_PREPASSED;
			pDebounceTimer->triggered = (boolean)TRUE;
			pDebounceTimer->timeout = 0U;
		}
	}
	else if(status == DEM_EVENT_STATUS_PREFAILED)
	{
		if((pDebounceTimer->status == DEM_EVENT_STATUS_PASSED)\
				|| (pDebounceTimer->status == DEM_EVENT_STATUS_PREPASSED)\
				|| (pDebounceTimer->triggered == (boolean)FALSE))
		{
			pDebounceTimer->status = DEM_EVENT_STATUS_PREFAILED;
			pDebounceTimer->triggered = (boolean)TRUE;
			pDebounceTimer->timeout = 0U;
		}
	}
	else
	{
		;
	}
}
#endif /* #if(DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0) */


/*
 * @brief        	Dem_EventDebounceDeal
 * @details			Deal event debounce in  Dem_MainfFunction which has added to event queue.
 *
 * @param[in]       pBuffer: Event queue node buffer,contain event id and event status which used to
 * 					handle event debounce.
 *
 * @return          Event status,when handle event debounce,its status will be changed.
 */
STATIC FUNC(Dem_EventStatusType,DEM_CODE)Dem_EventDebounceDeal
(
	P2CONST(Dem_EventBufferType,AUTOMATIC,DEM_VAR) pBuffer
)
{
	Dem_EventStatusType retVal = pBuffer->status;
	const Dem_EventParameterType* pEvtParam = &Dem_ConfigPtr->DemEventParameter[pBuffer->eventId-1u];
	sint8 s8FdcThreshold = (sint8)127;

	switch(pEvtParam->DemDebounceAlgorithmClassType)
	{
#if(DEM_DEBOUNCE_COUNTER_BASED_SUPPORT == STD_ON)
#if(DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM > 0)
	case DEM_DEBOUNCE_COUNTER_BASED:
		if(Dem_InternalDebounceCounter[pEvtParam->DemDebounceInfoIndex].isFreeze == (boolean)FALSE)
		{
			retVal = Dem_EventDebounceCounterDeal(pBuffer);
		}
		break;
#endif /* #if(DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM > 0) */
#endif /* #if(DEM_DEBOUNCE_COUNTER_BASED_SUPPORT == STD_ON) */

#if(DEM_DEBOUNCE_TIME_BASED_SUPPORT == STD_ON)
#if(DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0u)
	case DEM_DEBOUNCE_TIME_BASE:
		if(DemInternalDebounceTimer[pEvtParam->DemDebounceInfoIndex].isFreeze == (boolean)FALSE)
		{
			Dem_EventDebounceCounterTimer(pBuffer);
		}
		break;
#endif /* #if(DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0u) */
#endif /* #if(DEM_DEBOUNCE_TIME_BASED_SUPPORT == STD_ON) */

	case DEM_DEBOUNCE_MONITOR_INTERNAL:
		if(pBuffer->status == DEM_EVENT_STATUS_FDC_THRESHOLD_REACHED)
		{
			Dem_Enable_FDCReachThreshold(pBuffer->eventId-1u);
		}
		break;

	case DEM_NONE_DEBOUNCE:
		if(pBuffer->status == DEM_EVENT_STATUS_FAILED)
		{
			Dem_EventInternalData[pBuffer->eventId-1u].currentFDC = (sint8)127;
		}
		else if(pBuffer->status == DEM_EVENT_STATUS_PASSED)
		{
			Dem_EventInternalData[pBuffer->eventId-1u].currentFDC = (sint8)-128;
		}
		else
		{
			;
		}
		break;

	default:
		break;
	}

	(void)Dem_InternalFDCCal(pBuffer->eventId-1u);

#if(DEM_DTC_NUM > 0)
	if(pEvtParam->DemDTCRef != 0xFFFFu)
	{
		s8FdcThreshold = (sint8)Dem_ConfigPtr->DemDTCAttributes[Dem_ConfigPtr->DemDTC[pEvtParam->\
				DemDTCRef].DemDTCAttributesRef].DemEventMemoryEntryFdcThresholdStorageValue;
	}
#endif /* #if(DEM_DTC_NUM > 0) */

	if(Dem_EventInternalData[pBuffer->eventId-1u].currentFDC >= s8FdcThreshold)
	{
		Dem_Enable_FDCReachThreshold(pBuffer-> eventId-1u);
	}

	return retVal;
}

/*
 * @brief        	Dem_ReportStatusCheck
 * @details			Check event report condition whether fulfilled or not.
 *
 * @param[in]		InternalId: Internal event id,its value is equal to event id - 1.
 * @param[in]       pEventQueue: Event queue node,contain Dem module status when report
 * 					this event.
 *
 * @return          Result of this check.
 * @retval  		true: report condition fulfilled.
 * @retval  		false: report condition is not fulfilled,discard this report.
 */
STATIC FUNC(boolean, DEM_CODE)Dem_ReportStatusCheck
(
	Dem_EventIdType InternalId,
	P2CONST(Dem_EventBufferType,AUTOMATIC,DEM_VAR) pEventQueue
)
{
	boolean retVal = (boolean)FALSE;

	const Dem_EventParameterType*  pEventParameter = &(Dem_ConfigPtr->DemEventParameter[InternalId]);

	/* The monitor is not allowed to report the event states DEM_EVENT_STATUS_PREFAILED
	 * and DEM_EVENT_STATUS_PREPASSED for monitor internal debouncing */
	if((pEventParameter->DemDebounceAlgorithmClassType == DEM_DEBOUNCE_MONITOR_INTERNAL)\
				&&(pEventQueue->status != DEM_EVENT_STATUS_FAILED)\
				&&(pEventQueue->status != DEM_EVENT_STATUS_PASSED)\
				&&(pEventQueue->status != DEM_EVENT_STATUS_FDC_THRESHOLD_REACHED))
	{
#if (DEM_DEV_ERROR_DETECT == STD_ON)
		DEM_DET_ERROR_REPORT(DEM_SID_REPORTERRORSTATUS, DEM_E_WRONG_CONDITION);
#endif /* #if (DEM_DEV_ERROR_DETECT == STD_ON) */
	}
	else if(pEventQueue->reportStatus == DEM_STATE_UNINIT)
	{
#if (DEM_DEV_ERROR_DETECT == STD_ON)
		DEM_DET_ERROR_REPORT(DEM_SID_REPORTERRORSTATUS, DEM_E_UNINIT);
#endif /* #if (DEM_DEV_ERROR_DETECT == STD_ON) */
	}
	else if(pEventQueue->reportStatus == DEM_STATE_PRE_INIT)
	{
		if(pEventParameter->DemEventKind == DEM_EVENT_KIND_SWC)
		{
#if (DEM_DEV_ERROR_DETECT == STD_ON)
			DEM_DET_ERROR_REPORT(DEM_SID_REPORTERRORSTATUS, DEM_E_WRONG_CONDITION);
#endif /* #if (DEM_DEV_ERROR_DETECT == STD_ON) */
		}
		else /* DemEventKind == DEM_EVENT_KIND_BSW */
		{
			if(pEventParameter->DemReportBehavior != REPORT_BEFORE_INIT)
			{
#if (DEM_DEV_ERROR_DETECT == STD_ON)
				DEM_DET_ERROR_REPORT(DEM_SID_REPORTERRORSTATUS, DEM_E_WRONG_CONDITION);
#endif /* #if (DEM_DEV_ERROR_DETECT == STD_ON) */
			}
#if(DEM_OPERATIONCYCLE_STATUS_STORAGE == STD_ON)
/* DemDebounceCounterStorage can be set to TRUE when DemOperationCycleStatusStorage set to STD_ON. */
			else if((pEventParameter->DemDebounceAlgorithmClassType == DEM_DEBOUNCE_COUNTER_BASED)\
				&&(Dem_ConfigPtr->DemDebounceCounterBasedClass[pEventParameter->\
					   DemDebounceAlgorithmRef].DemDebounceCounterStorage == (boolean)TRUE))
			{
#if (DEM_DEV_ERROR_DETECT == STD_ON)
				DEM_DET_ERROR_REPORT(DEM_SID_REPORTERRORSTATUS, DEM_E_WRONG_CONDITION);
#endif /* #if (DEM_DEV_ERROR_DETECT == STD_ON) */
			}
#endif /* #if(DEM_OPERATIONCYCLE_STATUS_STORAGE == STD_ON) */
			else
			{
				retVal = (boolean)TRUE;
			}
		}
	}
	else /* reportStatus == DEM_STATE_INIT */
	{
		retVal = (boolean)TRUE;
	}

	return retVal;
}


/*
 * @brief        	Dem_EventQueueDeal
 * @details			Event queue asynchronous process in Dem_MainFunction.
 */
STATIC FUNC(void, DEM_CODE)Dem_EventQueueDeal
(
	void
)
{
	uint8 u8OpId;
	Dem_EventIdType u16InternalId;
	Dem_EventStatusType result;
	Dem_EventBufferType* pEventQueue = &(Dem_EventQueue[Dem_EventQueueRead]);

	while(Dem_EventQueue_ISAvailable(pEventQueue) == (boolean)TRUE)
	{
		u16InternalId = pEventQueue->eventId - 1u;
		u8OpId = Dem_ConfigPtr->DemEventParameter[u16InternalId].DemOperationCycleRef;

		if((boolean)TRUE == Dem_ReportStatusCheck(u16InternalId,pEventQueue))
		{
			/**
			 * @req [SWS_Dem_00626] When DTC setting is disabled, all status reports from SW-Cs
			 *      and BSW modules for those events being assigned to this specific DTC group
			 *      shall be ignored (no change of UDS DTC status byte) by the Dem.
			 *
			 * @req [SWS_Dem_01108] If an event is set to unavailable, the corresponding event
			 *      shall be treated as if it is not configured in the system.
			 *
			 * @req [SWS_Dem_00449] If one enable condition is not fulfilled, all status reports
			 *      from SWCs and BSW modules for those events being assigned to this condition
			 *      shall be ignored (no change of UDS DTC status byte) by the Dem.
			 */
			if((Dem_ISEnable_EventAvaliable(u16InternalId) == (boolean)TRUE)\
					&& (Dem_ISEnable_DTCSetting(u16InternalId) == (boolean)TRUE)
#if(DEM_ENABLE_CONDITION_NUM > 0)
					&& (Dem_ISEnable_EnableCondition(u16InternalId) == (boolean)TRUE)
#endif /* #if(DEM_ENABLE_CONDITION_NUM > 0) */
			)
			{
				/**
				 * @req [SWS_Dem_00481] If an operation cycle has started,all status reports from
				 *      SW-Cs and BSW modules for those events,being assigned to this cycle,shall
				 *      be accepted by the Dem from this point in time on.
				 *
				 * @req [SWS_Dem_00700] If the OBD driving cycle has ended, status reports shall
				 *      be processed, except update of the confirmed status.
				 */
				if((Dem_ISEnable_OperationCycle(u8OpId) == (boolean)TRUE)
#if(DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT)
					|| (Dem_General.DemOperationCycle[u8OpId].DemOperationCycleType == DEM_OPCYC_OBD_DCY)
#endif /* #if(DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT) */
					)
				{
					/**
					 * @req [SWS_Dem_00854] The operation cycle state shall be evaluated, when
					 *      processing the events from the queue.If the operation cycle related
					 *      to that event is started, the event shall be processed regularly (
					 *      similar to Dem_SetEventStatus);otherwise in case the operation cycle
					 *      is not started the event shall be dropped and the debounce counter
					 *      shall be reset to zero.
					 */
#if(DEM_ENVIRONMENT_DATA_CAPTURE == DEM_CAPTURE_SYNCHRONOUS_TO_REPORTING)
					if(pEventQueue->captureData == (boolean)FALSE)
#endif  /* #if(DEM_ENVIRONMENT_DATA_CAPTURE == DEM_CAPTURE_SYNCHRONOUS_TO_REPORTING) */
					{
#if(DEM_FREEZEFRAME_ENABLE == STD_ON)
						Dem_CaptureFreezeFrame(u16InternalId,pEventQueue->FFData);
#endif /* #if(DEM_FREEZEFRAME_ENABLE == STD_ON) */
#if(DEM_EXTENDED_DATA_CLASS_NUM > 0)
						Dem_CaptureExtendedData(u16InternalId,pEventQueue->ExtData);
#endif /* #if(DEM_EXTENDED_DATA_CLASS_NUM > 0) */
#if(DEM_PID_CLASS_NUM > 0)
						Dem_CapturePidClass(u16InternalId,pEventQueue->PidData);
#endif /* #if(DEM_PID_CLASS_NUM > 0) */
#if(DEM_ENVIRONMENT_DATA_CAPTURE == DEM_CAPTURE_SYNCHRONOUS_TO_REPORTING)
						pEventQueue->captureData = (boolean)TRUE;
#endif  /* #if(DEM_ENVIRONMENT_DATA_CAPTURE == DEM_CAPTURE_SYNCHRONOUS_TO_REPORTING) */
					}

					result = Dem_EventDebounceDeal(pEventQueue);

					if(result == DEM_EVENT_STATUS_FAILED)
					{
						Dem_FailedEventHandle(u16InternalId);
					}
					else if(result == DEM_EVENT_STATUS_PASSED)
					{
						Dem_PassedEventHandle(u16InternalId);
					}
					else
					{
						;
					}

#if(DEM_COMPONENT_NUM > 0)
					Dem_ComponentHandle(u16InternalId);
#endif /* #if(DEM_COMPONENT_NUM > 0) */

#if(DEM_DTC_NUM > 0)
					if((boolean)TRUE == Dem_ISEnable_StorageCondition(u16InternalId))
					{
						Dem_TriggerEventMemory(u16InternalId,pEventQueue);
					}
#endif /* #if(DEM_DTC_NUM > 0) */
				}
				else
				{
					/**
					 * @req [SWS_Dem_00854] The operation cycle state shall be evaluated,
					 * 		when processing the events from the queue. If the operation
					 * 		cycle related to that event is started,the event shall be
					 * 		processed regularly (similar to Dem_SetEventStatus); otherwise
					 * 		in case the operation cycle is not started the event shall be
					 * 		dropped and the debounce counter shall be reset to zero.
					 */
					Dem_DebounceReset(u16InternalId,(boolean)TRUE);
				}
#if(DEM_DTC_NUM > 0)
				Dem_SetCombineDtcStatus(u16InternalId);
				Dem_InternalDataUpdata(u16InternalId);
#endif /* #if(DEM_DTC_NUM > 0) */
			}
			else
			{
				/**
				 * @req [SWS_Dem_00626] When DTC setting is disabled, all status reports from
				 *      SW-Cs and BSW modules for those events being assigned to this specific
				 *      DTC group shall be ignored(no change of UDS DTC status byte)by the Dem.
				 *      This is similar like the enable condition handling. In case of Dem
				 *      internal debouncing the related fault detection counter will be frozen
				 *      or reset.
				 */
				Dem_InternalDebounceHandle(u16InternalId);
			}
		}
		pEventQueue = Dem_EventQueue_Remove(pEventQueue,&Dem_EventQueueRead);
	}
}

#if((DEM_DEBOUNCE_COUNTER_BASED_EVENT_NUM > 0) || (DEM_DEBOUNCE_TIME_BASED_EVENT_NUM > 0))
/*
 * @brief        	Dem_RecoverFreezeCheck
 * @details			Check event enable conditions and dtc setting status.
 *
 * @param[in]		IntId: Internal event id,its value is equal to event id - 1.
 */
STATIC FUNC(boolean, DEM_CODE)Dem_RecoverFreezeCheck
(
	Dem_EventIdType IntId
)
{
	boolean ret = (boolean)TRUE;
	uint8 u8Ret = 0x01u;
#if(DEM_ENABLE_CONDITION_NUM > 0)
	if(Dem_ISEnable_EnableCondition(IntId) == (boolean)FALSE)
	{
		u8Ret = 0x00u;
	}
#endif

#if(DEM_DTC_NUM > 0)
	if(Dem_ISEnable_DTCSetting(IntId) == (boolean)FALSE)
	{
		u8Ret = 0x00u; 
	}
#endif
	if(u8Ret == 0x00u)
	{
		ret = (boolean)FALSE;
	}
	return ret;
}

/*
 * @brief        	Dem_RecoverFreeze
 * @details			Cancel debounce freeze status.
 */
STATIC FUNC(void, DEM_CODE)Dem_RecoverFreeze
(
	void
)
{
	uint16 u16Loop = 0u;

	do
	{
		if(Dem_ConfigPtr->DemEventParameter[u16Loop].DemDebounceAlgorithmClassType \
				== DEM_DEBOUNCE_COUNTER_BASED)
		{
#if(DEM_DEBOUNCE_COUNTER_BASED_EVENT_NUM > 0)
			if(Dem_InternalDebounceCounter[Dem_ConfigPtr->DemEventParameter[u16Loop].\
										   DemDebounceInfoIndex].isFreeze == (boolean)TRUE)
			{
				if((boolean)TRUE == Dem_RecoverFreezeCheck(u16Loop))
				{
					Dem_InternalDebounceCounter[Dem_ConfigPtr->DemEventParameter[u16Loop].\
											   DemDebounceInfoIndex].isFreeze = (boolean)FALSE;
				}
			}
#endif /* #if(DEM_DEBOUNCE_COUNTER_BASED_EVENT_NUM > 0) */
		}
		else if(Dem_ConfigPtr->DemEventParameter[u16Loop].DemDebounceAlgorithmClassType \
				== DEM_DEBOUNCE_TIME_BASE)
		{
#if(DEM_DEBOUNCE_TIME_BASED_EVENT_NUM > 0)
			if(DemInternalDebounceTimer[Dem_ConfigPtr->DemEventParameter[u16Loop].\
										   DemDebounceInfoIndex].isFreeze == (boolean)TRUE)
			{
				if((boolean)TRUE == Dem_RecoverFreezeCheck(u16Loop))
				{
					DemInternalDebounceTimer[Dem_ConfigPtr->DemEventParameter[u16Loop].\
											   DemDebounceInfoIndex].isFreeze = (boolean)FALSE;
				}
			}
#endif /* #if(DEM_DEBOUNCE_TIME_BASED_EVENT_NUM > 0) */
		}
		else
		{
			;
		}
		u16Loop++;
	}while(u16Loop < DEM_EVENT_PARAMETER_NUM);
}
#endif /* #if((DEM_DEBOUNCE_COUNTER_BASED_EVENT_NUM > 0) || (DEM_DEBOUNCE_TIME_BASED_EVENT_NUM > 0)) */

#if(DEM_COMPONENT_NUM > 0)
/*
 * @brief        	Dem_SetChildComponentFailed
 * @details			set all components status to Failed.Note:this is a recursive function
 */
STATIC FUNC(void, DEM_CODE)Dem_SetChildComponentFailed
(
	Dem_ComponentIdType	ComponentIndex
)
{
	Dem_ComponentIdType loop;
	const Dem_ComponentType* pComponent = &(Dem_ConfigPtr->DemComponent[ComponentIndex]);

	if(Dem_IsEnable_ComponentAvailable(ComponentIndex))
	{
		if((boolean)FALSE == Dem_IsEnable_ComponentStatus(ComponentIndex))
		{
			Dem_Enable_ComponentStatus(ComponentIndex);

#if(DEM_TRIGGER_FIM_REPORTS == STD_ON)
			/**
			 * @req [SWS_Dem_01132] If DemTriggerFimReports (refer to DemGeneral) is enabled, the
			 * 		Dem shall notify the FiM module [8] on each change of DemComponent failed status
			 * 		by calling the function FiM_DemTriggerOnComponentStatus.
			 * @req [SWS_Dem_01133] The Dem shall allow defining a callback per DemComponent
			 * 		(DemComponent FailedCallbackFnc; <Module>_DemTriggerOnComponentStatus),which
			 * 		shall be called on a change of the components FAILED status.
			 */
			if(pComponent->DemComponentFailedCallbackFnc != NULL_PTR)
			{
				(void)pComponent->DemComponentFailedCallbackFnc((ComponentIndex + 1u),(boolean)TRUE);
			}
#endif /* #if(DEM_TRIGGER_FIM_REPORTS == STD_ON) */
		}

		for(loop = 0u; loop < pComponent->DemDemChildComponentRefNum; loop++)
		{
			Dem_SetChildComponentFailed(pComponent->DemImmediateChildComponentRef[loop]);
		}
	}
}

/*
 * @brief        	Dem_ComponentHandle
 * @details			Check whether the event is consecutive fault.
 */
STATIC FUNC(void, DEM_CODE)Dem_ComponentHandle
(
	Dem_EventIdType	InternalId
)
{
	uint16 u16Loop;
	Dem_ComponentIdType loop;
	boolean IsFailed = (boolean)FALSE;
	Dem_ComponentIdType componentRef = Dem_ConfigPtr->DemEventParameter[InternalId].DemComponentClassRef;
	const Dem_ComponentType* pComponent = &(Dem_ConfigPtr->DemComponent[componentRef]);

	if(Dem_IsEnable_ComponentAvailable(componentRef))
	{
		/**
		 * @req [SWS_Dem_01127] Whenever an event reports FAILED, it shall be considered as
		 * 		CONSECUTIVE FAULT, if any parent DemComponent is FAILED.
		 */
		for(loop = 0u; loop < pComponent->DemDemParentComponentRefNum; loop++)
		{
			if(Dem_IsEnable_ComponentAvailable(pComponent->DemParentComponentRef[loop]))
			{
				if(Dem_IsEnable_ComponentStatus(pComponent->DemParentComponentRef[loop]))
				{
					IsFailed = (boolean)TRUE;
					Dem_Enable_ConsecutiveFault(InternalId);
					break;
				}
			}
		}

		/**
		 * @req [SWS_Dem_01126] Whenever an event reports FAILED, it shall be considered as
		 * 		CONSECUTIVE FAULT, if any other event with higher priority at the same
		 * 		DemComponent already is FAILED
		 * @req [SWS_Dem_01128] The Dem shall allow to ignore the priority of events of a
		 * 		DemComponentIgnoresPriority). In this case, the event shall only be considered
		 * 		as CONSECUTIVE FAULT if any parent component is FAILED (other events FAILED
		 * 		status at the same component shall be ignored).
		 */
		if((pComponent->DemComponentIgnoresPriority == (boolean)FALSE) \
				&&((boolean)FALSE == Dem_ISEnable_ConsecutiveFault(InternalId)))
		{
			for(u16Loop = 0u; u16Loop < DEM_EVENT_PARAMETER_NUM; u16Loop++)
			{
				if(Dem_ConfigPtr->DemEventParameter[u16Loop].DemComponentClassRef == componentRef)
				{
					if(Dem_ISEnable_UdsStatusBits(u16Loop,DEM_UDS_STATUS_TF))
					{
						IsFailed = (boolean)TRUE;
						if(Dem_ConfigPtr->DemEventParameter[u16Loop].DemComponentPriority < \
							Dem_ConfigPtr->DemEventParameter[InternalId].DemComponentPriority)
						{
							Dem_Enable_ConsecutiveFault(InternalId);
						}
					}
				}
			}
		}

		/**
		 * @req [SWS_Dem_01125] A DemComponent shall be set to NOT FAILED, when all
		 * 		assigned events are NOT FAILED and all parent components are NOT FAILED.
		 */
		if(IsFailed == (boolean)FALSE)
		{
			if((boolean)TRUE == Dem_IsEnable_ComponentStatus(componentRef))
			{
				Dem_Disable_ComponentStatus(componentRef);

#if(DEM_TRIGGER_FIM_REPORTS == STD_ON)
			if(pComponent->DemComponentFailedCallbackFnc != NULL_PTR)
			{
				(void)pComponent->DemComponentFailedCallbackFnc((componentRef + 1u),(boolean)FALSE);
			}
#endif /* #if(DEM_TRIGGER_FIM_REPORTS == STD_ON) */
			}
		}
	}
}
#endif /* #if(DEM_COMPONENT_NUM > 0) */

#if(DEM_NVRAM_BLOCKID_NUM > 0)
/*
 * @brief        	Dem_WriteToNvRAM
 * @details			Write memory entrys and other datas to non-volatile memory.
 */
STATIC FUNC(void, DEM_CODE)Dem_WriteToNvRAM
(
	void
)
{
	uint16 u16InfoIndex = 0u;
	uint16 u16Loop = 0u;
	uint16 u16BlockRef;
	NvM_RequestResultType result = NVM_REQ_PENDING;

	do
	{
		u16BlockRef = Dem_General.DemNvRamBlockId[u16InfoIndex];

		(void)NvM_GetErrorStatus(u16BlockRef,&result);
		if(result != NVM_REQ_PENDING)
		{
			(void)NvM_WriteBlock(u16BlockRef,&DemPrimaryMemory[u16Loop]);
		}
		else
		{
			Dem_NvMPending = (boolean)TRUE;
		}
		u16InfoIndex++; /* PRQA S 2984 #violate MISAR2004_21.1:the value of the result will bigger than 1
                                * when DEM_MAX_NUMBER_EVENTENTRY_PRIMARY bigger than 1 */
		u16Loop++; /* PRQA S 2984 #violate MISAR2004_21.1:the value of the result will bigger than 1
                           * when DEM_MAX_NUMBER_EVENTENTRY_PRIMARY bigger than 1 */
	}while(u16Loop < DEM_MAX_NUMBER_EVENTENTRY_PRIMARY); /* PRQA S 2996,2993 #violate MISAR2004_13.7:The result
                                                             * of this logical operation is variable,and this loop
                                                             * will excute more than once */

#if(DEM_MAX_NUMBER_EVENTENTRY_PERMANENT > 0)
	u16Loop = 0u;
	do
	{
		if(DemPermanentMemory[u16Loop].EventId != 0u)
		{
			u16BlockRef = Dem_General.DemNvRamBlockId[u16InfoIndex];
			(void)NvM_GetErrorStatus(u16BlockRef,&result);
			if(result != NVM_REQ_PENDING)
			{
				(void)NvM_WriteBlock(u16BlockRef,&DemPermanentMemory[u16Loop]);
			}
		}
		u16InfoIndex++;
		u16Loop++;
	}while(u16Loop < DEM_MAX_NUMBER_EVENTENTRY_PERMANENT);
#endif /* #if(DEM_MAX_NUMBER_EVENTENTRY_PERMANENT > 0) */

	u16BlockRef = Dem_General.DemNvRamBlockId[u16InfoIndex];

	(void)NvM_GetErrorStatus(u16BlockRef,&result);
	if(result != NVM_REQ_PENDING)
	{
		(void)NvM_WriteBlock(u16BlockRef,Dem_EventUDSBitStatus);
	}
	else
	{
		Dem_NvMPending = (boolean)TRUE;
	}

#if(DEM_NVRAM_DEBOUNCE_INFO_NUM > 0)
	u16InfoIndex++; /* PRQA S 2984 #violate MISAR2004_21.1:the value of the result will bigger than 2
                        * when DEM_MAX_NUMBER_EVENTENTRY_PRIMARY bigger than 1 */
	u16Loop = 0u;
	u16BlockRef = Dem_General.DemNvRamBlockId[u16InfoIndex];
	do
	{
		Dem_NvRAMDebounceCnt[u16Loop] =\
				Dem_InternalDebounceCounter[Dem_NvRAMDebounceInfo[u16Loop]].counter;
		u16Loop++;
	}while(u16Loop < DEM_NVRAM_DEBOUNCE_INFO_NUM);

	(void)NvM_GetErrorStatus(u16BlockRef,&result);
	if(result != NVM_REQ_PENDING)
	{
		(void)NvM_WriteBlock(u16BlockRef,Dem_NvRAMDebounceCnt);
	}
#endif /* #if(DEM_NVRAM_DEBOUNCE_INFO_NUM > 0) */

#if(DEM_OPERATIONCYCLE_STATUS_STORAGE == STD_ON)
	u16InfoIndex++;
	u16BlockRef = Dem_General.DemNvRamBlockId[u16InfoIndex];

	(void)NvM_GetErrorStatus(u16BlockRef,&result);
	if(result != NVM_REQ_PENDING)
	{
		(void)NvM_WriteBlock(u16BlockRef,Dem_OperationCycleStatus);
	}
#endif /* DEM_OPERATIONCYCLE_STATUS_STORAGE */

#if(DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU)
	u16InfoIndex++;
	u16BlockRef = Dem_General.DemNvRamBlockId[u16InfoIndex];
	(void)NvM_GetErrorStatus(u16BlockRef,&result);
	if(result != NVM_REQ_PENDING)
	{
		(void)NvM_WriteBlock(u16BlockRef,&Dem_B1Counter);
	}

	u16InfoIndex++;
	u16BlockRef = Dem_General.DemNvRamBlockId[u16InfoIndex];
	(void)NvM_GetErrorStatus(u16BlockRef,&result);
	if(result != NVM_REQ_PENDING)
	{
		(void)NvM_WriteBlock(u16BlockRef,&Dem_ConMICounter);
	}

	u16InfoIndex++;
	u16BlockRef = Dem_General.DemNvRamBlockId[u16InfoIndex];
	(void)NvM_GetErrorStatus(u16BlockRef,&result);
	if(result != NVM_REQ_PENDING)
	{
		(void)NvM_WriteBlock(u16BlockRef,&Dem_CumConMICounter);
	}
#endif /* #if(DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU) */
}
#endif /* #if(DEM_NVRAM_BLOCKID_NUM > 0) */

/*
 * @brief        	Dem_PendingDeal
 * @details			If write to non-volatile memory pending or clear non-volatile memory
 * 					pending, Dem will try it again in Dem_MainFunction.
 */
STATIC FUNC(void, DEM_CODE)Dem_PendingDeal
(
	void
)
{
#if(DEM_NVRAM_BLOCKID_NUM > 0)
	NvM_RequestResultType result = NVM_REQ_NOT_OK;

	if(Dem_NvMPending == (boolean)TRUE)
	{
		(void)NvM_GetErrorStatus(Dem_General.DemNvRamBlockId[0],&result);

		if(result != NVM_REQ_PENDING)
		{
			Dem_WriteToNvRAM();
			Dem_NvMPending = (boolean)FALSE;
		}
	}
#endif /* #if(DEM_NVRAM_BLOCKID_NUM > 0) */
}

#if(DEM_CALLBACK_INIT_MFOREFNC_TOTALNUM > 0)
/*
 * @brief        	Dem_InitMonitorCbkDeal
 * @details			Initialize Dem_InitMonitorCbkStatus which record DemCallbackInitMForEFnc
 * 					function's input parameter reason.
 */
STATIC FUNC(void, DEM_CODE)Dem_InitMonitorCbkDeal
(
	void
)
{
	uint16 u16Loop = 0u;

	do
	{
		if(Dem_InitMonitorCbkStatus[u16Loop] != 0u)
		{
			(void)Dem_ConfigPtr->DemEventParameter[u16Loop].DemCallbackInitMForE->\
					DemCallbackInitMForEFnc(Dem_InitMonitorCbkStatus[u16Loop]);

			Dem_InitMonitorCbkStatus[u16Loop] = 0u;
		}
		u16Loop++;
	}while(u16Loop < DEM_EVENT_PARAMETER_NUM);
}
#endif /* #if(DEM_CALLBACK_INIT_MFOREFNC_TOTALNUM > 0) */

#if(DEM_NVRAM_BLOCKID_NUM > 0)
/*
 * @brief        	Dem_ReadFromNvRAM
 * @details			Read data from non-volatile memory when dem initialize.
 */
STATIC FUNC(void, DEM_CODE) Dem_ReadFromNvRAM
(
	void
)
{
	uint16 u16InfoIndex = 0u;
	uint16 u16Loop = 0u;
	uint16 u16BlockRef;
	Dem_EventIdType internalId;
	NvM_RequestResultType result = NVM_REQ_PENDING;
	Std_ReturnType ret;
	uint32 u32CopyLen;

	do
	{
		u16BlockRef = Dem_General.DemNvRamBlockId[u16InfoIndex];

		ret = NvM_GetErrorStatus(u16BlockRef,&result);
		u16BlockRef--;
		if((result != NVM_REQ_PENDING) && (ret == (Std_ReturnType)E_OK))
		{
			u32CopyLen = sizeof(Dem_MemoryEntryType);

			DEM_VALUE_COPY(\
					(uint8*)(&DemPrimaryMemory[u16Loop]),\
					NvM_Config.NvM_BlockDescriptor[u16BlockRef].NvM_RamBlockDataAddress,\
					u32CopyLen);

			if(DemPrimaryMemory[u16Loop].EventId != 0u)
			{
				internalId = DemPrimaryMemory[u16Loop].EventId - 1u;

				Dem_EventInternalData[internalId].agingUpCnt = \
						DemPrimaryMemory[u16Loop].AgingCounter;

				Dem_EventInternalData[internalId].failedCycles = \
						DemPrimaryMemory[u16Loop].FailureCounter;

				Dem_EventInternalData[internalId].healingCnt = \
						DemPrimaryMemory[u16Loop].HealingCounter;

				Dem_EventInternalData[internalId].occurCnt = \
						DemPrimaryMemory[u16Loop].OccurrenceCounter;

				Dem_EventInternalData[internalId].cyclesSinceLastFailed = \
						DemPrimaryMemory[u16Loop].CyclesSinceLastFailed;

				Dem_EventInternalData[internalId].cyclesSinceFirstFailed = \
						DemPrimaryMemory[u16Loop].CyclesSinceFirstFailed;
			}
		}
		u16InfoIndex++; /* PRQA S 2984 #violate MISAR2004_21.1: The value of the result is variable */
		u16Loop++;  /* PRQA S 2984 #violate MISAR2004_21.1: The value of the result is variable */
	}while(u16Loop < DEM_MAX_NUMBER_EVENTENTRY_PRIMARY); /* PRQA S 2996,2993 #violate MISAR2004_13.7:The result
                                                             * of this logical operation is variable,and this loop
                                                             * will excute more than once */
#if(DEM_MAX_NUMBER_EVENTENTRY_PERMANENT > 0)
	u16Loop = 0u;
	do
	{
		u16BlockRef = Dem_General.DemNvRamBlockId[u16InfoIndex];
		ret = NvM_GetErrorStatus(u16BlockRef,&result);
		u16BlockRef--;
		if((result != NVM_REQ_PENDING) && (ret == (Std_ReturnType)E_OK))
		{
			u32CopyLen = sizeof(Dem_MemoryEntryType);
			DEM_VALUE_COPY(\
					&DemPermanentMemory[u16Loop],\
					NvM_Config.NvM_BlockDescriptor[u16BlockRef].NvM_RamBlockDataAddress,\
					u32CopyLen);

			if(DemPrimaryMemory[u16Loop].EventId != 0u)
			{
				internalId = DemPrimaryMemory[u16Loop].EventId - 1u;

				Dem_EventInternalData[internalId].agingUpCnt = \
						DemPrimaryMemory[u16Loop].AgingCounter;

				Dem_EventInternalData[internalId].failedCycles = \
						DemPrimaryMemory[u16Loop].FailureCounter;

				Dem_EventInternalData[internalId].healingCnt = \
						DemPrimaryMemory[u16Loop].HealingCounter;

				Dem_EventInternalData[internalId].occurCnt = \
						DemPrimaryMemory[u16Loop].OccurrenceCounter;

				Dem_EventInternalData[internalId].cyclesSinceLastFailed = \
						DemPrimaryMemory[u16Loop].CyclesSinceLastFailed;

				Dem_EventInternalData[internalId].cyclesSinceFirstFailed = \
						DemPrimaryMemory[u16Loop].CyclesSinceFirstFailed;
			}
		}
		u16InfoIndex++;
		u16Loop++;
	}while(u16Loop < DEM_MAX_NUMBER_EVENTENTRY_PERMANENT);
#endif /* #if(DEM_MAX_NUMBER_EVENTENTRY_PERMANENT > 0) */

	u16BlockRef = Dem_General.DemNvRamBlockId[u16InfoIndex];
	ret = NvM_GetErrorStatus(u16BlockRef,&result);
	u16BlockRef--;
	if((result != NVM_REQ_PENDING) && (ret == (Std_ReturnType)E_OK))
	{
		u32CopyLen = sizeof(Dem_UdsStatusByteType) * DEM_EVENT_PARAMETER_NUM;
		DEM_VALUE_COPY(\
				Dem_EventUDSBitStatus,\
				NvM_Config.NvM_BlockDescriptor[u16BlockRef].NvM_RamBlockDataAddress,\
				u32CopyLen);
	}

#if(DEM_NVRAM_DEBOUNCE_INFO_NUM > 0)
	u16InfoIndex++; /* PRQA S 2984 #violate MISAR2004_21.1: The value of the result is variable */
	u16Loop = 0u;
	u16BlockRef = Dem_General.DemNvRamBlockId[u16InfoIndex];

	ret = NvM_GetErrorStatus(u16BlockRef,&result);
	u16BlockRef--;
	if((result != NVM_REQ_PENDING) && (ret == (Std_ReturnType)E_OK))
	{
		u32CopyLen = sizeof(sint8) * DEM_NVRAM_DEBOUNCE_INFO_NUM;
		DEM_VALUE_COPY(\
				Dem_NvRAMDebounceCnt,\
				NvM_Config.NvM_BlockDescriptor[u16BlockRef].NvM_RamBlockDataAddress,\
				u32CopyLen);
	}

	do
	{
		Dem_InternalDebounceCounter[Dem_NvRAMDebounceInfo[u16Loop]].counter \
		             = Dem_NvRAMDebounceCnt[u16Loop];
		u16Loop++;
	}while(u16Loop < DEM_NVRAM_DEBOUNCE_INFO_NUM);
#endif /* #if(DEM_NVRAM_DEBOUNCE_INFO_NUM > 0) */

#if(DEM_OPERATIONCYCLE_STATUS_STORAGE == STD_ON)
	u16InfoIndex++; /* PRQA S 2984 #violate MISAR2004_21.1: The value of the result is variable */
	u16Loop = 0u;
	u16BlockRef = Dem_General.DemNvRamBlockId[u16InfoIndex];

	ret = NvM_GetErrorStatus(u16BlockRef,&result);
	u16BlockRef--;
	if((result != NVM_REQ_PENDING) && (ret == (Std_ReturnType)E_OK))
	{
		u32CopyLen = sizeof(uint8) * DEM_OPERATION_CYCLE_NUM_BYTE;
		DEM_VALUE_COPY(\
				Dem_OperationCycleStatus,\
				NvM_Config.NvM_BlockDescriptor[u16BlockRef].NvM_RamBlockDataAddress,\
				u32CopyLen);
	}
#endif /* DEM_OPERATIONCYCLE_STATUS_STORAGE */

#if(DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU)
	u16InfoIndex++;
	u16BlockRef = Dem_General.DemNvRamBlockId[u16InfoIndex];
	ret = NvM_GetErrorStatus(u16BlockRef,&result);
	u16BlockRef--;
	if((result != NVM_REQ_PENDING) && (ret == (Std_ReturnType)E_OK))
	{
		u32CopyLen = sizeof(uint16);
		DEM_VALUE_COPY(\
				&Dem_B1Counter,\
				NvM_Config.NvM_BlockDescriptor[u16BlockRef].NvM_RamBlockDataAddress,\
				u32CopyLen);
	}

	u16InfoIndex++;
	u16BlockRef = Dem_General.DemNvRamBlockId[u16InfoIndex];
	ret = NvM_GetErrorStatus(u16BlockRef,&result);
	u16BlockRef--;
	if((result != NVM_REQ_PENDING) && (ret == (Std_ReturnType)E_OK))
	{
		u32CopyLen = sizeof(uint16);
		DEM_VALUE_COPY(\
				&Dem_ConMICounter,\
				NvM_Config.NvM_BlockDescriptor[u16BlockRef].NvM_RamBlockDataAddress,\
				u32CopyLen);
	}

	u16InfoIndex++;
	u16BlockRef = Dem_General.DemNvRamBlockId[u16InfoIndex];
	ret = NvM_GetErrorStatus(u16BlockRef,&result);
	u16BlockRef--;
	if((result != NVM_REQ_PENDING) && (ret == (Std_ReturnType)E_OK))
	{
		u32CopyLen = sizeof(uint16);
		DEM_VALUE_COPY(\
				&Dem_CumConMICounter,\
				NvM_Config.NvM_BlockDescriptor[u16BlockRef].NvM_RamBlockDataAddress,\
				u32CopyLen);
	}
#endif /* #if(DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU) */
}
#endif /* #if(DEM_NVRAM_BLOCKID_NUM > 0) */

/*
 * @brief        	Dem_EventMemoryInit
 * @details			Initialize primary memory and event uds status.
 */
STATIC FUNC(void, DEM_CODE) Dem_EventMemoryInit
(
	void
)
{
	uint8 u8EntryNum = 0u;
	uint16 u16Loop = 0u;
	Dem_MemoryEntryType* pEntry = Dem_GetMemoryConf(DEM_DTC_ORIGIN_PRIMARY_MEMORY,&u8EntryNum);
	do
	{
		if(pEntry->EventId == 0u)
		{
			(void)Dem_DeleMemoryEntry(DEM_DTC_ORIGIN_PRIMARY_MEMORY,pEntry);
		}
		pEntry++; /* PRQA S 2983 #violate MISAR2004_21.1: The value of this object will be 
				   * subsequently used when u8EntryNum is bigger than 1 */
		u16Loop++; /* PRQA S 2984 #violate MISAR2004_21.1: The value of the result is variable */
	}while(u16Loop < u8EntryNum); /* PRQA S 2996,2993 #violate MISAR2004_13.7:The result
                                      * of this logical operation is variable,and this loop
                                      * will excute more than once */

		for(u16Loop = 0u; u16Loop < DEM_EVENT_PARAMETER_NUM; u16Loop++)
		{
#if(DEM_STATUS_BITSTORAGE_TESTFAILED == STD_OFF)
			/**
			 * @req [SWS_Dem_00388] If the configuration parameter DemStatusBitStorageTestFailed
			 *      is set to False, the Dem module shall not retain the information for UDS DTC
			 *      status bit 0 (TestFailed) over power cycles (volatile).
			 */
			Dem_EventUDSBitStatus[u16Loop] &= 0xFEu;
#else
			if((boolean)TRUE == Dem_ISEnable_UdsStatusBits(u16Loop,DEM_UDS_STATUS_TF))
			{
				Dem_Enable_EventActive(u16Loop);
			}
#endif /* #if(DEM_STATUS_BITSTORAGE_TESTFAILED == STD_OFF) */

			if(Dem_EventUDSBitStatus[u16Loop] == 0u)
			{
				Dem_EventUDSBitStatus[u16Loop] = 0x50u;
			}
		}

	return;
}

#if((DEM_ENABLE_CONDITION_GROUP_NUM > 0) || (DEM_STORAGE_CONDITION_GROUP_NUM > 0))
/*
 * @brief        	Dem_EventConditionInit
 * @details			Using configuration to initialize enable conditions and storage conditions.
 */
STATIC FUNC(void, DEM_CODE) Dem_EventConditionInit
(
	Dem_EventIdType internalId
)
{
	const uint8*  pGroup = NULL_PTR;
	const Dem_EventParameterType* pEventPara = &(Dem_ConfigPtr->DemEventParameter[internalId]);

#if(DEM_ENABLE_CONDITION_GROUP_NUM > 0)
	if(pEventPara->DemEnableConditionGroupRef != 0xFFu)
	{
		pGroup = Dem_General.DemEnableConditionGroup[pEventPara->DemEnableConditionGroupRef];

		if((boolean)TRUE == Dem_ConditionIsFulFilled(Dem_EnableConditionStatus,pGroup,DEM_ENABLE_CONDITION_NUM_BYTE))
		{
			Dem_Enable_EnableCondition(internalId);
		}
	}
	else
#endif /* #if(DEM_ENABLE_CONDITION_GROUP_NUM > 0) */
	{
		Dem_Enable_EnableCondition(internalId);
	}

#if(DEM_STORAGE_CONDITION_GROUP_NUM > 0)
	if(pEventPara->DemStorageConditionGroupRef != 0xFFu)
	{
		pGroup = Dem_General.DemStorageConditionGroup[pEventPara->DemStorageConditionGroupRef];

		if((boolean)TRUE == Dem_ConditionIsFulFilled(Dem_StorageConditionStatus,pGroup,DEM_STORAGE_CONDITION_NUM_BYTE))
		{
			Dem_Enable_StorageCondition(internalId);
		}
	}
	else
#endif /* #if(DEM_STORAGE_CONDITION_GROUP_NUM > 0) */
	{
		Dem_Enable_StorageCondition(internalId);
	}
}
#endif /* #if((DEM_ENABLE_CONDITION_GROUP_NUM > 0) || (DEM_STORAGE_CONDITION_GROUP_NUM > 0)) */


/*
 * @brief        	Dem_DtcSuppressInit
 * @details			Using configuration to initialize dtc suppress information.
 *
 * @para[in]        internalId: Internal event id which value is equal to event id - 1.
 *
 * @para[out] 		flag: If event of a dtc is available,correspond value shall be set to 1.
 */
STATIC FUNC(void, DEM_CODE) Dem_DtcSuppressInit
(
	Dem_EventIdType internalId,
	P2VAR(uint8,AUTOMATIC,DEM_VAR)flag
)
{
#if(DEM_DTC_NUM > 0)
	uint16 u16DtcRef = Dem_ConfigPtr->DemEventParameter[internalId].DemDTCRef;
#endif /* #if(DEM_DTC_NUM > 0) */

	if(Dem_ConfigPtr->DemEventParameter[internalId].DemEventAvailable == (boolean)TRUE)
	{
		Dem_Enable_EventAvaliable(internalId);

#if(DEM_DTC_NUM > 0)
		if(u16DtcRef != 0xFFFFu)
		{
			flag[u16DtcRef] |= 1u; /* PRQA S 0492 #violate MISAR2004_17.4:Array subscripting
                                                * applied to a function parameter declared as a pointer */
		}
#else
		(void)flag;
#endif /* #if(DEM_DTC_NUM > 0) */
	}
}


/*
 * @brief        	Dem_EventInfoInit
 * @details			Initialize dtc suppress information, primary memory info, enable condition and
 * 					storage condition, and debounce timer.
 */
STATIC FUNC(void, DEM_CODE) Dem_EventInfoInit
(
	void
)
{
	uint8 u8Loop     = 0u;
	uint8 u8EntryNum = 0u;
	uint16 u16Loop   = 0u;

	Dem_MemoryEntryType* pEntry = Dem_GetMemoryConf(DEM_DTC_ORIGIN_PRIMARY_MEMORY,&u8EntryNum);

#if((DEM_DEBOUNCE_TIME_BASED_EVENT_NUM > 0)||(DEM_COMPONENT_NUM > 0))
	const Dem_EventParameterType* pEventPara = Dem_ConfigPtr->DemEventParameter;
#endif /* #if((DEM_DEBOUNCE_TIME_BASED_EVENT_NUM > 0)||(DEM_COMPONENT_NUM > 0)) */

#if(DEM_DTC_NUM > 0)
	uint8 flag[DEM_DTC_NUM] = {0};
#endif /* #if(DEM_DTC_NUM > 0) */

	Dem_PrimaryMemoryInfo.EntryNum = 0u;
	do
	{
		if(pEntry->EventId != 0u)
		{
			Dem_PrimaryMemoryInfo.EntryNum++;
		}
		pEntry++; /* PRQA S 2983 #violate MISAR2004_21.1: The value of this object will be 
                           * subsequently used when u8EntryNum is bigger than 1 */
		u8Loop++; /* PRQA S 2984 #violate MISAR2004_21.1: The value of the result is variable */
	}while(u8Loop < u8EntryNum); /* PRQA S 2996,2993 #violate MISAR2004_13.7:The result 
                                      * of this logical operation is variable,and this loop
                                      * will excute more than once */

	Dem_PrimaryMemoryInfo.OverFlow = (boolean)FALSE;
	if(Dem_PrimaryMemoryInfo.EntryNum == u8EntryNum)
	{
		Dem_PrimaryMemoryInfo.OverFlow = (boolean)TRUE;
	}

	do
	{
		Dem_Enable_DTCSetting(u16Loop);

#if(DEM_DTC_NUM > 0)
		Dem_DtcSuppressInit(u16Loop,flag);
#else
		Dem_DtcSuppressInit(u16Loop,NULL_PTR);
#endif /* #if(DEM_DTC_NUM > 0) */

#if(DEM_COMPONENT_NUM > 0)
		/**
		 * @req [SWS_Dem_01136] With setting a DemComponent to not available, all assigned
		 * 		events shall also be set as not available.
		 */
		if(pEventPara->DemComponentClassRef != 0xFFFFu)
		{
			if((boolean)FALSE == Dem_IsEnable_ComponentAvailable(pEventPara->DemComponentClassRef))
			{
				Dem_Disable_EventAvaliable(u16Loop);
			}
		}
#endif /* #if(DEM_COMPONENT_NUM > 0) */

#if((DEM_ENABLE_CONDITION_GROUP_NUM > 0) || (DEM_STORAGE_CONDITION_GROUP_NUM > 0))
		Dem_EventConditionInit(u16Loop);
#endif /* #if((DEM_ENABLE_CONDITION_GROUP_NUM > 0) || (DEM_STORAGE_CONDITION_GROUP_NUM > 0)) */

#if(DEM_DEBOUNCE_TIME_BASED_EVENT_NUM > 0)
		if((pEventPara->DemDebounceAlgorithmClassType == DEM_DEBOUNCE_TIME_BASE)\
				&&(pEventPara->DemDebounceInfoIndex < DEM_DEBOUNCE_TIME_BASED_EVENT_NUM))
		{
			DemInternalDebounceTimer[pEventPara->DemDebounceInfoIndex].IntId = u16Loop;
		}
		pEventPara++;
#endif /* #if(DEM_DEBOUNCE_TIME_BASED_EVENT_NUM > 0) */

		Dem_EventTriggerCondition[u16Loop] = 0u;
#if(DEM_DTC_NUM > 0)
		Dem_SetCombineDtcStatus(u16Loop);
#endif /* #if(DEM_DTC_NUM > 0) */
		u16Loop++;
	}while(u16Loop < DEM_EVENT_PARAMETER_NUM);

#if(DEM_DTC_NUM > 0)
	u16Loop = 0u;
	do
	{
		if(flag[u16Loop] == 0u)
		{
			Dem_Enable_DTCSuppress(u16Loop); /* PRQA S 2984,2985 #violate MISAR2004_21.1:
		 	 	 	 	 	 	 	 	 	    The value of the result is variable */
		}
		u16Loop++;
	}while(u16Loop < DEM_DTC_NUM);
#endif /* #if(DEM_DTC_NUM > 0) */

	Dem_DTCRecordUpdateInfo.DTCOrigin = 0xFFu;
	Dem_DTCRecordUpdateInfo.DtcRef = 0xFFFFu;
}

#if(DEM_MAXNUMBER_PRESTORED_FF > 0)
/*
 * @brief        	Dem_PreFFInit
 * @details			Initialize pre freeze frame info.
 */
STATIC FUNC(void, DEM_CODE) Dem_PreFFInit
(
	void
)
{
	uint8 u8Loop = 0u;
	uint32 u32Size = DEM_FREEZE_FRAME_MAX_LEN;

	do
	{
		Dem_PreFFInfos[u8Loop].eventId = 0u;
		DEM_VALUE_SET(Dem_PreFFInfos[u8Loop].FFData,0x00u,u32Size);
		u8Loop++;
	}while(u8Loop < DEM_MAXNUMBER_PRESTORED_FF);
}
#endif /* #if(DEM_MAXNUMBER_PRESTORED_FF > 0) */

#if(DEM_DTC_NUM > 0)
#if(DEM_EVENT_DISPLACEMENT_STRATEGY != DEM_DISPLACEMENT_NONE)
#if((DEM_OBDEVENT_DISPLACEMENT == STD_ON) && (DEM_INDICATOR_NUM > 0))
STATIC FUNC(boolean,DEM_CODE)Dem_CheckMILByEvent
(
	Dem_EventIdType InternalId
)
{
	boolean ret = (boolean)FALSE;
	uint8 u8Loop = 0u;
	const Dem_IndicatorAttributeType* pIndicatorRef = \
			Dem_ConfigPtr->DemEventParameter[InternalId].DemIndicatorAttribute;

	if(pIndicatorRef != NULL_PTR)
	{
		/* First,the MIL is ON. */
		if(Dem_IndicatorStatus[DEM_MILINDICATOR_REF] != DEM_INDICATOR_OFF)
		{
			while(u8Loop < Dem_ConfigPtr->DemEventParameter[InternalId].DemIndicatorAttributeNum)
			{
				/* Then,this event references MIL. */
				if(pIndicatorRef[u8Loop].DemIndicatorRef == DEM_MILINDICATOR_REF)
				{
					/* The last,this event caused MIL to turn on. */
					if(Dem_EventInternalData[InternalId].failedCycles >= \
							Dem_ConfigPtr->DemEventParameter[InternalId].\
							DemEventFailureCycleCounterThreshold)
					{
						ret = (boolean)TRUE;
					}
				}
				u8Loop++;
			}
		}
	}

	return ret;
}
#endif /* #if((DEM_OBDEVENT_DISPLACEMENT == STD_ON) && (DEM_INDICATOR_NUM > 0)) */

STATIC FUNC(Dem_MemoryEntryType*,DEM_CODE)Dem_EventDisplacementHandle
(
	Dem_EventIdType InternalId,
	Dem_DTCOriginType DtcOrigin
)
{
	uint8 u8Loop = 0u;
	uint8 u8EntryNum = 0u;
	Dem_MemoryEntryType* pRetEntry = NULL_PTR;
	Dem_MemoryEntryType* pEntry = Dem_GetMemoryConf(DtcOrigin,&u8EntryNum);

	uint16 u16DtcRef = Dem_ConfigPtr->DemEventParameter[InternalId].DemDTCRef;
	uint16 u16DtcAttrRef = Dem_ConfigPtr->DemDTC[u16DtcRef].DemDTCAttributesRef;
	uint8  Priority = Dem_ConfigPtr->DemDTCAttributes[u16DtcAttrRef].DemDTCPriority;
	uint8  AbsTime = 0xFFu;
#if(DEM_EVENT_DISPLACEMENT_STRATEGY == DEM_DISPLACEMENT_FULL)
	boolean Active = Dem_ISEnable_EventActive(InternalId);
#endif /* #if(DEM_EVENT_DISPLACEMENT_STRATEGY == DEM_DISPLACEMENT_FULL) */
	uint8 u8OldPriority;
#if(DEM_OBD_COMPLIANCY == 15u)
	uint8 Class;
	uint8 u8OldClass;

	if(Dem_ConfigPtr->DemDTC[u16DtcRef].DemWWHOBDDTCClass == 0xFF)
	{
		Class = 0u;
	}
	else
	{
		Class = Dem_ConfigPtr->DemDTC[u16DtcRef].DemWWHOBDDTCClass;
	}
#endif /* #if(DEM_OBD_COMPLIANCY == 15u) */

	while(u8Loop < u8EntryNum)
	{
		if(pEntry->EventId != 0u)
		{
			u16DtcRef = Dem_ConfigPtr->DemEventParameter[(pEntry->EventId-1u)].DemDTCRef;
			u16DtcAttrRef = Dem_ConfigPtr->DemDTC[u16DtcRef].DemDTCAttributesRef;
			u8OldPriority = Dem_ConfigPtr->DemDTCAttributes[u16DtcAttrRef].DemDTCPriority;
#if(DEM_OBD_COMPLIANCY == 15u)
			if(Dem_ConfigPtr->DemDTC[u16DtcRef].DemWWHOBDDTCClass == 0xFF)
			{
				u8OldClass = 0u;
			}
			else
			{
				u8OldClass = Dem_ConfigPtr->DemDTC[u16DtcRef].DemWWHOBDDTCClass;
			}
#endif /* #if(DEM_OBD_COMPLIANCY == 15u) */

			if((Dem_DTCRecordUpdateInfo.DtcRef == u16DtcRef)
				&& (Dem_DTCRecordUpdateInfo.DTCOrigin == DtcOrigin))
			{
				;
			}
			else
			{
#if(DEM_OBDEVENT_DISPLACEMENT == STD_ON)
				/**
				 * @req [SWS_Dem_00695] If the configuration parameter DemOBDEventDisplacement is
				 * 		set to TRUE all emission related events with the following conditions shall
				 * 		not be considered during the displacement mechanism and shall not displaced
				 * 		from error memory:
				 * 		Eventold is emission related
				 * 		AND
				 * 		(
				 * 		 Eventold triggers MIL indicator
				 * 		 OR
				 * 		 ((Eventold holds legislative Freeze Frame) AND (has equal or higher priority))
				 * 		 OR
				 * 		 Pending-DTC==1
				 * 		)
				 */
				if((Dem_ConfigPtr->DemDTC[u16DtcRef].DemObdDTCRef != 0xFFFFu)\
					&&((Dem_ISEnable_UdsStatusBits((pEntry->EventId-1),DEM_UDS_STATUS_PDTC))
#if(DEM_PID_CLASS_NUM > 0)
					||((pEntry->PidInfo[0].PidId != 0xFFu)&&(u8OldPriority >= Priority))
#endif /* #if(DEM_PID_CLASS_NUM > 0) */
#if(DEM_INDICATOR_NUM > 0)
					||((boolean)TRUE == Dem_CheckMILByEvent(pEntry->EventId-1))
#endif /* #if(DEM_INDICATOR_NUM > 0) */
					  ))
				{
					;
				}
				else
#endif /* #if(DEM_OBDEVENT_DISPLACEMENT == STD_ON) */
				{
#if(DEM_OBD_COMPLIANCY == 15u)
					if(u8OldClass < Class)
					{
						Priority = u8OldPriority;
#if(DEM_EVENT_DISPLACEMENT_STRATEGY == DEM_DISPLACEMENT_FULL)
						Active = Dem_ISEnable_EventActive(pEntry->EventId - 1u);
#endif /* #if(DEM_EVENT_DISPLACEMENT_STRATEGY == DEM_DISPLACEMENT_FULL) */
						AbsTime = pEntry->AbsTime;
						Class = u8OldClass;
						pRetEntry = pEntry;
					}
					else if(u8OldClass == Class)
#endif /* #if(DEM_OBD_COMPLIANCY == 15u) */
					{
						if(u8OldPriority > Priority)
						{
							Priority = u8OldPriority;
#if(DEM_EVENT_DISPLACEMENT_STRATEGY == DEM_DISPLACEMENT_FULL)
							Active = Dem_ISEnable_EventActive(pEntry->EventId - 1u);
#endif /* #if(DEM_EVENT_DISPLACEMENT_STRATEGY == DEM_DISPLACEMENT_FULL) */
							AbsTime = pEntry->AbsTime;
							pRetEntry = pEntry;
						}
						else if((u8OldPriority == Priority) && ((boolean)TRUE == \
							Dem_ISEnable_UdsStatusBits((pEntry->EventId-1u),DEM_UDS_STATUS_TNCTOC)))
						{
							/**
							 * @req [SWS_Dem_00692] If an event memory entry has the same priority
							 * 		like the reported event and the existing event is not tested in
							 * 		this OperationCycle(TestNotCompletedThisOperationCycle bit == 1)
							 * 		the Dem module shall displace this event.
							 * @req [SWS_Dem_00693] If an event memory entry has the same priority
							 * 		like the reported event and the existing event is tested in
							 * 		this OperationCycle (TestNotCompletedThisOperationCycle bit == 0)
							 * 		the Dem shall discard the reported event because the TestFailed
							 * 		status of the existing event is not verified.
							 */
#if(DEM_EVENT_DISPLACEMENT_STRATEGY == DEM_DISPLACEMENT_FULL)
							if((Dem_ISEnable_EventActive(pEntry->EventId - 1u) == (boolean)FALSE)
								&& (Active == (boolean)TRUE))
							{
								Active = (boolean)FALSE;
								AbsTime = pEntry->AbsTime;
								pRetEntry = pEntry;
							}
							else if(Dem_ISEnable_EventActive(pEntry->EventId - 1u) == Active)
#endif /* #if(DEM_EVENT_DISPLACEMENT_STRATEGY == DEM_DISPLACEMENT_FULL) */
							{
								if(pEntry->AbsTime < AbsTime)
								{
									AbsTime = pEntry->AbsTime;
									pRetEntry = pEntry;
								}
							}
							else{}
						}
						else{}
					}
#if(DEM_OBD_COMPLIANCY == 15u)
					else{}
#endif /* #if(DEM_OBD_COMPLIANCY == 15u) */
				}
			}
		}
		u8Loop++;
		pEntry++;
	}
	return pRetEntry;
}

STATIC FUNC(Dem_MemoryEntryType*,DEM_CODE)Dem_EventDisplacement
(
	Dem_EventIdType InternalId,
	Dem_DTCOriginType DtcOrigin
)
{
#if(DEM_RESSET_CONFIRMEDBIT_ONOVERFLOW == STD_ON)
#if(DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONSTORAGE)
	uint16 u16Loop = 0u;
#endif /* #if(DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONSTORAGE) */
#endif /* #if(DEM_RESSET_CONFIRMEDBIT_ONOVERFLOW == STD_ON) */

	Dem_MemoryEntryType* pDisplaceEntry = NULL_PTR;

	pDisplaceEntry = Dem_EventDisplacementHandle(InternalId,DtcOrigin);

	if(pDisplaceEntry != NULL_PTR)
	{
#if(DEM_RESSET_CONFIRMEDBIT_ONOVERFLOW == STD_ON)
		/**
		 * @req [SWS_Dem_00409] If an event memory entry was removed during displacement,
		 *      the Dem module shall reset the UDS status bit 2 (PendingDTC) and UDS status
		 *      bit 3 (ConfirmedDTC) to 0 if the configuration parameter DemResetConfirmed-
		 *      BitOnOverflow (refer to Dem_General) is set to true.
		 */
#if(DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONSTORAGE)
		/**
		 * @req [SWS_Dem_00443]  If a combined DTC (combination on storage) is displaced,
		 *      the Dem module shall remove this event memory entry and reset the status
		 *      bytes of all sub-events.
		 */
		for(u16Loop = 0u; u16Loop < DEM_EVENT_PARAMETER_NUM; u16Loop++)
		{
			if(Dem_ConfigPtr->DemEventParameter[u16Loop].DemDTCRef \
					== Dem_ConfigPtr->DemEventParameter[(pDisplaceEntry->EventId - 1u)].DemDTCRef)
			{
				Dem_Disable_UdsStatusBits(u16Loop,DEM_UDS_STATUS_PDTC);
				Dem_Disable_PDTCBitChange(u16Loop);
				Dem_Disable_UdsStatusBits(u16Loop,DEM_UDS_STATUS_CDTC);
				Dem_Disable_CDTCBitChange(u16Loop);

#if(DEM_STATUS_BIT_HANDLING_TEST_FAILED_SINCE_LAST_CLEAR == DEM_STATUS_BIT_AGING_AND_DISPLACEMENT)
				/**
				 * @req [SWS_Dem_01186] If an event memory entry was removed during displacement,
				 *      the UDS status bit 5 (TestFailedSinceLastClear)shall be reset to 0 in case
				 *      of DemStatusBitHandlingTestFailedSinceLastClear is set to DEM_STATUS_BIT_
				 *      AGING_AND_DISPLACEMENT and DemResetConfirmedBitOnOverflow is set to true.
				 */
				Dem_Disable_UdsStatusBits(u16Loop,DEM_UDS_STATUS_TFSLC);
#endif /* #if(DEM_STATUS_BIT_HANDLING_TEST_FAILED_SINCE_LAST_CLEAR
			   == DEM_STATUS_BIT_AGING_AND_DISPLACEMENT) */
			}
		}
#else
		Dem_Disable_UdsStatusBits((pDisplaceEntry->EventId - 1u),DEM_UDS_STATUS_PDTC);
		Dem_Disable_PDTCBitChange(pDisplaceEntry->EventId - 1u);
		Dem_Disable_UdsStatusBits((pDisplaceEntry->EventId - 1u),DEM_UDS_STATUS_CDTC);
		Dem_Disable_CDTCBitChange(pDisplaceEntry->EventId - 1u);

#if(DEM_STATUS_BIT_HANDLING_TEST_FAILED_SINCE_LAST_CLEAR == DEM_STATUS_BIT_AGING_AND_DISPLACEMENT)
		Dem_Disable_UdsStatusBits((pDisplaceEntry->EventId - 1u),DEM_UDS_STATUS_TFSLC);
#endif /* #if(DEM_STATUS_BIT_HANDLING_TEST_FAILED_SINCE_LAST_CLEAR
			   == DEM_STATUS_BIT_AGING_AND_DISPLACEMENT) */

#endif /* #if(DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONSTORAGE) */
#endif /* #if(DEM_RESSET_CONFIRMEDBIT_ONOVERFLOW == STD_ON) */

		Dem_SetCombineDtcStatus((pDisplaceEntry->EventId - 1u));

		Dem_DeleMemoryEntry(DtcOrigin,pDisplaceEntry);
	}
	return pDisplaceEntry;
}
#endif /* #if(DEM_EVENT_DISPLACEMENT_STRATEGY != DEM_DISPLACEMENT_NONE) */

STATIC FUNC(Dem_MemoryEntryType*,DEM_CODE)Dem_AllocateNewEntry
(
	Dem_EventIdType InternalId,
	Dem_DTCOriginType DtcOrigin
)
{
	uint8 u8EntryNum = 0u;
	uint8 u8Loop = 0u;
	uint8 u8AbsTime = 0u;
	Dem_MemoryEntryType* pEntry = Dem_GetEntryFromMemory(DtcOrigin,0x00u);
	Dem_MemoryInfoType* pMemInfo = Dem_GetMemInfoByOrigin(DtcOrigin);
	Dem_MemoryEntryType* entryPtr = Dem_GetMemoryConf(DtcOrigin,&u8EntryNum);

	if((pEntry == NULL_PTR) && (pMemInfo != NULL_PTR))
	{
		pMemInfo->OverFlow = (boolean)TRUE;
#if(DEM_EVENT_DISPLACEMENT_STRATEGY != DEM_DISPLACEMENT_NONE)
		/**
		 * @req [SWS_Dem_00400] If the event retention want to allocate a new event memory
		 *      entry and there is no free event memory entry available,the Dem module shall
		 *      check according [SWS_Dem_00406] for allocated event memory entries to be
		 *      displaced by the new event memory entry.
		 * @req [SWS_Dem_00401] The Dem module provides the configuration parameter
		 *      DemEventDisplacementStrategy (refer to Dem_General defining whether
		 *      the existing event memory entry can be displaced or not.
		 * @req [SWS_Dem_00402] If event displacement is disabled (DemEventDisplacementStrategy
		 *      selects DEM_DISPLACEMENT_NONE), the Dem module shall not displace existing event
		 *      memory entries if the event memory is full.
		 */
		pEntry = Dem_EventDisplacement(InternalId,DtcOrigin);
#endif /* #if(DEM_EVENT_DISPLACEMENT_STRATEGY != DEM_DISPLACEMENT_NONE) */
	}

	if(pEntry != NULL_PTR)
	{
		pMemInfo->EntryNum++;
		if(pMemInfo->EntryNum == u8EntryNum)
		{
			pMemInfo->OverFlow = (boolean)TRUE;
		}
		pEntry->EventId = InternalId + 1u;

		do
		{
			/**
			 * @req [SWS_Dem_00412] New added event memory entries shall be always stored as the most
			 *      recent memory entries to keep the chronological order. In case of an update of a
			 *      event memory location (e.g. event reports again) the chronological order of this
			 *      event memory entry shall remain the same.
			 */
			if(u8AbsTime < entryPtr->AbsTime)
			{
				u8AbsTime = entryPtr->AbsTime;
			}
			u8Loop++; /* PRQA S 2984 #violate MISAR2004_21.1: The value of the result is variable */
			entryPtr++; /* PRQA S 2983 #violate MISAR2004_21.1: The value of this object will be 
                                     * subsequently used when u8EntryNum is bigger than 1 */
		}while(u8Loop < u8EntryNum); /* PRQA S 2993,2996 #violate MISAR2004_21.1: The loop will be excuted
                                              * more than once when u8EntryNum is bigger than 1 */

		pEntry->AbsTime = u8AbsTime + 1u;
#if(DEM_MAX_NUMBER_FF_RECORDS > 0)
		pEntry->FFStoreNum				= 0u;
		pEntry->LastestFF				= 0u;
#endif /* #if(DEM_MAX_NUMBER_FF_RECORDS > 0) */
		pEntry->AgingCounter  			= 0u;
		pEntry->HealingCounter			= 0u;
		pEntry->FailureCounter			= 0u;
		pEntry->CyclesSinceLastFailed	= 0u;
		pEntry->CyclesSinceFirstFailed	= 0u;

		/**
		 * @req [SWS_Dem_00523] The Dem module shall initialize the occurrence counter with the value
		 *      one if the related event is entered in the respective event memory.
		 */
		Dem_EventInternalData[InternalId].occurCnt = 1u;
		pEntry->OccurrenceCounter = 1u;
		pEntry->UdsStatus = Dem_EventUDSBitStatus[InternalId];

		/* todo [SWS_Dem_00772] [SWS_Dem_00771] */

#if(DEM_CALLBACK_EVENTDATA_CHANGE_NUM > 0)
		/**
		 * @req [SWS_Dem_00475] If 'event related data' of an 'event memory entry' is added or
		 *      updated(triggering the collection of new 'event related data')AND notifications
		 *      on data changes are configured via 'DemCallbackEventDataChanged' AND the Dem-
		 *      DataElementClass of the 'event related data' is of type 'DemExternalCSDataElement-
		 *      Class' or DemExternalSRDataElementClass,the Dem shall trigger these configured
		 *      event-specific notifications as well as the general notification 'GeneralCallback-
		 *      EventDataChanged'.
		 */
		if(Dem_ConfigPtr->DemEventParameter[InternalId].DemCallbackEventDataChanged != NULL_PTR)
		{
			if(Dem_ConfigPtr->DemEventParameter[InternalId].DemCallbackEventDataChanged->\
					DemCallbackEventDataChangedFnc != NULL_PTR)
			{
				(void)Dem_ConfigPtr->DemEventParameter[InternalId].DemCallbackEventDataChanged->
						DemCallbackEventDataChangedFnc((InternalId + 1u));
			}
		}
#endif /* #if(DEM_CALLBACK_EVENTDATA_CHANGE_NUM > 0) */
	}
	else
	{
		/**
		 * @req [SWS_Dem_00407] If no event memory entry for displacement was identified,the Dem module
		 *      shall discard the storage request.
		 */
		Dem_Disable_UdsStatusBits(InternalId,DEM_UDS_STATUS_CDTC);
		Dem_Disable_PDTCBitChange(InternalId);
		Dem_Disable_UdsStatusBits(InternalId,DEM_UDS_STATUS_PDTC);
		Dem_Disable_CDTCBitChange(InternalId);

		Dem_EventInternalData[InternalId].failedCycles           = 0u;
		Dem_EventInternalData[InternalId].cyclesSinceFirstFailed = 0u;
		Dem_EventInternalData[InternalId].cyclesSinceLastFailed  = 0u;
		Dem_EventInternalData[InternalId].occurCnt   = 0u;
		Dem_EventInternalData[InternalId].agingUpCnt = 0u;
		Dem_EventInternalData[InternalId].healingCnt = 0u;
	}
	return pEntry;
}

STATIC FUNC(void,DEM_CODE)Dem_EventAlreadyStored
(
	Dem_EventIdType InternalId,
	Dem_DTCOriginType DtcOrigin,
	P2VAR(Dem_MemoryEntryType,AUTOMATIC,DEM_VAR) pEntry
)
{
	uint8 u8EntryNum = 0u;
	uint8 u8Loop = 0u;
	uint8 u8MaxAbsTime = 0u;

	Dem_MemoryEntryType* entryPtr = Dem_GetMemoryConf(DtcOrigin,&u8EntryNum);

	if((boolean)TRUE == Dem_ISEnable_TFBitChange(InternalId))
	{
#if(DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONSTORAGE)
		if(pEntry->EventId-1 == InternalId)
#endif /* #if(DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONSTORAGE) */
		{
			Dem_Disable_TFBitChange(InternalId);
		}
		/**
		 * @req [SWS_Dem_00787] If an 'stored event' gets re-qualified as failed (UDS DTC status bit
		 *      0 changes from 0 to 1)and a respective event memory entry exists,the Dem module shall
		 *      update the chronological order of the event storage by setting the particular event
		 *      as most recent event memory entry.
		 */
		while(u8Loop < u8EntryNum) /* PRQA S 2877 #violate MISAR2004_21.1: This loop will be executed more than once */
		{
			if(u8MaxAbsTime < entryPtr->AbsTime)
			{
				u8MaxAbsTime = entryPtr->AbsTime;
			}

			if(pEntry->AbsTime < entryPtr->AbsTime)
			{
				entryPtr->AbsTime--;
			}

			u8Loop++; /* PRQA S 2984 #violate MISAR2004_21.1: The value of the result is variable */
			entryPtr++; /* PRQA S 2983 #violate MISAR2004_21.1: The value of this object will be 
                                     * subsequently used when u8EntryNum is bigger than 1 */
		}
		pEntry->AbsTime = u8MaxAbsTime;
	}
}

STATIC FUNC(Dem_MemoryEntryType*,DEM_CODE)Dem_EntryAllocate
(
	Dem_EventIdType InternalId,
	Dem_DTCOriginType DtcOrigin
)
{
	Dem_MemoryEntryType* pEntry = Dem_GetEntryFromMemory(DtcOrigin,(InternalId + 1u));

#if(DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONSTORAGE)
	if((!(Dem_ISEnable_UdsStatusBits(InternalId,DEM_UDS_STATUS_CDTC)))\
			&& (Dem_ConfigPtr->DemEventParameter[InternalId].DemEventIsCombina == (boolean)TRUE))
	{
		/**
		 * @req [SWS_Dem_01051] For combination on storage,the event which allocated (or reallocate)
		 *      the event memory entry shall be the only event, which has the confirmed bit set.
		 */
		pEntry = NULL_PTR;
	}
	else
#endif /* #if(DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONSTORAGE) */
	{
#if(DEM_COMPONENT_NUM > 0)
		/**
		 * @req [SWS_Dem_01130] A failure which is considered as consecutive fault shall not be
		 *      stored to the failure memory.(The handling shall be analogous to storage condition
		 *      not fulfilled).
		 */
		if((boolean)FALSE == Dem_ISEnable_ConsecutiveFault(InternalId))
#endif /* #if(DEM_COMPONENT_NUM > 0) */
		{
#if(DEM_STORAGE_CONDITION_NUM > 0)
			if(((boolean)FALSE == Dem_ISEnable_StorageCondition(InternalId))
				&& ((boolean)TRUE == Dem_ISEnable_TFBitChange(InternalId)))
			{
				/**
				 * @req [SWS_Dem_00455] If the Dem module is requested to support storage conditions,
				 *      the Dem module shall check the assigned storage conditions after the event gets
				 *      qualified as failed (UDS DTC status bit 0 changes from 0 to 1).
				 *
				 * @req [SWS_Dem_00458] If one storage condition is not fulfilled and no respective
				 *      event memory entry exists,the Dem module shall not enter the reported event
				 *      into the event memory.
				 *
				 * @req [SWS_Dem_00591] If one storage condition is not fulfilled and a respective
				 *      event memory entry exists, the Dem module shall not update the event memory
				 *      of the reported event.
				 */
				Dem_Disable_TFBitChange(InternalId);
				pEntry = NULL_PTR;
			}
			else
			{
#endif /* #if(DEM_STORAGE_CONDITION_NUM > 0) */
				/**
				 * @req [SWS_Dem_00079] The function Dem_DcmDisableDTCSetting shall disable the
				 *      storage of all events assigned to a specific DTC group in the event memory
				 *      including the respective UDS DTC status byte updates.
				 */
				if((boolean)TRUE == Dem_ISEnable_DTCSetting(InternalId))
				{
					if(pEntry == NULL_PTR)
					{
						if((boolean)TRUE == Dem_EntryAllocateConditionCheck(InternalId))
						{
							/* this event did not have an existed entry,allocate new memory entry */
							pEntry = Dem_AllocateNewEntry(InternalId,DtcOrigin);
						}
					}
					else
					{
						Dem_EventAlreadyStored(InternalId,DtcOrigin,pEntry);
					}
				}
#if(DEM_STORAGE_CONDITION_NUM > 0)

			}
#endif /* #if(DEM_STORAGE_CONDITION_NUM > 0) */
		}
	}

	return pEntry;
}
#endif /* #if(DEM_DTC_NUM > 0) */

#if(DEM_PID_CLASS_NUM > 0)
STATIC FUNC(void, DEM_CODE)Dem_StorePidClass
(
	Dem_EventIdType InternalId,
	P2VAR(Dem_EventBufferType,AUTOMATIC,DEM_VAR)pBuffer
)
{
	uint16	u16DtcRef = Dem_ConfigPtr->DemEventParameter[InternalId].DemDTCRef;
	Dem_DTCOriginType dtcOrigin;
	Dem_MemoryEntryType* pEntry = NULL_PTR;
	Dem_EventBufferType	destBuffer;
	const Dem_PidClassType* pPidClass = Dem_ConfigPtr->DemPidClass;
	uint16 u16DataSize = 0u;
	uint16 u16Offset = 0u;
	uint8 u8ClassLoop = 0u;

    if(u16DtcRef != 0xFFFFu)
    {
    	dtcOrigin = Dem_ConfigPtr->DemDTCAttributes[Dem_ConfigPtr->DemDTC[u16DtcRef].\
					DemDTCAttributesRef].DemMemoryDestinationRef;

    	if((dtcOrigin != Dem_DTCRecordUpdateInfo.DTCOrigin)
			|| (Dem_DTCRecordUpdateInfo.DtcRef != u16DtcRef))
    	{
    		pEntry = Dem_GetEntryFromMemory(dtcOrigin,(InternalId + 1u));

    		if(pEntry == NULL_PTR)
    		{
    			pEntry = Dem_GetEntryFromMemory(dtcOrigin,0u);
    		}

    		if(pEntry != NULL_PTR)
    		{
				if(pBuffer == NULL_PTR)
				{
					pBuffer = &destBuffer;
					Dem_CapturePidClass(InternalId,pBuffer->PidData);
				}

				for(u8ClassLoop = 0u; u8ClassLoop < DEM_PID_CLASS_NUM; u8ClassLoop++)
				{
					pEntry->PidInfo[u8ClassLoop].PidId = pPidClass[u8ClassLoop].DemPidIdentifier;

					u16DataSize = pPidClass[u8ClassLoop].DemPidElementSize;

					DEM_VALUE_COPY(pEntry->PidInfo[u8ClassLoop].PidData,\
								   &(pBuffer->PidData[u16Offset]),\
								   u16DataSize);

					u16Offset += pPidClass[u8ClassLoop].DemPidElementSize;
				}
			}
    	}
    }
}
#endif /* #if(DEM_PID_CLASS_NUM > 0) */

#if(DEM_FREEZEFRAME_ENABLE == STD_ON)
STATIC FUNC(void, DEM_CODE)Dem_StoreFreezeFrame
(
	uint8 Trigger,
	P2CONST(uint8,AUTOMATIC,DEM_VAR) pFFData,
	P2VAR(Dem_MemoryEntryType,AUTOMATIC,DEM_VAR) pEntry
)
{
#if(DEM_TYPEOFFF_RECORD_NUMERATION == DEM_FF_RECNUM_CONFIGURED)
	uint8 u8Loop = 0u;
	uint8 u8FFRecordRefNum;
#endif /* #if(DEM_TYPEOFFF_RECORD_NUMERATION == DEM_FF_RECNUM_CONFIGURED) */

	Dem_EventIdType internalId = pEntry->EventId - 1u;

	Dem_MemFFInfoType* pMemFFInfo = NULL_PTR;

	uint16 u16DtcRef = Dem_ConfigPtr->DemEventParameter[internalId].DemDTCRef;

	const Dem_DTCAttributesType* pDtcAttr = &(Dem_ConfigPtr->DemDTCAttributes[Dem_ConfigPtr->\
													DemDTC[u16DtcRef].DemDTCAttributesRef]);

#if(DEM_TYPEOFFF_RECORD_NUMERATION == DEM_FF_RECNUM_CONFIGURED)
	const Dem_FreezeFrameRecordClassType* pFFRecordClass = NULL_PTR;
	const uint8*  pFFRecordRef = NULL_PTR;

	if(pDtcAttr->DemFreezeFrameRecNumClassRef != 0xFFu)
	{
		pFFRecordRef = Dem_General.DemFreezeFrameRecNumClass[pDtcAttr->DemFreezeFrameRecNumClassRef].\
				DemFreezeFrameRecordClassRefStartIndex;

		u8FFRecordRefNum = Dem_General.DemFreezeFrameRecNumClass[pDtcAttr->\
							DemFreezeFrameRecNumClassRef].DemFreezeFrameRecordClassRefNum;

		do
		{
			pFFRecordClass = &(Dem_General.DemFreezeFrameRecordClass[*pFFRecordRef]);
			if(pFFRecordClass->DemFreezeFrameRecordTrigger == Trigger)
			{
				/**
				 * @req [SWS_Dem_00797] If the FreezeFrame uses dedicated, configured record numbers
				 *      (refer to DemFreezeFrameRecNumClassRef) and an event memory entry exists,the
				 *      Dem module shall capture the FreezeFrame on the configured trigger (refer to
				 *      DemFreezeFrameRecordTrigger) and store it to the event memory entry.
				 */
				pMemFFInfo = &(pEntry->FFInfo[u8Loop]);

				if(pMemFFInfo->RecNum == 0xFFu)
				{
					pEntry->FFStoreNum++;
				}

				/**
				 * @req [SWS_Dem_00803] If the FreezeFrame uses dedicated, configured record numbers
				 *      (refer to DemFreezeFrameRecNumClass) and DemFreezeFrameRecordUpdate is set to
				 *      DEM_UPDATE_RECORD_NO, the FreezeFrame shall be stored only if the FreezeFrame
				 *      is currently not stored in this event memory entry.
				 *
				 * @req [SWS_Dem_00804] If the FreezeFrame uses dedicated, configured record numbers
				 *      (refer to DemFreezeFrameRecNumClass) and DemFreezeFrameRecordUpdate is set to
				 *      DEM_UPDATE_RECORD_YES,the FreezeFrame shall be updated with each trigger (refer
				 *      to DemFreezeFrameRecordTrigger).
				 */
				if(((pMemFFInfo->RecNum == 0xFFu) && (pFFRecordClass->DemFreezeFrameRecordUpdate \
						== DEM_UPDATE_RECORD_NO)) \
						|| (pFFRecordClass->DemFreezeFrameRecordUpdate == DEM_UPDATE_RECORD_YES))
				{
					pMemFFInfo->RecNum = pFFRecordClass->DemFreezeFrameRecordNumber;

#if(DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONSTORAGE)
#if(DEM_COMBINA_DTC_NUM > 0)
					if(Dem_ConfigPtr->DemEventParameter[internalId].DemEventIsCombina == (boolean)TRUE)
					{
						DEM_VALUE_COPY(\
								pMemFFInfo->FFData,\
								Dem_CombinaDtcInfo[Dem_ConfigPtr->\
											DemEventParameter[internalId].DemDTCRef].FFData,\
								DEM_FREEZE_FRAME_MAX_LEN);
					}
					else
#endif /* #if(DEM_COMBINA_DTC_NUM > 0) */
#endif /* #if(DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONSTORAGE) */
					{
						DEM_VALUE_COPY(\
								pMemFFInfo->FFData,\
								pFFData,\
								DEM_FREEZE_FRAME_MAX_LEN);
					}

					pEntry->LastestFF = u8Loop + 1u;
				}
			}
			pFFRecordRef++;
			u8Loop++;
		}while(u8Loop < u8FFRecordRefNum);
	}
#else /* DEM_TYPEOFFF_RECORD_NUMERATION = DEM_FF_RECNUM_CALCULATED */
	if(pDtcAttr->DemMaxNumberFreezeFrameRecords != 0u)
	{
		if(pDtcAttr->DemMaxNumberFreezeFrameRecords == 1u)
		{
			if(pEntry->FFStoreNum == 0u)
			{
				pMemFFInfo = &(pEntry->FFInfo[0]);
				pEntry->FFInfo[0].RecNum = 1u;
				pEntry->FFStoreNum += 1;
				pEntry->LastestFF += 1;
			}
		}
		else /* pDtcAttr->DemMaxNumberFreezeFrameRecords > 1u */
		{
			if(pEntry->FFStoreNum < pDtcAttr->DemMaxNumberFreezeFrameRecords)
			{
				pMemFFInfo = &(pEntry->FFInfo[pEntry->LastestFF]);
				pEntry->FFInfo[pEntry->LastestFF].RecNum = (pEntry->LastestFF + 1u);
				pEntry->FFStoreNum += 1;
				pEntry->LastestFF += 1;
			}
			else if(pEntry->FFStoreNum == pDtcAttr->DemMaxNumberFreezeFrameRecords)
			{
				pMemFFInfo = &(pEntry->FFInfo[pEntry->FFStoreNum - 1u]);
			}
		}

		if(pMemFFInfo != NULL_PTR)
		{
#if(DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONSTORAGE)
#if(DEM_COMBINA_DTC_NUM > 0)
			if(Dem_ConfigPtr->DemEventParameter[internalId].DemEventIsCombina \
					== (boolean)TRUE)
			{
				DEM_VALUE_COPY(\
						pMemFFInfo->FFData,\
						Dem_CombinaDtcInfo[Dem_ConfigPtr->\
									DemEventParameter[internalId].DemDTCRef].FFData,\
						DEM_FREEZE_FRAME_MAX_LEN);
			}
			else
#endif /* #if(DEM_COMBINA_DTC_NUM > 0) */
#endif /* #if(DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONSTORAGE) */
			{
				DEM_VALUE_COPY(\
						pMemFFInfo->FFData,\
						pFFData,\
						DEM_FREEZE_FRAME_MAX_LEN);
			}
		}
	}
#endif /* #if(DEM_TYPEOFFF_RECORD_NUMERATION == DEM_FF_RECNUM_CONFIGURED) */
}

#if(DEM_MAXNUMBER_PRESTORED_FF > 0)
STATIC FUNC(void, DEM_CODE)Dem_ClearPreFF
(
	Dem_EventIdType EventId
)
{
	uint16 u16Loop = 0u;
	do
	{
		if(EventId == Dem_PreFFInfos[u16Loop].eventId)
		{
			Dem_PreFFInfos[u16Loop].eventId = 0u;
			DEM_VALUE_SET(Dem_PreFFInfos[u16Loop].FFData,0xFFu,DEM_FREEZE_FRAME_MAX_LEN);
			break;
		}
		u16Loop++;
	}while(u16Loop < DEM_MAXNUMBER_PRESTORED_FF);
}
#endif /* #if(DEM_MAXNUMBER_PRESTORED_FF > 0) */

STATIC FUNC(void, DEM_CODE)Dem_UpdateEntryFFContent
(
	uint8 Trigger,
	P2VAR(Dem_EventBufferType,AUTOMATIC,DEM_VAR) pBuffer,
	P2VAR(Dem_MemoryEntryType,AUTOMATIC,DEM_VAR) pEntry
)
{
	Dem_EventIdType internalId = pEntry->EventId - 1u;
	uint8 u8FFData[DEM_FREEZE_FRAME_MAX_LEN] = {0u};

#if(DEM_MAXNUMBER_PRESTORED_FF > 0)
	uint8 u8Loop;
#endif /* #if(DEM_MAXNUMBER_PRESTORED_FF > 0) */

#if(DEM_MAXNUMBER_PRESTORED_FF > 0)
	if(Dem_ConfigPtr->DemEventParameter[internalId].DemFFPrestorageSupported == (boolean)TRUE)
	{
		/**
		 * @req [SWS_Dem_00464] If a pre-stored freeze frame is available, the Dem module shall
		 *      use the data of the pre-stored freeze frame instead of the current data at the
		 *      point in time when the event related date is captured.
		 */
		for(u8Loop = 0u; u8Loop < DEM_MAXNUMBER_PRESTORED_FF; u8Loop++)
		{
			if(Dem_PreFFInfos[u8Loop].eventId == pEntry->EventId)
			{
				DEM_VALUE_COPY(u8FFData,Dem_PreFFInfos[u8Loop].FFData,DEM_FREEZE_FRAME_MAX_LEN);

				Dem_ClearPreFF(pEntry->EventId);

				break;
			}
		}
	}

	if(u8Loop >= DEM_MAXNUMBER_PRESTORED_FF)
	{
#endif /* #if(DEM_MAXNUMBER_PRESTORED_FF > 0) */
		if(pBuffer != NULL_PTR)
		{
			DEM_VALUE_COPY(u8FFData,pBuffer->FFData,DEM_FREEZE_FRAME_MAX_LEN);
		}
		else
		{
			Dem_CaptureFreezeFrame(internalId,u8FFData);
		}
#if(DEM_MAXNUMBER_PRESTORED_FF > 0)
	}
#endif /* #if(DEM_MAXNUMBER_PRESTORED_FF > 0) */

#if(DEM_COMBINA_DTC_NUM > 0)
	if(Dem_ConfigPtr->DemEventParameter[internalId].DemEventIsCombina == (boolean)TRUE)
	{
		DEM_VALUE_COPY(\
				Dem_CombinaDtcInfo[Dem_ConfigPtr->DemEventParameter[internalId].DemDTCRef].FFData,\
				u8FFData,\
				DEM_FREEZE_FRAME_MAX_LEN);
	}
#endif /* #if(DEM_COMBINA_DTC_NUM > 0) */

	Dem_StoreFreezeFrame(Trigger,u8FFData,pEntry);
}
#endif /* #if(DEM_FREEZEFRAME_ENABLE == STD_ON)  */

#if(DEM_EXTENDED_DATA_CLASS_NUM > 0)
STATIC FUNC(void, DEM_CODE)Dem_StoreExtRecord
(
	uint8 Trigger,
	P2CONST(Dem_EventBufferType,AUTOMATIC,DEM_VAR)pBuffer,
	P2VAR(Dem_MemoryEntryType,AUTOMATIC,DEM_VAR) pEntry
)
{
	uint8 u8Loop = 0u;

	uint16 u16DataSize;

	uint16 u16Offset = 0u;

	uint16 u16BufferIndex = 0u;

	Dem_EventIdType internalId = pEntry->EventId - 1u;

	uint16 u16DtcRef = Dem_ConfigPtr->DemEventParameter[internalId].DemDTCRef;

	const Dem_DTCAttributesType* pDtcAttr = &(Dem_ConfigPtr->DemDTCAttributes[Dem_ConfigPtr->\
													DemDTC[u16DtcRef].DemDTCAttributesRef]);

	const uint8* pExtRecIndex = NULL_PTR;

	const Dem_ExtendedDataRecordClassType* pExtRecord = NULL_PTR;

#if(DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONSTORAGE)
	uint8* pExtData = NULL_PTR;
#endif /* #if(DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONSTORAGE) */

	if(pDtcAttr->DemExtendedDataClassRef != 0xFFFFu)
	{
		pExtRecIndex = Dem_General.DemExtendedDataClass[pDtcAttr->DemExtendedDataClassRef].\
				DemExtendedDataRecordClassRefStartIndex;

		while(u8Loop < Dem_General.DemExtendedDataClass[pDtcAttr->DemExtendedDataClassRef].\
				DemExtendedDataRecordClassRefNum)
		{
			pExtRecord = &(Dem_General.DemExtendedDataRecordClass[*pExtRecIndex]);

			/**
			 * @req [SWS_Dem_00815] If the configuration parameter DemExtendedDataRecordUpdate is
			 *      set to DEM_UPDATE_RECORD_NO,the ExtendedDataRecord shall be stored only if the
			 *      ExtendedDataRecord is currently not stored in this event memory entry.
			 *
			 * @req [SWS_Dem_00816] If the configuration parameter DemExtendedDataRecordUpdate is
			 *      set to DEM_UPDATE_RECORD_YES,the ExtendedDataRecord shall be updated with each
			 *      trigger (refer to DemExtendedDataRecordTrigger).
			 */

			if(pExtRecord->DemExtendedDataRecordTrigger == Trigger)
			{
				if((pExtRecord->DemExtendedDataRecordUpdate == DEM_UPDATE_RECORD_YES)\
						|| ((pExtRecord->DemExtendedDataRecordUpdate == DEM_UPDATE_RECORD_NO)\
								&& (pEntry->ExtInfo[u8Loop].RecNum == 0xFFu)))
				{
					pEntry->ExtInfo[u8Loop].RecNum = pExtRecord->DemExtendedDataRecordNumber;
					u16DataSize = pExtRecord->DemDataElementClassRefDataSize;

#if(DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONSTORAGE)
#if(DEM_COMBINA_DTC_NUM > 0)
					if(Dem_ConfigPtr->DemEventParameter[internalId].DemEventIsCombina == (boolean)TRUE)
					{
						pExtData = &(Dem_CombinaDtcInfo[Dem_ConfigPtr->DemEventParameter[internalId].\
													   DemDTCRef].ExtData[u16Offset]);
						DEM_VALUE_COPY(\
								pEntry->ExtInfo[u8Loop].ExtData,\
								&(pExtData[u16BufferIndex]),\
								u16DataSize);
					}
					else
#endif /* #if(DEM_COMBINA_DTC_NUM > 0) */
#endif /* #if(DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONSTORAGE) */
					{
						DEM_VALUE_COPY(\
								pEntry->ExtInfo[u8Loop].ExtData,\
								&(pBuffer->ExtData[u16BufferIndex]),\
								u16DataSize);
					}

					u16Offset += pExtRecord->DemDataElementClassRefDataSize;
				}
			}
			u16BufferIndex += pExtRecord->DemDataElementClassRefDataSize;
			u8Loop++;
			pExtRecIndex++;
		}
	}
}
#endif /* #if(DEM_EXTENDED_DATA_CLASS_NUM > 0) */

#if(DEM_EXTENDED_DATA_CLASS_NUM > 0)
STATIC FUNC(void, DEM_CODE)Dem_UpdataEntryExtContent
(
	uint8 Trigger,
	P2VAR(Dem_EventBufferType,AUTOMATIC,DEM_VAR)pBuffer,
	P2VAR(Dem_MemoryEntryType,AUTOMATIC,DEM_VAR) pEntry
)
{
	Dem_EventIdType internalId = pEntry->EventId - 1u;
	Dem_EventBufferType destBuffer;

#if(DEM_COMBINA_DTC_NUM > 0)
	uint16 u16DataSize = DEM_EXTENDED_DATA_MAX_LEN;
#endif /* #if(DEM_COMBINA_DTC_NUM > 0) */

	if(pBuffer == NULL_PTR)
	{
		pBuffer = &destBuffer;
		Dem_CaptureExtendedData(internalId,pBuffer->ExtData);
	}

#if(DEM_COMBINA_DTC_NUM > 0)
	if(Dem_ConfigPtr->DemEventParameter[internalId].DemEventIsCombina == (boolean)TRUE)
	{
		DEM_VALUE_COPY(\
				Dem_CombinaDtcInfo[Dem_ConfigPtr->\
							DemEventParameter[internalId].DemDTCRef].ExtData,\
				pBuffer->ExtData,\
				u16DataSize);
	}
#endif /* #if(DEM_COMBINA_DTC_NUM > 0) */

	Dem_StoreExtRecord(Trigger,pBuffer,pEntry);
}
#endif /* #if(DEM_EXTENDED_DATA_CLASS_NUM > 0) */

#if((DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU) || (DEM_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
STATIC FUNC(void, DEM_CODE)Dem_MemoryTransfer
(
	Dem_MemoryEntryType* pDestEntry,
	Dem_MemoryEntryType* pSrcEntry
)
{
	uint8 u8Loop = 0u;
	uint8 u8BufferSize = 0u;

#if(DEM_MAX_NUMBER_FF_RECORDS > 0)
	pDestEntry->LastestFF	= pSrcEntry->LastestFF;
	pDestEntry->FFStoreNum	= pSrcEntry->FFStoreNum;


	for(u8Loop = 0u; u8Loop < DEM_MAX_NUMBER_FF_RECORDS; u8Loop++)
	{
		u8BufferSize = DEM_FREEZE_FRAME_MAX_LEN;
		DEM_VALUE_COPY(\
					pDestEntry->FFInfo[u8Loop].FFData,\
					pSrcEntry->FFInfo[u8Loop].FFData,\
					u8BufferSize);
		pDestEntry->FFInfo[u8Loop].RecNum = pSrcEntry->FFInfo[u8Loop].RecNum;
	}
#endif /* #if(DEM_MAX_NUMBER_FF_RECORDS > 0) */

#if(DEM_PID_CLASS_NUM > 0)
	for(u8Loop = 0u; u8Loop < DEM_PID_CLASS_NUM; u8Loop++)
	{
		u8BufferSize = DEM_PID_DATA_MAX_LEN;
		DEM_VALUE_COPY(\
					pDestEntry->PidInfo[u8Loop].PidData,\
					pSrcEntry->PidInfo[u8Loop].PidData,\
					u8BufferSize);
		pDestEntry->PidInfo[u8Loop].PidId = pSrcEntry->PidInfo[u8Loop].PidId;
	}
#endif /* #if(DEM_PID_CLASS_NUM > 0) */

#if(DEM_MAX_NUMBER_EXT_REC > 0)
	for(u8Loop = 0u; u8Loop < DEM_MAX_NUMBER_EXT_REC; u8Loop++)
	{
		pDestEntry->ExtInfo[u8Loop].RecNum = pSrcEntry->ExtInfo[u8Loop].RecNum;
		u8BufferSize = DEM_EXTENDED_DATA_REC_MAX_LEN;
		DEM_VALUE_COPY(pDestEntry->ExtInfo[u8Loop].ExtData,\
						pSrcEntry->ExtInfo[u8Loop].ExtData,
						u8BufferSize);
	}
#endif /* #if(DEM_MAX_NUMBER_EXT_REC > 0) */
}
#endif /* #if((DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU) || (DEM_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU)) */


#if(DEM_DTC_NUM > 0)
STATIC FUNC(boolean, DEM_CODE)Dem_EntryAllocateConditionCheck
(
	Dem_EventIdType InternalId
)
{
	boolean ret = (boolean)FALSE;

#if(DEM_EVENTMEMORY_ENTRYSTORAGE_TRIGGER == DEM_TRIGGER_ON_CONFIRMED)
	/**
	 * @req [SWS_Dem_00785] If an event
	 *      1. gets confirmed (UDS DTC status bit 3 changes from 0 to 1) and
	 *      2. the configuration parameter DemEventMemoryEntryStorageTrigger
	 *         is set to DEM_TRIGGER_ON_CONFIRMED and
	 *      3. no event memory entry is existing,the Dem module shall try to
	 *         allocate according figure 7.26 an event memory entry in its
	 *         configured event memory.
	 */
	if(Dem_IsEnable_CDTCBitChange(InternalId) == (boolean)TRUE)
	{
		ret = (boolean)TRUE;
	}
#if(DEM_RESSET_CONFIRMEDBIT_ONOVERFLOW == STD_OFF)
	/**
	 * @req [SWS_Dem_00923] If an event
	 *      1. is confirmed (UDS DTC status bit 3 is set to 1) and gets re-qualified
	 *         as failed (UDS DTC status bit 0 changes from 0 to 1) and
	 *      2. the configuration parameter DemEventMemoryEntryStorageTrigger is set
	 *         to DEM_TRIGGER_ON_CONFIRMED and
	 *      3. no event event memory exists and
	 *      4. if DemResetConfirmedBitOnOverflow is set to false,the Dem module shall
	 *         try to allocate according Figure 7.26 an event memory entry in its
	 *         configured event memory.
	 */
	else if((Dem_ISEnable_UdsStatusBits(InternalId,DEM_UDS_STATUS_CDTC)  == (boolean)TRUE)\
			&& (Dem_ISEnable_TFBitChange(InternalId) == (boolean)TRUE))
	{
		ret = (boolean)TRUE;
	}
#endif /* #if(DEM_RESSET_CONFIRMEDBIT_ONOVERFLOW == STD_ON) */
#elif(DEM_EVENTMEMORY_ENTRYSTORAGE_TRIGGER == DEM_TRIGGER_ON_FDC_THRESHOLD)
	/*
	 * @req [SWS_Dem_00786] If an event
	 * 		1. has DemDebounceAlgorithmClass set to DemDebounceCounterBased and
	 * 		2. the internal debounce counter reaches the
	 * 		   DemEventMemoryEntryFdcThresholdStorageValue by a positive increment
	 * 		   via EventStatus set to preFailed and
	 * 		3. the configuration parameter DemEventMemoryEntryStorageTrigger is
	 * 		   set to DEM_TRIGGER_ON_FDC_THRESHOLD and
	 * 		4. no event event memory exists,
	 * 		the Dem module shall try to allocate according Figure 7.26 an event
	 * 		memory entry in its configured event memory
	 */
	if((Dem_IsEnable_FDCReachThreshold(InternalId) == (boolean)TRUE)&&(Dem_ConfigPtr->DemEventParameter\
			[InternalId].DemDebounceAlgorithmClassType == DEM_DEBOUNCE_COUNTER_BASED))
	{
		ret = (boolean)TRUE;
	}
#elif(DEM_EVENTMEMORY_ENTRYSTORAGE_TRIGGER == DEM_TRIGGER_ON_PENDING)
	/**
	 * @req [SWS_Dem_00784] If an event
	 *      1. gets pending (UDS DTC status bit 2 changes from 0 to 1) and
	 *      2. the configuration parameter DemEventMemoryEntryStorageTrigger is set to
	 *         DEM_TRIGGER_ON_PENDING and
	 *      3. no event memory entry is existing,
	 *      the Dem module shall try to allocate according figure 7.26 an event
	 *      memory entry in its configured event memory.
	 *
	 * @req [SWS_Dem_00922] If an event
	 *      1. is pending (UDS DTC status bit 2 is set to 1) and gets re-qualified as
	 *         failed (UDS DTC status bit 0 changes from 0 to 1) and
	 *      2. the configuration parameter DemEventMemoryEntryStorageTrigger is set to
	 *         DEM_TRIGGER_ON_PENDING and
	 *      3. no event memory entry is existing,
	 *      the Dem module shall try to allocate according figure 7.26 an event
	 *      memory entry in its configured event memory.
	 */
	if((Dem_IsEnable_PDTCBitChange(InternalId) == (boolean)TRUE)
		|| ((Dem_ISEnable_UdsStatusBits(InternalId,DEM_UDS_STATUS_PDTC) == (boolean)TRUE)\
			&& (Dem_ISEnable_TFBitChange(InternalId) == (boolean)TRUE)))
	{
		ret = (boolean)TRUE;
	}
#elif(DEM_EVENTMEMORY_ENTRYSTORAGE_TRIGGER == DEM_TRIGGER_ON_TEST_FAILED)
	/*
	 * @req [SWS_Dem_00783] If an event
	 * 		1. gets qualified as failed (UDS DTC status bit 0 changes from 0 to 1) and
	 * 		2. the configuration parameter DemEventMemoryEntryStorageTrigger is set to
	 * 		   DEM_TRIGGER_ON_TEST_FAILED and
	 * 		3. no event memory entry exist,
	 * 		the Dem module shall try to allocate according figure 7.26 an event memory
	 * 		entry in its configured event memory (refer to DemMemoryDestinationRef).
	 */
	if(Dem_ISEnable_TFBitChange(InternalId) == (boolean)TRUE)
	{
		ret = (boolean)TRUE;
	}
#endif /* #if(DEM_EVENTMEMORY_ENTRYSTORAGE_TRIGGER == DEM_TRIGGER_ON_CONFIRMED) */

	return ret;
}

STATIC FUNC(void, DEM_CODE)Dem_TriggerEventMemory
(
	Dem_EventIdType InternalId,
	P2VAR(Dem_EventBufferType,AUTOMATIC,DEM_VAR)pBuffer
)
{
	Dem_MemoryEntryType* pEntry = NULL_PTR;
	uint16 u16DtcRef = Dem_ConfigPtr->DemEventParameter[InternalId].DemDTCRef;
	const Dem_DTCAttributesType* pDtcAttr = NULL_PTR;
#if((DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU) || (DEM_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
	Dem_MemoryEntryType* pPermanentEntry = NULL_PTR;
#endif /* #if((DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU) || (DEM_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU)) */

	if(u16DtcRef != 0xFFFFu)
	{
		pDtcAttr = &(Dem_ConfigPtr->DemDTCAttributes[Dem_ConfigPtr->DemDTC[u16DtcRef].DemDTCAttributesRef]);

		if((Dem_DTCRecordUpdateInfo.DtcRef != u16DtcRef)
			|| (pDtcAttr->DemMemoryDestinationRef != Dem_DTCRecordUpdateInfo.DTCOrigin))
		{
			pEntry = Dem_EntryAllocate(InternalId,pDtcAttr->DemMemoryDestinationRef);

			if(pEntry != NULL_PTR)
			{
				Dem_TriggerCaptureData(InternalId,pEntry,pBuffer);

#if((DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU) || (DEM_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
				if((boolean)TRUE == Dem_CauseMILON(InternalId))
				{
					/* Refer to chapter 7.3.4,the emission-related events are automatically assigned to
					 * the permanent event memory. */
					pPermanentEntry = Dem_EntryAllocate(InternalId,DEM_DTC_ORIGIN_PERMANENT_MEMORY);
					if(pPermanentEntry != NULL_PTR)
					{
						Dem_MemoryTransfer(pPermanentEntry,pEntry);
					}
				}
#endif /* #if((DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU) || (DEM_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU)) */

#if(DEM_NVRAM_BLOCKID_NUM > 0)
				if(pDtcAttr->DemImmediateNvStorage == (boolean)TRUE)
				{
					if(Dem_EventInternalData[InternalId].occurCnt <= DEM_IMMEDIATE_NVSTORAGE_LIMIT)
					{
						/**
						 * @req [SWS_Dem_00552] If immediate non-volatile storage is enabled
						 *      for a specific DTC,the Dem module shall not trigger further
						 *      immediate write operations to NVRAM for this DTC, if its
						 *      occurrence counter has reached the threshold defined by the
						 *      configuration parameter DemImmediateNvStorageLimit (refer
						 *      to DemGeneral).
						 */
						Dem_WriteToNvRAM();
					}
				}
#endif /* #if(DEM_NVRAM_BLOCKID_NUM > 0) */
			}
		}
	}
}

#if((DEM_FREEZE_FRAME_CLASS_NUM > 0)||(DEM_EXTENDED_DATA_CLASS_NUM > 0))
STATIC FUNC(boolean, DEM_CODE)Dem_TriggerConditionCheck
(
	Dem_EventIdType InternalId,
	uint8 TriggerType,
	boolean CaptureFF
)
{
	boolean ret = (boolean)FALSE;
	uint16 u16DtcRef = Dem_ConfigPtr->DemEventParameter[InternalId].DemDTCRef;

	switch(TriggerType)
	{
	case DEM_TRIGGER_ON_TEST_FAILED:
		ret = Dem_ISEnable_TFBitChange(InternalId);
		break;

	case DEM_TRIGGER_ON_PENDING:
		ret = Dem_IsEnable_PDTCBitChange(InternalId);
		break;

	case DEM_TRIGGER_ON_FDC_THRESHOLD:
		if(Dem_IsEnable_FDCReachThreshold(InternalId) == (boolean)TRUE)
		{
			if(CaptureFF == (boolean)TRUE)
			{
#if(DEM_FREEZEFRAME_ENABLE == STD_ON)
				if(0u == DEM_U8BIT_ISENABLE(Dem_CaptureFFOnFDC,u16DtcRef))
				{
					DEM_U8BIT_ENABLE(Dem_CaptureFFOnFDC,u16DtcRef);
					ret = (boolean)TRUE;
				}
			}
#endif /* #if(DEM_FREEZEFRAME_ENABLE == STD_ON) */
#if(DEM_EXTENDED_DATA_CLASS_NUM > 0)
			if(CaptureFF == (boolean)FALSE) /* Capture Extended Data */
			{
				if(0u == DEM_U8BIT_ISENABLE(Dem_CaptureExtOnFDC,u16DtcRef))
				{
					DEM_U8BIT_ENABLE(Dem_CaptureExtOnFDC,u16DtcRef);
					ret = (boolean)TRUE;
				}
			}
#endif /* #if(DEM_EXTENDED_DATA_CLASS_NUM > 0) */
		}
		break;

	case DEM_TRIGGER_ON_CONFIRMED:
		ret = Dem_IsEnable_CDTCBitChange(InternalId);
		break;

	case DEM_TRIGGER_ON_PASSED:
		ret = Dem_IsEnable_TFBitReset(InternalId);
		break;

#if(DEM_MIRROR_MEMORY_NUM > 0)
	case DEM_TRIGGER_ON_MIRROR:
		break;
#endif /* #if(DEM_MIRROR_MEMORY_NUM > 0) */

	default:
		break;
	}
	return ret;
}
#endif /* #if((DEM_FREEZE_FRAME_CLASS_NUM > 0)||(DEM_EXTENDED_DATA_CLASS_NUM > 0)) */

STATIC FUNC(void, DEM_CODE)Dem_TriggerCaptureData
(
	Dem_EventIdType InternalId,
	P2VAR(Dem_MemoryEntryType,AUTOMATIC,DEM_VAR) pEntry,
	P2VAR(Dem_EventBufferType,AUTOMATIC,DEM_VAR) pBuffer
)
{
	uint8 u8Loop;
	const Dem_DTCAttributesType* pDtcAttr = &(Dem_ConfigPtr->DemDTCAttributes[Dem_ConfigPtr->\
											 DemDTC[Dem_ConfigPtr->DemEventParameter[InternalId].\
											 DemDTCRef].DemDTCAttributesRef]);

#if(DEM_TYPEOFFF_RECORD_NUMERATION == DEM_FF_RECNUM_CONFIGURED)
#if(DEM_FREEZE_FRAME_REC_NUM_CLASS_NUM > 0)
	const Dem_FreezeFrameRecNumClassType* pFFRecNumCls = NULL_PTR;
#endif /* #if(DEM_FREEZE_FRAME_REC_NUM_CLASS_NUM > 0) */

#if(DEM_FREEZE_FRAME_RECORD_CLASS_NUM > 0)
	const Dem_FreezeFrameRecordClassType* pFFRecCls = NULL_PTR;
#endif /* #if(DEM_FREEZE_FRAME_RECORD_CLASS_NUM > 0) */
#endif /* #if(DEM_TYPEOFFF_RECORD_NUMERATION == DEM_FF_RECNUM_CONFIGURED) */

#if(DEM_EXTENDED_DATA_CLASS_NUM > 0)
	const Dem_ExtendedDataClassType* pExtDataCls = NULL_PTR;
#endif /* #if(DEM_EXTENDED_DATA_CLASS_NUM > 0) */

#if(DEM_EXTENDED_DATA_RECORD_CLASS_NUM > 0)
	const Dem_ExtendedDataRecordClassType* pExtDataRecCls = NULL_PTR;
#endif /* #if(DEM_EXTENDED_DATA_RECORD_CLASS_NUM > 0) */

#if(DEM_FREEZE_FRAME_CLASS_NUM > 0)
	if(pDtcAttr->DemFreezeFrameClassRef != 0xFFFFu)
	{
#if(DEM_TYPEOFFF_RECORD_NUMERATION == DEM_FF_RECNUM_CONFIGURED)
#if((DEM_FREEZE_FRAME_REC_NUM_CLASS_NUM > 0)&&(DEM_FREEZE_FRAME_RECORD_CLASS_NUM > 0))
		if(pDtcAttr->DemFreezeFrameRecNumClassRef != 0xFFu)
		{
			pFFRecNumCls = &Dem_General.DemFreezeFrameRecNumClass[pDtcAttr->DemFreezeFrameRecNumClassRef];
			for(u8Loop = 0u; u8Loop < pFFRecNumCls->DemFreezeFrameRecordClassRefNum; u8Loop++)
			{
				pFFRecCls = &Dem_General.DemFreezeFrameRecordClass[\
							 pFFRecNumCls->DemFreezeFrameRecordClassRefStartIndex[u8Loop]];

				if((boolean)TRUE == Dem_TriggerConditionCheck(\
						InternalId,pFFRecCls->DemFreezeFrameRecordTrigger,(boolean)TRUE))
				{
					Dem_UpdateEntryFFContent(pFFRecCls->DemFreezeFrameRecordTrigger, pBuffer,pEntry);
				}
			}
		}
#endif /* #if((DEM_FREEZE_FRAME_REC_NUM_CLASS_NUM > 0)&&(DEM_FREEZE_FRAME_RECORD_CLASS_NUM > 0)) */
#else /* (DEM_TYPEOFFF_RECORD_NUMERATION == DEM_FF_RECNUM_CALCULATED) */
		/* If DemTypeOfFreezeFrameRecordNumeration = DEM_FF_RECNUM_CALCULATED, the default condition
		 * for triggering freeze frame storage or update is DEM_TRIGGER_ON_TEST_FAILED. */
		if(pDtcAttr->DemMaxNumberFreezeFrameRecords > 0u)
		{
			if(Dem_TriggerConditionCheck(InternalId,DEM_TRIGGER_ON_TEST_FAILED,(boolean)TRUE))
			{
				Dem_UpdateEntryFFContent(DEM_TRIGGER_ON_TEST_FAILED,pBuffer,pEntry);
			}
		}
#endif /* #if(DEM_TYPEOFFF_RECORD_NUMERATION == DEM_FF_RECNUM_CONFIGURED) */
	}
#endif /* #if(DEM_FREEZE_FRAME_CLASS_NUM > 0) */

#if(DEM_EXTENDED_DATA_CLASS_NUM > 0)
	if(pDtcAttr->DemExtendedDataClassRef != 0xFFFFu)
	{
		pExtDataCls = &Dem_General.DemExtendedDataClass[pDtcAttr->DemExtendedDataClassRef];
		for(u8Loop = 0u; u8Loop < pExtDataCls->DemExtendedDataRecordClassRefNum; u8Loop++)
		{
			pExtDataRecCls = &Dem_General.DemExtendedDataRecordClass[\
							  pExtDataCls->DemExtendedDataRecordClassRefStartIndex[u8Loop]];

			if((boolean)TRUE == Dem_TriggerConditionCheck(\
					InternalId,pExtDataRecCls->DemExtendedDataRecordTrigger,(boolean)FALSE))
			{
				Dem_UpdataEntryExtContent(pExtDataRecCls->DemExtendedDataRecordTrigger,pBuffer,pEntry);
			}
		}
	}
#endif /* #if(DEM_EXTENDED_DATA_CLASS_NUM > 0) */

#if((DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT) && (DEM_PID_CLASS_NUM > 0))
	if(Dem_ConfigPtr->DemDTC[Dem_ConfigPtr->DemEventParameter[InternalId].DemDTCRef].\
			DemObdDTCRef != 0xFFFFu)
	{
		/**
		 * @req [SWS_Dem_01170] The legislative Freeze Frame 0x00 shall be stored on transition
		 * 		of DTC status bit 2 (PendingDTC) from 0 to 1 (via DemFreezeFrameRecordTrigger
		 * 		set to DEM_TRIGGER_ON_PENDING).
		 */
		if((boolean)TRUE == Dem_IsEnable_PDTCBitChange(InternalId))
		{
			Dem_StorePidClass(InternalId,pBuffer);
		}
	}
#endif /* #if((DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT) && (DEM_PID_CLASS_NUM > 0)) */
}
#endif /* #if(DEM_DTC_NUM > 0) */

STATIC FUNC(void, DEM_CODE)Dem_EventConfirmedDeal
(
	Dem_EventIdType InternalId
)
{
	const Dem_EventParameterType* pEventPara = &(Dem_ConfigPtr->DemEventParameter[InternalId]);

#if(DEM_DTC_NUM > 0)
	uint16 u16DtcRef = pEventPara->DemDTCRef;

	const Dem_DTCAttributesType* pDtcAttr;
#endif /* #if(DEM_DTC_NUM > 0) */

	if((boolean)FALSE == Dem_ISEnable_UdsStatusBits(InternalId,DEM_UDS_STATUS_CDTC))
	{
		if(Dem_EventInternalData[InternalId].failedCycles >= \
				pEventPara->DemEventFailureCycleCounterThreshold)
		{
#if(DEM_DTC_NUM > 0)
			if(u16DtcRef != 0xFFFFu)
			{
				pDtcAttr = &(Dem_ConfigPtr->DemDTCAttributes[Dem_ConfigPtr->DemDTC[u16DtcRef].\
															 DemDTCAttributesRef]);

				if(pDtcAttr->DemMemoryDestinationRef == DEM_DTC_ORIGIN_PRIMARY_MEMORY)
				{
					if (Dem_EventOccTime.firstConfEvent == 0xFFFFu)
					{
						Dem_EventOccTime.firstConfEvent = InternalId;
					}
					Dem_EventOccTime.mostConfEvent = InternalId;
				}
#endif /* #if(DEM_DTC_NUM > 0) */
#if(DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT)
				if((Dem_General.DemOperationCycle[pEventPara->DemOperationCycleRef].\
						DemOperationCycleType == DEM_OPCYC_OBD_DCY)\
						&&((boolean)FALSE == Dem_ISEnable_OperationCycle(pEventPara->DemOperationCycleRef)))
				{
					/**
					 * @req [SWS_Dem_00700] If the OBD driving cycle has ended,status reports shall
					 *      be processed, except update of the confirmed status.
					 */
				}
				else
#endif /* #if(DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT) */
				{
					/**
					 * @req [SWS_Dem_00379] Depending on the design decision (synchronous or
					 *      asynchronous event processing) the status update of the following
					 *      bits:
					 *      --Bit 2 PendingDTC
					 *      --Bit 3 ConfirmedDTC
					 *      --Bit 7 WarningIndicatorRequested
					 */
					Dem_Enable_UdsStatusBits(InternalId,DEM_UDS_STATUS_CDTC);
					Dem_Enable_CDTCBitChange(InternalId);
				}
#if(DEM_DTC_NUM > 0)
			}
#endif /* #if(DEM_DTC_NUM > 0) */
		}
	}
}

STATIC FUNC(void, DEM_CODE)Dem_FailedEventHandle
(
	Dem_EventIdType InternalId
)
{
	boolean isStorage = (boolean)FALSE;
#if(DEM_DTC_NUM > 0)
	const Dem_EventParameterType* pEventPara = &(Dem_ConfigPtr->DemEventParameter[InternalId]);
	const Dem_DTCAttributesType* pDtcAttr = NULL_PTR;
	uint16 u16DtcRef = pEventPara->DemDTCRef;

	Dem_MemoryEntryType* pEntry = NULL_PTR;

	if(u16DtcRef != 0xFFFFu)
	{
		pDtcAttr = &Dem_ConfigPtr->DemDTCAttributes[Dem_ConfigPtr->DemDTC[u16DtcRef].DemDTCAttributesRef];

		if(pDtcAttr->DemMemoryDestinationRef == DEM_DTC_ORIGIN_PRIMARY_MEMORY)
		{
			if((boolean)FALSE == Dem_ISEnable_UdsStatusBits(InternalId,DEM_UDS_STATUS_TF))
			{
				if(Dem_EventOccTime.firstFailEvent == 0xFFFFu)
				{
					Dem_EventOccTime.firstFailEvent = InternalId;
				}
				Dem_EventOccTime.mostFailEvent = InternalId;
			}
		}

		pEntry = Dem_GetEntryFromMemory(pDtcAttr->DemMemoryDestinationRef,(InternalId + 1u));

		if(pEntry != NULL_PTR)
		{
			isStorage = (boolean)TRUE;
		}
	}
#endif /* #if(DEM_DTC_NUM > 0) */

	Dem_Enable_UdsStatusBits(InternalId,DEM_UDS_STATUS_TF);
	Dem_Enable_UdsStatusBits(InternalId,DEM_UDS_STATUS_TFSLC);
	Dem_Disable_UdsStatusBits(InternalId,DEM_UDS_STATUS_TNCTOC);
	Dem_Disable_UdsStatusBits(InternalId,DEM_UDS_STATUS_TNCSLC);
	Dem_Enable_TFBitChange(InternalId);
	Dem_Disable_TFBitReset(InternalId);
	Dem_Enable_EventActive(InternalId);/*If an event gets qualified as failed, it becomes active.*/

#if(DEM_COMPONENT_NUM > 0)
	/**
	 * @req [SWS_Dem_01123] On reporting an error (eventstatus FAILED) for an event, the
	 * 		assigned DemComponent shall be set as FAILED.
	 * @req [SWS_Dem_01124] On setting a DemComponent to FAILED, all dependent components
	 * 		shall be set as FAILED.
	 */
	Dem_SetChildComponentFailed(Dem_ConfigPtr->DemEventParameter[InternalId].DemComponentClassRef);
#endif /* #if(DEM_COMPONENT_NUM > 0) */

	if((boolean)FALSE == (Dem_ISEnable_UdsStatusBits(InternalId,DEM_UDS_STATUS_TFTOC)))
	{
		/* Only the first time DEM_UDS_STATUS_TFTOC be set,the cycle FailureCounter shall be add */
		Dem_Enable_UdsStatusBits(InternalId,DEM_UDS_STATUS_TFTOC);
		Dem_EventInternalData[InternalId].cyclesSinceLastFailed = 0u;
		Dem_EventInternalData[InternalId].agingUpCnt = 0u;
	}

	/* Set PendingDTC */
	if((boolean)FALSE == (Dem_ISEnable_UdsStatusBits(InternalId,DEM_UDS_STATUS_PDTC)))
	{
		Dem_Enable_UdsStatusBits(InternalId,DEM_UDS_STATUS_PDTC);
		Dem_Enable_PDTCBitChange(InternalId);
	}

	/* Set ConfirmedDTC */
	Dem_EventConfirmedDeal(InternalId);

	if(isStorage == (boolean)TRUE)
	{
		/**
		 * @req [SWS_Dem_00524] If the configuration parameter DemOccurrenceCounterProcessing is
		 *      DEM_PROCESS_OCCCTR_TF , the Dem module shall increment the occurrence counter by
		 *      one, triggered by each UDS DTC status bit 0 (TestFailed) transition from 0 to 1,
		 *      if the related event is already stored in the event memory.
		 */
		if((boolean)TRUE == Dem_ISEnable_TFBitChange(InternalId))
		{
			/**
			 * @req [SWS_Dem_00580] If the configuration parameter DemOccurrenceCounterProcessing
			 * 		(refer to Dem_General) is DEM_PROCESS_OCCCTR_CDTC, the Dem module shall increment
			 * 		the occurrence counter by one, triggered by each UDS DTC status bit 0 (TestFailed)
			 * 		transition from 0 to 1, if the related event is already stored in the event memory
			 * 		and the UDS DTC Status bit 3 (ConfirmedDTC) is equal to 1.
			 */
#if(DEM_OCCIRRENCE_COUNTER_PROCESSING == DEM_PROCESS_OCCCTR_CDTC)
			if((boolean)TRUE == Dem_ISEnable_UdsStatusBits(InternalId,DEM_UDS_STATUS_CDTC))
#endif /* #if(DEM_OCCIRRENCE_COUNTER_PROCESSING == DEM_PROCESS_OCCCTR_CDTC) */
			{
				/**
				 * @req [SWS_Dem_00625] The Dem module shall not increment the event-specific
				 * 		occurrence counter anymore, if it has reached its maximum value 255.
				 */
				if(Dem_EventInternalData[InternalId].occurCnt < 0xFFu)
				{
					Dem_EventInternalData[InternalId].occurCnt++;
				}
			}
		}
	}

#if(DEM_INDICATOR_ATTRIBUTE_TOTAL_NUM > 0)
	if ((boolean)TRUE == Dem_CheckWIROn(InternalId))
	{
		/**
		 * @req [SWS_Dem_00501] The Dem module shall generate the condition
		 *      WarningIndicatorOnCriteriaFulfilled specific for the assigned
		 *      warning indicator, if the respective indicator failure counter
		 *      of the event entry has been processed (counted further)
		 *      DemIndicatorFailureCycleCounterThreshold times.
		 */
		Dem_Enable_UdsStatusBits(InternalId,DEM_UDS_STATUS_WIR);
		Dem_EventInternalData[InternalId].healingCnt = 0u;
	}
#endif /* #if(DEM_INDICATOR_ATTRIBUTE_TOTAL_NUM > 0) */

#if(DEM_DTC_NUM > 0)
	Dem_SetCombineDtcStatus(InternalId);
#endif /* #if(DEM_DTC_NUM > 0) */
}

#if(DEM_INDICATOR_ATTRIBUTE_TOTAL_NUM > 0)
STATIC FUNC(boolean, DEM_CODE)Dem_CheckWIROn
(
	Dem_EventIdType InternalId
)
{
	boolean ret = (boolean)FALSE;
	uint8 u8Loop = 0u;
	const Dem_EventParameterType* pEventPara = &(Dem_ConfigPtr->DemEventParameter[InternalId]);
	const Dem_IndicatorAttributeType* pIndicatorAttr = pEventPara->DemIndicatorAttribute;

	/**
	 * @req [SWS_Dem_00566] If more than one indicator is configured for a specific event,
	 *      the Dem module shall use a logical OR operation of all combined warning indicators
	 *      assigned to this event to calculate the UDS DTC status bit 7 (WarningIndicator).
	 */
	while(u8Loop < pEventPara->DemIndicatorAttributeNum)
	{
		/**
		 * @req [SWS_Dem_00500] The Dem module shall provide the configuration parameter
		 *      DemIndicatorFailureCycleCounterThreshold per indicator per event (refer
		 *      to DemIndicatorAttribute) to define the maximum number of tested and
		 *      failed cycles, before the respective indicator is activated.
		 *
		 * @req [SWS_Dem_00501] The Dem module shall generate the condition WarningIndicator-
		 *      OnCriteriaFulfilled specific for the assigned warning indicator,if the respective
		 *      indicator failure counter of the event entry has been processed (counted further)
		 *      DemIndicatorFailureCycleCounterThreshold times.
		 */
		if((Dem_EventInternalData[InternalId].failedCycles >= \
				pIndicatorAttr->DemIndicatorFailureCycleCounterThreshold)
#if((DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU) || (DEM_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
			|| ((pEventPara->DemOBDGroupingAssociativeEventsRef != 0xFFFFu)\
				&& (Dem_EventInternalData[pEventPara->DemOBDGroupingAssociativeEventsRef].\
					failedCycles >= pIndicatorAttr->DemIndicatorFailureCycleCounterThreshold))
#endif /* #if((DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU) || (DEM_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU)) */
			)
		{
			ret = (boolean)TRUE;
#if((DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU) || (DEM_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
#if(DEM_OBD_COMPLIANCY == 15u)
			if(pIndicatorAttr->DemIndicatorRef != DEM_MILINDICATOR_REF)
#endif /* #if(DEM_OBD_COMPLIANCY == 15u) */
#endif /* #if((DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU) || (DEM_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU)) */
			{
				Dem_IndicatorStatus[pIndicatorAttr->DemIndicatorRef] = \
												pIndicatorAttr->DemIndicatorBehaviour;
			}
		}
		pIndicatorAttr++;
		u8Loop++;
	}
	return ret;
}
#endif /* #if(DEM_INDICATOR_ATTRIBUTE_TOTAL_NUM > 0) */

STATIC FUNC(void, DEM_CODE)Dem_PassedEventHandle
(
	Dem_EventIdType InternalId
)
{
#if(DEM_DTC_NUM > 0)
#if(DEM_RESSET_CONFIRMEDBIT_ONOVERFLOW == STD_OFF)
	uint8 u8EntryLoop = 0u;
	uint8 u8EntryNum = 0u;
	uint8 u8AbsTime = 0u;
	Dem_MemoryEntryType* pEntry;
	Dem_MemoryEntryType* entryPtr;
	Dem_MemoryInfoType* pMemInfo;
#endif /* #if(DEM_RESSET_CONFIRMEDBIT_ONOVERFLOW == STD_OFF) */
	uint16 u16DtcRef = Dem_ConfigPtr->DemEventParameter[InternalId].DemDTCRef;
	const Dem_DTCAttributesType* pDtcAttr = NULL_PTR;
#endif /* #if(DEM_DTC_NUM > 0) */

	/* clear bit0 TestFailed */
	Dem_Disable_UdsStatusBits(InternalId, DEM_UDS_STATUS_TF);

	/* clear bit4 TestNotCompletedSinceLastClear */
	Dem_Disable_UdsStatusBits(InternalId, DEM_UDS_STATUS_TNCSLC);

	/* clear bit6 TestNotCompletedThisOperationCycle */
	Dem_Disable_UdsStatusBits(InternalId, DEM_UDS_STATUS_TNCTOC);

	/* If an event gets qualified as failed, it becomes active.
	 * If the event gets qualified as passed,it becomes passive. */
	Dem_Disable_EventActive(InternalId);

	Dem_Disable_TFBitChange(InternalId);
	Dem_Enable_TFBitReset(InternalId);

#if(DEM_DTC_NUM > 0)

	if(u16DtcRef != 0xFFFFu)
	{
		pDtcAttr = &(Dem_ConfigPtr->DemDTCAttributes[Dem_ConfigPtr->\
							DemDTC[u16DtcRef].DemDTCAttributesRef]);

		if((Dem_ISEnable_UdsStatusBits(InternalId,DEM_UDS_STATUS_CDTC) == (boolean)TRUE)\
				|| (pDtcAttr->DemAgingAllowed == (boolean)TRUE))
		{
#if(DEM_RESSET_CONFIRMEDBIT_ONOVERFLOW == STD_OFF)
			/**
			 * @req [SWS_Dem_00823] If configuration parameter DemResetConfirmedBitOnOverflow is set
			 *      to false and in case an event has UDS status bit 3 (ConfirmedDTC) set and gets
			 *      qualified as passed and is not stored in an event memory entry the Dem module shall
			 *      try to allocate an event memory entry to get an aging counter.If it is not possible
			 *      to allocate an event memory entry, the aging delays until an event memory entry
			 *      becomes available.
			 */
			pMemInfo = Dem_GetMemInfoByOrigin(pDtcAttr->DemMemoryDestinationRef);
			pEntry = Dem_GetEntryFromMemory(pDtcAttr->DemMemoryDestinationRef,(InternalId + 1u));

			if((pMemInfo != NULL_PTR) && (pEntry == NULL_PTR))
			{
				pEntry = Dem_GetEntryFromMemory(pDtcAttr->DemMemoryDestinationRef,0u);
				entryPtr = Dem_GetMemoryConf(pDtcAttr->DemMemoryDestinationRef,&u8EntryNum);
			}

			if(pEntry != NULL_PTR)
			{
				pMemInfo->EntryNum++;
				if(pMemInfo->EntryNum == u8EntryNum)
				{
					pMemInfo->OverFlow = (boolean)TRUE;
				}

				pEntry->EventId = InternalId + 1u;
				pEntry->AgingCounter = 0u;

				do
				{
					if(u8AbsTime < entryPtr->AbsTime)
					{
						u8AbsTime = entryPtr->AbsTime;
					}
					entryPtr++;
					u8EntryLoop++;
				}while(u8EntryLoop < u8EntryNum);

				pEntry->AbsTime = u8AbsTime + 1u;
			}
			else
			{
				/* If it is not possible to allocate an event memory entry, the aging
				 * delays until an event memory entry becomes available. */
			}
#endif /* #if(DEM_RESSET_CONFIRMEDBIT_ONOVERFLOW == STD_OFF) */

			Dem_SetCombineDtcStatus(InternalId);

			/**
			 * @req [SWS_Dem_00465] If an event gets qualified as passed (UDS DTC status bit 0
			 *      changes from 1 to 0)the Dem module shall release the pre-stored freeze frame
			 *      for the specific event.
			 */
#if(DEM_MAXNUMBER_PRESTORED_FF > 0)
			Dem_ClearPreFF((InternalId + 1u));
#endif /* #if(DEM_MAXNUMBER_PRESTORED_FF > 0) */
		}
	}
#endif /* #if(DEM_DTC_NUM > 0) */
}

/*====================================================================================================*
 *                                          GLOBAL FUNCTIONS
 *====================================================================================================*/
#if (DEM_VERSION_INFO_API == STD_ON)
/**
 * @sid				0x00
 * @brief			Dem_GetVersionInfo
 * @details			Returns the version information of this module.
 * @param[out]		versionInfo:Pointer to where to store the version information of this module.
 */
FUNC(void, DEM_CODE)Dem_GetVersionInfo
(
	P2VAR(Std_VersionInfoType,AUTOMATIC,DEM_VAR)pVersioninfo
)
{
	if(pVersioninfo == NULL_PTR)
	{
		DEM_DET_ERROR_REPORT(DEM_SID_GETVERSIONINFO,DEM_E_PARAM_POINTER);
	}
	else
	{
		pVersioninfo->moduleID = DEM_MODULE_ID;
		pVersioninfo->vendorID = DEM_VENDOR_ID;
		pVersioninfo->sw_major_version = DEM_SW_MAJOR_VERSION;
		pVersioninfo->sw_minor_version = DEM_SW_MINOR_VERSION;
		pVersioninfo->sw_patch_version = DEM_SW_PATCH_VERSION;
	}
}
#endif /* #if (DEM_VERSION_INFO_API == STD_ON) */


/**
 * @sid				0x01
 * @brief			Dem_PreInit
 * @details			Initializes the internal states necessary to process events reported
 *                  by BSW-modules.
 */
FUNC(void, DEM_CODE) Dem_PreInit
(
	void
)
{
	uint16 u16Loop = 0u;
	uint8 u8Loop = 0u;

	if(Dem_InitState != DEM_STATE_UNINIT)
	{
		DEM_DET_ERROR_REPORT(DEM_SID_PREINIT,DEM_E_INIT_FAILED);
	}
	else
	{
		for(u16Loop = 0u; u16Loop < DEM_MAX_NUMBER_EVENTENTRY_PRIMARY; u16Loop++)
		{
			DemPrimaryMemory[u16Loop].EventId = 0u;
			DemPrimaryMemory[u16Loop].UdsStatus = 0x50u;
			DemPrimaryMemory[u16Loop].AbsTime = 0u;
			DemPrimaryMemory[u16Loop].AgingCounter = 0u;
			DemPrimaryMemory[u16Loop].HealingCounter = 0u;
			DemPrimaryMemory[u16Loop].FailureCounter = 0u;
			DemPrimaryMemory[u16Loop].OccurrenceCounter = 0u;
			DemPrimaryMemory[u16Loop].CyclesSinceFirstFailed = 0u;
			DemPrimaryMemory[u16Loop].CyclesSinceLastFailed = 0u;
#if(DEM_MAX_NUMBER_FF_RECORDS > 0)
			DemPrimaryMemory[u16Loop].FFStoreNum = 0u;
			DemPrimaryMemory[u16Loop].LastestFF = 0u;
#endif /* #if(DEM_MAX_NUMBER_FF_RECORDS > 0) */

#if(DEM_MAX_NUMBER_FF_RECORDS > 0)
			for(u8Loop = 0u; u8Loop < DEM_MAX_NUMBER_FF_RECORDS; u8Loop++)
			{
				DemPrimaryMemory[u16Loop].FFInfo[u8Loop].RecNum = 0xFFu;
				DEM_VALUE_SET(DemPrimaryMemory[u16Loop].FFInfo[u8Loop].FFData,\
								0xFFu,DEM_FREEZE_FRAME_MAX_LEN);
			}
#endif /* #if(DEM_MAX_NUMBER_FF_RECORDS > 0) */

#if(DEM_MAX_NUMBER_EXT_REC > 0)
			for(u8Loop = 0u; u8Loop < DEM_MAX_NUMBER_EXT_REC; u8Loop++)
			{
				DemPrimaryMemory[u16Loop].ExtInfo[u8Loop].RecNum = 0xFFu;
				DEM_VALUE_SET(DemPrimaryMemory[u16Loop].ExtInfo[u8Loop].ExtData,\
								0xFFu,DEM_EXTENDED_DATA_REC_MAX_LEN);
			}
#endif /* #if(DEM_MAX_NUMBER_EXT_REC > 0) */

#if(DEM_PID_CLASS_NUM > 0)
			for(u8Loop = 0u; u8Loop < DEM_PID_CLASS_NUM; u8Loop++)
			{
				DemPrimaryMemory[u16Loop].PidInfo[u8Loop].PidId = 0xFFu;
				DEM_VALUE_SET(DemPrimaryMemory[u16Loop].PidInfo[u8Loop].PidData,\
								0xFFu,DEM_PID_DATA_MAX_LEN);
			}
#endif /* #if(DEM_PID_CLASS_NUM > 0) */
		}

#if(DEM_MAX_NUMBER_EVENTENTRY_PERMANENT > 0)
		for(u16Loop = 0u; u16Loop < DEM_MAX_NUMBER_EVENTENTRY_PERMANENT; u16Loop++)
		{
			DemPermanentMemory[u16Loop].EventId = 0u;
			DemPermanentMemory[u16Loop].UdsStatus = 0x50u;
			DemPermanentMemory[u16Loop].AbsTime = 0u;
			DemPermanentMemory[u16Loop].AgingCounter = 0u;
			DemPermanentMemory[u16Loop].HealingCounter = 0u;
			DemPermanentMemory[u16Loop].FailureCounter = 0u;
			DemPermanentMemory[u16Loop].OccurrenceCounter = 0u;
			DemPermanentMemory[u16Loop].CyclesSinceFirstFailed = 0u;
			DemPermanentMemory[u16Loop].CyclesSinceLastFailed = 0u;
#if(DEM_MAX_NUMBER_FF_RECORDS > 0)
			DemPermanentMemory[u16Loop].FFStoreNum = 0u;
			DemPermanentMemory[u16Loop].LastestFF = 0u;
#endif /* #if(DEM_MAX_NUMBER_FF_RECORDS > 0) */

#if(DEM_MAX_NUMBER_FF_RECORDS > 0)
			for(u8Loop = 0u; u8Loop < DEM_MAX_NUMBER_FF_RECORDS; u8Loop++)
			{
				DemPermanentMemory[u16Loop].FFInfo[u8Loop].RecNum = 0xFFu;
				DEM_VALUE_SET(DemPermanentMemory[u16Loop].FFInfo[u8Loop].FFData,\
								0xFFu,DEM_FREEZE_FRAME_MAX_LEN);
			}
#endif /* #if(DEM_MAX_NUMBER_FF_RECORDS > 0) */

#if(DEM_MAX_NUMBER_EXT_REC > 0)
			for(u8Loop = 0u; u8Loop < DEM_MAX_NUMBER_EXT_REC; u8Loop++)
			{
				DemPermanentMemory[u16Loop].ExtInfo[u8Loop].RecNum = 0xFFu;
				DEM_VALUE_SET(DemPermanentMemory[u16Loop].ExtInfo[u8Loop].ExtData,\
								0xFFu,DEM_EXTENDED_DATA_REC_MAX_LEN);
			}
#endif /* #if(DEM_MAX_NUMBER_EXT_REC > 0) */

#if(DEM_PID_CLASS_NUM > 0)
			for(u8Loop = 0u; u8Loop < DEM_PID_CLASS_NUM; u8Loop++)
			{
				DemPermanentMemory[u16Loop].PidInfo[u8Loop].PidId = 0xFFu;
				DEM_VALUE_SET(DemPermanentMemory[u16Loop].PidInfo[u8Loop].PidData,\
								0xFFu,DEM_PID_DATA_MAX_LEN);
			}
#endif /* #if(DEM_PID_CLASS_NUM > 0) */
		}
#endif /* #if(DEM_MAX_NUMBER_EVENTENTRY_PERMANENT > 0) */

		/**
		 * @req [SWS_Dem_00180] The function Dem_PreInit shall initialize the internal states of
		 *      the Dem module necessary to process events and reset debounce counters reported
		 *      by BSW modules by using Dem_ReportErrorStatus and Dem_ResetEventDebounceStatus.
		 */
#if(DEM_ENABLE_CONDITION_NUM > 0)
		DEM_VALUE_COPY(Dem_EnableConditionStatus,Dem_General.DemEnableCondition,DEM_ENABLE_CONDITION_NUM_BYTE);
#endif /* #if(DEM_ENABLE_CONDITION_NUM > 0) */

#if(DEM_STORAGE_CONDITION_GROUP_NUM > 0)
		DEM_VALUE_SET(Dem_StorageConditionStatus,0x00u,DEM_STORAGE_CONDITION_NUM_BYTE);

		for(u8Loop = 0u; u8Loop < DEM_STORAGE_CONDITION_NUM; u8Loop++)
		{
			if((boolean)TRUE == Dem_General.DemStorageCondition[u8Loop].DemStorageConditionStatus)
			{
				Dem_Enable_EvStorageCondition(u8Loop);
			}
		}
#endif /* #if(DEM_STORAGE_CONDITION_NUM > 0) */

		DEM_VALUE_SET(Dem_OperationCycleStatus,0x00u,DEM_OPERATION_CYCLE_NUM_BYTE);

		/**
		 * @req [SWS_Dem_00853] For all operation cycles with DemOperationCycleAutostart set to
		 *      true Dem_Init shall start the operation cycle (identical to Dem_SetOperationCy-
		 *      cleState is called with parameter DEM_CYCLE_STATE_START) with the exception of
		 *      executing all callbacks resulting from UDS status byte changes.
		 */
		for(u16Loop = 0u; u16Loop < DEM_OPERATION_CYCLE_NUM; u16Loop++)
		{
			if(Dem_General.DemOperationCycle[u16Loop].DemOperationCycleAutostart == (boolean)TRUE)
			{
				/* During the pre-initialization of DEM,the global pointer Dem_ConfigPtr is not initialized.Therrfore,
				 * the behavior of starting the operation cycle is handle asynchronously in the Dem_Init() interface. */
				Dem_Enable_OperationCycle((uint8)u16Loop); /* PRQA S 2984 #violate MISAR2004_21.1: The value of the result is variable */
			}
		}

		for(u16Loop = 0u; u16Loop < DEM_EVENT_PARAMETER_NUM; u16Loop++)
		{
			Dem_EventInternalData[u16Loop].agingDownCnt = 0u;
			Dem_EventInternalData[u16Loop].agingUpCnt = 0u;
			Dem_EventInternalData[u16Loop].currentFDC = (sint8)0;
			Dem_EventInternalData[u16Loop].cyclesSinceFirstFailed = 0u;
			Dem_EventInternalData[u16Loop].cyclesSinceLastFailed = 0u;
			Dem_EventInternalData[u16Loop].failedCycles = 0u;
			Dem_EventInternalData[u16Loop].healingCnt = 0u;
			Dem_EventInternalData[u16Loop].occurCnt = 0u;
			Dem_EventInternalData[u16Loop].overflowIndication = 0u;
			Dem_EventInternalData[u16Loop].significance = 0u;

			Dem_InternalEventStatus[u16Loop] = 0u;
			Dem_EventUDSBitStatus[u16Loop] = 0x50u;
		}

		for(u16Loop = 0u; u16Loop < DEM_EVENT_QUEUE_SIZE; u16Loop++)
		{
			/**
			 * @req [SWS_Dem_00167] The Dem module shall provide a buffer mechanism (FIFO) to queue
			 *      events which are reported before Dem_Init via Dem_ReportErrorStatus as qualified
			 *      (Failed/Passed) or reaching the qualification (the Dem module cannot access the
			 *      event memory).
			 */
			Dem_EventQueue[u16Loop].eventId = 0u;
			Dem_EventQueue[u16Loop].status = 0u;
			Dem_EventQueue[u16Loop].reportStatus = DEM_STATE_UNINIT;
#if(DEM_ENVIRONMENT_DATA_CAPTURE == DEM_CAPTURE_SYNCHRONOUS_TO_REPORTING)
			Dem_EventQueue[u16Loop].captureData = (boolean)FALSE;
#endif /* #if(DEM_ENVIRONMENT_DATA_CAPTURE == DEM_CAPTURE_SYNCHRONOUS_TO_REPORTING) */

#if(DEM_EXTENDED_DATA_MAX_LEN > 0)
			DEM_VALUE_SET(Dem_EventQueue[u16Loop].ExtData,0xFFu,DEM_EXTENDED_DATA_MAX_LEN);

#endif /* #if(DEM_EXTENDED_DATA_MAX_LEN > 0) */

#if(DEM_FREEZE_FRAME_MAX_LEN > 0)
			DEM_VALUE_SET(Dem_EventQueue[u16Loop].FFData,0xFFu,DEM_FREEZE_FRAME_MAX_LEN);
#endif /* #if(DEM_FREEZE_FRAME_MAX_LEN > 0) */
		}

		Dem_EventQueueRead = 0u;
		Dem_EventQueueWrite = 0u;

#if(DEM_DEBOUNCE_COUNTER_BASED_EVENT_NUM > 0u)
		/**
		 * @req [SWS_Dem_00438] If Dem-internal debouncing is configured, the Dem module shall reset the
		 *      Dem-internal debounce algorithm when Dem_PreInit has been called.
		 */
		for(u16Loop = 0u; u16Loop < DEM_DEBOUNCE_COUNTER_BASED_EVENT_NUM; u16Loop++)
		{
			/**
			 * @req [SWS_Dem_00180] The function Dem_PreInit (refer to chapter 8.3.2.1) shall initialize
			 *      the internal states of the Dem module necessary to process events and reset debounce
			 *      counters reported by BSW modules by using Dem_ReportErrorStatus (refer to chapter 7.7)
			 *      and Dem_ResetEventDebounceStatus.
			 */
			Dem_InternalDebounceCounter[u16Loop].status = DEM_EVENT_STATUS_PREPASSED;
			Dem_InternalDebounceCounter[u16Loop].counter = (sint16)0;
			Dem_InternalDebounceCounter[u16Loop].isFreeze = (boolean)FALSE;
		}

#endif /* #if(DEM_DEBOUNCE_COUNTER_BASED_EVENT_NUM > 0u) */

#if(DEM_DEBOUNCE_TIME_BASED_EVENT_NUM > 0u)
		for(u16Loop = 0u; u16Loop < DEM_DEBOUNCE_TIME_BASED_EVENT_NUM; u16Loop++)
		{
			DemInternalDebounceTimer[u16Loop].status = DEM_EVENT_STATUS_PREPASSED;
			DemInternalDebounceTimer[u16Loop].timeout = 0u;
			DemInternalDebounceTimer[u16Loop].isFreeze = (boolean)FALSE;
			DemInternalDebounceTimer[u16Loop].IntId = 0xFFFFu;
			DemInternalDebounceTimer[u16Loop].triggered = (boolean)FALSE;
		}
#endif /* #if(DEM_DEBOUNCE_TIME_BASED_EVENT_NUM > 0u)	 */

#if(DEM_DTC_NUM > 0u)
		for(u16Loop = 0u; u16Loop < DEM_DTC_NUM; u16Loop++)
		{
			Dem_DtcUdsStatus[u16Loop]		  = 0x50u;
			Dem_InternalFDC[u16Loop]          = (sint8)0;
			Dem_MaxFDCDurCurCycles[u16Loop]   = 0u;
			Dem_MaxFDCSinceLastClear[u16Loop] = 0u;
		}
		DEM_VALUE_SET(Dem_DtcSuppress,0u,DEM_DTC_NUM_BYTE);
#endif /* #if(DEM_DTC_NUM > 0u) */

#if(DEM_COMPONENT_NUM > 0)
		for(u16Loop = 0u; u16Loop < DEM_COMPONENT_NUM_BYTE; u16Loop++)
		{
			Dem_ComponentStatus[u16Loop] = 0u;
			Dem_ComponentAvailable[u16Loop] = 0xFFu;
		}
#endif /* #if(DEM_COMPONENT_NUM > 0) */

		 Dem_InitState = DEM_STATE_PRE_INIT;
	}
}

/**
 * @sid				0x02
 * @brief			Dem_Init
 * @details			Initializes or reinitializes this module.
 *
 * @Para[in]		pConfigPtr: Pointer to the configuration set in VARIANT-POSTBUILD.
 */
FUNC(void, DEM_CODE) Dem_Init
(
	P2CONST(Dem_ConfigType,AUTOMATIC,DEM_CONST)pConfigPtr
)
{
	uint8 u8Loop;

	if(Dem_InitState != DEM_STATE_PRE_INIT)
	{
		DEM_DET_ERROR_REPORT(DEM_SID_INIT,DEM_E_INIT_FAILED);
	}
	else if(pConfigPtr == NULL_PTR)
	{
		DEM_DET_ERROR_REPORT(DEM_SID_INIT,DEM_E_PARAM_POINTER);
	}
	else
	{
		Dem_ConfigPtr = pConfigPtr;

#if(DEM_NVRAM_BLOCKID_NUM > 0)
		/**
		 * @req [SWS_Dem_00578] If the NVM module was not able to read some nonvolatile data
		 *      of the Dem module, the Dem module shall initialize all non-volatile data with
		 *      their initial values.
		 */
		Dem_ReadFromNvRAM();
#endif /* #if(DEM_NVRAM_BLOCKID_NUM > 0) */

		/**
		 * @req [SWS_Dem_00578] If the NVM module was not able to read some nonvolatile data
		 *      of the Dem module, the Dem module shall initialize all non-volatile data with
		 *      their initial values.
		 */
		Dem_EventMemoryInit();

		Dem_EventInfoInit();

		/* PRQA S 2877 ++ #violate MISAR2004_21.1: If DEM_DEBOUNCE_COUNTER_BASED_EVENT_NUM
		 * is bigger than 1 this loop will be executed more than once. */
		for(u8Loop = 0u; u8Loop < DEM_OPERATION_CYCLE_NUM; u8Loop++)
		{
			if(Dem_ISEnable_OperationCycle(u8Loop) == (boolean)TRUE)
			{
				Dem_StartOperationCycle(u8Loop, (boolean)FALSE);
			}
		}

#if(DEM_INDICATOR_NUM > 0)
		DEM_VALUE_SET(Dem_IndicatorStatus,DEM_INDICATOR_OFF,DEM_INDICATOR_NUM);
#endif /* #if(DEM_INDICATOR_NUM > 0) */

#if(DEM_MAXNUMBER_PRESTORED_FF > 0)
		Dem_PreFFInit();
#endif /* #if(DEM_MAXNUMBER_PRESTORED_FF > 0) */

#if(DEM_DCM_ENABLE == STD_ON)
		Dem_DcmInit();
#endif /* #if(DEM_DCM_ENABLE == STD_ON) */

#if(DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT)
		Dem_OBDInit();
#endif /* #if(DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT) */

		Dem_InitState = DEM_STATE_INIT;
	}
}

/**
 * @sid				0x03
 * @brief			Dem_Shutdown
 * @details			Shuts down this module.
 */
FUNC(void, DEM_CODE) Dem_Shutdown
(
	void
)
{
	uint8 u8Loop;

	if(Dem_InitState != DEM_STATE_INIT)
	{
		DEM_DET_ERROR_REPORT(DEM_SID_SHUTDOWN,DEM_E_UNINIT);
	}
	else
	{
		u8Loop = 0u;

		/**
		 * @req [SWS_Dem_01078] If DemOperationCycleStatusStorage is set to FALSE, a call of
		 *      Dem_Shutdown shall end all operation cycles which are not stored in non-volatile
		 *      memory.
		 */
		do
		{
			Dem_EndOperationCycle(u8Loop);
			Dem_Disable_OperationCycle(u8Loop); /* PRQA S 2984 #violate MISAR2004_21.1: The value of the result is variable */
			u8Loop++; /* PRQA S 2984 #violate MISAR2004_21.1: The value of the result is variable */
		}while(u8Loop < DEM_OPERATION_CYCLE_NUM); /* PRQA S 2996,2993 #violate MISAR2004_13.7:The result 
                                                           * of this logical operation is variable,and this loop
                                                           * will excute more than once */

#if(DEM_NVRAM_BLOCKID_NUM > 0)
		Dem_WriteToNvRAM();
#endif /* #if(DEM_NVRAM_BLOCKID_NUM > 0) */

		Dem_InitState = DEM_STATE_UNINIT;
	}
}

/**
 * @sid				0x0f
 * @brief			Dem_ReportErrorStatus
 * @details			Queues the reported events from the BSW modules (API is only used by BSW modules).
 *                  The interface has an asynchronous behavior,because the processing of the event is
 *                  done within the Dem main function.OBD Events Suppression shall be ignored for this
 *                  computation.
 *
 * @param[in]		EventId:Identification of an event by assigned Event ID.
 * @param[in]		EventStatus:Monitor test result.
 */
FUNC(void, DEM_CODE) Dem_ReportErrorStatus
(
    Dem_EventIdType EventId,
    Dem_EventStatusType EventStatus
)
{
	uint16  u16InternalId;
	const Dem_EventParameterType* pEventParameter;
	uint8 u8OpCycleIndex = 1u;

	if(Dem_InitState == DEM_STATE_UNINIT)
	{
		DEM_DET_ERROR_REPORT(DEM_SID_REPORTERRORSTATUS,DEM_E_UNINIT);
	}
	else if((EventId > DEM_EVENT_PARAMETER_NUM) || (EventId == 0u))
	{
		DEM_DET_ERROR_REPORT(DEM_SID_REPORTERRORSTATUS,DEM_E_WRONG_CONFIGURATION);
	}
	else if(EventStatus > 4u)
	{
		DEM_DET_ERROR_REPORT(DEM_SID_REPORTERRORSTATUS,DEM_E_WRONG_CONFIGURATION);
	}
	else
	{
		u16InternalId = EventId - 1u;

		if (Dem_InitState == DEM_STATE_INIT)
		{
			pEventParameter = &(Dem_ConfigPtr->DemEventParameter[u16InternalId]);

			DEM_DETCHECK_REPORTEVENT_INVALID(pEventParameter->DemEventKind,\
					pEventParameter->DemDebounceAlgorithmClassType,\
					EventStatus,\
					DEM_SID_REPORTERRORSTATUS,\
					&u8OpCycleIndex);

			if(u8OpCycleIndex != 0u)
			{
				/* PRQA S 2995,2991 #violate MISAR2004_13.7:The result of this logical operation is variable */
				if(((boolean)TRUE == Dem_ISEnable_EventAvaliable(u16InternalId))
					&& ((boolean)TRUE == Dem_EventConditionCheck(EventStatus,&u16InternalId)))
				{
					if((boolean)TRUE == Dem_ISEnable_DTCSetting(u16InternalId))
					{
						u8OpCycleIndex = pEventParameter->DemOperationCycleRef;

						if(((boolean)TRUE == Dem_ISEnable_OperationCycle(u8OpCycleIndex))
							|| (Dem_General.DemOperationCycle[u8OpCycleIndex].\
									DemOperationCycleType == DEM_OPCYC_OBD_DCY))
						{
							/**
							 * @req [SWS_Dem_01091] Dem_ReportErrorStatus shall ignore the replacement event.
							 */
							if((boolean)FALSE == Dem_ReplacementEventCheck(pEventParameter))
							{
#if(DEM_DTC_NUM > 0)
								Dem_SetCombineDtcStatus(u16InternalId);
								Dem_InternalDataUpdata(u16InternalId);
#endif /* #if(DEM_DTC_NUM > 0) */
								(void)Dem_EventEnterQueue(u16InternalId,EventStatus);
							}
						}
					}
					else
					{
						Dem_InternalDebounceHandle(u16InternalId);
					}
				}
			}
		}
		else
		{
			/**
			 * @req [SWS_Dem_00851] All events which are reported via
			 *      Dem_ReportErrorStatus before Dem_Init shall not
			 *      consider the state of the operation cycles
			 */
			(void)Dem_EventEnterQueue(u16InternalId,EventStatus);
		}
	}
	return;
}

/* PRQA S 3408 EOF # violate MISAR2004_8.8:It can only be used through the RTE, 
 * and therefore no declaration is exported via Dem.h. */
/**
 * @sid				0x04
 * @brief			Dem_SetEventStatus
 * @details			Processes the events reported by SW-Cs via RTE. This API can only
					be used through the RTE, and therefore no declaration is exported
					via Dem.h.Some bits of the UDS DTC status byte changes synchronously
					or asynchronously (refer to SWS_Dem_00036 and SWS_Dem_00379).OBD
					Events Suppression shall be ignored for this computation.

 * @param[in]		EventId: Identification of an event by assigned EventId.
 * @param[in]       EventStatus: Monitor test result.
 *
 * @return     		Status of the operation of Std_ReturnType
 * @retval			E_OK: set of event status was successful
 * @retval			E_NOT_OK: set of event status failed or could not be accepted
 */
FUNC(Std_ReturnType, DEM_CODE) Dem_SetEventStatus
(
    Dem_EventIdType EventId,
    Dem_EventStatusType EventStatus
)
{
	Std_ReturnType ret         = (Std_ReturnType)E_NOT_OK;
	const Dem_EventParameterType* pEventParameter;
	uint8   u8OpCycleIndex 	   = 1u;
	uint16  u16InternalId      = (uint16)(EventId - (uint16)1); /* PRQA S 2897 #violate MISAR2004_21.1:
                                                                 * EventId is bigger than zero,so the
                                                                 * minimum of expression is 0 */
	if(Dem_InitState != DEM_STATE_INIT)
	{
		DEM_DET_ERROR_REPORT(DEM_SID_SETEVENTSTATUS,DEM_E_UNINIT);
	}
	else if((EventId == 0u)||(EventId > DEM_EVENT_PARAMETER_NUM))
	{
		DEM_DET_ERROR_REPORT(DEM_SID_SETEVENTSTATUS,DEM_E_WRONG_CONFIGURATION);
	}
	else
	{
		pEventParameter = &(Dem_ConfigPtr->DemEventParameter[u16InternalId]);

		DEM_DETCHECK_REPORTEVENT_INVALID(pEventParameter->DemEventKind,\
				pEventParameter->DemDebounceAlgorithmClassType,\
				EventStatus,\
				DEM_SID_SETEVENTSTATUS,\
				&u8OpCycleIndex);

		if(u8OpCycleIndex != 0u)
		{
			/**
			 * @req [SWS_Dem_01108] If an event is set to unavailable, the corresponding
			 *      event shall be treated as if it is not configured in the system.
			 */
			/* PRQA S 2995,2991 #violate MISAR2004_13.7:The result of this logical operation is variable */
			if(((boolean)TRUE == Dem_ISEnable_EventAvaliable(u16InternalId))
				&& ((boolean)TRUE == Dem_EventConditionCheck(EventStatus,&u16InternalId)))
			{
				/**
				 * @req [SWS_Dem_00626] When DTC setting is disabled, all status reports from SW-Cs
				 *      (refer to Dem_SetEventStatus)and BSW modules(refer to Dem_ReportErrorStatus)
				 *      for those events being assigned to this specific DTC group shall be ignored
				 *      (no change of UDS DTC status byte) by the Dem.
				 */
				if((boolean)TRUE == Dem_ISEnable_DTCSetting(u16InternalId))
				{
					u8OpCycleIndex = pEventParameter->DemOperationCycleRef;

					/**
					 * @req [SWS_Dem_00481] If an operation cycle has started, all status
					 *      reports from SW-Cs and BSW modules for those events, being
					 *      assigned to this cycle, shall be accepted by the Dem from this
					 *      point in time on
					 */
					if(((boolean)TRUE == Dem_ISEnable_OperationCycle(u8OpCycleIndex))
#if(DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT)
						|| (Dem_General.DemOperationCycle[u8OpCycleIndex].\
							DemOperationCycleType == DEM_OPCYC_OBD_DCY)
#endif /* #if(DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT) */
					)
					{
						/**
						 * @req [SWS_Dem_00700] If the OBD driving cycle has ended, status
						 *      reports shall be processed, except update of the confirmed
						 *      status.
						 */
#if(DEM_DTC_NUM > 0)
						Dem_SetCombineDtcStatus(u16InternalId);
						Dem_InternalDataUpdata(u16InternalId);
#endif /* #if(DEM_DTC_NUM > 0) */
						ret = Dem_EventEnterQueue(u16InternalId,EventStatus);
					}
				}
				else
				{
					/**
					 * @req [SWS_Dem_00626] When DTC setting is disabled, all status reports from
					 *      SW-Cs and BSW modules for those events being assigned to this specific
					 *      DTC group shall be ignored(no change of UDS DTC status byte)by the Dem.
					 *      This is similar like the enable condition handling. In case of Dem
					 *      internal debouncing the related fault detection counter will be frozen
					 *      or reset.
					 */
					Dem_InternalDebounceHandle(u16InternalId);
				}
			}
		}
	}
	return ret;
}

/**
 * @sid				0x37
 * @brief			Dem_SetEventAvailable
 * @details			Set the available status of a specific Event.
 *
 * @param[in]		EventId:Identification of an event by assigned EventId
 * @param[in] 	 	AvailableStatus:This parameter specifies whether the respective
 *	 	 	 	 	Event shall be available (TRUE) or not (FALSE).
 *
 * @return          Result of changing event available status.
 * @retval          E_OK:change of available status accepted.
 * @retval          E_NOT_OK:change of available status not accepted.
 */
FUNC(Std_ReturnType, DEM_CODE) Dem_SetEventAvailable
(
    Dem_EventIdType EventId,
    boolean AvailableStatus
)
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;
#if (DEM_AVAILABILITY_SUPPORT == DEM_EVENT_AVAILABILITY)
#if(DEM_DTC_NUM > 0)
	Dem_DTCOriginType dtcOrigin;
#endif /* #if(DEM_DTC_NUM > 0) */

#if(DEM_TRIGGER_FIM_REPORTS == STD_ON)
    Dem_UdsStatusByteType oldStatus;
#endif /* #if(DEM_TRIGGER_FIM_REPORTS == STD_ON) */

    DEM_DETCHECK_API_SETEVENTABAILABLE(Dem_InitState,EventId,&ret);

    if(ret != 0u)
    {
    	EventId--;
#if(DEM_TRIGGER_FIM_REPORTS == STD_ON)
			oldStatus = Dem_EventUDSBitStatus[EventId];
#endif /* #if(DEM_TRIGGER_FIM_REPORTS == STD_ON) */

		/**
		 * @req [SWS_Dem_01109]	The API Dem_SetEventAvailable shall reject the request and return
		 *      E_NOT_OK, if an event memory entry exists already or test failed is set to 1.
		 */
#if(DEM_DTC_NUM > 0)
		if(Dem_ConfigPtr->DemEventParameter[EventId].DemDTCRef != 0xFFFFu)
		{
			dtcOrigin = Dem_ConfigPtr->DemDTCAttributes[Dem_ConfigPtr->DemDTC[Dem_ConfigPtr->\
				DemEventParameter[EventId].DemDTCRef].DemDTCAttributesRef].DemMemoryDestinationRef;

			if(NULL_PTR == Dem_GetEntryFromMemory(dtcOrigin,(EventId+1u)))
			{
				ret = (Std_ReturnType)E_OK;
			}
		}
#endif /* #if(DEM_DTC_NUM > 0) */

		if(ret == (Std_ReturnType)E_OK)
		{
			/* @req [SWS_Dem_01109] */
			if((boolean)FALSE == Dem_ISEnable_UdsStatusBits(EventId,DEM_UDS_STATUS_TF))
			{
				if(AvailableStatus == (boolean)TRUE)
				{
					if(Dem_ISEnable_EventAvaliable(EventId) == (boolean)FALSE)
					{
						/**
						 * @req [SWS_Dem_01111] In case an event changes its state to available
						 *      (availability==true)(via call of Dem_SetEventAvailable) the event
						 *      status shall be set to 0x50
						 */
						Dem_Enable_EventAvaliable(EventId);

						Dem_EventUDSBitStatus[EventId] = 0x50u;

#if(DEM_TRIGGER_FIM_REPORTS == STD_ON)
						FiM_DemTriggerOnEventStatus(\
								(EventId + 1u),\
								oldStatus,\
								Dem_EventUDSBitStatus[EventId]);
#endif /* #if(DEM_TRIGGER_FIM_REPORTS == STD_ON) */
					}
				}
				else
				{
					if(Dem_ISEnable_EventAvaliable(EventId) == (boolean)TRUE)
					{
						Dem_Disable_EventAvaliable(EventId);

						Dem_EventUDSBitStatus[EventId] = 0x00u;

#if(DEM_TRIGGER_FIM_REPORTS == STD_ON)
						if(oldStatus != Dem_EventUDSBitStatus[EventId])
						{
							/**
							 * @req [SWS_Dem_01110] In case an event changes its state to unavailable
							 *      (availability==false)(via call of Dem_SetEventAvailable) the event
							 *      status shall be set to 0x00.
							 */
							FiM_DemTriggerOnEventStatus(\
									(EventId + 1u),\
									oldStatus,\
									Dem_EventUDSBitStatus[EventId]);
						}
#endif /* #if(DEM_TRIGGER_FIM_REPORTS == STD_ON) */
					}
				}
				/**
				 * @req [SWS_Dem_00915] The Dem shall suppress a DTC if all related events of
				 *      this DTC are not available
				 */
				Dem_DTCSuppressUpdata(EventId);
			}
			else
			{
		    	ret = (Std_ReturnType)E_NOT_OK;
		    }
		}
    }
    else
    {
    	ret = (Std_ReturnType)E_NOT_OK;
    }
#endif /* #if (DEM_AVAILABILITY_SUPPORT == DEM_EVENT_AVAILABILITY) */
    return ret;
}

/**
 * @sid				0x09
 * @brief			Dem_ResetEventDebounceStatus
 * @details			Control the internal debounce counter/timer by BSW modules and SWCs.The event
 *                  qualification will not be affected by these debounce state changes.This API is
 *                  available for BSW modules as soon as Dem_PreInit has been completed.
 *
 * @param[in]		EventId: Identification of an event by assigned EventId.
 * @param[in]		DebounceResetStatus: Freeze or reset the internal debounce counter/timer of the
 *                  specified event.
 *
 * @return     		Result of this operation.
 * @retval			E_OK: Debounce status reset successful.
 * @retval			E_NOT_OK: Debounce status reset unsuccessful.
 */
FUNC(Std_ReturnType, DEM_CODE) Dem_ResetEventDebounceStatus
(
    Dem_EventIdType EventId,
    Dem_DebounceResetStatusType DebounceResetStatus
)
{
    Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;

    DEM_DETCHECK_API_RESETEVENTDEBOUNCESTATUS(Dem_InitState,EventId,&ret,FALSE);

    if(ret != (Std_ReturnType)E_OK)
    {
    	EventId--;
    	if((Dem_ISEnable_EventAvaliable(EventId) == (boolean)TRUE)
#if(DEM_ENABLE_CONDITION_NUM > 0)
    			&&(Dem_ISEnable_EnableCondition(EventId) == (boolean)TRUE)
#endif /* #if(DEM_ENABLE_CONDITION_NUM > 0) */
    	)
    	{
    		if(DebounceResetStatus == DEM_DEBOUNCE_STATUS_RESET)
    		{
    			Dem_DebounceReset(EventId,(boolean)FALSE);
    			ret = (Std_ReturnType)E_OK;
    		}
    		else if(DebounceResetStatus == DEM_DEBOUNCE_STATUS_FREEZE)
    		{
    			Dem_DebounceFreeze(EventId);
    			ret = (Std_ReturnType)E_OK;
    		}
    		else
    		{
    			DEM_DETCHECK_API_RESETEVENTDEBOUNCESTATUS(FALSE,FALSE,&ret,TRUE);
    		}
    	}
    }
    else
    {
    	ret = (Std_ReturnType)E_NOT_OK;
    }
    return ret;
}

/* PRQA S 3408 EOF # violate MISAR2004_8.8:It can only be used through the RTE, 
 * and therefore no declaration is exported via Dem.h. */
/**
 * @sid				0x05
 * @brief			Dem_ResetEventStatus
 * @details			Resets the event failed status.
 *
 * @param[in]		EventId: Identification of an event by assigned EventId.
 *
 * @return     		Result of this operation.
 * @retval			E_OK: reset of event status was successful.
 * @retval			E_NOT_OK: reset of event status failed or is not allowed,
 	 	 	 	 	because the event is already tested in this operation cycle.
 */
FUNC(Std_ReturnType, DEM_CODE) Dem_ResetEventStatus
(
    Dem_EventIdType EventId
)
{
	 Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;

	 /**
	  * @req [SWS_Dem_01112] If development error detection is enabled and any instance calls
	  *		 any Dem API, excluding Dem_ReportErrorStatus, Dem_ResetEventStatus,
	  *		 Dem_SetEventAvailable and Dem_GetVersionInfo, before the Dem was fully initialized,
	  *		 the Dem module shall set the error code DEM_E_UNINIT.
	  */
	 DEM_DETCHECK_API_RESETEVENTSTATUS(EventId,&ret);

	 if(ret != (Std_ReturnType)E_OK)
	 {
    	EventId--;
    	/**
    	 * @req [SWS_Dem_00638] The function Dem_ResetEventStatus shall return E_NOT_OK,
    	 *      if the event was already tested this operation cycle.
    	 * @req [SWS_Dem_01108] If an event is set to unavailable, the corresponding event
    	 *      shall be treated as if it is not configured in the system.
    	 */
    	if((Dem_ISEnable_UdsStatusBits(EventId,DEM_UDS_STATUS_TNCTOC) == (boolean)TRUE)\
    			&&(Dem_ISEnable_EventAvaliable(EventId) == (boolean)TRUE))
    	{
    		/**
    		 * @req [SWS_Dem_00187] The function Dem_ResetEventStatus shall set the UDS DTC status bit
    		 *      0 (TestFailed) to 0 and reset the Dem-internal debounce algorithm to initial values
    		 *      if configured.
    		 */
    		Dem_Disable_UdsStatusBits(EventId,DEM_UDS_STATUS_TF);
    		Dem_Enable_TFBitReset(EventId);
    		Dem_DebounceReset(EventId,(boolean)FALSE);

#if(DEM_DTC_NUM > 0)
    		Dem_SetCombineDtcStatus(EventId);
#endif /* #if(DEM_DTC_NUM > 0) */
    		ret = (Std_ReturnType)E_OK;
    	}
	 }
	 else
	 {
		 ret = (Std_ReturnType)E_NOT_OK;
	 }
    return ret;
}

#if(DEM_MAXNUMBER_PRESTORED_FF > 0)
/**
 * @sid				0x06
 * @brief			Dem_PrestoreFreezeFrame
 * @details			Captures the freeze frame data for a specific event.
 *
 * @param[in]		EventId: Identification of an event by assigned EventId.
 *
 * @return     		Result of this operation.
 * @retval			E_OK:Freeze frame pre-storage was successful.
 * @retval			E_NOT_OK:Freeze frame pre-storage failed.
 */
FUNC(Std_ReturnType, DEM_CODE) Dem_PrestoreFreezeFrame
(
    Dem_EventIdType EventId
)
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;

	DEM_DETCHECK_API_PRESTOREFREEZEFRAME(Dem_InitState,EventId,&ret,FALSE);

	if(ret == (Std_ReturnType)E_NOT_OK)
    {
    	if(Dem_ConfigPtr->DemEventParameter[(EventId-1u)].DemFFPrestorageSupported == (boolean)FALSE)
    	{
    		DEM_DETCHECK_API_PRESTOREFREEZEFRAME(FALSE,FALSE,&ret,TRUE);
    	}
    	else
    	{
    		/**
    		 * @req [SWS_Dem_01108] If an event is set to unavailable, the corresponding
    		 *      event shall be treated as if it is not configured in the system
    		 */
    		if(Dem_ISEnable_EventAvaliable(EventId-1u) == (boolean)TRUE)
			{
    			ret = Dem_PreStoreFFDeal(EventId);
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
 * @sid				0x07
 * @brief			Dem_ClearPrestoredFreezeFrame
 * @details			Clears a pre-stored freeze frame of a specific event.
 *
 * @param[in]		EventId: Identification of an event by assigned EventId.
 *
 * @return     		Result of this operation.
 * @retval			E_OK: Clear pre-stored freeze frame was successful.
 * @retval			E_NOT_OK: Clear pre-stored freeze frame failed.
 */
FUNC(Std_ReturnType, DEM_CODE) Dem_ClearPrestoredFreezeFrame
(
    Dem_EventIdType EventId
)
{
	/**
	 * @req [SWS_Dem_00050] The Dem module shall provide the API Dem_ClearPrestoredFreezeFrame
	 *      to release the pre-stored freeze frame for the specific event.
	 */
	uint16 u16Loop = 0u;
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;

	DEM_DETCHECK_API_CLEARPRESTOREDFREEZEFRAME(Dem_InitState,EventId,&ret);

	if(ret != (Std_ReturnType)E_OK)
    {
    	if (Dem_ConfigPtr->DemEventParameter[(EventId-1u)].DemFFPrestorageSupported == (boolean)FALSE)
    	{
    		DEM_DET_ERROR_REPORT(DEM_SID_CLEARPRESTOREDFREEZEFRAME,DEM_E_WRONG_CONFIGURATION);
    	}
    	else
    	{
			/**
			 * @req [SWS_Dem_01108] If an event is set to unavailable, the corresponding
			 *      event shall be treated as if it is not configured in the system
			 */
			if(Dem_ISEnable_EventAvaliable(EventId-1u) == (boolean)TRUE)
			{
				do
				{
					if(Dem_PreFFInfos[u16Loop].eventId == EventId)
					{
						Dem_PreFFInfos[u16Loop].eventId = 0x00u;
						DEM_VALUE_SET(Dem_PreFFInfos[u16Loop].FFData, 0xFFu, DEM_FREEZE_FRAME_MAX_LEN);
						ret = (Std_ReturnType)E_OK;
						break;
					}
					u16Loop++;
				}while(u16Loop < DEM_MAXNUMBER_PRESTORED_FF);
			}
    	}
    }
	else
	{
		ret = (Std_ReturnType)E_NOT_OK;
	}
    return ret;
}
#endif /* #if(DEM_MAXNUMBER_PRESTORED_FF > 0) */

/* PRQA S 3408 EOF # violate MISAR2004_8.8:It can only be used through the RTE, 
 * and therefore no declaration is exported via Dem.h. */
/**
 * @sid				0x08
 * @brief			Dem_SetOperationCycleState
 * @details			Sets an operation cycle state. This API can only be used through the RTE and
 *                  therefore no declaration is exported via Dem.h.
 *
 * @param[in]		OperationCycleId: Identification of operation cycle,like power cycle,driving cycle.
 * @param[in]		CycleState:New operation cycle state:(re-)start or end.
 *
 * @return     		Result of this operation.
 * @retval			E_OK: set of operation cycle was accepted and will be handled asynchronously.
 * @retval			E_NOT_OK: set of operation cycle was rejected.
 */
FUNC(Std_ReturnType, DEM_CODE) Dem_SetOperationCycleState
(
    uint8 OperationCycleId,
    Dem_OperationCycleStateType CycleState
)
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;

	DEM_DETCHECK_API_SETOPERATIONCYCLESTATE(Dem_InitState,OperationCycleId,CycleState,&ret);

	if(ret == (Std_ReturnType)E_NOT_OK)
    {
    	ret = (Std_ReturnType)E_OK;

    	if (CycleState == DEM_CYCLE_STATE_START)
    	{
    		if(Dem_ISEnable_OperationCycle(OperationCycleId) == (boolean)TRUE)/* PRQA S 2984 #violate MISAR2004_21.1: The value of the result is variable */
    		{
    			/**
    			 * @req [SWS_Dem_00483] If the API Dem_SetOperationCycleState is called with
    			 *      DEM_CYCLE_STATE_START and the respective operation cycle was already
    			 *      started,the operation cycle shall be restarted (started again)
    			 */
    			Dem_StartOperationCycle(OperationCycleId,(boolean)TRUE);
    		}
    		else
    		{
    			Dem_Enable_OperationCycle(OperationCycleId);/* PRQA S 2984 #violate MISAR2004_21.1: The value of the result is variable */
    			Dem_StartOperationCycle(OperationCycleId,(boolean)FALSE);
    		}
    	}
    	else
    	{
    		if(Dem_ISEnable_OperationCycle(OperationCycleId) == (boolean)TRUE)/* PRQA S 2984 #violate MISAR2004_21.1: The value of the result is variable */
			{
				Dem_EndOperationCycle(OperationCycleId);
				Dem_Disable_OperationCycle(OperationCycleId);/* PRQA S 2984 #violate MISAR2004_21.1: The value of the result is variable */
			}
    	}
    }
	else
	{
		ret = (Std_ReturnType)E_NOT_OK;
	}
    return ret;
}

/* PRQA S 3408 EOF # violate MISAR2004_8.8:It can only be used through the RTE, 
 * and therefore no declaration is exported via Dem.h. */
/**
 * @sid				0x9e
 * @brief			Dem_GetOperationCycleState
 * @details			Gets information about the status of a specific operation cycle.This API can only
 *                  be used through the RTE and therefore no declaration is exported via Dem.h.
 *
 * @param[in]		OperationCycleId: Identification of operation cycle,like power cycle,driving cycle.
 *
 * @param[out]      pCycleState: Cycle status information.
 *
 * @return     		Result of getting operation.
 * @retval			E_OK: read out of operation cycle was successful.
 * @retval			E_NOT_OK: read out of operation cycle failed.
 */
FUNC(Std_ReturnType, DEM_CODE) Dem_GetOperationCycleState
(
    uint8 OperationCycleId,
    P2VAR(Dem_OperationCycleStateType, AUTOMATIC, DEM_APPL_DATA) pCycleState
)
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;

	DEM_DETCHECK_API_GETOPERATIONCYCLESTATE(Dem_InitState,OperationCycleId,pCycleState,&ret);

	if(ret == (Std_ReturnType)E_NOT_OK)
    {
    	ret = (Std_ReturnType)E_OK;
		if(Dem_ISEnable_OperationCycle(OperationCycleId) == (boolean)FALSE)/* PRQA S 2984 #violate MISAR2004_21.1: The value of the result is variable */
		{
			*pCycleState = DEM_CYCLE_STATE_END;
		}
		else
		{
			*pCycleState = DEM_CYCLE_STATE_START;
		}
    }
	else
	{
		ret = (Std_ReturnType)E_NOT_OK;
	}
    return ret;
}

/* PRQA S 3408 EOF # violate MISAR2004_8.8:It can only be used through the RTE, 
 * and therefore no declaration is exported via Dem.h. */
/**
 * @sid				0x11
 * @brief			Dem_SetAgingCycleState
 * @details			Triggers the next aging cycle state.This API can only be used through the RTE,and
 *                  therefore no declaration is exported via Dem.h.
 *
 * @param[in]		OperationCycleId: Identification of aging cycle.
 *
 * @return     		Result of setting operation.
 * @retval			E_OK: set of aging cycle was successful.
 * @retval			E_NOT_OK: set of aging cycle failed.
 */
FUNC(Std_ReturnType, DEM_CODE) Dem_SetAgingCycleState
(
    uint8 OperationCycleId
)
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;

	DEM_DETCHECK_API_SETAGINGCYCLESTATE(Dem_InitState,OperationCycleId,&ret);

	if(ret == (Std_ReturnType)E_NOT_OK)
	{
		Dem_AgingCycle = OperationCycleId;
		ret = (Std_ReturnType)E_OK;
	}
	else
	{
		ret = (Std_ReturnType)E_NOT_OK;
	}
	return ret;
}

/* PRQA S 3408 EOF # violate MISAR2004_8.8:It can only be used through the RTE, 
 * and therefore no declaration is exported via Dem.h. */
/**
 * @sid				0x7a
 * @brief			Dem_SetWIRStatus
 * @details			Sets the WIR status bit via fail-safe SW-Cs.
 *
 * @param[in]		EventId: Identification of an event by assigned EventId.
 * @param[in]		WIRStatus: Requested status of event related WIR-bit.
 *
 * @return     		Result of setting operation.
 * @retval			E_OK: The request is accepted.
 * @retval			E_NOT_OK: not be accepted(e.g. disabled controlDTCSetting) and should be repeated.
 */
FUNC(Std_ReturnType, DEM_CODE) Dem_SetWIRStatus
(
    Dem_EventIdType EventId,
    boolean WIRStatus
)
{
	/**
	 * @req [SWS_Dem_00831] Dem shall provide a function to control (set/reset) the
	 *      WarningIndicatorRequested-bit of a configured event (in Dem) regarding
	 *      to e.g. failsafe state.
	 *
	 * @req [SWS_Dem_00832] Setting of the WIR-bit of an event can be controlled via
	 *      Dem_SetWIRStatus OR by the Dem internal WIR-bit handling. (OR-Operation).
	 */
    Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;

    DEM_DETCHECK_API_SETWIRSTATUS(Dem_InitState,EventId,&ret);

    if(ret == (Std_ReturnType)E_NOT_OK)
    {
    	EventId--;

    	/**
    	 * @req [SWS_Dem_01108] If an event is set to unavailable, the corresponding event shall
    	 *      be treated as if it is not configured in the system.
    	 */
    	if(Dem_ISEnable_EventAvaliable(EventId) == (boolean)TRUE)
		{
    		/**
    		 * @req [SWS_Dem_00836] During disabled ControlDTCSettings the WIR-bit of an event shall
    		 *      not be changed via Dem_SetWIRStatus and the function shall return E_NOT_OK.
    		 */
    		if(Dem_ISEnable_DTCSetting(EventId) == (boolean)TRUE)
    		{
    			/**
    			 * @req [SWS_Dem_00832] Setting of the WIR-bit of an event can be controlled via
    			 * 		Dem_SetWIRStatus OR by the Dem internal WIR-bit handling. (OR-Operation).
    			 */
    			if((boolean)FALSE == Dem_ISEnable_UdsStatusBits(EventId,DEM_UDS_STATUS_WIR))
    			{
					if(WIRStatus == (boolean)TRUE)
					{
						/**
						 * @req [SWS_Dem_00833] The WIR-bit of the corresponding event shall be set to
						 *      "1" if Dem_SetWIRStatus is called with parameter WIRStatus = TRUE
						 */
						Dem_Enable_UdsStatusBits(EventId,DEM_UDS_STATUS_WIR);
					}
					else
					{
						/**
						 * @req [SWS_Dem_00834] The WIR-bit of the corresponding event shall be set to
						 *      "0" if Dem_SetWIRStatus is called with WIRStatus = FALSE and no referenced
						 *      Dem Indicator(s) are set.
						 */
						Dem_Disable_UdsStatusBits(EventId,DEM_UDS_STATUS_WIR);
					}
#if(DEM_DTC_NUM > 0)
					Dem_SetCombineDtcStatus(EventId);
#endif /* #if(DEM_DTC_NUM > 0) */
    			}
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
 * @sid				0x2a
 * @brief			Dem_GetComponentFailed
 * @details			Gets the failed status of a DemComponent.
 *
 * @param[in]		ComponentId: Identification of a DemComponent.
 *
 * @param[out]		pComponentFailed: TRUE: failed ,FALSE: not failed.
 *
 * @return     		Result of getting operation.
 * @retval			E_OK: Getting "ComponentFailed" was successful.
 * @retval			E_NOT_OK: Getting "ComponentFailed" was not successful.
 */
FUNC(Std_ReturnType, DEM_CODE) Dem_GetComponentFailed
(
    Dem_ComponentIdType ComponentId,
    P2VAR(boolean, AUTOMATIC, DEM_CODE) pComponentFailed
)
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;

	DEM_DETCHECK_API_GETCOMPONENTFAILED(Dem_InitState,ComponentId,pComponentFailed,&ret);

	if(ret == (Std_ReturnType)E_NOT_OK)
	{
#if(DEM_COMPONENT_NUM > 0)
		/**
		 * @req [SWS_Dem_01134] The Dem shall support the availability of DemComponents.
		 * 		Components which are not available shall be treated as if they are not
		 * 		included in the system(e.g. Dem_GetComponentFailed will return E_NOT_OK).
		 */
		if((boolean)TRUE == Dem_IsEnable_ComponentAvailable(ComponentId - 1u))
		{
			/**
			 * @req [SWS_Dem_01131] The Dem shall provide the interface Dem_GetComponentFailed,
			 * 		which allows querying a DemComponents FAILED status.
			 */
			if((boolean)TRUE == Dem_IsEnable_ComponentStatus(ComponentId - 1u))
			{
				*pComponentFailed = (boolean)TRUE;
			}
			else
			{
				*pComponentFailed = (boolean)FALSE;
			}
			ret = (Std_ReturnType)E_OK;
		}
#endif /* #if(DEM_COMPONENT_NUM > 0) */
	}

	return ret;
}

/**
 * @sid				0x0a
 * @brief			Dem_GetEventStatus
 * @details			Gets the current extended event status of an event.
 *
 * @param[in]		EventId: Identification of an event by assigned EventId.
 *
 * @param[out]		pEventStatusByte: UDS DTC status byte of the requested event
 *
 * @return     		Result of getting operation.
 * @retval			E_OK: Get of event status was successful.
 * @retval			E_NOT_OK: Get of event status failed.
 */
FUNC(Std_ReturnType, DEM_CODE) Dem_GetEventStatus
(
    Dem_EventIdType EventId,
    P2VAR(Dem_UdsStatusByteType, AUTOMATIC, DEM_CODE) pEventStatusByte
)
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;

	DEM_DETCHECK_API_GETEVENTSTATUS(Dem_InitState,EventId,pEventStatusByte,&ret);

	if(ret == (Std_ReturnType)E_NOT_OK)
    {
    	EventId--;
    	/**
    	 * @req [SWS_Dem_01108] If an event is set to unavailable, the corresponding
    	 *      event shall be treated as if it is not configured in the system
    	 */
    	if(Dem_ISEnable_EventAvaliable(EventId) == (boolean)TRUE)
    	{
    		*pEventStatusByte = Dem_EventUDSBitStatus[EventId];
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
 * @sid				0x0b
 * @brief			Dem_GetEventFailed
 * @details			Gets the event failed status of an event.
 *
 * @param[in]		EventId: Identification of an event by assigned EventId.
 *
 * @param[out]		pEventFailed: TRUE:Last Failed; FALSE:not Last Failed.
 *
 * @return     		Result of getting operation.
 * @retval			E_OK: Get of "EventFailed" was successful.
 * @retval			E_NOT_OK: Get of "EventFailed" was not successful.
 */
FUNC(Std_ReturnType, DEM_CODE) Dem_GetEventFailed
(
    Dem_EventIdType EventId,
    P2VAR(boolean,AUTOMATIC,DEM_CODE) pEventFailed
)
{
    Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;

    DEM_DETCHECK_API_GETEVENTFAILED(Dem_InitState,EventId,pEventFailed,&ret);

    if(ret == (Std_ReturnType)E_NOT_OK)
    {
    	EventId--;

		/**
		 * @req [SWS_Dem_01108] If an event is set to unavailable, the corresponding event shall
		 *      be treated as if it is not configured in the system.
		 */
		if(Dem_ISEnable_EventAvaliable(EventId) == (boolean)TRUE)
		{
			/**
			 * @req [SWS_Dem_00052] The function Dem_GetEventFailed shall report the UDS DTC status
			 *      bit 0 (TestFailed) of the requested diagnostic event.
			 */
			if(Dem_ISEnable_UdsStatusBits(EventId,DEM_UDS_STATUS_TF) == (boolean)FALSE)
			{
				*pEventFailed = (boolean)FALSE;
			}
			else
			{
				*pEventFailed = (boolean)TRUE;
			}
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
 * @sid				0x0c
 * @brief			Dem_GetEventTested
 * @details			Gets the event failed status of an event.
 *
 * @param[in]		EventId: Identification of an event by assigned EventId.
 *
 * @param[out]		pEventTested: TRUE:event tested this cycle; FALSE:event not tested this cycle.
 *
 * @return     		Result of getting operation.
 * @retval			E_OK: Get of event state "tested" successful.
 * @retval			E_NOT_OK: Get of event state "tested" failed.
 */
FUNC(Std_ReturnType, DEM_CODE) Dem_GetEventTested
(
    Dem_EventIdType EventId,
    P2VAR(boolean, AUTOMATIC, DEM_CODE) pEventTested
)
{
    Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;

    DEM_DETCHECK_API_GETEVENTTESTED(Dem_InitState,EventId,pEventTested,&ret);

    if(ret == (Std_ReturnType)E_NOT_OK)
    {
    	EventId--;

		/**
		 * @req [SWS_Dem_01108] If an event is set to unavailable, the corresponding event shall
		 *      be treated as if it is not configured in the system.
		 */
		if(Dem_ISEnable_EventAvaliable(EventId) == (boolean)TRUE)
		{
			/**
			 * @req [SWS_Dem_00053] The function Dem_GetEventTested shall read the negated UDS DTC
			 *      status bit 6 (TestNotCompletedThisOperationCycle) of the requested diagnostic
			 *      event.
			 */
			if(Dem_ISEnable_UdsStatusBits(EventId,DEM_UDS_STATUS_TNCTOC) == (boolean)FALSE)
			{
				*pEventTested = (boolean)TRUE;
			}
			else
			{
				*pEventTested = (boolean)FALSE;
			}
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
 * @sid				0x9f
 * @brief			Dem_GetDebouncingOfEvent
 * @details			Gets the debouncing status of an event.
 *
 * @param[in]		EventId: Identification of an event by assigned EventId.
 *
 * @param[out]		pDebouncingState:
 * 						Bit 0 Temporarily Defective(corresponds to 0 < FDC < 127).
 * 						Bit 1 finally Defective (corresponds to FDC = 127).
 * 						Bit 2 temporarily healed (corresponds to -128 < FDC < 0).
 * 						Bit 3 Test complete (corresponds to FDC = -128 or FDC = 127).
 * 						Bit 4 DTR Update (= Test complete && Debouncing complete && enable
 * 						conditions / storage conditions fulfilled).
 *
 * @return     		Result of getting operation.
 * @retval			E_OK: Get of debouncing status per event state successful.
 * @retval			E_NOT_OK: Get of debouncing per event state failed.
 */
FUNC(Std_ReturnType, DEM_CODE) Dem_GetDebouncingOfEvent
(
    Dem_EventIdType EventId,
    P2VAR(Dem_DebouncingStateType, AUTOMATIC, DEM_CODE) pDebouncingState
)
{
	sint8 s8FDC = (sint8)0;
    Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;

    DEM_DETCHECK_API_GETDEBOUNCINGOFEVENT(Dem_InitState,EventId,pDebouncingState,&ret);

    if(ret == (Std_ReturnType)E_NOT_OK)
    {
    	/**
		 * @req [SWS_Dem_01108] If an event is set to unavailable, the corresponding event shall
		 *      be treated as if it is not configured in the system.
		 */
    	if(Dem_ISEnable_EventAvaliable(EventId-1u) == (boolean)TRUE)
    	{
    		ret = Dem_InternalFDCCal(EventId-1u);

    		if(ret == (Std_ReturnType)E_OK)
    		{
    			s8FDC = Dem_EventInternalData[EventId-1u].currentFDC;

    			/**
    			 * @req [SWS_Dem_00844] The Dem shall provide a function Dem_GetDebouncingOfEvent()
    			 *      that reports the debounce status of an event.The outparameter 'DebouncingState'
    			 *      returns the debouncing incl. intermediate states.
    			 */
    			if ((s8FDC < 127) && (s8FDC > 0))
				{
    				/* Bit 0: Temporarily Defective (corresponds to 0 < FDC < 127) */
					*pDebouncingState |= DEM_TEMPORARILY_DEFECTIVE;
				}
    			else if (s8FDC == 127)
				{
					/* Bit 1: finally Defective (corresponds to FDC = 127) */
					*pDebouncingState |= DEM_FINALLY_DEFECTIVE;

					/* Bit 3: Test complete (corresponds to FDC = -128 or FDC = 127) */
					*pDebouncingState |= DEM_TEST_COMPLETE;
				}
    			else if ((s8FDC < 0) && (s8FDC > -128))
				{
					/* Bit 2: temporarily healed (corresponds to -128 < FDC < 0) */
					*pDebouncingState |= DEM_TEMPORARILY_HEALED;
				}
				else
				{
					/* Bit 3: Test complete (corresponds to FDC = -128 or FDC = 127) */
					*pDebouncingState |= DEM_TEST_COMPLETE;
				}

    			/**
    			 * @req [SWS_Dem_00844] One particular OBD specific bit shall support the DTR update
    			 *      trigger if test is complete and debouncing is at its limit while the enable
    			 *      and storage conditions are met
    			 */
				if ((Dem_ISEnable_UdsStatusBits(EventId-1u,DEM_UDS_STATUS_TNCTOC) == (boolean)FALSE)
					&& ((s8FDC == 127) || (s8FDC == -128))
#if((DEM_ENABLE_CONDITION_NUM > 0) || (DEM_STORAGE_CONDITION_NUM > 0))
					&& (
#if(DEM_ENABLE_CONDITION_NUM > 0)
						(Dem_ISEnable_EnableCondition(EventId-1u) == (boolean)TRUE)
#endif /* #if(DEM_ENABLE_CONDITION_NUM > 0) */
#if(DEM_STORAGE_CONDITION_NUM > 0)
					|| (Dem_ISEnable_StorageCondition(EventId-1u) == (boolean)TRUE)
#endif /* #if(DEM_STORAGE_CONDITION_NUM > 0) */
						)
#endif /* #if((DEM_ENABLE_CONDITION_NUM > 0) || (DEM_STORAGE_CONDITION_NUM > 0)) */
					)
				{
					/* Bit 4: DTR Update (= Test complete && Debouncing complete
					 * && enable conditions / storage conditions fulfilled) */
					*pDebouncingState |= DEM_DTR_UPDATE;
				}
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
 * @sid				0x0d
 * @brief			Dem_GetDTCOfEvent
 * @details			Gets the DTC of an event.
 *
 * @param[in]		EventId: Identification of an event by assigned EventId.
 * @param[in]       DTCFormat: Defines the output-format of the requested DTC value.
 *
 * @param[out]		pDTCOfEvent: Receives the DTC value in respective format returned by this function.
 *
 * @return     		Result of getting operation.
 * @retval			E_OK: get of DTC was successful.
 * @retval			E_NOT_OK: the call was not successful.
 * @retval			DEM_E_NO_DTC_AVAILABLE: there is no DTC configured in the requested format.
 */
FUNC(Std_ReturnType, DEM_CODE) Dem_GetDTCOfEvent
(
    Dem_EventIdType EventId,
    Dem_DTCFormatType DTCFormat,
    P2VAR(uint32, AUTOMATIC, DEM_CODE) pDTCOfEvent
)
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;

#if(DEM_DTC_NUM > 0)
	uint16 u16DtcRef;
	Dem_EventIdType u16InternalId = (uint16)(EventId - (uint16)1); /* PRQA S 2897 #violate MISAR2004_21.1:
                                                                    * EventId is bigger than zero,so the
                                                                    * minimum of expression is 0 */

	DEM_DETCHECK_API_GETDTCOFEVENT(Dem_InitState,EventId,pDTCOfEvent,&ret);

	if(ret == (Std_ReturnType)E_NOT_OK)
    {
    	/**
		 * @req [SWS_Dem_01108] If an event is set to unavailable, the corresponding event shall
		 *      be treated as if it is not configured in the system.
		 */
    	if(Dem_ISEnable_EventAvaliable(u16InternalId) == (boolean)TRUE)
    	{
			u16DtcRef = Dem_ConfigPtr->DemEventParameter[u16InternalId].DemDTCRef;
			if(u16DtcRef != 0xFFFFu)
			{
				if(DTCFormat == DEM_DTC_FORMAT_UDS)
				{
					*pDTCOfEvent = Dem_ConfigPtr->DemDTC[u16DtcRef].DemDtcValue;
					ret = (Std_ReturnType)E_OK;
				}
#if(DEM_OBD_DTC_NUM > 0)
				else
				{
					u16DtcRef = Dem_ConfigPtr->DemDTC[u16DtcRef].DemObdDTCRef;

					if(u16DtcRef != 0xFFFFu)
					{
						if(DTCFormat == DEM_DTC_FORMAT_OBD)
						{
							*pDTCOfEvent = Dem_ConfigPtr->DemObdDTC[u16DtcRef].DemDtcValue;
							ret = E_OK;
						}
#if(DEM_J1939_SUPPORT == STD_ON)
						else if(DTCFormat == DEM_DTC_FORMAT_J1939)
						{
							*pDTCOfEvent = Dem_ConfigPtr->DemObdDTC[u16DtcRef].DemJ1939DTCValue;
							ret = E_OK;
						}
#endif /* #if(DEM_J1939_SUPPORT == STD_ON) */
						else
						{
							*pDTCOfEvent = 0u;
							ret = DEM_E_NO_DTC_AVAILABLE;
						}
					}
					else
					{
						*pDTCOfEvent = 0u;
						ret = DEM_E_NO_DTC_AVAILABLE;
					}
				}
#endif /* #if(DEM_OBD_DTC_NUM > 0) */
			}
			else
			{
				*pDTCOfEvent = 0u;
				ret = DEM_E_NO_DTC_AVAILABLE;
			}
    	}
    }
	else
	{
		ret = (Std_ReturnType)E_NOT_OK;
	}
#endif /* #if(DEM_DTC_NUM > 0) */
	return ret;
}


/**
 * @sid				0x39
 * @brief			Dem_SetEnableCondition
 * @details			Sets an enable condition.
 * @param[in]		EnableConditionID: This parameter identifies the enable condition.
 * @param[in]       ConditionFulfilled: This parameter specifies whether the enable condition assigned
 *                  to the EnableConditionID is fulfilled (TRUE) or not fulfilled (FALSE).
 *
 * @return     		Result of setting operation.
 * @retval			E_OK: enable condition  be set successfully.
 * @retval			E_NOT_OK:  setting of the enable condition failed.
 */
FUNC(Std_ReturnType, DEM_CODE) Dem_SetEnableCondition
(
    uint8 EnableConditionID,
    boolean ConditionFulfilled
)
{
	/**
	 * @req [SWS_Dem_00202] If the Dem module is requested to support enable conditions,the
	 *      Dem module shall provide the API Dem_SetEnableCondition receiving the current
	 *      status (condition fulfilled or not) of a specific enable condition
	 */
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;

#if(DEM_ENABLE_CONDITION_NUM > 0)
	uint16 u16Loop = 0u;
	const uint8*  pGroup = NULL_PTR;
	const Dem_EventParameterType* pEventPara = NULL_PTR;

	DEM_DETCHECK_API_SETENABLECONDITION(Dem_InitState,EnableConditionID,&ret);

	if(ret == (Std_ReturnType)E_NOT_OK)
    {
    	if(ConditionFulfilled == (boolean)FALSE)
    	{
    		if(Dem_ISEnable_EvEnableCondition(EnableConditionID) == (boolean)TRUE)
			{
    			Dem_Disable_EvEnableCondition(EnableConditionID);

				do
				{
					pEventPara = &(Dem_ConfigPtr->DemEventParameter[u16Loop]);

					if(pEventPara->DemEnableConditionGroupRef != 0xFFu)
					{
						pGroup = Dem_General.DemEnableConditionGroup[pEventPara->DemEnableConditionGroupRef];

						if((pGroup[EnableConditionID >> 3U] & ((uint8)((uint8)1U << (EnableConditionID & 0x07u)))) != 0U)
						{
							if(Dem_ISEnable_EnableCondition(u16Loop) == (boolean)TRUE)
							{
								ret = Dem_ConditionIsFulFilled(\
										Dem_EnableConditionStatus,\
										pGroup,\
										DEM_ENABLE_CONDITION_NUM_BYTE);

								if(ret == (boolean)FALSE)
								{
									Dem_Disable_EnableCondition(u16Loop);
									/**
									 * @req [SWS_Dem_00655] If the configuration parameter DemDebounce-
									 *      Behavior is set to DEM_DEBOUNCE_FREEZE,the Dem module shall
									 *      freeze the internal debounce timer when at least one enable
									 *      condition for the related event is set to not full filled.
									 */
									Dem_DebounceFreeze(u16Loop);

									Dem_DebounceReset(u16Loop,(boolean)FALSE);
								}
							}
						}
					}
					u16Loop++;
				}while(u16Loop < DEM_EVENT_PARAMETER_NUM);
			}
    	}
    	else /* ConditionFulfilled == (boolean)TRUE */
    	{
    		if(Dem_ISEnable_EvEnableCondition(EnableConditionID) == (boolean)FALSE)
    		{
    			Dem_Enable_EvEnableCondition(EnableConditionID);
    			do
    			{
    				pEventPara = &(Dem_ConfigPtr->DemEventParameter[u16Loop]);

    				if(pEventPara->DemEnableConditionGroupRef != 0xFFu)
    				{
						pGroup = Dem_General.DemEnableConditionGroup[pEventPara->DemEnableConditionGroupRef];

						if((pGroup[EnableConditionID >> 3U] & ((uint8)((uint8)1U << (EnableConditionID & 0x07u)))) != 0U)
						{
	    					if(Dem_ISEnable_EnableCondition(u16Loop) == (boolean)FALSE)
	    					{
	    			    		/**
	    			    		 * @req [SWS_Dem_00681] The API Dem_SetEnableCondition shall trigger the
	    			    		 *      callback function InitMonitorForEvent of the related event(s) in
	    			    		 *      case an enable condition of the event(s) is changed to fulfilled
	    			    		 *      and thus all enable conditions of the event(s) are fulfilled.The
	    			    		 *      InitMonitorReason parameter shall be set to DEM_INIT_MONITOR_RE-
	    			    		 *      ENABLED.
	    			    		 */
								ret = Dem_ConditionIsFulFilled(\
										Dem_EnableConditionStatus,\
										pGroup,\
										DEM_ENABLE_CONDITION_NUM_BYTE);

								if(ret == (boolean)TRUE)
								{
									Dem_Enable_EnableCondition(u16Loop);

#if(DEM_CALLBACK_INIT_MFOREFNC_TOTALNUM > 0)
									if(pEventPara->DemCallbackInitMForE != NULL_PTR)
									{
										if(pEventPara->DemCallbackInitMForE->\
												DemCallbackInitMForEFnc != NULL_PTR)
										{
											if(Dem_InitMonitorCbkStatus[u16Loop] == 0u)
											{
	/**
	 * @req [SWS_Dem_01046] In case multiple triggers for DemInitMonitorForEvent occur
	 * 		simultaneously, the InitMforE shall only be called once. The reason shall be
	 * 		selected by following priority: DEM_INIT_MONITOR_CLEAR (highest priority),
	 * 		DEM_INIT_MONITOR_RESTART,DEM_INIT_MONITOR_REENABLED (lowest priority).
	 */
												Dem_InitMonitorCbkStatus[u16Loop] = \
														DEM_INIT_MONITOR_REENABLED;
											}
										}
									}
#endif /* #if(DEM_CALLBACK_INIT_MFOREFNC_TOTALNUM > 0) */
								}
	    					}
						}
    				}
    				u16Loop++;
    			}while(u16Loop < DEM_EVENT_PARAMETER_NUM);
    		}
    	}
		ret = (Std_ReturnType)E_OK;
    }
	else
	{
		ret = (Std_ReturnType)E_NOT_OK;
	}
#endif /* #if(DEM_ENABLE_CONDITION_NUM > 0) */
    return ret;
}



/**
 * @sid				0x38
 * @brief			Dem_SetStorageCondition
 * @details			Sets a storage condition.
 *
 * @param[in]		StorageConditionID: This parameter identifies the storage condition.
 * @param[in]       ConditionFulfilled: This parameter specifies whether the storage condition assigned
 *                  to the StorageConditionID is fulfilled (TRUE) or not fulfilled (FALSE).
 *
 * @return     		Result of setting operation.
 * @retval			E_OK: Storage condition  be set successfully.
 * @retval			E_NOT_OK:  setting of the storage condition failed.
 */
FUNC(Std_ReturnType, DEM_CODE) Dem_SetStorageCondition
(
    uint8 StorageConditionID,
    boolean ConditionFulfilled
)
{
	/**
	 * @req [SWS_Dem_00543] If the Dem module is requested to support storage conditions,the
	 *      Dem module shall provide the API Dem_SetStorageCondition receiving the current
	 *      status (condition fulfilled or not) of a specific storage condition.
	 */
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;

#if(DEM_STORAGE_CONDITION_NUM > 0)
	uint16 u16Loop = 0u;
	Dem_EventIdType replacementEvent;
	const uint8*  pGroup = NULL_PTR;
	const Dem_EventParameterType* pEventPara = NULL_PTR;

	DEM_DETCHECK_API_SETSTORAGECONDITION(Dem_InitState,StorageConditionID,&ret);

	if(ret == (Std_ReturnType)E_NOT_OK)
    {
    	if(ConditionFulfilled == (boolean)FALSE)
		{
    		if((boolean)TRUE == Dem_ISEnable_EvStorageCondition(StorageConditionID))
    		{
				Dem_Disable_EvStorageCondition(StorageConditionID);
				do
				{
					pEventPara = &(Dem_ConfigPtr->DemEventParameter[u16Loop]);

					if(pEventPara->DemStorageConditionGroupRef != 0xFFu)
					{
						pGroup = Dem_General.DemStorageConditionGroup[\
									pEventPara->DemStorageConditionGroupRef];

						if((pGroup[StorageConditionID >> 3] & \
								(uint8)(1u << (StorageConditionID & 0x07u))) != 0u)
						{
							if((boolean)TRUE == Dem_ISEnable_StorageCondition(u16Loop))
							{
								ret = Dem_ConditionIsFulFilled(\
										Dem_StorageConditionStatus,\
										pGroup,
										DEM_STORAGE_CONDITION_NUM_BYTE);

								if(ret == (boolean)FALSE)
								{
									Dem_Disable_StorageCondition(u16Loop);
								}
							}
						}
					}
					u16Loop++;
				}while(u16Loop < DEM_EVENT_PARAMETER_NUM);
    		}
		}
		else /* ConditionFulfilled == (boolean)TRUE */
		{
			/**
			 * @req [SWS_Dem_01113] The API Dem_SetStorageCondition shall trigger the callback function
			 *      InitMonitorForEvent of the related event in case a storage condition of the event
			 *      is changed to fulfilled and thus all storage conditions of the event are fulfilled.
			 *      Furthermore the callback shall only be called,if the event did report FAILED or
			 *      PASSED while the storage condition was disabled.The InitMonitorReason parameter
			 *      shall be set to DEM_INIT_MONITOR_STORAGE_REENABLED
			 */
			if((boolean)FALSE == Dem_ISEnable_EvStorageCondition(StorageConditionID))
			{
				Dem_Enable_EvStorageCondition(StorageConditionID);
				do
				{
					pEventPara = &(Dem_ConfigPtr->DemEventParameter[u16Loop]);

					if(pEventPara->DemStorageConditionGroupRef != 0xFFu)
					{
						pGroup = Dem_General.DemStorageConditionGroup[\
									pEventPara->DemStorageConditionGroupRef];

						if((pGroup[StorageConditionID >> 3u] & \
								(uint8)(1u << (StorageConditionID & 0x07u))) != 0u)
						{
							if((boolean)FALSE == Dem_ISEnable_StorageCondition(u16Loop))
							{
								ret = Dem_ConditionIsFulFilled(\
										Dem_StorageConditionStatus,\
										pGroup,
										DEM_STORAGE_CONDITION_NUM_BYTE);

								if(ret == (boolean)TRUE)
								{
									Dem_Enable_StorageCondition(u16Loop);

									replacementEvent = Dem_General.DemStorageCondition[\
														StorageConditionID].\
														DemStorageConditionReplacementEventRef;
									/**
									 * @req [SWS_Dem_01089] The replacement event is reset
									 *      (status PASSED),when the storage condition is
									 *      fulfilled (on enabling the storage condition).
									 */
									if(replacementEvent != 0xFFFFu)
									{
										(void)Dem_EventEnterQueue(replacementEvent,\
																DEM_EVENT_STATUS_PASSED);
									}

#if(DEM_CALLBACK_INIT_MFOREFNC_TOTALNUM > 0)
									if(pEventPara->DemCallbackInitMForE != NULL_PTR)
									{
										if(pEventPara->DemCallbackInitMForE->DemCallbackInitMForEFnc \
												!= NULL_PTR)
										{
											if(Dem_InitMonitorCbkStatus[u16Loop] == 0u)
											{
												/**
												 * @req [SWS_Dem_01046] In case multiple triggers for
												 *      DemInitMonitorForEvent occur simultaneously,
												 *      the InitMforE shall only be called once. The
												 *      reason shall be selected by following priority:
												 *      DEM_INIT_MONITOR_CLEAR (highest priority),DEM_
												 *      INIT_MONITOR_RESTART,DEM_INIT_MONITOR_REENABLED
												 *      (lowest priority).
												 */
												Dem_InitMonitorCbkStatus[u16Loop] = \
														DEM_INIT_MONITOR_STORAGE_REENABLED;
											}
										}
									}
#endif /* #if(DEM_CALLBACK_INIT_MFOREFNC_TOTALNUM > 0) */
								}
							}
						}
					}
					u16Loop++;
				}while(u16Loop < DEM_EVENT_PARAMETER_NUM);
			}
		}
		ret = (Std_ReturnType)E_OK;
    }
	else
	{
		ret = (Std_ReturnType)E_NOT_OK;
	}
#endif /* #if(DEM_STORAGE_CONDITION_NUM > 0) */
    return ret;
}

/* PRQA S 3408 EOF # violate MISAR2004_8.8:It can only be used through the RTE, 
 * and therefore no declaration is exported via Dem.h. */
/**
 * @sid				0x3e
 * @brief			Dem_GetFaultDetectionCounter
 * @details			Gets the fault detection counter of an event.
 *
 * @param[in]		EventId: Identification of an event by assigned EventId.
 *
 * @param[out]		pFaultDetectionCounter: This parameter receives the Fault Detection Counter
 *                  information of the requested EventId.
 *
 * @return     		Result of getting operation.
 * @retval			E_OK: request was successful.
 * @retval			E_NOT_OK: request failed.
 * @retval			DEM_E_NO_FDC_AVAILABLE: there is no fault detection counter available for the
 *                  requested event.
 */
FUNC(Std_ReturnType, DEM_CODE) Dem_GetFaultDetectionCounter
(
    Dem_EventIdType EventId,
    P2VAR(sint8, AUTOMATIC, DEM_CODE) pFaultDetectionCounter
)
{
	/**
	 * @req [SWS_Dem_00204] The event-specific fault detection counter shall be accessible
	 *      by using the API Dem_GetFaultDetectionCounter
	 */
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;

	DEM_DETCHECK_API_GETFAULTDETECTIONCOUNTER(Dem_InitState,EventId,pFaultDetectionCounter,&ret);

	if(ret == (Std_ReturnType)E_NOT_OK)
    {
    	/**
    	 * @req [SWS_Dem_01108] If an event is set to unavailable, the corresponding event shall
    	 *      be treated as if it is not configured in the system
    	 */
    	if(Dem_ISEnable_EventAvaliable(EventId-1u) == (boolean)TRUE)
    	{
    		/**
    		 * @req [SWS_Dem_00439] If the callback-function GetFaultDetectionCounter
    		 *      returns other than E_OK,this return value shall also be returned
    		 *      by the API Dem_GetFaultDetectionCounter.
    		 */
    		ret = Dem_InternalFDCCal(EventId-1u);
    		if(ret == (Std_ReturnType)E_OK)
    		{
    			*pFaultDetectionCounter = Dem_EventInternalData[EventId-1u].currentFDC;
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
 * @sid				0x29
 * @brief			Dem_GetIndicatorStatus
 * @details			Gets the indicator status derived from the event status.
 *
 * @param[in]		IndicatorId: Number of indicator.
 *
 * @param[out]		pIndicatorStatus: Status of the indicator, like off, on, or blinking.
 *
 * @return     		Result of getting operation.
 * @retval			E_OK: Operation was successful
 * @retval			E_NOT_OK: Operation failed
 */
FUNC(Std_ReturnType, DEM_CODE) Dem_GetIndicatorStatus
(
    uint8 IndicatorId,
    P2VAR(Dem_IndicatorStatusType, AUTOMATIC, DEM_CODE) pIndicatorStatus
)
{
	/**
	 * @req [SWS_Dem_00046] The Dem module shall provide the API Dem_GetIndicatorStatus
            that a software component can get information about the calculated indicator
            status.
	 */
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;

#if(DEM_INDICATOR_NUM > 0)

	DEM_DETCHECK_API_GETINDICATORSTATUS(Dem_InitState,IndicatorId,pIndicatorStatus,&ret);

	if(ret == (Std_ReturnType)E_NOT_OK)
	{
		*pIndicatorStatus = Dem_IndicatorStatus[IndicatorId];
		ret = (Std_ReturnType)E_OK;
	}
	else
	{
		ret = (Std_ReturnType)E_NOT_OK;
	}
#endif /* #if(DEM_INDICATOR_NUM > 0) */
	return ret;
}

/**
 * @sid			  0x6e
 * @brief		  Dem_GetEventFreezeFrameDataEx
 * @details       Gets the data of a freeze frame by event.
 *
 * @param[in]     EventId: Identification of an event by assigned EventId.
 * @param[in]     RecordNumber: This parameter is a unique identifier for a freeze frame record as
 *                defined in ISO15031-5 and ISO14229-1. 0xFF means most recent freeze frame record
 *                is returned.
 * @param[in]     DataId: This parameter specifies the PID (ISO15031-5 mapped in UDS range 0xF400
 *                - 0xF4FF) or DID (ISO14229-1) that shall be copied to the destination buffer.
 *
 * @param[out]    pDestBuffer: This parameter contains a byte pointer that points to the buffer,
 *                to which the freeze frame data record shall be written to.The format is raw
 *                hexadecimal values and contains no header-information.
 *
 * @param[inout]  pBufSize: When the function is called this parameter contains the maximum number
 *                of data bytes that can be written to the buffer.The function returns the actual
 *                number of written data bytes in this parameter.
 *
 * @return        Result of getting operation.
 * @retval        E_OK: Operation was successful.
 * @retval		  E_NOT_OK: Operation could not be performed.
 * @retval        DEM_E_NODATAAVAILABLE: The requested event data is not currently stored (but the
 *                request was valid).
 * @retval        DEM_E_WRONG_RECORDNUMBER: The requested record number is not supported by the event.
 * @retval        DEM_E_WRONG_DIDNUMBER: The requested DID is not supported by the freeze frame.
 * @retval		  DEM_E_WRONG_BUFFERSIZE: The provided buffer size is too small.
 */
FUNC(Std_ReturnType, DEM_CODE) Dem_GetEventFreezeFrameDataEx
(
    Dem_EventIdType EventId,
    uint8 RecordNumber,
    uint16 DataId,
    P2VAR(uint8, AUTOMATIC, DEM_CODE) pDestBuffer,
	P2VAR(uint16, AUTOMATIC, DEM_CODE) pBufSize
)
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;

#if(DEM_FREEZE_FRAME_CLASS_NUM > 0)
	uint16 u16DtcRef = 0xFFFFu;
	const Dem_DTCAttributesType* pDtcAttr = NULL_PTR;
	const Dem_FreezeFrameClassType* pFFCls = NULL_PTR;
	const Dem_DidClassType* pDidCls = NULL_PTR;
	const Dem_DataElementClassType* pDataElemClass = NULL_PTR;
	Dem_MemoryEntryType* pEntry = NULL_PTR;
	uint8* pFFData = NULL_PTR;
	uint8 u8Loop = 0u;
	uint8 u8Flag = 0u;

#if(DEM_TYPEOFFF_RECORD_NUMERATION == DEM_FF_RECNUM_CONFIGURED)
#if(DEM_FREEZE_FRAME_REC_NUM_CLASS_NUM > 0)
	const Dem_FreezeFrameRecNumClassType* pFFRecNumCls = NULL_PTR;
#endif /* #if(DEM_FREEZE_FRAME_REC_NUM_CLASS_NUM > 0) */
#if(DEM_FREEZE_FRAME_RECORD_CLASS_NUM > 0)
	const Dem_FreezeFrameRecordClassType* pFFRecordCls = NULL_PTR;
#endif /* #if(DEM_FREEZE_FRAME_RECORD_CLASS_NUM > 0) */
#endif /* #if(DEM_TYPEOFFF_RECORD_NUMERATION == DEM_FF_RECNUM_CONFIGURED) */

#endif /* #if(DEM_FREEZE_FRAME_CLASS_NUM > 0) */


	DEM_DETCHECK_API_GETEVENTFREEZEFRAMEDATAEX(Dem_InitState,EventId,pDestBuffer,pBufSize,&ret);

	if(ret == (Std_ReturnType)E_NOT_OK)
    {
    	/**
		 * @req [SWS_Dem_01108] If an event is set to unavailable, the corresponding event shall
		 *      be treated as if it is not configured in the system
		 */
		if((boolean)FALSE == Dem_ISEnable_EventAvaliable(EventId-1u))
		{
			ret = (Std_ReturnType)E_NOT_OK;
		}
#if(DEM_TYPEOFFF_RECORD_NUMERATION == DEM_FF_RECNUM_CONFIGURED)
		/*
		 * @req [SWS_Dem_00479] If the RecordNumber is equal to 0xFF and parameter
		 * 		DemTypeOfFreezeFrameRecordNumeration is set to DEM_FF_RECNUM_CALCULATED
		 * 		the most recent record shall be used, otherwise E_NOT_OK shall be returned.
		 */
		else if(RecordNumber == 0xFFu)
		{
			ret = (Std_ReturnType)E_NOT_OK;
		}
#endif /* #if(DEM_TYPEOFFF_RECORD_NUMERATION == DEM_FF_RECNUM_CONFIGURED) */
#if(DEM_OBD_SUPPORT == DEM_OBD_NO_OBD_SUPPORT)
		/*
		 * @req [SWS_Dem_01194] The function Dem_GetEventFreezeFrameDataEx shall return
		 * 		the WWH-OBD freeze frame when called with RecordNumber 0x00. If WWH-OBD
		 * 		is not supported, the function shall return DEM_E_WRONG_RECORDNUMBER
		 * 		instead (refer to DemOBDSupport).
		 */
		else if(RecordNumber == 0x00u)
		{
			ret = (Std_ReturnType)DEM_E_WRONG_RECORDNUMBER;
		}
#endif /* #if(DEM_OBD_SUPPORT == DEM_OBD_NO_OBD_SUPPORT) */
		else
		{
			ret = (Std_ReturnType)DEM_E_WRONG_RECORDNUMBER;

#if(DEM_FREEZE_FRAME_CLASS_NUM > 0)
			if(Dem_ConfigPtr->DemEventParameter[EventId-1u].DemDTCRef != 0xFFFFu)
			{
				u16DtcRef = Dem_ConfigPtr->DemEventParameter[EventId-1u].DemDTCRef;
				pDtcAttr = &Dem_ConfigPtr->DemDTCAttributes[Dem_ConfigPtr->DemDTC[u16DtcRef].\
															DemDTCAttributesRef];

				if(pDtcAttr->DemFreezeFrameClassRef != 0xFFFFu)
				{
#if(DEM_TYPEOFFF_RECORD_NUMERATION == DEM_FF_RECNUM_CONFIGURED)
					if(pDtcAttr->DemFreezeFrameRecNumClassRef != 0xFFu)
					{
						pFFRecNumCls = &Dem_General.DemFreezeFrameRecNumClass[\
										pDtcAttr->DemFreezeFrameRecNumClassRef];

						for(u8Loop = 0u;
							u8Loop < pFFRecNumCls->DemFreezeFrameRecordClassRefNum;
							u8Loop++)
						{
							pFFRecordCls = &Dem_General.DemFreezeFrameRecordClass[pFFRecNumCls->\
											DemFreezeFrameRecordClassRefStartIndex[u8Loop]];
							if(pFFRecordCls->DemFreezeFrameRecordNumber == RecordNumber)
							{
								ret = (Std_ReturnType)DEM_E_WRONG_DIDNUMBER;
								break;
							}
						}
					}
#else /* DEM_FF_RECNUM_CALCULATED */
					if(RecordNumber <= pDtcAttr->DemMaxNumberFreezeFrameRecords)
					{
						ret = (Std_ReturnType)DEM_E_WRONG_DIDNUMBER;
					}
#endif /* #if(DEM_TYPEOFFF_RECORD_NUMERATION == DEM_FF_RECNUM_CONFIGURED) */

					if(ret == (Std_ReturnType)DEM_E_WRONG_DIDNUMBER)
					{
						pFFCls = &Dem_General.DemFreezeFrameClass[pDtcAttr->DemFreezeFrameClassRef];

						for(u8Loop = 0u; u8Loop < pFFCls->DemDidClassRefNum; u8Loop++)
						{
							pDidCls = &Dem_General.DemDidClass[pFFCls->DemDidClassRefStartIndex[u8Loop]];
							if(pDidCls->DemDidIdentifier == DataId)
							{
								if((*pBufSize) >= pDidCls->DemDidDataElementClassRefDataSize)
								{
									ret = (Std_ReturnType)DEM_E_NODATAAVAILABLE;
								}
								else
								{
									ret = (Std_ReturnType)DEM_E_WRONG_BUFFERSIZE;
								}
								break;
							}
						}
					}

					if(ret == (Std_ReturnType)DEM_E_NODATAAVAILABLE)
					{
						pEntry = Dem_GetEntryFromMemory(pDtcAttr->DemMemoryDestinationRef,EventId);
						if(pEntry != NULL_PTR)
						{
							for(u8Loop = 0u; u8Loop < DEM_MAX_NUMBER_FF_RECORDS; u8Loop++)
							{
								if(pEntry->FFInfo[u8Loop].RecNum == RecordNumber)
								{
									pFFData = pEntry->FFInfo[u8Loop].FFData;
									ret = (Std_ReturnType)E_OK;
									break;
								}
							}
						}
					}

					if(ret == (Std_ReturnType)E_OK)
					{
						for(u8Loop = 0u; u8Loop < pDidCls->DemDidDataElementClassRefNum; u8Loop++)
						{
							pDataElemClass = &Dem_General.DemDataElementClass[pDidCls->\
												DemDidDataElementClassRefStartIndex[u8Loop]];

#if(DEM_EXTERNALCSDATA_ELEMENT_NUM > 0)
							if(pDataElemClass->DemExternalCSDataElementClass != NULL_PTR)
							{
								u8Flag = pDataElemClass->DemExternalCSDataElementClass->\
											DemDataElementDataSize;
								DEM_VALUE_COPY(pDestBuffer, pFFData, u8Flag);
								pDestBuffer += u8Flag;
								pFFData += u8Flag;
							}
#endif /* #if(DEM_EXTERNALCSDATA_ELEMENT_NUM > 0) */
#if(DEM_INTERNAL_DATA_ELEMENT_NUM > 0)
							if(pDataElemClass->DemInternalDataElementClass != NULL_PTR)
							{
								u8Flag = pDataElemClass->DemInternalDataElementClass->\
											DemDataElementDataSize;
								Dem_CaptureInternalDataElement(\
										(EventId-1u),\
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
			}

#endif /* #if(DEM_FREEZE_FRAME_CLASS_NUM > 0) */
		}
    }
	else
	{
		ret = (Std_ReturnType)E_NOT_OK;
	}

    return ret;
}

/**
 * @sid		     0x6d
 * @brief		 Dem_GetEventExtendedDataRecordEx
 * @details      Gets the data of an extended data record by event.
 * @param[in]    EventId: Identification of an event by assigned EventId.
 * @param[in]    RecordNumber: Identification of requested Extended data record.Valid values are
 *               between 0x01 and 0xEF as defined in ISO14229-1.
 *
 * @param[out]   pDestBuffer: This parameter contains a byte pointer that points to the buffer,to
 *               which the extended data shall be written to. The format is raw hexadecimal values
 * 				 and contains no header-information.
 *
 * @param[inout] pBufSize: When the function is called this parameter contains the maximum number
 *               of data bytes that can be written to the buffer.The function returns the actual
 *               number of written data bytes in this parameter.
 *
 * @return       Result of getting operation.
 * @retval       E_OK: Operation was successful.
 * @retval		 E_NOT_OK: Operation could not be performed.
 * @retval       DEM_E_NODATAAVAILABLE: The requested event data is not currently stored (but the
 *               request was valid).
 * @retval       DEM_E_WRONG_RECORDNUMBER: The requested record number is not supported by the event.
 * @retval		 DEM_E_WRONG_BUFFERSIZE: The provided buffer size is too small.
 */
FUNC(Std_ReturnType, DEM_CODE) Dem_GetEventExtendedDataRecordEx
(
    Dem_EventIdType EventId,
    uint8 RecordNumber,
    P2VAR(uint8, AUTOMATIC, DEM_CODE) pDestBuffer,
	P2VAR(uint16, AUTOMATIC, DEM_CODE) pBufSize
)
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;

#if(DEM_EXTENDED_DATA_CLASS_NUM > 0)
	uint8 u8Loop = 0u;
	uint16 u16DtcRef = 0xFFFFu;
	const Dem_DTCAttributesType* pDtcAttr = NULL_PTR;
	const Dem_ExtendedDataClassType* pExtDataCls = NULL_PTR;
	const Dem_ExtendedDataRecordClassType* pExtRecCls = NULL_PTR;
	const Dem_DataElementClassType* pDataElemClass = NULL_PTR;
	Dem_MemoryEntryType* pEntry = NULL_PTR;
	uint8* pExtData = NULL_PTR;
	uint8 u8Flag = 0u;
#endif /* #if(DEM_EXTENDED_DATA_CLASS_NUM > 0) */
	DEM_DETCHECK_API_GETEVENTEXTENDEDDATARECORDEX(Dem_InitState,EventId,pDestBuffer,&ret);

	if(ret == (Std_ReturnType)E_NOT_OK)
    {
    	/**
		 * @req [SWS_Dem_01108] If an event is set to unavailable, the corresponding event shall
		 *      be treated as if it is not configured in the system
		 */
		if((boolean)FALSE == (Dem_ISEnable_EventAvaliable(EventId-1u)))
		{
			ret = (Std_ReturnType)E_NOT_OK;
		}
		else
		{
			ret = (Std_ReturnType)DEM_E_WRONG_RECORDNUMBER;

#if(DEM_EXTENDED_DATA_CLASS_NUM > 0)
			if(Dem_ConfigPtr->DemEventParameter[EventId-1u].DemDTCRef != 0xFFFFu)
			{
				u16DtcRef = Dem_ConfigPtr->DemEventParameter[EventId-1u].DemDTCRef;
				pDtcAttr = &Dem_ConfigPtr->DemDTCAttributes[Dem_ConfigPtr->DemDTC[u16DtcRef].\
															DemDTCAttributesRef];

				if(pDtcAttr->DemExtendedDataClassRef != 0xFFFFu)
				{
					pExtDataCls = &Dem_General.DemExtendedDataClass[pDtcAttr->DemExtendedDataClassRef];

					for(u8Loop = 0u; u8Loop < pExtDataCls->DemExtendedDataRecordClassRefNum; u8Loop++)
					{
						pExtRecCls = &Dem_General.DemExtendedDataRecordClass[pExtDataCls->\
										DemExtendedDataRecordClassRefStartIndex[u8Loop]];

						if(pExtRecCls->DemExtendedDataRecordNumber == RecordNumber)
						{
							/**
							 * @req [SWS_Dem_01062] The functions Dem_GetEventExtendedDataRecordEx
							 * 		and Dem_GetEventFreezeFrameDataEx shall consider only primary
							 * 		and user defined memory.
							 */
							pEntry = Dem_GetEntryFromMemory(pDtcAttr->DemMemoryDestinationRef,EventId);

							if((pEntry != NULL_PTR) && (pEntry->ExtInfo[u8Loop].RecNum == RecordNumber))
							{
								if((*pBufSize) >= pExtRecCls->DemDataElementClassRefDataSize)
								{
									pExtData = pEntry->ExtInfo[u8Loop].ExtData;
									*pBufSize = pExtRecCls->DemDataElementClassRefDataSize;
									ret = (Std_ReturnType)E_OK;
								}
								else
								{
									ret = (Std_ReturnType)DEM_E_WRONG_BUFFERSIZE;
								}
							}
							else
							{
								ret = (Std_ReturnType)DEM_E_NODATAAVAILABLE;
							}

							break;
						}
					}
				}
			}

			if(pExtData != NULL_PTR)
			{
				for(u8Loop = 0u; u8Loop < pExtRecCls->DemDataElementClassRefNum; u8Loop++)
				{
					pDataElemClass = &Dem_General.DemDataElementClass[pExtRecCls->\
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
								(EventId-1u),\
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
#endif /* #if(DEM_EXTENDED_DATA_CLASS_NUM > 0) */
		}
    }
	else
	{
		ret = (Std_ReturnType)E_NOT_OK;
	}
    return ret;
}


/**
 * @sid		     0x32
 * @brief		 Dem_GetEventMemoryOverflow
 * @details      Gets the event memory overflow indication status.
 *
 * @param[in]    DTCOrigin: If the Dem supports more than one event memory this parameter is used to
 * 				 select the source memory the overflow indication shall be read from.
 *
 * @param[out]   pOverflowIndication: This parameter returns TRUE if the according event memory was
 *               overflowed,otherwise it returnsFALSE.
 *
 * @return       Result of getting operation.
 * @retval       E_OK: Operation was successful.
 * @retval		 E_NOT_OK: Operation failed or is not supported.
 */
FUNC(Std_ReturnType, DEM_CODE) Dem_GetEventMemoryOverflow
(
    Dem_DTCOriginType DTCOrigin,
    P2VAR(boolean, AUTOMATIC, DEM_VAR) pOverflowIndication
)
{
    Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;

    DEM_DETCHECK_API_GETEVENTMEMORYOVERFLOW(Dem_InitState,pOverflowIndication,&ret);

    if(ret == (Std_ReturnType)E_NOT_OK)
    {
    	/**
    	 * @req [SWS_Dem_00398] The Dem module shall provide the API Dem_GetEventMemoryOverflow to
    	 *      provide access to the event memory overflow indication status of the respective event
    	 *      memory
    	 */
    	switch(DTCOrigin)
    	{
    	case DEM_DTC_ORIGIN_PRIMARY_MEMORY:
    		*pOverflowIndication = Dem_PrimaryMemoryInfo.OverFlow;
    		ret = (Std_ReturnType)E_OK;
    		break;

#if(DEM_MAX_NUMBER_EVENTENTRY_PERMANENT > 0)
    	case DEM_DTC_ORIGIN_PERMANENT_MEMORY:
    		break;
#endif /* #if(DEM_MAX_NUMBER_EVENTENTRY_PERMANENT > 0) */

#if(DEM_MIRROR_MEMORY_NUM > 0)
    	case DEM_DTC_ORIGIN_MIRROR_MEMORY:
    		break;
#endif /* 	#if(DEM_MIRROR_MEMORY_NUM > 0) */

#if(DEM_USERDEFINE_MEMORY_NUM > 0)
    	case 0xFFFF:
    		break;
#endif /* #if(DEM_USERDEFINE_MEMORY_NUM > 0) */

    	default:
    		DEM_DET_ERROR_REPORT(DEM_SID_GETEVENTMEMORYOVERFLOW,DEM_E_WRONG_CONFIGURATION);
    		break;
    	}
    }
    else
    {
    	ret = (Std_ReturnType)E_NOT_OK;
    }
    return ret;
}

/**
 * @sid		     0x35
 * @brief		 Dem_GetNumberOfEventMemoryEntries
 * @details      Returns the number of entries currently stored in the requested event memory.
 *
 * @param[in]    DTCOrigin: If the Dem supports more than one event memory this parameter is used to
 * 				 select the source memory the overflow indication shall be read from.
 *
 * @param[out]   pNumberOfEventMemoryEntries:Number of entries currently stored in the requested event
 *               memory.
 *
 * @return       Result of getting operation.
 * @retval       E_OK: Operation was successful
 * @retval		 E_NOT_OK: Operation failed
 */
FUNC(Std_ReturnType, DEM_CODE) Dem_GetNumberOfEventMemoryEntries
(
    Dem_DTCOriginType DTCOrigin,
    P2VAR(uint8, AUTOMATIC, DEM_CODE) pNumberOfEventMemoryEntries
)
{
    Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;

    DEM_DETCHECK_API_GETNUMBEROFEVENTMEMORYENTRIES(Dem_InitState,pNumberOfEventMemoryEntries,&ret,FALSE);

    if(ret == (Std_ReturnType)E_NOT_OK)
    {
    	*pNumberOfEventMemoryEntries = 0u;
    	/**
    	 * @req [SWS_Dem_00651] The Dem module shall provide the API Dem_GetNumberOfEventMemoryEntries
    	 *      to return the number of event memory entries currently stored in the event memory.
    	 */
    	if(DTCOrigin == DEM_DTC_ORIGIN_PRIMARY_MEMORY)
    	{
    		*pNumberOfEventMemoryEntries = Dem_PrimaryMemoryInfo.EntryNum;
    		ret = (Std_ReturnType)E_OK;
    	}
		else if(DTCOrigin == DEM_DTC_ORIGIN_MIRROR_MEMORY)
		{
#if(DEM_MIRROR_MEMORY_NUM > 0)
			/* todo */
#endif /* #if(DEM_MIRROR_MEMORY_NUM > 0) */
			ret = (Std_ReturnType)E_OK;
		}
		else if(DTCOrigin == DEM_DTC_ORIGIN_PERMANENT_MEMORY)
		{
#if(DEM_MAX_NUMBER_EVENTENTRY_PERMANENT > 0)
			/* todo */
#endif /* #if(DEM_MAX_NUMBER_EVENTENTRY_PERMANENT > 0) */
			ret = (Std_ReturnType)E_OK;
		}
		else
		{
			DEM_DETCHECK_API_GETNUMBEROFEVENTMEMORYENTRIES(FALSE,FALSE,&ret,TRUE);
		}
    }
    else
    {
    	ret = (Std_ReturnType)E_NOT_OK;
    }
    return ret;
}


/**
 * @sid		    	0x2b
 * @brief		 	Dem_SetComponentAvailable
 * @details     	Set the availability of a specific DemComponent.
 *
 * @param[in]   	ComponentId: Identification of a DemComponent.
 * @param[in]		AvailableStatus: This parameter specifies whether the respective Component shall
 *                  be available (TRUE) or not (FALSE).
 *
 * @return       	Result of setting operation.
 * @retval       	E_OK: Operation was successful
 * @retval		 	E_NOT_OK: Operation failed
 */
FUNC(Std_ReturnType, DEM_CODE) Dem_SetComponentAvailable
(
	Dem_ComponentIdType ComponentId,
	boolean AvailableStatus
)
{
	Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;
	DEM_DETCHECK_API_SETCOMPONENTAVAILABLE(Dem_InitState,ComponentId,&ret);

	if(ret == (Std_ReturnType)E_NOT_OK)
	{
#if(DEM_COMPONENT_NUM > 0)
		/**
		 * @req [SWS_Dem_01135] The interface Dem_SetComponentAvailable shall be
		 * 		available to set the availability state of a component.
		 */
		if(AvailableStatus == (boolean)TRUE)
		{
			Dem_Enable_ComponentAvailable(ComponentId - 1u);
		}
		else
		{
			Dem_Disable_ComponentAvailable(ComponentId - 1u);
		}
		ret = (Std_ReturnType)E_OK;
#endif /* #if(DEM_COMPONENT_NUM > 0) */
	}

	return ret;
}

#if(DEM_SUPPRESSION_SUPPORT == DEM_DTC_SUPPRESSION)
/*
 * @sid		     	0x33
 * @brief		 	Dem_SetDTCSuppression
 * @details      	Set the suppression status of a specific DTC.
 *
 * @param[in]    	DTC: Diagnostic Trouble Code
 * @param[in]		DTCFormat: Defines the input-format of the provided DTC value.
 * @param[in]		SuppressionStatus:This parameter specifies whether the respective DTC shall be
 *                  disabled (TRUE) or enabled (FALSE).
 *
 * @return       	Result of setting operation.
 * @retval       	E_OK: Operation was successful.
 * @retval		 	E_NOT_OK: operation failed or event entry for this DTC still exists.
 */
FUNC(Std_ReturnType, DEM_CODE) Dem_SetDTCSuppression
(
    uint32 DTC,
    Dem_DTCFormatType DTCFormat,
    boolean SuppressionStatus
)
{
    Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;

#if(DEM_SUPPRESSION_SUPPORT == DEM_DTC_SUPPRESSION)
    uint16 u16DtcIndex;

    DEM_DETCHECK_API_SETDTCSUPPRESSION(Dem_InitState,&ret);

    if(ret == (Std_ReturnType)E_NOT_OK)
    {
    	u16DtcIndex = Dem_GetDtcIndexByDtc(DTC,DTCFormat);

    	if(u16DtcIndex != 0xFFFFu)
    	{
			if(SuppressionStatus == (boolean)TRUE)
			{
				Dem_Enable_DTCSuppress(u16DtcIndex);
			}
			else
			{
				Dem_Disable_DTCSuppress(u16DtcIndex);
			}
			ret = (Std_ReturnType)E_OK;
		}
    }
    else
    {
    	ret = (Std_ReturnType)E_NOT_OK;
    }
#endif /* #if(DEM_SUPPRESSION_SUPPORT == DEM_DTC_SUPPRESSION) */
    return ret;
}
#endif /* #if(DEM_SUPPRESSION_SUPPORT == DEM_DTC_SUPPRESSION) */

/* PRQA S 3408 EOF # violate MISAR2004_8.8: This API is intended for complex device driver. 
 * It can only be used through the RTE (due to work-around described below SWS_Dem_00659), 
 * and therefore no declaration is exported via Dem.h. */
/*
 * @sid		     	0x23
 * @brief		 	Dem_ClearDTC
 * @details      	Clears single DTCs, as well as groups of DTCs.
 *
 * @param[in]    	DTC: Defines the DTC in respective format,that shall be cleared from the
 *                  event memory.If the DTC fits to a DTC group number, all DTCs of the group
 *                  shall be cleared.
 * @param[in]		DTCFormat: Defines the input-format of the provided DTC value.
 * @param[in]		DTCOrigin: If the Dem supports more than one event memory this parameter
 *                  is used to select the source memory the DTCs shall be read from.
 *
 * @return       	Result of clear DTC.
 * @retval       	DEM_CLEAR_OK: DTC successfully cleared.
 * @retval		 	DEM_CLEAR_WRONG_DTC: DTC value not existing (in this format).
 * @retval		 	DEM_CLEAR_WRONG_DTCORIGIN: Wrong DTC origin.
 * @retval		 	DEM_CLEAR_FAILED: DTC clearing failed.
 * @retval		 	DEM_CLEAR_PENDING: The DTC clearing is performed asynchronously and still
 *                  pending.The caller can retry later.
 * @retval		 	DEM_CLEAR_BUSY: DTC not cleared, as another clearing process is in progress.
 *                  The caller can retry later.
 * @retval 		 	DEM_CLEAR_MEMORY_ERROR: An error occurred during erasing a memory location
 *                  (e.g. if DemClearDTCBehavior in Dem is set to DEM_CLRRESP_NONVOLATILE_FINISH
 *                  and erasing of non-volatile-block failed).
 */
FUNC(Dem_ReturnClearDTCType, DEM_CODE)Dem_ClearDTC
(
    uint32 DTC,
    Dem_DTCFormatType DTCFormat,
    Dem_DTCOriginType DTCOrigin
)
{
	return DEM_CLEAR_OK;
}

/*
 * @sid		     	0x55
 * @brief		 	Dem_MainFunction
 * @details      	Processes all not event based Dem internal functions.
 */
FUNC(void, DEM_CODE)Dem_MainFunction
(
	void
)
{
	if(Dem_InitState == DEM_STATE_INIT)
	{
#if((DEM_DEBOUNCE_COUNTER_BASED_EVENT_NUM > 0) || (DEM_DEBOUNCE_TIME_BASED_EVENT_NUM > 0))
		Dem_RecoverFreeze();
#endif /* #if((DEM_DEBOUNCE_COUNTER_BASED_EVENT_NUM > 0) || (DEM_DEBOUNCE_TIME_BASED_EVENT_NUM > 0)) */

#if((DEM_DEBOUNCE_TIME_BASED_SUPPORT == STD_ON) && (DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0u))
		Dem_DebounceTimerDeal();
#endif /*#if((DEM_DEBOUNCE_TIME_BASED_SUPPORT == STD_ON) && (DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0u))*/

#if(DEM_CALLBACK_INIT_MFOREFNC_TOTALNUM > 0)
		Dem_InitMonitorCbkDeal();
#endif /* #if(DEM_CALLBACK_INIT_MFOREFNC_TOTALNUM > 0) */

		Dem_EventQueueDeal();

#if((DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU) || (DEM_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
		Dem_OBDInfoUpdate();
#endif /* #if((DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU) || (DEM_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU)) */

		Dem_PendingDeal();
	}
#if (DEM_DEV_ERROR_DETECT == STD_ON)
	else
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
    	DEM_DET_ERROR_REPORT(DEM_SID_MAINFUNCTION,DEM_E_UNINIT);
    }
#endif /* #if (DEM_DEV_ERROR_DETECT == STD_ON) */
}

/*
 * @brief        	Dem_GetMemInfoByOrigin
 * @details			Get event memory info by dtc origin.
 *
 * @param[in]       DTCOrigin:If the Dem supports more than one event memory,this parameter is used
 *                  to select the source memory the DTCs shall be read from.
 *
 * @return          Event memory info of the reported dtc origin.
 */
FUNC(Dem_MemoryInfoType*, DEM_CODE)Dem_GetMemInfoByOrigin
(
	Dem_DTCOriginType DTCOrigin
)
{
	Dem_MemoryInfoType* pMemInfo = NULL_PTR;

	if(DTCOrigin == DEM_DTC_ORIGIN_PRIMARY_MEMORY)
	{
		pMemInfo = &Dem_PrimaryMemoryInfo;
	}
#if(DEM_MIRROR_MEMORY_NUM > 0)
	else if(DTCOrigin == DEM_DTC_ORIGIN_MIRROR_MEMORY)
	{

	}
#endif /* #if(DEM_MIRROR_MEMORY_NUM > 0) */
#if(DEM_MAX_NUMBER_EVENTENTRY_PERMANENT > 0)
	else if(DTCOrigin == DEM_DTC_ORIGIN_PERMANENT_MEMORY)
	{
		pMemInfo = &Dem_PermanentMemoryInfo;
	}
#endif /* #if(DEM_MAX_NUMBER_EVENTENTRY_PERMANENT > 0) */
#if(DEM_USERDEFINE_MEMORY_NUM > 0)
	else
	{

	}
#endif /* #if(DEM_USERDEFINE_MEMORY_NUM > 0) */

	return pMemInfo;
}

#if(DEM_DTC_NUM > 0)
/*
 * @brief        	Dem_GetEntryFromMemory
 * @details			Check whether event has already stored in the event memory or not.
 *
 * @param[in]       MemDest: Origin memory which shall be checked.
 * @param[in]		EventId: Event identifier.
 *
 * @return          If event has already stored,it will return related entry,otherwise
 *                  it shall return null pointer.
 */
FUNC(Dem_MemoryEntryType*, DEM_CODE)Dem_GetEntryFromMemory
(
	Dem_DTCOriginType MemDest,
	Dem_EventIdType EventId
)
{
	uint8 u8Loop = 0u;
	uint8 u8EntryNum = 0u;

#if(DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONSTORAGE)
	uint16 u16DtcRef = 0xFFFFu;
	if(EventId != 0u)
	{
		u16DtcRef = Dem_ConfigPtr->DemEventParameter[(EventId - 1u)].DemDTCRef;
	}
#endif

	Dem_MemoryEntryType* entryPtr = NULL_PTR;
	/* PRQA S 2981 EOF # violate MISAR2004_21.1 :Pointer initialization assignment. */
	Dem_MemoryEntryType* pEntry = NULL_PTR;

	if(MemDest == DEM_DTC_ORIGIN_PRIMARY_MEMORY)
	{
		pEntry = DemPrimaryMemory;
		u8EntryNum = DEM_MAX_NUMBER_EVENTENTRY_PRIMARY;
	}
#if(DEM_MIRROR_MEMORY_NUM > 0)
	else if(MemDest == DEM_DTC_ORIGIN_MIRROR_MEMORY)
	{

	}
#endif /* #if(DEM_MIRROR_MEMORY_NUM > 0) */
#if(DEM_MAX_NUMBER_EVENTENTRY_PERMANENT > 0)
	else if(MemDest == DEM_DTC_ORIGIN_PERMANENT_MEMORY)
	{
		pEntry = DemPermanentMemory;
		u8EntryNum = DEM_MAX_NUMBER_EVENTENTRY_PERMANENT;
	}
#endif /* #if(DEM_MAX_NUMBER_EVENTENTRY_PERMANENT > 0) */
#if(DEM_USERDEFINE_MEMORY_NUM > 0)
	else
	{

	}
#endif /* #if(DEM_USERDEFINE_MEMORY_NUM > 0) */

	if(pEntry != NULL_PTR)
	{
		while(u8Loop < u8EntryNum) /* PRQA S 2877 #violate MISAR2004_21.1: This loop will be executed more than once */
		{
#if(DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONSTORAGE)
			if(EventId != 0u)
			{
				if(pEntry->EventId != 0)
				{
					if(u16DtcRef == Dem_ConfigPtr->DemEventParameter[(pEntry->EventId - 1u)].DemDTCRef)
					{
						entryPtr = pEntry;
						break;
					}
				}
			}
			else
#endif /* #if(DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONSTORAGE) */
			{
				if(pEntry->EventId == EventId)
				{
					entryPtr = pEntry;
					break;
				}
			}
			u8Loop++;
			pEntry++; /* PRQA S 2983 #violate MISAR2004_21.1: The value of this object will be
							   * subsequently used when u8EntryNum is bigger than 1 */
		}
	}

	return entryPtr;
}
#endif /* #if(DEM_DTC_NUM > 0) */

/*
 * @brief        	Dem_DebounceReset
 * @details			Reset debounce counter or debounce timer of relate event.
 *
 * @param[in]       InternalEventId: Internal event identifier which value is equal to EventId - 1,
 *                  used to retrieve configurations.
 *                  IsResetAll: Reset all debounce or not.
 */
FUNC(void, DEM_CODE)Dem_DebounceReset
(
	Dem_EventIdType InternalEventId,
	boolean IsResetAll
)
{
	/**
	 * @req [SWS_Dem_00684] If the API Dem_ResetEventDebounceStatus is called with
	 *      DEM_DEBOUNCE_STATUS_RESET, it shall reset the related fault detection
	 *      counter. The internal debounce counter is reset to zero. The reset of
	 *      an internal debounce timer will also stop this timer.
	 */
	if(Dem_ConfigPtr->DemEventParameter[InternalEventId].DemDebounceAlgorithmClassType \
			== DEM_DEBOUNCE_COUNTER_BASED)
	{
#if(DEM_DEBOUNCE_COUNTER_BASED_SUPPORT == STD_ON)
#if(DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM > 0u)
		if(Dem_ConfigPtr->DemEventParameter[InternalEventId].DemDebounceInfoIndex\
				< DEM_DEBOUNCE_COUNTER_BASED_EVENT_NUM)
		{
			if((Dem_ConfigPtr->DemDebounceCounterBasedClass[Dem_ConfigPtr->\
					DemEventParameter[InternalEventId].DemDebounceAlgorithmRef].DemDebounceBehavior \
					== DEM_DEBOUNCE_RESET) || (IsResetAll == (boolean)TRUE))
			{
				Dem_InternalDebounceCounter[Dem_ConfigPtr->DemEventParameter[InternalEventId].\
									DemDebounceInfoIndex].status = DEM_EVENT_STATUS_PREPASSED;

				Dem_InternalDebounceCounter[Dem_ConfigPtr->DemEventParameter[InternalEventId].\
									DemDebounceInfoIndex].counter = (sint16)0;
			}
		}
#endif /* #if(DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM > 0) */
#endif /* #if(DEM_DEBOUNCE_COUNTER_BASED_SUPPORT == STD_ON) */
	}
	else if(Dem_ConfigPtr->DemEventParameter[InternalEventId].DemDebounceAlgorithmClassType\
			== DEM_DEBOUNCE_TIME_BASE)
	{
#if(DEM_DEBOUNCE_TIME_BASED_SUPPORT == STD_ON)
#if(DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0u)
		if(Dem_ConfigPtr->DemEventParameter[InternalEventId].DemDebounceInfoIndex\
				< DEM_DEBOUNCE_TIME_BASED_EVENT_NUM)
		{
			if((Dem_ConfigPtr->DemDebounceTimeBaseClass[Dem_ConfigPtr->\
					DemEventParameter[InternalEventId].DemDebounceAlgorithmRef].DemDebounceBehavior \
					== DEM_DEBOUNCE_RESET) || (IsResetAll == (boolean)TRUE))
			{
				DemInternalDebounceTimer[Dem_ConfigPtr->DemEventParameter[InternalEventId].\
									DemDebounceInfoIndex].timeout = 0u;

				DemInternalDebounceTimer[Dem_ConfigPtr->DemEventParameter[InternalEventId].\
									DemDebounceInfoIndex].triggered = (boolean)FALSE;

				DemInternalDebounceTimer[Dem_ConfigPtr->DemEventParameter[InternalEventId].\
									DemDebounceInfoIndex].status = DEM_EVENT_STATUS_PREPASSED;
			}
		}
#endif /* #if(DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0) */
#endif /* #if(DEM_DEBOUNCE_TIME_BASED_SUPPORT == STD_ON) */
	}
	else
	{
		;
	}
}

/*
 * @brief        	Dem_DebounceFreeze
 * @details			Freeze debounce timer of relate event.
 *
 * @param[in]       InternalEventId: Internal event identifier which value is equal to EventId - 1,
 *                  used to retrieve configurations.
 */

FUNC(void, DEM_CODE)Dem_DebounceFreeze
(
	Dem_EventIdType InternalEventId
)
{
	if(Dem_ConfigPtr->DemEventParameter[InternalEventId].DemDebounceAlgorithmClassType\
			== DEM_DEBOUNCE_COUNTER_BASED)
	{
#if(DEM_DEBOUNCE_COUNTER_BASED_SUPPORT == STD_ON)
#if(DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM > 0)
		if(Dem_ConfigPtr->DemEventParameter[InternalEventId].DemDebounceInfoIndex\
				< DEM_DEBOUNCE_COUNTER_BASED_EVENT_NUM)
		{
			if(Dem_ConfigPtr->DemDebounceCounterBasedClass[Dem_ConfigPtr->\
					DemEventParameter[InternalEventId].DemDebounceAlgorithmRef].DemDebounceBehavior \
					== DEM_DEBOUNCE_FREEZE)
			{
				Dem_InternalDebounceCounter[Dem_ConfigPtr->DemEventParameter[InternalEventId].\
									DemDebounceInfoIndex].isFreeze = (boolean)TRUE;
			}
		}
#endif /* #if(DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM > 0) */
#endif /* #if(DEM_DEBOUNCE_COUNTER_BASED_SUPPORT == STD_ON) */
	}
	/**
	 * @req [SWS_Dem_00685] If the API Dem_ResetEventDebounceStatus is called with
	 *      DEM_DEBOUNCE_STATUS_FREEZE,it shall freeze the related internal debounce
	 *      timer
	 */
	else if(Dem_ConfigPtr->DemEventParameter[InternalEventId].DemDebounceAlgorithmClassType \
			== DEM_DEBOUNCE_TIME_BASE)
	{
#if(DEM_DEBOUNCE_TIME_BASED_SUPPORT == STD_ON)
#if(DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0)
		if(Dem_ConfigPtr->DemEventParameter[InternalEventId].DemDebounceInfoIndex \
				< DEM_DEBOUNCE_TIME_BASED_EVENT_NUM)
		{
			if(Dem_ConfigPtr->DemDebounceTimeBaseClass[Dem_ConfigPtr->\
					DemEventParameter[InternalEventId].DemDebounceAlgorithmRef].DemDebounceBehavior \
					== DEM_DEBOUNCE_FREEZE)
			{
				DemInternalDebounceTimer[Dem_ConfigPtr->DemEventParameter[InternalEventId].\
										 DemDebounceInfoIndex].isFreeze = (boolean)TRUE;
			}
		}
#endif /* #if(DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0) */
#endif /* #if(DEM_DEBOUNCE_TIME_BASED_SUPPORT == STD_ON) */
	}
	else
	{
		;
	}
}

/*
 * @brief        	Dem_DeleMemoryEntry
 * @details			Delete event entry from event memory.
 *
 * @param[in]		MemDest: Event memory which this entry stored in.
 * @param[in]		EntryPtr: Event entry which will be deleted from memory.
 */
FUNC(void, DEM_CODE) Dem_DeleMemoryEntry
(
	Dem_DTCOriginType MemDest,
	Dem_MemoryEntryType* EntryPtr
)
{
	uint8 u8Loop = 0u;
	uint8 u8EntryNum = 0u;
	/* PRQA S 2981 EOF # violate MISAR2004_21.1 :Pointer initialization assignment. */
	Dem_MemoryEntryType* pEntry = Dem_GetMemoryConf(MemDest,&u8EntryNum);

	Dem_MemoryInfoType *pMemInfo = 	Dem_GetMemInfoByOrigin(MemDest);

	while(u8Loop < u8EntryNum) /* PRQA S 2877 #violate MISAR2004_21.1: This loop will be executed more than once */
	{
		if(EntryPtr->AbsTime < pEntry->AbsTime)
		{
			pEntry->AbsTime--;
		}
		u8Loop++;
		pEntry++; /* PRQA S 2983 #violate MISAR2004_21.1: The value of this object will be 
                           * subsequently used when u8EntryNum is bigger than 1 */
	}

	EntryPtr->AbsTime = 0u;

#if(DEM_MAX_NUMBER_FF_RECORDS > 0)
	u8Loop = 0u;
	/* PRQA S 2877 ++ #violate MISAR2004_21.1:This loop will be executed 
           more than once if DEM_MAX_NUMBER_FF_RECORDS is bigger than zero.  */
	while(u8Loop < DEM_MAX_NUMBER_FF_RECORDS)
	{
		DEM_VALUE_SET(EntryPtr->FFInfo[u8Loop].FFData,0xFFu,DEM_FREEZE_FRAME_MAX_LEN);
		EntryPtr->FFInfo[u8Loop].RecNum = 0xFFu;
		/* PRQA S 2984 ++ #violate MISAR2004_21.1:The value of the result is variable  */
		u8Loop++;
		/* PRQA S 2984 -- */
	}
	/* PRQA S 2877 -- */
#endif /* #if(DEM_MAX_NUMBER_FF_RECORDS > 0) */

#if(DEM_MAX_NUMBER_EXT_REC > 0)
	u8Loop = 0u;
	while(u8Loop < DEM_MAX_NUMBER_EXT_REC)
	{
		DEM_VALUE_SET(EntryPtr->ExtInfo[u8Loop].ExtData,0xFFu,DEM_EXTENDED_DATA_REC_MAX_LEN);
		EntryPtr->ExtInfo[u8Loop].RecNum = 0xFFu;
		u8Loop++;
	}
#endif /* #if(DEM_MAX_NUMBER_EXT_REC > 0) */

#if(DEM_PID_CLASS_NUM > 0)
	u8Loop = 0u;
	while(u8Loop < DEM_PID_CLASS_NUM)
	{
		DEM_VALUE_SET(EntryPtr->PidInfo[u8Loop].PidData,0xFFu,DEM_PID_DATA_MAX_LEN);
		EntryPtr->PidInfo[u8Loop].PidId = 0xFFu;
		u8Loop++;
	}
#endif /* #if(DEM_PID_CLASS_NUM > 0) */

	EntryPtr->UdsStatus          		= 0x50u;
	EntryPtr->AgingCounter       		= 0x00u;
	EntryPtr->HealingCounter     		= 0x00u;
	EntryPtr->FailureCounter     		= 0x00u;
	EntryPtr->OccurrenceCounter  		= 0x00u;
	EntryPtr->CyclesSinceLastFailed		= 0x00u;
	EntryPtr->CyclesSinceFirstFailed	= 0x00u;
	EntryPtr->EventId		     		= 0x00u;
#if(DEM_MAX_NUMBER_FF_RECORDS > 0)
	EntryPtr->FFStoreNum		 		= 0x00u;
	EntryPtr->LastestFF					= 0x00u;
#endif /* #if(DEM_MAX_NUMBER_FF_RECORDS > 0) */

	if((pMemInfo != NULL_PTR) && (pMemInfo->EntryNum > (uint8)0))
	{
		pMemInfo->EntryNum--;
		if(pMemInfo->EntryNum == 0u)
		{
			pMemInfo->OverFlow = (boolean)FALSE;
		}
	}
}

/*
 * @brief        	Dem_GetDtcIndexByDtc
 * @details			Get the index of dtc configurations by dtc value.
 *
 * @param[in]		DTCFormat: The format of the DTC value.
 * @param[in]    	DTC: Diagnostic trouble code.
 *
 * @return          If get index successful,it shall return the index of dtc.
 *                  Otherwise it shall return 0xFF.
 */
FUNC(uint16, DEM_CODE) Dem_GetDtcIndexByDtc
(
	uint32 DTC,
    Dem_DTCFormatType DTCFormat
)
{
	uint16 u16DtcIndex = 0xFFFFu;

#if(DEM_DTC_NUM > 0)
	uint16 u16Loop;

	if(DTCFormat == DEM_DTC_FORMAT_UDS)
	{
		for(u16Loop = 0u; u16Loop < DEM_DTC_NUM; u16Loop++)
		{
			if(Dem_ConfigPtr->DemDTC[u16Loop].DemDtcValue == DTC)
			{
				u16DtcIndex = u16Loop;
				break;
			}
		}
	}
#if(DEM_OBD_DTC_NUM > 0)
	else if(DTCFormat == DEM_DTC_FORMAT_OBD)
	{
		if(DTC > 0xFFFF33u)
		{
			for(u16Loop = 0u; u16Loop < DEM_DTC_NUM; u16Loop++)
			{
				if(Dem_ConfigPtr->DemDTC[u16Loop].DemDtcValue == DTC)
				{
					u16DtcIndex = u16Loop;
					break;
				}
			}
		}
		else
		{
			for(u16Loop = 0u; u16Loop < DEM_DTC_NUM; u16Loop++)
			{
				if(Dem_ConfigPtr->DemObdDTC[Dem_ConfigPtr->DemDTC[u16Loop].DemObdDTCRef].\
						DemDtcValue == DTC)
				{
					u16DtcIndex = u16Loop;
					break;
				}
			}
		}
	}
#endif /* #if(DEM_OBD_DTC_NUM > 0) */
#if((DEM_OBD_DTC_NUM > 0) && (DEM_J1939_SUPPORT == STD_ON))
	else if(DTCFormat == DEM_DTC_FORMAT_J1939)
	{
		for(u16Loop = 0u; u16Loop < DEM_DTC_NUM; u16Loop++)
		{
			if(Dem_ConfigPtr->DemObdDTC[Dem_ConfigPtr->DemDTC[u16Loop].DemObdDTCRef].\
					DemJ1939DTCValue == DTC)
			{
				u16DtcIndex = u16Loop;
				break;
			}
		}
	}
#endif /* #if((DEM_OBD_DTC_NUM > 0) && (DEM_J1939_SUPPORT == STD_ON) )*/
#endif /* #if(DEM_DTC_NUM > 0) */

	return u16DtcIndex;
}


/*
 * @brief        	Dem_GetMemoryConf
 * @details			Get the configuration of requested event memory.
 *
 * @param[in]		DTCOrigin: requested event memory.
 *
 * @param[out]    	pEntryNum: Max entry num which can store in requested event memory.
 *
 * @return          The first event entry of requested event memory.
 */
FUNC(Dem_MemoryEntryType*, DEM_CODE)Dem_GetMemoryConf
(
	Dem_DTCOriginType DTCOrigin,
	P2VAR(uint8,AUTOMATIC,DEM_CONST) pEntryNum
)
{
	Dem_MemoryEntryType* pEntry = NULL_PTR;

	if(DTCOrigin == DEM_DTC_ORIGIN_PRIMARY_MEMORY)
	{
		pEntry = DemPrimaryMemory;
		*pEntryNum = DEM_MAX_NUMBER_EVENTENTRY_PRIMARY;
	}
#if(DEM_MAX_NUMBER_EVENTENTRY_PERMANENT > 0)
	if(DTCOrigin == DEM_DTC_ORIGIN_PERMANENT_MEMORY)
	{
		pEntry = DemPermanentMemory;
		*pEntryNum = DEM_MAX_NUMBER_EVENTENTRY_PERMANENT;
	}
#endif /* #if(DEM_MAX_NUMBER_EVENTENTRY_PERMANENT > 0) */
#if(DEM_MIRROR_MEMORY_NUM > 0)
	else if(MemDest == DEM_DTC_ORIGIN_MIRROR_MEMORY)
	{

	}
#endif /* #if(DEM_MIRROR_MEMORY_NUM > 0) */
	else
	{
#if(DEM_USERDEFINE_MEMORY_NUM > 0)

#endif /* #if(DEM_USERDEFINE_MEMORY_NUM > 0) */
	}
	return pEntry;
}

#if(DEM_DTC_NUM > 0)
FUNC(boolean, DEM_CODE)Dem_ClearDtcStatus
(
	Dem_EventIdType InternalId
)
{
	boolean ret = (boolean)TRUE;
#if(DEM_CALLBACK_CLEAR_EVENT_ALLOWED_NUM > 0)
	boolean clearCommand = (boolean)TRUE;
	boolean clearAllowed = (boolean)FALSE;
#endif /* #if(DEM_CALLBACK_CLEAR_EVENT_ALLOWED_NUM > 0) */

	uint16 u16DtcRef = Dem_ConfigPtr->DemEventParameter[InternalId].DemDTCRef;

#if((DEM_CALLBACK_INIT_MFOREFNC_TOTALNUM > 0) || (DEM_CALLBACK_CLEAR_EVENT_ALLOWED_NUM > 0))
	const Dem_EventParameterType* pEventPara = &(Dem_ConfigPtr->DemEventParameter[InternalId]);
#endif /* #if((DEM_CALLBACK_INIT_MFOREFNC_TOTALNUM > 0)
           || (DEM_CALLBACK_CLEAR_EVENT_ALLOWED_NUM > 0)) */

#if(DEM_CALLBACK_INIT_MFOREFNC_TOTALNUM > 0)
	/**
	 * @req [SWS_Dem_00680] Any Dem_<...>ClearDTC API (refer to chapter 7.6.2.2) shall trigger the
	 *      callback function InitMonitorForEvent of the related event(s) in case of clearing the
	 *      event(s). The InitMonitorReason parameter shall be set to DEM_INIT_MONITOR_CLEAR.
	 */
	if(pEventPara->DemCallbackInitMForE != NULL_PTR)
	{
		if(pEventPara->DemCallbackInitMForE->DemCallbackInitMForEFnc != NULL_PTR)
		{
			/**
			 * @req [SWS_Dem_01046] In case multiple triggers for DemInitMonitorForEvent occur
			 *      simultaneously,the InitMforE shall only be called once.The reason shall be
			 *      selected by following priority: DEM_INIT_MONITOR_CLEAR (highest priority),
			 *      DEM_INIT_MONITOR_RESTART,DEM_INIT_MONITOR_REENABLED (lowest priority).
			 */
			Dem_InitMonitorCbkStatus[InternalId] = DEM_INIT_MONITOR_CLEAR;
		}
	}
#endif /* #if(DEM_CALLBACK_INIT_MFOREFNC_TOTALNUM > 0) */

#if(DEM_CALLBACK_CLEAR_EVENT_ALLOWED_NUM > 0)
	/**
	 * @req [SWS_Dem_00515] The Dem module shall call the callback ClearEventAllowed for each event
	 *      it is configured for, before clearing this event (via Dem_<...>ClearDTC).
	 */
	if((pEventPara->DemCallbackClearEventAllowed != NULL_PTR)\
			&&(pEventPara->DemCallbackClearEventAllowed->DemClearEventAllowed != NULL_PTR))
	{
		if((Std_ReturnType)E_OK == pEventPara->DemCallbackClearEventAllowed->\
				DemClearEventAllowed(&clearAllowed))
		{
			ret = clearAllowed;
			if(clearAllowed == (boolean)TRUE)
			{
				/**
				 * @req [SWS_Dem_00385] After a clear command has been applied to a specific DTC the
				 *      Dem module shall set the UDS status byte to 0x50 (Readiness bits 4 and 6 set
				 *      to 1, and all others are set to zero).
				 */
				Dem_EventUDSBitStatus[InternalId] = 0x50u;
			}
			else
			{
				/**
				 * @req [SWS_Dem_00667] If the out-parameter Allowed of the callback ClearEventAllowed
				 *      returns "false" (and the return value is equal to E_OK) after the execution of
				 *      this callback function, the respective event memory entry and Dem-internal data
				 *      values must not be cleared.
				 */
				clearCommand = (boolean)FALSE;

				if(pEventPara->DemCallbackClearEventAllowed->DemClearEventAllowedBehavior \
						== DEM_ONLY_THIS_CYCLE_AND_READINESS)
				{
					/**
					 * @req [SWS_Dem_00669] If the out-parameter 'Allowed' of the callback ClearEvent-
					 *      Allowed returns 'false' and the configuration parameter DemClearEventAllow-
					 *      edBehavior is set to DEM_ONLY_THIS_CYCLE_AND_READINESS, the related event
					 *      status bits 1,4,5 and 6 shall be reset.
					 */
					Dem_Disable_UdsStatusBits(InternalId,DEM_UDS_STATUS_TFTOC);
					Dem_Disable_UdsStatusBits(InternalId,DEM_UDS_STATUS_TFSLC);
					Dem_Enable_UdsStatusBits(InternalId,DEM_UDS_STATUS_TNCSLC);
					Dem_Enable_UdsStatusBits(InternalId,DEM_UDS_STATUS_TNCTOC);
				}
				else
				{
					/**
					 * @req [SWS_Dem_00668] If the out-parameter 'Allowed' of the callback ClearEvent-
					 *      Allowed returns 'false' and the configuration parameter DemClearEventAllo-
					 *      wedBehavior is set to DEM_NO_STATUS_BYTE_CHANGE, the related event status
					 *      byte shall not be modified.
					 */
				}
			}
		}
		else
		{
			/**
			 * @req [SWS_Dem_00516] If the return value of the callback ClearEventAllowed is equal to
			 *      E_NOT_OK, the return value shall not be changed and event-deletion is allowed.
			 *
			 * @req [SWS_Dem_00385] After a clear command has been applied to a specific DTC the Dem
			 *      module shall set the UDS status byte to 0x50 (Readiness bits 4 and 6 set to 1,and
			 *      all others are set to zero).
			 */
			Dem_EventUDSBitStatus[InternalId] = 0x50u;
		}
	}
	else
	{
#endif /* #if(DEM_CALLBACK_CLEAR_EVENT_ALLOWED_NUM > 0) */
		/**
		 * @req [SWS_Dem_00385] After a clear command has been applied to a specific DTC the
		 *      Dem module shall set the UDS status byte to 0x50 (Readiness bits 4 and 6 set
		 *      to 1, and all others are set to zero).
		 */
		Dem_EventUDSBitStatus[InternalId] = 0x50u;

#if(DEM_CALLBACK_CLEAR_EVENT_ALLOWED_NUM > 0)
	}
#endif /* #if(DEM_CALLBACK_CLEAR_EVENT_ALLOWED_NUM > 0) */

	Dem_SetCombineDtcStatus(InternalId);

#if(DEM_CALLBACK_CLEAR_EVENT_ALLOWED_NUM > 0)
	if(clearCommand == (boolean)TRUE)
	{
#endif /* #if(DEM_CALLBACK_CLEAR_EVENT_ALLOWED_NUM > 0) */
		/**
		 * @req [SWS_Dem_00343] After receiving a command for clearing the event memory ,the Dem
		 *      internal debounce algorithm shall be reset,presuming event debouncing is handled
		 *      Dem internally.
		 */
		Dem_DebounceReset(InternalId,(boolean)TRUE);

		if(u16DtcRef != 0xFFFFu)
		{
			/**
			 * @req [SWS_Dem_00794] The maximum FDC since last clear shall be reset to zero with each
			 *      clear DTC command affecting this particular event.
			 */
			Dem_MaxFDCSinceLastClear[u16DtcRef] = 0u;
		}
#if (DEM_DTR_NUM > 0)
		/**
		 * @req [SWS_Dem_00763] The Dem shall reset the DTR data using the reference to the Event
		 *      per DTR, whenever the Event is affected by a fault clear command.
		 */
#endif /* #if (DEM_DTR_NUM > 0) */
#if(DEM_CALLBACK_CLEAR_EVENT_ALLOWED_NUM > 0)
	}
#endif /* #if(DEM_CALLBACK_CLEAR_EVENT_ALLOWED_NUM > 0) */
	return ret;
}
#endif /* #if(DEM_DTC_NUM > 0) */

#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

#ifdef __cplusplus
}
#endif
/** @} */
