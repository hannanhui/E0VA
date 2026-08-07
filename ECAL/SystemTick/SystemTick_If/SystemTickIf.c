/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      C source file                                                            */
/*   Name         :      SystemTickIf.c                                                           */
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
#include "model_Cfg_feature.h"
#include "Platform.h"
#include "Gpt.h"
#include "Ecal_SystemTick.h"



static uint32_t System_Tick_1mS_Cnt; 		
static uint32_t System_Tick_Period_Cnt;
static uint32 System_Tick_5msTick = 1;
static uint32 System_Tick_10msTick = 3;
static uint32 System_Tick_20msTick = 5 ;
static uint32 System_Tick_50msTick = 7;
static uint32 System_Tick_100msTick = 9;
static uint32 System_Tick_1000msTick = 11;


#define System_Tick_5msCnt       5uL
#define System_Tick_10msCnt      10uL
#define System_Tick_20msCnt      20uL
#define System_Tick_50msCnt      50uL
#define System_Tick_100msCnt     100uL
#define System_Tick_1000msCnt    1000uL


static SystemTick_state_t s_SystemTick_state_array[1];  

SystemTick_state_t * g_SystemTickStatePtr[1] = {NULL};

//static uint32_t Delay_mS_Count = 0;




void SystemTickIf_Irq_Handler(void)
{
	if (System_Tick_1mS_Cnt < uint32_t_MAX)
	{
		System_Tick_1mS_Cnt++;
	}

}



static void SystemTickIf_Hw_Drv_Init(void)
{
	Gpt_Init(NULL_PTR);
    Gpt_EnableNotification(3u);
    /* Counter clock is 48M, target value = 48000, period = 1ms*/
    Gpt_StartTimer(3u, 48000u);

}



void SystemTickIf_Init(void)
{
	System_Tick_1mS_Cnt = 0;
	System_Tick_Period_Cnt = 0;
	System_Tick_5msTick = 1;
	System_Tick_10msTick = 3;
	System_Tick_20msTick = 5 ;
	System_Tick_50msTick = 7;
	System_Tick_100msTick = 9;
	System_Tick_1000msTick = 11;
	SystemTickIf_Hw_Drv_Init();
	g_SystemTickStatePtr[0] = &s_SystemTick_state_array[0];
}
void SystemTickIf_DeInit(void)
{
	System_Tick_1mS_Cnt = 0;
	System_Tick_Period_Cnt = 0;
	System_Tick_5msTick = 1;
	System_Tick_10msTick = 3;
	System_Tick_20msTick = 5 ;
	System_Tick_50msTick = 7;
	System_Tick_100msTick = 9;
	System_Tick_1000msTick = 11;
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
		System_Tick_1mS_Cnt--;
		//System_Tick_Period_Cnt++;
		if (SystemTickCurrentState->Periodic_1mSCallback != NULL)
	    {
	        SystemTickCurrentState->Periodic_1mSCallback();
	    }
		System_Tick_5msTick++;
		if(System_Tick_5msTick >= System_Tick_5msCnt)
		{
			if (SystemTickCurrentState->Periodic_5mSCallback != NULL)
		    {
		        SystemTickCurrentState->Periodic_5mSCallback();
		    }
			System_Tick_5msTick =0;
		}
		System_Tick_10msTick++;
		if(System_Tick_10msTick >= System_Tick_10msCnt)
		{
			if (SystemTickCurrentState->Periodic_10mSCallback != NULL)
		    {
		       SystemTickCurrentState->Periodic_10mSCallback();
		    }
			System_Tick_10msTick =0;
		}
		System_Tick_20msTick++;
		if(System_Tick_20msTick >= System_Tick_20msCnt)
		{
			if (SystemTickCurrentState->Periodic_20mSCallback != NULL)
		    {
		      SystemTickCurrentState->Periodic_20mSCallback();
		    }
			System_Tick_20msTick =0;
		}
		System_Tick_50msTick++;
		if(System_Tick_50msTick >= System_Tick_50msCnt)
		{
			if (SystemTickCurrentState->Periodic_50mSCallback != NULL)
		    {
		       SystemTickCurrentState->Periodic_50mSCallback();
		    }
			System_Tick_50msTick =0;
		}
		System_Tick_100msTick++;
		if(System_Tick_100msTick >= System_Tick_100msCnt)
		{
			if (SystemTickCurrentState->Periodic_100mSCallback != NULL)
		    {
		       SystemTickCurrentState->Periodic_100mSCallback();
		    }
			System_Tick_100msTick=0;
		}
		
		System_Tick_1000msTick++;
		if(System_Tick_1000msTick >= System_Tick_1000msCnt)
		{
			if (SystemTickCurrentState->Periodic_1000mSCallback != NULL)
		    {
		      SystemTickCurrentState->Periodic_1000mSCallback();
		    }

			System_Tick_1000msTick = 0;
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
    if (SystemTickCurrentState->Periodic_LinTimeoutCallback != NULL)
    {
        SystemTickCurrentState->Periodic_LinTimeoutCallback();
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
		case SYSTEMTICK_PERIODIC_20MS:
			/* Uninstall callback function. */
			SystemTickCurrentState->Periodic_20mSCallback = NULL;
		
		break;
		case SYSTEMTICK_PERIODIC_50MS:
			/* Uninstall callback function. */
			SystemTickCurrentState->Periodic_50mSCallback = NULL;
		
		break;
		case SYSTEMTICK_PERIODIC_100MS:
			/* Uninstall callback function. */
			SystemTickCurrentState->Periodic_100mSCallback = NULL;
		
		break;
		
		case SYSTEMTICK_PERIODIC_1000MS:
			/* Uninstall callback function. */
			SystemTickCurrentState->Periodic_1000mSCallback = NULL;
		
		break;
		case SYSTEMTICK_PERIODIC_LinTimeout:
			/* Uninstall callback function. */
			SystemTickCurrentState->Periodic_LinTimeoutCallback = NULL;
		
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
			case SYSTEMTICK_PERIODIC_20MS:
				/* Get the current callback function. */
				currentCallback= SystemTickCurrentState->Periodic_20mSCallback;
				/* Install new callback function. */
				SystemTickCurrentState->Periodic_20mSCallback = function;
			
			break;
			case SYSTEMTICK_PERIODIC_50MS:
				/* Get the current callback function. */
				currentCallback= SystemTickCurrentState->Periodic_50mSCallback;
				/* Install new callback function. */
				SystemTickCurrentState->Periodic_50mSCallback = function;
			
			break;
			case SYSTEMTICK_PERIODIC_100MS:
				/* Get the current callback function. */
				currentCallback= SystemTickCurrentState->Periodic_100mSCallback;
				/* Install new callback function. */
				SystemTickCurrentState->Periodic_100mSCallback = function;
			
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

void GptNotification_1ms(void)
{
	SystemTickIf_Irq_Handler();
}

