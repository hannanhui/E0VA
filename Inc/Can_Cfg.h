/***************************************************************************************************/
/**
 * @file      : Can_Cfg.h  
 * @brief     : Can AUTOSAR level - Pre-Compile(PC) configuration file code template
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 2.0.0
 * @author    : Zhixin Semiconductor
 * @note      : None
 * 
 * @copyright : Copyright (c) 2021-2025 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef CAN_CFG_H
#define CAN_CFG_H

/** @addtogroup Can_Module
 *  @{
 */

/** @addtogroup Can_Configuration
 *  @brief Can AUTOSAR level configuration
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

#include "Can_PBcfg.h"

/** @defgroup Public_MacroDefinition
*  @{
*/

/* Published information */
#define CAN_CFG_H_VENDOR_ID                   0x00B3U
#define CAN_CFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define CAN_CFG_H_AR_RELEASE_MINOR_VERSION    6U
#define CAN_CFG_H_AR_RELEASE_REVISION_VERSION 0U
#define CAN_CFG_H_SW_MAJOR_VERSION            2U
#define CAN_CFG_H_SW_MINOR_VERSION            0U
#define CAN_CFG_H_SW_PATCH_VERSION            0U

/* Check if current file and Can_PBcfg.h are of the same vendor */
#if (CAN_CFG_H_VENDOR_ID != CAN_PBCFG_H_VENDOR_ID)
#error "Vendor ID of Can_Cfg.h and Can_PBcfg.h are different"
#endif
/* Check if current file and Can_PBcfg.h are of the same Autosar version */
#if ((CAN_CFG_H_AR_RELEASE_MAJOR_VERSION != CAN_PBCFG_H_AR_RELEASE_MAJOR_VERSION) || \
(CAN_CFG_H_AR_RELEASE_MINOR_VERSION != CAN_PBCFG_H_AR_RELEASE_MINOR_VERSION) || \
(CAN_CFG_H_AR_RELEASE_REVISION_VERSION != CAN_PBCFG_H_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version of Can_Cfg.h and Can_PBcfg.h are different"
#endif
/* Check if current file and Can_PBcfg.h are of the same software version */
#if ((CAN_CFG_H_SW_MAJOR_VERSION != CAN_PBCFG_H_SW_MAJOR_VERSION) || \
(CAN_CFG_H_SW_MINOR_VERSION != CAN_PBCFG_H_SW_MINOR_VERSION) ||\
(CAN_CFG_H_SW_PATCH_VERSION != CAN_PBCFG_H_SW_PATCH_VERSION))
#error "Software Version of Can_Cfg.h and Can_PBcfg.h are different"
#endif

/**
*   @brief      Message buffer index which not assigned for any Hw Object
*/
#define CAN_HWOBJ_UNMAPPED    ((Can_HwHandleType)0xFFU)

/**
*  @brief      Number Of Can Controller Config
*/
#define CAN_HWNUMBER_SUPPORT    4U

/**
*  @brief      CAN wake polling mask 
*/
#define CAN_WAKE_POLLING_MASK        (0x00000001U)

/**
*  @brief      The definition represent for number of ECUC partition configured.
*/
#define CAN_MAX_PARTITIONS    1U

/**
*  @brief      Enable/Disable Precompile Support
*/
#define CAN_PRECOMPILE_SUPPORT    (STD_ON)


/**
*   @brief      Enable/Disable support Can_GetVersionInfo API
*/
#define CAN_VERSION_INFO_API    (STD_ON)

/**
*  @brief Enable/Disable Development Error Detection and Notification.
*/
#define CAN_DEV_ERROR_DETECT    (STD_OFF)

/**
*   @brief      Instance of the Can Hw unit
*/
#define CAN_INSTANCE    ((uint8)0U)

/**
*   @brief     Enable/Disable  baudrate support
*/
#define CAN_SET_BAUDRATE_API    (STD_OFF)

/**
*   @brief      Enable/Disable support Can_AbortHwObjectSend API
*/
#define CAN_ABORT_HW_OBJECT_SEND_API    (STD_OFF)

