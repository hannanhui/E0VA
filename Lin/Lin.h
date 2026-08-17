/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Lin.h
 *  @Syntax          : GNU99
 *  @Author          : ChipON AE/FAE Group
 *  @Date            : 2025-08-29
 *  @Version         : V1.0.0_SF
 *  @Description     : This document describes the C language document template.
 ******************************************************************************
 *  Copyright (C) by Shanghai ChipON Micro-Electronic Co.,Ltd
 *  All rights reserved.
 *
 *  This software is copyright protected and proprietary to
 *  Shanghai ChipON Micro-Electronic Co.,Ltd.
 ******************************************************************************
 *                        REVISION HISTORY
 ******************************************************************************
 *  |Date        |Version  |Author       |Description
 ******************************************************************************
 *  |2025-08-29  |V1.0     |Wang Ning    |New creat
 *****************************************************************************/
#ifndef LIN_H
#define LIN_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 **                        MISRA-C Rules Violations
 ******************************************************************************/
/**
 * @page misra_violations MISRA-C:2004 violations
 *
 * @section
 */

/******************************************************************************
 **                        QAC Warnings
 ******************************************************************************/
/**
 * @page QAC Warnings
 *
 */

/******************************************************************************
 **                        Include Files
 ******************************************************************************/
#include "EcuM.h"
#include "Lin_Cfg.h"
#include "Lin_GeneralTypes.h"

/******************************************************************************
 **                        File Version Check
 ******************************************************************************/
#define LIN_VENDOR_ID   (0xCCU)
#define LIN_MODULE_ID   (82U)
#define LIN_INSTANCE_ID (0U)

#define LIN_SW_MAJOR_VERSION (1U)
#define LIN_SW_MINOR_VERSION (0U)
#define LIN_SW_PATCH_VERSION (0U)
/******************************************************************************
 **                        Macro  Definitions
 ******************************************************************************/

/**
 * @brief LIN Module states
 * @details The state LIN_UNINIT means that the Lin module has not been initialized yet and cannot be used.
 */
#define LIN_UNINIT (0x01U)

/**
 * @brief LIN Module states
 * @details The LIN_INIT state indicates that the LIN driver has been initialized, making each available channel ready
 * for service.
 */
#define LIN_INIT (0x02U)

/**
 * @brief Development Errors
 * @implements #SWS_Lin_00048
 */
/** @brief API service used without module initialization Default LIN_E_UNINIT 0x00 API service used with service. */
#define LIN_E_UNINIT (0x00U)
/** @brief API service used with an invalid or inactive channel parameter service. */
#define LIN_E_INVALID_CHANNEL (0x02U)
/** @brief API service called with invalid configuration pointer service. */
#define LIN_E_INVALID_POINTER (0x03U)
/** @brief Invalid state transition for the current state service. */
#define LIN_E_STATE_TRANSITION (0x04U)
/** @brief API service called with a NULL pointer service. */
#define LIN_E_PARAM_POINTER (0x05U)
/** @brief Timeout caused by hardware error service. */
#define LIN_E_TIMEOUT (0x0C)

/**
 * @brief API Service ID for Lin_Init
 */
#define LIN_INIT_ID (0x00U)

/**
 * @brief API Service ID for Lin_Checkup
 */
#define LIN_CHECKWAKEUP_ID (0x0aU)

/**
 * @brief API Service ID for Lin_GetVersionInfo
 */
#define LIN_GETVERSIONINFO_ID (0x01U)

/**
 * @brief API Service ID for Lin_SendFrame
 */
#define LIN_SENDFRAME_ID (0x04U)

/**
 * @brief API Service ID for Lin_GotoSleep
 */
#define LIN_GOTOSLEEP_ID (0x06U)

/**
 * @brief API Service ID for Lin_GotoSleepInternal
 */
#define LIN_GOTOSLEEPINTERNAL_ID (0x09U)

/**
 * @brief API Service ID for Lin_Wakeup
 */
#define LIN_WAKEUP_ID (0x07U)

/**
 * @brief API Service ID for Lin_WakeupInternal
 */
#define LIN_WAKEUPINTERNAL_ID (0x0bU)

/**
 * @brief API Service ID for Lin_GetStatus
 */
