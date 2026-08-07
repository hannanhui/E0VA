/**
 * @file        PduR_Dcm.h
 * @brief       Header file of PduR, used for Dcm callback notification.
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

#ifndef  PDUR_DCM_H
#define  PDUR_DCM_H

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
#define PDUR_DCM_VENDOR_ID               		0U
#define PDUR_DCM_MODULE_ID               		51U
#define PDUR_DCM_AR_RELEASE_MAJOR_VERSION		4U
#define PDUR_DCM_AR_RELEASE_MINOR_VERSION		2U
#define PDUR_DCM_AR_RELEASE_REVISION_VERSION		2U
#define PDUR_DCM_SW_MAJOR_VERSION      			1U
#define PDUR_DCM_SW_MINOR_VERSION      			2U
#define PDUR_DCM_SW_PATCH_VERSION      			0U

/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/
/* Check if current file and PduR_Cfg.h header file are of the same vendor */
#if(PDUR_DCM_VENDOR_ID != PDUR_CFG_VENDOR_ID )
#error "PduR_Dcm.h and PduR_Cfg.h have different vendor id"
#endif

#if(\
      (PDUR_DCM_AR_RELEASE_MAJOR_VERSION != PDUR_CFG_AR_RELEASE_MAJOR_VERSION) || \
      (PDUR_DCM_AR_RELEASE_MINOR_VERSION != PDUR_CFG_AR_RELEASE_MINOR_VERSION) || \
      (PDUR_DCM_AR_RELEASE_REVISION_VERSION != PDUR_CFG_AR_RELEASE_REVISION_VERSION) \
      )
#error "AutoSar Version Number of PduR_Dcm.h and PduR_Cfg.h are different "
#endif

/* Check if current file and PduR_Cfg.h header file are of the same software version */
#if(\
      (PDUR_DCM_SW_MAJOR_VERSION != PDUR_CFG_SW_MAJOR_VERSION) || \
      (PDUR_DCM_SW_MINOR_VERSION != PDUR_CFG_SW_MINOR_VERSION) ||\
	  (PDUR_DCM_SW_PATCH_VERSION != PDUR_CFG_SW_PATCH_VERSION)\
      )
#error "Software Version Number of PduR_Dcm.h and PduR_Cfg.h are different "
#endif

#ifndef DISABLE_INTERMOD_VERSION_CHECK
#if(\
      (PDUR_DCM_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
      (PDUR_DCM_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION) \
      )
#error "AutoSar Version Number of PduR_Dcm.h and Std_Types.h are different "
#endif

#endif
/*====================================================================================================*
 *                                             CONSTANTS
 *====================================================================================================*/

/*====================================================================================================*
 *                                         DEFINES AND MACROS
 *====================================================================================================*/
#if(STD_ON == PDUR_DCM_SUPPORT)
/* Zero cost enable */
#if(STD_ON == PDUR_ZERO_COST_OPERATION)
#if defined(PDUR_CANTP_SUPPORT == STD_ON)
#define PduR_DcmTransmit CanTp_Transmit
#define PduR_DcmCancelTransmit CanTp_CancelTransmit
#define PduR_DcmChangeParameter CanTp_ChangeParameter
#define PduR_DcmCancelReceive CanTp_CancelReceive
#else
#error "The CanTp module has not been configurated."
#endif /* defined(PDUR_COM_SUPPORT == STD_ON) */

#else /* STD_ON == PDUR_ZERO_COST_OPERATION */
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
/*Only have LoTp,no LoIf*/
extern FUNC(Std_ReturnType, PDUR_CODE)
PduR_DcmTransmit(
	VAR(PduIdType, PDUR_VAR) id,
	P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info
);

#if(STD_ON == PDUR_DCM_CANCEL_TRANSMIT)
extern FUNC(Std_ReturnType, PDUR_CODE)
PduR_DcmCancelTransmit(
	VAR(PduIdType, PDUR_VAR) id
);
#endif/* STD_ON == PDUR_DCM_CANCEL_TRANSMIT */

#if(STD_ON == PDUR_DCM_CHANGE_PARAMETER)
extern FUNC(Std_ReturnType, PDUR_CODE)
PduR_DcmChangeParameter(
	VAR(PduIdType, PDUR_VAR) id,
	VAR(TPParameterType, PDUR_VAR) parameter,
	VAR(uint16, PDUR_VAR) value
);
#endif/* STD_ON == PDUR_DCM_CHANGE_PARAMETER */

#if(STD_ON == PDUR_DCM_CANCEL_RECEIVE)
extern FUNC(Std_ReturnType, PDUR_CODE)
PduR_DcmCancelReceive(
	VAR(PduIdType, PDUR_VAR) id
);
#endif/* STD_ON == PDUR_DCM_CANCEL_RECEIVE */

#endif /* STD_ON == PDUR_ZERO_COST_OPERATION */

#define PDUR_STOP_SEC_CODE
#include "PduR_MemMap.h"

#endif /* STD_ON == PDUR_DCM_SUPPORT */

#ifdef __cplusplus
}
#endif

#endif  /* end of PDUR_DCM_H */

/** @} */
