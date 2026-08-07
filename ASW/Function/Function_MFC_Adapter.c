
#include "include.h"

//#include "MassageCode\Massage_MFC_Ctrl.h"


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
* @brief	   set massage enable 
* @details	   This is the detail description. 
* @par 修改日志
*	   ZYG于2025/09/23创建
*/
static void MFC_Set_Massage_Enable(void)
{
	BOOL ret = FALSE;
	ret = uint8_t_rd_LI0_TBL0_MVP17_Req_MassageEnable();
	Set_Massage_Enable((uint8_t)ret);
}




/**
* @brief	   set massage mode 
* @details	   This is the detail description. 
* @par 修改日志
*	   ZYG于2025/09/23创建
*/
static void MFC_Set_Massage_Mode(void)
{
	uint8_t ret = 0;
	ret = uint8_t_rd_LI0_TBL0_MVP17_Req_MassageMode();
	if(ret>=0 && ret<=9)
	{
		Set_Massage_Mode(ret);
	}
}


/**
* @brief	   set massage grade 
* @details	   This is the detail description. 
* @par 修改日志
*	   ZYG于2025/09/23创建
*/
static void MFC_Set_Massage_Grade(void)
{
	uint8_t ret = 0;
	ret = uint8_t_rd_LI0_TBL0_MVP17_Req_MassageGrade();
	if(ret>=0 && ret<=2)
	{
		Set_Massage_Grade(ret);
	}
}

/**
* @brief	   腰托模式
* @details	   This is the detail description. 
* @par 修改日志
*	   ZYG于2025/10/29创建
*/
static void Func_MFC_Get_LumbarReq(void)
{
	uint8_t Loc_Value = Get_Lumbar_Key_Value();
	if(Loc_Value!= LumbarKey_IDLE)
		{
			Set_Lumbar_Function((uint8_t)Loc_Value);
		}
	else
		{
			Loc_Value = uint8_t_rd_LI0_TBL0_MVP17_Req_Lumbar();
			Set_Lumbar_Function((uint8_t)Loc_Value);
		}

}

/**
* @brief	   腰托压力
* @details	   
* @par 修改日志
*	   ZYG于2025/10/30创建
*/
static void Func_Get_MFC_Press(void)
{
	AppInto_GasStoragePress = Func_Get_Pressure_To_MBD(Digital_Pressure_Index0);
	
	if( BOOL_rd_LI0_TBL0_MVP17_Req_PressEn())
	{
		return;
	}

	Set_Lumbar_Pressure(Lumb_UP,Func_Get_Pressure_To_MBD(Digital_Pressure_Index2));
	Set_Lumbar_Pressure(Lumb_DOWN,Func_Get_Pressure_To_MBD(Digital_Pressure_Index1));
}






/**
* @brief	  function init
* @details	   This is the detail description. 
* @par 修改日志
*	   ZYG于2025/09/23创建
*/
void MFC_Adapter_Init(void)
{
//	Massage_Init();
	MFC_Ctrl_Init();

}

/**
* @brief	  adapter valve  hardware
* @details	   This is the detail description. 
* @par 修改日志
*	   ZYG于2025/10/29创建
*/
static void MFC_Lumbar_HW(void)
{
	ValveCtrl_Drive_Output_If(VALVE_DRIVING_INDEX14,Get_LumbarBagState(Lumb_UP)&1U);//01 10
	ValveCtrl_Drive_Output_If(VALVE_DRIVING_INDEX21,Get_LumbarBagState(Lumb_UP)>>1U);

	ValveCtrl_Drive_Output_If(VALVE_DRIVING_INDEX15,Get_LumbarBagState(Lumb_DOWN)&1U);
	ValveCtrl_Drive_Output_If(VALVE_DRIVING_INDEX22,Get_LumbarBagState(Lumb_DOWN)>>1U);
}


/**
* @brief	  adapter valve  hardware
* @details	   This is the detail description. 
* @par 修改日志
*	   ZYG于2025/09/23创建
*/
void MFC_Adapter_HW(void)
{
//	Valve_Supply_Status_Set(TRUE);
	PumpCtrl_Drive_Output_If(PUMP_DRIVING_TYPE_IO,100,Get_MFC_PumpState());
	// VALVE POWER OUTPUT
//	DigitalIf_IoWt_DataSet(Digital_IoWt_Index2,1U);

	ValveCtrl_Drive_Output_If(VALVE_DRIVING_INDEX19,Get_Out_Valve_Map_Bit(BAG_INDEX0));
	ValveCtrl_Drive_Output_If(VALVE_DRIVING_INDEX6,Get_Out_Valve_Map_Bit(BAG_INDEX1));
	ValveCtrl_Drive_Output_If(VALVE_DRIVING_INDEX18,Get_Out_Valve_Map_Bit(BAG_INDEX2));
	ValveCtrl_Drive_Output_If(VALVE_DRIVING_INDEX7,Get_Out_Valve_Map_Bit(BAG_INDEX3));
	ValveCtrl_Drive_Output_If(VALVE_DRIVING_INDEX17,Get_Out_Valve_Map_Bit(BAG_INDEX4));
	ValveCtrl_Drive_Output_If(VALVE_DRIVING_INDEX1,Get_Out_Valve_Map_Bit(BAG_INDEX5));
	ValveCtrl_Drive_Output_If(VALVE_DRIVING_INDEX16,Get_Out_Valve_Map_Bit(BAG_INDEX6));
	ValveCtrl_Drive_Output_If(VALVE_DRIVING_INDEX0,Get_Out_Valve_Map_Bit(BAG_INDEX7));

	MFC_Lumbar_HW();
}


/**
* @brief	  MFC task in 10ms
* @details	   This is the detail description. 
* @par 修改日志
*	   ZYG于2025/09/23创建
*/
void MFC_Adapter_Task(void)
{
	MFC_Set_Massage_Enable();
	MFC_Set_Massage_Mode();
	MFC_Set_Massage_Grade();
	Func_MFC_Get_LumbarReq();
	Func_Get_MFC_Press();
//	Massage_Task_10ms();
	MFC_Ctrl_Task();

	MFC_Adapter_HW();
}








