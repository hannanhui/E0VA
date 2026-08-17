/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      H source file                                                            */
/*   Name         :      Vehicle_Action.h                                                         */
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


#ifndef __VEHICLE_ACTION_H__
#define __VEHICLE_ACTION_H__

extern uint8_t Boot_Major_Version[VERSION_INFO_MAX_SIZE];	// Boot
extern uint8_t App_Major_Version[VERSION_INFO_MAX_SIZE];	// App

extern uint8_t Boot_Minor_Version[VERSION_INFO_MAX_SIZE];	// Boot
extern uint8_t App_Minor_Version[VERSION_INFO_MAX_SIZE];	// App
typedef enum
{
	ASM_POS_FL_NAD = 0x8C, // Front row left
	ASM_POS_FR_NAD = 0x8D, // On the right of the front row
	ASM_POS_RL_NAD = 0x8E, // Left row
	ASM_POS_RR_NAD = 0x8F, // In the right row

}ASM_POS_NAD;
typedef enum
{
    ASM_POS_UKNOW = 0, 	// unknown
    ASM_POS_FL, 		// Front row left
    ASM_POS_FR, 		// Front row right
    ASM_POS_RL, 		// Left row
    ASM_POS_RR, 		// In the right row

}ASM_POS;
#include "ProprietaryLin\ProprietaryLin_Tp\ProprietaryLin_Tp.h"

#include "ProprietaryLin\ProprietaryLin_App\ProprietaryLin_App.h"



#include "Uds\Uds_Tp\Uds_Tp.h"

#include "Uds\Uds_App\Uds_alg_hal.h"
#include "Uds\Uds_App\Uds_App.h"


extern void Vehicle_Action_Init(void);
extern void Vehicle_Action_1mS(void);
extern void Vehicle_Action_10mS(void);



#endif /* __VEHICLE_ACTION_H__ */




