/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      C source file                                                            */
/*   Name         :      SystemTickIf.c                                                           */
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



static uint32_t System_Tick_1mS_Cnt; 		
static uint32_t System_Tick_Period_Cnt;


static SystemTick_state_t s_SystemTick_state_array[1];  

static uint32_t System_Check_Tout_Call_Cnt;
static uint32_t System_Check_Tout_1mS_Cnt;
SystemTick_state_t * g_SystemTickStatePtr[1] = {NULL};

//static uint32_t Delay_mS_Count = 0;

//-------------------------------------------STIM---------------------------------
/* STIM configuration */
const STIM_Config_t stimConfig = 
{
    .workMode = STIM_FREE_COUNT,              /* stim work mode */
    .compareValue = 8000,                    /* counter clock is 40M, compare value =40000,  period = 1ms*/
    .countResetMode = STIM_INCREASE_FROM_0,   /* stim counter reset and increaments from 0 when counter match */
    .clockSource = STIM_FUNCTION_CLOCK,       /* Select stim function clock as counter system clock */
};

static void SystemTickIf_Check_Tout_1mS_Irq(void)
{
	if (System_Check_Tout_1mS_Cnt>0U)
	{
		System_Check_Tout_1mS_Cnt--;
	}
}

void SystemTickIf_Check_Tout_Start(uint32_t Period_mS)
{
	System_Check_Tout_1mS_Cnt = Period_mS;

	if (Period_mS == 0U)
	{
		System_Check_Tout_Call_Cnt = 0;
	}
	else if (Period_mS < 1U)
	{
		System_Check_Tout_Call_Cnt = AT_96MHZ_1mS_LOOP_COUNT;
	}
	else
	{
		System_Check_Tout_Call_Cnt = AT_96MHZ_1mS_LOOP_COUNT*Period_mS;
	}
}

BOOL SystemTickIf_Check_Tout_Is_Tout(void)
{
	BOOL RetVal = FALSE;
	// The periodic timeout judgment is performed first
	if (0u == System_Check_Tout_1mS_Cnt)
	{
		RetVal =  TRUE;
	}

	//The second count is timed out
	if (System_Check_Tout_Call_Cnt>0U)
	{
		System_Check_Tout_Call_Cnt--;
	}
	if (0u == System_Check_Tout_Call_Cnt)
	{
		RetVal =  TRUE;
	}

	return RetVal;
}


void SystemTickIf_Irq_Handler(void)
{
	SystemTick_state_t * SystemTickCurrentState = g_SystemTickStatePtr[0];
	//SYSTICK_Counter_Updata();
	if (System_Tick_1mS_Cnt < uint32_t_MAX)
	{
		System_Tick_1mS_Cnt++;
	}
	if (SystemTickCurrentState->Periodic_1mS_IrqCall_Callback != NULL)
    {
        SystemTickCurrentState->Periodic_1mS_IrqCall_Callback();
    }
	if (SystemTickCurrentState->Periodic_LinTimeoutCallback != NULL)
    {
        SystemTickCurrentState->Periodic_LinTimeoutCallback();
    }
	SystemTickIf_Check_Tout_1mS_Irq();
}



static void SystemTickIf_Hw_Drv_Init(void)
{


	uint32_t Reload = SYSTEM_CORE_FREQ_HZ;
	Reload /= 1000000;
	Reload *= System_Tick_uS;

	if(Reload > 0xFFFFFF)
	{
		//System_Check_Failed();
	}
	/* Configure STIM function clock*/
	   CLK_ModuleSrc(CLK_STIM, CLK_SRC_OSC40M);
	   CLK_SetClkDivider(CLK_STIM, CLK_DIV_1);
	
	   /* Enable STIM module */
	   SYSCTRL_EnableModule(SYSCTRL_STIM);
	
	   /* Init STIM_0*/
	   STIM_Init(STIM_0,&stimConfig);
	
	   /* Install interrupt callback function */
	   STIM_InstallCallBackFunc(STIM_0,STIM_INT,SystemTickIf_Irq_Handler);
	   /* Enable STIM_0 interrupt*/
	   STIM_IntCmd(STIM_0, ENABLE);
	
	   /* Enable STIM NVIC IRQ*/
	   INT_EnableIRQ(STIM_IRQn);


}



