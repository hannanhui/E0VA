/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Lin_Im.h
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
#ifndef LIN_IM_H
#define LIN_IM_H

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
/* PRQA S 0791 EOF #KQR000791 */
/******************************************************************************
 **                        Include Files
 ******************************************************************************/
#include "Lin.h"

/******************************************************************************
 **                        File Version Check
 ******************************************************************************/

/******************************************************************************
 **                        Macro  Definitions
 ******************************************************************************/
/**
 * @brief Total number of available hardware LPUART channels.
 */
#define LIN_USART_MAX_MODULES 4U

/**
 * @brief Maximum Length of Data.
 *
 */
#define USART_MAX_DATA_LENGTH ((uint8)LIN_MAX_DATA_LENGTH)

/**
 * @brief Maximum Length of Buffer (Sync(1), Pid(1), Data bytes and
 * Checksum(1)).
 *
 */
#define USART_MAX_BUFFER_LENGTH ((uint8)LIN_MAX_DATA_LENGTH + (uint8)3U)

/**
 * @brief Master Request Diagnostic Frame ID 0x3C.
 *
 */
#define USART_MASTER_REQUEST_DIAGNOSTIC_ID ((uint8)0x3CU)

/**
 * @brief Slave Response Diagnostic Frame ID 0x3D.
 *
 */
/**
 * @violates @ref Lin_LPUART_h_REF_2 The compiler/linker shall be checked to
 * ensure that 31 character significance and case sensitivity are supported for
 * external identifiers.
 */
#define USART_SLAVE_RESPONSE_DIAGNOSTIC_ID ((uint8)0x3DU)

/**
 * @brief Master Request Diagnostic Frame PID 0x3C.
 *
 */
/**
 * @violates @ref Lin_LPUART_h_REF_2 The compiler/linker shall be checked to
 * ensure that 31 character significance and case sensitivity are supported for
 * external identifiers.
 */
#define USART_MASTER_REQUEST_DIAGNOSTIC_PID ((uint8)0x3CU)

/**
 * @brief Slave Response Diagnostic Frame PID 0x7D.
 *
 */
#define USART_SLAVE_RESPONSE_DIAGNOSTIC_PID ((uint8)0x7DU)

/**
 * @brief Synch byte value.
 *
 */
#define USART_SYNC_BYTE ((uint8)0x55U)
/**
 * @brief The position of Synch byte in Lin_LPUART_au8BytesToSend buffer.
 *
 */
#define USART_SYNCH_BYTE_OFFSET ((uint8)0U)

/**
 * @brief The position of PID byte in Lin_LPUART_au8BytesToSend buffer.
 *
 */
#define USART_PID_BYTE_OFFSET ((uint8)1U)

/**
 * @brief The position of PID byte in Lin_LPUART_au8BytesToSend buffer.
 *
 */
#define USART_FRAME_ID_MASK ((uint32)0x3FU)

/**
 * @brief The position of PID byte in Lin_LPUART_au8BytesToSend buffer.
 *
 */
#define USART_DATA_OFFSET ((uint8)2U)

/**
 * @brief Sleep command length frame.
 *
 */
#define USART_DATA_LENGTH_8 ((uint32)8U)

/**
 * @brief Sleep command frame: 0xFF data.
 *
 */
#define USART_DATA_255 ((uint8)255U)

/**
 * @brief Sleep command frame: 0x00 data.
 *
 */
#define USART_DATA_0 ((uint8)0U)

/******************************************************************************
 **                        Typedef  Definitions
 ******************************************************************************/

/******************************************************************************
 **                        Export Variables
 ******************************************************************************/

/******************************************************************************
 **                        Export Functions
 ******************************************************************************/
/**
 * @brief Deinitialize, clear variables
 *
 * @param ChCfgPtr channel config pointer
 * @return void
 * @retval void
 */
FUNC(void, LIN_CODE) Lin_Im_DeinitDataClear(Lin_ChannelCfgType const *ChCfgPtr);

/**
 * @brief Initialize a LIN channel.
 * @details This function initializes all hardware registers needed to start the LIN functionality on the selected
 * channel.
 * @param ChCfgPtr channel config pointer
 * @return void
 * @retval void
 */
FUNC(void, LIN_CODE) Lin_Im_UsartInitChannel(Lin_ChannelCfgType const *ChCfgPtr);

/**
 * @brief Deinitialize a LIN channel.
 * @details This function deinitialize all hardware registers of the lin channel.
 * @param ChCfgPtr channel config pointer
 * @return void
 * @retval void
 */
FUNC(void, LIN_CODE) Lin_Im_UsartDeInitChannel(Lin_ChannelCfgType const *ChCfgPtr);

