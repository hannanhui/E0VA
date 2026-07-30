/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      C source file                                                            */
/*   Name         :      Interrupt.c                                                              */
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
#include "include.h"
void INT_All_Enable (uint8_t NewState)
{
	if(TRUE == NewState)
	{
			__asm( "cpsie i" );
	}
	else
	{
		 __asm( "cpsid i" );
	}
}
extern uint8 APP_Jump;
extern volatile uint8 Dcm_Send_1002;
void UART0_IRQHandler()
{
    LIN_LPUART_Total_IRQHandler(0);
										/*if(APP_Jump == 0x01)
										{
											LIN_DRV_AbortTransferData(0);
											Dcm_Send_1002 = 1;
										}*/
}

void UART1_IRQHandler()
{
   // LIN_LPUART_DRV_IRQHandler(UART1_ID);
}

void UART2_IRQHandler()
{
    //LIN_LPUART_DRV_IRQHandler(UART2_ID);
}

void UART3_IRQHandler()
{
   // LIN_LPUART_DRV_IRQHandler(UART3_ID);
}
