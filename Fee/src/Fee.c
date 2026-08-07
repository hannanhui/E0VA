/**
 * @file        Fee.c
 * @brief       AUTOSAR FEE  - Fee driver source file.
 * @details     Fee driver source file, containing the C implementation of Autosar API specification
 *              and other variables and functions that are exported by the Fee driver.
 * @version     1.2.0
 * @addtogroup  FEE
 * @{
 */
/*=================================================================================================*
 * AngHui AUTOSAR BSW.
 *
 * Copyright(C) 2023 GuoKeAngHui Inc.
 *
 * All rights reserved.
 *
 * This file is part of AngHui AUTOSAR BSW, contains proprietary information.
 * Passing on and copying of this document, and communication of its contents
 * is not permitted without prior written authorization.
 *=================================================================================================*/


#ifdef __cplusplus
extern "C"{
#endif

/* PRQA S 0292, 0288, 1503, 1505, 0857, 0791, 0828, 0647 EOF #
 *
 * 1.0292 -- Violates MISRA 2004 Required Rule 3.1, Source file has comments containing one of the
 * characters '$', '@' or '`'.
 *
 * 2.0288 -- Violates MISRA 2004 Required Rule 3.1, Source file has comments containing characters
 * which are not members of the basic source character set.
 *
 * 3.1503 -- Violates MISRA 2004 Required Rule 14.1, The function is defined but is not used within
 * this project.
 *
 * 4.1505 -- Violates MISRA 2004 Required Rule 8.10, The function is only referenced in the translation
 * unit where it is defined.
 *
 * 5.0857 -- Violates MISRA 2004 Required Rule 1.1, Number of macro definitions exceeds 1024 - program
 * does not conform strictly to ISO:C90.
 *
 * 6.0791 -- Violates MISRA 2004 Required Rule 5.1, Macro identifier does not differ from other macro
 * identifier(s) within the specified number of significant characters.
 *
 * 7.0828 -- Violates MISRA 2004 Required Rule 1.1, More than 8 levels of nested conditional inclusion
 * - program does not conform strictly to ISO:C90.
 *
 * 8.0647 -- Violates MISRA 2004 Required Rule 1.1, Number of enumeration constants exceeds 127 - program
 * does not conform strictly to ISO:C90.
 *
 * @page misra_violations MISRA-C:2004 violations
 */

/* PRQA S 3453, 3412, 3410, 1055, 0310, 0498, 0489, 2982, 2843, 0781, 2003, 2877 EOF # These warnings do not need to be modified */

/*====================================================================================================*
 *                                           INCLUDE FILES                                          
 *====================================================================================================*/
#include "Fee.h"
#include "Fee_Cbk.h"
#include "Fee_Internal.h"
#if (FEE_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif/* FEE_DEV_ERROR_DETECT == STD_ON */

#ifdef AH_TEST_FEE
#include "TestCode.h"
#endif

/*====================================================================================================*
 *                                  SOURCE FILE VERSION INFORMATION                                 
 *====================================================================================================*/
#define FEE_VENDOR_ID_C 					0U
#define FEE_AR_RELEASE_MAJOR_VERSION_C 		4U
#define FEE_AR_RELEASE_MINOR_VERSION_C 		2U
#define FEE_AR_RELEASE_REVISION_VERSION_C 	2U
#define FEE_SW_MAJOR_VERSION_C 				1U
#define FEE_SW_MINOR_VERSION_C 				2U
#define FEE_SW_PATCH_VERSION_C 				0U

/*====================================================================================================*
 *                                         FILE VERSION CHECKS                                      
 *====================================================================================================*/
/* Check if current file and Fee_Cbk header file are of the same vendor */
#if(FEE_VENDOR_ID_C != FEE_CBK_VENDOR_ID )
#error "Fee.c and Fee_Cbk.h have different vendor id"
#endif
/* Check if current file and Fee_Cbk header file are of the same Autosar version */
#if(\
		(FEE_AR_RELEASE_MAJOR_VERSION_C != FEE_CBK_AR_RELEASE_MAJOR_VERSION) || \
		(FEE_AR_RELEASE_MINOR_VERSION_C != FEE_CBK_AR_RELEASE_MINOR_VERSION) || \
		(FEE_AR_RELEASE_REVISION_VERSION_C != FEE_CBK_AR_RELEASE_REVISION_VERSION) \
	)
#error "AutoSar Version Number of Fee.c and Fee_Cbk.h are different "
#endif
/* Check if current file and Fee_Cbk header file are of the same Software version */
#if(\
		(FEE_SW_MAJOR_VERSION_C != FEE_CBK_SW_MAJOR_VERSION) || \
		(FEE_SW_MINOR_VERSION_C != FEE_CBK_SW_MINOR_VERSION) || \
		(FEE_SW_PATCH_VERSION_C != FEE_CBK_SW_PATCH_VERSION) \
	)
#error "Software Version Number of Fee.c and Fee_Cbk.h are different "
#endif

/* Check if current file and Fee header file are of the same vendor */
#if(FEE_VENDOR_ID_C != FEE_VENDOR_ID )
#error "Fee.c and Fee.h have different vendor id"
#endif
/* Check if current file and Fee header file are of the same Autosar version */
#if(\
		(FEE_AR_RELEASE_MAJOR_VERSION_C != FEE_AR_RELEASE_MAJOR_VERSION) || \
		(FEE_AR_RELEASE_MINOR_VERSION_C != FEE_AR_RELEASE_MINOR_VERSION) || \
		(FEE_AR_RELEASE_REVISION_VERSION_C != FEE_AR_RELEASE_REVISION_VERSION) \
	)
#error "AutoSar Version Number of Fee.c and Fee.h are different "
#endif
/* Check if current file and Fee header file are of the same Software version */
#if(\
		(FEE_SW_MAJOR_VERSION_C != FEE_SW_MAJOR_VERSION) || \
		(FEE_SW_MINOR_VERSION_C != FEE_SW_MINOR_VERSION) || \
		(FEE_SW_PATCH_VERSION_C != FEE_SW_PATCH_VERSION) \
	)
#error "Software Version Number of Fee.c and Fee.h are different "
#endif

/* Check if current file and Fee_Internal header file are of the same vendor */
#if(FEE_VENDOR_ID_C != FEE_INTERNAL_VENDOR_ID )
#error "Fee.c and Fee_Internal.h have different vendor id"
#endif
/* Check if current file and Fee_Internal header file are of the same Autosar version */
#if(\
		(FEE_AR_RELEASE_MAJOR_VERSION_C != FEE_INTERNAL_AR_RELEASE_MAJOR_VERSION) || \
		(FEE_AR_RELEASE_MINOR_VERSION_C != FEE_INTERNAL_AR_RELEASE_MINOR_VERSION) || \
		(FEE_AR_RELEASE_REVISION_VERSION_C != FEE_INTERNAL_AR_RELEASE_REVISION_VERSION) \
	)
#error "AutoSar Version Number of Fee.c and Fee_Internal.h are different "
#endif
/* Check if current file and Fee_Internal header file are of the same Software version */
#if(\
		(FEE_SW_MAJOR_VERSION_C != FEE_INTERNAL_SW_MAJOR_VERSION) || \
		(FEE_SW_MINOR_VERSION_C != FEE_INTERNAL_SW_MINOR_VERSION) || \
		(FEE_SW_PATCH_VERSION_C != FEE_INTERNAL_SW_PATCH_VERSION) \
	)
#error "Software Version Number of Fee.c and Fee_Internal.h are different "
#endif

#ifndef DISABLE_INTERMOD_VERSION_CHECK

#if (FEE_DEV_ERROR_DETECT == STD_ON)
/* Check if current file and Det header file are of the same Autosar version */
#if(\
		(FEE_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
		(FEE_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION) \
	)
#error "AutoSar Version Number of Fee.c and Det.h are different "
#endif
#endif/* (FEE_DEV_ERROR_DETECT == STD_ON) */

#endif/* DISABLE_INTERMOD_VERSION_CHECK */

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

#if (STD_ON == FEE_DEV_ERROR_DETECT)
/**
 * @brief Error reported to the operation
 */
#define FEE_DET_REPORT(ApiId, ErrorId)  \
	(void)Det_ReportError((uint16)(FEE_MODULE_ID), (uint8)0U, (ApiId), (ErrorId))
#endif /* (STD_ON == BSWM_DEV_ERROR_DETECT) */

/**
* @brief          Serialize scalar parameter into the buffer
*
* @param[in]      ParamVal serialized parameter
* @param[in]      ParamType type of serialized parameter
* @param[in/out]  pSerialPtr pointer to target buffer
*
* @pre            pSerialPtr must be valid pointer
* @post           increments the pSerialPtr by sizeof(ParamType)
*
*/
#define FEE_SERIALIZE( ParamVal, ParamType, pSerialPtr ) \
    do \
    { \
        *((ParamType*)(pSerialPtr)) = (ParamVal); \
        (pSerialPtr) += sizeof(ParamType); \
    } while( 0 );

/**
* @brief          Deserialize scalar parameter from the buffer
*
* @param[in/out]  pDeserialPtr pointer to source buffer
* @param[out]     ParamVal deserialized parameter
* @param[int]     ParamType type of serialized parameter
*
* @pre            pDeserialPtr must be valid pointer
* @post           increments the pDeserialPtr by sizeof(ParamType)
*
*/
#define FEE_DESERIALIZE( pDeserialPtr, ParamVal, ParamType ) \
    do \
    { \
        (ParamVal) = *((ParamType*)(pDeserialPtr)); \
        (pDeserialPtr) += sizeof(ParamType); \
    } while( 0 );

/*====================================================================================================*
 *                                           LOCAL CONSTANTS                                        
 *====================================================================================================*/

/*====================================================================================================*
 *                                           LOCAL VARIABLES                                        
 *====================================================================================================*/
/* PRQA S 5087 EOF # Need to increase the Fee_MemMap module */
#define FEE_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Fee_MemMap.h"
/**
 * @brief Variables that need to be used at run time
 */
STATIC VAR(Fee_GlobalParType, FEE_VAR) Fee_GlobalPar;
#define FEE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Fee_MemMap.h"


#define FEE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Fee_MemMap.h"
/**
* @brief        Run-time information of all configured Fee blocks. Contains
*               status, and data information. Used by all jobs
* @implements   Fee_aBlockInfo_Object
*/
STATIC VAR(Fee_BlockInfoType, FEE_VAR) Fee_aBlockInfo[FEE_NUMBER_OF_BLOCKS];
/**
* @brief        Run-time information of all configured cluster groups
*/
STATIC VAR(Fee_ClusterGroupInfoType, FEE_VAR) Fee_aClrGrpInfo[FEE_NUMBER_OF_CLUSTER_GROUPS];
/**
 * @brief Information about the internal variables at run time
 */
STATIC VAR(Fee_InterRunInformationType, FEE_VAR) Fee_InterRunInfor = \
		{MEMIF_UNINIT, MEMIF_JOB_OK, FEE_JOB_DONE, FEE_JOB_DONE};
#define FEE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Fee_MemMap.h"


#define FEE_START_SEC_VAR_NO_INIT_8
#include "Fee_MemMap.h"
/**
* @brief        Pointer to user data buffer. Used by the read Fee jobs
*/
STATIC P2VAR( uint8, FEE_VAR, FEE_APPL_DATA ) Fee_pJobReadDataDestPtr = NULL_PTR;
/**
* @brief        Pointer to user data buffer. Used by the write Fee jobs
*/
STATIC P2CONST( uint8, FEE_CONST, FEE_APPL_CONST ) Fee_pJobWriteDataDestPtr = NULL_PTR;
/**
* @brief        Data buffer used by all jobs to store immediate data
*/
STATIC VAR(uint8, FEE_VAR) Fee_aDataBuffer[FEE_DATA_BUFFER_SIZE] = {0};
#define FEE_STOP_SEC_VAR_NO_INIT_8
#include "Fee_MemMap.h"

/*====================================================================================================*
 *                                      LOCAL FUNCTION PROTOTYPES                                   
 *====================================================================================================*/
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"

STATIC FUNC( void, FEE_CODE ) Fee_SerializeBlockHdr
(
	CONST( uint16, AUTOMATIC ) uBlockNumber,
	CONST( uint16, AUTOMATIC ) uLength,
	CONST( Fls_AddressType, AUTOMATIC) uTargetAddress,
	CONST( boolean, AUTOMATIC ) bImmediateBlock,
	P2VAR( uint8, AUTOMATIC, FEE_APPL_DATA ) pBlockHdrPtr
);

STATIC FUNC( Std_ReturnType, FEE_CODE ) Fee_BlankCheck
(
	P2CONST( uint8, AUTOMATIC, FEE_APPL_CONST ) pTargetPtr,
	CONSTP2CONST( uint8, AUTOMATIC, FEE_APPL_CONST ) pTargetEndPtr
);

STATIC FUNC( Std_ReturnType, FEE_CODE ) Fee_DeserializeFlag
(
	CONSTP2CONST( uint8, AUTOMATIC, FEE_APPL_CONST ) pTargetPtr,
	CONST( uint8, AUTOMATIC ) u8FlagPattern,
	P2VAR( boolean, AUTOMATIC, FEE_APPL_DATA ) pFlagValue
);

STATIC FUNC( Fee_BlockStatusType, FEE_CODE ) Fee_DeserializeBlockHdr
(
	CONSTP2VAR( uint16, AUTOMATIC, FEE_APPL_DATA ) pBlockNumber,
	CONSTP2VAR( uint16, AUTOMATIC, FEE_APPL_DATA ) pLength,
	CONSTP2VAR( Fls_AddressType, AUTOMATIC, FEE_APPL_DATA ) pTargetAddress,
	CONSTP2VAR( boolean, AUTOMATIC, FEE_APPL_DATA ) pImmediateBlock,
	P2CONST( uint8, AUTOMATIC, FEE_APPL_CONST ) pBlockHdrPtr
);

STATIC FUNC( Fee_ClusterStatusType, FEE_CODE ) Fee_DeserializeClusterHdr
(
	CONSTP2VAR( uint32, AUTOMATIC, FEE_APPL_DATA ) pClrID,
	CONSTP2VAR( Fls_AddressType, AUTOMATIC, FEE_APPL_DATA ) pStartAddress,
	CONSTP2VAR( Fls_LengthType, AUTOMATIC, FEE_APPL_DATA ) pClusteSize,
	P2CONST( uint8, AUTOMATIC, FEE_APPL_CONST ) pClrHdrPtr
);

STATIC FUNC( void, FEE_CODE ) Fee_SerializeClusterHdr
(
	CONST( uint32, AUTOMATIC ) uClrID,
	CONST( Fls_AddressType, AUTOMATIC) uStartAddress,
	CONST( Fls_LengthType, AUTOMATIC) uClusteSize,
	P2VAR( uint8, AUTOMATIC, FEE_APPL_DATA ) pClrHdrPtr
);

STATIC FUNC( uint16, FEE_CODE ) Fee_GetBlockIndex
(
	CONST( uint16, AUTOMATIC ) uBlockNumber
);

LOCAL_INLINE FUNC( uint16, FEE_CODE ) Fee_GetBlockNumber
(
    CONST( uint16, AUTOMATIC ) uBlockRuntimeInfoIndex
);
LOCAL_INLINE FUNC( uint16, FEE_CODE ) Fee_GetBlockSize
(
    CONST( uint16, AUTOMATIC ) uBlockRuntimeInfoIndex
);
LOCAL_INLINE FUNC( uint8, FEE_CODE ) Fee_GetBlockClusterGrp
(
    CONST( uint16, AUTOMATIC ) uBlockRuntimeInfoIndex
);
LOCAL_INLINE FUNC( boolean, FEE_CODE ) Fee_GetBlockImmediate
(
    CONST( uint16, AUTOMATIC ) uBlockRuntimeInfoIndex
);
STATIC FUNC( uint16, FEE_CODE ) Fee_AlignToVirtualPageSize
(
	VAR( uint16, AUTOMATIC ) uBlockSize
);

STATIC FUNC( void, FEE_CODE ) Fee_CopyDataToPageBuffer
(
	P2CONST( uint8, AUTOMATIC, FEE_APPL_CONST ) pSourcePtr,
	P2VAR( uint8, AUTOMATIC, FEE_APPL_DATA ) pTargetPtr,
	CONST( uint16, AUTOMATIC ) uLength
);

STATIC FUNC( void, FEE_CODE ) Fee_SerializeFlag
(
	P2VAR( uint8, AUTOMATIC, FEE_APPL_DATA ) pTargetPtr,
	CONST( uint8, AUTOMATIC ) u8FlagPattern
);

STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntSwapClrVld( void );

STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntSwapBlock( void );

STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntSwapClrFmt( void );

STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntSwapClrErase( void );

STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntSwap( void );

STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntScanBlockHdrRead( void );

STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntScanClrErase( void );

STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntScanClr( void );

STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntScanClrFmt( void );

STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntScanClrFmtDone( void );

STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntScanBlockHdrParse
    (
        CONST( boolean, AUTOMATIC ) bBufferValid
    );

STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntScanClrHdrRead( void );

STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntScan( void );

STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntScanClrHdrParse
    (
        CONST( boolean, AUTOMATIC) bBufferValid
    );

STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobRead( void );

STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntSwapBlockVld( void );

STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntSwapDataRead
    (
        CONST( boolean, AUTOMATIC) bBufferValid
    );

STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntSwapDataWrite
    (
        CONST( boolean, AUTOMATIC ) bBufferValid
    );

STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntSwapClrVldDone( void );

STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobWriteHdr( void );

STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobWriteData( void );

STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobWrite( void );

STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobWriteUnalignedData( void );

STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobWriteValidate( void );

STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobWriteDone( void );

STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobInvalBlock( void );

STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobInvalBlockDone( void );

STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobEraseImmediate( void );

STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobEraseImmediateDone( void );

STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobSchedule( void );

STATIC FUNC( sint8, FEE_CODE ) Fee_ReservedAreaWritable( void );

#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

/*====================================================================================================*
 *                                           LOCAL FUNCTIONS                                        
 *====================================================================================================*/
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"

/**
* @brief   Returns the cluster group for a block specified by its index in the Fee_aBlockInfo array
*
* @param[in]      uBlockRuntimeInfoIndex     index in the Fee_aBlockInfo array
* @return         uint8
* @retval         cluster group number
* @pre            -
*/
LOCAL_INLINE FUNC( uint8, FEE_CODE ) Fee_GetBlockClusterGrp(CONST( uint16, AUTOMATIC ) uBlockRuntimeInfoIndex)
{
	/* PRQA S 2981 , 2844 EOF # The pointer operation does not need to be modified */
	VAR(uint8, AUTOMATIC) uBlockClusterGrp = 0U;

	/* the config is part of Fee_BlockConfig*/
	uBlockClusterGrp = Fee_BlockConfig[uBlockRuntimeInfoIndex].FeeClrGrpIndex;

	return uBlockClusterGrp;
}

/**
* @brief        Serialize Fee block parameters into a write buffer
*
* @param[in]    uBlockNumber     Fee block number
* @param[in]    uLength          Size of Fee block in bytes
* @param[in]    uTargetAddress   Logical address of Fee block in Fls adress
*                                space
* @param[in]    bImmediateBlock  Type of Fee block. Set to TRUE for immediate
*                                block
* @param[out]   pBlockHdrPtr     Pointer to serialization buffer
*
* @pre          pBlockHdrPtr must be valid pointer
*
*/
STATIC FUNC( void, FEE_CODE ) Fee_SerializeBlockHdr
(
	CONST( uint16, AUTOMATIC ) uBlockNumber,
	CONST( uint16, AUTOMATIC ) uLength,
	CONST( Fls_AddressType, AUTOMATIC) uTargetAddress,
	CONST( boolean, AUTOMATIC ) bImmediateBlock,
	P2VAR( uint8, AUTOMATIC, FEE_APPL_DATA ) pBlockHdrPtr
)
{
	VAR( uint32, AUTOMATIC ) u32checkSum = 0UL;
	P2VAR( uint8, AUTOMATIC, FEE_APPL_DATA ) pTargetEndPtr = NULL_PTR;
	/* PRQA S 0488 EOF # The pointer operation does not need to be modified */
	pTargetEndPtr = pBlockHdrPtr + FEE_BLOCK_OVERHEAD;

	/* Calculate the block header checksum */
	u32checkSum = ((uint32) uBlockNumber) + ((uint32) uLength) + uTargetAddress;

	/* Use MSB of the checksum for the immediate block flag so
	   the checksum is 31-bit */
	if( bImmediateBlock == (boolean)1U )
	{
		u32checkSum += 1U;
		u32checkSum |= 0x80000000U;
	}
	else
	{
		u32checkSum &= 0x7fffffffU;
	}
	FEE_SERIALIZE( uBlockNumber, uint16, pBlockHdrPtr )

	FEE_SERIALIZE( uLength, uint16, pBlockHdrPtr )

	FEE_SERIALIZE( uTargetAddress, Fls_AddressType, pBlockHdrPtr )

	FEE_SERIALIZE( u32checkSum, uint32, pBlockHdrPtr )
	/* Fill rest of the header with the erase pattern */
	for( ; pBlockHdrPtr < pTargetEndPtr; pBlockHdrPtr++ )
	{
		*pBlockHdrPtr = FEE_ERASED_VALUE;
	}
}

/**
* @brief          Check whether specified data buffer contains only
*                 the FEE_ERASED_VALUE value
*
* @param[in]      pTargetPtr     pointer to start of the checked buffer
* @param[in]      pTargetEndPtr  pointer to end + 1 of the checked buffer
*
* @return         Std_ReturnType
* @retval         E_OK           The buffer contains only erased value
* @retval         E_NOT_OK       The buffer doesn't contain only erased value
*
* @pre            pTargetPtr and pTargetEndPtr pointers must be valid
*
*/
STATIC FUNC( Std_ReturnType, FEE_CODE ) Fee_BlankCheck
(
	P2CONST( uint8, AUTOMATIC, FEE_APPL_CONST ) pTargetPtr,
	CONSTP2CONST( uint8, AUTOMATIC, FEE_APPL_CONST ) pTargetEndPtr
)
{
	VAR( Std_ReturnType, AUTOMATIC ) uRetVal = (Std_ReturnType)E_OK;

	for( ; pTargetPtr < pTargetEndPtr; pTargetPtr++ )
	{
		if( FEE_ERASED_VALUE == *pTargetPtr )
		{
			/* Pattern match */
		}
		else
		{
			uRetVal = (Std_ReturnType)E_NOT_OK;
			break;
		}
	}

	return( uRetVal );
}

