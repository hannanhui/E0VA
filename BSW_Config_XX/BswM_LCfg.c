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
**  FILENAME    : BswM_LCfg.c                                                  **
**                                                                            **
**  Created on  : 2025/02/07 16:03:34                                           **
**  Author      : qinchun.yang                                                **
**  Vendor      :                                                             **
**  DESCRIPTION :                                                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*  <VERSION>    <DATE>        <AUTHOR>        <REVISION LOG>
 *  V1.0.0       2020-03-24  qinchun.yang    R19_11 BswM initial version.
 */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "BswM_Internal.h"

/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
static FUNC(BswM_RuleStateType, BSWM_CODE) BswM_RefLE_EcuMRUNRelease_Core0_Par0(void);
static FUNC(BswM_RuleStateType, BSWM_CODE) BswM_RefLE_EcuMPOSTRUNRelease_Core0_Par0(void);
/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
/* BswMConfig*/
/*********************BswMModeRequestPort******************/
#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_RuleIndexType, BSWM_CONST) BswM_CanSMInd0Rule_Core0_Par0[6u] =
{
    2u,
    3u,
    4u,
    5u,
    10u,
    23u,
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_RqstPortLcCfgType, BSWM_CONST) BswM_CansmInd_LCfg_Core0_Par0[1u] =
{
    /*MreqPort_CANSMIndi : BswMCanSMIndication*/
    {
        &(BswM_CanSMInd0Rule_Core0_Par0[0]),        /*belongToRlue*/
        6u,                    /*belongToRlueNum*/
        BSWM_IMMEDIATE    /*BswMRequestProcessing*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(NetworkHandleType, BSWM_CONST) BswM_CansmIndChRef_Core0_Par0[1u] =
{
    Channel_CanController_CAN0,
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_RuleIndexType, BSWM_CONST) BswM_DcmComModeRqstInd0Rule_Core0_Par0[12u] =
{
    11u,
    12u,
    13u,
    14u,
    15u,
    16u,
    17u,
    18u,
    19u,
    20u,
    21u,
    22u,
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_RqstPortLcCfgType, BSWM_CONST) BswM_DcmComModeRqst_LCfg_Core0_Par0[1u] =
{
    /*MreqPort_DcmComReq : BswMDcmComModeRequest*/
    {
        &(BswM_DcmComModeRqstInd0Rule_Core0_Par0[0]),        /*belongToRlue*/
        12u,                    /*belongToRlueNum*/
        BSWM_IMMEDIATE    /*BswMRequestProcessing*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(NetworkHandleType, BSWM_CONST) BswM_DcmChRef_Core0_Par0[1u] =
{
    Channel_CanController_CAN0,
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_RuleIndexType, BSWM_CONST) BswM_EcuMState0Rule_Core0_Par0[2u] =
{
    0u,
    1u,
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_RqstPortLcCfgType, BSWM_CONST) BswM_EcuMState_LCfg_Core0_Par0[1u] =
{
    /*MreqPort_EcuMIndi : BswMEcuMIndication*/
    {
        &(BswM_EcuMState0Rule_Core0_Par0[0]),        /*belongToRlue*/
        2u,                    /*belongToRlueNum*/
        BSWM_IMMEDIATE    /*BswMRequestProcessing*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_RuleIndexType, BSWM_CONST) BswM_EcuMWkSrcRqstInd0Rule_Core0_Par0[1u] =
{
    23u,
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_RqstPortLcCfgType, BSWM_CONST) BswM_EcuMWkSrcRqst_LCfg_Core0_Par0[1u] =
{
    /*MreqPort_WakeUp_CANNM : BswMEcuMWakeupSource*/
    {
        &(BswM_EcuMWkSrcRqstInd0Rule_Core0_Par0[0]),        /*belongToRlue*/
        1u,                    /*belongToRlueNum*/
        BSWM_IMMEDIATE    /*BswMRequestProcessing*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(EcuM_WakeupSourceType, BSWM_CONST) BswM_EcuMWkSrcRef_Core0_Par0[1u] =
{
    EcuMWakeupSource_CANNM,
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_RuleIndexType, BSWM_CONST) BswM_EcuMRunRqst0Rule_Core0_Par0[3u] =
{
    6u,
    7u,
    10u,
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_RuleIndexType, BSWM_CONST) BswM_EcuMRunRqst1Rule_Core0_Par0[3u] =
{
    8u,
    9u,
    10u,
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_RqstPortLcCfgType, BSWM_CONST) BswM_EcuMRunRqst_LCfg_Core0_Par0[2u] =
{
    /*MreqPort_EcuMRUNReq_RUN : BswMEcuMRUNRequestIndication*/
    {
        &(BswM_EcuMRunRqst0Rule_Core0_Par0[0]),        /*belongToRlue*/
        3u,                    /*belongToRlueNum*/
        BSWM_IMMEDIATE    /*BswMRequestProcessing*/
    },
    /*MreqPort_EcuMRUNReq_POSTRUN : BswMEcuMRUNRequestIndication*/
    {
        &(BswM_EcuMRunRqst1Rule_Core0_Par0[0]),        /*belongToRlue*/
        3u,                    /*belongToRlueNum*/
        BSWM_IMMEDIATE    /*BswMRequestProcessing*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(EcuM_StateType, BSWM_CONST) BswM_EcuMRunRqstRef_Core0_Par0[2u] =
{
    ECUM_STATE_APP_RUN,
    ECUM_STATE_APP_POST_RUN,
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ModeRqstPortLCfgType, BSWM_CONST) BswM_ModeRqstLCfg_Core0_Par0 =
{

    &(BswM_CansmInd_LCfg_Core0_Par0[0]),    /*BswMCanSMIndication*/
    &(BswM_CansmIndChRef_Core0_Par0[0]),    /*BswMCanSMChannelRef*/
    NULL_PTR,    /*BswMComMIndication*/
    NULL_PTR,    /*BswMComMChannelRef*/
    &(BswM_DcmComModeRqst_LCfg_Core0_Par0[0]),    /*BswMDcmComModeRequest*/
    &(BswM_DcmChRef_Core0_Par0[0]),    /*BswMDcmComMChannelRef*/
    &(BswM_EcuMState_LCfg_Core0_Par0[0]),
    &(BswM_EcuMWkSrcRqst_LCfg_Core0_Par0[0]),    /*BswMEcuMWakeupSource*/
    &(BswM_EcuMWkSrcRef_Core0_Par0[0]),    /*BswMEcuMWakeupSrcRef*/
    &(BswM_EcuMRunRqst_LCfg_Core0_Par0[0]),    /*BswMEcuMRUNRequestIndication*/
    &(BswM_EcuMRunRqstRef_Core0_Par0[0]),    /*BswMEcuMRUNRequestProtocolPort*/
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

/*********Rules**********/ 

#define BSWM_START_SEC_CODE
#include"BswM_MemMAp.h"
static FUNC(BswM_RuleStateType, BSWM_CODE) BswM_Rule0Expression_Core0_Par0(void)
{
     BswM_RuleStateType result = BSWM_FALSE;
    if(ECUM_STATE_STARTUP == BswM_GetEcuMState())
    {
        result = BSWM_TRUE;
    }
    return result;
};
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListIndexType, BSWM_CONST) BswM_Rule0TrueActList_Core0_Par0[1u] =
{
    0u
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CODE
#include"BswM_MemMAp.h"
static FUNC(BswM_RuleStateType, BSWM_CODE) BswM_Rule1Expression_Core0_Par0(void)
{
     BswM_RuleStateType result = BSWM_FALSE;
    if(ECUM_STATE_RUN == BswM_GetEcuMState())
    {
        result = BSWM_TRUE;
    }
    return result;
};
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListIndexType, BSWM_CONST) BswM_Rule1TrueActList_Core0_Par0[1u] =
{
    1u
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CODE
#include"BswM_MemMAp.h"
static FUNC(BswM_RuleStateType, BSWM_CODE) BswM_Rule2Expression_Core0_Par0(void)
{
     BswM_RuleStateType result = BSWM_FALSE;
    if(CANSM_BSWM_NO_COMMUNICATION == BswM_GetCanSmIndStatus(0))
    {
        result = BSWM_TRUE;
    }
    return result;
};
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListIndexType, BSWM_CONST) BswM_Rule2TrueActList_Core0_Par0[1u] =
{
    6u
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CODE
#include"BswM_MemMAp.h"
static FUNC(BswM_RuleStateType, BSWM_CODE) BswM_Rule3Expression_Core0_Par0(void)
{
     BswM_RuleStateType result = BSWM_FALSE;
    if(CANSM_BSWM_SILENT_COMMUNICATION == BswM_GetCanSmIndStatus(0))
    {
        result = BSWM_TRUE;
    }
    return result;
};
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListIndexType, BSWM_CONST) BswM_Rule3TrueActList_Core0_Par0[1u] =
{
    7u
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CODE
#include"BswM_MemMAp.h"
static FUNC(BswM_RuleStateType, BSWM_CODE) BswM_Rule4Expression_Core0_Par0(void)
{
     BswM_RuleStateType result = BSWM_FALSE;
    if(CANSM_BSWM_FULL_COMMUNICATION == BswM_GetCanSmIndStatus(0))
    {
        result = BSWM_TRUE;
    }
    return result;
};
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListIndexType, BSWM_CONST) BswM_Rule4TrueActList_Core0_Par0[1u] =
{
    8u
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CODE
#include"BswM_MemMAp.h"
static FUNC(BswM_RuleStateType, BSWM_CODE) BswM_Rule5Expression_Core0_Par0(void)
{
     BswM_RuleStateType result = BSWM_FALSE;
    if(CANSM_BSWM_BUS_OFF == BswM_GetCanSmIndStatus(0))
    {
        result = BSWM_TRUE;
    }
    return result;
};
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListIndexType, BSWM_CONST) BswM_Rule5TrueActList_Core0_Par0[1u] =
{
    9u
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CODE
#include"BswM_MemMAp.h"
static FUNC(BswM_RuleStateType, BSWM_CODE) BswM_Rule6Expression_Core0_Par0(void)
{
     BswM_RuleStateType result = BSWM_FALSE;
    if(ECUM_RUNSTATUS_REQUESTED == BswM_GetEcuMRunRqstStatus(0))
    {
        result = BSWM_TRUE;
    }
    return result;
};
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListIndexType, BSWM_CONST) BswM_Rule6TrueActList_Core0_Par0[1u] =
{
    2u
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CODE
#include"BswM_MemMAp.h"
static FUNC(BswM_RuleStateType, BSWM_CODE) BswM_Rule7Expression_Core0_Par0(void)
{
     BswM_RuleStateType result = BSWM_FALSE;
    if(ECUM_RUNSTATUS_RELEASED == BswM_GetEcuMRunRqstStatus(0))
    {
        result = BSWM_TRUE;
    }
    return result;
};
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListIndexType, BSWM_CONST) BswM_Rule7TrueActList_Core0_Par0[1u] =
{
    3u
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CODE
#include"BswM_MemMAp.h"
static FUNC(BswM_RuleStateType, BSWM_CODE) BswM_Rule8Expression_Core0_Par0(void)
{
     BswM_RuleStateType result = BSWM_FALSE;
    if(ECUM_RUNSTATUS_REQUESTED == BswM_GetEcuMRunRqstStatus(1))
    {
        result = BSWM_TRUE;
    }
    return result;
};
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListIndexType, BSWM_CONST) BswM_Rule8TrueActList_Core0_Par0[1u] =
{
    4u
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CODE
#include"BswM_MemMAp.h"
static FUNC(BswM_RuleStateType, BSWM_CODE) BswM_Rule9Expression_Core0_Par0(void)
{
     BswM_RuleStateType result = BSWM_FALSE;
    if(ECUM_RUNSTATUS_RELEASED == BswM_GetEcuMRunRqstStatus(1))
    {
        result = BSWM_TRUE;
    }
    return result;
};
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListIndexType, BSWM_CONST) BswM_Rule9TrueActList_Core0_Par0[1u] =
{
    5u
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CODE
#include"BswM_MemMAp.h"
static FUNC(BswM_RuleStateType, BSWM_CODE) BswM_Rule10Expression_Core0_Par0(void)
{
    BswM_RuleStateType result = BSWM_FALSE;
    if((ECUM_RUNSTATUS_RELEASED == BswM_GetEcuMRunRqstStatus(0))
    && (ECUM_RUNSTATUS_RELEASED == BswM_GetEcuMRunRqstStatus(1))
    && (CANSM_BSWM_NO_COMMUNICATION == BswM_GetCanSmIndStatus(0)))
    {
        result = BSWM_TRUE;
    }
    return result;
};
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListIndexType, BSWM_CONST) BswM_Rule10TrueActList_Core0_Par0[1u] =
{
    10u
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CODE
#include"BswM_MemMAp.h"
static FUNC(BswM_RuleStateType, BSWM_CODE) BswM_Rule11Expression_Core0_Par0(void)
{
     BswM_RuleStateType result = BSWM_FALSE;
    if(DCM_ENABLE_RX_TX_NORM == BswM_GetDcmCurModeStatus(0))
    {
        result = BSWM_TRUE;
    }
    return result;
};
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListIndexType, BSWM_CONST) BswM_Rule11TrueActList_Core0_Par0[1u] =
{
    11u
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CODE
#include"BswM_MemMAp.h"
static FUNC(BswM_RuleStateType, BSWM_CODE) BswM_Rule12Expression_Core0_Par0(void)
{
     BswM_RuleStateType result = BSWM_FALSE;
    if(DCM_ENABLE_RX_DISABLE_TX_NORM == BswM_GetDcmCurModeStatus(0))
    {
        result = BSWM_TRUE;
    }
    return result;
};
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListIndexType, BSWM_CONST) BswM_Rule12TrueActList_Core0_Par0[1u] =
{
    12u
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CODE
#include"BswM_MemMAp.h"
static FUNC(BswM_RuleStateType, BSWM_CODE) BswM_Rule13Expression_Core0_Par0(void)
{
     BswM_RuleStateType result = BSWM_FALSE;
    if(DCM_DISABLE_RX_ENABLE_TX_NORM == BswM_GetDcmCurModeStatus(0))
    {
        result = BSWM_TRUE;
    }
    return result;
};
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListIndexType, BSWM_CONST) BswM_Rule13TrueActList_Core0_Par0[1u] =
{
    13u
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CODE
#include"BswM_MemMAp.h"
static FUNC(BswM_RuleStateType, BSWM_CODE) BswM_Rule14Expression_Core0_Par0(void)
{
     BswM_RuleStateType result = BSWM_FALSE;
    if(DCM_DISABLE_RX_TX_NORMAL == BswM_GetDcmCurModeStatus(0))
    {
        result = BSWM_TRUE;
    }
    return result;
};
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListIndexType, BSWM_CONST) BswM_Rule14TrueActList_Core0_Par0[1u] =
{
    14u
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CODE
#include"BswM_MemMAp.h"
static FUNC(BswM_RuleStateType, BSWM_CODE) BswM_Rule15Expression_Core0_Par0(void)
{
     BswM_RuleStateType result = BSWM_FALSE;
    if(DCM_ENABLE_RX_TX_NM == BswM_GetDcmCurModeStatus(0))
    {
        result = BSWM_TRUE;
    }
    return result;
};
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListIndexType, BSWM_CONST) BswM_Rule15TrueActList_Core0_Par0[1u] =
{
    15u
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CODE
#include"BswM_MemMAp.h"
static FUNC(BswM_RuleStateType, BSWM_CODE) BswM_Rule16Expression_Core0_Par0(void)
{
     BswM_RuleStateType result = BSWM_FALSE;
    if(DCM_ENABLE_RX_DISABLE_TX_NM == BswM_GetDcmCurModeStatus(0))
    {
        result = BSWM_TRUE;
    }
    return result;
};
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListIndexType, BSWM_CONST) BswM_Rule16TrueActList_Core0_Par0[1u] =
{
    16u
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CODE
#include"BswM_MemMAp.h"
static FUNC(BswM_RuleStateType, BSWM_CODE) BswM_Rule17Expression_Core0_Par0(void)
{
     BswM_RuleStateType result = BSWM_FALSE;
    if(DCM_DISABLE_RX_ENABLE_TX_NM == BswM_GetDcmCurModeStatus(0))
    {
        result = BSWM_TRUE;
    }
    return result;
};
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListIndexType, BSWM_CONST) BswM_Rule17TrueActList_Core0_Par0[1u] =
{
    17u
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CODE
#include"BswM_MemMAp.h"
static FUNC(BswM_RuleStateType, BSWM_CODE) BswM_Rule18Expression_Core0_Par0(void)
{
     BswM_RuleStateType result = BSWM_FALSE;
    if(DCM_DISABLE_RX_TX_NM == BswM_GetDcmCurModeStatus(0))
    {
        result = BSWM_TRUE;
    }
    return result;
};
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListIndexType, BSWM_CONST) BswM_Rule18TrueActList_Core0_Par0[1u] =
{
    18u
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CODE
#include"BswM_MemMAp.h"
static FUNC(BswM_RuleStateType, BSWM_CODE) BswM_Rule19Expression_Core0_Par0(void)
{
     BswM_RuleStateType result = BSWM_FALSE;
    if(DCM_ENABLE_RX_TX_NORM_NM == BswM_GetDcmCurModeStatus(0))
    {
        result = BSWM_TRUE;
    }
    return result;
};
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListIndexType, BSWM_CONST) BswM_Rule19TrueActList_Core0_Par0[1u] =
{
    19u
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CODE
#include"BswM_MemMAp.h"
static FUNC(BswM_RuleStateType, BSWM_CODE) BswM_Rule20Expression_Core0_Par0(void)
{
     BswM_RuleStateType result = BSWM_FALSE;
    if(DCM_ENABLE_RX_DISABLE_TX_NORM_NM == BswM_GetDcmCurModeStatus(0))
    {
        result = BSWM_TRUE;
    }
    return result;
};
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListIndexType, BSWM_CONST) BswM_Rule20TrueActList_Core0_Par0[1u] =
{
    20u
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CODE
#include"BswM_MemMAp.h"
static FUNC(BswM_RuleStateType, BSWM_CODE) BswM_Rule21Expression_Core0_Par0(void)
{
     BswM_RuleStateType result = BSWM_FALSE;
    if(DCM_DISABLE_RX_ENABLE_TX_NORM_NM == BswM_GetDcmCurModeStatus(0))
    {
        result = BSWM_TRUE;
    }
    return result;
};
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListIndexType, BSWM_CONST) BswM_Rule21TrueActList_Core0_Par0[1u] =
{
    21u
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CODE
#include"BswM_MemMAp.h"
static FUNC(BswM_RuleStateType, BSWM_CODE) BswM_Rule22Expression_Core0_Par0(void)
{
     BswM_RuleStateType result = BSWM_FALSE;
    if(DCM_DISABLE_RX_TX_NORM_NM == BswM_GetDcmCurModeStatus(0))
    {
        result = BSWM_TRUE;
    }
    return result;
};
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListIndexType, BSWM_CONST) BswM_Rule22TrueActList_Core0_Par0[1u] =
{
    22u
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CODE
#include"BswM_MemMAp.h"
static FUNC(BswM_RuleStateType, BSWM_CODE) BswM_RefLE_EcuMRUNRelease_Core0_Par0(void)
{
     BswM_RuleStateType result = BSWM_FALSE;
     if(ECUM_RUNSTATUS_RELEASED == BswM_GetEcuMRunRqstStatus(0))
     {
       result = BSWM_TRUE;
      }
     return result;
};
#define BSWM_STOP_SEC_CODE
#include"BswM_MemMAp.h"

#define BSWM_START_SEC_CODE
#include"BswM_MemMAp.h"
static FUNC(BswM_RuleStateType, BSWM_CODE) BswM_RefLE_EcuMPOSTRUNRelease_Core0_Par0(void)
{
     BswM_RuleStateType result = BSWM_FALSE;
     if(ECUM_RUNSTATUS_RELEASED == BswM_GetEcuMRunRqstStatus(1))
     {
       result = BSWM_TRUE;
      }
     return result;
};
#define BSWM_STOP_SEC_CODE
#include"BswM_MemMAp.h"

#define BSWM_START_SEC_CODE
#include"BswM_MemMAp.h"
static FUNC(BswM_RuleStateType, BSWM_CODE) BswM_Rule23Expression_Core0_Par0(void)
{
    BswM_RuleStateType result = BSWM_FALSE;
    if((ECUM_WKSTATUS_EXPIRED == BswM_GetEcuMWakeSrcStatus(0))
    && (CANSM_BSWM_NO_COMMUNICATION == BswM_GetCanSmIndStatus(0))
    && (BSWM_TRUE == BswM_RefLE_EcuMRUNRelease_Core0_Par0())
    && (BSWM_TRUE == BswM_RefLE_EcuMPOSTRUNRelease_Core0_Par0()))
    {
        result = BSWM_TRUE;
    }
    return result;
};
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListIndexType, BSWM_CONST) BswM_Rule23TrueActList_Core0_Par0[1u] =
{
    10u
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_RuleLcCfgType, BSWM_CONST) BswM_RuleLCfg_Core0_Par0[24u] =
{
    {
        BswM_Rule0Expression_Core0_Par0,        /*BswMRuleExpressionRef*/
        BSWM_UNDEFINED,        /*BswMRuleInitState*/
        FALSE,    /*BswMNestedExecutionOnly*/
        NULL_PTR,    /*BswMRuleFalseActionList*/
        BswM_Rule0TrueActList_Core0_Par0, /*BswMRuleTrueActionList*/
    },
    {
        BswM_Rule1Expression_Core0_Par0,        /*BswMRuleExpressionRef*/
        BSWM_UNDEFINED,        /*BswMRuleInitState*/
        FALSE,    /*BswMNestedExecutionOnly*/
        NULL_PTR,    /*BswMRuleFalseActionList*/
        BswM_Rule1TrueActList_Core0_Par0, /*BswMRuleTrueActionList*/
    },
    {
        BswM_Rule2Expression_Core0_Par0,        /*BswMRuleExpressionRef*/
        BSWM_UNDEFINED,        /*BswMRuleInitState*/
        FALSE,    /*BswMNestedExecutionOnly*/
        NULL_PTR,    /*BswMRuleFalseActionList*/
        BswM_Rule2TrueActList_Core0_Par0, /*BswMRuleTrueActionList*/
    },
    {
        BswM_Rule3Expression_Core0_Par0,        /*BswMRuleExpressionRef*/
        BSWM_UNDEFINED,        /*BswMRuleInitState*/
        FALSE,    /*BswMNestedExecutionOnly*/
        NULL_PTR,    /*BswMRuleFalseActionList*/
        BswM_Rule3TrueActList_Core0_Par0, /*BswMRuleTrueActionList*/
    },
    {
        BswM_Rule4Expression_Core0_Par0,        /*BswMRuleExpressionRef*/
        BSWM_UNDEFINED,        /*BswMRuleInitState*/
        FALSE,    /*BswMNestedExecutionOnly*/
        NULL_PTR,    /*BswMRuleFalseActionList*/
        BswM_Rule4TrueActList_Core0_Par0, /*BswMRuleTrueActionList*/
    },
    {
        BswM_Rule5Expression_Core0_Par0,        /*BswMRuleExpressionRef*/
        BSWM_UNDEFINED,        /*BswMRuleInitState*/
        FALSE,    /*BswMNestedExecutionOnly*/
        NULL_PTR,    /*BswMRuleFalseActionList*/
        BswM_Rule5TrueActList_Core0_Par0, /*BswMRuleTrueActionList*/
    },
    {
        BswM_Rule6Expression_Core0_Par0,        /*BswMRuleExpressionRef*/
        BSWM_UNDEFINED,        /*BswMRuleInitState*/
        FALSE,    /*BswMNestedExecutionOnly*/
        NULL_PTR,    /*BswMRuleFalseActionList*/
        BswM_Rule6TrueActList_Core0_Par0, /*BswMRuleTrueActionList*/
    },
    {
        BswM_Rule7Expression_Core0_Par0,        /*BswMRuleExpressionRef*/
        BSWM_UNDEFINED,        /*BswMRuleInitState*/
        FALSE,    /*BswMNestedExecutionOnly*/
        NULL_PTR,    /*BswMRuleFalseActionList*/
        BswM_Rule7TrueActList_Core0_Par0, /*BswMRuleTrueActionList*/
    },
    {
        BswM_Rule8Expression_Core0_Par0,        /*BswMRuleExpressionRef*/
        BSWM_UNDEFINED,        /*BswMRuleInitState*/
        FALSE,    /*BswMNestedExecutionOnly*/
        NULL_PTR,    /*BswMRuleFalseActionList*/
        BswM_Rule8TrueActList_Core0_Par0, /*BswMRuleTrueActionList*/
    },
    {
        BswM_Rule9Expression_Core0_Par0,        /*BswMRuleExpressionRef*/
        BSWM_UNDEFINED,        /*BswMRuleInitState*/
        FALSE,    /*BswMNestedExecutionOnly*/
        NULL_PTR,    /*BswMRuleFalseActionList*/
        BswM_Rule9TrueActList_Core0_Par0, /*BswMRuleTrueActionList*/
    },
    {
        BswM_Rule10Expression_Core0_Par0,        /*BswMRuleExpressionRef*/
        BSWM_UNDEFINED,        /*BswMRuleInitState*/
        FALSE,    /*BswMNestedExecutionOnly*/
        NULL_PTR,    /*BswMRuleFalseActionList*/
        BswM_Rule10TrueActList_Core0_Par0, /*BswMRuleTrueActionList*/
    },
    {
        BswM_Rule11Expression_Core0_Par0,        /*BswMRuleExpressionRef*/
        BSWM_UNDEFINED,        /*BswMRuleInitState*/
        FALSE,    /*BswMNestedExecutionOnly*/
        NULL_PTR,    /*BswMRuleFalseActionList*/
        BswM_Rule11TrueActList_Core0_Par0, /*BswMRuleTrueActionList*/
    },
    {
        BswM_Rule12Expression_Core0_Par0,        /*BswMRuleExpressionRef*/
        BSWM_UNDEFINED,        /*BswMRuleInitState*/
        FALSE,    /*BswMNestedExecutionOnly*/
        NULL_PTR,    /*BswMRuleFalseActionList*/
        BswM_Rule12TrueActList_Core0_Par0, /*BswMRuleTrueActionList*/
    },
    {
        BswM_Rule13Expression_Core0_Par0,        /*BswMRuleExpressionRef*/
        BSWM_UNDEFINED,        /*BswMRuleInitState*/
        FALSE,    /*BswMNestedExecutionOnly*/
        NULL_PTR,    /*BswMRuleFalseActionList*/
        BswM_Rule13TrueActList_Core0_Par0, /*BswMRuleTrueActionList*/
    },
    {
        BswM_Rule14Expression_Core0_Par0,        /*BswMRuleExpressionRef*/
        BSWM_UNDEFINED,        /*BswMRuleInitState*/
        FALSE,    /*BswMNestedExecutionOnly*/
        NULL_PTR,    /*BswMRuleFalseActionList*/
        BswM_Rule14TrueActList_Core0_Par0, /*BswMRuleTrueActionList*/
    },
    {
        BswM_Rule15Expression_Core0_Par0,        /*BswMRuleExpressionRef*/
        BSWM_UNDEFINED,        /*BswMRuleInitState*/
        FALSE,    /*BswMNestedExecutionOnly*/
        NULL_PTR,    /*BswMRuleFalseActionList*/
        BswM_Rule15TrueActList_Core0_Par0, /*BswMRuleTrueActionList*/
    },
    {
        BswM_Rule16Expression_Core0_Par0,        /*BswMRuleExpressionRef*/
        BSWM_UNDEFINED,        /*BswMRuleInitState*/
        FALSE,    /*BswMNestedExecutionOnly*/
        NULL_PTR,    /*BswMRuleFalseActionList*/
        BswM_Rule16TrueActList_Core0_Par0, /*BswMRuleTrueActionList*/
    },
    {
        BswM_Rule17Expression_Core0_Par0,        /*BswMRuleExpressionRef*/
        BSWM_UNDEFINED,        /*BswMRuleInitState*/
        FALSE,    /*BswMNestedExecutionOnly*/
        NULL_PTR,    /*BswMRuleFalseActionList*/
        BswM_Rule17TrueActList_Core0_Par0, /*BswMRuleTrueActionList*/
    },
    {
        BswM_Rule18Expression_Core0_Par0,        /*BswMRuleExpressionRef*/
        BSWM_UNDEFINED,        /*BswMRuleInitState*/
        FALSE,    /*BswMNestedExecutionOnly*/
        NULL_PTR,    /*BswMRuleFalseActionList*/
        BswM_Rule18TrueActList_Core0_Par0, /*BswMRuleTrueActionList*/
    },
    {
        BswM_Rule19Expression_Core0_Par0,        /*BswMRuleExpressionRef*/
        BSWM_UNDEFINED,        /*BswMRuleInitState*/
        FALSE,    /*BswMNestedExecutionOnly*/
        NULL_PTR,    /*BswMRuleFalseActionList*/
        BswM_Rule19TrueActList_Core0_Par0, /*BswMRuleTrueActionList*/
    },
    {
        BswM_Rule20Expression_Core0_Par0,        /*BswMRuleExpressionRef*/
        BSWM_UNDEFINED,        /*BswMRuleInitState*/
        FALSE,    /*BswMNestedExecutionOnly*/
        NULL_PTR,    /*BswMRuleFalseActionList*/
        BswM_Rule20TrueActList_Core0_Par0, /*BswMRuleTrueActionList*/
    },
    {
        BswM_Rule21Expression_Core0_Par0,        /*BswMRuleExpressionRef*/
        BSWM_UNDEFINED,        /*BswMRuleInitState*/
        FALSE,    /*BswMNestedExecutionOnly*/
        NULL_PTR,    /*BswMRuleFalseActionList*/
        BswM_Rule21TrueActList_Core0_Par0, /*BswMRuleTrueActionList*/
    },
    {
        BswM_Rule22Expression_Core0_Par0,        /*BswMRuleExpressionRef*/
        BSWM_UNDEFINED,        /*BswMRuleInitState*/
        FALSE,    /*BswMNestedExecutionOnly*/
        NULL_PTR,    /*BswMRuleFalseActionList*/
        BswM_Rule22TrueActList_Core0_Par0, /*BswMRuleTrueActionList*/
    },
    {
        BswM_Rule23Expression_Core0_Par0,        /*BswMRuleExpressionRef*/
        BSWM_UNDEFINED,        /*BswMRuleInitState*/
        FALSE,    /*BswMNestedExecutionOnly*/
        NULL_PTR,    /*BswMRuleFalseActionList*/
        BswM_Rule23TrueActList_Core0_Par0, /*BswMRuleTrueActionList*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

/********************ActionItem*******************/

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionType, BSWM_CONST) BswM_ActListItemsRefAction_Core0_Par0[57u] =
{
    {
        BSWM_ECUM_DRIVER_INIT_BSWM,
        0
    },
    {
        BSWM_COMM_ALLOW_COM,
        0
    },
    {
        BSWM_COMM_MODE_SWITCH,
        1
    },
    {
        BSWM_USER_CALLOUT,
        0
    },
    {
        BSWM_USER_CALLOUT,
        1
    },
    {
        BSWM_USER_CALLOUT,
        2
    },
    {
        BSWM_USER_CALLOUT,
        3
    },
    {
        BSWM_DEADLINE_MONITOR_CONTROL,
        1
    },
    {
        BSWM_PDU_GROUP_SWITCH,
        2
    },
    {
        BSWM_PDU_GROUP_SWITCH,
        3
    },
    {
        BSWM_NM_CONTROL,
        3
    },
    {
        BSWM_PDU_ROUTER_CONTROL,
        1
    },
    {
        BSWM_PDU_GROUP_SWITCH,
        3
    },
    {
        BSWM_NM_CONTROL,
        3
    },
    {
        BSWM_PDU_GROUP_SWITCH,
        0
    },
    {
        BSWM_DEADLINE_MONITOR_CONTROL,
        0
    },
    {
        BSWM_PDU_GROUP_SWITCH,
        0
    },
    {
        BSWM_DEADLINE_MONITOR_CONTROL,
        0
    },
    {
        BSWM_PDU_GROUP_SWITCH,
        1
    },
    {
        BSWM_NM_CONTROL,
        2
    },
    {
        BSWM_PDU_ROUTER_CONTROL,
        0
    },
    {
        BSWM_DEADLINE_MONITOR_CONTROL,
        1
    },
    {
        BSWM_PDU_GROUP_SWITCH,
        2
    },
    {
        BSWM_PDU_GROUP_SWITCH,
        3
    },
    {
        BSWM_ECUM_GO_DOWN_HALT_POLL,
        0
    },
    {
        BSWM_PDU_GROUP_SWITCH,
        0
    },
    {
        BSWM_PDU_GROUP_SWITCH,
        1
    },
    {
        BSWM_DEADLINE_MONITOR_CONTROL,
        0
    },
    {
        BSWM_PDU_GROUP_SWITCH,
        0
    },
    {
        BSWM_PDU_GROUP_SWITCH,
        3
    },
    {
        BSWM_DEADLINE_MONITOR_CONTROL,
        0
    },
    {
        BSWM_DEADLINE_MONITOR_CONTROL,
        1
    },
    {
        BSWM_PDU_GROUP_SWITCH,
        2
    },
    {
        BSWM_PDU_GROUP_SWITCH,
        1
    },
    {
        BSWM_PDU_GROUP_SWITCH,
        3
    },
    {
        BSWM_DEADLINE_MONITOR_CONTROL,
        1
    },
    {
        BSWM_PDU_GROUP_SWITCH,
        2
    },
    {
        BSWM_NM_CONTROL,
        2
    },
    {
        BSWM_NM_CONTROL,
        3
    },
    {
        BSWM_NM_CONTROL,
        2
    },
    {
        BSWM_NM_CONTROL,
        3
    },
    {
        BSWM_PDU_GROUP_SWITCH,
        0
    },
    {
        BSWM_PDU_GROUP_SWITCH,
        1
    },
    {
        BSWM_DEADLINE_MONITOR_CONTROL,
        0
    },
    {
        BSWM_NM_CONTROL,
        2
    },
    {
        BSWM_PDU_GROUP_SWITCH,
        0
    },
    {
        BSWM_PDU_GROUP_SWITCH,
        3
    },
    {
        BSWM_DEADLINE_MONITOR_CONTROL,
        0
    },
    {
        BSWM_NM_CONTROL,
        3
    },
    {
        BSWM_DEADLINE_MONITOR_CONTROL,
        1
    },
    {
        BSWM_PDU_GROUP_SWITCH,
        2
    },
    {
        BSWM_PDU_GROUP_SWITCH,
        1
    },
    {
        BSWM_NM_CONTROL,
        2
    },
    {
        BSWM_PDU_GROUP_SWITCH,
        3
    },
    {
        BSWM_DEADLINE_MONITOR_CONTROL,
        1
    },
    {
        BSWM_PDU_GROUP_SWITCH,
        2
    },
    {
        BSWM_NM_CONTROL,
        3
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListItemRefType, BSWM_CONST) BswM_ActList0Ref_Core0_Par0[1u] =
{
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[0u])    /*avActType*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListItemRefType, BSWM_CONST) BswM_ActList1Ref_Core0_Par0[1u] =
{
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[1u])    /*avActType*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListItemRefType, BSWM_CONST) BswM_ActList2Ref_Core0_Par0[2u] =
{
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[2u])    /*avActType*/
    },
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[3u])    /*avActType*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListItemRefType, BSWM_CONST) BswM_ActList3Ref_Core0_Par0[1u] =
{
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[4u])    /*avActType*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListItemRefType, BSWM_CONST) BswM_ActList4Ref_Core0_Par0[1u] =
{
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[5u])    /*avActType*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListItemRefType, BSWM_CONST) BswM_ActList5Ref_Core0_Par0[1u] =
{
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[6u])    /*avActType*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListItemRefType, BSWM_CONST) BswM_ActList6Ref_Core0_Par0[5u] =
{
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[7u])    /*avActType*/
    },
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[8u])    /*avActType*/
    },
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[9u])    /*avActType*/
    },
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[10u])    /*avActType*/
    },
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[11u])    /*avActType*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListItemRefType, BSWM_CONST) BswM_ActList7Ref_Core0_Par0[4u] =
{
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[12u])    /*avActType*/
    },
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[13u])    /*avActType*/
    },
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[14u])    /*avActType*/
    },
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[15u])    /*avActType*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListItemRefType, BSWM_CONST) BswM_ActList8Ref_Core0_Par0[5u] =
{
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[16u])    /*avActType*/
    },
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[17u])    /*avActType*/
    },
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[18u])    /*avActType*/
    },
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[19u])    /*avActType*/
    },
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[20u])    /*avActType*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListItemRefType, BSWM_CONST) BswM_ActList9Ref_Core0_Par0[3u] =
{
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[21u])    /*avActType*/
    },
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[22u])    /*avActType*/
    },
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[23u])    /*avActType*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListItemRefType, BSWM_CONST) BswM_ActList10Ref_Core0_Par0[1u] =
{
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[24u])    /*avActType*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListItemRefType, BSWM_CONST) BswM_ActList11Ref_Core0_Par0[3u] =
{
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[25u])    /*avActType*/
    },
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[26u])    /*avActType*/
    },
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[27u])    /*avActType*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListItemRefType, BSWM_CONST) BswM_ActList12Ref_Core0_Par0[3u] =
{
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[28u])    /*avActType*/
    },
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[29u])    /*avActType*/
    },
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[30u])    /*avActType*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListItemRefType, BSWM_CONST) BswM_ActList13Ref_Core0_Par0[3u] =
{
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[31u])    /*avActType*/
    },
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[32u])    /*avActType*/
    },
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[33u])    /*avActType*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListItemRefType, BSWM_CONST) BswM_ActList14Ref_Core0_Par0[3u] =
{
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[34u])    /*avActType*/
    },
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[35u])    /*avActType*/
    },
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[36u])    /*avActType*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListItemRefType, BSWM_CONST) BswM_ActList15Ref_Core0_Par0[1u] =
{
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[37u])    /*avActType*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListItemRefType, BSWM_CONST) BswM_ActList16Ref_Core0_Par0[1u] =
{
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[38u])    /*avActType*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListItemRefType, BSWM_CONST) BswM_ActList17Ref_Core0_Par0[1u] =
{
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[39u])    /*avActType*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListItemRefType, BSWM_CONST) BswM_ActList18Ref_Core0_Par0[1u] =
{
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[40u])    /*avActType*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListItemRefType, BSWM_CONST) BswM_ActList19Ref_Core0_Par0[4u] =
{
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[41u])    /*avActType*/
    },
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[42u])    /*avActType*/
    },
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[43u])    /*avActType*/
    },
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[44u])    /*avActType*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListItemRefType, BSWM_CONST) BswM_ActList20Ref_Core0_Par0[4u] =
{
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[45u])    /*avActType*/
    },
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[46u])    /*avActType*/
    },
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[47u])    /*avActType*/
    },
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[48u])    /*avActType*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListItemRefType, BSWM_CONST) BswM_ActList21Ref_Core0_Par0[4u] =
{
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[49u])    /*avActType*/
    },
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[50u])    /*avActType*/
    },
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[51u])    /*avActType*/
    },
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[52u])    /*avActType*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListItemRefType, BSWM_CONST) BswM_ActList22Ref_Core0_Par0[4u] =
{
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[53u])    /*avActType*/
    },
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[54u])    /*avActType*/
    },
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[55u])    /*avActType*/
    },
    {
        NULL_PTR,                                        /*actListRefIdx*/
        NULL_PTR,                                        /*ruleRefIdx*/
        &(BswM_ActListItemsRefAction_Core0_Par0[56u])    /*avActType*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListItemType, BSWM_CONST) BswM_ActionListItemsLCfg_Core0_Par0[57u] =
{
    {
        0u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList0Ref_Core0_Par0[0u])    /*actionRef*/
    },
    {
        1u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList1Ref_Core0_Par0[0u])    /*actionRef*/
    },
    {
        2u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList2Ref_Core0_Par0[0u])    /*actionRef*/
    },
    {
        3u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList2Ref_Core0_Par0[1u])    /*actionRef*/
    },
    {
        4u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList3Ref_Core0_Par0[0u])    /*actionRef*/
    },
    {
        5u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList4Ref_Core0_Par0[0u])    /*actionRef*/
    },
    {
        6u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList5Ref_Core0_Par0[0u])    /*actionRef*/
    },
    {
        7u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList6Ref_Core0_Par0[0u])    /*actionRef*/
    },
    {
        8u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList6Ref_Core0_Par0[1u])    /*actionRef*/
    },
    {
        9u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList6Ref_Core0_Par0[2u])    /*actionRef*/
    },
    {
        10u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList6Ref_Core0_Par0[3u])    /*actionRef*/
    },
    {
        11u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList6Ref_Core0_Par0[4u])    /*actionRef*/
    },
    {
        12u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList7Ref_Core0_Par0[0u])    /*actionRef*/
    },
    {
        13u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList7Ref_Core0_Par0[1u])    /*actionRef*/
    },
    {
        14u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList7Ref_Core0_Par0[2u])    /*actionRef*/
    },
    {
        15u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList7Ref_Core0_Par0[3u])    /*actionRef*/
    },
    {
        16u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList8Ref_Core0_Par0[0u])    /*actionRef*/
    },
    {
        17u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList8Ref_Core0_Par0[1u])    /*actionRef*/
    },
    {
        18u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList8Ref_Core0_Par0[2u])    /*actionRef*/
    },
    {
        19u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList8Ref_Core0_Par0[3u])    /*actionRef*/
    },
    {
        20u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList8Ref_Core0_Par0[4u])    /*actionRef*/
    },
    {
        21u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList9Ref_Core0_Par0[0u])    /*actionRef*/
    },
    {
        22u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList9Ref_Core0_Par0[1u])    /*actionRef*/
    },
    {
        23u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList9Ref_Core0_Par0[2u])    /*actionRef*/
    },
    {
        24u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList10Ref_Core0_Par0[0u])    /*actionRef*/
    },
    {
        25u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList11Ref_Core0_Par0[0u])    /*actionRef*/
    },
    {
        26u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList11Ref_Core0_Par0[1u])    /*actionRef*/
    },
    {
        27u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList11Ref_Core0_Par0[2u])    /*actionRef*/
    },
    {
        28u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList12Ref_Core0_Par0[0u])    /*actionRef*/
    },
    {
        29u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList12Ref_Core0_Par0[1u])    /*actionRef*/
    },
    {
        30u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList12Ref_Core0_Par0[2u])    /*actionRef*/
    },
    {
        31u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList13Ref_Core0_Par0[0u])    /*actionRef*/
    },
    {
        32u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList13Ref_Core0_Par0[1u])    /*actionRef*/
    },
    {
        33u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList13Ref_Core0_Par0[2u])    /*actionRef*/
    },
    {
        34u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList14Ref_Core0_Par0[0u])    /*actionRef*/
    },
    {
        35u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList14Ref_Core0_Par0[1u])    /*actionRef*/
    },
    {
        36u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList14Ref_Core0_Par0[2u])    /*actionRef*/
    },
    {
        37u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList15Ref_Core0_Par0[0u])    /*actionRef*/
    },
    {
        38u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList16Ref_Core0_Par0[0u])    /*actionRef*/
    },
    {
        39u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList17Ref_Core0_Par0[0u])    /*actionRef*/
    },
    {
        40u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList18Ref_Core0_Par0[0u])    /*actionRef*/
    },
    {
        41u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList19Ref_Core0_Par0[0u])    /*actionRef*/
    },
    {
        42u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList19Ref_Core0_Par0[1u])    /*actionRef*/
    },
    {
        43u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList19Ref_Core0_Par0[2u])    /*actionRef*/
    },
    {
        44u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList19Ref_Core0_Par0[3u])    /*actionRef*/
    },
    {
        45u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList20Ref_Core0_Par0[0u])    /*actionRef*/
    },
    {
        46u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList20Ref_Core0_Par0[1u])    /*actionRef*/
    },
    {
        47u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList20Ref_Core0_Par0[2u])    /*actionRef*/
    },
    {
        48u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList20Ref_Core0_Par0[3u])    /*actionRef*/
    },
    {
        49u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList21Ref_Core0_Par0[0u])    /*actionRef*/
    },
    {
        50u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList21Ref_Core0_Par0[1u])    /*actionRef*/
    },
    {
        51u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList21Ref_Core0_Par0[2u])    /*actionRef*/
    },
    {
        52u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList21Ref_Core0_Par0[3u])    /*actionRef*/
    },
    {
        53u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList22Ref_Core0_Par0[0u])    /*actionRef*/
    },
    {
        54u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList22Ref_Core0_Par0[1u])    /*actionRef*/
    },
    {
        55u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList22Ref_Core0_Par0[2u])    /*actionRef*/
    },
    {
        56u,    /*actionItemIdx*/
        FALSE,    /*abortOnFail*/
        NULL_PTR,    /*BswMReportFailRuntimeErrorId*/
        BSWM_ACTIONITEM_ACTION,    /*actionItemType*/
        &(BswM_ActList22Ref_Core0_Par0[3u])    /*actionRef*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionListLCfgType, BSWM_CONST) BswM_ActionListLCfg_Core0_Par0[23u] =
{
    /* AL_EcuMState_StartUp */
    {
        BSWM_TRIGGER,    /*executeType*/
        NULL_PTR,    /*actListPrior*/
        1u,    /*BswMActionListItem*/
        &(BswM_ActionListItemsLCfg_Core0_Par0[0u])    /*actionItems*/
    },
    /* AL_EcuMState_Run */
    {
        BSWM_TRIGGER,    /* executeType */
        NULL_PTR,    /*actListPrior*/
        1u,    /*BswMActionListItem*/
        &(BswM_ActionListItemsLCfg_Core0_Par0[1u]),    /* actionItems */
    },
    /* AL_EcuMReq_RUNRequest */
    {
        BSWM_TRIGGER,    /* executeType */
        NULL_PTR,    /*actListPrior*/
        2u,    /*BswMActionListItem*/
        &(BswM_ActionListItemsLCfg_Core0_Par0[2u]),    /* actionItems */
    },
    /* AL_EcuMReq_RUNRelease */
    {
        BSWM_TRIGGER,    /* executeType */
        NULL_PTR,    /*actListPrior*/
        1u,    /*BswMActionListItem*/
        &(BswM_ActionListItemsLCfg_Core0_Par0[4u]),    /* actionItems */
    },
    /* AL_EcuMReq_POSTRUNRequest */
    {
        BSWM_TRIGGER,    /* executeType */
        NULL_PTR,    /*actListPrior*/
        1u,    /*BswMActionListItem*/
        &(BswM_ActionListItemsLCfg_Core0_Par0[5u]),    /* actionItems */
    },
    /* AL_EcuMReq_POSTRUNRelease */
    {
        BSWM_TRIGGER,    /* executeType */
        NULL_PTR,    /*actListPrior*/
        1u,    /*BswMActionListItem*/
        &(BswM_ActionListItemsLCfg_Core0_Par0[6u]),    /* actionItems */
    },
    /* AL_CANSMNOCOM */
    {
        BSWM_TRIGGER,    /* executeType */
        NULL_PTR,    /*actListPrior*/
        5u,    /*BswMActionListItem*/
        &(BswM_ActionListItemsLCfg_Core0_Par0[7u]),    /* actionItems */
    },
    /* AL_CANSMSILENTCOM */
    {
        BSWM_TRIGGER,    /* executeType */
        NULL_PTR,    /*actListPrior*/
        4u,    /*BswMActionListItem*/
        &(BswM_ActionListItemsLCfg_Core0_Par0[12u]),    /* actionItems */
    },
    /* AL_CANSMFULLCOM */
    {
        BSWM_TRIGGER,    /* executeType */
        NULL_PTR,    /*actListPrior*/
        5u,    /*BswMActionListItem*/
        &(BswM_ActionListItemsLCfg_Core0_Par0[16u]),    /* actionItems */
    },
    /* AL_CANSMBUSOFF */
    {
        BSWM_TRIGGER,    /* executeType */
        NULL_PTR,    /*actListPrior*/
        3u,    /*BswMActionListItem*/
        &(BswM_ActionListItemsLCfg_Core0_Par0[21u]),    /* actionItems */
    },
    /* AL_McuShutDown */
    {
        BSWM_TRIGGER,    /* executeType */
        NULL_PTR,    /*actListPrior*/
        1u,    /*BswMActionListItem*/
        &(BswM_ActionListItemsLCfg_Core0_Par0[24u]),    /* actionItems */
    },
    /* AL_DCMEnRxEnTx_Normal */
    {
        BSWM_TRIGGER,    /* executeType */
        NULL_PTR,    /*actListPrior*/
        3u,    /*BswMActionListItem*/
        &(BswM_ActionListItemsLCfg_Core0_Par0[25u]),    /* actionItems */
    },
    /* AL_DCMEnRxDisTx_Normal */
    {
        BSWM_TRIGGER,    /* executeType */
        NULL_PTR,    /*actListPrior*/
        3u,    /*BswMActionListItem*/
        &(BswM_ActionListItemsLCfg_Core0_Par0[28u]),    /* actionItems */
    },
    /* AL_DCMDisRxEnTx_Normal */
    {
        BSWM_TRIGGER,    /* executeType */
        NULL_PTR,    /*actListPrior*/
        3u,    /*BswMActionListItem*/
        &(BswM_ActionListItemsLCfg_Core0_Par0[31u]),    /* actionItems */
    },
    /* AL_DCMDisRxDisTx_Normal */
    {
        BSWM_TRIGGER,    /* executeType */
        NULL_PTR,    /*actListPrior*/
        3u,    /*BswMActionListItem*/
        &(BswM_ActionListItemsLCfg_Core0_Par0[34u]),    /* actionItems */
    },
    /* AL_DCMEnRxEnTx_NM */
    {
        BSWM_TRIGGER,    /* executeType */
        NULL_PTR,    /*actListPrior*/
        1u,    /*BswMActionListItem*/
        &(BswM_ActionListItemsLCfg_Core0_Par0[37u]),    /* actionItems */
    },
    /* AL_DCMEnRxDisTx_NM */
    {
        BSWM_TRIGGER,    /* executeType */
        NULL_PTR,    /*actListPrior*/
        1u,    /*BswMActionListItem*/
        &(BswM_ActionListItemsLCfg_Core0_Par0[38u]),    /* actionItems */
    },
    /* AL_DCMDisRxEnTx_NM */
    {
        BSWM_TRIGGER,    /* executeType */
        NULL_PTR,    /*actListPrior*/
        1u,    /*BswMActionListItem*/
        &(BswM_ActionListItemsLCfg_Core0_Par0[39u]),    /* actionItems */
    },
    /* AL_DCMDisRxDisTx_NM */
    {
        BSWM_TRIGGER,    /* executeType */
        NULL_PTR,    /*actListPrior*/
        1u,    /*BswMActionListItem*/
        &(BswM_ActionListItemsLCfg_Core0_Par0[40u]),    /* actionItems */
    },
    /* AL_DCMEnRxEnTx_Normal_NM */
    {
        BSWM_TRIGGER,    /* executeType */
        NULL_PTR,    /*actListPrior*/
        4u,    /*BswMActionListItem*/
        &(BswM_ActionListItemsLCfg_Core0_Par0[41u]),    /* actionItems */
    },
    /* AL_DCMEnRxDisTx_Normal_NM */
    {
        BSWM_TRIGGER,    /* executeType */
        NULL_PTR,    /*actListPrior*/
        4u,    /*BswMActionListItem*/
        &(BswM_ActionListItemsLCfg_Core0_Par0[45u]),    /* actionItems */
    },
    /* AL_DCMDisRxEnTx_Normal_NM */
    {
        BSWM_TRIGGER,    /* executeType */
        NULL_PTR,    /*actListPrior*/
        4u,    /*BswMActionListItem*/
        &(BswM_ActionListItemsLCfg_Core0_Par0[49u]),    /* actionItems */
    },
    /* AL_DCMDisRxDisTx_Normal_NM */
    {
        BSWM_TRIGGER,    /* executeType */
        NULL_PTR,    /*actListPrior*/
        4u,    /*BswMActionListItem*/
        &(BswM_ActionListItemsLCfg_Core0_Par0[53u]),    /* actionItems */
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

/********************Action*******************/
#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionComMAllowComLCfgType, BSWM_CONST) BswM_AllowComMLCfg_Core0_Par0[2u] =
{
    /* BswMComMAllowCom*/
    {
        /* comAllowed */
        TRUE,
        /* channel */    
        Channel_CanController_CAN0,
    },
    /* BswMComMDisAllowCom*/
    {
        /* comAllowed */
        FALSE,
        /* channel */    
        Channel_CanController_CAN0,
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionComMModeSwitchLCfgType, BSWM_CONST) BswM_ComMModeSwiLCfg_Core0_Par0[2u] =
{
    /* BswMComMModeSwitch*/
    {
        /* BswMComMRequestedMode */
        COMM_NO_COMMUNICATION,
        /* BswMComMUserRef */    
        ComMUser_0,
    },
    /* BswMComMModeSwitch*/
    {
        /* BswMComMRequestedMode */
        COMM_FULL_COMMUNICATION,
        /* BswMComMUserRef */    
        ComMUser_0,
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ComIpduGruType, BSWM_CONST) BswM_ComEnAbleDmGruLCfg_Core0_Par0[1u] =
{
    Com_RxPduGroup_CanController_CAN0,
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ComIpduGruType, BSWM_CONST) BswM_ComDisAbleDmGruLCfg_Core0_Par0[1u] =
{
    Com_RxPduGroup_CanController_CAN0,
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionDMControlLCfgType, BSWM_CONST) BswM_ComDmCtrlLCfg_Core0_Par0[2u] =
{
    /* BswMDeadlineMonitoringControl*/
    {
        &(BswM_ComEnAbleDmGruLCfg_Core0_Par0[0U]),    /*enableRecDmGruId*/
        1u,        /*numOfEnableRecDmGru*/
        NULL_PTR,    /*disableRecDmGruId*/
        0u,     /*numOfDisableRecDmGru*/
    },
    /* BswMDeadlineMonitoringControl*/
    {
        NULL_PTR,    /*enableRecDmGruId*/
        0u,        /*numOfEnableRecDmGru*/
        &(BswM_ComDisAbleDmGruLCfg_Core0_Par0[0U]), /*disableRecDmGruId*/
        1u,     /*numOfDisableRecDmGru*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ComIpduGruType, BSWM_CONST) BswM_ComEnAblePduGruLCfg_Core0_Par0[2u] =
{
    Com_RxPduGroup_CanController_CAN0,
    Com_TxPduGroup_CanController_CAN0,
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ComIpduGruType, BSWM_CONST) BswM_ComDisAblePduGruLCfg_Core0_Par0[2u] =
{
    Com_RxPduGroup_CanController_CAN0,
    Com_TxPduGroup_CanController_CAN0,
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

static CONST(BswM_ActionPduGrpSwitchLCfgType, BSWM_CONST) BswM_ComPduGruCtrlLCfg_Core0_Par0[4u] =
{
    /* BswMPduGroupSwitch*/
    {
        TRUE,
        &(BswM_ComEnAblePduGruLCfg_Core0_Par0[0U]),    /*enableIpduGruId*/
        1u,        /*numOfEnableIpduGru*/
        NULL_PTR,    /*disableRecDmGruId*/
        0u,     /*numOfDisableIpduGru*/
    },
    /* BswMPduGroupSwitch*/
    {
        TRUE,
        &(BswM_ComEnAblePduGruLCfg_Core0_Par0[1U]),    /*enableIpduGruId*/
        1u,        /*numOfEnableIpduGru*/
        NULL_PTR,    /*disableRecDmGruId*/
        0u,     /*numOfDisableIpduGru*/
    },
    /* BswMPduGroupSwitch*/
    {
        TRUE,
        NULL_PTR,    /*enableRecDmGruId*/
        0u,        /*numOfEnableIpduGru*/
        &(BswM_ComDisAblePduGruLCfg_Core0_Par0[0U]), /*disableIpduGruId*/
        1u,     /*numOfDisableIpduGru*/
    },
    /* BswMPduGroupSwitch*/
    {
        TRUE,
        NULL_PTR,    /*enableRecDmGruId*/
        0u,        /*numOfEnableIpduGru*/
        &(BswM_ComDisAblePduGruLCfg_Core0_Par0[1U]), /*disableIpduGruId*/
        1u,     /*numOfDisableIpduGru*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionEcuMDrvInitLCfgType, BSWM_CONST) BswM_EcuMDrvInitListLCfg_Core0_Par0[1u] =
{
    /* BswMEcuMDriverInitListBswM*/
    {
        EcuMDriverInitListBswM_0
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionEcuMGoDownLCfgType, BSWM_CONST) BswM_EcuMGoDownHaltPollLCfg_Core0_Par0[1u] =
{
    /* BswMEcuMGoDownHaltPoll*/
    {
        EcuMFlexUserConfig
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionEcuMSelectShutTgtLCfgType, BSWM_CONST) BswM_EcuMSelectShutTgtLCfg_Core0_Par0[1u] =
{
    /* BswMEcuMSelectShutdownTarget*/
    {
        /* target */
        ECUM_SHUTDOWN_TARGET_OFF,
        /* mode */
        0U,
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionEcuMStateSwitchLCfgType, BSWM_CONST) BswM_EcuMStateSwitchLCfg_Core0_Par0[2u] =
{
    /* BswMEcuMStateSwitch*/
    {
        /* ecuMState */
        ECUM_STATE_APP_RUN,
    },
    /* BswMEcuMStateSwitch*/
    {
        /* ecuMState */
        ECUM_STATE_APP_POST_RUN,
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionNMControlLCfgType, BSWM_CONST) BswM_NmControlLCfg_Core0_Par0[4u] =
{
    /* BswMNMControl*/
    {
        /* action */
        BSWM_NM_ENABLE,
        /* channel */
        Channel_CanController_CAN0,
    },
    /* BswMNMControl*/
    {
        /* action */
        BSWM_NM_DISABLE,
        /* channel */
        Channel_CanController_CAN0,
    },
    /* BswMNMControl*/
    {
        /* action */
        BSWM_NM_ENABLE,
        /* channel */
        Channel_CanController_CAN0,
    },
    /* BswMNMControl*/
    {
        /* action */
        BSWM_NM_DISABLE,
        /* channel */
        Channel_CanController_CAN0,
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(PduR_RoutingPathGroupIdType, BSWM_CONST) BswM_PdurPathIdsLCfg_Core0_Par0[2u] =
{
    PduRRoutingPathGroup_DCM,
    PduRRoutingPathGroup_DCM,
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionPduRCtrlLCfgType, BSWM_CONST) BswM_PdurCtrlLCfg_Core0_Par0[2u] =
{
    /* BswMPduRouterControl*/
    {
        BSWM_PDUR_ENABLE,
        NULL_PTR,
        1u,        /*numOfPathGrp*/
        &(BswM_PdurPathIdsLCfg_Core0_Par0[0U]),    /*pduPathIds*/
    },
    /* BswMPduRouterControl*/
    {
        BSWM_PDUR_DISABLE,
        NULL_PTR,
        1u,        /*numOfPathGrp*/
        &(BswM_PdurPathIdsLCfg_Core0_Par0[1U]),    /*pduPathIds*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionUserCalloutLCfgType, BSWM_CONST) BswM_UserCallLCfg_Core0_Par0[4u] =
{
    /* BswMUserCallout*/
    {
        /* userCalloutFctPtr */
        Act_RequestRUNCallout,
    },
    /* BswMUserCallout*/
    {
        /* userCalloutFctPtr */
        Act_ReleaseRUNCallout,
    },
    /* BswMUserCallout*/
    {
        /* userCalloutFctPtr */
        Act_BSWMAPPPOstRUNRequest,
    },
    /* BswMUserCallout*/
    {
        /* userCalloutFctPtr */
        Act_BSWMAPPPOstRUNRelease,
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ActionItemsLCfgType, BSWM_CONST) BswM_ActionItemsLCfg_Core0_Par0 =
{
    NULL_PTR,    /*BswMClearEventRequest*/
    &(BswM_AllowComMLCfg_Core0_Par0[0U]),    /*BswMComMAllowCom*/
    NULL_PTR,    /*BswMComMModeLimitation*/
    &(BswM_ComMModeSwiLCfg_Core0_Par0[0U]),    /*BswMComMModeSwitch*/
    &(BswM_ComDmCtrlLCfg_Core0_Par0[0U]),    /*BswMDeadlineMonitoringControl*/
    &(BswM_ComPduGruCtrlLCfg_Core0_Par0[0U]),    /*BswMPduGroupSwitch*/
    NULL_PTR,    /*BswMSwitchIPduMode*/
    NULL_PTR,    /*BswMTriggerIPduSend*/
    &(BswM_EcuMDrvInitListLCfg_Core0_Par0[0U]),    /*BswMEcuMDriverInitListBswM*/
    &(BswM_EcuMGoDownHaltPollLCfg_Core0_Par0[0U]),    /*BswMEcuMGoDownHaltPoll*/
    &(BswM_EcuMSelectShutTgtLCfg_Core0_Par0[0U]),    /*BswMEcuMSelectShutdownTarget*/
    &(BswM_EcuMStateSwitchLCfg_Core0_Par0[0U]),    /*BswMEcuMStateSwitch*/
    &(BswM_NmControlLCfg_Core0_Par0[0U]),    /*BswMNMControl*/
    &(BswM_PdurCtrlLCfg_Core0_Par0[0U]),    /*BswMPduRouterControl*/
    &(BswM_UserCallLCfg_Core0_Par0[0U]),    /*BswMUserCallout*/
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "BswM_MemMAp.h"
static VAR(BswM_RuleRunTimeType, BSWM_VAR_CLEARED) BswM_RuleRunTime_Core0_Par0[24u];
#define BSWM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_PartitionLCfgType, BSWM_CONST) BswM_PartitionLCfg_Core0[1u] =
{
    {
        NULL_PTR,    /*evRqstLCfg*/
        &BswM_ModeRqstLCfg_Core0_Par0,    /*modeRqstLCfg*/
        24u,    /*numOfRules*/
        &(BswM_RuleLCfg_Core0_Par0[0]),    /*ruleLCfg*/
        0u,    /*numOfDefRules*/
        NULL_PTR,    /*defRuleRefLCfg*/
        23u,    /*numOfActionList*/
        &(BswM_ActionListLCfg_Core0_Par0[0]),    /*acListLCfg*/
        &BswM_ActionItemsLCfg_Core0_Par0,    /*acItemsLCfg*/
        &(BswM_RuleRunTime_Core0_Par0[0]),    /*ruleRutTimeStatus*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "BswM_MemMap.h"
static CONST(BswM_LCfgType, BSWM_CONST) BswM_LCfg[1u] =
{
    {
        &(BswM_PartitionLCfg_Core0[0u]),
    },
};
#define BSWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "BswM_MemMap.h"

/*******************************************************************************
**                      Global Variable Definitions                          **
*******************************************************************************/
#define BSWM_START_SEC_CONST_PTR
#include "BswM_MemMap.h"
CONSTP2CONST(BswM_LCfgType, BSWM_CONST, BSWM_CONST) BswM_CoreLinkCfg = &(BswM_LCfg[0u]);
#define BSWM_STOP_SEC_CONST_PTR
#include "BswM_MemMap.h"
