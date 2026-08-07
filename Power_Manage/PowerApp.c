/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      C source file                                                            */
/*   Name         :      PowerApp.c                                                               */
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
#define POWER_APP_ROOT

#include "include.h"
static volatile uint32_t UnSleep_Flag;	// System sleep flag When UnSleep_Flag is 0, the system sleeps

extern void ValveCtrl_aLL_Valve_Disable(void);


POWER_MANAGER_STRUCT Power;
#ifndef POWER_ON_START_INTERVAL
#define POWER_ON_START_INTERVAL    T10_200MS
#endif
#define POWER_OFF_WAIT_TIMEOUT    T10_50MS

//The system needs to run this macro for a minimum amount of time before it enters sleep mode



// System operation counter
uint16_t Running_Tick_100mS=0;

BAT_VOL_STATE Bat_Vol_State;		//Battery voltage status Undervoltage/Normal/Overvoltage
POWER_MODE  Ign_Line_Power_Mode;	// Ignition state OFF/ON(IGN line detection)
POWER_MODE	LIN_Bus_Power_Mode;		// Ignition state OFF/ACC/ON/CRANK(LIN Bus)


uint16_t Ign_Running_Tick_10mS=0;
uint16_t Ign_Off_Tick_10mS=0;
uint16_t Ign_WakeupFlag=0;

uint8_t Vol_Ign_Filter ;
uint8_t Vol_Off_Filter ;
uint8_t PowerApp_SystemNoSleepEn=0 ;
uint8_t PowerApp_DiagSleepNoResponseEn=0 ;

/**** Definition of internal constants ****/
uint16_t  Power_Voltage_minDebounceTime =POWER_MIN_DEBOUNCE_TIME;
#define POWER_DEBOUNCE_TIME(T)    ((VOLTAGE_STATE_INIT == Pow_Voltage_State)?(Power_Voltage_minDebounceTime):((T>=Power_Voltage_minDebounceTime)?(T):(Power_Voltage_minDebounceTime)))
//#define POWER_DEBOUNCE_TIME(T)    ((VOLTAGE_STATE_INIT == Pow_Voltage_State)?(POWER_MIN_DEBOUNCE_TIME):((T>=POWER_MIN_DEBOUNCE_TIME)?(T):(POWER_MIN_DEBOUNCE_TIME)))
static POWER_VOLTAGE_STATUS UpToOverHighVolStatus;
static POWER_VOLTAGE_STATUS UpToHighVolStatus;
static POWER_VOLTAGE_STATUS UpToNormalVolStatus;
static POWER_VOLTAGE_STATUS UpToLowsVolStatus;
static POWER_VOLTAGE_STATUS DownToHighVolStatus;
static POWER_VOLTAGE_STATUS DownToNormalVolStatus;
static POWER_VOLTAGE_STATUS DownToLowVolStatus;
static POWER_VOLTAGE_STATUS DownToUnderLowVolStatus;
uint8_t Battery_Tal_Mode=0;
uint8_t Pow_Voltage_State = VOLTAGE_STATE_INIT;
uint8_t First_Vol_Over_Filter  =0;
uint8_t First_Vol_Under_Filter =0;
uint8_t First_Vol_Normal_Filter=0;
uint8_t BAT_First_PowerUp_Flg =0;


POWER_VOLTAGE_TYPE_MANAGE PowerUpTbl[] =
{
    {VOLTAGE_STATE_OVER_HIGH,  VOLTAGE_UP_TO_OVERHIGH,    UP_TO_OVERHIGH_DEBOUNCE,  &UpToOverHighVolStatus},
    {VOLTAGE_STATE_HIGH,       VOLTAGE_UP_TO_HIGH,        UP_TO_HIGH_DEBOUNCE, 		&UpToHighVolStatus},
    {VOLTAGE_STATE_NORMAL,     VOLTAGE_UP_TO_NORMAL,      UP_TO_NORMAL_DEBOUNCE, 	&UpToNormalVolStatus},
    {VOLTAGE_STATE_LOW,        VOLTAGE_UP_TO_LOW,         UP_TO_LOW_DEBOUNCE, 		&UpToLowsVolStatus},
    
 
};
POWER_VOLTAGE_TYPE_MANAGE PowerDownTbl[] =
{
    {VOLTAGE_STATE_HIGH,       VOLTAGE_DOWN_TO_HIGH,      DOWN_TO_HIGH_DEBOUNCE, 		&DownToHighVolStatus},
    {VOLTAGE_STATE_NORMAL,     VOLTAGE_DOWN_TO_NORMAL,    DOWN_TO_NORMAL_DEBOUNCE, 		&DownToNormalVolStatus},
    {VOLTAGE_STATE_LOW,        VOLTAGE_DOWN_TO_LOW,       DOWN_TO_LOW_DEBOUNCE, 		&DownToLowVolStatus},
    {VOLTAGE_STATE_UNDER_LOW,  VOLTAGE_DOWN_TO_UNDERLOW,  DOWN_TO_UNDERLOW_DEBOUNCE, 	&DownToUnderLowVolStatus},  
    
};


