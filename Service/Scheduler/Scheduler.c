/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      C source file                                                            */
/*   Name         :      Scheduler.c                                                              */
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


static uint8_t SystemResetFlag =0u;
static uint8_t SystemResetTimeCount = 0;

static uint8_t SystemResetDelayTime = T10_500MS;
static uint8_t WatchDogRunEn =TRUE;


void System_SwResetFlagSet(uint8_t opStatus)
{
	SystemResetFlag = opStatus;
}
void System_ResetDelayTimeSet(uint8_t data)
{
	SystemResetDelayTime = data;
}

uint8_t System_ResetDelayTimeGet(void)
{
	return SystemResetDelayTime;
}

void System_ResetMonitor(void)
{
	if(SystemResetFlag)
	{
		if(++SystemResetTimeCount >= SystemResetDelayTime)
		{
			System_Reset();
		}
	}
}


void System_WatchDogRunEnSet(uint8_t opStatus)
{
	WatchDogRunEn = opStatus;
}

uint8_t System_WatchDogRunEnGet(void)
{
	return WatchDogRunEn;
}



static void Scheduler_Periodic_1mS_IrqCall(void)
{
	App_Main_Scheduler_Periodic_1mS_IrqCall();
}

static void Scheduler_Periodic_1mS(void)
{
	App_Main_Scheduler_Periodic_1mS();
}
static void Scheduler_Periodic_5mS(void)
{
	App_Main_Scheduler_Periodic_5mS();
	

}

static void Scheduler_Periodic_10mS(void)
{

	PowerApp_10mS_PeriodicDetectProc();
	App_Main_Scheduler_Periodic_10mS();
	System_ResetMonitor();
	
	
}

static void Scheduler_Periodic_25mS(void)
{
	if(TRUE == System_WatchDogRunEnGet())
	{
		WatchDogIf_Free();	
	}
	App_Main_Scheduler_Periodic_25mS();
	
	

}


static void Scheduler_Periodic_100mS(void)
{
	PowerApp_100mS_PeriodicDetectProc();
	App_Main_Scheduler_Periodic_100mS();
	
	
}

static void Scheduler_Periodic_500mS(void)
{

	App_Main_Scheduler_Periodic_500mS();
}


static void Scheduler_Periodic_1000mS(void)
{

	App_Main_Scheduler_Periodic_1000mS();

}

static void Scheduler_LIN_Timeout_Handler(void)
{

	/* Timer Interrupt Handler */
   // l_lld_timeout_service_LI0();
}




static void Scheduler_ListCallbackInstall(void)
{
	SystemTickIf_InstallCallback(SYSTEMTICK_PERIODIC_1MS,Scheduler_Periodic_1mS);
	SystemTickIf_InstallCallback(SYSTEMTICK_PERIODIC_5MS,Scheduler_Periodic_5mS);
	SystemTickIf_InstallCallback(SYSTEMTICK_PERIODIC_10MS,Scheduler_Periodic_10mS);
	SystemTickIf_InstallCallback(SYSTEMTICK_PERIODIC_25MS,Scheduler_Periodic_25mS);
	SystemTickIf_InstallCallback(SYSTEMTICK_PERIODIC_100MS,Scheduler_Periodic_100mS);
	SystemTickIf_InstallCallback(SYSTEMTICK_PERIODIC_500MS,Scheduler_Periodic_500mS);
	SystemTickIf_InstallCallback(SYSTEMTICK_PERIODIC_1000MS,Scheduler_Periodic_1000mS);
	SystemTickIf_InstallCallback(SYSTEMTICK_PERIODIC_LinTimeout,Scheduler_LIN_Timeout_Handler);
	
	SystemTickIf_InstallCallback(SYSTEMTICK_PERIODIC_1MS_IrqCall,Scheduler_Periodic_1mS_IrqCall);
	
	
}
void Scheduler_ListCallbackUninstall(void)
{
	SystemTickIf_UninstallCallback(SYSTEMTICK_PERIODIC_1MS);
	SystemTickIf_UninstallCallback(SYSTEMTICK_PERIODIC_5MS);
	SystemTickIf_UninstallCallback(SYSTEMTICK_PERIODIC_10MS);
	SystemTickIf_UninstallCallback(SYSTEMTICK_PERIODIC_25MS);
	SystemTickIf_UninstallCallback(SYSTEMTICK_PERIODIC_100MS);
	SystemTickIf_UninstallCallback(SYSTEMTICK_PERIODIC_500MS);
	SystemTickIf_UninstallCallback(SYSTEMTICK_PERIODIC_1000MS);
	SystemTickIf_UninstallCallback(SYSTEMTICK_PERIODIC_LinTimeout);
	SystemTickIf_UninstallCallback(SYSTEMTICK_PERIODIC_1MS_IrqCall);
}



