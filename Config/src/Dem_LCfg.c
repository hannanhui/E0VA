/**
 * @file        Dem_LCfg.c
 * @brief       AUTOSAR Dem  - Dem configure source file.
 * @details     Dem configure source file.
 * @version     1.2.0
 *
 * @addtogroup  Dem
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
#include "Dem_Cfg.h"
#include "Dem.h"
#include "Dem_UserCallOut.h"

#if(DEM_NVRAM_BLOCKID_NUM > 0)
#include "NvM_Cfg.h"
#endif /* #if(DEM_NVRAM_BLOCKID_NUM > 0) */

/*====================================================================================================*
 *                                  SOURCE FILE VERSION INFORMATION                                 
 *====================================================================================================*/
#define DEM_LCFG_VENDOR_ID_C               				(0U)
#define DEM_LCFG_AR_RELEASE_MAJOR_VERSION_C      		(4U)
#define DEM_LCFG_AR_RELEASE_MINOR_VERSION_C      		(2U)
#define DEM_LCFG_AR_RELEASE_REVISION_VERSION_C          (2U)
#define DEM_LCFG_SW_MAJOR_VERSION_C      				(1U)
#define DEM_LCFG_SW_MINOR_VERSION_C      				(2U)
#define DEM_LCFG_SW_PATCH_VERSION_C      				(0U)
/*====================================================================================================*
 *                                         FILE VERSION CHECKS                                      
 *====================================================================================================*/
/* Check if current file and Dem_Cfg.h header file are of the same vendor */
#if(DEM_LCFG_VENDOR_ID_C != DEM_CFG_VENDOR_ID )
#error "Dem_LCfg.c and Dem_Cfg.h have different vendor id"
#endif /* #if(DEM_LCFG_VENDOR_ID_C != DEM_CFG_VENDOR_ID ) */

/* Check if current file and Dem_Cfg.h header file are of the same Autosar version */
#if(\
		(DEM_LCFG_AR_RELEASE_MAJOR_VERSION_C != DEM_CFG_AR_RELEASE_MAJOR_VERSION) || \
		(DEM_LCFG_AR_RELEASE_MINOR_VERSION_C != DEM_CFG_AR_RELEASE_MINOR_VERSION) || \
		(DEM_LCFG_AR_RELEASE_REVISION_VERSION_C != DEM_CFG_AR_RELEASE_REVISION_VERSION) \
   )
#error "AutoSar Version Number of Dem_LCfg.c and Dem_Cfg.h are different "
#endif /* #if(\
				(DEM_LCFG_AR_RELEASE_MAJOR_VERSION_C != DEM_CFG_AR_RELEASE_MAJOR_VERSION) || \
				(DEM_LCFG_AR_RELEASE_MINOR_VERSION_C != DEM_CFG_AR_RELEASE_MINOR_VERSION) || \
				(DEM_LCFG_AR_RELEASE_REVISION_VERSION_C != DEM_CFG_AR_RELEASE_REVISION_VERSION) \
   	   	     ) */

/* Check if current file and Dem_Cfg.h header file are of the same Software version */
#if(\
		(DEM_LCFG_SW_MAJOR_VERSION_C != DEM_CFG_SW_MAJOR_VERSION) || \
		(DEM_LCFG_SW_MINOR_VERSION_C != DEM_CFG_SW_MINOR_VERSION) || \
		(DEM_LCFG_SW_PATCH_VERSION_C != DEM_CFG_SW_PATCH_VERSION) \
   )
#error "Software Version Number of Dem_LCfg.c and Dem_Cfg.h are different "
#endif /* #if(\
				(DEM_LCFG_SW_MAJOR_VERSION_C != DEM_CFG_SW_MAJOR_VERSION) || \
				(DEM_LCFG_SW_MINOR_VERSION_C != DEM_CFG_SW_MINOR_VERSION) || \
				(DEM_LCFG_SW_PATCH_VERSION_C != DEM_CFG_SW_PATCH_VERSION) \
   	   	   	 ) */

/* Check if current file and Dem.h header file are of the same vendor */
#if(DEM_LCFG_VENDOR_ID_C != DEM_VENDOR_ID )
#error "Dem_LCfg.c and Dem.h have different vendor id"
#endif /* #if(DEM_LCFG_VENDOR_ID_C != DEM_VENDOR_ID ) */

