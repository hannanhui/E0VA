/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name        : kf32a158sf_drv_canfd.c
 *  @Date             : 2025-07-11
 *  @Version          : {{VersionDate}}
 *  @Description      : This file provides canfd driver.
 ******************************************************************************
 *  Copyright (C) by Shanghai ChipON Micro-Electronic Co.,Ltd
 *  All rights reserved.
 *
 *  This software is copyright protected and proprietary to
 *  Shanghai ChipON Micro-Electronic Co.,Ltd.
 *****************************************************************************/
/******************************************************************************
 *  |Date        |Version  |Author       |Description
 *******************************************************************************
 *  |2025-07-11  |V1.0     |AE Group     |New create
 ******************************************************************************/

/******************************************************************************
 *                       QAC Warnings
 ******************************************************************************/
/* PRQA S 0303,0306 EOF #KQR100303 */
/* PRQA S 0662 EOF #KQR000662 */
/* PRQA S 0310 EOF #KQR000310 */
/* PRQA S 0303,0306 EOF #KQR100303 */
/* PRQA S 0662 EOF #KQR000662 */
/* PRQA S 0310 EOF #KQR000310 */

/******************************************************************************
 *                      Include Files
 ******************************************************************************/
#include "kf32a158sf_drv_canfd.h"

/******************************************************************************
 *                      Macro Definitions
 ******************************************************************************/

/**
 * @brief Swap bytes in word index
 */
#define SwapBytesInWordIndex(index) (((index) & ~3U) + (3U - ((index) & 3U)))

/******************************************************************************
 *                      Constants
 ******************************************************************************/

/**
 * @brief Maximum threshold values for Payload
 */
static const uint8_t kvCanfd_MaxPayLoad[4U] = {CANFD_PAYLOAD_8, CANFD_PAYLOAD_16, CANFD_PAYLOAD_32, CANFD_PAYLOAD_64};

/**
 * @brief Maximum threshold values for Payload
 */
static const uint8_t kvCanfd_MaxMailboxNumber[4U] = {
    (uint8_t)CANFD_MAX_MB_PAYLOAD_8, (uint8_t)CANFD_MAX_MB_PAYLOAD_16, (uint8_t)CANFD_MAX_MB_PAYLOAD_32,
    (uint8_t)CANFD_MAX_MB_PAYLOAD_64};

/******************************************************************************
 *                      Type definitions
 ******************************************************************************/

/******************************************************************************
 *                      Variables
 ******************************************************************************/

/******************************************************************************
 *                      Private Function definitions
 ******************************************************************************/

/**
 * @brief Clear CANFD RAM
 *
 * @param Module Pointer to CANFD Module
 */
static void Canfd_LL_ClearRam(Canfd_RegisterMap_t *Module)
{
    uint32_t           databyte = 0U;
    volatile uint32_t *RAM      = Module->RAMn;

    Canfd_LL_SetWriteAccessToMemoryInHalt(Module, true);
    Canfd_LL_SetErrorCorrectConfigurationEnable(Module, true);
    Canfd_LL_SetErrorCorrectEnable(Module, false);

    /** Clear Mailbox region */
    for (databyte = 0U; databyte < CANFD_RAM_N_COUNT; databyte++)
    {
        RAM[databyte] = 0x0U;
    }

    /** Clear RXIMR region */
    RAM = (volatile uint32_t *)Module->RXIMR;
    for (databyte = 0; databyte < CANFD_MAX_MB_NUM; databyte++)
    {
        RAM[databyte] = 0x0;
    }

    /** Clear RXMGMASK, NRFGM,  RAM mapping */
    Module->RXMGMASK.reg = 0x0U;
    Module->NRFGM        = 0x0U;

    /* Clear SMB CAN region */
    RAM = (volatile uint32_t *)((uint32_t)Module + CAN_SMB_OFFSET);
    for (databyte = 0; databyte < CAN_SMB_LENGTH_IN_WORD; databyte++)
    {
        RAM[databyte] = 0x0;
    }
    /* Clear SMB FD region */
    RAM = (volatile uint32_t *)((uint32_t)Module + CANFD_SMB_OFFSET);
    for (databyte = 0; databyte < CANFD_SMB_LENGTH_IN_WORD; databyte++)
    {
        RAM[databyte] = 0x0;
    }
    /* Clear enhanced Rx FIFO RAM */
    RAM = (volatile uint32_t *)((uint32_t)Module + CAN_ENHANCED_RX_FIFO_OFFSET);
    for (databyte = 0; databyte < CAN_ENHANCED_RX_FIFO_LENGTH_IN_WORD; databyte++)
    {
        RAM[databyte] = 0x0;
    }
    /* Clear enhanced Rx FIFO filter RAM */
    RAM = (volatile uint32_t *)((uint32_t)Module + CAN_ENHANCED_RX_FIFO_FILTER_OFFSET);
    for (databyte = 0; databyte < CAN_ENHANCED_RX_FIFO_FILTER_LENGTH_IN_WORD; databyte++)
    {
        RAM[databyte] = 0x0;
    }

    Canfd_LL_SetErrorReportEnable(Module, false);
    Canfd_LL_SetErrorCorrectEnable(Module, true);
    Canfd_LL_SetWriteAccessToMemoryInHalt(Module, false);
}

/**
 * @brief Check whether the mailbox is valid or not.
 *
 * @param Module Module Pointer to CANFD Module
 * @param MailboxIndex Mailbox index
 * @return kf_status_t
 * @retval STATUS_OK  Mailbox is valid
 * @retval STATUS_ERROR Mailbox is invalid
 */
static kf_status_t Canfd_LL_CheckMailboxValid(const Canfd_RegisterMap_t *Module, uint32_t MailboxIndex)
{
    kf_status_t retStatus       = STATUS_OK;
    uint32_t    maxMailboxIndex = Canfd_LL_GetMaxMailboxCount(Module);
    uint32_t    rxFifoFilterNum = 0U;

    if (MailboxIndex > maxMailboxIndex)
    {
        /** Mailbox index out of range */
        retStatus = STATUS_ERROR;
    }
    else if (true == Canfd_LL_GetNormalRxFifoEnabledState(Module))
    {
        rxFifoFilterNum = (uint32_t)Canfd_LL_GetNormalFifoFilterNumber(Module);
        if (MailboxIndex <= Canfd_LL_GetRxFifoOccupiedLastMailbox(rxFifoFilterNum))
        {
            /** Mailbox is occupied by normal RX FIFO */
            retStatus = STATUS_ERROR;
        }
        else
        { /*Empty*/
        }
    }
    else
    { /*Empty*/
    }

    return retStatus;
}

/**
 * @brief Construct a new Canfd_LL_SetNormalRxFifoFilterFormatB object
 *
 * @param filterTablePtr
 * @param filterNumber
 * @param IDFilterTablePtr
 */
static void Canfd_LL_SetNormalRxFifoFilterFormatB(
    uint32_t volatile *filterTablePtr, uint32_t filterNumber, const Canfd_Filter_t *IDFilterTablePtr)
{
    volatile uint32_t val1;
    volatile uint32_t val2;
    uint32_t          filterTableIndex = 0U;
    /* PRQA S 0404 ++ #KQR000404 */

    for (uint32_t filterIndex = 0U; filterIndex < filterNumber; filterIndex++)
    {
        val1 = 0U;
        val2 = 0U;
        /** ID format 0 */
        if (IDFilterTablePtr[filterTableIndex].IsRemoteFrame)
        {
            val1 = (uint32_t)CAFND_RX_FIFO_ACCEPT_RTR_FRAME << (uint32_t)CANFD_FORMAT_AB_RTR_SHIFT;
        }
        else
        { /*Empty*/
        }
        if (IDFilterTablePtr[filterTableIndex].IsExtendedFrame)
        {
            val1 |= (uint32_t)CAFND_RX_FIFO_ACCEPT_EXT_FRAME << (uint32_t)CANFD_FORMAT_AB_IDE_SHIFT;
            filterTablePtr[filterIndex] =
                val1 +
                (((IDFilterTablePtr[filterTableIndex].ID & CANFD_FORMAT_B_EXT_MASK1) >> CANFD_FORMAT_B_ID_RIGHT_SHIFT)
                 << CANFD_FORMAT_B_EXT_SHIFT1);
        }
        else
        {
            filterTablePtr[filterIndex] =
                val1 + ((IDFilterTablePtr[filterTableIndex].ID & CANFD_FORMAT_B_STD_MASK) << CANFD_FORMAT_B_STD_SHIFT1);
        }

        /** ID format 1 */
        if (IDFilterTablePtr[filterTableIndex + 1U].IsRemoteFrame)
        {
            val2 = (uint32_t)CAFND_RX_FIFO_ACCEPT_RTR_FRAME << (uint32_t)CANFD_FORMAT_B_RTR_SHIFT;
        }
        else
        { /*Empty*/
        }
        if (IDFilterTablePtr[filterTableIndex + 1U].IsExtendedFrame)
        {
            val2 |= (uint32_t)CAFND_RX_FIFO_ACCEPT_EXT_FRAME << (uint32_t)CANFD_FORMAT_B_IDE_SHIFT;
            filterTablePtr[filterIndex] |=
                val2 + (((IDFilterTablePtr[filterTableIndex + 1U].ID & CANFD_FORMAT_B_EXT_MASK1) >>
                         CANFD_FORMAT_B_ID_RIGHT_SHIFT));
        }
        else
        {
            filterTablePtr[filterIndex] |=
                val2 +
                ((IDFilterTablePtr[filterTableIndex + 1U].ID & CANFD_FORMAT_B_STD_MASK) << CANFD_FORMAT_B_STD_SHIFT2);
        }
        filterTableIndex = filterTableIndex + 2U;
    }
    /* PRQA S 0404 -- #KQR000404 */
}

/**
 * @brief Construct a new Canfd_LL_SetNormalRxFifoFilterFormatC object
 *
 * @param filterTablePtr
 * @param filterNumber
 * @param IDFilterTablePtr
 */
