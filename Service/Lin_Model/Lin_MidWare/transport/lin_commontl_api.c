/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      C source file                                                            */
/*   Name         :      lin_commontl_api.c                                                       */
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


#include "include.h"

/* *****************************************************************************
 * Variables
 ******************************************************************************/

/* *****************************************************************************
 * Code
 ******************************************************************************/
/*FUNCTION**********************************************************************
 *
 * Function Name : ld_init
 * Description   : Initialize or reinitialize the raw and cooked layers  on the interface iii.
 * All the transport layer buffers will be initialized.
 *
 * Implements    : ld_init_Activity
 *END**************************************************************************/
void ld_init(l_ifc_handle iii)
{
    CHECK_RESTRICTION((uint8_t)iii < LIN_NUM_OF_IFCS);
    lin_tl_init(iii);
}

commontl_callback_t ld_InstallCallback(Lin_commontl_proto_callback_type_t opIndex,commontl_callback_t function)
{
    commontl_callback_t retVal = NULL;

    retVal = lin_tl_InstallCallback(opIndex, function);

    return retVal;
}
commontl_callback_Param_t ld_ApplyIdInstallCallback(Lin_commontl_proto_callback_type_t opIndex,commontl_callback_Param_t function)
{
    commontl_callback_Param_t retVal = NULL;

    retVal = lin_tl_ApplyIdInstallCallback(opIndex, function);

    return retVal;
}



/* *****************************************************************************
 * EOF
 ******************************************************************************/
