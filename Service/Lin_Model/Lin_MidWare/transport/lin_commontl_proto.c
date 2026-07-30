/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      C source file                                                            */
/*   Name         :      lin_commontl_proto.c                                                     */
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
 * @file lin_commontl_proto.c
 *
 * @page misra_violations MISRA-C:2012 violations
 *
 * @section [global]
 * Violates MISRA 2012 Required Rule 1.3,  Taking address of near auto variable.
 * The code is not dynamically linked. An absolute stack address is obtained
 * when taking the address of the near auto variable.
 */
#include "include.h"
#include "Linif.h"
#include "LinIf_Cbk.h"
#include "LinIf_Cfg.h"
S_commontl_callback_t * g_commontl_callbackPtr[1] = {NULL};
static S_commontl_callback_t s_commontl_callback_array[1]; 


/* *****************************************************************************
 * Static function prototypes
 ******************************************************************************/
/*static void lin_tl_handler_error(l_ifc_handle iii,
                                 uint8_t pid);*/

static lin_tl_callback_return_t lin_tl_get_pdu(l_ifc_handle iii,uint8_t id);

static void lin_tl_handler_rx_completed(l_ifc_handle iii,uint8_t id);

static void lin_tl_handler_tx_completed(l_ifc_handle iii,uint8_t id);











/* *****************************************************************************
 * Variables
 ******************************************************************************/
/* *****************************************************************************
 * Code
 ******************************************************************************/

/*FUNCTION**********************************************************************
 *
 * Function Name : lin_tl_callback_handler
 * Description   : Transport layer callback to process the specified event
 *
 * Implements    : lin_tl_callback_handler_Activity
 *END**************************************************************************/
lin_tl_callback_return_t lin_tl_callback_handler(l_ifc_handle iii,
                                                 lin_tl_event_id_t tl_event_id,
                                                 uint8_t id)
{
    lin_tl_callback_return_t ret_val = TL_ACTION_NONE;

    switch (tl_event_id)
    {
        case TL_RECEIVE_MESSAGE:
           
            break;
        case TL_MAKE_RES_DATA:
            
            break;
        case TL_SLAVE_GET_ACTION:

			ret_val = lin_tl_get_pdu(iii,id);
        
            break;
        case TL_TX_COMPLETED:

			lin_tl_handler_tx_completed(iii,id);
			
            
            break;
        case TL_RX_COMPLETED:
			
			lin_tl_handler_rx_completed(iii,id);

			
            
            break;
        case TL_ERROR:
            //lin_tl_handler_error(iii, id);
            break;
        #if (SUPPORT_PROTOCOL_21 == 1U)
        case TL_TIMEOUT_SERVICE:
          
            break;
        #endif /* if (SUPPORT_PROTOCOL_21 == 1U) */

        default:
            /* Do nothing */
            break;
    }

    return ret_val;
}
#if 0
/*FUNCTION**********************************************************************
 *
 * Function Name : lin_tl_handler_error
 * Description   : This function handles the diagnostic service and control error in TL
 * This function is implemented for Slave and Master.
 *
 * Implements    : lin_tl_handler_error_Activity
 *END**************************************************************************/
static void lin_tl_handler_error(l_ifc_handle iii,
                                 uint8_t pid)
{
   
}
#endif
/*FUNCTION**********************************************************************
 *
 * Function Name : LIN_LPUART_DRV_InstallCallback
 * Description   : This function installs the callback function that is used for LIN_LPUART_DRV_IRQHandler.
 * Pass in Null pointer as callback will uninstall.
 *
 * Implements    : LIN_LPUART_DRV_InstallCallback_Activity
 *END**************************************************************************/