/*******************************************************************************
*Name        : System_Sleep_Event_Set
*Function    : Set hibernation event
*argument    : Event - Indicates the current event that can be hibernated
*Retval      : NONE
*explain     : When all events can sleep, the system enters sleep mode
*******************************************************************************/
void System_Sleep_Event_Set(SYSTEM_SLEEP_EVENT Event)
{
	UnSleep_Flag &=~ ((uint32_t)1 << Event);
}

/*******************************************************************************
*Name        : System_Sleep_Event_Clear
*Function    : Clearhibernation event
*argument    : Event - The current event that cannot be hibernated
*Retval      : NONE
*explain     : If an event cannot be hibernated, 
*			   the system exits the hibernation mode
*******************************************************************************/

void System_Sleep_Event_Clear(SYSTEM_SLEEP_EVENT Event)
{
	UnSleep_Flag |= (uint32_t)1 << Event;
}


/*******************************************************************************
*Name        : System_Running_Init
*Function    : System Running Init
*argument    : NONE
*Retval      : NONE
*explain     : NONE
*******************************************************************************/

void System_Running_Init(void)
{
	Running_Tick_100mS = 0;
	System_Sleep_Event_Clear(RUNNING_TOUT_EVENT);
}

/*******************************************************************************
*Name        : System_Running_Periodic_100mS
*Function    : Process the system running cycle
*argument    : NONE
*Retval      : NONE
*explain     : NONE
*******************************************************************************/

void System_Running_Periodic_100mS(void)
{
	if (Running_Tick_100mS <= RUNNING_TICK_100MS_COUNT)
	{
		Running_Tick_100mS++;
	}
	else
	{
		if(0u == PowerApp_SystemNoSleepEn)
		{
			System_Sleep_Event_Set(RUNNING_TOUT_EVENT);
		}
	}
}

/*******************************************************************************
*Name        : PowerAppTimeProc
*Function    : power module all counters add and subtract scheduling
*argument    : NONE
*Retval      : NONE
*explain     : NONE
*******************************************************************************/

void PowerAppTimeProc(void)
{
	if (Power.WaitTimer!=0xffff)
	{
	   Power.WaitTimer++;	   
	}
}

/*******************************************************************************
*Name        : PowerApp_ModelPowerOnCustomer
*Function    : Power modules are powered on in a unified manner
*argument    : NONE
*Retval      : NONE
*explain     : NONE
*******************************************************************************/

void PowerApp_ModelPowerOnCustomer(void)
{
	
	Power.MainPowerState = POWER_SYS_RUNNING;
	
}

/*******************************************************************************
*Name        : PowerApp_Batt_Detect_Enable
*Function    : Batt detects the enable function
*argument    : En -Enable or disable batt+ detects
*Retval      : NONE
*explain     : NONE
*******************************************************************************/

void PowerApp_Batt_Detect_Enable(uint8_t En)
{
    if(En == true)
    {
        DigitalIf_IoWt_DataSet(Digital_IoWt_Index3,TRUE);
    }
	else
    {
        DigitalIf_IoWt_DataSet(Digital_IoWt_Index3,FALSE);
    }
}

/*******************************************************************************
*Name        : PowerApp_ModelPowerOffCustomer
*Function    : Power modules are powered off in a unified manner
*argument    : NONE
*Retval      : NONE
*explain     : NONE
*******************************************************************************/

