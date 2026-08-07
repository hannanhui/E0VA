/*============================================================================*/
/*  Copyright (C) iSOFT   (2020), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Rte_Type.h>
 *  @brief      <>
 *  
 *  <MCU:TC233>
 *  
 *  @author     <>
 *  @date       <2021-12-22 15:38:09>
 */
/*============================================================================*/

/* Rte_Type.h */

#ifndef RTE_TYPE_H
#define RTE_TYPE_H

/*******************************************************************************
 **                        Revision Control History                           **
******************************************************************************/

/*******************************************************************************
 **                        Version Information                                **
******************************************************************************/

/*******************************************************************************
 **                        Include Section                                    **
******************************************************************************/
#include "Rte.h"

/*******************************************************************************
 **                        Global Variable Definitions                        **
******************************************************************************/

typedef void * Rte_Instance;

typedef boolean Boolean;

/**************************************/


/**************************************/
//
//#define _DEFINED_TYPEDEF_FOR_Boolean_
//
//typedef uint8 Dem_DebounceResetStatusType;
//#ifndef DEM_DEBOUNCE_STATUS_FREEZE
//#define DEM_DEBOUNCE_STATUS_FREEZE ((Dem_DebounceResetStatusType)0x00)
//#endif /*DEM_DEBOUNCE_STATUS_FREEZE*/
//#ifndef DEM_DEBOUNCE_STATUS_RESET
//#define DEM_DEBOUNCE_STATUS_RESET ((Dem_DebounceResetStatusType)0x01)
//#endif /*DEM_DEBOUNCE_STATUS_RESET*/
//
//
//
//#define _DEFINED_TYPEDEF_FOR_Dem_DebounceResetStatusType_
//
//typedef uint8 Dem_DebouncingStateType;
//#ifndef DEM_TEMPORARILY_DEFECTIVE
//#define DEM_TEMPORARILY_DEFECTIVE ((Dem_DebouncingStateType)0x01)
//#endif /*DEM_TEMPORARILY_DEFECTIVE*/
//#ifndef DEM_FINALLY_DEFECTIVE
//#define DEM_FINALLY_DEFECTIVE ((Dem_DebouncingStateType)0x02)
//#endif /*DEM_FINALLY_DEFECTIVE*/
//#ifndef DEM_TEMPORARILY_HEALED
//#define DEM_TEMPORARILY_HEALED ((Dem_DebouncingStateType)0x04)
//#endif /*DEM_TEMPORARILY_HEALED*/
//#ifndef DEM_TEST_COMPLETE
//#define DEM_TEST_COMPLETE ((Dem_DebouncingStateType)0x08)
//#endif /*DEM_TEST_COMPLETE*/
//#ifndef DEM_DTR_UPDATE
//#define DEM_DTR_UPDATE ((Dem_DebouncingStateType)0x10)
//#endif /*DEM_DTR_UPDATE*/
//
//
//
//#define _DEFINED_TYPEDEF_FOR_Dem_DebouncingStateType_
//
//typedef uint8 Dem_DTCFormatType;
//#ifndef DEM_DTC_FORMAT_OBD
//#define DEM_DTC_FORMAT_OBD ((Dem_DTCFormatType)0)
//#endif /*DEM_DTC_FORMAT_OBD*/
//#ifndef DEM_DTC_FORMAT_UDS
//#define DEM_DTC_FORMAT_UDS ((Dem_DTCFormatType)1)
//#endif /*DEM_DTC_FORMAT_UDS*/
///*#ifndef DEM_DTC_FORMAT_J1939
//#define DEM_DTC_FORMAT_J1939 ((Dem_DTCFormatType)2)
//#endif *//*DEM_DTC_FORMAT_J1939*/
//
//
//
//#define _DEFINED_TYPEDEF_FOR_Dem_DTCFormatType_
//
//typedef uint8 Dem_DTCKindType;
//#ifndef DEM_DTC_KIND_ALL_DTCS
//#define DEM_DTC_KIND_ALL_DTCS ((Dem_DTCKindType)0x01)
//#endif /*DEM_DTC_KIND_ALL_DTCS*/
//#ifndef DEM_DTC_KIND_EMISSION_REL_DTCS
//#define DEM_DTC_KIND_EMISSION_REL_DTCS ((Dem_DTCKindType)0x02)
//#endif /*DEM_DTC_KIND_EMISSION_REL_DTCS*/
//
//
//
//#define _DEFINED_TYPEDEF_FOR_Dem_DTCKindType_
//
//typedef uint8 Dem_DTCOriginType;
//#ifndef DEM_DTC_ORIGIN_PRIMARY_MEMORY
//#define DEM_DTC_ORIGIN_PRIMARY_MEMORY ((Dem_DTCOriginType)0x01)
//#endif /*DEM_DTC_ORIGIN_PRIMARY_MEMORY*/
//#ifndef DEM_DTC_ORIGIN_MIRROR_MEMORY
//#define DEM_DTC_ORIGIN_MIRROR_MEMORY ((Dem_DTCOriginType)0x02)
//#endif /*DEM_DTC_ORIGIN_MIRROR_MEMORY*/
//#ifndef DEM_DTC_ORIGIN_PERMANENT_MEMORY
//#define DEM_DTC_ORIGIN_PERMANENT_MEMORY ((Dem_DTCOriginType)0x03)
//#endif /*DEM_DTC_ORIGIN_PERMANENT_MEMORY*/
//
//
//
//#define _DEFINED_TYPEDEF_FOR_Dem_DTCOriginType_
//
//typedef uint16 Dem_EventIdType;
//#define Dem_EventIdType_LowerLimit 0
//#define Dem_EventIdType_UpperLimit 65535
//
//
//
//#define _DEFINED_TYPEDEF_FOR_Dem_EventIdType_
//
//typedef uint8 Dem_EventStatusType;
//#ifndef DEM_EVENT_STATUS_PASSED
//#define DEM_EVENT_STATUS_PASSED ((Dem_EventStatusType)0x00)
//#endif /*DEM_EVENT_STATUS_PASSED*/
//#ifndef DEM_EVENT_STATUS_FAILED
//#define DEM_EVENT_STATUS_FAILED ((Dem_EventStatusType)0x01)
//#endif /*DEM_EVENT_STATUS_FAILED*/
//#ifndef DEM_EVENT_STATUS_PREPASSED
//#define DEM_EVENT_STATUS_PREPASSED ((Dem_EventStatusType)0x02)
//#endif /*DEM_EVENT_STATUS_PREPASSED*/
//#ifndef DEM_EVENT_STATUS_PREFAILED
//#define DEM_EVENT_STATUS_PREFAILED ((Dem_EventStatusType)0x03)
//#endif /*DEM_EVENT_STATUS_PREFAILED*/
//#ifndef DEM_EVENT_STATUS_FDC_THRESHOLD_REACHED
//#define DEM_EVENT_STATUS_FDC_THRESHOLD_REACHED ((Dem_EventStatusType)0x04)
//#endif /*DEM_EVENT_STATUS_FDC_THRESHOLD_REACHED*/
//
//
//
//#define _DEFINED_TYPEDEF_FOR_Dem_EventStatusType_
//
//typedef uint8 Dem_OperationCycleStateType;
//#ifndef DEM_CYCLE_STATE_START
//#define DEM_CYCLE_STATE_START ((Dem_OperationCycleStateType)0x00)
//#endif /*DEM_CYCLE_STATE_START*/
//#ifndef DEM_CYCLE_STATE_END
//#define DEM_CYCLE_STATE_END ((Dem_OperationCycleStateType)0x01)
//#endif /*DEM_CYCLE_STATE_END*/
//
//
//
//#define _DEFINED_TYPEDEF_FOR_Dem_OperationCycleStateType_
//
//typedef uint8 Dem_UdsStatusByteType;
//#ifndef DEM_UDS_STATUS_TF
//#define DEM_UDS_STATUS_TF ((Dem_UdsStatusByteType)0x01)
//#endif /*DEM_UDS_STATUS_TF*/
//#ifndef DEM_UDS_STATUS_TFTOC
//#define DEM_UDS_STATUS_TFTOC ((Dem_UdsStatusByteType)0x02)
//#endif /*DEM_UDS_STATUS_TFTOC*/
//#ifndef DEM_UDS_STATUS_PDTC
//#define DEM_UDS_STATUS_PDTC ((Dem_UdsStatusByteType)0x04)
//#endif /*DEM_UDS_STATUS_PDTC*/
//#ifndef DEM_UDS_STATUS_CDTC
//#define DEM_UDS_STATUS_CDTC ((Dem_UdsStatusByteType)0x08)
//#endif /*DEM_UDS_STATUS_CDTC*/
//#ifndef DEM_UDS_STATUS_TNCSLC
//#define DEM_UDS_STATUS_TNCSLC ((Dem_UdsStatusByteType)0x10)
//#endif /*DEM_UDS_STATUS_TNCSLC*/
//#ifndef DEM_UDS_STATUS_TFSLC
//#define DEM_UDS_STATUS_TFSLC ((Dem_UdsStatusByteType)0x20)
//#endif /*DEM_UDS_STATUS_TFSLC*/
//#ifndef DEM_UDS_STATUS_TNCTOC
//#define DEM_UDS_STATUS_TNCTOC ((Dem_UdsStatusByteType)0x40)
//#endif /*DEM_UDS_STATUS_TNCTOC*/
//#ifndef DEM_UDS_STATUS_WIR
//#define DEM_UDS_STATUS_WIR ((Dem_UdsStatusByteType)0x80)
//#endif /*DEM_UDS_STATUS_WIR*/
//
//
//
//#define _DEFINED_TYPEDEF_FOR_Dem_UdsStatusByteType_
//
//typedef uint8 DigitalLevel;
//#ifndef Low
//#define Low ((DigitalLevel)0)
//#endif /*Low*/
//#ifndef High
//#define High ((DigitalLevel)1)
//#endif /*High*/
//
//
//
//#define _DEFINED_TYPEDEF_FOR_DigitalLevel_
//
//typedef uint8 EcuM_BootTargetType;
//#ifndef ECUM_BOOT_TARGET_APP
//#define ECUM_BOOT_TARGET_APP ((EcuM_BootTargetType)0)
//#endif /*ECUM_BOOT_TARGET_APP*/
//#ifndef ECUM_BOOT_TARGET_OEM_BOOTLOADER
//#define ECUM_BOOT_TARGET_OEM_BOOTLOADER ((EcuM_BootTargetType)1)
//#endif /*ECUM_BOOT_TARGET_OEM_BOOTLOADER*/
//#ifndef ECUM_BOOT_TARGET_SYS_BOOTLOADER
//#define ECUM_BOOT_TARGET_SYS_BOOTLOADER ((EcuM_BootTargetType)2)
//#endif /*ECUM_BOOT_TARGET_SYS_BOOTLOADER*/
//#define EcuM_BootTargetType_LowerLimit 0
//#define EcuM_BootTargetType_UpperLimit 2
//
//
//
//#define _DEFINED_TYPEDEF_FOR_EcuM_BootTargetType_
//
//typedef uint8 EcuM_ShutdownCauseType;
//#ifndef ECUM_CAUSE_UNKNOWN
//#define ECUM_CAUSE_UNKNOWN ((EcuM_ShutdownCauseType)0)
//#endif /*ECUM_CAUSE_UNKNOWN*/
//#ifndef ECUM_CAUSE_ECU_STATE
//#define ECUM_CAUSE_ECU_STATE ((EcuM_ShutdownCauseType)1)
//#endif /*ECUM_CAUSE_ECU_STATE*/
//#ifndef ECUM_CAUSE_WDGM
//#define ECUM_CAUSE_WDGM ((EcuM_ShutdownCauseType)2)
//#endif /*ECUM_CAUSE_WDGM*/
//#ifndef ECUM_CAUSE_DCM
//#define ECUM_CAUSE_DCM ((EcuM_ShutdownCauseType)3)
//#endif /*ECUM_CAUSE_DCM*/
//#define EcuM_ShutdownCauseType_LowerLimit 0
//#define EcuM_ShutdownCauseType_UpperLimit 3
//
//
//
//#define _DEFINED_TYPEDEF_FOR_EcuM_ShutdownCauseType_
//
//typedef uint16 EcuM_ShutdownModeType;
//
//
//
//#define _DEFINED_TYPEDEF_FOR_EcuM_ShutdownModeType_
//
//typedef uint8 EcuM_ShutdownTargetType;
//#ifndef ECUM_SHUTDOWN_TARGET_SLEEP
//#define ECUM_SHUTDOWN_TARGET_SLEEP ((EcuM_ShutdownTargetType)0x0)
//#endif /*ECUM_SHUTDOWN_TARGET_SLEEP*/
//#ifndef ECUM_SHUTDOWN_TARGET_RESET
//#define ECUM_SHUTDOWN_TARGET_RESET ((EcuM_ShutdownTargetType)0x1)
//#endif /*ECUM_SHUTDOWN_TARGET_RESET*/
//#ifndef ECUM_SHUTDOWN_TARGET_OFF
//#define ECUM_SHUTDOWN_TARGET_OFF ((EcuM_ShutdownTargetType)0x2)
//#endif /*ECUM_SHUTDOWN_TARGET_OFF*/
//


