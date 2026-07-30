/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      C source file                                                            */
/*   Name         :      PowerApp.c                                                               */
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
#define POWER_APP_ROOT

#include "include.h"
static volatile uint32_t UnSleep_Flag;	// System sleep flag When UnSleep_Flag is 0, the system sleeps


POWER_MANAGER_STRUCT Power;
#ifndef POWER_ON_START_INTERVAL
#define POWER_ON_START_INTERVAL    T10_200MS
#endif
#define POWER_OFF_WAIT_TIMEOUT    T10_50MS

//The system needs to run this macro for a minimum amount of time before it enters sleep mode



// System operation counter
uint16_t Running_Tick_100mS=0;
uint8_t Pow_Voltage_State;
BAT_VOL_STATE Bat_Vol_State;		//Battery voltage status Undervoltage/Normal/Overvoltage
POWER_MODE  Ign_Line_Power_Mode;	// Ignition state OFF/ON(IGN line detection)
POWER_MODE	LIN_Bus_Power_Mode;		// Ignition state OFF/ACC/ON/CRANK(LIN Bus)



/*******************************************************************************
*Name        : System_Sleep_Event_Set
*Function    : Set hibernation event
*argument    : Event - Indicates the current event that can be hibernated
*Retval      : NONE
*explain     : When all events can sleep, the system enters sleep mode
*******************************************************************************/
void System_Sleep_Event_Set(SYSTEM_SLEEP_EVENT Event)
{
	UnSleep_Flag &=~ ((uint32_t)1 << Event);
}

/*******************************************************************************
*Name        : System_Sleep_Event_Clear
*Function    : Clearhibernation event
*argument    : Event - The current event that cannot be hibernated
*Retval      : NONE
*explain     : If an event cannot be hibernated, 
*			   the system exits the hibernation mode
*******************************************************************************/

void System_Sleep_Event_Clear(SYSTEM_SLEEP_EVENT Event)
{
	UnSleep_Flag |= (uint32_t)1 << Event;
}


/*******************************************************************************
*Name        : System_Running_Init
*Function    : System Running Init
*argument    : NONE
*Retval      : NONE
*explain     : NONE
*******************************************************************************/

void System_Running_Init(void)
{
	Running_Tick_100mS = 0;
	System_Sleep_Event_Clear(RUNNING_TOUT_EVENT);
}

/*******************************************************************************
*Name        : System_Running_Periodic_100mS
*Function    : Process the system running cycle
*argument    : NONE
*Retval      : NONE
*explain     : NONE
*******************************************************************************/

void System_Running_Periodic_100mS(void)
{
	if (Running_Tick_100mS <= RUNNING_TICK_100MS_COUNT)
	{
		Running_Tick_100mS++;
	}
	else
	{
		System_Sleep_Event_Set(RUNNING_TOUT_EVENT);
	}
}

/*******************************************************************************
*Name        : PowerAppTimeProc
*Function    : power module all counters add and subtract scheduling
*argument    : NONE
*Retval      : NONE
*explain     : NONE
*******************************************************************************/

void PowerAppTimeProc(void)
{
	if (Power.WaitTimer!=0xffff)
	{
	   Power.WaitTimer++;	   
	}
}

/*******************************************************************************
*Name        : PowerApp_ModelPowerOnCustomer
*Function    : Power modules are powered on in a unified manner
*argument    : NONE
*Retval      : NONE
*explain     : NONE
*******************************************************************************/

void PowerApp_ModelPowerOnCustomer(void)
{
	
	Power.MainPowerState = POWER_SYS_RUNNING;
	
}

/*******************************************************************************
*Name        : PowerApp_Batt_Detect_Enable
*Function    : Batt detects the enable function
*argument    : En -Enable or disable batt+ detects
*Retval      : NONE
*explain     : NONE
*******************************************************************************/

void PowerApp_Batt_Detect_Enable(uint8_t En)
{
    if(En == true)
    {
        //DigitalIf_IoWt_DataSet(Digital_IoWt_Index3,TRUE);
    }
	else
    {
        //DigitalIf_IoWt_DataSet(Digital_IoWt_Index3,FALSE);
    }
}

