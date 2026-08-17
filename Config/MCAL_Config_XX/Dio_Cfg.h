/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Dio_Cfg.h
 *  @Syntax             : GNU99
 *  @Author             : ChipON AE/FAE Group
 *  @Date            : 2026/3/10 13:22:24
 *  @Version         : V1.0
 *  @Description     : This document describes the C language document template.
 ******************************************************************************
 *  Copyright (C) by Shanghai ChipON Micro-Electronic Co.,Ltd
 *  All rights reserved.
 *
 *  This software is copyright protected and proprietary to
 *  Shanghai ChipON Micro-Electronic Co.,Ltd.
 *****************************************************************************/
#ifndef DIO_CFG_H
#define DIO_CFG_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 **                        Include Files
 ******************************************************************************/

/******************************************************************************
 **                        File Version Check
 ******************************************************************************/

/******************************************************************************
 **                        Macro  Definitions
 ******************************************************************************/

/**
 * @brief Switches the Default Error Tracer (Det) detection and notification ON or OFF
 */
#define DIO_DEV_ERROR_DETECT (STD_OFF)

/**
 * @brief Adds / removes the service Dio_FlipChannel() from the code
 */
#define DIO_FLIP_CHANNEL_API (STD_ON)

/**
 * @brief Adds / removes the service Dio_MaskedWritePort() from the code
 */
#define DIO_MASKED_WRITE_PORT_API (STD_ON)

/**
 * @brief Adds / removes the service Dio_ GetVersionInfo() from the code
 */
#define DIO_VERSION_INFO_API (STD_ON)

/**
 * @brief Channel information of DIO configuration
 */
#define DIO_CFG_CHANNEL_A_5  (0x5U)
#define DIO_CFG_CHANNEL_A_6  (0x6U)
#define DIO_CFG_CHANNEL_A_8  (0x8U)
#define DIO_CFG_CHANNEL_A_13  (0xDU)
#define DIO_CFG_CHANNEL_B_10  (0x1AU)
#define DIO_CFG_CHANNEL_B_13  (0x1DU)
#define DIO_CFG_CHANNEL_B_14  (0x1EU)
#define DIO_CFG_CHANNEL_D_12  (0x3CU)
#define DIO_CFG_CHANNEL_E_7  (0x47U)
#define DIO_CFG_CHANNEL_E_8  (0x48U)
#define DIO_CFG_CHANNEL_E_9  (0x49U)
#define DIO_CFG_CHANNEL_E_10  (0x4AU)
#define DIO_CFG_CHANNEL_F_2  (0x52U)
#define DIO_CFG_CHANNEL_F_8  (0x58U)
#define DIO_CFG_CHANNEL_G_4  (0x64U)
#define DIO_CFG_CHANNEL_H_3  (0x73U)
#define DIO_CFG_CHANNEL_H_4  (0x74U)

/**
* @brief PORT configuration information
*/
#define DIO_CFG_PORT_A  (0x0U)
#define DIO_CFG_PORT_B  (0x1U)
#define DIO_CFG_PORT_D  (0x3U)
#define DIO_CFG_PORT_E  (0x4U)
#define DIO_CFG_PORT_F  (0x5U)
#define DIO_CFG_PORT_G  (0x6U)
#define DIO_CFG_PORT_H  (0x7U)



/** @brief Numeric identifier of the DIO port A */
#define DIO_PORT_A (0x00U)
/** @brief Numeric identifier of the DIO port B */
#define DIO_PORT_B (0x01U)
/** @brief Numeric identifier of the DIO port C */
#define DIO_PORT_C (0x02U)
/** @brief Numeric identifier of the DIO port D */
#define DIO_PORT_D (0x03U)
/** @brief Numeric identifier of the DIO port E */
#define DIO_PORT_E (0x04U)
/** @brief Numeric identifier of the DIO port F */
#define DIO_PORT_F (0x05U)
/** @brief Numeric identifier of the DIO port G */
#define DIO_PORT_G (0x06U)
/** @brief Numeric identifier of the DIO port H */
#define DIO_PORT_H (0x07U)

