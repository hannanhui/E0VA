/**
 * @file        Dcm_Cfg.h
 * @brief       AUTOSAR 4.2.2 - 4.2.2 driver header file.
 * @details     Dcm driver header file, containing the Autosar API specification and
 *              other variables and functions that are exported by the Dcm driver.
 * @version     1.2.0
 *
 * @addtogroup  Dcm
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

#ifndef DCM_CFG_H
#define DCM_CFG_H

#ifdef __cplusplus
extern "C"{
#endif

/*====================================================================================================*
 *                                           INCLUDE FILES
 *====================================================================================================*/

/*====================================================================================================*
 *                                  HEADER FILE VERSION INFORMATION
 *====================================================================================================*/
#define DCM_CFG_VENDOR_ID                           		(0x00U)
#define DCM_CFG_AR_RELEASE_MAJOR_VERSION            		(0x04U)
#define DCM_CFG_AR_RELEASE_MINOR_VERSION            		(0x02U)
#define DCM_CFG_AR_RELEASE_REVISION_VERSION         		(0x02U)
#define DCM_CFG_SW_MAJOR_VERSION                    		(0x01U)
#define DCM_CFG_SW_MINOR_VERSION                    		(0x02U)
#define DCM_CFG_SW_PATCH_VERSION                    		(0x00U)
/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/

/*====================================================================================================*
 *                                             CONSTANTS
 *====================================================================================================*/

/*====================================================================================================*
 *                                         DEFINES AND MACROS
 *====================================================================================================*/
/* DcmGeneral */
#define DCM_TASK_TIME                                       5u
#define DCM_DDDID_STORAGE_BLOCK_ID_REF                      0u
#define DCM_DDDID_STORAGE                                   STD_OFF
#define DCM_DEV_ERROR_DETECT                                STD_ON
#define DCM_RESPOND_ALL_REQUEST                             STD_ON
#define DCM_VERSION_INFO_API                                STD_ON

/* DcmDsd */
#define DCM_DSD_REQUEST_MANUFACTURER_NOTIFICATION_ENABLED   STD_OFF
#define DCM_DSD_REQUEST_SUPPLIER_NOTIFICATION_ENABLED       STD_OFF

#define DCM_UDS0x10_ENABLE                                  STD_ON
#define DCM_UDS0x11_ENABLE                                  STD_ON
#define DCM_UDS0x14_ENABLE                                  STD_ON
#define DCM_UDS0x19_ENABLE                                  STD_ON
#define DCM_UDS0x22_ENABLE                                  STD_ON
#define DCM_UDS0x23_ENABLE                                  STD_OFF
#define DCM_UDS0x24_ENABLE                                  STD_OFF
#define DCM_UDS0x27_ENABLE                                  STD_ON
#define DCM_UDS0x28_ENABLE                                  STD_ON
#define DCM_UDS0x2A_ENABLE                                  STD_OFF
#define DCM_UDS0x2C_ENABLE                                  STD_OFF
#define DCM_UDS0x2E_ENABLE                                  STD_ON
#define DCM_UDS0x2F_ENABLE                                  STD_OFF
#define DCM_UDS0x31_ENABLE                                  STD_ON
#define DCM_UDS0x34_ENABLE                                  STD_OFF
#define DCM_UDS0x35_ENABLE                                  STD_OFF
#define DCM_UDS0x36_ENABLE                                  STD_OFF
#define DCM_UDS0x37_ENABLE                                  STD_OFF
#define DCM_UDS0x38_ENABLE                                  STD_OFF
#define DCM_UDS0x3D_ENABLE                                  STD_OFF
#define DCM_UDS0x3E_ENABLE                                  STD_ON
#define DCM_UDS0x83_ENABLE                                  STD_OFF
#define DCM_UDS0x84_ENABLE                                  STD_OFF
#define DCM_UDS0x85_ENABLE                                  STD_ON
#define DCM_UDS0x86_ENABLE                                  STD_OFF
#define DCM_UDS0x87_ENABLE                                  STD_OFF

