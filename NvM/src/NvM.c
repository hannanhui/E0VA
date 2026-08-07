/**
 * @file        NvM.c
 * @brief       AUTOSAR NvM  - NvM driver source file.
 * @details     NvM driver source file, containing the C implementation of Autosar API specification
 *              and other variables and functions that are exported by the NvM driver.
 * @version     1.2.0
 * @addtogroup  NvM
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
 * is not permitt
 * ed without prior written authorization.
 *====================================================================================================*/

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

/*====================================================================================================*
 *                                           INCLUDE FILES                                          
 *====================================================================================================*/
#include "NvM.h"
#include "Crc.h"
#include "MemIf.h"
#include "NvM_Cbk.h"

/* @todo Not at this time */
/* #include "Rte_NvM.h" */
/* #include "SchM_NvM.h" */

#if (NVM_BSWM_BLOCKSTATUS_INFORMATION == STD_ON) || \
	(NVM_BSWM_MULTIBLOCK_JOBSTATUS_INFORMATION == STD_ON)
#include "BswM_NvM.h"
#endif /* (NVM_BSWM_BLOCKSTATUS_INFORMATION == STD_ON) || \
			(NVM_BSWM_MULTIBLOCK_JOBSTATUS_INFORMATION == STD_ON)*/

#if (NVM_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif /* NVM_DEV_ERROR_DETECT == STD_ON */

#if (NVM_DEM_EVENT_PARAMETERREFS == STD_ON)
#include "Dem.h"
#endif /* NVM_DEM_EVENT_PARAMETERREFS == STD_ON */

#ifdef AH_TEST_NVM
#include "TestCode.h"
#endif

/*====================================================================================================*
 *                                  SOURCE FILE VERSION INFORMATION                                 
 *====================================================================================================*/
#define NVM_VENDOR_ID_C						0U
#define NVM_AR_RELEASE_MAJOR_VESION_C		4U
#define NVM_AR_RELEASE_MINOR_VERSION_C		2U
#define NVM_AR_RELEASE_REVISION_VERSION_C	2U
#define NVM_SW_MAJOR_VERSION_C				1U
#define NVM_SW_MINOR_VERSION_C				2U
#define NVM_SW_PATCH_VERSION_C				0U
/*====================================================================================================*
 *                                         FILE VERSION CHECKS                                      
 *====================================================================================================*/
/* Check if current file and NvM.h header file are of the same vendor */
#if(NVM_VENDOR_ID_C != NVM_VENDOR_ID )
#error "NvM.c and NvM.h have different vendor id"
#endif

/* Check if current file and NvM.h header file are of the same Autosar version */
#if(\
      (NVM_AR_RELEASE_MAJOR_VESION_C != NVM_AR_RELEASE_MAJOR_VERSION) || \
      (NVM_AR_RELEASE_MINOR_VERSION_C != NVM_AR_RELEASE_MINOR_VERSION) || \
      (NVM_AR_RELEASE_REVISION_VERSION_C != NVM_AR_RELEASE_REVISION_VERSION) \
      )
#error "AutoSar Version Number of NvM.c and NvM.h are different "
#endif

/* Check if current file and NvM.h header file are of the same software version */
#if(\
      (NVM_SW_MAJOR_VERSION_C != NVM_SW_MAJOR_VERSION) || \
      (NVM_SW_MINOR_VERSION_C != NVM_SW_MINOR_VERSION) || \
      (NVM_SW_PATCH_VERSION_C != NVM_SW_PATCH_VERSION) \
      )
#error "Software Version Number of NvM.c and NvM.h are different "
#endif

/* Check if current file and NvM_Cbk.h header file are of the same vendor */
#if(NVM_VENDOR_ID_C != NVM_CBK_VENDOR_ID )
#error "NvM.c and NvM_Cbk.h have different vendor id"
#endif

/* Check if current file and NvM_Cbk.h header file are of the same Autosar version */
#if(\
      (NVM_AR_RELEASE_MAJOR_VESION_C != NVM_CBK_AR_RELEASE_MAJOR_VERSION) || \
      (NVM_AR_RELEASE_MINOR_VERSION_C != NVM_CBK_AR_RELEASE_MINOR_VERSION) || \
      (NVM_AR_RELEASE_REVISION_VERSION_C != NVM_CBK_AR_RELEASE_REVISION_VERSION) \
      )
#error "AutoSar Version Number of NvM.c and NvM_Cbk.h are different "
#endif

/* Check if current file and NvM_Cbk.h header file are of the same software version */
#if(\
      (NVM_SW_MAJOR_VERSION_C != NVM_CBK_SW_MAJOR_VERSION) || \
      (NVM_SW_MINOR_VERSION_C != NVM_CBK_SW_MINOR_VERSION) || \
      (NVM_SW_PATCH_VERSION_C != NVM_CBK_SW_PATCH_VERSION) \
      )
#error "Software Version Number of NvM.c and NvM_Cbk.h are different "
#endif

#ifndef DISABLE_INTERMOD_VERSION_CHECK

#if (NVM_DEV_ERROR_DETECT == STD_ON)
/* Check if current file and Det.h header file are of the same Autosar version */
#if(\
      (NVM_AR_RELEASE_MAJOR_VESION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
      (NVM_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION) \
      )
#error "AutoSar Version Number of NvM.c and Det.h are different "
#endif

#endif /* NVM_DEV_ERROR_DETECT == STD_ON */

#if (NVM_DEM_EVENT_PARAMETERREFS == STD_ON)
/* Check if current file and Dem.h header file are of the same Autosar version */
#if(\
      (NVM_AR_RELEASE_MAJOR_VESION_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
      (NVM_AR_RELEASE_MINOR_VERSION_C != DEM_AR_RELEASE_MINOR_VERSION) \
      )
#error "AutoSar Version Number of NvM.c and Dem.h are different "
#endif

#endif /* NVM_DEM_EVENT_PARAMETERREFS == STD_ON */

/* Check if current file and Crc.h header file are of the same Autosar version */
#if(\
      (NVM_AR_RELEASE_MAJOR_VESION_C != CRC_AR_RELEASE_MAJOR_VERSION) || \
      (NVM_AR_RELEASE_MINOR_VERSION_C != CRC_AR_RELEASE_MINOR_VERSION) \
      )
#error "AutoSar Version Number of NvM.c and Crc.h are different "
#endif

/* Check if current file and MemIf.h header file are of the same Autosar version */
#if(\
      (NVM_AR_RELEASE_MAJOR_VESION_C != MEMIF_AR_RELEASE_MAJOR_VERSION) || \
      (NVM_AR_RELEASE_MINOR_VERSION_C != MEMIF_AR_RELEASE_MINOR_VERSION) \
      )
#error "AutoSar Version Number of NvM.c and MemIf.h are different "
#endif

#if (NVM_BSWM_BLOCKSTATUS_INFORMATION == STD_ON) || \
	(NVM_BSWM_MULTIBLOCK_JOBSTATUS_INFORMATION == STD_ON)

/* Check if current file and BswM_NvM.h header file are of the same Autosar version */
#if(\
      (NVM_AR_RELEASE_MAJOR_VESION_C != BSWM_NVM_AR_RELEASE_MAJOR_VERSION) || \
      (NVM_AR_RELEASE_MINOR_VERSION_C != BSWM_NVM_AR_RELEASE_MINOR_VERSION) \
      )
#error "AutoSar Version Number of NvM.c and BswM_NvM.h are different "
#endif

#endif /* (NVM_BSWM_BLOCKSTATUS_INFORMATION == STD_ON) || \
			(NVM_BSWM_MULTIBLOCK_JOBSTATUS_INFORMATION == STD_ON)*/

#endif /* DISABLE_INTERMOD_VERSION_CHECK */
/*====================================================================================================*
 *                                   EXTERNAL FUNCTION DECLARATIONS                                 
 *====================================================================================================*/


/*====================================================================================================*
 *                                           LOCAL TYPEDEFS                                         
 *====================================================================================================*/
/**
 * @brief The state of the RAM block
 */
typedef enum
{
	/**< @brief RAM block status (INVALID/UNCHANGED) */
	NVM_BLOCK_INVALID_UNCHANGED = 0U,
	/**< @brief RAM block status (INVALID/CHANGED) */
	NVM_BLOCK_INVALID_CHANGED,
	/**< @brief RAM block status (VALID/UNCHANGED) */
	NVM_BLOCK_VALID_UNCHANGED,
	/**< @brief RAM block status (VALID/CHANGED) */
	NVM_BLOCK_VALID_CHANGED,
	/**< @brief RAM block status (not initialized) */
	NVM_BLOCK_UNINITIALIZED
}NvM_BlockStateType;

/**
 * @brief NVRAM Job Type
 */
typedef enum
{
	/**< @brief NvM_ReadBlock interface job request */
	NVM_READ_BLOCK = 0U,
	/**< @brief NvM_WriteBlock interface job request */
	NVM_WRITE_BLOCK,
	/**< @brief NvM_RestoreBlockDefaults interface job request */
	NVM_RESTORE_BLOCK_DEFAULTS,
	/**< @brief NvM_EraseNvBlock interface job request */
	NVM_ERASE_NV_BLOCK,
	/**< @brief NvM_InvalidateNvBlock interface job request */
	NVM_INVALIDATE_NV_BLOCK,
	/**< @brief NvM_ReadPRAMBlock interface job request */
	NVM_READ_PRAM_BLOCK,
	/**< @brief NvM_WritePRAMBlock interface job request */
	NVM_WRITE_PRAM_BLOCK,
	/**< @brief NvM_RestorePRAMBlockDefaults interface job request */
	NVM_RESTORE_PRAM_BLOCK_DEFAULTS,
	/**< @brief NvM_ReadAll interface job request */
	NVM_READ_ALL,
	/**< @brief NvM_WriteAll interface job request */
	NVM_WRITE_ALL,
	/**< @brief NvM_CancelWriteAll interface job request */
	NVM_CANCEL_WRITE_ALL,
	/**< @brief NvM_ValidateAll interface job request */
	NVM_VALIDATE_ALL,
	/**< @brief Invalid request */
	NVM_INVALID_JOB
}NvM_JobType;

/**
 * @brief The internal type of the Job
 */
typedef enum
{
	/**< @brief Internal job reads */
	NVM_JOB_READ = 0U,
	/**< @brief Internal job writes */
	NVM_JOB_WRITE,
	/**< @brief Internal job calculate crc */
	NVM_JOB_CALCULATE_CRC,
	/**< @brief Internal job revert to defaults */
	NVM_JOB_RESTORE_DEFAULTS,
	/**< @brief Internal job erase */
	NVM_JOB_ERASE_IMMEDIATE_BLOCK,
	/**< @brief Internal job invalidate */
	NVM_JOB_INVALIDATE_BLOCK,
	/**< @brief Internal job read RAM from mirror */
	NVM_JOB_READ_RAM_BLOCK_FROM_NVM,
	/**< @brief Internal job write RAM to mirror */
	NVM_JOB_WRITE_RAM_BLOCK_TO_NVM,
	/**< @brief Read the written data to verify the correctness of the written data */
	NVM_JOB_WRITE_VALIDATION,
	/**< @brief Internal empty work  */
	NVM_JOB_INVALID,
	/**< @brief Internal job finish */
	NVM_JOB_FINISH
}NvM_InternalJobType;

/**
 * @brief The status of the job
 */
typedef enum
{
	/**< @brief Internal job status OK */
	NVM_JOB_OK = 0U,
	/**< @brief Internal job status MemIf failed to execute the Job */
	NVM_JOB_MEMIF_FAIL,
	/**< @brief Internal job status failed to read mirror */
	NVM_JOB_READ_RAM_FAIL,
	/**< @brief Internal job status failed to write mirror */
	NVM_JOB_WRITE_RAM_FAIL,
	/**< @brief Internal job status failed to compare crc */
	NVM_JOB_CRC_FAIL,
	/**< @brief Internal job status failed to restore defaults */
	NVM_JOB_RESTORE_DEFAULTS_FAIL,
	/**< @brief The static block id check failed */
	NVM_JOB_STATIC_ID_CHECK_FAIL,
	/**< @brief A write verification job is being executed */
	NVM_JOB_WRITE_VERIFYING,
	/**< @brief The write validation job failed */
	NVM_JOB_WRITE_VALIDATION_FAIL,
	/**< @brief Internal job status pending */
	NVM_JOB_PENDING
}NvM_InternalJobStatusType;

/**
 * @brief Job information
 */
typedef struct NvM_JobLink
{
	/**< @brief TRUE:Job valid FALSE:Job invalid */
	boolean NvM_JobIsValid;
	/**< @brief Job Priority */
	uint8 NvM_JobPriority;
	/**< @brief The type of Job (write/read...) */
	NvM_JobType NvM_Job;
	/**< @brief Block ID */
	NvM_BlockIdType NvM_BlockId;
	/**< @brief A pointer to the next job */
	struct NvM_JobLink* NvM_NextJob;
}NvM_JobQueueType;

/**
 * @brief NvM task scheduling structure
 */
typedef struct
{
	/**< @brief Queue depth */
	uint16 NvM_JobNumber;
	/**< @brief Job header (points to the next job to be executed) */
	NvM_JobQueueType* NvM_CurrentJob;
}NvM_JobSchedulingType;

/**
 * @brief NVRAM block Administrative block type.
 */
typedef struct
{
	/**< @brief TRUE:The block is locked FALSE:The block is unlocked */
	boolean NvM_BlockLockStatus;
	/**< @brief TRUE:The block is protected FALSE:The block is not protected */
	boolean NvM_BlockProtection;
	/**< @brief Read retry count */
	uint8 NvM_NumOfReadRetries;
	/**< @brief Write retry count */
	uint8 NvM_NumOfWriteRetries;
	/**< @brief Nv Block index */
	uint8 NvM_BlockIndex;
	/**< @brief Block State */
	NvM_BlockStateType NvM_BlockState;
	/**< @brief The result of the most recent request */
	NvM_RequestResultType NvM_BlockRequestResult;
	/**< @brief A pointer to a RAM block */
	uint8* NvM_RAMAddress;
	/**< @brief RAM block CRC */
	uint32 NvM_BlockCrc;
}NvM_AdministrativeBlockType;

/**
 * @brief Job in progress
 */
typedef struct
{
	/**< @brief TRUE:Job can be interrupted FALSE:Job can't be interrupted */
	boolean NvM_IsInterrupted;
	/**< @brief TRUE:A block job has been completed FALSE:The first block job is in progress */
	boolean NvM_IsLastRedundantBlock;
	/**< @brief TRUE:At least one of redundant blocks completes the Job
	 * FALSE:The redundant block job failed */
	boolean NvM_IsRedundantBlockJobOK;
	/**< @brief TRUE:Enable internal job-restore default FALSE:Do not use restore default job */
	boolean NvM_RestoreDefaultJob;
	/**< @brief TRUE:The configuration ID is verified FALSE:Configuration ID verification failed */
	boolean NvM_ConfigureIDIsOK;
	/**< @brief TRUE:Enable internal job-write FALSE:Do not use write job */
	boolean NvM_MultipleBlocksToWrite;
	/**< @brief TRUE:Enable internal job-read FALSE:Do not use read job */
	boolean NvM_MultipleBlocksToRead;
	/**< @brief TRUE:The multi-block Job is terminated FALSE:The multi-block Job is pending */
	boolean NvM_MultipleRequestEnd;
	/**< @brief Deliver task flags to MemIf to prevent repeated task delivery */
	boolean NvM_MemIfJobConfirmation;
	/**< @brief An internal job that is being executed */
	NvM_InternalJobType NvM_InternalJob;
	/**< @brief Internal job status */
	NvM_InternalJobStatusType NvM_InternalJobStatus;
	/**< @brief MemIf execution job result */
	MemIf_JobResultType NvM_MemIfJobResult;
	/**< @brief Multi-block request Pre-status */
	NvM_RequestResultType NvM_PreMultiBlockRequestResult;
	/**< @brief Block Pre-State */
	NvM_BlockStateType NvM_PreBlockState;
	/**< @brief The Pre-result of the most recent request */
	NvM_RequestResultType NvM_PreBlockRequestResult;
	/**< @brief The Job that is currently running */
	NvM_JobType NvM_CurrentRunJob;
	/**< @brief The type of job that was interrupted */
	NvM_JobType NvM_InterruptedJob;
	/**< @brief The block ID of the running job */
	NvM_BlockIdType NvM_CurrentRunBlockId;
	/**< @brief The block ID of interrupted job */
	NvM_BlockIdType NvM_InterruptedBlockId;
	/**< @brief The number of bytes that have been verified */
	uint16 NvM_WriteValidationBytes;
	/**< @brief The number of Crc bytes that have been calculated */
	uint16 NvM_CrcCalculatedBytes;
	/**< @brief CRC to run block calculations */
	uint32 NvM_TemporaryCrc;
#if (STD_ON == NVM_USE_MIRROR_MECHANISM)
	/**< @brief The number of retries of the mirror block */
	uint8 NvM_NumOfMirrorOperationRetries;
#endif /* STD_ON == NVM_USE_MIRROR_MECHANISM */
}NvM_RunJobType;
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

/* PRQA S 3410, 3453, 3412 EOF # Need to use the macro definition to increase the code running speed */
/**
 * @brief Get the block management type
 */
#define NVM_GET_BLOCK_MANAGEMENT_TYPE(NvM_BlockDescriptor,Index) \
	NvM_BlockDescriptor[Index].NvM_ManagementTypeofBlock

/**
 * @brief Get the default write-protected property of the block
 */
#define NVM_GET_BLOCK_IS_WRITE_PROTESTED(NvM_BlockDescriptor,Index) \
	NvM_BlockDescriptor[Index].NvM_BlockWriteProt

/**
 * @brief Get the block priority
 */
#define NVM_GET_BLOCK_JOB_PRIORITY(NvM_BlockDescriptor,Index) \
	NvM_BlockDescriptor[Index].NvM_BlockJobPriority

/**
 * @brief Get the address of the empty queue
 */
#define NVM_GET_EMPTY_QUEUE(Index,pOJobQueue,pIJobQueue,QueueSize) \
	do \
	{ \
		if((boolean)(pIJobQueue[Index].NvM_JobIsValid) == (boolean)FALSE) \
		{ \
			pOJobQueue = &pIJobQueue[Index]; \
			break; \
		} \
		else \
		{ \
			Index++; \
		} \
	}while(Index < QueueSize)

#if (\
	NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_2 || \
	NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3 \
	)
/**
 * @brief Get the number of blocks owned by the dataset NVRAM block
 */
#define NVM_GET_DATASETS_BLOCK_NUMBER(NvM_BlockDescriptor,Index) \
	(NvM_BlockDescriptor[Index].NvM_NvBlockNum+NvM_BlockDescriptor[Index].NvM_RomBlockNum)
#endif /* NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_2 || \
		NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3 */

/**
 * @brief Get the number of ROM blocks for NVRAM block
 */
#define NVM_GET_ROM_BLOCK_NUMBER(NvM_BlockDescriptor,Index) \
	NvM_BlockDescriptor[Index].NvM_RomBlockNum

/**
 * @brief Get the number of Nv blocks for NVRAM block
 */
#define NVM_GET_NV_BLOCK_NUMBER(NvM_BlockDescriptor,Index) \
	NvM_BlockDescriptor[Index].NvM_NvBlockNum
/**
 * @brief Get the write-once attribute of the NVRAM block
 */
#define NVM_IS_WRITE_ONCE(NvM_BlockDescriptor,Index) \
	NvM_BlockDescriptor[Index].NvM_WriteBlockOnce

/**
 * @brief Report the error to the Det module
 */
#define NVM_DET_REPORT_ERROR(ServiceId, ErrorId) \
	(void)Det_ReportError(NVM_MODULE_ID,NVM_INSTANCE_ID,ServiceId,ErrorId)

/**
 * @brief Get the sync-mechanism attribute of the NVRAM block
 */
#define NVM_USE_SYNC_MECHANISM(NvM_BlockDescriptor,Index) \
	NvM_BlockDescriptor[Index].NvM_BlockUseSyncMechanism

/**
 * @brief Get the permanent RAM block address of the NVRAM
 */
#define NVM_GET_RAM_BLOCK_ADDRESS(NvM_BlockDescriptor,Index) \
	NvM_BlockDescriptor[Index].NvM_RamBlockDataAddress

/**
 * @brief Get the current RAM block address of the NVRAM
 */
#define NVM_GET_CURRENT_RAM_BLOCK_ADDRESS(pCurrentJob) \
	pCurrentJob->NvM_RAMAddress

/**
 * @brief Get the ROM block address of the NVRAM
 */
#define NVM_GET_ROM_BLOCK_ADDRESS(NvM_BlockDescriptor,Index) \
	NvM_BlockDescriptor[Index].NvM_RomBlockDataAddress

/**
 * @brief Get the address of the initialization block callback function
 */
#define NVM_GET_INIT_BLOCK_CALLBACK(NvM_BlockDescriptor,Index) \
	NvM_BlockDescriptor[Index].NvM_InitBlockCallback

/**
 * @brief Get the underlying driver index (Fee/Ea)
 */
#define NVM_GET_BLOCK_DEVICE_INDEX(NvM_BlockDescriptor,Index) \
	NvM_BlockDescriptor[Index].NvM_NvramDeviceId

/**
 * @brief Get the length of the data stored in the NVRAM block
 */
#define NVM_GET_BLOCK_LENGTH(NvM_BlockDescriptor,Index,Length) \
	do \
	{ \
		Length += NvM_BlockDescriptor[Index].NvM_NvBlockLength; \
		Length += NvM_BlockDescriptor[Index].NvM_CrcTypeOfBlock; \
		if((boolean)TRUE == NvM_BlockDescriptor[Index].NvM_StaticBlockIDCheck) \
		{ \
			Length += 4U; \
		} \
		else \
		{ \
			Length += 0U; \
		} \
	}while(0U)

/**
 * @brief Get the offset of the CRC of the Nv block storage data
 */
#define NVM_GET_BLOCK_CRC_OFFSET(NvM_BlockDescriptor,Index,CrcOffset) \
	do \
	{ \
		CrcOffset += NvM_BlockDescriptor[Index].NvM_NvBlockLength; \
		if((boolean)TRUE == NvM_BlockDescriptor[Index].NvM_StaticBlockIDCheck) \
		{ \
			CrcOffset += 4U; \
		} \
		else \
		{ \
			CrcOffset += 0U; \
		} \
	}while(0U)

/**
 * @brief Get the length of CRC (uint8/uint16/uint32 - 1/2/4)
 */
#define NVM_GET_BLOCK_CRC_LENGTH(NvM_BlockDescriptor,Index) \
	NvM_BlockDescriptor[Index].NvM_CrcTypeOfBlock

/**
 * @brief Get the number of NVRAM read retries
 */
#define NVM_GET_BLOCK_MAX_NUM_OF_READ_RETRIES(NvM_BlockDescriptor,Index) \
	NvM_BlockDescriptor[Index].NvM_MaxNumOfReadRetries

/**
 * @brief Get the number of NVRAM write retries
 */
#define NVM_GET_BLOCK_MAX_NUM_OF_WRITE_RETRIES(NvM_BlockDescriptor,Index) \
	NvM_BlockDescriptor[Index].NvM_MaxNumOfWriteRetries

/**
 * @brief Get length of block
 */
#define NVM_GET_NV_BLOCK_LENGTH(NvM_BlockDescriptor,Index) \
	NvM_BlockDescriptor[Index].NvM_NvBlockLength

/**
 * @brief Get the underlying block number
 */
#define NVM_GET_CURRENT_BLOCK_NUMBER(pCurrentJob,NvM_BlockDescriptor,Index) \
	(NvM_BlockDescriptor[Index].NvM_EaOrFeeRef + pCurrentJob->NvM_BlockIndex)

/**
 * @brief Remove the queue header job
 */
#define NVM_UNLOAD_CURRENT_JOB_AND_LOAD_NEXT_JOB(JobScheduling) \
	do \
	{ \
		NvM_JobQueueType* pJobQueue = JobScheduling.NvM_CurrentJob; \
		JobScheduling.NvM_CurrentJob->NvM_JobIsValid = (boolean)FALSE; \
		JobScheduling.NvM_CurrentJob->NvM_Job = NVM_INVALID_JOB; \
		JobScheduling.NvM_CurrentJob->NvM_JobPriority = NVM_INVALID_JOB_PRIORITY; \
		JobScheduling.NvM_CurrentJob = \
				JobScheduling.NvM_CurrentJob->NvM_NextJob; \
		if(JobScheduling.NvM_JobNumber > 0) \
		{ \
			JobScheduling.NvM_JobNumber--; \
			pJobQueue->NvM_NextJob = NULL_PTR; \
		} \
	}while(0U)

/**
 * @brief Get the block CalcRamBlockCrc property
 */
#define NVM_IS_CALC_RAM_BLOCK_CRC(NvM_BlockDescriptor,Index) \
	NvM_BlockDescriptor[Index].NvM_CalcRamBlockCrc

/**
 * @brief Get the block static block ID to check the attributes
 */
#define NVM_GET_STATIC_BLOCK_ID_CHECK(NvM_BlockDescriptor,Index) \
	NvM_BlockDescriptor[Index].NvM_StaticBlockIDCheck

/**
 * @brief Get the next redundant block index
 */
#define NVM_GET_NEXT_REDUNDANT_BLOCK_INDEX(pCurrentJob) \
	do \
	{ \
		if(pCurrentJob->NvM_BlockIndex == 1U) \
		{ \
			pCurrentJob->NvM_BlockIndex = 0U; \
		} \
		else \
		{ \
			pCurrentJob->NvM_BlockIndex = 1U; \
		} \
	}while(0U)

/**
 * @brief Get the block BlockUseSetRamBlockStatus property
 */
#define NVM_IS_USE_SET_RAM_BLOCK_STATUS(NvM_BlockDescriptor,Index) \
	NvM_BlockDescriptor[Index].NvM_BlockUseSetRamBlockStatus

/**
 * @brief Get the block BaseNumber
 */
#define NVM_GET_NV_BLOCK_BASE_NUMBER(NvM_BlockDescriptor,Index) \
	NvM_BlockDescriptor[Index].NvM_NvBlockBaseNumber

/**
 * @brief Get the block BlockUseCRCCompMechanism property
 */
#define NVM_GET_CRC_COMP_MECHANISM(NvM_BlockDescriptor,Index) \
	NvM_BlockDescriptor[Index].NvM_BlockUseCRCCompMechanism

/**
 * @brief Get the block BlockUseCrc property
 */
#define NVM_IS_USE_CRC(NvM_BlockDescriptor,Index) \
	NvM_BlockDescriptor[Index].NvM_BlockUseCrc

/**
 * @brief Get the block SelectBlockForReadAll property
 */
#define NVM_GET_BLOCK_READ_ALL_ATTRIBUTE(NvM_BlockDescriptor,Index) \
	NvM_BlockDescriptor[Index].NvM_SelectBlockForReadAll

/**
 * @brief Get the block SelectBlockForWriteAll property
 */
#define NVM_GET_BLOCK_WRITE_ALL_ATTRIBUTE(NvM_BlockDescriptor,Index) \
	NvM_BlockDescriptor[Index].NvM_SelectBlockForWriteAll

/**
 * @brief Get the block ResistantToChangedSw property
 */
#define NVM_GET_BLOCK_RESISTANT_ATTRIBUTE(NvM_BlockDescriptor,Index) \
	NvM_BlockDescriptor[Index].NvM_ResistantToChangedSw

/**
 * @brief Get NvM DynamicConfiguration property
 */
#define NVM_IS_DYNAMIC_CONFIGURATION() \
	NvM_Config.NvM_DynamicConfiguration

/**
 * @brief Get NvM ConfigurationID
 */
#define NVM_GET_CONFIGURATION_ID_ADDRESS() \
	NvM_Config.NvM_ConfigurationID

/**
 * @brief Get NvM DrvModeSwitch property
 */
#define NVM_GET_DRV_MODE_SWITCH() \
	NvM_Config.NvM_DrvModeSwitch

/**
 * @brief Get the block BlockUseAutoValidation property
 */
#define NVM_IS_USE_AUTO_VALIDATION(NvM_BlockDescriptor,Index) \
	NvM_BlockDescriptor[Index].NvM_BlockUseAutoValidation

/**
 * @brief Get NvM Multi-block callback function pointers
 */
#if (NVM_MULTI_BLOCK_CALLBACK == STD_ON)
#define NVM_CALL_MULTI_BLOCK_CALLBACK(ServiceId, JobResult) \
	NvM_Config.NvM_MultiBlockCallback(ServiceId, JobResult)
#endif /* NVM_MULTI_BLOCK_CALLBACK == STD_ON */

/**
 * @brief Get block Single-block callback function pointers
 */
#define NVM_GET_SINGLE_BLOCK_CALLBACK(NvM_BlockDescriptor,Index) \
	NvM_BlockDescriptor[Index].NvM_SingleBlockCallback

/**
 * @brief Used to call Single-block callback function
 */
#define NVM_CALL_SINGLE_BLOCK_CALLBACK(NvM_BlockDescriptor,Index, ServiceId, JobResult) \
	NvM_BlockDescriptor[Index].NvM_SingleBlockCallback(ServiceId, JobResult)

/**
 * @brief Get the block BswMBlockStatusInformation property
 */
#define NVM_IS_NOTIFY_BSWM(NvM_BlockDescriptor,Index) \
	NvM_BlockDescriptor[Index].NvM_BswMBlockStatusInformation

/**
 * @brief Get the block write validation property
 */
#define NVM_GET_BLOCK_WRITE_VERIFICATION_ATTRIBUTE(NvM_BlockDescriptor,Index) \
		NvM_BlockDescriptor[Index].NvM_WriteVerification

/**
 * @brief Get the number of bytes for a single verification
 */
#define NVM_GET_BLOCK_WRITE_VERIFICATION_SIZE(NvM_BlockDescriptor,Index) \
		NvM_BlockDescriptor[Index].NvM_WriteVerificationDataSize

/**
 * @brief Clears the status of the last run
 */
#define NVM_CLEAR_RUN_JOB() \
	do \
	{ \
		NvM_RunJob.NvM_IsLastRedundantBlock = (boolean)FALSE; \
		NvM_RunJob.NvM_IsRedundantBlockJobOK = (boolean)FALSE; \
		NvM_RunJob.NvM_RestoreDefaultJob = (boolean)FALSE; \
		NvM_RunJob.NvM_MultipleBlocksToWrite = (boolean)FALSE; \
		NvM_RunJob.NvM_MultipleBlocksToRead = (boolean)FALSE; \
		NvM_RunJob.NvM_MultipleRequestEnd = (boolean)FALSE; \
		NvM_RunJob.NvM_InternalJob = NVM_JOB_INVALID; \
		NvM_RunJob.NvM_InternalJobStatus = NVM_JOB_OK; \
		NvM_RunJob.NvM_MemIfJobResult = MEMIF_JOB_OK; \
		NvM_RunJob.NvM_CrcCalculatedBytes = 0U; \
		NvM_RunJob.NvM_WriteValidationBytes = 0U; \
		NvM_RunJob.NvM_TemporaryCrc = 0U; \
		NvM_RunJob.NvM_MemIfJobConfirmation = (boolean)FALSE; \
		NvM_RunJob.NvM_PreBlockState = NVM_BLOCK_INVALID_UNCHANGED; \
		NvM_RunJob.NvM_PreBlockRequestResult = NVM_REQ_OK; \
	}while(0U)

/**
 * @brief Update the static block ID to the temporary buffer
 */
#define NVM_UPDATE_STATIC_BLOCK_ID(pBlockDescriptor,BlockId,pCurrentJob) \
	do \
	{ \
		if((boolean)TRUE == NVM_GET_STATIC_BLOCK_ID_CHECK(pBlockDescriptor,BlockId)) \
		{\
			NvM_NVRAMTemporaryData[0] = (uint8)(BlockId & 0xffU); \
			NvM_NVRAMTemporaryData[1] = (uint8)((BlockId >> 8U) & 0xffU); \
			NvM_NVRAMTemporaryData[2] = \
			(uint8)(((NVM_GET_NV_BLOCK_BASE_NUMBER(pBlockDescriptor,BlockId-1U) \
					<< NVM_DATASET_SELECTION_BITS) + pCurrentJob->NvM_BlockIndex) & 0xffU); \
			NvM_NVRAMTemporaryData[3] = \
			(uint8)((((NVM_GET_NV_BLOCK_BASE_NUMBER(pBlockDescriptor,BlockId-1U) \
					<< NVM_DATASET_SELECTION_BITS) + pCurrentJob->NvM_BlockIndex) >> 8U) & 0xffU); \
		} \
	}while(0)

/**
 * @brief Get the results of a multi-block job
 */
#define NVM_GET_RESULT_OF_MULTIPLE_JOB() \
	do \
	{ \
		if(NvM_RunJob.NvM_PreMultiBlockRequestResult == NVM_REQ_PENDING) \
		{ \
			NvM_MultiBlockRequestResult = NVM_REQ_OK; \
		} \
		else \
		{ \
			NvM_MultiBlockRequestResult = NvM_RunJob.NvM_PreMultiBlockRequestResult; \
		} \
	}while(0)
/*====================================================================================================*
 *                                           LOCAL CONSTANTS                                        
 *====================================================================================================*/

/*====================================================================================================*
 *                                           LOCAL VARIABLES                                        
 *====================================================================================================*/
/* PRQA S 5087 EOF # Need to increase the NvM_MemMap module */
#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "NvM_MemMap.h"

/**
 * @brief Administrative Block
 */
STATIC VAR(NvM_AdministrativeBlockType, NVM_VAR) NvM_AdministrativeBlock[NVM_NUM_OF_BLOCK];

#if (NVM_JOB_PRIORITIZATION == STD_ON)
/**
 * @brief Stores an array of immediate Jobs
 */
STATIC VAR(NvM_JobQueueType, NVM_VAR) NvM_ImmediateJobQueue[NVM_SIZE_IMMEDIATE_JOB_QUEUE];
#endif /* NVM_JOB_PRIORITIZATION == STD_ON */

/**
 * @brief Stores an array of standard Jobs
 */
STATIC VAR(NvM_JobQueueType, NVM_VAR) NvM_StandardJobQueue[NVM_SIZE_STANDARD_JOB_QUEUE];

#if (NVM_JOB_PRIORITIZATION == STD_ON)
/**
 * @brief Immediate job scheduling
 */
STATIC VAR(NvM_JobSchedulingType, NVM_VAR) NvM_ImmediateJobScheduling;
#endif /* NVM_JOB_PRIORITIZATION == STD_ON */

/**
 * @brief Standard job scheduling
 */
STATIC VAR(NvM_JobSchedulingType, NVM_VAR) NvM_StandardJobScheduling;

