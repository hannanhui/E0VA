/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      H source file                                                            */
/*   Name         :      model_MGP13.h                                                            */
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
#ifndef MODEL_PRO_MGP_H_
#define MODEL_PRO_MGP_H_

#include "Type_Define.h"
#include "model_Cfg_feature.h"
#if MODEL == PRO_MGP13
/* ------------------------------------------------------------------------------------------------
-------------------------------1.Version information configuration area----------------------------
---------------------------------------------------------------------------------------------------*/

#define STR_CUSTOMER_MODEL      		     "MGP13"
#define STR_COMPANY_MODEL        		     "MGP13"
#define STR_DEF_VERSION       	 		     "00.00.01"
#define STR_SOFT_DATE            		     "2025-12-22"
#define HW_DEF_VERSION           		     "A00"
#define MCU_CUSTOMER_MAIN_VERSION            "V00.00.01_251222_00_Z20K144MX_Boot\0"

#define VERSION_INFO_MAX_SIZE     			 48		// Defines the maximum length of version information





/* ------------------------------------------------------------------------------------------------
-------------------------------6.System function configuration area--------------------------------
---------------------------------------------------------------------------------------------------*/

#define UPGRADE_MODE_FOR_PROPRIETARY_LIN           1  
#define UPGRADE_MODE_FOR_UDS_LIN           2

#define UPGRADE_MODE           UPGRADE_MODE_FOR_PROPRIETARY_LIN





/* ------------------------------------------------------------------------------------------------
-------------------------------8.Power high and low voltage parameter configuration area-----------
---------------------------------------------------------------------------------------------------*/








#endif
#endif

