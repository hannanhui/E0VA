/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      H source file                                                            */
/*   Name         :      model_MGP13.h                                                            */
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
#ifndef MODEL_PRO_MGP_H_
#define MODEL_PRO_MGP_H_

#include "Type_Define.h"
#include "model_Cfg_feature.h"
//#include "Lib.h"
#if MODEL == PRO_MGP13
/* ------------------------------------------------------------------------------------------------
-------------------------------1.Version information configuration area----------------------------
---------------------------------------------------------------------------------------------------*/

#define STR_CUSTOMER_MODEL      		     "MVP17"
#define STR_COMPANY_MODEL        		     "MVP17"
#define STR_DEF_VERSION       	 		     "00.00.05"
#define STR_SOFT_DATE            		     "2026-06-10"
#define HW_DEF_VERSION           		     "A00"
#define MCU_CUSTOMER_MAIN_VERSION            "V00.00.05_260610_00_Z20K144MX__App\0"

#define VERSION_INFO_MAX_SIZE     			 48		// Defines the maximum length of version information





/* ------------------------------------------------------------------------------------------------
-------------------------------6.System function configuration area--------------------------------
---------------------------------------------------------------------------------------------------*/

#define UPGRADE_MODE_FOR_PROPRIETARY_LIN           1  
#define UPGRADE_MODE_FOR_UDS_LIN           2

#define UPGRADE_MODE           UPGRADE_MODE_FOR_PROPRIETARY_LIN



#define FUNCTION_USE_MFC  0
#define FUNCTION_USE_MBD  1

#define FUNCTION_USE_METHOD   FUNCTION_USE_MBD


#define PUMP_START_STOP_EN        1


#define MASSAGE_MODE1_POINT4_EN   0



#define MASSAGE_TEST_NO_AUTO_STOP_EN   0
#define MASSAGE_TESTAUTO_RUN_EN   0


#define PRESSURE_READBACK_ERR_TIMES  10



#define MASSAGE_LUMBAR_PHYSICAL_KAY_CTRL_EN   0



/*
 *  VALVE_PWM_OUT_HZ represents the starting point of frequency spreading.
 *  VALVE_PWM_ADJUST_MAX_HZ represents the endpoint of frequency spreading.
 *  VALVE_PWM_ADJUST_STEP_HZ represents the step size for frequency adjustment.
*/
#define VALVE_PWM_ADJUST_Start_HZ					(20000U)	//Initial clock frequency  Add by Ed 20250312
#define VALVE_PWM_ADJUST_End_HZ						(40000U)	//Add by Ed 20250312

#define VALVE_PWM_ADJUST_STEP_HZ					(1000U)	//Add by Ed 20250312
#define VALVE_PWM_ADJUST_STEP_TIME					(T10_100MS)	//Add by Ed 20250312

#define VALVE_PWM_DEFAULT_OUT_HZ					(30000U)	//Initial clock frequency  Add by Ed 20250312





/* ------------------------------------------------------------------------------------------------
-------------------------------8.Power high and low voltage parameter configuration area-----------
---------------------------------------------------------------------------------------------------*/

//massage1
#define Valve_Adjust_Grade0_Move_Start_Voltage_Factor		500//1.125
#define Valve_Adjust_Grade0_Move_End_Voltage_Factor			1500 // 2  //1.5
#define Valve_Adjust_Grade0_DownhillEnd_Voltage_Factor		500//1.125

//Lumbar
#define Valve_Adjust_Grade1_Move_Start_Voltage_Factor		600//1.125
#define Valve_Adjust_Grade1_Move_End_Voltage_Factor			1500 // 2
#define Valve_Adjust_Grade1_DownhillEnd_Voltage_Factor		500//1.125

//Flank
#define Valve_Adjust_Grade2_Move_Start_Voltage_Factor		600//1.125
#define Valve_Adjust_Grade2_Move_End_Voltage_Factor			1500 // 2
#define Valve_Adjust_Grade2_DownhillEnd_Voltage_Factor		500//1.125

//GasStorage1
#define Valve_Adjust_Grade3_Move_Start_Voltage_Factor		800//1.125
#define Valve_Adjust_Grade3_Move_End_Voltage_Factor			1630 // 2
#define Valve_Adjust_Grade3_DownhillEnd_Voltage_Factor		500//1.125


//massage2
#define Valve_Adjust_Grade4_Move_Start_Voltage_Factor		600//1.125
#define Valve_Adjust_Grade4_Move_End_Voltage_Factor			1500 // 2
#define Valve_Adjust_Grade4_DownhillEnd_Voltage_Factor		500//1.125


//GasStorage2
#define Valve_Adjust_Grade5_Move_Start_Voltage_Factor		500//1.125
#define Valve_Adjust_Grade5_Move_End_Voltage_Factor			1400 // 2
#define Valve_Adjust_Grade5_DownhillEnd_Voltage_Factor		500//1.125

//Flank2
#define Valve_Adjust_Grade6_Move_Start_Voltage_Factor		700//1.125
#define Valve_Adjust_Grade6_Move_End_Voltage_Factor			1300 // 2
#define Valve_Adjust_Grade6_DownhillEnd_Voltage_Factor		100//1.125



