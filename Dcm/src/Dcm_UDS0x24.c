/**
 * @file        Dcm_UDS0x24.c
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

/* PRQA S 0292, 0857, 0491, 3218, 2981, 5087 EOF #
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
 * 4.3218 -- Violates MISRA 2004 Required Rule 17.4, File scope static, 'Dcm_UDS0x24ReqSignalIdx', is
 * only accessed in one function.
 *
 * 5.2981 -- Violates MISRA 2004 Required Rule 21.1, This initialization is redundant. The value of this
 * object is never used before being modified.
 *
 * 6.5087 -- Violates MISRA 2004 Required Rule 19.1, Use of #include directive after code fragment.
 *
 * @page misra_violations MISRA-C:2004 violations
 */

/*====================================================================================================*
 *                                           INCLUDE FILES
 *====================================================================================================*/
#include "Dcm_Internal.h"

#ifdef AH_TEST_DCM
#include "TestCode.h"
#endif /* #ifdef AH_TEST_DCM */

#if(STD_ON == DCM_UDS0x24_ENABLE)
#if(STD_ON == DCM_UDS0x24_INTERNAL_FNC_ENABLE)
/**
 * @req [SWS_Dcm_00258] The Dcm module shall implement the UDS Service 0x24.
 */
/*====================================================================================================*
 *                                  SOURCE FILE VERSION INFORMATION
 *====================================================================================================*/
#define DCM_UDS0X24_VENDOR_ID_C                            	(0x00U)
#define DCM_UDS0X24_AR_RELEASE_MAJOR_VERSION_C             	(0x04U)
#define DCM_UDS0X24_AR_RELEASE_MINOR_VERSION_C             	(0x02U)
#define DCM_UDS0X24_AR_RELEASE_REVISION_VERSION_C          	(0x02U)
#define DCM_UDS0X24_SW_MAJOR_VERSION_C                     	(0x01U)
#define DCM_UDS0X24_SW_MINOR_VERSION_C                     	(0x02U)
#define DCM_UDS0X24_SW_PATCH_VERSION_C                     	(0x00U)
/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/
/* Check if current file and Dcm_Internal header file are of the same vendor */
#if(DCM_UDS0X24_VENDOR_ID_C != DCM_INTERNAL_VENDOR_ID )
#error "Dcm_UDS0x24.c and Dcm_Internal.h have different vendor id"
#endif
/* Check if current file and Dcm_Internal header file are of the same Autosar version */
#if(\
		(DCM_UDS0X24_AR_RELEASE_MAJOR_VERSION_C != DCM_INTERNAL_AR_RELEASE_MAJOR_VERSION) || \
		(DCM_UDS0X24_AR_RELEASE_MINOR_VERSION_C != DCM_INTERNAL_AR_RELEASE_MINOR_VERSION) || \
		(DCM_UDS0X24_AR_RELEASE_REVISION_VERSION_C != DCM_INTERNAL_AR_RELEASE_REVISION_VERSION) \
)
#error "AutoSar Version Number of Dcm_UDS0x24.c and Dcm_Internal.h are different"
#endif
/* Check if current file and Dcm_Internal header file are of the same software version */
#if(\
		(DCM_UDS0X24_SW_MAJOR_VERSION_C != DCM_INTERNAL_SW_MAJOR_VERSION) || \
		(DCM_UDS0X24_SW_MINOR_VERSION_C != DCM_INTERNAL_SW_MINOR_VERSION) || \
		(DCM_UDS0X24_SW_PATCH_VERSION_C != DCM_INTERNAL_SW_PATCH_VERSION) \
)
#error "Software Version Number of Dcm_UDS0x24.c and Dcm_Internal.h are different"
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
#ifdef AH_UNITTEST_ENABLED

	#ifdef STATIC
		#undef STATIC
		#define STATIC
	#else
		#define STATIC
	#endif /* STATIC */

	#ifdef INLINE
		#undef INLINE
		#define INLINE
	#else
		#define STATIC_INLINE
	#endif /* INLINE */

	#ifdef STATIC_INLINE
		#undef STATIC_INLINE
		#define STATIC_INLINE
	#else
		#define STATIC_INLINE
	#endif /* STATIC_INLINE */
#else
	#ifndef STATIC
		#define STATIC static
	#endif /* STATIC */

	#ifndef INLINE
		#define INLINE inline
	#endif /* INLINE */

	#ifndef STATIC_INLINE
		#define STATIC_INLINE static inline
	#endif /* STATIC_INLINE */

#endif /* AH_UNITTEST_ENABLED */
/*====================================================================================================*
 *                                           LOCAL CONSTANTS
 *====================================================================================================*/

/*====================================================================================================*
 *                                           LOCAL VARIABLES
 *====================================================================================================*/
#define DCM_START_SEC_VAR_NO_INIT_8
#include "Dcm_MemMap.h"

/**
 * @brief 	Used to record the index of the pending signal within the configuration.
 */
STATIC VAR(uint8, DCM_VAR)Dcm_UDS0x24ReqSignalIdx = 0u;

