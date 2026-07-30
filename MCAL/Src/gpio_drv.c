/**************************************************************************************************/
/**
 * @file     gpio_drv.c
 * @brief    GPIO module driver file.
 * @version  V1.1.1
 * @date     December-2022
 * @author   Zhixin Semiconductor
 *
 * @note
 * Copyright (C) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 *
 **************************************************************************************************/

#include "gpio_drv.h"

/** @addtogroup  Z20K14XM_Peripheral_Driver
 *  @{
 */
/** @addtogroup  GPIO
 *  @brief GPIO driver modules
 *  @{
 */

/** @defgroup PORT_Private_Type
 *  @{
 */

/** @} end of group PORT_Private_Type */

/** @defgroup PORT_Private_Defines
 *  @{
 */
#define PORT_TOTAL_NUM                (5U)
#define PINS_TOTAL_NUM                (32U)
#define PORT_PCR_ALL_MASK             (0x9F8F873BU)         /*!< PCR register all functions */

/**
 * @brief The pos of slew rate in PCR registers
 */
#define PORT_SLEWRATE_SHIFT_BITS      (3U)

/**
 * @brief The pos of passive filter in PCR registers
 */
#define PORT_PASSIVEFILTER_SHIFT_BITS (4U)

/**
 * @brief The pos of open drain in PCR registers
 */
#define PORT_OPENDRAIN_SHIFT_BITS     (5U)

/**
 * @brief The pos of pin mux in PCR registers
 */
#define PORT_PINMUX_SHIFT_BITS        (8U)

/**
 * @brief The pos of pin interrupt in PCR registers
 */
#define PORT_PININT_SHIFT_BITS        (16U)

/**
 * @brief The pos of filter config in PCR registers
 */
#define PORT_FILTER_SHIFT_BITS        (24U)

/**
 * @brief The pos of filter enable in PCR registers
 */
#define PORT_FILTER_ENABLE_SHIFT_BITS (31U)

/**
 * @brief The mask of interrupt status flag in PCR registers
 */
#define PORT_ISF_MASK                 (0x00800000U)

/**
 * @brief The mask of pin mux in PCR registers
 */
#define PORT_PINMUX_MASK              (0x00000700U)

/**
 * @brief The mask of pin interrupt in PCR registers
 */
#define PORT_PININT_MASK              (0x000F0000U)

/**
 * @brief The mask of pin pull in PCR registers
 */
#define PORT_PULL_MASK                (0x00000003U)

/**
 * @brief The mask of pin slew rate in PCR registers
 */
#define PORT_SLEWRATE_MASK            (0x00000008U)

/**
 * @brief The mask of pin passive filter in PCR registers
 */
#define PORT_PASSIVEFILTER_MASK       (0x00000010U)

/**
 * @brief The mask of pin open drain in PCR registers
 */
#define PORT_OPENDRAIN_MASK           (0x00000020U)

/**
 * @brief The mask of lock in PCR registers
 */
#define PORT_LOCK_MASK                (0x00008000U)

/**
 * @brief The mask of pin filter in PCR registers
 */
#define PORT_FILTER_MASK              (0x1F000000U)

/**
 * @brief The mask of pin filter enable in PCR registers
 */
#define PORT_FILTER_ENABLE_MASK       (0x80000000U)

/**
 *  @brief Defines PORT init clear target bits mask and mask ISF bit in PCR registers
 */
#define PORT_CLEAR_TARGETBITS_MASK                                                                 \
    (~(PORT_PULL_MASK | PORT_SLEWRATE_MASK | PORT_OPENDRAIN_MASK | PORT_PASSIVEFILTER_MASK |       \
       PORT_FILTER_MASK | PORT_FILTER_ENABLE_MASK | PORT_ISF_MASK))

/**
 *  @brief Defines PORT clear pinmux bits mask and mask ISF bit in PCR registers
 */
#define PORT_CLEAR_PINMUX_MASK        (PORT_PINMUX_MASK | PORT_ISF_MASK)

/**
 *  @brief Defines PORT clear pinint bits mask and mask ISF bit in PCR registers
 */
#define PORT_CLEAR_PININT_MASK        (PORT_PININT_MASK | PORT_ISF_MASK)

/**
 *  @brief Defines PORT clear pull bits mask and mask ISF bit in PCR registers
 */
#define PORT_CLEAR_PULL_MASK          (PORT_PULL_MASK | PORT_ISF_MASK)

/**
 *  @brief Defines PORT clear slew rate bit mask and mask ISF bit in PCR registers
 */
#define PORT_CLEAR_SLEWRATE_MASK      (PORT_SLEWRATE_MASK | PORT_ISF_MASK)

/**
 *  @brief Defines PORT clear passive filter bit mask and mask ISF bit in PCR registers
 */
#define PORT_CLEAR_PASSIVEFILTER_MASK (PORT_PASSIVEFILTER_MASK | PORT_ISF_MASK)

/**
 *  @brief Defines PORT clear open drain bit mask and mask ISF bit in PCR registers
 */
#define PORT_CLEAR_OPENDRAIN_MASK     (PORT_OPENDRAIN_MASK | PORT_ISF_MASK)

/**
 *  @brief Defines PORT clear filter bits mask and mask ISF bit in PCR registers
 */
#define PORT_CLEAR_FILTER_MASK        (PORT_FILTER_MASK | PORT_ISF_MASK)

