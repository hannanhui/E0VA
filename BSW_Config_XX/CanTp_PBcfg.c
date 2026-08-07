/*============================================================================*/
/*  Copyright (C) iSOFT   (2022), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <CanTp_PBcfg.c>
 *  @brief      <>
 *  
 *  <MCU:Z20K144M>
 *  
 *  @author     <>
 *  @date       <2025-05-09 15:24:15>
 */
/*============================================================================*/

/*=======[I N C L U D E S]================================*/
#include "CanTp_PBcfg.h"
#include "CanTp_Types.h"
#include "CanIf_Cfg.h"
#include "PduR_Cfg.h"

/*=======[I N T E R N A L   D A T A]=======================*/

/*CanTpChannel RxSdu address information*/
#define CANTP_START_SEC_CONST_32
#include "CanTp_MemMap.h"
static CONST(uint32, CANTP_CONST) CanTp_Ch0RxSdu_CANTP_CANTP_MCToAllBodyCan_FuncDiagReqFr_Nar = 1000u;
static CONST(uint32, CANTP_CONST) CanTp_Ch0RxSdu_CANTP_CANTP_MCToAllBodyCan_FuncDiagReqFr_Ncr = 1000u;
#define CANTP_STOP_SEC_CONST_32
#include "CanTp_MemMap.h"
#define CANTP_START_SEC_CONST_8
#include "CanTp_MemMap.h"
static CONST(uint8, CANTP_CONST) CanTp_Ch0RxSdu_CANTP_CANTP_MCToAllBodyCan_FuncDiagReqFr_Bs = 8u;
static CONST(uint8, CANTP_CONST) CanTp_Ch0RxSdu_CANTP_CANTP_MCToAllBodyCan_FuncDiagReqFr_RxWftMax = 255u;
static CONST(uint8, CANTP_CONST) CanTp_Ch0RxSdu_CANTP_CANTP_MCToAllBodyCan_FuncDiagReqFr_STmin = 5u;

#define CANTP_STOP_SEC_CONST_8
#include "CanTp_MemMap.h"
#define CANTP_START_SEC_CONST_32
#include "CanTp_MemMap.h"
static CONST(uint32, CANTP_CONST) CanTp_Ch0RxSdu_CANTP_CANTP_MCToTAB_PhyDiagReqFr_Nar = 1000u;
static CONST(uint32, CANTP_CONST) CanTp_Ch0RxSdu_CANTP_CANTP_MCToTAB_PhyDiagReqFr_Ncr = 1000u;
#define CANTP_STOP_SEC_CONST_32
#include "CanTp_MemMap.h"
#define CANTP_START_SEC_CONST_8
#include "CanTp_MemMap.h"
static CONST(uint8, CANTP_CONST) CanTp_Ch0RxSdu_CANTP_CANTP_MCToTAB_PhyDiagReqFr_Bs = 8u;
static CONST(uint8, CANTP_CONST) CanTp_Ch0RxSdu_CANTP_CANTP_MCToTAB_PhyDiagReqFr_RxWftMax = 255u;
static CONST(uint8, CANTP_CONST) CanTp_Ch0RxSdu_CANTP_CANTP_MCToTAB_PhyDiagReqFr_STmin = 5u;

#define CANTP_STOP_SEC_CONST_8
#include "CanTp_MemMap.h"

