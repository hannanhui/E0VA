/**
  * @file        LinIf.c
  * @brief       AUTOSAR LinIf.c  - LinIf.c source file.
  * @details     LinIf driver source file, containing the C implementation of Autosar API specification
  *              and other variables and functions that are exported by the LinIf driver.
  * @addtogroup  LinIf
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

/* PRQA S 0292, 0288, 1503, 1505, 0857, 0791, 0828, 0647 EOF #
*
* 1.0292 -- Violates MISRA 2004 Required Rule 3.1, Source file has comments containing one of the
* characters '$', '@' or '`'.
*
* 2.0288 -- Violates MISRA 2004 Required Rule 3.1, Source file has comments containing characters
* which are not members of the basic source character set.
*
* 3.1503 -- Violates MISRA 2004 Required Rule 14.1, The function is defined but is not used within
* this project.
*
* 4.1503 -- Violates MISRA 2004 Required Rule 8.10, The function is only referenced in the
* translation unit where it is defined.
*
* 5.0857 -- Violates MISRA 2004 Required Rule 1.1, Number of macro definitions exceeds 1024 -
* program does not conform strictly to ISO:C90.
*
* 6.0791 -- Violates MISRA 2004 Required Rule 5.1, Macro identifier does not differ from other
* macro identifier(s) within the specified number of significant characters.
*
* 7.0828 -- Violates MISRA 2004 Required Rule 1.1, More than 8 levels of nested conditional
* inclusion - program does not conform strictly to ISO:C90.
*
* 8.0647 -- Violates MISRA 2004 Required Rule 1.1, Number of enumeration constants exceeds
* 127 - program does not conform strictly to ISO:C90.
*
* @page misra_violations MISRA-C:2004 violations
*/

/* PRQA S 0491, 2877, 2982, 3219, 0771, 0715  EOF #
*
* 1.0491 -- Violates MISRA 2004 Required Rule 3.1, Array subscripting applied to an object of
* pointer type. does not conform strictly to ISO:C90.
*
* 2.2877 -- Violates MISRA 2004 Required Rule 21.1, This loop will never be executed
* more than once.
*
* 3.2982 -- Violates MISRA 2004 Required Rule 21.1, This assignment is redundant.
* The value of this object is never used before being modified.
*
* 4.3219 -- Violates MISRA 2004 Required Rule 14.1, Static function 'xxx' is not used
* within this translation unit.
*
* 5.0771 -- Violates MISRA 2004 Required Rule 14.6, More than one 'break' statement has been
*           used to terminate this iteration statement.
*
* 6.0715 -- Violates MISRA 2004 Required Rule 14.6, Nesting of control structures (statements)
* exceeds 15 - program does not conform strictly to ISO:C90.
*
* @page misra_violations MISRA-C:2004 violations
*/

/*====================================================================================================*
 *                                           INCLUDE FILES
 *====================================================================================================*/

#include "LinIf.h"
#include "LinIf_Cbk.h"
#if(LINIF_TP_SUPPORTED == STD_ON)
#include "Dcm_Cbk.h"
#endif /* LINIF_TP_SUPPORTED == STD_ON */

#if(LINIF_BUS_MIRRORING_SUPPORTED == STD_ON)
#include "Mirror.h"
#endif /* LINIF_BUS_MIRRORING_SUPPORTED == STD_ON */

#if (LINIF_SLAVE_RESPONSE_ERROR_SIGNAL == STD_ON)
#include "Com.h"
#endif /* LINIF_SLAVE_RESPONSE_ERROR_SIGNAL == STD_ON */

#if(LINIF_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */

/*====================================================================================================*
 *                                  SOURCE FILE VERSION INFORMATION
 *====================================================================================================*/

#define LINIF_VENDOR_ID_C 						   0U
#define LINIF_AR_RELEASE_MAJOR_VERSION_C           4U
#define LINIF_AR_RELEASE_MINOR_VERSION_C           2U
#define LINIF_AR_RELEASE_REVISION_VERSION_C        2U
#define LINIF_SW_MAJOR_VERSION_C                   1U
#define LINIF_SW_MINOR_VERSION_C                   0U
#define LINIF_SW_PATCH_VERSION_C                   0U

/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/
/* Check if current file and LinIf header file are of the same vendor */
#if(LINIF_VENDOR_ID_C != LINIF_VENDOR_ID )
#error "LinIf.c and LinIf.h have different vendor id"
#endif

/* Check if current file and LinIf header file are of the same Autosar version */
#if(\
	(LINIF_AR_RELEASE_MAJOR_VERSION_C != LINIF_AR_RELEASE_MAJOR_VERSION) || \
	(LINIF_AR_RELEASE_MINOR_VERSION_C != LINIF_AR_RELEASE_MINOR_VERSION) || \
	(LINIF_AR_RELEASE_REVISION_VERSION_C != LINIF_AR_RELEASE_REVISION_VERSION) \
	)
#error "AutoSar Version Number of LinIf.c and LinIf.h are different "
#endif

/* Check if current file and LinIf header file are of the same Software version */
#if(\
	(LINIF_SW_MAJOR_VERSION_C != LINIF_SW_MAJOR_VERSION) || \
	(LINIF_SW_MINOR_VERSION_C != LINIF_SW_MINOR_VERSION) || \
	(LINIF_SW_PATCH_VERSION_C != LINIF_SW_PATCH_VERSION) \
	)
#error "Software Version Number of LinIf.c and LinIf.h are different "
#endif

#ifndef  DISABLE_INTERMOD_VERSION_CHECK
#if (LINIF_DEV_ERROR_DETECT == STD_ON)
/* Check if current file and Det header file are of the same Autosar version */
#if(\
	(LINIF_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
	(LINIF_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION) \
	)
#error "AutoSar Version Number of LinIf.c and Det.h are different "
#endif
#endif
#endif /* DISABLE_INTERMOD_VERSION_CHECK */

/*====================================================================================================*
 *                                   EXTERNAL FUNCTION DECLARATIONS
 *====================================================================================================*/

extern boolean bInforSwitch;

/*====================================================================================================*
 *                                           LOCAL TYPEDEFS
 *====================================================================================================*/
/**
 * @brief Transmission status of the slave data frame.
 */
typedef enum
{
	/**
	 *  @brief The channel is in a silent state.
	 */
	LINIF_CH_TRANS_SILENT = 0x00U,

	/**
	 * @brief This channel receives the frame header.
	 */
	LINIF_CH_TRANS_HEADER = 0x01U,

	/**
	 *  @brief This channel is in the state of processing responses.
	 */
	LINIF_CH_TRANS_RESPONSE = 0x02U
}LinIf_ChannelTransStatus;

/**
 * @brief The sub state of each channel.
 * @req [SWS_LinIf_00441] The LIN channel sub-state-machine shall have the state
 *      LINIF_CHANNEL_OPERATIONAL.
 * @req [SWS_LinIf_00442] The LIN channel sub-state-machine shall have the state
 *      LINIF_CHANNEL_SLEEP.
 */
typedef enum
{
	/**
	 *  @brief The state LINIF_CHANNEL_OPERATIONAL.
	 */
	LINIF_CHANNEL_OPERATIONAL  = 0x02U,

	/**
	 *  @brief The state LINIF_CHANNEL_SLEEP.
	 */
	LINIF_CHANNEL_SLEEP        = 0x03U

}LinIf_ChannelSubStatus;

/**
 * @brief The type of structure that holds the scheduling information for each channel.
 */
typedef struct
{
	/**
	 * @brief Wake up process,receive frame header flag bit.
	 */
	VAR(boolean,AUTOMATIC) bWakeReqFlag;
	
	/**
	 * @brief Node Configuration response flags.
	 */
	 VAR(boolean,AUTOMATIC) bNcResponseFlag;

	/**
	 * @brief N_As timeout monitoring enable switch.
	 */
	 VAR(boolean,AUTOMATIC) bNasTimerSwitch;

	/**
	 * @brief The N_As time of the channel.
	 */
	 VAR(uint16, AUTOMATIC) u16NasTimer;
	/**
	 * @brief Bus idle timeout monitoring enable switch.
	 */
	 VAR(boolean,AUTOMATIC) bBusIdleTimerSwitch;

	/**
	 * @brief The bus idle time of the channel.
	 */
     VAR(uint16, AUTOMATIC) u16BusIdleTimer;

 	/**
 	 * @brief Slave node Error Signal value.
 	 */
     VAR(boolean,AUTOMATIC) bErrorSignalValue;

	/**
	 * @brief Tx Pdu Information.
	 */
	 VAR(PduInfoType,AUTOMATIC) txPduInfo ;

 	/**
 	 * @brief The sub state of each channel.
 	 */
	 VAR(LinIf_ChannelSubStatus, LINIF_VAR)  u8LinIfChannleSubStatus;

	/**
	 * @brief The data transmission status of the channel.
	 */
	 VAR(LinIf_ChannelTransStatus,LINIF_VAR)  u8LinIfChTransStatus;

	/**
	 * @brief The data frames currently active on the channel.
	 */
	 P2CONST(LinIf_FrameCfgType,AUTOMATIC,LINIF_APPL_CONST) curLinIfFrames;

	/**
	 * @brief The data frames currently active on the channel.
	 */
	 P2CONST(LinIf_SubstitutionFramesCfgType,AUTOMATIC,LINIF_APPL_CONST) subFramePtr;

}LinIf_SlaveChannelRunningType;


#if (LINIF_TP_SUPPORTED == STD_ON)
/**
 * @brief Request type for TP message.
 */
typedef enum{
	/* Function request type..*/
	LINTP_FUN_REQUEST_TYPE = 0x01U,
	/* Physical request type..*/
	LINTP_PHY_REQUEST_TYPE = 0x02U,
}LinTp_RequestType;

/**
 * @brief The sub states of each segment received by LinTp.
 */
typedef enum{
	/* The receiving status is in an idle state. */
	LINTP_RX_IDLE = 0x00U,
	/* The receiving status is in the state of receiving a single frame. */
	LINTP_RX_SF_STATUS = 0x01U,
	/* The receiving status is in the state of receiving a first frame. */
	LINTP_RX_FF_STATUS = 0x02U,
	/* The receiving status is in the state of receiving continuation frame. */
	LINTP_RX_CF_STATUS = 0x03U,
	/* The receiving status is in a waiting state for receiving continuation frame. */
	LINTP_RX_CF_WAIT_STATUS = 0x04U,
	/* Request buffer status. */
	LINTP_RX_REQUEST_BUFFER_STATUS = 0x05U
}LinTp_RxStatus;

/**
 * @brief The sub states of each segment send by LinTp.
 */
typedef enum{
	/* The sending status is in an idle state. */
	LINTP_TX_IDLE = 0x00U,
	/* The sending status is in the state of receiving a single frame. */
	LINTP_TX_SF_STATUS = 0x01U,
	/* The sending status is in the state of receiving a first frame. */
	LINTP_TX_FF_STATUS = 0x02U,
	/* The sending status is in the state of receiving continuation frame. */
	LINTP_TX_CF_STATUS = 0x03U,
	/* Send confirmation status. */
	LINTP_TX_CONFIRMATION_STATUS = 0x04U
}LinTp_TxStatus;

/**
 * @brief Runtime data of LinTp Channel.
 */
typedef struct {
	/**
	 * @brief N_Cr timeout monitoring enable switch.
	 */
	 VAR(boolean,AUTOMATIC) bNcrTimerSwitch;

	/**
	 * @brief The N_Cr time of the channel.
	 */
	 VAR(uint16, AUTOMATIC) u16NcrTimer;

	/**
	 * @brief N_As timeout monitoring enable switch.
	 */
	 VAR(boolean,AUTOMATIC) bNasTimerSwitch;

	/**
	 * @brief The N_As time of the channel.
	 */
	 VAR(uint16, AUTOMATIC) u16NasTimer;

	/**
	 * @brief N_Cs timeout monitoring enable switch.
	 */
	 VAR(boolean,AUTOMATIC) bNcsTimerSwitch;

	/**
	 * @brief The N_Cs time of the channel.
	 */
	 VAR(uint16, AUTOMATIC) u16NcsTimer;

	/**
	 * @brief TpSduLength is the total length of the Sdu.
	 */
	 VAR(uint16,AUTOMATIC) u32SduLength;

	/**
	 * @brief Effective byte start index.
	 */
	 VAR(uint8,AUTOMATIC) u8BetyIndex;

	/**
	 * @brief Sequence number of consecutive frames.
	 */
	 VAR(uint8,AUTOMATIC) u8SequenceNum;

	/**
	 * @brief LinTp Channel Status.
	 */
	 VAR(uint8,AUTOMATIC) u8SubChStatus;

	/**
	 * @brief LinTp Channel Status.
	 */
	 VAR(uint8,AUTOMATIC) u8CopyCnt;

	/**
	 * @brief The request type of the current TP message.
	 */
	 VAR(LinTp_RequestType,AUTOMATIC) eOngoingRequest;

	/**
	 * @brief remaining length of data.
	 */
	 VAR(PduLengthType,AUTOMATIC) SduRemaining;

	/**
	 * @brief Remaining length of upper buffer zone.
	 */
	 VAR(PduLengthType,AUTOMATIC) UpperBufRemaining;

	/**
	 * @brief The status of each stage of channel data reception.
	 */
	 VAR(LinTp_RxStatus,AUTOMATIC) LinTpRxStatus;

	/**
	 * @brief Status of various stages of channel data transmission.
	 */
	 VAR(LinTp_TxStatus,AUTOMATIC) LinTpTxStatus;

	 /* Temporary data buffer. */
	 VAR(uint8,AUTOMATIC) SduRxBuffer[LINTP_FRAME_MAX_LEN];

	 /* Temporary data buffer. */
	 VAR(uint8,AUTOMATIC) SduTxBuffer[LINTP_FRAME_MAX_LEN];

	 /* Related Rx Sdu  configuration.. */
	 P2CONST(LinTp_RxNSduType,AUTOMATIC,LINIF_APPL_CONST) LinTpRxNSdu;

	 /* Related Tx Sdu  configuration.. */
	 P2CONST(LinTp_TxNSduType,AUTOMATIC,LINIF_APPL_CONST) LinTpTxNSdu;

	 /* Associated channel configuration. */
	 P2CONST(LinTp_ChannelConfigType,AUTOMATIC,LINIF_APPL_CONST) LinTpChannel;
}LinIf_SlaveTpRunCfgType;
#endif /* LINIF_TP_SUPPORTED == STD_ON */

/*====================================================================================================*
 *                                            LOCAL MACROS
 *====================================================================================================*/

#define STATIC static
#define STATIC_INLINE static inline

/**
 * @brief            LINIF Module states
 * @details          The state LIN_UNINIT means that the LinIf module has not
 *                   been initialized yet and cannot be used.
 * @req [SWS_LinIf_00438] The LIN Interface state-machine shall have the state
 *      LINIF_UNINIT.
 *
 */
#define LINIF_UNINIT              								     ((uint8)0x01U)

/**
 * @brief            LINIF Module states
 * @details          The LINIF_INIT state indicates that the LinIf module has been
 *                   initialized, making each available channel ready for service.
 * @req [SWS_LinIf_00439] The LIN Interface state-machine shall have the state
 *      LINIF_INIT.
 */
#define LINIF_INIT                								     ((uint8)0x02U)

#if (LINIF_TP_SUPPORTED ==STD_ON)
/**
 * @brief            LINTP Module states
 * @req [SWS_LinIf_00316] The LIN TP state-machine shall have the state LINTP_UNINIT
 */
#define LINTP_UNINIT                                                 ((uint8)0x03U)

/**
 * @brief            LINTP Module states
 * @req [SWS_LinIf_00319] The LIN TP state-machine shall have the state LINTP_INIT.
 */
#define LINTP_INIT                                                   ((uint8)0x04U)

/**
 * @brief            LINTP Module sub states
 * @req [SWS_LinIf_00450] The sub-state-machine of the state LINTP_INIT
 *                        shall have the state LINTP_CHANNEL_IDLE.
 */
#define LINTP_CHANNEL_IDLE                                           ((uint8)0x05U)

/**
 * @brief            LINTP Module sub states
 * @req [SWS_LinIf_00322] The sub-state-machine of the state LINTP_INIT shall have the
 *                        state LINTP_CHANNEL_BUSY
 */
#define LINTP_CHANNEL_BUSY                                           ((uint8)0x06U)
#endif /* LINIF_TP_SUPPORTED ==STD_ON */

/**
 * @brief Defines the type and mask
 */
#define LINIF_PCI_MASK                                              ((uint8)0xF0U)
#define LINIF_PCI_LN_MASK                                           ((uint8)0x0FU)
#define LINIF_LEN_MASK                                              ((uint8)0xFFU)
#define LINIF_PCI_SF                                                ((uint8)0x00U)
#define LINIF_PCI_FF                                                ((uint8)0x10U)
#define LINIF_PCI_CF                                                ((uint8)0x20U)

/**
 * @brief Offset index of a byte in a Pdu.
 */
#define LINIF_PDU_NAD_OFFSET                                        ((uint8)0U)
#define LINIF_PDU_PCI_OFFSET                                        ((uint8)1U)
#define LINIF_PDU_LEN_OFFSET                                        ((uint8)2U)

/**
 * @brief Node Configuration Data Offset.
 */
#define LINIF_PDU_NODE_CFG_DATA1_OFFSET                             ((uint8)3U)
#define LINIF_PDU_NODE_CFG_DATA2_OFFSET                             ((uint8)4U)
#define LINIF_PDU_NODE_CFG_DATA3_OFFSET                             ((uint8)5U)
#define LINIF_PDU_NODE_CFG_DATA4_OFFSET                             ((uint8)6U)
#define LINIF_PDU_NODE_CFG_DATA5_OFFSET                             ((uint8)7U)

#define LINIF_PDU_SF_SID_OFFSET                                     ((uint8)2U)
#define LINIF_PDU_SF_RSID_OFFSET                                    ((uint8)2U)
#define LINIF_PDU_SF_DATA_OFFSET                                    ((uint8)3U)

#define LINIF_PDU_SF_NR_SID_OFFSET                                  ((uint8)3U)
#define LINIF_PDU_SF_NR_DATA_OFFSET                                 ((uint8)4U)
#define LINIF_PDU_FF_SID_OFFSET                                     ((uint8)3U)
#define LINIF_PDU_FF_RSID_OFFSET                                    ((uint8)3U)
#define LINIF_PDU_FF_DATA_OFFSET                                    ((uint8)3U)
#define LINIF_PDU_CF_DATA_OFFSET                                    ((uint8)2U)

/**
 * @brief Defines the SID/RSID negative response value and the error Id.
 */
#define LINIF_BROADCAST_NAD                                         ((uint8)0x7FU)
#define LINIF_NR_PENDING                                            ((uint8)0x78U)
#define LINIF_FUNCTIONAL_NAD                                        ((uint8)0x7EU)
#define LINIF_SLEEP_NAD                                             ((uint8)0x00U)

/**
 * @brief Defines the  length of the frame .
 */
#define LINIF_FRAME_MAX_LEN                                         ((uint8)8U)
#define LINIF_SF_MIN_LENGTH                                         ((uint8)0U)
#define LINIF_SF_MAX_LENGTH                                         ((uint8)6U)
#define LINIF_FF_MIN_LENGTH                                         ((uint8)7U)
#define LINIF_FF_DATA_LENGTH                                        ((uint8)5U)

#define LINIF_ASSIGN_NAD_SID                                        ((uint8)0xB0U)
#define LINIF_READ_BY_IDENTIFIER_SID                                ((uint8)0xB2U)
#define LINIF_CONDITIONAL_CHANGE_NAD_SID                            ((uint8)0xB3U)
#define LINIF_DATA_DUMP_SID                                         ((uint8)0xB4U)
#define LINIF_ASSIGN_SNPD_SID                                       ((uint8)0xB5U)
#define LINIF_SAVE_CONFIG_SID                                       ((uint8)0xB6U)
#define LINIF_ASSIGN_FRAME_IDENTIFIER_RANGE_SID                     ((uint8)0xB7U)

/**
 * @brief Gets the minimum value between two pieces of data.
 */
#define LINIF_GET_MIN_DATA(num1,num2)                   (num1 < num2 ? num1 : num2)

#define LINTP_TIME_OUT_MS                                           ((uint16)1000)

/*====================================================================================================*
 *                                           LOCAL CONSTANTS
 *====================================================================================================*/

/* Add code here */

/*====================================================================================================*
 *                                           LOCAL VARIABLES
 *====================================================================================================*/
/**
 * @brief  Local copy of the pointer to the configuration data.
 */
STATIC P2CONST(LinIf_ConfigType, LINIF_VAR, LINIF_APPL_CONST) LinIf_ConfigPtr = NULL_PTR;

#if (LINIF_USED_SLAVE_NODE == STD_ON)
/**
 * @brief  Channel Bus Mirroring Enable Flag Array.
 */
#if(LINIF_BUS_MIRRORING_SUPPORTED == STD_ON)
STATIC VAR(boolean, LINIF_VAR) LinIf_SlaveChannelBusMirrorFlag[LINIF_MAX_SLAVE_NODE_NUM];
#endif /* LINIF_BUS_MIRRORING_SUPPORTED == STD_ON */

/**
 * @brief  Slave PID Table.
 */
STATIC VAR(Lin_FramePidType, LINIF_VAR) LinIf_SlavePIDTable[LINIF_MAX_SLAVE_NODE_FRAME_NUM];

/**
 * @brief  Slave NAD Table.
 */
STATIC VAR(uint8, LINIF_VAR) LinIf_SlaveConfiguredNAD[LINIF_MAX_SLAVE_NODE_NUM];

/**
 * @brief  Slave Node Configuration response Data
 */
STATIC VAR(uint8, LINIF_VAR) LinIf_SlaveNodeCfgResData[LINIF_MAX_SLAVE_NODE_NUM][8];

/**
 * @brief  Slave Channel Running Status.
 */
STATIC VAR(LinIf_SlaveChannelRunningType, LINIF_VAR) LinIf_SlaveChannelCfg[LINIF_MAX_SLAVE_NODE_NUM];

#endif /* LINIF_USED_SLAVE_NODE == STD_ON */

/**
 * @brief Variable that indicated the state of the driver
 * @req [SWS_LinIf_00438] The LIN Interface state-machine shall have the state LINIF_UNINIT
 */
STATIC VAR(uint8, LINIF_VAR) LinIf_eStatus = LINIF_UNINIT;

#if(LINIF_TP_SUPPORTED == STD_ON)
/**
 * @brief Variable that indicated the state of the driver
 * @req [SWS_LinIf_00315] Each channel of the LIN Interface shall have one instance of
 *      the LIN TP state-machine which is called LIN TP channel state-machine.
 */
STATIC VAR(uint8, LINIF_VAR) LinTp_eStatus = LINTP_UNINIT;

/**
 * @brief  Local copy of the pointer to the configuration data.
 */
STATIC P2CONST(LinTp_ConfigType, LINIF_VAR, LINIF_APPL_CONST) LinTp_ConfigPtr = NULL_PTR;

/**
 * @brief  Slave Tp Channel Running Status.
 */
STATIC VAR(LinIf_SlaveTpRunCfgType, LINIF_VAR) LinTp_SlaveRunCfg[LINTP_MAX_CHANNEL_NUM];
#endif /* LINIF_TP_SUPPORTED == STD_ON */
/*====================================================================================================*
 *                                      LOCAL FUNCTION PROTOTYPES
 *====================================================================================================*/

#if(LINIF_DEV_ERROR_DETECT == STD_ON)
STATIC FUNC(void,LINIF_CODE)LinIf_ReportDetError
(
    VAR(uint8, AUTOMATIC) u8ServiceId,
    VAR(uint8, AUTOMATIC) u8ErrorId
);
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */

#if(LINIF_DEV_ERROR_DETECT == STD_ON)
STATIC FUNC(Std_ReturnType,LINIF_CODE) LinIf_HLDChecksEntry
(
	VAR(uint8, AUTOMATIC) u8LinIfServiceId
);

STATIC FUNC(Std_ReturnType,LINIF_CODE)LinIf_InitCheckPoint
(
    P2CONST(LinIf_ConfigType, AUTOMATIC, LINIF_APPL_CONST)pLinIfCfgPtr ,
    VAR(uint8,AUTOMATIC) u8LinIfServiceId
);

STATIC FUNC(Std_ReturnType,LINIF_CODE)LinIf_TransmitCheckPoint
(
    P2CONST(PduInfoType,AUTOMATIC,LINIF_APPL_CONST) pLinIfCfgPtr ,
    VAR(uint8,AUTOMATIC) u8LinIfServiceId
);
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */

STATIC FUNC(void,LINIF_CODE) LinIf_ResetSlaveChannel
(
	VAR(uint16,AUTOMATIC) u16ChannelIdx
);

STATIC FUNC(uint16,LINIF_CODE)LinIf_SlaveGetConfigChannelIdex
(
    VAR(NetworkHandleType,AUTOMATIC) Channel
);

#if(LINIF_DEV_ERROR_DETECT == STD_ON)
#if (LINIF_TRCV_DRIVER_SUPPORTED == STD_ON)
STATIC FUNC(Std_ReturnType,LINIF_CODE) LinIf_CheckTrcvModeValid
(
    VAR(uint8,AUTOMATIC)u8ServiceId ,
    VAR(LinTrcv_TrcvModeType,AUTOMATIC) mode
);

STATIC FUNC(Std_ReturnType,LINIF_CODE) LinIf_GetTrcvModeCheckPoint
(
    VAR(uint8,AUTOMATIC) u8ServiceId,
	P2VAR(LinTrcv_TrcvModeType, AUTOMATIC,LINIF_APPL_DATA) pLinIfCfgPtr
);

STATIC FUNC(Std_ReturnType,LINIF_CODE) LinIf_GetTrcvWakeupReasonCheckPoint
(
    VAR(uint8,AUTOMATIC) u8ServiceId,
	P2VAR(LinTrcv_TrcvWakeupReasonType,AUTOMATIC,LINIF_APPL_DATA) pLinIfCfgPtr
);

STATIC FUNC(Std_ReturnType,LINIF_CODE) LinIf_CheckWakeupModeValid
(
    VAR(uint8,AUTOMATIC) u8ServiceId ,
    VAR(LinTrcv_TrcvWakeupModeType,AUTOMATIC) mode
);
#endif /* LINIF_TRCV_DRIVER_SUPPORTED == STD_ON */

STATIC FUNC(Std_ReturnType,LINIF_CODE)LinIf_CheckWakeupSource
(
    VAR(uint8,AUTOMATIC) u8ServiceId ,
    VAR(uint16,AUTOMATIC) WakeupSource
);

STATIC FUNC(Std_ReturnType,LINIF_CODE)LinIf_CheckChannelRange
(
    VAR(uint8,AUTOMATIC) u8LinIfServiceId ,
    VAR(uint16,AUTOMATIC) u16ChannelIdx
);

STATIC FUNC(Std_ReturnType,LINIF_CODE)LinIf_HeaderIndicationCheckPoint
(
    P2VAR(Lin_PduType,AUTOMATIC,LINIF_APPL_DATA) pLinIfPduPtr ,
    VAR(uint8,AUTOMATIC) u8LinIfServiceId
);

STATIC FUNC(Std_ReturnType,LINIF_CODE)LinIf_PIDTableCheckPoint
(
    P2VAR(Lin_FramePidType,AUTOMATIC,LINIF_APPL_DATA) pLinIfPidTablePtr ,
    VAR(uint8,AUTOMATIC) u8LinIfServiceId
);

STATIC FUNC(Std_ReturnType,LINIF_CODE)LinIf_ParUint8CheckPoint
(
    P2VAR(uint8,AUTOMATIC,LINIF_APPL_DATA) pLinIfParUint8Ptr ,
    VAR(uint8,AUTOMATIC) u8LinIfServiceId
);

STATIC FUNC(Std_ReturnType,LINIF_CODE)LinIf_GetPIDTableParaCheck
(
	VAR(uint16,AUTOMATIC) u16LinIfChIndex ,
    P2VAR(uint8,AUTOMATIC,LINIF_APPL_DATA) pLinIfParUint8Ptr ,
    VAR(uint8,AUTOMATIC) u8LinIfServiceId
);

STATIC FUNC(Std_ReturnType,LINIF_CODE)LinIf_SetPIDTableParaCheck
(
	VAR(uint16,AUTOMATIC) u16LinIfChIndex ,
    VAR(uint8,AUTOMATIC) u8LinIfBufferLength ,
    VAR(uint8,AUTOMATIC) u8LinIfServiceId
);

STATIC FUNC(Std_ReturnType,LINIF_CODE)LinIf_SetConfiguredNADParCheck
(
    VAR(uint8,AUTOMATIC) u8Parameter ,
    VAR(uint8,AUTOMATIC) u8LinIfServiceId
);
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */

STATIC FUNC(Std_ReturnType,LINIF_CODE)LinIf_Call_Real_GotoSleep
(
	VAR(uint16,AUTOMATIC) Channel
);

STATIC FUNC(Std_ReturnType,LINIF_CODE)LinIf_Call_Real_Wakeup
(
	VAR(uint16,AUTOMATIC) Channel
);

FUNC(Std_ReturnType,LINIF_CODE)LinIf_Call_CheckWakeup
(
	VAR(uint16,AUTOMATIC) Channel
);

STATIC FUNC(void,LINIF_CODE)LinIf_Call_GetPIDTable
(
    VAR(uint16,AUTOMATIC) Channel,
    P2VAR(Lin_FramePidType,AUTOMATIC,LINIF_APPL_DATA) PidBuffer,
	P2VAR(uint8,AUTOMATIC,LINIF_APPL_DATA) PidBufferLength
);

STATIC FUNC(void,LINIF_CODE)LinIf_Call_SetPIDTable
(
    VAR(uint16,AUTOMATIC) Channel,
    P2VAR(Lin_FramePidType,AUTOMATIC,LINIF_APPL_DATA) PidBuffer,
	VAR(uint8,AUTOMATIC) PidBufferLength
);



STATIC FUNC(void,LINIF_CODE) LinIf_SlavePreparePduInfo
(
	P2VAR(Lin_PduType, AUTOMATIC,LINIF_APPL_DATA) PduPtr,
	P2CONST(LinIf_FrameCfgType,AUTOMATIC,LINIF_APPL_CONST) pLinIfFrame
);

STATIC FUNC(Std_ReturnType,LINIF_CODE)LinIf_SlaveHandleUnconditionalHeader
(
	VAR(uint16,AUTOMATIC) Channel,
	P2VAR(Lin_PduType, AUTOMATIC,LINIF_APPL_DATA) PduPtr,
	P2CONST(LinIf_FrameCfgType,AUTOMATIC,LINIF_APPL_CONST) pLinIfFrame
);

STATIC FUNC(Std_ReturnType,LINIF_CODE)LinIf_SlaveHandleMrfHeader
(
	VAR(uint16,AUTOMATIC) Channel,
	P2VAR(Lin_PduType, AUTOMATIC,LINIF_APPL_DATA) PduPtr,
	P2CONST(LinIf_FrameCfgType,AUTOMATIC,LINIF_APPL_CONST) pLinIfFrame
);

STATIC FUNC(Std_ReturnType,LINIF_CODE)LinIf_Call_HeaderIndication
(
    VAR(uint16,AUTOMATIC) Channel,
	P2VAR(Lin_PduType, AUTOMATIC,LINIF_APPL_DATA) PduPtr
);

STATIC FUNC(void,LINIF_CODE)LinIf_SlaveHandleRxUnconitionalData
(
    VAR(uint16,AUTOMATIC) Channel,
	P2VAR(uint8, AUTOMATIC,LINIF_APPL_DATA) Lin_SduPtr
);

#if (LINIF_NC_OPTIONAL_REQUEST_SUPPORTED == STD_ON)
STATIC FUNC(void,LINIF_CODE)LinIf_SlaveNodeAssignNadHandle
(
	VAR(uint16,AUTOMATIC) Channel,
	P2VAR(uint8, AUTOMATIC,LINIF_APPL_DATA) Lin_SduPtr
);
#endif /* LINIF_NC_OPTIONAL_REQUEST_SUPPORTED == STD_ON */

STATIC FUNC(void,LINIF_CODE)LinIf_SlaveNodeReadByIdentiHandle
(
	VAR(uint16,AUTOMATIC) Channel,
	P2VAR(uint8, AUTOMATIC,LINIF_APPL_DATA) Lin_SduPtr
);

#if(LINIF_SAVE_CONFIGURATION_CALLOUT == STD_ON)
STATIC FUNC(void,LINIF_CODE)LinIf_SlaveNodeSaveConfigHandle
(
	VAR(uint16,AUTOMATIC) Channel,
	P2VAR(uint8, AUTOMATIC,LINIF_APPL_DATA) Lin_SduPtr
);
#endif /* LINIF_SAVE_CONFIGURATION_CALLOUT == STD_ON */

STATIC FUNC(void,LINIF_CODE)LinIf_SlaveSetPidCommand
(
	VAR(uint16,AUTOMATIC) Channel,
	P2VAR(uint8, AUTOMATIC,LINIF_APPL_DATA) Lin_SduPtr
);

STATIC FUNC(void,LINIF_CODE)LinIf_SlaveNodeAssignFrameIdentiHandle
(
	VAR(uint16,AUTOMATIC) Channel,
	P2VAR(uint8, AUTOMATIC,LINIF_APPL_DATA) Lin_SduPtr
);

STATIC FUNC(void,LINIF_CODE)LinIf_SlaveHandleRxMrfData
(
    VAR(uint16,AUTOMATIC) Channel,
	P2VAR(uint8, AUTOMATIC,LINIF_APPL_DATA) Lin_SduPtr
);

STATIC FUNC(void,LINIF_CODE)LinIf_Call_RxIndication
(
    VAR(uint16,AUTOMATIC) Channel,
	P2VAR(uint8, AUTOMATIC,LINIF_APPL_DATA) Lin_SduPtr
);

STATIC FUNC(void,LINIF_CODE)LinIf_SlaveHandleTxUnconitionalData
(
    VAR(uint16,AUTOMATIC) Channel
);

STATIC FUNC(void,LINIF_CODE)LinIf_SlaveHandleTxSrfData
(
    VAR(uint16,AUTOMATIC) Channel
);

STATIC FUNC(void,LINIF_CODE)LinIf_Call_TxConfirmation
(
    VAR(uint16,AUTOMATIC) Channel
);

STATIC FUNC(void,LINIF_CODE)LinIf_Call_LinErrorIndication
(
    VAR(uint16,AUTOMATIC) Channel,
	VAR(Lin_SlaveErrorType,AUTOMATIC) ErrorStatus
);

STATIC FUNC(void,LINIF_CODE)LinIf_SlaveSleepProcess
(
	VAR(uint16,AUTOMATIC) Channel
);

#if (LINIF_TP_SUPPORTED == STD_ON)
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
STATIC FUNC(Std_ReturnType,LINIF_CODE) LinTp_HLDChecksEntry
(
  VAR(uint8, AUTOMATIC) u8ServiceId
);

STATIC FUNC(Std_ReturnType,LINIF_CODE)LinTp_InitCheckPoint
(
    P2CONST(LinTp_ConfigType, AUTOMATIC, LINIF_APPL_CONST)pLinTpCfgPtr ,
    VAR(uint8,AUTOMATIC) u8ServiceId
);

STATIC FUNC(Std_ReturnType,LINIF_CODE)LinTp_TransmitCheckPoint
(
    P2CONST(PduInfoType, AUTOMATIC, LINIF_APPL_CONST)pLinTpPtr ,
    VAR(uint8,AUTOMATIC) u8ServiceId
);

STATIC FUNC(Std_ReturnType,LINIF_CODE)LinTp_CheckSduPtrPoint
(
    P2CONST(uint8, AUTOMATIC, LINIF_APPL_CONST)pLinTpPtr ,
    VAR(uint8,AUTOMATIC) u8ServiceId
);
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */

STATIC FUNC(Std_ReturnType,LINIF_CODE) LinTp_CheckTxPduId
(
    VAR(PduIdType, AUTOMATIC) txPduId ,
    VAR(uint8,AUTOMATIC) u8ServiceId,
	P2VAR(uint16, AUTOMATIC,LINIF_APPL_DATA) chIdex
);

STATIC FUNC(void,LINIF_CODE) LinTp_ResetChannel
(
    P2VAR(LinIf_SlaveTpRunCfgType, AUTOMATIC, LINIF_APPL_DATA) chPtr
);

STATIC FUNC_P2CONST(LinTp_RxNSduType, AUTOMATIC, LINIF_APPL_CONST)LinTp_SlaveGetRxNSdu
(
	VAR(uint16,AUTOMATIC) Channel,
	VAR(uint8,AUTOMATIC) u8Nad
);

STATIC FUNC_P2CONST(LinTp_ChannelConfigType, AUTOMATIC, LINIF_APPL_CONST)LinTp_SlaveGetChannel
(
	VAR(NetworkHandleType,AUTOMATIC) Channel,
	P2VAR(uint16,AUTOMATIC,LINIF_APPL_DATA) u16ChIndex
);

STATIC FUNC(void, LINIF_CODE) LinTp_RxSFBufferRequestAndCopyData
(
	VAR(uint16, AUTOMATIC) Channel
);

STATIC FUNC(void,LINIF_CODE)LinTp_SlaveHandleSF
(
	P2VAR(uint8, AUTOMATIC,LINIF_APPL_DATA) Lin_SduPtr,
	P2CONST(LinTp_RxNSduType, AUTOMATIC, LINIF_APPL_CONST) pRxSdu
);

STATIC FUNC(void, LINIF_CODE) LinTp_RxFFBufferRequestAndCopyData
(
	VAR(uint16, AUTOMATIC) Channel
);

STATIC FUNC(void, LINIF_CODE) LinTp_RxCFCopyData
(
	VAR(uint16, AUTOMATIC) Channel
);

STATIC FUNC(void, LINIF_CODE) LinTp_RxCFBufferRequest
(
	VAR(uint16, AUTOMATIC) Channel
);

STATIC FUNC(void,LINIF_CODE)LinTp_SlaveHandleFF
(
	P2VAR(uint8, AUTOMATIC,LINIF_APPL_DATA) Lin_SduPtr,
	P2CONST(LinTp_RxNSduType, AUTOMATIC, LINIF_APPL_CONST) pRxSdu
);

STATIC FUNC(void,LINIF_CODE)LinTp_SlaveHandleCF
(
	P2VAR(uint8, AUTOMATIC,LINIF_APPL_DATA) Lin_SduPtr,
	P2CONST(LinTp_RxNSduType, AUTOMATIC, LINIF_APPL_CONST) pRxSdu
);

STATIC FUNC(void,LINIF_CODE)LinIf_SlaveTransportLayerMrfIndication
(
	VAR(uint16,AUTOMATIC) Channel,
	P2VAR(uint8, AUTOMATIC,LINIF_APPL_DATA) Lin_SduPtr
);

STATIC FUNC(void,LINIF_CODE)LinTp_SlaveHandleSrfSF
(
	VAR(uint8,AUTOMATIC) Nad,
	VAR(uint16,AUTOMATIC) Channel,
	P2VAR(Lin_PduType, AUTOMATIC,LINIF_APPL_DATA) Lin_SduPtr
);

STATIC FUNC(void,LINIF_CODE)LinTp_SlaveHandleSrfFF
(
	VAR(uint8,AUTOMATIC) Nad,
	VAR(uint16,AUTOMATIC) Channel,
	P2VAR(Lin_PduType, AUTOMATIC,LINIF_APPL_DATA) Lin_SduPtr
);