#define _DEFINED_TYPEDEF_FOR_EcuM_ShutdownTargetType_ 

//typedef uint32 EcuM_TimeType;
#define EcuM_TimeType_LowerLimit 0
#define EcuM_TimeType_UpperLimit 4294967295



#define _DEFINED_TYPEDEF_FOR_EcuM_TimeType_ 

//typedef uint8 EcuM_UserType;
#define EcuM_UserType_LowerLimit 0
#define EcuM_UserType_UpperLimit 31



#define _DEFINED_TYPEDEF_FOR_EcuM_UserType_ 

typedef float32 Float;



#define _DEFINED_TYPEDEF_FOR_Float_ 

typedef float32 Float32;



#define _DEFINED_TYPEDEF_FOR_Float32_ 

typedef float64 Float64;



#define _DEFINED_TYPEDEF_FOR_Float64_ 

typedef uint16 IoHwAb_SignalType;
#define IoHwAb_SignalType_LowerLimit 0
#define IoHwAb_SignalType_UpperLimit 65535



#define _DEFINED_TYPEDEF_FOR_IoHwAb_SignalType_ 

typedef uint32 MilliVolt;



#define _DEFINED_TYPEDEF_FOR_MilliVolt_ 

typedef uint8 SignalQuality;
#ifndef SignalQuality_InitialValue
#define SignalQuality_InitialValue ((SignalQuality)0)
#endif /*SignalQuality_InitialValue*/
#ifndef SignalQuality_Error
#define SignalQuality_Error ((SignalQuality)1)
#endif /*SignalQuality_Error*/
#ifndef SignalQuality_Bad
#define SignalQuality_Bad ((SignalQuality)2)
#endif /*SignalQuality_Bad*/
#ifndef SignalQuality_Good
#define SignalQuality_Good ((SignalQuality)3)
#endif /*SignalQuality_Good*/



#define _DEFINED_TYPEDEF_FOR_SignalQuality_ 

typedef sint16 SInt16;
#define SInt16_LowerLimit -32768
#define SInt16_UpperLimit 32767



#define _DEFINED_TYPEDEF_FOR_SInt16_ 

typedef sint32 SInt32;
#define SInt32_LowerLimit -2147483648
#define SInt32_UpperLimit 2147483647



#define _DEFINED_TYPEDEF_FOR_SInt32_ 

typedef sint8 SInt8;
#define SInt8_LowerLimit -128
#define SInt8_UpperLimit 127



#define _DEFINED_TYPEDEF_FOR_SInt8_ 

typedef uint16 UInt16;
#define UInt16_LowerLimit 0
#define UInt16_UpperLimit 65535



#define _DEFINED_TYPEDEF_FOR_UInt16_ 

typedef uint32 UInt32;
#define UInt32_LowerLimit 0
#define UInt32_UpperLimit 4294967295



#define _DEFINED_TYPEDEF_FOR_UInt32_ 

typedef uint64 UInt64;
#define UInt64_LowerLimit 0
#define UInt64_UpperLimit 18446744073709551615



#define _DEFINED_TYPEDEF_FOR_UInt64_ 

typedef uint8 UInt8;
#define UInt8_LowerLimit 0
#define UInt8_UpperLimit 255



#define _DEFINED_TYPEDEF_FOR_UInt8_ 

typedef UInt8 Dem_MaxDataValueType[9];


#define _DEFINED_TYPEDEF_FOR_Dem_MaxDataValueType_ 

typedef uint8 uint8_T;

typedef uint16 uint16_T;

typedef uint32 uint32_T;

typedef boolean boolean_T;

typedef uint16_T rt_Array_UInt16_100[100];

typedef float64 Double_T;

typedef uint32 imask_t;

typedef struct 
{
	Boolean value;
} Rte_DE_Read_APPCOM_MainFunction_10ms_IN_DIAG_BattFlt_SR_RP_CstnFltSt;

typedef struct 
{
	Boolean value;
} Rte_DE_Read_APPCOM_MainFunction_10ms_IN_DIAG_BattFlt_SR_RP_SnsrFltSt;

typedef struct 
{
	UInt8 value;
} Rte_DE_Read_APPCOM_MainFunction_10ms_IN_DIAG_BattFlt_SR_RP_SwFltSt;

typedef struct 
{
	Boolean value;
} Rte_DE_Read_APPCOM_MainFunction_10ms_IN_COM_LinRx_BattRlyReqPrim_SR_RP_BattRlyReqPrim;

typedef struct 
{
	UInt16 value;
} Rte_DE_Read_APPCOM_MainFunction_10ms_IN_COM_LinRx_VehSpdLgt_SR_RP_VehSpdLgt;

typedef struct 
{
	UInt8 value;
} Rte_DE_Read_APPCOM_MainFunction_10ms_IN_COM_LinRx_VehicleState_SR_RP_VehicleState;

typedef struct 
{
	UInt8 value;
} Rte_DE_Read_APPCOM_MainFunction_10ms_IN_RLY_BattRlyStsPrim_SR_RP_BattRlyStsPrim;

typedef struct 
{
	Float value;
} Rte_DE_Read_APPCOM_MainFunction_10ms_IN_SMP_Current_SR_RP_Current;

typedef struct 
{
	Float value;
} Rte_DE_Read_APPCOM_MainFunction_10ms_IN_SMP_Volt_SR_RP_OCV;

typedef struct 
{
	Float value;
} Rte_DE_Read_APPCOM_MainFunction_10ms_IN_SMP_Volt_SR_RP_PackVolt;