/**
 *  @brief Defines PORT clear filter enable bit mask and mask ISF bit in PCR registers
 */
#define PORT_CLEAR_FILTER_ENABLE_MASK (PORT_FILTER_ENABLE_MASK | PORT_ISF_MASK)

/** @} end of group PORT_Private_Defines */

/** @defgroup GPIO_Private_Defines
 *  @{
 */

#define GPIO_TOTAL_NUM                (5U)

#define GPIOA_BASE_ADDR               (GPIO_BASE_ADDR + 0x00UL)
#define GPIOB_BASE_ADDR               (GPIO_BASE_ADDR + 0x40UL)
#define GPIOC_BASE_ADDR               (GPIO_BASE_ADDR + 0x80UL)
#define GPIOD_BASE_ADDR               (GPIO_BASE_ADDR + 0xC0UL)
#define GPIOE_BASE_ADDR               (GPIO_BASE_ADDR + 0x100UL)

/** @} end of group GPIO_Private_Defines */


/** @defgroup PORT_Private_Variables
 *  @{
 */
/*PRQA S 0303 ++*/
static port_reg_t * const portRegPtr[PORT_TOTAL_NUM] =
{
    (port_reg_t *)PORTA_BASE_ADDR, /*!< Port A base address */
    (port_reg_t *)PORTB_BASE_ADDR, /*!< Port B base address */
    (port_reg_t *)PORTC_BASE_ADDR, /*!< Port C base address */
    (port_reg_t *)PORTD_BASE_ADDR, /*!< Port D base address */
    (port_reg_t *)PORTE_BASE_ADDR  /*!< Port E base address */
};

static port_reg_w_t * const portRegWPtr[PORT_TOTAL_NUM] =
{
    (port_reg_w_t *)PORTA_BASE_ADDR, /*!< Port A base address */
    (port_reg_w_t *)PORTB_BASE_ADDR, /*!< Port B base address */
    (port_reg_w_t *)PORTC_BASE_ADDR, /*!< Port C base address */
    (port_reg_w_t *)PORTD_BASE_ADDR, /*!< Port D base address */
    (port_reg_w_t *)PORTE_BASE_ADDR  /*!< Port E base address */
};

/*PRQA S 0303 --*/
/** @defgroup GPIO_Private_Variables
 *  @{
 */
/**
 *  @brief GPIOA GPIOB GPIOC GPIOD GPIOE address array
 */
/*PRQA S 0303 ++*/
static gpio_reg_t *const  gpioRegPtr[GPIO_TOTAL_NUM] =
{
    (gpio_reg_t *)GPIOA_BASE_ADDR,     /*!< GPIO A base address */
    (gpio_reg_t *)GPIOB_BASE_ADDR,     /*!< GPIO B base address */
    (gpio_reg_t *)GPIOC_BASE_ADDR,     /*!< GPIO C base address */
    (gpio_reg_t *)GPIOD_BASE_ADDR,     /*!< GPIO D base address */
    (gpio_reg_t *)GPIOE_BASE_ADDR      /*!< GPIO E base address */
};

static gpio_reg_w_t *const  gpioRegWPtr[GPIO_TOTAL_NUM] =
{
    (gpio_reg_w_t *)GPIOA_BASE_ADDR,     /*!< GPIO A base address */
    (gpio_reg_w_t *)GPIOB_BASE_ADDR,     /*!< GPIO B base address */
    (gpio_reg_w_t *)GPIOC_BASE_ADDR,     /*!< GPIO C base address */
    (gpio_reg_w_t *)GPIOD_BASE_ADDR,     /*!< GPIO D base address */
    (gpio_reg_w_t *)GPIOE_BASE_ADDR      /*!< GPIO E base address */
};
/*PRQA S 0303 --*/
/** @} end of group GPIO_Private_Variables */

/**
 *  @brief PORT ISR callback function pointer array
 */
static port_cb_t  portIsrCbFun = NULL;

/** @} end of group PORT_Private_Variables */

/** @defgroup PORT_Global_Variables
 *  @{
 */

/** @} end of group PORT_Global_Variables */

/** @defgroup PORT_Private_FunctionDeclaration
 *  @{
 */
static void PORT_IntHandler(PORT_Id_t portId);
void PORTA_DriverIRQHandler(void);
void PORTB_DriverIRQHandler(void);
void PORTC_DriverIRQHandler(void);
void PORTD_DriverIRQHandler(void);
void PORTE_DriverIRQHandler(void);

/** @} end of group PORT_Private_FunctionDeclaration */

/** @defgroup PORT_Private_Functions
 *  @{
 */
/**
 * @brief      PORT interrupt handle.
 *
 * @param[in]  none.
 * @return     none.
 *
 */
static void PORT_IntHandler(PORT_Id_t portId)
{
    uint32_t status;
    uint32_t gpioNum;
    port_reg_t * PORTx = (port_reg_t *)(portRegPtr[portId]);
    port_reg_w_t * PORTxw = (port_reg_w_t *)(portRegWPtr[portId]);
    status = PORTx->PORTx_IRQFLG.ISF;
    
    for(gpioNum = (uint32_t)GPIO_0; gpioNum < (uint32_t)PINS_TOTAL_NUM; gpioNum++)
    {
        if((status & (0x01UL<<gpioNum))!= 0U)
        {
            if(portIsrCbFun!= NULL)
            {
                portIsrCbFun(portId,(PORT_GpioNum_t)gpioNum);
            }
            else
            {
                PORTxw->PORTx_PCRn[gpioNum] = 0x5B000000U;
                PORTx->PORTx_PCRn[gpioNum].IRQC = 0U;
                PORTx->PORTx_PCRn[gpioNum].LK = 1U;
            }   
        } 
        PORTx->PORTx_IRQFLG.ISF = status & (0x01UL<<gpioNum); 
    }

    COMMON_DSB();
}