STATIC FUNC(void,LINIF_CODE)LinTp_SlaveHandleSrfCF
(
	VAR(uint8,AUTOMATIC) Nad,
	VAR(uint16,AUTOMATIC) Channel,
	P2VAR(Lin_PduType, AUTOMATIC,LINIF_APPL_DATA) Lin_SduPtr
);

STATIC FUNC(void,LINIF_CODE)LinIf_SlaveTransportLayerSrfIndication
(
	VAR(uint16,AUTOMATIC) Channel,
	P2VAR(Lin_PduType, AUTOMATIC,LINIF_APPL_DATA) Lin_SduPtr
);

STATIC FUNC(Std_ReturnType,LINIF_CODE) LinTp_Call_Transmit
(
    VAR(uint16,AUTOMATIC) Channel,
    P2CONST(PduInfoType,AUTOMATIC,LINIF_APPL_CONST) PduInfoPtr
);

STATIC FUNC(void,LINIF_CODE) LinTp_TimeHandle
(
    VAR(uint16,AUTOMATIC) Channel
);

STATIC FUNC(void,LINIF_CODE) LinTp_SlaveMainFunction(void);
#endif /* LINIF_TP_SUPPORTED == STD_ON */

STATIC FUNC(void,LINIF_CODE) LinIf_TimeHandle
(
    VAR(uint16,AUTOMATIC) Channel
);
/*====================================================================================================*
 *                                           LOCAL FUNCTIONS
 *====================================================================================================*/

#if(LINIF_DEV_ERROR_DETECT == STD_ON)
/**
 * @brief      This function reports an error to the Det module and records the failure in the local structure.
 * @details    This function reports an error to the Det module and records the failure in the local structure.
 *
 * @param[in]  u8ServiceId       The service id of the caller function
 * @param[in]  u8ErrorId         The error id to be reported
 *
 * @return     void
 */
STATIC FUNC(void,LINIF_CODE)LinIf_ReportDetError
(
    VAR(uint8, AUTOMATIC) u8ServiceId,
    VAR(uint8, AUTOMATIC) u8ErrorId
)
{
   (void)Det_ReportError((uint16)LINIF_MODULE_ID, (uint8)LINIF_INSTANCE_ID, u8ServiceId, u8ErrorId);
}
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */

#if(LINIF_DEV_ERROR_DETECT == STD_ON)
/**
 * @brief      LinIf_HLDChecksEntry - checks for invalid mode transitions
 * @details    Check that the timing of the API call is correct
 *
 * @param[in]  u8LinIfServiceId   Service id of the API
 *
 * @return     The timing state of an API call.
 * @retval     E_OK       Call correctly.
 * @retval     E_NOT_OK   Call exception.
 */
STATIC FUNC(Std_ReturnType,LINIF_CODE) LinIf_HLDChecksEntry
(
  VAR(uint8, AUTOMATIC) u8LinIfServiceId
)
{
  VAR(Std_ReturnType, AUTOMATIC) retStatus = (Std_ReturnType)E_OK;
  if((LINIF_SID_INIT == u8LinIfServiceId))
  {
    if(LINIF_INIT == LinIf_eStatus)
    {
        retStatus = (Std_ReturnType)E_NOT_OK;
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
        LinIf_ReportDetError(u8LinIfServiceId , LINIF_E_INIT_FAILED);
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */
    }
  }
  else
  {
    if(LINIF_UNINIT == LinIf_eStatus)
    {
        retStatus = (Std_ReturnType)E_NOT_OK;
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
        LinIf_ReportDetError(u8LinIfServiceId , LINIF_E_UNINIT);
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */
    }
  }

  return  retStatus;
}

/**
 * @brief       LinIf_InitCheckPoint - Checks whether the pointer is valid
 * @details ...
 *
 * @param[in]   pLinIfCfgPtr            Pointer parameter for checking
 * @param[in]   u8LinIfServiceId        Service id of the API
 *
 * @return      Result of examination
 */
STATIC FUNC(Std_ReturnType,LINIF_CODE)LinIf_InitCheckPoint
(
    P2CONST(LinIf_ConfigType, AUTOMATIC, LINIF_APPL_CONST)pLinIfCfgPtr ,
    VAR(uint8,AUTOMATIC) u8LinIfServiceId
)
{
  VAR(Std_ReturnType,AUTOMATIC) retStatus = (Std_ReturnType)E_OK;
  if(NULL_PTR == pLinIfCfgPtr)
  {
      retStatus = (Std_ReturnType)E_NOT_OK;
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
      LinIf_ReportDetError(u8LinIfServiceId,LINIF_E_PARAM_POINTER);
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */
  }
  return retStatus;
}

/**
 * @brief       LinIf_TransmitCheckPoint - Checks whether the pointer is valid
 *
 * @param[in]   pLinIfCfgPtr            Pointer parameter for checking
 * @param[in]   u8LinIfServiceId        Service id of the API
 *
 * @return      Result of examination
 */
STATIC FUNC(Std_ReturnType,LINIF_CODE)LinIf_TransmitCheckPoint
(
    P2CONST(PduInfoType,AUTOMATIC,LINIF_APPL_CONST) pLinIfCfgPtr ,
    VAR(uint8,AUTOMATIC) u8LinIfServiceId
)
{
  VAR(Std_ReturnType,AUTOMATIC) retStatus = (Std_ReturnType)E_OK;
  if(NULL_PTR == pLinIfCfgPtr)
  {
	  /**
	   * @req [SWS_LinIf_00570]  If development error detection is enabled and
	   *       the parameter PduInfoPtr has an invalid value, the function
	   *       LinIf_Transmit shall raise the development error code
	   *       LINIF_E_PARAM_POINTER.
	   */
      retStatus = (Std_ReturnType)E_NOT_OK;
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
      LinIf_ReportDetError(u8LinIfServiceId,LINIF_E_PARAM_POINTER);
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */
  }
  return retStatus;
}
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */

/**
 * @brief      Reset a specific LinIf Slave Channel.
 * @param[in]  u16ChannelIdx LinIf Slave Channel Index.
 *
 * @return     void
 */
STATIC FUNC(void,LINIF_CODE) LinIf_ResetSlaveChannel
(
	VAR(uint16,AUTOMATIC) u16ChannelIdx
)
{
	P2VAR(LinIf_SlaveChannelRunningType,AUTOMATIC,LINIF_APPL_DATA) pChRunStatus = NULL_PTR;

	pChRunStatus = &(LinIf_SlaveChannelCfg[u16ChannelIdx]);
	
	pChRunStatus->curLinIfFrames = NULL_PTR;
	pChRunStatus->bNasTimerSwitch = (boolean)FALSE;
	pChRunStatus->u16NasTimer = 0U;
	pChRunStatus->subFramePtr = NULL_PTR;
	pChRunStatus->u8LinIfChTransStatus = LINIF_CH_TRANS_SILENT;
}

/**
 * @brief   LinIf_SlaveGetConfigChannelIndex - Gets the LinIf Slave channel index.
 */
STATIC FUNC(uint16,LINIF_CODE)LinIf_SlaveGetConfigChannelIdex
(
    VAR(NetworkHandleType,AUTOMATIC) Channel
)
{
	VAR(uint16,AUTOMATIC) u16Loop= 0U;
	VAR(uint16,AUTOMATIC) u16ChIndex = 0xFFU;

	for(u16Loop = 0U ;u16Loop< LINIF_MAX_SLAVE_CHANNEL_NUM ; u16Loop++)
	{
		if(LinIf_ConfigPtr->LinIfSlaveChannel[u16Loop].LinIfComMNetworkHandleIdRef == Channel)
		{
			u16ChIndex = u16Loop;
			break;
		}
	}

   return u16ChIndex;
}

#if(LINIF_DEV_ERROR_DETECT == STD_ON)

#if (LINIF_TRCV_DRIVER_SUPPORTED == STD_ON)
/**
 * @brief  LinIf_CheckTrcvModeValid - Checks whether the mode is valid
 * @details ...
 *
 * @param[in]   mode                    Parameter to be verified.
 * @param[in]   u8ServiceId             Service id of the API
 *
 * @return      Result of examination
 */
STATIC FUNC(Std_ReturnType,LINIF_CODE) LinIf_CheckTrcvModeValid
(
    VAR(uint8,AUTOMATIC)u8ServiceId ,
    VAR(LinTrcv_TrcvModeType,AUTOMATIC) mode
)
{
  VAR(Std_ReturnType,AUTOMATIC) checkStatus = (Std_ReturnType)E_OK ;

  if((LINTRCV_TRCV_MODE_NORMAL != mode) &&
      (LINTRCV_TRCV_MODE_STANDBY != mode) &&
      (LINTRCV_TRCV_MODE_SLEEP != mode))
  {
      checkStatus = (Std_ReturnType)E_NOT_OK;
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
      LinIf_ReportDetError(u8ServiceId,LINIF_E_TRCV_INV_MODE);
#endif/* LINIF_DEV_ERROR_DETECT == STD_ON */
  }

  return checkStatus;
}

/**
 * @brief  LinIf_GetTrcvModeCheckPoint - Checks whether the pointer is valid
 * @details ...
 *
 * @param[in]   pLinIfCfgPtr            Parameter to be verified.
 * @param[in]   u8ServiceId             Service id of the API
 *
 * @return      Result of examination
 */
STATIC FUNC(Std_ReturnType,LINIF_CODE) LinIf_GetTrcvModeCheckPoint
(
    VAR(uint8,AUTOMATIC) u8ServiceId,
	P2VAR(LinTrcv_TrcvModeType, AUTOMATIC,LINIF_APPL_DATA) pLinIfCfgPtr
)
{
  VAR(Std_ReturnType,AUTOMATIC) checkStatus = (Std_ReturnType)E_OK;
  if(NULL_PTR == pLinIfCfgPtr)
  {
      checkStatus = (Std_ReturnType)E_NOT_OK;
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
      LinIf_ReportDetError(u8ServiceId,LINIF_E_PARAM_POINTER);
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */
  }
  return checkStatus;
}

/**
 * @brief  LinIf_GetTrcvWakeupReasonCheckPoint - Checks whether the pointer is valid
 * @details ...
 *
 * @param[in]   pLinIfCfgPtr            Parameter to be verified.
 * @param[in]   u8ServiceId             Service id of the API
 *
 * @return      Result of examination
 */
STATIC FUNC(Std_ReturnType,LINIF_CODE) LinIf_GetTrcvWakeupReasonCheckPoint
(
    VAR(uint8,AUTOMATIC) u8ServiceId,
	P2VAR(LinTrcv_TrcvWakeupReasonType,AUTOMATIC,LINIF_APPL_DATA) pLinIfCfgPtr
)
{
  VAR(Std_ReturnType,AUTOMATIC) checkStatus = (Std_ReturnType)E_OK;
  if(NULL_PTR == pLinIfCfgPtr)
  {
      checkStatus = (Std_ReturnType)E_NOT_OK;
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
      LinIf_ReportDetError(u8ServiceId,LINIF_E_PARAM_POINTER);
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */
  }
  return checkStatus;
}

/**
 * @brief  LinIf_CheckWakeupModeValid - Checks whether the mode is valid
 * @details ...
 *
 * @param[in]   mode                    Parameter to be verified.
 * @param[in]   u8ServiceId        Service id of the API
 *
 * @return      Result of examination
 */
STATIC FUNC(Std_ReturnType,LINIF_CODE) LinIf_CheckWakeupModeValid
(
    VAR(uint8,AUTOMATIC) u8ServiceId ,
    VAR(LinTrcv_TrcvWakeupModeType,AUTOMATIC) mode
)
{
  VAR(Std_ReturnType,AUTOMATIC) checkStatus = (Std_ReturnType)E_OK ;

  if((LINTRCV_WUMODE_ENABLE != mode) &&
      (LINTRCV_WUMODE_DISABLE != mode) &&
      (LINTRCV_WUMODE_CLEAR != mode))
  {
      checkStatus = (Std_ReturnType)E_NOT_OK;
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
      LinIf_ReportDetError(u8ServiceId,LINIF_E_PARAMETER);
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */
  }
  return checkStatus;
}

#endif /* LINIF_TRCV_DRIVER_SUPPORTED == STD_ON */

/**
 * @brief   LinIf_CheckWakeupSource - Check if the current wake-up source is valid.
 * @details ...
 *
 * @param[in]   WakeupSource     Wake up source identifier.
 * @param[in]   u8ServiceId        Service id of the API
 *
 * @return      Result of examination
 */
STATIC FUNC(Std_ReturnType,LINIF_CODE)LinIf_CheckWakeupSource
(
    VAR(uint8,AUTOMATIC) u8ServiceId ,
    VAR(uint16,AUTOMATIC) WakeupSource
)
{
  VAR(Std_ReturnType,AUTOMATIC) retStatus = (Std_ReturnType)E_OK ;
  if(WakeupSource >= 32U)
  {
     retStatus = (Std_ReturnType)E_NOT_OK;
	/**
	 * @req [SWS_LinIf_00717]If development error detection is enabled and the parameter
	 *      WakeupSource has an invalid value, the function LinIf_WakeupConfirmation shall
	 *      raise the development error code LINIF_E_PARAM_WAKEUPSOURCE.
	 */
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
      LinIf_ReportDetError(u8ServiceId,LINIF_E_PARAM_WAKEUPSOURCE);
#endif/* LINIF_DEV_ERROR_DETECT == STD_ON */
  }
  return retStatus;
}

/**
 * @brief   LinIf_CheckChannelRange - Gets whether the LinIf channel is valid.
 * @details ...
 *
 * @param[in]   u16ChannelIdx           Parameter to be verified.
 * @param[in]   u8LinIfServiceId        Service id of the API
 *
 * @return      Result of examination
 */
STATIC FUNC(Std_ReturnType,LINIF_CODE)LinIf_CheckChannelRange
(
    VAR(uint8,AUTOMATIC) u8LinIfServiceId ,
    VAR(uint16,AUTOMATIC) u16ChannelIdx
)
{
  VAR(Std_ReturnType,AUTOMATIC) retStatus = (Std_ReturnType)E_OK ;
  if(u16ChannelIdx == 0xFFU)
  {
      retStatus = (Std_ReturnType)E_NOT_OK;
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
      LinIf_ReportDetError(u8LinIfServiceId,LINIF_E_NONEXISTENT_CHANNEL);
#endif/* LINIF_DEV_ERROR_DETECT == STD_ON */
  }
  return retStatus;
}

/**
 * @brief       LinIf_HeaderIndicationCheckPoint - Checks whether the pointer is valid
 *
 * @param[in]   pLinIfPtr               Pointer parameter for checking
 * @param[in]   u8LinIfServiceId        Service id of the API
 *
 * @return      Result of examination
 */
STATIC FUNC(Std_ReturnType,LINIF_CODE)LinIf_HeaderIndicationCheckPoint
(
    P2VAR(Lin_PduType,AUTOMATIC,LINIF_APPL_DATA) pLinIfPduPtr ,
    VAR(uint8,AUTOMATIC) u8LinIfServiceId
)
{
  VAR(Std_ReturnType,AUTOMATIC) retStatus = (Std_ReturnType)E_OK;
  if(NULL_PTR == pLinIfPduPtr)
  {
      retStatus = (Std_ReturnType)E_NOT_OK;
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
      LinIf_ReportDetError(u8LinIfServiceId,LINIF_E_PARAM_POINTER);
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */
  }
  return retStatus;
}

/**
 * @brief       LinIf_PIDTableCheckPoint - Checks whether the pointer is valid
 *
 * @param[in]   pLinIfPtr               Pointer parameter for checking
 * @param[in]   u8LinIfServiceId        Service id of the API
 *
 * @return      Result of examination
 */
STATIC FUNC(Std_ReturnType,LINIF_CODE)LinIf_PIDTableCheckPoint
(
    P2VAR(Lin_FramePidType,AUTOMATIC,LINIF_APPL_DATA) pLinIfPidTablePtr ,
    VAR(uint8,AUTOMATIC) u8LinIfServiceId
)
{
  VAR(Std_ReturnType,AUTOMATIC) retStatus = (Std_ReturnType)E_OK;
  if(NULL_PTR == pLinIfPidTablePtr)
  {
      retStatus = (Std_ReturnType)E_NOT_OK;
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
      LinIf_ReportDetError(u8LinIfServiceId,LINIF_E_PARAM_POINTER);
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */
  }
  return retStatus;
}

/**
 * @brief       LinIf_ParUint8CheckPoint - Checks whether the pointer is valid
 *
 * @param[in]   pLinIfPtr               Pointer parameter for checking
 * @param[in]   u8LinIfServiceId        Service id of the API
 *
 * @return      Result of examination
 */
STATIC FUNC(Std_ReturnType,LINIF_CODE)LinIf_ParUint8CheckPoint
(
    P2VAR(uint8,AUTOMATIC,LINIF_APPL_DATA) pLinIfParUint8Ptr ,
    VAR(uint8,AUTOMATIC) u8LinIfServiceId
)
{
	VAR(Std_ReturnType,AUTOMATIC) retStatus = (Std_ReturnType)E_OK;
	if(NULL_PTR == pLinIfParUint8Ptr)
	{
	  retStatus = (Std_ReturnType)E_NOT_OK;
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
	  LinIf_ReportDetError(u8LinIfServiceId,LINIF_E_PARAM_POINTER);
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */
	}
	return retStatus;
}

/**
 * @brief       LinIf_GetPIDTableParaCheck - Check if the input parameter value for the
 *                                           detection channel is valid.
 *
 * @param[in]   u16LinIfChIndex              Target channel index to be validated.
 *              pLinIfParUint8Ptr            Pointer to the data to be validated.
 * @param[in]   u8LinIfServiceId             Service id of the API
 *
 * @return      Result of examination
 */
STATIC FUNC(Std_ReturnType,LINIF_CODE)LinIf_GetPIDTableParaCheck
(
	VAR(uint16,AUTOMATIC) u16LinIfChIndex ,
    P2VAR(uint8,AUTOMATIC,LINIF_APPL_DATA) pLinIfParUint8Ptr ,
    VAR(uint8,AUTOMATIC) u8LinIfServiceId
)
{
	VAR(uint8,AUTOMATIC) u8BufferLength = 0U;
	VAR(uint16,AUTOMATIC) u16NormalFrameNum = 0U;
	VAR(Std_ReturnType,AUTOMATIC) retStatus = (Std_ReturnType)E_OK;

	u16NormalFrameNum = (LinIf_ConfigPtr->LinIfSlaveChannel[u16LinIfChIndex].LinIfMaxFramesNum  - 2U);
	u8BufferLength = (*(pLinIfParUint8Ptr));

	if((u8BufferLength != 0U) && (u8BufferLength < u16NormalFrameNum))
	{
		retStatus = (Std_ReturnType)E_NOT_OK;
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
		LinIf_ReportDetError(u8LinIfServiceId,LINIF_E_PARAMETER);
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */
	}
	return retStatus;
}
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */

/**
 * @sid              0x06
 * @brief            Initiates a transition into the Sleep Mode on the selected channel.
 * @param[in]        Channel     LIN  Slave Channel Index.
 * @return           Std_ReturnType
 * @retval E_NOT_OK  Request to go to sleep has not been accepted due to one or more of the following reasons.
 * @retval E_OK      Request to go to sleep has been accepted or sleep
 *                   transition is already in progress or controller is already in sleep state.
 */
STATIC FUNC(Std_ReturnType,LINIF_CODE)LinIf_Call_Real_GotoSleep
(
	VAR(uint16,AUTOMATIC) Channel
)
{
	VAR(NetworkHandleType,AUTOMATIC) netWork;
	P2VAR(LinIf_SlaveChannelRunningType,AUTOMATIC,LINIF_APPL_DATA) pChRunStatus = NULL_PTR;
	pChRunStatus = &(LinIf_SlaveChannelCfg[Channel]);
	
	netWork = LinIf_ConfigPtr->LinIfSlaveChannel[Channel].LinIfComMNetworkHandleIdRef;
	pChRunStatus->bWakeReqFlag = (boolean)FALSE;
	pChRunStatus->bErrorSignalValue = (boolean)FALSE;
	pChRunStatus->bNcResponseFlag = (boolean)FALSE;
	LinIf_ResetSlaveChannel(Channel);
	pChRunStatus->u8LinIfChannleSubStatus = LINIF_CHANNEL_SLEEP;
	pChRunStatus->bBusIdleTimerSwitch = (boolean)FALSE;
	pChRunStatus->u16BusIdleTimer = 0U;
	if(LinIf_ConfigPtr->LinIfSlaveChannel[Channel].LinIfGotoSleepConfirmation != NULL_PTR)
	{
		LinIf_ConfigPtr->LinIfSlaveChannel[Channel].LinIfGotoSleepConfirmation(\
				netWork,(boolean)TRUE);
	}	
	
	return (Std_ReturnType)E_OK;
}

/**
 * @brief            Initiates the wake up process.
 * @param[in]        Channel     LIN Channel Index.
 * @return           Std_ReturnType
 * @retval E_NOT_OK  Request to wake up has not been accepted due to
 *                   one or more of the following reasons
 *                   - LIN Interface has not been initialized
 *                   - referenced channel does not exist (identification is out of range)
 *                   - Lin_Wakeup has returned E_NOT_OK
 *                   - Lin_WakeupInternal has returned E_NOT_OK
 * @retval E_OK      Request to wake up has been accepted or the controller is not in sleep state.
 */
STATIC FUNC(Std_ReturnType,LINIF_CODE)LinIf_Call_Real_Wakeup
(
	VAR(uint16,AUTOMATIC) Channel
)
{
	P2VAR(LinIf_SlaveChannelRunningType,AUTOMATIC,LINIF_APPL_DATA) pChRunStatus = NULL_PTR;

	pChRunStatus = &(LinIf_SlaveChannelCfg[Channel]);
	
	pChRunStatus->bWakeReqFlag = (boolean)TRUE;
	pChRunStatus->u8LinIfChannleSubStatus = LINIF_CHANNEL_OPERATIONAL;
	pChRunStatus->bBusIdleTimerSwitch = (boolean)TRUE;
	pChRunStatus->u16BusIdleTimer = \
		LinIf_ConfigPtr->LinIfSlaveChannel[Channel].LinIfBusIdleTimeoutPeriod;
	
	return (Std_ReturnType)E_OK;
}

/**
 * @brief            Will be called when the EcuM has been notified about a
 *                   wakeup on a specific LIN channel.
 * @param[in]        Channel   LIN Channel Index.
 * @return           Std_ReturnType
 * @retval E_NOT_OK  An error has occurred during execution of the API or invalid WakeupSource
 * @retval E_OK      No error has occurred during execution of the API
 */
FUNC(Std_ReturnType,LINIF_CODE)LinIf_Call_CheckWakeup
(
	VAR(uint16,AUTOMATIC) Channel
)
{
	VAR(uint8,AUTOMATIC) u8RefIndex = 0U;
	VAR(NetworkHandleType,AUTOMATIC) netWork;
	VAR(Std_ReturnType,AUTOMATIC) retStatus = (Std_ReturnType)E_OK;

	u8RefIndex = LinIf_ConfigPtr->LinIfSlaveChannel[Channel].LinIfChannelRefIndex;
	netWork = LinIf_ConfigPtr->LinIfSlaveChannel[Channel].LinIfComMNetworkHandleIdRef;

	/**
	 * @req [SWS_LinIf_00503] The function LinIf_CheckWakeup shall issue the call
	 *      of function Lin_CheckWakeup or LinTrcv_CheckWakeup depending on the
	 *      given parameter WakeupSource.
	 */
	retStatus = LinIf_ConfigPtr->LinIfLinApi[u8RefIndex].LinCheckWakeup(netWork);

#if(LINIF_TRCV_DRIVER_SUPPORTED == STD_ON)
	if(retStatus == ((Std_ReturnType)E_OK))
	{
		if(LinIf_ConfigPtr->LinIfSlaveChannel[Channel].LinIfTrcvIdRef != 0xFFU)
		{
			u8RefIndex = LinIf_ConfigPtr->LinIfSlaveChannel[Channel].LinIfTrcvRefIndex;
			retStatus =  LinIf_ConfigPtr->LinIfLinTrcvApi[u8RefIndex].\
					LinTrcvCheckWakeup((uint8)netWork);
		}
	}
#endif /* LINIF_TRCV_DRIVER_SUPPORTED == STD_ON */

	return retStatus;
}

/**
 * @brief            Retrieves all assigned PID values.
 *                   The order is congruent to the LIN frame index.
 * @param[in]        Channel   LinIf Channel Index.
 *
 * @param[inout]
 *                   PidBuffer Pointer to existing buffer to which the
 *                             current assigned PID values are copied to
 *
 *                   PidBufferLength   Pointer to actual length of provided buffer.
 *                   After successful return, it contains the number of copied PID values.
 *
 * @return           void
 *
 */
STATIC FUNC(void,LINIF_CODE)LinIf_Call_GetPIDTable
(
    VAR(uint16,AUTOMATIC) Channel,
    P2VAR(Lin_FramePidType,AUTOMATIC,LINIF_APPL_DATA) PidBuffer,
	P2VAR(uint8,AUTOMATIC,LINIF_APPL_DATA) PidBufferLength
)
{
	VAR(uint16,AUTOMATIC) u16Loop1 = 0U;
	VAR(uint16,AUTOMATIC) u16Loop2 = 0U;
	VAR(uint16,AUTOMATIC) u16FrameNum = 0U;
	VAR(uint8,AUTOMATIC) u8BufferLength = 0U;
	P2CONST(LinIf_FrameCfgType,AUTOMATIC,LINIF_APPL_CONST) pLinIfFrame = NULL_PTR;

	u8BufferLength = (*(PidBufferLength));

	/**
	 *	@req  [SWS_LinIf_00828] If the length of the buffer (provided by parameter
	 *	      PidBufferLength) is 0, the function shall return the number of configured
	 *	      PIDs of the slave node in parameter PidBufferLength, without updating the
	 *	      PID buffer with PIDs.
	 */
	(*PidBufferLength) =  LinIf_ConfigPtr->LinIfSlaveChannel[Channel].LinIfMaxFramesNum - 2U;

	if(u8BufferLength != 0U)
	{
		u8BufferLength = (*(PidBufferLength));

		u16FrameNum = LinIf_ConfigPtr->LinIfSlaveChannel[Channel].LinIfMaxFramesNum;
		/**
		 *  @req [SWS_LinIf_00816] This API shall return the configured PIDs of all frames
		 *       relevant for the slave node. The order shall be ascending corresponding to the
		 *       configuration parameter LinIfFrameIndex. The value of PidBufferLength shall be
		 *       updated with the actual number of configured PIDs.
		 *
		 *  @req [SWS_LinIf_00817] The returned PID list shall not include the PIDs for MRF
		 *       and SRF.
		 */
		for(u16Loop1 = 0U;u16Loop1< u8BufferLength; u16Loop1++)
		{
			for(u16Loop2 = 0U; u16Loop2< u16FrameNum;  u16Loop2++)
			{
				pLinIfFrame = &(LinIf_ConfigPtr->LinIfSlaveChannel[Channel].LinIfFrames[u16Loop2]);

				if((pLinIfFrame->LinIfFrameType == LINIF_UNCONDITIONAL) || \
						(pLinIfFrame->LinIfFrameType == LINIF_EVENT_TRIGGERED))
				{
					if(pLinIfFrame->LinIfFrameIndex == u16Loop1)
					{
						(*(PidBuffer + u16Loop1)) = LinIf_SlavePIDTable[pLinIfFrame->LinIfFrameTableIndex];
					}
				}
			}
		}
	}
}

#if(LINIF_DEV_ERROR_DETECT == STD_ON)
/**
 * @brief       LinIf_SetPIDTableParaCheck - Check if the input parameter value for the
 *                                           detection channel is valid.
 *
 * @param[in]   u16LinIfChIndex              Target channel index to be validated.
 *              u8LinIfBufferLength          the data to be validated.
 * @param[in]   u8LinIfServiceId             Service id of the API
 *
 * @return      Result of examination
 */
STATIC FUNC(Std_ReturnType,LINIF_CODE)LinIf_SetPIDTableParaCheck
(
	VAR(uint16,AUTOMATIC) u16LinIfChIndex ,
    VAR(uint8,AUTOMATIC) u8LinIfBufferLength ,
    VAR(uint8,AUTOMATIC) u8LinIfServiceId
)
{
	VAR(uint16,AUTOMATIC) u16NormalFrameNum = 0U;
	VAR(Std_ReturnType,AUTOMATIC) retStatus = (Std_ReturnType)E_OK;

	u16NormalFrameNum = LinIf_ConfigPtr->LinIfSlaveChannel[u16LinIfChIndex].LinIfMaxFramesNum - 2U ;

	if(u8LinIfBufferLength < u16NormalFrameNum)
	{
		retStatus = (Std_ReturnType)E_NOT_OK;
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
		LinIf_ReportDetError(u8LinIfServiceId,LINIF_E_PARAMETER);
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */
	}

	return retStatus;
}
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */
/**
 * @brief            Sets all assigned PID values. The order is congruent to the LIN frame index.
 * @details          This API shall update the internal configured PID list in LIN
 *                   Interface with the given PID list.
 * @param[in]        Channel   identification of the LIN channel.
 *
 *                   PidBuffer  Pointer to buffer which contains the PID values to configure.
 *
 *                   PidBufferLength Number of PID values in the provided buffer
 *
 * @return           void
 *
 */
STATIC FUNC(void,LINIF_CODE)LinIf_Call_SetPIDTable
(
    VAR(uint16,AUTOMATIC) Channel,
    P2VAR(Lin_FramePidType,AUTOMATIC,LINIF_APPL_DATA) PidBuffer,
	VAR(uint8,AUTOMATIC) PidBufferLength
)
{
	VAR(uint16,AUTOMATIC) u16Loop1 = 0U;
	VAR(uint16,AUTOMATIC) u16Loop2 = 0U;
	VAR(uint16,AUTOMATIC) u16FrameNum = 0U;
	VAR(uint8,AUTOMATIC) u8BufferLength = 0U;
	P2CONST(LinIf_FrameCfgType,AUTOMATIC,LINIF_APPL_CONST) pLinIfFrame = NULL_PTR;

	u8BufferLength = LinIf_ConfigPtr->LinIfSlaveChannel[Channel].LinIfMaxFramesNum - 2U;
	u16FrameNum = LinIf_ConfigPtr->LinIfSlaveChannel[Channel].LinIfMaxFramesNum;

	for(u16Loop1 = 0U;u16Loop1< u8BufferLength; u16Loop1++)
	{
		for(u16Loop2 = 0U; u16Loop2< u16FrameNum;  u16Loop2++)
		{
			pLinIfFrame = &(LinIf_ConfigPtr->LinIfSlaveChannel[Channel].LinIfFrames[u16Loop2]);
			/**
			 * @req [SWS_LinIf_00824] The provided PID list shall not include the PIDs for MRF and SRF.
			 */
			if((pLinIfFrame->LinIfFrameType == LINIF_UNCONDITIONAL) ||  \
					(pLinIfFrame->LinIfFrameType == LINIF_EVENT_TRIGGERED))
			{
				/**
				 * @req [SWS_LinIf_00823] This API shall update the internal
				 *      configured PID list in LIN Interface with the given PID list.
				 */
				if(pLinIfFrame->LinIfFrameIndex == u16Loop1)
				{
					LinIf_SlavePIDTable[pLinIfFrame->LinIfFrameTableIndex] = (*(PidBuffer + u16Loop1)) ;
				}
			}
		}
	}
}

#if(LINIF_DEV_ERROR_DETECT == STD_ON)
/**
 * @brief       LinIf_SetConfiguredNADParCheck - Checks whether the parameter is valid
 *
 * @param[in]   u8Parameter             parameter for checking
 * @param[in]   u8LinIfServiceId        Service id of the API
 *
 * @return      Result of examination
 */
STATIC FUNC(Std_ReturnType,LINIF_CODE)LinIf_SetConfiguredNADParCheck
(
    VAR(uint8,AUTOMATIC) u8Parameter ,
    VAR(uint8,AUTOMATIC) u8LinIfServiceId
)
{
	VAR(Std_ReturnType,AUTOMATIC) retStatus = (Std_ReturnType)E_OK;
	if(u8Parameter == 0U)
	{
	  retStatus = (Std_ReturnType)E_NOT_OK;
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
	  LinIf_ReportDetError(u8LinIfServiceId,LINIF_E_PARAMETER);
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */
	}
	return retStatus;
}
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */

/**
 * @brief   LinIf_PreparePduInfo - Transmission preparation.
 */
STATIC FUNC(void,LINIF_CODE) LinIf_SlavePreparePduInfo
(
	P2VAR(Lin_PduType, AUTOMATIC,LINIF_APPL_DATA) PduPtr,
	P2CONST(LinIf_FrameCfgType,AUTOMATIC,LINIF_APPL_CONST) pLinIfFrame
)
{
  /*checksum type */
  if(LINIF_ENHANCED == pLinIfFrame->LinIfChecksumType )
  {
	  PduPtr->Cs = LIN_ENHANCED_CS ;
  }
  else
  {
	  PduPtr->Cs = LIN_CLASSIC_CS ;
  }

  /* transmission direction */
  if(LINIF_TX_PDU == pLinIfFrame->LinIfPduDirection)
  {
	  PduPtr->Drc = LIN_FRAMERESPONSE_TX ;
  }
  else
  {
	  PduPtr->Drc = LIN_FRAMERESPONSE_RX ;
  }

  /* data  length */
  PduPtr->Dl = pLinIfFrame->LinIfFrameLength;
}

/**
 * @brief       LinIf_SlaveHandleUnconditionalHeader - Slave processing unconditional frame header.
 *
 * @param[in]   Channel   LinIf Channel Index.
 * @param[in]   PduPtr    Pointer to PDU providing the received PID and pointer to the
 *                             SDU data buffer as in parameter.
 *              pLinIfFrame Pointing to the configuration of the data frame to be processed.
 *
 * @return      Result of examination
 */
STATIC FUNC(Std_ReturnType,LINIF_CODE)LinIf_SlaveHandleUnconditionalHeader
(
	VAR(uint16,AUTOMATIC) Channel,
	P2VAR(Lin_PduType, AUTOMATIC,LINIF_APPL_DATA) PduPtr,
	P2CONST(LinIf_FrameCfgType,AUTOMATIC,LINIF_APPL_CONST) pLinIfFrame
)
{

	VAR(PduIdType,AUTOMATIC)  upPduId ;
	VAR(Std_ReturnType,AUTOMATIC) ret  = (Std_ReturnType)E_NOT_OK ;
	P2VAR(PduInfoType,AUTOMATIC,LINIF_APPL_DATA) pduInfo = NULL_PTR ;
	P2VAR(LinIf_SlaveChannelRunningType,AUTOMATIC,LINIF_APPL_DATA) pChRunStatus = NULL_PTR;

	pChRunStatus = &(LinIf_SlaveChannelCfg[Channel]);

	switch(pLinIfFrame->LinIfPduDirection)
	{
		case LINIF_RX_PDU:
			/**
			 * @req [SWS_LinIf_00733] If the PID of a received header is evaluated and
			 *      belongs to a configured receive frame, before returning from the callback
			 *      LinIf_HeaderIndication the LIN Interface shall set the PduPtr->Cs and
			 *      PduPtr->Dl to the configured values and shall set the PduPtr->Drc to
			 *      LIN_FRAMERESPONSE_RX.
			 */
			LinIf_SlavePreparePduInfo(PduPtr,pLinIfFrame);
			ret = (Std_ReturnType)E_OK;
			break;
		case LINIF_TX_PDU :
			/**
			 * @req [SWS_LinIf_00738] If LinIf_HeaderIndication is called and the PID is
			 *      evaluated and determined as a transmit frame, the LIN Interface shall
			 *      call the function <User_TriggerTransmit> with the PduInfoPtr->SduDataPtr
			 *      set to the buffer provided as PduPtr->SduPtr and PduInfoPtr->SduLength
			 *      set to the configured length to get the data part of the frame
			 *      (data in the LIN frame response).
			 */
			pduInfo = &(pChRunStatus->txPduInfo);
			pduInfo->SduDataPtr = PduPtr->SduPtr;
			pduInfo->SduLength = pLinIfFrame->LinIfFrameLength;
			upPduId = pLinIfFrame->LinIfTxPdu->LinIfTxPduRef;

			ret = pLinIfFrame->LinIfTxPdu->LinIfTxTriggerTransmitUL(upPduId,pduInfo);

			if((Std_ReturnType)E_OK == ret)
			{
				/**
				 * @req [SWS_LinIf_00739] After getting the data part of the frame
				 *      (when the function <User_TriggerTransmit> returns E_OK or
				 *      the SRF data is provided by node configuration handler or
				 *      transport protocol), before returning from the callback
				 *      LinIf_HeaderIndication, the LIN Interface shall set the PduPtr->Cs
				 *      and PduPtr->Dl to the configured values and shall set the PduPtr->Drc
				 *      to LIN_FRAMERESPONSE_TX.
				 */
				LinIf_SlavePreparePduInfo(PduPtr,pLinIfFrame);
				PduPtr->Dl = pduInfo->SduLength;
				ret = (Std_ReturnType)E_OK;
			}
			else
			{
				/**
				 * @req [SWS_LinIf_00740] When the function <User_TriggerTransmit> returns
				 * 		E_NOT_OK,the LIN Interface shall set the PduPtr->Drc to LIN_FRAMERESPONSE_IGNORE
				 * 		before returning from the callback LinIf_HeaderIndication.
				 */
				PduPtr->Drc = LIN_FRAMERESPONSE_IGNORE;
			}
			break;
		default:
			/**
			 * @req [SWS_LinIf_00740] When the function <User_TriggerTransmit> returns
			 * 		E_NOT_OK,the LIN Interface shall set the PduPtr->Drc to LIN_FRAMERESPONSE_IGNORE
			 * 		before returning from the callback LinIf_HeaderIndication.
			 */
			PduPtr->Drc = LIN_FRAMERESPONSE_IGNORE;
			break;
	}

	if(ret == (Std_ReturnType)E_OK)
	{
		pChRunStatus->u8LinIfChTransStatus =  LINIF_CH_TRANS_RESPONSE;
		pChRunStatus->curLinIfFrames = pLinIfFrame;
	}

	return ret;
}

/**
 * @brief       LinIf_SlaveHandleMrfHeader - Slave processing MRF frame header.
 *
 * @param[in]   Channel   LinIf Channel Index.
 * @param[in]   PduPtr    Pointer to PDU providing the received PID and pointer to the
 *                             SDU data buffer as in parameter.
 *              pLinIfFrame Pointing to the configuration of the data frame to be processed.
 *
 * @return      Result of examination
 */
STATIC FUNC(Std_ReturnType,LINIF_CODE)LinIf_SlaveHandleMrfHeader
(
	VAR(uint16,AUTOMATIC) Channel,
	P2VAR(Lin_PduType, AUTOMATIC,LINIF_APPL_DATA) PduPtr,
	P2CONST(LinIf_FrameCfgType,AUTOMATIC,LINIF_APPL_CONST) pLinIfFrame
)
{
	VAR(Std_ReturnType,AUTOMATIC) ret  = (Std_ReturnType)E_OK ;
	P2VAR(LinIf_SlaveChannelRunningType,AUTOMATIC,LINIF_APPL_DATA) pChRunStatus = NULL_PTR;

	pChRunStatus = &(LinIf_SlaveChannelCfg[Channel]);

	/**
	 * @req [SWS_LinIf_00733] If the PID of a received header is evaluated and
	 *      belongs to a configured receive frame, before returning from the callback
	 *      LinIf_HeaderIndication the LIN Interface shall set the PduPtr->Cs and
	 *      PduPtr->Dl to the configured values and shall set the PduPtr->Drc to
	 *      LIN_FRAMERESPONSE_RX.
	 */
	LinIf_SlavePreparePduInfo(PduPtr,pLinIfFrame);
	pChRunStatus->u8LinIfChTransStatus =  LINIF_CH_TRANS_RESPONSE;
	pChRunStatus->curLinIfFrames = pLinIfFrame;

	return ret;
}

