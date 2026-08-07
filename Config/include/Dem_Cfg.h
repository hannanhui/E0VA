/**
 * @file        Dem_Cfg.h
 * @brief       AUTOSAR Dem - Dem driver header file.
 * @details     Dem driver header file, containing the Autosar API specification and
 *              other variables and functions that are exported by the Dem driver.
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

#ifndef DEM_CFG_H
#define DEM_CFG_H

#ifdef __cplusplus
extern "C"{
#endif

/*====================================================================================================*
 *                                           INCLUDE FILES                                          
 *====================================================================================================*/

/* Add code here */

/*====================================================================================================*
 *                                  HEADER FILE VERSION INFORMATION                                 
 *====================================================================================================*/

#define DEM_CFG_VENDOR_ID             				(0U)
#define DEM_CFG_AR_RELEASE_MAJOR_VERSION      		(4U)
#define DEM_CFG_AR_RELEASE_MINOR_VERSION      		(2U)
#define DEM_CFG_AR_RELEASE_REVISION_VERSION         (2U)
#define DEM_CFG_SW_MAJOR_VERSION      				(1U)
#define DEM_CFG_SW_MINOR_VERSION      				(2U)
#define DEM_CFG_SW_PATCH_VERSION      				(0U)

/*====================================================================================================*
 *                                         FILE VERSION CHECKS                                      
 *====================================================================================================*/

/* Add code here */

/*====================================================================================================*
 *                                             CONSTANTS                                            
 *====================================================================================================*/

/* Add code here */

/*====================================================================================================*
 *                                         DEFINES AND MACROS                                       
 *====================================================================================================*/

#define DEM_CONF_PB   extern CONST(Dem_ConfigType, AUTOMATIC) Dem_Config;

/* DemAgingCycleCounterProcessing */
#define DEM_AGINGCYCLE_COUNTER_PROCESSING				        DEM_PROCESS_AGINGCTR_INTERN

/* DemAgingRequieresTestedCycle */
#define DEM_AGING_REQUIERES_TESTED_CYCLE			            STD_OFF

/* DemAvailabilitySupport */
#define DEM_AVAILABILITY_SUPPORT					            DEM_NO_AVAILABILITY

/* DemBswErrorBufferSize */
#define DEM_BSW_ERROR_BUFFERSIZE						        (5u)

/* DemClearDTCBehavior */
#define DEM_CLEAR_DTC_BEHAVIOR							        DEM_CLRRESP_NONVOLATILE_FINISH

/* DemClearDTCLimitation */
#define DEM_CLEARDTC_LIMITATION	                                DEM_ALL_SUPPORTED_DTCS

/* DemDataElementDefaultEndianness */
#define DEM_DATAELEMENT_DEFAULT_ENDIANNESS                      OPAQUE

/* DemDebounceCounterBasedSupport */
#define DEM_DEBOUNCE_COUNTER_BASEDSUPPORT                       STD_OFF

/* DemDebounceTimeBasedSupport */
#define DEM_DEBOUNCE_TIMER_BASEDSUPPORT                         STD_OFF

/* DemDevErrorDetect */
#define DEM_DEV_ERROR_DETECT							        STD_ON

/* DemDtcStatusAvailabilityMask */
#define DEM_DTCSTATUS_AVAILABILITY_MASK                         (0xFFu)

/* DemEnvironmentDataCapture */
#define DEM_ENVIRONMENT_DATA_CAPTURE					        DEM_CAPTURE_SYNCHRONOUS_TO_REPORTING

/* DemEventCombinationSupport */
#define DEM_EVENT_COMBINATION_SUPPORT                           DEM_EVCOMB_DISABLED

/* DemEventDisplacementStrategy */
#define DEM_EVENT_DISPLACEMENT_STRATEGY	                        DEM_DISPLACEMENT_FULL

/* DemEventMemoryEntryStorageTrigger */
#define DEM_EVENTMEMORY_ENTRYSTORAGE_TRIGGER                    DEM_TRIGGER_ON_TEST_FAILED

/* DemGeneralInterfaceSupport */
#define DEM_GENERAL_INTERFACE_SUPPORT                           STD_OFF

/* DemImmediateNvStorageLimit */
#define DEM_IMMEDIATE_NVSTORAGE_LIMIT	                        (0u)

/* DemMILIndicatorRef */
#define DEM_MILINDICATOR_REF						            (0xFFu)

/* DemMaxNumberEventEntryEventBuffer */
#define DEM_MAX_NUMBER_EVENTENTRY_EVENTBUFFER                    (0u)

