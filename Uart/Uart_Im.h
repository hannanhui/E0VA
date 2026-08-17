/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Uart_Im.h
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
#ifndef UART_IM_H
#define UART_IM_H

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
/* PRQA S 3205 EOF  #KQR003205*/
/******************************************************************************
 **                        Include Files
 ******************************************************************************/
#include "Uart_Types.h"

/******************************************************************************
 **                        File Version Check
 ******************************************************************************/

/******************************************************************************
 **                        Macro  Definitions
 ******************************************************************************/

/**
 * @brief uart asynchronous transfer status
 */
#define UART_IM_TRANSFER_STATE_IDLE         ((uint8)0x00U)
#define UART_IM_TRANSFER_STATE_BUSY_SEND    ((uint8)0x01U)
#define UART_IM_TRANSFER_STATE_BUSY_RECEIVE ((uint8)0x02U)

/******************************************************************************
 **                        Typedef  Definitions
 ******************************************************************************/

/**
 * @brief uart callback
 */
typedef struct
{
    Uart_ReceiveCompleteFcnType ReceiveCompleteCallback;
    Uart_SendCompleteFcnType    SendCompleteCallback;
} Uart_CallBackHandleType;

/* SCLK Oscillation source selection */
typedef enum
{
    OSC_HW_SCLK_SOURCE_INTHF = 0,
    OSC_HW_SCLK_SOURCE_INTLF = 1,
    OSC_HW_SCLK_SOURCE_EXTHF = 2,
    OSC_HW_SCLK_SOURCE_EXTLF = 3,
    OSC_HW_SCLK_SOURCE_PLL0  = 4,
    OSC_HW_SCLK_SOURCE_PLL1  = 5,
    OSC_HW_SCLK_SOURCE_LPHF  = 6,
    OSC_HW_SCLK_SOURCE_LPLF  = 7,
} Osc_SclkSrcEnumType;

/**
 * @brief uart status
 */
typedef enum
{
    /** @brief uart status ok */
    UART_STATUS_OK,
    /** @brief uart transfer timeout */
    UART_STATUS_TIMEOUT,
    /** @brief DMA not enabled */
    UART_STATUS_DMA_NOT_ENABLED,
    /** @brief uart busy */
    UART_STATUS_BUSY
} Uart_Im_StatusType;

/**
 * @brief uart interrupt  transfer data info
 */
typedef struct
{
    /** @brief data buffer address */
    uint8 *DataBuffer;
    /** @brief send data length */
    uint16 Length;
    /** @brief send data index */
    uint16 Index;
} Uart_IntrTransferType;

typedef struct
{
    Uart_IntrTransferType SendIntrInfo;
    Uart_IntrTransferType RecIntrInfo;
    uint8                 TransferState;
} Uart_TransferInfoType;
/******************************************************************************
 **                        Export Variables
 ******************************************************************************/

/******************************************************************************
 **                        Export Functions
 ******************************************************************************/

/**
 * @brief Uart Disable the DMA
 *
 * @param Module Usart module
 */
void Uart_Im_DmaDisable(Uart_ModuleType Module);

/**
 * @brief Synchronous send data processing
 *
 * @param Module Usart module
 * @param SendData send data pointer
 * @param SendLength Length of transmit
 * @param Timeout time out value,zero for infinite waiting
 *
 * @return Uart_Im_StatusType
 * @retval UART_STATUS_OK
 * @retval UART_STATUS_TIMEOUT
 * @retval UART_STATUS_BUSY
 */
Uart_Im_StatusType Uart_Im_SyncSend(Uart_ModuleType Module, const uint8 *SendData, uint16 SendLength, uint32 TimeOut);

/**
 * @brief Asynchronous  send data processing
 *
 * @param Module Usart module
 * @param SendData send data pointer
 * @param SendLength Length of transmit
 *
 * @return Uart_Im_StatusType
 * @retval UART_STATUS_OK
 * @retval UART_STATUS_TIMEOUT
 * @retval UART_STATUS_BUSY
 */
Uart_Im_StatusType Uart_Im_AsyncSend(Uart_ModuleType Module, const uint8 *SendData, uint16 SendLength);

