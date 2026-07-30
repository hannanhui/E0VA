/**
 * @file        Dcm_UDS0x22.c
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

/* PRQA S 0292, 0288, 0857, 2981, 0491, 0498, 5087 EOF #
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
 * 4.2981 -- Violates MISRA 2004 Required Rule 21.1, This initialization is redundant. The value of this
 * object is never used before being modified.
 *
 * 5.0491 -- Violates MISRA 2004 Required Rule 17.4, Array subscripting applied to an object of pointer
 * type.
 *
 * 6.0498 -- Violates MISRA 2004 Required Rule 17.4, A unary increment or decrement operator is being
 * applied to a pointer.
 *
 * 7.5087 -- Violates MISRA 2004 Required Rule 19.1, Use of #include directive after code fragment.
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

#if(STD_ON == DCM_UDS0x22_ENABLE)
#if(STD_ON == DCM_UDS0x22_INTERNAL_FNC_ENABLE)
/**
 * @req [SWS_Dcm_00253] The Dcm module shall implement the UDS Service ReadDataByIdentifier (0x22).
 */
/*====================================================================================================*
 *                                  SOURCE FILE VERSION INFORMATION
 *====================================================================================================*/
#define DCM_UDS0X22_VENDOR_ID_C                            	(0x00U)
#define DCM_UDS0X22_AR_RELEASE_MAJOR_VERSION_C             	(0x04U)
#define DCM_UDS0X22_AR_RELEASE_MINOR_VERSION_C             	(0x02U)
#define DCM_UDS0X22_AR_RELEASE_REVISION_VERSION_C          	(0x02U)
#define DCM_UDS0X22_SW_MAJOR_VERSION_C                     	(0x01U)
#define DCM_UDS0X22_SW_MINOR_VERSION_C                     	(0x02U)
#define DCM_UDS0X22_SW_PATCH_VERSION_C                     	(0x00U)
/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/
/* Check if current file and Dcm_Internal header file are of the same vendor */
#if(DCM_UDS0X22_VENDOR_ID_C != DCM_INTERNAL_VENDOR_ID )
#error "Dcm_UDS0x22.c and Dcm_Internal.h have different vendor id"
#endif
/* Check if current file and Dcm_Internal header file are of the same Autosar version */
#if(\
		(DCM_UDS0X22_AR_RELEASE_MAJOR_VERSION_C != DCM_INTERNAL_AR_RELEASE_MAJOR_VERSION) || \
		(DCM_UDS0X22_AR_RELEASE_MINOR_VERSION_C != DCM_INTERNAL_AR_RELEASE_MINOR_VERSION) || \
		(DCM_UDS0X22_AR_RELEASE_REVISION_VERSION_C != DCM_INTERNAL_AR_RELEASE_REVISION_VERSION) \
)
#error "AutoSar Version Number of Dcm_UDS0x22.c and Dcm_Internal.h are different"
#endif
/* Check if current file and Dcm_Internal header file are of the same software version */
#if(\
		(DCM_UDS0X22_SW_MAJOR_VERSION_C != DCM_INTERNAL_SW_MAJOR_VERSION) || \
		(DCM_UDS0X22_SW_MINOR_VERSION_C != DCM_INTERNAL_SW_MINOR_VERSION) || \
		(DCM_UDS0X22_SW_PATCH_VERSION_C != DCM_INTERNAL_SW_PATCH_VERSION) \
)
#error "Software Version Number of Dcm_UDS0x22.c and Dcm_Internal.h are different"
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
#define DCM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dcm_MemMap.h"

/**
 * @brief	Store internal status of service 0x22 during its processing.
 */
STATIC VAR(Dcm_ReadDataByDidStatusType, DCM_VAR)Dcm_UDS0x22Status;

#define DCM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dcm_MemMap.h"
/*====================================================================================================*
 *                                      LOCAL FUNCTION PROTOTYPES
 *====================================================================================================*/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"

#if((0u != DCM_DSP_DID_NUM) || (0u != DCM_DSP_DID_RANGE_NUM))
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x22ReqDidCheck
(
	Dcm_OpStatusType opState,
	P2VAR(uint8, AUTOMATIC, DCM_VAR)pReqDidIdx,
	P2VAR(uint8, AUTOMATIC, DCM_VAR)pReqDidType,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
);
#endif /* #if((0u != DCM_DSP_DID_NUM) || (0u != DCM_DSP_DID_RANGE_NUM)) */

#if(0u != DCM_DSP_DID_NUM)
#if(STD_ON == DCM_UDS0x2C_ENABLE)
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x22SingleDidProcess
(
	uint8 u8ReqDidIdx,
	Dcm_OpStatusType opState,
	boolean isDDDid,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
);
#else
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x22SingleDidProcess
(
	uint8 u8ReqDidIdx,
	Dcm_OpStatusType opState,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
);
#endif /* #if(STD_ON == DCM_UDS0x2C_ENABLE) */
#endif /* #if(0u != DCM_DSP_DID_NUM) */

#if(0u != DCM_DSP_DID_RANGE_NUM)
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x22RangeDidProcess
(
	uint8 u8ReqDidIdx,
	Dcm_OpStatusType opState,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
);
#endif /* #if(0u != DCM_DSP_DID_RANGE_NUM) */

