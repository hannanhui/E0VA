/**
 * @file        Dcm_UDS0x19.c
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

#ifdef AH_TEST_DCM
#include "TestCode.h"
#endif /* #ifdef AH_TEST_DCM */

#if(STD_ON == DCM_UDS0x19_ENABLE)
#if(STD_ON == DCM_UDS0x19_INTERNAL_FNC_ENABLE)
/**
 * @req [SWS_Dcm_00248] The Dcm module shall implement the UDS Service 0x19.
 */
/*====================================================================================================*
 *                                  SOURCE FILE VERSION INFORMATION
 *====================================================================================================*/
#define DCM_UDS0X19_VENDOR_ID_C                            	(0x00U)
#define DCM_UDS0X19_AR_RELEASE_MAJOR_VERSION_C             	(0x04U)
#define DCM_UDS0X19_AR_RELEASE_MINOR_VERSION_C             	(0x02U)
#define DCM_UDS0X19_AR_RELEASE_REVISION_VERSION_C          	(0x02U)
#define DCM_UDS0X19_SW_MAJOR_VERSION_C                     	(0x01U)
#define DCM_UDS0X19_SW_MINOR_VERSION_C                     	(0x02U)
#define DCM_UDS0X19_SW_PATCH_VERSION_C                     	(0x00U)
/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/
/* Check if current file and Dcm_Internal header file are of the same vendor */
#if(DCM_UDS0X19_VENDOR_ID_C != DCM_INTERNAL_VENDOR_ID )
#error "Dcm_UDS0x19.c and Dcm_Internal.h have different vendor id"
#endif
/* Check if current file and Dcm_Internal header file are of the same Autosar version */
#if(\
		(DCM_UDS0X19_AR_RELEASE_MAJOR_VERSION_C != DCM_INTERNAL_AR_RELEASE_MAJOR_VERSION) || \
		(DCM_UDS0X19_AR_RELEASE_MINOR_VERSION_C != DCM_INTERNAL_AR_RELEASE_MINOR_VERSION) || \
		(DCM_UDS0X19_AR_RELEASE_REVISION_VERSION_C != DCM_INTERNAL_AR_RELEASE_REVISION_VERSION) \
)
#error "AutoSar Version Number of Dcm_UDS0x19.c and Dcm_Internal.h are different"
#endif
/* Check if current file and Dcm_Internal header file are of the same software version */
#if(\
		(DCM_UDS0X19_SW_MAJOR_VERSION_C != DCM_INTERNAL_SW_MAJOR_VERSION) || \
		(DCM_UDS0X19_SW_MINOR_VERSION_C != DCM_INTERNAL_SW_MINOR_VERSION) || \
		(DCM_UDS0X19_SW_PATCH_VERSION_C != DCM_INTERNAL_SW_PATCH_VERSION) \
)
#error "Software Version Number of Dcm_UDS0x19.c and Dcm_Internal.h are different"
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

#define DCM_DEM_GETNUMBEROFFILTEREDDTC_PENDING_BIT					(0u)
#define DCM_DEM_GETNEXTFILTEREDDTC_PENDING_BIT						(1u)
#define DCM_DEM_GETNEXTFILTEREDDTCANDSEVERITY_PENDING_BIT			(2u)
#define DCM_DEM_GETSEVERITYOFDTC_PENDING_BIT						(3u)
#define DCM_DEM_GETFUNCTIONALUNITOFDTC_PENDING_BIT					(4u)
#define DCM_DEM_GETSTATUSOFDTC_PENDING_BIT							(5u)
#define DCM_DEM_DISABLEDTCRECORDUPDATE_PENDING_BIT					(6u)
#define DCM_DEM_GETSIZEOFEXTENDEDDATARECORDSELECTION_PENDING_BIT	(7u)
#define DCM_DEM_GETNEXTEXTENDEDDATARECORD_PENDING_BIT				(8u)
#define DCM_DEM_GETSIZEOFFREEZEFRAMESELECTION_PENDING_BIT			(9u)
#define DCM_DEM_GETNEXTFREEZEFRAMEDATA_PENDING_BIT					(10u)
#define DCM_DEM_GETNEXTFILTEREDRECORD_PENDING_BIT					(11u)
/*====================================================================================================*
 *                                           LOCAL CONSTANTS
 *====================================================================================================*/

/*====================================================================================================*
 *                                           LOCAL VARIABLES
 *====================================================================================================*/
#define DCM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dcm_MemMap.h"

/**
 * @brief	Store internal status of service 0x19 during its processing.
 */
STATIC VAR(Dcm_ReadDTCInfoStatusType, DCM_VAR)Dcm_UDS0x19Status;

#define DCM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dcm_MemMap.h"
/*====================================================================================================*
 *                                      LOCAL FUNCTION PROTOTYPES
 *====================================================================================================*/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"

STATIC FUNC(uint32, DCM_CODE)Dcm_UDS0x19GetReqMsgLen
(
    uint8 u8SubServiceId
);

STATIC FUNC(Dem_DTCKindType, DCM_CODE)Dcm_UDS0x19GetDTCKind
(
    uint8 u8SubServiceId
);

STATIC FUNC(Dem_DTCOriginType, DCM_CODE)Dcm_UDS0x19GetDTCOrigin
(
    uint8 u8SubServiceId,
    P2CONST(Dcm_MsgContextType, AUTOMATIC, DCM_CONST)pMsgContext
);

STATIC FUNC(uint8, DCM_CODE)Dcm_UDS0x19GetDTCStatusMask
(
    uint8 u8SubServiceId,
    P2CONST(Dcm_MsgContextType, AUTOMATIC, DCM_CONST)pMsgContext
);

#if((STD_ON == DCM_UDS0x19_SUB0x01_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x07_ENABLE) ||\
	(STD_ON == DCM_UDS0x19_SUB0x11_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x12_ENABLE))
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x19ReportDTCNumberHandle
(
	uint8 u8SubServiceId,
	Dcm_OpStatusType opState,
	P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
);
#endif /* #if((STD_ON == DCM_UDS0x19_SUB0x01_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x07_ENABLE) ||\
			  (STD_ON == DCM_UDS0x19_SUB0x11_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x12_ENABLE)) */

#if((STD_ON == DCM_UDS0x19_SUB0x02_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x0A_ENABLE) ||\
	(STD_ON == DCM_UDS0x19_SUB0x0F_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x13_ENABLE) ||\
	(STD_ON == DCM_UDS0x19_SUB0x15_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x17_ENABLE))
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x19ReportDTCAndStatusHandle
(
	uint8 u8SubServiceId,
	Dcm_OpStatusType opState,
	P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
);
#endif /* #if((STD_ON == DCM_UDS0x19_SUB0x02_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x0A_ENABLE) ||\
			  (STD_ON == DCM_UDS0x19_SUB0x0F_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x13_ENABLE) ||\
			  (STD_ON == DCM_UDS0x19_SUB0x15_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x17_ENABLE)) */

#if(STD_ON == DCM_UDS0x19_SUB0x08_ENABLE)
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x19ReprotDTCBySMaskHandle
(
	Dcm_OpStatusType opState,
	P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
);
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x08_ENABLE) */

#if(STD_ON == DCM_UDS0x19_SUB0x09_ENABLE)
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x19ReportSInfoOfDTCHandle
(
	Dcm_OpStatusType opState,
	P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
);
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x09_ENABLE) */

#if((STD_ON == DCM_UDS0x19_SUB0x06_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x10_ENABLE) ||\
	(STD_ON == DCM_UDS0x19_SUB0x19_ENABLE))
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x19ReportExtDataRecordHandle
(
	uint8 u8SubServiceId,
	Dcm_OpStatusType opState,
	P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
);
#endif /* #if((STD_ON == DCM_UDS0x19_SUB0x06_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x10_ENABLE) ||\
			  (STD_ON == DCM_UDS0x19_SUB0x19_ENABLE)) */

#if(STD_ON == DCM_UDS0x19_SUB0x03_ENABLE)
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x19ReportDTCSnapshotIdentificationHandle
(
	Dcm_OpStatusType opState,
	P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
);
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x03_ENABLE) */

#if((STD_ON == DCM_UDS0x19_SUB0x04_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x18_ENABLE))
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x19ReportDTCSnapshotRecordByDTCNumberHandle
(
	uint8 u8SubServiceId,
	Dcm_OpStatusType opState,
	P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
);
#endif /* #if((STD_ON == DCM_UDS0x19_SUB0x04_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x18_ENABLE)) */

#if(STD_ON == DCM_UDS0x19_SUB0x05_ENABLE)
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x19ReportDTCStoredDataByRecordNumberHandle
(
	P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
);
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x05_ENABLE) */

#if((STD_ON == DCM_UDS0x19_SUB0x0B_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x0C_ENABLE) ||\
	(STD_ON == DCM_UDS0x19_SUB0x0D_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x0E_ENABLE))
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x19ReportSpecificDTCHandle
(
	uint8 u8SubServiceId,
	P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
);
#endif /* #if((STD_ON == DCM_UDS0x19_SUB0x0B_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x0C_ENABLE) ||\
			  (STD_ON == DCM_UDS0x19_SUB0x0D_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x0E_ENABLE)) */

#if(STD_ON == DCM_UDS0x19_SUB0x14_ENABLE)
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x19ReportDTCFaultDetectionCounterHandle
(
	P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
);
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x14_ENABLE) */

#if(STD_ON == DCM_UDS0x19_SUB0x42_ENABLE)
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x19ReportWWHOBDDTCByMaskRecordHandle
(
	uint8 u8SubServiceId,
	P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
);
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x42_ENABLE) */

#if(STD_ON == DCM_UDS0x19_SUB0x55_ENABLE)
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x19ReportWWHOBDDTCWithPermanentStatusHandle
(
	uint8 u8SubServiceId,
	P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
);
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x55_ENABLE) */
/*====================================================================================================*
 *                                           LOCAL FUNCTIONS
 *====================================================================================================*/
/**
 * @brief           Dcm_UDS0x19GetReqMsgLen
 * @details         Return the request message length to be checked based on the requested sub-service.
 *
 * @param[in]       u8SubServiceId:Sub function identifier.
 *
 * @return          The request message length to be checked.
 */
STATIC FUNC(uint32, DCM_CODE)Dcm_UDS0x19GetReqMsgLen
(
    uint8 u8SubServiceId
)
{
    uint32 u32ReqLen = 0u;

    switch(u8SubServiceId)
    {
#if((STD_ON == DCM_UDS0x19_SUB0x01_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x02_ENABLE) ||\
    (STD_ON == DCM_UDS0x19_SUB0x0F_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x11_ENABLE) ||\
    (STD_ON == DCM_UDS0x19_SUB0x12_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x13_ENABLE))
#if(STD_ON == DCM_UDS0x19_SUB0x01_ENABLE)
        case 0x01u:
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x01_ENABLE) */
#if(STD_ON == DCM_UDS0x19_SUB0x02_ENABLE)
        case 0x02u:
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x02_ENABLE) */
#if(STD_ON == DCM_UDS0x19_SUB0x0F_ENABLE)
        case 0x0Fu:
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x0F_ENABLE) */
#if(STD_ON == DCM_UDS0x19_SUB0x11_ENABLE)
        case 0x11u:
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x11_ENABLE) */
#if(STD_ON == DCM_UDS0x19_SUB0x12_ENABLE)
        case 0x12u:
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x12_ENABLE) */
#if(STD_ON == DCM_UDS0x19_SUB0x13_ENABLE)
        case 0x13u:
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x13_ENABLE) */
            u32ReqLen = 3u;
            break;
#endif /* #if((STD_ON == DCM_UDS0x19_SUB0x01_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x02_ENABLE) ||\
              (STD_ON == DCM_UDS0x19_SUB0x0F_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x11_ENABLE) ||\
              (STD_ON == DCM_UDS0x19_SUB0x12_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x13_ENABLE)) */
#if((STD_ON == DCM_UDS0x19_SUB0x04_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x06_ENABLE) ||\
    (STD_ON == DCM_UDS0x19_SUB0x10_ENABLE))
#if(STD_ON == DCM_UDS0x19_SUB0x04_ENABLE)
        case 0x04u:
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x04_ENABLE) */
#if(STD_ON == DCM_UDS0x19_SUB0x06_ENABLE)
        case 0x06u:
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x06_ENABLE) */
#if(STD_ON == DCM_UDS0x19_SUB0x10_ENABLE)
        case 0x10u:
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x10_ENABLE) */
            u32ReqLen = 6u;
            break;
#endif /* #if((STD_ON == DCM_UDS0x19_SUB0x04_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x06_ENABLE) ||\
              (STD_ON == DCM_UDS0x19_SUB0x10_ENABLE)) */
#if((STD_ON == DCM_UDS0x19_SUB0x07_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x17_ENABLE))
#if(STD_ON == DCM_UDS0x19_SUB0x07_ENABLE)
        case 0x07u:
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x07_ENABLE) */
#if(STD_ON == DCM_UDS0x19_SUB0x17_ENABLE)
        case 0x17u:
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x17_ENABLE) */
            u32ReqLen = 4u;
            break;
#endif /* #if((STD_ON == DCM_UDS0x19_SUB0x07_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x17_ENABLE)) */
#if((STD_ON == DCM_UDS0x19_SUB0x0A_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x15_ENABLE))
#if(STD_ON == DCM_UDS0x19_SUB0x0A_ENABLE)
        case 0x0Au:
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x0A_ENABLE) */
#if(STD_ON == DCM_UDS0x19_SUB0x15_ENABLE)
        case 0x15u:
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x15_ENABLE) */
            u32ReqLen = 2u;
            break;
#endif /* #if((STD_ON == DCM_UDS0x19_SUB0x0A_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x15_ENABLE)) */
#if((STD_ON == DCM_UDS0x19_SUB0x18_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x19_ENABLE))
#if(STD_ON == DCM_UDS0x19_SUB0x18_ENABLE)
        case 0x18u:
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x18_ENABLE) */
#if(STD_ON == DCM_UDS0x19_SUB0x19_ENABLE)
        case 0x19u:
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x19_ENABLE) */
            u32ReqLen = 7u;
            break;
#endif /* #if((STD_ON == DCM_UDS0x19_SUB0x18_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x19_ENABLE)) */
        default:
            /* Nothing to do here. */
            break;
    }

    return u32ReqLen;
}

/**
 * @brief           Dcm_UDS0x19GetDTCKind
 * @details         Return the DTC kind based on the requested sub-service.
 *
 * @param[in]       u8SubServiceId:Sub function identifier.
 *
 * @return          The DTC kind.
 */