/**
 * @brief  PORTA interrupt function.
 *
 * @param  none.
 *
 * @return none.
 *
 * @note       The specific interrupt will be disabled if the corresponding interrupt callback is 
 *             not installed and an interrupt is raised. The rationale is focusing on the processing 
 *             efficiency mostly for the case that user might enable interrupts without processing 
 *             logic, in this case the CPU might also react to the interrupt.
 *             For the low power mode, especially for the wakeup source in the way of interrupt for 
 *             STOP, user must setup the callback.
 */
void PORTA_DriverIRQHandler(void)
{   
    PORT_IntHandler(PORT_A);
}

/**
 * @brief  PORTB interrupt function.
 *
 * @param  none.
 *
 * @return none.
 * 
 * @note       The specific interrupt will be disabled if the corresponding interrupt callback is 
 *             not installed and an interrupt is raised. The rationale is focusing on the processing 
 *             efficiency mostly for the case that user might enable interrupts without processing 
 *             logic, in this case the CPU might also react to the interrupt.
 *             For the low power mode, especially for the wakeup source in the way of interrupt for 
 *             STOP, user must setup the callback.
 */
void PORTB_DriverIRQHandler(void)
{   
    PORT_IntHandler(PORT_B);
}

/**
 * @brief  PORTC interrupt function.
 *
 * @param  none.
 *
 * @return none.
 *
 * @note       The specific interrupt will be disabled if the corresponding interrupt callback is 
 *             not installed and an interrupt is raised. The rationale is focusing on the processing 
 *             efficiency mostly for the case that user might enable interrupts without processing 
 *             logic, in this case the CPU might also react to the interrupt.
 *             For the low power mode, especially for the wakeup source in the way of interrupt for 
 *             STOP, user must setup the callback.
 */
void PORTC_DriverIRQHandler(void)
{   
    PORT_IntHandler(PORT_C);
}

/**
 * @brief  PORTD interrupt function.
 *
 * @param  none.
 *
 * @return none.
 *
 * @note       The specific interrupt will be disabled if the corresponding interrupt callback is 
 *             not installed and an interrupt is raised. The rationale is focusing on the processing 
 *             efficiency mostly for the case that user might enable interrupts without processing 
 *             logic, in this case the CPU might also react to the interrupt.
 *             For the low power mode, especially for the wakeup source in the way of interrupt for 
 *             STOP, user must setup the callback.
 */
void PORTD_DriverIRQHandler(void)
{
    PORT_IntHandler(PORT_D);
}

/**
 * @brief  PORTE interrupt function.
 *
 * @param  none.
 *
 * @return none.
 *
 * @note       The specific interrupt will be disabled if the corresponding interrupt callback is 
 *             not installed and an interrupt is raised. The rationale is focusing on the processing 
 *             efficiency mostly for the case that user might enable interrupts without processing 
 *             logic, in this case the CPU might also react to the interrupt.
 *             For the low power mode, especially for the wakeup source in the way of interrupt for 
 *             STOP, user must setup the callback.
 */
void PORTE_DriverIRQHandler(void)
{
    PORT_IntHandler(PORT_E);
}
/** @} end of group PORT_Private_Functions */


/** @defgroup PORT_Public_Functions
 *  @{
 */

/**
 * @brief       Configure pins with the same global configuration
 * If a pin is locked, global control will not work on it
 *
 * @param[in]  portId:        Select the PORT id,such as PORT_A,PORT_B,PORT_C,
 *                            PORT_D,PORT_E.
 * @param[in]   pins:        Select the GPIO pins.
 * @param[in]  value:        Set GPIO pin global value.
 *
 * @return none.
 *
 */
void PORT_GlobalPinsConfig(PORT_Id_t portId, uint32_t pins, uint32_t value)
{
    port_reg_w_t * PORTx = (port_reg_w_t *)(portRegWPtr[portId]);
    uint32_t mask = 0U;
    
    mask |= PORT_PCR_ALL_MASK;
    mask &= value;
    
    PORTx->PORTx_GLBDAT = mask;
    PORTx->PORTx_GLBCTL = pins;
}

/**
 * @brief       Initialize seleted pin with the given configuration structure.
 *
 * This function configures the pins with the options provided in the
 * provided structure.
 *
 * @param[in]  portId:     Select the PORT id,such as PORT_A,PORT_B,PORT_C,
 *                         PORT_D,PORT_E.
 * @param[in]  gpioNum:     Select the GPIO pin,such as GPIO_0~GPIO_31.
 * @param[in]  pinConfig:  Pin configuration struct.
 *
 * @return none.
 *
 */
