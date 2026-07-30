/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      C source file                                                            */
/*   Name         :      PortIf.c                                                                 */
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
#include "..\PORT.h"



uint8_t PINS_DRV_ReadPins(PORT_Id_t GPIOx, PORT_GpioNum_t GpioPin)
{	
		return GPIO_ReadPinLevel(GPIOx, GpioPin);
}
void PINS_DRV_SetPins(PORT_Id_t GPIOx, PORT_GpioNum_t GpioPin)
{
    GPIO_SetPinOutput(GPIOx, GpioPin);
	
}
void PINS_DRV_ClearPins(PORT_Id_t GPIOx, PORT_GpioNum_t GpioPin)
{
    GPIO_ClearPinOutput(GPIOx, GpioPin);
}
void PINS_DRV_SetPins_AN(PORT_Id_t GPIOx, PORT_GpioNum_t GpioPin)
{
	//GPIO_Write_Mode_Bits(GPIOx , GpioPin, GPIO_MODE_AN );

}
void PINS_DRV_TogglePins(PORT_Id_t GPIOx, PORT_GpioNum_t GpioPin)
{
    GPIO_TogglePinOutput(GPIOx, GpioPin);
}





void MCU_GPIO_SetWorkMode(E_PORT_IF_IOWORK_MODE gpio_workmode)
{


    if (E_PORT_IF_IOWORK_MODE_RUNING==gpio_workmode)
    {
       
				PORT_PinmuxConfig(BL_LIN_PORT, BL_LIN_RX_IO, BL_LIN_RX_PINMUX);
				PORT_PinmuxConfig(BL_LIN_PORT, BL_LIN_TX_IO, BL_LIN_TX_PINMUX);
			 

    }
    else if (E_PORT_IF_IOWORK_MODE_SLEEP==gpio_workmode)
    {
        

    }
    

}


void PORTIF_LIN_HE_DRV_SLP_EN_INIT(void)
{
	 /* Enable PORTB clock */
    SYSCTRL_EnableModule(SYSCTRL_PORTD);
    /*Config GPIO module*/
    SYSCTRL_EnableModule(SYSCTRL_GPIO);
	/* transciever slpeep pin */
    PORT_PinmuxConfig(BL_LIN_SLB_PORT, BL_LIN_SLB_IO, BL_LIN_SLB_PINMUX);
    GPIO_SetPinDir(BL_LIN_SLB_PORT, BL_LIN_SLB_IO, GPIO_OUTPUT);
    /*  pull up  */
    GPIO_SetPinOutput(BL_LIN_SLB_PORT, BL_LIN_SLB_IO);
	
	
}







