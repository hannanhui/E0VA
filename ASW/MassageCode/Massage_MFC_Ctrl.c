/*
 * @Author: yinggangzhang yinggangzhang@tangtring.com
 * @Date: 2025-09-17 10:19:12
 * @LastEditors: yinggangzhang yinggangzhang@tangtring.com
 * @LastEditTime: 2025-10-28 16:11:05
 * @FilePath: \MeaaageCode\Massage_Ctrl.c
 * @Description: 杩欐槸榛樿?よ?剧疆,璇疯?剧疆`customMade`, 鎵撳紑koroFileHeader鏌ョ湅閰嶇疆 杩涜?岃?剧疆: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */



#include "include.h"
//#include "Massage_Ctrl.h"
//#include "Massage_MFC_Map.h"




extern const Massage_Mode_Info_Type Massage_Mode_Info[MSSG_MODE_MAX];



Massage_Info_Type Massage_Ctrl;

/**
* @brief	 Massage stop
* @details	   This is the detail description. 
* @par 修改日志
*	   ZYG于2025/09/23创建
*/
static void Massage_Stop(void)
{
    Massage_Ctrl.Mapping = 0UL;
    Massage_Ctrl.Curr_Step = 0U;
    Massage_Ctrl.RollStartStep = 0U;
    Massage_Ctrl.ticks = 0U;
    Massage_Ctrl.MssgState = MSSG_CTL_IDLE;
    Massage_Ctrl.Enable = FALSE;
    Massage_Ctrl.PumpState = 0U;
    Massage_Ctrl.RunState = FALSE;
}

/**
* @brief	 Massage Initialize
* @details	   This is the detail description. 
* @par 修改日志
*	   ZYG于2025/09/23创建
*/
void Massage_Init(void)
{
    Massage_Ctrl.Mapping = 0UL;
    Massage_Ctrl.Curr_Step = 0U;
    Massage_Ctrl.RollStartStep = 0U;
    Massage_Ctrl.ticks = 0U;
    Massage_Ctrl.PumpState = 0U;
    Massage_Ctrl.RunState = FALSE;
}


/**
* @brief	  Massage set mode
* @details	   This is the detail description. 
* @param[in]   mode
* @par 修改日志
*	   ZYG于2025/09/23创建
*/
void Set_Massage_Mode(uint8_t mode)
{
    if(mode>=0 && mode<8)
    {
        Massage_Ctrl.Mode  = mode;
    }
}


/**
* @brief	  Massage set Grade
* @details	   This is the detail description. 
* @param[in]   Grade
* @par 修改日志
*	   ZYG于2025/09/23创建
*/
void Set_Massage_Grade(uint8_t grade)
{
    if(grade>=0 && grade<3)
    {
        Massage_Ctrl.Grade = grade;
    }
}


/**
* @brief	  Massage set Enable
* @details	   This is the detail description. 
* @param[in]   Enable
* @par 修改日志
*	   ZYG于2025/09/23创建
*/
void Set_Massage_Enable(uint8_t OnOff)
{
    
}

/**
* @brief	  get valve map bit
* @details	   This is the detail description. 
* @param[in]   loction
* @retval	   valve state
* @par 修改日志
*	   ZYG于2025/09/23创建
*/
BOOL Get_Out_Valve_Map_Bit(BAG_INDEX_TYPE Index)
{
    return GET_BIT(Massage_Ctrl.Mapping,Index);
}

/**
* @brief	  get pump state
* @details	   This is the detail description. 
* @retval	   pump state
* @par 修改日志
*	   ZYG于2025/09/23创建
*/
BOOL Get_Out_Massage_PumpState(void)
{
    return  Massage_Ctrl.PumpState;
}

/**
* @brief	  get RUN state
* @details	   This is the detail description. 
* @retval	   pump state
* @par 修改日志
*	   ZYG于2025/09/23创建
*/
uint8_t* Get_Out_Massage_pRunState(void)
{
    return  &Massage_Ctrl.RunState;
}

/**
* @brief	 updata massage information
* @details	  reset massage information
* @par 修改日志
*	   ZYG于2025/09/23创建
*/
static void Mode_updata_RestInfo(void)
{
	static uint8_t Backup_mode = MSSG_MODE_MAX;
	if(Massage_Ctrl.Mode!=Backup_mode)
	{
		Backup_mode	= Massage_Ctrl.Mode;
		Massage_Ctrl.ticks = 0U;
		Massage_Ctrl.Curr_Step = 0U;
		Massage_Ctrl.repeat = 0U;
	}
}


/**
* @brief	 According to the execution of massage movements
* @details	   This is the detail description. 
* @param[in]   Massage information
* @par 修改日志
*	   ZYG于2025/09/23创建
*/
static void Massage_Active(Massage_Parameter mode)
{
    
}


/**
* @brief	 massage step deal
* @details	   This is the detail description. 
* @param[in]   Massage group information
* @par 修改日志
*	   ZYG于2025/09/23创建
*/
void Massage_step(Massage_Mode_Info_Type ModeInfo)
{
	
}

/**
* @brief	 massage run Corresponding pattern
* @details	   This is the detail description. 
* @par 修改日志
*	   ZYG于2025/09/23创建
*/
void Massage_Run(void)
{
	
}


/**
* @brief	 massage state machine
* @details	   This is the detail description. 
* @par 修改日志
*	   ZYG于2025/09/23创建
*/
void Massage_Task_Deal(void)
{
    switch (Massage_Ctrl.MssgState)
    {
    case MSSG_CTL_IDLE: //idle
        Massage_Stop();
        break;
    case MSSG_RUN://Run
        Massage_Run();
        break;
    case MSSG_STOP://Stop
        Massage_Stop();
        break;
    case MSSG_FAULT://Fault
        Massage_Stop();
        break;
    
    default:
        break;
    }
}

/**
* @brief	 massage task 10ms
* @details	   This is the detail description. 
* @par 修改日志
*	   ZYG于2025/09/23创建
*/
void Massage_Task_10ms(void)
{
    Massage_Task_Deal();
}





