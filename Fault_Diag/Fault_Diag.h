/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      H source file                                                            */
/*   Name         :      Fault_Diag.h                                                             */
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
#ifndef INCLUDE_FAULT_DIAG_H_
#define INCLUDE_FAULT_DIAG_H_

#define FAULT_RECOVER_MAX_TIMER  15

#define FAULT_RECOVER_OFF_WAIT_TIME  T10_1000MS
#define FAULT_RECOVER_ON_WAIT_TIME  T10_600MS

#define VALVE_IS_OVER_CURRENT 3000U
#define VALVE_IS_UNDER_CURRENT 50U
#define _VALVE_IS_DIAG_SHORT_FILTER 25U
#define _VALVE_IS_DIAG_OPEN_FILTER 90U

#define VALVE_DIAG_SHORT_VOL_FILTER 5U


#define VALVE_DIAG_SHORT_VOL 500U



typedef enum
{
	POWER_IC_RECOVER_INIT= 0,
	POWER_IC_RECOVER_OFF_TRY,
	POWER_IC_RECOVER_ON_TRY,
	POWER_IC_RECOVER_MAXTIME_HOLD,

}POWER_IC_DIAGNOSTIC_RECOVER_STATUS;

typedef enum
{
	BOARD_TEMP_STATE_NORMAL = 0,
	BOARD_TEMP_STATE_OVER   = 1,
	BOARD_TEMP_STATE_FAULT  = 2,
	BOARD_TEMP_STATE_GET_TEMP_FAIL  = 3,
}BOARD_TEMP_STATE;

typedef enum
{
	VALVE_DIAG_NORMAL = 0,
	VALVE_DIAG_SHORT   = 1,
	VALVE_DIAG_OPEN  = 2,
}VALVE_DIAG_FAULT_Type;



typedef struct
{
	uint8_t Diag_Recover_DetEn;
	uint8_t Diag_Recover_Status;
	uint32_t Diag_Fault_RecoverTimer; //MA
	uint32_t Diag_RecoverOff_Timer; //MA
	uint32_t Diag_RecoverOn_Timer; //MA
}FaultDiag_Status_Struct;

extern void FaultDiag_DataInit(void);
extern void FaultDiag_Task_10msScheduler(void);
extern void FaultDiag_Task_100msScheduler(void);
/*************************************************************************************************************************/
								
/*  ######################################################################################################################
	#################################################External call API####################################################	
**  ######################################################################################################################*/

/*************************************************************************************************************************
*Name		 : FaultDiag_Poweric_StatusGet
*Function	 : Diag Power Ic Run Status
*argument	 : uint8_t opIndex:
				0, // The pump corresponds to the power IC
				1, // Solenoid valve corresponding to the power IC
*Retval 	 : uint8_t Fault state:
				POWER_IC_OUTPUT_NORMAL, 					// It is running properly
				POWER_IC_OUTPUT_SHORT_CIRCURT_TO_VS, 		// Short circuit to the power supply
				POWER_IC_OUTPUT_SHORT_CIRCURT_TO_GND, 		// Short circuits to the ground
				POWER_IC_OUTPUT_CURRENT_LIMIT, 				// The current is excessive
				POWER_IC_OUTPUT_OPEN_CIRCURT, 				// Open circuit
				POWER_IC_OUTPUT_VOUT_OUTPUT_ERR, 			// The output is abnormal
*explain	 : Returns the current PowerIc running status based on the index
**************************************************************************************************************************/

extern uint8_t FaultDiag_Poweric_StatusGet(uint8_t opIndex);

/*************************************************************************************************************************
*Name		 : FaultDiag_BattVol_StatusGet
*Function	 : Diag Batt+ Voltage Status
*argument	 : void
*Retval 	 : uint8_t status:
				BAT_VOL_STA_NORMAL,		 // The voltage is 9-16V
				BAT_VOL_STA_OVER, 		 // Voltage >=16V The voltage is too high
				BAT_VOL_STA_UNDER 		 // Voltage <=9V The voltage is too low
*explain	 : Returns the current Batt+ Voltage status 
**************************************************************************************************************************/

extern uint8_t FaultDiag_BattVol_StatusGet(void);

/*************************************************************************************************************************
*Name		 : FaultDiag_BoardTemp_StatusGet
*Function	 : Diag Board Temperature Run Status
*argument	 : void
*Retval 	 : uint8_t status:
				BOARD_TEMP_STATE_NORMAL, 			// The temperature is normal (-59 ¡æ  -- 100 ¡æ)
				BOARD_TEMP_STATE_OVER, 				//100 ¡ã C =< Temperature <170 ¡ã C
				BOARD_TEMP_STATE_FAULT, 			// If the temperature is > 170 ¡ã C or <= -60 ¡ã C, a fault occurs
				BOARD_TEMP_STATE_GET_TEMP_FAIL,		// The NTC temperature on the board is abnormal
*explain	 : Returns the current Board Temperature status
**************************************************************************************************************************/

extern uint8_t FaultDiag_BoardTemp_StatusGet(void);

extern uint8_t FaultDiag_PumpFault_StatusGet(void);
extern VALVE_DIAG_FAULT_Type FaultDiag_ValveFault_StatusGet(void);


/*************************************************************************************************************************/
/*************************************************************************************************************************
*Name		 : FaultDiag_Poweric_Recover_DetEnSet
*Function	 :  Power ic Diag Recover Det Enable/Disable
*argument	 : uint8_t opIndex:
				0, // The pump corresponds to the power IC
				1, // Solenoid valve corresponding to the power IC
			   uint8_t opEnStatus:
				0, // Automatic recovery detection is disabled
				1, // Automatic recovery detection is enabled
*Retval 	 : void
*explain	 : If use this Function PUMP_DIAG_RECOVER_FUNC_EN must set 1
			   If fault recovery detection is enabled and you prefer not to use the 
			   automatic short-circuit recovery detection controlled by the platform's 
			   lower layer during a short circuit, but instead want the APP to control 
			   the execution and termination of the recovery, you can use this function to set it up.
**************************************************************************************************************************/

extern void FaultDiag_Poweric_Recover_DetEnSet(uint8_t opIndex,uint8_t opEnStatus);


#endif /* INCLUDE_PUMP_CTRL_H_ */