/**
 * @brief       LinIf_SlaveHandleSrfHeader - Slave processing SRF frame header.
 *
 * @param[in]   Channel   LinIf Channel Index.
 * @param[in]   PduPtr    Pointer to PDU providing the received PID and pointer to the
 *                             SDU data buffer as in parameter.
 *              pLinIfFrame Pointing to the configuration of the data frame to be processed.
 *
 * @return      Result of examination
 */
STATIC FUNC(Std_ReturnType,LINIF_CODE)LinIf_SlaveHandleSrfHeader
(
	VAR(uint16,AUTOMATIC) Channel,
	P2VAR(Lin_PduType, AUTOMATIC,LINIF_APPL_DATA) PduPtr,
	P2CONST(LinIf_FrameCfgType,AUTOMATIC,LINIF_APPL_CONST) pLinIfFrame
)
{
	VAR(uint8,AUTOMATIC) u8Loop;
	VAR(Std_ReturnType,AUTOMATIC) ret  = (Std_ReturnType)E_OK ;
	P2VAR(LinIf_SlaveChannelRunningType,AUTOMATIC,LINIF_APPL_DATA) pChRunStatus = NULL_PTR;

	pChRunStatus = &(LinIf_SlaveChannelCfg[Channel]);

	/**
	 * @req [SWS_LinIf_00775]If the header of a SRF is received and the response of
	 *      a node configuration command is pending for transmission, the response of
	 *      the SRF shall be transmitted by the node configuration handler.
	 */
	if(pChRunStatus->bNcResponseFlag == (boolean)TRUE)
	{
#if (LINIF_TP_SUPPORTED == STD_ON)
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
		/**
		 * @req [SWS_LinIf_00845] If development error detection is enabled, the PID is
		 *      evaluated and rated to belong to a transmit frame and the parameter
		 *      PduPtr->SduPtr has an invalid value, the function LinIf_HeaderIndication
		 *      shall raise the development error code LINIF_E_PARAM_POINTER.
		 */
		ret = LinTp_CheckSduPtrPoint(PduPtr->SduPtr,LINIF_SID_HEADERINDICATION);
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */
#endif /* LINIF_TP_SUPPORTED == STD_ON */
		/**
		 * node configuration handler
		 */
		if(ret == ((Std_ReturnType)E_OK))
		{
			if(pChRunStatus->u8LinIfChTransStatus == LINIF_CH_TRANS_RESPONSE)
			{
				/**
				 * @req [SWS_LinIf_00846]If LinIf_HeaderIndication is called while the
				 *      indication of a response reception or the confirmation of a response
				 *      transmission is expected, the LIN Interface shall consider the received
				 *      frame as lost. Therefore, the LIN Interface shall report the runtime
				 *      error code LINIF_E_RESPONSE to the Default Error Tracer.
				 *      Afterwards, the received LIN Header shall be processed.
				 */
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
				LinIf_ReportDetError(LINIF_SID_HEADERINDICATION , LINIF_E_RESPONSE);
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */
				LinIf_ResetSlaveChannel(Channel);
			}

			/**
			 * @req [SWS_LinIf_00733] If the PID of a received header is evaluated and
			 *      belongs to a configured receive frame, before returning from the callback
			 *      LinIf_HeaderIndication the LIN Interface shall set the PduPtr->Cs and
			 *      PduPtr->Dl to the configured values and shall set the PduPtr->Drc to
			 *      LIN_FRAMERESPONSE_RX.
			 */
			LinIf_SlavePreparePduInfo(PduPtr,pLinIfFrame);
			pChRunStatus->u8LinIfChTransStatus =  LINIF_CH_TRANS_RESPONSE;
			pChRunStatus->curLinIfFrames = pLinIfFrame;
			for(u8Loop = 0U; u8Loop<8U; u8Loop++)
			{
				PduPtr->SduPtr[u8Loop] = LinIf_SlaveNodeCfgResData[Channel][u8Loop];
			}
		}
	}
	else
	{
#if (LINIF_TP_SUPPORTED == STD_ON)
		/**
		 * @req [SWS_LinIf_00733] If the PID of a received header is evaluated and
		 *      belongs to a configured receive frame, before returning from the callback
		 *      LinIf_HeaderIndication the LIN Interface shall set the PduPtr->Cs and
		 *      PduPtr->Dl to the configured values and shall set the PduPtr->Drc to
		 *      LIN_FRAMERESPONSE_RX.
		 */
		LinIf_SlavePreparePduInfo(PduPtr,pLinIfFrame);
		pChRunStatus->u8LinIfChTransStatus =  LINIF_CH_TRANS_RESPONSE;
		pChRunStatus->curLinIfFrames = pLinIfFrame;
		LinIf_SlaveTransportLayerSrfIndication(Channel,PduPtr);
#else
		LinIf_ResetSlaveChannel(Channel);
		PduPtr->Drc = LIN_FRAMERESPONSE_IGNORE ;
#endif /* LINIF_TP_SUPPORTED == STD_ON */
	}

	return ret;
}

/**
 * @brief            The LIN Driver will call this function to report a received LIN header.
 *                   This function is only applicable for LIN slave nodes (available only if
 *                   the ECU has any LIN slave channel).
 * @param[in]        Channel   LinIf Channel Index.
 *                   PduPtr    Pointer to PDU providing the received PID and pointer to the
 *                             SDU data buffer as in parameter.
 *
 * @return           Std_ReturnType
 * @retval E_NOT_OK  Request has not been accepted, development or production error occurred.
 * @retval E_OK      Request has been accepted.
 */
STATIC FUNC(Std_ReturnType,LINIF_CODE)LinIf_Call_HeaderIndication
(
    VAR(uint16,AUTOMATIC) Channel,
	P2VAR(Lin_PduType, AUTOMATIC,LINIF_APPL_DATA) PduPtr
)
{
	VAR(uint8,AUTOMATIC) u16Pid = 0U;
	VAR(uint16,AUTOMATIC) u16Loop = 0U;
	VAR(Std_ReturnType,AUTOMATIC) retStatus  = (Std_ReturnType)E_NOT_OK ;
	P2CONST(LinIf_FrameCfgType,AUTOMATIC,LINIF_APPL_CONST) pLinIfFrame = NULL_PTR;
	P2VAR(LinIf_SlaveChannelRunningType,AUTOMATIC,LINIF_APPL_DATA) pChRunStatus = NULL_PTR;
	P2CONST(LinIf_ChannelConfigCfgType,AUTOMATIC,LINIF_APPL_CONST) pLinIfChannel = NULL_PTR;

	pChRunStatus = &(LinIf_SlaveChannelCfg[Channel]);

	pLinIfChannel = &(LinIf_ConfigPtr->LinIfSlaveChannel[Channel]);
	
	if(pChRunStatus->bWakeReqFlag == (boolean)TRUE)
	{
		if(pLinIfChannel->LinIfWakeupConfirmation != NULL_PTR)
		{
			pLinIfChannel->LinIfWakeupConfirmation(pLinIfChannel->LinIfComMNetworkHandleIdRef,TRUE);
		}			
		pChRunStatus->bWakeReqFlag = (boolean)FALSE;
	}
		
	if(pChRunStatus->u8LinIfChannleSubStatus == LINIF_CHANNEL_OPERATIONAL)
	{
		for(u16Loop = 0U ; u16Loop< pLinIfChannel->LinIfMaxFramesNum ; u16Loop++)
		{
			u16Pid =  LinIf_SlavePIDTable[pLinIfChannel->LinIfFrames[u16Loop].LinIfFrameTableIndex];
			if(u16Pid == (PduPtr->Pid))
			{
				pLinIfFrame = &(pLinIfChannel->LinIfFrames[u16Loop]);
				//GYF
				//if(((u16Pid == 0xB4U) || (u16Pid == 0xF5U)) && (bInforSwitch != TRUE)) 
				if(((u16Pid == 0xB4U) || (u16Pid == 0xF5U))) 
				{
					pLinIfFrame = NULL_PTR;
				}
				break;
			}
		}
		
		if(pLinIfFrame != NULL_PTR)
		{
			switch(pLinIfFrame->LinIfFrameType)
			{
				case  LINIF_UNCONDITIONAL  :
					retStatus = LinIf_SlaveHandleUnconditionalHeader(Channel,PduPtr,pLinIfFrame);
					break;
				case LINIF_MRF:
					retStatus = LinIf_SlaveHandleMrfHeader(Channel,PduPtr,pLinIfFrame);
					break;
				case LINIF_SRF:
					retStatus = LinIf_SlaveHandleSrfHeader(Channel,PduPtr,pLinIfFrame);
					break;
				default :
					PduPtr->Drc =  LIN_FRAMERESPONSE_IGNORE;
					retStatus = (Std_ReturnType)E_OK;
					break;
			}

		}
		else
		{
			/**
			 * @req [SWS_LinIf_00748]  If LinIf_HeaderIndication is called and the PID is
			 *      evaluated and determined as a frame that is not relevant for the slave,
			 *      before returning from the callback LinIf_HeaderIndication, the LIN Interface
			 *      shall set the PduPtr->Drc to LIN_FRAMERESPONSE_IGNORE
			 */
			PduPtr->Drc =  LIN_FRAMERESPONSE_IGNORE;
			retStatus = (Std_ReturnType)E_OK;
		}

		/**
		 * @req [SWS_LinIf_00754] The LIN Interface shall reload the running bus idle
		 *      timer each time when LinIf_HeaderIndication, LinIf_RxIndication, LinIf_TxConfirmation
		 *       or LinIf_LinErrorIndication with any error code is called.
		 */
		pChRunStatus->u16BusIdleTimer = pLinIfChannel->LinIfBusIdleTimeoutPeriod;
	}

	return retStatus;
}

/**
 * @details          The LIN Driver will call this function to report a successfully received response
 *                   and provides the reception data to the LIN Interface. This function is only
 *                   applicable for LIN slave nodes (available only if the ECU has any LIN slave channel).
 * @param[in]        Channel   LinIf Channel Index.
 *
 *                   Lin_SduPtr  Pointer to pointer to a shadow buffer or memory mapped LIN
 *                               Hardware receive buffer where the current SDU is stored.
 *                               This pointer is only valid if the response is received.
 *
 * @return           void
 *
 */
STATIC FUNC(void,LINIF_CODE)LinIf_SlaveHandleRxUnconitionalData
(
    VAR(uint16,AUTOMATIC) Channel,
	P2VAR(uint8, AUTOMATIC,LINIF_APPL_DATA) Lin_SduPtr
)
{
	VAR(PduInfoType,AUTOMATIC) pduInfo ;
	VAR(PduIdType,AUTOMATIC)  upPduId ;
	P2CONST(LinIf_FrameCfgType,AUTOMATIC,LINIF_APPL_CONST) pLinIfFrame = NULL_PTR;
	P2VAR(LinIf_SlaveChannelRunningType,AUTOMATIC,LINIF_APPL_DATA) pChRunStatus = NULL_PTR;
#if(LINIF_BUS_MIRRORING_SUPPORTED == STD_ON)
	VAR(NetworkHandleType,AUTOMATIC) netWork;
	VAR(Lin_FramePidType,AUTOMATIC)  pid;
#endif /* LINIF_BUS_MIRRORING_SUPPORTED == STD_ON */

	pChRunStatus = &(LinIf_SlaveChannelCfg[Channel]);
	pLinIfFrame = pChRunStatus->curLinIfFrames;

	/**
	 * @req [SWS_LinIf_00734] If the function LinIf_RxIndication is called,
	 *      the LIN Interface shall invoke <User_RxIndication> with the received
	 *      data and payload length.
	 */
	pduInfo.SduDataPtr = Lin_SduPtr;
	pduInfo.SduLength = pLinIfFrame->LinIfFrameLength;

	upPduId = pLinIfFrame->LinIfRxPdu->LinIfRxPduRef;
	
	if((pLinIfFrame->LinIfFrameId == 0x01U) || \
		(pLinIfFrame->LinIfFrameId == 0x02U) || \
		(pLinIfFrame->LinIfFrameId == 0x03U))
	{
		//RLS_CalDateHandle(pLinIfFrame->LinIfFrameId, Lin_SduPtr);
	}
	else
	{
		pLinIfFrame->LinIfRxPdu->LinIfRxIndication(upPduId,&pduInfo);
	}

#if(LINIF_BUS_MIRRORING_SUPPORTED == STD_ON)
	/* Bus Mirroring */
	if(LinIf_SlaveChannelBusMirrorFlag[Channel] != (boolean)FALSE)
	{
		/**
		 * @req [SWS_LinIf_00838] If Bus Mirroring is enabled globally
		 *      (configuration parameter LinIfBusMirroringSupported) and has
		 *      been activated with a call to LinIf_EnableBusMirroring() for a
		 *      LIN channel, the LIN Interface shall call Mirror_ReportLinFrame()
		 *      each time LinIf_RxIndication is called on that channel, with
		 *      status code LIN_RX_OK and a pointer to the received data.
		 */
		netWork = LinIf_ConfigPtr->LinIfChannel[Channel].LinIfComMNetworkHandleIdRef;
		pid = LinIf_SlavePIDTable[pLinIfFrame->LinIfFrameTableIndex] ;
		Mirror_ReportLinFrame(netWork,pid,&pduInfo,LIN_RX_OK);
	}
#endif /* LINIF_BUS_MIRRORING_SUPPORTED == STD_ON */

	pChRunStatus->curLinIfFrames = NULL_PTR;
	pChRunStatus->u8LinIfChTransStatus = LINIF_CH_TRANS_SILENT;
}

#if (LINIF_NC_OPTIONAL_REQUEST_SUPPORTED == STD_ON)
/**
 * @details          Slave Node Configuration Handler
 * @param[in]        Channel   LinIf Channel Index.
 *
 *                   Lin_SduPtr  Pointer to pointer to a shadow buffer or memory mapped LIN
 *                               Hardware receive buffer where the current SDU is stored.
 *                               This pointer is only valid if the response is received.
 *
 * @return           void
 *
 */
STATIC FUNC(void,LINIF_CODE)LinIf_SlaveNodeAssignNadHandle
(
	VAR(uint16,AUTOMATIC) Channel,
	P2VAR(uint8, AUTOMATIC,LINIF_APPL_DATA) Lin_SduPtr
)
{
	VAR(uint8,AUTOMATIC) u8Nad;
	VAR(uint8,AUTOMATIC) u8Loop;
	VAR(uint16,AUTOMATIC) u16SupId;
	VAR(uint16,AUTOMATIC) u16FunId;
	P2CONST(LinIf_ChannelConfigCfgType,AUTOMATIC,LINIF_APPL_CONST) pLinIfChannel = NULL_PTR;
	P2VAR(LinIf_SlaveChannelRunningType,AUTOMATIC,LINIF_APPL_DATA) pChRunStatus = NULL_PTR;

	pLinIfChannel = &(LinIf_ConfigPtr->LinIfSlaveChannel[Channel]);
	pChRunStatus = &(LinIf_SlaveChannelCfg[Channel]);
	u8Nad = Lin_SduPtr[LINIF_PDU_NAD_OFFSET];
	u16SupId = (uint16)((Lin_SduPtr[LINIF_PDU_NODE_CFG_DATA2_OFFSET]<< 8U) | \
			(Lin_SduPtr[LINIF_PDU_NODE_CFG_DATA1_OFFSET]));
	u16FunId = (uint16)((Lin_SduPtr[LINIF_PDU_NODE_CFG_DATA4_OFFSET]<< 8U) | \
			(Lin_SduPtr[LINIF_PDU_NODE_CFG_DATA3_OFFSET]));

	if(((pLinIfChannel->LinIfSlaveNode->LinIfInitialNAD == u8Nad) || (LINIF_BROADCAST_NAD == u8Nad)) && \
			((pLinIfChannel->LinIfSlaveNode->LinIfSupplierId == u16SupId) && \
			(pLinIfChannel->LinIfSlaveNode->LinIfFunctionId == u16FunId))
	 )
	{
		LinIf_SlaveConfiguredNAD[Channel] = \
				Lin_SduPtr[LINIF_PDU_NODE_CFG_DATA5_OFFSET];
		/**
		 * Prepare node positive response data.
		 */
		for(u8Loop = 0U;u8Loop<8U;u8Loop++)
		{
			LinIf_SlaveNodeCfgResData[Channel][u8Loop] = 0xFFU;
		}

		LinIf_SlaveNodeCfgResData[Channel][LINIF_PDU_NAD_OFFSET] = \
				Lin_SduPtr[LINIF_PDU_NAD_OFFSET];
		LinIf_SlaveNodeCfgResData[Channel][LINIF_PDU_PCI_OFFSET] = 0x01U;

		LinIf_SlaveNodeCfgResData[Channel][LINIF_PDU_SF_RSID_OFFSET] = 0xF0U;

		LinIf_ResetSlaveChannel(Channel);

		/* Node configuration request response flag set.*/
		pChRunStatus->bNcResponseFlag = (boolean)TRUE;

		/**
		 * @req [SWS_LinIf_00784] The LIN Interface shall provide the N_As timeout
		 *      observation (configuration parameter LinIfNasTimeout) for node configuration
		 *      in order to abort a pending response if no SRF header is received.
		 * @req [SWS_LinIf_00785] The LIN Interface shall start the N_As timer after reception
		 *      of a valid node configuration request and stop the timer if a pending node
		 *      configuration response has been transmitted successfully.
		 */
		pChRunStatus->bNasTimerSwitch = (boolean)TRUE;
		pChRunStatus->u16NasTimer = pLinIfChannel->LinIfSlaveNode->LinIfNasTimeout;
	}
	else
	{
		LinIf_ResetSlaveChannel(Channel);
		/**
		 * @req [SWS_LinIf_00787] If a MRF with an unknown NAD is received,
		 *      the LIN interface shall reject the request and abort a pending
		 *      node configuration response.
		 */
		if(pChRunStatus->bNcResponseFlag == (boolean)TRUE)
		{
			for(u8Loop = 0U;u8Loop<8U;u8Loop++)
			{
				LinIf_SlaveNodeCfgResData[Channel][u8Loop] = 0xFFU;
			}

			pChRunStatus->bNcResponseFlag = (boolean)FALSE;
		}
	}
}
#endif /* LINIF_NC_OPTIONAL_REQUEST_SUPPORTED == STD_ON*/

/**
 * @details          Slave Node Read By Identifier Handler
 * @param[in]        Channel   LinIf Channel Index.
 *
 *                   Lin_SduPtr  Pointer to pointer to a shadow buffer or memory mapped LIN
 *                               Hardware receive buffer where the current SDU is stored.
 *                               This pointer is only valid if the response is received.
 *
 * @return           void
 *
 */
STATIC FUNC(void,LINIF_CODE)LinIf_SlaveNodeReadByIdentiHandle
(
	VAR(uint16,AUTOMATIC) Channel,
	P2VAR(uint8, AUTOMATIC,LINIF_APPL_DATA) Lin_SduPtr
)
{
	VAR(uint8,AUTOMATIC) u8Nad;
	VAR(uint8,AUTOMATIC) u8Loop;
	VAR(uint8,AUTOMATIC) u8Ident;
	VAR(uint16,AUTOMATIC) u16SupId;
	VAR(uint16,AUTOMATIC) u16FunId;
	P2CONST(LinIf_ChannelConfigCfgType,AUTOMATIC,LINIF_APPL_CONST) pLinIfChannel = NULL_PTR;
	P2VAR(LinIf_SlaveChannelRunningType,AUTOMATIC,LINIF_APPL_DATA) pChRunStatus = NULL_PTR;

	pLinIfChannel = &(LinIf_ConfigPtr->LinIfSlaveChannel[Channel]);
	pChRunStatus = &(LinIf_SlaveChannelCfg[Channel]);

	u8Nad = Lin_SduPtr[LINIF_PDU_NAD_OFFSET];
	u16SupId = (uint16)((Lin_SduPtr[LINIF_PDU_NODE_CFG_DATA3_OFFSET]<< 8U) | \
			(Lin_SduPtr[LINIF_PDU_NODE_CFG_DATA2_OFFSET]));
	u16FunId = (uint16)((Lin_SduPtr[LINIF_PDU_NODE_CFG_DATA5_OFFSET]<< 8U) | \
			(Lin_SduPtr[LINIF_PDU_NODE_CFG_DATA4_OFFSET]));

	if(((LinIf_SlaveConfiguredNAD[Channel] == u8Nad) || (LINIF_BROADCAST_NAD == u8Nad)) && \
			((pLinIfChannel->LinIfSlaveNode->LinIfSupplierId == u16SupId) && \
			(pLinIfChannel->LinIfSlaveNode->LinIfFunctionId == u16FunId))
	 )
	{
		u8Ident = Lin_SduPtr[LINIF_PDU_SF_DATA_OFFSET];
		/**
		 * Prepare node positive response data.
		 */
		for(u8Loop = 0U;u8Loop<8U;u8Loop++)
		{
			LinIf_SlaveNodeCfgResData[Channel][u8Loop] = 0xFFU;
		}
		LinIf_SlaveNodeCfgResData[Channel][LINIF_PDU_NAD_OFFSET] = \
						Lin_SduPtr[LINIF_PDU_NAD_OFFSET];

		if(u8Ident == 0U)
		{
			LinIf_SlaveNodeCfgResData[Channel][LINIF_PDU_PCI_OFFSET] = 0x06U;
			LinIf_SlaveNodeCfgResData[Channel][LINIF_PDU_SF_RSID_OFFSET] = 0xF6U;
			LinIf_SlaveNodeCfgResData[Channel][LINIF_PDU_NODE_CFG_DATA1_OFFSET] = \
					(uint8)(pLinIfChannel->LinIfSlaveNode->LinIfSupplierId & 0xFFU);
			LinIf_SlaveNodeCfgResData[Channel][LINIF_PDU_NODE_CFG_DATA2_OFFSET] = \
					(uint8)((pLinIfChannel->LinIfSlaveNode->LinIfSupplierId >> 8U) & 0xFFU);
			LinIf_SlaveNodeCfgResData[Channel][LINIF_PDU_NODE_CFG_DATA3_OFFSET] = \
					(uint8)(pLinIfChannel->LinIfSlaveNode->LinIfFunctionId & 0xFFU);
			LinIf_SlaveNodeCfgResData[Channel][LINIF_PDU_NODE_CFG_DATA4_OFFSET] = \
					(uint8)((pLinIfChannel->LinIfSlaveNode->LinIfFunctionId >> 8U) & 0xFFU);
			LinIf_SlaveNodeCfgResData[Channel][LINIF_PDU_NODE_CFG_DATA5_OFFSET] = \
					pLinIfChannel->LinIfSlaveNode->LinIfVariantId;
		}
		else if(u8Ident == 2U)
		{
			LinIf_SlaveNodeCfgResData[Channel][LINIF_PDU_PCI_OFFSET] = 0x03U;
			LinIf_SlaveNodeCfgResData[Channel][LINIF_PDU_SF_RSID_OFFSET] = 0x7FU;
			LinIf_SlaveNodeCfgResData[Channel][LINIF_PDU_NODE_CFG_DATA1_OFFSET] = 0xB2U;
			LinIf_SlaveNodeCfgResData[Channel][LINIF_PDU_NODE_CFG_DATA2_OFFSET] = 0x12U;
		}
		else
		{
			/* do nothing..*/;
		}

		LinIf_ResetSlaveChannel(Channel);

		/* Node configuration request response flag set.*/
		pChRunStatus->bNcResponseFlag = (boolean)TRUE;

		/**
		 * @req [SWS_LinIf_00784] The LIN Interface shall provide the N_As timeout
		 *      observation (configuration parameter LinIfNasTimeout) for node configuration
		 *      in order to abort a pending response if no SRF header is received.
		 * @req [SWS_LinIf_00785] The LIN Interface shall start the N_As timer after reception
		 *      of a valid node configuration request and stop the timer if a pending node
		 *      configuration response has been transmitted successfully.
		 */
		pChRunStatus->bNasTimerSwitch = (boolean)TRUE;
		pChRunStatus->u16NasTimer = pLinIfChannel->LinIfSlaveNode->LinIfNasTimeout;
	}
	else
	{
		LinIf_ResetSlaveChannel(Channel);
		/**
		 * @req [SWS_LinIf_00787] If a MRF with an unknown NAD is received,
		 *      the LIN interface shall reject the request and abort a pending
		 *      node configuration response.
		 */
		if(pChRunStatus->bNcResponseFlag == (boolean)TRUE)
		{
			for(u8Loop = 0U;u8Loop<8U;u8Loop++)
			{
				LinIf_SlaveNodeCfgResData[Channel][u8Loop] = 0xFFU;
			}

			pChRunStatus->bNcResponseFlag = (boolean)FALSE;
		}
	}
}

#if(LINIF_SAVE_CONFIGURATION_CALLOUT == STD_ON)
/**
 * @details          Slave Node Save Configuration Handler
 * @param[in]        Channel   LinIf Channel Index.
 *
 *                   Lin_SduPtr  Pointer to pointer to a shadow buffer or memory mapped LIN
 *                               Hardware receive buffer where the current SDU is stored.
 *                               This pointer is only valid if the response is received.
 *
 * @return           void
 *
 */
STATIC FUNC(void,LINIF_CODE)LinIf_SlaveNodeSaveConfigHandle
(
	VAR(uint16,AUTOMATIC) Channel,
	P2VAR(uint8, AUTOMATIC,LINIF_APPL_DATA) Lin_SduPtr
)
{
	VAR(uint8,AUTOMATIC) u8Nad;
	VAR(uint8,AUTOMATIC) u8Loop;
	P2CONST(LinIf_ChannelConfigCfgType,AUTOMATIC,LINIF_APPL_CONST) pLinIfChannel = NULL_PTR;
	P2VAR(LinIf_SlaveChannelRunningType,AUTOMATIC,LINIF_APPL_DATA) pChRunStatus = NULL_PTR;

	pLinIfChannel = &(LinIf_ConfigPtr->LinIfSlaveChannel[Channel]);
	pChRunStatus = &(LinIf_SlaveChannelCfg[Channel]);

	u8Nad = Lin_SduPtr[LINIF_PDU_NAD_OFFSET];

	if((LinIf_SlaveConfiguredNAD[Channel] == u8Nad) || (LINIF_BROADCAST_NAD == u8Nad))
	{
#ifdef LINIF_SAVE_CONFIGURATION_FUN
		LINIF_SAVE_CONFIGURATION_FUN();
#endif /* LINIF_SAVE_CONFIGURATION_FUN */

		/**
		 * Prepare node positive response data.
		 */
		for(u8Loop = 0U;u8Loop<8U;u8Loop++)
		{
			LinIf_SlaveNodeCfgResData[Channel][u8Loop] = 0xFFU;
		}

		LinIf_SlaveNodeCfgResData[Channel][LINIF_PDU_NAD_OFFSET] = \
				Lin_SduPtr[LINIF_PDU_NAD_OFFSET];
		LinIf_SlaveNodeCfgResData[Channel][LINIF_PDU_PCI_OFFSET] = 0x01U;

		LinIf_SlaveNodeCfgResData[Channel][LINIF_PDU_SF_RSID_OFFSET] = 0xF6U;

		LinIf_ResetSlaveChannel(Channel);

		/* Node configuration request response flag set.*/
		pChRunStatus->bNcResponseFlag = (boolean)TRUE;

		/**
		 * @req [SWS_LinIf_00784] The LIN Interface shall provide the N_As timeout
		 *      observation (configuration parameter LinIfNasTimeout) for node configuration
		 *      in order to abort a pending response if no SRF header is received.
		 * @req [SWS_LinIf_00785] The LIN Interface shall start the N_As timer after reception
		 *      of a valid node configuration request and stop the timer if a pending node
		 *      configuration response has been transmitted successfully.
		 */
		pChRunStatus->bNasTimerSwitch = (boolean)TRUE;
		pChRunStatus->u16NasTimer = pLinIfChannel->LinIfSlaveNode->LinIfNasTimeout;
	}
	else
	{
		LinIf_ResetSlaveChannel(Channel);
		/**
		 * @req [SWS_LinIf_00787] If a MRF with an unknown NAD is received,
		 *      the LIN interface shall reject the request and abort a pending
		 *      node configuration response.
		 */
		if(pChRunStatus->bNcResponseFlag == (boolean)TRUE)
		{
			for(u8Loop = 0U;u8Loop<8U;u8Loop++)
			{
				LinIf_SlaveNodeCfgResData[Channel][u8Loop] = 0xFFU;
			}

			pChRunStatus->bNcResponseFlag = (boolean)FALSE;
		}
	}
}
#endif /* LINIF_SAVE_CONFIGURATION_CALLOUT == STD_ON */

/**
 * @brief            The order is congruent to the LIN Start Index.
 * @details          This API shall update the internal configured PID list in LIN
 *                   Interface with the given PID list.
 * @param[in]        Channel   LinIf Channel Index.
 *
 *                   Lin_SduPtr  Pointer to pointer to a shadow buffer or memory mapped LIN
 *                               Hardware receive buffer where the current SDU is stored.
 *                               This pointer is only valid if the response is received.
 * @return           void
 *
 */
STATIC FUNC(void,LINIF_CODE)LinIf_SlaveSetPidCommand
(
	VAR(uint16,AUTOMATIC) Channel,
	P2VAR(uint8, AUTOMATIC,LINIF_APPL_DATA) Lin_SduPtr
)
{
	VAR(uint8,AUTOMATIC) u8Index = 0U;
	VAR(uint8,AUTOMATIC) u8Loop1 = 0U;
	VAR(uint16,AUTOMATIC) u16Loop2 = 0U;
	VAR(uint16,AUTOMATIC) u16FrameNum = 0U;
	P2CONST(LinIf_FrameCfgType,AUTOMATIC,LINIF_APPL_CONST) pLinIfFrame = NULL_PTR;

	u16FrameNum = LinIf_ConfigPtr->LinIfSlaveChannel[Channel].LinIfMaxFramesNum;

	for(u8Loop1 = 0U;u8Loop1< 4U; u8Loop1++)
	{
		u8Index = Lin_SduPtr[LINIF_PDU_NODE_CFG_DATA1_OFFSET] + u8Loop1;

		for(u16Loop2 = 0U; u16Loop2< u16FrameNum;  u16Loop2++)
		{
			pLinIfFrame = &(LinIf_ConfigPtr->LinIfSlaveChannel[Channel].LinIfFrames[u16Loop2]);
			/**
			 * @req [SWS_LinIf_00824] The provided PID list shall not include the PIDs for MRF and SRF.
			 */
			if((pLinIfFrame->LinIfFrameType == LINIF_UNCONDITIONAL) ||  \
					(pLinIfFrame->LinIfFrameType == LINIF_EVENT_TRIGGERED))
			{
				/**
				 * @req [SWS_LinIf_00823] This API shall update the internal
				 *      configured PID list in LIN Interface with the given PID list.
				 */
				if(pLinIfFrame->LinIfFrameIndex == u8Index)
				{
					LinIf_SlavePIDTable[pLinIfFrame->LinIfFrameTableIndex] = \
							Lin_SduPtr[LINIF_PDU_NODE_CFG_DATA2_OFFSET + u8Loop1] ;
				}
			}
		}
	}
}

/**
 * @details          Slave Node Assign Frame Identifier Handler
 * @param[in]        Channel   LinIf Channel Index.
 *
 *                   Lin_SduPtr  Pointer to pointer to a shadow buffer or memory mapped LIN
 *                               Hardware receive buffer where the current SDU is stored.
 *                               This pointer is only valid if the response is received.
 *
 * @return           void
 *
 */
STATIC FUNC(void,LINIF_CODE)LinIf_SlaveNodeAssignFrameIdentiHandle
(
	VAR(uint16,AUTOMATIC) Channel,
	P2VAR(uint8, AUTOMATIC,LINIF_APPL_DATA) Lin_SduPtr
)
{
	VAR(uint8,AUTOMATIC) u8Nad;
	VAR(uint8,AUTOMATIC) u8Loop;
	P2CONST(LinIf_ChannelConfigCfgType,AUTOMATIC,LINIF_APPL_CONST) pLinIfChannel = NULL_PTR;
	P2VAR(LinIf_SlaveChannelRunningType,AUTOMATIC,LINIF_APPL_DATA) pChRunStatus = NULL_PTR;

	pLinIfChannel = &(LinIf_ConfigPtr->LinIfSlaveChannel[Channel]);
	pChRunStatus = &(LinIf_SlaveChannelCfg[Channel]);

	u8Nad = Lin_SduPtr[LINIF_PDU_NAD_OFFSET];

	if((LinIf_SlaveConfiguredNAD[Channel] == u8Nad) || (LINIF_BROADCAST_NAD == u8Nad))
	{
		LinIf_SlaveSetPidCommand(Channel,Lin_SduPtr);

		/**
		 * Prepare node positive response data.
		 */
		for(u8Loop = 0U;u8Loop<8U;u8Loop++)
		{
			LinIf_SlaveNodeCfgResData[Channel][u8Loop] = 0xFFU;
		}
		LinIf_SlaveNodeCfgResData[Channel][LINIF_PDU_NAD_OFFSET] = \
						Lin_SduPtr[LINIF_PDU_NAD_OFFSET];
		LinIf_SlaveNodeCfgResData[Channel][LINIF_PDU_PCI_OFFSET] = 0x01U;
		LinIf_SlaveNodeCfgResData[Channel][LINIF_PDU_SF_RSID_OFFSET] = 0xF7U;

		LinIf_ResetSlaveChannel(Channel);

		/* Node configuration request response flag set.*/
		pChRunStatus->bNcResponseFlag = (boolean)TRUE;

		/**
		 * @req [SWS_LinIf_00784] The LIN Interface shall provide the N_As timeout
		 *      observation (configuration parameter LinIfNasTimeout) for node configuration
		 *      in order to abort a pending response if no SRF header is received.
		 * @req [SWS_LinIf_00785] The LIN Interface shall start the N_As timer after reception
		 *      of a valid node configuration request and stop the timer if a pending node
		 *      configuration response has been transmitted successfully.
		 */
		pChRunStatus->bNasTimerSwitch = (boolean)TRUE;
		pChRunStatus->u16NasTimer = pLinIfChannel->LinIfSlaveNode->LinIfNasTimeout;
	}
	else
	{
		LinIf_ResetSlaveChannel(Channel);
		/**
		 * @req [SWS_LinIf_00787] If a MRF with an unknown NAD is received,
		 *      the LIN interface shall reject the request and abort a pending
		 *      node configuration response.
		 */
		if(pChRunStatus->bNcResponseFlag == (boolean)TRUE)
		{
			for(u8Loop = 0U;u8Loop<8U;u8Loop++)
			{
				LinIf_SlaveNodeCfgResData[Channel][u8Loop] = 0xFFU;
			}

			pChRunStatus->bNcResponseFlag = (boolean)FALSE;
		}
	}
}

/**
 * @details          The LIN Driver will call this function to report a successfully received response
 *                   and provides the reception data to the LIN Interface. This function is only
 *                   applicable for LIN slave nodes (available only if the ECU has any LIN slave channel).
 * @param[in]        Channel   LinIf Channel Index.
 *
 *                   Lin_SduPtr  Pointer to pointer to a shadow buffer or memory mapped LIN
 *                               Hardware receive buffer where the current SDU is stored.
 *                               This pointer is only valid if the response is received.
 *
 * @return           void
 *
 */

/***
 * Assign NAD |NAD     |PCI |SID |D1        |D2        |D3        |D4        |D5     |
 *            |Init NAD|0x06|0xB0|Sup ID LSB|Sup ID MSB|Fun ID LSB|Fun ID MSB|New NAD|
 *			  |NAD     |PCI |RSID|D1        |D2        |D3        |D4        |D5     |
 *            |Init NAD|0x01|0xF0|0xFF      |0xFF      |0xFF      |0xFF      |0xFF   |
 *
 * Save Config|NAD     |PCI |SID |D1        |D2        |D3        |D4        |D5     |
 *            |NAD     |0x01|0xB6|0xFF      |0xFF      |0xFF      |0xFF      |0xFF   |
 *			  |NAD     |PCI |RSID|D1        |D2        |D3        |D4        |D5     |
 *            |NAD     |0x01|0xF6|0xFF      |0xFF      |0xFF      |0xFF      |0xFF   |
 *
 * Assign frame ID range
 * 			  |NAD     |PCI |SID |D1          |D2         |D3            |D4            |D5            |
 *            |NAD     |0x06|0xB7|start index |PID(index) |PID(index + 1)|PID(index + 2)|PID(index + 3)|
 *			  |NAD     |PCI |RSID|D1          |D2         |D3            |D4            |D5            |
 *            |NAD     |0x01|0xF7|0xFF        |0xFF       |0xFF          |0xFF          |0xFF          |
 *
 * Read By identifier
 *            |NAD     |PCI |SID |D1          |D2         |D3            |D4            |D5            |
 *            |NAD     |0x06|0xB2|identifier  |Sup ID LSB |Sup ID MSB    |Fun ID LSB    |Fun ID MSB    |
 *
 *            identifier: 0
 *            |NAD     |PCI |RSID|D1          |D2         |D3            |D4            |D5            |
 *            |NAD     |0x06|0xF2|Sup ID LSB  |Sup ID MSB |Fun ID LSB    |Fun ID MSB    |Variant       |
 *            identifier: 2
 *			  |NAD     |PCI |RSID|D1                    |D2                |D3          |D4   |D5      |
 *            |NAD     |0x03|0x7F|Requested SID = 0xB2  |Error Code = 0x12 |0xFF        |0xFF |0xFF    |
 *
 */
