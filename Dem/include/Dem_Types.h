/**
 * @file        Dem_Types.h
 * @brief       AUTOSAR Dem - Dem module header file.
 * @details     Dem module header file, containing the types definitions that are
 *              needed by the Dem module.
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

#ifndef DEM_TYPES_H
#define DEM_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif
/* PRQA S 0779 EOF #
 *
 *1.0779 -- Violates MISRA 2004 Required Rule 1.2,Identifier does not differ from other identifier(s)
 * within the specified number of significant characters.
 *
 *2.0779 -- Violates MISRA 2004 Required Rule 5.1,Identifier does not differ from other identifier(s)
 * within the specified number of significant characters.
 *
 * does not conform strictly to ISO:C90.
 *
 * @page misra_violations MISRA-C:2004 violations
 */

/*====================================================================================================*
 *                                           INCLUDE FILES
 *====================================================================================================*/
#include "Std_Types.h"
#include "Dem_Cfg.h"
#include "Rte_Dem_Type.h"

/*====================================================================================================*
 *                                  HEADER FILE VERSION INFORMATION
 *====================================================================================================*/
#define DEM_TYPES_VENDOR_ID             					(0U)
#define DEM_TYPES_AR_RELEASE_MAJOR_VERSION      			(4U)
#define DEM_TYPES_AR_RELEASE_MINOR_VERSION      			(2U)
#define DEM_TYPES_AR_RELEASE_REVISION_VERSION      			(2U)
#define DEM_TYPES_SW_MAJOR_VERSION      					(1U)
#define DEM_TYPES_SW_MINOR_VERSION      					(2U)
#define DEM_TYPES_SW_PATCH_VERSION      					(0U)

/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/
/* Check if current file and Dem_Cfg.h header file are of the same vendor */
#if(DEM_TYPES_VENDOR_ID != DEM_CFG_VENDOR_ID )
#error "Dem_Types.h and Dem_Cfg.h have different vendor id"
#endif /* #if(DEM_TYPES_VENDOR_ID != DEM_CFG_VENDOR_ID ) */

/* Check if current file and Dem_Cfg.h header file are of the same Autosar version */
#if(\
		(DEM_TYPES_AR_RELEASE_MAJOR_VERSION != DEM_CFG_AR_RELEASE_MAJOR_VERSION) || \
		(DEM_TYPES_AR_RELEASE_MINOR_VERSION != DEM_CFG_AR_RELEASE_MINOR_VERSION) || \
		(DEM_TYPES_AR_RELEASE_REVISION_VERSION != DEM_CFG_AR_RELEASE_REVISION_VERSION) \
   )
#error "AutoSar Version Number of Dem_Types.h and Dem_Cfg.h are different "
#endif /* #if(\
				(DEM_TYPES_AR_RELEASE_MAJOR_VERSION != DEM_CFG_AR_RELEASE_MAJOR_VERSION) || \
				(DEM_TYPES_AR_RELEASE_MINOR_VERSION != DEM_CFG_AR_RELEASE_MINOR_VERSION) || \
				(DEM_TYPES_AR_RELEASE_REVISION_VERSION != DEM_CFG_AR_RELEASE_REVISION_VERSION) \
   	   	     ) */

/* Check if current file and Dem_Cfg.h header file are of the same Software version */
#if(\
		(DEM_TYPES_SW_MAJOR_VERSION != DEM_CFG_SW_MAJOR_VERSION) || \
		(DEM_TYPES_SW_MINOR_VERSION != DEM_CFG_SW_MINOR_VERSION) || \
		(DEM_TYPES_SW_PATCH_VERSION != DEM_CFG_SW_PATCH_VERSION) \
   )
#error "Software Version Number of Dem_Types.h and Dem_Cfg.h are different "
#endif /* #if(\
				(DEM_TYPES_SW_MAJOR_VERSION != DEM_CFG_SW_MAJOR_VERSION) || \
				(DEM_TYPES_SW_MINOR_VERSION != DEM_CFG_SW_MINOR_VERSION) || \
				(DEM_TYPES_SW_PATCH_VERSION != DEM_CFG_SW_PATCH_VERSION) \
   	   	   	 ) */

#ifndef DISABLE_INTERMOD_VERSION_CHECK
/* Check if current file and Std_Types.h header file are of the same Autosar version */
#if(\
		(DEM_TYPES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
		(DEM_TYPES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION) \
   )
#error "AutoSar Version Number of Dem_Types.h and Std_Types.h are different "
#endif /* #if(\
				(DEM_TYPES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
				(DEM_TYPES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION) \
   	   	     ) */

/* Check if current file and Rte_Dem_Type.h header file are of the same Autosar version */
#if(\
		(DEM_TYPES_AR_RELEASE_MAJOR_VERSION != RTE_DEM_TYPE_AR_RELEASE_MAJOR_VERSION) || \
		(DEM_TYPES_AR_RELEASE_MINOR_VERSION != RTE_DEM_TYPE_AR_RELEASE_MINOR_VERSION) \
   )
#error "AutoSar Version Number of Dem_Types.h and Rte_Dem_Type.h are different "
#endif /* #if(\
				(DEM_TYPES_AR_RELEASE_MAJOR_VERSION != RTE_DEM_TYPE_AR_RELEASE_MAJOR_VERSION) || \
				(DEM_TYPES_AR_RELEASE_MINOR_VERSION != RTE_DEM_TYPE_AR_RELEASE_MINOR_VERSION) \
   	   	     ) */
#endif /* #ifndef DISABLE_INTERMOD_VERSION_CHECK */
/*====================================================================================================*
 *                                             CONSTANTS
 *====================================================================================================*/

/* Add code here */

/*====================================================================================================*
 *                                         DEFINES AND MACROS
 *====================================================================================================*/
/**
 * @req [SWS_Dem_00173]
 */
#define DEM_E_NO_DTC_AVAILABLE                          ((Std_ReturnType)0x02u)
#define DEM_E_NO_FDC_AVAILABLE                          ((Std_ReturnType)0x03u)
#define DEM_E_WRONG_BUFFERSIZE                       	((Std_ReturnType)0x15u)
#define DEM_E_WRONG_CONFIGURATION                    	((uint8)0x10u)
#define DEM_E_PARAM_POINTER                          	((uint8)0x11u)
#define DEM_E_PARAM_DATA                             	((uint8)0x12u)
#define DEM_E_PARAM_LENGTH                           	((uint8)0x13u)
#define DEM_E_INIT_FAILED                           	((uint8)0x14u)
#define DEM_E_UNINIT                                	((uint8)0x20u)
#define DEM_E_NODATAAVAILABLE                        	((uint8)0x30u)
#define DEM_E_WRONG_RECORDNUMBER                     	((uint8)0x31u)
#define DEM_E_WRONG_DIDNUMBER                        	((uint8)0x32u)
#define DEM_E_WRONG_CONDITION                        	((uint8)0x40u)

/* Service ID */
#define DEM_SID_GETVERSIONINFO                       	((uint8)0x00u)
#define DEM_SID_PREINIT                              	((uint8)0x01u)
#define DEM_SID_INIT                                 	((uint8)0x02u)
#define DEM_SID_SHUTDOWN                             	((uint8)0x03u)
#define DEM_SID_REPORTERRORSTATUS                    	((uint8)0x0fu)
#define DEM_SID_SETEVENTAVAILABLE                    	((uint8)0x37u)
#define DEM_SID_SETEVENTSTATUS                       	((uint8)0x04u)
#define DEM_SID_RESETEVENTDEBOUNCESTATUS             	((uint8)0x09u)
#define DEM_SID_RESETEVENTSTATUS                    	((uint8)0x05u)
#define DEM_SID_PRESTOREFREEZEFRAME                  	((uint8)0x06u)
#define DEM_SID_CLEARPRESTOREDFREEZEFRAME            	((uint8)0x07u)
#define DEM_SID_SETOPERATIONCYCLESTATE               	((uint8)0x08u)
#define DEM_SID_GETOPERATIONCYCLESTATE               	((uint8)0x9eu)
#define DEM_SID_SETAGINGCYCLESTATE                   	((uint8)0x11u)
#define DEM_SID_SETWIRSTATUS                        	((uint8)0x7au)
#define DEM_SID_GETCOMPONENTFAILED                   	((uint8)0x2au)
#define DEM_SID_GETEVENTSTATUS                       	((uint8)0x0au)
#define DEM_SID_GETEVENTFAILED                       	((uint8)0x0bu)
#define DEM_SID_GETEVENTTESTED                       	((uint8)0x0cu)
#define DEM_SID_GETDEBOUNCINGOFEVENT                 	((uint8)0x9fu)
#define DEM_SID_GETDTCOFEVENT                        	((uint8)0x0du)
#define DEM_SID_SETENABLECONDITION                   	((uint8)0x39u)
#define DEM_SID_SETSTORAGECONDITION                  	((uint8)0x38u)
#define DEM_SID_GETFAULTDETECTIONCOUNTER            	((uint8)0x3eu)
#define DEM_SID_GETINDICATORSTATUS                   	((uint8)0x29u)
#define DEM_SID_SETINDICATORSTATUS                   	((uint8)0xa1u)
#define DEM_SID_GETEVENTFREEZEFRAMEDATAEX           	((uint8)0x6eu)
#define DEM_SID_GETEVENTEXTENDEDDATARECORDEX         	((uint8)0x6du)
#define DEM_SID_GETEVENTMEMORYOVERFLOW               	((uint8)0x32u)
#define DEM_SID_GETNUMBEROFEVENTMEMORYENTRIES        	((uint8)0x35u)
#define DEM_SID_SETCOMPONENTAVAILABLE                	((uint8)0x2bu)
#define DEM_SID_SETDTCSUPPRESSION                   	((uint8)0x33u)
#define DEM_SID_CLEARDTC                           		((uint8)0x23u)
#define DEM_SID_MAINFUNCTION                         	((uint8)0x55u)
#define DEM_SID_DCMGETTRANSLATIONTYPE                   ((uint8)0x3cu)
#define DEM_SID_DCMGETDTCSTATUSAVAILABILITYMASK         ((uint8)0x16u)
#define DEM_SID_DCMGETSTATUSOFDTC                       ((uint8)0x15u)
#define DEM_SID_DCMGETSEVERITYOFDTC                     ((uint8)0x0eu)
#define DEM_SID_DCMGETFUNCTIONALUNITOFDTC               ((uint8)0x34u)
#define DEM_SID_DCMSETDTCFILTER                         ((uint8)0x13u)
#define DEM_SID_DCMGETNUMBEROFFILTEREDDTC               ((uint8)0x17u)
#define DEM_SID_DCMGETNEXTFILTEREDDTC                   ((uint8)0x18u)
#define DEM_SID_DCMGETNEXTFILTEREDDTCANDFDC             ((uint8)0x3bu)
#define DEM_SID_DCMGETNEXTFILTEREDDTCANDSEVERITY        ((uint8)0x3du)
#define DEM_SID_DCMSETFREEZEFRAMERECORDFILTER           ((uint8)0x3fu)
#define DEM_SID_DCMGETNEXTFILTEREDRECORD                ((uint8)0x3au)
#define DEM_SID_DCMGETDTCBYOCCURRENCETIME               ((uint8)0x19u)
#define DEM_SID_DCMCONTROLDTCSTATUSCHANGEDNOTIFICATION  ((uint8)0xb0u)
#define DEM_SID_DCMDISABLEDTCRECORDUPDATE               ((uint8)0x1au)
#define DEM_SID_DCMENABLEDTCRECORDUPDATE                ((uint8)0x1bu)
#define DEM_SID_DCMGETFREEZEFRAMEDATABYDTC              ((uint8)0x1du)
#define DEM_SID_DCMGETSIZEOFFREEZEFRAMEBYDTC            ((uint8)0x1fu)
#define DEM_SID_DCMGETEXTENDEDDATARECORDBYDTC           ((uint8)0x20u)
#define DEM_SID_DCMGETSIZEOFEXTENDEDDATARECORDBYDTC     ((uint8)0x21u)
#define DEM_SID_DCMCHECKCLEARPARAMETER                  ((uint8)0x7bu)
#define DEM_SID_DCMCLEARDTC                             ((uint8)0x22u)
#define DEM_SID_DCMDISABLEDTCSETTING                    ((uint8)0x24u)
#define DEM_SID_DCMENABLEDTCSETTING                     ((uint8)0x25u)
#define DEM_SID_DCMGETINFOTYPEVALUE08                   ((uint8)0x6bu)
#define DEM_SID_DCMGETINFOTYPEVALUE0B                   ((uint8)0x6cu)
#define DEM_SID_DCMREADDATDOFPID01                      ((uint8)0x61u)
#define DEM_SID_DCMREADDATDOFPID1C                      ((uint8)0x63u)
#define DEM_SID_DCMREADDATDOFPID21                      ((uint8)0x64u)
#define DEM_SID_DCMREADDATDOFPID30                      ((uint8)0x65u)
#define DEM_SID_DCMREADDATDOFPID31                      ((uint8)0x66u)
#define DEM_SID_DCMREADDATDOFPID41                      ((uint8)0x67u)
#define DEM_SID_DCMREADDATDOFPID4D                      ((uint8)0x68u)
#define DEM_SID_DCMREADDATDOFPID4E                      ((uint8)0x69u)
#define DEM_SID_DCMREADDATDOFPID91                      ((uint8)0x6Au)
#define DEM_SID_DCMREADDATAOFOBDFREEZEFRAME             ((uint8)0x52u)
#define DEM_SID_DCMGETDTCOFOBDFREEZEFRAME               ((uint8)0x53u)
#define DEM_SID_DCMGETAVAILABLEOBDMIDS                  ((uint8)0xa3u)
#define DEM_SID_DCMGETNUMTIDSOFOBDMID                   ((uint8)0xa4u)
#define DEM_SID_DCMGETDTRDATA                           ((uint8)0xa5u)
#define DEM_SID_J1939DCMSETDTCFILTER                    ((uint8)0x90u)
#define DEM_SID_J1939DCMGETNUMBEROFFILTEREDDTC          ((uint8)0x91u)
#define DEM_SID_J1939DCMGETNEXTFILTEREDDTC              ((uint8)0x92u)
#define DEM_SID_J1939DCMFIRSTDTCWITHLAMPSTATUS          ((uint8)0x93u)
#define DEM_SID_J1939DCMGETNEXTDTCWITHLAMPSTATUS        ((uint8)0x94u)
#define DEM_SID_J1939DCMCLEARDTC                        ((uint8)0x95u)
#define DEM_SID_J1939DCMSETFREEZEFRAMEFILTER            ((uint8)0x96u)
#define DEM_SID_J1939DCMGETNEXTFREEZEFRAME              ((uint8)0x97u)
#define DEM_SID_J1939DCMGETNEXTSPNINFREEZEFRAME         ((uint8)0x98u)
#define DEM_SID_J1939DCMSETRATIOFILTER                  ((uint8)0x99u)
#define DEM_SID_J1939DCMGETNEXTFILTEREDRATIO            ((uint8)0x9au)
#define DEM_SID_J1939DCMREADDIAGNOSTICREADINESS1        ((uint8)0x9bu)
#define DEM_SID_J1939DCMREADDIAGNOSTICREADINESS2        ((uint8)0x9cu)
#define DEM_SID_J1939DCMREADDIAGNOSTICREADINESS3        ((uint8)0x9du)
#define DEM_SID_DLTGETMOSTRECENTFREEZEFRAMERECORDDATA   ((uint8)0x41u)
#define DEM_SID_DLTGETALLEXTENDEDDATARECORDS            ((uint8)0x40u)
#define DEM_SID_SETEVENTDISABLED                        ((uint8)0x51u)
#define DEM_SID_REPIUMPRFAULTDETECT                     ((uint8)0x73u)
#define DEM_SID_SETIUMPRDENCONDITION                    ((uint8)0xaeu)
#define DEM_SID_GETIUMPRDENCONDITION                    ((uint8)0xafu)
#define DEM_SID_REPIUMPRDENLOCK                         ((uint8)0x71u)
#define DEM_SID_REPIUMPRDENRELEASE                      ((uint8)0x72u)
#define DEM_SID_SETPTOSTATUS                            ((uint8)0x79u)
#define DEM_SID_READDATAOFPID01                         ((uint8)0xb3u)
#define DEM_SID_GETDATAOFPID21                          ((uint8)0xb1u)
#define DEM_SID_SETDATAOFPID21                          ((uint8)0xa6u)
#define DEM_SID_SETDATAOFPID31                          ((uint8)0xa7u)
#define DEM_SID_SETDATAOFPID4D                          ((uint8)0xa8u)
#define DEM_SID_SETDATAOFPID4E                          ((uint8)0xa9u)
#define DEM_SID_SETPFCCYCLEQUALIFIED                    ((uint8)0xaau)
#define DEM_SID_GETPFCCYCLEQUALIFIED                    ((uint8)0xabu)
#define DEM_SID_SETCLEARDTC                             ((uint8)0xacu)
#define DEM_SID_DCMGETDTCSEVERITYAVAILABILITYMASK       ((uint8)0xb2u)
#define DEM_SID_GETB1COUNTER                            ((uint8)0xb4u)
#define DEM_SID_SETDTR                                  ((uint8)0xa2u)

