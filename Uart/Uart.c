/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Uart.c
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
/* PRQA S 2814 EOF #KQR002814 */
/* PRQA S 2824 EOF #KQR002824 */
/* PRQA S 2844 EOF #KQR002844 */
/* PRQA S 2201 EOF #KQR002201 */
/* PRQA S 2919 EOF #KQR002919 */
/* PRQA S 2934 EOF #KQR002934 */
/******************************************************************************
 **                        Include Files
 ******************************************************************************/
#include "Uart.h"
#include "Uart_Im.h"
#if (UART_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif

/******************************************************************************
 **                        File Version Check
 ******************************************************************************/

/******************************************************************************
 **                        Macro  Definitions
 ******************************************************************************/

/******************************************************************************
 **                        Typedef  Definitions
 ******************************************************************************/

/******************************************************************************
 **                        Variables
 ******************************************************************************/
/**
 * @brief          UART driver status variable.
 * @details        UART driver initialization status variable.
 */
static Uart_DrvStatusType Uart_DriverStatus = UART_DRV_UNINIT;

/**
 * @brief          Global configuration pointer.
 * @details        Pointer to the configuration structure.
 */
static const Uart_ConfigType *Uart_ConfigPtr = NULL_PTR;
/******************************************************************************
 **                        Export Variables
 ******************************************************************************/
#if (UART_PRECOMPILE_SUPPORT == STD_ON)
extern const Uart_ConfigType Uart_ConfigPredefined;
#endif
/******************************************************************************
 **                        Export Functions
 ******************************************************************************/

/******************************************************************************
 **                      Function definitions
 ******************************************************************************/

/**
 * @brief Initializes the UART module.
 * @details
 * This function performs software initialization of UART driver. It shall configure the Uart hardware peripheral for
 * each channel.
 *
 * Syntax:void Uart_Init(const Uart_ConfigType *ConfigPtr)
 * Service ID:
 * Sync/Async:Synchronous
 * Reentrancy:Non Reentrant
 * @param ConfigPtr Pointer to UART driver configuration set.
 * @return void
 */
void Uart_Init(const Uart_ConfigType *ConfigPtr)
{
    uint8                         loop;
    Uart_ChannelConfigType const *uartConfigPtr;
#if (UART_DEV_ERROR_DETECT == STD_ON)
    Std_ReturnType checkStatus = (Std_ReturnType)E_OK;
#endif

#if (UART_DEV_ERROR_DETECT == STD_ON)
    /* Check whether the Uart driver is in UART_DRV_UNINIT state */
    if (UART_DRV_UNINIT != Uart_DriverStatus)
    {
        /* Uart driver has been already initialized */
        (void)Det_ReportError((uint16)UART_MODULE_ID, (uint8)0, (uint8)UART_INIT_ID, (uint8)UART_E_ALREADY_INITIALIZED);
        checkStatus = E_NOT_OK;
    }
    else
    {
#if (UART_PRECOMPILE_SUPPORT == STD_OFF)
        if (NULL_PTR == ConfigPtr)
#else
        if (NULL_PTR != ConfigPtr)
#endif
        {
            /* Invalid pointer */
            (void)Det_ReportError((uint16)UART_MODULE_ID, (uint8)0, (uint8)UART_INIT_ID, (uint8)UART_E_INIT_FAILED);
            checkStatus = E_NOT_OK;
        }
    }
#endif
#if (UART_DEV_ERROR_DETECT == STD_ON)
    if (E_OK == checkStatus)
    {
#endif
#if (UART_PRECOMPILE_SUPPORT == STD_OFF)
        Uart_ConfigPtr = ConfigPtr;
#else
    Uart_ConfigPtr = &Uart_ConfigPredefined;
    (void)ConfigPtr;
#endif
        for (loop = 0U; loop < Uart_ConfigPtr->UartChannelNum; loop++)
        {
            uartConfigPtr = &(Uart_ConfigPtr->UartChannelConfigPtr[loop]);
            Uart_Im_PreInit(uartConfigPtr->Module, uartConfigPtr);
            Uart_Im_DmaConfig(uartConfigPtr->Module, uartConfigPtr);
            Uart_Im_IntrInit(uartConfigPtr->Module, uartConfigPtr);
            Uart_Im_Enable(uartConfigPtr->Module);
        }
        /* Update UART driver status to UART_DRV_INIT */
        Uart_DriverStatus = UART_DRV_INIT;
#if (UART_DEV_ERROR_DETECT == STD_ON)
    }
#endif
}

