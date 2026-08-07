/**
 * @file        LinIf_PBCfg.c
 * @brief       Post-build configuration file for LinIf.
 * @version     1.0.0
 * @addtogroup LinIF
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
#include "Com_Cfg.h"
#include "Lin.h"
//#include "LinSM_Cbk.h"
#include "PduR_LinIf.h"

/* 应用层桥接函数声明（LinIf → LinApp 数据通路） */
extern void LinApp_Rx_Bridge(PduIdType RxPduId, const PduInfoType* PduInfoPtr);
extern Std_ReturnType LinApp_TxTrigger_Bridge(PduIdType TxPduId, PduInfoType* PduInfoPtr);
extern void LinApp_TxConfirm_Bridge(PduIdType TxPduId);

/*====================================================================================================*
 *                                  SOURCE FILE VERSION INFORMATION                                 
 *====================================================================================================*/

#define LINIF_PBCFG_VENDOR_ID_C                            0U
#define LINIF_PBCFG_AR_RELEASE_MAJOR_VERSION_C             4U
#define LINIF_PBCFG_AR_RELEASE_MINOR_VERSION_C             2U
#define LINIF_PBCFG_AR_RELEASE_REVISION_VERSION_C          2U
#define LINIF_PBCFG_SW_MAJOR_VERSION_C                     1U
#define LINIF_PBCFG_SW_MINOR_VERSION_C                     0U
#define LINIF_PBCFG_SW_PATCH_VERSION_C                     0U

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
 * @brief Define API Function pointer table for multiple LIN drivers.
 */
CONST(LinIf_LinDriverApiCfgType,LINIF_CONST)LINIF_API_TABLE[1] =
{
    {
        /**< @brief Validates for upper layers the wake up of LIN channel.. */
        &Lin_CheckWakeup,

        /**< @brief Sends a LIN frame.. */
        NULL_PTR,

        /**< @brief The service instructs the driver to transmit a
         * 	go-to-sleep-command on the addressed LIN channel.
         */
        NULL_PTR,

        /**< @brief Put a Lin channel in the internal sleep state.. */
        &Lin_GoToSleepInternal,

        /**< @brief Generates a wake up pulse.. */
        &Lin_Wakeup,

        /**< @brief Wake up the LIN channel.. */
        &Lin_WakeupInternal,

        /**< @brief Gets the status of the LIN driver.. */
        NULL_PTR
    }
};



/**
 * @brief LinIf LinIfChannel_0 Channels  Frames Configuration.
 */
CONST(LinIf_FrameCfgType,LINIF_CONST) LinIf_LinIfChannel_0_Frames[6];


/**
 * @brief LinIf Channels Rx Frames Configuration.
 */
/**
 * @brief LinIf LinIfChannel_0 Channels LinFrame_ZCU_SMM_1_Rx Rx Pdu Configuration.
 */
CONST(LinIf_RxPduCfgType,LINIF_CONST) LinIf_LinIfChannel_0_LinFrame_ZCU_SMM_1_Rx_RxPdu =
{
    /**
     *  @brief This parameter defines the upper layer (UL) module to which
     *         the indication of the successfully received LinIfRxPdu has to be routed via
     *         User_RxIndication
     */
     (LinIf_ULModuleType)LINIF_CDD,

    /**
     *  @brief This parameter defines the name of the User_RxIndication
     */
    &LinApp_Rx_Bridge,

    /**
     *  @brief Reference to the PDU that is received in this frame.
     */
     PduRConf_PduRSrcPdu_LinPdu_LinIfToPduR_ZCU_SMM_1_Rx
};
/**
 * @brief LinIf LinIfChannel_0 Channels LinFrame_ZCU_SMM_2_Rx Rx Pdu Configuration.
 */
CONST(LinIf_RxPduCfgType,LINIF_CONST) LinIf_LinIfChannel_0_LinFrame_ZCU_SMM_2_Rx_RxPdu =
{
    /**
     *  @brief This parameter defines the upper layer (UL) module to which
     *         the indication of the successfully received LinIfRxPdu has to be routed via
     *         User_RxIndication
     */
     (LinIf_ULModuleType)LINIF_CDD,

    /**
     *  @brief This parameter defines the name of the User_RxIndication
     */
    &LinApp_Rx_Bridge,

    /**
     *  @brief Reference to the PDU that is received in this frame.
     */
     PduRConf_PduRSrcPdu_LinPdu_LinIfToPduR_ZCU_SMM_2_Rx
};
/**
 * @brief LinIf LinIfChannel_0 Channels LinFrame_MasterReq_Rx Rx Pdu Configuration.
 */
