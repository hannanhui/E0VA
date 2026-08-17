/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Dma_Irq.c
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
/* PRQA S 0602 EOF  #KQR000602 */
/* PRQA S 4397 EOF  #KQR004397 */
/* PRQA S 0303 EOF  #KQR000303 */
/* PRQA S 0499 EOF  #KQR000499 */
/* PRQA S 3408 EOF  #KQR003408 */
/* PRQA S 4342 EOF #KQR004342 */
/* PRQA S 2071 EOF #KQR002071 */
/* PRQA S 2814 EOF #KQR002814 */
/* PRQA S 2824 EOF #KQR002824 */
/* PRQA S 2844 EOF #KQR002844 */
/* PRQA S 2201 EOF #KQR002201 */
/* PRQA S 4899 EOF #KQR004899 */

/******************************************************************************
 **                        Include Files
 ******************************************************************************/
#include "Irq_Cfg.h"
#include "kf32a158sf_drv_dma.h"
#include "kf_types.h"
#include "Mcal.h"
/******************************************************************************
 **                        File Version Check
 ******************************************************************************/

/******************************************************************************
 **                        Macro  Definitions
 ******************************************************************************/
/* Number of DMA controllers and channels */
#define DMA_CONTROLLER_COUNT       (2U)
#define DMA_CHANNEL_COUNT_PER_CTRL (7U)
/******************************************************************************
 **                        Typedef  Definitions
 ******************************************************************************/
/**
 * @brief interrupt handle
 */
typedef void (*Dma_IntrHandleFcnType)(uint8 IntrFlag);
/******************************************************************************
 **                      Constant Definitions
 ******************************************************************************/
/* Channel bit masks and shift offsets for each channel (1..7) */
/* PRQA S 2203 ++ #KQR002203 */
static const uint32 DmaIntrBits[DMA_CHANNEL_COUNT_PER_CTRL] = {
  DMA_INTR_BITS_CHANNEL_1, DMA_INTR_BITS_CHANNEL_2, DMA_INTR_BITS_CHANNEL_3, DMA_INTR_BITS_CHANNEL_4,
  DMA_INTR_BITS_CHANNEL_5, DMA_INTR_BITS_CHANNEL_6, DMA_INTR_BITS_CHANNEL_7};

static const uint8 DmaIntrShiftOffset[DMA_CHANNEL_COUNT_PER_CTRL] = {
  DMA_INTR_OFFSET_CHANNEL_1, DMA_INTR_OFFSET_CHANNEL_2, DMA_INTR_OFFSET_CHANNEL_3, DMA_INTR_OFFSET_CHANNEL_4,
  DMA_INTR_OFFSET_CHANNEL_5, DMA_INTR_OFFSET_CHANNEL_6, DMA_INTR_OFFSET_CHANNEL_7};

/* Pointer to DMA register base for indexing */
static volatile Dma_RegisterMap_t *const DmaBaseAddr[DMA_CONTROLLER_COUNT] = {DMA0_PTR, DMA1_PTR};
/* PRQA S 2203 -- #KQR002203 */
/******************************************************************************
 **                      Variables
 ******************************************************************************/
/**
 * @brief Table for full-transfer completion interrupt callbacks
 */
/*PRQA S 0686,0694 3 #KQR100015 - Array allows flexible initialization*/
static Dma_IntrHandleFcnType DmaTriggerHandle[DMA_CONTROLLER_COUNT][DMA_CHANNEL_COUNT_PER_CTRL] = {
  {NULL_PTR}, /* DMA0: all channels initialized to NULL */
  {NULL_PTR}  /* DMA1: all channels initialized to NULL */
};

/**
 * @brief Table for half-transfer completion interrupt callbacks
 */
/* PRQA S 2203 4 #KQR002203 */
/*PRQA S 0686,0694 2 #KQR100015*/
static Dma_IntrHandleFcnType DmaHalfCompleteTriggerHandle[DMA_CONTROLLER_COUNT][DMA_CHANNEL_COUNT_PER_CTRL] = {
  {NULL_PTR}, {NULL_PTR}};
/******************************************************************************
 **                        Export Variables
 ******************************************************************************/

