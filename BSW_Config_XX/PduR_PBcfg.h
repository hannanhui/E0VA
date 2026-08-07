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
**  FILENAME    : PduR_PBcfg.h                                                **
**                                                                            **
**  Created on  : 2025/05/29 15:06:03                                         **
**  Author      : zhengfei.li                                                 **
**  Vendor      :                                                             **
**  DESCRIPTION : Configuration parameter of PDUR                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/
#ifndef  PDUR_PBCFG_H
#define  PDUR_PBCFG_H
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
#define PDUR_PBCFG_H_AR_MAJOR_VERSION  4u
#define PDUR_PBCFG_H_AR_MINOR_VERSION  2u
#define PDUR_PBCFG_H_AR_PATCH_VERSION  2u
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Macros                                                **
*******************************************************************************/
#define PDUR_SRC_PDU_SUM           22u

#define PDUR_SRCPDU_CANTP_MCToAllBodyCan_FuncDiagReqFr          0u
#define PDUR_SRCPDU_CANTP_MCToTAB_PhyDiagReqFr          1u
#define PDUR_SRCPDU_DCM_TABToMC_DiagResFr          2u
#define PDUR_SRCPDU_CanNM_TABBodyNMEira          3u
#define PDUR_SRCPDU_MC_BodyCAN_0x1AA          4u
#define PDUR_SRCPDU_MC_BodyCAN_0x143          5u
#define PDUR_SRCPDU_MC_BodyCAN_0x192          6u
#define PDUR_SRCPDU_MC_BodyCAN_0x107          7u
#define PDUR_SRCPDU_MC_BodyCAN_0x100          8u
#define PDUR_SRCPDU_MC_BodyCAN_0x103          9u
#define PDUR_SRCPDU_MC_TABFuncCtrl_BodyCAN_0x200          10u
#define PDUR_SRCPDU_MC_BodyCAN_0x1D4          11u
#define PDUR_SRCPDU_MC_BodyCAN_0x106          12u
#define PDUR_SRCPDU_MC_BodyCAN_0x10B          13u
#define PDUR_SRCPDU_COM_TAB_BodyCAN_0x2A7_Info          14u
#define PDUR_SRCPDU_COM_TAB_BodyCAN_0x2A4_SnsrPrm          15u
#define PDUR_SRCPDU_COM_TAB_BodyCAN_0x2A3_SnsrPrm          16u
#define PDUR_SRCPDU_COM_TAB_BodyCAN_0x2A6_PrmFr          17u
#define PDUR_SRCPDU_COM_TAB_BodyCAN_0x2A0_FuncSts          18u
#define PDUR_SRCPDU_COM_TAB_BodyCAN_0x2A1_FuncSts          19u
#define PDUR_SRCPDU_COM_TAB_BodyCAN_0x2A2_SnsrPrm          20u
#define PDUR_SRCPDU_COM_TAB_BodyCAN_0x2A5_FltSts          21u

#define PDUR_DEST_PDU_SUM              22u

#define PDUR_DEST_GATEWAY_TP_PDU_SUM   0u

#define PDUR_DESTPDU_DCM_MCToAllBodyCan_FuncDiagReqFr          0u
#define PDUR_DESTPDU_DCM_MCToTAB_PhyDiagReqFr          1u
#define PDUR_DESTPDU_CANTP_TABToMC_DiagResFr          2u
#define PDUR_DESTPDU_COM_TABBodyNMEira          3u
#define PDUR_DESTPDU_COM_MC_BodyCAN_0x1AA          4u
#define PDUR_DESTPDU_COM_MC_BodyCAN_0x143          5u
#define PDUR_DESTPDU_COM_MC_BodyCAN_0x192          6u
#define PDUR_DESTPDU_COM_MC_BodyCAN_0x107          7u
#define PDUR_DESTPDU_COM_MC_BodyCAN_0x100          8u
#define PDUR_DESTPDU_COM_MC_BodyCAN_0x103          9u
#define PDUR_DESTPDU_COM_MC_TABFuncCtrl_BodyCAN_0x200          10u
#define PDUR_DESTPDU_COM_MC_BodyCAN_0x1D4          11u
#define PDUR_DESTPDU_COM_MC_BodyCAN_0x106          12u
#define PDUR_DESTPDU_COM_MC_BodyCAN_0x10B          13u
#define PDUR_DESTPDU_TAB_BodyCAN_0x2A7_Info          14u
#define PDUR_DESTPDU_TAB_BodyCAN_0x2A4_SnsrPrm          15u
#define PDUR_DESTPDU_TAB_BodyCAN_0x2A3_SnsrPrm          16u
#define PDUR_DESTPDU_TAB_BodyCAN_0x2A6_PrmFr          17u
#define PDUR_DESTPDU_TAB_BodyCAN_0x2A0_FuncSts          18u
#define PDUR_DESTPDU_TAB_BodyCAN_0x2A1_FuncSts          19u
#define PDUR_DESTPDU_TAB_BodyCAN_0x2A2_SnsrPrm          20u
#define PDUR_DESTPDU_TAB_BodyCAN_0x2A5_FltSts          21u

#define PDUR_ROUTING_PATH_GROUP_SUM        1u

#define PduRRoutingPathGroup_DCM          0u

#define PDUR_SRC_UP_MULTICAST_TX_IF_SUM              0u
#define PDUR_GATEWAY_DIRECT_BUFFER_PDU_SUM           0u

#define PDUR_DEFAULT_VALUE_LENGTH           0u
#define PDUR_DEFAULT_VALUE_PDU                  0u

#endif  /* end of PDUR_CFG_H */

/*******************************************************************************
**                      End of file                                           **
*******************************************************************************/

