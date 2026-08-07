/**
 * @file        Dcm_UserCallOut.c
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

/*====================================================================================================*
 *                                           INCLUDE FILES                                          
 *====================================================================================================*/
#include "Dcm_UserCallOut.h"
#include "Dcm_Externals.h"
#include <time.h>
#include <stdlib.h>
#include "Dcm_Internal.h"
#include "ee_config.h"
#include "eep_emulation.h"
#include "trng.h"
#include "aes128.h"
/*====================================================================================================*
 *                                  SOURCE FILE VERSION INFORMATION
 *====================================================================================================*/
#define DCM_USERCALLOUT_VENDOR_ID_C                         (0x00U)
#define DCM_USERCALLOUT_AR_RELEASE_MAJOR_VERSION_C          (0x04U)
#define DCM_USERCALLOUT_AR_RELEASE_MINOR_VERSION_C          (0x02U)
#define DCM_USERCALLOUT_AR_RELEASE_REVISION_VERSION_C       (0x02U)
#define DCM_USERCALLOUT_SW_MAJOR_VERSION_C                  (0x01U)
#define DCM_USERCALLOUT_SW_MINOR_VERSION_C                  (0x02U)
#define DCM_USERCALLOUT_SW_PATCH_VERSION_C                  (0x00U)
/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/
/* Check if current file and Dcm_UserCallOut header file are of the same vendor */
#if(DCM_USERCALLOUT_VENDOR_ID_C != DCM_USERCALLOUT_VENDOR_ID )
#error "Dcm_UserCallOut.c and Dcm_UserCallOut.h have different vendor id"
#endif
/* Check if current file and Dcm_UserCallOut header file are of the same Autosar version */
#if(\
		(DCM_USERCALLOUT_AR_RELEASE_MAJOR_VERSION_C != DCM_USERCALLOUT_AR_RELEASE_MAJOR_VERSION) || \
		(DCM_USERCALLOUT_AR_RELEASE_MINOR_VERSION_C != DCM_USERCALLOUT_AR_RELEASE_MINOR_VERSION) || \
		(DCM_USERCALLOUT_AR_RELEASE_REVISION_VERSION_C != DCM_USERCALLOUT_AR_RELEASE_REVISION_VERSION) \
)
#error "AutoSar Version Number of Dcm_UserCallOut.c and Dcm_UserCallOut.h are different"
#endif
/* Check if current file and Dcm_UserCallOut header file are of the same software version */
#if(\
		(DCM_USERCALLOUT_SW_MAJOR_VERSION_C != DCM_USERCALLOUT_SW_MAJOR_VERSION) || \
		(DCM_USERCALLOUT_SW_MINOR_VERSION_C != DCM_USERCALLOUT_SW_MINOR_VERSION) || \
		(DCM_USERCALLOUT_SW_PATCH_VERSION_C != DCM_USERCALLOUT_SW_PATCH_VERSION) \
)
#error "Software Version Number of Dcm_UserCallOut.c and Dcm_UserCallOut.h are different"
#endif
/* Check if current file and Dcm_Externals header file are of the same vendor */
#if(DCM_USERCALLOUT_VENDOR_ID_C != DCM_EXTERNALS_VENDOR_ID )
#error "Dcm_UserCallOut.c and Dcm_Externals.h have different vendor id"
#endif
/* Check if current file and Dcm_Externals header file are of the same Autosar version */
#if(\
		(DCM_USERCALLOUT_AR_RELEASE_MAJOR_VERSION_C != DCM_EXTERNALS_AR_RELEASE_MAJOR_VERSION) || \
		(DCM_USERCALLOUT_AR_RELEASE_MINOR_VERSION_C != DCM_EXTERNALS_AR_RELEASE_MINOR_VERSION) || \
		(DCM_USERCALLOUT_AR_RELEASE_REVISION_VERSION_C != DCM_EXTERNALS_AR_RELEASE_REVISION_VERSION) \
)
#error "AutoSar Version Number of Dcm_UserCallOut.c and Dcm_Externals.h are different"
#endif
/* Check if current file and Dcm_Externals header file are of the same software version */
#if(\
		(DCM_USERCALLOUT_SW_MAJOR_VERSION_C != DCM_EXTERNALS_SW_MAJOR_VERSION) || \
		(DCM_USERCALLOUT_SW_MINOR_VERSION_C != DCM_EXTERNALS_SW_MINOR_VERSION) || \
		(DCM_USERCALLOUT_SW_PATCH_VERSION_C != DCM_EXTERNALS_SW_PATCH_VERSION) \
)
#error "Software Version Number of Dcm_UserCallOut.c and Dcm_Externals.h are different"
#endif
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
 *                                           LOCAL VARIABLES
 *====================================================================================================*/
#define DCM_START_SEC_VAR_NO_INIT_8
#include "Dcm_MemMap.h"

/**
 * @brief 	Store the random seed generated through the DcmDspSecurityGetSeedFnc.
 */
STATIC VAR(uint8, DCM_VAR)Dcm_RandSeed[16] = {0u};

/**
 * @brief 	Store the key calculated from the generated random seed.
 */
STATIC VAR(uint8, DCM_VAR)Dcm_LocalKey[16] = {0u};