CONST(LinIf_RxPduCfgType,LINIF_CONST) LinIf_LinIfChannel_0_LinFrame_MasterReq_Rx_RxPdu =
{
    /**
     *  @brief This parameter defines the upper layer (UL) module to which
     *         the indication of the successfully received LinIfRxPdu has to be routed via
     *         User_RxIndication
     */
     (LinIf_ULModuleType)LINIF_PDUR,

    /**
     *  @brief This parameter defines the name of the User_RxIndication
     */
    NULL_PTR,

    /**
     *  @brief Reference to the PDU that is received in this frame.
     */
     PduRConf_PduRSrcPdu_LinPdu_LinTpToPduR_MasterReq_Rx
};
/**
 * @brief LinIf LinIfChannel_0 Channels LinIf_Function_Rx Rx Pdu Configuration.
 */
CONST(LinIf_RxPduCfgType,LINIF_CONST) LinIf_LinIfChannel_0_LinIf_Function_Rx_RxPdu =
{
    /**
     *  @brief This parameter defines the upper layer (UL) module to which
     *         the indication of the successfully received LinIfRxPdu has to be routed via
     *         User_RxIndication
     */
     (LinIf_ULModuleType)LINIF_PDUR,

    /**
     *  @brief This parameter defines the name of the User_RxIndication
     */
    NULL_PTR,

    /**
     *  @brief Reference to the PDU that is received in this frame.
     */
     PduRConf_PduRSrcPdu_LinPdu_LinTpToPduR_FuncReq_Rx
};

/**
 * @brief LinIf Channels Tx Frames Configuration.
 */
/**
 * @brief LinIf LinIfChannel_0 Channels LinFrame_DSMM_1_Tx Tx Pdu Configuration.
 */
CONST(LinIf_TxPduCfgType,LINIF_CONST) LinIf_LinIfChannel_0_LinFrame_DSMM_1_Tx_TxPdu =
{
	/**
	 *  @brief This parameter defines the upper layer (UL) module to which the trigger
	 *         of the transmitted LinTxPdu User_TriggerTransmit
	 *         the confirmation of the successfully transmitted LinTxPdu has to be routed
	 *         User_TxConfirmation
	 */
     (LinIf_ULModuleType)LINIF_CDD,

	/**
	 *  @brief his parameter defines the name of the User_TxConfirmation
	 */
    &LinApp_TxConfirm_Bridge,

	/**
	 *  @brief Identifier of the Pdu for the upper layer.
	 */
     0,

	/**
	 *  @brief his parameter defines the name of the User_TriggerTransmit
	 */
	 &LinApp_TxTrigger_Bridge,

    /**
	 *  @brief Reference to the PDU that is transmitted in this frame.
	 */
	 PduRConf_PduRDestPdu_LinPdu_PduRToLinIf_DSMM_1_Tx,
};
/**
 * @brief LinIf LinIfChannel_0 Channels LinFrame_SlaveResp_Tx Tx Pdu Configuration.
 */
CONST(LinIf_TxPduCfgType,LINIF_CONST) LinIf_LinIfChannel_0_LinFrame_SlaveResp_Tx_TxPdu =
{
	/**
	 *  @brief This parameter defines the upper layer (UL) module to which the trigger
	 *         of the transmitted LinTxPdu User_TriggerTransmit
	 *         the confirmation of the successfully transmitted LinTxPdu has to be routed
	 *         User_TxConfirmation
	 */
     (LinIf_ULModuleType)LINIF_PDUR,

	/**
	 *  @brief his parameter defines the name of the User_TxConfirmation
	 */
    NULL_PTR,

	/**
	 *  @brief Identifier of the Pdu for the upper layer.
	 */
     0,

	/**
	 *  @brief his parameter defines the name of the User_TriggerTransmit
	 */
	 NULL_PTR,

    /**
	 *  @brief Reference to the PDU that is transmitted in this frame.
	 */
	 PduRConf_PduRDestPdu_LinPdu_PduRToLinTp_SlaveResp_Tx,
};

