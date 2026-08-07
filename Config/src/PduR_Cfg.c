/**
* @file        PduR_Cfg.c
* @brief       configuration file for PduR
* @version     1.2.0
* @addtogroup  PduR
* @{
*/
/*====================================================================================================*
 * AngHui AUTOSAR BSW.
 *
 * Copyright(C) 2023 GuoKeAngHui Inc.
 *
 * All rights reserved.
 *
 * This file is part of AngHui AUTOSAR BSW, contains proprietary information.
 * Passing on and copying of this document, and communication of its contents
 * is not permitted without prior written authorization.
 *====================================================================================================*/

 /*====================================================================================================*
 *                                           INCLUDE FILES                                          
 *====================================================================================================*/
#include "PduR.h"

/*====================================================================================================*
 *                                  SOURCE FILE VERSION INFORMATION
 *====================================================================================================*/
#define PDUR_CFG_VENDOR_ID_C               		    0U
#define PDUR_CFG_AR_RELEASE_MAJOR_VERSION_C		    4U
#define PDUR_CFG_AR_RELEASE_MINOR_VERSION_C		    2U
#define PDUR_CFG_AR_RELEASE_REVISION_VERSION_C	    2U
#define PDUR_CFG_SW_MAJOR_VERSION_C      			1U
#define PDUR_CFG_SW_MINOR_VERSION_C      			2U
#define PDUR_CFG_SW_PATCH_VERSION_C      			0U

/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/
 /* Check if current file and PduR.h header file are of the same vendor */
#if(PDUR_CFG_VENDOR_ID_C != PDUR_VENDOR_ID )
#error "PduR_Cfg.c and PduR.h have different vendor id"
#endif

#if(\
      (PDUR_CFG_AR_RELEASE_MAJOR_VERSION_C != PDUR_AR_RELEASE_MAJOR_VERSION) || \
      (PDUR_CFG_AR_RELEASE_MINOR_VERSION_C != PDUR_AR_RELEASE_MINOR_VERSION) || \
      (PDUR_CFG_AR_RELEASE_REVISION_VERSION_C != PDUR_AR_RELEASE_REVISION_VERSION) \
      )
#error "AutoSar Version Number of PduR_Cfg.c and PduR.h are different "
#endif

/* Check if current file and PduR.h header file are of the same software version */
#if(\
      (PDUR_CFG_SW_MAJOR_VERSION_C != PDUR_SW_MAJOR_VERSION) || \
      (PDUR_CFG_SW_MINOR_VERSION_C != PDUR_SW_MINOR_VERSION) ||\
	  (PDUR_CFG_SW_PATCH_VERSION_C != PDUR_SW_PATCH_VERSION)\
      )
#error "Software Version Number of PduR_Cfg.c and PduR.h are different "
#endif

/*====================================================================================================*
 *                                   EXTERNAL FUNCTION DECLARATIONS
 *====================================================================================================*/

/*====================================================================================================*
 *                                           LOCAL TYPEDEFS
 *====================================================================================================*/

/*====================================================================================================*
 *                                            LOCAL MACROS
 *====================================================================================================*/

/*====================================================================================================*
 *                                           LOCAL CONSTANTS
 *====================================================================================================*/

/*====================================================================================================*
 *                                           LOCAL VARIABLES
 *====================================================================================================*/

/*====================================================================================================*
 *                                      LOCAL FUNCTION PROTOTYPES
 *====================================================================================================*/

/*====================================================================================================*
 *                                           LOCAL FUNCTIONS
 *====================================================================================================*/

/*====================================================================================================*
 *                                          GLOBAL FUNCTIONS
 *====================================================================================================*/

