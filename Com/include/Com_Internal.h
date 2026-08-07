/**
 * @file       	Com_Internal.h
 * @brief       Com module internal header file
 * @version     1.2.0
 * @addtogroup  Com
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

/* PRQA S 0292, 0288, 1503, 1505, 0857, 0791, 0828, 0647 EOF #
 *
 * 1.0292 -- Violates MISRA 2004 Required Rule 3.1, Source file has comments containing one of the*
 * characters '$', '@' or '`'.
 *
 * 2.0288 -- Violates MISRA 2004 Required Rule 3.1, Source file has comments containing characters*
 * which are not members of the basic source character set.
 *
 * 3.1503 -- Violates MISRA 2004 Required Rule 14.1, The function is defined but is not used within*
 *  this project.
 *
 * 4.1505 -- Violates MISRA 2004 Required Rule 8.10, The function is only referenced in the
 * translation* unit where it is defined.
 *
 * 5.0857 -- Violates MISRA 2004 Required Rule 1.1, Number of macro definitions exceeds 1024 -
 * program* does not conform strictly to ISO:C90.
 *
 * 6.0791 -- Violates MISRA 2004 Required Rule 5.1, Macro identifier does not differ from other macro*
 *  identifier(s) within the specified number of significant characters.
 *
 * 7.0828 -- Violates MISRA 2004 Required Rule 1.1, More than 8 levels of nested conditional
 * inclusion* - program does not conform strictly to ISO:C90.
 *
 * 8.0647 -- Violates MISRA 2004 Required Rule 1.1, Number of enumeration constants exceeds 127-program
 * does not conform strictly to ISO:C90.
 *
 * @page misra_violations MISRA-C:2004 violations
 */

#ifndef COM_INTERNAL_H
#define COM_INTERNAL_H

#ifdef __cplusplus
extern "C"{
#endif

/*====================================================================================================*
 *                                           INCLUDE FILES
 *====================================================================================================*/
#include "Com.h"

/*====================================================================================================*
 *                                  HEADER FILE VERSION INFORMATION
 *====================================================================================================*/
#define COM_INTERNAL_VENDOR_ID               		0U
#define COM_INTERNAL_AR_RELEASE_MAJOR_VERSION		4U
#define COM_INTERNAL_AR_RELEASE_MINOR_VERSION		2U
#define COM_INTERNAL_AR_RELEASE_REVISION_VERSION	2U
#define COM_INTERNAL_SW_MAJOR_VERSION      			1U
#define COM_INTERNAL_SW_MINOR_VERSION      			2U
#define COM_INTERNAL_SW_PATCH_VERSION      			0U

/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/
#if(COM_INTERNAL_VENDOR_ID != COM_VENDOR_ID )
#error "Com_Internal.h and Com.h have different vendor id"
#endif

#if(\
      (COM_INTERNAL_AR_RELEASE_MAJOR_VERSION != COM_AR_RELEASE_MAJOR_VERSION) || \
      (COM_INTERNAL_AR_RELEASE_MINOR_VERSION != COM_AR_RELEASE_MINOR_VERSION) || \
      (COM_INTERNAL_AR_RELEASE_REVISION_VERSION != COM_AR_RELEASE_REVISION_VERSION) \
      )
#error "AutoSar Version Number of Com_Internal.h and Com.h are different "
#endif

/* Check if current file and Com.h header file are of the same software version */
#if(\
      (COM_INTERNAL_SW_MAJOR_VERSION != COM_SW_MAJOR_VERSION) || \
      (COM_INTERNAL_SW_MINOR_VERSION != COM_SW_MINOR_VERSION) ||\
	  (COM_INTERNAL_SW_PATCH_VERSION != COM_SW_PATCH_VERSION)\
      )
#error "Software Version Number of Com_Internal.h and Com.h are different "
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
#define COM_START_SEC_CODE
#include "Com_MemMap.h"

extern FUNC(void,COM_CODE)
Com_ErrorNotification(PduIdType PduId);

