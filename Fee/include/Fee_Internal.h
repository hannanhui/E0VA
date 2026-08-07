/**
 * @file        Fee_Internal.h
 * @brief       AUTOSAR FEE_INTERNAL - Fee_Internal driver header file.
 * @details     Fee_Internal driver header file, containing the Autosar API specification and
 *               other variables and functions that are exported by the Fee_Internal driver.
 * @version     1.2.0
 * @addtogroup  FEE_INTERNAL
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

#ifndef FEE_INTERNAL_H
#define FEE_INTERNAL_H

#ifdef __cplusplus
extern "C"{
#endif

/*====================================================================================================*
 *                                           INCLUDE FILES                                          
 *====================================================================================================*/

/*====================================================================================================*
 *                                  HEADER FILE VERSION INFORMATION                                 
 *====================================================================================================*/

#define FEE_INTERNAL_VENDOR_ID            		 	0U
#define FEE_INTERNAL_AR_RELEASE_MAJOR_VERSION     	4U
#define FEE_INTERNAL_AR_RELEASE_MINOR_VERSION     	2U
#define FEE_INTERNAL_AR_RELEASE_REVISION_VERSION  	2U
#define FEE_INTERNAL_SW_MAJOR_VERSION             	1U
#define FEE_INTERNAL_SW_MINOR_VERSION             	2U
#define FEE_INTERNAL_SW_PATCH_VERSION             	0U

/*====================================================================================================*
 *                                         FILE VERSION CHECKS                                      
 *====================================================================================================*/

/* Add code here */

/*====================================================================================================*
 *                                             CONSTANTS                                            
 *====================================================================================================*/

/* Add code here */

/*====================================================================================================*
 *                                         DEFINES AND MACROS                                       
 *====================================================================================================*/

/* Add code here */

/*====================================================================================================*
 *                                               ENUMS                                              
 *====================================================================================================*/
/**
* @brief        Status of Fee block header
* @api
*/
typedef enum
{
    FEE_BLOCK_VALID = 0,         /**< @brief Fee block is valid */
    FEE_BLOCK_INVALID,           /**< @brief Fee block is invalid
                                      (has been invalidated) */
    FEE_BLOCK_INCONSISTENT,      /**< @brief Fee block is inconsistent
                                      (contains bogus data) */
    FEE_BLOCK_HEADER_INVALID,    /**< @brief Fee block header is garbled */
    FEE_BLOCK_INVALIDATED,       /**< @brief Fee block header is invalidated by
                                      Fee_InvalidateBlock(BlockNumber)(not used when
                                      FEE_BLOCK_ALWAYS_AVAILABLE == STD_OFF) */
    FEE_BLOCK_HEADER_BLANK,      /**< @brief Fee block header is blank,
                                      it is used to mark the end of Fee block header list
                                      when parsing the memory at initialization*/
#if (FEE_MARK_EMPTY_BLOCKS_INVALID == STD_ON)
    FEE_BLOCK_INCONSISTENT_COPY  /**< @brief FEE data read error during swap
                                     (ie data area was allocated) */
#else
    FEE_BLOCK_INCONSISTENT_COPY,  /**< @brief FEE data read error during swap
                                     (ie data area was allocated) */
    FEE_BLOCK_NEVER_WRITTEN     /**< @brief FEE block was never written in data flash */
#endif
} Fee_BlockStatusType;

/**
* @brief        Status of Fee cluster header
* @api
*/
typedef enum
{
    FEE_CLUSTER_VALID = 0,       /**< @brief Fee cluster is valid */
    FEE_CLUSTER_INVALID,         /**< @brief Fee cluster is invalid */
    FEE_CLUSTER_INCONSISTENT,    /**< @brief Fee cluster is inconsistent
                                      (contains bogus data) */
    FEE_CLUSTER_HEADER_INVALID   /**< @brief Fee cluster header is garbled */
} Fee_ClusterStatusType;

