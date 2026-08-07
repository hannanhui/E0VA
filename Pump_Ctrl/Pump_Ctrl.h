/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      H source file                                                            */
/*   Name         :      Pump_Ctrl.h                                                              */
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
#ifndef INCLUDE_PUMP_CTRL_H_
#define INCLUDE_PUMP_CTRL_H_
#include "Type_Define.h"

#define PUMP_DIAG_VOL 5000U

#define PUMP_DIAG_UNDER_CURR 50U
#define PUMP_DIAG_OVER_CURR 3000U

#define PUMP_DIAG_SHORT_VOL 500U

#define PUMP_DIAG_SHORT_POWER_Filter  			(90U)
#define PUMP_DIAG_OPEN_Filter         			(25U)
#define PUMP_DIAG_SHORT_GND_Filter              (25U)
#define PUMP_DIAG_Normal_Filter                 (200U)
#define PUMP_DIAG_Short_VOL_Filter              (5U)







typedef enum
{
    PUMP_DRIVING_TYPE_IO=0,
    PUMP_DRIVING_TYPE_GEAR,
    PUMP_DRIVING_TYPE_DUTY      
}PUMP_DRIVING_TYPE;

/*Reserved*/
typedef enum
{
	PUMP_DRIVING_GEAR_OFF=0,
    PUMP_DRIVING_GEAR_LEVEL1,		//Voltage Output => 8.8V
    PUMP_DRIVING_GEAR_LEVEL2,		//Voltage Output => 10V
    PUMP_DRIVING_GEAR_LEVEL3,		//Voltage Output => 11.15V
    PUMP_DRIVING_GEAR_LEVEL4		//Voltage Output => 12.35V
}PUMP_DRIVING_GEAR_INDEX;

typedef enum
{
	PUMP_FAULT_NORMAL = 0,
	PUMP_FAULT_OPEN   ,
	PUMP_FAULT_SHORT_GND  ,
	PUMP_FAULT_SHORT_POWER  ,
	PUMP_FAULT_RESET,
}PUMP_FAULT_TYPE;



/*******************************************************************************
*Name		 : PumpCtrl_Drive_Output_Init
*Function	 : Pump Drive output
*argument	 : NONE 
*Retval 	 : NONE
*explain	 : Clr Pump power ic En,Power Voltage output set Level4(default)
*******************************************************************************/


extern void PumpCtrl_Drive_Output_Init(void);

/*******************************************************************************
*Name		 : PumpCtrl_Drive_Output_DeInit
*Function	 : Pump Drive output Deinit
*argument	 : NONE 
*Retval 	 : NONE
*explain	 : Clr Pump power ic En,Power Voltage output set Level1 			
*******************************************************************************/

extern void PumpCtrl_Drive_Output_DeInit(void);

extern PUMP_FAULT_TYPE PumpCtrl_Drive_Fault_Status_Get(void);
extern void Pump_Dtc_Process(void);


/*************************************************************************************************************************/
								
/*  ######################################################################################################################
	#################################################External call API####################################################	
**  ######################################################################################################################*/


/*******************************************************************************
*Name        : PumpCtrl_Drive_Output_If
*Function    : Pump Drive output
*argument    : opType - Pump driving Type 
*						0 - IO Driving
*						1 - Gear Driving
*						2 - Duty Driving
*			   opLevel - Pump driving level
*			   			0 - 100 pump output level
			   opOnOff - Pump driving switch
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
 			   When opOnOff is TRUE,Pump Power on;
 			   
*******************************************************************************/


BOOL PumpCtrl_Drive_Output_If(PUMP_DRIVING_TYPE opType,uint8_t opLevel,uint8_t opOnOff);


/*******************************************************************************
*Name        : PumpCtrl_Drive_Output_Status_Get_If
*Function    : Pump Drive output
*argument    : NONE	
*Retval      : uint8_t Drive Status,
			   When value is FALSE, Pump Off;
			   When value is TRUE, Pump On;
*explain     : Get Now Pump output status
*******************************************************************************/


extern uint8_t PumpCtrl_Drive_Output_Status_Get_If(void);
/*************************************************************************************************************************/




#endif /* INCLUDE_PUMP_CTRL_H_ */