typedef struct 
{
	Float value;
} Rte_DE_Read_APPCOM_MainFunction_10ms_IN_SMP_Temp_SR_RP_Temp;

typedef struct 
{
	Float value;
} Rte_DE_Read_APPCOM_MainFunction_10ms_IN_SOC_Display_SR_RP_Display;

typedef struct 
{
	UInt8 value;
} Rte_DE_Write_APPCOM_MainFunction_10ms_OUT_APPCOM_LinRx_VehicleState_SR_PP_VehicleState;

typedef struct 
{
	UInt16 value;
} Rte_DE_Write_APPCOM_MainFunction_10ms_OUT_APPCOM_LinRx_VehSpdLgt_SR_PP_VehSpdLgt;

typedef struct 
{
	Boolean value;
} Rte_DE_Write_APPCOM_MainFunction_10ms_OUT_APPCOM_LinRx_BattRlyReqPrim_SR_PP_BattRlyReqPrim;

typedef struct 
{
	Float value;
} Rte_DE_Write_APPCOM_MainFunction_10ms_OUT_APPCOM_LinTx_BattURaw_SR_PP_BattURaw;

typedef struct 
{
	Float value;
} Rte_DE_Write_APPCOM_MainFunction_10ms_OUT_APPCOM_LinTx_BattCircOpenU_SR_PP_BattCircOpenU;

typedef struct 
{
	Float value;
} Rte_DE_Write_APPCOM_MainFunction_10ms_OUT_APPCOM_LinTx_BattIRaw_SR_PP_BattIRaw;

typedef struct 
{
	Float value;
} Rte_DE_Write_APPCOM_MainFunction_10ms_OUT_APPCOM_LinTx_BattTRaw_SR_PP_BattTRaw;

typedef struct 
{
	Boolean value;
} Rte_DE_Write_APPCOM_MainFunction_10ms_OUT_APPCOM_LinTx_BattSnsrHwFltRaw_SR_PP_BattSnsrHwFltRaw;

typedef struct 
{
	Boolean value;
} Rte_DE_Write_APPCOM_MainFunction_10ms_OUT_APPCOM_LinTx_BattSnsrCalcnNotVldRaw_SR_PP_BattSnsrCalcnNotVldRaw;

typedef struct 
{
	UInt8 value;
} Rte_DE_Write_APPCOM_MainFunction_10ms_OUT_APPCOM_LinTx_BattFltStsPrim_SR_PP_BattFltStsPrim;

typedef struct 
{
	Float value;
} Rte_DE_Write_APPCOM_MainFunction_10ms_OUT_APPCOM_LinTx_BattSocRaw_SR_PP_BattSocRaw;

typedef struct 
{
	UInt8 value;
} Rte_DE_Write_APPCOM_MainFunction_10ms_OUT_APPCOM_LinTx_BattRlyStsPrim_SR_PP_BattRlyStsPrim;

typedef struct 
{
	Boolean value;
} Rte_DE_Read_DIAG_MainFunction_10ms_IN_MEM_BattFlt_SR_RP_BattSnsrCalcnNotVldRaw;

typedef struct 
{
	Boolean value;
} Rte_DE_Read_DIAG_MainFunction_10ms_IN_MEM_BattFlt_SR_RP_BattSnsrHwFltRaw;

typedef struct 
{
	UInt8 value;
} Rte_DE_Read_DIAG_MainFunction_10ms_IN_MEM_BattFlt_SR_RP_BattFltStsPrim;

typedef struct 
{
	Float value;
} Rte_DE_Read_DIAG_MainFunction_10ms_IN_SMP_Current_SR_RP_Current;

typedef struct 
{
	Float value;
} Rte_DE_Read_DIAG_MainFunction_10ms_IN_SMP_Volt_SR_RP_Cell1Volt;

typedef struct 
{
	Float value;
} Rte_DE_Read_DIAG_MainFunction_10ms_IN_SMP_Volt_SR_RP_Cell2Volt;

typedef struct 
{
	Float value;
} Rte_DE_Read_DIAG_MainFunction_10ms_IN_SMP_Volt_SR_RP_Cell3Volt;

typedef struct 
{
	Float value;
} Rte_DE_Read_DIAG_MainFunction_10ms_IN_SMP_Volt_SR_RP_Cell4Volt;

typedef struct 
{
	Float value;
} Rte_DE_Read_DIAG_MainFunction_10ms_IN_SMP_Volt_SR_RP_PackVolt;

typedef struct 
{
	Float value;
} Rte_DE_Read_DIAG_MainFunction_10ms_IN_SMP_Temp_SR_RP_Temp1;

typedef struct 
{
	Float value;
} Rte_DE_Read_DIAG_MainFunction_10ms_IN_SMP_Temp_SR_RP_Temp2;

typedef struct 
{
	Float value;
} Rte_DE_Read_DIAG_MainFunction_10ms_IN_SMP_Temp_SR_RP_Temp3;

typedef struct 
{
	Float value;
} Rte_DE_Read_DIAG_MainFunction_10ms_IN_SMP_TempRange_SR_RP_TempMax;

typedef struct 
{
	Float value;
} Rte_DE_Read_DIAG_MainFunction_10ms_IN_SMP_TempRange_SR_RP_TempMin;

typedef struct 
{
	Float value;
} Rte_DE_Read_DIAG_MainFunction_10ms_IN_SOC_Target_SR_RP_Target;

typedef struct 
{
	Float value;
} Rte_DE_Read_DIAG_MainFunction_10ms_IN_SOC_Display_SR_RP_Display;

typedef struct 
{
	Boolean value;
} Rte_DE_Write_DIAG_MainFunction_10ms_OUT_DIAG_BattFlt_SR_PP_SnsrFltSt;

typedef struct 
{
	Boolean value;
} Rte_DE_Write_DIAG_MainFunction_10ms_OUT_DIAG_BattFlt_SR_PP_CstnFltSt;

typedef struct 
{
	UInt8 value;
} Rte_DE_Write_DIAG_MainFunction_10ms_OUT_DIAG_BattFlt_SR_PP_SwFltSt;

typedef struct 
{
	Boolean value;
} Rte_DE_Write_DIAG_MainFunction_10ms_OUT_DIAG_RlyCutOffEnaSt_SR_PP_RlyCutOffEnaSt;

typedef struct 
{
	UInt16 value;
} Rte_DE_Write_MC33772_MainFunction_10ms_OUT_AFE_Volt_SR_PP_Cell1Volt;

typedef struct 
{
	UInt16 value;
} Rte_DE_Write_MC33772_MainFunction_10ms_OUT_AFE_Volt_SR_PP_Cell2Volt;

typedef struct 
{
	UInt16 value;
} Rte_DE_Write_MC33772_MainFunction_10ms_OUT_AFE_Volt_SR_PP_Cell3Volt;

typedef struct 
{
	UInt16 value;
} Rte_DE_Write_MC33772_MainFunction_10ms_OUT_AFE_Volt_SR_PP_Cell4Volt;

typedef struct 
{
	UInt16 value;
} Rte_DE_Write_MC33772_MainFunction_10ms_OUT_AFE_Volt_SR_PP_PackVolt;

typedef struct 
{
	SInt32 value;
} Rte_DE_Write_MC33772_MainFunction_10ms_OUT_AFE_Current_SR_PP_Current;

typedef struct 
{
	SInt16 value;
} Rte_DE_Write_MC33772_MainFunction_10ms_OUT_AFE_Temp_SR_PP_Temp1;

typedef struct 
{
	SInt16 value;
} Rte_DE_Write_MC33772_MainFunction_10ms_OUT_AFE_Temp_SR_PP_Temp2;

typedef struct 
{
	SInt16 value;
} Rte_DE_Write_MC33772_MainFunction_10ms_OUT_AFE_Temp_SR_PP_Temp3;

typedef struct 
{
	UInt16 value;
} Rte_DE_Write_MC33772_MainFunction_10ms_OUT_AFE_RelayExt_SR_PP_RelayExt;

typedef struct 
{
	UInt8 value;
} Rte_DE_Read_MDM_MainFunction_10ms_IN_APPCOM_LinRx_VehicleState_SR_RP_VehicleState;

typedef struct 
{
	Float value;
} Rte_DE_Read_MDM_MainFunction_10ms_IN_SMP_Current_SR_RP_Current;

typedef struct 
{
	Float value;
} Rte_DE_Write_MEM_Read_MainFunction_10ms_OUT_MEM_Volt_SR_PP_Cell1Volt;

typedef struct 
{
	Float value;
} Rte_DE_Write_MEM_Read_MainFunction_10ms_OUT_MEM_Volt_SR_PP_Cell2Volt;

typedef struct 
{
	Float value;
} Rte_DE_Write_MEM_Read_MainFunction_10ms_OUT_MEM_Volt_SR_PP_Cell3Volt;

typedef struct 
{
	Float value;
} Rte_DE_Write_MEM_Read_MainFunction_10ms_OUT_MEM_Volt_SR_PP_Cell4Volt;

typedef struct 
{
	Float value;
} Rte_DE_Write_MEM_Read_MainFunction_10ms_OUT_MEM_Volt_SR_PP_PackVolt;

typedef struct 
{
	Float value;
} Rte_DE_Write_MEM_Read_MainFunction_10ms_OUT_MEM_Volt_SR_PP_OCV;

typedef struct 
{
	Float value;
} Rte_DE_Write_MEM_Read_MainFunction_10ms_OUT_MEM_Current_SR_PP_Current;

