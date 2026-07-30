/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      H source file                                                            */
/*   Name         :      WatchDog.h                                                               */
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
#ifndef __INCLUDE_WATCHDOG_H__
#define __INCLUDE_WATCHDOG_H__



#include "model_Cfg_feature.h"
#if CFG_MODEL == CFG_MVP13

#include "Type_Define.h"
#include "wdog_drv.h"

#include "WatchDog_Cfg\WatchDog_Cfg.h"
#include "WatchDog_If\WatchDogIf.h"
#else
#pragma message("!!! WatchDog cfg error !!!")
#endif



#endif /*__INCLUDE_WATCHDOG_H__*/