static void System_HwInit(void)
{
	
	INT_All_Enable(FALSE);
	App_Setting_Before_SystemInit();
	if(TRUE == System_WatchDogRunEnGet())
	{
		#if DEBUG_APPLICATION_ENABLE
		WatchDogIf_Free();	
		WatchDogIf_Disable();
		#else
			#if WATCHDOG_FUNC_EN
			WatchDogIf_Free();		
			WatchDogIf_Init();
			WatchDogIf_Enable();
			#endif
		
		#endif
	}
	CLOCK_Init();
	MCU_GPIO_SetWorkMode(E_PORT_IF_IOWORK_MODE_RUNING);
	SystemMode_WakeupPinDisable_Config();
	SystemTickIf_Init();
	Scheduler_ListCallbackInstall();
	#if LIN_FUNCTION_USE_EN
	SystemTickIf_Timer_Init();
	//l_ifc_ld_init_LI0();
	LinTrcv_Init();
	LinTrcv_SetOpMode(LIN_TRCV_MODE_NORMAL);



	l_ifc_init_LI0();
	#endif
	FlashInit();
	INT_All_Enable(TRUE);

}





static void System_SwInit(void)
{
	SystemMode_CheckResetSrc();
	App_System_Init();
	System_Running_Init();
	PowerApp_Init();

}
void System_DataWakeupInit(void)
{
	//The system is initialized and does not sleep until the set time is reached
}




void System_WakeupInit(void)
{
	INT_All_Enable(FALSE);
	App_Setting_Before_SystemInit();
	if(TRUE == System_WatchDogRunEnGet())
	{
		#if DEBUG_APPLICATION_ENABLE
		WatchDogIf_Free();	
		WatchDogIf_Disable();
		#else
			#if WATCHDOG_FUNC_EN
			WatchDogIf_Free();		
			WatchDogIf_Init();
			WatchDogIf_Enable();
			#endif
		
		#endif
	}
	//CLOCK_Init();
	MCU_GPIO_SetWorkMode(E_PORT_IF_IOWORK_MODE_RUNING);

	SystemTickIf_Init();
	Scheduler_ListCallbackInstall();
	#if LIN_FUNCTION_USE_EN
	SystemTickIf_Timer_Init();
	l_ifc_ld_init_LI0();
	LinTrcv_Init();
	LinTrcv_SetOpMode(LIN_TRCV_MODE_NORMAL);



	l_ifc_init_LI0();
	#endif

	INT_All_Enable(TRUE);
	//DigitalIf_IoWt_DataSet(Digital_IoWt_Index1,TRUE);
	//SystemMode_CheckResetSrc();
	//DigitalIf_Init();
	App_System_Init();
	System_Running_Init();
	PowerApp_Init();

}
void System_Init(void)
{
	System_HwInit();
	System_SwInit();
}

void System_DeInit(void)
{
	App_System_DeInit();
}

uint8_t System_CAL_Version(VERSION_SEL Version_Sel, uint8_t* Ver)
{
	uint32_t Ver_Addr; 					
	uint8_t Temp;
	BOOL  Success = TRUE;
	uint8_t *ptr;

	if (APP_MAJOR_VERSION == Version_Sel)
	{
		Ver_Addr = ApplicationAddress + INTERRUPT_VECTOR_TABLE_SIZE;
		ptr = (uint8_t *) Ver_Addr;
	}
	else if (APP_MINOR_VERSION == Version_Sel)
	{
		Ver_Addr = ApplicationAddress + INTERRUPT_VECTOR_TABLE_SIZE+VERSION_INFO_MAX_SIZE;
		ptr = (uint8_t *) Ver_Addr;
	}
	else if (BOOT_MAJOR_VERSION == Version_Sel)
	{
		Ver_Addr = BootLoderAddress + INTERRUPT_VECTOR_TABLE_SIZE;
		ptr = (uint8_t *) Ver_Addr;
	}
	else if (BOOT_MINOR_VERSION == Version_Sel)
	{
		Ver_Addr = BootLoderAddress + INTERRUPT_VECTOR_TABLE_SIZE+VERSION_INFO_MAX_SIZE;
		ptr = (uint8_t *) Ver_Addr;
	}
	else
	{
		Success = FALSE;
	}
	if(Success)
	{
		// 读取版本号
		for (uint8_t i=0; i< VERSION_INFO_MAX_SIZE; i++)
		{
			Temp = *(uint8_t*)(ptr + i);

			if (Temp)
			{
				if ((0x20 <= Temp) && (Temp <= 0x7E))
				{
					Ver[i] = Temp;
				}
				else
				{
					Success = FALSE;
					break;
				}
			}
			else	// 版本数据结束
			{
				if (i==0)
				{
					Success = FALSE;
				}
				break;
			}
		}
	}
	return Success;
}

/* ************************************************************************************************/
/*                                        End Of File: SystemTimer.c                               */
/* ************************************************************************************************/