/**
 * @brief Multi-Block Job result
 */
STATIC VAR(NvM_RequestResultType, NVM_VAR) NvM_MultiBlockRequestResult = NVM_REQ_OK;

/**
 * @brief Run Job information
 */
STATIC VAR(NvM_RunJobType, NVM_VAR) NvM_RunJob;

#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "NvM_MemMap.h"

#define NVM_START_SEC_VAR_NO_INIT_BOOLEAN
#include "NvM_MemMap.h"

/**
 * @brief TRUE:NvM_Init completed FALSE:NvM_Init is not called
 */
STATIC VAR(boolean, NVM_VAR) NvM_InitDown = (boolean)FALSE;

#define NVM_STOP_SEC_VAR_NO_INIT_BOOLEAN
#include "NvM_MemMap.h"

#define NVM_START_SEC_VAR_INIT_UNSPECIFIED
#include "NvM_MemMap.h"
/**
 * @brief Multi-Block Job
 */
STATIC VAR(NvM_JobType, NVM_VAR) NvM_MultiBlockJob = NVM_INVALID_JOB;

#define NVM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "NvM_MemMap.h"

#define NVM_START_SEC_VAR_NO_INIT_8
#include "NvM_MemMap.h"
/**
 * @brief Temporary RAM buffer
 */
STATIC VAR(uint8, NVM_VAR) NvM_NVRAMTemporaryData[NVM_MAX_NVRAM_LENGTH];

#if (STD_ON == NVM_USE_MIRROR_MECHANISM)
/**
 * @brief Mirror block
 */
STATIC VAR(uint8, NVM_VAR) NvM_MirrorBlock[NVM_MAX_SYN_BLOCK_LENGTH];
#endif /*STD_ON == NVM_USE_MIRROR_MECHANISM  */

#define NVM_STOP_SEC_VAR_NO_INIT_8
#include "NvM_MemMap.h"

/*====================================================================================================*
 *                                      LOCAL FUNCTION PROTOTYPES                                   
 *====================================================================================================*/
#define NVM_START_SEC_CODE
#include "NvM_MemMap.h"

STATIC FUNC(void, NVM_CODE) NvM_UpdateCrcToTemporaryBuffer
(
	P2CONST(NvM_BlockDescriptorType, NVM_VAR, NVM_APPL_CONST) pBlockDescriptor,
	VAR(NvM_BlockIdType, AUTOMATIC) BlockId
);

STATIC FUNC(void, NVM_CODE) NvM_CompareCRC
(
	P2CONST(NvM_BlockDescriptorType, NVM_VAR, NVM_APPL_CONST) pBlockDescriptor,
	VAR(NvM_BlockIdType, AUTOMATIC) BlockId
);

STATIC FUNC(void, NVM_CODE) NvM_Callback
(
	P2CONST(NvM_BlockDescriptorType, NVM_VAR, NVM_APPL_CONST) pBlockDescriptor,
	VAR(NvM_BlockIdType, AUTOMATIC) BlockId,
	P2CONST(NvM_AdministrativeBlockType, NVM_VAR, NVM_APPL_CONST) pCurrentJob
);

#if(NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_2 || \
		NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3)
STATIC FUNC(Std_ReturnType, NVM_CODE) NvM_GetJobQueueAndIndex
(
	VAR(uint8, AUTOMATIC) Priority,
	P2VAR(NvM_JobSchedulingType*, AUTOMATIC, NVM_VAR) pJobScheduling,
	P2VAR(NvM_JobQueueType*, AUTOMATIC, NVM_VAR) pJobQueue,
	VAR(uint8, AUTOMATIC) ServiceID
);
#endif /* NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_2 || \
		NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3 */

#if(NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_2 || \
		NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3)
STATIC FUNC(void, NVM_CODE) NvM_SetJobQueue
(
	VAR(uint8, AUTOMATIC) Priority,
	VAR(NvM_BlockIdType, AUTOMATIC) BlockId,
	VAR(NvM_JobType, AUTOMATIC) Job,
	P2VAR(NvM_JobSchedulingType, NVM_VAR, NVM_APPL_CONST) pJobScheduling,
	P2VAR(NvM_JobQueueType, AUTOMATIC, NVM_VAR) pJobQueue
);
#endif /* NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_2 || \
		NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3 */

STATIC FUNC(boolean, NVM_CODE) NvM_GetUpcomingJob(void);

STATIC FUNC(Std_ReturnType, NVM_CODE) NvM_WriteTemporaryBufferToNVRAM
(
	P2CONST(NvM_BlockDescriptorType, NVM_VAR, NVM_APPL_CONST) pBlockDescriptor,
	VAR(NvM_BlockIdType, AUTOMATIC) BlockId,
	P2CONST(NvM_AdministrativeBlockType, NVM_VAR, NVM_APPL_CONST) pCurrentJob
);

STATIC FUNC(Std_ReturnType, NVM_CODE) NvM_ReadTemporaryBufferFromNVRAM
(
	P2CONST(NvM_BlockDescriptorType, NVM_VAR, NVM_APPL_CONST) pBlockDescriptor,
	VAR(NvM_BlockIdType, AUTOMATIC) BlockId,
	P2CONST(NvM_AdministrativeBlockType, NVM_VAR, NVM_APPL_CONST) pCurrentJob
);

STATIC FUNC(Std_ReturnType, NVM_CODE) NvM_RestoreRAMBlockToDefault
(
	P2CONST(NvM_BlockDescriptorType, NVM_VAR, NVM_APPL_CONST) pBlockDescriptor,
	VAR(NvM_BlockIdType, AUTOMATIC) BlockId,
	P2CONST(NvM_AdministrativeBlockType, NVM_VAR, NVM_APPL_CONST) pCurrentJob
);

STATIC FUNC(Std_ReturnType, NVM_CODE) NvM_CalcRamBlockCrcJob
(
	P2CONST(NvM_BlockDescriptorType, NVM_VAR, NVM_APPL_CONST) pBlockDescriptor,
	VAR(NvM_BlockIdType, AUTOMATIC) BlockId,
	P2VAR(uint32, NVM_VAR, NVM_APPL_CONST) pTemporaryCrc
);

STATIC FUNC(void, NVM_CODE) NvM_ReadRAMBlockFromTemporaryBuffer
(
	P2CONST(NvM_BlockDescriptorType, NVM_VAR, NVM_APPL_CONST) pBlockDescriptor,
	VAR(NvM_BlockIdType, AUTOMATIC) BlockId,
	P2VAR(NvM_AdministrativeBlockType, NVM_VAR, NVM_APPL_CONST) pCurrentJob
);

STATIC FUNC(void, NVM_CODE) NvM_WriteRAMBlockToTemporaryBuffer
(
	P2CONST(NvM_BlockDescriptorType, NVM_VAR, NVM_APPL_CONST) pBlockDescriptor,
	VAR(NvM_BlockIdType, AUTOMATIC) BlockId,
	P2CONST(NvM_AdministrativeBlockType, NVM_VAR, NVM_APPL_CONST) pCurrentJob
);

STATIC FUNC(Std_ReturnType, NVM_CODE) NvM_CompareConfigurationID(void);

STATIC FUNC(void, NVM_CODE) NvM_SetMultiBlockWriteJob
(
	P2CONST(NvM_BlockDescriptorType, NVM_VAR, NVM_APPL_CONST) pBlockDescriptor
);

STATIC FUNC(void, NVM_CODE) NvM_SetMultiBlockReadJob
(
	P2CONST(NvM_BlockDescriptorType, NVM_VAR, NVM_APPL_CONST) pBlockDescriptor
);

STATIC FUNC(void, NVM_CODE) NvM_MultiBlockProcessing
(
	P2CONST(NvM_BlockDescriptorType, NVM_VAR, NVM_APPL_CONST) pBlockDescriptor
);

STATIC FUNC(void, NVM_CODE) NvM_SetSingleBlockRestorJob
(
	P2CONST(NvM_BlockDescriptorType, NVM_VAR, NVM_APPL_CONST) pBlockDescriptor,
	VAR(NvM_BlockIdType, AUTOMATIC) BlockId
);

STATIC FUNC(void, NVM_CODE) NvM_SetSingleBlockReadJob
(
	P2CONST(NvM_BlockDescriptorType, NVM_VAR, NVM_APPL_CONST) pBlockDescriptor,
	VAR(NvM_BlockIdType, AUTOMATIC) BlockId,
	P2VAR(NvM_AdministrativeBlockType, NVM_VAR, NVM_APPL_CONST) pCurrentJob
);

STATIC FUNC(void, NVM_CODE) NvM_SetSingleBlockWriteJob
(
	P2CONST(NvM_BlockDescriptorType, NVM_VAR, NVM_APPL_CONST) pBlockDescriptor,
	VAR(NvM_BlockIdType, AUTOMATIC) BlockId,
	P2VAR(NvM_AdministrativeBlockType, NVM_VAR, NVM_APPL_CONST) pCurrentJob
);

STATIC FUNC(void, NVM_CODE) NvM_SingleBlockProcessing
(
	P2CONST(NvM_BlockDescriptorType, NVM_VAR, NVM_APPL_CONST) pBlockDescriptor,
	VAR(NvM_BlockIdType, AUTOMATIC) BlockId,
	P2VAR(NvM_AdministrativeBlockType, NVM_VAR, NVM_APPL_CONST) pCurrentJob
);

STATIC FUNC(void, NVM_CODE) NvM_MemIfJobIsRun
(
	P2CONST(NvM_BlockDescriptorType, NVM_VAR, NVM_APPL_CONST) pBlockDescriptor,
	VAR(NvM_BlockIdType, AUTOMATIC) BlockId,
	P2VAR(NvM_AdministrativeBlockType, NVM_VAR, NVM_APPL_CONST) pCurrentJob
);

STATIC FUNC(void, NVM_CODE) NvM_InternalJobCalculareCRC
(
	P2CONST(NvM_BlockDescriptorType, NVM_VAR, NVM_APPL_CONST) pBlockDescriptor,
	VAR(NvM_BlockIdType, AUTOMATIC) BlockId
);

STATIC FUNC(void, NVM_CODE) NvM_InternalResetBlockDefaultJobFinish
(
	P2CONST(NvM_BlockDescriptorType, NVM_VAR, NVM_APPL_CONST) pBlockDescriptor,
	VAR(NvM_BlockIdType, AUTOMATIC) BlockId,
	P2VAR(NvM_AdministrativeBlockType, NVM_VAR, NVM_APPL_CONST) pCurrentJob
);

STATIC FUNC(void, NVM_CODE) NvM_InternalReadJobFinish
(
	P2CONST(NvM_BlockDescriptorType, NVM_VAR, NVM_APPL_CONST) pBlockDescriptor,
	VAR(NvM_BlockIdType, AUTOMATIC) BlockId,
	P2VAR(NvM_AdministrativeBlockType, NVM_VAR, NVM_APPL_CONST) pCurrentJob
);

STATIC FUNC(void, NVM_CODE) NvM_InternalWriteJobFinish
(
	P2CONST(NvM_BlockDescriptorType, NVM_VAR, NVM_APPL_CONST) pBlockDescriptor,
	VAR(NvM_BlockIdType, AUTOMATIC) BlockId,
	P2VAR(NvM_AdministrativeBlockType, NVM_VAR, NVM_APPL_CONST) pCurrentJob
);

STATIC FUNC(void, NVM_CODE) NvM_InternalEraseOrInvalidateJobFinish
(
	P2CONST(NvM_BlockDescriptorType, NVM_VAR, NVM_APPL_CONST) pBlockDescriptor,
	VAR(NvM_BlockIdType, AUTOMATIC) BlockId,
	P2VAR(NvM_AdministrativeBlockType, NVM_VAR, NVM_APPL_CONST) pCurrentJob
);

STATIC FUNC(void, NVM_CODE) NvM_InternalJobFinish
(
	P2CONST(NvM_BlockDescriptorType, NVM_VAR, NVM_APPL_CONST) pBlockDescriptor,
	VAR(NvM_BlockIdType, AUTOMATIC) BlockId,
	P2VAR(NvM_AdministrativeBlockType, NVM_VAR, NVM_APPL_CONST) pCurrentJob
);

STATIC FUNC(void, NVM_CODE) NvM_InternalJobProcessing
(
	P2CONST(NvM_BlockDescriptorType, NVM_VAR, NVM_APPL_CONST) pBlockDescriptor,
	VAR(NvM_BlockIdType, AUTOMATIC) BlockId,
	P2VAR(NvM_AdministrativeBlockType, NVM_VAR, NVM_APPL_CONST) pCurrentJob
);

#if(NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_2 || \
		NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3)
STATIC FUNC(void, NVM_CODE) NvM_CancelJobInQueue
(
	P2VAR(NvM_JobSchedulingType, NVM_VAR, NVM_APPL_CONST) pJobScheduling,
	VAR(NvM_BlockIdType, AUTOMATIC) BlockId
);
#endif /* NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_2 || \
		NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3 */

#if (STD_ON == NVM_POLLING_MODE)
STATIC FUNC(void, NVM_CODE) NvM_GetMemIfStatus(void);
#endif /* STD_ON == NVM_POLLING_MODE */

STATIC FUNC(boolean, NVM_CODE) NvM_CompareStaticBlockId
(
	P2CONST(NvM_BlockDescriptorType, NVM_VAR, NVM_APPL_CONST) pBlockDescriptor,
	VAR(NvM_BlockIdType, AUTOMATIC) BlockId,
	P2CONST(NvM_AdministrativeBlockType, NVM_VAR, NVM_APPL_CONST) pCurrentJob
);

STATIC FUNC(void, NVM_CODE) NvM_WriteValidation
(
	P2CONST(NvM_BlockDescriptorType, NVM_VAR, NVM_APPL_CONST) pBlockDescriptor,
	VAR(NvM_BlockIdType, AUTOMATIC) BlockId,
	P2CONST(NvM_AdministrativeBlockType, NVM_VAR, NVM_APPL_CONST) pCurrentJob
);

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h"

/*====================================================================================================*
 *                                           LOCAL FUNCTIONS                                        
 *====================================================================================================*/
#define NVM_START_SEC_CODE
#include "NvM_MemMap.h"

/**
 * @brief   	Update the value of the temporary buffer
 * @details
 * @param[in]      pBlockDescriptor		A pointer to block configuration information
 * @param[in]      BlockId				Block Id
 */
STATIC FUNC(void, NVM_CODE) NvM_UpdateCrcToTemporaryBuffer
(
	P2CONST(NvM_BlockDescriptorType, NVM_VAR, NVM_APPL_CONST) pBlockDescriptor,
	VAR(NvM_BlockIdType, AUTOMATIC) BlockId
)
{
	VAR(uint16, AUTOMATIC) length;
	VAR(uint8, AUTOMATIC) Offset = 0U;
	/* PRQA S 0492 EOF # There is a judgment before the program */
	if((boolean)TRUE == NVM_GET_STATIC_BLOCK_ID_CHECK(pBlockDescriptor,BlockId-1U))
	{
		Offset = 4U;
	}
	length = NVM_GET_NV_BLOCK_LENGTH(pBlockDescriptor,BlockId-1U);

	/* PRQA S 2844 EOF # The array index will not be exceeded */
	if(NVM_CRC8 == NVM_GET_BLOCK_CRC_LENGTH(pBlockDescriptor, BlockId-1U))
	{
		NvM_NVRAMTemporaryData[Offset+length] = (uint8)((NvM_RunJob.NvM_TemporaryCrc) & 0xffU);
	}
	else if(NVM_CRC16 == NVM_GET_BLOCK_CRC_LENGTH(pBlockDescriptor, BlockId-1U))
	{
		NvM_NVRAMTemporaryData[Offset+length] = (uint8)((NvM_RunJob.NvM_TemporaryCrc) & 0xffU);
		NvM_NVRAMTemporaryData[Offset+length+1U] = (uint8)((NvM_RunJob.NvM_TemporaryCrc >> 8U) & 0xffU);
	}
	else if(NVM_CRC32 == NVM_GET_BLOCK_CRC_LENGTH(pBlockDescriptor, BlockId-1U))
	{
		NvM_NVRAMTemporaryData[Offset+length] = (uint8)(NvM_RunJob.NvM_TemporaryCrc & 0xffU);
		NvM_NVRAMTemporaryData[Offset+length+1U] = (uint8)((NvM_RunJob.NvM_TemporaryCrc >> 8U) & 0xffU);
		NvM_NVRAMTemporaryData[Offset+length+2U] = (uint8)((NvM_RunJob.NvM_TemporaryCrc >> 16U) & 0xffU);
		NvM_NVRAMTemporaryData[Offset+length+3U] = (uint8)(NvM_RunJob.NvM_TemporaryCrc >> 24U);
	}
	else
	{
		/* Do nothing */
	}
}

/**
 * @brief          Service for compare CRC
 * @details
 *
 * @param[in]      pBlockDescriptor		A pointer to block configuration information
 * @param[in]      BlockId				Block Id
 */
STATIC FUNC(void, NVM_CODE) NvM_CompareCRC
(
	P2CONST(NvM_BlockDescriptorType, NVM_VAR, NVM_APPL_CONST) pBlockDescriptor,
	VAR(NvM_BlockIdType, AUTOMATIC) BlockId
)
{
	VAR(uint16, AUTOMATIC) CrcOffset = 0U;
	VAR(uint16, AUTOMATIC) count = 0U;
	P2VAR(uint8, NVM_VAR, NVM_APPL_CONST) pData;
	/* PRQA S 2985, 2986 EOF # The logarithmic group is not required to handle special processing */
	NVM_GET_BLOCK_CRC_OFFSET(pBlockDescriptor,BlockId-1U,CrcOffset);
	/* PRQA S 2934 EOF # The array index will not be exceeded */
	pData = &NvM_NVRAMTemporaryData[CrcOffset];

	do
	{
		/* PRQA S 0491 EOF # The logarithmic group is not required to handle special processing */
		if(pData[count] != (uint8)((NvM_RunJob.NvM_TemporaryCrc >> (count*8U)) & 0xffU))
		{
			NvM_RunJob.NvM_InternalJobStatus = NVM_JOB_CRC_FAIL;
			break;
		}
		else
		{
			NvM_RunJob.NvM_InternalJobStatus = NVM_JOB_OK;
		}
		count++;
	}while(count < (uint16)NVM_GET_BLOCK_CRC_LENGTH(pBlockDescriptor,BlockId-1U));
}

/**
 * @brief          Job end callback
 * @details
 *
 * @param[in]      pBlockDescriptor		A pointer to block configuration information
 * @param[in]      BlockId				Block Id
 * @param[in]      pCurrentJob			A pointer to the management block of the current block
 */
STATIC FUNC(void, NVM_CODE) NvM_Callback
(
	P2CONST(NvM_BlockDescriptorType, NVM_VAR, NVM_APPL_CONST) pBlockDescriptor,
	VAR(NvM_BlockIdType, AUTOMATIC) BlockId,
	P2CONST(NvM_AdministrativeBlockType, NVM_VAR, NVM_APPL_CONST) pCurrentJob
)
{
	VAR(uint8, AUTOMATIC) ServiceId = 0U;

	if(((NVM_READ_ALL == NvM_RunJob.NvM_CurrentRunJob) || \
		(NVM_WRITE_ALL == NvM_RunJob.NvM_CurrentRunJob) || \
		(NVM_VALIDATE_ALL == NvM_RunJob.NvM_CurrentRunJob)) &&
		(((boolean)TRUE == NvM_RunJob.NvM_MultipleRequestEnd) && \
		 ((boolean)TRUE != NvM_RunJob.NvM_MultipleBlocksToWrite) && \
		 ((boolean)TRUE != NvM_RunJob.NvM_MultipleBlocksToRead) && \
		 ((boolean)TRUE != NvM_RunJob.NvM_RestoreDefaultJob)))
	{
		if(NVM_REQ_CANCELED == NvM_MultiBlockRequestResult)
		{
			NvM_MultiBlockJob = NVM_INVALID_JOB;
#if (NVM_MULTI_BLOCK_CALLBACK == STD_ON)
			NVM_CALL_MULTI_BLOCK_CALLBACK(NVM_SID_CANCELWRITEALL, NvM_MultiBlockRequestResult);
#endif /* (NVM_MULTI_BLOCK_CALLBACK == STD_ON) */
		}
		else if(NVM_WRITE_ALL == NvM_RunJob.NvM_CurrentRunJob)
		{
#if (NVM_MULTI_BLOCK_CALLBACK == STD_ON)
			NVM_CALL_MULTI_BLOCK_CALLBACK(NVM_SID_WRITEALL, NvM_MultiBlockRequestResult);
#endif /* (NVM_MULTI_BLOCK_CALLBACK == STD_ON) */
		}
		else if(NVM_READ_ALL == NvM_RunJob.NvM_CurrentRunJob)
		{
#if (NVM_MULTI_BLOCK_CALLBACK == STD_ON)
			NVM_CALL_MULTI_BLOCK_CALLBACK(NVM_SID_READALL, NvM_MultiBlockRequestResult);
#endif
		}
		else /* NVM_VALIDATE_ALL == NvM_RunJob.NvM_CurrentRunJob */
		{
#if (NVM_MULTI_BLOCK_CALLBACK == STD_ON)
			NVM_CALL_MULTI_BLOCK_CALLBACK(NVM_SID_VALIDATEALL, NvM_MultiBlockRequestResult);
#endif
		}

		/* End the current job */
		NvM_RunJob.NvM_CurrentRunJob = NVM_INVALID_JOB;
	}
	else if(((NVM_READ_ALL == NvM_RunJob.NvM_CurrentRunJob) || \
			(NVM_WRITE_ALL == NvM_RunJob.NvM_CurrentRunJob) || \
			(NVM_VALIDATE_ALL == NvM_RunJob.NvM_CurrentRunJob)) &&
			((boolean)TRUE == NvM_RunJob.NvM_MultipleRequestEnd))
	{
		if(NVM_REQ_CANCELED == NvM_MultiBlockRequestResult)
		{
			NvM_MultiBlockJob = NVM_INVALID_JOB;
#if (NVM_BSWM_MULTIBLOCK_JOBSTATUS_INFORMATION == STD_ON)
			BswM_NvM_CurrentJobMode(NVM_SID_CANCELWRITEALL, NvM_MultiBlockRequestResult);
#endif /* (NVM_BSWM_MULTIBLOCK_JOBSTATUS_INFORMATION == STD_ON) */
		}
		else if(NVM_WRITE_ALL == NvM_RunJob.NvM_CurrentRunJob)
		{
#if (NVM_BSWM_MULTIBLOCK_JOBSTATUS_INFORMATION == STD_ON)
			BswM_NvM_CurrentJobMode(NVM_SID_WRITEALL,NvM_MultiBlockRequestResult);
#endif /* (NVM_BSWM_MULTIBLOCK_JOBSTATUS_INFORMATION == STD_ON) */
		}
		else if(NVM_READ_ALL == NvM_RunJob.NvM_CurrentRunJob)
		{
#if (NVM_BSWM_MULTIBLOCK_JOBSTATUS_INFORMATION == STD_ON)
			BswM_NvM_CurrentJobMode(NVM_SID_READALL,NvM_MultiBlockRequestResult);
#endif /* (NVM_BSWM_MULTIBLOCK_JOBSTATUS_INFORMATION == STD_ON) */
		}
		else /* NVM_VALIDATE_ALL == NvM_RunJob.NvM_CurrentRunJob */
		{
#if (NVM_BSWM_MULTIBLOCK_JOBSTATUS_INFORMATION == STD_ON)
			BswM_NvM_CurrentJobMode(NVM_SID_VALIDATEALL,NvM_MultiBlockRequestResult);
#endif /* (NVM_BSWM_MULTIBLOCK_JOBSTATUS_INFORMATION == STD_ON) */
		}

		/* End the current job */
		NvM_RunJob.NvM_CurrentRunJob = NVM_INVALID_JOB;
	}
	else
	{
		if(NVM_READ_BLOCK == NvM_RunJob.NvM_CurrentRunJob)
		{
			ServiceId = NVM_SID_READBLOCK;
		}
		else if(NVM_WRITE_BLOCK == NvM_RunJob.NvM_CurrentRunJob)
		{
			ServiceId = NVM_SID_WRITEBLOCK;
		}
		else if(NVM_RESTORE_BLOCK_DEFAULTS == NvM_RunJob.NvM_CurrentRunJob)
		{
			ServiceId = NVM_SID_RESTOREBLOCKDEFAULTS;
		}
		else if(NVM_ERASE_NV_BLOCK == NvM_RunJob.NvM_CurrentRunJob)
		{
			ServiceId = NVM_SID_ERASENVBLOCK;
		}
		else if(NVM_INVALIDATE_NV_BLOCK == NvM_RunJob.NvM_CurrentRunJob)
		{
			ServiceId = NVM_SID_INVALIDATENVBLOCK;
		}
		else if(NVM_READ_PRAM_BLOCK == NvM_RunJob.NvM_CurrentRunJob)
		{
			ServiceId = NVM_SID_READPRAMBLOCK;
		}
		else if(NVM_WRITE_PRAM_BLOCK == NvM_RunJob.NvM_CurrentRunJob)
		{
			ServiceId = NVM_SID_WRITEPRAMBLOCK;
		}
		else if(NVM_RESTORE_PRAM_BLOCK_DEFAULTS == NvM_RunJob.NvM_CurrentRunJob)
		{
			ServiceId = NVM_SID_RESTOREPRAMBLOCKDEFAULTS;
		}
		else if(NVM_READ_ALL == NvM_RunJob.NvM_CurrentRunJob)
		{
			ServiceId = NVM_SID_READALL;
		}
		else if(NVM_WRITE_ALL == NvM_RunJob.NvM_CurrentRunJob)
		{
			ServiceId = NVM_SID_WRITEALL;
		}
		else
		{
			/* Do nothing */
		}

		if(NULL_PTR != NVM_GET_SINGLE_BLOCK_CALLBACK(pBlockDescriptor, BlockId-1U))
		{
			(void)NVM_CALL_SINGLE_BLOCK_CALLBACK(pBlockDescriptor, BlockId-1U, \
					ServiceId, pCurrentJob->NvM_BlockRequestResult);
		}

		if((boolean)TRUE == NVM_IS_NOTIFY_BSWM(pBlockDescriptor, BlockId-1U))
		{
#if (NVM_BSWM_BLOCKSTATUS_INFORMATION == STD_ON)
			BswM_NvM_CurrentBlockMode(BlockId, pCurrentJob->NvM_BlockRequestResult);
#endif /* (NVM_BSWM_BLOCKSTATUS_INFORMATION == STD_ON) */
		}

		if((NVM_REQ_PENDING != NvM_MultiBlockRequestResult) || \
				((NvM_RunJob.NvM_CurrentRunJob != NVM_READ_ALL) && \
				(NvM_RunJob.NvM_CurrentRunJob != NVM_WRITE_ALL) && \
				(NvM_RunJob.NvM_CurrentRunJob != NVM_VALIDATE_ALL)))
		{
			/* End the current job */
			NvM_RunJob.NvM_CurrentRunJob = NVM_INVALID_JOB;
		}
	}
}

#if(NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_2 || \
		NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3)
/**
 * @brief          Get an empty queue and schedule pointer
 * @details
 *
 * @param[in]      Priority			Block priority
 * @param[out]     pJobScheduling	A pointer to which the scheduling pointer is stored
 * @param[out]     pJobQueue		Point to an empty queue
 * @param[in]      ServiceID		Service id
 */
STATIC FUNC(Std_ReturnType, NVM_CODE) NvM_GetJobQueueAndIndex
(
	VAR(uint8, AUTOMATIC) Priority,
	P2VAR(NvM_JobSchedulingType*, AUTOMATIC, NVM_VAR) pJobScheduling,
	P2VAR(NvM_JobQueueType*, AUTOMATIC, NVM_VAR) pJobQueue,
	VAR(uint8, AUTOMATIC) ServiceID
)
{
	VAR(Std_ReturnType, AUTOMATIC) ret = (Std_ReturnType)E_NOT_OK;
	VAR(uint16, AUTOMATIC) Index = 0U;
#if (NVM_JOB_PRIORITIZATION == STD_ON)
	VAR(uint16, AUTOMATIC) ImmediateJobQueueSize = NVM_SIZE_IMMEDIATE_JOB_QUEUE;
#endif /* NVM_JOB_PRIORITIZATION == STD_ON */
	VAR(uint16, AUTOMATIC) StandardJobQueueSize = NVM_SIZE_STANDARD_JOB_QUEUE;

#if (NVM_JOB_PRIORITIZATION == STD_ON)
	if
	(
		(0U == Priority) &&
		((ServiceID == NVM_SID_WRITEBLOCK) || (ServiceID == NVM_SID_WRITEPRAMBLOCK))
	)
	{
		NVM_GET_EMPTY_QUEUE(Index,(*pJobQueue),NvM_ImmediateJobQueue,ImmediateJobQueueSize);

		(*pJobScheduling) = &NvM_ImmediateJobScheduling;
	}
	else
#endif /* NVM_JOB_PRIORITIZATION == STD_ON */
	{
		NVM_GET_EMPTY_QUEUE(Index,(*pJobQueue),NvM_StandardJobQueue,StandardJobQueueSize);

		(*pJobScheduling) = &NvM_StandardJobScheduling;
	}

	if(NULL_PTR != (*pJobQueue))
	{
		ret = (Std_ReturnType)E_OK;
	}
	else
	{
#if (STD_ON == NVM_E_QUEUE_OVERFLOW_SWITCH)
		Dem_ReportErrorStatus(NVM_E_QUEUE_OVERFLOW, DEM_EVENT_STATUS_FAILED);
#endif /* STD_ON == NVM_E_QUEUE_OVERFLOW_SWITCH */
	}

	return ret;
}
#endif /* NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_2 || \
		NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_1 */

#if(NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_2 || \
		NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3)
/**
 * @brief          Set the Job to a queue
 * @details
 *
 * @param[in]      Priority			Block priority
 * @param[in]	   BlockId
 * @param[in]	   Job
 * @param[in/out]  pJobScheduling	Point to Queue scheduling
 * @param[in/out]  pJobQueue		Point to an empty queue
 */
STATIC FUNC(void, NVM_CODE) NvM_SetJobQueue
(
	VAR(uint8, AUTOMATIC) Priority,
	VAR(NvM_BlockIdType, AUTOMATIC) BlockId,
	VAR(NvM_JobType, AUTOMATIC) Job,
	P2VAR(NvM_JobSchedulingType, NVM_VAR, NVM_APPL_CONST) pJobScheduling,
	P2VAR(NvM_JobQueueType, AUTOMATIC, NVM_VAR) pJobQueue
)
{
	VAR(uint16, AUTOMATIC) JobNumber = pJobScheduling->NvM_JobNumber;
	P2VAR(NvM_JobQueueType, AUTOMATIC, NVM_APPL_CONST) pCurrentJob = \
			pJobScheduling->NvM_CurrentJob;

	pJobQueue->NvM_BlockId = BlockId;
	pJobQueue->NvM_Job = Job;
	pJobQueue->NvM_JobPriority = Priority;
	pJobQueue->NvM_JobIsValid = (boolean)TRUE;

	if(NULL_PTR == pCurrentJob)
	{
		pJobScheduling->NvM_CurrentJob = pJobQueue;
	}
	else if(pCurrentJob->NvM_JobPriority > Priority)
	{
		pJobQueue->NvM_NextJob = pCurrentJob;
		pJobScheduling->NvM_CurrentJob = pJobQueue;
	}
	else
	{
		/* PRQA S 0771 EOF # Conditional judgment */
		do
		{
			if(NULL_PTR == pCurrentJob->NvM_NextJob)
			{
				pCurrentJob->NvM_NextJob = pJobQueue;
				break;
			}
			else if(pCurrentJob->NvM_NextJob->NvM_JobPriority > Priority)
			{
				pJobQueue->NvM_NextJob = pCurrentJob->NvM_NextJob;
				pCurrentJob->NvM_NextJob = pJobQueue;
				break;
			}
			else
			{
				pCurrentJob = pCurrentJob->NvM_NextJob;
			}

			JobNumber--;

		}while(JobNumber != 0U);
	}
	NvM_AdministrativeBlock[BlockId-1U].NvM_BlockRequestResult = NVM_REQ_PENDING;
	pJobScheduling->NvM_JobNumber++;
}
#endif /* NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_2 || \
		NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_1 */

/**
 * @brief   Set the Job to a queue
 * @details
 * @return	boolean
 * @retval 	FALSE:	There are no Jobs that need to be executed
 * 			TRUE:	The job that needs to be executed has been obtained
 */
