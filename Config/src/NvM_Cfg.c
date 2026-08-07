/**
 * @file        NvM_Cfg.c
 * @brief       AUTOSAR NVM_CFG  - NvM_Cfg driver source file.
 * @details     NvM_Cfg driver source file, containing the C implementation of Autosar API specification
 *              and other variables and functions that are exported by the NvM_Cfg driver.
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


#ifdef __cplusplus
extern "C"{
#endif

/*====================================================================================================*
 *                                           INCLUDE FILES                                          
 *====================================================================================================*/

#include "NvM.h"
#include "Std_Types.h"
#include "Fee_Cfg.h"
#include "NvM_RAM_ROM.h"

/*====================================================================================================*
 *                                  SOURCE FILE VERSION INFORMATION                                 
 *====================================================================================================*/

#define NVM_CFG_VENDOR_ID_C                      0U
#define NVM_CFG_AR_RELEASE_MAJOR_VERSION_C       4U
#define NVM_CFG_AR_RELEASE_MINOR_VERSION_C       2U
#define NVM_CFG_AR_RELEASE_REVISION_VERSION_C    2U
#define NVM_CFG_SW_MAJOR_VERSION_C               1U
#define NVM_CFG_SW_MINOR_VERSION_C               2U
#define NVM_CFG_SW_PATCH_VERSION_C               0U

/*====================================================================================================*
 *                                         FILE VERSION CHECKS                                      
 *====================================================================================================*/

/* Check if current file and NvM header file are of the same vendor */
#if(NVM_CFG_VENDOR_ID_C != NVM_VENDOR_ID )
#error "NvM_Cfg.c and NvM_Types.h have different vendor id"
#endif /* Check if current file and NvM header file are of the same Autosar version */
#if(\
		(NVM_CFG_AR_RELEASE_MAJOR_VERSION_C != NVM_AR_RELEASE_MAJOR_VERSION) || \
		(NVM_CFG_AR_RELEASE_MINOR_VERSION_C != NVM_AR_RELEASE_MINOR_VERSION) || \
		(NVM_CFG_AR_RELEASE_REVISION_VERSION_C != NVM_AR_RELEASE_REVISION_VERSION) \
	)
#error "AutoSar Version Number of NvM_Cfg.c and NvM.h are different "
#endif /* Check if current file and NvM header file are of the same Software version */
#if(\
		(NVM_CFG_SW_MAJOR_VERSION_C != NVM_SW_MAJOR_VERSION) || \
		(NVM_CFG_SW_MINOR_VERSION_C != NVM_SW_MINOR_VERSION) || \
		(NVM_CFG_SW_PATCH_VERSION_C != NVM_SW_PATCH_VERSION) \
	)
#error "Software Version Number of NvM_Cfg.c and NvM.h are different "
#endif

#ifndef DISABLE_INTERMOD_VERSION_CHECK

/* Check if current file and Std_Types header file are of the same vendor */
#if(\
		(NVM_CFG_AR_RELEASE_MAJOR_VERSION_C != STD_AR_RELEASE_MAJOR_VERSION) || \
		(NVM_CFG_AR_RELEASE_MINOR_VERSION_C != STD_AR_RELEASE_MINOR_VERSION) \
	)
#error "AutoSar Version Number of NvM_Cfg.c and Std_Types.h are different "
#endif /* Check if current file and Std_Types header file are of the same Software version */

/* Check if current file and Fee_Cfg header file are of the same vendor */
#if(\
		(NVM_CFG_AR_RELEASE_MAJOR_VERSION_C != FEE_CFG_AR_RELEASE_MAJOR_VERSION) || \
		(NVM_CFG_AR_RELEASE_MINOR_VERSION_C != FEE_CFG_AR_RELEASE_MINOR_VERSION) \
	)
#error "AutoSar Version Number of NvM_Cfg.c and Fee_Cfg.h are different "
#endif /* Check if current file and Fee_Cfg header file are of the same Software version */


#endif/* DISABLE_INTERMOD_VERSION_CHECK */
/*====================================================================================================*
 *                                   EXTERNAL FUNCTION DECLARATIONS                                 
 *====================================================================================================*/

/* Add code here */

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

/* Add code here */

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
#define NVM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "NvM_MemMap.h"

CONST(uint8, NVM_CONST) NvM_ConfigurationID[NVM_CONFIGUREID_LENGTH] = 
{
    65,
    246,
    59,
    214,
    51,
    93,
    19,
    148,
    19,
    6,
    252,
    172,
    41,
    130,
    243,
    166
};

#define NVM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "NvM_MemMap.h"


#define NVM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "NvM_MemMap.h"

