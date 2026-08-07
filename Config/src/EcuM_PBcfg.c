/**
 *  @file     EcuM_PBCfg.c
 *  @brief    AUTOSAR EcuM  - EcuM driver source file.
 *  @details  EcuM driver source file, containing the C implementation of Autosar API specification
 *            and other variables and functions that are exported by the EcuM driver.
 *  @version  1.2.0
 *
 * @addtogroup  EcuM
 * @{
 */
/*====================================================================================================*
 * AngHui AUTOSAR BSW.
 *
 * Copyright(C) 2026 GuoKeAngHui Inc.
 *
 * All rights reserved.
 *
 * This file is part of AngHui AUTOSAR BSW, contains proprietary information.
 * Passing on and copying of this document, and communication of its contents
 * is not permitted without prior written authorization.
 *====================================================================================================*/
#if defined(__cplusplus)
extern "C"
{
#endif /* defined(__cplusplus) */

/*====================================================================================================*
 *                                           INCLUDE FILES                                          
 *====================================================================================================*/
#include "EcuM.h"

//#include "Os.h"
#include "Mcu.h"
 
 
 
 
 
#include "ComM.h"
  
 
/*====================================================================================================*
 *                                  SOURCE FILE VERSION INFORMATION                                 
 *====================================================================================================*/

#define ECUM_PBCFG_VENDOR_ID_C                           0U
#define ECUM_PBCFG_SW_MAJOR_VERSION_C                    1U
#define ECUM_PBCFG_SW_MINOR_VERSION_C                    2U
#define ECUM_PBCFG_SW_PATCH_VERSION_C                    0U
#define ECUM_PBCFG_AR_RELEASE_MAJOR_VERSION_C            4U
#define ECUM_PBCFG_AR_RELEASE_MINOR_VERSION_C            2U
#define ECUM_PBCFG_AR_RELEASE_REVISION_VERSION_C         2U

/*====================================================================================================*
 *                                         FILE VERSION CHECKS                                      
 *====================================================================================================*/

/* Check if current file and EcuM header file are of the same vendor */
#if(ECUM_PBCFG_VENDOR_ID_C != ECUM_VENDOR_ID )
#error "EcuM_PBcfg.c and EcuM.h have different vendor id"
#endif
/* Check if current file and EcuM header file are of the same Autosar version */
#if(\
        (ECUM_PBCFG_AR_RELEASE_MAJOR_VERSION_C != ECUM_AR_RELEASE_MAJOR_VERSION) || \
        (ECUM_PBCFG_AR_RELEASE_MINOR_VERSION_C != ECUM_AR_RELEASE_MINOR_VERSION) || \
        (ECUM_PBCFG_AR_RELEASE_REVISION_VERSION_C != ECUM_AR_RELEASE_REVISION_VERSION) \
    )
#error "AutoSar Version Number of EcuM_PBcfg.c and EcuM.h are different "
#endif
/* Check if current file and EcuM header file are of the same software version */
#if(\
        (ECUM_PBCFG_SW_MAJOR_VERSION_C != ECUM_SW_MAJOR_VERSION) || \
        (ECUM_PBCFG_SW_MINOR_VERSION_C != ECUM_SW_MINOR_VERSION) || \
        (ECUM_PBCFG_SW_PATCH_VERSION_C != ECUM_SW_PATCH_VERSION) \
    )
#error "Software Version Number of EcuM_PBcfg.c and EcuM.h are different "
#endif

#ifndef DISABLE_INTERMOD_VERSION_CHECK
/* Check if current file and Os header file are of the same Autosar version */
#if(\
        (ECUM_PBCFG_AR_RELEASE_MAJOR_VERSION_C != OS_AR_RELEASE_MAJOR_VERSION) || \
        (ECUM_PBCFG_AR_RELEASE_MINOR_VERSION_C != OS_AR_RELEASE_MINOR_VERSION)  \
    )
#error "AutoSar Version Number of EcuM_PBcfg.c and Os.h are different "
#endif

/* Check if current file and Mcu header file are of the same Autosar version */
#if(\
        (ECUM_PBCFG_AR_RELEASE_MAJOR_VERSION_C != MCU_AR_RELEASE_MAJOR_VERSION) || \
        (ECUM_PBCFG_AR_RELEASE_MINOR_VERSION_C != MCU_AR_RELEASE_MINOR_VERSION)  \
    )