static void Canfd_LL_SetNormalRxFifoFilterFormatC(
    uint32_t volatile *filterTablePtr, uint32_t filterNumber, const Canfd_Filter_t *IDFilterTablePtr)
{
    volatile uint32_t val1             = 0U;
    uint32_t          filterTableIndex = 0U;
    /* PRQA S 0404 ++ #KQR000404 */

    for (uint32_t filterIndex = 0U; filterIndex < filterNumber; filterIndex++)
    {
        filterTablePtr[filterIndex] = 0U;
        val1                        = 0U;

        /** ID format 0 */
        if (IDFilterTablePtr[filterTableIndex].IsExtendedFrame)
        {
            filterTablePtr[filterIndex] |=
                val1 +
                (((IDFilterTablePtr[filterTableIndex].ID & CANFD_FORMAT_C_EXT_MASK) >> CANFD_FORMAT_C_EXT_RIGHT_SHIFT)
                 << CANFD_FORMAT_C_SHIFT1);
        }
        else
        {
            filterTablePtr[filterIndex] |=
                val1 +
                (((IDFilterTablePtr[filterTableIndex].ID & CANFD_FORMAT_C_STD_MASK) >> CANFD_FORMAT_C_STD_RIGHT_SHIFT)
                 << CANFD_FORMAT_C_SHIFT1);
        }
        /** ID format 1 */
        if (IDFilterTablePtr[filterTableIndex + 1U].IsExtendedFrame)
        {
            filterTablePtr[filterIndex] |=
                val1 + (((IDFilterTablePtr[filterTableIndex + 1U].ID & CANFD_FORMAT_C_EXT_MASK) >>
                         CANFD_FORMAT_C_EXT_RIGHT_SHIFT)
                        << CANFD_FORMAT_C_SHIFT2);
        }
        else
        {
            filterTablePtr[filterIndex] |=
                val1 + (((IDFilterTablePtr[filterTableIndex + 1U].ID & CANFD_FORMAT_C_STD_MASK) >>
                         CANFD_FORMAT_C_STD_RIGHT_SHIFT)
                        << CANFD_FORMAT_C_SHIFT2);
        }
        /** ID format 2 */
        if (IDFilterTablePtr[filterTableIndex + 2U].IsExtendedFrame)
        {
            filterTablePtr[filterIndex] |=
                val1 + (((IDFilterTablePtr[filterTableIndex + 2U].ID & CANFD_FORMAT_C_EXT_MASK) >>
                         CANFD_FORMAT_C_EXT_RIGHT_SHIFT)
                        << CANFD_FORMAT_C_SHIFT3);
        }
        else
        {
            filterTablePtr[filterIndex] |=
                val1 + (((IDFilterTablePtr[filterTableIndex + 2U].ID & CANFD_FORMAT_C_STD_MASK) >>
                         CANFD_FORMAT_C_STD_RIGHT_SHIFT)
                        << CANFD_FORMAT_C_SHIFT3);
        }
        /** ID format 3 */
        if (IDFilterTablePtr[filterTableIndex + 3U].IsExtendedFrame)
        {
            filterTablePtr[filterIndex] |=
                val1 + (((IDFilterTablePtr[filterTableIndex + 3U].ID & CANFD_FORMAT_C_EXT_MASK) >>
                         CANFD_FORMAT_C_EXT_RIGHT_SHIFT));
        }
        else
        {
            filterTablePtr[filterIndex] |=
                val1 + (((IDFilterTablePtr[filterTableIndex + 3U].ID & (uint32_t)CANFD_FORMAT_C_STD_MASK) >>
                         (uint32_t)CANFD_FORMAT_C_STD_RIGHT_SHIFT));
        }
        filterTableIndex = filterTableIndex + 4U;
    }
    /* PRQA S 0404 -- #KQR000404 */
}

/******************************************************************************
 *                      Global Function definitions
 ******************************************************************************/

/**
 * @brief Get the maximum number of mailboxes based on the payload size.
 *
 * @param PayloadSize The payload size index. @ref Canfd_PayloadSize_t
 * @return uint32_t The maximum number of mailboxes for the given payload size.
 */
uint32_t Canfd_LL_GetMailboxNumber(uint32_t PayloadSize)
{
    uint32_t mailboxNumber = 0U;

    mailboxNumber =
        (((PayloadSize) < (sizeof(kvCanfd_MaxMailboxNumber) / sizeof(kvCanfd_MaxMailboxNumber[0U])))
             ? kvCanfd_MaxMailboxNumber[(PayloadSize)]
             : 0U);
    return mailboxNumber;
}

/**
 * @brief Get the actual data length based on the DLC (Data Length Code).
 *
 * @param Dlc The Data Length Code.
 * @return uint32_t The actual data length.
 */
uint32_t Canfd_LL_GetDataLength(uint32_t Dlc)
{
    /**
     * @brief Maximum threshold values for DLC
     */
    static const uint8_t kvCanFd_MaxDataLength[8U] = {
        (uint8_t)CANFD_MAX_DLC8,  (uint8_t)CANFD_MAX_DLC9,  (uint8_t)CANFD_MAX_DLC10, (uint8_t)CANFD_MAX_DLC11,
        (uint8_t)CANFD_MAX_DLC12, (uint8_t)CANFD_MAX_DLC13, (uint8_t)CANFD_MAX_DLC14, (uint8_t)CANFD_MAX_DLC15};

    uint32_t dataLength = 0U;

    if (Dlc < 8U)
    {
        dataLength = Dlc;
    }
    else if ((Dlc - 8U) < (sizeof(kvCanFd_MaxDataLength) / sizeof(kvCanFd_MaxDataLength[0U])))
    {
        dataLength = kvCanFd_MaxDataLength[(Dlc)-8U];
    }
    else
    {
        dataLength = 0U;
    }

    return dataLength;
}

/**
 * @brief Get the DLC (Data Length Code) based on the actual data length.
 *
 * @param dataLength The actual data length.
 * @return uint32_t The DLC (Data Length Code).
 */
uint32_t Canfd_LL_ComputeDlcValue(uint32_t dataLength)
{
    uint32_t Dlc = 0x0U;

    static const uint8_t payload_code[65U] = {
        /* 0,  1,  2,  3,  4,  5,  6,  7,  8, */
        0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U,
        /* 9 to 12 payload have DLC Code 12 Bytes */
        9U, 9U, 9U, 9U,
        /* 13 to 16 payload have DLC Code 16 Bytes */
        10U, 10U, 10U, 10U,
        /* 17 to 20 payload have DLC Code 20 Bytes */
        11U, 11U, 11U, 11U,
        /* 21 to 24 payload have DLC Code 24 Bytes */
        12U, 12U, 12U, 12U,
        /* 25 to 32 payload have DLC Code 32 Bytes */
        13U, 13U, 13U, 13U, 13U, 13U, 13U, 13U,
        /* 33 to 48 payload have DLC Code 48 Bytes */
        14U, 14U, 14U, 14U, 14U, 14U, 14U, 14U, 14U, 14U, 14U, 14U, 14U, 14U, 14U, 14U,
        /* 49 to 64 payload have DLC Code 64 Bytes */
        15U, 15U, 15U, 15U, 15U, 15U, 15U, 15U, 15U, 15U, 15U, 15U, 15U, 15U, 15U, 15U};

    if (dataLength <= 64U)
    {
        Dlc = payload_code[dataLength];
    }
    else
    {
        /* The argument is not a valid payload size will return 0x0U*/
    }

    return Dlc;
}

/**
 * @brief Swap endian in a word
 *
 * @param DesPtr Pointer to destination
 * @param SouPtr Pointer to source
 */
void Canfd_LL_SwapBytesInWord(void *DesPtr, const void *SouPtr)
{
    /** Avoid not aligned to 4Bytes */
    /* PRQA S 0316 2 #KQR000316 */
    uint8_t       *ptrDes = (uint8_t *)DesPtr;
    const uint8_t *ptrSou = (const uint8_t *)SouPtr;

    ptrDes[0] = ptrSou[3];
    ptrDes[1] = ptrSou[2];
    ptrDes[2] = ptrSou[1];
    ptrDes[3] = ptrSou[0];
}

/**
 * @brief Get Payload Memory Size
 *
 * @param Module Pointer to CANFD Module
 * @param Region  Mailbox Region
 * @return uint32_t
 */
uint32_t Canfd_LL_GetPayloadMemSize(const Canfd_RegisterMap_t *Module, Canfd_Region_t Region)
{
    uint32_t payloadMemSize = 0U;

    payloadMemSize = kvCanfd_MaxPayLoad[(uint32_t)Canfd_LL_GetPayloadSize(Module, Region)];
    return payloadMemSize;
}

/**
 * @brief Enter Halt Mode
 *
 * @param Module Pointer to CANFD Module
 * @return void
 */
uint32_t Canfd_LL_EnterHaltMode(Canfd_RegisterMap_t *Module)
{
    uint32_t ret = 1U;

    if (false == Canfd_LL_GetHaltAck(Module))
    {
        Canfd_LL_SetHaltEnabled(Module, true);
        Canfd_LL_SetHaltRequestEnabled(Module, true);
        /* Wait till enter halt mode */
        while (false == Canfd_LL_GetHaltAck(Module))
        {
            ;
        }
    }
    else
    {
        ret = 0U;
    }

    return ret;
}

/**
 * @brief Exit Halt Mode
 *
 * @param Module Pointer to CANFD Module
 * @return void
 */
void Canfd_LL_ExitHaltMode(Canfd_RegisterMap_t *Module, uint32_t State)
{
    if (1U == State)
    {
        Canfd_LL_SetHaltRequestEnabled(Module, false);
        Canfd_LL_SetHaltEnabled(Module, false);
        /* Wait till exit halt mode */
        while (true == Canfd_LL_GetHaltAck(Module))
        {
            ;
        }
    }
    else
    { /*Empty*/
    }
}

/**
 * @brief Disable CANFD Module
 *
 * @param Module Pointer to CANFD Module
 * @return void
 */