STATIC FUNC(Dem_DTCKindType, DCM_CODE)Dcm_UDS0x19GetDTCKind
(
    uint8 u8SubServiceId
)
{
	Dem_DTCKindType dtcKind = DEM_DTC_KIND_ALL_DTCS;

#if((STD_ON == DCM_UDS0x19_SUB0x12_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x13_ENABLE))
	if(((uint8)0x12 == u8SubServiceId) || ((uint8)0x13 == u8SubServiceId))
	{
		dtcKind = DEM_DTC_KIND_EMISSION_REL_DTCS;
	}
#endif /* #if((STD_ON == DCM_UDS0x19_SUB0x12_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x13_ENABLE)) */

	return dtcKind;
}

/**
 * @brief           Dcm_UDS0x19GetDTCOrigin
 * @details         Return the DTC origin based on the requested sub-service.
 *
 * @param[in]       u8SubServiceId:Sub function identifier.
 * @param[in]       pMsgContext:Message-related information for one diagnostic protocol identifier.
 *
 * @return          The DTC origin.
 */
STATIC FUNC(Dem_DTCOriginType, DCM_CODE)Dcm_UDS0x19GetDTCOrigin
(
    uint8 u8SubServiceId,
    P2CONST(Dcm_MsgContextType, AUTOMATIC, DCM_CONST)pMsgContext
)
{
    Dem_DTCOriginType dtcOrigin = DEM_DTC_ORIGIN_PRIMARY_MEMORY;

    switch(u8SubServiceId)
    {
#if((STD_ON == DCM_UDS0x19_SUB0x01_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x02_ENABLE) ||\
    (STD_ON == DCM_UDS0x19_SUB0x04_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x06_ENABLE) ||\
    (STD_ON == DCM_UDS0x19_SUB0x07_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x0A_ENABLE))
#if(STD_ON == DCM_UDS0x19_SUB0x01_ENABLE)
        case 0x01u:
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x01_ENABLE) */
#if(STD_ON == DCM_UDS0x19_SUB0x02_ENABLE)
        case 0x02u:
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x02_ENABLE) */
#if(STD_ON == DCM_UDS0x19_SUB0x04_ENABLE)
        case 0x04u:
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x04_ENABLE) */
#if(STD_ON == DCM_UDS0x19_SUB0x06_ENABLE)
        case 0x06u:
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x06_ENABLE) */
#if(STD_ON == DCM_UDS0x19_SUB0x07_ENABLE)
        case 0x07u:
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x07_ENABLE) */
#if(STD_ON == DCM_UDS0x19_SUB0x0A_ENABLE)
        case 0x0Au:
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x0A_ENABLE) */
            dtcOrigin = DEM_DTC_ORIGIN_PRIMARY_MEMORY;
            break;
#endif /* #if((STD_ON == DCM_UDS0x19_SUB0x01_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x02_ENABLE) ||\
              (STD_ON == DCM_UDS0x19_SUB0x04_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x06_ENABLE) ||\
              (STD_ON == DCM_UDS0x19_SUB0x07_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x0A_ENABLE)) */
#if((STD_ON == DCM_UDS0x19_SUB0x0F_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x10_ENABLE) ||\
    (STD_ON == DCM_UDS0x19_SUB0x11_ENABLE))
#if(STD_ON == DCM_UDS0x19_SUB0x0F_ENABLE)
        case 0x0Fu:
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x0F_ENABLE) */
#if(STD_ON == DCM_UDS0x19_SUB0x10_ENABLE)
        case 0x10u:
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x10_ENABLE) */
#if(STD_ON == DCM_UDS0x19_SUB0x11_ENABLE)
        case 0x11u:
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x11_ENABLE) */
            dtcOrigin = DEM_DTC_ORIGIN_MIRROR_MEMORY;
            break;
#endif /* #if((STD_ON == DCM_UDS0x19_SUB0x0F_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x10_ENABLE) ||\
              (STD_ON == DCM_UDS0x19_SUB0x11_ENABLE)) */
#if((STD_ON == DCM_UDS0x19_SUB0x12_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x13_ENABLE))
#if(STD_ON == DCM_UDS0x19_SUB0x12_ENABLE)
        case 0x12u:
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x12_ENABLE) */
#if(STD_ON == DCM_UDS0x19_SUB0x13_ENABLE)
        case 0x13u:
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x13_ENABLE) */
            dtcOrigin = DEM_DTC_ORIGIN_OBD_RELEVANT_MEMORY;
            break;
#endif /* #if((STD_ON == DCM_UDS0x19_SUB0x12_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x13_ENABLE)) */
#if(STD_ON == DCM_UDS0x19_SUB0x15_ENABLE)
        case 0x15u:
            dtcOrigin = DEM_DTC_ORIGIN_PERMANENT_MEMORY;
            break;
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x15_ENABLE) */
#if(STD_ON == DCM_UDS0x19_SUB0x17_ENABLE)
        case 0x17u:
            dtcOrigin = ((Dem_DTCOriginType)pMsgContext->ReqData[3] + (Dem_DTCOriginType)0x0100);
            break;
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x17_ENABLE) */
#if((STD_ON == DCM_UDS0x19_SUB0x18_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x19_ENABLE))
#if(STD_ON == DCM_UDS0x19_SUB0x18_ENABLE)
        case 0x18u:
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x18_ENABLE) */
#if(STD_ON == DCM_UDS0x19_SUB0x19_ENABLE)
        case 0x19u:
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x19_ENABLE) */
            dtcOrigin = ((Dem_DTCOriginType)pMsgContext->ReqData[6] + (Dem_DTCOriginType)0x0100);
            break;
#endif /* #if((STD_ON == DCM_UDS0x19_SUB0x18_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x19_ENABLE)) */
        default:
            /* Nothing to do here. */
            break;
    }

    return dtcOrigin;
}

/**
 * @brief           Dcm_UDS0x19GetDTCStatusMask
 * @details         Return the DTC status mask based on the requested sub-service.
 *
 * @param[in]       u8SubServiceId:Sub function identifier.
 * @param[in]       pMsgContext:Message-related information for one diagnostic protocol identifier.
 *
 * @return          The DTC status mask.
 */
STATIC FUNC(uint8, DCM_CODE)Dcm_UDS0x19GetDTCStatusMask
(
    uint8 u8SubServiceId,
    P2CONST(Dcm_MsgContextType, AUTOMATIC, DCM_CONST)pMsgContext
)
{
    uint8 u8DTCStatusMask = 0x00u;

    switch(u8SubServiceId)
    {
#if((STD_ON == DCM_UDS0x19_SUB0x01_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x02_ENABLE) ||\
    (STD_ON == DCM_UDS0x19_SUB0x0F_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x11_ENABLE) ||\
    (STD_ON == DCM_UDS0x19_SUB0x12_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x13_ENABLE) ||\
    (STD_ON == DCM_UDS0x19_SUB0x17_ENABLE))
#if(STD_ON == DCM_UDS0x19_SUB0x01_ENABLE)
        case 0x01u:
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x01_ENABLE) */
#if(STD_ON == DCM_UDS0x19_SUB0x02_ENABLE)
        case 0x02u:
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x02_ENABLE) */
#if(STD_ON == DCM_UDS0x19_SUB0x0F_ENABLE)
        case 0x0Fu:
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x0F_ENABLE) */
#if(STD_ON == DCM_UDS0x19_SUB0x11_ENABLE)
        case 0x11u:
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x11_ENABLE) */
#if(STD_ON == DCM_UDS0x19_SUB0x12_ENABLE)
        case 0x12u:
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x12_ENABLE) */
#if(STD_ON == DCM_UDS0x19_SUB0x13_ENABLE)
        case 0x13u:
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x13_ENABLE) */
#if(STD_ON == DCM_UDS0x19_SUB0x17_ENABLE)
        case 0x17u:
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x17_ENABLE) */
            u8DTCStatusMask = pMsgContext->ReqData[2];
            break;
#endif /* #if((STD_ON == DCM_UDS0x19_SUB0x01_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x02_ENABLE) ||\
              (STD_ON == DCM_UDS0x19_SUB0x0F_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x11_ENABLE) ||\
              (STD_ON == DCM_UDS0x19_SUB0x12_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x13_ENABLE) ||\
              (STD_ON == DCM_UDS0x19_SUB0x17_ENABLE)) */
#if(STD_ON == DCM_UDS0x19_SUB0x07_ENABLE)
        case 0x07u:
            u8DTCStatusMask = pMsgContext->ReqData[3];
            break;
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x07_ENABLE) */
#if((STD_ON == DCM_UDS0x19_SUB0x0A_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x15_ENABLE))
#if(STD_ON == DCM_UDS0x19_SUB0x0A_ENABLE)
        case 0x0Au:
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x0A_ENABLE) */
#if(STD_ON == DCM_UDS0x19_SUB0x15_ENABLE)
        case 0x15u:
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x15_ENABLE) */
            /* u8DTCStatusMask = 0u */
            break;
#endif /* #if((STD_ON == DCM_UDS0x19_SUB0x0A_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x15_ENABLE)) */
        default:
            /* Nothing to do here. */
            break;
    }

    return u8DTCStatusMask;
}

#if((STD_ON == DCM_UDS0x19_SUB0x01_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x07_ENABLE) ||\
	(STD_ON == DCM_UDS0x19_SUB0x11_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x12_ENABLE))
/**
 * @brief			Dcm_UDS0x19ReportDTCNumberHandle
 * @details			Service 0x19 subfunction processing interface, used to retrieve the number of DTCs.
 *
 * @param[in]		u8ClientId:Client identifier.
 * @param[in]		u8SubServiceId:Sub function identifier.
 * @param[in]		opState:Operating state.
 * @param[in]		pMsgContext:Message-related information for one diagnostic protocol identifier.
 * 					The pointers in pMsgContext shall point behind the SID.
 *
 * @param[out]		pErrorCode:If the called external interface returns E_NOT_OK, use this pointer to
 * 					output the NRC.
 *
 * @return        	Result of this operation.
 * @retval			E_OK:Processing successful.
 * @retval			E_NOT_OK:Processing failure.
 */
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x19ReportDTCNumberHandle
(
	uint8 u8SubServiceId,
	Dcm_OpStatusType opState,
	P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
)
{
	/* Sub: 0x01, 0x07, 0x11, 0x12. */

	/**
	 * @req [SWS_Dcm_00376] When sending a positive response to UDS Service 0x19 with subfunction 0x01,
	 * 		0x07, 0x11 or 0x12, the Dcm module shall use the data in the response message according to
	 * 		Table 7.
	 */

	Std_ReturnType result = (Std_ReturnType)E_NOT_OK;

	uint8 u8Ret;
	uint8 u8DTCStatusMask = Dcm_UDS0x19GetDTCStatusMask(u8SubServiceId, pMsgContext);
	uint8 u8DTCSeverityMask = 0u;
	uint16 u16DTCCount;
	boolean filterWithSeverity = (boolean)FALSE;
	boolean flag = (boolean)FALSE;

	if(DCM_PENDING != opState)
	{
		if(Dcm_UDS0x19GetReqMsgLen(u8SubServiceId) != pMsgContext->ReqDataLen)
		{
			*pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
		}
#if(STD_OFF == DCM_UDS0x19_SUB0x07_ENABLE)
		else if(0u == u8DTCStatusMask)
#else
		else if((0u == u8DTCStatusMask) || ((0x07u == u8SubServiceId) && (0u == u8DTCSeverityMask)))
#endif /* #if(STD_OFF == DCM_UDS0x19_SUB0x07_ENABLE) */
		{
			/**
			 * @req [SWS_Dcm_00700] When the Dcm module receives a request with the DTCStatusMask
			 * 		set to 0x00, it shall send positive response and shall not use the Dem interface
			 * 		Dem_DcmSetDTCFilter().
			 */
			pMsgContext->ResData[pMsgContext->ResDataLen] = 0u;
			pMsgContext->ResDataLen++;
			pMsgContext->ResData[pMsgContext->ResDataLen] = Dem_DcmGetTranslationType();
			pMsgContext->ResDataLen++;
			pMsgContext->ResData[pMsgContext->ResDataLen] = 0u;
			pMsgContext->ResDataLen++;
			pMsgContext->ResData[pMsgContext->ResDataLen] = 0u;
			pMsgContext->ResDataLen++;

			result = (Std_ReturnType)E_OK;
		}
		else
		{
#if(STD_ON == DCM_UDS0x19_SUB0x07_ENABLE)
            if(7u == u8SubServiceId)
            {
                u8DTCSeverityMask = pMsgContext->ReqData[2];
                filterWithSeverity = (boolean)TRUE;
            }
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x07_ENABLE) */
			/**
			 * @req [SWS_Dcm_00293] When responding to UDS Service 0x19 with subfunction 0x01,
			 * 		0x07, 0x11 or 0x12, the DCM module shall calculate the number of DTCs using
			 * 		Dem_DcmGetNumberOfFilteredDTC() after having set the DEM-filter with
			 * 		Dem_DcmSetDTCFilter() using the parameter values of the following table.
			 *
			 * @req [SWS_Dcm_00835] The Dcm shall call Dem_DcmSetDTCFilter prior to
			 * 		Dem_DcmGetNumberOfFilteredDTC, any sequence of Dem_DcmGetNextFilteredDTC,
			 * 		any sequence of Dem_DcmGetNextFilteredDTCAndFDC, as well as any sequence of
			 * 		Dem_DcmGetNextFilteredDTCAndSeverity.
			 *
			 * @req [SWS_Dcm_01255] If Dem_DcmSetDTCFilter() returns DEM_WRONG_FILTER, the Dcm shall
			 * 		send a NRC 0x31 (Request out of Range).
			 */
			u8Ret = Dem_DcmSetDTCFilter(\
						u8DTCStatusMask, Dcm_UDS0x19GetDTCKind(u8SubServiceId), DEM_DTC_FORMAT_UDS,\
						Dcm_UDS0x19GetDTCOrigin(u8SubServiceId, pMsgContext), filterWithSeverity,\
						u8DTCSeverityMask, (boolean)FALSE\
						);
			/**
			 * @req [SWS_Dcm_00007] The Dcm module shall retrieve the DTCStatusAvailabilityMask by
			 * 		using the function Dem_DcmGetDTCStatusAvailabilityMask().
			 */
			u8Ret |= Dem_DcmGetDTCStatusAvailabilityMask(&u8DTCStatusMask);

			if((uint8)E_OK == u8Ret)
			{
				pMsgContext->ResData[pMsgContext->ResDataLen] = u8DTCStatusMask;
				pMsgContext->ResDataLen++;

				flag = (boolean)TRUE;
			}
		}
	}
	else
	{
		flag = (boolean)TRUE;
	}

	if((boolean)TRUE == flag)
	{
		u8Ret = Dem_DcmGetNumberOfFilteredDTC(&u16DTCCount);

		if((uint8)DEM_NUMBER_OK == u8Ret)
		{
			pMsgContext->ResData[pMsgContext->ResDataLen] = Dem_DcmGetTranslationType();
			pMsgContext->ResDataLen++;
			pMsgContext->ResData[pMsgContext->ResDataLen] = (uint8)(u16DTCCount >> 8);
			pMsgContext->ResDataLen++;
			pMsgContext->ResData[pMsgContext->ResDataLen] = (uint8)u16DTCCount;
			pMsgContext->ResDataLen++;

			result = (Std_ReturnType)E_OK;
		}
		/**
		 * @req [SWS_Dcm_01239] If Dem_DcmGetNumberOfFilteredDTC() returns DEM_NUMBER_PENDING, the Dcm
		 * 		shall call again Dem_DcmGetNumberOfFilteredDTC() API in next Dcm_MainFunction() call.
		 */
		else if((uint8)DEM_NUMBER_PENDING == u8Ret)
		{
			result = (Std_ReturnType)DCM_E_PENDING;
		}
		else
		{
			/* u8Ret = DEM_NUMBER_FAILED */
			;
		}
	}

	return result;
}
#endif /* #if((STD_ON == DCM_UDS0x19_SUB0x01_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x07_ENABLE) ||\
			  (STD_ON == DCM_UDS0x19_SUB0x11_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x12_ENABLE)) */