#if(STD_ON == DCM_UDS0x2C_ENABLE)
#if((STD_ON == DCM_UDS0x2C_SUB0x01_ENABLE) || (STD_ON == DCM_UDS0x2C_SUB0x02_ENABLE))
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x22DynDefDidProcess
(
	uint8 u8ReqDidIdx,
	Dcm_OpStatusType opState,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
);
#endif /* #if((STD_ON == DCM_UDS0x2C_SUB0x01_ENABLE) || (STD_ON == DCM_UDS0x2C_SUB0x02_ENABLE)) */
#endif /* #if(STD_ON == DCM_UDS0x2C_ENABLE) */

STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x22DidProcess
(
	Dcm_OpStatusType opState,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
);
/*====================================================================================================*
 *                                           LOCAL FUNCTIONS
 *====================================================================================================*/
#if((0u != DCM_DSP_DID_NUM) || (0u != DCM_DSP_DID_RANGE_NUM))
/**
 * @brief			Dcm_UDS0x22ReqDidCheck
 * @details			Check whether the requested Did is valid.
 *
 * @param[in]		opState:Operating state.
 *
 * @param[out]		pReqDidIdx:If the requested Did is valid, output its index within the configuration.
 * @param[out]		pReqDidType:Output the requested Did type.
 * @param[out]		pErrorCode:If error occur, output the NRC.
 *
 * @return        	Result of this operation.
 * @retval			E_OK:Processing successful.
 * @retval			E_NOT_OK:Processing failure.
 */
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x22ReqDidCheck
(
	Dcm_OpStatusType opState,
	P2VAR(uint8, AUTOMATIC, DCM_VAR)pReqDidIdx,
	P2VAR(uint8, AUTOMATIC, DCM_VAR)pReqDidType,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
)
{
	Std_ReturnType result = (Std_ReturnType)E_NOT_OK;

	uint16 u16ReqDid = Dcm_UDS0x22Status.ReqDid;

	/**
	 * @req [SWS_Dcm_00438] On reception of the UDS Service ReadDataByIdentifier (0x22), for every
	 * 		requested DID the DCM module shall check if the DID is supported (see configuration
	 * 		parameter DcmDspDid and DcmDspDidRange) If none of the requested DIDs is supported, the
	 * 		DCM module shall send NRC 0x31 (Request out of range).
	 */

#if(0u != DCM_DSP_DID_NUM)
#if((STD_ON == DCM_UDS0x2C_ENABLE) || (STD_ON == DCM_UDS0x2A_ENABLE))
	result = DspInternal_CheckDidValid(\
				u16ReqDid, DCM_PERMISSION_CHECK_USER_READ_DID, pReqDidIdx, NULL_PTR, NULL_PTR, pErrorCode\
				);

	/**
	 * @req [SWS_Dcm_00651] On reception of the UDS Service ReadDataByIdentifier (0x22) with DID in the
	 * 		range 0xF200 to 0xF3FF, the Dcm module shall check if the DID can be dynamically defined
	 * 		(the DcmDspDidInfo it references has the DcmDspDidDynamicallyDefined set to true). If yes,
	 * 		if this DID has not been dynamically defined yet by calls to the
	 * 		DynamicallyDefineDataIdentifier (0x2C) service, i.e. it has no data sources defined, the Dcm
	 * 		module shall send NRC 0x31 (Request out of range).
	 *
	 * @req [SWS_Dcm_00652] On reception of the UDS Service ReadDataByIdentifier (0x22) with DID in the
	 * 		range 0xF200 to 0xF3FF, if verification has been successfully done (see SWS_Dcm_00651) and
	 * 		the dynamic DID has been defined with a DID source (see SWS_Dcm_00646), the DCM module shall
	 * 		use the configuration of this DID source to read the data.
	 */
#if(STD_ON == DCM_UDS0x2C_ENABLE)
	if(((Std_ReturnType)E_OK == result) && (0xF200u <= u16ReqDid) && (0xF3FFu >= u16ReqDid))
	{
		result = DspInternal_CheckDDDidReadValid(*pReqDidIdx, pReqDidType, pErrorCode);
	}
#endif /* #if(STD_ON == DCM_UDS0x2C_ENABLE) */
#else
	result = DspInternal_CheckDidValid(\
				u16ReqDid, DCM_PERMISSION_CHECK_USER_READ_DID, pReqDidIdx, pErrorCode\
				);
#endif /* #if((STD_ON == DCM_UDS0x2C_ENABLE) || (STD_ON == DCM_UDS0x2A_ENABLE)) */
#endif /* #if(0u != DCM_DSP_DID_NUM) */

#if(0u != DCM_DSP_DID_RANGE_NUM)
	if((0xFFu == *pReqDidIdx) && (DCM_E_REQUESTOUTOFRANGE == *pErrorCode))
	{
		result = DspInternal_CheckRangeDidValid(\
					u16ReqDid, opState, DCM_PERMISSION_CHECK_USER_READ_DID, pReqDidIdx, pErrorCode\
					);

		if((Std_ReturnType)E_OK == result)
		{
			*pReqDidType = 0x02u;
		}
	}
#endif /* #if(0u != DCM_DSP_DID_RANGE_NUM) */

	return result;
}
#endif /* #if((0u != DCM_DSP_DID_NUM) || (0u != DCM_DSP_DID_RANGE_NUM)) */

#if(0u != DCM_DSP_DID_NUM)
/**
 * @brief			Dcm_UDS0x22SingleDidProcess
 * @details			Handler for reading Single-Did data.
 *
 * @param[in]		u8ReqDidIdx:The index of the Signal-Did to be read within the configuration.
 * @param[in]		opState:Operating state.
 * @param[in]		isDDDid:Whether the Signal-Did is DDDid or not.
 *
 * @param[out]		pErrorCode:If the called external interface returns E_NOT_OK, use this pointer to
 * 					output the NRC.
 *
 * @return        	Result of this operation.
 * @retval			E_OK:Processing successful.
 * @retval			E_NOT_OK:Processing failure.
 */