void Canfd_LL_Disable(Canfd_RegisterMap_t *Module)
{
    /* Clock disable (module) */
    Canfd_LL_SetEnabled(Module, false);
    /* Wait until disable mode acknowledged */
    while (false == Canfd_LL_GetDisableModeAck(Module))
    {
        ;
    }
}

/**
 * @brief Enable CANFD Module
 *
 * @param Module Pointer to CANFD Module
 * @return void
 */
void Canfd_LL_Enable(Canfd_RegisterMap_t *Module)
{
    /* Clock disable (module) */
    Canfd_LL_SetEnabled(Module, true);
    /* Wait until disable mode acknowledged */
    while (true == Canfd_LL_GetDisableModeAck(Module))
    {
        ;
    }
}

/**
 * @brief Set CAN bit Time Segments
 *
 * @param Module Pointer to CANFD Module
 * @param TimeSegPtr Pointer to CAN bit Time Segments
 * @note PropSeg, 0x0 ~ 0x7U
 * @note TSeg1, 0x0 ~ 0x7U
 * @note TSeg2, 0x0 ~ 0x7U
 * @note PreScaler, 0x0 ~ 0xFFU
 * @note Sjw, 0x0 ~ 0x3U
 */
void Canfd_LL_SetTimeSegments(Canfd_RegisterMap_t *Module, const Canfd_ArbiTimeSegment_t *const TimeSegPtr)
{
    Canfd_LL_SetPropSeg(Module, TimeSegPtr->PropSeg);
    Canfd_LL_SetPhaseSeg1(Module, TimeSegPtr->TSeg1);
    Canfd_LL_SetPhaseSeg2(Module, TimeSegPtr->TSeg2);
    Canfd_LL_SetPrescalerDivision(Module, TimeSegPtr->PreScaler);
    Canfd_LL_SetResyncJumpWidth(Module, TimeSegPtr->Sjw);
    Canfd_LL_SetSampleTime(Module, TimeSegPtr->SampleTime);
}

/**
 * @brief Set Extended CAN bit Time Segments
 *
 * @param Module Pointer to CANFD Module
 * @param TimeSegPtr Pointer to CAN bit Time Segments
 * @note PropSeg, 0x0 ~ 0x3FU
 * @note TSeg1, 0x0 ~ 0x1FU
 * @note TSeg2, 0x0 ~ 0x1FU
 * @note PreScaler, 0x0 ~ 0x3FFU
 * @note Sjw, 0x0 ~ 0x1FU
 */
void Canfd_LL_SetExtendedTimeSegments(Canfd_RegisterMap_t *Module, const Canfd_ArbiTimeSegment_t *const TimeSegPtr)
{
    Canfd_LL_SetExtendedPropSeg(Module, TimeSegPtr->PropSeg);
    Canfd_LL_SetExtendedPhaseSeg1(Module, TimeSegPtr->TSeg1);
    Canfd_LL_SetExtendedPhaseSeg2(Module, TimeSegPtr->TSeg2);
    Canfd_LL_SetExtendedPrescalerDivision(Module, TimeSegPtr->PreScaler);
    Canfd_LL_SetExtendedResyncJumpWidth(Module, TimeSegPtr->Sjw);
}

/**
 * @brief Set CANFD bit time segments
 *
 * @param Module Pointer to CANFD Module
 * @param TimeSegPtr Pointer to CANFD bit Time Segments
 * @note PropSeg, 0x0 ~ 0x1FU
 * @note HtSeg1, 0x0 ~ 0x7U
 * @note HtSeg2, 0x0 ~ 0x7U
 * @note BrsPrescale, 0x0 ~ 0x3FFU
 * @note Sjw, 0x0 ~ 0x7U
 */
void Canfd_LL_SetFdTimeSegments(Canfd_RegisterMap_t *Module, const Canfd_DataTimeSegment_t *const TimeSegPtr)
{
    Canfd_LL_SetFdPropSeg(Module, TimeSegPtr->PropSeg);
    Canfd_LL_SetFdPhaseSeg1(Module, TimeSegPtr->HtSeg1);
    Canfd_LL_SetFdPhaseSeg2(Module, TimeSegPtr->HtSeg2);
    Canfd_LL_SetFdPrescalerDivision(Module, TimeSegPtr->BrsPrescale);
    Canfd_LL_SetFdResyncJumpWidth(Module, TimeSegPtr->Sjw);
}

/**
 * @brief Get CAN bit time segments
 *
 * @param Module Pointer to CANFD Module
 * @param TimeSegPtr Pointer to CAN bit Time Segments
 */
void Canfd_LL_GetTimeSegments(const Canfd_RegisterMap_t *Module, Canfd_ArbiTimeSegment_t *TimeSegPtr)
{
    TimeSegPtr->PropSeg   = Canfd_LL_GetPropSeg(Module);
    TimeSegPtr->TSeg1     = Canfd_LL_GetPhaseSeg1(Module);
    TimeSegPtr->TSeg2     = Canfd_LL_GetPhaseSeg2(Module);
    TimeSegPtr->PreScaler = Canfd_LL_GetPrescalerDivision(Module);
    TimeSegPtr->Sjw       = Canfd_LL_GetResyncJumpWidth(Module);
    /* PRQA S 4342 1 #KQR004342 */
    TimeSegPtr->SampleTime = (Canfd_SampleTime_t)Canfd_LL_GetSampleTime(Module);
}

/**
 * @brief Get CANFD bit time segments
 *
 * @param Module Pointer to CANFD Module
 * @param TimeSegPtr Pointer to CANFD bit Time Segments
 */
void Canfd_LL_GetFdTimeSegments(const Canfd_RegisterMap_t *Module, Canfd_DataTimeSegment_t *TimeSegPtr)
{
    TimeSegPtr->PropSeg     = Canfd_LL_GetFdPropSeg(Module);
    TimeSegPtr->HtSeg1      = Canfd_LL_GetFdPhaseSeg1(Module);
    TimeSegPtr->HtSeg2      = Canfd_LL_GetFdPhaseSeg2(Module);
    TimeSegPtr->BrsPrescale = Canfd_LL_GetFdPrescalerDivision(Module);
    TimeSegPtr->Sjw         = Canfd_LL_GetFdResyncJumpWidth(Module);
}

/**
 * @brief Get First Individual MB
 *
 * @param Module Pointer to CANFD Module
 * @return uint32_t index of first individual MB
 */
uint32_t Canfd_LL_GetFirstIndividualMailbox(const Canfd_RegisterMap_t *Module)
{
    /* Get the number of RX FIFO Filters*/
    uint32_t count = (uint32_t)Canfd_LL_GetNormalFifoFilterNumber(Module);
    /* Max filters configured by individual mask are (5 + 2 + RFFN * 2) depends on the FIFO size,
     * max allowed value is 63 RXIMR */
    count = (uint32_t)(8U + ((uint32_t)count << 1U));
    if (count > CANFD_MAX_MB_NUM)
    {
        count = (uint32_t)(CANFD_MAX_MB_NUM - 1U);
    }
    else
    { /**Empty*/
    }
    return count;
}

/**
 * @brief Clear Error Status Flag
 *
 * @param Module Pointer to CANFD Module
 */
void Canfd_LL_ClearErrIntrStatusFlag(Canfd_RegisterMap_t *Module)
{
    if (0U != (Canfd_LL_GetErrorState(Module) & CANFD_ALL_INT))
    {
        Canfd_LL_ClearErrorState(Module, CANFD_ALL_INT);
    }
    else
    {
        /**Empty*/
    }
}

/**
 * @brief Enables/Disables the TDC feature and sets the TDC Offset
 *
 * @param Module Pointer to CANFD Module
 * @param Status true : Enable TDC, false : Disable TDC
 * @param Offset TDC Offset
 */
void Canfd_LL_SetTdcOffset(Canfd_RegisterMap_t *Module, bool Status, uint32_t Offset)
{
    Canfd_LL_SetTdcEnabled(Module, Status);
    Canfd_LL_SetTdcOffsetValue(Module, Offset);
}

/**
 * @brief Enables/Disables the TDC feature and sets the TDC Offset
 *
 * @param Module Pointer to CANFD Module
 * @param Status true : Enable TDC, false : Disable TDC
 * @param Offset TDC Offset, 0x0 ~ 0x7F
 */
void Canfd_LL_SetEnhancedTdcOffset(Canfd_RegisterMap_t *Module, bool Status, uint32_t Offset)
{
    Module->ETDC.bits.ETDCEN  = Status ? 1U : 0U;
    Module->ETDC.bits.ETDCOFF = Offset;
}

/**
 * @brief Initialize CANFD module
 *
 * @param Module Pointer to CANFD Module
 */
void Canfd_LL_Init(Canfd_RegisterMap_t *Module)
{
    /* Reset CANFD module */
    Canfd_LL_SetSoftReset(Module, true);
    /* Wait for reset cycle to complete */
    while (false != Canfd_LL_GetSoftResetState(Module))
    {
        ;
    }

    /* Avoid Abort Transmission, use Inactive MB */
    Module->CTL0.bits.ATXEN = 1U;

    /* Clear CANFD memory */
    Canfd_LL_ClearRam(Module);

    /* Rx global mask*/
    Canfd_LL_SetRxMailboxGlobalMask(Module, (uint32_t)0xFFFFFFFFU);

    /* Disable all MB interrupts */
    Canfd_LL_SetIntr1Mask(Module, 0x0U);
    /* Clear all MB interrupt flags */
    Canfd_LL_ClearIntr1Flag(Module, CAN_IMASK1_BUF31TO0M_MASK);
    /* Disable all MB interrupts */
    Canfd_LL_SetIntr2Mask(Module, 0x0U);
    /* Clear all MB interrupt flags */
    Canfd_LL_ClearIntr2Flag(Module, CAN_IMASK2_BUF63TO32M_MASK);

    /* Clear all error interrupt flags */
    Canfd_LL_ClearErrorState(Module, CANFD_ALL_INT);

    /* clear registers which are not effected by soft reset */
    Module->CTL1.reg = 0x0U;
    Module->CTL2.reg = 0x00100000U;
    Module->CBT.reg  = 0x0U;

    Module->EPRS.reg = 0x0U;
    Module->ETDC.reg = 0x0U;

    Module->FDCBT.reg = 0x0U;
    Module->FDCTL.reg = 0x0U;

#if (CAN_FEATURE_SWAP_ENABLE == true)
    Canfd_LL_SetReadEndianSwapEnabled(Module, true);
    Canfd_LL_SetWriteEndianSwapEnabled(Module, true);
#endif
}

