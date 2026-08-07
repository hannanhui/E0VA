/**
 * @file        Fee_Cfg.c
 * @brief       AUTOSAR FEE_CFG - Fee_Cfg driver source file.
 * @details     Fee_Cfg driver source file, containing the C implementation of Autosar API specification
 *              and other variables and functions that are exported by the Fee_Cfg driver.
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


#ifdef __cplusplus
extern "C"{
#endif

/*====================================================================================================*
 *                                           INCLUDE FILES                                          
 *====================================================================================================*/

#include "Fee.h"
#if((FEE_NVM_JOB_END_NOTIFICATION == STD_ON) || (FEE_NVM_JOB_ERROR_NOTIFICATION == STD_ON))
#include "NvM_Cbk.h"
#endif

/*====================================================================================================*
 *                                  SOURCE FILE VERSION INFORMATION                                 
 *====================================================================================================*/

#define FEE_CFG_VENDOR_ID_C                      0U
#define FEE_CFG_AR_RELEASE_MAJOR_VERSION_C       4U
#define FEE_CFG_AR_RELEASE_MINOR_VERSION_C       2U
#define FEE_CFG_AR_RELEASE_REVISION_VERSION_C    2U
#define FEE_CFG_SW_MAJOR_VERSION_C               1U
#define FEE_CFG_SW_MINOR_VERSION_C               2U
#define FEE_CFG_SW_PATCH_VERSION_C               0U

/*====================================================================================================*
 *                                         FILE VERSION CHECKS                                      
 *====================================================================================================*/

/* Check if current file and Fee header file are of the same vendor */
#if(FEE_CFG_VENDOR_ID_C != FEE_VENDOR_ID )
#error "Fee_Cfg.c and Fee.h have different vendor id"
#endif
/* Check if current file and Fee header file are of the same Autosar version */
#if(\
		(FEE_CFG_AR_RELEASE_MAJOR_VERSION_C != FEE_AR_RELEASE_MAJOR_VERSION) || \
		(FEE_CFG_AR_RELEASE_MINOR_VERSION_C != FEE_AR_RELEASE_MINOR_VERSION) || \
		(FEE_CFG_AR_RELEASE_REVISION_VERSION_C != FEE_AR_RELEASE_REVISION_VERSION) \
	)
#error "AutoSar Version Number of Fee_Cfg.c and Fee.h are different "
#endif
/* Check if current file and Fee header file are of the same Software version */
#if(\
		(FEE_CFG_SW_MAJOR_VERSION_C != FEE_SW_MAJOR_VERSION) || \
		(FEE_CFG_SW_MINOR_VERSION_C != FEE_SW_MINOR_VERSION) || \
        (FEE_CFG_SW_PATCH_VERSION_C != FEE_SW_PATCH_VERSION) \
	)
#error "Software Version Number of Fee_Cfg.c and Fee.h are different "
#endif

#ifndef DISABLE_INTERMOD_VERSION_CHECK

#if((FEE_NVM_JOB_END_NOTIFICATION == STD_ON) || (FEE_NVM_JOB_ERROR_NOTIFICATION == STD_ON))
/* Check if current file and NvM_Cbk header file are of the same Autosar version */ 
#if(\
        (FEE_CFG_AR_RELEASE_MAJOR_VERSION_C != NVM_CBK_AR_RELEASE_MAJOR_VERSION) || \
        (FEE_CFG_AR_RELEASE_MINOR_VERSION_C != NVM_CBK_AR_RELEASE_MINOR_VERSION) \
    )
#error "AutoSar Version Number of Fee_Cfg.c and NvM_Cbk.h are different " 
#endif 
#endif 

#endif /* DISABLE_INTERMOD_VERSION_CHECK */

/*====================================================================================================*
 *                                   EXTERNAL FUNCTION DECLARATIONS                                 
 *====================================================================================================*/



/*====================================================================================================*
 *                                           LOCAL TYPEDEFS                                         
 *====================================================================================================*/

/* Add code here */

/*====================================================================================================*
 *                                            LOCAL MACROS                                          
 *====================================================================================================*/

/* Add code here */

