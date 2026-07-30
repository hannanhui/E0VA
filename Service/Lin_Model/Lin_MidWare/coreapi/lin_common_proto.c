/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      C source file                                                            */
/*   Name         :      lin_common_proto.c                                                       */
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


#include "include.h"


/* *****************************************************************************
 * Variables
 ******************************************************************************/
static uint8_t lin_baseOnIdGet_TblIndex=0u;
/* *****************************************************************************
 * Static function prototypes
 ******************************************************************************/
/*
 * @brief Handle the received ID and decide the next action of Stack.
 *
 * @param iii Interface name
 * @param id ID to process
 * @return void
 */
static void lin_process_id(l_ifc_handle iii,
                           uint8_t id);

static void lin_update_rx(l_ifc_handle iii,
                          uint8_t id);

static void lin_update_tx(l_ifc_handle iii,
                          uint8_t id);

static void lin_handle_error(l_ifc_handle iii,
                             lin_lld_event_id_t event_id,
                             uint8_t id);

static void lin_bus_activity_timeout(l_ifc_handle iii);


static void lin_bus_RecvFrame_timeout_DataClr(l_ifc_handle iii);

/* *****************************************************************************
 * Code
 ******************************************************************************/

/*FUNCTION**********************************************************************
 *
 * Function Name : lin_pid_resp_callback_handler
 * Description   : Callback handler for LIN low level events.
 *
 * Implements    : lin_pid_resp_callback_handler_Activity
 *END**************************************************************************/
