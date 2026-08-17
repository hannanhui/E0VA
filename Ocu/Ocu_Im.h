/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Ocu_Im.h
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
#ifndef OCU_IM_H
#define OCU_IM_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 **                        MISRA-C Rules Violations
 ******************************************************************************/
/**
 * @page misra_violations MISRA-C:2004 violations
 *
 * @section
 */

/******************************************************************************
 **                        QAC Warnings
 ******************************************************************************/
/**
 * @page QAC Warnings
 *
 */

/******************************************************************************
 **                        Include Files
 ******************************************************************************/
#include "Ocu.h"

/******************************************************************************
 **                        File Version Check
 ******************************************************************************/

/******************************************************************************
 **                        Macro  Definitions
 ******************************************************************************/

/******************************************************************************
 **                        Typedef  Definitions
 ******************************************************************************/

/******************************************************************************
 **                        Export Variables
 ******************************************************************************/

/******************************************************************************
 **                        Export Functions
 ******************************************************************************/

/**
 * @brief Initialize hardware unit configured
 *
 * @param HwUnitConfig-Hardware configuration information of the Ocu channel
 * @param CommonDir-Ocu count direction
 */
FUNC(void, OCU_CODE)
Ocu_Im_InitModule(P2CONST(Ocu_ImConfigType, AUTOMATIC, OCU_APPL_CONST) HwUnitConfig,
                  VAR(Ocu_CountDirectionType, OCU_VAR) CommonDir);

/**
 * @brief Initialize channels configured
 *
 * @param Module Hardware unit
 * @param ChannelConfig Configuration information about each OCU channel
 */
FUNC(void, OCU_CODE)
Ocu_Im_InitChannel(VAR(uint8, OCU_VAR) Module, P2CONST(Ocu_ChannelConfigType, AUTOMATIC, OCU_APPL_CONST) ChannelConfig);

/**
 * @brief De-initialize hardware unit configured
 *
 * @param HwUnitConfig-Hardware configuration information of the Ocu channel
 */
FUNC(void, OCU_CODE) Ocu_Im_DeInitModule(P2CONST(Ocu_ImConfigType, AUTOMATIC, OCU_APPL_CONST) HwUnitConfig);

/**
 * @brief De-initialize channels configured
 *
 * @param Module Hardware unit
 * @param Channel channel index
 */
FUNC(void, OCU_CODE)
Ocu_Im_DeInitChannel(VAR(uint8, OCU_VAR) Module, VAR(uint8, OCU_VAR) Channel);

/**
 * @brief Start an Ocu channel
 *
 * @param Module Hardware unit
 * @param Channel channel index
 * @param PinAction Automatic action (by hardware) to be performed on a pin
 */
FUNC(void, OCU_CODE)
Ocu_Im_StartChannelProcess(
  VAR(uint8, OCU_VAR) Module, VAR(uint8, OCU_VAR) Channel, VAR(Ocu_PinStateType, OCU_VAR) PinAction);

/**
 * @brief Stop an Ocu channel
 *
 * @param Module Hardware unit
 * @param Channel channel index
 */
FUNC(void, OCU_CODE)
Ocu_Im_StopChannelProcess(VAR(uint8, OCU_VAR) Module, VAR(uint8, OCU_VAR) Channel);

/**
 * @brief Set immediately the level of the pin associated to an OCU channel
 *
 * @param Module Hardware unit
 * @param Channel channel index
 * @param PinState Output state of the pin
 */
FUNC(void, OCU_CODE)
Ocu_Im_SetPinOutPutState(VAR(uint8, OCU_VAR) Module, VAR(uint8, OCU_VAR) Channel,
                         VAR(Ocu_PinStateType, OCU_VAR) PinState);

/**
 * @brief Indicate driver what shall be done automatically by hardware (if supported) upon compare match
 *
 * @param Module Hardware unit
 * @param Channel channel index
 * @param PinAction Automatic action (by hardware) to be performed on a pin
 */
FUNC(void, OCU_CODE)
Ocu_Im_SetPinAction(VAR(uint8, OCU_VAR) Module, VAR(uint8, OCU_VAR) Channel, VAR(uint8, OCU_VAR) PinAction);

/**
 * @brief Read the current value of the counter
 *
 * @param Module Hardware unit
 * @retval Ocu_ValueType Current value of the counter
 */
FUNC(Ocu_ValueType, OCU_CODE) Ocu_Im_GetCounter(VAR(uint8, OCU_VAR) Module);

/**
 * @brief Set the value of the channel threshold
 *
 * @param Module Hardware unit
 * @param Channel channel index
 * @param Value Threshold to be setted
 */
FUNC(void, OCU_CODE)
Ocu_Im_SetChannelThreshold(VAR(uint8, OCU_VAR) Module, VAR(uint8, OCU_VAR) Channel, VAR(Ocu_ValueType, OCU_VAR) Value);

/**
 * @brief Enable/Disable the comparator channel interrupt function, call notification when flag is set
 *
 * @param Module Hardware unit
 * @param Channel channel index
 * @param Enabled State of channel interrupt to be setted
 */
FUNC(void, OCU_CODE)
Ocu_Im_SetChannelIntrEnabled(VAR(uint8, OCU_VAR) Module, VAR(uint8, OCU_VAR) Channel, VAR(boolean, OCU_VAR) Enabled);

/**
 * @brief Get interrupt flags of hardware unit
 *
 * @param Module-Hardware unit
 * @retval uint32-Interrupt flags
 */
FUNC(uint32, OCU_CODE) Ocu_Im_GetAllIntrFlags(VAR(uint8, OCU_VAR) Module);

/**
 * @brief Clear interrupt flags of hardware unit
 *
 * @param Module-Hardware unit
 */
FUNC(void, OCU_CODE) Ocu_Im_ClearAllInterFlags(VAR(uint8, OCU_VAR) Module);
#ifdef __cplusplus
}
#endif

#endif

/* EOF */