#if(STD_ON == DCM_UDS0x2C_ENABLE)
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x22SingleDidProcess
(
	uint8 u8ReqDidIdx,
	Dcm_OpStatusType opState,
	boolean isDDDid,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
)
#else
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x22SingleDidProcess
(
	uint8 u8ReqDidIdx,
	Dcm_OpStatusType opState,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
)
#endif /* #if(STD_ON == DCM_UDS0x2C_ENABLE) */
{
	Std_ReturnType result = (Std_ReturnType)E_NOT_OK;

#if(0u != DCM_DSP_DID_SIGNAL_NUM)

	uint8 u8Index;
	uint16 u16SignalSize;
	uint8* pDidData = NULL_PTR;
#if(0u)
#if(0u != DCM_DSP_DATA_BLOCK_USED_NUM)
	NvM_RequestResultType NvMRet = NVM_REQ_NOT_OK;
#endif /* #if(0u != DCM_DSP_DATA_BLOCK_USED_NUM) */
#endif /* #if(0u) */
	const Dcm_DspDidType* pDid = &Dcm_ConfigPtr->DcmDsp->DcmDspDid[u8ReqDidIdx];
	const Dcm_DspDidSignalType* pSignal = NULL_PTR;
	const Dcm_DspDataType* pSignalData = NULL_PTR;

	for(u8Index = Dcm_UDS0x22Status.ReqSignalIndex; u8Index < pDid->DcmDspDidSignalNum; u8Index++)
	{
		result = (Std_ReturnType)E_NOT_OK;

		Dcm_UDS0x22Status.ReqSignalIndex = u8Index;

		pSignal = &pDid->DcmDspDidSignal[u8Index];

#if(STD_ON == DCM_UDS0x2C_ENABLE)
		if((boolean)FALSE == isDDDid)
		{
			pDidData = &Dcm_UDS0x22Status.DidData[(pSignal->DcmDspDidDataPos / 8u) + 2u];
		}
		else
		{
			pDidData = &Dcm_UDS0x22Status.DidData[((uint32)pSignal->DcmDspDidDataPos / 8u) + Dcm_UDS0x22Status.DidDataLen];
		}
#else
		pDidData = &Dcm_UDS0x22Status.DidData[(pSignal->DcmDspDidDataPos / 8u) + 2u];
#endif /* #if(STD_ON == DCM_UDS0x2C_ENABLE) */

		pSignalData = pSignal->DcmDspDidDataRef;

		u16SignalSize = (pSignalData->DcmDspDataSize / 8u);

		switch(pSignalData->DcmDspDataUsePort)
		{
#if(STD_ON == DCM_DSP_DATA_READ_ECU_SIGNAL_FNC_ENABLED)
		/**
		 * @req [SWS_Dcm_00578] On reception of the UDS Service ReadDataByIdentifier (0x22), for every
		 * 		requested DID outside the OBD range (F400-F8FF), after all verification (see
		 * 		SWS_Dcm_00433, SWS_Dcm_00434 and SWS_Dcm_00435), If the data is configured as a "ECU
		 * 		signal" of the IoHwAb (parameter DcmDspDataUsePort), the DCM shall call the Api
		 * 		IoHwAb_Dcm_Read<EcuSignalName >() (parameter DcmDspDataReadEcuSignal) to get the Data.
		 * 		In this case, the requirements SWS_Dcm_00439, SWS_Dcm_00436 and SWS_Dcm_00437 shall not
		 * 		apply.
		 */
		case DCM_USE_ECU_SIGNAL:
			if(NULL_PTR != pSignalData->DcmDspDataReadEcuSignal)
			{
				result = pSignalData->DcmDspDataReadEcuSignal(pDidData);
			}
			break;
#endif /* #if(STD_ON == DCM_DSP_DATA_READ_ECU_SIGNAL_FNC_ENABLED) */
#if(STD_ON == DCM_DSP_DATA_READ_FNC_ENABLED)
		case DCM_USE_DATA_SYNCH_FNC:
		case DCM_USE_DATA_SYNCH_CLIENT_SERVER:
		case DCM_USE_DATA_ASYNCH_FNC:
		case DCM_USE_DATA_ASYNCH_FNC_ERROR:
		case DCM_USE_DATA_ASYNCH_CLIENT_SERVER:
		case DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR:
			result = (Std_ReturnType)E_OK;
#if(STD_ON == DCM_DSP_DATA_CONDITION_CHECK_READ_FNC_ENABLED)
			/**
			 * @req [SWS_Dcm_00439] On reception of the UDS Service ReadDataByIdentifier (0x22), for
			 * 		every requested DID outside the OBD range (F400-F8FF), the DCM module shall request
			 * 		the application if the DID can be read by calling the configured function (if
			 * 		parameter DcmDspDataUsePort set to USE_DATA_SYNCH_FNC or USE_DATA_ASYNCH_FNC or
			 * 		USE_DATA_ASYNCH_FNC_ERROR; see configuration parameter
			 * 		DcmDspDataConditionCheckReadFnc) on each data of the DID or call the associated
			 * 		ConditionCheckRead operation (if parameter DcmDspDataUsePort set to
			 * 		USE_DATA_SYNCH_CLIENT_SERVER or USE_DATA_ASYNCH_CLIENT_SERVER or
			 * 		USE_DATA_ASYNCH_CLIENT_SERVER_ERROR). If not (one function returns E_NOT_OK) , the
			 * 		DCM module shall send a negative response with NRC set to value from the parameter
			 * 		"ErrorCode" of DcmDspDataConditionCheckReadFnc function or ConditionCheckRead
			 * 		operation.
			 */
			if((boolean)TRUE == pSignalData->DcmDspDataConditionCheckReadFncUsed)
			{
				result = pSignalData->DcmDspDataConditionCheckReadFnc(opState, pErrorCode);
			}
#endif /* #if(STD_ON == DCM_DSP_DATA_CONDITION_CHECK_READ_FNC_ENABLED) */

#if(STD_ON == DCM_DSP_DATA_READ_DATA_LENGTH_FNC_ENABLED)
			/**
			 * @req [SWS_Dcm_00436] On reception of the UDS Service ReadDataByIdentifier (0x22), for
			 * 		every requested DID outside the OBD range (F400-F8FF), the DCM module shall for each
			 * 		signal (DcmDspDidSignal) with a dynamic data length (DcmDspDataType is set to
			 * 		UINT8_DYN): call either the configured function DcmDspDataReadDataLengthFnc (if
			 * 		parameter DcmDspDataUsePort set to USE_DATA_SYNCH_FNC or USE_DATA_ASYNCH_FNC or
			 * 		USE_DATA_ASYNCH_FNC_ERROR) or the associated ReadDataLength operation (if parameter
			 * 		DcmDspDataUsePort set to USE_DATA_SYNCH_CLIENT_SERVER or
			 * 		USE_DATA_ASYNCH_CLIENT_SERVER or USE_DATA_ASYNCH_CLIENT_SERVER_ERROR) to get the
			 * 		data length in byte.
			 */
			if(((Std_ReturnType)E_OK == result) && (DCM_UINT8_DYN == pSignalData->DcmDspDataType))
			{
				result = pSignalData->DcmDspDataReadDataLengthFnc(opState, &u16SignalSize);
			}
#endif /* #if(STD_ON == DCM_DSP_DATA_READ_DATA_LENGTH_FNC_ENABLED) */

			if((Std_ReturnType)E_OK == result)
			{
				result = (Std_ReturnType)E_NOT_OK;

				/**
				 * @req [SWS_Dcm_00437] After all verification (see SWS_Dcm_00433, SWS_Dcm_00434,
				 * 		SWS_Dcm_00435 and SWS_Dcm_00436) the DCM module shall get for every requested
				 * 		DID outside the OBD range (F400-F8FF), all the data values by calling all the
				 * 		configured function (if parameter DcmDspDataUsePort set to USE_DATA_SYNCH_FNC or
				 * 		USE_DATA_ASYNCH_FNC or USE_DATA_ASYNCH_FNC_ERROR; see configuration parameter
				 * 		DcmDspDataReadFnc) or call all the associated ReadData operations (if parameter
				 * 		DcmDspDataUsePort set to USE_DATA_SYNCH_CLIENT_SERVER or
				 * 		USE_DATA_ASYNCH_CLIENT_SERVER or USE_DATA_ASYNCH_CLIENT_SERVER_ERROR) or read
				 * 		all the associated SenderReceiver interfaces (if parameter DcmDspDataUsePort set
				 * 		to USE_DATA_SENDER_RECEIVER or to USE_DATA_SENDER_RECEIVER_AS_SERVICE).
				 */
				if(NULL_PTR != pSignalData->DcmDspDataReadFnc)
				{
					if((DCM_USE_DATA_ASYNCH_FNC_ERROR == pSignalData->DcmDspDataUsePort) ||\
						(DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR == pSignalData->DcmDspDataUsePort))
					{
						result = pSignalData->DcmDspDataReadFnc(opState, pDidData, pErrorCode);
					}
					else
					{
						result = pSignalData->DcmDspDataReadFnc(opState, pDidData, NULL_PTR);
					}
				}
			}
			break;
		case DCM_USE_DATA_SENDER_RECEIVER:
		case DCM_USE_DATA_SENDER_RECEIVER_AS_SERVICE:
			/**
			 * @req [SWS_Dcm_00962] The Dcm shall create for each configured DcmDspData element
			 * 		having a sender/receiver interface (if parameter DcmDspDataUsePort is set to
			 * 		USE_DATA_SENDER_RECEIVER or to USE_DATA_SENDER_RECEIVER_AS_SERVICE) which is
			 * 		read (DcmDspDidRead) a corresponding R-Port DataInterface with one data element
			 * 		having an ImplementationDataType of type DcmDspDataType.
			 */
			if(NULL_PTR != pSignalData->DcmDspDataReadFnc)
			{
				result = pSignalData->DcmDspDataReadFnc(opState, pDidData, pErrorCode);
			}
			break;
#endif /* #if(STD_ON == DCM_DSP_DATA_READ_FNC_ENABLED) */
#if(0u != DCM_DSP_DATA_BLOCK_USED_NUM)
			/**
			 * @req [SWS_Dcm_00560] If the data is configured as a BlockId of the NvRam (parameter
			 * 		DcmDspDataUsePort), the DCM shall call the Api NvM_ReadBlock() with the BlockId
			 * 		(parameter DcmDspDataBlockIdRef).
			 */
			case DCM_USE_BLOCK_ID:
#if(0u)
				if((boolean)FALSE == Dcm_UDS0x22Status.ReadBlock)
				{
					if((Std_ReturnType)E_OK == NvM_ReadBlock(pSignalData->DcmDspDataBlockIdRef, pDidData))
					{
						Dcm_UDS0x22Status.ReadBlock = (boolean)TRUE;

						result = (Std_ReturnType)DCM_E_PENDING;
					}
					else
					{
						*pErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
					}
				}
				else
				{
					if((Std_ReturnType)E_OK == NvM_GetErrorStatus(pSignalData->DcmDspDataBlockIdRef, &NvMRet))
					{
						if(NVM_REQ_OK == NvMRet)
						{
							Dcm_UDS0x22Status.ReadBlock = (boolean)FALSE;

							result = (Std_ReturnType)E_OK;
						}
						else if(NVM_REQ_PENDING == NvMRet)
						{
							result = (Std_ReturnType)DCM_E_PENDING;
						}
						else
						{
							/* Nothing to do here. */
							;
						}
					}
					else
					{
						*pErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
					}
				}
#else
				DCM_MEMORY_COPY(pSignalData->DcmDspDataInternalBuffer, pDidData, u16SignalSize);

				result = (Std_ReturnType)E_OK;
#endif /* #if(0u) */
				break;
#endif /* #if(0u != DCM_DSP_DATA_BLOCK_USED_NUM) */
		default:
			/* Nothing to do here. */
			break;
		}

		if((Std_ReturnType)E_OK == result)
		{
#if(STD_ON == DCM_UDS0x2C_ENABLE)
			if((boolean)FALSE == isDDDid)
			{
#endif /* #if(STD_ON == DCM_UDS0x2C_ENABLE) */

				Dcm_UDS0x22Status.DidDataLen += u16SignalSize;

#if(STD_ON == DCM_UDS0x2C_ENABLE)
			}
#endif /* #if(STD_ON == DCM_UDS0x2C_ENABLE) */
		}
		else
		{
			break;
		}
	}

#endif /* #if(0u != DCM_DSP_DID_SIGNAL_NUM) */

	return result;
}
#endif /* #if(0u != DCM_DSP_DID_NUM) */