void PORT_PinInit(PORT_Id_t portId, PORT_GpioNum_t gpioNum,
                  const PORT_PinConfig_t* pinConfig)
{
    uint32_t regVal;
    port_reg_t * PORTx = (port_reg_t *)(portRegPtr[portId]);
    port_reg_w_t * PORTxw = (port_reg_w_t *)(portRegWPtr[portId]);
    
    if(PORTx->PORTx_PCRn[gpioNum].LK == 1U)
    {
        PORTxw->PORTx_PCRn[gpioNum] = 0x5B000000U;
    }
    regVal  = (PORTxw->PORTx_PCRn[gpioNum] & PORT_CLEAR_TARGETBITS_MASK);
    regVal |= (uint32_t)(pinConfig->pullConfig);
    regVal |= ((uint32_t)(pinConfig->slewRateConfig) << PORT_SLEWRATE_SHIFT_BITS);
    regVal |= ((uint32_t)(pinConfig->passiveFilterConfig) << PORT_PASSIVEFILTER_SHIFT_BITS);
    regVal |= ((uint32_t)(pinConfig->openDrainConfig) << PORT_OPENDRAIN_SHIFT_BITS);
    regVal |= ((uint32_t)(pinConfig->filterConfig) << PORT_FILTER_SHIFT_BITS);
    regVal |= ((uint32_t)(pinConfig->filterEnable) << PORT_FILTER_ENABLE_SHIFT_BITS);
    /* Lock */
    PORTxw->PORTx_PCRn[gpioNum] = (regVal | PORT_LOCK_MASK);
}

/**
 * @brief       Configure the pin mux function
 *
 * This function configures the pin muxing.
 *
 * @param[in]  portId:      Select the PORT id,such as PORT_A,PORT_B,PORT_C
 *                          PORT_D,PORT_E.
 * @param[in]  gpioNum:      Select the GPIO pin,such as GPIO_0~GPIO_31.
 * @param[in]  pinMuxFunc:  Pin mux function.
 *
 * @return none.
 *
 */
void PORT_PinmuxConfig(PORT_Id_t portId, PORT_GpioNum_t gpioNum,
                       PORT_PinMuxFunc_t pinMuxFunc)
{
    uint32_t regVal;
    port_reg_t * PORTx = (port_reg_t *)(portRegPtr[portId]);
    port_reg_w_t * PORTxw = (port_reg_w_t *)(portRegWPtr[portId]);
    
    if(PORTx->PORTx_PCRn[gpioNum].LK == 1U)
    {
        PORTxw->PORTx_PCRn[gpioNum] = 0x5B000000U;
    }
    /* Mask target bits */
    regVal = (PORTxw->PORTx_PCRn[gpioNum] & (~PORT_CLEAR_PINMUX_MASK));
    /* Set pin mux */
    regVal |= ((uint32_t)pinMuxFunc << PORT_PINMUX_SHIFT_BITS);
    /* Lock */
    PORTxw->PORTx_PCRn[gpioNum] = (regVal | PORT_LOCK_MASK);
}

/**
 * @brief       Configure the pin interrupt configuration
 *
 * This function configures the pin interrupt.
 *
 * @param[in]  portId:     Select the PORT id,such as PORT_A,PORT_B,PORT_C
 *                         PORT_D,PORT_E.
 * @param[in]  gpioNum:     Select the GPIO pin,such as GPIO_0~GPIO_31.
 * @param[in]  intConfig:  Pin interrupt configuration.
 *                         - PORT_ISF_DISABLED(0)
 *                         - PORT_ISF_DMA_RISING_EDGE(1)
 *                         - PORT_ISF_DMA_FALLING_EDGE(2)
 *                         - PORT_ISF_DMA_BOTH_EDGE(3)
 *                         - PORT_ISF_INT_LOGIC_0(8)
 *                         - PORT_ISF_INT_RISING_EDGE(9)
 *                         - PORT_ISF_INT_FALLING_EDGE(10)
 *                         - PORT_ISF_INT_BOTH_EDGE(11)
 *                         - PORT_ISF_INT_LOGIC_1(12)
 *
 * @return none.
 *
 */
void PORT_PinIntConfig(PORT_Id_t portId, PORT_GpioNum_t gpioNum,
                       PORT_IntConfig_t intConfig)
{
    uint32_t regVal;
    port_reg_t * PORTx = (port_reg_t *)(portRegPtr[portId]);
    port_reg_w_t * PORTxw = (port_reg_w_t *)(portRegWPtr[portId]);
    
    if(PORTx->PORTx_PCRn[gpioNum].LK == 1U)
    {
        PORTxw->PORTx_PCRn[gpioNum] = 0x5B000000U;
    }
    /* Mask target bits */
    regVal = (PORTxw->PORTx_PCRn[gpioNum] & (~PORT_CLEAR_PININT_MASK));
    /* Set pin interrupt */
    regVal |= ((uint32_t)intConfig << PORT_PININT_SHIFT_BITS);
    /* Lock */
    PORTxw->PORTx_PCRn[gpioNum] = (regVal | PORT_LOCK_MASK);
}

/**
 * @brief       Configure the pin pull configuration.
 *
 * This function configures the pin interrupt.
 *
 * @param[in]  portId:      Select the PORT id,such as PORT_A,PORT_B,PORT_C,
 *                          PORT_D,PORT_E.
 * @param[in]  gpioNum:      Select the GPIO pin,such as GPIO_0~GPIO_31.
 * @param[in]  pullConfig:  Pin pull configuration, should be
 *                          PORT_PULL_NONE, PORT_PULL_DOWN and PORT_PULL_UP.
 *
 * @return none.
 *
 */