void PowerApp_ModelPowerOffCustomer(void)
{
	//INT_All_Enable(DISABLE);
	//MCU_GPIO_SetWorkMode(E_PORT_IF_IOWORK_MODE_SLEEP);

	Scheduler_ListCallbackUninstall();
	
	//ADCIf_DeInit();
	//l_ifc_ld_init_LI0();
	
	//LinTrcv_Init();
	
	ValveCtrl_aLL_Valve_Disable();
	Valve_Supply_Status_Set(FALSE);
	PumpCtrl_Drive_Output_DeInit();
	//l_ifc_init_LI0();
	//PWM_IF_DeInit();
	P_Sensor_DeInit();
	PowerApp_Batt_Detect_Enable(FALSE);
	DigitalIf_IoWt_DataSet(Digital_IoWt_Index1,FALSE);
	DigitalIf_IoWt_DataSet(Digital_IoWt_Index3,FALSE);
	DigitalIf_IoWt_DataSet(Digital_IoWt_Index0,FALSE);
	DigitalIf_IoWt_DataSet(Digital_IoWt_Index2,FALSE);
	DigitalIf_IoWt_DataSet(Digital_IoWt_Index4,FALSE);
	DigitalIf_IoWt_DataSet(Digital_IoWt_Index8,FALSE);
	
	#if ((CAR_PUB_NET_COM_MEOD == NET_COM_CAN)||(CAR_PUB_NET_COM_MEOD == NET_COM_LIN_CAN))
	CAN_WorkModeControl(CanPhyMod_GoTSp);
	CAN_WorkModeControl(CanPhyMod_Sp);

	#endif
//	INT_All_Enable(ENABLE);

}

void PowerApp_PowerUpDownCountClr( VOLTAGE_UP_DOWN_TYPE UpDownJudge)
{
    uint8_t i ;
    for(i=0;i<E_POWER_VOLTAGE_INDEX_MAX;i++)
    {
        if((NULL != PowerDownTbl[i].Status)&&(NULL != PowerUpTbl[i].Status))
        {
            if(VOLTAGE_TYPE_UP == UpDownJudge)
            {              
                
                PowerUpTbl[i].Status->BattTimer=0;                        

                
              
            }
            else
            {               
                PowerDownTbl[i].Status->BattTimer=0;                              
            }   
        }    
    }
}



void PowerApp_PowerVoltageDeal( VOLTAGE_UP_DOWN_TYPE UpDownJudge, uint32_t Voltage)
{
    uint8_t i ;
    for(i=0;i<E_POWER_VOLTAGE_INDEX_MAX;i++)
    {
        if((NULL != PowerDownTbl[i].Status)&&(NULL != PowerUpTbl[i].Status))
        {
            if(VOLTAGE_TYPE_UP == UpDownJudge)
            {              
                /*Voltage up*/              
                /*DOWN Voltage count Clr*/
                PowerDownTbl[i].Status->BattTimer=0;                 
                if(Voltage >= PowerUpTbl[i].SampleAD)
                {
                    if(PowerUpTbl[i].Status->BattTimer < 0xFF)
                    {
                        PowerUpTbl[i].Status->BattTimer++;
                    }             
                }
                else
                {
                    PowerUpTbl[i].Status->BattTimer=0;                        
                }
                
              
            }
            else
            {
                /*Voltage Down*/                   
                /*Up Voltage count Clr*/
                PowerUpTbl[i].Status->BattTimer=0;                        
                if(Voltage <= PowerDownTbl[i].SampleAD)
                {
                    if(PowerDownTbl[i].Status->BattTimer < 0xFF)
                    {
                        PowerDownTbl[i].Status->BattTimer++;                        
                    }
                }
                else
                {
                	
                    PowerDownTbl[i].Status->BattTimer=0;                            
                }
                
            }   
        }    
    }
}
uint8_t  PowerApp_PowerModeSwitchFunc( VOLTAGE_UP_DOWN_TYPE UpDownJudge)
{
    uint8_t ModeSwitchFlag= 0u;
    uint8_t i ,j;
	uint8_t ModeChangeOverFlag=0u;
    for(i=0;i<E_POWER_VOLTAGE_INDEX_MAX;i++)
    {
    	ModeChangeOverFlag = 0u;
        if((NULL != PowerDownTbl[i].Status)&&(NULL != PowerUpTbl[i].Status))
        {
            if(VOLTAGE_TYPE_UP == UpDownJudge)
            {             
                /*Voltage up*/
                if(0u == ModeSwitchFlag)
                {

                    if(PowerUpTbl[i].Status->BattTimer >= POWER_DEBOUNCE_TIME(PowerUpTbl[i].EnterDebounce))
                    {                        								
                        if(0 == i)
                        {
                            Battery_Tal_Mode = PowerUpTbl[i].VoltageMode;
                            ModeSwitchFlag = TRUE;
                        }
                        else
                        {
							
							for(j=0;j<i;j++)
							{
								if(0u != PowerUpTbl[j].Status->BattTimer)
								{
									ModeChangeOverFlag = 1u;
									break;
								}
							}
                            /*In UpLink Mode if next Mode  have Count don't change Mode*/
                            if(0u == ModeChangeOverFlag)
                            {
                                Battery_Tal_Mode = PowerUpTbl[i].VoltageMode;
                                ModeSwitchFlag = TRUE;    
                                
                            }
                        }
                    }

                    
                }

            }
            else
            {

                if(PowerDownTbl[i].Status->BattTimer >= POWER_DEBOUNCE_TIME(PowerDownTbl[i].EnterDebounce))
                {   
                    if(i<(E_POWER_VOLTAGE_INDEX_MAX-1))
                    {
                    	for(j=i+1;j<E_POWER_VOLTAGE_INDEX_MAX;j++)
						{
							if(0u != PowerDownTbl[j].Status->BattTimer)
							{
								ModeChangeOverFlag = 1u;
								break;
							}
						}
                        if(0u == ModeChangeOverFlag)
                        {
                            Battery_Tal_Mode = PowerDownTbl[i].VoltageMode;
                            ModeSwitchFlag = TRUE;
                        }
                    }
                    else
                    {
                        Battery_Tal_Mode = PowerDownTbl[i].VoltageMode;
                        ModeSwitchFlag = TRUE;
                    }
                    
                }

                
            }
       }
    }
	

    return ModeSwitchFlag;
}
uint8_t PowerApp_PowerVoltageModeJudge(void)
{
    uint8_t Power_End_Mode=0;
    uint8_t ModeChange = 0u;
    //static u8 PowerModeDebounce = 0u;

    Power_End_Mode = Battery_Tal_Mode;

    if(Power_End_Mode != Pow_Voltage_State)
    {
        Pow_Voltage_State = Power_End_Mode;
        ModeChange = TRUE;
		
    }

    return  ModeChange;
}



