/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Uart.h
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
#ifndef UART_H
#define UART_H

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
#include "Std_Types.h"
#include "Uart_Types.h"

/******************************************************************************
 **                        File Version Check
 ******************************************************************************/
/** @brief Uart MODULE INSTANCE ID */
#define UART_MODULE_ID (255)
/** @brief Uart Vendor ID */
#define UART_VENDOR_ID (0xCCU)

/**
 * @brief Uart module software version
 */
#define UART_SW_MAJOR_VERSION (1)
#define UART_SW_MINOR_VERSION (0)
#define UART_SW_PATCH_VERSION (1)
/******************************************************************************
 **                        Macro  Definitions
 ******************************************************************************/

/******************************************************************************
 **                        Typedef  Definitions
 ******************************************************************************/

/******************************************************************************
 **                        Export Variables
 ******************************************************************************/

/******************************************************************************
 **                        Export Functions
 ******************************************************************************/
/******************************************************************************
 * Function Name   : Uart_Init
 *
 * Service ID   :
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Non Reentrant
 *
 * Parameters(in)   : UartConfigPtr - Pointer to UART driver configuration set.
 *
 * Parameters(inout)   : None
 *
 * Parameters(out)   : None
 *
 * Return value   : None
 *
 * Description   :  Initializes the UART module.
 *
 ******************************************************************************/
void Uart_Init(const Uart_ConfigType *ConfigPtr);
/******************************************************************************
 * Function Name   : Uart_Deinit
 *
 * Service ID   :
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
 * Description   : De-initializes the UART module.This function performs software de-initialization of UART driver.
 *
 ******************************************************************************/
void Uart_Deinit(void);

/******************************************************************************
 * Function Name   : Uart_SyncSend
 *
 * Service ID   :
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Non Reentrant
 *
 * Parameters(in)   : Channel - Uart channel to be addressed
 * Buffer - The buffer which contains the bytes to be sent.
 * BufferSize - The Buffer size.
 *
 * Parameters(inout)   : None
 *
 * Parameters(out)   : None
 *
 * Return value   : Std_ReturnType
 * E_OK Successful transfer.
 * E_NOT_OK If the Uart Channel is not valid or Uart driver is not initialized or Buffer is a NULL_PTR or
 * BufferSize is 0, meaning no space has been allocated for the buffer or a transfer is already on going on the
 * requested channel or timeout occurred.
 *
 * Description   : Starts a synchronous transfer of bytes.This function starts sending a number of bytes in a
 *synchronous manner.
 *
 ******************************************************************************/
Std_ReturnType Uart_SyncSend(uint8 Channel, const uint8 *Buffer, uint16 BufferSize, uint32 Timeout);

/******************************************************************************
 * Function Name   : Uart_AsyncSend
 *
 * Service ID   :
 *
 * Sync/Async   : Async
 *
 * Reentrancy   : Non Reentrant
 *
 * Parameters(in)   : Channel - Uart channel to be addressed
 * Buffer - The buffer where the data to be sent is located.
 * BufferSize - The Buffer size.
 *
 * Parameters(inout)   : None
 *
 * Parameters(out)   : None
 *
 * Return value   : Std_ReturnType
 * E_OK The transfer(send) started successfully.
 * E_NOT_OK If the Uart Channel is not valid or Uart driver is not initialized or Buffer is a NULL_PTR or
 * BufferSize is 0, meaning no space has been allocated for the buffer or a transfer(send) is already on going on the
 * requested channel.
 *
 * Description   : Starts an asynchronous transfer(send) of bytes.This function starts sending a number of bytes in an
 *asynchronous manner. The transfer can be performed using either DMA or interrupts depending on the transfer type
 *configured on the addressed channel.
 *
 ******************************************************************************/
Std_ReturnType Uart_AsyncSend(uint8 Channel, const uint8 *Buffer, uint16 BufferSize);

/******************************************************************************
 * Function Name   : Uart_AsyncPollingSend
 *
 * Service ID   :
 *
 * Sync/Async   : Async
 *
 * Reentrancy   : Non Reentrant
 *
 * Parameters(in)   : Channel - Uart channel to be addressed
 * Buffer - The buffer where the data to be sent is located.
 * BufferSize - The Buffer size.
 *
 * Parameters(inout)   : None
 *
 * Parameters(out)   : None
 *
 * Return value   : Std_ReturnType
 * E_OK The transfer(send) started successfully
 * E_NOT_OK If the Uart Channel is not valid or Uart driver is not initialized or Buffer is a NULL_PTR or
 * BufferSize is 0 or DMA not enabled or a transfer(send) is already on going on the requested channel.
 *
 * Description   : Starts an asynchronous polling transfer(send) of bytes.This function starts sending a number of bytes
 *in an asynchronous polling manner. The transfer can only be performed using DMA, and no interrupt should be opened.
 *
 ******************************************************************************/
Std_ReturnType Uart_AsyncPollingSend(uint8 Channel, const uint8 *Buffer, uint16 BufferSize);