commontl_callback_Param_t lin_tl_ApplyIdInstallCallback(Lin_commontl_proto_callback_type_t opIndex,commontl_callback_Param_t function)
{
	S_commontl_callback_t * commontl_callback_Ptr = g_commontl_callbackPtr[0];
	commontl_callback_Param_t currentCallback;

		switch(opIndex)
		{
			case Commontl_proto_Callback_App_Tx_Data_assignment:
				/* Get the current callback function. */
				currentCallback= commontl_callback_Ptr->App_Tx_Data_assignmentCallback;
				/* Install new callback function. */
				commontl_callback_Ptr->App_Tx_Data_assignmentCallback = function;
			break;
			case Commontl_proto_Callback_App_Tx_Complete:
				/* Get the current callback function. */
				currentCallback= commontl_callback_Ptr->App_Tx_CompleteCallback;
				/* Install new callback function. */
				commontl_callback_Ptr->App_Tx_CompleteCallback = function;
			
			break;
			case Commontl_proto_Callback_App_Rx_Complete:
				/* Get the current callback function. */
				currentCallback= commontl_callback_Ptr->App_Rx_CompleteCallback;
				/* Install new callback function. */
				commontl_callback_Ptr->App_Rx_CompleteCallback = function;
			
			break;
			default:
			
			break;
		}
		return currentCallback;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : LIN_LPUART_DRV_InstallCallback
 * Description   : This function installs the callback function that is used for LIN_LPUART_DRV_IRQHandler.
 * Pass in Null pointer as callback will uninstall.
 *
 * Implements    : LIN_LPUART_DRV_InstallCallback_Activity
 *END**************************************************************************/
commontl_callback_t lin_tl_InstallCallback(Lin_commontl_proto_callback_type_t opIndex,commontl_callback_t function)
{
	S_commontl_callback_t * commontl_callback_Ptr = g_commontl_callbackPtr[0];

    
    commontl_callback_t currentCallback;

		switch(opIndex)
		{
			case Commontl_proto_Callback_Diag_Tx_Data_assignment:
				/* Get the current callback function. */
				currentCallback= commontl_callback_Ptr->Diag_Tx_Data_assignmentCallback;
				/* Install new callback function. */
				commontl_callback_Ptr->Diag_Tx_Data_assignmentCallback = function;
			break;
			case Commontl_proto_Callback_Diag_Tx_Complete:
				/* Get the current callback function. */
				currentCallback= commontl_callback_Ptr->Diag_Tx_CompleteCallback;
				/* Install new callback function. */
				commontl_callback_Ptr->Diag_Tx_CompleteCallback = function;
			
			break;
			case Commontl_proto_Callback_Diag_Rx_Complete:
				/* Get the current callback function. */
				currentCallback= commontl_callback_Ptr->Diag_Rx_CompleteCallback;
				/* Install new callback function. */
				commontl_callback_Ptr->Diag_Rx_CompleteCallback = function;
			
			break;
			case Commontl_proto_Callback_Proprietary_Tx_Data_assignment:
				/* Get the current callback function. */
				currentCallback= commontl_callback_Ptr->Proprietary_Tx_Data_assignmentCallback;
				/* Install new callback function. */
				commontl_callback_Ptr->Proprietary_Tx_Data_assignmentCallback = function;
			break;
			case Commontl_proto_Callback_Proprietary_Tx_Complete:
				/* Get the current callback function. */
				currentCallback= commontl_callback_Ptr->Proprietary_Tx_CompleteCallback;
				/* Install new callback function. */
				commontl_callback_Ptr->Proprietary_Tx_CompleteCallback = function;
			
			break;
			case Commontl_proto_Callback_Proprietary_Rx_Complete:
				/* Get the current callback function. */
				currentCallback= commontl_callback_Ptr->Proprietary_Rx_CompleteCallback;
				/* Install new callback function. */
				commontl_callback_Ptr->Proprietary_Rx_CompleteCallback = function;
			
			break;
			default:
			
			break;
		}

    

    return currentCallback;
}

void lin_tl_init(l_ifc_handle iii)
{
	g_commontl_callbackPtr[0] = &s_commontl_callback_array[0];
}


/*FUNCTION**********************************************************************
 *
 * Function Name : lin_tl_get_pdu
 * Description   : This function copies the current PDU to Response Buffer in Low-level
 * This function is implemented for Slave and Master.
 *
 * Implements    : lin_tl_get_pdu_Activity
 *END**************************************************************************/
static lin_tl_callback_return_t lin_tl_get_pdu(l_ifc_handle iii,uint8_t id)
{
    S_commontl_callback_t * commontl_callback_Ptr = g_commontl_callbackPtr[0];
	uint8_t i;
	lin_tl_callback_return_t ret_val = TL_ACTION_NONE;
	if(0x3D == id)
	{
		if (commontl_callback_Ptr->Diag_Tx_Data_assignmentCallback != NULL)
	    {
	        commontl_callback_Ptr->Diag_Tx_Data_assignmentCallback();
	    }
		if(g_lin_Diag_Tx_data_Len>0)
		{
		for(i=0;i<LIN_DIAG_TX_BUF_SIZE;i++)
		{
			g_lin_protocol_state_array[iii].response_buffer_ptr[i] = g_lin_Diag_Tx_data_buffer[i];
			}
		}
		else
		{
			ret_val = TL_ACTION_ID_IGNORE;
		}
	}
	else if(0x3F == id)
	{
		if (commontl_callback_Ptr->Proprietary_Tx_Data_assignmentCallback != NULL)
	    {
	        commontl_callback_Ptr->Proprietary_Tx_Data_assignmentCallback();
	    }
		for(i=0;i<LIN_PROPRIETARY_TX_BUF_SIZE;i++)
		{
			g_lin_protocol_state_array[iii].response_buffer_ptr[i] = g_lin_Proprietary_Tx_data_buffer[i];
		}
	}
	else
	{
		if (commontl_callback_Ptr->App_Tx_Data_assignmentCallback != NULL)
	    {
	        commontl_callback_Ptr->App_Tx_Data_assignmentCallback(id);
	    }
	}
	return ret_val;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : lin_tl_handler_rx_completed
 * Description   : This function handles the diag service and control event and data in TL
 * This function is implemented for Slave and Master.
 *
 * Implements    : lin_tl_handler_rx_completed_Activity
 *END**************************************************************************/
static void lin_tl_handler_rx_completed(l_ifc_handle iii,uint8_t id)
{
	S_commontl_callback_t * commontl_callback_Ptr = g_commontl_callbackPtr[0];
	uint8_t i;
	if(0x3C == id)
	{
	
		for(i=0;i<LIN_DIAG_TX_BUF_SIZE;i++)
		{
			g_lin_Diag_Rx_data_buffer[i] = g_lin_protocol_state_array[iii].response_buffer_ptr[i];
		}
		if (commontl_callback_Ptr->Diag_Rx_CompleteCallback != NULL)
	    {
	    }
	}
	else if(0x3E == id)
	{
		
		for(i=0;i<LIN_PROPRIETARY_TX_BUF_SIZE;i++)
		{
			g_lin_Proprietary_Rx_data_buffer[i] = g_lin_protocol_state_array[iii].response_buffer_ptr[i];
		}
		if (commontl_callback_Ptr->Proprietary_Rx_CompleteCallback != NULL)
	    {
	        commontl_callback_Ptr->Proprietary_Rx_CompleteCallback();
	    }
		
	}
	else
	{
		if (commontl_callback_Ptr->App_Rx_CompleteCallback != NULL)
	    {
	        commontl_callback_Ptr->App_Rx_CompleteCallback(id);
	    }
	}
	
}

/*FUNCTION**********************************************************************
 *
 * Function Name : lin_tl_handler_tx_completed
 * Description   : This function process when interface send diagnostic frame successfully
 *
 * Implements    : lin_tl_handler_tx_completed_Activity
 *END**************************************************************************/
static void lin_tl_handler_tx_completed(l_ifc_handle iii,uint8_t id)
{
	S_commontl_callback_t * commontl_callback_Ptr = g_commontl_callbackPtr[0];

	if(0x3D == id)
	{
		if (commontl_callback_Ptr->Diag_Tx_CompleteCallback != NULL)
	    {
	    }
		
	}
	else if(0x3F == id)
	{
		if (commontl_callback_Ptr->Proprietary_Tx_CompleteCallback != NULL)
	    {
	        commontl_callback_Ptr->Proprietary_Tx_CompleteCallback();//LinIf_TxConfirmation()
	    }

	}
	else
	{
		if (commontl_callback_Ptr->App_Tx_CompleteCallback != NULL)
	    {
	        commontl_callback_Ptr->App_Tx_CompleteCallback(id);
	    }
	}

	
}


/* *****************************************************************************
 * EOF
 ******************************************************************************/
