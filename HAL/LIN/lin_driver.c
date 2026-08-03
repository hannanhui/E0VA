/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      C source file                                                            */
/*   Name         :      lin_driver.c                                                             */
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
 * @file lin_driver.c
 *
 * @page misra_violations MISRA-C:2012 violations
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 8.7, External could be made static.
 * The function is defined for use by application code.
 */

/* *****************************************************************************
 * Includes
 ******************************************************************************/


#include "lin_driver.h"
#include "model_Cfg_feature.h"
#if (LPUART_INSTANCE_COUNT > 0U)
    #include "..\Uart\lin_lpuart_driver.h"
#endif
#define UART_INSTANCE_NUM 3
#define UART_INTSTA_IID_RBFI          0x04U
#define UART_INTSTA_IID_LSI           0x06U
#define UART_INTSTA_IID_BYDET         0x07U


#define UART_LSI_OE       (1U << 1U)
#define UART_LSI_PE       (1U << 2U)
#define UART_LSI_FE       (1U << 3U)
#define UART_LSI_BI       (1U << 4U)
#define UART_LSI_RFE      (1U << 7U)
static uart_reg_t * const uartRegPtr[UART_INSTANCE_NUM] = 
{
    (uart_reg_t *)UART0_BASE_ADDR,
    (uart_reg_t *)UART1_BASE_ADDR,
    (uart_reg_t *)UART2_BASE_ADDR,
#if (4U == UART_INSTANCE_NUM ) 
    (uart_reg_t *)UART3_BASE_ADDR,
#endif
};
static uart_reg_w_t * const uartRegWPtr[UART_INSTANCE_NUM] = 
{
    (uart_reg_w_t *)UART0_BASE_ADDR,
    (uart_reg_w_t *)UART1_BASE_ADDR,
    (uart_reg_w_t *)UART2_BASE_ADDR,
#if (4U == UART_INSTANCE_NUM ) 
    (uart_reg_w_t *)UART3_BASE_ADDR,
#endif
};
/* *****************************************************************************
 * Code
 ******************************************************************************/
/*FUNCTION**********************************************************************
 *
 * Function Name : LIN_DRV_Init
 * Description   : This function initializes a LIN Hardware Interface for operation.
 * This function will initialize the run-time state structure to keep track of
 * the on-going transfers, ungate the clock to LIN Hardware Interface, initialize the
 * module to user defined settings and default settings, configure the IRQ state
 * structure and enable the module-level interrupt to the core, and enable the
 * LIN Hardware Interface transmitter and receiver.
 * The following is an example of how to set up the lin_state_t and the
 * lin_user_config_t parameters and how to call the LIN_DRV_Init function
 * by passing in these parameters:
 *    lin_user_config_t linUserConfig
 *    linUserConfig.baudRate = 9600
 *    linUserConfig.nodeFunction = SLAVE
 *    linUserConfig.autobaudEnable = true
 *    linUserConfig.timerGetTimeIntervalCallback = (lin_timer_get_time_interval_t) l_ifc_timerGetTimeIntervalCallbackHandler
 *    lin_state_t linState
 *    LIN_DRV_Init(instance, (lin_user_config_t *) &linUserConfig, (lin_state_t *) &linState)
 *
 * Implements    : LIN_DRV_Init_Activity
 *END**************************************************************************/