/**
 * @brief Set Rx FIFO global mask
 *
 * @param Module Pointer to CANFD Module
 * @param IDType ID type, standard ID or extended ID
 * @param Mask The 11-bit standard mask or the 29-bit extended mask
 */
void Canfd_LL_SetNormalRxFifoGlobalMask(Canfd_RegisterMap_t *Module, Canfd_IDType_t IDType, uint32_t Mask)
{
    Canfd_NormalRxFifoIDFormat_t formatType;
    uint32_t                     calcMask = 0U;
    uint32_t                     halt     = 0U;

    halt = Canfd_LL_EnterHaltMode(Module);
    if (true == Canfd_LL_GetNormalRxFifoEnabledState(Module))
    {
        formatType = Canfd_LL_GetRxFifoIDFormat(Module);
        calcMask   = Canfd_LL_GetRxFifoMask(IDType, formatType, Mask);
        switch (formatType)
        {
        case CANFD_RX_FIFO_ID_FORMAT_A:
            break;
        case CANFD_RX_FIFO_ID_FORMAT_B:
            calcMask = (calcMask | (calcMask >> CANFD_FORMAT_B_SHIFT1));
            break;
        case CANFD_RX_FIFO_ID_FORMAT_C:
            calcMask = (calcMask | ((calcMask >> CANFD_FORMAT_C_SHIFT1) | (calcMask >> CANFD_FORMAT_C_SHIFT2) |
                                    (calcMask >> CANFD_FORMAT_C_SHIFT3)));
            break;
        default:
            /* Will Enable all filter fields mask */
            calcMask = 0xFFFFFFFFU;
            break;
        }
        Canfd_LL_SetNormalRxFifoFilterGlobalMask(Module, calcMask);
    }
    else
    { /*Empty*/
    }
    Canfd_LL_ExitHaltMode(Module, halt);
}

/**
 * @brief Set filter mask for individual mailbox
 *
 * @param Module Pointer to CANFD Module
 * @param MailboxIndex Index of mailbox
 * @param FilterPtr filter mask
 */
void Canfd_LL_SetRxIndividualMask(
    Canfd_RegisterMap_t *Module, Canfd_MB_t MailboxIndex, Canfd_IDType_t IDType, uint32_t Mask)
{
    kf_status_t retStatus = STATUS_OK;
    uint32_t    halt      = 0U;

    halt = Canfd_LL_EnterHaltMode(Module);

    /* PRQA S 3415 ++ #KQR003415 */
    if (((uint32_t)MailboxIndex >= (uint32_t)CANFD_MAX_MB_NUM) ||
        ((uint32_t)MailboxIndex > Canfd_LL_GetMaxMailboxCount(Module)))
    {
        retStatus = STATUS_ERROR;
    }
    else
    {
        if ((true == Canfd_LL_GetNormalRxFifoEnabledState(Module)) &&
            ((uint32_t)MailboxIndex < Canfd_LL_GetFirstIndividualMailbox(Module)))
        {

            retStatus = STATUS_ERROR;
        }
        else
        { /*Empty*/
        }
    }
    /* PRQA S 3415 -- #KQR003415 */

    if (STATUS_OK == retStatus)
    {
        if (IDType == CANFD_MSG_ID_STD)
        {
            Canfd_LL_SetRxMailboxIndividualStandardMask(Module, MailboxIndex, Mask);
        }
        else
        {
            Canfd_LL_SetRxMailboxIndividualExtendedMask(Module, MailboxIndex, Mask);
        }
    }
    else
    { /*Empty*/
    }

    Canfd_LL_ExitHaltMode(Module, halt);
}

/**
 * @brief Config Normal Rx Fifo
 *
 * @param Module Pointer to CANFD Module
 * @param NormalRxFifoPtr Pointer to Normal configuration
 *
 * @note The length of filter configuration (member of NormalRxFifoPtr: FilterPtr) is 8 + (2 * FilterNum).
 *
 * @return kf_status_t
 * @retval STATUS_OK Success to configure Normal Rx Fifo
 * @retval STATUS_ERROR Failed to configure Normal Rx Fifo
 */
kf_status_t Canfd_LL_ConfigNormalRxFifo(Canfd_RegisterMap_t *Module, const Canfd_NormalRxFifo_t *NormalRxFifoPtr)
{
    kf_status_t retStatus    = STATUS_OK;
    uint32_t    filterLength = 0U;
    uint32_t    halt         = 0U;

    if (true == Canfd_LL_GetFdEnabledState(Module))
    {
        retStatus = STATUS_ERROR;
    }
    else if (true == Canfd_LL_GetEnhancedRxFifoEnabledState(Module))
    {
        /*Enhanced RX FIFO and Normal RX FIFO cannot be enabled at the same time.*/
        retStatus = STATUS_ERROR;
    }
    else
    { /** Empty */
    }

    if (STATUS_OK == retStatus)
    {
        halt = Canfd_LL_EnterHaltMode(Module);
        Canfd_LL_SetNormalRxFifoEnabled(Module, true);
        Canfd_LL_SetNormalFifoFilterNum(Module, NormalRxFifoPtr->FilterNum);
        Canfd_LL_SetNormalRxFifoIDFormat(Module, NormalRxFifoPtr->IDFormat);
        Canfd_LL_SetNormalRxFifoGlobalMask(Module, NormalRxFifoPtr->GlobalIDType, NormalRxFifoPtr->GlobalMask);
        if (CANFD_RX_FIFO_ID_FORMAT_D != NormalRxFifoPtr->IDFormat)
        {
            filterLength = 8U + ((uint32_t)NormalRxFifoPtr->FilterNum << 1U);
            filterLength = (filterLength > 32U) ? 32U : filterLength;
            for (uint32_t filterCount = 0U; filterCount < filterLength; filterCount++)
            {
                Module->RXIMR[filterCount].reg = NormalRxFifoPtr->FilterPtr[filterCount].reg;
            }
        }
        else
        { /** Empty */
        }

        Canfd_LL_ExitHaltMode(Module, halt);
    }
    else
    { /**Empty*/
    }
    return retStatus;
}

/**
 * @brief Set Enhanced Rx FIFO filter
 *
 * @param Module Pointer to CANFD Module
 * @param FilterPtr Pointer to CANFD Enhanced Rx FIFO Filter
 */
void Canfd_LL_SetEnhancedRxFifoFilter(Canfd_RegisterMap_t *Module, const Canfd_EnhancedRxFifoFilter_t *FilterPtr)
{
    uint32_t filterCount          = 0U;
    uint32_t filterLength         = 0U;
    uint32_t extendedFilterLength = 0U;
    uint32_t FilterIndex          = 0U;
    uint32_t halt                 = 0U;

    halt = Canfd_LL_EnterHaltMode(Module);

    filterLength         = Canfd_LL_GetEnhancedRxFifoFilterNumber(Module);
    extendedFilterLength = Canfd_LL_GetEnhancedRxFifoExtendedFilterNumber(Module);
    extendedFilterLength = extendedFilterLength << 1U;
    filterLength         = (filterLength << 1U) + 2U;

    /** Set filter of extended ID */
    FilterIndex = 0U;
    for (filterCount = 0U; filterCount < extendedFilterLength; filterCount += 2U)
    {
        Canfd_LL_SetEnhancedRxFifoFilterElement(Module, filterCount, FilterPtr->ExtendedIDFilter[FilterIndex].reg[0U]);
        Canfd_LL_SetEnhancedRxFifoFilterElement(
            Module, (filterCount + 1U), FilterPtr->ExtendedIDFilter[FilterIndex].reg[1U]);
        FilterIndex++;
    }
    /** Set filter of standard ID */
    FilterIndex = 0U;
    for (filterCount = extendedFilterLength; filterCount < filterLength; filterCount++)
    {
        Canfd_LL_SetEnhancedRxFifoFilterElement(Module, filterCount, FilterPtr->StandardIDFilter[FilterIndex].reg);
        FilterIndex++;
    }
    Canfd_LL_ExitHaltMode(Module, halt);
}

/**
 * @brief Config Enhanced Rx Fifo
 *
 * @param Module Pointer to CANFD Module
 * @param EnhancedRxFifoPtr Pointer to Enhanced configuration
 * @return kf_status_t
 * @retval STATUS_OK Success to configure Enhanced Rx Fifo
 * @retval STATUS_ERROR Failed to configure Enhanced Rx Fifo
 */