/**
 * @req [SWS_Dem_01114] Identification of a DemComponent by assigned
 *      ComponentId.The ComponentId is automatically assigned by the Dem.
 */
#if(DEM_COMPONENT_NUM > 65535)
typedef	uint32 		Dem_ComponentIdType;
#elif(DEM_COMPONENT_NUM > 255)
typedef uint16		Dem_ComponentIdType;
#else
typedef uint8		Dem_ComponentIdType;
#endif

/**
 * @req [SWS_Dem_00925] Identification of an event by assigned EventId.
 */
typedef	uint16 		Dem_EventIdType;

/**
 * @req [SWS_Dem_00926] This type contains all monitor test result values, which
 *      can be reported via Dem_ReportErrorStatus() and Dem_SetEventStatus().
 */
typedef uint8		Dem_EventStatusType;
#define DEM_EVENT_STATUS_PASSED                       ((Dem_EventStatusType)0x00u)
#define DEM_EVENT_STATUS_FAILED                       ((Dem_EventStatusType)0x01u)
#define DEM_EVENT_STATUS_PREPASSED                    ((Dem_EventStatusType)0x02u)
#define DEM_EVENT_STATUS_PREFAILED                    ((Dem_EventStatusType)0x03u)
#define DEM_EVENT_STATUS_FDC_THRESHOLD_REACHED        ((Dem_EventStatusType)0x04u)

/**
 * @req [SWS_Dem_01000]
 */
typedef uint8		Dem_DebouncingStateType;
#define DEM_TEMPORARILY_DEFECTIVE                     ((Dem_DebouncingStateType)0x01u)
#define DEM_FINALLY_DEFECTIVE                         ((Dem_DebouncingStateType)0x02u)
#define DEM_TEMPORARILY_HEALED                        ((Dem_DebouncingStateType)0x04u)
#define DEM_TEST_COMPLETE                             ((Dem_DebouncingStateType)0x08u)
#define DEM_DTR_UPDATE                                ((Dem_DebouncingStateType)0x10u)

/**
 * @req [SWS_Dem_00927] This type contains all definitions to control an internal
 *      debounce counter/timer via the function Dem_ResetEventDebounceStatus().
 */
typedef uint8 		Dem_DebounceResetStatusType;
#define DEM_DEBOUNCE_STATUS_FREEZE                    ((Dem_DebounceResetStatusType)0x00u)
#define DEM_DEBOUNCE_STATUS_RESET                     ((Dem_DebounceResetStatusType)0x01u)

/**
 * @req [SWS_Dem_00928] In this data-type each bit has an individual meaning. The
 *      bit is set to 1 when the condition holds.For example,if the 2nd bit (0x02)
 *      is set to 1, this means that the test failed this operation cycle. If the
 *      bit is set to 0, it has not yet failed this cycle.
 */
typedef uint8 		Dem_UdsStatusByteType;
#define DEM_UDS_STATUS_TF                             ((Dem_UdsStatusByteType)0x01u)
#define DEM_UDS_STATUS_TFTOC                          ((Dem_UdsStatusByteType)0x02u)
#define DEM_UDS_STATUS_PDTC                           ((Dem_UdsStatusByteType)0x04u)
#define DEM_UDS_STATUS_CDTC                           ((Dem_UdsStatusByteType)0x08u)
#define DEM_UDS_STATUS_TNCSLC                         ((Dem_UdsStatusByteType)0x10u)
#define DEM_UDS_STATUS_TFSLC                          ((Dem_UdsStatusByteType)0x20u)
#define DEM_UDS_STATUS_TNCTOC                         ((Dem_UdsStatusByteType)0x40u)
#define DEM_UDS_STATUS_WIR                            ((Dem_UdsStatusByteType)0x80u)

/**
 * @req [SWS_Dem_00929] This type contains operation cycle state values, which can
 *      be reported via Dem_SetOperationCycleState()/ Dem_GetOperationCycleState().
 */
typedef uint8 		Dem_OperationCycleStateType;
#define DEM_CYCLE_STATE_START                         ((Dem_OperationCycleStateType)0x00u)
#define DEM_CYCLE_STATE_END                           ((Dem_OperationCycleStateType)0x01u)

/**
 * @req [SWS_Dem_00930] Indicator mode used by Dem_GetIndicatorStatus().
 */
typedef uint8 		Dem_IndicatorBehaviourType;
typedef uint8 		Dem_IndicatorStatusType;
#define DEM_INDICATOR_OFF                             ((Dem_IndicatorStatusType)0x00u)
#define DEM_INDICATOR_CONTINUOUS                      ((Dem_IndicatorStatusType)0x01u)
#define DEM_INDICATOR_BLINKING                        ((Dem_IndicatorStatusType)0x02u)
#define DEM_INDICATOR_BLINK_CONT                      ((Dem_IndicatorStatusType)0x03u)
#define DEM_INDICATOR_SLOW_FLASH                      ((Dem_IndicatorStatusType)0x04u)
#define DEM_INDICATOR_FAST_FLASH                      ((Dem_IndicatorStatusType)0x05u)
#define DEM_INDICATOR_ON_DEMAND                       ((Dem_IndicatorStatusType)0x06u)
#define DEM_INDICATOR_SHORT                           ((Dem_IndicatorStatusType)0x07u)

/**
 * @req [SWS_Dem_00932] This type is used to filter DTCs for their kind.
 */
typedef uint8 		Dem_DTCKindType;
#define DEM_DTC_KIND_ALL_DTCS                         ((Dem_DTCKindType)0x01u)
#define DEM_DTC_KIND_EMISSION_REL_DTCS                ((Dem_DTCKindType)0x02u)

/**
 * @req [SWS_Dem_00933] This type is used to select the format of the DTC value.
 */
typedef uint8 		Dem_DTCFormatType;
#define DEM_DTC_FORMAT_OBD                            ((Dem_DTCFormatType)0x00u)
#define DEM_DTC_FORMAT_UDS                            ((Dem_DTCFormatType)0x01u)
#define DEM_DTC_FORMAT_J1939                          ((Dem_DTCFormatType)0x02u)

/**
 * @req [SWS_Dem_00934] This enum is used to define the location of the events.
 *      The definition and use of the different memory types is OEM-specific.
 */
typedef uint8 		Dem_DTCOriginType;
#define DEM_DTC_ORIGIN_PRIMARY_MEMORY                 ((Dem_DTCOriginType)0x01u)
#define DEM_DTC_ORIGIN_MIRROR_MEMORY                  ((Dem_DTCOriginType)0x02u)
#define DEM_DTC_ORIGIN_PERMANENT_MEMORY               ((Dem_DTCOriginType)0x03u)

/**
 * @req [SWS_Dem_00935] This type is used to request a DTC with specific attributes.
 */
typedef uint8 		Dem_DTCRequestType;
#define DEM_FIRST_FAILED_DTC                          ((Dem_DTCRequestType)0x01u)
#define DEM_MOST_RECENT_FAILED_DTC                    ((Dem_DTCRequestType)0x02u)
#define DEM_FIRST_DET_CONFIRMED_DTC                   ((Dem_DTCRequestType)0x03u)
#define DEM_MOST_REC_DET_CONFIRMED_DTC                ((Dem_DTCRequestType)0x04u)

/**
 * @req [SWS_Dem_00935] DTC translation format as defined in ISO14229-1 Service
 *      0x19 returned by Dem_DcmGetTranslationType().
 */
typedef uint8 		Dem_DTCTranslationFormatType;
#define DEM_DTC_TRANSLATION_ISO15031_6                ((Dem_DTCTranslationFormatType)0x00u)
#define DEM_DTC_TRANSLATION_ISO14229_1                ((Dem_DTCTranslationFormatType)0x01u)
#define DEM_DTC_TRANSLATION_SAEJ1939_73               ((Dem_DTCTranslationFormatType)0x02u)
#define DEM_DTC_TRANSLATION_ISO11992_4                ((Dem_DTCTranslationFormatType)0x03u)
#define DEM_DTC_TRANSLATION_SAE_J2012_DA_DTCFORMAT_04 ((Dem_DTCTranslationFormatType)0x04u)

/**
 * @req [SWS_Dem_00937] Type definition of DTCSeverityMask / DTCSeverity byte containing
 *      the DTC severity and DTC class information according to ISO 14229-1 Annex D.3.
 *      The upper 3 bits (bit 7-5) are used to represent the DTC severity information.
 *      The lower 5 bits (bit 4-0) are used to represent the DTC class information.
 */
typedef uint8 		Dem_DTCSeverityType;
#define DEM_SEVERITY_NO_SEVERITY                      ((Dem_DTCSeverityType)0x00u)
#define DEM_SEVERITY_WWHOBD_CLASS_NO_CLASS            ((Dem_DTCSeverityType)0x01u)
#define DEM_SEVERITY_WWHOBD_CLASS_A                   ((Dem_DTCSeverityType)0x02u)
#define DEM_SEVERITY_WWHOBD_CLASS_B1                  ((Dem_DTCSeverityType)0x04u)
#define DEM_SEVERITY_WWHOBD_CLASS_B2                  ((Dem_DTCSeverityType)0x08u)
#define DEM_SEVERITY_WWHOBD_CLASS_C                   ((Dem_DTCSeverityType)0x10u)
#define DTC_CLASS                                     ((Dem_DTCSeverityType)0x1fu)
#define DEM_SEVERITY_MAINTENANCE_ONLY                 ((Dem_DTCSeverityType)0x20u)
#define DEM_SEVERITY_CHECK_AT_NEXT_HALT               ((Dem_DTCSeverityType)0x40u)
#define DEM_SEVERITY_CHECK_IMMEDIATELY                ((Dem_DTCSeverityType)0x80u)

/**
 * @req [SWS_Dem_00940] OBD specific ratio Id (related to a specific event, a FID, and an IUMPR group).
 */
#if(DEM_RATIO_NUM > 255)
typedef uint16 		Dem_RatioIdType;
#else
typedef uint8 		Dem_RatioIdType;
#endif /* #if(DEM_RATIO_NUM > 255) */

/**
 * @req [SWS_Dem_00941] Control parameter for the interpretation of the reported test results.
 */
typedef uint8 		Dem_DTRControlType;
#define DEM_DTR_CTL_NORMAL                            ((Dem_DTRControlType)0x00u)
#define DEM_DTR_CTL_NO_MAX                            ((Dem_DTRControlType)0x01u)
#define DEM_DTR_CTL_NO_MIN                            ((Dem_DTRControlType)0x02u)
#define DEM_DTR_CTL_RESET                             ((Dem_DTRControlType)0x03u)
#define DEM_DTR_CTL_INVISIBLE                         ((Dem_DTRControlType)0x04u)

/**
 * @req [SWS_Dem_00941] (Re-)Initialization reason returned by
 *      the callback <Module>_DemInitMonitorFor<EventName>().
 */
