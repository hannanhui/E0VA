/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      H source file                                                            */
/*   Name         :      WatchDog_Cfg.h                                                           */
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
#ifndef WATCHDOG_CONFIG_H_
#define WATCHDOG_CONFIG_H_

#include "MCAL.h"

// 看门狗设置内部低频振荡器软件使能, 内部低频振荡器作为看门狗时钟源。
// 时钟源为32KHZ,
//32KHz/64=500Hz=2mS----->看门狗计数时基

#define  IWDT_CLOCK_SOURCE  IWDT_SCK_INTLF



//1000ms---->看门狗最长喂狗时间1S

#define  IWDT_FREE_DOG_MAX_TIMER  1000U


#endif /* WATCHDOG_CONFIG_H_ */
