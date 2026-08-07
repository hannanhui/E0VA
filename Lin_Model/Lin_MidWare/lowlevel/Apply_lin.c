/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      C source file                                                            */
/*   Name         :      lin.c                                                                    */
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
 * Copyright (c) 2015-2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
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
 * @file lin.c
 *
 * @page misra_violations MISRA-C:2012 violations
 *
 * @section [global]
 * Violates MISRA 2012 Required Rule 1.3, Taking address of near auto variable.
 * The code is not dynamically linked. An absolute stack address is obtained
 * when taking the address of the near auto variable.
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 8.7, Could be made static.
 * Functions are APIs, so they shall not be made static.
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 11.5, Conversion from pointer to void to pointer to other type .
 * The conversion is needed to restore original type of pointer to lin_state_t. Before callback function,
 * the input pointer is a pointer to lin_state_t.
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 8.13, Pointer parameter 'linState' could be declared as pointing to const
 * This function must be of lin_callback_t type and this type is defined in lin_driver.h, part of LIN Driver
 */

#include "include.h"

/* *****************************************************************************
 * Variables
 ******************************************************************************/
/* Global variables */
/*  lin_tl_descriptor_t */
lin_protocol_state_t g_lin_protocol_state_array[LIN_NUM_OF_IFCS];   /*!< Global array for storing the protocol state for each interface */

/* Static variables */
static lin_state_t s_lin_state_array[LIN_NUM_OF_IFCS];              /*!< Global array for storing the status of all available LIN interfaces */
static volatile uint16_t s_lin_max_header_timeout[LIN_NUM_OF_IFCS];  /*!< Global array for storing the frame header timeout for each interface */
static uint16_t s_lin_max_frame_res_timeout_val[LIN_NUM_OF_IFCS][8]; /*!< Global 2-dimensions array for storing the response timeout for all frame sizes for each interface */
static void CallbackHandler(uint32_t instance,
                            void * linState);
static BOOL s_baudrate_adjusted_flg[LIN_NUM_OF_IFCS];

/* *****************************************************************************
 * Code
 ******************************************************************************/
/*FUNCTION**********************************************************************
 *
 * Function Name : lin_process_parity
 * Description   : Makes or checks parity bits. If action is checking parity, the function
 * returns ID value if parity bits are correct or 0xFF if parity bits are incorrect. If action
 * is making parity bits, then from input value of ID, the function returns PID.
 *
 * Implements    : lin_process_parity_Activity
 *END**************************************************************************/
uint8_t lin_process_parity(uint8_t pid,
                        uint8_t typeAction)
{
    return LIN_DRV_ProcessParity(pid, typeAction);
}



/*FUNCTION**********************************************************************
 *
 * Function Name : lin_lld_init
 * Description   : This function initializes a LIN hardware instance for operation.
 * This function will initialize the run-time state structure to keep track of
 * the on-going transfers, initialize the module to user defined settings and
 * default settings, configure the IRQ state structure and enable the module-level
 * interrupt to the core, and enable the LIN hardware module transmitter and receiver.
 *
 * Implements    : lin_lld_init_Activity
 *END**************************************************************************/
BOOL lin_lld_init(l_ifc_handle iii)
{

    uint32_t lin_hardware_instance;
    uint8_t index;
    status_t retVal = STATUS_ERROR;
    const lin_protocol_user_config_t * prot_user_config_ptr = &g_lin_protocol_user_cfg_array[iii];
    lin_protocol_state_t * prot_state_ptr = &g_lin_protocol_state_array[iii];
    static uint8_t lin_lld_response_buffer[LIN_NUM_OF_IFCS][10];

    prot_state_ptr->response_buffer_ptr = lin_lld_response_buffer[iii];
    /* Get the LIN hardware instance number */
    lin_hardware_instance = g_lin_virtual_ifc[iii];

    /* Initialize time out values */
	
    /* Initialize the LIN hardware interface */
    retVal = LIN_DRV_Init(lin_hardware_instance, prot_user_config_ptr->lin_user_config_ptr, &s_lin_state_array[iii]);

    if (retVal == STATUS_SUCCESS)
    {
        /* Install callback function */
        (void)LIN_DRV_InstallCallback(lin_hardware_instance, CallbackHandler);
		prot_state_ptr->idle_timeout_cnt = g_lin_protocol_user_cfg_array[iii].max_idle_timeout_cnt;
        /* Clear s_baudrate_adjusted_flg[iii] */
        s_baudrate_adjusted_flg[iii] = FALSE;
    }

    return (retVal != STATUS_SUCCESS) ? TRUE : FALSE;
}


void lin_lld_Wakeup(l_ifc_handle iii)
{
	

}


/*FUNCTION**********************************************************************
 *
 * Function Name : lin_lld_deinit
 * Description   : This function shuts down the LIN hardware interface by disabling interrupts and
 *                 transmitter/receiver.
 *
 * Implements    : lin_lld_deinit_Activity
 *END**************************************************************************/