#define PDUR_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"
const PduRBswModuleType PduR_BswModuleConfigData[PDUR_BSW_MODULE_SUM] =
{
    {
        PDUR_COM,/*PduRBswModuleRef*/
        FALSE,/*PduRCancelReceive*/
        FALSE,/*PduRCancelTransmit*/
        FALSE,/*PduRChangeParameterApi*/
        TRUE,/*PduRCommunicationInterface*/
        TRUE,/*PduRTransportProtocol*/
        FALSE,/*PduRLowerModule*/
        TRUE,/*PduRUpperModule*/
        TRUE,/*PduRRetransmission*/
        TRUE,/*PduRTriggertransmit*/
        TRUE,/*PduRTxConfirmation*/
        TRUE,/*PduRUseTag*/
    },
    {
        PDUR_LINIF,/*PduRBswModuleRef*/
        FALSE,/*PduRCancelReceive*/
        FALSE,/*PduRCancelTransmit*/
        FALSE,/*PduRChangeParameterApi*/
        TRUE,/*PduRCommunicationInterface*/
        FALSE,/*PduRTransportProtocol*/
        TRUE,/*PduRLowerModule*/
        FALSE,/*PduRUpperModule*/
        FALSE,/*PduRRetransmission*/
        FALSE,/*PduRTriggertransmit*/
        TRUE,/*PduRTxConfirmation*/
        TRUE,/*PduRUseTag*/
    },
    {
        PDUR_LINTP,/*PduRBswModuleRef*/
        FALSE,/*PduRCancelReceive*/
        FALSE,/*PduRCancelTransmit*/
        FALSE,/*PduRChangeParameterApi*/
        TRUE,/*PduRCommunicationInterface*/
        TRUE,/*PduRTransportProtocol*/
        TRUE,/*PduRLowerModule*/
        FALSE,/*PduRUpperModule*/
        FALSE,/*PduRRetransmission*/
        FALSE,/*PduRTriggertransmit*/
        TRUE,/*PduRTxConfirmation*/
        TRUE,/*PduRUseTag*/
    },
    {
        PDUR_DCM,/*PduRBswModuleRef*/
        FALSE,/*PduRCancelReceive*/
        FALSE,/*PduRCancelTransmit*/
        FALSE,/*PduRChangeParameterApi*/
        TRUE,/*PduRCommunicationInterface*/
        TRUE,/*PduRTransportProtocol*/
        FALSE,/*PduRLowerModule*/
        TRUE,/*PduRUpperModule*/
        FALSE,/*PduRRetransmission*/
        FALSE,/*PduRTriggertransmit*/
        TRUE,/*PduRTxConfirmation*/
        TRUE,/*PduRUseTag*/
    },
};
#define PDUR_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"

#define PDUR_START_SEC_CONFIG_DATA_8
#include "PduR_MemMap.h"
CONSTP2CONST(uint8, AUTOMATIC, PDUR_APPL_DATA) PduR_Default_value = NULL_PTR;
#define PDUR_STOP_SEC_CONFIG_DATA_8
#include "PduR_MemMap.h"

#define PDUR_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"
const PduRDestPduType PduR_DestPduConfigData[PDUR_DEST_PDU_SUM] =
{
    {
        PduRConf_PduRDestPdu_LinPdu_PduRToDcm_MasterReq_Rx,/*PduRDestPduHandleId*/
        TRUE,/*PduRTransmissionConfirmation*/
        PduRConf_PduRSrcPdu_LinPdu_LinTpToPduR_MasterReq_Rx,/*PduRSrcPduRef*/
        DcmConf_DcmDslProtocolRx_LinPdu_PduRToDcm_MasterReq_Rx,/*PduRDestModulePduIndex*/
    },
    {
        PduRConf_PduRDestPdu_LinPdu_PduRToLinTp_SlaveResp_Tx,/*PduRDestPduHandleId*/
        TRUE,/*PduRTransmissionConfirmation*/
        PduRConf_PduRSrcPdu_LinPdu_DcmToPduR_SlaveResp_Tx,/*PduRSrcPduRef*/
        LinTpConf_LinTpTxNSdu_LinPdu_PduRToLinTp_SlaveResp_Tx,/*PduRDestModulePduIndex*/
    },
    {
        PduRConf_PduRDestPdu_LinPdu_PduRToLinIf_DSMM_1_Tx,/*PduRDestPduHandleId*/
        TRUE,/*PduRTransmissionConfirmation*/
        PduRConf_PduRSrcPdu_LinPdu_ComToPduR_DSMM_1_Tx,/*PduRSrcPduRef*/
        LinIfConf_LinIfTxPdu_LinPdu_PduRToLinIf_DSMM_1_Tx,/*PduRDestModulePduIndex*/
    },
    {
        PduRConf_PduRDestPdu_LinPdu_PduRToCom_ZCU_SMM_1_Rx,/*PduRDestPduHandleId*/
        TRUE,/*PduRTransmissionConfirmation*/
        PduRConf_PduRSrcPdu_LinPdu_LinIfToPduR_ZCU_SMM_1_Rx,/*PduRSrcPduRef*/
        ComConf_ComIPdu_LinPdu_PduRToCom_ZCU_SMM_1_Rx,/*PduRDestModulePduIndex*/
    },
    {
        PduRConf_PduRDestPdu_LinPdu_PduRToCom_ZCU_SMM_2_Rx,/*PduRDestPduHandleId*/
        TRUE,/*PduRTransmissionConfirmation*/
        PduRConf_PduRSrcPdu_LinPdu_LinIfToPduR_ZCU_SMM_2_Rx,/*PduRSrcPduRef*/
        ComConf_ComIPdu_LinPdu_PduRToCom_ZCU_SMM_2_Rx,/*PduRDestModulePduIndex*/
    },
    {
        PduRConf_PduRDestPdu_LinPdu_PduRToDcm_FuncReq_Rx,/*PduRDestPduHandleId*/
        TRUE,/*PduRTransmissionConfirmation*/
        PduRConf_PduRSrcPdu_LinPdu_LinTpToPduR_FuncReq_Rx,/*PduRSrcPduRef*/
        DcmConf_DcmDslProtocolRx_LinPdu_PduRToDcm_FuncReq_Rx,/*PduRDestModulePduIndex*/
    },
};
#define PDUR_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"