#define DCM_STOP_SEC_VAR_NO_INIT_8
#include "Dcm_MemMap.h"

/**
 * @brief 	Internal buffer of the "DcmDspData_0xF180".
 */
extern VAR(uint8, DCM_VAR)Dcm_DspDataInternalBuffer_DcmDspData_0xF180[32];

/**
 * @brief 	Internal buffer of the "DcmDspData_0xF187".
 */
extern VAR(uint8, DCM_VAR)Dcm_DspDataInternalBuffer_DcmDspData_0xF187[16];

/**
 * @brief 	Internal buffer of the "DcmDspData_0xF189".
 */
extern VAR(uint8, DCM_VAR)Dcm_DspDataInternalBuffer_DcmDspData_0xF189[24];

/**
 * @brief 	Internal buffer of the "DcmDspData_0xF089".
 */
extern VAR(uint8, DCM_VAR)Dcm_DspDataInternalBuffer_DcmDspData_0xF089[24];

/**
 * @brief 	Internal buffer of the "DcmDspData_0xF013".
 */
extern VAR(uint8, DCM_VAR)Dcm_DspDataInternalBuffer_DcmDspData_0xF013[16];

/**
 * @brief 	Internal buffer of the "DcmDspData_0xF18A".
 */
extern VAR(uint8, DCM_VAR)Dcm_DspDataInternalBuffer_DcmDspData_0xF18A[10];

/**
 * @brief 	Internal buffer of the "DcmDspData_0xF18C".
 */
extern VAR(uint8, DCM_VAR)Dcm_DspDataInternalBuffer_DcmDspData_0xF18C[47];

/**
 * @brief 	Internal buffer of the "DcmDspData_0xF186".
 */
extern VAR(uint8, DCM_VAR)Dcm_DspDataInternalBuffer_DcmDspData_0xF186[1];

/**
 * @brief 	Internal buffer of the "DcmDspData_0xF184".
 */
extern VAR(uint8, DCM_VAR)Dcm_DspDataInternalBuffer_DcmDspData_0xF184[18];

/**
 * @brief 	Internal buffer of the "DcmDspData_0xF0F1".
 */
extern VAR(uint8, DCM_VAR)Dcm_DspDataInternalBuffer_DcmDspData_0xF0F1[18];

/**
 * @brief 	Internal buffer of the "DcmDspData_0xF0F3".
 */
extern VAR(uint8, DCM_VAR)Dcm_DspDataInternalBuffer_DcmDspData_0xF0F3[18];

/**
 * @brief 	Internal buffer of the "DcmDspData_0xF160".
 */
extern VAR(uint8, DCM_VAR)Dcm_DspDataInternalBuffer_DcmDspData_0xF160[18];

uint8 EcuNUmber[20] = {
		'1', '0', '_', '1', '1','_','1', '1','_','4','_','1', '2','_','2', '6','0', '7','1', '8'
};

uint8 PartNumber[16] = {
		'4', '0', '2', '0', '8', '2', '0', '1', '4', 'A', 'A', 0x20u, 0x20u, 0x20u, 0x20u, 0x20u
};

uint8 VendorCode[10] = {
		'8', 'K', 'C', 0x20, 0x20u, 0x20u, 0x20u, 0x20u, 0x20u, 0x20u
};

uint8 HardVersionNumber[24] = {
		'0', '.', '0', '.', '1', 0x20u, 0x20u, 0x20u, 0x20u, 0x20u, 0x20u, 0x20u,
        0x20u, 0x20u, 0x20u, 0x20u, 0x20u, 0x20u, 0x20u, 0x20u, 0x20u, 0x20u, 0x20u, 0x20u
};

uint8 BootVersionNumber[32] = {
		'0', '1', '.', '0', '0', '.', '0', '0', 0x20u, 0x20u, 0x20u, 0x20u, 0x20u, 0x20u, 0x20u, 0x20u,
    0x20u, 0x20u, 0x20u, 0x20u, 0x20u, 0x20u, 0x20u, 0x20u, 0x20u, 0x20u, 0x20u, 0x20u, 0x20u, 0x20u, 0x20u, 0x20u
};

uint8 AppVersionNumber[24] = {
		'0', '1', '.', '0', '0', '.', '0', '0', 0x20u, 0x20u, 0x20u, 0x20u, 0x20u, 0x20u, 0x20u
        , 0x20u, 0x20u, 0x20u, 0x20u, 0x20u, 0x20u, 0x20u, 0x20u, 0x20u
};

/*for debugging*/
uint8 SoftwarePartNumber[16] = {
		'S', '0', '0', '0', '0', '0', '6', '4', '5', '4', '7', 0x20u, 0x20u, 0x20u, 0x20u, 0x20u
};
/*====================================================================================================*
 *                                          GLOBAL FUNCTIONS                                        
 *====================================================================================================*/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"

static uint8 LocalSeed[16] = {0};


static uint8 SecurityConstant[16] = {
    0xDEU, 0x99U, 0x36U, 0x5EU, 0x27U, 0x31U, 0x26U, 0x66U, 0xC7U, 0x3CU, 0xABU, 0xF3U, 0x36U, 0x71U, 0x44U, 0xB7U
};

