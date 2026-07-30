/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      C source file                                                            */
/*   Name         :      SystemModeIf.c                                                           */
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

#include "global_var.h"
#include "..\SystemMode.h"
#include "..\..\WatchDog\WatchDog_If\WatchDogIf.h"
#include "..\..\Port\PORT.h"
#include "..\..\Interrupt\Interrupt.h"

uint8_t Sleep_Status=0u;

uint32_t SystemModeRstSrc =0u;


void SystemMode_Clear_External_WakeupIntFlag(void)
{
		
}
void SystemMode_WakeupPinDisable(void)
{
		/*In the current hardware design, the 5V power supply will be disconnected after sleep, 
			and after the LIN transceiver wakes up, the 5V power supply will be turned on, 
			and the MCU will run again, so there is no need key wake up and LIN wake up.
			*/
}
#if EXTERN_WAKEUP_KEY_EN
void intp10_interrupt(void)
{
    //INTC_ClearPendingIRQ(INTP10_IRQn);
	//INTP_Stop(INTP10);
	Sleep_Status =0u;
		/* clear KEY interrupt flag */
    /* Start user code. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}
#endif
#if EXTERN_WAKEUP_LIN_EN
void intp0_interrupt(void)
{
    //INTC_ClearPendingIRQ(INTP0_IRQn);
	//INTP_Stop(INTP0);
	Sleep_Status =0u;
		/* clear KEY interrupt flag */
    /* Start user code. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}
#endif
#if EXTERN_WAKEUP_IGN_EN
void intp3_interrupt(void)
{
    //INTC_ClearPendingIRQ(INTP3_IRQn);
	//INTP_Stop(INTP3);
	Sleep_Status =0u;
		/* clear KEY interrupt flag */
    /* Start user code. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}
#endif

void SystemMode_WakeupPinEnAndEdge_Config(void)
{
		
}
void SystemMode_WakeupPinDisable_Config(void)
{
	

}
void SystemMode_PMC_Error_Irq_Handler(void)
{
	


}
void SystemMode_PMC_Error_Init(void)
{
	
}


void SystemMode_WakeupIntp_Init(void)
{
	
		

}




void SystemMode__Entry_Standby(void)
{
	
}







static  bool RST_GetSrcStatusCmd(const RST_Source_names_t srcName)
{
  return 1;
}

void SystemMode_CheckResetSrc(void)
{
	

	

	
}

void SystemMode_Wakeup_Init(void)
{
	Sleep_Status =0u;
}



