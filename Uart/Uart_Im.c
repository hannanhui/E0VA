/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Uart_Im.c
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
/* PRQA S 0303 EOF #KQR000303 */
/* PRQA S 4342 EOF #KQR004342 */
/* PRQA S 4558 EOF #KQR004558 */
/* PRQA S 3387 EOF #KQR003387 */
/* PRQA S 0306 EOF #KQR000306 */
/* PRQA S 3415 EOF #KQR003415 */
/* PRQA S 1881 EOF #KQR001881 */
/* PRQA S 3006 EOF #KQR003006 */
/* PRQA S 1006 EOF #KQR101006 */
/* PRQA S 2814 EOF #KQR002814 */
/* PRQA S 2824 EOF #KQR002824 */
/* PRQA S 2844 EOF #KQR002844 */
/* PRQA S 2201 EOF #KQR002201 */
/* PRQA S 2934 EOF #KQR002934 */
/* PRQA S 4899 EOF #KQR004899 */
/* PRQA S 3383 EOF #KQR003383 */
/* PRQA S 3384 EOF #KQR003384 */
/******************************************************************************
 **                        Include Files
 ******************************************************************************/
#include "Uart_Im.h"
#include "kf32a158sf_drv_usart.h"
#include "kf32a158sf_drv_dma.h"
#include "kf32a158sf_drv_intr.h"
#include "kf32a158sf_drv_rst.h"
#include "kf32a158sf_drv_pclk.h"
#include "kf32a158sf_reg_osc.h"
#include "kf32a158sf_oscclk_base.h"

/******************************************************************************
 **                        File Version Check
 ******************************************************************************/

/******************************************************************************
 **                        Macro  Definitions
 ******************************************************************************/

/******************************************************************************
 **                        Typedef  Definitions
 ******************************************************************************/
/**
 * @brief interrupt handle
 */
typedef void (*Uart_DmaIntrFcnType)(uint8 IntrFlag);

/**
 * @brief uart dma user config information
 */
typedef struct
{
    /** @brief uart dma receive update status  */
    uint8 UpdateStatus;
    /** @brief uart dma send status  */
    uint8 TxDmaStatus;
    /** @brief uart dma receive status  */
    uint8 RxDmaStatus;
    /** @brief uart receive size  */
    uint16 RxMemorySize;
    /** @brief uart receive set addr  */
    uint32_t RxMemoryAddr;
    /** @brief uart send size  */
    uint16 TxMemorySize;
    /** @brief uart send set addr  */
    uint32_t TxMemoryAddr;
    /** @brief uart receive dma Ptr */
    Dma_RegisterMap_t *RxDmaBasePtr;
    /** @brief uart send dma Ptr */
    Dma_RegisterMap_t *TxDmaBasePtr;
    /** @brief uart receive dma channel index */
    uint8 RxDmaChannel;
    /** @brief uart send dma channel index */
    uint8 TxDmaChannel;
} Uart_DmaUserInfoType;

/**
 * @brief uart hardware informaiton config
 */
typedef struct
{
    /** @brief uart Hw Unit Pointer */
    Usart_RegisterMap_t *UartBasePtr;
} Uart_DescType;
/******************************************************************************
**                         Local Variables
******************************************************************************/
/**
 * @brief uart default buffer
 */
/* PRQA S 3233 1 #KQR003233  */
static uint8 const Uart_Im_DefaultBuffer[1U];

/**
 * @brief uart transfer information
 */
static Uart_TransferInfoType Uart_Im_TransferInfo[UART_CH_MAX_CONFIG];

/**
 * @brief user used dma,config information
 */
static Uart_DmaUserInfoType Uart_Im_DmaUserConfigInfo[UART_CH_MAX_CONFIG];

/**
 * @brief user callback
 */
static Uart_CallBackHandleType Uart_Im_CallBackHandle[UART_CH_MAX_CONFIG];
/******************************************************************************
 **                      Constant  Variables
 ******************************************************************************/

/**
 * @brief Uart dma Hw Information
 *
 */
static const Uart_DescType Uart_Im_Info[UART_CH_MAX_CONFIG] = {
  [0U] =
    {
      .UartBasePtr = USART0_PTR,
    },
  [1U] =
    {
      .UartBasePtr = USART1_PTR,
    },
  [2U] =
    {
      .UartBasePtr = USART2_PTR,
    },
  [3U] =
    {
      .UartBasePtr = USART3_PTR,
    },
  [4U] =
    {
      .UartBasePtr = USART6_PTR,
    },
};

/******************************************************************************
 **                      Function declarations
 ******************************************************************************/
static void Uart_Im_InterruptHandler(uint8 Module);

static void Uart_DmaInterruptTxHandler(Uart_ModuleType UartModule, uint8 IntrFlag);
static void Uart_DmaInterruptRxHandler(Uart_ModuleType UartModule, uint8 IntrFlag);

static void Uart_DmaIntrModule6TxHandle(uint8 IntrFlag);
static void Uart_DmaIntrModule3TxHandle(uint8 IntrFlag);
static void Uart_DmaIntrModule2TxHandle(uint8 IntrFlag);
static void Uart_DmaIntrModule1TxHandle(uint8 IntrFlag);
static void Uart_DmaIntrModule0TxHandle(uint8 IntrFlag);

static void Uart_DmaIntrModule6RxHandle(uint8 IntrFlag);
static void Uart_DmaIntrModule3RxHandle(uint8 IntrFlag);
static void Uart_DmaIntrModule2RxHandle(uint8 IntrFlag);
static void Uart_DmaIntrModule1RxHandle(uint8 IntrFlag);
static void Uart_DmaIntrModule0RxHandle(uint8 IntrFlag);

/**
 * @brief dma interrupt handle function for uart transmit
 */
/* PRQA S 2203 ++ #KQR002203 */
/* PRQA S 3218 1 #KQR003218 */
static const Uart_DmaIntrFcnType Uart_DmaIntrTxHandle[UART_CH_MAX_CONFIG] = {
  &Uart_DmaIntrModule0TxHandle, &Uart_DmaIntrModule1TxHandle, &Uart_DmaIntrModule2TxHandle,
  &Uart_DmaIntrModule3TxHandle, &Uart_DmaIntrModule6TxHandle};

/**
 * @brief dma interrupt handle function for uart receive
 */
/* PRQA S 3218 1 #KQR003218 */
static const Uart_DmaIntrFcnType Uart_DmaIntrRxHandle[UART_CH_MAX_CONFIG] = {
  &Uart_DmaIntrModule0RxHandle, &Uart_DmaIntrModule1RxHandle, &Uart_DmaIntrModule2RxHandle,
  &Uart_DmaIntrModule3RxHandle, &Uart_DmaIntrModule6RxHandle};
/* PRQA S 2203 -- #KQR002203 */
/******************************************************************************
 **                        Export Variables
 ******************************************************************************/

/******************************************************************************
 **                        Export Functions
 ******************************************************************************/
/**
 * @brief dma interrupt handle register
 *
 * @param DmaIndex dma index
 * @param DmaChannel dma channel
 * @param IrqHandle interrupt handle function
 */
/* PRQA S 1513 2 #KQR001513 */
/* PRQA S 1336 1 #KQR001336 */
extern void Dma_RegisterCustomHandler(uint8 DmaIndex, Dma_Channel_t DmaChannel, void (*IrqHandle)(uint8));

/**
 * @brief usart interrupt handle register
 *
 * @param UsartIndex usart index
 * @param IrqHandle interrupt handle function
 */
/* PRQA S 1513 2 #KQR001513 */
extern void Usart_RegisterCustomHandler(uint8 UsartIndex, void (*IrqHandle)(uint8 UsartIndex));
/******************************************************************************
 **                      Function definitions
 ******************************************************************************/
/**
 * @brief uart6 receive dma interrupt handle
 */
static void Uart_DmaIntrModule6RxHandle(uint8 IntrFlag)
{
    Uart_DmaInterruptRxHandler(UART_MODULE_6, IntrFlag);
}

/**
 * @brief uart3 receive dma interrupt handle
 */
static void Uart_DmaIntrModule3RxHandle(uint8 IntrFlag)
{
    Uart_DmaInterruptRxHandler(UART_MODULE_3, IntrFlag);
}

/**
 * @brief uart2 receive dma interrupt handle
 */
static void Uart_DmaIntrModule2RxHandle(uint8 IntrFlag)
{
    Uart_DmaInterruptRxHandler(UART_MODULE_2, IntrFlag);
}

/**
 * @brief uart1 receive dma interrupt handle
 */
static void Uart_DmaIntrModule1RxHandle(uint8 IntrFlag)
{
    Uart_DmaInterruptRxHandler(UART_MODULE_1, IntrFlag);
}

/**
 * @brief uart0 receive dma interrupt handle
 */
static void Uart_DmaIntrModule0RxHandle(uint8 IntrFlag)
{
    Uart_DmaInterruptRxHandler(UART_MODULE_0, IntrFlag);
}

/**
 * @brief uart6 send dma interrupt handle
 */
static void Uart_DmaIntrModule6TxHandle(uint8 IntrFlag)
{
    Uart_DmaInterruptTxHandler(UART_MODULE_6, IntrFlag);
}

/**
 * @brief uart3 send dma interrupt handle
 */
static void Uart_DmaIntrModule3TxHandle(uint8 IntrFlag)
{
    Uart_DmaInterruptTxHandler(UART_MODULE_3, IntrFlag);
}

/**
 * @brief uart2 send dma interrupt handle
 */
static void Uart_DmaIntrModule2TxHandle(uint8 IntrFlag)
{
    Uart_DmaInterruptTxHandler(UART_MODULE_2, IntrFlag);
}

/**
 * @brief uart1 send dma interrupt handle
 */
static void Uart_DmaIntrModule1TxHandle(uint8 IntrFlag)
{
    Uart_DmaInterruptTxHandler(UART_MODULE_1, IntrFlag);
}

/**
 * @brief uart0 send dma interrupt handle
 */
static void Uart_DmaIntrModule0TxHandle(uint8 IntrFlag)
{
    Uart_DmaInterruptTxHandler(UART_MODULE_0, IntrFlag);
}

/**
 * @brief uart user callback config
 *
 * @param Module Uart module
 * @param UartUnitConfig Uart config Information pointer
 */
static void Uart_Im_UserCallBackInit(Uart_ModuleType Module, const Uart_ChannelConfigType *UartUnitConfig)
{
    Uart_Im_CallBackHandle[Module].ReceiveCompleteCallback = UartUnitConfig->ReceiveCompleteCallback;
    Uart_Im_CallBackHandle[Module].SendCompleteCallback    = UartUnitConfig->SendCompleteCallback;
}

/**
 * @brief uart receive completed callback process
 *
 * @param UartModule Uart module
 * @param DataSize receive size
 */