STATIC FUNC(void,LINIF_CODE)LinIf_SlaveHandleRxMrfData
(
    VAR(uint16,AUTOMATIC) Channel,
	P2VAR(uint8, AUTOMATIC,LINIF_APPL_DATA) Lin_SduPtr
)
{
	VAR(uint8,AUTOMATIC) u8Sid;
	VAR(uint8,AUTOMATIC) u8Loop;
	P2VAR(LinIf_SlaveChannelRunningType,AUTOMATIC,LINIF_APPL_DATA) pChRunStatus = NULL_PTR;

	/* Sleeping NAD */
	if(LINIF_SLEEP_NAD == Lin_SduPtr[LINIF_PDU_NAD_OFFSET])
	{
		/* Perform the sleep transition logic. */
		/**
		 * @req [SWS_LinIf_00750] If the function LinIf_RxIndication is called and
		 *      the received frame is a MRF with the first data byte (NAD) equal to 0,
		 *      a go-to-sleep command has been received and the transition to sleep
		 *      mode shall be executed.
		 */
		LinIf_SlaveSleepProcess(Channel);
	}
	else
	{
		/* Prioritize forwarding data processing to node configuration users. */
		/* First determine whether PCI and SID are reasonable. */
		if(((0x06 == Lin_SduPtr[LINIF_PDU_PCI_OFFSET]) && (\
			(LINIF_ASSIGN_NAD_SID == Lin_SduPtr[LINIF_PDU_SF_SID_OFFSET])||\
			(LINIF_ASSIGN_FRAME_IDENTIFIER_RANGE_SID == Lin_SduPtr[LINIF_PDU_SF_SID_OFFSET])||\
			((LINIF_READ_BY_IDENTIFIER_SID == Lin_SduPtr[LINIF_PDU_SF_SID_OFFSET])&& \
			 ((0x00U == Lin_SduPtr[LINIF_PDU_NODE_CFG_DATA1_OFFSET])|| \
			  (0x02U == Lin_SduPtr[LINIF_PDU_NODE_CFG_DATA1_OFFSET]))))) || \
			((0x01 == Lin_SduPtr[LINIF_PDU_PCI_OFFSET]) && \
			(LINIF_SAVE_CONFIG_SID == Lin_SduPtr[LINIF_PDU_SF_SID_OFFSET]))
		)
		{
			u8Sid = Lin_SduPtr[LINIF_PDU_SF_SID_OFFSET];
			switch(u8Sid)
			{
				case LINIF_ASSIGN_NAD_SID:
#if (LINIF_NC_OPTIONAL_REQUEST_SUPPORTED == STD_ON)
					LinIf_SlaveNodeAssignNadHandle(Channel,Lin_SduPtr);
#endif /* LINIF_NC_OPTIONAL_REQUEST_SUPPORTED == STD_ON */
					break;
				case LINIF_READ_BY_IDENTIFIER_SID:
					LinIf_SlaveNodeReadByIdentiHandle(Channel,Lin_SduPtr);
					break;
				case LINIF_SAVE_CONFIG_SID:
#if(LINIF_SAVE_CONFIGURATION_CALLOUT == STD_ON)
					LinIf_SlaveNodeSaveConfigHandle(Channel,Lin_SduPtr);
#endif /* LINIF_SAVE_CONFIGURATION_CALLOUT == STD_ON */
					break;
				case LINIF_ASSIGN_FRAME_IDENTIFIER_RANGE_SID:
					LinIf_SlaveNodeAssignFrameIdentiHandle(Channel,Lin_SduPtr);
					break;
				default:
					LinIf_ResetSlaveChannel(Channel);
					break;
			}
		}
		else
		{
			LinIf_ResetSlaveChannel(Channel);
			pChRunStatus = &(LinIf_SlaveChannelCfg[Channel]);
			/**
			 * @req [SWS_LinIf_00787] If a MRF with an unknown NAD is received,
			 *      the LIN interface shall reject the request and abort a pending
			 *      node configuration response.
			 */
			if(pChRunStatus->bNcResponseFlag == (boolean)TRUE)
			{
				for(u8Loop = 0U;u8Loop<8U;u8Loop++)
				{
					LinIf_SlaveNodeCfgResData[Channel][u8Loop] = 0xFFU;
				}

				pChRunStatus->bNcResponseFlag = (boolean)FALSE;
			}
#if (LINIF_TP_SUPPORTED == STD_ON)
				LinIf_SlaveTransportLayerMrfIndication(Channel,Lin_SduPtr);
#endif /* LINIF_TP_SUPPORTED == STD_ON */
		}
	}
}

/**
 * @details          The LIN Driver will call this function to report a successfully received response
 *                   and provides the reception data to the LIN Interface. This function is only
 *                   applicable for LIN slave nodes (available only if the ECU has any LIN slave channel).
 * @param[in]        Channel   LinIf Channel Index.
 *
 *                   Lin_SduPtr  Pointer to pointer to a shadow buffer or memory mapped LIN
 *                               Hardware receive buffer where the current SDU is stored.
 *                               This pointer is only valid if the response is received.
 *
 * @return           void
 *
 */
STATIC FUNC(void,LINIF_CODE)LinIf_Call_RxIndication
(
    VAR(uint16,AUTOMATIC) Channel,
	P2VAR(uint8, AUTOMATIC,LINIF_APPL_DATA) Lin_SduPtr
)
{
	P2CONST(LinIf_FrameCfgType,AUTOMATIC,LINIF_APPL_CONST) pLinIfFrame = NULL_PTR;
	P2VAR(LinIf_SlaveChannelRunningType,AUTOMATIC,LINIF_APPL_DATA) pChRunStatus = NULL_PTR;
	P2CONST(LinIf_ChannelConfigCfgType,AUTOMATIC,LINIF_APPL_CONST) pLinIfChannel = NULL_PTR;

	pChRunStatus = &(LinIf_SlaveChannelCfg[Channel]);
	pLinIfChannel = &(LinIf_ConfigPtr->LinIfSlaveChannel[Channel]);
	pLinIfFrame = pChRunStatus->curLinIfFrames;

	if(pChRunStatus->u8LinIfChannleSubStatus  ==  LINIF_CHANNEL_OPERATIONAL)
	{
		/**
		 * @req [SWS_LinIf_00848]  If no header of a receive frame has been indicated before
		 *      (no response reception is expected), the function LinIf_RxIndication shall return
		 *      without further action.
		 */
		if(pChRunStatus->u8LinIfChTransStatus == LINIF_CH_TRANS_RESPONSE)
		{
			/**
			 * Ensure the correct usage of the data frame.
			 */
			if(pLinIfFrame->LinIfPduDirection == LINIF_RX_PDU)
			{
				switch(pLinIfFrame->LinIfFrameType)
				{
					case LINIF_UNCONDITIONAL:
						LinIf_SlaveHandleRxUnconitionalData(Channel,Lin_SduPtr);
						break;
					case LINIF_MRF:
						LinIf_SlaveHandleRxMrfData(Channel,Lin_SduPtr);
						break;
					default:
						LinIf_ResetSlaveChannel(Channel);
						break;
				}
			}
		}
		/**
		 * @req [SWS_LinIf_00754] The LIN Interface shall reload the running bus idle
		 *      timer each time when LinIf_HeaderIndication, LinIf_RxIndication, LinIf_TxConfirmation
		 *       or LinIf_LinErrorIndication with any error code is called.
		 */
		pChRunStatus->u16BusIdleTimer = pLinIfChannel->LinIfBusIdleTimeoutPeriod;
	}
}

uint8 Meg_Cnt = 0;
/**
 * @details          Unconditional frame data transmission completed processing.
 * @param[in]        Channel   the LIN channel index.
 *
 * @return           void
 *
 */
STATIC FUNC(void,LINIF_CODE)LinIf_SlaveHandleTxUnconitionalData
(
    VAR(uint16,AUTOMATIC) Channel
)
{
	VAR(PduIdType,AUTOMATIC)  upPduId ;
	P2CONST(LinIf_FrameCfgType,AUTOMATIC,LINIF_APPL_CONST) pLinIfFrame = NULL_PTR;
	P2VAR(LinIf_SlaveChannelRunningType,AUTOMATIC,LINIF_APPL_DATA) pChRunStatus = NULL_PTR;

#if (LINIF_SLAVE_RESPONSE_ERROR_SIGNAL == STD_ON)
	P2CONST(LinIf_SlaveNodeCfgType,AUTOMATIC,LINIF_APPL_CONST) pLinIfSlaveNode = NULL_PTR;
	pLinIfSlaveNode = LinIf_ConfigPtr->LinIfSlaveChannel[Channel].LinIfSlaveNode;
#endif /* LINIF_SLAVE_RESPONSE_ERROR_SIGNAL == STD_ON */

	pChRunStatus = &(LinIf_SlaveChannelCfg[Channel]);
	pLinIfFrame = pChRunStatus->curLinIfFrames;

	Meg_Cnt +=1;
	Meg_Cnt = (Meg_Cnt % 16);
	/**
	 * @req [SWS_LinIf_00741] If the function LinIf_TxConfirmation is called, the LIN
	 *      Interface shall issue a <User_TxConfirmation> callback with result E_OK.
	 */
	upPduId = pLinIfFrame->LinIfTxPdu->LinIfTxPduRef;
//	pLinIfFrame->LinIfTxPdu->LinIfTxConfirmationUL(upPduId,E_OK);
	pLinIfFrame->LinIfTxPdu->LinIfTxConfirmationUL(upPduId);     

#if(LINIF_BUS_MIRRORING_SUPPORTED == STD_ON)
	/* Bus Mirroring */
	if(LinIf_SlaveChannelBusMirrorFlag[Channel] != (boolean)FALSE)
	{
		/**
		 * @req [SWS_LinIf_00839] If Bus Mirroring is enabled globally (configuration parameter
		 *      LinIfBusMirroringSupported) and has been activated with a call to
		 *      LinIf_EnableBusMirroring() for a LIN channel, the LIN Interface shall call
		 *      Mirror_ReportLinFrame() each time LinIf_TxConfirmation is called on that channel,
		 *      with status code LIN_TX_OK and a pointer to the transmitted data
		 */
		netWork = LinIf_ConfigPtr->LinIfChannel[Channel].LinIfComMNetworkHandleIdRef;
		pid = LinIf_SlavePIDTable[pLinIfFrame->LinIfFrameTableIndex] ;
		Mirror_ReportLinFrame(netWork,pid,&(pChRunStatus->txPduInfo),LIN_RX_OK);
	}
#endif /* LINIF_BUS_MIRRORING_SUPPORTED == STD_ON */

#if (LINIF_SLAVE_RESPONSE_ERROR_SIGNAL == STD_ON)
	/**
	 * @req [SWS_LinIf_00747] If the function LinIf_TxConfirmation is called and
	 *      the transmitted frame contains the response_error signal, the LIN Interface shall
	 *      clear the response_error signal.
	 */
	if((pChRunStatus->bErrorSignalValue == (boolean)TRUE) && \
			(pLinIfFrame->LinIfFrameIncludeResponseSignal != (boolean)FALSE))
	{
		pChRunStatus->bErrorSignalValue = (boolean)FALSE;
		(void)Com_SendSignal(pLinIfSlaveNode->LinIfResponseErrorSignal, &(pChRunStatus->bErrorSignalValue));
	}
#endif /* LINIF_SLAVE_RESPONSE_ERROR_SIGNAL == STD_ON */

	/**
	 * @req [SWS_LinIf_00732] The LIN Interface shall clear the pending flag of an event-triggered
	 *      frame response once it has been transmitted successfully. This applies also to the case
	 *      if the response is successfully transmitted as an unconditional frame.
	 */
	if(pChRunStatus->subFramePtr != NULL_PTR)
	{
		if(pChRunStatus->subFramePtr->LinIfSubstitutionFrameRef == pLinIfFrame)
		{
			pChRunStatus->subFramePtr = NULL_PTR;
		}
	}

	pChRunStatus->curLinIfFrames = NULL_PTR;
	pChRunStatus->u8LinIfChTransStatus = LINIF_CH_TRANS_SILENT;

}

/**
 * @details          Srf frame data transmission completed processing.
 * @param[in]        Channel   the LIN channel index.
 *
 * @return           void
 *
 */
STATIC FUNC(void,LINIF_CODE)LinIf_SlaveHandleTxSrfData
(
    VAR(uint16,AUTOMATIC) Channel
)
{
	VAR(uint8,AUTOMATIC) u8Loop;
#if(LINIF_TP_SUPPORTED == STD_ON)
	VAR(PduIdType,AUTOMATIC) pduId;
	VAR(uint16,AUTOMATIC) u16ChIndex;
	VAR(NetworkHandleType,AUTOMATIC) netWork;
	P2CONST(LinTp_ChannelConfigType, AUTOMATIC, LINIF_APPL_CONST) pTpChannel = NULL_PTR;
#endif /* LINIF_TP_SUPPORTED == STD_ON */
	P2VAR(LinIf_SlaveChannelRunningType,AUTOMATIC,LINIF_APPL_DATA) pChRunStatus = NULL_PTR;

	pChRunStatus = &(LinIf_SlaveChannelCfg[Channel]);

	LinIf_ResetSlaveChannel(Channel);
	if(pChRunStatus->bNcResponseFlag == (boolean)TRUE)
	{
		for(u8Loop = 0U;u8Loop<8U;u8Loop++)
		{
			LinIf_SlaveNodeCfgResData[Channel][u8Loop] = 0xFFU;
		}
		pChRunStatus->bNcResponseFlag = (boolean)FALSE;
	}
	else
	{
#if(LINIF_TP_SUPPORTED == STD_ON)
		netWork = LinIf_ConfigPtr->LinIfSlaveChannel[Channel].LinIfComMNetworkHandleIdRef;
		pTpChannel = LinTp_SlaveGetChannel(netWork,&u16ChIndex);
		if(pTpChannel != NULL_PTR)
		{
			pduId = LinTp_SlaveRunCfg[Channel].LinTpTxNSdu->LinTpTxNSduPduRef;
			
			if(LinTp_SlaveRunCfg[u16ChIndex].LinTpTxStatus == LINTP_TX_CONFIRMATION_STATUS)
			{
				/**
				 * @req [SWS_LinIf_00068]When the LIN Interface has transmitted a SF or
				 *      the last CF as MRF (LIN master) or SRF response (LIN slave)
				 *      successfully, it shall notify the upper layer by calling the
				 *      function PduR_LinTpTxConfirmation with the result E_OK.
				 *
				 * @req [SWS_LinIf_00414] The LIN Interface shall set the sub-state of a
				 *      channel to LINTP_CHANNEL_IDLE when it has successfully terminated the
				 *      transmission or reception of a LIN TP message
				 * @req [SWS_LinIf_00688] The LIN Interface shall set the sub-state of a
				 *      channel to LINTP_CHANNEL_IDLE when it has detected an unrecoverable
				 *      error on this channel.
				 */
				LinTp_ResetChannel(&LinTp_SlaveRunCfg[u16ChIndex]);
				Dcm_TpTxConfirmation(pduId, E_OK);
			}
			else
			{
				LinTp_SlaveRunCfg[u16ChIndex].bNasTimerSwitch = (boolean)FALSE;
				LinTp_SlaveRunCfg[u16ChIndex].u16NasTimer = 0U;

				/**
				 * @req [SWS_LinIf_00803]The LIN Interface shall start the N_Cs
				 *      timer after the LIN driver confirms the response transmission
				 *      for a SRF header with invocation of callback function
				 *      LinIf_TxConfirmation and stop after the LIN driver indicates the
				 *      reception of a SRF header with invocation of callback function
				 *      LinIf_HeaderIndication.
				 */
				LinTp_SlaveRunCfg[u16ChIndex].bNcsTimerSwitch = (boolean)TRUE;
				if(LinTp_SlaveRunCfg[u16ChIndex].LinTpTxNSdu->LinTpNcsSwitch == (boolean)TRUE)
				{
					LinTp_SlaveRunCfg[u16ChIndex].u16NcsTimer = \
							LinTp_SlaveRunCfg[u16ChIndex].LinTpTxNSdu->LinTpNcs;
				}
				else
				{
					LinTp_SlaveRunCfg[u16ChIndex].u16NcsTimer = LINTP_TIME_OUT_MS;
				}
			}
		}
#endif /* LINIF_TP_SUPPORTED == STD_ON */
	}
}

/**
 * @details          The LIN Driver will call this function to report a successfully
 *                   transmitted response. This function is only applicable for LIN
 *                    slave nodes (available only if the ECU has any LIN slave channel).
 * @param[in]        Channel   the LIN channel index.
 *
 * @return           void
 *
 */
STATIC FUNC(void,LINIF_CODE)LinIf_Call_TxConfirmation
(
    VAR(uint16,AUTOMATIC) Channel
)
{
	P2CONST(LinIf_FrameCfgType,AUTOMATIC,LINIF_APPL_CONST) pLinIfFrame = NULL_PTR;
	P2VAR(LinIf_SlaveChannelRunningType,AUTOMATIC,LINIF_APPL_DATA) pChRunStatus = NULL_PTR;
	P2CONST(LinIf_ChannelConfigCfgType,AUTOMATIC,LINIF_APPL_CONST) pLinIfChannel = NULL_PTR;

	pChRunStatus = &(LinIf_SlaveChannelCfg[Channel]);
	pLinIfChannel = &(LinIf_ConfigPtr->LinIfSlaveChannel[Channel]);
	pLinIfFrame = pChRunStatus->curLinIfFrames;

	if(pChRunStatus->u8LinIfChannleSubStatus  ==  LINIF_CHANNEL_OPERATIONAL)
	{
		/**
		 * @req [SWS_LinIf_00852]  If no header of a transmit frame has been indicated before (no
		 *      response transmission is expected), the function LinIf_TxConfirmation shall return
		 *      without further action
		 */
		if(pChRunStatus->u8LinIfChTransStatus == LINIF_CH_TRANS_RESPONSE)
		{
			if(pLinIfFrame->LinIfPduDirection == LINIF_TX_PDU)
			{
				switch(pLinIfFrame->LinIfFrameType)
				{
					case LINIF_UNCONDITIONAL:
					case LINIF_EVENT_TRIGGERED:
						LinIf_SlaveHandleTxUnconitionalData(Channel);
						break;
					case LINIF_SRF:
						LinIf_SlaveHandleTxSrfData(Channel);
						break;
					default:
						break;
				}
			}
		}
		/**
		 * @req [SWS_LinIf_00754] The LIN Interface shall reload the running bus idle
		 *      timer each time when LinIf_HeaderIndication, LinIf_RxIndication, LinIf_TxConfirmation
		 *       or LinIf_LinErrorIndication with any error code is called.
		 */
		pChRunStatus->u16BusIdleTimer = pLinIfChannel->LinIfBusIdleTimeoutPeriod;
	}
}

/**
 * @details          The LIN Driver will call this function to report a detected error
 *                   event during header or response processing. This function is only
 *                   applicable for LIN slave nodes (available only if the ECU has any
 *                   LIN slave channel).
 * @param[in]        Channel   LinIf Channel Index.
 *
 *                   ErrorStatus  Type of detected error
 *
 * @return           void
 *
 */
STATIC FUNC(void,LINIF_CODE)LinIf_Call_LinErrorIndication
(
    VAR(uint16,AUTOMATIC) Channel,
	VAR(Lin_SlaveErrorType,AUTOMATIC) ErrorStatus
)
{
	VAR(PduIdType,AUTOMATIC)  upPduId ;
#if(LINIF_TP_SUPPORTED == STD_ON)
	VAR(PduIdType,AUTOMATIC) pduId;
	VAR(uint16,AUTOMATIC) u16ChIndex;
	VAR(NetworkHandleType,AUTOMATIC) netWork;
	P2CONST(LinTp_ChannelConfigType, AUTOMATIC, LINIF_APPL_CONST) pTpChannel = NULL_PTR;
#endif /* LINIF_TP_SUPPORTED == STD_ON */
	P2CONST(LinIf_FrameCfgType,AUTOMATIC,LINIF_APPL_CONST) pLinIfFrame = NULL_PTR;
	P2VAR(LinIf_SlaveChannelRunningType,AUTOMATIC,LINIF_APPL_DATA) pChRunStatus = NULL_PTR;

#if(LINIF_BUS_MIRRORING_SUPPORTED == STD_ON)
	VAR(NetworkHandleType,AUTOMATIC) netWork;
	VAR(Lin_FramePidType,AUTOMATIC)  pid;
	VAR(Lin_StatusType,AUTOMATIC)    linStatus = (Lin_StatusType)LIN_NOT_OK;
#endif /* LINIF_BUS_MIRRORING_SUPPORTED == STD_ON */

#if (LINIF_SLAVE_RESPONSE_ERROR_SIGNAL == STD_ON)
	P2CONST(LinIf_SlaveNodeCfgType,AUTOMATIC,LINIF_APPL_CONST) pLinIfSlaveNode = NULL_PTR;
	pLinIfSlaveNode = LinIf_ConfigPtr->LinIfSlaveChannel[Channel].LinIfSlaveNode;
#endif /* LINIF_SLAVE_RESPONSE_ERROR_SIGNAL == STD_ON */

	pChRunStatus = &(LinIf_SlaveChannelCfg[Channel]);
	pLinIfFrame = pChRunStatus->curLinIfFrames;

	if(pChRunStatus->u8LinIfChannleSubStatus  ==  LINIF_CHANNEL_OPERATIONAL)
	{
		/**
		 * @req [SWS_LinIf_00848]  If no header of a receive frame has been indicated before
		 *      (no response reception is expected), the function LinIf_RxIndication shall return
		 *      without further action.
		 */
		if(pChRunStatus->u8LinIfChTransStatus == LINIF_CH_TRANS_RESPONSE)
		{
			/**
			 * @req [SWS_LinIf_00735] If the function LinIf_LinErrorIndication is called, the LIN
			 *      Interface shall consider the response as lost. Therefore, the LIN Interface shall
			 *      report the runtime error code LINIF_E_RESPONSE to the Default Error Tracer unless the
			 *      error code of LinIf_LinErrorIndication is LIN_ERR_HEADER.
			 * @req [SWS_LinIf_00743] If the function LinIf_LinErrorIndication is called, the LIN
			 *      Interface shall consider the transmitted frame as lost and report the runtime error
			 *      code LINIF_E_RESPONSE to the Default Error Tracer unless the error code of
			 *      LinIf_LinErrorIndication is LIN_ERR_HEADER.
			 *
			 */
			if(ErrorStatus != LIN_ERR_HEADER)
			{
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
				LinIf_ReportDetError(LINIF_SID_LINERRORINDICATION,LINIF_E_RESPONSE);
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */

#if(LINIF_BUS_MIRRORING_SUPPORTED == STD_ON)
				/* Bus Mirroring */
				if(LinIf_SlaveChannelBusMirrorFlag[Channel] != (boolean)FALSE)
				{
					/**
					 * @req [SWS_LinIf_00869] If Bus Mirroring is enabled globally
					 *      (configuration parameter LinIfBusMirroringSupported) and has
					 *      been activated with a call to LinIf_EnableBusMirroring() for a
					 *      LIN channel, the LIN Interface shall call Mirror_ReportLinFrame()
					 *      each time LinIf_LinErrorIndication is called on that channel
					 *      with any error code of LinIf_LinErrorIndication other than LIN_ERR_HEADER,
					 *      providing the error status code and a NULL pointer for the frame content.
					 *
					 * @req [SWS_LinIf_00870] The LIN Interface shall translate the error code reported
					 *      by LinIf_LinErrorIndication to an error code of Lin_StatusType before calling
					 *      Mirror_ReportLinFrame(). The error code LIN_ERR_RESP_STOPBIT shall be mapped
					 *      LIN_TX_ERROR or LIN_RX_ERROR, depending on the direction of the current frame.
					 *      The error codes LIN_ERR_RESP_CHKSUM and LIN_ERR_INCOMP_RESP shall be mapped
					 *      to LIN_RX_ERROR. The error code LIN_ERR_NO_RESP shall be mapped to
					 *      LIN_RX_NO_RESPONSE. The error code LIN_ERR_RESP_DATABIT shall be mapped to
					 *      LIN_TX_ERROR.
					 */
					netWork = LinIf_ConfigPtr->LinIfChannel[Channel].LinIfComMNetworkHandleIdRef;
					pid = LinIf_SlavePIDTable[pLinIfFrame->LinIfFrameTableIndex] ;
					switch(ErrorStatus)
					{
						case LIN_ERR_RESP_STOPBIT:
							if(pLinIfFrame->LinIfPduDirection == LINIF_RX_PDU)
							{
								linStatus = (Lin_StatusType)LIN_RX_ERROR;
							}
							else if(pLinIfFrame->LinIfPduDirection == LINIF_TX_PDU)
							{
								linStatus = (Lin_StatusType)LIN_TX_ERROR;
							}
							else
							{
								/* do nothing */;
							}
							break;
						case LIN_ERR_RESP_CHKSUM:
						case LIN_ERR_INC_RESP:
							linStatus = (Lin_StatusType)LIN_RX_ERROR;
							break;
						case LIN_ERR_NO_RESP:
							linStatus = (Lin_StatusType)LIN_RX_NO_RESPONSE;
							break;
						case LIN_ERR_RESP_DATABIT:
							linStatus = (Lin_StatusType)LIN_TX_ERROR;
							break;
						default:
							break;
					}
					Mirror_ReportLinFrame(netWork,pid,NULL_PTR,linStatus);
				}
#endif /* LINIF_BUS_MIRRORING_SUPPORTED == STD_ON */
			}

			if(pLinIfFrame->LinIfPduDirection == LINIF_RX_PDU)
			{
				/**
				 * @req [SWS_LinIf_00736] If the reported error is of type LIN_ERR_RESP_STOPBIT,
				 *      LIN_ERR_RESP_CHKSUM, LIN_ERR_RESP_DATABIT or LIN_ERR_INC_RESP,
				 *      the LIN Interface shall set the response_error signal (see SWS_LinIf_00764).
				 */
#if (LINIF_SLAVE_RESPONSE_ERROR_SIGNAL == STD_ON)
				if((ErrorStatus != LIN_ERR_HEADER) && (ErrorStatus != LIN_ERR_NO_RESP))
				{
					if((pLinIfSlaveNode != NULL_PTR) && (pLinIfSlaveNode->LinIfResponseErrorSignal != 0xFFU))
					{
						pChRunStatus->bErrorSignalValue = (boolean)TRUE;
 					    (void)Com_SendSignal(pLinIfSlaveNode->LinIfResponseErrorSignal, &(pChRunStatus->bErrorSignalValue));
					}
				}
#endif /* LINIF_SLAVE_RESPONSE_ERROR_SIGNAL == STD_ON */
			}
			else if(pLinIfFrame->LinIfPduDirection == LINIF_TX_PDU)
			{
				/**
				 * @req [SWS_LinIf_00742]  If the function LinIf_LinErrorIndication is called,
				 *      the LIN Interface shall issue a <User_TxConfirmation> callback with result E_NOT_OK.
				 */
				upPduId = pLinIfFrame->LinIfTxPdu->LinIfTxPduRef;
				if(pLinIfFrame->LinIfTxPdu->LinIfTxConfirmationUL != NULL_PTR)
				{
					//pLinIfFrame->LinIfTxPdu->LinIfTxConfirmationUL(upPduId,E_NOT_OK); //4.4.0
					pLinIfFrame->LinIfTxPdu->LinIfTxConfirmationUL(upPduId);// 4.2.2
				}
				
				/**
				 * @req [SWS_LinIf_00744] If the error reported in LinIf_LinErrorIndication is of type
				 *      LIN_ERR_RESP_STOPBIT, LIN_ERR_RESP_CHKSUM or LIN_ERR_RESP_DATABIT, the
				 *      LIN Interface shall set the response_error signal (see SWS_LinIf_00764).
				 */
#if (LINIF_SLAVE_RESPONSE_ERROR_SIGNAL == STD_ON)
				if((ErrorStatus == LIN_ERR_RESP_STOPBIT) || (ErrorStatus == LIN_ERR_RESP_CHKSUM) || \
						(ErrorStatus == LIN_ERR_RESP_DATABIT))
				{
					if((pLinIfSlaveNode != NULL_PTR) && (pLinIfSlaveNode->LinIfResponseErrorSignal != 0xFFU))
					{
						pChRunStatus->bErrorSignalValue = (boolean)TRUE;
						(void)Com_SendSignal(pLinIfSlaveNode->LinIfResponseErrorSignal, &(pChRunStatus->bErrorSignalValue));
					}
				}
#endif /* LINIF_SLAVE_RESPONSE_ERROR_SIGNAL == STD_ON */
#if(LINIF_TP_SUPPORTED == STD_ON)
				if(pLinIfFrame->LinIfFrameType == LINIF_SRF)
				{
					netWork = LinIf_ConfigPtr->LinIfSlaveChannel[Channel].LinIfComMNetworkHandleIdRef;
					pTpChannel = LinTp_SlaveGetChannel(netWork,&u16ChIndex);
					if(pTpChannel != NULL_PTR)
					{
						pduId = LinTp_SlaveRunCfg[Channel].LinTpTxNSdu->LinTpTxNSduPduRef;
						if(LinTp_SlaveRunCfg[u16ChIndex].LinTpTxStatus == LINTP_TX_CONFIRMATION_STATUS)
						{
							/**
							 * @req [SWS_LinIf_00796]If a LIN error on the SRF response occurs
							 *      (LinIf_LinErrorIndication is called after reception of a SRF header),
							 *      the LIN Interface.
							 */
							LinTp_ResetChannel(&LinTp_SlaveRunCfg[u16ChIndex]);
							Dcm_TpTxConfirmation(pduId, E_NOT_OK);
						}
					}
				}
#endif /* LINIF_TP_SUPPORTED == STD_ON */
			}

			LinIf_ResetSlaveChannel(Channel);
		}
		else
		{
			if(ErrorStatus == LIN_ERR_HEADER)
			{
#if(LINIF_SLAVE_RESPONSE_ERROR_SIGNAL == STD_ON)
				if((pLinIfSlaveNode != NULL_PTR) && (pLinIfSlaveNode->LinIfResponseErrorSignal != 0xFFU))
				{
					pChRunStatus->bErrorSignalValue = (boolean)TRUE;
					(void)Com_SendSignal(pLinIfSlaveNode->LinIfResponseErrorSignal, &(pChRunStatus->bErrorSignalValue));
				}
#endif /* LINIF_SLAVE_RESPONSE_ERROR_SIGNAL == STD_ON */
			}
		}
		/**
		 * @req [SWS_LinIf_00754] The LIN Interface shall reload the running bus idle
		 *      timer each time when LinIf_HeaderIndication, LinIf_RxIndication, LinIf_TxConfirmation
		 *       or LinIf_LinErrorIndication with any error code is called.
		 */
		pChRunStatus->u16BusIdleTimer = \
				LinIf_ConfigPtr->LinIfSlaveChannel[Channel].LinIfBusIdleTimeoutPeriod;
	}
}

/**
 * @brief   LinIf_SlaveSleepProcess - According to different conditions for sleep processing.
 * @details ...
 *
 * @param[in]   Channel      Indicates the channel to be operated.
 * @return      void
 */
STATIC FUNC(void,LINIF_CODE)LinIf_SlaveSleepProcess
(
	VAR(uint16,AUTOMATIC) Channel
)
{
	P2CONST(LinIf_ChannelConfigCfgType,AUTOMATIC,LINIF_APPL_CONST) pLinIfChannel = NULL_PTR;

	pLinIfChannel = &(LinIf_ConfigPtr->LinIfSlaveChannel[Channel]);

	/**
	 * @req[SWS_LinIf_00750] If the function LinIf_RxIndication is called and the received
	 *     frame is a MRF with the first data byte (NAD) equal to 0, a go-to-sleep command
	 *     has been received and the transition to sleep mode shall be executed.
	 * @req[SWS_LinIf_00755] In case a bus idle timeout occurs, the sleep mode transition
	 *     shall be executed.
	 * @req[SWS_LinIf_00756] In case of SWS_LinIf_00750 or SWS_LinIf_00755, the LIN
	 *     Interface shall invoke the function <User>_GotoSleepIndication.
	 */
	if(pLinIfChannel->LinIfGotoSleepIndication != NULL_PTR)
	{
		pLinIfChannel->LinIfGotoSleepIndication(pLinIfChannel->LinIfComMNetworkHandleIdRef);
	}
}

#if (LINIF_TP_SUPPORTED == STD_ON)
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
/**
 * @brief      LinTp_HLDChecksEntry - checks for invalid mode transitions
 * @details    Check that the timing of the API call is correct
 *
 * @param[in]  u8ServiceId   Service id of the API
 *
 * @return     The timing state of an API call.
 * @retval     E_OK       Call correctly.
 * @retval     E_NOT_OK   Call exception.
 */
STATIC FUNC(Std_ReturnType,LINIF_CODE) LinTp_HLDChecksEntry
(
  VAR(uint8, AUTOMATIC) u8ServiceId
)
{
  VAR(Std_ReturnType, AUTOMATIC) checkStatus = (Std_ReturnType)E_OK;
  if(LINTP_SID_INIT == u8ServiceId)
  {
    if(LINTP_INIT == LinTp_eStatus)
    {
        checkStatus = (Std_ReturnType)E_NOT_OK;
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
        LinIf_ReportDetError(u8ServiceId , LINIF_E_INIT_FAILED);
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */
    }
  }
  else
  {
    if(LINTP_UNINIT == LinTp_eStatus)
    {
        checkStatus = (Std_ReturnType)E_NOT_OK;
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
        LinIf_ReportDetError(u8ServiceId , LINIF_E_UNINIT);
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */
    }
  }
  return  checkStatus;
}

/**
 * @brief       LinTp_InitCheckPoint - Checks whether the pointer is valid
 * @details ...
 *
 * @param[in]   pLinTpCfgPtr            Pointer parameter for checking
 * @param[in]   u8ServiceId             Service id of the API
 *
 * @return      Result of examination
 */
STATIC FUNC(Std_ReturnType,LINIF_CODE)LinTp_InitCheckPoint
(
    P2CONST(LinTp_ConfigType, AUTOMATIC, LINIF_APPL_CONST)pLinTpCfgPtr ,
    VAR(uint8,AUTOMATIC) u8ServiceId
)
{
  VAR(Std_ReturnType,AUTOMATIC) retStatus = (Std_ReturnType)E_OK;
  if(NULL_PTR == pLinTpCfgPtr)
  {
      retStatus = (Std_ReturnType)E_NOT_OK;
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
      LinIf_ReportDetError(u8ServiceId,LINIF_E_PARAM_POINTER);
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */
  }
  return retStatus;
}

/**
 * @brief       LinTp_TransmitCheckPoint - Checks whether the pointer is valid
 * @details ...
 *
 * @param[in]   pLinTpPtr            Pointer parameter for checking
 * @param[in]   u8ServiceId          Service id of the API
 *
 * @return      Result of examination
 */
STATIC FUNC(Std_ReturnType,LINIF_CODE)LinTp_TransmitCheckPoint
(
    P2CONST(PduInfoType, AUTOMATIC, LINIF_APPL_CONST)pLinTpPtr ,
    VAR(uint8,AUTOMATIC) u8ServiceId
)
{
  VAR(Std_ReturnType,AUTOMATIC) retStatus = (Std_ReturnType)E_OK;
  if(NULL_PTR == pLinTpPtr)
  {
    retStatus = (Std_ReturnType)E_NOT_OK;
	/**
	 * @req [SWS_LinIf_00574]If development error detection is enabled
	 *      and the parameter PduInfoPtr has an invalid value,
	 *      the function LinTp_Transmit shall raise the development error
	 *      code LINIF_E_PARAM_POINTER.
	 */
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
      LinIf_ReportDetError(u8ServiceId,LINIF_E_PARAM_POINTER);
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */
  }
  return retStatus;
}

/**
 * @brief       LinTp_CheckSduPtrPoint - Checks whether the pointer is valid
 * @details ...
 *
 * @param[in]   pLinTpPtr            Pointer parameter for checking
 * @param[in]   u8ServiceId          Service id of the API
 *
 * @return      Result of examination
 */
STATIC FUNC(Std_ReturnType,LINIF_CODE)LinTp_CheckSduPtrPoint
(
    P2CONST(uint8, AUTOMATIC, LINIF_APPL_CONST)pLinTpPtr ,
    VAR(uint8,AUTOMATIC) u8ServiceId
)
{
  VAR(Std_ReturnType,AUTOMATIC) retStatus = (Std_ReturnType)E_OK;
  if(NULL_PTR == pLinTpPtr)
  {
    retStatus = (Std_ReturnType)E_NOT_OK;
	/**
	 * @req [SWS_LinIf_00845]If development error detection is enabled,
	 *      the PID is evaluated and rated to belong to a transmit frame
	 *      and the parameter PduPtr->SduPtr has an invalid value, the
	 *      function LinIf_HeaderIndication shall raise the development
	 *      error code LINIF_E_PARAM_POINTER
	 */
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
      LinIf_ReportDetError(u8ServiceId,LINIF_E_PARAM_POINTER);
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */
  }
  return retStatus;
}
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */
/**
 * @brief    LinTp_CheckTxPduId - Checks whether the pdu id is valid.
 * @details  Verify that the entry is valid in all TxPdu Collections.
 *
 * @param[in]   TxPduId            Tx Pdu Id.
 * @param[in]   u8ServiceId        Service id of the API
 * @param[out]  chIdex             Tx Pdu Channel Index.
 * @return      Result of examination
 */
STATIC FUNC(Std_ReturnType,LINIF_CODE) LinTp_CheckTxPduId
(
    VAR(PduIdType, AUTOMATIC) txPduId ,
    VAR(uint8,AUTOMATIC) u8ServiceId,
	P2VAR(uint16, AUTOMATIC,LINIF_APPL_DATA) chIdex
)
{
	VAR(uint16,AUTOMATIC) u16Loop = 0U;
	VAR(Std_ReturnType,AUTOMATIC) retStatus = (Std_ReturnType)E_NOT_OK;

	for(u16Loop = 0U; u16Loop < LINTP_MAX_TX_NSDU_NUM; u16Loop++)
	{
		if(LinTp_ConfigPtr->LinTpTxNSdu[u16Loop].LinTpTxNSduId ==  txPduId)
		{
			(*chIdex) = u16Loop;
			retStatus = (Std_ReturnType)E_OK;
			break;
		}
	}
	if(retStatus != (Std_ReturnType)E_OK)
	{
		retStatus = (Std_ReturnType)E_NOT_OK;
		/**
		 * @req [SWS_LinIf_00576]If development error detection is enabled
		 *      and the parameter  TxPduId has an invalid value, the
		 *      function LinTp_Transmit shall raise the
		 *      development error code LINIF_E_PARAMETER.
		 */
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
      LinIf_ReportDetError(u8ServiceId,LINIF_E_PARAMETER);
#endif/* LINIF_DEV_ERROR_DETECT == STD_ON */
	}

	return retStatus;
}

/**
 * @brief    LinTp_ResetChannel - Reset LinTp Channel .
 * @details  Release the channel where LinTp resides.
 *
 * @param[in]   chPtr    The configured address needs to be written.
 * @return      void
 */
STATIC FUNC(void,LINIF_CODE) LinTp_ResetChannel
(
    P2VAR(LinIf_SlaveTpRunCfgType, AUTOMATIC, LINIF_APPL_DATA) chPtr
)
{
	VAR(uint8,AUTOMATIC) u8Loop = 0U;

	chPtr->LinTpTxNSdu = NULL_PTR;
	chPtr->LinTpRxNSdu = NULL_PTR;
	chPtr->LinTpChannel = NULL_PTR;
	chPtr->SduRemaining = 0U;
	chPtr->UpperBufRemaining = 0U;
	chPtr->u32SduLength = 0U;
	chPtr->LinTpRxStatus = LINTP_RX_IDLE;
	chPtr->LinTpTxStatus = LINTP_TX_IDLE;
	chPtr->bNasTimerSwitch = (boolean)FALSE;
	chPtr->bNcrTimerSwitch = (boolean)FALSE;
	chPtr->bNcsTimerSwitch = (boolean)FALSE;
	chPtr->u16NasTimer = 0U;
	chPtr->u16NcrTimer = 0U;
	chPtr->u16NcsTimer = 0U;
	chPtr->u8BetyIndex = 0U;
	chPtr->u8SequenceNum = 0U;
	chPtr->u8CopyCnt = 0U;
	chPtr->u8SubChStatus = LINTP_CHANNEL_IDLE;

	for(u8Loop=0U;u8Loop < LINTP_FRAME_MAX_LEN;u8Loop++)
	{
		chPtr->SduRxBuffer[u8Loop] = 0xFFU;
		chPtr->SduTxBuffer[u8Loop] = 0xFFU;
	}
}

/**
 * @details          Obtain the Rx Sdu Configuration for the target network channel and
 *                   appropriate node address.
 * @param[in]        Channel   LinIf Channel Index.
 *
 *                   Lin_SduPtr  Pointer to pointer to a shadow buffer or memory mapped LIN
 *                               Hardware receive buffer where the current SDU is stored.
 *                               This pointer is only valid if the response is received.
 *
 * @return           void
 *
 */
