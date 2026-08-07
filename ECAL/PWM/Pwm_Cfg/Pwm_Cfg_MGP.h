/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      H source file                                                            */
/*   Name         :      Pwm_Cfg_MGP.h                                                            */
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
#ifndef PWM_CFG_MGP_H_
#define PWM_CFG_MGP_H_
/***************************************************************************************************************************************
Valve Index  map and  Sensor Index map        
----------------------------------------------------------------------------------------------------------------------------------------
_______________________________________________________________________________________________________________________________________
| o    o o    o o    o o    o o    o |    _               _     _       | o    o  o    o  o    o  o    o  o    o  o    o  o    o |    _|
| index6 index7 index8 index9 index10|   |_|             |_|   |_|      |index13 index14 index15 index16 index17 index18 index19 |   | 
|          _                         |   P6              P5    P4       |                                                        |   |_
| Bottom->|_|                        ||                                 |                                                        |     | 
|        P10      _      _      _    ||              _________________  |                                                        |     | 
|                |_|    |_|    |_|   ||                o    o o    o  | |    _      _       _                                    |     | 
|                P9     P8     P7    ||               index11 index12 | |   |_|    |_|     |_|                   ________________|     | 
|                                    ||                               | |   P3     P2      P1                    |        _            |
|               o    o o    o o    o ||                               | | o    o  o    o  o    o                 |   ____| |____       | 
|               index2 index3 index4 ||                               | |index20 index21 index22                 |  |____| |____|      | 
|                 ^^                 ||                               | |                                        |       | |           |                                      
|        _________||                 ||                               | |                                        |   ----| |----       |                                            
|       |either-or||                 ||   o    o                      | |                                        |   ----| |----       |                                                                                       
|        ---------||                 ||   index5                      | |                                        |   ----| |----       |
|                 ||                 ||                               | |                                        |   ----| |----       |
| index1 index0 index2               ||    ___                        | |                                        |   ----| |----       | 
| o    o o    o o    o               ||   |   |                       | |                                        |   ____| |____       |                                   
|_______________________  ___________||   |___|       index24 index23 | |                                        |  |____| |____|      | 
                        )     ___     |    P0          o    o o    o  | |________________________________________|       |_|           |                
                        )_____|  |____|_______________ _______________|                      __________________________________________| 
                                                      |               >ooooooo              |  
                                                      |_____________________________________|
----------------------------------------------------------------------------------------------------------------------------------------                                                      
****************************************************************************************************************************************/



#define PWM_OPTPUT_FREQ_PERIOD (SYSTEM_CORE_FREQ_HZ/PWM_Period_Spread)
#define PWM_OPTPUT_DUTY_MAX_COUNT  0x8000



typedef enum
{
	E_PWM_CHANNEL_LIST_INDEX0=0U,   
	E_PWM_CHANNEL_LIST_INDEX1,  		
	E_PWM_CHANNEL_LIST_INDEX2,  	
	E_PWM_CHANNEL_LIST_INDEX3,  	
	E_PWM_CHANNEL_LIST_INDEX4, 		
	E_PWM_CHANNEL_LIST_INDEX5,  	
	E_PWM_CHANNEL_LIST_INDEX6,  	
	E_PWM_CHANNEL_LIST_INDEX7,  	
	E_PWM_CHANNEL_LIST_INDEX8,  	
	E_PWM_CHANNEL_LIST_INDEX9,  	
	E_PWM_CHANNEL_LIST_INDEX10, 	
	E_PWM_CHANNEL_LIST_INDEX11, 	
	E_PWM_CHANNEL_LIST_INDEX12, 	
	E_PWM_CHANNEL_LIST_INDEX13, 	
	E_PWM_CHANNEL_LIST_INDEX14, 	
	E_PWM_CHANNEL_LIST_INDEX15, 	
	E_PWM_CHANNEL_LIST_INDEX16, 	
	E_PWM_CHANNEL_LIST_INDEX17, 	
	E_PWM_CHANNEL_LIST_INDEX18, 	
	E_PWM_CHANNEL_LIST_INDEX19, 	
	E_PWM_CHANNEL_LIST_INDEX20, 	
	E_PWM_CHANNEL_LIST_INDEX21, 	
	E_PWM_CHANNEL_LIST_INDEX22, 	
	E_PWM_CHANNEL_LIST_INDEX23,		
	E_PWM_CHANNEL_LIST_INDEX24, 	
	E_PWM_CHANNEL_LIST_INDEX25, 	
	E_PWM_CHANNEL_LIST_INDEX26, 	
	E_PWM_CHANNEL_LIST_INDEX27, 	
	E_PWM_CHANNEL_LIST_INDEX28, 	
	E_PWM_CHANNEL_LIST_INDEX29, 	
	E_PWM_CHANNEL_LIST_INDEX30, 	
	E_PWM_CHANNEL_LIST_INDEX31, 	
	E_PWM_CHANNEL_LIST_NUM,

}E_PWM_CHANNEL_LIST;



#endif /* PWM_CFG_MGP_H_ */
