/*============================================================================*/
/*  Copyright (C) iSOFT   (2020), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Rte_ModeHandling.c>
 *  @brief      <>
 *  
 *  <MCU:TC233>
 *  
 *  @author     <>
 *  @date       <2021-12-24 16:09:14>
 */
/*============================================================================*/

/* Rte_ModeHandling.c */
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
#include "Rte_ModeHandling.h"
extern void EnableAllInterrupts();
extern void DisableAllInterrupts();

ModeMachine_EcuM_Mode modeMachine_currentMode_EcuM_EcuM_CurrentMode = {
	.currentMode = RTE_TRANSITION_EcuM_Mode,
	.nextMode = RTE_TRANSITION_EcuM_Mode,
	.fromMode = RTE_TRANSITION_EcuM_Mode,
	.inTransition = 0,
};

Rte_ModeType_EcuM_Mode currentMode_EcuM_EcuM_CurrentMode_buffer[MODE_QUEUE_SIZE_CURRENTMODE_ECUM_ECUM_CURRENTMODE];

Rte_ModeType_EcuM_Mode modeStep_EcuM_Mode(ModeMachine_EcuM_Mode* modeMachine)
{
	Rte_ModeType_EcuM_Mode nextMode;

	if (CirqBuffPop(&(modeMachine->queue),&nextMode) != 1) 
	{
		if (modeMachine->inTransition) 
			{
				modeMachine->fromMode = modeMachine->nextMode;
			}else 
			{
				modeMachine->fromMode = modeMachine->currentMode;
				DisableAllInterrupts();
				modeMachine->currentMode = RTE_TRANSITION_EcuM_Mode;
				EnableAllInterrupts();
				modeMachine->inTransition = 1;
			}
		modeMachine->nextMode = nextMode;
	} else if (modeMachine->inTransition) 
	{
		DisableAllInterrupts();
		modeMachine->currentMode = modeMachine->nextMode;
		EnableAllInterrupts();
		modeMachine->inTransition= 0;
		
	}
	return modeMachine->currentMode;
}