#if(0u != DCM_DSP_DID_RANGE_NUM)
/**
 * @brief			Dcm_UDS0x22RangeDidProcess
 * @details			Handler for reading Range-Did data.
 *
 * @param[in]		u8ReqDidIdx:The index of the range Did to be read within the configuration.
 * @param[in]		opState:Operating state.
 *
 * @param[out]		pErrorCode:If the called external interface returns E_NOT_OK, use this pointer to
 * 					output the NRC.
 *
 * @return        	Result of this operation.
 * @retval			E_OK:Processing successful.
 * @retval			E_NOT_OK:Processing failure.
 */
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x22RangeDidProcess
(
	uint8 u8ReqDidIdx,
	Dcm_OpStatusType opState,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
)
{
	Std_ReturnType result = (Std_ReturnType)E_OK;

	uint16 u16ReqDid = Dcm_UDS0x22Status.ReqDid;
	const Dcm_DspDidRangeType* pRangeDid = &Dcm_ConfigPtr->DcmDsp->DcmDspDidRange[u8ReqDidIdx];
	uint16 u16DataLen = pRangeDid->DcmDspDidRangeMaxDataLength;

#if(STD_ON == DCM_DSP_DID_RANGE_READ_DID_FNC_ENABLE)
#if(STD_ON == DCM_DSP_DID_RANGE_READ_DATA_LENGTH_FNC_ENABLE)
	if(NULL_PTR != pRangeDid->DcmDspDidRangeReadDataLengthFnc)
	{
		result = pRangeDid->DcmDspDidRangeReadDataLengthFnc(u16ReqDid, opState, &u16DataLen);
	}

	if((Std_ReturnType)E_OK == result)
	{
#endif /* #if(STD_ON == DCM_DSP_DID_RANGE_READ_DATA_LENGTH_FNC_ENABLE) */
		result = (Std_ReturnType)E_NOT_OK;

		if(NULL_PTR != pRangeDid->DcmDspDidRangeReadDidFnc)
		{
			result = pRangeDid->DcmDspDidRangeReadDidFnc(\
						u16ReqDid, &Dcm_UDS0x22Status.DidData[2], opState, &u16DataLen, pErrorCode\
						);
		}

		if((Std_ReturnType)E_OK == result)
		{
			Dcm_UDS0x22Status.DidDataLen += (uint32)u16DataLen;
		}
#if(STD_ON == DCM_DSP_DID_RANGE_READ_DATA_LENGTH_FNC_ENABLE)
	}
#endif /* #if(STD_ON == DCM_DSP_DID_RANGE_READ_DATA_LENGTH_FNC_ENABLE) */
#else
	result = (Std_ReturnType)E_NOT_OK;
#endif /* #if(STD_ON == DCM_DSP_DID_RANGE_READ_DID_FNC_ENABLE) */

	return result;
}
#endif /* #if(0u != DCM_DSP_DID_RANGE_NUM) */

