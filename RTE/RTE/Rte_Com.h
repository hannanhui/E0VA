/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Rte_Com.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : Rte module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : Rte module configuration File
*
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*
*   Version     Date          Initials      CR#          Descriptions
*   ---------   ----------    ------------  ----------   ---------------
*   3.4.0       19/04/2022    Eas           N/A          N/A
*
********************************************************************************
* END_FILE_HDR*/
#ifndef RTE_COM_H
#define RTE_COM_H

#ifndef RTE_CORE
#ifdef RTE_APPLICATION_HEADER_FILE
#error Multiple application header files included.
#endif /* RTE_APPLICATION_HEADER_FILE */
#define RTE_APPLICATION_HEADER_FILE
#endif
# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/*******************************************************************************
*   Includes.
*******************************************************************************/
#include "Com.h"
//#include "Rte_Com_Type.h"
#define RTE_START_SEC_CODE
//#include "MemMap.h"

#define Rte_Read_LatAccr Rte_Write_Com_SoftwareVersion
extern FUNC(Std_ReturnType,RTE_CODE)Rte_Write_Com_SoftwareVersion(P2VAR(uint8,AUTOMATIC,RTE_APPL_DATA) data);
#define Rte_Write_HardwareVersion Rte_Write_Com_HardwareVersion
extern FUNC(Std_ReturnType,RTE_CODE)Rte_Write_Com_HardwareVersion(P2VAR(uint8,AUTOMATIC,RTE_APPL_DATA) data);
#define Rte_Write_DriveSeatMsgStr_Lvlsts Rte_Write_Com_DriveSeatMsgStr_Lvlsts
extern FUNC(Std_ReturnType,RTE_CODE)Rte_Write_Com_DriveSeatMsgStr_Lvlsts(P2VAR(uint8,AUTOMATIC,RTE_APPL_DATA) data);
#define Rte_Write_DriverSeatMsg_ModeSts Rte_Write_Com_DriverSeatMsg_ModeSts
extern FUNC(Std_ReturnType,RTE_CODE)Rte_Write_Com_DriverSeatMsg_ModeSts(P2VAR(uint8,AUTOMATIC,RTE_APPL_DATA) data);
#define Rte_Write_DSMM_Rsp_Error Rte_Write_Com_DSMM_Rsp_Error
extern FUNC(Std_ReturnType,RTE_CODE)Rte_Write_Com_DSMM_Rsp_Error(P2VAR(boolean,AUTOMATIC,RTE_APPL_DATA) data);
#define Rte_Write_DrvLumSpprtSwtFct Rte_Write_Com_DrvLumSpprtSwtFct
extern FUNC(Std_ReturnType,RTE_CODE)Rte_Write_Com_DrvLumSpprtSwtFct(P2VAR(boolean,AUTOMATIC,RTE_APPL_DATA) data);
#define Rte_Write_DrvSeatLeSideBolsterFltSt Rte_Write_Com_DrvSeatLeSideBolsterFltSt
extern FUNC(Std_ReturnType,RTE_CODE)Rte_Write_Com_DrvSeatLeSideBolsterFltSt(P2VAR(uint8,AUTOMATIC,RTE_APPL_DATA) data);
#define Rte_Write_DrvSeatRiSideBolsterFltSt Rte_Write_Com_DrvSeatRiSideBolsterFltSt
extern FUNC(Std_ReturnType,RTE_CODE)Rte_Write_Com_DrvSeatRiSideBolsterFltSt(P2VAR(uint8,AUTOMATIC,RTE_APPL_DATA) data);
#define Rte_Write_DrvSeatLeSideBolsterNTCOverT Rte_Write_Com_DrvSeatLeSideBolsterNTCOverT
extern FUNC(Std_ReturnType,RTE_CODE)Rte_Write_Com_DrvSeatLeSideBolsterNTCOverT(P2VAR(boolean,AUTOMATIC,RTE_APPL_DATA) data);
#define Rte_Write_DrvSeatRiSideBolsterNTCOverT Rte_Write_Com_DrvSeatRiSideBolsterNTCOverT
extern FUNC(Std_ReturnType,RTE_CODE)Rte_Write_Com_DrvSeatRiSideBolsterNTCOverT(P2VAR(boolean,AUTOMATIC,RTE_APPL_DATA) data);
#define Rte_Write_DrvSeatLeSideBolsterPSnsrFlt Rte_Write_Com_DrvSeatLeSideBolsterPSnsrFlt
extern FUNC(Std_ReturnType,RTE_CODE)Rte_Write_Com_DrvSeatLeSideBolsterPSnsrFlt(P2VAR(boolean,AUTOMATIC,RTE_APPL_DATA) data);
#define Rte_Write_DrvSeatMainAirwayPSnsrFlt Rte_Write_Com_DrvSeatMainAirwayPSnsrFlt
extern FUNC(Std_ReturnType,RTE_CODE)Rte_Write_Com_DrvSeatMainAirwayPSnsrFlt(P2VAR(boolean,AUTOMATIC,RTE_APPL_DATA) data);
#define Rte_Write_DrvSeatRiSideBolsterPSnsrFlt Rte_Write_Com_DrvSeatRiSideBolsterPSnsrFlt
extern FUNC(Std_ReturnType,RTE_CODE)Rte_Write_Com_DrvSeatRiSideBolsterPSnsrFlt(P2VAR(uint8,AUTOMATIC,RTE_APPL_DATA) data);
#define Rte_Write_AirPotPressure Rte_Write_Com_AirPotPressure
extern FUNC(Std_ReturnType,RTE_CODE)Rte_Write_Com_AirPotPressure(P2VAR(uint8,AUTOMATIC,RTE_APPL_DATA) data);
#define Rte_Write_AirPotPressureSnsFlt Rte_Write_Com_AirPotPressureSnsFlt
extern FUNC(Std_ReturnType,RTE_CODE)Rte_Write_Com_AirPotPressureSnsFlt(P2VAR(boolean,AUTOMATIC,RTE_APPL_DATA) data);
#define Rte_Write_VoltageState Rte_Write_Com_VoltageState
extern FUNC(Std_ReturnType,RTE_CODE)Rte_Write_Com_VoltageState(P2VAR(uint8,AUTOMATIC,RTE_APPL_DATA) data);
#define Rte_Write_PumFlt Rte_Write_Com_PumFlt
extern FUNC(Std_ReturnType,RTE_CODE)Rte_Write_Com_PumFlt(P2VAR(boolean,AUTOMATIC,RTE_APPL_DATA) data);
#define Rte_Write_ValveFlt Rte_Write_Com_ValveFlt
extern FUNC(Std_ReturnType,RTE_CODE)Rte_Write_Com_ValveFlt(P2VAR(boolean,AUTOMATIC,RTE_APPL_DATA) data);
#define Rte_Write_EnvPressureSnsFlt Rte_Write_Com_EnvPressureSnsFlt
extern FUNC(Std_ReturnType,RTE_CODE)Rte_Write_Com_EnvPressureSnsFlt(P2VAR(boolean,AUTOMATIC,RTE_APPL_DATA) data);
#define Rte_Write_DrvSeatLeSidBolsterInflatuinSts Rte_Write_Com_DrvSeatLeSidBolsterInflatuinSts
extern FUNC(Std_ReturnType,RTE_CODE)Rte_Write_Com_DrvSeatLeSidBolsterInflatuinSts(P2VAR(uint8,AUTOMATIC,RTE_APPL_DATA) data);
#define Rte_Write_DrvSeatRiSideBolsterInflationSts Rte_Write_Com_DrvSeatRiSideBolsterInflationSts
extern FUNC(Std_ReturnType,RTE_CODE)Rte_Write_Com_DrvSeatRiSideBolsterInflationSts(P2VAR(uint8,AUTOMATIC,RTE_APPL_DATA) data);
#define Rte_Read_FuelVehPowerMode Rte_Read_Com_FuelVehPowerMode
extern FUNC(Std_ReturnType,RTE_CODE)Rte_Read_Com_FuelVehPowerMode(P2VAR(uint8,AUTOMATIC,RTE_APPL_DATA) data);
#define Rte_Read_DriverSeatMsgStr_Lvlcmd Rte_Read_Com_DriverSeatMsgStr_Lvlcmd
extern FUNC(Std_ReturnType,RTE_CODE)Rte_Read_Com_DriverSeatMsgStr_Lvlcmd(P2VAR(uint8,AUTOMATIC,RTE_APPL_DATA) data);
#define Rte_Read_DriveSeatMsg_ModeCmd Rte_Read_Com_DriveSeatMsg_ModeCmd
extern FUNC(Std_ReturnType,RTE_CODE)Rte_Read_Com_DriveSeatMsg_ModeCmd(P2VAR(uint8,AUTOMATIC,RTE_APPL_DATA) data);
#define Rte_Read_PowerMode Rte_Read_Com_PowerMode
extern FUNC(Std_ReturnType,RTE_CODE)Rte_Read_Com_PowerMode(P2VAR(uint8,AUTOMATIC,RTE_APPL_DATA) data);
#define Rte_Read_APC_Level_Limit Rte_Read_Com_APC_Level_Limit
extern FUNC(Std_ReturnType,RTE_CODE)Rte_Read_Com_APC_Level_Limit(P2VAR(uint8,AUTOMATIC,RTE_APPL_DATA) data);
#define Rte_Read_DrvSeatRisSideBolsterInflationReq Rte_Read_Com_DrvSeatRisSideBolsterInflationReq
extern FUNC(Std_ReturnType,RTE_CODE)Rte_Read_Com_DrvSeatRisSideBolsterInflationReq(P2VAR(uint8,AUTOMATIC,RTE_APPL_DATA) data);
#define Rte_Read_DrvSeatLeSideBolsterInflationReq Rte_Read_Com_DrvSeatLeSideBolsterInflationReq
extern FUNC(Std_ReturnType,RTE_CODE)Rte_Read_Com_DrvSeatLeSideBolsterInflationReq(P2VAR(uint8,AUTOMATIC,RTE_APPL_DATA) data);



#define RTE_STOP_SEC_CODE
//#include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif  /*RTE_COM_H*/