STATIC FUNC(boolean, NVM_CODE) NvM_GetUpcomingJob(void)
{
	VAR(boolean, AUTOMATIC) ret = (boolean)TRUE;

	if(NvM_RunJob.NvM_CurrentRunJob == NVM_INVALID_JOB)
	{
#if (NVM_JOB_PRIORITIZATION == STD_ON)
		if(NvM_ImmediateJobScheduling.NvM_CurrentJob != NULL_PTR)
		{
			NvM_RunJob.NvM_CurrentRunJob = \
					NvM_ImmediateJobScheduling.NvM_CurrentJob->NvM_Job;
			NvM_RunJob.NvM_CurrentRunBlockId = \
					NvM_ImmediateJobScheduling.NvM_CurrentJob->NvM_BlockId;
			NvM_RunJob.NvM_IsInterrupted = (boolean)FALSE;

			NVM_CLEAR_RUN_JOB();
#if (STD_ON == NVM_USE_MIRROR_MECHANISM)
			NvM_RunJob.NvM_NumOfMirrorOperationRetries = 0U;
#endif /* STD_ON == NVM_USE_MIRROR_MECHANISM */
			/* PRQA S 1862 EOF # Internal operation is judged */
			NVM_UNLOAD_CURRENT_JOB_AND_LOAD_NEXT_JOB(NvM_ImmediateJobScheduling);
		}
		else if(NvM_RunJob.NvM_InterruptedJob != NVM_INVALID_JOB)
		{
			NvM_RunJob.NvM_CurrentRunJob = NvM_RunJob.NvM_InterruptedJob;
			NvM_RunJob.NvM_CurrentRunBlockId = NvM_RunJob.NvM_InterruptedBlockId;
			NvM_RunJob.NvM_IsInterrupted = (boolean)TRUE;

			NVM_CLEAR_RUN_JOB();
#if (STD_ON == NVM_USE_MIRROR_MECHANISM)
			NvM_RunJob.NvM_NumOfMirrorOperationRetries = 0U;
#endif /* STD_ON == NVM_USE_MIRROR_MECHANISM */

			/* Clear Log */
			NvM_RunJob.NvM_InterruptedJob = NVM_INVALID_JOB;
			NvM_RunJob.NvM_InterruptedBlockId = 0U;
		}
		else
#endif /* NVM_JOB_PRIORITIZATION == STD_ON */
			if(NvM_StandardJobScheduling.NvM_CurrentJob != NULL_PTR)
		{
			NvM_RunJob.NvM_CurrentRunJob = \
					NvM_StandardJobScheduling.NvM_CurrentJob->NvM_Job;
			NvM_RunJob.NvM_CurrentRunBlockId = \
					NvM_StandardJobScheduling.NvM_CurrentJob->NvM_BlockId;
			NvM_RunJob.NvM_IsInterrupted = (boolean)TRUE;

			NVM_CLEAR_RUN_JOB();
#if (STD_ON == NVM_USE_MIRROR_MECHANISM)
			NvM_RunJob.NvM_NumOfMirrorOperationRetries = 0U;
#endif /* STD_ON == NVM_USE_MIRROR_MECHANISM */

			NVM_UNLOAD_CURRENT_JOB_AND_LOAD_NEXT_JOB(NvM_StandardJobScheduling);
		}
		else if(NvM_MultiBlockJob != NVM_INVALID_JOB)
		{
			NvM_RunJob.NvM_CurrentRunJob = NvM_MultiBlockJob;
			NvM_RunJob.NvM_CurrentRunBlockId = 1U;
			/* Multi-block operations cannot be interrupted */
			NvM_RunJob.NvM_IsInterrupted = (boolean)FALSE;
			NvM_RunJob.NvM_PreMultiBlockRequestResult = NvM_MultiBlockRequestResult;

			NVM_CLEAR_RUN_JOB();
#if (STD_ON == NVM_USE_MIRROR_MECHANISM)
			NvM_RunJob.NvM_NumOfMirrorOperationRetries = 0U;
#endif /* STD_ON == NVM_USE_MIRROR_MECHANISM */

			NvM_MultiBlockJob = NVM_INVALID_JOB;
		}
		else
		{
			ret = (boolean)FALSE;
		}
	}
	else
	{
#if (NVM_JOB_PRIORITIZATION == STD_ON)
		if(NvM_RunJob.NvM_IsInterrupted == (boolean)FALSE)
		{
			/* Do nothing */
		}
		else
		{
			if(NvM_ImmediateJobScheduling.NvM_CurrentJob == NULL_PTR)
			{
				/* Do nothing */
			}
			else
			{
				/* Log interrupted Job */
				NvM_RunJob.NvM_InterruptedBlockId = NvM_RunJob.NvM_CurrentRunBlockId;
				NvM_RunJob.NvM_InterruptedJob = NvM_RunJob.NvM_CurrentRunJob;

				/* Reset the current Job */
				NvM_RunJob.NvM_CurrentRunJob = \
						NvM_ImmediateJobScheduling.NvM_CurrentJob->NvM_Job;
				NvM_RunJob.NvM_CurrentRunBlockId = \
						NvM_ImmediateJobScheduling.NvM_CurrentJob->NvM_BlockId;
				NvM_RunJob.NvM_IsInterrupted = (boolean)FALSE;

				NVM_CLEAR_RUN_JOB();
#if (STD_ON == NVM_USE_MIRROR_MECHANISM)
				NvM_RunJob.NvM_NumOfMirrorOperationRetries = 0U;
#endif /* STD_ON == NVM_USE_MIRROR_MECHANISM */

				NVM_UNLOAD_CURRENT_JOB_AND_LOAD_NEXT_JOB(NvM_ImmediateJobScheduling);
			}
		}
#endif /* NVM_JOB_PRIORITIZATION == STD_ON */
	}

	return ret;
}

/**
 * @brief   Call MemIf to write tempoeary data to the Nv block
 * @details
 * @param[in]      pBlockDescriptor		A pointer to block configuration information
 * @param[in]      BlockId				Block Id
 * @param[in]      pCurrentJob			A pointer to the management block of the current block
 * @return	Std_ReturnType
 * @retval 	E_OK:		The job is successfully delivered
 * 			E_NOT_OK: 	The job is fails to be delivered
 */
STATIC FUNC(Std_ReturnType, NVM_CODE) NvM_WriteTemporaryBufferToNVRAM
(
	P2CONST(NvM_BlockDescriptorType, NVM_VAR, NVM_APPL_CONST) pBlockDescriptor,
	VAR(NvM_BlockIdType, AUTOMATIC) BlockId,
	P2CONST(NvM_AdministrativeBlockType, NVM_VAR, NVM_APPL_CONST) pCurrentJob
)
{
	VAR(Std_ReturnType, AUTOMATIC) ret;

	ret = MemIf_Write
			(
				NVM_GET_BLOCK_DEVICE_INDEX(pBlockDescriptor,BlockId-1U),
				NVM_GET_CURRENT_BLOCK_NUMBER(pCurrentJob,pBlockDescriptor,BlockId-1U),
				NvM_NVRAMTemporaryData
			);

	return ret;
}

/**
 * @brief   Call MemIf to read tempoeary data from the Nv block
 * @details
 * @param[in]      pBlockDescriptor		A pointer to block configuration information
 * @param[in]      BlockId				Block Id
 * @param[in]      pCurrentJob			A pointer to the management block of the current block
 * @return	Std_ReturnType
 * @retval 	E_OK:		The job is successfully delivered
 * 			E_NOT_OK: 	The job is fails to be delivered
 */
STATIC FUNC(Std_ReturnType, NVM_CODE) NvM_ReadTemporaryBufferFromNVRAM
(
	P2CONST(NvM_BlockDescriptorType, NVM_VAR, NVM_APPL_CONST) pBlockDescriptor,
	VAR(NvM_BlockIdType, AUTOMATIC) BlockId,
	P2CONST(NvM_AdministrativeBlockType, NVM_VAR, NVM_APPL_CONST) pCurrentJob
)
{
	VAR(Std_ReturnType, AUTOMATIC) ret;
	VAR(uint16, AUTOMATIC) BlockLength = 0U;
	/* PRQA S 4434 EOF # It has to do with pre-compilation */
	NVM_GET_BLOCK_LENGTH(pBlockDescriptor,BlockId-1U,BlockLength);

	ret = MemIf_Read
			(
				NVM_GET_BLOCK_DEVICE_INDEX(pBlockDescriptor,BlockId-1U),
				NVM_GET_CURRENT_BLOCK_NUMBER(pCurrentJob,pBlockDescriptor,BlockId-1U),
				0U,
				NvM_NVRAMTemporaryData,
				BlockLength
			);

	return ret;
}

/**
 * @brief   	Restore the RAM to default value
 * @details
 * @param[in]      pBlockDescriptor		A pointer to block configuration information
 * @param[in]      BlockId				Block Id
 * @param[in]      pCurrentJob			A pointer to the management block of the current block
 * @return	Std_ReturnType
 * @retval 	E_OK:		The job is successfully executed
 * 			E_NOT_OK:	The job failed to be executed
 */
STATIC FUNC(Std_ReturnType, NVM_CODE) NvM_RestoreRAMBlockToDefault
(
	P2CONST(NvM_BlockDescriptorType, NVM_VAR, NVM_APPL_CONST) pBlockDescriptor,
	VAR(NvM_BlockIdType, AUTOMATIC) BlockId,
	P2CONST(NvM_AdministrativeBlockType, NVM_VAR, NVM_APPL_CONST) pCurrentJob
)
{
	VAR(Std_ReturnType, AUTOMATIC) ret = (Std_ReturnType)E_OK;
	P2CONST(uint8, NVM_VAR, NVM_APPL_CONST) ROMData = \
			NVM_GET_ROM_BLOCK_ADDRESS(pBlockDescriptor,BlockId-1U);
	P2VAR(uint8, NVM_VAR, NVM_APPL_CONST) RAMData = \
			NVM_GET_CURRENT_RAM_BLOCK_ADDRESS(pCurrentJob);
	VAR(NvM_InitBlockCallbackType, AUTOMATIC) NvM_CallInitback = \
			NVM_GET_INIT_BLOCK_CALLBACK(pBlockDescriptor,BlockId-1U);
	VAR(uint32, AUTOMATIC) ROMDataIndex = 0U;
	VAR(uint16, AUTOMATIC) count = 0U;

	if(NVM_BLOCK_DATASET == NVM_GET_BLOCK_MANAGEMENT_TYPE(pBlockDescriptor,BlockId-1U))
	{
		ROMDataIndex = (((uint32)NvM_AdministrativeBlock[BlockId-1U].NvM_BlockIndex - \
				(uint32)NVM_GET_NV_BLOCK_NUMBER(pBlockDescriptor,BlockId-1U)) * \
						(uint32)NVM_GET_NV_BLOCK_LENGTH(pBlockDescriptor,BlockId-1U));
	}

	/* @req [SWS_NvM_00266] */
	if(NULL_PTR != ROMData)
	{
		/* Restore the default values via the ROM block */
		do
		{
			RAMData[count] = ROMData[count+ROMDataIndex];
			count++;
		}while(count < NVM_GET_NV_BLOCK_LENGTH(pBlockDescriptor,BlockId-1U));
	}
	else if(NULL_PTR != NvM_CallInitback)
	{
		/* Restore the default values with NvM_InitBlockCallback */
		ret = NvM_CallInitback();
	}
	else
	{
		ret = (Std_ReturnType)E_NOT_OK;
	}

	return ret;
}

/**
 * @brief   	Calc CRC
 * @details
 * @param[in]      pBlockDescriptor		A pointer to block configuration information
 * @param[in]      BlockId				Block Id
 * @param[in/out]  pTemporaryCrc		Point to CRC storage location
 * @return	Std_ReturnType
 * @retval 	E_OK:		The job is successfully executed
 * 			E_NOT_OK:	The job failed to be executed
 */
STATIC FUNC(Std_ReturnType, NVM_CODE) NvM_CalcRamBlockCrcJob
(
	P2CONST(NvM_BlockDescriptorType, NVM_VAR, NVM_APPL_CONST) pBlockDescriptor,
	VAR(NvM_BlockIdType, AUTOMATIC) BlockId,
	P2VAR(uint32, NVM_VAR, NVM_APPL_CONST) pTemporaryCrc
)
{
	VAR(Std_ReturnType, AUTOMATIC) ret = (Std_ReturnType)E_NOT_OK;
	VAR(boolean, AUTOMATIC) IsFirstCall;
	P2VAR(uint8, NVM_VAR, NVM_APPL_CONST) pData;
	VAR(uint32, AUTOMATIC) Length;
	P2VAR(NvM_AdministrativeBlockType, NVM_VAR, NVM_APPL_CONST) pCurrentJob = \
			&NvM_AdministrativeBlock[BlockId-1U];
	VAR(uint8, AUTOMATIC) Offset = 0U;

	if(0U == NvM_RunJob.NvM_CrcCalculatedBytes)
	{
		IsFirstCall = (boolean)TRUE;
	}
	else
	{
		IsFirstCall = (boolean)FALSE;
	}

	if((NvM_RunJob.NvM_CurrentRunJob == NVM_READ_BLOCK) || \
			(NvM_RunJob.NvM_CurrentRunJob == NVM_READ_PRAM_BLOCK) || \
			(NvM_RunJob.NvM_MultipleBlocksToRead == (boolean)TRUE))
	{
		if((boolean)TRUE == NVM_GET_STATIC_BLOCK_ID_CHECK(pBlockDescriptor,BlockId-1U))
		{
			Offset = 4U;
		}

		pData = &NvM_NVRAMTemporaryData[NvM_RunJob.NvM_CrcCalculatedBytes + Offset];
	}
	else
	{
		if(1U == BlockId)
		{
			/* PRQA S 0488 , 0311 EOF # The pointer operation does not need to be modified */
			pData = (uint8*)(NVM_GET_CONFIGURATION_ID_ADDRESS() + NvM_RunJob.NvM_CrcCalculatedBytes);
		}
		else
		{
			pData = NVM_GET_CURRENT_RAM_BLOCK_ADDRESS(pCurrentJob) + NvM_RunJob.NvM_CrcCalculatedBytes;
		}
	}

	if((uint16)(NvM_RunJob.NvM_CrcCalculatedBytes+NVM_CRC_NUM_OF_BYTES) >=  \
			NVM_GET_NV_BLOCK_LENGTH(pBlockDescriptor,BlockId-1U))
	{
		Length = (uint32)NVM_GET_NV_BLOCK_LENGTH(pBlockDescriptor,BlockId-1U) - \
				(uint32)NvM_RunJob.NvM_CrcCalculatedBytes;
		ret = (Std_ReturnType)E_OK;
	}
	else
	{
		Length = NVM_CRC_NUM_OF_BYTES;
	}

	if(NVM_CRC8 == NVM_GET_BLOCK_CRC_LENGTH(pBlockDescriptor, BlockId-1U))
	{
		(*pTemporaryCrc) = (uint32)Crc_CalculateCRC8(
					pData,
					Length,
					(uint8)(*pTemporaryCrc),
					IsFirstCall);
	}
	else if(NVM_CRC16 == NVM_GET_BLOCK_CRC_LENGTH(pBlockDescriptor, BlockId-1U))
	{
		(*pTemporaryCrc) = (uint32)Crc_CalculateCRC16(
					pData,
					Length,
					(uint16)((*pTemporaryCrc)),
					IsFirstCall);
	}
	else if(NVM_CRC32 == NVM_GET_BLOCK_CRC_LENGTH(pBlockDescriptor, BlockId-1U))
	{
		(*pTemporaryCrc) = (uint32)Crc_CalculateCRC32(
					pData,
					Length,
					(uint32)((*pTemporaryCrc)),
					IsFirstCall);
	}
	else
	{
		/* Do nothing */
	}

	if(ret == (Std_ReturnType)E_NOT_OK)
	{
		NvM_RunJob.NvM_CrcCalculatedBytes += (uint16)Length;
	}
	else
	{
		NvM_RunJob.NvM_CrcCalculatedBytes = 0U;
	}

	return ret;
}

/**
 * @brief   	Read the temporary data buffer data to the RAM block
 * @details
 * @param[in]      pBlockDescriptor		A pointer to block configuration information
 * @param[in]      BlockId				Block Id
 * @param[in]      pCurrentJob			A pointer to the management block of the current block
 */
STATIC FUNC(void, NVM_CODE) NvM_ReadRAMBlockFromTemporaryBuffer
(
	P2CONST(NvM_BlockDescriptorType, NVM_VAR, NVM_APPL_CONST) pBlockDescriptor,
	VAR(NvM_BlockIdType, AUTOMATIC) BlockId,
	P2VAR(NvM_AdministrativeBlockType, NVM_VAR, NVM_APPL_CONST) pCurrentJob
)
{
	VAR(uint16, AUTOMATIC) count = 0U;
	VAR(uint8, AUTOMATIC) Offset = 0U;
	P2VAR(uint8, NVM_VAR, NVM_APPL_CONST) pData = NVM_GET_CURRENT_RAM_BLOCK_ADDRESS(pCurrentJob);

	if((boolean)TRUE == NVM_GET_STATIC_BLOCK_ID_CHECK(pBlockDescriptor,BlockId-1U))
	{
		Offset = 4U;
	}

	do
	{
		pData[count] = NvM_NVRAMTemporaryData[Offset+count];
		count++;
	}while(count < NVM_GET_NV_BLOCK_LENGTH(pBlockDescriptor,BlockId-1U));

	pCurrentJob->NvM_BlockCrc = NvM_RunJob.NvM_TemporaryCrc;
}

/**
 * @brief   	Write the RAM block data to the temporary data buffer
 * @details
 * @param[in]      pBlockDescriptor		A pointer to block configuration information
 * @param[in]      BlockId				Block Id
 * @param[in]      pCurrentJob			A pointer to the management block of the current block
 */
STATIC FUNC(void, NVM_CODE) NvM_WriteRAMBlockToTemporaryBuffer
(
	P2CONST(NvM_BlockDescriptorType, NVM_VAR, NVM_APPL_CONST) pBlockDescriptor,
	VAR(NvM_BlockIdType, AUTOMATIC) BlockId,
	P2CONST(NvM_AdministrativeBlockType, NVM_VAR, NVM_APPL_CONST) pCurrentJob
)
{
	VAR(uint16, AUTOMATIC) count = 0U;
	VAR(uint8, AUTOMATIC) Offset = 0U;
	P2CONST(uint8, NVM_VAR, NVM_APPL_CONST) pData;

	if(1U == BlockId)
	{
		pData = NVM_GET_CONFIGURATION_ID_ADDRESS();
	}
	else
	{
		pData = NVM_GET_CURRENT_RAM_BLOCK_ADDRESS(pCurrentJob);
	}

	if((boolean)TRUE == NVM_GET_STATIC_BLOCK_ID_CHECK(pBlockDescriptor,BlockId-1U))
	{
		NvM_NVRAMTemporaryData[0] = (uint8)(BlockId & 0xffU);
		NvM_NVRAMTemporaryData[1] = (uint8)((BlockId >> 8U) & 0xffU);
		/* PRQA S 4397 EOF # Data migration */
		NvM_NVRAMTemporaryData[2] = \
				(uint8)(((NVM_GET_NV_BLOCK_BASE_NUMBER(pBlockDescriptor,BlockId-1U) \
				<< NVM_DATASET_SELECTION_BITS) + pCurrentJob->NvM_BlockIndex) & 0xffU);
		NvM_NVRAMTemporaryData[3] = \
				(uint8)((((NVM_GET_NV_BLOCK_BASE_NUMBER(pBlockDescriptor,BlockId-1U) \
				<< NVM_DATASET_SELECTION_BITS) + pCurrentJob->NvM_BlockIndex) >> 8U) & 0xffU);
		Offset = 4U;
	}

	do
	{
		NvM_NVRAMTemporaryData[Offset+count] = pData[count];
		count++;
	}while(count < NVM_GET_NV_BLOCK_LENGTH(pBlockDescriptor,BlockId-1U));

	if(NVM_CRC8 == NVM_GET_BLOCK_CRC_LENGTH(pBlockDescriptor, BlockId-1U))
	{
		NvM_NVRAMTemporaryData[Offset+count] = (uint8)((pCurrentJob->NvM_BlockCrc) & 0xffU);
	}
	else if(NVM_CRC16 == NVM_GET_BLOCK_CRC_LENGTH(pBlockDescriptor, BlockId-1U))
	{
		NvM_NVRAMTemporaryData[Offset+count] = (uint8)((pCurrentJob->NvM_BlockCrc) & 0xffU);
		NvM_NVRAMTemporaryData[Offset+count+1U] = (uint8)((pCurrentJob->NvM_BlockCrc >> 8U) & 0xffU);
	}
	else if(NVM_CRC32 == NVM_GET_BLOCK_CRC_LENGTH(pBlockDescriptor, BlockId-1U))
	{
		NvM_NVRAMTemporaryData[Offset+count] = (uint8)(pCurrentJob->NvM_BlockCrc & 0xffU);
		NvM_NVRAMTemporaryData[Offset+count+1U] = (uint8)((pCurrentJob->NvM_BlockCrc >> 8U) & 0xffU);
		NvM_NVRAMTemporaryData[Offset+count+2U] = (uint8)((pCurrentJob->NvM_BlockCrc >> 16U) & 0xffU);
		NvM_NVRAMTemporaryData[Offset+count+3U] = (uint8)((pCurrentJob->NvM_BlockCrc >> 24U) & 0xffU);
	}
	else
	{
		/* Do nothing */
	}

}

/**
 * @brief   	Compare the configuration ID
 * @details
 * @return	Std_ReturnType
 * @retval 	E_OK:		The configuration ID matches
 * 			E_NOT_OK:	The configuration ID do not match
 */
STATIC FUNC(Std_ReturnType, NVM_CODE) NvM_CompareConfigurationID(void)
{
	VAR(Std_ReturnType, AUTOMATIC) ret = (Std_ReturnType)E_OK;
	VAR(uint8, AUTOMATIC) count = 0U;
	/* The ID of the configuration read */
	P2VAR(uint8, NVM_VAR, NVM_APPL_CONST) pData1 = NvM_AdministrativeBlock[0].NvM_RAMAddress;
	/* The ID of the generated configuration */
	P2CONST(uint8, NVM_VAR, NVM_APPL_CONST) pData2 = NVM_GET_CONFIGURATION_ID_ADDRESS();

	do
	{
		if(pData1[count] != pData2[count])
		{
			ret = (Std_ReturnType)E_NOT_OK;
			break;
		}
		count++;
	}while(count < NVM_CONFIGUREID_LENGTH);

	return ret;
}

/**
 * @brief   	Multi-block write job task processing
 * @details
 * @param[in]      pBlockDescriptor		A pointer to block configuration information
 */
STATIC FUNC(void, NVM_CODE) NvM_SetMultiBlockWriteJob
(
	P2CONST(NvM_BlockDescriptorType, NVM_VAR, NVM_APPL_CONST) pBlockDescriptor
)
{
	/* SWS_NvM_00238 */
	if(NVM_CANCEL_WRITE_ALL == NvM_MultiBlockJob)
	{
		do
		{
			/* Skip block 1 */
			if(1U == NvM_RunJob.NvM_CurrentRunBlockId)
			{
				NvM_RunJob.NvM_CurrentRunBlockId = 2U;
			}
			if(NVM_REQ_PENDING == NvM_AdministrativeBlock[NvM_RunJob.NvM_CurrentRunBlockId-1U]. \
					NvM_BlockRequestResult)
			{
				/* @req [SWS_NvM_00237] */
				NvM_AdministrativeBlock[NvM_RunJob.NvM_CurrentRunBlockId-1U].NvM_BlockRequestResult \
				= NVM_REQ_CANCELED;
			}

			NvM_RunJob.NvM_CurrentRunBlockId++;
		}while((NvM_RunJob.NvM_CurrentRunBlockId-1U) < (NvM_BlockIdType)NVM_NUM_OF_BLOCK);

		NvM_RunJob.NvM_PreMultiBlockRequestResult = NVM_REQ_CANCELED;

		/* @req [SWS_NvM_00681] */
#if ((FEE_SETMODE_API_SUPPORTED == STD_ON) || (EA_SETMODE_API_SUPPORTED == STD_ON))
		if((boolean)TRUE == NVM_GET_DRV_MODE_SWITCH())
		{
			MemIf_SetMode(MEMIF_MODE_SLOW);
		}
#endif
		NvM_RunJob.NvM_InternalJob = NVM_JOB_FINISH;
		NvM_RunJob.NvM_MultipleRequestEnd = (boolean)TRUE;
	}
	else if(NvM_RunJob.NvM_MultipleRequestEnd != (boolean)TRUE)
	{
		if(1U == NvM_RunJob.NvM_CurrentRunBlockId)
		{
#if ((FEE_SETMODE_API_SUPPORTED == STD_ON) || (EA_SETMODE_API_SUPPORTED == STD_ON))
			if((boolean)TRUE == NVM_GET_DRV_MODE_SWITCH())
			{
				/* @req [SWS_NvM_00430] */
				MemIf_SetMode(MEMIF_MODE_FAST);
			}
			else
			{
				/* @req [SWS_NvM_00431] */
				MemIf_SetMode(MEMIF_MODE_SLOW);
			}
#endif
			NvM_RunJob.NvM_CurrentRunBlockId++;
		}

		if((NvM_BlockIdType)NVM_NUM_OF_BLOCK > (NvM_RunJob.NvM_CurrentRunBlockId-1U))
		{
			do
			{
				if((NVM_REQ_PENDING == NvM_AdministrativeBlock[NvM_RunJob.NvM_CurrentRunBlockId-1U]. \
						NvM_BlockRequestResult) && \
						((boolean)TRUE == NVM_GET_BLOCK_WRITE_ALL_ATTRIBUTE(pBlockDescriptor, \
								NvM_RunJob.NvM_CurrentRunBlockId-1U)))
				{
					/* Start the write block */
					NvM_RunJob.NvM_InternalJob = NVM_JOB_INVALID;
					NvM_RunJob.NvM_MultipleBlocksToWrite = (boolean)TRUE;

					NvM_RunJob.NvM_IsLastRedundantBlock = (boolean)FALSE;
					NvM_RunJob.NvM_IsRedundantBlockJobOK = (boolean)FALSE;
					NvM_RunJob.NvM_CrcCalculatedBytes = 0U;
					NvM_RunJob.NvM_InternalJobStatus = NVM_JOB_OK;
					NvM_RunJob.NvM_MemIfJobResult = MEMIF_JOB_OK;
#if (STD_ON == NVM_USE_MIRROR_MECHANISM)
					NvM_RunJob.NvM_NumOfMirrorOperationRetries = 0U;
#endif /* STD_ON == NVM_USE_MIRROR_MECHANISM */
					NvM_RunJob.NvM_WriteValidationBytes = 0U;
					break;
				}
				else
				{
					NvM_RunJob.NvM_CurrentRunBlockId++;
				}
			}while((NvM_RunJob.NvM_CurrentRunBlockId-1U) < (NvM_BlockIdType)NVM_NUM_OF_BLOCK);
		}

		if((NvM_BlockIdType)NVM_NUM_OF_BLOCK == (NvM_RunJob.NvM_CurrentRunBlockId-1U))
		{
			if(NVM_REQ_PENDING == NvM_AdministrativeBlock[0].NvM_BlockRequestResult)
			{
				NvM_RunJob.NvM_CurrentRunBlockId = 1U;
				NvM_RunJob.NvM_InternalJob = NVM_JOB_INVALID;

				NvM_RunJob.NvM_MultipleBlocksToWrite = (boolean)TRUE;

				NvM_RunJob.NvM_IsLastRedundantBlock = (boolean)FALSE;
				NvM_RunJob.NvM_IsRedundantBlockJobOK = (boolean)FALSE;
				NvM_RunJob.NvM_CrcCalculatedBytes = 0U;
				NvM_RunJob.NvM_InternalJobStatus = NVM_JOB_OK;
				NvM_RunJob.NvM_MemIfJobResult = MEMIF_JOB_OK;
#if (STD_ON == NVM_USE_MIRROR_MECHANISM)
				NvM_RunJob.NvM_NumOfMirrorOperationRetries = 0U;
#endif /* STD_ON == NVM_USE_MIRROR_MECHANISM */
				NvM_RunJob.NvM_WriteValidationBytes = 0U;
			}
			else
			{
				/* @req [SWS_NvM_00681] */
#if ((FEE_SETMODE_API_SUPPORTED == STD_ON) || (EA_SETMODE_API_SUPPORTED == STD_ON))
				if((boolean)TRUE == NVM_GET_DRV_MODE_SWITCH())
				{
					MemIf_SetMode(MEMIF_MODE_SLOW);
				}
#endif
				NvM_RunJob.NvM_MultipleRequestEnd = (boolean)TRUE;
				NvM_RunJob.NvM_InternalJob = NVM_JOB_FINISH;
			}
		}
	}
	else
	{
		if((boolean)TRUE == NVM_GET_DRV_MODE_SWITCH())
		{
#if ((FEE_SETMODE_API_SUPPORTED == STD_ON) || (EA_SETMODE_API_SUPPORTED == STD_ON))
			MemIf_SetMode(MEMIF_MODE_SLOW);
#endif
		}

		NvM_RunJob.NvM_InternalJob = NVM_JOB_FINISH;
	}
}

/**
 * @brief   	Multi-block read job task processing
 * @details
 * @param[in]      pBlockDescriptor		A pointer to block configuration information
 */
STATIC FUNC(void, NVM_CODE) NvM_SetMultiBlockReadJob
(
	P2CONST(NvM_BlockDescriptorType, NVM_VAR, NVM_APPL_CONST) pBlockDescriptor
)
{
	if((1U == NvM_RunJob.NvM_CurrentRunBlockId) && \
			(NvM_AdministrativeBlock[0].NvM_BlockRequestResult == NVM_REQ_PENDING))
	{
#if ((FEE_SETMODE_API_SUPPORTED == STD_ON) || (EA_SETMODE_API_SUPPORTED == STD_ON))
		if((boolean)TRUE == NVM_GET_DRV_MODE_SWITCH())
		{
			/* @req [SWS_NvM_00426] */
			MemIf_SetMode(MEMIF_MODE_FAST);
		}
		else
		{
			/* @req [SWS_NvM_00427] */
			MemIf_SetMode(MEMIF_MODE_SLOW);
		}
#endif
	}
	/* Block 1 has been read */
	/* @req [SWS_NvM_00244] */
	else if((1U == NvM_RunJob.NvM_CurrentRunBlockId) && \
			(NvM_AdministrativeBlock[0].NvM_BlockRequestResult != NVM_REQ_PENDING))
	{
		if((boolean)TRUE == NVM_IS_DYNAMIC_CONFIGURATION())
		{
			/* @req [SWS_NvM_00246] */
			if(NvM_AdministrativeBlock[0].NvM_BlockState == NVM_BLOCK_VALID_UNCHANGED)
			{
				if((Std_ReturnType)E_OK == NvM_CompareConfigurationID())
				{
					NvM_RunJob.NvM_ConfigureIDIsOK = (boolean)TRUE;
				}
				else
				{
					NvM_AdministrativeBlock[0].NvM_BlockState = NVM_BLOCK_INVALID_UNCHANGED;
					NvM_AdministrativeBlock[0].NvM_BlockRequestResult = NVM_REQ_NOT_OK;
				}
			}
			else
			{
				if((NvM_AdministrativeBlock[0].NvM_BlockRequestResult == NVM_REQ_NV_INVALIDATED) && \
						(NvM_AdministrativeBlock[0].NvM_BlockState == \
								NVM_BLOCK_INVALID_UNCHANGED))
				{
					NvM_RunJob.NvM_ConfigureIDIsOK = (boolean)TRUE;
				}
			}
		}
		/* @req [SWS_NvM_00248] */
		else /* (boolean)FALSE == NVM_IS_DYNAMIC_CONFIGURATION() */
		{
			NvM_RunJob.NvM_ConfigureIDIsOK = (boolean)TRUE;
		}
	}
	else
	{
		/* Do nothing */
	}

	if((NvM_BlockIdType)NVM_NUM_OF_BLOCK > (NvM_RunJob.NvM_CurrentRunBlockId-1U))
	{
		do
		{
			if((NVM_REQ_PENDING == NvM_AdministrativeBlock[NvM_RunJob.NvM_CurrentRunBlockId-1U]. \
					NvM_BlockRequestResult) && \
					((boolean)TRUE == NVM_GET_BLOCK_READ_ALL_ATTRIBUTE(pBlockDescriptor, \
									NvM_RunJob.NvM_CurrentRunBlockId-1U)))
			{
				if((1U == NvM_RunJob.NvM_CurrentRunBlockId) || \
						((boolean)TRUE == NvM_RunJob.NvM_ConfigureIDIsOK) || \
						(((boolean)FALSE == NvM_RunJob.NvM_ConfigureIDIsOK) && \
						((boolean)TRUE == NVM_IS_DYNAMIC_CONFIGURATION()) && \
						((boolean)TRUE == NVM_GET_BLOCK_RESISTANT_ATTRIBUTE(pBlockDescriptor, \
								NvM_RunJob.NvM_CurrentRunBlockId-1U))))
				{
					/* Start the read block */
					NvM_RunJob.NvM_InternalJob = NVM_JOB_INVALID;
					NvM_RunJob.NvM_MultipleBlocksToRead = (boolean)TRUE;
				}
				else
				{
					/* Configuration changes restore defaults */
					NvM_RunJob.NvM_InternalJob = NVM_JOB_INVALID;
					NvM_RunJob.NvM_RestoreDefaultJob = (boolean)TRUE;
				}

				NvM_RunJob.NvM_IsLastRedundantBlock = (boolean)FALSE;
				NvM_RunJob.NvM_IsRedundantBlockJobOK = (boolean)FALSE;
				NvM_RunJob.NvM_CrcCalculatedBytes = 0U;
				NvM_RunJob.NvM_InternalJobStatus = NVM_JOB_OK;
				NvM_RunJob.NvM_MemIfJobResult = MEMIF_JOB_OK;
#if (STD_ON == NVM_USE_MIRROR_MECHANISM)
				NvM_RunJob.NvM_NumOfMirrorOperationRetries = 0U;
#endif /* STD_ON == NVM_USE_MIRROR_MECHANISM */
				NvM_RunJob.NvM_WriteValidationBytes = 0U;

				break;
			}
			else
			{
				/* Blocks that do not participate in NvM_ReadAll */
				NvM_RunJob.NvM_CurrentRunBlockId++;
			}
		}while((NvM_RunJob.NvM_CurrentRunBlockId-1U) < (NvM_BlockIdType)NVM_NUM_OF_BLOCK);
	}

	if((NvM_BlockIdType)NVM_NUM_OF_BLOCK == (NvM_RunJob.NvM_CurrentRunBlockId-1U))
	{
#if ((FEE_SETMODE_API_SUPPORTED == STD_ON) || (EA_SETMODE_API_SUPPORTED == STD_ON))
		if((boolean)TRUE == NVM_GET_DRV_MODE_SWITCH())
		{
			MemIf_SetMode(MEMIF_MODE_SLOW);
		}
#endif
		NvM_RunJob.NvM_CurrentRunBlockId = 0U;
		NvM_RunJob.NvM_MultipleRequestEnd = (boolean)TRUE;
		NvM_RunJob.NvM_InternalJob = NVM_JOB_FINISH;
	}
}

/**
 * @brief   	Multi-block job task processing
 * @details
 * @param[in]      pBlockDescriptor		A pointer to block configuration information
 */