static void Uart_Im_RecCompleteCallBackProcess(Uart_ModuleType UartModule, uint16 DataSize)
{
    if (Uart_Im_CallBackHandle[UartModule].ReceiveCompleteCallback != NULL_PTR)
    {
        Uart_Im_CallBackHandle[UartModule].ReceiveCompleteCallback(UartModule, DataSize);
    }
    else
    {
        /* Do Nothing */
    }
}

/**
 * @brief uart send data completed callback process
 *
 * @param UartModule Uart module
 */
static void Uart_Im_SendCompleteCallBackProcess(Uart_ModuleType UartModule)
{
    if (Uart_Im_CallBackHandle[UartModule].SendCompleteCallback != NULL_PTR)
    {
        Uart_Im_CallBackHandle[UartModule].SendCompleteCallback(UartModule);
    }
    else
    {
        /* Do Nothing */
    }
}

/**
 * @brief uart clear receive buffer
 *
 * @param Module Uart module
 */
static void Uart_Im_ClearRecvBuffer(Uart_ModuleType Module)
{
    const Uart_DescType *hwDesc = &Uart_Im_Info[(uint32)Module];

    Usart_LL_SetClearRecvBufferSta(hwDesc->UartBasePtr, true);
    asm("NOP");
    asm("NOP");
    asm("NOP");
    asm("NOP");
    Usart_LL_SetClearRecvBufferSta(hwDesc->UartBasePtr, false);
}

/**
 * @brief uart clear send buffer
 *
 * @param Module Uart module
 */
static void Uart_Im_ClearSendBuffer(Uart_ModuleType Module)
{
    const Uart_DescType *hwDesc = &Uart_Im_Info[(uint32)Module];

    Usart_LL_SetClearTransBufferSta(hwDesc->UartBasePtr, true);
    asm("NOP");
    asm("NOP");
    asm("NOP");
    asm("NOP");
    Usart_LL_SetClearTransBufferSta(hwDesc->UartBasePtr, false);
}

/**
 * @brief Get the DMA trigger source corresponding to the USART module
 *
 * Based on the USART module type, DMA source type, and transmission direction,
 * look up the corresponding DMA trigger source configuration.
 * For the USART6 module, use a dedicated trigger source lookup table;
 * for USART1-3 modules, use a generic lookup table.
 *
 * @param Module Type of USART module, specifying the USART module to configure
 * @param DmaSource Type of DMA source, specifying whether it is transmit or receive DMA transfer
 * @param Direction Transmission direction is only valid for channel 4 of USART6, 0: transmit, 1: receive
 *
 * @return Returns the corresponding DMA trigger source enumeration value;
 * returns DMA_TRISRC_NONE if the module is not supported
 */
static Dma_TriggerSource_t
Uart_Im_GetDmaTrigSource(Uart_ModuleType Module, Uart_DmaSourceType DmaSource, uint8_t Direction)
{
    /**
     * @brief Usart dma TriggerSource
     */
    /* PRQA S 2203 ++ #KQR002203 */
    static const Dma_TriggerSource_t dmaTriggerSourceTable[4U] = {
      DMA_TRISRC_0_USART0_TX, DMA_TRISRC_0_USART1_TX, DMA_TRISRC_0_USART2_TX, DMA_TRISRC_1_USART3_TX};
    static const Dma_TriggerSource_t Uart6dmaTriggerSourceTable[7U][2U] = {
      {DMA_TRISRC_NONE, DMA_TRISRC_NONE},        {DMA_TRISRC_NONE, DMA_TRISRC_NONE},
      {DMA_TRISRC_2_USART6_TX, DMA_TRISRC_NONE}, {DMA_TRISRC_1_USART6_TX, DMA_TRISRC_2_USART6_RX},
      {DMA_TRISRC_NONE, DMA_TRISRC_1_USART6_RX}, {DMA_TRISRC_NONE, DMA_TRISRC_NONE},
      {DMA_TRISRC_NONE, DMA_TRISRC_NONE},
    };
    /* PRQA S 2203 -- #KQR002203 */
    Dma_TriggerSource_t triggerSourceX;

    /* Select the corresponding DMA trigger source lookup table according to the USART module type */
    if (Module == UART_MODULE_6)
    {
        /* USART6 uses a dedicated two-dimensional lookup table to obtain the trigger source based on the DMA source
         * type and transfer direction. */
        triggerSourceX = Uart6dmaTriggerSourceTable[DmaSource][Direction];
    }
    else if (Module <= UART_MODULE_3)
    {
        /* USART1-3 use a one-dimensional lookup table to directly obtain the trigger source based on the module index.
         */
        triggerSourceX = dmaTriggerSourceTable[(uint32_t)Module];
    }
    else
    {
        /* Unsupported USART module, return invalid trigger source */
        triggerSourceX = DMA_TRISRC_NONE;
    }

    return triggerSourceX;
}

/**
 * @brief uart send dam initialization
 *
 * @param Module Uart module
 */
static void Uart_Im_SendDmaInit(Uart_ModuleType Module)
{
    Dma_Channel_t      dmaChannel = (Dma_Channel_t)Uart_Im_DmaUserConfigInfo[Module].TxDmaChannel;
    Dma_RegisterMap_t *dmaPtr     = Uart_Im_DmaUserConfigInfo[Module].TxDmaBasePtr;
    /* dma index */
    uint8_t dmaIndex;

    if (DMA0_PTR == dmaPtr)
    {
        Rst_LL_SetDmaEnabled(RST_DMA0, true);
        Pclk_LL_SetDmaEnabled(PCLK_DMA0, true);
        dmaIndex = 0U;
    }
    else
    {
        Rst_LL_SetDmaEnabled(RST_DMA1, true);
        Pclk_LL_SetDmaEnabled(PCLK_DMA1, true);
        dmaIndex = 1U;
    }

    /* disable dma channel */
    Dma_LL_SetChannelEnabled(dmaPtr, dmaChannel, false);
    /* Select high Priority for DMA channel */
    Dma_LL_SetChannelPriority(dmaPtr, dmaChannel, DMA_PRIORITY_HIGH);
    /* Set Peripheral data size 8bits */
    Dma_LL_SetPeriphDataWidth(dmaPtr, dmaChannel, DMA_DATA_WIDTH_8_BITS);
    /* Set Memory data size 8bits */
    Dma_LL_SetMemDataWidth(dmaPtr, dmaChannel, DMA_DATA_WIDTH_8_BITS);
    /* Disable Peripheral address increment mode in oder to read only register */
    Dma_LL_SetPeriphAddrIncrement(dmaPtr, dmaChannel, false);
    /* Enable memory address increment mode */
    Dma_LL_SetMemAddrIncrement(dmaPtr, dmaChannel, true);
    /* disable loop mode */
    Dma_LL_SetLoopModeEnabled(dmaPtr, dmaChannel, false);
    /* DMATransmission direction */
    Dma_LL_SetDataDirection(dmaPtr, dmaChannel, DMA_DATA_DIR_MEM_TO_PERIPH);
    /* uart trigger once to DMA transmit once */
    Dma_LL_SetBlockMode(dmaPtr, dmaChannel, DMA_BLOCK_TRANSFER_BYTE);
    /* used BUFR register as the DMA peripheral address */
    Dma_LL_SetPeriphAddr(dmaPtr, dmaChannel, (uint32)(&Uart_Im_Info[Module].UartBasePtr->BUFR));
    /* Set DMA memory start address */
    Dma_LL_SetMemAddr(dmaPtr, dmaChannel, Uart_Im_DmaUserConfigInfo[Module].TxMemoryAddr);
    /* Transfer $numTransfer$ bytes at a time */
    Dma_LL_SetNumberOfData(dmaPtr, dmaChannel, Uart_Im_DmaUserConfigInfo[Module].TxMemorySize);
    /* Set trigger source */
    /* PRQA S 4322 1 #KQR004322 */
    Dma_TriggerSource_t triggerSource = Uart_Im_GetDmaTrigSource(Module, (Uart_DmaSourceType)dmaChannel, 0U);
    if (triggerSource != DMA_TRISRC_NONE)
    {
        Dma_LL_SelectTrigSource(dmaPtr, dmaChannel, triggerSource);
        Dma_LL_SetTriggerEnabled(dmaPtr, dmaChannel, true);
    }
    else
    {
        Dma_LL_SetTriggerEnabled(dmaPtr, dmaChannel, false);
    }
    /* disable dma oneshot */
    Dma_LL_SetOneShotEnabled(dmaPtr, dmaChannel, true);
    /* register interrupt handler */
    Dma_RegisterCustomHandler(dmaIndex, dmaChannel, Uart_DmaIntrTxHandle[Module]);
}

/**
 * @brief uart receive dam initialization
 *
 * @param Module Uart module
 */
static void Uart_Im_ReceiveDmaInit(Uart_ModuleType Module)
{
    Dma_Channel_t      dmaChannel = (Dma_Channel_t)Uart_Im_DmaUserConfigInfo[Module].RxDmaChannel;
    Dma_RegisterMap_t *dmaPtr     = Uart_Im_DmaUserConfigInfo[Module].RxDmaBasePtr;
    /* dma index */
    uint8_t dmaIndex;

    if (DMA0_PTR == dmaPtr)
    {
        Rst_LL_SetDmaEnabled(RST_DMA0, true);
        Pclk_LL_SetDmaEnabled(PCLK_DMA0, true);
        dmaIndex = 0U;
    }
    else
    {
        Rst_LL_SetDmaEnabled(RST_DMA1, true);
        Pclk_LL_SetDmaEnabled(PCLK_DMA1, true);
        dmaIndex = 1U;
    }

    /* disable dma channel */
    Dma_LL_SetChannelEnabled(dmaPtr, dmaChannel, false);
    /* Select high Priority for DMA channel */
    Dma_LL_SetChannelPriority(dmaPtr, dmaChannel, DMA_PRIORITY_HIGH);
    /* Set Peripheral data size 8bits */
    Dma_LL_SetPeriphDataWidth(dmaPtr, dmaChannel, DMA_DATA_WIDTH_8_BITS);
    /* Set Memory data size 8bits */
    Dma_LL_SetMemDataWidth(dmaPtr, dmaChannel, DMA_DATA_WIDTH_8_BITS);
    /* Disable Peripheral address increment mode in oder to read only register */
    Dma_LL_SetPeriphAddrIncrement(dmaPtr, dmaChannel, false);
    /* Enable memory address increment mode */
    Dma_LL_SetMemAddrIncrement(dmaPtr, dmaChannel, true);
    /* disable loop mode */
    Dma_LL_SetLoopModeEnabled(dmaPtr, dmaChannel, false);
    /* DMATransmission direction */
    Dma_LL_SetDataDirection(dmaPtr, dmaChannel, DMA_DATA_DIR_PERIPH_TO_MEM);
    /* uart trigger once to DMA transmit once */
    Dma_LL_SetBlockMode(dmaPtr, dmaChannel, DMA_BLOCK_TRANSFER_BYTE);
    /* used BUFR register as the DMA peripheral address */
    Dma_LL_SetPeriphAddr(dmaPtr, dmaChannel, (uint32)(&Uart_Im_Info[Module].UartBasePtr->BUFR));
    /* Set DMA memory start address */
    Dma_LL_SetMemAddr(dmaPtr, dmaChannel, Uart_Im_DmaUserConfigInfo[Module].RxMemoryAddr);
    /* Transfer $numTransfer$ bytes at a time */
    Dma_LL_SetNumberOfData(dmaPtr, dmaChannel, Uart_Im_DmaUserConfigInfo[Module].RxMemorySize);
    /* Set trigger source */
    /* PRQA S 4322 1 #KQR004322 */
    Dma_TriggerSource_t triggerSource = Uart_Im_GetDmaTrigSource(Module, (Uart_DmaSourceType)dmaChannel, 1U);
    if (triggerSource != DMA_TRISRC_NONE)
    {
        Dma_LL_SelectTrigSource(dmaPtr, dmaChannel, triggerSource);
        Dma_LL_SetTriggerEnabled(dmaPtr, dmaChannel, true);
    }
    else
    {
        Dma_LL_SetTriggerEnabled(dmaPtr, dmaChannel, false);
    }
    Dma_LL_SetTriggerEnabled(dmaPtr, dmaChannel, true);

    /* register interrupt handler */
    Dma_RegisterCustomHandler(dmaIndex, dmaChannel, Uart_DmaIntrRxHandle[Module]);
}

