/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Rte.c
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
*   ---------   ----------    ------------  ----------   ---------------
* devin 20230621 change to cs1e 
********************************************************************************
* END_FILE_HDR*/

/*******************************************************************************
*   Includes.
*******************************************************************************/
#include "Rte_Main.h"
#include "Rte_Type.h"
//#include "Rte_Hook.h"

//#define RTE_CORE
#include "Rte_Com.h"
//#include "Rte_ComM.h"
//#include "Rte_Dcm.h"
//#include "Rte_Dem.h"
//#include "SchM.h"
//#include "Rte_ComM_Type.h"
//#include "Rte_Dcm_Type.h"
//#include "Lib.h"
//#include "FreeRTimer.h"

#define STATIC       static

/*******************************************************************************
*   state
*******************************************************************************/
static boolean CommStWithVCCD = FALSE;
static boolean CommStWithACU = FALSE;


/*******************************************************************************
*   Rte Api
*******************************************************************************/
//FUNC(Std_ReturnType,RTE_CODE)Rte_Read_Com_LatAccr(P2VAR(uint16,AUTOMATIC,RTE_APPL_DATA) data)
//{
//    Std_ReturnType ret = RTE_E_OK;
//    ret = Com_ReceiveSignalGroup(LatAccrYawRateSigGrp_IPDU_COM_MC_BodyCAN_0x1AA);
//    if (ret == RTE_E_OK)
//    {
//        ret = Com_ReceiveSignal(LatAccrYawRateSigGrp_IPDU_COM_MC_BodyCAN_0x1AA_LatAccr_IPDU_COM_MC_BodyCAN_0x1AA, data);
//    }
//    return ret;
//};
//FUNC(Std_ReturnType,RTE_CODE)Rte_Read_Com_LatAccrSt(P2VAR(uint8,AUTOMATIC,RTE_APPL_DATA) data)
//{
//    Std_ReturnType ret = RTE_E_OK;
////    ret = Com_ReceiveSignalGroup(LatAccrYawRateSigGrp_IPDU_COM_MC_BodyCAN_0x1AA);
////    if (ret == RTE_E_OK)
////    {
////        ret = Com_ReceiveSignal(LatAccrYawRateSigGrp_IPDU_COM_MC_BodyCAN_0x1AA_LatAccrSt_IPDU_COM_MC_BodyCAN_0x1AA, data);
////    }
//    return ret;
//};
//FUNC(Std_ReturnType,RTE_CODE)Rte_Read_Com_LatAccrYawRateSigGrpChks(P2VAR(uint8,AUTOMATIC,RTE_APPL_DATA) data)
//{
//    Std_ReturnType ret = RTE_E_OK;
//    ret = Com_ReceiveSignalGroup(LatAccrYawRateSigGrp_IPDU_COM_MC_BodyCAN_0x1AA);
//    if (ret == RTE_E_OK)
//    {
//        ret = Com_ReceiveSignal(LatAccrYawRateSigGrp_IPDU_COM_MC_BodyCAN_0x1AA_LatAccrYawRateSigGrpChks_IPDU_COM_MC_BodyCAN_0x1AA, data);
//    }
//    return ret;
//};
//FUNC(Std_ReturnType,RTE_CODE)Rte_Read_Com_LatAccrYawRateSigGrpCntr(P2VAR(uint8,AUTOMATIC,RTE_APPL_DATA) data)
//{
//    Std_ReturnType ret = RTE_E_OK;
//    ret = Com_ReceiveSignalGroup(LatAccrYawRateSigGrp_IPDU_COM_MC_BodyCAN_0x1AA);
//    if (ret == RTE_E_OK)
//    {
//        ret = Com_ReceiveSignal(LatAccrYawRateSigGrp_IPDU_COM_MC_BodyCAN_0x1AA_LatAccrYawRateSigGrpCntr_IPDU_COM_MC_BodyCAN_0x1AA, data);
//    }
//    return ret;
//};
//FUNC(Std_ReturnType,RTE_CODE)Rte_Read_Com_YawRate(P2VAR(uint16,AUTOMATIC,RTE_APPL_DATA) data)
//{
//    Std_ReturnType ret = RTE_E_OK;
//    ret = Com_ReceiveSignalGroup(LatAccrYawRateSigGrp_IPDU_COM_MC_BodyCAN_0x1AA);
//    if (ret == RTE_E_OK)
//    {
//        ret = Com_ReceiveSignal(LatAccrYawRateSigGrp_IPDU_COM_MC_BodyCAN_0x1AA_YawRate_IPDU_COM_MC_BodyCAN_0x1AA, data);
//    }
//    return ret;
//};
//FUNC(Std_ReturnType,RTE_CODE)Rte_Read_Com_YawRateSnsrSt(P2VAR(uint8,AUTOMATIC,RTE_APPL_DATA) data)
//{
//    Std_ReturnType ret = RTE_E_OK;
//    ret = Com_ReceiveSignalGroup(LatAccrYawRateSigGrp_IPDU_COM_MC_BodyCAN_0x1AA);
//    if (ret == RTE_E_OK)
//    {
//        ret = Com_ReceiveSignal(LatAccrYawRateSigGrp_IPDU_COM_MC_BodyCAN_0x1AA_YawRateSnsrSt_IPDU_COM_MC_BodyCAN_0x1AA, data);
//    }
//    return ret;
//};
//FUNC(Std_ReturnType,RTE_CODE)Rte_Read_Com_BattSocRaw(P2VAR(uint16,AUTOMATIC,RTE_APPL_DATA) data)
//{
//    Std_ReturnType ret = RTE_E_OK;
//    ret = Com_ReceiveSignal(BattSocRawSigGrp_IPDU_COM_MC_BodyCAN_0x143, data);
//    return ret;
//};
//FUNC(Std_ReturnType,RTE_CODE)Rte_Read_Com_BattURaw(P2VAR(uint16,AUTOMATIC,RTE_APPL_DATA) data)
//{
//    Std_ReturnType ret = RTE_E_OK;
//    ret = Com_ReceiveSignal(BattSocRawSigGrp_IPDU_COM_MC_BodyCAN_0x143, data);
//    return ret;
//};
//FUNC(Std_ReturnType,RTE_CODE)Rte_Read_Com_TotOdoAcrt(P2VAR(uint32,AUTOMATIC,RTE_APPL_DATA) data)
//{
//    Std_ReturnType ret = RTE_E_OK;
//    ret = Com_ReceiveSignal(TotOdoAcrt_IPDU_COM_MC_BodyCAN_0x192, data);
//    return ret;
//};
//FUNC(Std_ReturnType,RTE_CODE)Rte_Read_Com_DateTiDay(P2VAR(uint8,AUTOMATIC,RTE_APPL_DATA) data)
//{
//    Std_ReturnType ret = RTE_E_OK;
//    ret = Com_ReceiveSignal(DateTiDay_IPDU_COM_MC_BodyCAN_0x107, data);
//    return ret;
//};
//FUNC(Std_ReturnType,RTE_CODE)Rte_Read_Com_DateTiHr(P2VAR(uint8,AUTOMATIC,RTE_APPL_DATA) data)
//{
//    Std_ReturnType ret = RTE_E_OK;
//    ret = Com_ReceiveSignal(DateTiHr_IPDU_COM_MC_BodyCAN_0x107, data);
//    return ret;
//};
//FUNC(Std_ReturnType,RTE_CODE)Rte_Read_Com_DateTiMilsec(P2VAR(uint16,AUTOMATIC,RTE_APPL_DATA) data)
//{
//    Std_ReturnType ret = RTE_E_OK;
//    ret = Com_ReceiveSignal(DateTiMilsec_IPDU_COM_MC_BodyCAN_0x107, data);
//    return ret;
//};
//FUNC(Std_ReturnType,RTE_CODE)Rte_Read_Com_DateTiMins(P2VAR(uint8,AUTOMATIC,RTE_APPL_DATA) data)
//{
//    Std_ReturnType ret = RTE_E_OK;
//    ret = Com_ReceiveSignal(DateTiMins_IPDU_COM_MC_BodyCAN_0x107, data);
//    return ret;
//};
//FUNC(Std_ReturnType,RTE_CODE)Rte_Read_Com_DateTiMth(P2VAR(uint8,AUTOMATIC,RTE_APPL_DATA) data)
//{
//    Std_ReturnType ret = RTE_E_OK;
//    ret = Com_ReceiveSignal(DateTiMth_IPDU_COM_MC_BodyCAN_0x107, data);
//    return ret;
//};
//FUNC(Std_ReturnType,RTE_CODE)Rte_Read_Com_DateTiSec(P2VAR(uint8,AUTOMATIC,RTE_APPL_DATA) data)
//{
//    Std_ReturnType ret = RTE_E_OK;
//    ret = Com_ReceiveSignal(DateTiSec_IPDU_COM_MC_BodyCAN_0x107, data);
//    return ret;
//};
//FUNC(Std_ReturnType,RTE_CODE)Rte_Read_Com_DateTiYr(P2VAR(uint8,AUTOMATIC,RTE_APPL_DATA) data)
//{
//    Std_ReturnType ret = RTE_E_OK;
//    ret = Com_ReceiveSignal(DateTiYr_IPDU_COM_MC_BodyCAN_0x107, data);
//    return ret;
//};
//FUNC(Std_ReturnType,RTE_CODE)Rte_Read_Com_CarModSts(P2VAR(uint8,AUTOMATIC,RTE_APPL_DATA) data)
//{
//    Std_ReturnType ret = RTE_E_OK;
//    ret = Com_ReceiveSignal(CarModSts_IPDU_COM_MC_BodyCAN_0x100, data);
//    return ret;
//};
//FUNC(Std_ReturnType,RTE_CODE)Rte_Read_Com_VCUPtRdyFlg(P2VAR(boolean,AUTOMATIC,RTE_APPL_DATA) data)
//{
//    Std_ReturnType ret = RTE_E_OK;
//    ret = Com_ReceiveSignal(VCUPtRdyFlg_IPDU_COM_MC_BodyCAN_0x100, data);
//    return ret;
//};
//FUNC(Std_ReturnType,RTE_CODE)Rte_Read_Com_PwrModSigGrpChks(P2VAR(uint8,AUTOMATIC,RTE_APPL_DATA) data)
//{
//    Std_ReturnType ret = RTE_E_OK;
//    ret = Com_ReceiveSignalGroup(PwrModSigGrp_IPDU_COM_MC_BodyCAN_0x103);
//    if (ret == RTE_E_OK)
//    {
//        ret = Com_ReceiveSignal(PwrModSigGrp_IPDU_COM_MC_BodyCAN_0x103_PwrModSigGrpChks_IPDU_COM_MC_BodyCAN_0x103, data);
//    }
//    return ret;
//};
//FUNC(Std_ReturnType,RTE_CODE)Rte_Read_Com_PwrModSigGrpCntr(P2VAR(uint8,AUTOMATIC,RTE_APPL_DATA) data)
//{
//    Std_ReturnType ret = RTE_E_OK;
//    ret = Com_ReceiveSignalGroup(PwrModSigGrp_IPDU_COM_MC_BodyCAN_0x103);
//    if (ret == RTE_E_OK)
//    {
//        ret = Com_ReceiveSignal(PwrModSigGrp_IPDU_COM_MC_BodyCAN_0x103_PwrModSigGrpCntr_IPDU_COM_MC_BodyCAN_0x103, data);
//    }
//    return ret;
//};
//FUNC(Std_ReturnType,RTE_CODE)Rte_Read_Com_PwrModSts(P2VAR(uint8,AUTOMATIC,RTE_APPL_DATA) data)
//{
//    Std_ReturnType ret = RTE_E_OK;
//    ret = Com_ReceiveSignalGroup(PwrModSigGrp_IPDU_COM_MC_BodyCAN_0x103);
//    if (ret == RTE_E_OK)
//    {
//        ret = Com_ReceiveSignal(PwrModSigGrp_IPDU_COM_MC_BodyCAN_0x103_PwrModSts_IPDU_COM_MC_BodyCAN_0x103, data);
//    }
//    return ret;
//};
//FUNC(Std_ReturnType,RTE_CODE)Rte_Read_Com_PwrModVld(P2VAR(boolean,AUTOMATIC,RTE_APPL_DATA) data)
//{
//    Std_ReturnType ret = RTE_E_OK;
//    ret = Com_ReceiveSignalGroup(PwrModSigGrp_IPDU_COM_MC_BodyCAN_0x103);
//    if (ret == RTE_E_OK)
//    {
//        ret = Com_ReceiveSignal(PwrModSigGrp_IPDU_COM_MC_BodyCAN_0x103_PwrModVld_IPDU_COM_MC_BodyCAN_0x103, data);
//    }
//    return ret;
//};
//FUNC(Std_ReturnType,RTE_CODE)Rte_Read_Com_VCUActGearLvr(P2VAR(uint8,AUTOMATIC,RTE_APPL_DATA) data)
//{
//    Std_ReturnType ret = RTE_E_OK;
//    ret = Com_ReceiveSignalGroup(VCUActGearSigGrp_IPDU_COM_MC_BodyCAN_0x103);
//    if (ret == RTE_E_OK)
//    {
//        ret = Com_ReceiveSignal(VCUActGearSigGrp_IPDU_COM_MC_BodyCAN_0x103_VCUActGearLvr_IPDU_COM_MC_BodyCAN_0x103, data);
//    }
//    return ret;
//};
//FUNC(Std_ReturnType,RTE_CODE)Rte_Read_Com_VCUActGearLvrVld(P2VAR(boolean,AUTOMATIC,RTE_APPL_DATA) data)
//{
//    Std_ReturnType ret = RTE_E_OK;
//    ret = Com_ReceiveSignalGroup(VCUActGearSigGrp_IPDU_COM_MC_BodyCAN_0x103);
//    if (ret == RTE_E_OK)
//    {
//        ret = Com_ReceiveSignal(VCUActGearSigGrp_IPDU_COM_MC_BodyCAN_0x103_VCUActGearLvrVld_IPDU_COM_MC_BodyCAN_0x103, data);
//    }
//    return ret;
//};
//FUNC(Std_ReturnType,RTE_CODE)Rte_Read_Com_VCUActGearSigGrpChks(P2VAR(uint8,AUTOMATIC,RTE_APPL_DATA) data)
//{
//    Std_ReturnType ret = RTE_E_OK;
//    ret = Com_ReceiveSignalGroup(VCUActGearSigGrp_IPDU_COM_MC_BodyCAN_0x103);
//    if (ret == RTE_E_OK)
//    {
//        ret = Com_ReceiveSignal(VCUActGearSigGrp_IPDU_COM_MC_BodyCAN_0x103_VCUActGearSigGrpChks_IPDU_COM_MC_BodyCAN_0x103, data);
//    }
//    return ret;
//};
//FUNC(Std_ReturnType,RTE_CODE)Rte_Read_Com_VCUActGearSigGrpCntr(P2VAR(uint8,AUTOMATIC,RTE_APPL_DATA) data)
//{
//    Std_ReturnType ret = RTE_E_OK;
//    ret = Com_ReceiveSignalGroup(VCUActGearSigGrp_IPDU_COM_MC_BodyCAN_0x103);
//    if (ret == RTE_E_OK)
//    {
//        ret = Com_ReceiveSignal(VCUActGearSigGrp_IPDU_COM_MC_BodyCAN_0x103_VCUActGearSigGrpCntr_IPDU_COM_MC_BodyCAN_0x103, data);
//    }
//    return ret;
//};
//FUNC(Std_ReturnType,RTE_CODE)Rte_Read_Com_DrvrSeat_SideBlstrlLeAdjCmd(P2VAR(uint8,AUTOMATIC,RTE_APPL_DATA) data)
//{
//    Std_ReturnType ret = RTE_E_OK;
//    ret = Com_ReceiveSignal(DrvrSeat_SideBlstrlLeAdjCmd_IPDU_COM_MC_TABFuncCtrl_BodyCAN_0x200, data);
//    return ret;
//};
//FUNC(Std_ReturnType,RTE_CODE)Rte_Read_Com_DrvrSeat_SideBlstrlRiAdjCmd(P2VAR(uint8,AUTOMATIC,RTE_APPL_DATA) data)
//{
//    Std_ReturnType ret = RTE_E_OK;
//    ret = Com_ReceiveSignal(DrvrSeat_SideBlstrlRiAdjCmd_IPDU_COM_MC_TABFuncCtrl_BodyCAN_0x200, data);
//    return ret;
//};
//FUNC(Std_ReturnType,RTE_CODE)Rte_Read_Com_DrvrSeat_MassgIntenStsCmd(P2VAR(uint8,AUTOMATIC,RTE_APPL_DATA) data)
//{
//    Std_ReturnType ret = RTE_E_OK;
//    ret = Com_ReceiveSignal(DrvrSeat_MassgIntenStsCmd_IPDU_COM_MC_TABFuncCtrl_BodyCAN_0x200, data);
//    return ret;
//};
//FUNC(Std_ReturnType,RTE_CODE)Rte_Read_Com_DrvrSeat_MassgModStsCmd(P2VAR(uint8,AUTOMATIC,RTE_APPL_DATA) data)
//{
//    Std_ReturnType ret = RTE_E_OK;
//    ret = Com_ReceiveSignal(DrvrSeat_MassgModStsCmd_IPDU_COM_MC_TABFuncCtrl_BodyCAN_0x200, data);
//    return ret;
//};
//FUNC(Std_ReturnType,RTE_CODE)Rte_Read_Com_DrvrSeat_MassgStsCmd(P2VAR(boolean,AUTOMATIC,RTE_APPL_DATA) data)
//{
//    Std_ReturnType ret = RTE_E_OK;
//    ret = Com_ReceiveSignal(DrvrSeat_MassgStsCmd_IPDU_COM_MC_TABFuncCtrl_BodyCAN_0x200, data);
//    return ret;
//};
//FUNC(Std_ReturnType,RTE_CODE)Rte_Read_Com_DrvrSeat_ActvBlstrAdjStsCmd(P2VAR(uint8,AUTOMATIC,RTE_APPL_DATA) data)
//{
//    Std_ReturnType ret = RTE_E_OK;
//    ret = Com_ReceiveSignal(DrvrSeat_ActvBlstrAdjStsCmd_IPDU_COM_MC_TABFuncCtrl_BodyCAN_0x200, data);
//    return ret;
//};
//FUNC(Std_ReturnType,RTE_CODE)Rte_Read_Com_DrvrSeat_LumAdjCmd(P2VAR(uint8,AUTOMATIC,RTE_APPL_DATA) data)
//{
//    Std_ReturnType ret = RTE_E_OK;
//    ret = Com_ReceiveSignal(DrvrSeat_LumAdjCmd_IPDU_COM_MC_TABFuncCtrl_BodyCAN_0x200, data);
//    return ret;
//};
//FUNC(Std_ReturnType,RTE_CODE)Rte_Read_Com_CurAtmPSoa(P2VAR(uint8,AUTOMATIC,RTE_APPL_DATA) data)
//{
//    Std_ReturnType ret = RTE_E_OK;
//    ret = Com_ReceiveSignal(CurAtmPSoa_IPDU_COM_MC_BodyCAN_0x1D4, data);
//    return ret;
//};
//FUNC(Std_ReturnType,RTE_CODE)Rte_Read_Com_CurAtmPValSoa(P2VAR(boolean,AUTOMATIC,RTE_APPL_DATA) data)
//{
//    Std_ReturnType ret = RTE_E_OK;
//    ret = Com_ReceiveSignal(CurAtmPValSoa_IPDU_COM_MC_BodyCAN_0x1D4, data);
//    return ret;
//};
//FUNC(Std_ReturnType,RTE_CODE)Rte_Read_Com_VehSpd(P2VAR(uint16,AUTOMATIC,RTE_APPL_DATA) data)
//{
//    Std_ReturnType ret = RTE_E_OK;
//    ret = Com_ReceiveSignal(VehSpd_IPDU_COM_MC_BodyCAN_0x106, data);
//    return ret;
//};
//FUNC(Std_ReturnType,RTE_CODE)Rte_Read_Com_VehSpdVld(P2VAR(boolean,AUTOMATIC,RTE_APPL_DATA) data)
//{
//    Std_ReturnType ret = RTE_E_OK;
//    ret = Com_ReceiveSignal(VehSpdVld_IPDU_COM_MC_BodyCAN_0x106, data);
//    return ret;
//};
//FUNC(Std_ReturnType,RTE_CODE)Rte_Read_Com_PinionSteerAgl(P2VAR(sint16,AUTOMATIC,RTE_APPL_DATA) data)
//{
//    Std_ReturnType ret = RTE_E_OK;
//    ret = Com_ReceiveSignal(PinionSteerAgl_IPDU_COM_MC_BodyCAN_0x10B, data);
//    return ret;
//};
//FUNC(Std_ReturnType,RTE_CODE)Rte_Read_Com_PinionSteerAglVld(P2VAR(boolean,AUTOMATIC,RTE_APPL_DATA) data)
//{
//    Std_ReturnType ret = RTE_E_OK;
//    ret = Com_ReceiveSignal(PinionSteerAglVld_IPDU_COM_MC_BodyCAN_0x10B, data);
//    return ret;
//};
//FUNC(Std_ReturnType,RTE_CODE)Rte_Write_Com_DrvrSeat_SideBlstrlLeAdjSts(P2VAR(uint8,AUTOMATIC,RTE_APPL_DATA) data)
//{
//    Std_ReturnType ret = RTE_E_OK;
//    ret = Com_SendSignal(DrvrSeat_SideBlstrlLeAdjSts_IPDU_COM_TAB_BodyCAN_0x2A0_FuncSts, data);
//    return ret;
//};
//FUNC(Std_ReturnType,RTE_CODE)Rte_Write_Com_DrvrSeat_SideBlstrlRiAdjSts(P2VAR(uint8,AUTOMATIC,RTE_APPL_DATA) data)
//{
//    Std_ReturnType ret = RTE_E_OK;
//    ret = Com_SendSignal(DrvrSeat_SideBlstrlRiAdjSts_IPDU_COM_TAB_BodyCAN_0x2A0_FuncSts, data);
//    return ret;
//};
//FUNC(Std_ReturnType,RTE_CODE)Rte_Write_DrvrSeat_ActvBlstrAdjSts(P2VAR(uint8,AUTOMATIC,RTE_APPL_DATA) data)
//{
//    Std_ReturnType ret = RTE_E_OK;
//    ret = Com_SendSignal(DrvrSeat_ActvBlstrAdjSts_IPDU_COM_TAB_BodyCAN_0x2A0_FuncSts, data);
//    return ret;
//};
//FUNC(Std_ReturnType,RTE_CODE)Rte_Write_Com_DrvrSeat_HSDUPrm(P2VAR(uint8,AUTOMATIC,RTE_APPL_DATA) data)
//{
//    Std_ReturnType ret = RTE_E_OK;
//    ret = Com_SendSignal(DrvrSeat_HSDUPrm_IPDU_COM_TAB_BodyCAN_0x2A6_PrmFr, data);
//    return ret;
//};
//FUNC(Std_ReturnType,RTE_CODE)Rte_Write_Com_DrvrSeat_HSDCurPrm(P2VAR(uint8,AUTOMATIC,RTE_APPL_DATA) data)
//{
//    Std_ReturnType ret = RTE_E_OK;
//    ret = Com_SendSignal(DrvrSeat_HSDCurPrm_IPDU_COM_TAB_BodyCAN_0x2A6_PrmFr, data);
//    return ret;
//};
//FUNC(Std_ReturnType,RTE_CODE)Rte_Write_Com_DrvrSeat_LeSideBlstrPSnsrPrm(P2VAR(uint16,AUTOMATIC,RTE_APPL_DATA) data)
//{
//    Std_ReturnType ret = RTE_E_OK;
//    ret = Com_SendSignal(DrvrSeat_LeSideBlstrPSnsrPrm_IPDU_COM_TAB_BodyCAN_0x2A2_SnsrPrm, data);
//    return ret;
//};
//FUNC(Std_ReturnType,RTE_CODE)Rte_Write_Com_DrvrSeat_LumSideBlstrVlvFltSts(P2VAR(uint8,AUTOMATIC,RTE_APPL_DATA) data)
//{
//    Std_ReturnType ret = RTE_E_OK;
//    ret = Com_SendSignal(DrvrSeat_LumSideBlstrVlvFltSts_IPDU_COM_TAB_BodyCAN_0x2A5_FltSts, data);
//    return ret;
//};
//FUNC(Std_ReturnType,RTE_CODE)Rte_Write_Com_DrvrSeat_MainPSnsrPrm(P2VAR(uint16,AUTOMATIC,RTE_APPL_DATA) data)
//{
//    Std_ReturnType ret = RTE_E_OK;
//    ret = Com_SendSignal(DrvrSeat_MainPSnsrPrm_IPDU_COM_TAB_BodyCAN_0x2A2_SnsrPrm, data);
//    return ret;
//};
//FUNC(Std_ReturnType,RTE_CODE)Rte_Write_Com_DrvrSeat_InpUSts(P2VAR(uint8,AUTOMATIC,RTE_APPL_DATA) data)
//{
//    Std_ReturnType ret = RTE_E_OK;
//    ret = Com_SendSignal(DrvrSeat_InpUSts_IPDU_COM_TAB_BodyCAN_0x2A1_FuncSts, data);
//    return ret;
//};
//FUNC(Std_ReturnType,RTE_CODE)Rte_Write_Com_DrvrSeat_TemSts(P2VAR(uint8,AUTOMATIC,RTE_APPL_DATA) data)
//{
//    Std_ReturnType ret = RTE_E_OK;
//    ret = Com_SendSignal(DrvrSeat_TempSts_IPDU_COM_TAB_BodyCAN_0x2A1_FuncSts, data);
//    return ret;
//};
//FUNC(Std_ReturnType,RTE_CODE)Rte_Write_Com_DrvrSeat_MassgSts(P2VAR(boolean,AUTOMATIC,RTE_APPL_DATA) data)
//{
//    Std_ReturnType ret = RTE_E_OK;
//    ret = Com_SendSignal(DrvrSeat_MassgSts_IPDU_COM_TAB_BodyCAN_0x2A0_FuncSts, data);
//    return ret;
//};
//FUNC(Std_ReturnType,RTE_CODE)Rte_Write_Com_DrvrSeat_HSDFltSts(P2VAR(uint8,AUTOMATIC,RTE_APPL_DATA) data)
//{
//    Std_ReturnType ret = RTE_E_OK;
//    ret = Com_SendSignal(DrvrSeat_HSDFltSts_IPDU_COM_TAB_BodyCAN_0x2A5_FltSts, data);
//    return ret;
//};
//FUNC(Std_ReturnType,RTE_CODE)Rte_Write_Com_DrvrSeat_MainVlvSts(P2VAR(boolean,AUTOMATIC,RTE_APPL_DATA) data)
//{
//    Std_ReturnType ret = RTE_E_OK;
//    ret = Com_SendSignal(DrvrSeat_MainVlvSts_IPDU_COM_TAB_BodyCAN_0x2A1_FuncSts, data);
//    return ret;
//};
//FUNC(Std_ReturnType,RTE_CODE)Rte_Write_Com_DrvrSeat_RiSideBlstrPSnsrPrm(P2VAR(uint16,AUTOMATIC,RTE_APPL_DATA) data)
//{
//    Std_ReturnType ret = RTE_E_OK;
//    ret = Com_SendSignal(DrvrSeat_RiSideBlstrPSnsrPrm_IPDU_COM_TAB_BodyCAN_0x2A2_SnsrPrm, data);
//    return ret;
//};
//FUNC(Std_ReturnType,RTE_CODE)Rte_Write_Com_DrvrSeat_LumAdjSts(P2VAR(uint8,AUTOMATIC,RTE_APPL_DATA) data)
//{
//    Std_ReturnType ret = RTE_E_OK;
//    ret = Com_SendSignal(DrvrSeat_LumAdjSts_IPDU_COM_TAB_BodyCAN_0x2A0_FuncSts, data);
//    return ret;
//};
//FUNC(Std_ReturnType,RTE_CODE)Rte_Write_Com_DrvrSeat_MainVlvFltSts(P2VAR(uint8,AUTOMATIC,RTE_APPL_DATA) data)
//{
//    Std_ReturnType ret = RTE_E_OK;
//    ret = Com_SendSignal(DrvrSeat_MainVlvFltSts_IPDU_COM_TAB_BodyCAN_0x2A5_FltSts, data);
//    return ret;
//};
//FUNC(Std_ReturnType,RTE_CODE)Rte_Write_Com_DrvrSeat_NtcTPrm(P2VAR(uint8,AUTOMATIC,RTE_APPL_DATA) data)
//{
//    Std_ReturnType ret = RTE_E_OK;
//    ret = Com_SendSignal(DrvrSeat_NtcTPrm_IPDU_COM_TAB_BodyCAN_0x2A6_PrmFr, data);
//    return ret;
//};
//FUNC(Std_ReturnType,RTE_CODE)Rte_Write_Com_DrvrSeat_InpUPrm(P2VAR(uint8,AUTOMATIC,RTE_APPL_DATA) data)
//{
//    Std_ReturnType ret = RTE_E_OK;
//    ret = Com_SendSignal(DrvrSeat_InpUPrm_IPDU_COM_TAB_BodyCAN_0x2A6_PrmFr, data);
//    return ret;
//};
//FUNC(Std_ReturnType,RTE_CODE)Rte_Write_Com_DrvrSeat_MassgIntenSts(P2VAR(uint8,AUTOMATIC,RTE_APPL_DATA) data)
//{
//    Std_ReturnType ret = RTE_E_OK;
//    ret = Com_SendSignal(DrvrSeat_MassgIntenSts_IPDU_COM_TAB_BodyCAN_0x2A0_FuncSts, data);
//    return ret;
//};
//FUNC(Std_ReturnType,RTE_CODE)Rte_Write_Com_DrvrSeat_MassgModSts(P2VAR(uint8,AUTOMATIC,RTE_APPL_DATA) data)
//{
//    Std_ReturnType ret = RTE_E_OK;
//    ret = Com_SendSignal(DrvrSeat_MassgModSts_IPDU_COM_TAB_BodyCAN_0x2A0_FuncSts, data);
//    return ret;
//};
//FUNC(Std_ReturnType,RTE_CODE)Rte_Write_Com_DrvrSeat_MassgVlvFltSts(P2VAR(boolean,AUTOMATIC,RTE_APPL_DATA) data)
//{
//    Std_ReturnType ret = RTE_E_OK;
//    ret = Com_SendSignal(DrvrSeat_MassgVlvFltSts_IPDU_COM_TAB_BodyCAN_0x2A5_FltSts, data);
//    return ret;
//};
//FUNC(Std_ReturnType,RTE_CODE)Rte_Write_Com_DrvrSeat_ResvFcnSts(P2VAR(uint16,AUTOMATIC,RTE_APPL_DATA) data)
//{
//    Std_ReturnType ret = RTE_E_OK;
//    ret = Com_SendSignal(DrvrSeat_ResvFuncSts_IPDU_COM_TAB_BodyCAN_0x2A0_FuncSts, data);
//    return ret;
//};
//FUNC(Std_ReturnType,RTE_CODE)Rte_Write_Com_ComSignal_CanNmUserData0_Tx(P2VAR(uint8,AUTOMATIC,RTE_APPL_DATA) data)
//{
//    Std_ReturnType ret = RTE_E_OK;
////    ret = Com_SendSignal(ComSignal_CanNmUserData0_Tx, data);
//    return ret;
//};
//FUNC(Std_ReturnType,RTE_CODE)Rte_Write_Com_ComSignal_CanNmUserData0RMS_Tx(P2VAR(boolean,AUTOMATIC,RTE_APPL_DATA) data)
//{
//    Std_ReturnType ret = RTE_E_OK;
////    ret = Com_SendSignal(ComSignal_CanNmUserData0RMS_Tx, data);
//    return ret;
//};


/* 0: lost, 1: normal */
boolean GetCommStWithVCCD(void)
{
    return CommStWithVCCD;
}

void SetCommStWithVCCD(boolean st)
{
     CommStWithVCCD = st;
}

/* 0: lost, 1: normal */
boolean GetCommStWithACU(void)
{
    return CommStWithACU;
}

void SetCommStWithACU(boolean st)
{
    CommStWithACU = st;
}


/*******************************************************************************
*   Os Task
*******************************************************************************/