#define VALVE_ADJUST_GRADE0_HOLD_MAX_DRIVER_VOLTAGE_mV  			8000	//
#define VALVE_ADJUST_GRADE1_HOLD_MAX_DRIVER_VOLTAGE_mV  			8000 	//
#define VALVE_ADJUST_GRADE2_HOLD_MAX_DRIVER_VOLTAGE_mV  			8000   //
#define VALVE_ADJUST_GRADE3_HOLD_MAX_DRIVER_VOLTAGE_mV  			7700   //
#define VALVE_ADJUST_GRADE4_HOLD_MAX_DRIVER_VOLTAGE_mV  			8000   //
#define VALVE_ADJUST_GRADE5_HOLD_MAX_DRIVER_VOLTAGE_mV  			7500   //



#define VALVE_ADJUST_GRADE0_DEFAULT_DRIVER_VOLTAGE_mV  		5500  //massage1
#define VALVE_ADJUST_GRADE1_DEFAULT_DRIVER_VOLTAGE_mV  		5500  //Lumbar
#define VALVE_ADJUST_GRADE2_DEFAULT_DRIVER_VOLTAGE_mV  		5500   //Flank
#define VALVE_ADJUST_GRADE3_DEFAULT_DRIVER_VOLTAGE_mV  		5300  //GasStorage1
#define VALVE_ADJUST_GRADE4_DEFAULT_DRIVER_VOLTAGE_mV  		5500  //massage2
#define VALVE_ADJUST_GRADE5_DEFAULT_DRIVER_VOLTAGE_mV  		5000  //GasStorage2
#define VALVE_ADJUST_GRADE6_DEFAULT_DRIVER_VOLTAGE_mV  		4700  //Flank2




#define VALVE_ADJUST_GRADE0_CLIMBING_TIME  		T10_90MS  //massage1
#define VALVE_ADJUST_GRADE1_CLIMBING_TIME  		T10_150MS //Lumbar
#define VALVE_ADJUST_GRADE2_CLIMBING_TIME  		T10_100MS //Flank //T10_100MS
#define VALVE_ADJUST_GRADE3_CLIMBING_TIME  		T10_250MS //GasStorage
#define VALVE_ADJUST_GRADE4_CLIMBING_TIME  		T10_150MS //massage2
#define VALVE_ADJUST_GRADE5_CLIMBING_TIME  		T10_150MS //GasStorage2


#define VALVE_ADJUST_GRADE0_RESPONSE_TIME  		T10_10MS  //massage1
#define VALVE_ADJUST_GRADE1_RESPONSE_TIME  		T10_300MS
#define VALVE_ADJUST_GRADE2_RESPONSE_TIME  		T10_450MS
#define VALVE_ADJUST_GRADE3_RESPONSE_TIME  		T10_300MS
#define VALVE_ADJUST_GRADE4_RESPONSE_TIME  		T10_300MS
#define VALVE_ADJUST_GRADE5_RESPONSE_TIME  		T10_300MS



#define VALVE_ADJUST_GRADE0_DOWNHILL_TIME  		T10_80MS//T10_80MS
#define VALVE_ADJUST_GRADE1_DOWNHILL_TIME  		T10_200MS
#define VALVE_ADJUST_GRADE2_DOWNHILL_TIME  		T10_200MS
#define VALVE_ADJUST_GRADE3_DOWNHILL_TIME  		T10_200MS
#define VALVE_ADJUST_GRADE4_DOWNHILL_TIME  		T10_200MS
#define VALVE_ADJUST_GRADE5_DOWNHILL_TIME  		T10_200MS






// Voltage drop on a diode connected in series on a power cord, unit: mV
#define BAT_VOL_DROP_ON_DIODE_mV				230U



#define VOLTAGE_UP_TO_OVERHIGH          18500U	   //Lin Power High Status Enter Voltage
#define VOLTAGE_DOWN_TO_HIGH            18000U	   //Lin Power High Status Exit  Voltage
#define VOLTAGE_UP_TO_HIGH              16500U     //Level A function Power High Status Enter Voltage
#define VOLTAGE_DOWN_TO_NORMAL          16000U 	   //Level A function Power High Status Exit  Voltage
	
#define VOLTAGE_DOWN_TO_LOW             8000U      //Level A function Power Low Status Enter Voltage
#define VOLTAGE_UP_TO_NORMAL            8500U 	   //Level A function Power Low Status Exit  Voltage  
#define VOLTAGE_DOWN_TO_UNDERLOW        7000U	   //Lin Power Low Status Enter Voltage
#define VOLTAGE_UP_TO_LOW               7500U	   //Lin Power Low Status Exit  Voltage	

#define POWER_MIN_DEBOUNCE_TIME     T100_500MS//T10_200MS

#define UP_TO_OVERHIGH_DEBOUNCE 	T100_2000MS
#define UP_TO_HIGH_DEBOUNCE 		T100_2000MS
#define UP_TO_NORMAL_DEBOUNCE 		T100_2000MS
#define UP_TO_LOW_DEBOUNCE 			T100_2000MS


#define DOWN_TO_HIGH_DEBOUNCE 		T100_2000MS
#define DOWN_TO_NORMAL_DEBOUNCE 	T100_2000MS
#define DOWN_TO_LOW_DEBOUNCE 		T100_2000MS
#define DOWN_TO_UNDERLOW_DEBOUNCE 	T100_2000MS


//Threshold for the voltage to return to normal ,unit mV
#define HYSTERESIS_VOLTAGE								400U	

#define IGN_ON_FILTER_TIME								T100_500MS	
#define IGN_OFF_FILTER_TIME								T100_500MS	

#define IGN_ON_VOLTAGE									11000U	// mV
#define IGN_OFF_VOLTAGE									4000U		// mV


#endif
#endif

