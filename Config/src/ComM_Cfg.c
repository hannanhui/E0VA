/**
 * @file        ComM_Cfg.c
 * @brief       Implementation for ComM
 * @version     1.2.0
 * @addtogroup  ComM
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

#include "ComM_Cfg.h"
#include "ComM.h"

/*====================================================================================================*
 *                                  SOURCE FILE VERSION INFORMATION                                 
 *====================================================================================================*/

#define COMM_CFG_VENDOR_ID_C                   0U
#define COMM_CFG_AR_RELEASE_MAJOR_VERSION_C    4U
#define COMM_CFG_AR_RELEASE_MINOR_VERSION_C    2U
#define COMM_CFG_AR_RELEASE_REVISION_VERSION_C 2U
#define COMM_CFG_SW_MAJOR_VERSION_C            1U
#define COMM_CFG_SW_MINOR_VERSION_C            2U
#define COMM_CFG_SW_PATCH_VERSION_C            0U

/*====================================================================================================*
 *                                         FILE VERSION CHECKS                                      
 *====================================================================================================*/

/* Check if current file and ComM.h header file are of the same vendor  */
#if(COMM_CFG_VENDOR_ID_C != COMM_VENDOR_ID )
#error "ComM_Cfg.c and ComM.h  have different vendor id"
#endif

/* Check if current file and ComM.h header file are of the same Autosar version */
#if(\
      (COMM_CFG_AR_RELEASE_MAJOR_VERSION_C != COMM_AR_RELEASE_MAJOR_VERSION) || \
      (COMM_CFG_AR_RELEASE_MINOR_VERSION_C != COMM_AR_RELEASE_MINOR_VERSION) || \
      (COMM_CFG_AR_RELEASE_REVISION_VERSION_C != COMM_AR_RELEASE_REVISION_VERSION) \
      )
#error "AutoSar Version Number of ComM_Cfg.c and ComM.h  are different "
#endif

/* Check if current file and ComM.h header file are of the same software version  */
#if(\
      (COMM_CFG_SW_MAJOR_VERSION_C != COMM_SW_MAJOR_VERSION) || \
      (COMM_CFG_SW_MINOR_VERSION_C != COMM_SW_MINOR_VERSION) ||\
	  (COMM_CFG_SW_PATCH_VERSION_C != COMM_SW_PATCH_VERSION)\
      )
#error "Software Version Number of ComM_Cfg.c and ComM.h  are different "
#endif


/* Check if current file and ComM_Cfg.h header file are of the same vendor  */
#if(COMM_CFG_VENDOR_ID_C != COMM_CFG_VENDOR_ID )
#error "ComM_Cfg.c and ComM_Cfg.h  have different vendor id"
#endif

/* Check if current file and ComM_Cfg.h header file are of the same Autosar version */
#if(\
      (COMM_CFG_AR_RELEASE_MAJOR_VERSION_C != COMM_CFG_AR_RELEASE_MAJOR_VERSION) || \
      (COMM_CFG_AR_RELEASE_MINOR_VERSION_C != COMM_CFG_AR_RELEASE_MINOR_VERSION) || \
      (COMM_CFG_AR_RELEASE_REVISION_VERSION_C != COMM_CFG_AR_RELEASE_REVISION_VERSION) \
      )
#error "AutoSar Version Number of ComM_Cfg.c and ComM_Cfg.h  are different "
#endif

/* Check if current file and ComM_Cfg.h header file are of the same software version  */
#if(\
      (COMM_CFG_SW_MAJOR_VERSION_C != COMM_CFG_SW_MAJOR_VERSION) || \
      (COMM_CFG_SW_MINOR_VERSION_C != COMM_CFG_SW_MINOR_VERSION) ||\
	  (COMM_CFG_SW_PATCH_VERSION_C != COMM_CFG_SW_PATCH_VERSION)\
      )
#error "Software Version Number of ComM_Cfg.c and ComM_Cfg.h  are different "
#endif
 /*====================================================================================================*
  *                                   EXTERNAL FUNCTION DECLARATIONS                                 
  *====================================================================================================*/



/*====================================================================================================*
 *                                           LOCAL TYPEDEFS                                         
 *====================================================================================================*/

#define COMM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "ComM_MemMap.h"

CONST(ComM_ChannelCfgType, COMM_CONST) ComM_ChannelCfg[COMM_NUMBER_OF_CHANNELS] =
{
    {
        COMM_BUS_TYPE_LIN,/*ComMBusType*/
        NULL_PTR,/*ComMCDDBusPrefix*/
        FALSE,   /*ComMFullCommRequestNotificationEnabled*/
        20, /*ComMMainFunctionPeriod(ms)*/
        FALSE, /*ComMNoCom*/  
        FALSE, /*ComMNoWakeUpInhibitionNvmStorage*/
        /* ComMWakeupInhibitionEnabled = FALSE ,There's no ComMNoWakeup member*/  
        /* ComMPncGatewayEnabled = FALSE or ComMPncEnabled = FALSE or ComMPncGatewayType is not Configurate,There no ComMNoWakeup member*/  
        COMM_NONE,/*ComMNmVariant*/
        0u,/*ComMNmLightTimeout*/
        /* ComMPncEnabled = FALSE ,There's no ComMPncNmRequest member*/  
    }
};

#define COMM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "ComM_MemMap.h"



#define COMM_START_SEC_CONFIG_DATA_8
#include "ComM_MemMap.h"

CONST(uint8, COMM_CONST) ComM_ComMUser_0ChannelMap[COMM_CHANNEL_NUMBER_OF_ComMUser_0] =
{       
    ComMConf_ComMChannel_ComMChannel_0
};

#define COMM_STOP_SEC_CONFIG_DATA_8
#include "ComM_MemMap.h"



#define COMM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "ComM_MemMap.h"

CONST(ComM_UserCfgType, COMM_CONST) ComM_UserCfg[COMM_NUMBER_OF_USERS] =
{
    {
        COMM_CHANNEL_NUMBER_OF_ComMUser_0,/*ChannelNum*/
        ComM_ComMUser_0ChannelMap,/*ChannelMap*/
        ComMConf_ComMUser_ComMUser_0, /*ComMUserIdentifier*/
        NULL_PTR, /*ComMUserEcucPartitionRef*/
    }
};

#define COMM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "ComM_MemMap.h"






#define COMM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "ComM_MemMap.h"

CONST(ComM_ConfigType, COMM_CONST) ComM_Config =
{
    STD_OFF,/*ComMPncEnabled,*/
    &ComM_ChannelCfg[0],	/*ComMChannelCfgInfo*/
    &ComM_UserCfg[0],  		/*ComMUserCfgInfo*/
};

#define COMM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "ComM_MemMap.h"


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

#ifdef __cplusplus
}
#endif
/** @} */