kf_status_t Canfd_LL_ConfigEnhancedRxFifo(Canfd_RegisterMap_t *Module, const Canfd_EnhancedRxFifo_t *EnhancedRxFifoPtr)
{
    kf_status_t       retStatus            = STATUS_OK;
    uint32_t          filterCount          = 0U;
    uint32_t          filterLength         = 0U;
    uint32_t          standardFilterLength = 0U;
    uint32_t          extendedFilterLength = 0U;
    volatile uint32_t filterIndex          = 0U;
    uint32_t          halt                 = 0U;

    if ((0U == EnhancedRxFifoPtr->StandardIDFilterNumber) && (0U == EnhancedRxFifoPtr->ExtendedIDFilterNumber))
    {
        retStatus = STATUS_ERROR;
    }
    else if (0U != (EnhancedRxFifoPtr->StandardIDFilterNumber & 1U))
    {
        /* If the number of Std Filters is odd */
        retStatus = STATUS_ERROR;
    }
    else if (true == Canfd_LL_GetNormalRxFifoEnabledState(Module))
    {
        /*Enhanced RX FIFO and Normal RX FIFO cannot be enabled at the same time.*/
        retStatus = STATUS_ERROR;
    }
    else if ((EnhancedRxFifoPtr->StandardIDFilterNumber + (EnhancedRxFifoPtr->ExtendedIDFilterNumber << 1U)) >
             CANFD_ERFFEL_NUM)
    {
        /** Number of filter is too large */
        retStatus = STATUS_ERROR;
    }
    else
    { /**Empty*/
    }
    if (STATUS_OK == retStatus)
    {
        standardFilterLength = EnhancedRxFifoPtr->StandardIDFilterNumber;
        extendedFilterLength = EnhancedRxFifoPtr->ExtendedIDFilterNumber << 1U;
        filterLength =
            ((EnhancedRxFifoPtr->StandardIDFilterNumber >> 1U) + EnhancedRxFifoPtr->ExtendedIDFilterNumber - 1U);
        halt = Canfd_LL_EnterHaltMode(Module);
        Canfd_LL_SetEnhancedRxFifoEnabled(Module, true);
        Canfd_LL_ClearEnhancedRxFifo(Module);
        Canfd_LL_ClearEnhancedRxFifoState(Module);
        Canfd_LL_SetEnhancedRxFifoFilterNumber(Module, filterLength);
        Canfd_LL_SetEnhancedRxFifoExtendedFilterNumber(Module, EnhancedRxFifoPtr->ExtendedIDFilterNumber);
        Canfd_LL_SetEnhancedRxFifoWaterMark(Module, EnhancedRxFifoPtr->WaterMark);

        /* PRQA S 0404 ++ #KQR000404 */
        /** Set filter of extended ID */
        filterIndex = 0U;
        for (filterCount = 0U; filterCount < extendedFilterLength; filterCount += 2U)
        {
            Canfd_LL_SetEnhancedRxFifoFilterElement(
                Module, filterCount, EnhancedRxFifoPtr->FilterPtr->ExtendedIDFilter[filterIndex].reg[0U]);
            Canfd_LL_SetEnhancedRxFifoFilterElement(
                Module, (filterCount + 1U), EnhancedRxFifoPtr->FilterPtr->ExtendedIDFilter[filterIndex].reg[1U]);
            filterIndex += 1U;
        }
        /** Set filter of standard ID */
        filterIndex = 0U;
        for (filterCount = extendedFilterLength; filterCount < (standardFilterLength + extendedFilterLength);
             filterCount++)
        {
            Canfd_LL_SetEnhancedRxFifoFilterElement(
                Module, filterCount, EnhancedRxFifoPtr->FilterPtr->StandardIDFilter[filterIndex].reg);
            filterIndex += 1U;
        }
        Canfd_LL_ExitHaltMode(Module, halt);
        /* PRQA S 0404 -- #KQR000404 */
    }
    else
    { /**Empty*/
    }
    return retStatus;
}

/**
 * @brief Get Mailbox Address
 *
 * @param Module Pointer to CANFD Module
 * @param MailboxIndex Index of mailbox
 * @return volatile uint32_t* Address of mailbox
 */
volatile uint32_t *Canfd_LL_GetMailboxAddress(Canfd_RegisterMap_t *Module, Canfd_MB_t MailboxIndex)
{
    uint32_t region                 = 0U;
    uint32_t mbSize                 = 0U;
    uint32_t ramOffset              = 0U;
    uint32_t payloadSize            = 0U;
    uint32_t TotalMBNumber          = 0U;
    uint32_t payloadMemSize         = 0U;
    uint32_t mailboxOffset          = 0U;
    uint32_t arbitrationMailboxSize = 8U;
    uint32_t ramBlockSize           = 128U;

    /** Only support 2 region */
    for (region = 0U; region < 2U; region++)
    {
        /* PRQA S 4342 1 #KQR004342 */
        payloadSize = (uint32_t)Canfd_LL_GetPayloadSize(Module, (Canfd_Region_t)region);
        TotalMBNumber += kvCanfd_MaxMailboxNumber[payloadSize];
        if ((uint32_t)MailboxIndex < TotalMBNumber)
        {
            mailboxOffset = (uint32_t)MailboxIndex - (TotalMBNumber - kvCanfd_MaxMailboxNumber[payloadSize]);
            break;
        }
        else
        { /**Empty*/
        }
    }
    payloadMemSize = kvCanfd_MaxPayLoad[payloadSize];
    mbSize         = payloadMemSize + arbitrationMailboxSize;
    ramOffset      = ((mailboxOffset * mbSize) >> 2U) + (region * ramBlockSize);
    return &(Module->RAMn[ramOffset]);
}

/**
 * @brief Set Max Mailbox Number
 *
 * @param Module Pointer to CANFD Module
 * @param MaxMailboxNumber Maximum number of mailbox, 1 ~ 64
 * @return kf_status_t
 */
kf_status_t Canfd_LL_SetMaxMailboxNumber(Canfd_RegisterMap_t *Module, uint32_t MaxMailboxNumber)
{
    kf_status_t retStatus        = STATUS_OK;
    uint32_t    tmpMailboxNumber = MaxMailboxNumber - 1U;

    /* PRQA S 4342 1 #KQR004342 */
    const volatile uint32_t *endMBPointer = Canfd_LL_GetMailboxAddress(Module, (Canfd_MB_t)tmpMailboxNumber);

    if (((uint32_t)endMBPointer >= (uint32_t)(&Module->RAMn[CANFD_RAM_N_COUNT])) ||
        (MaxMailboxNumber > CANFD_MAX_MB_NUM) || (MaxMailboxNumber < 2U))
    {
        /** Invalid Max Mailbox Number */
        retStatus = STATUS_ERROR;
    }
    else
    { /*Empty*/
    }
    if (STATUS_OK == retStatus)
    {
        /* Set the maximum number of MBs*/
        Canfd_LL_SetMaxMailboxCount(Module, tmpMailboxNumber);
    }
    else
    { /*Empty*/
    }
    return retStatus;
}

/**
 * @brief Set CANFD Operation Mode
 *
 * @param Module Pointer to CANFD Module
 * @param Mode Operation Mode
 */
void Canfd_LL_SetOperationMode(Canfd_RegisterMap_t *Module, Canfd_Mode_t Mode)
{
    switch (Mode)
    {
    case CANFD_HALT_MODE:
        /* Debug mode, Halt and Halt*/
        (void)Canfd_LL_EnterHaltMode(Module);
        break;
    case CANFD_DISABLE_MODE:
        /* Debug mode, Halt and Halt */
        Canfd_LL_SetEnabled(Module, false);
        break;
    case CANFD_NORMAL_MODE:
        Canfd_LL_SetSuperVisorMode(Module, false);
        Canfd_LL_SetListenOnlyMode(Module, false);
        Canfd_LL_SetLoopBackMode(Module, false);
        break;
    case CANFD_LISTEN_ONLY_MODE:
        Canfd_LL_SetListenOnlyMode(Module, true);
        break;
    case CANFD_LOOPBACK_MODE:
        Canfd_LL_SetListenOnlyMode(Module, false);
        Canfd_LL_SetLoopBackMode(Module, true);
        /* Enable Self Reception */
        Canfd_LL_SetSelfReceptionEnabled(Module, true);
        break;
    default:
        /* Should not get here */
        break;
    }
}

/**
 * @brief Set Error Interrupt Enable
 *
 * @param Module Pointer to CANFD Module
 * @param ErrType Error Interrupt Type
 * @param Status true: enable, false: disable
 */
void Canfd_LL_SetErrorIntrEnabled(Canfd_RegisterMap_t *Module, Canfd_ErrorIntr_t ErrType, bool Status)
{
    uint32_t intrBefore = 0U;

    if (Status)
    {
        if ((ErrType == CANFD_INTR_RX_WARNING) || (ErrType == CANFD_INTR_TX_WARNING))
        {
            Canfd_LL_SetWarningIntrEnabled(Module, Status);
        }
        else
        { /*Empty*/
        }
        if (ErrType == CANFD_INTR_ERR)
        {
            Canfd_LL_SetFdErrorIntrEnabled(Module, Status);
        }
        else
        { /*Empty*/
        }
        Canfd_LL_SetErrorIntrMask(Module, (uint32_t)ErrType);
    }
    else
    {
        Canfd_LL_ClearErrorIntrMask(Module, (uint32_t)ErrType);
        if (ErrType == CANFD_INTR_ERR)
        {
            Canfd_LL_SetFdErrorIntrEnabled(Module, Status);
        }
        else
        { /*Empty*/
        }
        intrBefore = Canfd_LL_GetErrorIntrMask(Module);
        if (((intrBefore & (uint32_t)CANFD_INTR_RX_WARNING) == 0U) &&
            ((intrBefore & (uint32_t)CANFD_INTR_TX_WARNING) == 0U))
        {
            Canfd_LL_SetWarningIntrEnabled(Module, Status);
        }
        else
        { /*Empty*/
        }
    }
}

/**
 * @brief Writes the abort code into the CODE field of Tx mailbox.
 *
 * @param Module Pointer to CANFD Module
 * @param MailboxIndex Index of mailbox
 */
void Canfd_LL_AbortTxMailbox(Canfd_RegisterMap_t *Module, Canfd_MB_t MailboxIndex)
{
    uint32_t           csInfor    = 0U;
    volatile uint32_t *mailboxPtr = Canfd_LL_GetMailboxAddress(Module, MailboxIndex);
    csInfor                       = *mailboxPtr;
    /* reset the code */
    csInfor &= (~CANFD_CS_CODE_MASK);
    /* set abort code */
    csInfor |= ((uint32_t)CANFD_TX_ABORT << (uint32_t)CANFD_CS_CODE_SHIFT) & (uint32_t)CANFD_CS_CODE_MASK;
    /* reload the code */
    *mailboxPtr = csInfor;
}

/**
 * @brief Configure Tx Mailbox for transmission
 *
 * @param Module Pointer to CANFD Module
 * @param MailboxIndex Index of mailbox
 * @param Code Transmission Code
 * @param MsgPtr Pointer to message
 * @return kf_status_t
 * @retval STATUS_OK Success to configure mailbox
 * @retval STATUS_ERROR Failed to configure mailbox
 */
