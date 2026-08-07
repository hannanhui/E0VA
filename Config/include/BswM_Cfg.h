 /**
 * @file        BswM_Cfg.h
 * @brief       AUTOSAR BSWM - BswM_Cfg driver header file.
 * @details     BswM_Cfg driver header file, containing the Autosar API specification and
 *              other variables and functions that are exported by the BswM_Cfg driver.
 * @version     1.2.0
 *
 * @addtogroup  BswM_Cfg
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
#ifndef BSWM_CFG_H
#define BSWM_CFG_H

#if defined(__cplusplus)
extern "C"
{
#endif /* defined(__cplusplus) */

/*====================================================================================================*
 *                                           INCLUDE FILES                                          
 *====================================================================================================*/

#include "ComStack_Types.h"

/*====================================================================================================*
 *                                  HEADER FILE VERSION INFORMATION                                 
 *====================================================================================================*/

#define BSWM_CFG_VENDOR_ID                    0U
#define BSWM_CFG_AR_RELEASE_MAJOR_VERSION     4U
#define BSWM_CFG_AR_RELEASE_MINOR_VERSION     2U
#define BSWM_CFG_AR_RELEASE_REVISION_VERSION  2U
#define BSWM_CFG_SW_MAJOR_VERSION             1U
#define BSWM_CFG_SW_MINOR_VERSION             2U
#define BSWM_CFG_SW_PATCH_VERSION             0U

/*====================================================================================================*
 *                                         FILE VERSION CHECKS                                      
 *====================================================================================================*/

#ifndef DISABLE_INTERMOD_VERSION_CHECK
/* Check if current file and ComStack_Types header file are of the same Autosar version */
#if(\
		(BSWM_CFG_AR_RELEASE_MAJOR_VERSION != COMTYPE_AR_RELEASE_MAJOR_VERSION) || \
		(BSWM_CFG_AR_RELEASE_MINOR_VERSION != COMTYPE_AR_RELEASE_MINOR_VERSION) \
	)
#error "AutoSar Version Number of BswM_Cfg.h and ComStack_Types.h are different "
#endif

#endif

/*====================================================================================================*
 *                                             CONSTANTS                                            
 *====================================================================================================*/

/*====================================================================================================*
 *                                         DEFINES AND MACROS                                       
 *====================================================================================================*/

/**
 * @{
 * @brief Standard Macro Definition
 */
/**
 * @brief enable/disable CanSM module related BswM API.
 */
#define BSWM_CANSM_ENABLED             (STD_OFF)

/**
 * @brief enable/disable CanSM Icom related BswM API.
 */
#define BSWM_CANSM_ICOM_ENABLED        (STD_OFF)

/**
 * @brief enable/disable ComM module related BswM API.
 */
#define BSWM_COMM_ENABLED              (STD_ON)

/**
 * @brief enable/disable Dcm module related BswM API.
 */
#define BSWM_DCM_ENABLED               (STD_ON)

/**
 * @brief enable/disable EcuM module related BswM API.
 */
#define BSWM_ECUM_ENABLED              (STD_ON)

/**
 * @brief enable/disable EthSM module related BswM API.
 */
#define BSWM_ETHSM_ENABLED             (STD_OFF)

/**
 * @brief enable/disable FrSM module related BswM API.
 */
#define BSWM_FRSM_ENABLED              (STD_OFF)

/**
 * @brief enable/disable Generic Request related BswM API.
 */
#define BSWM_GENERIC_REQUEST_ENABLED   (STD_ON)

/**
 * @brief enable/disable J1939Dcm module related BswM API.
 */
#define BSWM_J1939DCM_ENABLED          (STD_OFF)

/**
 * @brief enable/disable J1939Nm module related BswM API.
 */
#define BSWM_J1939NM_ENABLED           (STD_OFF)

/**
 * @brief enable/disable LinSM module related BswM API.
 */
#define BSWM_LINSM_ENABLED             (STD_OFF)

/**
 * @brief enable/disable LinTP module related BswM API.
 */
#define BSWM_LINTP_ENABLED             (STD_OFF)

/**
 * @brief enable/disable NvM module related BswM API.
 */
#define BSWM_NVM_ENABLED               (STD_ON)

/**
 * @brief enable/disable SchM module related BswM API.
 */
#define BSWM_SCHM_ENABLED              (STD_OFF)

/**
 * @brief enable/disable Sd module related BswM API.
 */
#define BSWM_SD_ENABLED                (STD_OFF)

/**
 * @brief enable/disable WdgM module related BswM API.
 */
#define BSWM_WDGM_ENABLED              (STD_OFF)
/** @} */

/**
 * @{
 * @brief additional macro configuration
 */
/**
 * @brief enable/disable NM module related BswM API.
 */
#define BSWM_NM_ENABLED                (STD_OFF)

/**
 * @brief enable/disable OS module related BswM API.
 */
#define BSWM_OS_ENABLED                (STD_OFF)

/**
 * @brief enable/disable Com module related BswM API.
 */