/*  Container : DioChannel
    Name : DioChannelId
    Description : Channel Id of the DIO channel. This value will be assigned to
        the symbolic names.
    Traceability : ECUC_Dio_00147 */

/* Channel Id of the DIO channel */
/* PORTA */
/** @brief Channel Id of the DIO A channel 0 */
#define DIO_CHANNEL_A_0 ((Dio_ChannelType)(0x00U))
/** @brief Channel Id of the DIO A channel 1 */
#define DIO_CHANNEL_A_1 ((Dio_ChannelType)(0x01U))
/** @brief Channel Id of the DIO A channel 2 */
#define DIO_CHANNEL_A_2 ((Dio_ChannelType)(0x02U))
/** @brief Channel Id of the DIO A channel 3 */
#define DIO_CHANNEL_A_3 ((Dio_ChannelType)(0x03U))
/** @brief Channel Id of the DIO A channel 4 */
#define DIO_CHANNEL_A_4 ((Dio_ChannelType)(0x04U))
/** @brief Channel Id of the DIO A channel 5 */
#define DIO_CHANNEL_A_5 ((Dio_ChannelType)(0x05U))
/** @brief Channel Id of the DIO A channel 6 */
#define DIO_CHANNEL_A_6 ((Dio_ChannelType)(0x06U))
/** @brief Channel Id of the DIO A channel 7 */
#define DIO_CHANNEL_A_7 ((Dio_ChannelType)(0x07U))
/** @brief Channel Id of the DIO A channel 8 */
#define DIO_CHANNEL_A_8 ((Dio_ChannelType)(0x08U))
/** @brief Channel Id of the DIO A channel 9 */
#define DIO_CHANNEL_A_9 ((Dio_ChannelType)(0x09U))
/** @brief Channel Id of the DIO A channel 10 */
#define DIO_CHANNEL_A_10 ((Dio_ChannelType)(0x0AU))
/** @brief Channel Id of the DIO A channel 11 */
#define DIO_CHANNEL_A_11 ((Dio_ChannelType)(0x0BU))
/** @brief Channel Id of the DIO A channel 12 */
#define DIO_CHANNEL_A_12 ((Dio_ChannelType)(0x0CU))
/** @brief Channel Id of the DIO A channel 13 */
#define DIO_CHANNEL_A_13 ((Dio_ChannelType)(0x0DU))
/** @brief Channel Id of the DIO A channel 14 */
#define DIO_CHANNEL_A_14 ((Dio_ChannelType)(0x0EU))
/** @brief Channel Id of the DIO A channel 15 */
#define DIO_CHANNEL_A_15 ((Dio_ChannelType)(0x0FU))