#define PDUR_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"
const PduR_DestPduInfoType PDUR_ROUTING_PduRRoutingPath_Master_Rx[1] = 
{
    {
        DcmConf_DcmDslProtocolRx_LinPdu_PduRToDcm_MasterReq_Rx,/*PduRDestModulePduIndex*/
        PDUR_DCM,/*BswModuleIndex*/
        0xffff,/*PduRDestTxBufferRef*/
        PDUR_DIRECT,/*PduRDestPduDataProvision*/
        0xffff,    /*PduRGatewayDirectTxStateIndex*/
        0xffff,/*GateWayTpRunTimeIndex*/
        NULL_PTR,/*PduRDefaultValueRef*/
        0xff,/*PduRTpThreshold*/
    }
};
                    
const PduR_DestPduInfoType PDUR_ROUTING_PduRRoutingPath_Slave_Tx[1] = 
{
    {
        LinTpConf_LinTpTxNSdu_LinPdu_PduRToLinTp_SlaveResp_Tx,/*PduRDestModulePduIndex*/
        PDUR_LINTP,/*BswModuleIndex*/
        0xffff,/*PduRDestTxBufferRef*/
        PDUR_DIRECT,/*PduRDestPduDataProvision*/
        0xffff,    /*PduRGatewayDirectTxStateIndex*/
        0xffff,/*GateWayTpRunTimeIndex*/
        NULL_PTR,/*PduRDefaultValueRef*/
        0xff,/*PduRTpThreshold*/
    }
};
                    
const PduR_DestPduInfoType PDUR_ROUTING_PduRRoutingPath_DSMM_Tx[1] = 
{
    {
        LinIfConf_LinIfTxPdu_LinPdu_PduRToLinIf_DSMM_1_Tx,/*PduRDestModulePduIndex*/
        PDUR_LINIF,/*BswModuleIndex*/
        0xffff,/*PduRDestTxBufferRef*/
        PDUR_DIRECT,/*PduRDestPduDataProvision*/
        0xffff,    /*PduRGatewayDirectTxStateIndex*/
        0xffff,/*GateWayTpRunTimeIndex*/
        NULL_PTR,/*PduRDefaultValueRef*/
        0xff,/*PduRTpThreshold*/
    }
};
                    
const PduR_DestPduInfoType PDUR_ROUTING_PduRRoutingPath_ZCU_SMM1_Rx[1] = 
{
    {
        ComConf_ComIPdu_LinPdu_PduRToCom_ZCU_SMM_1_Rx,/*PduRDestModulePduIndex*/
        PDUR_COM,/*BswModuleIndex*/
        0xffff,/*PduRDestTxBufferRef*/
        PDUR_DIRECT,/*PduRDestPduDataProvision*/
        0xffff,    /*PduRGatewayDirectTxStateIndex*/
        0xffff,/*GateWayTpRunTimeIndex*/
        NULL_PTR,/*PduRDefaultValueRef*/
        0xff,/*PduRTpThreshold*/
    }
};
                    
