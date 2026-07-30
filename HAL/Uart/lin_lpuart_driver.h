/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      H source file                                                            */
/*   Name         :      lin_lpuart_driver.h                                                      */
/*   Instance     :                                                                               */
/*   Author       :      Ed                                                                       */
/*   Modify date  :      2025-12-22 14:00:05 PM                                                   */
/*   Description  :                                                                               */
/*                                                                                                */
/*                                                                                                */
/*   Compiler    :       KungFu32 IDE  [Version: V1.0.20.3]                                       */
/*   Hardware    :       ChipOn microcontroller KF32A Family [KF32A156MQV]                        */
/*   Version     :       V1.0                                                                     */
/*                                                                                                */
/*                                                                                                */
/*   All rights reserved. Distribution or duplication without previous written agreement of the   */
/*   owner prohibited.                                                                            */
/*                                                                                                */
/**************************************************************************************************/
/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * Copyright 2016 - 2018 NXP
 * All rights reserved.
 *
 * THIS SOFTWARE IS PROVIDED BY NXP "AS IS" AND ANY EXPRESSED OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL NXP OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

/*!
 * @file lin_lpuart_driver.h
 */

#ifndef LIN_LPUART_DRIVER_H
#define LIN_LPUART_DRIVER_H

/* *****************************************************************************
 * Includes
 ******************************************************************************/
#include "lpuart_hw_access.h"
//#include "clock_manager.h"
#include "..\LIN\lin_driver.h"
#include "model_Cfg_feature.h"
/* *****************************************************************************
 * Definitions
 ******************************************************************************/


/*! @brief Table to save LPUART state structure pointers */
extern lin_state_t * g_linStatePtr[LPUART_INSTANCE_COUNT];

/*! @brief Table to save LIN user config structure pointers */
extern lin_user_config_t * g_linUserconfigPtr[LPUART_INSTANCE_COUNT];



/* *****************************************************************************
 * LPUART API
 ******************************************************************************/






/* *****************************************************************************
 * API
 ******************************************************************************/
#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Initializes an LIN_LPUART instance for LIN Network.
 *
 * The caller provides memory for the driver state structures during initialization.
 * The user must select the LIN_LPUART clock source in the application to initialize the LIN_LPUART.
 * This function initializes a LPUART instance for operation.
 * This function will initialize the run-time state structure to keep track of
 * the on-going transfers, initialize the module to user defined settings and
 * default settings, set break field length to be 13 bit times minimum, enable
 * the break detect interrupt, Rx complete interrupt, frame error detect interrupt,
 * and enable the LPUART module transmitter and receiver
 *
 * @param instance LIN_LPUART instance number
 * @param linUserConfig user configuration structure of type #lin_user_config_t
 * @param linCurrentState pointer to the LIN_LPUART driver state structure
 * @return operation status:
 *         - STATUS_SUCCESS : Operation was successful.
 *         - STATUS_ERROR   : Operation failed due to semaphores initialize error.
 */
status_t LIN_LPUART_DRV_Init(uint32_t instance,
                             lin_user_config_t * linUserConfig,
                             lin_state_t * linCurrentState);

/*!
 * @brief Shuts down the LIN_LPUART by disabling interrupts and transmitter/receiver.
 *
 * @param instance LIN_LPUART instance number
 * @return void
 */
void LIN_LPUART_DRV_Deinit(uint32_t instance);

/*!
 * @brief Initializes the LIN user configuration structure with default values.
 *
 * This function initializes a configuration structure received from the application
 * with default values.
 * Note: Users shall assign measurement callback function pointer that is timerGetTimeIntervalCallback
 * for linUserConfig. Users can see detail in doxygen.
 *
 * @param[in] isMaster Node function:
                - true if node is MASTER
                - false if node is SLAVE
 * @param[out] linUserConfig the default configuration
 * @return void
 */
void LIN_LPUART_DRV_GetDefaultConfig(bool isMaster,
                                     lin_user_config_t * linUserConfig);