#if(STD_ON == DCM_UDS0x2C_ENABLE)
#if((STD_ON == DCM_UDS0x2C_SUB0x01_ENABLE) || (STD_ON == DCM_UDS0x2C_SUB0x02_ENABLE))
/**
 * @brief			Dcm_UDS0x22DynDefDidProcess
 * @details			Handler for reading DDDid data.
 *
 * @param[in]		u8ReqDidIdx:The index of the DDDid to be read within the configuration.
 * @param[in]		opState:Operating state.
 *
 * @param[out]		pErrorCode:If the called external interface returns E_NOT_OK, use this pointer to
 * 					output the NRC.
 *
 * @return        	Result of this operation.
 * @retval			E_OK:Processing successful.
 * @retval			E_NOT_OK:Processing failure.
 */
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x22DynDefDidProcess
(
	uint8 u8ReqDidIdx,
	Dcm_OpStatusType opState,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
)
{
	Std_ReturnType result = (Std_ReturnType)E_NOT_OK;

	uint8 u8Index;
	uint8 u8DataPos;
	uint8 u8DataLen;
#if(STD_ON == DCM_UDS0x2C_SUB0x02_ENABLE)
	Dcm_ReturnReadMemoryType callRet = DCM_READ_FAILED;
#endif /* #if(STD_ON == DCM_UDS0x2C_SUB0x02_ENABLE) */
	const Dcm_DspDidInfoType* pDidInfo = Dcm_ConfigPtr->DcmDsp->DcmDspDid[u8ReqDidIdx].DcmDspDidInfoRef;
	Dcm_DDDIdElementStatus* pElementStatus = NULL_PTR;

	for(u8Index = Dcm_UDS0x22Status.ReqElementIndex; u8Index < Dcm_DDDidStatus[pDidInfo->DcmDspDDDIDIndex].ElementNum; u8Index++)
	{
		Dcm_UDS0x22Status.ReqElementIndex = u8Index;

		pElementStatus = &Dcm_DDDidStatus[pDidInfo->DcmDspDDDIDIndex].ElementStatus[u8Index];

#if((STD_ON == DCM_UDS0x2C_SUB0x01_ENABLE) && (STD_ON == DCM_UDS0x2C_SUB0x02_ENABLE))
		if((boolean)TRUE == pElementStatus->IsDidType)
		{
			result = Dcm_UDS0x22SingleDidProcess(\
							pElementStatus->Element.SrcDid.SrcDidIndex, opState, (boolean)TRUE, pErrorCode\
							);

			if((Std_ReturnType)E_OK == result)
			{
				Dcm_UDS0x22Status.ReqSignalIndex = 0u;

				u8DataPos = (pElementStatus->Element.SrcDid.SrcDidDataPos - 1u);
				u8DataLen = pElementStatus->Element.SrcDid.SrcDidDataLen;

				DCM_MEMORY_COPY(\
						&Dcm_UDS0x22Status.DidData[u8DataPos + Dcm_UDS0x22Status.DidDataLen],\
						&Dcm_UDS0x22Status.DidData[Dcm_UDS0x22Status.DidDataLen],\
						u8DataLen\
						);

				Dcm_UDS0x22Status.DidDataLen += u8DataLen;
			}
		}
		else
		{
			/**
			 * @req [SWS_Dcm_00653] On reception of the UDS Service ReadDataByIdentifier (0x22) with
			 * 		DID in the range 0xF200 to 0xF3FF, if verification has been successfully done (see
			 * 		SWS_Dcm_00651) and the dynamic DID has been defined with a memory address (see
			 * 		SWS_Dcm_00646), the DCM module shall use the callout Dcm_ReadMemory to read the
			 * 		data.
			 */
			callRet = Dcm_ReadMemory(opState,\
							pElementStatus->Element.Memory.MemoryId,\
							pElementStatus->Element.Memory.MemoryAddress,\
							pElementStatus->Element.Memory.MemorySize,\
							&Dcm_UDS0x22Status.DidData[Dcm_UDS0x22Status.DidDataLen],\
							pErrorCode\
							);

			switch(callRet)
			{
			case DCM_READ_OK:
				Dcm_UDS0x22Status.DidDataLen += pElementStatus->Element.Memory.MemorySize;
				result = (Std_ReturnType)E_OK;
				break;
			case DCM_READ_PENDING:
				result = (Std_ReturnType)DCM_E_PENDING;
				break;
			case DCM_READ_FORCE_RCRRP:
				result = (Std_ReturnType)DCM_E_FORCE_RCRRP;
				break;
			default:
				result = (Std_ReturnType)E_NOT_OK;
				break;
			}
		}
#elif(STD_ON == DCM_UDS0x2C_SUB0x01_ENABLE)
		result = Dcm_UDS0x22SingleDidProcess(\
						pElementStatus->Element.SrcDid.SrcDidIndex, opState, (boolean)TRUE, pErrorCode\
						);

		if((Std_ReturnType)E_OK == result)
		{
			Dcm_UDS0x22Status.ReqSignalIndex = 0u;

			u8DataPos = (pElementStatus->Element.SrcDid.SrcDidDataPos - 1u);
			u8DataLen = pElementStatus->Element.SrcDid.SrcDidDataLen;

			DCM_MEMORY_COPY(\
					&Dcm_UDS0x22Status.DidData[u8DataPos + Dcm_UDS0x22Status.DidDataLen],\
					&Dcm_UDS0x22Status.DidData[Dcm_UDS0x22Status.DidDataLen],\
					u8DataLen\
					);

			Dcm_UDS0x22Status.DidDataLen += u8DataLen;
		}
#else
		/**
		 * @req [SWS_Dcm_00653] On reception of the UDS Service ReadDataByIdentifier (0x22) with
		 * 		DID in the range 0xF200 to 0xF3FF, if verification has been successfully done (see
		 * 		SWS_Dcm_00651) and the dynamic DID has been defined with a memory address (see
		 * 		SWS_Dcm_00646), the DCM module shall use the callout Dcm_ReadMemory to read the
		 * 		data.
		 */
		callRet = Dcm_ReadMemory(opState,\
						pElementStatus->Element.Memory.MemoryId,\
						pElementStatus->Element.Memory.MemoryAddress,\
						pElementStatus->Element.Memory.MemorySize,\
						&Dcm_UDS0x22Status.DidData[Dcm_UDS0x22Status.DidDataLen],\
						pErrorCode\
						);

		switch(callRet)
		{
		case DCM_READ_OK:
			Dcm_UDS0x22Status.DidDataLen += pElementStatus->Element.Memory.MemorySize;
			result = (Std_ReturnType)E_OK;
			break;
		case DCM_READ_PENDING:
			result = (Std_ReturnType)DCM_E_PENDING;
			break;
		case DCM_READ_FORCE_RCRRP:
			result = (Std_ReturnType)DCM_E_FORCE_RCRRP;
			break;
		default:
			result = (Std_ReturnType)E_NOT_OK;
			break;
		}
#endif /* #if((STD_ON == DCM_UDS0x2C_SUB0x01_ENABLE) && (STD_ON == DCM_UDS0x2C_SUB0x02_ENABLE)) */

		if((Std_ReturnType)E_OK != result)
		{
			break;
		}
	}

	return result;
}
#endif /* #if((STD_ON == DCM_UDS0x2C_SUB0x01_ENABLE) || (STD_ON == DCM_UDS0x2C_SUB0x02_ENABLE)) */
#endif /* #if(STD_ON == DCM_UDS0x2C_ENABLE) */

