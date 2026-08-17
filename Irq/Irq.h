/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Irq.h
 *  @Syntax          : GNU99
 *  @Author          : ChipON AE/FAE Group
 *  @Date            : 2025-08-29
 *  @Version         : V1.0.0_SF
 *  @Description     : This document describes the C language document template.
 ******************************************************************************
 *  Copyright (C) by Shanghai ChipON Micro-Electronic Co.,Ltd
 *  All rights reserved.
 *
 *  This software is copyright protected and proprietary to
 *  Shanghai ChipON Micro-Electronic Co.,Ltd.
 ******************************************************************************
 *                        REVISION HISTORY
 ******************************************************************************
 *  |Date        |Version  |Author       |Description
 ******************************************************************************
 *  |2025-08-29  |V1.0     |Wang Ning    |New creat
 *****************************************************************************/
#ifndef IRQ_H
#define IRQ_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
**                        Include Files
******************************************************************************/
#include "Mcal.h"
#include "Irq_Types.h"
/******************************************************************************
**                        Macro Definitions
******************************************************************************/

/******************************************************************************
**                        Constants
******************************************************************************/

/******************************************************************************
**                        Type definitions
******************************************************************************/
#define Irq_Enable()                                                                                                   \
    do                                                                                                                 \
    {                                                                                                                  \
        __asm volatile("ENI");                                                                                         \
        __asm volatile("NOP");                                                                                         \
    } while (0)
#define Irq_Disable()                                                                                                  \
    do                                                                                                                 \
    {                                                                                                                  \
        __asm volatile("DSI");                                                                                         \
        __asm volatile("NOP");                                                                                         \
    } while (0)
/******************************************************************************
**                        Variables
******************************************************************************/

/******************************************************************************
**                        Function definitions
******************************************************************************/
/******************************************************************************
 * Function Name   : Irq_Deinit
 *
 * Service ID   :
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Non Reentrant
 *
 * Parameters(in)   : None
 *
 * Parameters(inout)   : None
 *
 * Parameters(out)   : None
 *
 * Return value   : None
 *
 * Description   : The interrupt deinitialization and closes the interrupt according to the configuration
 *
 ******************************************************************************/
FUNC(void, BSWM_CODE) Irq_Deinit(void);
/******************************************************************************
 * Function Name   : Irq_Init
 *
 * Service ID   :
 *
 * Sync/Async   : Synchronous
 *
 * Reentrancy   : Non Reentrant
 *
 * Parameters(in)   : Config-Interrupt configuration information
 *
 * Parameters(inout)   : None
 *
 * Parameters(out)   : None
 *
 * Return value   : None
 *
 * Description   : Peripheral interrupt initialization, enable peripheral interrupt and level 1 interrupt according to
 *configuration
 *
 ******************************************************************************/
FUNC(void, BSWM_CODE) Irq_Init(P2CONST(Irq_ConfigType, AUTOMATIC, INT_APPL_DATA) Config);

#ifdef __cplusplus
}
#endif

#endif
