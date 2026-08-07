/**
 * @file        PduR_Internal.h
 * @brief       The module internal header file, including the function service of this module
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
#ifndef  PDUR_INTERNAL_H
#define  PDUR_INTERNAL_H

#ifdef __cplusplus
extern "C"{
#endif

/*====================================================================================================*
 *                                           INCLUDE FILES
 *====================================================================================================*/
#include "PduR_Cfg.h"

#include "Std_Types.h"
/*====================================================================================================*
 *                                  HEADER FILE VERSION INFORMATION
 *====================================================================================================*/
#define PDUR_INTERNAL_VENDOR_ID               			0U
#define PDUR_INTERNAL_MODULE_ID               			51U
#define PDUR_INTERNAL_AR_RELEASE_MAJOR_VERSION			4U
#define PDUR_INTERNAL_AR_RELEASE_MINOR_VERSION			2U
#define PDUR_INTERNAL_AR_RELEASE_REVISION_VERSION		2U
#define PDUR_INTERNAL_SW_MAJOR_VERSION      			1U
#define PDUR_INTERNAL_SW_MINOR_VERSION      			2U
#define PDUR_INTERNAL_SW_PATCH_VERSION      			0U

/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/
/* Check if current file and PduR_Cfg.h header file are of the same vendor */
#if(PDUR_INTERNAL_VENDOR_ID != PDUR_CFG_VENDOR_ID )
#error "PduR_Internal.h and PduR_Cfg.h have different vendor id"
#endif

#if(\
      (PDUR_INTERNAL_AR_RELEASE_MAJOR_VERSION != PDUR_CFG_AR_RELEASE_MAJOR_VERSION) || \
      (PDUR_INTERNAL_AR_RELEASE_MINOR_VERSION != PDUR_CFG_AR_RELEASE_MINOR_VERSION) || \
      (PDUR_INTERNAL_AR_RELEASE_REVISION_VERSION != PDUR_CFG_AR_RELEASE_REVISION_VERSION) \
      )
#error "AutoSar Version Number of PduR_Internal.h and PduR_Cfg.h are different "
#endif

/* Check if current file and PduR_Cfg.h header file are of the same software version */
#if(\
      (PDUR_INTERNAL_SW_MAJOR_VERSION != PDUR_CFG_SW_MAJOR_VERSION) || \
      (PDUR_INTERNAL_SW_MINOR_VERSION != PDUR_CFG_SW_MINOR_VERSION) ||\
	  (PDUR_INTERNAL_SW_PATCH_VERSION != PDUR_CFG_SW_PATCH_VERSION)\
      )
#error "Software Version Number of PduR_Internal.h and PduR_Cfg.h are different "
#endif

#ifndef DISABLE_INTERMOD_VERSION_CHECK
#if(\
      (PDUR_INTERNAL_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
      (PDUR_INTERNAL_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION) \
      )
#error "AutoSar Version Number of PduR_Internal.h and Std_Types.h are different "
#endif
#endif

/*====================================================================================================*
 *                                             CONSTANTS
 *====================================================================================================*/

/*====================================================================================================*
 *                                         DEFINES AND MACROS
 *====================================================================================================*/

/*====================================================================================================*
 *                                               ENUMS
 *====================================================================================================*/

/*====================================================================================================*
 *                                   STRUCTURES AND OTHER TYPEDEFS
 *====================================================================================================*/

/*====================================================================================================*
 *                                    GLOBAL VARIABLE DECLARATIONS
 *====================================================================================================*/

/*====================================================================================================*
 *                                        FUNCTION PROTOTYPES
 *====================================================================================================*/
#if(STD_OFF == PDUR_ZERO_COST_OPERATION)
#define PDUR_START_SEC_CODE
#include "PduR_MemMap.h"
#if(STD_ON == PDUR_TP_SUPPORT)

FUNC(BufReq_ReturnType, PDUR_CODE)
PduR_StartOfReceptionToOneTpHandle(
    PduIdType SrcPduId,
	PduIdType DestPduId,
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
	PduLengthType Length,
	P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
);
/*1:n Rx Tp Pdu GateWay(more than one Tp Module,zero or one Up Module),when start of reception*/
FUNC(BufReq_ReturnType, PDUR_CODE)
PduR_StartOfReceptionToMoreModuleHandle(
	PduIdType SrcPduId,
	uint8 DestPduSum,
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
	PduLengthType Length,
	P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
);
/*at least one dest pdu state is enabled*/
FUNC(boolean, PDUR_CODE)
PduR_AtLeastOneDestIsEnabled(
	uint16 PduRSrcPduId
);
/*Rx Tp Pdu gateway to only one Tp Module Pdu handle,when copy Rx Data*/
extern FUNC(BufReq_ReturnType, PDUR_CODE)
PduR_CopyRxDataToOneTpHandle(
	PduIdType SrcPduId,
	PduIdType DestPduId,
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
	P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA)BufferSizePtr
);
/*1:n Rx Tp Pdu GateWay(more than one Tp Module,zero or one Up Module),when copy Rx Data*/
FUNC(BufReq_ReturnType, PDUR_CODE)
PduR_CopyRxDataToMoreModuleHandle(
	PduIdType SrcPduId,
	uint8 DestPduSum,
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
	P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA)BufferSizePtr
);
/*Rx Tp Pdu gateway to only one Tp Module Pdu handle,when Rx Indication*/
FUNC(void, PDUR_CODE)
PduR_RxIndicationToOneTpHandle(
	PduIdType SrcPduId,
	PduIdType DestPduId
);
/*1:n Rx Tp Pdu GateWay(more than one Tp Module,zero or one Up Module),when Rx Indication*/
FUNC(void, PDUR_CODE)
PduR_RxIndicationToMoreModuleHandle(
	PduIdType SrcPduId,
	uint8 DestPduSum
);
/*one Tp Pdu route to one Tp Pdu,the dest pdu copy tx data handle*/
FUNC(BufReq_ReturnType, PDUR_CODE)
PduR_OneDestCopyTxDataFromTpHandle(
	PduIdType SrcPduId,
	PduIdType DestPduId,
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
	P2VAR(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry,
	P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr
);
/*one Tp Pdu route to more module Pdus,one dest Tp Pdu copy tx data handle*/
FUNC(BufReq_ReturnType, PDUR_CODE)
PduR_MoreDestCopyTxDataFromTpHandle(
	PduIdType SrcPduId,
	PduIdType DestPduId,
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
	P2VAR(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry,
	P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr
);

/*1:n(n>1)Tp route,at least one dest pdu is still need transmit,return TRUE*/
FUNC(boolean, PDUR_CODE)
PduR_AtLeastOneDestIsNotTxConfirm(
	uint16 PduRSrcPduId
);
#endif/* STD_ON == PDUR_TP_SUPPORT */

/*copy data from source to dest*/
FUNC(void, PDUR_CODE)
PduR_Memcpy(
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) dest,
    P2CONST(uint8, AUTOMATIC, AUTOMATIC) source,
    uint16 length
);
#define PDUR_STOP_SEC_CODE
#include "PduR_MemMap.h"

#endif/* STD_OFF == PDUR_ZERO_COST_OPERATION */

#ifdef __cplusplus
}
#endif

#endif/* end of PDUR_INTERNAL_H */

/** @} */