extern FUNC(void , COM_CODE)
Com_InitSignalBuffer(
	VAR(Com_SignalType, COM_VAR) SignalType,
	VAR(uint16, COM_VAR) SignalInitValueId,
	VAR(uint16, COM_VAR) SignalLength
);

extern FUNC(boolean, COM_CODE)
Com_CalDynChange(
	PduIdType PduId,
	uint16 InitValueId,
	P2CONST(void, AUTOMATIC, COM_APPL_CONST) SignalNewDataPtr,
	uint16 Length
);

extern FUNC(void , COM_CODE)
Com_GetNextCounterValue(VAR(boolean, COM_VAR) IsTxPdu,VAR(PduIdType, COM_VAR) PduId);

extern FUNC(void,COM_CODE)
Com_ClearUpdates(PduIdType TxIpduId);

#if(COM_NUMBER_OF_TXIPDU > 0)
extern FUNC(void,COM_CODE)
Com_TxIpduControl(PduIdType TxPduId,boolean initialize);
#endif/* COM_IPDUGROUP_NUMBER > 0u */

extern FUNC(void , COM_CODE)
Com_HandleTxIpduTMS(VAR(PduIdType, COM_VAR) TxPduId,P2VAR(uint16, AUTOMATIC, COM_VAR) RptNum);

extern FUNC(uint8 , COM_CODE)
Com_HandleTxSignal(Com_SignalIdType SignalId, boolean ValueChanged);

extern FUNC(boolean , COM_CODE)
Com_CalSignalValueIsChange(uint16 SignalId, P2CONST(void, AUTOMATIC, COM_APPL_CONST) SignalNewDataPtr);

extern FUNC(boolean , COM_CODE)
Com_CalGroupSignalValueIsChange(
	uint16 GroupSignalId,
	P2CONST(void, AUTOMATIC, COM_APPL_CONST) SignalNewDataPtr
);

extern FUNC(void , COM_CODE)
Com_InitSignalRunTimeBuffer(void);

extern FUNC(void, COM_CODE)
Com_InitGroupSignalRunTimeBuffer(void);

extern FUNC(void, COM_CODE)
Com_InitRxPduBuffer(void);

extern FUNC(void, COM_CODE)
Com_InitTxPduBuffer(void);

extern FUNC(uint16 , COM_CODE)
Com_GetNextPduBufferIndex(
	VAR(Com_SignalEndiannessType, COM_VAR) SignalEndianness,
	VAR(Com_SignalType, COM_VAR) IpduBufferIndex
);

#if(COM_NUMBER_OF_TIMEOUT_SIGNAL > 0u)
extern FUNC(void , COM_CODE)
Com_ResetRxPduDeadlineMonitorTime(
	VAR(PduIdType, COM_VAR) IpduId
);
#endif/* COM_NUMBER_OF_RXSIGNALGROUP + COM_NUMBER_OF_RXSIGNAL > 0u */

#if(COM_NUMBER_OF_TIMEOUT_SIGNAL > 0)
extern FUNC(void , COM_CODE)
Com_ClearRxPduDeadlineMonitorTime(
	VAR(PduIdType, COM_VAR) PduId
);
#endif/* COM_NUMBER_OF_RXSIGNALGROUP + COM_NUMBER_OF_RXSIGNAL > 0u */

extern FUNC(void , COM_CODE)
Com_SendPdu(PduIdType PduId);

extern FUNC(boolean , COM_CODE)
Com_CalPduTMS(VAR(PduIdType, COM_VAR) PduId);

extern FUNC(void,COM_CODE)
Com_GwSignal(
	Com_SignalIdType GwMappingId,
	Com_GWSignalType GwSourceSignalType,
	Com_SignalIdType GwSourceSignalId
);

extern FUNC(void , COM_CODE)
Com_CalOutsideTMC
(
	VAR(Com_SignalType, COM_VAR) SignalType,
	VAR(uint64, COM_VAR) SignalValue,
	P2CONST(Com_FilterType, AUTOMATIC, COM_APPL_CONST) ComFilter,
	P2VAR(boolean, AUTOMATIC, COM_VAR) TMC
);