/* DemMaxNumberEventEntryPermanent */
#define DEM_MAX_NUMBER_EVENTENTRY_PERMANENT                     (0u)

/* DemMaxNumberPrestoredFF */   
#define DEM_MAXNUMBER_PRESTORED_FF	                            (0u)

/* DemOBDSupport */
#define DEM_OBD_SUPPORT	                                        DEM_OBD_NO_OBD_SUPPORT

/* DemOccurrenceCounterProcessing */
#define DEM_OCCIRRENCE_COUNTER_PROCESSING                       DEM_PROCESS_OCCCTR_TF

/* DemOperationCycleStatusStorage */
#define DEM_OPERATIONCYCLE_STATUS_STORAGE                       STD_OFF

/* DemPTOSupport */
#define DEM_PTO_SUPPORT                                         STD_OFF

/* DemResetConfirmedBitOnOverflow */
#define DEM_RESSET_CONFIRMEDBIT_ONOVERFLOW                      STD_ON

/* DemStatusBitHandlingTestFailedSinceLastClear */
#define DEM_STATUS_BIT_HANDLING_TEST_FAILED_SINCE_LAST_CLEAR    DEM_STATUS_BIT_NORMAL

/* DemStatusBitStorageTestFailed */
#define DEM_STATUS_BITSTORAGE_TESTFAILED                        STD_OFF

/* DemSuppressionSupport */
#define DEM_SUPPRESSION_SUPPORT                                 DEM_NO_SUPPRESSION

/* DemTaskTime */
#define DEM_TASK_TIME                                           (50u)

/* DemDcmSupport */
#define DEM_DCM_ENABLE                                          STD_ON

/* DemTriggerDcmReports */
#define DEM_TRIGGER_DCM_REPORTS							        STD_ON

/* DemTriggerDltReports */
#define DEM_TRIGGER_DLT_REPORTS							        STD_OFF

/* DemTriggerFiMReports */
#define DEM_TRIGGER_FIM_REPORTS							        STD_OFF

/* DemTriggerMonitorInitBeforeClearOk */
#define DEM_TRIGGER_MONITORINIT_BEFORECLEAROK                   STD_OFF

/* DemTypeOfDTCSupported */
#define DEM_TYPEOFDTC_SUPPORTED	                                DEM_DTC_TRANSLATION_ISO14229_1

/* DemTypeOfFreezeFrameRecordNumeration */
#define DEM_TYPEOFFF_RECORD_NUMERATION                          DEM_FF_RECNUM_CONFIGURED

/* DemVersionInfoApi */
#define DEM_VERSION_INFO_API                                    STD_OFF

/* Number of DemEnableCondition */
#define DEM_ENABLE_CONDITION_NUM						        (0u)

/* Number of DemEnableCondition to byte */
#define DEM_ENABLE_CONDITION_NUM_BYTE					        (0u)

/* Number of DemEnableConditionGroup */
#define DEM_ENABLE_CONDITION_GROUP_NUM                          (0u)

/* Number of DemDidClass */
#define DEM_DID_CLASS_NUM                                       (0u)

/* Indicate J1939 if support or not */
#define DEM_J1939_SUPPORT                                       STD_OFF

/* Number of DemRatio */
#define DEM_RATIO_NUM                                           (0u)

/* Number of DemStorageCondition */
#define DEM_STORAGE_CONDITION_NUM                               (0u)

/* Number of DemStorageCondition to byte */
#define DEM_STORAGE_CONDITION_NUM_BYTE                          (0u)

/* Number of DemStorageConditionGroup */
#define DEM_STORAGE_CONDITION_GROUP_NUM	                        (0u)

/* Number of DemCallbackDTCStatusChanged */
#define DEM_CALLBACK_DTC_STATUS_CHANGED_NUM                     (0u)

/* Number of DemDataElementClass */
#define DEM_DATA_ELEMENT_CLASS_NUM                              (0u)

/* Number of DemInternalDataElementClass */
#define DEM_INTERNAL_DATA_ELEMENT_NUM                           (0u)

/* Number of DemExternalSRDataElementClass */
#define DEM_EXTERNALSRDATA_ELEMENT_NUM                          (0u)

/* Number of DemExternalCSDataElementClass */
#define DEM_EXTERNALCSDATA_ELEMENT_NUM                          (0u)

/* Number of DemExtendedDataClass */
#define DEM_EXTENDED_DATA_CLASS_NUM	                            (0u)

