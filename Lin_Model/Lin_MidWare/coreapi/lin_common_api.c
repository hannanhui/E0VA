/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      C source file                                                            */
/*   Name         :      lin_common_api.c                                                         */
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
    lin_lld_Wakeup(iii);
}


lin_node_state_t l_ifc_get_state(l_ifc_handle iii)
{	
	lin_node_state_t ret_val;
	ret_val = lin_lld_get_state(iii);

    return ret_val;
}


/* *****************************************************************************
 * EOF
 ******************************************************************************/
