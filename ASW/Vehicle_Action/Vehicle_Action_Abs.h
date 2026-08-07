/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      H source file                                                            */
/*   Name         :      Vehicle_Action_Abs.h                                                     */
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

#ifndef __VEHICLE_ACTION_ABS_H__
#define __VEHICLE_ACTION_ABS_H__



typedef struct
{
	// Function initialization
	void(*Bus_Action_Init)(void);
	// Periodic processing
	void(*Bus_Action_Periodic_10mS)(void);

	// Obtain key information
	void(*Bus_Action_Get_Key)(KEY_VALUE*);
	uint8_t (*Bus_Action_GetLinTimeoutFlag)(void);
	void(*Bus_Action_Lintl_CallbackInstall)(void);
}VEHICLE_ACTION_ABS;


extern const VEHICLE_ACTION_ABS Vehicle_Action;





#endif /* __VEHICLE_ACTION_ABS_H__ */


