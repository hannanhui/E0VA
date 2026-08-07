/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      C source file                                                            */
/*   Name         :      Valve_Ctrl.c                                                             */
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



static uint8_t s_Valve_Ctrl_Status[VALVE_DRIVING_INDEX_MAX]={0};
static uint8_t s_Valve_Ctrl_BackupStatus[VALVE_DRIVING_INDEX_MAX]={0};

static uint8_t s_ValveSupply_On_Flag = 0;

static uint8_t s_ValveOutputCtrl_Flag = 1;
static uint16_t s_Valve_SetDuty =0; 
uint8_t  ValveOpenMaxVolFlag =0u;

static uint8_t s_Valve_curve_regulation_grade = 0;

VALVE_CURVE_CONFIG_T s_Valve_curve_config[VALVE_DRIVING_INDEX_MAX]={0};

VALVE_CURVE_DEFAULT_CONFIG_T s_Valve_curve_Default_Value[VALVE_DRIVING_INDEX_MAX]={0};



static uint8_t s_ValveStatusList_ChangeTick[VALVE_DRIVING_INDEX_MAX]={0};
static uint32_t Set_Valve_Supply_Voltage[VALVE_DRIVING_INDEX_MAX]={0};


uint32_t Valve_Init_Period=VALVE_PWM_OUT_HZ;
VALVE_DRIVER_PERIOD_CONFIG_T s_Valve_Driver_Period_config;
uint16_t  ValveSpread_SpectrumTimeCall =0u;
uint8_t Valve_DefaultPeriod_SetFlag=0;
uint8_t Period_turnFlag=0;
uint8_t Period_ChangeFlag=0;





void ValveCtrl_Drive_Output_Spread_SpectrumScheduler(void);

/***************************************************************************************************************************************
Valve Index  map and  Sensor Index map        
----------------------------------------------------------------------------------------------------------------------------------------
_______________________________________________________________________________________________________________________________________
| o    o o    o o    o o    o o    o |    _               _     _       | o    o  o    o  o    o  o    o  o    o  o    o  o    o |    _|
| index6 index7 index8 index9 index10|   |_|             |_|   |_|      |index13 index14 index15 index16 index17 index18 index19 |   | 
|          _                         |   P6              P5    P4       |                                                        |   |_
| Bottom->|_|                        ||                                 |                                                        |     | 
|        P10      _      _      _    ||              _________________  |                                                        |     | 
|                |_|    |_|    |_|   ||                o    o o    o  | |    _      _       _                                    |     | 
|                P9     P8     P7    ||               index11 index12 | |   |_|    |_|     |_|                   ________________|     | 
|                                    ||                               | |   P3     P2      P1                    |        _            |
|               o    o o    o o    o ||                               | | o    o  o    o  o    o                 |   ____| |____       | 
|               index2 index3 index4 ||                               | |index20 index21 index22                 |  |____| |____|      | 
|                 ^^                 ||                               | |                                        |       | |           |                                      
|        _________||                 ||                               | |                                        |   ----| |----       |                                            
|       |either-or||                 ||   o    o                      | |                                        |   ----| |----       |                                                                                       
|        ---------||                 ||   index5                      | |                                        |   ----| |----       |
|                 ||                 ||                               | |                                        |   ----| |----       |
| index1 index0 index2               ||    ___                        | |                                        |   ----| |----       | 
| o    o o    o o    o               ||   |   |                       | |                                        |   ____| |____       |                                   
|_______________________  ___________||   |___|       index24 index23 | |                                        |  |____| |____|      | 
                        )     ___     |    P0          o    o o    o  | |________________________________________|       |_|           |                
                        )_____|  |____|_______________ _______________|                      __________________________________________| 
                                                      |               >ooooooo              |  
                                                      |_____________________________________|
----------------------------------------------------------------------------------------------------------------------------------------                                                      
****************************************************************************************************************************************/


/*******************************************************************************
*Name        : Valve_Supply_Status_Set
*Function    : Valve supply enable
*argument    : opStatus 
*			   		FALSE - Valve supply enable Off
*			   		TRUE  - Valve supply enable On
*Retval      : NONE
*explain     : This opStatus needs to set True when either electromagnet 
				needs to be turned on
*******************************************************************************/

void Valve_Supply_Status_Set(uint8_t opStatus)
{
	s_ValveSupply_On_Flag = opStatus;
	DigitalIf_IoWt_DataSet(Digital_IoWt_Index2,opStatus);
}
uint8_t Valve_Supply_Status_Get(void)
{
	return s_ValveSupply_On_Flag;
}



#if(VALVE_DRIVING_METHOD==VALVE_DRIVING_BY_PWM_UNION_IO)
void Valve_OutputCtrl_Func(uint16_t opDyty)
{
	s_Valve_SetDuty = opDyty;
	if(s_ValveOutputCtrl_Flag)
	{		
		PWM_IF_PWM_DutySet((E_PWM_CHANNEL_LIST)VALVE_DRIVING_INDEX5,opDyty);
	}
	else
	{
		PWM_IF_PWM_DutySet((E_PWM_CHANNEL_LIST)VALVE_DRIVING_INDEX5,0);
	}
}
#endif


void ValveCtrl_Valve_Ctrl(VALVE_DRIVING_INDEX opIndex,uint16_t opDuty)
{
	PWM_IF_PWM_DutySet(opIndex ,opDuty);	
}
void ValveCtrl_aLL_Valve_Disable(void)
{
	
}
void ValveCtrl_Calculate_Adjust_Curve_Voltage(void)
{
	
}


void ValveCtrl_Valve_Voltage_Adjust_Manage(void)
{
	

}



uint8_t ValveCtrl_Drive_Valve_Open_NumberGet(void)
{
	
}








void ValveCtrl_Drive_Output_If(VALVE_DRIVING_INDEX opIndex,uint8_t opStatus)
{
	
}



void ValveCtrl_Drive_Output_10msScheduler(void)
{
	
}

void ValveCtrl_Drive_Curve_Param_Init(VALVE_CURVE_DEFAULT_CONFIG_T Config[])
{
	
}


void ValveCtrl_Drive_Output_Init(void)
{

}


void ValveCtrl_Driver_Period_Param_Init(VALVE_DRIVER_PERIOD_CONFIG_T *Config)
{
	
}	



void ValveCtrl_Drive_Output_100msScheduler(void)
{
	
}



void ValveCtrl_Drive_Output_Spread_SpectrumScheduler(void)
{

}