/**
 * @brief Check if a LIN channel has been waked-up.
 * @param Channel LIN channel to be waked-up.
 * @return Std_ReturnType.
 * @retval TRUE If the LIN Channel has the wake up flag set.
 * @retval FALSE Otherwise.
 */
FUNC(Std_ReturnType, LIN_CODE) Lin_Im_UsartCheckWakeup(uint8 Channel);

/**
 * @brief Sends the header part of the LIN frame.
 * @param Channel LIN channel to be addressed.
 * @param PduInfoPtr pointer to PDU containing the PID, Checksum model,Response type, Dl and SDU data pointer.
 * @return Std_ReturnType.
 * @retval E_NOT_OK In case of a time out situation only.
 * @retval E_OK Otherwise.
 */
FUNC(Std_ReturnType, LIN_CODE) Lin_Im_UsartSendHeader(uint8 Channel, const Lin_PduType *PduInfoPtr);

/**
 * @brief Sends the response part of the LIN frame.
 * @param Channel LIN channel to be addressed.
 * @param PduInfoPtr pointer to PDU containing the PID, Checksum model,Response type, Dl and SDU data pointer.
 * @return void
 * @retval void
 */
FUNC(void, LIN_CODE) Lin_Im_UsartSendResponse(uint8 Channel, Lin_PduType const *PduInfoPtr);

/**
 * @brief Prepares and send a go-to-sleep-command frame on Channel.
 * @details This function stops any ongoing transmission and initiates the transmission of the sleep command (master
 * command frame with id = 0x3C and data = (0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF).
 * @param Channel LIN channel to be addressed.
 * @return Std_ReturnType
 * @retval E_NOT_OK In case of a time-out situation only.
 * @retval E_OK Otherwise.
 */
FUNC(Std_ReturnType, LIN_CODE) Lin_Im_UsartGoToSleep(uint8 Channel);

/**
 * @brief Same function as Lin_Im_UsartGoToSleepInternal() but without sending a go-to-sleep-command on the bus.
 * @details This function stops any ongoing transmission and put the Channel in sleep mode (then LIN hardware enters a
 * reduced power operation mode).
 * @param Channel LIN channel to be addressed.
 * @return Std_ReturnType
 * @retval E_NOT_OK In case of a time-out situation only
 * @retval E_OK Otherwise
 */
FUNC(Std_ReturnType, LIN_CODE) Lin_Im_UsartGoToSleepInternal(uint8 Channel);

/**
 * @brief Sends a wake up signal to the LIN bus.
 * @details This function shall sent a wake up signal to the LIN bus and put the LIN channel in LIN_CH_OPERATIONAL
 * state.
 * @param Channel LIN channel to be addressed.
 * @return void
 * @retval void
 */
FUNC(void, LIN_CODE) Lin_Im_UsartWakeUp(uint8 Channel);

/**
 * @brief Wake up the LIN channel.
 * @details This function shall put the LIN channel in LIN_CH_OPERATIONAL state without sending a wake up signal to the
 * LIN bus
 * @param Channel LIN channel to be addressed.
 * @return void
 * @retval void
 */
FUNC(void, LIN_CODE) Lin_Im_UsartWakeUpInternal(uint8 Channel);

/**
 * @brief Gets the status of the LIN driver when Channel is operating.
 * @details This function returns the state of the current transmission, reception or operation status. If the reception
 * of a Slave response was successful then this service provides a pointer to the buffer where the data is stored.
 * @param Channel LIN channel to be addressed
 * @param LinSduPtr pointer to pointer to a shadow buffer or memory mapped LIN Hardware receive buffer where the current
 * SDU is stored
 * @return Lin_StatusType
 * @retval LIN_NOT_OK Development or production error raised none of the below conditions.
 * @retval LIN_TX_OK Successful transmission.
 * @retval LIN_TX_BUSY Ongoing transmission of header or response.
 * @retval LIN_TX_HEADER_ERROR Error occurred during header transmission.
 * @retval LIN_TX_ERROR Error occurred during response transmission.
 * @retval LIN_RX_OK Reception of correct response.
 * @retval LIN_RX_BUSY Ongoing reception where at least one byte has been received.
 * @retval LIN_RX_ERROR Error occurred during reception.
 * @retval LIN_RX_NO_RESPONSE No data byte has been received yet.
 * @retval LIN_OPERATIONAL Channel is ready for next header.transmission and no data are available.
 * @retval LIN_CH_SLEEP Channel is in sleep mode.
 */
FUNC(Lin_StatusType, LIN_CODE) Lin_Im_UsartHardwareGetStatus(uint8 Channel, uint8 *LinSduPtr);

#ifdef __cplusplus
}
#endif

#endif
/* EOF */
