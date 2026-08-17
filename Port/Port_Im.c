/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Port_Im.c
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
/* PRQA S 4342 EOF #KQR004342 */
/* PRQA S 4340 EOF #KQR004340 */
/* PRQA S 0303 EOF #KQR000303 */
/* PRQA S 3990 EOF #KQR003990 */
/* PRQA S 4461 EOF #KQR004461 */
/* PRQA S 2844 EOF #KQR002844 */
/* PRQA S 2201 EOF #KQR002201 */
/* PRQA S 4899 EOF #KQR004899 */
/******************************************************************************
 **                        Include Files
 ******************************************************************************/
#include "Port.h"
#include "Port_Im.h"
#include "Std_Types.h"
#include "kf32a158sf_drv_gpio.h"
#include "kf32a158sf_drv_rst.h"
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

/******************************************************************************
 **                      Constant Declarations
 ******************************************************************************/

/******************************************************************************
**                     Variable Declarations
******************************************************************************/
/**
 * @brief Gpio pointer
 */
/* PRQA S 2203 4 #KQR002203 */
static Gpio_RegisterMap_t *const Gpio_UnitPtr[PORT_TOTAL_NUMBER] = {
  (Gpio_RegisterMap_t *)GPIOA_PTR, (Gpio_RegisterMap_t *)GPIOB_PTR, (Gpio_RegisterMap_t *)GPIOC_PTR,
  (Gpio_RegisterMap_t *)GPIOD_PTR, (Gpio_RegisterMap_t *)GPIOE_PTR, (Gpio_RegisterMap_t *)GPIOF_PTR,
  (Gpio_RegisterMap_t *)GPIOG_PTR, (Gpio_RegisterMap_t *)GPIOH_PTR};
/******************************************************************************
 **                      Private Function Declarations
 ******************************************************************************/

/******************************************************************************
 **                      Function Implementation
 ******************************************************************************/
/**
 * @brief Get Remap value
 *
 * @param PinCfgValue PinsControl value
 * @retval uint8 Remap value
 * @return 0 - 14 represents AF0 to AF14
 */
/* PRQA S 1505 1 #KQR001505 */
LOCAL_INLINE uint8 Port_Im_GetRemap(uint32 PinCfgValue)
{
    return ((PinCfgValue & 0xFFFF0000U) >> 16U);
}

/**
 * @brief Get GPIO Mode value
 *
 * @param PinCfgValue PinsControl value
 * @retval uint8 GPIO Mode value
 * @return 0 gpio in
 * 1 gpio out
 * 2 remap mode
 * 3 analog mode
 */
uint8 Port_Im_GetMode(uint32 PinCfgValue)
{
    return ((PinCfgValue & 0x0000C000U) >> 14U);
}

/**
 * @brief Get Level value
 *
 * @param PinCfgValue PinsControl value
 * @retval uint8 Level value
 * @return 0 low
 * 1 high
 */
LOCAL_INLINE uint8 Port_Im_GetLevel(uint32 PinCfgValue)
{
    return ((PinCfgValue & 0x00002000U) >> 13U);
}

/**
 * @brief Get PullStatus value
 *
 * @param PinCfgValue PinsControl value
 * @retval uint8 PushStatus
 * @return 0 pull none
 * 1 pull up
 * 2 pull down
 */
LOCAL_INLINE uint8 Port_Im_GetPullStatus(uint32 PinCfgValue)
{
    return ((PinCfgValue & 0x00001800U) >> 11U);
}

/**
 * @brief Get OpenDrain value
 *
 * @param PinCfgValue PinsControl value
 * @retval uint8 OpenDrain or Push-Pull
 * @return 0 Push-Pull
 * 1 Open-Drain
 */
LOCAL_INLINE uint8 Port_Im_GetOpenDrain(uint32 PinCfgValue)
{
    return ((PinCfgValue & 0x00000400U) >> 10U);
}

/**
 * @brief Get SlewRate value
 *
 * @param PinCfgValue PinsControl value
 * @retval uint8 SlewRate value
 * @return 0 Port speed 10MHZ
 * 1 Port speed 20MHZ
 */
LOCAL_INLINE uint8 Port_Im_GetSlewRate(uint32 PinCfgValue)
{
    return ((PinCfgValue & 0x00000200U) >> 9U);
}

/**
 * @brief Determine whether the PIN is available
 *
 * @param PortIndex Port num 0-7
 * @param PinIndex Pin num 0-15
 * @retval uint8 Gpio pin be configured status
 * @return PORT_PIN_MASKED pin masked
 * PORT_PIN_NOT_MASKED pin not masked
 */
