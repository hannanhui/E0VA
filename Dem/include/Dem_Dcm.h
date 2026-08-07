/**
 * @file        Dem_Dcm.h
 * @brief       AUTOSAR Dem - Dem module header file.
 * @details     Dem module header file, containing the Autosar API specification and
 *              functions that are provided to Dcm.
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

#ifndef DEM_DCM_H
#define DEM_DCM_H

#ifdef __cplusplus
extern "C"{
#endif

/*====================================================================================================*
 *                                           INCLUDE FILES
 *====================================================================================================*/

#include "Dem_Types.h"
#if(DEM_DCM_ENABLE == STD_ON)
#include "Dcm_Types.h"
#endif /* #if(DEM_DCM_ENABLE == STD_ON) */

/*====================================================================================================*
 *                                  HEADER FILE VERSION INFORMATION
 *====================================================================================================*/

#define DEM_DCM_VENDOR_ID             					(0U)
#define DEM_DCM_AR_RELEASE_MAJOR_VERSION      			(4U)
#define DEM_DCM_AR_RELEASE_MINOR_VERSION      			(2U)
#define DEM_DCM_AR_RELEASE_REVISION_VERSION      		(2U)
#define DEM_DCM_SW_MAJOR_VERSION      					(1U)
#define DEM_DCM_SW_MINOR_VERSION      					(2U)
#define DEM_DCM_SW_PATCH_VERSION      					(0U)

/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/
/* Check if current file and Dem_Types.h header file are of the same vendor */
#if(DEM_DCM_VENDOR_ID != DEM_TYPES_VENDOR_ID )
#error "Dem_Dcm.h and Dem_Types.h have different vendor id"
#endif /* #if(DEM_DCM_VENDOR_ID != DEM_TYPES_VENDOR_ID ) */

/* Check if current file and Dem_Types.h header file are of the same Autosar version */
#if(\
		(DEM_DCM_AR_RELEASE_MAJOR_VERSION != DEM_TYPES_AR_RELEASE_MAJOR_VERSION) || \
		(DEM_DCM_AR_RELEASE_MINOR_VERSION != DEM_TYPES_AR_RELEASE_MINOR_VERSION) || \
		(DEM_DCM_AR_RELEASE_REVISION_VERSION != DEM_TYPES_AR_RELEASE_REVISION_VERSION) \
   )
#error "AutoSar Version Number of Dem_Dcm.h and Dem_Types.h are different "
#endif /* #if(\
				(DEM_DCM_AR_RELEASE_MAJOR_VERSION != DEM_TYPES_AR_RELEASE_MAJOR_VERSION) || \
				(DEM_DCM_AR_RELEASE_MINOR_VERSION != DEM_TYPES_AR_RELEASE_MINOR_VERSION) || \
				(DEM_DCM_AR_RELEASE_REVISION_VERSION != DEM_TYPES_AR_RELEASE_REVISION_VERSION) \
   	   	     ) */

/* Check if current file and Dem_Types.h header file are of the same Software version */
#if(\
		(DEM_DCM_SW_MAJOR_VERSION != DEM_TYPES_SW_MAJOR_VERSION) || \
		(DEM_DCM_SW_MINOR_VERSION != DEM_TYPES_SW_MINOR_VERSION) || \
		(DEM_DCM_SW_PATCH_VERSION != DEM_TYPES_SW_PATCH_VERSION) \
   )
#error "Software Version Number of Dem_Dcm.h and Dem_Types.h are different "
#endif /* #if(\
				(DEM_DCM_SW_MAJOR_VERSION != DEM_TYPES_SW_MAJOR_VERSION) || \
				(DEM_DCM_SW_MINOR_VERSION != DEM_TYPES_SW_MINOR_VERSION) || \
				(DEM_DCM_SW_PATCH_VERSION != DEM_TYPES_SW_PATCH_VERSION) \
   	   	   	 ) */


#ifndef DISABLE_INTERMOD_VERSION_CHECK

#if(DEM_DCM_ENABLE == STD_ON)
/* Check if current file and Dcm_Types.h header file are of the same Autosar version */
#if(\
		(DEM_DCM_AR_RELEASE_MAJOR_VERSION != DCM_TYPES_AR_RELEASE_MAJOR_VERSION) || \
		(DEM_DCM_AR_RELEASE_MINOR_VERSION != DCM_TYPES_AR_RELEASE_MINOR_VERSION) \
   )