typedef uint8 		Dem_InitMonitorReasonType;
#define DEM_INIT_MONITOR_CLEAR					   	  ((Dem_InitMonitorReasonType)0x01u)
#define DEM_INIT_MONITOR_RESTART				 	  ((Dem_InitMonitorReasonType)0x02u)
#define DEM_INIT_MONITOR_REENABLED				      ((Dem_InitMonitorReasonType)0x03u)
#define DEM_INIT_MONITOR_STORAGE_REENABLED		 	  ((Dem_InitMonitorReasonType)0x04u)

/**
 * @req [SWS_Dem_00941] This type contains all possible additional IUMPR
 *      denominator conditions to be broadcasted among OBD-relevant ECUs.
 */
typedef uint8 		Dem_IumprDenomCondIdType;
#define DEM_IUMPR_GENERAL_DENOMINATOR                 ((Dem_IumprDenomCondIdType)0x01u)
#define DEM_IUMPR_DEN_COND_COLDSTART                  ((Dem_IumprDenomCondIdType)0x02u)
#define DEM_IUMPR_DEN_COND_EVAP                       ((Dem_IumprDenomCondIdType)0x03u)
#define DEM_IUMPR_DEN_COND_500MI                      ((Dem_IumprDenomCondIdType)0x04u)

/**
 * @req [SWS_Dem_00941] This type contains all possible states of an additional
 *      IUMPR denominator condition to be broadcasted among OBD-relevant ECUs.
 */
typedef uint8 		Dem_IumprDenomCondStatusType;
#define DEM_IUMPR_DEN_STATUS_NOT_REACHED              ((Dem_IumprDenomCondStatusType)0x00u)
#define DEM_IUMPR_DEN_STATUS_REACHED                  ((Dem_IumprDenomCondStatusType)0x01u)
#define DEM_IUMPR_DEN_STATUS_INHIBITED                ((Dem_IumprDenomCondStatusType)0x02u)

/**
 * @req [SWS_Dem_00941] The type to distinguish which DTCs should be filtered.
 */
typedef uint8 		Dem_J1939DcmDTCStatusFilterType;
#define DEM_J1939DTC_ACTIVE                           ((Dem_J1939DcmDTCStatusFilterType)0x00u)
#define DEM_J1939DTC_PREVIOUSLY_ACTIVE                ((Dem_J1939DcmDTCStatusFilterType)0x01u)
#define DEM_J1939DTC_PENDING                          ((Dem_J1939DcmDTCStatusFilterType)0x02u)
#define DEM_J1939DTC_PERMANENT                        ((Dem_J1939DcmDTCStatusFilterType)0x03u)
#define DEM_J1939DTC_CURRENTLY_ACTIVE                 ((Dem_J1939DcmDTCStatusFilterType)0x04u)

/**
 * @req [SWS_Dem_00946] The type to distinguish which DTCs gets cleared.
 */
typedef uint8 		Dem_J1939DcmSetClearFilterType;
#define DEM_J1939DTC_CLEAR_ALL                        ((Dem_J1939DcmSetClearFilterType)0x00u)
#define DEM_J1939DTC_CLEAR_PREVIOUSLY_ACTIVE          ((Dem_J1939DcmSetClearFilterType)0x01u)

/**
 * @req [SWS_Dem_00947] The type to distinguish which DTCs gets cleared.
 */
typedef uint8 		Dem_J1939DcmSetFreezeFrameFilterType;
#define DEM_J1939DCM_FREEZEFRAME                      ((Dem_J1939DcmSetFreezeFrameFilterType)0x00u)
#define DEM_J1939DCM_EXPANDED_FREEZEFRAME             ((Dem_J1939DcmSetFreezeFrameFilterType)0x01u)
#define DEM_J1939DCM_SPNS_IN_EXPANDED_FREEZEFRAME     ((Dem_J1939DcmSetFreezeFrameFilterType)0x02u)

/**
 * @req [SWS_Dem_00948]
 *      bits 8-7:Malfunction Indicator Lamp Status.
 *      bits 6-5:Red Stop Lamp Status.
 *      bits 4-3:Amber Warning Lamp Status.
 *      bits 2-1:Protect Lamp Status.
 *      bits 8-7:Flash Malfunction Indicator Lamp.
 *      bits 6-5:Flash Red Stop Lamp.
 *      bits 4-3:Flash Amber Warning Lamp.
 *      bits 2-1:Flash Protect Lamp.
 */
typedef uint16 		Dem_J1939DcmLampStatusType;

/**
 * @req [SWS_Dem_00952] Used to return the status of Dem_DcmGetStatusOfDTC.
 */
typedef uint8 		Dem_ReturnGetStatusOfDTCType;
#define DEM_STATUS_OK                                 ((Dem_ReturnGetStatusOfDTCType)0x00u)
#define DEM_STATUS_WRONG_DTC                          ((Dem_ReturnGetStatusOfDTCType)0x01u)
#define DEM_STATUS_WRONG_DTCORIGIN                    ((Dem_ReturnGetStatusOfDTCType)0x02u)
#define DEM_STATUS_FAILED                             ((Dem_ReturnGetStatusOfDTCType)0x03u)
#define DEM_STATUS_PENDING                            ((Dem_ReturnGetStatusOfDTCType)0x04u)

/**
 * @req [SWS_Dem_00953] Used to return the status of Dem_DcmGetSeverityOfDTC.
 */
typedef uint8 		Dem_ReturnGetSeverityOfDTCType;
#define DEM_GET_SEVERITYOFDTC_OK                      ((Dem_ReturnGetSeverityOfDTCType)0x00u)
#define DEM_GET_SEVERITYOFDTC_WRONG_DTC               ((Dem_ReturnGetSeverityOfDTCType)0x01u)
#define DEM_GET_SEVERITYOFDTC_NOSEVERITY              ((Dem_ReturnGetSeverityOfDTCType)0x02u)
#define DEM_GET_SEVERITYOFDTC_PENDING                 ((Dem_ReturnGetSeverityOfDTCType)0x03u)

/**
 * @req [SWS_Dem_00954] Used to return the status of Dem_DcmGetFunctionalUnitOfDTC.
 */
typedef uint8 		Dem_ReturnGetFunctionalUnitOfDTCType;
#define DEM_GET_FUNCTIONALUNITOFDTC_OK                ((Dem_ReturnGetFunctionalUnitOfDTCType)0x00u)
#define DEM_GET_FUNCTIONALUNITOFDTC_WRONG_DTC         ((Dem_ReturnGetFunctionalUnitOfDTCType)0x01u)

/**
 * @req [SWS_Dem_00955] Used to return the status of (re-)setting a specific filter.
 */
typedef uint8  		Dem_ReturnSetFilterType;
#define DEM_FILTER_ACCEPTED                           ((Dem_ReturnSetFilterType)0x00u)
#define DEM_WRONG_FILTER                              ((Dem_ReturnSetFilterType)0x01u)

/**
 * @req [SWS_Dem_00956] Used to return the status of Dem_DcmGetNumberOfFilteredDTC.
 */
typedef uint8 		Dem_ReturnGetNumberOfFilteredDTCType;
#define DEM_NUMBER_OK                                 ((Dem_ReturnGetNumberOfFilteredDTCType)0x00u)
#define DEM_NUMBER_FAILED                             ((Dem_ReturnGetNumberOfFilteredDTCType)0x01u)
#define DEM_NUMBER_PENDING                            ((Dem_ReturnGetNumberOfFilteredDTCType)0x02u)

/**
 * @req [SWS_Dem_00957] Used to return the status of Dem_DcmGetNextFilteredXxx and
 *      Dem_J1939DcmGetNextFilteredXxx.
 */
typedef uint8 		Dem_ReturnGetNextFilteredElementType;
#define DEM_FILTERED_OK                               ((Dem_ReturnGetNextFilteredElementType)0x00u)
#define DEM_FILTERED_NO_MATCHING_ELEMENT              ((Dem_ReturnGetNextFilteredElementType)0x01u)
#define DEM_FILTERED_PENDING                          ((Dem_ReturnGetNextFilteredElementType)0x02u)
#define DEM_FILTERED_BUFFER_TOO_SMALL                 ((Dem_ReturnGetNextFilteredElementType)0x03u)

/**
 * @req [SWS_Dem_00958] Used to return the status of Dem_DtcGetDTCByOccurrenceTime.
 */
typedef uint8 		Dem_ReturnGetDTCByOccurrenceTimeType;
#define DEM_OCCURR_OK                                 ((Dem_ReturnGetDTCByOccurrenceTimeType)0x00u)
#define DEM_OCCURR_NOT_AVAILABLE                      ((Dem_ReturnGetDTCByOccurrenceTimeType)0x01u)

/**
 * @req [SWS_Dem_00959] Used to return the status of Dem_DcmDisableDTCRecordUpdate.
 */
typedef uint8 		Dem_ReturnDisableDTCRecordUpdateType;
#define DEM_DISABLE_DTCRECUP_OK                       ((Dem_ReturnDisableDTCRecordUpdateType)0x00u)
#define DEM_DISABLE_DTCRECUP_WRONG_DTC                ((Dem_ReturnDisableDTCRecordUpdateType)0x01u)
#define DEM_DISABLE_DTCRECUP_WRONG_DTCORIGIN          ((Dem_ReturnDisableDTCRecordUpdateType)0x02u)
#define DEM_DISABLE_DTCRECUP_PENDING                  ((Dem_ReturnDisableDTCRecordUpdateType)0x03u)

/**
 * @req [SWS_Dem_00960] Used to return the status of Dem_DcmGetFreezeFrameDataByDTC.
 */
typedef uint8 		Dem_ReturnGetFreezeFrameDataByDTCType;
#define DEM_GET_FFDATABYDTC_OK                        ((Dem_ReturnGetFreezeFrameDataByDTCType)0x00u)
#define DEM_GET_FFDATABYDTC_WRONG_DTC                 ((Dem_ReturnGetFreezeFrameDataByDTCType)0x01u)
#define DEM_GET_FFDATABYDTC_WRONG_DTCORIGIN           ((Dem_ReturnGetFreezeFrameDataByDTCType)0x02u)
#define DEM_GET_FFDATABYDTC_WRONG_RECORDNUMBER        ((Dem_ReturnGetFreezeFrameDataByDTCType)0x03u)
#define DEM_GET_FFDATABYDTC_WRONG_BUFFERSIZE          ((Dem_ReturnGetFreezeFrameDataByDTCType)0x04u)
#define DEM_GET_FFDATABYDTC_PENDING                   ((Dem_ReturnGetFreezeFrameDataByDTCType)0x05u)

/**
 * @req [SWS_Dem_00961] Used to return the status of Dem_DcmGetExtendedDataRecordByDTC.
 */
typedef uint8 		Dem_ReturnGetExtendedDataRecordByDTCType;
#define DEM_RECORD_OK                                 ((Dem_ReturnGetExtendedDataRecordByDTCType)0x00u)
#define DEM_RECORD_WRONG_DTC                          ((Dem_ReturnGetExtendedDataRecordByDTCType)0x01u)
#define DEM_RECORD_WRONG_DTCORIGIN                    ((Dem_ReturnGetExtendedDataRecordByDTCType)0x02u)
#define DEM_RECORD_WRONG_NUMBER                       ((Dem_ReturnGetExtendedDataRecordByDTCType)0x03u)
#define DEM_RECORD_WRONG_BUFFERSIZE                   ((Dem_ReturnGetExtendedDataRecordByDTCType)0x04u)
#define DEM_RECORD_PENDING                            ((Dem_ReturnGetExtendedDataRecordByDTCType)0x05u)

/**
 * @req [SWS_Dem_00962] Used to return the status of Dem_DcmGetSizeOfFreezeFrameByDTC
 *      and Dem_DcmGetSizeOfExtendedDataRecordByDTC.
 */
typedef uint8		Dem_ReturnGetSizeOfDataByDTCType;
#define DEM_GETSIZEBYDTC_OK                           ((Dem_ReturnGetSizeOfDataByDTCType)0x00u)
#define DEM_GETSIZEBYDTC_WRONG_DTC                    ((Dem_ReturnGetSizeOfDataByDTCType)0x01u)
#define DEM_GETSIZEBYDTC_WRONG_DTCORIGIN              ((Dem_ReturnGetSizeOfDataByDTCType)0x02u)
#define DEM_GETSIZEBYDTC_WRONG_RECNUM                 ((Dem_ReturnGetSizeOfDataByDTCType)0x03u)
#define DEM_GETSIZEBYDTC_PENDING                      ((Dem_ReturnGetSizeOfDataByDTCType)0x04u)

/**
 * @req [SWS_Dem_00963] Used to return the status of Dem_<...>ClearDTC.
 */
typedef uint8 		Dem_ReturnClearDTCType;
#define DEM_CLEAR_OK                                  ((Dem_ReturnClearDTCType)0x00u)
#define DEM_CLEAR_WRONG_DTC                           ((Dem_ReturnClearDTCType)0x01u)
#define DEM_CLEAR_WRONG_DTCORIGIN                     ((Dem_ReturnClearDTCType)0x02u)
#define DEM_CLEAR_FAILED                              ((Dem_ReturnClearDTCType)0x03u)
#define DEM_CLEAR_PENDING                             ((Dem_ReturnClearDTCType)0x04u)
#define DEM_CLEAR_BUSY                                ((Dem_ReturnClearDTCType)0x05u)
#define DEM_CLEAR_MEMORY_ERROR                        ((Dem_ReturnClearDTCType)0x06u)

/**
 * @req [SWS_Dem_00964] Used to return the status of Dem_DcmDisableDTCSetting
 *      and Dem_DcmEnableDTCSetting.
 */
typedef uint8 		Dem_ReturnControlDTCSettingType;
#define DEM_CONTROL_DTC_SETTING_OK                    ((Dem_ReturnControlDTCSettingType)0x00u)
#define DEM_CONTROL_DTC_SETTING_N_OK                  ((Dem_ReturnControlDTCSettingType)0x01u)
#define DEM_CONTROL_DTC_WRONG_DTCGROUP                ((Dem_ReturnControlDTCSettingType)0x02u)

typedef uint8 		Dem_DebounceBehaviorType;
#define DEM_DEBOUNCE_FREEZE							  ((Dem_DebounceBehaviorType)0x00u)
#define DEM_DEBOUNCE_RESET							  ((Dem_DebounceBehaviorType)0x01u)