typedef struct 
{
	Float value;
} Rte_DE_Write_MEM_Read_MainFunction_10ms_OUT_MEM_Temp_SR_PP_Temp1;

typedef struct 
{
	Float value;
} Rte_DE_Write_MEM_Read_MainFunction_10ms_OUT_MEM_Temp_SR_PP_Temp2;

typedef struct 
{
	Float value;
} Rte_DE_Write_MEM_Read_MainFunction_10ms_OUT_MEM_Temp_SR_PP_Temp3;

typedef struct 
{
	Float value;
} Rte_DE_Write_MEM_Read_MainFunction_10ms_OUT_MEM_Temp_SR_PP_BattTRaw;

typedef struct 
{
	UInt32 value;
} Rte_DE_Write_MEM_Read_MainFunction_10ms_OUT_MEM_SleepTime_SR_PP_SleepTime;

typedef struct 
{
	Boolean value;
} Rte_DE_Write_MEM_Read_MainFunction_10ms_OUT_MEM_BattFlt_SR_PP_BattSnsrHwFltRaw;

typedef struct 
{
	Boolean value;
} Rte_DE_Write_MEM_Read_MainFunction_10ms_OUT_MEM_BattFlt_SR_PP_BattSnsrCalcnNotVldRaw;

typedef struct 
{
	UInt8 value;
} Rte_DE_Write_MEM_Read_MainFunction_10ms_OUT_MEM_BattFlt_SR_PP_BattFltStsPrim;

typedef struct 
{
	Float value;
} Rte_DE_Write_MEM_Read_MainFunction_10ms_OUT_MEM_BattSocRaw_SR_PP_BattSocRaw;

typedef struct 
{
	Boolean value;
} Rte_DE_Read_MEM_Write_MainFunction_10ms_IN_DIAG_BattFlt_SR_RP_CstnFltSt;

typedef struct 
{
	Boolean value;
} Rte_DE_Read_MEM_Write_MainFunction_10ms_IN_DIAG_BattFlt_SR_RP_SnsrFltSt;

typedef struct 
{
	UInt8 value;
} Rte_DE_Read_MEM_Write_MainFunction_10ms_IN_DIAG_BattFlt_SR_RP_SwFltSt;

typedef struct 
{
	Float value;
} Rte_DE_Read_MEM_Write_MainFunction_10ms_IN_SMP_Current_SR_RP_Current;

typedef struct 
{
	Float value;
} Rte_DE_Read_MEM_Write_MainFunction_10ms_IN_SMP_Volt_SR_RP_Cell1Volt;

typedef struct 
{
	Float value;
} Rte_DE_Read_MEM_Write_MainFunction_10ms_IN_SMP_Volt_SR_RP_Cell2Volt;

typedef struct 
{
	Float value;
} Rte_DE_Read_MEM_Write_MainFunction_10ms_IN_SMP_Volt_SR_RP_Cell3Volt;

typedef struct 
{
	Float value;
} Rte_DE_Read_MEM_Write_MainFunction_10ms_IN_SMP_Volt_SR_RP_Cell4Volt;

typedef struct 
{
	Float value;
} Rte_DE_Read_MEM_Write_MainFunction_10ms_IN_SMP_Volt_SR_RP_OCV;

typedef struct 
{
	Float value;
} Rte_DE_Read_MEM_Write_MainFunction_10ms_IN_SMP_Volt_SR_RP_PackVolt;

typedef struct 
{
	Float value;
} Rte_DE_Read_MEM_Write_MainFunction_10ms_IN_SMP_Temp_SR_RP_Temp;

typedef struct 
{
	Float value;
} Rte_DE_Read_MEM_Write_MainFunction_10ms_IN_SMP_Temp_SR_RP_Temp1;

typedef struct 
{
	Float value;
} Rte_DE_Read_MEM_Write_MainFunction_10ms_IN_SMP_Temp_SR_RP_Temp2;

typedef struct 
{
	Float value;
} Rte_DE_Read_MEM_Write_MainFunction_10ms_IN_SMP_Temp_SR_RP_Temp3;

typedef struct 
{
	UInt32 value;
} Rte_DE_Read_MEM_Write_MainFunction_10ms_IN_SMP_SleepTime_SR_RP_SleepTime;

typedef struct 
{
	Float value;
} Rte_DE_Read_MEM_Write_MainFunction_10ms_IN_SOC_Display_SR_RP_Display;

typedef struct 
{
	Boolean value;
} Rte_DE_Read_Runnable_RLY_IN_APPCOM_LinRx_BattRlyReqPrim_SR_RP_BattRlyReqPrim;

typedef struct 
{
	UInt16 value;
} Rte_DE_Read_Runnable_RLY_IN_APPCOM_LinRx_VehSpdLgt_SR_RP_VehSpdLgt;

typedef struct 
{
	Boolean value;
} Rte_DE_Read_Runnable_RLY_IN_DIAG_RlyCutOffEnaSt_SR_RP_RlyCutOffEnaSt;

typedef struct 
{
	UInt16 value;
} Rte_DE_Read_Runnable_RLY_IN_AFE_RelayExt_SR_RP_RelayExt;

typedef struct 
{
	UInt8 value;
} Rte_DE_Write_Runnable_RLY_OUT_RLY_BattRlyStsPrim_SR_PP_BattRlyStsPrim;

typedef struct 
{
	Boolean value;
} Rte_DE_Read_SMP_MainFunction_10ms_IN_DIAG_BattFlt_SR_RP_SnsrFltSt;

typedef struct 
{
	UInt8 value;
} Rte_DE_Read_SMP_MainFunction_10ms_IN_SBC_WakeUp_SR_RP_WakeUpSource;

typedef struct 
{
	SInt16 value;
} Rte_DE_Read_SMP_MainFunction_10ms_IN_AFE_Temp_SR_RP_Temp3;

typedef struct 
{
	SInt16 value;
} Rte_DE_Read_SMP_MainFunction_10ms_IN_AFE_Temp_SR_RP_Temp1;

typedef struct 
{
	SInt16 value;
} Rte_DE_Read_SMP_MainFunction_10ms_IN_AFE_Temp_SR_RP_Temp2;

typedef struct 
{
	SInt32 value;
} Rte_DE_Read_SMP_MainFunction_10ms_IN_AFE_Current_SR_RP_Current;

typedef struct 
{
	UInt16 value;
} Rte_DE_Read_SMP_MainFunction_10ms_IN_AFE_Volt_SR_RP_Cell1Volt;

typedef struct 
{
	UInt16 value;
} Rte_DE_Read_SMP_MainFunction_10ms_IN_AFE_Volt_SR_RP_Cell2Volt;

typedef struct 
{
	UInt16 value;
} Rte_DE_Read_SMP_MainFunction_10ms_IN_AFE_Volt_SR_RP_Cell3Volt;

typedef struct 
{
	UInt16 value;
} Rte_DE_Read_SMP_MainFunction_10ms_IN_AFE_Volt_SR_RP_Cell4Volt;

typedef struct 
{
	UInt16 value;
} Rte_DE_Read_SMP_MainFunction_10ms_IN_AFE_Volt_SR_RP_PackVolt;

typedef struct 
{
	Float value;
} Rte_DE_Read_SMP_MainFunction_10ms_IN_MEM_Current_SR_RP_Current;

typedef struct 
{
	Float value;
} Rte_DE_Read_SMP_MainFunction_10ms_IN_MEM_Volt_SR_RP_Cell1Volt;

typedef struct 
{
	Float value;
} Rte_DE_Read_SMP_MainFunction_10ms_IN_MEM_Volt_SR_RP_Cell2Volt;

typedef struct 
{
	Float value;
} Rte_DE_Read_SMP_MainFunction_10ms_IN_MEM_Volt_SR_RP_Cell3Volt;

typedef struct 
{
	Float value;
} Rte_DE_Read_SMP_MainFunction_10ms_IN_MEM_Volt_SR_RP_Cell4Volt;

typedef struct 
{
	Float value;
} Rte_DE_Read_SMP_MainFunction_10ms_IN_MEM_Volt_SR_RP_OCV;

typedef struct 
{
	Float value;
} Rte_DE_Read_SMP_MainFunction_10ms_IN_MEM_Volt_SR_RP_PackVolt;

typedef struct 
{
	Float value;
} Rte_DE_Read_SMP_MainFunction_10ms_IN_MEM_Temp_SR_RP_BattTRaw;

typedef struct 
{
	Float value;
} Rte_DE_Read_SMP_MainFunction_10ms_IN_MEM_Temp_SR_RP_Temp1;

typedef struct 
{
	Float value;
} Rte_DE_Read_SMP_MainFunction_10ms_IN_MEM_Temp_SR_RP_Temp2;

typedef struct 
{
	Float value;
} Rte_DE_Read_SMP_MainFunction_10ms_IN_MEM_Temp_SR_RP_Temp3;

typedef struct 
{
	UInt32 value;
} Rte_DE_Read_SMP_MainFunction_10ms_IN_MEM_SleepTime_SR_RP_SleepTime;

typedef struct 
{
	Boolean value;
} Rte_DE_Read_SMP_MainFunction_10ms_IN_DIAG_SnsrFltSt_SR_RP_SnsrFltSt;

typedef struct 
{
	Float value;
} Rte_DE_Write_SMP_MainFunction_10ms_OUT_SMP_Volt_SR_PP_Cell1Volt;

