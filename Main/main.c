/**************************************************************************************************/
/**
 * @file      : main.c
 * @brief     : Can example source file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.0.0
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2022 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup Can
 *  @brief Can Example
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif
#include "include.h"
#include "LinIf.h"
#include "LinIf.h"
#include "Dem.h"
#include "Com.h"
#include "Wdg.h"
#include "eep_emulation.h"
#include "m_flash_drv.h"
volatile const static  uint8_t SwVer[VERSION_INFO_MAX_SIZE]  ={MCU_CUSTOMER_MAIN_VERSION};
volatile const static  uint8_t CfgSwVer[VERSION_INFO_MAX_SIZE]  ={MCU_CONFIG_MAIN_VERSION};


uint8 m_data[30];
int main(void)
{
	 System_Init();	
	 EcuM_Init();
	 EcuM_StartupTwo();
	  
	while (1)
	{
		SystemTickIf_MainWhileCallHandler();
	}
}

#define CAN_STOP_SEC_CODE

#ifdef __cplusplus
}
#endif


void DisableAllInterrupts()
{};
void EnableAllInterrupts()
{};
/** @} end of group Can_Example */


