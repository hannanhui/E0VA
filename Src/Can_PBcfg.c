/**************************************************************************************************/
/**
 * @file      : Can_PBcfg.c
 * @brief     : Can AUTOSAR level - Post-Build(PB) configuration file code template
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 2.0.0
 * @author    : Zhixin Semiconductor
 * @note      : None
 * 
 * @copyright : Copyright (c) 2021-2025 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

/** @addtogroup Can_Module
 *  @{
 */

/** @addtogroup Can_Configuration
 *  @brief Can AUTOSAR level configuration
 *  @{
 */

#include "Can.h"
#include "Can_Drv.h"


/** @defgroup Private_MacroDefinition
 *  @{
 */

#define CAN_PBCFG_C_VENDOR_ID                   0x00B3U
#define CAN_PBCFG_C_AR_RELEASE_MAJOR_VERSION    4U
#define CAN_PBCFG_C_AR_RELEASE_MINOR_VERSION    6U
#define CAN_PBCFG_C_AR_RELEASE_REVISION_VERSION 0U
#define CAN_PBCFG_C_SW_MAJOR_VERSION            2U
#define CAN_PBCFG_C_SW_MINOR_VERSION            0U
#define CAN_PBCFG_C_SW_PATCH_VERSION            0U

/* Check if current file and Can.h are of the same vendor */
#if (CAN_PBCFG_C_VENDOR_ID != CAN_VENDOR_ID)
    #error "Vendor ID of Can_PBcfg.c and Can.h are different"
#endif
/* Check if current file and Can.h are of the same Autosar version */
#if ((CAN_PBCFG_C_AR_RELEASE_MAJOR_VERSION   != CAN_AR_RELEASE_MAJOR_VERSION) || \
     (CAN_PBCFG_C_AR_RELEASE_MINOR_VERSION    != CAN_AR_RELEASE_MINOR_VERSION) || \
     (CAN_PBCFG_C_AR_RELEASE_REVISION_VERSION != CAN_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Can_PBcfg.c and Can.h are different"
#endif
/* Check if current file and Can.h are of the same Software version */
#if ((CAN_PBCFG_C_SW_MAJOR_VERSION  != CAN_SW_MAJOR_VERSION) || \
     (CAN_PBCFG_C_SW_MINOR_VERSION  != CAN_SW_MINOR_VERSION) || \
     (CAN_PBCFG_C_SW_PATCH_VERSION  != CAN_SW_PATCH_VERSION))
    #error "Software Version of Can_PBcfg.c and Can.h are different"
#endif

/* Check if current file and Can_Drv.h are of the same vendor */
#if (CAN_PBCFG_C_VENDOR_ID != CAN_DRV_H_VENDOR_ID)
    #error "Vendor ID of Can_PBcfg.c and Can_Drv.h are different"
#endif
/* Check if current file and Can_Drv.h are of the same Autosar version */
#if ((CAN_PBCFG_C_AR_RELEASE_MAJOR_VERSION   != CAN_DRV_H_AR_RELEASE_MAJOR_VERSION) || \
     (CAN_PBCFG_C_AR_RELEASE_MINOR_VERSION    != CAN_DRV_H_AR_RELEASE_MINOR_VERSION) || \
     (CAN_PBCFG_C_AR_RELEASE_REVISION_VERSION != CAN_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Can_PBcfg.c and Can_Drv.h are different"
#endif
/* Check if current file and Can_Drv.h are of the same Software version */
#if ((CAN_PBCFG_C_SW_MAJOR_VERSION  != CAN_DRV_H_SW_MAJOR_VERSION) || \
     (CAN_PBCFG_C_SW_MINOR_VERSION  != CAN_DRV_H_SW_MINOR_VERSION) || \
     (CAN_PBCFG_C_SW_PATCH_VERSION  != CAN_DRV_H_SW_PATCH_VERSION))
    #error "Software Version of Can_PBcfg.c and Can_Drv.h are different"
#endif

/** @} end of Private_MacroDefinition */