STATIC FUNC(void, NVM_CODE) NvM_MultiBlockProcessing
(
	P2CONST(NvM_BlockDescriptorType, NVM_VAR, NVM_APPL_CONST) pBlockDescriptor
)
{
	if((NvM_RunJob.NvM_CurrentRunJob == NVM_READ_ALL) && \
			(NvM_RunJob.NvM_MultipleBlocksToWrite == (boolean)FALSE) && \
			(NvM_RunJob.NvM_MultipleBlocksToRead == (boolean)FALSE) && \
			(NvM_RunJob.NvM_RestoreDefaultJob == (boolean)FALSE))
	{
		NvM_SetMultiBlockReadJob(pBlockDescriptor);
	}
	else if((NvM_RunJob.NvM_CurrentRunJob == NVM_WRITE_ALL) && \
			(NvM_RunJob.NvM_MultipleBlocksToWrite == (boolean)FALSE) && \
			(NvM_RunJob.NvM_MultipleBlocksToRead == (boolean)FALSE))
	{
		NvM_SetMultiBlockWriteJob(pBlockDescriptor);
	}
	else if(NvM_RunJob.NvM_CurrentRunJob == NVM_VALIDATE_ALL)
	{
		if((NvM_BlockIdType)NVM_NUM_OF_BLOCK > (NvM_RunJob.NvM_CurrentRunBlockId-1U))
		{
			/* Skip block 1 */
			if(1U == NvM_RunJob.NvM_CurrentRunBlockId)
			{
				NvM_RunJob.NvM_CurrentRunBlockId = 2U;
			}

#if (STD_ON == NVM_USE_MIRROR_MECHANISM)
			if((NVM_JOB_WRITE_RAM_BLOCK_TO_NVM == NvM_RunJob.NvM_InternalJob) && \
					(NVM_JOB_WRITE_RAM_FAIL == NvM_RunJob.NvM_InternalJobStatus))
			{
				if(NvM_RunJob.NvM_NumOfMirrorOperationRetries >= NVM_REPEAT_MIRROR_OPERATIONS)
				{
					NvM_AdministrativeBlock[NvM_RunJob.NvM_CurrentRunBlockId-1U]. \
					NvM_BlockRequestResult = NVM_REQ_NOT_OK;
					NvM_RunJob.NvM_PreMultiBlockRequestResult = NVM_REQ_NOT_OK;
					NvM_RunJob.NvM_InternalJob = NVM_JOB_INVALID;
					NvM_RunJob.NvM_CurrentRunBlockId++;
				}
				else
				{
					NvM_RunJob.NvM_NumOfMirrorOperationRetries++;
					NvM_RunJob.NvM_InternalJob = NVM_JOB_WRITE_RAM_BLOCK_TO_NVM;
				}
			}
			else if((NVM_JOB_WRITE_RAM_BLOCK_TO_NVM == NvM_RunJob.NvM_InternalJob) && \
					(NVM_JOB_OK == NvM_RunJob.NvM_InternalJobStatus))
			{
				NvM_AdministrativeBlock[NvM_RunJob.NvM_CurrentRunBlockId-1U].NvM_BlockRequestResult = \
						NVM_REQ_OK;
				NvM_AdministrativeBlock[NvM_RunJob.NvM_CurrentRunBlockId-1U].NvM_BlockState = \
						NVM_BLOCK_VALID_CHANGED;
				NvM_RunJob.NvM_InternalJob = NVM_JOB_INVALID;
				NvM_RunJob.NvM_CurrentRunBlockId++;
			}
			else
			{
				/* Do nothing */
			}
#endif /* STD_ON == NVM_USE_MIRROR_MECHANISM */

			if(NvM_RunJob.NvM_InternalJob == NVM_JOB_INVALID)
			{
				do
				{
					if(NvM_AdministrativeBlock[NvM_RunJob.NvM_CurrentRunBlockId-1U]. \
							NvM_BlockRequestResult == NVM_REQ_PENDING)
					{
						if(((boolean)TRUE == NVM_IS_CALC_RAM_BLOCK_CRC(pBlockDescriptor, \
								NvM_RunJob.NvM_CurrentRunBlockId-1U)) && \
								(NULL_PTR != NVM_GET_RAM_BLOCK_ADDRESS(pBlockDescriptor, \
										NvM_RunJob.NvM_CurrentRunBlockId-1U)))
						{
							NvM_RunJob.NvM_InternalJob = NVM_JOB_CALCULATE_CRC;
						}
#if (STD_ON == NVM_USE_MIRROR_MECHANISM)
						else if((boolean)TRUE == NVM_USE_SYNC_MECHANISM(pBlockDescriptor, \
								NvM_RunJob.NvM_CurrentRunBlockId-1U))
						{
							NvM_RunJob.NvM_NumOfMirrorOperationRetries = 0U;
							NvM_RunJob.NvM_InternalJob = NVM_JOB_WRITE_RAM_BLOCK_TO_NVM;
						}
						else
						{
							/* Do nothing */
						}
#endif /* STD_ON == NVM_USE_MIRROR_MECHANISM */
						break;
					}
					else
					{
						NvM_RunJob.NvM_CurrentRunBlockId++;
					}
				}while((NvM_RunJob.NvM_CurrentRunBlockId-1U) < (NvM_BlockIdType)NVM_NUM_OF_BLOCK);
			}
		}

		if((NvM_BlockIdType)NVM_NUM_OF_BLOCK == (NvM_RunJob.NvM_CurrentRunBlockId-1U))
		{
			NvM_RunJob.NvM_MultipleRequestEnd = (boolean)TRUE;
			NvM_RunJob.NvM_InternalJob = NVM_JOB_FINISH;
		}
	}
	else
	{
		/* Do nothing */
	}
}

/**
 * @brief   	Set a reset block default job based on the current job
 * @details
 * @param[in]      pBlockDescriptor		A pointer to block configuration information
 * @param[in]      BlockId				Block Id
 */
STATIC FUNC(void, NVM_CODE) NvM_SetSingleBlockRestorJob
(
	P2CONST(NvM_BlockDescriptorType, NVM_VAR, NVM_APPL_CONST) pBlockDescriptor,
	VAR(NvM_BlockIdType, AUTOMATIC) BlockId
)
{
	if(NVM_JOB_INVALID == NvM_RunJob.NvM_InternalJob)
	{
		NvM_RunJob.NvM_InternalJob = NVM_JOB_RESTORE_DEFAULTS;
	}
	else if(NVM_JOB_RESTORE_DEFAULTS_FAIL == NvM_RunJob.NvM_InternalJobStatus)
	{
		NvM_RunJob.NvM_InternalJob = NVM_JOB_FINISH;
	}
#if (STD_ON == NVM_USE_MIRROR_MECHANISM)
	else if(NVM_JOB_READ_RAM_FAIL == NvM_RunJob.NvM_InternalJobStatus)
	{
		if(NvM_RunJob.NvM_NumOfMirrorOperationRetries >= NVM_REPEAT_MIRROR_OPERATIONS)
		{
			NvM_RunJob.NvM_InternalJob = NVM_JOB_FINISH;
		}
		else
		{
			NvM_RunJob.NvM_NumOfMirrorOperationRetries++;
		}
	}
#endif /* STD_ON == NVM_USE_MIRROR_MECHANISM */
	else if((NVM_JOB_RESTORE_DEFAULTS == NvM_RunJob.NvM_InternalJob) && \
			(NVM_JOB_OK == NvM_RunJob.NvM_InternalJobStatus))
	{
		/* @req [SWS_NvM_00229] */
		if((boolean)TRUE == NVM_IS_USE_CRC(pBlockDescriptor,BlockId-1U))
		{
			NvM_RunJob.NvM_InternalJob = NVM_JOB_CALCULATE_CRC;
		}
		else
		{
#if (STD_ON == NVM_USE_MIRROR_MECHANISM)
			if((boolean)TRUE == NVM_USE_SYNC_MECHANISM(pBlockDescriptor,BlockId-1U))
			{
				NvM_RunJob.NvM_InternalJob = NVM_JOB_READ_RAM_BLOCK_FROM_NVM;
			}
			else
#endif /* STD_ON == NVM_USE_MIRROR_MECHANISM */
			{
				NvM_RunJob.NvM_InternalJob = NVM_JOB_FINISH;
			}
		}
	}
	else if((NVM_JOB_CALCULATE_CRC == NvM_RunJob.NvM_InternalJob) && \
			(NVM_JOB_OK == NvM_RunJob.NvM_InternalJobStatus))
	{
#if (STD_ON == NVM_USE_MIRROR_MECHANISM)
		if((boolean)TRUE == NVM_USE_SYNC_MECHANISM(pBlockDescriptor,BlockId-1U))
		{
			NvM_RunJob.NvM_InternalJob = NVM_JOB_READ_RAM_BLOCK_FROM_NVM;
		}
		else
#endif /* STD_ON == NVM_USE_MIRROR_MECHANISM */
		{
			NvM_RunJob.NvM_InternalJob = NVM_JOB_FINISH;
		}
	}
	else
	{
		NvM_RunJob.NvM_InternalJob = NVM_JOB_FINISH;
	}
}

/**
 * @brief   	Set a read job based on the current job
 * @details
 * @param[in]      pBlockDescriptor		A pointer to block configuration information
 * @param[in]      BlockId				Block Id
 * @param[in]      pCurrentJob			A pointer to the management block of the current block
 */
STATIC FUNC(void, NVM_CODE) NvM_SetSingleBlockReadJob
(
	P2CONST(NvM_BlockDescriptorType, NVM_VAR, NVM_APPL_CONST) pBlockDescriptor,
	VAR(NvM_BlockIdType, AUTOMATIC) BlockId,
	P2VAR(NvM_AdministrativeBlockType, NVM_VAR, NVM_APPL_CONST) pCurrentJob
)
{
	if((NVM_JOB_INVALID == NvM_RunJob.NvM_InternalJob) && \
			(NVM_JOB_STATIC_ID_CHECK_FAIL != NvM_RunJob.NvM_InternalJobStatus))
	{
		/* @req [SWS_NvM_00354] */
		if((NVM_BLOCK_DATASET == NVM_GET_BLOCK_MANAGEMENT_TYPE(pBlockDescriptor,BlockId-1U)) && \
				(pCurrentJob->NvM_BlockIndex >= \
				NVM_GET_NV_BLOCK_NUMBER(pBlockDescriptor,BlockId-1U)))
		{
			NvM_RunJob.NvM_RestoreDefaultJob = (boolean)TRUE;
		}
		else
		{
			NvM_RunJob.NvM_InternalJob = NVM_JOB_READ;
			NvM_RunJob.NvM_MemIfJobConfirmation = (boolean)TRUE;
			pCurrentJob->NvM_NumOfReadRetries = 0U;
		}
	}
#if (STD_ON == NVM_USE_MIRROR_MECHANISM)
	else if(NVM_JOB_READ_RAM_FAIL == NvM_RunJob.NvM_InternalJobStatus)
	{
		if(NvM_RunJob.NvM_NumOfMirrorOperationRetries >= NVM_REPEAT_MIRROR_OPERATIONS)
		{
			NvM_RunJob.NvM_InternalJob = NVM_JOB_FINISH;
		}
		else
		{
			NvM_RunJob.NvM_NumOfMirrorOperationRetries++;
		}
	}
#endif /* STD_ON == NVM_USE_MIRROR_MECHANISM */
	else if(((NVM_JOB_MEMIF_FAIL == NvM_RunJob.NvM_InternalJobStatus) || \
			(NVM_JOB_CRC_FAIL == NvM_RunJob.NvM_InternalJobStatus) || \
			(NVM_JOB_STATIC_ID_CHECK_FAIL == NvM_RunJob.NvM_InternalJobStatus)) && \
			(NVM_JOB_WRITE != NvM_RunJob.NvM_InternalJob))
	{
		if(pCurrentJob->NvM_NumOfReadRetries >= \
				NVM_GET_BLOCK_MAX_NUM_OF_READ_RETRIES(pBlockDescriptor,BlockId-1U))
		{
			/* @req [SWS_NvM_00199] */
			if((NVM_BLOCK_REDUNDANT == \
						NVM_GET_BLOCK_MANAGEMENT_TYPE(pBlockDescriptor,BlockId-1U)) && \
					(NvM_RunJob.NvM_IsLastRedundantBlock == (boolean)FALSE))
			{
				NVM_GET_NEXT_REDUNDANT_BLOCK_INDEX(pCurrentJob);
				NvM_RunJob.NvM_IsLastRedundantBlock = (boolean)TRUE;
				pCurrentJob->NvM_NumOfReadRetries = 0U;
				NvM_RunJob.NvM_InternalJob = NVM_JOB_READ;
				NvM_RunJob.NvM_MemIfJobConfirmation = (boolean)TRUE;
			}
			else
			{
				NvM_RunJob.NvM_InternalJob = NVM_JOB_FINISH;
			}
		}
		else
		{
			pCurrentJob->NvM_NumOfReadRetries++;
			NvM_RunJob.NvM_InternalJob = NVM_JOB_READ;
			NvM_RunJob.NvM_MemIfJobConfirmation = (boolean)TRUE;
		}
	}
	else if((NVM_JOB_OK == NvM_RunJob.NvM_InternalJobStatus) || \
			(NVM_JOB_WRITE == NvM_RunJob.NvM_InternalJob))
	{
		/* @req [SWS_NvM_00362] */
		if(((boolean)TRUE == NVM_IS_CALC_RAM_BLOCK_CRC(pBlockDescriptor,BlockId-1U)) && \
				(NVM_JOB_READ == NvM_RunJob.NvM_InternalJob))
		{
			if((boolean)FALSE == NvM_CompareStaticBlockId(pBlockDescriptor,BlockId,pCurrentJob))
			{
				NvM_RunJob.NvM_InternalJobStatus = NVM_JOB_STATIC_ID_CHECK_FAIL;
				NvM_RunJob.NvM_InternalJob = NVM_JOB_INVALID;
			}
			else
			{
				/* @req [SWS_NvM_00201] */
				NvM_RunJob.NvM_InternalJob = NVM_JOB_CALCULATE_CRC;
			}
		}
		else
		{
			/* @req [SWS_NvM_00010] Copy the message to RAM block */
			NvM_ReadRAMBlockFromTemporaryBuffer(pBlockDescriptor,BlockId,pCurrentJob);
#if (STD_ON == NVM_USE_MIRROR_MECHANISM)
			if(((boolean)TRUE == NVM_USE_SYNC_MECHANISM(pBlockDescriptor,BlockId-1U)) && \
					(NVM_JOB_READ_RAM_BLOCK_FROM_NVM != NvM_RunJob.NvM_InternalJob) && \
					(NVM_JOB_WRITE != NvM_RunJob.NvM_InternalJob))
			{
				NvM_RunJob.NvM_InternalJob = NVM_JOB_READ_RAM_BLOCK_FROM_NVM;
			}
			else
#endif /* STD_ON == NVM_USE_MIRROR_MECHANISM */
			{
				if((NVM_BLOCK_REDUNDANT == \
						NVM_GET_BLOCK_MANAGEMENT_TYPE(pBlockDescriptor,BlockId-1U)) && \
						((boolean)TRUE == NvM_RunJob.NvM_IsLastRedundantBlock) && \
						(NVM_JOB_WRITE != NvM_RunJob.NvM_InternalJob) && \
						(NVM_JOB_OK == NvM_RunJob.NvM_InternalJobStatus))
				{
					/* Redundant recovery */
					NvM_RunJob.NvM_IsRedundantBlockJobOK = (boolean)TRUE;
					NVM_GET_NEXT_REDUNDANT_BLOCK_INDEX(pCurrentJob);
					NVM_UPDATE_STATIC_BLOCK_ID(pBlockDescriptor,BlockId,pCurrentJob);
					NvM_RunJob.NvM_InternalJob = NVM_JOB_WRITE;
					NvM_RunJob.NvM_MemIfJobConfirmation = (boolean)TRUE;
				}
				else
				{
					NvM_RunJob.NvM_MemIfJobResult = MEMIF_JOB_OK;
					NvM_RunJob.NvM_InternalJob = NVM_JOB_FINISH;
				}
			}
		}
	}
	else
	{
		/* Do nothing */
	}
}

/**
 * @brief   	Set a write job based on the current job
 * @details
 * @param[in]      pBlockDescriptor		A pointer to block configuration information
 * @param[in]      BlockId				Block Id
 * @param[in]      pCurrentJob			A pointer to the management block of the current block
 */
STATIC FUNC(void, NVM_CODE) NvM_SetSingleBlockWriteJob
(
	P2CONST(NvM_BlockDescriptorType, NVM_VAR, NVM_APPL_CONST) pBlockDescriptor,
	VAR(NvM_BlockIdType, AUTOMATIC) BlockId,
	P2VAR(NvM_AdministrativeBlockType, NVM_VAR, NVM_APPL_CONST) pCurrentJob
)
{
	if((NvM_RunJob.NvM_InternalJob == NVM_JOB_WRITE_VALIDATION) && \
			(NvM_RunJob.NvM_InternalJobStatus == NVM_JOB_OK))
	{
		NvM_WriteValidation(pBlockDescriptor,BlockId,pCurrentJob);
	}

	if(NVM_JOB_INVALID == NvM_RunJob.NvM_InternalJob)
	{
		if(NVM_BLOCK_REDUNDANT == NVM_GET_BLOCK_MANAGEMENT_TYPE(pBlockDescriptor,BlockId-1U))
		{
			/* @req [SWS_NvM_00761] */
			NVM_GET_NEXT_REDUNDANT_BLOCK_INDEX(pCurrentJob);
		}

#if (STD_ON == NVM_USE_MIRROR_MECHANISM)
		if((boolean)TRUE == NVM_USE_SYNC_MECHANISM(pBlockDescriptor,BlockId-1U))
		{
			NvM_RunJob.NvM_InternalJob = NVM_JOB_WRITE_RAM_BLOCK_TO_NVM;
		}
		else
#endif /* STD_ON == NVM_USE_MIRROR_MECHANISM */
		{
			NvM_WriteRAMBlockToTemporaryBuffer(pBlockDescriptor,BlockId,pCurrentJob);

			if((boolean)TRUE == NVM_IS_USE_CRC(pBlockDescriptor,BlockId-1U))
			{
				NvM_RunJob.NvM_InternalJob = NVM_JOB_CALCULATE_CRC;
			}
			else
			{
				pCurrentJob->NvM_NumOfWriteRetries = 0U;
				NvM_RunJob.NvM_InternalJob = NVM_JOB_WRITE;
				NvM_RunJob.NvM_MemIfJobConfirmation = (boolean)TRUE;
			}
		}
	}
#if (STD_ON == NVM_USE_MIRROR_MECHANISM)
	else if(NVM_JOB_WRITE_RAM_FAIL == NvM_RunJob.NvM_InternalJobStatus)
	{
		if(NvM_RunJob.NvM_NumOfMirrorOperationRetries >= NVM_REPEAT_MIRROR_OPERATIONS)
		{
			NvM_RunJob.NvM_InternalJob = NVM_JOB_FINISH;
		}
		else
		{
			NvM_RunJob.NvM_NumOfMirrorOperationRetries++;
		}
	}
	else if((NVM_JOB_OK == NvM_RunJob.NvM_InternalJobStatus) && \
			(NVM_JOB_WRITE_RAM_BLOCK_TO_NVM == NvM_RunJob.NvM_InternalJob))
	{
		NvM_WriteRAMBlockToTemporaryBuffer(pBlockDescriptor,BlockId,pCurrentJob);
		if((boolean)TRUE == NVM_IS_CALC_RAM_BLOCK_CRC(pBlockDescriptor,BlockId-1U))
		{
			NvM_RunJob.NvM_InternalJob = NVM_JOB_CALCULATE_CRC;
		}
		else
		{
			NvM_RunJob.NvM_InternalJob = NVM_JOB_WRITE;
			NvM_RunJob.NvM_MemIfJobConfirmation = (boolean)TRUE;
		}
	}
#endif /* STD_ON == NVM_USE_MIRROR_MECHANISM */
	/* @req [SWS_NvM_00854] */
	else if(NVM_JOB_CALCULATE_CRC == NvM_RunJob.NvM_InternalJob)
	{
		if(((boolean)TRUE == NVM_GET_CRC_COMP_MECHANISM(pBlockDescriptor,BlockId-1U)) && \
				(NVM_JOB_OK == NvM_RunJob.NvM_InternalJobStatus))
		{
			/* The write job completes successfully */
			NvM_RunJob.NvM_InternalJob = NVM_JOB_FINISH;
		}
		else
		{
			NvM_RunJob.NvM_InternalJob = NVM_JOB_WRITE;
			NvM_RunJob.NvM_MemIfJobConfirmation = (boolean)TRUE;
			/* Update Crc */
			NvM_UpdateCrcToTemporaryBuffer(pBlockDescriptor,BlockId);
		}
	}
	else if((NVM_JOB_MEMIF_FAIL == NvM_RunJob.NvM_InternalJobStatus)|| \
			(NVM_JOB_WRITE_VALIDATION_FAIL == NvM_RunJob.NvM_InternalJobStatus))
	{
		if(pCurrentJob->NvM_NumOfWriteRetries >= \
				NVM_GET_BLOCK_MAX_NUM_OF_WRITE_RETRIES(pBlockDescriptor,BlockId-1U))
		{
			/* @req [SWS_NvM_00284] */
			if((NVM_BLOCK_REDUNDANT == \
						NVM_GET_BLOCK_MANAGEMENT_TYPE(pBlockDescriptor,BlockId-1U)) && \
					(NvM_RunJob.NvM_IsLastRedundantBlock == (boolean)FALSE))
			{
				NVM_GET_NEXT_REDUNDANT_BLOCK_INDEX(pCurrentJob);
				NvM_RunJob.NvM_IsLastRedundantBlock = (boolean)TRUE;
				pCurrentJob->NvM_NumOfWriteRetries = 0U;
				NVM_UPDATE_STATIC_BLOCK_ID(pBlockDescriptor,BlockId,pCurrentJob);
				NvM_RunJob.NvM_InternalJob = NVM_JOB_WRITE;
				NvM_RunJob.NvM_MemIfJobConfirmation = (boolean)TRUE;
				NvM_RunJob.NvM_WriteValidationBytes = 0U;
			}
			else
			{
				/* The write job completes successfully */
				NvM_RunJob.NvM_InternalJob = NVM_JOB_FINISH;
			}
		}
		else
		{
			/* @req [SWS_NvM_00296] */
			pCurrentJob->NvM_NumOfWriteRetries++;
			NvM_RunJob.NvM_InternalJob = NVM_JOB_WRITE;
			NvM_RunJob.NvM_MemIfJobConfirmation = (boolean)TRUE;
		}
	}
	else if(NVM_JOB_OK == NvM_RunJob.NvM_InternalJobStatus)
	{
		if(((boolean)TRUE == \
				NVM_GET_BLOCK_WRITE_VERIFICATION_ATTRIBUTE(pBlockDescriptor,BlockId-1U)) && \
				(NvM_RunJob.NvM_InternalJob != NVM_JOB_WRITE_VALIDATION))
		{
			NvM_RunJob.NvM_InternalJob = NVM_JOB_WRITE_VALIDATION;
			NvM_RunJob.NvM_MemIfJobConfirmation = (boolean)TRUE;
		}
		else
		{
			/* @req [SWS_NvM_00284] */
			if((NVM_BLOCK_REDUNDANT == \
						NVM_GET_BLOCK_MANAGEMENT_TYPE(pBlockDescriptor,BlockId-1U)) && \
					(NvM_RunJob.NvM_IsLastRedundantBlock == (boolean)FALSE))
			{
				NVM_GET_NEXT_REDUNDANT_BLOCK_INDEX(pCurrentJob);
				NvM_RunJob.NvM_IsLastRedundantBlock = (boolean)TRUE;
				NvM_RunJob.NvM_IsRedundantBlockJobOK = (boolean)TRUE;
				pCurrentJob->NvM_NumOfWriteRetries = 0U;
				NVM_UPDATE_STATIC_BLOCK_ID(pBlockDescriptor,BlockId,pCurrentJob);
				NvM_RunJob.NvM_InternalJob = NVM_JOB_WRITE;
				NvM_RunJob.NvM_MemIfJobConfirmation = (boolean)TRUE;
				NvM_RunJob.NvM_WriteValidationBytes = 0U;
			}
			else
			{
				/* The write job completes successfully */
				NvM_RunJob.NvM_InternalJob = NVM_JOB_FINISH;
			}
		}
	}
	else
	{
		/* Do nothing */
	}
}

/**
 * @brief   	Set an internal job based on the current job
 * @details
 * @param[in]      pBlockDescriptor		A pointer to block configuration information
 * @param[in]      BlockId				Block Id
 * @param[in]      pCurrentJob			A pointer to the management block of the current block
 */
STATIC FUNC(void, NVM_CODE) NvM_SingleBlockProcessing
(
	P2CONST(NvM_BlockDescriptorType, NVM_VAR, NVM_APPL_CONST) pBlockDescriptor,
	VAR(NvM_BlockIdType, AUTOMATIC) BlockId,
	P2VAR(NvM_AdministrativeBlockType, NVM_VAR, NVM_APPL_CONST) pCurrentJob
)
{
	if((NvM_RunJob.NvM_CurrentRunJob == NVM_RESTORE_BLOCK_DEFAULTS) || \
			(NvM_RunJob.NvM_CurrentRunJob == NVM_RESTORE_PRAM_BLOCK_DEFAULTS) || \
			((boolean)TRUE == NvM_RunJob.NvM_RestoreDefaultJob))
	{
		NvM_SetSingleBlockRestorJob(pBlockDescriptor, BlockId);
	}
	else if((NvM_RunJob.NvM_CurrentRunJob == NVM_READ_BLOCK) || \
			(NvM_RunJob.NvM_CurrentRunJob == NVM_READ_PRAM_BLOCK) || \
			(NvM_RunJob.NvM_MultipleBlocksToRead == (boolean)TRUE))
	{
		NvM_SetSingleBlockReadJob(pBlockDescriptor, BlockId, pCurrentJob);
	}
	else if((NvM_RunJob.NvM_CurrentRunJob == NVM_WRITE_BLOCK) || \
			(NvM_RunJob.NvM_CurrentRunJob == NVM_WRITE_PRAM_BLOCK) || \
			(NvM_RunJob.NvM_MultipleBlocksToWrite == (boolean)TRUE))
	{
		NvM_SetSingleBlockWriteJob(pBlockDescriptor, BlockId, pCurrentJob);
	}
	else if(NvM_RunJob.NvM_CurrentRunJob == NVM_ERASE_NV_BLOCK)
	{
		if(NVM_JOB_INVALID == NvM_RunJob.NvM_InternalJob)
		{
			NvM_RunJob.NvM_InternalJob = NVM_JOB_ERASE_IMMEDIATE_BLOCK;
			NvM_RunJob.NvM_MemIfJobConfirmation = (boolean)TRUE;
		}
		else if(NVM_JOB_MEMIF_FAIL == NvM_RunJob.NvM_InternalJobStatus)
		{
			NvM_RunJob.NvM_InternalJob = NVM_JOB_FINISH;
		}
		else
		{
			if((NVM_BLOCK_REDUNDANT == \
						NVM_GET_BLOCK_MANAGEMENT_TYPE(pBlockDescriptor,BlockId-1U)) && \
					(NvM_RunJob.NvM_IsLastRedundantBlock == (boolean)FALSE))
			{
				NVM_GET_NEXT_REDUNDANT_BLOCK_INDEX(pCurrentJob);
				NvM_RunJob.NvM_IsLastRedundantBlock = (boolean)TRUE;
				NvM_RunJob.NvM_InternalJob = NVM_JOB_ERASE_IMMEDIATE_BLOCK;
				NvM_RunJob.NvM_MemIfJobConfirmation = (boolean)TRUE;
			}
			else
			{
				NvM_RunJob.NvM_InternalJob = NVM_JOB_FINISH;
			}
		}
	}
	else if(NvM_RunJob.NvM_CurrentRunJob == NVM_INVALIDATE_NV_BLOCK)
	{
		if(NVM_JOB_INVALID == NvM_RunJob.NvM_InternalJob)
		{
			NvM_RunJob.NvM_InternalJob = NVM_JOB_INVALIDATE_BLOCK;
			NvM_RunJob.NvM_MemIfJobConfirmation = (boolean)TRUE;
		}
		else if(NVM_JOB_MEMIF_FAIL == NvM_RunJob.NvM_InternalJobStatus)
		{
			NvM_RunJob.NvM_InternalJob = NVM_JOB_FINISH;
		}
		else
		{
			if((NVM_BLOCK_REDUNDANT == \
						NVM_GET_BLOCK_MANAGEMENT_TYPE(pBlockDescriptor,BlockId-1U)) && \
					(NvM_RunJob.NvM_IsLastRedundantBlock == (boolean)FALSE))
			{
				NVM_GET_NEXT_REDUNDANT_BLOCK_INDEX(pCurrentJob);
				NvM_RunJob.NvM_IsLastRedundantBlock = (boolean)TRUE;
				NvM_RunJob.NvM_InternalJob = NVM_JOB_INVALIDATE_BLOCK;
				NvM_RunJob.NvM_MemIfJobConfirmation = (boolean)TRUE;
			}
			else
			{
				NvM_RunJob.NvM_InternalJob = NVM_JOB_FINISH;
			}
		}
	}
	else
	{
		/* Do nothing */
	}
}

/**
 * @brief   	The underlying task is being executed
 * @details
 * @param[in]      pBlockDescriptor		A pointer to block configuration information
 * @param[in]      BlockId				Block Id
 * @param[in]      pCurrentJob			A pointer to the management block of the current block
 */
STATIC FUNC(void, NVM_CODE) NvM_MemIfJobIsRun
(
	P2CONST(NvM_BlockDescriptorType, NVM_VAR, NVM_APPL_CONST) pBlockDescriptor,
	VAR(NvM_BlockIdType, AUTOMATIC) BlockId,
	P2VAR(NvM_AdministrativeBlockType, NVM_VAR, NVM_APPL_CONST) pCurrentJob
)
{
	if(NvM_RunJob.NvM_InternalJob == NVM_JOB_READ)
	{
		NvM_RunJob.NvM_MemIfJobConfirmation = (boolean)FALSE;
		if((Std_ReturnType)E_OK == \
				NvM_ReadTemporaryBufferFromNVRAM(pBlockDescriptor,BlockId,pCurrentJob))
		{
			NvM_RunJob.NvM_InternalJobStatus = NVM_JOB_PENDING;
		}
		else
		{
			NvM_RunJob.NvM_InternalJobStatus = NVM_JOB_MEMIF_FAIL;
		}
	}
	else if(NvM_RunJob.NvM_InternalJob == NVM_JOB_WRITE)
	{
		NvM_RunJob.NvM_MemIfJobConfirmation = (boolean)FALSE;
		if((Std_ReturnType)E_OK == \
				NvM_WriteTemporaryBufferToNVRAM(pBlockDescriptor,BlockId,pCurrentJob))
		{
			NvM_RunJob.NvM_InternalJobStatus = NVM_JOB_PENDING;
		}
		else
		{
			NvM_RunJob.NvM_InternalJobStatus = NVM_JOB_MEMIF_FAIL;
		}
	}
	else if(NvM_RunJob.NvM_InternalJob == NVM_JOB_ERASE_IMMEDIATE_BLOCK)
	{
		NvM_RunJob.NvM_MemIfJobConfirmation = (boolean)FALSE;
		if((Std_ReturnType)E_OK == \
				MemIf_EraseImmediateBlock
				(
					NVM_GET_BLOCK_DEVICE_INDEX(pBlockDescriptor,BlockId-1U),
					NVM_GET_CURRENT_BLOCK_NUMBER(pCurrentJob,pBlockDescriptor,BlockId-1U)
				))
		{
			NvM_RunJob.NvM_InternalJobStatus = NVM_JOB_PENDING;
		}
		else
		{
			NvM_RunJob.NvM_InternalJobStatus = NVM_JOB_MEMIF_FAIL;
		}
	}
	else if(NvM_RunJob.NvM_InternalJob == NVM_JOB_INVALIDATE_BLOCK)
	{
		NvM_RunJob.NvM_MemIfJobConfirmation = (boolean)FALSE;
		if((Std_ReturnType)E_OK == \
				MemIf_InvalidateBlock
				(
					NVM_GET_BLOCK_DEVICE_INDEX(pBlockDescriptor,BlockId-1U),
					NVM_GET_CURRENT_BLOCK_NUMBER(pCurrentJob,pBlockDescriptor,BlockId-1U)
				))
		{
			NvM_RunJob.NvM_InternalJobStatus = NVM_JOB_PENDING;
		}
		else
		{
			NvM_RunJob.NvM_InternalJobStatus = NVM_JOB_MEMIF_FAIL;
		}
	}
	/* Write to verify the internal job */
	else if(NvM_RunJob.NvM_InternalJob == NVM_JOB_WRITE_VALIDATION)
	{
		VAR(uint16, AUTOMATIC) Read_Length;
		VAR(uint16, AUTOMATIC) BlockLength = 0U;

		NvM_RunJob.NvM_MemIfJobConfirmation = (boolean)FALSE;
		NVM_GET_BLOCK_LENGTH(pBlockDescriptor,BlockId-1U,BlockLength);

		if(BlockLength >= \
				(NvM_RunJob.NvM_WriteValidationBytes + \
				NVM_GET_BLOCK_WRITE_VERIFICATION_SIZE(pBlockDescriptor,BlockId-1U)))
		{
			Read_Length = NVM_GET_BLOCK_WRITE_VERIFICATION_SIZE(pBlockDescriptor,BlockId-1U);
		}
		else
		{
			Read_Length = BlockLength - NvM_RunJob.NvM_WriteValidationBytes;
		}

		if((Std_ReturnType)E_OK == \
				MemIf_Read
				(
					NVM_GET_BLOCK_DEVICE_INDEX(pBlockDescriptor,BlockId-1U),
					NVM_GET_CURRENT_BLOCK_NUMBER(pCurrentJob,pBlockDescriptor,BlockId-1U),
					0U,
					NvM_NVRAMTemporaryData,
					Read_Length
				))
		{
			NvM_RunJob.NvM_InternalJobStatus = NVM_JOB_PENDING;
		}
		else
		{
			/* @req [SWS_NvM_00530] */
			pCurrentJob->NvM_NumOfWriteRetries = \
					NVM_GET_BLOCK_MAX_NUM_OF_WRITE_RETRIES(pBlockDescriptor,BlockId-1U);
			NvM_RunJob.NvM_InternalJobStatus = NVM_JOB_WRITE_VALIDATION_FAIL;
		}
	}
	else
	{
		/* Do nothing */
	}
}

/**
 * @brief   	Execute an internal job calculation CRC
 * @details
 * @param[in]      pBlockDescriptor		A pointer to block configuration information
 * @param[in]      BlockId				Block Id
 */
