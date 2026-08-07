
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
**  FILENAME    : CanIf_Cfg.h                                                 **
**                                                                            **
**  Created on  : 2025/05/29 15:06:03                                         **
**  Author      : zhengfei.li                                                 **
**  Vendor      :                                                             **
**  DESCRIPTION : cfg parameter declaration of CanIf                          **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/
#ifndef CANIF_CFG_H
#define CANIF_CFG_H

/*=======[V E R S I O N  I N F O R M A T I O N]===============================*/
#define CANIF_CFG_H_AR_MAJOR_VERSION    4u
#define CANIF_CFG_H_AR_MINOR_VERSION    2u
#define CANIF_CFG_H_AR_PATCH_VERSION    2u
#define CANIF_CFG_H_SW_MAJOR_VERSION    2u
#define CANIF_CFG_H_SW_MINOR_VERSION    0u
#define CANIF_CFG_H_SW_PATCH_VERSION    0u

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Macros                                                **
*******************************************************************************/
#define CANIF_CAN_AUTOSAR_422                0u
#define CANIF_CAN_AUTOSAR_431                1u
#define CANIF_CAN_AUTOSAR_440                2u

#define CANIF_CAN_AUTOSAR_VERSION            CANIF_CAN_AUTOSAR_440

#define CANIF_SOFTWARE_FILTER_BINARY                0u
#define CANIF_SOFTWARE_FILTER_INDEX                 1u
#define CANIF_SOFTWARE_FILTER_LINEAR                2u
#define CANIF_SOFTWARE_FILTER_TABLE                 3u

#define CANIF_FIXED_BUFFER            STD_ON

#define CANIF_PRIVATE_DLC_CHECK       STD_ON

#define CANIF_SOFTWARE_FILTER_TYPE    CANIF_SOFTWARE_FILTER_LINEAR

#define CANIF_SUPPORT_TTCAN           STD_OFF

#define CANIF_META_DATA_SUPPORT       STD_OFF

#define CANIF_PUBLIC_CANCEL_TRANSMIT_SUPPORT               STD_OFF

#define CANIF_PUBLIC_DEV_ERROR_DETECT                      STD_ON

#define CANIF_PUBLIC_ICOM_SUPPORT                          STD_OFF

#define CANIF_PUBLIC_MULTIPLE_DRV_SUPPORT                  STD_ON

#define CANIF_PUBLIC_PN_SUPPORT                            STD_OFF

#define CANIF_PUBLIC_READ_RX_PDU_DATA_API                  STD_OFF

#define CANIF_PUBLIC_READ_RX_PDU_NOTIFY_STATUS_API         STD_OFF

#define CANIF_PUBLIC_READ_TX_PDU_NOTIFY_STATUS_API         STD_OFF

#define CANIF_PUBLIC_SET_DYNAMIC_TX_ID_API                 STD_OFF

#define CANIF_PUBLIC_TX_BUFFERING                          STD_ON

#define CANIF_PUBLIC_TX_CONFIRM_POLLING_SUPPORT            STD_ON

#define CANIF_PUBLIC_VERSION_INFO_API                      STD_ON

#define CANIF_PUBLIC_WAKEUP_CHECK_VALID_BY_NM              STD_ON

#define CANIF_PUBLIC_WAKEUP_CHECK_VALID_SUPPORT            STD_ON

#define CANIF_SET_BAUDRATE_API                             STD_OFF

#define CANIF_TRIGGER_TRANSMIT_SUPPORT            STD_OFF

#define CANIF_TX_OFFLINE_ACTIVE_SUPPORT           STD_OFF

#define CANIF_WAKE_UP_SUPPORT                     STD_ON

#define CANIF_CANDRV_WAKE_UP_SUPPORT              STD_OFF

#define CANIF_CANTRCV_WAKE_UP_SUPPORT             STD_OFF

#define CANIF_WAKEUPSOURCE_MAX                    0x7Fu
/*******************************************************************************************/