/**
 * @brief uart send dma config
 *
 * @param Module Uart module
 * @param UartConfig Uart config information
 */
static void Uart_Im_SendDmaConfig(Uart_ModuleType Module, const Uart_ChannelConfigType *UartConfig)
{
    Usart_RegisterMap_t *uartPtr = Uart_Im_Info[Module].UartBasePtr;

    /* set status */
    Uart_Im_DmaUserConfigInfo[Module].TxDmaStatus  = UART_DMA_ENABLE;
    Uart_Im_DmaUserConfigInfo[Module].TxMemoryAddr = (uint32)&Uart_Im_DefaultBuffer[0];
    Uart_Im_DmaUserConfigInfo[Module].TxMemorySize = (uint16)sizeof(Uart_Im_DefaultBuffer);

    /* dma config information */
    if (UartConfig->DmaConfigPtr->TxDmaSource < UART_DMA1_CHANNEL_1)
    {
        Uart_Im_DmaUserConfigInfo[Module].TxDmaBasePtr = DMA0_PTR;
        Uart_Im_DmaUserConfigInfo[Module].TxDmaChannel = (uint8)UartConfig->DmaConfigPtr->TxDmaSource;
    }
    else
    {
        Uart_Im_DmaUserConfigInfo[Module].TxDmaBasePtr = DMA1_PTR;
        Uart_Im_DmaUserConfigInfo[Module].TxDmaChannel =
          (uint8)((uint8)UartConfig->DmaConfigPtr->TxDmaSource - (uint8)UART_DMA1_CHANNEL_1);
    }

    /* dma interrupt receive */
    Uart_Im_SendDmaInit(Module);
    /* enable uart dma */
    Usart_LL_SetTransDmaEnabled(uartPtr, true);
}

/**
 * @brief uart receive dma config
 *
 * @param Module Uart module
 * @param UartConfig Uart config information
 */
static void Uart_Im_ReceiveDmaConfig(Uart_ModuleType Module, const Uart_ChannelConfigType *UartConfig)
{
    Usart_RegisterMap_t *uartPtr = Uart_Im_Info[Module].UartBasePtr;

    /* set status */
    Uart_Im_DmaUserConfigInfo[Module].RxDmaStatus  = UART_DMA_ENABLE;
    Uart_Im_DmaUserConfigInfo[Module].RxMemoryAddr = (uint32)&Uart_Im_DefaultBuffer[0];
    Uart_Im_DmaUserConfigInfo[Module].RxMemorySize = (uint16)sizeof(Uart_Im_DefaultBuffer);
    Uart_Im_DmaUserConfigInfo[Module].UpdateStatus = UART_DMA_UPDATE_INIT;

    /* dma config information */
    if (UartConfig->DmaConfigPtr->RxDmaSource < UART_DMA1_CHANNEL_1)
    {
        Uart_Im_DmaUserConfigInfo[Module].RxDmaBasePtr = DMA0_PTR;
        Uart_Im_DmaUserConfigInfo[Module].RxDmaChannel = (uint8)UartConfig->DmaConfigPtr->RxDmaSource;
    }
    else
    {
        Uart_Im_DmaUserConfigInfo[Module].RxDmaBasePtr = DMA1_PTR;
        Uart_Im_DmaUserConfigInfo[Module].RxDmaChannel =
          (uint8)((uint8)UartConfig->DmaConfigPtr->RxDmaSource - (uint8)UART_DMA1_CHANNEL_1);
    }

    /* dma interrupt receive */
    Uart_Im_ReceiveDmaInit(Module);
    /* enable uart dma */
    Usart_LL_SetRecvDmaEnabled(uartPtr, true);
}

/**
 * @brief reset Uart module
 *
 * @param Module Uart module
 */
static void Uart_Im_Reset(Uart_ModuleType Module)
{
    switch (Module)
    {
    case UART_MODULE_0:
        Rst_LL_SetUsartEnabled(RST_USART0, false);
        Rst_LL_SetUsartEnabled(RST_USART0, true);
        Pclk_LL_SetUsartEnabled(PCLK_USART0, true);
        break;
    case UART_MODULE_1:
        Rst_LL_SetUsartEnabled(RST_USART1, false);
        Rst_LL_SetUsartEnabled(RST_USART1, true);
        Pclk_LL_SetUsartEnabled(PCLK_USART1, true);
        break;
    case UART_MODULE_2:
        Rst_LL_SetUsartEnabled(RST_USART2, false);
        Rst_LL_SetUsartEnabled(RST_USART2, true);
        Pclk_LL_SetUsartEnabled(PCLK_USART2, true);
        break;
    case UART_MODULE_3:
        Rst_LL_SetUsartEnabled(RST_USART3, false);
        Rst_LL_SetUsartEnabled(RST_USART3, true);
        Pclk_LL_SetUsartEnabled(PCLK_USART3, true);
        break;
    case UART_MODULE_6:
        Rst_LL_SetUsartEnabled(RST_USART6, false);
        Rst_LL_SetUsartEnabled(RST_USART6, true);
        Pclk_LL_SetUsartEnabled(PCLK_USART6, true);
        break;
    /* PRQA S 2016 1 #KQR002016 */
    default:
        break;
    }
}

/**
 * @brief write uart buffer send data
 *
 * @param UartPtr Uart unit pointer
 * @param Data send data
 * @param SendLength Length of transmission
 * @param Timeout time out value,zero for infinite waiting
 *
 * @return kf_status_t
 * @retval STATUS_OK
 * @retval STATUS_TIMEOUT
 */
static kf_status_t Uart_Im_SendByte(Usart_RegisterMap_t *const UartPtr, const uint8 Data, const uint32 Timeout)
{
    volatile uint32 waitFlag = 0x0U;
    volatile uint32 countOut;
    kf_status_t     ret = STATUS_OK;

    if ((NULL_PTR == UartPtr) || (0U == Timeout))
    {
        ret = STATUS_ERROR;
    }
    else
    {
        while ((!Usart_LL_GetIntrFlag(UartPtr, USART_INT_GET_TFEIF1)) && (waitFlag != Timeout))
        {
            waitFlag++;
        }
        /* PRQA S 3345 1 #KQR003345 */
        if (waitFlag == Timeout)
        {
            ret = STATUS_TIMEOUT;
        }
        else
        {
            Usart_LL_SetTxBufferData(UartPtr, Data);
        }

        countOut = 0xFFFFU;
        do
        {
            countOut--;
            /* PRQA S 4115  1 #KQR004115 */
        } while (!Usart_LL_GetIntrFlag(UartPtr, USART_INT_GET_TXEIF) && (countOut));
    }

    return ret;
}

/**
 * @brief Synchronous send data by write buffer
 *
 * @param Module Uart module
 * @param SendData A pointer to the send data
 * @param SendLength Length of transmission
 * @param Timeout time out value,zero for infinite waiting
 *
 * @return Uart_Im_StatusType
 * @retval UART_STATUS_OK
 * @retval UART_STATUS_TIMEOUT
 */
static Uart_Im_StatusType
Uart_Im_SyncSendByWriteReg(Uart_ModuleType Module, const uint8 *SendData, uint16 SendLength, uint32 TimeOut)
{
    Uart_Im_StatusType   retStatus = UART_STATUS_OK;
    volatile uint16      loop      = 0U;
    const Uart_DescType *hwDesc    = &Uart_Im_Info[(uint32)Module];

    if ((Uart_Im_TransferInfo[Module].TransferState & UART_IM_TRANSFER_STATE_BUSY_SEND) == 0U)
    {
        Uart_Im_TransferInfo[Module].TransferState |= UART_IM_TRANSFER_STATE_BUSY_SEND;

        /* disable interrupt */
        Usart_LL_SetIntrEnabled(hwDesc->UartBasePtr, USART_INT_SET_TXEIE, false);

        while (loop < SendLength)
        {
            if (0U == TimeOut)
            {
                while (STATUS_OK != Uart_Im_SendByte(hwDesc->UartBasePtr, SendData[loop], 0xFFFU))
                {
                    ;
                }
            }
            else
            {
                if (STATUS_OK != Uart_Im_SendByte(hwDesc->UartBasePtr, SendData[loop], TimeOut))
                {
                    retStatus = UART_STATUS_TIMEOUT;
                    break;
                }
                else
                {
                    /* Do Nothing */
                }
            }

            loop++;
        }

        Uart_Im_TransferInfo[Module].TransferState &= (uint8)(~UART_IM_TRANSFER_STATE_BUSY_SEND);
    }
    else
    {
        retStatus = UART_STATUS_BUSY;
    }

    return retStatus;
}

/**
 * @brief Synchronous send data by dma
 *
 * @param Module Usart module
 * @param SendData A pointer to the send data
 * @param SendLength Length of transmission
 * @param Timeout time out value,zero for infinite waiting
 *
 * @return Uart_Im_StatusType
 * @retval UART_STATUS_TIMEOUT
 * @retval UART_STATUS_BUSY
 */
