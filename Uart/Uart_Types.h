/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Uart_Types.h
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
#ifndef UART_TYPES_H
#define UART_TYPES_H

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
#include "Uart_Cfg.h"
#include "Std_Types.h"
/******************************************************************************
 **                        File Version Check
 ******************************************************************************/

/******************************************************************************
 **                        Macro  Definitions
 ******************************************************************************/
#if ((UART_DEV_ERROR_DETECT == STD_ON) || (UART_RUNTIME_ERROR_DETECT == STD_ON))

/**
 * @brief Driver not initialized
 * @details Errors reported by Det_ReportError() and Det_ReportRuntimeError().
 */
#define UART_E_UNINIT ((uint8)0x01U)

/**
 * @brief Invalid channel given as parameter
 * @details Errors reported by Det_ReportError() and Det_ReportRuntimeError().
 */
#define UART_E_INVALID_CHANNEL ((uint8)0x02U)

/**
 * @brief Invalid channel given as parameter
 * @details Errors reported by Det_ReportError() and Det_ReportRuntimeError().
 */
#define UART_E_INVALID_POINTER ((uint8)0x03U)

/**
 * @brief Driver already initialized
 * @details Errors reported by Det_ReportError() and Det_ReportRuntimeError().
 */
#define UART_E_ALREADY_INITIALIZED ((uint8)0x04U)

/**
 * @brief Parameter has a wrong value
 * @details Errors reported by Det_ReportError() and Det_ReportRuntimeError().
 */
#define UART_E_INVALID_PARAMETER ((uint8)0x07U)

/**
 * @brief Invalid pointer for init function parameter
 * @details Errors reported by Det_ReportError() and Det_ReportRuntimeError().
 */
#define UART_E_INIT_FAILED ((uint8)0x09U)

/**
 * @brief De-Init function for specific HW channel finish unsuccessfully
 * @details Errors reported by Det_ReportError() and Det_ReportRuntimeError().
 */
#define UART_E_DEINIT_FAILED ((uint8)0x10U)

/**
 * @brief API service ID for UART_Init() function
 * @details Parameters used when raising an error or exception.
 */
#define UART_INIT_ID ((uint8)0x00U)

/**
 * @brief API service ID for UART_DeInit() function
 * @details Parameters used when raising an error or exception.
 */
#define UART_DEINIT_ID ((uint8)0x01U)

/**
 * @brief API service ID for UART_SyncSend() function
 * @details Parameters used when raising an error or exception.
 */
#define UART_SYNCSEND_ID ((uint8)0x04U)

/**
 * @brief API service ID for Uart_AsyncSend() function
 * @details Parameters used when raising an error or exception.
 */
#define UART_ASYNCSEND_ID ((uint8)0x05U)

/**
 * @brief API service ID for UART_SyncReceive() function
 * @details Parameters used when raising an error or exception.
 */
#define UART_SYNCRECEIVE_ID ((uint8)0x06U)

/**
 * @brief API service ID for Uart_AsyncReceive() function
 * @details Parameters used when raising an error or exception.
 */
#define UART_ASYNCRECEIVE_ID ((uint8)0x07U)

/**
 * @brief API service ID for UART_Abort() function
 * @details Parameters used when raising an error or exception.
 */
#define UART_ABORT_ID ((uint8)0x08U)

/**
 * @brief API service ID for Uart_GetBusStatus() function
 * @details Parameters used when raising an error or exception.
 */
#define UART_GETBUSSTATUS_ID ((uint8)0x09U)

/**
 * @brief API service ID for Uart_GetVersionInfo() function
 * @details Parameters used when raising an error or exception.
 */
#define UART_VERSIONINFO_ID ((uint8)0x0AU)

/**
 * @brief API service ID for UART_SetBuffer() function
 * @details Parameters used when raising an error or exception.
 */
#define UART_SETBUFFER_ID ((uint8)0x0BU)

/**
 * @brief API service ID for Uart_AsyncPollingSend() function
 * @details Parameters used when raising an error or exception.
 */