CONST(NvM_BlockDescriptorType, NVM_CONST) NvM_BlockDescriptor[NVM_NUM_OF_BLOCK] =
{
/* NvMBlockDescriptor_0*/
	{
        NVM_CRC32,      /* NvM_CrcTypeOfBlock */
		1,  /* NvM_BlockJobPriority */
		NVM_BLOCK_REDUNDANT,  /* NvM_ManagementTypeofBlock */
		FALSE,           /* NvM_BlockUseAutoValidation */
		TRUE,        /*NvM_BlockUseCRCCompMechanism*/
		TRUE,        /* NvM_BlockUseCrc */
		TRUE,        /* NvM_BlockUseSetRamBlockStatus */
		FALSE,        /* NvM_BlockUseSyncMechanism */
        FALSE,        /* NvM_BlockWriteProt */
        FALSE,        /* NvM_BswMBlockStatusInformation */
        TRUE,        /* NvM_CalcRamBlockCrc */

        NULL_PTR,        /* NvM_InitBlockCallback */
        3,        /* NvM_MaxNumOfReadRetries */
        3,        /* NvM_MaxNumOfWriteRetries */
        1,        /* NvM_NvBlockBaseNumber */
        56,        /* NvM_NvBlockLength */
        2,        /* NvM_NvBlockNum */
        1,        /* NvM_NvramBlockIdentifier */
        0,        /* NvM_NvramDeviceId */
        (uint8*)RAM_0,        /* NvM_RamBlockDataAddress */

        NULL_PTR,                    /* NvM_ReadRamBlockFromNvCallback */
        FALSE,        /* NvM_ResistantToChangedSw */
        ROM_0,        /* NvM_RomBlockDataAddress */
        1,        /* NvM_RomBlockNum */
        TRUE,        /* NvM_SelectBlockForReadAll */
        TRUE,        /* NvM_SelectBlockForWriteAll */

        NULL_PTR,        /* NvM_SingleBlockCallback */
        TRUE,        /* NvM_StaticBlockIDCheck */
        FALSE,        /* NvM_WriteBlockOnce */

        NULL_PTR,        /* NvM_WriteRamBlockToNvCallback */
        TRUE,        /* NvM_WriteVerification */
        1,        /* NvM_WriteVerificationDataSize */
		FeeConf_FeeBlockConfiguration_FeeBlockConfiguration_0  /* NvM_EaOrFeeRef */
	},
/* NvMBlockDescriptor_1*/
	{
        NVM_CRC32,      /* NvM_CrcTypeOfBlock */
		1,  /* NvM_BlockJobPriority */
		NVM_BLOCK_NATIVE,  /* NvM_ManagementTypeofBlock */
		FALSE,           /* NvM_BlockUseAutoValidation */
		FALSE,        /*NvM_BlockUseCRCCompMechanism*/
		TRUE,        /* NvM_BlockUseCrc */
		TRUE,        /* NvM_BlockUseSetRamBlockStatus */
		FALSE,        /* NvM_BlockUseSyncMechanism */
        FALSE,        /* NvM_BlockWriteProt */
        FALSE,        /* NvM_BswMBlockStatusInformation */
        TRUE,        /* NvM_CalcRamBlockCrc */

        NULL_PTR,        /* NvM_InitBlockCallback */
        0,        /* NvM_MaxNumOfReadRetries */
        0,        /* NvM_MaxNumOfWriteRetries */
        2,        /* NvM_NvBlockBaseNumber */
        56,        /* NvM_NvBlockLength */
        1,        /* NvM_NvBlockNum */
        2,        /* NvM_NvramBlockIdentifier */
        0,        /* NvM_NvramDeviceId */
        (uint8*)RAM_1,        /* NvM_RamBlockDataAddress */

        NULL_PTR,                    /* NvM_ReadRamBlockFromNvCallback */
        TRUE,        /* NvM_ResistantToChangedSw */

        NULL_PTR,        /* NvM_RomBlockDataAddress */
        0,        /* NvM_RomBlockNum */
        TRUE,        /* NvM_SelectBlockForReadAll */
        TRUE,        /* NvM_SelectBlockForWriteAll */

        NULL_PTR,        /* NvM_SingleBlockCallback */
        TRUE,        /* NvM_StaticBlockIDCheck */
        FALSE,        /* NvM_WriteBlockOnce */

        NULL_PTR,        /* NvM_WriteRamBlockToNvCallback */
        FALSE,        /* NvM_WriteVerification */
        36,        /* NvM_WriteVerificationDataSize */
		FeeConf_FeeBlockConfiguration_FeeBlockConfiguration_2  /* NvM_EaOrFeeRef */
	}
};

#define NVM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "NvM_MemMap.h"


#define NVM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "NvM_MemMap.h"

CONST(NvM_ConfigType, NVM_CONST) NvM_Config =
{
#if (NVM_MULTI_BLOCK_CALLBACK == STD_ON)
	NULL_PTR, /* NvM_MultiBlockCallback */
#endif /* NVM_MULTI_BLOCK_CALLBACK == STD_ON */

	TRUE,  /* NvM_DynamicConfiguration */

	FALSE, /* NvM_DrvModeSwitch */

	NvM_ConfigurationID, /* NvM_ConfigurationID */

	NvM_BlockDescriptor /* NvM_BlockDescriptor */
};

#define NVM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "NvM_MemMap.h"

#ifdef __cplusplus
}
#endif
/** @} */