/**
 * @brief			Dcm_UDS0x22DidProcess
 * @details			Check whether the Did is valid and execute the corresponding handler.
 *
 * @param[in]		opState:Operating state.
 *
 * @param[out]		pErrorCode:If the called external interface returns E_NOT_OK, use this pointer to
 * 					output the NRC.
 *
 * @return        	Result of this operation.
 * @retval			E_OK:Processing successful.
 * @retval			E_NOT_OK:Processing failure.
 */
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x22DidProcess
(
	Dcm_OpStatusType opState,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
)
{
	Std_ReturnType result = (Std_ReturnType)E_NOT_OK;

#if((0u != DCM_DSP_DID_NUM) || (0u != DCM_DSP_DID_RANGE_NUM))

	uint8 u8ReqDidIdx = 0xFFu;
	/* 0x01: Single Did, 0x02: Range Did, 0x03: DDDid. */
	uint8 u8DidType = 0x01u;

	result = Dcm_UDS0x22ReqDidCheck(opState, &u8ReqDidIdx, &u8DidType, pErrorCode);

	if((Std_ReturnType)E_OK == result)
	{
		switch(u8DidType)
		{
#if(0u != DCM_DSP_DID_NUM)
		case 0x01u:
#if(STD_ON == DCM_UDS0x2C_ENABLE)
			result = Dcm_UDS0x22SingleDidProcess(u8ReqDidIdx, opState, (boolean)FALSE, pErrorCode);
#else
			result = Dcm_UDS0x22SingleDidProcess(u8ReqDidIdx, opState, pErrorCode);
#endif /* #if(STD_ON == DCM_UDS0x2C_ENABLE) */
			break;
#endif /* #if(0u != DCM_DSP_DID_NUM) */
#if(0u != DCM_DSP_DID_RANGE_NUM)
		case 0x02u:
			result = Dcm_UDS0x22RangeDidProcess(u8ReqDidIdx, opState, pErrorCode);
			break;
#endif /* #if(0u != DCM_DSP_DID_RANGE_NUM) */
#if(STD_ON == DCM_UDS0x2C_ENABLE)
#if((STD_ON == DCM_UDS0x2C_SUB0x01_ENABLE) || (STD_ON == DCM_UDS0x2C_SUB0x02_ENABLE))
		case 0x03u:
			result = Dcm_UDS0x22DynDefDidProcess(u8ReqDidIdx, opState, pErrorCode);
			break;
#endif /* #if((STD_ON == DCM_UDS0x2C_SUB0x01_ENABLE) || (STD_ON == DCM_UDS0x2C_SUB0x02_ENABLE)) */
#endif /* #if(STD_ON == DCM_UDS0x2C_ENABLE) */
		default:
			/* Nothing to do here. */
			break;
		}
	}

#endif /* #if((0u != DCM_DSP_DID_NUM) || (0u != DCM_DSP_DID_RANGE_NUM)) */

	return result;
}
/*====================================================================================================*
 *                                          GLOBAL FUNCTIONS
 *====================================================================================================*/
