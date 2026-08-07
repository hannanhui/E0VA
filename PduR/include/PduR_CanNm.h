/**
 * @file        PduR_CanNm.h
 * @brief       Header file of PduR, used for CanNm callback notification.
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

#ifndef PDUR_CANNM_H
#define PDUR_CANNM_H

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
#define PDUR_CANNM_VENDOR_ID               		0U
#define PDUR_CANNM_MODULE_ID               		51U
#define PDUR_CANNM_AR_RELEASE_MAJOR_VERSION		4U
#define PDUR_CANNM_AR_RELEASE_MINOR_VERSION		2U
#define PDUR_CANNM_AR_RELEASE_REVISION_VERSION		2U
#define PDUR_CANNM_SW_MAJOR_VERSION      			1U
#define PDUR_CANNM_SW_MINOR_VERSION      			2U
#define PDUR_CANNM_SW_PATCH_VERSION      			0U

/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/
/* Check if current file and PduR_Cfg.h header file are of the same vendor */
#if(PDUR_CANNM_VENDOR_ID != PDUR_CFG_VENDOR_ID )
#error "PduR_CanNm.h and PduR_Cfg.h have different vendor id"
#endif

#if(\
      (PDUR_CANNM_AR_RELEASE_MAJOR_VERSION != PDUR_CFG_AR_RELEASE_MAJOR_VERSION) || \
      (PDUR_CANNM_AR_RELEASE_MINOR_VERSION != PDUR_CFG_AR_RELEASE_MINOR_VERSION) || \
      (PDUR_CANNM_AR_RELEASE_REVISION_VERSION != PDUR_CFG_AR_RELEASE_REVISION_VERSION) \
      )
#error "AutoSar Version Number of PduR_CanNm.h and PduR_Cfg.h are different "
#endif

/* Check if current file and PduR_Cfg.h header file are of the same software version */
#if(\
      (PDUR_CANNM_SW_MAJOR_VERSION != PDUR_CFG_SW_MAJOR_VERSION) || \
      (PDUR_CANNM_SW_MINOR_VERSION != PDUR_CFG_SW_MINOR_VERSION) ||\
	  (PDUR_CANNM_SW_PATCH_VERSION != PDUR_CFG_SW_PATCH_VERSION)\
      )
#error "Software Version Number of PduR_CanNm.h and PduR_Cfg.h are different "
#endif


#ifndef DISABLE_INTERMOD_VERSION_CHECK
#if(\
      (PDUR_CANNM_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
      (PDUR_CANNM_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION) \
      )
#error "AutoSar Version Number of PduR_CanNm.h and Std_Types.h are different "
#endif
#endif

/*====================================================================================================*
 *                                             CONSTANTS
 *====================================================================================================*/

/*====================================================================================================*
 *                                         DEFINES AND MACROS
 *====================================================================================================*/
#if(STD_ON == PDUR_CANNM_SUPPORT)
/* Zero cost enable */
#if(STD_ON == PDUR_ZERO_COST_OPERATION)
#if defined(PDUR_COM_SUPPORT == STD_ON)
#define PduR_CanNmRxIndication Com_RxIndication
#define PduR_CanNmTxConfirmation Com_TxConfirmation
#define PduR_CanNmTriggerTransmit Com_TriggerTransmit
#else
#error "The Com module has not been configurated."
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
extern FUNC(void, PDUR_CODE)
PduR_CanNmRxIndication(
	VAR(PduIdType, PDUR_VAR) RxPduId,
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr
);

#if(STD_ON == PDUR_CANNM_TX_CONFIRMATION)
extern FUNC(void, PDUR_CODE)
PduR_CanNmTxConfirmation(
	VAR(PduIdType, PDUR_VAR) TxPduId
);
#endif/* STD_ON == PDUR_CANNM_TX_CONFIRMATION */

#if(STD_ON == PDUR_CANNM_TRIGGER_TRANSMIT)
extern FUNC(Std_ReturnType, PDUR_CODE)
PduR_CanNmTriggerTransmit(
	VAR(PduIdType, PDUR_VAR) TxPduId,
	P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr
);
#endif/* STD_ON == PDUR_CANNM_TRIGGER_TRANSMIT */

#endif /* STD_ON == PDUR_ZERO_COST_OPERATION */

#define PDUR_STOP_SEC_CODE
#include "PduR_MemMap.h"

#endif /* STD_ON == PDUR_CANNM_SUPPORT */

#ifdef __cplusplus
}
#endif

#endif /* PDUR_CANNM_H */

/** @} */