STATIC FUNC_P2CONST(LinTp_RxNSduType, AUTOMATIC, LINIF_APPL_CONST)LinTp_SlaveGetRxNSdu
(
	VAR(uint16,AUTOMATIC) Channel,
	VAR(uint8,AUTOMATIC) u8Nad
)
{
	VAR(uint16,AUTOMATIC) u16Loop = 0U;
	VAR(NetworkHandleType,AUTOMATIC) netWork = 0U;
	P2CONST(LinTp_RxNSduType, AUTOMATIC, LINIF_APPL_CONST) pRxSdu = NULL_PTR;

	netWork = LinIf_ConfigPtr->LinIfSlaveChannel[Channel].LinIfComMNetworkHandleIdRef;

	for(u16Loop = 0U; u16Loop < LINTP_MAX_RX_NSDU_NUM; u16Loop++)
	{
		/**
		 * 1. Functional addressing form
		 * 2. Physical addressing form
		 */
		if(LinTp_ConfigPtr->LinTpRxNSdu[u16Loop].LinTpRxNSduChannelRef == netWork)
		{
			if(((LinTp_ConfigPtr->LinTpRxNSdu[u16Loop].LinTpRxNSduNad == LINIF_FUNCTIONAL_NAD) && \
			  (LinTp_ConfigPtr->LinTpRxNSdu[u16Loop].LinTpRxNSduNad == u8Nad)) || \
			  ((LinTp_ConfigPtr->LinTpRxNSdu[u16Loop].LinTpRxNSduNad == u8Nad) && \
			  (LinIf_SlaveConfiguredNAD[Channel] == u8Nad)))
			  {
				pRxSdu = &(LinTp_ConfigPtr->LinTpRxNSdu[u16Loop]);
				break;
			  }
		}
	}

	return pRxSdu;
}

/**
 * @details          Obtain the channel Configuration for the target network channel
 * @param[in]        NetworkHandleType   Channel   Identification of the LIN channel
 *
 * @return           void
 *
 */
STATIC FUNC_P2CONST(LinTp_ChannelConfigType, AUTOMATIC, LINIF_APPL_CONST)LinTp_SlaveGetChannel
(
	VAR(NetworkHandleType,AUTOMATIC) Channel,
	P2VAR(uint16,AUTOMATIC,LINIF_APPL_DATA) u16ChIndex
)
{
	VAR(uint16,AUTOMATIC) u16Loop = 0U;
	P2CONST(LinTp_ChannelConfigType, AUTOMATIC, LINIF_APPL_CONST) pChannel = NULL_PTR;

	for(u16Loop = 0U; u16Loop < LINTP_MAX_CHANNEL_NUM; u16Loop++)
	{
		if(LinTp_ConfigPtr->LinTpChannel[u16Loop].LinTpChannelRef == Channel)
		{
			pChannel = &(LinTp_ConfigPtr->LinTpChannel[u16Loop]);
			(*u16ChIndex) = u16Loop;
			break;
		}
	}

	return pChannel;
}

/**
 * @brief       LinTp_RxSFBufferRequestAndCopyData - Requests a receive buffer and copy data from the 'PduR'.
 * @details  ...
 * @param[in]   Channel  Run time Channel Index.
 * @return      void
 *
 */
STATIC FUNC(void, LINIF_CODE) LinTp_RxSFBufferRequestAndCopyData
(
	VAR(uint16, AUTOMATIC) Channel
)
{
	VAR(PduIdType,AUTOMATIC) pduId;
	VAR(PduInfoType,AUTOMATIC) infoData ;
	P2VAR(PduInfoType, AUTOMATIC, LINIF_APPL_DATA) info ;
	VAR(BufReq_ReturnType,AUTOMATIC) bufResult = BUFREQ_E_NOT_OK;
	VAR(PduLengthType,AUTOMATIC) copyLen ;

	info = &infoData ;

	/* Get a copy of the effective length */
	copyLen = LINIF_GET_MIN_DATA((LINTP_FRAME_MAX_LEN - LinTp_SlaveRunCfg[Channel].u8BetyIndex), \
					LinTp_SlaveRunCfg[Channel].SduRemaining);

    /* Set destination buffer pointer and he number of bytes to be copied */
    info->SduDataPtr = &(LinTp_SlaveRunCfg[Channel].SduRxBuffer[LinTp_SlaveRunCfg[Channel].u8BetyIndex]);
    info->SduLength = copyLen;
	pduId = LinTp_SlaveRunCfg[Channel].LinTpRxNSdu->LinTpRxNSduPduRef;

    /**
     * @req [SWS_LinIf_00075] The LIN Interface shall call the function PduR_LinTpStartOfReception
     *      with a PduInfo pointer and TpSduLength when the start of a TP message reception is
     *      indicated by the reception of a FF or a SF. PduInfo is pointer to the buffer containing
     *      the received data (SduDataPtr) and data length (SduLength). The data length (including SID)
     *      is 5 bytes for FF and up to 6 bytes for SF. TpSduLength is the total length of the Sdu.
     * @req [SWS_LinIf_00076] The LIN Interface shall convert the received NAD from the
     *      transmitting LIN node to an N-SDU Id that the upper layer understands.
     */
    bufResult = Dcm_StartOfReception(
    		pduId,
			info,
			LinTp_SlaveRunCfg[Channel].u32SduLength,
			&(LinTp_SlaveRunCfg[Channel].UpperBufRemaining));

    if ((BUFREQ_OK == bufResult) && (LinTp_SlaveRunCfg[Channel].UpperBufRemaining >= copyLen))
    {
    	/**
    	 * @req [SWS_LinIf_00674] After reception of each frame of a TP message (SF, FF and CF),
    	 *      the LIN Interface shall call the function PduR_LinTpCopyRxData with a PduInfo
    	 *      pointer containing received data (SduDataPtr) and data length (SduLength).
    	 *      The data length is 5 bytes (including SID) for FF, up to 6 bytes for SF and 6 bytes
    	 *      for CF (or less in case of the last CF).
    	 */
    	bufResult = Dcm_CopyRxData(
    			pduId,
				info,
				&(LinTp_SlaveRunCfg[Channel].UpperBufRemaining));

    	if(BUFREQ_OK == bufResult)
    	{
        	/**
        	 * @req [SWS_LinIf_00078] When the LIN Interface has received the SF or the last CF of a
        	 *      TP message successfully, it shall notify the upper layer by calling the function
        	 *      PduR_LinTpRxIndication with the result E_OK
        	 *
        	 * @req [SWS_LinIf_00414] The LIN Interface shall set the sub-state of a
        	 *      channel to LINTP_CHANNEL_IDLE when it has successfully terminated the
        	 *      transmission or reception of a LIN TP message
        	 */

			LinTp_ResetChannel(&LinTp_SlaveRunCfg[Channel]);
								Dcm_TpRxIndication(pduId, E_OK);
    	}
    	else if(BUFREQ_E_NOT_OK == bufResult)
    	{
        	/**
        	 * @req [SWS_LinIf_00677] If the function PduR_LinTpCopyRxData returns BUFREQ_E_NOT_OK,
        	 *      the LIN Interface shall abort the reception and notify the upper layer by calling
        	 *      the function PduR_LinTpRxIndication with the result E_NOT_OK.
        	 * @req [SWS_LinIf_00414] The LIN Interface shall set the sub-state of a
        	 *      channel to LINTP_CHANNEL_IDLE when it has successfully terminated the
        	 *      transmission or reception of a LIN TP message
        	 */
			LinTp_ResetChannel(&LinTp_SlaveRunCfg[Channel]);
    		Dcm_TpRxIndication(pduId, E_NOT_OK);
    	}
    	else
    	{
    		/* do nothing .... */
    	}
    }
    else
    {
    	/**
    	 * @req [SWS_LinIf_00701] If the function PduR_LinTpStartOfReception returns
    	 *      BUFREQ_OK with a smaller available buffer size than needed for the data received
    	 *      in the first frame of a TP message (SF or FF), the LIN Interface shall abort the
    	 *      reception and notify the upper layer by calling the function PduR_LinTpRxIndication
    	 *      with result E_NOT_OK.
    	 */
    	if((BUFREQ_OK == bufResult) && \
    			(LinTp_SlaveRunCfg[Channel].UpperBufRemaining < LinTp_SlaveRunCfg[Channel].u32SduLength))
    	{
			LinTp_ResetChannel(&LinTp_SlaveRunCfg[Channel]);
    		Dcm_TpRxIndication(pduId, E_NOT_OK);
    	}
		else{
			
			/**
			 * @req [SWS_LinIf_00676] If the function PduR_LinTpStartOfReception returns BUFREQ_E_NOT_OK or
			 *      BUFREQ_E_OVFL, the LIN Interface shall abort the reception without any further calls to PduR.
			 * @req [SWS_LinIf_00414] The LIN Interface shall set the sub-state of a
			 *      channel to LINTP_CHANNEL_IDLE when it has successfully terminated the
			 *      transmission or reception of a LIN TP message
			 * @req [SWS_LinIf_00688] The LIN Interface shall set the sub-state of a
			 *      channel to LINTP_CHANNEL_IDLE when it has detected an unrecoverable
			 *      error on this channel.
			 */
			LinTp_ResetChannel(&LinTp_SlaveRunCfg[Channel]);
		}
    }
}

/**
 * @details     The case where MRF is processed by the slave machine and the frame type
 *              is equal to a signal frame.
 * @param[in]
 *              Lin_SduPtr  Pointer to pointer to a shadow buffer or memory mapped LIN
 *                          Hardware receive buffer where the current SDU is stored.
 *                          This pointer is only valid if the response is received.
 *              pRxSdu      Point to the configuration of the associated Rx Sdus.
 *
 * @return      void
 *
 */
STATIC FUNC(void,LINIF_CODE)LinTp_SlaveHandleSF
(
	P2VAR(uint8, AUTOMATIC,LINIF_APPL_DATA) Lin_SduPtr,
	P2CONST(LinTp_RxNSduType, AUTOMATIC, LINIF_APPL_CONST) pRxSdu
)
{
	VAR(PduIdType,AUTOMATIC) pduId;
	VAR(uint8,AUTOMATIC) u8Len = 0u;
	VAR(uint8,AUTOMATIC) u8Loop = 0U;
	VAR(uint16,AUTOMATIC) u16ChIndex = 0u;
	VAR(boolean,AUTOMATIC) bIgnore = (boolean)FALSE;

	P2CONST(LinTp_ChannelConfigType, AUTOMATIC, LINIF_APPL_CONST) pChannel = NULL_PTR;

	pChannel = LinTp_SlaveGetChannel(pRxSdu->LinTpRxNSduChannelRef, &u16ChIndex);

	if(pChannel != NULL_PTR)
	{
		if(LinTp_SlaveRunCfg[u16ChIndex].u8SubChStatus == LINTP_CHANNEL_BUSY)
		{
			if(LinTp_SlaveRunCfg[u16ChIndex].eOngoingRequest == LINTP_PHY_REQUEST_TYPE)
			{
				/**
				 * @req [SWS_LinIf_00807] If a new functional request is received while reception of a
				 *      physical request is ongoing, the LIN Interface shall ignore the functional
				 *      request.
				 *
				 */
				if(Lin_SduPtr[LINIF_PDU_NAD_OFFSET] == LINIF_FUNCTIONAL_NAD)
				{
					bIgnore = (boolean)TRUE;
				}
				else
				{
					/**
					 * @req [SWS_LinIf_00808] If the start of new physical request (SF or FF) is
					 *       received while reception of a physical request is ongoing, the LIN
					 *       Interface shall stop the current LIN TP message reception
					 *       (see also SWS_LinIf_00651). If the received NAD matches the configured
					 *       NAD or broadcast NAD, the new request shall be accepted.
					 *
					 * @req [SWS_LinIf_00651]In case a FF or a SF is received after a CF which is
					 *      not the last CF, the LIN Interface shall stop the current LIN TP message
					 *      reception.
					 * @req [SWS_LinIf_00653] In case a FF or a SF is received after a CF, the LIN
					 *      Interface shall report this failure to PDU Router by calling the function
					 *      PduR_LinTpRxIndication with the result E_NOT_OK.
					 *
					 * @req [SWS_LinIf_00797]If the start of a new physical request (SF or FF) is
					 *      received while transmission of a previously triggered physical request
					 *      is ongoing, the LIN Interface shall abort the ongoing transmission.
					 *      If the NAD matches the configured NAD of the slave node or the broadcast NAD,
					 *      the LIN Interface shall accept the new physical request.
					 * @req [SWS_LinIf_00414] The LIN Interface shall set the sub-state of a
					 *      channel to LINTP_CHANNEL_IDLE when it has successfully terminated the
					 *      transmission or reception of a LIN TP message
					 * @req [SWS_LinIf_00688] The LIN Interface shall set the sub-state of a
					 *      channel to LINTP_CHANNEL_IDLE when it has detected an unrecoverable
					 *      error on this channel.
					 */
					pduId = LinTp_SlaveRunCfg[u16ChIndex].LinTpRxNSdu->LinTpRxNSduPduRef;
					
					if(LinTp_SlaveRunCfg[u16ChIndex].LinTpRxNSdu != NULL_PTR)
					{
						LinTp_ResetChannel(&LinTp_SlaveRunCfg[u16ChIndex]);
						Dcm_TpRxIndication(pduId,E_NOT_OK);
					}
					else{
						LinTp_ResetChannel(&LinTp_SlaveRunCfg[u16ChIndex]);
					}
				}
			}
		}

		/**
		 * @req [SWS_LinIf_00652] In case an invalid data length is received (a SF with a length of 0
		 *      (zero) or greater than 6, a FF with a length of less than 7), the LIN Interface shall
		 *      ignore the LIN TP message.
		 */
		u8Len = (Lin_SduPtr[LINIF_PDU_PCI_OFFSET] & LINIF_PCI_LN_MASK);
		if((u8Len == 0U) || (u8Len > LINIF_SF_MAX_LENGTH))
		{
			bIgnore = (boolean)TRUE;
		}

		if(bIgnore == (boolean)FALSE)
		{
			LinTp_SlaveRunCfg[u16ChIndex].LinTpChannel = pChannel;
			LinTp_SlaveRunCfg[u16ChIndex].LinTpRxNSdu = pRxSdu;
			LinTp_SlaveRunCfg[u16ChIndex].LinTpRxStatus = LINTP_RX_SF_STATUS;
			LinTp_SlaveRunCfg[u16ChIndex].SduRemaining = u8Len;
			LinTp_SlaveRunCfg[u16ChIndex].u8BetyIndex = LINIF_PDU_SF_SID_OFFSET;
			if(Lin_SduPtr[LINIF_PDU_NAD_OFFSET] == LINIF_FUNCTIONAL_NAD)
			{
				LinTp_SlaveRunCfg[u16ChIndex].eOngoingRequest = LINTP_FUN_REQUEST_TYPE ;
			}
			else
			{
				LinTp_SlaveRunCfg[u16ChIndex].eOngoingRequest = LINTP_PHY_REQUEST_TYPE;
			}
			LinTp_SlaveRunCfg[u16ChIndex].u32SduLength = u8Len;
			/**
			 * @req[SWS_LinIf_00323] The LIN Interface shall set the sub-state
			 *     of a channel to LINTP_CHANNEL_BUSY when it has received a FF or a
			 *     SF on the channel and it has detected it as a TP message
			 *     (i.e. not conflicting with a configuration response from a
			 *     LIN slave node or a configuration request from a LIN master node).
			 */
			LinTp_SlaveRunCfg[u16ChIndex].u8SubChStatus = LINTP_CHANNEL_BUSY;

			for(u8Loop = 0U; u8Loop<LINIF_FRAME_MAX_LEN;u8Loop++)
			{
				LinTp_SlaveRunCfg[u16ChIndex].SduRxBuffer[u8Loop] = Lin_SduPtr[u8Loop];
			}
		}
	}
}

/**
 * @brief       LinTp_RxFFBufferRequestAndCopyData - Requests a receive buffer and copy data from the 'PduR'.
 * @details  ...
 * @param[in]   Channel  Run time Channel Index.
 * @return      void
 *
 */
STATIC FUNC(void, LINIF_CODE) LinTp_RxFFBufferRequestAndCopyData
(
	VAR(uint16, AUTOMATIC) Channel
)
{
	VAR(PduIdType,AUTOMATIC) pduId;
	VAR(PduInfoType,AUTOMATIC) infoData ;
	P2VAR(PduInfoType, AUTOMATIC, LINIF_APPL_DATA) info ;
	VAR(BufReq_ReturnType,AUTOMATIC) bufResult = BUFREQ_E_NOT_OK;
	VAR(PduLengthType,AUTOMATIC) copyLen ;

	info = &infoData ;

	/* Get a copy of the effective length */
	copyLen = LINIF_GET_MIN_DATA((LINTP_FRAME_MAX_LEN - LinTp_SlaveRunCfg[Channel].u8BetyIndex), \
					LinTp_SlaveRunCfg[Channel].SduRemaining);

    /* Set destination buffer pointer and he number of bytes to be copied */
    info->SduDataPtr = &(LinTp_SlaveRunCfg[Channel].SduRxBuffer[LinTp_SlaveRunCfg[Channel].u8BetyIndex]);
    info->SduLength = copyLen;

	pduId = LinTp_SlaveRunCfg[Channel].LinTpRxNSdu->LinTpRxNSduPduRef;
    /**
     * @req [SWS_LinIf_00075] The LIN Interface shall call the function PduR_LinTpStartOfReception
     *      with a PduInfo pointer and TpSduLength when the start of a TP message reception is
     *      indicated by the reception of a FF or a SF. PduInfo is pointer to the buffer containing
     *      the received data (SduDataPtr) and data length (SduLength). The data length (including SID)
     *      is 5 bytes for FF and up to 6 bytes for SF. TpSduLength is the total length of the Sdu.
     */
    bufResult = Dcm_StartOfReception(
    		pduId,
			info,
			LinTp_SlaveRunCfg[Channel].u32SduLength,
			&(LinTp_SlaveRunCfg[Channel].UpperBufRemaining));

    if ((BUFREQ_OK == bufResult) && (LinTp_SlaveRunCfg[Channel].UpperBufRemaining >= copyLen))
    {
    	/**
    	 * @req [SWS_LinIf_00674] After reception of each frame of a TP message (SF, FF and CF),
    	 *      the LIN Interface shall call the function PduR_LinTpCopyRxData with a PduInfo
    	 *      pointer containing received data (SduDataPtr) and data length (SduLength).
    	 *      The data length is 5 bytes (including SID) for FF, up to 6 bytes for SF and 6 bytes
    	 *      for CF (or less in case of the last CF).
    	 */
    	bufResult = Dcm_CopyRxData(
    			pduId,
				info,
				&(LinTp_SlaveRunCfg[Channel].UpperBufRemaining));

    	if(BUFREQ_OK == bufResult)
    	{
    		LinTp_SlaveRunCfg[Channel].SduRemaining -= copyLen;
    		LinTp_SlaveRunCfg[Channel].u8BetyIndex = LINIF_PDU_CF_DATA_OFFSET;
    		/**
    		 * Calculate the length of data to be replicated next time.
    		 */
    		copyLen = LINIF_GET_MIN_DATA((LINTP_FRAME_MAX_LEN - LinTp_SlaveRunCfg[Channel].u8BetyIndex), \
    							LinTp_SlaveRunCfg[Channel].SduRemaining);

    		/**
    		 * Check if the upper level buffer is sufficient.
    		 */
    		if(LinTp_SlaveRunCfg[Channel].UpperBufRemaining >= copyLen)
    		{
    			/**
    			 * Get Ready to receive the next frame of data.
    			 */
    			LinTp_SlaveRunCfg[Channel].LinTpRxStatus = LINTP_RX_CF_WAIT_STATUS;
    		}
    		else
    		{
    			/**
    			 * Polling upper layer requests for buffer space.
    			 */
    			/**
    			 * @req [SWS_LinIf_00793]If the function PduR_LinTpCopyRxData returns
    			 *      BUFREQ_OK with a smaller available buffer size than needed for
    			 *      the next CF, the LIN Interface shall call the function
    			 *      PduR_LinTpCopyRxData with a data length (SduLength) 0
    			 *      (zero) again during the next processing of the MainFunction
    			 *      until the available buffer size is big enough or the next CF is
    			 *      received.
    			 */
    			LinTp_SlaveRunCfg[Channel].LinTpRxStatus = LINTP_RX_REQUEST_BUFFER_STATUS;
    		}
    	}
    	else if(BUFREQ_E_NOT_OK == bufResult)
    	{
        	/**
        	 * @req [SWS_LinIf_00677] If the function PduR_LinTpCopyRxData returns BUFREQ_E_NOT_OK,
        	 *      the LIN Interface shall abort the reception and notify the upper layer by calling
        	 *      the function PduR_LinTpRxIndication with the result E_NOT_OK.
			 * @req [SWS_LinIf_00414] The LIN Interface shall set the sub-state of a
			 *      channel to LINTP_CHANNEL_IDLE when it has successfully terminated the
			 *      transmission or reception of a LIN TP message
			 * @req [SWS_LinIf_00688] The LIN Interface shall set the sub-state of a
			 *      channel to LINTP_CHANNEL_IDLE when it has detected an unrecoverable
			 *      error on this channel.
        	 */
			LinTp_ResetChannel(&LinTp_SlaveRunCfg[Channel]);
    		Dcm_TpRxIndication(pduId, E_NOT_OK);
			
    	}
		else
		{
			/* do nothing... */
		}
    }
    else
    {
    	/**
    	 * @req [SWS_LinIf_00701] If the function PduR_LinTpStartOfReception returns
    	 *      BUFREQ_OK with a smaller available buffer size than needed for the data received
    	 *      in the first frame of a TP message (SF or FF), the LIN Interface shall abort the
    	 *      reception and notify the upper layer by calling the function PduR_LinTpRxIndication
    	 *      with result E_NOT_OK.
    	 */
    	if((BUFREQ_OK == bufResult) && \
    			(LinTp_SlaveRunCfg[Channel].UpperBufRemaining < LinTp_SlaveRunCfg[Channel].u32SduLength))
    	{
			LinTp_ResetChannel(&LinTp_SlaveRunCfg[Channel]);
    		Dcm_TpRxIndication(pduId, E_NOT_OK);
    	}else{
			/**
			 * @req [SWS_LinIf_00676] If the function PduR_LinTpStartOfReception returns BUFREQ_E_NOT_OK or
			 *      BUFREQ_E_OVFL, the LIN Interface shall abort the reception without any further calls to PduR.
			 * @req [SWS_LinIf_00414] The LIN Interface shall set the sub-state of a
			 *      channel to LINTP_CHANNEL_IDLE when it has successfully terminated the
			 *      transmission or reception of a LIN TP message
			 * @req [SWS_LinIf_00688] The LIN Interface shall set the sub-state of a
			 *      channel to LINTP_CHANNEL_IDLE when it has detected an unrecoverable
			 *      error on this channel.
			 */
			LinTp_ResetChannel(&LinTp_SlaveRunCfg[Channel]);
		}

    }
}

/**
 * @brief       LinTp_RxCFCopyData - Requests a receive buffer and copy data from the 'PduR'.
 * @details  ...
 * @param[in]   Channel  Run time Channel Index.
 * @return      void
 *
 */
STATIC FUNC(void, LINIF_CODE) LinTp_RxCFCopyData
(
	VAR(uint16, AUTOMATIC) Channel
)
{
	VAR(PduIdType,AUTOMATIC) pduId;
	VAR(PduInfoType,AUTOMATIC) infoData ;
	P2VAR(PduInfoType, AUTOMATIC, LINIF_APPL_DATA) info ;
	VAR(BufReq_ReturnType,AUTOMATIC) bufResult = BUFREQ_E_NOT_OK;
	VAR(PduLengthType,AUTOMATIC) copyLen ;

	info = &infoData ;

	/* Get a copy of the effective length */
	copyLen = LINIF_GET_MIN_DATA((LINTP_FRAME_MAX_LEN - LinTp_SlaveRunCfg[Channel].u8BetyIndex), \
					LinTp_SlaveRunCfg[Channel].SduRemaining);

    /* Set destination buffer pointer and he number of bytes to be copied */
    info->SduDataPtr = &(LinTp_SlaveRunCfg[Channel].SduRxBuffer[LinTp_SlaveRunCfg[Channel].u8BetyIndex]);
    info->SduLength = copyLen;
	pduId = LinTp_SlaveRunCfg[Channel].LinTpRxNSdu->LinTpRxNSduPduRef;


	/**
	 * @req [SWS_LinIf_00674] After reception of each frame of a TP message (SF, FF and CF),
	 *      the LIN Interface shall call the function PduR_LinTpCopyRxData with a PduInfo
	 *      pointer containing received data (SduDataPtr) and data length (SduLength).
	 *      The data length is 5 bytes (including SID) for FF, up to 6 bytes for SF and 6 bytes
	 *      for CF (or less in case of the last CF).
	 */
	bufResult = Dcm_CopyRxData(
			pduId,
			info,
			&(LinTp_SlaveRunCfg[Channel].UpperBufRemaining));

	if(BUFREQ_OK == bufResult)
	{
		LinTp_SlaveRunCfg[Channel].SduRemaining -= copyLen;
		LinTp_SlaveRunCfg[Channel].u8BetyIndex = LINIF_PDU_CF_DATA_OFFSET;
		/**
		 * Calculate the length of data to be replicated next time.
		 */
		copyLen = LINIF_GET_MIN_DATA((LINTP_FRAME_MAX_LEN - LinTp_SlaveRunCfg[Channel].u8BetyIndex), \
							LinTp_SlaveRunCfg[Channel].SduRemaining);
		/**
		 *  The next data to be copied is equal to 0, indicating completion of continuous frame reception.
		 */
		if(copyLen == 0U)
		{
        	/**
        	 * @req [SWS_LinIf_00078] When the LIN Interface has received the SF or the last CF of a
        	 *      TP message successfully, it shall notify the upper layer by calling the function
        	 *      PduR_LinTpRxIndication with the result E_OK
			 * @req [SWS_LinIf_00414] The LIN Interface shall set the sub-state of a
			 *      channel to LINTP_CHANNEL_IDLE when it has successfully terminated the
			 *      transmission or reception of a LIN TP message
			 * @req [SWS_LinIf_00688] The LIN Interface shall set the sub-state of a
			 *      channel to LINTP_CHANNEL_IDLE when it has detected an unrecoverable
			 *      error on this channel.
        	 */
			LinTp_ResetChannel(&LinTp_SlaveRunCfg[Channel]);
    		Dcm_TpRxIndication(pduId, E_OK);
		}
		else
		{
    		/**
    		 * Check if the upper level buffer is sufficient.
    		 */
			if(LinTp_SlaveRunCfg[Channel].UpperBufRemaining >= copyLen)
			{
    			/**
    			 * Get Ready to receive the next frame of data.
    			 */
				LinTp_SlaveRunCfg[Channel].LinTpRxStatus = LINTP_RX_CF_WAIT_STATUS;
			}
			else
			{
    			/**
    			 * Polling upper layer requests for buffer space.
    			 */
    			/**
    			 * @req [SWS_LinIf_00793]If the function PduR_LinTpCopyRxData returns
    			 *      BUFREQ_OK with a smaller available buffer size than needed for
    			 *      the next CF, the LIN Interface shall call the function
    			 *      PduR_LinTpCopyRxData with a data length (SduLength) 0
    			 *      (zero) again during the next processing of the MainFunction
    			 *      until the available buffer size is big enough or the next CF is
    			 *      received.
    			 */
				LinTp_SlaveRunCfg[Channel].LinTpRxStatus = LINTP_RX_REQUEST_BUFFER_STATUS;
			}
		}
	}
	else if(BUFREQ_E_NOT_OK == bufResult)
	{
		/**
		 * LIN Interface shall abort the reception.
		 * @req [SWS_LinIf_00414] The LIN Interface shall set the sub-state of a
		 *      channel to LINTP_CHANNEL_IDLE when it has successfully terminated the
		 *      transmission or reception of a LIN TP message
		 * @req [SWS_LinIf_00688] The LIN Interface shall set the sub-state of a
		 *      channel to LINTP_CHANNEL_IDLE when it has detected an unrecoverable
		 *      error on this channel.
		 */
		LinTp_ResetChannel(&LinTp_SlaveRunCfg[Channel]);
		
		/**
		 * @req [SWS_LinIf_00677] If the function PduR_LinTpCopyRxData returns BUFREQ_E_NOT_OK,
		 *      the LIN Interface shall abort the reception and notify the upper layer by calling
		 *      the function PduR_LinTpRxIndication with the result E_NOT_OK.
		 *
		 */
		 Dcm_TpRxIndication(pduId, E_NOT_OK);
	}
	else
	{
		/**
		 * In case of other abnormal situations,terminate the receiving reset channel.
		 * @req [SWS_LinIf_00414] The LIN Interface shall set the sub-state of a
		 *      channel to LINTP_CHANNEL_IDLE when it has successfully terminated the
		 *      transmission or reception of a LIN TP message
		 * @req [SWS_LinIf_00688] The LIN Interface shall set the sub-state of a
		 *      channel to LINTP_CHANNEL_IDLE when it has detected an unrecoverable
		 *      error on this channel.
		 */
		LinTp_ResetChannel(&LinTp_SlaveRunCfg[Channel]);
	}
}

/**
 * @brief       LinTp_RxCFBufferRequest - Requests a receive buffer.
 * @details  ...
 * @param[in]   Channel  Run time Channel Index.
 * @return      void
 *
 */
STATIC FUNC(void, LINIF_CODE) LinTp_RxCFBufferRequest
(
	VAR(uint16, AUTOMATIC) Channel
)
{
	VAR(PduIdType,AUTOMATIC) pduId;
	VAR(PduInfoType,AUTOMATIC) infoData ;
	P2VAR(PduInfoType, AUTOMATIC, LINIF_APPL_DATA) info ;
	VAR(BufReq_ReturnType,AUTOMATIC) bufResult = BUFREQ_E_NOT_OK;
	VAR(PduLengthType,AUTOMATIC) copyLen  = 0U;

	info = &infoData ;

    /* Set destination buffer pointer and he number of bytes to be copied */
    info->SduDataPtr = &(LinTp_SlaveRunCfg[Channel].SduRxBuffer[LinTp_SlaveRunCfg[Channel].u8BetyIndex]);
	/**
	 * @req [SWS_LinIf_00793]If the function PduR_LinTpCopyRxData returns
	 *      BUFREQ_OK with a smaller available buffer size than needed for
	 *      the next CF, the LIN Interface shall call the function
	 *      PduR_LinTpCopyRxData with a data length (SduLength) 0
	 *      (zero) again during the next processing of the MainFunction
	 *      until the available buffer size is big enough or the next CF is
	 *      received.
	 */
    info->SduLength = 0U;
	pduId = LinTp_SlaveRunCfg[Channel].LinTpRxNSdu->LinTpRxNSduPduRef;

	/**
	 * @req [SWS_LinIf_00674] After reception of each frame of a TP message (SF, FF and CF),
	 *      the LIN Interface shall call the function PduR_LinTpCopyRxData with a PduInfo
	 *      pointer containing received data (SduDataPtr) and data length (SduLength).
	 *      The data length is 5 bytes (including SID) for FF, up to 6 bytes for SF and 6 bytes
	 *      for CF (or less in case of the last CF).
	 */
	bufResult = Dcm_CopyRxData(
			pduId,
			info,
			&(LinTp_SlaveRunCfg[Channel].UpperBufRemaining));

	if(BUFREQ_OK == bufResult)
	{
		LinTp_SlaveRunCfg[Channel].SduRemaining -= copyLen;
		LinTp_SlaveRunCfg[Channel].u8BetyIndex = LINIF_PDU_CF_DATA_OFFSET;
		/**
		 * Calculate the length of data to be replicated next time.
		 */
		copyLen = LINIF_GET_MIN_DATA((LINTP_FRAME_MAX_LEN - LinTp_SlaveRunCfg[Channel].u8BetyIndex), \
							LinTp_SlaveRunCfg[Channel].SduRemaining);

   		/**
		 * Check if the upper level buffer is sufficient.
		 */
		if(LinTp_SlaveRunCfg[Channel].UpperBufRemaining >= copyLen)
		{
			/**
			 * Get Ready to receive the next frame of data.
			 */
			/**
			 * @req [SWS_LinIf_00794]In case of SWS_LinIf_00793, when the buffer of
			 *      sufficient size is available, the LIN Interface shall copy the
			 *      received data via the function PduR_LinTpCopyRxData.
			 */
			LinTp_SlaveRunCfg[Channel].LinTpRxStatus = LINTP_RX_CF_WAIT_STATUS;
		}
		else
		{
			/**
			 * Polling upper layer requests for buffer space.
			 */
			/**
			 * @req [SWS_LinIf_00793]If the function PduR_LinTpCopyRxData returns
			 *      BUFREQ_OK with a smaller available buffer size than needed for
			 *      the next CF, the LIN Interface shall call the function
			 *      PduR_LinTpCopyRxData with a data length (SduLength) 0
			 *      (zero) again during the next processing of the MainFunction
			 *      until the available buffer size is big enough or the next CF is
			 *      received.
			 */
			LinTp_SlaveRunCfg[Channel].LinTpRxStatus = LINTP_RX_REQUEST_BUFFER_STATUS;
		}

	}
	else if(BUFREQ_E_NOT_OK == bufResult)
	{
		/**
		 * LIN Interface shall abort the reception.
		 * @req [SWS_LinIf_00414] The LIN Interface shall set the sub-state of a
		 *      channel to LINTP_CHANNEL_IDLE when it has successfully terminated the
		 *      transmission or reception of a LIN TP message
		 * @req [SWS_LinIf_00688] The LIN Interface shall set the sub-state of a
		 *      channel to LINTP_CHANNEL_IDLE when it has detected an unrecoverable
		 *      error on this channel.
		 */
		LinTp_ResetChannel(&LinTp_SlaveRunCfg[Channel]);
		
		/**
		 * @req [SWS_LinIf_00677] If the function PduR_LinTpCopyRxData returns BUFREQ_E_NOT_OK,
		 *      the LIN Interface shall abort the reception and notify the upper layer by calling
		 *      the function PduR_LinTpRxIndication with the result E_NOT_OK.
		 */
		Dcm_TpRxIndication(pduId, E_NOT_OK);
	}
	else
	{
		/**
		 * In case of other abnormal situations,terminate the receiving reset channel.
		 * @req [SWS_LinIf_00414] The LIN Interface shall set the sub-state of a
		 *      channel to LINTP_CHANNEL_IDLE when it has successfully terminated the
		 *      transmission or reception of a LIN TP message
		 * @req [SWS_LinIf_00688] The LIN Interface shall set the sub-state of a
		 *      channel to LINTP_CHANNEL_IDLE when it has detected an unrecoverable
		 *      error on this channel.
		 */
		LinTp_ResetChannel(&LinTp_SlaveRunCfg[Channel]);
	}
}
/**
 * @details     The case where MRF is processed by the slave machine and the frame type
 *              is equal to a first frame of a continuous frame.
 * @param[in]
 *              Lin_SduPtr  Pointer to pointer to a shadow buffer or memory mapped LIN
 *                          Hardware receive buffer where the current SDU is stored.
 *                          This pointer is only valid if the response is received.
 *              pRxSdu      Point to the configuration of the associated Rx Sdus.
 *
 * @return      void
 *
 */
STATIC FUNC(void,LINIF_CODE)LinTp_SlaveHandleFF
(
	P2VAR(uint8, AUTOMATIC,LINIF_APPL_DATA) Lin_SduPtr,
	P2CONST(LinTp_RxNSduType, AUTOMATIC, LINIF_APPL_CONST) pRxSdu
)
{
	VAR(PduIdType,AUTOMATIC) pduId;
	VAR(uint8,AUTOMATIC) u8Loop = 0u;
	VAR(uint16,AUTOMATIC) u16Len = 0u;
	VAR(uint16,AUTOMATIC) u16ChIndex = 0u;
	VAR(boolean,AUTOMATIC) bIgnore = (boolean)FALSE;

	P2CONST(LinTp_ChannelConfigType, AUTOMATIC, LINIF_APPL_CONST) pChannel = NULL_PTR;

	pChannel = LinTp_SlaveGetChannel(pRxSdu->LinTpRxNSduChannelRef, &u16ChIndex);

	if(pChannel != NULL_PTR)
	{
		if(LinTp_SlaveRunCfg[u16ChIndex].u8SubChStatus == LINTP_CHANNEL_BUSY)
		{
			if(LinTp_SlaveRunCfg[u16ChIndex].eOngoingRequest == LINTP_PHY_REQUEST_TYPE)
			{
				/**
				 * @req [SWS_LinIf_00807] If a new functional request is received while reception of a
				 *      physical request is ongoing, the LIN Interface shall ignore the functional
				 *      request.
				 *
				 */
				if(Lin_SduPtr[LINIF_PDU_NAD_OFFSET] == LINIF_FUNCTIONAL_NAD)
				{
					bIgnore = (boolean)TRUE;
				}
				else
				{
					/**
					 * @req [SWS_LinIf_00808] If the start of new physical request (SF or FF) is
					 *       received while reception of a physical request is ongoing, the LIN
					 *       Interface shall stop the current LIN TP message reception
					 *       (see also SWS_LinIf_00651). If the received NAD matches the configured
					 *       NAD or broadcast NAD, the new request shall be accepted.
					 *
					 * @req [SWS_LinIf_00651]In case a FF or a SF is received after a CF which is
					 *      not the last CF, the LIN Interface shall stop the current LIN TP message
					 *      reception.
					 * @req [SWS_LinIf_00653] In case a FF or a SF is received after a CF, the LIN
					 *      Interface shall report this failure to PDU Router by calling the function
					 *      PduR_LinTpRxIndication with the result E_NOT_OK.
					 *
					 * @req [SWS_LinIf_00797]If the start of a new physical request (SF or FF) is
					 *      received while transmission of a previously triggered physical request
					 *      is ongoing, the LIN Interface shall abort the ongoing transmission.
					 *      If the NAD matches the configured NAD of the slave node or the broadcast NAD,
					 *      the LIN Interface shall accept the new physical request.
					 * @req [SWS_LinIf_00414] The LIN Interface shall set the sub-state of a
					 *      channel to LINTP_CHANNEL_IDLE when it has successfully terminated the
					 *      transmission or reception of a LIN TP message
					 * @req [SWS_LinIf_00688] The LIN Interface shall set the sub-state of a
					 *      channel to LINTP_CHANNEL_IDLE when it has detected an unrecoverable
					 *      error on this channel.
					 */
					pduId = LinTp_SlaveRunCfg[u16ChIndex].LinTpRxNSdu->LinTpRxNSduPduRef;
					if(LinTp_SlaveRunCfg[u16ChIndex].LinTpRxNSdu != NULL_PTR)
					{
						LinTp_ResetChannel(&LinTp_SlaveRunCfg[u16ChIndex]);
						Dcm_TpRxIndication(pduId,E_NOT_OK);
					}
					else{
						LinTp_ResetChannel(&LinTp_SlaveRunCfg[u16ChIndex]);
					}
				}
			}
		}

		/**
		 * @req [SWS_LinIf_00652] In case an invalid data length is received (a SF with a length of 0
		 *      (zero) or greater than 6, a FF with a length of less than 7), the LIN Interface shall
		 *      ignore the LIN TP message.
		 */
		u16Len = (Lin_SduPtr[LINIF_PDU_PCI_OFFSET] & LINIF_PCI_LN_MASK);
		u16Len = (uint16)((u16Len<<8U) | Lin_SduPtr[LINIF_PDU_LEN_OFFSET]);

		if(u16Len < LINIF_FF_MIN_LENGTH)
		{
			bIgnore = (boolean)TRUE;
		}

		if(bIgnore == (boolean)FALSE)
		{
			LinTp_SlaveRunCfg[u16ChIndex].LinTpChannel = pChannel;
			LinTp_SlaveRunCfg[u16ChIndex].LinTpRxNSdu = pRxSdu;
			LinTp_SlaveRunCfg[u16ChIndex].LinTpRxStatus = LINTP_RX_FF_STATUS;
			LinTp_SlaveRunCfg[u16ChIndex].SduRemaining = u16Len;
			LinTp_SlaveRunCfg[u16ChIndex].u8BetyIndex = LINIF_PDU_FF_SID_OFFSET;
			if(Lin_SduPtr[LINIF_PDU_NAD_OFFSET] == LINIF_FUNCTIONAL_NAD)
			{
				LinTp_SlaveRunCfg[u16ChIndex].eOngoingRequest = LINTP_FUN_REQUEST_TYPE ;
			}
			else
			{
				LinTp_SlaveRunCfg[u16ChIndex].eOngoingRequest = LINTP_PHY_REQUEST_TYPE;
			}
			LinTp_SlaveRunCfg[u16ChIndex].u32SduLength =  u16Len;
			LinTp_SlaveRunCfg[u16ChIndex].u8SequenceNum = 0U;
			LinTp_SlaveRunCfg[u16ChIndex].u8SubChStatus = LINTP_CHANNEL_BUSY;

			for(u8Loop = 0U; u8Loop<LINIF_FRAME_MAX_LEN;u8Loop++)
			{
				LinTp_SlaveRunCfg[u16ChIndex].SduRxBuffer[u8Loop] = Lin_SduPtr[u8Loop];
			}

			/**
			 * @req [SWS_LinIf_00804] The LIN Interface shall provide the N_Cr timeout observation
			 *      (configuration parameter LinTpNcr) in order to abort a running reception in case the
			 *      no further MRF are received.
			 *
			 * @req [SWS_LinIf_00805] The LIN Interface shall start/restart the N_Cr timer after the
			 *      LIN driver indicates the reception of a MRF (FF or CF except last CF) with invocation
			 *      of callback function LinIf_RxIndication and stop after the LIN driver indicates the
			 *      reception of a MRF (last CF) with invocation of callback function LinIf_RxIndication.
			 */
			 LinTp_SlaveRunCfg[u16ChIndex].bNcrTimerSwitch = (boolean)TRUE;
			 if(pRxSdu->LinTpNcrSwitch == (boolean)TRUE)
			 {
				 LinTp_SlaveRunCfg[u16ChIndex].u16NcrTimer = pRxSdu->LinTpNcr;
			 }
			 else
			 {
				 LinTp_SlaveRunCfg[u16ChIndex].u16NcrTimer = LINTP_TIME_OUT_MS;
			 }
		}
	}
}

