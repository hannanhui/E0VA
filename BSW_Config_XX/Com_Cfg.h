/*******************************************************************************
**                                                                            **
** Copyright (C) iSOFT   (2022)                                               **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to iSOFT.         **
** Passing on and copying of this document, and communication                 **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : Com_Cfg.h                                                   **
**                                                                            **
**  Created on  : 2025/05/29 15:06:01                                         **
**  Author      : zhengfei.li                                                 **
**  Vendor      :                                                             **
**  DESCRIPTION : Configuration parameter of Com                              **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#ifndef  COM_CFG_H
#define  COM_CFG_H

#include "ComStack_Types.h"
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
#define COM_CFG_H_AR_MAJOR_VERSION    4u
#define COM_CFG_H_AR_MINOR_VERSION    2u
#define COM_CFG_H_AR_PATCH_VERSION    2u
#define COM_CFG_H_SW_MAJOR_VERSION    2u
#define COM_CFG_H_SW_MINOR_VERSION    0u
#define COM_CFG_H_SW_PATCH_VERSION    0u

/*******************************************************************************
**                      Macros                                                **
*******************************************************************************/

#define COM_CANCELLATION_SUPPORT                     STD_OFF
#define COM_DEV_ERROR_DETECT                         STD_ON
#define COM_ENABLE_SIGNAL_GROUP_ARRAY_API            STD_OFF
#define COM_VERSION_INFO_API                         STD_OFF
#define COM_ENABLE_MDT_FOR_CYCLIC_TRANSMISSION       STD_ON
#define COM_METADATA_SUPPORT                         STD_OFF
#define COM_RETRY_FAILED_TRANSMIT_REQUESTS           STD_OFF

#define COM_IPDUGROUP_NUMBER                         2u
#define Com_RxPduGroup_CanController_CAN0        0u
#define Com_TxPduGroup_CanController_CAN0        1u

#define COM_RXIPDU_NUMBER        11u
#define COM_RXPDU_COM_TABBodyNMEira        0u
#define COM_RXPDU_COM_MC_BodyCAN_0x1AA        1u
#define COM_RXPDU_COM_MC_BodyCAN_0x143        2u
#define COM_RXPDU_COM_MC_BodyCAN_0x192        3u
#define COM_RXPDU_COM_MC_BodyCAN_0x107        4u
#define COM_RXPDU_COM_MC_BodyCAN_0x100        5u
#define COM_RXPDU_COM_MC_BodyCAN_0x103        6u
#define COM_RXPDU_COM_MC_TABFuncCtrl_BodyCAN_0x200        7u
#define COM_RXPDU_COM_MC_BodyCAN_0x1D4        8u
#define COM_RXPDU_COM_MC_BodyCAN_0x106        9u
#define COM_RXPDU_COM_MC_BodyCAN_0x10B        10u

#define COM_TXIPDU_NUMBER    8u
#define COM_TXPDU_COM_TAB_BodyCAN_0x2A7_Info        11u
#define COM_TXPDU_COM_TAB_BodyCAN_0x2A4_SnsrPrm        12u
#define COM_TXPDU_COM_TAB_BodyCAN_0x2A3_SnsrPrm        13u
#define COM_TXPDU_COM_TAB_BodyCAN_0x2A6_PrmFr        14u
#define COM_TXPDU_COM_TAB_BodyCAN_0x2A0_FuncSts        15u
#define COM_TXPDU_COM_TAB_BodyCAN_0x2A1_FuncSts        16u
#define COM_TXPDU_COM_TAB_BodyCAN_0x2A2_SnsrPrm        17u
#define COM_TXPDU_COM_TAB_BodyCAN_0x2A5_FltSts        18u
#define COM_RXIPDUBUFF_SIZE        88u
#define COM_TXIPDUBUFF_SIZE        64u

#define COM_SIGNAL_BOOLBUFF_SIZE            6u
#define COM_RXGROUPSIGNAL_BOOLBUFF_SIZE     2u
#define COM_SIGNAL_BOOL_INVALID_SIZE        0u

#define COM_SIGNAL_8BITBUFF_SIZE            51u
#define COM_RXGROUPSIGNAL_8BITBUFF_SIZE     14u
#define COM_SIGNAL_8BIT_INVALID_SIZE        0u

#define COM_SIGNAL_16BITBUFF_SIZE           24u
#define COM_RXGROUPSIGNAL_16BITBUFF_SIZE    4u
#define COM_SIGNAL_16BIT_INVALID_SIZE       0u

#define COM_SIGNAL_32BITBUFF_SIZE           1u
#define COM_RXGROUPSIGNAL_32BITBUFF_SIZE    0u
#define COM_SIGNAL_32BIT_INVALID_SIZE       0u