typedef uint8		Dem_DebounceAlgorithmClassType;
#define DEM_DEBOUNCE_COUNTER_BASED 					  ((Dem_DebounceAlgorithmClassType)0x00u)
#define DEM_DEBOUNCE_TIME_BASE 						  ((Dem_DebounceAlgorithmClassType)0x01u)
#define DEM_DEBOUNCE_MONITOR_INTERNAL				  ((Dem_DebounceAlgorithmClassType)0x02u)
#define DEM_NONE_DEBOUNCE							  ((Dem_DebounceAlgorithmClassType)0x03u)

typedef uint8		Dem_ClearEventAllowedBehaviorType;
#define DEM_NO_STATUS_BYTE_CHANGE					  ((Dem_ClearEventAllowedBehaviorType)0x00u)
#define DEM_ONLY_THIS_CYCLE_AND_READINESS			  ((Dem_ClearEventAllowedBehaviorType)0x01u)

typedef uint8		Dem_FreezeFrameRecordUpdateType;
typedef uint8		Dem_ExtendedDataRecordUpdateType;
#define DEM_UPDATE_RECORD_NO					 	  ((Dem_FreezeFrameRecordUpdateType)0x00u)
#define DEM_UPDATE_RECORD_YES			 			  ((Dem_FreezeFrameRecordUpdateType)0x01u)

typedef uint8 		Dem_EventMemoryEntryStorageTriggerType;
typedef uint8		Dem_FreezeFrameRecordTriggerType;
typedef uint8		Dem_ExtendedDataRecordTriggerType;
#define DEM_TRIGGER_ON_CONFIRMED					  (0x00u)
#define DEM_TRIGGER_ON_FDC_THRESHOLD			 	  (0x01u)
#define DEM_TRIGGER_ON_PENDING					      (0x04u)
#define DEM_TRIGGER_ON_TEST_FAILED			 	      (0x05u)
#define DEM_TRIGGER_ON_MIRROR					      (0x02u)
#define DEM_TRIGGER_ON_PASSED				          (0x03u)

typedef uint8 		Dem_InternalDataElementType;
#define DEM_AGINGCTR_DOWNCNT						  ((Dem_InternalDataElementType)0x00u)
#define DEM_AGINGCTR_UPCNT						      ((Dem_InternalDataElementType)0x01u)
#define DEM_CURRENT_FDC								  ((Dem_InternalDataElementType)0x02u)
#define DEM_CYCLES_SINCE_FIRST_FAILED				  ((Dem_InternalDataElementType)0x03u)
#define DEM_CYCLES_SINCE_LAST_FAILED			 	  ((Dem_InternalDataElementType)0x04u)
#define DEM_FAILED_CYCLES		  				 	  ((Dem_InternalDataElementType)0x05u)
#define DEM_MAX_FDC_DURING_CURRENT_CYCLE			  ((Dem_InternalDataElementType)0x06u)
#define DEM_MAX_FDC_SINCE_LAST_CLEAR				  ((Dem_InternalDataElementType)0x07u)
#define DEM_OCCCTR								 	  ((Dem_InternalDataElementType)0x08u)
#define DEM_OVFLIND				 					  ((Dem_InternalDataElementType)0x09u)
#define DEM_SIGNIFICANCE				 			  ((Dem_InternalDataElementType)0x0Au)

typedef uint8       Dem_DataElementDataType;
#define DEM_BOOLEAN									  ((Dem_DataElementDataType)0x00u)
#define DEM_SINT16									  ((Dem_DataElementDataType)0x01u)
#define DEM_SINT32									  ((Dem_DataElementDataType)0x02u)
#define DEM_SINT8									  ((Dem_DataElementDataType)0x03u)
#define DEM_UINT16									  ((Dem_DataElementDataType)0x04u)
#define DEM_UINT32									  ((Dem_DataElementDataType)0x05u)
#define DEM_UINT8									  ((Dem_DataElementDataType)0x06u)

typedef uint8		Dem_OperationCycleEnumType;
#define DEM_OPCYC_IGNITION							  ((Dem_OperationCycleEnumType)0x00u)
#define DEM_OPCYC_OBD_DCY							  ((Dem_OperationCycleEnumType)0x01u)
#define DEM_OPCYC_OTHER							 	  ((Dem_OperationCycleEnumType)0x02u)
#define DEM_OPCYC_POWER							 	  ((Dem_OperationCycleEnumType)0x03u)
#define DEM_OPCYC_TIME							 	  ((Dem_OperationCycleEnumType)0x04u)
#define DEM_OPCYC_WARMUP							  ((Dem_OperationCycleEnumType)0x05u)

typedef uint8		Dem_DataElementDefaultEndiannessType;
#define DEM_BIG_ENDIAN								  ((Dem_DataElementDefaultEndiannessType)0x00u)
#define DEM_LITTLE_ENDIAN							  ((Dem_DataElementDefaultEndiannessType)0x00u)
#define DEM_OPAQUE								 	  ((Dem_DataElementDefaultEndiannessType)0x00u)

/**
 * @req [SWS_Dem_00169] The Dem module shall distinguish between a
 *      pre-initialization mode and a full-initialized mode (operation mode).
 */
typedef uint8 		Dem_StateType;
#define DEM_STATE_UNINIT							  ((Dem_StateType)0x00u)
#define DEM_STATE_PRE_INIT							  ((Dem_StateType)0x01u)
#define DEM_STATE_INIT							 	  ((Dem_StateType)0x02u)

typedef uint8       Dem_EventKindType;
#define DEM_EVENT_KIND_BSW 							  ((Dem_EventKindType)0u)
#define DEM_EVENT_KIND_SWC 							  ((Dem_EventKindType)1u)

typedef uint8       Dem_ReportBehaviorType;
#define REPORT_AFTER_INIT 							  ((Dem_ReportBehaviorType)0u)
#define REPORT_BEFORE_INIT 							  ((Dem_ReportBehaviorType)1u)

typedef uint8       Dem_InternalEventStatusType;
#define DEM_EVENT_STATUS_DTC_SETTING 				  ((Dem_InternalEventStatusType)0x01u)
#define DEM_EVENT_STATUS_AVAILABLE					  ((Dem_InternalEventStatusType)0x02u)
#define DEM_EVENT_STATUS_ENABLED_CONDICTION 		  ((Dem_InternalEventStatusType)0x04u)
#define DEM_EVENT_STATUS_STORAGE_CONDICTION 		  ((Dem_InternalEventStatusType)0x08u)
#define DEM_EVENT_STATUS_FDC_TRIGGERED				  ((Dem_InternalEventStatusType)0x10u)
#define DEM_EVENT_STATUS_TFBITCHANGE 				  ((Dem_InternalEventStatusType)0x20u)
#define DEM_EVENT_STATUS_CONSECUTIVE_FAULT 			  ((Dem_InternalEventStatusType)0x40u)
#define DEM_EVENT_STATUS_ACTIVE 					  ((Dem_InternalEventStatusType)0x80u)

typedef uint8		Dem_EventTriggerConditionType;
#define DEM_EVENT_TF_RESET								((Dem_EventTriggerConditionType)0x01u)
#define DEM_EVENT_PDTC_CHANGE							((Dem_EventTriggerConditionType)0x02u)
#define DEM_EVENT_CDTC_CHANGE							((Dem_EventTriggerConditionType)0x04u)
#define DEM_EVENT_FDC_REACH_THRESHOLD					((Dem_EventTriggerConditionType)0x08u)
#define DEM_EVENT_TRANSFER_MIRROR						((Dem_EventTriggerConditionType)0X10u)
#define DEM_OBD_DISABLE_EVENT							((Dem_EventTriggerConditionType)0X20u)

#define DEM_DTC_WWHOBD_CLASS_A						  (0x05u)
#define DEM_DTC_WWHOBD_CLASS_B1						  (0x04u)
#define DEM_DTC_WWHOBD_CLASS_B2						  (0x03u)
#define DEM_DTC_WWHOBD_CLASS_C					      (0x02u)
#define DEM_DTC_WWHOBD_CLASS_NOCLASS				  (0x01u)

#define DEM_PROCESS_OCCCTR_CDTC						  (0x00u)
#define DEM_PROCESS_OCCCTR_TF                         (0x01u)

#define DEM_DISPLACEMENT_FULL 						  (0x00u)
#define DEM_DISPLACEMENT_NONE						  (0x01u)
#define DEM_DISPLACEMENT_PRIO_OCC					  (0x02u)

#define DEM_EVCOMB_DISABLED							  (0x00u)
#define DEM_EVCOMB_ONRETRIEVAL					      (0x01u)
#define DEM_EVCOMB_ONSTORAGE						  (0x02u)

#define DEM_FF_RECNUM_CALCULATED           			  (0x00u)
#define DEM_FF_RECNUM_CONFIGURED					  (0x01u)

#define DEM_CAPTURE_ASYNCHRONOUS_TO_REPORTING         (0x00u)
#define DEM_CAPTURE_SYNCHRONOUS_TO_REPORTING          (0x01u)

#define DEM_PROCESS_AGINGCTR_EXTERN					  (0x00u)
#define DEM_PROCESS_AGINGCTR_INTERN                   (0x01u)

#define DEM_ALL_SUPPORTED_DTCS						  (0x00u)
#define DEM_ONLY_CLEAR_ALL_DTCS						  (0x01u)

#define DEM_EVENT_AVAILABILITY						  (0x00u)
#define DEM_NO_AVAILABILITY							  (0x01u)

#define DEM_CLRRESP_NONVOLATILE_FINISH			  	  (0x00u)
#define DEM_CLRRESP_NONVOLATILE_TRIGGER				  (0x01u)
#define DEM_CLRRESP_VOLATILE					 	  (0x02u)

#define DEM_OBD_DEP_SEC_ECU 						  (0x00u)
#define DEM_OBD_MASTER_ECU                            (0x01u)
#define DEM_OBD_NO_OBD_SUPPORT                        (0x02u)
#define DEM_OBD_PRIMARY_ECU                           (0x03u)

#define DEM_STATUS_BIT_AGING_AND_DISPLACEMENT         (0x00u)
#define DEM_STATUS_BIT_NORMAL                         (0x01u)

#define DEM_DTC_SUPPRESSION                           (0x00u)
#define DEM_NO_SUPPRESSION                            (0x01u)

#define DEM_DTC_GROUP_ALL_DTCS						  (0xFFFFFFu)

#define DEM_EVENT_SIGNIFICANCE_FAULT				  (0x00u)
#define DEM_EVENT_SIGNIFICANCE_OCCURRENCE		      (0x01u)

#define DEM_IGNITION_COMPRESSION					   (0x00u)
#define DEM_IGNITION_SPARK							   (0x01u)

/* do not change order */
#define DEM_OBD_RDY_MISF								(0x00u)
#define DEM_OBD_RDY_FLSYS								(0x01u)
#define DEM_OBD_RDY_CMPRCMPT							(0x02u)
#define DEM_OBD_RDY_CAT									(0x03u)
#define DEM_OBD_RDY_HTCAT								(0x04u)
#define DEM_OBD_RDY_EVAP								(0x05u)
#define DEM_OBD_RDY_SECAIR								(0x06u)
#define DEM_OBD_RDY_O2SENS								(0x07u)
#define DEM_OBD_RDY_O2SENSHT							(0x08u)
#define DEM_OBD_RDY_ERG									(0x09u)
#define DEM_OBD_RDY_HCCAT								(0x0Au)
#define DEM_OBD_RDY_NOXCAT								(0x0Bu)
#define DEM_OBD_RDY_BOOSTPR								(0x0Cu)
#define DEM_OBD_RDY_EGSENS								(0x0Du)
#define DEM_OBD_RDY_PMFLT								(0x0Eu)
#define DEM_OBD_RDY_AC									(0x0Fu)
#define DEM_OBD_RDY_FLSYS_NONCONT						(0x10u)
#define DEM_OBD_RDY_NONE								(0x11u)

/* do not change order */
#define DEM_IUMPR_DEN_NONE							   (0x00u)
#define DEM_IUMPR_DEN_COLDSTART						   (0x01u)
#define DEM_IUMPR_DEN_EVAP						       (0x02u)
#define DEM_IUMPR_DEN_500MILL   					   (0x03u)
#define DEM_IUMPR_DEN_PHYS_API						   (0x04u)

/* do not change order */
#define DEM_IUMPR_BOOSTPRS							   (0x00u)
#define DEM_IUMPR_CAT1							       (0x01u)
#define DEM_IUMPR_CAT2								   (0x02u)
#define DEM_IUMPR_EGR						           (0x03u)
#define DEM_IUMPR_EGSENSOR							   (0x04u)
#define DEM_IUMPR_EVAP								   (0x05u)
#define DEM_IUMPR_FLSYS							       (0x06u)
#define DEM_IUMPR_NMHCCAT							   (0x07u)
#define DEM_IUMPR_NOXADSORB					           (0x08u)
#define DEM_IUMPR_NOXCAT							   (0x09u)
#define DEM_IUMPR_OXS1							       (0x0Au)
#define DEM_IUMPR_OXS2							       (0x0Bu)
#define DEM_IUMPR_PMFILTER							   (0x0Cu)
#define DEM_IUMPR_PRIVATE							   (0x0Du)
#define DEM_IUMPR_SAIR							       (0x0Eu)
#define DEM_IUMPR_SECOXS1						       (0x0Fu)
#define DEM_IUMPR_SECOXS2							   (0x10u)

#define DEM_RATIO_API								   (0x00u)
#define DEM_RATIO_OBSERVER							   (0x01u)

typedef uint8		Dem_DtrUpdateKindType;
#define DEM_DTR_UPDATE_ALWAYS							((Dem_DtrUpdateKindType)0x00u)
#define DEM_DTR_UPDATE_STEADY							((Dem_DtrUpdateKindType)0x01u)

/*====================================================================================================*
 *                                               ENUMS
 *====================================================================================================*/

/*====================================================================================================*
 *                                   STRUCTURES AND OTHER TYPEDEFS
 *====================================================================================================*/
#if(DEM_MAX_NUMBER_FF_RECORDS > 0)
typedef struct
{
	uint8 RecNum;
	uint8 FFData[DEM_FREEZE_FRAME_MAX_LEN];
}Dem_MemFFInfoType;
#endif /* #if(DEM_MAX_NUMBER_FF_RECORDS > 0) */

