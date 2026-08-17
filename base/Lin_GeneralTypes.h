/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Lin_GeneralTypes.h
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
#ifndef LIN_GENERALTYPES_H
#define LIN_GENERALTYPES_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 **                                             MISRA-C Rules Violations
 ******************************************************************************/
/**
 * @page misra_violations MISRA-C:2004 violations
 *
 * @section
 * MISRA RULE 2.3 - A project should not contain unused type declarations
 */

/******************************************************************************
 **                                                  QAC Warnings
 ******************************************************************************/
/**
 * @page QAC Warnings
 *
 */
/* PRQA S 3205 EOF #KQR003205 */
/******************************************************************************
 **                                                         Include Files
 ******************************************************************************/
#include "ComStack_Types.h"

/******************************************************************************
 **                      File Version Check
 ******************************************************************************/

/******************************************************************************
 **                      Typedef  Definitions
 ******************************************************************************/
/**
 * @brief Checksum models for the LIN Frame.
 * @details This type is used to specify the Checksum model to be used for the LIN Frame.
 * @implements #SWS_Lin_00229
 */
typedef enum
{
    /** @brief Enhanced checksum model.*/
    LIN_ENHANCED_CS,
    /** @brief Classic checksum model.*/
    LIN_CLASSIC_CS
} Lin_FrameCsModelType;

/**
 * @brief Frame response types.
 * @details This type is used to specify whether the frame processor is required to transmit the response part of
 * the LIN frame.
 * @implements Lin_FrameResponseType_enumeration
 */
typedef enum
{
    /** @brief Response is generated from this (master) node. */
    LIN_MASTER_RESPONSE,
    /** @brief Response is generated from a remote slave node.*/
    LIN_SLAVE_RESPONSE,
    /** @brief Response is generated from one slave to another slave.*/
    LIN_SLAVE_TO_SLAVE
} Lin_FrameResponseType;

/**
 * @brief LIN Frame and Channel states operation.
 * @details LIN operation states for a LIN channel or frame, as returned by the API service Lin_GetStatus(). part
 * of the LIN frame.
 * @implements Lin_StatusType_enumeration
 */
typedef enum
{
    /** @brief Development or production error occurred.*/
    LIN_NOT_OK,
    /** @brief Successful transmission.*/
    LIN_TX_OK,
    /** @brief Ongoing transmission (Header orResponse).*/
    LIN_TX_BUSY,
    /** @brief Erroneous header transmission such as: Mismatch between sent and read back data. Identifier parity error.
     * Physical bus error. */
    LIN_TX_HEADER_ERROR,
    /** @brief Erroneous transmission such as: Mismatch between sent and read back data. Physical bus error.*/
    LIN_TX_ERROR,
    /** @brief Reception of correct response.*/
    LIN_RX_OK,
    /** @brief Ongoing reception: at least one response byte has been received, but the checksum byte has not been
     * received.*/
    LIN_RX_BUSY,
    /** @brief Erroneous reception such as: Framing error. Overrun error. Checksum error. Short response.*/
    LIN_RX_ERROR,
    /** @brief No response byte has been received so far.*/
    LIN_RX_NO_RESPONSE,
    /** @brief Normal operation; The related LIN channel is ready to transmit next header. No data from previous frame
     * available (e.g. after initialization).*/
    LIN_OPERATIONAL,
    /** @brief Sleep mode operation; In this mode wake-up detection from slave nodes is enabled.*/
    LIN_CH_SLEEP
} Lin_StatusType;

/**
 * @brief Data length of a LIN Frame.
 * @details This type is used to specify the number of SDU data bytes to copy.
 * @implements Lin_FrameDlType_typedef
 */
typedef uint8 Lin_FrameDlType;

/**
 * @brief The LIN identifier (0..0x3F) with its parity bits.
 * @details Represents all valid protected Identifier used by Lin_SendHeader().
 * @implements Lin_FramePidType_typedef
 */
typedef uint8 Lin_FramePidType;

/**
 * @brief The LIN identifier (0..0x3F) with its parity bits.
 * @details This Type is used to provide PID, checksum model, data length and SDU pointer from the LIN Interface to the
 * LIN driver.
 * @implements Lin_PduType_struct
 */
/* PRQA S 3630 ++ #KQR003630 */
typedef struct
{
    /** @brief LIN frame identifier.*/
    Lin_FramePidType Pid;
    /** @brief Checksum model type.*/
    Lin_FrameCsModelType Cs;
    /** @brief Response type.*/
    Lin_FrameResponseType Drc;
    /** @brief Data length.*/
    Lin_FrameDlType Dl;
    /** @brief Pointer to Sdu.*/
    uint8 *SduPtr;
} Lin_PduType;
/* PRQA S 3630 -- #KQR003630 */

typedef enum
{
    LINTRCV_WUMODE_ENABLE,
    LINTRCV_WUMODE_DISABLE,
    LINTRCV_WUMODE_CLEAR
} LinTrcv_TrcvWakeupModeType;

typedef enum
{
    LINTRCV_WU_ERROR,
    LINTRCV_WU_BY_BUS,
    LINTRCV_WU_BY_PIN,
    LINTRCV_WU_INTERNALLY,
    LINTRCV_WU_NOT_SUPPORTED,
    LINTRCV_WU_POWER_ON,
    LINTRCV_WU_RESET,
    LINTRCV_WU_BY_SYSERR
} LinTrcv_TrcvWakeupReasonType;

/******************************************************************************
 **                      Export Variables
 ******************************************************************************/

/******************************************************************************
 **                      Export Functions
 ******************************************************************************/

#ifdef __cplusplus
}
#endif

#endif
/* EOF */