void PORT_PullConfig(PORT_Id_t portId, PORT_GpioNum_t gpioNum,
                     PORT_PullConfig_t pullConfig)
{
    uint32_t regVal;
    port_reg_t * PORTx = (port_reg_t *)(portRegPtr[portId]);
    port_reg_w_t * PORTxw = (port_reg_w_t *)(portRegWPtr[portId]);
    
    if(PORTx->PORTx_PCRn[gpioNum].LK == 1U)
    {
        PORTxw->PORTx_PCRn[gpioNum] = 0x5B000000U;
    }
    /* Mask target bits */
    regVal = (PORTxw->PORTx_PCRn[gpioNum] & (~PORT_CLEAR_PULL_MASK));
    /* Set pin pull */
    regVal |= (uint32_t)pullConfig;
    /* Lock */
    PORTxw->PORTx_PCRn[gpioNum] = (regVal | PORT_LOCK_MASK);
}

/**
 * @brief       Configure the pin slew rate configuration.
 *
 * This function configures the pin slew rate.
 *
 * @param[in]  portId:      Select the PORT id,such as PORT_A,PORT_B,PORT_C,
 *                          PORT_D,PORT_E.
 * @param[in]  gpioNum:      Select the GPIO pin,such as GPIO_0~GPIO_31.
 * @param[in]  slewRateConfig:  Pin slew rate configuration, should be
 *                          PORT_FAST_RATE and PORT_SLOW_RATE.
 *
 * @return none.
 *
 */
void PORT_SlewRateConfig(PORT_Id_t portId, PORT_GpioNum_t gpioNum,
                         PORT_SlewRate_t slewRateConfig)
{
    uint32_t regVal;
    port_reg_t * PORTx = (port_reg_t *)(portRegPtr[portId]);
    port_reg_w_t * PORTxw = (port_reg_w_t *)(portRegWPtr[portId]);
    
    if(PORTx->PORTx_PCRn[gpioNum].LK == 1U)
    {
        PORTxw->PORTx_PCRn[gpioNum] = 0x5B000000U;
    }
    /* Mask target bits */
    regVal = (PORTxw->PORTx_PCRn[gpioNum] & (~PORT_CLEAR_SLEWRATE_MASK));
    /* Set pin slew rate */
    regVal |= ((uint32_t)slewRateConfig << PORT_SLEWRATE_SHIFT_BITS);
    /* Lock */
    PORTxw->PORTx_PCRn[gpioNum] = (regVal | PORT_LOCK_MASK);
}

/**
 * @brief       Configure the pin passive filter configuration.
 *
 * This function configures the pin passive filter.
 *
 * @param[in]  portId:      Select the PORT id,such as PORT_A,PORT_B,PORT_C,
 *                          PORT_D,PORT_E.
 * @param[in]  gpioNum:      Select the GPIO pin,such as GPIO_0~GPIO_31.
 * @param[in]  passiveFilterConfig:  Pin passive filter configuration, should be
 *                          DISABLE and ENABLE.
 *
 * @return none.
 *
 */
void PORT_PassiveFilterConfig(PORT_Id_t portId, PORT_GpioNum_t gpioNum,
                              ControlState_t passiveFilterConfig)
{
    uint32_t regVal;
    port_reg_t * PORTx = (port_reg_t *)(portRegPtr[portId]);
    port_reg_w_t * PORTxw = (port_reg_w_t *)(portRegWPtr[portId]);
    
    if(PORTx->PORTx_PCRn[gpioNum].LK == 1U)
    {
        PORTxw->PORTx_PCRn[gpioNum] = 0x5B000000U;
    }
    /* Mask target bits */
    regVal = (PORTxw->PORTx_PCRn[gpioNum] & (~PORT_CLEAR_PASSIVEFILTER_MASK));
    /* Set pin passive filter */
    regVal |= ((uint32_t)passiveFilterConfig << PORT_PASSIVEFILTER_SHIFT_BITS);
    /* Lock */
    PORTxw->PORTx_PCRn[gpioNum] = (regVal | PORT_LOCK_MASK);
}

/**
 * @brief       Configure the pin open drain configuration.
 *
 * This function configures the pin open drain.
 *
 * @param[in]  portId:      Select the PORT id,such as PORT_A,PORT_B,PORT_C,
 *                          PORT_D,PORT_E.
 * @param[in]  gpioNum:      Select the GPIO pin,such as GPIO_0~GPIO_31.
 * @param[in]  openDrainConfig:  Pin open drain configuration, should be
 *                          DISABLE and ENABLE.
 *
 * @return none.
 *
 */
void PORT_OpenDrainConfig(PORT_Id_t portId, PORT_GpioNum_t gpioNum,
                          ControlState_t openDrainConfig)
{
    uint32_t regVal;
    port_reg_t * PORTx = (port_reg_t *)(portRegPtr[portId]);
    port_reg_w_t * PORTxw = (port_reg_w_t *)(portRegWPtr[portId]);
    
    if(PORTx->PORTx_PCRn[gpioNum].LK == 1U)
    {
        PORTxw->PORTx_PCRn[gpioNum] = 0x5B000000U;
    }
    /* Mask target bits */
    regVal = (PORTxw->PORTx_PCRn[gpioNum] & (~PORT_CLEAR_OPENDRAIN_MASK));
    /* Set pin open drain */
    regVal |= ((uint32_t)openDrainConfig << PORT_OPENDRAIN_SHIFT_BITS);
    /* Lock */
    PORTxw->PORTx_PCRn[gpioNum] = (regVal | PORT_LOCK_MASK);
}