#if(DEM_MAX_NUMBER_EXT_REC > 0)
typedef struct
{
	uint8 RecNum;
	uint8 ExtData[DEM_EXTENDED_DATA_REC_MAX_LEN];
}Dem_MemExtInfoType;
#endif /* #if(DEM_MAX_NUMBER_EXT_REC > 0) */

#if(DEM_PID_CLASS_NUM > 0)
typedef struct
{
	uint8 PidId;
	uint8 PidData[DEM_PID_DATA_MAX_LEN];
}Dem_PidInfoType;
#endif /* #if(DEM_PID_CLASS_NUM > 0) */

typedef struct
{
	Dem_EventIdType EventId;
	uint8 			AbsTime;
	uint8 			UdsStatus;
	uint8 			AgingCounter;
	uint8 			HealingCounter;
	uint8 			FailureCounter;
	uint8 			OccurrenceCounter;
	uint8 			CyclesSinceLastFailed;
	uint8 			CyclesSinceFirstFailed;

#if(DEM_MAX_NUMBER_FF_RECORDS > 0)
	uint8 LastestFF;
	uint8 FFStoreNum;
	Dem_MemFFInfoType FFInfo[DEM_MAX_NUMBER_FF_RECORDS];
#endif /* #if(DEM_MAX_NUMBER_FF_RECORDS > 0) */

#if(DEM_MAX_NUMBER_EXT_REC > 0)
	Dem_MemExtInfoType ExtInfo[DEM_MAX_NUMBER_EXT_REC];
#endif /* #if(DEM_MAX_NUMBER_EXT_REC > 0) */

#if(DEM_PID_CLASS_NUM > 0)
	Dem_PidInfoType PidInfo[DEM_PID_CLASS_NUM];
#endif /* #if(DEM_PID_CLASS_NUM > 0) */
}Dem_MemoryEntryType;

/**
 * @req [SWS_Dem_00949] This structure represents all data elements of the
 *      DM05 message.The encoding shall be done according SAE J1939-73.
 */
typedef struct
{
	/**< @brief Number of active DTCs */
    uint8 										ActiveTroubleCodes;

    /**< @brief Number of previously active DTCs */
    uint8 										PreviouslyActiveDiagnosticTroubleCodes;

    /**< @brief OBD Compliance */
    uint8 										OBDCompliance;

    /**< @brief Identifies the continuously monitored system support and status */
    uint8 										ContinuouslyMonitoredSystemsSupport_Status;

    /**< @brief Identifies the non-continuously monitored systems support */
    uint16										NonContinuouslyMonitoredSystemsSupport;

    /**< @brief Identifies the non-continuously monitored systems status */
    uint16 										NonContinuouslyMonitoredSystemsStatus;
}Dem_J1939DcmDiagnosticReadiness1Type;

/**
 * @req [SWS_Dem_00950] This structure represents all data elements of the
 *      DM21 message. The encoding shall be done according SAE J1939-73.
 */
typedef struct
{
	/**< @brief The kilometers accumulated while the MIL is activated */
    uint16      								DistanceTraveledWhileMILisActivated;

    /**< @brief Distance accumulated since emission related DTCs were cleared */
    uint16      								DistanceSinceDTCsCleared;

    /**< @brief Accumulated count (in minutes) while the MIL is activated (on) */
    uint16     		 							MinutesRunbyEngineWhileMILisActivated;

    /**< @brief Engine running time accumulated since emission related DTCs were cleared */
    uint16      								TimeSinceDiagnosticTroubleCodesCleared;
}Dem_J1939DcmDiagnosticReadiness2Type;

/**
 * @req [SWS_Dem_00951] This structure represents all data elemets of the
 *      DM26 message. The encoding shall be done according SAE J1939-73.
 */
typedef struct
{
	/**< @brief Number of OBD warm up cycles since all DTCs were cleared */
    uint8      									NumberofWarmupsSinceDTCsCleared;

    /**< @brief Identifies the continuously monitored system enable/completed support and status */
    uint8      									ContinuouslyMonitoredSystemsEnableCompletedStatus;

    /**< @brief Time since key-on that the engine has been running. */
    uint16     									TimeSinceEngineStart;

    /**< @brief Enable status of non-continuous monitors this monitoring cycle */
    uint16     									NonContinuouslyMonitoredSystemsEnableStatus;

    /**< @brief Completion status of non-continuous monitors this monitoring cycle */
    uint16     									NonContinuouslyMonitoredSystems;
}Dem_J1939DcmDiagnosticReadiness3Type;

#if(DEM_DATA_ELEMENT_CLASS_NUM > 0)
typedef Std_ReturnType (*DemDataElementReadFncType)(
		uint8* Buffer
		);
#endif

#if(DEM_EXTERNALSRDATA_ELEMENT_NUM > 0)
typedef struct
{
	/**< @brief Defines the size of the data element in bits */
	const uint8 								DemDataElementDataSize;

	/**< @brief Provide the implementation data type of data belonging to a external data */
	const Dem_DataElementDataType				DemDataElementDataType;

	/**< @brief Defines the endianness of the data belonging to an external
	 *          data,If no DemDataElementEndianness is defined the value of
	 *          DemDataElementDefaultEndianness is applicable */
	const Dem_DataElementDefaultEndiannessType  Dem_DataElementDefaultEndiannessType;

#if 0
	const Dem_DiagnosisScalingType*				DemDiagnosisScaling;

	const Dem_SRDataElementClassType*			DemSRDataElementClass;
#endif
}Dem_ExternalSRDataElementClassType;
#endif /* #if(DEM_EXTERNALSRDATA_ELEMENT_NUM > 0) */

#if(DEM_EXTERNALCSDATA_ELEMENT_NUM > 0)
typedef struct
{
	/**< @brief If the parameter is set to True, a R-Port is generated, to obtain the data element
	 *          (interface DataServices_{Data}). If the parameter is set to False, the information
	 *          is obtained by C function-call on another BSW module specified by the parameter
	 *          DemDataElementReadFnc */
	const boolean 								DemDataElementUsePort;

	/**< @brief Defines the size of the data element in bytes */
	const uint8  								DemDataElementDataSize;

	/**< @brief In case of DemDataElementUsePort is false, this parameter defines the prototype of the
	 *          C function "ReadDataElement" used to get the according value */
	const DemDataElementReadFncType			 	DemDataElementReadFnc;
}Dem_ExternalCSDataElementClassType;
#endif /* #if(DEM_EXTERNALCSDATA_ELEMENT_NUM > 0) */

#if(DEM_INTERNAL_DATA_ELEMENT_NUM > 0)
typedef struct
{
	/**< @brief Defines the size of the data element in bytes */
	const uint8  								DemDataElementDataSize;

	/**< @brief This parameter defines the Dem-internal data value, which is mapped to the data
	 *          element */
	const Dem_InternalDataElementType		 	DemInternalDataElement;
}Dem_InternalDataElementClassType;
#endif /* #if(DEM_INTERNAL_DATA_ELEMENT_NUM > 0) */

#if(DEM_DATA_ELEMENT_CLASS_NUM > 0)
typedef struct
{
#if(DEM_EXTERNALCSDATA_ELEMENT_NUM > 0)
	const Dem_ExternalCSDataElementClassType*	DemExternalCSDataElementClass;
#endif /* #if(DEM_EXTERNALCSDATA_ELEMENT_NUM > 0) */

#if(DEM_EXTERNALSRDATA_ELEMENT_NUM > 0)
	const Dem_ExternalSRDataElementClassType*	DemExternalSRDataElementClass;
#endif /* #if(DEM_EXTERNALSRDATA_ELEMENT_NUM > 0) */

#if(DEM_INTERNAL_DATA_ELEMENT_NUM > 0)
	const Dem_InternalDataElementClassType*		DemInternalDataElementClass;
#endif /* #if(DEM_INTERNAL_DATA_ELEMENT_NUM > 0) */
} Dem_DataElementClassType;
#endif /* #if(DEM_DATA_ELEMENT_CLASS_NUM > 0) */

#if(DEM_EXTENDED_DATA_RECORD_CLASS_NUM > 0)
typedef struct
{
	/**< @brief This configuration parameter specifies an unique identifier for an extended data record.
	 *  		One or more extended data records can be assigned to one diagnostic event/DTC. 0x00 is
	 *  		reserved by ISO (therefore the minimal value equals 1).0xF0 to 0xFF are reserved by ISO
	 *  		(therefore the maximal value equals 239) */
    const uint8 								DemExtendedDataRecordNumber;

    /**< @brief Number of DemDataElementClassRef */
    const uint8 								DemDataElementClassRefNum;

    /**< @brief Defines the trigger to store the ExtendedDataRecord */
    const Dem_ExtendedDataRecordTriggerType 	DemExtendedDataRecordTrigger;

    /**< @brief This extended data record is captured if the configured trigger condition in
     *          "DemExtendedDataRecordTrigger" is fulfilled */
    const Dem_ExtendedDataRecordUpdateType		DemExtendedDataRecordUpdate;

    /**< @brief Total size which contained in data element class */
    const uint16 								DemDataElementClassRefDataSize;

    /**< @brief This reference contains the link to a data element class */
    const uint16* 								DemDataElementClassRefStartIndex;
} Dem_ExtendedDataRecordClassType;
#endif /* #if(DEM_EXTENDED_DATA_RECORD_CLASS_NUM > 0) */

#if(DEM_EXTENDED_DATA_CLASS_NUM > 0)
typedef struct
{
    /**< @brief Number of DemExtendedDataRecordClassRef */
    const uint8 								DemExtendedDataRecordClassRefNum;

	/**< @brief This reference contains the link to an extended data class record */
    const uint8* 								DemExtendedDataRecordClassRefStartIndex;
} Dem_ExtendedDataClassType;
#endif /* #if(DEM_EXTENDED_DATA_CLASS_NUM > 0) */

#if(DEM_FREEZE_FRAME_REC_NUM_CLASS_NUM > 0)
typedef struct
{
	/**< @brief Number of DemFreezeFrameRecordClassRef */
    const uint8 								DemFreezeFrameRecordClassRefNum;

    /**< @brief This parameter references record number(s) for a freeze frame record */
    const uint8* 								DemFreezeFrameRecordClassRefStartIndex;
} Dem_FreezeFrameRecNumClassType;
#endif /* #if(DEM_FREEZE_FRAME_REC_NUM_CLASS_NUM > 0) */

#if(DEM_FREEZE_FRAME_RECORD_CLASS_NUM > 0)
typedef struct
{
	/**< @brief This parameter defines a record number for a freeze frame record.This record number is
	 *          unique per freeze frame record number class */
    const uint8 								DemFreezeFrameRecordNumber;

    /**< @brief Defines the trigger to store the FreezeFrameRecordTrigger */
    const Dem_FreezeFrameRecordTriggerType 		DemFreezeFrameRecordTrigger;

    /**< @brief This parameter defines the case, when the freeze frame record is stored/updated */
    const Dem_FreezeFrameRecordUpdateType 		DemFreezeFrameRecordUpdate;
} Dem_FreezeFrameRecordClassType;
#endif /* #if(DEM_FREEZE_FRAME_RECORD_CLASS_NUM > 0) */

#if(DEM_DID_CLASS_NUM > 0)
typedef struct
{
	/**< @brief Number of DemDidDataElementClassRef */
    const uint8 								DemDidDataElementClassRefNum;

    /**< @brief Identifier of the Data ID */
    const uint16 								DemDidIdentifier;

    /**< @brief Total data size of data element class which this DID class reference to */
    const uint16 								DemDidDataElementClassRefDataSize;

    /**< @brief Index of data element class which this DID class reference to */
    const uint16* 								DemDidDataElementClassRefStartIndex;
} Dem_DidClassType;
#endif /* #if(DEM_DID_CLASS_NUM > 0) */

#if(DEM_FREEZE_FRAME_CLASS_NUM > 0)
typedef struct
{
	/**< @brief Number of DemDidClassRef */
	const uint8  								DemDidClassRefNum;

	/**< @brief Total data size of DID elements which shall be contained in the freeze frame */
    const uint16								DemRefDidDataSize;

    /**< @brief Index of DID elements which shall be contained in the freeze frame */
    const uint16* 								DemDidClassRefStartIndex;
} Dem_FreezeFrameClassType;
#endif /* #if(DEM_FREEZE_FRAME_CLASS_NUM > 0) */

#if(DEM_CALLBACK_INIT_MFOREFNC_TOTALNUM > 0)
typedef Std_ReturnType (*Dem_CallbackInitMForEFncType)(
		Dem_InitMonitorReasonType InitMonitorReason
		);
#endif /* #if(DEM_CALLBACK_INIT_MFOREFNC_TOTALNUM > 0) */

#if(DEM_CALLBACK_EVENT_STATUS_CHANGED_NUM > 0)
typedef Std_ReturnType (*Dem_TriggerOnEventStatusType)(
		Dem_EventIdType EventId,
		Dem_UdsStatusByteType EventStatusByteOld,
		Dem_UdsStatusByteType EventStatusByteNew
		);
#endif /* #if(DEM_CALLBACK_EVENT_STATUS_CHANGED_NUM > 0) */

#if(DEM_CALLBACK_EVENTDATA_CHANGE_NUM > 0)
typedef Std_ReturnType  (*Dem_CallbackEventDataChangedFncType)(
		Dem_EventIdType EventId
		);
#endif /* #if(DEM_CALLBACK_EVENTDATA_CHANGE_NUM > 0) */

#if(DEM_CALLBACK_CLEAR_EVENT_ALLOWED_NUM > 0)
typedef Std_ReturnType (*Dem_ClearEventAllowedType)(
		boolean *Allowed
		);

typedef struct
{
    /**< @brief Defines the resulting UDS status byte for the related event, which
     *          must not be cleared ording to the ClearEventAllowed callback. */
    const Dem_ClearEventAllowedBehaviorType		DemClearEventAllowedBehavior;

	/**< @brief Function name of prototype "ClearEventAllowed". */
    const Dem_ClearEventAllowedType 			DemClearEventAllowed;
} Dem_CallbackClearEventAllowedType;
#endif /* #if(DEM_CALLBACK_CLEAR_EVENT_ALLOWED_NUM > 0) */