/*!
 * @brief Installs callback function that is used for LIN_LPUART_DRV_IRQHandler.
 *
 * @note After a callback is installed, it bypasses part of the LIN_LPUART IRQHandler logic.
 * Therefore, the callback needs to handle the indexes of txBuff and txSize.
 *
 * @param instance The LIN_LPUART instance number.
 * @param function The LIN_LPUART receive callback function.
 * @return Former LIN callback function pointer.
 */
lin_callback_t LIN_LPUART_DRV_InstallCallback(uint32_t instance,
                                              lin_callback_t function);



/*!
 * @brief Sends frame data out through the LIN_LPUART module using non-blocking method.
 *  This enables an a-sync method for transmitting data.
 *  Non-blocking  means that the function returns immediately.
 *  The application has to get the transmit status to know when the transmit is complete.
 *  This function will calculate the checksum byte and send it with the frame data.
 *  If txSize is equal to 0 or greater than 8 or node's current state is in SLEEP mode
 *  then the function will return STATUS_ERROR. If isBusBusy is currently true then the
 *  function will return STATUS_BUSY.
 *
 * @param instance LIN_LPUART instance number
 * @param txBuff  source buffer containing 8-bit data chars to send
 * @param txSize  the number of bytes to send
 * @return operation status:
 *         - STATUS_SUCCESS : The transmission is successful.
 *         - STATUS_BUSY    : Operation failed due to isBusBusy is currently true.
 *         - STATUS_ERROR   : Operation failed due to txSize is equal to 0 or greater than 8
 *                            or node's current state is in SLEEP mode
 */
status_t LIN_LPUART_DRV_SendFrameData(uint32_t instance,
                                      const uint8_t * txBuff,
                                      uint8_t txSize);

/*!
 * @brief Get status of an on-going non-blocking transmission
 *  While sending frame data using non-blocking method, users can
 *  use this function to get status of that transmission.
 *  This function return STATUS_BUSY while sending, or STATUS_TIMEOUT
 *  if timeout has occurred, or return STATUS_SUCCESS when the transmission is complete.
 *  The bytesRemaining shows number of bytes that still needed to transmit.
 *
 * @param instance LIN_LPUART instance number
 * @param bytesRemaining  Number of bytes still needed to transmit
 * @return operation status:
 *         - STATUS_SUCCESS : The transmission is successful.
 *         - STATUS_BUSY    : The transmission is sending
 *         - STATUS_TIMEOUT : Operation failed due to timeout has occurred.
 */
status_t LIN_LPUART_DRV_GetTransmitStatus(uint32_t instance,
                                          uint8_t * bytesRemaining);

/*!
 * @brief Receives frame data through the LIN_LPUART module using non-blocking method.
 *  This function returns immediately after initiating the receive function.
 *  The application has to get the receive status to see when the receive is complete.
 *  The interrupt handler LIN_LPUART_DRV_IRQHandler will check the checksum byte.
 *  If the checksum is correct, it will receive the frame data.
 *  If the checksum is incorrect, this function will return STATUS_TIMEOUT and data in
 *  rxBuff might be wrong. This function also check if rxSize is in range from 1 to 8.
 *  If not, it will return STATUS_ERROR. This function also returns STATUS_ERROR if
 *  node's current state is in SLEEP mode. This function checks if the isBusBusy is
 *  false, if not it will return STATUS_BUSY.
 *
 * @param instance LIN_LPUART instance number
 * @param rxBuff  buffer containing 8-bit received data
 * @param rxSize the number of bytes to receive
 * @return operation status:
 *         - STATUS_SUCCESS : The receives frame data is successful.
 *         - STATUS_TIMEOUT : The checksum is incorrect.
 *         - STATUS_BUSY    : Bus busy flag is true.
 *         - STATUS_ERROR   : Operation failed due is equal to 0 or greater than 8 or
 *                            node's current state is in SLEEP mode
 */
status_t LIN_LPUART_DRV_RecvFrmData(uint32_t instance,
                                    uint8_t * rxBuff,
                                    uint8_t rxSize);

/*!
 * @brief Aborts an on-going non-blocking transmission/reception.
 *  While performing a non-blocking transferring data, users can call this function
 *  to terminate immediately the transferring.
 *
 * @param instance LIN_LPUART instance number
 * @return function always return STATUS_SUCCESS
 */
