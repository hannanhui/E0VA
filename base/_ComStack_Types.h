/******************************************************************************
 *                  Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : ComStack_Types.h
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
#ifndef COMSTACK_TYPES_H
#define COMSTACK_TYPES_H

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
 */

/******************************************************************************
 **                                                  QAC Warnings
 ******************************************************************************/
/**
 * @page QAC Warnings
 *
 */
/******************************************************************************
 **                                                         Include Files
 ******************************************************************************/
#include "ComStack_Cfg.h"
#include "Std_Types.h"

/******************************************************************************
 **                      File Version Check
 ******************************************************************************/

/******************************************************************************
 **                      Macro  Definitions
 ******************************************************************************/
/**
 * @brief  Action has been successfully finished
 * @details   General return codes for NotifResultType
 * @implements DBASE02011
 */
#define NTFRSLT_OK 0x00U

/**
 * @brief  Message not successfully received or sent out
 * @details   General return codes for NotifResultType
 * @implements DBASE02011
 */
#define NTFRSLT_E_NOT_OK 0x01U

/**
 * @brief  Timer N_Ar/N_As has passed its time-out value N_Asmax/N_Armax
 * @details   General return codes for NotifResultType
 * @implements DBASE02011
 */
#define NTFRSLT_E_TIMEOUT_A 0x02U

/**
 * @brief  Timer N_Bs has passed its time-out value N_Bsmax
 * @details   General return codes for NotifResultType
 * @implements DBASE02011
 */
#define NTFRSLT_E_TIMEOUT_BS 0x03U

/**
 * @brief  Timer N_Cr has passed its time-out value N_Crmax
 * @details   General return codes for NotifResultType
 * @implements DBASE02011
 */
#define NTFRSLT_E_TIMEOUT_CR 0x04U

/**
 * @brief  Unexpected sequence number (PCI.SN) value received
 * @details   General return codes for NotifResultType
 * @implements DBASE02011
 */
#define NTFRSLT_E_WRONG_SN 0x05U

/**
 * @brief  Invalid or unknown FlowStatus value has been received
 * @details   General return codes for NotifResultType
 * @implements DBASE02011
 */
#define NTFRSLT_E_INVALID_FS 0x06U

/**
 * @brief  Unexpected protocol data unit received
 * @details   General return codes for NotifResultType
 * @implements DBASE02011
 */
#define NTFRSLT_E_UNEXP_PDU 0x07U

/**
 * @brief  Flow control WAIT frame that exceeds the maximum counter N_WFTmax
 * received
 * @details   General return codes for NotifResultType
 * @implements DBASE02011
 */
#define NTFRSLT_E_WFT_OVRN 0x08U

/**
 * @brief  Flow control (FC) N_PDU with FlowStatus = OVFLW received
 * @details   General return codes for NotifResultType
 * @implements DBASE02011
 */
#define NTFRSLT_E_ABORT 0x09U

/**
 * @brief  Indicates an abort of a transmission.
 * @details   General return codes for NotifResultType
 * @implements DBASE02011
 */
#define NTFRSLT_E_NO_BUFFER 0x0AU

/**
 * @brief  Requested cancellation has been executed
 * @details   General return codes for NotifResultType
 * @implements DBASE02011
 */
#define NTFRSLT_E_CANCELATION_OK 0x0BU

/**
 * @brief  Request cancellation has not been executed
 *         Due to an internal error the requested cancellation has not been
 * executed. This will happen e.g. if the to be canceled transmission has been
 * executed already.
 * @details   General return codes for NotifResultType
 * @implements DBASE02011
 */
#define NTFRSLT_E_CANCELATION_NOT_OK 0x0CU

/**
 * @brief  The parameter change request has been successfully executed
 * @details   General return codes for NotifResultType
 * @implements DBASE02011
 */
#define NTFRSLT_PARAMETER_OK 0x0DU

/**
 * @brief  The request for the change of the parameter did not complete
 * successfully
 * @details   General return codes for NotifResultType
 * @implements DBASE02011
 */
#define NTFRSLT_E_PARAMETER_NOT_OK 0x0EU

/**
 * @brief  The parameter change request not executed successfully due to an
 * ongoing reception
 * @details   General return codes for NotifResultType
 * @implements DBASE02011
 */
#define NTFRSLT_E_RX_ON 0x0FU

