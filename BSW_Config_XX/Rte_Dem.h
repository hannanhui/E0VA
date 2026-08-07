/*============================================================================*/
/*  Copyright (C) iSOFT   (2022), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Rte_Dem.h>
 *  @brief      <>
 *  
 *  <MCU:Z20K144M>
 *  
 *  @author     <>
 *  @date       <2025-02-07 16:03:36>
 */
/*============================================================================*/

#ifndef RTEDEM_H
#define RTEDEM_H

#include "Dem_Types.h"
#include "NvM_Types.h"

extern Std_ReturnType  Rte_SnapshotDataRead_DD00H( uint8* Buffer );
extern Std_ReturnType  Rte_SnapshotDataRead_DD01H( uint8* Buffer );
extern Std_ReturnType  Rte_SnapshotDataRead_DD02H( uint8* Buffer );
extern Std_ReturnType  Rte_SnapshotDataRead_DD0AH( uint8* Buffer );
extern Std_ReturnType  Rte_SnapshotDataRead_DD0CH( uint8* Buffer );
extern Std_ReturnType  Rte_ExtendedData_Read_DTC_Time_Stamp_20( uint8* Buffer );
extern Std_ReturnType  Rte_ExtendedData_Read_DTC_Time_Stamp_21( uint8* Buffer );
extern Std_ReturnType  Rte_Call_Dem_CS_DataServices_DemDataElementClass_OCC6_ReadData( uint8* Buffer );
extern Std_ReturnType  Rte_Call_Dem_CS_DataServices_DemDataElementClass_SI30_ReadData( uint8* Buffer );
extern void            Rte_NvMNotifyJobFinished_MultiBlock(NvM_MultiBlockRequestType MultiBlockRequest, NvM_RequestResultType JobResult);
#endif /*RTEDEM_H*/
