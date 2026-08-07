
#include "include.h"

static uint16_t  Pressure_To_Lin[Digital_Pressure_Index11] ={0};
 uint32_t  Pressure_To_MBD[Digital_Pressure_Index11] ={0};

 int16_t  Temperature_PressureSensor[Digital_Pressure_Index11] ={0};


uint32_t Filtered_Pressure[Digital_Pressure_Index11] = {0};









/**
* @brief	   LIN获取修正后压力
* @details	   This is the detail description. 
* @param[out]  位置
* @retval	   对应压力
* @par 修改日志
*	   ZYG于2025/08/6创建
*/
uint16_t Func_Get_Pressure_To_LIN(Digital_Pressure_Index opIndex)
{
	if(opIndex>Digital_Pressure_Index11)
		{
			return 0U;
		}
	
		return Pressure_To_Lin[opIndex];
}


/**
* @brief	   MBD获取修正后压力
* @details	   This is the detail description. 
* @param[out]  位置
* @retval	   对应压力
* @par 修改日志
*	   ZYG于2025/08/19创建
*/
uint32_t Func_Get_Pressure_To_MBD(Digital_Pressure_Index opIndex)
{
	if(opIndex>Digital_Pressure_Index11)
		{
			return 0U;
		}
	
		return Pressure_To_MBD[opIndex];
}





/**
* @brief	   获取压力传感器对应的温度
* @details	   This is the detail description. 
* @param[out]  位置
* @retval	   对应温度
* @par 修改日志
*	   ZYG于2025/08/7创建
*/
uint8_t Func_Get_PressureTemperature(Digital_Pressure_Index opIndex)
{
	if(opIndex>Digital_Pressure_Index11)
		{
			return 0U;
		}
	
		return (uint8_t)Temperature_PressureSensor[opIndex];
}

/**
* @brief	   获取ntc温度
* @details	   This is the detail description. 
* @param[out]  位置
* @retval	   对应压力
* @par 修改日志
*	   ZYG于2025/08/7创建
*/
uint8_t Func_Get_NTC_Temperature(void)
{
	int16_t Value = 0;
	DigitalIf_Temperature_DataGet(Digital_Pressure_Index0,&Value);
	
	return (uint8_t)Value;
}



/**
* @brief	   压力数据处理
* @details	   This is the detail description. 
* @par 修改日志
*	   ZYG于2025/08/6创建
*/
void Func_Pressure_Task(void)
{

}


/**
* @brief	   压力数据处理
* @details	   This is the detail description. 
* @par 修改日志
*	   ZYG于2025/08/7创建
*/
void Func_Pressure_Init(void)
{
	init_all_filters();
}