/* Number of DemExtendedDataRecordClass */
#define DEM_EXTENDED_DATA_RECORD_CLASS_NUM                      (0u)

/* Number of DemFreezeFrameClass */
#define DEM_FREEZE_FRAME_CLASS_NUM	                            (0u)

/* Number of DemFreezeFrameRecordClass */
#define DEM_FREEZE_FRAME_RECORD_CLASS_NUM	                    (0u)

/* Number of DemFreezeFrameRecNumClass */
#define DEM_FREEZE_FRAME_REC_NUM_CLASS_NUM                      (0u)

/* Number of DemGroupOfDTC */
#define DEM_GROUP_OF_DTC_NUM                                    (0u)

/* Number of DemGroupOfDTC to byte */
#define DEM_GROUP_OF_DTC_NUM_BYTE                               (0u)

/* Number of DemNvRamBlockId */
#define DEM_NVRAM_BLOCKID_NUM                                   (2u) 

/* Number of DemUserDefinedMemory */
#define DEM_USERDEFINE_MEMORY_NUM                               (0u)

/* Number of DemOperationCycle */
#define DEM_OPERATION_CYCLE_NUM	                                (1u)

/* Number of DemOperationCycle to byte */
#define DEM_OPERATION_CYCLE_NUM_BYTE                            (1u)

/* Number of DemComponent */
#define DEM_COMPONENT_NUM                                       (0u)

/* Number of DemComponent to byte */
#define DEM_COMPONENT_NUM_BYTE									(0u)

/* Number of DemDTC */
#define DEM_DTC_NUM		                                        (0u)									

/* Number of DemDTC to byte */
#define DEM_DTC_NUM_BYTE                                        (0u)

/* Number of combine dtc */
#define DEM_COMBINA_DTC_NUM                                     (0u)

/* Number of DemDTCAttributes */
#define DEM_DTC_ATTRIBUTES_NUM                                  (0u)

/* Switch of debounce counter based */
#define DEM_DEBOUNCE_COUNTER_BASED_SUPPORT                      STD_OFF

/* Number of DemDebounceCounterBasedClass */
#define DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM                    (0u)

/* Number of events which use debounce counter */   
#define DEM_DEBOUNCE_COUNTER_BASED_EVENT_NUM                    (0u)      

/* Switch of debounce timer based */
#define DEM_DEBOUNCE_TIME_BASED_SUPPORT                         STD_OFF

/* Number of DemDebounceTimeBaseClass */
#define DEM_DEBOUNCE_TIME_BASE_CLASS_NUM                        (0u)

/* Number of events which use debounce timer */
#define DEM_DEBOUNCE_TIME_BASED_EVENT_NUM                       (0u)      

/* Number of events which use debounce monitor */
#define DEM_DEBOUNCE_MONITOR_INTERNAL_EVENT_NUM                 (0u)      

/* Number of DemEventParameter */
#define DEM_EVENT_PARAMETER_NUM	                                (1u)

/* Total number of DemIndicatorAttribute */
#define DEM_INDICATOR_ATTRIBUTE_TOTAL_NUM                       (0u)

/* Number of DemCallbackEventStatusChanged */
#define DEM_CALLBACK_EVENT_STATUS_CHANGED_NUM                   (0u)

#define DEM_CALLBACK_INIT_MFOREFNC_TOTALNUM	                    (0u)

/* Number of DemCallbackEventDataChangedFnc */
#define DEM_CALLBACK_EVENTDATA_CHANGE_NUM                       (0u)

/* Number of DemCallbackClearEventAllowed */
#define DEM_CALLBACK_CLEAR_EVENT_ALLOWED_NUM                    (0u)

#define DEM_NVRAM_DEBOUNCE_INFO_NUM                             (0u)

#define DEM_MAX_NUMBER_FF_RECORDS                               (0u)

#define DEM_EVENT_QUEUE_SIZE 						            (DEM_BSW_ERROR_BUFFERSIZE + DEM_MAX_NUMBER_EVENTENTRY_EVENTBUFFER)

#define DEM_MIRROR_MEMORY_NUM									(0u)

/* Emission Dtc num */
#define DEM_DTC_EMISSION_REL_NUM                                (0u)

/* Number of OBD kind DTC */
#define DEM_OBD_KIND_DTC_NUM									(0u)

/* Number of J1939 kind DTC */
#define DEM_J1939_KIND_DTC_NUM                                  (0u)

/* DemMaxNumberEventEntryPrimary */
#define DEM_MAX_NUMBER_EVENTENTRY_PRIMARY                       (1u)

