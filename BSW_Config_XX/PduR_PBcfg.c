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
**  FILENAME    : PduR_PBcfg.c                                                **
**                                                                            **
**  Created on  : 2025/05/29 15:06:03                                         **
**  Author      : zhengfei.li                                                 **
**  Vendor      :                                                             **
**  DESCRIPTION : Configuration parameter of PDUR                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "PduR.h"
#include "CanIf.h"
#include "CanTp.h"
#include "Com_Cbk.h"
#include "Dcm.h"
#include "Dcm_Cbk.h"
#include "CanNm.h"
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
#define PDUR_PBCFG_C_AR_MAJOR_VERSION  4u
#define PDUR_PBCFG_C_AR_MINOR_VERSION  2u
#define PDUR_PBCFG_C_AR_PATCH_VERSION  2u

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (PDUR_PBCFG_C_AR_MAJOR_VERSION != PDUR_PBCFG_H_AR_MAJOR_VERSION)
    #error "PduR.c : Mismatch in Specification Major Version"
#endif
#if (PDUR_PBCFG_C_AR_MINOR_VERSION != PDUR_PBCFG_H_AR_MINOR_VERSION)
    #error "PduR.c : Mismatch in Specification Major Version"
#endif
#if (PDUR_PBCFG_C_AR_PATCH_VERSION != PDUR_PBCFG_H_AR_PATCH_VERSION)
    #error "PduR.c : Mismatch in Specification Major Version"
#endif

