/**
 * @file        LinTp_PBCfg.c
 * @brief       Post-build configuration file for LinTp.
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
#ifdef __cplusplus
extern "C"{
#endif

/*====================================================================================================*
 *                                           INCLUDE FILES
 *====================================================================================================*/

#include "LinIf.h"
#include "PduR_LinTp.h"
/*====================================================================================================*
 *                                  SOURCE FILE VERSION INFORMATION
 *====================================================================================================*/

#define LINTP_PBCFG_VENDOR_ID_C                            0U
#define LINTP_PBCFG_AR_RELEASE_MAJOR_VERSION_C             4U
#define LINTP_PBCFG_AR_RELEASE_MINOR_VERSION_C             2U
#define LINTP_PBCFG_AR_RELEASE_REVISION_VERSION_C          2U
#define LINTP_PBCFG_SW_MAJOR_VERSION_C                     1U
#define LINTP_PBCFG_SW_MINOR_VERSION_C                     0U
#define LINTP_PBCFG_SW_PATCH_VERSION_C                     0U

/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/

/* Add code here */

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
 *                                           LOCAL VARIABLES
 *====================================================================================================*/

/* Add code here */

/*====================================================================================================*
 *                                           GLOBAL CONSTANTS
 *====================================================================================================*/
/**
 * @brief LinTp Channel Configuration.
 */
CONST(LinTp_ChannelConfigType, LINTP_CONST) LinTp_ChannelCfg[LINTP_MAX_CHANNEL_NUM] =
{
    {
        /**< @brief Configures if TP Frames of not requested LIN-Slaves are dropped or not. */
        FALSE,

        /**< @brief Configures the maximum number of allowed response pending frames.
         *          Only used for LIN Master nodes, ignored for slave nodes.
         */
        1U,

    	/**< @brief P2*max timeout when a response pending frame is expected in milliseconds.
         *          Only used for LIN Master nodes, ignored for slave nodes
         */
         2000U,

        /**< @brief Definition of the P2max timeout observation parameter in milliseconds.
         *          Only used for LIN Master nodes, ignored for slave nodes
         */
         500U,

        /**< @brief Enables or disables the call of BswM_LinTp_RequestMode() to diagnostic
         *          request/response schedule.
         *          Only used for LIN Master nodes, ignored for slave nodes
         */
         FALSE,

         /**< @brief Index of the channel this LinTp channel belongs to.*/
         0,

         /**< @brief Index of the channel this LinTp channel belongs to.*/
         LINIF_SLAVE_CHANNEL_LinIfChannel_0
    }
};

 /**< @brief Rx NSdu Configuration for LinTp. */
CONST(LinTp_RxNSduType, LINTP_CONST) LinTp_RxNSduCfg[LINTP_MAX_RX_NSDU_NUM] =
{
    {
        /**< @brief N_Cr timeout enable switch.*/
        TRUE,

       /**< @brief Value in milliseconds of the N_Cr timeout. N_Cr is the time until
        *          reception of the next Consecutive Frame N_PDU.
        */
        1000U,

        /**< @brief The identifier of the Transport Protocol message. This ID will be
         *          used by upper layers to call LinTp_ChangeParameter.
         */
         0U,

         /**< @brief A N-SDU transported on LIN is identified using the NAD for the specific slave.*/
         116U,

         /**< @brief Index of the channel this N-SDU belongs to.*/
         0,

         /**< @brief Reference to the global PDU.*/
         PduRConf_PduRSrcPdu_LinPdu_LinTpToPduR_MasterReq_Rx,
    },
    {
        /**< @brief N_Cr timeout enable switch.*/
        TRUE,

       /**< @brief Value in milliseconds of the N_Cr timeout. N_Cr is the time until
        *          reception of the next Consecutive Frame N_PDU.
        */
        1000U,

        /**< @brief The identifier of the Transport Protocol message. This ID will be
         *          used by upper layers to call LinTp_ChangeParameter.
         */
         1U,

         /**< @brief A N-SDU transported on LIN is identified using the NAD for the specific slave.*/
         126U,

         /**< @brief Index of the channel this N-SDU belongs to.*/
         0,

         /**< @brief Reference to the global PDU.*/
         PduRConf_PduRSrcPdu_LinPdu_LinTpToPduR_FuncReq_Rx,
    }
};

 /**< @brief Rx NSdu Configuration for LinTp. */
CONST(LinTp_TxNSduType, LINTP_CONST) LinTp_TxNSduCfg[LINTP_MAX_TX_NSDU_NUM] =
{
    {
        /**< @brief This parameter defines the maximum number of times the LinTp should
         *          request upper layer for the Tx Buffer. It is also used to limit the
         *          number of retries for PduR_LinTpCopyTxData when no timer is active.
         */
         10U,

        /**< @brief Value in seconds of the N_As timeout. N_As is the time for transmission of
         *          a LIN frame (any N_PDU) on the part of the sender.
         */
         1000U,

         /**< @brief N_Cs timeout enable switch.*/
         TRUE,

        /**< @brief Value in seconds of the performance requirement of N_Cs. N_Cs is the
         *          time which elapses between the transmit request of a CF N-PDU until the
         *          transmit request of the next CF N-PDU.
         */
         1000U,

        /**< @brief The identifier of the Transport Protocol message. This ID will be
         *          used by upper layers to call LinTp_ChangeParameter.
         */
         0U,

         /**< @brief A N-SDU transported on LIN is identified using the NAD for the specific slave.*/
         116U,

         /**< @brief Index of the channel this N-SDU belongs to.*/
         0,

         /**< @brief Reference to the global PDU.*/
         PduRConf_PduRDestPdu_LinPdu_PduRToLinTp_SlaveResp_Tx,
    }
};

/**
 * @brief LinTp Configuration.
 */
CONST(LinTp_ConfigType, LINTP_CONST) LinTp_Config =
{
    /**< @brief LinTp Channel configuration. */
    &LinTp_ChannelCfg[0],
    /**< @brief Rx NSdu Configuration for LinTp. */
    &LinTp_RxNSduCfg[0],
    /**< @brief Tx NSdu Configuration for LinTp. */
    &LinTp_TxNSduCfg[0]
};
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

/*====================================================================================================*
 *                                          GLOBAL VARIABLES
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
