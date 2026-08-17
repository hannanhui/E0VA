/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : I2c_LCfg.c
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

/******************************************************************************
 **                        Include Files
 ******************************************************************************/
#include "I2c_LCfg.h"

/******************************************************************************
 **                      Macro Definitions
 ******************************************************************************/

/******************************************************************************
 **                      Type definitions
 ******************************************************************************/

/******************************************************************************
 **                      Export Variables
 ******************************************************************************/

/******************************************************************************
**                       Export Functions
******************************************************************************/

/******************************************************************************
 **                      Constant Declarations
 ******************************************************************************/

/*******************************************************************************
 **                      Global Variable Definitions
 *******************************************************************************/
/**
 * @brief notify function
 * @retval void
 * @return void
 */
static void I2c_ModuleCallBack(I2c_PacketType Packet, I2C_MasterEventType Event, uint8 UserData)
{
    /* user process */
    switch (Event)
    {
    case I2C_MASTER_EVENT_NACK: {
        break;
    }
    case I2C_MASTER_EVENT_ARBITRATION_LOST: {
        break;
    }
    case I2C_MASTER_EVENT_BUS_ERROR: {
        break;
    }
    case I2C_MASTER_EVENT_END_WRITE: {
        break;
    }
    case I2C_MASTER_EVENT_END_READ: {
        break;
    }
    default:
        break;
    }
}

/**
 * @brief config information
 */
const I2c_ConfigType I2c_ConfigPredefined = {
  .I2cPacketConfigPtr =
    (I2c_PacketConfigType[I2C_MAX_PACKET_NUM]){
      [0U].ExtDeviceAddress = 0xA0U,
      [0U].HwUnit           = (I2c_HwUnitType)I2C_INDEX_0,
      [1U].ExtDeviceAddress = 0xA0U,
      [1U].HwUnit           = (I2c_HwUnitType)I2C_INDEX_1,
    },
  .HwUnitNum = 2U,
  .HwModuleConfigPtr =
    (I2c_HWModuleConfigType[2U]){
      /* I2C0 CONFIG 100K */
      [0U].HwUnit         = (I2c_HwUnitType)I2C_INDEX_0,
      [0U].HwClkSource    = (uint32)CLOCK_CFG_SELECT_SCLK,
      [0U].HwClkDriver    = (uint32)CLOCK_CFG_DIV_1,
      [0U].HwBaudRateLo   = 600U,
      [0U].HwBaudRateHi   = 600U,
      [0U].HwMode         = (uint32)HW_MODE_CFG_I2C_MASTER,
      [0U].HwAddrMoe      = (I2c_DeviceAddrModeType)I2C_ADDRTYPE_7BIT,
      [0U].MasterCallback = &I2c_ModuleCallBack,
      [0U].SlaveCallback  = NULL_PTR,
      [0U].CallbackParam  = (uint8)I2C_INDEX_0,
      /* I2C1 CONFIG 150K */
      [1U].HwUnit         = (I2c_HwUnitType)I2C_INDEX_1,
      [1U].HwClkSource    = (uint32)CLOCK_CFG_SELECT_SCLK,
      [1U].HwClkDriver    = (uint32)CLOCK_CFG_DIV_1,
      [1U].HwBaudRateLo   = 400U,
      [1U].HwBaudRateHi   = 400U,
      [1U].HwMode         = (uint32)HW_MODE_CFG_I2C_MASTER,
      [1U].HwAddrMoe      = (I2c_DeviceAddrModeType)I2C_ADDRTYPE_7BIT,
      [1U].MasterCallback = NULL_PTR,
      [1U].SlaveCallback  = NULL_PTR,
      [1U].CallbackParam  = (uint8)I2C_INDEX_1,
    },
};
/******************************************************************************
 **                      Private Function Declarations
 ******************************************************************************/

/******************************************************************************
 **                      Function definitions
 ******************************************************************************/