#if((STD_ON == DCM_UDS0x19_SUB0x02_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x0A_ENABLE) ||\
	(STD_ON == DCM_UDS0x19_SUB0x0F_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x13_ENABLE) ||\
	(STD_ON == DCM_UDS0x19_SUB0x15_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x17_ENABLE))
/**
 * @brief			Dcm_UDS0x19ReportDTCAndStatusHandle
 * @details			Service 0x19 subfunction processing interface, used to retrieve the DTCs and status.
 *
 * @param[in]		u8ClientId:Client identifier.
 * @param[in]		u8SubServiceId:Sub function identifier.
 * @param[in]		opState:Operating state.
 * @param[in]		pMsgContext:Message-related information for one diagnostic protocol identifier.
 * 					The pointers in pMsgContext shall point behind the SID.
 *
 * @param[out]		pErrorCode:If the called external interface returns E_NOT_OK, use this pointer to
 * 					output the NRC.
 *
 * @return        	Result of this operation.
 * @retval			E_OK:Processing successful.
 * @retval			E_NOT_OK:Processing failure.
 */
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x19ReportDTCAndStatusHandle
(
	uint8 u8SubServiceId,
	Dcm_OpStatusType opState,
	P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
)
{
	/* Sub: 0x02, 0x0A, 0x0F, 0x13, 0x15, 0x17. */

	/**
	 * @req [SWS_Dcm_00377] When sending a positive response to UDS Service 0x19 with subfunction 0x02,
	 * 		0x0A, 0x0F, 0x13, 0x15 or 0x17, the Dcm module shall use the following data in the response
	 * 		message.
	 */

	Std_ReturnType result = (Std_ReturnType)E_NOT_OK;
	
	uint8 u8Ret;
    uint8 u8DTCStatusMask = Dcm_UDS0x19GetDTCStatusMask(u8SubServiceId, pMsgContext);
	uint8 u8AvaDTCStatusMask;
	uint8 u8DTCStatus;
	uint32 u32DTC;
	boolean flag = (boolean)FALSE;
#if((STD_ON == DCM_UDS0x19_SUB0x0A_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x15_ENABLE))
	boolean maskCheckFlag = (boolean)TRUE;
#endif /* #if((STD_ON == DCM_UDS0x19_SUB0x0A_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x15_ENABLE)) */

	if(DCM_PENDING != opState)
	{
#if((STD_ON == DCM_UDS0x19_SUB0x0A_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x15_ENABLE))
        if((0x0Au == u8SubServiceId) || (0x15u == u8SubServiceId))
        {
            maskCheckFlag = (boolean)FALSE;
        }
#endif /* #if((STD_ON == DCM_UDS0x19_SUB0x0A_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x15_ENABLE)) */

		if(Dcm_UDS0x19GetReqMsgLen(u8SubServiceId) != pMsgContext->ReqDataLen)
		{
			*pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
		}
#if((STD_ON == DCM_UDS0x19_SUB0x0A_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x15_ENABLE))
		else if(((boolean)TRUE == maskCheckFlag) && (0u == u8DTCStatusMask))
#else
		else if(0u == u8DTCStatusMask)
#endif /* #if((STD_ON == DCM_UDS0x19_SUB0x0A_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x15_ENABLE)) */
		{
#if(STD_ON == DCM_UDS0x19_SUB0x17_ENABLE)
			if(0x17u == u8SubServiceId)
			{
				pMsgContext->ResData[pMsgContext->ResDataLen] = pMsgContext->ReqData[2];
				pMsgContext->ResDataLen++;
			}
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x17_ENABLE) */

			/**
			 * @req [SWS_Dcm_00007] The Dcm module shall retrieve the DTCStatusAvailabilityMask by
			 * 		using the function Dem_DcmGetDTCStatusAvailabilityMask().
			 *
			 * @req [SWS_Dcm_00700] When the Dcm module receives a request with the DTCStatusMask set
			 * 		to 0x00, it shall send positive response and shall not use the Dem interface
			 * 		Dem_DcmSetDTCFilter().
			 */
			if((Std_ReturnType)E_OK == Dem_DcmGetDTCStatusAvailabilityMask(&u8AvaDTCStatusMask))
			{
				pMsgContext->ResData[pMsgContext->ResDataLen] = u8AvaDTCStatusMask;
				pMsgContext->ResDataLen++;

				result = (Std_ReturnType)E_OK;
			}
		}
		else
		{
			/*
			 * @req [SWS_Dcm_00835] The Dcm shall call Dem_DcmSetDTCFilter prior to
			 * 		Dem_DcmGetNumberOfFilteredDTC, any sequence of Dem_DcmGetNextFilteredDTC,
			 * 		any sequence of Dem_DcmGetNextFilteredDTCAndFDC, as well as any sequence of
			 * 		Dem_DcmGetNextFilteredDTCAndSeverity.
			 *
			 * @req [SWS_Dcm_01255] If Dem_DcmSetDTCFilter() returns DEM_WRONG_FILTER, the Dcm shall
			 * 		send a NRC 0x31 (Request out of Range).
			 */
			u8Ret = Dem_DcmSetDTCFilter(\
						u8DTCStatusMask, Dcm_UDS0x19GetDTCKind(u8SubServiceId), DEM_DTC_FORMAT_UDS,\
						Dcm_UDS0x19GetDTCOrigin(u8SubServiceId, pMsgContext), (boolean)FALSE,\
						(uint8)0x00, (boolean)FALSE\
						);
			/**
			 * @req [SWS_Dcm_00007] The Dcm module shall retrieve the DTCStatusAvailabilityMask by using
			 * 		the function Dem_DcmGetDTCStatusAvailabilityMask().
			 */
			u8Ret |= Dem_DcmGetDTCStatusAvailabilityMask(&u8AvaDTCStatusMask);

			if((uint8)E_OK == u8Ret)
			{
				/**
				 * @req [SWS_Dcm_00377] When sending a positive response to UDS Service 0x19 with
				 * 		subfunction 0x02, 0x0A, 0x0F, 0x13, 0x15 or 0x17, the Dcm module shall use the
				 * 		data in the response message according to Table 7.10.
				 */
#if(STD_ON == DCM_UDS0x19_SUB0x17_ENABLE)
				if((uint8)0x17 == u8SubServiceId)
				{
					pMsgContext->ResData[pMsgContext->ResDataLen] = pMsgContext->ReqData[2];
					pMsgContext->ResDataLen++;
				}
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x17_ENABLE) */

				pMsgContext->ResData[pMsgContext->ResDataLen] = u8AvaDTCStatusMask;
				pMsgContext->ResDataLen++;

				/**
				 * @req [SWS_Dcm_00008] On reception of a UDS Service 0x19 request with subfunction
				 * 		0x02, 0x0F and 0x13 and if the result of the bitwise AND operation between
				 * 		the DTCStatusMask received within the request message and the
				 * 		DTCStatusAvailabilityMask reported by the DEM is equal to 0, the Dcm module
				 * 		shall answer positively with 0 DTC.
				 */
#if((STD_ON == DCM_UDS0x19_SUB0x0A_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x15_ENABLE))
				if(((boolean)FALSE == maskCheckFlag) || (0u != (u8DTCStatusMask & u8AvaDTCStatusMask)))
#else
				if(0u != (u8DTCStatusMask & u8AvaDTCStatusMask))
#endif /* #if((STD_ON == DCM_UDS0x19_SUB0x0A_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x15_ENABLE)) */
				{
					flag = (boolean)TRUE;
				}
				else
				{
					result = (Std_ReturnType)E_OK;
				}
			}
		}
	}
	else
	{
		flag = (boolean)TRUE;
	}

	if((boolean)TRUE == flag)
	{
		if(DCM_CHECK_BIT_SET(Dcm_UDS0x19Status.PendStep, DCM_DEM_GETNUMBEROFFILTEREDDTC_PENDING_BIT, uint16))
		{
			u8Ret = Dem_DcmGetNumberOfFilteredDTC(&Dcm_UDS0x19Status.RemainDTCNum);

			if((uint8)DEM_NUMBER_OK == u8Ret)
			{
				if(pMsgContext->ResMaxDataLen >= (((uint32)Dcm_UDS0x19Status.RemainDTCNum * 4u) + pMsgContext->ResDataLen))
				{
					DCM_BIT_CLEAR(Dcm_UDS0x19Status.PendStep, DCM_DEM_GETNUMBEROFFILTEREDDTC_PENDING_BIT, uint16);
				}
				else
				{
					*pErrorCode = DCM_E_RESPONSETOOLONG;

					flag = (boolean)FALSE;
				}
			}
			else
			{
				/**
				 * @req [SWS_Dcm_01239] If Dem_DcmGetNumberOfFilteredDTC() returns DEM_NUMBER_PENDING,
				 * 		the Dcm shall call again Dem_DcmGetNumberOfFilteredDTC() API in next
				 * 		Dcm_MainFunction() call.
				 */
				if((uint8)DEM_NUMBER_PENDING == u8Ret)
				{
					result = (Std_ReturnType)DCM_E_PENDING;
				}

				flag = (boolean)FALSE;
			}
		}

		if(((boolean)TRUE == flag) && (DCM_CHECK_BIT_SET(Dcm_UDS0x19Status.PendStep, DCM_DEM_GETNEXTFILTEREDDTC_PENDING_BIT, uint16)))
		{
			/**
			 * @req [SWS_Dcm_00828] In case of paged buffer support is disabled, the Dcm module shall
			 * 		not insert zero-padded DTCs to the response of UDS Service 0x19 with subfunctions
			 * 		0x02, 0x0A, 0x0F, 0x13, 0x15 or 0x17.
			 */
			do{
				u8Ret = Dem_DcmGetNextFilteredDTC(&u32DTC, &u8DTCStatus);

				if(((uint8)DEM_FILTERED_OK == u8Ret) && (0u != Dcm_UDS0x19Status.RemainDTCNum))
				{
					pMsgContext->ResData[pMsgContext->ResDataLen] = (uint8)(u32DTC >> 16u);
					pMsgContext->ResDataLen++;
					pMsgContext->ResData[pMsgContext->ResDataLen] = (uint8)(u32DTC >> 8u);
					pMsgContext->ResDataLen++;
					pMsgContext->ResData[pMsgContext->ResDataLen] = (uint8)u32DTC;
					pMsgContext->ResDataLen++;
					pMsgContext->ResData[pMsgContext->ResDataLen] = u8DTCStatus;
					pMsgContext->ResDataLen++;

					Dcm_UDS0x19Status.RemainDTCNum--;
				}
				/**
				 * @req [SWS_Dcm_01229] If Dem_DcmGetNextFilteredDTC() returns
				 * 		DEM_FILTERED_NO_MATCHING_ELEMENT and at least one matching element could be
				 * 		retrieved before, the Dcm shall send a positive response including these data
				 * 		elements.
				 *
				 * @req [SWS_Dcm_01230] If Dem_DcmGetNextFilteredDTC() returns
				 * 		DEM_FILTERED_NO_MATCHING_ELEMENT and at no matching element could be retrieved
				 * 		before, the Dcm shall send a positive response only for service and subservice
				 * 		and additional parameters required within a positive response.
				 */
				else if((uint8)DEM_FILTERED_NO_MATCHING_ELEMENT == u8Ret)
				{
					result = (Std_ReturnType)E_OK;

					break;
				}
				/**
				 * @req [SWS_Dcm_01231] If Dem_DcmGetNextFilteredDTC() returns DEM_FILTERED_PENDING, the
				 * 		Dcm shall call again Dem_DcmGetNextFilteredDTC() API in next Dcm_MainFunction()
				 * 		call.
				 */
				else if((uint8)DEM_FILTERED_PENDING == u8Ret)
				{
					result = (Std_ReturnType)DCM_E_PENDING;
				}
				else
				{
					/* Nothing to do here. */
					;
				}
			}while((uint8)DEM_FILTERED_OK == u8Ret);
		}
	}

	return result;
}
#endif /* #if((STD_ON == DCM_UDS0x19_SUB0x02_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x0A_ENABLE) ||\
			  (STD_ON == DCM_UDS0x19_SUB0x0F_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x13_ENABLE) ||\
			  (STD_ON == DCM_UDS0x19_SUB0x15_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x17_ENABLE)) */

