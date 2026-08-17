/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Can_GeneralTypes.h
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

#ifndef CAN_GENERAL_TYPES_H
#define CAN_GENERAL_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif
/******************************************************************************
 *                        Include Files                                        *
 ******************************************************************************/
#include "ComStack_Types.h"
/******************************************************************************
 *                      Macro or Inline *
 ******************************************************************************/
/**
 * @brief          CAN Controller State Modes of operation.
 * @details        States that are used by the several ControllerMode functions
 * @implements     Can_Can_ControllerStateType_enumeration
 */
typedef enum
{
    CAN_CS_UNINIT,  /**< @brief CAN controller state UNINIT */
    CAN_CS_STARTED, /**< @brief CAN controller state STARTED */
    CAN_CS_STOPPED, /**< @brief CAN controller state STOPPED */
    CAN_CS_SLEEP    /**< @brief CAN controller state SLEEP */
} Can_ControllerStateType;

/**
 * @brief          CAN Controller State Modes of operation.
 * @details        Error states of a CAN controller
 * @implements     Can_Can_ControllerStateType_enumeration
 */
typedef enum
{
    CAN_ERRORSTATE_ACTIVE,  /**< @brief The CAN controller takes fully part in
                               communication. */
    CAN_ERRORSTATE_PASSIVE, /**< @brief The CAN controller takes part in
                               communication, but does not send active error
                               frames. */
    CAN_ERRORSTATE_BUSOFF   /**< @brief The CAN controller does not take part in
                               communication. */
} Can_ErrorStateType;

/**
 * @brief          CAN Transceiver Wakeup Reason
 * @details        Transceiver Wakeup reason
 * @implements     CanTrcv_TrcvWakeupReasonType_enumeration
 */
typedef enum
{
    CANTRCV_WU_ERROR,
    CANTRCV_WU_NOT_SUPPORTED,
    CANTRCV_WU_BY_BUS,
    CANTRCV_WU_INTERNALLY,
    CANTRCV_WU_RESET,
    CANTRCV_WU_POWER_ON,
    CANTRCV_WU_BY_PIN,
    CANTRCV_WU_BY_SYSERR
} CanTrcv_TrcvWakeupReasonType;

/**
 * @brief          CAN Transceiver Wakeup Mode
 * @details        Transceiver Wakeup reason
 * @implements     CanTrcv_TrcvWakeupReasonType_enumeration
 */
typedef enum
{
    CANTRCV_WUMODE_ENABLE,
    CANTRCV_WUMODE_DISABLE,
    CANTRCV_WUMODE_CLEAR,
} CanTrcv_TrcvWakeupModeType;
#define CAN_EXTENDEDID STD_ON
#ifdef CAN_EXTENDEDID
#if (CAN_EXTENDEDID == STD_ON)
/**
 * @{
 * @brief          Can_IdType
 * @details        Type for storing the Identifier Length Type: Normal or
 * Extended.
 *                   - used by "Can_MessageBufferConfigObjectType" structure.
 *                 The driver does not distinguish between Extended and Mixed
 * transmission modes. Extended transmission mode of operation behaves the same
 * as Mixed mode.
 * @implements     Can_IdType_type
 */
typedef uint32 Can_IdType;
#else
typedef uint16 Can_IdType;
#endif
#else
typedef uint16 Can_IdType;
#endif
/**@}*/

/**
 * @brief          Can_PduType
 * @details        Type used to provide ID, DLC, SDU from CAN interface to CAN
 * driver. HTH or HRH = ID+DLC+SDU.
 * @implements     Can_PduType_structure
 */
typedef struct
{
    VAR(Can_IdType, CAN_VAR)
    id; /**< @brief CAN L-PDU = Data Link Layer Protocol Data Unit.
                                             Consists of Identifier, DLC and
           Data(SDU)  It is uint32 for CAN_EXTENDEDID=STD_ON, else is uint16.
                                             */
    VAR(PduIdType, CAN_VAR)
    swPduHandle; /**< @brief The L-PDU Handle Pduid = defined and placed
                                                     inside the CanIf module
                    layer. Each handle represents an L-PDU, which is a constant
                                                     structure with information
                    for Tx/Rx processing. */
    VAR(uint8, CAN_VAR)
    length; /**< @brief DLC = Data Length Code (part of L-PDU that describes
                                            the SDU length). */
    P2VAR(uint8, CAN_VAR, CAN_APPL_DATA)
    sdu; /**< @brief CAN L-SDU = Link Layer Service Data
                                                          Unit. Data that is
            transported inside the L-PDU. */
} Can_PduType;

