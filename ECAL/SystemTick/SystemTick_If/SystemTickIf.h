/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      H source file                                                            */
/*   Name         :      SystemTickIf.h                                                           */
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
#ifndef SYSTEMTICK_IF_H_
#define SYSTEMTICK_IF_H_
#include "model_Cfg_feature.h"
typedef void (* SystemTick_callback_t)(void);



typedef enum {
    SYSTEMTICK_PERIODIC_1MS             = 0x00U,
	SYSTEMTICK_PERIODIC_5MS, 
    SYSTEMTICK_PERIODIC_10MS, 
    SYSTEMTICK_PERIODIC_20MS, 
    SYSTEMTICK_PERIODIC_50MS, 
    SYSTEMTICK_PERIODIC_100MS, 
    SYSTEMTICK_PERIODIC_1000MS, 
    SYSTEMTICK_PERIODIC_LinTimeout
} SystemTick_event_id_t;


typedef struct {

    SystemTick_callback_t Periodic_1mSCallback;                   
	SystemTick_callback_t Periodic_5mSCallback; 
	SystemTick_callback_t Periodic_10mSCallback; 
	SystemTick_callback_t Periodic_20mSCallback; 
	SystemTick_callback_t Periodic_50mSCallback; 
	SystemTick_callback_t Periodic_100mSCallback; 
	SystemTick_callback_t Periodic_1000mSCallback; 
	SystemTick_callback_t Periodic_LinTimeoutCallback; 

} SystemTick_state_t;

extern void SystemTickIf_Check_Tout_Start(uint32_t Period_mS);
extern BOOL SystemTickIf_Check_Tout_Is_Tout(void);
extern void SystemTickIf_Irq_Handler(void);
extern void SystemTickIf_Init(void);
extern void SystemTickIf_DeInit(void);
extern void SystemTickIf_Timer_Irq_Handler(void);
extern void SystemTickIf_MainWhileCallHandler(void);

extern void SystemTickIf_Timer_Init(void);
extern void SystemTickIf_Timer_DeInit(void);
extern SystemTick_callback_t SystemTickIf_InstallCallback(SystemTick_event_id_t opIndex,SystemTick_callback_t function);
extern void SystemTickIf_UninstallCallback(SystemTick_event_id_t opIndex);

#endif /* SYSTEMTICK_IF_H_ */