STATIC FUNC(void, NVM_CODE) NvM_InternalJobCalculareCRC
(
	P2CONST(NvM_BlockDescriptorType, NVM_VAR, NVM_APPL_CONST) pBlockDescriptor,
	VAR(NvM_BlockIdType, AUTOMATIC) BlockId
)
{
	/* Distribution calculates CRC */
	if((Std_ReturnType)E_NOT_OK == \
			NvM_CalcRamBlockCrcJob(pBlockDescriptor,BlockId,&NvM_RunJob.NvM_TemporaryCrc))
	{
		NvM_RunJob.NvM_InternalJobStatus = NVM_JOB_PENDING;
	}
	else
	/* Verify the CRC */
	{
		if(((boolean)TRUE != NvM_RunJob.NvM_RestoreDefaultJob) && \
				((NVM_READ_BLOCK == NvM_RunJob.NvM_CurrentRunJob) || \
				(NVM_READ_PRAM_BLOCK == NvM_RunJob.NvM_CurrentRunJob) || \
				(NvM_RunJob.NvM_MultipleBlocksToRead == (boolean)TRUE) || \
				(((NVM_WRITE_BLOCK == NvM_RunJob.NvM_CurrentRunJob) || \
						(NVM_WRITE_PRAM_BLOCK == NvM_RunJob.NvM_CurrentRunJob) || \
						(NvM_RunJob.NvM_MultipleBlocksToWrite == (boolean)TRUE)) && \
						((boolean)TRUE == NVM_GET_CRC_COMP_MECHANISM(pBlockDescriptor,BlockId-1U)))))
		{
			NvM_CompareCRC(pBlockDescriptor,BlockId);
		}
		else if(NVM_VALIDATE_ALL == NvM_RunJob.NvM_CurrentRunJob)
		{
			if((boolean)TRUE != \
					NVM_USE_SYNC_MECHANISM(pBlockDescriptor,NvM_RunJob.NvM_CurrentRunBlockId-1U))
			{
				NvM_AdministrativeBlock[NvM_RunJob.NvM_CurrentRunBlockId-1U]. \
				NvM_BlockRequestResult = NVM_REQ_OK;
				NvM_AdministrativeBlock[NvM_RunJob.NvM_CurrentRunBlockId-1U].NvM_BlockState = \
						NVM_BLOCK_VALID_CHANGED;
				NvM_RunJob.NvM_InternalJobStatus = NVM_JOB_OK;
				NvM_RunJob.NvM_InternalJob = NVM_JOB_INVALID;
			}
			else
			{
				NvM_RunJob.NvM_InternalJob = NVM_JOB_WRITE_RAM_BLOCK_TO_NVM;
			}
		}
		else
		{
			NvM_RunJob.NvM_InternalJobStatus = NVM_JOB_OK;
		}
	}
}

/**
 * @brief   	Internal reset block default job finish
 * @details
 * @param[in]      pBlockDescriptor		A pointer to block configuration information
 * @param[in]      BlockId				Block Id
 * @param[in]      pCurrentJob			A pointer to the management block of the current block
 */
STATIC FUNC(void, NVM_CODE) NvM_InternalResetBlockDefaultJobFinish
(
	P2CONST(NvM_BlockDescriptorType, NVM_VAR, NVM_APPL_CONST) pBlockDescriptor,
	VAR(NvM_BlockIdType, AUTOMATIC) BlockId,
	P2VAR(NvM_AdministrativeBlockType, NVM_VAR, NVM_APPL_CONST) pCurrentJob
)
{
	if(NVM_JOB_OK == NvM_RunJob.NvM_InternalJobStatus)
	{
		/* @req [SWS_NvM_00308] */
		/* @req [SWS_NvM_00309] */
		if(((boolean)FALSE == NvM_RunJob.NvM_ConfigureIDIsOK) && \
				((boolean)TRUE == NVM_IS_DYNAMIC_CONFIGURATION()) && \
				((boolean)FALSE == NVM_GET_BLOCK_RESISTANT_ATTRIBUTE(pBlockDescriptor, \
						BlockId-1U)) && (NvM_RunJob.NvM_CurrentRunJob == NVM_READ_ALL))
		{
			NvM_RunJob.NvM_PreBlockState = NVM_BLOCK_INVALID_UNCHANGED;
			NvM_RunJob.NvM_PreBlockRequestResult = NVM_REQ_OK;
		}
		else if(((NVM_BLOCK_DATASET == NVM_GET_BLOCK_MANAGEMENT_TYPE(pBlockDescriptor,BlockId-1U)) && \
				(NvM_AdministrativeBlock[BlockId-1U].NvM_BlockIndex < \
				NVM_GET_NV_BLOCK_NUMBER(pBlockDescriptor,BlockId-1U))) && \
				(((boolean)TRUE == NvM_RunJob.NvM_RestoreDefaultJob) && \
				((NvM_RunJob.NvM_CurrentRunJob == NVM_READ_BLOCK) || \
						(NvM_RunJob.NvM_CurrentRunJob == NVM_READ_PRAM_BLOCK))))
		{
			NvM_RunJob.NvM_PreBlockState = NVM_BLOCK_VALID_CHANGED;
			NvM_RunJob.NvM_PreBlockRequestResult = NVM_REQ_RESTORED_FROM_ROM;
		}
		else
		{
			NvM_RunJob.NvM_PreBlockState = NVM_BLOCK_VALID_CHANGED;
			NvM_RunJob.NvM_PreBlockRequestResult = NVM_REQ_OK;
		}
	}
	else
	{
		NvM_RunJob.NvM_PreBlockState = NVM_BLOCK_INVALID_UNCHANGED;
		NvM_RunJob.NvM_PreBlockRequestResult = NVM_REQ_NOT_OK;
#if (STD_ON == NVM_E_REQ_FAILED_SWITCH)
		Dem_ReportErrorStatus(NVM_E_REQ_FAILED,DEM_EVENT_STATUS_FAILED);
#endif /* STD_ON == NVM_E_REQ_FAILED_SWITCH */
	}

	if((boolean)TRUE == NvM_RunJob.NvM_RestoreDefaultJob)
	{
		NvM_RunJob.NvM_RestoreDefaultJob = (boolean)FALSE;
	}

	pCurrentJob->NvM_BlockState = NvM_RunJob.NvM_PreBlockState;
	pCurrentJob->NvM_BlockRequestResult = NvM_RunJob.NvM_PreBlockRequestResult;

	NvM_Callback(pBlockDescriptor, BlockId, pCurrentJob);

	if(NvM_RunJob.NvM_MultipleBlocksToRead == (boolean)TRUE)
	{
		NvM_RunJob.NvM_MultipleBlocksToRead = (boolean)FALSE;
	}
}

/**
 * @brief   	Internal read job finish
 * @details
 * @param[in]      pBlockDescriptor		A pointer to block configuration information
 * @param[in]      BlockId				Block Id
 * @param[in]      pCurrentJob			A pointer to the management block of the current block
 */
STATIC FUNC(void, NVM_CODE) NvM_InternalReadJobFinish
(
	P2CONST(NvM_BlockDescriptorType, NVM_VAR, NVM_APPL_CONST) pBlockDescriptor,
	VAR(NvM_BlockIdType, AUTOMATIC) BlockId,
	P2VAR(NvM_AdministrativeBlockType, NVM_VAR, NVM_APPL_CONST) pCurrentJob
)
{
	if(MEMIF_JOB_OK == NvM_RunJob.NvM_MemIfJobResult)
	{
		if(NvM_RunJob.NvM_IsRedundantBlockJobOK == (boolean)TRUE)
		{
			/* @req [SWS_NvM_00200] */
			NvM_RunJob.NvM_PreBlockState = NVM_BLOCK_VALID_UNCHANGED;
			/* @req [SWS_NvM_00206] */
			NvM_RunJob.NvM_PreBlockRequestResult = NVM_REQ_OK;

			if(NVM_JOB_OK == NvM_RunJob.NvM_InternalJobStatus)
			{
				/* Redundancy recovery succeeded */
			}
			else
			{
#if (STD_ON == NVM_E_LOSS_OF_REDUNDANCY_SWITCH)
				/* Redundancy recovery failed */
				/* @req [SWS_NvM_00546] */
				Dem_ReportErrorStatus(NVM_E_LOSS_OF_REDUNDANCY,DEM_EVENT_STATUS_FAILED);
#endif /* STD_ON == NVM_E_LOSS_OF_REDUNDANCY_SWITCH */
			}

			/* @req [SWS_NvM_00316] */
			if((boolean)TRUE == NVM_IS_WRITE_ONCE(pBlockDescriptor,BlockId-1U))
			{
				pCurrentJob->NvM_BlockProtection = (boolean)TRUE;
			}
		}
		else if(NVM_JOB_OK == NvM_RunJob.NvM_InternalJobStatus)
		{
			/* @req [SWS_NvM_00200] */
			NvM_RunJob.NvM_PreBlockState = NVM_BLOCK_VALID_UNCHANGED;
			/* @req [SWS_NvM_00206] */
			NvM_RunJob.NvM_PreBlockRequestResult = NVM_REQ_OK;

			/* @req [SWS_NvM_00316] */
			if((boolean)TRUE == NVM_IS_WRITE_ONCE(pBlockDescriptor,BlockId-1U))
			{
				pCurrentJob->NvM_BlockProtection = (boolean)TRUE;
			}
		}
		/* @req [SWS_NvM_00202] */
		else if(NVM_JOB_CRC_FAIL == NvM_RunJob.NvM_InternalJobStatus)
		{
			NvM_RunJob.NvM_PreBlockState = NVM_BLOCK_INVALID_UNCHANGED;
			/* @req [SWS_NvM_00204] */
			NvM_RunJob.NvM_PreBlockRequestResult = NVM_REQ_INTEGRITY_FAILED;
#if (STD_ON == NVM_E_INTEGRITY_FAILED_SWITCH)
			/* @req [SWS_NvM_00203] */
			Dem_ReportErrorStatus(NVM_E_INTEGRITY_FAILED,DEM_EVENT_STATUS_FAILED);
#endif /* STD_ON == NVM_E_REQ_FAILED_SWITCH */
#if (STD_ON == NVM_E_HARDWARE_SWITCH)
			/* @req [SWS_NvM_00835] */
			Dem_ReportErrorStatus(NVM_E_HARDWARE,DEM_EVENT_STATUS_FAILED);
#endif /* STD_ON == NVM_E_HARDWARE_SWITCH */
		}
		else if(NVM_JOB_STATIC_ID_CHECK_FAIL == NvM_RunJob.NvM_InternalJobStatus)
		{
			NvM_RunJob.NvM_PreBlockState = NVM_BLOCK_INVALID_UNCHANGED;
			NvM_RunJob.NvM_PreBlockRequestResult = NVM_REQ_NOT_OK;
#if (STD_ON == NVM_E_WRONG_BLOCK_ID_SWITCH)
			/* @req [SWS_NvM_00525] */
			Dem_ReportErrorStatus(NVM_E_WRONG_BLOCK_ID,DEM_EVENT_STATUS_FAILED);
#endif /* STD_ON == NVM_E_WRONG_BLOCK_ID_SWITCH */
		}
		else /* NVM_JOB_READ_RAM_FAIL == NvM_RunJob.NvM_InternalJobStatus */
		{
			NvM_RunJob.NvM_PreBlockState = NVM_BLOCK_INVALID_UNCHANGED;
			NvM_RunJob.NvM_PreBlockRequestResult = NVM_REQ_NOT_OK;
#if (STD_ON == NVM_E_REQ_FAILED_SWITCH)
			Dem_ReportErrorStatus(NVM_E_REQ_FAILED,DEM_EVENT_STATUS_FAILED);
#endif /* STD_ON == NVM_E_REQ_FAILED_SWITCH */
		}
	}
	else if(MEMIF_JOB_FAILED == NvM_RunJob.NvM_MemIfJobResult)
	{
		NvM_RunJob.NvM_PreBlockState = NVM_BLOCK_INVALID_UNCHANGED;
		/* @req [SWS_NvM_00359] */
		NvM_RunJob.NvM_PreBlockRequestResult = NVM_REQ_NOT_OK;
		/* @req [SWS_NvM_00316] */
		if((boolean)TRUE == NVM_IS_WRITE_ONCE(pBlockDescriptor,BlockId-1U))
		{
			pCurrentJob->NvM_BlockProtection = (boolean)TRUE;
		}

#if (STD_ON == NVM_E_REQ_FAILED_SWITCH)
		/* @req [SWS_NvM_00654] */
		Dem_ReportErrorStatus(NVM_E_REQ_FAILED,DEM_EVENT_STATUS_FAILED);
#endif /* STD_ON == NVM_E_REQ_FAILED_SWITCH */
#if (STD_ON == NVM_E_HARDWARE_SWITCH)
		/* @req [SWS_NvM_00835] */
		Dem_ReportErrorStatus(NVM_E_HARDWARE,DEM_EVENT_STATUS_FAILED);
#endif /* STD_ON == NVM_E_HARDWARE_SWITCH */
	}
	else if(MEMIF_BLOCK_INCONSISTENT == NvM_RunJob.NvM_MemIfJobResult)
	{
		NvM_RunJob.NvM_PreBlockState = NVM_BLOCK_INVALID_UNCHANGED;
		/* @req [SWS_NvM_00358] */
		NvM_RunJob.NvM_PreBlockRequestResult = NVM_REQ_INTEGRITY_FAILED;
#if (STD_ON == NVM_E_INTEGRITY_FAILED_SWITCH)
		/* @req [SWS_NvM_00653] */
		Dem_ReportErrorStatus(NVM_E_INTEGRITY_FAILED,DEM_EVENT_STATUS_FAILED);
#endif /* STD_ON == NVM_E_REQ_FAILED_SWITCH */
#if (STD_ON == NVM_E_HARDWARE_SWITCH)
		/* @req [SWS_NvM_00835] */
		Dem_ReportErrorStatus(NVM_E_HARDWARE,DEM_EVENT_STATUS_FAILED);
#endif /* STD_ON == NVM_E_HARDWARE_SWITCH */
	}
	else if(MEMIF_BLOCK_INVALID == NvM_RunJob.NvM_MemIfJobResult)
	{
		NvM_RunJob.NvM_PreBlockState = NVM_BLOCK_INVALID_UNCHANGED;
		/* @req [SWS_NvM_00341] */
		NvM_RunJob.NvM_PreBlockRequestResult = NVM_REQ_NV_INVALIDATED;
		/* @req [SWS_NvM_00652] */
	}
	else
	{
		/* Do nothing */
	}

	if((NVM_BLOCK_INVALID_UNCHANGED == NvM_RunJob.NvM_PreBlockState) && \
			((NvM_RunJob.NvM_CurrentRunJob == NVM_READ_BLOCK) || \
					(NvM_RunJob.NvM_CurrentRunJob == NVM_READ_PRAM_BLOCK) || \
					(NvM_RunJob.NvM_MultipleBlocksToRead == (boolean)TRUE)))
	{
		if((NULL_PTR != NVM_GET_ROM_BLOCK_ADDRESS(pBlockDescriptor,BlockId-1U)) || \
			(NULL_PTR != NVM_GET_INIT_BLOCK_CALLBACK(pBlockDescriptor,BlockId-1U)))
		{
			NvM_RunJob.NvM_RestoreDefaultJob = (boolean)TRUE;
			NvM_RunJob.NvM_InternalJob = NVM_JOB_INVALID;
		}
		else
		{
			pCurrentJob->NvM_BlockState = NvM_RunJob.NvM_PreBlockState;
			pCurrentJob->NvM_BlockRequestResult = NvM_RunJob.NvM_PreBlockRequestResult;

			NvM_Callback(pBlockDescriptor, BlockId, pCurrentJob);
			if(NvM_RunJob.NvM_MultipleBlocksToRead == (boolean)TRUE)
			{
				NvM_RunJob.NvM_MultipleBlocksToRead = (boolean)FALSE;
			}
		}
	}
	else
	{
		pCurrentJob->NvM_BlockState = NvM_RunJob.NvM_PreBlockState;
		pCurrentJob->NvM_BlockRequestResult = NvM_RunJob.NvM_PreBlockRequestResult;

		NvM_Callback(pBlockDescriptor, BlockId, pCurrentJob);
		if(NvM_RunJob.NvM_MultipleBlocksToRead == (boolean)TRUE)
		{
			NvM_RunJob.NvM_MultipleBlocksToRead = (boolean)FALSE;
		}
	}
}

/**
 * @brief   	Internal write job finish
 * @details
 * @param[in]      pBlockDescriptor		A pointer to block configuration information
 * @param[in]      BlockId				Block Id
 * @param[in]      pCurrentJob			A pointer to the management block of the current block
 */
STATIC FUNC(void, NVM_CODE) NvM_InternalWriteJobFinish
(
	P2CONST(NvM_BlockDescriptorType, NVM_VAR, NVM_APPL_CONST) pBlockDescriptor,
	VAR(NvM_BlockIdType, AUTOMATIC) BlockId,
	P2VAR(NvM_AdministrativeBlockType, NVM_VAR, NVM_APPL_CONST) pCurrentJob
)
{
	if(((NVM_JOB_MEMIF_FAIL == NvM_RunJob.NvM_InternalJobStatus) || \
			(NVM_JOB_WRITE_RAM_FAIL == NvM_RunJob.NvM_InternalJobStatus) || \
			(MEMIF_JOB_FAILED == NvM_RunJob.NvM_MemIfJobResult) || \
			(NVM_JOB_WRITE_VALIDATION_FAIL == NvM_RunJob.NvM_InternalJobStatus)) && \
			((boolean)FALSE == NvM_RunJob.NvM_IsRedundantBlockJobOK))
	{
		NvM_RunJob.NvM_PreBlockState = NVM_BLOCK_INVALID_UNCHANGED;
		/* @req [SWS_NvM_00213] */
		NvM_RunJob.NvM_PreBlockRequestResult = NVM_REQ_NOT_OK;
		if(NvM_RunJob.NvM_InternalJobStatus != NVM_JOB_WRITE_VALIDATION_FAIL)
		{
#if (STD_ON == NVM_E_REQ_FAILED_SWITCH)
			/* @req [SWS_NvM_00659] */
			Dem_ReportErrorStatus(NVM_E_REQ_FAILED,DEM_EVENT_STATUS_FAILED);
#endif /* STD_ON == NVM_E_REQ_FAILED_SWITCH */
		}
		else
		{
#if (STD_ON == NVM_E_VERIFY_FAILED_SWITCH)
			/* @req [SWS_NvM_00528] */
			Dem_ReportErrorStatus(NVM_E_VERIFY_FAILED,DEM_EVENT_STATUS_FAILED);
#endif /* STD_ON == NVM_E_REQ_FAILED_SWITCH */
		}

#if (STD_ON == NVM_E_HARDWARE_SWITCH)
		if(MEMIF_JOB_FAILED == NvM_RunJob.NvM_MemIfJobResult)
		{
			/* @req [SWS_NvM_00835] */
			Dem_ReportErrorStatus(NVM_E_HARDWARE,DEM_EVENT_STATUS_FAILED);
		}
#endif /* STD_ON == NVM_E_HARDWARE_SWITCH */
	}
	else
	{
		pCurrentJob->NvM_BlockCrc = NvM_RunJob.NvM_TemporaryCrc;

		NvM_RunJob.NvM_PreBlockState = NVM_BLOCK_VALID_UNCHANGED;
		/* @req [SWS_NvM_00328] */
		NvM_RunJob.NvM_PreBlockRequestResult = NVM_REQ_OK;

		/* @req [SWS_NvM_00316] */
		if((boolean)TRUE == NVM_IS_WRITE_ONCE(pBlockDescriptor,BlockId-1U))
		{
			pCurrentJob->NvM_BlockProtection = (boolean)TRUE;
		}
	}

	pCurrentJob->NvM_BlockState = NvM_RunJob.NvM_PreBlockState;
	pCurrentJob->NvM_BlockRequestResult = NvM_RunJob.NvM_PreBlockRequestResult;

	NvM_Callback(pBlockDescriptor, BlockId, pCurrentJob);
	if(NvM_RunJob.NvM_MultipleBlocksToWrite == (boolean)TRUE)
	{
		NvM_RunJob.NvM_MultipleBlocksToWrite = (boolean)FALSE;
	}
}

/**
 * @brief   	Internal erase or invalidate job finish
 * @details
 * @param[in]      pBlockDescriptor		A pointer to block configuration information
 * @param[in]      BlockId				Block Id
 * @param[in]      pCurrentJob			A pointer to the management block of the current block
 */
STATIC FUNC(void, NVM_CODE) NvM_InternalEraseOrInvalidateJobFinish
(
	P2CONST(NvM_BlockDescriptorType, NVM_VAR, NVM_APPL_CONST) pBlockDescriptor,
	VAR(NvM_BlockIdType, AUTOMATIC) BlockId,
	P2VAR(NvM_AdministrativeBlockType, NVM_VAR, NVM_APPL_CONST) pCurrentJob
)
{
	/* @req [SWS_NvM_00269] */
	/* @req [SWS_NvM_00274] */
	if(MEMIF_JOB_FAILED == NvM_RunJob.NvM_MemIfJobResult)
	{
		/* @req [SWS_NvM_00271] */
		/* @req [SWS_NvM_00275] */
		NvM_RunJob.NvM_PreBlockRequestResult = NVM_REQ_NOT_OK;
#if (STD_ON == NVM_E_REQ_FAILED_SWITCH)
		/* @req [SWS_NvM_00663] */
		/* @req [SWS_NvM_00666] */
		Dem_ReportErrorStatus(NVM_E_REQ_FAILED,DEM_EVENT_STATUS_FAILED);
#endif /* STD_ON == NVM_E_REQ_FAILED_SWITCH */
	}
	else if(MEMIF_JOB_OK == NvM_RunJob.NvM_MemIfJobResult)
	{
		NvM_RunJob.NvM_PreBlockState = NVM_BLOCK_INVALID_UNCHANGED;
		NvM_RunJob.NvM_PreBlockRequestResult = NVM_REQ_OK;
	}
	else
	{
		/* Do nothing */
	}

	pCurrentJob->NvM_BlockState = NvM_RunJob.NvM_PreBlockState;
	pCurrentJob->NvM_BlockRequestResult = NvM_RunJob.NvM_PreBlockRequestResult;

	NvM_Callback(pBlockDescriptor, BlockId, pCurrentJob);
}

/**
 * @brief   	Internal job finish
 * @details
 * @param[in]      pBlockDescriptor		A pointer to block configuration information
 * @param[in]      BlockId				Block Id
 * @param[in]      pCurrentJob			A pointer to the management block of the current block
 */
STATIC FUNC(void, NVM_CODE) NvM_InternalJobFinish
(
	P2CONST(NvM_BlockDescriptorType, NVM_VAR, NVM_APPL_CONST) pBlockDescriptor,
	VAR(NvM_BlockIdType, AUTOMATIC) BlockId,
	P2VAR(NvM_AdministrativeBlockType, NVM_VAR, NVM_APPL_CONST) pCurrentJob
)
{
	if((NvM_RunJob.NvM_CurrentRunJob == NVM_RESTORE_BLOCK_DEFAULTS) || \
			(NvM_RunJob.NvM_CurrentRunJob == NVM_RESTORE_PRAM_BLOCK_DEFAULTS) || \
			((boolean)TRUE == NvM_RunJob.NvM_RestoreDefaultJob))
	{
		NvM_InternalResetBlockDefaultJobFinish(pBlockDescriptor, BlockId, pCurrentJob);
	}
	else if((NvM_RunJob.NvM_CurrentRunJob == NVM_READ_BLOCK) || \
			(NvM_RunJob.NvM_CurrentRunJob == NVM_READ_PRAM_BLOCK) || \
			(NvM_RunJob.NvM_MultipleBlocksToRead == (boolean)TRUE))
	{
		NvM_InternalReadJobFinish(pBlockDescriptor, BlockId, pCurrentJob);
	}
	else if((NvM_RunJob.NvM_CurrentRunJob == NVM_WRITE_BLOCK) || \
			(NvM_RunJob.NvM_CurrentRunJob == NVM_WRITE_PRAM_BLOCK) || \
			(NvM_RunJob.NvM_MultipleBlocksToWrite == (boolean)TRUE))
	{
		NvM_InternalWriteJobFinish(pBlockDescriptor, BlockId, pCurrentJob);
	}
	else if((NvM_RunJob.NvM_CurrentRunJob == NVM_ERASE_NV_BLOCK) || \
			(NvM_RunJob.NvM_CurrentRunJob == NVM_INVALIDATE_NV_BLOCK))
	{
		NvM_InternalEraseOrInvalidateJobFinish(pBlockDescriptor, BlockId, pCurrentJob);
	}
	else if((NvM_RunJob.NvM_CurrentRunJob == NVM_READ_ALL) && \
			(NvM_RunJob.NvM_MultipleRequestEnd == (boolean)TRUE))
	{
		NVM_GET_RESULT_OF_MULTIPLE_JOB();
		NvM_Callback(pBlockDescriptor, BlockId, pCurrentJob);
	}
	else if((NvM_RunJob.NvM_CurrentRunJob == NVM_WRITE_ALL) && \
			(NvM_RunJob.NvM_MultipleRequestEnd == (boolean)TRUE))
	{
		NVM_GET_RESULT_OF_MULTIPLE_JOB();
		NvM_Callback(pBlockDescriptor, BlockId, pCurrentJob);
	}
	else if(NvM_RunJob.NvM_CurrentRunJob == NVM_VALIDATE_ALL)
	{
		NVM_GET_RESULT_OF_MULTIPLE_JOB();
		NvM_Callback(pBlockDescriptor, BlockId, pCurrentJob);
	}
	else
	{
		/* Do nothing */
	}

	if(((NvM_RunJob.NvM_CurrentRunJob == NVM_READ_ALL) || \
			((NvM_RunJob.NvM_CurrentRunJob == NVM_WRITE_ALL) && \
					(NvM_MultiBlockJob != NVM_CANCEL_WRITE_ALL))) && \
			(NvM_RunJob.NvM_MultipleRequestEnd != (boolean)TRUE))
	{
		if((pCurrentJob->NvM_BlockRequestResult != NVM_REQ_OK) && \
				(pCurrentJob->NvM_BlockRequestResult != NVM_REQ_PENDING))
		{
			NvM_RunJob.NvM_PreMultiBlockRequestResult = NVM_REQ_NOT_OK;
		}
	}
}

/**
 * @brief   	Execute an internal job
 * @details
 * @param[in]      pBlockDescriptor		A pointer to block configuration information
 * @param[in]      BlockId				Block Id
 * @param[in]      pCurrentJob			A pointer to the management block of the current block
 */
STATIC FUNC(void, NVM_CODE) NvM_InternalJobProcessing
(
	P2CONST(NvM_BlockDescriptorType, NVM_VAR, NVM_APPL_CONST) pBlockDescriptor,
	VAR(NvM_BlockIdType, AUTOMATIC) BlockId,
	P2VAR(NvM_AdministrativeBlockType, NVM_VAR, NVM_APPL_CONST) pCurrentJob
)
{
	/* Performs work in the current job state */
	if(NvM_RunJob.NvM_MemIfJobConfirmation == (boolean)TRUE)
	{
		NvM_MemIfJobIsRun(pBlockDescriptor, BlockId, pCurrentJob);
	}
	else if(NvM_RunJob.NvM_InternalJob == NVM_JOB_RESTORE_DEFAULTS)
	{
		/* Read failed, attempting to restore the default value */
		if((Std_ReturnType)E_OK == \
				NvM_RestoreRAMBlockToDefault(pBlockDescriptor,BlockId,pCurrentJob))
		{
			NvM_RunJob.NvM_InternalJobStatus = NVM_JOB_OK;
		}
		else
		{
			NvM_RunJob.NvM_InternalJobStatus = NVM_JOB_RESTORE_DEFAULTS_FAIL;
		}
	}
#if (STD_ON == NVM_USE_MIRROR_MECHANISM)
	else if(NVM_JOB_READ_RAM_BLOCK_FROM_NVM == NvM_RunJob.NvM_InternalJob)
	{
		if((Std_ReturnType)E_OK == \
				pBlockDescriptor[BlockId-1U].NvM_ReadRamBlockFromNvCallback( \
						&NvM_MirrorBlock[0]))
		{
			NvM_RunJob.NvM_InternalJobStatus = NVM_JOB_OK;
		}
		else
		{
			NvM_RunJob.NvM_InternalJobStatus = NVM_JOB_READ_RAM_FAIL;
		}
	}
	else if(NVM_JOB_WRITE_RAM_BLOCK_TO_NVM == NvM_RunJob.NvM_InternalJob)
	{
		if((Std_ReturnType)E_OK == \
				pBlockDescriptor[BlockId-1U].NvM_WriteRamBlockToNvCallback( \
						&NvM_MirrorBlock[0]))
		{
			/* @req [SWS_NvM_00303] */
			NvM_AdministrativeBlock[BlockId-1U].NvM_BlockState = NVM_BLOCK_VALID_CHANGED;
			NvM_RunJob.NvM_InternalJobStatus = NVM_JOB_OK;
		}
		else
		{
			NvM_RunJob.NvM_InternalJobStatus = NVM_JOB_WRITE_RAM_FAIL;
		}
	}
#endif /* STD_ON == NVM_USE_MIRROR_MECHANISM */
	else if(NvM_RunJob.NvM_InternalJob == NVM_JOB_CALCULATE_CRC)
	{
		NvM_InternalJobCalculareCRC(pBlockDescriptor,BlockId);
	}
	else if(NVM_JOB_FINISH == NvM_RunJob.NvM_InternalJob)
	{
		NvM_InternalJobFinish(pBlockDescriptor, BlockId, pCurrentJob);
	}
	else
	{
		/* Do nothing */
	}
}

#if(NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_2 || \
		NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3)
/**
 * @brief   	Cancel a job with the corresponding Block Id in the queue
 * @details
 * @param[in]      BlockId				Block Id
 * @param[in/out]  pJobScheduling	Point to Queue scheduling
 */
STATIC FUNC(void, NVM_CODE) NvM_CancelJobInQueue
(
	P2VAR(NvM_JobSchedulingType, NVM_VAR, NVM_APPL_CONST) pJobScheduling,
	VAR(NvM_BlockIdType, AUTOMATIC) BlockId
)
{
	VAR(uint16, AUTOMATIC) count;
	P2VAR(NvM_JobQueueType, NVM_VAR, NVM_APPL_CONST) pJob;
	P2VAR(NvM_JobQueueType, NVM_VAR, NVM_APPL_CONST) pClearJob;

	pJob = pJobScheduling->NvM_CurrentJob;
	if(NULL_PTR == pJob)
	{
		/* Do nothing */
	}
	else
	{
		for(count = pJobScheduling->NvM_JobNumber; count > 0U; count--)
		{
			if(pJob->NvM_NextJob->NvM_BlockId == BlockId)
			{
				pClearJob = pJob->NvM_NextJob;

				pJob->NvM_NextJob = pClearJob->NvM_NextJob;
				pJobScheduling->NvM_JobNumber--;

				pClearJob->NvM_JobIsValid = (boolean)FALSE;
				pClearJob->NvM_Job = NVM_INVALID_JOB;
				pClearJob->NvM_NextJob = NULL_PTR;
				NvM_AdministrativeBlock[BlockId-1U].NvM_BlockRequestResult = NVM_REQ_CANCELED;
			}
			else
			{
				pJob = pJob->NvM_NextJob;
			}
		}

		if((pJobScheduling->NvM_CurrentJob->NvM_BlockId == BlockId) && \
				(pJobScheduling->NvM_JobNumber > 0U))
		{
			pClearJob = pJobScheduling->NvM_CurrentJob;

			pJobScheduling->NvM_CurrentJob = pClearJob->NvM_NextJob;
			pJobScheduling->NvM_JobNumber--;

			pClearJob->NvM_JobIsValid = (boolean)FALSE;
			pClearJob->NvM_Job = NVM_INVALID_JOB;
			pClearJob->NvM_NextJob = NULL_PTR;
			NvM_AdministrativeBlock[BlockId-1U].NvM_BlockRequestResult = NVM_REQ_CANCELED;
		}
	}
}
#endif /* NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_2 || \
		NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_1 */

#if (STD_ON == NVM_POLLING_MODE)
/**
 * @brief   	Get the MemIf job status
 * @details
 */
STATIC FUNC(void, NVM_CODE) NvM_GetMemIfStatus(void)
{
	P2CONST(NvM_BlockDescriptorType, NVM_VAR, NVM_APPL_CONST) pBlockDescriptor = \
			NvM_Config.NvM_BlockDescriptor;

	if(((NvM_RunJob.NvM_InternalJob == NVM_JOB_READ) || \
			(NvM_RunJob.NvM_InternalJob == NVM_JOB_WRITE) || \
			(NvM_RunJob.NvM_InternalJob == NVM_JOB_ERASE_IMMEDIATE_BLOCK)  || \
			(NvM_RunJob.NvM_InternalJob == NVM_JOB_INVALIDATE_BLOCK) || \
			(NvM_RunJob.NvM_InternalJob == NVM_JOB_WRITE_VALIDATION)) && \
			(NvM_RunJob.NvM_InternalJobStatus != NVM_JOB_MEMIF_FAIL) && \
			(NvM_RunJob.NvM_InternalJobStatus != NVM_JOB_WRITE_VALIDATION_FAIL))
	{
		NvM_RunJob.NvM_MemIfJobResult = \
				MemIf_GetJobResult(NVM_GET_BLOCK_DEVICE_INDEX(pBlockDescriptor, \
						NvM_RunJob.NvM_CurrentRunBlockId-1U));
		if(MEMIF_JOB_PENDING == NvM_RunJob.NvM_MemIfJobResult)
		{
			NvM_RunJob.NvM_InternalJobStatus = NVM_JOB_PENDING;
		}
		else if(MEMIF_JOB_OK == NvM_RunJob.NvM_MemIfJobResult)
		{
			NvM_RunJob.NvM_InternalJobStatus = NVM_JOB_OK;
		}
		else
		{
			NvM_RunJob.NvM_InternalJobStatus = NVM_JOB_MEMIF_FAIL;
		}
	}
}
#endif /* STD_ON == NVM_POLLING_MODE */

/**
 * @brief   	Compare static block ID
 * @details
 * @param[in]      pBlockDescriptor		A pointer to block configuration information
 * @param[in]      BlockId				Block Id
 * @param[in]      pCurrentJob			A pointer to the management block of the current block
 * @return	boolean
 * @retval 	FALSE: The static block ID is not the same
 * 			TRUE: The static block ID is same
 */
STATIC FUNC(boolean, NVM_CODE) NvM_CompareStaticBlockId
(
	P2CONST(NvM_BlockDescriptorType, NVM_VAR, NVM_APPL_CONST) pBlockDescriptor,
	VAR(NvM_BlockIdType, AUTOMATIC) BlockId,
	P2CONST(NvM_AdministrativeBlockType, NVM_VAR, NVM_APPL_CONST) pCurrentJob
)
{
	VAR(boolean, AUTOMATIC) ret = (boolean)FALSE;
	if((boolean)FALSE == NVM_GET_STATIC_BLOCK_ID_CHECK(pBlockDescriptor,BlockId-1U))
	{
		ret = (boolean)TRUE;
	}
	else
	{
		if((NvM_NVRAMTemporaryData[0] == (uint8)(BlockId & 0xffU)) && \
				(NvM_NVRAMTemporaryData[1] == (uint8)((BlockId >> 8U) & 0xffU)) && \
				(NvM_NVRAMTemporaryData[2] == \
						(uint8)(((NVM_GET_NV_BLOCK_BASE_NUMBER(pBlockDescriptor,BlockId-1U) \
						<< NVM_DATASET_SELECTION_BITS) + \
								pCurrentJob->NvM_BlockIndex) & 0xffU)) && \
				(NvM_NVRAMTemporaryData[3] == \
						(uint8)((((NVM_GET_NV_BLOCK_BASE_NUMBER(pBlockDescriptor,BlockId-1U) \
						<< NVM_DATASET_SELECTION_BITS) + pCurrentJob->NvM_BlockIndex) >> 8U) & 0xffU)))
		{
			ret = (boolean)TRUE;
		}
	}

	return ret;
}