/**
 * @details     The case where MRF is processed by the slave machine and the frame type
 *              is equal to continuous frame.
 * @param[in]
 *              Lin_SduPtr  Pointer to pointer to a shadow buffer or memory mapped LIN
 *                          Hardware receive buffer where the current SDU is stored.
 *                          This pointer is only valid if the response is received.
 *              pRxSdu      Point to the configuration of the associated Rx Sdus.
 *
 * @return      void
 *
 */
STATIC FUNC(void,LINIF_CODE)LinTp_SlaveHandleCF
(
	P2VAR(uint8, AUTOMATIC,LINIF_APPL_DATA) Lin_SduPtr,
	P2CONST(LinTp_RxNSduType, AUTOMATIC, LINIF_APPL_CONST) pRxSdu
)
{
	VAR(PduIdType,AUTOMATIC) pduId;
	VAR(uint8,AUTOMATIC) u8Loop = 0u;
	VAR(uint8,AUTOMATIC) u8PciLen = 0u;
	VAR(uint16,AUTOMATIC) u16ChIndex = 0u;

	P2CONST(LinTp_ChannelConfigType, AUTOMATIC, LINIF_APPL_CONST) pChannel = NULL_PTR;

	pChannel = LinTp_SlaveGetChannel(pRxSdu->LinTpRxNSduChannelRef, &u16ChIndex);

	if(pChannel != NULL_PTR)
	{
		if(LinTp_SlaveRunCfg[u16ChIndex].u8SubChStatus == LINTP_CHANNEL_BUSY)
		{
			pduId = LinTp_SlaveRunCfg[u16ChIndex].LinTpRxNSdu->LinTpRxNSduPduRef;
			
			if(LinTp_SlaveRunCfg[u16ChIndex].LinTpRxStatus == LINTP_RX_REQUEST_BUFFER_STATUS)
			{
				/**
				 * @req [SWS_LinIf_00795] In case of SWS_LinIf_00793, when the next CF is received
				 *      before the data of the current CF could be copied, the LIN Interface shall
				 *      abort the reception and notify the upper layer by calling the function
				 *      PduR_LinTpRxIndication with the result E_NOT_OK.
				 *
				 * @req [SWS_LinIf_00414] The LIN Interface shall set the sub-state of a
				 *      channel to LINTP_CHANNEL_IDLE when it has successfully terminated the
				 *      transmission or reception of a LIN TP message
				 * @req [SWS_LinIf_00688] The LIN Interface shall set the sub-state of a
				 *      channel to LINTP_CHANNEL_IDLE when it has detected an unrecoverable
				 *      error on this channel.
				 */
				
				if(LinTp_SlaveRunCfg[u16ChIndex].LinTpRxNSdu != NULL_PTR)
				{
					LinTp_ResetChannel(&LinTp_SlaveRunCfg[u16ChIndex]);
					Dcm_TpRxIndication(pduId,E_NOT_OK);
				}else{
					LinTp_ResetChannel(&LinTp_SlaveRunCfg[u16ChIndex]);
				}
				
			}
			else if(LinTp_SlaveRunCfg[u16ChIndex].LinTpRxStatus == LINTP_RX_CF_WAIT_STATUS)
			{
				LinTp_SlaveRunCfg[u16ChIndex].u8SequenceNum ++ ;
				LinTp_SlaveRunCfg[u16ChIndex].u8SequenceNum = \
						(LinTp_SlaveRunCfg[u16ChIndex].u8SequenceNum  % 16U);
				u8PciLen = (Lin_SduPtr[LINIF_PDU_PCI_OFFSET] & LINIF_PCI_LN_MASK);
				/**
				 * @req [SWS_LinIf_00079]In case an incorrect sequence number is received, the LIN
				 *      Interface shall stop the current LIN TP message reception.
				 */
				if(u8PciLen == LinTp_SlaveRunCfg[u16ChIndex].u8SequenceNum)
				{
					for(u8Loop = 0U; u8Loop<LINIF_FRAME_MAX_LEN;u8Loop++)
					{
						LinTp_SlaveRunCfg[u16ChIndex].SduRxBuffer[u8Loop] = Lin_SduPtr[u8Loop];
					}

					LinTp_SlaveRunCfg[u16ChIndex].LinTpRxStatus =  LINTP_RX_CF_STATUS;

					/**
					 * @req [SWS_LinIf_00804] The LIN Interface shall provide the N_Cr timeout observation
					 *      (configuration parameter LinTpNcr) in order to abort a running reception in case the
					 *      no further MRF are received.
					 *
					 * @req [SWS_LinIf_00805] The LIN Interface shall start/restart the N_Cr timer after the
					 *      LIN driver indicates the reception of a MRF (FF or CF except last CF) with invocation
					 *      of callback function LinIf_RxIndication and stop after the LIN driver indicates the
					 *      reception of a MRF (last CF) with invocation of callback function LinIf_RxIndication.
					 */
					 LinTp_SlaveRunCfg[u16ChIndex].bNcrTimerSwitch = (boolean)TRUE;
					 if(pRxSdu->LinTpNcrSwitch == (boolean)TRUE)
					 {
						 LinTp_SlaveRunCfg[u16ChIndex].u16NcrTimer = pRxSdu->LinTpNcr;
					 }
					 else
					 {
						 LinTp_SlaveRunCfg[u16ChIndex].u16NcrTimer = LINTP_TIME_OUT_MS;
					 }
				}
				else
				{
					/**
					 * @req [SWS_LinIf_00081]In case an incorrect sequence number is received,
					 *      the LIN Interface shall report this failure to PDU Router by calling
					 *      the function PduR_LinTpRxIndication with the result E_NOT_OK.
					 *
					 * @req [SWS_LinIf_00079]In case an incorrect sequence number is received,
					 *      the LIN Interface shall stop the current LIN TP message reception
					 *
					 * @req [SWS_LinIf_00414] The LIN Interface shall set the sub-state of a
					 *      channel to LINTP_CHANNEL_IDLE when it has successfully terminated the
					 *      transmission or reception of a LIN TP message
					 * @req [SWS_LinIf_00688] The LIN Interface shall set the sub-state of a
					 *      channel to LINTP_CHANNEL_IDLE when it has detected an unrecoverable
					 *      error on this channel.
					 */

					if(LinTp_SlaveRunCfg[u16ChIndex].LinTpRxNSdu != NULL_PTR)
					{
						LinTp_ResetChannel(&LinTp_SlaveRunCfg[u16ChIndex]);
						Dcm_TpRxIndication(pduId,E_NOT_OK);
					}
					else{
						LinTp_ResetChannel(&LinTp_SlaveRunCfg[u16ChIndex]);
					}
					
				}
			}
			else
			{
				/**
				 * @ref [SWS_LinIf_00696] In case a CF is received instead of a FF or a SF, the LIN
				 *      Interface shall ignore this LIN frame.
				 */
			}
		}
		else
		{
			/**
			 * @ref [SWS_LinIf_00696] In case a CF is received instead of a FF or a SF, the LIN
			 *      Interface shall ignore this LIN frame.
			 */
		}
	}
}

/**
 * @details          Received data transmission frame to the transport layer.
 * @param[in]        Channel   LinIf Channel Index.
 *
 *                   Lin_SduPtr  Pointer to pointer to a shadow buffer or memory mapped LIN
 *                               Hardware receive buffer where the current SDU is stored.
 *                               This pointer is only valid if the response is received.
 *
 * @return           void
 *
 */
STATIC FUNC(void,LINIF_CODE)LinIf_SlaveTransportLayerMrfIndication
(
	VAR(uint16,AUTOMATIC) Channel,
	P2VAR(uint8, AUTOMATIC,LINIF_APPL_DATA) Lin_SduPtr
)
{
	VAR(uint8,AUTOMATIC) u8Pci;
	P2CONST(LinTp_RxNSduType, AUTOMATIC, LINIF_APPL_CONST) pRxSdu = NULL_PTR;

	pRxSdu = LinTp_SlaveGetRxNSdu(Channel,Lin_SduPtr[LINIF_PDU_NAD_OFFSET]);

	if(pRxSdu != NULL_PTR)
	{
		u8Pci = (Lin_SduPtr[LINIF_PDU_PCI_OFFSET] & LINIF_PCI_MASK);
		switch(u8Pci)
		{
			case LINIF_PCI_SF:
				LinTp_SlaveHandleSF(Lin_SduPtr,pRxSdu);
				break;
			case LINIF_PCI_FF:
				LinTp_SlaveHandleFF(Lin_SduPtr,pRxSdu);
				break;
			case LINIF_PCI_CF:
				LinTp_SlaveHandleCF(Lin_SduPtr,pRxSdu);
				break;
			default:
				break;
		}
	}
}

/**
 * @details     The case where MRF is processed by the slave machine and the frame type
 *              is equal to a signal frame.
 * @param[in]
 *              Lin_SduPtr  Pointer to pointer to a shadow buffer or memory mapped LIN
 *                          Hardware receive buffer where the current SDU is stored.
 *                          This pointer is only valid if the response is received.
 *              Channel   LinTp Channel Index.
 *
 * @return      void
 *
 */
STATIC FUNC(void,LINIF_CODE)LinTp_SlaveHandleSrfSF
(
	VAR(uint8,AUTOMATIC) Nad,
	VAR(uint16,AUTOMATIC) Channel,
	P2VAR(Lin_PduType, AUTOMATIC,LINIF_APPL_DATA) Lin_SduPtr
)
{
	VAR(uint8,AUTOMATIC) u8Loop;
	VAR(PduIdType,AUTOMATIC) pduId; 
	VAR(PduInfoType,AUTOMATIC) infoData ;
	P2VAR(PduInfoType, AUTOMATIC, LINIF_APPL_DATA) info ;
	VAR(BufReq_ReturnType,AUTOMATIC) bufResult = BUFREQ_E_NOT_OK;

	info = &infoData ;
    pduId = LinTp_SlaveRunCfg[Channel].LinTpTxNSdu->LinTpTxNSduPduRef;
	/**
	 * @req [SWS_LinIf_00330]If the function PduR_LinTpCopyTxData returns BUFREQ_E_BUSY,
	 *      the LIN Interface shall retry to copy the data via the function
	 *      PduR_LinTpCopyTxData. For a master node, the LIN Interface shall retry to copy the
	 *      data during the next processing of the MainFunction until the transmit data is
	 *      provided. For a slave node, the LIN Interface shall retry to copy the data after
	 *      reception of a SRF header until the transmit data is provided. For the number of
	 *      retries, refer to the configuration parameter LinTpMaxBufReq.
	 */
	if((LinTp_SlaveRunCfg[Channel].SduRemaining == 0U) ||
	   (LinTp_SlaveRunCfg[Channel].SduRemaining > LINIF_SF_MAX_LENGTH))
	{
		/* SduRemaining==0 previously built PCI 0x00 → 00 FF FF FF...; ignore instead. */
		Lin_SduPtr->Drc = LIN_FRAMERESPONSE_IGNORE;
		return;
	}
	if(LinTp_SlaveRunCfg[Channel].u8CopyCnt <= LinTp_SlaveRunCfg[Channel].LinTpTxNSdu->LinTpMaxBufReq)
	{
		for(u8Loop=0U;u8Loop<8U;u8Loop++)
		{
			LinTp_SlaveRunCfg[Channel].SduTxBuffer[u8Loop] = 0xFFU;
		}

		/**
		 * @req [SWS_LinIf_00671]After a transmission request from the upper layer, the
		 *      LIN Interface shall call the function PduR_LinTpCopyTxData with the PduInfo pointer
		 *      containing data buffer (SduDataPtr) and data length (SduLength) for each segment
		 *      that is sent. The data length is 5 bytes (including SID) for FF, up to 6 bytes for SF
		 *      and 6 bytes for CF (or less in case of the last CF).
		 *
		 * @req [SWS_LinIf_00705] When calling PduR_LinTpCopyTxData, the LIN Interface shall
		 *      always set the parameter retry to NULL.
		 */
		infoData.SduDataPtr = &(LinTp_SlaveRunCfg[Channel].SduTxBuffer[LINIF_PDU_SF_RSID_OFFSET]);
		infoData.SduLength = LinTp_SlaveRunCfg[Channel].SduRemaining;

		bufResult = Dcm_CopyTxData(
	    		pduId,
				info,
				NULL_PTR,
				&(LinTp_SlaveRunCfg[Channel].UpperBufRemaining));

		if(bufResult == BUFREQ_OK)
		{
			/**
			 * @req [SWS_LinIf_00672]When the function PduR_LinTpCopyTxData
			 *      returns BUFREQ_OK, a LIN master node shall resume the
			 *      transmission of the MRF and a LIN slave node shall resume
			 *      the response transmission to SRF header.
			 */
			LinTp_SlaveRunCfg[Channel].u8CopyCnt = 0U;
			/**
			 * Assemble Tp Message.
			 */
			LinTp_SlaveRunCfg[Channel].SduTxBuffer[LINIF_PDU_NAD_OFFSET] =  Nad;
			LinTp_SlaveRunCfg[Channel].SduTxBuffer[LINIF_PDU_PCI_OFFSET] =  (uint8)(LINIF_PCI_SF | (info->SduLength));

			/* Drop bogus SF 74 03 00 00 00 (empty payload after RCRRP). */
			if((info->SduLength == 3U) &&
			   (LinTp_SlaveRunCfg[Channel].SduTxBuffer[LINIF_PDU_SF_RSID_OFFSET] == 0U) &&
			   (LinTp_SlaveRunCfg[Channel].SduTxBuffer[LINIF_PDU_SF_RSID_OFFSET + 1U] == 0U) &&
			   (LinTp_SlaveRunCfg[Channel].SduTxBuffer[LINIF_PDU_SF_RSID_OFFSET + 2U] == 0U))
			{
				LinTp_ResetChannel(&LinTp_SlaveRunCfg[Channel]);
				Dcm_TpTxConfirmation(pduId, E_NOT_OK);
				Lin_SduPtr->Drc = LIN_FRAMERESPONSE_IGNORE;
				return;
			}

			/*
			 * Functional-request suppress (IGNORE + immediate TxConfirmation) must NOT
			 * apply to DCM-triggered responses. Always put the SF on the SRF.
			 */
			{
				for(u8Loop=0U;u8Loop<8U;u8Loop++)
				{
					Lin_SduPtr->SduPtr[u8Loop] = LinTp_SlaveRunCfg[Channel].SduTxBuffer[u8Loop];
				}
				/**
				 * @req [SWS_LinIf_00068]When the LIN Interface has transmitted a SF or the
				 *      last CF as MRF (LIN master) or SRF response (LIN slave) successfully,
				 *      it shall notify the upper layer by calling the function
				 *      PduR_LinTpTxConfirmation with the result E_OK.
				 */
				LinTp_SlaveRunCfg[Channel].LinTpTxStatus = LINTP_TX_CONFIRMATION_STATUS;
			}
		}
		else if(bufResult == BUFREQ_E_NOT_OK)
		{
			/**
			 * @req [SWS_LinIf_00073]If the function PduR_LinTpCopyTxData reports
			 *      BUFREQ_E_NOT_OK, the LIN Interface shall abort the transmission and notify the
			 *      upper layer by calling the function PduR_LinTpTxConfirmation with the result
			 *      E_NOT_OK.
			 * @req [SWS_LinIf_00414] The LIN Interface shall set the sub-state of a
			 *      channel to LINTP_CHANNEL_IDLE when it has successfully terminated the
			 *      transmission or reception of a LIN TP message
			 * @req [SWS_LinIf_00688] The LIN Interface shall set the sub-state of a
			 *      channel to LINTP_CHANNEL_IDLE when it has detected an unrecoverable
			 *      error on this channel.
			 */
			LinTp_ResetChannel(&LinTp_SlaveRunCfg[Channel]);
	        Dcm_TpTxConfirmation(pduId, E_NOT_OK);
	        Lin_SduPtr->Drc = LIN_FRAMERESPONSE_IGNORE;
		}
		else if(bufResult == BUFREQ_E_BUSY)
		{
			/**
			 * @req [SWS_LinIf_00329] If the function PduR_LinTpCopyTxData returns
			 *      BUFREQ_E_BUSY, a LIN master node shall not send the next MRF
			 *      and a LIN slave node shall not send a response to the next SRF header
			 * @req [SWS_LinIf_00330] If the function PduR_LinTpCopyTxData returns
			 *      BUFREQ_E_BUSY, the LIN Interface shall retry to copy the data via
			 *      the function PduR_LinTpCopyTxData. For a master node, the LIN
			 *      Interface shall retry to copy the data during the next processing
			 *      of the MainFunction until the transmit data is provided. For a
			 *      slave node, the LIN Interface shall retry to copy the data after
			 *      reception of a SRF header until the transmit data is provided.
			 *      For the number of retries, refer to the configuration parameter
			 *      LinTpMaxBufReq.
			 */
			LinTp_SlaveRunCfg[Channel].u8CopyCnt +=1U;
			Lin_SduPtr->Drc = LIN_FRAMERESPONSE_IGNORE;
		}
		else
		{
			/* do nothing.. */
		}
	}
	else
	{
		/**
		 * @req [SWS_LinIf_00414] The LIN Interface shall set the sub-state of a
		 *      channel to LINTP_CHANNEL_IDLE when it has successfully terminated the
		 *      transmission or reception of a LIN TP message
		 * @req [SWS_LinIf_00688] The LIN Interface shall set the sub-state of a
		 *      channel to LINTP_CHANNEL_IDLE when it has detected an unrecoverable
		 *      error on this channel.
		 */
		LinTp_ResetChannel(&LinTp_SlaveRunCfg[Channel]);
        Dcm_TpTxConfirmation(pduId, E_NOT_OK);
        Lin_SduPtr->Drc = LIN_FRAMERESPONSE_IGNORE;
	}
}

/**
 * @details     The case where SRF is processed by the slave machine and the frame type
 *              is equal to a first frame of a continuous frame.
 * @param[in]
 *              Lin_SduPtr  Pointer to pointer to a shadow buffer or memory mapped LIN
 *                          Hardware receive buffer where the current SDU is stored.
 *                          This pointer is only valid if the response is received.
 *              Channel   LinTp Channel Index.
 *
 * @return      void
 *
 */
STATIC FUNC(void,LINIF_CODE)LinTp_SlaveHandleSrfFF
(
	VAR(uint8,AUTOMATIC) Nad,
	VAR(uint16,AUTOMATIC) Channel,
	P2VAR(Lin_PduType, AUTOMATIC,LINIF_APPL_DATA) Lin_SduPtr
)
{
	VAR(uint8,AUTOMATIC) u8Loop;
	VAR(PduIdType,AUTOMATIC) pduId; 
	VAR(PduInfoType,AUTOMATIC) infoData ;
	P2VAR(PduInfoType, AUTOMATIC, LINIF_APPL_DATA) info ;
	VAR(BufReq_ReturnType,AUTOMATIC) bufResult = BUFREQ_E_NOT_OK;

	info = &infoData ;
	pduId = LinTp_SlaveRunCfg[Channel].LinTpTxNSdu->LinTpTxNSduPduRef;

	/**
	 * @req [SWS_LinIf_00330]If the function PduR_LinTpCopyTxData returns BUFREQ_E_BUSY,
	 *      the LIN Interface shall retry to copy the data via the function
	 *      PduR_LinTpCopyTxData. For a master node, the LIN Interface shall retry to copy the
	 *      data during the next processing of the MainFunction until the transmit data is
	 *      provided. For a slave node, the LIN Interface shall retry to copy the data after
	 *      reception of a SRF header until the transmit data is provided. For the number of
	 *      retries, refer to the configuration parameter LinTpMaxBufReq.
	 */
	if(LinTp_SlaveRunCfg[Channel].u8CopyCnt <= LinTp_SlaveRunCfg[Channel].LinTpTxNSdu->LinTpMaxBufReq)
	{
		for(u8Loop=0U;u8Loop<8U;u8Loop++)
		{
			LinTp_SlaveRunCfg[Channel].SduTxBuffer[u8Loop] = 0xFFU;
		}

		/**
		 * @req [SWS_LinIf_00671]After a transmission request from the upper layer, the
		 *      LIN Interface shall call the function PduR_LinTpCopyTxData with the PduInfo pointer
		 *      containing data buffer (SduDataPtr) and data length (SduLength) for each segment
		 *      that is sent. The data length is 5 bytes (including SID) for FF, up to 6 bytes for SF
		 *      and 6 bytes for CF (or less in case of the last CF).
		 *
		 * @req [SWS_LinIf_00705] When calling PduR_LinTpCopyTxData, the LIN Interface shall
		 *      always set the parameter retry to NULL.
		 */
		infoData.SduDataPtr = &(LinTp_SlaveRunCfg[Channel].SduTxBuffer[LINIF_PDU_FF_DATA_OFFSET]);
		infoData.SduLength = LINIF_FF_DATA_LENGTH;

		bufResult = Dcm_CopyTxData(
	    		pduId,
				info,
				NULL_PTR,
				&(LinTp_SlaveRunCfg[Channel].UpperBufRemaining));

		if(bufResult == BUFREQ_OK)
		{
			/**
			 * The number of attempts to copy this frame of data to the upper layer.
			 * @req [SWS_LinIf_00672]When the function PduR_LinTpCopyTxData
			 *      returns BUFREQ_OK, a LIN master node shall resume the
			 *      transmission of the MRF and a LIN slave node shall resume
			 *      the response transmission to SRF header.
			 */
			LinTp_SlaveRunCfg[Channel].u8CopyCnt = 0U;
			/**
			 * Assemble Tp Message.
			 */
			LinTp_SlaveRunCfg[Channel].SduTxBuffer[LINIF_PDU_NAD_OFFSET] =  Nad;
			LinTp_SlaveRunCfg[Channel].SduTxBuffer[LINIF_PDU_PCI_OFFSET] =  \
					(uint8)(LINIF_PCI_FF | (uint8)(LinTp_SlaveRunCfg[Channel].SduRemaining>>8U));
			LinTp_SlaveRunCfg[Channel].SduTxBuffer[LINIF_PDU_LEN_OFFSET] = \
					(uint8)(LinTp_SlaveRunCfg[Channel].SduRemaining & 0xFFU);
			LinTp_SlaveRunCfg[Channel].SduRemaining -=info->SduLength;
			LinTp_SlaveRunCfg[Channel].LinTpTxStatus = LINTP_TX_CF_STATUS;
			LinTp_SlaveRunCfg[Channel].u8BetyIndex = LINIF_PDU_CF_DATA_OFFSET;
			LinTp_SlaveRunCfg[Channel].u8SequenceNum = 0U;
			for(u8Loop=0U;u8Loop<8U;u8Loop++)
			{
				Lin_SduPtr->SduPtr[u8Loop] = LinTp_SlaveRunCfg[Channel].SduTxBuffer[u8Loop];
			}
		}
		else if(bufResult == BUFREQ_E_NOT_OK)
		{
			/**
			 * @req [SWS_LinIf_00073]If the function PduR_LinTpCopyTxData reports
			 *      BUFREQ_E_NOT_OK, the LIN Interface shall abort the transmission and notify the
			 *      upper layer by calling the function PduR_LinTpTxConfirmation with the result
			 *      E_NOT_OK.
			 * @req [SWS_LinIf_00414] The LIN Interface shall set the sub-state of a
			 *      channel to LINTP_CHANNEL_IDLE when it has successfully terminated the
			 *      transmission or reception of a LIN TP message
			 * @req [SWS_LinIf_00688] The LIN Interface shall set the sub-state of a
			 *      channel to LINTP_CHANNEL_IDLE when it has detected an unrecoverable
			 *      error on this channel.
			 */
			LinTp_ResetChannel(&LinTp_SlaveRunCfg[Channel]);
	        Dcm_TpTxConfirmation(pduId, E_NOT_OK);
	        Lin_SduPtr->Drc = LIN_FRAMERESPONSE_IGNORE;
		}
		else if(bufResult == BUFREQ_E_BUSY)
		{
			/**
			 * @req [SWS_LinIf_00329] If the function PduR_LinTpCopyTxData returns
			 *      BUFREQ_E_BUSY, a LIN master node shall not send the next MRF
			 *      and a LIN slave node shall not send a response to the next SRF header
			 * @req [SWS_LinIf_00330] If the function PduR_LinTpCopyTxData returns
			 *      BUFREQ_E_BUSY, the LIN Interface shall retry to copy the data via
			 *      the function PduR_LinTpCopyTxData. For a master node, the LIN
			 *      Interface shall retry to copy the data during the next processing
			 *      of the MainFunction until the transmit data is provided. For a
			 *      slave node, the LIN Interface shall retry to copy the data after
			 *      reception of a SRF header until the transmit data is provided.
			 *      For the number of retries, refer to the configuration parameter
			 *      LinTpMaxBufReq.
			 */
			LinTp_SlaveRunCfg[Channel].u8CopyCnt +=1U;
			Lin_SduPtr->Drc = LIN_FRAMERESPONSE_IGNORE;
		}
		else
		{
			/* do nothing.. */
		}
	}
	else
	{
		/**
		 * @req [SWS_LinIf_00414] The LIN Interface shall set the sub-state of a
		 *      channel to LINTP_CHANNEL_IDLE when it has successfully terminated the
		 *      transmission or reception of a LIN TP message
		 * @req [SWS_LinIf_00688] The LIN Interface shall set the sub-state of a
		 *      channel to LINTP_CHANNEL_IDLE when it has detected an unrecoverable
		 *      error on this channel.
		 */
		LinTp_ResetChannel(&LinTp_SlaveRunCfg[Channel]);
        Dcm_TpTxConfirmation(pduId, E_NOT_OK);
        Lin_SduPtr->Drc = LIN_FRAMERESPONSE_IGNORE;
	}
}

/**
 * @details     The case where SRF is processed by the slave machine and the frame type
 *              is equal to continuous frame.
 * @param[in]
 *              Lin_SduPtr  Pointer to pointer to a shadow buffer or memory mapped LIN
 *                          Hardware receive buffer where the current SDU is stored.
 *                          This pointer is only valid if the response is received.
 *              Channel   LinTp Channel Index.
 *
 * @return      void
 *
 */
STATIC FUNC(void,LINIF_CODE)LinTp_SlaveHandleSrfCF
(
	VAR(uint8,AUTOMATIC) Nad,
	VAR(uint16,AUTOMATIC) Channel,
	P2VAR(Lin_PduType, AUTOMATIC,LINIF_APPL_DATA) Lin_SduPtr
)
{
	VAR(uint8,AUTOMATIC) u8Loop;
	VAR(PduIdType,AUTOMATIC) pduId; 
	VAR(PduInfoType,AUTOMATIC) infoData ;
	VAR(PduLengthType,AUTOMATIC) copyLen ;
	P2VAR(PduInfoType, AUTOMATIC, LINIF_APPL_DATA) info ;
	VAR(BufReq_ReturnType,AUTOMATIC) bufResult = BUFREQ_E_NOT_OK;

	info = &infoData ;

	if(LinTp_SlaveRunCfg[Channel].u8CopyCnt == 0U)
	{
		/**
		 * @req [SWS_LinIf_00800] The LIN Interface shall start the N_As timer for a SF or FF
		 *      after invocation of the function LinTp_Transmit with return value E_OK and for a CF
		 *      after the LIN driver indicates the reception of a SRF header with invocation of
		 *      callback function LinIf_HeaderIndication and shall stop the N_As timer after the LIN
		 *      driver confirms the response transmission for a SRF header with invocation of
		 *      callback function LinIf_TxConfirmation
		 */
		LinTp_SlaveRunCfg[Channel].bNasTimerSwitch = (boolean)TRUE;
		LinTp_SlaveRunCfg[Channel].u16NasTimer = LinTp_SlaveRunCfg[Channel].LinTpTxNSdu->LinTpNas;
	}
	/**
	 * @req [SWS_LinIf_00803]The LIN Interface shall start the N_Cs timer after the LIN
	 *      driver confirms the response transmission for a SRF header with invocation of
	 *      callback function LinIf_TxConfirmation and stop after the LIN driver indicates the
	 *      reception of a SRF header with invocation of callback function LinIf_HeaderIndication.
	 */
	LinTp_SlaveRunCfg[Channel].bNcsTimerSwitch = (boolean)FALSE;
	LinTp_SlaveRunCfg[Channel].u16NcsTimer = 0U;
	pduId = LinTp_SlaveRunCfg[Channel].LinTpTxNSdu->LinTpTxNSduPduRef;

	/**
	 * @req [SWS_LinIf_00330]If the function PduR_LinTpCopyTxData returns BUFREQ_E_BUSY,
	 *      the LIN Interface shall retry to copy the data via the function
	 *      PduR_LinTpCopyTxData. For a master node, the LIN Interface shall retry to copy the
	 *      data during the next processing of the MainFunction until the transmit data is
	 *      provided. For a slave node, the LIN Interface shall retry to copy the data after
	 *      reception of a SRF header until the transmit data is provided. For the number of
	 *      retries, refer to the configuration parameter LinTpMaxBufReq.
	 */
	if(LinTp_SlaveRunCfg[Channel].u8CopyCnt <= LinTp_SlaveRunCfg[Channel].LinTpTxNSdu->LinTpMaxBufReq)
	{
		for(u8Loop=0U;u8Loop<8U;u8Loop++)
		{
			LinTp_SlaveRunCfg[Channel].SduTxBuffer[u8Loop] = 0xFFU;
		}

		/**
		 * @req [SWS_LinIf_00671]After a transmission request from the upper layer, the
		 *      LIN Interface shall call the function PduR_LinTpCopyTxData with the PduInfo pointer
		 *      containing data buffer (SduDataPtr) and data length (SduLength) for each segment
		 *      that is sent. The data length is 5 bytes (including SID) for FF, up to 6 bytes for SF
		 *      and 6 bytes for CF (or less in case of the last CF).
		 *
		 * @req [SWS_LinIf_00705] When calling PduR_LinTpCopyTxData, the LIN Interface shall
		 *      always set the parameter retry to NULL.
		 */
		/* Get a copy of the effective length */
		copyLen = LINIF_GET_MIN_DATA((LINTP_FRAME_MAX_LEN - LinTp_SlaveRunCfg[Channel].u8BetyIndex), \
						LinTp_SlaveRunCfg[Channel].SduRemaining);
		infoData.SduDataPtr = &(LinTp_SlaveRunCfg[Channel].SduTxBuffer[LINIF_PDU_CF_DATA_OFFSET]);
		infoData.SduLength = copyLen;

		bufResult = Dcm_CopyTxData(
	    		pduId,
				info,
				NULL_PTR,
				&(LinTp_SlaveRunCfg[Channel].UpperBufRemaining));

		if(bufResult == BUFREQ_OK)
		{
			/**
			 * @req [SWS_LinIf_00672]When the function PduR_LinTpCopyTxData
			 *      returns BUFREQ_OK, a LIN master node shall resume the
			 *      transmission of the MRF and a LIN slave node shall resume
			 *      the response transmission to SRF header.
			 */
			LinTp_SlaveRunCfg[Channel].u8CopyCnt = 0U;
			/**
			 * Assemble Tp Message.
			 */
			LinTp_SlaveRunCfg[Channel].u8SequenceNum += 1U;
			LinTp_SlaveRunCfg[Channel].u8SequenceNum = (LinTp_SlaveRunCfg[Channel].u8SequenceNum % 16U);
			LinTp_SlaveRunCfg[Channel].SduTxBuffer[LINIF_PDU_NAD_OFFSET] =  Nad;
			LinTp_SlaveRunCfg[Channel].SduTxBuffer[LINIF_PDU_PCI_OFFSET] =  \
					(uint8)(LINIF_PCI_CF | (uint8)(LinTp_SlaveRunCfg[Channel].u8SequenceNum));
			LinTp_SlaveRunCfg[Channel].SduRemaining -=info->SduLength;

			/**
			 * Copy data from this layer buffer to the bottom layer buffer.
			 */
			for(u8Loop=0U;u8Loop<8U;u8Loop++)
			{
				Lin_SduPtr->SduPtr[u8Loop] = LinTp_SlaveRunCfg[Channel].SduTxBuffer[u8Loop];
			}

			/**
			 * Upper layer data transmission completed,waiting for lower layer to send confirmation.
			 */
			if(LinTp_SlaveRunCfg[Channel].SduRemaining == 0U)
			{
				/**
				 * @req [SWS_LinIf_00068]When the LIN Interface has transmitted a SF or the
				 *      last CF as MRF (LIN master) or SRF response (LIN slave) successfully,
				 *      it shall notify the upper layer by calling the function
				 *      PduR_LinTpTxConfirmation with the result E_OK.
				 */
				LinTp_SlaveRunCfg[Channel].LinTpTxStatus = LINTP_TX_CONFIRMATION_STATUS;
			}
			else
			{
				/**
				 * Waiting for the transmission of the next frame of data.
				 */
				LinTp_SlaveRunCfg[Channel].LinTpTxStatus = LINTP_TX_CF_STATUS;
				LinTp_SlaveRunCfg[Channel].u8BetyIndex = LINIF_PDU_CF_DATA_OFFSET;
			}
		}
		else if(bufResult == BUFREQ_E_NOT_OK)
		{
			/**
			 * @req [SWS_LinIf_00073]If the function PduR_LinTpCopyTxData reports
			 *      BUFREQ_E_NOT_OK, the LIN Interface shall abort the transmission and notify the
			 *      upper layer by calling the function PduR_LinTpTxConfirmation with the result
			 *      E_NOT_OK.
			 * @req [SWS_LinIf_00414] The LIN Interface shall set the sub-state of a
			 *      channel to LINTP_CHANNEL_IDLE when it has successfully terminated the
			 *      transmission or reception of a LIN TP message
			 * @req [SWS_LinIf_00688] The LIN Interface shall set the sub-state of a
			 *      channel to LINTP_CHANNEL_IDLE when it has detected an unrecoverable
			 *      error on this channel.
			 */
			LinTp_ResetChannel(&LinTp_SlaveRunCfg[Channel]);
	        Dcm_TpTxConfirmation(pduId, E_NOT_OK);   
	        Lin_SduPtr->Drc = LIN_FRAMERESPONSE_IGNORE;
		}
		else if(bufResult == BUFREQ_E_BUSY)
		{
			/**
			 * @req [SWS_LinIf_00329] If the function PduR_LinTpCopyTxData returns
			 *      BUFREQ_E_BUSY, a LIN master node shall not send the next MRF
			 *      and a LIN slave node shall not send a response to the next SRF header
			 * @req [SWS_LinIf_00330] If the function PduR_LinTpCopyTxData returns
			 *      BUFREQ_E_BUSY, the LIN Interface shall retry to copy the data via
			 *      the function PduR_LinTpCopyTxData. For a master node, the LIN
			 *      Interface shall retry to copy the data during the next processing
			 *      of the MainFunction until the transmit data is provided. For a
			 *      slave node, the LIN Interface shall retry to copy the data after
			 *      reception of a SRF header until the transmit data is provided.
			 *      For the number of retries, refer to the configuration parameter
			 *      LinTpMaxBufReq.
			 */
			LinTp_SlaveRunCfg[Channel].u8CopyCnt +=1U;
			Lin_SduPtr->Drc = LIN_FRAMERESPONSE_IGNORE;
		}
		else
		{
			/* do nothing.. */
		}
	}
	else
	{
		/**
		 * @req [SWS_LinIf_00414] The LIN Interface shall set the sub-state of a
		 *      channel to LINTP_CHANNEL_IDLE when it has successfully terminated the
		 *      transmission or reception of a LIN TP message
		 * @req [SWS_LinIf_00688] The LIN Interface shall set the sub-state of a
		 *      channel to LINTP_CHANNEL_IDLE when it has detected an unrecoverable
		 *      error on this channel.
		 */
		LinTp_ResetChannel(&LinTp_SlaveRunCfg[Channel]);
        Dcm_TpTxConfirmation(pduId, E_NOT_OK);
        Lin_SduPtr->Drc = LIN_FRAMERESPONSE_IGNORE;
	}
}

/**
 * @details          Received data transmission frame to the transport layer.
 * @param[in]        Channel   LinIf Channel Index.
 *
 *                   Lin_SduPtr  Pointer to pointer to a shadow buffer or memory mapped LIN
 *                               Hardware receive buffer where the current SDU is stored.
 *                               This pointer is only valid if the response is received.
 *
 * @return           void
 *
 */