/**
 * @brief LinIf Channels Frames Configuration.
 */
/**
 * @brief LinIf LinIfChannel_0 Channels  Frames Configuration.
 */
CONST(LinIf_FrameCfgType,LINIF_CONST) LinIf_LinIfChannel_0_Frames[6] =
{
    {
    	/**
         *  @brief Type of checksum that the frame is using.
         */
         (LinIf_ChecksumType)LINIF_ENHANCED,

        /**
         *  @brief ID of the LIN frame. The Protected ID including parity
         *         is calculated by the generation tool.
         */
         (uint8)0xaU,

        /**
         *  @brief Protection ID identifier calculated by the tool.
         */
         (uint8)0xcaU,

        /**
         *  @brief PID index of the frame. This index is used in the
         *         AssignFrameIdentifierRange node configuration service to
         *         identify the frame(s) to which a new PID shall be assigned.
         */
         (uint8)0U,

        /**
         *  @brief Index value of the LIN frame Length.
         */
         (uint8)8U,

        /**
         *  @brief Index value of the LIN frame in the PID table.
         */
        (uint16)0U,

        /**
         *  @brief Index value of the LIN frame in the PID table.
         */
         (boolean)TRUE,

        /**
         *  @brief This parameter defines the type of frame (e.g. sporadic frame).
         */
         (LinIf_FrameType)LINIF_UNCONDITIONAL,

        /**
         *  @brief In case this is a fixed frame this is the SDU (response).
         *         This container represents an eight byte array.
         *         The Byte order shall be MSB first.
         */
         NULL_PTR,

        /**
         *  @brief Direction of the frame.
         */
        LINIF_TX_PDU,

        /**
         *  @brief represents a received PDU/frame
         */
         NULL_PTR,

         /**
         *  @brief represents a transmitted PDU/frame
         */
         &LinIf_LinIfChannel_0_LinFrame_DSMM_1_Tx_TxPdu,

        /**
         *  @brief The maximum number of associated unconditional frames.
         */
         (uint16)0U,

        /**
         *  @brief Reference to an unconditional Frame that is used as
         *         sporadic frame in a master node or event-triggered
         *         frame in a slave node.
         */
        NULL_PTR
    },
    {
    	/**
         *  @brief Type of checksum that the frame is using.
         */
         (LinIf_ChecksumType)LINIF_ENHANCED,

        /**
         *  @brief ID of the LIN frame. The Protected ID including parity
         *         is calculated by the generation tool.
         */
         (uint8)0xcU,

        /**
         *  @brief Protection ID identifier calculated by the tool.
         */
         (uint8)0x4cU,

        /**
         *  @brief PID index of the frame. This index is used in the
         *         AssignFrameIdentifierRange node configuration service to
         *         identify the frame(s) to which a new PID shall be assigned.
         */
         (uint8)1U,

        /**
         *  @brief Index value of the LIN frame Length.
         */
         (uint8)8U,

        /**
         *  @brief Index value of the LIN frame in the PID table.
         */
        (uint16)1U,

        /**
         *  @brief Index value of the LIN frame in the PID table.
         */
         (boolean)FALSE,

        /**
         *  @brief This parameter defines the type of frame (e.g. sporadic frame).
         */
         (LinIf_FrameType)LINIF_UNCONDITIONAL,

        /**
         *  @brief In case this is a fixed frame this is the SDU (response).
         *         This container represents an eight byte array.
         *         The Byte order shall be MSB first.
         */
         NULL_PTR,

        /**
         *  @brief Direction of the frame.
         */
        LINIF_RX_PDU,

        /**
         *  @brief represents a received PDU/frame
         */
         &LinIf_LinIfChannel_0_LinFrame_ZCU_SMM_1_Rx_RxPdu,

         /**
         *  @brief represents a transmitted PDU/frame
         */
         NULL_PTR,

        /**
         *  @brief The maximum number of associated unconditional frames.
         */
         (uint16)0U,

        /**
         *  @brief Reference to an unconditional Frame that is used as
         *         sporadic frame in a master node or event-triggered
         *         frame in a slave node.
         */
        NULL_PTR
    },
    {
    	/**
         *  @brief Type of checksum that the frame is using.
         */
         (LinIf_ChecksumType)LINIF_ENHANCED,

        /**
         *  @brief ID of the LIN frame. The Protected ID including parity
         *         is calculated by the generation tool.
         */
         (uint8)0xeU,

        /**
         *  @brief Protection ID identifier calculated by the tool.
         */
         (uint8)0x8eU,

        /**
         *  @brief PID index of the frame. This index is used in the
         *         AssignFrameIdentifierRange node configuration service to
         *         identify the frame(s) to which a new PID shall be assigned.
         */
         (uint8)2U,

        /**
         *  @brief Index value of the LIN frame Length.
         */
         (uint8)8U,

        /**
         *  @brief Index value of the LIN frame in the PID table.
         */
        (uint16)2U,

        /**
         *  @brief Index value of the LIN frame in the PID table.
         */
         (boolean)FALSE,

        /**
         *  @brief This parameter defines the type of frame (e.g. sporadic frame).
         */
         (LinIf_FrameType)LINIF_UNCONDITIONAL,

        /**
         *  @brief In case this is a fixed frame this is the SDU (response).
         *         This container represents an eight byte array.
         *         The Byte order shall be MSB first.
         */
         NULL_PTR,

        /**
         *  @brief Direction of the frame.
         */
        LINIF_RX_PDU,

        /**
         *  @brief represents a received PDU/frame
         */
         &LinIf_LinIfChannel_0_LinFrame_ZCU_SMM_2_Rx_RxPdu,

         /**
         *  @brief represents a transmitted PDU/frame
         */
         NULL_PTR,

        /**
         *  @brief The maximum number of associated unconditional frames.
         */
         (uint16)0U,

        /**
         *  @brief Reference to an unconditional Frame that is used as
         *         sporadic frame in a master node or event-triggered
         *         frame in a slave node.
         */
        NULL_PTR
    },
    {
    	/**
         *  @brief Type of checksum that the frame is using.
         */
         (LinIf_ChecksumType)LINIF_CLASSIC,

        /**
         *  @brief ID of the LIN frame. The Protected ID including parity
         *         is calculated by the generation tool.
         */
         (uint8)0x3cU,

        /**
         *  @brief Protection ID identifier calculated by the tool.
         */
         (uint8)0x3cU,

        /**
         *  @brief PID index of the frame. This index is used in the
         *         AssignFrameIdentifierRange node configuration service to
         *         identify the frame(s) to which a new PID shall be assigned.
         */
         (uint8)3U,

        /**
         *  @brief Index value of the LIN frame Length.
         */
         (uint8)8U,

        /**
         *  @brief Index value of the LIN frame in the PID table.
         */
        (uint16)3U,

        /**
         *  @brief Index value of the LIN frame in the PID table.
         */
         (boolean)FALSE,

        /**
         *  @brief This parameter defines the type of frame (e.g. sporadic frame).
         */
         (LinIf_FrameType)LINIF_MRF,

        /**
         *  @brief In case this is a fixed frame this is the SDU (response).
         *         This container represents an eight byte array.
         *         The Byte order shall be MSB first.
         */
         NULL_PTR,

        /**
         *  @brief Direction of the frame.
         */
        LINIF_RX_PDU,

        /**
         *  @brief represents a received PDU/frame
         */
         &LinIf_LinIfChannel_0_LinFrame_MasterReq_Rx_RxPdu,

         /**
         *  @brief represents a transmitted PDU/frame
         */
         NULL_PTR,

        /**
         *  @brief The maximum number of associated unconditional frames.
         */
         (uint16)0U,

        /**
         *  @brief Reference to an unconditional Frame that is used as
         *         sporadic frame in a master node or event-triggered
         *         frame in a slave node.
         */
        NULL_PTR
    },
    {
    	/**
         *  @brief Type of checksum that the frame is using.
         */
         (LinIf_ChecksumType)LINIF_CLASSIC,

        /**
         *  @brief ID of the LIN frame. The Protected ID including parity
         *         is calculated by the generation tool.
         */
         (uint8)0x3dU,

        /**
         *  @brief Protection ID identifier calculated by the tool.
         */
         (uint8)0x7dU,

        /**
         *  @brief PID index of the frame. This index is used in the
         *         AssignFrameIdentifierRange node configuration service to
         *         identify the frame(s) to which a new PID shall be assigned.
         */
         (uint8)4U,

        /**
         *  @brief Index value of the LIN frame Length.
         */
         (uint8)8U,

        /**
         *  @brief Index value of the LIN frame in the PID table.
         */
        (uint16)4U,

        /**
         *  @brief Index value of the LIN frame in the PID table.
         */
         (boolean)FALSE,

        /**
         *  @brief This parameter defines the type of frame (e.g. sporadic frame).
         */
         (LinIf_FrameType)LINIF_SRF,

        /**
         *  @brief In case this is a fixed frame this is the SDU (response).
         *         This container represents an eight byte array.
         *         The Byte order shall be MSB first.
         */
         NULL_PTR,

        /**
         *  @brief Direction of the frame.
         */
        LINIF_TX_PDU,

        /**
         *  @brief represents a received PDU/frame
         */
         NULL_PTR,

         /**
         *  @brief represents a transmitted PDU/frame
         */
         &LinIf_LinIfChannel_0_LinFrame_SlaveResp_Tx_TxPdu,

        /**
         *  @brief The maximum number of associated unconditional frames.
         */
         (uint16)0U,

        /**
         *  @brief Reference to an unconditional Frame that is used as
         *         sporadic frame in a master node or event-triggered
         *         frame in a slave node.
         */
        NULL_PTR
    },
    {
    	/**
         *  @brief Type of checksum that the frame is using.
         */
         (LinIf_ChecksumType)LINIF_CLASSIC,

        /**
         *  @brief ID of the LIN frame. The Protected ID including parity
         *         is calculated by the generation tool.
         */
         (uint8)0x3cU,

        /**
         *  @brief Protection ID identifier calculated by the tool.
         */
         (uint8)0x3cU,

        /**
         *  @brief PID index of the frame. This index is used in the
         *         AssignFrameIdentifierRange node configuration service to
         *         identify the frame(s) to which a new PID shall be assigned.
         */
         (uint8)5U,

        /**
         *  @brief Index value of the LIN frame Length.
         */
         (uint8)8U,

        /**
         *  @brief Index value of the LIN frame in the PID table.
         */
        (uint16)5U,

        /**
         *  @brief Index value of the LIN frame in the PID table.
         */
         (boolean)FALSE,

        /**
         *  @brief This parameter defines the type of frame (e.g. sporadic frame).
         */
         (LinIf_FrameType)LINIF_MRF,

        /**
         *  @brief In case this is a fixed frame this is the SDU (response).
         *         This container represents an eight byte array.
         *         The Byte order shall be MSB first.
         */
         NULL_PTR,

        /**
         *  @brief Direction of the frame.
         */
        LINIF_RX_PDU,

        /**
         *  @brief represents a received PDU/frame
         */
         &LinIf_LinIfChannel_0_LinIf_Function_Rx_RxPdu,

         /**
         *  @brief represents a transmitted PDU/frame
         */
         NULL_PTR,

        /**
         *  @brief The maximum number of associated unconditional frames.
         */
         (uint16)0U,

        /**
         *  @brief Reference to an unconditional Frame that is used as
         *         sporadic frame in a master node or event-triggered
         *         frame in a slave node.
         */
        NULL_PTR
    }
};

