
#include "Rte_Com.h"



static boolean CommStWithVCCD = FALSE;
static boolean CommStWithACU = FALSE;

FUNC(Std_ReturnType,RTE_CODE)Rte_Write_Com_SoftwareVersion(P2VAR(uint8,AUTOMATIC,RTE_APPL_DATA) data)
{
    Std_ReturnType ret = E_OK;
    ret = Com_SendSignal(ComConf_ComSignal_SoftwareVersion_Tx, data);
    return ret;
};





FUNC(Std_ReturnType,RTE_CODE)Rte_Write_Com_HardwareVersion(P2VAR(uint8,AUTOMATIC,RTE_APPL_DATA) data)
{
    Std_ReturnType ret = E_OK;
    ret = Com_SendSignal(ComConf_ComSignal_HardwareVersion_Tx, data);
    return ret;
};




FUNC(Std_ReturnType,RTE_CODE)Rte_Write_Com_DriveSeatMsgStr_Lvlsts(P2VAR(uint8,AUTOMATIC,RTE_APPL_DATA) data)
{
    Std_ReturnType ret = E_OK;
    ret = Com_SendSignal(ComConf_ComSignal_DriveSeatMsgStr_Lvlsts_Tx, data);
    return ret;
};



FUNC(Std_ReturnType,RTE_CODE)Rte_Write_Com_DriverSeatMsg_ModeSts(P2VAR(uint8,AUTOMATIC,RTE_APPL_DATA) data)
{
    Std_ReturnType ret = E_OK;
    ret = Com_SendSignal(ComConf_ComSignal_DriverSeatMsg_ModeSts_Tx, data);
    return ret;
};




FUNC(Std_ReturnType,RTE_CODE)Rte_Write_Com_DSMM_Rsp_Error(P2VAR(boolean,AUTOMATIC,RTE_APPL_DATA) data)
{
    Std_ReturnType ret = E_OK;
    ret = Com_SendSignal(ComConf_ComSignal_DSMM_Rsp_Error_Tx, data);
    return ret;
};



FUNC(Std_ReturnType,RTE_CODE)Rte_Write_Com_DrvLumSpprtSwtFct(P2VAR(uint8,AUTOMATIC,RTE_APPL_DATA) data)
{
    Std_ReturnType ret = E_OK;
    ret = Com_SendSignal(ComConf_ComSignal_DrvLumSpprtSwtFct_Tx, data);
    return ret;
};


FUNC(Std_ReturnType,RTE_CODE)Rte_Write_Com_DrvSeatLeSideBolsterFltSt(P2VAR(uint8,AUTOMATIC,RTE_APPL_DATA) data)
{
    Std_ReturnType ret = E_OK;
    ret = Com_SendSignal(ComConf_ComSignal_DrvSeatLeSideBolsterFltSt_Tx, data);
    return ret;
};




FUNC(Std_ReturnType,RTE_CODE)Rte_Write_Com_DrvSeatRiSideBolsterFltSt(P2VAR(uint8,AUTOMATIC,RTE_APPL_DATA) data)
{
    Std_ReturnType ret = E_OK;
    ret = Com_ReceiveSignal(ComConf_ComSignal_DrvSeatRiSideBolsterFltSt_Tx, data);
    return ret;
};



FUNC(Std_ReturnType,RTE_CODE)Rte_Write_Com_DrvSeatLeSideBolsterNTCOverT(P2VAR(boolean,AUTOMATIC,RTE_APPL_DATA) data)
{
    Std_ReturnType ret = E_OK;
    ret = Com_SendSignal(ComConf_ComSignal_DrvSeatLeSideBolsterNTCOverT_Tx, data);
    return ret;
};



FUNC(Std_ReturnType,RTE_CODE)Rte_Write_Com_DrvSeatRiSideBolsterNTCOverT(P2VAR(boolean,AUTOMATIC,RTE_APPL_DATA) data)
{
    Std_ReturnType ret = E_OK;
    ret = Com_SendSignal(ComConf_ComSignal_DrvSeatRiSideBolsterNTCOverT_Tx, data);
    return ret;
};



FUNC(Std_ReturnType,RTE_CODE)Rte_Write_Com_DrvSeatLeSideBolsterPSnsrFlt(P2VAR(boolean,AUTOMATIC,RTE_APPL_DATA) data)
{
    Std_ReturnType ret = E_OK;
    ret = Com_SendSignal(ComConf_ComSignal_DrvSeatLeSideBolsterPSnsrFlt_Tx, data);
    return ret;
};





FUNC(Std_ReturnType,RTE_CODE)Rte_Write_Com_DrvSeatMainAirwayPSnsrFlt(P2VAR(boolean,AUTOMATIC,RTE_APPL_DATA) data)
{
    Std_ReturnType ret = E_OK;
    ret = Com_SendSignal(ComConf_ComSignal_DrvSeatMainAirwayPSnsrFlt_Tx, data);
    return ret;
};



FUNC(Std_ReturnType,RTE_CODE)Rte_Write_Com_DrvSeatRiSideBolsterPSnsrFlt(P2VAR(boolean,AUTOMATIC,RTE_APPL_DATA) data)
{
    Std_ReturnType ret = E_OK;
    ret = Com_SendSignal(ComConf_ComSignal_DrvSeatRiSideBolsterPSnsrFlt_Tx, data);
    return ret;
};



FUNC(Std_ReturnType,RTE_CODE)Rte_Write_Com_AirPotPressure(P2VAR(uint8,AUTOMATIC,RTE_APPL_DATA) data)
{
    Std_ReturnType ret = E_OK;
    ret = Com_SendSignal(ComConf_ComSignal_AirPotPressure_Tx, data);
    return ret;
};



