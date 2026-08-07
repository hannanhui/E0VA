/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      H source file                                                            */
/*   Name         :      App_MainScheduler.h                                                      */
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
#ifndef APP_MAIN_SCHEDULER_RUN_H
#define APP_MAIN_SCHEDULER_RUN_H




extern void App_Main_Scheduler_Periodic_1mS(void);
extern void App_Main_Scheduler_Periodic_5mS(void);
extern void App_Main_Scheduler_Periodic_10mS(void);
extern void App_Main_Scheduler_Periodic_20mS(void);
extern void App_Main_Scheduler_Periodic_100mS(void);
extern void App_Main_Scheduler_Periodic_50mS(void);
extern void App_Main_Scheduler_Periodic_1000mS(void);
extern void App_Main_Before_ResetSaveOperation(void);
extern void App_System_Init(void);

extern void App_System_DeInit(void);

#endif  

