/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Ocu_Im.c
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
/* PRQA S 0303 EOF #KQR000303 */
/* PRQA S 4342 EOF #KQR004342 */
/* PRQA S 4322 EOF #KQR004322 */
/* PRQA S 2814 EOF #KQR002814 */
/* PRQA S 2824 EOF #KQR002824 */
/* PRQA S 2844 EOF #KQR002844 */
/* PRQA S 2201 EOF #KQR002201 */
/* PRQA S 4899 EOF #KQR004899 */
/* PRQA S 3383 EOF #KQR003383 */
/******************************************************************************
 **                        Include Files
 ******************************************************************************/
#include "Ocu_Im.h"
#include "kf32a158sf_drv_ccp.h"
#include "kf32a158sf_drv_rst.h"
#include "kf32a158sf_drv_pclk.h"
#include "kf32a158sf_drv_intr.h"
#include "kf32a158sf_drv_gptimer.h"

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
 **                        Constant Declarations
 ******************************************************************************/

/******************************************************************************
 **                      Variable Declarations
 ******************************************************************************/

/******************************************************************************
 **                      Private Function Declarations
 ******************************************************************************/
/** @brief Array of Ccp unit address */
/* PRQA S 2203 2 #KQR002203 */
static VAR(Ccp_RegisterMap_t *, OCU_VAR) const Ocu_CcpUnitPtr[OCU_MAX_CCP_UNIT_NUM] = {
  T0_PTR, T1_PTR, T2_PTR, T3_PTR, T4_PTR, T20_PTR, T21_PTR};
/******************************************************************************
 **                      Function definitions
 ******************************************************************************/

/**
 * @brief Enable clock and reset Ocu unit
 *
 * @param OcuUnit Comparison of unit
 * @return None
 */
static FUNC(void, OCU_CODE) Ocu_Im_UnitReset(VAR(Ocu_ModuleInstanceType, OCU_VAR) OcuUnit)
{
    switch (OcuUnit)
    {
    case OCU_MODULE_0: {
        Rst_LL_SetTimerEnabled(RST_T0, false);
        Rst_LL_SetTimerEnabled(RST_T0, true);

        Pclk_LL_SetTimerEnabled(PCLK_T0, true);

        break;
    }
    case OCU_MODULE_1: {
        Rst_LL_SetTimerEnabled(RST_T1, false);
        Rst_LL_SetTimerEnabled(RST_T1, true);

        Pclk_LL_SetTimerEnabled(PCLK_T1, true);
        break;
    }
    case OCU_MODULE_2: {
        Rst_LL_SetTimerEnabled(RST_T2, false);
        Rst_LL_SetTimerEnabled(RST_T2, true);

        Pclk_LL_SetTimerEnabled(PCLK_T2, true);
        break;
    }
    case OCU_MODULE_3: {
        Rst_LL_SetTimerEnabled(RST_T3, false);
        Rst_LL_SetTimerEnabled(RST_T3, true);

        Pclk_LL_SetTimerEnabled(PCLK_T3, true);
        break;
    }
    case OCU_MODULE_4: {
        Rst_LL_SetTimerEnabled(RST_T4, false);
        Rst_LL_SetTimerEnabled(RST_T4, true);

        Pclk_LL_SetTimerEnabled(PCLK_T4, true);
        break;
    }
    case OCU_MODULE_20: {
        Rst_LL_SetTimerEnabled(RST_T20, false);
        Rst_LL_SetTimerEnabled(RST_T20, true);

        Pclk_LL_SetTimerEnabled(PCLK_T20, true);
        break;
    }
    case OCU_MODULE_21: {
        Rst_LL_SetTimerEnabled(RST_T21, false);
        Rst_LL_SetTimerEnabled(RST_T21, true);

        Pclk_LL_SetTimerEnabled(PCLK_T21, true);
        break;
    }
    default: {
        KF_DEV_ASSERT(false);
    }
    break;
    }
}