#define DCM_UDS0x19_SUB0x01_ENABLE                          STD_OFF
#define DCM_UDS0x19_SUB0x07_ENABLE                          STD_OFF
#define DCM_UDS0x19_SUB0x11_ENABLE                          STD_OFF
#define DCM_UDS0x19_SUB0x12_ENABLE                          STD_OFF
#define DCM_UDS0x19_SUB0x02_ENABLE                          STD_ON
#define DCM_UDS0x19_SUB0x0A_ENABLE                          STD_OFF
#define DCM_UDS0x19_SUB0x0F_ENABLE                          STD_OFF
#define DCM_UDS0x19_SUB0x13_ENABLE                          STD_OFF
#define DCM_UDS0x19_SUB0x15_ENABLE                          STD_OFF
#define DCM_UDS0x19_SUB0x17_ENABLE                          STD_OFF
#define DCM_UDS0x19_SUB0x08_ENABLE                          STD_OFF
#define DCM_UDS0x19_SUB0x09_ENABLE                          STD_OFF
#define DCM_UDS0x19_SUB0x06_ENABLE                          STD_OFF
#define DCM_UDS0x19_SUB0x10_ENABLE                          STD_OFF
#define DCM_UDS0x19_SUB0x19_ENABLE                          STD_OFF
#define DCM_UDS0x19_SUB0x03_ENABLE                          STD_OFF
#define DCM_UDS0x19_SUB0x04_ENABLE                          STD_OFF
#define DCM_UDS0x19_SUB0x18_ENABLE                          STD_OFF
#define DCM_UDS0x19_SUB0x05_ENABLE                          STD_OFF
#define DCM_UDS0x19_SUB0x0B_ENABLE                          STD_OFF
#define DCM_UDS0x19_SUB0x0C_ENABLE                          STD_OFF
#define DCM_UDS0x19_SUB0x0D_ENABLE                          STD_OFF
#define DCM_UDS0x19_SUB0x0E_ENABLE                          STD_OFF
#define DCM_UDS0x19_SUB0x14_ENABLE                          STD_OFF
#define DCM_UDS0x19_SUB0x42_ENABLE                          STD_OFF
#define DCM_UDS0x19_SUB0x55_ENABLE                          STD_OFF


#define DCM_UDS0x10_INTERNAL_FNC_ENABLE                     STD_ON
#define DCM_UDS0x11_INTERNAL_FNC_ENABLE                     STD_ON
#define DCM_UDS0x14_INTERNAL_FNC_ENABLE                     STD_ON
#define DCM_UDS0x19_INTERNAL_FNC_ENABLE                     STD_ON
#define DCM_UDS0x22_INTERNAL_FNC_ENABLE                     STD_ON
#define DCM_UDS0x27_INTERNAL_FNC_ENABLE                     STD_ON
#define DCM_UDS0x28_INTERNAL_FNC_ENABLE                     STD_ON
#define DCM_UDS0x2E_INTERNAL_FNC_ENABLE                     STD_ON
#define DCM_UDS0x31_INTERNAL_FNC_ENABLE                     STD_ON
#define DCM_UDS0x3E_INTERNAL_FNC_ENABLE                     STD_ON
#define DCM_UDS0x85_INTERNAL_FNC_ENABLE                     STD_ON
#define DCM_DSD_SERVICE_CONDITION_CHECK_FNC_USED            STD_ON
#define DCM_DSD_SUB_SERVICE_CONDITION_CHECK_FNC_USED        STD_ON
#define DCM_DSD_SERVICE_P4_TIMER_ENABLE                     STD_ON
#define DCM_DSD_SUB_SERVICE_P4_TIMER_ENABLE                 STD_ON

/* DcmDsl */
#define DCM_DSL_DIAG_RESP_MAX_NUM_RESP_PEND                 10u
#define DCM_DSL_PROTOCOLROW_NUM                             1u
#define DCM_DSL_MAIN_CONNECTION_NUM                         1u
#define DCM_DSL_RESPONSE_ON_EVENT_NUM                       0u
#define DCM_DSL_PROTOCOL_RX_NUM                             1u
#define DCM_DSL_PROTOCOL_TX_NUM                             1u
#define DCM_DSL_PERIODIC_CONNECTION_NUM                     0u
#define DcmConf_DcmDslProtocolRx_PduR_To_Dcm_MasterReq_Rx                      0u
#define DcmConf_DcmDslProtocolTx_Dcm_To_PduR_SlaveResp_Tx                      0u

