/*
 * Os.h
 *
 *  Created on: 2019Äê5ÔÂ30ÈÕ
 *      Author: Administrator
 */

#ifndef SOURCE_COMMONINCLUDE_OS_H_
#define SOURCE_COMMONINCLUDE_OS_H_
#include "Std_Types.h"

//typedef uint8 Mcu_ModeType;
//typedef uint8 Mcu_ResetType;
typedef uint32 TickType;

//#define DisableAllInterrupts() ///INT_All_Enable (FALSE); //__asm("cpsid i")
//#define EnableAllInterrupts() //INT_All_Enable (TRUE); //__asm("dsb\n cpsie i\n")

//#define SuspendAllInterrupts() //INT_All_Enable (FALSE);
//#define ResumeAllInterrupts() //INT_All_Enable (TRUE);

//#define ISR(IsrName)       void IsrName(void)   /* FIXME, by wjj, 20201004 */


#define GetCoreID()

//#define GetResource(x)
//#define ReleaseResource(x)

//#define Mcu_SetMode(x)

#define StartOS(x)          //EcuM_StartupTwo();
//#define ShutdownOS(x)           EcuM_Shutdown();

#define OS_CORE_ID_0                0
#define OSDEFAULTAPPMODE            1u
#define OsResource_0                0u
#define RES_SCHEDULER_CORE0         0
#define OS_AUTOSAR_CORES            1u

//typedef uint16          CoreIdType;
typedef uint16          AppModeType;
typedef uint16          ResourceType;
typedef uint16          ApplicationType;
typedef uint16          Os_AppModeType;

uint16 GetResource(uint16 x);
uint16 ReleaseResource(uint16 x);
void ShutdownOS(StatusType Error);

#endif /* SOURCE_COMMONINCLUDE_OS_H_ */