/*******************************************************************************
*Name        : PowerApp_ModelPowerOffCustomer
*Function    : Power modules are powered off in a unified manner
*argument    : NONE
*Retval      : NONE
*explain     : NONE
*******************************************************************************/

void PowerApp_ModelPowerOffCustomer(void)
{
	INT_All_Enable(DISABLE);
	MCU_GPIO_SetWorkMode(E_PORT_IF_IOWORK_MODE_SLEEP);
	//SystemTickIf_DeInit();
	#if LIN_FUNCTION_USE_EN
	//SystemTickIf_Timer_DeInit();
	
	#endif
	LinTrcv_SetOpMode(LIN_TRCV_MODE_STANDBY);
	Scheduler_ListCallbackUninstall();
	
	//ADCIf_DeInit();
	//l_ifc_ld_init_LI0();
	
	//LinTrcv_Init();
	
	
	//l_ifc_init_LI0();
	PowerApp_Batt_Detect_Enable(FALSE);
//	DigitalIf_IoWt_DataSet(Digital_IoWt_Index1,FALSE);
	//DigitalIf_IoWt_DataSet(Digital_IoWt_Index2,FALSE);
	INT_All_Enable(ENABLE);

}




/*******************************************************************************
*Name        : PowerApp_Voltage_100mS_Periodic_Detect
*Function    : Battery voltage status Detect
*argument    : NONE
*Retval      : NONE
*explain     : NONE
*******************************************************************************/

void PowerApp_Voltage_100mS_Periodic_Detect(void)
{
	
}


void PowerApp_Ign_Line_100mS_periodic_Detect(void)
{

	
}

void PowerApp_LinNm_State_Judge(void)
{
	#if LIN_FUNCTION_USE_EN
	if(l_ifc_Nm_Sleep_State_get)
	{
		System_Sleep_Event_Set(LIN_BUS_EVENT);
		System_Sleep_Event_Set(RUNNING_TOUT_EVENT);
		
	}
	else
	{
		System_Sleep_Event_Clear(LIN_BUS_EVENT);
	}
	#else
	System_Sleep_Event_Set(LIN_BUS_EVENT);
	#endif
}

void PowerApp_IGN_State_Judge(void)
{
	
	
}


void PowerApp_Sleep_Judge(void)
{
	
	#if 1
	LinTrcv_SetOpMode(LIN_TRCV_MODE_NORMAL);
	#else
	#if LIN_FUNCTION_USE_EN
	static uint32_t Wait_Transceiver_Entry_LowPow_Cnt = 0;
	
	if (UnSleep_Flag)
	{
		Wait_Transceiver_Entry_LowPow_Cnt = 0;
		LinTrcv_SetOpMode(LIN_TRCV_MODE_NORMAL);
	}
	else
	{

		Wait_Transceiver_Entry_LowPow_Cnt++;
		LinTrcv_SetOpMode(LIN_TRCV_MODE_STANDBY);
		// The LIN transceiver is low and in normal working state, and the MCU cannot go to sleep
		
		if (LinTrcv_GetOpMode(LIN_TRCV_MODE_STANDBY))
		{
			// The LIN transceiver is in a sleep working state, and the MCU is in sleep
			Power.MainPowerState = POWER_OFF_WAIT;
		}
		else if (Wait_Transceiver_Entry_LowPow_Cnt >= T10_500MS)
		{
			Wait_Transceiver_Entry_LowPow_Cnt = 0;
			LinTrcv_SetOpMode(LIN_TRCV_MODE_NORMAL);
		}

	}
	#else
	if (UnSleep_Flag)
	{
	}
	else
	{
		Power.MainPowerState = POWER_OFF_WAIT;
	}

	#endif
	#endif
}


