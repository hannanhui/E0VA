/**
 * @file        ComM_Cfg.h
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
#ifndef COMM_CFG_H
#define COMM_CFG_H
 
#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */
/*====================================================================================================*
 *                                           INCLUDE FILES                                          
 *====================================================================================================*/
 
/*====================================================================================================*
 *                                  HEADER FILE VERSION INFORMATION                                 
 *====================================================================================================*/
#define COMM_CFG_VENDOR_ID                      0U
#define COMM_CFG_AR_RELEASE_MAJOR_VERSION 	    4u
#define COMM_CFG_AR_RELEASE_MINOR_VERSION 	    2u
#define COMM_CFG_AR_RELEASE_REVISION_VERSION 	2u
#define COMM_CFG_SW_MAJOR_VERSION 			    1u
#define COMM_CFG_SW_MINOR_VERSION 			    2u
#define COMM_CFG_SW_PATCH_VERSION               0U

/*====================================================================================================*
 *                                         FILE VERSION CHECKS                                      
 *====================================================================================================*/

 /*====================================================================================================*
 *                                             CONSTANTS                                            
 *====================================================================================================*/

/*====================================================================================================*
 *                                         DEFINES AND MACROS                                       
 *====================================================================================================*/
/*
 * ComMGeneral,ComMConfigSet
 */
/* Whether the CAN bus is supported or not.*/
#define COMM_BUS_CAN_USED                 	STD_OFF

/* Whether the LIN bus is supported or not.*/
#define COMM_BUS_LIN_USED                 	STD_OFF

/* Whether the FlexRay bus is supported or not.*/
#define COMM_BUS_FLEXRAY_USED              	STD_OFF

/* Whether the CDD bus is supported or not.*/
#define COMM_BUS_CDD_USED                 	STD_OFF

/* Whether the ETH bus is supported or not.*/
#define COMM_BUS_ETH_USED                 	STD_OFF

/* Whether the NM is supported or not.*/
 /* Whether the NM is supported or not.*/
#define COMM_NM_USED              STD_OFF
 /* Whether the none volatile memory is supported or not.*/
#define COMM_NVM_USED                       STD_OFF

/* Whether the DCM is supported or not.*/
#define COMM_DCM_USED                       STD_ON /*ComMDcmUsed*/

/* Whether the ECUM is supported or not.*/
#define COMM_ECUM_USED                      STD_ON /*ComMEcuMUsed*/

/* Whether the RTE notification is supported or not.*/
#define COMM_RTE_NOTIFY_USED                STD_OFF /*ComMRTENotifyUsed*/

/* Whether the BSWM notification is supported or not.*/
#define COMM_BSWM_USED                      STD_ON /*ComMBswMUsed*/

/* Whether the COM notification is supported or not.*/
#define COMM_COM_USED                       STD_ON /*ComMComUsed*/


/* Switches the Development Error Detection and Notification ON or OFF.*/
/**@req ComM555*/
#define COMM_DEV_ERROR_DETECT               STD_OFF /*ComMDevErrorDetect*/
#define COMM_DIRECT_USER_MAPPING            STD_OFF/*ComMDirectUserMapping*/

/* Switches the Porduct Error Detection ON or OFF.*/
#define COMM_DEM_ERROR_DETECT               STD_OFF

/* Defines whether a mode inhibition affects the ECU or not.*/
/**@req ComM563*/
#define COMM_ECU_GROUP_CLASSIFICATION       0x3u /*ComMEcuGroupClassification*/

/* True if mode limitation functionality shall be enabled. true:Enabled false: Disabled*/
/**@req ComM560*/
#define COMM_MODE_LIMITATION_ENABLED        STD_ON /*ComMModeLimitationEnabled*/
#define COMM_NM_PASSIVE_MODE_ENABLED        STD_OFF/*ComMNmPassiveModeEnable*/
/* True if wake up inhibition functionality enabled.*/
#define COMM_WAKEUP_INHIBITION_ENABLED      STD_OFF /*ComMWakeupInhibitionEnabled*/

/* The ECU is not allowed to change state of the ECU to "Silent Communication" or 
 *"Full Communication".*/
#define COMM_NO_COM                         STD_OFF

/* ComM shall perform a reset after entering "No Communication" mode because of an active mode 
 * limitation to "No Communication" mode.*/
#define COMM_RESET_AFTER_FORCING_NO_COMM    STD_ON  /*ComMResetAfterForcingNoComm*/

/* Wake up of one channel shall lead to a wake up of all channels if true.*/
#define COMM_SYNCHRONOUS_WAKE_UP            STD_ON /*ComMSynchronousWakeUp*/

/* Minimum time duration in seconds, spent in the Full Communication mode.*/
#define COMM_T_MIN_FULL_COM_MODE_DURATION   5  /*ComMTMinFullComModeDuration*/

/* Switches the possibility to read the published information with the service.*/
#define COMM_VERSION_INFO_API               STD_OFF /*ComMVersionInfoApi*/

/* Reference to NvmBlockDescriptor.*/
#define COMM_GLOBAL_NVM_BLOCK_DESCRIPTOR    0x0u /*ComMGlobalNvMBlockDescriptor*/
 #define COMM_PNC_GATEWAY_ENABLED           STD_OFF
#define COMM_PNC_SUPPORT                    STD_OFF  /*ComMPncSupport*/

/*
 * Additional Configuration
 */

 /* Number of the PNCs*/
 #define COMM_NUMBER_OF_PNCS                                            0x0u


/* Number of the channels */
#define COMM_NUMBER_OF_CHANNELS       1u
#define ComMConf_ComMChannel_ComMChannel_0       0u
#define ComM_MainFunction_0()     ComM_MainFunction(0)

/* Number of the channels belong to eatch User*/
#define COMM_CHANNEL_NUMBER_OF_ComMUser_0       1u

/* Number of the user */
#define COMM_NUMBER_OF_USERS       1u
#define ComMConf_ComMUser_ComMUser_0       0u



/*====================================================================================================*
 *                                               ENUMS                                              
 *====================================================================================================*/


/*====================================================================================================*
 *                                   STRUCTURES AND OTHER TYPEDEFS                                  
 *====================================================================================================*/


/*====================================================================================================*
 *                                    GLOBAL VARIABLE DECLARATIONS                                  
 *====================================================================================================*/
 
#define COMM_CONF_PB   extern CONST(ComM_ConfigType, COMM_CONST) ComM_Config;

/*====================================================================================================*
 *                                        FUNCTION PROTOTYPES                                       
 *====================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* CANTP_CFG_H */
/** @} */