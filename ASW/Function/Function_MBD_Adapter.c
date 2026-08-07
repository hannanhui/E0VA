
#include "include.h"






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


/**
* @brief	   按摩使能
* @details	   This is the detail description. 
* @par 修改日志
*	   ZYG于2025/08/5创建
*/
static void Func_MBD_Get_MassageEn(void)
{
	BOOL ret = FALSE;
	ret = uint8_t_rd_LI0_TBL0_MVP17_Req_MassageEnable();
	AppInto_MassageEnable = ret;
}

/**
* @brief	   按摩模式
* @details	   This is the detail description. 
* @par 修改日志
*	   ZYG于2025/08/5创建
*/
static void Func_MBD_Get_MassageMode(void)
{

	uint8_t ret = 0;
	ret = uint8_t_rd_LI0_TBL0_MVP17_Req_MassageMode();
	if(ret>=0 && ret<=9)
	{
		AppInto_MassageMode = ret;
		uint8_t_wr_LI0_TBL0_FK_MassageMode(ret);
	}
}

/**
* @brief	   腰托模式
* @details	   This is the detail description. 
* @par 修改日志
*	   ZYG于2025/08/6创建
*/
static void Func_MBD_Get_LumbarReq(void)
{
	Lumbar_Key_Type Loc_Value = Get_Lumbar_Key_Value();
	//Lumbar_Key_Type Loc_Value = LumbarKey_IDLE;
	if(Loc_Value!= LumbarKey_IDLE)
		{

			AppInto_LumbarFunc = (uint8_t)Loc_Value;
		}
	else
		{
			AppInto_LumbarFunc = uint8_t_rd_LI0_TBL0_MVP17_Req_Lumbar();
		}

}


/**
* @brief	   侧翼模式
* @details	   This is the detail description. 
* @par 修改日志
*	   ZYG于2025/08/6创建
*/
static void Func_MBD_Get_FlankReq(void)
{

	AppInto_FlankFunc = uint8_t_rd_LI0_TBL0_MVP17_Req_Flank();
}



/**
* @brief	   按摩力度
* @details	   This is the detail description. 
* @par 修改日志
*	   ZYG于2025/08/19创建
*/
static void Func_MBD_Get_MassageGrade(void)
{

	uint8_t ret = 0;
	ret = uint8_t_rd_LI0_TBL0_MVP17_Req_MassageGrade();
	if(ret>=0 && ret<=2)
	{
		AppInto_MassageGrade = ret;
		uint8_t_wr_LI0_TBL0_FK_MassageGrade(ret);
	}
}



/**
* @brief	   主动侧翼
* @details	   使能
* @par 修改日志
*	   ZYG于2025/08/19创建
*/
static void Func_MBD_Get_ActiveFlankEn(void)
{

	AppInto_ActiveFlankEn = uint8_t_rd_LI0_TBL0_MVP17_Req_Active_Flank_Switch();
}


/**
* @brief	   主动侧翼
* @details	   模式
* @par 修改日志
*	   ZYG于2025/08/19创建
*/
static void Func_MBD_Get_ActiveFlankMode(void)
{
	uint8_t ret = 0;
	ret = uint8_t_rd_LI0_TBL0_MVP17_Req_Active_Flank_Ctrl();
	if(ret>=0 && ret<=4)
	{
		AppInto_ActiveFlankMode = ret;
	}
}

/**
* @brief	   主动侧翼
* @details	   灵敏等级
* @par 修改日志
*	   ZYG于2025/08/19创建
*/
static void Func_MBD_Get_ActiveFlankSensitivity(void)
{
	uint8_t ret = 0;
	ret = uint8_t_rd_LI0_TBL0_MVP17_Req_Active_Flank_Sensitivity();
	if(ret>=0 && ret<=2)
	{
		AppInto_ActiveFlankSensitivity = ret;
	}

}


/**
* @brief	   自适应侧翼
* @details	   使能
* @par 修改日志
*	   ZYG于2025/08/19创建
*/
static void Func_MBD_Get_AdaptiveFlank(void)
{
	AppInto_AdaptiveFlank = uint8_t_rd_LI0_TBL0_MVP17_Req_Adaptive_Flank_Switch();
}


