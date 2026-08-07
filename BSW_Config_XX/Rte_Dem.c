/*============================================================================*/
/*  Copyright (C) iSOFT   (2022), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Rte_Dem.c>
 *  @brief      <>
 *  
 *  <MCU:Z20K144M>
 *  
 *  @author     <>
 *  @date       <2025-02-07 16:03:35>
 */
/*============================================================================*/

#include "Rte_Dem.h"
#include "Dem.h"
#ifdef OEM_SPECIFI_GEELY_2P0
#include "Dem_Internal.h"
extern VAR(Dem_InternalDataType, AUTOMATIC) DemInternalData;
#endif


Std_ReturnType  Rte_SnapshotDataRead_DD00H( uint8* Buffer )
{
    return E_OK;
};
Std_ReturnType  Rte_SnapshotDataRead_DD01H( uint8* Buffer )
{
    return E_OK;
};
Std_ReturnType  Rte_SnapshotDataRead_DD02H( uint8* Buffer )
{
    return E_OK;
};
Std_ReturnType  Rte_SnapshotDataRead_DD0AH( uint8* Buffer )
{
    return E_OK;
};
Std_ReturnType  Rte_SnapshotDataRead_DD0CH( uint8* Buffer )
{
    return E_OK;
};
Std_ReturnType  Rte_ExtendedData_Read_DTC_Time_Stamp_20( uint8* Buffer )
{
    return E_OK;
};
Std_ReturnType  Rte_ExtendedData_Read_DTC_Time_Stamp_21( uint8* Buffer )
{
    return E_OK;
};
Std_ReturnType  Rte_Call_Dem_CS_DataServices_DemDataElementClass_OCC6_ReadData( uint8* Buffer )
{
#ifdef OEM_SPECIFI_GEELY_2P0
    /* OCC6 */
    *Buffer = DemInternalData.CyclesConsecutiveFailed;
#endif /* OEM_SPECIFI_GEELY_2P0 */  
    return E_OK;
};
Std_ReturnType  Rte_Call_Dem_CS_DataServices_DemDataElementClass_SI30_ReadData( uint8* Buffer )
{
#ifdef OEM_SPECIFI_GEELY_2P0
    *Buffer = 0x0;
#endif /* OEM_SPECIFI_GEELY_2P0 */     
    return E_OK;
};
void Rte_NvMNotifyJobFinished_MultiBlock(NvM_MultiBlockRequestType MultiBlockRequest, NvM_RequestResultType JobResult)
{
    extern uint8 NvM_InitReadAll_Flag; // shared with main.c 
    if(0 == NvM_InitReadAll_Flag && 
        JobResult != NVM_REQ_PENDING && 
        MultiBlockRequest == NVM_READ_ALL)
    {
        Dem_Init(&DemPbCfg);
        Dem_SetOperationCycleState((uint8)0, DEM_CYCLE_STATE_START);
        NvM_InitReadAll_Flag = 1;
    }
}