#define COM_SIGNAL_64BITBUFF_SIZE           0u
#define COM_RXGROUPSIGNAL_64BITBUFF_SIZE    0u
#define COM_SIGNAL_64BIT_INVALID_SIZE       0u

#define COM_TMCTXSIGNAL_NUMBER              0u
#define COM_TMCTXGROUPSIGNAL_NUMBER         0u

#define COM_TXSIGNALGROUP_NUMBER            0u

#define COM_RXSIGNALGROUP_NUMBER            5u
#define LatAccrYawRateSigGrp_IPDU_COM_MC_BodyCAN_0x1AA               0u
#define BattSocRawSigGrp_IPDU_COM_MC_BodyCAN_0x143               1u
#define BattURawSigGrp_IPDU_COM_MC_BodyCAN_0x143               2u
#define PwrModSigGrp_IPDU_COM_MC_BodyCAN_0x103               3u
#define VCUActGearSigGrp_IPDU_COM_MC_BodyCAN_0x103               4u

#define COM_TXSIGNAL_NUMBER                  36u
#define DrvrSeat_HWVerNum_IPDU_COM_TAB_BodyCAN_0x2A7_Info               0u
#define DrvrSeat_SWVerNum_IPDU_COM_TAB_BodyCAN_0x2A7_Info               1u
#define DrvrSeat_BTVerNum_IPDU_COM_TAB_BodyCAN_0x2A7_Info               2u
#define DrvrSeat_X11PSnsrPrm_IPDU_COM_TAB_BodyCAN_0x2A4_SnsrPrm               3u
#define DrvrSeat_X10PSnsrPrm_IPDU_COM_TAB_BodyCAN_0x2A4_SnsrPrm               4u
#define DrvrSeat_X9PSnsrPrm_IPDU_COM_TAB_BodyCAN_0x2A3_SnsrPrm               5u
#define DrvrSeat_X8PSnsrPrm_IPDU_COM_TAB_BodyCAN_0x2A3_SnsrPrm               6u
#define DrvrSeat_X7PSnsrPrm_IPDU_COM_TAB_BodyCAN_0x2A3_SnsrPrm               7u
#define DrvrSeat_X6PSnsrPrm_IPDU_COM_TAB_BodyCAN_0x2A3_SnsrPrm               8u
#define DrvrSeat_X5PSnsrPrm_IPDU_COM_TAB_BodyCAN_0x2A3_SnsrPrm               9u
#define DrvrSeat_InpUPrm_IPDU_COM_TAB_BodyCAN_0x2A6_PrmFr               10u
#define DrvrSeat_NtcTPrm_IPDU_COM_TAB_BodyCAN_0x2A6_PrmFr               11u
#define DrvrSeat_HSDUPrm_IPDU_COM_TAB_BodyCAN_0x2A6_PrmFr               12u
#define DrvrSeat_HSDCurPrm_IPDU_COM_TAB_BodyCAN_0x2A6_PrmFr               13u
#define DrvrSeat_ResvFuncSts_IPDU_COM_TAB_BodyCAN_0x2A0_FuncSts               14u
#define DrvrSeat_MassgAreaSts_IPDU_COM_TAB_BodyCAN_0x2A0_FuncSts               15u
#define DrvrSeat_CushSptHrdnsSts_IPDU_COM_TAB_BodyCAN_0x2A0_FuncSts               16u
#define DrvrSeat_SideBlstrlRiAdjSts_IPDU_COM_TAB_BodyCAN_0x2A0_FuncSts               17u
#define DrvrSeat_SideBlstrlLeAdjSts_IPDU_COM_TAB_BodyCAN_0x2A0_FuncSts               18u
#define DrvrSeat_MassgSts_IPDU_COM_TAB_BodyCAN_0x2A0_FuncSts               19u
#define DrvrSeat_MassgModSts_IPDU_COM_TAB_BodyCAN_0x2A0_FuncSts               20u
#define DrvrSeat_MassgIntenSts_IPDU_COM_TAB_BodyCAN_0x2A0_FuncSts               21u
#define DrvrSeat_LumAdjSts_IPDU_COM_TAB_BodyCAN_0x2A0_FuncSts               22u
#define DrvrSeat_ActvBlstrAdjSts_IPDU_COM_TAB_BodyCAN_0x2A0_FuncSts               23u
#define DrvrSeat_TempSts_IPDU_COM_TAB_BodyCAN_0x2A1_FuncSts               24u
#define DrvrSeat_MainVlvSts_IPDU_COM_TAB_BodyCAN_0x2A1_FuncSts               25u
#define DrvrSeat_InpUSts_IPDU_COM_TAB_BodyCAN_0x2A1_FuncSts               26u
#define DrvrSeat_X4PSnsrPrm_IPDU_COM_TAB_BodyCAN_0x2A2_SnsrPrm               27u
#define DrvrSeat_X3PSnsrPrm_IPDU_COM_TAB_BodyCAN_0x2A2_SnsrPrm               28u
#define DrvrSeat_RiSideBlstrPSnsrPrm_IPDU_COM_TAB_BodyCAN_0x2A2_SnsrPrm               29u
#define DrvrSeat_MainPSnsrPrm_IPDU_COM_TAB_BodyCAN_0x2A2_SnsrPrm               30u
#define DrvrSeat_LeSideBlstrPSnsrPrm_IPDU_COM_TAB_BodyCAN_0x2A2_SnsrPrm               31u
#define DrvrSeat_MassgVlvFltSts_IPDU_COM_TAB_BodyCAN_0x2A5_FltSts               32u
#define DrvrSeat_MainVlvFltSts_IPDU_COM_TAB_BodyCAN_0x2A5_FltSts               33u
#define DrvrSeat_LumSideBlstrVlvFltSts_IPDU_COM_TAB_BodyCAN_0x2A5_FltSts               34u
#define DrvrSeat_HSDFltSts_IPDU_COM_TAB_BodyCAN_0x2A5_FltSts               35u