STATIC FUNC(void,DCM_CODE)Dcm_MemoryCopy
(
    P2VAR(void, AUTOMATIC, DCM_APPL_DATA) Source,	/* PRQA S 3673 #violate MISAR2004_16.7:Suggest note*/
    P2VAR(void, AUTOMATIC, DCM_APPL_DATA) Dest,
    uint32 Length
)
{
    uint8 * pDest = (uint8 *)Dest;
    uint8 * pSrc = (uint8 *)Source;
    while (Length > (uint32)0)
    {
        *(pDest) = *(pSrc);
        pDest++;
        pSrc++;
        Length--;
    }
    return;
}




#if((STD_ON == DCM_UDS0x23_ENABLE) || (STD_ON == DCM_UDS0x2C_ENABLE) || (STD_ON == DCM_UDS0x36_ENABLE))
/**
 * @sid				0x26
 * @brief			Dcm_ReadMemory
 * @details			The Dcm_ReadMemory callout is used to request memory data identified by the
 * 					parameter memoryAddress and memorySize from the UDS request message. This service is
 * 					needed for the implementation of UDS services: ReadMemoryByAddress, RequestUpload,
 * 					ReadDataByIdentifier (in case of Dynamical DID defined by memory address),
 * 					TransferData.
 *
 * @param[in]		OpStatus:DCM_INITIAL, DCM_PENDING, DCM_CANCEL, DCM_FORCE_RCRRP_OK.
 * @param[in]		MemoryIdentifier:Identifier of the Memory Block (e.g. used if memory section
 * 					distinguishing is needed). Note: If it's not used this parameter shall be set to 0.
 * @param[in]		MemoryAddress:Starting address of server memory from which data is to be retrieved.
 * @param[in]		MemorySize:Number of bytes in the MemoryData.
 *
 * @param[out]		MemoryData:Data read (Points to the diagnostic buffer in DCM).
 * @param[out]		ErrorCode:If the operation Dcm_ReadMemory returns value DCM_READ_FAILED, the Dcm
 * 					module shall send a negative response with NRC code equal to the parameter ErrorCode
 * 					parameter value.
 *
 * @return     		Result of this operation.
 * @retval			DCM_READ_OK:Read was successful.
 * @retval			DCM_READ_FAILED:Read was not successful.
 * @retval			DCM_READ_PENDING:Read is not yet finished.
 * @retval			DCM_READ_FORCE_RCRRP:Reading is pending, the Response pending transmission starts
 * 					immediately.
 *
 * @req [SWS_Dcm_00539]
 */
FUNC(Dcm_ReturnReadMemoryType, DCM_CODE)Dcm_ReadMemory
(
	Dcm_OpStatusType OpStatus,
	uint8 MemoryIdentifier,
	uint32 MemoryAddress,
	uint32 MemorySize,
	P2VAR(uint8, AUTOMATIC, DCM_VAR)MemoryData,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
)
{
	Dcm_ReturnReadMemoryType result = DCM_READ_FAILED;

	return result;
}
#endif /* #if((STD_ON == DCM_UDS0x23_ENABLE) ||
	      	  (STD_ON == DCM_UDS0x2C_ENABLE) ||
	          (STD_ON == DCM_UDS0x36_ENABLE)) */

#if((STD_ON == DCM_UDS0x3D_ENABLE) || (STD_ON == DCM_UDS0x36_ENABLE))
/**
 * @sid				0x27
 * @brief			Dcm_WriteMemory
 * @details			The Dcm_WriteMemory callout is used to write memory data identified by the
 * 					parameter memoryAddress and memorySize. This service is needed for the
 * 					implementation of UDS services: WriteMemoryByAddress, RequestDownload, TransferData.
 *
 * @param[in]		OpStatus:DCM_INITIAL, DCM_PENDING, DCM_CANCEL, DCM_FORCE_RCRRP_OK.
 * @param[in]		MemoryIdentifier:Identifier of the Memory Block (e.g. used by WriteDataByIdentifier
 * 					service). Note: If it's not used this parameter shall be set to 0.
 * @param[in]		MemoryAddress:Starting address of server memory in which data is to be copied. Note:
 * 					If it's not used (e.g. if the data is compressed) this parameter shall be set to 0.
 * @param[in]		MemorySize:Number of bytes in the MemoryData.
 * @param[in]		MemoryData:Data write (Points to the diagnostic buffer in DCM).
 *
 * @param[out]		ErrorCode:If the operation Dcm_WriteMemory returns value DCM_WRITE_FAILED, the Dcm
 * 					module shall send a negative response with NRC code equal to the parameter ErrorCode
 * 					parameter value.
 *
 * @return     		Result of this operation.
 * @retval			DCM_WRITE_OK:Write was successful.
 * @retval			DCM_WRITE_FAILED:Write was not successful.
 * @retval			DCM_WRITE_PENDING:Write is not yet finished.
 * @retval			DCM_WRITE_FORCE_RCRRP:Write is pending, the Response pending transmission starts
 * 					immediately.
 *
 * @req [SWS_Dcm_00540]
 */