#define DCM_STOP_SEC_VAR_NO_INIT_8
#include "Dcm_MemMap.h"
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
 * @brief			Dcm_UDS0x24
 * @details			Internal processing interface for Service 0x10.
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
FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x24
(
	Dcm_OpStatusType OpStatus,
	P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
)
{
	Std_ReturnType result = (Std_ReturnType)E_OK;

#if((0u != DCM_DSP_DID_NUM) &&\
	(0u != DCM_DSP_DID_SIGNAL_NUM) &&\
	(STD_ON == DCM_DSP_DATA_GET_SCALING_INFO_FNC_ENABLED))
	uint8 u8Index;
	uint8 u8ReqDidIdx;
	uint16 u16ReqDid;
	const Dcm_DspDidType* pDid = NULL_PTR;
	const Dcm_DspDataType* pSignalData = NULL_PTR;
#endif /* #if((0u != DCM_DSP_DID_NUM) &&\
			  (0u != DCM_DSP_DID_SIGNAL_NUM) &&\
			  (STD_ON == DCM_DSP_DATA_GET_SCALING_INFO_FNC_ENABLED)) */

	if(DCM_PENDING != OpStatus)
	{
		if(3u != pMsgContext->ReqDataLen)
		{
			*ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;

			result = (Std_ReturnType)E_NOT_OK;
		}
		else
		{
			Dcm_UDS0x24ReqSignalIdx = 0u;
			pMsgContext->ResDataLen = 3u;
		}
	}

	if((Std_ReturnType)E_OK == result)
	{
#if((0u != DCM_DSP_DID_NUM) &&\
	(0u != DCM_DSP_DID_SIGNAL_NUM) &&\
	(STD_ON == DCM_DSP_DATA_GET_SCALING_INFO_FNC_ENABLED))

		u16ReqDid = (uint16)pMsgContext->ReqData[1] << 8u;
		u16ReqDid |= (uint16)pMsgContext->ReqData[2];

#if((STD_ON == DCM_UDS0x2C_ENABLE) || (STD_ON == DCM_UDS0x2A_ENABLE))
		result = DspInternal_CheckDidValid(\
					u16ReqDid, DCM_PERMISSION_CHECK_USER_SCALING_DID,\
					&u8ReqDidIdx, NULL_PTR, NULL_PTR, ErrorCode\
					);
#else
		result = DspInternal_CheckDidValid(\
					u16ReqDid, DCM_PERMISSION_CHECK_USER_SCALING_DID, &u8ReqDidIdx, ErrorCode\
					);
#endif /* #if((STD_ON == DCM_UDS0x2C_ENABLE) || (STD_ON == DCM_UDS0x2A_ENABLE)) */

		/**
		 * @req [SWS_Dcm_00394] On reception of a request for UDS Service ReadScalingByIdentifier, the
		 * 		DCM module shall call every function Xxx_GetScalingInformation() configured for everay
		 * 		data of the DID received in the request and return the data received in the response.
		 */
		if((Std_ReturnType)E_OK == result)
		{
			pDid = &Dcm_ConfigPtr->DcmDsp->DcmDspDid[u8ReqDidIdx];

			if(0u != pDid->DcmDspDidSignalNum)
			{
				for(u8Index = Dcm_UDS0x24ReqSignalIdx; u8Index < pDid->DcmDspDidSignalNum; u8Index++)
				{
					result = (Std_ReturnType)E_NOT_OK;

					Dcm_UDS0x24ReqSignalIdx = u8Index;

					pSignalData = pDid->DcmDspDidSignal[u8Index].DcmDspDidDataRef;

					if(NULL_PTR != pSignalData->DcmDspDataGetScalingInfoFnc)
					{
						if(pMsgContext->ResMaxDataLen >= (pMsgContext->ResDataLen + pSignalData->DcmDspDataInfoRef))
						{
							result = pSignalData->DcmDspDataGetScalingInfoFnc(\
										OpStatus, &pMsgContext->ResData[pMsgContext->ResDataLen], ErrorCode\
										);
						}
						else
						{
							*ErrorCode = DCM_E_RESPONSETOOLONG;
						}
					}
					else
					{
						*ErrorCode = DCM_E_REQUESTOUTOFRANGE;
					}

					if((Std_ReturnType)E_OK == result)
					{
						pMsgContext->ResDataLen += pSignalData->DcmDspDataInfoRef;
					}
					else
					{
						if((Std_ReturnType)DCM_E_PENDING == result)
						{
							Dcm_OpState = DCM_PENDING;
							*ErrorCode = DCM_E_RESPONSE_PENDING;
							result = (Std_ReturnType)E_NOT_OK;
						}

						break;
					}
				}

				if((Std_ReturnType)E_OK == result)
				{
					pMsgContext->ResData[0] = 0x64u;
					pMsgContext->ResData[1] = pMsgContext->ReqData[1];
					pMsgContext->ResData[2] = pMsgContext->ReqData[2];
				}
			}
			else
			{
				*ErrorCode = DCM_E_REQUESTOUTOFRANGE;
				result = (Std_ReturnType)E_NOT_OK;
			}
		}
#else
		*ErrorCode = DCM_E_REQUESTOUTOFRANGE;
		result = (Std_ReturnType)E_NOT_OK;
#endif /* #if((0u != DCM_DSP_DID_NUM) &&\
			  (0u != DCM_DSP_DID_SIGNAL_NUM) &&\
			  (STD_ON == DCM_DSP_DATA_GET_SCALING_INFO_FNC_ENABLED)) */
	}

	return result;
}

#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#endif /* #if(STD_ON == DCM_UDS0x10_INTERNAL_FNC_ENABLE) */
#endif /* #if(STD_ON == DCM_UDS0x10_ENABLE) */

#ifdef __cplusplus
}
#endif
/** @} */