/* PORTB */
/** @brief Channel Id of the DIO B channel 0 */
#define DIO_CHANNEL_B_0 ((Dio_ChannelType)(0x10U))
/** @brief Channel Id of the DIO B channel 1 */
#define DIO_CHANNEL_B_1 ((Dio_ChannelType)(0x11U))
/** @brief Channel Id of the DIO B channel 2 */
#define DIO_CHANNEL_B_2 ((Dio_ChannelType)(0x12U))
/** @brief Channel Id of the DIO B channel 3 */
#define DIO_CHANNEL_B_3 ((Dio_ChannelType)(0x13U))
/** @brief Channel Id of the DIO B channel 4 */
#define DIO_CHANNEL_B_4 ((Dio_ChannelType)(0x14U))
/** @brief Channel Id of the DIO B channel 5 */
#define DIO_CHANNEL_B_5 ((Dio_ChannelType)(0x15U))
/** @brief Channel Id of the DIO B channel 6 */
#define DIO_CHANNEL_B_6 ((Dio_ChannelType)(0x16U))
/** @brief Channel Id of the DIO B channel 7 */
#define DIO_CHANNEL_B_7 ((Dio_ChannelType)(0x17U))
/** @brief Channel Id of the DIO B channel 8 */
#define DIO_CHANNEL_B_8 ((Dio_ChannelType)(0x18U))
/** @brief Channel Id of the DIO B channel 9 */
#define DIO_CHANNEL_B_9 ((Dio_ChannelType)(0x19U))
/** @brief Channel Id of the DIO B channel 10 */
#define DIO_CHANNEL_B_10 ((Dio_ChannelType)(0x1AU))
/** @brief Channel Id of the DIO B channel 11 */
#define DIO_CHANNEL_B_11 ((Dio_ChannelType)(0x1BU))
/** @brief Channel Id of the DIO B channel 12 */
#define DIO_CHANNEL_B_12 ((Dio_ChannelType)(0x1CU))
/** @brief Channel Id of the DIO B channel 13 */
#define DIO_CHANNEL_B_13 ((Dio_ChannelType)(0x1DU))
/** @brief Channel Id of the DIO B channel 14 */
#define DIO_CHANNEL_B_14 ((Dio_ChannelType)(0x1EU))
/** @brief Channel Id of the DIO B channel 15 */
#define DIO_CHANNEL_B_15 ((Dio_ChannelType)(0x1FU))

/* PORTC */
/** @brief Channel Id of the DIO C channel 0 */
#define DIO_CHANNEL_C_0 ((Dio_ChannelType)(0x20U))
/** @brief Channel Id of the DIO C channel 1 */
#define DIO_CHANNEL_C_1 ((Dio_ChannelType)(0x21U))
/** @brief Channel Id of the DIO C channel 2 */
#define DIO_CHANNEL_C_2 ((Dio_ChannelType)(0x22U))
/** @brief Channel Id of the DIO C channel 3 */
#define DIO_CHANNEL_C_3 ((Dio_ChannelType)(0x23U))
/** @brief Channel Id of the DIO C channel 4 */
#define DIO_CHANNEL_C_4 ((Dio_ChannelType)(0x24U))
/** @brief Channel Id of the DIO C channel 5 */
#define DIO_CHANNEL_C_5 ((Dio_ChannelType)(0x25U))
/** @brief Channel Id of the DIO C channel 6 */
#define DIO_CHANNEL_C_6 ((Dio_ChannelType)(0x26U))
/** @brief Channel Id of the DIO C channel 7 */
#define DIO_CHANNEL_C_7 ((Dio_ChannelType)(0x27U))
/** @brief Channel Id of the DIO C channel 8 */
#define DIO_CHANNEL_C_8 ((Dio_ChannelType)(0x28U))
/** @brief Channel Id of the DIO C channel 9 */
#define DIO_CHANNEL_C_9 ((Dio_ChannelType)(0x29U))
/** @brief Channel Id of the DIO C channel 10 */
#define DIO_CHANNEL_C_10 ((Dio_ChannelType)(0x2AU))
/** @brief Channel Id of the DIO C channel 11 */
#define DIO_CHANNEL_C_11 ((Dio_ChannelType)(0x2BU))
/** @brief Channel Id of the DIO C channel 12 */
#define DIO_CHANNEL_C_12 ((Dio_ChannelType)(0x2CU))
/** @brief Channel Id of the DIO C channel 13 */
#define DIO_CHANNEL_C_13 ((Dio_ChannelType)(0x2DU))
/** @brief Channel Id of the DIO C channel 14 */
#define DIO_CHANNEL_C_14 ((Dio_ChannelType)(0x2EU))
/** @brief Channel Id of the DIO C channel 15 */
#define DIO_CHANNEL_C_15 ((Dio_ChannelType)(0x2FU))