FUNC(Dcm_ReturnWriteMemoryType, DCM_CODE)Dcm_WriteMemory
(
	Dcm_OpStatusType OpStatus,
	uint8 MemoryIdentifier,
	uint32 MemoryAddress,
	uint32 MemorySize,
	P2CONST(uint8, AUTOMATIC, DCM_CONST)MemoryData,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
)
{
	Dcm_ReturnWriteMemoryType result = DCM_WRITE_FAILED;

	return result;
}
#endif /* #if((STD_ON == DCM_UDS0x3D_ENABLE) || (STD_ON == DCM_UDS0x36_ENABLE)) */

/**
 * @sid				-
 * @brief			Dcm_SetProgConditions
 * @details			The Dcm_SetProgConditions callout allows the integrator to store relevant
 * 					information prior to jumping to bootloader / jump due to ECUReset request. The
 * 					context parameter are defined in Dcm_ProgConditionsType.
 *
 * @param[in]		OpStatus:DCM_INITIAL, DCM_PENDING, DCM_CANCEL, DCM_FORCE_RCRRP_OK.
 * @param[in]		ProgConditions:Conditions on which the jump to bootloader has been requested.
 *
 * @return     		Result of this operation.
 * @retval			E_OK:Conditions have correctly been set.
 * @retval			E_NOT_OK:Conditions cannot be set.
 * @retval			DCM_E_PENDING:Conditions set is in progress, a further call to this API is needed
 * 					to end the setting.
 * @retval			DCM_E_FORCE_RCRRP:Application requests the transmission of a response Response
 * 					Pending (NRC 0x78).
 *
 * @req [SWS_Dcm_00543]
 */
FUNC(Std_ReturnType, DCM_CODE)Dcm_SetProgConditions
(
	Dcm_OpStatusType OpStatus,
	P2CONST(Dcm_ProgConditionsType, AUTOMATIC, DCM_CONST)ProgConditions
)
{
	Std_ReturnType result = (Std_ReturnType)E_OK;

	/* Just saves the ProgConditions to memory. */

	return result;
}

/**
 * @sid				-
 * @brief			Dcm_GetProgConditions
 * @details			The Dcm_GetProgConditions callout is called upon Dcm initialization and allows to
 * 					determine if a response ($50 or $51) has to be sent. The context parameters are
 * 					defined in Dcm_ProgConditionsType.
 *
 * @param[out]		ProgConditions:Conditions on which the jump to bootloader has been requested.
 *
 * @return     		Result of this operation.
 * @retval			DCM_COLD_START:The ECU starts normally.
 * @retval			DCM_WARM_START:The ECU starts from a bootloader jump.
 *
 * @req [SWS_Dcm_00544]
 */
FUNC(Dcm_EcuStartModeType, DCM_CODE)Dcm_GetProgConditions
(
	P2VAR(Dcm_ProgConditionsType, AUTOMATIC, DCM_VAR)ProgConditions
)
{
	Dcm_EcuStartModeType result = DCM_COLD_START;

#if(0u)
	/* TODO:2025.12.10 LY:Do this. */
	if((boolean)TRUE == Memory_ProgConditions.ReprogramingRequest)
	{
		result = DCM_WARM_START;
	}

	*ProgConditions = Memory_ProgConditions;

	Clear(Memory_ProgConditions);
#endif /* #if(0u) */

	*(&ProgConditions->ResponseRequired) = (boolean)FALSE;

	return result;
}

#if(STD_ON == DCM_UDS0x37_ENABLE)
/**
 * @sid				0x32
 * @brief			Dcm_ProcessRequestTransferExit
 * @details			Callout function. DCM shall call this callout function to terminate a download or
 * 					upload process.
 *
 * @param[in]		OpStatus:DCM_INITIAL, DCM_PENDING and DCM_CANCEL.
 * @param[in]		TransferRequestParameterRecord:Pointer to vehicle manufacturer specific data.
 * @param[in]		TransferRequestParameterRecordSize:Length of ParameterRecord in bytes.
 *
 * @param[in/out]	TransferResponseParameterRecordSize:Length of ParameterRecord in bytes.
 *
 * @param[out]		TransferResponseParameterRecord:Pointer to vehicle manufacturer specific data.
 * @param[out]		ErrorCode:See below.
 *
 * @return     		Result of this operation.
 * @retval			E_OK:Transfer was successful
 * @retval			E_NOT_OK:Transfer was not successful or the response buffer is too small.
 * @retval			DCM_E_PENDING:Transfer is not yet finished.

 *
 * @req [SWS_Dcm_00755]
 */
FUNC(Std_ReturnType, DCM_CODE)Dcm_ProcessRequestTransferExit
(
	Dcm_OpStatusType OpStatus,
	P2VAR(uint8, AUTOMATIC, DCM_VAR)TransferRequestParameterRecord,
	uint32 TransferRequestParameterRecordSize,
	P2VAR(uint8, AUTOMATIC, DCM_VAR)TransferResponseParameterRecord,
	P2VAR(uint32, AUTOMATIC, DCM_VAR)TransferResponseParameterRecordSize,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
)
{
	Std_ReturnType result = (Std_ReturnType)E_NOT_OK;

	return result;
}
#endif /* #if(STD_ON == DCM_UDS0x37_ENABLE) */