void PowerApp_PowerInit_Detect(uint16_t Vol)
{
	if (Vol >= VOLTAGE_UP_TO_HIGH)
	{
		First_Vol_Under_Filter = 0;
		First_Vol_Normal_Filter = 0;

		if (First_Vol_Over_Filter < POWER_MIN_DEBOUNCE_TIME)
		{
			First_Vol_Over_Filter++;
		}
		else
		{
			Battery_Tal_Mode = VOLTAGE_STATE_HIGH;
			BAT_First_PowerUp_Flg = true;
		}
	}
	else if (Vol <= VOLTAGE_DOWN_TO_LOW)
	{
		First_Vol_Over_Filter   = 0;
		First_Vol_Normal_Filter = 0;

		if (First_Vol_Under_Filter < POWER_MIN_DEBOUNCE_TIME)
		{
			First_Vol_Under_Filter++;
		}
		else
		{
			Battery_Tal_Mode = VOLTAGE_STATE_LOW;
			BAT_First_PowerUp_Flg = true;
		}
	}
	else
	{
		First_Vol_Over_Filter  = 0;
		First_Vol_Under_Filter = 0;

		if (First_Vol_Normal_Filter < POWER_MIN_DEBOUNCE_TIME)
		{
			First_Vol_Normal_Filter++;
		}
		else
		{
			Battery_Tal_Mode = VOLTAGE_STATE_NORMAL;
			BAT_First_PowerUp_Flg = true;	
		}
	}

}


