/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      C source file                                                            */
/*   Name         :      Pump_Ctrl.c                                                              */
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


static uint8_t PumpCtrl_Drive_Status = 0u;
 BOOL PumpCtrl_Reset_Flag = FALSE;
static PUMP_FAULT_TYPE Pump_Fault_State = PUMP_FAULT_NORMAL; //ZYG 20251009


/*******************************************************************************
*Name        : PumpCtrl_Drive_Output_Status_Get_If
*Function    : Pump Drive output
*argument    : NONE	
*Retval      : uint8_t Drive Status,
			   When value is FALSE, Pump Off;
			   When value is TRUE, Pump On;
*explain     : Get Now Pump output status
*******************************************************************************/

uint8_t PumpCtrl_Drive_Output_Status_Get_If(void)
{
	return PumpCtrl_Drive_Status;
}

/*******************************************************************************
*Name        : PumpCtrl_Drive_Fault_Status_Get
*Function    : Pump Drive output
*argument    : NONE	
*Retval      : 
*explain     : Get Now Pump fault status
*note        : ZYG 20251009
*******************************************************************************/

PUMP_FAULT_TYPE PumpCtrl_Drive_Fault_Status_Get(void)
{
	return Pump_Fault_State;
}

/*******************************************************************************
*Name        : PumpCtrl_Set_Reset
*Function    : Pump Drive output
*argument    : NONE	
*Retval      : 
*explain     : Get Now Pump fault status
*note        : ZYG 20251009
*******************************************************************************/

void PumpCtrl_Set_Reset(BOOL ReqEN)
{
	static BOOL Lock = FALSE;
	if (ReqEN)
	{
		if (!Lock)
		{
			PumpCtrl_Reset_Flag = TRUE;
		}
	}
	else
	{
		Lock = TRUE;
	}
}


/*******************************************************************************
*Name        : PumpCtrl_Drive_Output_Init
*Function    : Pump Drive output
*argument    : NONE	
*Retval      : NONE
*explain     : Clr Pump power ic En,Power Voltage output set Level4(default)
*******************************************************************************/


void PumpCtrl_Drive_Output_Init(void)
{
	
	PumpCtrl_Drive_Status =FALSE;

	DigitalIf_IoWt_DataSet(Digital_IoWt_Index0,FALSE);
	DigitalIf_IoWt_DataSet(Digital_IoWt_Index8,TRUE);//ZYG 20251009 ON diagnostic

}
/*******************************************************************************
*Name        : PumpCtrl_Drive_Output_DeInit
*Function    : Pump Drive output Deinit
*argument    : NONE	
*Retval      : NONE
*explain     : Clr Pump power ic En,Power Voltage output set Level1				
*******************************************************************************/

void PumpCtrl_Drive_Output_DeInit(void)
{
	PumpCtrl_Drive_Status =FALSE;

	DigitalIf_IoWt_DataSet(Digital_IoWt_Index0,FALSE);
	DigitalIf_IoWt_DataSet(Digital_IoWt_Index8,FALSE);//ZYG 20251009 ON diagnostic

}



/*******************************************************************************
*Name        : PumpCtrl_Drive_Output_If
*Function    : Pump Drive output
*argument    : opType - Pump driving Type 
*						0 - IO Driving
*						1 - Gear Driving
*						2 - Duty Driving
*			   opLevel - Pump driving level
*			   			0 - 100 pump output level
			   opOnOff - Pump driving level
*			   			0 - pump Off
*			   			1 - pump on 
*Retval      : TRUE  opType is the same as the driver mode set on the hardware
*			   FALSE opType driver mode set error
*explain     : When Pump driving Type by IO or Gear,default use max level 12.35V
*					  oplevel <= 25     ===> Pump output level1(8.8V)
*				25 <  oplevel <= 50     ===> Pump output level2(10V)
*				50 <  oplevel <= 75     ===> Pump output level3(11.15V)
*				75 <  oplevel		    ===> Pump output level4(12.35V)
*			   When Pump driving Type by Duty
*				oplevel = 0 ===> Pump off
*				oplevel > 0 ===> Pump Pwm output duty
 			   When opOnOff is TRUE,Pump Power on
*******************************************************************************/


BOOL PumpCtrl_Drive_Output_If(PUMP_DRIVING_TYPE opType,uint8_t opLevel,uint8_t opOnOff)
{
	BOOL Retval = FALSE;
	uint16_t AmpDuty =(uint16_t)opLevel*10;
	if(PUMP_DRIVING_METHOD == opType)
	{
		Retval = TRUE;
		
		if(opOnOff)
		{
			DigitalIf_IoWt_DataSet(Digital_IoWt_Index0,TRUE);
			PumpCtrl_Drive_Status = TRUE;
		}
		else
		{
			DigitalIf_IoWt_DataSet(Digital_IoWt_Index0,FALSE);
			PumpCtrl_Drive_Status = FALSE;
		}
	}
	else
	{
		Retval = FALSE;

		DigitalIf_IoWt_DataSet(Digital_IoWt_Index0,FALSE);

		PumpCtrl_Drive_Status = FALSE;
	}
	return Retval;
}






