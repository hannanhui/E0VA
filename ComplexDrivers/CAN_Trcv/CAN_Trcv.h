/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      H source file                                                            */
/*   Name         :      LIN_Trcv.h                                                               */
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
#ifndef __INCLUDE_CAN_TRANSCEIVER_H__
#define __INCLUDE_CAN_TRANSCEIVER_H__


//========= CAN Mode Define ========//
 typedef enum
 {
	 CanPhyMod_Nor = 0U, //Normal Mode
	 CanPhyMod_LiO, //ListenOnly Mode
	 CanPhyMod_Stb, //Standby Mode
	 CanPhyMod_GoTSp, //Go To Sleep Mode
	 CanPhyMod_Sp //Sleep Mode
 }CanPhyMode_t;




extern void CANTrcv_Init(void);
extern void CAN_WorkModeControl(CanPhyMode_t ModeType);



#endif