void lin_lld_deinit(l_ifc_handle iii)
{
    

}

/*FUNCTION**********************************************************************
 *
 * Function Name : lin_lld_get_state
 * Description   : This function returns current node's state.
 *
 * Implements    : lin_lld_get_state_Activity
 *END**************************************************************************/
lin_node_state_t lin_lld_get_state(l_ifc_handle iii)
{
   uint32_t lin_hardware_instance;
    lin_node_state_t retVal;

    /* Get the LIN hardware instance number */
    lin_hardware_instance = g_lin_virtual_ifc[iii];

    /* Get current node's state */
    retVal = LIN_DRV_GetCurrentNodeState(lin_hardware_instance);

    return retVal;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : lin_lld_tx_wake_up
 * Description   : This function sends a wakeup signal.
 *
 * Implements    : lin_lld_tx_wake_up_Activity
 *END**************************************************************************/
uint8_t lin_lld_tx_wake_up(l_ifc_handle iii)
{

    status_t retVal = STATUS_ERROR;

  

    return (retVal == STATUS_SUCCESS) ? LIN_LLD_OK : LIN_LLD_ERROR;
}



/*FUNCTION**********************************************************************
 *
 * Function Name : lin_lld_ignore_response
 * Description   : This function terminates an on-going data transmission/reception.
 *
 * Implements    : lin_lld_ignore_response_Activity
 *END**************************************************************************/
uint8_t lin_lld_ignore_response(l_ifc_handle iii)
{
    uint32_t lin_hardware_instance;
    status_t retVal = STATUS_ERROR;

    /* Get the LIN hardware instance number */
    lin_hardware_instance = g_lin_virtual_ifc[iii];

    /* Abort frame data transferring */
    retVal = LIN_DRV_AbortTransferData(lin_hardware_instance);

    return (retVal == STATUS_SUCCESS) ? LIN_LLD_OK : LIN_LLD_ERROR;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : lin_lld_set_low_power_mode
 * Description   : This function puts current node to sleep mode.
 *
 * Implements    : lin_lld_set_low_power_mode_Activity
 *END**************************************************************************/
uint8_t lin_lld_set_low_power_mode(l_ifc_handle iii)
{
    uint32_t lin_hardware_instance;
    status_t retVal = STATUS_ERROR;

    /* Get the LIN hardware instance number */
    lin_hardware_instance = g_lin_virtual_ifc[iii];

    /* Put current node to sleep mode */
    retVal = LIN_DRV_GoToSleepMode(lin_hardware_instance);

    return (retVal == STATUS_SUCCESS) ? LIN_LLD_OK : LIN_LLD_ERROR;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : lin_lld_set_response
 * Description   : This function sends frame data that is contained in g_lin_protocol_state_array[iii].response_buffer_ptr.
 *
 * Implements    : lin_lld_set_response_Activity
 *END**************************************************************************/
uint8_t lin_lld_set_response(l_ifc_handle iii,
                          uint8_t response_length)
{

    uint32_t lin_hardware_instance;
    status_t retVal = STATUS_ERROR;
    const uint8_t * buffer;

    /* Check if response_length is from 1 to 8 */
    if ((response_length <= 8U) && (response_length != 0U))
    {
        buffer = g_lin_protocol_state_array[iii].response_buffer_ptr;
        /* Get the LIN hardware instance number */
        lin_hardware_instance = g_lin_virtual_ifc[iii];

        /* Put response length into buffer */
        g_lin_protocol_state_array[iii].response_length = response_length;

        /* Set correct timeout value */
        //LIN_DRV_SetTimeoutCounter(lin_hardware_instance, s_lin_max_frame_res_timeout_val[iii][response_length - 1U]);

        /* Start sending data from the buffer */
        retVal = LIN_DRV_SendFrameData(lin_hardware_instance, &buffer[0U], response_length);
    }

    return (retVal == STATUS_SUCCESS) ? LIN_LLD_OK : LIN_LLD_ERROR;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : lin_lld_rx_response
 * Description   : This function receives frame data into the buffer g_lin_protocol_state_array[iii].response_buffer_ptr.
 *
 * Implements    : lin_lld_rx_response_Activity
 *END**************************************************************************/
uint8_t lin_lld_rx_response(l_ifc_handle iii,
                         uint8_t response_length)
{

    uint32_t lin_hardware_instance;
    status_t retVal = STATUS_ERROR;

    /* Get the LIN hardware instance number */
    lin_hardware_instance = g_lin_virtual_ifc[iii];

    /* Check if response_length is from 1 to 8 */
    if ((response_length <= 8U) && (response_length != 0U))
    {
        /* Set correct timeout value */
      //  LIN_DRV_SetTimeoutCounter(lin_hardware_instance, s_lin_max_frame_res_timeout_val[iii][response_length - 1U]);

        /* Start receiving frame data into the buffer */
        retVal = LIN_DRV_ReceiveFrameData(lin_hardware_instance, g_lin_protocol_state_array[iii].response_buffer_ptr, response_length);
    }

    return (retVal == STATUS_SUCCESS) ? LIN_LLD_OK : LIN_LLD_ERROR;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : lin_lld_timeout_service
 * Description   : This is a part of Timer Interrupt Handler.
 *
 * Implements    : lin_lld_timeout_service_Activity
 *END**************************************************************************/
void lin_lld_timeout_service(l_ifc_handle iii)
{
	lin_state_t linState = s_lin_state_array[iii];
	lin_protocol_state_t * prot_state_ptr = &g_lin_protocol_state_array[iii];
	switch (linState.currentNodeState)
    {
		case LIN_NODE_STATE_IDLE:
			if (!(prot_state_ptr->idle_timeout_cnt-- > 0U))
            {
                /* Callback to handle timeout */
                CALLBACK_HANDLER(iii, LIN_LLD_BUS_ACTIVITY_TIMEOUT, 0xFFU);

                /* Put current node to Idle state, reset idle timeout count */
                prot_state_ptr->idle_timeout_cnt = g_lin_protocol_user_cfg_array[iii].max_idle_timeout_cnt;
                if(0u == PowerApp_SystemNoSleepEnGet())
                {
					/* Put current node to sleep mode */
					(void)LIN_DRV_GoToSleepMode(0);
                }
            }
			break;
		default:
            /* do nothing */
            break;
	}
}

/*FUNCTION**********************************************************************
 *
 * Function Name : CallbackHandler
 * Description   : This is the callback function for LIN Driver.
 *
 * Implements    : CallbackHandler_Activity
 *END**************************************************************************/
static void CallbackHandler(uint32_t instance,
                            void * linState)
{
    const lin_state_t * linCurrentState = linState;
    lin_lld_event_id_t event_id;
    uint8_t id = linCurrentState->currentId;
    uint8_t bytesRemaining = 0U;
    l_ifc_handle iii = g_lin_hardware_ifc[instance];
    const lin_protocol_user_config_t * prot_user_config_ptr = &g_lin_protocol_user_cfg_array[iii];
    lin_protocol_state_t * prot_state_ptr = &g_lin_protocol_state_array[iii];

    switch (linCurrentState->currentEventId)
    {
        case LIN_PID_OK:
            event_id = LIN_LLD_PID_OK;
            CALLBACK_HANDLER(iii, (event_id), (id));
            break;
        case LIN_PID_ERROR:
            event_id = LIN_LLD_PID_ERR;
            CALLBACK_HANDLER(iii, (event_id), (id));
            break;
        case LIN_TX_COMPLETED:
            event_id = LIN_LLD_TX_COMPLETED;
            CALLBACK_HANDLER(iii, (event_id), (id));
            break;
        case LIN_RX_COMPLETED:
            event_id = LIN_LLD_RX_COMPLETED;
            CALLBACK_HANDLER(iii, (event_id), (id));
            break;
        case LIN_CHECKSUM_ERROR:
            event_id = LIN_LLD_CHECKSUM_ERR;
            CALLBACK_HANDLER(iii, (event_id), (id));
            break;
        case LIN_READBACK_ERROR:
            event_id = LIN_LLD_READBACK_ERR;
            CALLBACK_HANDLER(iii, (event_id), (id));
            break;
        case LIN_FRAME_ERROR:
            event_id = LIN_LLD_FRAME_ERR;
            CALLBACK_HANDLER(iii, (event_id), (id));
            break;
		case LIN_TX_BIT_ERR:
			event_id = LIN_LLD_TX_BIT_ERR;
            CALLBACK_HANDLER(iii, (event_id), (id));
			break;
        case LIN_RECV_BREAK_FIELD_OK:
           
            break;
		case LIN_RX_OVERRUN:
			event_id = LIN_LLD_RX_OVERFLOW;
            CALLBACK_HANDLER(iii, (event_id), (id));
			break;
        case LIN_SYNC_ERROR:
			
			event_id = LIN_LLD_SYNC_ERR;
            CALLBACK_HANDLER(iii, (event_id), (id));
            break;
		case LIN_TX_TIMEOUT_ERROR:
			event_id = LIN_LLD_TX_TIMEOUT;
            CALLBACK_HANDLER(iii, (event_id), (id));
			break;
		case LIN_RX_TIMEOUT_ERROR:
			event_id = LIN_LLD_RX_TIMEOUT;
	        CALLBACK_HANDLER(iii, (event_id), (id));
		break;
        case LIN_BAUDRATE_ADJUSTED:
            /* Set s_baudrate_adjusted_flg[iii] */
            s_baudrate_adjusted_flg[iii] = TRUE;
            break;
        case LIN_NO_EVENT:
            
            break;
        default:
            /* do nothing */
            break;
    }

    prot_state_ptr->idle_timeout_cnt = prot_user_config_ptr->max_idle_timeout_cnt;
    /*
    * @violates MISRA 2012 Advisory Rule 8.13 Advisory
    */
}


/* *****************************************************************************
 * EOF
 ******************************************************************************/
