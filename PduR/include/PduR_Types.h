/**
 * @file        PduR_Types.h
 * @brief       Module header file of PduR, including version information,
 *              The type and structure of the pdur module are defined
 *              @version     1.2.0
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
#ifndef  PDUR_TYPES_H
#define  PDUR_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif

/*====================================================================================================*
 *                                           INCLUDE FILES
 *====================================================================================================*/
#include "ComStack_Types.h"
#include "PduR_Cfg.h"
#if(STD_OFF == PDUR_ZERO_COST_OPERATION)
/*====================================================================================================*
 *                                  HEADER FILE VERSION INFORMATION
 *====================================================================================================*/
#define PDUR_TYPES_VENDOR_ID               			0U
#define PDUR_TYPES_MODULE_ID               			51U
#define PDUR_TYPES_AR_RELEASE_MAJOR_VERSION			4U
#define PDUR_TYPES_AR_RELEASE_MINOR_VERSION			2U
#define PDUR_TYPES_AR_RELEASE_REVISION_VERSION		2U
#define PDUR_TYPES_SW_MAJOR_VERSION      			1U
#define PDUR_TYPES_SW_MINOR_VERSION      			2U
#define PDUR_TYPES_SW_PATCH_VERSION      			0U

/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/
/* Check if current file and PduR_Cfg.h header file are of the same vendor */
#if(PDUR_TYPES_VENDOR_ID != PDUR_CFG_VENDOR_ID )
#error "PduR_Types.h and PduR_Cfg.h have different vendor id"
#endif

#if(\
      (PDUR_TYPES_AR_RELEASE_MAJOR_VERSION != PDUR_CFG_AR_RELEASE_MAJOR_VERSION) || \
      (PDUR_TYPES_AR_RELEASE_MINOR_VERSION != PDUR_CFG_AR_RELEASE_MINOR_VERSION) || \
      (PDUR_TYPES_AR_RELEASE_REVISION_VERSION != PDUR_CFG_AR_RELEASE_REVISION_VERSION) \
      )
#error "AutoSar Version Number of PduR_Types.h and PduR_Cfg.h are different "
#endif

/* Check if current file and PduR_Cfg.h header file are of the same software version */
#if(\
      (PDUR_TYPES_SW_MAJOR_VERSION != PDUR_CFG_SW_MAJOR_VERSION) || \
      (PDUR_TYPES_SW_MINOR_VERSION != PDUR_CFG_SW_MINOR_VERSION) ||\
	  (PDUR_TYPES_SW_PATCH_VERSION != PDUR_CFG_SW_PATCH_VERSION)\
      )
#error "Software Version Number of PduR_Types.h and PduR_Cfg.h are different "
#endif

#ifndef DISABLE_INTERMOD_VERSION_CHECK
#if(\
      (PDUR_TYPES_AR_RELEASE_MAJOR_VERSION != COMTYPE_AR_RELEASE_MAJOR_VERSION) || \
      (PDUR_TYPES_AR_RELEASE_MINOR_VERSION != COMTYPE_AR_RELEASE_MINOR_VERSION) \
      )
#error "AutoSar Version Number of PduR_Types.h and ComStack_Types.h are different "
#endif
#endif

/*====================================================================================================*
 *                                             CONSTANTS
 *====================================================================================================*/

/*====================================================================================================*
 *                                         DEFINES AND MACROS
 *====================================================================================================*/
/* PduR module  Lower Layer Modules */

#define PDUR_MAX_BUSTYPE_NUMBER    16U
#define PDUR_COM 			0U
#define PDUR_LDCOM 			1U
#define PDUR_IPDUM 			2U
#define PDUR_SECOC 			3U
#define PDUR_DCM 			4U
#define PDUR_J1939DCM 		5U
#define PDUR_J1939RM 		6U
#define PDUR_CANIF 			7U
#define PDUR_CANTP 			8U
#define PDUR_J1939TP 		9U
#define PDUR_CANNM 			10U
#define PDUR_LINIF 			11U
#define PDUR_LINTP 			12U
#define PDUR_FRIF 			13U
#define PDUR_SOADIF 		14U
#define PDUR_SOADTP 		15U

/*====================================================================================================*
 *                                               ENUMS
 *====================================================================================================*/
typedef enum
{
	PDUR_DIRECT = 0u,
	PDUR_TRIGGERTRANSMIT/* PduRDestTxBufferRef is required*/
}PduR_DestPduDataProvisionType;