#error "AutoSar Version Number of Dem_Dcm.h and Dcm_Types.h are different "
#endif /* #if(\
				(DEM_DCM_AR_RELEASE_MAJOR_VERSION != DCM_TYPES_AR_RELEASE_MAJOR_VERSION) || \
				(DEM_DCM_AR_RELEASE_MINOR_VERSION != DCM_TYPES_AR_RELEASE_MINOR_VERSION) \
   	   	     ) */

#endif /* #if(DEM_DCM_ENABLE == STD_ON) */
#endif /* #ifndef DISABLE_INTERMOD_VERSION_CHECK */

#if(DEM_DCM_ENABLE == STD_ON)
/*====================================================================================================*
 *                                             CONSTANTS
 *====================================================================================================*/

/* Add code here */

/*====================================================================================================*
 *                                         DEFINES AND MACROS
 *====================================================================================================*/

/* Add code here */

/*====================================================================================================*
 *                                               ENUMS
 *====================================================================================================*/

/* Add code here */

/*====================================================================================================*
 *                                   STRUCTURES AND OTHER TYPEDEFS
 *====================================================================================================*/

/* Add code here */

/*====================================================================================================*
 *                                    GLOBAL VARIABLE DECLARATIONS
 *====================================================================================================*/

#if(DEM_CLEAR_DTC_BEHAVIOR != DEM_CLRRESP_VOLATILE)
#if(DEM_NVRAM_BLOCKID_NUM > 0)
extern VAR(boolean,DEM_VAR) Dem_NvMPending;
#endif /* #if(DEM_NVRAM_BLOCKID_NUM > 0) */
#endif /* #if(DEM_CLEAR_DTC_BEHAVIOR != DEM_CLRRESP_VOLATILE) */

/*====================================================================================================*
 *                                        FUNCTION PROTOTYPES
 *====================================================================================================*/
FUNC(Dem_DTCTranslationFormatType, DEM_CODE)Dem_DcmGetTranslationType
(
	void
);

FUNC(Std_ReturnType, DEM_CODE)Dem_DcmGetDTCStatusAvailabilityMask
(
	P2VAR(Dem_UdsStatusByteType, AUTOMATIC, DEM_CODE) pDTCStatusMask
);

FUNC(Dem_ReturnGetStatusOfDTCType, DEM_CODE) Dem_DcmGetStatusOfDTC
(
    uint32 DTC,
    Dem_DTCOriginType DTCOrigin,
    P2VAR(uint8, AUTOMATIC, DEM_CODE) pDTCStatus
);

FUNC(Dem_ReturnGetSeverityOfDTCType, DEM_CODE) Dem_DcmGetSeverityOfDTC
(
    uint32 DTC,
    P2VAR(Dem_DTCSeverityType, AUTOMATIC, DEM_CODE) pDTCSeverity
);

FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetDTCSeverityAvailabilityMask
(
    P2VAR(Dem_DTCSeverityType, AUTOMATIC, DEM_CODE) DTCSeverityMask
);

FUNC(Dem_ReturnGetFunctionalUnitOfDTCType, DEM_CODE) Dem_DcmGetFunctionalUnitOfDTC
(
    uint32 DTC,
    P2VAR(uint8, AUTOMATIC, DEM_CODE) pDTCFunctionalUnit
);

FUNC(Dem_ReturnSetFilterType, DEM_CODE) Dem_DcmSetDTCFilter
(
    Dem_UdsStatusByteType DTCStatusMask,
    Dem_DTCKindType DTCKind,
    Dem_DTCFormatType DTCFormat,
    Dem_DTCOriginType DTCOrigin,
    boolean FilterWithSeverity,
    Dem_DTCSeverityType DTCSeverityMask,
    boolean FilterForFaultDetectionCounter
);

FUNC(Dem_ReturnGetNumberOfFilteredDTCType,DEM_CODE)Dem_DcmGetNumberOfFilteredDTC
(
	P2VAR(uint16, AUTOMATIC, DEM_CODE) pNumberOfFilteredDTC
);

FUNC(Dem_ReturnGetNextFilteredElementType, DEM_CODE)Dem_DcmGetNextFilteredDTC
(
	P2VAR(uint32, AUTOMATIC, DEM_CODE) pDTC,
	P2VAR(Dem_UdsStatusByteType, AUTOMATIC, DEM_CODE) pDTCStatus
);

FUNC(Dem_ReturnGetNextFilteredElementType, DEM_CODE)Dem_DcmGetNextFilteredDTCAndFDC
(
	P2VAR(uint32, AUTOMATIC, DEM_CODE) pDTC,
	P2VAR(sint8, AUTOMATIC, DEM_CODE) pDTCFaultDetectionCounter
);

