/**
 * @file        Dcm_UDS0x2C.c
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

/* PRQA S 0292, 0857, 0491, 2981, 2877, 5087 EOF #
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
 * 5.2877 -- Violates MISRA 2004 Required Rule 21.1, This loop will never be executed more than once.
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

#if(STD_ON == DCM_UDS0x2C_ENABLE)
#if(STD_ON == DCM_UDS0x2C_INTERNAL_FNC_ENABLE)
/**
 * @req [SWS_Dcm_00259] The DSP submodule shall implement the DynamicallyDefineDataIdentifier (service
 * 		0x2C, diagnostic data access) of the Unified Diagnostic Services.
 */
/*====================================================================================================*
 *                                  SOURCE FILE VERSION INFORMATION
 *====================================================================================================*/
#define DCM_UDS0X2C_VENDOR_ID_C                            	(0x00U)
#define DCM_UDS0X2C_AR_RELEASE_MAJOR_VERSION_C             	(0x04U)
#define DCM_UDS0X2C_AR_RELEASE_MINOR_VERSION_C             	(0x02U)
#define DCM_UDS0X2C_AR_RELEASE_REVISION_VERSION_C          	(0x02U)
#define DCM_UDS0X2C_SW_MAJOR_VERSION_C                     	(0x01U)
#define DCM_UDS0X2C_SW_MINOR_VERSION_C                     	(0x02U)
#define DCM_UDS0X2C_SW_PATCH_VERSION_C                     	(0x00U)
/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/
/* Check if current file and Dcm_Internal header file are of the same vendor */
#if(DCM_UDS0X2C_VENDOR_ID_C != DCM_INTERNAL_VENDOR_ID )
#error "Dcm_UDS0x2C.c and Dcm_Internal.h have different vendor id"
#endif
/* Check if current file and Dcm_Internal header file are of the same Autosar version */
#if(\
		(DCM_UDS0X2C_AR_RELEASE_MAJOR_VERSION_C != DCM_INTERNAL_AR_RELEASE_MAJOR_VERSION) || \
		(DCM_UDS0X2C_AR_RELEASE_MINOR_VERSION_C != DCM_INTERNAL_AR_RELEASE_MINOR_VERSION) || \
		(DCM_UDS0X2C_AR_RELEASE_REVISION_VERSION_C != DCM_INTERNAL_AR_RELEASE_REVISION_VERSION) \
)
#error "AutoSar Version Number of Dcm_UDS0x2C.c and Dcm_Internal.h are different"
#endif
/* Check if current file and Dcm_Internal header file are of the same software version */
#if(\
		(DCM_UDS0X2C_SW_MAJOR_VERSION_C != DCM_INTERNAL_SW_MAJOR_VERSION) || \
		(DCM_UDS0X2C_SW_MINOR_VERSION_C != DCM_INTERNAL_SW_MINOR_VERSION) || \
		(DCM_UDS0X2C_SW_PATCH_VERSION_C != DCM_INTERNAL_SW_PATCH_VERSION) \
)
#error "Software Version Number of Dcm_UDS0x2C.c and Dcm_Internal.h are different"
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

/*====================================================================================================*
 *                                      LOCAL FUNCTION PROTOTYPES
 *====================================================================================================*/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"

#if(0u != DCM_DSP_DDDID_NUM)
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x2CReqDDDidCheck
(
	P2VAR(uint8, AUTOMATIC, DCM_VAR)pReqDDDidIdx,
	P2CONST(Dcm_MsgContextType, AUTOMATIC, DCM_CONST)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
);
#endif /* #if(0u != DCM_DSP_DDDID_NUM) */

#if(STD_ON == DCM_UDS0x2C_SUB0x01_ENABLE)
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x2CDefineByDid
(
	P2CONST(Dcm_MsgContextType, AUTOMATIC, DCM_CONST)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
);
#endif /* #if(STD_ON == DCM_UDS0x2C_SUB0x01_ENABLE) */

#if(STD_ON == DCM_UDS0x2C_SUB0x02_ENABLE)
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x2CDefineByMemoryAddress
(
	P2CONST(Dcm_MsgContextType, AUTOMATIC, DCM_CONST)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
);
#endif /* #if(STD_ON == DCM_UDS0x2C_SUB0x02_ENABLE) */