#define CANIF_RXPDU_NUMBER              13u
#define CANIF_RXPDU_Rx_TABBodyNMFr         0u
#define CANIF_RXPDU_CANIF_MCToAllBodyCan_FuncDiagReqFr         1u
#define CANIF_RXPDU_CANIF_MCToTAB_PhyDiagReqFr         2u
#define CANIF_RXPDU_MC_BodyCAN_0x1AA         3u
#define CANIF_RXPDU_MC_BodyCAN_0x143         4u
#define CANIF_RXPDU_MC_BodyCAN_0x192         5u
#define CANIF_RXPDU_MC_BodyCAN_0x107         6u
#define CANIF_RXPDU_MC_BodyCAN_0x100         7u
#define CANIF_RXPDU_MC_BodyCAN_0x103         8u
#define CANIF_RXPDU_MC_TABFuncCtrl_BodyCAN_0x200         9u
#define CANIF_RXPDU_MC_BodyCAN_0x1D4         10u
#define CANIF_RXPDU_MC_BodyCAN_0x106         11u
#define CANIF_RXPDU_MC_BodyCAN_0x10B         12u

#define CANIF_TXPDU_NUMBER              10u
#define CANIF_DYNAMIC_TXPDU_NUMBER      0u
#define CANIF_TXPDU_TABBodyNMFr         0u
#define CANIF_TXPDU_CANIF_TABToMC_DiagResFr         1u
#define CANIF_TXPDU_TAB_BodyCAN_0x2A7_Info         2u
#define CANIF_TXPDU_TAB_BodyCAN_0x2A4_SnsrPrm         3u
#define CANIF_TXPDU_TAB_BodyCAN_0x2A3_SnsrPrm         4u
#define CANIF_TXPDU_TAB_BodyCAN_0x2A6_PrmFr         5u
#define CANIF_TXPDU_TAB_BodyCAN_0x2A0_FuncSts         6u
#define CANIF_TXPDU_TAB_BodyCAN_0x2A1_FuncSts         7u
#define CANIF_TXPDU_TAB_BodyCAN_0x2A2_SnsrPrm         8u
#define CANIF_TXPDU_TAB_BodyCAN_0x2A5_FltSts         9u

#define CANIF_HRH_NUMBER           13u
#define CANIF_HOH0_HRH_0           0u
#define CANIF_HOH0_HRH_1           1u
#define CANIF_HOH0_HRH_2           2u
#define CANIF_HOH0_HRH_3           3u
#define CANIF_HOH0_HRH_4           4u
#define CANIF_HOH0_HRH_5           5u
#define CANIF_HOH0_HRH_6           6u
#define CANIF_HOH0_HRH_7           7u
#define CANIF_HOH0_HRH_8           8u
#define CANIF_HOH0_HRH_9           9u
#define CANIF_HOH0_HRH_10           10u
#define CANIF_HOH0_HRH_11           11u
#define CANIF_HOH0_HRH_12           12u

#define CANIF_HTH_NUMBER           10u
#define CANIF_HOH0_HTH_0           0u
#define CANIF_HOH0_HTH_1           1u
#define CANIF_HOH0_HTH_2           2u
#define CANIF_HOH0_HTH_3           3u
#define CANIF_HOH0_HTH_4           4u
#define CANIF_HOH0_HTH_5           5u
#define CANIF_HOH0_HTH_6           6u
#define CANIF_HOH0_HTH_7           7u
#define CANIF_HOH0_HTH_8           8u
#define CANIF_HOH0_HTH_9           9u

#define CANIF_TXBUFFER_NUMBER          2u
#define CANIF_RXBUFFER_NUMBER          0u

#define CANIF_RXNOTIFYSTATUS_BUFFER    0u
#define CANIF_TXNOTIFYSTATUS_BUFFER    0u

#define CANIF_CANDRIVER_NUMBER      1u
#define CANIF_CAN    0u
#define CANIF_CANCONTROLLER_NUMBER      1u
#define CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_CAN0    0u

#define CANIF_TRCVDRIVER_NUMBER      0u
#define CANIF_TRCV_NUMBER      0u

#endif
/*******************************************************************************
**                      End of file                                           **
*******************************************************************************/
