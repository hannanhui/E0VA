/**
 * @file        Fee.h
 * @brief       AUTOSAR FEE - Fee driver header file.
 * @details     Fee driver header file, containing the Autosar API specification and
 *               other variables and functions that are exported by the Fee driver.
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

#ifndef FEE_H
#define FEE_H

#ifdef __cplusplus
extern "C"{
#endif

/*====================================================================================================*
 *                                           INCLUDE FILES                                          
 *====================================================================================================*/

#include "Fee_Cfg.h"
#include "Std_Types.h"

/*====================================================================================================*
 *                                  HEADER FILE VERSION INFORMATION                                 
 *====================================================================================================*/

#define FEE_VENDOR_ID            		 0U
#define FEE_MODULE_ID            		 21U
#define FEE_AR_RELEASE_MAJOR_VERSION     4U
#define FEE_AR_RELEASE_MINOR_VERSION     2U
#define FEE_AR_RELEASE_REVISION_VERSION  2U
#define FEE_SW_MAJOR_VERSION             1U
#define FEE_SW_MINOR_VERSION             2U
#define FEE_SW_PATCH_VERSION             0U

/*====================================================================================================*
 *                                         FILE VERSION CHECKS                                      
 *====================================================================================================*/
/* Check if current file and Fee_Cfg header file are of the same vendor */
#if (FEE_VENDOR_ID != FEE_CFG_VENDOR_ID)
    #error "Fee.h and Fee_Cfg.h have different vendor id"