#if(STD_ON == DCM_UDS0x2C_SUB0x03_ENABLE)
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x2CClearDynamicallyDefinedDid
(
	P2CONST(Dcm_MsgContextType, AUTOMATIC, DCM_CONST)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
);
#endif /* #if(STD_ON == DCM_UDS0x2C_SUB0x03_ENABLE) */
/*====================================================================================================*
 *                                           LOCAL FUNCTIONS
 *====================================================================================================*/
#if(0u != DCM_DSP_DDDID_NUM)
/**
 * @brief			Dcm_UDS0x2CReqDDDidCheck
 * @details			Check whether the requested DDDid is valid.
 *
 * @param[in]		pMsgContext:Message-related information for one diagnostic protocol identifier. The
 * 					pointers in pMsgContext shall point behind the SID.
 *
 * @param[out]		pReqDDDidIdx:If the requested DDDid is valid, output its index within the
 * 					configuration.
 * @param[out]		pErrorCode:If error occur, output the NRC.
 *
 * @return        	Result of this operation.
 * @retval			E_OK:Processing successful.
 * @retval			E_NOT_OK:Processing failure.
 */
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x2CReqDDDidCheck
(
	P2VAR(uint8, AUTOMATIC, DCM_VAR)pReqDDDidIdx,
	P2CONST(Dcm_MsgContextType, AUTOMATIC, DCM_CONST)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
)
{
	Std_ReturnType result;

	uint16 u16ReqDDDid;

	u16ReqDDDid = (uint16)pMsgContext->ReqData[2] << 8u;
	u16ReqDDDid |= (uint16)pMsgContext->ReqData[3];

	/**
	 * @req [SWS_Dcm_00723] On reception of the UDS Service DynamicallyDefineDataIdentifier (0x2C), the
	 * 		DCM module shall check if the DDDID can be defined in the current session (see configuration
	 * 		parameter DcmDspDidReadSessionRef). If not, the DCM module shall send a NRC 0x31 (Request
	 * 		out of Range).
	 *
	 * @req [SWS_Dcm_00724] On reception of the UDS Service DynamicallyDefineDataIdentifier (0x2C), the
	 * 		DCM module shall check if the DDDID can be defined in the current security level (see
	 * 		configuration parameter DcmDspDidReadSecurityLevelRef). If not, the DCM module shall send
	 * 		NRC 0x33 (Security access denied).
	 */
	result = DspInternal_CheckDidValid(\
				u16ReqDDDid, DCM_PERMISSION_CHECK_USER_DYNAMICALLY_DEFINE_DID, pReqDDDidIdx, NULL_PTR, NULL_PTR, pErrorCode\
				);

	return result;
}
#endif /* #if(0u != DCM_DSP_DDDID_NUM) */