#define UART_ASYNCPOLLINGSEND_ID ((uint8)0x0CU)

/**
 * @brief API service ID for Uart_GetAsyncPollingSendStatus() function
 * @details Parameters used when raising an error or exception.
 */
#define UART_GETASYNCPOLLINGSENDSTATUS_ID ((uint8)0x0DU)
#endif

/**
 * @brief dma enable or disable
 */
#define UART_DMA_DISABLE ((uint8)0U)
#define UART_DMA_ENABLE  ((uint8)1U)

#define UART_DMA_UPDATE_INIT ((uint8)0U)
#define UART_DMA_UPDATE_SET  ((uint8)1U)
/******************************************************************************
 **                        Typedef  Definitions
 ******************************************************************************/

/**
 * @brief Uart Operation status
 */
typedef enum
{
    /**< @brief No transferring process exists */
    UART_STATUS_OPERATION_IDLE,
    /**< @brief transferring operation is on going  */
    UART_STATUS_OPERATION_ONGOING,
} Uart_StatusType;

/**
 * @brief dma source
 */
typedef enum
{
    /** @brief dma0 channel1 */
    UART_DMA0_CHANNEL_1,
    /** @brief dma channel2 */
    UART_DMA0_CHANNEL_2,
    /** @brief dma channel3 */
    UART_DMA0_CHANNEL_3,
    /** @brief dma channel4 */
    UART_DMA0_CHANNEL_4,
    /** @brief dma channel5 */
    UART_DMA0_CHANNEL_5,
    /** @brief dma channel6 */
    UART_DMA0_CHANNEL_6,
    /** @brief dma channel7 */
    UART_DMA0_CHANNEL_7,
    /** @brief dma1 channel1 */
    UART_DMA1_CHANNEL_1,
    /** @brief dma1 channel2 */
    UART_DMA1_CHANNEL_2,
    /** @brief dma1 channel3 */
    UART_DMA1_CHANNEL_3,
    /** @brief dma1 channel4 */
    UART_DMA1_CHANNEL_4,
    /** @brief dma1 channel5 */
    UART_DMA1_CHANNEL_5,
    /** @brief dma1 channel6 */
    UART_DMA1_CHANNEL_6,
    /** @brief dma1 channel7 */
    UART_DMA1_CHANNEL_7
} Uart_DmaSourceType;

/**
 * @brief uart module
 */
typedef enum
{
    /** @brief module UART0 */
    UART_MODULE_0,
    /** @brief module UART1 */
    UART_MODULE_1,
    /** @brief module UART2 */
    UART_MODULE_2,
    /** @brief module UART3 */
    UART_MODULE_3,
    /** @brief module UART4 */
    UART_MODULE_6,
    /** @brief Number of Channels configured. */
    UART_CH_MAX_CONFIG
} Uart_ModuleType;

/**
 * @brief tx select
 */
typedef enum
{
    /** @brief TX0 */
    UART_TX0,
    /** @brief TX1 */
    UART_TX1
} Uart_TxSelectType;

/**
 * @brief byte order
 */
typedef enum
{
    /** @brief LSB first */
    UART_LSB_FIRST,
    /** @brief MSB first */
    UART_MSB_FIRST
} Uart_ByteOrderType;

/**
 * @brief parity check
 */
typedef enum
{
    /** @brief None check */
    UART_PARITY_NONE,
    /** @brief Odd check */
    UART_PARITY_ODD,
    /** @brief Even check */
    UART_PARITY_EVEN
} Uart_ParityType;

/**
 * @brief stop bit length
 */
typedef enum
{
    /** @brief 1bit stop */
    UART_STOP_BIT_1,
    /** @brief 2bit stop */
    UART_STOP_BIT_2
} Uart_StopBitType;

/**
 * @brief clock source
 */
typedef enum
{
    /** @brief SCLK */
    UART_CLOCK_SCLK,
    /** @brief HFCLK */
    UART_CLOCK_HFCLK
} Uart_ClockSourceType;