STATIC FUNC(void,LINIF_CODE)LinIf_SlaveTransportLayerSrfIndication
(
	VAR(uint16,AUTOMATIC) Channel,
	P2VAR(Lin_PduType, AUTOMATIC,LINIF_APPL_DATA) Lin_SduPtr
)
{
	VAR(uint8,AUTOMATIC) Nad;
	VAR(uint16,AUTOMATIC) u16ChIndex;
	VAR(NetworkHandleType,AUTOMATIC) netWork;
	P2CONST(LinTp_ChannelConfigType, AUTOMATIC, LINIF_APPL_CONST) pTpChannel = NULL_PTR;
	netWork = LinIf_ConfigPtr->LinIfSlaveChannel[Channel].LinIfComMNetworkHandleIdRef;

	pTpChannel = LinTp_SlaveGetChannel(netWork,&u16ChIndex);

	if(pTpChannel != NULL_PTR)
	{
		if(LinTp_SlaveRunCfg[u16ChIndex].LinTpTxNSdu != NULL_PTR)
		{
			Nad = LinIf_SlaveConfiguredNAD[u16ChIndex];
			switch(LinTp_SlaveRunCfg[u16ChIndex].LinTpTxStatus)
			{
				case LINTP_TX_SF_STATUS:
					LinTp_SlaveHandleSrfSF(Nad,u16ChIndex,Lin_SduPtr);
					break;
				case LINTP_TX_FF_STATUS:
					LinTp_SlaveHandleSrfFF(Nad,u16ChIndex,Lin_SduPtr);
					break;
				case LINTP_TX_CF_STATUS:
					LinTp_SlaveHandleSrfCF(Nad,u16ChIndex,Lin_SduPtr);
					break;
				default:
					Lin_SduPtr->Drc = LIN_FRAMERESPONSE_IGNORE;
					break;
			}
		}
		else
		{
			Lin_SduPtr->Drc = LIN_FRAMERESPONSE_IGNORE;
		}
	}
	else
	{
		Lin_SduPtr->Drc = LIN_FRAMERESPONSE_IGNORE;
	}
}

/**
 * @brief            Requests transmission of a PDU.
 * @details          The function LinTp_Transmit shall prepare a LIN TP message for transmission.
 * @param[in]        PduInfoPtr Length of and pointer to the PDU data and pointer to MetaData.
 * @param[in]        Channel    Tx Pdu Index
 * @return           Std_ReturnType
 *                   E_OK: The request can be started successfully.
 *                   E_NOT_OK: The request can not be started.
 */
STATIC FUNC(Std_ReturnType,LINIF_CODE) LinTp_Call_Transmit
(
    VAR(uint16,AUTOMATIC) Channel,
    P2CONST(PduInfoType,AUTOMATIC,LINIF_APPL_CONST) PduInfoPtr
)
{
	VAR(uint8,AUTOMATIC) u8Nad;
	VAR(boolean,AUTOMATIC) bIgnore = (boolean)FALSE;
	VAR(uint16,AUTOMATIC) u16ChIndex = 0u;
	VAR(uint16,AUTOMATIC) u16IfChIndex = 0u;
	VAR(NetworkHandleType,AUTOMATIC) netWork;
	VAR(Std_ReturnType,AUTOMATIC) retStatus  = (Std_ReturnType)E_NOT_OK ;
	P2CONST(LinTp_ChannelConfigType, AUTOMATIC, LINIF_APPL_CONST) pChannel = NULL_PTR;

	netWork = LinTp_ConfigPtr->LinTpTxNSdu[Channel].LinTpTxNSduChannelRef;

	pChannel = LinTp_SlaveGetChannel(netWork,&u16ChIndex);

	if(pChannel != NULL_PTR)
	{
		
		u16IfChIndex = LinIf_SlaveGetConfigChannelIdex(pChannel->LinTpChannelRef);
		if(u16IfChIndex != 0xFFU)
		{
			u8Nad = LinIf_SlaveConfiguredNAD[u16IfChIndex];
		}
		else
		{
			u8Nad = 0xFFU;
		}
		
		/**
		 * @req [SWS_LinIf_00616]If the transmission for a further physical request is
		 *      triggered while transmission of a previously triggered physical request is
		 *      ongoing, the LIN Interface shall accept the new physical request and drop
		 *      the old physical request.
		 *
		 * @req [SWS_LinIf_00702] When LinTp_Transmit was successful (returned E_OK),
		 *      the LIN Interface shall ensure that PduR_LinTpTxConfirmation is always
		 *      called, with a negative or positive result. When LinTp_Transmit was
		 *      not successful, PduR_LinTpTxConfirmation shall not be called.
		 */
		if(LinTp_SlaveRunCfg[u16ChIndex].u8SubChStatus == LINTP_CHANNEL_BUSY)
		{
			if((LinTp_ConfigPtr->LinTpTxNSdu[Channel].LinTpTxNSduNad == LINIF_FUNCTIONAL_NAD) && \
					(LinTp_SlaveRunCfg[u16ChIndex].eOngoingRequest == LINTP_PHY_REQUEST_TYPE))
			{
				/**
				 * @req [SWS_LinIf_00798]If a functional request is received while transmission
				 *      of a previously triggered physical request is ongoing, the
				 *      LIN Interface shall ignore the functional request.
				 */
				bIgnore = (boolean)TRUE;
			}
			else
			{
				/**
				 * @req [SWS_LinIf_00797]If the start of a new physical request (SF or FF)
				 *      is received while transmission of a previously triggered physical
				 *      request is ongoing, the LIN Interface shall abort the ongoing
				 *      transmission. If the NAD matches the configured NAD of the slave
				 *      node or the broadcast NAD, the LIN Interface shall accept the new
				 *      physical request.
				 */
				if((LinTp_SlaveRunCfg[u16ChIndex].eOngoingRequest == LINTP_PHY_REQUEST_TYPE) && \
						(LinTp_ConfigPtr->LinTpTxNSdu[Channel].LinTpTxNSduNad != LINIF_FUNCTIONAL_NAD))
				{
					if(LinTp_SlaveRunCfg[u16ChIndex].LinTpTxNSdu != NULL_PTR)
					{
						Dcm_TpTxConfirmation(\
								LinTp_SlaveRunCfg[u16ChIndex].LinTpTxNSdu->LinTpTxNSduPduRef,\
								E_NOT_OK);
					}
					/**
					 * @req [SWS_LinIf_00414] The LIN Interface shall set the sub-state of a
					 *      channel to LINTP_CHANNEL_IDLE when it has successfully terminated the
					 *      transmission or reception of a LIN TP message
					 * @req [SWS_LinIf_00688] The LIN Interface shall set the sub-state of a
					 *      channel to LINTP_CHANNEL_IDLE when it has detected an unrecoverable
					 *      error on this channel.
					 */
					LinTp_ResetChannel(&LinTp_SlaveRunCfg[u16ChIndex]);
				}
			}
		}

		if(bIgnore != (boolean)TRUE)
		{
			/**
			 * @req [SWS_LinIf_00321] The LIN Interface shall start only a transmission of a TP
			 *      message if the channel is in the sub-state LINTP_CHANNEL_IDLE.
			 *
			 * @req [SWS_LinIf_00797]If the start of a new physical request (SF or FF)
			 *      is received while transmission of a previously triggered physical
			 *      request is ongoing, the LIN Interface shall abort the ongoing
			 *      transmission. If the NAD matches the configured NAD of the slave
			 *      node or the broadcast NAD, the LIN Interface shall accept the new
			 *      physical request.
			 */
			if((LinTp_SlaveRunCfg[u16ChIndex].u8SubChStatus == LINTP_CHANNEL_IDLE) && \
				((LinTp_ConfigPtr->LinTpTxNSdu[Channel].LinTpTxNSduNad == LINIF_FUNCTIONAL_NAD) || \
				 (LinTp_ConfigPtr->LinTpTxNSdu[Channel].LinTpTxNSduNad == u8Nad)))
			{
				LinTp_SlaveRunCfg[u16ChIndex].LinTpTxNSdu = &(LinTp_ConfigPtr->LinTpTxNSdu[Channel]);
				LinTp_SlaveRunCfg[u16ChIndex].LinTpChannel = pChannel;
				LinTp_SlaveRunCfg[u16ChIndex].SduRemaining = PduInfoPtr->SduLength;
				/**
				 * DCM called LinTp_Transmit — this response must go out on SRF.
				 * Do not keep a stale LINTP_FUN_REQUEST_TYPE from a prior 0x7E frame
				 * (that path does IGNORE + fake TxConfirmation, so 78/positive never
				 * leave the node and the tester may see length-3 garbage / 00 00 00).
				 */
				LinTp_SlaveRunCfg[u16ChIndex].eOngoingRequest = LINTP_PHY_REQUEST_TYPE;
				/**
				 * Determine the type of frame to be sent for the first time based on
				 * the length of the data to be transmitted.
				 */
				if(PduInfoPtr->SduLength <= LINIF_SF_MAX_LENGTH)
				{
					LinTp_SlaveRunCfg[u16ChIndex].LinTpTxStatus = LINTP_TX_SF_STATUS;
				}
				else
				{
					LinTp_SlaveRunCfg[u16ChIndex].LinTpTxStatus = LINTP_TX_FF_STATUS;
				}

				/**
				 * @req [SWS_LinIf_00413]The function LinTp_Transmit shall set the sub-state
				 *      of the referenced channel to LINTP_CHANNEL_BUSY.
				 */
				LinTp_SlaveRunCfg[u16ChIndex].u8SubChStatus = LINTP_CHANNEL_BUSY;

				/**
				 * @req [SWS_LinIf_00800]The LIN Interface shall start the N_As timer for
				 *      a SF or FF after invocation of the function LinTp_Transmit with
				 *      return value E_OK and for a CF after the LIN driver indicates the
				 *      reception of a SRF header with invocation of callback function
				 *      LinIf_HeaderIndication and shall stop the N_As timer after the LIN
				 *      driver confirms the response transmission for a SRF header with invocation of
				 *      callback function LinIf_TxConfirmation.
				 */
				LinTp_SlaveRunCfg[u16ChIndex].bNasTimerSwitch = (boolean)TRUE;
				LinTp_SlaveRunCfg[u16ChIndex].u16NasTimer = \
						LinTp_ConfigPtr->LinTpTxNSdu[Channel].LinTpNas;
				retStatus = (Std_ReturnType)E_OK ;
			}
		}
	}
	return retStatus;
}

/**
 * @brief            Processing timeout for transport layer.
 * @param[in]        Channel    Index.
 * @return           void
 */
STATIC FUNC(void,LINIF_CODE) LinTp_TimeHandle
(
    VAR(uint16,AUTOMATIC) Channel
)
{
	VAR(PduIdType,AUTOMATIC) pduId; 
	
	/**
	 * Ncr timeout
	 */
	if(LinTp_SlaveRunCfg[Channel].bNcrTimerSwitch != (boolean)FALSE)
	{
		LinTp_SlaveRunCfg[Channel].u16NcrTimer -=1U;
		if(LinTp_SlaveRunCfg[Channel].u16NcrTimer == 0U)
		{
			/**
			 * @req [SWS_LinIf_00414] The LIN Interface shall set the sub-state of a
			 *      channel to LINTP_CHANNEL_IDLE when it has successfully terminated the
			 *      transmission or reception of a LIN TP message
			 * @req [SWS_LinIf_00688] The LIN Interface shall set the sub-state of a
			 *      channel to LINTP_CHANNEL_IDLE when it has detected an unrecoverable
			 *      error on this channel.
			 */
			pduId = LinTp_SlaveRunCfg[Channel].LinTpRxNSdu->LinTpRxNSduPduRef;
			LinTp_ResetChannel(&LinTp_SlaveRunCfg[Channel]);
			Dcm_TpRxIndication(pduId, E_NOT_OK);
		}
	}

	/**
	 * Nas timeout
	 */
	if(LinTp_SlaveRunCfg[Channel].bNasTimerSwitch != (boolean)FALSE)
	{
		LinTp_SlaveRunCfg[Channel].u16NasTimer -=1U;
		if(LinTp_SlaveRunCfg[Channel].u16NasTimer == 0U)
		{
			/**
			 * @req [SWS_LinIf_00414] The LIN Interface shall set the sub-state of a
			 *      channel to LINTP_CHANNEL_IDLE when it has successfully terminated the
			 *      transmission or reception of a LIN TP message
			 * @req [SWS_LinIf_00688] The LIN Interface shall set the sub-state of a
			 *      channel to LINTP_CHANNEL_IDLE when it has detected an unrecoverable
			 *      error on this channel.
			 * @req [SWS_LinIf_00801] In case of N_As timeout occurrence the
			 *      LIN Interface shall abort the transmission and notify the upper
			 *      layer by calling the function PduR_LinTpTxConfirmation with the
			 *      result E_NOT_OK
			 */
			pduId = LinTp_SlaveRunCfg[Channel].LinTpTxNSdu->LinTpTxNSduPduRef;
			LinTp_ResetChannel(&LinTp_SlaveRunCfg[Channel]);
			Dcm_TpTxConfirmation(pduId, E_NOT_OK);
			
		}
	}

	/**
	 * Ncs timeout
	 */
	if(LinTp_SlaveRunCfg[Channel].bNcsTimerSwitch != (boolean)FALSE)
	{
		LinTp_SlaveRunCfg[Channel].u16NcsTimer -=1U;
		if(LinTp_SlaveRunCfg[Channel].u16NcsTimer == 0U)
		{
			pduId = LinTp_SlaveRunCfg[Channel].LinTpTxNSdu->LinTpTxNSduPduRef;
			/**
			 * @req [SWS_LinIf_00414] The LIN Interface shall set the sub-state of a
			 *      channel to LINTP_CHANNEL_IDLE when it has successfully terminated the
			 *      transmission or reception of a LIN TP message
			 * @req [SWS_LinIf_00688] The LIN Interface shall set the sub-state of a
			 *      channel to LINTP_CHANNEL_IDLE when it has detected an unrecoverable
			 *      error on this channel.
			 */
			LinTp_ResetChannel(&LinTp_SlaveRunCfg[Channel]);
			Dcm_TpTxConfirmation(pduId, E_NOT_OK);
		}
	}
}

/**
 * @sid              0x80
 * @brief            The main processing function of the LIN Interface/LinTp
 * @details
 * @param[in]        None
 * @return           None
 */
STATIC FUNC(void,LINIF_CODE) LinTp_SlaveMainFunction(void)
{
	VAR(uint16,AUTOMATIC) u16Loop;

	for(u16Loop = 0U; u16Loop< LINTP_MAX_CHANNEL_NUM; u16Loop++)
	{
		LinTp_TimeHandle(u16Loop);

		if((LinTp_SlaveRunCfg[u16Loop].LinTpRxNSdu != NULL_PTR) && \
		   (LinTp_SlaveRunCfg[u16Loop].LinTpChannel != NULL_PTR))
		{
			switch(LinTp_SlaveRunCfg[u16Loop].LinTpRxStatus)
			{
				case LINTP_RX_SF_STATUS:
					LinTp_RxSFBufferRequestAndCopyData(u16Loop);
					break;
				case LINTP_RX_FF_STATUS:
					LinTp_RxFFBufferRequestAndCopyData(u16Loop);
					break;
				case LINTP_RX_CF_STATUS:
					LinTp_RxCFCopyData(u16Loop);
					break;
				case LINTP_RX_REQUEST_BUFFER_STATUS:
					LinTp_RxCFBufferRequest(u16Loop);
					break;
				default:
					break;
			}
		}
	}
}
#endif /* LINIF_TP_SUPPORTED == STD_ON */

/**
 * @brief            Processing timeout for transport layer.
 * @param[in]        Channel    Index.
 * @return           void
 */
STATIC FUNC(void,LINIF_CODE) LinIf_TimeHandle
(
    VAR(uint16,AUTOMATIC) Channel
)
{
	VAR(uint8,AUTOMATIC) u8Loop;
	P2VAR(LinIf_SlaveChannelRunningType,AUTOMATIC,LINIF_APPL_DATA) pChRunStatus = NULL_PTR;

	pChRunStatus = &(LinIf_SlaveChannelCfg[Channel]);
	/**
	 * Nas timeout
	 */
	if(pChRunStatus->bNasTimerSwitch != (boolean)FALSE)
	{
		pChRunStatus->u16NasTimer -=1U;
		if(pChRunStatus->u16NasTimer == 0U)
		{
			LinIf_ResetSlaveChannel(Channel);
			for(u8Loop = 0U;u8Loop<8U;u8Loop++)
			{
				LinIf_SlaveNodeCfgResData[Channel][u8Loop] = 0xFFU;
			}
			pChRunStatus->bNcResponseFlag = (boolean)FALSE;
		}
	}
	/**
	 * Bus Idle Timeout
	 */
	if(pChRunStatus->bBusIdleTimerSwitch != (boolean)FALSE)
	{
		pChRunStatus->u16BusIdleTimer -=1U;
		if(pChRunStatus->u16BusIdleTimer == 0U)
		{
			LinIf_SlaveSleepProcess(Channel);
		}
	}

}
/*====================================================================================================*
 *                                          GLOBAL FUNCTIONS
 *====================================================================================================*/
/**
 * @sid              0x01
 * @brief            Initializes the LIN Interface.
 * @details          Initialize LinIf according to the configuration file.
 * @param[in]        ConfigPtr  Pointer to the LIN Interface configuration.
 * @return           None.
 *
 */
FUNC(void,LINIF_CODE)LinIf_Init(P2CONST(LinIf_ConfigType, AUTOMATIC, LINIF_APPL_CONST)ConfigPtr)
{
  VAR(uint16, AUTOMATIC) u16ChIdex ;
  VAR(uint16,AUTOMATIC) u16SlavePidTableIndex;
  VAR(uint16,AUTOMATIC) u16SlaveFrameIdex;
  VAR(Std_ReturnType,AUTOMATIC) retStatus = (Std_ReturnType)E_OK;
  P2CONST(LinIf_ChannelConfigCfgType,AUTOMATIC,LINIF_APPL_CONST) pLinIfChannel = NULL_PTR;
  P2VAR(LinIf_SlaveChannelRunningType,AUTOMATIC,LINIF_APPL_DATA) pChRunStatus = NULL_PTR;

#if(LINIF_DEV_ERROR_DETECT == STD_ON)
  /* Checks whether LinIf can be initial normally */
  retStatus = LinIf_HLDChecksEntry(LINIF_SID_INIT);

  if((Std_ReturnType)E_OK == retStatus)
  {
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */
	  /**
	   * @req [SWS_LinIf_00373] The function LinIf_Init shall accept a parameter that references
	   *      to a LIN Interface configuration descriptor.
	   */
	  LinIf_ConfigPtr = ConfigPtr;
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
	  /* Checks whether the input parameter is valid */
	 retStatus = LinIf_InitCheckPoint(LinIf_ConfigPtr,LINIF_SID_INIT);

	 if((Std_ReturnType)E_OK == retStatus)
	 {
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */
#if (LINIF_USED_SLAVE_NODE == STD_ON)
#if(LINIF_BUS_MIRRORING_SUPPORTED == STD_ON)
		/* Slave Node Bus Mirroring */
		for(u16ChIdex = 0U; u16ChIdex< LINIF_MAX_SLAVE_CHANNEL_NUM ; u16ChIdex++)
		{
			LinIf_SlaveChannelBusMirrorFlag[u16ChIdex] = (boolean)FALSE;
		}
#endif /* LINIF_BUS_MIRRORING_SUPPORTED == STD_ON */

	   /* Slave node Init */
	   for(u16ChIdex = 0U ; u16ChIdex< LINIF_MAX_SLAVE_CHANNEL_NUM ; u16ChIdex++)
	   {
		   pLinIfChannel = &(LinIf_ConfigPtr->LinIfSlaveChannel[u16ChIdex]);
		   /* PID Table Init, Error Signal init. */
		   for(u16SlaveFrameIdex = 0U ; u16SlaveFrameIdex< pLinIfChannel->LinIfMaxFramesNum; u16SlaveFrameIdex++ )
		   {
			   u16SlavePidTableIndex = pLinIfChannel->LinIfFrames[u16SlaveFrameIdex].LinIfFrameTableIndex;

			   if(u16SlavePidTableIndex != 0xFFU)
			   {
				   LinIf_SlavePIDTable[u16SlavePidTableIndex] = \
						   pLinIfChannel->LinIfFrames[u16SlaveFrameIdex].LinIfFramePID;
			   }
		   }

		   /* NAD */
		   if (NULL_PTR != pLinIfChannel->LinIfSlaveNode)
		   {
			   LinIf_SlaveConfiguredNAD[u16ChIdex] = \
			   				   pLinIfChannel->LinIfSlaveNode->LinIfConfiguredNAD;
		   }

		   pChRunStatus = &(LinIf_SlaveChannelCfg[u16ChIdex]);
		   pChRunStatus->bErrorSignalValue = (boolean)FALSE;
		   pChRunStatus->u8LinIfChTransStatus = LINIF_CH_TRANS_SILENT;
		   pChRunStatus->u8LinIfChannleSubStatus = LINIF_CHANNEL_OPERATIONAL;
		   pChRunStatus->bBusIdleTimerSwitch = (boolean)TRUE;
		   pChRunStatus->u16BusIdleTimer = pLinIfChannel->LinIfBusIdleTimeoutPeriod;
		   pChRunStatus->bNcResponseFlag = (boolean)FALSE;
		   pChRunStatus->curLinIfFrames = NULL_PTR;
		   pChRunStatus->subFramePtr = NULL_PTR;
			 
		   LinIf_eStatus = LINIF_INIT;
		   (void)retStatus;
		   (void)LinIf_eStatus;
	   }
#endif /* LINIF_USED_SLAVE_NODE == STD_ON */
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
	 }
  }
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */
}

#if (LINIF_VERSION_INFO_API == STD_ON)
/**
 * @sid              0x03
 * @brief            Returns the version information of this module.
 * @details          This function returns the vendor id, module id,
 *                   major, minor and patch version.
 * @param[out]       versioninfo  Pointer to where to store the version
 *                                information of this module.
 * @return           None.
 *
 */
FUNC(void,LINIF_CODE)LinIf_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, LINIF_APPL_DATA) versioninfo)
{
#if(LINIF_PARAM_CHECK == STD_ON)
  if(NULL_PTR == versioninfo)
  {
	  /**
	   * @req [SWS_LinIf_00640] If development error detection is enabled and the parameter
	   *      versioninfo has an invalid value, the function LinIf_GetVersionInfo shall raise the
	   *      development error code LINIF_E_PARAM_POINTER.
	   */
      LinIf_ReportDetError(LINIF_SID_GETVERSIONINFO , LINIF_E_PARAM_POINTER);
  }
  else
#endif /* LINIF_PARAM_CHECK == STD_ON */
  {
      versioninfo->vendorID = (uint16) LINIF_VENDOR_ID;
      versioninfo->moduleID = (uint16) LINIF_MODULE_ID;
      versioninfo->sw_major_version = (uint8) LINIF_SW_MAJOR_VERSION;
      versioninfo->sw_minor_version = (uint8) LINIF_SW_MINOR_VERSION;
      versioninfo->sw_patch_version = (uint8) LINIF_SW_PATCH_VERSION;
  }
}
#endif /*LINIF_VERSION_INFO_API == STD_ON */

/**
 * @sid              0x04
 * @brief            Indicates a request.
 * @details          Requests a sporadic frame based on the upper-layer PduId.
 * @param[in]        TxPduId      Upper layer identification of the LIN frame
 *                                to be transmitted (not the LIN protected ID).
 *                   PduInfoPtr   Pointer to a structure with frame related data.
 *
 * @return           Std_ReturnType
 * @retval E_NOT_OK  Transmit request has not been accepted.
 * @retval E_OK      Transmit request has been accepted.
 *
 */
/**
 * @req [SWS_LinIf_00105] The function LinIf_Transmit shall indicate a request from an
 *      upper layer to transmit a frame specified by the parameter TxPduId.
 */
FUNC(Std_ReturnType,LINIF_CODE)LinIf_Transmit
(
    VAR(PduIdType,AUTOMATIC) TxPduId,
    P2CONST(PduInfoType,AUTOMATIC,LINIF_APPL_CONST) PduInfoPtr
)
{
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
  VAR(uint16,AUTOMATIC) u16ChIdex  ;
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */
  VAR(Std_ReturnType,AUTOMATIC) retStatus  = (Std_ReturnType)E_NOT_OK ;

#if(LINIF_DEV_ERROR_DETECT == STD_ON)
  /* verify that LinIf has been initialized */
  retStatus = LinIf_HLDChecksEntry(LINIF_SID_TRANSMIT);

  if((Std_ReturnType)E_OK == retStatus)
  {
      /* Checks whether the pointer is valid */
      retStatus = LinIf_TransmitCheckPoint(PduInfoPtr , LINIF_SID_TRANSMIT);

      if((Std_ReturnType)E_OK == retStatus)
      {
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */
		
		
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
      }
  }
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */

  	  return retStatus;
}

/**
 * @sid              0x06
 * @brief            Initiates a transition into the Sleep Mode on the selected channel.
 * @param[in]        Channel           Identification of the LIN channel
 * @return           Std_ReturnType
 * @retval E_NOT_OK  Request to go to sleep has not been accepted due to one or more of the following reasons.
 * @retval E_OK      Request to go to sleep has been accepted or sleep
 *                   transition is already in progress or controller is already in sleep state.
 */
FUNC(Std_ReturnType,LINIF_CODE)LinIf_GotoSleep
(
	VAR(NetworkHandleType,AUTOMATIC) Channel
)
{
	VAR(uint16,AUTOMATIC) u16ChIdex ;
    VAR(Std_ReturnType,AUTOMATIC) retStatus  = (Std_ReturnType)E_NOT_OK ;
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
    /* verify that LinIf has been initialized */
	retStatus = LinIf_HLDChecksEntry(LINIF_SID_GOTOSLEEP);

	if((Std_ReturnType)E_OK == retStatus)
	{
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */
		u16ChIdex = LinIf_SlaveGetConfigChannelIdex(Channel);
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
		/**
		 *	@req [SWS_LinIf_00564] If development error detection is enabled and
		 *	     an invalid value for Channel is given, the function LinIf_GotoSleep
		 *	     shall report LINIF_E_NONEXISTENT_CHANNEL to the default error tracer.
		 */
		retStatus = LinIf_CheckChannelRange(LINIF_SID_GOTOSLEEP,u16ChIdex);

		if((Std_ReturnType)E_OK == retStatus)
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */
		{
			/**
			 * @req[SWS_LinIf_00488]The function LinIf_GotoSleep shall initiate a
			 *     transition into sleep mode on the selected channel.
			 *     (see SWS_LinIf_00453, SWS_LinIf_00597 and SWS_LinIf_00757)
			 */
			retStatus = LinIf_Call_Real_GotoSleep(u16ChIdex);
		}
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
	}
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */
    return retStatus;
}

/**
 * @sid              0x07
 * @brief            Initiates the wake up process.
 * @param[in]        Channel           Identification of the LIN channel
 * @return           Std_ReturnType
 * @retval E_NOT_OK  Request to wake up has not been accepted due to
 *                   one or more of the following reasons
 *                   - LIN Interface has not been initialized
 *                   - referenced channel does not exist (identification is out of range)
 *                   - Lin_Wakeup has returned E_NOT_OK
 *                   - Lin_WakeupInternal has returned E_NOT_OK
 * @retval E_OK      Request to wake up has been accepted or the controller is not in sleep state.
 */
FUNC(Std_ReturnType,LINIF_CODE)LinIf_Wakeup
(
	VAR(NetworkHandleType,AUTOMATIC) Channel
)
{
	VAR(uint16,AUTOMATIC) u16ChIdex ;
    VAR(Std_ReturnType,AUTOMATIC) retStatus  = (Std_ReturnType)E_NOT_OK ;
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
    /* verify that LinIf has been initialized */
	retStatus = LinIf_HLDChecksEntry(LINIF_SID_WAKEUP);

	if((Std_ReturnType)E_OK == retStatus)
	{
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */
		u16ChIdex = LinIf_SlaveGetConfigChannelIdex(Channel);
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
		/**
		 *	@req [SWS_LinIf_00564] If development error detection is enabled and
		 *	     an invalid value for Channel is given, the function LinIf_Wakeup
		 *	     shall report LINIF_E_NONEXISTENT_CHANNEL to the default error tracer.
		 */
		retStatus = LinIf_CheckChannelRange(LINIF_SID_WAKEUP,u16ChIdex);

		if((Std_ReturnType)E_OK == retStatus)
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */
		{
			retStatus = LinIf_Call_Real_Wakeup(u16ChIdex);
		}
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
	}
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */

	return retStatus;
}

#if (LINIF_TRCV_DRIVER_SUPPORTED == STD_ON)
/**
 * @sid              0x08
 * @brief            Set the given LIN transceiver to the given mode.
 * @param[in]        Channel           Identification of the LIN channel
 * 					 TransceiverMode   Requested mode transition
 * @return           Std_ReturnType
 * @retval E_NOT_OK  Will be returned, if the transceiver state change has
 *                   failed or the parameter is out of the allowed range.
 *                   The previous state has not been changed.
 * @retval E_OK      Will be returned, if the transceiver state has been
 *                   changed to the requested mode.
 */
FUNC(Std_ReturnType,LINIF_CODE)LinIf_SetTrcvMode
(
	VAR(NetworkHandleType,AUTOMATIC) Channel,
	VAR(LinTrcv_TrcvModeType,AUTOMATIC) TransceiverMode
)
{
	VAR(uint8,AUTOMATIC) u8RefIndex ;
	VAR(uint16,AUTOMATIC) u16ChIdex ;
    VAR(Std_ReturnType,AUTOMATIC) retStatus  = (Std_ReturnType)E_NOT_OK ;
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
    /* verify that LinIf has been initialized */
	retStatus = LinIf_HLDChecksEntry(LINIF_SID_SETTRCVMODE);

	if((Std_ReturnType)E_OK == retStatus)
	{
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */
		u16ChIdex = LinIf_SlaveGetConfigChannelIdex(Channel);
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
		/**
		 *	@req [SWS_LinIf_00539] If development error detection is enabled and
		 *	     an invalid value for Channel is given, the function LinIf_SetTrcvMode
		 *	     shall report LINIF_E_NONEXISTENT_CHANNEL to the default error tracer.
		 */
		retStatus = LinIf_CheckChannelRange(LINIF_SID_SETTRCVMODE,u16ChIdex);

		if((Std_ReturnType)E_OK == retStatus)
		{
			/**
			 * @req [SWS_LinIf_00540]If development error detection is enabled and
			 *      an invalid mode is requested for TransceiverMode, the function
			 *      LinIf_SetTrcvMode shall report LINIF_E_TRCV_INV_MODE to the
			 *      default error tracer.
			 */
			retStatus =  LinIf_CheckTrcvModeValid(LINIF_SID_SETTRCVMODE,TransceiverMode);

			if((Std_ReturnType)E_OK == retStatus)
			{
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */
				if(LinIf_ConfigPtr->LinIfSlaveChannel[u16ChIdex].LinIfTrcvIdRef != 0xFFU)
				{
					/**
					 * @req[SWS_LinIf_00536]This service shall call the underlying
					 *     function LinTrcv_SetOpMode(LinNetwork, OpMode) for the
					 *     corresponding requested LIN transceiver.
					 * @req[SWS_LinIf_00537]This API shall be applicable to all
					 *     LIN transceivers with all values independent if the
					 *     transceiver hardware supports these modes or not.
					 * @req[SWS_LinIf_00538]The API LinIf_SetTrcvMode returns the
					 *     value that is returned by LinTrcv_SetOpMode.
					 */
					u8RefIndex = LinIf_ConfigPtr->LinIfSlaveChannel[u16ChIdex].LinIfTrcvRefIndex;
					retStatus = LinIf_ConfigPtr->LinIfLinTrcvApi[u8RefIndex].LinTrcvSetOpMode(\
							(uint8)Channel,TransceiverMode);
				}
				else
				{
					retStatus = (Std_ReturnType)E_NOT_OK ;
				}
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
			}
		}
	}
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */

	return retStatus;
}

/**
 * @sid              0x09
 * @brief            Returns the actual state of a LIN Transceiver Driver.
 * @param[in]        Channel             Identification of the LIN channel
 * @param[out]		 TransceiverModePtr  Pointer to a memory location
 *                                       where output value will be
 *                                       stored
 * @return           Std_ReturnType
 * @retval E_NOT_OK  The call of the LIN Transceiver Driver's API
 *                   service has returned E_NOT_OK or channel parameter is
 *                   invalid or pointer is NULL.
 * @retval E_OK      The call of the LIN Transceiver Driver's API service
 *                   has returned E_OK.
 */
FUNC(Std_ReturnType,LINIF_CODE)LinIf_GetTrcvMode
(
	VAR(NetworkHandleType,AUTOMATIC) Channel,
	P2VAR(LinTrcv_TrcvModeType,AUTOMATIC,LINIF_APPL_DATA) TransceiverModePtr
)
{
	VAR(uint8,AUTOMATIC) u8RefIndex ;
	VAR(uint16,AUTOMATIC) u16ChIdex ;
    VAR(Std_ReturnType,AUTOMATIC) retStatus  = (Std_ReturnType)E_NOT_OK ;
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
    /* verify that LinIf has been initialized */
	retStatus = LinIf_HLDChecksEntry(LINIF_SID_GETTRCVMODE);

	if((Std_ReturnType)E_OK == retStatus)
	{
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */
		u16ChIdex = LinIf_SlaveGetConfigChannelIdex(Channel);
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
		/**
		 *	@req [SWS_LinIf_00546] If development error detection is enabled and
		 *	     an invalid value for Channel is given, the function LinIf_GetTrcvMode
		 *	     shall report LINIF_E_NONEXISTENT_CHANNEL to the default error tracer.
		 */
		retStatus = LinIf_CheckChannelRange(LINIF_SID_GETTRCVMODE,u16ChIdex);

		if((Std_ReturnType)E_OK == retStatus)
		{
			/**
			 * @req [SWS_LinIf_00571]If development error detection is enabled and the parameter
			 *      TransceiverModePtr has an invalid value, the function LinIf_GetTrcvMode shall
			 *      raise the development error code LINIF_E_PARAM_POINTER.
			 */
			retStatus =  LinIf_GetTrcvModeCheckPoint(LINIF_SID_SETTRCVMODE,TransceiverModePtr);

			if((Std_ReturnType)E_OK == retStatus)
			{
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */
				if(LinIf_ConfigPtr->LinIfSlaveChannel[u16ChIdex].LinIfTrcvIdRef != 0xFFU)
				{
					/**
					 * @req[SWS_LinIf_00541]This service shall invoke the underlying
					 *     function LinTrcv_GetOpMode(LinNetwork, OpMode) for the
					 *     corresponding requested LIN transceiver.
					 */
					u8RefIndex = LinIf_ConfigPtr->LinIfSlaveChannel[u16ChIdex].LinIfTrcvRefIndex;
					retStatus = LinIf_ConfigPtr->LinIfLinTrcvApi[u8RefIndex].LinTrcvGetOpMode(\
							(uint8)Channel,TransceiverModePtr);
				}
				else
				{
					retStatus = (Std_ReturnType)E_NOT_OK ;
				}
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
			}
		}
	}
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */

	return retStatus;
}

/**
 * @sid              0x0A
 * @brief            Returns the reason for the wake up that has been detected
 *                   by the LIN Transceiver Driver.
 * @param[in]        Channel             Identification of the LIN channel
 * @param[out]		 TrcvWuReasonPtr     Pointer to a memory location where output value will be stored.
 * @return           Std_ReturnType
 * @retval E_NOT_OK  The call of the LIN Transceiver Driver's API
 *                   service has returned E_NOT_OK or channel parameter is
 *                   invalid or pointer is NULL.
 * @retval E_OK      The call of the LIN Transceiver Driver's API service
 *                   has returned E_OK.
 */
FUNC(Std_ReturnType,LINIF_CODE)LinIf_GetTrcvWakeupReason
(
	VAR(NetworkHandleType,AUTOMATIC) Channel,
	P2VAR(LinTrcv_TrcvWakeupReasonType,AUTOMATIC,LINIF_APPL_DATA) TrcvWuReasonPtr
)
{
	VAR(uint8,AUTOMATIC) u8RefIndex ;
	VAR(uint16,AUTOMATIC) u16ChIdex ;
	VAR(LinTrcv_TrcvModeType,AUTOMATIC) TransceiverMode;
    VAR(Std_ReturnType,AUTOMATIC) retStatus  = (Std_ReturnType)E_NOT_OK ;
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
    /* verify that LinIf has been initialized */
	retStatus = LinIf_HLDChecksEntry(LINIF_SID_GETTRCVWAKEUPREASON);

	if((Std_ReturnType)E_OK == retStatus)
	{
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */
		u16ChIdex = LinIf_SlaveGetConfigChannelIdex(Channel);
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
		/**
		 *	@req [SWS_LinIf_00549] If development error detection is enabled and
		 *	     an invalid value for Channel is given, the function LinIf_GetTrcvWakeupReason
		 *	     shall report LINIF_E_NONEXISTENT_CHANNEL to the default error tracer.
		 */
		retStatus = LinIf_CheckChannelRange(LINIF_SID_GETTRCVWAKEUPREASON,u16ChIdex);

		if((Std_ReturnType)E_OK == retStatus)
		{
			/**
			 * @req [SWS_LinIf_00573]If development error detection is enabled and the parameter
			 *      TrcvWuReasonPtr has an invalid value, the function LinIf_GetTrcvWakeupReason
			 *      shall raise the development error code LINIF_E_PARAM_POINTER.
			 */
			retStatus =  LinIf_GetTrcvWakeupReasonCheckPoint(\
						LINIF_SID_GETTRCVWAKEUPREASON,TrcvWuReasonPtr);

			if((Std_ReturnType)E_OK == retStatus)
			{
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */
				if(LinIf_ConfigPtr->LinIfSlaveChannel[u16ChIdex].LinIfTrcvIdRef != 0xFFU)
				{
					u8RefIndex = LinIf_ConfigPtr->LinIfSlaveChannel[u16ChIdex].LinIfTrcvRefIndex;
					retStatus = LinIf_ConfigPtr->LinIfLinTrcvApi[u8RefIndex].LinTrcvGetOpMode(\
							(uint8)Channel,&TransceiverMode);
					if(retStatus != (Std_ReturnType)E_NOT_OK)
					{
						/**
						 * @req[SWS_LinIf_00572] If development error detection is enabled
						 *     and the current mode is not LINTRCV_TRCV_MODE_NORMAL,
						 *     the function LinIf_GetTrcvWakeupReason shall report
						 *     LINIF_E_TRCV_NOT_NORMAL to the default error tracer.
						 */
						if(TransceiverMode != LINTRCV_TRCV_MODE_NORMAL)
						{
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
							LinIf_ReportDetError(\
									LINIF_SID_GETTRCVWAKEUPREASON,LINIF_E_TRCV_NOT_NORMAL);
#endif/* LINIF_DEV_ERROR_DETECT == STD_ON */
							retStatus = (Std_ReturnType)E_NOT_OK ;
						}
						else
						{
							retStatus = LinIf_ConfigPtr->LinIfLinTrcvApi[u8RefIndex].\
									LinTrcvGetBusWuReason((uint8)Channel,TrcvWuReasonPtr);
						}
					}
				}
				else
				{
					retStatus = (Std_ReturnType)E_NOT_OK ;
				}
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
			}
		}
	}
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */

	return retStatus;
}

/**
 * @sid              0x0B
 * @brief            This API enables, disables and clears the notification for
 *                   wakeup events on the addressed network
 * @param[in]        Channel           Identification of the LIN channel
 * 					 LinTrcvWakeupMode Requested transceiver wake up reason.
 * @return           Std_ReturnType
 * @retval E_NOT_OK  The call of the LIN Transceiver Driver's API service has
 *                   returned E_NOT_OK or channel or mode parameter is invalid.
 * @retval E_OK      The call of the LIN Transceiver Driver's API service
 *                   has returned E_OK.
 */
