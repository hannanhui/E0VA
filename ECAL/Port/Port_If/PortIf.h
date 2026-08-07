/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      H source file                                                            */
/*   Name         :      PortIf.h                                                                 */
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


#ifndef PORT_IF_H_
#define PORT_IF_H_

#include "model_Cfg_feature.h"
typedef enum
{
    E_PORT_IF_IOWORK_MODE_RUNING=0,
    E_PORT_IF_IOWORK_MODE_SLEEP,
    E_PORT_IF_IOWORK_MODE_MAX
}E_PORT_IF_IOWORK_MODE;


extern void MCU_GPIO_SetWorkMode(E_PORT_IF_IOWORK_MODE gpio_workmode);




#endif /* PORT_IF_H_ */