#define LIN_GETSTATUS_ID (0x08U)

/**
 * @brief API Service ID for Lin_GetStatus
 */
#define LIN_DEINIT_ID (0x50U)

/**
 * @brief LIN Channel states
 * @details go-to-sleep-command has been issued on the bus, LIN channel stay at this state until Lin_GetStatus() is
 * called
 */
#define LIN_CH_SLEEP_PENDING ((uint8)0x01U)

/**
 * @brief LIN Channel states
 * @details The detection of a wake-up pulse is enabled. The LIN hardware is into a low power mode if such a mode is
 * provided by the hardware.
 */
#define LIN_CH_SLEEP_STATE ((uint8)0x02U)

/**
 * @brief LIN Channel states
 * @details The individual channel has been initialized (using at least one statically configured data set) and is able
 * to participate in the LIN cluster.
 */
#define LIN_CH_OPERATIONAL ((uint8)0x03U)

/**
 * @brief LIN Channel states
 * @details The individual channel is not ready to process a frame.
 */
#define LIN_CH_NOT_READY_STATE ((uint8)0x04U)

/**
 * @brief LIN Channel states
 * @details The individual channel is ready to process a frame.
 */
#define LIN_CH_READY_STATE ((uint8)0x05U)

/**
 * @brief LIN Channel states
 * @details LIN frame was sent; no errors.
 */
#define LIN_TX_COMPLETE_STATE ((uint8)0x06U)

/**
 * @brief LIN Channel states
 * @details LIN frame was received; no errors.
 */
#define LIN_RX_COMPLETE_STATE ((uint8)0x07U)

/**
 * @brief LIN Channel states
 * @details State after the LIN frame header was correctly sent.
 */
#define LIN_CH_RECEIVE_NOTHING_STATE ((uint8)0x08U)

/**
 * @brief LIN Channel states
 * @details LIN frame is receiving.
 */
#define LIN_RX_ONGOING_STATE ((uint8)0x09U)

/**
 * @brief LIN Channel states
 * @details LIN header is transmission.
 */
#define LIN_TX_HEADER_COMPLETE_STATE ((uint8)0x10U)

/**
 * @brief Interrupt Errors conditions
 * @details No error occurred on a channel.
 */
#define LIN_NO_ERROR ((uint8)0x00U)

/**
 * @brief Interrupt Errors conditions
 * @details Bit error on a channel:
 *  - During response field transmission (Slave and Master modes);
 *  - During header transmission (in Master mode).
 */
#define LIN_BIT_ERROR ((uint8)0x01U)

/**
 * @brief Interrupt Errors conditions
 * @details Checksum error on a channel.
 */
#define LIN_CHECKSUM_ERROR ((uint8)0x02U)

/**
 * @brief Interrupt Errors conditions
 * @details Inconsistent Synch Field.
 */
#define LIN_SYNCH_FIELD_ERROR ((uint8)0x03U)

/**
 * @brief Interrupt Errors conditions
 * @details Break Delimiter too short (< 1 bit).
 */
#define LIN_BREAK_DELIMITER_ERROR ((uint8)0x04U)

/**
 * @brief Interrupt Errors conditions
 * @details Parity error.
 */
#define LIN_IDENTIFIER_PARITY_ERROR ((uint8)0x05U)

/**
 * @brief Interrupt Errors conditions
 * @details Invalid stop bit:
 *          - During reception of any data in the
 *            response field (Slave and Master modes);
 *          - During reception of Synch or Identifier
 *            Field (Slave mode).
 */
#define LIN_FRAMING_ERROR ((uint8)0x06U)

/**
 * @brief Interrupt Errors conditions
 * @details New data byte is received on a channel
 *          and the buffer full flag is not cleared.
 */
#define LIN_BUFFER_OVER_RUN_ERROR ((uint8)0x07U)

/**
 * @brief Interrupt Errors conditions
 * @details Noise detected on a received character.
 */
#define LIN_FRAME_ERROR ((uint8)0x08U)

/**
 * @brief Interrupt Errors conditions
 * @details Header or Response timeout detected.
 */
#define LIN_TIMEOUT_ERROR ((uint8)0x09U)