#if(STD_ON == DCM_UDS0x19_SUB0x08_ENABLE)
/**
 * @brief			Dcm_UDS0x19ReprotDTCBySMaskHandle
 * @details			Service 0x19 subfunction processing interface, used to retrieve the DTCs by Mask.
 *
 * @param[in]		u8ClientId:Client identifier.
 * @param[in]		opState:Operating state.
 * @param[in]		pMsgContext:Message-related information for one diagnostic protocol identifier.
 * 					The pointers in pMsgContext shall point behind the SID.
 *
 * @param[out]		pErrorCode:If the called external interface returns E_NOT_OK, use this pointer to
 * 					output the NRC.
 *
 * @return        	Result of this operation.
 * @retval			E_OK:Processing successful.
 * @retval			E_NOT_OK:Processing failure.
 */
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x19ReprotDTCBySMaskHandle
(
	Dcm_OpStatusType opState,
	P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
)
{
	/* Sub: 0x08. */

	/**
	 * @req [SWS_Dcm_00379] When sending a positive response to UDS Service 0x19 with subfunction 0x08,
	 * 		the DCM module shall use the following data in the response message.
	 */

	Std_ReturnType result = (Std_ReturnType)E_NOT_OK;

	uint8 u8DTCUnit;
	uint8 u8DTCStatus;
	uint8 u8DTCStatusMask;
	uint8 u8DTCSeverityMask;
	uint32 u32DTC;
	uint8 u8Ret = (uint8)E_NOT_OK;
	boolean flag = (boolean)FALSE;
	Dem_DTCSeverityType dtcSeverity;

	if(DCM_PENDING != opState)
	{
		if(4u != pMsgContext->ReqDataLen)
		{
			*pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
		}
		else
		{
			u8DTCSeverityMask = pMsgContext->ReqData[3];
			u8DTCStatusMask = pMsgContext->ReqData[4];

			if((0u == u8DTCStatusMask) || (0u == u8DTCSeverityMask))
			{
				/**
				 * @req [SWS_Dcm_00700] When the Dcm module receives a request with the DTCStatusMask
				 * 		set to 0x00, it shall send positive response and shall not use the Dem interface
				 * 		Dem_DcmSetDTCFilter().
				 *
				 * @req [SWS_Dcm_01160] When the Dcm module receives a request with the DTCSeverityMask
				 * 		set to 0x00, it shall send a positive response as specified in ISO14229 and
				 * 		shall not use the Dem interface Dem_SetDTCFilter().
				 */
				pMsgContext->ResData[pMsgContext->ResDataLen++] = 0u;

				result = (Std_ReturnType)E_OK;
			}
			else
			{
				/**
				 * @req [SWS_Dcm_00380] When responding to UDS Service 0x19 with subfunction 0x08, the
				 * 		DCM module shall obtain the DTCAndSeverityRecords by repeatedly calling
				 * 		Dem_DcmGetNextFilteredDTCAndSeverity() after having configured the filter with
				 * 		Dem_DcmSetDTCFilter() using the parameter values of the following table.
				 *
				 * @req [SWS_Dcm_00835] The Dcm shall call Dem_DcmSetDTCFilter prior to
				 * 		Dem_DcmGetNumberOfFilteredDTC, any sequence of Dem_DcmGetNextFilteredDTC,
				 * 		any sequence of Dem_DcmGetNextFilteredDTCAndFDC, as well as any sequence of
				 * 		Dem_DcmGetNextFilteredDTCAndSeverity.
				 *
				 * @req [SWS_Dcm_01255] If Dem_DcmSetDTCFilter() returns DEM_WRONG_FILTER, the Dcm shall
				 * 		send a NRC 0x31 (Request out of Range).
				 */
				u8Ret = Dem_DcmSetDTCFilter(\
							u8DTCStatusMask, DEM_DTC_KIND_ALL_DTCS, DEM_DTC_FORMAT_UDS,\
							DEM_DTC_ORIGIN_PRIMARY_MEMORY, (boolean)TRUE, u8DTCSeverityMask,\
							(boolean)FALSE\
							);
				/**
				 * @req [SWS_Dcm_00007] The Dcm module shall retrieve the DTCStatusAvailabilityMask by
				 * 		using the function Dem_DcmGetDTCStatusAvailabilityMask().
				 */
				u8Ret |= Dem_DcmGetDTCStatusAvailabilityMask(&u8DTCStatusMask);

				if((uint8)E_OK == u8Ret)
				{
					pMsgContext->ResData[pMsgContext->ResDataLen] = u8DTCStatusMask;
					pMsgContext->ResDataLen++;

					flag = (boolean)TRUE;
				}
			}
		}
	}
	else
	{
		flag = (boolean)TRUE;
	}

	if((boolean)TRUE == flag)
	{
		if(DCM_CHECK_BIT_SET(Dcm_UDS0x19Status.PendStep, DCM_DEM_GETNUMBEROFFILTEREDDTC_PENDING_BIT, uint16))
		{
			u8Ret = Dem_DcmGetNumberOfFilteredDTC(&Dcm_UDS0x19Status.RemainDTCNum);

			if((uint8)DEM_NUMBER_OK == u8Ret)
			{
				if(pMsgContext->ResMaxDataLen >= (((uint32)Dcm_UDS0x19Status.RemainDTCNum * 4u) + pMsgContext->ResDataLen))
				{
					DCM_BIT_CLEAR(Dcm_UDS0x19Status.PendStep, DCM_DEM_GETNUMBEROFFILTEREDDTC_PENDING_BIT, uint16);
				}
				else
				{
					*pErrorCode = DCM_E_RESPONSETOOLONG;

					flag = (boolean)FALSE;
				}
			}
			else
			{
				/**
				 * @req [SWS_Dcm_01239] If Dem_DcmGetNumberOfFilteredDTC() returns DEM_NUMBER_PENDING,
				 * 		the Dcm shall call again Dem_DcmGetNumberOfFilteredDTC() API in next
				 * 		Dcm_MainFunction() call.
				 */
				if((uint8)DEM_NUMBER_PENDING == u8Ret)
				{
					result = (Std_ReturnType)DCM_E_PENDING;
				}

				flag = (boolean)FALSE;
			}
		}

		if(((boolean)TRUE == flag) && (DCM_CHECK_BIT_SET(Dcm_UDS0x19Status.PendStep, DCM_DEM_GETNEXTFILTEREDDTCANDSEVERITY_PENDING_BIT, uint16)))
		{
			do{
				u8Ret = Dem_DcmGetNextFilteredDTCAndSeverity(&u32DTC, &u8DTCStatus, &dtcSeverity, &u8DTCUnit);

				if(((uint8)DEM_FILTERED_OK == u8Ret) && (0u != Dcm_UDS0x19Status.RemainDTCNum))
				{
					pMsgContext->ResData[pMsgContext->ResDataLen++] = dtcSeverity;
					pMsgContext->ResData[pMsgContext->ResDataLen++] = u8DTCUnit;
					pMsgContext->ResData[pMsgContext->ResDataLen++] = (uint8)(u32DTC >> 16u);
					pMsgContext->ResData[pMsgContext->ResDataLen++] = (uint8)(u32DTC >> 8u);
					pMsgContext->ResData[pMsgContext->ResDataLen++] = (uint8)u32DTC;
					pMsgContext->ResData[pMsgContext->ResDataLen++] = u8DTCStatus;

					Dcm_UDS0x19Status.RemainDTCNum--;
				}
				/**
				 * @req [SWS_Dcm_01234] If Dem_DcmGetNextFilteredDTCAndSeverity() returns
				 * 		DEM_FILTERED_NO_MATCHING_ELEMENT and at least one matching element could be
				 * 		retrieved before, the Dcm shall send a positive response including these data
				 * 		elements.
				 *
				 * @req [SWS_Dcm_01235] If Dem_DcmGetNextFilteredDTCAndSeverity() returns
				 * 		DEM_FILTERED_NO_MATCHING_ELEMENT and no matching element could be retrieved
				 * 		before, the Dcm shall send a positive response only for service, subservice and
				 * 		mandatory data specified in ISO 14229.
				 */
				else if((uint8)DEM_FILTERED_NO_MATCHING_ELEMENT == u8Ret)
				{
					result = (Std_ReturnType)E_OK;

					break;
				}
				/**
				 * @req [SWS_Dcm_01236] If Dem_DcmGetNextFilteredDTCAndSeverity() returns
				 * 		DEM_FILTERED_PENDING, the Dcm shall call again
				 * 		Dem_DcmGetNextFilteredDTCAndSeverity() API in next Dcm_MainFunction() call.
				 */
				else if((uint8)DEM_FILTERED_PENDING == u8Ret)
				{
					result = (Std_ReturnType)DCM_E_PENDING;
				}
				else
				{
					/* Nothing to do here. */
					;
				}
			}while((uint8)DEM_FILTERED_OK == u8Ret);
		}
	}

	return result;
}
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x08_ENABLE) */

#if(STD_ON == DCM_UDS0x19_SUB0x09_ENABLE)
/**
 * @brief			Dcm_UDS0x19ReportSInfoOfDTCHandle
 * @details			Service 0x19 subfunction processing interface, used to retrieve the SInfo of DTCs.
 *
 * @param[in]		u8ClientId:Client identifier.
 * @param[in]		opState:Operating state.
 * @param[in]		pMsgContext:Message-related information for one diagnostic protocol identifier.
 * 					The pointers in pMsgContext shall point behind the SID.
 *
 * @param[out]		pErrorCode:If the called external interface returns E_NOT_OK, use this pointer to
 * 					output the NRC.
 *
 * @return        	Result of this operation.
 * @retval			E_OK:Processing successful.
 * @retval			E_NOT_OK:Processing failure.
 */
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x19ReportSInfoOfDTCHandle
(
	Dcm_OpStatusType opState,
	P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
)
{
	/* Sub: 0x09. */

	/**
	 * @req [SWS_Dcm_00381] When sending a positive response to UDS Service 0x19 with subfunction 0x09,
	 * 		the DCM module shall use the following data in the response message.
	 */

	Std_ReturnType result = (Std_ReturnType)E_NOT_OK;

	uint8 u8DTCUnit;
	uint8 u8DTCStatus;
	uint8 u8DTCStatusMask;
	uint32 u32DTC;
	uint8 u8Ret = (uint8)E_NOT_OK;
	boolean flag = (boolean)FALSE;
	Dem_DTCSeverityType dtcSeverity;

	u32DTC = ((uint32)pMsgContext->ReqData[2] << 16u);
	u32DTC |= ((uint32)pMsgContext->ReqData[3] << 8u);
	u32DTC |= (uint32)pMsgContext->ReqData[4];

	if(DCM_PENDING != opState)
	{
		if(5u != pMsgContext->ReqDataLen)
		{
			*pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
		}
		else
		{
			/**
			 * @req [SWS_Dcm_00007] The Dcm module shall retrieve the DTCStatusAvailabilityMask by using
			 * 		the function Dem_DcmGetDTCStatusAvailabilityMask().
			 */
			u8Ret = Dem_DcmGetDTCStatusAvailabilityMask(&u8DTCStatusMask);

			if((uint8)E_OK == u8Ret)
			{
				pMsgContext->ResData[pMsgContext->ResDataLen++] = u8DTCStatusMask;

				flag = (boolean)TRUE;
			}
		}
	}
	else
	{
		flag = (boolean)TRUE;
	}

	if((boolean)TRUE == flag)
	{
		if(DCM_CHECK_BIT_SET(Dcm_UDS0x19Status.PendStep, DCM_DEM_GETSEVERITYOFDTC_PENDING_BIT, uint16))
		{
			u8Ret = Dem_DcmGetSeverityOfDTC(u32DTC, &dtcSeverity);

			if((uint8)DEM_GET_SEVERITYOFDTC_OK == u8Ret)
			{
				pMsgContext->ResData[pMsgContext->ResDataLen] = dtcSeverity;
				pMsgContext->ResDataLen++;

				DCM_BIT_CLEAR(Dcm_UDS0x19Status.PendStep, DCM_DEM_GETSEVERITYOFDTC_PENDING_BIT, uint16);
			}
			/**
			 * @req [SWS_Dcm_01241] If Dem_DcmGetSeverityOfDTC() returns DEM_GET_SEVERITYOFDTC_PENDING,
			 * 		the Dcm shall call again Dem_DcmGetSeverityOfDTC() API in next Dcm_MainFunction()
			 * 		call.
			 */
			else if((uint8)DEM_GET_SEVERITYOFDTC_PENDING == u8Ret)
			{
				result = (Std_ReturnType)DCM_E_PENDING;
			}
			/**
			 * @req [SWS_Dcm_01240] If Dem_DcmGetSeverityOfDTC() returns
			 * 		DEM_GET_SEVERITYOFDTC_WRONG_DTC, the Dcm shall send a NRC 0x31 (Request out of
			 * 		Range).
			 */
			else
			{
				flag = (boolean)FALSE;
			}
		}

		if(((boolean)TRUE == flag) && (DCM_CHECK_BIT_SET(Dcm_UDS0x19Status.PendStep, DCM_DEM_GETFUNCTIONALUNITOFDTC_PENDING_BIT, uint16)))
		{
			u8Ret = Dem_DcmGetFunctionalUnitOfDTC(u32DTC, &u8DTCUnit);

			if((uint8)DEM_GET_FUNCTIONALUNITOFDTC_OK == u8Ret)
			{
				pMsgContext->ResData[pMsgContext->ResDataLen] = u8DTCUnit;
				pMsgContext->ResDataLen++;
				pMsgContext->ResData[pMsgContext->ResDataLen] = (uint8)(u32DTC >> 16u);
				pMsgContext->ResDataLen++;
				pMsgContext->ResData[pMsgContext->ResDataLen] = (uint8)(u32DTC >> 8u);
				pMsgContext->ResDataLen++;
				pMsgContext->ResData[pMsgContext->ResDataLen] = (uint8)u32DTC;
				pMsgContext->ResDataLen++;

				DCM_BIT_CLEAR(Dcm_UDS0x19Status.PendStep, DCM_DEM_GETFUNCTIONALUNITOFDTC_PENDING_BIT, uint16);
			}
			/**
			 * @req [SWS_Dcm_01226] If Dem_DcmGetFunctionalUnitOfDTC() returns
			 * 		DEM_GET_FUNCTIONALUNITOFDTC_WRONG_DTC, the Dcm shall send a NRC 0x31 (Request out of
			 * 		Range).
			 */
			else
			{
				flag = (boolean)FALSE;
			}
		}

		if(((boolean)TRUE == flag) && (DCM_CHECK_BIT_SET(Dcm_UDS0x19Status.PendStep, DCM_DEM_GETSTATUSOFDTC_PENDING_BIT, uint16)))
		{
			if(9u <= pMsgContext->ResMaxDataLen)
			{
				u8Ret = Dem_DcmGetStatusOfDTC(u32DTC, DEM_DTC_ORIGIN_PRIMARY_MEMORY, &u8DTCStatus);

				if((uint8)DEM_STATUS_OK == u8Ret)
				{
					pMsgContext->ResData[pMsgContext->ResDataLen] = u8DTCStatus;
					pMsgContext->ResDataLen++;
				}
				else if((uint8)DEM_STATUS_PENDING == u8Ret)
				{
					result = (Std_ReturnType)DCM_E_PENDING;
				}
				/**
				 * @req [SWS_Dcm_01250] If Dem_DcmGetStatusOfDTC() returns DEM_STATUS_WRONG_DTC, the Dcm
				 * 		shall send a NRC 0x31 (Request out of Range).
				 *
				 * @req [SWS_Dcm_01251] If Dem_DcmGetStatusOfDTC() returns DEM_STATUS_WRONG_DTCORIGIN,
				 * 		the Dcm shall send a NRC 0x31 (Request out of Range).
				 */
				else
				{
					;
				}
			}
			else
			{
				*pErrorCode = DCM_E_RESPONSETOOLONG;

				result = (Std_ReturnType)E_NOT_OK;
			}
		}
	}

	return result;
}
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x09_ENABLE) */

