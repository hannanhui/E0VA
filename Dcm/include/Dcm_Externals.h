/**
 * @file        Dcm_Externals.h
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

#ifndef DCM_EXTERNALS_H
#define DCM_EXTERNALS_H

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
#define DCM_EXTERNALS_VENDOR_ID                           	(0x00U)
#define DCM_EXTERNALS_AR_RELEASE_MAJOR_VERSION            	(0x04U)
#define DCM_EXTERNALS_AR_RELEASE_MINOR_VERSION            	(0x02U)
#define DCM_EXTERNALS_AR_RELEASE_REVISION_VERSION         	(0x02U)
#define DCM_EXTERNALS_SW_MAJOR_VERSION                    	(0x01U)
#define DCM_EXTERNALS_SW_MINOR_VERSION                    	(0x02U)
#define DCM_EXTERNALS_SW_PATCH_VERSION                    	(0x00U)
/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/
/* Check if current file and Dcm_Types header file are of the same vendor */
#if(DCM_EXTERNALS_VENDOR_ID != DCM_TYPES_VENDOR_ID )
#error "Dcm_Externals.h and Dcm_Types.h have different vendor id"
#endif
/* Check if current file and Dcm_Types header file are of the same Autosar version */
#if(\
		(DCM_EXTERNALS_AR_RELEASE_MAJOR_VERSION != DCM_TYPES_AR_RELEASE_MAJOR_VERSION) || \
		(DCM_EXTERNALS_AR_RELEASE_MINOR_VERSION != DCM_TYPES_AR_RELEASE_MINOR_VERSION) || \
		(DCM_EXTERNALS_AR_RELEASE_REVISION_VERSION != DCM_TYPES_AR_RELEASE_REVISION_VERSION) \
)
#error "AutoSar Version Number of Dcm_Externals.h and Dcm_Types.h are different"
#endif
/* Check if current file and Dcm_Types header file are of the same software version */
#if(\
		(DCM_EXTERNALS_SW_MAJOR_VERSION != DCM_TYPES_SW_MAJOR_VERSION) || \
		(DCM_EXTERNALS_SW_MINOR_VERSION != DCM_TYPES_SW_MINOR_VERSION) || \
		(DCM_EXTERNALS_SW_PATCH_VERSION != DCM_TYPES_SW_PATCH_VERSION) \
)
#error "Software Version Number of Dcm_Externals.h and Dcm_Types.h are different"
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

#if((STD_ON == DCM_UDS0x23_ENABLE) || (STD_ON == DCM_UDS0x2C_ENABLE) || (STD_ON == DCM_UDS0x36_ENABLE))
FUNC(Dcm_ReturnReadMemoryType, DCM_CODE)Dcm_ReadMemory
(
	Dcm_OpStatusType OpStatus,
	uint8 MemoryIdentifier,
	uint32 MemoryAddress,
	uint32 MemorySize,
	P2VAR(uint8, AUTOMATIC, DCM_VAR)MemoryData,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
);
#endif /* #if((STD_ON == DCM_UDS0x23_ENABLE) || (STD_ON == DCM_UDS0x36_ENABLE)) */

#if((STD_ON == DCM_UDS0x3D_ENABLE) || (STD_ON == DCM_UDS0x36_ENABLE))
FUNC(Dcm_ReturnWriteMemoryType, DCM_CODE)Dcm_WriteMemory
(
	Dcm_OpStatusType OpStatus,
	uint8 MemoryIdentifier,
	uint32 MemoryAddress,
	uint32 MemorySize,
	P2CONST(uint8, AUTOMATIC, DCM_CONST)MemoryData,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
);
#endif /* #if((STD_ON == DCM_UDS0x3D_ENABLE) || (STD_ON == DCM_UDS0x36_ENABLE)) */

FUNC(Std_ReturnType, DCM_CODE)Dcm_SetProgConditions
(
	Dcm_OpStatusType OpStatus,
	P2CONST(Dcm_ProgConditionsType, AUTOMATIC, DCM_CONST)ProgConditions
);

FUNC(Dcm_EcuStartModeType, DCM_CODE)Dcm_GetProgConditions
(
	P2VAR(Dcm_ProgConditionsType, AUTOMATIC, DCM_VAR)ProgConditions
);

#if(STD_ON == DCM_UDS0x37_ENABLE)
FUNC(Std_ReturnType, DCM_CODE)Dcm_ProcessRequestTransferExit
(
	Dcm_OpStatusType OpStatus,
	P2VAR(uint8, AUTOMATIC, DCM_VAR)TransferRequestParameterRecord,
	uint32 TransferRequestParameterRecordSize,
	P2VAR(uint8, AUTOMATIC, DCM_VAR)TransferResponseParameterRecord,
	P2VAR(uint32, AUTOMATIC, DCM_VAR)TransferResponseParameterRecordSize,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
);
#endif /* #if(STD_ON == DCM_UDS0x37_ENABLE) */

#if(STD_ON == DCM_UDS0x34_ENABLE)
FUNC(Std_ReturnType, DCM_CODE)Dcm_ProcessRequestDownload
(
	Dcm_OpStatusType OpStatus,
	uint8 DataFormatIdentifier,
	uint8 MemoryIdentifier,
	uint32 MemoryAddress,
	uint32 MemorySize,
	P2VAR(uint32, AUTOMATIC, DCM_VAR)BlockLength,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
);
#endif /* #if(STD_ON == DCM_UDS0x34_ENABLE) */

#if(STD_ON == DCM_UDS0x35_ENABLE)
FUNC(Std_ReturnType, DCM_CODE)Dcm_ProcessRequestUpload
(
	Dcm_OpStatusType OpStatus,
	uint8 DataFormatIdentifier,
	uint8 MemoryIdentifier,
	uint32 MemoryAddress,
	uint32 MemorySize,
	P2VAR(uint32, AUTOMATIC, DCM_VAR)BlockLength,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
);
#endif /* #if(STD_ON == DCM_UDS0x35_ENABLE) */

#if(STD_ON == DCM_UDS0x38_ENABLE)
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
);
#endif /* #if(STD_ON == DCM_UDS0x38_ENABLE) */

#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* DCM_EXTERNALS_H */
/** @} */