kf_status_t Canfd_LL_SetTxMailbox(
    Canfd_RegisterMap_t *Module, Canfd_MB_t MailboxIndex, Canfd_TxCode_t Code, const Canfd_Msg_t *MsgPtr)
{
    kf_status_t retStatus = STATUS_OK;

    retStatus = Canfd_LL_CheckMailboxValid(Module, (uint32_t)MailboxIndex);

    if (STATUS_OK == retStatus)
    {
        uint32_t               realDlc       = 0U;
        uint32_t               payloadLength = 0U;
        uint8_t const         *dataPtr       = MsgPtr->Data;
        Canfd_MsgInfo_t const *infoPtr       = &MsgPtr->Info;
        uint32_t               databyte      = 0U;

        /* Clean up the arbitration field area */
        /* PRQA S 0759 2 #KQR000759 */
        volatile Canfd_Cs_t csInfor     = {0U};
        volatile Canfd_ID_t mailboxID   = {.reg = 0U};
        volatile uint32_t  *mailboxBase = Canfd_LL_GetMailboxAddress(Module, MailboxIndex);

        volatile Canfd_Cs_t *csInforPtr       = (volatile Canfd_Cs_t *)&mailboxBase[0];
        volatile Canfd_ID_t *mailboxIDPtr     = (volatile Canfd_ID_t *)&mailboxBase[1];
        volatile uint8_t    *mailboxDataPtr   = (volatile uint8_t *)(&mailboxBase[2]);
        volatile uint32_t   *mailboxData32Ptr = (volatile uint32_t *)(&mailboxBase[2]);
        /* PRQA S 3305 1 #KQR003305 */
        const volatile uint32_t *msgData32pPtr = (volatile uint32_t *)MsgPtr->Data;

        /* Make sure the BRS bit will not be ignored */
        if (Canfd_LL_GetFdEnabledState(Module) && (infoPtr->BrsEnable))
        {
            Canfd_LL_SetFdRateSwitch(Module, true);
        }
        else
        { /*Empty*/
        }

        realDlc = Canfd_LL_ComputeDlcValue(infoPtr->DataLength);
        if (NULL_PTR != dataPtr)
        {
            payloadLength = Canfd_LL_GetDataLength(realDlc);
#if (CAN_FEATURE_SWAP_ENABLE == true)
            /** Enable endian swap */
            mailboxData32Ptr = (volatile uint32_t *)((uint32_t)mailboxData32Ptr | (1UL << 14U));
            mailboxDataPtr   = (volatile uint8_t *)((uint32_t)mailboxDataPtr | (1UL << 14U));

            for (databyte = 0U; databyte < ((uint32_t)infoPtr->DataLength & ~3U); databyte += 4U)
            {
                mailboxData32Ptr[databyte >> 2U] = msgData32pPtr[databyte >> 2U];
            }
            for (; databyte < infoPtr->DataLength; databyte++)
            {
                mailboxDataPtr[databyte] = dataPtr[databyte];
            }
            /* Add padding, if needed */
            for (databyte = infoPtr->DataLength; databyte < payloadLength; databyte++)
            {
                mailboxDataPtr[databyte] = infoPtr->FdPadding;
            }
#else
            for (databyte = 0U; databyte < ((uint32_t)infoPtr->DataLength & ~3U); databyte += 4U)
            {
                Canfd_LL_SwapBytesInWord(
                    (void *)&mailboxData32Ptr[databyte >> 2U], (const void *)&msgData32pPtr[databyte >> 2U]);
            }
            for (; databyte < infoPtr->DataLength; databyte++)
            {
                mailboxDataPtr[SwapBytesInWordIndex(databyte)] = dataPtr[databyte];
            }
            /* Add padding, if needed */
            for (databyte = infoPtr->DataLength; databyte < payloadLength; databyte++)
            {
                mailboxDataPtr[SwapBytesInWordIndex(databyte)] = infoPtr->FdPadding;
            }
#endif
        }
        else
        { /*Empty*/
        }

        if (CANFD_MSG_ID_EXT == infoPtr->IDType)
        {
            /* ID [28-0] */
            mailboxID.EFF.ID = infoPtr->MsgID;
            /* Set IDE */
            csInfor.IDE = (uint32_t)1;
            /* Clear SRR bit */
            csInfor.SRR = (uint32_t)0;
        }
        else if (CANFD_MSG_ID_STD == infoPtr->IDType)
        {
            /* ID[28-18] */
            mailboxID.SFF.ID = infoPtr->MsgID;
            /* make sure IDE and SRR are not set */
            csInfor.IDE = (uint32_t)0;
            csInfor.SRR = (uint32_t)0;
        }
        else
        { /*Empty*/
        }
        /** Write ID to mailbox */
        mailboxIDPtr->reg = mailboxID.reg;

        /* Set the length of data in bytes */
        csInfor.DLC = realDlc;
        /* Set MB CODE */
        if (CANFD_TX_NOTUSED != Code)
        {
            if (CANFD_TX_REMOTE == Code)
            {
                csInfor.RTR = (uint32_t)1;
            }
            else
            { /*Empty*/
            }
            /* Set the code */
            if (infoPtr->IsCanfd)
            {
                csInfor.EDL = (uint32_t)1;
            }
            else
            { /*Empty*/
            }
            if (infoPtr->BrsEnable)
            {
                csInfor.BRS = (uint32_t)1;
            }
            else
            { /*Empty*/
            }
            csInfor.CODE = (uint32_t)Code;
            /** Write Code to mailbox */
            csInforPtr->CS_CODE = csInfor.CS_CODE;
        }
        else
        { /*Empty*/
        }
    }
    else
    { /*Empty*/
    }
    return retStatus;
}

/**
 * @brief
 *
 * @param Module
 * @param MailboxIndex
 * @param Code
 * @param MsgInfoPtr
 * @return kf_status_t
 */
kf_status_t Canfd_LL_SetRxMailbox(
    Canfd_RegisterMap_t *Module, Canfd_MB_t MailboxIndex, Canfd_RxCode_t Code, const Canfd_MsgInfo_t *MsgInfoPtr)
{
    kf_status_t retStatus = STATUS_OK;

    retStatus = Canfd_LL_CheckMailboxValid(Module, (uint32_t)MailboxIndex);

    if (STATUS_OK == retStatus)
    {
        /* Clean up the arbitration field area */
        /* PRQA S 0759 2 #KQR000759 */
        volatile Canfd_Cs_t csInfor     = {0U};
        volatile Canfd_ID_t mailboxID   = {.reg = 0U};
        volatile uint32_t  *mailboxBase = Canfd_LL_GetMailboxAddress(Module, MailboxIndex);

        volatile Canfd_Cs_t *csInforPtr   = (volatile Canfd_Cs_t *)&mailboxBase[0];
        volatile Canfd_ID_t *mailboxIDPtr = (volatile Canfd_ID_t *)&mailboxBase[1];

        if (CANFD_MSG_ID_EXT == MsgInfoPtr->IDType)
        {
            /* ID [28-0] */
            mailboxID.EFF.ID = MsgInfoPtr->MsgID;
            /* Set IDE */
            csInfor.IDE = (uint32_t)1;
            /* Clear SRR bit */
            csInfor.SRR = (uint32_t)0;
        }
        else if (CANFD_MSG_ID_STD == MsgInfoPtr->IDType)
        {
            /* ID[28-18] */
            mailboxID.SFF.ID = MsgInfoPtr->MsgID;
            /* make sure IDE and SRR are not set */
            csInfor.IDE = (uint32_t)0;
            csInfor.SRR = (uint32_t)0;
        }
        else
        { /*Empty*/
        }
        /** Write ID to mailbox */
        mailboxIDPtr->reg = mailboxID.reg;

        if (CANFD_RX_NOTUSED != Code)
        {
            /* Set the code */
            csInfor.CODE = (uint32_t)Code;
        }
        else
        { /*Empty*/
        }
        /** Write Code to mailbox */
        csInforPtr->CS_CODE = csInfor.CS_CODE;
    }
    else
    { /*Empty*/
    }
    return retStatus;
}

/**
 * @brief Read RX FIFO
 * @note Buffer for reading Rx Fifo is required to be 64 bytes
 *
 * @param Module Pointer to the CANFD module
 * @param MsgPtr Pointer to the message buffer
 * @return void
 */
void Canfd_LL_ReadRxFifo(const Canfd_RegisterMap_t *Module, Canfd_Msg_t *MsgPtr)
{
    uint32_t databyte = 0U;
    uint32_t csWord   = 0U;
#if (CAN_FEATURE_SWAP_ENABLE == false)
    uint32_t mbWord = 0U;
#endif

    Canfd_MsgInfo_t           *infoPtr        = &MsgPtr->Info;
    const volatile uint32_t   *mailboxBase    = &Module->RAMn[0];
    const volatile Canfd_Cs_t *csInforPtr     = (const volatile Canfd_Cs_t *)&mailboxBase[0];
    const volatile Canfd_ID_t *mailboxIDPtr   = (const volatile Canfd_ID_t *)&mailboxBase[1];
    volatile const uint32_t   *mailboxDataPtr = &mailboxBase[2];
    /* PRQA S 3305 1 #KQR003305 */
    uint32_t *msgData32Ptr = (uint32_t *)(MsgPtr->Data);

    csWord           = csInforPtr->CS_CODE;
    uint32_t realDlc = (csWord & CANFD_CS_DLC_MASK) >> CANFD_CS_DLC_SHIFT;

    infoPtr->DataLength = (uint8_t)Canfd_LL_GetDataLength(realDlc);
    if (0U != (csWord & CANFD_CS_IDE_MASK))
    {
        /* extend frame format */
        infoPtr->MsgID  = mailboxIDPtr->reg;
        infoPtr->IDType = CANFD_MSG_ID_EXT;
    }
    else
    {
        /* standard frame format */
        infoPtr->MsgID  = (mailboxIDPtr->reg) >> CANFD_ID_STD_SHIFT;
        infoPtr->IDType = CANFD_MSG_ID_STD;
    }
    if (0U != (csWord & CANFD_CS_RTR_MASK))
    {
        infoPtr->IsRemote = true;
    }
    else
    {
        infoPtr->IsRemote = false;
    }
    if (0U != (csWord & CANFD_CS_EDL_MASK))
    {
        infoPtr->IsCanfd = true;
    }
    else
    {
        infoPtr->IsCanfd = false;
    }
    if (0U != (csWord & CANFD_CS_BRS_MASK))
    {
        infoPtr->BrsEnable = true;
    }
    else
    {
        infoPtr->BrsEnable = false;
    }
#if (CAN_FEATURE_SWAP_ENABLE == true)
    /**Enable endian swap */
    mailboxDataPtr = (volatile const uint32_t *)((uint32_t)mailboxDataPtr | (1UL << 14U));

    /* Copy MB[0] data field into user's buffer */
    for (databyte = 0U; databyte < infoPtr->DataLength; databyte += 4U)
    {
        msgData32Ptr[databyte >> 2U] = mailboxDataPtr[databyte >> 2U];
    }
#else
    /* Copy MB[0] data field into user's buffer */
    for (databyte = 0U; databyte < infoPtr->DataLength; databyte += 4U)
    {
        mbWord = mailboxDataPtr[databyte >> 2U];
        Canfd_LL_SwapBytesInWord(&msgData32Ptr[databyte >> 2U], &mbWord);
    }
#endif
}