void PowerApp_PowerDetectProc(void)
{
	
 	uint32_t Battery_Voltage = 0;
    uint8_t Battery_TalModeGetFlag=0; 
	uint8_t INIT_TalModeGetFlag=0;  
    uint8_t i;
    uint8_t ModeChange = 0u;	
    static uint32_t UpPowerVoltage=0u;
    static uint32_t DownPowerVoltage=0u;

	Battery_Voltage = DigitalIf_Batt_Voltage_DataGet();

	// ���Ӷ����ܼ������ܵ�ѹ���������õ���������BAT�ĵ�ѹ   
	Battery_Voltage+= BAT_VOL_DROP_ON_DIODE_mV;

	if(!BAT_First_PowerUp_Flg)
	{
		PowerApp_PowerInit_Detect(Battery_Voltage);
		if(BAT_First_PowerUp_Flg)
		{
			INIT_TalModeGetFlag = TRUE;
		}
	}
	else
	{
		if(UpPowerVoltage <= Battery_Voltage)
	    {
	    	/*BATT+Voltage up*/
			PowerApp_PowerVoltageDeal(VOLTAGE_TYPE_UP,Battery_Voltage);            
	        Battery_TalModeGetFlag = PowerApp_PowerModeSwitchFunc(VOLTAGE_TYPE_UP);
	    }
		else
		{
			PowerApp_PowerUpDownCountClr(VOLTAGE_TYPE_UP);
		}
	    if( Battery_Voltage <= DownPowerVoltage)
	    {       
	    	/*BATT+Voltage down*/
	        PowerApp_PowerVoltageDeal(VOLTAGE_TYPE_DOWN,Battery_Voltage);      
	        Battery_TalModeGetFlag = PowerApp_PowerModeSwitchFunc(VOLTAGE_TYPE_DOWN);
	    }
		else
		{
			PowerApp_PowerUpDownCountClr(VOLTAGE_TYPE_DOWN);
		}
	}
    if((Battery_TalModeGetFlag)||(INIT_TalModeGetFlag))
    {        
        ModeChange = PowerApp_PowerVoltageModeJudge();  

    }
    if(TRUE == ModeChange)
    {
        for(i=0;i<E_POWER_VOLTAGE_INDEX_MAX;i++)
        {
            if(NULL != PowerUpTbl[i].Status)
            {                  
                PowerUpTbl[i].Status->BattTimer=0;  
            }  
            if(NULL != PowerDownTbl[i].Status)
            {
                PowerDownTbl[i].Status->BattTimer=0; 
            } 
            if(Pow_Voltage_State == PowerDownTbl[i].VoltageMode)
            {
                if(Pow_Voltage_State == VOLTAGE_STATE_UNDER_LOW)
                {
                    DownPowerVoltage = PowerDownTbl[i].SampleAD;
                }
                else
                {
               	 	if(i<E_POWER_VOLTAGE_INDEX_3)
                	{
                    	DownPowerVoltage = PowerDownTbl[i+1].SampleAD;
                	}
                }
            }
            else
            {
                if(Pow_Voltage_State == VOLTAGE_STATE_OVER_HIGH)
                {
                    DownPowerVoltage = PowerDownTbl[0].SampleAD;
                }
            }
            if(Pow_Voltage_State == PowerUpTbl[i].VoltageMode)
            {
                if(Pow_Voltage_State== VOLTAGE_STATE_OVER_HIGH)
                {
                    UpPowerVoltage = PowerUpTbl[i].SampleAD;
                }
                else
                {
                    UpPowerVoltage = PowerUpTbl[i-1].SampleAD;
                }
            }
            else
            {
                if(Pow_Voltage_State == VOLTAGE_STATE_UNDER_LOW)
                {
                    UpPowerVoltage = PowerUpTbl[3].SampleAD;
                }
            }
                    
        }
        switch ((VOLTAGE_STATE)Pow_Voltage_State)
        {
            
            case VOLTAGE_STATE_INIT:
				Bat_Vol_State = BAT_VOL_STA_NORMAL;
            break;
            case VOLTAGE_STATE_NORMAL:
            {       
				Bat_Vol_State = BAT_VOL_STA_NORMAL;
            }
            break;
            case VOLTAGE_STATE_UNDER_LOW:
            {
                Bat_Vol_State = BAT_VOL_STA_UNDER;
            }
            break;    
            case VOLTAGE_STATE_LOW:
            {
            	Bat_Vol_State = BAT_VOL_STA_UNDER;
            }
            break;  
            case VOLTAGE_STATE_HIGH: 
            {
            	Bat_Vol_State = BAT_VOL_STA_OVER;
            }
            break;  
            case VOLTAGE_STATE_OVER_HIGH:
            {
                Bat_Vol_State = BAT_VOL_STA_OVER;
            }
            break;
            default :
                
            break;
        }

    }


}



/*******************************************************************************
*Name        : PowerApp_Voltage_100mS_Periodic_Detect
*Function    : Battery voltage status Detect
*argument    : NONE
*Retval      : NONE
*explain     : NONE
*******************************************************************************/

void PowerApp_Voltage_100mS_Periodic_Detect(void)
{
	PowerApp_PowerDetectProc();
}


void PowerApp_Ign_Line_100mS_periodic_Detect(void)
{

	#if POWER_MODE_IGN_LINE_DET_EN
	
	uint16_t Vol = DigitalIf_Adc_DataGet(Digital_Adc_Index0);

	if (Vol >= IGN_ON_VOLTAGE)
	{
		Vol_Off_Filter = 0;

		if (Vol_Ign_Filter < IGN_ON_FILTER_TIME)
		{
			Vol_Ign_Filter++;
		}
		else
		{
			Ign_Line_Power_Mode = POWER_MODE_ON;
		}
	}
	else if (Vol <= IGN_OFF_VOLTAGE)
	{
		Vol_Ign_Filter = 0;

		if (Vol_Off_Filter < IGN_OFF_FILTER_TIME)
		{
			Vol_Off_Filter++;
		}
		else
		{
			Ign_Line_Power_Mode = POWER_MODE_OFF;
		}
	}
	#endif
}