#if(STD_ON == DCM_UDS0x35_ENABLE)
/**
 * @sid				0x31
 * @brief			Dcm_ProcessRequestUpload
 * @details			Callout function. DCM shall call this callout function to start a download process.
 * 					This service is needed for the implementation of UDS service RequestDownload.
 *
 * @param[in]		OpStatus:DCM_INITIAL, DCM_PENDING and DCM_CANCEL.
 * @param[in]		DataFormatIdentifier:Bit 7 - 4: Compression Method, 0x0: not compressed, 0x1..F:
 * 					vehicle-manufacturer-specific, Bit 3 - 0: Encrypting method, 0x0: not encrypted,
 * 					0x1..F: vehicle-manufacturer-specific.
 * @param[in]		MemoryIdentifier:Identifier of the Memory Block, if the parameter is not used it
 * 					shall be set to 0.
 * @param[in]		MemoryAddress:Starting address of server memory to which data is to be written.
 * @param[in]		MemorySize:Uncompressed memory size in bytes.
 *
 * @param[in/out]	BlockLength:Max number of bytes for one Dcm_ReadMemory.
 *
 * @param[out]		ErrorCode:If the operation Dcm_ProcessRequestDownload returns value E_NOT_OK, the
 * 					DCM module shall send a negative response with NRC code equal to the parameter
 * 					ErrorCode parameter value.
 *
 * @return     		Result of this operation.
 * @retval			E_OK:Request was successful.
 * @retval			E_NOT_OK:Request was not successful.
 * @retval			DCM_E_PENDING:Request is not yet finished.
 *
 * @req [SWS_Dcm_00756]
 */
FUNC(Std_ReturnType, DCM_CODE)Dcm_ProcessRequestUpload
(
	Dcm_OpStatusType OpStatus,
	uint8 DataFormatIdentifier,
	uint8 MemoryIdentifier,
	uint32 MemoryAddress,
	uint32 MemorySize,
	P2VAR(uint32, AUTOMATIC, DCM_VAR)BlockLength,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
)
{
	Std_ReturnType result = (Std_ReturnType)E_NOT_OK;

	return result;
}
#endif /* #if(STD_ON == DCM_UDS0x35_ENABLE) */

#if(STD_ON == DCM_UDS0x34_ENABLE)
/**
 * @sid				0x30
 * @brief			Dcm_ProcessRequestDownload
 * @details			Callout function. DCM shall call this callout function to start a download process.
 * 					This service is needed for the implementation of UDS service RequestDownload.
 *
 * @param[in]		OpStatus:DCM_INITIAL, DCM_PENDING and DCM_CANCEL.
 * @param[in]		DataFormatIdentifier:Bit 7 - 4: Compression Method, 0x0: not compressed, 0x1..F:
 * 					vehicle-manufacturer-specific, Bit 3 - 0: Encrypting method, 0x0: not encrypted,
 * 					0x1..F: vehicle-manufacturer-specific.
 * @param[in]		MemoryIdentifier:Identifier of the Memory Block, if the parameter is not used it
 * 					shall be set to 0.
 * @param[in]		MemoryAddress:Starting address of server memory to which data is to be written.
 * @param[in]		MemorySize:Uncompressed memory size in bytes.
 *
 * @param[in/out]	BlockLength:Max number of bytes for one Dcm_WriteMemory.
 *
 * @param[out]		ErrorCode:If the operation Dcm_ProcessRequestDownload returns value E_NOT_OK, the
 * 					DCM module shall send a negative response with NRC code equal to the parameter
 * 					ErrorCode parameter value.
 *
 * @return     		Result of this operation.
 * @retval			E_OK:Request was successful.
 * @retval			E_NOT_OK:Request was not successful.
 * @retval			DCM_E_PENDING:Request is not yet finished.
 *
 * @req [SWS_Dcm_00754]
 */
FUNC(Std_ReturnType, DCM_CODE)Dcm_ProcessRequestDownload
(
	Dcm_OpStatusType OpStatus,
	uint8 DataFormatIdentifier,
	uint8 MemoryIdentifier,
	uint32 MemoryAddress,
	uint32 MemorySize,
	P2VAR(uint32, AUTOMATIC, DCM_VAR)BlockLength,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
)
{
	Std_ReturnType result = (Std_ReturnType)E_NOT_OK;

	return result;
}
#endif /* #if(STD_ON == DCM_UDS0x34_ENABLE) */

