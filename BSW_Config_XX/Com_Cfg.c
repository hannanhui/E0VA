
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
**  FILENAME    : Com_Cfg.c                                                   **
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
#include "Com.h"
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
#define COM_CFG_C_AR_MAJOR_VERSION  4u
#define COM_CFG_C_AR_MINOR_VERSION  2u
#define COM_CFG_C_AR_PATCH_VERSION  2u
#define COM_CFG_C_SW_MAJOR_VERSION  2u
#define COM_CFG_C_SW_MINOR_VERSION  0u
#define COM_CFG_C_SW_PATCH_VERSION  0u

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (COM_CFG_C_AR_MAJOR_VERSION != COM_CFG_H_AR_MAJOR_VERSION)
    #error "Com.c:Mismatch in Specification Major Version"
#endif

#if (COM_CFG_C_AR_MINOR_VERSION != COM_CFG_H_AR_MINOR_VERSION)
    #error "Com.c:Mismatch in Specification Minor Version"
#endif

#if (COM_CFG_C_AR_PATCH_VERSION != COM_CFG_H_AR_PATCH_VERSION)
    #error "Com.c:Mismatch in Specification Patch Version"
#endif

#if (COM_CFG_C_SW_MAJOR_VERSION != COM_CFG_H_SW_MAJOR_VERSION)
    #error "Com.c:Mismatch in Specification Major Version"
#endif

#if (COM_CFG_C_SW_MINOR_VERSION != COM_CFG_H_SW_MINOR_VERSION)
    #error "Com.c:Mismatch in Specification Minor Version"
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
#define COM_START_SEC_VAR_NO_INIT_8
#include "Com_MemMap.h"
VAR(uint8, COM_VAR) Com_TxIPduRuntimeBuff[COM_TXIPDUBUFF_SIZE];
#define COM_STOP_SEC_VAR_NO_INIT_8
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_8
#include "Com_MemMap.h"
CONST(uint8,COM_CONST_PBCFG) Com_TxIPduInitValue[COM_TXIPDUBUFF_SIZE] = {
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x87,0x4B,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};
#define COM_STOP_SEC_PBCONFIG_DATA_8
#include "Com_MemMap.h"

#define COM_START_SEC_VAR_NO_INIT_8
#include "Com_MemMap.h"
VAR(uint8, COM_VAR) Com_RxIPduRuntimeBuff[COM_RXIPDUBUFF_SIZE];
#define COM_STOP_SEC_VAR_NO_INIT_8
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_8
#include "Com_MemMap.h"
CONST(uint8,COM_CONST_PBCFG) Com_RxIPduInitValue[COM_RXIPDUBUFF_SIZE]= {
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x61,0xA8,0x75,0x30,0x05,0x00,
    0x00,0x00,0x67,0x20,0x00,0x00,0x03,0x20,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x18,0x3C,0xF3,0xE8,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x20,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};
#define COM_STOP_SEC_PBCONFIG_DATA_8
#include "Com_MemMap.h"

#define COM_START_SEC_VAR_NO_INIT_BOOLEAN
#include "Com_MemMap.h"
VAR(boolean, COM_VAR) Com_SignalBoolRuntimeBuff[COM_SIGNAL_BOOLBUFF_SIZE];
#define COM_STOP_SEC_VAR_NO_INIT_BOOLEAN
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_BOOLEAN
#include "Com_MemMap.h"
CONST(boolean,COM_CONST_PBCFG) Com_SignalBoolInitValue[COM_SIGNAL_BOOLBUFF_SIZE] = {
    FALSE,FALSE,FALSE,FALSE,FALSE,FALSE
};
#define COM_STOP_SEC_PBCONFIG_DATA_BOOLEAN
#include "Com_MemMap.h"

#define COM_START_SEC_VAR_NO_INIT_8
#include "Com_MemMap.h"
VAR(uint8, COM_VAR) Com_Signal8BitRuntimeBuff[COM_SIGNAL_8BITBUFF_SIZE];
#define COM_STOP_SEC_VAR_NO_INIT_8
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_8
#include "Com_MemMap.h"
CONST(uint8,COM_CONST_PBCFG) Com_Signal8BitInitValue[COM_SIGNAL_8BITBUFF_SIZE] = {
    0x01,0x00,0x00,0x01,0x00,0x00,0x00,0x00,
    0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x18,
    0x3C,0x00,0x3C,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x87,
    0x4B,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00
};
#define COM_STOP_SEC_PBCONFIG_DATA_8
#include "Com_MemMap.h"

#define COM_START_SEC_VAR_NO_INIT_16
#include "Com_MemMap.h"
VAR(uint16, COM_VAR) Com_Signal16BitRuntimeBuff[COM_SIGNAL_16BITBUFF_SIZE];
#define COM_STOP_SEC_VAR_NO_INIT_16
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"
CONST(uint16,COM_CONST_PBCFG) Com_Signal16BitInitValue[COM_SIGNAL_16BITBUFF_SIZE]={
    0x61a8,0x7530,0x320,0x3390,0x3e8,0x0,0x0,0x0,
    0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
    0x0,0x0,0xff,0x0,0x0,0x0,0x0,0x0
};
#define COM_STOP_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"

#define COM_START_SEC_VAR_NO_INIT_32
#include "Com_MemMap.h"
VAR(uint32, COM_VAR) Com_Signal32BitRuntimeBuff[COM_SIGNAL_32BITBUFF_SIZE];
#define COM_STOP_SEC_VAR_NO_INIT_32
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_32
#include "Com_MemMap.h"
CONST(uint32,COM_CONST_PBCFG) Com_Signal32BitInitValue[COM_SIGNAL_32BITBUFF_SIZE] = {
    0x0
};
#define COM_STOP_SEC_PBCONFIG_DATA_32
#include "Com_MemMap.h"

#define COM_START_SEC_VAR_NO_INIT_BOOLEAN
#include "Com_MemMap.h"
VAR(boolean, COM_VAR) Com_RxGroupSignalBoolShadowBuff[COM_RXGROUPSIGNAL_BOOLBUFF_SIZE];
#define COM_STOP_SEC_VAR_NO_INIT_BOOLEAN
#include "Com_MemMap.h"

#define COM_START_SEC_VAR_NO_INIT_8
#include "Com_MemMap.h"
VAR(uint8, COM_VAR) Com_RxGroupSignal8BitShadowBuff[COM_RXGROUPSIGNAL_8BITBUFF_SIZE];
#define COM_STOP_SEC_VAR_NO_INIT_8
#include "Com_MemMap.h"

#define COM_START_SEC_VAR_NO_INIT_16
#include "Com_MemMap.h"
VAR(uint16, COM_VAR) Com_RxGroupSignal16BitShadowBuff[COM_RXGROUPSIGNAL_16BITBUFF_SIZE];
#define COM_STOP_SEC_VAR_NO_INIT_16
#include "Com_MemMap.h"

#define COM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Com_MemMap.h"
VAR(Com_RxIPduRunTimeStateType, COM_VAR) Com_RxIPduRunTimeState[COM_RXIPDU_NUMBER];
#define COM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"
CONST(Com_RxIPduRunTimeStateType, COM_CONST) Com_RxIPduInitState[COM_RXIPDU_NUMBER]=
{
    {
        TRUE,
        FALSE,
        FALSE,
        8u,
        0u,
        FALSE,
        FALSE,
        0u,
        FALSE,
        0u,
        0u
    },
    {
        FALSE,
        FALSE,
        FALSE,
        8u,
        0u,
        FALSE,
        FALSE,
        0u,
        FALSE,
        0u,
        0u
    },
    {
        FALSE,
        FALSE,
        FALSE,
        8u,
        0u,
        FALSE,
        FALSE,
        0u,
        FALSE,
        0u,
        0u
    },
    {
        FALSE,
        FALSE,
        FALSE,
        8u,
        0u,
        FALSE,
        FALSE,
        0u,
        FALSE,
        0u,
        0u
    },
    {
        FALSE,
        FALSE,
        FALSE,
        8u,
        0u,
        FALSE,
        FALSE,
        0u,
        FALSE,
        0u,
        0u
    },
    {
        FALSE,
        FALSE,
        FALSE,
        8u,
        0u,
        FALSE,
        FALSE,
        0u,
        FALSE,
        0u,
        0u
    },
    {
        FALSE,
        FALSE,
        FALSE,
        8u,
        0u,
        FALSE,
        FALSE,
        0u,
        FALSE,
        0u,
        0u
    },
    {
        FALSE,
        FALSE,
        FALSE,
        8u,
        0u,
        FALSE,
        FALSE,
        0u,
        FALSE,
        0u,
        0u
    },
    {
        FALSE,
        FALSE,
        FALSE,
        8u,
        0u,
        FALSE,
        FALSE,
        0u,
        FALSE,
        0u,
        0u
    },
    {
        FALSE,
        FALSE,
        FALSE,
        8u,
        0u,
        FALSE,
        FALSE,
        0u,
        FALSE,
        0u,
        0u
    },
    {
        FALSE,
        FALSE,
        FALSE,
        8u,
        0u,
        FALSE,
        FALSE,
        0u,
        FALSE,
        0u,
        0u
    },
};
#define COM_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"