#endif
/* Check if current file and Fee_Cfg header file are of the same Autosar version */
#if (\
		(FEE_AR_RELEASE_MAJOR_VERSION    != FEE_CFG_AR_RELEASE_MAJOR_VERSION) || \
		(FEE_AR_RELEASE_MINOR_VERSION    != FEE_CFG_AR_RELEASE_MINOR_VERSION) || \
		(FEE_AR_RELEASE_REVISION_VERSION != FEE_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Fee.h and Fee_Cfg.h are different"
#endif
/* Check if current file and Fee_Cfg header file are of the same software version */
#if (\
		(FEE_SW_MAJOR_VERSION != FEE_CFG_SW_MAJOR_VERSION) || \
		(FEE_SW_MINOR_VERSION != FEE_CFG_SW_MINOR_VERSION) || \
		(FEE_SW_PATCH_VERSION != FEE_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Fee.h and Fee_Cfg.h are different"
#endif

#ifndef DISABLE_INTERMOD_VERSION_CHECK

/* Check if current file and Std_Types header file are of the same Autosar version */
#if (\
		(FEE_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
		(FEE_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION) \
    )
    #error "AutoSar Version Numbers of Fee.h and Std_Types.h are different"
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
* @brief        All service IDs (passed to DET)
*/
/** @brief service ID of function: Fee_Init. */
#define FEE_INIT_ID                    0x00U
/** @brief service ID of function: Fee_SetMode. */
#define FEE_SETMODE_ID                 0x01U
/** @brief service ID of function: Fee_Read. */
#define FEE_READ_ID                    0x02U
/** @brief service ID of function: Fee_Write. */
#define FEE_WRITE_ID                   0x03U
/** @brief service ID of function: Fee_Cancel. */
#define FEE_CANCEL_ID                  0x04U
/** @brief service ID of function: Fee_GetStatus. */
#define FEE_GETSTATUS_ID               0x05U
/** @brief service ID of function: Fee_GetJobResult. */
#define FEE_GETJOBRESULT_ID            0x06U
/** @brief service ID of function: Fee_InvalidateBlock. */
#define FEE_INVALIDATEBLOCK_ID         0x07U
/** @brief service ID of function: Fee_GetVersionInfo. */
#define FEE_GETVERSIONINFO_ID          0x08U
/** @brief service ID of function: Fee_EraseImmediateBlock. */
#define FEE_ERASEIMMEDIATEBLOCK_ID     0x09U
/** @brief service ID of function: Fee_JobEndNotification. */
#define FEE_JOBENDNOTIFICATION_ID      0x10U
/** @brief service ID of function: Fee_JobErrorNotification. */
#define FEE_JOBERRORNOTIFICATION_ID    0x11U
/** @brief service ID of function: Fee_MainFunction. */
#define FEE_MAINFUNCTION_ID            0x12U
/* Vendor specific API */
/** @brief service ID of function: Fee_GetRunTimeInfo. */
#define FEE_GETRUNTIMEINFO_ID          0x13U
/** @brief service ID of function: Fee_ForceSwapOnNextWrite. */
#define FEE_FORCESWAPONNEXTWRITE_ID    0x14U

/**
* @brief        Development error codes (passed to DET)
*
*/
/** @brief API called when module was not initialized */
#define FEE_E_UNINIT                  0x01U
/** @brief API called with invalid block number */
#define FEE_E_INVALID_BLOCK_NO        0x02U
/** @brief API called with invalid block offset */
#define FEE_E_INVALID_BLOCK_OFS       0x03U
/** @brief API called with invalid data pointer */
#define FEE_E_PARAM_POINTER           0x04U
/** @brief API called with invalid length information */
#define FEE_E_INVALID_BLOCK_LEN       0x05U
/** @brief API called while module is busy processing a user request */
#define FEE_E_BUSY                    0x06U
/** @brief API called while module is busy doing internal management operations */
#define FEE_E_BUSY_INTERNAL           0x07U
/** @brief API called while module is not busy because there is no job to cancel */
#define FEE_E_INVALID_CANCEL          0x08U
/** @brief API Fee_init failed */
#define FEE_E_INIT_FAILED             0x09U
/* Vendor Specific Define */
/** @brief API called when underlying driver has cancel API disabled */
#define FEE_E_CANCEL_API              0x0AU
/** @brief API called with invalid cluster group index */
#define FEE_E_CLUSTER_GROUP_IDX       0x0BU
/** @brief API number of foreign blocks from data flash exceeds the total number
    of blocks allowed which is FEE_MAX_NR_OF_BLOCKS */
#define FEE_E_FOREIGN_BLOCKS_OVF      0x0CU


/*====================================================================================================*
 *                                               ENUMS                                              
 *====================================================================================================*/
/**
* @brief Fee block assignment type
* @api
*/
typedef enum
{
    FEE_PROJECT_SHARED          = 0x01,     /** block is used for all the projects */
    FEE_PROJECT_APPLICATION     = 0x02,     /** block is used for the application project */
    FEE_PROJECT_BOOTLOADER      = 0x03,     /** block is used for the bootloader project */
    FEE_PROJECT_RESERVED        = 0xFF      /** the value is reserved */
} Fee_BlockAssignmentType;

/*====================================================================================================*
 *                                   STRUCTURES AND OTHER TYPEDEFS                                  
 *====================================================================================================*/
/**
 * @brief Array of Fee cluster configurations
 */
typedef struct
{
	 /**< @brief Address of Fee cluster in flash */
	CONST(uint32, FEE_CONFIG_DATA) Fee_ClrStartAddr;

	 /**< @brief Size of Fee cluster in bytes */
	CONST(uint32, FEE_CONFIG_DATA) Fee_Clrlength;

} Fee_ClusterConfigType;

/**
 * @brief Fee cluster group configuration structure
 */
typedef struct
{
	/**< @brief Number of clusters in cluster group */
	CONST(uint16, FEE_CONFIG_DATA) Fee_ClusterCounter;

	/**< @brief Size of reserved area in the given cluster group */
	CONST(uint32, FEE_CONFIG_DATA) Fee_reservedSize;

	/**< @brief Pointer to array of Fee cluster configurations */
	P2CONST(Fee_ClusterConfigType , FEE_CONST, FEE_APPL_CONST) Fee_ClusterConfig;

} Fee_ClusterGroupConfigType;

/**
 * @brief Configuration of block specific parameters for the Flash EEPROM Emulation module.
 */
typedef struct
{
	/**< @brief Current cluster index. */
	CONST(uint8, FEE_CONFIG_DATA)  FeeClrGrpIndex;

	/**< @brief Marker for high priority data. */
	CONST(boolean, FEE_CONFIG_DATA) FeeImmediateData;

	/**< @brief Block identifier (handle) */
	CONST(uint16, FEE_CONFIG_DATA) FeeBlockNumber;

	/**< @brief Size of a logical block in bytes. */
	CONST(uint16, FEE_CONFIG_DATA) FeeBlockSize;

	/**< @brief Number of write cycles required for this block. */
	CONST(uint32, FEE_CONFIG_DATA) FeeNumberOfWriteCycles;

} Fee_BlockConfigType;

#if(FEE_NVM_JOB_END_NOTIFICATION == STD_ON)
/**
 * @brief Mapped to the job end notification routine provided by the upper layer module
 */
typedef P2FUNC(void, FEE_APPL_CODE, Fee_NvM_JobEndNotificationType)(void);
#endif

#if(FEE_NVM_JOB_ERROR_NOTIFICATION == STD_ON)
/**
 * @brief Mapped to the job error notification routine provided by the upper layer module
 */
typedef P2FUNC(void, FEE_APPL_CODE, Fee_NvM_JobErrorNotificationType)(void);
#endif

/**
 * @brief Configuration data structure of the Fee module.
 */
typedef struct
{
	/**< @brief Fee cluster group configuration structure */
	P2CONST(Fee_ClusterGroupConfigType , FEE_CONST, FEE_APPL_CONST) Fee_ClusterGroupConfig;

	/**< @brief Configuration of block specific parameters for the Flash EEPROM Emulation module. */
	P2CONST(Fee_BlockConfigType , FEE_CONST, FEE_APPL_CONST) Fee_BlockConfig;

#if(FEE_NVM_JOB_END_NOTIFICATION == STD_ON)
	/**< @brief Mapped to the job end notification routine provided by the upper layer module. */
	Fee_NvM_JobEndNotificationType Fee_NvM_JobEndNotification;
#endif

#if(FEE_NVM_JOB_ERROR_NOTIFICATION == STD_ON)
	/**< @brief Mapped to the job error notification routine provided by the upper layer module. */
	Fee_NvM_JobErrorNotificationType Fee_NvM_JobErrorNotification;
#endif

} Fee_ConfigType;

/*====================================================================================================*
 *                                    GLOBAL VARIABLE DECLARATIONS                                  
 *====================================================================================================*/

FEE_CONF_PB

/* PRQA S 0781 EOF #violate MISAR2004_5.6: Need to use this parameter*/
extern CONST(Fee_BlockConfigType , AUTOMATIC) Fee_BlockConfig[FEE_NUMBER_OF_BLOCKS];

extern CONST(Fee_ClusterGroupConfigType , AUTOMATIC) Fee_ClrGrps[FEE_NUMBER_OF_CLUSTER_GROUPS];
/*====================================================================================================*
 *                                        FUNCTION PROTOTYPES                                       
 *====================================================================================================*/
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"

FUNC( void, FEE_CODE ) Fee_Init(P2CONST( Fee_ConfigType, AUTOMATIC, FEE_APPL_CONST ) paConfigPtr);

#if( FEE_SETMODE_API_SUPPORTED == STD_ON )
FUNC( void, FEE_CODE ) Fee_SetMode( VAR( MemIf_ModeType, AUTOMATIC ) eMode );
#endif /* FEE_SETMODE_API_SUPPORTED == STD_ON */

FUNC( Std_ReturnType, FEE_CODE ) Fee_Read
    (
        VAR( uint16, AUTOMATIC ) uBlockNumber,
        VAR( uint16, AUTOMATIC ) uBlockOffset,
        P2VAR( uint8, AUTOMATIC, FEE_APPL_DATA ) pDataBufferPtr,
        VAR( uint16, AUTOMATIC ) uLength
    );

FUNC( Std_ReturnType, FEE_CODE ) Fee_Write
   (
       VAR( uint16, AUTOMATIC ) uBlockNumber,
       P2CONST( uint8, AUTOMATIC, FEE_APPL_CONST ) pDataBufferPtr
   );

FUNC( void, FEE_CODE ) Fee_Cancel( void );

FUNC( MemIf_StatusType, FEE_CODE ) Fee_GetStatus( void );

FUNC( MemIf_JobResultType, FEE_CODE ) Fee_GetJobResult( void );

FUNC( Std_ReturnType, FEE_CODE ) Fee_InvalidateBlock
    (
        VAR( uint16, AUTOMATIC ) uBlockNumber
    );

#if( FEE_VERSION_INFO_API == STD_ON )
FUNC( void, FEE_CODE ) Fee_GetVersionInfo
    (
        P2VAR( Std_VersionInfoType, AUTOMATIC, FEE_APPL_DATA ) pVersionInfoPtr
    );
#endif /* FEE_VERSION_INFO_API == STD_ON */

FUNC( Std_ReturnType, FEE_CODE ) Fee_EraseImmediateBlock
    (
        VAR( uint16, AUTOMATIC ) uBlockNumber
    );

FUNC( void, FEE_CODE ) Fee_MainFunction( void );

#ifdef AH_TEST_FEE
FUNC(void, FEE_CODE) Fee_DeInit();
#endif

#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* FEE_H */
/** @} */