#define DCM_DSL_CALLBACK_DCM_REQUEST_SERVICE_ENABLED        STD_OFF
#define DCM_DSL_DIAG_RESP_ON_SECOND_DECLINED_REQUEST        STD_ON
#define DCM_DSL_CANCEL_RECEIVE_ENABLE                       STD_OFF
#define DCM_DSL_CANCEL_TRANSMIT_ENABLE                      STD_OFF

/* DcmDsp */
#define DCM_DSP_DATA_DEFAULT_ENDIANNESS                     DCM_OPAQUE
#define DCM_DSP_MAX_DID_TO_READ                             50u
#define DCM_DSP_MAX_PERIODIC_DID_TO_READ                    0u
#define DCM_DSP_POWER_DOWN_TIME                             0u
#define DCM_DSP_TRANSFER_EXIT_REQ_RECORD_SIZE               0u
#define DCM_DSP_COMMON_AUTHORIZATION_NUM                    2u
#define DCM_DSP_COM_CONTROL_ALL_CHANNEL_NUM                 1u
#define DCM_DSP_COM_CONTROL_SPECIFIC_CHANNEL_NUM            1u
#define DCM_DSP_COM_CONTROL_SUB_NODE_NUM                    0u
#define DCM_DSP_DATA_NUM                                    12u
#define DCM_DSP_DATA_BLOCK_USED_NUM                         0u
#define DCM_DSP_DID_NUM                                     12u
#define DCM_DSP_DDDID_NUM                                   0u
#define DCM_DSP_DID_SIGNAL_NUM                              12u
#define DCM_DSP_DID_INTO_NUM                                12u
#define DCM_DSP_DDDID_ELEMENT_MAX_NUM                       0u
#define DCM_DSP_DID_DATA_MAX_SIZE                           47u
#define DCM_DSP_DID_RANGE_NUM                               0u
#define DCM_DSP_MEMORY_NUM                                  1u
#define DCM_DSP_MEMORY_FORMAT_ID_NUM                        0u
#define DCM_DSP_MEMORY_ID_INFO_NUM                          1u
#define DCM_DSP_READ_MEMORY_RANGE_INFO_NUM                  1u
#define DCM_DSP_WRITE_MEMORY_RANGE_INFO_NUM                 0u
#define DCM_DSP_MAX_PERIODIC_DID_SCHEDULER                  0u
#define DCM_DSP_PERIODIC_TRANSMISSION_FAST_RATE             0u
#define DCM_DSP_PERIODIC_TRANSMISSION_MEDIUM_RATE           0u
#define DCM_DSP_PERIODIC_TRANSMISSION_SLOW_RATE             0u
#define DCM_DSP_PID_NUM                                     0u
#define DCM_DSP_READ_DTC_INFORMATION_NUM                    0u
#define DCM_DSP_REQUEST_CONTROL_NUM                         0u
#define DCM_DSP_REQUEST_FILE_TRANSFER_NUM                   0u
#define DCM_DSP_ROE_NUM                                     0u
#define DCM_DSP_ROUTINE_NUM                                 1u
#define DCM_DSP_REQUEST_ROUTINE_RESULTS_IN_SIGNAL_NUM       0u
#define DCM_DSP_REQUEST_ROUTINE_RESULTS_OUT_SIGNAL_NUM      0u
#define DCM_DSP_START_ROUTINE_IN_SIGNAL_NUM                 0u
#define DCM_DSP_START_ROUTINE_OUT_SIGNAL_NUM                1u
#define DCM_DSP_STOP_ROUTINE_IN_SIGNAL_NUM                  0u
#define DCM_DSP_STOP_ROUTINE_OUT_SIGNAL_NUM                 0u
#define DCM_DSP_SECURITY_MAX_ATTEMPT_COUNTER_READOUT_TIME   0u
#define DCM_DSP_SECURITY_ROW_NUM                            1u
#define DCM_DSP_SESSION_ROW_NUM                             3u
#define DCM_DSP_DEFAULT_SESSION_ROW_IDX                     0u
#define DCM_DSP_VEHINFO_NUM                                 0u