/**
*   @brief      Enable/Disable support SecurityEventReporting
*/
#define CAN_SEC_EVENT_REPORT_SUPPORT    (STD_OFF)

/**
* @brief          Enable/Disable LPdu Receive callout function support
*/
#define CAN_LPDU_CALLOUT_SUPPORT    (STD_OFF)


/**
*   @brief      Define period of CAN Tx/Rx
*/
#define CAN_MAINFUNCTION_MULTIPLE_WRITE    (STD_OFF)
#define CAN_MAINFUNCTION_MULTIPLE_READ    (STD_OFF)

/**
*   @brief      Can MainFunction period
*/
#define CAN_MAINFUNCTION_MODE_PERIOD    (0.001F)



/**
*   @brief       trigger transmit configure.
*/
#define CAN_TRIGGER_TRANSMIT_USED    (STD_OFF)

/**
*   @brief      Can Rx/Tx common interrupt support
*/
#define CAN_MB_INTERRUPT_SUPPORT    (STD_ON)
/**
*   @brief     Can controller configure number
*/
#define CAN_CONTROLLER_CONFIG_COUNT    (1U)

/**
*   @brief      Number Of Hw Message Buffer support
*/
#define CAN_HWMB_COUNT    ((uint8)64U)

/**
*   @brief      HardwareObject Config Number 
*/
#define CAN_HWOBJECT_CONFIG_COUNT    ((Can_HwHandleType)23U)

/**
*   @brief      Symbolic Name generated for Can Controller
*/
#define CanConf_CanController_CanController_CAN0    ((uint8)0U)

/**
*   @brief      Symbolic Name generated for Can HardwareObject
*/
#define CanConf_CanHardwareObject_MC_BodyCAN_0x100    ((Can_HwHandleType)0U)
#define CanConf_CanHardwareObject_MC_BodyCAN_0x103    ((Can_HwHandleType)1U)
#define CanConf_CanHardwareObject_MC_BodyCAN_0x106    ((Can_HwHandleType)2U)
#define CanConf_CanHardwareObject_MC_BodyCAN_0x107    ((Can_HwHandleType)3U)
#define CanConf_CanHardwareObject_MC_BodyCAN_0x10B    ((Can_HwHandleType)4U)
#define CanConf_CanHardwareObject_MC_BodyCAN_0x143    ((Can_HwHandleType)5U)
#define CanConf_CanHardwareObject_MC_BodyCAN_0x192    ((Can_HwHandleType)6U)
#define CanConf_CanHardwareObject_MC_BodyCAN_0x1AA    ((Can_HwHandleType)7U)
#define CanConf_CanHardwareObject_MC_BodyCAN_0x1D4    ((Can_HwHandleType)8U)
#define CanConf_CanHardwareObject_MC_TABFuncCtrl_BodyCAN_0x200    ((Can_HwHandleType)9U)
#define CanConf_CanHardwareObject_MC_BodyCanNMFr_0x537    ((Can_HwHandleType)10U)
#define CanConf_CanHardwareObject_MCToAllBodyCan_FuncDiagReqFr_0x7FF    ((Can_HwHandleType)11U)
#define CanConf_CanHardwareObject_MCToTAB_PhyDiagReqFr_0x736    ((Can_HwHandleType)12U)
#define CanConf_CanHardwareObject_TAB_BodyCAN_0x2A0_FuncSts    ((Can_HwHandleType)13U)
#define CanConf_CanHardwareObject_TAB_BodyCAN_0x2A1_FuncSts    ((Can_HwHandleType)14U)
#define CanConf_CanHardwareObject_TAB_BodyCAN_0x2A2_SnsrPrm    ((Can_HwHandleType)15U)
#define CanConf_CanHardwareObject_TAB_BodyCAN_0x2A3_SnsrPrm    ((Can_HwHandleType)16U)
#define CanConf_CanHardwareObject_TAB_BodyCAN_0x2A4_SnsrPrm    ((Can_HwHandleType)17U)
#define CanConf_CanHardwareObject_TAB_BodyCAN_0x2A5_FltSts    ((Can_HwHandleType)18U)
#define CanConf_CanHardwareObject_TAB_BodyCAN_0x2A6_PrmFr    ((Can_HwHandleType)19U)
#define CanConf_CanHardwareObject_TAB_BodyCAN_0x2A7_Info    ((Can_HwHandleType)20U)
#define CanConf_CanHardwareObject_TAB_BodyCanNMFr_0x536    ((Can_HwHandleType)21U)
#define CanConf_CanHardwareObject_TABToMC_DiagResFr_0x636    ((Can_HwHandleType)22U)