/** @defgroup Global_VariableDefinition
 *  @{
 */

#if (CAN_FEATURE_HAS_DMA_ENABLE == STD_ON)
    /* CAN_START_SEC_VAR_CLEARED_UNSPECIFIED */
    #define CAN_START_SEC_VAR_CLEARED_UNSPECIFIED
    #include "Can_MemMap.h"


    #define CAN_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #include "Can_MemMap.h"
    /* CAN_STOP_SEC_VAR_CLEARED_UNSPECIFIED */
#endif /* (CAN_FEATURE_HAS_DMA_ENABLE == STD_ON) */

#define CAN_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Can_MemMap.h"



/**
* @brief   Export CAN configurations.
*/

static const Can_HwChannelConfigType Can_HwChannelConfig0 =
{
    /* Here should be included the structure from CAN*/
    &Can_Drv_CtrlConfig[0U]
};

/* Can_HardwareFilterType */
static const Can_HardwareFilterType Can_HwFilterObject0=
{
                                
    (uint32)0x00000100U,
    (uint32)0xdffc0000U

};
static const Can_HardwareFilterType Can_HwFilterObject1=
{
                                
    (uint32)0x00000103U,
    (uint32)0xdffc0000U

};
static const Can_HardwareFilterType Can_HwFilterObject2=
{
                                
    (uint32)0x00000106U,
    (uint32)0xdffc0000U

};
static const Can_HardwareFilterType Can_HwFilterObject3=
{
                                
    (uint32)0x00000107U,
    (uint32)0xdffc0000U

};
static const Can_HardwareFilterType Can_HwFilterObject4=
{
                                
    (uint32)0x0000010bU,
    (uint32)0xdffc0000U

};
static const Can_HardwareFilterType Can_HwFilterObject5=
{
                                
    (uint32)0x00000143U,
    (uint32)0xdffc0000U

};
static const Can_HardwareFilterType Can_HwFilterObject6=
{
                                
    (uint32)0x00000192U,
    (uint32)0xdffc0000U

};
static const Can_HardwareFilterType Can_HwFilterObject7=
{
                                
    (uint32)0x000001aaU,
    (uint32)0xdffc0000U

};
static const Can_HardwareFilterType Can_HwFilterObject8=
{
                                
    (uint32)0x000001d4U,
    (uint32)0xdffc0000U

};
static const Can_HardwareFilterType Can_HwFilterObject9=
{
                                
    (uint32)0x00000200U,
    (uint32)0xdffc0000U

};
static const Can_HardwareFilterType Can_HwFilterObject10=
{
                                
    (uint32)0x00000537U,
    (uint32)0xdf000000U

};
static const Can_HardwareFilterType Can_HwFilterObject11=
{
                                
    (uint32)0x000007ffU,
    (uint32)0xdffc0000U

};
static const Can_HardwareFilterType Can_HwFilterObject12=
{
                                
    (uint32)0x00000736U,
    (uint32)0xdffc0000U

};