/**
 * @brief Asynchronous polling send data processing
 *
 * @param Module Usart module
 * @param SendData send data pointer
 * @param SendLength Length of transmit
 *
 * @return Uart_Im_StatusType
 * @retval UART_STATUS_OK
 * @retval UART_STATUS_DMA_NOT_ENABLED
 * @retval UART_STATUS_BUSY
 */
Uart_Im_StatusType Uart_Im_AsyncPollingSend(Uart_ModuleType Module, const uint8 *SendData, uint16 SendLength);

/**
 * @brief Get the asynchronous polling sending status
 *
 * @param Module Usart module
 *
 * @return Uart_Im_StatusType
 * @retval UART_STATUS_OK
 * @retval UART_STATUS_BUSY
 */
Uart_Im_StatusType Uart_Im_GetAsyncPollingSendStatus(Uart_ModuleType Module);

/**
 * @brief Synchronous receive processing
 *
 * @param Module Usart module
 * @param Buffer read buffer
 * @param BufferSize Length of receive
 * @param Timeout time out value,zero for infinite waiting
 *
 * @return Uart_Im_StatusType
 * @retval UART_STATUS_OK
 * @retval UART_STATUS_TIMEOUT
 * @retval UART_STATUS_BUSY
 */
Uart_Im_StatusType Uart_Im_SyncReceive(Uart_ModuleType Module, uint8 *Buffer, uint16 BufferSize, uint32 Timeout);

/**
 * @brief Asynchronous receive processing
 *
 * @param Module Usart module
 * @param Buffer read buffer
 * @param BufferSize Length of receive
 *
 * @return Uart_Im_StatusType
 * @retval UART_STATUS_OK
 * @retval UART_STATUS_TIMEOUT
 * @retval UART_STATUS_BUSY
 */
Uart_Im_StatusType Uart_Im_AsyncReceive(Uart_ModuleType Module, uint8 *Buffer, uint16 BufferSize);

/**
 * @brief Stop sending data
 *
 * @param Module Usart module
 *
 * @return Uart_Im_StatusType
 * @retval UART_STATUS_OK
 */
Uart_Im_StatusType Uart_Im_AbortSendingData(Uart_ModuleType Module);

/**
 * @brief Stop receiving data
 *
 * @param Module Usart module
 *
 * @return Uart_Im_StatusType
 * @retval UART_STATUS_OK
 */
Uart_Im_StatusType Uart_Im_AbortReceivingData(Uart_ModuleType Module);

/**
 * @brief Gets the status of the record
 *
 * @param Module Usart module
 * @param TransferDir Send or receive
 *
 * @return Uart_Im_StatusType
 * @retval UART_STATUS_OK
 * @retval UART_STATUS_BUSY
 */
Uart_Im_StatusType Uart_Im_GetTransferStatus(Uart_ModuleType Module, Uart_DataDirectionType TransferDir);

/**
 * @brief set the module in the reset state
 *
 * @param Module Usart module
 */
void Uart_Im_DeInitDevice(Uart_ModuleType Module);

/**
 * @brief enable module
 *
 * @param Module Usart module
 */
void Uart_Im_Enable(Uart_ModuleType Module);

/**
 * @brief disable module
 *
 * @param Module Usart module
 */
void Uart_Im_Disable(Uart_ModuleType Module);

/**
 * @brief uart interrupt init
 *
 * @param Module Usart module
 * @param UartUnitConfig module config information
 */
void Uart_Im_IntrInit(Uart_ModuleType Module, const Uart_ChannelConfigType *UartUnitConfig);

/**
 * @brief uart dma config initialize
 *
 * @param Module Usart module
 * @param UartUnitConfig module config information
 */
void Uart_Im_DmaConfig(Uart_ModuleType Module, const Uart_ChannelConfigType *UartUnitConfig);

/**
 * @brief uart pre-initialization
 *
 * @param Module Usart module
 * @param UartUnitConfig module config information
 */
void Uart_Im_PreInit(Uart_ModuleType Module, const Uart_ChannelConfigType *UartUnitConfig);

#ifdef __cplusplus
}
#endif

#endif
/* EOF */
