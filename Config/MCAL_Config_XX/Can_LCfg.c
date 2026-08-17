/******************************************************************************
 *                        Shanghai ChipON Micro-Electronic Co.,Ltd
 ******************************************************************************
 *  @File Name       : Can_LCfg.c
 *  @Syntax             : GNU99
 *  @Author             : ChipON AE/FAE Group
 *  @Date            : 2026/5/11 15:57:14
 *  @Version         : V1.0
 *  @Description     : This document describes the C language document template.
 ******************************************************************************
 *  Copyright (C) by Shanghai ChipON Micro-Electronic Co.,Ltd
 *  All rights reserved.
 *
 *  This software is copyright protected and proprietary to
 *  Shanghai ChipON Micro-Electronic Co.,Ltd.
 ******************************************************************************/

/******************************************************************************
 **                        Include Files
 ******************************************************************************/
#include "Can_LCfg.h"
/******************************************************************************
 **                        File Version Check
 ******************************************************************************/

/******************************************************************************
 **                        Macro  Definitions
 ******************************************************************************/
#define CAN_HW_CONTROLLER_CANFD6 (CANFD6)
#define CAN_HW_CONTROLLER_CANFD7 (CANFD7)
#define CAN_HW_CONTROLLER_CANFD8 (CANFD8)
#define CAN_HW_CONTROLLER_CANFD9 (CANFD9)
/******************************************************************************
 **                        Typedef  Definitions
 ******************************************************************************/

/******************************************************************************
 **                        Export Variables
 ******************************************************************************/

/******************************************************************************
 **                        Export Functions
 ******************************************************************************/
extern void Can0_UserErrorNotification(void);	
extern void Can0_UserOffNotification(void);	
extern Std_ReturnType Can0_TxNotification(Can_HwHandleType Hth);	
/******************************************************************************
 **                      Variables
 ******************************************************************************/
/**
 * @brief can Arbitrate baudrate config
 */
static CONST(Can_ArbitrateBDRConfigType, CAN_CONST) Can_ControllerCanBDRConfig[CAN_TOTAL_USED_NUMBER][1U] = {
  /* Clock prescale and baudrate config: Index 0 */
 [0U] = {
    [0U] = 
    {
      /** @brief BaudRate Id */
      .BaudRateConfigID = 0U,
      /** @brief baud rate */
      .CanControllerFdBaudRate = 500U,
      /** @brief Tx Arbitration start delay */
      .TxArbitrationDelay = 0U,
      /** @brief PreScale */
      .PreScale = 3U,
      /** @brief PropSeg */
      .PropSeg = 8U,
      /** @brief TSeg1 */
      .TSeg1 = 5U,
      /** @brief TSeg2 */
      .TSeg2 = 3U,
      /** @brief Sjw */
      .Sjw = 3U,
      /** @brief Sample time */
      .SampleTimes = CAN_SAMPLE_ONCE,
	}	}};

/**
 * @brief can data baudrate config value
 */
static CONST(Can_FdDataBDRConfigType, CAN_CONST) Can_ControllerFdBDRConfig[CAN_TOTAL_USED_NUMBER][1U] = {
[0U] =
	{
	  [0U] =
		{
		  /** @brief baud rate */
		  .CanControllerFdBaudRate = 2000U,
		  /** @brief BrsPrescale */
		  .BrsPrescale = 1U,
		  /** @brief HSjw */
		  .HSjw = 1U,
		  /** @brief PropSeg */
		  .PropSeg = 5U,
		  /** @brief HtSeg1 */
		  .HtSeg1 = 1U,
		  /** @brief HtSeg2 */
		  .HtSeg2 = 1U,
		  /** @brief TDC */
		  .EnableTdc =  FALSE,
	      /** @brief TDC offset */
		  .TdcOffset = 0U,
		}
	}		
};

/**
 * @brief can data baudrate config
 */
static CONST(Can_ArbitrateBDRArrayConfigType, CAN_CONST) Can_BDRArrayConfig[CAN_TOTAL_USED_NUMBER] = {
  [0U] =
    {
      /** @brief controller BaudRate array config */
      .ArbitrateBDRConfigPtr = &Can_ControllerCanBDRConfig[0U][0U],
    }
};

#if (CAN_CANFD_MODE == STD_ON)
/**
 * @brief controller CanFd config
 */