#error "AutoSar Version Number of EcuM_PBcfg.c and Mcu.h are different "
#endif

/* Check if current file and ComM header file are of the same Autosar version */
#if(\
        (ECUM_PBCFG_AR_RELEASE_MAJOR_VERSION_C != COMM_AR_RELEASE_MAJOR_VERSION) || \
        (ECUM_PBCFG_AR_RELEASE_MINOR_VERSION_C != COMM_AR_RELEASE_MINOR_VERSION)  \
    )
/*#error "AutoSar Version Number of EcuM_PBcfg.c and ComM.h are different "*/
#endif
 
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

/*====================================================================================================*
 *                                      LOCAL FUNCTION PROTOTYPES                                   
 *====================================================================================================*/

/*====================================================================================================*
 *                                           LOCAL FUNCTIONS                                        
 *====================================================================================================*/

/*====================================================================================================*
 *                                          GLOBAL FUNCTIONS                                        
 *====================================================================================================*/
#define ECUM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "EcuM_MemMap.h"
static CONST(EcuM_DefaultShutdownTargetType, ECUM_CONST) EcuM_DefaultShutdownTarget =
{
    /* EcuM_DefaultState */
    ECUM_SHUTDOWN_TARGET_SLEEP,
    /* EcuM_DefaultShutdownMode */
    EcuMConf_EcuMSleepMode_EcuMSleepMode_0
};


static CONST(EcuM_SleepModeType, ECUM_CONST) EcuM_SleepMode[ECUM_SLEEP_MODE_NUM] =
{
    {
        /* EcuM_SleepModeId */
        EcuMConf_EcuMSleepMode_EcuMSleepMode_0,
        /* EcuM_SleepModeSuspend */
        FALSE,
        /* EcuM_SleepModeMcuModeRef */
        McuConf_McuModeSettingConf_McuModeSettingConf_0,
        /* EcuM_WakeupSourceMask */
        EcuMConf_EcuMWakeupSource_EcuMWakeupSource_SW_Wake_Up
    }
 
};


       



static CONST(EcuM_WakeupSourceCfgType, ECUM_CONST) EcuM_WakeupSource[ECUM_WAKEUP_SOURCE_NUM] =
{
    {
        /* EcuM_WakeupSourcePolling */
        TRUE,
        /* EcuM_ComMChannelRef */
        ECUM_INVALID_COMM_CHANNEL,
        /* EcuM_NumberOfResetReason */
        0U,
        /* EcuM_CheckWakeupTimeout Unit: [ms]*/
        0U,
        /* EcuM_ValidationTimeout Unit: [ms]*/
        0U,
        /* EcuM_WakeupSourceMask */
        (uint32)1,
        /* EcuM_ResetReasonRefPtr */
        NULL_PTR
    },
    {
        /* EcuM_WakeupSourcePolling */
        FALSE,
        /* EcuM_ComMChannelRef */
        ECUM_INVALID_COMM_CHANNEL,
        /* EcuM_NumberOfResetReason */
        0U,
        /* EcuM_CheckWakeupTimeout Unit: [ms]*/
        0U,
        /* EcuM_ValidationTimeout Unit: [ms]*/
        0U,
        /* EcuM_WakeupSourceMask */
        (uint32)2,
        /* EcuM_ResetReasonRefPtr */
        NULL_PTR
    },
    {
        /* EcuM_WakeupSourcePolling */
        FALSE,
        /* EcuM_ComMChannelRef */
        ECUM_INVALID_COMM_CHANNEL,
        /* EcuM_NumberOfResetReason */
        0U,
        /* EcuM_CheckWakeupTimeout Unit: [ms]*/
        0U,
        /* EcuM_ValidationTimeout Unit: [ms]*/
        0U,
        /* EcuM_WakeupSourceMask */
        (uint32)4,
        /* EcuM_ResetReasonRefPtr */
        NULL_PTR
    },
    {
        /* EcuM_WakeupSourcePolling */
        FALSE,
        /* EcuM_ComMChannelRef */
        ECUM_INVALID_COMM_CHANNEL,
        /* EcuM_NumberOfResetReason */
        0U,
        /* EcuM_CheckWakeupTimeout Unit: [ms]*/
        0U,
        /* EcuM_ValidationTimeout Unit: [ms]*/
        0U,
        /* EcuM_WakeupSourceMask */
        (uint32)8,
        /* EcuM_ResetReasonRefPtr */
        NULL_PTR
    },
    {
        /* EcuM_WakeupSourcePolling */
        FALSE,
        /* EcuM_ComMChannelRef */
        ECUM_INVALID_COMM_CHANNEL,
        /* EcuM_NumberOfResetReason */
        0U,
        /* EcuM_CheckWakeupTimeout Unit: [ms]*/
        0U,
        /* EcuM_ValidationTimeout Unit: [ms]*/
        0U,
        /* EcuM_WakeupSourceMask */
        (uint32)16,
        /* EcuM_ResetReasonRefPtr */
        NULL_PTR
    },
    {
        /* EcuM_WakeupSourcePolling */
        TRUE,
        /* EcuM_ComMChannelRef */
        ComMConf_ComMChannel_ComMChannel_0,
        /* EcuM_NumberOfResetReason */
        0U,
        /* EcuM_CheckWakeupTimeout Unit: [ms]*/
        1000U,
        /* EcuM_ValidationTimeout Unit: [ms]*/
        2000U,
        /* EcuM_WakeupSourceMask */
        (uint32)32,
        /* EcuM_ResetReasonRefPtr */
        NULL_PTR
    }
 
};
#define ECUM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "EcuM_MemMap.h"