#ifdef CAN_MBCOUNTEXTENSION
#if (CAN_MBCOUNTEXTENSION == STD_ON)
/**
* @{
* @brief          Can_HwHandleType
* @details        Represents the hardware object handles of a CAN hardware unit.
              For CAN hardware units with more than 255 HW objects use extended
range.
*                   - used by "Can_Write" function.
*                 The driver does not distinguish between Extended and Mixed
transmission modes.
*                 Extended transmission mode of operation behaves the same as
Mixed mode.
* @implements     Can_HwHandleType_type
*/
typedef uint16 Can_HwHandleType;
#else
typedef uint8 Can_HwHandleType;
#endif
#else
typedef uint16 Can_HwHandleType;
#endif
/**@}*/

/**
* @brief          Can_HwType
* @details        This type defines a data structure which clearly provides an
Hardware Object Handle including its corresponding CAN Controller and therefore
CanDrv as well as the specific CanId.
* @implements     Can_HwType_structure
*/

typedef struct
{
    VAR(Can_IdType, CAN_VAR) CanId; /**< @brief Standard/Extended CAN ID of CAN L-PDU. */

    VAR(Can_HwHandleType, CAN_VAR) Hoh; /**< @brief ID of the corresponding Hardware Object Range */

    VAR(uint8, CAN_VAR)
    ControllerId; /**< @brief ControllerId provided by CanIf clearly identify the corresponding controller */
} Can_HwType;

/* Operating modes of the CAN Transceiver Driver. */
typedef enum
{
    CANTRCV_TRCVMODE_NORMAL, /* Transceiver mode NORMAL */
    CANTRCV_TRCVMODE_SLEEP,  /* Transceiver mode SLEEP */
    CANTRCV_TRCVMODE_STANDBY /*Transceiver mode STANDBY */
} CanTrcv_TrcvModeType;

typedef enum
{
    CANTRCV_FLAG_SET,     /* The flag is set in the transceiver hardware */
    CANTRCV_FLAG_CLEARED, /* The flag is cleared in the transceiver hardware */
} CanTrcv_TrcvFlagStateType;

typedef enum
{
    PN_ENABLED,  /* PN wakeup functionality in CanTrcv is enabled */
    PN_DISABLED, /* PN wakeup functionality in CanTrcv is disabled */
} CanTrcv_PNActivationType;

/* PRQA S 0722 ++ #KQR000722 */
typedef enum
{
    CAN_ERROR_BIT_MONITORING1 = 0x01U, /* A 0 was transmitted and a 1 was read back */
    CAN_ERROR_BIT_MONITORING0,         /* A 1 was transmitted and a 0 was read back */
    CAN_ERROR_BIT,                     /* The HW reports a CAN bit error but cannot report
                                          distinguish between CAN_ERROR_BIT_MONITORING1 and
                                          CAN_ERROR_BIT_MONITORING0k */
    CAN_ERROR_CHECK_ACK_FAILED,        /* Acknowledgement check failed */
    CAN_ERROR_ACK_DELIMITER,           /* Acknowledgement delimiter check failed */
    CAN_ERROR_ARBITRATION_LOST,        /* The sender lost in arbitration. */
    CAN_ERROR_OVERLOAD,                /*CAN overload detected via an overload frame.
                                         Indicates that the receive buffers of a receiver
                                         are full. */
    CAN_ERROR_CHECK_FORM_FAILED,       /* Violations of the fixed frame format */
    CAN_ERROR_CHECK_STUFFING_FAILED,   /* Stuffing bits not as expected */
    CAN_ERROR_CHECK_CRC_FAILED,        /*CRC failed */
    CAN_ERROR_BUS_LOCK,                /* Bus lock (Bus is stuck to dominant level) */
} Can_ErrorType;
/* PRQA S 0722 -- #KQR000722 */
/* Variables of this type are used to express time stamps based on relative time */
typedef struct
{
    uint32 nanoseconds; /*Nanoseconds part of the time*/
    uint32 seconds;     /*Seconds part of the time*/
} Can_TimeStampType;
#ifdef __cplusplus
}
#endif

#endif /*CAN_GENERAL_TYPES_H*/

/** @} */