uint8_t PowerApp_MainPowerStateGet(void)
{
	return Power.MainPowerState;
}
void PowerApp_ManageProcess(void)
{

	switch (Power.MainPowerState)
	{
    	case POWER_ON_RESET:
			#if POWER_WAKEUP_DISCHARGE_EN
	       	/*When the main power supply is turned on, the delay time from the last time off to ensure that the discharge is complete*/
	        if (Power.WaitTimer<POWER_ON_START_INTERVAL)
	        {
	            break;
	        }
			#endif
			Power.WaitTimer=0;
	        Power.MainPowerState = POWER_ON_START;
        break;

	    case POWER_ON_START:
	        
	        Power.WaitTimer=0;
			// TODO:
			/*Whether to consider placing hardware-related initialization here*/
	        Power.MainPowerState = POWER_ON_INIT_MODULE;
	        break;

	    case POWER_ON_INIT_MODULE:
			// TODO:
			/*Whether to consider placing the external power enable here*/
	        PowerApp_ModelPowerOnCustomer();
	        break;

	    case POWER_SYS_RUNNING:
			PowerApp_LinNm_State_Judge();
			PowerApp_IGN_State_Judge();
			PowerApp_Sleep_Judge();
			Power.WaitTimer=0;	
	        break;
		case POWER_OFF_WAIT:
			#if SLEEP_POWER_CTRL_MODE == SLEEP_POWER_CTRL_SHUT_POWER
			// TODO:
			if(Power.WaitTimer>=POWER_OFF_WAIT_TIMEOUT)
			{
				Power.WaitTimer=0;
				System_ResetDelayTimeSet(T10_10MS);
				System_SwResetFlagSet(TRUE);
			}
			#else
			Power.MainPowerState = SYSTEM_SLEEP;	
			#endif
			//
			break;
	    case SYSTEM_SLEEP:
			PowerApp_ModelPowerOffCustomer();
			SystemMode__Entry_Standby();
			System_Reset();
			//System_WakeupInit();
		break;
		default:
	    break;
	}

}
/*******************************************************************************
* Function name: Get_Battery_Voltage_State
* Function Function: Obtain power status
* Function parameter: none
* Function return: BAT_VOL_STA_UNDER/BAT_VOL_STA_NORMAL/BAT_VOL_STA_OVER
* Note: None
*******************************************************************************/
BAT_VOL_STATE Get_Battery_Voltage_State(void)
{
	return Bat_Vol_State;
}


uint8_t PowerApp_LinGetBattery_Voltage_State(void)
{
	return Pow_Voltage_State;
}



/*******************************************************************************
* Function name: Power_Mode_Set_By_LIN_Bus
* Function function: LIN bus set power mode
* Function argument: Mode OFF/ACC/ON/CRANK
* Function return: none
* Note: None
*******************************************************************************/
void Power_Mode_Set_By_LIN_Bus(POWER_MODE Mode)
{
	LIN_Bus_Power_Mode = Mode;
}

/*******************************************************************************
* Function name: Get_Power_Mode
* Function Function: Get power mode
* Function parameter: none
* Function return value: OFF/ACC/ON/CRANK
* Note: None
*******************************************************************************/
POWER_MODE Get_Power_Mode(void)
{


		return POWER_MODE_ON;		// The SGM458 has no LIN power mode and no IGN cable, so it defaults to ON

	
}

void PowerApp_Init(void)
{
	#if POWER_WAKEUP_DISCHARGE_EN
    Power.MainPowerState = POWER_ON_RESET;
	#else
	Power.MainPowerState = POWER_ON_START;
	#endif
	
	Ign_Line_Power_Mode = POWER_MODE_OFF;
	LIN_Bus_Power_Mode  = POWER_MODE_OFF;
	
	
}
void PowerApp_BattVolDataInit(void)
{
	Bat_Vol_State = BAT_VOL_STA_NORMAL;

	Pow_Voltage_State = VOLTAGE_STATE_NORMAL;

}

void PowerApp_100mS_PeriodicDetectProc(void)
{
	
	System_Running_Periodic_100mS();

}

void PowerApp_10mS_PeriodicDetectProc(void)
{

	PowerAppTimeProc();
	
	PowerApp_ManageProcess();
	
}