/**
*   @brief      Can WakeUp configure
*/
#define CAN_WAKEUP_FUNCTIONALITY_API    (STD_OFF)

/**
*   @brief      Instance of the Can wakeup
*/
#define CAN_WAKEUP_SUPPORT    (STD_OFF)

/**
*   @brief      Can Tx polling configure
*/
#define CAN_TX_POLLING_SUPPORT    (STD_OFF)
/**
*   @brief      Can Rx polling configure
*/
#define CAN_RX_POLLING_SUPPORT    (STD_OFF)
/**
*   @brief      Can bus off polling configure
*/
#define CAN_BUSOFF_POLLING_SUPPORT    (STD_OFF)

/**
*   @brief      Can Wakeup Polling configure
*/
#define CAN_WAKEUP_POLLING_SUPPORT    (STD_OFF)

/**
* @brief        Definition of none EcuM wakeup source defined
*/
#if (CAN_WAKEUP_SUPPORT == STD_ON)
#define CAN_NONE_ECUM_WAKEUP_SOURCE_REF     (0U)
#endif

/**
*  @brief Enable/Disable CAN FD mode
*/
#define CAN_FD_MODE_ENABLE          CAN_DRV_FD_MODE_ENABLE


/**
*   @brief     Define Name of CanMainFunction
*/

/**
 *  @brief      CAN bus off polling mask 
 */
#define CAN_BUSOFF_POLLING_MASK    (0x00000002U)

/**
*   @brief      Can error interrupt support
*/
#define CAN_ERROR_INTERRUPT_SUPPORT             CAN_DRV_ERROR_INTERRUPT_SUPPORT

/**
*   @brief      Can DMA feature support ot not
*/
#define CAN_FEATURE_HAS_DMA_ENABLE              CAN_DRV_FEATURE_HAS_DMA_ENABLE

/**
*   @brief      Can FD feature support or not
*/
#define CAN_FEATURE_HAS_FD                      CAN_DRV_FEATURE_HAS_FD

/**
*   @brief      Can ecc interrupt support
*/
#define CAN_ECC_INTERRUPT_SUPPORT               CAN_DRV_ECC_INTERRUPT_SUPPORT

/**
*   @brief      Can error injection support
*/
#define CAN_ERROR_INJECTION_SUPPORT             CAN_DRV_ERROR_INJECTION_SUPPORT

#if(STD_ON == CAN_ECC_INTERRUPT_SUPPORT)
/**
 *  @brief      CAN host memory mask 
 */
#define CAN_HOST_MEM_MASK    (0x00080000U)

/**
 *  @brief      CAN memory mask 
 */
#define CAN_MEM_MASK    (0x00040000U)

/**
 *  @brief      CAN correctable memory mask 
 */
#define CAN_COR_MEM_MASK    (0x00010000U)
#endif



/**
*   @brief      Instance of the Can bus off interrupt
*/
#define CAN_BUSOFF_INTERRUPT_SUPPORT    (STD_ON)


/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */
/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */

/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"

#define CAN_ERROR_NOTIFICATION_CFG_EXT \

#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

/** @} end of group Public_FunctionDeclaration */



#ifdef __cplusplus
}
#endif
/** @} end of group Can_Configuration */

/** @} end of group Can_Module */
#endif /* CAN_CFG_H */