#define DCM_DSP_DDDID_CHECK_PER_SOURCE_DID                  STD_OFF
#define DCM_DSP_TRNASFER_ERROR_HANDLING_ENABLE              STD_OFF
#define DCM_DSP_ENABLE_OBD_MIRROR                           STD_OFF
#define DCM_RESPONSE_TO_ECU_RESET                           DCM_BEFORE_RESET
#define DCM_DSP_SESSION_REF_DATA_TYPE_UINT8                 STD_ON
#define DCM_DSP_SECURITY_REF_DATA_TYPE_UINT8                STD_ON
#define DCM_DSP_DATA_CONDITION_CHECK_READ_FNC_ENABLED       STD_ON
#define DCM_DSP_DATA_ECU_SIGNAL_FNC_ENABLED                 STD_OFF
#define DCM_DSP_DATA_FREEZE_CURRENT_STATE_FNC_ENABLED       STD_OFF
#define DCM_DSP_DATA_GET_SCALING_INFO_FNC_ENABLED           STD_OFF
#define DCM_DSP_DATA_READ_DATA_LENGTH_FNC_ENABLED           STD_OFF
#define DCM_DSP_DATA_READ_ECU_SIGNAL_FNC_ENABLED            STD_OFF
#define DCM_DSP_DATA_READ_FNC_ENABLED                       STD_ON
#define DCM_DSP_DATA_RESET_TO_DEFAULT_FNC_ENABLED           STD_OFF
#define DCM_DSP_DATA_RETURN_CONTROL_TO_ECU_FNC_ENABLED      STD_OFF
#define DCM_DSP_DATA_SHORT_TERM_ADJUSTMENT_FNC_ENABLED      STD_OFF
#define DCM_DSP_DATA_WRITE_FNC_ENABLED                      STD_OFF
#define DCM_DSP_DID_RANGE_IS_DID_AVAILABLE_FNC_ENABLE       STD_OFF
#define DCM_DSP_DID_RANGE_READ_DATA_LENGTH_FNC_ENABLE       STD_OFF
#define DCM_DSP_DID_RANGE_READ_DID_FNC_ENABLE               STD_OFF
#define DCM_DSP_DID_RANGE_WRITE_DID_FNC_ENABLE              STD_OFF
#define DCM_DSP_SECURITY_ATTEMPT_COUNTER_DELAY_END_RESET    STD_ON
#define DCM_DSP_SECURITY_ATTEMPT_COUNTER_ENABLED            STD_OFF
#define DCM_DSP_ROUTINE_REQUEST_RESULTS_ENABLED             STD_OFF
#define DCM_DSP_ROUTINE_START_ENABLED                       STD_ON
#define DCM_DSP_ROUTINE_STOP_ENABLED                        STD_OFF
#define DCM_DSP_ROUTINE_CONFIRMATION_FNC_ENABLED            STD_OFF
#define DCM_DSP_REQUEST_CONFIRMATION_FNC_ENABLED            STD_OFF
#define DCM_DSP_START_CONFIRMATION_FNC_ENABLED              STD_OFF
#define DCM_DSP_STOP_CONFIRMATION_FNC_ENABLED               STD_OFF
#define DCM_DSP_SESSION_TIM_P2_PENDING_WINDOW               STD_ON
#define DCM_DSP_SECURITY_ATTEMPT_COUNTER_BLOCK_ID_REF       0u

/* DcmPageBufferCfg */
#define DCM_PAGED_BUFFER_ENABLED                            STD_OFF

/* DcmProcessingConditions */
#define DCM_PROCESSING_CONDITIONS_ENABLED                   STD_OFF
/*====================================================================================================*
 *                                               ENUMS
 *====================================================================================================*/

/*====================================================================================================*
 *                                   STRUCTURES AND OTHER TYPEDEFS
 *====================================================================================================*/

/*====================================================================================================*
 *                                    GLOBAL VARIABLE DECLARATIONS
 *====================================================================================================*/

/*====================================================================================================*
 *                                        FUNCTION PROTOTYPES
 *====================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* DCM_CFG_H */
/** @} */