typedef struct 
{
	Float value;
} Rte_DE_Write_SMP_MainFunction_10ms_OUT_SMP_Volt_SR_PP_Cell2Volt;

typedef struct 
{
	Float value;
} Rte_DE_Write_SMP_MainFunction_10ms_OUT_SMP_Volt_SR_PP_Cell3Volt;

typedef struct 
{
	Float value;
} Rte_DE_Write_SMP_MainFunction_10ms_OUT_SMP_Volt_SR_PP_Cell4Volt;

typedef struct 
{
	Float value;
} Rte_DE_Write_SMP_MainFunction_10ms_OUT_SMP_CellVoltRange_SR_PP_CellVoltMax;

typedef struct 
{
	Float value;
} Rte_DE_Write_SMP_MainFunction_10ms_OUT_SMP_CellVoltRange_SR_PP_CellVoltMin;

typedef struct 
{
	Float value;
} Rte_DE_Write_SMP_MainFunction_10ms_OUT_SMP_Volt_SR_PP_PackVolt;

typedef struct 
{
	Float value;
} Rte_DE_Write_SMP_MainFunction_10ms_OUT_SMP_Volt_SR_PP_OCV;

typedef struct 
{
	Float value;
} Rte_DE_Write_SMP_MainFunction_10ms_OUT_SMP_Current_SR_PP_Current;

typedef struct 
{
	Float value;
} Rte_DE_Write_SMP_MainFunction_10ms_OUT_SMP_Temp_SR_PP_Temp1;

typedef struct 
{
	Float value;
} Rte_DE_Write_SMP_MainFunction_10ms_OUT_SMP_Temp_SR_PP_Temp2;

typedef struct 
{
	Float value;
} Rte_DE_Write_SMP_MainFunction_10ms_OUT_SMP_Temp_SR_PP_Temp3;

typedef struct 
{
	Float value;
} Rte_DE_Write_SMP_MainFunction_10ms_OUT_SMP_Temp_SR_PP_Temp;

typedef struct 
{
	Float value;
} Rte_DE_Write_SMP_MainFunction_10ms_OUT_SMP_TempRange_SR_PP_TempMax;

typedef struct 
{
	Float value;
} Rte_DE_Write_SMP_MainFunction_10ms_OUT_SMP_TempRange_SR_PP_TempMin;

typedef struct 
{
	UInt32 value;
} Rte_DE_Write_SMP_MainFunction_10ms_OUT_SMP_SleepTime_SR_PP_SleepTime;

typedef struct 
{
	Float value;
} Rte_DE_Read_SOC_MainFunction_10ms_IN_MEM_BattSocRaw_SR_RP_BattSocRaw;

typedef struct 
{
	Float value;
} Rte_DE_Read_SOC_MainFunction_10ms_IN_SMP_Current_SR_RP_Current;

typedef struct 
{
	Float value;
} Rte_DE_Read_SOC_MainFunction_10ms_IN_SMP_CellVoltRange_SR_RP_CellVoltMax;

typedef struct 
{
	Float value;
} Rte_DE_Read_SOC_MainFunction_10ms_IN_SMP_CellVoltRange_SR_RP_CellVoltMin;

typedef struct 
{
	Float value;
} Rte_DE_Read_SOC_MainFunction_10ms_IN_SMP_TempRange_SR_RP_TempMax;

typedef struct 
{
	Float value;
} Rte_DE_Write_SOC_MainFunction_10ms_OUT_SOC_Display_SR_PP_Display;

typedef struct 
{
	Float value;
} Rte_DE_Write_SOC_MainFunction_10ms_OUT_SOC_Target_SR_PP_Target;

typedef struct 
{
	UInt8 value;
} Rte_DE_Write_TLF35584_MainFunction_10ms_OUT_SBC_WakeUp_SR_PP_WakeUpSource;

typedef uint8 Rte_ModeGroupType;
#define RTE_MODE_EcuM_Mode ((Rte_ModeGroupType)0)


typedef uint8 Rte_ModeType_EcuM_Mode;
#define RTE_TRANSITION_EcuM_Mode ((Rte_ModeType_EcuM_Mode)6)
#define RTE_MODE_EcuM_Mode_STARTUP ((Rte_ModeType_EcuM_Mode)4)
#define RTE_MODE_EcuM_Mode_RUN ((Rte_ModeType_EcuM_Mode)1)
#define RTE_MODE_EcuM_Mode_POST_RUN ((Rte_ModeType_EcuM_Mode)0)
#define RTE_MODE_EcuM_Mode_SLEEP ((Rte_ModeType_EcuM_Mode)3)
#define RTE_MODE_EcuM_Mode_SHUTDOWN ((Rte_ModeType_EcuM_Mode)2)
#define RTE_MODE_EcuM_Mode_WAKE_SLEEP ((Rte_ModeType_EcuM_Mode)5)


typedef struct 
{
	Rte_DE_Read_APPCOM_MainFunction_10ms_IN_DIAG_BattFlt_SR_RP_CstnFltSt* APPCOM_MainFunction_10ms_DIAG_BattFlt_SR_RP_CstnFltSt;
	Rte_DE_Read_APPCOM_MainFunction_10ms_IN_DIAG_BattFlt_SR_RP_SnsrFltSt* APPCOM_MainFunction_10ms_DIAG_BattFlt_SR_RP_SnsrFltSt;
	Rte_DE_Read_APPCOM_MainFunction_10ms_IN_DIAG_BattFlt_SR_RP_SwFltSt* APPCOM_MainFunction_10ms_DIAG_BattFlt_SR_RP_SwFltSt;
	Rte_DE_Read_APPCOM_MainFunction_10ms_IN_COM_LinRx_BattRlyReqPrim_SR_RP_BattRlyReqPrim* APPCOM_MainFunction_10ms_COM_LinRx_BattRlyReqPrim_SR_RP_BattRlyReqPrim;
	Rte_DE_Read_APPCOM_MainFunction_10ms_IN_COM_LinRx_VehSpdLgt_SR_RP_VehSpdLgt* APPCOM_MainFunction_10ms_COM_LinRx_VehSpdLgt_SR_RP_VehSpdLgt;
	Rte_DE_Read_APPCOM_MainFunction_10ms_IN_COM_LinRx_VehicleState_SR_RP_VehicleState* APPCOM_MainFunction_10ms_COM_LinRx_VehicleState_SR_RP_VehicleState;
	Rte_DE_Read_APPCOM_MainFunction_10ms_IN_RLY_BattRlyStsPrim_SR_RP_BattRlyStsPrim* APPCOM_MainFunction_10ms_RLY_BattRlyStsPrim_SR_RP_BattRlyStsPrim;
	Rte_DE_Read_APPCOM_MainFunction_10ms_IN_SMP_Current_SR_RP_Current* APPCOM_MainFunction_10ms_SMP_Current_SR_RP_Current;
	Rte_DE_Read_APPCOM_MainFunction_10ms_IN_SMP_Volt_SR_RP_OCV* APPCOM_MainFunction_10ms_SMP_Volt_SR_RP_OCV;
	Rte_DE_Read_APPCOM_MainFunction_10ms_IN_SMP_Volt_SR_RP_PackVolt* APPCOM_MainFunction_10ms_SMP_Volt_SR_RP_PackVolt;
	Rte_DE_Read_APPCOM_MainFunction_10ms_IN_SMP_Temp_SR_RP_Temp* APPCOM_MainFunction_10ms_SMP_Temp_SR_RP_Temp;
	Rte_DE_Read_APPCOM_MainFunction_10ms_IN_SOC_Display_SR_RP_Display* APPCOM_MainFunction_10ms_SOC_Display_SR_RP_Display;
	Rte_DE_Write_APPCOM_MainFunction_10ms_OUT_APPCOM_LinRx_VehicleState_SR_PP_VehicleState* APPCOM_MainFunction_10ms_APPCOM_LinRx_VehicleState_SR_PP_VehicleState;
	Rte_DE_Write_APPCOM_MainFunction_10ms_OUT_APPCOM_LinRx_VehSpdLgt_SR_PP_VehSpdLgt* APPCOM_MainFunction_10ms_APPCOM_LinRx_VehSpdLgt_SR_PP_VehSpdLgt;
	Rte_DE_Write_APPCOM_MainFunction_10ms_OUT_APPCOM_LinRx_BattRlyReqPrim_SR_PP_BattRlyReqPrim* APPCOM_MainFunction_10ms_APPCOM_LinRx_BattRlyReqPrim_SR_PP_BattRlyReqPrim;
	Rte_DE_Write_APPCOM_MainFunction_10ms_OUT_APPCOM_LinTx_BattURaw_SR_PP_BattURaw* APPCOM_MainFunction_10ms_APPCOM_LinTx_BattURaw_SR_PP_BattURaw;
	Rte_DE_Write_APPCOM_MainFunction_10ms_OUT_APPCOM_LinTx_BattCircOpenU_SR_PP_BattCircOpenU* APPCOM_MainFunction_10ms_APPCOM_LinTx_BattCircOpenU_SR_PP_BattCircOpenU;
	Rte_DE_Write_APPCOM_MainFunction_10ms_OUT_APPCOM_LinTx_BattIRaw_SR_PP_BattIRaw* APPCOM_MainFunction_10ms_APPCOM_LinTx_BattIRaw_SR_PP_BattIRaw;
	Rte_DE_Write_APPCOM_MainFunction_10ms_OUT_APPCOM_LinTx_BattTRaw_SR_PP_BattTRaw* APPCOM_MainFunction_10ms_APPCOM_LinTx_BattTRaw_SR_PP_BattTRaw;
	Rte_DE_Write_APPCOM_MainFunction_10ms_OUT_APPCOM_LinTx_BattSnsrHwFltRaw_SR_PP_BattSnsrHwFltRaw* APPCOM_MainFunction_10ms_APPCOM_LinTx_BattSnsrHwFltRaw_SR_PP_BattSnsrHwFltRaw;
	Rte_DE_Write_APPCOM_MainFunction_10ms_OUT_APPCOM_LinTx_BattSnsrCalcnNotVldRaw_SR_PP_BattSnsrCalcnNotVldRaw* APPCOM_MainFunction_10ms_APPCOM_LinTx_BattSnsrCalcnNotVldRaw_SR_PP_BattSnsrCalcnNotVldRaw;
	Rte_DE_Write_APPCOM_MainFunction_10ms_OUT_APPCOM_LinTx_BattFltStsPrim_SR_PP_BattFltStsPrim* APPCOM_MainFunction_10ms_APPCOM_LinTx_BattFltStsPrim_SR_PP_BattFltStsPrim;
	Rte_DE_Write_APPCOM_MainFunction_10ms_OUT_APPCOM_LinTx_BattSocRaw_SR_PP_BattSocRaw* APPCOM_MainFunction_10ms_APPCOM_LinTx_BattSocRaw_SR_PP_BattSocRaw;
	Rte_DE_Write_APPCOM_MainFunction_10ms_OUT_APPCOM_LinTx_BattRlyStsPrim_SR_PP_BattRlyStsPrim* APPCOM_MainFunction_10ms_APPCOM_LinTx_BattRlyStsPrim_SR_PP_BattRlyStsPrim;
} Rte_CDS_APPCOM;