static CONST(Can_FDConfigType, CAN_CONST) Can_ControllerFdConfig[CAN_TOTAL_USED_NUMBER] = {
 [0U] =
	{
	  /** @brief CanFd status */
	  .CanFdEnable = TRUE,
	  /** @brief CanFd BRS status */
	  .CanFdTxBitRateSwitch = TRUE,
	  /** @brief CanFd frame mode */
	  .CanFdFrameMode = CAN_FD_ISOMODE,
	  /** @brief CanFd data BaudRate config */
	  .CanFdDataBDRConfigPtr = &Can_ControllerFdBDRConfig[0U][0U],
	}
};
#endif

/**
 * @brief all can interrupt config
 */
static CONST(Can_IntConfigType, CAN_CONST) Can_IntrConfig[CAN_TOTAL_USED_NUMBER] = {
 [0U] =
	{
	  /** @brief Rx interrupt */
	  .RxIntEnableSet = CAN_INTERRUPT_ENABLE,
	  /** @brief Tx interrupt */
	  .TxIntEnableSet = CAN_INTERRUPT_ENABLE,
	  /** @brief Bus error interrupt */
	  .BusErrorIntEnableSet = CAN_INTERRUPT_ENABLE,
	  /** @brief Bus off interrupt */
	  .BusOffEnableSet = CAN_INTERRUPT_ENABLE,
	  /** @brief Wakeup interrupt */
	  .WakeUpIntEnableSet = CAN_INTERRUPT_DISABLE,
	}
};
	
/**
 * @brief can controller information
 */
static CONST(Can_DescriptorType, CAN_CONST) Can_ControllerDescriptor[CAN_TOTAL_USED_NUMBER] = {
 [0U] =
	{
	  /** @brief Pointer to send complete interrupt notification function */
	  .TxConfirmationNotification = &Can0_TxNotification,
	  /** @brief Pointer to receive interrupt notification function */
	  .RxIndicationNotification = NULL_PTR,
	  /** @brief Pointer to BusError interrupt notification function */
	  .BusErrorNotification = &Can0_UserErrorNotification,
	  /** @brief Pointer to BusOff interrupt notification function */
	  .BusOffNotification = &Can0_UserOffNotification,
	  /** @brief Rx FIFO event callback */
	  .RxFifoEventCallbackFunc = NULL_PTR,
	  /** @brief support BaudRate number */
	  .MaxBaudRateCount = (uint8)1U,
	  /** @brief default BaudRate config index */
	  .DefaultBaudRateIndex = 0U
	}		
};


/**
 * @brief HOH information config
 */
static CONST(Can_HOHType, CAN_CONST) Can_ControllerHOHConfig[] = {
  [0U] =
    {
      /** @brief receive or write */
      .HOHType = CAN_RECEIVE,
      /** @brief filter status */
      .bFilterEnable = TRUE,
      /** @brief Full-CAN or Basic-CAN */
      .HRHType.CanHandleType = CAN_TYPE_BASIC,
      /** @brief receive frame Id */
      .HRHType.FullCan_HRH.Id = 0x779U,
      /** @brief filter mask */
      .HRHType.FullCan_HRH.CanFilterMask = 0x1FFFFFFFU,
      /** @brief receive frame type */
      .HRHType.FullCan_HRH.IdType = CAN_DATA_STANDARD,
      /** @brief mailbox start index */
      .StartMbIndex = 0U,
      /** @brief mailbox end index */
      .EndMbIndex = 1U,
      /** @brief api HOH index find controller */
      .CfgId = CONTROLLER_0,
      /** @brief Enables polling of this hardware object */
      .bPolling = FALSE,
      /** @brief Reference to CanMainFunctionPeriod */
      .MainfunctionId = 0U,
      /** @brief Configuration of Rx fifo */
      .RxFifoConfig = NULL_PTR,
	},
  [1U] =
    {
      /** @brief receive or write */
      .HOHType = CAN_RECEIVE,
      /** @brief filter status */
      .bFilterEnable = TRUE,
      /** @brief Full-CAN or Basic-CAN */
      .HRHType.CanHandleType = CAN_TYPE_BASIC,
      /** @brief receive frame Id */
      .HRHType.FullCan_HRH.Id = 0x7FFU,
      /** @brief filter mask */
      .HRHType.FullCan_HRH.CanFilterMask = 0x1FFFFFFFU,
      /** @brief receive frame type */
      .HRHType.FullCan_HRH.IdType = CAN_DATA_STANDARD,
      /** @brief mailbox start index */
      .StartMbIndex = 1U,
      /** @brief mailbox end index */
      .EndMbIndex = 2U,
      /** @brief api HOH index find controller */
      .CfgId = CONTROLLER_0,
      /** @brief Enables polling of this hardware object */
      .bPolling = FALSE,
      /** @brief Reference to CanMainFunctionPeriod */
      .MainfunctionId = 0U,
      /** @brief Configuration of Rx fifo */
      .RxFifoConfig = NULL_PTR,
	},
  [2U] =
    {
      /** @brief receive or write */
      .HOHType = CAN_TRANSMIT,
      /** @brief receive frame Id */
      .HRHType.FullCan_HRH.Id = 0x125U,
      /** @brief filter mask */
      .HRHType.FullCan_HRH.CanFilterMask = 0x1FFFFFFFU,
      /** @brief mailbox start index */
      .StartMbIndex = 2U,
      /** @brief mailbox end index */
      .EndMbIndex = 3U,
      /** @brief api HOH index find controller */
      .CfgId = CONTROLLER_0,
#if (CAN_CANFD_MODE == STD_ON)
      /** @brief CanFd Padding Value */
      .CanFdPaddingValue = 0xFFU,
#endif
      /** @brief Enables polling of this hardware object */
      .bPolling = FALSE,
      /** @brief Reference to CanMainFunctionPeriod */
      .MainfunctionId = 0U,
	}

};