#if(STD_ON == DCM_UDS0x2C_SUB0x01_ENABLE)
/**
 * @brief			Dcm_UDS0x2CDefineByDid
 * @details			Define DDDid by Did process.
 *
 * @param[in]		pMsgContext:Message-related information for one diagnostic protocol identifier. The
 * 					pointers in pMsgContext shall point behind the SID.
 *
 * @param[out]		pErrorCode:If error occur, output the NRC.
 *
 * @return        	Result of this operation.
 * @retval			E_OK:Processing successful.
 * @retval			E_NOT_OK:Processing failure.
 */
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x2CDefineByDid
(
	P2CONST(Dcm_MsgContextType, AUTOMATIC, DCM_CONST)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
)
{
	Std_ReturnType result = (Std_ReturnType)E_NOT_OK;

	uint8 u8DidIdx;
	uint8 u8ReqSourceDidNum;
	uint8 u8ReqSourceDidPos;
	uint8 u8ReqSourceDidMemSize;
	uint8 u8SourceDidIndex;
	uint8 u8ElementNum;
	uint16 u16ReqSourceDid;
	Dcm_SessionDataType sesLevelRef;
	Dcm_SecurityDataType secLevelRef;
	const Dcm_DspDidInfoType* pDDDidInfo = NULL_PTR;

	if(0u != ((pMsgContext->ReqDataLen - 4u) % 4u))
	{
		*pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
	}
	else
	{
#if(0u != DCM_DSP_DDDID_NUM)

		if((Std_ReturnType)E_OK == Dcm_UDS0x2CReqDDDidCheck(&u8DidIdx, pMsgContext, pErrorCode))
		{
			u8ReqSourceDidNum = (uint8)((pMsgContext->ReqDataLen - 4u) / 4u);

			pDDDidInfo = Dcm_ConfigPtr->DcmDsp->DcmDspDid[u8DidIdx].DcmDspDidInfoRef;

			u8ElementNum = Dcm_DDDidStatus[pDDDidInfo->DcmDspDDDIDIndex].ElementNum;

			/**
			 * @req [SWS_Dcm_00861] On reception of the UDS Service DynamicallyDefineDataIdentifier (0x2C),
			 * 		the DCM module shall check if the DDDID will not exceed the configured parameter value
			 * 		DcmDspDDDIDMaxElements. Otherwise (in case the number of elements will be exceeded) the
			 * 		DCM module shall send a NRC 0x31 (Request out of Range).
			 */
			if((0u == pDDDidInfo->DcmDspDDDIDMaxElements) ||\
				((u8ElementNum + u8ReqSourceDidNum) > pDDDidInfo->DcmDspDDDIDMaxElements))
			{
				*pErrorCode = DCM_E_REQUESTOUTOFRANGE;
			}
			else
			{
				for(u8SourceDidIndex = 0u; u8SourceDidIndex < u8ReqSourceDidNum; u8SourceDidIndex++)
				{
					u16ReqSourceDid = (uint16)pMsgContext->ReqData[(u8SourceDidIndex * 4u) + 4u] << 8u;
					u16ReqSourceDid |= (uint16)pMsgContext->ReqData[(u8SourceDidIndex * 4u) + 5u];

					/**
					 * @req [SWS_Dcm_00725] On reception of the UDS Service DynamicallyDefineDataIdentifier
					 * 		(0x2C), the DCM module shall check if the requested Source-DIDs are supported in
					 * 		the current session (see configuration parameter of referenced DID
					 * 		DcmDspDidReadSessionRef)). If not, the DCM module shall send a NRC 0x31 (Request
					 * 		out of Range).
					 */
					result = DspInternal_CheckDidValid(\
								u16ReqSourceDid, DCM_PERMISSION_CHECK_USER_READ_DID, &u8DidIdx, &sesLevelRef, &secLevelRef, pErrorCode\
								);

					if((Std_ReturnType)E_OK == result)
					{
						u8ReqSourceDidPos = pMsgContext->ReqData[(u8SourceDidIndex * 4u) + 6u];
						u8ReqSourceDidMemSize = pMsgContext->ReqData[(u8SourceDidIndex * 4u) + 7u];

						/**
						 * @req [SWS_Dcm_00646] On reception of service DynamicallyDefineDataIdentifier with
						 * 		subservice defineByIdentifier or defineByMemoryAddress, the DCM module shall
						 * 		configure this new DID with associated information receive from the
						 * 		diagnostic request: Memory address and memory length or DID source, position
						 * 		and size.
						 */
						Dcm_DDDidStatus[pDDDidInfo->DcmDspDDDIDIndex].ElementStatus[u8ElementNum].IsDidType = (boolean)TRUE;
						Dcm_DDDidStatus[pDDDidInfo->DcmDspDDDIDIndex].ElementStatus[u8ElementNum].Element.SrcDid.SrcDidIndex = u8DidIdx;
						Dcm_DDDidStatus[pDDDidInfo->DcmDspDDDIDIndex].ElementStatus[u8ElementNum].Element.SrcDid.SrcDidDataPos = u8ReqSourceDidPos;
						Dcm_DDDidStatus[pDDDidInfo->DcmDspDDDIDIndex].ElementStatus[u8ElementNum].Element.SrcDid.SrcDidDataLen = u8ReqSourceDidMemSize;
						Dcm_DDDidStatus[pDDDidInfo->DcmDspDDDIDIndex].ElementStatus[u8ElementNum].Element.SrcDid.Identifier = u16ReqSourceDid;
						Dcm_DDDidStatus[pDDDidInfo->DcmDspDDDIDIndex].ElementStatus[u8ElementNum].SesLevelRef = sesLevelRef;
						Dcm_DDDidStatus[pDDDidInfo->DcmDspDDDIDIndex].ElementStatus[u8ElementNum].SecLevelRef = secLevelRef;
						u8ElementNum++;
					}
					else
					{
						if(DCM_E_SECURITYACCESSDENIED != *pErrorCode)
						{
							*pErrorCode = DCM_E_REQUESTOUTOFRANGE;
						}

						break;
					}
				}

				if(u8SourceDidIndex == u8ReqSourceDidNum)
				{
					Dcm_DDDidStatus[pDDDidInfo->DcmDspDDDIDIndex].DefinedState = (boolean)TRUE;
					Dcm_DDDidStatus[pDDDidInfo->DcmDspDDDIDIndex].ElementNum = u8ElementNum;

#if(STD_ON == DCM_DDDID_STORAGE)
					/**
					 * @req [SWS_Dcm_00868] If DcmDDDIDStorage configuration parameter is set to TRUE,
					 * 		the DCM shall trigger the storage of the DDDID definition to NvRam (via
					 * 		NvM_SetRamBlockStatus).
					 */
					(void)NvM_SetRamBlockStatus(DCM_DDDID_STORAGE_BLOCK_ID_REF, (boolean)TRUE);
#endif /* #if(STD_ON == DCM_DDDID_STORAGE) */
				}
			}
		}

#else

		*pErrorCode = DCM_E_REQUESTOUTOFRANGE;

#endif /* #if(0u != DCM_DSP_DDDID_NUM) */
	}

	return result;
}
#endif /* #if(STD_ON == DCM_UDS0x2C_SUB0x01_ENABLE) */

