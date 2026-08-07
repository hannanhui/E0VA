/**
 * @file        PduR_SecOC.h
 * @brief       Header file of PduR, used for SecOC callback notification.
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

#ifndef PDUR_SECOC_H
#define PDUR_SECOC_H

#ifdef __cplusplus
extern "C"{
#endif

/*====================================================================================================*
 *                                           INCLUDE FILES
 *====================================================================================================*/
#include "PduR_Cfg.h"

#include "Std_Types.h"
/*====================================================================================================*
 *                                         SOURCE FILE VERSION INFORMATION
 *====================================================================================================*/
#define PDUR_SECOC_VENDOR_ID               			0U
#define PDUR_SECOC_MODULE_ID               			51U
#define PDUR_SECOC_AR_RELEASE_MAJOR_VERSION			4U
#define PDUR_SECOC_AR_RELEASE_MINOR_VERSION			2U
#define PDUR_SECOC_AR_RELEASE_REVISION_VERSION		2U
#define PDUR_SECOC_SW_MAJOR_VERSION      			1U
#define PDUR_SECOC_SW_MINOR_VERSION      			2U
#define PDUR_SECOC_SW_PATCH_VERSION      			0U

/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/
/* Check if current file and PduR_Cfg.h header file are of the same vendor */
#if(PDUR_SECOC_VENDOR_ID != PDUR_CFG_VENDOR_ID )
#error "PduR_SecOC.h and PduR_Cfg.h have different vendor id"
#endif

#if(\
      (PDUR_SECOC_AR_RELEASE_MAJOR_VERSION != PDUR_CFG_AR_RELEASE_MAJOR_VERSION) || \
      (PDUR_SECOC_AR_RELEASE_MINOR_VERSION != PDUR_CFG_AR_RELEASE_MINOR_VERSION) || \
      (PDUR_SECOC_AR_RELEASE_REVISION_VERSION != PDUR_CFG_AR_RELEASE_REVISION_VERSION) \
      )
#error "AutoSar Version Number of PduR_SecOC.h and PduR_Cfg.h are different "
#endif

/* Check if current file and PduR_Cfg.h header file are of the same software version */
#if(\
      (PDUR_SECOC_SW_MAJOR_VERSION != PDUR_CFG_SW_MAJOR_VERSION) || \
      (PDUR_SECOC_SW_MINOR_VERSION != PDUR_CFG_SW_MINOR_VERSION) ||\
	  (PDUR_SECOC_SW_PATCH_VERSION != PDUR_CFG_SW_PATCH_VERSION)\
      )
#error "Software Version Number of PduR_SecOC.h and PduR_Cfg.h are different "
#endif

#ifndef DISABLE_INTERMOD_VERSION_CHECK
#if(\
      (PDUR_SECOC_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
      (PDUR_SECOC_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION) \
      )
#error "AutoSar Version Number of PduR_SecOC.h and Std_Types.h are different "
#endif
#endif

/*====================================================================================================*
 *                                             CONSTANTS
 *====================================================================================================*/

/*====================================================================================================*
 *                                         DEFINES AND MACROS
 *====================================================================================================*/
#if(STD_ON == PDUR_SECOC_SUPPORT)
/* Zero cost enable */
#if(STD_ON == PDUR_ZERO_COST_OPERATION)
#else

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
extern FUNC(Std_ReturnType, PDUR_SECOC_TRANSMIT_CODE)
PduR_SecOCTransmit(
	VAR(PduIdType, PDUR_VAR) id,
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info
);

#if(STD_ON == PDUR_SECOC_CANCEL_TRANSMIT)
extern FUNC(Std_ReturnType, PDUR_SECOC_CANCELTRANSMIT_CODE)
PduR_SecOCCancelTransmit(
	VAR(PduIdType, PDUR_VAR) id
);
#endif/* STD_ON == PDUR_SECOC_CANCEL_TRANSMIT */

extern FUNC(void, PDUR_SECOC_RXINDICATION_CODE)
PduR_SecOCRxIndication(
	VAR(PduIdType, PDUR_VAR) RxPduId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr
);

#if(STD_ON == PDUR_SECOC_TX_CONFIRMATION)
extern FUNC(void, PDUR_SECOC_TXCONFIRMATION_CODE)
PduR_SecOCTxConfirmation(
	VAR(PduIdType, PDUR_VAR) TxPduId
);

#endif/* STD_ON == PDUR_SECOC_TX_CONFIRMATION */

#endif /* STD_OFF == PDUR_ZERO_COST_OPERATION */

#define PDUR_STOP_SEC_CODE
#include "PduR_MemMap.h"
#endif /* STD_ON == PDUR_SECOC_SUPPORT */

#ifdef __cplusplus
}
#endif

#endif  /* end of PDUR_SECOC_H */

/** @} */