/**
*   @brief  Can Hardware Object Config
*/
static const Can_HwObjConfigType Can_HwObjectConfig[CAN_HWOBJECT_CONFIG_COUNT]=
{
    
    {
        
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)0,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject0,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)0U,
    },
    
    
    {
        
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)1,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject1,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)1U,
    },
    
    
    {
        
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)2,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject2,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)2U,
    },
    
    
    {
        
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)3,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject3,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)3U,
    },
    
    
    {
        
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)4,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject4,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)4U,
    },
    
    
    {
        
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)5,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject5,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)5U,
    },
    
    
    {
        
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)6,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject6,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)6U,
    },
    
    
    {
        
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)7,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject7,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)7U,
    },
    
    
    {
        
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)8,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject8,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)8U,
    },
    
    
    {
        
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)9,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject9,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)9U,
    },
    
    
    {
        
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_BASIC,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)10,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject10,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)10U,
    },
    
    
    {
        
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)11,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject11,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)11U,
    },
    
    
    {
        
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_FULL,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)12,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_HwFilterObject12,
        /* Hardware Object handle type */
        CAN_OBJ_RECEIVE,
        /* Buffer Index in Message buffer ram */
        (uint8)12U,
    },
    
    
    {
        
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_BASIC,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)13,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)0U,
        /* Hw Filter Config */
        NULL_PTR,
        /* Message Buffer is Tx normal */
        CAN_OBJ_TRANSMIT,
        /* Buffer Index in Message buffer ram */
        (uint8)13U,
    },
    
    
    {
        
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_BASIC,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)14,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)0U,
        /* Hw Filter Config */
        NULL_PTR,
        /* Message Buffer is Tx normal */
        CAN_OBJ_TRANSMIT,
        /* Buffer Index in Message buffer ram */
        (uint8)14U,
    },
    
    
    {
        
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_BASIC,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)15,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)0U,
        /* Hw Filter Config */
        NULL_PTR,
        /* Message Buffer is Tx normal */
        CAN_OBJ_TRANSMIT,
        /* Buffer Index in Message buffer ram */
        (uint8)15U,
    },
    
    
    {
        
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_BASIC,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)16,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)0U,
        /* Hw Filter Config */
        NULL_PTR,
        /* Message Buffer is Tx normal */
        CAN_OBJ_TRANSMIT,
        /* Buffer Index in Message buffer ram */
        (uint8)16U,
    },
    
    
    {
        
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_BASIC,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)17,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)0U,
        /* Hw Filter Config */
        NULL_PTR,
        /* Message Buffer is Tx normal */
        CAN_OBJ_TRANSMIT,
        /* Buffer Index in Message buffer ram */
        (uint8)17U,
    },
    
    
    {
        
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_BASIC,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)18,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)0U,
        /* Hw Filter Config */
        NULL_PTR,
        /* Message Buffer is Tx normal */
        CAN_OBJ_TRANSMIT,
        /* Buffer Index in Message buffer ram */
        (uint8)18U,
    },
    
    
    {
        
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_BASIC,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)19,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)0U,
        /* Hw Filter Config */
        NULL_PTR,
        /* Message Buffer is Tx normal */
        CAN_OBJ_TRANSMIT,
        /* Buffer Index in Message buffer ram */
        (uint8)19U,
    },
    
    
    {
        
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_BASIC,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)20,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)0U,
        /* Hw Filter Config */
        NULL_PTR,
        /* Message Buffer is Tx normal */
        CAN_OBJ_TRANSMIT,
        /* Buffer Index in Message buffer ram */
        (uint8)20U,
    },
    
    
    {
        
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_BASIC,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)21,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)0U,
        /* Hw Filter Config */
        NULL_PTR,
        /* Message Buffer is Tx normal */
        CAN_OBJ_TRANSMIT,
        /* Buffer Index in Message buffer ram */
        (uint8)21U,
    },
    
    
    {
        
        
        (uint8)0U,/*Specifies the Type of a hardware object*/
        (Can_HandleType)CAN_BASIC,
        /* IdValue is of Type  */
        CAN_MSG_ID_STANDARD,
        /* Holds the handle ID of HRH or HTH. */
        (Can_HwHandleType)22,
        /* Enables polling of this hardware object. */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Reference to CanMainFunctionPeriod */
        0xFFU,         
        
        /* Number of hardware objects used to implement one HOH */
        (uint8)1U,
        /* Specifies the maximum L-PDU Payload length */
        (uint8)8U,
        
        
        
        
        /* Hardware Filter Count */
        (uint8)0U,
        /* Hw Filter Config */
        NULL_PTR,
        /* Message Buffer is Tx normal */
        CAN_OBJ_TRANSMIT,
        /* Buffer Index in Message buffer ram */
        (uint8)22U,
    }
    
};
/**
*   @brief  Can Baudrate Config of 0
*/
static const Can_ControllerBaudrateConfigType Can_BaudrateConfigCtrl0[1U]=
{
    
    {
        
        (uint8)0U,                
        /* arbitration phase  */
        {
            
            (uint8)8U,
            (uint8)5U,
            (uint8)2U,
            (uint16)4U,
            (uint8)1U
        },
        /* FD enable */
        (boolean)FALSE,
        
        /* Can Fd Data Bit Rate */
        {
        (uint8)1U,
        (uint8)1U,
        (uint8)2U,
        (uint16)1U,
        (uint8)1U
        },
        /* Tx Bit Rate Switch */
        (boolean)FALSE,
        
        
        (boolean)FALSE,
        (uint8)0U
    }
    
};