#if(STD_ON == DCM_UDS0x2C_SUB0x02_ENABLE)
/**
 * @brief			Dcm_UDS0x2CDefineByMemoryAddress
 * @details			Define DDDid by memory address process.
 *
 * @param[in]		pMsgContext:Message-related information for one diagnostic protocol identifier. The
 * 					pointers in pMsgContext shall point behind the SID.
 *
 * @param[out]		pErrorCode:If error occur, output the NRC.
 *
 * @return        	Result of this operation.
 * @retval			E_OK:Processing successful.
 * @retval			E_NOT_OK:Processing failure.
 */
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x2CDefineByMemoryAddress
(
	P2CONST(Dcm_MsgContextType, AUTOMATIC, DCM_CONST)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
)
{
	Std_ReturnType result = (Std_ReturnType)E_NOT_OK;

	uint8 u8ReqDDDidIdx;
	uint8 u8FormatId = pMsgContext->ReqData[4];
	uint8 u8ReqMemoryId;
	uint8 u8ReqMemoryNum;
	uint8 u8ReqMemoryIndex;
	uint8 u8ElementNum;
	uint32 u32Index;
	uint32 u32AddrLen;
	uint32 u32SizeLen;
	uint32 u32Addr;
	uint32 u32Size;
	uint32 u32Offset = 5u;
	Dcm_SessionDataType sesLevelRef;
	Dcm_SecurityDataType secLevelRef;
	const Dcm_DspDidInfoType* pDDDidInfo = NULL_PTR;
	const Dcm_DspMemoryType* pMemory = Dcm_ConfigPtr->DcmDsp->DcmDspMemory;

#if(0u != DCM_DSP_MEMORY_FORMAT_ID_NUM)
	/**
	 * @req [SWS_Dcm_00854] On reception of the UDS Service DynamicallyDefineDataIdentifier (0x2C) with
	 * 		subservice defineByMemoryAddress, the DCM shall check if the requested
	 * 		AddressAndLengthFormatIdentifier is supported (refer to configuration parameter
	 * 		DcmDspSupportedAddressAndLengthFormatIdentifier), Otherwise the NRC 0x31 (requestOutOfRange)
	 * 		shall be responded. In case the container AddressAndLengthFormatIdentifier is not present,
	 * 		the DCM shall accept all possible AddressAndLengthFormatIdentifiers.
	 */
	for(u32Index = 0u; u32Index < DCM_DSP_MEMORY_FORMAT_ID_NUM; u32Index++)
	{
		if(u8FormatId == pMemory->DcmDspSupportedAddressAndLengthFormatIdentifier[u32Index])
		{
			break;
		}
	}
	if(DCM_DSP_MEMORY_FORMAT_ID_NUM == u32Index)
	{
		*pErrorCode = DCM_E_REQUESTOUTOFRANGE;
	}
	else
	{
#endif /* #if(0u != DCM_DSP_MEMORY_FORMAT_ID_NUM) */
		u32AddrLen = ((uint32)u8FormatId & 0x0Fu);
		u32SizeLen = (((uint32)u8FormatId & 0xF0u) >> 4u);

		if(0u != ((pMsgContext->ReqDataLen - 5u) % (u32AddrLen + u32SizeLen)))
		{
			*pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
		}
		else
		{
#if(0u != DCM_DSP_DDDID_NUM)

			if((Std_ReturnType)E_OK == Dcm_UDS0x2CReqDDDidCheck(&u8ReqDDDidIdx, pMsgContext, pErrorCode))
			{
				u8ReqMemoryNum = (uint8)((pMsgContext->ReqDataLen - 5u) / (u32AddrLen + u32SizeLen));

				pDDDidInfo = Dcm_ConfigPtr->DcmDsp->DcmDspDid[u8ReqDDDidIdx].DcmDspDidInfoRef;

				u8ElementNum = Dcm_DDDidStatus[pDDDidInfo->DcmDspDDDIDIndex].ElementNum;

				/**
				 * @req [SWS_Dcm_00861] On reception of the UDS Service DynamicallyDefineDataIdentifier
				 * 		(0x2C), the DCM module shall check if the DDDID will not exceed the configured
				 * 		parameter value DcmDspDDDIDMaxElements. Otherwise (in case the number of
				 * 		elements will be exceeded) the DCM module shall send a NRC 0x31 (Request out of
				 * 		Range).
				 */
				if((0u == pDDDidInfo->DcmDspDDDIDMaxElements) ||\
					((u8ElementNum + u8ReqMemoryNum) > pDDDidInfo->DcmDspDDDIDMaxElements))
				{
					*pErrorCode = DCM_E_REQUESTOUTOFRANGE;
				}
				else
				{
					for(u8ReqMemoryIndex = 0u; u8ReqMemoryIndex < u8ReqMemoryNum; u8ReqMemoryIndex++)
					{
						u32Addr = 0u;
						u32Size = 0u;

						u8ReqMemoryId = pMsgContext->ReqData[u32Offset];

						for(u32Index = 0u; u32Index < u32AddrLen; u32Index++)
						{
							u32Addr <<= 8u;
							u32Addr |= ((uint32)pMsgContext->ReqData[u32Index + u32Offset]);
						}
						u32Offset += u32AddrLen;

						for(u32Index = 0u; u32Index < u32SizeLen; u32Index++)
						{
							u32Size <<= 8u;
							u32Size |= ((uint32)pMsgContext->ReqData[u32Index + u32Offset]);
						}
						u32Offset += u32SizeLen;

						/**
						 * @req [SWS_Dcm_00646] On reception of service DynamicallyDefineDataIdentifier
						 * 		with subservice defineByIdentifier or defineByMemoryAddress, the DCM
						 * 		module shall configure this new DID with associated information receive
						 * 		from the diagnostic request: Memory address and memory length or DID
						 * 		source, position and size.
						 *
						 * @req [SWS_Dcm_00726] On reception of the UDS Service
						 * 		DynamicallyDefineDataIdentifier (0x2C), the DCM module shall check if
						 * 		the requested Source-DID or the memoryRange are supported in the current
						 * 		security level (see configuration parameter of referenced DID
						 * 		DcmDspDidReadSecurityLevelRef or memoryRange
						 * 		DcmDspReadMemoryRangeSecurityLevelRef). If not, the DCM module shall
						 * 		send a NRC 0x33 (Security access denied).
						 *
						 * @req [SWS_Dcm_01051] On reception of the UDS Service
						 * 		DynamicallyDefineDataIdentifier (0x2C), if the request message contains
						 * 		different MemoryIdValue compare to the configured values in
						 * 		DcmDspMemoryIdInfo container, the Dcm shall send a NRC 0x31 (Request out
						 * 		of Range).
						 */
						if((Std_ReturnType)E_OK == DspInternal_MemoryAddrCheck(u32Addr, u32Size, (boolean)TRUE, &u8ReqMemoryId, &sesLevelRef, &secLevelRef, pErrorCode))
						{
							Dcm_DDDidStatus[pDDDidInfo->DcmDspDDDIDIndex].ElementStatus[u8ElementNum].Element.Memory.MemoryId = u8ReqMemoryId;
							Dcm_DDDidStatus[pDDDidInfo->DcmDspDDDIDIndex].ElementStatus[u8ElementNum].Element.Memory.MemorySize = u32Size;
							Dcm_DDDidStatus[pDDDidInfo->DcmDspDDDIDIndex].ElementStatus[u8ElementNum].Element.Memory.MemoryAddress = u32Addr;
							Dcm_DDDidStatus[pDDDidInfo->DcmDspDDDIDIndex].ElementStatus[u8ElementNum].SesLevelRef = sesLevelRef;
							Dcm_DDDidStatus[pDDDidInfo->DcmDspDDDIDIndex].ElementStatus[u8ElementNum].SecLevelRef = secLevelRef;
							Dcm_DDDidStatus[pDDDidInfo->DcmDspDDDIDIndex].ElementNum++;
						}
						else
						{
							break;
						}
					}

					if(u8ReqMemoryIndex == u8ReqMemoryNum)
					{
						Dcm_DDDidStatus[pDDDidInfo->DcmDspDDDIDIndex].DefinedState = (boolean)TRUE;

						result = (Std_ReturnType)E_OK;

#if(STD_ON == DCM_DDDID_STORAGE)
						/**
						 * @req [SWS_Dcm_00868] If DcmDDDIDStorage configuration parameter is set to
						 * 		TRUE, the DCM shall trigger the storage of the DDDID definition to NvRam
						 * 		(via NvM_SetRamBlockStatus).
						 */
						(void)NvM_SetRamBlockStatus(DCM_DDDID_STORAGE_BLOCK_ID_REF, (boolean)TRUE);
#endif /* #if(STD_ON == DCM_DDDID_STORAGE) */
					}
				}
			}
#else

			*pErrorCode = DCM_E_REQUESTOUTOFRANGE;

#endif /* #if(0u != DCM_DSP_DDDID_NUM) */
		}
#if(0u != DCM_DSP_MEMORY_FORMAT_ID_NUM)
	}
#endif /* #if(0u != DCM_DSP_MEMORY_FORMAT_ID_NUM) */

	return result;
}
#endif /* #if(STD_ON == DCM_UDS0x2C_SUB0x02_ENABLE) */