#define COM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Com_MemMap.h"
VAR(Com_TxIPduRunTimeStateType, COM_VAR) Com_TxIPduRunTimeState[COM_TXIPDU_NUMBER];
#define COM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"
CONST(Com_TxIPduRunTimeStateType, COM_CONST) Com_TxIPduInitState[COM_TXIPDU_NUMBER]=
{
    {
        FALSE,
        FALSE,
        TRUE,
        FALSE,
        8u,
        0u,
        COM_TX_MODE_PERIODIC,
        0u,
        0u,
        0u,
        0u,
        FALSE,
        0u,
        0u
    },
    {
        FALSE,
        FALSE,
        TRUE,
        FALSE,
        8u,
        0u,
        COM_TX_MODE_PERIODIC,
        0u,
        0u,
        0u,
        0u,
        FALSE,
        0u,
        0u
    },
    {
        FALSE,
        FALSE,
        TRUE,
        FALSE,
        8u,
        0u,
        COM_TX_MODE_PERIODIC,
        0u,
        0u,
        0u,
        0u,
        FALSE,
        0u,
        0u
    },
    {
        FALSE,
        FALSE,
        TRUE,
        FALSE,
        8u,
        0u,
        COM_TX_MODE_PERIODIC,
        0u,
        0u,
        0u,
        0u,
        FALSE,
        0u,
        0u
    },
    {
        FALSE,
        FALSE,
        TRUE,
        FALSE,
        8u,
        0u,
        COM_TX_MODE_PERIODIC,
        0u,
        0u,
        0u,
        0u,
        FALSE,
        0u,
        0u
    },
    {
        FALSE,
        FALSE,
        TRUE,
        FALSE,
        8u,
        0u,
        COM_TX_MODE_PERIODIC,
        0u,
        0u,
        0u,
        0u,
        FALSE,
        0u,
        0u
    },
    {
        FALSE,
        FALSE,
        TRUE,
        FALSE,
        8u,
        0u,
        COM_TX_MODE_PERIODIC,
        0u,
        0u,
        0u,
        0u,
        FALSE,
        0u,
        0u
    },
    {
        FALSE,
        FALSE,
        TRUE,
        FALSE,
        8u,
        0u,
        COM_TX_MODE_PERIODIC,
        0u,
        0u,
        0u,
        0u,
        FALSE,
        0u,
        0u
    },
};
#define COM_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"
CONST(Com_IpduGroupIdType, COM_CONST) ComRxIPduGroupsRef_0[1] = {0u};
#define COM_STOP_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"
CONST(Com_IpduGroupIdType, COM_CONST) ComRxIPduGroupsRef_1[1] = {0u};
#define COM_STOP_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"
CONST(Com_IpduGroupIdType, COM_CONST) ComRxIPduGroupsRef_2[1] = {0u};
#define COM_STOP_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"
CONST(Com_IpduGroupIdType, COM_CONST) ComRxIPduGroupsRef_3[1] = {0u};
#define COM_STOP_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"
CONST(Com_IpduGroupIdType, COM_CONST) ComRxIPduGroupsRef_4[1] = {0u};
#define COM_STOP_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"
CONST(Com_IpduGroupIdType, COM_CONST) ComRxIPduGroupsRef_5[1] = {0u};
#define COM_STOP_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"
CONST(Com_IpduGroupIdType, COM_CONST) ComRxIPduGroupsRef_6[1] = {0u};
#define COM_STOP_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"
CONST(Com_IpduGroupIdType, COM_CONST) ComRxIPduGroupsRef_7[1] = {0u};
#define COM_STOP_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"
CONST(Com_IpduGroupIdType, COM_CONST) ComRxIPduGroupsRef_8[1] = {0u};
#define COM_STOP_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"
CONST(Com_IpduGroupIdType, COM_CONST) ComRxIPduGroupsRef_9[1] = {0u};
#define COM_STOP_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"
CONST(Com_SignalGroupIdType, COM_CONST) ComRxIPduSignalGroupsRef_0[1] = {0u};
#define COM_STOP_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"
CONST(Com_SignalGroupIdType, COM_CONST) ComRxIPduSignalGroupsRef_1[2] = {1u,2u};
#define COM_STOP_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"
CONST(Com_SignalGroupIdType, COM_CONST) ComRxIPduSignalGroupsRef_2[2] = {3u,4u};
#define COM_STOP_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"
CONST(Com_SignalIdType, COM_CONST) ComRxIPduSignalsRef_0[1] = {0u};
#define COM_STOP_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"
CONST(Com_SignalIdType, COM_CONST) ComRxIPduSignalsRef_1[7] = {1u,2u,3u,4u,5u,6u,7u};
#define COM_STOP_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"
CONST(Com_SignalIdType, COM_CONST) ComRxIPduSignalsRef_2[2] = {8u,9u};
#define COM_STOP_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"
CONST(Com_SignalIdType, COM_CONST) ComRxIPduSignalsRef_3[10] = {10u,11u,12u,13u,14u,15u,16u,17u,18u,19u};
#define COM_STOP_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"
CONST(Com_SignalIdType, COM_CONST) ComRxIPduSignalsRef_4[2] = {20u,21u};
#define COM_STOP_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"
CONST(Com_SignalIdType, COM_CONST) ComRxIPduSignalsRef_5[2] = {22u,23u};
#define COM_STOP_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"
CONST(Com_SignalIdType, COM_CONST) ComRxIPduSignalsRef_6[2] = {24u,25u};
#define COM_STOP_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"
CONST(Com_RxIPduType, COM_CONST) Com_RxIPdu[COM_RXIPDU_NUMBER]=
{
    {
        NULL_PTR,

        COM_RXPDU_COM_TABBodyNMEira,
        COM_DEFERRED,
        COM_PDU_NORMAL,
        0u,
        NULL_PTR,
        0u,
        NULL_PTR,
        0u,
        NULL_PTR,
        0u,
        NULL_PTR,
        0u,
        8u,
        0u,
        0u,
        NULL_PTR,
        NULL_PTR,
        FALSE
    },
    {
        NULL_PTR,

        COM_RXPDU_COM_MC_BodyCAN_0x1AA,
        COM_DEFERRED,
        COM_PDU_NORMAL,
        1u,
        &ComRxIPduGroupsRef_0[0],
        1u,
        &ComRxIPduSignalGroupsRef_0[0],
        0u,
        NULL_PTR,
        0u,
        NULL_PTR,
        0u,
        8u,
        0u,
        8u,
        NULL_PTR,
        NULL_PTR,
        FALSE
    },
    {
        NULL_PTR,

        COM_RXPDU_COM_MC_BodyCAN_0x143,
        COM_DEFERRED,
        COM_PDU_NORMAL,
        1u,
        &ComRxIPduGroupsRef_1[0],
        2u,
        &ComRxIPduSignalGroupsRef_1[0],
        0u,
        NULL_PTR,
        0u,
        NULL_PTR,
        0u,
        8u,
        0u,
        16u,
        NULL_PTR,
        NULL_PTR,
        FALSE
    },
    {
        NULL_PTR,

        COM_RXPDU_COM_MC_BodyCAN_0x192,
        COM_DEFERRED,
        COM_PDU_NORMAL,
        1u,
        &ComRxIPduGroupsRef_2[0],
        0u,
        NULL_PTR,
        1u,
        &ComRxIPduSignalsRef_0[0],
        0u,
        NULL_PTR,
        0u,
        8u,
        0u,
        24u,
        NULL_PTR,
        NULL_PTR,
        FALSE
    },
    {
        NULL_PTR,

        COM_RXPDU_COM_MC_BodyCAN_0x107,
        COM_DEFERRED,
        COM_PDU_NORMAL,
        1u,
        &ComRxIPduGroupsRef_3[0],
        0u,
        NULL_PTR,
        7u,
        &ComRxIPduSignalsRef_1[0],
        0u,
        NULL_PTR,
        0u,
        8u,
        0u,
        32u,
        NULL_PTR,
        NULL_PTR,
        FALSE
    },
    {
        NULL_PTR,

        COM_RXPDU_COM_MC_BodyCAN_0x100,
        COM_DEFERRED,
        COM_PDU_NORMAL,
        1u,
        &ComRxIPduGroupsRef_4[0],
        0u,
        NULL_PTR,
        2u,
        &ComRxIPduSignalsRef_2[0],
        0u,
        NULL_PTR,
        0u,
        8u,
        0u,
        40u,
        NULL_PTR,
        NULL_PTR,
        FALSE
    },
    {
        NULL_PTR,

        COM_RXPDU_COM_MC_BodyCAN_0x103,
        COM_DEFERRED,
        COM_PDU_NORMAL,
        1u,
        &ComRxIPduGroupsRef_5[0],
        2u,
        &ComRxIPduSignalGroupsRef_2[0],
        0u,
        NULL_PTR,
        0u,
        NULL_PTR,
        0u,
        8u,
        0u,
        48u,
        NULL_PTR,
        NULL_PTR,
        FALSE
    },
    {
        NULL_PTR,

        COM_RXPDU_COM_MC_TABFuncCtrl_BodyCAN_0x200,
        COM_DEFERRED,
        COM_PDU_NORMAL,
        1u,
        &ComRxIPduGroupsRef_6[0],
        0u,
        NULL_PTR,
        10u,
        &ComRxIPduSignalsRef_3[0],
        0u,
        NULL_PTR,
        0u,
        8u,
        0u,
        56u,
        NULL_PTR,
        NULL_PTR,
        FALSE
    },
    {
        NULL_PTR,

        COM_RXPDU_COM_MC_BodyCAN_0x1D4,
        COM_DEFERRED,
        COM_PDU_NORMAL,
        1u,
        &ComRxIPduGroupsRef_7[0],
        0u,
        NULL_PTR,
        2u,
        &ComRxIPduSignalsRef_4[0],
        0u,
        NULL_PTR,
        0u,
        8u,
        0u,
        64u,
        NULL_PTR,
        NULL_PTR,
        FALSE
    },
    {
        NULL_PTR,

        COM_RXPDU_COM_MC_BodyCAN_0x106,
        COM_DEFERRED,
        COM_PDU_NORMAL,
        1u,
        &ComRxIPduGroupsRef_8[0],
        0u,
        NULL_PTR,
        2u,
        &ComRxIPduSignalsRef_5[0],
        0u,
        NULL_PTR,
        0u,
        8u,
        0u,
        72u,
        NULL_PTR,
        NULL_PTR,
        FALSE
    },
    {
        NULL_PTR,

        COM_RXPDU_COM_MC_BodyCAN_0x10B,
        COM_DEFERRED,
        COM_PDU_NORMAL,
        1u,
        &ComRxIPduGroupsRef_9[0],
        0u,
        NULL_PTR,
        2u,
        &ComRxIPduSignalsRef_6[0],
        0u,
        NULL_PTR,
        0u,
        8u,
        0u,
        80u,
        NULL_PTR,
        NULL_PTR,
        FALSE
    },
};
#define COM_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"
CONST(Com_IpduGroupIdType, COM_CONST) ComTxIPduGroupsRef_0[1] = {1u};
#define COM_STOP_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"
CONST(Com_IpduGroupIdType, COM_CONST) ComTxIPduGroupsRef_1[1] = {1u};
#define COM_STOP_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"
CONST(Com_IpduGroupIdType, COM_CONST) ComTxIPduGroupsRef_2[1] = {1u};
#define COM_STOP_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"
CONST(Com_IpduGroupIdType, COM_CONST) ComTxIPduGroupsRef_3[1] = {1u};
#define COM_STOP_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"
CONST(Com_IpduGroupIdType, COM_CONST) ComTxIPduGroupsRef_4[1] = {1u};
#define COM_STOP_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"
CONST(Com_IpduGroupIdType, COM_CONST) ComTxIPduGroupsRef_5[1] = {1u};
#define COM_STOP_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"
CONST(Com_IpduGroupIdType, COM_CONST) ComTxIPduGroupsRef_6[1] = {1u};
#define COM_STOP_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"
CONST(Com_IpduGroupIdType, COM_CONST) ComTxIPduGroupsRef_7[1] = {1u};
#define COM_STOP_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"
CONST(Com_SignalIdType, COM_CONST) ComTxIPduSignalsRef_0[3] = {0u,1u,2u};
#define COM_STOP_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"
CONST(Com_SignalIdType, COM_CONST) ComTxIPduSignalsRef_1[2] = {3u,4u};
#define COM_STOP_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"
CONST(Com_SignalIdType, COM_CONST) ComTxIPduSignalsRef_2[5] = {5u,6u,7u,8u,9u};
#define COM_STOP_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"
CONST(Com_SignalIdType, COM_CONST) ComTxIPduSignalsRef_3[4] = {10u,11u,12u,13u};
#define COM_STOP_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"
CONST(Com_SignalIdType, COM_CONST) ComTxIPduSignalsRef_4[10] = {14u,15u,16u,17u,18u,19u,20u,21u,22u,23u};
#define COM_STOP_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"
CONST(Com_SignalIdType, COM_CONST) ComTxIPduSignalsRef_5[3] = {24u,25u,26u};
#define COM_STOP_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"
CONST(Com_SignalIdType, COM_CONST) ComTxIPduSignalsRef_6[5] = {27u,28u,29u,30u,31u};
#define COM_STOP_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"
CONST(Com_SignalIdType, COM_CONST) ComTxIPduSignalsRef_7[4] = {32u,33u,34u,35u};
#define COM_STOP_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"
CONST(Com_TxModeType, COM_CONST) ComTxModeTrue[8]=
{
    {
        COM_TX_MODE_PERIODIC,
        1u,
        0u,
        0u,
        20u,
    },
    {
        COM_TX_MODE_PERIODIC,
        1u,
        0u,
        0u,
        10u,
    },
    {
        COM_TX_MODE_PERIODIC,
        1u,
        0u,
        0u,
        10u,
    },
    {
        COM_TX_MODE_PERIODIC,
        1u,
        0u,
        0u,
        20u,
    },
    {
        COM_TX_MODE_PERIODIC,
        1u,
        0u,
        0u,
        10u,
    },
    {
        COM_TX_MODE_PERIODIC,
        1u,
        0u,
        0u,
        10u,
    },
    {
        COM_TX_MODE_PERIODIC,
        1u,
        0u,
        0u,
        10u,
    },
    {
        COM_TX_MODE_PERIODIC,
        1u,
        0u,
        0u,
        40u,
    },
};
#define COM_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"
CONST(Com_TxIPduType, COM_CONST) Com_TxIPdu[COM_TXIPDU_NUMBER]=
{
    {
        NULL_PTR,

        COM_TXPDU_COM_TAB_BodyCAN_0x2A7_Info,
        COM_DEFERRED,
        NULL_PTR,
        COM_PDU_NORMAL,
        1u,
        &ComTxIPduGroupsRef_0[0],
        0u,
        NULL_PTR,
        3u,
        &ComTxIPduSignalsRef_0[0],
        0u,
        NULL_PTR,
        PDUR_SRCPDU_COM_TAB_BodyCAN_0x2A7_Info,
        0u,
        8u,
        0u,
        0u,
        NULL_PTR,
        NULL_PTR,
        0u,
        COM_CONFIRMATION,
        &ComTxModeTrue[0],
        NULL_PTR,
        0u
    },
    {
        NULL_PTR,

        COM_TXPDU_COM_TAB_BodyCAN_0x2A4_SnsrPrm,
        COM_DEFERRED,
        NULL_PTR,
        COM_PDU_NORMAL,
        1u,
        &ComTxIPduGroupsRef_1[0],
        0u,
        NULL_PTR,
        2u,
        &ComTxIPduSignalsRef_1[0],
        0u,
        NULL_PTR,
        PDUR_SRCPDU_COM_TAB_BodyCAN_0x2A4_SnsrPrm,
        0u,
        8u,
        0u,
        8u,
        NULL_PTR,
        NULL_PTR,
        0u,
        COM_CONFIRMATION,
        &ComTxModeTrue[1],
        NULL_PTR,
        0u
    },
    {
        NULL_PTR,

        COM_TXPDU_COM_TAB_BodyCAN_0x2A3_SnsrPrm,
        COM_DEFERRED,
        NULL_PTR,
        COM_PDU_NORMAL,
        1u,
        &ComTxIPduGroupsRef_2[0],
        0u,
        NULL_PTR,
        5u,
        &ComTxIPduSignalsRef_2[0],
        0u,
        NULL_PTR,
        PDUR_SRCPDU_COM_TAB_BodyCAN_0x2A3_SnsrPrm,
        0u,
        8u,
        0u,
        16u,
        NULL_PTR,
        NULL_PTR,
        0u,
        COM_CONFIRMATION,
        &ComTxModeTrue[2],
        NULL_PTR,
        0u
    },
    {
        NULL_PTR,

        COM_TXPDU_COM_TAB_BodyCAN_0x2A6_PrmFr,
        COM_DEFERRED,
        NULL_PTR,
        COM_PDU_NORMAL,
        1u,
        &ComTxIPduGroupsRef_3[0],
        0u,
        NULL_PTR,
        4u,
        &ComTxIPduSignalsRef_3[0],
        0u,
        NULL_PTR,
        PDUR_SRCPDU_COM_TAB_BodyCAN_0x2A6_PrmFr,
        0u,
        8u,
        0u,
        24u,
        NULL_PTR,
        NULL_PTR,
        0u,
        COM_CONFIRMATION,
        &ComTxModeTrue[3],
        NULL_PTR,
        0u
    },
    {
        NULL_PTR,

        COM_TXPDU_COM_TAB_BodyCAN_0x2A0_FuncSts,
        COM_DEFERRED,
        NULL_PTR,
        COM_PDU_NORMAL,
        1u,
        &ComTxIPduGroupsRef_4[0],
        0u,
        NULL_PTR,
        10u,
        &ComTxIPduSignalsRef_4[0],
        0u,
        NULL_PTR,
        PDUR_SRCPDU_COM_TAB_BodyCAN_0x2A0_FuncSts,
        0u,
        8u,
        0u,
        32u,
        NULL_PTR,
        NULL_PTR,
        0u,
        COM_CONFIRMATION,
        &ComTxModeTrue[4],
        NULL_PTR,
        0u
    },
    {
        NULL_PTR,

        COM_TXPDU_COM_TAB_BodyCAN_0x2A1_FuncSts,
        COM_DEFERRED,
        NULL_PTR,
        COM_PDU_NORMAL,
        1u,
        &ComTxIPduGroupsRef_5[0],
        0u,
        NULL_PTR,
        3u,
        &ComTxIPduSignalsRef_5[0],
        0u,
        NULL_PTR,
        PDUR_SRCPDU_COM_TAB_BodyCAN_0x2A1_FuncSts,
        0u,
        8u,
        0u,
        40u,
        NULL_PTR,
        NULL_PTR,
        0u,
        COM_CONFIRMATION,
        &ComTxModeTrue[5],
        NULL_PTR,
        0u
    },
    {
        NULL_PTR,

        COM_TXPDU_COM_TAB_BodyCAN_0x2A2_SnsrPrm,
        COM_DEFERRED,
        NULL_PTR,
        COM_PDU_NORMAL,
        1u,
        &ComTxIPduGroupsRef_6[0],
        0u,
        NULL_PTR,
        5u,
        &ComTxIPduSignalsRef_6[0],
        0u,
        NULL_PTR,
        PDUR_SRCPDU_COM_TAB_BodyCAN_0x2A2_SnsrPrm,
        0u,
        8u,
        0u,
        48u,
        NULL_PTR,
        NULL_PTR,
        0u,
        COM_CONFIRMATION,
        &ComTxModeTrue[6],
        NULL_PTR,
        0u
    },
    {
        NULL_PTR,

        COM_TXPDU_COM_TAB_BodyCAN_0x2A5_FltSts,
        COM_DEFERRED,
        NULL_PTR,
        COM_PDU_NORMAL,
        1u,
        &ComTxIPduGroupsRef_7[0],
        0u,
        NULL_PTR,
        4u,
        &ComTxIPduSignalsRef_7[0],
        0u,
        NULL_PTR,
        PDUR_SRCPDU_COM_TAB_BodyCAN_0x2A5_FltSts,
        0u,
        8u,
        0u,
        56u,
        NULL_PTR,
        NULL_PTR,
        0u,
        COM_CONFIRMATION,
        &ComTxModeTrue[7],
        NULL_PTR,
        0u
    },
};
#define COM_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"
CONST(Com_RxSignalType, COM_CONST) Com_RxSignal[COM_RXSIGNAL_NUMBER]=
{
    {
        16u,
        24u,
        0u,
        0u,
        0u,
        3u,
        TotOdoAcrt_IPDU_COM_MC_BodyCAN_0x192,
        COM_INVALID_ACTION_NOTIFY,
        NULL_PTR,
        NULL_PTR,
        COM_TIMEOUT_ACTION_NONE,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        0u,
        0u,
        COM_UINT32,
        NULL_PTR,
        COM_UNUSED_UINT32,
        NULL_PTR,
        0u,
        0u,

        COM_UNUSED_UINT16,
        COM_UNUSED_UINT16
    },
    {
        24u,
        5u,
        0u,
        0u,
        1u,
        4u,
        DateTiDay_IPDU_COM_MC_BodyCAN_0x107,
        COM_INVALID_ACTION_NOTIFY,
        NULL_PTR,
        NULL_PTR,
        COM_TIMEOUT_ACTION_NONE,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        14u,
        0u,
        COM_UINT8,
        NULL_PTR,
        COM_UNUSED_UINT32,
        NULL_PTR,
        0u,
        0u,

        COM_UNUSED_UINT16,
        COM_UNUSED_UINT16
    },
    {
        32u,
        5u,
        0u,
        0u,
        2u,
        4u,
        DateTiHr_IPDU_COM_MC_BodyCAN_0x107,
        COM_INVALID_ACTION_NOTIFY,
        NULL_PTR,
        NULL_PTR,
        COM_TIMEOUT_ACTION_NONE,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        15u,
        0u,
        COM_UINT8,
        NULL_PTR,
        COM_UNUSED_UINT32,
        NULL_PTR,
        0u,
        0u,

        COM_UNUSED_UINT16,
        COM_UNUSED_UINT16
    },
    {
        56u,
        10u,
        0u,
        0u,
        3u,
        4u,
        DateTiMilsec_IPDU_COM_MC_BodyCAN_0x107,
        COM_INVALID_ACTION_NOTIFY,
        NULL_PTR,
        NULL_PTR,
        COM_TIMEOUT_ACTION_NONE,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        4u,
        0u,
        COM_UINT16,
        NULL_PTR,
        COM_UNUSED_UINT32,
        NULL_PTR,
        0u,
        0u,

        COM_UNUSED_UINT16,
        COM_UNUSED_UINT16
    },
    {
        40u,
        6u,
        0u,
        0u,
        4u,
        4u,
        DateTiMins_IPDU_COM_MC_BodyCAN_0x107,
        COM_INVALID_ACTION_NOTIFY,
        NULL_PTR,
        NULL_PTR,
        COM_TIMEOUT_ACTION_NONE,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        16u,
        0u,
        COM_UINT8,
        NULL_PTR,
        COM_UNUSED_UINT32,
        NULL_PTR,
        0u,
        0u,

        COM_UNUSED_UINT16,
        COM_UNUSED_UINT16
    },
    {
        16u,
        4u,
        0u,
        0u,
        5u,
        4u,
        DateTiMth_IPDU_COM_MC_BodyCAN_0x107,
        COM_INVALID_ACTION_NOTIFY,
        NULL_PTR,
        NULL_PTR,
        COM_TIMEOUT_ACTION_NONE,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        17u,
        0u,
        COM_UINT8,
        NULL_PTR,
        COM_UNUSED_UINT32,
        NULL_PTR,
        0u,
        0u,

        COM_UNUSED_UINT16,
        COM_UNUSED_UINT16
    },
    {
        50u,
        6u,
        0u,
        0u,
        6u,
        4u,
        DateTiSec_IPDU_COM_MC_BodyCAN_0x107,
        COM_INVALID_ACTION_NOTIFY,
        NULL_PTR,
        NULL_PTR,
        COM_TIMEOUT_ACTION_NONE,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        18u,
        0u,
        COM_UINT8,
        NULL_PTR,
        COM_UNUSED_UINT32,
        NULL_PTR,
        0u,
        0u,

        COM_UNUSED_UINT16,
        COM_UNUSED_UINT16
    },
    {
        8u,
        8u,
        0u,
        0u,
        7u,
        4u,
        DateTiYr_IPDU_COM_MC_BodyCAN_0x107,
        COM_INVALID_ACTION_NOTIFY,
        NULL_PTR,
        NULL_PTR,
        COM_TIMEOUT_ACTION_NONE,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        19u,
        0u,
        COM_UINT8,
        NULL_PTR,
        COM_UNUSED_UINT32,
        NULL_PTR,
        0u,
        0u,

        COM_UNUSED_UINT16,
        COM_UNUSED_UINT16
    },
    {
        61u,
        3u,
        0u,
        0u,
        8u,
        5u,
        CarModSts_IPDU_COM_MC_BodyCAN_0x100,
        COM_INVALID_ACTION_NOTIFY,
        NULL_PTR,
        NULL_PTR,
        COM_TIMEOUT_ACTION_NONE,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        20u,
        0u,
        COM_UINT8,
        NULL_PTR,
        COM_UNUSED_UINT32,
        NULL_PTR,
        0u,
        0u,

        COM_UNUSED_UINT16,
        COM_UNUSED_UINT16
    },
    {
        60u,
        1u,
        0u,
        0u,
        9u,
        5u,
        VCUPtRdyFlg_IPDU_COM_MC_BodyCAN_0x100,
        COM_INVALID_ACTION_NOTIFY,
        NULL_PTR,
        NULL_PTR,
        COM_TIMEOUT_ACTION_NONE,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        2u,
        0u,
        COM_BOOLEAN,
        NULL_PTR,
        COM_UNUSED_UINT32,
        NULL_PTR,
        0u,
        0u,

        COM_UNUSED_UINT16,
        COM_UNUSED_UINT16
    },
    {
        56u,
        16u,
        0u,
        0u,
        10u,
        7u,
        DrvrSeat_ResvFuncCmd_IPDU_COM_MC_TABFuncCtrl_BodyCAN_0x200,
        COM_INVALID_ACTION_NOTIFY,
        NULL_PTR,
        NULL_PTR,
        COM_TIMEOUT_ACTION_NONE,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        5u,
        0u,
        COM_UINT16,
        NULL_PTR,
        COM_UNUSED_UINT32,
        NULL_PTR,
        0u,
        0u,

        COM_UNUSED_UINT16,
        COM_UNUSED_UINT16
    },
    {
        12u,
        3u,
        0u,
        0u,
        11u,
        7u,
        DrvrSeat_MassgAreaStsCmd_IPDU_COM_MC_TABFuncCtrl_BodyCAN_0x200,
        COM_INVALID_ACTION_NOTIFY,
        NULL_PTR,
        NULL_PTR,
        COM_TIMEOUT_ACTION_NONE,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        21u,
        0u,
        COM_UINT8,
        NULL_PTR,
        COM_UNUSED_UINT32,
        NULL_PTR,
        0u,
        0u,

        COM_UNUSED_UINT16,
        COM_UNUSED_UINT16
    },
    {
        27u,
        3u,
        0u,
        0u,
        12u,
        7u,
        DrvrSeat_CushSptHrdnsStsCmd_IPDU_COM_MC_TABFuncCtrl_BodyCAN_0x200,
        COM_INVALID_ACTION_NOTIFY,
        NULL_PTR,
        NULL_PTR,
        COM_TIMEOUT_ACTION_NONE,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        22u,
        0u,
        COM_UINT8,
        NULL_PTR,
        COM_UNUSED_UINT32,
        NULL_PTR,
        0u,
        0u,

        COM_UNUSED_UINT16,
        COM_UNUSED_UINT16
    },
    {
        9u,
        3u,
        0u,
        0u,
        13u,
        7u,
        DrvrSeat_LumAdjCmd_IPDU_COM_MC_TABFuncCtrl_BodyCAN_0x200,
        COM_INVALID_ACTION_NOTIFY,
        NULL_PTR,
        NULL_PTR,
        COM_TIMEOUT_ACTION_NONE,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        23u,
        0u,
        COM_UINT8,
        NULL_PTR,
        COM_UNUSED_UINT32,
        NULL_PTR,
        0u,
        0u,

        COM_UNUSED_UINT16,
        COM_UNUSED_UINT16
    },
    {
        21u,
        4u,
        0u,
        0u,
        14u,
        7u,
        DrvrSeat_SideBlstrlLeAdjCmd_IPDU_COM_MC_TABFuncCtrl_BodyCAN_0x200,
        COM_INVALID_ACTION_NOTIFY,
        NULL_PTR,
        NULL_PTR,
        COM_TIMEOUT_ACTION_NONE,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        24u,
        0u,
        COM_UINT8,
        NULL_PTR,
        COM_UNUSED_UINT32,
        NULL_PTR,
        0u,
        0u,

        COM_UNUSED_UINT16,
        COM_UNUSED_UINT16
    },
    {
        17u,
        4u,
        0u,
        0u,
        15u,
        7u,
        DrvrSeat_SideBlstrlRiAdjCmd_IPDU_COM_MC_TABFuncCtrl_BodyCAN_0x200,
        COM_INVALID_ACTION_NOTIFY,
        NULL_PTR,
        NULL_PTR,
        COM_TIMEOUT_ACTION_NONE,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        25u,
        0u,
        COM_UINT8,
        NULL_PTR,
        COM_UNUSED_UINT32,
        NULL_PTR,
        0u,
        0u,

        COM_UNUSED_UINT16,
        COM_UNUSED_UINT16
    },
    {
        6u,
        2u,
        0u,
        0u,
        16u,
        7u,
        DrvrSeat_MassgStsCmd_IPDU_COM_MC_TABFuncCtrl_BodyCAN_0x200,
        COM_INVALID_ACTION_NOTIFY,
        NULL_PTR,
        NULL_PTR,
        COM_TIMEOUT_ACTION_NONE,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        26u,
        0u,
        COM_UINT8,
        NULL_PTR,
        COM_UNUSED_UINT32,
        NULL_PTR,
        0u,
        0u,

        COM_UNUSED_UINT16,
        COM_UNUSED_UINT16
    },
    {
        2u,
        4u,
        0u,
        0u,
        17u,
        7u,
        DrvrSeat_MassgModStsCmd_IPDU_COM_MC_TABFuncCtrl_BodyCAN_0x200,
        COM_INVALID_ACTION_NOTIFY,
        NULL_PTR,
        NULL_PTR,
        COM_TIMEOUT_ACTION_NONE,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        27u,
        0u,
        COM_UINT8,
        NULL_PTR,
        COM_UNUSED_UINT32,
        NULL_PTR,
        0u,
        0u,

        COM_UNUSED_UINT16,
        COM_UNUSED_UINT16
    },
    {
        15u,
        3u,
        0u,
        0u,
        18u,
        7u,
        DrvrSeat_MassgIntenStsCmd_IPDU_COM_MC_TABFuncCtrl_BodyCAN_0x200,
        COM_INVALID_ACTION_NOTIFY,
        NULL_PTR,
        NULL_PTR,
        COM_TIMEOUT_ACTION_NONE,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        28u,
        0u,
        COM_UINT8,
        NULL_PTR,
        COM_UNUSED_UINT32,
        NULL_PTR,
        0u,
        0u,

        COM_UNUSED_UINT16,
        COM_UNUSED_UINT16
    },
    {
        30u,
        3u,
        0u,
        0u,
        19u,
        7u,
        DrvrSeat_ActvBlstrAdjStsCmd_IPDU_COM_MC_TABFuncCtrl_BodyCAN_0x200,
        COM_INVALID_ACTION_NOTIFY,
        NULL_PTR,
        NULL_PTR,
        COM_TIMEOUT_ACTION_NONE,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        29u,
        0u,
        COM_UINT8,
        NULL_PTR,
        COM_UNUSED_UINT32,
        NULL_PTR,
        0u,
        0u,

        COM_UNUSED_UINT16,
        COM_UNUSED_UINT16
    },
    {
        1u,
        7u,
        0u,
        0u,
        20u,
        8u,
        CurAtmPSoa_IPDU_COM_MC_BodyCAN_0x1D4,
        COM_INVALID_ACTION_NOTIFY,
        NULL_PTR,
        NULL_PTR,
        COM_TIMEOUT_ACTION_NONE,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        30u,
        0u,
        COM_UINT8,
        NULL_PTR,
        COM_UNUSED_UINT32,
        NULL_PTR,
        0u,
        0u,

        COM_UNUSED_UINT16,
        COM_UNUSED_UINT16
    },
    {
        0u,
        1u,
        0u,
        0u,
        21u,
        8u,
        CurAtmPValSoa_IPDU_COM_MC_BodyCAN_0x1D4,
        COM_INVALID_ACTION_NOTIFY,
        NULL_PTR,
        NULL_PTR,
        COM_TIMEOUT_ACTION_NONE,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        3u,
        0u,
        COM_BOOLEAN,
        NULL_PTR,
        COM_UNUSED_UINT32,
        NULL_PTR,
        0u,
        0u,

        COM_UNUSED_UINT16,
        COM_UNUSED_UINT16
    },
    {
        8u,
        16u,
        0u,
        0u,
        22u,
        9u,
        VehSpd_IPDU_COM_MC_BodyCAN_0x106,
        COM_INVALID_ACTION_NOTIFY,
        NULL_PTR,
        NULL_PTR,
        COM_TIMEOUT_ACTION_NONE,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        6u,
        0u,
        COM_UINT16,
        NULL_PTR,
        COM_UNUSED_UINT32,
        NULL_PTR,
        0u,
        0u,

        COM_UNUSED_UINT16,
        COM_UNUSED_UINT16
    },
    {
        23u,
        1u,
        0u,
        0u,
        23u,
        9u,
        VehSpdVld_IPDU_COM_MC_BodyCAN_0x106,
        COM_INVALID_ACTION_NOTIFY,
        NULL_PTR,
        NULL_PTR,
        COM_TIMEOUT_ACTION_NONE,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        4u,
        0u,
        COM_BOOLEAN,
        NULL_PTR,
        COM_UNUSED_UINT32,
        NULL_PTR,
        0u,
        0u,

        COM_UNUSED_UINT16,
        COM_UNUSED_UINT16
    },
    {
        25u,
        15u,
        0u,
        0u,
        24u,
        10u,
        PinionSteerAgl_IPDU_COM_MC_BodyCAN_0x10B,
        COM_INVALID_ACTION_NOTIFY,
        NULL_PTR,
        NULL_PTR,
        COM_TIMEOUT_ACTION_NONE,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        7u,
        0u,
        COM_SINT16,
        NULL_PTR,
        COM_UNUSED_UINT32,
        NULL_PTR,
        0u,
        0u,

        COM_UNUSED_UINT16,
        COM_UNUSED_UINT16
    },
    {
        43u,
        1u,
        0u,
        0u,
        25u,
        10u,
        PinionSteerAglVld_IPDU_COM_MC_BodyCAN_0x10B,
        COM_INVALID_ACTION_NOTIFY,
        NULL_PTR,
        NULL_PTR,
        COM_TIMEOUT_ACTION_NONE,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        5u,
        0u,
        COM_BOOLEAN,
        NULL_PTR,
        COM_UNUSED_UINT32,
        NULL_PTR,
        0u,
        0u,

        COM_UNUSED_UINT16,
        COM_UNUSED_UINT16
    },
};
#define COM_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"
CONST(Com_TxSignalType, COM_CONST) Com_TxSignal[COM_TXSIGNAL_NUMBER]=
{
    {
        40u,
        16u,
        NULL_PTR,
        DrvrSeat_HWVerNum_IPDU_COM_TAB_BodyCAN_0x2A7_Info,
        FALSE,
        NULL_PTR,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        8u,
        0u,
        COM_UINT16,
        0u,
        0u,
        NULL_PTR,
        COM_PENDING,
        COM_UNUSED_UINT32,
        NULL_PTR,
        0u,
        0u
    },
    {
        24u,
        16u,
        NULL_PTR,
        DrvrSeat_SWVerNum_IPDU_COM_TAB_BodyCAN_0x2A7_Info,
        FALSE,
        NULL_PTR,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        9u,
        0u,
        COM_UINT16,
        0u,
        0u,
        NULL_PTR,
        COM_PENDING,
        COM_UNUSED_UINT32,
        NULL_PTR,
        0u,
        0u
    },
    {
        8u,
        16u,
        NULL_PTR,
        DrvrSeat_BTVerNum_IPDU_COM_TAB_BodyCAN_0x2A7_Info,
        FALSE,
        NULL_PTR,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        10u,
        0u,
        COM_UINT16,
        0u,
        0u,
        NULL_PTR,
        COM_PENDING,
        COM_UNUSED_UINT32,
        NULL_PTR,
        0u,
        0u
    },
    {
        16u,
        12u,
        NULL_PTR,
        DrvrSeat_X11PSnsrPrm_IPDU_COM_TAB_BodyCAN_0x2A4_SnsrPrm,
        FALSE,
        NULL_PTR,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        11u,
        0u,
        COM_UINT16,
        0u,
        1u,
        NULL_PTR,
        COM_PENDING,
        COM_UNUSED_UINT32,
        NULL_PTR,
        0u,
        0u
    },
    {
        12u,
        12u,
        NULL_PTR,
        DrvrSeat_X10PSnsrPrm_IPDU_COM_TAB_BodyCAN_0x2A4_SnsrPrm,
        FALSE,
        NULL_PTR,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        12u,
        0u,
        COM_UINT16,
        0u,
        1u,
        NULL_PTR,
        COM_PENDING,
        COM_UNUSED_UINT32,
        NULL_PTR,
        0u,
        0u
    },
    {
        60u,
        12u,
        NULL_PTR,
        DrvrSeat_X9PSnsrPrm_IPDU_COM_TAB_BodyCAN_0x2A3_SnsrPrm,
        FALSE,
        NULL_PTR,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        13u,
        0u,
        COM_UINT16,
        0u,
        2u,
        NULL_PTR,
        COM_PENDING,
        COM_UNUSED_UINT32,
        NULL_PTR,
        0u,
        0u
    },
    {
        40u,
        12u,
        NULL_PTR,
        DrvrSeat_X8PSnsrPrm_IPDU_COM_TAB_BodyCAN_0x2A3_SnsrPrm,
        FALSE,
        NULL_PTR,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        14u,
        0u,
        COM_UINT16,
        0u,
        2u,
        NULL_PTR,
        COM_PENDING,
        COM_UNUSED_UINT32,
        NULL_PTR,
        0u,
        0u
    },
    {
        36u,
        12u,
        NULL_PTR,
        DrvrSeat_X7PSnsrPrm_IPDU_COM_TAB_BodyCAN_0x2A3_SnsrPrm,
        FALSE,
        NULL_PTR,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        15u,
        0u,
        COM_UINT16,
        0u,
        2u,
        NULL_PTR,
        COM_PENDING,
        COM_UNUSED_UINT32,
        NULL_PTR,
        0u,
        0u
    },
    {
        16u,
        12u,
        NULL_PTR,
        DrvrSeat_X6PSnsrPrm_IPDU_COM_TAB_BodyCAN_0x2A3_SnsrPrm,
        FALSE,
        NULL_PTR,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        16u,
        0u,
        COM_UINT16,
        0u,
        2u,
        NULL_PTR,
        COM_PENDING,
        COM_UNUSED_UINT32,
        NULL_PTR,
        0u,
        0u
    },
    {
        12u,
        12u,
        NULL_PTR,
        DrvrSeat_X5PSnsrPrm_IPDU_COM_TAB_BodyCAN_0x2A3_SnsrPrm,
        FALSE,
        NULL_PTR,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        17u,
        0u,
        COM_UINT16,
        0u,
        2u,
        NULL_PTR,
        COM_PENDING,
        COM_UNUSED_UINT32,
        NULL_PTR,
        0u,
        0u
    },
    {
        0u,
        8u,
        NULL_PTR,
        DrvrSeat_InpUPrm_IPDU_COM_TAB_BodyCAN_0x2A6_PrmFr,
        FALSE,
        NULL_PTR,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        31u,
        0u,
        COM_UINT8,
        0u,
        3u,
        NULL_PTR,
        COM_PENDING,
        COM_UNUSED_UINT32,
        NULL_PTR,
        0u,
        0u
    },
    {
        8u,
        8u,
        NULL_PTR,
        DrvrSeat_NtcTPrm_IPDU_COM_TAB_BodyCAN_0x2A6_PrmFr,
        FALSE,
        NULL_PTR,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        32u,
        0u,
        COM_UINT8,
        0u,
        3u,
        NULL_PTR,
        COM_PENDING,
        COM_UNUSED_UINT32,
        NULL_PTR,
        0u,
        0u
    },
    {
        16u,
        8u,
        NULL_PTR,
        DrvrSeat_HSDUPrm_IPDU_COM_TAB_BodyCAN_0x2A6_PrmFr,
        FALSE,
        NULL_PTR,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        33u,
        0u,
        COM_UINT8,
        0u,
        3u,
        NULL_PTR,
        COM_PENDING,
        COM_UNUSED_UINT32,
        NULL_PTR,
        0u,
        0u
    },
    {
        24u,
        8u,
        NULL_PTR,
        DrvrSeat_HSDCurPrm_IPDU_COM_TAB_BodyCAN_0x2A6_PrmFr,
        FALSE,
        NULL_PTR,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        34u,
        0u,
        COM_UINT8,
        0u,
        3u,
        NULL_PTR,
        COM_PENDING,
        COM_UNUSED_UINT32,
        NULL_PTR,
        0u,
        0u
    },
    {
        56u,
        16u,
        NULL_PTR,
        DrvrSeat_ResvFuncSts_IPDU_COM_TAB_BodyCAN_0x2A0_FuncSts,
        FALSE,
        NULL_PTR,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        18u,
        0u,
        COM_UINT16,
        0u,
        4u,
        NULL_PTR,
        COM_PENDING,
        COM_UNUSED_UINT32,
        NULL_PTR,
        0u,
        0u
    },
    {
        11u,
        3u,
        NULL_PTR,
        DrvrSeat_MassgAreaSts_IPDU_COM_TAB_BodyCAN_0x2A0_FuncSts,
        FALSE,
        NULL_PTR,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        35u,
        0u,
        COM_UINT8,
        0u,
        4u,
        NULL_PTR,
        COM_PENDING,
        COM_UNUSED_UINT32,
        NULL_PTR,
        0u,
        0u
    },
    {
        26u,
        3u,
        NULL_PTR,
        DrvrSeat_CushSptHrdnsSts_IPDU_COM_TAB_BodyCAN_0x2A0_FuncSts,
        FALSE,
        NULL_PTR,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        36u,
        0u,
        COM_UINT8,
        0u,
        4u,
        NULL_PTR,
        COM_PENDING,
        COM_UNUSED_UINT32,
        NULL_PTR,
        0u,
        0u
    },
    {
        16u,
        4u,
        NULL_PTR,
        DrvrSeat_SideBlstrlRiAdjSts_IPDU_COM_TAB_BodyCAN_0x2A0_FuncSts,
        FALSE,
        NULL_PTR,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        37u,
        0u,
        COM_UINT8,
        0u,
        4u,
        NULL_PTR,
        COM_PENDING,
        COM_UNUSED_UINT32,
        NULL_PTR,
        0u,
        0u
    },
    {
        20u,
        4u,
        NULL_PTR,
        DrvrSeat_SideBlstrlLeAdjSts_IPDU_COM_TAB_BodyCAN_0x2A0_FuncSts,
        FALSE,
        NULL_PTR,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        38u,
        0u,
        COM_UINT8,
        0u,
        4u,
        NULL_PTR,
        COM_PENDING,
        COM_UNUSED_UINT32,
        NULL_PTR,
        0u,
        0u
    },
    {
        6u,
        2u,
        NULL_PTR,
        DrvrSeat_MassgSts_IPDU_COM_TAB_BodyCAN_0x2A0_FuncSts,
        FALSE,
        NULL_PTR,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        39u,
        0u,
        COM_UINT8,
        0u,
        4u,
        NULL_PTR,
        COM_PENDING,
        COM_UNUSED_UINT32,
        NULL_PTR,
        0u,
        0u
    },
    {
        2u,
        4u,
        NULL_PTR,
        DrvrSeat_MassgModSts_IPDU_COM_TAB_BodyCAN_0x2A0_FuncSts,
        FALSE,
        NULL_PTR,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        40u,
        0u,
        COM_UINT8,
        0u,
        4u,
        NULL_PTR,
        COM_PENDING,
        COM_UNUSED_UINT32,
        NULL_PTR,
        0u,
        0u
    },
    {
        14u,
        4u,
        NULL_PTR,
        DrvrSeat_MassgIntenSts_IPDU_COM_TAB_BodyCAN_0x2A0_FuncSts,
        FALSE,
        NULL_PTR,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        41u,
        0u,
        COM_UINT8,
        0u,
        4u,
        NULL_PTR,
        COM_PENDING,
        COM_UNUSED_UINT32,
        NULL_PTR,
        0u,
        0u
    },
    {
        8u,
        3u,
        NULL_PTR,
        DrvrSeat_LumAdjSts_IPDU_COM_TAB_BodyCAN_0x2A0_FuncSts,
        FALSE,
        NULL_PTR,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        42u,
        0u,
        COM_UINT8,
        0u,
        4u,
        NULL_PTR,
        COM_PENDING,
        COM_UNUSED_UINT32,
        NULL_PTR,
        0u,
        0u
    },
    {
        29u,
        3u,
        NULL_PTR,
        DrvrSeat_ActvBlstrAdjSts_IPDU_COM_TAB_BodyCAN_0x2A0_FuncSts,
        FALSE,
        NULL_PTR,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        43u,
        0u,
        COM_UINT8,
        0u,
        4u,
        NULL_PTR,
        COM_PENDING,
        COM_UNUSED_UINT32,
        NULL_PTR,
        0u,
        0u
    },
    {
        5u,
        3u,
        NULL_PTR,
        DrvrSeat_TempSts_IPDU_COM_TAB_BodyCAN_0x2A1_FuncSts,
        FALSE,
        NULL_PTR,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        44u,
        0u,
        COM_UINT8,
        0u,
        5u,
        NULL_PTR,
        COM_PENDING,
        COM_UNUSED_UINT32,
        NULL_PTR,
        0u,
        0u
    },
    {
        3u,
        2u,
        NULL_PTR,
        DrvrSeat_MainVlvSts_IPDU_COM_TAB_BodyCAN_0x2A1_FuncSts,
        FALSE,
        NULL_PTR,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        45u,
        0u,
        COM_UINT8,
        0u,
        5u,
        NULL_PTR,
        COM_PENDING,
        COM_UNUSED_UINT32,
        NULL_PTR,
        0u,
        0u
    },
    {
        0u,
        3u,
        NULL_PTR,
        DrvrSeat_InpUSts_IPDU_COM_TAB_BodyCAN_0x2A1_FuncSts,
        FALSE,
        NULL_PTR,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        46u,
        0u,
        COM_UINT8,
        0u,
        5u,
        NULL_PTR,
        COM_PENDING,
        COM_UNUSED_UINT32,
        NULL_PTR,
        0u,
        0u
    },
    {
        60u,
        12u,
        NULL_PTR,
        DrvrSeat_X4PSnsrPrm_IPDU_COM_TAB_BodyCAN_0x2A2_SnsrPrm,
        FALSE,
        NULL_PTR,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        19u,
        0u,
        COM_UINT16,
        0u,
        6u,
        NULL_PTR,
        COM_PENDING,
        COM_UNUSED_UINT32,
        NULL_PTR,
        0u,
        0u
    },
    {
        40u,
        12u,
        NULL_PTR,
        DrvrSeat_X3PSnsrPrm_IPDU_COM_TAB_BodyCAN_0x2A2_SnsrPrm,
        FALSE,
        NULL_PTR,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        20u,
        0u,
        COM_UINT16,
        0u,
        6u,
        NULL_PTR,
        COM_PENDING,
        COM_UNUSED_UINT32,
        NULL_PTR,
        0u,
        0u
    },
    {
        36u,
        12u,
        NULL_PTR,
        DrvrSeat_RiSideBlstrPSnsrPrm_IPDU_COM_TAB_BodyCAN_0x2A2_SnsrPrm,
        FALSE,
        NULL_PTR,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        21u,
        0u,
        COM_UINT16,
        0u,
        6u,
        NULL_PTR,
        COM_PENDING,
        COM_UNUSED_UINT32,
        NULL_PTR,
        0u,
        0u
    },
    {
        12u,
        12u,
        NULL_PTR,
        DrvrSeat_MainPSnsrPrm_IPDU_COM_TAB_BodyCAN_0x2A2_SnsrPrm,
        FALSE,
        NULL_PTR,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        22u,
        0u,
        COM_UINT16,
        0u,
        6u,
        NULL_PTR,
        COM_PENDING,
        COM_UNUSED_UINT32,
        NULL_PTR,
        0u,
        0u
    },
    {
        16u,
        12u,
        NULL_PTR,
        DrvrSeat_LeSideBlstrPSnsrPrm_IPDU_COM_TAB_BodyCAN_0x2A2_SnsrPrm,
        FALSE,
        NULL_PTR,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        23u,
        0u,
        COM_UINT16,
        0u,
        6u,
        NULL_PTR,
        COM_PENDING,
        COM_UNUSED_UINT32,
        NULL_PTR,
        0u,
        0u
    },
    {
        0u,
        2u,
        NULL_PTR,
        DrvrSeat_MassgVlvFltSts_IPDU_COM_TAB_BodyCAN_0x2A5_FltSts,
        FALSE,
        NULL_PTR,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        47u,
        0u,
        COM_UINT8,
        0u,
        7u,
        NULL_PTR,
        COM_PENDING,
        COM_UNUSED_UINT32,
        NULL_PTR,
        0u,
        0u
    },
    {
        4u,
        2u,
        NULL_PTR,
        DrvrSeat_MainVlvFltSts_IPDU_COM_TAB_BodyCAN_0x2A5_FltSts,
        FALSE,
        NULL_PTR,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        48u,
        0u,
        COM_UINT8,
        0u,
        7u,
        NULL_PTR,
        COM_PENDING,
        COM_UNUSED_UINT32,
        NULL_PTR,
        0u,
        0u
    },
    {
        2u,
        2u,
        NULL_PTR,
        DrvrSeat_LumSideBlstrVlvFltSts_IPDU_COM_TAB_BodyCAN_0x2A5_FltSts,
        FALSE,
        NULL_PTR,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        49u,
        0u,
        COM_UINT8,
        0u,
        7u,
        NULL_PTR,
        COM_PENDING,
        COM_UNUSED_UINT32,
        NULL_PTR,
        0u,
        0u
    },
    {
        6u,
        2u,
        NULL_PTR,
        DrvrSeat_HSDFltSts_IPDU_COM_TAB_BodyCAN_0x2A5_FltSts,
        FALSE,
        NULL_PTR,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        50u,
        0u,
        COM_UINT8,
        0u,
        7u,
        NULL_PTR,
        COM_PENDING,
        COM_UNUSED_UINT32,
        NULL_PTR,
        0u,
        0u
    },
};
#define COM_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"
CONST(Com_SignalIdType, COM_CONST) ComRxGroupSignalId_0[6]={0u,1u,2u,3u,4u,5u};
CONST(Com_SignalIdType, COM_CONST) ComRxGroupSignalId_1[3]={6u,7u,8u};
CONST(Com_SignalIdType, COM_CONST) ComRxGroupSignalId_2[3]={9u,10u,11u};
CONST(Com_SignalIdType, COM_CONST) ComRxGroupSignalId_3[4]={12u,13u,14u,15u};
CONST(Com_SignalIdType, COM_CONST) ComRxGroupSignalId_4[4]={16u,17u,18u,19u};
#define COM_STOP_SEC_PBCONFIG_DATA_16
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"
CONST(Com_RxSignalGroupType, COM_CONST) Com_RxSignalGroup[COM_RXSIGNALGROUP_NUMBER]=
{
    {
        COM_INVALID_ACTION_NOTIFY,
        0u,
        0u,
        LatAccrYawRateSigGrp_IPDU_COM_MC_BodyCAN_0x1AA,
        NULL_PTR,
        NULL_PTR,
        COM_TIMEOUT_ACTION_NONE,
        NULL_PTR,
        NULL_PTR,
        COM_UNUSED_UINT32,
        6u,
        &ComRxGroupSignalId_0[0],
        1u,
        26u,
        COM_UNUSED_UINT16,
    },
    {
        COM_INVALID_ACTION_NOTIFY,
        0u,
        0u,
        BattSocRawSigGrp_IPDU_COM_MC_BodyCAN_0x143,
        NULL_PTR,
        NULL_PTR,
        COM_TIMEOUT_ACTION_NONE,
        NULL_PTR,
        NULL_PTR,
        COM_UNUSED_UINT32,
        3u,
        &ComRxGroupSignalId_1[0],
        2u,
        27u,
        COM_UNUSED_UINT16,
    },
    {
        COM_INVALID_ACTION_NOTIFY,
        0u,
        0u,
        BattURawSigGrp_IPDU_COM_MC_BodyCAN_0x143,
        NULL_PTR,
        NULL_PTR,
        COM_TIMEOUT_ACTION_NONE,
        NULL_PTR,
        NULL_PTR,
        COM_UNUSED_UINT32,
        3u,
        &ComRxGroupSignalId_2[0],
        2u,
        28u,
        COM_UNUSED_UINT16,
    },
    {
        COM_INVALID_ACTION_NOTIFY,
        0u,
        0u,
        PwrModSigGrp_IPDU_COM_MC_BodyCAN_0x103,
        NULL_PTR,
        NULL_PTR,
        COM_TIMEOUT_ACTION_NONE,
        NULL_PTR,
        NULL_PTR,
        COM_UNUSED_UINT32,
        4u,
        &ComRxGroupSignalId_3[0],
        6u,
        29u,
        COM_UNUSED_UINT16,
    },
    {
        COM_INVALID_ACTION_NOTIFY,
        0u,
        0u,
        VCUActGearSigGrp_IPDU_COM_MC_BodyCAN_0x103,
        NULL_PTR,
        NULL_PTR,
        COM_TIMEOUT_ACTION_NONE,
        NULL_PTR,
        NULL_PTR,
        COM_UNUSED_UINT32,
        4u,
        &ComRxGroupSignalId_4[0],
        6u,
        30u,
        COM_UNUSED_UINT16,
    },
};
#define COM_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"
CONST(Com_RxGroupSignalType, COM_CONST) Com_RxGroupSignal[COM_RXGROUPSIGNAL_NUMBER]=
{
    {
        24u,
        16u,
        LatAccrYawRateSigGrp_IPDU_COM_MC_BodyCAN_0x1AA_LatAccr_IPDU_COM_MC_BodyCAN_0x1AA,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        0u,
        0u,
        COM_UINT16,
        NULL_PTR,
        LatAccrYawRateSigGrp_IPDU_COM_MC_BodyCAN_0x1AA,
        0u,
        0u,
        COM_UNUSED_UINT16,
    },
    {
        48u,
        2u,
        LatAccrYawRateSigGrp_IPDU_COM_MC_BodyCAN_0x1AA_LatAccrSt_IPDU_COM_MC_BodyCAN_0x1AA,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        0u,
        0u,
        COM_UINT8,
        NULL_PTR,
        LatAccrYawRateSigGrp_IPDU_COM_MC_BodyCAN_0x1AA,
        0u,
        0u,
        COM_UNUSED_UINT16,
    },
    {
        0u,
        8u,
        LatAccrYawRateSigGrp_IPDU_COM_MC_BodyCAN_0x1AA_LatAccrYawRateSigGrpChks_IPDU_COM_MC_BodyCAN_0x1AA,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        1u,
        0u,
        COM_UINT8,
        NULL_PTR,
        LatAccrYawRateSigGrp_IPDU_COM_MC_BodyCAN_0x1AA,
        0u,
        0u,
        COM_UNUSED_UINT16,
    },
    {
        8u,
        4u,
        LatAccrYawRateSigGrp_IPDU_COM_MC_BodyCAN_0x1AA_LatAccrYawRateSigGrpCntr_IPDU_COM_MC_BodyCAN_0x1AA,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        2u,
        0u,
        COM_UINT8,
        NULL_PTR,
        LatAccrYawRateSigGrp_IPDU_COM_MC_BodyCAN_0x1AA,
        0u,
        0u,
        COM_UNUSED_UINT16,
    },
    {
        40u,
        16u,
        LatAccrYawRateSigGrp_IPDU_COM_MC_BodyCAN_0x1AA_YawRate_IPDU_COM_MC_BodyCAN_0x1AA,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        1u,
        0u,
        COM_UINT16,
        NULL_PTR,
        LatAccrYawRateSigGrp_IPDU_COM_MC_BodyCAN_0x1AA,
        0u,
        0u,
        COM_UNUSED_UINT16,
    },
    {
        50u,
        2u,
        LatAccrYawRateSigGrp_IPDU_COM_MC_BodyCAN_0x1AA_YawRateSnsrSt_IPDU_COM_MC_BodyCAN_0x1AA,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        3u,
        0u,
        COM_UINT8,
        NULL_PTR,
        LatAccrYawRateSigGrp_IPDU_COM_MC_BodyCAN_0x1AA,
        0u,
        0u,
        COM_UNUSED_UINT16,
    },
    {
        56u,
        10u,
        BattSocRawSigGrp_IPDU_COM_MC_BodyCAN_0x143_BattSocRaw_IPDU_COM_MC_BodyCAN_0x143,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        2u,
        0u,
        COM_UINT16,
        NULL_PTR,
        BattSocRawSigGrp_IPDU_COM_MC_BodyCAN_0x143,
        0u,
        0u,
        COM_UNUSED_UINT16,
    },
    {
        32u,
        8u,
        BattSocRawSigGrp_IPDU_COM_MC_BodyCAN_0x143_BattSocRawSigGrpChks_IPDU_COM_MC_BodyCAN_0x143,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        4u,
        0u,
        COM_UINT8,
        NULL_PTR,
        BattSocRawSigGrp_IPDU_COM_MC_BodyCAN_0x143,
        0u,
        0u,
        COM_UNUSED_UINT16,
    },
    {
        40u,
        4u,
        BattSocRawSigGrp_IPDU_COM_MC_BodyCAN_0x143_BattSocRawSigGrpCntr_IPDU_COM_MC_BodyCAN_0x143,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        5u,
        0u,
        COM_UINT8,
        NULL_PTR,
        BattSocRawSigGrp_IPDU_COM_MC_BodyCAN_0x143,
        0u,
        0u,
        COM_UNUSED_UINT16,
    },
    {
        25u,
        15u,
        BattURawSigGrp_IPDU_COM_MC_BodyCAN_0x143_BattURaw_IPDU_COM_MC_BodyCAN_0x143,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        3u,
        0u,
        COM_UINT16,
        NULL_PTR,
        BattURawSigGrp_IPDU_COM_MC_BodyCAN_0x143,
        0u,
        0u,
        COM_UNUSED_UINT16,
    },
    {
        0u,
        8u,
        BattURawSigGrp_IPDU_COM_MC_BodyCAN_0x143_BattURawSigGrpChks_IPDU_COM_MC_BodyCAN_0x143,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        6u,
        0u,
        COM_UINT8,
        NULL_PTR,
        BattURawSigGrp_IPDU_COM_MC_BodyCAN_0x143,
        0u,
        0u,
        COM_UNUSED_UINT16,
    },
    {
        8u,
        4u,
        BattURawSigGrp_IPDU_COM_MC_BodyCAN_0x143_BattURawSigGrpCntr_IPDU_COM_MC_BodyCAN_0x143,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        7u,
        0u,
        COM_UINT8,
        NULL_PTR,
        BattURawSigGrp_IPDU_COM_MC_BodyCAN_0x143,
        0u,
        0u,
        COM_UNUSED_UINT16,
    },
    {
        0u,
        8u,
        PwrModSigGrp_IPDU_COM_MC_BodyCAN_0x103_PwrModSigGrpChks_IPDU_COM_MC_BodyCAN_0x103,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        8u,
        0u,
        COM_UINT8,
        NULL_PTR,
        PwrModSigGrp_IPDU_COM_MC_BodyCAN_0x103,
        0u,
        0u,
        COM_UNUSED_UINT16,
    },
    {
        8u,
        4u,
        PwrModSigGrp_IPDU_COM_MC_BodyCAN_0x103_PwrModSigGrpCntr_IPDU_COM_MC_BodyCAN_0x103,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        9u,
        0u,
        COM_UINT8,
        NULL_PTR,
        PwrModSigGrp_IPDU_COM_MC_BodyCAN_0x103,
        0u,
        0u,
        COM_UNUSED_UINT16,
    },
    {
        21u,
        3u,
        PwrModSigGrp_IPDU_COM_MC_BodyCAN_0x103_PwrModSts_IPDU_COM_MC_BodyCAN_0x103,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        10u,
        0u,
        COM_UINT8,
        NULL_PTR,
        PwrModSigGrp_IPDU_COM_MC_BodyCAN_0x103,
        0u,
        0u,
        COM_UNUSED_UINT16,
    },
    {
        20u,
        1u,
        PwrModSigGrp_IPDU_COM_MC_BodyCAN_0x103_PwrModVld_IPDU_COM_MC_BodyCAN_0x103,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        0u,
        0u,
        COM_BOOLEAN,
        NULL_PTR,
        PwrModSigGrp_IPDU_COM_MC_BodyCAN_0x103,
        0u,
        0u,
        COM_UNUSED_UINT16,
    },
    {
        53u,
        3u,
        VCUActGearSigGrp_IPDU_COM_MC_BodyCAN_0x103_VCUActGearLvr_IPDU_COM_MC_BodyCAN_0x103,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        11u,
        0u,
        COM_UINT8,
        NULL_PTR,
        VCUActGearSigGrp_IPDU_COM_MC_BodyCAN_0x103,
        0u,
        0u,
        COM_UNUSED_UINT16,
    },
    {
        52u,
        1u,
        VCUActGearSigGrp_IPDU_COM_MC_BodyCAN_0x103_VCUActGearLvrVld_IPDU_COM_MC_BodyCAN_0x103,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        1u,
        0u,
        COM_BOOLEAN,
        NULL_PTR,
        VCUActGearSigGrp_IPDU_COM_MC_BodyCAN_0x103,
        0u,
        0u,
        COM_UNUSED_UINT16,
    },
    {
        24u,
        8u,
        VCUActGearSigGrp_IPDU_COM_MC_BodyCAN_0x103_VCUActGearSigGrpChks_IPDU_COM_MC_BodyCAN_0x103,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        12u,
        0u,
        COM_UINT8,
        NULL_PTR,
        VCUActGearSigGrp_IPDU_COM_MC_BodyCAN_0x103,
        0u,
        0u,
        COM_UNUSED_UINT16,
    },
    {
        32u,
        4u,
        VCUActGearSigGrp_IPDU_COM_MC_BodyCAN_0x103_VCUActGearSigGrpCntr_IPDU_COM_MC_BodyCAN_0x103,
        COM_UNUSED_UINT16,
        COM_BIG_ENDIAN,
        13u,
        0u,
        COM_UINT8,
        NULL_PTR,
        VCUActGearSigGrp_IPDU_COM_MC_BodyCAN_0x103,
        0u,
        0u,
        COM_UNUSED_UINT16,
    },
};
#define COM_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"

#define COM_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"
CONST(Com_ConfigType, COM_CONST_PBCFG) Com_PBConfigData =
{
    &Com_RxIPdu[0],
    &Com_TxIPdu[0],
    &Com_RxSignal[0],
    &Com_TxSignal[0],
    &Com_RxSignalGroup[0],
    NULL_PTR,
    &Com_RxGroupSignal[0],
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR
};
#define COM_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "Com_MemMap.h"