/**
 * @req [SWS_PduR_00293] Type definitions of the PDU Router module shall be defined in PduR_Types.h.
 */
/**
 * @req [SWS_PduR_00324] The PDU Router module shall consist of two states, PDUR_UNINIT and PDUR_ONLINE,
 * 						 as defined in PduR_StateType.
 */
/**
 * @req [SWS_PduR_00742] Name: PduR_StateType Type: Enumeration Range: PDUR_UNINIT PDU Router not
 * 						 initialised PDUR_ONLINE PDU Router initialized successfully Description:
 * 						 States of the PDU Router
 */
/**
 * @req [SWS_PduR_00324] The PDU Router module shall consist of two states,PDUR_UNINIT and
 * 										 PDUR_ONLINE, as defined in PduR_StateType
 */
typedef enum
{
    PDUR_UNINIT = 0u, /* not initialized */
    PDUR_ONLINE /* initialized successfully */
} PduR_StateType;

/*====================================================================================================*
 *                                   STRUCTURES AND OTHER TYPEDEFS
 *====================================================================================================*/
/**
 * @req [SWS_PduR_00771]
 */
typedef uint16 PduR_PBConfigIdType;

/**
 * @req [SWS_PduR_00654] Name: PduR_RoutingPathGroupIdType Type: uint16 Description:Identification of
 * 						 a Routing Table
 */
typedef uint16 PduR_RoutingPathGroupIdType;

/* You can only configure when you use a trigger */
/**
 * @brief Default Value struct
 */
typedef struct
{
	/** <@brief default value data */
	const uint32 DefaultValueData;
	/** <@brief default value data length */
	const uint32 DefaultValueLength;
}PduRDefaultValueType;

/**
 * @brief dest Pdu struct
 */
typedef struct
{
	/** <@brief pdu id */
	uint16 DestPduId;
	/** <@brief pdu module */
	uint8 DestModuleType;
	/** <@brief Reference to [ PduRTxBuffer ],no buffer the default value is 0xffff */
	const uint16 PduRDestTxBufferRef;
	/** <@brief pdu property */
	const PduR_DestPduDataProvisionType PduRDestPduDataProvision;
	/** <@brief used for gateway direct pdu */
	const PduIdType PduRGatewayDirectTxStateIndex;
	/** <@brief used for gateway Tp */
	const PduIdType GateWayTpRunTimeIndex;
	/** <@brief no default value is null */
	P2CONST(PduRDefaultValueType, AUTOMATIC, PDUR_CONST_PBCFG) PduRDefaultValueRef;
	/** <@brief Threshold value */
	const uint16 PduRTpThreshold;
}PduR_DestPduInfoType;

/**
 * @brief source Pdu struct
 */
typedef struct
{
	/** <@brief RoutingPath Id is same to the PduRSourcePduHandleId,PduRSrcPdu belong to RoutingPath */
	const PduIdType PduRSourcePduHandleId;
	/** <@brief define if forward tx confirm to up layer(COM,DCM,J1939DCM...) */
	const boolean PduRSrcPduUpTxConf;
	/** <@brief if not up tx(1:n(n>1)),the value is 0xffff.IF module is before of TP module */
	const PduIdType UpTxconfirmStateIndex;
	/** <@brief dest pdu id */
	const PduIdType PduRSrcModulePduId;
	/** <@brief slection module */
	const uint8 SrcModuleType;
    #if(STD_ON == PDUR_META_DATA_SUPPORT)
	/** <@brief MetaDataLength */
	const uint8 MetaDataLength;
    #endif/* STD_ON == PDUR_META_DATA_SUPPORT */
	/** <@brief used for 1:n (up module transmit) */
	const PduIdType TxTpMulticastIndex;
}PduRSrcPduType;


/**
 * @brief dest Pdu struct
 */
typedef struct
{
	/** <@brief RoutingPath Id is same to the PduRSourcePduHandleId,PduRSrcPdu belong to RoutingPath*/
	const PduIdType PduRDestPduHandleId;
	/** <@brief This parameter is only for communication interfaces. Transport protocol modules will
	 * 	always call the TxConfirmation function */
	const boolean PduRTransmissionConfirmation;
	/** <@brief simple implementation for PduR_CanIfTxConfirmation*/
	const PduIdType PduRSrcPduRef;
	/** <@brief dest pdu id */
	const PduIdType ActualPduId;

}PduRDestPduType;


/**
 * @brief Routing Path struct
 */
