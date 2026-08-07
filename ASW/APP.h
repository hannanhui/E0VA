/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      H source file                                                            */
/*   Name         :      APP.h                                                                    */
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
#ifndef __INCLUDE_APP_H__
#define __INCLUDE_APP_H__
#include "model_feature.h"

#include "App_MainScheduler\App_MainScheduler.h"
#include "Vehicle_Action\Vehicle_Action.h"

#include "Function\Function_Valve_Curve_Config.h"

#include "Function\Function_Pressure_Comm.h"
#include "Function\Func_Fault_Diag.h"


//#define FUNC_USE_MBD 0U
//#define FUNC_USE_CODE 1U
//
//#define FUNC_USE_DESIGN FUNC_USE_MBD


//#if (FUNCTION_USE_METHOD == FUNCTION_USE_MFC)
//#include "MassageCode\Massage_MFC_Map.h"
//#include "MassageCode\Massage_MFC_Ctrl.h"
#include "MassageCode\MFC_Ctrl.h"


#include "Function\Function_MFC_Adapter.h"


//#else
#include "MBD_Code\BackMassage_Model.h"
#include "MBD_Code\Model_Adapter.h"
#include "Function\Function_MBD_Adapter.h"
//#endif

#include "APP_KEY\Function_Key.h"






#endif /*__INCLUDE_APP_H__*/