/**
 * @brief set channel output type
 */
static FUNC(void, OCU_CODE) Ocu_Im_SetChannelOutPutType(
  VAR(uint8, OCU_VAR) Module, VAR(uint8, OCU_VAR) Channel, VAR(Ocu_PinActionType, OCU_VAR) PinActionType)
{
    switch (PinActionType)
    {
    case OCU_SET_HIGH:
        Ccp_LL_SetChannelMode(Ocu_CcpUnitPtr[Module], (Ccp_ChannelIndex_t)Channel, CCP_MODE_CMP_ACTIVE_LEVEL);
        break;
    case OCU_SET_LOW:
        Ccp_LL_SetChannelMode(Ocu_CcpUnitPtr[Module], (Ccp_ChannelIndex_t)Channel, CCP_MODE_CMP_INACTIVE_LEVEL);
        break;
    case OCU_TOGGLE:
        Ccp_LL_SetChannelMode(Ocu_CcpUnitPtr[Module], (Ccp_ChannelIndex_t)Channel, CCP_MODE_CMP_TOGGLE);
        break;
    case OCU_DISABLE:
        Ccp_LL_SetChannelMode(Ocu_CcpUnitPtr[Module], (Ccp_ChannelIndex_t)Channel, CCP_MODE_CLOSE);
        break;
    default:
        Ccp_LL_SetChannelMode(Ocu_CcpUnitPtr[Module], (Ccp_ChannelIndex_t)Channel, CCP_MODE_CLOSE);
        break;
    }
}

/**
 * @brief Initialize hardware unit configured
 *
 * @param HwUnitConfig Hardware configuration information of the Ocu channel
 * @param CommonDir Ocu Count direction
 */
FUNC(void, OCU_CODE)
Ocu_Im_InitModule(P2CONST(Ocu_ImConfigType, AUTOMATIC, OCU_APPL_CONST) HwUnitConfig,
                  VAR(Ocu_CountDirectionType, OCU_VAR) CommonDir)
{
    /* Reset Ocu module */
    Ocu_Im_UnitReset(HwUnitConfig->ModuleInstance);
    /* Set the Tx Counting direction */
    if (OCU_DOWN_COUNTING == CommonDir)
    {
        GPTimer_LL_SetCounterManner(Ocu_CcpUnitPtr[HwUnitConfig->ModuleInstance], TIM_MANNER_DOWN_FLAG);
    }
    else
    {
        GPTimer_LL_SetCounterManner(Ocu_CcpUnitPtr[HwUnitConfig->ModuleInstance], TIM_MANNER_UP_FLAG);
    }

    /* Set Tx Working in Counting Mode */
    GPTimer_LL_SetWorkingMode(Ocu_CcpUnitPtr[HwUnitConfig->ModuleInstance], TIMING_MODE);
    /* Set Tx Counter to 0 */
    GPTimer_LL_SetCounter(Ocu_CcpUnitPtr[HwUnitConfig->ModuleInstance], 0U);
    /* Set the free-running timer to Max Value */
    GPTimer_LL_SetPeriod(Ocu_CcpUnitPtr[HwUnitConfig->ModuleInstance], HwUnitConfig->MaxCounter);
    /* set timer prescaler value */
    GPTimer_LL_SetPrescaler(Ocu_CcpUnitPtr[HwUnitConfig->ModuleInstance], HwUnitConfig->Prescale - 1U);
    /* Configure working clock  */
    GPTimer_LL_SetClkSrc(Ocu_CcpUnitPtr[HwUnitConfig->ModuleInstance], (Timer_ClockSource_t)HwUnitConfig->ClockSource);
    /* Configuration update enable */
    GPTimer_LL_SetUpdateEnabled(Ocu_CcpUnitPtr[HwUnitConfig->ModuleInstance], (bool)TRUE);
}

