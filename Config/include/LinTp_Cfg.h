/**
 * @file        LinTp_Cfg.h
 * @brief       Precompile configuration file for LinTp module.
 * @version     1.0.0
 * @addtogroup  LINTP
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
#ifndef LINTP_CFG_H
#define LINTP_CFG_H

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

#define LINTP_CFG_VENDOR_ID                        0U
#define LINTP_CFG_AR_RELEASE_MAJOR_VERSION         4U
#define LINTP_CFG_AR_RELEASE_MINOR_VERSION         2U
#define LINTP_CFG_AR_RELEASE_REVISION_VERSION      2U
#define LINTP_CFG_SW_MAJOR_VERSION                 1U
#define LINTP_CFG_SW_MINOR_VERSION                 0U
#define LINTP_CFG_SW_PATCH_VERSION                 0U

/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/

/* Add code here */

/*====================================================================================================*
 *                                             CONSTANTS
 *====================================================================================================*/
/**
 * @brief Total number of configured channels.
 */
#define LINTP_MAX_CHANNEL_NUM             (1U)

/**
 * @brief The total number of Rx NSdu Configuration for LinTp
 */
#define LINTP_MAX_RX_NSDU_NUM             (2U)

/**
 * @brief The total number of Tx NSdu Configuration for LinTp
 */
#define LINTP_MAX_TX_NSDU_NUM             (1U)

/**
 * @brief Define the identifier for the LinTp layer PDU.
 */
#define LinTpConf_LinTpRxNSdu_LinPdu_LinTpToPduR_MasterReq_Rx         (0U)
#define LinTpConf_LinTpRxNSdu_LinPdu_LinTpToPduR_FuncReq_Rx         (1U)

#define LinTpConf_LinTpTxNSdu_LinPdu_PduRToLinTp_SlaveResp_Tx         (0U)

/*====================================================================================================*
 *                                         DEFINES AND MACROS
 *====================================================================================================*/

/**
 * @brief This parameter, if set to true, enables the LinTp_ChangeParameter Api for this Module.
 */
#define LINTP_CHANGE_PARAMETER_API        (STD_OFF)

/**
 * @brief Switches the LinTp_GetVersionInfo function ON or OFF.
 */
#define LINTP_VERSION_INFO_API            (STD_OFF)

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
 * @brief Post-Build structures from LinTp_PBCfg.c file.
 */
#define LINTP_CONF_PB    extern CONST(LinTp_ConfigType, LINTP_CONST) LinTp_Config;

/*====================================================================================================*
 *                                        FUNCTION PROTOTYPES
 *====================================================================================================*/

/* Add code here */

#ifdef __cplusplus
}
#endif

#endif /* LINTP_CFG_H */
/** @} */