/**
* @brief        Deserialize the valid or invalid flag from a read buffer
*
* @param[in]    pTargetPtr       Pointer to the read buffer
* @param[in]    u8FlagPattern    FEE_VALIDATED_VALUE or FEE_INVALIDATED_VALUE
* @param[out]   pFlagValue        TRUE if flag of above type is set
*
* @return       Std_ReturnType
* @retval       E_OK             The flag is set or cleared and rest of the read buffer
*                               (FEE_VIRTUAL_PAGE_SIZE - 1) contains FEE_ERASED_VALUE
* @retval       E_NOT_OK         Buffer doesn't contain valid flag data. It's garbled...
*
* @pre          pTargetPtr and pFlagValue pointers must be valid
*
*/
STATIC FUNC( Std_ReturnType, FEE_CODE ) Fee_DeserializeFlag
(
	CONSTP2CONST( uint8, AUTOMATIC, FEE_APPL_CONST ) pTargetPtr,
	CONST( uint8, AUTOMATIC ) u8FlagPattern,
	P2VAR( boolean, AUTOMATIC, FEE_APPL_DATA ) pFlagValue
)
{
	VAR( Std_ReturnType, AUTOMATIC ) uRetVal = (Std_ReturnType)E_OK;

	if( (u8FlagPattern == *pTargetPtr) || ( FEE_ERASED_VALUE == *pTargetPtr ))
	{
		/* The bytePattern can be either present or not */
		if( u8FlagPattern == *pTargetPtr )
		{
			*pFlagValue = (boolean)TRUE;
		}
		else
		{
			*pFlagValue = (boolean)FALSE;
		}

		/* Check rest of the FEE_VIRTUAL_PAGE_SIZE */
		uRetVal = Fee_BlankCheck( pTargetPtr+1, pTargetPtr+FEE_VIRTUAL_PAGE_SIZE );
	}
	else
	{
		uRetVal = (Std_ReturnType)E_NOT_OK;
	}

	return( uRetVal );
}

/**
* @brief        Deserialize Fee block header parameters from read buffer
*
* @param[out]   pBlockNumber             Fee block number
* @param[out]   pLength                  Size of Fee block in bytes
* @param[out]   pTargetAddress           Logical address of Fee block in Fls adress space
* @param[out]   pImmediateBlock          Type of Fee block. Set to TRUE for immediate block
* @param[in]    pBlockHdrPtr             Pointer to read buffer
*
* @return       Fee_BlockStatusType
* @retval       FEE_BLOCK_VALID          Fee block is valid
* @retval       FEE_BLOCK_INVALID        Fee block is invalid (has been invalidated)
* @retval       FEE_BLOCK_INCONSISTENT   Fee block is inconsistent, it may contain corrupted data...
* @retval       FEE_BLOCK_HEADER_INVALID Fee block header is invalid (garbled)
* @retval       FEE_BLOCK_HEADER_BLANK   Fee block header is filled with FEE_ERASED_VALUE
*
* @pre          pBlockHdrPtr             pointer must be valid
*
*/
STATIC FUNC( Fee_BlockStatusType, FEE_CODE ) Fee_DeserializeBlockHdr
(
	CONSTP2VAR( uint16, AUTOMATIC, FEE_APPL_DATA ) pBlockNumber,
	CONSTP2VAR( uint16, AUTOMATIC, FEE_APPL_DATA ) pLength,
	CONSTP2VAR( Fls_AddressType, AUTOMATIC, FEE_APPL_DATA ) pTargetAddress,
	CONSTP2VAR( boolean, AUTOMATIC, FEE_APPL_DATA ) pImmediateBlock,
	P2CONST( uint8, AUTOMATIC, FEE_APPL_CONST ) pBlockHdrPtr
)
{
	VAR( Fee_BlockStatusType, AUTOMATIC ) eRetVal = FEE_BLOCK_HEADER_INVALID;
	VAR( uint32, AUTOMATIC ) u32ReadCheckSum = 0UL;
	VAR( uint32, AUTOMATIC ) u32CalcCheckSum = 0UL;
	P2CONST( uint8, AUTOMATIC, FEE_APPL_CONST ) pTargetEndPtr = NULL_PTR;
	VAR( boolean, AUTOMATIC ) bFlagValid = (boolean)FALSE;
	VAR( boolean, AUTOMATIC ) bFlagInvalid = (boolean)FALSE;
	VAR( uint8, AUTOMATIC ) u8ReservedSpace = 0U;

	if( Fee_BlankCheck( pBlockHdrPtr, pBlockHdrPtr+FEE_BLOCK_OVERHEAD ) == ((Std_ReturnType)E_OK) )
	{
		eRetVal = FEE_BLOCK_HEADER_BLANK;
	}
	else
	{
		/* Check 1st part of the header */
		pTargetEndPtr = (pBlockHdrPtr + FEE_BLOCK_OVERHEAD) - (2U * FEE_VIRTUAL_PAGE_SIZE);
		/* PRQA S 0310 , 0311 EOF # The pointer operation does not need to be modified */
		FEE_DESERIALIZE( pBlockHdrPtr, *pBlockNumber, uint16 )

		FEE_DESERIALIZE( pBlockHdrPtr, *pLength, uint16 )

		FEE_DESERIALIZE( pBlockHdrPtr, *pTargetAddress, Fls_AddressType )

		FEE_DESERIALIZE( pBlockHdrPtr, u32ReadCheckSum, uint32 )
		 /* pBlockHdrPtr must be advanced with 1 bytes.
		  * the reason is to avoid blank check for this area reserved for blockAssignment even when
		  * SWAP_FOREIGN is disabled to allow disabling SWAP_FOREIGN at production time. */
		FEE_DESERIALIZE( pBlockHdrPtr, u8ReservedSpace, uint8)
		/* variable u8ReservedSpace not used */
		(void)u8ReservedSpace;
		/* Use MSB of checksum for immediate block flag so
			the checksum is 31-bit long */
		u32CalcCheckSum = *pLength + *pTargetAddress + *pBlockNumber;

		if( 0U == (u32ReadCheckSum & 0x80000000U) )
		{
			*pImmediateBlock = (boolean)FALSE;
		}
		else
		{
			*pImmediateBlock = (boolean)TRUE;
			u32CalcCheckSum += 1U;
		}

		/* Ignore MSB since it's used for ImmediateBlock flag */
		if( (u32ReadCheckSum & 0x7fffffffU) != (u32CalcCheckSum & 0x7fffffffU) )
		{
			/* FEE_BLOCK_HEADER_INVALID */
		}
		else if( ((Std_ReturnType)E_OK) != Fee_BlankCheck( pBlockHdrPtr, pTargetEndPtr ) )
		{
			/* FEE_BLOCK_HEADER_INVALID */
		}
		else if( ((Std_ReturnType)E_OK) !=
				 Fee_DeserializeFlag( pTargetEndPtr, FEE_VALIDATED_VALUE, &bFlagValid )
			   )
		{
			/* FEE_BLOCK_HEADER_INVALID */
		}
		else if( ((Std_ReturnType)E_OK) !=
				 Fee_DeserializeFlag( pTargetEndPtr+FEE_VIRTUAL_PAGE_SIZE,
									  FEE_INVALIDATED_VALUE, &bFlagInvalid \
									)
			   )
		{
			/* FEE_BLOCK_HEADER_INVALID */
		}
		else
		{
			/* Block header is valid */
			if( ((boolean)FALSE == bFlagValid) && ((boolean)FALSE == bFlagInvalid) )
			{
				eRetVal = FEE_BLOCK_INCONSISTENT;
			}
			else if( ((boolean)TRUE == bFlagValid) && ((boolean)FALSE == bFlagInvalid) )
			{
				eRetVal = FEE_BLOCK_VALID;
			}
			else
			{
				eRetVal = FEE_BLOCK_INVALID;
			}
		}
	}

	return( eRetVal );
}

/**
* @brief        Deserialize Fee cluster header parameters from read buffer
*
* @param[out]   pClrID                     32-bit cluster ID
* @param[out]   pStartAddress              Logical address of Fee cluster in Fls address space
* @param[out]   pClusteSize                Size of Fee cluster in bytes
* @param[in]    pClrHdrPtr                 Pointer to read buffer
*
* @return       Fee_ClusterStatusType
* @retval       FEE_CLUSTER_VALID          Fee cluster is valid
* @retval       FEE_CLUSTER_INVALID        Fee cluster has been invalidated
* @retval       FEE_CLUSTER_INCONSISTENT   Fee cluster is inconsistent, it may
*                                          contain corrupted data
* @retval       FEE_CLUSTER_HEADER_INVALID Fee cluster header is invalid (garbled)
*
* @pre          pClrHdrPtr pointer must be valid
*
*/
STATIC FUNC( Fee_ClusterStatusType, FEE_CODE ) Fee_DeserializeClusterHdr
(
	CONSTP2VAR( uint32, AUTOMATIC, FEE_APPL_DATA ) pClrID,
	CONSTP2VAR( Fls_AddressType, AUTOMATIC, FEE_APPL_DATA ) pStartAddress,
	CONSTP2VAR( Fls_LengthType, AUTOMATIC, FEE_APPL_DATA ) pClusteSize,
	P2CONST( uint8, AUTOMATIC, FEE_APPL_CONST ) pClrHdrPtr
)
{
	VAR( Fee_ClusterStatusType, AUTOMATIC ) eRetVal = FEE_CLUSTER_HEADER_INVALID;
	VAR( uint32, AUTOMATIC ) u32CheckSum = 0UL;
	VAR( boolean, AUTOMATIC ) bFlagValid = (boolean)FALSE;
	VAR( boolean, AUTOMATIC ) bFlagInvalid = (boolean)FALSE;
	P2CONST( uint8, AUTOMATIC, FEE_APPL_CONST ) pTargetEndPtr = NULL_PTR;

	/* Check 1st part of the header */
	pTargetEndPtr = (pClrHdrPtr + FEE_CLUSTER_OVERHEAD) - (2U * FEE_VIRTUAL_PAGE_SIZE);

	FEE_DESERIALIZE( pClrHdrPtr, *pClrID, uint32 )

	FEE_DESERIALIZE( pClrHdrPtr, *pStartAddress, Fls_AddressType )

	FEE_DESERIALIZE( pClrHdrPtr, *pClusteSize, Fls_LengthType )

	FEE_DESERIALIZE( pClrHdrPtr, u32CheckSum, uint32 )

	if( (*pClrID+*pStartAddress+*pClusteSize) != u32CheckSum )
	{
		/* FEE_CLUSTER_HEADER_INVALID */
	}
	else if( ((Std_ReturnType)E_OK) != Fee_BlankCheck( pClrHdrPtr, pTargetEndPtr ) )
	{
		/* FEE_CLUSTER_HEADER_INVALID */
	}
	else if( ((Std_ReturnType)E_OK) !=
			 Fee_DeserializeFlag( pTargetEndPtr, FEE_VALIDATED_VALUE, &bFlagValid )
		   )
	{
		/* FEE_CLUSTER_HEADER_INVALID */
	}
	else if( ((Std_ReturnType)E_OK) !=
			 Fee_DeserializeFlag( pTargetEndPtr+FEE_VIRTUAL_PAGE_SIZE,
								  FEE_INVALIDATED_VALUE, &bFlagInvalid)
		   )
	{
		/* FEE_CLUSTER_HEADER_INVALID */
	}
	else
	{
		if( ((boolean)FALSE == bFlagValid) && ((boolean)FALSE == bFlagInvalid) )
		{
			eRetVal = FEE_CLUSTER_INCONSISTENT;
		}
		if( ((boolean)TRUE == bFlagValid) && ((boolean)FALSE == bFlagInvalid) )
		{
			eRetVal = FEE_CLUSTER_VALID;
		}
		else
		{
			eRetVal = FEE_CLUSTER_INVALID;
		}
	}

	return( eRetVal );
}

/**
* @brief        Serialize        Fee cluster header parameters to write buffer
*
* @param[in]    uClrID           32-bit cluster ID
* @param[in]    uStartAddress    Logical address of Fee cluster in Fls address space
* @param[in]    uClusteSize      Size of Fee cluster in bytes
* @param[out]   pClrHdrPtr       Pointer to write buffer
*
* @pre          pClrHdrPtr       pointer must be valid
*
*/
STATIC FUNC( void, FEE_CODE ) Fee_SerializeClusterHdr
(
	CONST( uint32, AUTOMATIC ) uClrID,
	CONST( Fls_AddressType, AUTOMATIC) uStartAddress,
	CONST( Fls_LengthType, AUTOMATIC) uClusteSize,
	P2VAR( uint8, AUTOMATIC, FEE_APPL_DATA ) pClrHdrPtr
)
{
	VAR( uint32, AUTOMATIC ) u32CheckSum = 0UL;
	P2VAR( uint8, AUTOMATIC, FEE_APPL_DATA ) pTargetEndPtr = NULL_PTR;

	pTargetEndPtr = pClrHdrPtr + FEE_CLUSTER_OVERHEAD;

	/* Calculate the cluster header checksum */
	u32CheckSum = uClrID + uStartAddress + uClusteSize;

	FEE_SERIALIZE( uClrID, uint32, pClrHdrPtr )

	FEE_SERIALIZE( uStartAddress, Fls_AddressType, pClrHdrPtr )

	FEE_SERIALIZE( uClusteSize, Fls_LengthType, pClrHdrPtr )

	FEE_SERIALIZE( u32CheckSum, uint32, pClrHdrPtr )

	/* Fill rest of the header with the erase pattern */
	for( ; pClrHdrPtr < pTargetEndPtr; pClrHdrPtr++ )
	{
		*pClrHdrPtr = FEE_ERASED_VALUE;
	}
}

/**
* @brief        Searches ordered list of Fee blocks and returns index of block
*               with matching BlockNumber
*
* @param[in]    uBlockNumber             Fee block number (FeeBlockNumber)
*
* @return       uint16
* @retval       Fee block index
* @retval       0xFFFF if uBlockNumber is invalid
*
*/
STATIC FUNC( uint16, FEE_CODE ) Fee_GetBlockIndex( CONST( uint16, AUTOMATIC ) uBlockNumber )
{
	VAR( sint32, AUTOMATIC ) sLow = 0L;
	VAR( sint32, AUTOMATIC ) sHigh = (sint32)FEE_NUMBER_OF_BLOCKS - 1;
	VAR( sint32, AUTOMATIC ) sMiddle = 0;
	VAR( uint16, AUTOMATIC ) uRetVal = 0xFFFFU;

	while( sLow <= sHigh )
	{
		sMiddle = sLow + (( sHigh - sLow ) / 2);

		if( uBlockNumber < Fee_BlockConfig[sMiddle].FeeBlockNumber )
		{
			sHigh = sMiddle - 1;
		}
		else if( uBlockNumber > Fee_BlockConfig[sMiddle].FeeBlockNumber )
		{
			sLow = sMiddle + 1;
		}
		else
		{
			uRetVal = (uint16)sMiddle;
			break;
		}
	}

	return( uRetVal );
}

/**
* @brief  Returns the block size for a block specified by its index in the Fee_aBlockInfo array
*
* @param[in]      uBlockRuntimeInfoIndex     index in the Fee_aBlockInfo array
* @return         uint16
* @retval         block size
* @pre            -
*/
LOCAL_INLINE FUNC( uint16, FEE_CODE ) Fee_GetBlockSize(CONST( uint16, AUTOMATIC ) uBlockRuntimeInfoIndex)
{
	VAR(uint16, AUTOMATIC) uBlockSize = 0U;

	/* the config is part of Fee_BlockConfig*/
	uBlockSize = Fee_BlockConfig[uBlockRuntimeInfoIndex].FeeBlockSize;

	return uBlockSize;
}
/**
* @brief  Returns the block number for a block specified by its index in the Fee_aBlockInfo array
*
* @param[in]      uBlockRuntimeInfoIndex     index in the Fee_aBlockInfo array
* @return         uint16
* @retval         block number
* @pre            -
*/
LOCAL_INLINE FUNC( uint16, FEE_CODE ) Fee_GetBlockNumber(CONST( uint16, AUTOMATIC ) uBlockRuntimeInfoIndex)
{
	VAR(uint16, AUTOMATIC) uBlockNumber = 0U;

	/* the config is part of Fee_BlockConfig*/
	uBlockNumber = Fee_BlockConfig[uBlockRuntimeInfoIndex].FeeBlockNumber;

	return uBlockNumber;
}
/**
* @brief  Returns the immediate attribute for a block specified by its index in the Fee_aBlockInfo array
*
* @param[in]      uBlockRuntimeInfoIndex     index in the Fee_aBlockInfo array
* @return         boolean
* @retval         value of the immediate attribute
* @pre            -
*/
LOCAL_INLINE FUNC( boolean, FEE_CODE ) Fee_GetBlockImmediate(CONST( uint16, AUTOMATIC ) uBlockRuntimeInfoIndex)
{
	VAR(boolean, AUTOMATIC) bImmediate = (boolean)FALSE;

	/* the config is part of Fee_BlockConfig*/
	bImmediate = Fee_BlockConfig[uBlockRuntimeInfoIndex].FeeImmediateData;

	return bImmediate;
}
/**
* @brief        Adjusts passed size so it's integer multiple of pre-configured +
*               FEE_VIRTUAL_PAGE_SIZE
*
* @param[in]    uBlockSize        Fee block size (FeeBlockSize)
*
* @return       uint16
* @retval       Adjusted         Fee block size to integer multiple    of FEE_VIRTUAL_PAGE_SIZE
*
*/
STATIC FUNC( uint16, FEE_CODE ) Fee_AlignToVirtualPageSize( VAR( uint16, AUTOMATIC ) uBlockSize )
{
	/* Check whether the block size is integer multiple
		of FEE_VIRTUAL_PAGE_SIZE */
	if( 0U == (uBlockSize % FEE_VIRTUAL_PAGE_SIZE) )
	{
		/* block size is an integer multiple of FEE_VIRTUAL_PAGE_SIZE */
	}
	else
	{
		uBlockSize = ((uBlockSize / FEE_VIRTUAL_PAGE_SIZE) + 1U) *
						 FEE_VIRTUAL_PAGE_SIZE;
	}

	return( (uint16)uBlockSize );
}

/**
* @brief        Copy data from user to internal write buffer and fills
*               rest of the write buffer with FEE_ERASED_VALUE
*
* @param[in]    pSourcePtr        Pointer to user data buffer
* @param[out]   pTargetPtr        Pointer to internal write buffer
* @param[in]    uLength           Number of bytes to copy
*
* @pre          pSourcePtr and pTargetPtr must be valid pointers
* @pre          uLength must be <= FEE_VIRTUAL_PAGE_SIZE
*
*/
STATIC FUNC( void, FEE_CODE ) Fee_CopyDataToPageBuffer
(
	P2CONST( uint8, AUTOMATIC, FEE_APPL_CONST ) pSourcePtr,
	P2VAR( uint8, AUTOMATIC, FEE_APPL_DATA ) pTargetPtr,
	CONST( uint16, AUTOMATIC ) uLength
)
{
	P2VAR( uint8, AUTOMATIC, FEE_APPL_DATA ) pTargetEndPtr = pTargetPtr + uLength;

	P2VAR( uint8, AUTOMATIC, FEE_APPL_DATA ) pPageEndPtr = pTargetPtr + FEE_VIRTUAL_PAGE_SIZE;

	/* Copy data to page buffer */
	for( ; pTargetPtr < pTargetEndPtr; pTargetPtr++ )
	{
		*pTargetPtr = *pSourcePtr;
		pSourcePtr++;
	}

	/* Fill rest of the page buffer with FEE_ERASED_VALUE */
	for( ; pTargetPtr < pPageEndPtr; pTargetPtr++ )
	{
		*pTargetPtr = FEE_ERASED_VALUE;
	}
}

/**
* @brief        Serialize validation or invalidation flag to write buffer
*
* @param[out]   pTargetPtr       Pointer to write buffer
* @param[in]    u8FlagPattern    FEE_VALIDATED_VALUE or FEE_INVALIDATED_VALUE
*
* @pre          pTargetPtr        must be valid pointer
*
*/
STATIC FUNC( void, FEE_CODE ) Fee_SerializeFlag
(
	P2VAR( uint8, AUTOMATIC, FEE_APPL_DATA ) pTargetPtr,
	CONST( uint8, AUTOMATIC ) u8FlagPattern
)
{
	P2VAR( uint8, AUTOMATIC, FEE_APPL_DATA ) pTargetEndPtr = pTargetPtr + FEE_VIRTUAL_PAGE_SIZE;

	*pTargetPtr = u8FlagPattern;

	for( pTargetPtr++ ; pTargetPtr < pTargetEndPtr; pTargetPtr++ )
	{
		*pTargetPtr = FEE_ERASED_VALUE;
	}
}

/**
* @brief        Validate current Fee cluster in current Fee cluster group by
*               writing FEE_VALIDATED_VALUE into flash
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the write job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept the write
*                                        job
*
* @pre          Fee_uJobIntClrGrpIt must contain index of current cluster group
* @pre          Fee_uJobIntClrIt must contain index of current cluster
* @post         Schedule the FEE_JOB_INT_SWAP_CLR_VLD_DONE subsequent job
*
*/
STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntSwapClrVld( void )
{
	VAR( MemIf_JobResultType, AUTOMATIC ) eRetVal = MEMIF_JOB_OK;
	VAR( Fls_AddressType, AUTOMATIC ) uStartAddr = 0UL;
	/* PRQA S 0491 EOF # The logarithmic group is not required to handle special processing */
	/* Get start address of swap cluster */
	uStartAddr = Fee_ClrGrps[Fee_GlobalPar.Fee_uJobIntClrGrpIt]. \
			Fee_ClusterConfig[Fee_GlobalPar.Fee_uJobIntClrIt].Fee_ClrStartAddr;

	/* Serialize validation pattern to write buffer */
	Fee_SerializeFlag( Fee_aDataBuffer, FEE_VALIDATED_VALUE );

	/* Write validation pattern to flash */
	if( ((Std_ReturnType)E_OK) ==
			Fls_Write( (uStartAddr+FEE_CLUSTER_OVERHEAD )-(2U*FEE_VIRTUAL_PAGE_SIZE),
					   Fee_aDataBuffer, FEE_VIRTUAL_PAGE_SIZE
					 )
	  )
	{
		/* Fls write job has been accepted */
		eRetVal = MEMIF_JOB_PENDING;
	}
	else
	{
		/* Fls write job hasn't been accepted */
		eRetVal = MEMIF_JOB_FAILED;
	}

	/* Schedule subsequent Fee job */
	Fee_InterRunInfor.Fee_eJob = FEE_JOB_INT_SWAP_CLR_VLD_DONE;

	return( eRetVal );
}

