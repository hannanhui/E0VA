/**************************************************************************************************/
/**
 * @file      : Spi_PBcfg.c
 * @brief     : Spi AUTOSAR level - Post-Build(PB) configuration file code template
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 2.0.0
 * @author    : Zhixin Semiconductor
 * @note      : None
 * 
 * @copyright : Copyright (c) 2021-2025 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup Spi_Module
 *  @{
 */

/** @addtogroup Spi_Configuration
 *  @brief Spi AUTOSAR level configuration
 *  @{
 */
#ifdef __cplusplus
extern "C"{
#endif

#include "Spi.h"
#include "Spi_Drvw.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */
#define SPI_PBCFG_C_VENDOR_ID                   0x00B3U
#define SPI_PBCFG_C_AR_RELEASE_MAJOR_VERSION    4U
#define SPI_PBCFG_C_AR_RELEASE_MINOR_VERSION    6U
#define SPI_PBCFG_C_AR_RELEASE_REVISION_VERSION 0U
#define SPI_PBCFG_C_SW_MAJOR_VERSION            2U
#define SPI_PBCFG_C_SW_MINOR_VERSION            0U
#define SPI_PBCFG_C_SW_PATCH_VERSION            0U

/* Check if current file and Spi.h are the same vendor */
#if (SPI_PBCFG_C_VENDOR_ID != SPI_VENDOR_ID)
    #error "Vendor ID of Spi_PBCfg.c and Spi.h are different"
#endif
/* Check if current file and Spi.h are the same Autosar version */
#if ((SPI_PBCFG_C_AR_RELEASE_MAJOR_VERSION    != SPI_AR_RELEASE_MAJOR_VERSION) || \
     (SPI_PBCFG_C_AR_RELEASE_MINOR_VERSION    != SPI_AR_RELEASE_MINOR_VERSION) || \
     (SPI_PBCFG_C_AR_RELEASE_REVISION_VERSION != SPI_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Spi_PBCfg.c and Spi.h are different"
#endif
/* Check if current file and Spi.h are the same Software version */
#if ((SPI_PBCFG_C_SW_MAJOR_VERSION != SPI_SW_MAJOR_VERSION) || \
     (SPI_PBCFG_C_SW_MINOR_VERSION != SPI_SW_MINOR_VERSION) || \
     (SPI_PBCFG_C_SW_PATCH_VERSION != SPI_SW_PATCH_VERSION))
    #error "Software Version of Spi_PBCfg.c and Spi.h are different"
#endif

/* Check if current file and Spi_Drvw.h are the same vendor */
#if (SPI_PBCFG_C_VENDOR_ID != SPI_DRVW_H_VENDOR_ID)
    #error "Vendor ID of Spi_PBCfg.c and Spi_Drvw.h are different"
#endif
/* Check if current file and Spi_Drvw.h are the same Autosar version */
#if ((SPI_PBCFG_C_AR_RELEASE_MAJOR_VERSION    != SPI_DRVW_H_AR_RELEASE_MAJOR_VERSION) || \
     (SPI_PBCFG_C_AR_RELEASE_MINOR_VERSION    != SPI_DRVW_H_AR_RELEASE_MINOR_VERSION) || \
     (SPI_PBCFG_C_AR_RELEASE_REVISION_VERSION != SPI_DRVW_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Spi_PBCfg.c and Spi_Drvw.h are different"
#endif
/* Check if current file and Spi_Drvw.h are the same Software version */
#if ((SPI_PBCFG_C_SW_MAJOR_VERSION != SPI_DRVW_H_SW_MAJOR_VERSION) || \
     (SPI_PBCFG_C_SW_MINOR_VERSION != SPI_DRVW_H_SW_MINOR_VERSION) || \
     (SPI_PBCFG_C_SW_PATCH_VERSION != SPI_DRVW_H_SW_PATCH_VERSION))
    #error "Software Version of Spi_PBCfg.c and Spi_Drvw.h are different"
#endif

/** @} end of Private_MacroDefinition */

/** @defgroup Private_TypeDefinition
 *  @{
 */

/** @} end of group Private_TypeDefinition */

/** @defgroup Private_VariableDefinition
 *  @{
 */
#define SPI_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Spi_MemMap.h"

#if (CPU_TYPE == CPU_TYPE_64)
VAR_ALIGN(static Spi_Drvw_BufferDescriptorType Spi_BufferMasterC_SPI1, (8))
#else
VAR_ALIGN(static Spi_Drvw_BufferDescriptorType Spi_BufferMasterC_SPI1, (4))
#endif


#define SPI_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Spi_MemMap.h"

#define SPI_START_SEC_VAR_INIT_UNSPECIFIED
#include "Spi_MemMap.h"



#define SPI_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Spi_MemMap.h"

#define SPI_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Spi_MemMap.h"

/**
* @brief Channel Configuration for Channel 'MasterC_SPI1'
*/
static const Spi_Drvw_ChannelConfigType Spi_ChannelConfig_MasterC_SPI1 =
{
    EB, /*!< BufferType IB or EB */
    8U, /*!< FrameSize */
    (boolean)FALSE, /*!< Lsb */
    (uint32)1U, /*!< DefaultTransmitValue */
    100U, /*!< Length for SpiEbMaxLength */
    &Spi_BufferMasterC_SPI1, /*!< BufferDescriptor */
    0U, /*!< SpiCoreUse */
    &Spi_ChannelStateArray[0U] /*!< ChannelState */
};


/**
* @brief Channel Configuration list: Spi_ChannelConfigList[1]
*/
static const Spi_ChannelConfigListType Spi_ChannelConfigList[1] =
{
    {&Spi_ChannelConfig_MasterC_SPI1}
};


/**
* @brief Channel Assignment of Jobs
*/
static const Spi_ChannelType Spi_ChannelAssignment_MasterJ_SPI1[1] =
{
    SpiConf_SpiChannel_MasterC_SPI1
};

/**
* @brief Job Configuration for Job 'MasterJ_SPI1'
*/
static const Spi_JobConfigType Spi_JobConfig_MasterJ_SPI1 =
{
    (Spi_ChannelType)1U, /*!< ChannelNum field */
    Spi_ChannelAssignment_MasterJ_SPI1, /*!< List of Channels */
    &Cbk_Spi1_Master_JobEndNotification, /*!< End Notification */
    &Cbk_Spi1_Master_JobStartNotification, /*!< Start Notification */
    (sint8)0, /*!< Priority */
    0U, /*!< Core ID */
    &Spi_JobStateArray[0], /* Pointer to Job State */
    CSIB0, /*!< HWUnit index */
    SPI_EXTERNAL_DEVICE_CONF_SPIEXTERNALDEVICE_MASTER, /*!< External Device */
    &Spi_ExternalDeviceConfigList[SPI_EXTERNAL_DEVICE_CONF_SPIEXTERNALDEVICE_MASTER] /*!< ExternalDeviceConfig */
};


/**
* @brief Job Configuration list: Spi_JobConfigList[1]
*/
static const Spi_JobConfigListType Spi_JobConfigList[1] =
{
    {&Spi_JobConfig_MasterJ_SPI1}
};


/**
* @brief Job Assignment of Sequences
*/
static const Spi_JobType Spi_JobAssignment_MasterS_SPI1[1] =
{
    SpiConf_SpiJob_MasterJ_SPI1
};

/**
* @brief Sequence Configuration for Sequence 'MasterS_SPI1'
*/
static const Spi_SequenceConfigType Spi_SequenceConfig_MasterS_SPI1 =
{
    (Spi_JobType)1U, /* JobNum */
    0U, /* SpiCoreUse */
    Spi_JobAssignment_MasterS_SPI1, /* List of Jobs */
    &Cbk_Spi1_Master_SeqEndNotification, /* End Notification */
    (uint8)FALSE /* Interruptible */
};


/**
* @brief Sequence Configuration list: Spi_SequenceConfigList[1]
*/
static const Spi_SequenceConfigListType Spi_SequenceConfigList[1] =
{
    {&Spi_SequenceConfig_MasterS_SPI1},
};


#define SPI_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Spi_MemMap.h"

/** @} end of group Private_VariableDefinition */

/** @defgroup Global_VariableDefinition
 *  @{
 */

#define SPI_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Spi_MemMap.h"

/**
* @brief SPI Configuration
*/
static const Spi_ConfigType Spi_Config=
{
    1U, /*!< Configured External Devices */
    0U, /*!< Configured Channels */
    0U, /*!< Configured Jobs */
    0U, /*!< Configured Sequences */
    0U, /*!< SpiCoreUse */
    Spi_ChannelConfigList, /*!< ChannelConfigList */
    Spi_JobConfigList, /*!< JobConfigList */
    Spi_SequenceConfigList, /*!< SequenceConfigList */
    Spi_ExternalDeviceConfigList, /*!< ExternalDeviceConfigList */
    Spi_HwUnitConfigList /*!< HWUnitConfigList */
};


#define SPI_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Spi_MemMap.h"

#define SPI_START_SEC_CONFIG_DATA_PTR
#include "Spi_MemMap.h"

/**
* @brief Pointer to SPI Configuration
*/
const Spi_ConfigType * const Spi_PreDefinedConfigPtr[SPI_MAX_PARTITIONS]=
{
    &Spi_Config
};


#define SPI_STOP_SEC_CONFIG_DATA_PTR
#include "Spi_MemMap.h"
/** @} end of group Global_VariableDefinition */

/** @defgroup Private_FunctionDeclaration
 *  @{
 */

/** @} end of group Private_FunctionDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */
/** @} end of group Public_FunctionDeclaration */

/** @defgroup Private_FunctionDefinition
 *  @{
 */

/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDefinition
 *  @{
 */

/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Spi_Configuration */

/** @} end of group Spi_Module */
