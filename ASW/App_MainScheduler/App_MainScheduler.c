/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      C source file                                                            */
/*   Name         :      App_MainScheduler.c                                                      */
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
#include "Wdg.h"
POWER_VOLTAGE_INIT_VALUE App_Project_Batt_Voltage_Param;
VALVE_DRIVER_PERIOD_CONFIG_T  App_Project_ValveDriver_Period_Param;


void App_Main_Scheduler_Periodic_1mS(void)
{

//	#if UPGRADE_MODE == UPGRADE_MODE_FOR_UDS_LIN
//	UDS_SystemTickCtl();
//	UDS_MainFun();
//	#elif UPGRADE_MODE == UPGRADE_MODE_FOR_PROPRIETARY_LIN
//		
//	//ProprietaryLin_MainFun();
//	#endif

}

void App_Main_Scheduler_Periodic_5mS(void)
{
	
}

void App_Main_Scheduler_Periodic_10mS(void)
{

#if (FUNCTION_USE_METHOD == FUNCTION_USE_MFC)
	MFC_Adapter_Task();

#else
	MBD_Task();
#endif

	Function_Key_Timer10ms();
	Func_Pressure_Task();
	
	Vehicle_Action.Bus_Action_Periodic_10mS();

}

void App_Main_Scheduler_Periodic_20mS(void)
{

	
}
void App_Main_Scheduler_Periodic_50mS(void)
{

	
}


void App_Main_Scheduler_Periodic_100mS(void)
{
	Func_FaultDiag_Task();
}

uint32_t HsdCurrent = 0;
uint32_t HsdCurrent1 = 0;
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

uint16_t AdcReadbackVal[Digital_Adc_MaxNum]={0};

void App_Main_Scheduler_Services_Api_Test(void)
{
	
	int16_t  NowTemperature_Ntc =0u;
	int16_t  NowTemperature_Sensor[Digital_Pressure_Index11] ={0};
	uint32_t  NowPressure[Digital_Pressure_Index11] ={0};
	uint8_t BoardTempStatus =0;
	uint8_t BoardBattStatus =0;
	uint8_t PumpPowerOpenStatus =0;
	uint8_t ValvePowerOpenStatus =0;

	static uint8_t TestValveIndex =0;
	static uint8_t TestValveDelay =0;
//	static uint32_t  NowPressure[Digital_Pressure_Index11] ={0};
//	static int16_t  NowTemperature_Ntc =0u;
//	static int16_t  NowTemperature_Sensor[Digital_Pressure_Index11] ={0};
	static uint16_t  battVoltage =0u;
	static uint8_t HwBoardVersion=0;
	static uint8_t HwVersionGetFlag=0;
//	static uint16_t AdcReadbackVal[Digital_Adc_MaxNum]={0};
	static uint8_t Index=0;

	
	
	uint8_t ValveOpenNb =0;
	uint32_t Pump_Voltage = 0;
	uint32_t Valve_Voltage = 0;

	
	
	for(Index=0;Index<Digital_Pressure_Index11;Index++)
	{
		DigitalIf_Pressure_DataGet(Index,&NowPressure[Index]);
		DigitalIf_Temperature_DataGet((Index+1),&NowTemperature_Sensor[Index]);
	}
	
	DigitalIf_Temperature_DataGet(Digital_Temperature_Index0,&NowTemperature_Ntc);



	battVoltage = DigitalIf_Batt_Voltage_DataGet();
	HwVersionGetFlag =DigitalIf_Platform_HwVerStateGet(&HwBoardVersion);

	for(Index=0;Index<Digital_Adc_MaxNum;Index++)
	{
		AdcReadbackVal[Index] = DigitalIf_Adc_DataGet(Index);
	}
	BoardBattStatus = FaultDiag_BattVol_StatusGet();

	BoardTempStatus = FaultDiag_BoardTemp_StatusGet();

	
	#if 1
	// VALVE POWER OUTPUT
	DigitalIf_IoWt_DataSet(Digital_IoWt_Index2,TRUE);
	// VALVE DIAG CTRL
	DigitalIf_IoWt_DataSet(Digital_IoWt_Index4,TRUE);
	// PUMP POWER OUTPUT
	DigitalIf_IoWt_DataSet(Digital_IoWt_Index0,TRUE);
	// PUMP DIAG CTRL
	DigitalIf_IoWt_DataSet(Digital_IoWt_Index8,TRUE);
	//DigitalIf_IoWt_DataSet(Digital_IoWt_Index6,TRUE);
	//DigitalIf_IoWt_DataSet(Digital_IoWt_Index7,FALSE);
	PumpCtrl_Drive_Output_If(PUMP_DRIVING_TYPE_IO,100,TRUE);
	PumpPowerOpenStatus =PumpCtrl_Drive_Output_Status_Get_If();
	
	ValveOpenNb =ValveCtrl_Drive_Valve_Open_NumberGet();
	Pump_Voltage = DigitalIf_Pump_OutputPoint_VoltageGet();
	Valve_Voltage = DigitalIf_Valve_OutputPoint_VoltageGet(Digital_Current_Index0);
	HsdCurrent = DigitalIf_Diag_Current_DataGet(Digital_Current_Index0);
	HsdCurrent1 = DigitalIf_Diag_Current_DataGet(Digital_Current_Index1);
	#if 1
	if(TestValveDelay<3)
	{
		TestValveDelay++;
	}
	else
	{
		TestValveDelay =0;
		if(0u == TestValveIndex)
		{
				ValveCtrl_Drive_Output_If(0,TRUE);
				TestValveIndex =1;
		}
		else
		{
				ValveCtrl_Drive_Output_If(0,FALSE);
				TestValveIndex =0;
		}
	}
	#endif
	ValvePowerOpenStatus =Valve_Supply_Status_Get();
	#if 0
	if(TestValveDelay<3)
	{
		TestValveDelay++;
	}
	else
	{
		TestValveDelay =0;

		if(TestValveIndex < VALVE_DRIVING_INDEX_MAX)
		{
			if(0u == TestValveIndex)
			{
				ValveCtrl_Drive_Output_If(VALVE_DRIVING_INDEX_MAX-1,FALSE);
			}
			else
			{
				ValveCtrl_Drive_Output_If(TestValveIndex-1,FALSE);
			}
			ValveCtrl_Drive_Output_If(TestValveIndex,TRUE);
			TestValveIndex++;
			if(TestValveIndex == VALVE_DRIVING_INDEX_MAX)
			{
				TestValveIndex =0;

			}
		}
	}
	#endif
#endif
}