/**
* @brief        Copy next block from source to target cluster
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING Underlying Fls accepted the write job
* @retval       MEMIF_JOB_FAILED Underlying Fls didn't accept the write job
*
* @pre          Fee_uJobIntBlockIt       must contain index of currently swaped
*                                        Fee block
* @pre          Fee_uJobBlockIndex       must contain index of Fee block which
*                                        caused the swap
* @pre          Fee_uJobIntClrGrpIt       must contain index of current cluster
*                                        group
* @pre          Fee_uJobIntHdrAddr       must contain valid address of Fee block
*                                        header in target cluster
*
* @post         Fee_uJobIntHdrAddr is advanced on to next Fee block
* @post         Schedule the FEE_JOB_INT_SWAP_DATA_READ, FEE_JOB_INT_SWAP_BLOCK,
* or            FEE_JOB_INT_SWAP_CLR_VLD_DONE subsequent job
*
* @implements   Fee_JobIntSwapBlock_Activity
*/
STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntSwapBlock( void )
{
	VAR( MemIf_JobResultType, AUTOMATIC ) eRetVal = MEMIF_JOB_OK;
	VAR( Fls_AddressType, AUTOMATIC ) uDataAddr = 0UL;
	VAR( uint16, AUTOMATIC ) uBlockSize = 0U;
	VAR( uint16, AUTOMATIC ) uAlignedBlockSize = 0U;
	VAR( uint16, AUTOMATIC ) uBlockNumber = 0U;
	VAR( uint8, AUTOMATIC ) uBlockClusterGrp = 0U;
	VAR( boolean, AUTOMATIC ) bImmediateBlock = (boolean)FALSE;

	/* Find first valid or inconsistent block in same cluster group */
	for( ; Fee_GlobalPar.Fee_uJobIntBlockIt < FEE_NUMBER_OF_BLOCKS; Fee_GlobalPar.Fee_uJobIntBlockIt++ )
	{
		/* get cluster group */
		uBlockClusterGrp = Fee_GetBlockClusterGrp(Fee_GlobalPar.Fee_uJobIntBlockIt);
		/* process only valid and inconsistent blocks from the current cluster */
		if ((Fee_GlobalPar.Fee_uJobIntClrGrpIt == uBlockClusterGrp) &&
			((FEE_BLOCK_VALID == Fee_aBlockInfo[Fee_GlobalPar.Fee_uJobIntBlockIt].eBlockStatus) ||
			 (FEE_BLOCK_INCONSISTENT == Fee_aBlockInfo[Fee_GlobalPar.Fee_uJobIntBlockIt].eBlockStatus) ||
			 (FEE_BLOCK_INCONSISTENT_COPY == Fee_aBlockInfo[Fee_GlobalPar.Fee_uJobIntBlockIt].eBlockStatus)))
		{
			break;
		}
		else
		{
			/* No match. Try next one... */
		}
	}
	if( FEE_NUMBER_OF_BLOCKS == Fee_GlobalPar.Fee_uJobIntBlockIt )
	{
		/* No more matching blocks. Validate the cluster */
		eRetVal = Fee_JobIntSwapClrVld();
	}
	else
	{
		uBlockSize = Fee_GetBlockSize(Fee_GlobalPar.Fee_uJobIntBlockIt);
		bImmediateBlock = Fee_GetBlockImmediate(Fee_GlobalPar.Fee_uJobIntBlockIt);
		uBlockNumber = Fee_GetBlockNumber(Fee_GlobalPar.Fee_uJobIntBlockIt);

		/* Data space no more allocated even for inconsistent immediate (pre-erased) blocks */
		if( FEE_BLOCK_VALID == Fee_aBlockInfo[Fee_GlobalPar.Fee_uJobIntBlockIt].eBlockStatus )
		{
			/* Align Fee block size to the virtual page boundary */
			uAlignedBlockSize = Fee_AlignToVirtualPageSize( uBlockSize );

			/* Calculate data address */
			uDataAddr = Fee_GlobalPar.Fee_uJobIntDataAddr - uAlignedBlockSize;

			/* Update the block address info */
			Fee_GlobalPar.Fee_uJobIntDataAddr = uDataAddr;

			/* Initialize the data transfer iterator */
			Fee_GlobalPar.Fee_uJobIntAddrIt = uDataAddr;
		}
		else
		{
			uDataAddr = 0U;
		}
		/* Serialize block header to the write buffer */
		Fee_SerializeBlockHdr( uBlockNumber,
							   uBlockSize, uDataAddr,
							   bImmediateBlock,
							   Fee_aDataBuffer
							 );

		if( FEE_BLOCK_VALID == Fee_aBlockInfo[Fee_GlobalPar.Fee_uJobIntBlockIt].eBlockStatus )
		{
			/* Read block data */
			Fee_InterRunInfor.Fee_eJob = FEE_JOB_INT_SWAP_DATA_READ;
		}
		else
		{
			/* Nothing to read. Move on to next block */
			Fee_GlobalPar.Fee_uJobIntBlockIt++;
			Fee_InterRunInfor.Fee_eJob = FEE_JOB_INT_SWAP_BLOCK;
		}

		/* Write header to flash */
		if( ((Std_ReturnType)E_OK) !=
				Fls_Write( Fee_GlobalPar.Fee_uJobIntHdrAddr, Fee_aDataBuffer,
						   FEE_BLOCK_OVERHEAD-(2U*FEE_VIRTUAL_PAGE_SIZE))
		  )
		{
			/* Fls write job hasn't been accepted */
			eRetVal = MEMIF_JOB_FAILED;
		}
		else
		{
			/* Fls write job has been accepted */
			eRetVal = MEMIF_JOB_PENDING;
		}

		/* Move on to next block header */
		Fee_GlobalPar.Fee_uJobIntHdrAddr += FEE_BLOCK_OVERHEAD;
	}

	return( eRetVal );
}

/**
* @brief        Format current Fee cluster in current Fee cluster group by
*               writing cluster header into flash
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the write job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept the write
*                                        job
*
* @pre          Fee_uJobIntClrGrpIt      must contain index of current cluster
*                                        group
* @pre          Fee_uJobIntClrIt         must contain index of current cluster
* @post         Schedule the FEE_JOB_INT_SWAP_BLOCK subsequent job
*
*
*/
STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntSwapClrFmt( void )
{
	VAR( MemIf_JobResultType, AUTOMATIC ) eRetVal = MEMIF_JOB_OK;
	VAR( Fls_AddressType, AUTOMATIC ) uStartAddr = 0UL;
	VAR( Fls_LengthType, AUTOMATIC ) uLength = 0UL;
	VAR( uint32, AUTOMATIC ) uActClrID = 0UL;

	uStartAddr = Fee_ClrGrps[Fee_GlobalPar.Fee_uJobIntClrGrpIt]. \
			Fee_ClusterConfig[Fee_GlobalPar.Fee_uJobIntClrIt].Fee_ClrStartAddr;

	uLength = Fee_ClrGrps[Fee_GlobalPar.Fee_uJobIntClrGrpIt]. \
			Fee_ClusterConfig[Fee_GlobalPar.Fee_uJobIntClrIt].Fee_Clrlength;
	uActClrID = Fee_aClrGrpInfo[Fee_GlobalPar.Fee_uJobIntClrGrpIt].uActClrID;

	/* Build cluster header with new uActClrID + 1 */
	Fee_SerializeClusterHdr( uActClrID+1U, uStartAddr, uLength, Fee_aDataBuffer );

	/* Write the cluster header to flash */
	if( ((Std_ReturnType)E_OK) ==
			Fls_Write( uStartAddr, Fee_aDataBuffer,
					   FEE_CLUSTER_OVERHEAD-(2U*FEE_VIRTUAL_PAGE_SIZE))
	  )
	{
		/* Fls read job has been accepted */
		eRetVal = MEMIF_JOB_PENDING;
	}
	else
	{
		/* Fls write job hasn't been accepted */
		eRetVal = MEMIF_JOB_FAILED;
	}

	/* Schedule cluster format done job */
	Fee_InterRunInfor.Fee_eJob = FEE_JOB_INT_SWAP_BLOCK;

	return( eRetVal );
}

/**
* @brief        Erase current Fee cluster in current Fee cluster group by erasing flash
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the erase job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept the erase job
*
* @pre          Fee_uJobIntClrGrpIt      must contain index of current cluster group
* @pre          Fee_uJobIntClrIt        must contain index of current cluster
* @post         Schedule the FEE_JOB_INT_SWAP_CLR_FMT subsequent job
*
*
*/
STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntSwapClrErase( void )
{
	VAR( MemIf_JobResultType, AUTOMATIC ) eRetVal = MEMIF_JOB_OK;
	VAR( Fls_AddressType, AUTOMATIC ) uStartAddr = 0UL;
	VAR( Fls_LengthType, AUTOMATIC ) uLength = 0UL;

	uStartAddr = Fee_ClrGrps[Fee_GlobalPar.Fee_uJobIntClrGrpIt]. \
			Fee_ClusterConfig[Fee_GlobalPar.Fee_uJobIntClrIt].Fee_ClrStartAddr;

	uLength = Fee_ClrGrps[Fee_GlobalPar.Fee_uJobIntClrGrpIt]. \
			Fee_ClusterConfig[Fee_GlobalPar.Fee_uJobIntClrIt].Fee_Clrlength;

	/* Erase cluster */
	if( ((Std_ReturnType)E_OK) == Fls_Erase( uStartAddr, uLength ) )
	{
		/* Fls read job has been accepted */
		eRetVal = MEMIF_JOB_PENDING;
	}
	else
	{
		/* Fls read job hasn't been accepted */
		eRetVal = MEMIF_JOB_FAILED;
	}

	/* Schedule cluster format job */
	Fee_InterRunInfor.Fee_eJob = FEE_JOB_INT_SWAP_CLR_FMT;

	return( eRetVal );
}

/**
* @brief        Initialize the cluster swap internal operation on
*               current cluster group
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the erase job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept the erase job
*
* @pre          Fee_uJobIntClrGrpIt      must contain index of current cluster group
* @pre          Fee_eJob                 must contain type of Fee job which caused the cluster swap
*
* @post         Fee module status is set to MEMIF_BUSY_INTERNAL
* @post         Fee_eJob is stored in Fee_eJobIntOriginalJob so it can be rescheduled
*               once the swap operation is finished
* @post         Fee internal block iterator Fee_uJobIntBlockIt is set to zero
* @post         Fee internal cluster iterator Fee_uJobIntClrIt is set to
*               the target cluster
* @post         Fee_uJobIntHdrAddr and Fee_uJobIntDataAddr addresses are initialized to
*               point to the target cluster
* @post         Schedule erase of the target cluster
*
*
*/
STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntSwap( void )
{
	VAR( MemIf_JobResultType, AUTOMATIC ) eRetVal = MEMIF_JOB_OK;

	/* Store type of original job so Fee can re-schedule
		this job once the swap is complete */
	Fee_InterRunInfor.Fee_eJobIntOriginalJob = Fee_InterRunInfor.Fee_eJob;

	/* Reset the block iterator */
	Fee_GlobalPar.Fee_uJobIntBlockIt = 0U;

	/* Get cluster index the block belongs to */
	Fee_GlobalPar.Fee_uJobIntClrIt = Fee_aClrGrpInfo[Fee_GlobalPar.Fee_uJobIntClrGrpIt].uActClr;

	/* Calculate index of cluster to swap to */
	Fee_GlobalPar.Fee_uJobIntClrIt++;

	if( Fee_GlobalPar.Fee_uJobIntClrIt ==
			Fee_ClrGrps[Fee_GlobalPar.Fee_uJobIntClrGrpIt].Fee_ClusterCounter )
	{
		/* Cluster roll over */
		Fee_GlobalPar.Fee_uJobIntClrIt = 0U;
	}
	else
	{
		/* Do nothing */
	}

	/* Calculate header and data address iterators */
	Fee_GlobalPar.Fee_uJobIntHdrAddr =
		Fee_ClrGrps[Fee_GlobalPar.Fee_uJobIntClrGrpIt]. \
		Fee_ClusterConfig[Fee_GlobalPar.Fee_uJobIntClrIt].Fee_ClrStartAddr;

	Fee_GlobalPar.Fee_uJobIntDataAddr = Fee_GlobalPar.Fee_uJobIntHdrAddr +
		Fee_ClrGrps[Fee_GlobalPar.Fee_uJobIntClrGrpIt]. \
		Fee_ClusterConfig[Fee_GlobalPar.Fee_uJobIntClrIt].Fee_Clrlength;

	/* Move on to the first block header */
	Fee_GlobalPar.Fee_uJobIntHdrAddr += FEE_CLUSTER_OVERHEAD;

	/* Erase the swap cluster */
	eRetVal = Fee_JobIntSwapClrErase();

	return( eRetVal );
}

/**
* @brief        Read the Fee block header into internal buffer
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING Underlying Fls accepted the read job
* @retval       MEMIF_JOB_FAILED Underlying Fls didn't accept the read job
*
* @pre          Fee_uJobIntAddrIt must contain valid logical address of
*               Fee block header to read
* @post         Schedule the FEE_JOB_INT_SCAN_CLR_PARSE subsequent job
*
*/
STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntScanBlockHdrRead( void )
{
	VAR( MemIf_JobResultType, AUTOMATIC ) eRetVal = MEMIF_JOB_OK;

	/* Read the block header */
	if( ((Std_ReturnType)E_OK) !=
			Fls_Read( Fee_GlobalPar.Fee_uJobIntAddrIt, Fee_aDataBuffer, FEE_BLOCK_OVERHEAD )
	  )
	{
		/* Fls read job hasn't been accepted */
		eRetVal = MEMIF_JOB_FAILED;
	}
	else
	{
		/* Fls read job has been accepted */
		eRetVal = MEMIF_JOB_PENDING;
	}

	Fee_InterRunInfor.Fee_eJob = FEE_JOB_INT_SCAN_BLOCK_HDR_PARSE;

	return( eRetVal );
}

/**
* @brief        Erase first Fee cluster in current cluster group
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the erase job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept the erase
*                                        job
*
* @pre          Fee_uJobIntClrGrpIt must contain index of current Fee cluster
*               group
* @post         Schedule the FEE_JOB_INT_SCAN_CLR_FMT subsequent job
*
*/
STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntScanClrErase( void )
{
	VAR( MemIf_JobResultType, AUTOMATIC ) eRetVal = MEMIF_JOB_OK;
	VAR( Fls_AddressType, AUTOMATIC ) uStartAddr = 0UL;
	VAR( Fls_LengthType, AUTOMATIC ) uLength = 0UL;

	/* Get address and size of first cluster in the current cluster group */
	uStartAddr = Fee_ClrGrps[Fee_GlobalPar.Fee_uJobIntClrGrpIt]. \
			Fee_ClusterConfig[0].Fee_ClrStartAddr;

	uLength = Fee_ClrGrps[Fee_GlobalPar.Fee_uJobIntClrGrpIt]. \
			Fee_ClusterConfig[0].Fee_Clrlength;

	if( ((Std_ReturnType)E_OK) == Fls_Erase( uStartAddr, uLength ) )
	{
		/* Fls read job has been accepted */
		eRetVal = MEMIF_JOB_PENDING;
	}
	else
	{
		/* Fls read job hasn't been accepted */
		eRetVal = MEMIF_JOB_FAILED;
	}

	/* Schedule cluster format job */
	Fee_InterRunInfor.Fee_eJob = FEE_JOB_INT_SCAN_CLR_FMT;

	return( eRetVal );
}

/**
* @brief        Scan active cluster of current cluster group or erase and format
*               first cluster if an active cluster can't be found
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the erase or read job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept the erase or read job
* @retval       MEMIF_JOB_OK             There is no more cluster groups to scan
*
* @pre          Fee_uJobIntClrGrpIt must contain index of current Fee cluster group
* @post         Initialize the Fee_uJobIntAddrIt iterator to address of
*               the first Fee block header to scan
* @post         Initialize the uHdrAddrIt and uDataAddrIt iterators to addresses of
*               the first Fee block header and data block
* @post         Schedule the FEE_JOB_DONE, FEE_JOB_INT_SCAN_CLR_FMT,
*               FEE_JOB_INT_SCAN_CLR_PARSE subsequent job
*
*/
STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntScanClr( void )
{
	VAR( MemIf_JobResultType, AUTOMATIC ) eRetVal = MEMIF_JOB_OK;
	VAR( uint8, AUTOMATIC ) uClrIndex = (uint8)0;
	VAR( Fls_AddressType , AUTOMATIC ) uClrStartAddr = 0UL;
	VAR( Fls_LengthType , AUTOMATIC ) uClrLength = 0UL;

	if( FEE_NUMBER_OF_CLUSTER_GROUPS == Fee_GlobalPar.Fee_uJobIntClrGrpIt )
	{
		/* Nor more cluster groups to scan */
		Fee_InterRunInfor.Fee_eJob = FEE_JOB_DONE;
	}
	else
	{
		if( 0U == Fee_aClrGrpInfo[Fee_GlobalPar.Fee_uJobIntClrGrpIt].uActClrID )
		{
			/* No active cluster found in current group so erase and format
				the first one... */
			eRetVal = Fee_JobIntScanClrErase();
		}
		else
		{
			/* Active cluster found */
			/* Get index of active cluster */
			uClrIndex = Fee_aClrGrpInfo[Fee_GlobalPar.Fee_uJobIntClrGrpIt].uActClr;

			uClrStartAddr = Fee_ClrGrps[Fee_GlobalPar.Fee_uJobIntClrGrpIt]. \
					Fee_ClusterConfig[uClrIndex].Fee_ClrStartAddr;

			/* Calculate logical address of first block header in active cluster */
			Fee_GlobalPar.Fee_uJobIntAddrIt = FEE_CLUSTER_OVERHEAD + uClrStartAddr;

			/* Initialize the block header pointer */
			Fee_aClrGrpInfo[Fee_GlobalPar.Fee_uJobIntClrGrpIt].uHdrAddrIt =
					Fee_GlobalPar.Fee_uJobIntAddrIt;

			/* Initialize the block data pointer */
			uClrLength = Fee_ClrGrps[Fee_GlobalPar.Fee_uJobIntClrGrpIt]. \
					Fee_ClusterConfig[uClrIndex].Fee_Clrlength;
			Fee_aClrGrpInfo[Fee_GlobalPar.Fee_uJobIntClrGrpIt].uDataAddrIt =
					uClrStartAddr + uClrLength;

			/* Active cluster found so read the first block header */
			eRetVal = Fee_JobIntScanBlockHdrRead();
		}
	}

	return( eRetVal );
}

/**
* @brief        Format first Fee cluster in current Fee cluster group by writing
*               cluster header into flash
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the erase job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept the erase
*                                        job
*
* @pre          Fee_uJobIntClrGrpIt must contain index of current Fee cluster
*               group
* @post         Schedule the FEE_JOB_INT_SCAN_CLR_FMT_DONE subsequent job
*
*/
STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntScanClrFmt( void )
{
	VAR( MemIf_JobResultType, AUTOMATIC ) eRetVal = MEMIF_JOB_OK;
	VAR( Fls_AddressType, AUTOMATIC ) uStartAddr = 0UL;
	VAR( Fls_LengthType, AUTOMATIC ) uLength = 0UL;

	/* Get address and size of first cluster in the current cluster group */
	uStartAddr = Fee_ClrGrps[Fee_GlobalPar.Fee_uJobIntClrGrpIt]. \
			Fee_ClusterConfig[0].Fee_ClrStartAddr;

	uLength = Fee_ClrGrps[Fee_GlobalPar.Fee_uJobIntClrGrpIt]. \
			Fee_ClusterConfig[0].Fee_Clrlength;

	/* Build cluster header with clusterID = 1 */
	Fee_SerializeClusterHdr( 1U, uStartAddr, uLength, Fee_aDataBuffer );

	/* Make the cluster valid right away as it's empty anyway... */
	Fee_SerializeFlag( (Fee_aDataBuffer+FEE_CLUSTER_OVERHEAD)-(2U*FEE_VIRTUAL_PAGE_SIZE),
					   FEE_VALIDATED_VALUE);

	/* Write the cluster header to flash */
	if( ((Std_ReturnType)E_OK) ==
			Fls_Write( uStartAddr, Fee_aDataBuffer,
					   FEE_CLUSTER_OVERHEAD-FEE_VIRTUAL_PAGE_SIZE)
	  )
	{
		/* Fls read job has been accepted */
		eRetVal = MEMIF_JOB_PENDING;
	}
	else
	{
		/* Fls write job hasn't been accepted */
		eRetVal = MEMIF_JOB_FAILED;
	}

	/* Schedule cluster format done job */
	Fee_InterRunInfor.Fee_eJob = FEE_JOB_INT_SCAN_CLR_FMT_DONE;

	return( eRetVal );
}