/******************************************************************************
 **                       Export Functions
 ******************************************************************************/
/**
 * @brief Register a custom callback for DMA transfer complete interrupt
 *
 * @param DmaIndex     Index of DMA controller (0 or 1)
 * @param DmaChannel   Channel number (DMA_CHANNEL_1 ~ DMA_CHANNEL_7)
 * @param IrqHandle    Function pointer to user handler
 */
/* PRQA S 1336 1 #KQR001336 */
void Dma_RegisterCustomHandler(uint8 DmaIndex, Dma_Channel_t DmaChannel, void (*IrqHandle)(uint8))
{
    if ((DmaIndex < DMA_CONTROLLER_COUNT) && (DmaChannel >= DMA_CHANNEL_1) && (DmaChannel <= DMA_CHANNEL_7))
    {
        DmaTriggerHandle[DmaIndex][DmaChannel] = (Dma_IntrHandleFcnType)IrqHandle;
    }
}

/**
 * @brief Register a custom callback for DMA half-transfer complete interrupt
 *
 * @param DmaIndex     Index of DMA controller (0 or 1)
 * @param DmaChannel   Channel number (DMA_CHANNEL_1 ~ DMA_CHANNEL_7)
 * @param IrqHandle    Function pointer to user handler
 */
/* PRQA S 1336 1 #KQR001336 */
void Dma_RegisterHalfCompleteCustomHandler(uint8 DmaIndex, Dma_Channel_t DmaChannel, void (*IrqHandle)(uint8))
{
    if ((DmaIndex < DMA_CONTROLLER_COUNT) && (DmaChannel >= DMA_CHANNEL_1) && (DmaChannel <= DMA_CHANNEL_7))
    {
        DmaHalfCompleteTriggerHandle[DmaIndex][DmaChannel] = (Dma_IntrHandleFcnType)IrqHandle;
    }
}

/******************************************************************************
 **                      Internal Helper Functions
 ******************************************************************************/

/**
 * @brief Dispatch full-transfer interrupt to registered callback
 *
 * @param DmaIndex     DMA controller index
 * @param DmaChannel   Zero-based channel index (0~6)
 * @param IntrFlag     Raw interrupt flag
 */
static void Dma_IntrHandleDistribution(uint8 DmaIndex, uint8 DmaChannel, uint8 IntrFlag)
{
    if (DmaTriggerHandle[DmaIndex][DmaChannel] != NULL_PTR)
    {
        DmaTriggerHandle[DmaIndex][DmaChannel](IntrFlag);
    }
}

/**
 * @brief Dispatch half-transfer interrupt to registered callback
 *
 * @param DmaIndex     DMA controller index
 * @param DmaChannel   Zero-based channel index (0~6)
 * @param IntrFlag     Raw interrupt flag
 */
static void Dma_IntrHalfCompleteHandleDistribution(uint8 DmaIndex, uint8 DmaChannel, uint8 IntrFlag)
{
    if (DmaHalfCompleteTriggerHandle[DmaIndex][DmaChannel] != NULL_PTR)
    {
        DmaHalfCompleteTriggerHandle[DmaIndex][DmaChannel](IntrFlag);
    }
}

/******************************************************************************
 **                      Weak Error Handlers
 ******************************************************************************/

/**
 * @brief Default error handler for DMA0 (can be overridden by user)
 */
/* PRQA S 0602,2888 1 #KQR100017 */
void __attribute__((weak)) Dma0_ErrorIntrHandler(uint8_t DmaChannel)
{
    Dma_LL_ClearIntrFlag(DMA0_PTR, (Dma_Channel_t)DmaChannel, DMA_LIFR_ETIF_LOGIC_BIT);
}

/**
 * @brief Default error handler for DMA1 (can be overridden by user)
 */
/* PRQA S 0602,2888 1 #KQR100017 */
void __attribute__((weak)) Dma1_ErrorIntrHandler(uint8_t DmaChannel)
{
    Dma_LL_ClearIntrFlag(DMA1_PTR, (Dma_Channel_t)DmaChannel, DMA_LIFR_ETIF_LOGIC_BIT);
}

/******************************************************************************
 **                      Interrupt Service Routines
 ******************************************************************************/