void SystemTickIf_Init(void)
{
	System_Tick_1mS_Cnt = 0;
	System_Tick_Period_Cnt = 0;
	SystemTickIf_Hw_Drv_Init();
	g_SystemTickStatePtr[0] = &s_SystemTick_state_array[0];
	STIM_Enable(STIM_0);
}
void SystemTickIf_DeInit(void)
{
	System_Tick_1mS_Cnt = 0;
	System_Tick_Period_Cnt = 0;
}



void SystemTickIf_MainWhileCallHandler(void)
{
	/* Callback to handle timeout Counter flag */
	SystemTick_state_t * SystemTickCurrentState = g_SystemTickStatePtr[0];
    
	if (0u == System_Tick_1mS_Cnt)
	{
		//return;
	}
	else
	{
		System_Tick_1mS_Cnt=0;
		System_Tick_Period_Cnt++;
		if (SystemTickCurrentState->Periodic_1mSCallback != NULL)
	    {
	        SystemTickCurrentState->Periodic_1mSCallback();
	    }
		if((System_Tick_Period_Cnt % 5U) == 0U)
		{
			if (SystemTickCurrentState->Periodic_5mSCallback != NULL)
		    {
		        SystemTickCurrentState->Periodic_5mSCallback();
		    }
		}
		if((System_Tick_Period_Cnt % 10U) == 0U)
		{
			if (SystemTickCurrentState->Periodic_10mSCallback != NULL)
		    {
		        SystemTickCurrentState->Periodic_10mSCallback();
		    }
		}
		if((System_Tick_Period_Cnt % 25U) == 0U)
		{
			if (SystemTickCurrentState->Periodic_25mSCallback != NULL)
		    {
		        SystemTickCurrentState->Periodic_25mSCallback();
		    }
		}
		if((System_Tick_Period_Cnt % 100U) == 0U)
		{
			if (SystemTickCurrentState->Periodic_100mSCallback != NULL)
		    {
		        SystemTickCurrentState->Periodic_100mSCallback();
		    }
		}
		if((System_Tick_Period_Cnt % 500U) == 0U)
		{
			if (SystemTickCurrentState->Periodic_500mSCallback != NULL)
		    {
		        SystemTickCurrentState->Periodic_500mSCallback();
		    }
		}
		if((System_Tick_Period_Cnt % 1000U) == 0U)
		{
			if (SystemTickCurrentState->Periodic_1000mSCallback != NULL)
		    {
		        SystemTickCurrentState->Periodic_1000mSCallback();
		    }

			System_Tick_Period_Cnt = 0;
		}
	}
}



void SystemTickIf_Timer_Init(void)
{

}
void SystemTickIf_Timer_DeInit(void)
{
}


void SystemTickIf_Timer_Irq_Handler(void)
{

	/* Callback to handle timeout Counter flag */
	SystemTick_state_t * SystemTickCurrentState = g_SystemTickStatePtr[0];

   // if (SystemTickCurrentState->Periodic_LinTimeoutCallback != NULL)
    {
  //      SystemTickCurrentState->Periodic_LinTimeoutCallback();
    }
	//SystemTick_Cfg_Abs.SystemTickTimer_Lin_TimeoutHandler();
}
void SystemTickIf_DRV_UninstallCallback(SystemTick_event_id_t opIndex)
{
	SystemTick_state_t * SystemTickCurrentState = g_SystemTickStatePtr[0];
	switch(opIndex)
	{
		case SYSTEMTICK_PERIODIC_1MS:
			/* Uninstall callback function. */
			SystemTickCurrentState->Periodic_1mSCallback = NULL;
		break;
		case SYSTEMTICK_PERIODIC_5MS:
			SystemTickCurrentState->Periodic_5mSCallback = NULL;
		break;
		case SYSTEMTICK_PERIODIC_10MS:

			/* Uninstall callback function. */
			SystemTickCurrentState->Periodic_10mSCallback = NULL;
		
		break;
		case SYSTEMTICK_PERIODIC_25MS:
			/* Uninstall callback function. */
			SystemTickCurrentState->Periodic_25mSCallback = NULL;
		
		break;
		case SYSTEMTICK_PERIODIC_100MS:
			/* Uninstall callback function. */
			SystemTickCurrentState->Periodic_100mSCallback = NULL;
		
		break;
		case SYSTEMTICK_PERIODIC_500MS:
			/* Uninstall callback function. */
			SystemTickCurrentState->Periodic_500mSCallback = NULL;
		
		break;
		case SYSTEMTICK_PERIODIC_1000MS:
			/* Uninstall callback function. */
			SystemTickCurrentState->Periodic_1000mSCallback = NULL;
		
		break;
		case SYSTEMTICK_PERIODIC_LinTimeout:
			/* Uninstall callback function. */
			SystemTickCurrentState->Periodic_LinTimeoutCallback = NULL;
		
		break;
		case SYSTEMTICK_PERIODIC_1MS_IrqCall:
			/* Install new callback function. */
			SystemTickCurrentState->Periodic_1mS_IrqCall_Callback = NULL;
			
			break;
		default:
		
		break;
	}
}