static Uart_Im_StatusType
Uart_Im_SyncSendByDma(Uart_ModuleType Module, const uint8 *SendData, uint16 SendLength, uint32 TimeOut)
{
    Uart_Im_StatusType retStatus = UART_STATUS_OK;
    /* timeout */
    volatile uint32      sendTimeOut = TimeOut;
    const Uart_DescType *hwDesc      = &Uart_Im_Info[(uint32)Module];

    if ((Uart_Im_TransferInfo[Module].TransferState & UART_IM_TRANSFER_STATE_BUSY_SEND) == 0U)
    {
        Uart_Im_TransferInfo[Module].TransferState |= UART_IM_TRANSFER_STATE_BUSY_SEND;
        Dma_LL_SetFinishTransIntrEnabled(
          Uart_Im_DmaUserConfigInfo[Module].TxDmaBasePtr, (Dma_Channel_t)Uart_Im_DmaUserConfigInfo[Module].TxDmaChannel,
          false);

        Dma_LL_ClearIntrFlag(Uart_Im_DmaUserConfigInfo[Module].TxDmaBasePtr,
                             (Dma_Channel_t)Uart_Im_DmaUserConfigInfo[Module].TxDmaChannel, DMA_LIFR_FTIF_LOGIC_BIT);

        /* disable dma channel */
        Dma_LL_SetChannelEnabled(
          Uart_Im_DmaUserConfigInfo[Module].TxDmaBasePtr, (Dma_Channel_t)Uart_Im_DmaUserConfigInfo[Module].TxDmaChannel,
          false);

        Dma_LL_SetMemAddr(Uart_Im_DmaUserConfigInfo[Module].TxDmaBasePtr,
                          (Dma_Channel_t)Uart_Im_DmaUserConfigInfo[Module].TxDmaChannel, (uint32)SendData);
        Dma_LL_SetNumberOfData(
          Uart_Im_DmaUserConfigInfo[Module].TxDmaBasePtr, (Dma_Channel_t)Uart_Im_DmaUserConfigInfo[Module].TxDmaChannel,
          SendLength);

        /* enable dma channel */
        Dma_LL_SetChannelEnabled(
          Uart_Im_DmaUserConfigInfo[Module].TxDmaBasePtr, (Dma_Channel_t)Uart_Im_DmaUserConfigInfo[Module].TxDmaChannel,
          true);

        while ((!Dma_LL_GetFinishTransIntrFlag(Uart_Im_DmaUserConfigInfo[Module].TxDmaBasePtr,
                                               (Dma_Channel_t)Uart_Im_DmaUserConfigInfo[Module].TxDmaChannel)) &&
               ((!(TimeOut != 0U)) || (sendTimeOut != 0U)))
        {
            sendTimeOut--;
        }

        Dma_LL_ClearIntrFlag(Uart_Im_DmaUserConfigInfo[Module].TxDmaBasePtr,
                             (Dma_Channel_t)Uart_Im_DmaUserConfigInfo[Module].TxDmaChannel, DMA_LIFR_FTIF_LOGIC_BIT);

        if (0U == sendTimeOut)
        {
            retStatus = UART_STATUS_TIMEOUT;
        }
        else
        {
            volatile uint32 countOut = 0xFFFFU;
            do
            {
                countOut--;
                /* PRQA S 4115  1 #KQR004115 */
            } while (!Usart_LL_GetIntrFlag(hwDesc->UartBasePtr, USART_INT_GET_TXEIF) && (countOut));
        }

        Uart_Im_TransferInfo[Module].TransferState &= (uint8)(~UART_IM_TRANSFER_STATE_BUSY_SEND);
    }
    else
    {
        retStatus = UART_STATUS_BUSY;
    }

    return retStatus;
}

/**
 * @brief Asynchronous send data by write buffer
 *
 * @param Module Usart module
 * @param SendData A pointer to the send data
 * @param SendLength Length of transmission
 *
 * @return Uart_Im_StatusType
 * @retval UART_STATUS_OK
 * @retval UART_STATUS_BUSY
 */
static Uart_Im_StatusType Uart_Im_AsyncSendByWriteReg(Uart_ModuleType Module, const uint8 *SendData, uint16 SendLength)
{
    const Uart_DescType *hwDesc    = &Uart_Im_Info[(uint32)Module];
    Uart_Im_StatusType   retStatus = UART_STATUS_OK;

    if ((Uart_Im_TransferInfo[Module].TransferState & UART_IM_TRANSFER_STATE_BUSY_SEND) == 0U)
    {
        /* update send information */
        /* PRQA S 0311 1 #KQR000311 */
        Uart_Im_TransferInfo[Module].SendIntrInfo.DataBuffer = (uint8 *)SendData;
        Uart_Im_TransferInfo[Module].SendIntrInfo.Length     = SendLength;
        Uart_Im_TransferInfo[Module].SendIntrInfo.Index      = 0U;
        Uart_Im_TransferInfo[Module].TransferState |= UART_IM_TRANSFER_STATE_BUSY_SEND;

        Usart_LL_SetTxBufferData(hwDesc->UartBasePtr, SendData[0]);
        Usart_LL_SetIntrEnabled(hwDesc->UartBasePtr, USART_INT_SET_TXEIE, true);
    }
    else
    {
        retStatus = UART_STATUS_BUSY;
    }

    return retStatus;
}

/**
 * @brief Asynchronous send data by dma
 *
 * @param Module Usart module
 * @param SendData A pointer to the send data
 * @param SendLength Length of transmission
 *
 * @return Uart_Im_StatusType
 * @retval UART_STATUS_OK
 * @retval UART_STATUS_BUSY
 */
static Uart_Im_StatusType Uart_Im_AsyncSendByDma(Uart_ModuleType Module, const uint8 *SendData, uint16 SendLength)
{
    Uart_Im_StatusType retStatus = UART_STATUS_OK;

    if ((Uart_Im_TransferInfo[Module].TransferState & UART_IM_TRANSFER_STATE_BUSY_SEND) == 0U)
    {
        Uart_Im_TransferInfo[Module].TransferState |= UART_IM_TRANSFER_STATE_BUSY_SEND;

        Dma_LL_SetFinishTransIntrEnabled(
          Uart_Im_DmaUserConfigInfo[Module].TxDmaBasePtr, (Dma_Channel_t)Uart_Im_DmaUserConfigInfo[Module].TxDmaChannel,
          false);

        Dma_LL_ClearIntrFlag(Uart_Im_DmaUserConfigInfo[Module].TxDmaBasePtr,
                             (Dma_Channel_t)Uart_Im_DmaUserConfigInfo[Module].TxDmaChannel, DMA_LIFR_FTIF_LOGIC_BIT);

        /* disable dma channel */
        Dma_LL_SetChannelEnabled(
          Uart_Im_DmaUserConfigInfo[Module].TxDmaBasePtr, (Dma_Channel_t)Uart_Im_DmaUserConfigInfo[Module].TxDmaChannel,
          false);

        Dma_LL_SetMemAddr(Uart_Im_DmaUserConfigInfo[Module].TxDmaBasePtr,
                          (Dma_Channel_t)Uart_Im_DmaUserConfigInfo[Module].TxDmaChannel, (uint32)SendData);
        Dma_LL_SetNumberOfData(
          Uart_Im_DmaUserConfigInfo[Module].TxDmaBasePtr, (Dma_Channel_t)Uart_Im_DmaUserConfigInfo[Module].TxDmaChannel,
          SendLength);

        Dma_LL_SetFinishTransIntrEnabled(
          Uart_Im_DmaUserConfigInfo[Module].TxDmaBasePtr, (Dma_Channel_t)Uart_Im_DmaUserConfigInfo[Module].TxDmaChannel,
          true);

        /* enable dma channel */
        Dma_LL_SetChannelEnabled(
          Uart_Im_DmaUserConfigInfo[Module].TxDmaBasePtr, (Dma_Channel_t)Uart_Im_DmaUserConfigInfo[Module].TxDmaChannel,
          true);
    }
    else
    {
        retStatus = UART_STATUS_BUSY;
    }

    return retStatus;
}

/**
 * @brief Synchronous receiving data by read buffer
 *
 * @param Module Usart module
 * @param Buffer read buffer
 * @param BufferSize Length of read
 * @param Timeout time out value,zero for infinite waiting
 *
 * @return Uart_Im_StatusType
 * @retval UART_STATUS_OK
 * @retval UART_STATUS_TIMEOUT
 * @retval UART_STATUS_BUSY
 */
static Uart_Im_StatusType
Uart_Im_SyncReceiveDataByReadReg(Uart_ModuleType Module, uint8 *Buffer, uint16 BufferSize, uint32 Timeout)
{
    Uart_Im_StatusType ret      = UART_STATUS_OK;
    uint16             tmpLen   = 0U;
    uint32             waitFlag = 0U;

    if ((Uart_Im_TransferInfo[Module].TransferState & UART_IM_TRANSFER_STATE_BUSY_RECEIVE) == 0U)
    {
        Uart_Im_TransferInfo[Module].TransferState |= UART_IM_TRANSFER_STATE_BUSY_RECEIVE;

        Usart_LL_SetIntrEnabled(Uart_Im_Info[Module].UartBasePtr, USART_INT_SET_RDRIE, false);
        Usart_LL_SetReceiveDataEnabled(Uart_Im_Info[Module].UartBasePtr, true);

        /* dummy read to clear RDRIF */
        (void)Usart_LL_GetRxBufferData(Uart_Im_Info[Module].UartBasePtr);
        Uart_Im_ClearRecvBuffer(Module);

        for (; tmpLen < BufferSize; tmpLen++)
        {
            while ((!Usart_LL_GetIntrFlag(Uart_Im_Info[Module].UartBasePtr, USART_INT_GET_RDRIF)) &&
                   ((Timeout == 0U) || (waitFlag < Timeout)))
            {
                waitFlag++;
            }

            if ((Timeout > 0U) && (waitFlag >= Timeout))
            {
                ret = UART_STATUS_TIMEOUT;
                break;
            }
            else
            {
                Buffer[tmpLen] = (uint8)Usart_LL_GetRxBufferData(Uart_Im_Info[Module].UartBasePtr);
            }
        }

        Usart_LL_SetReceiveDataEnabled(Uart_Im_Info[Module].UartBasePtr, false);
        Uart_Im_TransferInfo[Module].TransferState &= (uint8)(~UART_IM_TRANSFER_STATE_BUSY_RECEIVE);
    }
    else
    {
        ret = UART_STATUS_BUSY;
    }

    return ret;
}

/**
 * @brief Synchronous receiving data by dma
 *
 * @param Module Usart module
 * @param Buffer read buffer
 * @param BufferSize Length of read
 * @param Timeout time out value,zero for infinite waiting
 *
 * @return Uart_Im_StatusType
 * @retval UART_STATUS_OK
 * @retval UART_STATUS_TIMEOUT
 * @retval UART_STATUS_BUSY
 */
