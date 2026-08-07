
/*************************************************************************************/
/**
 * @file      : Dio_Cfg.h
 * @brief     : AUTOSAR Dio configuration header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 2.0.0
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2025 Zhixin Semiconductor Ltd. All rights reserved.
 *************************************************************************************/

/** @addtogroup DIO_CFG
*   @{
*/
#ifndef DIO_CFG_H
#define DIO_CFG_H

#ifdef __cplusplus
extern "C" {
#endif



/** @defgroup Public_MacroDefinition
*  @{
*/
#define DIO_CFG_H_VENDOR_ID                   0x00B3U
#define DIO_CFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define DIO_CFG_H_AR_RELEASE_MINOR_VERSION    6U
#define DIO_CFG_H_AR_RELEASE_REVISION_VERSION 0U
#define DIO_CFG_H_SW_MAJOR_VERSION            2U
#define DIO_CFG_H_SW_MINOR_VERSION            0U
#define DIO_CFG_H_SW_PATCH_VERSION            0U

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if header file and Std_Types.h file are of the same Autosar version */
    #if ((DIO_CFG_H_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) ||   \
         (DIO_CFG_H_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version of Dio_Cfg.h and Std_Types.h are different"
    #endif
#endif

/**
* @brief          Enable or Disable Development Error Detection.
*/
#define DIO_DEV_ERROR_DETECT     (STD_OFF)

#if (DIO_DEV_ERROR_DETECT == STD_ON)
#endif 
/**
* @brief          Enable or Disable Dio module verion acquisition.
*/
#define DIO_VERSION_INFO_API   (STD_ON)

/**
* @brief          Enable or Disable function for flipping channel.
*
*/
#define DIO_FLIP_CHANNEL_API    (STD_ON)

/**
* @brief          Enable or Disable function for mask channel.
*
*/
#define DIO_MASKED_WRITE_PORT_API  (STD_ON)





/**
* @brief          Number of implemented ports.
*
*/
#define DIO_PORT_NUM            ((uint16)0x5U)      

/**
* @brief          The number of partition on the port
*/
#define DIO_PORT_PARTITION_NUM   ((uint16)5U)
 
/**
* @brief          Number of channels available on the implemented ports.
*/
#if (STD_ON == DIO_DEV_ERROR_DETECT)
#define DIO_CHANNEL_NUM           ((uint32)159U)
#endif

/**
* @brief The number of partition on the channel.
*/
#define DIO_CHANNEL_PARTITION_NUM   ((uint16)160U)

/**
* @brief          Mask representing no available channels on a port.
*/
#if (STD_ON == DIO_DEV_ERROR_DETECT)
    #define DIO_NO_AVAILABLE_CHANNEL_NUM   ((Dio_PortLevelType)0x0U)
#endif


/**
* @brief          Mask representing the maximum valid offset for a channel group.
*/
#if (STD_ON == DIO_DEV_ERROR_DETECT)
    #define DIO_VALID_OFFSET_MAX         ((uint8)0x1FU)
#endif


/**
* @brief          Dio driver Pre-Compile configuration switch.
*/
#define DIO_PRECOMPILE_SUPPORT





/* ========== DioConfig ========== */

/* ---------- DioPort_A ---------- */ 

/**
* @brief          Symbolic name for the port DioPort_A.
*
*/
#define DioConf_DioPort_DioPort_A  ((uint8)0x00U)



/**
* @brief          Symbolic name for the channel VOLTAGE_DTC_EN.
*
*/
#define  DioConf_DioChannel_VOLTAGE_DTC_EN  ((uint16)0x0001U)


/**
* @brief          Symbolic name for the channel CAN0_ERR.
*
*/
#define  DioConf_DioChannel_CAN0_ERR  ((uint16)0x0011U)

/* ---------- DioPort_B ---------- */ 

/**
* @brief          Symbolic name for the port DioPort_B.
*
*/
#define DioConf_DioPort_DioPort_B  ((uint8)0x01U)



/**
* @brief          Symbolic name for the channel CAN0_EN.
*
*/
#define  DioConf_DioChannel_CAN0_EN  ((uint16)0x0031U)


/**
* @brief          Symbolic name for the channel CAN0_STB.
*
*/
#define  DioConf_DioChannel_CAN0_STB  ((uint16)0x002dU)

/* ---------- DioPort_C ---------- */ 

/**
* @brief          Symbolic name for the port DioPort_C.
*
*/
#define DioConf_DioPort_DioPort_C  ((uint8)0x02U)



/**
* @brief          Symbolic name for the channel PUMP_HSD_SEN.
*
*/
#define  DioConf_DioChannel_PUMP_HSD_SEN  ((uint16)0x0051U)


/**
* @brief          Symbolic name for the channel PUMP_HSD_IN.
*
*/
#define  DioConf_DioChannel_PUMP_HSD_IN  ((uint16)0x0050U)


/**
* @brief          Symbolic name for the channel SPI1_CS6.
*
*/
#define  DioConf_DioChannel_SPI1_CS6  ((uint16)0x0043U)


/**
* @brief          Symbolic name for the channel SPI1_CS5.
*
*/
#define  DioConf_DioChannel_SPI1_CS5  ((uint16)0x0042U)


/**
* @brief          Symbolic name for the channel SPI1_CS1.
*
*/
#define  DioConf_DioChannel_SPI1_CS1  ((uint16)0x0041U)


/**
* @brief          Symbolic name for the channel SPI1_CS2.
*
*/
#define  DioConf_DioChannel_SPI1_CS2  ((uint16)0x0040U)

/* ---------- DioPort_D ---------- */ 

/**
* @brief          Symbolic name for the port DioPort_D.
*
*/
#define DioConf_DioPort_DioPort_D  ((uint8)0x03U)



/**
* @brief          Symbolic name for the channel SPWR_EN.
*
*/
#define  DioConf_DioChannel_SPWR_EN  ((uint16)0x0068U)


/**
* @brief          Symbolic name for the channel SPI1_CS8.
*
*/
#define  DioConf_DioChannel_SPI1_CS8  ((uint16)0x0071U)


/**
* @brief          Symbolic name for the channel SPI1_CS9.
*
*/
#define  DioConf_DioChannel_SPI1_CS9  ((uint16)0x006eU)


/**
* @brief          Symbolic name for the channel SPI1_CS10.
*
*/
#define  DioConf_DioChannel_SPI1_CS10  ((uint16)0x006dU)


/**
* @brief          Symbolic name for the channel SPI1_CS4.
*
*/
#define  DioConf_DioChannel_SPI1_CS4  ((uint16)0x0066U)


/**
* @brief          Symbolic name for the channel SPI1_CS3.
*
*/
#define  DioConf_DioChannel_SPI1_CS3  ((uint16)0x0069U)


/**
* @brief          Symbolic name for the channel LIN0_S_CS.
*
*/
#define  DioConf_DioChannel_LIN0_S_CS  ((uint16)0x0062U)

/* ---------- DioPort_E ---------- */ 

/**
* @brief          Symbolic name for the port DioPort_E.
*
*/
#define DioConf_DioPort_DioPort_E  ((uint8)0x04U)



/**
* @brief          Symbolic name for the channel VALVE_HSD_SEN.
*
*/
#define  DioConf_DioChannel_VALVE_HSD_SEN  ((uint16)0x008eU)


/**
* @brief          Symbolic name for the channel VALVE_HSD_IN.
*
*/
#define  DioConf_DioChannel_VALVE_HSD_IN  ((uint16)0x0083U)


/**
* @brief          Symbolic name for the channel SPI1_CS7.
*
*/
#define  DioConf_DioChannel_SPI1_CS7  ((uint16)0x008cU)


/**
* @brief          Symbolic name for the channel LIN1_M_CS.
*
*/
#define  DioConf_DioChannel_LIN1_M_CS  ((uint16)0x0087U)


/**
* @brief          Symbolic name for the channel IGN_ACT.
*
*/
#define  DioConf_DioChannel_IGN_ACT  ((uint16)0x0081U)


/**
* @brief          Symbolic name for the channel LIN_CAN_WAKE.
*
*/
#define  DioConf_DioChannel_LIN_CAN_WAKE  ((uint16)0x008dU)

/** @} end of group Public_MacroDefinition */



/** @defgroup Global_VariableDefinition
 *  @{
 */

/**
* @brief Array: the available pins in each port.
*/
#define DIO_CONFIG_AVAILABLE_PIN \
extern const Dio_PortLevelType Dio_AvailablePinsForWrite[DIO_PORT_NUM];\
extern const Dio_PortLevelType Dio_AvailablePinsForRead[DIO_PORT_NUM];

#define DIO_CONFIG_GROUP_LIST
#define DIO_CONFIG_GROUP_PARTITION
/** @} end of group Global_VariableDefinition */



#ifdef __cplusplus
}
#endif

#endif  /* DIO_CFG_H */

/** @} end of group DIO_CFG */