/**
 * @brief Interrupt Errors conditions
 * @details Shifter was ready to load new data from SHIFTBUF
 *          before new data had been written into SHIFTBUF.
 */
#define LIN_BUFFER_UNDER_RUN_ERROR ((uint8)0x0AU)

/**
 * @brief Commands IDs
 * @details Tx frame is a master frame (response is provided by master).
 */
#define LIN_TX_MASTER_RES_COMMAND ((uint8)0x01U)

/**
 * @brief Commands IDs
 * @details Tx frame is a slave frame (response is provided by slave).
 */
#define LIN_TX_SLAVE_RES_COMMAND ((uint8)0x02U)

/**
 * @brief Commands IDs
 * @details Tx frame is a sleep command frame.
 */
#define LIN_TX_SLEEP_COMMAND ((uint8)0x03U)

/**
 * @brief Commands IDs
 * @details No tx master command pending.
 */
#define LIN_TX_NO_COMMAND ((uint8)0x04U)

/**
 * @brief Commands IDs
 * @details Tx frame is a slave frame.
 */
#define LIN_TX_SLAVE_TO_SLAVE_COMMAND ((uint8)0x05U)

/**
 * @brief dma enable or disable
 */
#define LIN_DMA_DISABLE ((uint8)0U)
#define LIN_DMA_ENABLE  ((uint8)1U)
/******************************************************************************
 **                        Typedef  Definitions
 ******************************************************************************/
#if (LIN_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
/**
 * @brief Typedef for DEM error management implemented by Lin drivers
 */
typedef struct
{
    /** @brief Lin Dem event ID */
    uint32 id;
    /** @brief Lin Dem event Status */
    uint8 state;
} Lin_DemErrorType;
#endif

/** @brief USART MODEL*/
/* PRQA S 3205 ++ #KQR003205 */
typedef enum
{
    LIN_MODULE_USART0,
    LIN_MODULE_USART1,
    LIN_MODULE_USART2,
    LIN_MODULE_USART3,
    LIN_MODULE_USART6,
    LIN_MODULE_NUM
} Lin_UsartModuleType;

/**
 * @brief clock source
 */
typedef enum
{
    /** @brief SCLK */
    LIN_CLOCK_SCLK,
    /** @brief HFCLK */
    LIN_CLOCK_HFCLK
} Lin_ClockSourceType;

/**
 * @brief the LIN channel mode
 */
typedef enum
{
    LIN_CHANNEL_SLAVE_MODE,
    LIN_CHANNEL_MASTER_MODE
} Lin_ChannelModeType;

/**
 * @brief dma source
 */
typedef enum
{
    /** @brief dma0 channel1 */
    LIN_DMA0_CHANNEL_1,
    /** @brief dma channel2 */
    LIN_DMA0_CHANNEL_2,
    /** @brief dma channel3 */
    LIN_DMA0_CHANNEL_3,
    /** @brief dma channel4 */
    LIN_DMA0_CHANNEL_4,
    /** @brief dma channel5 */
    LIN_DMA0_CHANNEL_5,
    /** @brief dma channel6 */
    LIN_DMA0_CHANNEL_6,
    /** @brief dma channel7 */
    LIN_DMA0_CHANNEL_7,
    /** @brief dma1 channel1 */
    LIN_DMA1_CHANNEL_1,
    /** @brief dma1 channel2 */
    LIN_DMA1_CHANNEL_2,
    /** @brief dma1 channel3 */
    LIN_DMA1_CHANNEL_3,
    /** @brief dma1 channel4 */
    LIN_DMA1_CHANNEL_4,
    /** @brief dma1 channel5 */
    LIN_DMA1_CHANNEL_5,
    /** @brief dma1 channel6 */
    LIN_DMA1_CHANNEL_6,
    /** @brief dma1 channel7 */
    LIN_DMA1_CHANNEL_7
} Lin_DmaSourceType;

/* PRQA S 3205 -- #KQR003205 */
#if LIN_SLAVE_MODE_USED == STD_ON
/**
 * @brief the LIN Tx confirmation callback
 */
typedef Std_ReturnType (*Lin_CbkHeaderIndication)(NetworkHandleType Channel, Lin_PduType *PduPtr);
#endif
/**
 * @brief the LIN Tx confirmation callback
 */