/**
 * @brief LinIf Channels  Substitution Frames Configuration.
 */

/**
 * @brief LinIf Slave Node Configuration.
 */
/**
 * @brief LinIf LinIfChannel_0 Channels Slave Node Configuration.
 */
CONST(LinIf_SlaveNodeCfgType,LINIF_CONST) LinIf_LinIfChannel_0_SlaveNode =
{
	/**
	 *  @brief Defines the LIN protocol version of the slave node.
	 */
	 (LinIf_LinProtocolVersionType)LINIF_LIN21,

    /**
	 *  @brief Reference to the response_error signal.
	 */
    ComConf_ComSignal_DSMM_Rsp_Error_Tx,

    /**
	 *  @brief Slave node configured NAD.
	 */
	 (uint8)116U,

    /**
	 *  @brief LIN function Id.
	 */
	(uint16)0U,

    /**
	 *  @brief Slave node initial NAD.
	 */
	 (uint8)116U,

    /**
	 *  @brief N_As timeout in cycle.
	 */
    (uint16)1000U,

	/**
	 *  @brief LIN consortium or ISO LIN supplier Id.
	 */
    (uint16)0U,

    /**
	 *  @brief LIN variant Id.
	 */
	 (uint8)0U
};

/**
 * @brief LinIf Channels Configuration.
 */
