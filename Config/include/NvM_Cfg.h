/**
 * @file        NvM_Cfg.h
 * @brief       AUTOSAR NVM_CFG - NvM_Cfg driver header file.
 * @details     NvM_Cfg driver header file, containing the Autosar API specification and
 *               other variables and functions that are exported by the NvM_Cfg driver.
 * @version     1.2.0
 *
 * @addtogroup  NvM_Cfg
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

#ifndef NVM_CFG_H
#define NVM_CFG_H

#ifdef __cplusplus
extern "C"{
#endif

/*====================================================================================================*
 *                                           INCLUDE FILES                                          
 *====================================================================================================*/

#include "NvM_Types.h"


/*====================================================================================================*
 *                                  HEADER FILE VERSION INFORMATION                                 
 *====================================================================================================*/

#define NVM_CFG_VENDOR_ID                      0U
#define NVM_CFG_AR_RELEASE_MAJOR_VERSION       4U
#define NVM_CFG_AR_RELEASE_MINOR_VERSION       2U
#define NVM_CFG_AR_RELEASE_REVISION_VERSION    2U
#define NVM_CFG_SW_MAJOR_VERSION               1U
#define NVM_CFG_SW_MINOR_VERSION               2U
#define NVM_CFG_SW_PATCH_VERSION               0U

/*====================================================================================================*
 *                                         FILE VERSION CHECKS                                      
 *====================================================================================================*/

/* Check if current file and NvM_Types.h header file are of the same vendor */
#if(NVM_CFG_VENDOR_ID != NVM_TYPES_VENDOR_ID )
#error "NvM_Cfg.h and NvM_Types.h have different vendor id"
#endif

/* Check if current file and NvM_Types.h header file are of the same Autosar version */
#if(\
		(NVM_CFG_AR_RELEASE_MAJOR_VERSION != NVM_TYPES_AR_RELEASE_MAJOR_VERSION) || \
		(NVM_CFG_AR_RELEASE_MINOR_VERSION != NVM_TYPES_AR_RELEASE_MINOR_VERSION) || \
		(NVM_CFG_AR_RELEASE_REVISION_VERSION != NVM_TYPES_AR_RELEASE_REVISION_VERSION) \
	)
#error "AutoSar Version Number of NvM_Cfg.h and NvM_Types.h are different "
#endif

/* Check if current file and NvM_Types.h header file are of the same software version */
#if(\
		(NVM_CFG_SW_MAJOR_VERSION != NVM_TYPES_SW_MAJOR_VERSION) || \
		(NVM_CFG_SW_MINOR_VERSION != NVM_TYPES_SW_MINOR_VERSION) || \
		(NVM_CFG_SW_PATCH_VERSION != NVM_TYPES_SW_PATCH_VERSION) \
	)
#error "Software Version Number of NvM_Cfg.h and NvM_Types.h are different "
#endif

/*====================================================================================================*
 *                                             CONSTANTS                                            
 *====================================================================================================*/

/* Add code here */

/*====================================================================================================*
 *                                         DEFINES AND MACROS                                       
 *====================================================================================================*/
/**
 * @brief API configuration class 1 macros
 */
#define NVM_API_CONFIG_CLASS_1	(0U)
/**
 * @brief API configuration class 2 macros
 */
#define NVM_API_CONFIG_CLASS_2	(1U)
/**
 * @brief API configuration class 3 macros
 */
#define NVM_API_CONFIG_CLASS_3	(2U)

/**
 * @brief API configuration of the current NvM module
 */
#define NVM_API_CONFIG_CLASS	NVM_API_CONFIG_CLASS_3

/**
 * @brief This macros specifies whether BswM is informed about the current
 * 		  status of the Block Status
 */
#define NVM_BSWM_BLOCKSTATUS_INFORMATION	(STD_OFF)

/**
 * @brief This macros specifies whether BswM is informed about the current
 * 		  status of the multiblock job
 */
#define NVM_BSWM_MULTIBLOCK_JOBSTATUS_INFORMATION	(STD_OFF)

/**
 * @brief The length of the CRC is calculated each time
 */
#define NVM_CRC_NUM_OF_BYTES	(16U)

/**
 * @brief Defines the number of least significant bits which shall be ussed to address a
 * 		  certain dataset of a NVRAM block within the interface to the memory hardware
 * 		  abstraction.
 */
#define NVM_DATASET_SELECTION_BITS	(1U)

/**
 * @brief Switches the Default Error Tracer detection and notification ON or OFF
 */
#define NVM_DEV_ERROR_DETECT	(STD_OFF)

/**
 * @brief Priority switch
 */
#define NVM_JOB_PRIORITIZATION	(STD_ON)

/**
 * @brief NvM_MainFunction Scheduling Cycle (Unit:ms)
 */
#define NVM_MAIN_FUNCTION_PERIOD	(10U)

/**
 * @brief Multi-block callback switch
 */
#define NVM_MULTI_BLOCK_CALLBACK	(STD_OFF)

/**
 * @brief NvM polling mode switch
 */
#define NVM_POLLING_MODE	(STD_OFF)

/**
 * @brief Number of image copy operations
 */
#define NVM_REPEAT_MIRROR_OPERATIONS	(0U)

/**
 * @brief NvM_SetRamBlockStatus interface switch
 */
#define NVM_SET_RAM_BLOCK_STATUS_API	(STD_ON)

/**
 * @brief Immediate block queue depth
 */
#define NVM_SIZE_IMMEDIATE_JOB_QUEUE	(5U)

/**
 * @brief Standard block queue depth
 */
#define NVM_SIZE_STANDARD_JOB_QUEUE	(5U)

/**
 * @brief NvM_GetVersionInfo interface switch
 */
#define NVM_VERSION_INFO_API	(STD_OFF)

/**
 * @brief DEM event switch
 */
#define NVM_DEM_EVENT_PARAMETERREFS (STD_OFF)

/**
 * @brief Mirror mechanism switch
 */
#define NVM_USE_MIRROR_MECHANISM       (STD_OFF)



/**
 * @brief Number of NVRAM block
 */
#define NVM_NUM_OF_BLOCK	(2U)

/**
 * @brief NvM module instance id
 */
#define NVM_INSTANCE_ID		(0U)

/**
 * @brief Maximum length of NVRAM
 */
#define NVM_MAX_NVRAM_LENGTH	(64U)

/**
 * @brief Configure the ID length
 */
#define NVM_CONFIGUREID_LENGTH 	(16U)

/**
 * @brief The maximum synchronization block length of NVM
 */
#define NVM_MAX_SYN_BLOCK_LENGTH  (0U)

#define NVM_CONF_PB \
extern CONST(NvM_ConfigType ,NvM_CONST) NvM_Config;

/**
 * @brief Invalid priority
 */
#define NVM_INVALID_JOB_PRIORITY    (0xFFU)

/**
 * @brief Identification of a NVRAM block via a unique block identifier
 */
#define NvMConf_NvMBlockDescriptor_NvMBlockDescriptor_0               ((NvM_BlockIdType)1U)
#define NvMConf_NvMBlockDescriptor_NvMBlockDescriptor_1               ((NvM_BlockIdType)2U)

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

#endif /* NVM_CFG_H */
/** @} */