/**
 * @brief DMA0 Exception Handler
 *
 */
#if (DMA0_UNIFIED_INTERRUPT == STD_ON)
#if (IRQ_CAT_DMA0 == IRQ_CAT1)
/* PRQA S 0602,2888 1 #KQR100017 */
KF_INTERRUPT(DMA0)
#else
ISR(DMA0)
#endif
{
    uint32 validBits = Dma_LL_GetAllActiveIntrBits(DMA0_PTR);
    uint8  dmaIdx    = 0U;

    for (uint8 loop = 0U; loop < DMA_CHANNEL_COUNT_PER_CTRL; loop++)
    {
        uint32 mask = DmaIntrBits[loop];
        if ((validBits & mask) != 0U)
        {
            uint32                      flag    = (validBits & mask) >> DmaIntrShiftOffset[loop];
            volatile Dma_RegisterMap_t *dmaBase = DmaBaseAddr[dmaIdx];

            if ((flag & (uint8_t)DMA_LIFR_FTIF_LOGIC_BIT) != 0U)
            {
                /* Clear flag first to prevent re-entry */
                Dma_LL_ClearIntrFlag(dmaBase, (Dma_Channel_t)loop, DMA_LIFR_FTIF_LOGIC_BIT);
                Dma_LL_SetFinishTransIntrEnabled(dmaBase, (Dma_Channel_t)loop, false);
                Dma_IntrHandleDistribution(dmaIdx, loop, (uint8)flag);
            }
            else if ((flag & (uint8_t)DMA_LIFR_HTIF_LOGIC_BIT) != 0U)
            {
                Dma_LL_ClearIntrFlag(dmaBase, (Dma_Channel_t)loop, DMA_LIFR_HTIF_LOGIC_BIT);
                Dma_LL_SetHalfTransIntrEnabled(dmaBase, (Dma_Channel_t)loop, false);
                Dma_IntrHalfCompleteHandleDistribution(dmaIdx, loop, (uint8)flag);
            }
            else
            {
                /* Unknown or error interrupt */
                (void)Dma0_ErrorIntrHandler((uint8_t)loop);
            }
        }
    }
}
#endif

/**
 * @brief DMA1 Exception Handler
 *
 */
#if (DMA1_UNIFIED_INTERRUPT == STD_ON)
#if (IRQ_CAT_DMA1 == IRQ_CAT1)
/* PRQA S 0602,2888 1 #KQR100017 */
KF_INTERRUPT(DMA1)
#else
ISR(DMA1)
#endif
{
    uint32 validBits = Dma_LL_GetAllActiveIntrBits(DMA1_PTR);
    uint8  dmaIdx    = 1U;

    for (uint8 loop = 0U; loop < DMA_CHANNEL_COUNT_PER_CTRL; loop++)
    {
        uint32 mask = DmaIntrBits[loop];
        if ((validBits & mask) != 0U)
        {
            uint32 flag = (validBits & mask) >> DmaIntrShiftOffset[loop];

            volatile Dma_RegisterMap_t *dmaBase = DmaBaseAddr[dmaIdx];

            if ((flag & (uint8_t)DMA_LIFR_FTIF_LOGIC_BIT) != 0U)
            {
                Dma_LL_ClearIntrFlag(dmaBase, (Dma_Channel_t)loop, DMA_LIFR_FTIF_LOGIC_BIT);
                Dma_LL_SetFinishTransIntrEnabled(dmaBase, (Dma_Channel_t)loop, false);
                Dma_IntrHandleDistribution(dmaIdx, loop, (uint8)flag);
            }
            else if ((flag & (uint8_t)DMA_LIFR_HTIF_LOGIC_BIT) != 0U)
            {
                Dma_LL_ClearIntrFlag(dmaBase, (Dma_Channel_t)loop, DMA_LIFR_HTIF_LOGIC_BIT);
                Dma_LL_SetHalfTransIntrEnabled(dmaBase, (Dma_Channel_t)loop, false);
                Dma_IntrHalfCompleteHandleDistribution(dmaIdx, loop, (uint8)flag);
            }
            else
            {
                (void)Dma1_ErrorIntrHandler((uint8_t)loop);
            }
        }
    }
}
#endif