typedef struct 
{
	Rte_DE_Read_DIAG_MainFunction_10ms_IN_MEM_BattFlt_SR_RP_BattSnsrCalcnNotVldRaw* DIAG_MainFunction_10ms_MEM_BattFlt_SR_RP_BattSnsrCalcnNotVldRaw;
	Rte_DE_Read_DIAG_MainFunction_10ms_IN_MEM_BattFlt_SR_RP_BattSnsrHwFltRaw* DIAG_MainFunction_10ms_MEM_BattFlt_SR_RP_BattSnsrHwFltRaw;
	Rte_DE_Read_DIAG_MainFunction_10ms_IN_MEM_BattFlt_SR_RP_BattFltStsPrim* DIAG_MainFunction_10ms_MEM_BattFlt_SR_RP_BattFltStsPrim;
	Rte_DE_Read_DIAG_MainFunction_10ms_IN_SMP_Current_SR_RP_Current* DIAG_MainFunction_10ms_SMP_Current_SR_RP_Current;
	Rte_DE_Read_DIAG_MainFunction_10ms_IN_SMP_Volt_SR_RP_Cell1Volt* DIAG_MainFunction_10ms_SMP_Volt_SR_RP_Cell1Volt;
	Rte_DE_Read_DIAG_MainFunction_10ms_IN_SMP_Volt_SR_RP_Cell2Volt* DIAG_MainFunction_10ms_SMP_Volt_SR_RP_Cell2Volt;
	Rte_DE_Read_DIAG_MainFunction_10ms_IN_SMP_Volt_SR_RP_Cell3Volt* DIAG_MainFunction_10ms_SMP_Volt_SR_RP_Cell3Volt;
	Rte_DE_Read_DIAG_MainFunction_10ms_IN_SMP_Volt_SR_RP_Cell4Volt* DIAG_MainFunction_10ms_SMP_Volt_SR_RP_Cell4Volt;
	Rte_DE_Read_DIAG_MainFunction_10ms_IN_SMP_Volt_SR_RP_PackVolt* DIAG_MainFunction_10ms_SMP_Volt_SR_RP_PackVolt;
	Rte_DE_Read_DIAG_MainFunction_10ms_IN_SMP_Temp_SR_RP_Temp1* DIAG_MainFunction_10ms_SMP_Temp_SR_RP_Temp1;
	Rte_DE_Read_DIAG_MainFunction_10ms_IN_SMP_Temp_SR_RP_Temp2* DIAG_MainFunction_10ms_SMP_Temp_SR_RP_Temp2;
	Rte_DE_Read_DIAG_MainFunction_10ms_IN_SMP_Temp_SR_RP_Temp3* DIAG_MainFunction_10ms_SMP_Temp_SR_RP_Temp3;
	Rte_DE_Read_DIAG_MainFunction_10ms_IN_SMP_TempRange_SR_RP_TempMax* DIAG_MainFunction_10ms_SMP_TempRange_SR_RP_TempMax;
	Rte_DE_Read_DIAG_MainFunction_10ms_IN_SMP_TempRange_SR_RP_TempMin* DIAG_MainFunction_10ms_SMP_TempRange_SR_RP_TempMin;
	Rte_DE_Read_DIAG_MainFunction_10ms_IN_SOC_Target_SR_RP_Target* DIAG_MainFunction_10ms_SOC_Target_SR_RP_Target;
	Rte_DE_Read_DIAG_MainFunction_10ms_IN_SOC_Display_SR_RP_Display* DIAG_MainFunction_10ms_SOC_Display_SR_RP_Display;
	Rte_DE_Write_DIAG_MainFunction_10ms_OUT_DIAG_BattFlt_SR_PP_SnsrFltSt* DIAG_MainFunction_10ms_DIAG_BattFlt_SR_PP_SnsrFltSt;
	Rte_DE_Write_DIAG_MainFunction_10ms_OUT_DIAG_BattFlt_SR_PP_CstnFltSt* DIAG_MainFunction_10ms_DIAG_BattFlt_SR_PP_CstnFltSt;
	Rte_DE_Write_DIAG_MainFunction_10ms_OUT_DIAG_BattFlt_SR_PP_SwFltSt* DIAG_MainFunction_10ms_DIAG_BattFlt_SR_PP_SwFltSt;
	Rte_DE_Write_DIAG_MainFunction_10ms_OUT_DIAG_RlyCutOffEnaSt_SR_PP_RlyCutOffEnaSt* DIAG_MainFunction_10ms_DIAG_RlyCutOffEnaSt_SR_PP_RlyCutOffEnaSt;
} Rte_CDS_DIAG;







typedef struct 
{
	Rte_DE_Write_MC33772_MainFunction_10ms_OUT_AFE_Volt_SR_PP_Cell1Volt* MC33772_MainFunction_10ms_AFE_Volt_SR_PP_Cell1Volt;
	Rte_DE_Write_MC33772_MainFunction_10ms_OUT_AFE_Volt_SR_PP_Cell2Volt* MC33772_MainFunction_10ms_AFE_Volt_SR_PP_Cell2Volt;
	Rte_DE_Write_MC33772_MainFunction_10ms_OUT_AFE_Volt_SR_PP_Cell3Volt* MC33772_MainFunction_10ms_AFE_Volt_SR_PP_Cell3Volt;
	Rte_DE_Write_MC33772_MainFunction_10ms_OUT_AFE_Volt_SR_PP_Cell4Volt* MC33772_MainFunction_10ms_AFE_Volt_SR_PP_Cell4Volt;
	Rte_DE_Write_MC33772_MainFunction_10ms_OUT_AFE_Volt_SR_PP_PackVolt* MC33772_MainFunction_10ms_AFE_Volt_SR_PP_PackVolt;
	Rte_DE_Write_MC33772_MainFunction_10ms_OUT_AFE_Current_SR_PP_Current* MC33772_MainFunction_10ms_AFE_Current_SR_PP_Current;
	Rte_DE_Write_MC33772_MainFunction_10ms_OUT_AFE_Temp_SR_PP_Temp1* MC33772_MainFunction_10ms_AFE_Temp_SR_PP_Temp1;
	Rte_DE_Write_MC33772_MainFunction_10ms_OUT_AFE_Temp_SR_PP_Temp2* MC33772_MainFunction_10ms_AFE_Temp_SR_PP_Temp2;
	Rte_DE_Write_MC33772_MainFunction_10ms_OUT_AFE_Temp_SR_PP_Temp3* MC33772_MainFunction_10ms_AFE_Temp_SR_PP_Temp3;
	Rte_DE_Write_MC33772_MainFunction_10ms_OUT_AFE_RelayExt_SR_PP_RelayExt* MC33772_MainFunction_10ms_AFE_RelayExt_SR_PP_RelayExt;
} Rte_CDS_MC33772;

typedef struct 
{
	Rte_DE_Read_MDM_MainFunction_10ms_IN_APPCOM_LinRx_VehicleState_SR_RP_VehicleState* MDM_MainFunction_10ms_APPCOM_LinRx_VehicleState_SR_RP_VehicleState;
	Rte_DE_Read_MDM_MainFunction_10ms_IN_SMP_Current_SR_RP_Current* MDM_MainFunction_10ms_SMP_Current_SR_RP_Current;
} Rte_CDS_MDM;

