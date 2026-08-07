/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      H source file                                                            */
/*   Name         :      Valve_Ctrl.h                                                             */
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
#ifndef INCLUDE_VALVE_CTRL_H_
#define INCLUDE_VALVE_CTRL_H_



#include "model_Cfg_feature.h"

typedef enum
{
	VALVE_DRIVING_INDEX0=0,
    VALVE_DRIVING_INDEX1,		
    VALVE_DRIVING_INDEX2,		
    VALVE_DRIVING_INDEX3,		
    VALVE_DRIVING_INDEX4,
    VALVE_DRIVING_INDEX5,		
    VALVE_DRIVING_INDEX6,		
    VALVE_DRIVING_INDEX7,		
    VALVE_DRIVING_INDEX8,
    VALVE_DRIVING_INDEX9,		
    VALVE_DRIVING_INDEX10,		
    VALVE_DRIVING_INDEX11,		
    VALVE_DRIVING_INDEX12,
    VALVE_DRIVING_INDEX13,		
    VALVE_DRIVING_INDEX14,		
    VALVE_DRIVING_INDEX15,	
    VALVE_DRIVING_INDEX16,		
    VALVE_DRIVING_INDEX17,		
    VALVE_DRIVING_INDEX18,
    VALVE_DRIVING_INDEX19,
    VALVE_DRIVING_INDEX20,		
    VALVE_DRIVING_INDEX21,		
    VALVE_DRIVING_INDEX22,
    VALVE_DRIVING_INDEX23,		
    VALVE_DRIVING_INDEX24,			
    VALVE_DRIVING_INDEX_MAX,
}VALVE_DRIVING_INDEX;

typedef enum
{
	VALVE_VOLTAGE_ADJUST_IDLE=0,
    VALVE_VOLTAGE_ADJUST_WAIT,		
    VALVE_VOLTAGE_ADJUST_UNDER_WAY,		
}VALVE_VOLTAGE_ADJUST_STATE;


typedef enum
{
    VALVE_ADJUST_STATUS_CLIMBING=0,
    VALVE_ADJUST_STATUS_RESPONSE,
    VALVE_ADJUST_STATUS_STABLE,      
}VALVE_ADJUST_MANAGE_STATUS;



typedef enum
{
	VALVE_REGULATION_GRADE0=0,
    VALVE_REGULATION_GRADE1,		
    VALVE_REGULATION_GRADE2,
    VALVE_REGULATION_GRADE3,
    VALVE_REGULATION_GRADE_NUM
}VALVE_REGULATION_GRADE;


typedef struct
{
	uint32_t  Valve_PWM_Spread_Spectrum_StartPeriod;
	uint32_t  Valve_PWM_Spread_Spectrum_EndPeriod; 	
	uint32_t  Valve_PWM_Spread_Spectrum_StepPeriod; 
	uint32_t  Valve_PWM_Spread_Spectrum_DefaultPeriod;
	uint32_t  Valve_PWM_Spread_Spectrum_Step_Time;
	uint8_t  Valve_PWM_Spread_Spectrum_EnFlag;

}VALVE_DRIVER_PERIOD_CONFIG_T;




typedef struct
{
	uint32_t  Valve_Stable_Voltage;
	uint32_t  Valve_Move_End_Voltage; 	
	uint32_t  Valve_Move_Start_Voltage; 
	uint32_t  Valve_Downhill_Voltage;
	uint32_t  Valve_Move_Voltage_Inc;
	uint32_t  Valve_Move_Voltage_Dec;
	uint16_t  Valve_Climbing_time;
	uint16_t  Valve_Response_time;
	uint16_t  Valve_Stable_time;
	uint16_t  Valve_Downhill_time;
}VALVE_CURVE_CONFIG_T;

typedef struct
{
	uint32_t  Valve_Default_Driver_Voltage;
	
	uint32_t  Valve_Move_Start_Voltage_Factor; 	
	uint32_t  Valve_Move_End_Voltage_Factor; 
	uint32_t  Valve_DownhillEnd_Voltage_Factor;
	
	uint32_t  Valve_Hold_Voltage_Max;
	uint16_t  Valve_Climbing_time;
	uint16_t  Valve_Response_time;
	uint16_t  Valve_Downhill_time;
}VALVE_CURVE_DEFAULT_CONFIG_T;

struct Pwm_Valve_Type
{
	uint8_t PwmIndex;
    //void (*MassageDotSet)(uint8_t ValveIndex,uint8_t En);
};
/*******************************************************************************
*Name        : ValveCtrl_Drive_Output_10msScheduler
*Function    : 
			   call child function1:
				 Valve_Voltage Adjust Manage run base time
*argument    : NONE
*Retval      : NONE
*explain     : This function needs to be called every 10ms
*******************************************************************************/

extern void ValveCtrl_Drive_Output_10msScheduler(void);
/*******************************************************************************
*Name        : ValveCtrl_Drive_Output_100msScheduler
*Function    : 
			   call child function1:
				 Calculate the voltage and time interval at each point of the regulation curve
*argument    : NONE
*Retval      : NONE
*explain     : This function needs to be called every 100ms
*******************************************************************************/

extern void ValveCtrl_Drive_Output_100msScheduler(void);
/*************************************************************************************************************************/
								
/*  ######################################################################################################################
	#################################################External call API####################################################	
**  ######################################################################################################################*/

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



