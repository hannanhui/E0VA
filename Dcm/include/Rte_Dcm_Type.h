/**
 * @file        Rte_Dcm_Type.h
 * @brief       AUTOSAR 4.2.2 - 4.2.2 driver header file.
 * @details     Rte driver header file, containing the Autosar API specification and
 *              other variables and functions that are exported by the Rte driver.
 * @version     1.2.0
 *
 * @addtogroup  Rte
 * @{
 */
/*====================================================================================================*
 * AngHui AUTOSAR BSW.
 *
 * Copyright(C) 2023 GuoKeAngHui Inc.
 *
 * All rights reserved.
 *
 * This file is part of AngHui AUTOSAR BSW, contains proprietary information.
 * Passing on and copying of this document, and communication of its contents
 * is not permitted without prior written authorization.
 *====================================================================================================*/

#ifndef RTE_DCM_TYPE_H
#define RTE_DCM_TYPE_H

#ifdef __cplusplus
extern "C"{
#endif

/*====================================================================================================*
 *                                           INCLUDE FILES
 *====================================================================================================*/
#include "Std_Types.h"
/*====================================================================================================*
 *                                  HEADER FILE VERSION INFORMATION
 *====================================================================================================*/
#define RTE_DCM_TYPE_VENDOR_ID	                            (0x00U)
#define RTE_DCM_TYPE_AR_RELEASE_MAJOR_VERSION	            (0x04U)
#define RTE_DCM_TYPE_AR_RELEASE_MINOR_VERSION	            (0x02U)
#define RTE_DCM_TYPE_AR_RELEASE_REVISION_VERSION	        (0x02U)
#define RTE_DCM_TYPE_SW_MAJOR_VERSION	                    (0x01U)
#define RTE_DCM_TYPE_SW_MINOR_VERSION	                    (0x02U)
#define RTE_DCM_TYPE_SW_PATCH_VERSION	                    (0x00U)
/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/

/*====================================================================================================*
 *                                             CONSTANTS
 *====================================================================================================*/

/*====================================================================================================*
 *                                         DEFINES AND MACROS
 *====================================================================================================*/
#define DCM_E_PENDING										((Std_ReturnType)0x0A)
#define DCM_E_COMPARE_KEY_FAILED							((Std_ReturnType)0x0B)
#define DCM_E_FORCE_RCRRP									((Std_ReturnType)0x0C)

/* @req [SWS_Dcm_00984] */
typedef uint8 Dcm_OpStatusType;
#define DCM_INITIAL											((Dcm_OpStatusType)0x00)
#define DCM_PENDING											((Dcm_OpStatusType)0x01)
#define DCM_CANCEL											((Dcm_OpStatusType)0x02)
#define DCM_FORCE_RCRRP_OK									((Dcm_OpStatusType)0x03)
#define DCM_FAILED											((Dcm_OpStatusType)0x08)

/* @req [SWS_Dcm_00983] */
typedef uint8 Dcm_ConfirmationStatusType;
#define DCM_RES_POS_OK										((Dcm_ConfirmationStatusType)0x00)
#define DCM_RES_POS_NOT_OK									((Dcm_ConfirmationStatusType)0x01)
#define DCM_RES_NEG_OK										((Dcm_ConfirmationStatusType)0x02)
#define DCM_RES_NEG_NOT_OK									((Dcm_ConfirmationStatusType)0x03)

/* @req [SWS_Dcm_00977] */
typedef uint8 Dcm_SecLevelType;
#define DCM_SEC_LEV_LOCKED									((Dcm_SecLevelType)0x00)

/* @req [SWS_Dcm_00978] */
typedef uint8 Dcm_SesCtrlType;
#define DCM_DEFAULT_SESSION									((Dcm_SesCtrlType)0x01)
#define DCM_PROGRAMMING_SESSION								((Dcm_SesCtrlType)0x02)
#define DCM_EXTENDED_DIAGNOSTIC_SESSION						((Dcm_SesCtrlType)0x03)
#define DCM_SAFETY_SYSTEM_DIAGNOSTIC_SESSION				((Dcm_SesCtrlType)0x04)

/* @req [SWS_Dcm_00979] */
typedef uint8 Dcm_ProtocolType;
#define DCM_OBD_ON_CAN                      	 			((Dcm_ProtocolType)0x00)
#define	DCM_OBD_ON_FLEXRAY						  			((Dcm_ProtocolType)0x01)
#define	DCM_OBD_ON_IP							  			((Dcm_ProtocolType)0x02)
#define DCM_UDS_ON_CAN          	             			((Dcm_ProtocolType)0x03)
#define DCM_UDS_ON_FLEXRAY                   				((Dcm_ProtocolType)0x04)
#define	DCM_UDS_ON_IP						  				((Dcm_ProtocolType)0x05)
#define DCM_ROE_ON_CAN                      			 	((Dcm_ProtocolType)0x06)
#define DCM_ROE_ON_FLEXRAY                  	 			((Dcm_ProtocolType)0x07)
#define	DCM_ROE_ON_IP							  			((Dcm_ProtocolType)0x08)
#define DCM_PERIODIC_ON_CAN         	         			((Dcm_ProtocolType)0x09)
#define DCM_PERIODIC_ON_FLEXRAY 	             			((Dcm_ProtocolType)0x0A)
#define DCM_PERIODIC_ON_IP		              				((Dcm_ProtocolType)0x0B)
#define	DCM_NO_ACTIVE_PROTOCOL				  				((Dcm_ProtocolType)0x0C)
#define DCM_SUPPLIER_1							  			((Dcm_ProtocolType)0xF0)
#define DCM_SUPPLIER_2							  			((Dcm_ProtocolType)0xF1)
#define DCM_SUPPLIER_3							  			((Dcm_ProtocolType)0xF2)
#define DCM_SUPPLIER_4							  			((Dcm_ProtocolType)0xF3)
#define DCM_SUPPLIER_5							  			((Dcm_ProtocolType)0xF4)
#define DCM_SUPPLIER_6							  			((Dcm_ProtocolType)0xF5)
#define DCM_SUPPLIER_7							  			((Dcm_ProtocolType)0xF6)
#define DCM_SUPPLIER_8							  			((Dcm_ProtocolType)0xF7)
#define DCM_SUPPLIER_9							  			((Dcm_ProtocolType)0xF8)
#define DCM_SUPPLIER_10						  				((Dcm_ProtocolType)0xF9)
#define DCM_SUPPLIER_11						  				((Dcm_ProtocolType)0xFA)
#define DCM_SUPPLIER_12						  				((Dcm_ProtocolType)0xFB)
#define DCM_SUPPLIER_13						  				((Dcm_ProtocolType)0xFC)
#define DCM_SUPPLIER_14						 				((Dcm_ProtocolType)0xFD)
#define DCM_SUPPLIER_15					  					((Dcm_ProtocolType)0xFE)

/* @req [SWS_Dcm_00980] */
typedef uint8 Dcm_NegativeResponseCodeType;
#define DCM_POS_RESP                             			((Dcm_NegativeResponseCodeType)0x00)
#define DCM_E_GENERALREJECT                             	((Dcm_NegativeResponseCodeType)0x10)
#define DCM_E_SERVICENOTSUPPORTED                       	((Dcm_NegativeResponseCodeType)0x11)
#define DCM_E_SUBFUNCTIONNOTSUPPORTED                   	((Dcm_NegativeResponseCodeType)0x12)
#define DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT			((Dcm_NegativeResponseCodeType)0x13)
#define	DCM_E_RESPONSETOOLONG								((Dcm_NegativeResponseCodeType)0x14)
#define DCM_E_BUSYREPEATREQUEST                         	((Dcm_NegativeResponseCodeType)0x21)
#define DCM_E_CONDITIONSNOTCORRECT                      	((Dcm_NegativeResponseCodeType)0x22)
#define DCM_E_REQUESTSEQUENCEERROR                      	((Dcm_NegativeResponseCodeType)0x24)
#define DCM_E_NORESPONSEFROMSUBNETCOMPONENT			 		((Dcm_NegativeResponseCodeType)0x25)
#define DCM_E_FAILUREPREVENTSEXECUTIONOFREQUESTEDACTION 	((Dcm_NegativeResponseCodeType)0x26)
#define DCM_E_REQUESTOUTOFRANGE                         	((Dcm_NegativeResponseCodeType)0x31)
#define DCM_E_SECURITYACCESSDENIED                     		((Dcm_NegativeResponseCodeType)0x33)
#define DCM_E_AUTHENTICATIONREQUIRED						((Dcm_NegativeResponseCodeType)0x34)
#define DCM_E_INVALIDKEY                               		((Dcm_NegativeResponseCodeType)0x35)
#define DCM_E_EXCEEDEDNUMBEROFATTEMPTS                  	((Dcm_NegativeResponseCodeType)0x36)
#define DCM_E_REQUIREDTIMEDELAYNOTEXPIRED               	((Dcm_NegativeResponseCodeType)0x37)
#define DCM_E_CERTIFICATEINVALIDTIMEPERIOD					((Dcm_NegativeResponseCodeType)0x50)
#define DCM_E_CERTIFICATEINVALIDSIGNATURE					((Dcm_NegativeResponseCodeType)0x51)
#define DCM_E_CERTIFICATEINVALIDCHAINOFTRUST				((Dcm_NegativeResponseCodeType)0x52)
#define DCM_E_CERTIFICATEINVALIDTYPE						((Dcm_NegativeResponseCodeType)0x53)
#define DCM_E_CERTIFICATEINVALIDFORMAT						((Dcm_NegativeResponseCodeType)0x54)
#define DCM_E_CERTIFICATEINVALIDCONTENT						((Dcm_NegativeResponseCodeType)0x55)
#define DCM_E_CERTIFICATEINVALIDSCOPE						((Dcm_NegativeResponseCodeType)0x56)
#define DCM_E_CERTIFICATEINVALIDCERTIFICATE					((Dcm_NegativeResponseCodeType)0x57)
#define DCM_E_OWNERSHIPVERIFICATIONFAILED					((Dcm_NegativeResponseCodeType)0x58)
#define DCM_E_CHALLENGECALCULATIONFAILED					((Dcm_NegativeResponseCodeType)0x59)
#define DCM_E_SETTINGACCESSRIGHTSFAILED						((Dcm_NegativeResponseCodeType)0x5A)
#define DCM_E_SESSIONKEYCREATIONORDERIVATIONFAILED			((Dcm_NegativeResponseCodeType)0x5B)
#define DCM_E_CONFIGURATIONDATAUSAGEFAILED					((Dcm_NegativeResponseCodeType)0x5C)
#define DCM_E_DEAUTHENTICATIONFAILED						((Dcm_NegativeResponseCodeType)0x5D)
#define DCM_E_UPLOADDOWNLOADNOTACCEPTED                 	((Dcm_NegativeResponseCodeType)0x70)
#define DCM_E_TRANSFERDATASUSPENDED                     	((Dcm_NegativeResponseCodeType)0x71)
#define DCM_E_GENERALPROGRAMMINGFAILURE                 	((Dcm_NegativeResponseCodeType)0x72)
#define DCM_E_WRONGBLOCKSEQUENCECOUNTER                 	((Dcm_NegativeResponseCodeType)0x73)
#define DCM_E_RESPONSE_PENDING                          	((Dcm_NegativeResponseCodeType)0x78)
#define DCM_E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION    	((Dcm_NegativeResponseCodeType)0x7E)
#define DCM_E_SERVICENOTSUPPORTEDINACTIVESESSION        	((Dcm_NegativeResponseCodeType)0x7F)
#define DCM_E_RPMTOOHIGH                                	((Dcm_NegativeResponseCodeType)0x81)
#define DCM_E_RPMTOOLOW                                 	((Dcm_NegativeResponseCodeType)0x82)
#define DCM_E_ENGINEISRUNNING                           	((Dcm_NegativeResponseCodeType)0x83)
#define DCM_E_ENGINEISNOTRUNNING                        	((Dcm_NegativeResponseCodeType)0x84)
#define DCM_E_ENGINERUNTIMETOOLOW       	           	    ((Dcm_NegativeResponseCodeType)0x85)
#define DCM_E_TEMPERATURETOOHIGH                        	((Dcm_NegativeResponseCodeType)0x86)
#define DCM_E_TEMPERATURETOOLOW                         	((Dcm_NegativeResponseCodeType)0x87)
#define DCM_E_VEHICLESPEEDTOOHIGH                 	      	((Dcm_NegativeResponseCodeType)0x88)
#define DCM_E_VEHICLESPEEDTOOLOW                    	    ((Dcm_NegativeResponseCodeType)0x89)
#define DCM_E_THROTTLE_PEDALTOOHIGH                	 	    ((Dcm_NegativeResponseCodeType)0x8A)
#define DCM_E_THROTTLE_PEDALTOOLOW            	       		((Dcm_NegativeResponseCodeType)0x8B)
#define DCM_E_TRANSMISSIONRANGENOTINNEUTRAL  	           	((Dcm_NegativeResponseCodeType)0x8C)
#define DCM_E_TRANSMISSIONRANGENOTINGEAR   	         	    ((Dcm_NegativeResponseCodeType)0x8D)
#define DCM_E_BRAKESWITCH_NOTCLOSED                     	((Dcm_NegativeResponseCodeType)0x8F)
#define DCM_E_SHIFTERLEVERNOTINPARK                 	    ((Dcm_NegativeResponseCodeType)0x90)
#define DCM_E_TORQUECONVERTERCLUTCHLOCKED       	        ((Dcm_NegativeResponseCodeType)0x91)
#define DCM_E_VOLTAGETOOHIGH                	            ((Dcm_NegativeResponseCodeType)0x92)
#define DCM_E_VOLTAGETOOLOW             	                ((Dcm_NegativeResponseCodeType)0x93)
#define DCM_E_VMSCNC_0              	               		((Dcm_NegativeResponseCodeType)0xF0)
#define DCM_E_VMSCNC_1          	                   		((Dcm_NegativeResponseCodeType)0xF1)
#define DCM_E_VMSCNC_2      	                       		((Dcm_NegativeResponseCodeType)0xF2)
#define DCM_E_VMSCNC_3  	                           		((Dcm_NegativeResponseCodeType)0xF3)
#define DCM_E_VMSCNC_4	                             		((Dcm_NegativeResponseCodeType)0xF4)
#define DCM_E_VMSCNC_5                             			((Dcm_NegativeResponseCodeType)0xF5)
#define DCM_E_VMSCNC_6                             			((Dcm_NegativeResponseCodeType)0xF6)
#define DCM_E_VMSCNC_7                          	   		((Dcm_NegativeResponseCodeType)0xF7)
#define DCM_E_VMSCNC_8                      	       		((Dcm_NegativeResponseCodeType)0xF8)
#define DCM_E_VMSCNC_9                  	           		((Dcm_NegativeResponseCodeType)0xF9)
#define DCM_E_VMSCNC_A              	               		((Dcm_NegativeResponseCodeType)0xFA)
#define DCM_E_VMSCNC_B          	                   		((Dcm_NegativeResponseCodeType)0xFB)
#define DCM_E_VMSCNC_C      	                       		((Dcm_NegativeResponseCodeType)0xFC)
#define DCM_E_VMSCNC_D   	                          		((Dcm_NegativeResponseCodeType)0xFD)
#define DCM_E_VMSCNC_E                            	 		((Dcm_NegativeResponseCodeType)0xFE)

/* @req [SWS_Dcm_01138] */
typedef uint8 Dcm_DidSupportedType;
#define DCM_DID_SUPPORTED									((Dcm_DidSupportedType)0x00)
#define DCM_DID_NOT_SUPPORTED								((Dcm_DidSupportedType)0x01)

typedef uint8 Dcm_EcuResetType;
#define RTE_MODE_DcmEcuReset_EXECUTE						((Dcm_EcuResetType)0x00)
#define RTE_MODE_DcmEcuReset_HARD							((Dcm_EcuResetType)0x01)
#define RTE_MODE_DcmEcuReset_KEYOFFONRESET					((Dcm_EcuResetType)0x02)
#define RTE_MODE_DcmEcuReset_SOFT							((Dcm_EcuResetType)0x03)
#define RTE_MODE_DcmEcuReset_ENABLE_RAPIDPOWERSHUTDOWN		((Dcm_EcuResetType)0x04)
#define RTE_MODE_DcmEcuReset_DISABLE_RAPIDPOWERSHUTDOWN		((Dcm_EcuResetType)0x05)
#define RTE_MODE_DcmEcuReset_JUMPTOBOOTLOADER				((Dcm_EcuResetType)0x06)
#define RTE_MODE_DcmEcuReset_JUMPTOSYSSUPPLIERBOOTLOADER	((Dcm_EcuResetType)0x07)

typedef uint8 Dcm_ControlDTCSettingType;
#define RTE_MODE_DcmControlDTCSetting_ENABLEDTCSETTING		((Dcm_ControlDTCSettingType)0x01)
#define RTE_MODE_DcmControlDTCSetting_DISABLEDTCSETTING 	((Dcm_ControlDTCSettingType)0x02)
/*====================================================================================================*
 *                                               ENUMS
 *====================================================================================================*/

/*====================================================================================================*
 *                                   STRUCTURES AND OTHER TYPEDEFS
 *====================================================================================================*/
/* @req [SWS_Dcm_01165] */
typedef uint8* Dcm_RequestDataArrayType;

/**< @brief For AuthenticationRole function. */
typedef uint8* Dcm_AuthenticationRoleType;

/**< @brief For ECU signal function. */
typedef uint8 EcuSignalDataType;
/*====================================================================================================*
 *                                    GLOBAL VARIABLE DECLARATIONS
 *====================================================================================================*/

/*====================================================================================================*
 *                                        FUNCTION PROTOTYPES
 *====================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* RTE_DCM_TYPE_H */
/** @} */
