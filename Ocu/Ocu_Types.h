/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Ocu_Type.h
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
#ifndef OCU_TYPE_H
#define OCU_TYPE_H

#ifdef __cplusplus
extern "C" {
#endif

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
 * @brief Index of channel number
 */
#define OCU_CHANNEL1_CFG_INDEX (0U)
#define OCU_CHANNEL2_CFG_INDEX (1U)
#define OCU_CHANNEL3_CFG_INDEX (2U)
#define OCU_CHANNEL4_CFG_INDEX (3U)
/******************************************************************************
 **                        Typedef  Definitions
 ******************************************************************************/

/**
 * @brief channel index
 */
/*PRQA S 3205 ++ #KQR003205 */
typedef enum
{
    OCU_CHANNEL0_INDEX,
    OCU_CHANNEL1_INDEX,
    OCU_CHANNEL2_INDEX,
    OCU_CHANNEL3_INDEX,
    OCU_CHANNEL4_INDEX,
    OCU_CHANNEL5_INDEX,
    OCU_CHANNEL6_INDEX,
    OCU_CHANNEL7_INDEX,
    OCU_CHANNEL8_INDEX,
    OCU_CHANNEL9_INDEX,
    OCU_CHANNEL10_INDEX,
    OCU_CHANNEL11_INDEX,
    OCU_CHANNEL12_INDEX,
    OCU_CHANNEL13_INDEX,
    OCU_CHANNEL14_INDEX,
    OCU_CHANNEL15_INDEX,
    OCU_CHANNEL16_INDEX,
    OCU_CHANNEL17_INDEX,
    OCU_CHANNEL18_INDEX,
    OCU_CHANNEL19_INDEX,
    OCU_CHANNEL20_INDEX,
    OCU_CHANNEL21_INDEX,
    OCU_CHANNEL22_INDEX,
    OCU_CHANNEL23_INDEX,
    OCU_CHANNEL24_INDEX,
    OCU_CHANNEL25_INDEX,
    OCU_CHANNEL26_INDEX,
    OCU_CHANNEL27_INDEX,
    OCU_CHANNEL28_INDEX,
    OCU_CHANNEL29_INDEX,
    OCU_CHANNEL30_INDEX,
    OCU_CHANNEL31_INDEX,
    OCU_CHANNEL32_INDEX,
    OCU_CHANNEL33_INDEX,
    OCU_CHANNEL34_INDEX,
    OCU_CHANNEL35_INDEX,
    OCU_CHANNEL36_INDEX,
    OCU_CHANNEL37_INDEX,
    OCU_CHANNEL38_INDEX,
    OCU_CHANNEL39_INDEX
} Ocu_ChannelNumType;
/*PRQA S 3205 -- #KQR003205 */
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
