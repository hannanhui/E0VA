/**
 * @file        Dcm_UserCallOut.h
 * @brief       AUTOSAR 4.2.2 - 4.2.2 driver header file.
 * @details     Dcm driver header file, containing the Autosar API specification and
 *               other variables and functions that are exported by the Dcm driver.
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

#ifndef DCM_USERCALLOUT_H
#define DCM_USERCALLOUT_H

#ifdef __cplusplus
extern "C"{
#endif

/*====================================================================================================*
 *                                           INCLUDE FILES                                          
 *====================================================================================================*/
#include "Rte_Dcm_type.h"
#include "Dcm_Types.h"
/*====================================================================================================*
 *                                  HEADER FILE VERSION INFORMATION
 *====================================================================================================*/
#define DCM_USERCALLOUT_VENDOR_ID	                        (0x00U)
#define DCM_USERCALLOUT_AR_RELEASE_MAJOR_VERSION	        (0x04U)
#define DCM_USERCALLOUT_AR_RELEASE_MINOR_VERSION	        (0x02U)
#define DCM_USERCALLOUT_AR_RELEASE_REVISION_VERSION	        (0x02U)
#define DCM_USERCALLOUT_SW_MAJOR_VERSION	                (0x01U)
#define DCM_USERCALLOUT_SW_MINOR_VERSION	                (0x02U)
#define DCM_USERCALLOUT_SW_PATCH_VERSION	                (0x00U)
/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/
/* Check if current file and Dcm_Types header file are of the same vendor */
#if(DCM_USERCALLOUT_VENDOR_ID != DCM_TYPES_VENDOR_ID )
#error "Dcm_UserCallOut.h and Dcm_Types.h have different vendor id"
#endif
/* Check if current file and Dcm_Types header file are of the same Autosar version */
#if(\
		(DCM_USERCALLOUT_AR_RELEASE_MAJOR_VERSION != DCM_TYPES_AR_RELEASE_MAJOR_VERSION) || \
		(DCM_USERCALLOUT_AR_RELEASE_MINOR_VERSION != DCM_TYPES_AR_RELEASE_MINOR_VERSION) || \
		(DCM_USERCALLOUT_AR_RELEASE_REVISION_VERSION != DCM_TYPES_AR_RELEASE_REVISION_VERSION) \
)
#error "AutoSar Version Number of Dcm_UserCallOut.h and Dcm_Types.h are different"
#endif
/* Check if current file and Dcm_Types header file are of the same software version */
#if(\
		(DCM_USERCALLOUT_SW_MAJOR_VERSION != DCM_TYPES_SW_MAJOR_VERSION) || \
		(DCM_USERCALLOUT_SW_MINOR_VERSION != DCM_TYPES_SW_MINOR_VERSION) || \
		(DCM_USERCALLOUT_SW_PATCH_VERSION != DCM_TYPES_SW_PATCH_VERSION) \
)
#error "Software Version Number of Dcm_UserCallOut.h and Dcm_Types.h are different"
#endif
#ifndef DISABLE_INTERMOD_VERSION_CHECK
/* Check if current file and Rte_Dcm_type header file are of the same Autosar version */
#if(\
		(DCM_USERCALLOUT_AR_RELEASE_MAJOR_VERSION != RTE_DCM_TYPE_AR_RELEASE_MAJOR_VERSION) || \
		(DCM_USERCALLOUT_AR_RELEASE_MINOR_VERSION != RTE_DCM_TYPE_AR_RELEASE_MINOR_VERSION) \
)
#error "AutoSar Version Number of Dcm.h and Rte_Dcm_type.h are different"
#endif
#endif
/*====================================================================================================*
 *                                        FUNCTION PROTOTYPES                                       
 *====================================================================================================*/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"

FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x10Sub0x2ConditionCheck
(
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
);

FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x11Sub0x1ConditionCheck
(
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
);

FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x22ConditionCheck
(
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
);

FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x31Sub0x1ConditionCheck
(
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
);

FUNC(Std_ReturnType, DCM_CODE)DcmDspDataConditionCheckRead_0xF180
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
);

FUNC(Std_ReturnType, DCM_CODE)DcmDspDataRead_0xF180
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR)Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
);

FUNC(Std_ReturnType, DCM_CODE)DcmDspDataConditionCheckRead_0xF187
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
);

FUNC(Std_ReturnType, DCM_CODE)DcmDspDataRead_0xF187
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR)Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
);

FUNC(Std_ReturnType, DCM_CODE)DcmDspDataConditionCheckRead_0xF089
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
);

FUNC(Std_ReturnType, DCM_CODE)DcmDspDataRead_0xF089
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR)Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
);

FUNC(Std_ReturnType, DCM_CODE)DcmDspDataConditionCheckRead_0xF18A
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
);

