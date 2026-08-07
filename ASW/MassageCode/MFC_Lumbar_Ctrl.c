/*
 * @Author: yinggangzhang yinggangzhang@tangtring.com
 * @Date: 2025-10-10 13:54:34
 * @LastEditors: yinggangzhang yinggangzhang@tangtring.com
 * @LastEditTime: 2025-10-28 16:36:54
 * @FilePath: \MassageCode\MFC_Lumbar_Ctrl.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

#include "include.h"
// #include "MFC_Lumbar_Ctrl.h"

Lumbar_Info_Type Lumbar_Ctrl;

static uint8_t BagOverPressureFlag[Lumb_OTHER] = {FALSE};

void Lumbar_Init(void)
{
	Lumbar_Ctrl.Lumbar_Func = LumbFunc_IDLE;
	Lumbar_Ctrl.Lumbar_State = LumbState_IDLE;
	Lumbar_Ctrl.Bag_Info[Lumb_UP].ticks = 0;
	Lumbar_Ctrl.Bag_Info[Lumb_DOWN].ticks = 0;
	Lumbar_Ctrl.RunFlag  = FALSE;
}


void Set_Lumbar_Function(uint8 u8Value)
{
	
	
}


void Set_Lumbar_Pressure(Lumbar_BagNum_Type Index,uint32_t u32Value)
{
	
}	



uint8_t* Get_Lumbar_pRunState(void)
{
	return &Lumbar_Ctrl.RunFlag ; 
}

/**
* @brief	  get pump state
* @details	   This is the detail description. 
* @retval	   pump state
* @par 修改日志
*	   ZYG于2025/10/29创建
*/
BOOL Get_Out_Lumbar_PumpState(void)
{
    return  Lumbar_Ctrl.PumpState;
}




Lumbar_BagRun_Type Get_LumbarBagState(Lumbar_BagNum_Type Index)
{
	if(Lumb_OTHER <= Index)
	{
		return LumbBag_IDLE;
	}

	return Lumbar_Ctrl.Bag_Info[Index].BagState;
}







static void Lumbar_Stop(void)
{
	
}



static void Lumbar_RunBagState_Deal(Lumbar_BagNum_Type Index ,Lumbar_BagRun_Type LumbBagState)
{
	
}

static void Lumbar_RunState_To_EndState_Judge(void)
{
	
}

static void Lumbar_RunState_Pump(void)
{
	
}


static void Lumbar_Run(void)
{
	
}


static void LumbarState_Process(void)
{
	
}


void Lumbar_Task(void)
{
	LumbarState_Process();
}



