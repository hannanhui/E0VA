/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Spi_Irq.c
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
#include "Irq_Cfg.h"
#include "Mcal.h"
#include "kf_types.h"
/******************************************************************************
**                        Version Check
******************************************************************************/

/******************************************************************************
**                        Macro Definitions
******************************************************************************/
#if ((SPI0_UNIFIED_INTERRUPT == STD_ON) || (SPI1_UNIFIED_INTERRUPT == STD_ON) || (SPI2_UNIFIED_INTERRUPT == STD_ON))
extern void Spi_Isr(uint8 module);
#endif
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
#if (SPI0_UNIFIED_INTERRUPT == STD_ON)
#if (IRQ_CAT_SPI0 == IRQ_CAT1)
KF_INTERRUPT(SPI0)
#else
ISR(SPI0)
#endif
{
    Spi_Isr(0U);
}
#endif

#if (SPI1_UNIFIED_INTERRUPT == STD_ON)
#if (IRQ_CAT_SPI1 == IRQ_CAT1)
KF_INTERRUPT(SPI1)
#else
ISR(SPI1)
#endif
{
    Spi_Isr(1U);
}
#endif

#if (SPI2_UNIFIED_INTERRUPT == STD_ON)
#if (IRQ_CAT_SPI2 == IRQ_CAT1)
KF_INTERRUPT(SPI2)
#else
ISR(SPI2)
#endif
{
    Spi_Isr(2U);
}
#endif

/* EOF */
