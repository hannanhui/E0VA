/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      H source file                                                            */
/*   Name         :      model_Cfg_MGP13.h                                                        */
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

#ifndef MODEL_CFG_MVP_H_
#define MODEL_CFG_MVP_H_

#include "Type_Define.h"

/* ------------------------------------------------------------------------------------------------
-------------------------------1.Version information configuration area----------------------------
---------------------------------------------------------------------------------------------------*/

#define STR_CFG_COMPANY_MODEL        		 "MVP13"
#define STR_CFG_VERSION       	 		     "01.00.04"
#define STR_CFG_DATE            		     "2026-06-10"

#define MCU_CONFIG_MAIN_VERSION            "V01.00.04_260610_App_DrvLib\0"

/* ------------------------------------------------------------------------------------------------
-------------------------------2.Memory information configuration area------------------------------------
---------------------------------------------------------------------------------------------------*/

#define 	FLASH_ONE_SECTOR_SIZE   0x2000

// Define the FLASH start address
#define    FLASH_BASE_ADDRESS     	0x00000000

// Define the Bootloader size
#define    BOOT_SIZE              	(0x10000)	//0x4000

// Define the Bootloader size
#define    DATAFLASH_SIZE              	(0x4000)	//0x4000

// Define the Application size
#define    APP_SIZE              	0x6C000	//0x6F000+0x10000+0x1000

// The entry address to start the loader
#define    BootLoderAddress       	(FLASH_BASE_ADDRESS)

// The entry address of the application
#define    ApplicationAddress     	(FLASH_BASE_ADDRESS + BOOT_SIZE+DATAFLASH_SIZE)
//
#define    INTERRUPT_VECTOR_TABLE_SIZE     	(0x400)

/* ------------------------------------------------------------------------------------------------
-------------------------------3.System information and interrupt configuration area---------------
---------------------------------------------------------------------------------------------------*/

//Defines the system run clock
#define SYSTEM_CORE_FREQ_HZ   		( 96000000UL )

#define SPI_COMM_BAUDRETE		1000000UL


//ADC reference voltage,unit: mV
#define AD_REF_VOL					5000U		
//12-bit precision ADC,range 0-4096
#define AD_RES_MAX					4095U		

#define BATTERY_RESISTANCE_HIGH_SIDE_OHM		56U
#define BATTERY_RESISTANCE_LOW_SIDE_OHM			15U


//Disable watchdog during debugging
#define DEBUG_APPLICATION_ENABLE			0U

#define NET_COM_CAN             0u //CAN communication, Use for CAR_PUB_NET_COM_MEOD or CAR_PRI_NET_COM_MEOD
#define NET_COM_LIN             1u //LIN communication, Use for CAR_PUB_NET_COM_MEOD or CAR_PRI_NET_COM_MEOD
#define NET_COM_LIN_CAN             2u //LIN communication, Use for CAR_PUB_NET_COM_MEOD or CAR_PRI_NET_COM_MEOD

#define DEBUG_NM_DISABLE

#define FLS_USE_BY_NONE_FUNC      0U
#define FLS_USE_BY_CAN_FUNC       1U
#define FLS_USE_BY_LIN_FUNC       2U
#define FLS_USE_BY_OTA_FUNC       3U




#define FLS_USE_BY_FUNC_TYPE   FLS_USE_BY_LIN_FUNC
/* The communication interaction method with the entire vehicle's public network */
#define CAR_PUB_NET_COM_MEOD        NET_COM_LIN_CAN

/* Communication and interaction methods for internal private networks 
*/
#define CAR_PRI_NET_COM_MEOD        NET_COM_LIN

#define MCU_LIN_MASTER_USE_DEFINE    (STD_ON)

#if ((CAR_PUB_NET_COM_MEOD == NET_COM_LIN_CAN)||(CAR_PUB_NET_COM_MEOD == NET_COM_LIN))
#define MCU_LIN_SLAVE_USE_DEFINE    (STD_ON)

#else
#define MCU_LIN_SLAVE_USE_DEFINE    (STD_OFF)

#endif
#define MCU_SPI_USE_DEFINE    (STD_ON)

#define SLEEP_POWER_CTRL_SHUT_POWER  0U
#define SLEEP_POWER_CTRL_MCU_SLEEP   1U


#define SLEEP_POWER_CTRL_MODE		SLEEP_POWER_CTRL_MCU_SLEEP


#define PRESSURE_USE_TYPE_SMP581      1U
#define PRESSURE_USE_TYPE_NSPAD1      2U

#define PRESSURE_USE_TYPE   PRESSURE_USE_TYPE_NSPAD1

#define RUNNING_TICK_100MS_COUNT	50	// (50*100)




#define EXTERN_WAKEUP_LIN_EN        1
#define EXTERN_WAKEUP_IGN_EN        0
#define EXTERN_WAKEUP_KEY_EN        0


#define IGN_OFF_TICK_10MS_COUNT	800	// (50*100)
#define IGN_FILTER_TICK_10MS_COUNT	20	// (50*100)

#define POWER_WAKEUP_DISCHARGE_EN		0U

/* ------------------------------------------------------------------------------------------------
-------------------------------6.System function configuration area--------------------------------
---------------------------------------------------------------------------------------------------*/





/* ------------------------------------------------------------------------------------------------
-------------------------------7.Pump motor drive mode configuration area--------------------------
---------------------------------------------------------------------------------------------------*/


// Whether it is a brushless motor
#define	PUMP_IS_BLDC_MOTOR  							0			// 0-brush motor   1-brushless motor
// PWM frequency setting
//The solenoid valve controls the PWM output frequency
#define VALVE_PWM_OUT_HZ									(30000U)	//(30000U)		
//The brush motor controls the PWM output frequency
#define DC_MOTOR_PWM_OUT_HZ								(22000U)			
//The brushless motor controls the PWM output frequency
#define BLDC_MOTOR_PWM_OUT_HZ							(100U)		

#define PUMP_DRIVING_BY_IO			0
#define PUMP_DRIVING_BY_GEAR			1
#define PUMP_DRIVING_BY_DUTY			2


#define PUMP_DRIVING_METHOD  PUMP_DRIVING_BY_IO



#define VALVE_DRIVING_BY_IO					0
#define VALVE_DRIVING_BY_PWM_UNION_IO		1
#define VALVE_DRIVING_BY_PWM_ALONE			2


#define VALVE_DRIVING_METHOD  VALVE_DRIVING_BY_PWM_ALONE
#define BOARD_TEMP_DIAG_OVER_LIMIT				170
#define BOARD_TEMP_DIAG_UNDER_LIMIT				-60
#define BOARD_TEMP_DIAG_HIGH_TEMP				100
#define BOARD_TEMP_DIAG_HIGH_TO_NORMAL_TEMP				94

#define BOARD_TEMP_DIAG_FILTER					T100_1S

/* ------------------------------------------------------------------------------------------------
-------------------------------8.Power high and low voltage parameter configuration area-----------
---------------------------------------------------------------------------------------------------*/



// Hardline IGN detection was enabled
#define POWER_MODE_IGN_LINE_DET_EN				0






#endif