#define BSWM_COM_ENABLED               (STD_OFF)

/**
 * @brief enable/disable J1939Rm module related BswM API.
 */
#define BSWM_J1939RM_ENABLED           (STD_OFF)

/**
 * @brief enable/disable PduR module related BswM API.
 */
#define BSWM_PDUR_ENABLED              (STD_OFF)

/**
 * @brief  use/or not to use disable Dem.(Non-Autosar)
 */ 
#define BSWM_DEM_ENABLED               (STD_OFF)
/** @} */ 

/**
 * @brief Switches the Default Error Tracer (Det) detection and
 *         notification ON or OFF.
 * @range  true - Enabled
 *         false - Disabled
 */
#define BSWM_DEV_ERROR_DETECT          (STD_OFF)

/**
 * @brief The corresponding  condition has no request mode configured( NO autosar )    .
 */
#define	BSWM_NO_CONDITIONAL_REQUESTMODE			 (0xFFU)

/**
 * @brief The cycle time of the periodic main function of BswM. Defined in seconds.
 */
#define BSWM_MAIN_FUNCTION_PERIOD      (0.1)

/**
 * @brief Switches the possibility to read the version information with
 *         the service BswM_GetVersionInfo().
 * @range  true - Enabled
 *         false - Disabled
 */
#define BSWM_VERSION_INFO_API          (STD_ON)

#define BSWM_PRECOMPILE                (0u)
#define BSWM_POSTBUILD                 (1u)
#define BSWM_VARIANT                   (BSWM_POSTBUILD)

#define BSWM_CONFIG_PB                 extern CONST(BswM_ConfigType, BSWM_CONST) BswM_Config;

/**
 * @{
 * @brief Length Information
 */
#define BSWM_RULE_COUNT                        (1UL)
#define BSWM_MODE_REQUEST_PORT_COUNT           (2UL)
#define BSWM_MODE_CONDITION_COUNT              (2UL)
#define BSWM_MDOE_LOGICAL_EXPRESSION_COUNT     (2UL)
#define BSWM_ACTION_LIST_COUNT                 (1UL)
#define BSWM_EXPANDED_PORT_MULTIPLE_COUNT      (1UL)
/** @} */

/**
 * @{
 * @brief List all customized requesting users.
 */
#define BswMConf_BswMGenericRequest_BswMGenericRequest_ShutDown  (2UL)
/** @} */

/**
 * @{
 * @brief List all BswMModeRequestPorts
 */
#define BswMConf_BswMModeRequestPort_BswMModeRequestPort_startup  (0UL)
#define BswMConf_BswMModeRequestPort_BswMModeRequestPort_ShutDown  (1UL)
/** @} */

/**
 * @{
 * @brief List all BswMModeConditions
 */
#define BswMConf_BswMModeCondition_BswMModeCondition_startup  (0UL)
#define BswMConf_BswMModeCondition_BswMModeCondition_Shut_Down  (1UL)
/** @} */

/**
 * @{
 * @brief List all BswMLogicalExpressions
 */
#define BswMConf_BswMLogicalExpression_BswMLogicalExpression_startup  (0UL)
#define BswMConf_BswMLogicalExpression_BswMLogicalExpression_Shut_Dowm  (1UL)
/** @} */

/**
 * @{
 * @brief List all BswMRules
 */
#define BswMConf_BswMRule_BswMRule_startup_zero  (0UL)
/** @} */

/**
 * @{
 * @brief List all BswMActionLists
 */
#define BswMConf_BswMActionList_BswMActionList_All_Init_zero  (0UL)
/** @} */

/**
* @{
* @brief List all BswMActions
*/
#define BswMConf_BswMAction_BswMAction_NvM_ReadAll    (0)
#define BswMConf_BswMAction_BswMAction_Memory_All_Init    (1)
#define BswMConf_BswMAction_BswMAction_Communication_All_Init    (2)
#define BswMConf_BswMAction_BswMAction_Dcm    (3)
#define BswMConf_BswMAction_BswMAction_Action    (4)
/** @} */

/*====================================================================================================*
 *                                               ENUMS                                              
 *====================================================================================================*/

/*====================================================================================================*
 *                                   STRUCTURES AND OTHER TYPEDEFS                                  
 *====================================================================================================*/

/**
 * @brief  This type <b>identifies the modes</b> that can be requested by BswM Users.
 * @range  uint8, uint16
 * @req    SWS_BswM_00214
 */
typedef uint8 BswM_ModeType;
#define BSWM_INVALID_MODE  (255U)

/**
 * @brief  This type identifies a BswM User that makes mode requests to the BswM.
 * @range  uint8, uint16
 * @req    SWS_BswM_00216
 */
typedef uint8 BswM_UserType;

/*====================================================================================================*
 *                                    GLOBAL VARIABLE DECLARATIONS                                  
 *====================================================================================================*/


/*====================================================================================================*
 *                                        FUNCTION PROTOTYPES                                       
 *====================================================================================================*/


#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */
/** @} */

#endif /* #ifndef BSWM_CFG_H */