/**
 * @brief       Configure the pin filter configuration.
 *
 * This function configures the pin filter.
 *
 * @param[in]  portId:      Select the PORT id,such as PORT_A,PORT_B,PORT_C,
 *                          PORT_D,PORT_E.
 * @param[in]  gpioNum:      Select the GPIO pin,such as GPIO_0~GPIO_31.
 * @param[in]  filterConfig:  pin filter configuration, the value is 0x0 - 0x1F.
 *
 * @return none.
 *
 */
void PORT_FilterConfig(PORT_Id_t portId, PORT_GpioNum_t gpioNum,
                       uint8_t filterConfig)
{
    uint32_t regVal;
    port_reg_t * PORTx = (port_reg_t *)(portRegPtr[portId]);
    port_reg_w_t * PORTxw = (port_reg_w_t *)(portRegWPtr[portId]);
    
    if(PORTx->PORTx_PCRn[gpioNum].LK == 1U)
    {
        PORTxw->PORTx_PCRn[gpioNum] = 0x5B000000U;
    }
    /* Mask target bits */
    regVal = (PORTxw->PORTx_PCRn[gpioNum] & (~PORT_CLEAR_FILTER_MASK));
    /* Set pin filter */
    regVal |= ((uint32_t)filterConfig << PORT_FILTER_SHIFT_BITS);
    /* Lock */
    PORTxw->PORTx_PCRn[gpioNum] = (regVal | PORT_LOCK_MASK);
}

/**
 * @brief       Enable/Disable the pin filter .
 *
 * This function enables/disables the pin filter.
 *
 * @param[in]  portId:      Select the PORT id,such as PORT_A,PORT_B,PORT_C,
 *                          PORT_D,PORT_E.
 * @param[in]  gpioNum:      Select the GPIO pin,such as GPIO_0~GPIO_31.
 * @param[in]  filterEnable:  pin filter configuration, 
                             should be DISABLE or ENABLE.
 *
 * @return none.
 *
 */
void PORT_FilterCmd(PORT_Id_t portId, PORT_GpioNum_t gpioNum,
                       ControlState_t filterEnable)
{
    uint32_t regVal;
    port_reg_t * PORTx = (port_reg_t *)(portRegPtr[portId]);
    port_reg_w_t * PORTxw = (port_reg_w_t *)(portRegWPtr[portId]);
    
    if(PORTx->PORTx_PCRn[gpioNum].LK == 1U)
    {
        PORTxw->PORTx_PCRn[gpioNum] = 0x5B000000U;
    }
    /* Mask target bits */
    regVal = (PORTxw->PORTx_PCRn[gpioNum] & (~PORT_CLEAR_FILTER_ENABLE_MASK));
    /* Set pin filter enable*/
    regVal |= ((uint32_t)filterEnable << PORT_FILTER_ENABLE_SHIFT_BITS);
    /* Lock */
    PORTxw->PORTx_PCRn[gpioNum] = (regVal | PORT_LOCK_MASK);
}

/**
 * @brief       Get pin interrupt status function
 *
 * This function gets the pin interrupt status.
 *
 * @param[in]  portId:      Select the PORT id,such as PORT_A,PORT_B,PORT_C,
 *                          PORT_D,PORT_E.
 * @param[in]  gpioNum:      Select the GPIO pin,such as GPIO_0~GPIO_31.
 *
 * @return     Interrupt status of a pin.
 *
 */
FlagStatus_t PORT_GetIntStatus(PORT_Id_t portId, PORT_GpioNum_t gpioNum)
{
    port_reg_t * PORTx = (port_reg_t *)(portRegPtr[portId]);
    
    return ((FlagStatus_t)PORTx->PORTx_PCRn[gpioNum].ISF);
}

/**
 * @brief       Get all pins interrupt status of a Port.
 *
 * This function gets all pins interrupt status.
 *
 * @param[in]  portId:     Select the PORT id,such as PORT_A,PORT_B,PORT_C,
 *                         PORT_D,PORT_E.
 *
 * @return     All Pins interrupt status of a Port.
 *
 */
uint32_t PORT_GetIntStatusAll(PORT_Id_t portId)
{
    port_reg_w_t * PORTx = (port_reg_w_t *)(portRegWPtr[portId]);
    
    return ((uint32_t)PORTx->PORTx_IRQFLG);
}

/**
 * @brief       Clear the pin interrupt status function.
 *
 * This function clears interrupt status of a pin.
 *
 * @param[in]  portId:     Select pin PORT ID: PORT_A, PORT_B, PORT_C,
 *                         PORT_D, PORT_E.
 * @param[in]  gpioNum:     Select the GPIO pin,such as GPIO_0~GPIO_31.
 *
 * @return     none.
 *
 */