/* Number of DemIndicator */
#define DEM_INDICATOR_NUM                                       (0u)     

#define DEM_FREEZE_FRAME_MAX_LEN                                (0u)

#define DEM_EXTENDED_DATA_MAX_LEN                               (0u)

#define DEM_MAX_NUMBER_EXT_REC                                  (0u)

#define DEM_EXTENDED_DATA_REC_MAX_LEN                           (0u)

#define DemConf_DemEventParameter_DemEventParameter_0  (1u)




#define DemConf_DemOperationCycle_DemOperationCycle_0  (0u)

/***************OBD****************/
/* Number of DemObdDTC */
#define DEM_OBD_DTC_NUM                                         (0u)

/* Number of DemDtr */
#define DEM_DTR_NUM												(0u)

/* Number of DemSecondaryFunctionIdRef */
#define DEM_SECFUNCIDREF_NUM									(0u)

/* Number of DemPidClass */
#define DEM_PID_CLASS_NUM                                       (0u)

/* Size of DemPidClass(uint8) */
#define DEM_PID_CLASS_SIZE										(0u)

/* Number of DemPidDataElement */
#define DEM_PID_DATA_ELEMENT_NUM								(0)

/* Max length of DemPidDataElement */
#define DEM_PID_DATA_MAX_LEN									(0u)

/* DemOBDCentralizedPID21Handling */
#define DEM_OBDCENTRALIZED_PID21HANDLING   						FALSE

/* DemOBDCentralizedPID31Handling */
#define DEM_OBDCENTRALIZED_PID31HANDLING   						FALSE

/* DemOBDEventDisplacement */
#define DEM_OBDEVENT_DISPLACEMENT          						STD_OFF

/* DemOBDCompliancy */
#define DEM_OBD_COMPLIANCY          							(0u)

/* DemOBDEngineType */
#define DEM_OBDENGINE_TYPE										(0xFFu)

#define DEM_GENERAL_OBD_CSDATAREF_NUM							(0u)

#define DEM_GENERAL_OBD_SRDATAREF_NUM							(0u)

#define DEM_GENERAL_OBD_INTERDATAREF_NUM						(0u)

#define DEM_CALLBACK_OBD_DTC_STATUS_CHANGED_NUM				    (0u)

/***************J1939****************/
/* DemRedStopLampIndicatorRef */
#define DEM_REDSTOPLAMPINDICATOR_REF							(0xFFu)

/* DemAmberWarningLampIndicatorRef */
#define DEM_AMBERWARNINGLAMPINDICATOR_REF						(0xFFu)

/* DemProtectLampIndicatorRef */
#define DEM_PROTECTLAMPINDICATOR_REF							(0xFFu)

/* DemJ1939ClearDtcSupport */
#define DEM_J1939CLEARDTC_SUPPORT		   						(STD_OFF)

/* DemJ1939Dm31Support */
#define DEM_J1939DM31_SUPPORT		       						(STD_OFF)

/* DemJ1939ExpandedFreezeFrameSupport */
#define DEM_J1939EXPANDEDFREEZEFRAME_SUPPORT 					(STD_OFF)

/* DemJ1939FreezeFrameSupport */
#define DEM_J1939FREEZEFRAME_SUPPORT		    				(STD_OFF)

/* DemJ1939RatioSupport */
#define DEM_J1939RATIO_SUPPORT		       						(STD_OFF)

/* DemJ1939Readiness1Support */
#define DEM_J1939READINESS1_SUPPORT		        				(STD_OFF)

/* DemJ1939Readiness2Support */
#define DEM_J1939READINESS2_SUPPORT		        				(STD_OFF)

/* DemJ1939Readiness3Support */
#define DEM_J1939READINESS3_SUPPORT		       					(STD_OFF)

/* DemJ1939ReadingDtcSupport */
#define DEM_J1939READINGDTC_SUPPORT		       					(STD_OFF)

/* DemJ1939FreezeFrameClass */
#define DEM_J1939_FREEZE_FRAME_CLASS_NUM						(0u)

/* DemSPNClass */
#define DEM_SPNCLASS_NUM										(0u)

#define DEM_CALLBACK_J1939_DTC_STATUS_CHANGED_NUM				(0u)

#define DEM_FREEZEFRAME_ENABLE									(STD_OFF)

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

/* Add code here */

/*====================================================================================================*
 *                                        FUNCTION PROTOTYPES                                       
 *====================================================================================================*/

/* Add code here */

#ifdef __cplusplus
}
#endif

#endif /* DEM_CFG_H */
/** @} */