/* PORTD */
/** @brief Channel Id of the DIO D channel 0 */
#define DIO_CHANNEL_D_0 ((Dio_ChannelType)(0x30U))
/** @brief Channel Id of the DIO D channel 1 */
#define DIO_CHANNEL_D_1 ((Dio_ChannelType)(0x31U))
/** @brief Channel Id of the DIO D channel 2 */
#define DIO_CHANNEL_D_2 ((Dio_ChannelType)(0x32U))
/** @brief Channel Id of the DIO D channel 3 */
#define DIO_CHANNEL_D_3 ((Dio_ChannelType)(0x33U))
/** @brief Channel Id of the DIO D channel 4 */
#define DIO_CHANNEL_D_4 ((Dio_ChannelType)(0x34U))
/** @brief Channel Id of the DIO D channel 5 */
#define DIO_CHANNEL_D_5 ((Dio_ChannelType)(0x35U))
/** @brief Channel Id of the DIO D channel 6 */
#define DIO_CHANNEL_D_6 ((Dio_ChannelType)(0x36U))
/** @brief Channel Id of the DIO D channel 7 */
#define DIO_CHANNEL_D_7 ((Dio_ChannelType)(0x37U))
/** @brief Channel Id of the DIO D channel 8 */
#define DIO_CHANNEL_D_8 ((Dio_ChannelType)(0x38U))
/** @brief Channel Id of the DIO D channel 9 */
#define DIO_CHANNEL_D_9 ((Dio_ChannelType)(0x39U))
/** @brief Channel Id of the DIO D channel 10 */
#define DIO_CHANNEL_D_10 ((Dio_ChannelType)(0x3AU))
/** @brief Channel Id of the DIO D channel 11 */
#define DIO_CHANNEL_D_11 ((Dio_ChannelType)(0x3BU))
/** @brief Channel Id of the DIO D channel 12 */
#define DIO_CHANNEL_D_12 ((Dio_ChannelType)(0x3CU))
/** @brief Channel Id of the DIO D channel 13 */
#define DIO_CHANNEL_D_13 ((Dio_ChannelType)(0x3DU))
/** @brief Channel Id of the DIO D channel 14 */
#define DIO_CHANNEL_D_14 ((Dio_ChannelType)(0x3EU))
/** @brief Channel Id of the DIO D channel 15 */
#define DIO_CHANNEL_D_15 ((Dio_ChannelType)(0x3FU))

/* PORTE */
/** @brief Channel Id of the DIO E channel 0 */
#define DIO_CHANNEL_E_0 ((Dio_ChannelType)(0x40U))
/** @brief Channel Id of the DIO E channel 1 */
#define DIO_CHANNEL_E_1 ((Dio_ChannelType)(0x41U))
/** @brief Channel Id of the DIO E channel 2 */
#define DIO_CHANNEL_E_2 ((Dio_ChannelType)(0x42U))
/** @brief Channel Id of the DIO E channel 3 */
#define DIO_CHANNEL_E_3 ((Dio_ChannelType)(0x43U))
/** @brief Channel Id of the DIO E channel 4 */
#define DIO_CHANNEL_E_4 ((Dio_ChannelType)(0x44U))
/** @brief Channel Id of the DIO E channel 5 */
#define DIO_CHANNEL_E_5 ((Dio_ChannelType)(0x45U))
/** @brief Channel Id of the DIO E channel 6 */
#define DIO_CHANNEL_E_6 ((Dio_ChannelType)(0x46U))
/** @brief Channel Id of the DIO E channel 7 */
#define DIO_CHANNEL_E_7 ((Dio_ChannelType)(0x47U))
/** @brief Channel Id of the DIO E channel 8 */
#define DIO_CHANNEL_E_8 ((Dio_ChannelType)(0x48U))
/** @brief Channel Id of the DIO E channel 9 */
#define DIO_CHANNEL_E_9 ((Dio_ChannelType)(0x49U))
/** @brief Channel Id of the DIO E channel 10 */
#define DIO_CHANNEL_E_10 ((Dio_ChannelType)(0x4AU))
/** @brief Channel Id of the DIO E channel 11 */
#define DIO_CHANNEL_E_11 ((Dio_ChannelType)(0x4BU))
/** @brief Channel Id of the DIO E channel 12 */
#define DIO_CHANNEL_E_12 ((Dio_ChannelType)(0x4CU))
/** @brief Channel Id of the DIO E channel 13 */
#define DIO_CHANNEL_E_13 ((Dio_ChannelType)(0x4DU))
/** @brief Channel Id of the DIO E channel 14 */
#define DIO_CHANNEL_E_14 ((Dio_ChannelType)(0x4EU))
/** @brief Channel Id of the DIO E channel 15 */
#define DIO_CHANNEL_E_15 ((Dio_ChannelType)(0x4FU))

