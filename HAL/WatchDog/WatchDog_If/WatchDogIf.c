/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      C source file                                                            */
/*   Name         :      WatchDogIf.c                                                             */
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

#include "..\WatchDog.h"

#include "Type_Define.h"
#define WDOGTEST_INTTEST_WINDOWVALUE   0x00000000U


static void WDOG_HwWdogInit(void)
{
    WDOG_Config_t tWDOGInitConfig;
    
    tWDOGInitConfig.clkSource = WDOG_LPO_CLOCK;
    tWDOGInitConfig.wait = DISABLE;
    tWDOGInitConfig.stop = DISABLE;
    tWDOGInitConfig.debug = DISABLE;
    tWDOGInitConfig.winEnable = DISABLE;
    tWDOGInitConfig.timeoutValue = 0xffff;
    tWDOGInitConfig.windowValue = WDOGTEST_INTTEST_WINDOWVALUE;
    tWDOGInitConfig.testMode = WDOG_TST_NORMAL;

    WDOG_Init(&tWDOGInitConfig);
}


void WDOGHW_IntCallBack(void)
{
    WDOG_SetTestMode(WDOG_TST_MODE1);
}


void WatchDogIf_Enable(void)
{
	/* Enable wdog */
    WDOG_Enable();
}


void WatchDogIf_Init(void)
{
	/* Reset Wdog */
    SYSCTRL_ResetModule(SYSCTRL_WDOG);
    /* Enable Wdog clock */
    SYSCTRL_EnableModule(SYSCTRL_WDOG);
    /* Wdog Init*/
    WDOG_HwWdogInit();

    /* Set wdog callback function*/
    WDOG_InstallCallBackFunc(WDOG_INT_BEFORERESET, WDOGHW_IntCallBack);
    /* Enable WDOG interrupt */
    WDOG_IntMask(WDOG_INT_BEFORERESET, UNMASK);
    /* Enable Wdog interrupt */
    INT_EnableIRQ(WDOG_IRQn);
}

void FeedWatchdog(void)
{
	return;
/*
    uint32_t tmp;
#if (defined(DEV_Z20K118M)) || (defined(DEV_Z20K116M)) || (defined(DEV_Z20K114M))
    tmp = __get_PRIMASK();
#else
    __asm volatile( "MRS %0, PRIMASK " : "=r"(tmp));
#endif
    
    if(tmp == 0U)
    {
       INT_All_Enable(FALSE);
    }
    
    WDOG->WDOG_CNT.CNT = 0xA0C4B1D6U; 
    WDOG->WDOG_CNT.CNT = 0x1E0D0C7BU;
    
    if(tmp == 0U)
    {
        INT_All_Enable(TRUE);
    }*/
}


void WatchDogIf_Disable(void)
{	
	WDOG_Disable();
	
}

void WatchDogIf_Free(void)
{
	
	
	WDOG_Refresh();

}

