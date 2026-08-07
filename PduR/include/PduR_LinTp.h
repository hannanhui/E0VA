/**
 * @file        PduR_LinTp.h
 * @brief       Header file of PduR, used for LinTp callback notification.
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
#ifndef  PDUR_LINTP_H
#define  PDUR_LINTP_H

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
#define PDUR_LINTP_VENDOR_ID               		0U
#define PDUR_LINTP_MODULE_ID               		51U
#define PDUR_LINTP_AR_RELEASE_MAJOR_VERSION		4U
#define PDUR_LINTP_AR_RELEASE_MINOR_VERSION		2U
#define PDUR_LINTP_AR_RELEASE_REVISION_VERSION		2U
#define PDUR_LINTP_SW_MAJOR_VERSION      			1U
#define PDUR_LINTP_SW_MINOR_VERSION      			2U
#define PDUR_LINTP_SW_PATCH_VERSION      			0U

/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/
/* Check if current file and PduR_Cfg.h header file are of the same vendor */
#if(PDUR_LINTP_VENDOR_ID != PDUR_CFG_VENDOR_ID )
#error "PduR_LinTp.h and PduR_Cfg.h have different vendor id"
#endif

#if(\
      (PDUR_LINTP_AR_RELEASE_MAJOR_VERSION != PDUR_CFG_AR_RELEASE_MAJOR_VERSION) || \
      (PDUR_LINTP_AR_RELEASE_MINOR_VERSION != PDUR_CFG_AR_RELEASE_MINOR_VERSION) || \
      (PDUR_LINTP_AR_RELEASE_REVISION_VERSION != PDUR_CFG_AR_RELEASE_REVISION_VERSION) \
      )
#error "AutoSar Version Number of PduR_LinTp.h and PduR_Cfg.h are different "
#endif

/* Check if current file and PduR_Cfg.h header file are of the same software version */
#if(\
      (PDUR_LINTP_SW_MAJOR_VERSION != PDUR_CFG_SW_MAJOR_VERSION) || \
      (PDUR_LINTP_SW_MINOR_VERSION != PDUR_CFG_SW_MINOR_VERSION) ||\
	  (PDUR_LINTP_SW_PATCH_VERSION != PDUR_CFG_SW_PATCH_VERSION)\
      )
#error "Software Version Number of PduR_LinTp.h and PduR_Cfg.h are different "
#endif

#ifndef DISABLE_INTERMOD_VERSION_CHECK
#if(\
      (PDUR_LINTP_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
      (PDUR_LINTP_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION) \
      )
#error "AutoSar Version Number of PduR_LinTp.h and Std_Types.h are different "
#endif
#endif

/*====================================================================================================*
 *                                             CONSTANTS
 *====================================================================================================*/

/*====================================================================================================*
 *                                         DEFINES AND MACROS
 *====================================================================================================*/
#if(STD_ON == PDUR_LINTP_SUPPORT)
/* Zero cost enable */
#if(STD_ON == PDUR_ZERO_COST_OPERATION)
#if defined(PDUR_DCM_SUPPORT == STD_ON)
#define PduR_LinTpStartOfReception Dcm_StartOfReception
#define PduR_LinTpCopyRxData Dcm_CopyRxData
#define PduR_LinTpRxIndication Dcm_TpRxIndication
#define PduR_LinTpCopyTxData Dcm_CopyTxData
#define PduR_LinTpTxConfirmation Dcm_TpTxConfirmation
#else
#error "The Dcm module has not been configurated."
#endif /* defined(PDUR_COM_SUPPORT == STD_ON) */

#else	/*STD_ON == PDUR_ZERO_COST_OPERATION*/
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
#define PDUR_START_SEC_CODE
#include "PduR_MemMap.h"
extern FUNC(BufReq_ReturnType, PDUR_CODE)
PduR_LinTpStartOfReception(
	VAR(PduIdType, PDUR_VAR) id,
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
	PduLengthType TpSduLength,
	P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
);

extern FUNC(BufReq_ReturnType, PDUR_CODE)
PduR_LinTpCopyRxData(
	VAR(PduIdType, PDUR_VAR) id,
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
	P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
);

extern FUNC(void, PDUR_CODE)
PduR_LinTpRxIndication(
	VAR(PduIdType, PDUR_VAR) id,
	VAR(Std_ReturnType, PDUR_VAR) result
);

extern FUNC(BufReq_ReturnType, PDUR_CODE)
PduR_LinTpCopyTxData(
	VAR(PduIdType, PDUR_VAR) id,
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
	P2VAR(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry,
	P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr
);

extern FUNC(void, PDUR_CODE)
PduR_LinTpTxConfirmation(
	VAR(PduIdType, PDUR_VAR) id,
	VAR(Std_ReturnType, PDUR_VAR) result
);

#endif /*STD_ON == PDUR_ZERO_COST_OPERATION*/

#define PDUR_STOP_SEC_CODE
#include "PduR_MemMap.h"
#endif /*STD_ON == PDUR_LINTP_SUPPORT*/

#ifdef __cplusplus
}
#endif

#endif /* end of PDUR_LINTP_H */

/** @} */