#if(STD_ON == DCM_UDS0x2C_SUB0x03_ENABLE)
/**
 * @brief			Dcm_UDS0x2CClearDynamicallyDefinedDid
 * @details			Clear the DDDid process.
 *
 * @param[in]		pMsgContext:Message-related information for one diagnostic protocol identifier. The
 * 					pointers in pMsgContext shall point behind the SID.
 *
 * @param[out]		pErrorCode:If error occur, output the NRC.
 *
 * @return        	Result of this operation.
 * @retval			E_OK:Processing successful.
 * @retval			E_NOT_OK:Processing failure.
 */
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x2CClearDynamicallyDefinedDid
(
	P2CONST(Dcm_MsgContextType, AUTOMATIC, DCM_CONST)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
)
{
	Std_ReturnType result = (Std_ReturnType)E_NOT_OK;

	uint8 u8ReqDDDidIdx;
	const Dcm_DspDidInfoType* pDDDidInfo = NULL_PTR;

	if(4u != pMsgContext->ReqDataLen)
	{
		*pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
	}
	else
	{
#if(0u != DCM_DSP_DDDID_NUM)

		if((Std_ReturnType)E_OK == Dcm_UDS0x2CReqDDDidCheck(&u8ReqDDDidIdx, pMsgContext, pErrorCode))
		{
			pDDDidInfo = Dcm_ConfigPtr->DcmDsp->DcmDspDid[u8ReqDDDidIdx].DcmDspDidInfoRef;

			/**
			 * @req [SWS_Dcm_00647] On reception of service DynamicallyDefineDataIdentifier with subservice
			 * 		clearDynamicallyDefinedDataIdentifier, the DCM module shall remove the configuration of
			 * 		this DID.
			 */
			if((boolean)TRUE == Dcm_DDDidStatus[pDDDidInfo->DcmDspDDDIDIndex].DefinedState)
			{
				DspInternal_DDDidStatusInit(pDDDidInfo->DcmDspDDDIDIndex);

				result = (Std_ReturnType)E_OK;

#if(STD_ON == DCM_DDDID_STORAGE)
				/**
				 * @req [SWS_Dcm_00868] If DcmDDDIDStorage configuration parameter is set to TRUE, the DCM
				 * 		shall trigger the storage of the DDDID definition to NvRam (via
				 * 		NvM_SetRamBlockStatus).
				 */
				(void)NvM_SetRamBlockStatus(DCM_DDDID_STORAGE_BLOCK_ID_REF, (boolean)TRUE);
#endif /* #if(STD_ON == DCM_DDDID_STORAGE) */
			}
			else
			{
				*pErrorCode = DCM_E_REQUESTOUTOFRANGE;
			}
		}

#else

		*pErrorCode = DCM_E_REQUESTOUTOFRANGE;

#endif /* #if(0u != DCM_DSP_DDDID_NUM) */
	}

	return result;
}
#endif /* #if(STD_ON == DCM_UDS0x2C_SUB0x03_ENABLE) */
/*====================================================================================================*
 *                                          GLOBAL FUNCTIONS
 *====================================================================================================*/
