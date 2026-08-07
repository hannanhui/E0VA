/******************************************************************************
|  Project Name: SAME5x AUTOSAR MCAL
|  Asr: File Name: Os.c
|
|  Description: Implementation of the Os Module
|               Target systems:           SAME5x
|               Derivatives:              SAME5x
|               Compiler:                 IAR
|               TechnicalReference:       AUTOSAR_SWS_OS.pdf
|------------------------------------------------------------------------------
|               C O P Y R I G H T
|------------------------------------------------------------------------------
|\file
|
| (c) Copyright 2021 Microchip Technology Inc. and its subsidiaries
|
| Microchip provides this software to you pursuant to the Microchip
| license agreement that accompanies the software. The software 
| is owned by Microchip and its licensors, and is protected under 
| applicable copyright laws. All rights reserved.
|
| EXCEPT AS OTHERWISE MAY BE PROVIDED IN THE MICROCHIP SOFTWARE LICENSE, THIS 
| SOFTWARE IS PROVIDED "AS IS." MICROCHIP EXPRESSLY DISCLAIMS ANY WARRANTY OF
| ANY KIND, WHETHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO, THE
| IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, OR
| NON-INFRINGEMENT. IN NO EVENT SHALL MICROCHIP BE LIABLE FOR ANY INCIDENTAL,
| SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, HARM
| TO YOUR EQUIPMENT, COST OF PROCUREMENT OF SUBSTITUTE GOODS, TECHNOLOGY OR
| SERVICES, ANY CLAIMS BY THIRD PARTIES (INCLUDING BUT NOT LIMITED TO ANY
| DEFENSE THEREOF), ANY CLAIMS FOR INDEMNITY OR CONTRIBUTION, OR OTHER SIMILAR
| COSTS. 
| To the fullest extent allowed by law, Microchip and its licensors liability 
| shall not exceed the amount of fees, if any, that you have paid directly to 
| Microchip to use this software.
|
|------------------------------------------------------------------------------
|------------------------------------------------------------------------------
|   FILE DESCRIPTION
|------------------------------------------------------------------------------
|    File:        Os.c
|    Project:     SAME5x_MCAL
|    Module:      OS
|    Description: Autosar 4.2.2 OS
|------------------------------------------------------------------------------
|
|------------------------------------------------------------------------------
|               A U T H O R   I D E N T I T Y
|------------------------------------------------------------------------------
| Initials     Name                      Company
| --------     ---------------------     --------------------------------------
| KishoreG     Kishore Gedda            Microchip Technology Inc.
|------------------------------------------------------------------------------
|
|*****************************************************************************/
/******************************************************************************
**                      Revision Control History                             **
*******************************************************************************
**V0.1: KishoreG 08-Apr-2020: [APG-668] Initial Version
******************************************************************************/

/******************************************************************************
 *  MISRA VIOLATIONS - Summary and analysis.
 *****************************************************************************/

/*******************************************************************************
 *  Includes
 ******************************************************************************/

#include "Os.h"
#include "EcuM.h"

/*******************************************************************************
 * VERSION CHECK
 ******************************************************************************/

#define OS_SW_MAJOR_VERSION_C         (1u)
#define OS_SW_MINOR_VERSION_C         (0u)
#define OS_SW_PATCH_VERSION_C         (0u)

#define OS_AR_RELEASE_MAJOR_VERSION_C (4u)
#define OS_AR_RELEASE_MINOR_VERSION_C (2u)
#define OS_AR_RELEASE_PATCH_VERSION_C (2u)

/*******************************************************************************
 *  Define & Macros
 ******************************************************************************/

static uint32 TickValue = 0u;

/*******************************************************************************
 *  TYPEDEFS
 ******************************************************************************/


/*******************************************************************************
 *  FUNCTION PROTOTYPES
 ******************************************************************************/


/*******************************************************************************
 *  FUNCTION DEFINITIONS
 ******************************************************************************/
//
//StatusType GetCounterValue (CounterType CounterID, TickRefType Value)
//{
//  TickValue++;
//
//  if (TickValue > OS_MAX_COUNTER_VALUE) {
//    TickValue = 0u;
//  }
//  else {
//    /* Do Nothing */
//  }
//
//  *Value =  TickValue;
//
//  return E_OK;
//}
//
//void StartOS(AppModeType Mode)
//{
//	EcuM_StartupTwo();
//}

//CoreIdType GetCoreID(void)
//{
	//return 0;
//}

//void ShutdownOS(uint8 Error)
//{
//	EcuM_Shutdown();
//}

//void Mcu_SetMode(uint8 Mode)
//{
	//;
//}
//
//void DisableAllInterrupts()
//{
//	;
//}
//
//void EnableAllInterrupts()
//{
//	;
//}
//
//void SuspendAllInterrupts()
//{
//  return;
//}
//void ResumeAllInterrupts()
//{
//  return;
//}
//void GetResource()
//{
//	;
//}
//void ReleaseResource()
//{
//	;
//}
uint16 GetResource(uint16 x)
{

}
uint16 ReleaseResource(uint16 x)
{

}
void ShutdownOS(StatusType Error)
{
	if(E_OK == Error)
	{
		EcuM_Shutdown();
	}
}
/*---------------------- End of File -----------------------------------------*/
