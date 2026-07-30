/**
 * @file        Dcm_Cbk.h
 * @brief       AUTOSAR 4.2.2 - 4.2.2 driver header file.
 * @details     Dcm driver header file, containing the Autosar API specification and
 *              other variables and functions that are exported by the Dcm driver.
 * @version     1.2.0
 *
 * @addtogroup  Dcm
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

#ifndef DCM_CBK_H
#define DCM_CBK_H

#ifdef __cplusplus
extern "C"{
#endif

/*====================================================================================================*
 *                                           INCLUDE FILES
 *====================================================================================================*/
#include "Dcm_Types.h"
/*====================================================================================================*
 *                                  HEADER FILE VERSION INFORMATION
 *====================================================================================================*/
#define DCM_CBK_VENDOR_ID                           		(0x00U)
#define DCM_CBK_AR_RELEASE_MAJOR_VERSION            		(0x04U)
#define DCM_CBK_AR_RELEASE_MINOR_VERSION            		(0x02U)
#define DCM_CBK_AR_RELEASE_REVISION_VERSION         		(0x02U)
#define DCM_CBK_SW_MAJOR_VERSION                    		(0x01U)
#define DCM_CBK_SW_MINOR_VERSION                    		(0x02U)
#define DCM_CBK_SW_PATCH_VERSION                    		(0x00U)
/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/
/* Check if current file and Dcm_Types header file are of the same vendor */
#if(DCM_CBK_VENDOR_ID != DCM_TYPES_VENDOR_ID )
#error "Dcm_Cbk.h and Dcm_Types.h have different vendor id"
#endif
/* Check if current file and Dcm_Types header file are of the same Autosar version */
#if(\
		(DCM_CBK_AR_RELEASE_MAJOR_VERSION != DCM_TYPES_AR_RELEASE_MAJOR_VERSION) || \
		(DCM_CBK_AR_RELEASE_MINOR_VERSION != DCM_TYPES_AR_RELEASE_MINOR_VERSION) || \
		(DCM_CBK_AR_RELEASE_REVISION_VERSION != DCM_TYPES_AR_RELEASE_REVISION_VERSION) \
)
#error "AutoSar Version Number of Dcm_Cbk.h and Dcm_Types.h are different"
#endif
/* Check if current file and Dcm_Types header file are of the same software version */
#if(\
		(DCM_CBK_SW_MAJOR_VERSION != DCM_TYPES_SW_MAJOR_VERSION) || \
		(DCM_CBK_SW_MINOR_VERSION != DCM_TYPES_SW_MINOR_VERSION) || \
		(DCM_CBK_SW_PATCH_VERSION != DCM_TYPES_SW_PATCH_VERSION) \
)
#error "Software Version Number of Dcm_Cbk.h and Dcm_Types.h are different"
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
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"

/**
 * @req [SWS_Dcm_01066] The file Dcm_Cbk.h shall provide all Typedefinitions and APIs used by other BSW
 * 		modules for direct calls as described in chapter 8.4 Callback Notifications.
 */

FUNC(BufReq_ReturnType, DCM_CODE)Dcm_StartOfReception
(
	PduIdType Id,
	P2CONST(PduInfoType, AUTOMATIC, DCM_CONST)Info,
	PduLengthType TpSduLength,
	P2VAR(PduLengthType, AUTOMATIC, DCM_VAR)BufferSizePtr
);

FUNC(BufReq_ReturnType, DCM_CODE)Dcm_CopyRxData
(
	PduIdType Id,
	P2CONST(PduInfoType, AUTOMATIC, DCM_CONST)Info,
	P2VAR(PduLengthType, AUTOMATIC, DCM_VAR)BufferSizePtr
);

FUNC(void, DCM_CODE)Dcm_TpRxIndication
(
	PduIdType Id,
	Std_ReturnType Result
);

FUNC(BufReq_ReturnType, DCM_CODE)Dcm_CopyTxData
(
	PduIdType Id,
	P2CONST(PduInfoType, AUTOMATIC, DCM_CONST)Info,
	P2VAR(RetryInfoType, AUTOMATIC, DCM_VAR)Retry,
	P2VAR(PduLengthType, AUTOMATIC, DCM_VAR)AvailableDataPtr
);

FUNC(void, DCM_CODE)Dcm_TpTxConfirmation
(
	PduIdType Id,
	Std_ReturnType Result
);

FUNC(void, DCM_CODE)Dcm_TxConfirmation
(
	PduIdType TxPduId
);

FUNC(void, DCM_CODE)Dcm_ComM_NoComModeEntered
(
	uint8 NetworkId
);

FUNC(void, DCM_CODE)Dcm_ComM_SilentComModeEntered
(
	uint8 NetworkId
);

FUNC(void, DCM_CODE)Dcm_ComM_FullComModeEntered
(
	uint8 NetworkId
);

#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* DCM_CBK_H */
/** @} */