#if((STD_ON == DCM_UDS0x19_SUB0x06_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x10_ENABLE) ||\
	(STD_ON == DCM_UDS0x19_SUB0x19_ENABLE))
/**
 * @brief			Dcm_UDS0x19ReportExtDataRecordHandle
 * @details			Service 0x19 subfunction processing interface, used to retrieve the ExtDataRecode.
 *
 * @param[in]		u8ClientId:Client identifier.
 * @param[in]		u8SubServiceId:Sub function identifier.
 * @param[in]		opState:Operating state.
 * @param[in]		pMsgContext:Message-related information for one diagnostic protocol identifier.
 * 					The pointers in pMsgContext shall point behind the SID.
 *
 * @param[out]		pErrorCode:If the called external interface returns E_NOT_OK, use this pointer to
 * 					output the NRC.
 *
 * @return        	Result of this operation.
 * @retval			E_OK:Processing successful.
 * @retval			E_NOT_OK:Processing failure.
 */
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x19ReportExtDataRecordHandle
(
	uint8 u8SubServiceId,
	Dcm_OpStatusType opState,
	P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
)
{
	/* Sub: 0x06, 0x10, 0x19. */

	/**
	 * @req [SWS_Dcm_00297] When sending a positive response to UDS Service 0x19 with subfunction 0x06,
	 * 		0x10 or 0x19 and DTCExtendedDataRecordNumber=0xFF, the Dcm module shall use the following
	 * 		data in the response message.
	 *
	 * @req [SWS_Dcm_00474] When sending a positive response to UDS Service 0x19 with subfunction 0x06,
	 * 		0x10 or0x19 and DTCExtendedDataRecordNumber=0xFE, the Dcm module shall use the following
	 * 		data in the response message.
	 *
	 * @req [SWS_Dcm_00386] When sending a positive response to UDS Service 0x19 with subfunction 0x06,
	 * 		0x10 or 0x19 and DTCExtendedDataRecordNumber different from 0xFF or 0xFE, the Dcm module
	 * 		shall use the following data in the response message.
	 */

	Std_ReturnType result = (Std_ReturnType)E_NOT_OK;

	uint8 u8Ret;
	uint8 u8LoopNum = 0u;
	uint8 u8DTCStatus;
	uint8 u8RecordNumber;
	uint16 u16DataSize = Dcm_UDS0x19Status.RemainDataSize;
	uint32 u32DTC;
	boolean flag = (boolean)FALSE;

	if(DCM_PENDING != opState)
	{
		if(Dcm_UDS0x19GetReqMsgLen(u8SubServiceId) != pMsgContext->ReqDataLen)
		{
			*pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
		}
		else
		{
			u32DTC = ((uint32)pMsgContext->ReqData[2] << 16u);
			u32DTC |= ((uint32)pMsgContext->ReqData[3] << 8u);
			u32DTC |= (uint32)pMsgContext->ReqData[4];
			u8RecordNumber = pMsgContext->ReqData[5];

			Dcm_UDS0x19Status.DTC = u32DTC;

			if((0xFFu == u8RecordNumber) || (0xFEu == u8RecordNumber))
			{
				Dcm_UDS0x19Status.SingleRecordNum = (boolean)FALSE;
			}
			Dcm_UDS0x19Status.RecordNum = u8RecordNumber;

#if(STD_ON == DCM_UDS0x19_SUB0x19_ENABLE)
			Dcm_UDS0x19Status.DTCOrigin = Dcm_UDS0x19GetDTCOrigin(u8SubServiceId, pMsgContext);

			if(0x19u == u8SubServiceId)
			{
				pMsgContext->ResData[2] = pMsgContext->ReqData[6];

				pMsgContext->ResDataLen++;
			}
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x19_ENABLE) */

			pMsgContext->ResData[pMsgContext->ResDataLen] = pMsgContext->ReqData[2];
			pMsgContext->ResDataLen++;
			pMsgContext->ResData[pMsgContext->ResDataLen] = pMsgContext->ReqData[3];
			pMsgContext->ResDataLen++;
			pMsgContext->ResData[pMsgContext->ResDataLen] = pMsgContext->ReqData[4];
			pMsgContext->ResDataLen++;

			flag = (boolean)TRUE;
		}
	}
	else
	{
		flag = (boolean)TRUE;
	}

	if((boolean)TRUE == flag)
	{
		if(DCM_CHECK_BIT_SET(Dcm_UDS0x19Status.PendStep, DCM_DEM_GETSTATUSOFDTC_PENDING_BIT, uint16))
		{
			/**
			 * @req [SWS_Dcm_00295] When responding to UDS Service 0x19 with subfunction 0x06,
			 * 		0x10 or 0x19, the Dcm module shall calculate the statusOfDTC by calling
			 * 		Dem_DcmGetStatusOfDTC() with the following parameters.
			 *
			 * @req [SWS_Dcm_00475] When responding to UDS Service 0x19 with subfunction 0x06,
			 * 		0x10 or 0x19, the Dcm module shall calculate the statusOfDTC by calling
			 * 		Dem_DcmGetStatusOfDTC() with the following parameters.
			 */
#if(STD_ON == DCM_UDS0x19_SUB0x19_ENABLE)
			u8Ret = Dem_DcmGetStatusOfDTC(Dcm_UDS0x19Status.DTC, Dcm_UDS0x19Status.DTCOrigin, &u8DTCStatus);
#else
			u8Ret = Dem_DcmGetStatusOfDTC(Dcm_UDS0x19Status.DTC, DEM_DTC_ORIGIN_PRIMARY_MEMORY, &u8DTCStatus);
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x19_ENABLE) */

			if((uint8)DEM_STATUS_OK == u8Ret)
			{
				pMsgContext->ResData[pMsgContext->ResDataLen] = u8DTCStatus;
				pMsgContext->ResDataLen++;

				DCM_BIT_CLEAR(Dcm_UDS0x19Status.PendStep, DCM_DEM_GETSTATUSOFDTC_PENDING_BIT, uint16);
			}
			else
			{
				if((uint8)DEM_STATUS_PENDING == u8Ret)
				{
					result = (Std_ReturnType)DCM_E_PENDING;
				}

				flag = (boolean)FALSE;
			}
		}

		/**
		 * @req [SWS_Dcm_00371] To avoid updating data values while reading out extended data records,
		 * 		the DCM module shall call the following API sequence: first lock updates by calling
		 * 		Dem_DcmDisableDTCRecordUpdate() (which is an exclusive area function concerning to
		 * 		SWS_BSW_00434) then call Dem_DcmGetSizeOfExtendedDataRecordByDTC(), then
		 * 		Dem_DcmGetExtendedDataRecordByDTC(RecNum) and finally shall re-enable updates by calling
		 * 		Dem_DcmEnableDTCRecordUpdate().
		 */
		if(((boolean)TRUE == flag) && (DCM_CHECK_BIT_SET(Dcm_UDS0x19Status.PendStep, DCM_DEM_DISABLEDTCRECORDUPDATE_PENDING_BIT, uint16)))
		{
#if(STD_ON == DCM_UDS0x19_SUB0x19_ENABLE)
			u8Ret = Dem_DcmDisableDTCRecordUpdate(Dcm_UDS0x19Status.DTC, Dcm_UDS0x19Status.DTCOrigin);
#else
			u8Ret = Dem_DcmDisableDTCRecordUpdate(Dcm_UDS0x19Status.DTC, DEM_DTC_ORIGIN_PRIMARY_MEMORY);
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x19_ENABLE) */

			if((uint8)DEM_DISABLE_DTCRECUP_OK == u8Ret)
			{
				Dcm_UDS0x19Status.DisableDTCUpdate = (boolean)TRUE;

				DCM_BIT_CLEAR(Dcm_UDS0x19Status.PendStep, DCM_DEM_DISABLEDTCRECORDUPDATE_PENDING_BIT, uint16);
			}
			else
			{
				/**
				 * @req [SWS_Dcm_00702] If function Dem_DcmDisableDTCRecordUpdate() returns
				 * 		DEM_DISABLE_DTCRECUP_PENDING, the DCM shall retry to get the lock in the next
				 * 		Dcm_MainFunction().
				 */
				if((uint8)DEM_DISABLE_DTCRECUP_PENDING == u8Ret)
				{
					result = (Std_ReturnType)DCM_E_PENDING;
				}

				/**
				 * @req [SWS_Dcm_01212] If Dem_DcmDisableDTCRecordUpdate() returns
				 * 		DEM_DISABLE_DTCRECUP_WRONG_DTC, the Dcm shall send a NRC 0x31 (Request out of
				 * 		Range).
				 *
				 * @req [SWS_Dcm_01213] If Dem_DcmDisableDTCRecordUpdate() returns
				 * 		DEM_DISABLE_DTCRECUP_WRONG_DTCORIGIN, the Dcm shall send a NRC 0x31 (Request out
				 * 		of Range).
				 */
				flag = (boolean)FALSE;
			}
		}

		if(((boolean)TRUE == flag) && (DCM_CHECK_BIT_SET(Dcm_UDS0x19Status.PendStep, DCM_DEM_GETSIZEOFEXTENDEDDATARECORDSELECTION_PENDING_BIT, uint16)))
		{
			if((boolean)FALSE == Dcm_UDS0x19Status.SingleRecordNum)
			{
				if((uint8)0xFE == Dcm_UDS0x19Status.RecordNum)
				{
					Dcm_UDS0x19Status.RecordNum = 0x90u;
					u8RecordNumber = 0xFEu;
				}
				else
				{
					Dcm_UDS0x19Status.RecordNum = 0x01u;
					u8RecordNumber = 0xFFu;
				}
			}
			else
			{
				u8RecordNumber = Dcm_UDS0x19Status.RecordNum;
			}

			/**
			 * @req [SWS_Dcm_00478] The DCM module shall obtain the size of the data returned by DEM
			 * 		in Dem_DcmGetExtendedDataRecordByDTC() call by using
			 * 		Dem_DcmGetSizeOfExtendedDataRecordByDTC().
			 */
#if(STD_ON == DCM_UDS0x19_SUB0x19_ENABLE)
			u8Ret = Dem_DcmGetSizeOfExtendedDataRecordByDTC(\
						Dcm_UDS0x19Status.DTC, Dcm_UDS0x19Status.DTCOrigin, u8RecordNumber, &u16DataSize\
						);
#else
			u8Ret = Dem_DcmGetSizeOfExtendedDataRecordByDTC(\
						Dcm_UDS0x19Status.DTC, DEM_DTC_ORIGIN_PRIMARY_MEMORY, u8RecordNumber, &u16DataSize\
						);
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x19_ENABLE) */

			if((uint8)DEM_GETSIZEBYDTC_OK == u8Ret)
			{
				if(pMsgContext->ResMaxDataLen >= (u16DataSize + pMsgContext->ResDataLen))
				{
					Dcm_UDS0x19Status.RemainDataSize = u16DataSize;

					DCM_BIT_CLEAR(Dcm_UDS0x19Status.PendStep, DCM_DEM_GETSIZEOFEXTENDEDDATARECORDSELECTION_PENDING_BIT, uint16);
				}
				else
				{
					*pErrorCode = DCM_E_RESPONSETOOLONG;

					flag = (boolean)FALSE;
				}
			}
			else
			{
				/**
				 * @req [SWS_Dcm_01245] If Dem_DcmGetSizeOfExtendedDataRecordByDTC() returns
				 * 		DEM_GETSIZEBYDTC_PENDING, the Dcm shall call again
				 * 		Dem_DcmGetSizeOfExtendedDataRecordByDTC() API in next Dcm_MainFunction() call.
				 */
				if((uint8)DEM_GETSIZEBYDTC_PENDING == u8Ret)
				{
					result = (Std_ReturnType)DCM_E_PENDING;
				}

				/**
				 * @req [SWS_Dcm_01242] If Dem_DcmGetSizeOfExtendedDataRecordByDTC() returns
				 * 		DEM_GETSIZEBYDTC_WRONG_DTC, the Dcm shall send a NRC 0x31 (Request out of
				 * 		Range).
				 *
				 * @req [SWS_Dcm_01243] If Dem_DcmGetSizeOfExtendedDataRecordByDTC() returns
				 * 		DEM_GETSIZEBYDTC_WRONG_DTCORIGIN, the Dcm shall send a NRC 0x31 (Request out of
				 * 		Range).
				 *
				 * @req [SWS_Dcm_01244] If Dem_DcmGetSizeOfExtendedDataRecordByDTC() returns
				 * 		DEM_GETSIZEBYDTC_WRONG_RECNUM, the Dcm shall send a NRC 0x31 (Request out of
				 * 		Range).
				 */
				flag = (boolean)FALSE;
			}
		}

		if(((boolean)TRUE == flag) && (DCM_CHECK_BIT_SET(Dcm_UDS0x19Status.PendStep, DCM_DEM_GETNEXTEXTENDEDDATARECORD_PENDING_BIT, uint16)))
		{
			if((boolean)FALSE == Dcm_UDS0x19Status.SingleRecordNum)
			{
				u8LoopNum = (uint8)(0xEFu + 1u);
			}
			else
			{
				u8LoopNum = (uint8)(Dcm_UDS0x19Status.RecordNum + 1u);
			}

			do
			{
				/**
				 * @req [SWS_Dcm_00296] When responding to UDS Service 0x19 with subfunction 0x06, 0x10
				 * 		or 0x19, the Dcm module shall assemble the ExtendedDataRecords by calling
				 * 		Dem_DcmGetExtendedDataRecordByDTC() repeatedly (only If
				 * 		Dem_DcmGetExtendedDataRecordByDTC() returns DEM_RECORD_OK and BufSize different
				 * 		from 0 (not empty buffer) (where ExtendedDataNumber goes from 0x01 to 0xEF) with
				 * 		the following parameter values.
				 *
				 * @req [SWS_Dcm_00476] When responding to UDS Service 0x19 with subfunction 0x06, 0x10
				 * 		or 0x19, the Dcm module shall assemble the ExtendedDataRecords by calling
				 * 		Dem_DcmGetExtendedDataRecordByDTC() repeatedly (only If
				 * 		Dem_DcmGetExtendedDataRecordByDTC() returns DEM_RECORD_OK and BufSize different
				 * 		from 0 (not empty buffer) (where ExtendedDataNumber goes from 0x90 to 0xEF) with
				 * 		the following parameter values.
				 *
				 * @req [SWS_Dcm_00382] When responding to UDS Service 0x19 with subfunction 0x06, 0x10
				 * 		or 0x19 and DTCExtendedDataRecordNumber different from 0xFF or 0xFE, the Dcm
				 * 		module shall calculate the DTCExtendedDataRecord from
				 * 		Dem_DcmGetExtendedDataRecordByDTC() with the following parameter values.
				 */
#if(STD_ON == DCM_UDS0x19_SUB0x19_ENABLE)
				u8Ret = Dem_DcmGetExtendedDataRecordByDTC(\
							Dcm_UDS0x19Status.DTC, Dcm_UDS0x19Status.DTCOrigin, Dcm_UDS0x19Status.RecordNum,\
							&pMsgContext->ResData[(pMsgContext->ResDataLen + 1u)], &u16DataSize\
							);
#else
				u8Ret = Dem_DcmGetExtendedDataRecordByDTC(\
							Dcm_UDS0x19Status.DTC, DEM_DTC_ORIGIN_PRIMARY_MEMORY, Dcm_UDS0x19Status.RecordNum,\
							&pMsgContext->ResData[(pMsgContext->ResDataLen + 1u)], &u16DataSize\
							);
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x19_ENABLE) */

				if((uint8)DEM_RECORD_OK == u8Ret)
				{
					/**
					 * @req [SWS_Dcm_00841] If Dem_DcmGetExtendedDataRecordByDTC returns DEM_RECORD_OK
					 * 		and BufSize 0 (empty buffer), the Dcm module shall omit the
					 * 		DTCExtendedDataRecordNumber for the related record in the response of service
					 * 		0x19 0x06/0x10/0x19.
					 */
					if(0u != u16DataSize)
					{
						pMsgContext->ResData[pMsgContext->ResDataLen] = Dcm_UDS0x19Status.RecordNum;

						pMsgContext->ResDataLen += ((uint32)u16DataSize + 1u);

						Dcm_UDS0x19Status.RemainDataSize -= u16DataSize;

						u16DataSize = Dcm_UDS0x19Status.RemainDataSize;
					}

					result = (Std_ReturnType)E_OK;
				}
				/**
				 * @req [SWS_Dcm_01217] If Dem_DcmGetExtendedDataRecordByDTC() returns
				 * 		DEM_RECORD_WRONG_NUMBER and if multiple Extended Data Record is requested, the
				 * 		Dcm shall proceed with the next record.
				 */
				else if(((uint8)DEM_RECORD_WRONG_NUMBER == u8Ret) && ((boolean)FALSE == Dcm_UDS0x19Status.SingleRecordNum))
				{
					/* Nothing to do here. */
					;
				}
				else
				{
					/**
					 * @req [SWS_Dcm_01219] If Dem_DcmGetExtendedDataRecordByDTC() returns
					 * 		DEM_RECORD_PENDING, the Dcm shall call again
					 * 		Dem_DcmGetExtendedDataRecordByDTC in next Dcm_MainFunction call.
					 */
					if((uint8)DEM_RECORD_PENDING == u8Ret)
					{
						result = (Std_ReturnType)DCM_E_PENDING;
					}
					/**
					 * @req [SWS_Dcm_01214] If Dem_DcmGetExtendedDataRecordByDTC() returns
					 * 		DEM_RECORD_WRONG_DTC, the Dcm shall send a NRC 0x31 (Request out of Range).
					 *
					 * @req [SWS_Dcm_01215] If Dem_DcmGetExtendedDataRecordByDTC() returns
					 * 		DEM_RECORD_WRONG_DTCORIGIN, the Dcm shall send a NRC 0x31 (Request out of
					 * 		Range).
					 *
					 * @req [SWS_Dcm_01216] If Dem_DcmGetExtendedDataRecordByDTC() returns
					 * 		DEM_RECORD_WRONG_NUMBER and if a single Extended Data Record is requested,
					 * 		the Dcm shall send a NRC 0x31 (Request out of Range).
					 */
					else
					{
						/* Nothing to do here. */
						;
					}

					break;
				}

				Dcm_UDS0x19Status.RecordNum++;

			}while(Dcm_UDS0x19Status.RecordNum < u8LoopNum);
		}
	}

	return result;
}
#endif /* #if((STD_ON == DCM_UDS0x19_SUB0x06_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x10_ENABLE) ||\
			  (STD_ON == DCM_UDS0x19_SUB0x19_ENABLE)) */

