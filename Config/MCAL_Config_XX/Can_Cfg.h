/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Can_Cfg.h
 *  @Syntax             : GNU99
 *  @Author             : ChipON AE/FAE Group
 *  @Date            : 2026/3/26 10:58:41
 *  @Version         : V1.0
 *  @Description     : This document describes the C language document template.
 ******************************************************************************
 *  Copyright (C) by Shanghai ChipON Micro-Electronic Co.,Ltd
 *  All rights reserved.
 *
 *  This software is copyright protected and proprietary to
 *  Shanghai ChipON Micro-Electronic Co.,Ltd.
 *****************************************************************************/
#ifndef CAN_CFG_H
#define CAN_CFG_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 **                        Include Files
 ******************************************************************************/
#include "Std_Types.h"
/******************************************************************************
 **                        File Version Check
 ******************************************************************************/

/******************************************************************************
 **                        Macro  Definitions
 ******************************************************************************/

/**
 * @brief Precompile Support
 */
#define CAN_PRECOMPILE_SUPPORT (STD_ON)

/**
 * @brief Switches the development error detection and notification on or off.
 * true: detection and notification is enabled.
 * false: detection and notification is disabled.
 * @implements #ECUC_Can_00064
 */
#define CAN_DEV_ERROR_DETECT (STD_OFF)

/**
 * @brief Specifies the InstanceId of this module instance. If only one instance is present it shall have the Id 0.
 */
#define CAN_INDEX (0U)

/**
 * @brief This parameter describes the period for cyclic call to Can_MainFunction_Mode. Unit is seconds.
 */
#define CAN_MAIN_FUNCTION_MODE_PERIOD (0.005F)

/**
 * @brief Specifies if multiplexed transmission shall be supported.ON or OFF
 */
#define CAN_MULTIPLEXED_TRA_SUPPORT (STD_ON)

/**
 * @brief Selects support of Pretended Network features in Can driver
 */
#define CAN_PUBLIC_ICOM_SUPPORT (STD_OFF)

/**
 * @brief The support of the Can_SetBaudrate API is optional.If this parameter is set to true the Can_SetBaudrate API
 * shall be supported. Otherwise the API is not supported
 * @implements #ECUC_Can_00482
 */
#define CAN_SET_BAUDRATE_API (STD_OFF)

/**
 * @brief Specifies the maximum time for blocking function until a timeout is detected. Unit is seconds.
 */
#define CAN_TIMEOUT_DURATION (1F)

/**
 * @brief Switches the Can_GetVersionInfo() API ON or OFF.
 */
#define CAN_VERSION_INFO_API (STD_OFF)

/**
 * @brief No CanMainFunctionRWPeriods configured.
 */
#define CAN_MAIN_FUNCTION_PERIOD_0 (0.01F)

/**
 * @brief The number of CAN execution polling cycles.
 */
#define CAN_MAIN_FUNCTION_PERIOD_NUM (0U)

/**
 * @brief Support for Wakeup feature.
 * @details This parameter is enabled only for platforms which have wakeup were suppoted. This platform isn't supported
 * Wakeup.
 *
 * not supported
 */
#define CAN_ENABLE_WAKEUP_SUPPORT (STD_OFF)
/******************************************************************************
 **                        Tailoring Config information
 ******************************************************************************/
/**
 * @brief The support of the CanDeInitController API is optional.If this parameter is set to true the
 * CanDeInitController API shall be supported. Otherwise the API is not supported
 * @implements #ECUC_Can_00482
 */
#define CAN_DEINIT_CONTROLLER_API (STD_ON)

/**
 * @brief Support for ABORT Hardware Transmit Handle feature.
 */
#define CAN_API_ENABLE_ABORT_HTH (STD_OFF)

/**
 * @brief Support for transmits Notification
 */
#define CAN_TX_NOTIFICATION (STD_ON)

/**
 * @brief Support for Receive Notification
 */
#define CAN_RX_INDICATION (STD_ON)

/**
 * @brief Support for BusError Notification
 */
#define CAN_ERROR_NOTIFICATION (STD_ON)

/**
 * @brief Support for BusOff Notification
 */
#define CAN_OFF_NOTIFICATION (STD_ON)

