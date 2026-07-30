/**************************************************************************************************/
/**
 * @file     int_drv.c
 * @brief    interrupt driver source file.
 * @version  V1.1.1
 * @date     December-2022
 * @author   Zhixin Semiconductor
 *
 * @note
 * Copyright (C) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 * 
 **************************************************************************************************/

#include "int_drv.h"

/** @addtogroup  Z20K14XM_Peripheral_Driver
 *  @{
 */

/** @defgroup INT
 *  @brief Interrupt driver modules
 *  @{
 */

/** @defgroup INT_Private_Type
 *  @{
 */

/** @} end of group INT_Private_Type*/

/** @defgroup INT_Private_Defines
 *  @{
 */

/** @} end of group INT_Private_Defines */

/** @defgroup INT_Private_Variables
 *  @{
 */

/** @} end of group INT_Private_Variables */

/** @defgroup INT_Global_Variables
 *  @{
 */

/**
 *  @brief INT Register address array
 */

/*PRQA S 0306 ++*/
static Z20_SCBType *const SCBRegPtr = (Z20_SCBType *) Z20_SCB_BASE;
static Z20_SysTickType *const SysTickPtr = (Z20_SysTickType *) Z20_SYSTICK_BASE;
static Z20_NVICType *const NVICRegPtr = (Z20_NVICType *) Z20_NVIC_BASE;
/*PRQA S 0306 --*/

/** @} end of group INT_Global_Variables */

/** @defgroup INT_Private_FunctionDeclaration
 *  @{
 */


/** @} end of group INT_Private_FunctionDeclaration */

/** @defgroup INT_Private_Functions
 *  @{
 */

/** @} end of group INT_Private_Functions */

/** @defgroup INT_Public_Functions
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
void INT_EnableIRQ(IRQn_Type IRQn)
{
    if ((int32_t)(IRQn) >= 0)
    {
      NVICRegPtr->ISER[(((uint32_t)IRQn) >> 5U)] = \
        (uint32_t)(1UL << (((uint32_t)IRQn) & 0x1FU));
    }
}

/**
 * @brief     Get Interrupt Enable Status.
 * 
 * @param[in] IRQn: Interrupt number. The valid value is defined in enum IRQn_Type.
 *                  This function can only get the enable status of the interrupt whose IRQn >= 0;
 *                  Otherwise, this function takes no effect.
 * 
 * @return    intEnStatus: Interrupt enable status
 *           - 0:Interrupt is not enabled.
 *           - 1:Interrupt is enabled.
 *           
 */