status_t LIN_LPUART_DRV_AbortTransferData(uint32_t instance);

/*!
 * @brief Get status of an on-going non-blocking reception
 *  While receiving frame data using non-blocking method, users can
 *  use this function to get status of that receiving.
 *  This function return the current event ID, STATUS_BUSY while receiving
 *  and return STATUS_SUCCESS, or timeout (STATUS_TIMEOUT) when the reception is complete.
 *  The bytesRemaining shows number of bytes that still needed to receive.
 *
 * @param instance LIN_LPUART instance number
 * @param bytesRemaining  Number of bytes still needed to receive
 * @return operation status:
 *         - STATUS_SUCCESS : The reception is complete.
 *         - STATUS_TIMEOUT : The reception isn't complete.
 *         - STATUS_BUSY    : The reception is on going
 */
status_t LIN_LPUART_DRV_GetReceiveStatus(uint32_t instance,
                                         uint8_t * bytesRemaining);

/*!
 * @brief This function puts current node to sleep mode
 * This function changes current node state to LIN_NODE_STATE_SLEEP_MODE
 *
 * @param instance LIN_LPUART instance number
 * @return function always return STATUS_SUCCESS
 */
status_t LIN_LPUART_DRV_GoToSleepMode(uint32_t instance);

/*!
 * @brief Puts current LIN node to Idle state
 * This function changes current node state to LIN_NODE_STATE_IDLE
 *
 * @param instance LIN_LPUART instance number
 * @return function always return STATUS_SUCCESS
 */
status_t LIN_LPUART_DRV_GotoIdleState(uint32_t instance);

/*!
 * @brief Sends a wakeup signal through the LIN_LPUART interface
 *
 * @param instance LIN_LPUART instance number
 * @return operation status:
 *         - STATUS_SUCCESS : Bus busy flag is false.
 *         - STATUS_BUSY    : Bus busy flag is true.
 */
status_t LIN_LPUART_DRV_SendWakeupSignal(uint32_t instance);

/*!
 * @brief Get the current LIN node state
 *
 * @param instance LIN_LPUART instance number
 * @return current LIN node state
 */
lin_node_state_t LIN_LPUART_DRV_GetCurrentNodeState(uint32_t instance);

/*!
 * @brief Callback function for Timer Interrupt Handler
 * Users shall initialize a timer (for example FTM) in Output compare mode
 * with period of 500 micro seconds. In timer IRQ handler, call this function.
 *
 * @param instance LIN_LPUART instance number
 * @return void
 */
void LIN_LPUART_DRV_TimeoutService(uint32_t instance);

/*!
 * @brief Set Value for Timeout Counter that is used in LIN_LPUART_DRV_TimeoutService
 *
 * @param instance LPUART instance number
 * @param timeoutValue  Timeout Value to be set
 * @return void
 */
void LIN_LPUART_DRV_SetTimeoutCounter(uint32_t instance,
                                      uint32_t timeoutValue);

/*!
 * @brief Enables LIN_LPUART hardware interrupts.
 *
 * @param instance LIN_LPUART instance number.
 * @return function always return STATUS_SUCCESS.
 */
status_t LIN_LPUART_DRV_EnableIRQ(uint32_t instance);

/*!
 * @brief Disables LIN_LPUART hardware interrupts.
 *
 * @param instance LIN_LPUART instance number.
 * @return function always return STATUS_SUCCESS.
 */
status_t LIN_LPUART_DRV_DisableIRQ(uint32_t instance);

/*!
 * @brief LIN_LPUART interrupt handler for RX_TX and Error interrupts.
 *
 * @param instance LIN_LPUART instance number
 * @return void
 */
void LIN_LPUART_DRV_RX_IRQHandler(uint32_t instance);
void LIN_LPUART_DRV_BREAK_IRQHandler(uint32_t instance);
void LIN_LPUART_DRV_TX_IRQHandler(uint32_t instance);

#if defined(__cplusplus)
}
#endif

#endif /* LIN_LPUART_DRIVER_H */
/* ****************************************************************************/
/* EOF */
/* ****************************************************************************/