/**
* @brief        Finalize format of first Fee cluster in current Fee cluster group
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the erase or
*                                        read job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept the erase
*                                        or read job
* @retval       MEMIF_JOB_OK             There is no more cluster groups to scan
*
* @pre          Fee_uJobIntClrGrpIt must contain index of current Fee cluster
*               group
* @post         Assign index (uActClr) and ID (uActClrID) of active cluster in
*               current cluster group
* @post         Initialize the uHdrAddrIt and uDataAddrIt iterators to addresses
*               of
*               the first Fee block header and data block
* @post         Advance the Fee_uJobIntClrGrpIt iterator to next cluster group
* @post         Schedule the FEE_JOB_DONE, FEE_JOB_INT_SCAN_CLR_FMT,
*               FEE_JOB_INT_SCAN_CLR_PARSE subsequent job
*
*/
STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntScanClrFmtDone( void )
{
	VAR( MemIf_JobResultType, AUTOMATIC ) eRetVal = MEMIF_JOB_OK;
	VAR( Fls_AddressType , AUTOMATIC ) uClrStartAddr = 0UL;
	VAR( Fls_LengthType , AUTOMATIC ) uClrLength = 0UL;

	/* Assign Index and ID of active cluster */
	Fee_aClrGrpInfo[Fee_GlobalPar.Fee_uJobIntClrGrpIt].uActClr = 0U;
	Fee_aClrGrpInfo[Fee_GlobalPar.Fee_uJobIntClrGrpIt].uActClrID = 1U;

	uClrStartAddr = Fee_ClrGrps[Fee_GlobalPar.Fee_uJobIntClrGrpIt]. \
			Fee_ClusterConfig[0].Fee_ClrStartAddr;

	uClrLength = Fee_ClrGrps[Fee_GlobalPar.Fee_uJobIntClrGrpIt]. \
			Fee_ClusterConfig[0].Fee_Clrlength;

	/* Initialize the block header pointer */
	Fee_aClrGrpInfo[Fee_GlobalPar.Fee_uJobIntClrGrpIt].uHdrAddrIt =
		uClrStartAddr + FEE_CLUSTER_OVERHEAD;

	/* Initialize the block data pointer */
	Fee_aClrGrpInfo[Fee_GlobalPar.Fee_uJobIntClrGrpIt].uDataAddrIt = uClrStartAddr + uClrLength;

	/* Move on to next cluster group */
	Fee_GlobalPar.Fee_uJobIntClrGrpIt++;

	/* Scan next cluster group if any */
	eRetVal = Fee_JobIntScanClr();

	return( eRetVal );
}

/**
* @brief        Parse Fee block header
*
* @param[in]    bBufferValid             FALSE if previous Fls read job has failed
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the erase or
*                                        read job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept the erase
*                                        or read job
* @retval       MEMIF_JOB_OK             There is no more cluster groups to scan
*
* @pre          Fee_uJobIntClrGrpIt      must contain index of current Fee
*                                        cluster group
*
* @post         Initialize internal recovery swap operation in case of bogus
*               Fee block header or failure of previous read job (perhaps ECC failure..)
* @post         Advance the Fee_uJobIntClrGrpIt iterator to next cluster group in
*               case of blank Fee block header (end of header list)
* @post         Update the eBlockStatus, uDataAddr, and uInvalidAddr block
*               information and the uHdrAddrIt and uDataAddrIt iterators in case of valid
*               Fee block header
* @post         Schedule the FEE_JOB_INT_SCAN_CLR_PARSE subsequent job in case
*               of valid Fee block header
*
*
*/
STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntScanBlockHdrParse
(
	CONST( boolean, AUTOMATIC ) bBufferValid
)
{
	VAR( MemIf_JobResultType, AUTOMATIC ) eRetVal = MEMIF_JOB_FAILED;
	VAR( Fee_BlockStatusType, AUTOMATIC ) eBlockStatus;
	VAR( uint16, AUTOMATIC ) uBlockNumber = 0U;
	VAR( uint16, AUTOMATIC ) uBlockSize = 0U;
	VAR( Fls_AddressType, AUTOMATIC ) uDataAddr = 0UL;
	VAR( boolean, AUTOMATIC ) bImmediateData = (boolean)FALSE;
	VAR( uint16, AUTOMATIC ) uBlockIndex = 0U;
	VAR( uint16, AUTOMATIC ) uAlignedBlockSize = 0U;
	VAR( uint16, AUTOMATIC ) uBlockRuntimeInfoIndex = 0U;

	/* Internal variable used to trigger a cluster swap. Used by the swap job. */
	static VAR( boolean, AUTOMATIC) bSwapToBePerformed = (boolean)FALSE;
	VAR( boolean, AUTOMATIC) bFeeSwapNeeded = (boolean)FALSE;

	/* Deserialize block header from read buffer */
	eBlockStatus =
		Fee_DeserializeBlockHdr( &uBlockNumber, &uBlockSize, &uDataAddr,  &bImmediateData,Fee_aDataBuffer);

	if( (FEE_BLOCK_HEADER_INVALID  == eBlockStatus) || ((boolean)FALSE == bBufferValid))
	{
		/* Invalidate the block index so Fee won't skip
			the Fee_uJobBlockIndex block */
		Fee_GlobalPar.Fee_uJobBlockIndex = 0xffffU;

		/* Move on to next block header */
		Fee_GlobalPar.Fee_uJobIntAddrIt += FEE_BLOCK_OVERHEAD;

		/* Update the block header pointer */
		Fee_aClrGrpInfo[Fee_GlobalPar.Fee_uJobIntClrGrpIt].uHdrAddrIt = Fee_GlobalPar.Fee_uJobIntAddrIt;

		/* Set swap-to-be-performed flag */
		bSwapToBePerformed = (boolean)TRUE;

		/* Read next header */
		eRetVal = Fee_JobIntScanBlockHdrRead();

	}
	else if( FEE_BLOCK_HEADER_BLANK  == eBlockStatus )
	{
		/* If SwapToBePerformed is set, it means that last header is corrupted and
		   ONLY now the uDataAddrIt variable will be updated to cause swap. */
		if( ((boolean)TRUE) == bSwapToBePerformed )
		{
		   bSwapToBePerformed = (boolean)FALSE;
		   Fee_aClrGrpInfo[Fee_GlobalPar.Fee_uJobIntClrGrpIt].uDataAddrIt = Fee_GlobalPar.Fee_uJobIntAddrIt +
															   (2U * FEE_BLOCK_OVERHEAD);
		}

		/* End of header list so move on to next cluster group */
		Fee_GlobalPar.Fee_uJobIntClrGrpIt++;

		eRetVal = Fee_JobIntScanClr();
	}
	else
	{
		/* Look for found block in the block configuration */
		uBlockIndex = Fee_GetBlockIndex( uBlockNumber );

		if( 0xFFFFU != uBlockIndex)
		{
			/* prepare index to be used for the runtime info data*/
			uBlockRuntimeInfoIndex = uBlockIndex;

			uAlignedBlockSize = Fee_AlignToVirtualPageSize( uBlockSize );

			/* Check whether found block belongs to current cluster group,
				and its size and type match the configuration,
				and its data pointer points to an acceptable area
			*/
			bFeeSwapNeeded = (boolean)FALSE;

			if ((uDataAddr <=(Fee_aClrGrpInfo[Fee_GlobalPar.Fee_uJobIntClrGrpIt].uDataAddrIt-uAlignedBlockSize)) &&
				(uDataAddr >= (Fee_aClrGrpInfo[Fee_GlobalPar.Fee_uJobIntClrGrpIt].uHdrAddrIt+(2U*FEE_BLOCK_OVERHEAD)))
			   )
			{
				if((Fee_BlockConfig[uBlockIndex].FeeClrGrpIndex == Fee_GlobalPar.Fee_uJobIntClrGrpIt) &&
				   (Fee_BlockConfig[uBlockIndex].FeeBlockSize == uBlockSize) &&
				   (Fee_BlockConfig[uBlockIndex].FeeImmediateData == bImmediateData)
				  )
				{
					bFeeSwapNeeded = (boolean)FALSE;
				}
				else
				{
					bFeeSwapNeeded = (boolean)TRUE;
				}
			}
			else
			{
				bFeeSwapNeeded = (boolean)TRUE;
			}
			/* check if swap is needed */
			if( (boolean)FALSE == bFeeSwapNeeded )
			{
				/* Update block run-time information */
				Fee_aBlockInfo[uBlockRuntimeInfoIndex].eBlockStatus = eBlockStatus;

				 /* Update the block data pointer */
				Fee_aBlockInfo[uBlockRuntimeInfoIndex].uDataAddr = uDataAddr;

				Fee_aBlockInfo[uBlockRuntimeInfoIndex].uInvalidAddr =
					(Fee_GlobalPar.Fee_uJobIntAddrIt + FEE_BLOCK_OVERHEAD) - FEE_VIRTUAL_PAGE_SIZE;

				Fee_aClrGrpInfo[Fee_GlobalPar.Fee_uJobIntClrGrpIt].uDataAddrIt = uDataAddr;
			}
			else
			{
				/* Block header doesn't match Fee config or the FEE algorithm...
				   during next write cluster swap occurs */
				bSwapToBePerformed = (boolean)TRUE;
			}
		}
		else
		{
			/* Invalid block number (removed from Fee config...) next write cluster swap occurs */
			bSwapToBePerformed = (boolean)TRUE;
		}

		/* Move on to next block header */
		Fee_GlobalPar.Fee_uJobIntAddrIt += FEE_BLOCK_OVERHEAD;

		/* Update the block header pointer */
		Fee_aClrGrpInfo[Fee_GlobalPar.Fee_uJobIntClrGrpIt].uHdrAddrIt = Fee_GlobalPar.Fee_uJobIntAddrIt;

		/* Read next header */
		eRetVal = Fee_JobIntScanBlockHdrRead();
	}

	return( eRetVal );
}

/**
* @brief        Read Fee cluster header
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the read job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept read job
*
* @pre          Fee_uJobIntClrGrpIt must contain index of current Fee cluster group
* @pre          Fee_uJobIntClrIt must contain index of current Fee cluster
* @post         Schedule the FEE_JOB_INT_SCAN_CLR_HDR_PARSE subsequent job
*
*/
STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntScanClrHdrRead( void )
{
	VAR( MemIf_JobResultType, AUTOMATIC ) eRetVal = MEMIF_JOB_OK;
	VAR( Fls_AddressType, AUTOMATIC ) uReadAddress = 0UL;

	/* Get address of current cluster */
	uReadAddress = Fee_ClrGrps[Fee_GlobalPar.Fee_uJobIntClrGrpIt]. \
			Fee_ClusterConfig[Fee_GlobalPar.Fee_uJobIntClrIt]. \
			Fee_ClrStartAddr;

	if( ((Std_ReturnType)E_OK) != Fls_Read( uReadAddress, Fee_aDataBuffer, FEE_CLUSTER_OVERHEAD  ) )
	{
		/* Fls read job hasn't been accepted */
		eRetVal = MEMIF_JOB_FAILED;
	}
	else
	{
		/* Fls read job has been accepted */
		eRetVal = MEMIF_JOB_PENDING;
	}

	/* Schedule cluster scan job */
	Fee_InterRunInfor.Fee_eJob = FEE_JOB_INT_SCAN_CLR_HDR_PARSE;

	return( eRetVal );
}

/**
* @brief        Initialize the cluster scan job
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the read job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept read job
*
* @post         Reset the Fee_uJobIntClrGrpIt and Fee_uJobIntClrIt iterators
* @post         Schedule the FEE_JOB_INT_SCAN_CLR_HDR_PARSE subsequent job
*
*/
STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntScan( void )
{
	VAR( MemIf_JobResultType, AUTOMATIC ) eRetVal = MEMIF_JOB_OK;

	/* Reset iterators to first cluster of first cluster group */
	Fee_GlobalPar.Fee_uJobIntClrGrpIt = 0U;
	Fee_GlobalPar.Fee_uJobIntClrIt = 0U;

	/* Schedule reading of first cluster header */
	eRetVal = Fee_JobIntScanClrHdrRead();

	return( eRetVal );
}

/**
* @brief        Parse Fee cluster header
*
* @param[in]    bBufferValid             FALSE if previous Fls read job has failed
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the erase or read job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept the erase or read job
*
* @pre          Fee_uJobIntClrGrpIt must contain index of current Fee cluster group
* @pre          Fee_uJobIntClrIt must contain index of current cluster
* @post         Update the Fee_uJobIntClrIt and/or Fee_uJobIntClrGrpIt iterators to move
*               into next cluster and/or cluster group and read next cluster header if
*               there is any
* @post         Scan first active cluster if Fee is done with reading the cluster headers
* @post         Schedule the FEE_JOB_DONE, FEE_JOB_INT_SCAN_CLR_FMT,
*               FEE_JOB_INT_SCAN_CLR_PARSE, FEE_JOB_INT_SCAN_CLR_HDR_PARSE subsequent jobs
*
*/
STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntScanClrHdrParse
(
	CONST( boolean, AUTOMATIC) bBufferValid
)
{
	VAR( MemIf_JobResultType, AUTOMATIC ) eRetVal = MEMIF_JOB_OK;
	VAR( Fee_ClusterStatusType, AUTOMATIC ) eClrStatus = FEE_CLUSTER_VALID;
	VAR( uint32, AUTOMATIC ) uClrID = 0UL;
	VAR( Fls_AddressType, AUTOMATIC ) uClrStartAddr = 0UL;
	VAR( Fls_LengthType, AUTOMATIC ) uClrSize = 0UL;
	VAR( Fls_AddressType, AUTOMATIC ) uCfgStartAddr = 0UL;
	VAR( Fls_LengthType, AUTOMATIC ) uCfgClrSize = 0UL;

	/* Get configured cluster start address and size */
	uCfgStartAddr = Fee_ClrGrps[Fee_GlobalPar.Fee_uJobIntClrGrpIt]. \
			Fee_ClusterConfig[Fee_GlobalPar.Fee_uJobIntClrIt]. \
			Fee_ClrStartAddr;

	uCfgClrSize = Fee_ClrGrps[Fee_GlobalPar.Fee_uJobIntClrGrpIt]. \
			Fee_ClusterConfig[Fee_GlobalPar.Fee_uJobIntClrIt]. \
			Fee_Clrlength;

	/* Deserialize cluster parameters from the read buffer */
	eClrStatus = Fee_DeserializeClusterHdr( &uClrID, &uClrStartAddr, &uClrSize, Fee_aDataBuffer );

	if( ((boolean)TRUE == bBufferValid) && (FEE_CLUSTER_VALID == eClrStatus) &&
		(uClrStartAddr == uCfgStartAddr) && (uClrSize == uCfgClrSize) &&
		(uClrID > Fee_aClrGrpInfo[Fee_GlobalPar.Fee_uJobIntClrGrpIt].uActClrID)
	  )
	{
		/* Found valid and active cluster */
		Fee_aClrGrpInfo[Fee_GlobalPar.Fee_uJobIntClrGrpIt].uActClr = Fee_GlobalPar.Fee_uJobIntClrIt;
		Fee_aClrGrpInfo[Fee_GlobalPar.Fee_uJobIntClrGrpIt].uActClrID = uClrID;
	}
	else
	{
		/* Invalid, inconsistent, or cluster with low ID */
	}

	/* Move on to next cluster */
	Fee_GlobalPar.Fee_uJobIntClrIt++;

	if( Fee_GlobalPar.Fee_uJobIntClrIt == Fee_ClrGrps[Fee_GlobalPar.Fee_uJobIntClrGrpIt].Fee_ClusterCounter )
	{
		/* Move on to next cluster group */
		Fee_GlobalPar.Fee_uJobIntClrGrpIt++;
		Fee_GlobalPar.Fee_uJobIntClrIt = 0U;
	}
	else
	{
		/* next cluster in current cluster group */
	}

	if( FEE_NUMBER_OF_CLUSTER_GROUPS == Fee_GlobalPar.Fee_uJobIntClrGrpIt )
	{
		Fee_GlobalPar.Fee_uJobIntClrGrpIt = 0U;
		/* Done reading all cluster headers. Now scan active clusters */
		eRetVal = Fee_JobIntScanClr();
	}
	else
	{
		/* Read next cluster header */
		eRetVal = Fee_JobIntScanClrHdrRead();
	}

	return( eRetVal );
}

/**
* @brief        Read Fee block
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the read job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept read job
* @retval       MEMIF_BLOCK_INVALID      Requested Fee block is invalid
* @retval       MEMIF_BLOCK_INCONSISTENT Requested Fee block is inconsistent
*
* @pre          Fee_uJobBlockIndex must contain index of requested Fee block
* @pre          Fee_uJobBlockOffset must contain offset in requested Fee block
* @pre          Fee_uJobBlockLength must contain number of bytes to read from requested Fee block
* @post         Schedule the FEE_JOB_DONE    subsequent job
*
* @implements   Fee_JobRead_Activity
*/
STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobRead( void )
{
	VAR( MemIf_JobResultType, AUTOMATIC ) eRetVal = MEMIF_JOB_FAILED;
	VAR( Fee_BlockStatusType, AUTOMATIC ) eBlockStatus = FEE_BLOCK_VALID;
	VAR( Fls_AddressType, AUTOMATIC ) uBlockAddress = 0UL;

	eBlockStatus = Fee_aBlockInfo[Fee_GlobalPar.Fee_uJobBlockIndex].eBlockStatus;
	uBlockAddress = Fee_aBlockInfo[Fee_GlobalPar.Fee_uJobBlockIndex].uDataAddr;

	if( FEE_BLOCK_VALID == eBlockStatus )
	{

		if( ((Std_ReturnType)E_OK) != Fls_Read( uBlockAddress+Fee_GlobalPar.Fee_uJobBlockOffset,
						  Fee_pJobReadDataDestPtr, Fee_GlobalPar.Fee_uJobBlockLength)
		  )
		{
			/* Fls read job hasn't been accepted */
			eRetVal = MEMIF_JOB_FAILED;
		}
		else
		{
			/* Fls read job has been accepted */
			eRetVal = MEMIF_JOB_PENDING;
		}
	}
	else if( FEE_BLOCK_NEVER_WRITTEN == eBlockStatus )
	{
		/* in case the block was never written */
		eRetVal = MEMIF_BLOCK_INCONSISTENT;
	}
	else if( FEE_BLOCK_INVALID == eBlockStatus )
	{
		eRetVal = MEMIF_BLOCK_INVALID;
	}
	else if( (FEE_BLOCK_INCONSISTENT == eBlockStatus) || (FEE_BLOCK_INCONSISTENT_COPY == eBlockStatus) )
	{
		/* No special treatment of immediate blocks needed anymore */
		eRetVal = MEMIF_BLOCK_INCONSISTENT;
	}
	else
	{
		/* Something is wrong... MEMIF_JOB_FAILED */
	}

	/* There is no consecutive job to schedule */
	Fee_InterRunInfor.Fee_eJob = FEE_JOB_DONE;

	return( eRetVal );
}

/**
* @brief        Validate Fee block
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the write job
* @retval       MEMIF_JOB_FAILED         Underlying Fls did not accept write job
*
* @pre          Fee_uJobIntHdrAddr must contain address of Fee block header to
*               validate
* @post         Schedule the FEE_JOB_INT_SWAP_BLOCK subsequent job
*
* @implements   Fee_JobIntSwapBlockVld_Activity
*/
STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntSwapBlockVld( void )
{
	VAR( MemIf_JobResultType, AUTOMATIC ) eRetVal = MEMIF_JOB_OK;

	/* Serialize validation pattern to buffer */
	Fee_SerializeFlag( Fee_aDataBuffer, FEE_VALIDATED_VALUE );

	/* Write header to flash */
	if( ((Std_ReturnType)E_OK) != Fls_Write( Fee_GlobalPar.Fee_uJobIntHdrAddr-(2U*FEE_VIRTUAL_PAGE_SIZE),
					   Fee_aDataBuffer, FEE_VIRTUAL_PAGE_SIZE)
	  )
	{
		/* Fls read job hasn't been accepted */
		eRetVal = MEMIF_JOB_FAILED;
	}
	else
	{
		/* Fls read job has been accepted */
		eRetVal = MEMIF_JOB_PENDING;
	}

	/* Finalize the write operation */
	Fee_InterRunInfor.Fee_eJob = FEE_JOB_INT_SWAP_BLOCK;

	return( eRetVal );
}

/**
* @brief        Read data from source cluster to internal Fee buffer
*
* @param[in]    bBufferValid             FALSE if previous Fls read job has failed
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the read job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept read job
*
* @pre          Fee_uJobIntBlockIt must contain index of currently swaped
*               Fee block
* @pre          Fee_uJobIntDataAddr must contain start address of Fee data block
*               in the target cluster
* @pre          Fee_uJobIntAddrIt must contain current address of Fee data block
*               in the target cluster
* @post         Move on to next block Fee block if bBufferValid == FALSE
* @post         Validates the Fee block if there is no more data to read
* @post         Schedule the FEE_JOB_INT_SWAP_DATA_WRITE subsequent job
*
*
*/
STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntSwapDataRead
(
	CONST( boolean, AUTOMATIC) bBufferValid
)
{
	VAR( MemIf_JobResultType, AUTOMATIC ) eRetVal = MEMIF_JOB_FAILED;
	VAR( Fls_AddressType, AUTOMATIC ) uReadAddr = 0UL;
	VAR( uint16, AUTOMATIC ) uAlignedBlockSize = 0U;
	VAR( uint16, AUTOMATIC ) uBlockSize = 0U;

	/* Get size of swaped block */
	uBlockSize = Fee_GetBlockSize(Fee_GlobalPar.Fee_uJobIntBlockIt);

	/* Get size of swaped block aligned to virtual page boundary */
	uAlignedBlockSize = Fee_AlignToVirtualPageSize( uBlockSize );

	/* Calculate remaining number of bytes to read */
	Fee_GlobalPar.Fee_uJobBlockLength = (Fee_GlobalPar.Fee_uJobIntDataAddr +
			uAlignedBlockSize) - Fee_GlobalPar.Fee_uJobIntAddrIt;

	if( (boolean)FALSE == bBufferValid )
	{
		/* There was error while reading the source cluster.
		   Change the block status to FEE_BLOCK_INCONSISTENT_COPY to mark the status change
		   during swap, leave the block (in flash) INCONSITENT and move on to next block */
		Fee_aBlockInfo[Fee_GlobalPar.Fee_uJobIntBlockIt].eBlockStatus = FEE_BLOCK_INCONSISTENT_COPY;

		Fee_GlobalPar.Fee_uJobIntBlockIt++;

		eRetVal = Fee_JobIntSwapBlock();
	}
	else if( 0U == Fee_GlobalPar.Fee_uJobBlockLength )
	{
		/* No more bytes to copy. Validate the block and
			move on to next block... */
		Fee_GlobalPar.Fee_uJobIntBlockIt++;

		eRetVal = Fee_JobIntSwapBlockVld();
	}
	else
	{
		if( Fee_GlobalPar.Fee_uJobBlockLength > FEE_DATA_BUFFER_SIZE )
		{
			Fee_GlobalPar.Fee_uJobBlockLength = FEE_DATA_BUFFER_SIZE;
		}
		else
		{
			/* Block data fits into the buffer */
		}

		/* Calculate source address */
		uReadAddr = (Fee_aBlockInfo[Fee_GlobalPar.Fee_uJobIntBlockIt].uDataAddr +
				Fee_GlobalPar.Fee_uJobIntAddrIt) -
				Fee_GlobalPar.Fee_uJobIntDataAddr;

		/* Read the block data */
		if( ((Std_ReturnType)E_OK) != Fls_Read( uReadAddr, Fee_aDataBuffer,
				Fee_GlobalPar.Fee_uJobBlockLength ) )
		{
			/* Fls read job hasn't been accepted */
			eRetVal = MEMIF_JOB_FAILED;
		}
		else
		{
			/* Fls read job has been accepted */
			eRetVal = MEMIF_JOB_PENDING;
		}

		Fee_InterRunInfor.Fee_eJob = FEE_JOB_INT_SWAP_DATA_WRITE;
	}

	return( eRetVal );
}

