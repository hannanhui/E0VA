/**
 * @file        Dcm_UDS0x14.c
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

/* PRQA S 0292, 0288, 0857, 3218, 0491, 5087 EOF #
 *
 * 1.0292 -- Violates MISRA 2004 Required Rule 3.1, Source file has comments containing one of the
 * characters '$', '@' or '`'.
 *
 * 2.0288 -- Violates MISRA 2004 Required Rule 3.1, Source file has comments containing characters which
 * are not members of the basic source character set.
 *
 * 3.0857 -- Violates MISRA 2004 Required Rule 1.1, Number of macro definitions exceeds 1024 - program
 * does not conform strictly to ISO:C90.
 *
 * 4.3218 -- Violates MISRA 2004 Required Rule 8.7, File scope static, 'Dcm_UDS0x14CallState' is only
 * accessed in one function.
 *
 * 5.0491 -- Violates MISRA 2004 Required Rule 17.4, Array subscripting applied to an object of pointer
 * type.
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

#if(STD_ON == DCM_UDS0x14_ENABLE)
#if(STD_ON == DCM_UDS0x14_INTERNAL_FNC_ENABLE)
/**
 * @req [SWS_Dcm_00247] The Dcm module shall implement UDS Service 0x14.
 */
/*====================================================================================================*
 *                                  SOURCE FILE VERSION INFORMATION
 *====================================================================================================*/
#define DCM_UDS0X14_VENDOR_ID_C                            	(0x00U)
#define DCM_UDS0X14_AR_RELEASE_MAJOR_VERSION_C             	(0x04U)
#define DCM_UDS0X14_AR_RELEASE_MINOR_VERSION_C             	(0x02U)
#define DCM_UDS0X14_AR_RELEASE_REVISION_VERSION_C          	(0x02U)
#define DCM_UDS0X14_SW_MAJOR_VERSION_C                     	(0x01U)
#define DCM_UDS0X14_SW_MINOR_VERSION_C                     	(0x02U)
#define DCM_UDS0X14_SW_PATCH_VERSION_C                     	(0x00U)
/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/
/* Check if current file and Dcm_Internal header file are of the same vendor */
#if(DCM_UDS0X14_VENDOR_ID_C != DCM_INTERNAL_VENDOR_ID )
#error "Dcm_UDS0x14.c and Dcm_Internal.h have different vendor id"
#endif
/* Check if current file and Dcm_Internal header file are of the same Autosar version */
#if(\
		(DCM_UDS0X14_AR_RELEASE_MAJOR_VERSION_C != DCM_INTERNAL_AR_RELEASE_MAJOR_VERSION) || \
		(DCM_UDS0X14_AR_RELEASE_MINOR_VERSION_C != DCM_INTERNAL_AR_RELEASE_MINOR_VERSION) || \
		(DCM_UDS0X14_AR_RELEASE_REVISION_VERSION_C != DCM_INTERNAL_AR_RELEASE_REVISION_VERSION) \
)
#error "AutoSar Version Number of Dcm_UDS0x14.c and Dcm_Internal.h are different"
#endif
/* Check if current file and Dcm_Internal header file are of the same software version */
#if(\
		(DCM_UDS0X14_SW_MAJOR_VERSION_C != DCM_INTERNAL_SW_MAJOR_VERSION) || \
		(DCM_UDS0X14_SW_MINOR_VERSION_C != DCM_INTERNAL_SW_MINOR_VERSION) || \
		(DCM_UDS0X14_SW_PATCH_VERSION_C != DCM_INTERNAL_SW_PATCH_VERSION) \
)
#error "Software Version Number of Dcm_UDS0x14.c and Dcm_Internal.h are different"
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
 * @brief	The lower four bits respectively represent the call status of the four interfaces that
 * 			should be invoked. A set bit (1) indicates that the interface has been successfully called.
 * 			The meaning of each bit is as follows:
 * 			Bit0: Dem_DcmCheckClearParameter;
 * 			Bit1: DcmDspClearDTCCheckFnc;
 * 			Bit2: Dem_DcmClearDTC.
 */