status_t LIN_DRV_Init(uint32_t instance,
                      lin_user_config_t * linUserConfig,
                      lin_state_t * linCurrentState)
{
    status_t retVal = STATUS_UNSUPPORTED;

#if (LPUART_INSTANCE_COUNT > 0U)
    retVal = LIN_LPUART_DRV_Init(instance, linUserConfig, linCurrentState);
#endif

    return retVal;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : LIN_DRV_Deinit
 * Description   : This function shuts down the LIN Hardware Interface by disabling interrupts and
 *                 transmitter/receiver.
 *
 * Implements    : LIN_DRV_Deinit_Activity
 *END**************************************************************************/
void LIN_DRV_Deinit(uint32_t instance)
{
#if (LPUART_INSTANCE_COUNT > 0U)
    LIN_LPUART_DRV_Deinit(instance);
#endif
}

/*FUNCTION**********************************************************************
 *
 * Function Name : LIN_DRV_InstallCallback
 * Description   : This function installs the callback function that is used for LIN_DRV_IRQHandler.
 * Pass in Null pointer as callback will uninstall.
 *
 * Implements    : LIN_DRV_InstallCallback_Activity
 *END**************************************************************************/
lin_callback_t LIN_DRV_InstallCallback(uint32_t instance,
                                       lin_callback_t function)
{
    lin_callback_t retVal = NULL;

#if (LPUART_INSTANCE_COUNT > 0U)
    retVal = LIN_LPUART_DRV_InstallCallback(instance, function);
#endif

    return retVal;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : LIN_DRV_SendFrameData
 * Description   : This function sends data out through the LIN Hardware Interface using
 * non-blocking method. This function will calculate the checksum byte and send it with the
 * frame data. The function will return immediately after calling this function. If txSize
 * is equal to 0 or greater than 8 then the function will return STATUS_ERROR. If isBusBusy is
 * currently true then the function will return STATUS_BUSY.
 *
 * Implements    : LIN_DRV_SendFrameData_Activity
 *END**************************************************************************/
status_t LIN_DRV_SendFrameData(uint32_t instance,
                               const uint8_t * txBuff,
                               uint8_t txSize)
{
    status_t retVal = STATUS_UNSUPPORTED;

#if (LPUART_INSTANCE_COUNT > 0U)
    retVal = LIN_LPUART_DRV_SendFrameData(instance, txBuff, txSize);
#endif

    return retVal;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : LIN_DRV_GetTransmitStatus
 * Description   : This function returns whether the previous transmission has
 * finished. When performing non-blocking transmit, the user can call this
 * function to ascertain the state of the current transmission:
 * in progress (or busy that STATUS_BUSY) or timeout (STATUS_TIMEOUT) or complete (success that is STATUS_SUCCESS).
 * In addition, if the transmission is still in progress, the user can obtain the number
 * of bytes that still needed to transmit.
 *
 * Implements    : LIN_DRV_GetTransmitStatus_Activity
 *END**************************************************************************/
status_t LIN_DRV_GetTransmitStatus(uint32_t instance,
                                   uint8_t * bytesRemaining)
{
    status_t retVal = STATUS_UNSUPPORTED;

#if (LPUART_INSTANCE_COUNT > 0U)
    retVal = LIN_LPUART_DRV_GetTransmitStatus(instance, bytesRemaining);
#endif

    return retVal;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : LIN_DRV_ReceiveFrameData
 * Description   : This function receives data from LIN Hardware Interface using
 * non-blocking method. This function will check the checksum byte. If the checksum is
 * correct, it will receive it with the frame data.
 * Non-blocking  means that the function returns immediately.
 * The application has to get the receive status to know when the reception is complete.
 * The interrupt handler LIN_LPUART_DRV_IRQHandler will check the checksum byte. If the
 * checksum is correct, it will receive the frame data. If the checksum is incorrect, this
 * function will return STATUS_TIMEOUT and data in rxBuff might be wrong. This function also
 * check if rxSize is in range from 1 to 8. If not, it will return STATUS_ERROR. This function
 * also checks if the isBusBusy is false, if not it will return STATUS_BUSY.
 *
 * Implements    : LIN_DRV_ReceiveFrameData_Activity
 *END**************************************************************************/
status_t LIN_DRV_ReceiveFrameData(uint32_t instance,
                                  uint8_t * rxBuff,
                                  uint8_t rxSize)  
{
    status_t retVal = STATUS_UNSUPPORTED;

#if (LPUART_INSTANCE_COUNT > 0U)
    retVal = LIN_LPUART_DRV_RecvFrmData(instance, rxBuff, rxSize);
#endif

    return retVal;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : LIN_DRV_AbortTransferData
 * Description   : Aborts an on-going non-blocking transmission/reception.
 * While performing a non-blocking transferring data, users can call this
 * function to terminate immediately the transferring.
 *
 * Implements    : LIN_DRV_AbortTransferData_Activity
 *END**************************************************************************/
status_t LIN_DRV_AbortTransferData(uint32_t instance)
{
    status_t retVal = STATUS_UNSUPPORTED;

#if (LPUART_INSTANCE_COUNT > 0U)
    retVal = LIN_LPUART_DRV_AbortTransferData(instance);
#endif

    return retVal;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : LIN_DRV_GetReceiveStatus
 * Description   : This function returns whether the data reception is complete.
 * When performing non-blocking transmit, the user can call this function to
 * ascertain the state of the current receive progress:
 * in progress (STATUS_BUSY) or timeout (STATUS_TIMEOUT) or complete (STATUS_SUCCESS).
 * In addition, if the reception is still in progress, the user can obtain the
 * number of bytes that still needed to receive.
 *
 * Implements    : LIN_DRV_GetReceiveStatus_Activity
 *END**************************************************************************/
status_t LIN_DRV_GetReceiveStatus(uint32_t instance,
                                  uint8_t * bytesRemaining)
{
    status_t retVal = STATUS_UNSUPPORTED;

#if (LPUART_INSTANCE_COUNT > 0U)
    retVal = LIN_LPUART_DRV_GetReceiveStatus(instance, bytesRemaining);
#endif

    return retVal;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : LIN_DRV_GoToSleepMode
 * Description   : This function puts current LIN node to sleep mode.
 * This function changes current node state to LIN_NODE_STATE_SLEEP_MODE.
 *
 * Implements    : LIN_DRV_GoToSleepMode_Activity
 *END**************************************************************************/
status_t LIN_DRV_GoToSleepMode(uint32_t instance)
{
    status_t retVal = STATUS_UNSUPPORTED;

#if (LPUART_INSTANCE_COUNT > 0U)
    retVal = LIN_LPUART_DRV_GoToSleepMode(instance);
#endif

    return retVal;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : LIN_DRV_GotoIdleState
 * Description   : This function puts current node to Idle state.
 *
 * Implements    : LIN_DRV_GoToIdleState_Activity
 *END**************************************************************************/
status_t LIN_DRV_GotoIdleState(uint32_t instance)
{
    status_t retVal = STATUS_UNSUPPORTED;

#if (LPUART_INSTANCE_COUNT > 0U)
    retVal = LIN_LPUART_DRV_GotoIdleState(instance);
#endif

    return retVal;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : LIN_DRV_SendWakeupSignal
 * Description   : This function sends a wakeup signal through the LPUART interface.
 *
 * Implements    : LIN_DRV_SendWakeupSignal_Activity
 *END**************************************************************************/
status_t LIN_DRV_SendWakeupSignal(uint32_t instance)
{
    status_t retVal = STATUS_UNSUPPORTED;

#if (LPUART_INSTANCE_COUNT > 0U)
    retVal = LIN_LPUART_DRV_SendWakeupSignal(instance);
#endif

    return retVal;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : LIN_DRV_GetCurrentNodeState
 * Description   : This function gets the current LIN node state.
 *
 * Implements    : LIN_DRV_GetCurrentNodeState_Activity
 *END**************************************************************************/
lin_node_state_t LIN_DRV_GetCurrentNodeState(uint32_t instance)
{
    lin_node_state_t retVal = LIN_NODE_STATE_UNINIT;

#if (LPUART_INSTANCE_COUNT > 0U)
    retVal = LIN_LPUART_DRV_GetCurrentNodeState(instance);
#endif

    return retVal;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : LIN_DRV_TimeoutService
 * Description   : This is callback function for Timer Interrupt Handler.
 * Users shall initialize a timer (for example FTM) in Output compare mode
 * with period of 500 micro seconds. In timer IRQ handler, call this function.
 *
 * Implements    : LIN_DRV_TimeoutService_Activity
 *END**************************************************************************/
void LIN_DRV_TimeoutService(uint32_t instance)
{
#if (LPUART_INSTANCE_COUNT > 0U)
    LIN_LPUART_DRV_TimeoutService(instance);
#endif
}

/*FUNCTION**********************************************************************
 *
 * Function Name : LIN_DRV_SetTimeoutCounter
 * Description   : This function sets value for timeout counter that is used in
 * LIN_DRV_TimeoutService
 *
 * Implements    : LIN_DRV_SetTimeoutCounter_Activity
 *END**************************************************************************/
void LIN_DRV_SetTimeoutCounter(uint32_t instance,
                               uint32_t timeoutValue)
{
#if (LPUART_INSTANCE_COUNT > 0U)
    LIN_LPUART_DRV_SetTimeoutCounter(instance, timeoutValue);
#endif
}

/*FUNCTION**********************************************************************
 *
 * Function Name : LIN_DRV_EnableIRQ
 * Description   : This function enables LIN hardware interrupts.
 *
 * Implements    : LIN_DRV_EnableIRQ_Activity
 *END**************************************************************************/
status_t LIN_DRV_EnableIRQ(uint32_t instance)
{
    status_t retVal = STATUS_UNSUPPORTED;

#if (LPUART_INSTANCE_COUNT > 0U)
    retVal = LIN_LPUART_DRV_EnableIRQ(instance);
#endif

    return retVal;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : LIN_DRV_DisableIRQ
 * Description   : This function disables LIN hardware interrupts.
 *
 * Implements    : LIN_DRV_DisableIRQ_Activity
 *END**************************************************************************/
status_t LIN_DRV_DisableIRQ(uint32_t instance)
{
    status_t retVal = STATUS_UNSUPPORTED;

#if (LPUART_INSTANCE_COUNT > 0U)
    retVal = LIN_LPUART_DRV_DisableIRQ(instance);
#endif

    return retVal;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : LIN_DRV_IRQHandler
 * Description   : Interrupt handler for LIN Hardware Interface.
 * This is not a public API as it is called by IRQ whenever an interrupt
 * occurs.
 *
 * Implements    : LIN_DRV_IRQHandler_Activity
 *END**************************************************************************/
void LIN_DRV_RX_IRQHandler(uint32_t instance)
{
#if (LPUART_INSTANCE_COUNT > 0U)
    LIN_LPUART_DRV_RX_IRQHandler(instance);
#endif
}






 /*FUNCTION**********************************************************************
  *
  * Function Name : LIN_DRV_IRQHandler
  * Description   : Interrupt handler for LIN Hardware Interface.
  * This is not a public API as it is called by IRQ whenever an interrupt
  * occurs.
  *
  * Implements	  : LIN_DRV_IRQHandler_Activity
  *END**************************************************************************/
 void LIN_DRV_TX_IRQHandler(uint32_t instance)
 {
#if (LPUART_INSTANCE_COUNT > 0U)
	 LIN_LPUART_DRV_TX_IRQHandler(instance);
#endif
 }

void LIN_DRV_Break_IRQHandler(uint32_t instance)
{

    LIN_LPUART_DRV_BREAK_IRQHandler(instance);

}


void LIN_LPUART_Rx_IRQHandler(void)
{
    LIN_DRV_RX_IRQHandler(0U);
}
void LIN_LPUART_Tx_IRQHandler(void)
{
    LIN_DRV_TX_IRQHandler(0U);
}

void LIN_LPUART_Break_IRQHandler(void)
{
	LIN_DRV_Break_IRQHandler(0U);
}


void LIN_LPUART_Total_IRQHandler(uint32_t instance)
{
	/* Get the current LIN state of this LPUART instance. */
    lin_state_t * linCurrentState = g_linStatePtr[instance];
    uint32_t LinBusStatus = 0;    
    uint32_t tmpByte,dummyData,intId;
    
    uart_reg_t * UARTx = (uart_reg_t *)(uartRegPtr[LIN_ID]);
    uart_reg_w_t * UARTxw = (uart_reg_w_t *)(uartRegWPtr[LIN_ID]);
    uint8_t ErrFlag=0;
    intId = UARTx->UART_IIR_FCR.UART_IIR.IID;
    LinBusStatus = UARTxw->UART_LSR;
	switch(intId)
    {
        case UART_INTSTA_IID_LSI:
            /*Line status interrupt*/
            if(UART_LSI_BI & LinBusStatus)
            {
                /* detected the Break Interrupt */
                LIN_DRV_Break_IRQHandler(instance);
            }
            else if(UART_LSI_FE & LinBusStatus)
            {
                /* frame error occur */
                /* Read dummy to clear LPUART_RX_DATA_REG_FULL flag */
                UART_EmptyRxFifo(LIN_ID);
								/* Check if LIN current node state is LIN_NODE_STATE_RECV_DATA */
								if (linCurrentState->currentNodeState == LIN_NODE_STATE_RECV_DATA)
								{						
										/* Set current event id to LIN_FRAME_ERROR */
										linCurrentState->currentEventId = LIN_FRAME_ERROR;
										/* Callback function to handle Framing Error Event */
										if (linCurrentState->Callback != NULL)
										{
											linCurrentState->Callback(instance, linCurrentState);
										}
									ErrFlag =1u;
									
								}
								else if (linCurrentState->currentNodeState == LIN_NODE_STATE_SEND_DATA)
								{

									/* Set current event id to LIN_FRAME_ERROR */
									linCurrentState->currentEventId = LIN_FRAME_ERROR;
									/* Callback function to handle Framing Error Event */
									if (linCurrentState->Callback != NULL)
									{
										linCurrentState->Callback(instance, linCurrentState);
									}
									ErrFlag =1u;
								}
								else if (linCurrentState->currentNodeState == LIN_NODE_STATE_RECV_SYNC)
								{

									/* Set current event id to LIN_FRAME_ERROR */
									linCurrentState->currentEventId = LIN_SYNC_ERROR;
									/* Callback function to handle Framing Error Event */
									if (linCurrentState->Callback != NULL)
									{
										linCurrentState->Callback(instance, linCurrentState);
									}
								
									ErrFlag =1u;

								}
								else if (linCurrentState->currentNodeState == LIN_NODE_STATE_RECV_PID)
								{
									linCurrentState->currentEventId = LIN_PID_ERROR;

									/* Callback function to handle event PID incorrect */
									if (linCurrentState->Callback != NULL)
									{
											linCurrentState->Callback(instance, linCurrentState);
									}
									ErrFlag =1u;

								}
								if(1u == ErrFlag)
								{
													/* Change node's state to IDLE */
													(void)LIN_DRV_GotoIdleState(instance); 
								}
					  } 
						else if(UART_LSI_OE & LinBusStatus)
						{
								UART_EmptyRxFifo((UART_ID_t)instance);
								if(linCurrentState->currentNodeState >= LIN_NODE_STATE_RECV_SYNC)
								{
											linCurrentState->currentEventId = LIN_RX_OVERRUN;

											if(linCurrentState->Callback != NULL)
											{
													linCurrentState->Callback(instance, linCurrentState);
											}
								}
								/* Change node's state to IDLE */
								(void)LIN_DRV_GotoIdleState(instance); 
						}
						LinBusStatus = 0;
        break;
        
        case UART_INTSTA_IID_RBFI:
				if(linCurrentState->currentNodeState >= LIN_NODE_STATE_RECV_SYNC)
				{
							LIN_LPUART_Rx_IRQHandler();
				}
				else
				{
					/* IDLE/SLEEP: drain bytes that arrive after GotoIdle flush.
					 * Only BreakDetect must NOT EmptyRxFifo (SYNC may already be queued). */
					UART_EmptyRxFifo(LIN_ID);
				}
        break;
        
        case UART_INTSTA_IID_BYDET:
            /* Clear it by reading the UART status register */
            dummyData = UARTxw->UART_USR;
        break;
        default:
            break;
    }
	

	
}



/* *****************************************************************************
 * EOF
 ******************************************************************************/
