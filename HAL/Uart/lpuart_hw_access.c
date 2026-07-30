/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      C source file                                                            */
/*   Name         :      lpuart_hw_access.c                                                       */
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
/*
 * Copyright (c) 2013 - 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * THIS SOFTWARE IS PROVIDED BY NXP "AS IS" AND ANY EXPRESSED OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL NXP OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

/*!
 * @file lpuart_hw_access.c
 *
 * @page misra_violations MISRA-C:2012 violations
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 8.7, External could be made static.
 * The functions are only used by LPUART driver, errors appear for LIN driver where
 * they are not used.
 *
 * @section [global]
 * Violates MISRA 2012 Required Rule 10.3, Expression assigned to a
 * narrower or different essential type.
 * The assign operations are safe as the baud rate calculation algorithm cannot
 * overflow the result.
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 15.5, Return statement before end of
 * function .
 * The return statement before end of function is used for simpler code structure
 * and better readability.
 */

#include "lpuart_hw_access.h"
#include "MCAL.h"



/* *****************************************************************************
 * Code
 ******************************************************************************/


void LPUART_DRV_BREAK_Init(void)
{

}
void LPUART_Break_Timer_Detc_Start(void)
{

}
void LPUART_Break_Timer_Detc_Stop(void)
{

}

uint8_t LPUART_Break_Timer_Ovf_Det(void)
{
	uint8_t RetVal = FALSE;
	

	return RetVal;
}
uint32_t LPUART_Break_Timer_Counter_Val(void)
{
	uint32_t RetVal = 0;
	return RetVal;
}

uint8_t LPUART_Error_Status_Det(void)
{
	uint8_t RetVal = LIN_BUS_ERROR_TYPE_NO;
	

	return RetVal;
}






/*FUNCTION**********************************************************************
 *
 * Function Name : LPUART_SetIntMode
 * Description   : Configures the LPUART module interrupts to enable/disable
 * various interrupt sources.
 *END**************************************************************************/