/**
 * @brief   	Verify the writen data
 * @details
 * @param[in]      pBlockDescriptor		A pointer to block configuration information
 * @param[in]      BlockId				Block Id
 * @param[in]      pCurrentJob			A pointer to the management block of the current block
 */
STATIC FUNC(void, NVM_CODE) NvM_WriteValidation
(
	P2CONST(NvM_BlockDescriptorType, NVM_VAR, NVM_APPL_CONST) pBlockDescriptor,
	VAR(NvM_BlockIdType, AUTOMATIC) BlockId,
	P2CONST(NvM_AdministrativeBlockType, NVM_VAR, NVM_APPL_CONST) pCurrentJob
)
{
	VAR(uint16, AUTOMATIC) offset = 0U;
	VAR(uint16, AUTOMATIC) CrcOffset = 0U;
	VAR(uint16, AUTOMATIC) BlockLength = 0U;
	VAR(uint16, AUTOMATIC) Index = NvM_RunJob.NvM_WriteValidationBytes;
	VAR(boolean, AUTOMATIC) flag = (boolean)TRUE;
	P2VAR(uint8, NVM_VAR, NVM_APPL_CONST) pData = pCurrentJob->NvM_RAMAddress;

	NVM_GET_BLOCK_CRC_OFFSET(pBlockDescriptor,BlockId-1U,CrcOffset);
	NVM_GET_BLOCK_LENGTH(pBlockDescriptor,BlockId-1U,BlockLength);

	if((boolean)TRUE == NVM_GET_STATIC_BLOCK_ID_CHECK(pBlockDescriptor,BlockId-1U))
	{
		offset = 4U;
	}

	do
	{
		if(((boolean)TRUE == NVM_GET_STATIC_BLOCK_ID_CHECK(pBlockDescriptor,BlockId-1U)) && \
				(Index < 4U))
		{
			if(Index <= 1U)
			{
				if(NvM_NVRAMTemporaryData[Index] != \
						(uint8)((BlockId >> (Index*8U)) & 0xffU))
				{
					flag = (boolean)FALSE;
					break;
				}
			}
			else /* Index > 1U */
			{
				if(NvM_NVRAMTemporaryData[Index] != \
						(uint8)((((NVM_GET_NV_BLOCK_BASE_NUMBER(pBlockDescriptor,BlockId-1U) \
								<< NVM_DATASET_SELECTION_BITS) + pCurrentJob->NvM_BlockIndex) \
								>> ((Index - 2U)*8U)) & 0xffU))
				{
					flag = (boolean)FALSE;
					break;
				}
			}
		}
		else
		{
			if(Index < CrcOffset)
			{
				if(NvM_NVRAMTemporaryData[Index] != pData[Index - offset])
				{
					flag = (boolean)FALSE;
					break;
				}
			}
			/* PRQA S 2995,2996 EOF # The condition of judgment is not constant */
			else if((Index >= CrcOffset) && ((boolean)TRUE == NVM_IS_USE_CRC(pBlockDescriptor,BlockId-1U)))
			{
				if(NvM_NVRAMTemporaryData[Index] != \
						(uint8)(NvM_RunJob.NvM_TemporaryCrc >> ((Index - CrcOffset) * 8U)))
				{
					flag = (boolean)FALSE;
					break;
				}
			}
			else
			{
				/* Do nothing */
			}
		}
		Index++;
	}while((Index < (NvM_RunJob.NvM_WriteValidationBytes + \
			NVM_GET_BLOCK_WRITE_VERIFICATION_SIZE(pBlockDescriptor,BlockId-1U))) && \
			(Index < BlockLength));

	if((boolean)TRUE == flag)
	{
		NvM_RunJob.NvM_WriteValidationBytes = Index;
		if(NvM_RunJob.NvM_WriteValidationBytes == BlockLength)
		{
			 NvM_RunJob.NvM_InternalJobStatus = NVM_JOB_OK;
		}
		else
		{
			NvM_RunJob.NvM_InternalJobStatus = NVM_JOB_WRITE_VERIFYING;
			NvM_RunJob.NvM_MemIfJobConfirmation = (boolean)TRUE;
		}
	}
	else
	{
		NvM_RunJob.NvM_WriteValidationBytes = 0U;
		NvM_RunJob.NvM_InternalJobStatus = NVM_JOB_WRITE_VALIDATION_FAIL;
	}
}
/*====================================================================================================*
 *                                          GLOBAL FUNCTIONS                                        
 *====================================================================================================*/
#if (\
	NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_1 || \
	NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_2 || \
	NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3 \
	)
/**
 * @sid            0x00
 * @brief          Service for resetting all internal variables.
 * @details        The Configuration pointer ConfigPtr shall always have a NULL_PTR value,
 *                 The Configuration pointer ConfigPtr is currently not used and shall therefore
 *                 be set to  a NULL_PTR value when calling the NvM_Init API.
 *
 * @param[in]      none.
 * @param[in]      none.
 */
FUNC(void, NVM_CODE) NvM_Init(P2CONST(NvM_ConfigType, AUTOMATIC, NVM_APPL_CONST) ConfigPtr)
{
	VAR(uint16, AUTOMATIC) count = 0U;
	P2CONST(NvM_BlockDescriptorType, NVM_VAR, NVM_APPL_CONST) pBlockDescriptor = \
			NvM_Config.NvM_BlockDescriptor;

	/* @req [SWS_NvM_00881] The Configuration pointer ConfigPtr shall always have a NULL_PTR value. */
	(void)ConfigPtr;

	/* Initialize all Administrative Blocks  */
	do
	{
		NvM_AdministrativeBlock[count].NvM_BlockState = NVM_BLOCK_INVALID_UNCHANGED;
		/* @req [SWS_NvM_00192] */
		NvM_AdministrativeBlock[count].NvM_BlockIndex = 0U;
		NvM_AdministrativeBlock[count].NvM_BlockLockStatus = (boolean)FALSE;
		NvM_AdministrativeBlock[count].NvM_BlockRequestResult = NVM_REQ_OK;
		NvM_AdministrativeBlock[count].NvM_BlockProtection = \
				NVM_GET_BLOCK_IS_WRITE_PROTESTED(pBlockDescriptor,count);
		NvM_AdministrativeBlock[count].NvM_RAMAddress = \
				NVM_GET_RAM_BLOCK_ADDRESS(pBlockDescriptor,count);
		NvM_AdministrativeBlock[count].NvM_BlockCrc = NVM_INVALID_CRC;
		NvM_AdministrativeBlock[count].NvM_NumOfWriteRetries = 0U;
		NvM_AdministrativeBlock[count].NvM_NumOfReadRetries = 0U;
		count++;
	}while(count < NVM_NUM_OF_BLOCK);

#if (NVM_JOB_PRIORITIZATION == STD_ON)
	/* Initialize Immediate queue */
	count = 0U;
	NvM_ImmediateJobScheduling.NvM_CurrentJob = NULL_PTR;
	NvM_ImmediateJobScheduling.NvM_JobNumber = 0U;
	do
	{
		NvM_ImmediateJobQueue[count].NvM_BlockId = 0U;
		NvM_ImmediateJobQueue[count].NvM_Job = NVM_INVALID_JOB;
		NvM_ImmediateJobQueue[count].NvM_JobPriority = NVM_INVALID_JOB_PRIORITY;
		NvM_ImmediateJobQueue[count].NvM_NextJob = NULL_PTR;
		NvM_ImmediateJobQueue[count].NvM_JobIsValid = (boolean)FALSE;
		count++;
	}while(count < NVM_SIZE_IMMEDIATE_JOB_QUEUE);
#endif /* NVM_JOB_PRIORITIZATION == STD_ON */

	/* Initialize Standard queue */
	count = 0U;
	NvM_StandardJobScheduling.NvM_CurrentJob = NULL_PTR;
	NvM_StandardJobScheduling.NvM_JobNumber = 0U;
	do
	{
		NvM_StandardJobQueue[count].NvM_BlockId = 0U;
		NvM_StandardJobQueue[count].NvM_Job = NVM_INVALID_JOB;
		NvM_StandardJobQueue[count].NvM_JobPriority = NVM_INVALID_JOB_PRIORITY;
		NvM_StandardJobQueue[count].NvM_NextJob = NULL_PTR;
		NvM_StandardJobQueue[count].NvM_JobIsValid = (boolean)FALSE;
		count++;
	}while(count < NVM_SIZE_STANDARD_JOB_QUEUE);

	/* Initialize the temporary data buffer */
	count = 0U;
	do
	{
		NvM_NVRAMTemporaryData[count] = NVM_INVALID_DATA;
		count++;
	}while(count < NVM_MAX_NVRAM_LENGTH);

	/* Initialize Multi Block Job */
	NvM_MultiBlockJob = NVM_INVALID_JOB;

	/* Initialize Run Job */
	NvM_RunJob.NvM_MultipleRequestEnd = (boolean)FALSE;
	NvM_RunJob.NvM_MultipleBlocksToRead = (boolean)FALSE;
	NvM_RunJob.NvM_MultipleBlocksToWrite = (boolean)FALSE;
	NvM_RunJob.NvM_ConfigureIDIsOK = (boolean)FALSE;
	NvM_RunJob.NvM_CurrentRunJob = NVM_INVALID_JOB;
	NvM_RunJob.NvM_CurrentRunBlockId = 0U;
	NvM_RunJob.NvM_IsInterrupted = (boolean)FALSE;
	NvM_RunJob.NvM_MemIfJobConfirmation = (boolean)FALSE;
	NvM_RunJob.NvM_InterruptedJob = NVM_INVALID_JOB;
	NvM_RunJob.NvM_InterruptedBlockId = 0U;
	NvM_RunJob.NvM_IsLastRedundantBlock = (boolean)FALSE;
	NvM_RunJob.NvM_IsRedundantBlockJobOK = (boolean)FALSE;
	NvM_RunJob.NvM_RestoreDefaultJob = (boolean)FALSE;
	NvM_RunJob.NvM_TemporaryCrc = NVM_INVALID_CRC;
	NvM_RunJob.NvM_InternalJob = NVM_JOB_INVALID;
	NvM_RunJob.NvM_InternalJobStatus = NVM_JOB_OK;
	NvM_RunJob.NvM_MemIfJobResult = MEMIF_JOB_OK;
	NvM_RunJob.NvM_PreMultiBlockRequestResult = NVM_REQ_OK;
	NvM_RunJob.NvM_WriteValidationBytes = 0U;
	NvM_RunJob.NvM_CrcCalculatedBytes = 0U;
	NvM_RunJob.NvM_PreBlockState = NVM_BLOCK_INVALID_UNCHANGED;
	NvM_RunJob.NvM_PreBlockRequestResult = NVM_REQ_OK;
#if (STD_ON == NVM_USE_MIRROR_MECHANISM)
	NvM_RunJob.NvM_NumOfMirrorOperationRetries = 0U;
#endif /* STD_ON == NVM_USE_MIRROR_MECHANISM */

	/* @req [SWS_NvM_00399] Complete initialization */
	NvM_InitDown = (boolean)TRUE;
}
#endif /* NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_1 || \
		NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_2 || \
		NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3 */

#if (\
	NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_2 || \
	NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3 \
	)
/**
 * @sid            0x01
 * @brief          Service for setting the DataIndex of a dataset NVRAM block.
 *
 * @param[in]      BlockId    The block identifier uniquely identifies one NVRAM block
 *                            descriptor. A NVRAM block descriptor contains all needed
 *                            information about a single NVRAM block.
 * @param[in]      DataIndex  Index position (association) of a NV/ROM block.
 *
 * @return         Std_ReturnType
 * @retval         E_OK      The index position was set successfully
 * @retval         E_NOT_OK  An error occurred.
 *
 */
FUNC(Std_ReturnType, NVM_CODE) NvM_SetDataIndex
(
	VAR(NvM_BlockIdType, AUTOMATIC) BlockId,
	VAR(uint8, AUTOMATIC) DataIndex
)
{
	VAR(Std_ReturnType, AUTOMATIC) ret = (Std_ReturnType)E_NOT_OK;

	P2CONST(NvM_BlockDescriptorType, NVM_VAR, NVM_APPL_CONST) pBlockDescriptor = \
			NvM_Config.NvM_BlockDescriptor;

	if((boolean)TRUE != NvM_InitDown)
	{
#if (NVM_DEV_ERROR_DETECT == STD_ON)
		/* @req [SWS_NvM_00027] */
		NVM_DET_REPORT_ERROR(NVM_SID_SETDATAINDEX,NVM_E_NOT_INITIALIZED);
#endif /* NVM_DEV_ERROR_DETECT == STD_ON */
	}
	else if((BlockId == 0U) || ((BlockId-1U) >= NVM_NUM_OF_BLOCK))
	{
#if (NVM_DEV_ERROR_DETECT == STD_ON)
		/* @req [SWS_NvM_00601] */
		NVM_DET_REPORT_ERROR(NVM_SID_SETDATAINDEX,NVM_E_PARAM_BLOCK_ID);
#endif /* NVM_DEV_ERROR_DETECT == STD_ON */
	}
	else if(NVM_BLOCK_DATASET != NVM_GET_BLOCK_MANAGEMENT_TYPE(pBlockDescriptor,BlockId-1U))
	{
#if (NVM_DEV_ERROR_DETECT == STD_ON)
		/* @req [SWS_NvM_00264] */
		NVM_DET_REPORT_ERROR(NVM_SID_SETDATAINDEX,NVM_E_PARAM_BLOCK_TYPE);
#endif /* NVM_DEV_ERROR_DETECT == STD_ON */
	}
	else if(NVM_REQ_PENDING == NvM_AdministrativeBlock[BlockId-1U].NvM_BlockRequestResult)
	{
#if (NVM_DEV_ERROR_DETECT == STD_ON)
		/* @req [SWS_NvM_00598] */
		NVM_DET_REPORT_ERROR(NVM_SID_SETDATAINDEX,NVM_E_BLOCK_PENDING);
#endif /* NVM_DEV_ERROR_DETECT == STD_ON */
	}
	else if(DataIndex >= NVM_GET_DATASETS_BLOCK_NUMBER(pBlockDescriptor,BlockId-1U))
	{
#if (NVM_DEV_ERROR_DETECT == STD_ON)
		/* @req [SWS_NvM_00599] */
		NVM_DET_REPORT_ERROR(NVM_SID_SETDATAINDEX,NVM_E_PARAM_BLOCK_DATA_IDX);
#endif /* NVM_DEV_ERROR_DETECT == STD_ON */
	}
	else if((boolean)TRUE == NvM_AdministrativeBlock[BlockId-1U].NvM_BlockLockStatus)
	{
#if (NVM_DEV_ERROR_DETECT == STD_ON)
		NVM_DET_REPORT_ERROR(NVM_SID_SETDATAINDEX,NVM_E_BLOCK_LOCKED);
#endif /* NVM_DEV_ERROR_DETECT == STD_ON */
	}
	else
	{
		/* @req [SWS_NvM_00014] */
		NvM_AdministrativeBlock[BlockId-1U].NvM_BlockIndex = DataIndex;

		ret = (Std_ReturnType)E_OK;
	}

	return ret;
}
#endif /* NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_2 || \
		NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3 */

#if (\
	NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_2 || \
	NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3 \
	)
/**
 * @sid            0x02
 * @brief          Service for getting the currently set DataIndex of a data set NVRAM block
 *
 * @param[in]      BlockId    The block identifier uniquely identifies one NVRAM block
 *                             descriptor. A NVRAM block descriptor contains all needed
 *                             information about a single NVRAM block.
 * @param[out]     DataIndexPtr  Pointer to where to store the current dataset index (0..255)
 *
 * @return         Std_ReturnType
 * @retval         E_OK      The index position has been retrieved successfully.
 * @retval         E_NOT_OK  An error occurred
 *
 */
FUNC(Std_ReturnType, NVM_CODE) NvM_GetDataIndex
(
	VAR(NvM_BlockIdType, AUTOMATIC) BlockId,
	P2VAR(uint8, AUTOMATIC, NVM_APPL_VAR) DataIndexPtr
)
{
	VAR(Std_ReturnType, AUTOMATIC) ret = (Std_ReturnType)E_NOT_OK;

	P2CONST(NvM_BlockDescriptorType, NVM_VAR, NVM_APPL_CONST) pBlockDescriptor = \
			NvM_Config.NvM_BlockDescriptor;

	if((boolean)TRUE != NvM_InitDown)
	{
#if (NVM_DEV_ERROR_DETECT == STD_ON)
		/* @req [SWS_NvM_00602] */
		NVM_DET_REPORT_ERROR(NVM_SID_GETDATAINDEX,NVM_E_NOT_INITIALIZED);
#endif /* NVM_DEV_ERROR_DETECT == STD_ON */
	}
	else if((0U == BlockId) || ((BlockId-1U) >= NVM_NUM_OF_BLOCK))
	{
#if (NVM_DEV_ERROR_DETECT == STD_ON)
		/* @req [SWS_NvM_00604] */
		NVM_DET_REPORT_ERROR(NVM_SID_GETDATAINDEX,NVM_E_PARAM_BLOCK_ID);
#endif /* NVM_DEV_ERROR_DETECT == STD_ON */
	}
	else if(NULL_PTR == DataIndexPtr)
	{
#if (NVM_DEV_ERROR_DETECT == STD_ON)
		/* @req [SWS_NvM_00605] */
		NVM_DET_REPORT_ERROR(NVM_SID_GETDATAINDEX,NVM_E_PARAM_DATA);
#endif /* NVM_DEV_ERROR_DETECT == STD_ON */
	}
	else if(NVM_BLOCK_DATASET != NVM_GET_BLOCK_MANAGEMENT_TYPE(pBlockDescriptor,BlockId-1U))
	{
		/* @req [SWS_NvM_00265] */
		(*DataIndexPtr) = 0U;
#if (NVM_DEV_ERROR_DETECT == STD_ON)
		NVM_DET_REPORT_ERROR(NVM_SID_GETDATAINDEX,NVM_E_PARAM_BLOCK_TYPE);
#endif /* NVM_DEV_ERROR_DETECT == STD_ON */
	}
	else
	{
		(*DataIndexPtr) = NvM_AdministrativeBlock[BlockId-1U].NvM_BlockIndex;
		ret = (Std_ReturnType)E_OK;
	}

	return ret;
}
#endif /* NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_2 || \
		NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3 */

#if (NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3)
/**
 * @sid            0x03
 * @brief          Service for setting/resetting the write protection for a NV block
 *
 * @param[in]      BlockId     The block identifier uniquely identifies one NVRAM block descriptor.
 *                             A NVRAM block descriptor contains all needed information about a
 *                             single NVRAM block
 *                 ProtectionEnabled  TRUE: Write protection shall be enabled
 *                                    FALSE: Write protection shall be disabled
 *
 * @return         Std_ReturnType
 * @retval         E_OK      The block was enabled/disabled as requested
 * @retval         E_NOT_OK  An error occurred
 *
 */
FUNC(Std_ReturnType, NVM_CODE) NvM_SetBlockProtection
(
	VAR(NvM_BlockIdType, AUTOMATIC) BlockId,
	VAR(boolean, AUTOMATIC) ProtectionEnabled
)
{
	VAR(Std_ReturnType, AUTOMATIC) ret = (Std_ReturnType)E_NOT_OK;
	P2CONST(NvM_BlockDescriptorType, NVM_VAR, NVM_APPL_CONST) pBlockDescriptor = \
			NvM_Config.NvM_BlockDescriptor;

	if((boolean)TRUE != NvM_InitDown)
	{
#if (NVM_DEV_ERROR_DETECT == STD_ON)
		/* @req [SWS_NvM_00606] */
		NVM_DET_REPORT_ERROR(NVM_SID_SETBLOCKPROTECTION,NVM_E_NOT_INITIALIZED);
#endif /* NVM_DEV_ERROR_DETECT == STD_ON */
	}
	else if((0U == BlockId) || ((BlockId-1U) >= NVM_NUM_OF_BLOCK))
	{
#if (NVM_DEV_ERROR_DETECT == STD_ON)
		/* @req [SWS_NvM_00609] */
		NVM_DET_REPORT_ERROR(NVM_SID_SETBLOCKPROTECTION,NVM_E_PARAM_BLOCK_ID);
#endif /* NVM_DEV_ERROR_DETECT == STD_ON */
	}
	else if(NVM_REQ_PENDING == NvM_AdministrativeBlock[BlockId-1U].NvM_BlockRequestResult)
	{
#if (NVM_DEV_ERROR_DETECT == STD_ON)
		/* @req [SWS_NvM_00607] */
		NVM_DET_REPORT_ERROR(NVM_SID_SETBLOCKPROTECTION,NVM_E_BLOCK_PENDING);
#endif /* NVM_DEV_ERROR_DETECT == STD_ON */
	}
	else if((boolean)TRUE == NVM_IS_WRITE_ONCE(pBlockDescriptor,BlockId-1U))
	{
#if (NVM_DEV_ERROR_DETECT == STD_ON)
		/* @req [SWS_NvM_00608] */
		NVM_DET_REPORT_ERROR(NVM_SID_SETBLOCKPROTECTION,NVM_E_BLOCK_CONFIG);
#endif /* NVM_DEV_ERROR_DETECT == STD_ON */
	}
	else if((boolean)TRUE == NvM_AdministrativeBlock[BlockId-1U].NvM_BlockLockStatus)
	{
#if (NVM_DEV_ERROR_DETECT == STD_ON)
		NVM_DET_REPORT_ERROR(NVM_SID_SETBLOCKPROTECTION,NVM_E_BLOCK_LOCKED);
#endif /* NVM_DEV_ERROR_DETECT == STD_ON */
	}
	else
	{
		NvM_AdministrativeBlock[BlockId-1U].NvM_BlockProtection = ProtectionEnabled;
		ret = (Std_ReturnType)E_OK;
	}

	return ret;
}
#endif /* NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3 */

#if (\
	NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_1 || \
	NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_2 || \
	NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3 \
	)
/**
 * @sid            0x04
 * @brief          read the block dependent error/status information.
 *
 * @param[in]      BlockId.    The block identifier uniquely identifies one NVRAM block descriptor.
 *                             A NVRAM block descriptor contains all needed information about a single
 *                             NVRAM block
 * @param[out]     RequestResultPtr   Pointer to where to store the request result.
 * 									  See NvM_RequestResultType
 *
 * @return         Std_ReturnType
 * @retval         E_OK      The block dependent error/status information was read successfully
 * @retval         E_NOT_OK  An error occurred
 *
 */
FUNC(Std_ReturnType, NVM_CODE) NvM_GetErrorStatus
(
	VAR(NvM_BlockIdType, AUTOMATIC) BlockId,
	P2VAR(NvM_RequestResultType, AUTOMATIC, NVM_APPL_VAR) RequestResultPtr
)
{
	VAR(Std_ReturnType, AUTOMATIC) ret = (Std_ReturnType)E_NOT_OK;

	if((boolean)TRUE != NvM_InitDown)
	{
#if (NVM_DEV_ERROR_DETECT == STD_ON)
		/* @req [SWS_NvM_00610] */
		NVM_DET_REPORT_ERROR(NVM_SID_GETERRORSTATUS,NVM_E_NOT_INITIALIZED);
#endif /* NVM_DEV_ERROR_DETECT == STD_ON */
	}
	else if((BlockId != 0U) && ((BlockId-1U) >= (NvM_BlockIdType)NVM_NUM_OF_BLOCK))
	{
#if (NVM_DEV_ERROR_DETECT == STD_ON)
		/* @req [SWS_NvM_00611] */
		NVM_DET_REPORT_ERROR(NVM_SID_GETERRORSTATUS,NVM_E_PARAM_BLOCK_ID);
#endif /* NVM_DEV_ERROR_DETECT == STD_ON */
	}
	else if(NULL_PTR == RequestResultPtr)
	{
#if (NVM_DEV_ERROR_DETECT == STD_ON)
		/* @req [SWS_NvM_00612] */
		NVM_DET_REPORT_ERROR(NVM_SID_GETERRORSTATUS,NVM_E_PARAM_DATA);
#endif /* NVM_DEV_ERROR_DETECT == STD_ON */
	}
	else
	{
		if(0U == BlockId)
		{
			(*RequestResultPtr) = NvM_MultiBlockRequestResult;
		}
		else
		{
			(*RequestResultPtr) = NvM_AdministrativeBlock[BlockId-1U].NvM_BlockRequestResult;
		}

		ret = (Std_ReturnType)E_OK;
	}

	return ret;
}
#endif /* NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_1 || \
		NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_2 || \
		NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3 */

#if (NVM_VERSION_INFO_API == STD_ON)
/**
 * @sid     0x0f
 * @brief   This service returns the version information of this module.
 * @details This  service is Non reentrant and returns the version information of this module.
 *          The version information includes:
 *          - Module Id
 *          - Vendor Id
 *          - Vendor specific version numbers
 *          If source code for caller and callee of this function is available this function should
 *          be realized as a macro. The macro should be defined in the modules header file.
 *
 * @param[out]    VersionInfo      Pointer to location to store version info
 *
 * @return void
 */
FUNC(void, NVM_CODE) NvM_GetVersionInfo
(
	P2VAR(Std_VersionInfoType, AUTOMATIC, NVM_APPL_VAR) versionInfo
)
{
	if(NULL_PTR == versionInfo)
	{
#if (NVM_DEV_ERROR_DETECT == STD_ON)
		/* @req [SWS_NvM_00613] */
		NVM_DET_REPORT_ERROR(NVM_SID_GETVERSIONINFO,NVM_E_PARAM_DATA);
#endif /* NVM_DEV_ERROR_DETECT == STD_ON */
	}
	else
	{
		versionInfo->vendorID = NVM_VENDOR_ID;
		versionInfo->moduleID = NVM_MODULE_ID;
		versionInfo->sw_major_version = NVM_SW_MAJOR_VERSION;
		versionInfo->sw_minor_version = NVM_SW_MINOR_VERSION;
		versionInfo->sw_patch_version = NVM_SW_PATCH_VERSION;
	}
}
#endif /* NVM_VERSION_INFO_API == STD_ON */

#if (\
	NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_1 || \
	NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_2 || \
	NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3 \
	)
/**
 * @sid            0x05
 * @brief          Service for setting the RAM block status of a permanent RAM block
 *
 * @param[in]      BlockId     The block identifier uniquely identifies one NVRAM block descriptor.
 *                             A NVRAM block descriptor contains all needed information about a
 *                             single NVRAM block
 *                 BlockChanged   TRUE: Validate the RAM block and mark block as changed.
 *                                FALSE: Invalidate the RAM block and mark block as unchanged
 *
 * @return         Std_ReturnType
 * @retval         E_OK      The status of the RAM-Block was changed as requested.
 * @retval         E_NOT_OK  An error occurred
 *
 */
FUNC(Std_ReturnType, NVM_CODE) NvM_SetRamBlockStatus
(
	VAR(NvM_BlockIdType, AUTOMATIC) BlockId,
	VAR(boolean, AUTOMATIC) BlockChanged
)
{
	VAR(Std_ReturnType, AUTOMATIC) ret = (Std_ReturnType)E_NOT_OK;
	P2CONST(NvM_BlockDescriptorType, NVM_VAR, NVM_APPL_CONST) pBlockDescriptor = \
			NvM_Config.NvM_BlockDescriptor;

	if((boolean)TRUE != NvM_InitDown)
	{
#if (NVM_DEV_ERROR_DETECT == STD_ON)
		/* @req [SWS_NvM_00643] */
		NVM_DET_REPORT_ERROR(NVM_SID_SETRAMBLOCKSTATUS,NVM_E_NOT_INITIALIZED);
#endif /* NVM_DEV_ERROR_DETECT == STD_ON */
	}
	else if((0U == BlockId) || ((BlockId-1U) >= (NvM_BlockIdType)NVM_NUM_OF_BLOCK))
	{
#if (NVM_DEV_ERROR_DETECT == STD_ON)
		/* @req [SWS_NvM_00645] */
		NVM_DET_REPORT_ERROR(NVM_SID_SETRAMBLOCKSTATUS,NVM_E_PARAM_BLOCK_ID);
#endif /* NVM_DEV_ERROR_DETECT == STD_ON */
	}
	else if(NVM_REQ_PENDING == NvM_AdministrativeBlock[BlockId-1U].NvM_BlockRequestResult)
	{
#if (NVM_DEV_ERROR_DETECT == STD_ON)
		/* @req [SWS_NvM_00644] */
		NVM_DET_REPORT_ERROR(NVM_SID_SETRAMBLOCKSTATUS,NVM_E_BLOCK_PENDING);
#endif /* NVM_DEV_ERROR_DETECT == STD_ON */
	}
	else if((boolean)TRUE == NvM_AdministrativeBlock[BlockId-1U].NvM_BlockLockStatus)
	{
#if (NVM_DEV_ERROR_DETECT == STD_ON)
		/* @req [SWS_NvM_00758] */
		NVM_DET_REPORT_ERROR(NVM_SID_SETRAMBLOCKSTATUS,NVM_E_BLOCK_LOCKED);
#endif /* NVM_DEV_ERROR_DETECT == STD_ON */
	}
	else if((boolean)FALSE == NVM_IS_USE_SET_RAM_BLOCK_STATUS(pBlockDescriptor,BlockId-1U))
	{
#if (NVM_DEV_ERROR_DETECT == STD_ON)
		/* @req [SWS_NvM_00590] */
		NVM_DET_REPORT_ERROR(NVM_SID_SETRAMBLOCKSTATUS,NVM_E_BLOCK_CONFIG);
#endif /* NVM_DEV_ERROR_DETECT == STD_ON */
	}
	else
	{
		/* @req [SWS_NvM_00240] */
		if(NULL_PTR != NVM_GET_RAM_BLOCK_ADDRESS(pBlockDescriptor,BlockId-1U))
		{
			ret = (Std_ReturnType)E_OK;
			if((boolean)TRUE == BlockChanged)
			{
				NvM_AdministrativeBlock[BlockId-1U].NvM_BlockState = NVM_BLOCK_VALID_CHANGED;
			}
			else
			{
				NvM_AdministrativeBlock[BlockId-1U].NvM_BlockState = NVM_BLOCK_INVALID_UNCHANGED;
			}
		}
		else
		{
			/* Do nothing */
		}
	}

	return ret;
}
#endif /* NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_1 || \
		NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_2 || \
		NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3 */

#if (\
	NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_1 || \
	NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_2 || \
	NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3 \
	)
/**
 * @sid            0x13
 * @brief          Service for setting the RAM block status of an NVRAM block
 *
 * @param[in]      BlockId     The block identifier uniquely identifies one NVRAM block descriptor.
 *                             A NVRAM block descriptor contains all needed information about a
 *                             single NVRAM block
 *                 BlockChanged   TRUE: Validate the RAM block and mark block as changed.
 *                                FALSE: Invalidate the RAM block and mark block as unchanged
 *
 */
FUNC(void, NVM_CODE) NvM_SetBlockLockStatus
(
	VAR(NvM_BlockIdType, AUTOMATIC) BlockId,
	VAR(boolean, AUTOMATIC) BlockLocked
)
{
	P2CONST(NvM_BlockDescriptorType, NVM_VAR, NVM_APPL_CONST) pBlockDescriptor = \
			NvM_Config.NvM_BlockDescriptor;

	if((boolean)TRUE != NvM_InitDown)
	{
#if (NVM_DEV_ERROR_DETECT == STD_ON)
		/* @req [SWS_NvM_00728] */
		NVM_DET_REPORT_ERROR(NVM_SID_SETBLOCKLOCKSTATUS,NVM_E_NOT_INITIALIZED);
#endif /* NVM_DEV_ERROR_DETECT == STD_ON */
	}
	else if((0U == BlockId) || ((BlockId-1U) >= (NvM_BlockIdType)NVM_NUM_OF_BLOCK))
	{
#if (NVM_DEV_ERROR_DETECT == STD_ON)
		/* @req [SWS_NvM_00731] */
		NVM_DET_REPORT_ERROR(NVM_SID_SETBLOCKLOCKSTATUS,NVM_E_PARAM_BLOCK_ID);
#endif /* NVM_DEV_ERROR_DETECT == STD_ON */
	}
	else if(NVM_REQ_PENDING == NvM_AdministrativeBlock[BlockId-1U].NvM_BlockRequestResult)
	{
#if (NVM_DEV_ERROR_DETECT == STD_ON)
		/* @req [SWS_NvM_00729] */
		NVM_DET_REPORT_ERROR(NVM_SID_SETBLOCKLOCKSTATUS,NVM_E_BLOCK_PENDING);
#endif /* NVM_DEV_ERROR_DETECT == STD_ON */
	}
	else if((boolean)TRUE == NVM_IS_WRITE_ONCE(pBlockDescriptor,BlockId-1U))
	{
#if (NVM_DEV_ERROR_DETECT == STD_ON)
		/* @req [SWS_NvM_00730] */
		NVM_DET_REPORT_ERROR(NVM_SID_SETBLOCKLOCKSTATUS,NVM_E_BLOCK_CONFIG);
#endif /* NVM_DEV_ERROR_DETECT == STD_ON */
	}
	else
	{
		/* @req [SWS_NvM_00732] */
		if((NULL_PTR != NVM_GET_RAM_BLOCK_ADDRESS(pBlockDescriptor,BlockId-1U)) || \
				((boolean)TRUE == NVM_USE_SYNC_MECHANISM(pBlockDescriptor,BlockId-1U)))
		{
			NvM_AdministrativeBlock[BlockId-1U].NvM_BlockLockStatus = BlockLocked;
		}
		else
		{
			/* Do nothing */
		}
	}
}
#endif /* NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_1 || \
		NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_2 || \
		NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3 */

#if (\
	NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_2 || \
	NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3 \
	)
/**
 * @sid            0x10
 * @brief          Service for getting the currently set DataIndex of a dataset NVRAM block
 *
 * @param[in]      BlockId    The block identifier uniquely identifies one NVRAM block descriptor.
 *                             A NVRAM block descriptor contains all needed information about a
 *                             single NVRAM block
 *
 * @return         Std_ReturnType
 * @retval         E_OK      The job was successfully removed from queue
 * @retval         E_NOT_OK   The job could not be found in the queue.
 *
 */