uint32_t INT_GetEnableIRQ(IRQn_Type IRQn)
{
    uint32_t intEnStatus = 0U;

    if ((int32_t)(IRQn) >= 0)
    {
        intEnStatus = (uint32_t)(((NVICRegPtr->ISER[(((uint32_t)IRQn) \
            >> 5U)] & (1UL << (((uint32_t)IRQn) & 0x1FU))) != 0U) ? 1U : 0U);
    }

    return (intEnStatus);
}

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
void INT_DisableIRQ(IRQn_Type IRQn)
{
    if ((int32_t)(IRQn) >= 0)
    {
        NVICRegPtr->ICER[(((uint32_t)IRQn) >> 5U)] = \
            (uint32_t)(1UL << (((uint32_t)IRQn) & 0x1FU));
        COMMON_DSB();
        COMMON_ISB();
    }
}

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
uint32_t INT_GetPendingIRQ(IRQn_Type IRQn)
{
    uint32_t intPendingStatus = 0U;
    if ((int32_t)(IRQn) >= 0)
    {
        intPendingStatus = (uint32_t)(((NVICRegPtr->ISPR[(((uint32_t)IRQn) \
            >> 5U)] & (1UL << (((uint32_t)IRQn) & 0x1FU))) != 0UL) ? 1U : 0U);
    }
    return (intPendingStatus);
}

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
void INT_SetPendingIRQ(IRQn_Type IRQn)
{
    if ((int32_t)(IRQn) >= 0)
    {
        NVICRegPtr->ISPR[(((uint32_t)IRQn) >> 5U)] = \
            (uint32_t)(1UL << (((uint32_t)IRQn) & 0x1FU));
    }
}

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
void INT_ClearPendingIRQ(IRQn_Type IRQn)
{
    if ((int32_t)(IRQn) >= 0)
    {
        NVICRegPtr->ICPR[(((uint32_t)IRQn) >> 5U)] = \
            (uint32_t)(1UL << (((uint32_t)IRQn) & 0x1FU));
    }
}

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
uint32_t INT_GetActive(IRQn_Type IRQn)
{
    uint32_t activeStatus = 0U;

    if ((int32_t)(IRQn) >= 0)
    {
        activeStatus = (uint32_t)(((NVICRegPtr->IABR[(((uint32_t)IRQn) \
            >> 5U)] & (1UL << (((uint32_t)IRQn) & 0x1FU))) != 0U) ? 1U : 0U);
    }

    return (activeStatus);
}

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
void INT_SetPriority(IRQn_Type IRQn, uint32_t priority)
{
    if ((int32_t)(IRQn) >= 0)
    {
        NVICRegPtr->IP[((uint32_t)IRQn)] = (uint8_t)((priority << \
        (8U - INT_PRIO_BITS)) & (uint32_t)0xFFU);
    }
    else
    {
        /*PRQA S 2896 ++*/
        SCBRegPtr->SHP[(((uint32_t)IRQn) & 0xFU)-4U] = (uint8_t)((priority << \
        (8U - INT_PRIO_BITS)) & (uint32_t)0xFFU);
        /*PRQA S 2896 --*/
    }
}

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
uint32_t INT_GetPriority(IRQn_Type IRQn)
{
    uint32_t intNumber = 0U;

    if ((int32_t)(IRQn) >= 0)
    {
        intNumber = ((uint32_t)NVICRegPtr->IP[((uint32_t)IRQn)] \
             >> (8U - INT_PRIO_BITS));
    }
    else
    {
        /*PRQA S 2896 ++*/
        intNumber = ((uint32_t)SCBRegPtr->SHP[(((uint32_t)IRQn) \
            & 0xFU)-4U] >> (8U - INT_PRIO_BITS));
        /*PRQA S 2896 --*/
    }

    return (intNumber);
}

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
void INT_SetVector(IRQn_Type IRQn, uint32_t vector)
{  
    /*PRQA S 0306 ++*/
    uint32_t *vectors = (uint32_t *)SCBRegPtr->VTOR;
    /*PRQA S 0306 --*/

    vectors[(int32_t)IRQn + NVIC_DEVICE_IRQ_OFFSET] = vector;
}

/**
 * @brief        Get Interrupt Vector
 * 
 * @param[in]    IRQn: Interrupt number.
 * 
 * @return       Interrupt handler address.
 * 
 */
uint32_t INT_GetVector(IRQn_Type IRQn)
{
    /*PRQA S 0306 ++*/
    uint32_t *vectors = (uint32_t *)SCBRegPtr->VTOR;
    /*PRQA S 0306 --*/

    return vectors[(int32_t)IRQn + NVIC_DEVICE_IRQ_OFFSET];
}

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
uint32_t SysTick_Config(uint32_t ticks)
{
    uint32_t result = 0U;

    if ((ticks - 1U) > (0xFFFFFFU))
    {
        result = 1U;
    }
    else
    {
        /* Set reload register */
        SysTickPtr->LOAD  = (uint32_t)(ticks - 1U); 
        /* Set Priority */   
        INT_SetPriority(SysTick_IRQn, (1U << INT_PRIO_BITS) - 1U);
        /* Load Counter Value */
        SysTickPtr->VAL = 0U;  
        /* Enable SysTick IRQ and Start Timer */                                           
        SysTickPtr->CTRL = (1U << 2U) | (1U << 1U) | (1U);
    }

    return (result);
}

/** @} end of group INT_Public_Functions */

/** @} end of group INT */

/** @} end of group Z20K14XM_Peripheral_Driver */