#if(STD_ON == DCM_UDS0x19_SUB0x03_ENABLE)
/**
 * @brief			Dcm_UDS0x19ReportDTCSnapshotIdentificationHandle
 * @details			Service 0x19 subfunction processing interface, used to retrieve the snapshot
 * 					identification.
 *
 * @param[in]		u8ClientId:Client identifier.
 * @param[in]		opState:Operating state.
 * @param[in]		pMsgContext:Message-related information for one diagnostic protocol identifier.
 * 					The pointers in pMsgContext shall point behind the SID.
 *
 * @param[out]		pErrorCode:If the called external interface returns E_NOT_OK, use this pointer to
 * 					output the NRC.
 *
 * @return        	Result of this operation.
 * @retval			E_OK:Processing successful.
 * @retval			E_NOT_OK:Processing failure.
 */
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x19ReportDTCSnapshotIdentificationHandle
(
	Dcm_OpStatusType opState,
	P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
)
{
	/* Sub: 0x03. */

	/**
	 * @req [SWS_Dcm_00300] When sending a positive response to UDS Service 0x19 with subfunction 0x03,
	 * 		the DCM module shall use the following data in the response message.
	 */

	Std_ReturnType result = (Std_ReturnType)E_NOT_OK;

	uint8 u8Ret;
	uint8 u8RecordNum;
	uint32 u32DTC;
	boolean flag = (boolean)FALSE;

	if(DCM_PENDING != opState)
	{
		if(2u != pMsgContext->ReqDataLen)
		{
			*pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
		}
		else
		{
			/**
			 * @req [SWS_Dcm_00298] The DSP submodule shall call Dem_DcmSetFreezeFrameRecordFilter()
			 * 		that returns the NumberOfFilteredRecords value with DTCFormat equal to
			 * 		DEM_DTC_FORMAT_UDS.
			 *
			 * @req [SWS_Dcm_01256] If Dem_DcmSetFreezeFrameRecordFilter() returns DEM_WRONG_FILTER,
			 * 		the Dcm shall send a NRC 0x31 (Request out of Range).
			 *
			 * @req [SWS_Dcm_00836] The Dcm shall call Dem_DcmSetFreezeFrameRecordFilter prior to any
			 * 		sequence of Dem_DcmGetNextFilteredRecord.
			 */
			u8Ret = Dem_DcmSetFreezeFrameRecordFilter(DEM_DTC_FORMAT_UDS, &Dcm_UDS0x19Status.RemainDTCNum);

			if((Std_ReturnType)DEM_FILTER_ACCEPTED == u8Ret)
			{
				if(pMsgContext->ResMaxDataLen >= (((uint32)Dcm_UDS0x19Status.RemainDTCNum * 4u) + pMsgContext->ResDataLen))
				{
					flag = (boolean)TRUE;
				}
				else
				{
					*pErrorCode = DCM_E_RESPONSETOOLONG;
				}
			}
		}
	}
	else
	{
		flag = (boolean)TRUE;
	}

	if((boolean)TRUE == flag)
	{
		if(DCM_CHECK_BIT_SET(Dcm_UDS0x19Status.PendStep, DCM_DEM_GETNEXTFILTEREDRECORD_PENDING_BIT, uint16))
		{
			/**
			 * @req [SWS_Dcm_00299] When responding to UDS Service 0x19 with subfunction 0x03, the DCM
			 * 		module shall obtain the consecutive DTCs and DTCSnapshotRecordNumbers by repeatedly
			 * 		calling Dem_DcmGetNextFilteredRecord().
			 */
			do{
				u8Ret = Dem_DcmGetNextFilteredRecord(&u32DTC, &u8RecordNum);

				if(((uint8)DEM_FILTERED_OK == u8Ret) && (0u != Dcm_UDS0x19Status.RemainDTCNum))
				{
					pMsgContext->ResData[pMsgContext->ResDataLen] = (uint8)(u32DTC >> 16u);
					pMsgContext->ResDataLen++;
					pMsgContext->ResData[pMsgContext->ResDataLen] = (uint8)(u32DTC >> 8u);
					pMsgContext->ResDataLen++;
					pMsgContext->ResData[pMsgContext->ResDataLen] = (uint8)u32DTC;
					pMsgContext->ResDataLen++;
					pMsgContext->ResData[pMsgContext->ResDataLen] = u8RecordNum;
					pMsgContext->ResDataLen++;

					Dcm_UDS0x19Status.RemainDTCNum--;
				}
				/**
				 * @req [SWS_Dcm_01237] If Dem_DcmGetNextFilteredRecord() returns
				 * 		DEM_FILTERED_NO_MATCHING_ELEMENT and at least one matching element could be
				 * 		retrieved before, the Dcm shall send a positive response including these data
				 * 		elements.
				 *
				 * @req [SWS_Dcm_01238] If Dem_DcmGetNextFilteredRecord() returns
				 * 		DEM_FILTERED_NO_MATCHING_ELEMENT and no matching element could be retrieved
				 * 		before, the Dcm shall send a positive response only for service and subservice.
				 */
				else if((uint8)DEM_FILTERED_NO_MATCHING_ELEMENT == u8Ret)
				{
					result = (Std_ReturnType)E_OK;

					break;
				}
				else
				{
					/* Nothing to do here. */
					;
				}
			}while((uint8)DEM_FILTERED_OK == u8Ret);
		}
	}

	return result;
}
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x03_ENABLE) */

