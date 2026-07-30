/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      C source file                                                            */
/*   Name         :      App_MainScheduler.c                                                      */
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
#include "include.h"
#include "Dcm.h"
#include "FBL.h"

// uint32 randSeed;

void App_Main_Scheduler_Periodic_1mS_IrqCall(void)
{
	//Only count code is allowed to be stored. Keep it concise; 
	//otherwise, it will affect the system time base scheduling.
	/*************************** User Code ***************************/
	
	/*****************************************************************/
}
void App_Main_Scheduler_Periodic_1mS(void)
{
	Vehicle_Action_1mS();	
	
		FBL_MainFunction();
	
}

void App_Main_Scheduler_Periodic_5mS(void)
{
	LinIf_MainFunction();
	Dcm_MainFunction();
}

void App_Main_Scheduler_Periodic_10mS(void)
{
	
	Vehicle_Action_10mS();
}

void App_Main_Scheduler_Periodic_25mS(void)
{
	// randSeed++;
	// if(randSeed > 0xFFFFFFF)
	// {
	// 	randSeed = 0;
	// }
	// randSeed = randSeed << 16;
	// randSeed += 1000;
	// randSeed = randSeed * 2;
}


void App_Main_Scheduler_Periodic_100mS(void)
{

}

void App_Main_Scheduler_Periodic_500mS(void)
{

	
}

void App_Main_Scheduler_Periodic_1000mS(void)
{

	
}




void App_Main_Before_ResetSaveOperation(void)
{
}


void App_System_Init(void)
{
	Vehicle_Action_Init();
}

void App_System_DeInit(void)
{
	
}

void App_Setting_Before_SystemInit(void)
{
	/**/
	System_WatchDogRunEnSet(TRUE);
}





/* ************************************************************************************************/
/*                                        End Of File: SystemTimer.c                               */
/* ************************************************************************************************/