void PORT_ClearPinInt(PORT_Id_t portId, PORT_GpioNum_t gpioNum)
{
    port_reg_t * PORTx = (port_reg_t *)(portRegPtr[portId]);
    port_reg_w_t * PORTxw = (port_reg_w_t *)(portRegWPtr[portId]);
    
    if(PORTx->PORTx_PCRn[gpioNum].LK == 1U)
    {
        PORTxw->PORTx_PCRn[gpioNum] = 0x5B000000U;
    }
    PORTx->PORTx_PCRn[gpioNum].ISF = 0x01U;
    PORTx->PORTx_PCRn[gpioNum].LK = 1U;
}

/**
 * @brief     Clear  All Pins Interrupt  Status Function
 *
 * @param[in]  portId:     Select pin PORT ID: PORT_A, PORT_B, PORT_C,
 *                         PORT_D, PORT_E.
 * @param[in]  clrPins:    Select pins no, a bit is a pin, bit0-gpio0,...
 *
 * @return     none.
 *
 */
void PORT_ClearPinsInt(PORT_Id_t portId, uint32_t clrPins)
{
    port_reg_w_t * PORTxw = (port_reg_w_t *)(portRegWPtr[portId]);

    PORTxw->PORTx_IRQFLG = clrPins;
}

/**
 * @brief      Port install call back function
 *
 * @param[in]  cbFun: pointer to callback function.
 *
 * @return none
 *
 */
void PORT_InstallCallbackFunc(port_cb_t cbFun)
{
    portIsrCbFun = cbFun;
}

/** @} end of group PORT_Public_Functions */

/** @defgroup GPIO_Public_Functions
 *  @{
 */

/**
 * @brief       Set the pin direction configuration.
 *
 * This function sets the pin direction.
 *
 * @param[in]    port:   Select pin PORT ID: PORT_A, PORT_B, PORT_C,
 *                         PORT_D, PORT_E.
 * @param[in]  gpioNum:   Select the GPIO pin,such as GPIO_0~GPIO_31.
 * @param[in]     dir:   Select  I/O direction of a pin.
 *                       - 0: corresponding pin is set to input
 *                       - 1: corresponding pin is set to output
 *
 * @return none.
 *
 */
void GPIO_SetPinDir(PORT_Id_t port, PORT_GpioNum_t gpioNum, GPIO_Dir_t dir)
{
    gpio_reg_w_t * GPIOx = (gpio_reg_w_t *)(gpioRegWPtr[port]);

    uint32_t pinDir = GPIOx->GPIOx_PDDR;
    pinDir &= (~(0x01UL << (uint32_t)gpioNum));
    pinDir |= ((uint32_t)dir << (uint32_t)gpioNum);
    GPIOx->GPIOx_PDDR = pinDir;
}

/**
 * @brief       Set the direction configuration for all pins.
 *
 * This function sets the pin directions.
 *
 * @param[in]        port:   Select pin PORT ID: PORT_A, PORT_B, PORT_C,
 *                           PORT_D, PORT_E.
 * @param[in]     dataDir:   Select I/O directions.
 *                           - 0: corresponding pin is set to input
 *                           - 1: corresponding pin is set to output
 *
 * @return none.
 *
 */
void GPIO_SetPinsDir(PORT_Id_t port, uint32_t dataDir)
{
    gpio_reg_w_t * GPIOx = (gpio_reg_w_t *)(gpioRegWPtr[port]);

    GPIOx->GPIOx_PDDR = dataDir;
}

/**
 * @brief        Write a pin with a given value.
 *
 * This function writes a pin with a given value.
 *
 * @param[in]    port:   Select pin PORT ID: PORT_A, PORT_B, PORT_C,
 *                       PORT_D, PORT_E.
 * @param[in]  gpioNum:   Select the GPIO pin,such as GPIO_0~GPIO_31.
 * @param[in]     val:   Pin value.
 *                    - 0: corresponding pin is set to LOW
 *                    - 1: corresponding pin is set to HIGH
 *
 * @return none.
 *
 */
void GPIO_WritePinOutput(PORT_Id_t port, PORT_GpioNum_t gpioNum, GPIO_Level_t val)
{
    gpio_reg_w_t * GPIOx = (gpio_reg_w_t *)(gpioRegWPtr[port]);
    
    if(GPIO_LOW == val)
    {
        GPIOx->GPIOx_PCOR = (0x01UL << (uint32_t)gpioNum);
    }
    else
    {
        GPIOx->GPIOx_PSOR = (0x01UL << (uint32_t)gpioNum);
    }
}

/**
 * @brief        Write  pins  with the given value.
 *
 * This function writes pins with the given value.
 *
 * @param[in]    port:   Select pin PORT ID: PORT_A, PORT_B, PORT_C,
 *                       PORT_D, PORT_E.
 * @param[in]     val:   Pin value.
 *                    - 0: corresponding pin is set to LOW
 *                    - 1: corresponding pin is set to HIGH
 *
 * @return none.
 *
 */
void GPIO_WritePinsOutput(PORT_Id_t port, uint32_t val)
{
    gpio_reg_w_t * GPIOx = (gpio_reg_w_t *)(gpioRegWPtr[port]);

    GPIOx->GPIOx_PDOR = val;
}

/**
 * @brief        Write a pin to 'Clear' value.
 *
 * This function writes a pin to 'Clear' value.
 *
 * @param[in]    port:   Select pin PORT ID: PORT_A, PORT_B, PORT_C,
 *                       PORT_D, PORT_E.
 * @param[in]  gpioNum:   Select the GPIO pin,such as GPIO_0~GPIO_31.
 *
 * @return none.
 *
 */