static void App_Test_Diver(void)
{
	static uint16_t Loc_Cnt = 0;
	static BOOL bValue = FALSE;
	DigitalIf_IoWt_DataSet(Digital_IoWt_Index0,TRUE);
	DigitalIf_IoWt_DataSet(Digital_IoWt_Index1,TRUE);
	DigitalIf_IoWt_DataSet(Digital_IoWt_Index2,TRUE);
	DigitalIf_IoWt_DataSet(Digital_IoWt_Index3,TRUE);
	DigitalIf_IoWt_DataSet(Digital_IoWt_Index4,TRUE);
	DigitalIf_IoWt_DataSet(Digital_IoWt_Index8,TRUE);
	if (Loc_Cnt<2)
		{
		Loc_Cnt++;
		
		}
	else
		{
		bValue = !bValue;
//		ValveCtrl_Drive_Output_If(VALVE_DRIVING_INDEX8,bValue);
//		ValveCtrl_Drive_Output_If(VALVE_DRIVING_INDEX2,!bValue);
//
//		ValveCtrl_Drive_Output_If(VALVE_DRIVING_INDEX9,bValue);
//		ValveCtrl_Drive_Output_If(VALVE_DRIVING_INDEX3,!bValue);
//
//		ValveCtrl_Drive_Output_If(VALVE_DRIVING_INDEX10,bValue);
//		ValveCtrl_Drive_Output_If(VALVE_DRIVING_INDEX4,!bValue);
//		
//		ValveCtrl_Drive_Output_If(VALVE_DRIVING_INDEX13,bValue);
//		ValveCtrl_Drive_Output_If(VALVE_DRIVING_INDEX20,!bValue);
				ValveCtrl_Drive_Output_If(VALVE_DRIVING_INDEX23,bValue);
//				ValveCtrl_Drive_Output_If(VALVE_DRIVING_INDEX24,!bValue);

		Loc_Cnt = 0;
		
		}
}
void App_Main_Scheduler_Periodic_1000mS(void)
{
//	App_Main_Scheduler_Services_Api_Test();
//	App_Test_Diver();
	
}




void App_Main_Before_ResetSaveOperation(void)
{
}