#if((STD_ON == DCM_UDS0x19_SUB0x04_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x18_ENABLE))
/**
 * @brief			Dcm_UDS0x19ReportDTCSnapshotRecordByDTCNumberHandle
 * @details			Service 0x19 subfunction processing interface, used to retrieve the snapshot record.
 *
 * @param[in]		u8ClientId:Client identifier.
 * @param[in]		u8SubServiceId:Sub function identifier.
 * @param[in]		opState:Operating state.
 * @param[in]		pMsgContext:Message-related information for one diagnostic protocol identifier.
 * 					The pointers in pMsgContext shall point behind the SID.
 *
 * @param[out]		pErrorCode:If the called external interface returns E_NOT_OK, use this pointer to
 * 					output the NRC.
 *
 * @return        	Result of this operation.
 * @retval			E_OK:Processing successful.
 * @retval			E_NOT_OK:Processing failure.
 */
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x19ReportDTCSnapshotRecordByDTCNumberHandle
(
	uint8 u8SubServiceId,
	Dcm_OpStatusType opState,
	P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)pErrorCode
)
{
	/* Sub: 0x04, 0x18. */

	/**
	 * @req [SWS_Dcm_00302] When sending a positive response to UDS Service 0x19 with subfunction 0x04
	 * 		or 0x18 and DTCSnapshotRecordNumber not 0xFF, the Dcm module shall use the following data
	 * 		in the response message.
	 *
	 * @req [SWS_Dcm_00387] When sending a positive response to UDS Service 0x19 with subfunction 0x04
	 * 		or 0x18 and DTCSnapshotRecordNumber=0xFF, the Dcm module shall use the following data in the
	 * 		response message.
	 */

	Std_ReturnType result = (Std_ReturnType)E_NOT_OK;

	uint8 u8Ret;
	uint8 u8LoopNum = 0u;
	uint8 u8DTCStatus;
	uint8 u8RecordNumber;
	uint16 u16DataSize = Dcm_UDS0x19Status.RemainDataSize;
	uint32 u32DTC;
	boolean flag = (boolean)FALSE;

	/**
	 * @req [SWS_Dcm_00384] Upon reception of UDS Service 0x019 with subfunction 0x04 or 0x18, the Dcm
	 * 		shall retrieve from the Dem the stored snapshot records for the requested DTC and origin.
	 */

	if(DCM_PENDING != opState)
	{
		if(Dcm_UDS0x19GetReqMsgLen(u8SubServiceId) != pMsgContext->ReqDataLen)
		{
			*pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
		}
		else
		{
			u32DTC = ((uint32)pMsgContext->ReqData[2] << 16u);
			u32DTC |= ((uint32)pMsgContext->ReqData[3] << 8u);
			u32DTC |= (uint32)pMsgContext->ReqData[4];
			u8RecordNumber = pMsgContext->ReqData[5];

			Dcm_UDS0x19Status.DTC = u32DTC;

			if(0xFFu == u8RecordNumber)
			{
				Dcm_UDS0x19Status.SingleRecordNum = (boolean)FALSE;
			}
			Dcm_UDS0x19Status.RecordNum = u8RecordNumber;

#if(STD_ON == DCM_UDS0x19_SUB0x18_ENABLE)
			Dcm_UDS0x19Status.DTCOrigin = Dcm_UDS0x19GetDTCOrigin(u8SubServiceId, pMsgContext);
#if(STD_ON == DCM_UDS0x19_SUB0x04_ENABLE)
			if(0x18u == u8SubServiceId)
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x04_ENABLE) */
			{
				pMsgContext->ResData[2] = pMsgContext->ReqData[6];

				pMsgContext->ResDataLen++;
			}
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x18_ENABLE) */

			pMsgContext->ResData[pMsgContext->ResDataLen] = (uint8)(u32DTC >> 16u);
			pMsgContext->ResDataLen++;
			pMsgContext->ResData[pMsgContext->ResDataLen] = (uint8)(u32DTC >> 8u);
			pMsgContext->ResDataLen++;
			pMsgContext->ResData[pMsgContext->ResDataLen] = (uint8)u32DTC;
			pMsgContext->ResDataLen++;

			flag = (boolean)TRUE;
		}
	}
	else
	{
		flag = (boolean)TRUE;
	}

	if((boolean)TRUE == flag)
	{
		if(DCM_CHECK_BIT_SET(Dcm_UDS0x19Status.PendStep, DCM_DEM_GETSTATUSOFDTC_PENDING_BIT, uint16))
		{
			/**
			 * @req [SWS_Dcm_00383] When responding to UDS Service 0x19 with subfunction 0x04, the DCM
			 * 		module shall obtain the status of the DTC by calling Dem_DcmGetStatusOfDTC() with
			 * 		the following parameters:
			 * 		DTC: DTC from the request,
			 * 		DTCOrigin: DEM_DTC_ORIGIN_PRIMARY_MEMORY.
			 *
			 * @req [SWS_Dcm_01147] When responding to UDS Service 0x19 with subfunction 0x18, the DCM
			 * 		module shall obtain the status of the DTC by calling Dem_DcmGetStatusOfDTC() with
			 * 		the following parameters:
			 * 		DTC: DTC from the request,
			 * 		DTCOrigin: Memory Selection from request.
			 */
#if(STD_ON == DCM_UDS0x19_SUB0x18_ENABLE)
			u8Ret = Dem_DcmGetStatusOfDTC(Dcm_UDS0x19Status.DTC, Dcm_UDS0x19Status.DTCOrigin, &u8DTCStatus);
#else
			u8Ret = Dem_DcmGetStatusOfDTC(Dcm_UDS0x19Status.DTC, DEM_DTC_ORIGIN_PRIMARY_MEMORY, &u8DTCStatus);
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x18_ENABLE) */

			if((uint8)DEM_STATUS_OK == u8Ret)
			{
				pMsgContext->ResData[pMsgContext->ResDataLen] = u8DTCStatus;
				pMsgContext->ResDataLen++;

				DCM_BIT_CLEAR(Dcm_UDS0x19Status.PendStep, DCM_DEM_GETSTATUSOFDTC_PENDING_BIT, uint16);
			}
			else
			{
				if((uint8)DEM_STATUS_PENDING == u8Ret)
				{
					result = (Std_ReturnType)DCM_E_PENDING;
				}

				flag = (boolean)FALSE;
			}
		}

		/**
		 * @req [SWS_Dcm_00372] To avoid updating data values while reading out freeze frame records,
		 * 		the DCM module shall call the following API sequence: first lock updates by calling
		 * 		Dem_DcmDisableDTCRecordUpdate() (which is an exclusive area function concerning to
		 * 		SWS_BSW_00434) then call Dem_DcmGetSizeOfFreezeFrameByDTC(RecNum), then
		 * 		Dem_DcmGetFreezeFrameDataByDTC(RecNum) and finally shall re-enable updates by calling
		 * 		Dem_DcmEnableDTCRecordUpdate().
		 */
		if(((boolean)TRUE == flag) && (DCM_CHECK_BIT_SET(Dcm_UDS0x19Status.PendStep, DCM_DEM_DISABLEDTCRECORDUPDATE_PENDING_BIT, uint16)))
		{
#if(STD_ON == DCM_UDS0x19_SUB0x18_ENABLE)
			u8Ret = Dem_DcmDisableDTCRecordUpdate(Dcm_UDS0x19Status.DTC, Dcm_UDS0x19Status.DTCOrigin);
#else
			u8Ret = Dem_DcmDisableDTCRecordUpdate(Dcm_UDS0x19Status.DTC, DEM_DTC_ORIGIN_PRIMARY_MEMORY);
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x19_ENABLE) */

			if((uint8)DEM_DISABLE_DTCRECUP_OK == u8Ret)
			{
				Dcm_UDS0x19Status.DisableDTCUpdate = (boolean)TRUE;

				DCM_BIT_CLEAR(Dcm_UDS0x19Status.PendStep, DCM_DEM_DISABLEDTCRECORDUPDATE_PENDING_BIT, uint16);
			}
			else
			{
				/**
				 * @req [SWS_Dcm_00702] If function Dem_DcmDisableDTCRecordUpdate() returns
				 * 		DEM_DISABLE_DTCRECUP_PENDING, the DCM shall retry to get the lock in the next
				 * 		Dcm_MainFunction().
				 */
				if((uint8)DEM_DISABLE_DTCRECUP_PENDING == u8Ret)
				{
					result = (Std_ReturnType)DCM_E_PENDING;
				}

				/**
				 * @req [SWS_Dcm_01212] If Dem_DcmDisableDTCRecordUpdate() returns
				 * 		DEM_DISABLE_DTCRECUP_WRONG_DTC, the Dcm shall send a NRC 0x31 (Request out of
				 * 		Range).
				 *
				 * @req [SWS_Dcm_01213] If Dem_DcmDisableDTCRecordUpdate() returns
				 * 		DEM_DISABLE_DTCRECUP_WRONG_DTCORIGIN, the Dcm shall send a NRC 0x31 (Request out
				 * 		of Range).
				 */
				flag = (boolean)FALSE;
			}
		}

		if(((boolean)TRUE == flag) && (DCM_CHECK_BIT_SET(Dcm_UDS0x19Status.PendStep, DCM_DEM_GETSIZEOFFREEZEFRAMESELECTION_PENDING_BIT, uint16)))
		{
			if((boolean)FALSE == Dcm_UDS0x19Status.SingleRecordNum)
			{
				Dcm_UDS0x19Status.RecordNum = 0x01u;
				u8RecordNumber = 0xFFu;
			}
			else
			{
				u8RecordNumber = Dcm_UDS0x19Status.RecordNum;
			}

			/**
			 * @req [SWS_Dcm_00441] The DCM module shall obtain the size of the data returned by DEM in
			 * 		Dem_DcmGetFreezeFrameDataByDTC()call by using Dem_DcmGetSizeOfFreezeFrameByDTC().
			 */
#if(STD_ON == DCM_UDS0x19_SUB0x18_ENABLE)
			u8Ret = Dem_DcmGetSizeOfFreezeFrameByDTC(\
						Dcm_UDS0x19Status.DTC, Dcm_UDS0x19Status.DTCOrigin, u8RecordNumber, &u16DataSize\
						);
#else
			u8Ret = Dem_DcmGetSizeOfFreezeFrameByDTC(\
						Dcm_UDS0x19Status.DTC, DEM_DTC_ORIGIN_PRIMARY_MEMORY, u8RecordNumber, &u16DataSize\
						);
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x19_ENABLE) */

			if((uint8)DEM_GETSIZEBYDTC_OK == u8Ret)
			{
				if(pMsgContext->ResMaxDataLen >= (u16DataSize + pMsgContext->ResDataLen))
				{
					Dcm_UDS0x19Status.RemainDataSize = u16DataSize;

					DCM_BIT_CLEAR(Dcm_UDS0x19Status.PendStep, DCM_DEM_GETSIZEOFFREEZEFRAMESELECTION_PENDING_BIT, uint16);
				}
				else
				{
					*pErrorCode = DCM_E_RESPONSETOOLONG;

					flag = (boolean)FALSE;
				}
			}
			else
			{
				/**
				 * @req [SWS_Dcm_01249] If Dem_DcmGetSizeOfFreezeFrameByDTC() returns
				 * 		DEM_GETSIZEBYDTC_PENDING, the Dcm shall call again
				 * 		Dem_DcmGetSizeOfFreezeFrameByDTC() API in next Dcm_MainFunction call.
				 */
				if((uint8)DEM_GETSIZEBYDTC_PENDING == u8Ret)
				{
					result = (Std_ReturnType)DCM_E_PENDING;
				}

				/**
				 * @req [SWS_Dcm_01246] If Dem_DcmGetSizeOfFreezeFrameByDTC() returns
				 * 		DEM_GETSIZEBYDTC_WRONG_DTC, the Dcm shall send a NRC 0x31 (Request out of Range).
				 *
				 * @req [SWS_Dcm_01247] If Dem_DcmGetSizeOfFreezeFrameByDTC() returns
				 * 		DEM_GETSIZEBYDTC_WRONG_DTCORIGIN, the Dcm shall send a NRC 0x31 (Request out of
				 * 		Range).
				 *
				 * @req [SWS_Dcm_01248] If Dem_DcmGetSizeOfFreezeFrameByDTC() returns
				 * 		DEM_GETSIZEBYDTC_WRONG_RECNUM, the Dcm shall send a NRC 0x31 (Request out of
				 * 		Range).
				 */
				flag = (boolean)FALSE;
			}
		}

		if(((boolean)TRUE == flag) && (DCM_CHECK_BIT_SET(Dcm_UDS0x19Status.PendStep, DCM_DEM_GETNEXTFREEZEFRAMEDATA_PENDING_BIT, uint16)))
		{
			if((boolean)FALSE == Dcm_UDS0x19Status.SingleRecordNum)
			{
				u8LoopNum = (uint8)(0xFEu + 1u);
			}
			else
			{
				u8LoopNum = (uint8)(Dcm_UDS0x19Status.RecordNum + 1u);
			}

			do
			{
				/**
				 * @req [SWS_Dcm_00384] Upon reception of UDS Service 0x019 with subfunction
				 * 		0x04 and DTCSnapshotRecordNumber not 0xff, DCM module shall obtain the
				 * 		"DTCSnapshotRecordNumberOfIdentifiers" and the FreezeFrame by calling
				 * 		Dem_DcmGetFreezeFrameDataByDTC() with the following parameter values:
				 * 		DTC: DTCMaskRecord from the request in UDS format,
				 * 		DTCOrigin: DEM_DTC_ORIGIN_PRIMARY_MEMORY,
				 * 		RecordNumber: DTCSnapshotRecordNumber from the request.
				 *
				 * @req [SWS_Dcm_01148] Upon reception of UDS Service 0x019 with subfunction
				 * 		0x18 and DTCSnapshotRecordNumber not 0xff, Dcm module shall obtain the
				 * 		"DTCSnapshotRecordNumberOfIdentifiers" and the FreezeFrame by calling
				 * 		Dem_DcmGetFreezeFrameDataByDTC() with the following parameter values:
				 * 		DTC: DTCMaskRecord from the request in UDS format,
				 * 		DTCOrigin: Memory Selection from request,
				 * 		RecordNumber: DTCSnapshotRecordNumber from the request.
				 *
				 * @req [SWS_Dcm_00385] Upon reception of UDS Service 0x19 with subfunction 0x04
				 * 		and DTCSnapshotRecordNumber 0xff, the DCM module shall cycle through all
				 * 		FreezeFrame numbers from 0x00 to 0xfe and obtain the corresponding
				 * 		"DTCSnapshotRecordNumberOfIdentifiers" and FreezeFrame by calling
				 * 		Dem_DcmGetFreezeFrameDataByDTC() with the following parameter values:
				 * 		DTC: DTCMaskRecord from the request in UDS format,
				 * 		DTCOrigin: DEM_DTC_ORIGIN_PRIMARY_MEMORY,
				 * 		RecordNumber: value from 0x00 -> 0xFE.
				 *
				 * @req [SWS_Dcm_01149] Upon reception of UDS Service 0x19 with subfunction 0x18
				 * 		and DTCSnapshotRecordNumber 0xff, the Dcm module shall cycle through all
				 * 		FreezeFrame numbers from 0x00 to 0xfe and obtain the corresponding
				 * 		"DTCSnapshotRecordNumberOfIdentifiers" and FreezeFrame by calling
				 * 		Dem_DcmGetFreezeFrameDataByDTC() with the following parameter values:
				 * 		DTC: DTCMaskRecord from the request in UDS format,
				 * 		DTCOrigin: Memory Selection from request,
				 * 		RecordNumber: value from 0x00 -> 0xFE.
				 */
#if(STD_ON == DCM_UDS0x19_SUB0x18_ENABLE)
				u8Ret = Dem_DcmGetFreezeFrameDataByDTC(\
							Dcm_UDS0x19Status.DTC, Dcm_UDS0x19Status.DTCOrigin, Dcm_UDS0x19Status.RecordNum,\
							&pMsgContext->ResData[pMsgContext->ResDataLen], &u16DataSize\
							);
#else
				u8Ret = Dem_DcmGetFreezeFrameDataByDTC(\
							Dcm_UDS0x19Status.DTC, DEM_DTC_ORIGIN_PRIMARY_MEMORY, Dcm_UDS0x19Status.RecordNum,\
							&pMsgContext->ResData[pMsgContext->ResDataLen], &u16DataSize\
							);
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x19_ENABLE) */

				if((uint8)DEM_GET_FFDATABYDTC_OK == u8Ret)
				{
					pMsgContext->ResDataLen += (uint32)u16DataSize;

					Dcm_UDS0x19Status.RemainDataSize -= u16DataSize;

					u16DataSize = Dcm_UDS0x19Status.RemainDataSize;

					Dcm_UDS0x19Status.RemainDTCNum++;

					result = (Std_ReturnType)E_OK;
				}
				/**
				 * @req [SWS_Dcm_01223] If Dem_DcmGetFreezeFrameDataByDTC() returns
				 * 		DEM_RECORD_WRONG_NUMBER and if multiple Extended Data Record is requested,
				 * 		the Dcm shall proceed with the next record.
				 */
				else if(((uint8)DEM_RECORD_WRONG_NUMBER == u8Ret) && ((boolean)FALSE == Dcm_UDS0x19Status.SingleRecordNum))
				{
					/* Nothing to do here. */
					;
				}
				else
				{
					/**
					 * @req [SWS_Dcm_01225] If Dem_DcmGetFreezeFrameDataByDTC() returns
					 * 		DEM_GET_FFDATABYDTC_PENDING, the Dcm shall call again
					 * 		Dem_DcmGetFreezeFrameDataByDTC() API in next Dcm_MainFunction() call.
					 */
					if((uint8)DEM_GET_FFDATABYDTC_PENDING == u8Ret)
					{
						result = (Std_ReturnType)DCM_E_PENDING;
					}
					/**
					 * @req [SWS_Dcm_01220] If Dem_DcmGetFreezeFrameDataByDTC() returns
					 * 		DEM_GET_FFDATABYDTC_WRONG_DTC, the Dcm shall send a NRC 0x31 (Request
					 * 		out of Range).
					 *
					 * @req [SWS_Dcm_01221] If Dem_DcmGetFreezeFrameDataByDTC() returns
					 * 		DEM_GET_FFDATABYDTC_WRONG_DTCORIGIN, the Dcm shall send a NRC 0x31
					 * 		(Request out of Range).
					 *
					 * @req [SWS_Dcm_01222] If Dem_DcmGetFreezeFrameDataByDTC() returns
					 * 		DEM_GET_FFDATABYDTC_WRONG_RECORDNUMBER and if a single Extended Data
					 * 		Record is requested, the Dcm shall send a NRC 0x31 (Request out of
					 * 		Range).
					 */
					else
					{
						/* Nothing to do here. */
						;
					}

					break;
				}

				Dcm_UDS0x19Status.RecordNum++;

			}while(Dcm_UDS0x19Status.RecordNum < u8LoopNum);
		}
	}

	return result;
}
#endif /* #if((STD_ON == DCM_UDS0x19_SUB0x04_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x18_ENABLE)) */