#if(STD_ON == DCM_UDS0x38_ENABLE)
/**
 * @sid				0x57
 * @brief			Dcm_ProcessRequestFileTransfer
 * @details			Callout function. DCM shall call this callout function to start a
 * 					RequestFileTransferprocess. This service is needed for the implementation of UDS
 * 					service RequestFileTransfer.
 *
 * @param[in]		OpStatus:DCM_INITIAL, DCM_PENDING, DCM_CANCEL and DCM_FORCE_RCRRP_OK.
 * @param[in]		ModeOfOperation:This data-parameter defines the type of operation to be applied to
 * 					the file or directory indicated in the filePathAndName parameter.
 * @param[in]		FileSizeParameterLength:Defines the length in byte for the parameter filePath.
 * @param[in]		FilePathAndName:Defines the file system location of the server where the file which
 * 					shall be added, deleted, replaced or read from depending on the parameter
 * 					modeOfOperation parameter. In addition this parameter includes the file name of the
 * 					file which shall be added, deleted, replaced or read as part of the file path.
 * @param[in]		DataFormatIdentifier:Defines the length (number of bytes) of the
 * 					maxNumberOfBlockLength parameter.
 *
 * @param[in/out]	FileSizeUncompressedOrDirInfoLength:Defines the size of the uncompressed file to be
 * 					uploaded or the length of the directory information to be read in bytes.
 * @param[in/out]	FileSizeCompressed:Defines the size of the compressed file in bytes.
 *
 * @param[out]		BlockLength:Max number of bytes for one Dcm_WriteMemory.
 * @param[out]		ErrorCode:If the operation Dcm_ProcessRequestFileTransfer returns value E_NOT_OK,
 * 					the DCM module shall send a negative response with NRC code equal to the parameter
 * 					ErrorCode parameter value.
 *
 * @return     		Result of this operation.
 * @retval			E_OK:Request was successful.
 * @retval			E_NOT_OK:Request was not successful.
 * @retval			DCM_E_PENDING:Request is not yet finished.
 *
 * @req [SWS_Dcm_01120]
 */
FUNC(Std_ReturnType, DCM_CODE)Dcm_ProcessRequestFileTransfer
(
	Dcm_OpStatusType OpStatus,
	uint8 ModeOfOperation,
	uint16 FileSizeParameterLength,
	P2VAR(uint8, AUTOMATIC, DCM_CONST)FilePathAndName,
	uint8 DataFormatIdentifier,
	P2VAR(uint8, AUTOMATIC, DCM_CONST)FileSizeUncompressedOrDirInfoLength,
	P2VAR(uint8, AUTOMATIC, DCM_CONST)FileSizeCompressed,
	P2VAR(uint32, AUTOMATIC, DCM_VAR)BlockLength,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
)
{
	Std_ReturnType result = (Std_ReturnType)E_NOT_OK;

	return result;
}
#endif /* #if(STD_ON == DCM_UDS0x38_ENABLE) */

FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x10Sub0x2ConditionCheck
(
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
)
{
    Std_ReturnType result = (Std_ReturnType)E_OK;
    (void)ErrorCode;
    return result;
}

FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x11Sub0x1ConditionCheck
(
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
)
{
    Std_ReturnType result = (Std_ReturnType)E_OK;
    (void)ErrorCode;
    return result;
}

FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x22ConditionCheck
(
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
)
{
    Std_ReturnType result = (Std_ReturnType)E_OK;
    (void)ErrorCode;
    return result;
}

FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x28Sub0x0ConditionCheck
(
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
)
{
    Std_ReturnType result = (Std_ReturnType)E_OK;
    (void)ErrorCode;
    return result;
}

FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x28Sub0x3ConditionCheck
(
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
)
{
    Std_ReturnType result = (Std_ReturnType)E_OK;
    (void)ErrorCode;
    return result;
}

FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x31Sub0x1ConditionCheck
(
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
)
{
    Std_ReturnType result = (Std_ReturnType)E_OK;
    (void)ErrorCode;
    return result;
}

FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x85Sub0x1ConditionCheck
(
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
)
{
    Std_ReturnType result = (Std_ReturnType)E_OK;
    (void)ErrorCode;
    return result;
}

FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x85Sub0x2ConditionCheck
(
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
)
{
    Std_ReturnType result = (Std_ReturnType)E_OK;
    (void)ErrorCode;
    return result;
}

FUNC(Std_ReturnType, DCM_CODE)DcmDspDataConditionCheckRead_0xF180
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
)
{
    Std_ReturnType result = (Std_ReturnType)E_OK;
    (void)OpStatus;
    (void)ErrorCode;
    return result;
}

FUNC(Std_ReturnType, DCM_CODE)DcmDspDataRead_0xF180
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR)Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
)
{
    Std_ReturnType result = (Std_ReturnType)E_OK;
    (void)OpStatus;
    (void)ErrorCode;
    uint16 u16Index;
    for(u16Index = 0u; u16Index < 32u; u16Index++)
    {
        Data[u16Index] = BootVersionNumber[u16Index];
    }
    return result;
}

FUNC(Std_ReturnType, DCM_CODE)DcmDspDataConditionCheckRead_0xF187
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
)
{
    Std_ReturnType result = (Std_ReturnType)E_OK;
    (void)OpStatus;
    (void)ErrorCode;
    return result;
}

FUNC(Std_ReturnType, DCM_CODE)DcmDspDataRead_0xF187
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR)Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
)
{
    Std_ReturnType result = (Std_ReturnType)E_OK;
    (void)OpStatus;
    (void)ErrorCode;
    uint16 u16Index;
    for(u16Index = 0u; u16Index < 16u; u16Index++)
    {
        Data[u16Index] = PartNumber[u16Index];
    }
    return result;
}

