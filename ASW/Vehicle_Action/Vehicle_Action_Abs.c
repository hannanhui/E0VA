/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      C source file                                                            */
/*   Name         :      Vehicle_Action_Abs.c                                                     */
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

#include "include.h"


const VEHICLE_ACTION_ABS Vehicle_Action =
{
	.Bus_Action_Init   = DC1E_Action_Init,
	.Bus_Action_Periodic_10mS = DC1E_Action_Periodic_10mS,
	.Bus_Action_Get_Key = DC1E_Action_Get_Key_Value,
	.Bus_Action_GetLinTimeoutFlag = MVP17_BusGetLinTimeOutFlag,
	.Bus_Action_Lintl_CallbackInstall = DC1E_Lintl_UseFuncListCallbackInstall

};





