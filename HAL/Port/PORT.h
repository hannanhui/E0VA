/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      H source file                                                            */
/*   Name         :      PORT.h                                                                   */
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


#ifndef __INCLUDE_PORT_H__
#define __INCLUDE_PORT_H__
#include "model_Cfg_feature.h"
#if CFG_MODEL == CFG_MVP13


#include ".\Port_Cfg\Port_Cfg_Mux_MVP.h"
#include ".\Port_If\PortIf.h"

#else
#pragma message("!!! Port error !!!")
#endif


#if CFG_MODEL == CFG_MVP13




// LIN transceiver Work enable


#define LIN_TRANSCEIVER_WORK_EN_PORT 									PORT_D
#define LIN_TRANSCEIVER_WORK_EN_PIN 									GPIO_2
#define LIN_TRANSCEIVER_WORK_EN_MUX 									PTD2_GPIO

#define SET_LIN_TRANSCEIVER_WORK_EN      	   	 				(PINS_DRV_SetPins(LIN_TRANSCEIVER_WORK_EN_PORT, LIN_TRANSCEIVER_WORK_EN_PIN)) 
#define CLR_LIN_TRANSCEIVER_WORK_EN            				(PINS_DRV_ClearPins(LIN_TRANSCEIVER_WORK_EN_PORT, LIN_TRANSCEIVER_WORK_EN_PIN)) 

#define LIN_TRANSCEIVER_WORK_STATUS_PORT 							//GPIOF_SFR
#define LIN_TRANSCEIVER_WORK_STATUS_PIN 							//GPIO_PIN_MASK_8

#define GET_LIN_TRANSCEIVER_WORK_STATUS             	//((PINS_DRV_ReadPins(LIN_TRANSCEIVER_WORK_STATUS_PORT,LIN_TRANSCEIVER_WORK_STATUS_PIN,GPIO_MODE_OUT)) & 0x01)


#define LIN_TRANSCEIVER_INH_STATUS_PORT 							//GPIOD_SFR
#define LIN_TRANSCEIVER_INH_STATUS_PIN 							//GPIO_PIN_MASK_4

#define GET_LIN_TRANSCEIVER_INH_STATUS             //	((PINS_DRV_ReadPins(LIN_TRANSCEIVER_INH_STATUS_PORT,LIN_TRANSCEIVER_INH_STATUS_PIN,GPIO_MODE_IN)) & 0x01)

/* CAN IO definition */
#define  BL_CAN_SYS_PORT      SYSCTRL_PORTB
#define  BL_CAN_PORT          PORT_B
#define  BL_CAN_TX_IO         GPIO_1
#define  BL_CAN_TX_PINMUX     PTB1_CAN0_TX
#define  BL_CAN_RX_IO         GPIO_0
#define  BL_CAN_RX_PINMUX     PTB0_CAN0_RX
#define  BL_CAN_STB_IO        GPIO_2
#define  BL_CAN_STB_PINMUX    PTB2_GPIO   

/* LIN IO definition */
#define  BL_LIN_SYS_PORT      SYSCTRL_PORTA
#define  BL_LIN_PORT          PORT_A
#define  BL_LIN_TX_IO         GPIO_3
#define  BL_LIN_TX_PINMUX     PTA3_UART0_TX
#define  BL_LIN_RX_IO         GPIO_2
#define  BL_LIN_RX_PINMUX     PTA2_UART0_RX


#define  BL_LIN_SYS_SLB_PORT   SYSCTRL_PORTD
#define  BL_LIN_SLB_PORT      PORT_D
#define  BL_LIN_SLB_IO        GPIO_2
#define  BL_LIN_SLB_PINMUX    PTD2_GPIO


#else
#pragma message("!!! Port error !!!")
#endif



#endif /* __INCLUDE_PORT_H__*/