void PowerApp_LinNm_State_Judge(void)
{
//	#if (CAR_PUB_NET_COM_MEOD == NET_COM_LIN_CAN)
	#if (CAR_PUB_NET_COM_MEOD == NET_COM_LIN_CAN || CAR_PUB_NET_COM_MEOD == NET_COM_LIN)
	
	if(l_ifc_Nm_Sleep_State_get)
	{
		System_Sleep_Event_Set(LIN_BUS_EVENT);
		System_Sleep_Event_Set(RUNNING_TOUT_EVENT);
		System_Sleep_Event_Set(CAN_BUS_EVENT);
		
	}
	else
	{
		System_Sleep_Event_Clear(LIN_BUS_EVENT);
	}
	#else
	System_Sleep_Event_Set(LIN_BUS_EVENT);
	#endif
}

void PowerApp_IGN_State_Judge(void)
{
	#if EXTERN_WAKEUP_IGN_EN

	if(DigitalIf_IoRd_DataGet(Digital_IoRd_Index5))
	{
		Ign_Off_Tick_10mS =0u;
		if(Ign_Running_Tick_10mS<IGN_FILTER_TICK_10MS_COUNT)
		{
			Ign_Running_Tick_10mS++;
		}
		else
		{
			System_Sleep_Event_Clear(IGN_OFF_EVENT);
			Ign_WakeupFlag =1u;
		}
		
	}
	else
	{
		Ign_Running_Tick_10mS =0u;
		if(0u == Ign_WakeupFlag)
		{
			System_Sleep_Event_Set(IGN_OFF_EVENT);
		}
		else
		{
			
			if(Ign_Off_Tick_10mS<IGN_OFF_TICK_10MS_COUNT)
			{
				Ign_Off_Tick_10mS++;
			}
			else
			{
				System_Sleep_Event_Set(IGN_OFF_EVENT);
			}
		}
	
	}
	
	#endif
	
}


void PowerApp_Sleep_Judge(void)
{
//	#if (CAR_PUB_NET_COM_MEOD == NET_COM_LIN_CAN)
	#if (CAR_PUB_NET_COM_MEOD == NET_COM_LIN_CAN || CAR_PUB_NET_COM_MEOD == NET_COM_LIN)
	
	//static uint32_t Wait_Transceiver_Entry_LowPow_Cnt = 0;
	if(0u == PowerApp_SystemNoSleepEn)
	{
		if (UnSleep_Flag)
		{
			//Wait_Transceiver_Entry_LowPow_Cnt = 0;
			#if (CAR_PUB_NET_COM_MEOD == NET_COM_LIN_CAN)
			CAN_WorkModeControl(CanPhyMod_Nor);
			#endif
			#if (MCU_LIN_MASTER_USE_DEFINE == STD_ON)
			
				LinTrcv_SetOpMode(LIN_TRCV_INDEX0,LIN_TRCV_MODE_NORMAL);

			#endif

			#if (MCU_LIN_SLAVE_USE_DEFINE == STD_ON)
			
				LinTrcv_SetOpMode(LIN_TRCV_INDEX1,LIN_TRCV_MODE_NORMAL);
			
			#endif
		}
		else
		{
			#if (CAR_PUB_NET_COM_MEOD == NET_COM_LIN_CAN)
			CAN_WorkModeControl(CanPhyMod_GoTSp);
			CAN_WorkModeControl(CanPhyMod_Sp);
			#endif
			#if (MCU_LIN_MASTER_USE_DEFINE == STD_ON)
			
				LinTrcv_SetOpMode(LIN_TRCV_INDEX0,LIN_TRCV_MODE_STANDBY);

			#endif

			#if (MCU_LIN_SLAVE_USE_DEFINE == STD_ON)
			
				LinTrcv_SetOpMode(LIN_TRCV_INDEX1,LIN_TRCV_MODE_STANDBY);
			
			#endif
			#if SLEEP_POWER_CTRL_MODE == SLEEP_POWER_CTRL_SHUT_POWER
			Power.MainPowerState = POWER_OFF_WAIT;
			#else
			Power.MainPowerState = SYSTEM_SLEEP;
			#endif
		}
	}
	else
	{
		#if (CAR_PUB_NET_COM_MEOD == NET_COM_LIN_CAN)
		CAN_WorkModeControl(CanPhyMod_Nor);
		#endif
		#if (MCU_LIN_MASTER_USE_DEFINE == STD_ON)
		
			LinTrcv_SetOpMode(LIN_TRCV_INDEX0,LIN_TRCV_MODE_NORMAL);

		#endif

		#if (MCU_LIN_SLAVE_USE_DEFINE == STD_ON)
		
			LinTrcv_SetOpMode(LIN_TRCV_INDEX1,LIN_TRCV_MODE_NORMAL);
		
		#endif
		
	}
	
	#elif (CAR_PUB_NET_COM_MEOD == NET_COM_CAN)
	if(0u == PowerApp_SystemNoSleepEn)
	{
		if (UnSleep_Flag)
		{
			CAN_WorkModeControl(CanPhyMod_Nor);
		}
		else
		{
			CAN_WorkModeControl(CanPhyMod_GoTSp);
			CAN_WorkModeControl(CanPhyMod_Sp);
			#if SLEEP_POWER_CTRL_MODE == SLEEP_POWER_CTRL_SHUT_POWER
			Power.MainPowerState = POWER_OFF_WAIT;
			#else
			Power.MainPowerState = SYSTEM_SLEEP;
			#endif
		}
	}
	else
	{
		CAN_WorkModeControl(CanPhyMod_Nor);
	}

	#endif
}