/**
 * @brief De-initializes the UART module.
 * @details
 * This function performs software de-initialization of UART driver.
 *
 * Syntax:void Uart_Deinit(void)
 * Service ID:
 * Sync/Async:Synchronous
 * Reentrancy:Non Reentrant
 * @param None
 * @return void
 */
void Uart_Deinit(void)
{
    Uart_ModuleType hwModule;
    uint8           loop;

#if (UART_DEV_ERROR_DETECT == STD_ON)
    boolean isAllChannelsIdle = TRUE;
    /* Check whether the UART driver is in UART_DRV_UNINIT state */
    if (UART_DRV_INIT != Uart_DriverStatus)
    {
        /* Uart driver has been already initialized */
        (void)Det_ReportError((uint16)UART_MODULE_ID, (uint8)0, (uint8)UART_DEINIT_ID, (uint8)UART_E_UNINIT);
    }
    else
    {
        for (loop = 0U; loop < Uart_ConfigPtr->UartChannelNum; loop++)
        {
            hwModule = Uart_ConfigPtr->UartChannelConfigPtr[loop].Module;
            /* Check whether channel is busy sending or receiving */
            /* PRQA S 3415 2 #KQR003415 */
            if ((Uart_Im_GetTransferStatus(hwModule, UART_SEND) == UART_STATUS_BUSY) ||
                (Uart_Im_GetTransferStatus(hwModule, UART_RECEIVE) == UART_STATUS_BUSY))
            {
                isAllChannelsIdle = FALSE;
                break;
            }
            else
            {
                /* Do Nothing */
            }
        }
        /*PRQA S 3344 1 #KQR003344 */
        if (isAllChannelsIdle)
        {
#endif
            /* In case all of setting channel are free */
            for (loop = 0U; loop < Uart_ConfigPtr->UartChannelNum; loop++)
            {
                hwModule = Uart_ConfigPtr->UartChannelConfigPtr[loop].Module;
                /* Disable module */
                Uart_Im_Disable(hwModule);
                /* Deinit module */
                Uart_Im_DeInitDevice(hwModule);
                /*Uart Disable the DMA*/
                Uart_Im_DmaDisable(hwModule);
            }
            Uart_DriverStatus = UART_DRV_UNINIT;
            Uart_ConfigPtr    = NULL_PTR;
#if (UART_DEV_ERROR_DETECT == STD_ON)
        }
    }
#endif
}

/**
 * @brief Starts a synchronous transfer of bytes
 * @details
 * This function starts sending a number of bytes in a synchronous manner.
 *
 * Syntax:Std_ReturnType Uart_SyncSend(uint8 Channel, const uint8 *Buffer, uint16 BufferSize, uint32 Timeout)
 * Service ID:
 * Sync/Async:Synchronous
 * Reentrancy:Non Reentrant
 * @param Channel Uart channel to be addressed
 * @param Buffer The buffer which contains the bytes to be sent.
 * @param BufferSize The Buffer size.
 * @param Timeout The timeout in us.zero for infinite waiting
 * @return Std_ReturnType
 * @retval E_OK Successful transfer.
 * @retval E_NOT_OK If the Uart Channel is not valid or Uart driver is not initialized or Buffer is a NULL_PTR or
 * BufferSize is 0, meaning no space has been allocated for the buffer or a transfer is already on going on the
 * requested channel or timeout occurred.
 */
