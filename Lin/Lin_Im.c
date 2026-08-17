/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Lin_Im.c
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
/* PRQA S 3387 EOF #KQR003387 */
/* PRQA S 1881 EOF #KQR001881 */
/* PRQA S 3408 EOF #KQR003408 */
/* PRQA S 0303 EOF #KQR000303 */
/* PRQA S 0404 EOF #KQR000404 */
/* PRQA S 3345 EOF #KQR003345 */
/* PRQA S 3415 EOF #KQR003415 */
/* PRQA S 1852 EOF #KQR001852 */
/* PRQA S 1853 EOF #KQR001853 */
/* PRQA S 3218 EOF #KQR003218 */
/* PRQA S 4342 EOF #KQR004342 */
/* PRQA S 0306 EOF #KQR000306 */
/* PRQA S 2814 EOF #KQR002814 */
/* PRQA S 2824 EOF #KQR002824 */
/* PRQA S 2844 EOF #KQR002844 */
/* PRQA S 2201 EOF #KQR002201 */
/* PRQA S 4899 EOF #KQR004899 */
/* PRQA S 2934 EOF #KQR002934 */
/* PRQA S 3383 EOF #KQR003383 */
/* PRQA S 3384 EOF #KQR003384 */
/******************************************************************************
 **                        Include Files
 ******************************************************************************/
#include "Lin_Im.h"
#include "dev_assert.h"
#include "kf32a158sf_drv_intr.h"
#include "kf32a158sf_drv_pclk.h"
#include "kf32a158sf_drv_rst.h"
#include "kf32a158sf_drv_usart.h"
#include "kf32a158sf_drv_dma.h"
/******************************************************************************
 **                        File Version Check
 ******************************************************************************/

/******************************************************************************
 **                        Macro  Definitions
 ******************************************************************************/

/**
 * @brief Lin master receive status
 */
#define C_LIN_BUS_IDLE_STATUS          (0x00U)
#define C_MASTER_BREAK_RECEIVED_STATUS (0x01U)
#define C_MASTER_SYN_RECEIVED_STATUS   (0x02U)
#define C_LIN_RECEIVE_MODE_STATUS      (0x03U)
#define C_LIN_CHECKSUM_STATUS          (0x04U)

/**
 * @brief Lin slave receive status
 * @details
 */
#define C_LIN_SLAVE_BUS_IDLE_STATUS      (0x00U)
#define C_LIN_SLAVE_BREAK_RECEIVE_STATUS (0x01U)
#define C_LIN_SLAVE_SYN_RECEIVE_STATUS   (0x02U)
#define C_LIN_SLAVE_RECEIVE_MODE_STATUS  (0x03U)
#define C_LIN_SLAVE_CHECKSUM_STATUS      (0x04U)
/******************************************************************************
 **                        Typedef  Definitions
 ******************************************************************************/
typedef Usart_RegisterMap_t *UsartRegMapPtr;

/**
 * @brief interrupt handle
 */
typedef void (*Lin_DmaIntrFcnType)(uint8 IntrFlag);

/**
 * @brief lin dma user config information
 */
typedef struct
{
    /** @brief lin dma send status  */
    uint8 TxDmaStatus;
    /** @brief lin dma receive status  */
    uint8 RxDmaStatus;
    /** @brief lin receive dma Ptr */
    Dma_RegisterMap_t *RxDmaBasePtr;
    /** @brief lin send dma Ptr */
    Dma_RegisterMap_t *TxDmaBasePtr;
    /** @brief lin receive dma channel index */
    uint8 RxDmaChannel;
    /** @brief lin send dma channel index */
    uint8 TxDmaChannel;
} Lin_DmaUserInfoType;

/**
 * @brief lin hardware informaiton config
 */
typedef struct
{
    /** @brief lin Hw Unit Pointer */
    Usart_RegisterMap_t *UartBasePtr;
} Lin_HardWareInfoType;
/******************************************************************************
 **                        Variable Declarations
 ******************************************************************************/

/******************************************************************************
 **                      Function declarations
 ******************************************************************************/
static void Lin_DmaIntrModule6TxHandle(uint8 IntrFlag);
static void Lin_DmaIntrModule3TxHandle(uint8 IntrFlag);
static void Lin_DmaIntrModule2TxHandle(uint8 IntrFlag);
static void Lin_DmaIntrModule1TxHandle(uint8 IntrFlag);
static void Lin_DmaIntrModule0TxHandle(uint8 IntrFlag);

static void Lin_DmaIntrModule6RxHandle(uint8 IntrFlag);
static void Lin_DmaIntrModule3RxHandle(uint8 IntrFlag);
static void Lin_DmaIntrModule2RxHandle(uint8 IntrFlag);
static void Lin_DmaIntrModule1RxHandle(uint8 IntrFlag);
static void Lin_DmaIntrModule0RxHandle(uint8 IntrFlag);

/**
 * @brief dma interrupt handle function for lin transmit
 */
/* PRQA S 2203 ++ #KQR002203 */
static const Lin_DmaIntrFcnType Lin_DmaIntrTxHandle[LIN_MODULE_NUM] = {
  &Lin_DmaIntrModule0TxHandle, &Lin_DmaIntrModule1TxHandle, &Lin_DmaIntrModule2TxHandle, &Lin_DmaIntrModule3TxHandle,
  &Lin_DmaIntrModule6TxHandle};

/**
 * @brief dma interrupt handle function for lin receive
 */
static const Lin_DmaIntrFcnType Lin_DmaIntrRxHandle[LIN_MODULE_NUM] = {
  &Lin_DmaIntrModule0RxHandle, &Lin_DmaIntrModule1RxHandle, &Lin_DmaIntrModule2RxHandle, &Lin_DmaIntrModule3RxHandle,
  &Lin_DmaIntrModule6RxHandle};
/* PRQA S 2203 -- #KQR002203 */
/******************************************************************************
 **                      Private Function Declarations
 ******************************************************************************/

/**
 * @brief Lin dma Hw Information
 *
 */