uint8_t PowerApp_MainPowerStateGet(void)
{
	return Power.MainPowerState;
}
void PowerApp_ManageProcess(void)
{

	switch (Power.MainPowerState)
	{
    	case POWER_ON_RESET:
			#if POWER_WAKEUP_DISCHARGE_EN
	       	/*When the main power supply is turned on, the delay time from the last time off to ensure that the discharge is complete*/
	        if (Power.WaitTimer<POWER_ON_START_INTERVAL)
	        {
	            break;
	        }
			#endif
			Power.WaitTimer=0;
	        Power.MainPowerState = POWER_ON_START;
        break;

	    case POWER_ON_START:
	        
	        Power.WaitTimer=0;
			// TODO:
			/*Whether to consider placing hardware-related initialization here*/
	        Power.MainPowerState = POWER_ON_INIT_MODULE;
	        break;

	    case POWER_ON_INIT_MODULE:
			// TODO:
			/*Whether to consider placing the external power enable here*/
	        PowerApp_ModelPowerOnCustomer();
	        break;

	    case POWER_SYS_RUNNING:
			PowerApp_LinNm_State_Judge();
			PowerApp_IGN_State_Judge();
			PowerApp_Sleep_Judge();
			Power.WaitTimer=0;	
	        break;
		case POWER_OFF_WAIT:
			#if SLEEP_POWER_CTRL_MODE == SLEEP_POWER_CTRL_SHUT_POWER
			// TODO:
			if(Power.WaitTimer>=POWER_OFF_WAIT_TIMEOUT)
			{
				Power.WaitTimer=0;
				System_ResetDelayTimeSet(T10_10MS);
				System_SwResetFlagSet(TRUE);
			}
			#endif
			//
			break;
	    case SYSTEM_SLEEP:
//			PowerApp_ModelPowerOffCustomer();
//			SystemMode__Entry_Standby();
//			System_Reset();
			//System_WakeupInit();
		break;
		default:
	    break;
	}

}
/*******************************************************************************
* Function name: Get_Battery_Voltage_State
* Function Function: Obtain power status
* Function parameter: none
* Function return: BAT_VOL_STA_UNDER/BAT_VOL_STA_NORMAL/BAT_VOL_STA_OVER
* Note: None
*******************************************************************************/
BAT_VOL_STATE Get_Battery_Voltage_State(void)
{
	return Bat_Vol_State;
}


uint8_t PowerApp_LinGetBattery_Voltage_State(void)
{
	return Pow_Voltage_State;
}
void PowerApp_DiagSleepNoResponseEnSet(uint8_t opStatus)
{
	PowerApp_DiagSleepNoResponseEn = opStatus;
}
uint8_t PowerApp_DiagSleepNoResponseEnGet(void)
{
	return PowerApp_DiagSleepNoResponseEn;
}

void PowerApp_SystemNoSleepEnSet(uint8_t opStatus)
{
	PowerApp_SystemNoSleepEn = opStatus;
}
uint8_t PowerApp_SystemNoSleepEnGet(void)
{
	return PowerApp_SystemNoSleepEn;
}


/*******************************************************************************
* Function name: Power_Mode_Set_By_LIN_Bus
* Function function: LIN bus set power mode
* Function argument: Mode OFF/ACC/ON/CRANK
* Function return: none
* Note: None
*******************************************************************************/
void Power_Mode_Set_By_LIN_Bus(POWER_MODE Mode)
{
	LIN_Bus_Power_Mode = Mode;
}