#define COM_RXSIGNAL_NUMBER               26u
#define TotOdoAcrt_IPDU_COM_MC_BodyCAN_0x192             0u
#define DateTiDay_IPDU_COM_MC_BodyCAN_0x107             1u
#define DateTiHr_IPDU_COM_MC_BodyCAN_0x107             2u
#define DateTiMilsec_IPDU_COM_MC_BodyCAN_0x107             3u
#define DateTiMins_IPDU_COM_MC_BodyCAN_0x107             4u
#define DateTiMth_IPDU_COM_MC_BodyCAN_0x107             5u
#define DateTiSec_IPDU_COM_MC_BodyCAN_0x107             6u
#define DateTiYr_IPDU_COM_MC_BodyCAN_0x107             7u
#define CarModSts_IPDU_COM_MC_BodyCAN_0x100             8u
#define VCUPtRdyFlg_IPDU_COM_MC_BodyCAN_0x100             9u
#define DrvrSeat_ResvFuncCmd_IPDU_COM_MC_TABFuncCtrl_BodyCAN_0x200             10u
#define DrvrSeat_MassgAreaStsCmd_IPDU_COM_MC_TABFuncCtrl_BodyCAN_0x200             11u
#define DrvrSeat_CushSptHrdnsStsCmd_IPDU_COM_MC_TABFuncCtrl_BodyCAN_0x200             12u
#define DrvrSeat_LumAdjCmd_IPDU_COM_MC_TABFuncCtrl_BodyCAN_0x200             13u
#define DrvrSeat_SideBlstrlLeAdjCmd_IPDU_COM_MC_TABFuncCtrl_BodyCAN_0x200             14u
#define DrvrSeat_SideBlstrlRiAdjCmd_IPDU_COM_MC_TABFuncCtrl_BodyCAN_0x200             15u
#define DrvrSeat_MassgStsCmd_IPDU_COM_MC_TABFuncCtrl_BodyCAN_0x200             16u
#define DrvrSeat_MassgModStsCmd_IPDU_COM_MC_TABFuncCtrl_BodyCAN_0x200             17u
#define DrvrSeat_MassgIntenStsCmd_IPDU_COM_MC_TABFuncCtrl_BodyCAN_0x200             18u
#define DrvrSeat_ActvBlstrAdjStsCmd_IPDU_COM_MC_TABFuncCtrl_BodyCAN_0x200             19u
#define CurAtmPSoa_IPDU_COM_MC_BodyCAN_0x1D4             20u
#define CurAtmPValSoa_IPDU_COM_MC_BodyCAN_0x1D4             21u
#define VehSpd_IPDU_COM_MC_BodyCAN_0x106             22u
#define VehSpdVld_IPDU_COM_MC_BodyCAN_0x106             23u
#define PinionSteerAgl_IPDU_COM_MC_BodyCAN_0x10B             24u
#define PinionSteerAglVld_IPDU_COM_MC_BodyCAN_0x10B             25u

#define COM_GWSOURCESIGNAL_UPDATE_NUMBER           0u
#define COM_ONEEVERYNFILTERSIGNAL_NUMBER           0u
#define COM_RXSIGNALMASKNEWDIFFERMASKOLD_NUMBER    0u