static Uart_Im_StatusType
Uart_Im_SyncReceiveDataByDma(Uart_ModuleType Module, const uint8 *Buffer, uint16 BufferSize, uint32 TimeOut)
{
    Uart_Im_StatusType ret      = UART_STATUS_OK;
    uint32             waitFlag = 0U;

    if ((Uart_Im_TransferInfo[Module].TransferState & UART_IM_TRANSFER_STATE_BUSY_RECEIVE) == 0U)
    {
        Uart_Im_TransferInfo[Module].TransferState |= UART_IM_TRANSFER_STATE_BUSY_RECEIVE;

        Usart_LL_SetIntrEnabled(Uart_Im_Info[Module].UartBasePtr, USART_INT_SET_RDRIE, false);
        Usart_LL_SetIntrEnabled(Uart_Im_Info[Module].UartBasePtr, USART_INT_SET_IDLEIE, false);
        Usart_LL_SetReceiveDataEnabled(Uart_Im_Info[Module].UartBasePtr, true);

        /* disable DMA channel */
        Dma_LL_SetChannelEnabled(
          Uart_Im_DmaUserConfigInfo[Module].RxDmaBasePtr, (Dma_Channel_t)Uart_Im_DmaUserConfigInfo[Module].RxDmaChannel,
          false);

        Dma_LL_SetFinishTransIntrEnabled(
          Uart_Im_DmaUserConfigInfo[Module].RxDmaBasePtr, (Dma_Channel_t)Uart_Im_DmaUserConfigInfo[Module].RxDmaChannel,
          false);

        Uart_Im_DmaUserConfigInfo[Module].RxMemoryAddr = (uint32)Buffer;
        Uart_Im_DmaUserConfigInfo[Module].RxMemorySize = BufferSize;

        Dma_LL_SetMemAddr(
          Uart_Im_DmaUserConfigInfo[Module].RxDmaBasePtr, (Dma_Channel_t)Uart_Im_DmaUserConfigInfo[Module].RxDmaChannel,
          (uint32)Uart_Im_DmaUserConfigInfo[Module].RxMemoryAddr);
        Dma_LL_SetNumberOfData(
          Uart_Im_DmaUserConfigInfo[Module].RxDmaBasePtr, (Dma_Channel_t)Uart_Im_DmaUserConfigInfo[Module].RxDmaChannel,
          Uart_Im_DmaUserConfigInfo[Module].RxMemorySize);

        /* dummy read to clear RDRIF */
        (void)Usart_LL_GetRxBufferData(Uart_Im_Info[Module].UartBasePtr);
        Uart_Im_ClearRecvBuffer(Module);

        /* enable DMA channel */
        Dma_LL_SetChannelEnabled(
          Uart_Im_DmaUserConfigInfo[Module].RxDmaBasePtr, (Dma_Channel_t)Uart_Im_DmaUserConfigInfo[Module].RxDmaChannel,
          true);

        while ((!Dma_LL_GetFinishTransIntrFlag(Uart_Im_DmaUserConfigInfo[Module].RxDmaBasePtr,
                                               (Dma_Channel_t)Uart_Im_DmaUserConfigInfo[Module].RxDmaChannel)) &&
               ((TimeOut == 0U) || (waitFlag < TimeOut)))
        {
            waitFlag++;
        }

        if ((TimeOut > 0U) && (waitFlag >= TimeOut))
        {
            ret = UART_STATUS_TIMEOUT;
        }
        else
        {
            /* disable DMA channel */
            Dma_LL_SetChannelEnabled(
              Uart_Im_DmaUserConfigInfo[Module].RxDmaBasePtr,
              (Dma_Channel_t)Uart_Im_DmaUserConfigInfo[Module].RxDmaChannel, false);

            Dma_LL_ClearFinishTransIntrFlag(
              Uart_Im_DmaUserConfigInfo[Module].RxDmaBasePtr,
              (Dma_Channel_t)Uart_Im_DmaUserConfigInfo[Module].RxDmaChannel);
        }

        Usart_LL_SetReceiveDataEnabled(Uart_Im_Info[Module].UartBasePtr, false);
        Uart_Im_TransferInfo[Module].TransferState &= (uint8)(~UART_IM_TRANSFER_STATE_BUSY_RECEIVE);
    }
    else
    {
        ret = UART_STATUS_BUSY;
    }

    return ret;
}

/**
 * @brief Asynchronously received data by read buffer,enable interrupt
 *
 * @param Module Usart module
 * @param Buffer read buffer
 * @param BufferSize Length of read
 *
 * @return Uart_Im_StatusType
 * @retval UART_STATUS_OK
 * @retval UART_STATUS_TIMEOUT
 * @retval UART_STATUS_BUSY
 */
static Uart_Im_StatusType Uart_Im_AsyncReceiveByReadReg(Uart_ModuleType Module, uint8 *Buffer, uint16 BufferSize)
{
    Uart_Im_StatusType retStatus = UART_STATUS_OK;

    if ((Uart_Im_TransferInfo[Module].TransferState & UART_IM_TRANSFER_STATE_BUSY_RECEIVE) == 0U)
    {
        Uart_Im_TransferInfo[Module].TransferState |= UART_IM_TRANSFER_STATE_BUSY_RECEIVE;
        Uart_Im_TransferInfo[Module].RecIntrInfo.DataBuffer = Buffer;
        Uart_Im_TransferInfo[Module].RecIntrInfo.Index      = 0U;
        if (BufferSize == 0U)
        {
            Uart_Im_TransferInfo[Module].RecIntrInfo.Length = UART_RX_DATA_MAX_SIZE;
            Usart_LL_SetRecvIdleFrameIntMode(Uart_Im_Info[Module].UartBasePtr, true);
            Usart_LL_SetIntrEnabled(Uart_Im_Info[Module].UartBasePtr, USART_INT_SET_IDLEIE, true);
        }
        /* the data size is certain, the whole process is run by read-data-ready interrupt */
        else
        {
            Uart_Im_TransferInfo[Module].RecIntrInfo.Length = BufferSize;
            Usart_LL_SetIntrEnabled(Uart_Im_Info[Module].UartBasePtr, USART_INT_SET_IDLEIE, false);
        }

        /* dummy read to clear RDRIF */
        (void)Usart_LL_GetRxBufferData(Uart_Im_Info[Module].UartBasePtr);
        Uart_Im_ClearRecvBuffer(Module);
        Usart_LL_SetIntrEnabled(Uart_Im_Info[Module].UartBasePtr, USART_INT_SET_RDRIE, true);
        Usart_LL_SetReceiveDataEnabled(Uart_Im_Info[Module].UartBasePtr, true);
    }
    else
    {
        retStatus = UART_STATUS_BUSY;
    }

    return retStatus;
}

/**
 * @brief Asynchronously received data by read dma,enable interrupt
 *
 * @param Module Usart module
 * @param Buffer read buffer
 * @param BufferSize Length of read
 *
 * @return Uart_Im_StatusType
 * @retval UART_STATUS_OK
 * @retval UART_STATUS_BUSY
 */
static Uart_Im_StatusType Uart_Im_AsyncReceiveByDma(Uart_ModuleType Module, const uint8 *Buffer, uint16 BufferSize)
{
    Uart_Im_StatusType retStatus = UART_STATUS_OK;

    if ((Uart_Im_TransferInfo[Module].TransferState & UART_IM_TRANSFER_STATE_BUSY_RECEIVE) == 0U)
    {
        Uart_Im_TransferInfo[Module].TransferState |= UART_IM_TRANSFER_STATE_BUSY_RECEIVE;

        Usart_LL_SetReceiveDataEnabled(Uart_Im_Info[Module].UartBasePtr, false);
        Usart_LL_SetIntrEnabled(Uart_Im_Info[Module].UartBasePtr, USART_INT_SET_RDRIE, false);

        Dma_LL_SetChannelEnabled(
          Uart_Im_DmaUserConfigInfo[Module].RxDmaBasePtr, (Dma_Channel_t)Uart_Im_DmaUserConfigInfo[Module].RxDmaChannel,
          false);

        Uart_Im_DmaUserConfigInfo[Module].RxMemoryAddr = (uint32)Buffer;
        Dma_LL_SetMemAddr(
          Uart_Im_DmaUserConfigInfo[Module].RxDmaBasePtr, (Dma_Channel_t)Uart_Im_DmaUserConfigInfo[Module].RxDmaChannel,
          (uint32)Uart_Im_DmaUserConfigInfo[Module].RxMemoryAddr);

        /* not know the data size, the end of the process is indicated by idle interrupt */
        if (BufferSize == 0U)
        {
            Uart_Im_DmaUserConfigInfo[Module].RxMemorySize = UART_RX_DATA_MAX_SIZE;
            Dma_LL_SetNumberOfData(
              Uart_Im_DmaUserConfigInfo[Module].RxDmaBasePtr,
              (Dma_Channel_t)Uart_Im_DmaUserConfigInfo[Module].RxDmaChannel, UART_RX_DATA_MAX_SIZE);
            Usart_LL_SetRecvIdleFrameIntMode(Uart_Im_Info[Module].UartBasePtr, true);
            Dma_LL_SetFinishTransIntrEnabled(
              Uart_Im_DmaUserConfigInfo[Module].RxDmaBasePtr,
              (Dma_Channel_t)Uart_Im_DmaUserConfigInfo[Module].RxDmaChannel, false);
            Usart_LL_SetIntrEnabled(Uart_Im_Info[Module].UartBasePtr, USART_INT_SET_IDLEIE, true);
        }
        /* the data size is certain, the end of the process is indicated by DMA finish interrupt */
        else
        {
            Uart_Im_DmaUserConfigInfo[Module].RxMemorySize = BufferSize;
            Dma_LL_SetNumberOfData(
              Uart_Im_DmaUserConfigInfo[Module].RxDmaBasePtr,
              (Dma_Channel_t)Uart_Im_DmaUserConfigInfo[Module].RxDmaChannel,
              Uart_Im_DmaUserConfigInfo[Module].RxMemorySize);
            Dma_LL_SetFinishTransIntrEnabled(
              Uart_Im_DmaUserConfigInfo[Module].RxDmaBasePtr,
              (Dma_Channel_t)Uart_Im_DmaUserConfigInfo[Module].RxDmaChannel, true);
            Usart_LL_SetIntrEnabled(Uart_Im_Info[Module].UartBasePtr, USART_INT_SET_IDLEIE, false);
        }

        Dma_LL_SetChannelEnabled(
          Uart_Im_DmaUserConfigInfo[Module].RxDmaBasePtr, (Dma_Channel_t)Uart_Im_DmaUserConfigInfo[Module].RxDmaChannel,
          true);
        /* dummy read to clear RDRIF */
        (void)Usart_LL_GetRxBufferData(Uart_Im_Info[Module].UartBasePtr);
        Uart_Im_ClearRecvBuffer(Module);
        Usart_LL_SetReceiveDataEnabled(Uart_Im_Info[Module].UartBasePtr, true);
    }
    else
    {
        retStatus = UART_STATUS_BUSY;
    }

    return retStatus;
}

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
Uart_Im_StatusType Uart_Im_SyncSend(Uart_ModuleType Module, const uint8 *SendData, uint16 SendLength, uint32 TimeOut)
{
    Uart_Im_StatusType retStatus;

    if (UART_DMA_ENABLE == Uart_Im_DmaUserConfigInfo[Module].TxDmaStatus)
    {
        retStatus = Uart_Im_SyncSendByDma(Module, SendData, SendLength, TimeOut);
    }
    else
    {
        retStatus = Uart_Im_SyncSendByWriteReg(Module, SendData, SendLength, TimeOut);
    }

    return retStatus;
}

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
Uart_Im_StatusType Uart_Im_AsyncSend(Uart_ModuleType Module, const uint8 *SendData, uint16 SendLength)
{
    Uart_Im_StatusType retStatus;

    if (UART_DMA_ENABLE == Uart_Im_DmaUserConfigInfo[Module].TxDmaStatus)
    {
        retStatus = Uart_Im_AsyncSendByDma(Module, SendData, SendLength);
    }
    else
    {
        retStatus = Uart_Im_AsyncSendByWriteReg(Module, SendData, SendLength);
    }

    return retStatus;
}

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
Uart_Im_StatusType Uart_Im_AsyncPollingSend(Uart_ModuleType Module, const uint8 *SendData, uint16 SendLength)
{
    Uart_Im_StatusType retStatus = UART_STATUS_OK;

    if (Uart_Im_DmaUserConfigInfo[Module].TxDmaStatus == UART_DMA_ENABLE)
    {
        if ((Uart_Im_TransferInfo[Module].TransferState & UART_IM_TRANSFER_STATE_BUSY_SEND) == 0U)
        {
            Uart_Im_TransferInfo[Module].TransferState |= UART_IM_TRANSFER_STATE_BUSY_SEND;

            Dma_LL_SetFinishTransIntrEnabled(
              Uart_Im_DmaUserConfigInfo[Module].TxDmaBasePtr,
              (Dma_Channel_t)Uart_Im_DmaUserConfigInfo[Module].TxDmaChannel, false);

            Dma_LL_ClearIntrFlag(
              Uart_Im_DmaUserConfigInfo[Module].TxDmaBasePtr,
              (Dma_Channel_t)Uart_Im_DmaUserConfigInfo[Module].TxDmaChannel, DMA_LIFR_FTIF_LOGIC_BIT);

            /* disable dma channel */
            Dma_LL_SetChannelEnabled(
              Uart_Im_DmaUserConfigInfo[Module].TxDmaBasePtr,
              (Dma_Channel_t)Uart_Im_DmaUserConfigInfo[Module].TxDmaChannel, false);

            Dma_LL_SetMemAddr(Uart_Im_DmaUserConfigInfo[Module].TxDmaBasePtr,
                              (Dma_Channel_t)Uart_Im_DmaUserConfigInfo[Module].TxDmaChannel, (uint32)SendData);
            Dma_LL_SetNumberOfData(
              Uart_Im_DmaUserConfigInfo[Module].TxDmaBasePtr,
              (Dma_Channel_t)Uart_Im_DmaUserConfigInfo[Module].TxDmaChannel, SendLength);

            /* enable dma channel */
            Dma_LL_SetChannelEnabled(
              Uart_Im_DmaUserConfigInfo[Module].TxDmaBasePtr,
              (Dma_Channel_t)Uart_Im_DmaUserConfigInfo[Module].TxDmaChannel, true);
        }
        else
        {
            retStatus = UART_STATUS_BUSY;
        }
    }
    else
    {
        retStatus = UART_STATUS_DMA_NOT_ENABLED;
    }

    return retStatus;
}