FUNC(Std_ReturnType, DCM_CODE)DcmDspDataRead_0xF18A
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR)Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
);

FUNC(Std_ReturnType, DCM_CODE)DcmDspDataConditionCheckRead_0xF186
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
);

FUNC(Std_ReturnType, DCM_CODE)DcmDspDataRead_0xF186
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR)Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
);

FUNC(Std_ReturnType, DCM_CODE)DcmDspDataConditionCheckRead_0xF184
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
);

FUNC(Std_ReturnType, DCM_CODE)DcmDspDataRead_0xF184
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR)Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
);

FUNC(Std_ReturnType, DCM_CODE)DcmDspDataWrite_0xF184
(
    P2CONST(uint8, AUTOMATIC, DCM_CONST)Data,
    uint16 DataLength,
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
);

FUNC(Std_ReturnType, DCM_CODE)DcmDspDataConditionCheckRead_0xF0F1
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
);

FUNC(Std_ReturnType, DCM_CODE)DcmDspDataRead_0xF0F1
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR)Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
);

FUNC(Std_ReturnType, DCM_CODE)DcmDspDataConditionCheckRead_0xF0F3
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
);

FUNC(Std_ReturnType, DCM_CODE)DcmDspDataRead_0xF0F3
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR)Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
);

FUNC(Std_ReturnType, DCM_CODE)DcmDspDataConditionCheckRead_0xF160
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
);

FUNC(Std_ReturnType, DCM_CODE)DcmDspDataRead_0xF160
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR)Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
);

FUNC(Std_ReturnType, DCM_CODE)DcmDspStartRoutine_0x0203
(
    P2VAR(uint8, AUTOMATIC, DCM_VAR)DataIn,
    P2CONST(uint8, AUTOMATIC, DCM_CONST)DataInVar,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR)DataOut,
    P2VAR(uint8, AUTOMATIC, DCM_VAR)DataOutVar,
    uint16 CurrentLengthDataInVar,
    P2VAR(uint16, AUTOMATIC, DCM_VAR)CurrentLengthDataOutVar,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
);

FUNC(Std_ReturnType, DCM_CODE)DcmDspStartRoutine_0xFF00_EraseMemory
(
    P2VAR(uint8, AUTOMATIC, DCM_VAR)DataIn,
    P2CONST(uint8, AUTOMATIC, DCM_CONST)DataInVar,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR)DataOut,
    P2VAR(uint8, AUTOMATIC, DCM_VAR)DataOutVar,
    uint16 CurrentLengthDataInVar,
    P2VAR(uint16, AUTOMATIC, DCM_VAR)CurrentLengthDataOutVar,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
);

FUNC(Std_ReturnType, DCM_CODE)DcmDspStartRoutine_0xFF01_checkProgrammingDependencies
(
    P2VAR(uint8, AUTOMATIC, DCM_VAR)DataIn,
    P2CONST(uint8, AUTOMATIC, DCM_CONST)DataInVar,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR)DataOut,
    P2VAR(uint8, AUTOMATIC, DCM_VAR)DataOutVar,
    uint16 CurrentLengthDataInVar,
    P2VAR(uint16, AUTOMATIC, DCM_VAR)CurrentLengthDataOutVar,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
);

FUNC(Std_ReturnType, DCM_CODE)DcmDspStartRoutine_0xDD01_StayInBoot
(
    P2VAR(uint8, AUTOMATIC, DCM_VAR)DataIn,
    P2CONST(uint8, AUTOMATIC, DCM_CONST)DataInVar,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR)DataOut,
    P2VAR(uint8, AUTOMATIC, DCM_VAR)DataOutVar,
    uint16 CurrentLengthDataInVar,
    P2VAR(uint16, AUTOMATIC, DCM_VAR)CurrentLengthDataOutVar,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
);

FUNC(Std_ReturnType, DCM_CODE)DcmDspStartRoutine_0xDD02_SecuritySignatureVerification
(
    P2VAR(uint8, AUTOMATIC, DCM_VAR)DataIn,
    P2CONST(uint8, AUTOMATIC, DCM_CONST)DataInVar,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR)DataOut,
    P2VAR(uint8, AUTOMATIC, DCM_VAR)DataOutVar,
    uint16 CurrentLengthDataInVar,
    P2VAR(uint16, AUTOMATIC, DCM_VAR)CurrentLengthDataOutVar,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
);

FUNC(Std_ReturnType, DCM_CODE)DcmDspSecurityCompareKey_Level_FBL
(
    P2CONST(uint8, AUTOMATIC, DCM_CONST)Key,
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
);

FUNC(Std_ReturnType, DCM_CODE)DcmDspSecurityGetSeed_Level_FBL
(
    P2CONST(uint8, AUTOMATIC, DCM_CONST)SecurityAccessDataRecord,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR)Seed,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
);

#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* DCM_USERCALLOUT_H */
/** @} */