/**
* @brief	   自适应腰托
* @details	   使能
* @par 修改日志
*	   ZYG于2025/08/19创建
*/
static void Func_MBD_Get_AdaptiveLumbar(void)
{
	AppInto_AdaptiveLumbar =uint8_t_rd_LI0_TBL0_MVP17_Req_Adaptive_Lumbar_Switch();
}


/**
* @brief	   获取故障状态
* @details	   故障
* @par 修改日志
*	   ZYG于2025/09/26创建
*/
static void Func_MBD_Get_FaultState(void)
{

	if(FaultDiag_BattVol_StatusGet()==BAT_VOL_STA_UNDER||FaultDiag_BattVol_StatusGet()==BAT_VOL_STA_OVER)
	{
		AppInto_FaultState = 1U<<0U;
	}
	else
	{
		AppInto_FaultState &= ~(1U<<0U);
	}
	
	if (FaultDiag_BoardTemp_StatusGet()!=BOARD_TEMP_STATE_NORMAL)
	{
		AppInto_FaultState = 1U<<1U;
	}
	else
	{
		AppInto_FaultState  &= ~(1U<<1U);
	}

	if(FaultDiag_PumpFault_StatusGet()!=PUMP_FAULT_NORMAL)
	{
		AppInto_FaultState = 1U<<2U;
	}
	else
	{
		AppInto_FaultState  &= ~(1U<<2U);
	}

	if (FaultDiag_ValveFault_StatusGet() == VALVE_DIAG_SHORT)
	{
		AppInto_FaultState = 1U<<3U;
	}
	else
	{
		AppInto_FaultState  &= ~(1U<<3U);
	}

	if (Vehicle_Action.Bus_Action_GetLinTimeoutFlag())
	{
		AppInto_FaultState = 1U<<4U;
	}
	else
	{
		AppInto_FaultState  &= ~(1U<<4U);
	}
	
}




/**
* @brief	   腰托压力
* @details	   
* @par 修改日志
*	   ZYG于2025/08/19创建
*/
static void Func_Get_MBD_Press(void)
{
	AppInto_GasStoragePress = Func_Get_Pressure_To_MBD(Digital_Pressure_Index0);
	
	if( BOOL_rd_LI0_TBL0_MVP17_Req_PressEn())
	{
		AppInto_FlankPress[0] = 0U;
		AppInto_FlankPress[1] = 0U;

		AppInto_F_SensorPress[0] = 0U;
		AppInto_F_SensorPress[1] = 0U;

		AppInto_LumbarPress[0] = 0U;
		AppInto_LumbarPress[1] = 0U;

		AppInto_L_SensorPress[0] = 0U;
		AppInto_L_SensorPress[1] = 0U;
		
		return;
	}
	
	AppInto_FlankPress[0] = Func_Get_Pressure_To_MBD(Digital_Pressure_Index5);
	AppInto_FlankPress[1] = Func_Get_Pressure_To_MBD(Digital_Pressure_Index4);

	AppInto_F_SensorPress[0] = Func_Get_Pressure_To_MBD(Digital_Pressure_Index7);
	AppInto_F_SensorPress[1] = Func_Get_Pressure_To_MBD(Digital_Pressure_Index3);

	AppInto_LumbarPress[0] = Func_Get_Pressure_To_MBD(Digital_Pressure_Index2);
	AppInto_LumbarPress[1] = Func_Get_Pressure_To_MBD(Digital_Pressure_Index1);

	AppInto_L_SensorPress[0] = Func_Get_Pressure_To_MBD(Digital_Pressure_Index9);
	AppInto_L_SensorPress[1] = Func_Get_Pressure_To_MBD(Digital_Pressure_Index8);		
}