/**
 * @brief Initialize channels configured
 *
 * @param Module Hardware unit
 * @param ChannelConfig Configuration information about each OCU channel
 */
FUNC(void, OCU_CODE)
Ocu_Im_InitChannel(VAR(uint8, OCU_VAR) Module, P2CONST(Ocu_ChannelConfigType, AUTOMATIC, OCU_APPL_CONST) ChannelConfig)
{
    /* Configure CCPx to compare mode, the output level is inverted during comparison match*/
    Ocu_Im_SetChannelOutPutType(Module, ChannelConfig->AssignedHwChannel, ChannelConfig->PinAction);
    /* Configure CCPx compare register */
    Ccp_LL_SetCompareResult(
      Ocu_CcpUnitPtr[Module], (Ccp_ChannelIndex_t)ChannelConfig->AssignedHwChannel, ChannelConfig->DefaultThreshold);
}

/**
 * @brief De-initialize hardware unit configured
 *
 * @param HwUnitConfig-Hardware configuration information of the Ocu channel
 */
FUNC(void, OCU_CODE) Ocu_Im_DeInitModule(P2CONST(Ocu_ImConfigType, AUTOMATIC, OCU_APPL_CONST) HwUnitConfig)
{
    /* Reset Ocu module */
    Ocu_Im_UnitReset(HwUnitConfig->ModuleInstance);
    /** @brief  Ocu_DeInit shall stop all free-running counters, which are exclusively used by this driver */
    GPTimer_LL_Stop(Ocu_CcpUnitPtr[HwUnitConfig->ModuleInstance]);
}

/**
 * @brief De-initialize channels configured
 *
 * @param Module Hardware unit
 * @param Channel channel index
 */
FUNC(void, OCU_CODE)
Ocu_Im_DeInitChannel(VAR(uint8, OCU_VAR) Module, VAR(uint8, OCU_VAR) Channel)
{
    /* Clear Intr Flag */
    Ccp_LL_ClearIntrFlag(Ocu_CcpUnitPtr[Module], (Ccp_IntIndex_t)Channel);
    /* Disable Intr */
    Ccp_LL_SetIntrEnabled(Ocu_CcpUnitPtr[Module], (Ccp_IntIndex_t)Channel, (bool)FALSE);
    /* close ccp mode*/
    Ocu_Im_SetChannelOutPutType(Module, Channel, OCU_DISABLE);
}

/**
 * @brief Enable/Disable the comparator channel interrupt function, call notification when flag is set
 *
 * @param Module Hardware unit
 * @param Channel channel index
 * @param Enabled State of channel interrupt to be setted
 */
FUNC(void, OCU_CODE)
Ocu_Im_SetChannelIntrEnabled(VAR(uint8, OCU_VAR) Module, VAR(uint8, OCU_VAR) Channel, VAR(boolean, OCU_VAR) Enabled)
{
    /* Set channel interrupt enabled flag */
    Ccp_LL_SetIntrEnabled(Ocu_CcpUnitPtr[Module], (Ccp_IntIndex_t)Channel, (TRUE == Enabled));
}

/**
 * @brief Start an Ocu channel
 *
 * @param Module Hardware unit
 * @param Channel channel index
 * @param PinAction Automatic action (by hardware) to be performed on a pin
 */
FUNC(void, OCU_CODE)
Ocu_Im_StartChannelProcess(
  VAR(uint8, OCU_VAR) Module, VAR(uint8, OCU_VAR) Channel, VAR(Ocu_PinStateType, OCU_VAR) PinAction)
{
    /* Configure CCPx to compare mode, the output level is inverted during comparison match */
    Ocu_Im_SetChannelOutPutType(Module, Channel, (Ocu_PinActionType)PinAction);
    /* Timer start control enable */
    GPTimer_LL_Start(Ocu_CcpUnitPtr[Module]);
}

/**
 * @brief Stop an Ocu channel
 *
 * @param Module Hardware unit
 * @param Channel channel index
 */