void App_System_Init(void)
{

//config  under voltage  over voltage
	App_Project_Batt_Voltage_Param.minDebounceTime =POWER_MIN_DEBOUNCE_TIME;
	App_Project_Batt_Voltage_Param.UpToOverHighAD= VOLTAGE_UP_TO_OVERHIGH;
	App_Project_Batt_Voltage_Param.UpToOverHighDebounce = UP_TO_OVERHIGH_DEBOUNCE;
	App_Project_Batt_Voltage_Param.UpToHighAD = VOLTAGE_UP_TO_HIGH;
	App_Project_Batt_Voltage_Param.UpToHighDebounce = UP_TO_HIGH_DEBOUNCE;
	App_Project_Batt_Voltage_Param.UpToNormalAD = VOLTAGE_UP_TO_NORMAL;
	App_Project_Batt_Voltage_Param.UpToNormalDebounce= UP_TO_NORMAL_DEBOUNCE;
	App_Project_Batt_Voltage_Param.UpToLowAD= VOLTAGE_UP_TO_LOW;
	App_Project_Batt_Voltage_Param.UpToLowDebounce = UP_TO_LOW_DEBOUNCE;

	App_Project_Batt_Voltage_Param.DownToHighAD= VOLTAGE_DOWN_TO_HIGH;
	App_Project_Batt_Voltage_Param.DownToHighDebounce = DOWN_TO_HIGH_DEBOUNCE;
	App_Project_Batt_Voltage_Param.DownToNormalAD= VOLTAGE_DOWN_TO_NORMAL;
	App_Project_Batt_Voltage_Param.DownToNormalDebounce = DOWN_TO_NORMAL_DEBOUNCE;
	App_Project_Batt_Voltage_Param.DownToLowAD= VOLTAGE_DOWN_TO_LOW;
	App_Project_Batt_Voltage_Param.DownToLowDebounce = DOWN_TO_LOW_DEBOUNCE;
	App_Project_Batt_Voltage_Param.DownToUnderLowAD= VOLTAGE_DOWN_TO_UNDERLOW;
	App_Project_Batt_Voltage_Param.DownToUnderLowDebounce= DOWN_TO_UNDERLOW_DEBOUNCE;
	PowerVoltage_Param_Init(&App_Project_Batt_Voltage_Param);
	Function_Valve_Curve_Init();//valve voltage curve
	//Function_DiagDeal_Init();
	#if UPGRADE_MODE == UPGRADE_MODE_FOR_PROPRIETARY_LIN
	System_CAL_Version(BOOT_MAJOR_VERSION, Boot_Major_Version);
	System_CAL_Version(APP_MAJOR_VERSION, App_Major_Version);
	System_CAL_Version(BOOT_MINOR_VERSION, Boot_Minor_Version);
	System_CAL_Version(APP_MINOR_VERSION, App_Minor_Version);	
	#endif
	Vehicle_Action.Bus_Action_Lintl_CallbackInstall();		
	Vehicle_Action.Bus_Action_Init();
	//Function_Manage_Init();
#if FUNCTION_USE_METHOD == FUNCTION_USE_MBD
	//MassageDot_Mode_initialize();

#else
	//MFC_Mode_initialize();

#endif
	//Param_PressureUseNone , Param_PressureUseSMP58X, Param_PressureUseNSPAD1
	Param_Calibration_SensorUseCfgTypeSet(Param_PressureUseNSPAD1);
	//Lumbar mode selection, 0: three-bag mode 1: two-bag mode
	//Func_logic_LumSupModeStateSet(0);
	
	Function_Key_Init();
	Func_Pressure_Init();

#if (FUNCTION_USE_METHOD == FUNCTION_USE_MFC)
	MFC_Adapter_Init();
#else
	BackMassage_Model_initialize();
#endif
	Valve_Supply_Status_Set(TRUE);

	App_Project_ValveDriver_Period_Param.Valve_PWM_Spread_Spectrum_StartPeriod = VALVE_PWM_ADJUST_Start_HZ;
	App_Project_ValveDriver_Period_Param.Valve_PWM_Spread_Spectrum_EndPeriod = VALVE_PWM_ADJUST_End_HZ;
	App_Project_ValveDriver_Period_Param.Valve_PWM_Spread_Spectrum_StepPeriod = VALVE_PWM_ADJUST_STEP_HZ;
	App_Project_ValveDriver_Period_Param.Valve_PWM_Spread_Spectrum_DefaultPeriod =VALVE_PWM_DEFAULT_OUT_HZ ;
	App_Project_ValveDriver_Period_Param.Valve_PWM_Spread_Spectrum_Step_Time = VALVE_PWM_ADJUST_STEP_TIME;
	App_Project_ValveDriver_Period_Param.Valve_PWM_Spread_Spectrum_EnFlag = FALSE;
	ValveCtrl_Driver_Period_Param_Init(&App_Project_ValveDriver_Period_Param);
	//PowerApp_SystemNoSleepEnSet(TRUE);

}

void App_System_DeInit(void)
{
	
}







/* ************************************************************************************************/
/*                                        End Of File: SystemTimer.c                               */
/* ************************************************************************************************/

