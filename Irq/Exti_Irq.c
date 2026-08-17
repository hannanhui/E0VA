/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Eint_Irq.c
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
/* PRQA S 2071 EOF #KQR002071 */
/* PRQA S 3408 EOF #KQR003408 */
/* PRQA S 3383 EOF #KQR003383 */
/******************************************************************************
 **                        Include Files
 ******************************************************************************/
#include "Irq_Cfg.h"
#include "Dio_Exti.h"
#include "kf_types.h"
#include "kf32a158sf_drv_intr.h"
#include "kf32a158sf_drv_gpio.h"
#include "Mcal.h"
/******************************************************************************
 **                        File Version Check
 ******************************************************************************/

/******************************************************************************
 **                        Macro  Definitions
 ******************************************************************************/

/**
 * @brief PORTA Channel 0 Interrupt Request ID
 */
#define DIO_EXTI_CHANNEL_A_0 ((Dio_ChannelType)(0x00U))
/**
 * @brief PORTB Channel 0 Interrupt Request ID
 */
#define DIO_EXTI_CHANNEL_B_0 ((Dio_ChannelType)(0x10U))
/**
 * @brief PORTC Channel 0 Interrupt Request ID
 */
#define DIO_EXTI_CHANNEL_C_0 ((Dio_ChannelType)(0x20U))
/**
 * @brief PORTD Channel 0 Interrupt Request ID
 */
#define DIO_EXTI_CHANNEL_D_0 ((Dio_ChannelType)(0x30U))
/**
 * @brief PORTE Channel 0 Interrupt Request ID
 */
#define DIO_EXTI_CHANNEL_E_0 ((Dio_ChannelType)(0x40U))
/**
 * @brief PORTF Channel 0 Interrupt Request ID
 */
#define DIO_EXTI_CHANNEL_F_0 ((Dio_ChannelType)(0x50U))
/**
 * @brief PORTG Channel 0 Interrupt Request ID
 */
#define DIO_EXTI_CHANNEL_G_0 ((Dio_ChannelType)(0x60U))
/**
 * @brief PORTH Channel 0 Interrupt Request ID
 */
#define DIO_EXTI_CHANNEL_H_0 ((Dio_ChannelType)(0x70U))

typedef enum
{
    PORT_A_INDEX,
    PORT_B_INDEX,
    PORT_C_INDEX,
    PORT_D_INDEX,
    PORT_E_INDEX,
    PORT_F_INDEX,
    PORT_G_INDEX,
    PORT_H_INDEX,
} Port_IrqIndexType;
/******************************************************************************
 **                        Typedef  Definitions
 ******************************************************************************/
/**
 * @brief interrupt handle
 */
typedef void (*Port_IntrHandleFcnType)(uint8 ChannelId);
/******************************************************************************
 **                      Variables
 ******************************************************************************/
/**
 * @brief Port interrupt handle
 */
/*PRQA S 0686,0694 1 #KQR100015 */
static Port_IntrHandleFcnType PortIntrHandle[DIO_PORT_NUMBER] = {NULL_PTR};
/******************************************************************************
 **                        Export Variables
 ******************************************************************************/

/******************************************************************************
 **                        Export Functions
 ******************************************************************************/

/**
 * @brief port interrupt handle register
 *
 * @param PortIndex Port index
 * @param IrqHandle interrupt handle function
 */
/* PRQA S 1336 1 #KQR001336 */
void Port_RegisterCustomHandler(uint8 PortIndex, void (*IrqHandle)(uint8))
{
    PortIntrHandle[PortIndex] = (Port_IntrHandleFcnType)IrqHandle;
}

/**
 * @brief port interrupt handle
 *
 * @param PortIndex port index
 * @param ChannelId port channel
 */
static void Port_IntrHandleDistribution(uint8 PortIndex, uint8 ChannelId)
{
    if (PortIntrHandle[PortIndex] != NULL_PTR)
    {
        PortIntrHandle[PortIndex](ChannelId);
    }
    else
    {
        Dio_ExtiCallbackHandle(ChannelId);
    }
}

#if (PA_UNIFIED_INTERRUPT == STD_ON)
#if (IRQ_CAT_EINTA == IRQ_CAT1)
KF_INTERRUPT(PA)
#else
ISR(PA)
#endif
{
    for (uint32_t index_offset = 0U; index_offset < 16U; index_offset++)
    {
        /* Get the interrupt flag on EXTI */
        if (GpioExti_LL_GetIntrFlag(EXTIA_PTR, GPIO_PIN_INDEX_0 + index_offset) == true)
        {
            /* Clear the interrupt flag */
            GpioExti_LL_ClearIntrFlag(EXTIA_PTR, GPIO_PIN_INDEX_0 + index_offset);

            Port_IntrHandleDistribution(PORT_A_INDEX, (Dio_ChannelType)(DIO_EXTI_CHANNEL_A_0 + index_offset));
        }
    }
}
#endif

#if (PB_UNIFIED_INTERRUPT == STD_ON)
#if (IRQ_CAT_EINTB == IRQ_CAT1)
KF_INTERRUPT(PB)
#else
ISR(PB)
#endif
{
    for (uint32_t index_offset = 0U; index_offset < 16U; index_offset++)
    {
        /* Get the interrupt flag on EXTI */
        if (GpioExti_LL_GetIntrFlag(EXTIB_PTR, GPIO_PIN_INDEX_0 + index_offset) == true)
        {
            /* Clear the interrupt flag */
            GpioExti_LL_ClearIntrFlag(EXTIB_PTR, GPIO_PIN_INDEX_0 + index_offset);

            Port_IntrHandleDistribution(PORT_B_INDEX, (Dio_ChannelType)(DIO_EXTI_CHANNEL_B_0 + index_offset));
        }
    }
}
#endif

