/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      H source file                                                            */
/*   Name         :      LIN_Trcv.h                                                               */
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
#ifndef __INCLUDE_LIN_TRANSCEIVER_H__
#define __INCLUDE_LIN_TRANSCEIVER_H__



typedef enum
{
	LIN_TRCV_MODE_STANDBY = 0,
	LIN_TRCV_MODE_NORMAL,
}LinTrcv_TrcvModeType;




extern void LinTrcv_Init(void);
extern BOOL LinTrcv_SetOpMode(LinTrcv_TrcvModeType OpMode);
extern BOOL LinTrcv_GetOpMode(LinTrcv_TrcvModeType OpMode); 



#endif
