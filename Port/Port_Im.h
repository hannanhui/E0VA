/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Port_Im.h
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
#ifndef PORT_IM_H
#define PORT_IM_H

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
#include "Port.h"
/******************************************************************************
 **                        File Version Check
 ******************************************************************************/

/******************************************************************************
 **                        Macro  Definitions
 ******************************************************************************/
/**
 * @brief pin masked define.
 * true : Port Pin is masked.
 * false: Port Pin is not masked
 */
#define PORT_PIN_NOT_MASKED (0x00U)
#define PORT_PIN_MASKED     (0x01U)
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
 * @brief Get GPIO Mode value
 *
 * @param PinCfgValue PinsControl value
 * @retval 0 - Gpio IN
 * @retval 1 - Gpio OUT
 * @retval 2 - Remap Mode
 * @retval 3 - Analog Mode
 * @return uint8
 */
uint8 Port_Im_GetMode(uint32 PinCfgValue);

/**
 * @brief Sets the port pin mode
 *
 * @param PortIndex port index
 * @param PinIndex pin number
 * @param PinConfigValue pin config value
 * @param PortMode mode
 * @retval void
 * @return void
 */
void Port_Im_SetPinMode(Port_PinType PortIndex, Port_PinType PinIndex, Port_PinModeType PortAltFcn,
                        Port_PinModeType PortMode);

/**
 * @brief Pin refresh
 *
 * @param PortIndex port index
 * @param PinIndex pin number
 * @param PinConfigValue pin config value
 * @retval void
 * @return void
 */
void Port_Im_RefreshPinDirection(Port_PinType PortIndex, uint32 PinIndex, uint32 PinConfigValue);

/**
 * @brief Sets the port pin direction
 *
 * @param PortIndex port index
 * @param PinIndex pin number
 * @param Direction Port Pin Direction
 * @retval void
 * @return void
 */
void Port_Im_SetPinDirection(Port_PinType PortIndex, Port_PinType PinIndex, Port_PinDirectionType Direction);

/**
 * @brief port reset
 *
 * @retval void
 * @return void
 */
void Port_Im_Reset(void);

/**
 * @brief Get direction
 *
 * @param PortIndex port index
 * @param PinIndex pin number
 * @retval Port_PinDirectionType
 * @return PORT_PIN_IN config pin in
 * PORT_PIN_OUT config pin out
 */
Port_PinDirectionType Port_Im_GetModeDirectionStatus(Port_PinType PortIndex, Port_PinType PinIndex);

/**
 * @brief Determine whether the PIN is available
 *
 * @param PortIndex Port num 0-7
 * @param PinIndex Pin num 0-15
 * @retval uint8 Gpio pin be configured status
 * @return PORT_PIN_MASKED pin masked
 * PORT_PIN_NOT_MASKED pin not masked
 */
uint8 Port_Im_isPortPinMasked(uint8 PortIndex, uint32 PinIndex);

/**
 * @brief Pin configuration
 *
 * @param PortIndex port index
 * @param PinIndex pin number
 * @param PinConfigValue pin config value
 * @retval void
 * @return void
 */
void Port_Im_PinInit(Port_PinType PortIndex, uint32 PinIndex, uint32 PinConfigValue);

#ifdef __cplusplus
}
#endif

#endif
/* EOF */
