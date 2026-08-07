/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      H source file                                                            */
/*   Name         :      Scheduler.h                                                              */
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
#ifndef SCHEDULER_RUN_H
#define SCHEDULER_RUN_H


#include "Type_Define.h"

/* ************************************************************************************************/
/*                          Include common and project definition header                          */
/* ************************************************************************************************/

/* ************************************************************************************************/
/*                 Definition of exported types (typedef, enum, struct, union, define)            */
/* ************************************************************************************************/
typedef enum
{
	BOOT_MAJOR_VERSION = 0,	// Boot模式主版本号
	BOOT_MINOR_VERSION    ,	// Boot模式次版本号
	APP_MAJOR_VERSION     ,	// App模式主版本号
	APP_MINOR_VERSION		// App模式次版本号
	
}VERSION_SEL;

/* *************************************Definition of typedef**************************************/


/* ************************************************************************************************/
/*                             Declaration of exported function prototypes                        */
/* ************************************************************************************************/
extern void System_Init(void);

extern void System_DataWakeupInit(void);
extern void System_WakeupInit(void);
extern void Scheduler_ListCallbackUninstall(void);
extern void System_SwResetFlagSet(uint8_t opStatus);
extern uint8_t System_CAL_Version(VERSION_SEL Version_Sel, uint8_t* Ver);
extern void System_ResetDelayTimeSet(uint8_t data);
extern uint8_t System_ResetDelayTimeGet(void);
uint8_t System_CAL_Version(VERSION_SEL Version_Sel, uint8_t* Ver);

#endif  

/* ************************************************************************************************/
/*                                        End Of File: Scheduler.h                               */
/* ************************************************************************************************/