/**
 * @brief Get Rx FIFO mask
 *
 * @param IDType ID type, standard ID or extended ID
 * @param FormatType Rx FIFO ID Format, see @ref Canfd_NormalRxFifoIDFormat_t
 * @param Mask The 11-bit standard mask or the 29-bit extended mask
 * @note bit30 can be used to set mask of IDE
 * @note bit31 can be used to set mask of RTR
 * @return uint32_t Mask start at the high byte
 */
uint32_t Canfd_LL_GetRxFifoMask(Canfd_IDType_t IDType, Canfd_NormalRxFifoIDFormat_t FormatType, uint32_t Mask)
{
    volatile uint32_t val = 0;
    switch (FormatType)
    {
    case CANFD_RX_FIFO_ID_FORMAT_A:
        /* Set RTR bit encoded as bit 31 and IDE bit encoded as bit 30 in mask */
        val = Mask & (1UL << CANFD_FORMAT_AB_RTR_SHIFT);
        if (CANFD_MSG_ID_STD == IDType)
        {
            /* Set standard global mask for RX FIFO and IDE will be 1 and check the FIFO filter ide */
            val |= ((Mask << CANFD_FORMAT_A_STD_SHIFT) & CANFD_FORMAT_A_STD_MASK);
        }
        else if (CANFD_MSG_ID_EXT == IDType)
        {
            val |= (Mask & (1UL << CANFD_FORMAT_AB_IDE_SHIFT));
            /* Set extended global mask for RX FIFO and IDE will be 0 and don't check the FIFO filter ide */
            val |= ((Mask << CANFD_FORMAT_A_EXT_SHIFT) & CANFD_FORMAT_A_EXT_MASK);
        }
        else
        {
            /* Empty */
        }
        break;
    case CANFD_RX_FIFO_ID_FORMAT_B:
        /* Set RTR bit encoded as bit 31 and IDE bit encoded as bit 30 in mask */
        val = Mask & (1UL << CANFD_FORMAT_AB_RTR_SHIFT);
        if (CANFD_MSG_ID_STD == IDType)
        {
            /* Set standard global mask for RX FIFO  */
            val |= ((Mask & CANFD_FORMAT_B_STD_MASK) << CANFD_FORMAT_B_STD_SHIFT1);
        }
        else if (CANFD_MSG_ID_EXT == IDType)
        {
            val |= (Mask & (1UL << CANFD_FORMAT_AB_IDE_SHIFT));
            /* Set extended global mask for RX FIFO  */
            val |= ((Mask & CANFD_FORMAT_B_EXT_MASK) << CANFD_FORMAT_B_EXT_SHIFT1);
        }
        else
        {
            /* Empty */
        }
        break;
    case CANFD_RX_FIFO_ID_FORMAT_C:
        if ((CANFD_MSG_ID_EXT == IDType) || (CANFD_MSG_ID_STD == IDType))
        {
            val |= ((Mask & CANFD_FORMAT_C_MASK) << CANFD_FORMAT_C_SHIFT1);
        }
        else
        {
            /* Empty */
        }
        break;
    case CANFD_RX_FIFO_ID_FORMAT_D:
        break;
    default:
        /* Intentionally Empty */
        break;
    }
    return val;
}

/**
 * @brief Set normal RX FIFO filters
 *
 * @param Module Pointer to the CANFD module
 * @param IDFormat Rx FIFO ID Format, see @ref Canfd_NormalRxFifoIDFormat_t
 * @param IDFilterTablePtr Pointer to the filter table
 * @return void
 */
void Canfd_LL_SetNormalRxFifoFilter(
    Canfd_RegisterMap_t *Module, Canfd_NormalRxFifoIDFormat_t IDFormat, const Canfd_Filter_t *IDFilterTablePtr)
{
    /* PRQA S 0404 ++ #KQR000404 */

    volatile uint32_t val1        = 0U;
    uint32_t          filterIndex = 0U;

    volatile uint32_t *filterTablePtr = &Module->RAMn[CANFD_NORMAL_RX_FIFO_FILTER_TABLE_OFFSET];
    volatile uint32_t  filterNumber   = (uint32_t)Canfd_LL_GetNormalFifoFilterNumber(Module);
    filterNumber                      = (filterNumber + 1U) << 3U;

    Canfd_LL_SetNormalRxFifoIDFormat(Module, IDFormat);

    switch (IDFormat)
    {
    case CANFD_RX_FIFO_ID_FORMAT_A: {
        for (filterIndex = 0U; filterIndex < filterNumber; filterIndex++)
        {
            val1 = 0U;
            if (IDFilterTablePtr[filterIndex].IsRemoteFrame)
            {
                val1 = (uint32_t)CAFND_RX_FIFO_ACCEPT_RTR_FRAME << (uint32_t)CANFD_FORMAT_AB_RTR_SHIFT;
            }
            else
            {
                /*Empty*/
            }
            if (IDFilterTablePtr[filterIndex].IsExtendedFrame)
            {
                val1 |= (uint32_t)CAFND_RX_FIFO_ACCEPT_EXT_FRAME << (uint32_t)CANFD_FORMAT_AB_IDE_SHIFT;
                filterTablePtr[filterIndex] =
                    val1 + ((IDFilterTablePtr[filterIndex].ID << CANFD_FORMAT_A_EXT_SHIFT) & CANFD_FORMAT_A_EXT_MASK);
            }
            else
            {
                filterTablePtr[filterIndex] =
                    val1 + ((IDFilterTablePtr[filterIndex].ID << CANFD_FORMAT_A_STD_SHIFT) & CANFD_FORMAT_A_STD_MASK);
            }
        }
    }
    break;
    case CANFD_RX_FIFO_ID_FORMAT_B: {
        Canfd_LL_SetNormalRxFifoFilterFormatB(filterTablePtr, filterNumber, IDFilterTablePtr);
    }
    break;
    case CANFD_RX_FIFO_ID_FORMAT_C: {
        Canfd_LL_SetNormalRxFifoFilterFormatC(filterTablePtr, filterNumber, IDFilterTablePtr);
    }
    break;
    case CANFD_RX_FIFO_ID_FORMAT_D:
        break;
    default:
        /*Empty*/
        break;
    }
    /* PRQA S 0404 -- #KQR000404 */
}

/**
 * @brief Get mailbox data
 *
 * @param Module Pointer to the module
 * @param MBIndex Mailbox index
 * @param MsgPtr Pointer to the message
 * @return kf_status_t
 * @retval STATUS_OK Success to get data
 * @retval STATUS_ERROR Failed to get data
 */
kf_status_t Canfd_LL_GetMailboxData(Canfd_RegisterMap_t *Module, Canfd_MB_t MBIndex, Canfd_Msg_t *MsgPtr)
{
    kf_status_t retStatus     = STATUS_OK;
    uint32_t    i             = 0U;
    uint32_t    payloadLength = 0U;

    Canfd_MsgInfo_t           *infoPtr         = &MsgPtr->Info;
    volatile uint32_t const   *mailboxBase     = Canfd_LL_GetMailboxAddress(Module, MBIndex);
    volatile Canfd_Cs_t const *csInforPtr      = (volatile Canfd_Cs_t const *)&mailboxBase[0];
    volatile Canfd_ID_t const *mailboxIDPtr    = (volatile Canfd_ID_t const *)&mailboxBase[1];
    volatile uint32_t const   *mailboxDataPtr  = &mailboxBase[2];
    volatile const uint8_t    *mailboxData8Ptr = (volatile const uint8_t *)&mailboxBase[2];
    /* PRQA S 3305 1 #KQR003305 */
    uint32_t *msgData32Ptr = (uint32_t *)(MsgPtr->Data);

    uint32_t csWord     = csInforPtr->CS_CODE;
    uint32_t realDlc    = (csWord & CANFD_CS_DLC_MASK) >> CANFD_CS_DLC_SHIFT;
    payloadLength       = Canfd_LL_GetDataLength(realDlc);
    infoPtr->DataLength = (uint8_t)payloadLength;

    /* Check if RX Mailbox is enabled */
    retStatus = Canfd_LL_CheckMailboxValid(Module, (uint32_t)MBIndex);

    if (STATUS_OK == retStatus)
    {
        /* Get a mailbox field values */
        if ((csWord & CANFD_CS_IDE_MASK) != 0U)
        {
            /* extend frame format */
            infoPtr->MsgID  = mailboxIDPtr->reg;
            infoPtr->IDType = CANFD_MSG_ID_EXT;
        }
        else
        {
            /* standard frame format */
            infoPtr->MsgID  = (mailboxIDPtr->reg) >> CANFD_ID_STD_SHIFT;
            infoPtr->IDType = CANFD_MSG_ID_STD;
        }
        if (0U != (csWord & CANFD_CS_RTR_MASK))
        {
            infoPtr->IsRemote = true;
        }
        else
        {
            infoPtr->IsRemote = false;
        }
        if (0U != (csWord & CANFD_CS_EDL_MASK))
        {
            infoPtr->IsCanfd = true;
        }
        else
        {
            infoPtr->IsCanfd = false;
        }
        if (0U != (csWord & CANFD_CS_BRS_MASK))
        {
            infoPtr->BrsEnable = true;
        }
        else
        {
            infoPtr->BrsEnable = false;
        }
#if (CAN_FEATURE_SWAP_ENABLE == true)
        /**Enable endian swap */
        mailboxDataPtr  = (volatile uint32_t const *)((uint32_t)mailboxDataPtr | (1UL << 14U));
        mailboxData8Ptr = (volatile uint8_t const *)((uint32_t)mailboxData8Ptr | (1UL << 14U));

        for (i = 0U; i < (payloadLength & ~3U); i += 4U)
        {
            msgData32Ptr[i >> 2U] = mailboxDataPtr[i >> 2U];
        }
        for (; i < payloadLength; i++)
        { /* Max allowed value for index is 63 */
            MsgPtr->Data[i] = mailboxData8Ptr[i];
        }
#else
        for (i = 0U; i < (payloadLength & ~3U); i += 4U)
        {
            Canfd_LL_SwapBytesInWord((void *)&msgData32Ptr[i >> 2U], (void *)&mailboxDataPtr[i >> 2U]);
        }
        for (; i < payloadLength; i++)
        { /* Max allowed value for index is 63 */
            MsgPtr->Data[i] = mailboxData8Ptr[SwapBytesInWordIndex(i)];
        }
#endif
    }
    else
    { /*Empty*/
    }

    return retStatus;
}

