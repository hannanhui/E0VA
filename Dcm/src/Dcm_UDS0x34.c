/**
 * @file        Dcm_UDS0x34.c
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

#if(STD_ON == DCM_UDS0x34_ENABLE)
#if(STD_ON == DCM_UDS0x34_INTERNAL_FNC_ENABLE)
/**
 * @req [SWS_Dcm_00496] The Dcm module shall implement the RequestDownload (service 0x34) of the
 * 		Unified Diagnostic Services.
 */
/*====================================================================================================*
 *                                  SOURCE FILE VERSION INFORMATION
 *====================================================================================================*/
#define DCM_UDS0X34_VENDOR_ID_C                            	(0x00U)
#define DCM_UDS0X34_AR_RELEASE_MAJOR_VERSION_C             	(0x04U)
#define DCM_UDS0X34_AR_RELEASE_MINOR_VERSION_C             	(0x02U)
#define DCM_UDS0X34_AR_RELEASE_REVISION_VERSION_C          	(0x02U)
#define DCM_UDS0X34_SW_MAJOR_VERSION_C                     	(0x01U)
#define DCM_UDS0X34_SW_MINOR_VERSION_C                     	(0x02U)
#define DCM_UDS0X34_SW_PATCH_VERSION_C                     	(0x00U)
/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/
/* Check if current file and Dcm_Internal header file are of the same vendor */
#if(DCM_UDS0X34_VENDOR_ID_C != DCM_INTERNAL_VENDOR_ID )
#error "Dcm_UDS0x34.c and Dcm_Internal.h have different vendor id"
#endif
/* Check if current file and Dcm_Internal header file are of the same Autosar version */
#if(\
		(DCM_UDS0X34_AR_RELEASE_MAJOR_VERSION_C != DCM_INTERNAL_AR_RELEASE_MAJOR_VERSION) || \
		(DCM_UDS0X34_AR_RELEASE_MINOR_VERSION_C != DCM_INTERNAL_AR_RELEASE_MINOR_VERSION) || \
		(DCM_UDS0X34_AR_RELEASE_REVISION_VERSION_C != DCM_INTERNAL_AR_RELEASE_REVISION_VERSION) \
)
#error "AutoSar Version Number of Dcm_UDS0x34.c and Dcm_Internal.h are different"
#endif
/* Check if current file and Dcm_Internal header file are of the same software version */
#if(\
		(DCM_UDS0X34_SW_MAJOR_VERSION_C != DCM_INTERNAL_SW_MAJOR_VERSION) || \
		(DCM_UDS0X34_SW_MINOR_VERSION_C != DCM_INTERNAL_SW_MINOR_VERSION) || \
		(DCM_UDS0X34_SW_PATCH_VERSION_C != DCM_INTERNAL_SW_PATCH_VERSION) \
)
#error "Software Version Number of Dcm_UDS0x34.c and Dcm_Internal.h are different"
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
 * @brief			Dcm_UDS0x34
 * @details			Internal processing interface for Service 0x34.
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
FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x34
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
	uint32 u32BlockLength;
#if(0u != DCM_DSP_MEMORY_FORMAT_ID_NUM)
	const Dcm_DspMemoryType* pMemory = NULL_PTR;