#define COM_GWSIGNAL_BOOLBUFF_SIZE          0u
#define COM_GWSIGNAL_8BITBUFF_SIZE          0u
#define COM_GWSIGNAL_16BITBUFF_SIZE         0u
#define COM_GWSIGNAL_32BITBUFF_SIZE         0u
#define COM_GWSIGNAL_64BITBUFF_SIZE         0u

#define COM_TXGROUPSIGNAL_NUMBER        0u

#define COM_RXGROUPSIGNAL_NUMBER        20u
#define LatAccrYawRateSigGrp_IPDU_COM_MC_BodyCAN_0x1AA_LatAccr_IPDU_COM_MC_BodyCAN_0x1AA             26u
#define LatAccrYawRateSigGrp_IPDU_COM_MC_BodyCAN_0x1AA_LatAccrSt_IPDU_COM_MC_BodyCAN_0x1AA             27u
#define LatAccrYawRateSigGrp_IPDU_COM_MC_BodyCAN_0x1AA_LatAccrYawRateSigGrpChks_IPDU_COM_MC_BodyCAN_0x1AA             28u
#define LatAccrYawRateSigGrp_IPDU_COM_MC_BodyCAN_0x1AA_LatAccrYawRateSigGrpCntr_IPDU_COM_MC_BodyCAN_0x1AA             29u
#define LatAccrYawRateSigGrp_IPDU_COM_MC_BodyCAN_0x1AA_YawRate_IPDU_COM_MC_BodyCAN_0x1AA             30u
#define LatAccrYawRateSigGrp_IPDU_COM_MC_BodyCAN_0x1AA_YawRateSnsrSt_IPDU_COM_MC_BodyCAN_0x1AA             31u
#define BattSocRawSigGrp_IPDU_COM_MC_BodyCAN_0x143_BattSocRaw_IPDU_COM_MC_BodyCAN_0x143             32u
#define BattSocRawSigGrp_IPDU_COM_MC_BodyCAN_0x143_BattSocRawSigGrpChks_IPDU_COM_MC_BodyCAN_0x143             33u
#define BattSocRawSigGrp_IPDU_COM_MC_BodyCAN_0x143_BattSocRawSigGrpCntr_IPDU_COM_MC_BodyCAN_0x143             34u
#define BattURawSigGrp_IPDU_COM_MC_BodyCAN_0x143_BattURaw_IPDU_COM_MC_BodyCAN_0x143             35u
#define BattURawSigGrp_IPDU_COM_MC_BodyCAN_0x143_BattURawSigGrpChks_IPDU_COM_MC_BodyCAN_0x143             36u
#define BattURawSigGrp_IPDU_COM_MC_BodyCAN_0x143_BattURawSigGrpCntr_IPDU_COM_MC_BodyCAN_0x143             37u
#define PwrModSigGrp_IPDU_COM_MC_BodyCAN_0x103_PwrModSigGrpChks_IPDU_COM_MC_BodyCAN_0x103             38u
#define PwrModSigGrp_IPDU_COM_MC_BodyCAN_0x103_PwrModSigGrpCntr_IPDU_COM_MC_BodyCAN_0x103             39u
#define PwrModSigGrp_IPDU_COM_MC_BodyCAN_0x103_PwrModSts_IPDU_COM_MC_BodyCAN_0x103             40u
#define PwrModSigGrp_IPDU_COM_MC_BodyCAN_0x103_PwrModVld_IPDU_COM_MC_BodyCAN_0x103             41u
#define VCUActGearSigGrp_IPDU_COM_MC_BodyCAN_0x103_VCUActGearLvr_IPDU_COM_MC_BodyCAN_0x103             42u
#define VCUActGearSigGrp_IPDU_COM_MC_BodyCAN_0x103_VCUActGearLvrVld_IPDU_COM_MC_BodyCAN_0x103             43u
#define VCUActGearSigGrp_IPDU_COM_MC_BodyCAN_0x103_VCUActGearSigGrpChks_IPDU_COM_MC_BodyCAN_0x103             44u
#define VCUActGearSigGrp_IPDU_COM_MC_BodyCAN_0x103_VCUActGearSigGrpCntr_IPDU_COM_MC_BodyCAN_0x103             45u

#define COM_GWMAPPING_NUMBER         0u
#define COM_SOURCE_SIGNAL_NUMBER     0u
#define COM_DST_SIGNAL_NUMBER        0u

#define COM_TXTPPDU_SUPPORT          STD_OFF
#define COM_RXTPPDU_SUPPORT          STD_OFF

#endif

