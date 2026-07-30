/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      H source file                                                            */
/*   Name         :      lpuart_hw_access.h                                                       */
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
 * Copyright (c) 2013 - 2014, Freescale Semiconductor, Inc.
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
 * @file lpuart_hw_access.h
 *
 * @page misra_violations MISRA-C:2012 violations
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 2.3, Global typedef not referenced.
 * This increases ease of use: allows users to access the corresponding field in the register
 * using an already defined type.
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 2.5, Global macro not referenced.
 * The macros were defined for consistency reasons, all the registers have a corresponding ID.
 *
 * @section [global]
 * Violates MISRA 2012 Required Rule 10.3, Expression assigned to a narrower or different essential type.
 * The cast is required to perform a conversion between an unsigned integer and an enum type.
 */

#ifndef LPUART_HW_ACCESS_H__
#define LPUART_HW_ACCESS_H__

#include "MCAL.h"


#define LIN_ID             UART0_ID
#define CLK_LIN_ID         CLK_UART0
#define SYSCTRL_LIN_ID     SYSCTRL_UART0
#define LIN_IRQ_NUM        UART0_IRQn 


#define LPUART_CHL_BASE  //USART0_SFR

#define LPUART_CHL_INT_BASE  //INT_USART0

/* *****************************************************************************
 * Definitions
 ******************************************************************************/
#define LPUART_SHIFT (16U)
#define LPUART_BAUD_REG_ID (1U)
#define LPUART_STAT_REG_ID (2U)
#define LPUART_CTRL_REG_ID (3U)
#define LPUART_DATA_REG_ID (4U)
#define LPUART_MATCH_REG_ID (5U)
#define LPUART_MODIR_REG_ID (6U)
#define LPUART_FIFO_REG_ID (7U)

/*! @brief LPUART wakeup from standby method constants
 */
typedef enum
{
    LPUART_IDLE_LINE_WAKE = 0x0U, /*!< Idle-line wakes the LPUART receiver from standby. */
    LPUART_ADDR_MARK_WAKE = 0x1U  /*!< Addr-mark wakes LPUART receiver from standby.*/
} lpuart_wakeup_method_t;

/*!
 * @brief LPUART break character length settings for transmit/detect.
 *
 * The actual maximum bit times may vary depending on the LPUART instance.
 */
typedef enum
{
    LPUART_BREAK_CHAR_10_BIT_MINIMUM = 0x0U, 
                                                  
	LPUART_BREAK_CHAR_11_BIT_MINIMUM = 0x1U,  
	 											
    LPUART_BREAK_CHAR_13_BIT_MINIMUM = 0x2U  
                                                  
} lpuart_break_char_length_t;
typedef enum
{
    LPUART_LIN_BREAK_DETECT = 0x0U, 
                                                  
	LPUART_LIN_TX_DETECT = 0x1U,  
	 											
    LPUART_LIN_RX_DETECT = 0x2U,  
    
    LPUART_LIN_ERR_DETECT = 0x3U  
                                                  
} E_LPUART_IRQ_STATUS_TYPE;


typedef enum
{
	LIN_BUS_ERROR_TYPE_NO = 0,
	LIN_BUS_ERROR_TYPE_RESET,
	LIN_BUS_ERROR_TYPE_OVERRUN,
	LIN_BUS_ERROR_TYPE_RESERVED2,
	LIN_BUS_ERROR_TYPE_TX_BIT_ERR,
	LIN_BUS_ERROR_TYPE_CHECKSUM_ERR,
	LIN_BUS_ERROR_TYPE_BYTE_FRAMING_ERR,
	LIN_BUS_ERROR_TYPE_ID_PARITY_ERR,

}LIN_BUS_ERROR_TYPE;




/* *****************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @name LPUART Common Configurations
 * @{
 */

/*!
 * @brief Initializes the LPUART controller.
 *
 * This function Initializes the LPUART controller to known state.
 *
 *
 * @param base LPUART base pointer.
 */


