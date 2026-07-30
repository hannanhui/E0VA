/**
 * @file        Dcm_UDS0x3D.c
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

/* PRQA S 0292, 0857, 0491, 3218, 2877, 5087 EOF #
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
 * 4.3218 -- Violates MISRA 2004 Required Rule 17.4, File scope static, 'Dcm_UDS0x3DStatus', is only
 * accessed in one function.
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

#if(STD_ON == DCM_UDS0x3D_ENABLE)
#if(STD_ON == DCM_UDS0x3D_INTERNAL_FNC_ENABLE)
/**
 * @req [SWS_Dcm_00488] The Dcm module shall implement the WriteMemoryByAddress (service 0x3D) of the
 * 		Unified Diagnostic Services.
 *
 * @req [SWS_Dcm_01056] The configured ranges of memory address (DcmDspWriteMemoryRangeHigh and
 * 		DcmDspWriteMemoryRangeLow) should not overlap each other.
 */
/*====================================================================================================*
 *                                  SOURCE FILE VERSION INFORMATION
 *====================================================================================================*/
#define DCM_UDS0X3D_VENDOR_ID_C                            	(0x00U)
#define DCM_UDS0X3D_AR_RELEASE_MAJOR_VERSION_C             	(0x04U)
#define DCM_UDS0X3D_AR_RELEASE_MINOR_VERSION_C             	(0x02U)
#define DCM_UDS0X3D_AR_RELEASE_REVISION_VERSION_C          	(0x02U)
#define DCM_UDS0X3D_SW_MAJOR_VERSION_C                     	(0x01U)
#define DCM_UDS0X3D_SW_MINOR_VERSION_C                     	(0x02U)
#define DCM_UDS0X3D_SW_PATCH_VERSION_C                     	(0x00U)
/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/
/* Check if current file and Dcm_Internal header file are of the same vendor */
#if(DCM_UDS0X3D_VENDOR_ID_C != DCM_INTERNAL_VENDOR_ID )
#error "Dcm_UDS0x3D.c and Dcm_Internal.h have different vendor id"
#endif
/* Check if current file and Dcm_Internal header file are of the same Autosar version */
#if(\
		(DCM_UDS0X3D_AR_RELEASE_MAJOR_VERSION_C != DCM_INTERNAL_AR_RELEASE_MAJOR_VERSION) || \
		(DCM_UDS0X3D_AR_RELEASE_MINOR_VERSION_C != DCM_INTERNAL_AR_RELEASE_MINOR_VERSION) || \
		(DCM_UDS0X3D_AR_RELEASE_REVISION_VERSION_C != DCM_INTERNAL_AR_RELEASE_REVISION_VERSION) \
)
#error "AutoSar Version Number of Dcm_UDS0x3D.c and Dcm_Internal.h are different"
#endif
/* Check if current file and Dcm_Internal header file are of the same software version */
#if(\
		(DCM_UDS0X3D_SW_MAJOR_VERSION_C != DCM_INTERNAL_SW_MAJOR_VERSION) || \
		(DCM_UDS0X3D_SW_MINOR_VERSION_C != DCM_INTERNAL_SW_MINOR_VERSION) || \
		(DCM_UDS0X3D_SW_PATCH_VERSION_C != DCM_INTERNAL_SW_PATCH_VERSION) \
)
#error "Software Version Number of Dcm_UDS0x3D.c and Dcm_Internal.h are different"
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
 * @brief	Store internal status of service 0x3D during its processing.
 */
STATIC VAR(Dcm_RwMemoryStatusType, DCM_VAR)Dcm_UDS0x3DStatus;