/**
 * @brief Get the asynchronous polling sending status
 *
 * @param Module Usart module
 *
 * @return Uart_Im_StatusType
 * @retval UART_STATUS_OK
 * @retval UART_STATUS_BUSY
 */
Uart_Im_StatusType Uart_Im_GetAsyncPollingSendStatus(Uart_ModuleType Module)
{
    Uart_Im_StatusType   retStatus = UART_STATUS_OK;
    const Uart_DescType *hwDesc    = &Uart_Im_Info[(uint32)Module];

    if ((Uart_Im_TransferInfo[Module].TransferState & UART_IM_TRANSFER_STATE_BUSY_SEND) != 0U)
    {
        if ((!Dma_LL_GetFinishTransIntrFlag(Uart_Im_DmaUserConfigInfo[Module].TxDmaBasePtr,
                                            (Dma_Channel_t)Uart_Im_DmaUserConfigInfo[Module].TxDmaChannel)) ||
            (!Usart_LL_GetIntrFlag(hwDesc->UartBasePtr, USART_INT_GET_TXEIF)))
        {
            retStatus = UART_STATUS_BUSY;
        }
        else
        {
            /* clear dma finish flag */
            Dma_LL_ClearIntrFlag(
              Uart_Im_DmaUserConfigInfo[Module].TxDmaBasePtr,
              (Dma_Channel_t)Uart_Im_DmaUserConfigInfo[Module].TxDmaChannel, DMA_LIFR_FTIF_LOGIC_BIT);
            /* disable dma channel */
            Dma_LL_SetChannelEnabled(
              Uart_Im_DmaUserConfigInfo[Module].TxDmaBasePtr,
              (Dma_Channel_t)Uart_Im_DmaUserConfigInfo[Module].TxDmaChannel, false);

            Uart_Im_TransferInfo[Module].TransferState &= (uint8)(~UART_IM_TRANSFER_STATE_BUSY_SEND);
        }
    }
    else
    {
        retStatus = UART_STATUS_OK;
    }

    return retStatus;
}

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
Uart_Im_StatusType Uart_Im_SyncReceive(Uart_ModuleType Module, uint8 *Buffer, uint16 BufferSize, uint32 Timeout)
{
    Uart_Im_StatusType retStatus;

    if (UART_DMA_ENABLE == Uart_Im_DmaUserConfigInfo[Module].RxDmaStatus)
    {
        retStatus = Uart_Im_SyncReceiveDataByDma(Module, Buffer, BufferSize, Timeout);
    }
    else
    {
        retStatus = Uart_Im_SyncReceiveDataByReadReg(Module, Buffer, BufferSize, Timeout);
    }

    return retStatus;
}

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
Uart_Im_StatusType Uart_Im_AsyncReceive(Uart_ModuleType Module, uint8 *Buffer, uint16 BufferSize)
{
    Uart_Im_StatusType retStatus;

    if (UART_DMA_ENABLE == Uart_Im_DmaUserConfigInfo[Module].RxDmaStatus)
    {
        retStatus = Uart_Im_AsyncReceiveByDma(Module, Buffer, BufferSize);
    }
    else
    {
        retStatus = Uart_Im_AsyncReceiveByReadReg(Module, Buffer, BufferSize);
    }

    return retStatus;
}

/**
 * @brief Stop sending data
 *
 * @param Module Usart module
 *
 * @return Uart_Im_StatusType
 * @retval UART_STATUS_OK
 */
Uart_Im_StatusType Uart_Im_AbortSendingData(Uart_ModuleType Module)
{
    const Uart_DescType *hwDesc = &Uart_Im_Info[(uint32)Module];

    if ((Uart_Im_TransferInfo[Module].TransferState & UART_IM_TRANSFER_STATE_BUSY_SEND) != 0U)
    {
        /* asynchronous sending by DMA */
        if (Uart_Im_DmaUserConfigInfo[Module].TxDmaStatus == UART_DMA_ENABLE)
        {
            /* disable dma channel */
            Dma_LL_SetChannelEnabled(
              Uart_Im_DmaUserConfigInfo[Module].TxDmaBasePtr,
              (Dma_Channel_t)Uart_Im_DmaUserConfigInfo[Module].TxDmaChannel, false);
        }
        /* asynchronous sending by INTR */
        else
        {
            Usart_LL_SetIntrEnabled(hwDesc->UartBasePtr, USART_INT_SET_TXEIE, false);
        }
        Uart_Im_ClearSendBuffer(Module);
        Uart_Im_TransferInfo[Module].TransferState &= (uint8)(~UART_IM_TRANSFER_STATE_BUSY_SEND);
    }
    else
    {
        /* do nothing */
    }
    return UART_STATUS_OK;
}

/**
 * @brief Stop receiving data
 *
 * @param Module Usart module
 *
 * @return Uart_Im_StatusType
 * @retval UART_STATUS_OK
 */
Uart_Im_StatusType Uart_Im_AbortReceivingData(Uart_ModuleType Module)
{
    const Uart_DescType *hwDesc = &Uart_Im_Info[(uint32)Module];

    if ((Uart_Im_TransferInfo[Module].TransferState & UART_IM_TRANSFER_STATE_BUSY_RECEIVE) != 0U)
    {
        /* asynchronous receiving by DMA */
        if (Uart_Im_DmaUserConfigInfo[Module].RxDmaStatus == UART_DMA_ENABLE)
        {
            Usart_LL_SetReceiveDataEnabled(hwDesc->UartBasePtr, false);
            Dma_LL_SetChannelEnabled(
              Uart_Im_DmaUserConfigInfo[Module].RxDmaBasePtr,
              (Dma_Channel_t)Uart_Im_DmaUserConfigInfo[Module].RxDmaChannel, false);
        }
        /* asynchronous receiving by INTR */
        else
        {
            Usart_LL_SetReceiveDataEnabled(hwDesc->UartBasePtr, false);
            Usart_LL_SetIntrEnabled(hwDesc->UartBasePtr, USART_INT_SET_RDRIE, false);
        }
        /* dummy read to clear RDRIF */
        (void)Usart_LL_GetRxBufferData(hwDesc->UartBasePtr);
        Uart_Im_ClearRecvBuffer(Module);
        Uart_Im_TransferInfo[Module].TransferState &= (uint8)(~UART_IM_TRANSFER_STATE_BUSY_RECEIVE);
    }
    else
    {
        /* do nothing */
    }
    return UART_STATUS_OK;
}

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
Uart_Im_StatusType Uart_Im_GetTransferStatus(Uart_ModuleType Module, Uart_DataDirectionType TransferDir)
{
    Uart_Im_StatusType ret = UART_STATUS_OK;

    if (TransferDir == UART_SEND)
    {
        if ((Uart_Im_TransferInfo[Module].TransferState & UART_IM_TRANSFER_STATE_BUSY_SEND) != 0U)
        {
            ret = UART_STATUS_BUSY;
        }
        else
        {
            /* do nothing */
        }
    }
    else if (TransferDir == UART_RECEIVE)
    {
        if ((Uart_Im_TransferInfo[Module].TransferState & UART_IM_TRANSFER_STATE_BUSY_RECEIVE) != 0U)
        {
            ret = UART_STATUS_BUSY;
        }
        else
        {
            /* do nothing */
        }
    }
    else
    {
        /* do nothing */
    }

    return ret;
}

/**
 * @brief set the module in the reset state
 *
 * @param Module Usart module
 */