typedef void (*Lin_CbkTxConfirmation)(NetworkHandleType Channel);
/**
 * @brief the LIN rx indication callback
 */
typedef void (*Lin_CbkRxIndication)(NetworkHandleType Channel, uint8 *Lin_SduPtr);

/**
 * @brief dma config information
 */
/* PRQA S 3630 ++ #KQR003630 */
typedef struct
{
    /** @brief lin dma switch */
    const uint8 ReceiveDmaSwitch;
    /** @brief lin dma switch */
    const uint8 SendDmaSwitch;
    /** @brief lin send dma source */
    const Lin_DmaSourceType TxDmaSource;
    /** @brief lin receive dma source */
    const Lin_DmaSourceType RxDmaSource;
} Lin_DmaSourceConfigType;

/**
 * @brief LIN channel configuration type structure.
 * @details This is the type of the external data structure containing
 *          the overall initialization data for one LIN Channel.
 *          A pointer to such a structure is provided to the LIN channel
 *          initialization routine for configuration of the LIN hardware
 *          channel.
 * @implements #SWS_Lin_00201
 */
typedef struct
{
    /** @brief LIN Hardware Module */
    Lin_UsartModuleType HwModule;
    /** @brief LIN Channel Mode */
    Lin_ChannelModeType ChannelMode;
    /** baudrate clock source select */
    Lin_ClockSourceType ClockSelect;
    /** @brief Is wake-up supported by the LIN channel ? */
    uint8 ChannelWakeupSupport;
    /** @brief This parameter contains a reference to the Wakeup Source for
     *  this controller as defined in the ECU State Manager.*/
    EcuM_WakeupSourceType ChannelEcuMWakeupSource;
    /** @brief baud integer*/
    uint16 BaudInteger;
    /** @brief baudrate numerator */
    uint8 BaudNumerator;
    /** @brief baudrate denominator */
    uint8 BaudDenom;
    /** @brief lin dma source config */
    const Lin_DmaSourceConfigType *DmaConfigPtr;
} Lin_ChannelCfgType;

/**
 * @brief LIN driver configuration type structure.
 * @implements #SWS_Lin_00227,#SWS_Lin_00045
 */
typedef struct
{
    /** @brief channel number */
    uint8 ChannelNum;
    /** @brief Lin Channel config */
    Lin_ChannelCfgType *ChannelPtr;
#if LIN_SLAVE_MODE_USED == STD_ON
    /**
     * @brief Tx confirmation callback
     */
    Lin_CbkTxConfirmation TxConfirmationCallback;
    /**
     * @brief rx indication callback
     */
    Lin_CbkRxIndication RxIndicationCallback;
    /**
     * @brief receive a frame header callback
     */
    Lin_CbkHeaderIndication HeaderIndicationCallback;
#endif
} Lin_ConfigType;
/* PRQA S 3630 -- #KQR003630 */
/******************************************************************************
 **                        Export Variables
 ******************************************************************************/

/******************************************************************************
 **                        Export Functions
 ******************************************************************************/

/******************************************************************************
 * Function Name   : Lin_Init
 *
 * Service ID   : 0x00
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Non Reentrant
 *
 * Parameters(in)   : ConfigPtr   Pointer to LIN driver configuration set.
 *
 * Parameters(inout)   : None
 *
 * Parameters(out)   : None
 *
 * Return value   : None
 *
 * Description   : Initializes the LIN module.
 *                 SWS_Lin_00008,SWS_Lin_00190,SWS_Lin_00099,SWS_Lin_00105
 *                 SWS_Lin_00084,SWS_Lin_00150,SWS_Lin_00106
 *
 ******************************************************************************/
FUNC(void, LIN_CODE) Lin_Init(const Lin_ConfigType *Config);

/******************************************************************************
 * Function Name   : Lin_DeInit
 *
 * Service ID   : 0x50
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Non Reentrant
 *
 * Parameters(in)   : None
 *
 * Parameters(inout)   : None
 *
 * Parameters(out)   : None
 *
 * Return value   : None
 *
 * Description   : Deinitialize the LIN module.
 *
 ******************************************************************************/
FUNC(void, LIN_CODE) Lin_DeInit(void);