/**
* @brief        Write data from internal Fee buffer to target cluster
*
* @param[in]    bBufferValid              FALSE if previous Fls read job has failed
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING         Underlying Fls accepted the write job
* @retval       MEMIF_JOB_FAILED          Underlying Fls didn't accept write job
*
* @pre          Fee_uJobBlockLength       must contain size of data block being
*                                         transfered(up to FEE_DATA_BUFFER_SIZE)
* @pre          Fee_uJobIntAddrIt         must contain current address of Fee
*                                         data block in the target cluster
* @post         Update the Fee_uJobIntAddrIt data iterator for next data
*               transfer if any
* @post         Schedule the FEE_JOB_INT_SWAP_DATA_READ subsequent job
*
*
*/
STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntSwapDataWrite
(
	CONST( boolean, AUTOMATIC ) bBufferValid
)
{
	VAR( MemIf_JobResultType, AUTOMATIC ) eRetVal = MEMIF_JOB_OK;

	if( bBufferValid == (boolean)1U )
	{
		if( ((Std_ReturnType)E_OK) ==
				Fls_Write( Fee_GlobalPar.Fee_uJobIntAddrIt,
						Fee_aDataBuffer, Fee_GlobalPar.Fee_uJobBlockLength )
		  )
		{
			/* Fls read job has been accepted */
			eRetVal = MEMIF_JOB_PENDING;
		}
		else
		{
			/* Fls write job hasn't been accepted */
			eRetVal = MEMIF_JOB_FAILED;
		}

		Fee_GlobalPar.Fee_uJobIntAddrIt += Fee_GlobalPar.Fee_uJobBlockLength;

		Fee_InterRunInfor.Fee_eJob = FEE_JOB_INT_SWAP_DATA_READ;
	}
	else
	{
		eRetVal = Fee_JobIntSwapDataRead( (boolean)FALSE );
	}

	return( eRetVal );
}

/**
* @brief        Finalize cluster validation
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING Underlying Fls accepted the write job
* @retval       MEMIF_JOB_FAILED Underlying Fls didn't accept write job
*
* @pre          Fee_uJobIntClrGrpIt must contain index of current Fee cluster
*               group
* @pre          Fee_uJobIntClrIt must contain index of current cluster
* @post         Update the uDataAddr and uInvalidAddr Fee_BlockConfig variables of
*               all affected (swaped) Fee blocks
* @post         Update uActClr, uActClrID, uHdrAddrIt, uDataAddrIt Fee_aClrGrpInfo
*               variables of current cluster group
* @post         Change Fee module status from MEMIF_BUSYINTERNAL to MEMIF_BUSY
* @post         Re-schedule the Fee_eJobIntOriginalJob subsequent job
*
* @implements   Fee_JobIntSwapClrVldDone_Activity
*/
STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntSwapClrVldDone( void )
{
	VAR( MemIf_JobResultType, AUTOMATIC ) eRetVal = MEMIF_JOB_OK;
	VAR( uint16, AUTOMATIC ) uBlockIt = 0U;
	VAR( Fls_AddressType, AUTOMATIC ) uHdrAddrIt = 0UL;
	VAR( Fls_AddressType, AUTOMATIC ) uDataAddrIt = 0UL;
	VAR( uint16, AUTOMATIC ) uBlockSize = 0U;
	VAR( uint16, AUTOMATIC ) uAlignedBlockSize = 0U;
	VAR( uint8, AUTOMATIC ) uBlockClusterGrp = 0U;

	uHdrAddrIt = Fee_ClrGrps[Fee_GlobalPar.Fee_uJobIntClrGrpIt]. \
			Fee_ClusterConfig[Fee_GlobalPar.Fee_uJobIntClrIt]. \
			Fee_ClrStartAddr;

	uDataAddrIt = uHdrAddrIt + Fee_ClrGrps[Fee_GlobalPar.Fee_uJobIntClrGrpIt]. \
			Fee_ClusterConfig[Fee_GlobalPar.Fee_uJobIntClrIt]. \
			Fee_Clrlength;

	/* Move on to the first block header */
	uHdrAddrIt += FEE_CLUSTER_OVERHEAD;

	/* Sync block info */

   for( uBlockIt = 0U; uBlockIt < FEE_NUMBER_OF_BLOCKS; uBlockIt++ )
	{
		uBlockClusterGrp = Fee_GetBlockClusterGrp(uBlockIt);

		if(Fee_GlobalPar.Fee_uJobIntClrGrpIt == uBlockClusterGrp)
		{
			/* Valid blocks and inconsistent blocks with allocated data were copied,
			   update the block info and internal pointers accordingly.
			*/
			if( (FEE_BLOCK_VALID == Fee_aBlockInfo[uBlockIt].eBlockStatus) ||
				(FEE_BLOCK_INCONSISTENT == Fee_aBlockInfo[uBlockIt].eBlockStatus) ||
				(FEE_BLOCK_INCONSISTENT_COPY == Fee_aBlockInfo[uBlockIt].eBlockStatus)
			  )
			{
				/* Sync uInvalidAddr */
				Fee_aBlockInfo[uBlockIt].uInvalidAddr = (uHdrAddrIt + FEE_BLOCK_OVERHEAD) -
														 FEE_VIRTUAL_PAGE_SIZE;
				/* check if block is immediate */
				/* Update the block data address info */
				if( (FEE_BLOCK_VALID == Fee_aBlockInfo[ uBlockIt ].eBlockStatus) ||
					(FEE_BLOCK_INCONSISTENT_COPY == Fee_aBlockInfo[ uBlockIt ].eBlockStatus)
				  )
				{
					uBlockSize = Fee_GetBlockSize(uBlockIt);
					/* Align block size to the virtual page boundary */
					uAlignedBlockSize = Fee_AlignToVirtualPageSize( uBlockSize );
					/* "Allocate" data already swapped (written to the flash) */
					uDataAddrIt -= uAlignedBlockSize;
					if( FEE_BLOCK_INCONSISTENT_COPY == Fee_aBlockInfo[ uBlockIt ].eBlockStatus )
					{
						/* Damaged data read during copy, but already allocated => inconsistent */
						Fee_aBlockInfo[ uBlockIt ].eBlockStatus = FEE_BLOCK_INCONSISTENT;
						/* Mark inconsistency in the runtime info (no data) for the next swap attempt */
						Fee_aBlockInfo[uBlockIt].uDataAddr = 0U;
					}
					else
					{
						/* store the data address to the block runtime record */
						Fee_aBlockInfo[uBlockIt].uDataAddr = uDataAddrIt;
					}
				}
				else
				{
					/* (Inconsistent plain block in LEGACY == ON) or
					   (Inconsistent plain or immediate block in LEGACY == OFF)
					    -- no data written (swapped, allocated)/available */
					Fee_aBlockInfo[uBlockIt].uDataAddr = 0U;
				}

				/* Advance the header pointer */
				uHdrAddrIt += FEE_BLOCK_OVERHEAD;
			}
			else
			{
				/* Not a usable block */
				/* clear the addresses of the block not present in the new active cluster */
				Fee_aBlockInfo[uBlockIt].uDataAddr = 0U;
				Fee_aBlockInfo[uBlockIt].uInvalidAddr = 0U;
			}
		}
	}

	/* Switch to the new cluster */
	Fee_aClrGrpInfo[Fee_GlobalPar.Fee_uJobIntClrGrpIt].uActClr = Fee_GlobalPar.Fee_uJobIntClrIt;
	Fee_aClrGrpInfo[Fee_GlobalPar.Fee_uJobIntClrGrpIt].uActClrID++;
	Fee_aClrGrpInfo[Fee_GlobalPar.Fee_uJobIntClrGrpIt].uHdrAddrIt = uHdrAddrIt;
	Fee_aClrGrpInfo[Fee_GlobalPar.Fee_uJobIntClrGrpIt].uDataAddrIt = uDataAddrIt;

	/* restore original Fee_eJob */
	if( FEE_JOB_INT_SCAN_CLR == Fee_InterRunInfor.Fee_eJobIntOriginalJob )
	{
		Fee_GlobalPar.Fee_uJobIntClrGrpIt++;
	}
	else
	{
		/* Do nothing */
	}

	/* Internal job has finished so transition from MEMIF_BUSYINTERNAL to MEMIF_BUSY */
	Fee_InterRunInfor.Fee_eModuleStatus = MEMIF_BUSY;

	/* And now cross fingers and re-schedule original job ... */
	Fee_InterRunInfor.Fee_eJob = Fee_InterRunInfor.Fee_eJobIntOriginalJob;

	eRetVal = Fee_JobSchedule();

	return( eRetVal );
}

/**
* @brief        Write Fee block header to flash
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the write job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept write job
*
* @pre          Fee_uJobBlockIndex must contain index of Fee block to write to
* @post         Update the uDataAddr and uInvalidAddr Fee_BlockConfig variables of
*               written Fee block
* @post         Initialize internal cluster swap sequence if requested block
*               doesn't fit into current cluster
*
* @implements   Fee_JobWriteHdr_Activity
*/
STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobWriteHdr( void )
{
	VAR( MemIf_JobResultType, AUTOMATIC ) eRetVal = MEMIF_JOB_FAILED;
	VAR( uint16, AUTOMATIC ) uBlockSize = 0U;
	VAR( uint16, AUTOMATIC ) uAlignedBlockSize = 0U;
	VAR( uint8, AUTOMATIC ) uClrGrpIndex = (uint8)0;
	VAR( Fls_AddressType, AUTOMATIC ) uDataAddr = 0U;
	VAR( Fls_AddressType, AUTOMATIC ) uHdrAddr = 0U;

	/* Index of cluster group the Fee block belongs to */
	uClrGrpIndex = Fee_BlockConfig[Fee_GlobalPar.Fee_uJobBlockIndex].FeeClrGrpIndex;

	/* Get size of Fee block */
	uBlockSize = Fee_BlockConfig[Fee_GlobalPar.Fee_uJobBlockIndex].FeeBlockSize;

	/* Align Fee block size to the virtual page boundary */
	uAlignedBlockSize = Fee_AlignToVirtualPageSize( uBlockSize );

	if( (boolean)FALSE == (boolean)Fee_ReservedAreaWritable() )
	{
		/* Get cluster group index the block belongs to */
		Fee_GlobalPar.Fee_uJobIntClrGrpIt = uClrGrpIndex;

		eRetVal = Fee_JobIntSwap();
	}
	else
	{
		/* Calculate data and header addresses */
		uDataAddr = Fee_aClrGrpInfo[uClrGrpIndex].uDataAddrIt - uAlignedBlockSize;
		uHdrAddr = Fee_aClrGrpInfo[uClrGrpIndex].uHdrAddrIt;

		/* Serialize block header to the write buffer */
		Fee_SerializeBlockHdr( Fee_BlockConfig[Fee_GlobalPar.Fee_uJobBlockIndex].FeeBlockNumber,
							   uBlockSize, uDataAddr,
							   Fee_BlockConfig[Fee_GlobalPar.Fee_uJobBlockIndex].FeeImmediateData,
							   Fee_aDataBuffer);

		/* Write header to flash */
		if( ((Std_ReturnType)E_OK) !=
				Fls_Write( uHdrAddr, Fee_aDataBuffer,
						   FEE_BLOCK_OVERHEAD-(2U*FEE_VIRTUAL_PAGE_SIZE))
		  )
		{
			/* Fls read job hasn't been accepted */
			eRetVal = MEMIF_JOB_FAILED;
		}
		else
		{
			/* Fls read job has been accepted */
			eRetVal = MEMIF_JOB_PENDING;
		}
	}
	return( eRetVal );
}


/**
* @brief        Write Fee block data to flash
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the write job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept write job
*
* @pre          Fee_uJobBlockIndex       must contain index of Fee block to
*                                        write to
* @pre          Fee_pJobWriteDataDestPtr must contain valid pointer to user
*                                        buffer
* @post         Update uHdrAddrIt, uDataAddrIt Fee_aClrGrpInfo variables of current
*               cluster group if FeeImmediateData == FALSE only
* @post         Changes eBlockStatus to FEE_BLOCK_INCONSISTENT
* @post         Schedule either FEE_JOB_WRITE_VALIDATE or
*               FEE_JOB_WRITE_UNALIGNED_DATA subsequent job
*
* @implements   Fee_JobWriteData_Activity
*/
STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobWriteData( void )
{
	VAR( Fls_AddressType, AUTOMATIC ) uDataAddr = (Fls_AddressType)0;
	VAR( MemIf_JobResultType, AUTOMATIC ) eRetVal = MEMIF_JOB_OK;
	VAR( uint16, AUTOMATIC ) uBlockSize = 0U;
	VAR( uint16, AUTOMATIC ) uAlignedBlockSize = 0U;
	VAR( Fls_LengthType, AUTOMATIC ) uWriteLength = 0UL;
	VAR( uint8, AUTOMATIC ) uClrGrp = 0U;
	P2CONST( uint8, AUTOMATIC, FEE_APPL_CONST ) pWriteDataPtr = NULL_PTR;
	VAR( Fls_AddressType, AUTOMATIC ) uHdrAddr = 0U;
	VAR( uint8, AUTOMATIC ) uClrGrpIndex = (uint8)0;

	/* Index of cluster group the Fee block belongs to */
	uClrGrpIndex = Fee_BlockConfig[Fee_GlobalPar.Fee_uJobBlockIndex].FeeClrGrpIndex;

	/* Get size of Fee block */
	uBlockSize = Fee_BlockConfig[Fee_GlobalPar.Fee_uJobBlockIndex].FeeBlockSize;

	/* Align Fee block size to the virtual page boundary */
	uAlignedBlockSize = Fee_AlignToVirtualPageSize( uBlockSize );

	/* Calculate data and header addresses */
	uDataAddr = Fee_aClrGrpInfo[uClrGrpIndex].uDataAddrIt - uAlignedBlockSize;
	uHdrAddr = Fee_aClrGrpInfo[uClrGrpIndex].uHdrAddrIt;

	Fee_aBlockInfo[Fee_GlobalPar.Fee_uJobBlockIndex].uDataAddr = uDataAddr;
	Fee_aBlockInfo[Fee_GlobalPar.Fee_uJobBlockIndex].uInvalidAddr = (uHdrAddr + FEE_BLOCK_OVERHEAD) -
														  FEE_VIRTUAL_PAGE_SIZE;

	/* Mark the block as inconsistent since the block header has been written */
	Fee_aBlockInfo[Fee_GlobalPar.Fee_uJobBlockIndex].eBlockStatus = FEE_BLOCK_INCONSISTENT;

	/* Get size of Fee block */
	uBlockSize = Fee_BlockConfig[Fee_GlobalPar.Fee_uJobBlockIndex].FeeBlockSize;

	/* Align Fee block size to the virtual page boundary */
	uAlignedBlockSize = Fee_AlignToVirtualPageSize( uBlockSize );

	/* Index of cluster group the Fee block belongs to */
	uClrGrp = Fee_BlockConfig[Fee_GlobalPar.Fee_uJobBlockIndex].FeeClrGrpIndex;

	/* Header has been written so update both header and data addresses;
	   no special treatment of immediate blocks needed anymore */
	Fee_aClrGrpInfo[uClrGrp].uHdrAddrIt += FEE_BLOCK_OVERHEAD;
	Fee_aClrGrpInfo[uClrGrp].uDataAddrIt -= uAlignedBlockSize;

	if( uBlockSize < FEE_VIRTUAL_PAGE_SIZE )
	{
		/* Go through buffer... */
			Fee_CopyDataToPageBuffer( Fee_pJobWriteDataDestPtr, Fee_aDataBuffer, uBlockSize );
			pWriteDataPtr = Fee_aDataBuffer;
		uWriteLength = FEE_VIRTUAL_PAGE_SIZE;

		/* Schedule write of validation pattern */
		Fee_InterRunInfor.Fee_eJob = FEE_JOB_WRITE_VALIDATE;
	}
	else
	{
		pWriteDataPtr = Fee_pJobWriteDataDestPtr;

		if( uAlignedBlockSize == uBlockSize )
		{
			uWriteLength = uBlockSize;

			/* Schedule write of validation pattern */
			Fee_InterRunInfor.Fee_eJob = FEE_JOB_WRITE_VALIDATE;
		}
		else
		{
			uWriteLength = ((uint32)uAlignedBlockSize) - FEE_VIRTUAL_PAGE_SIZE;

			/* Schedule write of unaligned data */
			Fee_InterRunInfor.Fee_eJob = FEE_JOB_WRITE_UNALIGNED_DATA;
		}
	}

	uDataAddr = Fee_aClrGrpInfo[uClrGrp].uDataAddrIt;

	if( ((Std_ReturnType)E_OK) == Fls_Write( uDataAddr, pWriteDataPtr, uWriteLength ) )
	{
		/* Fls read job has been accepted */
		eRetVal = MEMIF_JOB_PENDING;
	}
	else
	{
		/* Fls write job hasn't been accepted */
		eRetVal = MEMIF_JOB_FAILED;
	}
	return( eRetVal );
}

/**
* @brief        Write Fee block to flash
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING Underlying Fls accepted the write job
* @retval       MEMIF_JOB_FAILED Underlying Fls didn't accept write job
*
* @pre          Fee_uJobBlockIndex must contain index of Fee block to write to
* @pre          Fee_pJobWriteDataDestPtr must contain valid pointer to user buffer
* @post         Initialize internal cluster swap sequence if requested block
*               doesn't fit into current cluster
* @post         Schedule FEE_JOB_WRITE_DATA subsequent job
*
* @implements   Fee_JobWrite_Activity
*/
STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobWrite( void )
{
	VAR( MemIf_JobResultType, AUTOMATIC ) eRetVal = MEMIF_JOB_FAILED;

	/* Write block header */
	eRetVal = Fee_JobWriteHdr();

	/* Schedule next job */
	if( FEE_JOB_INT_SWAP_CLR_FMT == Fee_InterRunInfor.Fee_eJob )
	{
		/* Block din't fit into the cluster.
		   Cluster swap has been enforced... */
	}
	else
	{
		Fee_InterRunInfor.Fee_eJob = FEE_JOB_WRITE_DATA;
	}

	return( eRetVal );
}

/**
* @brief        Write unaligned rest of Fee block data to flash
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the write job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept write job
*
* @pre          Fee_uJobBlockIndex must contain index of Fee block to write to
* @pre          Fee_pJobWriteDataDestPtr must contain valid pointer to user buffer
* @post         Schedule FEE_JOB_WRITE_VALIDATE subsequent job
*
*
*/
STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobWriteUnalignedData( void )
{
	VAR( MemIf_JobResultType, AUTOMATIC ) eRetVal = MEMIF_JOB_OK;
	VAR( Fls_AddressType, AUTOMATIC ) uDataAddr = 0U;
	VAR( uint16, AUTOMATIC ) uWriteOffset = 0U;
	VAR( uint16, AUTOMATIC ) uWriteLength = 0U;
	VAR( uint16, AUTOMATIC ) uBlockSize = 0U;

	/* Get size of Fee block */
	uBlockSize = Fee_BlockConfig[Fee_GlobalPar.Fee_uJobBlockIndex].FeeBlockSize;

	/* Calculate number of bytes already written */
	uWriteOffset = (uBlockSize / FEE_VIRTUAL_PAGE_SIZE) * FEE_VIRTUAL_PAGE_SIZE;

	/* Calculate Fee_Clrlength remaining data to write */
	uWriteLength = uBlockSize % FEE_VIRTUAL_PAGE_SIZE;

	Fee_CopyDataToPageBuffer( Fee_pJobWriteDataDestPtr+uWriteOffset, Fee_aDataBuffer, uWriteLength );

	/* No special treatment of immediate data needed any more */
	/* Use Block info because it has been updated */
	uDataAddr = Fee_aBlockInfo[Fee_GlobalPar.Fee_uJobBlockIndex].uDataAddr;

	if( ((Std_ReturnType)E_OK) ==
			Fls_Write( uDataAddr+uWriteOffset, Fee_aDataBuffer, FEE_VIRTUAL_PAGE_SIZE )
	  )
	{
		/* Fls write job has been accepted */
		eRetVal = MEMIF_JOB_PENDING;
	}
	else
	{
		/* Fls write job hasn't been accepted */
		eRetVal = MEMIF_JOB_FAILED;
	}

	/* Schedule write of validation pattern */
	Fee_InterRunInfor.Fee_eJob = FEE_JOB_WRITE_VALIDATE;

	return( eRetVal );
}