Std_ReturnType Uart_SyncSend(uint8 Channel, const uint8 *Buffer, uint16 BufferSize, uint32 Timeout)
{
    Std_ReturnType  tempReturn = E_NOT_OK;
    Uart_ModuleType hwModule;

#if (UART_DEV_ERROR_DETECT == STD_ON)
    if (UART_DRV_UNINIT == Uart_DriverStatus)
    {
        (void)Det_ReportError((uint16)UART_MODULE_ID, (uint8)0, (uint8)UART_SYNCSEND_ID, (uint8)UART_E_UNINIT);
    }
    else
    {
        if (Channel >= Uart_ConfigPtr->UartChannelNum)
        {
            (void)Det_ReportError(
              (uint16)UART_MODULE_ID, (uint8)0, (uint8)UART_SYNCSEND_ID, (uint8)UART_E_INVALID_CHANNEL);
        }
        else
        {
            if (NULL_PTR == Buffer)
            {
                (void)Det_ReportError(
                  (uint16)UART_MODULE_ID, (uint8)0, (uint8)UART_SYNCSEND_ID, (uint8)UART_E_INVALID_POINTER);
            }
            else
            {
                if (0U == BufferSize)
                {
                    (void)Det_ReportError(
                      (uint16)UART_MODULE_ID, (uint8)0, (uint8)UART_SYNCSEND_ID, (uint8)UART_E_INVALID_PARAMETER);
                }
                else
                {
#endif
                    hwModule = Uart_ConfigPtr->UartChannelConfigPtr[Channel].Module;
                    if (Uart_Im_SyncSend(hwModule, Buffer, BufferSize, Timeout) == UART_STATUS_OK)
                    {
                        tempReturn = E_OK;
                    }
                    else
                    {
                        /* Do Nothing */
                    }
#if (UART_DEV_ERROR_DETECT == STD_ON)
                }
            }
        }
    }
#endif
    return tempReturn;
}

/**
 * @brief Starts an asynchronous transfer(send) of bytes.
 * @details
 * This function starts sending a number of bytes in an asynchronous manner. The transfer can be performed
 * using either DMA or interrupts depending on the transfer type configured on the addressed channel.
 *
 * Syntax:Std_ReturnType Uart_AsyncSend(uint8 Channel, const uint8 *Buffer, uint16 BufferSize)
 * Service ID:
 * Sync/Async:Async
 * Reentrancy:Non Reentrant
 * @param Channel Uart channel to be addressed
 * @param Buffer The buffer where the data to be sent is located.
 * @param BufferSize The Buffer size.
 * @return Std_ReturnType
 * @retval E_OK The transfer(send) started successfully.
 * @retval E_NOT_OK If the Uart Channel is not valid or Uart driver is not initialized or Buffer is a NULL_PTR or
 * BufferSize is 0, meaning no space has been allocated for the buffer or a transfer(send) is already on going on the
 * requested channel.
 */
Std_ReturnType Uart_AsyncSend(uint8 Channel, const uint8 *Buffer, uint16 BufferSize)
{
    Std_ReturnType  tempReturn = E_NOT_OK;
    Uart_ModuleType hwModule;

#if (UART_DEV_ERROR_DETECT == STD_ON)
    if (UART_DRV_UNINIT == Uart_DriverStatus)
    {
        (void)Det_ReportError((uint16)UART_MODULE_ID, (uint8)0, (uint8)UART_ASYNCSEND_ID, (uint8)UART_E_UNINIT);
    }
    else
    {
        if (Channel >= Uart_ConfigPtr->UartChannelNum)
        {
            (void)Det_ReportError(
              (uint16)UART_MODULE_ID, (uint8)0, (uint8)UART_ASYNCSEND_ID, (uint8)UART_E_INVALID_CHANNEL);
        }
        else
        {
            if (NULL_PTR == Buffer)
            {
                (void)Det_ReportError(
                  (uint16)UART_MODULE_ID, (uint8)0, (uint8)UART_ASYNCSEND_ID, (uint8)UART_E_INVALID_POINTER);
            }
            else
            {
                if (0U == BufferSize)
                {
                    (void)Det_ReportError(
                      (uint16)UART_MODULE_ID, (uint8)0, (uint8)UART_ASYNCSEND_ID, (uint8)UART_E_INVALID_PARAMETER);
                }
                else
                {
#endif
                    hwModule = Uart_ConfigPtr->UartChannelConfigPtr[Channel].Module;
                    if (Uart_Im_AsyncSend(hwModule, Buffer, BufferSize) == UART_STATUS_OK)
                    {
                        tempReturn = E_OK;
                    }
                    else
                    {
                        /* Do Nothing */
                    }
#if (UART_DEV_ERROR_DETECT == STD_ON)
                }
            }
        }
    }
#endif
    return tempReturn;
}

