/**
 * @file        Com_cbk.h
 * @brief       Header file of Com, used for Com callback notification.
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

#ifndef  COM_CBK_H/* PRQA S 0828 EOF # violate MISRA_2004_Rule_1.1:The program has no more than eight layers*/
#define  COM_CBK_H

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
#define COM_CBK_VENDOR_ID               		0U
#define COM_CBK_MODULE_ID               		50U
#define COM_CBK_AR_RELEASE_MAJOR_VERSION		4U
#define COM_CBK_AR_RELEASE_MINOR_VERSION		2U
#define COM_CBK_AR_RELEASE_REVISION_VERSION		2U
#define COM_CBK_SW_MAJOR_VERSION      			1U
#define COM_CBK_SW_MINOR_VERSION      			2U
#define COM_CBK_SW_PATCH_VERSION      			0U

/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/
/* Check if current file and Com.h header file are of the same vendor */
#if(COM_CBK_VENDOR_ID != COM_VENDOR_ID )
#error "Com_cbk.h and Com.h have different vendor id"
#endif

#if(\
      (COM_CBK_AR_RELEASE_MAJOR_VERSION != COM_AR_RELEASE_MAJOR_VERSION) || \
      (COM_CBK_AR_RELEASE_MINOR_VERSION != COM_AR_RELEASE_MINOR_VERSION) || \
      (COM_CBK_AR_RELEASE_REVISION_VERSION != COM_AR_RELEASE_REVISION_VERSION) \
      )
#error "AutoSar Version Number of Com_cbk.h and Com.h are different "
#endif

/* Check if current file and Com.h header file are of the same software version */
#if(\
      (COM_CBK_SW_MAJOR_VERSION != COM_SW_MAJOR_VERSION) || \
      (COM_CBK_SW_MINOR_VERSION != COM_SW_MINOR_VERSION) ||\
	  (COM_CBK_SW_PATCH_VERSION != COM_SW_PATCH_VERSION)\
      )
#error "Software Version Number of Com_cbk.h and Com.h are different "
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

FUNC(Std_ReturnType , COM_CODE)
Com_TriggerTransmit(PduIdType TxPduId,P2VAR(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);

FUNC(void ,COM_CODE)
Com_RxIndication(PduIdType RxPduId,P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);

FUNC(void,COM_CODE)
Com_TpRxIndication(PduIdType id,Std_ReturnType result);

FUNC(void, COM_CODE)
Com_TpTxConfirmation(PduIdType id,Std_ReturnType result);

FUNC(void, COM_CODE)
Com_TxConfirmation(PduIdType TxPduId);

FUNC(BufReq_ReturnType, COM_CODE)
Com_StartOfReception
(
	PduIdType id,
	P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) info,
	PduLengthType TpSduLength,
	P2VAR(PduLengthType, AUTOMATIC, COM_APPL_DATA) bufferSizePtr
);

FUNC(BufReq_ReturnType , COM_CODE)
Com_CopyRxData(
	PduIdType id,
	P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) info,
	P2VAR(PduLengthType, AUTOMATIC, COM_APPL_DATA) bufferSizePtr
);

FUNC(BufReq_ReturnType , COM_CODE)
Com_CopyTxData(
	PduIdType id,
	P2CONST(PduInfoType, AUTOMATIC, DCM_CONST)info,
	P2VAR(RetryInfoType,AUTOMATIC,DCM_VAR)retry,
	P2VAR(PduLengthType,AUTOMATIC,DCM_VAR) availableDataPtr
		);

#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* COM_CBK_H */

/** @} */
