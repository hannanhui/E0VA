/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      C source file                                                            */
/*   Name         :      Fault_Diag.c                                                             */
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

#include "include.h"


static uint8_t PowerIC0_Diag_Status = FALSE;
static uint8_t PowerIC1_Diag_Status = FALSE;
static uint8_t  Temp_Over_Filter;
static uint8_t  Temp_Normal_Filter;
static uint8_t  Temp_Fault_ULimit_Filter;
static uint8_t  Temp_Fault_DLimit_Filter;
static int16_t  Temperature;
static BOARD_TEMP_STATE Board_Temp_State;
static VALVE_DIAG_FAULT_Type ValveDiagFaultState = VALVE_DIAG_NORMAL;


static void Temperature_Diag_Data_Init(void)
{
	Temp_Over_Filter  = 0;
	Temp_Normal_Filter = 0;
	Temp_Fault_ULimit_Filter = 0;
	Temp_Fault_DLimit_Filter = 0;
	Temperature = 25;
	Board_Temp_State = BOARD_TEMP_STATE_NORMAL;

}


void FaultDiag_DataInit(void)
{
	PowerIC0_Diag_Status = TRUE;
	PowerIC1_Diag_Status = TRUE;

	Temperature_Diag_Data_Init();

	PowerApp_BattVolDataInit();

	DigitalIf_IoWt_DataSet(Digital_IoWt_Index4,TRUE);//ZYG 20251016 ON diagnostic
}


static void Board_Temperature_DiagFunc(void)
{
	
	if(DigitalIf_Temperature_DataGet(Digital_Temperature_Index0,&Temperature))
	{
		if (Temperature >= BOARD_TEMP_DIAG_OVER_LIMIT)
		{
			Temp_Fault_DLimit_Filter = 0;
			Temp_Normal_Filter = 0;
			Temp_Over_Filter = 0;

			if (Temp_Fault_ULimit_Filter < BOARD_TEMP_DIAG_FILTER)
			{
				Temp_Fault_ULimit_Filter++;
			}
			else
			{
				Board_Temp_State = BOARD_TEMP_STATE_FAULT;
			}
		}
		else if (Temperature <= BOARD_TEMP_DIAG_UNDER_LIMIT)
		{
			Temp_Fault_ULimit_Filter = 0;
			Temp_Normal_Filter = 0;
			Temp_Over_Filter = 0;

			if (Temp_Fault_DLimit_Filter < BOARD_TEMP_DIAG_FILTER)
			{
				Temp_Fault_DLimit_Filter++;
			}
			else
			{
				Board_Temp_State = BOARD_TEMP_STATE_FAULT;
			}
		}
		else if (Temperature >= BOARD_TEMP_DIAG_HIGH_TEMP)
		{
			Temp_Normal_Filter = 0;
			Temp_Fault_ULimit_Filter = 0;
			Temp_Fault_DLimit_Filter = 0;

			if (Temp_Over_Filter < BOARD_TEMP_DIAG_FILTER)
			{
				Temp_Over_Filter++;
			}
			else
			{
				Board_Temp_State = BOARD_TEMP_STATE_OVER;
			}
		}
		else if (Temperature <= (BOARD_TEMP_DIAG_HIGH_TO_NORMAL_TEMP))
		{
			Temp_Over_Filter = 0;
			Temp_Fault_ULimit_Filter = 0;
			Temp_Fault_DLimit_Filter = 0;

			if (Temp_Normal_Filter < BOARD_TEMP_DIAG_FILTER)
			{
				Temp_Normal_Filter++;
			}
			else
			{
				Board_Temp_State = BOARD_TEMP_STATE_NORMAL;
			}
		}
	}
	else
	{
//		Board_Temp_State = BOARD_TEMP_STATE_GET_TEMP_FAIL;
	}
	
}

uint32_t TEST_Valve_current = 0; 
uint32_t TEST_Valve_Num = 0; 