/*************************************************************************************************************************
*Name        : ValveCtrl_Drive_Output_If
*Function    : Valve Drive output
*argument    : opIndex - E-Valve Index(Max 16 channel) 
					If you need to see the hardware I/O pin corresponding to the index, see PORT.h
*					VALVE_DRIVING_INDEX0 
				    VALVE_DRIVING_INDEX1,		
				    VALVE_DRIVING_INDEX2,		
				    VALVE_DRIVING_INDEX3,		
				    VALVE_DRIVING_INDEX4,
				    VALVE_DRIVING_INDEX5,		
				    VALVE_DRIVING_INDEX6,		
				    VALVE_DRIVING_INDEX7,		
				    VALVE_DRIVING_INDEX8,
				    VALVE_DRIVING_INDEX9,		
				    VALVE_DRIVING_INDEX10,		
				    VALVE_DRIVING_INDEX11,		
				    VALVE_DRIVING_INDEX12,
				    VALVE_DRIVING_INDEX13,		
				    VALVE_DRIVING_INDEX14,		
				    VALVE_DRIVING_INDEX15,	
				    VALVE_DRIVING_INDEX16,		
				    VALVE_DRIVING_INDEX17,		
				    VALVE_DRIVING_INDEX18,
				    VALVE_DRIVING_INDEX19,
				    VALVE_DRIVING_INDEX20,		
				    VALVE_DRIVING_INDEX21,		
				    VALVE_DRIVING_INDEX22,
				    VALVE_DRIVING_INDEX23,		
				    VALVE_DRIVING_INDEX24,		
*			   opStatus - Valve driving switch
*			   			FALSE - index corresponding to the valve Off
*			   			TRUE  - index corresponding to the valve On
*Retval      : NONE
*explain     : If Valve Driving by pwm alone:
					Valve use Pwm driving
				  	Valve Power supply use Batt+ driving
				  	opIndex corresponding to the hardware PWM channel
			   If Valve Driving by Pwm union i/o:
			   		Valve use I/O driving
				  	Valve Power supply use PWM driving
			   		opIndex corresponding to the hardware I/O
			   If Valve Driving by i/o alone:
			   		Valve use I/O driving
				  	Valve Power supply use Batt+ driving
				  	opIndex corresponding to the hardware I/O
*************************************************************************************************************************/
extern void ValveCtrl_Drive_Output_If(VALVE_DRIVING_INDEX opIndex,uint8_t opStatus);
extern void ValveCtrl_Drive_Curve_Param_Init(VALVE_CURVE_DEFAULT_CONFIG_T Config[] );

/*************************************************************************************************************************
*Name        : ValveCtrl_Drive_Output_Pressure_RegulationIf
*Function    : Set the current software regulator drive voltage
*argument    : uint16_t opValveVol:
*			   		Set the current software regulator drive voltage uint:mV
*Retval      : NONE
*explain     : Set the current software regulator drive voltage uint:mV
*************************************************************************************************************************/

extern void ValveCtrl_Drive_Output_Pressure_RegulationIf(uint16_t opValveVol);

/*************************************************************************************************************************
*Name        : ValveCtrl_Drive_Output_Pressure_RegulationIf
*Function    : Set the current status of the maximum voltage regulation flag for the solenoid valve.
*argument    : uint8_t 
*			   	FALSE - maximum voltage regulation flag set False
*			   	TRUE  - maximum voltage regulation flag set True
*Retval      : NONE
*explain     : Set the current software regulator drive voltage uint:mV
*************************************************************************************************************************/

extern void Valve_Ctrl_OpenMaxVolFlag_Set(uint8_t opStatus);
/*************************************************************************************************************************
*Name        : Valve_Ctrl_OpenMaxVolFlag_Get
*Function    : Obtain the current status of the maximum voltage regulation flag for the solenoid valve.
*argument    : NONE
*Retval      : uint8_t 
*			   	FALSE - maximum voltage regulation flag is False
*			   	TRUE  - maximum voltage regulation flag is True
*explain     : Obtain the current status of the maximum voltage regulation flag for the solenoid valve.
*************************************************************************************************************************/

extern uint8_t Valve_Ctrl_OpenMaxVolFlag_Get(void);
	

/*************************************************************************************************************************
*Name        : Valve_Supply_Status_Set
*Function    : Valve supply enable
*argument    : opStatus 
*			   		FALSE - Valve supply enable Off
*			   		TRUE  - Valve supply enable On
*Retval      : NONE
*explain     : This opStatus needs to set True when either electromagnet 
				needs to be turned on
*************************************************************************************************************************/

extern void Valve_Supply_Status_Set(uint8_t opStatus);

/*************************************************************************************************************************
*Name        : Valve_Supply_Status_Get
*Function    : Valve supply enable state get
*argument    : void
*Retval      : uint8_t SwitchStatus 
*			   		FALSE - Valve supply Off
*			   		TRUE  - Valve supply  On
*explain     : Obtain the current power supply switch status of the solenoid valve
*************************************************************************************************************************/

extern uint8_t Valve_Supply_Status_Get(void);




extern void ValveCtrl_Valve_Ctrl(VALVE_DRIVING_INDEX opIndex,uint16_t opDuty);
/*************************************************************************************************************************/
uint8_t ValveCtrl_Drive_Valve_Open_NumberGet(void);

extern void Valve_OutputCtrl_Status_Set(uint8_t opStatus);
extern void Valve_OutputCtrl_Func(uint16_t opDyty);

extern uint8_t Valve_Fault_Diag_Get_ValveRunStatus(void);
extern void ValveCtrl_Drive_Output_Init(void);
extern void ValveCtrl_Driver_Period_Param_Init(VALVE_DRIVER_PERIOD_CONFIG_T *Config);




#endif /* INCLUDE_VALVE_CTRL_H_ */