static const Can_RxFifoConfigType Can_RxFiFOConfigCtr0=
{
    /* --- Default values when Legacy FIFO is not available --- */
    /* ID Acceptance Mode */
    CAN_RX_FIFO_FORMAT_A,
    /* Global mask of Legacy FIFO */
    (uint32)0xFFFFFFFFU,
    /* Legacy FIFO Overflow Notification */
    NULL_PTR,
    /* Legacy FIFO Warning Notification */
    NULL_PTR,
    /* Legacy FIFO avialbe Notification */
     NULL_PTR,
    
};

#define CAN_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Can_MemMap.h"

#define CAN_START_SEC_CONFIG_DATA_PTR
#include "Can_MemMap.h"


/**
*   @brief  CAN Hardware Object Type of CanControllerId_0
*/
static const Can_HwObjConfigType * const Can_HwObjectCfgPtr0[23U]=
{
    &Can_HwObjectConfig[0U],
    
    &Can_HwObjectConfig[1U],
    
    &Can_HwObjectConfig[2U],
    
    &Can_HwObjectConfig[3U],
    
    &Can_HwObjectConfig[4U],
    
    &Can_HwObjectConfig[5U],
    
    &Can_HwObjectConfig[6U],
    
    &Can_HwObjectConfig[7U],
    
    &Can_HwObjectConfig[8U],
    
    &Can_HwObjectConfig[9U],
    
    &Can_HwObjectConfig[10U],
    
    &Can_HwObjectConfig[11U],
    
    &Can_HwObjectConfig[12U],
    
    &Can_HwObjectConfig[13U],
    
    &Can_HwObjectConfig[14U],
    
    &Can_HwObjectConfig[15U],
    
    &Can_HwObjectConfig[16U],
    
    &Can_HwObjectConfig[17U],
    
    &Can_HwObjectConfig[18U],
    
    &Can_HwObjectConfig[19U],
    
    &Can_HwObjectConfig[20U],
    
    &Can_HwObjectConfig[21U],
    
    &Can_HwObjectConfig[22U]
    
};


#define CAN_STOP_SEC_CONFIG_DATA_PTR
#include "Can_MemMap.h"


#define CAN_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Can_MemMap.h"


static const Can_ControllerConfigType Can_ControllerConfig[CAN_CONTROLLER_CONFIG_COUNT]=
{
        {
        #if (CAN_WAKEUP_SUPPORT == STD_ON)
        (uint32)CAN_NONE_ECUM_WAKEUP_SOURCE_REF, 
        
        /*!< Source Wakeup Enable Status*/
        (boolean)FALSE,
        #endif
        /* Controller ID */
        (uint8)0U,
        /* Current Can interface index  */
        
        (uint8)0U,            
        /* Current Can Controller Offset */
        (uint8)0U,
        /* Can Controller active Status configure bit */
        (boolean)TRUE,
        &Can_RxFiFOConfigCtr0,
        /* Bus Off uses polling */
        (0x00000000U),      
        /* Error interrupt enable */
        (boolean)FALSE,
        
        /* Error Notification */
        NULL_PTR,
        
        /* Error FD Notification */
        NULL_PTR,
        /* Default Baudrate ID */
        (uint16)0U,
        /* Number of Can baudrate*/
        (uint16)1U,
        /* pointer to Can baudrate configure */
        Can_BaudrateConfigCtrl0,
        /* Number of Can hardware referred to current controller */
        (uint8)23U,
        /* Pointer point to Group of Hw Object that refer to Controller */
        Can_HwObjectCfgPtr0,      
        /* Pointer to hardware channel configuration */
        &Can_HwChannelConfig0,
        #if (CAN_FEATURE_HAS_DMA_ENABLE == STD_ON)
        /* FIFO Dma Error Notification */
        NULL_PTR,
        /* DMA is not enabled */
        NULL_PTR,
        #endif /* (CAN_FEATURE_HAS_DMA_ENABLE == STD_ON) */
        #if (CAN_ECC_INTERRUPT_SUPPORT == STD_ON)
        /* Can ecc interrupt enable */
        0,
        /* Notification */
        NULL_PTR,
        
        /* Notification */
        NULL_PTR,
        
        /* Notification */
        NULL_PTR,
        
        #endif
        FALSE,
    }
};