#if(DEM_DEBOUNCE_MONITOR_INTERNAL_EVENT_NUM > 0)
typedef Std_ReturnType (*Dem_GetFDCFncType)(
		sint8* FDC
		);
#endif /* #if(DEM_DEBOUNCE_MONITOR_INTERNAL_EVENT_NUM > 0) */


#if(DEM_DEBOUNCE_TIME_BASED_SUPPORT == STD_ON)
#if(DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0)
typedef struct
{
    /**< @brief This parameter defines how the event debounce algorithm will behave,if a related enable
     *          condition is not fulfilled or ControlDTCSetting of the related event is disabled. */
    const Dem_DebounceBehaviorType 				DemDebounceBehavior;

    /**< @brief Defines the time out duration for "Event Failed" qualification. */
    const uint32	 							DemDebounceTimeFailedThreshold;

    /**< @brief Defines the time out duration for "Event Passed" qualification. */
    const uint32 								DemDebounceTimePassedThreshold;
} Dem_DebounceTimeBaseClassType;
#endif /* #if(DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0) */
#endif /* #if(DEM_DEBOUNCE_TIME_BASED_SUPPORT == STD_ON) */

#if(DEM_DEBOUNCE_COUNTER_BASED_SUPPORT == STD_ON)
#if(DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM > 0)
typedef struct
{
	/**< @brief Switch for the activation of Jump-Down */
    const boolean 								DemDebounceCounterJumpDown;

    /**< @brief Switch for the activation of Jump-Up */
    const boolean 								DemDebounceCounterJumpUp;

    /**< @brief Switch to store the debounce counter value non-volatile or not */
    const boolean 								DemDebounceCounterStorage;

    /**< @brief This parameter defines how the event debounce algorithm will behave,if a related enable
     *          condition is not fulfilled or ControlDTCSetting of the related event is disabled. */
    const Dem_DebounceBehaviorType 				DemDebounceBehavior;

    /**< @brief Defines the step size for decrementation of the internal debounce counter (PREPASSED) */
    const uint16 								DemDebounceCounterDecrementStepSize;

    /**< @brief Defines the step size for incrementation of the internal debounce counter (PREFAILED) */
    const uint16 								DemDebounceCounterIncrementStepSize;

    /**< @brief Jump-Down value of the internal debounce counter which is taken as initialization value
     *          for the counter when the respective step-down occurs. */
    const sint16 								DemDebounceCounterJumpDownValue;

    /**< @brief Jump-Up value of the internal debounce counter which is taken as initialization value
     *          for the counter when the respective step-up occurs */
    const sint16 								DemDebounceCounterJumpUpValue;

    /**< @brief Defines the value of the internal debounce counter, which indicates the failed status */
    const sint16 								DemDebounceCounterFailedThreshold;

    /**< @brief Defines the value of the internal debounce counter, which indicates the passed status */
    const sint16 								DemDebounceCounterPassedThreshold;
} Dem_DebounceCounterBasedClassType;
#endif /* #if(DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM > 0) */
#endif /* #if(DEM_DEBOUNCE_COUNTER_BASED_SUPPORT == STD_ON) */

#if(DEM_INDICATOR_NUM > 0)
#if(DEM_INDICATOR_ATTRIBUTE_TOTAL_NUM > 0)
typedef struct
{
	/**< @brief Defines the number of failure cycles for the WarningIndicatorOnCriteria */
    const uint8									DemIndicatorFailureCycleCounterThreshold;

    /**< @brief Defines the number of healing cycles for the WarningIndicatorOffCriteria */
    const uint8 								DemIndicatorHealingCycleCounterThreshold;

    /**< @brief Reference to the used indicator */
    const uint8 								DemIndicatorRef;

    /**
     * @req [SWS_Dem_00511] The Dem module shall provide the configuration parameter
     *      DemIndicatorBehaviour (refer to DemIndicatorAttribute) to assign a specific
     *      behavior (e.g. illuminate continuously or blinking) to each indicator and
     *      per event.
     */

    /**< @brief Behaviour of the linked indicator */
    const Dem_IndicatorBehaviourType 			DemIndicatorBehaviour;
} Dem_IndicatorAttributeType;
#endif /* #if(DEM_INDICATOR_ATTRIBUTE_TOTAL_NUM > 0) */
#endif /* #if(DEM_INDICATOR_NUM > 0) */

#if(DEM_DTR_NUM > 0)
typedef struct
{
    /**< @brief [ECUC_Dem_00815] This is the only one supported denominator
     *          value, a constant divisor.The value 0 is not allowed.*/
    const uint32								DemDtrCompuDenominator0;

    /**< @brief [ECUC_Dem_00814] This is the first numerator value, which is
     *          multiplied with x^0, that is the offset.*/
    const uint32								DemDtrCompuNumerator0;

    /**< @brief [ECUC_Dem_00813] This is the second numerator value, which is
     *          multiplied with x^1, that is the factor.*/
    const uint32								DemDtrCompuNumerator1;

    /**< @brief [ECUC_Dem_00807] The index identifier value assigned to this DTR. The value
     *          is generated during the Dem configuration process.*/
    const uint16								DemDtrId;

    /**< @brief [ECUC_Dem_00809] The OBDMID of the DTR.The values 0x00, 0x20, 0x40, 0x60,
     *          0x80, 0xA0, 0xC0, 0xE0 are reserved.*/
    const uint8 								DemDtrMid;

    /**< @brief [ECUC_Dem_00810] The OBDTID of the DTR.*/
    const uint8 								DemDtrTid;

    /**< @brief [ECUC_Dem_00811] The UaSId the DTR data shall be scaled to, and reported
     *          together with the rescaled DTR data.*/
    const uint8 								DemDtrUasid;

    /**< @brief [ECUC_Dem_00808] Update conditions applied by the Dem to reports of DTR values.\
     *  		Only supported if a related Event is configured..*/
    const Dem_DtrUpdateKindType					DemDtrUpdateKind;

    /**< @brief [ECUC_Dem_00808] Reference to the DemEventParameter this DTR is related to.*/
    const Dem_EventIdType						DemDtrEventRef;
} Dem_DtrsType;
#endif /* #if(DEM_DTR_NUM > 0) */

#if(DEM_CALLBACK_INIT_MFOREFNC_TOTALNUM > 0)
typedef struct
{
	const Dem_CallbackInitMForEFncType 				DemCallbackInitMForEFnc;
}Dem_CallbackInitMForEType;
#endif /* #if(DEM_CALLBACK_INIT_MFOREFNC_TOTALNUM > 0) */

#if(DEM_CALLBACK_EVENTDATA_CHANGE_NUM > 0)
typedef struct
{
	const Dem_CallbackEventDataChangedFncType 	    DemCallbackEventDataChangedFnc;
}Dem_CallbackEventDataChangedType;
#endif /* #if(DEM_CALLBACK_EVENTDATA_CHANGE_NUM > 0) */

#if(DEM_CALLBACK_EVENT_STATUS_CHANGED_NUM > 0)
typedef struct
{
	const Dem_TriggerOnEventStatusType 	            DemCallbackEventStatusChangedFnc;
}Dem_CallbackEventStatusChangedsType;
#endif /* #if(DEM_CALLBACK_EVENT_STATUS_CHANGED_NUM > 0) */

typedef struct
{
	/**< @brief This parameter configures an Event as unavailable. It is treated by Dem
	 *          as if it does not exist. */
	const boolean 								DemEventAvailable;

	/**< @brief If this parameter is set to true, then the Prestorage of Freeze Frames
	 *          is supported by the assigned event.This parameter is useful to calculate
	 *          the buffer size. */
	const boolean 								DemFFPrestorageSupported;

	const boolean                               DemEventIsCombina;

	/**< @brief Defines the number of failure cycles for the event based fault
	 *          confirmation.If this parameter is enabled, fault confirmation
	 *          of the event is enabled accordingly. */
	const uint8 								DemEventFailureCycleCounterThreshold;

	/**< @brief This parameter is used to distinguish between SW-C and BSW events.
	 *          SW-C events are reported by Dem_SetEventStatus API and BSW events
	 *          are reported by Dem_ReportErrorStatus API */
	const Dem_EventKindType 					DemEventKind;

    /**< @brief Indicates the reporting behavior of the BSW Module (DemEventKind ==
     *          DEM_EVENT_KIND_BSW) in order to determine the size of the reporting
     *          queue.If the parameter is not defined it means REPORT_BEFORE_INIT */
	const Dem_ReportBehaviorType 				DemReportBehavior;

	/**< @brief Kind of operation cycle for the event (e.g. power cycle, driving cycle, ...) */
	const uint8 								DemOperationCycleRef;

	/**< @brief Indicate the type of debounce algorithm */
	const Dem_DebounceAlgorithmClassType 		DemDebounceAlgorithmClassType;

#if(DEM_ENABLE_CONDITION_GROUP_NUM > 0)
	/**< @brief References an enable condition group. */
	const uint8 								DemEnableConditionGroupRef;
#endif /* #if(DEM_ENABLE_CONDITION_GROUP_NUM > 0) */

#if(DEM_STORAGE_CONDITION_GROUP_NUM > 0)
	/**< @brief References  a storage condition group. */
	const uint8 								DemStorageConditionGroupRef;
#endif /* #if(DEM_STORAGE_CONDITION_GROUP_NUM > 0) */

#if(DEM_COMPONENT_NUM > 0)
    /**< @brief Specifies the priority within the component. A lower value means higher priority. */
    const uint8 								DemComponentPriority;
#endif /* #if(DEM_COMPONENT_NUM > 0) */

#if(DEM_INDICATOR_ATTRIBUTE_TOTAL_NUM > 0)
	/**< @brief Number of DemIndicatorAttribute */
	const uint8 								DemIndicatorAttributeNum;
#endif /* #if(DEM_INDICATOR_ATTRIBUTE_TOTAL_NUM > 0) */

#if(DEM_CALLBACK_EVENT_STATUS_CHANGED_NUM > 0)
    /**< @brief Number of DemCallbackEventStatusChanged */
    const uint8 								DemStatusChangedCbkNum;
#endif /* #if(DEM_CALLBACK_EVENT_STATUS_CHANGED_NUM > 0) */

#if(DEM_DTC_NUM > 0)
    /**< @brief This parameter defines the DTC configuration (typically Uds)associated
     *          with the diagnostic event.It is allowed to have events without a DTC
     *          (e.g. for ECU-internal events triggering safety reactions without being
     *          reported via diagnostic communication).The same DemDTCAttributes can be
     *          used from several events,to combine these (refer to chapter "Combination
     *          of diagnostic event"). */
    const uint16 								DemDTCRef;
#endif /* #if(DEM_DTC_NUM > 0) */

    /**< @brief Debounce algorithm class: counter based, time based,or monitor internal. */
    const uint16 								DemDebounceAlgorithmRef;

    /**< @brief Index of runtime variables which record debounce status */
    const uint16 								DemDebounceInfoIndex;

    /**< @brief Unique identifier of a diagnostic event.This parameter should not be changeable
     *          by user, because the Id should be generated by Dem itself to prevent gaps and
     *          multiple use of an Id. The events should be sequentially ordered beginning with
     *          1 and no gaps in between */
    const uint16 								DemEventId;

    /**< @brief This parameter defines a reference which points to a representative event of one
     *          group of associate events.The 'reverence event' must refer to it self. Note: One
     *          event is only allowed to be reverence to only one group of associate events */
    const uint16 								DemOBDGroupingAssociativeEventsRef;

#if(DEM_COMPONENT_NUM > 0)
    /**< @brief Reference to the monitored component. */
    const Dem_ComponentIdType 					DemComponentClassRef;
#endif /* #if(DEM_COMPONENT_NUM > 0) */

#if(DEM_INDICATOR_ATTRIBUTE_TOTAL_NUM > 0)
    /**< @brief This container contains the event specific configuration of Indicators. */
    const Dem_IndicatorAttributeType* 			DemIndicatorAttribute;
#endif /* #if(DEM_INDICATOR_ATTRIBUTE_TOTAL_NUM > 0) */

#if(DEM_CALLBACK_INIT_MFOREFNC_TOTALNUM > 0)
	/**< @brief Function name of prototype "InitMonitorForEvent" */
    const Dem_CallbackInitMForEType* 		    DemCallbackInitMForE;
#endif /* #if(DEM_CALLBACK_INIT_MFOREFNC_TOTALNUM > 0) */

#if(DEM_CALLBACK_EVENTDATA_CHANGE_NUM > 0)
    /**< @brief The presence of this container indicates that the Dem has access to an
     *          "EventDataChanged" callback. */
    const Dem_CallbackEventDataChangedType* 	DemCallbackEventDataChanged;
#endif /* #if(DEM_CALLBACK_EVENTDATA_CHANGE_NUM > 0) */

#if(DEM_CALLBACK_CLEAR_EVENT_ALLOWED_NUM > 0)
    /**< @brief The presence of this container indicates that the Dem has access to a
     *          "ClearEventAllowed" callback. */
    const Dem_CallbackClearEventAllowedType* 	DemCallbackClearEventAllowed;
#endif /* #if(DEM_CALLBACK_CLEAR_EVENT_ALLOWED_NUM > 0) */

#if(DEM_CALLBACK_EVENT_STATUS_CHANGED_NUM > 0)
    /**< @brief The presence of this container indicates, that the Dem has access to an
     *          "EventStatusChanged" callback, which the Dem will call to notify other
     *          components about the change in the status of an event. */
    const Dem_CallbackEventStatusChangedsType*  DemCallbackEventStatusChanged;
#endif /* #if(DEM_CALLBACK_EVENT_STATUS_CHANGED_NUM > 0) */
} Dem_EventParameterType;


