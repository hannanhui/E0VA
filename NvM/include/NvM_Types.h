/**
 * @file        NvM_Types.h
 * @brief       AUTOSAR NvM - NvM driver header file.
 * @details     NvM driver header file, containing the Autosar API specification and
 *               other variables and functions that are exported by the NvM driver.
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
 * is not permitted without prior written authorization.
 *====================================================================================================*/

#ifndef NVM_TYPES_H
#define NVM_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif

/*====================================================================================================*
 *                                           INCLUDE FILES                                          
 *====================================================================================================*/
/* @todo Not at this time */
/* #include "Rte_NvM_Type.h" */
#include "Std_Types.h"

/*====================================================================================================*
 *                                  SOURCE FILE VERSION INFORMATION                                 
 *====================================================================================================*/
#define NVM_TYPES_VENDOR_ID                      0U
#define NVM_TYPES_AR_RELEASE_MAJOR_VERSION       4U
#define NVM_TYPES_AR_RELEASE_MINOR_VERSION       2U
#define NVM_TYPES_AR_RELEASE_REVISION_VERSION    2U
#define NVM_TYPES_SW_MAJOR_VERSION               1U
#define NVM_TYPES_SW_MINOR_VERSION               2U
#define NVM_TYPES_SW_PATCH_VERSION               0U

/*====================================================================================================*
 *                                         FILE VERSION CHECKS                                      
 *====================================================================================================*/

#ifndef DISABLE_INTERMOD_VERSION_CHECK

/* Check if current file and Std_Types.h header file are of the same Autosar version */
#if(\
		(NVM_TYPES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
		(NVM_TYPES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION) \
		)
#error "AutoSar Version Number of NvM_Types.h and Std_Types.h are different "
#endif

#endif /* DISABLE_INTERMOD_VERSION_CHECK */

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
 * @brief The type NvM_RequestResultType is an asynchronous request result
 * @req [SWS_NvM_00470]
 */
typedef enum
{
	/**< @brief The last asynchronous request has been finished successfully.
	 * This shall be the default value after reset. This status shall have the value 0. */
	NVM_REQ_OK = 0U,
	/**< @brief The last asynchronous read/write/control request has been finished unsuccessfully. */
	NVM_REQ_NOT_OK,
	/**< @brief An asynchronous read/write/control request is currently pending. */
	NVM_REQ_PENDING,
	/**< @brief The result of the last asynchronous request NvM_ReadBlock or NvM_ReadAll
	 * is a data integrity failure */
	NVM_REQ_INTEGRITY_FAILED,
	/**< @brief The referenced block was skipped during execution of NvM_ReadAll or NvM_WriteAll,
	 * e.g. Dataset NVRAM blocks (NvM_ReadAll) or NVRAM blocks without a permanently configured
	 * RAM block */
	NVM_REQ_BLOCK_SKIPPED,
	/**< @brief The referenced NV block is invalidated. */
	NVM_REQ_NV_INVALIDATED,
	/**< @brief The multi block request NvM_WriteAll was canceled by calling NvM_CancelWriteAll.Or
	 * Any single block job request (NvM_ReadBlock, NvM_WriteBlock, NvM_EraseNvBlock,
	 * NvM_InvalidateNvBlock and NvM_RestoreBlockDefaults) was canceled by calling NvM_CancelJobs. */
	NVM_REQ_CANCELED,
	/**< @brief The required redundancy of the referenced NV block is lost */
	NVM_REQ_REDUNDANCY_FAILED,
	/**< @brief The referenced NV block had the default values copied to the RAM image. */
	NVM_REQ_RESTORED_FROM_ROM
}NvM_RequestResultType;

/*====================================================================================================*
 *                                   STRUCTURES AND OTHER TYPEDEFS                                  
 *====================================================================================================*/
/**
 * @brief Identification of a NVRAM block via a unique block identifier. Reserved NVRAM block IDs:
 * 		  0 -> to derive multi block request results via NvM_GetErrorStatus
 * 		  1 -> redundant NVRAM block which holds the configuration ID
 * @req [SWS_NvM_00471]
 */
typedef uint16 NvM_BlockIdType;

/*====================================================================================================*
 *                                    GLOBAL VARIABLE DECLARATIONS                                  
 *====================================================================================================*/

/*====================================================================================================*
 *                                        FUNCTION PROTOTYPES                                       
 *====================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* NVM_TYPES_H */
/** @} */