//void LPUART_DeInit(void);
bool LPUART_SetStatusFlag(E_LPUART_IRQ_STATUS_TYPE statusFlag);

void LPUART_DRV_BREAK_Init(void);

void LPUART_Break_Timer_Detc_Start(void);
void LPUART_Break_Timer_Detc_Stop(void);

uint8_t LPUART_Break_Timer_Ovf_Det(void);

uint32_t LPUART_Break_Timer_Counter_Val(void);
uint8_t LPUART_Error_Status_Det(void);

/*@}*/

/*!
 * @name LPUART Interrupts and DMA
 * @{
 */

/*!
 * @brief Configures the LPUART module interrupts.
 *
 * This function configures the LPUART module interrupts to enable/disable various interrupt sources.
 *
 *
 * @param   base LPUART module base pointer.
 * @param   intSrc LPUART interrupt configuration data.
 * @param   enable   true: enable, false: disable.
 */
void LPUART_SetIntMode(E_LPUART_IRQ_STATUS_TYPE reg, bool enable);

/*!
 * @brief Returns LPUART module interrupts state.
 *
 * This function returns whether a certain LPUART module interrupt is enabled or disabled.
 *
 *
 * @param   base LPUART module base pointer.
 * @param   intSrc LPUART interrupt configuration data.
 * @return  true: enable, false: disable.
 */
bool LPUART_GetIntMode( E_LPUART_IRQ_STATUS_TYPE intSrc);


/*@}*/

/*!
 * @name LPUART Transfer Functions
 * @{
 */

/*!
 * @brief Sends the LPUART 8-bit character.
 *
 * This functions sends an 8-bit character.
 *
 *
 * @param base LPUART Instance
 * @param data     data to send (8-bit)
 */
static inline void LPUART_Putchar( uint8_t data)
{
    //volatile uint8_t * dataRegBytes = (volatile uint8_t *)(&(base->DATA));
	
	UART_SendByte(LIN_ID, data);
	//UART_SendByte(LPUART_CHL_BASE, data);
}


/*!
 * @brief Gets the LPUART 8-bit character.
 *
 * This functions receives an 8-bit character.
 *
 *
 * @param base LPUART base pointer
 * @param readData Data read from receive (8-bit)
 */
static inline void LPUART_Getchar(volatile uint8_t *readData)
{
    if(readData != NULL)
   	{
   	
		 *readData = UART_ReceiveByte(LIN_ID);;
		 //*readData = UART_ReceiveByte(LPUART_CHL_BASE);
	}

   
}



/*@}*/

/*!
 * @name LPUART Status Flags
 * @{
 */

/*!
 * @brief  LPUART get status flag
 *
 * This function returns the state of a status flag.
 *
 *
 * @param base LPUART base pointer
 * @param statusFlag  The status flag to query
 * @return Whether the current status flag is set(true) or not(false).
 */
bool LPUART_GetStatusFlag(E_LPUART_IRQ_STATUS_TYPE statusFlag);

/*!
 * @brief LPUART clears an individual status flag.
 *
 * This function clears an individual status flag (see lpuart_status_flag_t for list of status bits).
 *
 *
 * @param base LPUART base pointer
 * @param statusFlag  Desired LPUART status flag to clear
 * @return STATUS_SUCCESS if successful or STATUS_ERROR if an error occured
 */
status_t LPUART_ClearStatusFlag(E_LPUART_IRQ_STATUS_TYPE statusFlag);

/*@}*/

/*!
 * @name LPUART Special Feature Configurations
 * @{
 */

/*!
 * @brief Enable or disable the LPUART error interrupts.
 *
 * This function configures the error interrupts (parity, noise, overrun, framing).
 *
 *
 * @param base LPUART base pointer
 * @param enable true - enable, false - disable error interrupts
 */
void LPUART_SetErrorInterrupts( bool enable);


/*@}*/

#if defined(__cplusplus)
}
#endif

#endif /* LPUART_HW_ACCESS_H__ */
/* *****************************************************************************
 * EOF
 ******************************************************************************/