#endif /* #if(0u != DCM_DSP_MEMORY_FORMAT_ID_NUM) */
	const Dcm_DslProtocolRowType* pProtocolRow = &Dcm_ConfigPtr->DcmDsl->DcmDslProtocolRow[Dcm_ActiveProRowIdx];

	if(DCM_PENDING != OpStatus)
	{
		if(5u > pMsgContext->ReqDataLen)
		{
			*ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
		}
		else
		{
			u8FormatId = pMsgContext->ReqData[2];

#if(0u != DCM_DSP_MEMORY_FORMAT_ID_NUM)
			pMemory = Dcm_ConfigPtr->DcmDsp->DcmDspMemory;

			/**
			 * @req [SWS_Dcm_00856] On reception of the UDS ServiceRequestDownload (0x34), the DCM shall
			 * 		check if the requested AddressAndLengthFormatIdentifier is supported (refer to
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
			{
#endif /* #if(0u != DCM_DSP_MEMORY_FORMAT_ID_NUM) */

				u8AddrLen = (u8FormatId & 0x0Fu);
				u8SizeLen = ((u8FormatId & 0xF0u) >> 4u);

				if((uint8)pMsgContext->ReqDataLen != (u8AddrLen + u8SizeLen + 3u))
				{
					*ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
				}
				else
				{
					for(u8Index = 0u; u8Index < u8AddrLen; u8Index++)
					{
						u32Addr <<= 8u;
						u32Addr |= ((uint32)pMsgContext->ReqData[u8Index + 3u]);
					}

					for(u8Index = 0u; u8Index < u8SizeLen; u8Index++)
					{
						u32Size <<= 8u;
						u32Size |= ((uint32)pMsgContext->ReqData[u8Index + u8AddrLen + 3u]);
					}

					u8ReqMemoryId = pMsgContext->ReqData[3];

					/**
					 * @req [SWS_Dcm_01057] On reception of the UDS ServiceRequestDownload (0x34), if
					 * 		the request message contains different MemoryIdValue compare to the
					 * 		configured values in DcmDspMemoryIdInfo container, the Dcm shall send a NRC
					 * 		0x31 (Request out of Range).
					 */
#if(STD_ON == DCM_UDS0x2C_ENABLE)
					result = DspInternal_MemoryAddrCheck(\
								u32Addr, u32Size, (boolean)FALSE,\
								&u8ReqMemoryId, NULL_PTR, NULL_PTR, ErrorCode\
								);
#else
					result = DspInternal_MemoryAddrCheck(\
								u32Addr, u32Size, (boolean)FALSE, &u8ReqMemoryId, ErrorCode\
								);
#endif /* #if(STD_ON == DCM_UDS0x2C_ENABLE) */

					if((Std_ReturnType)E_OK == result)
					{
						Dcm_TransferStatus.MemoryAddr = u32Addr;
						Dcm_TransferStatus.MemorySize = u32Size;
						Dcm_TransferStatus.MemoryId = u8ReqMemoryId;
						Dcm_TransferStatus.BlockLength = (pProtocolRow->DcmDslProtocolRxBufferRef->DcmDslBufferSize - 2u);
						
					}
				}
#if(0u != DCM_DSP_MEMORY_FORMAT_ID_NUM)
			}
#endif /* #if(0u != DCM_DSP_MEMORY_FORMAT_ID_NUM) */
		}
	}
	else
	{
		result = (Std_ReturnType)E_OK;
	}

	if((Std_ReturnType)E_OK == result)
	{
		result = Dcm_ProcessRequestDownload(OpStatus,\
					pMsgContext->ReqData[1], Dcm_TransferStatus.MemoryId,\
					Dcm_TransferStatus.MemoryAddr, Dcm_TransferStatus.MemorySize,\
					&Dcm_TransferStatus.BlockLength, ErrorCode\
					);

		if((Std_ReturnType)E_OK == result)
		{
			u32BlockLength = (Dcm_TransferStatus.BlockLength + 2u);

			if(pProtocolRow->DcmDslProtocolRxBufferRef->DcmDslBufferSize < u32BlockLength)
			{
				DCM_DET_ERROR_REPORT(DCM_SID_TPRXINDICATION, DCM_E_INTERFACE_BUFFER_OVERFLOW);

				result = (Std_ReturnType)E_NOT_OK;
			}
			else
			{
				if(u32BlockLength <= 0x000000FFu)
				{
					u8FormatId = 1u;
				}
				else if(u32BlockLength <= 0x0000FFFFu)
				{
					u8FormatId = 2u;
				}
				else if(u32BlockLength <= 0x00FFFFFFu)
				{
					u8FormatId = 3u;
				}
				else
				{
					u8FormatId = 4u;
				}

				/* The minimum length of the buffer is 8 bytes, no need to check the response length. */

				Dcm_TransferStatus.BlockSeqCnt = 1u;
				Dcm_TransferStatus.Process = DCM_TRANSFER_DOWNLOAD;
				Dcm_TransferStatus.IsFirstBlock = (boolean)TRUE;

				if(Dcm_TransferStatus.MemorySize < Dcm_TransferStatus.BlockLength)
				{
					Dcm_TransferStatus.IsLastBlock = (boolean)TRUE;
				}

				pMsgContext->ResData[0] = 0x74u;
				pMsgContext->ResData[1] = (u8FormatId << 4u);

				pMsgContext->ResDataLen = ((uint32)u8FormatId + 2u);

				u8Index = 2u;
				while(0u < u8FormatId)
				{
					u8FormatId--;
					pMsgContext->ResData[u8Index] = (uint8)(u32BlockLength >> (u8FormatId * 8u));
					u8Index++;
				}
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

#endif /* #if(STD_ON == DCM_UDS0x34_INTERNAL_FNC_ENABLE) */
#endif /* #if(STD_ON == DCM_UDS0x34_ENABLE) */

#ifdef __cplusplus
}
#endif
/** @} */