FUNC(Std_ReturnType, DCM_CODE)DcmDspDataConditionCheckRead_0xF189
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
)
{
    Std_ReturnType result = (Std_ReturnType)E_OK;
    (void)OpStatus;
    (void)ErrorCode;
    return result;
}

FUNC(Std_ReturnType, DCM_CODE)DcmDspDataRead_0xF189
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR)Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
)
{
    Std_ReturnType result = (Std_ReturnType)E_OK;
    (void)OpStatus;
    (void)ErrorCode;
    uint16 u16Index;
    for(u16Index = 0u; u16Index < 24u; u16Index++)
    {
        Data[u16Index] = AppVersionNumber[u16Index];
    }
    return result;
}

FUNC(Std_ReturnType, DCM_CODE)DcmDspDataConditionCheckRead_0xF089
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
)
{
    Std_ReturnType result = (Std_ReturnType)E_OK;
    (void)OpStatus;
    (void)ErrorCode;
    return result;
}

FUNC(Std_ReturnType, DCM_CODE)DcmDspDataRead_0xF089
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR)Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
)
{
    Std_ReturnType result = (Std_ReturnType)E_OK;
    (void)OpStatus;
    (void)ErrorCode;
    uint16 u16Index;
    for(u16Index = 0u; u16Index < 24u; u16Index++)
    {
        Data[u16Index] = HardVersionNumber[u16Index];
    }
    return result;
}

FUNC(Std_ReturnType, DCM_CODE)DcmDspDataConditionCheckRead_0xF013
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
)
{
    Std_ReturnType result = (Std_ReturnType)E_OK;
    (void)OpStatus;
    (void)ErrorCode;
    return result;
}

FUNC(Std_ReturnType, DCM_CODE)DcmDspDataRead_0xF013
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR)Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
)
{
    Std_ReturnType result = (Std_ReturnType)E_OK;
    (void)OpStatus;
    (void)ErrorCode;
    uint16 u16Index;
    for(u16Index = 0u; u16Index < 16u; u16Index++)
    {
        Data[u16Index] = SoftwarePartNumber[u16Index];
    }
    return result;
}

FUNC(Std_ReturnType, DCM_CODE)DcmDspDataConditionCheckRead_0xF18A
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
)
{
    Std_ReturnType result = (Std_ReturnType)E_OK;
    (void)OpStatus;
    (void)ErrorCode;
    return result;
}

FUNC(Std_ReturnType, DCM_CODE)DcmDspDataRead_0xF18A
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR)Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
)
{
    Std_ReturnType result = (Std_ReturnType)E_OK;
    (void)OpStatus;
    (void)ErrorCode;
    uint16 u16Index;
    for(u16Index = 0u; u16Index < 10u; u16Index++)
    {
        Data[u16Index] = VendorCode[u16Index];
    }
    return result;
}

FUNC(Std_ReturnType, DCM_CODE)DcmDspDataConditionCheckRead_0xF18C
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
)
{
    Std_ReturnType result = (Std_ReturnType)E_OK;
    (void)OpStatus;
    (void)ErrorCode;
    return result;
}

FUNC(Std_ReturnType, DCM_CODE)DcmDspDataRead_0xF18C
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR)Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
)
{
    Std_ReturnType result = (Std_ReturnType)E_OK;
    (void)OpStatus;
    (void)ErrorCode;
    uint16 u16Index;
    for(u16Index = 0u; u16Index < 20u; u16Index++)
    {
        Data[u16Index] = EcuNUmber[u16Index];
    }
    return result;
}

FUNC(Std_ReturnType, DCM_CODE)DcmDspDataConditionCheckRead_0xF186
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
)
{
    Std_ReturnType result = (Std_ReturnType)E_OK;
    (void)OpStatus;
    (void)ErrorCode;
    return result;
}

FUNC(Std_ReturnType, DCM_CODE)DcmDspDataRead_0xF186
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR)Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
)
{
    Std_ReturnType result = (Std_ReturnType)E_OK;
    (void)OpStatus;
    (void)ErrorCode;
    uint16 u16Index;
    Data[0] = Dcm_ActiveSession;
    return result;
}

FUNC(Std_ReturnType, DCM_CODE)DcmDspDataConditionCheckRead_0xF184
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
)
{
    Std_ReturnType result = (Std_ReturnType)E_OK;
    (void)OpStatus;
    (void)ErrorCode;
    return result;
}

FUNC(Std_ReturnType, DCM_CODE)DcmDspDataRead_0xF184
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR)Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
)
{
    Std_ReturnType result = (Std_ReturnType)E_OK;
    (void)OpStatus;
    (void)ErrorCode;
    uint16 u16Index;
    uint8 RealLeng = 0;
    EE_ReadRecord(&eeConf,EE_BLOCK_Finger_F184,19,Data,&RealLeng,NULL_PTR);
    return result;
}

FUNC(Std_ReturnType, DCM_CODE)DcmDspDataConditionCheckRead_0xF0F1
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
)
{
    Std_ReturnType result = (Std_ReturnType)E_OK;
    (void)OpStatus;
    (void)ErrorCode;
    return result;
}

