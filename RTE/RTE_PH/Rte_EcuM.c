/*============================================================================*/
/*  Copyright (C) iSOFT   (2020), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Rte_EcuM.c>
 *  @brief      <>
 *  
 *  <MCU:TC233>
 *  
 *  @author     <>
 *  @date       <2021-12-22 15:38:09>
 */
/*============================================================================*/

/* Rte_EcuM.c */
/*******************************************************************************
 **                        Revision Control History                           **
******************************************************************************/

/*******************************************************************************
 **                        Version Information                                **
******************************************************************************/

/*******************************************************************************
 **                        Include Section                                    **
******************************************************************************/
//#include "Os.h"
//#include "Os_Processor.h"
#include "Rte_EcuM.h"
/*#include "Rte_Data.h"*/
#include "Com.h"
#include "Rte_ModeHandling.h"

/*******************************************************************************
 **                        Global Function                                    **
******************************************************************************/

/*******************************************************************************
*Function-Name        Rte_Switch_EcuM_CurrentMode_currentMode
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Std_ReturnType
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

Std_ReturnType Rte_Switch_EcuM_CurrentMode_currentMode(Rte_ModeType_EcuM_Mode mode)
{
    switch (mode)
    {
		case RTE_MODE_EcuM_Mode_STARTUP:
			break;

		case RTE_MODE_EcuM_Mode_RUN:
			break;

		case RTE_MODE_EcuM_Mode_POST_RUN:
			/*do some post-run activity*/
			/*BswM_SwcModeNotification(0, ECUM_STATE_APP_POST_RUN);*/
			break;

		case RTE_MODE_EcuM_Mode_SHUTDOWN:
			/*Same with sleep.*/
		case RTE_MODE_EcuM_Mode_SLEEP:
			break;
        default:
            break;
    }


	return RTE_E_OK;
}

/*******************************************************************************
*Function-Name        Rte_Mode_EcuM_CurrentMode_currentMode
*Service ID           <None>
*Sync/Async           <Synchronous>
*Reentrancy           <Non Reentrant>
*param-Name[in]       <None>
*Param-Name[out]      <None>
*Param-Name[in/out]   <None>
*return               Rte_ModeType_EcuM_Mode
*PreCondition         <None>
*CallByAPI            <None>
******************************************************************************/

Rte_ModeType_EcuM_Mode Rte_Mode_EcuM_CurrentMode_currentMode(void)
{
	Rte_ModeType_EcuM_Mode mode;
#if 0 //devin comment 2025.04.27,no use
	imask_t irqMask = 0;
	Os_ArchSuspendInt(&irqMask);
	mode = modeMachine_currentMode_EcuM_EcuM_CurrentMode.currentMode;
	Os_ArchRestoreInt(irqMask);
#endif
	return mode;
}