/**
 * @brief Starts an asynchronous polling transfer(send) of bytes.
 * @details
 * This function starts sending a number of bytes in an asynchronous polling manner.
 * The transfer can only be performed using DMA, and no interrupt should be opened.
 *
 * Syntax:Std_ReturnType Uart_AsyncPollingSend(uint8 Channel, const uint8 *Buffer, uint16 BufferSize)
 * Service ID:
 * Sync/Async:Async
 * Reentrancy:Non Reentrant
 * @param Channel Uart channel to be addressed
 * @param Buffer The buffer where the data to be sent is located.
 * @param BufferSize The Buffer size.
 * @return Std_ReturnType
 * @retval E_OK The transfer(send) started successfully
 * @retval E_NOT_OK If the Uart Channel is not valid or Uart driver is not initialized or Buffer is a NULL_PTR or
 * BufferSize is 0 or DMA not enabled or a transfer(send) is already on going on the requested channel.
 */
Std_ReturnType Uart_AsyncPollingSend(uint8 Channel, const uint8 *Buffer, uint16 BufferSize)
{
    Std_ReturnType  tempReturn = E_NOT_OK;
    Uart_ModuleType hwModule;

#if (UART_DEV_ERROR_DETECT == STD_ON)
    if (UART_DRV_UNINIT == Uart_DriverStatus)
    {
        (void)Det_ReportError((uint16)UART_MODULE_ID, (uint8)0, (uint8)UART_ASYNCPOLLINGSEND_ID, (uint8)UART_E_UNINIT);
    }
    else
    {
        if (Channel >= Uart_ConfigPtr->UartChannelNum)
        {
            (void)Det_ReportError(
              (uint16)UART_MODULE_ID, (uint8)0, (uint8)UART_ASYNCPOLLINGSEND_ID, (uint8)UART_E_INVALID_CHANNEL);
        }
        else
        {
            if (NULL_PTR == Buffer)
            {
                (void)Det_ReportError(
                  (uint16)UART_MODULE_ID, (uint8)0, (uint8)UART_ASYNCPOLLINGSEND_ID, (uint8)UART_E_INVALID_POINTER);
            }
            else
            {
                if (0U == BufferSize)
                {
                    (void)Det_ReportError((uint16)UART_MODULE_ID, (uint8)0, (uint8)UART_ASYNCPOLLINGSEND_ID,
                                          (uint8)UART_E_INVALID_PARAMETER);
                }
                else
                {
#endif
                    hwModule = Uart_ConfigPtr->UartChannelConfigPtr[Channel].Module;
                    if (Uart_Im_AsyncPollingSend(hwModule, Buffer, BufferSize) == UART_STATUS_OK)
                    {
                        tempReturn = E_OK;
                    }
                    else
                    {
                        /* Do Nothing */
                    }
#if (UART_DEV_ERROR_DETECT == STD_ON)
                }
            }
        }
    }
#endif
    return tempReturn;
}

/**
 * @brief Gets an asynchronous polling transfer(send) state.
 * @details
 * This function gets the status of an an asynchronous polling sending process.
 *
 * Syntax:Std_ReturnType Uart_GetAsyncPollingSendStatus(uint8 Channel)
 * Service ID:
 * Sync/Async:Synchronous
 * Reentrancy:Non Reentrant
 * @param Channel Uart channel to be addressed
 * @param Buffer A pointer to the send data
 * @param BufferSize Length of transmission
 * @return Std_ReturnType
 * @retval E_OK The sending process is done or not started.
 * @retval E_NOT_OK the sending process is on going.
 */