uint32 UpdataTriedCounter = 0;
FUNC(Std_ReturnType, DCM_CODE)DcmDspDataRead_0xF0F1
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR)Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
)
{
    Std_ReturnType result = (Std_ReturnType)E_OK;
    (void)OpStatus;
    (void)ErrorCode;
    uint16 u16Index;
    uint8 RealLeng = 0;
    EE_ReadRecord(&eeConf,EE_UpdataTriedCounter,4,&UpdataTriedCounter,&RealLeng,NULL_PTR);

    Data[0] = EE_UpdataTriedCounter >> 16;
    Data[1] = EE_UpdataTriedCounter >> 24;
    Data[2] = EE_UpdataTriedCounter;
    Data[3] = EE_UpdataTriedCounter >> 8;

    return result;
}

FUNC(Std_ReturnType, DCM_CODE)DcmDspDataConditionCheckRead_0xF0F3
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
)
{
    Std_ReturnType result = (Std_ReturnType)E_OK;
    (void)OpStatus;
    (void)ErrorCode;
    return result;
}

uint32 DependecyCheckSeccessCounter = 0;
FUNC(Std_ReturnType, DCM_CODE)DcmDspDataRead_0xF0F3
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR)Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
)
{
    Std_ReturnType result = (Std_ReturnType)E_OK;
    (void)OpStatus;
    (void)ErrorCode;
    uint16 u16Index;
    uint8 RealLeng = 0;
    EE_ReadRecord(&eeConf,EE_DependecyCheckSeccessCounter,4,&DependecyCheckSeccessCounter,&RealLeng,NULL_PTR);
    Data[0] = DependecyCheckSeccessCounter >> 16;
    Data[1] = DependecyCheckSeccessCounter >> 24;
    Data[2] = DependecyCheckSeccessCounter;
    Data[3] = DependecyCheckSeccessCounter >> 8;
    return result;
}

FUNC(Std_ReturnType, DCM_CODE)DcmDspDataConditionCheckRead_0xF160
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
)
{
    Std_ReturnType result = (Std_ReturnType)E_OK;
    (void)OpStatus;
    (void)ErrorCode;
    return result;
}

uint8 SignaturePublicKeyStatus = 1;
FUNC(Std_ReturnType, DCM_CODE)DcmDspDataRead_0xF160
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR)Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
)
{
    Std_ReturnType result = (Std_ReturnType)E_OK;
    (void)OpStatus;
    (void)ErrorCode;
    uint16 u16Index;
    *Data = SignaturePublicKeyStatus;
    return result;
}

FUNC(Std_ReturnType, DCM_CODE)StartRoutine_0x203_CheckProgrammingPreconditions
(
    P2VAR(uint8, AUTOMATIC, DCM_VAR)DataIn,
    P2CONST(uint8, AUTOMATIC, DCM_CONST)DataInVar,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR)DataOut,
    P2VAR(uint8, AUTOMATIC, DCM_VAR)DataOutVar,
    uint16 CurrentLengthDataInVar,
    P2VAR(uint16, AUTOMATIC, DCM_VAR)CurrentLengthDataOutVar,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
)
{
    Std_ReturnType result = (Std_ReturnType)E_OK;
    (void)DataIn;
    (void)DataInVar;
    (void)OpStatus;
    (void)DataOut;
    (void)DataOutVar;
    (void)CurrentLengthDataInVar;
    (void)ErrorCode;
    *DataOut = 0x00;
    *CurrentLengthDataOutVar = 1;
    return result;
}



FUNC(Std_ReturnType, DCM_CODE)DcmDspSecurityCompareKey_Level_1
(
    P2CONST(uint8, AUTOMATIC, DCM_CONST)Key,
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
)
{
       Std_ReturnType ret = E_OK;

    uint8 expectedKey[16] = {0u};
    struct aes128_t ctx;
    
    aes128_init_cmac(&ctx,SecurityConstant);
    aes128_cmac(&ctx,LocalSeed,16,expectedKey);

    for(uint8 index = 0;index < 16;index++)
    {
        if(expectedKey[index] == Key[index])
        {
            ret = E_OK;
        }
        else
        {
            *ErrorCode = DCM_E_INVALIDKEY;
            ret = DCM_E_COMPARE_KEY_FAILED;
            break;
        }
    }

    return ret;
}

FUNC(Std_ReturnType, DCM_CODE)DcmDspSecurityGetSeed_Level_1
(
    P2CONST(uint8, AUTOMATIC, DCM_CONST)SecurityAccessDataRecord,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR)Seed,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
)
{
    Std_ReturnType ret = E_OK;
    // uint8 u8Index;

    
    // for(u8Index = 0;u8Index < 16;u8Index += 4)
    // {
    //     LocalSeed[u8Index] = randSeed & 0xFF;
    //     LocalSeed[u8Index+1] = (randSeed >> 8) & 0xFF;
    //     LocalSeed[u8Index+2] = (randSeed >> 16) & 0xFF;
    //     LocalSeed[u8Index+3] = (randSeed >> 24) & 0xFF;
    // }

    Trng_GetRandom(LocalSeed,16);

    if(LocalSeed != NULL_PTR)
    {
        Dcm_MemoryCopy(LocalSeed, Seed, 16U);
        ret = E_OK;
    }
    return ret;
		
}		



#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#ifdef __cplusplus
}
#endif
/** @} */