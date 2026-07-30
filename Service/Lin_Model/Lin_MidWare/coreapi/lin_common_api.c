/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      C source file                                                            */
/*   Name         :      lin_common_api.c                                                         */
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
 * @file lin_common_api.c
 *
 * @page misra_violations MISRA-C:2012 violations
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 8.7, Could be made static.
 * Functions are APIs, so they shall not be made static.
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 8.9, An object should be defined at block
 * scope if its identifier only appears in a single function.
 * An object with static storage duration declared at block scope cannot be
 * accessed directly from outside the block.
 */

#include "include.h"

/* *****************************************************************************
 * Code
 ******************************************************************************/

/* *****************************************************************************
 * Static function prototypes
 ******************************************************************************/

/*FUNCTION**********************************************************************
 *
 * Function Name : l_sys_init
 * Description   : This function performs the initialization of the LIN core.
 * The implementation of this function can be replaced by user if needed.
 *
 * Implements    : l_sys_init_Activity
 *END**************************************************************************/
BOOL l_sys_init(void)
{
    return (BOOL)0;
}

lin_node_state_t l_ifc_get_state(l_ifc_handle iii)
{	
	lin_node_state_t ret_val;
	CHECK_RESTRICTION((uint8_t)iii < LIN_NUM_OF_IFCS);
	ret_val = lin_lld_get_state(iii);

    return ret_val;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : l_ifc_init
 * Description   : Initialize the interface specified by name, i.e. sets up internal
 * functions such as the baud rate
 *
 * Implements    : l_ifc_init_Activity
 *END**************************************************************************/
BOOL l_ifc_init(l_ifc_handle iii)
{
    CHECK_RESTRICTION((uint8_t)iii < LIN_NUM_OF_IFCS);
    lin_protocol_state_t * prot_state_ptr = &g_lin_protocol_state_array[iii];

    BOOL ret_val;
    prot_state_ptr->diagnostic_mode = DIAG_NONE;

    /* Call Low level initialization function */
    ret_val = lin_lld_init(iii);
    /* Check if low level initialization is successful */
    if (ret_val == (BOOL)LIN_LLD_OK)
    {
    }

    return ret_val;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : l_ifc_wake_up
 * Description   : Transmit the wake up signal.
 *
 * Implements    : l_ifc_wake_up_Activity
 *END**************************************************************************/
void l_ifc_wake_up(l_ifc_handle iii)
{
    CHECK_RESTRICTION((uint8_t)iii < LIN_NUM_OF_IFCS);
    lin_lld_Wakeup(iii);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : l_ifc_read_status
 * Description   : This function will return the status of the previous communication.
 *
 * Implements    : l_ifc_read_status_Activity
 *END**************************************************************************/
uint16_t l_ifc_read_status(l_ifc_handle iii)
{
    CHECK_RESTRICTION((uint8_t)iii < LIN_NUM_OF_IFCS);

    uint16_t tmp_word_status = 0U;
    lin_protocol_state_t * prot_state_ptr = &g_lin_protocol_state_array[iii];
    tmp_word_status = (uint16_t)(prot_state_ptr->word_status.last_pid << 8);
    if (prot_state_ptr->word_status.save_config_flg == 1U)
    {
        tmp_word_status |= SAVE_CONFIG_SET;
    }

    if (prot_state_ptr->word_status.event_trigger_collision_flg == 1U)
    {
        tmp_word_status |= EVENT_TRIGGER_COLLISION_SET;
    }

    if (prot_state_ptr->word_status.bus_activity == 1U)
    {
        tmp_word_status |= BUS_ACTIVITY_SET;
    }

    if (prot_state_ptr->word_status.go_to_sleep_flg == 1U)
    {
        tmp_word_status |= GO_TO_SLEEP_SET;
    }

    if (prot_state_ptr->word_status.overrun == 1U)
    {
        tmp_word_status |= OVERRUN;
    }

    if (prot_state_ptr->word_status.successful_transfer == 1U)
    {
        tmp_word_status |= SUCCESSFULL_TRANSFER;
    }

    if (prot_state_ptr->word_status.error_in_res == 1U)
    {
        tmp_word_status |= ERROR_IN_RESPONSE;
    }

    /* Read-reset call; meaning that after the call has returned,
     * the status word is set to 0 */
    /* Clear word status */
    prot_state_ptr->word_status.last_pid = 0x00U;
    prot_state_ptr->word_status.reserved = 0U;
    prot_state_ptr->word_status.save_config_flg = 0U;
    prot_state_ptr->word_status.event_trigger_collision_flg = 0U;
    prot_state_ptr->word_status.bus_activity = 0U;
    prot_state_ptr->word_status.go_to_sleep_flg = 0U;
    prot_state_ptr->word_status.overrun = 0U;
    prot_state_ptr->word_status.successful_transfer = 0U;
    prot_state_ptr->word_status.error_in_res = 0U;
    /* Clear save configuration flag value */
    prot_state_ptr->save_config_flg = (bool)0U;
    /* reset word status flags in g_lin_protocol_state_array for new session*/
    prot_state_ptr->go_to_sleep_flg = false;
    prot_state_ptr->overrun_flg = 0U;
    prot_state_ptr->successful_transfer = 0U;

    /* Reset number of processed frames to 0 */
    prot_state_ptr->num_of_processed_frame = 0U;

    return tmp_word_status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : l_sys_irq_disable
 * Description   : Disable LIN related IRQ.
 *
 * Implements    : l_sys_irq_disable_Activity
 *END**************************************************************************/
uint16_t l_sys_irq_disable(l_ifc_handle iii)
{
    CHECK_RESTRICTION((uint8_t)iii < LIN_NUM_OF_IFCS);

    return lin_lld_int_disable(iii);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : l_sys_irq_restore
 * Description   : Enable LIN related IRQ.
 *
 * Implements    : l_sys_irq_restore_Activity
 *END**************************************************************************/
void l_sys_irq_restore(l_ifc_handle iii)
{
    CHECK_RESTRICTION((uint8_t)iii < LIN_NUM_OF_IFCS);

    (void)lin_lld_int_enable(iii);
}


/* *****************************************************************************
 * EOF
 ******************************************************************************/