#if(STD_ON == DCM_UDS0x19_SUB0x05_ENABLE)
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x19ReportDTCStoredDataByRecordNumberHandle
(
	P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
)
{
	/* Sub: 0x05. */

	Std_ReturnType result = (Std_ReturnType)E_NOT_OK;

	return result;
}
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x05_ENABLE) */

#if((STD_ON == DCM_UDS0x19_SUB0x0B_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x0C_ENABLE) ||\
	(STD_ON == DCM_UDS0x19_SUB0x0D_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x0E_ENABLE))
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x19ReportSpecificDTCHandle
(
	uint8 u8SubServiceId,
	P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
)
{
	/* Sub: 0x0B, 0x0C, 0x0D, 0x0E. */

	Std_ReturnType result = (Std_ReturnType)E_NOT_OK;

	return result;
}
#endif /* #if((STD_ON == DCM_UDS0x19_SUB0x0B_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x0C_ENABLE) ||\
			  (STD_ON == DCM_UDS0x19_SUB0x0D_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x0E_ENABLE)) */

#if(STD_ON == DCM_UDS0x19_SUB0x14_ENABLE)
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x19ReportDTCFaultDetectionCounterHandle
(
	P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
)
{
	/* Sub: 0x14. */

	Std_ReturnType result = (Std_ReturnType)E_NOT_OK;

	return result;
}
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x14_ENABLE) */

#if(STD_ON == DCM_UDS0x19_SUB0x42_ENABLE)
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x19ReportWWHOBDDTCByMaskRecordHandle
(
	uint8 u8SubServiceId,
	P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
)
{
	/* Sub: 0x42. */

	Std_ReturnType result = (Std_ReturnType)E_NOT_OK;

	/**
	 * @req [SWS_Dcm_01127] The Dcm module shall retrieve the DTCSeverityAvailabilityMask by using the
	 * 		function Dem_GetDTCSeverityAvailabilityMask().
	 */

	return result;
}
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x42_ENABLE) */

#if(STD_ON == DCM_UDS0x19_SUB0x55_ENABLE)
STATIC FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x19ReportWWHOBDDTCWithPermanentStatusHandle
(
	uint8 u8SubServiceId,
	P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
)
{
	/* Sub: 0x55. */

	Std_ReturnType result = (Std_ReturnType)E_NOT_OK;

	return result;
}
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x55_ENABLE) */
/*====================================================================================================*
 *                                          GLOBAL FUNCTIONS
 *====================================================================================================*/
/**
 * @brief			Dcm_UDS0x19
 * @details			Internal processing interface for Service 0x19.
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
FUNC(Std_ReturnType, DCM_CODE)Dcm_UDS0x19
(
	Dcm_OpStatusType OpStatus,
	P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR)pMsgContext,
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
)
{
	Std_ReturnType result = (Std_ReturnType)E_NOT_OK;

	uint8 u8AddrType;
	Std_ReturnType callResult = (Std_ReturnType)E_OK;
	const Dcm_DsdServiceType* pService = NULL_PTR;

	if(DCM_PENDING != OpStatus)
	{
		if(2u > pMsgContext->ReqDataLen)
		{
			*ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;

			callResult = (Std_ReturnType)E_NOT_OK;
		}
		else
		{
			Dcm_UDS0x19Status.SubId = pMsgContext->ReqData[1];

			u8AddrType = (pMsgContext->MsgAddInfo & 0x01u);

			pService = DCM_GET_SERVICE_PTR(Dcm_ConnectionStatus[Dcm_ActiveConIdx].ServiceIdx);

			callResult = DspInternal_SubServiceCheck(\
							u8AddrType, Dcm_UDS0x19Status.SubId, pService, ErrorCode\
							);

			if((Std_ReturnType)E_OK == callResult)
			{
				pMsgContext->ResDataLen = 2u;

				/* Ensure that all interfaces can be called under normal circumstances. */
				Dcm_UDS0x19Status.DTC = 0u;
				Dcm_UDS0x19Status.RecordNum = 0u;
				Dcm_UDS0x19Status.RemainDTCNum = 0u;
				Dcm_UDS0x19Status.RemainDataSize = 0u;
				Dcm_UDS0x19Status.PendStep = 0xFFFFu;
				Dcm_UDS0x19Status.SingleRecordNum = (boolean)TRUE;
				Dcm_UDS0x19Status.DisableDTCUpdate = (boolean)FALSE;
#if((STD_ON == DCM_UDS0x19_SUB0x19_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x18_ENABLE))
				Dcm_UDS0x19Status.DTCOrigin = DEM_DTC_ORIGIN_PRIMARY_MEMORY;
#endif /* #if((STD_ON == DCM_UDS0x19_SUB0x19_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x18_ENABLE)) */
			}
		}
	}

	if((Std_ReturnType)E_OK == callResult)
	{
		switch(Dcm_UDS0x19Status.SubId)
		{
#if((STD_ON == DCM_UDS0x19_SUB0x01_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x07_ENABLE) ||\
	(STD_ON == DCM_UDS0x19_SUB0x11_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x12_ENABLE))
#if(STD_ON == DCM_UDS0x19_SUB0x01_ENABLE)
			case 0x01u:
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x01_ENABLE) */
#if(STD_ON == DCM_UDS0x19_SUB0x07_ENABLE)
			case 0x07u:
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x07_ENABLE) */
#if(STD_ON == DCM_UDS0x19_SUB0x11_ENABLE)
			case 0x11u:
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x11_ENABLE) */
#if(STD_ON == DCM_UDS0x19_SUB0x12_ENABLE)
			case 0x12u:
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x12_ENABLE) */
				callResult = Dcm_UDS0x19ReportDTCNumberHandle(Dcm_UDS0x19Status.SubId, OpStatus, pMsgContext, ErrorCode);
				break;
#endif /* #if((STD_ON == DCM_UDS0x19_SUB0x01_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x07_ENABLE) ||\
			  (STD_ON == DCM_UDS0x19_SUB0x11_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x12_ENABLE)) */
#if((STD_ON == DCM_UDS0x19_SUB0x02_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x0A_ENABLE) ||\
	(STD_ON == DCM_UDS0x19_SUB0x0F_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x13_ENABLE) ||\
	(STD_ON == DCM_UDS0x19_SUB0x15_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x17_ENABLE))
#if(STD_ON == DCM_UDS0x19_SUB0x02_ENABLE)
			case 0x02u:
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x02_ENABLE) */
#if(STD_ON == DCM_UDS0x19_SUB0x0A_ENABLE)
			case 0x0Au:
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x0A_ENABLE) */
#if(STD_ON == DCM_UDS0x19_SUB0x0F_ENABLE)
			case 0x0Fu:
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x0F_ENABLE) */
#if(STD_ON == DCM_UDS0x19_SUB0x13_ENABLE)
			case 0x13u:
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x13_ENABLE) */
#if(STD_ON == DCM_UDS0x19_SUB0x15_ENABLE)
			case 0x15u:
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x15_ENABLE) */
#if(STD_ON == DCM_UDS0x19_SUB0x17_ENABLE)
			case 0x17u:
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x17_ENABLE) */
				callResult = Dcm_UDS0x19ReportDTCAndStatusHandle(Dcm_UDS0x19Status.SubId, OpStatus, pMsgContext, ErrorCode);
				break;
#endif /* #if((STD_ON == DCM_UDS0x19_SUB0x02_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x0A_ENABLE) ||\
		      (STD_ON == DCM_UDS0x19_SUB0x0F_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x13_ENABLE) ||\
			  (STD_ON == DCM_UDS0x19_SUB0x15_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x17_ENABLE)) */
#if(STD_ON == DCM_UDS0x19_SUB0x08_ENABLE)
			case 0x08u:
				callResult = Dcm_UDS0x19ReprotDTCBySMaskHandle(OpStatus, pMsgContext, ErrorCode);
				break;
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x08_ENABLE) */
#if(STD_ON == DCM_UDS0x19_SUB0x09_ENABLE)
			case 0x09u:
				callResult = Dcm_UDS0x19ReportSInfoOfDTCHandle(OpStatus, pMsgContext, ErrorCode);
				break;
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x09_ENABLE) */
#if((STD_ON == DCM_UDS0x19_SUB0x06_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x10_ENABLE) ||\
	(STD_ON == DCM_UDS0x19_SUB0x19_ENABLE))
#if(STD_ON == DCM_UDS0x19_SUB0x06_ENABLE)
			case 0x06u:
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x06_ENABLE) */
#if(STD_ON == DCM_UDS0x19_SUB0x10_ENABLE)
			case 0x10u:
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x10_ENABLE) */
#if(STD_ON == DCM_UDS0x19_SUB0x19_ENABLE)
			case 0x19u:
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x19_ENABLE) */
				callResult = Dcm_UDS0x19ReportExtDataRecordHandle(Dcm_UDS0x19Status.SubId, OpStatus, pMsgContext, ErrorCode);
				break;
#endif /* #if((STD_ON == DCM_UDS0x19_SUB0x06_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x10_ENABLE) ||\
			  (STD_ON == DCM_UDS0x19_SUB0x19_ENABLE)) */
#if(STD_ON == DCM_UDS0x19_SUB0x03_ENABLE)
			case 0x03u:
				callResult = Dcm_UDS0x19ReportDTCSnapshotIdentificationHandle(OpStatus, pMsgContext, ErrorCode);
				break;
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x03_ENABLE) */
#if((STD_ON == DCM_UDS0x19_SUB0x04_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x18_ENABLE))
#if(STD_ON == DCM_UDS0x19_SUB0x04_ENABLE)
			case 0x04u:
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x04_ENABLE) */
#if(STD_ON == DCM_UDS0x19_SUB0x18_ENABLE)
			case 0x18u:
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x18_ENABLE) */
				callResult = Dcm_UDS0x19ReportDTCSnapshotRecordByDTCNumberHandle(Dcm_UDS0x19Status.SubId, OpStatus, pMsgContext, ErrorCode);
				break;
#endif /* #if((STD_ON == DCM_UDS0x19_SUB0x04_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x18_ENABLE)) */
#if(STD_ON == DCM_UDS0x19_SUB0x05_ENABLE)
			case 0x05u:
				callResult = Dcm_UDS0x19ReportDTCStoredDataByRecordNumberHandle(pMsgContext, ErrorCode);
				break;
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x05_ENABLE) */
#if((STD_ON == DCM_UDS0x19_SUB0x0B_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x0C_ENABLE) ||\
	(STD_ON == DCM_UDS0x19_SUB0x0D_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x0E_ENABLE))
#if(STD_ON == DCM_UDS0x19_SUB0x0B_ENABLE)
			case 0x0Bu:
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x0B_ENABLE) */
#if(STD_ON == DCM_UDS0x19_SUB0x0C_ENABLE)
			case 0x0Cu:
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x0C_ENABLE) */
#if(STD_ON == DCM_UDS0x19_SUB0x0D_ENABLE)
			case 0x0Du:
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x0D_ENABLE) */
#if(STD_ON == DCM_UDS0x19_SUB0x0E_ENABLE)
			case 0x0Eu:
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x0E_ENABLE) */
				callResult = Dcm_UDS0x19ReportSpecificDTCHandle(Dcm_UDS0x19Status.SubId, pMsgContext, ErrorCode);
				break;
#endif /* #if((STD_ON == DCM_UDS0x19_SUB0x0B_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x0C_ENABLE) ||\
			  (STD_ON == DCM_UDS0x19_SUB0x0D_ENABLE) || (STD_ON == DCM_UDS0x19_SUB0x0E_ENABLE)) */
#if(STD_ON == DCM_UDS0x19_SUB0x14_ENABLE)
			case 0x14u:
				callResult = Dcm_UDS0x19ReportDTCFaultDetectionCounterHandle(pMsgContext, ErrorCode);
				break;
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x14_ENABLE) */
#if(STD_ON == DCM_UDS0x19_SUB0x42_ENABLE)
			case 0x42u:
				callResult = Dcm_UDS0x19ReportWWHOBDDTCByMaskRecordHandle(pMsgContext, ErrorCode);
				break;
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x42_ENABLE) */
#if(STD_ON == DCM_UDS0x19_SUB0x55_ENABLE)
			case 0x55u:
				callResult = Dcm_UDS0x19ReportWWHOBDDTCWithPermanentStatusHandle(pMsgContext, ErrorCode);
				break;
#endif /* #if(STD_ON == DCM_UDS0x19_SUB0x55_ENABLE) */
			default:
				callResult = (Std_ReturnType)E_NOT_OK;
				break;
		}

		if((Std_ReturnType)DCM_E_PENDING == callResult)
		{
			Dcm_OpState = DCM_PENDING;
			*ErrorCode = DCM_E_RESPONSE_PENDING;
		}
		else
		{
			if((Std_ReturnType)E_OK == callResult)
			{
				pMsgContext->ResData[0] = 0x59u;
				pMsgContext->ResData[1] = Dcm_UDS0x19Status.SubId;

				result = (Std_ReturnType)E_OK;
			}
			else
			{
				/**
				 * @req [SWS_Dcm_01218] If at least one of the requested extended data record is
				 * 		supported, the Dcm shall send a positive response. Otherwise the Dcm shall send
				 * 		a NRC 0x31 (Request out of Range).
				 *
				 * @req [SWS_Dcm_01224] If at least one of the requested extended data is supported,
				 * 		the Dcm shall send a positive response. Otherwise the Dcm shall send a NRC 0x31
				 * 		(Request out of Range).
				 */
				if((0xFFu == *ErrorCode) || (DCM_PENDING == Dcm_OpState))
				{
					*ErrorCode = DCM_E_REQUESTOUTOFRANGE;
				}
			}

			if((boolean)TRUE == Dcm_UDS0x19Status.DisableDTCUpdate)
			{
				(void)Dem_DcmEnableDTCRecordUpdate();
			}
		}
	}

	return result;
}

#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#endif /* #if(STD_ON == DCM_UDS0x19_INTERNAL_FNC_ENABLE) */
#endif /* #if(STD_ON == DCM_UDS0x19_ENABLE) */

#ifdef __cplusplus
}
#endif
/** @} */
