/**
 * @file        Dcm_UDS0x3E.c
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

/* PRQA S 0292, 0857, 0491, 2981, 5087 EOF #
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
 * 4.2981 -- Violates MISRA 2004 Required Rule 21.1, This initialization is redundant. The value of this
 * object is never used before being modified.
 *
 * 5.5087 -- Violates MISRA 2004 Required Rule 19.1, Use of #include directive after code fragment.
 *
 * @page misra_violations MISRA-C:2004 violations
 */

/*====================================================================================================*
 *                                           INCLUDE FILES
 *====================================================================================================*/
#include "Dcm_Internal.h"

#if(STD_ON == DCM_UDS0x3E_ENABLE)
#if(STD_ON == DCM_UDS0x3E_INTERNAL_FNC_ENABLE)
/**
 * @req [SWS_Dcm_00251] The DCM module shall implement the Tester Present (service 0x3E, diagnostic
 * 		communication and security) of the Unified Diagnostic Services for the subfunction values 0x00
 * 		and 0x80.
 */
/*====================================================================================================*
 *                                  SOURCE FILE VERSION INFORMATION
 *====================================================================================================*/
#define DCM_UDS0X3E_VENDOR_ID_C                            	(0x00U)
#define DCM_UDS0X3E_AR_RELEASE_MAJOR_VERSION_C             	(0x04U)
#define DCM_UDS0X3E_AR_RELEASE_MINOR_VERSION_C             	(0x02U)
#define DCM_UDS0X3E_AR_RELEASE_REVISION_VERSION_C          	(0x02U)
#define DCM_UDS0X3E_SW_MAJOR_VERSION_C                     	(0x01U)
#define DCM_UDS0X3E_SW_MINOR_VERSION_C                     	(0x02U)
#define DCM_UDS0X3E_SW_PATCH_VERSION_C                     	(0x00U)
/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/
/* Check if current file and Dcm_Internal header file are of the same vendor */
#if(DCM_UDS0X3E_VENDOR_ID_C != DCM_INTERNAL_VENDOR_ID )
#error "Dcm_UDS0x3E.c and Dcm_Internal.h have different vendor id"
#endif
/* Check if current file and Dcm_Internal header file are of the same Autosar version */
#if(\
		(DCM_UDS0X3E_AR_RELEASE_MAJOR_VERSION_C != DCM_INTERNAL_AR_RELEASE_MAJOR_VERSION) || \
		(DCM_UDS0X3E_AR_RELEASE_MINOR_VERSION_C != DCM_INTERNAL_AR_RELEASE_MINOR_VERSION) || \
		(DCM_UDS0X3E_AR_RELEASE_REVISION_VERSION_C != DCM_INTERNAL_AR_RELEASE_REVISION_VERSION) \
)
#error "AutoSar Version Number of Dcm_UDS0x3E.c and Dcm_Internal.h are different"
#endif
/* Check if current file and Dcm_Internal header file are of the same software version */
#if(\
		(DCM_UDS0X3E_SW_MAJOR_VERSION_C != DCM_INTERNAL_SW_MAJOR_VERSION) || \
		(DCM_UDS0X3E_SW_MINOR_VERSION_C != DCM_INTERNAL_SW_MINOR_VERSION) || \
		(DCM_UDS0X3E_SW_PATCH_VERSION_C != DCM_INTERNAL_SW_PATCH_VERSION) \
)
#error "Software Version Number of Dcm_UDS0x3E.c and Dcm_Internal.h are different"
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
 * @brief			Dcm_UDS0x3E
 * @details			Internal processing interface for Service 0x3E.
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
FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x3E
(
	Dcm_OpStatusType OpStatus,
	P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
)
{
	Std_ReturnType result = (Std_ReturnType)E_NOT_OK;

	uint8 u8AddrType;
	uint8 u8SubServiceId;
	const Dcm_DsdServiceType* pService = NULL_PTR;

	if(2u != pMsgContext->ReqDataLen)
	{
		*ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
	}
	else
	{
		u8SubServiceId = pMsgContext->ReqData[1];

		u8AddrType = (pMsgContext->MsgAddInfo & 0x01u);

		pService = DCM_GET_SERVICE_PTR(Dcm_ConnectionStatus[Dcm_ActiveConIdx].ServiceIdx);

		if((Std_ReturnType)E_OK == DspInternal_SubServiceCheck(u8AddrType, u8SubServiceId, pService, ErrorCode))
		{
			/* The minimum length of the buffer is 8 bytes, no need to check the response length. */

			pMsgContext->ResData[0] = 0x7Eu;
			pMsgContext->ResData[1] = 0x00u;

			pMsgContext->ResDataLen = 2u;

			result = (Std_ReturnType)E_OK;
		}
	}

	return result;
}

#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#endif /* #if(STD_ON == DCM_UDS0x3E_INTERNAL_FNC_ENABLE) */
#endif /* #if(STD_ON == DCM_UDS0x3E_ENABLE) */

#ifdef __cplusplus
}
#endif
/** @} */
