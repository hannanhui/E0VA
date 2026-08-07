/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      H source file                                                            */
/*   Name         :      MX11_Action.h                                                            */
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

#ifndef __DC1E_ACTION_H__
#define __DC1E_ACTION_H__

#include "include.h"
#if MODEL == PRO_MGP13

extern uint8_t Boot_Major_Version[VERSION_INFO_MAX_SIZE];	// Boot
extern uint8_t App_Major_Version[VERSION_INFO_MAX_SIZE];	// App

extern uint8_t Boot_Minor_Version[VERSION_INFO_MAX_SIZE];	// Boot
extern uint8_t App_Minor_Version[VERSION_INFO_MAX_SIZE];	// App

typedef enum
{
    ASM_POS_UKNOW = 0, 	// unknown
    ASM_POS_FL, 		// Front row left
    ASM_POS_FR, 		// Front row right
    ASM_POS_RL, 		// Left row
    ASM_POS_RR, 		// In the right row

}ASM_POS;

typedef enum
{
	Hut_Key_NO_Action = 0,  // invalid
	Hut_Key_Up, 			// up
	Hut_Key_Down, 			// down
	Hut_Key_Left, 			// left
	Hut_Key_Right, 			// right
	Hut_Key_M, 				// Function switch
	Hut_Key_Reserved0, 		// Reserve
	Hut_Key_Reserved1, 		// Reserve
}HUT_KEY; 					// Large-screen key status

    

typedef enum
{
	ASM_POS_FL_NAD = 0x8C, // Front row left
	ASM_POS_FR_NAD = 0x8D, // On the right of the front row
	ASM_POS_RL_NAD = 0x8E, // Left row
	ASM_POS_RR_NAD = 0x8F, // In the right row

}ASM_POS_NAD;

// KEY is a non-fixed enumeration type. The value can be changed based on the actual situation and represents all keys that need to be used
typedef enum
{
	KEY_VAL_NONE = 0, 			// No keys are pressed
	KEY_VAL_LUMBAR_UP, 			// lumbar up
	KEY_VAL_LUMBAR_DOWN, 		// lumbar down
	KEY_VAL_LUMBAR_FWD, 		// Forward lumbar
	KEY_VAL_LUMBAR_RWD, 		// lumbar backwards
	KEY_VAL_MASS_MODE,		 	// Massage mode
	KEY_VAL_MASS_INTEN,	 		// Massage strength
	KEY_VAL_MASS_SWITCH, 		// Massage switch
	KEY_VAL_MAX

}KEY_VALUE;


typedef enum
{
    Pump_Sts_Resp_Nornal = 0,
	Pump_Sts_Resp_Fault ,	    //Fault

}PUMP_STATUS_RESP;				// Pump status

typedef enum
{
	Mass_Sts_Off = 0,		//Massage off
	Mass_Sts_On,		    //Massage on

}MASS_STATUS;			// Massage Status
typedef enum
{
	Voltage_Sts_Normal = 0  ,	
	Voltage_Sts_UnderVoltage,	
    Voltage_Sts_OverVoltage ,
}VOLTAGE_STATUS;			
typedef enum
{
    Valve_Sts_Normal = 0,
    Valve_Sts_Error,
}VALVE_STATUS;

extern uint8 PartNum0[7];
extern uint8 PartNum1[8];
extern uint8 SwNum[8];
extern uint8 HwNum[8];

extern void DC1E_Action_Periodic_10mS(void);
extern void DC1E_Action_Init(void);

extern void DC1E_Action_Get_Key_Value (KEY_VALUE* Key_Value);

extern void DC1E_Lintl_UseFuncListCallbackInstall(void);

extern uint8_t MVP17_BusGetLinTimeOutFlag(void);

/* LinIf → LinApp 桥接函数，在 LinIf_PBCfg.c 中注册 */
extern void LinApp_Rx_Bridge(PduIdType RxPduId, const PduInfoType* PduInfoPtr);
extern Std_ReturnType LinApp_TxTrigger_Bridge(PduIdType TxPduId, PduInfoType* PduInfoPtr);
extern void LinApp_TxConfirm_Bridge(PduIdType TxPduId);


extern ASM_POS DC1E_Action_Mounting_PositionGet(void);


#endif

#endif /* __SG_ACTION_H__ */