/**
* @brief	   腰托气袋适配
* @details	   This is the detail description. 
* @par 修改日志
*	   ZYG于2025/08/6创建
*/
static void Lumbar_MBD_Adaper_HW(void)
{

//	ValveCtrl_Drive_Output_If(VALVE_DRIVING_INDEX13,AppOut_LumbarBag[0]&1U);
//	ValveCtrl_Drive_Output_If(VALVE_DRIVING_INDEX20,AppOut_LumbarBag[0]>>1U);

	ValveCtrl_Drive_Output_If(VALVE_DRIVING_INDEX14,AppOut_LumbarBag[0]&1U);//01 10
	ValveCtrl_Drive_Output_If(VALVE_DRIVING_INDEX21,AppOut_LumbarBag[0]>>1U);

	ValveCtrl_Drive_Output_If(VALVE_DRIVING_INDEX15,AppOut_LumbarBag[1]&1U);
	ValveCtrl_Drive_Output_If(VALVE_DRIVING_INDEX22,AppOut_LumbarBag[1]>>1U);

	uint8_t_wr_LI0_TBL0_Lumbar_UP(AppOut_LumbarBag[0]);
	uint8_t_wr_LI0_TBL0_Lumbar_Down(AppOut_LumbarBag[1]);
}


/**
* @brief	   侧翼气袋适配
* @details	   This is the detail description. 
* @par 修改日志
*	   ZYG于2025/08/6创建
*/
static void Flank_MBD_Adaper_HW(void)
{

	ValveCtrl_Drive_Output_If(VALVE_DRIVING_INDEX11,AppOut_FlankBag[0]&1U);
	ValveCtrl_Drive_Output_If(VALVE_DRIVING_INDEX24,AppOut_FlankBag[0]>>1U);

	ValveCtrl_Drive_Output_If(VALVE_DRIVING_INDEX12,AppOut_FlankBag[1]&1U);
	ValveCtrl_Drive_Output_If(VALVE_DRIVING_INDEX23,AppOut_FlankBag[1]>>1U);

	uint8_t_wr_LI0_TBL0_Flank_Left(AppOut_FlankBag[0]);
	uint8_t_wr_LI0_TBL0_Flank_Right(AppOut_FlankBag[1]);
	

}


/**
* @brief	   感应气袋适配
* @details	   This is the detail description. 
* @par 修改日志
*	   ZYG于2025/08/18创建
*/
static void SensorBag_MBD_Adaper_HW(void)
{

	ValveCtrl_Drive_Output_If(VALVE_DRIVING_INDEX8,AppOut_SensorBag[0]&1U);
	ValveCtrl_Drive_Output_If(VALVE_DRIVING_INDEX2,AppOut_SensorBag[0]>>1U);

	ValveCtrl_Drive_Output_If(VALVE_DRIVING_INDEX9,AppOut_SensorBag[1]&1U);
	ValveCtrl_Drive_Output_If(VALVE_DRIVING_INDEX3,AppOut_SensorBag[1]>>1U);

	ValveCtrl_Drive_Output_If(VALVE_DRIVING_INDEX10,AppOut_SensorBag[2]&1U);
	ValveCtrl_Drive_Output_If(VALVE_DRIVING_INDEX4,AppOut_SensorBag[2]>>1U);
	
	ValveCtrl_Drive_Output_If(VALVE_DRIVING_INDEX13,AppOut_SensorBag[3]&1U);
	ValveCtrl_Drive_Output_If(VALVE_DRIVING_INDEX20,AppOut_SensorBag[3]>>1U);

	uint8_t_wr_LI0_TBL0_Sensor_Bag1(AppOut_SensorBag[0]);
	uint8_t_wr_LI0_TBL0_Sensor_Bag2(AppOut_SensorBag[1]);
	uint8_t_wr_LI0_TBL0_Sensor_Bag3(AppOut_SensorBag[2]);
	uint8_t_wr_LI0_TBL0_Sensor_Bag4(AppOut_SensorBag[3]);
}

/**
* @brief	   储气罐适配
* @details	   This is the detail description. 
* @par 修改日志
*	   ZYG于2025/08/18创建
*/
static void GasStorage_MBD_Adaper_HW(void)
{
	ValveCtrl_Drive_Output_If(VALVE_DRIVING_INDEX5,AppOut_GasStorage);
	uint8_t_wr_LI0_TBL0_GasStorage(AppOut_GasStorage);

}



