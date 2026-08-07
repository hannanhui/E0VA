/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      C source file                                                            */
/*   Name         :      PortIf.c                                                                 */
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


#include "Ecal_PORT.h"





void MCU_GPIO_SetWorkMode(E_PORT_IF_IOWORK_MODE gpio_workmode)
{


    if (E_PORT_IF_IOWORK_MODE_RUNING==gpio_workmode)
    {
       Port_Init(NULL_PTR);

    }
    else if (E_PORT_IF_IOWORK_MODE_SLEEP==gpio_workmode)
    {
        

    }
    

}