/**
 * @brief Lock the Rx mailbox
 *
 * @param Module Pointer to the module
 * @param MBIndex Mailbox index
 */
void Canfd_LL_LockRxMailBox(Canfd_RegisterMap_t *Module, Canfd_MB_t MBIndex)
{
    const volatile uint32_t *mailboxPtr = Canfd_LL_GetMailboxAddress(Module, MBIndex);
    /* Lock the mailbox by reading it */
    (void)*mailboxPtr;
}

/**
 * @brief
 *
 * @param Module
 * @param MBIndex
 */
void Canfd_LL_ResetRxMailbox(Canfd_RegisterMap_t *Module, Canfd_MB_t MBIndex)
{
    volatile uint32_t csInfo = 0;
    uint32_t          code   = (uint32_t)CANFD_RX_INACTIVE;

    volatile uint32_t *mailBoxPtr = Canfd_LL_GetMailboxAddress(Module, MBIndex);
    csInfo                        = *mailBoxPtr;
    /* Reset the code and unlock the MB */
    csInfo &= (~CANFD_CS_CODE_MASK);
    csInfo |= ((code << (uint32_t)CANFD_CS_CODE_SHIFT) & (uint32_t)CANFD_CS_CODE_MASK);
    *mailBoxPtr = csInfo;

    /* Reconfigure The MB as left by RxMBconfig */
    code = (uint32_t)CANFD_RX_EMPTY;
    csInfo &= (~(uint32_t)CANFD_CS_CODE_MASK);
    csInfo |= (code << CANFD_CS_CODE_SHIFT) & CANFD_CS_CODE_MASK;
    *mailBoxPtr = csInfo;
}

/**
 * @brief Disable memory error detection
 *
 * @param Module Pointer to the module
 */
void Canfd_LL_DisableMemErrorDetection(Canfd_RegisterMap_t *Module)
{
    Canfd_LL_SetErrorCorrectConfigurationEnable(Module, true);
    Canfd_LL_EnterHaltIfErrorNonCorrect(Module, false);
    Canfd_LL_SetErrorCorrectIntrEnabled(Module, CANFD_MECR_CEI_ALL_MASK, false);
    Canfd_LL_SetErrorCorrectConfigurationEnable(Module, false);
}

/**
 * @brief Configure controller depending on options
 *
 * @param Module Pointer to the module
 * @param Options Options. Value can be as follow MACROS:
 * CANFD_OPTIONS_REMOTE_STORE
 * CANFD_OPTIONS_BUSOFF_RECOVERY
 * CANFD_OPTIONS_PROTOCOL_EXCEPTION
 * CANFD_OPTIONS_EDGE_FILTER
 * CANFD_OPTIONS_ISO
 * CANFD_OPTIONS_EACEN
 */
void Canfd_LL_ConfigControllerByOptions(Canfd_RegisterMap_t *Module, uint32_t Options)
{
    /** Set ISOCANFD mode */
    if ((Options & CANFD_OPTIONS_ISO) != 0U)
    {
        Canfd_LL_SetIsoMode(Module, true);
    }
    else
    {
        Canfd_LL_SetIsoMode(Module, false);
    }
    /** Set Remote Frame Arbitration Field Comparison. */
    if ((Options & CANFD_OPTIONS_EACEN) != 0U)
    {
        Canfd_LL_SetRemoteFrameFilterEnabled(Module, true);
    }
    else
    {
        Canfd_LL_SetRemoteFrameFilterEnabled(Module, false);
    }
    /** Set Protocol Exception Enabled */
    if ((Options & CANFD_OPTIONS_PROTOCOL_EXCEPTION) != 0U)
    {
        Canfd_LL_SetProtocolExceptionEnabled(Module, true);
    }
    else
    {
        Canfd_LL_SetProtocolExceptionEnabled(Module, false);
    }
    /** Set AutoBusOff Recovery */
    if ((Options & CANFD_OPTIONS_BUSOFF_RECOVERY) != 0U)
    {
        Canfd_LL_SetHardwareBusoffRecoveryEnabled(Module, true);
    }
    else
    {
        Canfd_LL_SetHardwareBusoffRecoveryEnabled(Module, false);
    }
    /** Set Remote Request Store */
    if ((Options & CANFD_OPTIONS_REMOTE_STORE) != 0U)
    {
        Canfd_LL_SetRemoteRequestStoreEnabled(Module, true);
    }
    else
    {
        Canfd_LL_SetRemoteRequestStoreEnabled(Module, false);
    }
    /** Set Edge Filter */
    if ((Options & CANFD_OPTIONS_EDGE_FILTER) != 0U)
    {
        Canfd_LL_SetEdgeFilterEnabled(Module, true);
    }
    else
    {
        Canfd_LL_SetEdgeFilterEnabled(Module, false);
    }
}

/**
 * @brief
 *
 * @param Module
 * @param MsgPtr
 */
void Canfd_LL_ReadEnhancedRxFifo(const Canfd_RegisterMap_t *Module, Canfd_Msg_t *MsgPtr)
{
    uint32_t databyte = 0U;
    uint32_t csWord   = 0U;
#if (CAN_FEATURE_SWAP_ENABLE == false)
    uint32_t mbWord = 0U;
#endif

    Canfd_MsgInfo_t         *infoPtr = &MsgPtr->Info;
    const volatile uint32_t *mailboxBase =
        (volatile uint32_t *)((uint32_t)Module + (uint32_t)CANFD_ENHANCED_RX_FIFO_RAM_OFFSET);
    const volatile Canfd_Cs_t *csInforPtr     = (const volatile Canfd_Cs_t *)&mailboxBase[0];
    const volatile Canfd_ID_t *mailboxIDPtr   = (const volatile Canfd_ID_t *)&mailboxBase[1];
    volatile const uint32_t   *mailboxDataPtr = &mailboxBase[2];
    /* PRQA S 3305 1 #KQR003305 */
    uint32_t *msgData32Ptr = (uint32_t *)(MsgPtr->Data);

    csWord              = csInforPtr->CS_CODE;
    uint32_t realDlc    = (csWord & CANFD_CS_DLC_MASK) >> CANFD_CS_DLC_SHIFT;
    infoPtr->DataLength = (uint8_t)Canfd_LL_GetDataLength(realDlc);

    if (0U != (csWord & CANFD_CS_IDE_MASK))
    {
        /* extend frame format */
        infoPtr->MsgID  = mailboxIDPtr->reg;
        infoPtr->IDType = CANFD_MSG_ID_EXT;
    }
    else
    {
        /* standard frame format */
        infoPtr->MsgID  = (mailboxIDPtr->reg) >> CANFD_ID_STD_SHIFT;
        infoPtr->IDType = CANFD_MSG_ID_STD;
    }
    if (0U != (csWord & CANFD_CS_RTR_MASK))
    {
        infoPtr->IsRemote = true;
    }
    else
    {
        infoPtr->IsRemote = false;
    }
    if (0U != (csWord & CANFD_CS_EDL_MASK))
    {
        infoPtr->IsCanfd = true;
    }
    else
    {
        infoPtr->IsCanfd = false;
    }
    if (0U != (csWord & CANFD_CS_BRS_MASK))
    {
        infoPtr->BrsEnable = true;
    }
    else
    {
        infoPtr->BrsEnable = false;
    }
#if (CAN_FEATURE_SWAP_ENABLE == true)
    /**Enable endian swap */
    mailboxDataPtr = (volatile const uint32_t *)((uint32_t)mailboxDataPtr | (1UL << 14U));

    /* Copy MB[0] data field into user's buffer */
    for (databyte = 0U; databyte < infoPtr->DataLength; databyte += 4U)
    {
        msgData32Ptr[databyte >> 2U] = mailboxDataPtr[databyte >> 2U];
    }
#else
    /* Copy MB[0] data field into user's buffer */
    for (databyte = 0U; databyte < infoPtr->DataLength; databyte += 4U)
    {
        mbWord = mailboxDataPtr[databyte >> 2U];
        Canfd_LL_SwapBytesInWord(&msgData32Ptr[databyte >> 2U], &mbWord);
    }
#endif
}

/* EOF */