/* Check if current file and Dem.h header file are of the same Autosar version */
#if(\
		(DEM_LCFG_AR_RELEASE_MAJOR_VERSION_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
		(DEM_LCFG_AR_RELEASE_MINOR_VERSION_C != DEM_AR_RELEASE_MINOR_VERSION) || \
		(DEM_LCFG_AR_RELEASE_REVISION_VERSION_C != DEM_AR_RELEASE_REVISION_VERSION) \
   )
#error "AutoSar Version Number of Dem_LCfg.c and Dem.h are different "
#endif /* #if(\
				(DEM_LCFG_AR_RELEASE_MAJOR_VERSION_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
				(DEM_LCFG_AR_RELEASE_MINOR_VERSION_C != DEM_AR_RELEASE_MINOR_VERSION) || \
				(DEM_LCFG_AR_RELEASE_REVISION_VERSION_C != DEM_AR_RELEASE_REVISION_VERSION) \
   	   	     ) */

/* Check if current file and Dem.h header file are of the same Software version */
#if(\
		(DEM_LCFG_SW_MAJOR_VERSION_C != DEM_SW_MAJOR_VERSION) || \
		(DEM_LCFG_SW_MINOR_VERSION_C != DEM_SW_MINOR_VERSION) || \
		(DEM_LCFG_SW_PATCH_VERSION_C != DEM_SW_PATCH_VERSION) \
   )
#error "Software Version Number of Dem_LCfg.c and Dem.h are different "
#endif /* #if(\
				(DEM_LCFG_SW_MAJOR_VERSION_C != DEM_SW_MAJOR_VERSION) || \
				(DEM_LCFG_SW_MINOR_VERSION_C != DEM_SW_MINOR_VERSION) || \
				(DEM_LCFG_SW_PATCH_VERSION_C != DEM_SW_PATCH_VERSION) \
   	   	   	 ) */

/* Check if current file and Dem_UserCallOut.h header file are of the same Autosar version */
#if(DEM_LCFG_VENDOR_ID_C != DEM_USERCALLOUT_VENDOR_ID )
#error "Dem_LCfg.c and Dem_UserCallOut.h have different vendor id"
#endif /* #if(DEM_LCFG_VENDOR_ID_C != DEM_USERCALLOUT_VENDOR_ID ) */

/* Check if current file and Dem_UserCallOut.h header file are of the same Autosar version */
#if(\
		(DEM_LCFG_AR_RELEASE_MAJOR_VERSION_C != DEM_USERCALLOUT_AR_RELEASE_MAJOR_VERSION) || \
		(DEM_LCFG_AR_RELEASE_MINOR_VERSION_C != DEM_USERCALLOUT_AR_RELEASE_MINOR_VERSION) || \
		(DEM_LCFG_AR_RELEASE_REVISION_VERSION_C != DEM_USERCALLOUT_AR_RELEASE_REVISION_VERSION) \
   )
#error "AutoSar Version Number of Dem_LCfg.c and Dem_UserCallOut.h are different "
#endif

/* Check if current file and Dem_UserCallOut.h header file are of the same Software version */
#if(\
		(DEM_LCFG_SW_MAJOR_VERSION_C != DEM_USERCALLOUT_SW_MAJOR_VERSION) || \
		(DEM_LCFG_SW_MINOR_VERSION_C != DEM_USERCALLOUT_SW_MINOR_VERSION) || \
		(DEM_LCFG_SW_PATCH_VERSION_C != DEM_USERCALLOUT_SW_PATCH_VERSION) \
   )
#error "Software Version Number of Dem_LCfg.c and Dem_UserCallOut.h are different "
#endif

#ifndef DISABLE_INTERMOD_VERSION_CHECK
#if(DEM_NVRAM_BLOCKID_NUM > 0)
/* Check if current file and NvM_Cfg.h header file are of the same Autosar version */
#if(\
		(DEM_LCFG_AR_RELEASE_MAJOR_VERSION_C != NVM_CFG_AR_RELEASE_MAJOR_VERSION) || \
		(DEM_LCFG_AR_RELEASE_MINOR_VERSION_C != NVM_CFG_AR_RELEASE_MINOR_VERSION) \
   )