typedef struct
{
	/** <@brief src pdu index */
	const uint16 PduRSrcPduId;
	/** <@brief total dest pdu num */
	const uint8 DestPduNumber;
	/** <@brief dest pdu ref */
	P2CONST(PduR_DestPduInfoType, AUTOMATIC, PDUR_CONST_PBCFG) PduRDestPduIdRef;
	/** <@brief true is Tp route,false is route */
	const boolean RouteIsTp;
	/** <@brief Tp route:true is SF,false is FF */
	const boolean TpPduIsSF;
	/** <@brief gateway-on-the-fly mode or not */
	const boolean GatewayOnTheFly;
	/** <@brief gateway-on-the-fly mode,used to select valid tp buffer*/
	const uint16 PduRTpMaxThreshold;
}PduRRoutingPathType;

/**
 * @brief Routing Path Table struct
*/
typedef struct
{
	/** <@brief routing path ref*/
	P2CONST(PduRRoutingPathType, AUTOMATIC, PDUR_CONST_PBCFG) PduRRoutingPathRef;
}PduRRoutingTableType;

/**
 * @brief Routing Path Group struct
 */
typedef struct
{
	/** <@brief pdur if enable when init*/
	const boolean PduRIsEnabledAtInit;
	/** <@brief pdur route path group index*/
	const PduR_RoutingPathGroupIdType PduRRoutingPathGroupId;
	/** <@brief number of ref pdu*/
	const uint16 PduRDestPduRefNumber;
	/** <@brief ref Pdu*/
	P2CONST(uint16, AUTOMATIC, PDUR_CONST_PBCFG) PduRDestPduRef;
}PduRRoutingPathGroupType;


/**
 * @brief ref module struct
 */
typedef struct
{
	/** <@brief ref mdoule */
	const uint8	PduRBswModuleRef;
	/** <@brief TP module:CancelReceive API*/
	const boolean PduRCancelReceive;
	/** <@brief TP module:CancelTransmit API*/
	const boolean PduRCancelTransmit;
	/** <@brief TP module:ChangeParameter API*/
	const boolean PduRChangeParameterApi;
	/** <@brief ref interface*/
	const boolean PduRCommunicationInterface;
	/** <@brief wether is tp*/
	const boolean PduRTransportProtocol;
	/** <@brief low module*/
	const boolean PduRLowerModule;
	/** <@brief up module */
	const boolean PduRUpperModule;
	/** <@brief TP retry*/
	const boolean PduRRetransmission;
	/** <@brief Triggertransmit API*/
	const boolean PduRTriggertransmit;
	/** <@brief TxConfirmation API*/
	const boolean PduRTxConfirmation;
	/** <@brief PduR_<Up>CancelReceive,PduR_<Up>CancelTransmit,PduR_<Up>ChangeParameter:<Up>*/
	const boolean PduRUseTag;
}PduRBswModuleType;

/**
 * @brief tp buffer struct
 */
typedef struct
{
	/** <@brief buffer recive stop place to set flag*/
	uint16 RxBufferOffset;
	/** <@brief buffer length*/
	uint16 TpBufferLength;
	/** <@brief sdu length*/
	uint16 SduLength;
	/** <@brief data ptr*/
	P2VAR(uint8, AUTOMATIC, PDUR_CONST_PBCFG) TpBufferData;
	/** <@brief pdu id*/
	PduIdType PduHandleId;
	/** <@brief the buffer wether is use*/
	boolean used;
    #if(STD_ON == PDUR_META_DATA_SUPPORT)
	/** <@brief metadata ptr*/
	uint8 MetaData[4];
    #endif/* STD_ON == PDUR_META_DATA_SUPPORT */
	/** <@brief used for gateway-on-the-fly next buffer id*/
	uint8 NextTpBufferId;
}PduR_TpBufferTableType;

/**
 * @brief pdu buffer struct
 */
typedef struct
{
	/** <@brief sdu length*/
	uint16 SduLength;
	/** <@brief data ptr*/
	P2VAR(uint8, AUTOMATIC, PDUR_CONST_PBCFG) TxBufferData;
	/** <@brief check the buffer wether is used*/
	boolean used;
    #if(STD_ON == PDUR_META_DATA_SUPPORT)
	/** <@brief matadata ptr*/
	uint8 MetaData[4];
    #endif/* STD_ON == PDUR_META_DATA_SUPPORT */
}PduR_TxBufferType;

/**
 * @brief pdu buffer table struct
 */
