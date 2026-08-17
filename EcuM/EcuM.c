/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : EcuM.c
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

/******************************************************************************
**                        Include Files
******************************************************************************/
#include "EcuM.h"

/******************************************************************************
**                        Version Check
******************************************************************************/

/******************************************************************************
**                        Macro Definitions
******************************************************************************/

/******************************************************************************
**                        Constants
******************************************************************************/

/******************************************************************************
**                        Type definitions
******************************************************************************/

/******************************************************************************
**                        Variables
******************************************************************************/

/******************************************************************************
**                        Function definitions
******************************************************************************/

/**
 * @brief This function sets the last wakeup event of the ECUM.
 *
 * @param source - last wakeup event
 * @return None
 */
/* PRQA S 3206  ++*/
void EcuM_SetWakeupEvent(EcuM_WakeupSourceType source)
{
    /* user code */
#if 0
    /* Check if the wakeup source is CAN related */
    if (source == ECUM_WKUP_CAN) 
    {
        /**
         * @note When CAN is the wakeup source and the controller is already in STOP state,
         *       only need to call Can_SetControllerMode() to switch to START mode,
         *       to resume normal CAN communication.
         */

        /* Step: Start the CAN controller directly from STOP state */
        (void)Can_SetControllerMode(0U, CAN_CS_STARTED); 
    }

    /* Other wakeup sources can be handled here if needed */
#endif
}

/**
 * @brief Check wakeup events.
 *
 * @param source - The wakeup source that needs to be checked.
 * @return None
 */
/* PRQA S 3206  ++*/
void EcuM_CheckWakeup(EcuM_WakeupSourceType source)
{
    /* user code */
#if 0
    /* Check if the wakeup source is CAN related */
    if (source == ECUM_WKUP_CAN)  
    {
        /**
         * @note When CAN is the wakeup source, call Can_CheckWakeup() to notify the CAN driver
         *       to handle the wake-up event. This ensures that the CAN module can perform any
         *       necessary actions such as switching controller mode or clearing flags.
         */
        Can_CheckWakeup(0U);  
    }

    /* Other wakeup sources can be handled here if needed */
#endif
}
/* EOF */
