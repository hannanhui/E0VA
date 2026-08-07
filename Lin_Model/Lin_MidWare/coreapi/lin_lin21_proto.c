/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      C source file                                                            */
/*   Name         :      lin_lin21_proto.c                                                        */
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


#include "lin_lin21_proto.h"
#include "lin_common_proto.h"

/* *****************************************************************************
 * Variables
 ******************************************************************************/


/*FUNCTION**********************************************************************
 *
 * Function Name : lin_update_word_status_lin21
 * Description   : Update node status flags.
 *
 * Implements    : lin_update_word_status_lin21_Activity
 *END**************************************************************************/
void lin_update_word_status_lin21(l_ifc_handle iii,
                                  lin_lld_event_id_t event_id)
{
    uint8_t err_in_res;
    uint8_t suc_in_tras;
    uint8_t save_config;
    uint8_t overrun_flag;
    lin_word_status_str_t * word_status_ptr;
    lin_protocol_state_t * prot_state_ptr = &g_lin_protocol_state_array[iii];

    err_in_res = prot_state_ptr->error_in_response;
    prot_state_ptr->error_in_response = 0;
    suc_in_tras = prot_state_ptr->successful_transfer;
    /* use of ternary operator below is for being MISRA compliant */
    save_config = (uint8_t)(prot_state_ptr->save_config_flg ? 1U : 0U);
    overrun_flag = prot_state_ptr->overrun_flg;

    word_status_ptr = &prot_state_ptr->word_status;
    word_status_ptr->overrun = overrun_flag;

    /* values for all processed frames */
    word_status_ptr->error_in_res |= err_in_res;
    word_status_ptr->successful_transfer |= suc_in_tras;
    word_status_ptr->last_pid = prot_state_ptr->last_pid;

    if(prot_state_ptr->go_to_sleep_flg == TRUE)
    {
        /* Set go to sleep flag for word status*/
        word_status_ptr->go_to_sleep_flg = 1;
    }

    if(LIN_LLD_BUS_ACTIVITY_TIMEOUT != event_id)
    {
        /* Set bus activity timeout */
        word_status_ptr->bus_activity = 1U;
    }

    {
        /* For Slave node - using ternary operator is a workaround for MISRA */
        word_status_ptr->event_trigger_collision_flg = 0U;
        /* Updated save configuration value to word status */
        word_status_ptr->save_config_flg = save_config;
        word_status_ptr->reserved = 0U;
    }
}

#if (SUPPORT_SLAVE_MODE == 1U)
/*FUNCTION**********************************************************************
 *
 * Function Name : lin_update_err_signal
 * Description   : Updates error in response flag for frames different than Event Frames
 *
 * Implements    : lin_update_err_signal_Activity
 *END**************************************************************************/
void lin_update_err_signal(l_ifc_handle iii,
                           uint8_t frm_id)
{
	#if 0
    uint8_t i;
    const uint16_t* byte_offset_temp_ptr;
    const uint8_t* bit_offset_temp_ptr;
	uint8_t Tbl_Index =0u;
    uint8_t err_in_res = g_lin_protocol_state_array[iii].error_in_response;
    const lin_protocol_user_config_t * prot_user_config_ptr = &g_lin_protocol_user_cfg_array[iii];
    const lin_node_attribute_t * node_attr_ptr;
    node_attr_ptr = &g_lin_node_attribute_array[prot_user_config_ptr->slave_ifc_handle];

    if (frm_id < g_lin_protocol_ldf_cfg_array[Tbl_Index].number_of_configurable_frames)
    {
        /* Set error signal equal to error in response */
        if (LIN_FRM_EVNT != g_lin_protocol_ldf_cfg_array[Tbl_Index].frame_tbl_ptr[frm_id].frm_type)
        {
            for (i = 0; i < node_attr_ptr->num_frame_have_esignal; i++)
            {
                byte_offset_temp_ptr = &node_attr_ptr->response_error_byte_offset_ptr[i];
                bit_offset_temp_ptr = &node_attr_ptr->response_error_bit_offset_ptr[i];
                g_lin_protocol_ldf_cfg_array[Tbl_Index].Frame_Buff_data_ptr[*byte_offset_temp_ptr] = (uint8_t)((g_lin_protocol_ldf_cfg_array[Tbl_Index].Frame_Buff_data_ptr[*byte_offset_temp_ptr] & (~(1U << (*bit_offset_temp_ptr)))) |
                                                        ((uint8_t)(err_in_res << (*bit_offset_temp_ptr))));
            }
        }
    }
	#endif
}

#endif /* End (SUPPORT_SLAVE_MODE == 1U) */

/*FUNCTION**********************************************************************
 *
 * Function Name : lin_update_rx_evnt_frame
 * Description   : The function updates the receive flags associated with signals/frames
 * in case receive an event trigger frame.
 *
 * Implements    : lin_update_rx_evnt_frame_Activity
 *END**************************************************************************/
void lin_update_rx_evnt_frame(l_ifc_handle iii,
                              uint8_t pid)
{
		#if 0
    const lin_associate_frame_t * ptr;
    uint8_t frame_index, i, associate_id;
    const lin_protocol_user_config_t * prot_user_config_ptr = &g_lin_protocol_user_cfg_array[iii];
	
    /* Get frame index of the event trigger frame */
    frame_index = lin_get_frame_index(iii, pid);
	Tbl_Index = lin_get_Tbl_index(iii);
    if (0xFFU != frame_index) /* This PID doesn't belong to this node */
    {
        /* calculate PID that associated with ETF */
        associate_id = lin_process_parity(g_lin_protocol_state_array[iii].response_buffer_ptr[0], CHECK_PARITY);
        ptr = prot_user_config_ptr->frame_tbl_ptr[frame_index].frame_data_ptr;

        for (i = 0U; i < ptr->num_of_associated_uncond_frames; i++)
        {
            /* First byte of response for event trigger is the PID of the associate frame */
            if (prot_user_config_ptr->list_identifiers_RAM_ptr[((uint8_t)ptr->associated_uncond_frame_ptr[i] - prot_user_config_ptr->frame_start) + 1U] == associate_id)
            {
                /* Update unconditional frame */
                lin_process_uncd_frame(iii, associate_id, UPDATE_UNCONDITIONAL_FRAME);
                break;
            }
        }
    }
	#endif
}

#if (SUPPORT_SLAVE_MODE == 1U)
/*FUNCTION**********************************************************************
 *
 * Function Name : lin_make_res_evnt_frame
 * Description   : This function packs signals associated with event trigger frame into buffer.
 *
 * Implements    : lin_make_res_evnt_frame_Activity
 *END**************************************************************************/
void lin_make_res_evnt_frame(l_ifc_handle iii,
                             uint8_t pid)
{
    /* Create response */
    lin_process_uncd_frame(iii, pid, MAKE_UNCONDITIONAL_FRAME);
    /* Set associate PID */
    g_lin_protocol_state_array[iii].response_buffer_ptr[0] = lin_process_parity(pid, MAKE_PARITY);
}

#endif /* End (SUPPORT_SLAVE_MODE == 1U) */

/* *****************************************************************************
 * EOF
 ******************************************************************************/
