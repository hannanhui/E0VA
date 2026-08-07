
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
**  FILENAME    : CanIf_Cfg.c                                                 **
**                                                                            **
**  Created on  : 2025/05/29 15:06:03                                         **
**  Author      : zhengfei.li                                                 **
**  Vendor      :                                                             **
**  DESCRIPTION :parameter declaration of CanIf                               **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
#define CANIF_CFG_C_AR_MAJOR_VERSION  4u
#define CANIF_CFG_C_AR_MINOR_VERSION  2u
#define CANIF_CFG_C_AR_PATCH_VERSION  2u
#define CANIF_CFG_C_SW_MAJOR_VERSION  2u
#define CANIF_CFG_C_SW_MINOR_VERSION  0u
#define CANIF_CFG_C_SW_PATCH_VERSION  0u

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "CanIf.h"
#include "CanSM_Cbk.h"
#include "EcuM_Cbk.h"
#include "CanNm_Cbk.h"
#include "CanTp_Cbk.h"
#include "CanTp.h"
#include "PduR_CanIf.h"
#include "Can.h"
/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (CANIF_CFG_C_AR_MAJOR_VERSION != CANIF_CFG_H_AR_MAJOR_VERSION)
    #error "CanIf.c:Mismatch in Specification Major Version"
#endif

#if (CANIF_CFG_C_AR_MINOR_VERSION != CANIF_CFG_H_AR_MINOR_VERSION)
    #error "CanIf.c:Mismatch in Specification Minor Version"
#endif

#if (CANIF_CFG_C_AR_PATCH_VERSION != CANIF_CFG_H_AR_PATCH_VERSION)
    #error "CanIf.c:Mismatch in Specification Patch Version"
#endif

#if (CANIF_CFG_C_SW_MAJOR_VERSION != CANIF_CFG_H_SW_MAJOR_VERSION)
    #error "CanIf.c:Mismatch in Specification Major Version"
#endif

