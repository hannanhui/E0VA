/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      H source file                                                            */
/*   Name         :      PortIf.h                                                                 */
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


#ifndef PORT_IF_H_
#define PORT_IF_H_

#include "MCAL.h"
#include "model_Cfg_feature.h"
typedef enum
{
    E_PORT_IF_IOWORK_MODE_RUNING=0,
    E_PORT_IF_IOWORK_MODE_SLEEP,
    E_PORT_IF_IOWORK_MODE_MAX
}E_PORT_IF_IOWORK_MODE;


extern void MCU_GPIO_SetWorkMode(E_PORT_IF_IOWORK_MODE gpio_workmode);


extern uint8_t PINS_DRV_ReadPins(PORT_Id_t GPIOx, PORT_GpioNum_t GpioPin);
extern void PINS_DRV_SetPins(PORT_Id_t GPIOx, PORT_GpioNum_t GpioPin);
extern void PINS_DRV_ClearPins(PORT_Id_t GPIOx, PORT_GpioNum_t GpioPin);
extern void PINS_DRV_TogglePins(PORT_Id_t GPIOx, PORT_GpioNum_t GpioPin);
extern void PORTIF_LIN_HE_DRV_SLP_EN_INIT(void);

extern void MCU_GPIO_Wakeup_Pin_AN_Set(void);
extern void PINS_DRV_SetPins_AN(PORT_Id_t GPIOx, PORT_GpioNum_t GpioPin);

#endif /* PORT_IF_H_ */
