/**
 * @file        LinIf_Cfg.h
 * @brief       Precompile configuration file for LinIf module.
 * @version     1.0.0
 * @addtogroup  LINIF
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
#ifndef LINIF_CFG_H
#define LINIF_CFG_H

#ifdef __cplusplus
extern "C"{
#endif

/*====================================================================================================*
 *                                           INCLUDE FILES
 *====================================================================================================*/

#include "Std_Types.h"

/*====================================================================================================*
 *                                  SOURCE FILE VERSION INFORMATION
 *====================================================================================================*/

#define LINIF_CFG_VENDOR_ID                        0U
#define LINIF_CFG_AR_RELEASE_MAJOR_VERSION         4U
#define LINIF_CFG_AR_RELEASE_MINOR_VERSION         2U
#define LINIF_CFG_AR_RELEASE_REVISION_VERSION      2U
#define LINIF_CFG_SW_MAJOR_VERSION                 1U
#define LINIF_CFG_SW_MINOR_VERSION                 0U
#define LINIF_CFG_SW_PATCH_VERSION                 0U

/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/

/* Add code here */

/*====================================================================================================*
 *                                             CONSTANTS
 *====================================================================================================*/
/**
 * @brief Total number of configured slave node channels.
 */
#define LINIF_MAX_SLAVE_CHANNEL_NUM              (1U)

/**
 * @brief Configure the maximum number of slave nodes.
 */
#define LINIF_MAX_SLAVE_NODE_NUM                 (1U)

/**
 * @brief Total number of frames configured for the slave node channel.
 */
#define LINIF_MAX_SLAVE_NODE_FRAME_NUM          (6U)

/**
 * @brief Define the identifier for the LinIf layer PDU.
 */
#define LinIfConf_LinIfTxPdu_LinPdu_PduRToLinIf_DSMM_1_Tx         (0U)
#define LinIfConf_LinIfTxPdu_LinPdu_PduRToLinTp_SlaveResp_Tx         (0U)

#define LinIfConf_LinIfRxPdu_LinPdu_LinIfToPduR_ZCU_SMM_1_Rx         (1U)
#define LinIfConf_LinIfRxPdu_LinPdu_LinIfToPduR_ZCU_SMM_2_Rx         (2U)
#define LinIfConf_LinIfRxPdu_LinPdu_LinTpToPduR_MasterReq_Rx         (3U)
#define LinIfConf_LinIfRxPdu_LinPdu_LinTpToPduR_FuncReq_Rx         (5U)

/**
 *  @brief Define LinIf Slave Channel Identifier.
 */
#define LINIF_SLAVE_CHANNEL_LinIfChannel_0      (0U)

/*====================================================================================================*
 *                                         DEFINES AND MACROS
 *====================================================================================================*/
/**
 * @brief Bus Mirroring is enabled in the LIN Interface or not
 */
#define LINIF_BUS_MIRRORING_SUPPORTED            (STD_OFF)

/**
 * @brief Switches the development error detection and notification on or off
 */
 #define LINIF_DEV_ERROR_DETECT                  (STD_OFF)

/**
 * @brief States if multiple drivers are supported by the LIN Interface or not
 */
#define LINIF_MULTIPLE_DRIVERS_SUPPORTED         (STD_OFF)

/**
 * @brief States if multiple transceiver drivers are supported by the LIN Interface or not
 */
#define LINIF_MULTIPLE_TRCV_DRIVERS_SUPPORTED    (STD_OFF)

/**
 * @brief States if the node configuration commands Assign NAD and Conditional Change NAD are supported
 */
#define LINIF_NC_OPTIONAL_REQUEST_SUPPORTED      (STD_OFF)

/**
 * @brief Defines header files for callback functions which shall be included in case of CDDs
 */
#define LINIF_PUBLIC_CDD_HEADER_FILE             (STD_OFF)

/**
 * @brief This parameter contains the name of the callout function that is called after
 *        a response error signal change.
 */
#define LINIF_RESPONSE_ERROR_SIGNAL_CHANGED_CALLOUT    (STD_OFF)

/**
 * @brief This parameter contains the name of the callout function that is called when a save
 *        configuration node configuration command is processed by this slave node.
 */
#define LINIF_SAVE_CONFIGURATION_CALLOUT         (STD_OFF)

/**
 * @brief States if the TP is included in the LIN Interface or not.
 */
#define LINIF_TP_SUPPORTED                       (STD_ON)

/**
 * @brief States if transceiver driver support is included in the LIN Interface or not.
 */
#define LINIF_TRCV_DRIVER_SUPPORTED              (STD_OFF)

/**
 * @brief Switches the LinIf_GetVersionInfo function ON or OFF.
 */
#define LINIF_VERSION_INFO_API                   (STD_OFF)

/**
 * @brief Slave node enable switch.
 */
#define LINIF_USED_SLAVE_NODE                    (STD_ON)

/**
 * @brief The response_error signal,switch
 */
#define LINIF_SLAVE_RESPONSE_ERROR_SIGNAL        (STD_ON)

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

/**
 * @brief Post-Build structures from LinIf_PBCfg.c file.
 */
#define LINIF_CONF_PB    extern CONST(LinIf_ConfigType, LINIF_CONST) LinIf_Config;

/*====================================================================================================*
 *                                        FUNCTION PROTOTYPES
 *====================================================================================================*/

/* Add code here */

#ifdef __cplusplus
}
#endif

#endif /* LINIF_CFG_H */
/** @} */