/**
 * @brief			Dcm_UDS0x22
 * @details			Internal processing interface for Service 0x22.
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
FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x22
(
	Dcm_OpStatusType OpStatus,
	P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
)
{
	Std_ReturnType result = (Std_ReturnType)E_OK;

	uint8 u8Index;
	uint8 u8ReqDidNum = (uint8)(pMsgContext->ReqDataLen >> 1u);
	boolean flag = (boolean)FALSE;

	if((DCM_PENDING != OpStatus)
#if(STD_ON == DCM_UDS0x2C_ENABLE)
		&& (DCM_FORCE_RCRRP_OK != OpStatus)
#endif /* #if(STD_ON == DCM_UDS0x2C_ENABLE) */
	)
	{
		if((3u > pMsgContext->ReqDataLen) ||\
			(DCM_DSP_MAX_DID_TO_READ < u8ReqDidNum) ||\
			(pMsgContext->ReqDataLen != (((uint32)u8ReqDidNum * 2u) + 1u)))
		{
			*ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;

			result = (Std_ReturnType)E_NOT_OK;
		}
		else
		{
			Dcm_UDS0x22Status.ReqDid = 0u;
			Dcm_UDS0x22Status.ReqDidIndex = 0u;
			Dcm_UDS0x22Status.ReqSignalIndex = 0u;
#if(STD_ON == DCM_UDS0x2C_ENABLE)
			Dcm_UDS0x22Status.ReqElementIndex = 0u;
#endif /* #if(STD_ON == DCM_UDS0x2C_ENABLE) */
			Dcm_UDS0x22Status.DidDataLen = 2u;
			Dcm_UDS0x22Status.DataTotalLen = 1u;
			Dcm_UDS0x22Status.ReadDidNum = 0u;
#if(0u != DCM_DSP_DATA_BLOCK_USED_NUM)
			Dcm_UDS0x22Status.ReadBlock = (boolean)FALSE;
#endif /* #if(0u != DCM_DSP_DATA_BLOCK_USED_NUM) */
		}
	}

	if((Std_ReturnType)E_OK == result)
	{
		for(u8Index = Dcm_UDS0x22Status.ReqDidIndex; u8Index < u8ReqDidNum; u8Index++)
		{
			Dcm_UDS0x22Status.ReqDid = (uint16)pMsgContext->ReqData[(u8Index * 2u) + 1u] << 8u;
			Dcm_UDS0x22Status.ReqDid |= (uint16)pMsgContext->ReqData[(u8Index * 2u) + 2u];

			result = Dcm_UDS0x22DidProcess(OpStatus, ErrorCode);

			if((Std_ReturnType)E_OK == result)
			{
				Dcm_UDS0x22Status.DidData[0] = (uint8)(Dcm_UDS0x22Status.ReqDid >> 8u);
				Dcm_UDS0x22Status.DidData[1] = (uint8)Dcm_UDS0x22Status.ReqDid;

				if(pMsgContext->ResMaxDataLen >= (Dcm_UDS0x22Status.DataTotalLen + Dcm_UDS0x22Status.DidDataLen))
				{
					DCM_MEMORY_COPY(\
							Dcm_UDS0x22Status.DidData,\
							&pMsgContext->ResData[Dcm_UDS0x22Status.DataTotalLen],\
							Dcm_UDS0x22Status.DidDataLen\
							);

					Dcm_UDS0x22Status.DataTotalLen += Dcm_UDS0x22Status.DidDataLen;

					Dcm_UDS0x22Status.DidDataLen = 2u;
					Dcm_UDS0x22Status.ReqSignalIndex = 0u;
#if(STD_ON == DCM_UDS0x2C_ENABLE)
					Dcm_UDS0x22Status.ReqElementIndex = 0u;
#endif /* #if(STD_ON == DCM_UDS0x2C_ENABLE) */
					Dcm_UDS0x22Status.ReadDidNum++;
#if(0u != DCM_DSP_DATA_BLOCK_USED_NUM)
					Dcm_UDS0x22Status.ReadBlock = (boolean)FALSE;
#endif /* #if(0u != DCM_DSP_DATA_BLOCK_USED_NUM) */
				}
				else
				{
					*ErrorCode = DCM_E_RESPONSETOOLONG;

					result = (Std_ReturnType)E_NOT_OK;
				}
			}

			if((Std_ReturnType)E_OK != result)
			{
				if((Std_ReturnType)DCM_E_PENDING == result)
				{
					Dcm_UDS0x22Status.ReqDidIndex = u8Index;

					Dcm_OpState = DCM_PENDING;
					*ErrorCode = DCM_E_RESPONSE_PENDING;

					flag = (boolean)TRUE;

					result = (Std_ReturnType)E_NOT_OK;
				}
#if(STD_ON == DCM_UDS0x2C_ENABLE)
				else if((Std_ReturnType)DCM_E_FORCE_RCRRP == result)
				{
					Dcm_UDS0x22Status.ReqDidIndex = u8Index;

					Dcm_OpState = DCM_FORCE_RCRRP_OK;
					*ErrorCode = DCM_E_RESPONSE_PENDING;

					flag = (boolean)TRUE;

					result = (Std_ReturnType)E_NOT_OK;
				}
#endif /* #if(STD_ON == DCM_UDS0x2C_ENABLE) */
				else
				{
					if((DCM_E_SECURITYACCESSDENIED == *ErrorCode) ||\
						(DCM_E_CONDITIONSNOTCORRECT == *ErrorCode) ||\
						(DCM_E_AUTHENTICATIONREQUIRED == *ErrorCode) ||\
						(DCM_E_GENERALPROGRAMMINGFAILURE == *ErrorCode) ||\
						(DCM_E_RESPONSETOOLONG == *ErrorCode))
					{
						flag = (boolean)TRUE;
					}
				}

				if((boolean)TRUE == flag)
				{
					break;
				}
			}
		}

		if(u8Index == u8ReqDidNum)
		{
			if(0u != Dcm_UDS0x22Status.ReadDidNum)
			{
				pMsgContext->ResData[0] = 0x62u;
				pMsgContext->ResDataLen = Dcm_UDS0x22Status.DataTotalLen;

				result = (Std_ReturnType)E_OK;
			}
			else
			{
				*ErrorCode = DCM_E_REQUESTOUTOFRANGE;

				result = (Std_ReturnType)E_NOT_OK;
			}
		}
	}

	return result;
}

#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#endif /* #if(STD_ON == DCM_UDS0x22_INTERNAL_FNC_ENABLE) */
#endif /* #if(STD_ON == DCM_UDS0x22_ENABLE) */

#ifdef __cplusplus
}
#endif
/** @} */