#if (PC_UNIFIED_INTERRUPT == STD_ON)
#if (IRQ_CAT_EINTC == IRQ_CAT1)
KF_INTERRUPT(PC)
#else
ISR(PC)
#endif
{
    for (uint32_t index_offset = 0U; index_offset < 16U; index_offset++)
    {
        /* Get the interrupt flag on EXTI */
        if (GpioExti_LL_GetIntrFlag(EXTIC_PTR, GPIO_PIN_INDEX_0 + index_offset) == true)
        {
            /* Clear the interrupt flag */
            GpioExti_LL_ClearIntrFlag(EXTIC_PTR, GPIO_PIN_INDEX_0 + index_offset);

            Port_IntrHandleDistribution(PORT_C_INDEX, (Dio_ChannelType)(DIO_EXTI_CHANNEL_C_0 + index_offset));
        }
    }
}
#endif

#if (PD_UNIFIED_INTERRUPT == STD_ON)
#if (IRQ_CAT_EINTD == IRQ_CAT1)
/* PRQA S 0602,2888 1 #KQR100017 */
KF_INTERRUPT(PD)
#else
ISR(PD)
#endif
{
    for (uint32_t index_offset = 0U; index_offset < 16U; index_offset++)
    {
        /* Get the interrupt flag on EXTI */
        /* PRQA S 4394 2 #KQR004394 */
        /* PRQA S 2985,2986 6 #KQR002985 */
        if (GpioExti_LL_GetIntrFlag(EXTID_PTR, (Gpio_PinIndex_t)((uint32_t)GPIO_PIN_INDEX_0 + index_offset)) == true)
        {
            /* Clear the interrupt flag */
            /* PRQA S 4394 1 #KQR004394 */
            GpioExti_LL_ClearIntrFlag(EXTID_PTR, (Gpio_PinIndex_t)((uint32_t)GPIO_PIN_INDEX_0 + index_offset));

            Port_IntrHandleDistribution(PORT_D_INDEX, (Dio_ChannelType)(DIO_EXTI_CHANNEL_D_0 + index_offset));
        }
    }
}
#endif

#if (PE_UNIFIED_INTERRUPT == STD_ON)
#if (IRQ_CAT_EINTE == IRQ_CAT1)
KF_INTERRUPT(PE)
#else
ISR(PE)
#endif
{
    for (uint32_t index_offset = 0U; index_offset < 16U; index_offset++)
    {
        /* Get the interrupt flag on EXTI */
        if (GpioExti_LL_GetIntrFlag(EXTIE_PTR, GPIO_PIN_INDEX_0 + index_offset) == true)
        {
            /* Clear the interrupt flag */
            GpioExti_LL_ClearIntrFlag(EXTIE_PTR, GPIO_PIN_INDEX_0 + index_offset);

            Port_IntrHandleDistribution(PORT_E_INDEX, (Dio_ChannelType)(DIO_EXTI_CHANNEL_E_0 + index_offset));
        }
    }
}
#endif

#if (PF_UNIFIED_INTERRUPT == STD_ON)
#if (IRQ_CAT_EINTF == IRQ_CAT1)
KF_INTERRUPT(PF)
#else
ISR(PF)
#endif
{
    for (uint32_t index_offset = 0U; index_offset < 16U; index_offset++)
    {
        /* Get the interrupt flag on EXTI */
        if (GpioExti_LL_GetIntrFlag(EXTIF_PTR, GPIO_PIN_INDEX_0 + index_offset) == true)
        {
            /* Clear the interrupt flag */
            GpioExti_LL_ClearIntrFlag(EXTIF_PTR, GPIO_PIN_INDEX_0 + index_offset);

            Port_IntrHandleDistribution(PORT_F_INDEX, (Dio_ChannelType)(DIO_EXTI_CHANNEL_F_0 + index_offset));
        }
    }
}
#endif

#if (PX_UNIFIED_INTERRUPT == STD_ON)
#if (IRQ_CAT_EINTX == IRQ_CAT1)
KF_INTERRUPT(PG_PH)
#else
ISR(PG_PH)
#endif
{
    for (uint32_t index_offset = 0U; index_offset < 16U; index_offset++)
    {
        /* Get the interrupt flag on EXTI */
        if (GpioExti_LL_GetIntrFlag(EXTIG_PTR, GPIO_PIN_INDEX_0 + index_offset) == true)
        {
            /* Clear the interrupt flag */
            GpioExti_LL_ClearIntrFlag(EXTIG_PTR, GPIO_PIN_INDEX_0 + index_offset);

            Port_IntrHandleDistribution(PORT_G_INDEX, (Dio_ChannelType)(DIO_EXTI_CHANNEL_G_0 + index_offset));
        }

        /* Get the interrupt flag on EXTI */
        if (GpioExti_LL_GetIntrFlag(EXTIH_PTR, GPIO_PIN_INDEX_0 + index_offset) == true)
        {
            /* Clear the interrupt flag */
            GpioExti_LL_ClearIntrFlag(EXTIH_PTR, GPIO_PIN_INDEX_0 + index_offset);

            Port_IntrHandleDistribution(PORT_H_INDEX, (Dio_ChannelType)(DIO_EXTI_CHANNEL_H_0 + index_offset));
        }
    }
}
#endif
