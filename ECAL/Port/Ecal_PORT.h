/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      H source file                                                            */
/*   Name         :      PORT.h                                                                   */
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


#ifndef __INCLUDE_PORT_H__
#define __INCLUDE_PORT_H__
#include "Port.h"
#include "Dio.h"

#include "Port_Cfg_Mux_MVP.h"
#include "PortIf.h"


#define SET_LIN_TRANSCEIVER_MASTER_WORK_EN      	   	 				(Dio_WriteChannel(DioConf_DioChannel_LIN1_M_CS, STD_HIGH)) 
#define CLR_LIN_TRANSCEIVER_MASTER_WORK_EN      	   	 				(Dio_WriteChannel(DioConf_DioChannel_LIN1_M_CS, STD_LOW)) 


#define SET_LIN_TRANSCEIVER_SLAVE_WORK_EN      	   	 					(Dio_WriteChannel(DioConf_DioChannel_LIN0_S_CS, STD_HIGH)) 
#define CLR_LIN_TRANSCEIVER_SLAVE_WORK_EN      	   	 					(Dio_WriteChannel(DioConf_DioChannel_LIN0_S_CS, STD_LOW)) 

#define GET_LIN_TRANSCEIVER_INH_STATUS             						(Dio_ReadChannel(DioConf_DioChannel_LIN_CAN_WAKE))

#define GET_CAN_TRANSCEIVER_ERR_STATUS             						(Dio_ReadChannel(DioConf_DioChannel_CAN0_ERR))


#define SET_CAN_TRANSCEIVER0_WORK_EN      	   	 						(Dio_WriteChannel(DioConf_DioChannel_CAN0_EN, STD_HIGH)) 
#define CLR_CAN_TRANSCEIVER0_WORK_EN      	   	 						(Dio_WriteChannel(DioConf_DioChannel_CAN0_EN, STD_LOW)) 

#define SET_CAN_TRANSCEIVER0_STB 	   	 								(Dio_WriteChannel(DioConf_DioChannel_CAN0_STB, STD_HIGH)) 
#define CLR_CAN_TRANSCEIVER0_STB     	   	 							(Dio_WriteChannel(DioConf_DioChannel_CAN0_STB, STD_LOW)) 





#define SET_MCU_CONTROL_5V_POWER_EN_EN       	    					(Dio_WriteChannel(DioConf_DioChannel_SPWR_EN,STD_HIGH))
#define CLR_MCU_CONTROL_5V_POWER_EN_EN             						(Dio_WriteChannel(DioConf_DioChannel_SPWR_EN,STD_LOW))





#define SET_SPI1_CS0_EN                                                   (Dio_WriteChannel(DioConf_DioChannel_SPI1_CS1, STD_HIGH)) 
#define CLR_SPI1_CS0_EN                                                   (Dio_WriteChannel(DioConf_DioChannel_SPI1_CS1, STD_LOW)) 	 

#define SET_SPI1_CS1_EN                                                   (Dio_WriteChannel(DioConf_DioChannel_SPI1_CS2, STD_HIGH))        	    							
#define CLR_SPI1_CS1_EN                                                   (Dio_WriteChannel(DioConf_DioChannel_SPI1_CS2, STD_LOW)) 	  

#define SET_SPI1_CS2_EN                                                   (Dio_WriteChannel(DioConf_DioChannel_SPI1_CS3, STD_HIGH))        	    							
#define CLR_SPI1_CS2_EN                                                   (Dio_WriteChannel(DioConf_DioChannel_SPI1_CS3, STD_LOW)) 	  

#define SET_SPI1_CS3_EN                                                   (Dio_WriteChannel(DioConf_DioChannel_SPI1_CS4, STD_HIGH))        	    							
#define CLR_SPI1_CS3_EN                                                   (Dio_WriteChannel(DioConf_DioChannel_SPI1_CS4, STD_LOW)) 	  