#define CAN_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Can_MemMap.h"

#define CAN_START_SEC_CONFIG_DATA_PTR
#include "Can_MemMap.h"

static const Can_ControllerConfigType * const Can_ControllerPtr[CAN_CONTROLLER_CONFIG_COUNT]=
{
    &Can_ControllerConfig[0U]
    
};

#define CAN_STOP_SEC_CONFIG_DATA_PTR
#include "Can_MemMap.h"


/** @} end of group Global_VariableDefinition */

/** @defgroup Private_VariableDefinition
 *  @{
 */

#define CAN_START_SEC_CONFIG_DATA_8
#include "Can_MemMap.h"
/*Can_CtrlOffsetToCtrlIDMap and Can_HwObjIDToCtrlIDMap  */


/**
*   @brief  The index corresponds to the actual sequence Value
*/
static const uint8 Can_CtrlOffsetToCtrlIDMap[CAN_HWNUMBER_SUPPORT]=
{        
    
    (uint8)0,
    
    (uint8)CAN_HWOBJ_UNMAPPED,
    
    (uint8)CAN_HWOBJ_UNMAPPED,
    
    (uint8)CAN_HWOBJ_UNMAPPED
};
/**
*   @brief  Controller ID corresponds to Hardware Object ID
*/
static const uint8 Can_HwObjIDToCtrlIDMap[CAN_HWOBJECT_CONFIG_COUNT]=
{
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U
};

#define CAN_STOP_SEC_CONFIG_DATA_8
#include "Can_MemMap.h"

#define CAN_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Can_MemMap.h"


/**
*   @brief This structure is All dirver Configure  
*/

static const Can_ConfigType Can_Config =
{
    
    /* default core id is 0 cause not support multicore*/
    (uint32)0U,
    /* Can Tx First Index*/
    (Can_HwHandleType)13U,
    /*Can controller number */
    CAN_CONTROLLER_CONFIG_COUNT,
    /*  The index corresponds to the actual sequence Value*/
    Can_CtrlOffsetToCtrlIDMap,
    /*Hardware object Counter*/
    CAN_HWOBJECT_CONFIG_COUNT,
    /* Controller ID corresponds to Hardware Object ID  */
    Can_HwObjIDToCtrlIDMap,
    /* Pointer point to Can Hw Object Config */
    Can_HwObjectConfig,
    /* Array of Pointer to Controller infomation have aligned by Controller ID */
    Can_ControllerPtr

};


#define CAN_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Can_MemMap.h"

#define CAN_START_SEC_CONFIG_DATA_PTR
#include "Can_MemMap.h"


const Can_ConfigType * const  Can_PreDefinedConfigPtr[CAN_MAX_PARTITIONS] =
{
    &Can_Config,

};

#define CAN_STOP_SEC_CONFIG_DATA_PTR
#include "Can_MemMap.h"

/** @} end of group Private_VariableDefinition */

/** @defgroup Private_FunctionDeclaration
 *  @{
 */

/** @} end of group Private_FunctionDeclaration */

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

/** @} end of group Can_Configuration */

/** @} end of group Can_Module */
