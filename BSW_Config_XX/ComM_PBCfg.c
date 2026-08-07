/**
 *
 * Copyright (C) iSOFT   (2022)
 *
 * All rights reserved.
 *
 * This document contains proprietary information belonging to iSOFT.Passing on and copying of this document, and
 * communication of its contents is not permitted without prior written authorization.
 *
 *
 *  @file               : ComM_PBCfg.c
 *  @version            : V1.0.0
 *  @author             : darren.zhang
 *  @date               : 2025/02/07 16:03:33 
 *  @vendor             : isoft
 *  @description        : Communication Manager
 *  @specification(s)   : AUTOSAR classic R19-11
 *
 */

/*=================================================[inclusions]=======================================================*/
#include "ComM_Cfg.h"
#include "ComM_PBCfg.h"
#include "CanSM_ComM.h"
/*==========================================[external function definitions]===========================================*/
BEGIN_C_DECLS
/*=================================================[internal data]====================================================*/
#define COMM_START_SEC_CONST_PBCFG_8
#include "ComM_MemMap.h"
COMM_CONFIG_LOCAL CONST(uint8, COMM_CONST) ComM_UserMapChanelTable[1] = {0u};
COMM_CONFIG_LOCAL CONST(uint8, COMM_CONST) ComM_UserInChanelIdexTable[1] = {0u};
#define COMM_STOP_SEC_CONST_PBCFG_8
#include "ComM_MemMap.h"

#define COMM_START_SEC_CONST_PBCFG_UNSPECIFIED
#include "ComM_MemMap.h"
COMM_CONFIG_LOCAL CONST(ComM_UserConfigType, COMM_CONST) ComM_UserCfg[COMM_USER_NUMBER] = {
    /* ComMUser_0 */
    {
        0u,/*userId*/
        &ComM_UserMapChanelTable[0],/*chnelList*/
        1u,/*chnnlListSize*/
        &ComM_UserInChanelIdexTable[0],/*userInChIdex*/
    },
};
#define COMM_STOP_SEC_CONST_PBCFG_UNSPECIFIED
#include "ComM_MemMap.h"

#define COMM_START_SEC_CONST_PBCFG_UNSPECIFIED
#include "ComM_MemMap.h"
COMM_CONFIG_LOCAL CONST(ComM_BusSmConfigType, COMM_CONST) ComM_BusSmCfgTable[1] = {
    {
        CanSM_RequestComMode,/*busSm_RequestComMode*/
        CanSM_GetCurrentComMode /*busSm_GetCurrentComMode*/
    },
};
#define COMM_STOP_SEC_CONST_PBCFG_UNSPECIFIED
#include "ComM_MemMap.h"
#define COMM_START_SEC_VAR_NO_INIT_8
#include "ComM_MemMap.h"
COMM_CONFIG_LOCAL VAR(uint8, AUTOMATIC) ComM_ReqMaskBuf_Channel_CanController_CAN0[1];
#define COMM_STOP_SEC_VAR_NO_INIT_8
#include "ComM_MemMap.h"

#define COMM_START_SEC_CONST_PBCFG_8
#include "ComM_MemMap.h"

COMM_CONFIG_LOCAL CONST(uint8, COMM_CONST) ComM_DcmNotifyId[1]={0x0u};
#define COMM_STOP_SEC_CONST_PBCFG_8
#include "ComM_MemMap.h"

#define COMM_START_SEC_CONST_PBCFG_UNSPECIFIED
#include "ComM_MemMap.h"
COMM_CONFIG_LOCAL CONST(ComM_ChannelConfigType, COMM_CONST) ComM_ChannelConfig[COMM_CHANNEL_NUMBER] = {
    /* Channel_CanController_CAN0 */
    {
        0u,/*inerChIdx*/
        COMM_BUS_TYPE_CAN,/*busType*/
        0u,/*busIndex*/
        &ComM_BusSmCfgTable[0],/*busSmCfgType*/
        COMM_NM_VARIANT_FULL,/*nmVariant*/
        1u,/*dcmInReqIdx*/
        &ComM_DcmNotifyId[0],/*dcmNotifyIdPtr*/
        0u,/*netifId*/
        {0x0},/*cfgMask*/
        &ComM_ReqMaskBuf_Channel_CanController_CAN0[0],/*requestMask*/
        1u /*requestMaskLen*/
    }
};
#define COMM_STOP_SEC_CONST_PBCFG_UNSPECIFIED
#include "ComM_MemMap.h"

/*=================================================[external data]====================================================*/
#define COMM_START_SEC_CONST_PBCFG_UNSPECIFIED
#include "ComM_MemMap.h"
CONST(ComM_ConfigType, COMM_CONST)
ComM_Config = {
    ComM_ChannelConfig,/*chCfgPtr*/
    COMM_CHANNEL_NUMBER,/*chCfgNum*/
    ComM_UserCfg,/*userCfgPtr*/
    COMM_USER_NUMBER,/*userCfgNum*/
};
#define COMM_STOP_SEC_CONST_PBCFG_UNSPECIFIED
#include "ComM_MemMap.h"
END_C_DECLS