/**
 * @brief Define the enum of the Events which can trigger UART callback
 * @details This enum should include the Events for all platforms
 */
typedef enum
{
    /**< @brief Rx buffer is full */
    UART_EVENT_RX_FULL,
    /**< @brief Tx buffer is empty */
    UART_EVENT_TX_EMPTY,
    /**< @brief The current transfer is ending */
    UART_EVENT_END_TRANSFER,
    /**< @brief An error occurred during transfer */
    UART_EVENT_ERROR,
} Uart_EventType;

/**
 * @brief Driver initialization status.
 * @details This enum contains the values for the driver initialization status.
 */
typedef enum
{
    /**< @brief Driver not initialized */
    UART_DRV_UNINIT,
    /**< @brief Driver ready */
    UART_DRV_INIT,
} Uart_DrvStatusType;

/**
 * @brief The type operation of an Uart channel.
 */
typedef enum
{
    /**< @brief The sending operation */
    UART_SEND,
    /**< @brief The receiving operation */
    UART_RECEIVE
} Uart_DataDirectionType;

/**
 * @brief uart receive completed callback
 */
/* PRQA S 1336 1 #KQR001336 */
typedef void (*Uart_ReceiveCompleteFcnType)(Uart_ModuleType, uint16);

/**
 * @brief uart send completed callback
 */
/* PRQA S 1336 1 #KQR001336 */
typedef void (*Uart_SendCompleteFcnType)(Uart_ModuleType);

/**
 * @brief Uart callback notification signature.
 */
typedef void (*Uart_CallbackType)(uint8 Channel, Uart_EventType Event);

/**
 * @brief dma config information
 */
/* PRQA S 3630 ++ #KQR003630 */
typedef struct
{
    /** @brief uart dma switch */
    const uint8 ReceiveDmaSwitch;
    /** @brief uart dma switch */
    const uint8 SendDmaSwitch;
    /** @brief uart send dma source */
    const Uart_DmaSourceType TxDmaSource;
    /** @brief uart receive dma source */
    const Uart_DmaSourceType RxDmaSource;
} Uart_DmaSourceConfigType;

/**
 * @brief uart config information
 */
typedef struct
{
    /** @brief uart module */
    const Uart_ModuleType Module;
    /** @brief clock source */
    const Uart_ClockSourceType BaudRateClkSrc;
    /** @brief BRGM */
    const uint16 BaudRateInteger;
    /** @brief BRGF1 */
    const uint8 BaudRateNumerator;
    /** @brief BRGF2 */
    const uint8 BaudRateDenominator;
    /** @brief uart stop bit length */
    const Uart_StopBitType StopBit;
    /** @brief uart parity type */
    const Uart_ParityType ParityMode;
    /** @brief uart receive byte order */
    const Uart_ByteOrderType ReceiveOrder;
    /** @brief uart send byte order */
    const Uart_ByteOrderType SendOrder;
    /** @brief TX0,TX1 */
    const Uart_TxSelectType TxSelect;
    /** @brief uart dma source config */
    const Uart_DmaSourceConfigType *DmaConfigPtr;
    /** @brief uart receive completed callback */
    Uart_ReceiveCompleteFcnType ReceiveCompleteCallback;
    /** @brief uart send completed callback */
    Uart_SendCompleteFcnType SendCompleteCallback;
} Uart_ChannelConfigType;

/**
 * @brief uart config information
 */
typedef struct
{
    /** @brief UART number */
    uint8 UartChannelNum;
    /** @brief UART configuration */
    const Uart_ChannelConfigType *UartChannelConfigPtr;
} Uart_ConfigType;
/* PRQA S 3630 -- #KQR003630 */
/******************************************************************************
 **                        Export Variables
 ******************************************************************************/

/******************************************************************************
 **                        Export Functions
 ******************************************************************************/

#ifdef __cplusplus
}
#endif

#endif
/* EOF */