CONST(LinIf_ChannelConfigCfgType, LINIF_CONST) LinIf_SlaveChannelsConfig[LINIF_MAX_SLAVE_CHANNEL_NUM] =
{
    {
        /**< @brief Bus idle timeout cycle. */
        4000U,

        /**
         *  @brief This parameter defines the upper layer (UL) module
         *         to which the confirmation of the goto-sleep command
         *         shall be sent.
         */
         LINIF_LIN_SM,

         0,

        /**
         *  @brief This parameter defines the upper layer (UL) module
         *         to which the indication of the goto-sleep command
         *         shall be sent.
         */
         LINIF_LIN_SM,

         0,

        /**
         *  @brief Defines the interval of calls to main functions per channel in milliseconds.
         */
         (uint32)1U,

        /**
         *  @brief Maximum number of Frames
         */
         (uint16)0U,

        /**
         *  @brief Enables/disables the switch to a new schedule table at the start of
         *         the next time base after status check.
         */
         (boolean)FALSE,

        /**
         *  @brief This parameter defines the upper layer (UL) module to which the confirmation
         *         of the successfully performed schedule table change shall be sent.
         */
         LINIF_NONE,

         NULL_PTR,

        /**
         *  @brief This parameter defines the upper layer (UL) module to which the confirmation
         *         of the wake-up shall be sent.
         */
         LINIF_LIN_SM,

         0,

        /**
         *  @brief Reference to the CDD module description.
         */
         0xFFU,

         /**< @brief Reference to the channel definition in the LIN driver */
         0,

         /**< @brief Reference Index values belonging to different LIN drivers. */
         0,

         /**< @brief The wake-up source configured for the current channel. */
         0xFFU,

        /**
         *  @brief Unique handle to identify one LIN network. Reference to one of the
         *         network handles configured for the ComM.
         */
        0,

        /**
         *  @brief The maximum number of replacement frames that the channel can have..
         */
         (uint16)0U,

        /**
         *  @brief The maximum number of data frames that the channel can have.
         */
         (uint16)6U,

        /**
         *  @brief The configuration set of data frames that the channel has.
         */
         &LinIf_LinIfChannel_0_Frames[0],

        /**
         *  @brief defines the LIN node type of this channel.
         */
         LINIF_SLAVE_NODE,

        /**
         *  @brief The jitter specifies the differences between the maximum and minimum delay
         *         from time base tick to the header sending start point in milliseconds.
         */
        (uint16)0,

        /**
         * 	@brief Describes all parameters which are only relevant for a LIN Slave node.
         */
        &LinIf_LinIfChannel_0_SlaveNode,

         /**
         *  @brief The maximum number of scheduling tables that the channel can have.
         */
         (uint8)0U,

        /**
         * 	@brief Describes a schedule table. Each LinIfChannel may have several
         *         schedule tables. Each schedule table can only be connected to
         *         one channel.
         */
        NULL_PTR,

#if (LINIF_TRCV_DRIVER_SUPPORTED == STD_ON)
        /**
         *  @brief Logical handle of the underlying LIN transceiver to be served by the LIN Interface.
         */
        0xFFU,

        /**< @brief Reference Index values belonging to different LIN transceiver drivers. */
        0U
#endif /* LINIF_TRCV_DRIVER_SUPPORTED == STD_ON */
    }
};

/**
 * @brief LinIf Configuration.
 */
CONST(LinIf_ConfigType, LINIF_CONST) LinIf_Config =
{
    /**< @brief Total number of configured master node channels. */
    0U,

    /**< @brief Total number of configured slave node channels. */
    1U,

    /**< @brief LIN Driver API table used by LINIF */
    &LINIF_API_TABLE[0],

#if (LINIF_TRCV_DRIVER_SUPPORTED == STD_ON)
    /**< @brief LIN Transceiver Driver API table used by LINIF */
    NULL_PTR,
#endif /* LINIF_TRCV_DRIVER_SUPPORTED == STD_ON */

    /**< @brief Configure the specific parameter information for LinIf Master channles */
    NULL_PTR,

    /**< @brief Configure the specific parameter information for LinIf Slave channles */
    &LinIf_SlaveChannelsConfig[0]
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
