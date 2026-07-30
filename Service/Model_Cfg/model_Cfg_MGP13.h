/**************************************************************************************************/
/*                                                                                                */
/*   Project      :                                                                               */
/*   Type         :      H source file                                                            */
/*   Name         :      model_Cfg_MGP13.h                                                        */
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

#ifndef MODEL_CFG_MVP_H_
#define MODEL_CFG_MVP_H_

#include "Type_Define.h"

/* ------------------------------------------------------------------------------------------------
-------------------------------1.Version information configuration area----------------------------
---------------------------------------------------------------------------------------------------*/

#define STR_CFG_COMPANY_MODEL        		 "MVP13"
#define STR_CFG_VERSION       	 		     "01.00.01"
#define STR_CFG_DATE            		     "2025-10-20"

#define MCU_CONFIG_MAIN_VERSION            "V01.00.01_251222_Boot_DrvLib\0"

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
#define SYSTEM_CORE_FREQ_HZ   		( 120000000UL )

#define EXT_INTER_CLOCK_SELECT			1U//0 Use Inside Clock 1 Use Ext Clock
#define EXT_SRYSTAL_OSC_FREQ_HZ   		( 8000000UL )
#define SPI_COMM_BAUDRETE		1000000UL
// ϵͳʱ��96MHzʱ������1mS��ʱ������Ҫ���ú���"System_Check_Tout_Is_Tout"�Ĵ�����
// �����ԼƵ�216SСʱ
#define AT_96MHZ_1mS_LOOP_COUNT			660U


#define AT_SPI_COMMUMICATION_TIMEOUT			AT_96MHZ_1mS_LOOP_COUNT

//Watchdog function enable
#define WATCHDOG_FUNC_EN					1U		
#define LIN_FUNCTION_USE_EN			1U

#define CAN_FUNCTION_USE_EN			0U

#define PRESSURE_SENSOR_FUNCTION_USE_EN			1U


#define INT_PRIORITY_GROUP_TYPE		//INT_PRIORITY_GROUP_0VS4

#define PMC_IRQ_PRIORITY   			1, 0		// PMC�����ж� �ж����ȼ�����

#define T14_IRQ_PRIORITY			0, 15		// T14  �ж����ȼ�����

#define DEBUG_PRINT_IRQ_PRIORITY   	0, 14		// ������Ϣ��ӡ �ж����ȼ�����

#define ADC0_IRQ_PRIORITY 			0, 13		// ADC �ж����ȼ�����

#define LIN_IRQ_PRIORITY 			0, 12		// LIN_BUS �ж����ȼ�����

//#define SYSTEMTICK_IRQ_PRIORITY 	0, 14		// LIN_BUS �ж����ȼ�����

//Disable watchdog during debugging
#define DEBUG_APPLICATION_ENABLE			0U
/*
	ϵͳʹ�����»������ţ�
	������         PORT     ����           ��������

	Wake1    PC6	   IGN    �½���
	Wake2    PC0       KEY	     ������
	Wake7    PA15  	   LIN    �½���
	Wake10   PD13
*/

#define WAKEUP_PORT1_EN				1U
#define WAKEUP_PORT2_EN				0U
#define WAKEUP_PORT3_EN				1U
#define WAKEUP_PORT4_EN				0U
#define WAKEUP_PORT5_EN				0U
#define WAKEUP_PORT7_EN				0U
#define WAKEUP_PORT10_EN			0U

/*				PM_TRIGGER_RISE_EDGE: WKPx�����ش���
 *              PM_TRIGGER_FALL_EDGE: WKPx�½��ش���
 */
#define WAKEUP_IGN_TRIGGER_EDGE		PM_TRIGGER_FALL_EDGE
#define WAKEUP_KEY_TRIGGER_EDGE		PM_TRIGGER_RISE_EDGE
#define WAKEUP_LIN_TRIGGER_EDGE		PM_TRIGGER_FALL_EDGE

#define EXTERN_WAKEUP_LIN_PIN  PM_PIN_WKP3

#define EXTERN_WAKEUP_KEY_PIN  PM_PIN_WKP1
#define EXTERN_WAKEUP_IGN_PIN  PM_PIN_WKP2

#define EXTERN_WAKEUP_LIN_PIN_STATUS  PM_WAKEUP_EXTERNAL_PIN_WKP3

#define EXTERN_WAKEUP_KEY_PIN_STATUS  PM_WAKEUP_EXTERNAL_PIN_WKP1
#define EXTERN_WAKEUP_IGN_PIN_STATUS  PM_WAKEUP_EXTERNAL_PIN_WKP2





#define EXTERN_WAKEUP_LIN_INT  INT_WKP3

#define EXTERN_WAKEUP_KEY_INT  INT_WKP1
#define EXTERN_WAKEUP_IGN_INT  INT_WKP2

#if LIN_FUNCTION_USE_EN
#define EXTERN_WAKEUP_LIN_EN        WAKEUP_PORT3_EN
#else
#define EXTERN_WAKEUP_LIN_EN        0U
#endif
#define EXTERN_WAKEUP_KEY_EN        WAKEUP_PORT1_EN


#define EXTERN_WAKEUP_IGN_EN        0U
#define SLEEP_POWER_CTRL_SHUT_POWER  0U
#define SLEEP_POWER_CTRL_MCU_SLEEP   1U


#define SLEEP_POWER_CTRL_MODE		SLEEP_POWER_CTRL_MCU_SLEEP



#define RUNNING_TICK_100MS_COUNT	50	// (50*100)
#define IGN_OFF_TICK_10MS_COUNT	800	// (50*100)
#define IGN_FILTER_TICK_10MS_COUNT	20	// (50*100)


#define SLEEP_FUNC_EN				  		1U
#define NVM_FUNC_USE_PROPRIETARY_EN				  		1U


/* ------------------------------------------------------------------------------------------------
-------------------------------4.LIN information configuration area--------------------------------
---------------------------------------------------------------------------------------------------*/
#define POWER_WAKEUP_DISCHARGE_EN		0U




// LIN Signal Control Run mode Enable
#define LIN_BUS_CTRL_RUN_MODE_EN		1U

#if LIN_BUS_CTRL_RUN_MODE_EN
	// LIN Signal IGN Detect Enable 
	#define POWER_MODE_LIN_BUS_DET_EN		0U
#else
	#define POWER_MODE_LIN_BUS_DET_EN		0U
#endif

/* ------------------------------------------------------------------------------------------------
-------------------------------5.Sleep and wake up function configuration area---------------------
---------------------------------------------------------------------------------------------------*/

#define LPUART_INSTANCE_COUNT                    (1u)


/* ------------------------------------------------------------------------------------------------
-------------------------------6.System function configuration area--------------------------------
---------------------------------------------------------------------------------------------------*/





/* ------------------------------------------------------------------------------------------------
-------------------------------7.Pump motor drive mode configuration area--------------------------
---------------------------------------------------------------------------------------------------*/



/* ------------------------------------------------------------------------------------------------
-------------------------------8.Power high and low voltage parameter configuration area-----------
---------------------------------------------------------------------------------------------------*/



// Hardline IGN detection was enabled
#define POWER_MODE_IGN_LINE_DET_EN				0






#endif

