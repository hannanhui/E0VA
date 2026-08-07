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
**  FILENAME    : CanNm_Cfg.c                                                 **
**                                                                            **
**  Created on  : 2025/05/09 15:24:12                                         **
**  Author      : wanglili                                                    **
**  Vendor      :                                                             **
**  DESCRIPTION : Configuration data for CanNm                                **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "CanNm.h"
#include "PduR_Cfg.h"
#include "CanIf_Cfg.h"
#include "ComM_Cfg.h"
/*******************************************************************************
**                       Version  Check                                       **
*******************************************************************************/
/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/
/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
/*******************************************************************************
**                      Global Variable Definitions                          **
*******************************************************************************/
#define CANNM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanNm_MemMap.h"

static CONST(CanNm_RxPduType, CANNM_CONST) CanNm_RxPduData[CANNM_RX_PDU_NUMBER_MAX] =
{
        {
            0u,           /* RxPduId */
        },
};

static CONST(CanNm_TxPduType, CANNM_CONST)  CanNm_TxPduData[CANNM_TX_PDU_NUMBER_MAX] =
{
        {
            0u,           /* TxConfirmationPduId*/
            CANIF_TXPDU_TABBodyNMFr,      /* CanNmTxPduRef */
            FALSE        /*TxPduIsTriggerTrans*/
        },
};

static CONST(CanNm_ChannelConfigType, CANNM_CONST)
CanNm_ChannelCfgData[CANNM_NUMBER_OF_CHANNEL]=
{
    {
        TRUE,    /* CanNmActiveWakeupBitEnabled */
        FALSE,    /* CanNmAllNmMessagesKeepAwake */
        20u,        /* CanNmImmediateNmCycleTime */
        20u,        /* CanNmImmediateNmTransmissions */
        5u,        /* CanNmMsgCycleOffset */
        1000u,        /* CanNmMsgCycleTime */
        0u,        /* CanNmMsgTimeoutTime */
        54u,        /* CanNmNodeId */
        CANNM_PDU_BYTE_1,    /* CanNmPduCbvPosition */
        CANNM_PDU_BYTE_0,    /* CanNmPduNidPosition */
        TRUE,            /* CanNmPnEnabled */
        FALSE,            /* CanNmPnEraCalcEnabled */
        TRUE,            /* CanNmPnHandleMultipleNetworkRequests */
        1000u,                    /* CanNmRepeatMessageTime */
        TRUE,                /* CanNmRetryFirstMessageRequest */
        FALSE,    /* CanNmStayInPbsEnabled */
        3000u,                    /* CanNmTimeoutTime */
        4000u,                    /* CanNmWaitBusSleepTime */
        Channel_CanController_CAN0,    /* CanNmComMNetworkHandleRef */
        &CanNm_RxPduData[0],    /* CanNmRxPdu */
        1u,              /* RxPduNum */
        &CanNm_TxPduData[0],   /* CanNmTxPdu */
        NULL_PTR,   /* CanNmUserDataTxPdu */
    },

};

static CONST(CanNm_PnFilterMaskByteType, CANNM_CONST) CanNm_PnFilterMaskByteData[6]=
{
    {
        0x0u,
        0x41
    },
    {
        0x1u,
        0x20
    },
    {
        0x2u,
        0x20
    },
    {
        0x3u,
        0x0
    },
    {
        0x4u,
        0x0
    },
    {
        0x5u,
        0x0
    },
};
static CONST(CanNm_PnInfoType, CANNM_CONST) CanNm_PnInfoData =
{
    6u,        /* CanNmPnInfoLength */
    2u,        /* CanNmPnInfoOffset */
    6u,                          /* CanNmPnFilterMaskByteNum */
    CanNm_PnFilterMaskByteData  /* CanNmPnFilterMaskByte */
};

CONST(CanNm_ConfigType, CANNM_CONST) CanNm_Config =
{
    0xau,    /* CanNmMainFunctionPeriod */
    2950u,    /* CanNmPnResetTime */
    PDUR_SRCPDU_CanNM_TABBodyNMEira,    /*CanNmPnEiraRxNSduRef*/
    CanNm_ChannelCfgData,       /* CanNmChannelConfig */
    &CanNm_PnInfoData           /* CanNmPnInfo */

};
#define CANNM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanNm_MemMap.h"
/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/