uint8 Port_Im_isPortPinMasked(uint8 PortIndex, uint32 PinIndex)
{
    uint8 result;
    /* PRQA S 2203 3 #KQR002203 */
    const uint16 kvPort_PortPinsMask[PORT_TOTAL_NUMBER] = {
      MASK_PORTA, MASK_PORTB, MASK_PORTC, MASK_PORTD, MASK_PORTE, MASK_PORTF, MASK_PORTG, MASK_PORTH};

    /* FIXME: why not directly assign */
    if ((kvPort_PortPinsMask[PortIndex] & ((uint32)1U << PinIndex)) != PORT_PIN_NOT_MASKED)
    {
        result = PORT_PIN_MASKED;
    }
    else
    {
        result = PORT_PIN_NOT_MASKED;
    }

    return result;
}

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
                        Port_PinModeType PortMode)
{
    Gpio_RegisterMap_t *PortRegAddrPtr = Gpio_UnitPtr[PortIndex];

    /* assign PMOD register */
    Gpio_LL_WriteModeDirectionState(PortRegAddrPtr, (Gpio_PinIndex_t)PinIndex, (Gpio_PinMode_t)PortMode);

    if (MODE_RMP == PortMode)
    {
        /* assign RMPL register and OMOD to config value */
        Gpio_LL_WriteRemapCtrlState(PortRegAddrPtr, (Gpio_PinIndex_t)PinIndex, (Gpio_PinRemap_t)PortAltFcn);

        /* Assign page remap register : PAGE1 */
        Gpio_LL_WriteRemapMsbState(PortRegAddrPtr, (Gpio_PinIndex_t)PinIndex, (Gpio_PinRemap_t)PortAltFcn);
    }
    else
    {
        /* Do nothing */
    }
}

/**
 * @brief Pin refresh
 *
 * @param PortIndex port index
 * @param PinIndex pin number
 * @param PinConfigValue pin config value
 * @retval void
 * @return void
 */
void Port_Im_RefreshPinDirection(Port_PinType PortIndex, uint32 PinIndex, uint32 PinConfigValue)
{
    Gpio_RegisterMap_t *portRegPtr = Gpio_UnitPtr[PortIndex];

    /* config slew rate */
    Gpio_LL_WriteSpeedCtrlState(
      portRegPtr, (Gpio_PinIndex_t)PinIndex, (Gpio_PinSpeed_t)Port_Im_GetSlewRate(PinConfigValue));
    /* assign PODR register to config value */
    Gpio_LL_WriteOpenDrainState(portRegPtr, (Gpio_PinIndex_t)PinIndex, (bool)Port_Im_GetOpenDrain(PinConfigValue));
    /* assign PDR&PUP register to config value */
    Gpio_LL_WritePullState(portRegPtr, (Gpio_PinIndex_t)PinIndex, (Gpio_Pull_t)Port_Im_GetPullStatus(PinConfigValue));
    /* PRQA S 2032 1 #KQR002032 */
    switch (Port_Im_GetMode(PinConfigValue))
    {
    case (uint8)MODE_GPIO_IN: {
        /* assign PMOD register to gpio in mode */
        Gpio_LL_WriteModeDirectionState(portRegPtr, (Gpio_PinIndex_t)PinIndex, GPIO_PIN_MODE_IN);
    }
    break;
    case (uint8)MODE_GPIO_OUT: {
        /* config init pin output level */
        /* assign POR register */
        Gpio_LL_WriteOutputState(portRegPtr, (Gpio_PinIndex_t)PinIndex, (bool)Port_Im_GetLevel(PinConfigValue));

        /* assign PMOD register to gpio out mode */
        Gpio_LL_WriteModeDirectionState(portRegPtr, (Gpio_PinIndex_t)PinIndex, GPIO_PIN_MODE_OUT);
    }
    break;
    default: {
        /* assign PMOD register to gpio in mode */
        Gpio_LL_WriteModeDirectionState(portRegPtr, (Gpio_PinIndex_t)PinIndex, GPIO_PIN_MODE_IN);
    }
    break;
    }
}

/**
 * @brief Get direction
 *
 * @param PortIndex port index
 * @param PinIndex pin number
 * @retval Port_PinDirectionType
 * @return PORT_PIN_IN config pin in
 * PORT_PIN_OUT config pin out
 */
Port_PinDirectionType Port_Im_GetModeDirectionStatus(Port_PinType PortIndex, Port_PinType PinIndex)
{
    Gpio_RegisterMap_t const *portRegPtr = Gpio_UnitPtr[PortIndex];
    /* PRQA S 4322 2 #KQR004322 */
    return (Port_PinDirectionType)(Gpio_LL_ReadModeDirectionState(portRegPtr, (Gpio_PinIndex_t)PinIndex));
}

/**
 * @brief Sets the port pin direction
 *
 * @param PortIndex port index
 * @param PinIndex pin number
 * @param Direction Port Pin Direction
 * @retval void
 * @return void
 */
void Port_Im_SetPinDirection(Port_PinType PortIndex, Port_PinType PinIndex, Port_PinDirectionType Direction)
{
    Gpio_RegisterMap_t *portRegPtr = Gpio_UnitPtr[PortIndex];

    if (Direction == PORT_PIN_IN)
    {
        /* PMOD.PXPMDx = 00 */
        Gpio_LL_WriteModeDirectionState(portRegPtr, (Gpio_PinIndex_t)PinIndex, GPIO_PIN_MODE_IN);
    }
    else
    {
        /* PMOD.PXPMDx = 01 */
        Gpio_LL_WriteModeDirectionState(portRegPtr, (Gpio_PinIndex_t)PinIndex, GPIO_PIN_MODE_OUT);
    }
}