/**
 * @brief can controller config
 */
static CONST(Can_ControllerType, CAN_CONST) Can_ControllerConfig[CAN_TOTAL_USED_NUMBER] = {
/* Can 0 Config */
  [0U] =
	{
	  /** @brief can id */
	  .HardwareID = (Can_HwHandleType)CAN_HW_CONTROLLER_CANFD6,
	  /** @brief can work mode */
	  .WorkMode = CAN_NORMAL_MODE,
	  /** @brief Enable/Disable IO connection to internal bus */
	  .ConnectInternalBusEnabled = FALSE,
	  /** @brief Set Protocol Enable rx IO connection to internal bus */
	  .RxConnectInternalBusEnabled = FALSE,
	  /** @brief Set Protocol Exception */
	  .ProtocolEnabled = TRUE,
	  /** @brief Set Edge Filter */
	  .EdgeFilterEnabled = TRUE,
	  /** @brief clock source */
	  .ClockSource = CAN_CLOCKSOURCE_SCLK,
	  /** @brief Set Clock Division */
	  .Division = CAN_CLOCK_DIVISION_3,
#if (CAN_CANFD_MODE == STD_ON)
	  /** @brief CanFd mail box size */
	  .MailBoxBlockSize0 = CAN_PAYLOAD_8BYTE,
	  /** @brief CanFd mail box size */
	  .MailBoxBlockSize1 = CAN_PAYLOAD_8BYTE,
#endif		
	  /** @brief Interrupt config */
	  .InterruptConfigPtr = &Can_IntrConfig[0U],
	  /** @brief Arbitrate Segment Baudrate Config */
	  .ArbitrateBDRArrayConfigPtr = &Can_BDRArrayConfig[0U],
#if (CAN_CANFD_MODE == STD_ON)
	  /** @brief CanFd config */
	  .CanFdConfigPtr = &Can_ControllerFdConfig[0U],
#endif
	  /** @brief can controller information */
	  .DescriptorPtr = &Can_ControllerDescriptor[0U],
	}
};

/**
 * @brief can config information
 */
CONST(Can_ConfigType, CAN_CONST)
Can_ConfigPredefined = {
  /** @brief can controller config */
  .CanControllerSets = &Can_ControllerConfig[0],
  /** @brief can HOH information config */
  .CanHOHSets = &Can_ControllerHOHConfig[0],
  /** @brief HOH config number */
  .CanHOHNumber = sizeof(Can_ControllerHOHConfig) / sizeof(Can_HOHType),
};
/******************************************************************************
 ** 					 Function definitions
 ******************************************************************************/
void __attribute__((weak)) Can0_UserErrorNotification(void) 
{
    // Add your implementation here
}
void __attribute__((weak))Can0_UserOffNotification(void) 
{
    // set can start mode
}
Std_ReturnType __attribute__((weak)) Can0_TxNotification(Can_HwHandleType Hth)
{
	// Add your implementation here
	return E_OK;
}

/* EOF */
