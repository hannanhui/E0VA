/**
 * @file        Fee_Cfg.h
 * @brief       AUTOSAR FEE_CFG - Fee_Cfg driver header file.
 * @details     Fee_Cfg driver header file, containing the Autosar API specification and
 *               other variables and functions that are exported by the Fee_Cfg driver.
 * @version     1.2.0
 * @addtogroup  FEE_CFG
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

#ifndef FEE_CFG_H
#define FEE_CFG_H

#ifdef __cplusplus
extern "C"{
#endif

/*====================================================================================================*
 *                                           INCLUDE FILES                                          
 *====================================================================================================*/

#include "MemIf_Types.h"
#include "Fls.h"

/*====================================================================================================*
 *                                  HEADER FILE VERSION INFORMATION                                 
 *====================================================================================================*/

#define FEE_CFG_VENDOR_ID                       0U
#define FEE_CFG_MODULE_ID                       21U
#define FEE_CFG_AR_RELEASE_MAJOR_VERSION        4U
#define FEE_CFG_AR_RELEASE_MINOR_VERSION        2U
#define FEE_CFG_AR_RELEASE_REVISION_VERSION     2U
#define FEE_CFG_SW_MAJOR_VERSION                1U
#define FEE_CFG_SW_MINOR_VERSION                2U
#define FEE_CFG_SW_PATCH_VERSION                0U

/*====================================================================================================*
 *                                         FILE VERSION CHECKS                                      
 *====================================================================================================*/

#ifndef DISABLE_INTERMOD_VERSION_CHECK

/* Check if current file and MemIf_Types header file are of the same Autosar version */ 
#if(\
        (FEE_CFG_AR_RELEASE_MAJOR_VERSION != MEMIF_TYPES_AR_RELEASE_MAJOR_VERSION) || \
        (FEE_CFG_AR_RELEASE_MINOR_VERSION != MEMIF_TYPES_AR_RELEASE_MINOR_VERSION) \
    )
#error "AutoSar Version Number of Fee_Cfg.h and MemIf_Types.h are different " 
#endif 

/* Check if current file and Fls header file are of the same Autosar version */ 
#if(\
        (FEE_CFG_AR_RELEASE_MAJOR_VERSION != FLS_AR_RELEASE_MAJOR_VERSION) || \
        (FEE_CFG_AR_RELEASE_MINOR_VERSION != FLS_AR_RELEASE_MINOR_VERSION) \
    )
#error "AutoSar Version Number of Fee_Cfg.h and Fls.h are different " 
#endif 

#endif/* DISABLE_INTERMOD_VERSION_CHECK */

/*====================================================================================================*
 *                                             CONSTANTS                                            
 *====================================================================================================*/

/* Add code here */

/*====================================================================================================*
 *                                         DEFINES AND MACROS                                       
 *====================================================================================================*/

/**
 * @brief Pre-processor switch to enable and disable development error detection
 */
#define FEE_DEV_ERROR_DETECT                (STD_OFF)

/**
 * @brief Pre-processor switch to enable / disable the API to read out the modules version information
 */
#define FEE_VERSION_INFO_API                (STD_OFF)

/**
 * @brief Compiler switch to enable/disable the SetMode functionality of the module
 */
#define FEE_SETMODE_API_SUPPORTED           (STD_OFF)

/**
 * @brief Pre-processor switch to enable /disable the Fls_Cancel function of the module
 */
#define FEE_CANCEL_API                     (STD_OFF)

/**
 * @brief The size in bytes to which logical blocks shall be aligned
 */
#define FEE_VIRTUAL_PAGE_SIZE               (16U)

/**
 * @brief Job end notification routine provided by the upper layer module
 */
#define FEE_NVM_JOB_END_NOTIFICATION        (STD_ON)

/**
 * @brief Job error notification routine provided by the upper layer module
 */
#define FEE_NVM_JOB_ERROR_NOTIFICATION        (STD_ON)

/**
 * @brief Pre-processor switch to enable and disable the polling mode for this module.
 */
#define FEE_POLLING_MODE                     (STD_OFF)

/**
 * @brief Number of configured Fee cluster groups
 */
#define FEE_NUMBER_OF_CLUSTER_GROUPS        (1U)

/**
 * @brief Number of configured Fee blocks
 */
#define FEE_NUMBER_OF_BLOCKS                (4U)

/**
 * @brief Management overhead per logical block in bytes
 */
#define FEE_BLOCK_OVERHEAD                  (48U)

/**
 * @brief Management overhead per logical cluster in bytes
 */
#define FEE_CLUSTER_OVERHEAD                (48U)

/**
 * @brief Size of the data buffer in bytes
 */
#define FEE_DATA_BUFFER_SIZE                (48U)

/**
 * @brief The contents of an erased flash memory cell
 */
#define FEE_ERASED_VALUE                    0xffU

/**
 * @brief Value of the block and cluster validation flag
 */
#define FEE_VALIDATED_VALUE                 0x81U

/**
 * @brief Value of the block and cluster invalidation flag
 */
#define FEE_INVALIDATED_VALUE               0x18U

/**
 * @brief Symbolic names of configured Fee blocks
 */
#define FeeConf_FeeBlockConfiguration_FeeBlockConfiguration_0    2U
#define FeeConf_FeeBlockConfiguration_FeeBlockConfiguration_1    3U
#define FeeConf_FeeBlockConfiguration_FeeBlockConfiguration_2    4U
#define FeeConf_FeeBlockConfiguration_FeeBlockConfiguration_3    5U

#define FEE_CONF_PB  extern CONST(Fee_ConfigType , AUTOMATIC) Fee_Config;

/*====================================================================================================*
 *                                               ENUMS                                              
 *====================================================================================================*/

/* Add code here */

/*====================================================================================================*
 *                                   STRUCTURES AND OTHER TYPEDEFS                                  
 *====================================================================================================*/

/* Add code here */

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

#endif /* FEE_CFG_H */
/** @} */