/*******************************************************************************
* Function name: Get_Power_Mode
* Function Function: Get power mode
* Function parameter: none
* Function return value: OFF/ACC/ON/CRANK
* Note: None
*******************************************************************************/
POWER_MODE Get_Power_Mode(void)
{

	#if (POWER_MODE_IGN_LINE_DET_EN && POWER_MODE_LIN_BUS_DET_EN)
		if (LIN_Bus_Power_Mode)
		{
			return LIN_Bus_Power_Mode;
		}
		else if (Ign_Line_Power_Mode)
		{
			return Ign_Line_Power_Mode;
		}

		return POWER_MODE_OFF;
	#elif POWER_MODE_LIN_BUS_DET_EN
		if (LIN_Bus_Power_Mode)
		{
			return LIN_Bus_Power_Mode;
		}
		return POWER_MODE_OFF;
	#elif POWER_MODE_IGN_LINE_DET_EN
		if (Ign_Line_Power_Mode)
		{
			return Ign_Line_Power_Mode;
		}
		return POWER_MODE_OFF;
	#else
		return POWER_MODE_ON;		// The SGM458 has no LIN power mode and no IGN cable, so it defaults to ON
	#endif
	
}

void PowerApp_Init(void)
{
	#if POWER_WAKEUP_DISCHARGE_EN
    Power.MainPowerState = POWER_ON_RESET;
	#else
	Power.MainPowerState = POWER_ON_START;
	#endif
	
	Ign_Line_Power_Mode = POWER_MODE_OFF;
	LIN_Bus_Power_Mode  = POWER_MODE_OFF;
	
	
}
void PowerApp_BattVolDataInit(void)
{
	Bat_Vol_State = BAT_VOL_STA_INIT;

	Vol_Ign_Filter = 0;
	Vol_Off_Filter = 0;
	UpToOverHighVolStatus.BattTimer =0U;
	UpToHighVolStatus.BattTimer =0U;
	UpToNormalVolStatus.BattTimer =0U;
	UpToLowsVolStatus.BattTimer =0U;
	DownToHighVolStatus.BattTimer =0U;
	DownToNormalVolStatus.BattTimer =0U;
	DownToLowVolStatus.BattTimer =0U;
	DownToUnderLowVolStatus.BattTimer =0U;
	Battery_Tal_Mode=0;
	Pow_Voltage_State = VOLTAGE_STATE_INIT;
	First_Vol_Over_Filter  =0;
	First_Vol_Under_Filter =0;
	First_Vol_Normal_Filter=0;
	BAT_First_PowerUp_Flg =0;
	Ign_Off_Tick_10mS =0u;
	Ign_Running_Tick_10mS=0u;
	Ign_WakeupFlag =0u;
	PowerApp_SystemNoSleepEn=0 ;
	PowerApp_Batt_Detect_Enable(TRUE);
}
void PowerVoltage_Param_Init(POWER_VOLTAGE_INIT_VALUE *Config)
{
	Power_Voltage_minDebounceTime =Config->minDebounceTime;
	PowerUpTbl[0].SampleAD = Config->UpToOverHighAD;
	PowerUpTbl[0].EnterDebounce = Config->UpToOverHighDebounce;
	PowerUpTbl[1].SampleAD = Config->UpToHighAD;
	PowerUpTbl[1].EnterDebounce = Config->UpToHighDebounce;
	PowerUpTbl[2].SampleAD = Config->UpToNormalAD;
	PowerUpTbl[2].EnterDebounce = Config->UpToNormalDebounce;
	PowerUpTbl[3].SampleAD = Config->UpToLowAD;
	PowerUpTbl[3].EnterDebounce = Config->UpToLowDebounce;

	PowerDownTbl[0].SampleAD = Config->DownToHighAD;
	PowerDownTbl[0].EnterDebounce = Config->DownToHighDebounce;
	PowerDownTbl[1].SampleAD = Config->DownToNormalAD;
	PowerDownTbl[1].EnterDebounce = Config->DownToNormalDebounce;
	PowerDownTbl[2].SampleAD = Config->DownToLowAD;
	PowerDownTbl[2].EnterDebounce = Config->DownToLowDebounce;
	PowerDownTbl[3].SampleAD = Config->DownToUnderLowAD;
	PowerDownTbl[3].EnterDebounce = Config->DownToUnderLowDebounce;
}
void PowerApp_100mS_PeriodicDetectProc(void)
{
	
	System_Running_Periodic_100mS();

}

void PowerApp_10mS_PeriodicDetectProc(void)
{

	PowerAppTimeProc();
	
	PowerApp_ManageProcess();
	
}


