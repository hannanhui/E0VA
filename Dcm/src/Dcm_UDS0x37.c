/**
 * @file        Dcm_UDS0x37.c
 * @brief       AUTOSAR 4.2.2 - 4.2.2 driver source file.
 * @details     Dcm driver source file, containing the C implementation of Autosar API specification
 *              and other variables and functions that are exported by the Dcm driver.
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

#ifdef __cplusplus
extern "C"{
#endif

/* PRQA S 0292, 0857, 0491, 5087 EOF #
 *
 * 1.0292 -- Violates MISRA 2004 Required Rule 3.1, Source file has comments containing one of the
 * characters '$', '@' or '`'.
 *
 * 2.0857 -- Violates MISRA 2004 Required Rule 1.1, Number of macro definitions exceeds 1024 - program
 * does not conform strictly to ISO:C90.
 *
 * 3.0491 -- Violates MISRA 2004 Required Rule 17.4, Array subscripting applied to an object of pointer
 * type.
 *
 * 4.5087 -- Violates MISRA 2004 Required Rule 19.1, Use of #include directive after code fragment.
 *
 * @page misra_violations MISRA-C:2004 violations
 */

/*====================================================================================================*
 *                                           INCLUDE FILES
 *====================================================================================================*/
#include "Dcm_Internal.h"
#include "FBL.h"

#ifdef AH_TEST_DCM
#include "TestCode.h"
#endif /* #ifdef AH_TEST_DCM */

#if(STD_ON == DCM_UDS0x37_ENABLE)
#if(STD_ON == DCM_UDS0x37_INTERNAL_FNC_ENABLE)
/**
 * @req [SWS_Dcm_00505] The Dcm module shall implement the RequestTransferExit (service 0x37) of the
 * 		Unified Diagnostic Services.
 */
/*====================================================================================================*
 *                                  SOURCE FILE VERSION INFORMATION
 *====================================================================================================*/
#define DCM_UDS0X37_VENDOR_ID_C                            	(0x00U)
#define DCM_UDS0X37_AR_RELEASE_MAJOR_VERSION_C             	(0x04U)
#define DCM_UDS0X37_AR_RELEASE_MINOR_VERSION_C             	(0x02U)
#define DCM_UDS0X37_AR_RELEASE_REVISION_VERSION_C          	(0x02U)
#define DCM_UDS0X37_SW_MAJOR_VERSION_C                     	(0x01U)
#define DCM_UDS0X37_SW_MINOR_VERSION_C                     	(0x02U)
#define DCM_UDS0X37_SW_PATCH_VERSION_C                     	(0x00U)
/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/
/* Check if current file and Dcm_Internal header file are of the same vendor */
#if(DCM_UDS0X37_VENDOR_ID_C != DCM_INTERNAL_VENDOR_ID )
#error "Dcm_UDS0x37.c and Dcm_Internal.h have different vendor id"
#endif
/* Check if current file and Dcm_Internal header file are of the same Autosar version */
#if(\
		(DCM_UDS0X37_AR_RELEASE_MAJOR_VERSION_C != DCM_INTERNAL_AR_RELEASE_MAJOR_VERSION) || \
		(DCM_UDS0X37_AR_RELEASE_MINOR_VERSION_C != DCM_INTERNAL_AR_RELEASE_MINOR_VERSION) || \
		(DCM_UDS0X37_AR_RELEASE_REVISION_VERSION_C != DCM_INTERNAL_AR_RELEASE_REVISION_VERSION) \
)
#error "AutoSar Version Number of Dcm_UDS0x37.c and Dcm_Internal.h are different"
#endif
/* Check if current file and Dcm_Internal header file are of the same software version */
#if(\
		(DCM_UDS0X37_SW_MAJOR_VERSION_C != DCM_INTERNAL_SW_MAJOR_VERSION) || \
		(DCM_UDS0X37_SW_MINOR_VERSION_C != DCM_INTERNAL_SW_MINOR_VERSION) || \
		(DCM_UDS0X37_SW_PATCH_VERSION_C != DCM_INTERNAL_SW_PATCH_VERSION) \
)
#error "Software Version Number of Dcm_UDS0x37.c and Dcm_Internal.h are different"
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
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"

/**
 * @brief			Dcm_UDS0x37
 * @details			Internal processing interface for Service 0x37.
 *
 * @param[in]		OpStatus:Operating state.
 * @param[in]		pMsgContext:Message-related information for one diagnostic protocol identifier.
 * 					The pointers in pMsgContext shall point behind the SID.
 *
 * @param[out]		ErrorCode:If the operation <Module>_<DiagnosticService> returns value  E_NOT_OK,
 * 					the DCM module shall send a negative response  with NRC code equal to the parameter
 * 					ErrorCode parameter value.
 *
 * @return        	Result of this operation.
 * @retval			E_OK:Request was successful.
 * @retval			E_NOT_OK:Request was not successful.
 */
FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x37
(
	Dcm_OpStatusType OpStatus,
	P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
)
{
	Std_ReturnType result = (Std_ReturnType)E_NOT_OK;

	uint32 u32ResRecordDataLen;

	if((DCM_DSP_TRANSFER_EXIT_REQ_RECORD_SIZE + 1u) != pMsgContext->ReqDataLen)
	{
		*ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
	}
	else if(DCM_TRANSFER_EXIT != Dcm_TransferStatus.Process)
	{
		*ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
	}
	else
	{
		u32ResRecordDataLen = (pMsgContext->ReqDataLen - 1u);

		result = Dcm_ProcessRequestTransferExit(\
						OpStatus, &pMsgContext->ReqData[1], DCM_DSP_TRANSFER_EXIT_REQ_RECORD_SIZE,\
						&pMsgContext->ResData[1], &u32ResRecordDataLen, ErrorCode\
						);
		if(	E_OK != FBL_Dcm0x37Call())
		{
			*ErrorCode = DCM_E_REQUESTOUTOFRANGE;
			result = E_NOT_OK;
		}

		if((Std_ReturnType)E_OK == result)
		{
			if(pMsgContext->ResMaxDataLen < (u32ResRecordDataLen + 1u))
			{
				*ErrorCode = DCM_E_RESPONSETOOLONG;

				result = (Std_ReturnType)E_NOT_OK;
			}
			else
			{
				pMsgContext->ResData[0] = 0x77u;

				pMsgContext->ResDataLen = (u32ResRecordDataLen + 1u);

				DspInternal_TransferInit();
			}
		}
		else
		{
			if((Std_ReturnType)DCM_E_PENDING == result)
			{
				Dcm_OpState = DCM_PENDING;
				*ErrorCode = DCM_E_RESPONSE_PENDING;
			}
			else
			{
				DspInternal_TransferInit();
			}

			result = (Std_ReturnType)E_NOT_OK;
		}
	}

	return result;
}

#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#endif /* #if(STD_ON == DCM_UDS0x37_INTERNAL_FNC_ENABLE) */
#endif /* #if(STD_ON == DCM_UDS0x37_ENABLE) */

#ifdef __cplusplus
}
#endif
/** @} */