static const Lin_HardWareInfoType Lin_Im_Info[LIN_MODULE_NUM] = {
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

/**
 * @brief user used dma,config information
 */
static Lin_DmaUserInfoType Lin_Im_DmaUserConfigInfo[LIN_MODULE_NUM];

/**
 * @brief lin master control status
 */
static uint8 Lin_MasterControlStatus[LIN_IM_MODULES];

#if (LIN_SLAVE_MODE_USED == STD_ON)
/**
 * @brief Slave Receive state machine
 */
static uint8 LIN_SlaveControlStatus[LIN_IM_MODULES];
#endif
/**
 * @brief usart hardware pointer
 */
/* PRQA S 2203 2 #KQR002203 */
static const UsartRegMapPtr Usart_ModulePtr[LIN_MODULE_NUM] = {
  USART0_PTR, USART1_PTR, USART2_PTR, USART3_PTR, USART6_PTR};

/**
 * @brief Store Checksum type
 */
static volatile uint8 Usart_ChecksumType[LIN_IM_MODULES];

/**
 * @brief Store data to send or receive
 */
/* PRQA S 1504 1 #KOR001504 */
volatile uint8 Lin_Usart_Buffer[LIN_IM_MODULES][USART_MAX_BUFFER_LENGTH];

/**
 * @brief Point to the next byte to send or receive in USART Buffers
 */
static volatile uint8 Lin_UsartBufferPtr[LIN_IM_MODULES];

/**
 * @brief Real sizes of USART Buffers
 */
static volatile uint8 Lin_UsartBufferLength[LIN_IM_MODULES];

/**
 * @brief Usart Wakeup flag
 */
static volatile uint8 Lin_Usart_WakeupFlag[LIN_IM_MODULES];

/**
 * @brief lin receive data counter
 */
static uint8 Lin_ReceiveDataCount[LIN_IM_MODULES] = {0};

/**
 * @brief lin receive data
 */
/* PRQA S 0686,0694 1 #KQR100011 */
static uint8 Lin_ReceiveTemp[LIN_IM_MODULES][12U] = {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};
/**
 * @brief lin receive pdu temp
 */
static Lin_PduType Lin_ReceivePdu[LIN_IM_MODULES] = {0};

/******************************************************************************
 **                        Export Variables
 ******************************************************************************/
/* PRQA S 1513 8 #KQR001513 */
extern volatile uint8        Lin_ChannelFrameStatus[LIN_IM_MODULES];
extern volatile uint8        Lin_ChannelFrameErrorStatus[LIN_IM_MODULES];
extern uint8                 Lin_TransmitHeaderCommand[LIN_IM_MODULES];
extern Lin_ChannelCfgType   *Lin_ChannelConfigPtr[LIN_IM_MODULES];
extern volatile uint8        Lin_ChannelStatus[LIN_IM_MODULES];
extern const Lin_ConfigType *Lin_ConfigPtr;
extern uint8                 Lin_WakeupSupport[LIN_IM_MODULES];
/******************************************************************************
 **                      Private Function Declarations
 ******************************************************************************/
KF_INLINE UsartRegMapPtr kfLin_GetModuleFromIndex(Lin_UsartModuleType Index);

static FUNC(void, LIN_CODE) Lin_Im_Reset(CONST(Lin_UsartModuleType, AUTOMATIC) Index);

static FUNC(uint32, LIN_CODE)
  Lin_Im_ChecksumCalc(VAR(uint8, AUTOMATIC) Channel, VAR(Lin_FrameCsModelType, AUTOMATIC) CheckSumModel);
/* PRQA S 3432 2 #KQR003432 */
static FUNC(void, LIN_CODE)
  Lin_Im_CopyData(CONST(uint8, AUTOMATIC) Channel, P2VAR(uint8, AUTOMATIC, LIN_APPL_DATA) LinSduPtr);

static FUNC(void, LIN_CODE) Lin_IM_IdleLineDetectInterruptHandler(uint8 Channel);

static FUNC(void, LIN_CODE) Lin_RxInterruptHandler(uint8 Channel);

static FUNC(void, LIN_CODE) Lin_TxInterruptHandler(uint8 Channel);

/**
 * @brief interrupt process
 * @implements #SWS_Lin_00155
 */
static FUNC(void, LIN_CODE) Lin_UsartInterruptHandler(uint8 ModuleId);
#if (LIN_SLAVE_MODE_USED == STD_ON)
/**
 * @brief Slave Interrupt processing
 *
 * @param ModuleId USART index
 */
static FUNC(void, LIN_CODE) Lin_Slave_UsartInterruptHandler(uint8 ModuleId);
#endif
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
/* PRQA S 1336 1 #KQR001336 */
extern void Dma_RegisterCustomHandler(uint8 DmaIndex, Dma_Channel_t DmaChannel, void (*IrqHandle)(uint8));

/**
 * @brief usart interrupt handle register
 *
 * @param UsartIndex usart index
 * @param IrqHandle interrupt handle function
 */
extern void Usart_RegisterCustomHandler(uint8 UsartIndex, void (*IrqHandle)(uint8 UsartIndex));
/******************************************************************************
 **                      Function definitions
 ******************************************************************************/
/**
 * @brief Deinitialize, clear variables
 *
 * @param ChCfgPtr channel config pointer
 * @return void
 * @retval void
 */
FUNC(void, LIN_CODE) Lin_Im_DeinitDataClear(Lin_ChannelCfgType const *ChCfgPtr)
{
    Lin_UsartModuleType hwModuleId;

    hwModuleId = ChCfgPtr->HwModule;

    Lin_UsartBufferPtr[hwModuleId]    = 0U;
    Lin_UsartBufferLength[hwModuleId] = 0U;
}

/**
 * @brief Lin dma send interrupt handler
 * @param ModuleId Uart module
 * @param IntrFlag Dma flag
 */
static void Lin_DmaInterruptTxHandler(Lin_UsartModuleType ModuleId, uint8 IntrFlag)
{
    uint8 i;
    uint8 Channel = 0U;

    if ((IntrFlag & (uint8)DMA_LIFR_FTIF_LOGIC_BIT) > 0U)
    {
#if 0 
        /* wait until TX buffer empty before disable sending process */
        volatile uint32 countOut = 0xFFFU;
        do
        {
            countOut--;
            /*PRQA S 4115,4558 2 #KQR100001 */
        } while (!Usart_LL_GetIntrFlag(Lin_Im_Info[ModuleId].UartBasePtr, USART_INT_GET_TXEIF) && (countOut));
#endif

        Dma_LL_SetChannelEnabled(
          Lin_Im_DmaUserConfigInfo[ModuleId].TxDmaBasePtr,
          (Dma_Channel_t)Lin_Im_DmaUserConfigInfo[ModuleId].TxDmaChannel, false);
        Dma_LL_SetFinishTransIntrEnabled(
          Lin_Im_DmaUserConfigInfo[ModuleId].TxDmaBasePtr,
          (Dma_Channel_t)Lin_Im_DmaUserConfigInfo[ModuleId].TxDmaChannel, false);
        /* disable uart send dma */
        // Usart_LL_SetTransDmaEnabled(Usart_ModulePtr[ModuleId], false);
        /* PRQA S 2877 1 #KQR002877 */
        for (i = 0U; i < LIN_IM_MODULES; ++i)
        {
            /* PRQA S 1440 1 #KQR001440 */
            if (Lin_ChannelConfigPtr[i]->HwModule == ModuleId)
            {
                Channel = i;
                break;
            }
            else
            {
                /* do nothing */
            }
        }

#if (LIN_SLAVE_MODE_USED == STD_ON)
        if (Lin_ChannelConfigPtr[Channel]->ChannelMode == LIN_CHANNEL_SLAVE_MODE)
        {
            if (Lin_ConfigPtr->TxConfirmationCallback != NULL_PTR)
            {
                Lin_ConfigPtr->TxConfirmationCallback(Channel);
            }
            else
            {
                /* do nothing */
            }
            LIN_SlaveControlStatus[Channel] = C_LIN_SLAVE_BUS_IDLE_STATUS;
        }
        else
#endif
        {
            if (Lin_TransmitHeaderCommand[Channel] == LIN_TX_SLEEP_COMMAND)
            {
                /* Enable wake up detection */
                if ((uint8)STD_ON == Lin_WakeupSupport[Channel])
                {
                    /*Start Detection interrupt*/
                }
                else
                {
                    /* do nothing */
                }
            }

            Lin_UsartBufferPtr[Channel] = (Lin_UsartBufferLength[Channel] - 1U);

            Lin_TransmitHeaderCommand[Channel] = LIN_TX_NO_COMMAND;

            Lin_ChannelFrameStatus[Channel] = LIN_TX_COMPLETE_STATE;
        }
    }
    else
    {
        /* Do Nothing */
    }
}

/**
 * @brief uart4 send dma interrupt handle
 */
static void Lin_DmaIntrModule6TxHandle(uint8 IntrFlag)
{
    Lin_DmaInterruptTxHandler(LIN_MODULE_USART6, IntrFlag);
}

/**
 * @brief uart3 send dma interrupt handle
 */
static void Lin_DmaIntrModule3TxHandle(uint8 IntrFlag)
{
    Lin_DmaInterruptTxHandler(LIN_MODULE_USART3, IntrFlag);
}

/**
 * @brief uart2 send dma interrupt handle
 */
static void Lin_DmaIntrModule2TxHandle(uint8 IntrFlag)
{
    Lin_DmaInterruptTxHandler(LIN_MODULE_USART2, IntrFlag);
}

/**
 * @brief uart1 send dma interrupt handle
 */
static void Lin_DmaIntrModule1TxHandle(uint8 IntrFlag)
{
    Lin_DmaInterruptTxHandler(LIN_MODULE_USART1, IntrFlag);
}

/**
 * @brief uart0 send dma interrupt handle
 */
static void Lin_DmaIntrModule0TxHandle(uint8 IntrFlag)
{
    Lin_DmaInterruptTxHandler(LIN_MODULE_USART0, IntrFlag);
}

/**
 * @brief Lin dma receive interrupt handler
 * @param ModuleId Uart module
 * @param IntrFlag Dma flag
 */
static void Lin_DmaInterruptRxHandler(Lin_UsartModuleType ModuleId, uint8 IntrFlag)
{
    uint8 i;
    uint8 Channel = 0U;

    if ((IntrFlag & (uint8)DMA_LIFR_FTIF_LOGIC_BIT) > 0U)
    {
        Dma_LL_SetChannelEnabled(
          Lin_Im_DmaUserConfigInfo[ModuleId].RxDmaBasePtr,
          (Dma_Channel_t)Lin_Im_DmaUserConfigInfo[ModuleId].RxDmaChannel, false);
        Dma_LL_SetFinishTransIntrEnabled(
          Lin_Im_DmaUserConfigInfo[ModuleId].RxDmaBasePtr,
          (Dma_Channel_t)Lin_Im_DmaUserConfigInfo[ModuleId].RxDmaChannel, false);

        /* disable uart dma */
        Usart_LL_SetRecvDmaEnabled(Usart_ModulePtr[ModuleId], false);
        /* PRQA S 2877 1 #KQR002877 */
        for (i = 0U; i < LIN_IM_MODULES; ++i)
        {
            /* PRQA S 1440 1 #KQR001440 */
            if (Lin_ChannelConfigPtr[i]->HwModule == ModuleId)
            {
                Channel = i;
                break;
            }
            else
            {
                /* do nothing */
            }
        }

#if (LIN_SLAVE_MODE_USED == STD_ON)
        if (Lin_ChannelConfigPtr[Channel]->ChannelMode == LIN_CHANNEL_SLAVE_MODE)
        {
            if (Lin_ReceivePdu[Channel].Drc == LIN_MASTER_RESPONSE)
            {
                if (Lin_ConfigPtr->RxIndicationCallback != NULL_PTR)
                {
                    Lin_ConfigPtr->RxIndicationCallback(Channel, Lin_ReceivePdu[Channel].SduPtr);
                }
                else
                {
                    /* do nothing */
                }
            }
            else
            {
                /* Do Nothing */
            }

            LIN_SlaveControlStatus[Channel] = C_LIN_SLAVE_BUS_IDLE_STATUS;
        }
        else
#endif
        {
            Lin_UsartBufferPtr[Channel] += (Lin_UsartBufferLength[Channel] - 3U + 1U);
            Lin_ReceiveDataCount[Channel]    = 0U;
            Lin_MasterControlStatus[Channel] = C_LIN_BUS_IDLE_STATUS;
            Lin_IM_IdleLineDetectInterruptHandler(Channel);
            /* changed receive status */
            Lin_ChannelFrameStatus[Channel] = LIN_RX_COMPLETE_STATE;
        }
    }
    else
    {
        /* Do Nothing */
    }
}

/**
 * @brief uart4 receive dma interrupt handle
 */
static void Lin_DmaIntrModule6RxHandle(uint8 IntrFlag)
{
    Lin_DmaInterruptRxHandler(LIN_MODULE_USART6, IntrFlag);
}

/**
 * @brief uart3 receive dma interrupt handle
 */
static void Lin_DmaIntrModule3RxHandle(uint8 IntrFlag)
{
    Lin_DmaInterruptRxHandler(LIN_MODULE_USART3, IntrFlag);
}

/**
 * @brief uart2 receive dma interrupt handle
 */
static void Lin_DmaIntrModule2RxHandle(uint8 IntrFlag)
{
    Lin_DmaInterruptRxHandler(LIN_MODULE_USART2, IntrFlag);
}

/**
 * @brief uart1 receive dma interrupt handle
 */
static void Lin_DmaIntrModule1RxHandle(uint8 IntrFlag)
{
    Lin_DmaInterruptRxHandler(LIN_MODULE_USART1, IntrFlag);
}

/**
 * @brief uart0 receive dma interrupt handle
 */
static void Lin_DmaIntrModule0RxHandle(uint8 IntrFlag)
{
    Lin_DmaInterruptRxHandler(LIN_MODULE_USART0, IntrFlag);
}

/**
 * @brief get Usart module
 * @param index usart index
 * @return UsartRegMapPtr
 * @retval usart hardware pointer
 */
KF_INLINE UsartRegMapPtr kfLin_GetModuleFromIndex(Lin_UsartModuleType Index)
{
    KF_DEV_ASSERT(Index < LIN_MODULE_NUM);
    return Usart_ModulePtr[Index];
}

/**
 * @brief Usart reset
 * @param index usart index
 * @param None
 * @retval None
 */
static FUNC(void, LIN_CODE) Lin_Im_Reset(CONST(Lin_UsartModuleType, AUTOMATIC) Index)
{
    switch (Index)
    {
    case LIN_MODULE_USART0: {
        Rst_LL_SetUsartEnabled(RST_USART0, false);
        Rst_LL_SetUsartEnabled(RST_USART0, true);
        Pclk_LL_SetUsartEnabled(PCLK_USART0, true);
        break;
    }
    case LIN_MODULE_USART1: {
        Rst_LL_SetUsartEnabled(RST_USART1, false);
        Rst_LL_SetUsartEnabled(RST_USART1, true);
        Pclk_LL_SetUsartEnabled(PCLK_USART1, true);
        break;
    }
    case LIN_MODULE_USART2: {
        Rst_LL_SetUsartEnabled(RST_USART2, false);
        Rst_LL_SetUsartEnabled(RST_USART2, true);
        Pclk_LL_SetUsartEnabled(PCLK_USART2, true);
        break;
    }
    case LIN_MODULE_USART3: {
        Rst_LL_SetUsartEnabled(RST_USART3, false);
        Rst_LL_SetUsartEnabled(RST_USART3, true);
        Pclk_LL_SetUsartEnabled(PCLK_USART3, true);
        break;
    }
    case LIN_MODULE_USART6: {
        Rst_LL_SetUsartEnabled(RST_USART6, false);
        Rst_LL_SetUsartEnabled(RST_USART6, true);
        Pclk_LL_SetUsartEnabled(PCLK_USART6, true);
        break;
    }
    default: {
        KF_DEV_ASSERT(false);
        break;
    }
    }
}

/**
 * @brief Use LIN2.0 standard check, calculate the test value of LIN data
 * @param PctId Data of protection segment id
 * @param DataBuf Pointer of the data to be sent
 * @param Length The length of the data to be sent
 * @return uint8
 * @retval calculate data, the LIN2.0 standard check segment
 */

static FUNC(uint8, LIN_CODE) GetCheckSumValue(uint8 PctId, const volatile uint8 *DataBuf, uint8 Length)
{
    uint16 check_sum = PctId;
    uint8  i;
    for (i = 0U; i < Length; i++)
    {
        check_sum += DataBuf[i];
        if (check_sum > 0xFFU)
        {
            /* PRQA S 4434,1860 1 #KQR100005 */
            check_sum -= 255;
        }
        else
        {
            /* do nothing */
        }
    }
    /* PRQA S 4434,1860 1 #KQR100005 */
    return (255 - check_sum);
}

/**
 * @brief Calculate LIN Checksum.
 * @param Channel Channel to be addressed.
 * @param CheckSumModel
 * @return uint32
 * @retval checksum value
 */
static FUNC(uint32, LIN_CODE)
  Lin_Im_ChecksumCalc(VAR(uint8, AUTOMATIC) Channel, VAR(Lin_FrameCsModelType, AUTOMATIC) CheckSumModel)
{
    uint32 checkSum = (uint32)0U;
    uint32 carry;
    uint32 dataLen;
    uint32 index;

    dataLen = ((uint32)Lin_UsartBufferLength[Channel]) - ((uint32)3U);
    /* Enhanced Model */
    if (LIN_ENHANCED_CS == CheckSumModel)
    {
        checkSum = (uint32)Lin_Usart_Buffer[Channel][USART_PID_BYTE_OFFSET];
    }
    else
    {
        /* do nothing */
    }

    for (index = (uint32)0U; index < dataLen; index++)
    {
        checkSum += (uint32)Lin_Usart_Buffer[Channel][USART_DATA_OFFSET + index];
        carry    = checkSum >> (uint32)8U;
        checkSum = (checkSum & ((uint32)0xFFU)) + carry;
    }

    checkSum = (~(checkSum)) & ((uint32)0xFFU);
    return checkSum;
}

/**
 * @brief:Usart Send data
 * @param[in] Usartx usart Module pointer
 * @param[in] Data waiting to be sent
 * @param[in] Timeout
 * @retval kf_status_t
 */
/* PRQA S 1505 1 #KQR001505 */
kf_status_t Usart_Im_SendData(Usart_RegisterMap_t *const Usartx, const uint8 Data, const uint32 Timeout)
{
    volatile uint32 waitFlag = 0x0U, waitFlag1 = 0x0U;
    kf_status_t     Ret = STATUS_OK;

    if ((NULL_PTR == Usartx) || (0U == Timeout))
    {
        Ret = STATUS_ERROR;
    }
    else
    {
#if 1
        /* PRQA S 2109 1 #KQR002109 */
        while ((Usart_LL_GetIntrFlag(Usartx, USART_INT_GET_TFEIF1) == 0) && (waitFlag != Timeout))
        {
            waitFlag++;
        }
        if ((waitFlag == Timeout) || (waitFlag1 == Timeout))
        {
            Ret = STATUS_TIMEOUT;
        }
        else
        {
            Usart_LL_SetTxBufferData(Usartx, Data);
        }

#else
        Usart_LL_SetTxBufferData(Usartx, Data);

        while (Usart_LL_GetIntrFlag(Usartx, USART_INT_GET_TFEIF1) && (waitFlag != Timeout))
        {
            waitFlag++;
        }
        while ((false == Usart_LL_GetIntrFlag(Usartx, USART_INT_GET_TXEIF)) && (waitFlag1 != Timeout))
        {
            waitFlag1++;
        }
        if ((waitFlag == Timeout) || (waitFlag1 == Timeout))
        {
            return STATUS_TIMEOUT;
        }
#endif
    }
    return Ret;
}

/**
 * @brief: Usart Send data
 * @retval uint32 Residual length
 */
/* PRQA S 1505 1 #KQR001505 */
uint32
Usart_Im_TransData(Usart_RegisterMap_t *const Usartx, uint8 const *const Buff, const uint32 Len, const uint32 Timeout)
{
    volatile uint32 tmpLen   = 0U;
    volatile uint32 waitFlag = 0x0U, waitFlag1 = 0x0U;

    if ((NULL_PTR == Usartx) || (NULL_PTR == Buff) || (0U == Len))
    {
        /*Empty*/
    }
    else
    {
        while ((tmpLen < Len) && (STATUS_OK == Usart_Im_SendData(Usartx, Buff[tmpLen], Timeout)))
        {
            tmpLen++;
        }
        if (tmpLen < Len)
        {
            /* PRQA S 2109 1 #KQR002109 */
            while ((Usart_LL_GetIntrFlag(Usartx, USART_INT_GET_TFEIF1) == 0) && (waitFlag != Timeout))
            {
                waitFlag++;
            }
            if ((waitFlag == Timeout) || (waitFlag1 == Timeout))
            {
            }
            else
            {
                Usart_LL_SetTxBufferData(Usartx, Buff[tmpLen]);
            }

            tmpLen++;
        }
        else
        {
            /* do nothing */
        }
    }

    return (Len - tmpLen);
}

/**
 * @brief: LIN slave respond data
 * @param[in] Usartx usart Module pointer
 * @param[in] FrameStruct
 * @retval
 */
/* PRQA S 1505 1 #KQR001505 */
uint32 Lin_Im_SlaveSendRespond(Lin_UsartModuleType hwModuleId, Lin_PduType const *FrameStruct, uint32 Timeout)
{
    uint32 remainLen;

    if ((NULL_PTR == FrameStruct) || (NULL_PTR == FrameStruct->SduPtr) || (0U == FrameStruct->Dl))
    {
        remainLen = 0xFFFFFFFFU;
    }
    else
    {
        uint8 CheckSum;
        if (LIN_CLASSIC_CS == FrameStruct->Cs)
        {
            CheckSum = GetCheckSumValue(0U, FrameStruct->SduPtr, FrameStruct->Dl);
        }
        else
        {
            CheckSum = GetCheckSumValue(FrameStruct->Pid, FrameStruct->SduPtr, FrameStruct->Dl);
        }

        (void)Usart_Im_TransData(kfLin_GetModuleFromIndex(hwModuleId), FrameStruct->SduPtr, FrameStruct->Dl, Timeout);
        remainLen = Usart_Im_TransData(kfLin_GetModuleFromIndex(hwModuleId), &CheckSum, 1U, Timeout);
    }

    return remainLen;
}

/**
 * @brief Copy the data received from the usart data registers to LinSduPtr.
 * @details This function shall copy the received data in the provided buffer addressed by the LinSduPtr pointer
 * parameter.
 * @param Channel Channel to be addressed.
 * @param LinSduPtr pointer to pointer to a shadow buffer or memory mapped usart Hardware receive buffer where the
 * current SDU is stored
 * @return void
 * @retval void
 */
/* PRQA S 3432 2 #KQR003432 */
static FUNC(void, LIN_CODE)
  Lin_Im_CopyData(CONST(uint8, AUTOMATIC) Channel, P2VAR(uint8, AUTOMATIC, LIN_APPL_DATA) LinSduPtr)
{
    uint8 index;
    uint8 bufferLength;

    bufferLength = (uint8)(Lin_UsartBufferLength[Channel] - (uint8)3U);
    if (LIN_DMA_ENABLE == Lin_Im_DmaUserConfigInfo[Lin_ChannelConfigPtr[Channel]->HwModule].RxDmaStatus)
    {
        for (index = (uint8)0U; index < bufferLength; index++)
        {
            /* DMA will receive the frame header and PID, and start copying data from the data area. */
            LinSduPtr[index] = Lin_ReceiveTemp[Channel][index + 2U];
        }
    }
    else
    {
        for (index = (uint8)0U; index < bufferLength; index++)
        {
            /* Lin_LPUART_c_REF_4 pointer arithmetic other than array indexing used */
            LinSduPtr[index] = Lin_ReceiveTemp[Channel][index];
        }
    }
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
Lin_Im_GetDmaTrigSource(Lin_UsartModuleType Module, Lin_DmaSourceType DmaSource, uint8_t Direction)
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
    if (Module == LIN_MODULE_USART6)
    {
        /* USART6 uses a dedicated two-dimensional lookup table to obtain the trigger source based on the DMA source
         * type and transfer direction. */
        triggerSourceX = Uart6dmaTriggerSourceTable[DmaSource][Direction];
    }
    else if (Module <= LIN_MODULE_USART3)
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
 * @brief lin receive dam initialization
 *
 * @param Module Uart module
 */
static void Lin_Im_ReceiveDmaInit(Lin_UsartModuleType Module)
{
    Dma_Channel_t      dmaChannel = (Dma_Channel_t)Lin_Im_DmaUserConfigInfo[Module].RxDmaChannel;
    Dma_RegisterMap_t *dmaPtr     = Lin_Im_DmaUserConfigInfo[Module].RxDmaBasePtr;
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
    Dma_LL_SetPeriphAddr(dmaPtr, dmaChannel, (uint32)(&Lin_Im_Info[Module].UartBasePtr->BUFR));
    /* Set trigger source */
    /* PRQA S 4322 1 #KQR004322 */
    Dma_TriggerSource_t triggerSource = Lin_Im_GetDmaTrigSource(Module, (Lin_DmaSourceType)dmaChannel, 1U);
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
    Dma_RegisterCustomHandler(dmaIndex, dmaChannel, Lin_DmaIntrRxHandle[Module]);
}

/**
 * @brief lin send dam initialization
 *
 * @param Module Uart module
 */
static void Lin_Im_SendDmaInit(Lin_UsartModuleType Module)
{
    Dma_Channel_t      dmaChannel = (Dma_Channel_t)Lin_Im_DmaUserConfigInfo[Module].TxDmaChannel;
    Dma_RegisterMap_t *dmaPtr     = Lin_Im_DmaUserConfigInfo[Module].TxDmaBasePtr;
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
    Dma_LL_SetPeriphAddr(dmaPtr, dmaChannel, (uint32)(&Lin_Im_Info[Module].UartBasePtr->BUFR));
    /* Set trigger source */
    /* PRQA S 4322 1 #KQR004322 */
    Dma_TriggerSource_t triggerSource = Lin_Im_GetDmaTrigSource(Module, (Lin_DmaSourceType)dmaChannel, 0U);
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
    /* enable dma oneshot */
    Dma_LL_SetOneShotEnabled(dmaPtr, dmaChannel, true);
    /* register interrupt handler */
    Dma_RegisterCustomHandler(dmaIndex, dmaChannel, Lin_DmaIntrTxHandle[Module]);
}

/**
 * @brief lin receive dma config
 *
 * @param Module Uart module
 * @param ChCfgPtr Uart config information
 */
static void Lin_Im_ReceiveDmaConfig(Lin_UsartModuleType Module, const Lin_ChannelCfgType *ChCfgPtr)
{
    /* set status */
    Lin_Im_DmaUserConfigInfo[Module].RxDmaStatus = LIN_DMA_ENABLE;

    /* dma config information */
    if (ChCfgPtr->DmaConfigPtr->RxDmaSource < LIN_DMA1_CHANNEL_1)
    {
        Lin_Im_DmaUserConfigInfo[Module].RxDmaBasePtr = DMA0_PTR;
        Lin_Im_DmaUserConfigInfo[Module].RxDmaChannel = (uint8)ChCfgPtr->DmaConfigPtr->RxDmaSource;
    }
    else
    {
        Lin_Im_DmaUserConfigInfo[Module].RxDmaBasePtr = DMA1_PTR;
        Lin_Im_DmaUserConfigInfo[Module].RxDmaChannel =
          (uint8)((uint8)ChCfgPtr->DmaConfigPtr->RxDmaSource - (uint8)LIN_DMA1_CHANNEL_1);
    }

    /* dma interrupt receive */
    Lin_Im_ReceiveDmaInit(Module);
    /* disable uart receive dma */
    Usart_LL_SetRecvDmaEnabled(Usart_ModulePtr[Module], false);
}

/**
 * @brief lin send dma config
 *
 * @param Module Uart module
 * @param ChCfgPtr Uart config information
 */
static void Lin_Im_SendDmaConfig(Lin_UsartModuleType Module, const Lin_ChannelCfgType *ChCfgPtr)
{
    UsartRegMapPtr usartx = kfLin_GetModuleFromIndex(Module);

    /* set status */
    Lin_Im_DmaUserConfigInfo[Module].TxDmaStatus = LIN_DMA_ENABLE;

    /* dma config information */
    if (ChCfgPtr->DmaConfigPtr->TxDmaSource < LIN_DMA1_CHANNEL_1)
    {
        Lin_Im_DmaUserConfigInfo[Module].TxDmaBasePtr = DMA0_PTR;
        Lin_Im_DmaUserConfigInfo[Module].TxDmaChannel = (uint8)ChCfgPtr->DmaConfigPtr->TxDmaSource;
    }
    else
    {
        Lin_Im_DmaUserConfigInfo[Module].TxDmaBasePtr = DMA1_PTR;
        Lin_Im_DmaUserConfigInfo[Module].TxDmaChannel =
          (uint8)((uint8)ChCfgPtr->DmaConfigPtr->TxDmaSource - (uint8)LIN_DMA1_CHANNEL_1);
    }

    /* dma interrupt config */
    Lin_Im_SendDmaInit(Module);
    /* disable uart send dma */
    Usart_LL_SetTransDmaEnabled(usartx, false);
}

/**
 * @brief lin dma config initialize
 *
 * @param Module Usart module
 * @param ChCfgPtr module config information
 */
static void Lin_Im_DmaConfig(Lin_UsartModuleType Module, const Lin_ChannelCfgType *ChCfgPtr)
{
    if (ChCfgPtr->DmaConfigPtr != NULL_PTR)
    {
        if (LIN_DMA_ENABLE == ChCfgPtr->DmaConfigPtr->SendDmaSwitch)
        {
            Lin_Im_SendDmaConfig(Module, ChCfgPtr);
        }
        else
        {
            Lin_Im_DmaUserConfigInfo[Module].TxDmaStatus = LIN_DMA_DISABLE;
        }

        if (LIN_DMA_ENABLE == ChCfgPtr->DmaConfigPtr->ReceiveDmaSwitch)
        {
            Lin_Im_ReceiveDmaConfig(Module, ChCfgPtr);
        }
        else
        {
            Lin_Im_DmaUserConfigInfo[Module].RxDmaStatus = LIN_DMA_DISABLE;
        }
    }
    else
    {
        Lin_Im_DmaUserConfigInfo[Module].TxDmaStatus = LIN_DMA_DISABLE;
        Lin_Im_DmaUserConfigInfo[Module].RxDmaStatus = LIN_DMA_DISABLE;
    }
}

/**
 * @brief Initialize a LIN channel.
 * @details This function initializes all hardware registers needed to start the LIN functionality on the selected
 * channel.
 * @param ChCfgPtr channel config pointer
 * @return void
 * @retval void
 */
FUNC(void, LIN_CODE) Lin_Im_UsartInitChannel(Lin_ChannelCfgType const *ChCfgPtr)
{
    Lin_UsartModuleType hwModuleId;
    uint8               baudClk;
    UsartRegMapPtr      usartx;
    uint16              baudInteger;
    uint8               baudNum;
    uint8               baudDenom;

    hwModuleId = ChCfgPtr->HwModule;

    baudClk = (uint8)ChCfgPtr->ClockSelect;

    usartx = kfLin_GetModuleFromIndex(hwModuleId);

    baudInteger = ChCfgPtr->BaudInteger;

    baudNum = ChCfgPtr->BaudNumerator;

    baudDenom = ChCfgPtr->BaudDenom;

    Lin_Im_Reset(hwModuleId);

    /* Clear Wakeup Flag */
    Lin_Usart_WakeupFlag[hwModuleId] = (uint8)FALSE;

    /* usart transmit data enable */
    Usart_LL_EnableTransmitData(usartx);
    /* usart receive data enable */
    Usart_LL_EnableReceiveData(usartx);

    Usart_LL_SelectBlankLength(usartx, true);

    /* usart baudrate clock source select bit */
    /* PRQA S 4342 1 #KQR004342 */
    Usart_LL_SelectBaudRateGeneratorClk(usartx, (Usart_BaudrateClk_t)baudClk);

    /* set baudrate */
    Usart_LL_SetBaudRateInteger(usartx, baudInteger);

    Usart_LL_SetBaudRateMolecular(usartx, baudNum);

    Usart_LL_SetBaudRateDenominator(usartx, baudDenom);

    if (ChCfgPtr->ChannelMode == LIN_CHANNEL_SLAVE_MODE)
    {
        /* RDRIF enable bit */
        Usart_LL_SetIntrEnabled(usartx, USART_INT_SET_RDRIE, true);
        /* spacer enable bit */
        Usart_LL_SetIntrEnabled(usartx, USART_INT_SET_BRIE, true);
#if (LIN_SLAVE_MODE_USED == STD_ON)
        /* register interrupt handle */
        Usart_RegisterCustomHandler((uint8)hwModuleId, &Lin_Slave_UsartInterruptHandler);
#endif
    }
    else
    {
        Usart_LL_SetIntrEnabled(usartx, USART_INT_SET_RDRIE, false);
        Usart_LL_SetIntrEnabled(usartx, USART_INT_SET_BRIE, false);
        /* register interrupt handle */
        Usart_RegisterCustomHandler((uint8)hwModuleId, &Lin_UsartInterruptHandler);
    }

    /* dma config */
    Lin_Im_DmaConfig(hwModuleId, ChCfgPtr);

    /* Usart enable */
    Usart_LL_Enable(usartx);
}

/**
 * @brief Deinitialize a LIN channel.
 * @details This function deinitialize all hardware registers of the lin channel.
 * @param ChCfgPtr channel config pointer
 * @return void
 * @retval void
 */
FUNC(void, LIN_CODE) Lin_Im_UsartDeInitChannel(Lin_ChannelCfgType const *ChCfgPtr)
{
    Lin_UsartModuleType hwModuleId;

    hwModuleId = ChCfgPtr->HwModule;

    Lin_Im_Reset(hwModuleId);
}
/**
 * @brief Check if a LIN channel has been waked-up.
 * @param Channel LIN channel to be waked-up.
 * @return Std_ReturnType.
 * @retval TRUE If the LIN Channel has the wake up flag set.
 * @retval FALSE Otherwise.
 */
FUNC(Std_ReturnType, LIN_CODE) Lin_Im_UsartCheckWakeup(uint8 Channel)
{
    Std_ReturnType tempReturn = Lin_Usart_WakeupFlag[Channel];

    if ((uint8)TRUE == tempReturn)
    {
        /* Reset Wakeup Flag */
        Lin_Usart_WakeupFlag[Channel] = (uint8)FALSE;
    }
    else
    {
        /* Do nothing */
    }
    return tempReturn;
}

/**
 * @brief lin stop dma send process
 * @param
 * @param
 */
static void Lin_Im_DmaSendStop(Lin_UsartModuleType Module, uint8 Channel)
{
    (void)Channel;
    /* disable uart send dma */
    Usart_LL_SetTransDmaEnabled(Usart_ModulePtr[Module], false);

    Dma_LL_SetFinishTransIntrEnabled(
      Lin_Im_DmaUserConfigInfo[Module].TxDmaBasePtr, (Dma_Channel_t)Lin_Im_DmaUserConfigInfo[Module].TxDmaChannel,
      false);
    Dma_LL_ClearIntrFlag(Lin_Im_DmaUserConfigInfo[Module].TxDmaBasePtr,
                         (Dma_Channel_t)Lin_Im_DmaUserConfigInfo[Module].TxDmaChannel, DMA_LIFR_FTIF_LOGIC_BIT);

    /* disable dma channel */
    Dma_LL_SetChannelEnabled(
      Lin_Im_DmaUserConfigInfo[Module].TxDmaBasePtr, (Dma_Channel_t)Lin_Im_DmaUserConfigInfo[Module].TxDmaChannel,
      false);
}

/**
 * @brief lin stop dma receive process
 * @param
 * @param
 */
static void Lin_Im_DmaReceiveStop(Lin_UsartModuleType Module, uint8 Channel)
{
    (void)Channel;

    Usart_LL_SetRecvDmaEnabled(Usart_ModulePtr[Module], false);

    Dma_LL_SetFinishTransIntrEnabled(
      Lin_Im_DmaUserConfigInfo[Module].RxDmaBasePtr, (Dma_Channel_t)Lin_Im_DmaUserConfigInfo[Module].RxDmaChannel,
      false);
    Dma_LL_ClearIntrFlag(Lin_Im_DmaUserConfigInfo[Module].RxDmaBasePtr,
                         (Dma_Channel_t)Lin_Im_DmaUserConfigInfo[Module].RxDmaChannel, DMA_LIFR_FTIF_LOGIC_BIT);

    /* disable dma channel */
    Dma_LL_SetChannelEnabled(
      Lin_Im_DmaUserConfigInfo[Module].RxDmaBasePtr, (Dma_Channel_t)Lin_Im_DmaUserConfigInfo[Module].RxDmaChannel,
      false);
}

/**
 * @brief lin dma receive process
 * @param
 * @param
 */
static void Lin_Im_DmaReceiveStart(Lin_UsartModuleType Module, uint8 Channel)
{
    Usart_LL_SetRecvDmaEnabled(Usart_ModulePtr[Module], false);

    Dma_LL_SetFinishTransIntrEnabled(
      Lin_Im_DmaUserConfigInfo[Module].RxDmaBasePtr, (Dma_Channel_t)Lin_Im_DmaUserConfigInfo[Module].RxDmaChannel,
      false);
    Dma_LL_ClearIntrFlag(Lin_Im_DmaUserConfigInfo[Module].RxDmaBasePtr,
                         (Dma_Channel_t)Lin_Im_DmaUserConfigInfo[Module].RxDmaChannel, DMA_LIFR_FTIF_LOGIC_BIT);

    /* disable dma channel */
    Dma_LL_SetChannelEnabled(
      Lin_Im_DmaUserConfigInfo[Module].RxDmaBasePtr, (Dma_Channel_t)Lin_Im_DmaUserConfigInfo[Module].RxDmaChannel,
      false);

    Dma_LL_SetMemAddr(
      Lin_Im_DmaUserConfigInfo[Module].RxDmaBasePtr, (Dma_Channel_t)Lin_Im_DmaUserConfigInfo[Module].RxDmaChannel,
      (uint32)&Lin_ReceivePdu[Channel].SduPtr[0U]);
    Dma_LL_SetNumberOfData(
      Lin_Im_DmaUserConfigInfo[Module].RxDmaBasePtr, (Dma_Channel_t)Lin_Im_DmaUserConfigInfo[Module].RxDmaChannel,
      Lin_UsartBufferLength[Channel]);

    Dma_LL_SetFinishTransIntrEnabled(
      Lin_Im_DmaUserConfigInfo[Module].RxDmaBasePtr, (Dma_Channel_t)Lin_Im_DmaUserConfigInfo[Module].RxDmaChannel,
      true);

    /* enable dma channel */
    Dma_LL_SetChannelEnabled(
      Lin_Im_DmaUserConfigInfo[Module].RxDmaBasePtr, (Dma_Channel_t)Lin_Im_DmaUserConfigInfo[Module].RxDmaChannel,
      true);

    /* enable uart dma */
    Usart_LL_SetRecvDmaEnabled(Usart_ModulePtr[Module], true);
}

/**
 * @brief Sends the header part of the LIN frame.
 * @param Channel LIN channel to be addressed.
 * @param PduInfoPtr pointer to PDU containing the PID, Checksum model,Response type, Dl and SDU data pointer.
 * @return Std_ReturnType.
 * @retval E_NOT_OK In case of a time out situation only.
 * @retval E_OK Otherwise.
 */
FUNC(Std_ReturnType, LIN_CODE) Lin_Im_UsartSendHeader(uint8 Channel, const Lin_PduType *PduInfoPtr)
{
    Lin_UsartModuleType  hwModuleId;
    volatile uint32      counter = 0U;
    Usart_RegisterMap_t *usartx;
    Std_ReturnType       tmpReturn = (uint8)E_NOT_OK;
    uint16               timeOut   = 0xFFFU;

    hwModuleId = Lin_ChannelConfigPtr[Channel]->HwModule;
    usartx     = kfLin_GetModuleFromIndex(hwModuleId);

    /* Wait for the sender to be empty */
    while (counter <= (LIN_TIMEOUT_LOOPS + (uint32)1U))
    {
        /* PRQA S 2109 2 #KQR002109 */
        if ((1U == Usart_LL_GetIntrFlag(usartx, USART_INT_GET_TXEIF)) &&
            (1U == Usart_LL_GetIntrFlag(usartx, USART_INT_GET_TFEIF)))
        {
            tmpReturn = (uint8)E_OK;
            break;
        }
        else
        {
            counter++;
        }
    }

    if ((uint8)E_OK == tmpReturn)
    {
        /* Set checksum type, use for interrupt */
        if (LIN_ENHANCED_CS == PduInfoPtr->Cs)
        {
            /* Update LIN Checksum type to LIN_ENHANCED_CS */
            Usart_ChecksumType[Channel] = (uint8)TRUE;
        }
        else
        {
            /* Update LIN Checksum type to LIN_CLASSIC_CS */
            Usart_ChecksumType[Channel] = (uint8)FALSE;
        }

        /* Set header status to TRUE if master wants to send the response frame */
        if (LIN_MASTER_RESPONSE == PduInfoPtr->Drc)
        {
            Lin_TransmitHeaderCommand[Channel] = LIN_TX_MASTER_RES_COMMAND;
            /* Update LIN channel frame operation status to LIN_CH_READY_STATE*/
            Lin_ChannelFrameStatus[Channel] = LIN_CH_READY_STATE;
        }
        else if (LIN_SLAVE_RESPONSE == PduInfoPtr->Drc)
        {
            Lin_TransmitHeaderCommand[Channel] = LIN_TX_SLAVE_RES_COMMAND;
            Lin_ChannelFrameStatus[Channel]    = LIN_CH_RECEIVE_NOTHING_STATE;
        }
        else
        {
            Lin_TransmitHeaderCommand[Channel] = LIN_TX_SLAVE_TO_SLAVE_COMMAND;
            Lin_ChannelFrameStatus[Channel]    = LIN_CH_RECEIVE_NOTHING_STATE;
        }

        /* The buffer contains [sync byte, pid, data, checksum] */
        /* total length */
        Lin_UsartBufferLength[Channel] =
          ((uint8)3U) + ((PduInfoPtr->Dl > USART_MAX_DATA_LENGTH) ? USART_MAX_DATA_LENGTH : PduInfoPtr->Dl);
        /* Write in the transmission buffer the synchronization byte and the PID */
        Lin_Usart_Buffer[Channel][USART_SYNCH_BYTE_OFFSET] = USART_SYNC_BYTE;
        Lin_Usart_Buffer[Channel][USART_PID_BYTE_OFFSET]   = PduInfoPtr->Pid;

        /* Set Data Direction */
        if (LIN_MASTER_RESPONSE == PduInfoPtr->Drc)
        {
            /* Do not transmit header here because it's a master->slave frame the header will be transmitted together
             * with the response when calling SendResponse function */
        }
        else
        {

            if (LIN_DMA_ENABLE == Lin_Im_DmaUserConfigInfo[hwModuleId].TxDmaStatus)
            {
                Lin_Im_DmaSendStop(hwModuleId, Channel);
            }
            else
            {
                /* do nothing */
            }

            if (LIN_DMA_ENABLE == Lin_Im_DmaUserConfigInfo[hwModuleId].RxDmaStatus)
            {
                Lin_Im_DmaReceiveStop(hwModuleId, Channel);
            }
            else
            {
                /* do nothing */
            }

            Usart_LL_SetIntrEnabled(usartx, USART_INT_SET_RDRIE, false);
            Usart_LL_SetIntrEnabled(usartx, USART_INT_SET_TXEIE, false);

            /* Turn on TXEIF INT */
            Lin_UsartBufferPtr[Channel]    = 0U;
            Lin_ReceiveDataCount[Channel]  = 0U;
            Lin_ReceivePdu[Channel].SduPtr = Lin_ReceiveTemp[Channel];

            Usart_LL_ClearIntrFlag(Usart_ModulePtr[hwModuleId], USART_INT_CLEAR_OVFEIC);
            Usart_LL_ClearIntrFlag(Usart_ModulePtr[hwModuleId], USART_INT_CLEAR_FREIC);
            Usart_LL_ClearIntrFlag(Usart_ModulePtr[hwModuleId], USART_INT_CLEAR_BRIC);
            Usart_LL_EnableSendBlank(usartx);

            if (LIN_DMA_ENABLE == Lin_Im_DmaUserConfigInfo[hwModuleId].RxDmaStatus)
            {
                /**
                 * @brief Using DMA to transfer data requires waiting for the delimiter to end; otherwise, it may cause
                 * DMA data transfer
                 */
                /*PRQA S 4115,4558 1 #KQR100001 */
                while ((Usart_LL_GetIntrFlag(Usart_ModulePtr[hwModuleId], USART_INT_GET_BRIF) != true) && (timeOut))
                {
                    timeOut--;
                }
                Usart_LL_ClearIntrFlag(Usart_ModulePtr[hwModuleId], USART_INT_CLEAR_BRIC);
                /**
                 * @brief Performing a dummy read to clear the data prevents existing data from causing an overflow flag
                 * after sending the frame header data, which would otherwise prevent the triggering of DMA data
                 * transfer
                 */
                (void)Usart_LL_GetRxBufferData(Usart_ModulePtr[hwModuleId]);
                Lin_Im_DmaReceiveStart(hwModuleId, Channel);
            }
            else
            {
                /* Do nothing */
            }

            Usart_LL_SetTxBufferData(usartx, Lin_Usart_Buffer[Channel][USART_SYNCH_BYTE_OFFSET]);
            /* Turn on TXEIF INT */
            Usart_LL_SetIntrEnabled(usartx, USART_INT_SET_TXEIE, true);
        }
    }
    else
    {
        /* do nothing */
    }
    return tmpReturn;
}

/**
 * @brief lin dma send process
 * @param
 * @param
 */
static void Lin_Im_DmaSendStart(Lin_UsartModuleType Module, uint8 Channel)
{
    Dma_LL_SetFinishTransIntrEnabled(
      Lin_Im_DmaUserConfigInfo[Module].TxDmaBasePtr, (Dma_Channel_t)Lin_Im_DmaUserConfigInfo[Module].TxDmaChannel,
      false);
    Dma_LL_ClearIntrFlag(Lin_Im_DmaUserConfigInfo[Module].TxDmaBasePtr,
                         (Dma_Channel_t)Lin_Im_DmaUserConfigInfo[Module].TxDmaChannel, DMA_LIFR_FTIF_LOGIC_BIT);

    /* disable dma channel */
    Dma_LL_SetChannelEnabled(
      Lin_Im_DmaUserConfigInfo[Module].TxDmaBasePtr, (Dma_Channel_t)Lin_Im_DmaUserConfigInfo[Module].TxDmaChannel,
      false);

    Dma_LL_SetMemAddr(Lin_Im_DmaUserConfigInfo[Module].TxDmaBasePtr,
                      (Dma_Channel_t)Lin_Im_DmaUserConfigInfo[Module].TxDmaChannel, (uint32)&Lin_Usart_Buffer[Channel]);
    Dma_LL_SetNumberOfData(
      Lin_Im_DmaUserConfigInfo[Module].TxDmaBasePtr, (Dma_Channel_t)Lin_Im_DmaUserConfigInfo[Module].TxDmaChannel,
      Lin_UsartBufferLength[Channel]);

    Dma_LL_SetFinishTransIntrEnabled(
      Lin_Im_DmaUserConfigInfo[Module].TxDmaBasePtr, (Dma_Channel_t)Lin_Im_DmaUserConfigInfo[Module].TxDmaChannel,
      true);

    /* enable dma channel */
    Dma_LL_SetChannelEnabled(
      Lin_Im_DmaUserConfigInfo[Module].TxDmaBasePtr, (Dma_Channel_t)Lin_Im_DmaUserConfigInfo[Module].TxDmaChannel,
      true);

    /* enable uart send dma */
    Usart_LL_SetTransDmaEnabled(Usart_ModulePtr[Module], true);
}

/**
 * @brief Sends the response part of the LIN frame.
 * @param Channel LIN channel to be addressed.
 * @param PduInfoPtr pointer to PDU containing the PID, Checksum model,Response type, Dl and SDU data pointer.
 * @return void
 * @retval void
 */
FUNC(void, LIN_CODE) Lin_Im_UsartSendResponse(uint8 Channel, Lin_PduType const *PduInfoPtr)
{
    uint8                loop;
    uint8                frameId;
    Lin_UsartModuleType  hwModuleId;
    Usart_RegisterMap_t *usartx;

    hwModuleId = Lin_ChannelConfigPtr[Channel]->HwModule;

    usartx = kfLin_GetModuleFromIndex(hwModuleId);

    for (loop = (uint8)0U; loop < ((PduInfoPtr->Dl > USART_MAX_DATA_LENGTH) ? USART_MAX_DATA_LENGTH : PduInfoPtr->Dl);
         loop++)
    {
        Lin_Usart_Buffer[Channel][USART_DATA_OFFSET + loop] = PduInfoPtr->SduPtr[loop];
    }

    frameId = (uint8)(PduInfoPtr->Pid & USART_FRAME_ID_MASK);
    /* PRQA S 3352 1 #KQR003352 */
    switch (frameId)
    {
    case USART_MASTER_REQUEST_DIAGNOSTIC_PID:
    case USART_SLAVE_RESPONSE_DIAGNOSTIC_PID:
        Lin_Usart_Buffer[Channel][Lin_UsartBufferLength[Channel] - ((uint8)1U)] =
          (uint8)Lin_Im_ChecksumCalc(Channel, LIN_CLASSIC_CS);
        break;
    default:
        if ((boolean)TRUE == Usart_ChecksumType[Channel])
        {
            /* Enhance checksum */
            Lin_Usart_Buffer[Channel][Lin_UsartBufferLength[Channel] - ((uint8)1U)] =
              (uint8)Lin_Im_ChecksumCalc(Channel, LIN_ENHANCED_CS);
            Usart_ChecksumType[Channel] = (boolean)TRUE;
        }
        else
        {
            /* Classic checksum */
            Lin_Usart_Buffer[Channel][Lin_UsartBufferLength[Channel] - ((uint8)1U)] =
              (uint8)Lin_Im_ChecksumCalc(Channel, LIN_CLASSIC_CS);
            Usart_ChecksumType[Channel] = (boolean)FALSE;
        }
        break;
    }

    if (LIN_DMA_ENABLE == Lin_Im_DmaUserConfigInfo[hwModuleId].RxDmaStatus)
    {
        Lin_Im_DmaReceiveStop(hwModuleId, Channel);
    }
    else
    {
        /* do nothing */
    }

    if (LIN_DMA_ENABLE == Lin_Im_DmaUserConfigInfo[hwModuleId].TxDmaStatus)
    {
        Lin_Im_DmaSendStop(hwModuleId, Channel);
    }
    else
    {
        /* do nothing */
    }

    Usart_LL_SetIntrEnabled(usartx, USART_INT_SET_RDRIE, false);
    Usart_LL_SetIntrEnabled(usartx, USART_INT_SET_TXEIE, false);

    Usart_LL_ClearIntrFlag(Usart_ModulePtr[hwModuleId], USART_INT_CLEAR_OVFEIC);
    Usart_LL_ClearIntrFlag(Usart_ModulePtr[hwModuleId], USART_INT_CLEAR_FREIC);
    Usart_LL_ClearIntrFlag(Usart_ModulePtr[hwModuleId], USART_INT_CLEAR_BRIC);
    Usart_LL_EnableSendBlank(usartx);

    Lin_UsartBufferPtr[Channel]   = 0U;
    Lin_ReceiveDataCount[Channel] = 0U;

    if (LIN_DMA_ENABLE == Lin_Im_DmaUserConfigInfo[hwModuleId].TxDmaStatus)
    {
        /* disable uart send dma */
        Usart_LL_SetTransDmaEnabled(usartx, false);
        Lin_Im_DmaSendStart(hwModuleId, Channel);
    }
    else
    {
        Usart_LL_SetTxBufferData(usartx, Lin_Usart_Buffer[Channel][USART_SYNCH_BYTE_OFFSET]);
        /* Turn on TXEIF INT */
        Usart_LL_SetIntrEnabled(usartx, USART_INT_SET_TXEIE, true);
    }
}

/**
 * @brief Prepares and send a go-to-sleep-command frame on Channel.
 * @details This function stops any ongoing transmission and initiates the transmission of the sleep command (master
 * command frame with id = 0x3C and data = (0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF).
 * @param Channel LIN channel to be addressed.
 * @return Std_ReturnType
 * @retval E_NOT_OK In case of a time-out situation only.
 * @retval E_OK Otherwise.
 */
FUNC(Std_ReturnType, LIN_CODE) Lin_Im_UsartGoToSleep(uint8 Channel)
{
    Std_ReturnType       tmpReturn = (uint8)E_NOT_OK;
    Usart_RegisterMap_t *usartx;
    Lin_UsartModuleType  hwModuleId;
    volatile uint32      counter = 0U;

    hwModuleId = Lin_ChannelConfigPtr[Channel]->HwModule;
    usartx     = kfLin_GetModuleFromIndex(hwModuleId);

    /* Wait for the sender to be empty */
    while (counter <= (LIN_TIMEOUT_LOOPS + (uint32)1U))
    {
        /* PRQA S 2109 2 #KQR002109 */
        if ((1U == Usart_LL_GetIntrFlag(usartx, USART_INT_GET_TXEIF)) &&
            (1U == Usart_LL_GetIntrFlag(usartx, USART_INT_GET_TFEIF)))
        {
            tmpReturn = (uint8)E_OK;
            break;
        }
        else
        {
            counter++;
        }
    }

    if ((uint8)E_OK == tmpReturn)
    {
        if (LIN_DMA_ENABLE == Lin_Im_DmaUserConfigInfo[hwModuleId].RxDmaStatus)
        {
            Lin_Im_DmaReceiveStop(hwModuleId, Channel);
        }
        else
        {
            /* do nothing */
        }

        if (LIN_DMA_ENABLE == Lin_Im_DmaUserConfigInfo[hwModuleId].TxDmaStatus)
        {
            Lin_Im_DmaSendStop(hwModuleId, Channel);
        }
        else
        {
            /* do nothing */
        }

        Usart_LL_SetIntrEnabled(usartx, USART_INT_SET_RDRIE, false);
        Usart_LL_SetIntrEnabled(usartx, USART_INT_SET_TXEIE, false);

        Lin_TransmitHeaderCommand[Channel] = LIN_TX_MASTER_RES_COMMAND;

        /* Write in the transmission buffer the synchronization byte and the PID */
        Lin_Usart_Buffer[Channel][USART_SYNCH_BYTE_OFFSET] = USART_SYNC_BYTE;
        Lin_Usart_Buffer[Channel][USART_PID_BYTE_OFFSET]   = USART_MASTER_REQUEST_DIAGNOSTIC_PID;

        Lin_Usart_Buffer[Channel][2U] = USART_DATA_0;
        Lin_Usart_Buffer[Channel][3U] = USART_DATA_255;
        Lin_Usart_Buffer[Channel][4U] = USART_DATA_255;
        Lin_Usart_Buffer[Channel][5U] = USART_DATA_255;
        Lin_Usart_Buffer[Channel][6U] = USART_DATA_255;
        Lin_Usart_Buffer[Channel][7U] = USART_DATA_255;
        Lin_Usart_Buffer[Channel][8U] = USART_DATA_255;
        Lin_Usart_Buffer[Channel][9U] = USART_DATA_255;

        Lin_UsartBufferLength[Channel] = USART_MAX_BUFFER_LENGTH;

        Lin_Usart_Buffer[Channel][Lin_UsartBufferLength[Channel] - ((uint8)1U)] =
          (uint8)Lin_Im_ChecksumCalc(Channel, LIN_CLASSIC_CS);

        Usart_LL_ClearIntrFlag(Usart_ModulePtr[hwModuleId], USART_INT_CLEAR_OVFEIC);
        Usart_LL_ClearIntrFlag(Usart_ModulePtr[hwModuleId], USART_INT_CLEAR_FREIC);
        Usart_LL_ClearIntrFlag(Usart_ModulePtr[hwModuleId], USART_INT_CLEAR_BRIC);
        Usart_LL_EnableSendBlank(usartx);

        Lin_UsartBufferPtr[Channel]   = 0U;
        Lin_ReceiveDataCount[Channel] = 0U;

        /* Set header command type is sleep */
        Lin_TransmitHeaderCommand[Channel] = LIN_TX_SLEEP_COMMAND;

        if (LIN_DMA_ENABLE == Lin_Im_DmaUserConfigInfo[hwModuleId].TxDmaStatus)
        {
            /* disable uart send dma */
            Usart_LL_SetTransDmaEnabled(usartx, false);
            Lin_Im_DmaSendStart(hwModuleId, Channel);
        }
        else
        {
            Usart_LL_SetTxBufferData(usartx, Lin_Usart_Buffer[Channel][USART_SYNCH_BYTE_OFFSET]);
            /* Turn on TXEIF INT */
            Usart_LL_SetIntrEnabled(usartx, USART_INT_SET_TXEIE, true);
        }
    }
    else
    {
        /* do nothing */
    }
    return tmpReturn;
}

/**
 * @brief Same function as Lin_Im_UsartGoToSleepInternal() but without sending a go-to-sleep-command on the bus.
 * @details This function stops any ongoing transmission and put the Channel in sleep mode (then LIN hardware enters a
 * reduced power operation mode).
 * @param Channel LIN channel to be addressed.
 * @return Std_ReturnType
 * @retval E_NOT_OK In case of a time-out situation only
 * @retval E_OK Otherwise
 */
FUNC(Std_ReturnType, LIN_CODE) Lin_Im_UsartGoToSleepInternal(uint8 Channel)
{
    Std_ReturnType       tmpReturn = (uint8)E_NOT_OK;
    Usart_RegisterMap_t *usartx;
    Lin_UsartModuleType  hwModuleId;
    volatile uint32      counter = 0U;

    hwModuleId = Lin_ChannelConfigPtr[Channel]->HwModule;
    usartx     = kfLin_GetModuleFromIndex(hwModuleId);

    /* Wait for the sender to be empty */
    while (counter <= (LIN_TIMEOUT_LOOPS + (uint32)1U))
    {
        /* PRQA S 2109 2 #KQR002109 */
        if ((1U == Usart_LL_GetIntrFlag(usartx, USART_INT_GET_TXEIF)) &&
            (1U == Usart_LL_GetIntrFlag(usartx, USART_INT_GET_TFEIF)))
        {
            tmpReturn = (uint8)E_OK;
            break;
        }
        else
        {
            counter++;
        }
    }

    if ((uint8)E_OK == tmpReturn)
    {
        /* Set Channel State to Sleep */
        Lin_ChannelStatus[Channel] = LIN_CH_SLEEP_STATE;
        /* Update Lin_TransmitHeaderCommand value to LIN_TX_NO_COMMAND */
        Lin_TransmitHeaderCommand[Channel] = LIN_TX_NO_COMMAND;
        /* @implements #SWS_Lin_00222 Enable wake-up detection */
        Usart_LL_EnableWakeUp(usartx);
    }
    else
    {
        /* do nothing */
    }

    return tmpReturn;
}

/**
 * @brief Sends a wake up signal to the LIN bus.
 * @details This function shall sent a wake up signal to the LIN bus and put the LIN channel in LIN_CH_OPERATIONAL
 * state.
 * @param Channel LIN channel to be addressed.
 * @return void
 * @retval void
 */
FUNC(void, LIN_CODE) Lin_Im_UsartWakeUp(uint8 Channel)
{
    Usart_RegisterMap_t *usartx;

    usartx = kfLin_GetModuleFromIndex(Lin_ChannelConfigPtr[Channel]->HwModule);

    Usart_LL_EnableSendBlank(usartx);
    Usart_LL_DisableWakeUp(usartx);
}

/**
 * @brief Wake up the LIN channel.
 * @details This function shall put the LIN channel in LIN_CH_OPERATIONAL state without sending a wake up signal to the
 * LIN bus
 * @param Channel LIN channel to be addressed.
 * @return void
 * @retval void
 */
FUNC(void, LIN_CODE) Lin_Im_UsartWakeUpInternal(uint8 Channel)
{
    Usart_LL_DisableWakeUp(kfLin_GetModuleFromIndex(Lin_ChannelConfigPtr[Channel]->HwModule));
}

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
FUNC(Lin_StatusType, LIN_CODE) Lin_Im_UsartHardwareGetStatus(uint8 Channel, uint8 *LinSduPtr)
{
    uint8          temp1;
    uint8          temp2;
    uint8          transmitHeaderCommand;
    uint8          channelFrameError;
    uint8          channelFrameStatus;
    Lin_StatusType tempReturn = LIN_NOT_OK;

    temp1                 = Lin_UsartBufferPtr[Channel];
    temp2                 = Lin_UsartBufferLength[Channel];
    transmitHeaderCommand = Lin_TransmitHeaderCommand[Channel];
    channelFrameStatus    = Lin_ChannelFrameStatus[Channel];

    /* Frame transmission */
    if (((uint8)0U) != temp2)
    {
        channelFrameError = Lin_ChannelFrameErrorStatus[Channel];
        /* Header transmission */
        if ((USART_PID_BYTE_OFFSET + ((uint8)1U)) >= temp1)
        {
            switch (channelFrameError)
            {
            /* No error has occurred */
            case LIN_NO_ERROR: {
                if ((LIN_TX_SLAVE_TO_SLAVE_COMMAND == transmitHeaderCommand) &&
                    (LIN_TX_HEADER_COMPLETE_STATE == channelFrameStatus))
                {
                    tempReturn = LIN_TX_OK;
                }
                else if ((LIN_TX_SLAVE_RES_COMMAND == transmitHeaderCommand) &&
                         (LIN_TX_HEADER_COMPLETE_STATE == channelFrameStatus))
                {
                    tempReturn = LIN_RX_NO_RESPONSE;
                }
                else
                {
                    tempReturn = LIN_TX_BUSY;
                }
                break;
            }
                /* Errors occurred */
            case LIN_BIT_ERROR:
                tempReturn = LIN_TX_HEADER_ERROR;
                break;

            default:
                tempReturn = LIN_NOT_OK;
                break;
            }
        }
        /* Data transmission */
        /* PRQA S 1860 1 #KQR001860 */
        else if ((temp2 - 1) > temp1)
        {
            switch (channelFrameError)
            {
            /* No error has occurred */
            case LIN_NO_ERROR: {
                if (LIN_TX_SLAVE_RES_COMMAND == transmitHeaderCommand)
                {
                    if (LIN_RX_ONGOING_STATE == channelFrameStatus)
                    {
                        tempReturn = LIN_RX_BUSY;
                    }
                    else if (LIN_TX_HEADER_COMPLETE_STATE == channelFrameStatus)
                    {
                        tempReturn = LIN_TX_OK;
                    }
                    else
                    {
                        tempReturn = LIN_TX_BUSY;
                    }
                }
                else
                {
                    /* do nothing */
                }
                break;
            }
                /* Errors occurred */
            case LIN_BIT_ERROR:
                tempReturn = LIN_TX_ERROR;
                break;

            case LIN_BUFFER_OVER_RUN_ERROR:
            case LIN_FRAME_ERROR:
                /* TODO */
                tempReturn = LIN_TX_ERROR;
                break;
            default:
                tempReturn = LIN_NOT_OK;
                break;
            }
        }
        /* The last byte has been transmitted/received */
        /* PRQA S 1860 1 #KQR001860 */
        else if ((temp2 - 1) == temp1)
        {

            switch (channelFrameError)
            {
            /* No error has occurred */
            case LIN_NO_ERROR:
                if (LIN_TX_COMPLETE_STATE == channelFrameStatus)
                {
                    tempReturn                     = LIN_TX_OK;
                    Lin_UsartBufferLength[Channel] = (uint8)0U;
                }
                else if (LIN_RX_COMPLETE_STATE == channelFrameStatus)
                {
                    tempReturn = LIN_RX_OK;
                    Lin_Im_CopyData(Channel, LinSduPtr);
                    Lin_UsartBufferLength[Channel] = (uint8)0U;
                }
                else
                {
                    /* Code Flow Error */
                    tempReturn = LIN_NOT_OK;
                }
                break;
                /* Errors occurred */
            case LIN_BUFFER_OVER_RUN_ERROR:
            case LIN_FRAMING_ERROR:
                tempReturn = LIN_RX_ERROR;
                break;
            default:
                (void)0U;
                break;
            }
        }
        else
        {
            /* Code Flow Error */
            tempReturn = LIN_NOT_OK;
        }
    }
    /* LIN is idle */
    else
    {
        tempReturn = LIN_OPERATIONAL;
    }
    return tempReturn;
}

/**
 * @brief Usart idle process
 */
static FUNC(void, LIN_CODE) Lin_IM_IdleLineDetectInterruptHandler(uint8 Channel)
{
    if (Lin_ChannelStatus[Channel] == LIN_CH_SLEEP_STATE)
    {
        if ((uint8)STD_ON == Lin_WakeupSupport[Channel])
        {
/* Indicates a valid timer wakeup event to ECU State Manager */
/* @implements #SWS_Lin_00176 */
#if 0
            EcuM_CheckWakeup(Lin_pChannelConfigPtr[u8LogicalChannel]->pChannelConfigPC->ChannelEcuMWakeupSource);
#endif
            /* Update Wakeup Flag */
            Lin_Usart_WakeupFlag[Channel] = (uint8)FALSE;
            /* Set Channel state Operational */
            Lin_ChannelStatus[Channel] = LIN_CH_OPERATIONAL;
            /* Update LIN channel frame operation status to LIN_CH_READY_STATE */
            Lin_ChannelFrameStatus[Channel] = LIN_CH_READY_STATE;
        }
        else
        {
            /* Update Wakeup Flag */
            Lin_Usart_WakeupFlag[Channel] = (uint8)TRUE;
        }
    }
    else
    {
        /* do nothing */
    }
}

/**
 * @brief receive interrupt process
 */
static FUNC(void, LIN_CODE) Lin_RxInterruptHandler(uint8 Channel)
{
    Lin_UsartModuleType hwModuleId;

    hwModuleId = Lin_ChannelConfigPtr[Channel]->HwModule;

    /* PRQA S 2109 2 #KQR002109 */
    if ((TRUE == Usart_LL_GetIntrEnabledState(Usart_ModulePtr[hwModuleId], USART_INT_SET_RDRIE)) &&
        (Usart_LL_GetIntrFlag(Usart_ModulePtr[hwModuleId], USART_INT_GET_RDRIF) == 1U))
    {
        /* Receive DATA */
        switch (Lin_MasterControlStatus[Channel])
        {

        case C_LIN_RECEIVE_MODE_STATUS: {
            /* PRQA S 2109 1 #KQR002109 */
            if (Usart_LL_GetIntrFlag(Usart_ModulePtr[hwModuleId], USART_INT_GET_RDRIF) == 1U)
            {
                /* Update LIN channel frame operation status to LIN_RX_ONGOING_STATE */
                Lin_ChannelFrameStatus[Channel] = LIN_RX_ONGOING_STATE;

                if (Lin_ReceiveDataCount[Channel] < (Lin_UsartBufferLength[Channel] - 3U))
                {
                    /* If the first data read is the sent PID, discard the data. */
                    if ((Lin_ReceiveDataCount[Channel] == 0U) &&
                        (Usart_LL_GetRxBufferData(Usart_ModulePtr[hwModuleId]) ==
                         Lin_Usart_Buffer[Channel][USART_PID_BYTE_OFFSET]))
                    {
                        ;
                    }
                    else
                    {
                        Lin_ReceivePdu[Channel].SduPtr[Lin_ReceiveDataCount[Channel]] =
                          (uint8)Usart_LL_GetRxBufferData(Usart_ModulePtr[hwModuleId]);
                        Lin_ReceiveDataCount[Channel]++;
                        Lin_UsartBufferPtr[Channel]++;
                    }
                }
                else
                {
                    Lin_MasterControlStatus[Channel] = C_LIN_CHECKSUM_STATUS;
                }
            }
            else
            {
            }
            break;
        }
        case C_LIN_CHECKSUM_STATUS: {
            /* PRQA S 2109 1 #KQR002109 */
            if (Usart_LL_GetIntrFlag(Usart_ModulePtr[hwModuleId], USART_INT_GET_RDRIF) == 1U)
            {
                Lin_ReceivePdu[Channel].SduPtr[Lin_ReceiveDataCount[Channel]] =
                  (uint8)Usart_LL_GetRxBufferData(Usart_ModulePtr[hwModuleId]);
                Lin_UsartBufferPtr[Channel]++;
                Lin_ReceiveDataCount[Channel]    = 0U;
                Lin_MasterControlStatus[Channel] = C_LIN_BUS_IDLE_STATUS;
                Lin_IM_IdleLineDetectInterruptHandler(Channel);
            }
            else
            {
                Lin_ReceiveDataCount[Channel]    = 0U;
                Lin_MasterControlStatus[Channel] = C_LIN_BUS_IDLE_STATUS;
            }

            /* changed receive status */
            Lin_ChannelFrameStatus[Channel] = LIN_RX_COMPLETE_STATE;
            break;
        }
        default: {
            Lin_MasterControlStatus[Channel] = C_LIN_BUS_IDLE_STATUS;
            /* Empty receive BUF RDRIF */
            (void)Usart_LL_GetRxBufferData(Usart_ModulePtr[hwModuleId]);
            break;
        }
        }
    }
    else
    {
        /* do nothing */
    }
    if (Usart_LL_GetIntrFlag(Usart_ModulePtr[hwModuleId], USART_INT_GET_FREIF))
    {
        Usart_LL_ClearIntrFlag(Usart_ModulePtr[hwModuleId], USART_INT_CLEAR_FREIC);
    }
    else
    {
        /* Do Nothing */
    }

    if (Usart_LL_GetIntrFlag(Usart_ModulePtr[hwModuleId], USART_INT_GET_OVFEIF))
    {
        Usart_LL_ClearIntrFlag(Usart_ModulePtr[hwModuleId], USART_INT_CLEAR_OVFEIC);
    }
    else
    {
        /* Do Nothing */
    }
}

/**
 * @brief send interrupt process
 */
static FUNC(void, LIN_CODE) Lin_TxInterruptHandler(uint8 Channel)
{
    VAR(boolean, AUTOMATIC) bIsSleepFrame = (boolean)FALSE;
    Lin_UsartModuleType hwModuleId;

    hwModuleId = Lin_ChannelConfigPtr[Channel]->HwModule;

    /* SEND DATA */
    /* PRQA S 2109 2 #KQR002109 */
    if ((TRUE == Usart_LL_GetIntrEnabledState(Usart_ModulePtr[hwModuleId], USART_INT_SET_TXEIE)) &&
        (Usart_LL_GetIntrFlag(Usart_ModulePtr[hwModuleId], USART_INT_GET_TXEIF) == 1U))
    {
        if (Lin_TransmitHeaderCommand[Channel] == LIN_TX_SLAVE_RES_COMMAND)
        {
            /* Send Header */
            if (Lin_UsartBufferPtr[Channel] == 0U)
            {
                Usart_LL_SetTxBufferData(Usart_ModulePtr[hwModuleId], Lin_Usart_Buffer[Channel][USART_PID_BYTE_OFFSET]);
                Lin_UsartBufferPtr[Channel]++;
            }
            else
            {
                /* Update LIN channel frame operation status to LIN_TX_HEADER_COMPLETE_STATE */
                Lin_ChannelFrameStatus[Channel] = LIN_TX_HEADER_COMPLETE_STATE;

                Lin_TransmitHeaderCommand[Channel] = LIN_TX_NO_COMMAND;

                Usart_LL_SetIntrEnabled(kfLin_GetModuleFromIndex(hwModuleId), USART_INT_SET_TXEIE, false);

                Lin_MasterControlStatus[Channel] = C_LIN_RECEIVE_MODE_STATUS;
                /* Empty receive BUF RDRIF */
                (void)Usart_LL_GetRxBufferData(Usart_ModulePtr[hwModuleId]);

                if (LIN_DMA_ENABLE == Lin_Im_DmaUserConfigInfo[hwModuleId].RxDmaStatus)
                {
                    /**
                     * @brief When using DMA for reception, if reception has already started during the transmission of
                     * the frame header, no processing is required at this time.
                     */
                }
                else
                {
                    Usart_LL_SetIntrEnabled(Usart_ModulePtr[hwModuleId], USART_INT_SET_RDRIE, true);
                }
            }
        }
        else if (Lin_TransmitHeaderCommand[Channel] == LIN_TX_MASTER_RES_COMMAND)
        {
            /* Send Header */
            if (Lin_UsartBufferPtr[Channel] == 0U)
            {
                Usart_LL_SetTxBufferData(Usart_ModulePtr[hwModuleId], Lin_Usart_Buffer[Channel][USART_PID_BYTE_OFFSET]);
                Lin_UsartBufferPtr[Channel]++;
            }
            /* PRQA S 1860 1 #KQR001860 */
            else if (Lin_UsartBufferPtr[Channel] <= (Lin_UsartBufferLength[Channel] - 3U))
            {
                Usart_LL_SetTxBufferData(
                  Usart_ModulePtr[hwModuleId],
                  Lin_Usart_Buffer[Channel][(USART_DATA_OFFSET + Lin_UsartBufferPtr[Channel]) - (uint8)1U]);
                Lin_UsartBufferPtr[Channel]++;
            }
            /* PRQA S 1860 1 #KQR001860 */
            else if (Lin_UsartBufferPtr[Channel] == (Lin_UsartBufferLength[Channel] - 2U))
            {
                Usart_LL_SetTxBufferData(
                  Usart_ModulePtr[hwModuleId], Lin_Usart_Buffer[Channel][Lin_UsartBufferLength[Channel] - (uint8)1U]);
                Lin_UsartBufferPtr[Channel]++;
            }
            else
            {
                Usart_LL_SetIntrEnabled(kfLin_GetModuleFromIndex(hwModuleId), USART_INT_SET_TXEIE, false);

                Lin_TransmitHeaderCommand[Channel] = LIN_TX_NO_COMMAND;

                Lin_ChannelFrameStatus[Channel] = LIN_TX_COMPLETE_STATE;
            }
        }
        else if (Lin_TransmitHeaderCommand[Channel] == LIN_TX_SLEEP_COMMAND)
        {
            /* Send Header */
            if (Lin_UsartBufferPtr[Channel] == 0U)
            {
                Usart_LL_SetTxBufferData(Usart_ModulePtr[hwModuleId], Lin_Usart_Buffer[Channel][USART_PID_BYTE_OFFSET]);
                Lin_UsartBufferPtr[Channel]++;
            }
            else if (Lin_UsartBufferPtr[Channel] <= 8U)
            {
                Usart_LL_SetTxBufferData(
                  Usart_ModulePtr[hwModuleId],
                  Lin_Usart_Buffer[Channel][(USART_DATA_OFFSET + Lin_UsartBufferPtr[Channel]) - (uint8)1U]);
                Lin_UsartBufferPtr[Channel]++;
            }
            else if (Lin_UsartBufferPtr[Channel] == 9U)
            {
                Usart_LL_SetTxBufferData(
                  Usart_ModulePtr[hwModuleId], Lin_Usart_Buffer[Channel][Lin_UsartBufferLength[Channel] - (uint8)1U]);
                Lin_UsartBufferPtr[Channel]++;
            }
            else
            {
                Usart_LL_SetIntrEnabled(kfLin_GetModuleFromIndex(hwModuleId), USART_INT_SET_TXEIE, false);

                Lin_TransmitHeaderCommand[Channel] = LIN_TX_NO_COMMAND;
                Lin_ChannelFrameStatus[Channel]    = LIN_TX_COMPLETE_STATE;

                bIsSleepFrame = (boolean)TRUE;
            }

        } /* LIN_TX_SLAVE_TO_SLAVE_COMMAND */
        else if (Lin_TransmitHeaderCommand[Channel] == LIN_TX_SLAVE_TO_SLAVE_COMMAND)
        {
            /* Send Header */
            if (Lin_UsartBufferPtr[Channel] == (Lin_UsartBufferLength[Channel] - 3U))
            {
                Usart_LL_SetTxBufferData(Usart_ModulePtr[hwModuleId], Lin_Usart_Buffer[Channel][USART_PID_BYTE_OFFSET]);
                Lin_UsartBufferPtr[Channel]++;
            }
            else
            {
                /* Update LIN channel frame operation status to LIN_TX_HEADER_COMPLETE_STATE */
                Lin_ChannelFrameStatus[Channel] = LIN_TX_HEADER_COMPLETE_STATE;

                Usart_LL_SetIntrEnabled(Usart_ModulePtr[hwModuleId], USART_INT_SET_TXEIE, false);
                Lin_TransmitHeaderCommand[Channel] = LIN_TX_NO_COMMAND;
            }
        }
        else
        {
            Usart_LL_SetIntrEnabled(kfLin_GetModuleFromIndex(hwModuleId), USART_INT_SET_TXEIE, false);
            Lin_ChannelFrameStatus[Channel]    = LIN_CH_READY_STATE;
            Lin_TransmitHeaderCommand[Channel] = LIN_TX_NO_COMMAND;
        }

        if ((boolean)TRUE == bIsSleepFrame)
        {
            Lin_TransmitHeaderCommand[Channel] = LIN_TX_NO_COMMAND;
            /* Enable wake up detection */
            if ((uint8)STD_ON == Lin_WakeupSupport[Channel])
            {
                /*Start Detection interrupt*/
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
    }
    else
    {
        /* do nothing */
    }
}

#if (LIN_SLAVE_MODE_USED == STD_ON)

/**
 * @brief lin slave dma send process
 * @param
 * @param
 */
static void Lin_Im_SlaveDmaSendStart(Lin_UsartModuleType Module, uint8 Channel, Lin_PduType const *FrameStruct)
{
    if ((NULL_PTR == FrameStruct) || (0U == FrameStruct->Dl) || (FrameStruct->Dl > 8U))
    {
        /* do nothing */
    }
    else
    {
        uint8 CheckSum;

        if (LIN_CLASSIC_CS == FrameStruct->Cs)
        {
            CheckSum = GetCheckSumValue(0U, FrameStruct->SduPtr, FrameStruct->Dl);
        }
        else
        {
            CheckSum = GetCheckSumValue(FrameStruct->Pid, FrameStruct->SduPtr, FrameStruct->Dl);
        }

        Lin_ReceiveTemp[Channel][FrameStruct->Dl] = CheckSum;

        Dma_LL_SetFinishTransIntrEnabled(
          Lin_Im_DmaUserConfigInfo[Module].TxDmaBasePtr, (Dma_Channel_t)Lin_Im_DmaUserConfigInfo[Module].TxDmaChannel,
          false);
        Dma_LL_ClearIntrFlag(Lin_Im_DmaUserConfigInfo[Module].TxDmaBasePtr,
                             (Dma_Channel_t)Lin_Im_DmaUserConfigInfo[Module].TxDmaChannel, DMA_LIFR_FTIF_LOGIC_BIT);

        /* disable dma channel */
        Dma_LL_SetChannelEnabled(
          Lin_Im_DmaUserConfigInfo[Module].TxDmaBasePtr, (Dma_Channel_t)Lin_Im_DmaUserConfigInfo[Module].TxDmaChannel,
          false);

        Dma_LL_SetMemAddr(
          Lin_Im_DmaUserConfigInfo[Module].TxDmaBasePtr, (Dma_Channel_t)Lin_Im_DmaUserConfigInfo[Module].TxDmaChannel,
          (uint32)&Lin_ReceiveTemp[Channel]);
        Dma_LL_SetNumberOfData(
          Lin_Im_DmaUserConfigInfo[Module].TxDmaBasePtr, (Dma_Channel_t)Lin_Im_DmaUserConfigInfo[Module].TxDmaChannel,
          (uint16)((uint32)FrameStruct->Dl + 1U));

        Dma_LL_SetFinishTransIntrEnabled(
          Lin_Im_DmaUserConfigInfo[Module].TxDmaBasePtr, (Dma_Channel_t)Lin_Im_DmaUserConfigInfo[Module].TxDmaChannel,
          true);

        /* enable dma channel */
        Dma_LL_SetChannelEnabled(
          Lin_Im_DmaUserConfigInfo[Module].TxDmaBasePtr, (Dma_Channel_t)Lin_Im_DmaUserConfigInfo[Module].TxDmaChannel,
          true);

        /* enable uart send dma */
        Usart_LL_SetTransDmaEnabled(Usart_ModulePtr[Module], true);
    }
}

/**
 * @brief lin slave dma receive process
 * @param
 * @param
 */
static void Lin_Im_SlaveDmaReceiveStart(Lin_UsartModuleType Module, uint8 Channel)
{
    Usart_LL_SetRecvDmaEnabled(Usart_ModulePtr[Module], false);

    Dma_LL_SetFinishTransIntrEnabled(
      Lin_Im_DmaUserConfigInfo[Module].RxDmaBasePtr, (Dma_Channel_t)Lin_Im_DmaUserConfigInfo[Module].RxDmaChannel,
      false);
    Dma_LL_ClearIntrFlag(Lin_Im_DmaUserConfigInfo[Module].RxDmaBasePtr,
                         (Dma_Channel_t)Lin_Im_DmaUserConfigInfo[Module].RxDmaChannel, DMA_LIFR_FTIF_LOGIC_BIT);

    /* disable dma channel */
    Dma_LL_SetChannelEnabled(
      Lin_Im_DmaUserConfigInfo[Module].RxDmaBasePtr, (Dma_Channel_t)Lin_Im_DmaUserConfigInfo[Module].RxDmaChannel,
      false);

    Dma_LL_SetMemAddr(
      Lin_Im_DmaUserConfigInfo[Module].RxDmaBasePtr, (Dma_Channel_t)Lin_Im_DmaUserConfigInfo[Module].RxDmaChannel,
      (uint32)&Lin_ReceivePdu[Channel].SduPtr[0U]);
    Dma_LL_SetNumberOfData(
      Lin_Im_DmaUserConfigInfo[Module].RxDmaBasePtr, (Dma_Channel_t)Lin_Im_DmaUserConfigInfo[Module].RxDmaChannel,
      (uint16)((uint32)Lin_ReceivePdu[Channel].Dl + 1U));

    Dma_LL_SetFinishTransIntrEnabled(
      Lin_Im_DmaUserConfigInfo[Module].RxDmaBasePtr, (Dma_Channel_t)Lin_Im_DmaUserConfigInfo[Module].RxDmaChannel,
      true);

    /* enable dma channel */
    Dma_LL_SetChannelEnabled(
      Lin_Im_DmaUserConfigInfo[Module].RxDmaBasePtr, (Dma_Channel_t)Lin_Im_DmaUserConfigInfo[Module].RxDmaChannel,
      true);

    /* enable uart dma */
    Usart_LL_SetRecvDmaEnabled(Usart_ModulePtr[Module], true);
}

/**
 * @brief Receive interrupt processing
 *
 * @param ModuleId module index
 */
static void Lin_Slave_RxInterruptHandler(uint8 Channel)
{
    /* PRQA S 3223 1 #KQR003223 */
    static uint8        receiveDataOffset = 0U;
    Lin_UsartModuleType hwModuleId;
    Std_ReturnType      result = E_NOT_OK;
    UsartRegMapPtr      usartx;

    hwModuleId = Lin_ChannelConfigPtr[Channel]->HwModule;
    usartx     = kfLin_GetModuleFromIndex(hwModuleId);
    /* PRQA S 2109 1 #KQR002109 */
    if (TRUE == Usart_LL_GetIntrFlag(usartx, USART_INT_GET_BRIF))
    {
        Usart_LL_ClearIntrFlag(usartx, USART_INT_CLEAR_BRIC);
        (void)Usart_LL_GetRxBufferData(usartx);
        LIN_SlaveControlStatus[Channel] = C_LIN_SLAVE_BREAK_RECEIVE_STATUS;
    }
    else
    {
        if (Usart_LL_GetIntrFlag(usartx, USART_INT_GET_RDRIF))
        {
            /* PRQA S 2032 1 #KQR002032 */
            switch (LIN_SlaveControlStatus[Channel])
            {
            case C_LIN_SLAVE_BUS_IDLE_STATUS: {
                (void)Usart_LL_GetRxBufferData(usartx);
                break;
            }
            case C_LIN_SLAVE_BREAK_RECEIVE_STATUS: {
                if (Usart_LL_GetRxBufferData(usartx) == 0x55U)
                {
                    LIN_SlaveControlStatus[Channel] = C_LIN_SLAVE_SYN_RECEIVE_STATUS;
                }
                else
                {
                    /* Do Nothing */
                }
                break;
            }
            case C_LIN_SLAVE_SYN_RECEIVE_STATUS: {
                Lin_ReceivePdu[Channel].Pid = (Lin_FramePidType)Usart_LL_GetRxBufferData(usartx);
                if (Lin_ConfigPtr->HeaderIndicationCallback != NULL_PTR)
                {
                    Lin_ReceivePdu[Channel].SduPtr = Lin_ReceiveTemp[Channel];
                    result = Lin_ConfigPtr->HeaderIndicationCallback(Channel, &Lin_ReceivePdu[Channel]);
                }
                else
                {
                    /* do nothing */
                }
                if (E_OK == result)
                {
                    if (Lin_ReceivePdu[Channel].Drc == LIN_SLAVE_RESPONSE)
                    {
                        if (LIN_DMA_ENABLE == Lin_Im_DmaUserConfigInfo[hwModuleId].TxDmaStatus)
                        {
                            /* Switch to the idle state, send data to prevent the response to receive */
                            LIN_SlaveControlStatus[Channel] = C_LIN_SLAVE_BUS_IDLE_STATUS;
                            Lin_Im_SlaveDmaSendStart(hwModuleId, Channel, &Lin_ReceivePdu[Channel]);
                        }
                        else
                        {
                            (void)Lin_Im_SlaveSendRespond(hwModuleId, &Lin_ReceivePdu[Channel], LIN_TIMEOUT_LOOPS);
                            if (Lin_ConfigPtr->TxConfirmationCallback != NULL_PTR)
                            {
                                Lin_ConfigPtr->TxConfirmationCallback(Channel);
                            }
                            else
                            {
                                /* do nothing */
                            }
                            LIN_SlaveControlStatus[Channel] = C_LIN_SLAVE_BUS_IDLE_STATUS;
                        }
                    }
                    else if(Lin_ReceivePdu[Channel].Drc == LIN_MASTER_RESPONSE)
                    {
                        if (LIN_DMA_ENABLE == Lin_Im_DmaUserConfigInfo[hwModuleId].RxDmaStatus)
                        {
                            Lin_Im_SlaveDmaReceiveStart(hwModuleId, Channel);
                        }
                        else
                        {
                            LIN_SlaveControlStatus[Channel] = C_LIN_SLAVE_RECEIVE_MODE_STATUS;
                        }
                    }
                    else
                    {
                        LIN_SlaveControlStatus[Channel] = C_LIN_SLAVE_BUS_IDLE_STATUS;
                    }
                }
                else
                {
                    LIN_SlaveControlStatus[Channel] = C_LIN_SLAVE_BUS_IDLE_STATUS;
                }
                break;
            }
            case C_LIN_SLAVE_RECEIVE_MODE_STATUS: {
                Lin_ReceivePdu[Channel].SduPtr[receiveDataOffset] = (uint8)Usart_LL_GetRxBufferData(usartx);
                receiveDataOffset++;
                /*****RECEIVE DATA*****/
                if (Lin_ReceivePdu[Channel].Dl == receiveDataOffset)
                {
                    LIN_SlaveControlStatus[Channel] = C_LIN_SLAVE_CHECKSUM_STATUS;
                }
                else
                {
                    /* Do Nothing */
                }
                break;
            }
            case C_LIN_SLAVE_CHECKSUM_STATUS: {
                Lin_ReceivePdu[Channel].SduPtr[receiveDataOffset] = (uint8)Usart_LL_GetRxBufferData(usartx);
                if (Lin_ReceivePdu[Channel].Drc == LIN_MASTER_RESPONSE)
                {
                    if (Lin_ConfigPtr->RxIndicationCallback != NULL_PTR)
                    {
                        Lin_ConfigPtr->RxIndicationCallback(Channel, Lin_ReceivePdu[Channel].SduPtr);
                    }
                    else
                    {
                        /* do nothing */
                    }
                }
                else
                {
                    /* Do Nothing */
                }
                receiveDataOffset               = 0U;
                LIN_SlaveControlStatus[Channel] = C_LIN_SLAVE_BUS_IDLE_STATUS;
                break;
            }
            default:
                (void)0U;
                break;
            }
        }
        else
        {
            /* Do Nothing */
        }
    }
}

#endif
/**
 * @brief interrupt process
 * @implements #SWS_Lin_00155
 */
static FUNC(void, LIN_CODE) Lin_UsartInterruptHandler(uint8 ModuleId)
{
    uint8 i;
    /* PRQA S 2877 1 #KQR002877 */
    for (i = 0U; i < LIN_IM_MODULES; ++i)
    {
        /* PRQA S 1440 1 #KQR001440 */
        if ((Lin_ChannelConfigPtr[i]->HwModule == ModuleId) &&
            (Lin_ChannelConfigPtr[i]->ChannelMode == LIN_CHANNEL_MASTER_MODE))
        {
            Lin_RxInterruptHandler(i);
            Lin_TxInterruptHandler(i);
            break;
        }
        else
        {
            /* do nothing */
        }
    }
}

#if (LIN_SLAVE_MODE_USED == STD_ON)
/**
 * @brief Slave Interrupt processing
 *
 * @param ModuleId USART index
 */
static FUNC(void, LIN_CODE) Lin_Slave_UsartInterruptHandler(uint8 ModuleId)
{
    uint8 i;
    /* PRQA S 2877 1 #KQR002877 */
    for (i = 0U; i < LIN_IM_MODULES; ++i)
    {
        /* PRQA S 1440 2 #KQR001440 */
        if ((Lin_ChannelConfigPtr[i]->HwModule == ModuleId) &&
            (Lin_ChannelConfigPtr[i]->ChannelMode == LIN_CHANNEL_SLAVE_MODE))
        {
            Lin_Slave_RxInterruptHandler(i);
            break;
        }
        else
        {
            /* do nothing */
        }
    }
}

#endif
/* EOF */
