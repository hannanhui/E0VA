/**************************************************************************************************/
/**
 * @file     int_drv.h
 * @brief    interrupt driver header file.
 * @version  V1.1.1
 * @date     December-2022
 * @author   Zhixin Semiconductor
 *
 * @note
 * Copyright (C) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 * 
 **************************************************************************************************/
#ifndef INT_DRV_H
#define INT_DRV_H

#include "common_drv.h"

/** @addtogroup  Z20K14XM_Peripheral_Driver
 *  @{
 */

/** @addtogroup  INT
 *  @{
 */

/** @defgroup INT_Public_Types 
 *  @{
 */

#define NVIC_DEVICE_IRQ_OFFSET          16

/** @} end of group INT_Public_Types */

/** @defgroup SYSCTRL_Public_Constants
 *  @{
 */

/** @} end of group SYSCTRL_Public_Constants */

/** @defgroup SYSCTRL_Public_Macro
 *  @{
 */

/** @} end of group SYSCTRL_Public_Macro */

/** @defgroup INT_Public_FunctionDeclaration
 *  @brief INT functions declaration
 *  @{
 */

/**
 * @brief     Enable Interrupt.
 * 
 * @param[in] IRQn: Interrupt number. The valid value is defined in enum IRQn_Type.
 *                  This function can only enable the interrupt whose IRQn >= 0;
 *                  Otherwise, this function takes no effect.
 * 
 * @return    None.
 * 
 */
void INT_EnableIRQ(IRQn_Type IRQn);

/**
 * @brief     Get Interrupt Enable Status.
 * 
 * @param[in] IRQn: Interrupt number. The valid value is defined in enum IRQn_Type.
 *                  This function can only get the status of the interrupt whose IRQn >= 0;
 *                  Otherwise, this function takes no effect.
 * 
 * @return    intEnStatus: Interrupt enable status
 *           - 0:Interrupt is not enabled.
 *           - 1:Interrupt is enabled.
 *           
 */
uint32_t INT_GetEnableIRQ(IRQn_Type IRQn);

/**
 * @brief     Disable Interrupt.
 * 
 * @param[in] IRQn: Interrupt number. The valid value is defined in enum IRQn_Type.
 *                  This function can only disable the interrupt whose IRQn >= 0;
 *                  Otherwise, this function takes no effect.
 * 
 * @return    None.
 * 
 */
void INT_DisableIRQ(IRQn_Type IRQn);

/**
 * @brief      Get Interrupt Pending Status.
 * 
 * @param[in]  IRQn: Interrupt number. The valid value is defined in enum IRQn_Type.
 *                   This function can only get the pending status of the interrupt whose IRQn >= 0;
 *                   Otherwise, this function takes no effect.
 * 
 * @return     intPendingStatus: Interrupt pending status
 *            - 0  Interrupt status is not pending.
 *            - 1  Interrupt status is pending.
 * 
 */
uint32_t INT_GetPendingIRQ(IRQn_Type IRQn);

/**
 * @brief     Set Interrupt To Pending.
 * 
 * @param[in] IRQn: Interrupt number. The valid value is defined in enum IRQn_Type.
 *                  This function can only set pending with the interrupt whose IRQn >= 0;
 *                  Otherwise, this function takes no effect.
 * 
 * @return    None.
 * 
 */
void INT_SetPendingIRQ(IRQn_Type IRQn);


/**
 * @brief     Clear Interrupt Pending Status
 * 
 * @param[in] IRQn: Interrupt number. The valid value is defined in enum IRQn_Type.
 *                  This function can only unset pending with the interrupt whose IRQn >= 0;
 *                  Otherwise, this function takes no effect.
 * 
 * @note      None
 * 
 */
void INT_ClearPendingIRQ(IRQn_Type IRQn);

/**
 * @brief     Get Interrupt Active Status
 * 
 * @param[in] IRQn: Interrupt number. The valid value is defined in enum IRQn_Type.
 *                  This function can only get active status of interrupt whose IRQn >= 0;
 *                  Otherwise, this function takes no effect.
 * 
 * @retunr    Interrupt active status
 *           - 0  Interrupt status is not active.
 *           - 1  Interrupt status is active.
 * 
 */
uint32_t INT_GetActive(IRQn_Type IRQn);

/**
 * @brief       Set Interrupt Priority
 * 
 * @param[in]  IRQn: Interrupt number.
 * @param[in]  priority: Priority level.
 *                       For IRQn>=0 the priority value range should be within 0-15. 
 *                       For IRQn<0, only system handler
 *                       MemManageFault/BusFault/UsageFault/SVCall/DebugMonitor/PendSV/SysTick
 *                       can be set.
 * 
 * @return      None
 * 
 */
void INT_SetPriority(IRQn_Type IRQn, uint32_t priority);

/**
 * @brief      Get Interrupt Priority
 * 
 * @param[in] IRQn: Interrupt number.
 * 
 * @return     uint32_t: Interrupt priority value, the value is valid only for IRQn>=0.
 *                       For IRQn<0, only system handler MemManageFault/BusFault/UsageFault
 *                       /SVCall/DebugMonitor/PendSV/SysTick can be get.
 * 
 */
uint32_t INT_GetPriority(IRQn_Type IRQn);

/**
 * @brief        Set Interrupt Vector
 * 
 * @param[in]    IRQn: Interrupt number
 * @param[in]    vector: Interrupt handler address
 * 
 * @return       None
 * 
 * @note         Interrupt VTOR must been relocated to SRAM before.
 *               If VTOR is not present address 0 must be mapped to SRAM.
 * 
 */
void INT_SetVector(IRQn_Type IRQn, uint32_t vector);

/**
 * @brief        Get Interrupt Vector
 * 
 * @param[in]    IRQn: Interrupt number.
 * 
 * @return       Interrupt handler address.
 * 
 */
uint32_t INT_GetVector(IRQn_Type IRQn);

/**
 * @brief       SYSTICK config and enable
 * 
 * @param[in]   ticks: Tick value that to be set.
 *                     The Ticks value range is 1U to 0x1000000U.
 * 
 * @return      uint32_t: Status of config system tick.
 *              0U: SysTick configure failed.
 *              1U: SysTick configure successful.
 * 
 * @note        Initializes the System Timer and its interrupt, and starts the System Tick Timer.
 *              Counter is in free running mode to generate periodic interrupts.
 *              The reload value is equal to the set tick value minus one. When the ticks value is 1
 *              the reload value is 0. It has the effect of disabling the SysTick counter on the next
 *              wrap.
 * 
 */
uint32_t SysTick_Config(uint32_t ticks);

/** @} end of group INT_Public_FunctionDeclaration */

/** @} end of group INT  */

/** @} end of group Z20K14XM_Peripheral_Driver */

#endif /* INT_DRV_H */