#if(DEM_DTC_ATTRIBUTES_NUM > 0)
typedef struct
{
	/**< @brief Switch to allow aging/unlearning */
    const boolean 								DemAgingAllowed;

    /**< @brief Number of aging cycles needed to unlearn/delete the event. */
    const uint8 								DemAgingCycleCounterThreshold;

    /**< @brief Number of aging cycles needed to reset the testFailedSinceLastClear Bit */
    const uint8 								DemAgingCycleCounterThresholdForTFSLC;

    /**< @brief Priority of the event/dtc, in view of full event buffer. A lower value
     *          means higher priority. It can be mapped as Dem-internal data element.
     *          It shall be configured,if it is a part of event related data */
    const uint8 								DemDTCPriority;

    /**< @brief Significance of the event, which indicates additional information concerning
     *          fault classification and resolution. */
    const uint8	 								DemDTCSignificance;

    /**< @brief Threshold to allocate an event memory entry and to capture the Freeze Frame */
    const uint8 								DemEventMemoryEntryFdcThresholdStorageValue;

    /**< @brief Switch to enable immediate storage triggering of an according event memory
     *          entriy persistently to NVRAM. */
    const boolean 								DemImmediateNvStorage;

    /**< @brief The event destination assigns events to none, one or two origins. If no event
     *          destination is assigned to a specific event, the event is handled internally
     *          and is not visible externally to the Dcm. If more than one event destination
     *          is assigned to a specific event, the event can be present in the corresponding
     *          origins. */
    const Dem_DTCOriginType						DemMemoryDestinationRef;

#if(DEM_MIRROR_MEMORY_NUM > 0)
    /**< @brief If the value is 0, it indicates that no mirror memory allocate for the event. */
    const Dem_DTCOriginType						DemMirrorMemoryDestinationRef;
#endif /* #if(DEM_MIRROR_MEMORY_NUM > 0) */

    /**< @brief Reference to the cycle which is triggering the aging of the event. */
    const uint8 								DemAgingCycleRef;

    /**< @brief This reference defines the link to an extended data class sampler. */
    const uint16 								DemExtendedDataClassRef;

    /**< @brief These references define the links to a freeze frame class sampler. */
    const uint16 								DemFreezeFrameClassRef;

#if(DEM_TYPEOFFF_RECORD_NUMERATION == DEM_FF_RECNUM_CONFIGURED)
    /**< @brief This parameter defines the list of dedicated freeze frame record numbers
     *          associated with the diagnostic event. These record numbers are assigned
     *          to the freeze frame records (instead of calculated record numbers). */
    const uint8 								DemFreezeFrameRecNumClassRef;
#else
    /**< @brief This parameter defines the number of according freeze frame records, which can
     *          maximal be stored for this event. Therefore all these freeze frame records have
     *          the same freeze frame class.This parameter is only required for calculated record
     *          numeration */
    const uint8 								DemMaxNumberFreezeFrameRecords;
#endif /* #if(DEM_TYPEOFFF_RECORD_NUMERATION == DEM_FF_RECNUM_CONFIGURED) */

#if(DEM_J1939_SUPPORT == STD_ON)
    /**< @brief Reference to a J1939 Node */
    const uint8 								DemJ1939DTC_J1939NodeRef;

    /**< @brief These references define the links to a J1939 freeze frame class sampler */
    const uint8	 								DemJ1939ExpandedFreezeFrameClassRef;

    /**< @brief These references define the links to a J1939 freeze frame class sampler */
    const uint8 								DemJ1939FreezeFrameClassRef;
#endif /* #if(DEM_J1939_SUPPORT == STD_ON) */

#if(DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT)
    /**< @brief This reference defines the link to a WWH-OBD freeze frame class sampler. */
    const uint8 								DemWWHOBDFreezeFrameClassRef;
#endif /* #if(DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT) */
} Dem_DTCAttributesType;
#endif /* #if(DEM_DTC_ATTRIBUTES_NUM > 0) */

#if(DEM_PID_CLASS_NUM > 0)
typedef struct
{
    const Dem_DataElementClassType* 			DemPidDataElementClassRef;
    const uint8									DemPidDataElementClassRefSize;
} Dem_PidDataElementType;

typedef struct
{
	/**< @brief identifier of the PID. */
    const uint8 								DemPidIdentifier;

    /**< @brief Number of DemPidDataElementClassRef. */
    const uint8   								DemPidDataElementClassRefNum;

    /**< @brief Size of all DemPidDataElements.  */
    const uint16								DemPidElementSize;

    /**< @brief This reference contains the link to a data element class. */
    const Dem_PidDataElementType* 				DemPidDataElementRef;
} Dem_PidClassType;
#endif /* #if(DEM_PID_CLASS_NUM > 0) */

#if(DEM_J1939_SUPPORT == STD_ON)
typedef struct
{
	/**< @brief Number of references to the corresponding J1939Nm node. */
    const uint8 								DemJ1939NmNodeNum;

    /**< @brief Reference to the corresponding J1939Nm node. */
    const uint8* 								DemJ1939NmNodeRef;
}Dem_J1939NodeType;
#endif /* #if(DEM_J1939_SUPPORT == STD_ON) */


#if(DEM_DTC_NUM > 0)
typedef struct
{
	/**< @brief DTCFuncitonalUnit is a 1-byte value which identifies the corresponding basic
	 *          vehicle / system function which reports the DTC. This parameter is necessary
	 *          for the report of severity information.If this parameter is configured for no
	 *          DTC, the Dem provides no DTC functional unit information.*/
    const uint8 								DemDTCFunctionalUnit;

    /**< @brief DTC severity according to ISO 14229-1. This parameter depends on the automotive
     *          manufacturer.If it is not configured, the value is counted as 'no severity'.If
     *          this parameter is configured for no DTC, the Dem provides no DTC severity
     *          information. */
    const Dem_DTCSeverityType 					DemDTCSeverity;

    /**< @brief Unique Diagnostic Trouble Code value for UDS.(Range: 0x000000 and 0xFFFFFF are
     *          reserved for DTC groups by ISO 14229-1) */
    const uint32 								DemDtcValue;

    /**< @brief This parameter defines the DTC Attributes associated with the DemDTC. */
    const uint16 								DemDTCAttributesRef;

    /**< @brief DTC Class according to ISO 14229-1 [2013 version]. This parameter depends on the
     *          automotive manufacturer.If it is not configured, the value is marked as 'unclassified'.
     *          If this parameter is configured for no DTC, the Dem provides no DTC WWHOBD class
     *          information. */
    const uint8 								DemWWHOBDDTCClass;

    /**< @brief This parameter defines the OBD DTC configuration associated with the DemDTC.
     * 			It is allowed to have events without a OBD DTC. */
    const uint16  								DemObdDTCRef;

    /**< @brief A DTC can have any combination of the three formats (UDS, OBD, and J1939), i.e.
     * 			one, two, or three formats at the same time. The reported format depends on the
     * 			Dem_DTCFormatType (refer to chapter 8.2.1.11) or is defined by the context of
     * 			the related API. (bit0 = 1: UDS; bit1 = 1: OBD; bit2 = 1: J1939) */
    const uint8									DemDTCFormat;

    /**< @brief Indicate which dtc group is this dtc belong to */
    const uint8 								DemDtcGroupRef;
}Dem_DTCType;

#if(DEM_OBD_DTC_NUM > 0)
typedef struct
{
	/**< @brief This parameter is TRUE, when the event is affected by the Dem PTO handling. */
    const boolean 								DemConsiderPtoStatus;

#if((DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU) || (DEM_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
    /**< @brief This parameter specifies the Event OBD Readiness group for PID $01 and PID
     *          $41 computation. This parameter is only applicable for emission-related ECUs. */
    const uint8							  		DemEventOBDReadinessGroup;
#endif /* #if((DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU) || (DEM_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU)) */

    /**< @brief Unique Diagnostic Trouble Code value for OBD. */
    const uint16  								DemDtcValue;

    /**< @brief Unique Diagnostic Trouble Code value for J1939 (consisting of SPN and FMI) */
    const uint32 								DemJ1939DTCValue;
}Dem_ObdDTCType;
#endif /* #if(DEM_OBD_DTC_NUM > 0) */
#endif /* #if(DEM_DTC_NUM > 0) */

#if(DEM_COMPONENT_NUM > 0)
typedef Std_ReturnType (*DemComponentFailedCallbackFnc)(\
		Dem_ComponentIdType ComponentId,\
		boolean ComponentFailedStatus\
		);

typedef struct
{
	/**< @brief This configuration switch defines, whether the priority of
	 *          events at this component shall be ignored. */
    const boolean 								DemComponentIgnoresPriority;

    /**< @brief Number of child component which referenced. */
    const Dem_ComponentIdType					DemDemChildComponentRefNum;

    /**< @brief All immediate child components of this component. */
    const Dem_ComponentIdType* 					DemImmediateChildComponentRef;

    /**< @brief Number of parent component which referenced. */
    const Dem_ComponentIdType					DemDemParentComponentRefNum;

    /**< @brief All Parent components of this component(include immediate and ind). */
    const Dem_ComponentIdType* 					DemParentComponentRef;

    /**< @brief Specifies the function to be called on component failed status changes. */
    const DemComponentFailedCallbackFnc 		DemComponentFailedCallbackFnc;
} Dem_ComponentType;
#endif /* #if(DEM_COMPONENT_NUM > 0) */

/**
 * @req [SWS_Dem_00924] This type of the external data structure shall
 *      contain the post build initialization data for the Dem.
 */
typedef struct
{
#if(DEM_COMPONENT_NUM > 0)
	/**< @brief This container configures the monitored components and system dependencies. */
	const Dem_ComponentType* 					DemComponent;
#endif /* #if(DEM_COMPONENT_NUM > 0) */

#if(DEM_DTC_NUM > 0)
	/**< @brief This container contains the configuration (parameters) for DemUdsDTC. */
    const Dem_DTCType* 							DemDTC;
#endif /* #if(DEM_DTC_NUM > 0) */

#if(DEM_DTC_ATTRIBUTES_NUM > 0)
    /**< @brief This container contains the configuration (parameters) for DemDTCAttributes. */
    const Dem_DTCAttributesType* 				DemDTCAttributes;
#endif /* #if(DEM_DTC_ATTRIBUTES_NUM > 0) */

#if(DEM_DEBOUNCE_COUNTER_BASED_SUPPORT == STD_ON)
#if(DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM > 0)
    /**< @brief This container contains the configuration of Debounce Counter Based Class */
    const Dem_DebounceCounterBasedClassType* 	DemDebounceCounterBasedClass;
#endif /* #if(DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM > 0) */
#endif /* #if(DEM_DEBOUNCE_COUNTER_BASED_SUPPORT == STD_ON) */

#if(DEM_DEBOUNCE_TIME_BASED_SUPPORT == STD_ON)
#if(DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0)
    /**< @brief This container contains the configuration of Debounce Counter Based Class */
    const Dem_DebounceTimeBaseClassType* 		DemDebounceTimeBaseClass;
#endif /* #if(DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0) */
#endif /* #if(DEM_DEBOUNCE_TIME_BASED_SUPPORT == STD_ON) */

#if(DEM_DTR_NUM > 0)
    /**< @brief This container holds the configuration of DTRs collection. */
    const Dem_DtrsType* 						DemDtrs;
#endif /* #if(DEM_DTR_NUM > 0) */

    /**< @brief This container contains the configuration (parameters) for events. */
    const Dem_EventParameterType* 				DemEventParameter;

#if(DEM_DTC_NUM > 0)
#if(DEM_J1939_SUPPORT == STD_ON)
    /**< @brief Contains the parameters for the support of a logical J1939 node. */
    const Dem_J1939NodeType* 					DemJ1939Node;
#endif /* #if(DEM_J1939_SUPPORT == STD_ON) */

#if(DEM_OBD_DTC_NUM > 0)
    /**< @brief This container contains the configuration (parameters) for DemObdDTC. */
    const Dem_ObdDTCType* 						DemObdDTC;
#endif /* #if(DEM_OBD_DTC_NUM > 0) */
#endif /* #if(DEM_DTC_NUM > 0) */

#if(DEM_PID_CLASS_NUM > 0)
    /**< @brief This container contains the different PIDs for the single global OBD
     *          relevant freeze frame class. It is assembled out of one or several
     *          data elements. */
    const Dem_PidClassType* 					DemPidClass;
#endif /* #if(DEM_PID_CLASS_NUM > 0) */
} Dem_ConfigType;

#if((DEM_CALLBACK_DTC_STATUS_CHANGED_NUM > 0) || (DEM_CALLBACK_OBD_DTC_STATUS_CHANGED_NUM> 0)\
		|| (DEM_CALLBACK_J1939_DTC_STATUS_CHANGED_NUM > 0))
typedef Std_ReturnType (*Dem_CallbackDTCStatusChangedFncType)(\
		uint32 DTC,\
		Dem_UdsStatusByteType DTCStatusOld,\
		Dem_UdsStatusByteType DTCStatusNew\
		);
#endif /* #if((DEM_CALLBACK_DTC_STATUS_CHANGED_NUM > 0) || (DEM_CALLBACK_OBD_DTC_STATUS_CHANGED_NUM> 0)\
		|| (DEM_CALLBACK_J1939_DTC_STATUS_CHANGED_NUM > 0)) */

#if((DEM_CALLBACK_DTC_STATUS_CHANGED_NUM > 0) || (DEM_CALLBACK_OBD_DTC_STATUS_CHANGED_NUM> 0)\
		|| (DEM_CALLBACK_J1939_DTC_STATUS_CHANGED_NUM > 0))
typedef struct
{
	/**< @brief Function name of prototype "DTCStatusChanged". Note: If the
	 *          parameter DemTriggerDcmReports is enabled, this parameter
	 *          shall not be "Dcm_DemTriggerOnDTCStatus". */
	const Dem_CallbackDTCStatusChangedFncType 	DemCallbackDTCStatusChangedFnc;
}Dem_CallbackDTCStatusChangedType;
#endif /* #if((DEM_CALLBACK_DTC_STATUS_CHANGED_NUM > 0) || (DEM_CALLBACK_OBD_DTC_STATUS_CHANGED_NUM> 0)\
		|| (DEM_CALLBACK_J1939_DTC_STATUS_CHANGED_NUM > 0)) */