/**
* @brief        Type of job currently executed by Fee_MainFunction
* @api
*/
typedef enum
{
    /* Fee_Read() related jobs */

    FEE_JOB_READ = 0,                /**< @brief Read Fee block */

    /* Fee_Write() related jobs */

    FEE_JOB_WRITE,                   /**< @brief Write Fee block to flash */
    FEE_JOB_WRITE_DATA,              /**< @brief Write Fee block data to flash
                                          */
    FEE_JOB_WRITE_UNALIGNED_DATA,    /**< @brief Write unaligned rest of Fee
                                          block data to flash */
    FEE_JOB_WRITE_VALIDATE,          /**< @brief Validate Fee block by writing
                                          validation flag to flash */
    FEE_JOB_WRITE_DONE,              /**< @brief Finalize validation of Fee
                                          block */
    /* Fee_InvalidateBlock() related jobs */

    FEE_JOB_INVAL_BLOCK,             /**< @brief Invalidate Fee block by writing
                                          the invalidation flag to flash */
    FEE_JOB_INVAL_BLOCK_DONE,        /**< @brief Finalize invalidation of Fee
                                          block */

    /* Fee_EraseImmediateBlock() related jobs */

    FEE_JOB_ERASE_IMMEDIATE,         /**< @brief Erase (pre-allocate) immediate
                                          Fee block */
    FEE_JOB_ERASE_IMMEDIATE_DONE,    /**< @brief Finalize erase (pre-allocation)
                                          of Fee block */
    /* Fee_Init() realted jobs */
    FEE_JOB_INT_SCAN,                /**< @brief Initialize the cluster scan job
                                          */
    FEE_JOB_INT_SCAN_CLR_HDR_PARSE,  /**< @brief Parse Fee cluster header */
    FEE_JOB_INT_SCAN_CLR,            /**< @brief Scan active cluster of current
                                          cluster group */
    FEE_JOB_INT_SCAN_CLR_FMT,        /**< @brief Format first Fee cluster */
    FEE_JOB_INT_SCAN_CLR_FMT_DONE,   /**< @brief Finalize format of first Fee
                                          cluster */
    FEE_JOB_INT_SCAN_BLOCK_HDR_PARSE,/**< @brief Parse Fee block header */

    /* Internal swap jobs */

    FEE_JOB_INT_SWAP_BLOCK,          /**< @brief Copy next block from source to
                                          target cluster */
    FEE_JOB_INT_SWAP_CLR_FMT,        /**< @brief Format current Fee cluster in
                                          current Fee cluster group */
    FEE_JOB_INT_SWAP_DATA_READ,      /**< @brief Read data from source cluster
                                          to internal Fee buffer */
    FEE_JOB_INT_SWAP_DATA_WRITE,     /**< @brief Write data from internal
                                          Fee buffer to target cluster */
    FEE_JOB_INT_SWAP_CLR_VLD_DONE,   /**< @brief Finalize cluster validation */
    /* Fee system jobs */
    FEE_JOB_DONE                     /**< @brief No more subsequent jobs to
                                          schedule */
} Fee_JobType;


/*====================================================================================================*
 *                                   STRUCTURES AND OTHER TYPEDEFS
 *====================================================================================================*/
/**
* @brief        Fee cluster group run-time status
* @api
*/
typedef struct
{
    Fls_AddressType uDataAddrIt;  /**< @brief Address of current Fee data block in flash */
    Fls_AddressType uHdrAddrIt;   /**< @brief Address of current Fee block header in flash */
    uint32 uActClrID;             /**< @brief ID of active cluster */
    uint8 uActClr;                /**< @brief Index of active cluster */
} Fee_ClusterGroupInfoType;

/**
* @brief        Fee block run-time status
* @api
*/
typedef struct
{
    Fls_AddressType uDataAddr;      /**< @brief Address of Fee block data in flash */
    Fls_AddressType uInvalidAddr;   /**< @brief Address of Fee block invalidation field in flash */
    Fee_BlockStatusType eBlockStatus;   /**< @brief Current status of Fee block */
} Fee_BlockInfoType;

/**
 * @brief Information for the runtime
 */
typedef struct
{
	/**< @brief Internal state of Fee module */
	MemIf_StatusType Fee_eModuleStatus;

	/**< @brief Result of last Fee module job */
	MemIf_JobResultType Fee_eJobResult;

	/**< @brief Currently executed job (including internal one) */
	Fee_JobType Fee_eJob;

	/**< @brief Fee job which started internal management job(s) such as swap... */
	Fee_JobType Fee_eJobIntOriginalJob;

}Fee_InterRunInformationType;

/**
 * @brief Global variable type
 */
typedef struct
{
	/**< @brief Internal cluster group iterator. Used by the scan and swap jobs
	 *               Warning: do not use it outside scan and swap functions
	 *                        (because it will be Out of Range)
 	*/
	uint8 Fee_uJobIntClrGrpIt;

	/**< @brief Internal cluster iterator. Used by the scan and swap jobs */
	uint8 Fee_uJobIntClrIt;

	/**< @brief Fee block index. Used by all Fee jobs */
	uint16 Fee_uJobBlockIndex;

	/**< @brief Internal block iterator. Used by the swap job */
	uint16 Fee_uJobIntBlockIt;

	/**< @brief Fee block offset. Used by the read Fee job */
	Fls_LengthType Fee_uJobBlockOffset;

	/**< @brief Number of bytes to read. Used by the read Fee job */
	Fls_LengthType Fee_uJobBlockLength;

	/**< @brief Internal flash helper address iterator. Used by the scan and
	 *               swap jobs
	*/
	Fls_AddressType Fee_uJobIntAddrIt;

	/**< @brief Internal address of current block header. Used by the swap job */
	Fls_AddressType Fee_uJobIntHdrAddr;

	/**< @brief Internal address of current data block. Used by the swap job */
	Fls_AddressType Fee_uJobIntDataAddr;

}Fee_GlobalParType;


/*====================================================================================================*
 *                                    GLOBAL VARIABLE DECLARATIONS                                  
 *====================================================================================================*/

/* Add code here */

/*====================================================================================================*
 *                                        FUNCTION PROTOTYPES                                       
 *====================================================================================================*/

/* Add code here */

#ifdef __cplusplus
}
#endif

#endif /* FEE_INTERNAL_H */
/** @} */