/**
 * @brief wakeup status
 *
 * @details not support
 */
#define CAN_WAKEUP_NOTIFICATION (STD_OFF)

/**
 * @brief Enable Busoff Hardware Recovery Function
 */
#define CAN_BUSOFF_HARDWARE_RECOVERY (STD_OFF)

/**
 * @brief Enables/Disables the Global Time APIs used when hardware time stamping is supported by CAN controller.
 *
 * @details not support
 */
#define CAN_GLOBAL_TIME_SUPPORT (STD_OFF)

/**
 * @brief This parameter define whether use FD mode or not
 */
#define CAN_CANFD_MODE (STD_ON)

/**
 * @brief This parameter define whether use FD mode or not
 */
#define CAN_HARDWARE_FILTER (STD_ON)

/**
 * @brief Mask CanIf API , in case use Can Driver without CanIf
 */
#define CAN_MASK_IF_API (STD_OFF)

/**
 * @brief API Compile definition,Need to change with Processing Mode
 */
#define CAN_TXPOLL_SUPPORTED (STD_ON)
#define CAN_RXPOLL_SUPPORTED (STD_ON)
#define CAN_BOPOLL_SUPPORTED (STD_ON)

#define CAN_0_CONTROLLER_ACTIVATION (STD_ON)
#define CAN_1_CONTROLLER_ACTIVATION (STD_OFF)
#define CAN_2_CONTROLLER_ACTIVATION (STD_OFF)
#define CAN_3_CONTROLLER_ACTIVATION (STD_OFF)

#if (CAN_0_CONTROLLER_ACTIVATION == STD_ON)
#define CAN_0_CONTROLLER_ENABLE (1U)
#else
#define CAN_0_CONTROLLER_ENABLE (0U)
#endif

#if (CAN_1_CONTROLLER_ACTIVATION == STD_ON)
#define CAN_1_CONTROLLER_ENABLE (1U)
#else
#define CAN_1_CONTROLLER_ENABLE (0U)
#endif

#if (CAN_2_CONTROLLER_ACTIVATION == STD_ON)
#define CAN_2_CONTROLLER_ENABLE (1U)
#else
#define CAN_2_CONTROLLER_ENABLE (0U)
#endif

#if (CAN_3_CONTROLLER_ACTIVATION == STD_ON)
#define CAN_3_CONTROLLER_ENABLE (1U)
#else
#define CAN_3_CONTROLLER_ENABLE (0U)
#endif

#define CAN_TOTAL_USED_NUMBER                                                                                          \
    (CAN_0_CONTROLLER_ENABLE + CAN_1_CONTROLLER_ENABLE + CAN_2_CONTROLLER_ENABLE + CAN_3_CONTROLLER_ENABLE)

/**
 * @brief Interrupt configure of normal Rx FIFO
 */
#define CAN_NORMAL_RX_FIFO_INTR_OVERFLOW         (STD_ON)
#define CAN_NORMAL_RX_FIFO_INTR_OVERFLOW_WARNING (STD_ON)
#define CAN_NORMAL_RX_FIFO_INTR_VALID_MESSAGE    (STD_ON)

/**
 * @brief Interrupt configure of enhanced Rx FIFO
 *
 * @note The value can be:
 * CAN_ENHANCED_RX_FIFO_UNDERFLOW,
 * CAN_ENHANCED_RX_FIFO_OVERFLOW,
 * CAN_ENHANCED_RX_FIFO_WATER_MARK,
 * CAN_ENHANCED_RX_FIFO_DATA_USEFUL
 */
#define CAN_ENHANCED_RX_FIFO_INTR_MASK ( \
		0U | CAN_ENHANCED_RX_FIFO_OVERFLOW | CAN_ENHANCED_RX_FIFO_WATER_MARK | CAN_ENHANCED_RX_FIFO_DATA_USEFUL \
	)

/******************************************************************************
 **                        Typedef  Definitions
 ******************************************************************************/

/******************************************************************************
 **                        Export Variables
 ******************************************************************************/

/******************************************************************************
 **                        Export Functions
 ******************************************************************************/

#ifdef __cplusplus
}
#endif

#endif
/* EOF */
