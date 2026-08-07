/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      H source file                                                            */
/*   Name         :      Function_Logic_Valve_Access.h                                            */
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
#ifndef INCLUDE_FUNCTION_VALVE_CURVE_CONFIG_H_
#define INCLUDE_FUNCTION_VALVE_CURVE_CONFIG_H_


extern void MassageValve_Vol_Curve0_Set(void);
extern void MassageValve_Vol_Curve4_Set(void);
extern void GasStorageValve_Vol_Curve3_Set(void);
extern void GasStorageValve_Vol_Curve5_Set(void);


extern void Valve_Vol_Curve_Effect(void);

extern void Function_Valve_Curve_Init(void);


#endif /* INCLUDE_FUNCTION_MBD_VALVE_ACCESS_H_ */