void Uart_Im_DeInitDevice(Uart_ModuleType Module)
{
    if (UART_MODULE_0 == Module)
    {
        Rst_LL_SetUsartEnabled(RST_USART0, false);
        Pclk_LL_SetUsartEnabled(PCLK_USART0, false);
    }
    else if (UART_MODULE_1 == Module)
    {
        Rst_LL_SetUsartEnabled(RST_USART1, false);
        Pclk_LL_SetUsartEnabled(PCLK_USART1, false);
    }
    else if (UART_MODULE_2 == Module)
    {
        Rst_LL_SetUsartEnabled(RST_USART2, false);
        Pclk_LL_SetUsartEnabled(PCLK_USART2, false);
    }
    else if (UART_MODULE_3 == Module)
    {
        Rst_LL_SetUsartEnabled(RST_USART3, false);
        Pclk_LL_SetUsartEnabled(PCLK_USART3, false);
    }
    else if (UART_MODULE_6 == Module)
    {
        Rst_LL_SetUsartEnabled(RST_USART6, false);
        Pclk_LL_SetUsartEnabled(PCLK_USART6, false);
    }
    else
    {
        /* Do Nothing */
    }
}

/**
 * @brief Uart Disable the DMA
 *
 * @param Module Usart module
 */
void Uart_Im_DmaDisable(Uart_ModuleType Module)
{

    if (UART_DMA_ENABLE == Uart_Im_DmaUserConfigInfo[Module].RxDmaStatus)
    {
        Dma_LL_ClearIntrFlag(Uart_Im_DmaUserConfigInfo[Module].RxDmaBasePtr,
                             (Dma_Channel_t)Uart_Im_DmaUserConfigInfo[Module].RxDmaChannel, DMA_LIFR_FTIF_LOGIC_BIT);
        Dma_LL_SetChannelEnabled(
          Uart_Im_DmaUserConfigInfo[Module].RxDmaBasePtr, (Dma_Channel_t)Uart_Im_DmaUserConfigInfo[Module].RxDmaChannel,
          false);
        Dma_LL_SetTriggerEnabled(
          Uart_Im_DmaUserConfigInfo[Module].RxDmaBasePtr, (Dma_Channel_t)Uart_Im_DmaUserConfigInfo[Module].RxDmaChannel,
          false);
        /* disable dma oneshot */
        Dma_LL_SetOneShotEnabled(
          Uart_Im_DmaUserConfigInfo[Module].RxDmaBasePtr, (Dma_Channel_t)Uart_Im_DmaUserConfigInfo[Module].RxDmaChannel,
          false);
    }
    else
    {
        /* Do Nothing */
    }

    if (UART_DMA_ENABLE == Uart_Im_DmaUserConfigInfo[Module].TxDmaStatus)
    {
        Dma_LL_ClearIntrFlag(Uart_Im_DmaUserConfigInfo[Module].TxDmaBasePtr,
                             (Dma_Channel_t)Uart_Im_DmaUserConfigInfo[Module].TxDmaChannel, DMA_LIFR_FTIF_LOGIC_BIT);
        Dma_LL_SetChannelEnabled(
          Uart_Im_DmaUserConfigInfo[Module].TxDmaBasePtr, (Dma_Channel_t)Uart_Im_DmaUserConfigInfo[Module].TxDmaChannel,
          false);
        Dma_LL_SetTriggerEnabled(
          Uart_Im_DmaUserConfigInfo[Module].TxDmaBasePtr, (Dma_Channel_t)Uart_Im_DmaUserConfigInfo[Module].TxDmaChannel,
          false);
        /* disable dma oneshot */
        Dma_LL_SetOneShotEnabled(
          Uart_Im_DmaUserConfigInfo[Module].TxDmaBasePtr, (Dma_Channel_t)Uart_Im_DmaUserConfigInfo[Module].TxDmaChannel,
          false);
    }
    else
    {
        /* Do Nothing */
    }
}

/**
 * @brief enable module
 *
 * @param Module Usart module
 */
void Uart_Im_Enable(Uart_ModuleType Module)
{
    Usart_LL_Enable(Uart_Im_Info[Module].UartBasePtr);
}

/**
 * @brief disable module
 *
 * @param Module Usart module
 */
void Uart_Im_Disable(Uart_ModuleType Module)
{
    Usart_LL_Disable(Uart_Im_Info[Module].UartBasePtr);
}

/**
 * @brief uart interrupt init
 *
 * @param Module Usart module
 * @param UartUnitConfig module config information
 */
void Uart_Im_IntrInit(Uart_ModuleType Module, const Uart_ChannelConfigType *UartUnitConfig)
{
    const Uart_DescType *hwDesc = &Uart_Im_Info[(uint32)Module];

    Usart_LL_SetIntrEnabled(hwDesc->UartBasePtr, USART_INT_SET_TXEIE, false);
    Usart_LL_SetIntrEnabled(hwDesc->UartBasePtr, USART_INT_SET_TFEIE, false);
    Usart_LL_SetIntrEnabled(hwDesc->UartBasePtr, USART_INT_SET_RDRIE, false);
    Usart_LL_SetIntrEnabled(hwDesc->UartBasePtr, USART_INT_SET_IDLEIE, false);

    Uart_Im_UserCallBackInit(Module, UartUnitConfig);
    /* register interrupt handle */
    Usart_RegisterCustomHandler((uint8)Module, &Uart_Im_InterruptHandler);
}

/**
 * @brief uart dma config initialize
 *
 * @param Module Usart module
 * @param UartUnitConfig module config information
 */
void Uart_Im_DmaConfig(Uart_ModuleType Module, const Uart_ChannelConfigType *UartUnitConfig)
{
    if (UartUnitConfig->DmaConfigPtr != NULL_PTR)
    {
        if (UART_DMA_ENABLE == UartUnitConfig->DmaConfigPtr->SendDmaSwitch)
        {
            Uart_Im_SendDmaConfig(Module, UartUnitConfig);
        }
        else
        {
            Uart_Im_DmaUserConfigInfo[Module].TxDmaStatus = UART_DMA_DISABLE;
        }

        if (UART_DMA_ENABLE == UartUnitConfig->DmaConfigPtr->ReceiveDmaSwitch)
        {
            Uart_Im_ReceiveDmaConfig(Module, UartUnitConfig);
        }
        else
        {
            Uart_Im_DmaUserConfigInfo[Module].RxDmaStatus = UART_DMA_DISABLE;
        }
    }
    else
    {
        Uart_Im_DmaUserConfigInfo[Module].TxDmaStatus = UART_DMA_DISABLE;
        Uart_Im_DmaUserConfigInfo[Module].RxDmaStatus = UART_DMA_DISABLE;
    }
}

/**
 * @brief uart pre-initialization
 *
 * @param Module Usart module
 * @param UartUnitConfig module config information
 */
void Uart_Im_PreInit(Uart_ModuleType Module, const Uart_ChannelConfigType *UartUnitConfig)
{
    Usart_RegisterMap_t *uartPtr = Uart_Im_Info[Module].UartBasePtr;

    Uart_Im_TransferInfo[Module].RecIntrInfo.DataBuffer  = NULL_PTR;
    Uart_Im_TransferInfo[Module].RecIntrInfo.Index       = 0U;
    Uart_Im_TransferInfo[Module].SendIntrInfo.DataBuffer = NULL_PTR;
    Uart_Im_TransferInfo[Module].SendIntrInfo.Index      = 0U;
    Uart_Im_TransferInfo[Module].TransferState           = UART_IM_TRANSFER_STATE_IDLE;

    /* reset UART */
    Uart_Im_Reset(Module);
    /* clear buffer */
    Uart_Im_ClearSendBuffer(Module);
    Uart_Im_ClearRecvBuffer(Module);

    if (UART_TX1 == UartUnitConfig->TxSelect)
    {
        Usart_LL_SelectPassageWay(uartPtr, true);
    }
    else
    {
        Usart_LL_SelectPassageWay(uartPtr, false);
    }

    Usart_LL_SelectSerialCommMode(uartPtr, false);
    /* PRQA S 4322 2 #KQR004322 */
    Usart_LL_SelectBaudRateGeneratorClk(uartPtr, (Usart_BaudrateClk_t)UartUnitConfig->BaudRateClkSrc);

    if (UART_PARITY_NONE == UartUnitConfig->ParityMode)
    {
        Usart_LL_SetBit9Enabled(uartPtr, false);
        /* set 8bits,parity inaction */
        Usart_LL_SelectParityCheck(uartPtr, false);
    }
    else
    {
        Usart_LL_SetBit9Enabled(uartPtr, true);
        if (UART_PARITY_ODD == UartUnitConfig->ParityMode)
        {
            Usart_LL_SelectParityCheck(uartPtr, false);
        }
        else
        {
            Usart_LL_SelectParityCheck(uartPtr, true);
        }
    }

    if (UART_STOP_BIT_1 == UartUnitConfig->StopBit)
    {
        Usart_LL_SelectStopBitLen(uartPtr, false);
    }
    else
    {
        Usart_LL_SelectStopBitLen(uartPtr, true);
    }

    if (UART_LSB_FIRST == UartUnitConfig->ReceiveOrder)
    {
        Usart_LL_SelectRecvOrder(uartPtr, false);
    }
    else
    {
        Usart_LL_SelectRecvOrder(uartPtr, true);
    }

    if (UART_LSB_FIRST == UartUnitConfig->SendOrder)
    {
        Usart_LL_SelectSendOrder(uartPtr, false);
    }
    else
    {
        Usart_LL_SelectSendOrder(uartPtr, true);
    }

    Usart_LL_SelectDataOfBit9(uartPtr, false);
    Usart_LL_SelectClkSrc(uartPtr, false);
    Usart_LL_SetAutoBaudRateDetectionEnabled(uartPtr, false);

    /* Configure UART baudRate */
    Usart_LL_SetBaudRate(
      uartPtr, UartUnitConfig->BaudRateInteger, UartUnitConfig->BaudRateNumerator, UartUnitConfig->BaudRateDenominator);

    /* enable transmit */
    Usart_LL_SetTransmitDataEnabled(uartPtr, true);
    /* Disable receive */
    Usart_LL_SetReceiveDataEnabled(uartPtr, false);
}

/**
 * @brief Uart module interrupt handler function
 *
 * @param Module uart module
 */
