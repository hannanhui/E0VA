/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      C source file                                                            */
/*   Name         :      ClockIf.c                                                                */
/*   Instance     :                                                                               */
/*   Author       :      Ed                                                                       */
/*   Modify date  :      2025-12-22 14:00:05 PM                                                   */
/*   Description  :                                                                               */
/*                                                                                                */
/*                                                                                                */
/*   Compiler    :       KungFu32 IDE  [Version: V1.0.20.3]                                       */
/*   Hardware    :       ChipOn microcontroller KF32A Family [KF32A156MQV]                        */
/*   Version     :       V1.0                                                                     */
/*                                                                                                */
/*                                                                                                */
/*   All rights reserved. Distribution or duplication without previous written agreement of the   */
/*   owner prohibited.                                                                            */
/*                                                                                                */
/**************************************************************************************************/
#include "..\Clock.h"

#define CLK_LIN_ID         CLK_UART0



/* PLL parameter structure*/
CLK_PLLConfig_t PLL120M =
{
    .pllPreDivider = PLL_PRE_DIV_VALUE_1,       /* PLL pre divider value is 4 */
    .pllPostDivider = PLL_POST_DIV_VALUE_8,    /* PLL post divider value is 12 */
    .pllMultiplier = 60,                        /* PLL multiplier value is 48 */
    .pllRefClock = PLL_OSC_CLK,                 /* PLL select OSC as reference clock */
    .pllPreScaler = PLL_SCALER_VALUE_2,         /* PLL prescaler value is 2 */
};

/* Board clock init function */
void Ex_ClockInit(void)
{
    /* Enable OSC40M */
    CLK_OSC40MEnable(CLK_OSC_FREQ_MODE_LOW, ENABLE, CLK_OSC_XTAL);

    /* Set Flash wait-state value to AHB clock <=96M mode*/
    FLASH_SetWaitState(3);

    /* Init PLL as 80M */
    CLK_PLLConfig(&PLL120M);
    CLK_PLLEnable(ENABLE);


    /* Choose PLL as system clock */
    while(CLK_SysClkSrc(CLK_SYS_PLL));

    /* Set Core and bus clock */
    CLK_SetClkDivider(CLK_CORE, CLK_DIV_1);
    CLK_SetClkDivider(CLK_BUS, CLK_DIV_2);
    //CLK_SetClkDivider(CLK_UART0, CLK_DIV_6);
    
    // ??????8M?¨¦¨®?¦Ì?
    // CLK_ModuleSrc(CLK_LIN_ID, CLK_SRC_OSC40M);     // CLK_SRC_NO ,CLK_SRC_PLL
    // CLK_SetClkDivider(CLK_LIN_ID, CLK_DIV_1);
    
    // ¨®?????¦Ì?¨°2?¨¦¨°?¡ê?
    CLK_ModuleSrc(CLK_LIN_ID, CLK_SRC_PLL);     // CLK_SRC_NO ,CLK_SRC_PLL
    CLK_SetClkDivider(CLK_LIN_ID, CLK_DIV_6);
    

    /*Set Flash clock, please select SLOW clock source when using STOP mode function*/
    SYSCTRL_DisableModule(SYSCTRL_FLASH);
    CLK_ModuleSrc(CLK_FLASH, CLK_SRC_OSC40M);
    CLK_SetClkDivider(CLK_FLASH, CLK_DIV_1);
    SYSCTRL_EnableModule(SYSCTRL_FLASH);
}




void Clock_System_Init(void)
{
	PMU_IsoClr();
      
    Ex_ClockInit();

    SYSCTRL_EnableModule(SYSCTRL_REGFILE);

    /* Select clock source for PORTB */
    CLK_ModuleSrc(CLK_PORTA, CLK_SRC_OSC40M);

}




void Clock_Func_GPIO_Peripheral_En(void)
{
	 /* Enable PORTB clock */
    SYSCTRL_EnableModule(SYSCTRL_PORTA);
    /*Config GPIO module*/
    SYSCTRL_EnableModule(SYSCTRL_GPIO);

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

