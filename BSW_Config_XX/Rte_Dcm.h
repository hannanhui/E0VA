/*============================================================================*/
/*  Copyright (C) iSOFT   (2022), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Rte_Dcm.h>
 *  @brief      <>
 *  
 *  <MCU:Z20K144M>
 *  
 *  @author     <>
 *  @date       <2025-02-07 16:03:35>
 */
/*============================================================================*/

#ifndef RTEDCM_H
#define RTEDCM_H

#include "Rte_Dcm_Type.h"

extern  Std_ReturnType  Dcm_DcmDslCallbackDCMRequestService_0_StartProtocol;
extern  Std_ReturnType  Dcm_DcmDslCallbackDCMRequestService_0_StopProtocol;

#define  DataLength_DcmDspData_F1FEH 8
extern uint8 Buffer_DcmDspData_F1FEH[ DataLength_DcmDspData_F1FEH ];
/***************************Security Part****************************************/

/***************************Did Part****************************************/

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataConditionCheck_220AH( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataConditionCheck_D03AH( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataConditionCheck_D0B5H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataConditionCheck_D109H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataConditionCheck_D110H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataConditionCheck_D134H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataConditionCheck_D214H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataConditionCheck_D291H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataConditionCheck_D907H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataConditionCheck_457EH( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataConditionCheck_DD00H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataConditionCheck_DD01H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataConditionCheck_DD02H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataConditionCheck_DD0AH( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataConditionCheck_DD0CH( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataConditionCheck_F120H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataConditionCheck_F121H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataConditionCheck_F125H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataConditionCheck_F126H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataConditionCheck_F12AH( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataConditionCheck_F12BH( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataConditionCheck_F12EH( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataConditionCheck_F186H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataConditionCheck_F18AH( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataConditionCheck_F18CH( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataConditionCheck_F1A0H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataConditionCheck_F1A1H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataConditionCheck_F1A5H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataConditionCheck_F1AAH( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataConditionCheck_F1ABH( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataConditionCheck_F1AEH( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataConditionCheck_F1F8H( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataConditionCheck_F1FAH( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataConditionCheck_F1FBH( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataConditionCheck_F1FEH( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataConditionCheck_F1FFH( Dcm_OpStatusType  OpStatus,  Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataRead_220AH( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataRead_D03AH( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataRead_D0B5H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataRead_D109H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataRead_D110H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataRead_D134H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataRead_D214H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataRead_D291H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataRead_D907H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataRead_457EH( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataRead_DD00H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataRead_DD01H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataRead_DD02H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataRead_DD0AH( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataRead_DD0CH( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataRead_F120H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataRead_F121H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataRead_F125H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataRead_F126H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataRead_F12AH( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataRead_F12BH( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataRead_F12EH( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataRead_F186H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataRead_F18AH( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataRead_F18CH( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataRead_F1A0H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataRead_F1A1H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataRead_F1A5H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataRead_F1AAH( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataRead_F1ABH( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataRead_F1AEH( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataRead_F1F8H( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataRead_F1FAH( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataRead_F1FBH( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataRead_F1FEH( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataRead_F1FFH( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataRead_F1A0H_Name( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataRead_F1AAH_Name( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataRead_F1ABH_Name( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataRead_F18CH_Name( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataRead_F1AEH_Name( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataRead_F120H_Name( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataRead_F12AH_Name( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataRead_F12BH_Name( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_DataRead_F12EH_Name( Dcm_OpStatusType  OpStatus,uint8*  Data,Dcm_NegativeResponseCodeType*  ErrorCode );
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/***************************Routine Part****************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_RoutineRequest_202AH(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        Dcm_OpStatusType OpStatus,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_RoutineRequest_203DH(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        Dcm_OpStatusType OpStatus,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_RoutineRequest_F010H(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        Dcm_OpStatusType OpStatus,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_RoutineRequest_F011H(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        Dcm_OpStatusType OpStatus,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_RoutineRequest_F012H(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        Dcm_OpStatusType OpStatus,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_RoutineRequest_F013H(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        Dcm_OpStatusType OpStatus,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_RoutineRequest_F014H(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        Dcm_OpStatusType OpStatus,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_RoutineRequest_F015H(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        Dcm_OpStatusType OpStatus,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_RoutineStart_0206H(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        Dcm_OpStatusType OpStatus,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_RoutineStart_202AH(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        Dcm_OpStatusType OpStatus,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_RoutineStart_203DH(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        Dcm_OpStatusType OpStatus,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_RoutineStart_F010H(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        Dcm_OpStatusType OpStatus,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_RoutineStart_F011H(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        Dcm_OpStatusType OpStatus,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_RoutineStart_F012H(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        Dcm_OpStatusType OpStatus,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_RoutineStart_F013H(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        Dcm_OpStatusType OpStatus,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_RoutineStart_F014H(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        Dcm_OpStatusType OpStatus,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_RoutineStart_F015H(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        Dcm_OpStatusType OpStatus,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_RoutineStop_202AH(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        Dcm_OpStatusType OpStatus,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_RoutineStop_203DH(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        Dcm_OpStatusType OpStatus,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_RoutineStop_F010H(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        Dcm_OpStatusType OpStatus,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_RoutineStop_F011H(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        Dcm_OpStatusType OpStatus,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_RoutineStop_F012H(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        Dcm_OpStatusType OpStatus,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_RoutineStop_F013H(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        Dcm_OpStatusType OpStatus,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_RoutineStop_F014H(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        Dcm_OpStatusType OpStatus,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  Rte_RoutineStop_F015H(
        P2VAR(uint8,AUTOMATIC,DCM_VAR)InBuffer,
        Dcm_OpStatusType OpStatus,
        P2VAR(uint8,AUTOMATIC,DCM_VAR)OutBuffer,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_VAR)ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/**************function for ClearDTC**************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern Std_ReturnType Rte_ClearDTCCheck(uint32 GoDTC,Dcm_NegativeResponseCodeType* ErrorCode);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/*******function for Protocol Start and stop***********/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  Std_ReturnType  DcmDslCallbackDCMRequestService_0_StartProtocol(Dcm_ProtocolType  ProtocolID);
extern  Std_ReturnType  DcmDslCallbackDCMRequestService_0_StopProtocol(Dcm_ProtocolType  ProtocolID);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/********* PreConditon Check ***********************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
//extern Std_ReturnType Dcm_Rte_PreConditonCheck;
extern Std_ReturnType RTE_PreConditonCheck(	uint8 SID, uint8 Subfunction);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern Std_ReturnType SchM_PerformReset(Rte_ModeType_DcmEcuReset Reset);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

extern Std_ReturnType Rte_IsPublicKeyWritten();
extern Std_ReturnType Rte_IsSecurityConstantWritten();

#endif /*RTEDCM_H*/