typedef struct 
{
	Rte_DE_Write_MEM_Read_MainFunction_10ms_OUT_MEM_Volt_SR_PP_Cell1Volt* MEM_Read_MainFunction_10ms_MEM_Volt_SR_PP_Cell1Volt;
	Rte_DE_Write_MEM_Read_MainFunction_10ms_OUT_MEM_Volt_SR_PP_Cell2Volt* MEM_Read_MainFunction_10ms_MEM_Volt_SR_PP_Cell2Volt;
	Rte_DE_Write_MEM_Read_MainFunction_10ms_OUT_MEM_Volt_SR_PP_Cell3Volt* MEM_Read_MainFunction_10ms_MEM_Volt_SR_PP_Cell3Volt;
	Rte_DE_Write_MEM_Read_MainFunction_10ms_OUT_MEM_Volt_SR_PP_Cell4Volt* MEM_Read_MainFunction_10ms_MEM_Volt_SR_PP_Cell4Volt;
	Rte_DE_Write_MEM_Read_MainFunction_10ms_OUT_MEM_Volt_SR_PP_PackVolt* MEM_Read_MainFunction_10ms_MEM_Volt_SR_PP_PackVolt;
	Rte_DE_Write_MEM_Read_MainFunction_10ms_OUT_MEM_Volt_SR_PP_OCV* MEM_Read_MainFunction_10ms_MEM_Volt_SR_PP_OCV;
	Rte_DE_Write_MEM_Read_MainFunction_10ms_OUT_MEM_Current_SR_PP_Current* MEM_Read_MainFunction_10ms_MEM_Current_SR_PP_Current;
	Rte_DE_Write_MEM_Read_MainFunction_10ms_OUT_MEM_Temp_SR_PP_Temp1* MEM_Read_MainFunction_10ms_MEM_Temp_SR_PP_Temp1;
	Rte_DE_Write_MEM_Read_MainFunction_10ms_OUT_MEM_Temp_SR_PP_Temp2* MEM_Read_MainFunction_10ms_MEM_Temp_SR_PP_Temp2;
	Rte_DE_Write_MEM_Read_MainFunction_10ms_OUT_MEM_Temp_SR_PP_Temp3* MEM_Read_MainFunction_10ms_MEM_Temp_SR_PP_Temp3;
	Rte_DE_Write_MEM_Read_MainFunction_10ms_OUT_MEM_Temp_SR_PP_BattTRaw* MEM_Read_MainFunction_10ms_MEM_Temp_SR_PP_BattTRaw;
	Rte_DE_Write_MEM_Read_MainFunction_10ms_OUT_MEM_SleepTime_SR_PP_SleepTime* MEM_Read_MainFunction_10ms_MEM_SleepTime_SR_PP_SleepTime;
	Rte_DE_Write_MEM_Read_MainFunction_10ms_OUT_MEM_BattFlt_SR_PP_BattSnsrHwFltRaw* MEM_Read_MainFunction_10ms_MEM_BattFlt_SR_PP_BattSnsrHwFltRaw;
	Rte_DE_Write_MEM_Read_MainFunction_10ms_OUT_MEM_BattFlt_SR_PP_BattSnsrCalcnNotVldRaw* MEM_Read_MainFunction_10ms_MEM_BattFlt_SR_PP_BattSnsrCalcnNotVldRaw;
	Rte_DE_Write_MEM_Read_MainFunction_10ms_OUT_MEM_BattFlt_SR_PP_BattFltStsPrim* MEM_Read_MainFunction_10ms_MEM_BattFlt_SR_PP_BattFltStsPrim;
	Rte_DE_Write_MEM_Read_MainFunction_10ms_OUT_MEM_BattSocRaw_SR_PP_BattSocRaw* MEM_Read_MainFunction_10ms_MEM_BattSocRaw_SR_PP_BattSocRaw;
} Rte_CDS_MEM_Read;

typedef struct 
{
	Rte_DE_Read_MEM_Write_MainFunction_10ms_IN_DIAG_BattFlt_SR_RP_CstnFltSt* MEM_Write_MainFunction_10ms_DIAG_BattFlt_SR_RP_CstnFltSt;
	Rte_DE_Read_MEM_Write_MainFunction_10ms_IN_DIAG_BattFlt_SR_RP_SnsrFltSt* MEM_Write_MainFunction_10ms_DIAG_BattFlt_SR_RP_SnsrFltSt;
	Rte_DE_Read_MEM_Write_MainFunction_10ms_IN_DIAG_BattFlt_SR_RP_SwFltSt* MEM_Write_MainFunction_10ms_DIAG_BattFlt_SR_RP_SwFltSt;
	Rte_DE_Read_MEM_Write_MainFunction_10ms_IN_SMP_Current_SR_RP_Current* MEM_Write_MainFunction_10ms_SMP_Current_SR_RP_Current;
	Rte_DE_Read_MEM_Write_MainFunction_10ms_IN_SMP_Volt_SR_RP_Cell1Volt* MEM_Write_MainFunction_10ms_SMP_Volt_SR_RP_Cell1Volt;
	Rte_DE_Read_MEM_Write_MainFunction_10ms_IN_SMP_Volt_SR_RP_Cell2Volt* MEM_Write_MainFunction_10ms_SMP_Volt_SR_RP_Cell2Volt;
	Rte_DE_Read_MEM_Write_MainFunction_10ms_IN_SMP_Volt_SR_RP_Cell3Volt* MEM_Write_MainFunction_10ms_SMP_Volt_SR_RP_Cell3Volt;
	Rte_DE_Read_MEM_Write_MainFunction_10ms_IN_SMP_Volt_SR_RP_Cell4Volt* MEM_Write_MainFunction_10ms_SMP_Volt_SR_RP_Cell4Volt;
	Rte_DE_Read_MEM_Write_MainFunction_10ms_IN_SMP_Volt_SR_RP_OCV* MEM_Write_MainFunction_10ms_SMP_Volt_SR_RP_OCV;
	Rte_DE_Read_MEM_Write_MainFunction_10ms_IN_SMP_Volt_SR_RP_PackVolt* MEM_Write_MainFunction_10ms_SMP_Volt_SR_RP_PackVolt;
	Rte_DE_Read_MEM_Write_MainFunction_10ms_IN_SMP_Temp_SR_RP_Temp* MEM_Write_MainFunction_10ms_SMP_Temp_SR_RP_Temp;
	Rte_DE_Read_MEM_Write_MainFunction_10ms_IN_SMP_Temp_SR_RP_Temp1* MEM_Write_MainFunction_10ms_SMP_Temp_SR_RP_Temp1;
	Rte_DE_Read_MEM_Write_MainFunction_10ms_IN_SMP_Temp_SR_RP_Temp2* MEM_Write_MainFunction_10ms_SMP_Temp_SR_RP_Temp2;
	Rte_DE_Read_MEM_Write_MainFunction_10ms_IN_SMP_Temp_SR_RP_Temp3* MEM_Write_MainFunction_10ms_SMP_Temp_SR_RP_Temp3;
	Rte_DE_Read_MEM_Write_MainFunction_10ms_IN_SMP_SleepTime_SR_RP_SleepTime* MEM_Write_MainFunction_10ms_SMP_SleepTime_SR_RP_SleepTime;
	Rte_DE_Read_MEM_Write_MainFunction_10ms_IN_SOC_Display_SR_RP_Display* MEM_Write_MainFunction_10ms_SOC_Display_SR_RP_Display;
} Rte_CDS_MEM_Write;

typedef struct 
{
	Rte_DE_Read_Runnable_RLY_IN_APPCOM_LinRx_BattRlyReqPrim_SR_RP_BattRlyReqPrim* Runnable_RLY_APPCOM_LinRx_BattRlyReqPrim_SR_RP_BattRlyReqPrim;
	Rte_DE_Read_Runnable_RLY_IN_APPCOM_LinRx_VehSpdLgt_SR_RP_VehSpdLgt* Runnable_RLY_APPCOM_LinRx_VehSpdLgt_SR_RP_VehSpdLgt;
	Rte_DE_Read_Runnable_RLY_IN_DIAG_RlyCutOffEnaSt_SR_RP_RlyCutOffEnaSt* Runnable_RLY_DIAG_RlyCutOffEnaSt_SR_RP_RlyCutOffEnaSt;
	Rte_DE_Read_Runnable_RLY_IN_AFE_RelayExt_SR_RP_RelayExt* Runnable_RLY_AFE_RelayExt_SR_RP_RelayExt;
	Rte_DE_Write_Runnable_RLY_OUT_RLY_BattRlyStsPrim_SR_PP_BattRlyStsPrim* Runnable_RLY_RLY_BattRlyStsPrim_SR_PP_BattRlyStsPrim;
} Rte_CDS_RLY;