/**
* @brief        Validate Fee block by writing validation flag to flash
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the write job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept write job
*
* @pre          Fee_uJobBlockIndex must contain index of Fee block to validate
* @post         Schedule FEE_JOB_WRITE_DONE subsequent job
*
* @implements   Fee_JobWriteValidate_Activity
*/
STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobWriteValidate( void )
{
	VAR( MemIf_JobResultType, AUTOMATIC ) eRetVal = MEMIF_JOB_OK;
	VAR( Fls_AddressType, AUTOMATIC ) uHdrAddr = (Fls_AddressType)0;

	/* Serialize validation pattern to buffer */
	Fee_SerializeFlag( Fee_aDataBuffer, FEE_VALIDATED_VALUE );

	/* Use Block info */
	uHdrAddr = Fee_aBlockInfo[Fee_GlobalPar.Fee_uJobBlockIndex].uInvalidAddr - FEE_VIRTUAL_PAGE_SIZE;

	/* Write validation pattern to flash */
	if( ((Std_ReturnType)E_OK) == Fls_Write( uHdrAddr, Fee_aDataBuffer, FEE_VIRTUAL_PAGE_SIZE) )
	{
		/* Fls read job has been accepted */
		eRetVal = MEMIF_JOB_PENDING;
	}
	else
	{
		/* Fls write job hasn't been accepted */
		eRetVal = MEMIF_JOB_FAILED;
	}

	/* Finalize the write operation */
	Fee_InterRunInfor.Fee_eJob = FEE_JOB_WRITE_DONE;

	return( eRetVal );
}

/**
* @brief        Finalize validation of Fee block
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_OK
*
* @pre          Fee_uJobBlockIndex must contain index of Fee block to write to
* @post         change Fee block status to FEE_BLOCK_VALID
* @post         Schedule FEE_JOB_DONE subsequent job
*
*
*/
STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobWriteDone( void )
{

	/* Mark the Fee block as valid */
	Fee_aBlockInfo[Fee_GlobalPar.Fee_uJobBlockIndex].eBlockStatus = FEE_BLOCK_VALID;

	/* No more Fls jobs to schedule */
	Fee_InterRunInfor.Fee_eJob = FEE_JOB_DONE;

	return( MEMIF_JOB_OK );
}

/**
* @brief        Invalidate Fee block by writing the invalidation flag to flash
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the write job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept write job
* @retval       MEMIF_JOB_OK             The Fee block is already invalid
*
* @pre          Fee_uJobBlockIndex must contain index of Fee block to invalidate
* @post         Schedule FEE_JOB_DONE or FEE_JOB_INVAL_BLOCK_DONE subsequent
*               jobs
*
*/
STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobInvalBlock( void )
{
	VAR( MemIf_JobResultType, AUTOMATIC ) eRetVal = MEMIF_JOB_OK;

	if( FEE_BLOCK_INVALID == Fee_aBlockInfo[Fee_GlobalPar.Fee_uJobBlockIndex].eBlockStatus )
	{
		/* No more subsequent Fls jobs to schedule */
		Fee_InterRunInfor.Fee_eJob = FEE_JOB_DONE;

		/* Fee job completed */
		eRetVal = MEMIF_JOB_OK;
	}
	else
	{
		if( FEE_BLOCK_NEVER_WRITTEN == Fee_aBlockInfo[Fee_GlobalPar.Fee_uJobBlockIndex].eBlockStatus )
		{
			/* set status as INVALID */
			Fee_aBlockInfo[Fee_GlobalPar.Fee_uJobBlockIndex].eBlockStatus = FEE_BLOCK_INVALID;

			/* No more subsequent Fls jobs to schedule */
			Fee_InterRunInfor.Fee_eJob = FEE_JOB_DONE;

			/* Fee job completed */
			eRetVal = MEMIF_JOB_OK;
		}
		else
		{
			/* Serialize invalidation pattern to buffer */
			Fee_SerializeFlag( Fee_aDataBuffer, FEE_INVALIDATED_VALUE );

			/* Write invalidation pattern to flash */
			if( ((Std_ReturnType)E_OK) == Fls_Write( Fee_aBlockInfo[Fee_GlobalPar.Fee_uJobBlockIndex].uInvalidAddr,
							   Fee_aDataBuffer, FEE_VIRTUAL_PAGE_SIZE)
			  )
			{
				/* Fls read job has been accepted */
				eRetVal = MEMIF_JOB_PENDING;
			}
			else
			{
				/* Fls write job hasn't been accepted */
				eRetVal = MEMIF_JOB_FAILED;
			}

			/* Finalize the invalidation operation */
			Fee_InterRunInfor.Fee_eJob = FEE_JOB_INVAL_BLOCK_DONE;
		}
	}

	return( eRetVal );
}

/**
* @brief        Finalize invalidation of Fee block
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_OK
*
* @pre          Fee_uJobBlockIndex       must contain index of Fee block to
*                                        write to
* @post         change Fee block status to FEE_BLOCK_INVALID
* @post         Schedule FEE_JOB_DONE subsequent job
*
*/
STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobInvalBlockDone( void )
{
	/* Mark the Fee block as in valid */
	Fee_aBlockInfo[Fee_GlobalPar.Fee_uJobBlockIndex].eBlockStatus = FEE_BLOCK_INVALID;

	/* No more subsequent Fls jobs to schedule */
	Fee_InterRunInfor.Fee_eJob = FEE_JOB_DONE;

	/* Fee job completed */
	return( MEMIF_JOB_OK );
}

/**
* @brief        Erase (pre-allocate) immediate Fee block
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the write job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept write job
*
* @pre          Fee_uJobBlockIndex must contain index of Fee block to
*               pre-allocated
* @post         Initialize internal cluster swap sequence if requested block
*               doesn't fit into current cluster
* @post         Schedule FEE_JOB_ERASE_IMMEDIATE_DONE subsequent jobs
*
* @implements   Fee_JobEraseImmediate_Activity
*
*/
STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobEraseImmediate( void )
{
	VAR( MemIf_JobResultType, AUTOMATIC ) eRetVal = MEMIF_JOB_OK;

	/* In standard mode, perform swap if reserved area has been touched, or do nothing. */
	if( FALSE == Fee_ReservedAreaWritable() )
	{
		/* Reserved area is not writable, force the swap */
		Fee_GlobalPar.Fee_uJobIntClrGrpIt =
				Fee_BlockConfig[ Fee_GlobalPar.Fee_uJobBlockIndex ].FeeClrGrpIndex;/* Get cluster group index */
		eRetVal = Fee_JobIntSwap();
	}
	else
	{
		/* Do effectively nothing */
		Fee_InterRunInfor.Fee_eJob = FEE_JOB_DONE;
	}

	return( eRetVal );
}

/**
* @brief        Finalize erase (pre-allocation) of Fee block
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_OK
*
* @pre          Fee_uJobBlockIndex must contain index of Fee block to write to
* @post         change Fee block status to FEE_BLOCK_INCONSISTENT
* @post         Schedule FEE_JOB_DONE subsequent job
*
* @implements   Fee_JobEraseImmediateDone_Activity
*/
STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobEraseImmediateDone( void )
{
	VAR( uint16, AUTOMATIC ) uBlockSize = 0U;
	VAR( uint16, AUTOMATIC ) uAlignedBlockSize = 0U;
	VAR( uint16, AUTOMATIC ) uClrGrp = 0U;
	VAR( MemIf_JobResultType, AUTOMATIC ) eRetVal = MEMIF_JOB_OK;
	VAR( Fls_AddressType, AUTOMATIC ) uDataAddr = (Fls_AddressType)0;
	VAR( Fls_AddressType, AUTOMATIC ) uHdrAddr = (Fls_AddressType)0;
	VAR( uint8, AUTOMATIC ) uClrGrpIndex = (uint8)0;

	/* Mark the Fee immediate block as inconsistent so it can be written later on */
	Fee_aBlockInfo[Fee_GlobalPar.Fee_uJobBlockIndex].eBlockStatus = FEE_BLOCK_INCONSISTENT;

	/* Get size of Fee block */
	uBlockSize = Fee_BlockConfig[Fee_GlobalPar.Fee_uJobBlockIndex].FeeBlockSize;

	/* Align Fee block size to the virtual page boundary */
	uAlignedBlockSize = Fee_AlignToVirtualPageSize( uBlockSize );

	/* Index of cluster group the Fee block belongs to */
	uClrGrp = Fee_BlockConfig[Fee_GlobalPar.Fee_uJobBlockIndex].FeeClrGrpIndex;

	/* Index of cluster group the Fee block belongs to */
	uClrGrpIndex = Fee_BlockConfig[Fee_GlobalPar.Fee_uJobBlockIndex].FeeClrGrpIndex;
	uDataAddr = Fee_aClrGrpInfo[uClrGrpIndex].uDataAddrIt - uAlignedBlockSize;
	uHdrAddr = Fee_aClrGrpInfo[uClrGrpIndex].uHdrAddrIt;

	/* Update the block address info */
	Fee_aBlockInfo[Fee_GlobalPar.Fee_uJobBlockIndex].uDataAddr = uDataAddr;
	Fee_aBlockInfo[Fee_GlobalPar.Fee_uJobBlockIndex].uInvalidAddr = (uHdrAddr + FEE_BLOCK_OVERHEAD) -
														  FEE_VIRTUAL_PAGE_SIZE;

	/* Header has been written so update both header and data addresses */
	Fee_aClrGrpInfo[uClrGrp].uHdrAddrIt += FEE_BLOCK_OVERHEAD;
	Fee_aClrGrpInfo[uClrGrp].uDataAddrIt -= uAlignedBlockSize;

	/* No more subsequent Fls jobs to schedule */
	Fee_InterRunInfor.Fee_eJob = FEE_JOB_DONE;
	/* set job as ook */
	eRetVal = MEMIF_JOB_OK;
	/* Fee job completed */

	return( eRetVal );
}

/**
* @brief        Schedule subsequent jobs
*
* @return       MemIf_JobResultType
*
* @pre          Fee_eJob must contain type of job to schedule
*
* @implements   Fee_JobSchedule_Activity
*/
STATIC FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobSchedule( void )
{
	VAR( MemIf_JobResultType, AUTOMATIC ) eRetVal = MEMIF_JOB_FAILED;

	switch( Fee_InterRunInfor.Fee_eJob )
	{
		/* Fee_Read() related jobs */
		case FEE_JOB_READ:
			eRetVal = Fee_JobRead();
			break;

		/* Fee_Write() related jobs */
		case FEE_JOB_WRITE:
			eRetVal = Fee_JobWrite();
			break;
		case FEE_JOB_WRITE_DATA:
			eRetVal = Fee_JobWriteData();
			break;
		case FEE_JOB_WRITE_UNALIGNED_DATA:
			eRetVal = Fee_JobWriteUnalignedData();
			break;
		case FEE_JOB_WRITE_VALIDATE:
			eRetVal = Fee_JobWriteValidate();
			break;
		case FEE_JOB_WRITE_DONE:
			eRetVal = Fee_JobWriteDone();
			break;

		/* Fee_InvalidateBlock() related jobs */
		case FEE_JOB_INVAL_BLOCK:
			eRetVal = Fee_JobInvalBlock();
			break;
		case FEE_JOB_INVAL_BLOCK_DONE:
			eRetVal = Fee_JobInvalBlockDone();
			break;

		/* Fee_EraseImmediateBlock() related jobs */
		case FEE_JOB_ERASE_IMMEDIATE:
			eRetVal = Fee_JobEraseImmediate();
			break;
		case FEE_JOB_ERASE_IMMEDIATE_DONE:
			eRetVal = Fee_JobEraseImmediateDone();
			break;

		/* Fee_Init() related jobs */
		case FEE_JOB_INT_SCAN:
			eRetVal = Fee_JobIntScan();
			break;
		case FEE_JOB_INT_SCAN_CLR:
			eRetVal = Fee_JobIntScanClr();
			break;
		case FEE_JOB_INT_SCAN_CLR_HDR_PARSE:
			eRetVal = Fee_JobIntScanClrHdrParse( (boolean)TRUE );
			break;
		case FEE_JOB_INT_SCAN_CLR_FMT:
			eRetVal = Fee_JobIntScanClrFmt();
			break;
		case FEE_JOB_INT_SCAN_CLR_FMT_DONE:
			eRetVal = Fee_JobIntScanClrFmtDone();
			break;
		case FEE_JOB_INT_SCAN_BLOCK_HDR_PARSE:
			eRetVal = Fee_JobIntScanBlockHdrParse( (boolean)TRUE );
			break;

		/* Swap related jobs */
		case FEE_JOB_INT_SWAP_CLR_FMT:
			eRetVal = Fee_JobIntSwapClrFmt();
			break;
		case FEE_JOB_INT_SWAP_BLOCK:
			eRetVal = Fee_JobIntSwapBlock();
			break;
		case FEE_JOB_INT_SWAP_DATA_READ:
			eRetVal = Fee_JobIntSwapDataRead( (boolean)TRUE );
			break;
		case FEE_JOB_INT_SWAP_DATA_WRITE:
			eRetVal = Fee_JobIntSwapDataWrite( (boolean)TRUE );
			break;
		case FEE_JOB_INT_SWAP_CLR_VLD_DONE:
			eRetVal = Fee_JobIntSwapClrVldDone();
			break;

		/* if the job is finished switch case will break */
		case FEE_JOB_DONE:
			/* Do nothing */
			break;

		default:
			/* Compiler_Warning: This default branch will never be reached in FTE */
			break;
	}

	return( eRetVal );
}

/**
* @brief Checks whether the block specified by Fee_JobBlockIndex is writable into the reserved area.
*
* @return sint8
* @retval TRUE The block is writable into the reserved area.
* @retval FALSE The block is not writable into the reserved area.
*
* @pre Fee_JobBlockIndex must contain index of Fee block to be written
* @pre Fee_aClrGrpInfo[uClrGrpIndex].uDataAddrIt must be up to date
* @pre Fee_aClrGrpInfo[uClrGrpIndex].uHdrAddrIt must be up to date
*
* @implements   Fee_ReservedAreaWritable_Activity
*
*/
STATIC FUNC( sint8, FEE_CODE ) Fee_ReservedAreaWritable( void )
{
	VAR( sint8, AUTOMATIC ) sRetVal = TRUE;
	VAR( uint16, AUTOMATIC ) uBlockSize = 0U;
	VAR( uint16, AUTOMATIC ) uAlignedBlockSize = 0U;
	VAR( Fls_LengthType, AUTOMATIC ) uAvailClrSpace = 0UL;
	VAR( uint8, AUTOMATIC ) uClrGrpIndex = (uint8)0;
	VAR( uint32, AUTOMATIC ) uReservedSpace = 0UL;
	VAR( boolean, AUTOMATIC ) bImmediateData = (boolean)FALSE;

	/* Index of cluster group the Fee block belongs to */
	uClrGrpIndex = Fee_GetBlockClusterGrp(Fee_GlobalPar.Fee_uJobBlockIndex);

	/* Reserved space of cluster group*/
	uReservedSpace = Fee_ClrGrps[uClrGrpIndex].Fee_reservedSize;

	/* Calculate available space in active cluster */
	uAvailClrSpace = Fee_aClrGrpInfo[uClrGrpIndex].uDataAddrIt -
					 Fee_aClrGrpInfo[uClrGrpIndex].uHdrAddrIt;

	/* Get size of Fee block */
	uBlockSize = Fee_GetBlockSize(Fee_GlobalPar.Fee_uJobBlockIndex);

	/* Align Fee block size to the virtual page boundary */
	uAlignedBlockSize = Fee_AlignToVirtualPageSize( uBlockSize );

	/* Hard Stop condition: One FEE_BLOCK_OVERHEAD must be left blank to have a clear separation
	   between header block space and data block space */
	if( (((uint32)uAlignedBlockSize) + (2U * FEE_BLOCK_OVERHEAD)) > uAvailClrSpace )
	{
		sRetVal = FALSE;
	}
	else if( (((uint32)uAlignedBlockSize) + (2U * FEE_BLOCK_OVERHEAD) + uReservedSpace) >
			 uAvailClrSpace
		   )
	{
		bImmediateData = Fee_GetBlockImmediate(Fee_GlobalPar.Fee_uJobBlockIndex);
		/* Block targets reserved area */
		if( (boolean)TRUE == bImmediateData )
		{
			/* Immediate block - only writable if not already present in the reserved area */
			if( (0UL == Fee_aBlockInfo[Fee_GlobalPar.Fee_uJobBlockIndex].uDataAddr) &&
				(0UL == Fee_aBlockInfo[Fee_GlobalPar.Fee_uJobBlockIndex].uInvalidAddr)
			  )
			{
				/* The block is not written in the cluster at all => writable */
				sRetVal = TRUE;
			}
			else
			{
				/* The block is written in the cluster - is it written in the reserved area? */
				if( (FEE_BLOCK_OVERHEAD + uReservedSpace) >
					(Fee_aBlockInfo[Fee_GlobalPar.Fee_uJobBlockIndex].uDataAddr -
					   (Fee_aBlockInfo[Fee_GlobalPar.Fee_uJobBlockIndex].uInvalidAddr + FEE_VIRTUAL_PAGE_SIZE))
				  )
				{
					/* The block is already written in the reserved area */
					sRetVal = FALSE;
				}
				else
				{
				   /* The block is not written in the reserved area */
				   sRetVal = TRUE;
				}
			}
		}
		else
		{
			sRetVal = FALSE;
		}
	}
	else
	{
		/* Block does not target reserved area */
		sRetVal = TRUE;
	}
	return sRetVal;
}

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/**
 * @sid          0x00
 * @brief        Service to initialize the FEE module.
 * @details      The function Fee_Init will initialize the Flash EEPROM
 *               Emulation module.
 * @param[in]    ConfigPtr  Pointer to the selected configuration set.
 * @param[out]   	None
 * @param[in/out] 	None
 * @return       	None
 * @retval
 */
FUNC( void, FEE_CODE ) Fee_Init(P2CONST( Fee_ConfigType, AUTOMATIC, FEE_APPL_CONST ) paConfigPtr)
{
   VAR( uint32, AUTOMATIC ) uInvalIndex = 0U;

	/**
	 * @req [SWS_Fee_00189] The configuration pointer ConfigPtr shall always have a
	 *      NULL_PTR value.
	 */
	(void)paConfigPtr;

#if (FEE_DEV_ERROR_DETECT == STD_ON)
	if (NULL_PTR == paConfigPtr)
	{
		FEE_DET_REPORT(FEE_INIT_ID, FEE_E_PARAM_POINTER);
	}
	else if( MEMIF_BUSY == Fee_InterRunInfor.Fee_eModuleStatus )
	{
		FEE_DET_REPORT(FEE_INIT_ID, FEE_E_BUSY );
	}
	else if( MEMIF_BUSY_INTERNAL == Fee_InterRunInfor.Fee_eModuleStatus )
	{
		FEE_DET_REPORT(FEE_INIT_ID, FEE_E_BUSY_INTERNAL);
	}
	else
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
	{
		/* Initialize all block info records */
		for( uInvalIndex = 0U; uInvalIndex < FEE_NUMBER_OF_BLOCKS; uInvalIndex++ )
		{
			/* for blocks which were never written Fee returns INCONSISTENT status */
			Fee_aBlockInfo[uInvalIndex].eBlockStatus = FEE_BLOCK_NEVER_WRITTEN;

			Fee_aBlockInfo[uInvalIndex].uDataAddr = 0U;
			Fee_aBlockInfo[uInvalIndex].uInvalidAddr = 0U;
		}

		/* Invalidate all cluster groups */
		for( uInvalIndex = 0U; uInvalIndex < FEE_NUMBER_OF_CLUSTER_GROUPS; uInvalIndex++ )
		{
			Fee_aClrGrpInfo[uInvalIndex].uActClrID = 0U;
		}

		Fee_GlobalPar.Fee_uJobIntClrGrpIt = 0U;
		Fee_GlobalPar.Fee_uJobIntClrIt = 0U;
		Fee_GlobalPar.Fee_uJobBlockIndex = 0U;
		Fee_GlobalPar.Fee_uJobIntBlockIt = 0U;
		Fee_GlobalPar.Fee_uJobBlockOffset = 0U;
		Fee_GlobalPar.Fee_uJobBlockLength = 0U;
		Fee_GlobalPar.Fee_uJobIntAddrIt = 0U;
		Fee_GlobalPar.Fee_uJobIntHdrAddr = 0U;
		Fee_GlobalPar.Fee_uJobIntDataAddr = 0U;

		/**
		 * @req [SWS_Fee_00120] The function Fee_Init shall set the module state from
		 *      MEMIF_UNINIT to MEMIF_BUSY_INTERNAL once it starts the module's initialization.
		 */
		Fee_InterRunInfor.Fee_eJob = FEE_JOB_INT_SCAN;

		Fee_InterRunInfor.Fee_eModuleStatus = MEMIF_BUSY_INTERNAL;

		Fee_InterRunInfor.Fee_eJobResult = MEMIF_JOB_PENDING;
	}
}

#if (FEE_SETMODE_API_SUPPORTED == STD_ON)
/**
 * @sid          0x01
 * @brief        Service to call the Fls_SetMode function of the underlying flash driver.
 * @details      Call the Fls_SetMode function of the underlying flash driver.
 *
 * @param[in]    	Mode      Desired mode for the underlying flash driver
 * @param[out]   	None
 * @param[in/out] 	None
 * @return       	None
 * @retval
 */
FUNC( void, FEE_CODE ) Fee_SetMode( VAR( MemIf_ModeType, AUTOMATIC) eMode )
{
#if (FEE_DEV_ERROR_DETECT == STD_ON)
	/**
	 * @req [SWS_Fee_00121] If development error detection is enabled for the module: the
	 *      function Fee_SetMode shall check if the module status is MEMIF_UNINIT. If this is
	 *      the case, the function Fee_SetMode shall raise the development error
	 *      FEE_E_UNINIT and return to the caller without executing the mode switch.
	 */
	if( MEMIF_UNINIT == Fee_InterRunInfor.Fee_eModuleStatus )
	{
		FEE_DET_REPORT(FEE_SETMODE_ID, FEE_E_UNINIT );
	}
	/**
	 * @req [SWS_Fee_00170] If development error detection is enabled for the module: the
	 *      function Fee_SetMode shall check if the module state is MEMIF_BUSY. If this is the
	 *      case, the function Fee_SetMode shall raise the development error FEE_E_BUSY and
	 *      return to the caller without executing the mode switch.
	 */
	else if( MEMIF_BUSY == Fee_InterRunInfor.Fee_eModuleStatus )
	{
		FEE_DET_REPORT(FEE_SETMODE_ID, FEE_E_BUSY );
	}
	else if( MEMIF_BUSY_INTERNAL == Fee_InterRunInfor.Fee_eModuleStatus )
	{
		FEE_DET_REPORT(FEE_SETMODE_ID, FEE_E_BUSY_INTERNAL);
	}
	else
#else
		if( MEMIF_IDLE == Fee_InterRunInfor.Fee_eModuleStatus )
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
		{
			/**
			 * @req [SWS_Fee_00020] If the current module status is MEMIF_IDLE and if supported
			 *      by the underlying hardware and device driver, the function Fee_SetMode
			 *      shall call the function Fls_SetMode of the underlying flash driver with
			 *      the given "Mode" parameter.
			 */
			Fls_SetMode( eMode );
		}
}
#endif /* (FEE_SETMODE_API_SUPPORTED == STD_ON) */