/**
 * @brief			Dcm_UDS0x2C
 * @details			Internal processing interface for Service 0x2C.
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
FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x2C
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

	if(4u > pMsgContext->ReqDataLen)
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
			switch(u8SubServiceId)
			{
#if(STD_ON == DCM_UDS0x2C_SUB0x01_ENABLE)
			case 0x01u:
				result = Dcm_UDS0x2CDefineByDid(pMsgContext, ErrorCode);
				break;
#endif /* #if(STD_ON == DCM_UDS0x2C_SUB0x01_ENABLE) */
#if(STD_ON == DCM_UDS0x2C_SUB0x02_ENABLE)
			case 0x02u:
				result = Dcm_UDS0x2CDefineByMemoryAddress(pMsgContext, ErrorCode);
				break;
#endif /* #if(STD_ON == DCM_UDS0x2C_SUB0x02_ENABLE) */
#if(STD_ON == DCM_UDS0x2C_SUB0x03_ENABLE)
			case 0x03u:
				result = Dcm_UDS0x2CClearDynamicallyDefinedDid(pMsgContext, ErrorCode);
				break;
#endif /* #if(STD_ON == DCM_UDS0x2C_SUB0x03_ENABLE) */
			default:
				/* Nothing to do here. */
				break;
			}

			if((Std_ReturnType)E_OK == result)
			{
				pMsgContext->ResData[0] = 0x6Cu;
				pMsgContext->ResData[1] = pMsgContext->ReqData[1];
				pMsgContext->ResData[2] = pMsgContext->ReqData[2];
				pMsgContext->ResData[3] = pMsgContext->ReqData[3];

				pMsgContext->ResDataLen = 4u;
			}
		}
	}

	return result;
}

#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#endif /* #if(STD_ON == DCM_UDS0x2C_INTERNAL_FNC_ENABLE) */
#endif /* #if(STD_ON == DCM_UDS0x2C_ENABLE) */

#ifdef __cplusplus
}
#endif
/** @} */
