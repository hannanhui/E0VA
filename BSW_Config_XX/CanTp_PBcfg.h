/*============================================================================*/
/*  Copyright (C) iSOFT   (2022), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <CanTp_PBcfg.h>
 *  @brief      <>
 *  
 *  <MCU:Z20K144M>
 *  
 *  @author     <>
 *  @date       <2025-05-09 15:24:15>
 */
/*============================================================================*/

/*============================================================================*/
#ifndef CANTP_PBCFG_H
#define CANTP_PBCFG_H

/*======== [I N C L U D E S]========================*/
#include "Std_Types.h"

/*========[V E R S I O N  I N F O R M A T I O N]=========*/
#define CANTP_CFG_H_AR_MAJOR_VERSION 4U
#define CANTP_CFG_H_AR_MINOR_VERSION 5U
#define CANTP_CFG_H_AR_PATCH_VERSION 0U
#define CANTP_CFG_H_SW_MAJOR_VERSION 2U
#define CANTP_CFG_H_SW_MINOR_VERSION 1U
#define CANTP_CFG_H_SW_PATCH_VERSION 0U

/*========[M A C R O S] ==========================*/
/* Total number of channel used in CanTp module. */
#define CANTP_CHANNEL_NUMBER                        0x1u

/*configuration MACRO addressing mode for cutting*/
#define CANTP_EXTENDED_ADDRESSING_SUPPORT           STD_OFF
#define CANTP_NORMAL_FIXED_ADDRESSING_SUPPORT       STD_OFF
#define CANTP_MIXED_ADDRESSING_SUPPORT              STD_OFF
#define CANTP_MIXED29_ADDRESSING_SUPPORT            STD_OFF

/* -------------------- CanTpChannel -------------------- */

/* CanTpRxNSdu_FuncReq */    
#define CANTP_CANTP_MCToAllBodyCan_FuncDiagReqFr                                0x8u/*RxNSdu Id*/
#define CANTP_CANIF_MCToAllBodyCan_FuncDiagReqFr                                 0x2u/*RxNPdu Id*/

/* CanTpRxNSdu_PhyReq */    
#define CANTP_CANTP_MCToTAB_PhyDiagReqFr                                0x9u/*RxNSdu Id*/
#define CANTP_CANIF_MCToTAB_PhyDiagReqFr                                 0x3u/*RxNPdu Id*/
#define CANTP_CANIF_TABToMC_DiagResFr                               0x4u/*TxFcNPdu Id*/

/* CanTpTxNSdu_Resp */    
#define CANTP_CANTP_TABToMC_DiagResFr                                0xau/*TxNSdu Id*/
#define CANTP_CANIF_TABToMC_DiagResFr                                 0x4u/*TxNPdu Id*/
#define CANTP_CANIF_MCToTAB_PhyDiagReqFr                               0x3u/*RxFcNPdu Id*/

#endif /* CANTP_PBCFG_H */