const PduR_DestPduInfoType PDUR_ROUTING_PduRRoutingPath_ZCU_SMM2_Rx[1] = 
{
    {
        ComConf_ComIPdu_LinPdu_PduRToCom_ZCU_SMM_2_Rx,/*PduRDestModulePduIndex*/
        PDUR_COM,/*BswModuleIndex*/
        0xffff,/*PduRDestTxBufferRef*/
        PDUR_DIRECT,/*PduRDestPduDataProvision*/
        0xffff,    /*PduRGatewayDirectTxStateIndex*/
        0xffff,/*GateWayTpRunTimeIndex*/
        NULL_PTR,/*PduRDefaultValueRef*/
        0xff,/*PduRTpThreshold*/
    }
};
                    
const PduR_DestPduInfoType PDUR_ROUTING_PduRRoutingPath_Function_Rx[1] = 
{
    {
        DcmConf_DcmDslProtocolRx_LinPdu_PduRToDcm_FuncReq_Rx,/*PduRDestModulePduIndex*/
        PDUR_DCM,/*BswModuleIndex*/
        0xffff,/*PduRDestTxBufferRef*/
        PDUR_DIRECT,/*PduRDestPduDataProvision*/
        0xffff,    /*PduRGatewayDirectTxStateIndex*/
        0xffff,/*GateWayTpRunTimeIndex*/
        NULL_PTR,/*PduRDefaultValueRef*/
        0xff,/*PduRTpThreshold*/
    }
};
                    
#define PDUR_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"

#define PDUR_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"
const PduRSrcPduType PduR_SrcPduConfigData[PDUR_SRC_PDU_SUM] =
{
    {
        PduRConf_PduRSrcPdu_LinPdu_LinTpToPduR_MasterReq_Rx,/*PduRSourcePduHandleId*/
        TRUE,/*PduRSrcPduUpTxConf*/
        0xffff,/*UpTxconfirmStateIndex*/
        LinTpConf_LinTpRxNSdu_LinPdu_LinTpToPduR_MasterReq_Rx,/*PduRSrcModulePduIndex*/
        PDUR_LINTP,   /*PduRSrcModule*/
        0xffff/*TxTpMulticastIndex*/
    },
    {
        PduRConf_PduRSrcPdu_LinPdu_DcmToPduR_SlaveResp_Tx,/*PduRSourcePduHandleId*/
        TRUE,/*PduRSrcPduUpTxConf*/
        0xffff,/*UpTxconfirmStateIndex*/
        DcmConf_DcmDslProtocolTx_LinPdu_DcmToPduR_SlaveResp_Tx,/*PduRSrcModulePduIndex*/
        PDUR_DCM,   /*PduRSrcModule*/
        0xffff/*TxTpMulticastIndex*/
    },
    {
        PduRConf_PduRSrcPdu_LinPdu_ComToPduR_DSMM_1_Tx,/*PduRSourcePduHandleId*/
        TRUE,/*PduRSrcPduUpTxConf*/
        0xffff,/*UpTxconfirmStateIndex*/
        ComConf_ComIPdu_LinPdu_ComToPduR_DSMM_1_Tx,/*PduRSrcModulePduIndex*/
        PDUR_COM,   /*PduRSrcModule*/
        0xffff/*TxTpMulticastIndex*/
    },
    {
        PduRConf_PduRSrcPdu_LinPdu_LinIfToPduR_ZCU_SMM_1_Rx,/*PduRSourcePduHandleId*/
        TRUE,/*PduRSrcPduUpTxConf*/
        0xffff,/*UpTxconfirmStateIndex*/
        LinIfConf_LinIfRxPdu_LinPdu_LinIfToPduR_ZCU_SMM_1_Rx,/*PduRSrcModulePduIndex*/
        PDUR_LINIF,   /*PduRSrcModule*/
        0xffff/*TxTpMulticastIndex*/
    },
    {
        PduRConf_PduRSrcPdu_LinPdu_LinIfToPduR_ZCU_SMM_2_Rx,/*PduRSourcePduHandleId*/
        TRUE,/*PduRSrcPduUpTxConf*/
        0xffff,/*UpTxconfirmStateIndex*/
        LinIfConf_LinIfRxPdu_LinPdu_LinIfToPduR_ZCU_SMM_2_Rx,/*PduRSrcModulePduIndex*/
        PDUR_LINIF,   /*PduRSrcModule*/
        0xffff/*TxTpMulticastIndex*/
    },
    {
        PduRConf_PduRSrcPdu_LinPdu_LinTpToPduR_FuncReq_Rx,/*PduRSourcePduHandleId*/
        TRUE,/*PduRSrcPduUpTxConf*/
        0xffff,/*UpTxconfirmStateIndex*/
        LinIfConf_LinIfRxPdu_LinPdu_LinTpToPduR_FuncReq_Rx,/*PduRSrcModulePduIndex*/
        PDUR_LINIF,   /*PduRSrcModule*/
        0xffff/*TxTpMulticastIndex*/
    },
};
#define PDUR_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"