/*FUNCTION**********************************************************************
 *
 * Function Name : LIN_LPUART_DRV_InstallCallback
 * Description   : This function installs the callback function that is used for LIN_LPUART_DRV_IRQHandler.
 * Pass in Null pointer as callback will uninstall.
 *
 * Implements    : LIN_LPUART_DRV_InstallCallback_Activity
 *END**************************************************************************/
SystemTick_callback_t SystemTickIf_DRV_InstallCallback(SystemTick_event_id_t opIndex,SystemTick_callback_t function)
{
	SystemTick_state_t * SystemTickCurrentState = g_SystemTickStatePtr[0];

    
    SystemTick_callback_t currentCallback;

    
		switch(opIndex)
		{
			case SYSTEMTICK_PERIODIC_1MS:
				/* Get the current callback function. */
				currentCallback= SystemTickCurrentState->Periodic_1mSCallback;
				/* Install new callback function. */
				SystemTickCurrentState->Periodic_1mSCallback = function;
			break;
			case SYSTEMTICK_PERIODIC_5MS:
				currentCallback= SystemTickCurrentState->Periodic_5mSCallback;
				SystemTickCurrentState->Periodic_5mSCallback = function;
			break;
			case SYSTEMTICK_PERIODIC_10MS:
				/* Get the current callback function. */
				currentCallback= SystemTickCurrentState->Periodic_10mSCallback;
				/* Install new callback function. */
				SystemTickCurrentState->Periodic_10mSCallback = function;
			
			break;
			case SYSTEMTICK_PERIODIC_25MS:
				/* Get the current callback function. */
				currentCallback= SystemTickCurrentState->Periodic_25mSCallback;
				/* Install new callback function. */
				SystemTickCurrentState->Periodic_25mSCallback = function;
			
			break;
			case SYSTEMTICK_PERIODIC_100MS:
				/* Get the current callback function. */
				currentCallback= SystemTickCurrentState->Periodic_100mSCallback;
				/* Install new callback function. */
				SystemTickCurrentState->Periodic_100mSCallback = function;
			
			break;
			case SYSTEMTICK_PERIODIC_500MS:
				/* Get the current callback function. */
				currentCallback= SystemTickCurrentState->Periodic_500mSCallback;
				/* Install new callback function. */
				SystemTickCurrentState->Periodic_500mSCallback = function;
			
			break;
			case SYSTEMTICK_PERIODIC_1000MS:
				/* Get the current callback function. */
				currentCallback= SystemTickCurrentState->Periodic_1000mSCallback;
				/* Install new callback function. */
				SystemTickCurrentState->Periodic_1000mSCallback = function;
			
			break;
			case SYSTEMTICK_PERIODIC_LinTimeout:
				/* Get the current callback function. */
				currentCallback= SystemTickCurrentState->Periodic_LinTimeoutCallback;
				/* Install new callback function. */
				SystemTickCurrentState->Periodic_LinTimeoutCallback = function;
			
			break;
			case SYSTEMTICK_PERIODIC_1MS_IrqCall:
				/* Get the current callback function. */
				currentCallback= SystemTickCurrentState->Periodic_1mS_IrqCall_Callback;
				/* Install new callback function. */
				SystemTickCurrentState->Periodic_1mS_IrqCall_Callback = function;
			
			break;
			default:
			
			break;
		}

    

    return currentCallback;
}

void SystemTickIf_UninstallCallback(SystemTick_event_id_t opIndex)
{
	SystemTickIf_DRV_UninstallCallback(opIndex);
}


SystemTick_callback_t SystemTickIf_InstallCallback(SystemTick_event_id_t opIndex,SystemTick_callback_t function)
{
    SystemTick_callback_t retVal = NULL;

    retVal = SystemTickIf_DRV_InstallCallback(opIndex, function);

    return retVal;
}