/**
 * @sid          0x02
 * @brief        Service to initiate a read job.
 * @details      The function Fee_Read shall take the block start address and offset and
 *               calculate the corresponding memory read address.
 *
 * @param[in]    BlockNumber     Number of logical block, also denoting start address
 *                               of that block in flash memory.
 * @param[in]    BlockOffset     Read address offset inside the block
 * @param[out]   DataBufferPtr   Pointer to data buffer.
 * @param[in]    Length          Number of bytes to read
 * @param[in/out] 	None
 * @return       Std_ReturnType
 * @retval       E_OK            The requested job has been accepted by the module.
 * @retval       E_NOT_OK        The requested job has not been accepted by the module.
 */
FUNC( Std_ReturnType, FEE_CODE ) Fee_Read
(
		VAR( uint16, AUTOMATIC ) uBlockNumber,
		VAR( uint16, AUTOMATIC ) uBlockOffset,
		P2VAR( uint8, AUTOMATIC, FEE_APPL_DATA ) pDataBufferPtr,
		VAR( uint16, AUTOMATIC ) uLength
)
{
	VAR( Std_ReturnType, AUTOMATIC ) uRetVal = (Std_ReturnType)E_OK;
	/**
	 * @req [SWS_Fee_00021] The function Fee_Read shall take the block start address and
	 *      offset and calculate the corresponding memory read address.
	 */
	VAR( uint16, AUTOMATIC ) uBlockIndex = Fee_GetBlockIndex( uBlockNumber );

	/**
	 * @req [SWS_Fee_00122] If development error detection is enabled for the module: the
	 *  	function Fee_Read shall check if the module state is MEMIF_UNINIT. If this is the
	 *  	case, the function Fee_Read shall reject the read request, raise the development
	 *  	error FEE_E_UNINIT and return with E_NOT_OK.
	 */
	if( MEMIF_UNINIT == Fee_InterRunInfor.Fee_eModuleStatus )
	{
#if (FEE_DEV_ERROR_DETECT == STD_ON)
		FEE_DET_REPORT(FEE_READ_ID, FEE_E_UNINIT );
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
		uRetVal = (Std_ReturnType)E_NOT_OK;
	}
	/**
	 * @req [SWS_Fee_00133] If development error detection is enabled for the module: the
	 * 	 	function Fee_Read shall check if the module state is MEMIF_BUSY. If this is
	 * 	 	the case, the function Fee_Read shall reject the read request, raise the
	 * 	 	development error FEE_E_BUSY and return with E_NOT_OK.
	 */
	else if( MEMIF_BUSY == Fee_InterRunInfor.Fee_eModuleStatus )
	{
#if (FEE_DEV_ERROR_DETECT == STD_ON)
		FEE_DET_REPORT(FEE_READ_ID, FEE_E_BUSY );
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
		uRetVal = (Std_ReturnType)E_NOT_OK;
	}
	else if( MEMIF_BUSY_INTERNAL == Fee_InterRunInfor.Fee_eModuleStatus )
	{
#if (FEE_DEV_ERROR_DETECT == STD_ON)
		FEE_DET_REPORT(FEE_READ_ID, FEE_E_BUSY_INTERNAL);
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
		uRetVal = (Std_ReturnType)E_NOT_OK;
	}

#if (FEE_DEV_ERROR_DETECT == STD_ON)
	/**
	 * @req [SWS_Fee_00134] If development error detection is enabled for the module: the
	 *      function Fee_Read shall check that the given block number is valid (i.e. it has been
	 *      configured). If this is not the case, the function Fee_Read shall reject the read
	 *      request, raise the development error FEE_E_INVALID_BLOCK_NO and return with
	 *      E_NOT_OK.
	 */
	else if( 0xFFFFU == uBlockIndex )
	{
		FEE_DET_REPORT(FEE_READ_ID, FEE_E_INVALID_BLOCK_NO);
		uRetVal = (Std_ReturnType)E_NOT_OK;
	}
	/**
	 * @req [SWS_Fee_00135] If development error detection is enabled for the module: the
	 * 		function Fee_Read shall check that the given block offset is valid (i.e. that it is less
	 * 		than the block length configured for this block). If this is not the case, the function
	 * 		Fee_Read shall reject the read request, raise the development error
	 * 		FEE_E_INVALID_BLOCK_OFS and return with E_NOT_OK.
	 */
	else if( uBlockOffset >= Fee_BlockConfig[uBlockIndex].FeeBlockSize )
	{
		FEE_DET_REPORT(FEE_READ_ID, FEE_E_INVALID_BLOCK_OFS);
		uRetVal = (Std_ReturnType)E_NOT_OK;
	}
	/**
	 * @req [SWS_Fee_00137] If development error detection is enabled for the module: the
	 * 		function Fee_Read shall check that the given length information is valid, i.e.
	 * 		that the requested length information plus the block offset do not exceed the
	 * 		block endaddress (block start address plus configured block length). If this
	 * 		is not the case, the function Fee_Read shall reject the read request, raise
	 * 		the development error FEE_E_INVALID_BLOCK_LEN and return with E_NOT_OK.
	 */
	else if((0U == uLength) || ((uBlockOffset+uLength) > Fee_BlockConfig[uBlockIndex].FeeBlockSize))
	{
		FEE_DET_REPORT(FEE_READ_ID, FEE_E_INVALID_BLOCK_LEN);
		uRetVal = (Std_ReturnType)E_NOT_OK;
	}
	/**
	 * @req [SWS_Fee_00136] If development error detection is enabled for the module: the
	 * 		function Fee_Read shall check that the given data pointer is valid
	 * 		(i.e. that it is not NULL). If this is not the case, the function Fee_Read
	 * 		shall reject the read request,raise the development error FEE_E_PARAM_POINTER
	 * 		and return with E_NOT_OK.
	 */
	else if( NULL_PTR == pDataBufferPtr )
	{
		FEE_DET_REPORT(FEE_READ_ID, FEE_E_PARAM_POINTER);
		uRetVal = (Std_ReturnType)E_NOT_OK;
	}
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
	else
	{
		/**
		 * @req [SWS_Fee_00022] If the current module status is MEMIF_IDLE or if the current
		 * 		module status is MEMIF_BUSY INTERNAL, the function Fee_Read shall accept the
		 * 		read request, copy the given / computed parameters to module internal
		 * 		variables, initiate a read job, set the FEE module status to MEMIF_BUSY,
		 * 		set the job result to MEMIF_JOB_PENDING and return with E_OK.
		 */
		Fee_GlobalPar.Fee_uJobBlockIndex = uBlockIndex;

		Fee_GlobalPar.Fee_uJobBlockOffset = uBlockOffset;

		Fee_GlobalPar.Fee_uJobBlockLength = uLength;
		Fee_pJobReadDataDestPtr = pDataBufferPtr;

		Fee_InterRunInfor.Fee_eJob = FEE_JOB_READ;

		Fee_InterRunInfor.Fee_eModuleStatus = MEMIF_BUSY;

		/* Execute the read job */
		Fee_InterRunInfor.Fee_eJobResult = MEMIF_JOB_PENDING;
	}

	return( uRetVal );
}

/**
 * @sid          0x03
 * @brief        Service to initiate a write job.
 * @details      The function Fee_Write shall take the block start address and
 *               calculate the corresponding memory write address. The block
 *               address offset shall be fixed to zero.
 *               If the current module status is MEMIF_IDLE or if the current
 *               module status is MEMIF_BUSY INTERNAL, the function Fee_Write shall accept the
 *               write request, copy the given / computed parameters to module internal variables,
 *               initiate a write job, set the FEE module status to MEMIF_BUSY, set the job
 *               result to MEMIF_JOB_PENDING and return with E_OK
 *               The FEE module shall execute the write job of the function Fee_Write
 *               asynchronously within the FEE module' s main function.
 *
 * @param[in]    BlockNumber     Number of logical block, also denoting
 *                                start address of that block in emulated
 *                                EEPROM.
 * @param[out]   DataBufferPtr   Pointer to data buffer.
 * @param[in/out] 	None
 *
 * @return       Std_ReturnType
 * @retval       E_OK             The requested job has been accepted by the module
 * @retval       E_NOT_OK         The requested job has not been accepted by the module.
 */
FUNC( Std_ReturnType, FEE_CODE ) Fee_Write
(
	VAR( uint16, AUTOMATIC ) uBlockNumber,
	P2CONST( uint8, AUTOMATIC, FEE_APPL_CONST ) pDataBufferPtr
)
{
	VAR( Std_ReturnType, AUTOMATIC ) uRetVal = (Std_ReturnType)E_OK;
	/**
	 * @req [SWS_Fee_00024] The function Fee_Write shall take the block start address
	 * 		and calculate the corresponding memory write address. The block address offset
	 * 		shall be fixed to zero.
	 */
	VAR( uint16, AUTOMATIC ) uBlockIndex = Fee_GetBlockIndex( uBlockNumber );

	/**
	 * @req [SWS_Fee_00123] If development error detection is enabled for the module: the
	 * 		function Fee_Write shall check if the module state is MEMIF_UNINIT. If this is the
	 * 		case, the function Fee_Write shall reject the write request, raise the development
	 * 		error FEE_E_UNINIT and return with E_NOT_OK.
	 * @req [SWS_Fee_00174] If the current module status is MEMIF_UNINIT or MEMIF_BUSY,
	 * 		the function Fee_Write shall reject the job request and return with E_NOT_OK.
	 */
	if( MEMIF_UNINIT == Fee_InterRunInfor.Fee_eModuleStatus )
	{
#if (FEE_DEV_ERROR_DETECT == STD_ON)
		FEE_DET_REPORT(FEE_WRITE_ID, FEE_E_UNINIT );
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
		uRetVal = (Std_ReturnType)E_NOT_OK;
	}
	/**
	 * @req [SWS_Fee_00144] If development error detection is enabled for the module: the
	 * 		function Fee_Write shall check if the module state is MEMIF_BUSY. If this is the
	 * 		case, the function Fee_Write shall reject the write request, raise the development
	 * 		error FEE_E_BUSY and return with E_NOT_OK.
	 */
	else if( MEMIF_BUSY == Fee_InterRunInfor.Fee_eModuleStatus )
	{
#if (FEE_DEV_ERROR_DETECT == STD_ON)
		FEE_DET_REPORT(FEE_WRITE_ID, FEE_E_BUSY );
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
		uRetVal = (Std_ReturnType)E_NOT_OK;
	}
#if (FEE_DEV_ERROR_DETECT == STD_ON)
	else if( MEMIF_BUSY_INTERNAL == Fee_InterRunInfor.Fee_eModuleStatus )
	{
		FEE_DET_REPORT(FEE_WRITE_ID, FEE_E_BUSY_INTERNAL);
		uRetVal = (Std_ReturnType)E_NOT_OK;
	}
	/**
	 * @req [SWS_Fee_00138] If development error detection is enabled for the module: the
	 * 		function Fee_Write shall check that the given block number is valid (i.e. it has been
	 * 		configured). If this is not the case, the function Fee_Write shall reject the write
	 * 		request, raise the development error FEE_E_INVALID_BLOCK_NO and return with E_NOT_OK.
	 */
	else if( 0xFFFFU == uBlockIndex )
	{
		FEE_DET_REPORT(FEE_WRITE_ID, FEE_E_INVALID_BLOCK_NO);
		uRetVal = (Std_ReturnType)E_NOT_OK;
	}
	/**
	 * @req [SWS_Fee_00139] If development error detection is enabled for the module:
	 * 		the function Fee_Write shall check that the given data pointer is valid
	 * 		(i.e. that it is not NULL). If this is not the case, the function Fee_Write
	 * 		shall reject the write request, raise the development error FEE_E_PARAM_POINTER
	 * 		and return with E_NOT_OK.
	 */
	else if( NULL_PTR == pDataBufferPtr )
	{
		FEE_DET_REPORT(FEE_WRITE_ID, FEE_E_PARAM_POINTER);

		uRetVal = (Std_ReturnType)E_NOT_OK;
	}
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
	else
	{
		/* Configure the write job */
		Fee_GlobalPar.Fee_uJobBlockIndex = uBlockIndex;
		Fee_pJobWriteDataDestPtr = pDataBufferPtr;

		Fee_InterRunInfor.Fee_eJob = FEE_JOB_WRITE;

		Fee_InterRunInfor.Fee_eModuleStatus = MEMIF_BUSY;

		/* Execute the write job */
		Fee_InterRunInfor.Fee_eJobResult = MEMIF_JOB_PENDING;
	}

	return( uRetVal );
}

/**
 * @sid          0x04
 * @brief        Service to call the cancel function of the underlying flash driver.
 * @details      The function Fee_Cancel and the cancel function of the underlying flash
 *               driver are from their behaviour synchronous functions but they are asynchronous
 *               w.r.t. an ongoing read, erase or write job in the flash memory.
 *
 * @param[in]    None
 *
 * @param[out]   None
 * @param[in/out] 	None
 *
 * @return       None
 */
FUNC( void, FEE_CODE ) Fee_Cancel( void )
{
/* If FEE_CANCEL_API == STD_OFF Fee_Cancel set only a Det Error Notification
   Note: this is to avoid robustness issues (in term of internal variables) */
#if (FEE_CANCEL_API == STD_OFF)
	#if (FEE_DEV_ERROR_DETECT == STD_ON)
	FEE_DET_REPORT(FEE_CANCEL_ID, FEE_E_CANCEL_API );
	#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
#else

#if (FEE_DEV_ERROR_DETECT == STD_ON)
	/**
	 * @req [SWS_Fee_00124] If development error detection is enabled for the module: the
	 * 		function Fee_Cancel shall check if the module state is MEMIF_UNINIT. If this is the
	 * 		case the function Fee_Cancel shall raise the development error FEE_E_UNINIT and
	 * 		return to the caller without changing any internal variables.
	 */
	if( MEMIF_UNINIT == Fee_InterRunInfor.Fee_eModuleStatus )
	{
		FEE_DET_REPORT(FEE_CANCEL_ID, FEE_E_UNINIT );
	}
	else
	{
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */

		if( MEMIF_JOB_PENDING == Fee_InterRunInfor.Fee_eJobResult )
		{
			/* Cancel ongoing Fls job if any */
			if( MEMIF_BUSY == Fee_InterRunInfor.Fee_eModuleStatus )
			{
				/**
				 * @req [SWS_Fee_00080] If the current module status is MEMIF_BUSY
				 * 		(i.e. the request to cancel a pending job is accepted by the function
				 * 		Fee_Cancel), the function Fee_Cancel shall call the cancel function of
				 * 		the underlying flash driver.
				 */
				/**
				 * @req [SWS_Fee_00081] If the current module status is MEMIF_BUSY (i.e. the
				 * 		request to cancel a pending job is accepted by the function Fee_Cancel),
				 * 		the function Fee_Cancel shall reset the FEE module's internal variables
				 * 		to make the module ready for a new job request from the upper layer,
				 * 		i.e. it shall set the module status to MEMIF_IDLE.
				 */
				Fee_InterRunInfor.Fee_eJobResult = MEMIF_JOB_CANCELED;
				Fee_InterRunInfor.Fee_eJob = FEE_JOB_DONE;
				Fls_Cancel();
				Fee_InterRunInfor.Fee_eModuleStatus = MEMIF_IDLE;
			}
			else
			{
				/**
				 * @req [SWS_Fee_00164] If the current module status is not MEMIF_BUSY (i.e. the
				 * 		request to cancel a pending job is rejected by the function Fee_Cancel),
				 * 		the function Fee_Cancel shall not change the current module status or job
				 * 		result.
				 * @req [SWS_Fee_00184] If the current module status is not MEMIF_BUSY (i.e. there is
				 * 		no job to cancel and therefore the request to cancel a pending job is rejected
				 * 		by the function Fee_Cancel), the function Fee_Cancel shall raise the
				 * 		development error FEE_E_INVALID_CANCEL.
				 */
#if (FEE_DEV_ERROR_DETECT == STD_ON)
				FEE_DET_REPORT(FEE_CANCEL_ID, FEE_E_INVALID_CANCEL);
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */

#if(FEE_NVM_JOB_ERROR_NOTIFICATION == STD_ON)
				/* Call job error notification function */
				Fee_Config.Fee_NvM_JobErrorNotification();
#endif
			}
		}
		else
		{
			/* Leave the job result unchanged */
		}
#if (FEE_DEV_ERROR_DETECT == STD_ON)
	}
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
#endif    /* FLS_CANCEL_API == STD_ON */
}

/**
 * @sid          0x05
 * @brief        Service to return the status.
 * @details      Return the Fee module state synchronously.
 *
 * @param[in]    None
 * @param[out]   None
 * @param[in/out] 	None
 *
 * @return       ModuleStatus
 * @retval       MEMIF_UNINIT             The FEE module has not been initialized
 * @retval       MEMIF_IDLE               The FEE module is currently idle.
 * @retval       MEMIF_BUSY               The FEE module is currently busy.
 * @retval       MEMIF_BUSY_INTERNAL      The FEE module is busy with internal
 * 										  management operations.
 */
FUNC( MemIf_StatusType, FEE_CODE ) Fee_GetStatus( void )
{
	/**
	 * @req [SWS_Fee_00034] The function Fee_GetStatus shall return MEMIF_UNINIT if
	 * 		the module has not (yet) been initialized.
	 * @req [SWS_Fee_00128] The function Fee_GetStatus shall return MEMIF_IDLE if the
	 * 		module is neither processing a request from the upper layer nor is it doing an
	 * 		internal management operation.
	 * @req	[SWS_Fee_00129] The function Fee_GetStatus shall return MEMIF_BUSY if it is
	 * 		currently processing a request from the upper layer.
	 * @req	[SWS_Fee_00074] The function Fee_GetStatus shall return MEMIF_BUSY_INTERNAL,
	 * 		if an internal management operation is currently ongoing.
	 */
	return( Fee_InterRunInfor.Fee_eModuleStatus );
}

/**
 * @sid          0x06
 * @brief        Service to query the result of the last accepted
 *               job issued by the upper layer software.
 *
 * @details      Return the result of the last job synchronously.
 * @param[in]    None
 * @param[in/out] 	None
 * @param[out]   None
 * @return       MemIf_JobResultType
 * @retval       MEMIF_JOB_OK              The last job has been finished successfully
 * @retval       MEMIF_JOB_FAILED          The last job has not been finished successfully
 * @retval       MEMIF_JOB_PENDING         The last job is waiting for execution or currently
 * 										   being executed.
 * @retval       MEMIF_JOB_CANCELED        The last job has been canceled (which means it failed).
 * @retval       MEMIF_BLOCK_INCONSISTENT  The requested block is inconsistent,
 * 										   it may contain corrupted data.
 * @retval       MEMIF_BLOCK_INVALID       The requested block has been invalidated,
 *                                         the requested read operation can not be performed.
 */
FUNC( MemIf_JobResultType, FEE_CODE ) Fee_GetJobResult( void )
{
	/**
	 * @req [SWS_Fee_00035] The function Fee_GetJobResult shall return
	 * 		MEMIF_JOB_OK if the last job has been finished successfully.
	 * @req [SWS_Fee_00156] The function Fee_GetJobResult shall return
	 * 		MEMIF_JOB_PENDING if the requested job is still waiting for
	 * 		execution or is currently being executed.
	 * @req [SWS_Fee_00157] The function Fee_GetJobResult shall return
	 * 		MEMIF_JOB_CANCELED if the last job has been canceled by the
	 * 		upper layer.
	 * @req [SWS_Fee_00158] The function Fee_GetJobResult shall return
	 * 		MEMIF_JOB_FAILED if the last job has failed.
	 * @req [SWS_Fee_00159] The function Fee_GetJobResult shall return
	 * 		MEMIF_BLOCK_INCONSISTENT if the requested block is found to
	 * 		be inconsistent
	 * @req [SWS_Fee_00160] The function Fee_GetJobResult shall return
	 * 		MEMIF_BLOCK_INVALID if the requested block has been invalidated
	 * 		by the upper layer.
	 */
	VAR( MemIf_JobResultType, AUTOMATIC ) eRetVal = Fee_InterRunInfor.Fee_eJobResult;

#if (FEE_DEV_ERROR_DETECT == STD_ON)
	/**
	 * @req [SWS_Fee_00125] If development error detection is enabled for the module: the
	 * 		function Fee_GetJobResult shall check if the module state is MEMIF_UNINIT. If
	 * 		this is the case, the function Fee_GetJobResult shall raise the development error
	 * 		FEE_E_UNINIT and return with MEMIF_JOB_FAILED.
	 */
	if( MEMIF_UNINIT == Fee_InterRunInfor.Fee_eModuleStatus )
	{
		FEE_DET_REPORT(FEE_GETJOBRESULT_ID, FEE_E_UNINIT);
		eRetVal = MEMIF_JOB_FAILED;
	}
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */

	return( eRetVal );
}

/**
 * @sid          0x07
 * @brief        Service to invalidate a logical block.
 * @details      The function Fee_InvalidateBlock shall take the block
 *               number and calculate the corresponding memory block address.
 *
 * @param[in]    BlockNumber     Number of logical block, also denoting start
 * 								 address of that block in flash memory.
 * @param[in/out] 	None
 * @param[out]   None
 * @return       Std_ReturnType
 * @retval       E_OK             The requested job has been accepted by the module
 * @retval       E_NOT_OK         The requested job has not been accepted by the module.
 */