/*====================================================================================================*
 *                                           LOCAL CONSTANTS                                        
 *====================================================================================================*/

/* Add code here */

/*====================================================================================================*
 *                                           LOCAL VARIABLES                                        
 *====================================================================================================*/
#define FEE_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Fee_MemMap.h"

/* Configuration of cluster group FeeClusterGroup_0 */
CONST(Fee_ClusterConfigType , AUTOMATIC) Fee_FeeClusterGroup_0[2] =
{
    /* FeeCluster_0 */
    {
        0,  /* Start address */
        4096,  /* Size */
    },
    /* FeeCluster_1 */
    {
        4096,  /* Start address */
        4096,  /* Size */
    }
};

#define FEE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Fee_MemMap.h"


#define FEE_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Fee_MemMap.h"

/* Configuration of cluster group set */
CONST(Fee_ClusterGroupConfigType , AUTOMATIC) Fee_ClrGrps[FEE_NUMBER_OF_CLUSTER_GROUPS] =
{
    /* FeeClusterGroup_0 */
    {
        2,   /* Number of clusters */
        0,   /* Size of the reserved area */
        Fee_FeeClusterGroup_0  /* Cluster set */
    }
};

#define FEE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Fee_MemMap.h"


#define FEE_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Fee_MemMap.h"

/* Configuration of Fee blocks */
CONST(Fee_BlockConfigType , AUTOMATIC) Fee_BlockConfig[FEE_NUMBER_OF_BLOCKS] =
{
    /* FeeBlockConfiguration_0 */
    {
        0,    /* FeeClusterGroup */
        (boolean)FALSE,   /* FeeImmediateData */
        FeeConf_FeeBlockConfiguration_FeeBlockConfiguration_0,    /* FeeBlockNumber */
        64,   /* FeeBlockSize */
        0  /* FeeNumberOfWriteCycles */
    },
    /* FeeBlockConfiguration_1 */
    {
        0,    /* FeeClusterGroup */
        (boolean)FALSE,   /* FeeImmediateData */
        FeeConf_FeeBlockConfiguration_FeeBlockConfiguration_1,    /* FeeBlockNumber */
        64,   /* FeeBlockSize */
        0  /* FeeNumberOfWriteCycles */
    },
    /* FeeBlockConfiguration_2 */
    {
        0,    /* FeeClusterGroup */
        (boolean)FALSE,   /* FeeImmediateData */
        FeeConf_FeeBlockConfiguration_FeeBlockConfiguration_2,    /* FeeBlockNumber */
        64,   /* FeeBlockSize */
        0  /* FeeNumberOfWriteCycles */
    },
    /* FeeBlockConfiguration_3 */
    {
        0,    /* FeeClusterGroup */
        (boolean)FALSE,   /* FeeImmediateData */
        FeeConf_FeeBlockConfiguration_FeeBlockConfiguration_3,    /* FeeBlockNumber */
        64,   /* FeeBlockSize */
        0  /* FeeNumberOfWriteCycles */
    }
};

#define FEE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Fee_MemMap.h"


#define FEE_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Fee_MemMap.h"

CONST(Fee_ConfigType , AUTOMATIC) Fee_Config =
{
    Fee_ClrGrps,  /* Fee_ClusterGroupConfig */

    Fee_BlockConfig,  /* Fee_BlockConfig */

#if(FEE_NVM_JOB_END_NOTIFICATION == STD_ON)
	NvM_JobEndNotification,  /* FeeNvmJobEndNotification */
#endif

#if(FEE_NVM_JOB_ERROR_NOTIFICATION == STD_ON)
	NvM_JobErrorNotification  /* FeeNvmJobErrorNotification */
#endif
};

#define FEE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Fee_MemMap.h"
/*====================================================================================================*
 *                                      LOCAL FUNCTION PROTOTYPES                                   
 *====================================================================================================*/

/* Add code here */

/*====================================================================================================*
 *                                           LOCAL FUNCTIONS                                        
 *====================================================================================================*/

/* Add code here */

/*====================================================================================================*
 *                                          GLOBAL FUNCTIONS                                        
 *====================================================================================================*/

/* Add code here */

#ifdef __cplusplus
}
#endif
/** @} */