/**
* @brief	   适配硬件
* @details	   This is the detail description. 
* @param[in]   self 按摩任务结构体
* @param[out]  outArgName output argument description. 
* @retval	   OK	   成功
* @retval	   ERROR   错误 
* @par 标识符
*	   保留
* @par 其它
*	   无
* @par 修改日志
*	   ZYG于2025/08/4创建
*/
void MBD_Adapter_HW(void)
{
//	Valve_Supply_Status_Set(TRUE);
	PumpCtrl_Drive_Output_If(PUMP_DRIVING_TYPE_IO,100,AppOut_PumpState);
	// VALVE POWER OUTPUT
//	DigitalIf_IoWt_DataSet(Digital_IoWt_Index2,1U);
//	// VALVE DIAG CTRL
//	DigitalIf_IoWt_DataSet(Digital_IoWt_Index4,TRUE);
//	// PUMP POWER OUTPUT
//	DigitalIf_IoWt_DataSet(Digital_IoWt_Index0,TRUE);
//	// PUMP DIAG CTRL
//	DigitalIf_IoWt_DataSet(Digital_IoWt_Index8,TRUE);


//	ValveCtrl_Drive_Output_If(VALVE_DRIVING_INDEX16,AppOut_MassageBag[0]);
//	ValveCtrl_Drive_Output_If(VALVE_DRIVING_INDEX17,AppOut_MassageBag[1]);
//
//	ValveCtrl_Drive_Output_If(VALVE_DRIVING_INDEX18,AppOut_MassageBag[2]);
//	ValveCtrl_Drive_Output_If(VALVE_DRIVING_INDEX19,AppOut_MassageBag[3]);
//	ValveCtrl_Drive_Output_If(VALVE_DRIVING_INDEX6,AppOut_MassageBag[4]);
//	ValveCtrl_Drive_Output_If(VALVE_DRIVING_INDEX7,AppOut_MassageBag[5]);
//	ValveCtrl_Drive_Output_If(VALVE_DRIVING_INDEX1,AppOut_MassageBag[6]);
//	ValveCtrl_Drive_Output_If(VALVE_DRIVING_INDEX0,AppOut_MassageBag[7]);

	ValveCtrl_Drive_Output_If(VALVE_DRIVING_INDEX19,AppOut_MassageBag[0]);
	ValveCtrl_Drive_Output_If(VALVE_DRIVING_INDEX6,AppOut_MassageBag[1]);
	ValveCtrl_Drive_Output_If(VALVE_DRIVING_INDEX18,AppOut_MassageBag[2]);
	ValveCtrl_Drive_Output_If(VALVE_DRIVING_INDEX7,AppOut_MassageBag[3]);
	ValveCtrl_Drive_Output_If(VALVE_DRIVING_INDEX17,AppOut_MassageBag[4]);
	ValveCtrl_Drive_Output_If(VALVE_DRIVING_INDEX1,AppOut_MassageBag[5]);
	ValveCtrl_Drive_Output_If(VALVE_DRIVING_INDEX16,AppOut_MassageBag[6]);
	ValveCtrl_Drive_Output_If(VALVE_DRIVING_INDEX0,AppOut_MassageBag[7]);

	//BOOL_wr_LI0_TBL0_PumpState(AppOut_PumpState);

	BOOL_wr_LI0_TBL0_Massage_Dot1(AppOut_MassageBag[0]);
	BOOL_wr_LI0_TBL0_Massage_Dot2(AppOut_MassageBag[1]);
	BOOL_wr_LI0_TBL0_Massage_Dot3(AppOut_MassageBag[2]);
	BOOL_wr_LI0_TBL0_Massage_Dot4(AppOut_MassageBag[3]);
	BOOL_wr_LI0_TBL0_Massage_Dot5(AppOut_MassageBag[4]);
	BOOL_wr_LI0_TBL0_Massage_Dot6(AppOut_MassageBag[5]);
	BOOL_wr_LI0_TBL0_Massage_Dot7(AppOut_MassageBag[6]);
	BOOL_wr_LI0_TBL0_Massage_Dot8(AppOut_MassageBag[7]);

	Lumbar_MBD_Adaper_HW();
	Flank_MBD_Adaper_HW();
	SensorBag_MBD_Adaper_HW();
	GasStorage_MBD_Adaper_HW();

}