/******************************************************************************
 * Function Name   : Uart_GetAsyncPollingSendStatus
 *
 * Service ID   :
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Non Reentrant
 *
 * Parameters(in)   : Channel - Uart channel to be addressed
 *
 * Parameters(inout)   : None
 *
 * Parameters(out)   : None
 *
 * Return value   : Std_ReturnType
 * E_NOT_OK the sending process is on going.
 * E_OK The sending process is done or not started.
 *
 * Description   : Gets an asynchronous polling transfer(send) state.This function gets the status of an an asynchronous
 *polling sending process.
 *
 ******************************************************************************/
Std_ReturnType Uart_GetAsyncPollingSendStatus(uint8 Channel);

/******************************************************************************
 * Function Name   : Uart_SyncReceive
 *
 * Service ID   :
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Non Reentrant
 *
 * Parameters(in)   : Channel - Uart channel to be addressed
 * Buffer -  The buffer where the bytes will be located.
 * BufferSize - The Buffer size.
 * Timeout - The timeout in us.
 *
 * Parameters(inout)   : None
 *
 * Parameters(out)   : None
 *
 * Return value   : Std_ReturnType
 * E_NOT_OK If the Uart Channel is not valid or Uart driver is not initialized or Buffer is a NULL_PTR or
 * BufferSize is 0, meaning no space has been allocated for the buffer or a reception is already on going on the
 * requested channel or timeout occurred.
 * E_OK Successful reception.
 *
 * Description   : Starts a synchronous reception of bytes.This function starts receiving a number of bytes in a
 *synchronous manner.
 *
 ******************************************************************************/
Std_ReturnType Uart_SyncReceive(uint8 Channel, uint8 *Buffer, uint16 BufferSize, uint32 Timeout);

/******************************************************************************
 * Function Name   : Uart_AsyncReceive
 *
 * Service ID   :
 *
 * Sync/Async   : Async
 *
 * Reentrancy   : Non Reentrant
 *
 * Parameters(in)   : Channel - Uart channel to be addressed
 * Buffer -  The buffer where the data to be received will located.
 * BufferSize - The Buffer size;if BufferSize == 0U, it means the size of the data to be received is not certain,UART
 *will receive until a idle frame
 *
 * Parameters(inout)   : None
 *
 * Parameters(out)   : None
 *
 * Return value   : Std_ReturnType
 * E_NOT_OK If the Uart Channel is not valid or Uart driver is not initialized or Buffer is a NULL_PTR or BufferSize is
 *0, meaning no space has been allocated for the buffer or a transfer(receive) is already on going on the requested
 *channel.
 * E_OK The transfer(receive) started successfully.
 *
 * Description   : Starts an asynchronous transfer(receive) of bytes.This function starts receiving a number of bytes in
 *an asynchronous manner. The transfer can be performed using either DMA or interrupts depending on the transfer type
 *configured on the addressed channel.
 *
 ******************************************************************************/
Std_ReturnType Uart_AsyncReceive(uint8 Channel, uint8 *Buffer, uint16 BufferSize);

/******************************************************************************
 * Function Name   : Uart_Abort
 *
 * Service ID   :
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Reentrant
 *
 * Parameters(in)   : Channel - Uart channel to be addressed
 * TransmissionType -  Type of the transfer to be aborted. It can be either UART_SEND or UART_RECEIVE.
 *
 * Parameters(inout)   : None
 *
 * Parameters(out)   : None
 *
 * Return value   : Std_ReturnType
 * E_NOT_OK If the Uart Channel is not valid or Uart driver is not initialized.
 * E_OK Successful transfer aborted or in case no transfer was on going.
 *
 * Description   : Aborts an on-going transfer.
 *
 ******************************************************************************/
Std_ReturnType Uart_Abort(uint8 Channel, Uart_DataDirectionType TransmissionType);

/******************************************************************************
 * Function Name   : Uart_GetBusStatus
 *
 * Service ID   :
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Reentrant
 *
 * Parameters(in)   : Channel - Uart channel to be addressed
 * TransferType -  The type of transfer in discussion (UART_SEND or UART_RECEIVE)
 *
 * Parameters(inout)   : None
 *
 * Parameters(out)   : None
 *
 * Return value   : Uart_StatusType
 * UART_STATUS_OPERATION_IDLE - No transferring process exists.
 * UART_STATUS_OPERATION_ONGOING - transferring operation is on going.
 *
 * Description   : Returns the status of the previous transfer.
 *
 ******************************************************************************/
Uart_StatusType Uart_GetBusStatus(uint8 Channel, Uart_DataDirectionType TransferType);

#if (UART_VERSION_INFO_API == STD_ON)
/******************************************************************************
 * Function Name   : Uart_GetVersionInfo
 *
 * Service ID   :
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Reentrant
 *
 * Parameters(in)   : None
 *
 * Parameters(inout)   : None
 *
 * Parameters(out)   : VersionInfo - Pointer to where to store the version information of this module
 *
 * Return value   : None
 *
 * Description   : Returns the version information of this module
 *
 ******************************************************************************/
void Uart_GetVersionInfo(Std_VersionInfoType *VersionInfo);
#endif

#ifdef __cplusplus
}
#endif

#endif
/* EOF */