/**
 * @brief  The parameter change request not executed successfully due to a wrong
 * value
 * @details   General return codes for NotifResultType
 * @implements DBASE02011
 */
#define NTFRSLT_E_VALUE_NOT_OK 0x10U

/**
 * @brief   There is no bus transceiver error seen or transceiver does not
 * support the detection of bus errors
 * @details   General return codes for BusTrcvErrorType
 * @implements DBASE02012
 */
#define BUSTRCV_OK 0x00U

/**
 * @brief BUSTRCV_E_OK needed by FrTrcv specification inconcistency between ComStackTypes and FrTrcv
 */
#define BUSTRCV_E_OK 0x00U

/**
 * @brief  Bus transceiver detected an unclassified error
 * @details   General return codes for BusTrcvErrorType
 * @implements DBASE02012
 */
#define BUSTRCV_E_ERROR 0x01U

/******************************************************************************
 **                      Typedef  Definitions
 ******************************************************************************/
/**
 * @brief Variables of this type are used to store the result of a buffer
 * request.
 * @implements DBASE02009
 */
typedef enum
{
    BUFREQ_OK,       /**< @brief Buffer request accomplished successful */
    BUFREQ_E_NOT_OK, /**< @brief Buffer request not successful. Buffer
                            cannot be accessed */
    BUFREQ_E_BUSY,   /**< @brief Temporarily no buffer available. It's up the
                      * requestor to retry request for a certain time. */
    BUFREQ_E_OVFL    /**< @brief No Buffer of the required length can be provided */
} BufReq_ReturnType;

/**
 * @brief Variables of this type shall be used to store the state of TP buffer.
 * @implements DBASE02010
 */
typedef enum
{
    TP_DATACONF,    /**< @brief Indicates that all data, that have been copied so far,
                     * are c confirmed and can be removed from the TP buffer. */
    TP_DATARETRY,   /**< @brief Indicates that this API call shall copy already
                     * copied data in order to recover from an error */
    TP_CONFPENDING, /**< @brief Indicates that the previously copied data
                     * must remain in the TP
                     */
    TP_NORETRY      /**< @brief Indicate that the copied transmit data can be
                     * removed from the      buffer after it has been copied */
} TpDataStateType;

/**
 * @brief Specify the parameter to which the value has to be changed (BS or
 * STmin)
 * @implements DBASE02008
 */
typedef enum
{
    TP_STMIN, /**< @brief Separation Time */
    TP_BS,    /**< @brief Block Size */
    TP_BC     /**<Band width control parameter used in FlexRay transport
                        protocol     module */
} TPParameterType;

/**
 * @brief IcomSwitch_ErrorType defines the errors which can occur when activating or deactivating Pretended Networking
 * @implements IcomSwitch_ErrorType_type
 */
typedef enum
{
    ICOM_SWITCH_E_OK,    /**< @brief The activation of Pretended Networking was successful */
    ICOM_SWITCH_E_FAILED /**< @brief The activation of Pretended Networking was not successful */
} IcomSwitch_ErrorType;

/**
 * @brief Variables of this type are used to store the result status of a
 * notification (confirmation or indication).
 * @implements DBASE02003
 */
typedef uint8 NotifResultType;

/**
 * @brief Variables of this type are used to return the bus status evaluated by
 * a transceiver.
 * @implements DBASE02005
 */
typedef uint8 BusTrcvErrorType;

/**
 * @brief   Variables of the type NetworkHandleType are used to store the
 * identifier of a communication channel.
 * @implements DBASE02004
 */
typedef uint8 NetworkHandleType;

typedef uint8 PNCHandleType; /* Necessary for partial network */

typedef P2VAR(uint8, AUTOMATIC, TYPEDEF) SduDataPtrType;

typedef struct
{
    SduDataPtrType SduDataPtr; /**< pointer to the SDU (i.e. payload data) of the PDU */

    SduDataPtrType MetaDataPtr; /**< pointer to the meta data of the PDU */

    PduLengthType SduLength; /**< length of the SDU in bytes */
} PduInfoType;

/**
 * @brief Variables of this type shall be used to store the information about Tp
 * buffer handling.
 * @implements DBASE02007
 */
typedef struct
{
    TpDataStateType TpDataState; /**< The enum type to be used to store the
                                    state of Tp buffer */
    PduLengthType TxTpDataCnt;   /**< length of the SDU in bytes */
} RetryInfoType;
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