#define CANTP_START_SEC_CONST_UNSPECIFIED
#include "CanTp_MemMap.h"
static CONST(CanTp_RxNSduType, CANTP_CONST) CanTp_Ch0RxNSdus[2] =
{
    {
        &CanTp_Ch0RxSdu_CANTP_CANTP_MCToAllBodyCan_FuncDiagReqFr_Bs,
        &CanTp_Ch0RxSdu_CANTP_CANTP_MCToAllBodyCan_FuncDiagReqFr_Nar,
        900u,
        &CanTp_Ch0RxSdu_CANTP_CANTP_MCToAllBodyCan_FuncDiagReqFr_Ncr,
        CANTP_STANDARD,
        PDUR_SRCPDU_CANTP_MCToAllBodyCan_FuncDiagReqFr,
        CANTP_CANTP_MCToAllBodyCan_FuncDiagReqFr,
        CANTP_CANIF_MCToAllBodyCan_FuncDiagReqFr,
        0xFFu,
        0xFFu,
        0u,
        8u,
        CANTP_PADDING_ON,
        CANTP_FUNCTIONAL_RX,
        &CanTp_Ch0RxSdu_CANTP_CANTP_MCToAllBodyCan_FuncDiagReqFr_RxWftMax,
        &CanTp_Ch0RxSdu_CANTP_CANTP_MCToAllBodyCan_FuncDiagReqFr_STmin,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        CAN20,
    },
    {
        &CanTp_Ch0RxSdu_CANTP_CANTP_MCToTAB_PhyDiagReqFr_Bs,
        &CanTp_Ch0RxSdu_CANTP_CANTP_MCToTAB_PhyDiagReqFr_Nar,
        900u,
        &CanTp_Ch0RxSdu_CANTP_CANTP_MCToTAB_PhyDiagReqFr_Ncr,
        CANTP_STANDARD,
        PDUR_SRCPDU_CANTP_MCToTAB_PhyDiagReqFr,
        CANTP_CANTP_MCToTAB_PhyDiagReqFr,
        CANTP_CANIF_MCToTAB_PhyDiagReqFr,
        CANTP_CANIF_TABToMC_DiagResFr,
        CANIF_TXPDU_CANIF_TABToMC_DiagResFr,
        0u,
        8u,
        CANTP_PADDING_ON,
        CANTP_PHYSICAL_RX,
        &CanTp_Ch0RxSdu_CANTP_CANTP_MCToTAB_PhyDiagReqFr_RxWftMax,
        &CanTp_Ch0RxSdu_CANTP_CANTP_MCToTAB_PhyDiagReqFr_STmin,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        CAN20,
    },
};
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
#include "CanTp_MemMap.h"

/*CanTpChannel TxSdu address information*/
#define CANTP_START_SEC_CONST_32
#include "CanTp_MemMap.h"
static CONST(uint32, CANTP_CONST) CanTp_Ch0TxSdu_CANTP_CANTP_TABToMC_DiagResFr_Nbs = 1000u;
static CONST(uint32, CANTP_CONST) CanTp_Ch0TxSdu_CANTP_CANTP_TABToMC_DiagResFr_Ncs = 900u;
#define CANTP_STOP_SEC_CONST_32
#include "CanTp_MemMap.h"

#define CANTP_START_SEC_CONST_UNSPECIFIED
#include "CanTp_MemMap.h"
static CONST(CanTp_TxNSduType, CANTP_CONST) CanTp_Ch0TxNSdus[1] =
{
    {
        1000u,
        &CanTp_Ch0TxSdu_CANTP_CANTP_TABToMC_DiagResFr_Nbs,
        &CanTp_Ch0TxSdu_CANTP_CANTP_TABToMC_DiagResFr_Ncs,
        CANTP_STANDARD,
        PDUR_DESTPDU_CANTP_TABToMC_DiagResFr,
        CANTP_CANTP_TABToMC_DiagResFr,
        CANTP_CANIF_TABToMC_DiagResFr,
        CANTP_CANIF_MCToTAB_PhyDiagReqFr,
        CANIF_TXPDU_CANIF_TABToMC_DiagResFr,
        0u,
        8u,
        CANTP_PADDING_ON,
        CANTP_PHYSICAL_TX,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        CAN20,
    },
};
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
#include "CanTp_MemMap.h"

#define CANTP_START_SEC_CONST_UNSPECIFIED
#include "CanTp_MemMap.h"
static CONST(CanTp_ChannelType, CANTP_CONST) CanTp_CfgChannel[CANTP_CHANNEL_NUMBER] =
{
    {
        CANTP_MODE_HALF_DUPLEX,
        FALSE,
        50u,
        5000u,
        0u,
        0x2u,
        &CanTp_Ch0RxNSdus[0],
        0x1u,
        &CanTp_Ch0TxNSdus[0]
    },
};
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
#include "CanTp_MemMap.h"

#define CANTP_START_SEC_CONST_UNSPECIFIED
#include "CanTp_MemMap.h"
CONST(CanTp_ConfigType, CANTP_CONST) CanTp_Config =
{
    CANTP_CHANNEL_NUMBER,
    &CanTp_CfgChannel[0]
};
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
#include "CanTp_MemMap.h"

/*=======[E X T E R N A L   D A T A]===========================*/
/*=======[E N D   O F   F I L E]==============================*/