static void Valve_IS_DiagFunc(void)
{
	static uint8_t  Valve_IS_Over_Filter = _VALVE_IS_DIAG_SHORT_FILTER;
	static uint8_t  Valve_IS_Open_Filter = _VALVE_IS_DIAG_OPEN_FILTER;
	static uint8_t  Valve_Short_VOL_Filter = VALVE_DIAG_SHORT_VOL_FILTER;
	
	
	TEST_Valve_current = DigitalIf_Valve_IS_CurrentGet();
	TEST_Valve_Num = ValveCtrl_Drive_Valve_Open_NumberGet();

	if(ValveDiagFaultState == VALVE_DIAG_SHORT)
	{
		return ;
	}

	if (Valve_Supply_Status_Get()==TRUE && 
	DigitalIf_Valve_OutputPoint_VoltageGet(Power_Ic_Index0)<=VALVE_DIAG_SHORT_VOL &&
	DigitalIf_Batt_Voltage_DataGet()>VOLTAGE_DOWN_TO_LOW)
	{
		if (Valve_Short_VOL_Filter)
		{
			Valve_Short_VOL_Filter--;
		}
		else
		{
			ValveDiagFaultState = VALVE_DIAG_SHORT;
		}
	}
	else
	{
		Valve_Short_VOL_Filter = VALVE_DIAG_SHORT_VOL_FILTER;
	}
	
	if(DigitalIf_Valve_IS_CurrentGet()>VALVE_IS_OVER_CURRENT)
	{
		if (Valve_IS_Over_Filter)
		{
			Valve_IS_Over_Filter--;
		}
		else
		{
			ValveDiagFaultState = VALVE_DIAG_SHORT;
		}
	}
	else
	{
		Valve_IS_Over_Filter = _VALVE_IS_DIAG_SHORT_FILTER;
	}


	if(ValveDiagFaultState == VALVE_DIAG_OPEN)
		{
			return ;
		}

	if(DigitalIf_Valve_IS_CurrentGet()<VALVE_IS_UNDER_CURRENT &&
	ValveCtrl_Drive_Valve_Open_NumberGet()>0U)
	{
		if (Valve_IS_Open_Filter)
		{
			Valve_IS_Open_Filter--;
		}
		else
		{
			ValveDiagFaultState = VALVE_DIAG_OPEN;
		}
	}
	else
	{
		Valve_IS_Open_Filter = _VALVE_IS_DIAG_OPEN_FILTER;
	}

	
}



void FaultDiag_Task_10msScheduler(void)
{
	Pump_Dtc_Process();
	Valve_IS_DiagFunc();
}

void FaultDiag_Task_100msScheduler(void)
{
	PowerApp_Voltage_100mS_Periodic_Detect();	
	#if POWER_MODE_IGN_LINE_DET_EN
	PowerApp_Ign_Line_100mS_periodic_Detect();
	#endif
	Board_Temperature_DiagFunc();
	
}

BOARD_TEMP_STATE Get_Board_Temp_State(void)
{
	return Board_Temp_State;
}

uint8_t FaultDiag_Poweric_StatusGet(uint8_t opIndex)
{
	return 0u;//(uint8_t)POWER_IC_DIAG_Status_Get((Power_Ic_Index_Def)opIndex);
}
void FaultDiag_Poweric_Recover_DetEnSet(uint8_t opIndex,uint8_t opEnStatus)
{
	//FaultDiagStatus[opIndex].Diag_Recover_DetEn = opEnStatus;
}




uint8_t FaultDiag_BattVol_StatusGet(void)
{
	return (uint8_t)Get_Battery_Voltage_State();
}

uint8_t FaultDiag_BoardTemp_StatusGet(void)
{
	return (uint8_t)Get_Board_Temp_State();
}

//zyg
uint8_t FaultDiag_PumpFault_StatusGet(void)
{
	return (uint8_t)PumpCtrl_Drive_Fault_Status_Get();
}


VALVE_DIAG_FAULT_Type FaultDiag_ValveFault_StatusGet(void)
{
	return ValveDiagFaultState;
}