#define PDUR_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"
const PduRRoutingPathType PduR_RoutingPathConfigData[PDUR_SRC_PDU_SUM] =
{
    {
        PduRConf_PduRSrcPdu_LinPdu_LinTpToPduR_MasterReq_Rx,/*PduRSrcPduId*/
        1,/*PduDestSum*/
        PDUR_ROUTING_PduRRoutingPath_Master_Rx,/*PduRDestPduIdRef*/
        TRUE,/*TpRoute*/
        TRUE,/*TpPduIsSF*/
        FALSE,/*GatewayOnTheFly*/
        0xffff/*PduRTpMaxThreshold*/
    },
    {
        PduRConf_PduRSrcPdu_LinPdu_DcmToPduR_SlaveResp_Tx,/*PduRSrcPduId*/
        1,/*PduDestSum*/
        PDUR_ROUTING_PduRRoutingPath_Slave_Tx,/*PduRDestPduIdRef*/
        TRUE,/*TpRoute*/
        TRUE,/*TpPduIsSF*/
        FALSE,/*GatewayOnTheFly*/
        0xffff/*PduRTpMaxThreshold*/
    },
    {
        PduRConf_PduRSrcPdu_LinPdu_ComToPduR_DSMM_1_Tx,/*PduRSrcPduId*/
        1,/*PduDestSum*/
        PDUR_ROUTING_PduRRoutingPath_DSMM_Tx,/*PduRDestPduIdRef*/
        FALSE,/*TpRoute*/
        TRUE,/*TpPduIsSF*/
        FALSE,/*GatewayOnTheFly*/
        0xffff/*PduRTpMaxThreshold*/
    },
    {
        PduRConf_PduRSrcPdu_LinPdu_LinIfToPduR_ZCU_SMM_1_Rx,/*PduRSrcPduId*/
        1,/*PduDestSum*/
        PDUR_ROUTING_PduRRoutingPath_ZCU_SMM1_Rx,/*PduRDestPduIdRef*/
        FALSE,/*TpRoute*/
        TRUE,/*TpPduIsSF*/
        FALSE,/*GatewayOnTheFly*/
        0xffff/*PduRTpMaxThreshold*/
    },
    {
        PduRConf_PduRSrcPdu_LinPdu_LinIfToPduR_ZCU_SMM_2_Rx,/*PduRSrcPduId*/
        1,/*PduDestSum*/
        PDUR_ROUTING_PduRRoutingPath_ZCU_SMM2_Rx,/*PduRDestPduIdRef*/
        FALSE,/*TpRoute*/
        TRUE,/*TpPduIsSF*/
        FALSE,/*GatewayOnTheFly*/
        0xffff/*PduRTpMaxThreshold*/
    },
    {
        PduRConf_PduRSrcPdu_LinPdu_LinTpToPduR_FuncReq_Rx,/*PduRSrcPduId*/
        1,/*PduDestSum*/
        PDUR_ROUTING_PduRRoutingPath_Function_Rx,/*PduRDestPduIdRef*/
        TRUE,/*TpRoute*/
        TRUE,/*TpPduIsSF*/
        FALSE,/*GatewayOnTheFly*/
        0xffff/*PduRTpMaxThreshold*/
    },
};
#define PDUR_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"


#define PDUR_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"
P2VAR(PduR_TpBufferTableType, AUTOMATIC, PDUR_APPL_DATA) PduR_TpBuffer;
#define PDUR_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"
#define PDUR_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"
P2VAR(PduR_TxBufferTableType, AUTOMATIC, PDUR_APPL_DATA) PduR_TxBuffer = NULL_PTR;
#define PDUR_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"

#define PDUR_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"
const PduR_PBConfigType PduR_Config =
{
    NULL_PTR,
    PduR_RoutingPathConfigData,
    PduR_SrcPduConfigData,
    PduR_DestPduConfigData,
};
#define PDUR_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "PduR_MemMap.h"

#ifdef __cplusplus
}
#endif
/** @} */