/**
* @brief	   输出到LIN信号
* @details	   This is the detail description. 
* @param[in]   
* @param[out]  outArgName output argument description. 
* @par 修改日志
*	   ZYG于2025/10/24创建
*/
static void MBD_Out_Message(void)
{

	uint8_t_wr_LI0_TBL0_MVP17_State_MassageSwitch(AppOut_RunState.Massage);



}



/**
* @brief	   根据模式设置按摩驱动曲线
* @details	   This is the detail description. 
* @param[in]   
* @param[out]  outArgName output argument description. 
* @retval	   OK	   成功
* @par 修改日志
*	   ZYG于2025/09/10创建
*/
static void Massage_MBD_Select_VolCurve(void)
{
	static BOOL Lock =TRUE;
	if ((AppInto_MassageMode ==0||
		AppInto_MassageMode ==1||
		AppInto_MassageMode ==2||
		AppInto_MassageMode ==7)&&Lock)
	{
		MassageValve_Vol_Curve0_Set();
		Lock = FALSE;
	}

	if ((AppInto_MassageMode ==3||
		AppInto_MassageMode ==4||
		AppInto_MassageMode ==5||
		AppInto_MassageMode ==6)&& !Lock)
	{
		MassageValve_Vol_Curve4_Set();
		Lock = TRUE;
	}		
	//...
}



/**
* @brief	   根据模式设置储气罐驱动曲线
* @details	   This is the detail description. 
* @param[in]   
* @param[out]  outArgName output argument description. 
* @retval	   OK	   成功
* @par 修改日志
*	   ZYG于2025/11/14创建
*/
static void GasStorage_MBD_Select_VolCurve(void)
{
//	uint32_t Loc_Pressure;
//	static GasStoragePressure_Type LocState = GasStoragePressure_Dowm;
//	
//	Loc_Pressure = Func_Get_Pressure_To_MBD(Digital_Pressure_Index0);
//	if (Loc_Pressure<35000)
//	{
//		if (LocState!= GasStoragePressure_Dowm)
//		{
//			LocState = GasStoragePressure_Dowm;
//		}
//	}
//	else if(Loc_Pressure>40000)
//	{
//		if (LocState != GasStoragePressure_Up)
//		{
//			LocState = GasStoragePressure_Up;
//		}
//	}
//	else
//	{
//	
//	}
//	
//	if (LocState == GasStoragePressure_Up)
//	{
//		GasStorageValve_Vol_Curve5_Set();
//	}
//	else
//	{
//		GasStorageValve_Vol_Curve3_Set();
//	}	

	GasStorageValve_Vol_Curve3_Set();
//	GasStorageValve_Vol_Curve5_Set();
}


/**
* @brief	   模型任务
* @details	   This is the detail description. 
* @param[in]   self 按摩任务结构体
* @param[out]  outArgName output argument description. 
* @retval	   OK	   成功
* @par 修改日志
*	   ZYG于2025/08/4创建
*/
void MBD_Task(void)
{
	//设置输入
	Func_MBD_Get_MassageEn();
	Func_MBD_Get_MassageMode();
	Func_MBD_Get_MassageGrade();
	Func_MBD_Get_LumbarReq();
	Func_MBD_Get_FlankReq();
	Func_MBD_Get_ActiveFlankEn();
	Func_MBD_Get_ActiveFlankMode();
	Func_MBD_Get_ActiveFlankSensitivity();
	Func_MBD_Get_AdaptiveFlank();
	Func_MBD_Get_AdaptiveLumbar();
	Func_Get_MBD_Press();
	Func_MBD_Get_FaultState();

	BackMassage_Model_step();	//MBD
	
	MBD_Adapter_HW();
	Massage_MBD_Select_VolCurve();
	//GasStorage_MBD_Select_VolCurve();//曲线
	Valve_Vol_Curve_Effect();
	MBD_Out_Message();
}







