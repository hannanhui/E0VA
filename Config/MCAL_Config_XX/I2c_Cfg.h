/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : I2c_Cfg.h
 *  @Syntax          : GNU99
 *  @Author          : ChipON AE/FAE Group
 *  @Date            : 2022-07-25
 *  @Version         : {{VersionDate}}
 *  @Description     : This document describes the C language document template.
 ******************************************************************************
 *  Copyright (C) by Shanghai ChipON Micro-Electronic Co.,Ltd
 *  All rights reserved.
 *
 *  This software is copyright protected and proprietary to
 *  Shanghai ChipON Micro-Electronic Co.,Ltd.
 *****************************************************************************/

#ifndef I2C_CFG_H
#define I2C_CFG_H

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
 * @brief Error Detection
 *
 */
#define I2C_DEV_ERROR_DETECT (STD_ON)

/**
 * @brief Fixed Address
 *
 */
#define I2C_PB_FIXEDADDR (STD_OFF)

/**
 * @brief Version Info
 *
 */
#define I2C_VERSION_INFO_API (STD_ON)

/**
 * @brief Async Read/Write
 *
 */
#define I2C_ASYNC_READ_OR_WRITE (STD_ON)

/**
 * @brief  Maximum Packet Number
 *
 */
#define I2C_MAX_PACKET_NUM (2U)

/**
 * @brief Default send data when actual send data number greater than expected.
 */
#define I2C_DEFAULT_SEND_DATA (0xFFU)
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