/*******************************************************************************
*Name        : Pump_Dtc_Process
*Function    : Pump fault deal
*argument    : NONE	
*Retval      : NONE
*explain     : 			
*note        : ZYG 20251009
*******************************************************************************/
void Pump_Dtc_Process(void)
{
	static uint16 SHORT_POWER_Filter  = PUMP_DIAG_SHORT_POWER_Filter;
	static uint16 OPEN_Filter  = PUMP_DIAG_OPEN_Filter;
	static uint16 SHORT_GND_Filter  = PUMP_DIAG_SHORT_GND_Filter;
	static uint16 Normal_Filter  = PUMP_DIAG_Normal_Filter;
	static uint16 PUMP_Short_VOL_Filter = PUMP_DIAG_Short_VOL_Filter;

//OPEN or SHORT_GND
	if(Pump_Fault_State==PUMP_FAULT_OPEN || Pump_Fault_State==PUMP_FAULT_SHORT_GND)
	{
		if(PumpCtrl_Reset_Flag)
		{
			PumpCtrl_Reset_Flag = FALSE;
			SHORT_POWER_Filter  = PUMP_DIAG_SHORT_POWER_Filter;
			OPEN_Filter  = PUMP_DIAG_OPEN_Filter;
			SHORT_GND_Filter  = PUMP_DIAG_SHORT_GND_Filter;
			Normal_Filter  = PUMP_DIAG_Normal_Filter;
			PUMP_Short_VOL_Filter = PUMP_DIAG_Short_VOL_Filter;
			Pump_Fault_State = PUMP_FAULT_RESET;//redetect
		}
		else
		{
			return;
		}
	}
	
	if (TRUE == PumpCtrl_Drive_Output_Status_Get_If())
	{
		PumpCtrl_Reset_Flag = FALSE;
		if(Pump_Fault_State == PUMP_FAULT_SHORT_POWER)
		{
			return;
		}
	
		SHORT_POWER_Filter  = PUMP_DIAG_SHORT_POWER_Filter;

		//SHORT_GND1
		if (DigitalIf_Pump_OutputPoint_VoltageGet()<=PUMP_DIAG_SHORT_VOL &&
			DigitalIf_Batt_Voltage_DataGet()>VOLTAGE_DOWN_TO_LOW)
		{
			if (PUMP_Short_VOL_Filter)
			{
				PUMP_Short_VOL_Filter--;
			}
			else
			{
				Pump_Fault_State = PUMP_FAULT_SHORT_GND;
			}
		}
		else
		{
			PUMP_Short_VOL_Filter = PUMP_DIAG_Short_VOL_Filter;
		}


		//OPEN
		if(PUMP_DIAG_UNDER_CURR>DigitalIf_Pump_IS_CurrentGet())
		{
			Normal_Filter = PUMP_DIAG_Normal_Filter;
			if(OPEN_Filter>0)
			{
				OPEN_Filter--;
			}
			else
			{
				Pump_Fault_State = PUMP_FAULT_OPEN;
			}
		}
		else
		{
			OPEN_Filter = PUMP_DIAG_OPEN_Filter;
		}

		//SHORT_GND2
		if (PUMP_DIAG_OVER_CURR<DigitalIf_Pump_IS_CurrentGet())
		{
			Normal_Filter = PUMP_DIAG_Normal_Filter;
			if(SHORT_GND_Filter>0)
			{
				SHORT_GND_Filter--;
			}
			else
			{
				Pump_Fault_State = PUMP_FAULT_SHORT_GND;
			}
		}
		else
		{
			SHORT_GND_Filter = PUMP_DIAG_SHORT_GND_Filter;
		}
	}
	else
	{
		OPEN_Filter = PUMP_DIAG_OPEN_Filter;
		SHORT_GND_Filter = PUMP_DIAG_SHORT_GND_Filter;
		PUMP_Short_VOL_Filter = PUMP_DIAG_Short_VOL_Filter;
		//SHORT_POWER
		if(DigitalIf_Pump_OutputPoint_VoltageGet()>PUMP_DIAG_VOL)
		{
			Normal_Filter = PUMP_DIAG_Normal_Filter;
			if(SHORT_POWER_Filter>0)
			{
				SHORT_POWER_Filter--;
			}
			else
			{
				Pump_Fault_State = PUMP_FAULT_SHORT_POWER;
			}
		}
		else
		{
			SHORT_POWER_Filter  = PUMP_DIAG_SHORT_POWER_Filter;
		}
	}

	if(Normal_Filter>0)
	{
		Normal_Filter--;
	}
	else
	{
		if (Pump_Fault_State == PUMP_FAULT_SHORT_POWER ||Pump_Fault_State == PUMP_FAULT_RESET)
		{
//			Pump_Fault_State = PUMP_FAULT_NORMAL;
		}
	}
}