FUNC(Std_ReturnType,LINIF_CODE)LinIf_SetTrcvWakeupMode
(
	VAR(NetworkHandleType,AUTOMATIC) Channel,
	VAR(LinTrcv_TrcvWakeupModeType,AUTOMATIC) LinTrcvWakeupMode
)
{
	VAR(uint8,AUTOMATIC) u8RefIndex ;
	VAR(uint16,AUTOMATIC) u16ChIdex ;
    VAR(Std_ReturnType,AUTOMATIC) retStatus  = (Std_ReturnType)E_NOT_OK ;
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
    /* verify that LinIf has been initialized */
	retStatus = LinIf_HLDChecksEntry(LINIF_SID_SETTRCVWAKEUPREASON);

	if((Std_ReturnType)E_OK == retStatus)
	{
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */
		u16ChIdex = LinIf_SlaveGetConfigChannelIdex(Channel);
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
		/**
		 *	@req [SWS_LinIf_00595] If development error detection is enabled and
		 *	     an invalid value for Channel is given, the function LinIf_SetTrcvWakeupMode
		 *	     shall report LINIF_E_NONEXISTENT_CHANNEL to the default error tracer.
		 */
		retStatus = LinIf_CheckChannelRange(LINIF_SID_SETTRCVWAKEUPREASON,u16ChIdex);

		if((Std_ReturnType)E_OK == retStatus)
		{
			/**
			 * @req [SWS_LinIf_00596]If development error detection is enabled and an
			 *      invalid value for LinTrcvWakeupMode is given, the function
			 *      LinIf_SetTrcvWakeupMode shall report LINIF_E_PARAMETER to the
			 *      default error tracer.
			 */
			retStatus =  LinIf_CheckWakeupModeValid(LINIF_SID_SETTRCVWAKEUPREASON,LinTrcvWakeupMode);
			if((Std_ReturnType)E_OK == retStatus)
			{
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */
				if(LinIf_ConfigPtr->LinIfSlaveChannel[u16ChIdex].LinIfTrcvIdRef != 0xFFU)
				{
					/**
					 * @req[SWS_LinIf_00551]This service shall call the underlying
					 *     function LinTrcv_SetWakeupMode(LinNetwork, TrcvWakeupMode) for the
					 *     corresponding requested LIN transceiver.
					 */
					u8RefIndex = LinIf_ConfigPtr->LinIfSlaveChannel[u16ChIdex].LinIfTrcvRefIndex;
					retStatus = LinIf_ConfigPtr->LinIfLinTrcvApi[u8RefIndex].LinTrcvSetWakeupMode(\
							(uint8)Channel,LinTrcvWakeupMode);
				}
				else
				{
					retStatus = (Std_ReturnType)E_NOT_OK ;
				}
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
			}
		}
	}
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */

	return retStatus;
}


#endif /* LINIF_TRCV_DRIVER_SUPPORTED == STD_ON */

/**
 * @sid              0x60
 * @brief            Will be called when the EcuM has been notified about a
 *                   wakeup on a specific LIN channel.
 * @param[in]        WakeupSource    Source device, which initiated the wakeup event:
 *                                   LIN controller or LIN transceiver
 * @return           Std_ReturnType
 * @retval E_NOT_OK  An error has occurred during execution of the API or invalid WakeupSource
 * @retval E_OK      No error has occurred during execution of the API
 */
FUNC(Std_ReturnType,LINIF_CODE)LinIf_CheckWakeup
(
	VAR(EcuM_WakeupSourceType,AUTOMATIC) WakeupSource
)
{
	VAR(uint16,AUTOMATIC) u16Loop;
	VAR(Std_ReturnType,AUTOMATIC) retStatus  = (Std_ReturnType)E_NOT_OK ;

#if(LINIF_DEV_ERROR_DETECT == STD_ON)
	retStatus = LinIf_HLDChecksEntry(LINIF_SID_CHECKWAKEUP);

	if((Std_ReturnType)E_OK == retStatus)
	{
		/**
		 * @req [SWS_LinIf_00566]If development error detection is enabled and the parameter
		 *      WakeupSource has an invalid value, the function LinIf_CheckWakeup shall
		 *      raise the development error code LINIF_E_PARAM_WAKEUPSOURCE.
		 */
		retStatus = LinIf_CheckWakeupSource(LINIF_SID_CHECKWAKEUP, WakeupSource);

		if((Std_ReturnType)E_OK == retStatus)
		{
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */
			for(u16Loop = 0U;u16Loop<LINIF_MAX_SLAVE_CHANNEL_NUM; u16Loop++)
			{
				if(LinIf_ConfigPtr->LinIfSlaveChannel[u16Loop].LinIfWakeUpSource == WakeupSource)
				{
					retStatus = LinIf_Call_CheckWakeup(u16Loop);
					break;
				}
			}
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
		}
	}
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */

	return retStatus;
}

#if(LINIF_BUS_MIRRORING_SUPPORTED == STD_ON)
/**
 * @sid              0x7f
 * @brief            Enables or disables mirroring for a LIN channel.
 * @param[in]        Channel           Identification of the LIN channel
 *                   MirroringActive
 *							TRUE: Mirror_ReportLinFrame will be called for each
 *							      frame received or transmitted on the given channel.
 *						    FALSE: Mirror_ReportLinFrame will not be called for the
 *						          given channel.
 * @return           Std_ReturnType
 * @retval E_NOT_OK  Wrong Channel, or mirroring globally disabled (see LinIfBusMirroringSupport).
 * @retval E_OK      Mirroring mode was changed.
 */
FUNC(Std_ReturnType,LINIF_CODE)LinIf_EnableBusMirroring
(
    VAR(NetworkHandleType,AUTOMATIC) Channel,
    VAR(boolean,AUTOMATIC) MirroringActive
)
{
	VAR(uint16,AUTOMATIC) u16ChIdex ;
    VAR(Std_ReturnType,AUTOMATIC) retStatus  = (Std_ReturnType)E_NOT_OK ;
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
    /* verify that LinIf has been initialized */
	retStatus = LinIf_HLDChecksEntry(LINIF_SID_ENABLEBUSMIRRORING);

	if((Std_ReturnType)E_OK == retStatus)
	{
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */
		u16ChIdex = LinIf_SlaveGetConfigChannelIdex(Channel);
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
		/**
		 *	@req [SWS_LinIf_00818] If development error detection is enabled and
		 *	     an invalid value for Channel is given, the function LinIf_EnableBusMirroring
		 *	     shall report LINIF_E_NONEXISTENT_CHANNEL to the default error tracer.
		 */
		retStatus = LinIf_CheckChannelRange(LINIF_SID_ENABLEBUSMIRRORING,u16ChIdex);

		if((Std_ReturnType)E_OK == retStatus)
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */
		{
			LinIf_SlaveChannelBusMirrorFlag[u16ChIdex] = (boolean)MirroringActive;
			retStatus = (Std_ReturnType)E_OK;
		}
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
	}
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */
    return retStatus;
}
#endif /* LINIF_BUS_MIRRORING_SUPPORTED == STD_ON */

/**
 * @sid              0x61
 * @brief            The LIN Driver or LIN Transceiver Driver will call this
 *                   function to report the wake up source after the successful
 *                   wakeup detection during CheckWakeup or after power on by bus.
 * @param[in]        WakeupSource   Source device which initiated the wakeup event:
 *                                  LIN controller or LIN transceiver
 * @return           void
 *
 */
FUNC(void,LINIF_CODE)LinIf_WakeupConfirmation
(
    VAR(EcuM_WakeupSourceType,AUTOMATIC) WakeupSource
)
{
	VAR(uint16,AUTOMATIC) u16Loop;
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
	VAR(Std_ReturnType,AUTOMATIC) retStatus  = (Std_ReturnType)E_NOT_OK ;
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */

#if(LINIF_DEV_ERROR_DETECT == STD_ON)
	retStatus = LinIf_HLDChecksEntry(LINIF_SID_WAKEUPCONFIRMATION);

	if((Std_ReturnType)E_OK == retStatus)
	{
		/**
		 * @req [SWS_LinIf_00717]If development error detection is enabled and the parameter
		 *      WakeupSource has an invalid value, the function LinIf_WakeupConfirmation shall
		 *      raise the development error code LINIF_E_PARAM_WAKEUPSOURCE.
		 */
		retStatus = LinIf_CheckWakeupSource(LINIF_SID_WAKEUPCONFIRMATION, WakeupSource);

		if((Std_ReturnType)E_OK == retStatus)
		{
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */
			for(u16Loop = 0U;u16Loop<LINIF_MAX_SLAVE_CHANNEL_NUM; u16Loop++)
			{
				if(LinIf_ConfigPtr->LinIfSlaveChannel[u16Loop].LinIfWakeUpSource == WakeupSource)
				{
					/**
					 * @req[SWS_LinIf_00716]The function LinIf_WakeupConfirmation shall set
					 *     the wakeup flag for the channel depending on the given parameter
					 *     WakeupSource. The wakeup flags shall be provided for each channel.
					 */
					break;
				}
			}
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
		}
	}
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */
}

#if (LINIF_USED_SLAVE_NODE == STD_ON)
/**
 * @sid              0x72
 * @brief            Retrieves all assigned PID values.
 *                   The order is congruent to the LIN frame index.
 * @param[in]        Channel   Identification of the LIN channel.
 *
 * @param[inout]
 *                   PidBuffer Pointer to existing buffer to which the
 *                             current assigned PID values are copied to
 *
 *                   PidBufferLength   Pointer to actual length of provided buffer.
 *                   After successful return, it contains the number of copied PID values.
 *
 * @return           Std_ReturnType
 * @retval E_NOT_OK  Request has not been accepted, development or production error occurred.
 * @retval E_OK      Request has been accepted.
 *
 */
FUNC(Std_ReturnType,LINIF_CODE)LinIf_GetPIDTable
(
    VAR(NetworkHandleType,AUTOMATIC) Channel,
    P2VAR(Lin_FramePidType,AUTOMATIC,LINIF_APPL_DATA) PidBuffer,
	P2VAR(uint8,AUTOMATIC,LINIF_APPL_DATA) PidBufferLength
)
{
	VAR(uint16,AUTOMATIC) u16ChIdex = 0U;
	VAR(Std_ReturnType,AUTOMATIC) retStatus  = (Std_ReturnType)E_NOT_OK ;
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
	retStatus = LinIf_HLDChecksEntry(LINIF_SID_GETPIDTABLE);

	if((Std_ReturnType)E_OK == retStatus)
	{
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */
		u16ChIdex = LinIf_SlaveGetConfigChannelIdex(Channel);
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
		/**
		 *	@req [SWS_LinIf_00818] If development error detection is enabled and
		 *	     an invalid value for Channel is given, the function LinIf_GetPIDTable
		 *	     shall report LINIF_E_NONEXISTENT_CHANNEL to the default error tracer.
		 */
		retStatus = LinIf_CheckChannelRange(LINIF_SID_GETPIDTABLE,u16ChIdex);

		if((Std_ReturnType)E_OK == retStatus)
		{
			/**
			 * @req [SWS_LinIf_00819] If development error detection is enabled and
			 *      an invalid value for PidBuffer is given, the function LinIf_GetPIDTable
			 *      shall raise the development error code LINIF_E_PARAM_POINTER
			 */
			retStatus = LinIf_PIDTableCheckPoint(PidBuffer,LINIF_SID_GETPIDTABLE);

			if((Std_ReturnType)E_OK == retStatus)
			{

				/**
				 * @req [SWS_LinIf_00820] If development error detection is enabled and
				 *      an invalid value for PidBufferLength is given, the function
				 *      LinIf_GetPIDTable shall raise the development error
				 *      code LINIF_E_PARAM_POINTER.
				 */
				retStatus = LinIf_ParUint8CheckPoint(PidBufferLength,LINIF_SID_GETPIDTABLE);

				if((Std_ReturnType)E_OK == retStatus)
				{
					/**
					 * @req [SWS_LinIf_00821]  If development error detection is enabled
					 *      and length of the buffer (provided by parameter PidBufferLength)
					 *      is smaller than the number of configured PIDs of the slave node
					 *      (except 0, see SWS_LinIf_00828), the function LinIf_GetPIDTable
					 *      shall raise the development error code LINIF_E_PARAMETER.
					 */
					retStatus = LinIf_GetPIDTableParaCheck( u16ChIdex,\
															  PidBufferLength,\
															  LINIF_SID_GETPIDTABLE\
															);
					if((Std_ReturnType)E_OK == retStatus)
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */
					{
						LinIf_Call_GetPIDTable(u16ChIdex,PidBuffer,PidBufferLength);
						retStatus = (Std_ReturnType)E_OK;
					}
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
				}
			}
		}
	}
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */

	return retStatus;
}

/**
 * @sid              0x73
 * @brief            Sets all assigned PID values. The order is congruent to the LIN frame index.
 * @details          This API shall update the internal configured PID list in LIN
 *                   Interface with the given PID list.
 * @param[in]        Channel   identification of the LIN channel.
 *
 *                   PidBuffer Pointer to buffer which contains the PID values to configure.
 *
 *                   PidBufferLength Number of PID values in the provided buffer
 *
 * @return           Std_ReturnType
 * @retval E_NOT_OK  Request has not been accepted,
 *                   development or production error occurred.
 * @retval E_OK      Request has been accepted.
 *
 */
FUNC(Std_ReturnType,LINIF_CODE)LinIf_SetPIDTable
(
    VAR(NetworkHandleType,AUTOMATIC) Channel,
    P2VAR(Lin_FramePidType,AUTOMATIC,LINIF_APPL_DATA) PidBuffer,
	VAR(uint8,AUTOMATIC) PidBufferLength
)
{
	VAR(uint16,AUTOMATIC) u16ChIdex = 0U;
	VAR(Std_ReturnType,AUTOMATIC) retStatus  = (Std_ReturnType)E_NOT_OK ;
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
	retStatus = LinIf_HLDChecksEntry(LINIF_SID_SETPIDTABLE);

	if((Std_ReturnType)E_OK == retStatus)
	{
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */
		u16ChIdex = LinIf_SlaveGetConfigChannelIdex(Channel);
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
		/**
		 *	@req [SWS_LinIf_00825] If development error detection is enabled and
		 *	     an invalid value for Channel is given, the function LinIf_SetPIDTable
		 *	     shall report LINIF_E_NONEXISTENT_CHANNEL to the default error tracer.
		 */
		retStatus = LinIf_CheckChannelRange(LINIF_SID_SETPIDTABLE,u16ChIdex);

		if((Std_ReturnType)E_OK == retStatus)
		{

			/**
			 * @req [SWS_LinIf_00826] If development error detection is enabled and an
			 *      invalid value for PidBuffer is given, the function LinIf_SetPIDTable
			 *      shall raise the development error code LINIF_E_PARAM_POINTER.
			 */
			retStatus = LinIf_PIDTableCheckPoint(PidBuffer,LINIF_SID_SETPIDTABLE);

			if((Std_ReturnType)E_OK == retStatus)
			{

				retStatus = LinIf_SetPIDTableParaCheck( u16ChIdex,\
														  PidBufferLength,\
														  LINIF_SID_SETPIDTABLE \
														);
				if((Std_ReturnType)E_OK == retStatus)
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */
				{
					LinIf_Call_SetPIDTable(u16ChIdex,PidBuffer,PidBufferLength);
					retStatus = (Std_ReturnType)E_OK;
				}
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
			}
		}
	}
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */
	return retStatus;
}

/**
 * @sid              0x70
 * @brief            Reports the current configured NAD.
 * @param[in]        Channel   Identification of the LIN channel.
 *                   Nad   Configured NAD of slave.
 *
 * @return           Std_ReturnType
 * @retval E_NOT_OK  Request has not been accepted, development or
 *                   production error occurred.
 * @retval E_OK      Request has been accepted.
 *
 */
FUNC(Std_ReturnType,LINIF_CODE)LinIf_GetConfiguredNAD
(
    VAR(NetworkHandleType,AUTOMATIC) Channel,
	P2VAR(uint8, AUTOMATIC,LINIF_APPL_DATA) Nad
)
{
	VAR(uint16,AUTOMATIC) u16ChIdex = 0U;
	VAR(Std_ReturnType,AUTOMATIC) retStatus  = (Std_ReturnType)E_NOT_OK ;
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
	retStatus = LinIf_HLDChecksEntry(LINIF_SID_GETCONFIGUREDNAD);

	if((Std_ReturnType)E_OK == retStatus)
	{
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */
		u16ChIdex = LinIf_SlaveGetConfigChannelIdex(Channel);
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
		/**
		 *	@req [SWS_LinIf_00831] If development error detection is enabled and
		 *	     an invalid value for Channel is given, the function LinIf_GetConfiguredNAD
		 *	     shall report LINIF_E_NONEXISTENT_CHANNEL to the default error tracer.
		 */
		retStatus = LinIf_CheckChannelRange(LINIF_SID_GETCONFIGUREDNAD,u16ChIdex);

		if((Std_ReturnType)E_OK == retStatus)
		{
			/**
			 * @req [SWS_LinIf_00832]  If development error detection is enabled and an
			 *       invalid value for Nad is given, the function LinIf_GetConfiguredNAD
			 *       shall raise the development error code LINIF_E_PARAM_POINTER.
			 */
			retStatus = LinIf_ParUint8CheckPoint(Nad,LINIF_SID_GETCONFIGUREDNAD);

			if((Std_ReturnType)E_OK == retStatus)
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */
			{
				(*Nad) = LinIf_SlaveConfiguredNAD[u16ChIdex] ;
				retStatus = (Std_ReturnType)E_OK;
			}
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
		}
	}
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */

	return retStatus;
}

/**
 * @sid              0x71
 * @brief            Sets the current configured NAD.
 * @param[in]        Channel   Identification of the LIN channel.
 *                   Nad   Configured NAD to set as new slave NAD
 *
 * @return           Std_ReturnType
 * @retval E_NOT_OK  Request has not been accepted, development or
 *                   production error occurred.
 * @retval E_OK      Request has been accepted.
 *
 */
FUNC(Std_ReturnType,LINIF_CODE)LinIf_SetConfiguredNAD
(
    VAR(NetworkHandleType,AUTOMATIC) Channel,
	VAR(uint8, AUTOMATIC) Nad
)
{
	VAR(uint16,AUTOMATIC) u16ChIdex = 0U;
	VAR(Std_ReturnType,AUTOMATIC) retStatus  = (Std_ReturnType)E_NOT_OK ;
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
	retStatus = LinIf_HLDChecksEntry(LINIF_SID_SETCONFIGUREDNAD);

	if((Std_ReturnType)E_OK == retStatus)
	{
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */
		u16ChIdex = LinIf_SlaveGetConfigChannelIdex(Channel);
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
		/**
		 *	@req [SWS_LinIf_00835] If development error detection is enabled and
		 *	     an invalid value for Channel is given, the function LinIf_SetConfiguredNAD
		 *	     shall report LINIF_E_NONEXISTENT_CHANNEL to the default error tracer.
		 */
		retStatus = LinIf_CheckChannelRange(LINIF_SID_SETCONFIGUREDNAD,u16ChIdex);

		if((Std_ReturnType)E_OK == retStatus)
		{
			/**
			 * @req [SWS_LinIf_00836]  If development error detection is enabled and the
			 *       value 0 for Nad is given, the function LinIf_SetConfiguredNAD shall
			 *       raise the development error code LINIF_E_PARAM
			 */
			retStatus = LinIf_SetConfiguredNADParCheck(Nad,LINIF_SID_SETCONFIGUREDNAD);

			if((Std_ReturnType)E_OK == retStatus)
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */
			{
				LinIf_SlaveConfiguredNAD[u16ChIdex] = Nad ;
				retStatus = (Std_ReturnType)E_OK;
			}
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
		}
	}
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */
	return retStatus;
}

/**
 * @sid              0x78
 * @brief            The LIN Driver will call this function to report a received LIN header.
 *                   This function is only applicable for LIN slave nodes (available only if
 *                   the ECU has any LIN slave channel).
 * @param[in]        Channel   identification of the LIN channel
 *                   PduPtr    Pointer to PDU providing the received PID and pointer to the
 *                             SDU data buffer as in parameter.
 *
 * @return           Std_ReturnType
 * @retval E_NOT_OK  Request has not been accepted, development or production error occurred.
 * @retval E_OK      Request has been accepted.
 */
FUNC(Std_ReturnType,LINIF_CODE)LinIf_HeaderIndication
(
    VAR(NetworkHandleType,AUTOMATIC) Channel,
	P2VAR(Lin_PduType, AUTOMATIC,LINIF_APPL_DATA) PduPtr
)
{
	VAR(uint16,AUTOMATIC) u16ChIdex = 0U;
	VAR(Std_ReturnType,AUTOMATIC) retStatus  = (Std_ReturnType)E_NOT_OK ;
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
	retStatus = LinIf_HLDChecksEntry(LINIF_SID_HEADERINDICATION);

	if((Std_ReturnType)E_OK == retStatus)
	{
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */
		u16ChIdex = LinIf_SlaveGetConfigChannelIdex(Channel);

#if(LINIF_DEV_ERROR_DETECT == STD_ON)
		/**
		 *	@req [SWS_LinIf_00843] If development error detection is enabled and
		 *	     an invalid value for Channel is given, the function LinIf_HeaderIndication
		 *	     shall report LINIF_E_NONEXISTENT_CHANNEL to the default error tracer.
		 */
		retStatus = LinIf_CheckChannelRange(LINIF_SID_HEADERINDICATION,u16ChIdex);

		if((Std_ReturnType)E_OK == retStatus)
		{
			/**
			 *	@req [SWS_LinIf_00844] If development error detection is enabled and the
			 *	     parameter PduPtr has an invalid value, the function LinIf_HeaderIndication
			 *	     shall raise the development error code LINIF_E_PARAM_POINTER.
			 */
			retStatus = LinIf_HeaderIndicationCheckPoint(PduPtr,LINIF_SID_HEADERINDICATION);

			if((Std_ReturnType)E_OK == retStatus)
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */
			{
				retStatus = LinIf_Call_HeaderIndication(u16ChIdex,PduPtr);
			}
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
		}
	}
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */

	return retStatus;
}

/**
 * @sid              0x79
 * @details          The LIN Driver will call this function to report a successfully received response
 *                   and provides the reception data to the LIN Interface. This function is only
 *                   applicable for LIN slave nodes (available only if the ECU has any LIN slave channel).
 * @param[in]        Channel   Identification of the LIN channel
 *
 *                   Lin_SduPtr  Pointer to pointer to a shadow buffer or memory mapped LIN
 *                               Hardware receive buffer where the current SDU is stored.
 *                               This pointer is only valid if the response is received.
 *
 * @return           void
 *
 */
FUNC(void,LINIF_CODE)LinIf_RxIndication
(
    VAR(NetworkHandleType,AUTOMATIC) Channel,
	P2VAR(uint8, AUTOMATIC,LINIF_APPL_DATA) Lin_SduPtr
)
{
	VAR(uint16,AUTOMATIC) u16ChIdex = 0U;
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
	VAR(Std_ReturnType,AUTOMATIC) retStatus  = (Std_ReturnType)E_NOT_OK ;

	retStatus = LinIf_HLDChecksEntry(LINIF_SID_RXINDICATION);

	if((Std_ReturnType)E_OK == retStatus)
	{
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */
		u16ChIdex = LinIf_SlaveGetConfigChannelIdex(Channel);

#if(LINIF_DEV_ERROR_DETECT == STD_ON)
		/**
		 *	@req [SWS_LinIf_00849] If development error detection is enabled and
		 *	     an invalid value for Channel is given, the function LinIf_RxIndication
		 *	     shall report LINIF_E_NONEXISTENT_CHANNEL to the default error tracer.
		 */
		retStatus = LinIf_CheckChannelRange(LINIF_SID_RXINDICATION,u16ChIdex);

		if((Std_ReturnType)E_OK == retStatus)
		{
			/**
			 *	@req [SWS_LinIf_00850] If development error detection is enabled and the
			 *	     parameter PduPtr has an invalid value, the function LinIf_RxIndication
			 *	     shall raise the development error code LINIF_E_PARAM_POINTER.
			 */
			retStatus = LinIf_ParUint8CheckPoint(Lin_SduPtr,LINIF_SID_RXINDICATION);

			if((Std_ReturnType)E_OK == retStatus)
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */
			{
				LinIf_Call_RxIndication(u16ChIdex,Lin_SduPtr);
			}
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
		}
	}
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */
}

/**
 * @sid              0x7A
 * @details          The LIN Driver will call this function to report a successfully
 *                   transmitted response. This function is only applicable for LIN
 *                    slave nodes (available only if the ECU has any LIN slave channel).
 * @param[in]        Channel   Identification of the LIN channel
 *
 * @return           void
 *
 */
FUNC(void,LINIF_CODE)LinIf_TxConfirmation
(
    VAR(NetworkHandleType,AUTOMATIC) Channel
)
{
	VAR(uint16,AUTOMATIC) u16ChIdex = 0U;
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
	VAR(Std_ReturnType,AUTOMATIC) retStatus  = (Std_ReturnType)E_NOT_OK ;

	retStatus = LinIf_HLDChecksEntry(LINIF_SID_TXCONFIRMATION);

	if((Std_ReturnType)E_OK == retStatus)
	{
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */
		u16ChIdex = LinIf_SlaveGetConfigChannelIdex(Channel);
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
		/**
		 *	@req [SWS_LinIf_00843] If development error detection is enabled and
		 *	     an invalid value for Channel is given, the function LinIf_HeaderIndication
		 *	     shall report LINIF_E_NONEXISTENT_CHANNEL to the default error tracer.
		 */
		retStatus = LinIf_CheckChannelRange(LINIF_SID_HEADERINDICATION,u16ChIdex);

		if((Std_ReturnType)E_OK == retStatus)
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */
		{
			LinIf_Call_TxConfirmation(u16ChIdex);
		}
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
	}
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */
}

/**
 * @sid              0x7B
 * @details          The LIN Driver will call this function to report a detected error
 *                   event during header or response processing. This function is only
 *                   applicable for LIN slave nodes (available only if the ECU has any
 *                   LIN slave channel).
 * @param[in]        Channel   Identification of the LIN channel
 *
 *                   ErrorStatus  Type of detected error
 *
 * @return           void
 *
 */
FUNC(void,LINIF_CODE)LinIf_LinErrorIndication
(
    VAR(NetworkHandleType,AUTOMATIC) Channel,
	VAR(Lin_SlaveErrorType,AUTOMATIC) ErrorStatus
)
{
	VAR(uint16,AUTOMATIC) u16ChIdex = 0U;
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
	VAR(Std_ReturnType,AUTOMATIC) retStatus  = (Std_ReturnType)E_NOT_OK ;
	retStatus = LinIf_HLDChecksEntry(LINIF_SID_LINERRORINDICATION);
	if((Std_ReturnType)E_OK == retStatus)
	{
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */
		u16ChIdex = LinIf_SlaveGetConfigChannelIdex(Channel);
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
		/**
		 *	@req [SWS_LinIf_00855] If development error detection is enabled and
		 *	     an invalid value for Channel is given, the function LinIf_LinErrorIndication
		 *	     shall report LINIF_E_NONEXISTENT_CHANNEL to the default error tracer.
		 */
		retStatus = LinIf_CheckChannelRange(LINIF_SID_LINERRORINDICATION,u16ChIdex);
		if((Std_ReturnType)E_OK == retStatus)
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */
		{
			LinIf_Call_LinErrorIndication(u16ChIdex,ErrorStatus);
		}
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
	}
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */
}
#endif /* LINIF_USED_SLAVE_NODE == STD_ON */

#if (LINIF_TP_SUPPORTED == STD_ON)
/**
 * @sid              0x40
 * @brief            Initializes the LIN Transport Layer.
 * @details          initializes the relates channel of LinTp.
 * @param[in]        ConfigPtr  Pointer to the LIN Transport Protocol configuration.
 * @return           None
 */
FUNC(void,LINIF_CODE) LinTp_Init(P2CONST(LinTp_ConfigType,AUTOMATIC,LINIF_APPL_CONST) ConfigPtr)
{
  VAR(uint16, AUTOMATIC) u16ChIdex ;
  P2VAR(LinIf_SlaveTpRunCfgType,AUTOMATIC,LINIF_APPL_DATA) chPtr ;

#if(LINIF_DEV_ERROR_DETECT == STD_ON)
  VAR(Std_ReturnType,AUTOMATIC) checkStatus  = (Std_ReturnType)E_NOT_OK ;
  /* Checks whether LinTp can be initialized normally */
  checkStatus = LinTp_HLDChecksEntry(LINTP_SID_INIT);
  if((Std_ReturnType)E_OK == checkStatus)
  {
      /* Checks whether the input parameter is valid */
      checkStatus = LinTp_InitCheckPoint(ConfigPtr,LINTP_SID_INIT);
      if((Std_ReturnType)E_OK == checkStatus)
      {
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */
        /**
         * @req [SWS_LinIf_00427]The parameter ConfigPtr of the function LinTp_Init is
         *      only relevant for the configuration variant VARIANT-POST-BUILD.
         *      The parameter ConfigPtr shall be ignored for the configuration
         *      variant VARIANT-PRE-COMPILE and the configuration variant VARIANT-LINK-TIME.
         */
    	   LinTp_ConfigPtr = ConfigPtr;

         /* Reset all of the LinTp Channel. */
         for(u16ChIdex = 0U ; u16ChIdex< LINTP_MAX_CHANNEL_NUM ; u16ChIdex++)
         {
             chPtr = &LinTp_SlaveRunCfg[u16ChIdex];
             /**
              * @req [SWS_LinIf_00710] The LIN Interface shall set the sub-state of a channel to
              *      LINTP_CHANNEL_IDLE when the LIN TP state-machine is set to the state LINTP_INIT.
              */
             LinTp_ResetChannel(chPtr);
			 chPtr->eOngoingRequest = LINTP_PHY_REQUEST_TYPE;
         }
         /**
          * @req[SWS_LinIf_00412] The LIN TP state-machine shall have the sub-state-machines
          *     of the state LINTP_INIT for each channel, that track the state of
          *     channel separately.
          * @req [SWS_LinIf_00710] The LIN Interface shall set the sub-state of a
          *     channel to LINTP_CHANNEL_IDLE when the LIN TP state-machine is set
          *     to the state LINTP_INIT.
          *
          */
         LinTp_eStatus = LINTP_INIT;
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
      }
  }
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */
}

/**
 * @sid              0x49
 * @brief            Requests transmission of a PDU.
 * @details          The function LinTp_Transmit shall prepare a LIN TP message for transmission.
 * @param[in]        PduInfoPtr Length of and pointer to the PDU data and pointer to MetaData.
 * @param[in]        TxPduId    Identifier of the PDU to be transmitted
 * @return           Std_ReturnType
 *                   E_OK: The request can be started successfully.
 *                   E_NOT_OK: The request can not be started.
 */
FUNC(Std_ReturnType,LINIF_CODE) LinTp_Transmit
(
    VAR(PduIdType,AUTOMATIC) TxPduId,
    P2CONST(PduInfoType,AUTOMATIC,LINIF_APPL_CONST) PduInfoPtr
)
{
	VAR(uint16, AUTOMATIC) u16ChIdex ;
	VAR(Std_ReturnType,AUTOMATIC) checkStatus  = (Std_ReturnType)E_NOT_OK ;

#if(LINIF_DEV_ERROR_DETECT == STD_ON)
	/* Checks whether LinIf can be initialized normally */
	checkStatus = LinIf_HLDChecksEntry(LINTP_SID_TRANSMIT);
	if((Std_ReturnType)E_OK == checkStatus)
	{
		/* Checks whether LinTp can be initialized normally */
		checkStatus = LinTp_HLDChecksEntry(LINTP_SID_TRANSMIT);
		if((Std_ReturnType)E_OK == checkStatus)
		{
			/**
			 * @req [SWS_LinIf_00574]If development error detection is enabled
			 *      and the parameter PduInfoPtr has an invalid value,
			 *      the function LinTp_Transmit shall raise the development error
			 *      code LINIF_E_PARAM_POINTER.
			 */
			checkStatus = LinTp_TransmitCheckPoint(PduInfoPtr,LINTP_SID_TRANSMIT);
			if((Std_ReturnType)E_OK == checkStatus)
			{
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */
				/**
				 * @req [SWS_LinIf_00576]If development error detection is enabled
				 *      and the parameter  TxPduId has an invalid value, the
				 *      function LinTp_Transmit shall raise the
				 *      development error code LINIF_E_PARAMETER.
				 */
				checkStatus = LinTp_CheckTxPduId(TxPduId,LINTP_SID_TRANSMIT,&u16ChIdex);
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
				if((Std_ReturnType)E_OK == checkStatus)
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */
				{
					checkStatus = LinTp_Call_Transmit(u16ChIdex,PduInfoPtr);
				}
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
			}
		}
	}
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */

	return checkStatus;
}

#if(LINTP_VERSION_INFO_API == STD_ON)
/**
 * @sid              0x42
 * @brief            Returns the version information of this module.
 * @details          This function returns the vendor id, module id,
 *                   major, minor and patch version.
 * @param[out]       versioninfo  Pointer to where to store the version
 *                                information of this module.
 * @return           None.
 *
 */
FUNC(void,LINIF_CODE)LinTp_GetVersionInfo
(
	P2VAR(Std_VersionInfoType, AUTOMATIC, LINIF_APPL_DATA) versioninfo
)
{
#if(LINIF_PARAM_CHECK == STD_ON)
  if(NULL_PTR == versioninfo)
  {
	  /**
	   * @req [SWS_LinIf_00639] If development error detection is enabled and the parameter
	   *      versioninfo has an invalid value, the function LinTp_GetVersionInfo shall raise the
	   *      development error code LINIF_E_PARAM_POINTER.
	   */

      LinIf_ReportDetError(LINTP_SID_GETVERSIONINFO , LINIF_E_PARAM_POINTER);
  }
  else
#endif /* LINIF_PARAM_CHECK == STD_ON */
  {
      versioninfo->vendorID = (uint16) LINIF_VENDOR_ID;
      versioninfo->moduleID = (uint16) LINIF_MODULE_ID;
      versioninfo->sw_major_version = (uint8) LINIF_SW_MAJOR_VERSION;
      versioninfo->sw_minor_version = (uint8) LINIF_SW_MINOR_VERSION;
      versioninfo->sw_patch_version = (uint8) LINIF_SW_PATCH_VERSION;
  }
}
#endif /* LINTP_VERSION_INFO_API == STD_ON */

/**
 * @sid              0x43
 * @brief            Shutdowns the LIN TP.
 * @details          The function LinTp_Shutdown shall close all pending transport
 *                   protocol connection of the LIN TP and free all resources of the LIN TP.
 * @param[in]       None
 * @return           None
 */
FUNC(void,LINIF_CODE)LinTp_Shutdown(void)
{
  VAR(uint16, AUTOMATIC) u16ChIdex ;
  P2VAR(LinIf_SlaveTpRunCfgType,AUTOMATIC,LINIF_APPL_DATA) chPtr ;

#if(LINIF_DEV_ERROR_DETECT == STD_ON)
  VAR(Std_ReturnType,AUTOMATIC) checkStatus  = (Std_ReturnType)E_NOT_OK ;
  /* Checks whether LinIf can be initialized normally */
  checkStatus = LinIf_HLDChecksEntry(LINTP_SID_SHUTDOWN);
  if((Std_ReturnType)E_OK == checkStatus)
  {
	  /* Checks whether LinTp can be initialized normally */
	  checkStatus = LinTp_HLDChecksEntry(LINTP_SID_SHUTDOWN);
	  if((Std_ReturnType)E_OK == checkStatus)
	  {
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */
		  /* Reset all of the LinTp Channel. */
		  /**
		   * @req [SWS_LinIf_00356] The function LinTp_Shutdown shall close all pending
		   *      transport protocol connection of the LIN TP and free all resources of the LIN TP.
		   * @req [SWS_LinIf_00433] The function LinTp_Shutdown shall affect all configured
		   *      channels.
		   * @req [SWS_LinIf_00484]The function LinTp_Shutdown shall set the LIN TP state of all
		   *      channels to LINTP_UNINIT.
		   *
		   * Caveats: The LIN Interface has to be initialized with a call of LinIf_Init and
		   *      LinTp_Init before this API service may be called, see [SRS_BSW_00487].
		   */
		 for(u16ChIdex = 0U ; u16ChIdex< LINTP_MAX_CHANNEL_NUM ; u16ChIdex++)
		 {
			 chPtr = &LinTp_SlaveRunCfg[u16ChIdex];
			 LinTp_ResetChannel(chPtr);
		 }
		 (void)LinTp_eStatus;
		 LinTp_eStatus = LINTP_UNINIT;
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
	  }
  }
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */
}

#if (LINTP_CHANGE_PARAMETER_API == STD_ON)
/**
 * @sid              0x4b
 * @brief            This is a dummy method introduced for interface compatibility.
 * @details          The cancellation request shall always be rejected by returning E_NOT_OK.
 * @param[in]        id:  Identification of the PDU which the parameter change shall affect.
 *                   parameter:  ID of the parameter that shall be changed.
 *                   value:  The new value of the parameter.
 * @return           Std_ReturnType
 *                   E_NOT_OK :  Cancellation request of the transfer of the specified Lin N-SDU is rejected.
 */
FUNC(Std_ReturnType,LINIF_CODE)LinTp_ChangeParameter
(
    VAR(PduIdType,AUTOMATIC) id,
    VAR(TPParameterType,AUTOMATIC) parameter,
    VAR(uint16,AUTOMATIC) value
)
{
	VAR(Std_ReturnType,AUTOMATIC) retStatus  = (Std_ReturnType)E_NOT_OK ;

#if(LINIF_DEV_ERROR_DETECT == STD_ON)
	VAR(Std_ReturnType,AUTOMATIC) checkStatus  = (Std_ReturnType)E_NOT_OK ;
	/* Checks whether LinIf can be initialized normally */
	checkStatus = LinIf_HLDChecksEntry(LINTP_SID_CHANGEPARAMETER);
	if((Std_ReturnType)E_OK == checkStatus)
	{
	  /* Checks whether LinTp can be initialized normally */
	  checkStatus = LinTp_HLDChecksEntry(LINTP_SID_CHANGEPARAMETER);
	  if((Std_ReturnType)E_OK == checkStatus)
	  {
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */
		  /**
		   * @req [SWS_LinIf_00592]The change parameter request shall always be rejected by
		   *      returning E_NOT_OK.
		   *
		   * @req [SWS_LinIf_00578] If development error detection is enabled and the parameter
		   *      id has an invalid value, the function LinTp_ChangeParameter shall raise the
		   *      development error code LINIF_E_PARAMETER.
		   *
		   * Caveats: The LIN Interface has to be initialized with a call of LinIf_Init and
		   *      LinTp_Init before this API service may be called, [SRS_BSW_00487].
		   */
		  retStatus = (Std_ReturnType)E_NOT_OK ;
#if(LINIF_DEV_ERROR_DETECT == STD_ON)
	   }
	}
#endif /* LINIF_DEV_ERROR_DETECT == STD_ON */

	return retStatus;
}
#endif /* LINTP_CHANGE_PARAMETER_API == STD_ON */
#endif /* LINIF_TP_SUPPORTED == STD_ON */

/**
 * @sid              0x80
 * @brief            The main processing function of the LIN Interface/LinTp
 * @details
 * @param[in]        None
 * @return           None
 */
FUNC(void,LINIF_CODE) LinIf_MainFunction(void)
{

	VAR(uint16,AUTOMATIC) u16Loop;
	for(u16Loop = 0U; u16Loop< LINIF_MAX_SLAVE_CHANNEL_NUM; u16Loop++)
	{
		LinIf_TimeHandle(u16Loop);
	}
#if(LINIF_TP_SUPPORTED == STD_ON)
		LinTp_SlaveMainFunction();
#endif /* LINIF_TP_SUPPORTED == STD_ON */
}

#ifdef __cplusplus
}
#endif
/** @} */