/******************************************************************************
 * Function Name   : Lin_CheckWakeup
 *
 * Service ID   : 0x0a
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Non Reentrant
 *
 * Parameters(in)   : Channel   LIN channel to be addressed.
 *
 * Parameters(inout)   : None
 *
 * Parameters(out)   : None
 *
 * Return value   : Std_ReturnType
 *                      E_OK:No error has occurred during execution of the API
 *                      E_NOT_OK: An error has occurred during execution of the API
 *
 * Description   : This function checks if a wakeup has occurred on the addressed.
 *                  LIN channel.
 *                  SWS_Lin_00098, SWS_Lin_00251,SWS_Lin_00107
 ******************************************************************************/
FUNC(Std_ReturnType, LIN_CODE) Lin_CheckWakeup(uint8 Channel);

#if (LIN_VERSION_INFO_API == STD_ON)
/******************************************************************************
 * Function Name   : Lin_GetVersionInfo
 *
 * Service ID   : 0x01
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Reentrant
 *
 * Parameters(in)   : Channel   LIN channel to be addressed.
 *
 * Parameters(inout)   : None
 *
 * Parameters(out)   : versioninfo   Pointer to where is stored the version
 *                                   information of this module.
 *
 * Return value   : None
 *
 * Description   : Returns the version information of this module.
 *                 SWS_Lin_00001,SWS_Lin_00248
 ******************************************************************************/
FUNC(void, LIN_CODE) Lin_GetVersionInfo(Std_VersionInfoType *VersionInfo);
#endif

/******************************************************************************
 * Function Name   : Lin_SendFrame
 *
 * Service ID   : 0x04
 *
 * Sync/Async   : Asynchronous
 *
 * Reentrancy   : Non Reentrant
 *
 * Parameters(in)   : Channel   LIN channel to be addressed.
 *                  : PduInfoPtr Pointer to PDU containing the PID,checksum
 *                               module,response type,DI and SDU data pointer
 * Parameters(inout) : None
 *
 * Parameters(out)   : None
 *
 * Return value   : Std_ReturnType
 *                        E_OK:Send command has been accepted
 *                        E_NOT_OK: Send command has not been accepted,
 *                                  development or production error occurred
 *
 * Description   : Sends a LIN header and a LIN response, if necessary. The direction of the frame
 *                 response (master response, slave response, slave-to-slave
 *                 communication) is provided by the PduInfoPtr.
 *                 SWS_Lin_00192,SWS_Lin_00194,SWS_Lin_00195,
 *                 SWS_Lin_00197,SWS_Lin_00198,SWS_Lin_00199
 ******************************************************************************/
FUNC(Std_ReturnType, LIN_CODE) Lin_SendFrame(uint8 Channel, const Lin_PduType *PduInfoPtr);

/******************************************************************************
 * Function Name   : Lin_GoToSleep
 *
 * Service ID   : 0x06
 *
 * Sync/Async   : Asynchronous
 *
 * Reentrancy   : Non Reentrant
 *
 * Parameters(in)   : Channel   LIN channel to be addressed.
 *
 * Parameters(inout)   : None
 *
 * Parameters(out)   : None
 *
 * Return value   : Std_ReturnType
 *                      E_OK:Sleep command has been accepted
 *                      E_NOT_OK: Sleep command has not been accepted,development
 *                                or production error occurred.
 *
 * Description   : The service instructs the driver to transmit a go-to-sleep-command
 *                 on the addressed LIN channel.
 *                 SWS_Lin_00089,SWS_Lin_00266,SWS_Lin_00129,SWS_Lin_00131
 ******************************************************************************/
FUNC(Std_ReturnType, LIN_CODE) Lin_GoToSleep(uint8 Channel);

/******************************************************************************
 * Function Name   : Lin_GoToSleepInternal
 *
 * Service ID   : 0x09
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Non Reentrant
 *
 * Parameters(in)   : Channel   LIN channel to be addressed.
 *
 * Parameters(inout)   : None
 *
 * Parameters(out)   : None
 *
 * Return value   : Std_ReturnType
 *                      E_OK: Command has been accepted
 *                      E_NOT_OK: Command has not been accepted,development
 *                                or production error occurred.
 *
 * Description  : Sets the channel state to LIN_CH_SLEEP, enables the wake-up detection and
 *                optionally sets the LIN hardware unit to reduced power operation mode (if
 *                supported by HW).
 *                 SWS_Lin_00222,SWS_Lin_00095,SWS_Lin_00133,SWS_Lin_00135
 ******************************************************************************/