FUNC(void, OCU_CODE)
Ocu_Im_StopChannelProcess(VAR(uint8, OCU_VAR) Module, VAR(uint8, OCU_VAR) Channel)
{
    Ccp_LL_SetIntrEnabled(Ocu_CcpUnitPtr[Module], (Ccp_IntIndex_t)Channel, (bool)FALSE);

    /* Stop channel comparision */
    Ocu_Im_SetChannelOutPutType(Module, Channel, OCU_DISABLE);
}

/**
 * @brief Set immediately the level of the pin associated to an OCU channel
 *
 * @param Module Hardware unit
 * @param Channel channel index
 * @param PinState Output state of the pin
 */
FUNC(void, OCU_CODE)
Ocu_Im_SetPinOutPutState(VAR(uint8, OCU_VAR) Module, VAR(uint8, OCU_VAR) Channel,
                         VAR(Ocu_PinStateType, OCU_VAR) PinState)
{
    GPTimer_LL_Stop(Ocu_CcpUnitPtr[Module]);
    Ocu_Im_SetChannelOutPutType(Module, Channel, (Ocu_PinActionType)PinState);
    /* Timer start control enable */
    GPTimer_LL_Start(Ocu_CcpUnitPtr[Module]);

    /* pin level changed immediately */
    Ccp_LL_GenerateCapOrCmpEvent(Ocu_CcpUnitPtr[Module], (Ccp_ChannelIndex_t)Channel);
}

/**
 * @brief Indicate driver what shall be done automatically by hardware (if supported) upon compare match
 *
 * @param Module Hardware unit
 * @param Channel channel index
 * @param PinAction Automatic action (by hardware) to be performed on a pin
 */
FUNC(void, OCU_CODE)
Ocu_Im_SetPinAction(VAR(uint8, OCU_VAR) Module, VAR(uint8, OCU_VAR) Channel, VAR(uint8, OCU_VAR) PinAction)
{
    /* Operate register to set pin action */
    Ocu_Im_SetChannelOutPutType(Module, Channel, (Ocu_PinActionType)PinAction);
}

/**
 * @brief Read the current value of the counter
 *
 * @param Module Hardware unit
 * @retval Ocu_ValueType Current value of the counter
 */
FUNC(Ocu_ValueType, OCU_CODE) Ocu_Im_GetCounter(VAR(uint8, OCU_VAR) Module)
{
    /* Get counter from register */
    return GPTimer_LL_GetCounter(Ocu_CcpUnitPtr[Module]);
}

/**
 * @brief Set the value of the channel threshold
 *
 * @param Module Hardware unit
 * @param Channel channel index
 * @param Value Threshold to be setted
 */
FUNC(void, OCU_CODE)
Ocu_Im_SetChannelThreshold(VAR(uint8, OCU_VAR) Module, VAR(uint8, OCU_VAR) Channel, VAR(Ocu_ValueType, OCU_VAR) Value)
{
    Ccp_LL_SetCompareResult(Ocu_CcpUnitPtr[Module], (Ccp_ChannelIndex_t)Channel, Value);
}

/**
 * @brief Get interrupt flags of hardware unit
 *
 * @param Module Hardware unit
 * @retval uint32 Interrupt flags
 */
FUNC(uint32, OCU_CODE) Ocu_Im_GetAllIntrFlags(VAR(uint8, OCU_VAR) Module)
{
    return Ccp_LL_GetAllIntrFlag(Ocu_CcpUnitPtr[Module]);
}

/**
 * @brief Clear interrupt flags of hardware unit
 *
 * @param Module Hardware unit
 */
FUNC(void, OCU_CODE) Ocu_Im_ClearAllInterFlags(VAR(uint8, OCU_VAR) Module)
{
    Ccp_LL_ClearAllIntrFlag(Ocu_CcpUnitPtr[Module]);
}

/* EOF */