/* PORTF */
/** @brief Channel Id of the DIO F channel 0 */
#define DIO_CHANNEL_F_0 ((Dio_ChannelType)(0x50U))
/** @brief Channel Id of the DIO F channel 1 */
#define DIO_CHANNEL_F_1 ((Dio_ChannelType)(0x51U))
/** @brief Channel Id of the DIO F channel 2 */
#define DIO_CHANNEL_F_2 ((Dio_ChannelType)(0x52U))
/** @brief Channel Id of the DIO F channel 3 */
#define DIO_CHANNEL_F_3 ((Dio_ChannelType)(0x53U))
/** @brief Channel Id of the DIO F channel 4 */
#define DIO_CHANNEL_F_4 ((Dio_ChannelType)(0x54U))
/** @brief Channel Id of the DIO F channel 5 */
#define DIO_CHANNEL_F_5 ((Dio_ChannelType)(0x55U))
/** @brief Channel Id of the DIO F channel 6 */
#define DIO_CHANNEL_F_6 ((Dio_ChannelType)(0x56U))
/** @brief Channel Id of the DIO F channel 7 */
#define DIO_CHANNEL_F_7 ((Dio_ChannelType)(0x57U))
/** @brief Channel Id of the DIO F channel 8 */
#define DIO_CHANNEL_F_8 ((Dio_ChannelType)(0x58U))
/** @brief Channel Id of the DIO F channel 9 */
#define DIO_CHANNEL_F_9 ((Dio_ChannelType)(0x59U))
/** @brief Channel Id of the DIO F channel 10 */
#define DIO_CHANNEL_F_10 ((Dio_ChannelType)(0x5AU))
/** @brief Channel Id of the DIO F channel 11 */
#define DIO_CHANNEL_F_11 ((Dio_ChannelType)(0x5BU))
/** @brief Channel Id of the DIO F channel 12 */
#define DIO_CHANNEL_F_12 ((Dio_ChannelType)(0x5CU))
/** @brief Channel Id of the DIO F channel 13 */
#define DIO_CHANNEL_F_13 ((Dio_ChannelType)(0x5DU))
/** @brief Channel Id of the DIO F channel 14 */
#define DIO_CHANNEL_F_14 ((Dio_ChannelType)(0x5EU))
/** @brief Channel Id of the DIO F channel 15 */
#define DIO_CHANNEL_F_15 ((Dio_ChannelType)(0x5FU))

