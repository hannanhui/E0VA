/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      H source file                                                            */
/*   Name         :      WatchDogIf.h                                                             */
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
#ifndef WATCH_IF_H_
#define WATCH_IF_H_


#include "common_drv.h"
extern  void WatchDogIf_Init(void);
extern void WatchDogIf_Free(void);



extern void WatchDogIf_Disable(void);
extern void WatchDogIf_Enable(void);

START_FUNCTION_DECLARATION_RAMSECTION
void FeedWatchdog(void)
END_FUNCTION_DECLARATION_RAMSECTION



#endif /* WATCH_IF_H_ */