#if (CANIF_CFG_C_SW_MINOR_VERSION != CANIF_CFG_H_SW_MINOR_VERSION)
    #error "CanIf.c:Mismatch in Specification Minor Version"
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
#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(CanIf_DispatchConfigType,CANIF_CONST) CanIf_DispatchConfigData =
{
    /* void XXX_ControllerBusOff(uint8 ControllerId) */
    &CanSM_ControllerBusOff,
    /* void XXX_ControllerModeIndication(uint8 ControllerId,CanIf_ControllerModeType ControllerMode)  */
    &CanSM_ControllerModeIndication,
    /* void XXX_TransceiverModeIndication(uint8 TransceiverId,CanTrcv_TrcvModeType TransceiverMode) */
    NULL_PTR,
    /* void XXX_ValidateWakeupEvent(EcuM_WakeupSourceType sources)*/
    &EcuM_ValidateWakeupEvent,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(Can_DriverApiType,CANIF_CONST_PBCFG) Can_DriverApi[CANIF_CANDRIVER_NUMBER] =
{
    {
        &Can_SetControllerMode,
        &Can_Write,
    },
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(CanIfCtrlCanCtrlRefType,CANIF_CONST_PBCFG) CanIf_CtrlRef[CANIF_CANCONTROLLER_NUMBER] =
{
    {
        0u,EcuMWakeupSource_CANNM
    },
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(CanIf_ControllerCfgType,CANIF_CONST) CanIf_CtrlCfgData[CANIF_CANCONTROLLER_NUMBER] =
{
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_CAN0,
        CANIF_CAN,
        FALSE,
        &CanIf_CtrlRef[0],
    },
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(CanIfHrhIdSymRefType,CANIF_CONST_PBCFG) CanIf_HrhRef[CANIF_HRH_NUMBER] =
{
    {
        10u,
        CANIF_BASIC_CAN,
    },
    {
        11u,
        CANIF_FULL_CAN,
    },
    {
        12u,
        CANIF_FULL_CAN,
    },
    {
        7u,
        CANIF_FULL_CAN,
    },
    {
        5u,
        CANIF_FULL_CAN,
    },
    {
        6u,
        CANIF_FULL_CAN,
    },
    {
        3u,
        CANIF_FULL_CAN,
    },
    {
        0u,
        CANIF_FULL_CAN,
    },
    {
        1u,
        CANIF_FULL_CAN,
    },
    {
        9u,
        CANIF_FULL_CAN,
    },
    {
        8u,
        CANIF_FULL_CAN,
    },
    {
        2u,
        CANIF_FULL_CAN,
    },
    {
        4u,
        CANIF_FULL_CAN,
    },
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef0[1] =
{
    CANIF_RXPDU_Rx_TABBodyNMFr,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef1[1] =
{
    CANIF_RXPDU_CANIF_MCToAllBodyCan_FuncDiagReqFr,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef2[1] =
{
    CANIF_RXPDU_CANIF_MCToTAB_PhyDiagReqFr,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef3[1] =
{
    CANIF_RXPDU_MC_BodyCAN_0x1AA,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef4[1] =
{
    CANIF_RXPDU_MC_BodyCAN_0x143,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef5[1] =
{
    CANIF_RXPDU_MC_BodyCAN_0x192,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef6[1] =
{
    CANIF_RXPDU_MC_BodyCAN_0x107,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef7[1] =
{
    CANIF_RXPDU_MC_BodyCAN_0x100,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef8[1] =
{
    CANIF_RXPDU_MC_BodyCAN_0x103,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef9[1] =
{
    CANIF_RXPDU_MC_TABFuncCtrl_BodyCAN_0x200,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef10[1] =
{
    CANIF_RXPDU_MC_BodyCAN_0x1D4,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef11[1] =
{
    CANIF_RXPDU_MC_BodyCAN_0x106,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef12[1] =
{
    CANIF_RXPDU_MC_BodyCAN_0x10B,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(CanIfHrhCfgType,CANIF_CONST) CanIf_HrhCfgData[CANIF_HRH_NUMBER] =
{
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_CAN0,
        0u,
        1u,
        &CanIf_HrhRxPduRef0[0],
        NULL_PTR,
        &CanIf_HrhRef[0],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_CAN0,
        0u,
        1u,
        &CanIf_HrhRxPduRef1[0],
        NULL_PTR,
        &CanIf_HrhRef[1],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_CAN0,
        0u,
        1u,
        &CanIf_HrhRxPduRef2[0],
        NULL_PTR,
        &CanIf_HrhRef[2],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_CAN0,
        0u,
        1u,
        &CanIf_HrhRxPduRef3[0],
        NULL_PTR,
        &CanIf_HrhRef[3],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_CAN0,
        0u,
        1u,
        &CanIf_HrhRxPduRef4[0],
        NULL_PTR,
        &CanIf_HrhRef[4],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_CAN0,
        0u,
        1u,
        &CanIf_HrhRxPduRef5[0],
        NULL_PTR,
        &CanIf_HrhRef[5],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_CAN0,
        0u,
        1u,
        &CanIf_HrhRxPduRef6[0],
        NULL_PTR,
        &CanIf_HrhRef[6],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_CAN0,
        0u,
        1u,
        &CanIf_HrhRxPduRef7[0],
        NULL_PTR,
        &CanIf_HrhRef[7],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_CAN0,
        0u,
        1u,
        &CanIf_HrhRxPduRef8[0],
        NULL_PTR,
        &CanIf_HrhRef[8],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_CAN0,
        0u,
        1u,
        &CanIf_HrhRxPduRef9[0],
        NULL_PTR,
        &CanIf_HrhRef[9],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_CAN0,
        0u,
        1u,
        &CanIf_HrhRxPduRef10[0],
        NULL_PTR,
        &CanIf_HrhRef[10],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_CAN0,
        0u,
        1u,
        &CanIf_HrhRxPduRef11[0],
        NULL_PTR,
        &CanIf_HrhRef[11],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_CAN0,
        0u,
        1u,
        &CanIf_HrhRxPduRef12[0],
        NULL_PTR,
        &CanIf_HrhRef[12],
    },
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(CanIfHthIdSymRefType,CANIF_CONST_PBCFG) CanIf_HthRef[CANIF_HTH_NUMBER] =
{
    {
        21u,
        CANIF_BASIC_CAN,
    },
    {
        22u,
        CANIF_BASIC_CAN,
    },
    {
        20u,
        CANIF_BASIC_CAN,
    },
    {
        17u,
        CANIF_BASIC_CAN,
    },
    {
        16u,
        CANIF_BASIC_CAN,
    },
    {
        19u,
        CANIF_BASIC_CAN,
    },
    {
        13u,
        CANIF_BASIC_CAN,
    },
    {
        14u,
        CANIF_BASIC_CAN,
    },
    {
        15u,
        CANIF_BASIC_CAN,
    },
    {
        18u,
        CANIF_BASIC_CAN,
    },
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(CanIfHthCfgType,CANIF_CONST) CanIf_HthCfgData[CANIF_HTH_NUMBER] =
{
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_CAN0,
        &CanIf_HthRef[0],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_CAN0,
        &CanIf_HthRef[1],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_CAN0,
        &CanIf_HthRef[2],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_CAN0,
        &CanIf_HthRef[3],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_CAN0,
        &CanIf_HthRef[4],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_CAN0,
        &CanIf_HthRef[5],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_CAN0,
        &CanIf_HthRef[6],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_CAN0,
        &CanIf_HthRef[7],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_CAN0,
        &CanIf_HthRef[8],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CanController_CAN0,
        &CanIf_HthRef[9],
    },
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(CanIf_InitHohCfgType,CANIF_CONST) CanIf_InitHohCfgData =
{
    CanIf_HrhCfgData,
    CanIf_HthCfgData,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(CanIfRxPduRefType,CANIF_CONST_PBCFG) CanIf_RxPduRef[CANIF_RXPDU_NUMBER] =
{
    {
        CANNM_RX_PDU_0,
        FALSE
    },
    {
        CANTP_CANIF_MCToAllBodyCan_FuncDiagReqFr,
        FALSE
    },
    {
        CANTP_CANIF_MCToTAB_PhyDiagReqFr,
        FALSE
    },
    {
        PDUR_SRCPDU_MC_BodyCAN_0x1AA,
        FALSE
    },
    {
        PDUR_SRCPDU_MC_BodyCAN_0x143,
        FALSE
    },
    {
        PDUR_SRCPDU_MC_BodyCAN_0x192,
        FALSE
    },
    {
        PDUR_SRCPDU_MC_BodyCAN_0x107,
        FALSE
    },
    {
        PDUR_SRCPDU_MC_BodyCAN_0x100,
        FALSE
    },
    {
        PDUR_SRCPDU_MC_BodyCAN_0x103,
        FALSE
    },
    {
        PDUR_SRCPDU_MC_TABFuncCtrl_BodyCAN_0x200,
        FALSE
    },
    {
        PDUR_SRCPDU_MC_BodyCAN_0x1D4,
        FALSE
    },
    {
        PDUR_SRCPDU_MC_BodyCAN_0x106,
        FALSE
    },
    {
        PDUR_SRCPDU_MC_BodyCAN_0x10B,
        FALSE
    },
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(CanIf_RxPduConfigType,CANIF_CONST) CanIf_RxPduConfigData[CANIF_RXPDU_NUMBER] =
{
    {
        CANIF_RXPDU_Rx_TABBodyNMFr,
        0x537u,
        0x7c0u,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_0,
        TRUE,
        &CanNm_RxIndication,
        &CanIf_RxPduRef[0],
        0x0u,
        0x7ffu
    },
    {
        CANIF_RXPDU_CANIF_MCToAllBodyCan_FuncDiagReqFr,
        0x7ffu,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_1,
        FALSE,
        &CanTp_RxIndication,
        &CanIf_RxPduRef[1],
        0x0u,
        0x7ffu
    },
    {
        CANIF_RXPDU_CANIF_MCToTAB_PhyDiagReqFr,
        0x736u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_2,
        FALSE,
        &CanTp_RxIndication,
        &CanIf_RxPduRef[2],
        0x0u,
        0x7ffu
    },
    {
        CANIF_RXPDU_MC_BodyCAN_0x1AA,
        0x1aau,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_3,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[3],
        0x0u,
        0x7ffu
    },
    {
        CANIF_RXPDU_MC_BodyCAN_0x143,
        0x143u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_4,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[4],
        0x0u,
        0x7ffu
    },
    {
        CANIF_RXPDU_MC_BodyCAN_0x192,
        0x192u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_5,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[5],
        0x0u,
        0x7ffu
    },
    {
        CANIF_RXPDU_MC_BodyCAN_0x107,
        0x107u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_6,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[6],
        0x0u,
        0x7ffu
    },
    {
        CANIF_RXPDU_MC_BodyCAN_0x100,
        0x100u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_7,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[7],
        0x0u,
        0x7ffu
    },
    {
        CANIF_RXPDU_MC_BodyCAN_0x103,
        0x103u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_8,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[8],
        0x0u,
        0x7ffu
    },
    {
        CANIF_RXPDU_MC_TABFuncCtrl_BodyCAN_0x200,
        0x200u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_9,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[9],
        0x0u,
        0x7ffu
    },
    {
        CANIF_RXPDU_MC_BodyCAN_0x1D4,
        0x1d4u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_10,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[10],
        0x0u,
        0x7ffu
    },
    {
        CANIF_RXPDU_MC_BodyCAN_0x106,
        0x106u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_11,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[11],
        0x0u,
        0x7ffu
    },
    {
        CANIF_RXPDU_MC_BodyCAN_0x10B,
        0x10bu,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_12,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[12],
        0x0u,
        0x7ffu
    },
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(CanIfTxPduRefType,CANIF_CONST_PBCFG) CanIf_TxPduRef[CANIF_TXPDU_NUMBER] =
{
    {
        CANNM_TX_PDU_0,
        FALSE,
        8u
    },
    {
        CANTP_CANIF_TABToMC_DiagResFr,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_TAB_BodyCAN_0x2A7_Info,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_TAB_BodyCAN_0x2A4_SnsrPrm,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_TAB_BodyCAN_0x2A3_SnsrPrm,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_TAB_BodyCAN_0x2A6_PrmFr,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_TAB_BodyCAN_0x2A0_FuncSts,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_TAB_BodyCAN_0x2A1_FuncSts,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_TAB_BodyCAN_0x2A2_SnsrPrm,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_TAB_BodyCAN_0x2A5_FltSts,
        FALSE,
        8u
    },
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(CanIf_TxPduConfigType,CANIF_CONST) CanIf_TxPduConfigData[CANIF_TXPDU_NUMBER] =
{
    {
        CANIF_TXPDU_TABBodyNMFr,
        0x536u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_0,
        0u,
        CANID_STATIC,
        0xffffu,
        &CanNm_TxConfirmation,
        &CanIf_TxPduRef[0],
    },
    {
        CANIF_TXPDU_CANIF_TABToMC_DiagResFr,
        0x636u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_1,
        1u,
        CANID_STATIC,
        0xffffu,
        &CanTp_TxConfirmation,
        &CanIf_TxPduRef[1],
    },
    {
        CANIF_TXPDU_TAB_BodyCAN_0x2A7_Info,
        0x2a7u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_2,
        CANIF_UNUSED_UINT16,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[2],
    },
    {
        CANIF_TXPDU_TAB_BodyCAN_0x2A4_SnsrPrm,
        0x2a4u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_3,
        CANIF_UNUSED_UINT16,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[3],
    },
    {
        CANIF_TXPDU_TAB_BodyCAN_0x2A3_SnsrPrm,
        0x2a3u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_4,
        CANIF_UNUSED_UINT16,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[4],
    },
    {
        CANIF_TXPDU_TAB_BodyCAN_0x2A6_PrmFr,
        0x2a6u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_5,
        CANIF_UNUSED_UINT16,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[5],
    },
    {
        CANIF_TXPDU_TAB_BodyCAN_0x2A0_FuncSts,
        0x2a0u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_6,
        CANIF_UNUSED_UINT16,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[6],
    },
    {
        CANIF_TXPDU_TAB_BodyCAN_0x2A1_FuncSts,
        0x2a1u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_7,
        CANIF_UNUSED_UINT16,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[7],
    },
    {
        CANIF_TXPDU_TAB_BodyCAN_0x2A2_SnsrPrm,
        0x2a2u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_8,
        CANIF_UNUSED_UINT16,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[8],
    },
    {
        CANIF_TXPDU_TAB_BodyCAN_0x2A5_FltSts,
        0x2a5u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_9,
        CANIF_UNUSED_UINT16,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[9],
    },
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
uint8 TxPduBuffer0[8];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
uint8 TxPduBuffer1[8];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
uint8 TxPduBuffer2[8];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
uint8 TxPduBuffer3[8];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
uint8 TxPduBuffer4[8];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
uint8 TxPduBuffer5[8];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
uint8 TxPduBuffer6[8];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
uint8 TxPduBuffer7[8];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
uint8 TxPduBuffer8[8];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
uint8 TxPduBuffer9[8];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
uint8 TxPduBuffer10[8];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
uint8 TxPduBuffer11[8];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
uint8 TxPduBuffer12[8];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
uint8 TxPduBuffer13[8];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
uint8 TxPduBuffer14[8];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
uint8 TxPduBuffer15[8];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
uint8 TxPduBuffer16[8];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
uint8 TxPduBuffer17[8];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
uint8 TxPduBuffer18[8];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
uint8 TxPduBuffer19[8];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_INIT_UNSPECIFIED
#include "CanIf_MemMap.h"
VAR(CanIf_TxPduBufferType, CANIF_VAR) CanIf_TxPduBuffer0[10] =
{
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer0
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer1
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer2
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer3
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer4
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer5
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer6
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer7
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer8
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer9
    },
};
#define CANIF_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_INIT_UNSPECIFIED
#include "CanIf_MemMap.h"
VAR(CanIf_TxPduBufferType, CANIF_VAR) CanIf_TxPduBuffer1[10] =
{
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer10
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer11
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer12
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer13
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer14
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer15
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer16
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer17
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer18
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer19
    },
};
#define CANIF_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_INIT_UNSPECIFIED
#include "CanIf_MemMap.h"
VAR(CanIf_TxBufferType, CANIF_VAR) CanIf_TxBuffer[CANIF_TXBUFFER_NUMBER] =
{
    {CanIf_TxPduBuffer0},
    {CanIf_TxPduBuffer1},
};
#define CANIF_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_8
#include "CanIf_MemMap.h"
CONST(uint8,CANIF_CONST) CanIf_TxBufferSizeCfg[CANIF_TXBUFFER_NUMBER] ={10,10};
#define CANIF_STOP_SEC_CONFIG_DATA_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(CanIf_ConfigType,CANIF_CONST) CanIf_InitCfgSet =
{
    NULL_PTR,
    CanIf_CtrlCfgData,
    &CanIf_InitHohCfgData,
    CanIf_RxPduConfigData,
    CanIf_TxPduConfigData,
    CanIf_TxBufferSizeCfg,
};
#define CANIF_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#if (STD_OFF == CANIF_RXINDICATION_AUTOSAR_PARAMETER)
#define CANIF_START_SEC_PBCONFIG_DATA_16
#include "CanIf_MemMap.h"
CONST(uint16,CANIF_CONST_PBCFG) CanIf_Can0Hoh2HrhId[13u] =
{
    0x7u,0x8u,0xBu,0x6u,0xCu,0x4u,0x5u,0x3u,0xAu,0x9u,
    0x0u,0x1u,0x2u
};
#define CANIF_STOP_SEC_PBCONFIG_DATA_16
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
CONST(CanIf_CanHOH2HRHType,CANIF_CONST) CanIf_CanHoh2Hrh[1] =
{
    {
        CanIf_Can0Hoh2HrhId,
        13u
    }
};
#define CANIF_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
#endif/*STD_OFF == CANIF_RXINDICATION_AUTOSAR_PARAMETER*/
/*******************************************************************************
**                      End of file                                           **
*******************************************************************************/