FUNC(Std_ReturnType, LIN_CODE) Lin_GoToSleepInternal(uint8 Channel);

/******************************************************************************
 * Function Name   : Lin_Wakeup
 *
 * Service ID   : 0x07
 *
 * Sync/Async   :Asynchronous
 *
 * Reentrancy   : Non Reentrant
 *
 * Parameters(in)   : Channel   LIN channel to be addressed.
 *
 * Parameters(inout)   : None
 *
 * Parameters(out)   : None
 *
 * Return value   : Std_ReturnType
 *                      E_OK: Wake-up request has been accepted
 *                      E_NOT_OK: Wake-up request has not been accepted,
 *                                development or production error occurred
 *
 * Description  : Generates a wake up pulse and sets the channel state to
 *                LIN_CH_OPERATIONAL.
 *                SWS_Lin_00137,SWS_Lin_00139,SWS_Lin_00140
 ******************************************************************************/
FUNC(Std_ReturnType, LIN_CODE) Lin_Wakeup(uint8 Channel);

/******************************************************************************
 * Function Name   : LIN_WakeupInternal
 *
 * Service ID   : 0x0b
 *
 * Sync/Async   :Asynchronous
 *
 * Reentrancy   : Non Reentrant
 *
 * Parameters(in)   : Channel   LIN channel to be addressed.
 *
 * Parameters(inout)   : None
 *
 * Parameters(out)   : None
 *
 * Return value   : Std_ReturnType
 *                      E_OK: Wake-up request has been accepted
 *                      E_NOT_OK: Wake-up request has not been accepted,
 *                                development or production error occurred
 *
 * Description  : Sets the channel state to LIN_CH_OPERATIONAL without generating a wake up
 *                pulse.
 *                SWS_Lin_00257,SWS_Lin_00258,SWS_Lin_00259,SWS_Lin_00260
 ******************************************************************************/
FUNC(Std_ReturnType, LIN_CODE) Lin_WakeupInternal(uint8 Channel);

/******************************************************************************
 * Function Name   : Lin_GetStatus
 *
 * Service ID   : 0x08
 *
 * Sync/Async   :Synchronous
 *
 * Reentrancy   : Non Reentrant
 *
 * Parameters(in)   : Channel   LIN channel to be addressed.
 *
 * Parameters(inout)   : None
 *
 * Parameters(out)   : Lin_SduPtr  Pointer to pointer to a shadow buffer or memory mapped LIN
 *                     Hardware receive buffer where the current SDU is stored.
 *
 * Return value   : Lin_StatusType
 *                     LIN_NOT_OK: Development or production error occurred
 *                     LIN_TX_OK: Successful transmission LIN_TX_BUSY: Ongoing t
 *                                (Header or Response)
 *                     LIN_TX_HEADER_ERROR: Erroneous header transmission
 *                     LIN_TX_ERROR: Erroneous response transmission
 *                     LIN_RX_OK: Reception of correct response
 *                     LIN_RX_BUSY: Ongoing reception: at least one
 *                                 response byte has been received, but the checksum
 *                                    has not been received
 *                     LIN_RX_ERROR: Erroneous response reception
 *                     LIN_RX_NO_RESPONSE: No response byte has been
 *                                        received so far LIN_OPERATIONAL: Norma
 *                                        LIN channel is woken up from the LIN_C
 *                                         been sent. LIN_CH_SLEEP: Sleep state
 *                                        detection from slave nodes is enabled.
 *
 * Description  :Gets the status of the LIN driver..
 *               SWS_Lin_00091,SWS_Lin_00200,SWS_Lin_00092,SWS_Lin_00238
 *               SWS_Lin_00141,SWS_Lin_00143,SWS_Lin_00144
 ******************************************************************************/
FUNC(Lin_StatusType, LIN_CODE) Lin_GetStatus(uint8 Channel, uint8 **Lin_SduPtr);

#ifdef __cplusplus
}
#endif

#endif
/* EOF */