/* PORTG */
/** @brief Channel Id of the DIO G channel 0 */
#define DIO_CHANNEL_G_0 ((Dio_ChannelType)(0x60U))
/** @brief Channel Id of the DIO G channel 1 */
#define DIO_CHANNEL_G_1 ((Dio_ChannelType)(0x61U))
/** @brief Channel Id of the DIO G channel 2 */
#define DIO_CHANNEL_G_2 ((Dio_ChannelType)(0x62U))
/** @brief Channel Id of the DIO G channel 3 */
#define DIO_CHANNEL_G_3 ((Dio_ChannelType)(0x63U))
/** @brief Channel Id of the DIO G channel 4 */
#define DIO_CHANNEL_G_4 ((Dio_ChannelType)(0x64U))
/** @brief Channel Id of the DIO G channel 5 */
#define DIO_CHANNEL_G_5 ((Dio_ChannelType)(0x65U))
/** @brief Channel Id of the DIO G channel 6 */
#define DIO_CHANNEL_G_6 ((Dio_ChannelType)(0x66U))
/** @brief Channel Id of the DIO G channel 7 */
#define DIO_CHANNEL_G_7 ((Dio_ChannelType)(0x67U))
/** @brief Channel Id of the DIO G channel 8 */
#define DIO_CHANNEL_G_8 ((Dio_ChannelType)(0x68U))
/** @brief Channel Id of the DIO G channel 9 */
#define DIO_CHANNEL_G_9 ((Dio_ChannelType)(0x69U))
/** @brief Channel Id of the DIO G channel 10 */
#define DIO_CHANNEL_G_10 ((Dio_ChannelType)(0x6AU))
/** @brief Channel Id of the DIO G channel 11 */
#define DIO_CHANNEL_G_11 ((Dio_ChannelType)(0x6BU))
/** @brief Channel Id of the DIO G channel 12 */
#define DIO_CHANNEL_G_12 ((Dio_ChannelType)(0x6CU))
/** @brief Channel Id of the DIO G channel 13 */
#define DIO_CHANNEL_G_13 ((Dio_ChannelType)(0x6DU))
/** @brief Channel Id of the DIO G channel 14 */
#define DIO_CHANNEL_G_14 ((Dio_ChannelType)(0x6EU))
/** @brief Channel Id of the DIO G channel 15 */
#define DIO_CHANNEL_G_15 ((Dio_ChannelType)(0x6FU))

/* PORTH */
/** @brief Channel Id of the DIO H channel 0 */
#define DIO_CHANNEL_H_0 ((Dio_ChannelType)(0x70U))
/** @brief Channel Id of the DIO H channel 1 */
#define DIO_CHANNEL_H_1 ((Dio_ChannelType)(0x71U))
/** @brief Channel Id of the DIO H channel 2 */
#define DIO_CHANNEL_H_2 ((Dio_ChannelType)(0x72U))
/** @brief Channel Id of the DIO H channel 3 */
#define DIO_CHANNEL_H_3 ((Dio_ChannelType)(0x73U))
/** @brief Channel Id of the DIO H channel 4 */
#define DIO_CHANNEL_H_4 ((Dio_ChannelType)(0x74U))
/** @brief Channel Id of the DIO H channel 5 */
#define DIO_CHANNEL_H_5 ((Dio_ChannelType)(0x75U))
/** @brief Channel Id of the DIO H channel 6 */
#define DIO_CHANNEL_H_6 ((Dio_ChannelType)(0x76U))
/** @brief Channel Id of the DIO H channel 7 */
#define DIO_CHANNEL_H_7 ((Dio_ChannelType)(0x77U))
/** @brief Channel Id of the DIO H channel 8 */
#define DIO_CHANNEL_H_8 ((Dio_ChannelType)(0x78U))
/** @brief Channel Id of the DIO H channel 9 */
#define DIO_CHANNEL_H_9 ((Dio_ChannelType)(0x79U))
/** @brief Channel Id of the DIO H channel 10 */
#define DIO_CHANNEL_H_10 ((Dio_ChannelType)(0x7AU))
/** @brief Channel Id of the DIO H channel 11 */
#define DIO_CHANNEL_H_11 ((Dio_ChannelType)(0x7BU))
/** @brief Channel Id of the DIO H channel 12 */
#define DIO_CHANNEL_H_12 ((Dio_ChannelType)(0x7CU))
/** @brief Channel Id of the DIO H channel 13 */
#define DIO_CHANNEL_H_13 ((Dio_ChannelType)(0x7DU))
/** @brief Channel Id of the DIO H channel 14 */
#define DIO_CHANNEL_H_14 ((Dio_ChannelType)(0x7EU))
/** @brief Channel Id of the DIO H channel 15 */
#define DIO_CHANNEL_H_15 ((Dio_ChannelType)(0x7FU))
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