FUNC(Std_ReturnType, NVM_CODE) NvM_CancelJobs(VAR(NvM_BlockIdType, AUTOMATIC) BlockId)
{
	VAR(Std_ReturnType, AUTOMATIC) ret = (Std_ReturnType)E_NOT_OK;
	P2CONST(NvM_BlockDescriptorType, NVM_VAR, NVM_APPL_CONST) pBlockDescriptor = \
			NvM_Config.NvM_BlockDescriptor;

	if((boolean)TRUE != NvM_InitDown)
	{
#if (NVM_DEV_ERROR_DETECT == STD_ON)
		/* @req [SWS_NvM_00648] */
		NVM_DET_REPORT_ERROR(NVM_SID_CANCELJOBS,NVM_E_NOT_INITIALIZED);
#endif /* NVM_DEV_ERROR_DETECT == STD_ON */
	}
	else if((0U == BlockId) || ((BlockId-1U) >= NVM_NUM_OF_BLOCK))
	{
#if (NVM_DEV_ERROR_DETECT == STD_ON)
		/* @req [SWS_NvM_00649] */
		NVM_DET_REPORT_ERROR(NVM_SID_CANCELJOBS,NVM_E_PARAM_BLOCK_ID);
#endif /* NVM_DEV_ERROR_DETECT == STD_ON */
	}
	else
	{
#if (NVM_JOB_PRIORITIZATION == STD_ON)
		NvM_CancelJobInQueue(&NvM_ImmediateJobScheduling,BlockId);
#endif /* NVM_JOB_PRIORITIZATION == STD_ON */
		NvM_CancelJobInQueue(&NvM_StandardJobScheduling,BlockId);

		if((boolean)TRUE == NVM_IS_NOTIFY_BSWM(pBlockDescriptor, BlockId-1U))
		{
#if (NVM_BSWM_BLOCKSTATUS_INFORMATION == STD_ON)
			BswM_NvM_CurrentBlockMode(BlockId, \
					NvM_AdministrativeBlock[BlockId-1U].NvM_BlockRequestResult);
#endif /* (NVM_BSWM_BLOCKSTATUS_INFORMATION == STD_ON) */
		}

		ret = (Std_ReturnType)E_OK;
	}
	return ret;
}
#endif /* NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_2 || \
		NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3 */

#if (NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3)
/**
 * @sid            0x09
 * @brief          Service to erase a NV block
 *
 * @param[in]      BlockId    The block identifier uniquely identifies one NVRAM block descriptor.
 *                             A NVRAM block descriptor contains all needed information about a
 *                             single NVRAM block
 *
 * @return         Std_ReturnType
 * @retval         E_OK       request has been accepted
 * @retval         E_NOT_OK   request has not been accepted
 *
 */
FUNC(Std_ReturnType, NVM_CODE) NvM_EraseNvBlock(VAR(NvM_BlockIdType, AUTOMATIC) BlockId)
{
	VAR(Std_ReturnType, AUTOMATIC) ret = (Std_ReturnType)E_NOT_OK;
	P2CONST(NvM_BlockDescriptorType, NVM_VAR, NVM_APPL_CONST) pBlockDescriptor = \
			NvM_Config.NvM_BlockDescriptor;
	P2VAR(NvM_JobSchedulingType, NVM_VAR, NVM_APPL_CONST) pJobScheduling = NULL_PTR;
	P2VAR(NvM_JobQueueType, AUTOMATIC, NVM_VAR) pJobQueue = NULL_PTR;

	if((boolean)TRUE != NvM_InitDown)
	{
#if (NVM_DEV_ERROR_DETECT == STD_ON)
		/* @req [SWS_NvM_00631] */
		NVM_DET_REPORT_ERROR(NVM_SID_ERASENVBLOCK,NVM_E_NOT_INITIALIZED);
#endif /* NVM_DEV_ERROR_DETECT == STD_ON */
	}
	else if((0U == BlockId) || ((BlockId-1U) >= NVM_NUM_OF_BLOCK))
	{
#if (NVM_DEV_ERROR_DETECT == STD_ON)
		/* @req [SWS_NvM_00635] */
		NVM_DET_REPORT_ERROR(NVM_SID_ERASENVBLOCK,NVM_E_PARAM_BLOCK_ID);
#endif /* NVM_DEV_ERROR_DETECT == STD_ON */
	}
	else if(NVM_REQ_PENDING == NvM_AdministrativeBlock[BlockId-1U].NvM_BlockRequestResult)
	{
#if (NVM_DEV_ERROR_DETECT == STD_ON)
		/* @req [SWS_NvM_00632] */
		NVM_DET_REPORT_ERROR(NVM_SID_ERASENVBLOCK,NVM_E_BLOCK_PENDING);
#endif /* NVM_DEV_ERROR_DETECT == STD_ON */
	}
	else if(0U != NVM_GET_BLOCK_JOB_PRIORITY(pBlockDescriptor,BlockId-1U))
	{
#if (NVM_DEV_ERROR_DETECT == STD_ON)
		/* @req [SWS_NvM_00636] */
		NVM_DET_REPORT_ERROR(NVM_SID_ERASENVBLOCK,NVM_E_BLOCK_CONFIG);
#endif /* NVM_DEV_ERROR_DETECT == STD_ON */
	}
	else if((boolean)TRUE == NvM_AdministrativeBlock[BlockId-1U].NvM_BlockLockStatus)
	{
#if (NVM_DEV_ERROR_DETECT == STD_ON)
		/* @req [SWS_NvM_00757] */
		NVM_DET_REPORT_ERROR(NVM_SID_ERASENVBLOCK,NVM_E_BLOCK_LOCKED);
#endif /* NVM_DEV_ERROR_DETECT == STD_ON */
	}
	else if(((boolean)TRUE == NvM_AdministrativeBlock[BlockId-1U].NvM_BlockProtection) || \
			((NVM_BLOCK_DATASET == NVM_GET_BLOCK_MANAGEMENT_TYPE(pBlockDescriptor,BlockId-1U)) && \
					(NvM_AdministrativeBlock[BlockId-1U].NvM_BlockIndex >= \
					NVM_GET_NV_BLOCK_NUMBER(pBlockDescriptor,BlockId-1U))))
	{
		/* Write-protected returns E_NOT_OK */
#if (STD_ON == NVM_E_WRITE_PROTECTED_SWITCH)
		/* @req [SWS_NvM_00411] */
		Dem_ReportErrorStatus(NVM_E_WRITE_PROTECTED, DEM_EVENT_STATUS_FAILED);
#endif /* STD_ON == NVM_E_WRITE_PROTECTED_SWITCH */
	}
	else
	{
		if((Std_ReturnType)E_OK == NvM_GetJobQueueAndIndex(
				NVM_GET_BLOCK_JOB_PRIORITY(pBlockDescriptor,BlockId-1U),
				&pJobScheduling,&pJobQueue,NVM_SID_ERASENVBLOCK))
		{
			NvM_SetJobQueue(NVM_GET_BLOCK_JOB_PRIORITY(pBlockDescriptor,BlockId-1U),BlockId,
				NVM_ERASE_NV_BLOCK,pJobScheduling,pJobQueue);
			if((boolean)TRUE == NVM_IS_NOTIFY_BSWM(pBlockDescriptor, BlockId-1U))
			{
#if (NVM_BSWM_BLOCKSTATUS_INFORMATION == STD_ON)
				BswM_NvM_CurrentBlockMode(BlockId, \
						NvM_AdministrativeBlock[BlockId-1U].NvM_BlockRequestResult);
#endif /* (NVM_BSWM_BLOCKSTATUS_INFORMATION == STD_ON) */
			}
			ret = (Std_ReturnType)E_OK;
		}
	}

	return ret;
}
#endif /* NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3 */

#if (\
	NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_2 || \
	NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3 \
	)
/**
 * @sid            0x06
 * @brief          Service to copy the data of the NV block to its corresponding RAM block
 *
 * @param[in]      BlockId     The block identifier uniquely identifies one NVRAM block descriptor.
 *                             A NVRAM block descriptor contains all needed information about a
 *                             single NVRAM block
 * @param[out]     NvM_DstPtr  Pointer to the RAM data block.
 * @return         Std_ReturnType
 * @retval         E_OK       request has been accepted
 * @retval         E_NOT_OK   request has not been accepted
 *
 */
FUNC(Std_ReturnType, NVM_CODE) NvM_ReadBlock
(
	VAR(NvM_BlockIdType, AUTOMATIC) BlockId,
	P2VAR(void, AUTOMATIC, NVM_APPL_VAR) NvM_DstPtr
)
{
	VAR(Std_ReturnType, AUTOMATIC) ret = (Std_ReturnType)E_NOT_OK;
	P2CONST(NvM_BlockDescriptorType, NVM_VAR, NVM_APPL_CONST) pBlockDescriptor = \
			NvM_Config.NvM_BlockDescriptor;
	P2VAR(NvM_JobSchedulingType, NVM_VAR, NVM_APPL_CONST) pJobScheduling = NULL_PTR;
	P2VAR(NvM_JobQueueType, AUTOMATIC, NVM_VAR) pJobQueue = NULL_PTR;

	if((boolean)TRUE != NvM_InitDown)
	{
#if (NVM_DEV_ERROR_DETECT == STD_ON)
		/* @req [SWS_NvM_00614] */
		NVM_DET_REPORT_ERROR(NVM_SID_READBLOCK,NVM_E_NOT_INITIALIZED);
#endif /* NVM_DEV_ERROR_DETECT == STD_ON */
	}
	else if((0U == BlockId) || ((BlockId-1U) >= NVM_NUM_OF_BLOCK))
	{
#if (NVM_DEV_ERROR_DETECT == STD_ON)
		/* @req [SWS_NvM_00618] */
		NVM_DET_REPORT_ERROR(NVM_SID_READBLOCK,NVM_E_PARAM_BLOCK_ID);
#endif /* NVM_DEV_ERROR_DETECT == STD_ON */
	}
	else if(NVM_REQ_PENDING == NvM_AdministrativeBlock[BlockId-1U].NvM_BlockRequestResult)
	{
#if (NVM_DEV_ERROR_DETECT == STD_ON)
		/* @req [SWS_NvM_00615] */
		NVM_DET_REPORT_ERROR(NVM_SID_READBLOCK,NVM_E_BLOCK_PENDING);
#endif /* NVM_DEV_ERROR_DETECT == STD_ON */
	}
	else if(((boolean)FALSE == NVM_USE_SYNC_MECHANISM(pBlockDescriptor,BlockId-1U)) &&
		(NULL_PTR == NVM_GET_RAM_BLOCK_ADDRESS(pBlockDescriptor,BlockId-1U)) &&
		(NULL_PTR == NvM_DstPtr))
	{
#if (NVM_DEV_ERROR_DETECT == STD_ON)
		/* @req [SWS_NvM_00616] */
		NVM_DET_REPORT_ERROR(NVM_SID_READBLOCK,NVM_E_PARAM_ADDRESS);
#endif /* NVM_DEV_ERROR_DETECT == STD_ON */
	}
	else
	{
		if((Std_ReturnType)E_OK == NvM_GetJobQueueAndIndex(
					NVM_GET_BLOCK_JOB_PRIORITY(pBlockDescriptor,BlockId-1U),&pJobScheduling,
					&pJobQueue,NVM_SID_READBLOCK))
		{
			NvM_SetJobQueue(NVM_GET_BLOCK_JOB_PRIORITY(pBlockDescriptor,BlockId-1U),BlockId,
				NVM_READ_BLOCK,pJobScheduling,pJobQueue);

#if (STD_ON == NVM_USE_MIRROR_MECHANISM)
			if((boolean)TRUE == NVM_USE_SYNC_MECHANISM(pBlockDescriptor,BlockId-1U))
			{
				NvM_AdministrativeBlock[BlockId-1U].NvM_RAMAddress = &NvM_MirrorBlock[0];
			} else
#endif /* STD_ON == NVM_USE_MIRROR_MECHANISM */
			/* @req [SWS_NvM_00278] */
			if(NULL_PTR != NvM_DstPtr)
			{
				/* PRQA S 0316 EOF # There is no problem with the entry */
				NvM_AdministrativeBlock[BlockId-1U].NvM_RAMAddress = (uint8*)NvM_DstPtr;
			}
			else
			{
				NvM_AdministrativeBlock[BlockId-1U].NvM_RAMAddress = \
						NVM_GET_RAM_BLOCK_ADDRESS(pBlockDescriptor,BlockId-1U);
			}

			/* @req [SWS_NvM_00198] */
			NvM_AdministrativeBlock[BlockId-1U].NvM_BlockState = NVM_BLOCK_INVALID_UNCHANGED;
			if((boolean)TRUE == NVM_IS_NOTIFY_BSWM(pBlockDescriptor, BlockId-1U))
			{
#if (NVM_BSWM_BLOCKSTATUS_INFORMATION == STD_ON)
				BswM_NvM_CurrentBlockMode(BlockId, \
						NvM_AdministrativeBlock[BlockId-1U].NvM_BlockRequestResult);
#endif /* (NVM_BSWM_BLOCKSTATUS_INFORMATION == STD_ON) */
			}
			ret = (Std_ReturnType)E_OK;
		}
	}

	return ret;
}
#endif /* NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_2 || \
		NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3 */

#if (\
	NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_2 || \
	NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3 \
	)
/**
 * @sid            0x16
 * @brief          Service to copy the data of the NV block to its corresponding permanent RAM block
 *
 * @param[in]      BlockId     The block identifier uniquely identifies one NVRAM block descriptor.
 *                             A NVRAM block descriptor contains all needed information about a
 *                             single NVRAM block
 * @return         Std_ReturnType
 * @retval         E_OK       request has been accepted
 * @retval         E_NOT_OK   request has not been accepted
 *
 */
FUNC(Std_ReturnType, NVM_CODE) NvM_ReadPRAMBlock(VAR(NvM_BlockIdType, AUTOMATIC) BlockId)
{
	VAR(Std_ReturnType, AUTOMATIC) ret = (Std_ReturnType)E_NOT_OK;
	P2CONST(NvM_BlockDescriptorType, NVM_VAR, NVM_APPL_CONST) pBlockDescriptor = \
				NvM_Config.NvM_BlockDescriptor;
	P2VAR(NvM_JobSchedulingType, NVM_VAR, NVM_APPL_CONST) pJobScheduling = NULL_PTR;
	P2VAR(NvM_JobQueueType, AUTOMATIC, NVM_VAR) pJobQueue = NULL_PTR;

	if((boolean)TRUE != NvM_InitDown)
	{
#if (NVM_DEV_ERROR_DETECT == STD_ON)
		/* @req [SWS_NvM_00823] */
		NVM_DET_REPORT_ERROR(NVM_SID_READPRAMBLOCK,NVM_E_NOT_INITIALIZED);
#endif /* NVM_DEV_ERROR_DETECT == STD_ON */
	}
	else if((0U == BlockId) || ((BlockId-1U) >= NVM_NUM_OF_BLOCK))
	{
#if (NVM_DEV_ERROR_DETECT == STD_ON)
		/* @req [SWS_NvM_00826] */
		NVM_DET_REPORT_ERROR(NVM_SID_READPRAMBLOCK,NVM_E_PARAM_BLOCK_ID);
#endif /* NVM_DEV_ERROR_DETECT == STD_ON */
	}
	else if(NVM_REQ_PENDING == NvM_AdministrativeBlock[BlockId-1U].NvM_BlockRequestResult)
	{
#if (NVM_DEV_ERROR_DETECT == STD_ON)
		/* @req [SWS_NvM_00824] */
		NVM_DET_REPORT_ERROR(NVM_SID_READPRAMBLOCK,NVM_E_BLOCK_PENDING);
#endif /* NVM_DEV_ERROR_DETECT == STD_ON */
	}
	else if(NULL_PTR == NVM_GET_RAM_BLOCK_ADDRESS(pBlockDescriptor,BlockId-1U))
	{
#if (NVM_DEV_ERROR_DETECT == STD_ON)
		/* @req [SWS_NvM_00825] */
		NVM_DET_REPORT_ERROR(NVM_SID_READPRAMBLOCK,NVM_E_PARAM_ADDRESS);
#endif /* NVM_DEV_ERROR_DETECT == STD_ON */
	}
	else
	{
		if((Std_ReturnType)E_OK == NvM_GetJobQueueAndIndex(
					NVM_GET_BLOCK_JOB_PRIORITY(pBlockDescriptor,BlockId-1U),&pJobScheduling,
					&pJobQueue,NVM_SID_READPRAMBLOCK))
		{
			NvM_SetJobQueue(NVM_GET_BLOCK_JOB_PRIORITY(pBlockDescriptor,BlockId-1U),BlockId,
				NVM_READ_PRAM_BLOCK,pJobScheduling,pJobQueue);

#if (STD_ON == NVM_USE_MIRROR_MECHANISM)
			if((boolean)TRUE == NVM_USE_SYNC_MECHANISM(pBlockDescriptor,BlockId-1U))
			{
				NvM_AdministrativeBlock[BlockId-1U].NvM_RAMAddress = &NvM_MirrorBlock[0];
			}
			else
#endif /* STD_ON == NVM_USE_MIRROR_MECHANISM */
			{
				NvM_AdministrativeBlock[BlockId-1U].NvM_RAMAddress = \
						NVM_GET_RAM_BLOCK_ADDRESS(pBlockDescriptor,BlockId-1U);
			}

			/* @req [SWS_NvM_00198] */
			NvM_AdministrativeBlock[BlockId-1U].NvM_BlockState = NVM_BLOCK_INVALID_UNCHANGED;

			if((boolean)TRUE == NVM_IS_NOTIFY_BSWM(pBlockDescriptor, BlockId-1U))
			{
#if (NVM_BSWM_BLOCKSTATUS_INFORMATION == STD_ON)
				BswM_NvM_CurrentBlockMode(BlockId, \
						NvM_AdministrativeBlock[BlockId-1U].NvM_BlockRequestResult);
#endif /* (NVM_BSWM_BLOCKSTATUS_INFORMATION == STD_ON) */
			}
			ret = (Std_ReturnType)E_OK;
		}
	}

	return ret;
}
#endif /* NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_2 || \
		NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3 */

#if (\
	NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_2 || \
	NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3 \
	)
/**
 * @sid            0x07
 * @brief          Service to copy the data of the RAM block to its corresponding NV block.
 *
 * @param[in]      BlockId     The block identifier uniquely identifies one NVRAM block descriptor.
 *                             A NVRAM block descriptor contains all needed information about a
 *                             single NVRAM block
 *                 NvM_SrcPtr  Pointer to the RAM data block.
 * @return         Std_ReturnType
 * @retval         E_OK       request has been accepted
 * @retval         E_NOT_OK   request has not been accepted
 *
 */
FUNC(Std_ReturnType, NVM_CODE) NvM_WriteBlock
(
	VAR(NvM_BlockIdType, AUTOMATIC) BlockId,
	P2CONST(void, AUTOMATIC, NVM_APPL_CONST) NvM_SrcPtr
)
{
	VAR(Std_ReturnType, AUTOMATIC) ret = (Std_ReturnType)E_NOT_OK;
	P2CONST(NvM_BlockDescriptorType, NVM_VAR, NVM_APPL_CONST) pBlockDescriptor = \
				NvM_Config.NvM_BlockDescriptor;
	P2VAR(NvM_JobSchedulingType, NVM_VAR, NVM_APPL_CONST) pJobScheduling = NULL_PTR;
	P2VAR(NvM_JobQueueType, AUTOMATIC, NVM_VAR) pJobQueue = NULL_PTR;

	if((boolean)TRUE != NvM_InitDown)
	{
#if (NVM_DEV_ERROR_DETECT == STD_ON)
		/* @req [SWS_NvM_00619] */
		NVM_DET_REPORT_ERROR(NVM_SID_WRITEBLOCK,NVM_E_NOT_INITIALIZED);
#endif /* NVM_DEV_ERROR_DETECT == STD_ON */
	}
	else if((0U == BlockId) ||(( BlockId-1U) >= NVM_NUM_OF_BLOCK))
	{
#if (NVM_DEV_ERROR_DETECT == STD_ON)
		/* @req [SWS_NvM_00624] */
		NVM_DET_REPORT_ERROR(NVM_SID_WRITEBLOCK,NVM_E_PARAM_BLOCK_ID);
#endif /* NVM_DEV_ERROR_DETECT == STD_ON */
	}
	else if(NVM_REQ_PENDING == NvM_AdministrativeBlock[BlockId-1U].NvM_BlockRequestResult)
	{
#if (NVM_DEV_ERROR_DETECT == STD_ON)
		/* @req [SWS_NvM_00620] */
		NVM_DET_REPORT_ERROR(NVM_SID_WRITEBLOCK,NVM_E_BLOCK_PENDING);
#endif /* NVM_DEV_ERROR_DETECT == STD_ON */
	}
	else if(((boolean)FALSE == NVM_USE_SYNC_MECHANISM(pBlockDescriptor,BlockId-1U)) &&
		(NULL_PTR == NVM_GET_RAM_BLOCK_ADDRESS(pBlockDescriptor,BlockId-1U)) && (NULL_PTR == NvM_SrcPtr))
	{
#if (NVM_DEV_ERROR_DETECT == STD_ON)
		/* @req [SWS_NvM_00622] */
		NVM_DET_REPORT_ERROR(NVM_SID_WRITEBLOCK,NVM_E_PARAM_ADDRESS);
#endif /* NVM_DEV_ERROR_DETECT == STD_ON */
	}
	else if(((boolean)TRUE == NvM_AdministrativeBlock[BlockId-1U].NvM_BlockProtection) || \
			((NVM_BLOCK_DATASET == NVM_GET_BLOCK_MANAGEMENT_TYPE(pBlockDescriptor,BlockId-1U)) && \
					(NvM_AdministrativeBlock[BlockId-1U].NvM_BlockIndex >= \
					NVM_GET_NV_BLOCK_NUMBER(pBlockDescriptor,BlockId-1U))))
	{
#if (STD_ON == NVM_E_WRITE_PROTECTED_SWITCH)
		/* @req [SWS_NvM_00411] */
		Dem_ReportErrorStatus(NVM_E_WRITE_PROTECTED, DEM_EVENT_STATUS_FAILED);
#endif /* STD_ON == NVM_E_WRITE_PROTECTED_SWITCH */
	}
	else if((boolean)TRUE == NvM_AdministrativeBlock[BlockId-1U].NvM_BlockLockStatus)
	{
#if (NVM_DEV_ERROR_DETECT == STD_ON)
		/* @req [SWS_NvM_00749] */
		NVM_DET_REPORT_ERROR(NVM_SID_WRITEBLOCK,NVM_E_BLOCK_LOCKED);
#endif /* NVM_DEV_ERROR_DETECT == STD_ON */
	}
	else if(((boolean)FALSE == NVM_IS_DYNAMIC_CONFIGURATION()) && (1U == BlockId))
	{
#if (NVM_DEV_ERROR_DETECT == STD_ON)
		/* @req [SWS_NvM_00311] */
		NVM_DET_REPORT_ERROR(NVM_SID_WRITEBLOCK,NVM_E_BLOCK_CONFIG);
#endif /* NVM_DEV_ERROR_DETECT == STD_ON */
	}
	else
	{
		if((Std_ReturnType)E_OK == NvM_GetJobQueueAndIndex(
					NVM_GET_BLOCK_JOB_PRIORITY(pBlockDescriptor,BlockId-1U),&pJobScheduling,
					&pJobQueue,NVM_SID_WRITEBLOCK))
		{
			NvM_SetJobQueue(NVM_GET_BLOCK_JOB_PRIORITY(pBlockDescriptor,BlockId-1U),BlockId,
				NVM_WRITE_BLOCK,pJobScheduling,pJobQueue);

#if (STD_ON == NVM_USE_MIRROR_MECHANISM)
			if((boolean)TRUE == NVM_USE_SYNC_MECHANISM(pBlockDescriptor,BlockId-1U))
			{
				NvM_AdministrativeBlock[BlockId-1U].NvM_RAMAddress = &NvM_MirrorBlock[0];
			}
			else
#endif /* STD_ON == NVM_USE_MIRROR_MECHANISM */
			/* @req [SWS_NvM_00210] */
			if(NULL_PTR != NvM_SrcPtr)
			{
				NvM_AdministrativeBlock[BlockId-1U].NvM_RAMAddress = (uint8*)NvM_SrcPtr;
			}
			else
			{
				NvM_AdministrativeBlock[BlockId-1U].NvM_RAMAddress = \
						NVM_GET_RAM_BLOCK_ADDRESS(pBlockDescriptor,BlockId-1U);
				/* @req [SWS_NvM_00303] */
				NvM_AdministrativeBlock[BlockId-1U].NvM_BlockState = NVM_BLOCK_VALID_CHANGED;
			}

			if((boolean)TRUE == NVM_IS_NOTIFY_BSWM(pBlockDescriptor, BlockId-1U))
			{
#if (NVM_BSWM_BLOCKSTATUS_INFORMATION == STD_ON)
				BswM_NvM_CurrentBlockMode(BlockId, \
						NvM_AdministrativeBlock[BlockId-1U].NvM_BlockRequestResult);
#endif /* (NVM_BSWM_BLOCKSTATUS_INFORMATION == STD_ON) */
			}
			ret = (Std_ReturnType)E_OK;
		}
		else
		{
			/* Do nothing */
		}
	}

	return ret;
}
#endif /* NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_2 || \
		NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3 */

#if (\
	NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_2 || \
	NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3 \
	)
/**
 * @sid            0x17
 * @brief          Service to copy the data of the RAM block to its corresponding permanent RAM block
 *
 * @param[in]      BlockId     The block identifier uniquely identifies one NVRAM block descriptor.
 *                             A NVRAM block descriptor contains all needed information about a
 *                             single NVRAM block
 * @return         Std_ReturnType
 * @retval         E_OK       request has been accepted
 * @retval         E_NOT_OK   request has not been accepted
 *
 */
FUNC(Std_ReturnType, NVM_CODE) NvM_WritePRAMBlock(VAR(NvM_BlockIdType, AUTOMATIC) BlockId)
{
	VAR(Std_ReturnType, AUTOMATIC) ret = (Std_ReturnType)E_NOT_OK;
	P2CONST(NvM_BlockDescriptorType, NVM_VAR, NVM_APPL_CONST) pBlockDescriptor = \
				NvM_Config.NvM_BlockDescriptor;
	P2VAR(NvM_JobSchedulingType, NVM_VAR, NVM_APPL_CONST) pJobScheduling = NULL_PTR;
	P2VAR(NvM_JobQueueType, AUTOMATIC, NVM_VAR) pJobQueue = NULL_PTR;

	if((boolean)TRUE != NvM_InitDown)
	{
#if (NVM_DEV_ERROR_DETECT == STD_ON)
		/* @req [SWS_NvM_00827] */
		NVM_DET_REPORT_ERROR(NVM_SID_WRITEPRAMBLOCK,NVM_E_NOT_INITIALIZED);
#endif /* NVM_DEV_ERROR_DETECT == STD_ON */
	}
	else if((0U == BlockId) || ((BlockId-1U) >= NVM_NUM_OF_BLOCK))
	{
#if (NVM_DEV_ERROR_DETECT == STD_ON)
		/* @req [SWS_NvM_00829] */
		NVM_DET_REPORT_ERROR(NVM_SID_WRITEPRAMBLOCK,NVM_E_PARAM_BLOCK_ID);
#endif /* NVM_DEV_ERROR_DETECT == STD_ON */
	}
	else if(NVM_REQ_PENDING == NvM_AdministrativeBlock[BlockId-1U].NvM_BlockRequestResult)
	{
#if (NVM_DEV_ERROR_DETECT == STD_ON)
		/* @req [SWS_NvM_00828] */
		NVM_DET_REPORT_ERROR(NVM_SID_WRITEPRAMBLOCK,NVM_E_BLOCK_PENDING);
#endif /* NVM_DEV_ERROR_DETECT == STD_ON */
	}
	else if(NULL_PTR == NVM_GET_RAM_BLOCK_ADDRESS(pBlockDescriptor,BlockId-1U))
	{
#if (NVM_DEV_ERROR_DETECT == STD_ON)
		NVM_DET_REPORT_ERROR(NVM_SID_WRITEPRAMBLOCK,NVM_E_PARAM_ADDRESS);
#endif /* NVM_DEV_ERROR_DETECT == STD_ON */
	}
	else if(((boolean)TRUE == NvM_AdministrativeBlock[BlockId-1U].NvM_BlockProtection) || \
			((NVM_BLOCK_DATASET == NVM_GET_BLOCK_MANAGEMENT_TYPE(pBlockDescriptor,BlockId-1U)) && \
					(NvM_AdministrativeBlock[BlockId-1U].NvM_BlockIndex >= \
					NVM_GET_NV_BLOCK_NUMBER(pBlockDescriptor,BlockId-1U))))
	{
#if (STD_ON == NVM_E_WRITE_PROTECTED_SWITCH)
		/* @req [SWS_NvM_00795] */
		Dem_ReportErrorStatus(NVM_E_WRITE_PROTECTED, DEM_EVENT_STATUS_FAILED);
#endif /* STD_ON == NVM_E_WRITE_PROTECTED_SWITCH */
	}
	else if((boolean)TRUE == NvM_AdministrativeBlock[BlockId-1U].NvM_BlockLockStatus)
	{
#if (NVM_DEV_ERROR_DETECT == STD_ON)
		/* @req [SWS_NvM_00748] [SWS_NvM_00830] */
		NVM_DET_REPORT_ERROR(NVM_SID_WRITEPRAMBLOCK,NVM_E_BLOCK_LOCKED);
#endif /* NVM_DEV_ERROR_DETECT == STD_ON */
	}
	else if(((boolean)FALSE == NVM_IS_DYNAMIC_CONFIGURATION()) && (1U == BlockId))
	{
#if (NVM_DEV_ERROR_DETECT == STD_ON)
		/* @req [SWS_NvM_00311] */
		NVM_DET_REPORT_ERROR(NVM_SID_WRITEPRAMBLOCK,NVM_E_BLOCK_CONFIG);
#endif /* NVM_DEV_ERROR_DETECT == STD_ON */
	}
	else
	{
		if((Std_ReturnType)E_OK == NvM_GetJobQueueAndIndex(
					NVM_GET_BLOCK_JOB_PRIORITY(pBlockDescriptor,BlockId-1U),&pJobScheduling,
					&pJobQueue,NVM_SID_WRITEPRAMBLOCK))
		{
			NvM_SetJobQueue(NVM_GET_BLOCK_JOB_PRIORITY(pBlockDescriptor,BlockId-1U),BlockId,
				NVM_WRITE_PRAM_BLOCK,pJobScheduling,pJobQueue);

#if (STD_ON == NVM_USE_MIRROR_MECHANISM)
			if((boolean)TRUE == NVM_USE_SYNC_MECHANISM(pBlockDescriptor,BlockId-1U))
			{
				NvM_AdministrativeBlock[BlockId-1U].NvM_RAMAddress = &NvM_MirrorBlock[0];
			}
			else
#endif /* STD_ON == NVM_USE_MIRROR_MECHANISM */
			{
				NvM_AdministrativeBlock[BlockId-1U].NvM_RAMAddress = \
						NVM_GET_RAM_BLOCK_ADDRESS(pBlockDescriptor,BlockId-1U);
			}

			/* @req [SWS_NvM_00803] */
			NvM_AdministrativeBlock[BlockId-1U].NvM_BlockState = NVM_BLOCK_VALID_CHANGED;

			if((boolean)TRUE == NVM_IS_NOTIFY_BSWM(pBlockDescriptor, BlockId-1U))
			{
#if (NVM_BSWM_BLOCKSTATUS_INFORMATION == STD_ON)
				BswM_NvM_CurrentBlockMode(BlockId, \
						NvM_AdministrativeBlock[BlockId-1U].NvM_BlockRequestResult);
#endif /* (NVM_BSWM_BLOCKSTATUS_INFORMATION == STD_ON) */
			}
			ret = (Std_ReturnType)E_OK;
		}
		else
		{
			/* Do nothing */
		}
	}

	return ret;
}
#endif /* NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_2 || \
		NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3 */

#if (\
	NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_2 || \
	NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3 \
	)
/**
 * @sid            0x08
 * @brief          Service to restore the default data to its corresponding RAM block.
 *
 * @param[in]      BlockId     The block identifier uniquely identifies one NVRAM block descriptor.
 *                             A NVRAM block descriptor contains all needed information about a
 *                             single NVRAM block
 * @param[out]     NvM_DestPtr  Pointer to the RAM data block.
 * @return         Std_ReturnType
 * @retval         E_OK       request has been accepted
 * @retval         E_NOT_OK   request has not been accepted
 *
 */