FUNC(Std_ReturnType,RTE_CODE)Rte_Write_Com_AirPotPressureSnsFlt(P2VAR(boolean,AUTOMATIC,RTE_APPL_DATA) data)
{
    Std_ReturnType ret = E_OK;
    ret = Com_SendSignal(ComConf_ComSignal_AirPotPressureSnsFlt_Tx, data);
    return ret;
};




FUNC(Std_ReturnType,RTE_CODE)Rte_Write_Com_VoltageState(P2VAR(uint8,AUTOMATIC,RTE_APPL_DATA) data)
{
    Std_ReturnType ret = E_OK;
    ret = Com_SendSignal(ComConf_ComSignal_VoltageState_Tx, data);
    return ret;
};




FUNC(Std_ReturnType,RTE_CODE)Rte_Write_Com_PumFlt(P2VAR(boolean,AUTOMATIC,RTE_APPL_DATA) data)
{
    Std_ReturnType ret = E_OK;
    ret = Com_SendSignal(ComConf_ComSignal_PumFlt_Tx, data);
    return ret;
};


FUNC(Std_ReturnType,RTE_CODE)Rte_Write_Com_ValveFlt(P2VAR(boolean,AUTOMATIC,RTE_APPL_DATA) data)
{
    Std_ReturnType ret = E_OK;
    ret = Com_SendSignal(ComConf_ComSignal_ValveFlt_Tx, data);
    return ret;
};



FUNC(Std_ReturnType,RTE_CODE)Rte_Write_Com_EnvPressureSnsFlt(P2VAR(boolean,AUTOMATIC,RTE_APPL_DATA) data)
{
    Std_ReturnType ret = E_OK;
    ret = Com_SendSignal(ComConf_ComSignal_EnvPressureSnsFlt_Tx, data);
    return ret;
};



FUNC(Std_ReturnType,RTE_CODE)Rte_Write_Com_DrvSeatLeSidBolsterInflatuinSts(P2VAR(uint8,AUTOMATIC,RTE_APPL_DATA) data)
{
    Std_ReturnType ret = E_OK;
    ret = Com_SendSignal(ComConf_ComSignal_DrvSeatLeSidBolsterInflatuinSts_Tx, data);
    return ret;
};


FUNC(Std_ReturnType,RTE_CODE)Rte_Write_Com_DrvSeatRiSideBolsterInflationSts(P2VAR(uint8,AUTOMATIC,RTE_APPL_DATA) data)
{
    Std_ReturnType ret = E_OK;
    ret = Com_SendSignal(ComConf_ComSignal_DrvSeatRiSideBolsterInflationSts_Tx, data);
    return ret;
};




FUNC(Std_ReturnType,RTE_CODE)Rte_Read_Com_FuelVehPowerMode(P2VAR(uint8,AUTOMATIC,RTE_APPL_DATA) data)
{
    Std_ReturnType ret = E_OK;
    ret = Com_ReceiveSignal(ComConf_ComSignal_FuelVehPowerMode_Rx, data);
    return ret;
};



FUNC(Std_ReturnType,RTE_CODE)Rte_Read_Com_DriverSeatMsgStr_Lvlcmd(P2VAR(uint8,AUTOMATIC,RTE_APPL_DATA) data)
{
    Std_ReturnType ret = E_OK;
    ret = Com_ReceiveSignal(ComConf_ComSignal_DriverSeatMsgStr_Lvlcmd_Rx, data);
    return ret;
};


FUNC(Std_ReturnType,RTE_CODE)Rte_Read_Com_DriveSeatMsg_ModeCmd(P2VAR(uint8,AUTOMATIC,RTE_APPL_DATA) data)
{
    Std_ReturnType ret = E_OK;
    ret = Com_ReceiveSignal(ComConf_ComSignal_DriveSeatMsg_ModeCmd_Rx, data);
    return ret;
};


FUNC(Std_ReturnType,RTE_CODE)Rte_Read_Com_PowerMode(P2VAR(uint8,AUTOMATIC,RTE_APPL_DATA) data)
{
    Std_ReturnType ret = E_OK;
    ret = Com_ReceiveSignal(ComConf_ComSignal_PowerMode_Rx, data);
    return ret;
};


FUNC(Std_ReturnType,RTE_CODE)Rte_Read_Com_APC_Level_Limit(P2VAR(uint8,AUTOMATIC,RTE_APPL_DATA) data)
{
    Std_ReturnType ret = E_OK;
    ret = Com_ReceiveSignal(ComConf_ComSignal_APC_Level_Limit_Rx, data);
    return ret;
};


FUNC(Std_ReturnType,RTE_CODE)Rte_Read_Com_DrvSeatRisSideBolsterInflationReq(P2VAR(uint8,AUTOMATIC,RTE_APPL_DATA) data)
{
    Std_ReturnType ret = E_OK;
    ret = Com_ReceiveSignal(ComConf_ComSignal_DrvSeatRisSideBolsterInflationReq_Rx, data);
    return ret;
};


FUNC(Std_ReturnType,RTE_CODE)Rte_Read_Com_DrvSeatLeSideBolsterInflationReq(P2VAR(uint8,AUTOMATIC,RTE_APPL_DATA) data)
{
    Std_ReturnType ret = E_OK;
    ret = Com_ReceiveSignal(ComConf_ComSignal_DrvSeatLeSideBolsterInflationReq_Rx, data);
    return ret;
};