#error "AutoSar Version Number of Dem_LCfg.c and NvM_Cfg.h are different "
#endif /* #if(\
				(DEM_LCFG_AR_RELEASE_MAJOR_VERSION_C != NVM_CFG_AR_RELEASE_MAJOR_VERSION) || \
				(DEM_LCFG_AR_RELEASE_MINOR_VERSION_C != NVM_CFG_AR_RELEASE_MINOR_VERSION) \
   	   	     ) */
#endif /* #if(DEM_NVRAM_BLOCKID_NUM > 0) */
#endif /* #ifndef DISABLE_INTERMOD_VERSION_CHECK */
/*====================================================================================================*
 *                                   EXTERNAL FUNCTION DECLARATIONS                                 
 *====================================================================================================*/

/*====================================================================================================*
 *                                           LOCAL TYPEDEFS                                         
 *====================================================================================================*/

/*====================================================================================================*
 *                                            LOCAL MACROS                                          
 *====================================================================================================*/

/*====================================================================================================*
 *                                           LOCAL CONSTANTS                                        
 *====================================================================================================*/

/*====================================================================================================*
 *                                           LOCAL VARIABLES                                        
 *====================================================================================================*/
#define DEM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Dem_MemMap.h"
CONST(Dem_OperationCycleType,AUTOMATIC) Dem_OperationCycles[DEM_OPERATION_CYCLE_NUM] =
{
    {FALSE,FALSE,DEM_OPCYC_POWER,0u}
};
#define DEM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Dem_MemMap.h"

#define DEM_START_SEC_CONFIG_DATA_16
#include "Dem_MemMap.h"
CONST(uint16,AUTOMATIC) Dem_NvRamBlockIds[DEM_NVRAM_BLOCKID_NUM] =
{
    NvMConf_NvMBlockDescriptor_NvMBlockDescriptor_1,
    NvMConf_NvMBlockDescriptor_NvMBlockDescriptor_1,
};
#define DEM_STOP_SEC_CONFIG_DATA_16
#include "Dem_MemMap.h"

#define DEM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Dem_MemMap.h"
CONST(Dem_EventParameterType,AUTOMATIC) Dem_EventParameters[DEM_EVENT_PARAMETER_NUM] =
{
    {
        /* DemEventAvailable */                     FALSE,
        /* DemFFPrestorageSupported */              FALSE,
        /* DemEventIsCombina */                     FALSE,
        /* DemEventFailureCycleCounterThreshold */  0u,
        /* DemEventKind */                          DEM_EVENT_KIND_BSW,
        /* DemReportBehavior */                     REPORT_BEFORE_INIT,
        /* DemOperationCycleRef */                  0u,
        /* DemDebounceAlgorithmClassType */         DEM_NONE_DEBOUNCE,
        /* DemDebounceAlgorithmRef */               0xFFFFu,
        /* DemDebounceInfoIndex */                  0xFFFFu,
        /* DemEventId */                            1u,
        /* DemOBDGroupingAssociativeEventsRef */    0xFFFFu,
    }
};
#define DEM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Dem_MemMap.h"

/*====================================================================================================*
 *                                      LOCAL FUNCTION PROTOTYPES                                   
 *====================================================================================================*/

/*====================================================================================================*
 *                                           LOCAL FUNCTIONS                                        
 *====================================================================================================*/

/*====================================================================================================*
 *                                          GLOBAL FUNCTIONS                                        
 *====================================================================================================*/
#define DEM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Dem_MemMap.h"

VAR(Dem_MemoryEntryType,DEM_VAR) DemPrimaryMemory[DEM_MAX_NUMBER_EVENTENTRY_PRIMARY];

VAR(Dem_MemoryEntryType,DEM_VAR) DemPermanentMemory[DEM_MAX_NUMBER_EVENTENTRY_PERMANENT];

#define DEM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Dem_MemMap.h"


#define DEM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Dem_MemMap.h"
CONST(Dem_GeneralType,AUTOMATIC)Dem_General =
{
    Dem_OperationCycles,
    Dem_NvRamBlockIds,
};
#define DEM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Dem_MemMap.h"

#define DEM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Dem_MemMap.h"
CONST(Dem_ConfigType, AUTOMATIC) Dem_Config =
{
    Dem_EventParameters,
};
#define DEM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Dem_MemMap.h"

#ifdef __cplusplus
}
#endif
/** @} */