STATIC VAR(uint8, DCM_VAR)Dcm_UDS0x14CallState = 0u;

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
 * @brief			Dcm_UDS0x14
 * @details			Internal processing interface for Service 0x14.
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
FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x14
(
	Dcm_OpStatusType OpStatus,
	P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
)
{
	Std_ReturnType result = (Std_ReturnType)E_NOT_OK;

	uint32 u32GroupOfDTC;
	Dem_ReturnClearDTCType callRet = (Dem_ReturnClearDTCType)DEM_CLEAR_OK;

	if(4u != pMsgContext->ReqDataLen)
	{
		*ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
	}
	else
	{
		u32GroupOfDTC = (uint32)pMsgContext->ReqData[1] << 16;
		u32GroupOfDTC |= (uint32)pMsgContext->ReqData[2] << 8;
		u32GroupOfDTC |= (uint32)pMsgContext->ReqData[3];

		if(!DCM_CHECK_BIT_SET(Dcm_UDS0x14CallState, 0u, uint8))
		{
			/**
			 * @req [SWS_Dcm_01263] Upon reception of a UDS Service ClearDiagnosticInformation
			 * 		(0x14) request with parameter groupOfDTC, the Dcm module shall call the API
			 * 		Dem_DcmCheckClearParameter() with the following parameter values:
			 * 		DTC: groupOfDTC from the service request,
			 * 		DTCFormat: DEM_DTC_FORMAT_UDS,
			 * 		DTCOrigin: DEM_DTC_ORIGIN_PRIMARY_MEMORY.
			 */
			callRet = Dem_DcmCheckClearParameter(u32GroupOfDTC, DEM_DTC_FORMAT_UDS, DEM_DTC_ORIGIN_PRIMARY_MEMORY);
		}

		if(((Dem_ReturnClearDTCType)DEM_CLEAR_OK == callRet) && (!DCM_CHECK_BIT_SET(Dcm_UDS0x14CallState, 1u, uint8)))
		{
			DCM_BIT_SET(Dcm_UDS0x14CallState, 0u, uint8);

			/**
			 * @req [SWS_Dcm_01268] In case Dem_DcmCheckClearParameter() returns DEM_CLEAR_OK, the Dcm
			 * 		module shall check if application allows to clear the DTC (according to the
			 * 		configuration parameter DcmDspClearDTCCheckFnc). If not, the Dcm module shall send
			 * 		a negative response with NRC set to value from the parameter "ErrorCode".
			 */
			if(NULL_PTR != Dcm_ConfigPtr->DcmDsp->DcmDspClearDTC->DcmDspClearDTCCheckFnc)
			{
				callRet = Dcm_ConfigPtr->DcmDsp->DcmDspClearDTC->DcmDspClearDTCCheckFnc(u32GroupOfDTC, ErrorCode);
			}
		}

		if(((Dem_ReturnClearDTCType)DEM_CLEAR_OK == callRet) && (!DCM_CHECK_BIT_SET(Dcm_UDS0x14CallState, 2u, uint8)))
		{
			DCM_BIT_SET(Dcm_UDS0x14CallState, 1u, uint8);

			/**
			 * @req [SWS_Dcm_00005] If the condition checks are successfully done, the Dcm module shall
			 * 		call the operation DcmClearDTC with the following parameter values:
			 * 		DTC: groupOfDTC from the service request,
			 * 		DTCFormat: DEM_DTC_FORMAT_UDS,
			 * 		DTCOrigin: DEM_DTC_ORIGIN_PRIMARY_MEMORY.
			 */
			callRet = Dem_DcmClearDTC(u32GroupOfDTC, DEM_DTC_FORMAT_UDS, DEM_DTC_ORIGIN_PRIMARY_MEMORY);
		}

		if((Dem_ReturnClearDTCType)DEM_CLEAR_PENDING == callRet)
		{
			/**
			 * @req [SWS_Dcm_01264] In case Dem_DcmCheckClearParameter() returns DEM_CLEAR_PENDING, the
			 * 		Dcm shall invoke Dem_DcmCheckClearParameter() on next Dcm_MainFunction() call again.
			 * 		It is up to the Dcm to send NRC 0x78 to respect the response behaviour.
			 *
			 * @req [SWS_Dcm_00706] In case Dem_DcmClearDTC() returns DEM_CLEAR_PENDING, the DCM shall
			 * 		invoke Dem_DcmClearDTC() on next Dcm_MainFunction call again. It is up to the DCM to
			 * 		send NRC 78 to respect the response behaviour.
			 */
			Dcm_OpState = DCM_PENDING;
			*ErrorCode = DCM_E_RESPONSE_PENDING;
		}
		else
		{
			if((Dem_ReturnClearDTCType)DEM_CLEAR_OK == callRet)
			{
				/**
				 * @req [SWS_Dcm_00705] In case Dem_DcmClearDTC() returns DEM_CLEAR_OK, the DCM module
				 * 		shall send a positive response.
				 */
				pMsgContext->ResData[0] = 0x54u;

				pMsgContext->ResDataLen = 1u;

				result = (Std_ReturnType)E_OK;
			}
			else if((Std_ReturnType)DEM_CLEAR_MEMORY_ERROR == callRet)
			{
				/**
				 * @req [SWS_Dcm_01060] In case Dem_DcmClearDTC() returns DEM_CLEAR_MEMORY_ERROR, the
				 * 		Dcm shall trigger a negative response with NRC 0x72 (GeneralProgrammingFailure).
				 */
				*ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
			}
			else if(((Std_ReturnType)DEM_CLEAR_FAILED == callRet) || ((Std_ReturnType)DEM_CLEAR_BUSY == callRet))
			{
				/**
				 * @req [SWS_Dcm_01267] In case Dem_DcmCheckClearParameter() returns DEM_CLEAR_FAILED,
				 * 		the Dcm shall send a NRC 0x22 (Conditions not correct).
				 *
				 * @req [SWS_Dcm_00707] In case Dem_DcmClearDTC() return DEM_CLEAR_FAILED, the DCM shall
				 * 		send a negative response 0x22 – conditionsNotCorrect.
				 *
				 * @req [SWS_Dcm_00966] In case Dem_DcmClearDTC() returns DEM_CLEAR_BUSY, the DCM shall
				 * 		send a negative response 0x22 – ConditionsNotCorrect.
				 */
				*ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
			}
			else
			{
				/**
				 * @req [SWS_Dcm_01265] In case Dem_DcmCheckClearParameter() return DEM_CLEAR_WRONG_DTC,
				 * 		the Dcm shall send a NRC 0x31 (Request out of range).
				 *
				 * @req [SWS_Dcm_00708] In case Dem_DcmClearDTC() returns DEM_CLEAR_WRONG_DTC, the DCM
				 * 		shall send a negative response 0x31 – requestOutOfRange.
				 */
				if((Dcm_NegativeResponseCodeType)0xFF == *ErrorCode)
				{
					*ErrorCode = DCM_E_REQUESTOUTOFRANGE;
				}
			}

			Dcm_UDS0x14CallState = 0u;
		}
	}

	return result;
}

#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#endif /* #if(STD_ON == DCM_UDS0x14_INTERNAL_FNC_ENABLE) */
#endif /* #if(STD_ON == DCM_UDS0x14_ENABLE) */

#ifdef __cplusplus
}
#endif
/** @} */