#define ECUM_START_SEC_CONFIG_DATA_32
#include "EcuM_MemMap.h"
static CONST(uint32, ECUM_CONST) EcuM_OsResource[ECUM_OS_RESOURCE_NUM] =
{
      0
};
#define ECUM_STOP_SEC_CONFIG_DATA_32
#include "EcuM_MemMap.h"

#define ECUM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "EcuM_MemMap.h"
static CONST(EcuM_CommonConfigurationType, ECUM_CONST) EcuM_CommonConfiguration =
{
    /* Os module designation */
    0,/* EcuM_DefaultAppMode */
    EcuM_OsResource,/* EcuM_OsResource */
    /* EcuM_DefaultShutdownTargetPtr */
    &EcuM_DefaultShutdownTarget,
    /* EcuM_SleepModePtr */
    &EcuM_SleepMode[0],
    /* EcuM_WakeupSourcePtr */
    &EcuM_WakeupSource[0]
};


static CONST(EcuM_FlexUserConfigType, ECUM_CONST) EcuM_FlexUserConfig[ECUM_FLEX_USER_NUM] =
{
    {
        /* EcuM_FlexUser */
        EcuMConf_EcuMFlexUserConfig_EcuMFlexUserConfig_0,
        /* Currently, the partition feature is not supported */
        NULL_PTR  /* EcuM_FlexEcucPartitionRefPtr */
    }
};
#define ECUM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "EcuM_MemMap.h"

#define ECUM_START_SEC_CONFIG_DATA_8
#include "EcuM_MemMap.h"
static CONST(uint8, ECUM_CONST) EcuM_GoDownAllowedUsers[1] =
{
    EcuMConf_EcuMFlexUserConfig_EcuMFlexUserConfig_0
};
#define ECUM_STOP_SEC_CONFIG_DATA_8
#include "EcuM_MemMap.h"
 


 


#define ECUM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "EcuM_MemMap.h"
static CONST(EcuM_FlexConfigurationType, ECUM_CONST) EcuM_FlexConfiguration =
{
    /* EcuM_NormalMcuModeRef */
    McuConf_McuModeSettingConf_McuModeSettingConf_0,
    /* Currently, the partition feature is not supported */
    NULL_PTR,/* EcuM_PartitionRefPtr */
    NULL_PTR,/* EcuM_AlarmClockPtr */
    &EcuM_FlexUserConfig[0],/* EcuM_FlexUserConfigPtr */
    &EcuM_GoDownAllowedUsers[0],/* EcuM_GoDownAllowedUsersPtr */
    NULL_PTR,/* EcuM_SetClockAllowedUsersPtr */
};


CONST(EcuM_ConfigType, ECUM_CONST) EcuM_Config =
{
    ECUM_CONFIGCONSISTENCY_HASH,/* EcuM_ConfigConsistencyHash */
    &EcuM_CommonConfiguration,	/* EcuM_CommonConfigurationPtr */
    NULL_PTR,					/* EcuM_FixedConfigurationPtr */
    &EcuM_FlexConfiguration		/* EcuM_FlexConfigurationPtr */
};
#define ECUM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "EcuM_MemMap.h"

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */
/** @} */