extern FUNC(void , COM_CODE)
Com_CalWithinTMC
(
	VAR(Com_SignalType, COM_VAR) SignalType,
	VAR(uint64, COM_VAR) SignalValue,
	P2CONST(Com_FilterType, AUTOMATIC, COM_APPL_CONST) ComFilter,
	P2VAR(boolean, AUTOMATIC, COM_VAR) TMC
);

#if((COM_NUMBER_OF_RXSIGNALGROUP > 0u) && (COM_NUMBER_OF_TIMEOUT_SIGNAL > 0u))
extern FUNC(void , COM_CODE)
Com_RxGroupSignalMainFunction(PduIdType pduid);
#endif

#if(COM_NUMBER_OF_RXIPDU > 0)
extern FUNC(void, COM_CODE)
Com_HandleRxPduCounter(
	VAR(PduIdType, COM_VAR) RxPduId,
	boolean* allowReceive,
	P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr
);
#endif

#if((COM_NUMBER_OF_RXSIGNAL > 0u) && (COM_NUMBER_OF_TIMEOUT_SIGNAL > 0u))
extern FUNC(void, COM_CODE)
Com_HandleReceiveDm(
	VAR(PduIdType, COM_VAR) RxPduId
);
#endif

#if(COM_NUMBER_OF_RXIPDU > 0u)
extern FUNC(void , COM_CODE)
Com_RxIpduControl(
	VAR(PduIdType, COM_VAR) RxPduId,
	VAR(boolean, COM_VAR) initialize
);
#endif

#if(COM_NUMBER_OF_TIMEOUT_SIGNAL > 0)
extern FUNC(void,COM_CODE)
Com_ResetDMTime(
	VAR(PduIdType, COM_VAR) PduId,
	P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfo
);
#endif

#if(COM_NUMBER_OF_RXIPDU > 0)
extern FUNC(boolean,COM_CODE)
Com_CalCounterIsValid(
	VAR(PduIdType, COM_VAR) PduId,
	VAR(uint8, COM_VAR) CurrentCounterValue
);
#endif

#if(COM_NUMBER_OF_RXIPDU > 0)
extern FUNC(void,COM_CODE)
Com_HandlePdu(
	VAR(PduIdType, COM_VAR) PduId
);
#endif

#if(COM_NUMBER_OF_RXIPDU > 0)
extern FUNC(void,COM_CODE)
Com_HandleReceivePdu(
	VAR(boolean, COM_VAR) allowReceive,
	VAR(PduIdType, COM_VAR) RxPduId
);
#endif

#if(COM_NUMBER_OF_RXIPDU > 0u)
extern FUNC(uint8,COM_CODE)
Com_UnPackCounter(
	VAR(PduIdType, COM_VAR) PduId
);
#endif

extern FUNC(void,COM_CODE)
Com_HandleInvalidPdu(
	VAR(PduIdType, COM_VAR) RxIpduId
);

extern FUNC(void , COM_CODE)
Com_UpdateTMC(
	Com_SignalIdType SignalId,
	PduIdType PduId,
	P2CONST(void, AUTOMATIC, COM_APPL_CONST) TxSignalDataPtr
);

extern FUNC(void , COM_CODE)
Com_PackSignal(Com_SignalIdType SignalId);

#if(COM_NUMBER_OF_TXSIGNALGROUP > 0u)
extern FUNC(void,COM_CODE)
Com_PackSignalGroup(Com_SignalGroupIdType SignalGroupId);
#endif

extern FUNC(void , COM_CODE)
Com_HandleTxSignalProperty
(
	VAR(PduIdType, COM_VAR) PduId,
	VAR(Com_TransferPropertyType, COM_VAR) SignalProperty,
	VAR(boolean, COM_VAR) ValueChanged,
	VAR(boolean, COM_VAR) DmStart,
	VAR(boolean, COM_VAR) SignalDM,
	VAR(uint16, COM_VAR) RptNum
);