Std_ReturnType Uart_GetAsyncPollingSendStatus(uint8 Channel)
{
    Std_ReturnType  tempReturn = E_NOT_OK;
    Uart_ModuleType hwModule;

#if (UART_DEV_ERROR_DETECT == STD_ON)
    if (UART_DRV_UNINIT == Uart_DriverStatus)
    {
        (void)Det_ReportError(
          (uint16)UART_MODULE_ID, (uint8)0, (uint8)UART_GETASYNCPOLLINGSENDSTATUS_ID, (uint8)UART_E_UNINIT);
    }
    else
    {
        if (Channel >= Uart_ConfigPtr->UartChannelNum)
        {
            (void)Det_ReportError((uint16)UART_MODULE_ID, (uint8)0, (uint8)UART_GETASYNCPOLLINGSENDSTATUS_ID,
                                  (uint8)UART_E_INVALID_CHANNEL);
        }
        else
        {
#endif
            hwModule = Uart_ConfigPtr->UartChannelConfigPtr[Channel].Module;
            if (Uart_Im_GetAsyncPollingSendStatus(hwModule) == UART_STATUS_OK)
            {
                tempReturn = E_OK;
            }
            else
            {
                /* Do Nothing */
            }
#if (UART_DEV_ERROR_DETECT == STD_ON)
        }
    }
#endif
    return tempReturn;
}

/**
 * @brief Starts a synchronous reception of bytes.This function starts receiving a number of bytes in a synchronous
 * manner.
 * @details
 * Syntax:Std_ReturnType Uart_SyncReceive(uint8 Channel, uint8 *Buffer, uint16 BufferSize, uint32 Timeout)
 * Service ID:
 * Sync/Async:Synchronous
 * Reentrancy:Non Reentrant
 * @param Channel Uart channel to be addressed
 * @param Buffer The buffer where the bytes will be located.
 * @param BufferSize The Buffer size.
 * @param Timeout The timeout in us.zero for infinite waiting
 * @return Std_ReturnType
 * @retval E_OK Successful reception.
 * @retval E_NOT_OK If the Uart Channel is not valid or Uart driver is not initialized or Buffer is a NULL_PTR or
 * BufferSize is 0, meaning no space has been allocated for the buffer or a reception is already on going on the
 * requested channel or timeout occurred.
 */
Std_ReturnType Uart_SyncReceive(uint8 Channel, uint8 *Buffer, uint16 BufferSize, uint32 Timeout)
{
    Std_ReturnType  tempReturn = E_NOT_OK;
    Uart_ModuleType hwModule;

#if (UART_DEV_ERROR_DETECT == STD_ON)
    if (UART_DRV_UNINIT == Uart_DriverStatus)
    {
        (void)Det_ReportError((uint16)UART_MODULE_ID, (uint8)0, (uint8)UART_SYNCRECEIVE_ID, (uint8)UART_E_UNINIT);
    }
    else
    {
        if (Channel >= Uart_ConfigPtr->UartChannelNum)
        {
            (void)Det_ReportError(
              (uint16)UART_MODULE_ID, (uint8)0, (uint8)UART_SYNCRECEIVE_ID, (uint8)UART_E_INVALID_CHANNEL);
        }
        else
        {
            if (NULL_PTR == Buffer)
            {
                (void)Det_ReportError(
                  (uint16)UART_MODULE_ID, (uint8)0, (uint8)UART_SYNCRECEIVE_ID, (uint8)UART_E_INVALID_POINTER);
            }
            else
            {
                if (0U == BufferSize)
                {
                    (void)Det_ReportError(
                      (uint16)UART_MODULE_ID, (uint8)0, (uint8)UART_SYNCRECEIVE_ID, (uint8)UART_E_INVALID_PARAMETER);
                }
                else
                {
#endif
                    hwModule = Uart_ConfigPtr->UartChannelConfigPtr[Channel].Module;
                    if (Uart_Im_SyncReceive(hwModule, Buffer, BufferSize, Timeout) == UART_STATUS_OK)
                    {
                        tempReturn = E_OK;
                    }
                    else
                    {
                        /* Do Nothing */
                    }
#if (UART_DEV_ERROR_DETECT == STD_ON)
                }
            }
        }
    }
#endif
    return tempReturn;
}