static void Uart_Im_InterruptHandler(uint8 Module)
{
    const Uart_DescType *hwDesc = &Uart_Im_Info[(uint32)Module];

    if (((uint8)(hwDesc->UartBasePtr->IER.bits.RDRIE) != 0U) &&
        (Usart_LL_GetIntrFlag(hwDesc->UartBasePtr, USART_INT_GET_RDRIF)))
    {
        if (((Uart_Im_TransferInfo[Module].TransferState & UART_IM_TRANSFER_STATE_BUSY_RECEIVE) != 0U) &&
            (Uart_Im_DmaUserConfigInfo[Module].RxDmaStatus == UART_DMA_DISABLE))
        {
            /* PRQA S 3440 2 #KQR003440 */
            Uart_Im_TransferInfo[Module].RecIntrInfo.DataBuffer[Uart_Im_TransferInfo[Module].RecIntrInfo.Index++] =
              (uint8)Usart_LL_GetRxBufferData(hwDesc->UartBasePtr);

            if (Uart_Im_TransferInfo[Module].RecIntrInfo.Index == Uart_Im_TransferInfo[Module].RecIntrInfo.Length)
            {
                /* disable uart receive */
                Usart_LL_SetReceiveDataEnabled(hwDesc->UartBasePtr, false);
                Usart_LL_SetIntrEnabled(hwDesc->UartBasePtr, USART_INT_SET_RDRIE, false);
                Uart_Im_TransferInfo[Module].TransferState &= (uint8)(~UART_IM_TRANSFER_STATE_BUSY_RECEIVE);
                Uart_Im_RecCompleteCallBackProcess(
                  (Uart_ModuleType)Module, Uart_Im_TransferInfo[Module].RecIntrInfo.Length);
            }
            else
            {
                /* Do Nothing */
            }
        }
        else
        {
            /* Do Nothing */
        }

        Uart_Im_ClearRecvBuffer((Uart_ModuleType)Module);
    }
    /* send byte completed */
    else if (((uint8)(hwDesc->UartBasePtr->IER.bits.TXEIE) != 0U) &&
             (Usart_LL_GetIntrFlag(hwDesc->UartBasePtr, USART_INT_GET_TXEIF)))
    {
        if (((Uart_Im_TransferInfo[Module].TransferState & UART_IM_TRANSFER_STATE_BUSY_SEND) != 0U) &&
            (Uart_Im_DmaUserConfigInfo[Module].TxDmaStatus == UART_DMA_DISABLE))
        {
            Uart_Im_TransferInfo[Module].SendIntrInfo.Index++;

            if (Uart_Im_TransferInfo[Module].SendIntrInfo.Index == Uart_Im_TransferInfo[Module].SendIntrInfo.Length)
            {
                Usart_LL_SetIntrEnabled(hwDesc->UartBasePtr, USART_INT_SET_TXEIE, false);
                Uart_Im_TransferInfo[Module].TransferState &= (uint8)(~UART_IM_TRANSFER_STATE_BUSY_SEND);
                Uart_Im_SendCompleteCallBackProcess((Uart_ModuleType)Module);
            }
            else
            {
                Usart_LL_SetTxBufferData(
                  hwDesc->UartBasePtr,
                  Uart_Im_TransferInfo[Module]
                    .SendIntrInfo.DataBuffer[Uart_Im_TransferInfo[Module].SendIntrInfo.Index]);
            }
        }
        else
        {
            /* Do Nothing */
        }
    }
    /* received idle frame */
    else if (((uint8)(hwDesc->UartBasePtr->IER.bits.IDLEIE) != 0U) &&
             (Usart_LL_GetIntrFlag(hwDesc->UartBasePtr, USART_INT_GET_IDLEIF)))
    {
        Usart_LL_SetIntrEnabled(hwDesc->UartBasePtr, USART_INT_SET_IDLEIE, false);
        Usart_LL_ClearIntrFlag(hwDesc->UartBasePtr, USART_INT_CLEAR_IDLEIC);
        if ((Uart_Im_TransferInfo[Module].TransferState & UART_IM_TRANSFER_STATE_BUSY_RECEIVE) != 0U)
        {
            /* disable uart receive */
            Usart_LL_SetReceiveDataEnabled(hwDesc->UartBasePtr, false);
            Uart_Im_TransferInfo[Module].TransferState &= (uint8)(~UART_IM_TRANSFER_STATE_BUSY_RECEIVE);
            if (Uart_Im_DmaUserConfigInfo[Module].RxDmaStatus == UART_DMA_ENABLE)
            {
                Dma_LL_SetChannelEnabled(
                  Uart_Im_DmaUserConfigInfo[Module].RxDmaBasePtr,
                  (Dma_Channel_t)Uart_Im_DmaUserConfigInfo[Module].RxDmaChannel, false);
                Uart_Im_RecCompleteCallBackProcess(
                  (Uart_ModuleType)Module,
                  (uint16)(UART_RX_DATA_MAX_SIZE -
                           Dma_LL_GetRemainingTransNum(Uart_Im_DmaUserConfigInfo[Module].RxDmaBasePtr,
                                                       (Dma_Channel_t)Uart_Im_DmaUserConfigInfo[Module].RxDmaChannel)));
            }
            else
            {
                Usart_LL_SetIntrEnabled(hwDesc->UartBasePtr, USART_INT_SET_RDRIE, false);
                Uart_Im_RecCompleteCallBackProcess(
                  (Uart_ModuleType)Module, Uart_Im_TransferInfo[Module].RecIntrInfo.Index);
            }
        }
        else
        {
            /* do nothing */
        }
#if 0
        /* update memory address and size */
        if (UART_DMA_UPDATE_SET == Uart_Im_DmaUserConfigInfo[Module].UpdateStatus)
        {
            Dma_LL_SetMemAddr(
              Uart_Im_DmaUserConfigInfo[Module].RxDmaBasePtr,
              (Dma_Channel_t)Uart_Im_DmaUserConfigInfo[Module].RxDmaChannel,
              (uint32)Uart_Im_DmaUserConfigInfo[Module].RxMemoryAddr);
            Dma_LL_SetNumberOfData(
              Uart_Im_DmaUserConfigInfo[Module].RxDmaBasePtr,
              (Dma_Channel_t)Uart_Im_DmaUserConfigInfo[Module].RxDmaChannel,
              Uart_Im_DmaUserConfigInfo[Module].RxMemorySize);

            /* restart dma */
            Dma_LL_SetChannelEnabled(
              Uart_Im_DmaUserConfigInfo[Module].RxDmaBasePtr,
              (Dma_Channel_t)Uart_Im_DmaUserConfigInfo[Module].RxDmaChannel, true);
            Usart_LL_SetReceiveDataEnabled(hwDesc->UartBasePtr, true);
        }
        else
        {
            /* user not config ,not start receive */
            Uart_Im_DmaUserConfigInfo[Module].UpdateStatus = UART_DMA_UPDATE_INIT;
            Usart_LL_SetReceiveDataEnabled(hwDesc->UartBasePtr, false);
        }
#endif
    }
    else
    {
        /* Do Nothing */
    }
    if (Usart_LL_GetIntrFlag(hwDesc->UartBasePtr, USART_INT_GET_OVFEIF))
    {
        /* TODO */
        Usart_LL_ClearIntrFlag(hwDesc->UartBasePtr, USART_INT_CLEAR_OVFEIC);
    }
    else
    {
        /* Do Nothing */
    }
}

/**
 * @brief Uart dma receive interrupt handler
 * @param UartModule Uart module
 * @param IntrFlag Dma flag
 */
static void Uart_DmaInterruptRxHandler(Uart_ModuleType UartModule, uint8 IntrFlag)
{
    if ((IntrFlag & (uint8)DMA_LIFR_FTIF_LOGIC_BIT) > 0U)
    {
        Dma_LL_SetChannelEnabled(
          Uart_Im_DmaUserConfigInfo[UartModule].RxDmaBasePtr,
          (Dma_Channel_t)Uart_Im_DmaUserConfigInfo[UartModule].RxDmaChannel, false);
        Dma_LL_SetFinishTransIntrEnabled(
          Uart_Im_DmaUserConfigInfo[UartModule].RxDmaBasePtr,
          (Dma_Channel_t)Uart_Im_DmaUserConfigInfo[UartModule].RxDmaChannel, false);

        /* PRQA S 4109 2 #KQR004109 */
        if ((Uart_Im_DmaUserConfigInfo[UartModule].RxDmaStatus == UART_DMA_ENABLE) &&
            (Uart_Im_TransferInfo[UartModule].TransferState & UART_IM_TRANSFER_STATE_BUSY_RECEIVE))
        {
            /* disable uart receive */
            Usart_LL_SetReceiveDataEnabled(Uart_Im_Info[UartModule].UartBasePtr, false);
            Uart_Im_TransferInfo[UartModule].TransferState &= (uint8)(~UART_IM_TRANSFER_STATE_BUSY_RECEIVE);
            Uart_Im_RecCompleteCallBackProcess(UartModule, Uart_Im_DmaUserConfigInfo[UartModule].RxMemorySize);
        }
        else
        {
            /* Do Nothing */
        }
    }
    else
    {
        /* Do Nothing */
    }

    if ((IntrFlag & (uint8)DMA_LIFR_ETIF_LOGIC_BIT) > 0U)
    {
        // TODO
    }
    else
    {
        /* Do Nothing */
    }
}

/**
 * @brief Uart dma send interrupt handler
 * @param UartModule Uart module
 * @param IntrFlag Dma flag
 */
static void Uart_DmaInterruptTxHandler(Uart_ModuleType UartModule, uint8 IntrFlag)
{
    if ((IntrFlag & (uint8)DMA_LIFR_FTIF_LOGIC_BIT) > 0U)
    {
        Dma_LL_SetChannelEnabled(
          Uart_Im_DmaUserConfigInfo[UartModule].TxDmaBasePtr,
          (Dma_Channel_t)Uart_Im_DmaUserConfigInfo[UartModule].TxDmaChannel, false);
        Dma_LL_SetFinishTransIntrEnabled(
          Uart_Im_DmaUserConfigInfo[UartModule].TxDmaBasePtr,
          (Dma_Channel_t)Uart_Im_DmaUserConfigInfo[UartModule].TxDmaChannel, false);

        /* PRQA S 4109 2 #KQR004109 */
        if ((Uart_Im_DmaUserConfigInfo[UartModule].TxDmaStatus == UART_DMA_ENABLE) &&
            (Uart_Im_TransferInfo[UartModule].TransferState & UART_IM_TRANSFER_STATE_BUSY_SEND))
        {
            /* wait until TX buffer empty before disable sending process */
            volatile uint32 countOut = 0xFFFFU;
            do
            {
                countOut--;
                /*PRQA S 4115 2 #KQR004115 */
            } while (!Usart_LL_GetIntrFlag(Uart_Im_Info[UartModule].UartBasePtr, USART_INT_GET_TXEIF) && (countOut));

            Uart_Im_TransferInfo[UartModule].TransferState &= (uint8)(~UART_IM_TRANSFER_STATE_BUSY_SEND);
            Uart_Im_SendCompleteCallBackProcess(UartModule);
        }
        else
        {
            /* Do Nothing */
        }
    }
    else
    {
        /* Do Nothing */
    }

    if ((IntrFlag & (uint8)DMA_LIFR_ETIF_LOGIC_BIT) > 0U)
    {
        // TODO
    }
    else
    {
        /* Do Nothing */
    }
}
/* EOF */