extern FUNC(void , COM_CODE)
Com_PackDynSignal(
	VAR(PduIdType, COM_VAR) PduId,
	VAR(uint32, COM_VAR) BitPosition,
	VAR(uint16, COM_VAR) InitValueId,
	VAR(uint16, COM_VAR) SignalLength
);

extern FUNC(void,COM_CODE)
Com_CalCounterValue(PduIdType PduId);

extern FUNC(void,COM_CODE)
Com_Confirmation(VAR(PduIdType, COM_VAR) PduId);

extern FUNC(void,COM_CODE)
Com_TimeOutNotification(PduIdType PduId);

extern FUNC(boolean,COM_CODE)
Com_TxDirect(PduIdType PduId, boolean txMDT);

extern FUNC(boolean,COM_CODE)
Com_TxPeriodic(PduIdType PduId, boolean txMDT);

extern FUNC(boolean,COM_CODE)
Com_TxMix(PduIdType PduId, boolean txMDT);

#if(COM_NUMBER_OF_TXSIGNALGROUP > 0u)
extern FUNC(uint8 , COM_CODE)
Com_HandleTxGroupSignal(
	Com_SignalIdType TxGroupSignalId,
	P2CONST(void, AUTOMATIC, COM_APPL_CONST) SignalDataPtr
);
#endif

#if(COM_NUMBER_OF_TXSIGNALGROUP > 0u)
extern FUNC(uint8 , COM_CODE)
Com_HandleTxDynGroupSignal(
	Com_SignalIdType TxGroupSignalId,
	P2CONST(void, AUTOMATIC, COM_APPL_CONST) SignalDataPtr,
	uint16 DynLength
);
#endif

extern FUNC(Std_ReturnType , COM_CODE)
Com_HandlePassSignal(
	VAR(Com_SignalIdType, COM_VAR) SignalId,
	VAR(PduIdType, COM_VAR) PduId,
	P2CONST(void, AUTOMATIC, COM_APPL_CONST) SignalDataPtr
);

extern FUNC(Std_ReturnType , COM_CODE)
Com_HandlePassDynSignal(
	VAR(Com_SignalIdType, COM_VAR) SignalId,
	VAR(PduIdType, COM_VAR) PduId,
	P2CONST(void, AUTOMATIC, COM_APPL_CONST) SignalDataPtr,
	VAR(uint16, COM_VAR) Length
);

#if(COM_NUMBER_OF_TXIPDU)
extern FUNC(void , COM_CODE)
Com_HandleTransmitResult(
	VAR(PduIdType, COM_VAR) PduId,
	VAR(Std_ReturnType, COM_VAR)Result,
	VAR(uint8, COM_VAR)CounterValue
);
#endif

#if(COM_NUMBER_OF_TXIPDU)
FUNC(void , COM_CODE)
Com_CheckPduIsDelay(
	VAR(PduIdType, COM_VAR) PduId,
	P2VAR(Std_ReturnType, COM_AUTOMATIC, COM_VAR)NeedDelay
);
#endif

#if(COM_NUMBER_OF_TXSIGNALGROUP > 0u)
extern FUNC(Std_ReturnType , COM_CODE)
Com_HandlePassSignalGroup(Com_SignalGroupIdType SignalGroupId, PduIdType PduId);
#endif

#if(COM_NUMBER_OF_MASKNEWDIFFERMASKOLD_SIGNAL > 0u)
FUNC(void,COM_CODE)
Com_CalMaskedNewDiffersMaskedOldTMC
(
	VAR(Com_SignalType, COM_VAR) SignalType,
	VAR(uint64, COM_VAR) SignalValue,
	P2CONST(Com_FilterType, AUTOMATIC, COM_APPL_CONST) ComFilter,
	VAR(uint16, COM_VAR) SignalBufferId,
	P2VAR(boolean, AUTOMATIC, COM_VAR) TMC
);
#endif

#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* COM_INTERNAL_H */
/** @} */