typedef struct 
{
	Rte_DE_Read_SMP_MainFunction_10ms_IN_DIAG_BattFlt_SR_RP_SnsrFltSt* SMP_MainFunction_10ms_DIAG_BattFlt_SR_RP_SnsrFltSt;
	Rte_DE_Read_SMP_MainFunction_10ms_IN_SBC_WakeUp_SR_RP_WakeUpSource* SMP_MainFunction_10ms_SBC_WakeUp_SR_RP_WakeUpSource;
	Rte_DE_Read_SMP_MainFunction_10ms_IN_AFE_Temp_SR_RP_Temp3* SMP_MainFunction_10ms_AFE_Temp_SR_RP_Temp3;
	Rte_DE_Read_SMP_MainFunction_10ms_IN_AFE_Temp_SR_RP_Temp1* SMP_MainFunction_10ms_AFE_Temp_SR_RP_Temp1;
	Rte_DE_Read_SMP_MainFunction_10ms_IN_AFE_Temp_SR_RP_Temp2* SMP_MainFunction_10ms_AFE_Temp_SR_RP_Temp2;
	Rte_DE_Read_SMP_MainFunction_10ms_IN_AFE_Current_SR_RP_Current* SMP_MainFunction_10ms_AFE_Current_SR_RP_Current;
	Rte_DE_Read_SMP_MainFunction_10ms_IN_AFE_Volt_SR_RP_Cell1Volt* SMP_MainFunction_10ms_AFE_Volt_SR_RP_Cell1Volt;
	Rte_DE_Read_SMP_MainFunction_10ms_IN_AFE_Volt_SR_RP_Cell2Volt* SMP_MainFunction_10ms_AFE_Volt_SR_RP_Cell2Volt;
	Rte_DE_Read_SMP_MainFunction_10ms_IN_AFE_Volt_SR_RP_Cell3Volt* SMP_MainFunction_10ms_AFE_Volt_SR_RP_Cell3Volt;
	Rte_DE_Read_SMP_MainFunction_10ms_IN_AFE_Volt_SR_RP_Cell4Volt* SMP_MainFunction_10ms_AFE_Volt_SR_RP_Cell4Volt;
	Rte_DE_Read_SMP_MainFunction_10ms_IN_AFE_Volt_SR_RP_PackVolt* SMP_MainFunction_10ms_AFE_Volt_SR_RP_PackVolt;
	Rte_DE_Read_SMP_MainFunction_10ms_IN_MEM_Current_SR_RP_Current* SMP_MainFunction_10ms_MEM_Current_SR_RP_Current;
	Rte_DE_Read_SMP_MainFunction_10ms_IN_MEM_Volt_SR_RP_Cell1Volt* SMP_MainFunction_10ms_MEM_Volt_SR_RP_Cell1Volt;
	Rte_DE_Read_SMP_MainFunction_10ms_IN_MEM_Volt_SR_RP_Cell2Volt* SMP_MainFunction_10ms_MEM_Volt_SR_RP_Cell2Volt;
	Rte_DE_Read_SMP_MainFunction_10ms_IN_MEM_Volt_SR_RP_Cell3Volt* SMP_MainFunction_10ms_MEM_Volt_SR_RP_Cell3Volt;
	Rte_DE_Read_SMP_MainFunction_10ms_IN_MEM_Volt_SR_RP_Cell4Volt* SMP_MainFunction_10ms_MEM_Volt_SR_RP_Cell4Volt;
	Rte_DE_Read_SMP_MainFunction_10ms_IN_MEM_Volt_SR_RP_OCV* SMP_MainFunction_10ms_MEM_Volt_SR_RP_OCV;
	Rte_DE_Read_SMP_MainFunction_10ms_IN_MEM_Volt_SR_RP_PackVolt* SMP_MainFunction_10ms_MEM_Volt_SR_RP_PackVolt;
	Rte_DE_Read_SMP_MainFunction_10ms_IN_MEM_Temp_SR_RP_BattTRaw* SMP_MainFunction_10ms_MEM_Temp_SR_RP_BattTRaw;
	Rte_DE_Read_SMP_MainFunction_10ms_IN_MEM_Temp_SR_RP_Temp1* SMP_MainFunction_10ms_MEM_Temp_SR_RP_Temp1;
	Rte_DE_Read_SMP_MainFunction_10ms_IN_MEM_Temp_SR_RP_Temp2* SMP_MainFunction_10ms_MEM_Temp_SR_RP_Temp2;
	Rte_DE_Read_SMP_MainFunction_10ms_IN_MEM_Temp_SR_RP_Temp3* SMP_MainFunction_10ms_MEM_Temp_SR_RP_Temp3;
	Rte_DE_Read_SMP_MainFunction_10ms_IN_MEM_SleepTime_SR_RP_SleepTime* SMP_MainFunction_10ms_MEM_SleepTime_SR_RP_SleepTime;
	Rte_DE_Read_SMP_MainFunction_10ms_IN_DIAG_SnsrFltSt_SR_RP_SnsrFltSt* SMP_MainFunction_10ms_DIAG_SnsrFltSt_SR_RP_SnsrFltSt;
	Rte_DE_Write_SMP_MainFunction_10ms_OUT_SMP_Volt_SR_PP_Cell1Volt* SMP_MainFunction_10ms_SMP_Volt_SR_PP_Cell1Volt;
	Rte_DE_Write_SMP_MainFunction_10ms_OUT_SMP_Volt_SR_PP_Cell2Volt* SMP_MainFunction_10ms_SMP_Volt_SR_PP_Cell2Volt;
	Rte_DE_Write_SMP_MainFunction_10ms_OUT_SMP_Volt_SR_PP_Cell3Volt* SMP_MainFunction_10ms_SMP_Volt_SR_PP_Cell3Volt;
	Rte_DE_Write_SMP_MainFunction_10ms_OUT_SMP_Volt_SR_PP_Cell4Volt* SMP_MainFunction_10ms_SMP_Volt_SR_PP_Cell4Volt;
	Rte_DE_Write_SMP_MainFunction_10ms_OUT_SMP_CellVoltRange_SR_PP_CellVoltMax* SMP_MainFunction_10ms_SMP_CellVoltRange_SR_PP_CellVoltMax;
	Rte_DE_Write_SMP_MainFunction_10ms_OUT_SMP_CellVoltRange_SR_PP_CellVoltMin* SMP_MainFunction_10ms_SMP_CellVoltRange_SR_PP_CellVoltMin;
	Rte_DE_Write_SMP_MainFunction_10ms_OUT_SMP_Volt_SR_PP_PackVolt* SMP_MainFunction_10ms_SMP_Volt_SR_PP_PackVolt;
	Rte_DE_Write_SMP_MainFunction_10ms_OUT_SMP_Volt_SR_PP_OCV* SMP_MainFunction_10ms_SMP_Volt_SR_PP_OCV;
	Rte_DE_Write_SMP_MainFunction_10ms_OUT_SMP_Current_SR_PP_Current* SMP_MainFunction_10ms_SMP_Current_SR_PP_Current;
	Rte_DE_Write_SMP_MainFunction_10ms_OUT_SMP_Temp_SR_PP_Temp1* SMP_MainFunction_10ms_SMP_Temp_SR_PP_Temp1;
	Rte_DE_Write_SMP_MainFunction_10ms_OUT_SMP_Temp_SR_PP_Temp2* SMP_MainFunction_10ms_SMP_Temp_SR_PP_Temp2;
	Rte_DE_Write_SMP_MainFunction_10ms_OUT_SMP_Temp_SR_PP_Temp3* SMP_MainFunction_10ms_SMP_Temp_SR_PP_Temp3;
	Rte_DE_Write_SMP_MainFunction_10ms_OUT_SMP_Temp_SR_PP_Temp* SMP_MainFunction_10ms_SMP_Temp_SR_PP_Temp;
	Rte_DE_Write_SMP_MainFunction_10ms_OUT_SMP_TempRange_SR_PP_TempMax* SMP_MainFunction_10ms_SMP_TempRange_SR_PP_TempMax;
	Rte_DE_Write_SMP_MainFunction_10ms_OUT_SMP_TempRange_SR_PP_TempMin* SMP_MainFunction_10ms_SMP_TempRange_SR_PP_TempMin;
	Rte_DE_Write_SMP_MainFunction_10ms_OUT_SMP_SleepTime_SR_PP_SleepTime* SMP_MainFunction_10ms_SMP_SleepTime_SR_PP_SleepTime;
} Rte_CDS_SMP;

typedef struct 
{
	Rte_DE_Read_SOC_MainFunction_10ms_IN_MEM_BattSocRaw_SR_RP_BattSocRaw* SOC_MainFunction_10ms_MEM_BattSocRaw_SR_RP_BattSocRaw;
	Rte_DE_Read_SOC_MainFunction_10ms_IN_SMP_Current_SR_RP_Current* SOC_MainFunction_10ms_SMP_Current_SR_RP_Current;
	Rte_DE_Read_SOC_MainFunction_10ms_IN_SMP_CellVoltRange_SR_RP_CellVoltMax* SOC_MainFunction_10ms_SMP_CellVoltRange_SR_RP_CellVoltMax;
	Rte_DE_Read_SOC_MainFunction_10ms_IN_SMP_CellVoltRange_SR_RP_CellVoltMin* SOC_MainFunction_10ms_SMP_CellVoltRange_SR_RP_CellVoltMin;
	Rte_DE_Read_SOC_MainFunction_10ms_IN_SMP_TempRange_SR_RP_TempMax* SOC_MainFunction_10ms_SMP_TempRange_SR_RP_TempMax;
	Rte_DE_Write_SOC_MainFunction_10ms_OUT_SOC_Display_SR_PP_Display* SOC_MainFunction_10ms_SOC_Display_SR_PP_Display;
	Rte_DE_Write_SOC_MainFunction_10ms_OUT_SOC_Target_SR_PP_Target* SOC_MainFunction_10ms_SOC_Target_SR_PP_Target;
} Rte_CDS_SOC;

typedef struct 
{
	Rte_DE_Write_TLF35584_MainFunction_10ms_OUT_SBC_WakeUp_SR_PP_WakeUpSource* TLF35584_MainFunction_10ms_SBC_WakeUp_SR_PP_WakeUpSource;
} Rte_CDS_TLF35584;



#endif