/**
 * @brief Starts an asynchronous transfer(receive) of bytes.
 * @details
 * This function starts receiving a number of bytes in an asynchronous manner. The transfer can be performed
 * using either DMA or interrupts depending on the transfer type configured on the addressed channel
 *
 * Syntax:Std_ReturnType Uart_AsyncReceive(uint8 Channel, uint8 *Buffer, uint16 BufferSize)
 * Service ID:
 * Sync/Async:Async
 * Reentrancy:Non Reentrant
 * @param Channel Uart channel to be addressed
 * @param Buffer The buffer where the data to be received will located
 * @param BufferSize The Buffer size;if BufferSize == 0U, it means the size of the data to be received is not
 * certain,UART will receive until a idle frame
 * @return Std_ReturnType
 * @retval E_OK If the Uart Channel is not valid or Uart driver is not initialized or Buffer is a NULL_PTR or BufferSize
 * is 0, meaning no space has been allocated for the buffer or a transfer(receive) is already on going on the requested
 * channel.
 * @retval E_NOT_OK The transfer(receive) started successfully.
 */
Std_ReturnType Uart_AsyncReceive(uint8 Channel, uint8 *Buffer, uint16 BufferSize)
{
    Std_ReturnType  tempReturn = E_NOT_OK;
    Uart_ModuleType hwModule;

#if (UART_DEV_ERROR_DETECT == STD_ON)
    if (UART_DRV_UNINIT == Uart_DriverStatus)
    {
        (void)Det_ReportError((uint16)UART_MODULE_ID, (uint8)0, (uint8)UART_ASYNCRECEIVE_ID, (uint8)UART_E_UNINIT);
    }
    else
    {
        if (Channel >= Uart_ConfigPtr->UartChannelNum)
        {
            (void)Det_ReportError(
              (uint16)UART_MODULE_ID, (uint8)0, (uint8)UART_ASYNCRECEIVE_ID, (uint8)UART_E_INVALID_CHANNEL);
        }
        else
        {
            if (NULL_PTR == Buffer)
            {
                (void)Det_ReportError(
                  (uint16)UART_MODULE_ID, (uint8)0, (uint8)UART_ASYNCRECEIVE_ID, (uint8)UART_E_INVALID_POINTER);
            }
            else
            {
                if (BufferSize > UART_RX_DATA_MAX_SIZE)
                {
                    (void)Det_ReportError(
                      (uint16)UART_MODULE_ID, (uint8)0, (uint8)UART_ASYNCRECEIVE_ID, (uint8)UART_E_INVALID_PARAMETER);
                }
                else
                {
#endif
                    hwModule = Uart_ConfigPtr->UartChannelConfigPtr[Channel].Module;
                    if (Uart_Im_AsyncReceive(hwModule, Buffer, BufferSize) == UART_STATUS_OK)
                    {
                        tempReturn = E_OK;
                    }
                    else
                    {
                        /* Do Nothing */
                    }
#if (UART_DEV_ERROR_DETECT == STD_ON)
                }
            }
        }
    }
#endif
    return tempReturn;
}

/**
 * @brief Aborts an on-going transfer
 * @details
 * Syntax:Std_ReturnType Uart_Abort(uint8 Channel, Uart_DataDirectionType TransmissionType)
 * Service ID:
 * Sync/Async:Synchronous
 * Reentrancy:Reentrant
 * @param Channel Uart channel to be addressed
 * @param TransmissionType Type of the transfer to be aborted. It can be either UART_SEND or UART_RECEIVE.
 * @return Std_ReturnType
 * @retval E_OK Successful transfer aborted or in case no transfer was on going.
 * @retval E_NOT_OK If the Uart Channel is not valid or Uart driver is not initialized.
 */