#if(DEM_USERDEFINE_MEMORY_NUM > 0)
typedef struct
{
	/**< @brief Maximum number of events which can be stored in the user defined memory. */
	const uint8 								DemMaxNumberEventEntryUserDefined;

	/**< @brief Identifier used by external tester to identify the User defined event memory. */
	const uint8 								DemUserDefinedMemoryIdentifier;

	Dem_MemoryEntryType*                  		DemUserDefinedMemory;
}Dem_UserDefinedMemoryType;
#endif /* #if(DEM_USERDEFINE_MEMORY_NUM > 0) */

#if((DEM_RATIO_NUM > 0) && ((DEM_J1939RATIO_SUPPORT == STD_ON)||DemOBDSupport != DEM_OBD_NO_OBD_SUPPORT))
typedef struct
{
	const uint8					DemIUMPRDenGroup;
	const uint8 				DemIUMPRGroup;
	const Dem_RatioIdType		DemRatioId;
	const uint8 				DemRatioKind;
	const Dem_EventIdType 		DemDiagnosticEventRef;
	const uint8 				DemFunctionIdRef;
	const uint8*				DemSecondaryFunctionIdRef;
	const uint16				DemSecFuncIdRefNum;
}Dem_RatioType;
#endif /* #if((DEM_RATIO_NUM > 0) && ((DEM_J1939RATIO_SUPPORT == STD_ON)||DemOBDSupport != DEM_OBD_NO_OBD_SUPPORT)) */

#if(DEM_STORAGE_CONDITION_NUM > 0)
typedef struct
{
	/**< @brief Defines the initial status for enable or disable of storage of a diagnostic event.
	 *          The value is the initialization after power up (before this condition is reported
	 *          the first time).true: storage of a diagnostic event enabled. false: storage of a
	 *          diagnostic event disabled. */
	const boolean 								DemStorageConditionStatus;

	/**< @brief Specifies the reference to an event which is stored to event memory and supports
	 *          failure analysis. */
	const Dem_EventIdType				 		DemStorageConditionReplacementEventRef;
}Dem_StorageConditionType;
#endif /* #if(DEM_STORAGE_CONDITION_NUM > 0) */

typedef struct
{
	/**< @brief If DemOperationCycleAutomaticEnd is configured to TRUE, Dem shall automatically
	 *          end the driving cycle at either Dem_Shutdown() or Dem_Init(). */
	const boolean 								DemOperationCycleAutomaticEnd;

	/**< @brief The auto start property defines if the operation cycles is automatically (re-)
	 *          started during Dem_PreInit. */
	const boolean 								DemOperationCycleAutostart;

	/**< @brief Operation cycles types for the Dem to be supported by cycle-state APIs. */
	const Dem_OperationCycleEnumType  			DemOperationCycleType;

	/**< @brief This parameters value is used, together with the aggregating container, to define
	 *          a symbolic name of the operation cycle. */
	const uint8 								DemOperationCycleId;
}Dem_OperationCycleType;

#if(DEM_J1939_SUPPORT == STD_ON)

typedef struct
{
	const uint8  								DemSPNDataElementClassRef;
	const uint8 								SPNDataSize;
	const uint32 								DemSPNId;
}Dem_SPNClassType;

typedef struct
{
	const uint8 								SPNClassRefNum;
	const uint16  								FFDataSize;
	const uint8* 								SPNClassStart;
}Dem_J1939FreezeFrameType;


typedef struct
{
	const Dem_SPNClassType* 					DemSPNClasses;

	const Dem_J1939FreezeFrameType* 			DemJ1939FreezeFrameClasses;

#if(DEM_CALLBACK_J1939_DTC_STATUS_CHANGED_NUM > 0)
	const Dem_CallbackDTCStatusChangedType*		DemCallbackJ1939DTCStatusChanged;
#endif /* #if(DEM_CALLBACK_J1939_DTC_STATUS_CHANGED_NUM > 0) */
} Dem_GeneralJ1939Type;
#endif /* #if(DEM_J1939_SUPPORT == STD_ON) */

#if(DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT)
typedef struct
{
#if(DEM_GENERAL_OBD_CSDATAREF_NUM > 0)
	const Dem_ExternalCSDataElementClassType*	DemExternalCSDataElementClass;
#endif /* #if(DEM_GENERAL_OBD_CSDATAREF_NUM > 0) */

#if(DEM_GENERAL_OBD_SRDATAREF_NUM > 0)
	const Dem_ExternalSRDataElementClassType*	DemExternalSRDataElementClass;
#endif /* #if(DEM_GENERAL_OBD_SRDATAREF_NUM > 0) */

#if(DEM_GENERAL_OBD_INTERDATAREF_NUM > 0)
	const Dem_InternalDataElementClassType*		Dem_InternalDataElementClass;
#endif /* #if(DEM_GENERAL_OBD_INTERDATAREF_NUM > 0) */
}Dem_GeneralOBDInputType;

typedef struct
{
	const uint8 DemOBDInputAcceleratorPedalInformation;

	const uint8 DemOBDInputAmbientPressure;

	const uint8 DemOBDInputAmbientTemperature;

	const uint8 DemOBDInputDistanceInformation;

	const uint8 DemOBDInputEngineSpeed;

	const uint8 DemOBDInputEngineTemperature;

	const uint8 DemOBDInputProgrammingEvent;

	const uint8 DemOBDInputVehicleSpeed;

	const uint8 DemOBDTimeSinceEngineStart;

#if(DEM_GENERAL_OBD_CSDATAREF_NUM+DEM_GENERAL_OBD_SRDATAREF_NUM+DEM_GENERAL_OBD_INTERDATAREF_NUM > 0)
	const Dem_GeneralOBDInputType* DemOBDDataElement;
#endif /* #if(DEM_GENERAL_OBD_CSDATAREF_NUM+DEM_GENERAL_OBD_SRDATAREF_NUM+DEM_GENERAL_OBD_INTERDATAREF_NUM > 0) */

#if(DEM_CALLBACK_OBD_DTC_STATUS_CHANGED_NUM > 0)
	const Dem_CallbackDTCStatusChangedType* Dem_CallbackOBDDTCStatusChangeds;
#endif /* #if(DEM_CALLBACK_OBD_DTC_STATUS_CHANGED_NUM > 0) */
}Dem_GeneralOBDType;
#endif /* #if(DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT) */

typedef struct
{
#if(DEM_ENABLE_CONDITION_NUM > 0)
	/**< @brief This container contains the configuration (parameters) for enable conditions. */
	const uint8* 								DemEnableCondition;
#endif /* #if(DEM_ENABLE_CONDITION_NUM > 0) */

#if(DEM_ENABLE_CONDITION_GROUP_NUM > 0)
	/**< @brief This container contains the configuration (parameters) for enable condition groups. */
	const uint8 								(*DemEnableConditionGroup)[DEM_ENABLE_CONDITION_NUM_BYTE];
#endif /* #if(DEM_ENABLE_CONDITION_GROUP_NUM > 0) */

#if(DEM_DID_CLASS_NUM > 0)
	/**< @brief This container contains the configuration (parameters) for a data
	 *          Id class. It is assembled out of one or several data elements. */
	const Dem_DidClassType* 					DemDidClass;
#endif /* #if(DEM_DID_CLASS_NUM > 0) */

#if(DEM_J1939_SUPPORT == STD_ON)
	/**< @brief This container contains the general J1939-specific configuration (parameters)
	 *          of the Dem module. If the container exists the J1939 support is enabled. */
	const Dem_GeneralJ1939Type* 				DemGeneralJ1939;
#endif /* #if(DEM_J1939_SUPPORT == STD_ON) */

#if(DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT)
	/**< @brief This container contains the general OBD-specific configuration (parameters)
	 *          of the Dem module. */
	const Dem_GeneralOBDType* 					DemGeneralOBD;
#endif /* #if(DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT) */

	/**< @brief This container holds all parameters that are relevant to configure an operation cycle. */
	const Dem_OperationCycleType* 				DemOperationCycle;

#if((DEM_RATIO_NUM > 0) && ((DEM_J1939RATIO_SUPPORT == STD_ON)||(DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT)))
	/**< @brief This container contains the OBD-specific in-use-monitor performance ratio
	 *          configuration.It is related to a specific event, a FID, and an IUMPR group. */
	const Dem_RatioType* 						DemRatio;
#endif /* #if((DEM_RATIO_NUM > 0) && (DEM_J1939RATIO_SUPPORT == STD_ON)) */

#if(DEM_STORAGE_CONDITION_NUM > 0)
	/**< @brief This container contains the configuration (parameters) for storage conditions. */
	const Dem_StorageConditionType* 			DemStorageCondition;
#endif /* #if(DEM_STORAGE_CONDITION_NUM > 0) */

#if(DEM_STORAGE_CONDITION_GROUP_NUM > 0)
	/**< @brief This container contains the configuration (parameters) for storage condition groups. */
	const uint8 		                        (*DemStorageConditionGroup)[DEM_STORAGE_CONDITION_NUM_BYTE];
#endif /* #if(DEM_STORAGE_CONDITION_GROUP_NUM > 0) */

#if(DEM_CALLBACK_DTC_STATUS_CHANGED_NUM > 0)
	/**< @brief The presence of this container indicates,that the Dem has access to
	 *          a 'DTCStatusChanged' callback,which the Dem will call to notify other
	 *          components about the change in the status of a DTC. */
	const Dem_CallbackDTCStatusChangedType* 	DemCallbackDTCStatusChanged;
#endif /* #if(DEM_CALLBACK_DTC_STATUS_CHANGED_NUM > 0) */

#if(DEM_DATA_ELEMENT_CLASS_NUM > 0)
	/**< @brief This container contains the configuration (parameters) for an internal/external
	 *          data element class. */
	const Dem_DataElementClassType* 			DemDataElementClass;
#endif /* #if(DEM_DATA_ELEMENT_CLASS_NUM > 0) */

#if(DEM_EXTENDED_DATA_CLASS_NUM > 0)
	/**< @brief This container contains the configuration (parameters) for an internal/external
	 *          data element class. */
	const Dem_ExtendedDataClassType* 			DemExtendedDataClass;
#endif /* #if(DEM_EXTENDED_DATA_CLASS_NUM > 0) */

#if(DEM_EXTENDED_DATA_RECORD_CLASS_NUM > 0)
	/**< @brief This container contains the configuration (parameters) for an extended
	 *          data record class.It is assembled out of one or several data elements */
	const Dem_ExtendedDataRecordClassType* 		DemExtendedDataRecordClass;
#endif /* #if(DEM_EXTENDED_DATA_RECORD_CLASS_NUM > 0) */

#if(DEM_FREEZE_FRAME_CLASS_NUM > 0)
	/**< @brief This container contains the combinations of DIDs for a non OBD2 and WWH-OBD
	 *          relevant freeze frame class */
	const Dem_FreezeFrameClassType* 			DemFreezeFrameClass;
#endif /* #if(DEM_FREEZE_FRAME_CLASS_NUM > 0) */

#if(DEM_FREEZE_FRAME_RECORD_CLASS_NUM > 0)
	/**< @brief This container contains a list of dedicated, different freeze frame record numbers */
	const Dem_FreezeFrameRecordClassType* 		DemFreezeFrameRecordClass;
#endif /* #if(DEM_FREEZE_FRAME_RECORD_CLASS_NUM > 0) */

#if(DEM_FREEZE_FRAME_REC_NUM_CLASS_NUM > 0)
	/**< @brief This container contains a list of dedicated, different freeze frame record numbers
	 *          assigned to an event. The order of record numbers in this list is assigned to the
	 *          chronological order of the according freeze frame records. */
	const Dem_FreezeFrameRecNumClassType* 		DemFreezeFrameRecNumClass;
#endif /* #if(DEM_FREEZE_FRAME_REC_NUM_CLASS_NUM > 0) */

#if(DEM_GROUP_OF_DTC_NUM > 0)
	/**< @brief This container contains the configuration (parameters) for DTC groups. */
	const uint32* 								DemGroupOfDTC;
#endif /* #if(DEM_GROUP_OF_DTC_NUM > 0) */

#if(DEM_NVRAM_BLOCKID_NUM > 0)
	/**< @brief This container contains the configuration (parameters) for a non-volatile
	 *          memory block, which is used from the Dem. If no permanent storage of event
	 *          memory entries is required, no block needs to be configured. */
	const uint16* 								DemNvRamBlockId;
#endif /* #if(DEM_NVRAM_BLOCKID_NUM > 0) */

#if(DEM_USERDEFINE_MEMORY_NUM > 0)
	/**< @brief This container contains the user defined event memory specific parameters of
	 *          the Dem module. */
	const Dem_UserDefinedMemoryType* 			DemUserDefinedMemory;
#endif /* #if(DEM_USERDEFINE_MEMORY_NUM > 0) */
}Dem_GeneralType;

/**
 * @brief	Record the information required for calculating IUMPR.
 */
#if(DEM_RATIO_NUM > 0)
typedef struct
{
	/**< @brief The numerator of IUMPR. */
	uint16		DemNumerator;

	/**< @brief The denominator of IUMPR. */
	uint16		DemDenominator;

	/**< @brief The lock of Numerator.*/
	boolean		DemNumeratorlock;

	/**< @brief The lock of Denominator. */
	boolean		DemDenominatorlock;
} Dem_IUMPRType;
#endif /* #if(DEM_RATIO_NUM > 0) */

/**
 * @brief	The input parameter of API Dem_GetVehicleInfo.
 * @details	Indicate which vehicle information API Dem_GetVehicleInfo needs to get by parameter.
 */
typedef enum
{
	/**< @brief Input variable for the Time Since Engine Start information. */
	DEM_OBD_TIME_SINCE_ENGINE_START,

	/**< @brief Input variable for the vehicle speed. */
	DEM_OBD_INPUT_VEHICLE_SPEED,

	/**< @brief Input variable for the distance information. */
	DEM_OBD_INPUT_DISTANCE_INFORMATION
} Dem_VehicleDataType;
/*====================================================================================================*
 *                                    GLOBAL VARIABLE DECLARATIONS
 *====================================================================================================*/

/* Add code here */

/*====================================================================================================*
 *                                        FUNCTION PROTOTYPES
 *====================================================================================================*/

/* Add code here */

#ifdef __cplusplus
}
#endif

#endif /* DEM_TYPES_H */
/** @} */
