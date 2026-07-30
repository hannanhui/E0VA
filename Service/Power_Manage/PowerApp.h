/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      H source file                                                            */
/*   Name         :      PowerApp.h                                                               */
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
#ifndef POWER_APP_H_
#define POWER_APP_H_



#ifdef POWER_APP_ROOT
#define EXTERN_POWER_APP
#else
#define EXTERN_POWER_APP extern
#endif

typedef enum
{
	POWER_MODE_OFF    = 0,
	POWER_MODE_ACC    = 1,
	POWER_MODE_ON     = 2,
	POWER_MODE_CRANK  = 3

}POWER_MODE;

typedef enum
{
	RUNNING_TOUT_EVENT = 0,		// Uptime Timeout hibernation event. The hibernation event cannot be hibernated before the timeout
	LIN_BUS_EVENT,				// LIN Bus event


}SYSTEM_SLEEP_EVENT;

typedef enum
{
	BAT_VOL_STA_INIT = 0,
	BAT_VOL_STA_NORMAL = 1,
	BAT_VOL_STA_OVER   = 2,
	BAT_VOL_STA_UNDER  = 3
	
}BAT_VOL_STATE;
typedef enum
{
    VOLTAGE_STATE_INIT=0,
    VOLTAGE_STATE_UNDER_LOW,	//bg off  can off //UV2
    VOLTAGE_STATE_LOW,			//bg off  can on //UV1
    VOLTAGE_STATE_NORMAL,
    VOLTAGE_STATE_HIGH,			//bg off  can on //OV1
    VOLTAGE_STATE_OVER_HIGH		//bg off  can off //OV2
} VOLTAGE_STATE;





typedef enum
{
    POWER_ON_RESET=0,
    POWER_ON_START,
    POWER_ON_INIT_MODULE,
    POWER_SYS_RUNNING,  
    POWER_OFF_WAIT,
    SYSTEM_SLEEP         
}POWER_STATUS;



typedef struct
{
    POWER_STATUS MainPowerState; 
    uint16_t WaitTimer;

    
    
}POWER_MANAGER_STRUCT;

EXTERN_POWER_APP uint8_t PowerApp_LinGetBattery_Voltage_State(void);

EXTERN_POWER_APP void PowerApp_10mS_PeriodicDetectProc(void);

EXTERN_POWER_APP void PowerApp_100mS_PeriodicDetectProc(void);

EXTERN_POWER_APP void PowerApp_Init(void);

EXTERN_POWER_APP BAT_VOL_STATE Get_Battery_Voltage_State(void);

EXTERN_POWER_APP POWER_MODE Get_Power_Mode(void);

EXTERN_POWER_APP void Power_Mode_Set_By_LIN_Bus(POWER_MODE Mode);
EXTERN_POWER_APP void PowerApp_Voltage_100mS_Periodic_Detect(void);


EXTERN_POWER_APP uint8_t PowerApp_MainPowerStateGet(void);

EXTERN_POWER_APP void PowerApp_ModelPowerOffCustomer(void);

EXTERN_POWER_APP void PowerApp_Batt_Detect_Enable(uint8_t En);
EXTERN_POWER_APP void PowerApp_BattVolDataInit(void);

/*************************************************************************************************************************/
								
/*  ######################################################################################################################
	#################################################External call API####################################################	
**  ######################################################################################################################*/

/*************************************************************************************************************************
*Name		 : System_Running_Init
*Function	 : Reset the system running event
*argument	 : void
*Retval 	 : void
*explain	 : Reset the system running eventBy default, the system keeps running for 5 seconds. 
				If you need to keep the system running after receiving a key signal or other events,
				you need to invoke this function to refresh the system keep running time
**************************************************************************************************************************/

EXTERN_POWER_APP void System_Running_Init(void);

/*************************************************************************************************************************
*Name		 : System_Sleep_Event_Clear
*Function	 : Clear input sleep events
*argument	 : SYSTEM_SLEEP_EVENT Event:
				RUNNING_TOUT_EVENT, 		// System running event
				LIN_BUS_EVENT, 					// LIN Bus event
				VALVE_PUMP_CTRL_EVENT 			// Solenoid valve and pump control event
*Retval 	 : void
*explain	 : If the input sleep event is cleared, the current event activation cannot be hibernated
				The system executes sleep after all sleep events are suspended
				Any event that activates the system doesn't go to sleep
**************************************************************************************************************************/

EXTERN_POWER_APP void System_Sleep_Event_Clear(SYSTEM_SLEEP_EVENT Event);
/*************************************************************************************************************************
*Name		 : System_Sleep_Event_Set
*Function	 : Set input sleep events
*argument	 : SYSTEM_SLEEP_EVENT Event:
				RUNNING_TOUT_EVENT, 		// System running event
				LIN_BUS_EVENT, 					// LIN Bus event
				VALVE_PUMP_CTRL_EVENT 			// Solenoid valve and pump control event
*Retval 	 : void
*explain	 : Set the input sleep event to indicate that the current event can be hibernated
				The system executes sleep after all sleep events are suspended
				Any event that activates the system doesn't go to sleep
**************************************************************************************************************************/


EXTERN_POWER_APP void System_Sleep_Event_Set(SYSTEM_SLEEP_EVENT Event);

/*************************************************************************************************************************/


#endif /* POWER_APP_H_ */