#define DCM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
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
 * @brief			Dcm_UDS0x3D
 * @details			Internal processing interface for Service 0x3D.
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
FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x3D
(
	Dcm_OpStatusType OpStatus,
	P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
)
{
	Std_ReturnType result = (Std_ReturnType)E_NOT_OK;

	uint8 u8Index;
	uint8 u8FormatId;
	uint8 u8AddrLen;
	uint8 u8SizeLen;
	uint8 u8ReqMemoryId;
	uint32 u32Addr = 0u;
	uint32 u32Size = 0u;
	Dcm_ReturnWriteMemoryType writeRet = (Dcm_ReturnWriteMemoryType)DCM_WRITE_FAILED;
#if(0u != DCM_DSP_MEMORY_FORMAT_ID_NUM)
	const Dcm_DspMemoryType* pMemory = Dcm_ConfigPtr->DcmDsp->DcmDspMemory;
#endif /* #if(0u != DCM_DSP_MEMORY_FORMAT_ID_NUM) */

	if((DCM_PENDING != OpStatus) && (DCM_FORCE_RCRRP_OK != OpStatus))
	{
		Dcm_UDS0x3DStatus.MemoryId = 0u;
		Dcm_UDS0x3DStatus.MemoryAddr = 0xFFFFFFFFu;
		Dcm_UDS0x3DStatus.MemorySize = 0u;
		Dcm_UDS0x3DStatus.DataOffset = 0u;

		if(5u > pMsgContext->ReqDataLen)
		{
			*ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
		}
		else
		{
			u8FormatId = pMsgContext->ReqData[1];

#if(0u != DCM_DSP_MEMORY_FORMAT_ID_NUM)
			/**
			 * @req [SWS_Dcm_00855] On reception of the UDS Service WriteMemoryByAddress (0x3D), the DCM
			 * 		shall check if the requested AddressAndLengthFormatIdentifier is supported (refer to
			 * 		configuration parameter DcmDspSupportedAddressAndLengthFormatIdentifier), Otherwise
			 * 		the NRC 0x31 (requestOutOfRange) shall be responded. In case the container
			 * 		AddressAndLengthFormatIdentifier is not present, the DCM shall accept all possible
			 * 		AddressAndLengthFormatIdentifiers.
			 */
			for(u8Index = 0u; u8Index < DCM_DSP_MEMORY_FORMAT_ID_NUM; u8Index++)
			{
				if(u8FormatId == pMemory->DcmDspSupportedAddressAndLengthFormatIdentifier[u8Index])
				{
					break;
				}
			}
			if(DCM_DSP_MEMORY_FORMAT_ID_NUM == u8Index)
			{
				*ErrorCode = DCM_E_REQUESTOUTOFRANGE;
			}
			else
#endif /* #if(0u != DCM_DSP_MEMORY_FORMAT_ID_NUM) */
			{
				u8AddrLen = (u8FormatId & 0x0Fu);
				u8SizeLen = ((u8FormatId & 0xF0u) >> 4u);

				for(u8Index = 0u; u8Index < u8SizeLen; u8Index++)
				{
					u32Size <<= 8u;
					u32Size |= ((uint32)pMsgContext->ReqData[u8Index + u8AddrLen + 2u]);
				}

				if(pMsgContext->ReqDataLen != ((uint32)u8AddrLen + (uint32)u8SizeLen + u32Size + 2u))
				{
					*ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
				}
				else
				{
					for(u8Index = 0u; u8Index < u8AddrLen; u8Index++)
					{
						u32Addr <<= 8u;
						u32Addr |= ((uint32)pMsgContext->ReqData[u8Index + 2u]);
					}

					u8ReqMemoryId = pMsgContext->ReqData[2];
#if(STD_ON == DCM_UDS0x2C_ENABLE)
					if((Std_ReturnType)E_OK ==\
						DspInternal_MemoryAddrCheck(\
						u32Addr, u32Size, (boolean)FALSE, &u8ReqMemoryId, NULL_PTR, NULL_PTR, ErrorCode\
						))
#else
					if((Std_ReturnType)E_OK ==\
						DspInternal_MemoryAddrCheck(\
						u32Addr, u32Size, (boolean)FALSE, &u8ReqMemoryId, ErrorCode\
						))
#endif /* #if(STD_ON == DCM_UDS0x2C_ENABLE) */
					{
						Dcm_UDS0x3DStatus.MemoryAddr = u32Addr;
						Dcm_UDS0x3DStatus.MemorySize = u32Size;
						Dcm_UDS0x3DStatus.MemoryId = u8ReqMemoryId;
						Dcm_UDS0x3DStatus.DataOffset = (u8AddrLen + u8SizeLen + 2u);

						writeRet = (Dcm_ReturnWriteMemoryType)DCM_WRITE_OK;
					}
				}
			}
		}
	}
	else
	{
		writeRet = (Dcm_ReturnWriteMemoryType)DCM_WRITE_OK;
	}

	if((Dcm_ReturnWriteMemoryType)DCM_WRITE_OK == writeRet)
	{
		/**
		 * @req [SWS_Dcm_00491] On reception of the UDS Service WriteMemoryByAddress (0x3D), and after
		 * 		verification of the validity of the request (see [SWS_Dcm_00489 and [SWS_Dcm_00490) the
		 * 		DCM module shall call the callout Dcm_WriteMemory().
		 */
		writeRet = Dcm_WriteMemory(\
					OpStatus, Dcm_UDS0x3DStatus.MemoryId, Dcm_UDS0x3DStatus.MemoryAddr,\
					Dcm_UDS0x3DStatus.MemorySize,\
					&pMsgContext->ReqData[Dcm_UDS0x3DStatus.DataOffset], ErrorCode\
					);

		if((Dcm_ReturnWriteMemoryType)DCM_WRITE_OK == writeRet)
		{
			if(pMsgContext->ResMaxDataLen < (uint32)Dcm_UDS0x3DStatus.DataOffset)
			{
				*ErrorCode = DCM_E_RESPONSETOOLONG;
			}
			else
			{
				pMsgContext->ResData[0] = 0x7Du;
				pMsgContext->ResData[1] = pMsgContext->ReqData[1];

				for(u8Index = 0u; u8Index < (Dcm_UDS0x3DStatus.DataOffset - 2u); u8Index++)
				{
					pMsgContext->ResData[u8Index + 2u] = pMsgContext->ReqData[u8Index + 2u];
				}

				pMsgContext->ResDataLen = (uint32)Dcm_UDS0x3DStatus.DataOffset;

				result = (Std_ReturnType)E_OK;
			}
		}
		else if((Dcm_ReturnWriteMemoryType)DCM_WRITE_PENDING == writeRet)
		{
			Dcm_OpState = DCM_PENDING;
			*ErrorCode = DCM_E_RESPONSE_PENDING;
		}
		else if((Dcm_ReturnWriteMemoryType)DCM_WRITE_FORCE_RCRRP == writeRet)
		{
			Dcm_OpState = DCM_FORCE_RCRRP_OK;
			*ErrorCode = DCM_E_RESPONSE_PENDING;
		}
		else
		{
			/* Nothing to do here. */
			;
		}
	}

	return result;
}

#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#endif /* #if(STD_ON == DCM_UDS0x3D_INTERNAL_FNC_ENABLE) */
#endif /* #if(STD_ON == DCM_UDS0x3D_ENABLE) */

#ifdef __cplusplus
}
#endif
/** @} */