typedef struct
{
	/** <@brief max length of pdu buffer */
	uint32 PduRPduMaxLength;
	/** <@brief buffer depth for TP SF:always 1 */
	uint8 PduRTxBufferDepth;
	/** <@brief ref pdu buffer */
	P2VAR(PduR_TxBufferType, AUTOMATIC, PDUR_CONST_PBCFG) PduRTxBufferRef;
}PduR_TxBufferTableType;

#endif/* STD_OFF == PDUR_ZERO_COST_OPERATION */


typedef P2FUNC(Std_ReturnType, PDUR_APPL_CODE, PduRLowTransmitFunctionType)
(PduIdType TxPduId, P2CONST(PduInfoType, AUTOMATIC, AUTOMATIC) PduInfoPtr);

typedef P2FUNC(void, PDUR_APPL_CODE, PduRUpRxIndicationFunctionType)
(PduIdType RxPduId, P2CONST(PduInfoType, AUTOMATIC, AUTOMATIC) PduInfoPtr);

typedef P2FUNC(void, PDUR_APPL_CODE, PduRUpTpRxIndicationFunctionType)
(PduIdType RxPduId, Std_ReturnType result);

typedef P2FUNC(BufReq_ReturnType, PDUR_APPL_CODE, PduRUpTpStartOfReceptionFunctionType)
(PduIdType RxPduId, P2CONST(PduInfoType, AUTOMATIC, AUTOMATIC) PduInfoPtr,PduLengthType TpSduLength,\
P2VAR(PduLengthType, AUTOMATIC, COM_APPL_DATA) bufferSizePtr);

typedef P2FUNC(BufReq_ReturnType, PDUR_APPL_CODE, PduRUpTpCopyRxDataFunctionType)
(PduIdType RxPduId, P2CONST(PduInfoType, AUTOMATIC, AUTOMATIC) PduInfoPtr,\
P2VAR(PduLengthType, AUTOMATIC, COM_APPL_DATA) bufferSizePtr);

typedef P2FUNC(void, PDUR_APPL_CODE, PduRUpTxConfirmationFunctionType)
(PduIdType TxPduId);

typedef P2FUNC(Std_ReturnType, PDUR_APPL_CODE, PduRUpTriggerTransmitFunctionType)
(PduIdType TxPduId, P2VAR(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);

typedef P2FUNC(BufReq_ReturnType, PDUR_APPL_CODE, PduRUpTpCopyTxDataFunctionType)
(
	PduIdType id,
	P2CONST(PduInfoType, AUTOMATIC, DCM_CONST)info,
	P2VAR(RetryInfoType,AUTOMATIC,DCM_VAR)retry,
	P2VAR(PduLengthType,AUTOMATIC,DCM_VAR) availableDataPtr
);

typedef P2FUNC(void, PDUR_APPL_CODE, PduRUpTpTxConfirmationFunctionType)
(PduIdType TxPduId,Std_ReturnType result);

typedef P2FUNC(Std_ReturnType, PDUR_APPL_CODE, PduRCancelTransmitFunctionType)(PduIdType TxPduId);

typedef P2FUNC(Std_ReturnType, PDUR_APPL_CODE, PduRCancelReceiveFunctionType)(PduIdType RxPduId);

typedef P2FUNC(Std_ReturnType, PDUR_APPL_CODE, PduRChangeParameterFunctionType)
(PduIdType TxPduId,TPParameterType parameter,uint16 value);


/* @req [SWS_PduR_00743] [SWS_PduR_00241]*/
/**
 * @brief config struct
 */
typedef struct
{
	/** <@brief routing path config */
	P2CONST(PduRRoutingPathGroupType, AUTOMATIC, PDUR_CONST_PBCFG) PduRRoutingPathGroupRef;
	/** <@brief routing config */
	P2CONST(PduRRoutingPathType, AUTOMATIC, PDUR_CONST_PBCFG) PduRRoutingTableRef;
	/** <@brief source pdu config */
	P2CONST(PduRSrcPduType, AUTOMATIC, PDUR_CONST_PBCFG) PduRSrcPduRef;
	/** <@brief pdur dest pdur config used for confirmation */
	P2CONST(PduRDestPduType, AUTOMATIC, PDUR_CONST_PBCFG) PduRDestPduRef;
}PduR_PBConfigType;

/*====================================================================================================*
 *                                    GLOBAL VARIABLE DECLARATIONS
 *====================================================================================================*/

/*====================================================================================================*
 *                                        FUNCTION PROTOTYPES
 *====================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif  /* end of PDUR_TYPES_H */

/** @} */