#define SET_SPI1_CS4_EN                                                   (Dio_WriteChannel(DioConf_DioChannel_SPI1_CS5, STD_HIGH))        	    							
#define CLR_SPI1_CS4_EN                                                   (Dio_WriteChannel(DioConf_DioChannel_SPI1_CS5, STD_LOW)) 	  

#define SET_SPI1_CS5_EN                                                   (Dio_WriteChannel(DioConf_DioChannel_SPI1_CS6, STD_HIGH))        	    							
#define CLR_SPI1_CS5_EN                                                   (Dio_WriteChannel(DioConf_DioChannel_SPI1_CS6, STD_LOW)) 	 

#define SET_SPI1_CS6_EN                                                   (Dio_WriteChannel(DioConf_DioChannel_SPI1_CS7, STD_HIGH)) 
#define CLR_SPI1_CS6_EN                                                   (Dio_WriteChannel(DioConf_DioChannel_SPI1_CS7, STD_LOW)) 	 

#define SET_SPI1_CS7_EN                                                   (Dio_WriteChannel(DioConf_DioChannel_SPI1_CS8, STD_HIGH))        	    							
#define CLR_SPI1_CS7_EN                                                   (Dio_WriteChannel(DioConf_DioChannel_SPI1_CS8, STD_LOW)) 	  

#define SET_SPI1_CS8_EN                                                   (Dio_WriteChannel(DioConf_DioChannel_SPI1_CS9, STD_HIGH))        	    							
#define CLR_SPI1_CS8_EN                                                   (Dio_WriteChannel(DioConf_DioChannel_SPI1_CS9, STD_LOW)) 	  

#define SET_SPI1_CS9_EN                                                   (Dio_WriteChannel(DioConf_DioChannel_SPI1_CS10, STD_HIGH))        	    							
#define CLR_SPI1_CS9_EN                                                   (Dio_WriteChannel(DioConf_DioChannel_SPI1_CS10, STD_LOW)) 	  

// Batt+ DTC enable


#define SET_BATT_VOLTAGE_DET_EN     	   	 							  (Dio_WriteChannel(DioConf_DioChannel_VOLTAGE_DTC_EN,STD_HIGH)) 
#define CLR_BATT_VOLTAGE_DET_EN            								  (Dio_WriteChannel(DioConf_DioChannel_VOLTAGE_DTC_EN,STD_LOW)) 


#define SET_HSD_VALVE_POWER_SUPPLY_EN      	   	 						 (Dio_WriteChannel(DioConf_DioChannel_VALVE_HSD_IN,STD_HIGH)) 
#define CLR_HSD_VALVE_POWER_SUPPLY_EN           						 (Dio_WriteChannel(DioConf_DioChannel_VALVE_HSD_IN,STD_LOW)) 


#define SET_HSD_VALVE_POWER_SUPPLY_DIAG_EN      	   	 				(Dio_WriteChannel(DioConf_DioChannel_VALVE_HSD_SEN,STD_HIGH)) 
#define CLR_HSD_VALVE_POWER_SUPPLY_DIAG_EN           				    (Dio_WriteChannel(DioConf_DioChannel_VALVE_HSD_SEN,STD_LOW)) 


#define SET_HSD_PUMP_POWER_SUPPLY_EN      	   	 						(Dio_WriteChannel(DioConf_DioChannel_PUMP_HSD_IN,STD_HIGH)) 
#define CLR_HSD_PUMP_POWER_SUPPLY_EN           				            (Dio_WriteChannel(DioConf_DioChannel_PUMP_HSD_IN,STD_LOW)) 


#define SET_HSD_PUMP_POWER_SUPPLY_DIAG_EN      	   	 				    (Dio_WriteChannel(DioConf_DioChannel_PUMP_HSD_SEN,STD_HIGH)) 
#define CLR_HSD_PUMP_POWER_SUPPLY_DIAG_EN           				    (Dio_WriteChannel(DioConf_DioChannel_PUMP_HSD_SEN,STD_LOW)) 


#endif /* __INCLUDE_PORT_H__*/