void GPIO_ClearPinOutput(PORT_Id_t port, PORT_GpioNum_t gpioNum)
{
    gpio_reg_w_t * GPIOx = (gpio_reg_w_t *)(gpioRegWPtr[port]);

    GPIOx->GPIOx_PCOR = (0x01UL << (uint32_t)gpioNum);
}

/**
 * @brief        Write pins to 'Clear' value
 *
 * This function writes pins to 'Clear' value.
 *
 * @param[in]    port:   Select pin PORT ID: PORT_A, PORT_B, PORT_C,
 *                       PORT_D, PORT_E.
 * @param[in]    pins:   Clean the GPIO pins.
 *
 * @return none.
 *
 */
void GPIO_ClearPinsOutput(PORT_Id_t port, uint32_t pins)
{
    gpio_reg_t * GPIOx = (gpio_reg_t *)(gpioRegPtr[port]);

    GPIOx->GPIOx_PCOR.PCO = pins;
}

/**
 * @brief        Write a pin with 'Set' value.
 *
 * This function writes a pin with 'Set' value.
 *
 * @param[in]    port:   Select pin PORT ID: PORT_A, PORT_B, PORT_C,
 *                       PORT_D, PORT_E.
 * @param[in]  gpioNum:   Select the GPIO pin,such as GPIO_0~GPIO_31.
 *
 * @return none.
 *
 */
void GPIO_SetPinOutput(PORT_Id_t port, PORT_GpioNum_t gpioNum)
{
    gpio_reg_w_t * GPIOx = (gpio_reg_w_t *)(gpioRegWPtr[port]);

    GPIOx->GPIOx_PSOR = (0x01UL << (uint32_t)gpioNum);
}

/**
 * @brief        Write  pins with 'Set' value.
 *
 * This function writes pins with 'Set' value.
 *
 * @param[in]    port:   Select pin PORT ID: PORT_A, PORT_B, PORT_C,
 *                       PORT_D, PORT_E.
 * @param[in]    pins:   Set the GPIO pins.
 *
 * @return none.
 *
 */
void GPIO_SetPinsOutput(PORT_Id_t port, uint32_t pins)
{
    gpio_reg_w_t * GPIOx = (gpio_reg_w_t *)(gpioRegWPtr[port]);

    GPIOx->GPIOx_PSOR = pins;
}

/**
 * @brief        Toggle a pin value.
 *
 * This function toggles a pin with 'Set' value.
 *
 * @param[in]      port:   Select pin PORT ID: PORT_A, PORT_B, PORT_C,
 *                         PORT_D, PORT_E.
 * @param[in]    gpioNum:   Select the GPIO pin,such as GPIO_0~GPIO_31.
 *
 * @return none.
 *
 */
void GPIO_TogglePinOutput(PORT_Id_t port, PORT_GpioNum_t gpioNum)
{
    gpio_reg_w_t * GPIOx = (gpio_reg_w_t *)(gpioRegWPtr[port]);

    GPIOx->GPIOx_PTOR = (0x01UL << (uint32_t)gpioNum);
}

/**
 * @brief        Toggle pins value.
 *
 * This function toggles pins with 'Set' value.
 *
 * @param[in]    port:   Select pin PORT ID: PORT_A, PORT_B, PORT_C,
 *                       PORT_D, PORT_E.
 * @param[in]    pins:   Toggle the GPIO pins.
 *
 * @return none.
 *
 */
void GPIO_TogglePinsOutput(PORT_Id_t port, uint32_t pins)
{
    gpio_reg_w_t * GPIOx = (gpio_reg_w_t *)(gpioRegWPtr[port]);

    GPIOx->GPIOx_PTOR = pins;
}

/**
 * @brief        Read a pin value.
 *
 * This function reads a pin value.
 *
 * @param[in]      port:   Select pin PORT ID: PORT_A, PORT_B, PORT_C,
 *                         PORT_D, PORT_E.
 * @param[in]    gpioNum:   Select the GPIO pin,such as GPIO_0~GPIO_31.
 *
 * @return       GPIO_HIGH or GPIO_LOW.
 *
 */
GPIO_Level_t GPIO_ReadPinLevel(PORT_Id_t port, PORT_GpioNum_t gpioNum)
{
    gpio_reg_w_t * GPIOx = (gpio_reg_w_t *)(gpioRegWPtr[port]);

    uint32_t pinLevel = GPIOx->GPIOx_PDIR;
    pinLevel &= (0x01UL << (uint32_t)gpioNum);
    return ((pinLevel!=0U) ? GPIO_HIGH : GPIO_LOW);
}

/**
 * @brief        Read  pins value.
 *
 * This function reads pins value.
 *
 * @param[in]      port:   Select pin PORT ID: PORT_A, PORT_B, PORT_C,
 *                         PORT_D, PORT_E.
 *
 * @return        Pins value.
 *
 */
uint32_t GPIO_ReadPinsLevel(PORT_Id_t port)
{
    gpio_reg_t * GPIOx = (gpio_reg_t *)(gpioRegPtr[port]);

    return GPIOx->GPIOx_PDIR.PDI;
}

/** @} end of group GPIO_Public_Functions */

/** @} end of group  GPIO  */

/** @} end of group Z20K14XM_Peripheral_Driver */