void lin_pid_resp_callback_handler(l_ifc_handle iii,
                                   const lin_lld_event_id_t event_id,
                                   uint8_t id)
{
    switch (event_id)
    {
        case LIN_LLD_PID_OK:
            lin_process_id(iii, id);
            break;
        case LIN_LLD_TX_COMPLETED:
            lin_update_tx(iii, id);
            break;
        case LIN_LLD_RX_COMPLETED:
            lin_update_rx(iii, id);
            break;
        case LIN_LLD_BUS_ACTIVITY_TIMEOUT:
            lin_bus_activity_timeout(iii);
            break;
        case LIN_LLD_PID_ERR:
        case LIN_LLD_FRAME_ERR:
        case LIN_LLD_CHECKSUM_ERR:
        case LIN_LLD_READBACK_ERR:
		case LIN_LLD_TX_BIT_ERR:
		case LIN_LLD_RX_OVERFLOW:
		case LIN_LLD_SYNC_ERR:	
        case LIN_LLD_NODATA_TIMEOUT:
		case LIN_LLD_TX_TIMEOUT:	
        case LIN_LLD_RX_TIMEOUT:
            lin_handle_error(iii, event_id, id);
            break;
        default:
            /* do nothing */
            break;
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : lin_process_id
 * Description   : Handle the received ID and decide the next action of Stack.
 *
 * Implements    : lin_process_id_Activity
 *END**************************************************************************/
static void lin_process_id(l_ifc_handle iii,
                           uint8_t id)
{
    uint8_t action = 0U;
    const lin_frame_t * lin_frame_ptr;
    uint8_t frame_index;
	uint8_t Tbl_Index =0u;
#if ((SUPPORT_SLAVE_MODE == 1U) && (SUPPORT_PROTOCOL_21 == 1U))
    uint8_t volatile associate_frame;
    //uint16_t flag_offset;
    //uint8_t flag_size;
    //uint8_t i;
#endif
    const lin_protocol_user_config_t * prot_user_config_ptr = &g_lin_protocol_user_cfg_array[iii];
    lin_protocol_state_t * prot_state_ptr = &g_lin_protocol_state_array[iii];

    frame_index = lin_get_frame_index(iii, id);
    Tbl_Index = lin_get_Tbl_index(iii);
    if (0xFFU != frame_index)
    {
    	lin_frame_ptr = &(g_lin_protocol_ldf_cfg_array[Tbl_Index].frame_tbl_ptr[frame_index]);
        action = 1U;
        prot_state_ptr->last_pid = lin_process_parity(id,MAKE_PARITY);
        /* PID belongs to this node, then check type of frame */
        switch (lin_frame_ptr->frm_type)
        {
            /* Unconditional frame */
            case LIN_FRM_UNCD:
                if (LIN_RES_PUB == lin_frame_ptr->frm_response)
                {
                    lin_process_uncd_frame(iii, id, MAKE_UNCONDITIONAL_FRAME);
                    /* Set response */
                    action = 2U;
                }
                break;
            #if (SUPPORT_PROTOCOL_21 == 1U)
            /* Event trigger frame */
            case LIN_FRM_EVNT:
                if ((bool)LIN_MASTER == prot_user_config_ptr->function)
                {
                    /* Rx response */
                    action = 1U;
                }
            #if (SUPPORT_SLAVE_MODE == 1U)
                else
                {
                    /* For each slave node, get the only one associated unconditional frame */
					#if 0
                    associate_frame = (uint8_t)(*((lin_frame_ptr->frame_data_ptr)->associated_uncond_frame_ptr));
                    flag_offset = prot_user_config_ptr->frame_tbl_ptr[associate_frame].flag_offset;
                    flag_size = prot_user_config_ptr->frame_tbl_ptr[associate_frame].flag_size;
                    /* Update transmit flags */
                    for (i = 0U; i < flag_size; i++)
                    {
                        if (g_lin_flag_handle_tbl[flag_offset++] != 0xFFU)
                        {
                            /* Frame is updated */
                            lin_make_res_evnt_frame(iii, prot_user_config_ptr->list_identifiers_RAM_ptr[1U + associate_frame - prot_user_config_ptr->frame_start]);
                            /* Set response */
                            action = 2U;
                            break;
                        }
                    }
					#else
					//associate_frame = (uint8_t)(*((lin_frame_ptr->frame_data_ptr)->associated_uncond_frame_ptr));
					//lin_make_res_evnt_frame(iii, prot_user_config_ptr->list_identifiers_RAM_ptr[1U + associate_frame - prot_user_config_ptr->frame_start]);
					action = 0U;
					#endif
					
                }
            #endif /* End (SUPPORT_SLAVE_MODE == 1) */
                break;
            #endif /* End (SUPPORT_PROTOCOL_21 == 1) */

            /* Diagnostic frame */
            case LIN_FRM_DIAG:
                if(prot_user_config_ptr->protocol_version != LIN_PROTOCOL_13)
                {
                    if (LIN_RES_PUB == lin_frame_ptr->frm_response)
                    {
                        action = 2U;

                        if (LIN_TL_CALLBACK_HANDLER(iii, TL_SLAVE_GET_ACTION, id) == TL_ACTION_ID_IGNORE)
                        {
                            action = 0U;
                        }
                    }
                    else
                    {
                        /* Rx response */
                        action = 1U;
						if (LIN_TL_CALLBACK_HANDLER(iii, TL_RECEIVE_MESSAGE, id) == TL_ACTION_ID_IGNORE)
                        {
                            action = 0U;
                        }
                    }
                }
                else
                {
                    action = 0U;
                }

                break;
			case LIN_FRM_PROPRIETARY:
				if (LIN_RES_PUB == lin_frame_ptr->frm_response)
                {
					action = 2U;
                    if (LIN_TL_CALLBACK_HANDLER(iii, TL_SLAVE_GET_ACTION, id) == TL_ACTION_ID_IGNORE)
                    {
                        action = 0U;
                    }
				}
				else
                {
                    action = 1U;
					if (LIN_TL_CALLBACK_HANDLER(iii, TL_RECEIVE_MESSAGE, id) == TL_ACTION_ID_IGNORE)
                    {
                        action = 0U;
                    }
                }
			break;
            default:
                /* do nothing */
                break;
        }
    }

    switch (action)
    {
        case 1U:
            /* Receive response */
            (void)lin_lld_rx_response(iii, lin_frame_ptr->frm_len);
            break;
        case 2U:
            /* Set response */
            (void)lin_lld_set_response(iii, lin_frame_ptr->frm_len);
            break;
        default:
            /* ignore response */
            (void)lin_lld_ignore_response(iii);
            break;
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : lin_update_rx
 * Description   : This function update signal, status, and flag after received response.
 *
 * Implements    : lin_update_rx_Activity
 *END**************************************************************************/
static void lin_update_rx(l_ifc_handle iii,
                          uint8_t id)
{
    uint8_t frame_index;//,  associate_id;//flag_size, i,
    uint8_t Tbl_Index =0u;
    //uint16_t flag_offset;
    const lin_protocol_user_config_t * prot_user_config_ptr = &g_lin_protocol_user_cfg_array[iii];
    lin_protocol_state_t * prot_state_ptr = &g_lin_protocol_state_array[iii];

    /* Set successful transfer */
    prot_state_ptr->successful_transfer = 1U;
    /* if two or more frames are processed since the previous call to l_ifc_read_status, set overrun flag to 1 */
    if (prot_state_ptr->num_of_processed_frame < 0xFFU)
    {
        prot_state_ptr->num_of_processed_frame++;
    }

    if ((prot_state_ptr->num_of_processed_frame > 1U) && (prot_state_ptr->overrun_flg == 0U))
    {
        prot_state_ptr->overrun_flg = 1U;
    }

    frame_index = lin_get_frame_index(iii, id);
	Tbl_Index = lin_get_Tbl_index(iii);
    if (frame_index < g_lin_protocol_ldf_cfg_array[Tbl_Index].number_of_configurable_frames)
    {
        /* This PID doesn't belong to this node */
        /* PID belongs to this node, then check type of frame */
        switch (g_lin_protocol_ldf_cfg_array[Tbl_Index].frame_tbl_ptr[frame_index].frm_type)
        {
            /* Unconditional frame */
            case LIN_FRM_UNCD:
                lin_process_uncd_frame(iii, id, UPDATE_UNCONDITIONAL_FRAME);
                break;
            /* Event trigger frame */
            case LIN_FRM_EVNT:
                lin_update_rx_evnt_frame(iii, id);
                /* Recalculate frame_index by updating associate PID */
                //associate_id = lin_process_parity(prot_state_ptr->response_buffer_ptr[0], CHECK_PARITY);
                //frame_index = lin_get_frame_index(iii, associate_id);
				//Tbl_Index = lin_get_Tbl_index(iii);
                break;
            /* Diagnostic frame */
            case LIN_FRM_DIAG:
                /* If goto sleep signal */
                if (0U == prot_state_ptr->response_buffer_ptr[0])
                {
                    /* In a slave node, set go to sleep flag in state structure */
                    prot_state_ptr->go_to_sleep_flg = true;
					lin_bus_RecvFrame_timeout_DataClr(iii);
                    (void)lin_lld_set_low_power_mode(iii);
                }
                else
                {
                    /* Call transport layer callback to process TL_RX_COMPLETED event*/
                    (void)LIN_TL_CALLBACK_HANDLER(iii, TL_RX_COMPLETED, id);
                }

                break;
			case LIN_FRM_PROPRIETARY:
				// /* Call transport layer callback to process TL_RX_COMPLETED event*/
                    (void)LIN_TL_CALLBACK_HANDLER(iii, TL_RX_COMPLETED, id);
            default:
                /* do nothing */
                break;
        }


    #if (SUPPORT_SLAVE_MODE == 1U)
        /* update word status */
        if ((bool)LIN_SLAVE == prot_user_config_ptr->function)
        {
            if (prot_user_config_ptr->protocol_version == LIN_PROTOCOL_21)
            {
                lin_update_word_status_lin21(iii, LIN_LLD_RX_COMPLETED);
            }
            else
            {
                if (prot_user_config_ptr->protocol_version == LIN_PROTOCOL_J2602)
                {
                    lin_update_word_status_j2602(iii);
                }
            }
        }
    #endif /* End (SUPPORT_SLAVE_MODE == 1U) */
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : lin_update_tx
 * Description   : This function update status and flags after transmit response
 *
 * Implements    : lin_update_tx_Activity
 *END**************************************************************************/
static void lin_update_tx(l_ifc_handle iii,
                          uint8_t id)
{
    //uint8_t frame_index;
    const lin_protocol_user_config_t * prot_user_config_ptr = &g_lin_protocol_user_cfg_array[iii];
    lin_protocol_state_t * prot_state_ptr = &g_lin_protocol_state_array[iii];
	//const lin_node_attribute_t * node_attr_ptr;
    //node_attr_ptr = &g_lin_node_attribute_array[prot_user_config_ptr->slave_ifc_handle];


    /* Set successful transfer */
    prot_state_ptr->successful_transfer = 1U;
    /* if two or more frames are processed since the previous call to l_ifc_read_status, set overrun flag to 1 */
    if (prot_state_ptr->num_of_processed_frame < 0xFFU)
    {
        prot_state_ptr->num_of_processed_frame++;
    }

    if ((prot_state_ptr->num_of_processed_frame > 1U) && (prot_state_ptr->overrun_flg == 0U))
    {
        prot_state_ptr->overrun_flg = 1U;
    }

    if ((bool)1U == prot_state_ptr->transmit_error_resp_sig_flg)
    {
        /* Set no error in response */
        prot_state_ptr->error_in_response = 0U;
        prot_state_ptr->transmit_error_resp_sig_flg = (bool)0U;
    }

    /* Find frame index by pid */
    //frame_index = lin_get_frame_index(iii, id);
    
    /* Call transport layer callback to process TL_TX_COMPLETED event*/
    (void)LIN_TL_CALLBACK_HANDLER(iii, TL_TX_COMPLETED, id);
   


#if (SUPPORT_SLAVE_MODE == 1U)
    /* Update word status */
    if ((bool)LIN_SLAVE == prot_user_config_ptr->function)
    {
    	//low driver only set ResponeErr ,App user need clear ResponeErr
    	//node_attr_ptr->ResponeErr_Type->Value=0;
    #if (SUPPORT_PROTOCOL_21 == 1U)
		if (prot_user_config_ptr->protocol_version == LIN_PROTOCOL_21)
        {
            lin_update_word_status_lin21(iii, LIN_LLD_TX_COMPLETED);
        }
        else
        {
            if (prot_user_config_ptr->protocol_version == LIN_PROTOCOL_J2602)
            {
                lin_update_word_status_j2602(iii);
            }
        }
    #endif
    
    }

#endif /* End (SUPPORT_SLAVE_MODE == 1U) */
}

/*FUNCTION**********************************************************************
 *
 * Function Name : lin_handle_error
 * Description   : This function handle error raised by low-level
 *
 * Implements    : lin_handle_error_Activity
 *END**************************************************************************/
static void lin_handle_error(l_ifc_handle iii,
                             lin_lld_event_id_t event_id,
                             uint8_t id)
{
#if ((SUPPORT_PROTOCOL_21 == 1U) || (SUPPORT_SLAVE_MODE == 1U))
    const lin_protocol_user_config_t * prot_user_config_ptr = &g_lin_protocol_user_cfg_array[iii];
#endif
    lin_protocol_state_t * prot_state_ptr = &g_lin_protocol_state_array[iii];
	uint8_t Tbl_Index =0u;
	const lin_node_attribute_t * node_attr_ptr;
    node_attr_ptr = &g_lin_node_attribute_array[prot_user_config_ptr->slave_ifc_handle];
#if (SUPPORT_PROTOCOL_21 == 1U)
    uint8_t frame_index;
    frame_index = lin_get_frame_index(iii, id);
	Tbl_Index = lin_get_Tbl_index(iii);
#endif

    /* if two or more frames are processed since the previous call to l_ifc_read_status, set overrun flag to 1 */
    if (prot_state_ptr->num_of_processed_frame < 0xFFU)
    {
        prot_state_ptr->num_of_processed_frame++;
    }

    if ((prot_state_ptr->num_of_processed_frame > 1U) && (prot_state_ptr->overrun_flg == 0U))
    {
        prot_state_ptr->overrun_flg = 1U;
    }

    switch (event_id)
    {
        /* PID error */
        case LIN_LLD_PID_ERR:
            /* do nothing here */
			node_attr_ptr->ResponeErr_Type->Bit.Rx_Pid_Check_Err=1;
            break;
        /* Frame error */
        case LIN_LLD_FRAME_ERR:
			/* do nothing here */
			node_attr_ptr->ResponeErr_Type->Bit.Rx_ByteField_Framing_Err=1;
            break;
        case LIN_LLD_CHECKSUM_ERR:
			/* do nothing here */
			node_attr_ptr->ResponeErr_Type->Bit.Rx_Check_Sum_Err=1;
            break;
        case LIN_LLD_READBACK_ERR:
			/* do nothing here */
			node_attr_ptr->ResponeErr_Type->Bit.Tx_ReadBack_Err=1;
            break;
		case LIN_LLD_TX_BIT_ERR:
			/* do nothing here */
			node_attr_ptr->ResponeErr_Type->Bit.Tx_Bit_Err=1;
            break;
    	case LIN_LLD_SYNC_ERR:
			/* do nothing here */
			node_attr_ptr->ResponeErr_Type->Bit.Rx_Sync_Err=1;
            break;
    	case LIN_LLD_RX_OVERFLOW:
			/* do nothing here */
			node_attr_ptr->ResponeErr_Type->Bit.Rx_Overflow_Err=1;
            break;
		case LIN_LLD_TX_TIMEOUT:
			/* do nothing here */
			node_attr_ptr->ResponeErr_Type->Bit.Tx_Data_Timeout=1;
            break;
    	case LIN_LLD_RX_TIMEOUT:
			/* do nothing here */
			node_attr_ptr->ResponeErr_Type->Bit.Rx_Data_Timeout=1;
            break;
        case LIN_LLD_NODATA_TIMEOUT:
        #if (SUPPORT_PROTOCOL_21 == 1U)
            /* Check if frame type is event trigger */
            /* Find the corresponding frame */

            if (LIN_FRM_EVNT == g_lin_protocol_ldf_cfg_array[Tbl_Index].frame_tbl_ptr[frame_index].frm_type)
            {

            }
            else
        #endif  /* if (SUPPORT_PROTOCOL_21 == 1U) */
            {
                /* Set response error */
                //prot_state_ptr->error_in_response = 1U;
                /* TL support */
                if ((0x3CU == id) || (0x3DU == id))
                {
                    /* Call transport layer callback to handle TL_ERROR */
                    (void)LIN_TL_CALLBACK_HANDLER(iii, TL_ERROR, id);
                }
            }
            break;
        default:
            /* do nothing */
            break;
    }

#if (SUPPORT_SLAVE_MODE == 1U)
    /* Update word status */
    if ((bool)LIN_SLAVE == prot_user_config_ptr->function)
    {
    #if (SUPPORT_PROTOCOL_21 == 1U)
		if (prot_user_config_ptr->protocol_version == LIN_PROTOCOL_21)
        {
            lin_update_word_status_lin21(iii, event_id);
        }
        else
        {
            if (prot_user_config_ptr->protocol_version == LIN_PROTOCOL_J2602)
            {
                lin_update_word_status_j2602(iii);
            }
        }
    #endif
    
    }
#endif /* End (SUPPORT_SLAVE_MODE == 1U) */
}


static void lin_bus_RecvFrame_timeout_DataClr(l_ifc_handle iii)
{
	//uint8_t frame_index;
    //uint8_t * response_buffer_ptr;
    uint16_t frame_byte_offset;
	uint8_t datalength;
    uint8_t i,j,k;
    const lin_protocol_user_config_t * prot_user_config_ptr = &g_lin_protocol_user_cfg_array[iii];
    //lin_protocol_state_t * prot_state_ptr = &g_lin_protocol_state_array[iii];
    for(i = 0;i<prot_user_config_ptr->number_of_schedule_Tbl; i++)
   	{
		for (j = 0;j<g_lin_protocol_ldf_cfg_array[i].number_of_configurable_frames-4; j++)
	    {
				if(LIN_RES_SUB == g_lin_protocol_ldf_cfg_array[i].frame_tbl_ptr[j].frm_response)
				{
					datalength = g_lin_protocol_ldf_cfg_array[i].frame_tbl_ptr[j].frm_len;
					frame_byte_offset = g_lin_protocol_ldf_cfg_array[i].frame_tbl_ptr[j].frm_offset;
					for (k = 0U; k < datalength; k++)
					{

						g_lin_protocol_ldf_cfg_array[i].Frame_Buff_data_ptr[frame_byte_offset + k]=0;
					}
				}
		}
	}
	


}
/*FUNCTION**********************************************************************
 *
 * Function Name : lin_bus_activity_timeout
 * Description   : This function set bus activity timeout
 *
 * Implements    : lin_bus_activity_timeout_Activity
 *END**************************************************************************/
static void lin_bus_activity_timeout(l_ifc_handle iii)
{
    /* Set goto sleep mode */
#if (SUPPORT_SLAVE_MODE == 1U)
    const lin_protocol_user_config_t * prot_user_config_ptr = &g_lin_protocol_user_cfg_array[iii];

    if ((bool)LIN_SLAVE == prot_user_config_ptr->function)
    {
    #if (SUPPORT_PROTOCOL_21 == 1U)
        if (prot_user_config_ptr->protocol_version == LIN_PROTOCOL_21)
        {
            lin_update_word_status_lin21(iii, LIN_LLD_BUS_ACTIVITY_TIMEOUT);
			lin_bus_RecvFrame_timeout_DataClr(iii);
        }
		else
		{
			if (prot_user_config_ptr->protocol_version == LIN_PROTOCOL_J2602)
            {
                lin_update_word_status_j2602(iii);
				lin_bus_RecvFrame_timeout_DataClr(iii);
            }
			
		}
		
    #endif
    
    }

#endif /* End (SUPPORT_SLAVE_MODE == 1U) */

    /* Change to low power mode */
    (void)lin_lld_set_low_power_mode(iii);
}





/*FUNCTION**********************************************************************
 *
 * Function Name : lin_get_frame_index
 * Description   : This function returns the index of a frame in frame list
 * or 0xFF if not found.
 *
 * Implements    : lin_get_frame_index_Activity
 *END**************************************************************************/
uint8_t lin_get_frame_index(l_ifc_handle iii,
                         uint8_t id)
{
    uint8_t i;
    uint8_t retVal = 0xFFU;
    const lin_protocol_user_config_t * prot_user_config_ptr = &g_lin_protocol_user_cfg_array[iii];
	uint8_t Tbl_Index =0u;//l_lld_Id_Stbl_use_index_Get_LI0();
	uint8_t Lin_PowerState = PowerApp_LinGetBattery_Voltage_State();
	uint8_t id_FindGetFlag =0u;
	if((VOLTAGE_STATE_UNDER_LOW != Lin_PowerState)&&(VOLTAGE_STATE_OVER_HIGH != Lin_PowerState))
	{
		for(Tbl_Index = 0u;Tbl_Index<prot_user_config_ptr->number_of_schedule_Tbl;Tbl_Index++)
		{
			if (TRUE == prot_user_config_ptr->list_schedule_tbl_En_ptr[Tbl_Index])
			{
				id_FindGetFlag =0u;
				for (i = g_lin_protocol_ldf_cfg_array[Tbl_Index].number_of_configurable_frames; i > 0U; i--)
			    {
			        if ((g_lin_protocol_ldf_cfg_array[Tbl_Index].list_identifiers_RAM_ptr[i] == id)&&(TRUE == g_lin_protocol_ldf_cfg_array[Tbl_Index].list_Node_tbl_En_ptr[i-1]))
			        {
			            retVal = (uint8_t)(i + prot_user_config_ptr->frame_start - 1U);
						id_FindGetFlag =1u;
						lin_baseOnIdGet_TblIndex = Tbl_Index;
			            break;
			        }
			    }
				if(id_FindGetFlag)
				{
					break;
				}
			}
		    
		}
	}
    return retVal;
}
uint8_t lin_get_Tbl_index(l_ifc_handle iii)
{
    return lin_baseOnIdGet_TblIndex;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : lin_process_uncd_frame
 * Description   : This function packs signals associated with unconditional frame
 * into buffer.
 *
 * Implements    : lin_process_uncd_frame_Activity
 *END**************************************************************************/
void lin_process_uncd_frame(l_ifc_handle iii,
                            uint8_t id,
                            uint8_t type)
{
    uint8_t frame_index;
    uint8_t * response_buffer_ptr;
    uint16_t frame_byte_offset;
    uint8_t i;
	uint8_t Tbl_Index =0u;
    const lin_protocol_user_config_t * prot_user_config_ptr = &g_lin_protocol_user_cfg_array[iii];
    lin_protocol_state_t * prot_state_ptr = &g_lin_protocol_state_array[iii];
#if (SUPPORT_SLAVE_MODE == 1U)
    //const lin_node_attribute_t * node_attr_ptr;
    //uint8_t flag;
#endif /* End (SUPPORT_SLAVE_MODE == 1U) */

    frame_index = lin_get_frame_index(iii, id);
	Tbl_Index = lin_get_Tbl_index(iii);

    if (0xFFU != frame_index)
    {
        response_buffer_ptr = prot_state_ptr->response_buffer_ptr;
		
        /* Set frame length */
        prot_state_ptr->response_length = g_lin_protocol_ldf_cfg_array[Tbl_Index].frame_tbl_ptr[frame_index].frm_len;
        frame_byte_offset = g_lin_protocol_ldf_cfg_array[Tbl_Index].frame_tbl_ptr[frame_index].frm_offset;

        /* Make unconditional frame */
        if (MAKE_UNCONDITIONAL_FRAME == type)
        {
        	
        	#if (SUPPORT_SLAVE_MODE == 1U)
            if ((bool)LIN_SLAVE == prot_user_config_ptr->function)
            {
            	#if 0
                node_attr_ptr = &g_lin_node_attribute_array[prot_user_config_ptr->slave_ifc_handle];
				
                for (i = 0U; i < node_attr_ptr->num_frame_have_esignal; i++)
                {
                    /* Check if frame contain error signal */
                    if ((id == node_attr_ptr->resp_err_frm_id_ptr[i])&&(0xFF != node_attr_ptr->resp_err_frm_id_ptr[i]))
                    {
                        prot_state_ptr->transmit_error_resp_sig_flg = (bool)1U;
                        break;
                    }
                }

				#endif
								LIN_TL_CALLBACK_HANDLER(iii, TL_SLAVE_GET_ACTION, id);
                /* Get data from LIN frame buffer */
                for (i = 0U; i < prot_state_ptr->response_length; i++)
                {

                    response_buffer_ptr[i] = g_lin_protocol_ldf_cfg_array[Tbl_Index].Frame_Buff_data_ptr[frame_byte_offset + i];
                }
            }
            else
        #endif /* End (SUPPORT_SLAVE_MODE == 1U) */
            {

            }
        }
        /* Update unconditional frame */
        else
        {
            if ((bool)LIN_SLAVE == prot_user_config_ptr->function)
            {
                for (i = 0U; i < prot_state_ptr->response_length; i++)
                {
                    g_lin_protocol_ldf_cfg_array[Tbl_Index].Frame_Buff_data_ptr[frame_byte_offset + i] = response_buffer_ptr[i];
                }
				/* Call transport layer callback to process TL_RX_COMPLETED event*/
                (void)LIN_TL_CALLBACK_HANDLER(iii, TL_RX_COMPLETED, id);
            }

        }
    }
}

/* *****************************************************************************
 * EOF
 ******************************************************************************/