FUNC(Dem_ReturnGetNextFilteredElementType, DEM_CODE)Dem_DcmGetNextFilteredDTCAndSeverity
(
	P2VAR(uint32, AUTOMATIC, DEM_CODE) pDTC,
	P2VAR(Dem_UdsStatusByteType, AUTOMATIC, DEM_CODE) pDTCStatus,
	P2VAR(Dem_DTCSeverityType, AUTOMATIC, DEM_CODE) pDTCSeverity,
	P2VAR(uint8, AUTOMATIC, DEM_CODE) pDTCFunctionalUnit
);

FUNC(Dem_ReturnSetFilterType, DEM_CODE)Dem_DcmSetFreezeFrameRecordFilter
(
    Dem_DTCFormatType DTCFormat,
    P2VAR(uint16, AUTOMATIC, DEM_CODE) pNumberOfFilteredRecords
);

FUNC(Dem_ReturnGetNextFilteredElementType, DEM_CODE)Dem_DcmGetNextFilteredRecord
(
	P2VAR(uint32, AUTOMATIC, DEM_CODE) pDTC,
	P2VAR(uint8, AUTOMATIC, DEM_CODE) pRecordNumber
);

FUNC(Dem_ReturnGetDTCByOccurrenceTimeType, DEM_CODE)Dem_DcmGetDTCByOccurrenceTime
(
    Dem_DTCRequestType DTCRequest,
    P2VAR(uint32, AUTOMATIC, DEM_CODE) pDTC
);

FUNC(void, DEM_CODE) Dem_DcmControlDTCStatusChangedNotification
(
    boolean TriggerNotification
);

FUNC(Dem_ReturnDisableDTCRecordUpdateType, DEM_CODE)Dem_DcmDisableDTCRecordUpdate
(
    uint32 DTC,
    Dem_DTCOriginType DTCOrigin
);

FUNC(Std_ReturnType, DEM_CODE) Dem_DcmEnableDTCRecordUpdate
(
	void
);

FUNC(Dem_ReturnGetFreezeFrameDataByDTCType, DEM_CODE)Dem_DcmGetFreezeFrameDataByDTC
(
    uint32 DTC,
    Dem_DTCOriginType DTCOrigin,
    uint8 RecordNumber,
    P2VAR(uint8, AUTOMATIC, DEM_CODE) pDestBuffer,
	P2VAR(uint16, AUTOMATIC, DEM_CODE) pBufSize
);

FUNC(Dem_ReturnGetSizeOfDataByDTCType, DEM_CODE)Dem_DcmGetSizeOfFreezeFrameByDTC
(
    uint32 DTC,
    Dem_DTCOriginType DTCOrigin,
    uint8 RecordNumber,
    P2VAR(uint16,AUTOMATIC,DEM_CODE) pSizeOfFreezeFrame
);

FUNC(Dem_ReturnGetExtendedDataRecordByDTCType, DEM_CODE)Dem_DcmGetExtendedDataRecordByDTC
(
    uint32 DTC,
    Dem_DTCOriginType DTCOrigin,
    uint8 ExtendedDataNumber,
    P2VAR(uint8, AUTOMATIC, DEM_CODE) pDestBuffer,
	P2VAR(uint16, AUTOMATIC, DEM_CODE) pBufSize
);

FUNC(Dem_ReturnGetSizeOfDataByDTCType, DEM_CODE)Dem_DcmGetSizeOfExtendedDataRecordByDTC
(
    uint32 DTC,
    Dem_DTCOriginType DTCOrigin,
    uint8 ExtendedDataNumber,
    P2VAR(uint16, AUTOMATIC, DEM_CODE) pSizeOfExtendedDataRecord
);

FUNC(Dem_ReturnClearDTCType, DEM_CODE)Dem_DcmCheckClearParameter
(
	uint32 DTC,
    Dem_DTCFormatType DTCFormat,
    Dem_DTCOriginType DTCOrigin
);

FUNC(Dem_ReturnControlDTCSettingType, DEM_CODE)Dem_DcmDisableDTCSetting
(
    uint32 DTCGroup,
    Dem_DTCKindType DTCKind
);


#endif /* #if(DEM_DCM_ENABLE == STD_ON) */

#ifdef __cplusplus
}
#endif

#endif /* DEM_DCM_H */
/** @} */
