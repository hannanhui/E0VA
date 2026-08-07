
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
**  FILENAME    : BswM_Cfg.c                                                  **
**                                                                            **
**  Created on  : 2025/02/07 16:03:34                                         **
**  Author      :                                                              **
**  Vendor      :                                                             **
**  DESCRIPTION : pre-compile configure parameter definitions of BSWM         **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                       **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "BswM_Internal.h"

/* BswMConfig*/
#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(CanSM_BswMCurrentStateType, BSWM_CONST) BswM_CanSmInitState_Core0_Par0 = CANSM_BSWM_NO_COMMUNICATION;
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(Dcm_CommunicationModeType, BSWM_CONST) BswM_DcmInitMode_Core0_Par0 = DCM_ENABLE_RX_TX_NORM;
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(EcuM_WakeupStatusType, BSWM_CONST) BswM_EcumWkInitstate_Core0_Par0 = ECUM_WKSTATUS_NONE;
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(EcuM_RunStatusType, BSWM_CONST) BswM_EcumRunRqstInitstate_Core0_Par0 = ECUM_RUNSTATUS_RELEASED;
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_ModeRqstPortPCCfgType, BSWM_CONST) BswM_ModeRqstSrc_Core0_Par0 =
{
    1u,    /*numOfCanSMInd*/
    &BswM_CanSmInitState_Core0_Par0,    /*canSMInitState*/
    0u,    /*numOfComMInd*/
    NULL_PTR,
    1u,    /*numOfDcmComModeReq*/
    &BswM_DcmInitMode_Core0_Par0,    /*dcmInitMode*/
    1u,    /*numOfEcuMWakeupSource*/
    &BswM_EcumWkInitstate_Core0_Par0,    /*ecumWkInitstate*/
    2u,    /*numOfEcuMRUNRequestIndications*/
    &BswM_EcumRunRqstInitstate_Core0_Par0,    /*ecumWkInitstate*/
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "BswM_MemMAp.h"
static VAR(CanSM_BswMCurrentStateType, BSWM_VAR_CLEARED) BswM_CanSMIndicationStatus_Core0_Par0[1u];
#define BSWM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "BswM_MemMAp.h"
static VAR(Dcm_CommunicationModeType, BSWM_VAR_CLEARED) BswM_DcmComModeRequestStatus_Core0_Par0[1u];
#define BSWM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "BswM_MemMAp.h"
static VAR(EcuM_WakeupStatusType, BSWM_VAR_CLEARED) BswM_EcuMWakeupSourceStatus_Core0_Par0[1u];
#define BSWM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "BswM_MemMAp.h"
static VAR(EcuM_RunStatusType, BSWM_VAR_CLEARED) BswM_EcuMRunRqstStatus_Core0_Par0[2u];
#define BSWM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_VAR_INIT_UNSPECIFIED
#include "BswM_MemMAp.h"
static VAR(BswM_ModeRqstPortRuntimeType, BSWM_VAR_CLEARED) BswM_ModeRqstSrcSatus_Core0_Par0 =
{
    &(BswM_CanSMIndicationStatus_Core0_Par0[0u]),    /*BswMCanSMIndication*/
    NULL_PTR,    /*BswMComMIndication*/
    &(BswM_DcmComModeRequestStatus_Core0_Par0[0u]),    /*BswMDcmComModeRequest*/
    &(BswM_EcuMWakeupSourceStatus_Core0_Par0[0u]),    /*BswMEcuMWakeupSource*/
    &(BswM_EcuMRunRqstStatus_Core0_Par0[0u]),    /*BswMEcuMRUNRequestIndications*/
};
#define BSWM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "BswM_MemMAp.h"
static VAR(Com_IpduGroupVector, BSWM_VAR_CLEARED) BswM_ComIpduGroup_Ctrl[3u];
#define BSWM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"
static CONST(BswM_PartitionPCCfgType, BSWM_CONST) BswM_PartitionPCCfg_Core0[1u] =
{
    {
        0u,    /*evRqstSrcNum*/
        NULL_PTR,
        &BswM_ModeRqstSrc_Core0_Par0,    /*modeRqstPCCfg*/
        NULL_PTR,
        &BswM_ModeRqstSrcSatus_Core0_Par0,    /*modeRqstPortRunPtr*/
        &(BswM_ComIpduGroup_Ctrl[0u]),    /*comRxDmIpduGroupVector*/
        &(BswM_ComIpduGroup_Ctrl[1u]),    /*ipduGroupReinitVecotr*/
        &(BswM_ComIpduGroup_Ctrl[2u]),    /*ipduGroupAllVecotr*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMAp.h"

#define BSWM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "BswM_MemMap.h"
CONST(BswM_PCCfgType, BSWM_CONST) BswM_PCCfg[1u] =
{
    {
        /* numOfPartitions */
        1U,
        /* bswmPartPCCfgs */
        &(BswM_PartitionPCCfg_Core0[0u]),
    },
};
#define BSWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "BswM_MemMap.h"

/*******************************************************************************
**                      Global Variable Definitions                          **
*******************************************************************************/
#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMap.h"
CONSTP2CONST(BswM_PCCfgType, BSWM_CONST, BSWM_CONST) BswM_CorePCCfg = &(BswM_PCCfg[0]);
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMap.h"
