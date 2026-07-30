/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      H source file                                                            */
/*   Name         :      SystemTick_Cfg.h                                                         */
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
#ifndef SYSTEMTICK_CFG_H_
#define SYSTEMTICK_CFG_H_





//Set the period of the system tick timer (unit: uS). This parameter does not need to be changed
#define System_Tick_uS	(1000U)




//定时器配置
#define TIMER_USE_SFR		T14_SFR
#define TIMER_USE_INT   	INT_T14





#define TIMER_IRQ_IS_USE_T14       1

#define TIMER_IRQ_USE_DEFINE  TIMER_IRQ_IS_USE_T14
//系统时钟96M为例，96000000/96 = 1000000,计数一次1uS，最大周期为65mS
#define TIMER_CLKFREQ_DIVISION    ((SYSTEM_CORE_FREQ_HZ/1000000U) -1)			//95+1

#define Timer_period_uS	(500U)







#endif /* _SYSTEMTICK_CFG_H_ */