/**
 * @brief Pin configuration
 *
 * @param PortIndex port index
 * @param PinIndex pin number
 * @param PinConfigValue pin config value
 * @retval void
 * @return void
 */
void Port_Im_PinInit(Port_PinType PortIndex, uint32 PinIndex, uint32 PinConfigValue)
{
    Gpio_RegisterMap_t *PortRegAddrPtr = Gpio_UnitPtr[PortIndex];
    /* config slew rate */
    Gpio_LL_WriteSpeedCtrlState(
      PortRegAddrPtr, (Gpio_PinIndex_t)PinIndex, (Gpio_PinSpeed_t)Port_Im_GetSlewRate(PinConfigValue));
    /* assign PODR register to config value */
    Gpio_LL_WriteOpenDrainState(PortRegAddrPtr, (Gpio_PinIndex_t)PinIndex, (bool)Port_Im_GetOpenDrain(PinConfigValue));
    /* assign PDR&PUP register to config value */
    /* @implements #SWS_Port_00055 */
    Gpio_LL_WritePullState(
      PortRegAddrPtr, (Gpio_PinIndex_t)PinIndex, (Gpio_Pull_t)Port_Im_GetPullStatus(PinConfigValue));

    /* config pullup, pulldown, push-pull or OD , mode and direction */
    /* PRQA S 2032 1 #KQR002032 */
    switch (Port_Im_GetMode(PinConfigValue))
    {
    case (uint8)MODE_GPIO_IN: {
        /* assign PMOD register to gpio in mode */
        Gpio_LL_WriteModeDirectionState(PortRegAddrPtr, (Gpio_PinIndex_t)PinIndex, GPIO_PIN_MODE_IN);
    }
    break;
    case (uint8)MODE_GPIO_OUT: {
        /* config init pin output level */
        /* assign POR register */
        /* @implements #SWS_Port_00043 */
        Gpio_LL_WriteOutputState(PortRegAddrPtr, (Gpio_PinIndex_t)PinIndex, (bool)Port_Im_GetLevel(PinConfigValue));

        /* assign PMOD register to gpio out mode */
        Gpio_LL_WriteModeDirectionState(PortRegAddrPtr, (Gpio_PinIndex_t)PinIndex, GPIO_PIN_MODE_OUT);
    }
    break;
    case (uint8)MODE_RMP: {
        /* assign RMPL register and OMOD to config value */
        Gpio_LL_WriteRemapCtrlState(
          PortRegAddrPtr, (Gpio_PinIndex_t)PinIndex, (Gpio_PinRemap_t)Port_Im_GetRemap(PinConfigValue));

        /* assign PMOD register to config value */
        Gpio_LL_WriteModeDirectionState(PortRegAddrPtr, (Gpio_PinIndex_t)PinIndex, GPIO_PIN_MODE_REMAP);

        /* Assign page remap register : PAGE1 */
        Gpio_LL_WriteRemapMsbState(
          PortRegAddrPtr, (Gpio_PinIndex_t)PinIndex, (Gpio_PinRemap_t)Port_Im_GetRemap(PinConfigValue));
    }
    break;
    case (uint8)MODE_AN: {
        /* assign PMOD register to config value */
        Gpio_LL_WriteModeDirectionState(PortRegAddrPtr, (Gpio_PinIndex_t)PinIndex, GPIO_PIN_MODE_AN);
    }
    break;
    default: {
        /* config to analog mode */
        /* assign PMOD register to config value */
        Gpio_LL_WriteModeDirectionState(PortRegAddrPtr, (Gpio_PinIndex_t)PinIndex, GPIO_PIN_MODE_AN);
    }
    break;
    }
}

/**
 * @brief port reset
 *
 * @retval void
 * @return void
 */
void Port_Im_Reset(void)
{
    Rst_LL_SetCtl0State(RST_IDX_GPIOARST, (bool)BIT_CLR);
    Rst_LL_SetCtl0State(RST_IDX_GPIOBRST, (bool)BIT_CLR);
    Rst_LL_SetCtl0State(RST_IDX_GPIOCRST, (bool)BIT_CLR);
    Rst_LL_SetCtl0State(RST_IDX_GPIODRST, (bool)BIT_CLR);
    Rst_LL_SetCtl0State(RST_IDX_GPIOERST, (bool)BIT_CLR);
    Rst_LL_SetCtl0State(RST_IDX_GPIOFRST, (bool)BIT_CLR);
    Rst_LL_SetCtl0State(RST_IDX_GPIOGRST, (bool)BIT_CLR);
    Rst_LL_SetCtl0State(RST_IDX_GPIOHRST, (bool)BIT_CLR);
}
