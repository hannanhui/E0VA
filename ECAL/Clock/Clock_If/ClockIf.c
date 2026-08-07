/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      C source file                                                            */
/*   Name         :      ClockIf.c                                                                */
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
#include "Ecal_Clock.h"


void Clock_System_Init(void)
{
	McalLib_Init();
    Mcu_Init(NULL_PTR);
    
    Mcu_InitClock(0u);
    
#if(MCU_NO_PLL == STD_OFF)
    while(MCU_PLL_LOCKED != Mcu_GetPllStatus());
    Mcu_DistributePllClock();
#endif /* MCU_NO_PLL == STD_OFF */
}




void Clock_Func_GPIO_Peripheral_En(void)
{
	
}

void Clock_Func_GPIO_Peripheral_Disable(void)
{


}

void Clock_Func_Init(void)
{
	Clock_Func_GPIO_Peripheral_En();
	//TBD
}

void CLOCK_Init(void)
{
	Clock_System_Init();
	
	Clock_Func_Init();
	
}