/*******************************************************************************
**                      Macros                                                **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

#define PDUR_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"
CONST(PduRDestPduType,PDUR_CONST)
PduR_DestPduConfigData[PDUR_DEST_PDU_SUM] =
{
    {
        PDUR_DESTPDU_DCM_MCToAllBodyCan_FuncDiagReqFr,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CANTP_MCToAllBodyCan_FuncDiagReqFr,
        DCM_DCM_MCToAllBodyCan_FuncDiagReqFr,
        PDUR_DCM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_DCM_MCToTAB_PhyDiagReqFr,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CANTP_MCToTAB_PhyDiagReqFr,
        DCM_DCM_MCToTAB_PhyDiagReqFr,
        PDUR_DCM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_CANTP_TABToMC_DiagResFr,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_DCM_TABToMC_DiagResFr,
        CANTP_CANTP_TABToMC_DiagResFr,
        PDUR_CANTP,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_TABBodyNMEira,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_CanNM_TABBodyNMEira,
        COM_RXPDU_COM_TABBodyNMEira,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_MC_BodyCAN_0x1AA,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_MC_BodyCAN_0x1AA,
        COM_RXPDU_COM_MC_BodyCAN_0x1AA,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_MC_BodyCAN_0x143,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_MC_BodyCAN_0x143,
        COM_RXPDU_COM_MC_BodyCAN_0x143,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_MC_BodyCAN_0x192,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_MC_BodyCAN_0x192,
        COM_RXPDU_COM_MC_BodyCAN_0x192,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_MC_BodyCAN_0x107,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_MC_BodyCAN_0x107,
        COM_RXPDU_COM_MC_BodyCAN_0x107,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_MC_BodyCAN_0x100,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_MC_BodyCAN_0x100,
        COM_RXPDU_COM_MC_BodyCAN_0x100,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_MC_BodyCAN_0x103,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_MC_BodyCAN_0x103,
        COM_RXPDU_COM_MC_BodyCAN_0x103,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_MC_TABFuncCtrl_BodyCAN_0x200,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_MC_TABFuncCtrl_BodyCAN_0x200,
        COM_RXPDU_COM_MC_TABFuncCtrl_BodyCAN_0x200,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_MC_BodyCAN_0x1D4,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_MC_BodyCAN_0x1D4,
        COM_RXPDU_COM_MC_BodyCAN_0x1D4,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_MC_BodyCAN_0x106,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_MC_BodyCAN_0x106,
        COM_RXPDU_COM_MC_BodyCAN_0x106,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_COM_MC_BodyCAN_0x10B,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_MC_BodyCAN_0x10B,
        COM_RXPDU_COM_MC_BodyCAN_0x10B,
        PDUR_COM,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_TAB_BodyCAN_0x2A7_Info,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_COM_TAB_BodyCAN_0x2A7_Info,
        CANIF_TXPDU_TAB_BodyCAN_0x2A7_Info,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_TAB_BodyCAN_0x2A4_SnsrPrm,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_COM_TAB_BodyCAN_0x2A4_SnsrPrm,
        CANIF_TXPDU_TAB_BodyCAN_0x2A4_SnsrPrm,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_TAB_BodyCAN_0x2A3_SnsrPrm,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_COM_TAB_BodyCAN_0x2A3_SnsrPrm,
        CANIF_TXPDU_TAB_BodyCAN_0x2A3_SnsrPrm,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_TAB_BodyCAN_0x2A6_PrmFr,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_COM_TAB_BodyCAN_0x2A6_PrmFr,
        CANIF_TXPDU_TAB_BodyCAN_0x2A6_PrmFr,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_TAB_BodyCAN_0x2A0_FuncSts,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_COM_TAB_BodyCAN_0x2A0_FuncSts,
        CANIF_TXPDU_TAB_BodyCAN_0x2A0_FuncSts,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_TAB_BodyCAN_0x2A1_FuncSts,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_COM_TAB_BodyCAN_0x2A1_FuncSts,
        CANIF_TXPDU_TAB_BodyCAN_0x2A1_FuncSts,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_TAB_BodyCAN_0x2A2_SnsrPrm,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_COM_TAB_BodyCAN_0x2A2_SnsrPrm,
        CANIF_TXPDU_TAB_BodyCAN_0x2A2_SnsrPrm,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
    {
        PDUR_DESTPDU_TAB_BodyCAN_0x2A5_FltSts,
        PDUR_DIRECT,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        PDUR_UNUSED_UINT16,
        FALSE,
        TRUE,
        PDUR_SRCPDU_COM_TAB_BodyCAN_0x2A5_FltSts,
        CANIF_TXPDU_TAB_BodyCAN_0x2A5_FltSts,
        PDUR_CANIF,
        PDUR_UNUSED_UINT16,
        NULL_PTR,

    },
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"
CONST(PduRSrcPduType,PDUR_CONST)
PduR_SrcPduConfigData[PDUR_SRC_PDU_SUM] =
{
    {
        PDUR_SRCPDU_CANTP_MCToAllBodyCan_FuncDiagReqFr,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANTP_CANTP_MCToAllBodyCan_FuncDiagReqFr,
        PDUR_CANTP,

    },
    {
        PDUR_SRCPDU_CANTP_MCToTAB_PhyDiagReqFr,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANTP_CANTP_MCToTAB_PhyDiagReqFr,
        PDUR_CANTP,

    },
    {
        PDUR_SRCPDU_DCM_TABToMC_DiagResFr,
        TRUE,
        PDUR_UNUSED_UINT16,
        DCM_DCM_TABToMC_DiagResFr,
        PDUR_DCM,

    },
    {
        PDUR_SRCPDU_CanNM_TABBodyNMEira,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANNM_PNEIRARXNSDU,
        PDUR_CANNM,

    },
    {
        PDUR_SRCPDU_MC_BodyCAN_0x1AA,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_MC_BodyCAN_0x1AA,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_MC_BodyCAN_0x143,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_MC_BodyCAN_0x143,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_MC_BodyCAN_0x192,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_MC_BodyCAN_0x192,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_MC_BodyCAN_0x107,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_MC_BodyCAN_0x107,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_MC_BodyCAN_0x100,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_MC_BodyCAN_0x100,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_MC_BodyCAN_0x103,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_MC_BodyCAN_0x103,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_MC_TABFuncCtrl_BodyCAN_0x200,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_MC_TABFuncCtrl_BodyCAN_0x200,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_MC_BodyCAN_0x1D4,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_MC_BodyCAN_0x1D4,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_MC_BodyCAN_0x106,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_MC_BodyCAN_0x106,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_MC_BodyCAN_0x10B,
        TRUE,
        PDUR_UNUSED_UINT16,
        CANIF_RXPDU_MC_BodyCAN_0x10B,
        PDUR_CANIF,

    },
    {
        PDUR_SRCPDU_COM_TAB_BodyCAN_0x2A7_Info,
        TRUE,
        PDUR_UNUSED_UINT16,
        COM_TXPDU_COM_TAB_BodyCAN_0x2A7_Info,
        PDUR_COM,

    },
    {
        PDUR_SRCPDU_COM_TAB_BodyCAN_0x2A4_SnsrPrm,
        TRUE,
        PDUR_UNUSED_UINT16,
        COM_TXPDU_COM_TAB_BodyCAN_0x2A4_SnsrPrm,
        PDUR_COM,

    },
    {
        PDUR_SRCPDU_COM_TAB_BodyCAN_0x2A3_SnsrPrm,
        TRUE,
        PDUR_UNUSED_UINT16,
        COM_TXPDU_COM_TAB_BodyCAN_0x2A3_SnsrPrm,
        PDUR_COM,

    },
    {
        PDUR_SRCPDU_COM_TAB_BodyCAN_0x2A6_PrmFr,
        TRUE,
        PDUR_UNUSED_UINT16,
        COM_TXPDU_COM_TAB_BodyCAN_0x2A6_PrmFr,
        PDUR_COM,

    },
    {
        PDUR_SRCPDU_COM_TAB_BodyCAN_0x2A0_FuncSts,
        TRUE,
        PDUR_UNUSED_UINT16,
        COM_TXPDU_COM_TAB_BodyCAN_0x2A0_FuncSts,
        PDUR_COM,

    },
    {
        PDUR_SRCPDU_COM_TAB_BodyCAN_0x2A1_FuncSts,
        TRUE,
        PDUR_UNUSED_UINT16,
        COM_TXPDU_COM_TAB_BodyCAN_0x2A1_FuncSts,
        PDUR_COM,

    },
    {
        PDUR_SRCPDU_COM_TAB_BodyCAN_0x2A2_SnsrPrm,
        TRUE,
        PDUR_UNUSED_UINT16,
        COM_TXPDU_COM_TAB_BodyCAN_0x2A2_SnsrPrm,
        PDUR_COM,

    },
    {
        PDUR_SRCPDU_COM_TAB_BodyCAN_0x2A5_FltSts,
        TRUE,
        PDUR_UNUSED_UINT16,
        COM_TXPDU_COM_TAB_BodyCAN_0x2A5_FltSts,
        PDUR_COM,

    },
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_MCToAllBodyCan_FuncDiagReqFr[1] =
{
    PDUR_DESTPDU_DCM_MCToAllBodyCan_FuncDiagReqFr,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_MCToTAB_PhyDiagReqFr[1] =
{
    PDUR_DESTPDU_DCM_MCToTAB_PhyDiagReqFr,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_TABToMC_DiagResFr[1] =
{
    PDUR_DESTPDU_CANTP_TABToMC_DiagResFr,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
CONST(uint16,PDUR_CONST)
PduR_PduR_CanNM_Eira[1] =
{
    PDUR_DESTPDU_COM_TABBodyNMEira,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_MC_BodyCAN_0x1AA[1] =
{
    PDUR_DESTPDU_COM_MC_BodyCAN_0x1AA,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_MC_BodyCAN_0x143[1] =
{
    PDUR_DESTPDU_COM_MC_BodyCAN_0x143,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_MC_BodyCAN_0x192[1] =
{
    PDUR_DESTPDU_COM_MC_BodyCAN_0x192,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_MC_BodyCAN_0x107[1] =
{
    PDUR_DESTPDU_COM_MC_BodyCAN_0x107,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_MC_BodyCAN_0x100[1] =
{
    PDUR_DESTPDU_COM_MC_BodyCAN_0x100,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_MC_BodyCAN_0x103[1] =
{
    PDUR_DESTPDU_COM_MC_BodyCAN_0x103,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_MC_TABFuncCtrl_BodyCAN_0x200[1] =
{
    PDUR_DESTPDU_COM_MC_TABFuncCtrl_BodyCAN_0x200,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_MC_BodyCAN_0x1D4[1] =
{
    PDUR_DESTPDU_COM_MC_BodyCAN_0x1D4,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_MC_BodyCAN_0x106[1] =
{
    PDUR_DESTPDU_COM_MC_BodyCAN_0x106,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_MC_BodyCAN_0x10B[1] =
{
    PDUR_DESTPDU_COM_MC_BodyCAN_0x10B,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_TAB_BodyCAN_0x2A7_Info[1] =
{
    PDUR_DESTPDU_TAB_BodyCAN_0x2A7_Info,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_TAB_BodyCAN_0x2A4_SnsrPrm[1] =
{
    PDUR_DESTPDU_TAB_BodyCAN_0x2A4_SnsrPrm,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_TAB_BodyCAN_0x2A3_SnsrPrm[1] =
{
    PDUR_DESTPDU_TAB_BodyCAN_0x2A3_SnsrPrm,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_TAB_BodyCAN_0x2A6_PrmFr[1] =
{
    PDUR_DESTPDU_TAB_BodyCAN_0x2A6_PrmFr,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_TAB_BodyCAN_0x2A0_FuncSts[1] =
{
    PDUR_DESTPDU_TAB_BodyCAN_0x2A0_FuncSts,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_TAB_BodyCAN_0x2A1_FuncSts[1] =
{
    PDUR_DESTPDU_TAB_BodyCAN_0x2A1_FuncSts,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_TAB_BodyCAN_0x2A2_SnsrPrm[1] =
{
    PDUR_DESTPDU_TAB_BodyCAN_0x2A2_SnsrPrm,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
CONST(uint16,PDUR_CONST)
PduR_PDUR_ROUTING_TAB_BodyCAN_0x2A5_FltSts[1] =
{
    PDUR_DESTPDU_TAB_BodyCAN_0x2A5_FltSts,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"
CONST(PduRRoutingPathType,PDUR_CONST)
PduR_RoutingPathConfigData0[22] =
{
    {
        PDUR_SRCPDU_CANTP_MCToAllBodyCan_FuncDiagReqFr,
        1u,
        PduR_PDUR_ROUTING_MCToAllBodyCan_FuncDiagReqFr,
        TRUE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CANTP_MCToTAB_PhyDiagReqFr,
        1u,
        PduR_PDUR_ROUTING_MCToTAB_PhyDiagReqFr,
        TRUE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_DCM_TABToMC_DiagResFr,
        1u,
        PduR_PDUR_ROUTING_TABToMC_DiagResFr,
        TRUE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_CanNM_TABBodyNMEira,
        1u,
        PduR_PduR_CanNM_Eira,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_MC_BodyCAN_0x1AA,
        1u,
        PduR_PDUR_ROUTING_MC_BodyCAN_0x1AA,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_MC_BodyCAN_0x143,
        1u,
        PduR_PDUR_ROUTING_MC_BodyCAN_0x143,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_MC_BodyCAN_0x192,
        1u,
        PduR_PDUR_ROUTING_MC_BodyCAN_0x192,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_MC_BodyCAN_0x107,
        1u,
        PduR_PDUR_ROUTING_MC_BodyCAN_0x107,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_MC_BodyCAN_0x100,
        1u,
        PduR_PDUR_ROUTING_MC_BodyCAN_0x100,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_MC_BodyCAN_0x103,
        1u,
        PduR_PDUR_ROUTING_MC_BodyCAN_0x103,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_MC_TABFuncCtrl_BodyCAN_0x200,
        1u,
        PduR_PDUR_ROUTING_MC_TABFuncCtrl_BodyCAN_0x200,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_MC_BodyCAN_0x1D4,
        1u,
        PduR_PDUR_ROUTING_MC_BodyCAN_0x1D4,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_MC_BodyCAN_0x106,
        1u,
        PduR_PDUR_ROUTING_MC_BodyCAN_0x106,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_MC_BodyCAN_0x10B,
        1u,
        PduR_PDUR_ROUTING_MC_BodyCAN_0x10B,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_COM_TAB_BodyCAN_0x2A7_Info,
        1u,
        PduR_PDUR_ROUTING_TAB_BodyCAN_0x2A7_Info,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_COM_TAB_BodyCAN_0x2A4_SnsrPrm,
        1u,
        PduR_PDUR_ROUTING_TAB_BodyCAN_0x2A4_SnsrPrm,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_COM_TAB_BodyCAN_0x2A3_SnsrPrm,
        1u,
        PduR_PDUR_ROUTING_TAB_BodyCAN_0x2A3_SnsrPrm,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_COM_TAB_BodyCAN_0x2A6_PrmFr,
        1u,
        PduR_PDUR_ROUTING_TAB_BodyCAN_0x2A6_PrmFr,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_COM_TAB_BodyCAN_0x2A0_FuncSts,
        1u,
        PduR_PDUR_ROUTING_TAB_BodyCAN_0x2A0_FuncSts,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_COM_TAB_BodyCAN_0x2A1_FuncSts,
        1u,
        PduR_PDUR_ROUTING_TAB_BodyCAN_0x2A1_FuncSts,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_COM_TAB_BodyCAN_0x2A2_SnsrPrm,
        1u,
        PduR_PDUR_ROUTING_TAB_BodyCAN_0x2A2_SnsrPrm,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
    {
        PDUR_SRCPDU_COM_TAB_BodyCAN_0x2A5_FltSts,
        1u,
        PduR_PDUR_ROUTING_TAB_BodyCAN_0x2A5_FltSts,
        FALSE,
        FALSE,
        PDUR_UNUSED_UINT16
    },
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"
CONST(PduRRoutingTableType,PDUR_CONST)
PduR_RoutingTableConfigData[1] =
{
    {
        PduR_RoutingPathConfigData0
    }
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"
CONST(uint16,PDUR_CONST)
PduR_DestPduPathGroup0[3] =
{
    PDUR_DESTPDU_DCM_MCToAllBodyCan_FuncDiagReqFr,
    PDUR_DESTPDU_DCM_MCToTAB_PhyDiagReqFr,
    PDUR_DESTPDU_CANTP_TABToMC_DiagResFr,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_16
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"
CONST(PduRRoutingPathGroupType,PDUR_CONST)
PduR_RoutingPathGroupConfigData[PDUR_ROUTING_PATH_GROUP_SUM] =
{
    {
        FALSE,
        PduRRoutingPathGroup_DCM,
        3u,
        PduR_DestPduPathGroup0
    },
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"

#define PDUR_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"
CONST(PduR_PBConfigType, PDUR_CONST_PBCFG) PduR_PBConfigData =
{
    0u,
    1u,
    22u,
    22u,
    PduR_RoutingPathGroupConfigData,
    PduR_RoutingTableConfigData,
    PduR_SrcPduConfigData,
    PduR_DestPduConfigData,
};
#define PDUR_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"
/*******************************************************************************
**                      End of file                                           **
*******************************************************************************/