FUNC( Std_ReturnType, FEE_CODE ) Fee_InvalidateBlock( VAR( uint16, AUTOMATIC ) uBlockNumber )
{
	VAR( Std_ReturnType, AUTOMATIC ) uRetVal = (Std_ReturnType)E_NOT_OK;
	/**
	 * @req [SWS_Fee_00036] The function Fee_InvalidateBlock shall take the block
	 * 		number and calculate the corresponding memory block address.
	 */
	VAR( uint16, AUTOMATIC ) uBlockIndex = Fee_GetBlockIndex( uBlockNumber );

#if (FEE_DEV_ERROR_DETECT == STD_ON)
	/**
	 * @req [SWS_Fee_00126] If development error detection is enabled for the module: the
	 * 		function Fee_InvalidateBlock shall check if the module status is MEMIF_UNINIT.
	 * 		If this is the case, the function Fee_InvalidateBlock shall reject the
	 * 		invalidation request, raise the development error FEE_E_UNINIT and return with
	 * 		E_NOT_OK.
	 */
	if( MEMIF_UNINIT == Fee_InterRunInfor.Fee_eModuleStatus )
	{
		FEE_DET_REPORT(FEE_INVALIDATEBLOCK_ID, FEE_E_UNINIT);
	}
	/**
	 * @req [SWS_Fee_00140] If development error detection is enabled for the module: the
	 * 		function Fee_InvalidateBlock shall check that the given block number is valid
	 * 		(i.e. it has been configured). If this is not the case, the function
	 * 		Fee_InvalidateBlock shall reject the request, raise the development error
	 * 		FEE_E_INVALID_BLOCK_NO and return with E_NOT_OK.
	 */
	else if( 0xFFFFU == uBlockIndex )
	{
		FEE_DET_REPORT(FEE_INVALIDATEBLOCK_ID, FEE_E_INVALID_BLOCK_NO);
	}
	/**
	 * @req [SWS_Fee_00145] If development error detection is enabled for the module: the
	 * 		function Fee_InvalidateBlock shall check if the module status is MEMIF_BUSY. If
	 * 		this is the case, the function Fee_InvalidateBlock shall reject the request, raise
	 * 		the development error FEE_E_BUSY and return with E_NOT_OK.
	 */
	else if( MEMIF_BUSY == Fee_InterRunInfor.Fee_eModuleStatus )
	{
		FEE_DET_REPORT(FEE_INVALIDATEBLOCK_ID, FEE_E_BUSY );
	}
	else if( MEMIF_BUSY_INTERNAL == Fee_InterRunInfor.Fee_eModuleStatus )
	{
		FEE_DET_REPORT(FEE_INVALIDATEBLOCK_ID, FEE_E_BUSY_INTERNAL);
	}
	else
#else
		if( MEMIF_IDLE == Fee_InterRunInfor.Fee_eModuleStatus )
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
		{

			/* Configure the invalidate block job */
			Fee_GlobalPar.Fee_uJobBlockIndex = uBlockIndex;

			Fee_InterRunInfor.Fee_eJob = FEE_JOB_INVAL_BLOCK;

			Fee_InterRunInfor.Fee_eModuleStatus = MEMIF_BUSY;

			/* Execute the invalidate block job */
			Fee_InterRunInfor.Fee_eJobResult = MEMIF_JOB_PENDING;

			uRetVal = (Std_ReturnType)E_OK;
		}

	return( uRetVal );
}

#if (FEE_VERSION_INFO_API == STD_ON)
/**
 * @sid          0x08
 * @brief        Service to return the version information of the FEE module.
 * @details      The version information includes: Module Id, Vendor Id,
 *               Vendor specific version numbers.
 * @param[in]    None
 * @param[in/out] 	None
 * @param[out]   VersionInfoPtr  Pointer to standard version information structure.
 *
 * @return       None
 * @retval
 */
FUNC( void, FEE_CODE ) Fee_GetVersionInfo
(
	P2VAR( Std_VersionInfoType, AUTOMATIC, FEE_APPL_DATA ) pVersionInfoPtr
)
{
#if (FEE_DEV_ERROR_DETECT == STD_ON)
	/**
	 * @req [SWS_Fee_00147] If development error detection is enabled for the module:
	 * 		the function Fee_GetVersionInfo shall check that the given data pointer is
	 * 		valid (i.e.that it is not NULL). If this is not the case, the function
	 * 		Fee_GetVersionInfo shall raise the development error FEE_E_PARAM_POINTER.
	 */
	if( NULL_PTR == pVersionInfoPtr )
	{
		FEE_DET_REPORT(FEE_GETVERSIONINFO_ID, FEE_E_PARAM_POINTER);
	}
	else
	{
#endif /* FEE_DEV_ERROR_DETECT == STD_ON */
		pVersionInfoPtr->moduleID = (uint16)FEE_MODULE_ID;
		pVersionInfoPtr->vendorID = (uint16)FEE_VENDOR_ID;
		pVersionInfoPtr->sw_major_version = (uint8)FEE_SW_MAJOR_VERSION;
		pVersionInfoPtr->sw_minor_version = (uint8)FEE_SW_MINOR_VERSION;
		pVersionInfoPtr->sw_patch_version = (uint8)FEE_SW_PATCH_VERSION;
#if (FEE_DEV_ERROR_DETECT == STD_ON)
	}
#endif /* FEE_DEV_ERROR_DETECT == STD_ON */
}
#endif /* FEE_VERSION_INFO_API == STD_ON */

/**
 * @sid          0x09
 * @brief        Service to erase a logical block.
 * @details      The function Fee_EraseImmediateBlock shall take the block number
 *               and calculate the corresponding memory block address.
 *               The function Fee_EraseImmediateBlock shall ensure that
 *               the FEE module can write immediate data. Whether this involves
 *               physically erasing a memory area and therefore calling the erase
 *               function of the underlying driver depends on the implementation of the module
 *
 * @param[in]    BlockNumber     Number of logical block, also denoting start address
 * 								 of that block in EEPROM.
 * @param[in/out] 	None
 * @param[out] 	 None
 * @return       Std_ReturnType
 * @retval       E_OK             The requested job has been accepted by the module
 * @retval       E_NOT_OK         The requested job has not been accepted by the module.
 */
FUNC( Std_ReturnType, FEE_CODE ) Fee_EraseImmediateBlock( VAR( uint16, AUTOMATIC ) uBlockNumber )
{
	VAR( Std_ReturnType, AUTOMATIC ) uRetVal = (Std_ReturnType)E_OK;
	/**
	 * @req [SWS_Fee_00066] The function Fee_EraseImmediateBlock shall take the
	 * 		block number and calculate the corresponding memory block address
	 */
	VAR( uint16, AUTOMATIC ) uBlockIndex = Fee_GetBlockIndex( uBlockNumber );

#if (FEE_DEV_ERROR_DETECT == STD_ON)
	/**
	 * @req [SWS_Fee_00127] If development error detection is enabled for the module: the
	 * 		function Fee_EraseImmediateBlock shall check if the module state is
	 * 		MEMIF_UNINIT. If this is the case, the function Fee_EraseImmediateBlock shall
	 * 		reject the erase request, raise the development error FEE_E_UNINIT and return
	 * 		with E_NOT_OK.
	 */
	if( MEMIF_UNINIT == Fee_InterRunInfor.Fee_eModuleStatus )
	{
		FEE_DET_REPORT(FEE_ERASEIMMEDIATEBLOCK_ID, FEE_E_UNINIT);
		uRetVal = (Std_ReturnType)E_NOT_OK;
	}
	/**
	 * @req [SWS_Fee_00141] If development error detection is enabled for the module: the
	 * 		function Fee_EraseImmediateBlock shall check that the given block number is
	 * 		valid (i.e. it has been configured). If this is not the case, the function
	 * 		Fee_EraseImmediateBlock shall reject the erase request, raise the development
	 * 		error FEE_E_INVALID_BLOCK_NO and return with E_NOT_OK.
	 */
	else if( 0xFFFFU == uBlockIndex )
	{
		FEE_DET_REPORT(FEE_ERASEIMMEDIATEBLOCK_ID, FEE_E_INVALID_BLOCK_NO);
		uRetVal = (Std_ReturnType)E_NOT_OK;
	}
	/**
	 * @req [SWS_Fee_00141] If development error detection is enabled for the module: the
	 * 		function Fee_EraseImmediateBlock shall check that the given block number is
	 * 		valid (i.e. it has been configured). If this is not the case, the function
	 * 		Fee_EraseImmediateBlock shall reject the erase request, raise the development
	 * 		error FEE_E_INVALID_BLOCK_NO and return with E_NOT_OK.
	 */
	else if( (boolean)FALSE == Fee_BlockConfig[uBlockIndex].FeeImmediateData )
	{
		FEE_DET_REPORT(FEE_ERASEIMMEDIATEBLOCK_ID, FEE_E_INVALID_BLOCK_NO);
		uRetVal = (Std_ReturnType)E_NOT_OK;
	}
	/**
	 * @req [SWS_Fee_00146] If development error detection is enabled for the module: the
	 * 		function Fee_EraseImmediateBlock shall check if the module state is
	 * 		MEMIF_BUSY. If this is the case, the function Fee_EraseImmediateBlock shall
	 */
	else if( MEMIF_BUSY == Fee_InterRunInfor.Fee_eModuleStatus )
	{
		FEE_DET_REPORT(FEE_ERASEIMMEDIATEBLOCK_ID, FEE_E_BUSY);
		uRetVal = (Std_ReturnType)E_NOT_OK;
	}
	else if( MEMIF_BUSY_INTERNAL == Fee_InterRunInfor.Fee_eModuleStatus )
	{
		FEE_DET_REPORT(FEE_ERASEIMMEDIATEBLOCK_ID, FEE_E_BUSY_INTERNAL);
		uRetVal = (Std_ReturnType)E_NOT_OK;
	}
	else
	{
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */

		/* Configure the erase immediate block job */
		Fee_GlobalPar.Fee_uJobBlockIndex = uBlockIndex;

		Fee_InterRunInfor.Fee_eJob = FEE_JOB_ERASE_IMMEDIATE;

		Fee_InterRunInfor.Fee_eModuleStatus = MEMIF_BUSY;

		/* Execute the erase immediate block job */
		Fee_InterRunInfor.Fee_eJobResult = MEMIF_JOB_PENDING;
#if (FEE_DEV_ERROR_DETECT == STD_ON)
	}
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */

	return( uRetVal );
}

/**
 * @sid          0x10
 * @brief        Service to report to this module the successful end of an asynchronous operation.
 * @details      The underlying flash driver shall call the function
 *               Fee_JobEndNotification to report the successful end of
 *               an asynchronous operation.
 * @param[in]    None
 * @param[in/out] 	None
 * @param[out] 	 None
 * @return       None
 * @retval
 */
FUNC( void, FEE_CODE ) Fee_JobEndNotification( void )
{
	if( MEMIF_UNINIT == Fee_InterRunInfor.Fee_eModuleStatus )
	{
	 #if (FEE_DEV_ERROR_DETECT == STD_ON)
		FEE_DET_REPORT(FEE_JOBENDNOTIFICATION_ID, FEE_E_UNINIT);
	 #else
		 /* Do nothing. Fee is not initialized */
	 #endif  /* FEE_DEV_ERROR_DETECT == STD_ON */
	}
	else
	{
		if( FEE_JOB_DONE == Fee_InterRunInfor.Fee_eJob )
		{
			/* Last schedule Fls job finished */
			Fee_InterRunInfor.Fee_eJobResult = Fls_GetJobResult();

			if( MEMIF_BUSY_INTERNAL == Fee_InterRunInfor.Fee_eModuleStatus )
			{
				/* no notifications from internal jobs */
				Fee_InterRunInfor.Fee_eModuleStatus = MEMIF_IDLE;
			}
			else
			{
				Fee_InterRunInfor.Fee_eModuleStatus = MEMIF_IDLE;

#if(FEE_NVM_JOB_END_NOTIFICATION == STD_ON)
				/* Call job end notification function */
				Fee_Config.Fee_NvM_JobEndNotification();
#endif
			}
		}
		else
		{
			Fee_InterRunInfor.Fee_eJobResult = Fee_JobSchedule();

			if( MEMIF_JOB_OK == Fee_InterRunInfor.Fee_eJobResult )
			{
				if( MEMIF_BUSY_INTERNAL == Fee_InterRunInfor.Fee_eModuleStatus )
				{
					/* no notifications from internal jobs */
					Fee_InterRunInfor.Fee_eModuleStatus = MEMIF_IDLE;
				}
				else
				{
					Fee_InterRunInfor.Fee_eModuleStatus = MEMIF_IDLE;

#if(FEE_NVM_JOB_END_NOTIFICATION == STD_ON)
					/* Call job end notification function */
					Fee_Config.Fee_NvM_JobEndNotification();
#endif
				}
			}
			else if( MEMIF_JOB_PENDING == Fee_InterRunInfor.Fee_eJobResult )
			{
				/* Nothing to do (ongoing Fls job) */
			}
			else
			{
				if( MEMIF_BUSY_INTERNAL == Fee_InterRunInfor.Fee_eModuleStatus )
				{
					/* no notifications from internal jobs */
					Fee_InterRunInfor.Fee_eModuleStatus = MEMIF_IDLE;
				}
				else
				{
					Fee_InterRunInfor.Fee_eModuleStatus = MEMIF_IDLE;

#if(FEE_NVM_JOB_ERROR_NOTIFICATION == STD_ON)
					/* Call job error notification function */
					Fee_Config.Fee_NvM_JobErrorNotification();
#endif
				}
			}
		}
	}
}

/**
 * @sid          0x11
 * @brief        Service to report to this module the failure of an
 *               asynchronous operation.
 * @details      The underlying flash driver shall call the function
 *               Fee_JobErrorNotification to report the failure of
 *               an asynchronous operation.
 * @param[in]    None
 * @param[in/out] 	None
 * @param[out] 	 None
 * @return       None
 * @retval
 */
FUNC( void, FEE_CODE ) Fee_JobErrorNotification( void )
{
	VAR( uint8, AUTOMATIC ) uClrGrpIndex = 0U;

	if( MEMIF_UNINIT == Fee_InterRunInfor.Fee_eModuleStatus )
	{
	 #if (FEE_DEV_ERROR_DETECT == STD_ON)
		FEE_DET_REPORT(FEE_JOBERRORNOTIFICATION_ID, FEE_E_UNINIT);
	 #else
		 /* Do nothing. Fee is not initialized */
	 #endif  /* FEE_DEV_ERROR_DETECT == STD_ON */
	}
	else
	{
		if( MEMIF_JOB_CANCELED == Fee_InterRunInfor.Fee_eJobResult )
		{
			/* Fls job has been canceled. Do nothing in this callback.
			The NvM_JobErrorNotification() callback will be called from
			the Fee_Cancel()function which called the Fls_Cancel() function */
		}
		else
		{
			switch( Fee_InterRunInfor.Fee_eJob )
			{
				/* Error while reading block header. Treat block header as
					invalid and    stop reading further block headers */
				case FEE_JOB_INT_SCAN_BLOCK_HDR_PARSE:
					Fee_InterRunInfor.Fee_eJobResult = Fee_JobIntScanBlockHdrParse( (boolean)FALSE );
					break;
				/* Error while reading cluster header. Treat cluster as
					invalid and    move on to next cluster */
				case FEE_JOB_INT_SCAN_CLR_HDR_PARSE:
					Fee_InterRunInfor.Fee_eJobResult = Fee_JobIntScanClrHdrParse( (boolean)FALSE );
					break;
				/* Error while reading data from source cluster.
					Leave block as INCONSISTENT and move on to next block */
				case FEE_JOB_INT_SWAP_DATA_WRITE:
					Fee_InterRunInfor.Fee_eJobResult = Fee_JobIntSwapDataWrite( (boolean)FALSE );
					break;
				/* for all the following cases based on the Fee module status error notification will
				be called */
				case FEE_JOB_WRITE:
				case FEE_JOB_WRITE_DATA:
				case FEE_JOB_WRITE_UNALIGNED_DATA:
				case FEE_JOB_ERASE_IMMEDIATE:
				case FEE_JOB_ERASE_IMMEDIATE_DONE:
				case FEE_JOB_WRITE_VALIDATE:
				case FEE_JOB_WRITE_DONE:
				{
					uClrGrpIndex = Fee_GetBlockClusterGrp(Fee_GlobalPar.Fee_uJobBlockIndex);

					/* Something wrong in FlashMemory (cluster swap occurs to next write) */
					Fee_aClrGrpInfo[uClrGrpIndex].uDataAddrIt =
						Fee_aClrGrpInfo[uClrGrpIndex].uHdrAddrIt +
						(2U * FEE_BLOCK_OVERHEAD);
				}
				case FEE_JOB_READ:
				case FEE_JOB_INVAL_BLOCK:
				case FEE_JOB_INVAL_BLOCK_DONE:
				case FEE_JOB_INT_SCAN:
				case FEE_JOB_INT_SCAN_CLR:
				case FEE_JOB_INT_SCAN_CLR_FMT:
				case FEE_JOB_INT_SCAN_CLR_FMT_DONE:
				case FEE_JOB_INT_SWAP_BLOCK:
				case FEE_JOB_INT_SWAP_CLR_FMT:
				case FEE_JOB_INT_SWAP_DATA_READ:
				case FEE_JOB_INT_SWAP_CLR_VLD_DONE:
				case FEE_JOB_DONE:
				default:
					Fee_InterRunInfor.Fee_eJobResult = Fls_GetJobResult();
					if( MEMIF_BUSY_INTERNAL == Fee_InterRunInfor.Fee_eModuleStatus )
					{
						/* No notifications from internal jobs */
						Fee_InterRunInfor.Fee_eModuleStatus = MEMIF_IDLE;
					}
					else
					{
						Fee_InterRunInfor.Fee_eModuleStatus = MEMIF_IDLE;
#if(FEE_NVM_JOB_ERROR_NOTIFICATION == STD_ON)
						/* Call job error notification function */
						Fee_Config.Fee_NvM_JobErrorNotification();
#endif
					}
					break;
			}
		}
	}
}

/**
 * @sid          0x12
 * @brief        Service to handle the requested read / write / erase jobs and the
 *               internal management operations.
 * @details      The function Fee_MainFunction shall asynchronously handle the
 *               read / write / erase / invalidate jobs requested by the upper layer
 *               and internal management operations
 *               The function Fee_MainFunction shall check, whether the block requested
 *               for reading has been invalidated by the upper layer module. If so,
 *               the function Fee_MainFunction shall set the job result to MEMIF_BLOCK_INVALID
 *               and call the error notification routine of the upper layer if configured.
 *               The function Fee_MainFunction shall check the consistency
 *               of the logical block being read before notifying the caller.
 *               If an inconsistency of the read data is detected or if the
 *               requested block can't be found, the function Fee_MainFunction shall
 *               set the job result to MEMIF_BLOCK_INCONSISTENT and call the error
 *               notification routine of the upper layer if configured.
 *
 * @param[in]    None
 * @param[in/out] 	None
 * @param[out] 	 None
 * @return       None
 * @retval
 */
FUNC( void, FEE_CODE ) Fee_MainFunction( void )
{
#if (FEE_DEV_ERROR_DETECT == STD_ON)
	if( MEMIF_UNINIT == Fee_InterRunInfor.Fee_eModuleStatus )
	{
		FEE_DET_REPORT(FEE_MAINFUNCTION_ID, FEE_E_UNINIT);
	}
	else
	{
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
		if( MEMIF_JOB_PENDING == Fee_InterRunInfor.Fee_eJobResult )
		{
			switch( Fee_InterRunInfor.Fee_eJob )
			{
				/* for all the following jobs subsequent jobs will be called in Fee job schedule
				   function based on Job */
				case FEE_JOB_INT_SCAN:
				case FEE_JOB_READ:
				case FEE_JOB_WRITE:
				case FEE_JOB_INVAL_BLOCK:
				case FEE_JOB_ERASE_IMMEDIATE:
					Fee_InterRunInfor.Fee_eJobResult = Fee_JobSchedule();
					break;
				default:
					/* Internal or subsequent job */
					break;
			}
			if( MEMIF_JOB_PENDING == Fee_InterRunInfor.Fee_eJobResult )
			{
				/* Nothing to do */
			}
			else if( MEMIF_JOB_OK == Fee_InterRunInfor.Fee_eJobResult )
			{
				if( MEMIF_BUSY_INTERNAL == Fee_InterRunInfor.Fee_eModuleStatus )
				{
					/* no notifications from internal jobs */
					Fee_InterRunInfor.Fee_eModuleStatus = MEMIF_IDLE;
				}
				else
				{
					Fee_InterRunInfor.Fee_eModuleStatus = MEMIF_IDLE;
#if(FEE_NVM_JOB_END_NOTIFICATION == STD_ON)
					/* Call job end notification function */
					Fee_Config.Fee_NvM_JobEndNotification();
#endif
				}
			}
			else
			{
				if( MEMIF_BUSY_INTERNAL == Fee_InterRunInfor.Fee_eModuleStatus )
				{
					/* no notifications from internal jobs */
					Fee_InterRunInfor.Fee_eModuleStatus = MEMIF_IDLE;
				}
				else
				{
					Fee_InterRunInfor.Fee_eModuleStatus = MEMIF_IDLE;
#if(FEE_NVM_JOB_ERROR_NOTIFICATION == STD_ON)
					/* Call job error notification function */
					Fee_Config.Fee_NvM_JobErrorNotification();
#endif
				}
			}
		}
#if (FEE_DEV_ERROR_DETECT == STD_ON)
	}
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
}

#ifdef AH_TEST_FEE
FUNC(void, FEE_CODE) Fee_DeInit()
{
	Fee_InterRunInfor.Fee_eModuleStatus = MEMIF_UNINIT;

	Fee_InterRunInfor.Fee_eJobResult = MEMIF_JOB_OK;

	Fee_InterRunInfor.Fee_eJob = FEE_JOB_DONE;

	Fee_InterRunInfor.Fee_eJobIntOriginalJob = FEE_JOB_DONE;
}
#endif

#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

#ifdef __cplusplus
}
#endif
/** @} */