void LPUART_SetIntMode(E_LPUART_IRQ_STATUS_TYPE reg, bool enable)
{

    switch (reg)
    {
        case LPUART_LIN_BREAK_DETECT:
        	if(enable)
			{
			//	USART_Blank_INT_Enable(LPUART_CHL_BASE, TRUE);		// 接收中断使能
			}
			else
			{
			//	USART_Blank_INT_Enable(LPUART_CHL_BASE, FALSE);		// 接收中断使能
			}
            break;
        case LPUART_LIN_TX_DETECT:
            if(enable)
           	{
         //   	USART_TFE_INT_Enable (LPUART_CHL_BASE, TRUE);
			}
			else
			{
				//USART_TFE_INT_Enable (LPUART_CHL_BASE, FALSE);
			}
            break;
		case LPUART_LIN_RX_DETECT:
            if(enable)
           	{
           // 	USART_RDR_INT_Enable(LPUART_CHL_BASE, TRUE);		// 接收中断使能
			}
			else
			{
			//	USART_RDR_INT_Enable(LPUART_CHL_BASE, FALSE);		// 接收中断使能
			}
            break;
        case LPUART_LIN_ERR_DETECT:
            //retVal = (((base->DATA >> (uint16_t)(statusFlag)) & 1U) > 0U);
            break;
        default:
            /* Invalid parameter: return */
            break;
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : LPUART_GetIntMode
 * Description   : Returns whether LPUART module interrupt is enabled/disabled.
 *END**************************************************************************/
bool LPUART_GetIntMode( E_LPUART_IRQ_STATUS_TYPE intSrc)
{

    bool retVal = false;

    switch ( intSrc )
    {
        case LPUART_LIN_BREAK_DETECT:
            //retVal = INTC_GetPendingIRQ(TM03_IRQn);
            break;
        case LPUART_LIN_TX_DETECT:
            //retVal = INTC_GetPendingIRQ(ST0_IRQn);
            break;
		case LPUART_LIN_RX_DETECT:
            //retVal = INTC_GetPendingIRQ(SR0_IRQn);
            break;
        case LPUART_LIN_ERR_DETECT:
            //retVal = (((base->DATA >> (uint16_t)(statusFlag)) & 1U) > 0U);
            break;
        default:
            /* Invalid parameter: return */
            break;
    }

    return retVal;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : LPUART_GetStatusFlag
 * Description   : LPUART get status flag by passing flag enum.
 *END**************************************************************************/
bool LPUART_GetStatusFlag(E_LPUART_IRQ_STATUS_TYPE statusFlag)
{
    bool retVal = false;

		

    switch ( statusFlag )
    {
        case LPUART_LIN_BREAK_DETECT:
           // retVal = USART_Get_Blank_Flag(LPUART_CHL_BASE);
            break;
        case LPUART_LIN_TX_DETECT:
       // 	if((LPUART_CHL_BASE->IER & USART_IER_TFEIE) &&	// 发送缓冲区空中断打开
      //  		   (LPUART_CHL_BASE->STR & USART_STR_TFEIF))
        	{
        		retVal = TRUE;
        	}
       // 	else
        	{
        		retVal = FALSE;
        	}
            break;
		case LPUART_LIN_RX_DETECT:
	//		if(LPUART_CHL_BASE->STR & USART_STR_RDRIF)
			{
				retVal = TRUE;
			}
			//else
			{
				retVal = FALSE;
			}
            break;
        case LPUART_LIN_ERR_DETECT:
            //retVal = (((base->DATA >> (uint16_t)(statusFlag)) & 1U) > 0U);
            break;
        default:
            /* Invalid parameter: return */
            break;
    }

    return retVal;
}
/*FUNCTION**********************************************************************
 *
 * Function Name : LPUART_SetStatusFlag
 * Description   : LPUART set status flag by passing flag enum.
 *END**************************************************************************/
bool LPUART_SetStatusFlag(E_LPUART_IRQ_STATUS_TYPE statusFlag)
{
    bool retVal = false;

		

    switch ( statusFlag )
    {
        case LPUART_LIN_BREAK_DETECT:
            //retVal = INTC_SetPendingIRQ(TM03_IRQn);
            break;
        case LPUART_LIN_TX_DETECT:
            //retVal = INTC_SetPendingIRQ(ST0_IRQn);
            break;
		case LPUART_LIN_RX_DETECT:
            //retVal = INTC_SetPendingIRQ(SR0_IRQn);
            break;
        case LPUART_LIN_ERR_DETECT:
            //retVal = (((base->DATA >> (uint16_t)(statusFlag)) & 1U) > 0U);
            break;
        default:
            /* Invalid parameter: return */
            break;
    }

    return retVal;
}



/*FUNCTION**********************************************************************
 *
 * Function Name : LPUART_ClearStatusFlag
 * Description   : LPUART clears an individual status flag
 * (see lpuart_status_flag_t for list of status bits).
 *END**************************************************************************/
status_t LPUART_ClearStatusFlag(E_LPUART_IRQ_STATUS_TYPE statusFlag)
{
    status_t returnCode = STATUS_SUCCESS;
	uint8_t Recv_Temp;
    switch(statusFlag)
    {
       

        case LPUART_LIN_BREAK_DETECT:
        //	USART_Clear_Blank_INT_Flag (LPUART_CHL_BASE);				// 清Break中断标志
        	//LPUART_Getchar((volatile uint8_t *)&Recv_Temp);
            break;

        case LPUART_LIN_TX_DETECT:
            //INTC_ClearPendingIRQ(ST0_IRQn);
          //  USART_Clear_Transmit_BUFR_INT_Flag(LPUART_CHL_BASE);
            break;

        case LPUART_LIN_RX_DETECT:
			//USART_Clear_Receive_BUFR_INT_Flag(LPUART_CHL_BASE);
            break;

        case LPUART_LIN_ERR_DETECT:
         //   USART_Clear_Receive_Overflow_INT_Flag(LPUART_CHL_BASE);
		//	USART_Clear_Frame_ERROR_INT_Flag(LPUART_CHL_BASE);
            break;

       
        default:
            returnCode = STATUS_ERROR;
            break;
    }

    return (returnCode);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : LPUART_SetErrorInterrupts
 * Description   : Enable or disable the LPUART error interrupts.
 *END**************************************************************************/
void LPUART_SetErrorInterrupts(bool enable)
{
    /* Configure the error interrupts */
    //LPUART_SetIntMode(base, LPUART_INT_RX_OVERRUN, enable);
    //LPUART_SetIntMode(base, LPUART_INT_PARITY_ERR_FLAG, enable);
    //LPUART_SetIntMode(base, LPUART_INT_NOISE_ERR_FLAG, enable);
    //LPUART_SetIntMode(base, LPUART_INT_FRAME_ERR_FLAG, enable);
}

/* *****************************************************************************
 * EOF
 ******************************************************************************/
