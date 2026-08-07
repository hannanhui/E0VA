
#include "include.h"


static void Func_BattVol_FaultDiag(void)
{
	BAT_VOL_STATE Fault_State = BAT_VOL_STA_INIT;
	switch (FaultDiag_BattVol_StatusGet())
	{
		case BAT_VOL_STA_INIT:
			break;
		case BAT_VOL_STA_NORMAL:
			uint8_t_wr_LI0_TBL0_MVP17_BattVolFaultState(0U);
			break;
		case BAT_VOL_STA_UNDER:
			uint8_t_wr_LI0_TBL0_MVP17_BattVolFaultState(1U);
			break;
		case BAT_VOL_STA_OVER:
			uint8_t_wr_LI0_TBL0_MVP17_BattVolFaultState(2U);
			break;
		default:
		break;
	}
}


static void Func_Pump_FaultDiag(void)
{
	BAT_VOL_STATE Fault_State = BAT_VOL_STA_INIT;
	switch (FaultDiag_PumpFault_StatusGet())
	{
		case PUMP_FAULT_NORMAL:
			uint8_t_wr_LI0_TBL0_MVP17_PumpFaultState(0U);
			break;
		case PUMP_FAULT_OPEN:
			uint8_t_wr_LI0_TBL0_MVP17_PumpFaultState(1U);
			break;
		case PUMP_FAULT_SHORT_GND:
			uint8_t_wr_LI0_TBL0_MVP17_PumpFaultState(2U);
			break;
		case PUMP_FAULT_SHORT_POWER:
			uint8_t_wr_LI0_TBL0_MVP17_PumpFaultState(3U);
			break;
		case PUMP_FAULT_RESET:
			uint8_t_wr_LI0_TBL0_MVP17_PumpFaultState(0U);
			break;	
		default:
		break;
	}
}


static void Func_Valve_FaultDiag(void)
{
	if (FaultDiag_ValveFault_StatusGet() == VALVE_DIAG_SHORT)
	{
		Valve_Supply_Status_Set(FALSE);
		uint8_t_wr_LI0_TBL0_MVP17_ValveFaultState(1);
	}
	else{
		Valve_Supply_Status_Set(TRUE);
		uint8_t_wr_LI0_TBL0_MVP17_ValveFaultState(0);
	}
}



void Func_FaultDiag_Task(void)
{
	Func_BattVol_FaultDiag();
	Func_Pump_FaultDiag();
	Func_Valve_FaultDiag();
}