Std_ReturnType Uart_Abort(uint8 Channel, Uart_DataDirectionType TransmissionType)
{
    Std_ReturnType  tempReturn;
    Uart_ModuleType hwModule;

#if (UART_DEV_ERROR_DETECT == STD_ON)
    if (UART_DRV_UNINIT == Uart_DriverStatus)
    {
        (void)Det_ReportError((uint16)UART_MODULE_ID, (uint8)0, (uint8)UART_ABORT_ID, (uint8)UART_E_UNINIT);
    }
    else
    {
        if (Channel >= Uart_ConfigPtr->UartChannelNum)
        {
            (void)Det_ReportError(
              (uint16)UART_MODULE_ID, (uint8)0, (uint8)UART_ABORT_ID, (uint8)UART_E_INVALID_CHANNEL);
        }
        else
        {
#endif
            hwModule = Uart_ConfigPtr->UartChannelConfigPtr[Channel].Module;
            if (UART_SEND == TransmissionType)
            {
                tempReturn = (Std_ReturnType)Uart_Im_AbortSendingData(hwModule);
            }
            else
            {
                tempReturn = (Std_ReturnType)Uart_Im_AbortReceivingData(hwModule);
            }
#if (UART_DEV_ERROR_DETECT == STD_ON)
        }
    }
#endif
    return tempReturn;
}

/**
 * @brief Returns the status of the previous transfer
 * @details
 * Syntax:Uart_StatusType Uart_GetBusStatus(uint8 Channel, Uart_DataDirectionType TransferType)
 * Service ID:
 * Sync/Async:Synchronous
 * Reentrancy:Reentrant
 * @param Channel Uart channel to be addressed
 * @param TransferType The type of transfer in discussion (UART_SEND or UART_RECEIVE)
 * @return Std_ReturnType
 * @retval UART_STATUS_OPERATION_IDLE No transferring process exists
 * @retval UART_STATUS_OPERATION_ONGOING transferring operation is on going
 */
Uart_StatusType Uart_GetBusStatus(uint8 Channel, Uart_DataDirectionType TransferType)
{
    Uart_ModuleType hwModule;

    Uart_StatusType tempReturn;

#if (UART_DEV_ERROR_DETECT == STD_ON)
    if (UART_DRV_UNINIT == Uart_DriverStatus)
    {
        (void)Det_ReportError((uint16)UART_MODULE_ID, (uint8)0, (uint8)UART_GETBUSSTATUS_ID, (uint8)UART_E_UNINIT);
    }
    else
    {
        if (Channel >= Uart_ConfigPtr->UartChannelNum)
        {
            (void)Det_ReportError(
              (uint16)UART_MODULE_ID, (uint8)0, (uint8)UART_GETBUSSTATUS_ID, (uint8)UART_E_INVALID_CHANNEL);
        }
        else
        {
#endif
            hwModule = Uart_ConfigPtr->UartChannelConfigPtr[Channel].Module;
            if (Uart_Im_GetTransferStatus(hwModule, TransferType) == UART_STATUS_OK)
            {
                tempReturn = UART_STATUS_OPERATION_IDLE;
            }
            else
            {
                tempReturn = UART_STATUS_OPERATION_ONGOING;
            }
#if (UART_DEV_ERROR_DETECT == STD_ON)
        }
    }
#endif
    return tempReturn;
}

/**
 * @brief Returns the version information of this module
 * @details
 * Syntax:void Uart_GetVersionInfo(Std_VersionInfoType *VersionInfo)
 * Service ID:
 * Sync/Async:Synchronous
 * Reentrancy:Reentrant
 * @param VersionInfo Pointer to where to store the version information of this module
 * @return void
 */
#if (UART_VERSION_INFO_API == STD_ON)
void Uart_GetVersionInfo(Std_VersionInfoType *VersionInfo)
{
#if (UART_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == VersionInfo)
    {
        (void)Det_ReportError(
          (uint16)UART_MODULE_ID, (uint8)0, (uint8)UART_VERSIONINFO_ID, (uint8)UART_E_INVALID_POINTER);
    }
    else
    {
#endif
        VersionInfo->vendorID         = (uint16)UART_VENDOR_ID;
        VersionInfo->moduleID         = (uint8)UART_MODULE_ID;
        VersionInfo->sw_major_version = (uint8)UART_SW_MAJOR_VERSION;
        VersionInfo->sw_minor_version = (uint8)UART_SW_MINOR_VERSION;
        VersionInfo->sw_patch_version = (uint8)UART_SW_PATCH_VERSION;
#if (UART_DEV_ERROR_DETECT == STD_ON)
    }
#endif
}
#endif
/* EOF */