FUNC(Std_ReturnType, NVM_CODE) NvM_RestoreBlockDefaults
(
	VAR(NvM_BlockIdType, AUTOMATIC) BlockId,
	P2VAR(void, AUTOMATIC, NVM_APPL_VAR) NvM_DestPtr
)
{
	VAR(Std_ReturnType, AUTOMATIC) ret = (Std_ReturnType)E_NOT_OK;
	P2CONST(NvM_BlockDescriptorType, NVM_VAR, NVM_APPL_CONST) pBlockDescriptor = \
			NvM_Config.NvM_BlockDescriptor;
	P2VAR(NvM_JobSchedulingType, NVM_VAR, NVM_APPL_CONST) pJobScheduling = NULL_PTR;
	P2VAR(NvM_JobQueueType, AUTOMATIC, NVM_VAR) pJobQueue = NULL_PTR;

	if((boolean)TRUE != NvM_InitDown)
	{
#if (NVM_DEV_ERROR_DETECT == STD_ON)
		/* @req [SWS_NvM_00625] */
		NVM_DET_REPORT_ERROR(NVM_SID_RESTOREBLOCKDEFAULTS,NVM_E_NOT_INITIALIZED);
#endif /* NVM_DEV_ERROR_DETECT == STD_ON */
	}
	else if((0U == BlockId) || ((BlockId-1U) >= NVM_NUM_OF_BLOCK)|| (1U == BlockId))
	{
#if (NVM_DEV_ERROR_DETECT == STD_ON)
		/* @req [SWS_NvM_00630] */
		NVM_DET_REPORT_ERROR(NVM_SID_RESTOREBLOCKDEFAULTS,NVM_E_PARAM_BLOCK_ID);
#endif /* NVM_DEV_ERROR_DETECT == STD_ON */
	}
	else if(NVM_REQ_PENDING == NvM_AdministrativeBlock[BlockId-1U].NvM_BlockRequestResult)
	{
#if (NVM_DEV_ERROR_DETECT == STD_ON)
		/* @req [SWS_NvM_00626] */
		NVM_DET_REPORT_ERROR(NVM_SID_RESTOREBLOCKDEFAULTS,NVM_E_BLOCK_PENDING);
#endif /* NVM_DEV_ERROR_DETECT == STD_ON */
	}
	else if(((boolean)FALSE == NVM_USE_SYNC_MECHANISM(pBlockDescriptor,BlockId-1U)) &&
		(NULL_PTR == NVM_GET_RAM_BLOCK_ADDRESS(pBlockDescriptor,BlockId-1U)) &&
		(NULL_PTR == NvM_DestPtr))
	{
#if (NVM_DEV_ERROR_DETECT == STD_ON)
		/* @req [SWS_NvM_00629] */
		NVM_DET_REPORT_ERROR(NVM_SID_RESTOREBLOCKDEFAULTS,NVM_E_PARAM_ADDRESS);
#endif /* NVM_DEV_ERROR_DETECT == STD_ON */
	}
	else if((NULL_PTR == NVM_GET_ROM_BLOCK_ADDRESS(pBlockDescriptor,BlockId-1U)) && \
		(NULL_PTR == NVM_GET_INIT_BLOCK_CALLBACK(pBlockDescriptor,BlockId-1U)))
	{
#if (NVM_DEV_ERROR_DETECT == STD_ON)
		/* @req [SWS_NvM_00885] */
		NVM_DET_REPORT_ERROR(NVM_SID_RESTOREBLOCKDEFAULTS,NVM_E_BLOCK_WITHOUT_DEFAULTS);
		/* @req [SWS_NvM_00628] */
		NVM_DET_REPORT_ERROR(NVM_SID_RESTOREBLOCKDEFAULTS,NVM_E_BLOCK_CONFIG);
#endif /* NVM_DEV_ERROR_DETECT == STD_ON */
	}
	else if((NVM_BLOCK_DATASET == NVM_GET_BLOCK_MANAGEMENT_TYPE(pBlockDescriptor,BlockId-1U)) && \
			(NvM_AdministrativeBlock[BlockId-1U].NvM_BlockIndex < \
			NVM_GET_NV_BLOCK_NUMBER(pBlockDescriptor,BlockId-1U)) && \
			(0U != NVM_GET_ROM_BLOCK_NUMBER(pBlockDescriptor,BlockId-1U)))
	{
		/* @req [SWS_NvM_00353] */
	}
	else
	{
		if((Std_ReturnType)E_OK == NvM_GetJobQueueAndIndex(
					NVM_GET_BLOCK_JOB_PRIORITY(pBlockDescriptor,BlockId-1U),&pJobScheduling,
					&pJobQueue,NVM_SID_RESTOREBLOCKDEFAULTS))
		{
			NvM_SetJobQueue(NVM_GET_BLOCK_JOB_PRIORITY(pBlockDescriptor,BlockId-1U),BlockId,
				NVM_RESTORE_BLOCK_DEFAULTS,pJobScheduling,pJobQueue);

#if (STD_ON == NVM_USE_MIRROR_MECHANISM)
			if((boolean)TRUE == NVM_USE_SYNC_MECHANISM(pBlockDescriptor,BlockId-1U))
			{
				NvM_AdministrativeBlock[BlockId-1U].NvM_RAMAddress = &NvM_MirrorBlock[0];
			}
			else
#endif /* STD_ON == NVM_USE_MIRROR_MECHANISM */
			/* @req [SWS_NvM_00435] */
			/* @req [SWS_NvM_00436] */
			if(NULL_PTR != NvM_DestPtr)
			{
				NvM_AdministrativeBlock[BlockId-1U].NvM_RAMAddress = (uint8*)NvM_DestPtr;
			}
			else
			{
				NvM_AdministrativeBlock[BlockId-1U].NvM_RAMAddress = \
						NVM_GET_RAM_BLOCK_ADDRESS(pBlockDescriptor,BlockId-1U);
			}

			/* @req [SWS_NvM_00227] */
			NvM_AdministrativeBlock[BlockId-1U].NvM_BlockState = NVM_BLOCK_INVALID_UNCHANGED;
			if((boolean)TRUE == NVM_IS_NOTIFY_BSWM(pBlockDescriptor, BlockId-1U))
			{
#if (NVM_BSWM_BLOCKSTATUS_INFORMATION == STD_ON)
				BswM_NvM_CurrentBlockMode(BlockId, \
						NvM_AdministrativeBlock[BlockId-1U].NvM_BlockRequestResult);
#endif /* (NVM_BSWM_BLOCKSTATUS_INFORMATION == STD_ON) */
			}
			ret = (Std_ReturnType)E_OK;
		}
		else
		{
			/* Do nothing */
		}
	}

	return ret;
}
#endif /* NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_2 || \
		NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3 */

#if (\
	NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_2 || \
	NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3 \
	)
/**
 * @sid            0x18
 * @brief          Service to restore the default data to its corresponding Penmanent RAM block
 *
 * @param[in]      BlockId     The block identifier uniquely identifies one NVRAM block descriptor.
 *                             A NVRAM block descriptor contains all needed information about a
 *                             single NVRAM block
 * @return         Std_ReturnType
 * @retval         E_OK       request has been accepted
 * @retval         E_NOT_OK   request has not been accepted
 */
FUNC(Std_ReturnType, NVM_CODE) NvM_RestorePRAMBlockDefaults(VAR(NvM_BlockIdType, AUTOMATIC) BlockId)
{
	VAR(Std_ReturnType, AUTOMATIC) ret = (Std_ReturnType)E_NOT_OK;
	P2CONST(NvM_BlockDescriptorType, NVM_VAR, NVM_APPL_CONST) pBlockDescriptor = \
			NvM_Config.NvM_BlockDescriptor;
	P2VAR(NvM_JobSchedulingType, NVM_VAR, NVM_APPL_CONST) pJobScheduling = NULL_PTR;
	P2VAR(NvM_JobQueueType, AUTOMATIC, NVM_VAR) pJobQueue = NULL_PTR;

	if((boolean)TRUE != NvM_InitDown)
	{
#if (NVM_DEV_ERROR_DETECT == STD_ON)
		/* @req [SWS_NvM_00831] */
		NVM_DET_REPORT_ERROR(NVM_SID_RESTOREPRAMBLOCKDEFAULTS,NVM_E_NOT_INITIALIZED);
#endif /* NVM_DEV_ERROR_DETECT == STD_ON */
	}
	else if((0U == BlockId) || ((BlockId-1U) >= NVM_NUM_OF_BLOCK) || (1U == BlockId))
	{
#if (NVM_DEV_ERROR_DETECT == STD_ON)
		/* @req [SWS_NvM_00834] */
		NVM_DET_REPORT_ERROR(NVM_SID_RESTOREPRAMBLOCKDEFAULTS,NVM_E_PARAM_BLOCK_ID);
#endif /* NVM_DEV_ERROR_DETECT == STD_ON */
	}
	else if(NVM_REQ_PENDING == NvM_AdministrativeBlock[BlockId-1U].NvM_BlockRequestResult)
	{
#if (NVM_DEV_ERROR_DETECT == STD_ON)
		/* @req [SWS_NvM_00832] */
		NVM_DET_REPORT_ERROR(NVM_SID_RESTOREPRAMBLOCKDEFAULTS,NVM_E_BLOCK_PENDING);
#endif /* NVM_DEV_ERROR_DETECT == STD_ON */
	}
	else if(NULL_PTR == NVM_GET_RAM_BLOCK_ADDRESS(pBlockDescriptor,BlockId-1U))
	{
#if (NVM_DEV_ERROR_DETECT == STD_ON)
		NVM_DET_REPORT_ERROR(NVM_SID_RESTOREPRAMBLOCKDEFAULTS,NVM_E_PARAM_ADDRESS);
#endif /* NVM_DEV_ERROR_DETECT == STD_ON */
	}
	else if(
		(NULL_PTR == NVM_GET_ROM_BLOCK_ADDRESS(pBlockDescriptor,BlockId-1U)) && \
		(NULL_PTR == NVM_GET_INIT_BLOCK_CALLBACK(pBlockDescriptor,BlockId-1U)))
	{
#if (NVM_DEV_ERROR_DETECT == STD_ON)
		/* @req [SWS_NvM_00833] */
		NVM_DET_REPORT_ERROR(NVM_SID_RESTOREPRAMBLOCKDEFAULTS,NVM_E_BLOCK_CONFIG);
		/* @req [SWS_NvM_00886] */
		NVM_DET_REPORT_ERROR(NVM_SID_RESTOREPRAMBLOCKDEFAULTS,NVM_E_BLOCK_WITHOUT_DEFAULTS);
#endif /* NVM_DEV_ERROR_DETECT == STD_ON */
	}
	else if((NVM_BLOCK_DATASET == NVM_GET_BLOCK_MANAGEMENT_TYPE(pBlockDescriptor,BlockId-1U)) && \
			(NvM_AdministrativeBlock[BlockId-1U].NvM_BlockIndex < \
			NVM_GET_NV_BLOCK_NUMBER(pBlockDescriptor,BlockId-1U)) && \
			(0U != NVM_GET_ROM_BLOCK_NUMBER(pBlockDescriptor,BlockId-1U)))
	{
		/* @req [SWS_NvM_00353] */
	}
	else
	{
		if((Std_ReturnType)E_OK == NvM_GetJobQueueAndIndex(
					NVM_GET_BLOCK_JOB_PRIORITY(pBlockDescriptor,BlockId-1U),&pJobScheduling,
					&pJobQueue,NVM_SID_RESTOREPRAMBLOCKDEFAULTS))
		{
			NvM_SetJobQueue(NVM_GET_BLOCK_JOB_PRIORITY(pBlockDescriptor,BlockId-1U),BlockId,
				NVM_RESTORE_PRAM_BLOCK_DEFAULTS,pJobScheduling,pJobQueue);

#if (STD_ON == NVM_USE_MIRROR_MECHANISM)
			if((boolean)TRUE == NVM_USE_SYNC_MECHANISM(pBlockDescriptor,BlockId-1U))
			{
				NvM_AdministrativeBlock[BlockId-1U].NvM_RAMAddress = &NvM_MirrorBlock[0];
			}
			else
#endif /* STD_ON == NVM_USE_MIRROR_MECHANISM */
			{
				NvM_AdministrativeBlock[BlockId-1U].NvM_RAMAddress = \
						NVM_GET_RAM_BLOCK_ADDRESS(pBlockDescriptor,BlockId-1U);
			}

			/* @req [SWS_NvM_00819] */
			NvM_AdministrativeBlock[BlockId-1U].NvM_BlockState = NVM_BLOCK_INVALID_UNCHANGED;
			if((boolean)TRUE == NVM_IS_NOTIFY_BSWM(pBlockDescriptor, BlockId-1U))
			{
#if (NVM_BSWM_BLOCKSTATUS_INFORMATION == STD_ON)
				BswM_NvM_CurrentBlockMode(BlockId, \
						NvM_AdministrativeBlock[BlockId-1U].NvM_BlockRequestResult);
#endif /* (NVM_BSWM_BLOCKSTATUS_INFORMATION == STD_ON) */
			}
			ret = (Std_ReturnType)E_OK;
		}
		else
		{
			/* Do nothing */
		}
	}

	return ret;
}
#endif /* NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_2 || \
		NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3 */

#if (NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3)
/**
 * @sid            0x0b
 * @brief          Service to invalidate a NV block.
 *
 * @param[in]      BlockId     The block identifier uniquely identifies one NVRAM block descriptor.
 *                             A NVRAM block descriptor contains all needed information about a
 *                             single NVRAM block
 *
 * @return         Std_ReturnType
 * @retval         E_OK       request has been accepted
 * @retval         E_NOT_OK   request has not been accepted
 *
 */
FUNC(Std_ReturnType, NVM_CODE) NvM_InvalidateNvBlock(VAR(NvM_BlockIdType, AUTOMATIC) BlockId)
{
	VAR(Std_ReturnType, AUTOMATIC) ret = (Std_ReturnType)E_NOT_OK;
	P2CONST(NvM_BlockDescriptorType, NVM_VAR, NVM_APPL_CONST) pBlockDescriptor = \
				NvM_Config.NvM_BlockDescriptor;
	P2VAR(NvM_JobSchedulingType, NVM_VAR, NVM_APPL_CONST) pJobScheduling = NULL_PTR;
	P2VAR(NvM_JobQueueType, AUTOMATIC, NVM_VAR) pJobQueue = NULL_PTR;

	if((boolean)TRUE != NvM_InitDown)
	{
#if (NVM_DEV_ERROR_DETECT == STD_ON)
		/* @req [SWS_NvM_00638] */
		NVM_DET_REPORT_ERROR(NVM_SID_INVALIDATENVBLOCK,NVM_E_NOT_INITIALIZED);
#endif /* NVM_DEV_ERROR_DETECT == STD_ON */
	}
	else if((0U == BlockId) || ((BlockId-1U) >= NVM_NUM_OF_BLOCK) || (1U == BlockId))
	{
#if (NVM_DEV_ERROR_DETECT == STD_ON)
		/* @req [SWS_NvM_00642] */
		NVM_DET_REPORT_ERROR(NVM_SID_INVALIDATENVBLOCK,NVM_E_PARAM_BLOCK_ID);
#endif /* NVM_DEV_ERROR_DETECT == STD_ON */
	}
	else if(NVM_REQ_PENDING == NvM_AdministrativeBlock[BlockId-1U].NvM_BlockRequestResult)
	{
#if (NVM_DEV_ERROR_DETECT == STD_ON)
		/* @req [SWS_NvM_00639] */
		NVM_DET_REPORT_ERROR(NVM_SID_INVALIDATENVBLOCK,NVM_E_BLOCK_PENDING);
#endif /* NVM_DEV_ERROR_DETECT == STD_ON */
	}
	else if((boolean)TRUE == NvM_AdministrativeBlock[BlockId-1U].NvM_BlockLockStatus)
	{
#if (NVM_DEV_ERROR_DETECT == STD_ON)
		/* @req [SWS_NvM_00756] */
		NVM_DET_REPORT_ERROR(NVM_SID_INVALIDATENVBLOCK,NVM_E_BLOCK_LOCKED);
#endif /* NVM_DEV_ERROR_DETECT == STD_ON */
	}
	else if(((boolean)TRUE == NvM_AdministrativeBlock[BlockId-1U].NvM_BlockProtection) || \
			((NVM_BLOCK_DATASET == NVM_GET_BLOCK_MANAGEMENT_TYPE(pBlockDescriptor,BlockId-1U)) && \
					(NvM_AdministrativeBlock[BlockId-1U].NvM_BlockIndex >= \
					NVM_GET_NV_BLOCK_NUMBER(pBlockDescriptor,BlockId-1U))))
	{
#if (STD_ON == NVM_E_WRITE_PROTECTED_SWITCH)
		/* @req [SWS_NvM_00411] */
		Dem_ReportErrorStatus(NVM_E_WRITE_PROTECTED, DEM_EVENT_STATUS_FAILED);
#endif /* STD_ON == NVM_E_WRITE_PROTECTED_SWITCH */
	}
	else
	{
		if((Std_ReturnType)E_OK == NvM_GetJobQueueAndIndex(
					NVM_GET_BLOCK_JOB_PRIORITY(pBlockDescriptor,BlockId-1U),&pJobScheduling,
					&pJobQueue,NVM_SID_INVALIDATENVBLOCK))
		{
			NvM_SetJobQueue(NVM_GET_BLOCK_JOB_PRIORITY(pBlockDescriptor,BlockId-1U),BlockId,
				NVM_INVALIDATE_NV_BLOCK,pJobScheduling,pJobQueue);
			if((boolean)TRUE == NVM_IS_NOTIFY_BSWM(pBlockDescriptor, BlockId-1U))
			{
#if (NVM_BSWM_BLOCKSTATUS_INFORMATION == STD_ON)
				BswM_NvM_CurrentBlockMode(BlockId, \
						NvM_AdministrativeBlock[BlockId-1U].NvM_BlockRequestResult);
#endif /* (NVM_BSWM_BLOCKSTATUS_INFORMATION == STD_ON) */
			}
			ret = (Std_ReturnType)E_OK;
		}
	}

	return ret;
}
#endif /* NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3 */

#if (\
	NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_2 || \
	NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3 \
	)
/**
 * @sid            0x19
 * @brief          Initiates a multi block validation request.
 *
 * @Param[in]      None
 * @Param[out]     None
 * @Param[in/out]  None
 * @return         None
 **/
FUNC(void, NVM_CODE) NvM_ValidateAll(void)
{
	VAR(uint16, AUTOMATIC) count = 1U;
	P2CONST(NvM_BlockDescriptorType, NVM_VAR, NVM_APPL_CONST) pBlockDescriptor = \
				NvM_Config.NvM_BlockDescriptor;

	if((boolean)TRUE != NvM_InitDown)
	{
#if (NVM_DEV_ERROR_DETECT == STD_ON)
		/* @req [SWS_NvM_00638] */
		NVM_DET_REPORT_ERROR(NVM_SID_VALIDATEALL,NVM_E_NOT_INITIALIZED);
#endif /* NVM_DEV_ERROR_DETECT == STD_ON */
	}
	else if(NVM_REQ_PENDING == NvM_MultiBlockRequestResult)
	{
		/* Do nothing */
	}
	else
	{
		NvM_MultiBlockJob = NVM_VALIDATE_ALL;
		do
		{
			/* @req [SWS_NvM_00856] */
			/* @req [SWS_NvM_00860] */
			if(((boolean)TRUE == NVM_IS_USE_AUTO_VALIDATION(pBlockDescriptor, count)) && \
					(NvM_AdministrativeBlock[count].NvM_BlockState != NVM_BLOCK_INVALID_UNCHANGED) && \
					(NvM_AdministrativeBlock[count].NvM_BlockState != NVM_BLOCK_INVALID_CHANGED) && \
					((NULL_PTR != NVM_GET_RAM_BLOCK_ADDRESS(pBlockDescriptor, count)) || \
							((boolean)TRUE == NVM_USE_SYNC_MECHANISM(pBlockDescriptor,count))))
			{
				NvM_AdministrativeBlock[count].NvM_BlockRequestResult = NVM_REQ_PENDING;
				if((boolean)TRUE == NVM_IS_NOTIFY_BSWM(pBlockDescriptor, count))
				{
#if (NVM_BSWM_BLOCKSTATUS_INFORMATION == STD_ON)
					BswM_NvM_CurrentBlockMode(count+1U, \
							NvM_AdministrativeBlock[count].NvM_BlockRequestResult);
#endif /* (NVM_BSWM_BLOCKSTATUS_INFORMATION == STD_ON) */
				}
			}
			count++;
		}while(count < NVM_NUM_OF_BLOCK);
		/* @req [SWS_NvM_00861] */
		NvM_MultiBlockRequestResult = NVM_REQ_PENDING;
#if (NVM_BSWM_MULTIBLOCK_JOBSTATUS_INFORMATION == STD_ON)
		BswM_NvM_CurrentJobMode(NVM_SID_VALIDATEALL,NvM_MultiBlockRequestResult);
#endif /* NVM_BSWM_MULTIBLOCK_JOBSTATUS_INFORMATION == STD_ON */
	}
}
#endif /* NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_2 || \
		NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3 */

#if (\
	NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_1 || \
	NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_2 || \
	NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3 \
	)
/**
 * @sid            0x0C
 * @brief          Initiates a multi block read request.
 *
 * @Param[in]      None
 * @Param[out]     None
 * @Param[in/out]  None
 * @return         None
 */
FUNC(void, NVM_CODE) NvM_ReadAll(void)
{
	VAR(uint16, AUTOMATIC) count = 0U;
	P2CONST(NvM_BlockDescriptorType, NVM_VAR, NVM_APPL_CONST) pBlockDescriptor = \
				NvM_Config.NvM_BlockDescriptor;

	if((boolean)TRUE != NvM_InitDown)
	{
#if (NVM_DEV_ERROR_DETECT == STD_ON)
		/* @req [SWS_NvM_00646] */
		NVM_DET_REPORT_ERROR(NVM_SID_READALL,NVM_E_NOT_INITIALIZED);
#endif /* NVM_DEV_ERROR_DETECT == STD_ON */
	}
	else if(NVM_REQ_PENDING == NvM_MultiBlockRequestResult)
	{
		/* Do nothing */
	}
	else
	{
		NvM_MultiBlockJob = NVM_READ_ALL;

		/* @req [SWS_NvM_00304] */
		do
		{
			/**
			 * If the nvm_blockrequestresult in the management block is set to nvm_req_pending,
			 * the task that is currently in a single block is required to be executed,
			 * and there is no need to set up the block in multiple tasks
			 **/
			if(NvM_AdministrativeBlock[count].NvM_BlockRequestResult != NVM_REQ_PENDING)
			{
				/* @req [SWS_NvM_00245] */
				if(((NULL_PTR != NVM_GET_RAM_BLOCK_ADDRESS(pBlockDescriptor, count)) || \
						((boolean)TRUE == NVM_USE_SYNC_MECHANISM(pBlockDescriptor,count))) && \
					((boolean)TRUE == NVM_GET_BLOCK_READ_ALL_ATTRIBUTE(pBlockDescriptor, count)) && \
					(NVM_BLOCK_DATASET != NVM_GET_BLOCK_MANAGEMENT_TYPE(pBlockDescriptor, count)))
				{
					if(NULL_PTR != NVM_GET_RAM_BLOCK_ADDRESS(pBlockDescriptor, count))
					{
						NvM_AdministrativeBlock[count].NvM_RAMAddress = \
								NVM_GET_RAM_BLOCK_ADDRESS(pBlockDescriptor, count);
					}
#if (STD_ON == NVM_USE_MIRROR_MECHANISM)
					else
					{
						NvM_AdministrativeBlock[count].NvM_RAMAddress = &NvM_MirrorBlock[0];
					}
#endif/* (STD_ON == NVM_USE_MIRROR_MECHANISM) */
					NvM_AdministrativeBlock[count].NvM_BlockRequestResult = NVM_REQ_PENDING;
					NvM_AdministrativeBlock[count].NvM_BlockState = NVM_BLOCK_INVALID_UNCHANGED;
					if((boolean)TRUE == NVM_IS_NOTIFY_BSWM(pBlockDescriptor, count))
					{
#if (NVM_BSWM_BLOCKSTATUS_INFORMATION == STD_ON)
						BswM_NvM_CurrentBlockMode(count+1U, \
								NvM_AdministrativeBlock[count].NvM_BlockRequestResult);
#endif /* (NVM_BSWM_BLOCKSTATUS_INFORMATION == STD_ON) */
					}
				}
				else
				{
					NvM_AdministrativeBlock[count].NvM_BlockRequestResult = NVM_REQ_BLOCK_SKIPPED;
					if((boolean)TRUE == NVM_IS_NOTIFY_BSWM(pBlockDescriptor, count))
					{
#if (NVM_BSWM_BLOCKSTATUS_INFORMATION == STD_ON)
						BswM_NvM_CurrentBlockMode(count+1U, \
								NvM_AdministrativeBlock[count].NvM_BlockRequestResult);
#endif /* (NVM_BSWM_BLOCKSTATUS_INFORMATION == STD_ON) */
					}
				}
			}
			count++;
		}while(count < NVM_NUM_OF_BLOCK);

		/* @req [SWS_NvM_00667] */
		NvM_MultiBlockRequestResult = NVM_REQ_PENDING;
#if (NVM_BSWM_MULTIBLOCK_JOBSTATUS_INFORMATION == STD_ON)
		BswM_NvM_CurrentJobMode(NVM_SID_READALL,NvM_MultiBlockRequestResult);
#endif /* NVM_BSWM_MULTIBLOCK_JOBSTATUS_INFORMATION == STD_ON */
	}
}
#endif /* NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_1 || \
		NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_2 || \
		NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3 */

#if (\
	NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_1 || \
	NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_2 || \
	NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3 \
	)
/**
 * @sid            0x0D
 * @brief          Initiates a multi block write request
 *
 * @Param[in]      None
 * @Param[out]     None
 * @Param[in/out]  None
 * @return         None
 */
FUNC(void, NVM_CODE) NvM_WriteAll(void)
{
	VAR(uint16, AUTOMATIC) count = 1U;
	P2CONST(NvM_BlockDescriptorType, NVM_VAR, NVM_APPL_CONST) pBlockDescriptor = \
				NvM_Config.NvM_BlockDescriptor;

	if((boolean)TRUE != NvM_InitDown)
	{
#if (NVM_DEV_ERROR_DETECT == STD_ON)
		/* @req [SWS_NvM_00647] */
		NVM_DET_REPORT_ERROR(NVM_SID_WRITEALL,NVM_E_NOT_INITIALIZED);
#endif /* NVM_DEV_ERROR_DETECT == STD_ON */
	}
	else if(NVM_REQ_PENDING == NvM_MultiBlockRequestResult)
	{
		/* Do nothing */
	}
	else
	{
		NvM_MultiBlockJob = NVM_WRITE_ALL;

		/* @req [SWS_NvM_00310] */
		/* Block 1 needs to be writen during WriteAll */
		if(((boolean)FALSE == NvM_RunJob.NvM_ConfigureIDIsOK) || (NVM_REQ_NV_INVALIDATED == \
				NvM_AdministrativeBlock[0].NvM_BlockRequestResult) || \
				(NvM_AdministrativeBlock[0].NvM_BlockState == NVM_BLOCK_VALID_CHANGED))
		{
			NvM_AdministrativeBlock[0].NvM_BlockRequestResult = NVM_REQ_PENDING;
			if((boolean)TRUE == NVM_IS_NOTIFY_BSWM(pBlockDescriptor, 0))
			{
#if (NVM_BSWM_BLOCKSTATUS_INFORMATION == STD_ON)
				BswM_NvM_CurrentBlockMode(1U, \
						NvM_AdministrativeBlock[0].NvM_BlockRequestResult);
#endif /* (NVM_BSWM_BLOCKSTATUS_INFORMATION == STD_ON) */
			}
		}

		do
		{
			/* @req [SWS_NvM_00298] */
			/**
			 * If the nvm_blockrequestresult in the management block is set to nvm_req_pending,
			 * the task that is currently in a single block is required to be executed,
			 * and there is no need to set up the block in multiple tasks
			 **/
			if(((boolean)TRUE == NVM_GET_BLOCK_WRITE_ALL_ATTRIBUTE(pBlockDescriptor, count)) && \
					(NvM_AdministrativeBlock[count].NvM_BlockRequestResult != NVM_REQ_PENDING))
			{
				/* @req [SWS_NvM_00252] */
				/* @req [SWS_NvM_00432] */
				/* @req [SWS_NvM_00682] */
				/* @req [SWS_NvM_00433] */
				/* @req [SWS_NvM_00434] */
				/* @req [SWS_NvM_00750] */
				if(((NULL_PTR != NVM_GET_RAM_BLOCK_ADDRESS(pBlockDescriptor, count)) || \
						((boolean)TRUE == NVM_USE_SYNC_MECHANISM(pBlockDescriptor,count))) && \
						((boolean)FALSE == NvM_AdministrativeBlock[count].NvM_BlockProtection) && \
						((boolean)FALSE == NvM_AdministrativeBlock[count].NvM_BlockLockStatus) && \
						(NVM_BLOCK_VALID_CHANGED == NvM_AdministrativeBlock[count].NvM_BlockState) && \
						(((NVM_BLOCK_DATASET != \
								NVM_GET_BLOCK_MANAGEMENT_TYPE(pBlockDescriptor,count))) || \
						((NVM_BLOCK_DATASET == \
								NVM_GET_BLOCK_MANAGEMENT_TYPE(pBlockDescriptor,count)) && \
								(NvM_AdministrativeBlock[count].NvM_BlockIndex < \
								NVM_GET_NV_BLOCK_NUMBER(pBlockDescriptor,count)))))
				{
					if(NULL_PTR != NVM_GET_RAM_BLOCK_ADDRESS(pBlockDescriptor, count))
					{
						NvM_AdministrativeBlock[count].NvM_RAMAddress = \
								NVM_GET_RAM_BLOCK_ADDRESS(pBlockDescriptor, count);
					}
					else
					{
						/* Do nothing */
					}
					NvM_AdministrativeBlock[count].NvM_BlockRequestResult = NVM_REQ_PENDING;
					if((boolean)TRUE == NVM_IS_NOTIFY_BSWM(pBlockDescriptor, count))
					{
#if (NVM_BSWM_BLOCKSTATUS_INFORMATION == STD_ON)
						BswM_NvM_CurrentBlockMode(count+1U, \
								NvM_AdministrativeBlock[count].NvM_BlockRequestResult);
#endif /* (NVM_BSWM_BLOCKSTATUS_INFORMATION == STD_ON) */
					}
				}
				else
				{
					NvM_AdministrativeBlock[count].NvM_BlockRequestResult = NVM_REQ_BLOCK_SKIPPED;
					if((boolean)TRUE == NVM_IS_NOTIFY_BSWM(pBlockDescriptor, count))
					{
#if (NVM_BSWM_BLOCKSTATUS_INFORMATION == STD_ON)
						BswM_NvM_CurrentBlockMode(count+1U, \
								NvM_AdministrativeBlock[count].NvM_BlockRequestResult);
#endif /* (NVM_BSWM_BLOCKSTATUS_INFORMATION == STD_ON) */
					}
				}
			}
			count++;
		}while(count < NVM_NUM_OF_BLOCK);

		/* @req [SWS_NvM_00549] */
		NvM_MultiBlockRequestResult = NVM_REQ_PENDING;
#if (NVM_BSWM_MULTIBLOCK_JOBSTATUS_INFORMATION == STD_ON)
		BswM_NvM_CurrentJobMode(NVM_SID_WRITEALL,NvM_MultiBlockRequestResult);
#endif /* NVM_BSWM_MULTIBLOCK_JOBSTATUS_INFORMATION == STD_ON */
	}
}
#endif /* NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_1 || \
		NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_2 || \
		NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3 */

#if (\
	NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_1 || \
	NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_2 || \
	NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3 \
	)
/**
 * @sid            0x0A
 * @brief          Service to cancel a running NvM_WriteAll request.
 *
 * @Param[in]      None
 * @Param[out]     None
 * @Param[in/out]  None
 * @return         None
 */
FUNC(void, NVM_CODE) NvM_CancelWriteAll(void)
{

	if((boolean)TRUE != NvM_InitDown)
	{
#if (NVM_DEV_ERROR_DETECT == STD_ON)
		/* @req [SWS_NvM_00637] */
		NVM_DET_REPORT_ERROR(NVM_SID_CANCELWRITEALL,NVM_E_NOT_INITIALIZED);
#endif /* NVM_DEV_ERROR_DETECT == STD_ON */
	}
	/* @req [SWS_NvM_00019] */
	else if(NVM_WRITE_ALL == NvM_RunJob.NvM_CurrentRunJob)
	{
		NvM_MultiBlockJob = NVM_CANCEL_WRITE_ALL;
	}
	else
	{
		/* Do nothing */
	}
}
#endif /* NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_1 || \
		NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_2 || \
		NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3 \ */

#if (NVM_POLLING_MODE == STD_OFF)
/**
 * @sid            0x11
 * @brief          Function to be used by the underlying memory abstraction to signal
 * 				   end of job without error.
 *
 * @Param[in]      None
 * @Param[out]     None
 * @Param[in/out]  None
 * @return         None
 */
void NvM_JobEndNotification(void)
{
	NvM_RunJob.NvM_InternalJobStatus = NVM_JOB_OK;
	NvM_RunJob.NvM_MemIfJobResult = \
			MemIf_GetJobResult(NVM_GET_BLOCK_DEVICE_INDEX(
					NvM_Config.NvM_BlockDescriptor,NvM_RunJob.NvM_CurrentRunBlockId-1U));
}
#endif /* NVM_POLLING_MODE == STD_OFF */

#if (NVM_POLLING_MODE == STD_OFF)
/**
 * @sid            0x12
 * @brief          Function to be used by the underlying memory abstraction to signal
 * 				   end of job with error.
 *
 * @Param[in]      None
 * @Param[out]     None
 * @Param[in/out]  None
 * @return         None
 */
void NvM_JobErrorNotification(void)
{
	NvM_RunJob.NvM_MemIfJobResult = \
			MemIf_GetJobResult(NVM_GET_BLOCK_DEVICE_INDEX(
					NvM_Config.NvM_BlockDescriptor,NvM_RunJob.NvM_CurrentRunBlockId-1U));
	NvM_RunJob.NvM_InternalJobStatus = NVM_JOB_MEMIF_FAIL;
}
#endif /* NVM_POLLING_MODE == STD_OFF */

/**
 * @sid            0x0e
 * @brief          Service for performing the processing of the NvM jobs.
 *
 * @Param[in]      None
 * @Param[out]     None
 * @Param[in/out]  None
 * @return         None
 */
FUNC(void, NVM_CODE) NvM_MainFunction(void)
{
	P2CONST(NvM_BlockDescriptorType, NVM_VAR, NVM_APPL_CONST) pBlockDescriptor = \
			NvM_Config.NvM_BlockDescriptor;
	P2VAR(NvM_AdministrativeBlockType, NVM_VAR, NVM_APPL_CONST) pCurrentJob = NULL_PTR;

	boolean queue;

	MemIf_StatusType memifStatu;
	
	memifStatu = MemIf_GetStatus(NVM_GET_BLOCK_DEVICE_INDEX(pBlockDescriptor, \
			NvM_RunJob.NvM_CurrentRunBlockId-1U));

	/* Get the Job that need to be performed */
	if(((boolean)TRUE == NvM_InitDown) && (MEMIF_IDLE == memifStatu))
	{
		queue = NvM_GetUpcomingJob();

		if((boolean)TRUE == queue)
		{
#if (STD_ON == NVM_POLLING_MODE)
			NvM_GetMemIfStatus();
#endif /* STD_ON == NVM_POLLING_MODE */
			if(NVM_JOB_PENDING != NvM_RunJob.NvM_InternalJobStatus)
			{
				NvM_MultiBlockProcessing(pBlockDescriptor);
				pCurrentJob = &NvM_AdministrativeBlock[NvM_RunJob.NvM_CurrentRunBlockId-1U];
				/* Get the internal jobs that need to be executed */
				NvM_SingleBlockProcessing(pBlockDescriptor, \
						NvM_RunJob.NvM_CurrentRunBlockId,pCurrentJob);
			}
			/* Perform internal Jobs */
			NvM_InternalJobProcessing(pBlockDescriptor,NvM_RunJob.NvM_CurrentRunBlockId,pCurrentJob);
		}
	}
}

#ifdef AH_TEST_NVM
FUNC(void, NVM_CODE) NvM_DeInit()
{
	NvM_MultiBlockJob = NVM_INVALID_JOB;

	NvM_InitDown = (boolean)FALSE;
}
#endif

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h"

#ifdef __cplusplus
}
#endif
/** @} */
