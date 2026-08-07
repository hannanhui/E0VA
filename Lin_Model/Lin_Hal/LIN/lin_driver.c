/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      C source file                                                            */
/*   Name         :      lin_driver.c                                                             */
/*   Instance     :                                                                               */
/*   Author       :      Ed                                                                       */
/*   Modify date  :      2025-04-11 11:08:33 AM                                                   */
/*   Description  :                                                                               */
/*                                                                                                */
/*                                                                                                */
/*   Compiler    :       KungFu32 IDE  [Version: V1.0.20.3]                                       */
/*   Hardware    :       ChipOn microcontroller KF32A Family [KF32A136KQT]                        */
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
#include "LinIf.h"


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


    retVal = LIN_LPUART_DRV_Init(instance, linUserConfig, linCurrentState);


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


    retVal = LIN_LPUART_DRV_InstallCallback(instance, function);

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


    retVal = LIN_LPUART_DRV_SendFrameData(instance, txBuff, txSize);


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

    retVal = LIN_LPUART_DRV_RecvFrmData(instance, rxBuff, rxSize);

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

    retVal = LIN_LPUART_DRV_AbortTransferData(instance);

    return retVal;
}

lin_node_state_t LIN_DRV_GetCurrentNodeState(uint32_t instance)
{
    lin_node_state_t retVal = LIN_NODE_STATE_UNINIT;


    retVal = LIN_LPUART_DRV_GetCurrentNodeState(instance);

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
	retVal = LIN_LPUART_DRV_GoToSleepMode(instance);

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


    return retVal;
}





/* *****************************************************************************
 * EOF
 ******************************************************************************/
