/**
 * @file        Dcm_Types.h
 * @brief       AUTOSAR 4.2.2 - 4.2.2 driver header file.
 * @details     Dcm driver header file, containing the Autosar API specification and
 *              other variables and functions that are exported by the Dcm driver.
 * @version     1.2.0
 *
 * @addtogroup  Dcm
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

#ifndef DCM_TYPES_H
#define DCM_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif

/**
 * @req [SWS_Dcm_00683] The file Dcm_Types.h shall provide all Dcm types definition.
 *
 * @req [SWS_Dcm_00968] The Dcm shall support the following data types: boolean, uint8, uint16, uint32,
 * 		sint8, sint16, sint32, uint8[n].
 */

/*====================================================================================================*
 *                                           INCLUDE FILES
 *====================================================================================================*/
#include "Dcm_Cfg.h"
#include "Rte_Dcm_Type.h"
#include "Std_Types.h"
#include "ComStack_Types.h"
/*====================================================================================================*
 *                                  HEADER FILE VERSION INFORMATION
 *====================================================================================================*/
#define DCM_TYPES_VENDOR_ID                           		(0x00U)
#define DCM_TYPES_AR_RELEASE_MAJOR_VERSION            		(0x04U)
#define DCM_TYPES_AR_RELEASE_MINOR_VERSION            		(0x02U)
#define DCM_TYPES_AR_RELEASE_REVISION_VERSION         		(0x02U)
#define DCM_TYPES_SW_MAJOR_VERSION                    		(0x01U)
#define DCM_TYPES_SW_MINOR_VERSION                    		(0x02U)
#define DCM_TYPES_SW_PATCH_VERSION                    		(0x00U)
/*====================================================================================================*
 *                                         FILE VERSION CHECKS
 *====================================================================================================*/
/* Check if current file and Dcm_Cfg header file are of the same vendor */
#if(DCM_TYPES_VENDOR_ID != DCM_CFG_VENDOR_ID )
#error "Dcm_Types.h and Dcm_Cfg.h have different vendor id"
#endif
/* Check if current file and Dcm_Cfg header file are of the same Autosar version */
#if(\
		(DCM_TYPES_AR_RELEASE_MAJOR_VERSION != DCM_CFG_AR_RELEASE_MAJOR_VERSION) || \
		(DCM_TYPES_AR_RELEASE_MINOR_VERSION != DCM_CFG_AR_RELEASE_MINOR_VERSION) || \
		(DCM_TYPES_AR_RELEASE_REVISION_VERSION != DCM_CFG_AR_RELEASE_REVISION_VERSION) \
)
#error "AutoSar Version Number of Dcm_Types.h and Dcm_Cfg.h are different"
#endif
/* Check if current file and Dcm_Cfg header file are of the same software version */
#if(\
		(DCM_TYPES_SW_MAJOR_VERSION != DCM_CFG_SW_MAJOR_VERSION) || \
		(DCM_TYPES_SW_MINOR_VERSION != DCM_CFG_SW_MINOR_VERSION) || \
		(DCM_TYPES_SW_PATCH_VERSION != DCM_CFG_SW_PATCH_VERSION) \
)
#error "Software Version Number of Dcm_Types.h and Dcm_Cfg.h are different"
#endif

#ifndef DISABLE_INTERMOD_VERSION_CHECK
/* Check if current file and Rte_Dcm_Type header file are of the same Autosar version */
#if(\
		(DCM_TYPES_AR_RELEASE_MAJOR_VERSION != RTE_DCM_TYPE_AR_RELEASE_MAJOR_VERSION) || \
		(DCM_TYPES_AR_RELEASE_MINOR_VERSION != RTE_DCM_TYPE_AR_RELEASE_MINOR_VERSION) \
)
#error "AutoSar Version Number of Dcm_Types.h and Rte_Dcm_Type.h are different"
#endif
/* Check if current file and Std_Types header file are of the same Autosar version */
#if(\
		(DCM_TYPES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
		(DCM_TYPES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION) \
)
#error "AutoSar Version Number of Dcm_Types.h and Std_Types.h are different"
#endif
/* Check if current file and ComStack_Types header file are of the same Autosar version */
#if(\
		(DCM_TYPES_AR_RELEASE_MAJOR_VERSION != COMTYPE_AR_RELEASE_MAJOR_VERSION) || \
		(DCM_TYPES_AR_RELEASE_MINOR_VERSION != COMTYPE_AR_RELEASE_MINOR_VERSION) \
)
#error "AutoSar Version Number of Dcm_Types.h and ComStack_Types.h are different"
#endif
#endif
/*====================================================================================================*
 *                                             CONSTANTS
 *====================================================================================================*/

/*====================================================================================================*
 *                                         DEFINES AND MACROS
 *====================================================================================================*/
#if(0u != DCM_DSP_ROE_NUM)
/* @req [SWS_Dcm_00976] */
/**
 * @brief	Base item type to transport status information.
 */
typedef uint8 Dcm_StatusType;

/**
 * @brief	This value is representing a successful operation.
 */
#define DCM_E_OK							((Dcm_StatusType)0x00)

/**
 * @brief	ResponseOnOneEvent request is not accepted by DCM (e.g. old ResponseOnOneEvent is not
 * 			finished) (used at API: Dcm_ResponseOnOneEvent()).
 */
#define DCM_E_ROE_NOT_ACCEPTED				((Dcm_StatusType)0x06)

/**
 * @brief	Periodic transmission request is not accepted by DCM (e.g. old Periodic transmission is not
 * 			finished) (used at API: Dcm_ResponseOnOneDataByPeriodicId()).
 */
#define DCM_E_PERIODICID_NOT_ACCEPTED		((Dcm_StatusType)0x07)
#endif /* #if(0u != DCM_DSP_ROE_NUM) */

#if(STD_ON == DCM_UDS0x28_ENABLE)
/* @req [SWS_Dcm_00981] */
/**
 * @brief	Base mode type of communication.
 */
typedef uint8 Dcm_CommunicationModeType;

/**
 * @brief	Enable the Rx and Tx for normal communication.
 */
#define DCM_ENABLE_RX_TX_NORM				((Dcm_CommunicationModeType)0x00)

/**
 * @brief	Enable the Rx and disable the Tx for normal communication.
 */
#define DCM_ENABLE_RX_DISABLE_TX_NORM		((Dcm_CommunicationModeType)0x01)

/**
 * @brief	Disable the Rx and enable the Tx for normal communication.
 */
#define DCM_DISABLE_RX_ENABLE_TX_NORM		((Dcm_CommunicationModeType)0x02)

/**
 * @brief	Disable Rx and Tx for normal communication.
 */
#define DCM_DISABLE_RX_TX_NORM				((Dcm_CommunicationModeType)0x03)

/**
 * @brief	Enable the Rx and Tx for network management communication.
 */
#define DCM_ENABLE_RX_TX_NM					((Dcm_CommunicationModeType)0x04)

/**
 * @brief	Enable Rx and disable the Tx for network management communication.
 */
#define DCM_ENABLE_RX_DISABLE_TX_NM			((Dcm_CommunicationModeType)0x05)

/**
 * @brief	Disable the Rx and enable the Tx for network management communication.
 */
#define DCM_DISABLE_RX_ENABLE_TX_NM			((Dcm_CommunicationModeType)0x06)

/**
 * @brief	Disable Rx and Tx for network management communication.
 */
#define DCM_DISABLE_RX_TX_NM				((Dcm_CommunicationModeType)0x07)

/**
 * @brief	Enable Rx and Tx for normal and network management communication.
 */
#define DCM_ENABLE_RX_TX_NORM_NM			((Dcm_CommunicationModeType)0x08)

/**
 * @brief	Enable the Rx and disable the Tx for normal and network management communication.
 */
#define DCM_ENABLE_RX_DISABLE_TX_NORM_NM	((Dcm_CommunicationModeType)0x09)

/**
 * @brief	Disable the Rx and enable the Tx for normal and network management communication.
 */
#define DCM_DISABLE_RX_ENABLE_TX_NORM_NM	((Dcm_CommunicationModeType)0x0A)

/**
 * @brief	Disable Rx and Tx for normal and network management communication.
 */
#define DCM_DISABLE_RX_TX_NORM_NM			((Dcm_CommunicationModeType)0x0B)
#endif /* #if(STD_ON == DCM_UDS0x28_ENABLE) */

#if((STD_ON == DCM_UDS0x23_ENABLE) || (STD_ON == DCM_UDS0x2C_ENABLE) || (STD_ON == DCM_UDS0x36_ENABLE))
/* @req [SWS_Dcm_00985] */
/**
 * @brief	Return values of callout Dcm_ReadMemory.
 */
typedef uint8 Dcm_ReturnReadMemoryType;

/**
 * @brief	Reading has been done.
 */
#define DCM_READ_OK							((Dcm_ReturnReadMemoryType)0x00)

/**
 * @brief	Reading is pending, another call is request to finalize the reading.
 */
#define DCM_READ_PENDING					((Dcm_ReturnReadMemoryType)0x01)

/**
 * @brief	Reading has failed.
 */
#define DCM_READ_FAILED						((Dcm_ReturnReadMemoryType)0x02)

/**
 * @brief	Reading is pending, the Response pending transmission starts immediately.
 */
#define DCM_READ_FORCE_RCRRP				((Dcm_ReturnReadMemoryType)0x03)
#endif /* #if((STD_ON == DCM_UDS0x23_ENABLE) ||
		      (STD_ON == DCM_UDS0x2C_ENABLE) ||
		      (STD_ON == DCM_UDS0x36_ENABLE)) */

#if((STD_ON == DCM_UDS0x3D_ENABLE) || (STD_ON == DCM_UDS0x36_ENABLE))
/* @req [SWS_Dcm_00986] */
/**
 * @brief	Return values of callout Dcm_WriteMemory.
 */
typedef uint8 Dcm_ReturnWriteMemoryType;

/**
 * @brief	Writing has been done.
 */
#define DCM_WRITE_OK						((Dcm_ReturnWriteMemoryType)0x00)

/**
 * @brief	Writing is pending, another call is request to finalize the reading.
 */
#define DCM_WRITE_PENDING					((Dcm_ReturnWriteMemoryType)0x01)

/**
 * @brief	Writing has failed.
 */
#define DCM_WRITE_FAILED					((Dcm_ReturnWriteMemoryType)0x02)

/**
 * @brief	Writing is pending, the Response pending transmission starts immediately.
 */
#define DCM_WRITE_FORCE_RCRRP				((Dcm_ReturnWriteMemoryType)0x03)
#endif /* #if((STD_ON == DCM_UDS0x3D_ENABLE) || (STD_ON == DCM_UDS0x36_ENABLE)) */

/* @req [SWS_Dcm_00987] */
/**
 * @brief	Allows the DCM to know if a diagnostic response shall be sent in the case of a jump from
 * 			bootloader.
 */
typedef uint8 Dcm_EcuStartModeType;

/**
 * @brief	The ECU starts normally.
 */
#define DCM_COLD_START						((Dcm_EcuStartModeType)0x00)

/**
 * @brief	The ECU starts from a bootloader jump.
 */
#define DCM_WARM_START						((Dcm_EcuStartModeType)0x01)

/* @req [SWS_Dcm_91015] */
/**
 * @brief	This message context identifier can be used to determine the relation between request and
 * 			response confirmation.
 */
typedef uint8 Dcm_ExtendedOpStatusType;

/**
 * @brief	Indicates that a positive response has been sent successfully.
 */
#define DCM_POS_RESPONSE_SENT				((Dcm_ExtendedOpStatusType)0x04)

/**
 * @brief	Indicates that a positive response has not been sent successfully.
 */
#define DCM_POS_RESPONSE_FAILED				((Dcm_ExtendedOpStatusType)0x05)

/**
 * @brief	Indicates that a negative response has been sent successfully.
 */
#define DCM_NEG_RESPONSE_SENT				((Dcm_ExtendedOpStatusType)0x06)

/**
 * @brief	Indicates that a negative response has not been sent successfully.
 */
#define DCM_NEG_RESPONSE_FAILED				((Dcm_ExtendedOpStatusType)0x07)
/*====================================================================================================*
 *                                               ENUMS
 *====================================================================================================*/
#if(STD_ON == DCM_PROCESSING_CONDITIONS_ENABLED)
/**
 * @brief	This parameter specifies what kind of comparison that is made for the evaluation of the
 * 			mode condition.
 */
typedef enum
{
	/**< @brief No description. */
	DCM_EQUALS = 0u,
	/**< @brief No description. */
	DCM_EQUALS_NOT,
	/**< @brief No description. */
	DCM_GREATER_OR_EQUAL,
	/**< @brief No description. */
	DCM_GREATER_THAN,
	/**< @brief No description. */
	DCM_LESS_OR_EQUAL,
	/**< @brief No description. */
	DCM_LESS_THAN
}Dcm_ConditionType;

/**
 * @brief	This parameter specifies the logical operator to be used in the logical expression. If the
 * 			expression only consists of a single condition this parameter shall not be used.
 */
typedef enum
{
	/**< @brief No description. */
	DCM_AND = 0u,
	/**< @brief No description. */
	DCM_OR
}Dcm_LogicalOperatorType;
#endif /* #if(STD_ON == DCM_PROCESSING_CONDITIONS_ENABLED) */

#if(0u != DCM_DSP_ROE_NUM)
/**
 * @brief	This parameter is used only if the protocol is of type DCM_ROE_ON_xxx. It selects the
 * 			transmission type of the protocol.
 */
typedef enum
{
	/**< @brief Messages on the DcmTxPduId already used for normal diagnostic responses. The outgoing
	 * 			messages must be synchronized with 'normal outgoing messages', which have a higher
	 * 			priority. */
	DCM_TYPE1 = 0u,
	/**< @brief Messages on a separate DcmTxPduId. */
	DCM_TYPE2
}Dcm_DslProtocolTransType;
#endif /* #if(0u != DCM_DSP_ROE_NUM) */

/**
 * @brief	Selects the addressing type of the reception channel.
 */
typedef enum
{
	/**< @brief PHYSICAL = 1 to 1 communications using physical addressing. */
	DCM_PHYSICAL_TYPE = 0u,
	/**< @brief FUNCTIONAL = 1 to n communication. */
	DCM_FUNCTIONAL_TYPE,
	/**< @brief Simultaneously supporting both FUNCTIONAL and PHYSICAL addressing. */
	DCM_FUNCTIONAL_PHYSICAL_TYPE
}Dcm_DslProtocolRxAddrType;

/**
 * @brief	Defines the endianness of the data belonging to a DID in a diagnostic request or response
 * 			message.
 */
typedef enum
{
	/**< @brief Most significant byte shall be stored at the lowest address. */
	DCM_BIG_ENDIAN = 0u,
	/**< @brief Most significant byte shall be stored at the highest address. */
	DCM_LITTLE_ENDIAN,
	/**< @brief Opaque data endianness. */
	DCM_OPAQUE
}Dcm_DspDataEndiannessType;

/**
 * @brief	Provide the implementation data type of data belonging to a DID.
 */
typedef enum
{
	/**< @brief Type of the data is boolean. */
	DCM_BOOLEAN = 0u,
	/**< @brief Type of the data is sint16. */
	DCM_SINT16,
	/**< @brief Type of the data is sint16 array. */
	DCM_SINT16_N,
	/**< @brief Type of the data is sint32. */
	DCM_SINT32,
	/**< @brief Type of the data is sint32 array. */
	DCM_SINT32_N,
	/**< @brief Type of the data is sint8. */
	DCM_SINT8,
	/**< @brief Type of the data is sint8 array. */
	DCM_SINT8_N,
	/**< @brief Type of the data is uint16. */
	DCM_UINT16,
	/**< @brief Type of the data is uint16 array. */
	DCM_UINT16_N,
	/**< @brief Type of the data is uint32. */
	DCM_UINT32,
	/**< @brief Type of the data is uint32 array. */
	DCM_UINT32_N,
	/**< @brief Type of the data is uint8. */
	DCM_UINT8,
	/**< @brief Type of the data is uint8 array with dynamic length. */
	DCM_UINT8_DYN,
	/**< @brief Type of the data is uint8 array. */
	DCM_UINT8_N
}Dcm_DspDataEnumType;

/**
 * @brief	Defines which interface shall be used to access the data.
 */
typedef enum
{
	/**< @brief The DCM will access the Data using the NVRAM Apis with the BlockId defined in
	 * 			DcmDspDataBlockId */
	DCM_USE_BLOCK_ID = 0u,
	/**< @brief The DCM will access the Data using an R-Port requiring a asynchronous
	 * 			ClientServertInterface DataServices_{Data}. */
	DCM_USE_DATA_ASYNCH_CLIENT_SERVER,
	/**< @brief The Dcm will access the Data using an R-Port requiring a asynchronous
	 * 			ClientServertInterface DataServices_{Data}. */
	DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
	/**< @brief The DCM will access the Data using the functions that are defined in parameters of
	 * 			type EcucFunctionNameDef (but without DcmDspDataReadDataLengthFnc) in the DcmDspData
	 * 			container. */
	DCM_USE_DATA_ASYNCH_FNC,
	/**< @brief The DCM will access the Data using the functions that are defined in parameters of
	 * 			type EcucFunctionNameDef (but without DcmDspDataReadDataLengthFnc) in the DcmDspData
	 * 			container. */
	DCM_USE_DATA_ASYNCH_FNC_ERROR,
	/**< @brief The DCM will access the Data using an Port requiring a SenderReceiverInteface (with
	 * 			isService=false) DataServices_{Data}. */
	DCM_USE_DATA_SENDER_RECEIVER,
	/**< @brief The DCM will access the Data using an Port requiring a SenderReceiverInteface (with
	 * 			isService=false) DataServices_{Data}. */
	DCM_USE_DATA_SENDER_RECEIVER_AS_SERVICE,
	/**< @brief The DCM will access the Data using an R-Port requiring a synchronous
	 * 			ClientServertInterface DataServices_{Data}. */
	DCM_USE_DATA_SYNCH_CLIENT_SERVER,
	/**< @brief The DCM will access the Data using the functions that are defined in parameters of
	 * 			type EcucFunctionNameDef (but without DcmDspDataReadDataLengthFnc) in the DcmDspData
	 * 			container. */
	DCM_USE_DATA_SYNCH_FNC,
	/**< @brief The DCM will access the Data using a direct access to IoHwAb. */
	DCM_USE_ECU_SIGNAL
}Dcm_DspDataUsePortType;

#if(STD_ON == DCM_UDS0x2F_ENABLE)
/**
 * @brief	This indicates the presence of "controlEnableMask" in SWC service interfaces and defines
 * 			how the Dcm treats a service request.
 */
typedef enum
{
	/**< @brief The control enable mask record shall be forwarded within each interface and is handled
	 * 			externally */
	DCM_CONTROLMASK_EXTERNAL = 0u,
	/**< @brief The control enable mask record is handled internally and Dcm controls only the included
	 * 			signals. */
	DCM_CONTROLMASK_INTERNAL,
	/**< @brief No control enable mask handling. */
	DCM_CONTROLMASK_NO
}Dcm_DspDidControlMaskType;
#endif /* #if(STD_ON == DCM_UDS0x2F_ENABLE) */

#if(STD_ON == DCM_UDS0x11_ENABLE)
/**
 * @brief	Defines the answer to EcuReset service should come: Before or after the reset.
 */
typedef enum
{
	/**< @brief Answer to EcuReset service should come after the reset. */
	DCM_AFTER_RESET = 0u,
	/**< @brief Answer to EcuReset service should come before the reset. */
	DCM_BEFORE_RESET
}Dcm_ResponseToEcuResetType;
#endif /* #if(STD_ON == DCM_UDS0x11_ENABLE) */

#if(0u != DCM_DSP_PID_NUM)
/**
 * @brief	Indicates if a PID is used with service $01 and/or $02.
 */
typedef enum
{
	/**< @brief A PID is used with service $01 only. */
	DCM_SERVICE_01 = 0u,
	/**< @brief A PID is used with service $01 and $02. Allowed with a PID configuration containing
	 * 			data elements on byte basis. */
	DCM_SERVICE_01_02,
	/**< @brief A PID is used with service $02 only. Allowed with a PID configuration containing data
	 * 			elements on byte basis. */
	DCM_SERVICE_02
}Dcm_DspPidServiceType;
#endif /* #if(0u != DCM_DSP_PID_NUM) */

#if(0u != DCM_DSP_ROE_NUM)
/**
 * @brief	Initial Roe status of this RoeEvent.
 */
typedef enum
{
	/**< @brief No description. */
	DCM_ROE_CLEARED = 0u,
	/**< @brief No description. */
	DCM_ROE_STOPPED
}Dcm_DspRoeInitialEventStatusType;

/**
 * @brief	Value of the EventWindowTime.
 */
typedef enum
{
	/**< @brief No description. */
	DCM_ROE_EVENT_WINDOW_CURRENT_AND_FOLLOWING_CYCLE = 0u,
	/**< @brief No description. */
	DCM_ROE_EVENT_WINDOW_CURRENT_CYCLE,
	/**< @brief No description. */
	DCM_ROE_EVENT_WINDOW_INFINITE
}Dcm_DspRoeEventWindowTimeType;
#endif /* #if(0u != DCM_DSP_ROE_NUM) */

#if(STD_ON == DCM_UDS0x10_ENABLE)
/**
 * @brief	This parameter defines whether this diagnostic session allows to jump to Bootloader
 * 			(OEM Bootloader or System Supplier Bootloader) and determines, from which unit the final
 * 			response will be sent.
 */
typedef enum
{
	/**< @brief This diagnostic session doesn't allow to jump to Bootloader. */
	DCM_NO_BOOT = 0u,
	/**< @brief This diagnostic session allows to jump to OEM Bootloader and bootloader sends final
	 * 			response. */
	DCM_OEM_BOOT,
	/**< @brief This diagnostic session allows to jump to OEM Bootloader and application sends final
	 * 			response. */
	DCM_OEM_BOOT_RESPAPP,
	/**< @brief This diagnostic session allows to jump to System Supplier Bootloader and bootloader
	 * 			sends final response. */
	DCM_SYS_BOOT,
	/**< @brief This diagnostic session allows to jump to System Supplier Bootloader and application
	 * 			sends final response. */
	DCM_SYS_BOOT_RESPAPP
}Dcm_DspSessionForBootType;
#endif /* #if(STD_ON == DCM_UDS0x10_ENABLE) */
/*====================================================================================================*
 *                                   STRUCTURES AND OTHER TYPEDEFS
 *====================================================================================================*/
/**
 * @brief Typedef of the SessionRefData.
 */
#ifdef DCM_DSP_SESSION_REF_DATA_TYPE_UINT8
typedef uint8 Dcm_SessionDataType;
#else
#ifdef DCM_DSP_SESSION_REF_DATA_TYPE_UINT16
typedef uint16 Dcm_SessionDataType;
#else
typedef uint32 Dcm_SessionDataType;
#endif /* #ifdef DCM_DSP_SESSION_REF_DATA_TYPE_UINT16 */
#endif /* #ifdef DCM_DSP_SESSION_REF_DATA_TYPE_UINT8 */

/**
 * @brief Typedef of the SecurityRefData.
 */
#ifdef DCM_DSP_SECURITY_REF_DATA_TYPE_UINT8
typedef uint8 Dcm_SecurityDataType;
#else
#ifdef DCM_DSP_SECURITY_REF_DATA_TYPE_UINT16
typedef uint16 Dcm_SecurityDataType;
#else
typedef uint32 Dcm_SecurityDataType;
#endif /* #ifdef DCM_DSP_SECURITY_REF_DATA_TYPE_UINT16 */
#endif /* #ifdef DCM_DSP_SECURITY_REF_DATA_TYPE_UINT8 */

#if((STD_ON == DCM_DSD_REQUEST_MANUFACTURER_NOTIFICATION_ENABLED) || (STD_ON == DCM_DSD_REQUEST_SUPPLIER_NOTIFICATION_ENABLED))
/**
 * @brief	The following interface indicates to the Application that a service is about to be executed
 * 			and allows the Application to reject the execution of the service request.
 */
typedef Std_ReturnType(* Dcm_ServiceRequestNotificationType)
(
	/**< @brief Value of service identifier. */
	uint8 SID,
	/**< @brief This parameter contains the complete request data (diagnostic buffer), except the
	 * 			service ID. */
	Dcm_RequestDataArrayType RequestData,
	/**< @brief This parameter defines how many bytes in the RequestData parameter are valid. */
	uint16 DataSize,
	/**< @brief Addressing type of the request(0 = physical request, 1 = functional request). */
	uint8 ReqType,
	/**< @brief Unique connection identifier. */
	uint16 ConnectionId,
	/**< @brief No description. */
	Dcm_NegativeResponseCodeType ErrorCode,
	/**< @brief No description. */
	Dcm_ProtocolType ProtocolType,
	/**< @brief No description. */
	uint16 TesterSourceAddress
);
#endif /* #if((STD_ON == DCM_DSD_REQUEST_MANUFACTURER_NOTIFICATION_ENABLED) || (STD_ON == DCM_DSD_REQUEST_SUPPLIER_NOTIFICATION_ENABLED)) */

#if(STD_ON == DCM_DSL_CALLBACK_DCM_REQUEST_SERVICE_ENABLED)
/**
 * @brief	The following interface provides information on the status of the protocol communication
 * 			and allows the Application to disallow a protocol.
 */
typedef Std_ReturnType(* Dcm_CallbackDCMRequestServiceType)
(
	/**< @brief No description. */
	Dcm_ProtocolType ProtocolType,
	/**< @brief No description. */
	uint16 TesterSourceAddress,
	/**< @brief No description. */
	uint16 ConnectionId
);
#endif /* #if(STD_ON == DCM_DSL_CALLBACK_DCM_REQUEST_SERVICE_ENABLED) */

#if(STD_ON == DCM_UDS0x14_ENABLE)
/**
 * @brief	The following interface provides information on the status of the protocol communication
 * 			and allows the Application to disallow a protocol.
 */
typedef Std_ReturnType(* Dcm_DspClearDTCCheckFncType)
(
	/**< @brief No description. */
	uint32 GoDTC,
	/**< @brief No description. */
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
);
#endif /* #if(STD_ON == DCM_UDS0x14_ENABLE) */

#if(STD_ON == DCM_DSP_DATA_CONDITION_CHECK_READ_FNC_ENABLED)
/**
 * @brief	This function requests to the application if the conditions to read the Data are correct.
 */
typedef Std_ReturnType(* Dcm_DspDataConditionCheckReadFncType)
(
	/**< @brief No description. */
	Dcm_OpStatusType OpStatus,
	/**< @brief No description. */
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
);
#endif /* #if(STD_ON == DCM_DSP_DATA_CONDITION_CHECK_READ_FNC_ENABLED) */

#if(STD_ON == DCM_DSP_DATA_ECU_SIGNAL_FNC_ENABLED)
/**
 * @brief	This function provides control access to a certain ECU Signal to the DCM module
 * 			(<EcuSignalname> is the symbolic name of an ECU Signal).
 */
typedef Std_ReturnType(* Dcm_DspDataEcuSignalType)
(
	/**< @brief No description. */
	uint8 Action,
	/**< @brief No description. */
	EcuSignalDataType Signal
);
#endif /* #if(STD_ON == DCM_DSP_DATA_ECU_SIGNAL_FNC_ENABLED) */

#if(STD_ON == DCM_DSP_DATA_FREEZE_CURRENT_STATE_FNC_ENABLED)
/**
 * @brief	This function requests to the application to freeze the current state of an IOControl.
 */
typedef Std_ReturnType(* Dcm_DspDataFreezeCurrentStateFncType)
(
	/**< @brief No description. */
	Dcm_OpStatusType OpStatus,
	/**< @brief No description. */
	uint32 ControlMask,
	/**< @brief No description. */
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
);
#endif /* #if(STD_ON == DCM_DSP_DATA_FREEZE_CURRENT_STATE_FNC_ENABLED) */

#if(STD_ON == DCM_DSP_DATA_GET_SCALING_INFO_FNC_ENABLED)
/**
 * @brief	This function requests to the application for the scaling information of a Data.
 */
typedef Std_ReturnType(* Dcm_DspDataGetScalingInfoFncType)
(
	/**< @brief No description. */
	Dcm_OpStatusType OpStatus,
	/**< @brief No description. */
	P2VAR(uint8, AUTOMATIC, DCM_VAR)ScalingInfo,
	/**< @brief No description. */
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
);
#endif /* #if(STD_ON == DCM_DSP_DATA_GET_SCALING_INFO_FNC_ENABLED) */

#if(STD_ON == DCM_DSP_DATA_READ_DATA_LENGTH_FNC_ENABLED)
/**
 * @brief	This function requests the application to return the data length in byte of a Data.
 */
typedef Std_ReturnType(* Dcm_DspDataReadDataLengthFncType)
(
	/**< @brief No description. */
	Dcm_OpStatusType OpStatus,
	/**< @brief No description. */
	P2VAR(uint16, AUTOMATIC, DCM_VAR)DataLength
);
#endif /* #if(STD_ON == DCM_DSP_DATA_READ_DATA_LENGTH_FNC_ENABLED) */

#if(STD_ON == DCM_DSP_DATA_READ_ECU_SIGNAL_FNC_ENABLED)
/**
 * @brief	This function provides read access to a certain ECU Signal to the DCM module
 * 			(<EcuSignalname> is the symbolic name of an ECU Signal).
 */
typedef Std_ReturnType(* Dcm_DspDataReadEcuSignalType)
(
	/**< @brief No description. */
	P2VAR(EcuSignalDataType, AUTOMATIC, DCM_VAR)Signal
);
#endif /* #if(STD_ON == DCM_DSP_DATA_READ_ECU_SIGNAL_FNC_ENABLED) */

#if(STD_ON == DCM_DSP_DATA_READ_FNC_ENABLED)
/**
 * @brief	This function requests to the application a data value of a DID/PID.
 */
typedef Std_ReturnType(* Dcm_DspDataReadFncType)
(
	/**< @brief No description. */
	Dcm_OpStatusType OpStatus,
	/**< @brief No description. */
	P2VAR(uint8, AUTOMATIC, DCM_VAR)Data,
	/**< @brief No description. */
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
);
#endif /* #if(STD_ON == DCM_DSP_DATA_READ_FNC_ENABLED) */

#if(STD_ON == DCM_DSP_DATA_RESET_TO_DEFAULT_FNC_ENABLED)
/**
 * @brief	This function requests to the application to reset an IOControl to default value.
 */
typedef Std_ReturnType(* Dcm_DspDataResetToDefaultFncType)
(
	/**< @brief No description. */
	Dcm_OpStatusType OpStatus,
	/**< @brief No description. */
	uint32 ControlMask,
	/**< @brief No description. */
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
);
#endif /* #if(STD_ON == DCM_DSP_DATA_RESET_TO_DEFAULT_FNC_ENABLED) */

#if(STD_ON == DCM_DSP_DATA_RETURN_CONTROL_TO_ECU_FNC_ENABLED)
/**
 * @brief	This function requests to the application to return control to ECU of an IOControl.
 */
typedef Std_ReturnType(* Dcm_DspDataReturnControlToEcuFncType)
(
	/**< @brief No description. */
	uint32 ControlMask,
	/**< @brief No description. */
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
);
#endif /* #if(STD_ON == DCM_DSP_DATA_RETURN_CONTROL_TO_ECU_FNC_ENABLED) */

#if(STD_ON == DCM_DSP_DATA_SHORT_TERM_ADJUSTMENT_FNC_ENABLED)
/**
 * @brief	This function requests to the application to return control to ECU of an IOControl.
 */
typedef Std_ReturnType(* Dcm_DspDataShortTermAdjustmentFncType)
(
	/**< @brief No description. */
	P2CONST(uint8, AUTOMATIC, DCM_CONST)ControlStateInfo,
	/**< @brief No description. */
	uint16 DataLength,
	/**< @brief No description. */
	Dcm_OpStatusType OpStatus,
	/**< @brief No description. */
	uint32 ControlMask,
	/**< @brief No description. */
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
);
#endif /* #if(STD_ON == DCM_DSP_DATA_SHORT_TERM_ADJUSTMENT_FNC_ENABLED) */

#if(STD_ON == DCM_DSP_DATA_WRITE_FNC_ENABLED)
/**
 * @brief	This function requests to the application a data value of a DID/PID.
 */
typedef Std_ReturnType(* Dcm_DspDataWriteFncType)
(
	/**< @brief No description. */
	P2CONST(uint8, AUTOMATIC, DCM_CONST)Data,
	/**< @brief No description. */
	uint16 DataLength,
	/**< @brief No description. */
	Dcm_OpStatusType OpStatus,
	/**< @brief No description. */
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
);
#endif /* #if(STD_ON == DCM_DSP_DATA_WRITE_FNC_ENABLED) */

#if(0u != DCM_DSP_DID_RANGE_NUM)
#if(STD_ON == DCM_DSP_DID_RANGE_IS_DID_AVAILABLE_FNC_ENABLE)
/**
 * @brief	This function requests if a specific DID is available within the range or not.
 */
typedef Std_ReturnType(* Dcm_DspDidRangeIsDidAvailableFncType)
(
	/**< @brief No description. */
	uint16 DID,
	/**< @brief No description. */
	Dcm_OpStatusType OpStatus,
	/**< @brief No description. */
	P2VAR(Dcm_DidSupportedType, AUTOMATIC, DCM_VAR)Supported
);
#endif /* #if(STD_ON == DCM_DSP_DID_RANGE_IS_DID_AVAILABLE_FNC_ENABLE) */

#if(STD_ON == DCM_DSP_DID_RANGE_READ_DATA_LENGTH_FNC_ENABLE)
/**
 * @brief	This function requests the application to return the data length of a DID Range.
 */
typedef Std_ReturnType(* Dcm_DspDidRangeReadDataLengthFncType)
(
	/**< @brief No description. */
	uint16 DID,
	/**< @brief No description. */
	Dcm_OpStatusType OpStatus,
	/**< @brief No description. */
	P2VAR(uint16, AUTOMATIC, DCM_VAR)DataLength
);
#endif /* #if(STD_ON == DCM_DSP_DID_RANGE_READ_DATA_LENGTH_FNC_ENABLE) */

#if(STD_ON == DCM_DSP_DID_RANGE_READ_DID_FNC_ENABLE)
/**
 * @brief	This function requests to the application a data value of a DID.
 */
typedef Std_ReturnType(* Dcm_DspDidRangeReadDidFncType)
(
	/**< @brief No description. */
	uint16 DID,
	/**< @brief No description. */
	P2VAR(uint8, AUTOMATIC, DCM_VAR)Data,
	/**< @brief No description. */
	Dcm_OpStatusType OpStatus,
	/**< @brief No description. */
	P2VAR(uint16, AUTOMATIC, DCM_VAR)DataLength,
	/**< @brief No description. */
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
);
#endif /* #if(STD_ON == DCM_DSP_DID_RANGE_READ_DID_FNC_ENABLE) */

#if(STD_ON == DCM_DSP_DID_RANGE_WRITE_DID_FNC_ENABLE)
/**
 * @brief	This function requests the application to write a data value of a DID.
 */
typedef Std_ReturnType(* Dcm_DspDidRangeWriteDidFncType)
(
	/**< @brief No description. */
	uint16 DID,
	/**< @brief No description. */
	P2CONST(uint8, AUTOMATIC, DCM_CONST)Data,
	/**< @brief No description. */
	Dcm_OpStatusType OpStatus,
	/**< @brief No description. */
	uint16 DataLength,
	/**< @brief No description. */
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
);
#endif /* #if(STD_ON == DCM_DSP_DID_RANGE_WRITE_DID_FNC_ENABLE) */
#endif /* #if(0u != DCM_DSP_DID_RANGE_NUM) */

#if(0u != DCM_DSP_PID_NUM)
/**
 * @brief	This function requests the application to write a data value of a DID.
 */
typedef Std_ReturnType(* Dcm_DspPidDataReadFncType)
(
	/**< @brief No description. */
	P2VAR(uint8, AUTOMATIC, DCM_VAR)Data
);
#endif /* #if(0u != DCM_DSP_PID_NUM) */

#if(STD_ON == DCM_DSP_ROUTINE_CONFIRMATION_FNC_ENABLED)
/**
 * @brief	This function indicates the transmission of a response to a RoutineContrl request.
 */
typedef Std_ReturnType(* Dcm_DspRoutineConfirmationFncType)
(
	/**< @brief No description. */
	Dcm_ConfirmationStatusType ConfirmationStatus
);
#endif /* #if(STD_ON == DCM_DSP_ROUTINE_CONFIRMATION_FNC_ENABLED) */

#if(STD_ON == DCM_DSP_ROUTINE_REQUEST_RESULTS_ENABLED)
/**
 * @brief	This function requests to the application the result of a routine execution.
 */
typedef Std_ReturnType(* Dcm_DspRequestRoutineResultsFncType)
(
	/**< @brief No description. */
	Dcm_OpStatusType OpStatus,
	/**< @brief No description. */
	P2VAR(uint8, AUTOMATIC, DCM_VAR)DataOut,
	/**< @brief No description. */
	P2VAR(uint8, AUTOMATIC, DCM_VAR)DataOutVar,
	/**< @brief No description. */
	P2VAR(uint16, AUTOMATIC, DCM_VAR)CurrentLengthDataOutVar,
	/**< @brief No description. */
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
);
#endif /* #if(STD_ON == DCM_DSP_ROUTINE_REQUEST_RESULTS_ENABLED) */

#if(STD_ON == DCM_DSP_ROUTINE_START_ENABLED)
/**
 * @brief	This function requests to the application to start the execution of a routine.
 */
typedef Std_ReturnType(* Dcm_DspStartRoutineFncType)
(
	/**< @brief No description. */
	P2VAR(uint8, AUTOMATIC, DCM_VAR)DataIn,
	/**< @brief No description. */
	P2CONST(uint8, AUTOMATIC, DCM_CONST)DataInVar,
	/**< @brief No description. */
	Dcm_OpStatusType OpStatus,
	/**< @brief No description. */
	P2VAR(uint8, AUTOMATIC, DCM_VAR)DataOut,
	/**< @brief No description. */
	P2VAR(uint8, AUTOMATIC, DCM_VAR)DataOutVar,
	/**< @brief No description. */
	uint16 CurrentLengthDataInVar,
	/**< @brief No description. */
	P2VAR(uint16, AUTOMATIC, DCM_VAR)CurrentLengthDataOutVar,
	/**< @brief No description. */
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
);
#endif /* #if(STD_ON == DCM_DSP_ROUTINE_START_ENABLED) */

#if(STD_ON == DCM_DSP_ROUTINE_STOP_ENABLED)
/**
 * @brief	This function requests to the application to stop the execution of a routine.
 */
typedef Std_ReturnType(* Dcm_DspStopRoutineFncType)
(
	/**< @brief No description. */
	P2VAR(uint8, AUTOMATIC, DCM_VAR)DataIn,
	/**< @brief No description. */
	P2CONST(uint8, AUTOMATIC, DCM_CONST)DataInVar,
	/**< @brief No description. */
	P2VAR(uint8, AUTOMATIC, DCM_VAR)DataOut,
	/**< @brief No description. */
	P2VAR(uint8, AUTOMATIC, DCM_VAR)DataOutVar,
	/**< @brief No description. */
	uint16 CurrentLengthDataInVar,
	/**< @brief No description. */
	P2VAR(uint16, AUTOMATIC, DCM_VAR)CurrentLengthDataOutVar,
	/**< @brief No description. */
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
);
#endif /* #if(STD_ON == DCM_DSP_ROUTINE_STOP_ENABLED) */

#if(STD_ON == DCM_UDS0x27_ENABLE)
/**
 * @brief	Request to application for asynchronous comparing key.
 */
typedef Std_ReturnType(* Dcm_DspSecurityCompareKeyFncType)
(
	/**< @brief No description. */
	P2CONST(uint8, AUTOMATIC, DCM_CONST)Key,
	/**< @brief No description. */
	Dcm_OpStatusType OpStatus,
	/**< @brief No description. */
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
);

/**
 * @brief	Request to application for asynchronous provision of seed value.
 */
typedef Std_ReturnType(* Dcm_DspSecurityGetSeedFncType)
(
	/**< @brief No description. */
	P2CONST(uint8, AUTOMATIC, DCM_CONST)SecurityAccessDataRecord,
	/**< @brief No description. */
	Dcm_OpStatusType OpStatus,
	/**< @brief No description. */
	P2VAR(uint8, AUTOMATIC, DCM_VAR)Seed,
	/**< @brief No description. */
	P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR)ErrorCode
);

#if(STD_ON == DCM_DSP_SECURITY_ATTEMPT_COUNTER_ENABLED)
/**
 * @brief	Read the attempt counter for a specific security level from the application.
 */
typedef Std_ReturnType(* Dcm_DspSecurityGetAttemptCounterFncType)
(
	/**< @brief No description. */
	Dcm_OpStatusType OpStatus,
	/**< @brief No description. */
	P2VAR(uint8, AUTOMATIC, DCM_VAR)AttemptCounter
);

/**
 * @brief	Set the attempt counter for a specific security level in the application.
 */
typedef Std_ReturnType(* Dcm_DspSecuritySetAttemptCounterFncType)
(
	/**< @brief No description. */
	Dcm_OpStatusType OpStatus,
	/**< @brief No description. */
	uint8 AttemptCounter
);
#endif /* #if(STD_ON == DCM_DSP_SECURITY_ATTEMPT_COUNTER_ENABLED) */
#endif /* #if(STD_ON == DCM_UDS0x27_ENABLE) */

#if(0u != DCM_DSP_VEHINFO_NUM)
/**
 * @brief	Callout function name for reading InfoType data item.
 */
typedef Std_ReturnType(* Dcm_DspVehInfoDataReadFncType)
(
	/**< @brief No description. */
	Dcm_OpStatusType OpStatus,
	/**< @brief No description. */
	P2VAR(uint8, AUTOMATIC, DCM_VAR)Data,
	/**< @brief No description. */
	P2VAR(uint8, AUTOMATIC, DCM_VAR)DataSize
);
#endif /* #if(0u != DCM_DSP_VEHINFO_NUM) */

/* @req [SWS_Dcm_00989] */
/**
 * @brief	Base type for diagnostic message item.
 */
typedef uint8 Dcm_MsgItemType;

/* @req [SWS_Dcm_00990] */
/**
 * @brief	Base type for diagnostic message (request, positive or negative response).
 */
typedef Dcm_MsgItemType* Dcm_MsgType;

/* @req [SWS_Dcm_00991] */
/**
 * @brief	Length of diagnostic message (request, positive or negative response). The maximum length
 * 			is dependent of the underlying transport protocol/media.
 */
typedef uint32 Dcm_MsgLenType;

/* @req [SWS_Dcm_00992] */
/**
 * @brief	Additional information on message request.
 * 			Bit0 = 0: Physical request, Bit0 = 1: Functional request.
 * 			Bit1 = 0: No (do not suppress), Bit1 = 1: Yes (no positive response will be sent).
 */
typedef uint8 Dcm_MsgAddInfoType;

/* @req [SWS_Dcm_00993] */
/**
 * @brief	This message context identifier can be used to determine the relation between request and
 * 			response confirmation.
 */
typedef uint8 Dcm_IdContextType;

/* @req [SWS_Dcm_00988] */
/**
 * @brief	Used in Dcm_SetProgConditions() to allow the integrator to store relevant information prior
 * 			to jumping to bootloader / jump due to ECUReset request.
 */
typedef struct
{
	/**< @brief Set to true in order to request reprogramming of the ECU. */
	boolean ReprogramingRequest;
	/**< @brief Indicate whether the application has been updated or not. */
	boolean ApplUpdated;
	/**< @brief Set to true in case the flashloader or application shall send a response. */
	boolean ResponseRequired;
	/**< @brief Service identifier of the received request. */
	uint8 Sid;
	/**< @brief Identifier of the received sub-function. */
	uint8 SubFncId;
	/**< @brief Unique id of the connection on which the request has been received. */
	uint16 ConnectionId;
	/**< @brief Source address of the received request if metadata is enabled, otherwise the value as
	 * 			configured in DcmDslProtocolRxTesterSourceAddr. */
	uint16 TesterAddress;
}Dcm_ProgConditionsType;

/* @req [SWS_Dcm_00994] */
/**
 * @brief	This data structure contains all information which is necessary to process a diagnostic
 * 			message from request to response and response confirmation.
 */
typedef struct
{
	/**< @brief This message context identifier can be used to determine the relation between request
	 * 			and response confirmation. */
	Dcm_IdContextType IdContext;
	/**< @brief Additional information about service request and response (see: Dcm_MsgAddInfo). */
	Dcm_MsgAddInfoType MsgAddInfo;
	/**< @brief Pdu identifier on which the request was received. */
	PduIdType DcmRxPduId;
	/**< @brief Request data length (excluding service identifier). */
	Dcm_MsgLenType ReqDataLen;
	/**< @brief Positive response data length (excluding service identifier). */
	Dcm_MsgLenType ResDataLen;
	/**< @brief The maximal length of a response is restricted by the size of the buffer. */
	Dcm_MsgLenType ResMaxDataLen;
	/**< @brief Request data, starting directly after service identifier (which is not part of this
	 * 			data). */
	Dcm_MsgType ReqData;
	/**< @brief Positive response data, starting directly after service identifier (which is not part
	 * 			of this data). */
	Dcm_MsgType ResData;
}Dcm_MsgContextType;

/**
 * @brief	Callback function of the ECU Supplier specific component for the particular service.
 */
typedef Std_ReturnType(* Dcm_DsdServiceFncType)
(
	/**< @brief No description. */
	Dcm_OpStatusType OpStatus,
	/**< @brief No description. */
	Dcm_MsgContextType* pMsgContext,
	/**< @brief No description. */
	Dcm_NegativeResponseCodeType* ErrorCode
);

#if((STD_ON == DCM_DSD_SERVICE_CONDITION_CHECK_FNC_USED) ||\
	(STD_ON == DCM_DSD_SUB_SERVICE_CONDITION_CHECK_FNC_USED))
/**
 * @brief	Callback function of the service or sub-service condition checked.
 */
typedef Std_ReturnType(* Dcm_DsdServiceConditionCheckFncType)
(
	/**< @brief No description. */
	Dcm_NegativeResponseCodeType* ErrorCode
);
#endif /* #if((STD_ON == DCM_DSD_SERVICE_CONDITION_CHECK_FNC_USED) ||\
			  (STD_ON == DCM_DSD_SUB_SERVICE_CONDITION_CHECK_FNC_USED)) */

/**
 * @brief	This container contains the configuration (DSD parameters) for a subservice of a service.
 * 			Only those services may have subservices, which have the DcmDsdSidTabSubfuncAvail configured
 * 			as TRUE.
 */
typedef struct
{
	/**< @brief Allows to activate or deactivate the usage of a Subservice. This parameter can be used
	 * 			for multi-purpose ECUs. */
	boolean DcmDsdSubServiceUsed;
	/**< @brief Identifier of the subservice. */
	uint8 DcmDsdSubServiceId;
	/**< @brief Reference to a Session Level in which the subservice is allowed to be executed. */
	Dcm_SessionDataType DcmDsdSubServiceSessionLevelRef;
	/**< @brief Reference to a Security Level in which the subservice is allowed to be executed. */
	Dcm_SecurityDataType DcmDsdSubServiceSecurityLevelRef;
	/**< @brief Sub-Service addressing method. */
	Dcm_DslProtocolRxAddrType DcmDsdSubServiceRxAddrType;
#if(STD_ON == DCM_DSD_SUB_SERVICE_P4_TIMER_ENABLE)
	/**< @brief Specifies the maximum time (in seconds) allowed for the complete execution of this
	 * 			specific sub-diagnostic service, including all intermediate negative responses with NRC
	 * 			0x78. */
	uint32 DcmDsdSubServiceP4ServerMax;
#endif /* #if(STD_ON == DCM_DSD_SERVICE_P4_TIMER_ENABLE) */
#if(0u)
	/* TODO:2025.12.10, LY: Not supported. */
	/**< @brief Callback function of the ECU Supplier specific component for the particular service. */
	Dcm_DsdServiceFncType DcmDsdSubServiceFnc;
#endif/* #if(0u) */
#if(STD_ON == DCM_DSD_SUB_SERVICE_CONDITION_CHECK_FNC_USED)
	/**< @brief Callback function of the sub-service condition checked. */
	Dcm_DsdServiceConditionCheckFncType DcmDsdSubServiceConditionCheckFnc;
#endif /* DCM_DSD_SUB_SERVICE_CONDITION_CHECK_FNC_USED */
#if(STD_ON == DCM_PROCESSING_CONDITIONS_ENABLED)
	/**< @brief Reference to a DcmDspModeRule which controls the execution of the subservice. */
	P2CONST(Dcm_ModeRuleType, AUTOMATIC, DCM_CONST)DcmDsdSubServiceModeRuleRef;
#endif /* #if(STD_ON == DCM_PROCESSING_CONDITIONS_ENABLED) */
}Dcm_DsdSubServiceType;

/**
 * @brief	This container contains the configuration (DSD parameters) for a Service.
 */
typedef struct
{
	/**< @brief Allows to activate or deactivate the usage of a Service. This parameter can be used for
	 * 			multi-purpose ECUs. */
	boolean DcmDsdServiceUsed;
	/**< @brief Information about whether the service has subfunctions or not. */
	boolean DcmDsdSidTabSubfuncAvail;
	/**< @brief Identifier of the service. */
	uint8 DcmDsdSidTabServiceId;
	/**< @brief Number of sub-service. */
	uint8 DcmDsdSubServiceNum;
	/**< @brief Reference to a Session Level in which the service is allowed to be executed. */
	Dcm_SessionDataType DcmDsdSidTabSessionLevelRef;
	/**< @brief Reference to a Security Level in which the service is allowed to be executed. */
	Dcm_SecurityDataType DcmDsdSidTabSecurityLevelRef;
	/**< @brief Service addressing method. */
	Dcm_DslProtocolRxAddrType DcmDsdServiceRxAddrType;
#if(STD_ON == DCM_DSD_SERVICE_P4_TIMER_ENABLE)
	/**< @brief Specifies the maximum time (in seconds) allowed for the complete execution of this
	 * 			specific diagnostic service, including all intermediate negative responses with NRC
	 * 			0x78. */
	uint32 DcmDsdServiceP4ServerMax;
#endif /* #if(STD_ON == DCM_DSD_SERVICE_P4_TIMER_ENABLE) */
	/**< @brief Callback function of the ECU Supplier specific component for the particular service. */
	Dcm_DsdServiceFncType DcmDsdSidTabFnc;
#if(STD_ON == DCM_DSD_SERVICE_CONDITION_CHECK_FNC_USED)
	/**< @brief Callback function of the service condition checked. */
	Dcm_DsdServiceConditionCheckFncType DcmDsdServiceConditionCheckFnc;
#endif /* DCM_DSD_SERVICE_CONDITION_CHECK_FNC_USED */
#if(STD_ON == DCM_PROCESSING_CONDITIONS_ENABLED)
	/**< @brief Reference to a DcmDspModeRule which controls the execution of the service. */
	P2CONST(Dcm_ModeRuleType, AUTOMATIC, DCM_CONST)DcmDsdSidTabModeRuleRef;
#endif /* #if(STD_ON == DCM_PROCESSING_CONDITIONS_ENABLED) */
	/**< @brief This container contains the configuration (DSD parameters) for a subservice of a
	 * 			service. Only those services may have subservices, which have the
	 * 			DcmDsdSidTabSubfuncAvail configured as TRUE. */
	P2CONST(Dcm_DsdSubServiceType, AUTOMATIC, DCM_CONST)DcmDsdSubService;
}Dcm_DsdServiceType;

/**
 * @brief	This container contains the configuration (DSD parameters) for a Service Identifier Table.
 */
typedef struct
{
	/**< @brief Due to using possibly more service tables, the unique DcmDsdSidTabId can be used to
	 * 			identify them. */
	uint8 DcmDsdSidTabId;
	/**< @brief Service number of service table. */
	uint8 DcmServiceNum;
	/**< @brief This container contains the configuration (DSD parameters) for a Service. */
	P2CONST(Dcm_DsdServiceType, AUTOMATIC, DCM_CONST)DcmDsdService;
}Dcm_DsdServiceTableType;

/**
 * @brief	These parameters configure the Diagnostic Service Dispatcher submodule.
 */
typedef struct
{
#if(STD_ON == DCM_UDS0x28_ENABLE)
	Dcm_SessionDataType DcmDsdUDS0x28SesRef;
#endif /* #if(STD_ON == DCM_UDS0x28_ENABLE) */
#if(STD_ON == DCM_UDS0x85_ENABLE)
	Dcm_SessionDataType DcmDsdUDS0x85SesRef;
#endif /* #if(STD_ON == DCM_UDS0x28_ENABLE) */
#if(STD_ON == DCM_DSD_REQUEST_MANUFACTURER_NOTIFICATION_ENABLED)
	/**< @brief The name of this container is used to define the name of the R-Port through which the
	 * 			DCM accesses the interface ServiceRequestNotification. The R-Port is named
	 * 			ServiceRequestManufacturerNotification_{Name} where {Name} is the name of the container
	 * 			DcmDsdServiceRequestManufacturerNotification. */
	P2CONST(Dcm_ServiceRequestNotificationType, AUTOMATIC, DCM_CONST)DcmDsdServiceRequestManufacturerNotification;
#endif /* #if(STD_ON == DCM_DSD_REQUEST_MANUFACTURER_NOTIFICATION_ENABLED) */
#if(STD_ON == DCM_DSD_REQUEST_SUPPLIER_NOTIFICATION_ENABLED)
	/**< @brief The name of this container is used to define the name of the R-Port through which the
	 * 			DCM accesses the interface ServiceRequestNotification. The R-Port is named
	 * 			ServiceRequestSupplierNotification_<SWC> where <SWC> is the name of the container
	 * 			DcmDsdServiceRequestSupplierNotification. */
	P2CONST(Dcm_ServiceRequestNotificationType, AUTOMATIC, DCM_CONST)DcmDsdServiceRequestSupplierNotification;
	/**< @brief This container contains the configuration (DSD parameters) for a Service Identifier
	 * 			Table. */
#endif /* #if(STD_ON == DCM_DSD_REQUEST_SUPPLIER_NOTIFICATION_ENABLED) */
	P2CONST(Dcm_DsdServiceTableType, AUTOMATIC, DCM_CONST)DcmDsdServiceTable;
}Dcm_DsdType;

/**
 * @brief	This container contains the configuration of a diagnostic buffer.
 */
typedef struct
{
	/**< @brief Size of the diagnostic buffer in bytes. */
	uint32 DcmDslBufferSize;
	/**< @brief Pointer to the buffer. */
	P2VAR(uint8, AUTOMATIC, DCM_VAR)DcmDslBufferRef;
}Dcm_DslBufferType;

/**
 * @brief	This container contains the configuration parameters of a reception channel in a diagnostic
 * 			connection.
 */
typedef struct
{
	/**< @brief Index of the father MainConnection container. */
	uint8 DcmDslRxParentConIdx;
	/**< @brief Index of the father ProtocolRow container. */
	uint8 DcmDslRxParentProIdx;
	/**< @brief Reference to a Pdu in EcuC that is used for this reception channel. */
	PduIdType DcmDslProtocolRxPduRef;
	/**< @brief Identifier of the PDU that is used for this reception channel. */
	PduIdType DcmDslProtocolRxPduId;
	/**< @brief Selects the addressing type of the reception channel. */
	Dcm_DslProtocolRxAddrType DcmDslProtocolRxAddrType;
}Dcm_DslProtocolRxType;

#if(0u != DCM_DSL_PROTOCOL_TX_NUM)
/**
 * @brief	This container contains the configuration parameters of a transmission channel in a
 * 			diagnostic connection.
 */
typedef struct
{
	/**< @brief Index of the father MainConnection container. */
	uint8 DcmDslTxParentConIdx;
	/**< @brief Index of the father ProtocolRow container. */
	uint8 DcmDslTxParentProIdx;
	/**< @brief Reference to a Pdu in EcuC that is used for this transmission channel. */
	PduIdType DcmDslProtocolTxPduRef;
	/**< @brief Identifier of the PDU that is used by the lower level module for transmission
	 * 			confirmation of responses on this channel. */
	PduIdType DcmDslTxConfirmationPduId;
}Dcm_DslProtocolTxType;
#endif /* #if(0u != DCM_DSL_PROTOCOL_TX_NUM) */

#if(STD_ON == DCM_UDS0x2A_ENABLE)
/**
 * @brief	This container contains the configuration of a transmission channel for a periodic
 * 			transmission connection.
 */
typedef struct
{
	/**< @brief Reference to a Pdu in EcuC that is used for this periodic transmission channel. */
	PduIdType DcmDslPeriodicTxPduRef;
	/**< @brief Identifier of the PDU that is used by the lower level module for transmission
	 * 			confirmation of responses on this channel. */
	PduIdType DcmDslPeriodicTxConfirmationPduId;
}Dcm_DslPeriodicConnectionType;
#endif /* #if(STD_ON == DCM_UDS0x2A_ENABLE) */

/**
 * @brief	This container contains the configuration for a main connection of a diagnostic protocol.
 */
typedef struct
{
	/**< @brief Parent ProtocolRow index. */
	uint8 DcmDslParentProIdx;
	/**< @brief Reference to the ComMChannel on which the DcmDslProtocolRxPdu is received and the
	 * 			DcmDslProtocolTxPdu is transmitted. */
	uint8 DcmDslProtocolComMChannelRef;
#if(STD_ON == DCM_UDS0x2A_ENABLE)
	/**< @brief Number of DcmDslPeriodicConnection. */
	uint8 DcmDslPeriodicConnectionNum;
#endif /* #if(STD_ON == DCM_UDS0x2A_ENABLE) */
#if(0u != DCM_DSP_ROE_NUM)
	/**< @brief Reference to a ResponseOnEvent connection which is used for the processing of
	 * 			ResponseOnEvent events. */
	uint8 DcmDslROEConnectionRef;
#endif /* #if(0u != DCM_DSP_ROE_NUM) */
#if(0u)
	/* TODO:2025.12.10, LY: Not used. */
	/**< @brief Tester source address uniquely describes a client and will be used e.g within the jump
	 * 			to Bootloader interfaces. */
	uint16 DcmDslProtocolRxTesterSourceAddr;
	/**< @brief This container contains the configuration parameters of a reception channel in a
	 * 			diagnostic connection. */
	P2CONST(uint8, AUTOMATIC, DCM_CONST)DcmDslProtocolRx;
#endif /* #if(0u) */
#if(0u != DCM_DSL_PROTOCOL_TX_NUM)
	/**< @brief This container contains the configuration parameters of a transmission channel in a
	 * 			diagnostic connection. */
	P2CONST(Dcm_DslProtocolTxType, AUTOMATIC, DCM_CONST)DcmDslProtocolTx;
#endif /* #if(0u != DCM_DSL_PROTOCOL_TX_NUM) */
#if(STD_ON == DCM_UDS0x2A_ENABLE)
	/**< @brief Reference to a periodic transmission connection which is used for the processing of
	 * 			periodic transmission events. */
	P2CONST(Dcm_DslPeriodicConnectionType, AUTOMATIC, DCM_CONST)DcmDslPeriodicConnection;
#endif /* #if(STD_ON == DCM_UDS0x2A_ENABLE) */
}Dcm_DslMainConnectionType;

#if(0u != DCM_DSP_ROE_NUM)
/**
 * @brief	This container contains the configuration of a ResponseOnEvent connection.
 */
typedef struct
{
	/**< @brief  */
	/* TODO:2025.12.10, LY: Not supported. */
}Dcm_DslResponseOnEventType;
#endif /* #if(0u != DCM_DSP_ROE_NUM) */

/**
 * @brief	This container contains the configuration of one particular diagnostic protocol used in Dcm.
 */
typedef struct
{
	/**< @brief Allows to activate or deactivate the usage of a Protocol. */
	boolean DcmDslProtocolRowUsed;
	/**< @brief If set to TRUE, the Dcm will send a NRC 0x78 before a transition to bootloader or
	 * 			performing an ECU reset. If set to False, no 0x78 is send in this case. */
	boolean DcmSendRespPendOnTransToBoot;
	/**< @brief Protocol priority used during protocol preemption. */
	uint8 DcmDslProtocolPriority;
	/**< @brief This parameter is used to guarantee that the diagnostic response is available on the bus
	 * 			before reaching P2 by adjusting the current DcmDspSessionP2ServerMax. */
	uint8 DcmTimStrP2ServerAdjust;
	/**< @brief This parameter is used to guarantee that the diagnostic response is available on the bus
	 * 			before reaching P2Star by adjusting the current DcmDspSessionP2StarServerMax. */
	uint8 DcmTimStrP2StarServerAdjust;
#if(STD_ON == DCM_PAGED_BUFFER_ENABLED)
	/**< @brief This parameter is mandatory and defines the maximum length of the response message in
	 * 			case DcmPagedBufferEnabled == TRUE. */
	uint16 DcmDslProtocolMaximumResponseSize;
#endif /* #if(STD_ON == DCM_PAGED_BUFFER_ENABLED) */
	/**< @brief This parameter is the timeout value used in protocol preemption if this protocol
	 * 			preempts another diagnostic protocol. The protocol shall be started maximum
	 * 			DcmDslProtocolPreemptTimeout time after the first request in the new protocol. */
	uint16 DcmDslProtocolPreemptTimeout;
#if(0u != DCM_DSP_ROE_NUM)
	/**< @brief This parameter is used only if the protocol is of type DCM_ROE_ON_xxx. It selects the
	 * 			transmission type of the protocol. */
	Dcm_DslProtocolTransType DcmDslProtocolTransType;
#endif /* #if(0u != DCM_DSP_ROE_NUM) */
	/**< @brief The diagnostic protocol type for the DCM DSL protocol that is being configured. */
	Dcm_ProtocolType DcmDslProtocolID;
	/**< @brief Reference to a configured diagnostic buffer that is used for diagnostic request
	 * 			reception for the protocol. */
	P2CONST(Dcm_DslBufferType, AUTOMATIC, DCM_CONST)DcmDslProtocolRxBufferRef;
	/**< @brief Reference to a service table that is used for diagnostic request processing for this
	 * 			protocol. */
	P2CONST(Dcm_DsdServiceTableType, AUTOMATIC, DCM_CONST)DcmDslProtocolSIDTable;
#if(0u != DCM_DSL_PROTOCOL_TX_NUM)
	/**< @brief Reference to a configured diagnostic buffer that is used for diagnostic response
	 * 			transmission for the protocol. */
	P2CONST(Dcm_DslBufferType, AUTOMATIC, DCM_CONST)DcmDslProtocolTxBufferRef;
#endif /* #if(0u != DCM_DSL_PROTOCOL_TX_NUM) */
#if(0u)
	/* TODO:2025.12.10, LY: Not used. */
#if(0u != DCM_DSL_MAIN_CONNECTION_NUM)
	/**< @brief This container contains the configuration for a main connection of a diagnostic
	 * 			protocol. */
	P2CONST(uint8, AUTOMATIC, DCM_CONST)DcmDslMainConnection;
#endif /* #if(0u != DCM_DSL_MAIN_CONNECTION_NUM) */
#if(STD_ON == DCM_UDS0x2A_ENABLE)
	/**< @brief This container contains the configuration of a periodic transmission connection. */
	P2CONST(Dcm_DslPeriodicTransmissionType, AUTOMATIC, DCM_CONST)DcmDslPeriodicTransmission;
#endif /* #if(STD_ON == DCM_UDS0x2A_ENABLE) */
#if(0u != DCM_DSL_RESPONSEONEVENT_NUM)
	/**< @brief This container contains the configuration of a ResponseOnEvent connection. */
	P2CONST(uint8, AUTOMATIC, DCM_CONST)DcmDslResponseOnEvent;
#endif /* #if(0u != DCM_DSL_RESPONSEONEVENT_NUM) */
#endif /* #if(0u) */
}Dcm_DslProtocolRowType;

#if(STD_ON == DCM_DSL_CALLBACK_DCM_REQUEST_SERVICE_ENABLED)
/**
 * @brief	Each DcmDslCallbackDCMRequestService container defines an R-Port with the
 * 			CallbackDCMRequestServices interface which the Dcm uses to ask permission for protocol
 * 			changes from the application software.
 */
typedef struct
{
	/**< @brief All of the start protocol callback interface. */
	P2CONST(Dcm_CallbackDCMRequestServiceType, AUTOMATIC, DCM_CONST)DcmDslCallbackStartProtocol;
	/**< @brief All of the stop protocol callback interface. */
	P2CONST(Dcm_CallbackDCMRequestServiceType, AUTOMATIC, DCM_CONST)DcmDslCallbackStopProtocol;
}Dcm_DslCallbackDCMRequestServiceType;
#endif /* #if(STD_ON == DCM_DSL_CALLBACK_DCM_REQUEST_SERVICE_ENABLED) */

/**
 * @brief	These parameters configure the Diagnostic Session Layer submodule.
 */
typedef struct
{
	/**< @brief This container contains the configuration of a diagnostic buffer. */
	P2CONST(Dcm_DslBufferType, AUTOMATIC, DCM_CONST)DcmDslBuffer;
#if(STD_ON == DCM_DSL_CALLBACK_DCM_REQUEST_SERVICE_ENABLED)
	/**< @brief Each DcmDslCallbackDCMRequestService container defines an R-Port with the
	 * 			CallbackDCMRequestServices interface which the Dcm uses to ask permission for protocol
	 * 			changes from the application software. */
	P2CONST(Dcm_DslCallbackDCMRequestServiceType, AUTOMATIC, DCM_CONST)DcmDslCallbackDCMRequestService;
#endif /* #if(STD_ON == DCM_DSL_CALLBACK_DCM_REQUEST_SERVICE_ENABLED) */
	/**< @brief This container contains the configurations of the diagnostic protocols used in Dcm. */
	P2CONST(Dcm_DslProtocolRowType, AUTOMATIC, DCM_CONST)DcmDslProtocolRow;
}Dcm_DslType;

#if(STD_ON == DCM_UDS0x14_ENABLE)
/**
 * @brief	This container contains the configuration for the Clear DTC service.
 */
typedef struct
{
#if(STD_ON == DCM_PROCESSING_CONDITIONS_ENABLED)
	/**< @brief Reference to DcmModeRule. */
	uint8 DcmDspClearDTCModeRuleRef;
#endif /* #if(STD_ON == DCM_PROCESSING_CONDITIONS_ENABLED) */
	/**< @brief Callback function for condition check, manufacturer / supplier specific checks on the
	 * 			groupOfDTC, which is requested to clear. */
	Dcm_DspClearDTCCheckFncType DcmDspClearDTCCheckFnc;
}Dcm_DspClearDTCType;
#endif /* #if(STD_ON == DCM_UDS0x14_ENABLE) */

#if(STD_ON == DCM_UDS0x28_ENABLE)
#if(0u != DCM_DSP_COM_CONTROL_ALL_CHANNEL_NUM)
/**
 * @brief	Collection of ComM channels which shall be controlled if all networks are addressed.
 */
typedef struct
{
	/**< @brief Allow to activate or deactivate the usage of a ComM channel collection to be controlled,
	 * 			for multi purpose ECUs. */
	boolean DcmDspComControlAllChannelUsed;
	/**< @brief Reference to ComM channel. */
	uint8 DcmDspAllComMChannelRef;
}Dcm_DspComControlAllChannelType;
#endif /* #if(0u != DCM_DSP_COM_CONTROL_ALL_CHANNEL_NUM) */

#if(0u != DCM_DSP_COM_CONTROL_SPECIFIC_CHANNEL_NUM)
/**
 * @brief	Assigns subnet number to ComM channel which will be controlled.
 */
typedef struct
{
	/**< @brief Allow to activate or deactivate the usage of a Subnet assigned to the ComM channel which
	 * 			will be controlled, for multi purpose ECUs. */
	boolean DcmDspComControlSpecificChannelUsed;
	/**< @brief Subnet Number which controls the specific ComMChannel. */
	uint8 DcmDspSubnetNumber;
	/**< @brief Reference to ComM channel. */
	uint8 DcmDspSpecificComMChannelRef;
}Dcm_DspComControlSpecificChannelType;
#endif /* #if(0u != DCM_DSP_COM_CONTROL_SPECIFIC_CHANNEL_NUM) */

#if(0u != DCM_DSP_COM_CONTROL_SUB_NODE_NUM)
/**
 * @brief	This container gives information about the node identification number and the ComM channel
 * 			used to address a sub-network.
 */
typedef struct
{
	/**< @brief This parameter determines if a node control function is available or not. */
	boolean DcmDspComControlSubNodeUsed;
	/**< @brief This parameter references a ComM channel where this node is connected to. */
	uint8 DcmDspComControlSubNodeComMChannelRef;
	/**< @brief The node identification number DcmDspComControlSubNodeId is addressed by the
	 * 			CommunicationControl (0x28) request. */
	uint16 DcmDspComControlSubNodeId;
}Dcm_DspComControlSubNodeType;
#endif /* #if(0u != DCM_DSP_COM_CONTROL_SUB_NODE_NUM) */

/**
 * @brief	Provides the configuration of the CommunicationControl mechanism.
 */
typedef struct
{
#if(STD_ON == DCM_PROCESSING_CONDITIONS_ENABLED)
	/**< @brief Reference to DcmModeRule Mode rule which controls re-enabling. */
	uint8 DcmDspComControlCommunicationReEnableModeRuleRef;
#endif /* #if(STD_ON == DCM_PROCESSING_CONDITIONS_ENABLED) */
#if(0u != DCM_DSP_COM_CONTROL_ALL_CHANNEL_NUM)
	/**< @brief Collection of ComM channels which shall be controlled if all networks are addressed. */
	P2CONST(Dcm_DspComControlAllChannelType, AUTOMATIC, DCM_CONST)DcmDspComControlAllChannel;
#endif /* #if(0u != DCM_DSP_COM_CONTROL_ALL_CHANNEL_NUM) */
#if(0u != DCM_DSP_COM_CONTROL_SPECIFIC_CHANNEL_NUM)
	/**< @brief Assigns subnet number to ComM channel which will be controlled. */
	P2CONST(Dcm_DspComControlSpecificChannelType, AUTOMATIC, DCM_CONST)DcmDspComControlSpecificChannel;
#endif /* #if(0u != DCM_DSP_COM_CONTROL_SPECIFIC_CHANNEL_NUM) */
#if(0u != DCM_DSP_COM_CONTROL_SUB_NODE_NUM)
	/**< @brief This container gives information about the node identification number and the ComM
	 * 			channel used to address a sub-network. */
	P2CONST(Dcm_DspComControlSubNodeType, AUTOMATIC, DCM_CONST)DcmDspComControlSubNode;
#endif /* #if(0u != DCM_DSP_COM_CONTROL_SUB_NODE_NUM) */
}Dcm_DspComControlType;
#endif /* #if(STD_ON == DCM_UDS0x28_ENABLE) */

#if(STD_ON == DCM_UDS0x31_ENABLE)
#if(0u != DCM_DSP_COMMON_AUTHORIZATION_NUM)
/**
 * @brief	This container contains the configuration (parameters) for the common Authorization being
 * 			equal for several services / sub-services.
 */
typedef struct
{
#if(STD_ON == DCM_PROCESSING_CONDITIONS_ENABLED)
	/**< @brief Reference to DcmModeRule. */
	uint8 DcmDspCommonAuthorizationModeRuleRef;
#endif /* #if(STD_ON == DCM_PROCESSING_CONDITIONS_ENABLED) */
	/**< @brief Reference to DcmDspSessionRow. */
	Dcm_SessionDataType DcmDspCommonAuthorizationSessionRef;
	/**< @brief Reference to DcmDspSecurityRow. */
	Dcm_SecurityDataType DcmDspCommonAuthorizationSecurityLevelRef;
}Dcm_DspCommonAuthorizationType;
#endif /* #if(0u != DCM_DSP_COMMON_AUTHORIZATION_NUM) */
#endif /* #if(STD_ON == DCM_UDS0x31_ENABLE) */

#if(STD_ON == DCM_UDS0x85_ENABLE)
/**
 * @brief	Provide the configuration of the ControlDTCSetting mechanism.
 */
typedef struct
{
	/**< @brief This configuration switch defines if the DTCSettingControlOptionRecord is in general
	 * 			supported in the request message or not. */
	boolean DcmSupportDTCSettingControlOptionRecord;
#if(STD_ON == DCM_PROCESSING_CONDITIONS_ENABLED)
	/**< @brief Reference to DcmModeRule. */
	uint8 DcmDspControlDTCSettingReEnableModeRuleRef;
#endif /* #if(STD_ON == DCM_PROCESSING_CONDITIONS_ENABLED) */
}Dcm_DspControlDTCSettingType;
#endif /* #if(STD_ON == DCM_UDS0x85_ENABLE) */

#if(0u)
	/* TODO:2025.12.10, LY: Not supported. */
/**
 * @brief	This container contains the configuration (parameters) of an alternative Diagnosis
 * 			Representation by the means of a VariableDataPrototoype in a DataInterface.
 */
typedef struct
{
	/**< @brief Alternative Diagnosis Representation for the data defined by the means of a
	 * 			VariableDataPrototoype in a DataInterface. */
	uint8 DcmDataElement;
	/**< @brief Optional reference to PortInterfaceMapping which defines the mapping rules. */
	uint8 DcmPortInterfaceMapping;
}Dcm_DspAlternativeDataInterfaceType;

/**
 * @brief	The purpose of the DcmDspTextTableMapping is to associate a texttable value defined in the
 * 			context of the Dcm to a texttable value defined in the context of a CompuMethod referenced
 * 			by a DataType that shall be taken to create a dataElement in a SenderReceiverInterface. By
 * 			this means it is possible to create a primitive version of a TexttableMapping (which can
 * 			only be applied if a dataElement already exists).
 */
typedef struct
{
	/**< @brief The data value in the diagnosis representation. */
	uint64 DcmDspDiagnosisRepresentationDataValue;
	/**< @brief The ECU internal data value. */
	uint64 DcmDspInternalDataValue;
}Dcm_DspTextTableMappingType;

/**
 * @brief	This container contains the configuration (parameters) of an alternative Diagnosis
 * 			Representation by the means of an ApplicationDataType.
 */
typedef struct
{
	/**< @brief Alternative Diagnosis Representation for the data defined by the means of a
	 * 			ApplicationDataType of category VALUE, BOOLEAN or ARRAY. */
	uint8 DcmApplicationDataType;
	/**< @brief The purpose of the DcmDspTextTableMapping is to associate a texttable value defined
	 * 			in the context of the Dcm to a texttable value defined in the context of a CompuMethod
	 * 			referenced by a DataType that shall be taken to create a dataElement in a
	 * 			SenderReceiverInterface. By this means it is possible to create a primitive version of
	 * 			a TexttableMapping (which can only be applied if a dataElement already exists). */
	P2CONST(Dcm_DspTextTableMappingType, AUTOMATIC, DCM_CONST)DcmDspTextTableMapping;
}Dcm_DspAlternativeDataType;

/**
 * @brief	This container contains the configuration (parameters) of an alternative Diagnosis
 * 			Representation by the means of Diagnostic Extract.
 */
typedef struct
{
	/**< @brief Alternative Diagnosis Representation for the data defined by the means of a
	 * 			DiagnosticDataElement in the Diagnostic Extract. */
	uint8 DcmDspDiagnosticDataElementRef;
}Dcm_DspAlternativeDiagnosticDataElementType;

/**
 * @brief	Instance Reference to the primitive data in a port where the data element is typed with an
 * 			ApplicationPrimitveDataType or an ImplementationDataType.
 */
typedef struct
{
	/**< @brief Instance Reference to the primitive or array data which shall be read or written. */
	uint8 DcmDataElementInstanceRef;
}Dcm_DataElementInstanceType;

/**
 * @brief	Instance Reference to the primitve sub-element (at any level) of composite data in a port
 * 			where the data element is typed with an ApplicationCompositeDataType.
 */
typedef struct
{
	/**< @brief Instance Reference to the primitve sub-element (at any level) of composite data in a
	 * 			port which shall be read. */
	uint8 DcmSubElementInDataElementInstanceRef;
}Dcm_SubElementInDataElementInstanceType;

/**
 * @brief	Instance Reference to the primitve sub-element (at any level) of composite data in a port
 * 			where the data element is typed with an ImplementationDataType.
 */
typedef struct
{
	/**< @brief Instance Reference to the primitve sub-element (at any level) of composite data in a
	 * 			port which shall be read. */
	uint8 DcmSubElementInImplDataElementInstanceRef;
}Dcm_SubElementInImplDataElementInstanceType;
#endif /* #if(0u) */

#if(STD_ON == DCM_UDS0x24_ENABLE)
/**
 * @brief	This container contains the configuration (parameters) of one Data.
 */
typedef struct
{
	/**< @brief If Scaling information service is available for this Data, it provides the size in bytes
	 * 			of the scaling information. */
	uint32 DcmDspDataScalingInfoSize;
}Dcm_DspDataInfoType;
#endif /* #if(STD_ON == DCM_UDS0x24_ENABLE) */

#if(0u != DCM_DSP_DATA_NUM)
#if(0u)
	/* TODO:2025.12.10, LY: Not supported. */
/**
 * @brief	This container defines the supported information.
 */
typedef struct
{
	/**< @brief Referenced Bit of the SupportInfo. */
	uint8 DcmDspDidDataSupportInfoBit;
	/**< @brief Reference to DcmDspDidSupportInfo. */
	uint8 DcmDspDidDataSupportInfoRef;
}Dcm_DspDidDataSupportInfoType;
#endif /* #if(0u) */

#if(0u != DCM_DSP_DATA_BLOCK_USED_NUM)
/**
 * @brief	The read NV-block status for each signal of the DID.
 */
typedef struct
{
	/**< @brief NRAM blockId to access the data. */
	uint16 DcmDspDataReadBlockIdRef;
	/**< @brief Did signal internal buffer. */
	P2VAR(uint8, AUTOMATIC, DCM_VAR)DcmDspDataReadInternalBuffer;
}Dcm_DspDataReadBlockType;
#endif /* #if(0u != DCM_DSP_DATA_BLOCK_USED_NUM) */

/**
 * @brief	This container contains the configuration (parameters) of a Data belonging to a DID.
 */
typedef struct
{
#if(STD_ON == DCM_DSP_DATA_CONDITION_CHECK_READ_FNC_ENABLED)
	/**< @brief This parameter determines if a condition check function is available or not. */
	boolean DcmDspDataConditionCheckReadFncUsed;
#endif /* #if(STD_ON == DCM_DSP_DATA_CONDITION_CHECK_READ_FNC_ENABLED) */
#if(0u)
	/* TODO:2025.12.10, LY: Not supported. */
	/**< @brief Defines additional description for ODX documentation. */
	uint8 DcmDspOdxDataDescription;
#endif /* #if(0u) */
	/**< @brief Length of data in bits associated to the Data. If Data has variable datalength, that
	 * 			corresponds to the maximum datalength. */
	uint16 DcmDspDataSize;
#if(0u != DCM_DSP_DATA_BLOCK_USED_NUM)
	/**< @brief NRAM blockId to access the data. */
	uint16 DcmDspDataBlockIdRef;
#endif /* #if(0u != DCM_DSP_DATA_BLOCK_USED_NUM) */
	/**< @brief Defines the endianness of the data belonging to a DID in a diagnostic request or
	 * 			response message. */
	Dcm_DspDataEndiannessType DcmDspDataEndianness;
	/**< @brief Provide the implementation data type of data belonging to a DID. */
	Dcm_DspDataEnumType DcmDspDataType;
	/**< @brief Defines which interface shall be used to access the data. */
	Dcm_DspDataUsePortType DcmDspDataUsePort;
#if(STD_ON == DCM_DSP_DATA_GET_SCALING_INFO_FNC_ENABLED)
	/**< @brief Reference to 1 DcmDspDataInfo. */
	uint32 DcmDspDataInfoRef;
#endif /* #if(STD_ON == DCM_DSP_DATA_READ_ECU_SIGNAL_FNC_ENABLED) */
#if(STD_ON == DCM_DSP_DATA_CONDITION_CHECK_READ_FNC_ENABLED)
	/**< @brief Function name to demand application if the conditions (e.g. System state) to read the
	 * 			DID are correct. (ConditionCheckRead-function). */
	Dcm_DspDataConditionCheckReadFncType DcmDspDataConditionCheckReadFnc;
#endif /* #if(STD_ON == DCM_DSP_DATA_CONDITION_CHECK_READ_FNC_ENABLED) */
#if(STD_ON == DCM_DSP_DATA_ECU_SIGNAL_FNC_ENABLED)
	/**< @brief Function name to control the access to a certain ECU Signal by the DCM.
	 * 			(IoHwAb_Dcm_<symbolic name of ECU signal>-function). */
	Dcm_DspDataEcuSignalType DcmDspDataEcuSignal;
#endif /* #if(STD_ON == DCM_DSP_DATA_ECU_SIGNAL_FNC_ENABLED) */
#if(STD_ON == DCM_DSP_DATA_FREEZE_CURRENT_STATE_FNC_ENABLED)
	/**< @brief Function name to request to application to freeze the current state of an IOControl.
	 * 			(FreezeCurrentState-function). */
	Dcm_DspDataFreezeCurrentStateFncType DcmDspDataFreezeCurrentStateFnc;
#endif /* #if(STD_ON == DCM_DSP_DATA_FREEZE_CURRENT_STATE_FNC_ENABLED) */
#if(STD_ON == DCM_DSP_DATA_GET_SCALING_INFO_FNC_ENABLED)
	/**< @brief Function name to request to application the scaling information of the DID.
	 * 			(GetScalingInformation-function). */
	Dcm_DspDataGetScalingInfoFncType DcmDspDataGetScalingInfoFnc;
#endif /* #if(STD_ON == DCM_DSP_DATA_GET_SCALING_INFO_FNC_ENABLED) */
#if(STD_ON == DCM_DSP_DATA_READ_DATA_LENGTH_FNC_ENABLED)
	/**< @brief Function name to request from application the data length of a DID.
	 * 			(ReadDataLength-function). */
	Dcm_DspDataReadDataLengthFncType DcmDspDataReadDataLengthFnc;
#endif /* #if(STD_ON == DCM_DSP_DATA_READ_DATA_LENGTH_FNC_ENABLED) */
#if(STD_ON == DCM_DSP_DATA_READ_ECU_SIGNAL_FNC_ENABLED)
	/**< @brief Function name for read access to a certain ECU Signal by the DCM.
	 * 			(IoHwAb_Dcm_Read<EcuSignalName>-function). */
	Dcm_DspDataReadEcuSignalType DcmDspDataReadEcuSignal;
#endif /* #if(STD_ON == DCM_DSP_DATA_READ_ECU_SIGNAL_FNC_ENABLED) */
#if(STD_ON == DCM_DSP_DATA_READ_FNC_ENABLED)
	/**< @brief Function name to request from application the data value of a DID. */
	Dcm_DspDataReadFncType DcmDspDataReadFnc;
#endif /* #if(STD_ON == DCM_DSP_DATA_READ_FNC_ENABLED) */
#if(STD_ON == DCM_DSP_DATA_RESET_TO_DEFAULT_FNC_ENABLED)
	/**< @brief Function name to request to application to reset an IOControl to default value.
	 * 			(ResetToDefault-function). */
	Dcm_DspDataResetToDefaultFncType DcmDspDataResetToDefaultFnc;
#endif /* #if(STD_ON == DCM_DSP_DATA_RESET_TO_DEFAULT_FNC_ENABLED) */
#if(STD_ON == DCM_DSP_DATA_RETURN_CONTROL_TO_ECU_FNC_ENABLED)
	/**< @brief Function name to request to application to return control to ECU of an IOControl.
	 * 			(ReturnControlToECU-function). */
	Dcm_DspDataReturnControlToEcuFncType DcmDspDataReturnControlToEcuFnc;
#endif /* #if(STD_ON == DCM_DSP_DATA_RETURN_CONTROL_TO_ECU_FNC_ENABLED) */
#if(STD_ON == DCM_DSP_DATA_SHORT_TERM_ADJUSTMENT_FNC_ENABLED)
	/**< @brief Function name to request to application to adjust the IO signal.
	 * 			(ShortTermAdjustment-function). */
	Dcm_DspDataShortTermAdjustmentFncType DcmDspDataShortTermAdjustmentFnc;
#endif /* #if(STD_ON == DCM_DSP_DATA_SHORT_TERM_ADJUSTMENT_FNC_ENABLED) */
#if(STD_ON == DCM_DSP_DATA_WRITE_FNC_ENABLED)
	/**< @brief Function name to request application to write the data value of a DID.
	 * 			(WriteData-function). */
	Dcm_DspDataWriteFncType DcmDspDataWriteFnc;
#endif /* #if(STD_ON == DCM_DSP_DATA_WRITE_FNC_ENABLED) */
	/**< @brief Did signal internal buffer. */
	P2VAR(uint8, AUTOMATIC, DCM_VAR)DcmDspDataInternalBuffer;
#if(0u)
	/* TODO:2025.12.10, LY: Not supported. */
	/**< @brief This container contains the configuration (parameters) of an alternative Diagnosis
	 * 			Representation by the means of a VariableDataPrototoype in a DataInterface. */
	P2CONST(Dcm_DspAlternativeDataInterfaceType, AUTOMATIC, DCM_CONST)DcmDspAlternativeDataInterface;
	/**< @brief This container contains the configuration (parameters) of an alternative Diagnosis
	 * 			Representation by the means of an ApplicationDataType. */
	P2CONST(Dcm_DspAlternativeDataType, AUTOMATIC, DCM_CONST)DcmDspAlternativeDataType;
	/**< @brief This container contains the configuration (parameters) of an alternative Diagnosis
	 * 			Representation by the means of Diagnostic Extract. */
	P2CONST(Dcm_DspAlternativeDiagnosticDataElementType, AUTOMATIC, DCM_CONST)DcmDspAlternativeDiagnosticDataElement;
	/**< @brief This container defines the supported information. */
	P2CONST(Dcm_DspDidDataSupportInfoType, AUTOMATIC, DCM_CONST)DcmDspDidDataSupportInfo;
	/**< @brief Instance Reference to the primitive data in a port where the data element is typed with
	 * 			an ApplicationPrimitveDataType or an ImplementationDataType. */
	P2CONST(Dcm_DataElementInstanceType, AUTOMATIC, DCM_CONST)DcmDataElementInstance;
	/**< @brief Instance Reference to the primitve sub-element (at any level) of composite data in a
	 * 			port where the data element is typed with an ApplicationCompositeDataType. */
	P2CONST(Dcm_SubElementInDataElementInstanceType, AUTOMATIC, DCM_CONST)DcmSubElementInDataElementInstance;
	/**< @brief Instance Reference to the primitve sub-element (at any level) of composite data in a
	 * 			port where the data element is typed with an ImplementationDataType. */
	P2CONST(Dcm_SubElementInImplDataElementInstanceType, AUTOMATIC, DCM_CONST)DcmSubElementInImplDataElementInstance;
#endif /* #if(0u) */
}Dcm_DspDataType;
#endif /* #if(0u != DCM_DSP_DATA_NUM) */

#if(0u != DCM_DSP_DID_INTO_NUM)
#if(STD_ON == DCM_UDS0x2F_ENABLE)
/**
 * @brief	This container contains the configuration (parameters) of the DID control.
 */
typedef struct
{
	/**< @brief This indicates the presence of "FreezeCurrentState". */
	boolean DcmDspDidFreezeCurrentState;
	/**< @brief This indicates the presence of "ResetToDefault". */
	boolean DcmDspDidResetToDefault;
	/**< @brief This indicates the presence of "ShortTermAdjustment". */
	boolean DcmDspDidShortTermAdjustment;
#if(STD_ON == DCM_PROCESSING_CONDITIONS_ENABLED)
	/**< @brief Reference to DcmModeRule. */
	uint8 DcmDspDidControlModeRuleRef;
#endif /* #if(STD_ON == DCM_PROCESSING_CONDITIONS_ENABLED) */
	/**< @brief Reference to DcmDspSessionRow. */
	Dcm_SessionDataType DcmDspDidControlSessionRef;
	/**< @brief Reference to DcmDspSecurityRow. */
	Dcm_SecurityDataType DcmDspDidControlSecurityLevelRef;
	/**< @brief The value defines the size of the controlEnableMaskRecord in bytes. */
	uint32 DcmDspDidControlMaskSize;
	/**< @brief Defines the position of the bit in the controlMask starting from most significant bit
	 * 			(MSB first) to least significant bit. */
	uint32 DcmDspDidControlEnableMask;
	/**< @brief This indicates the presence of "controlEnableMask" in SWC service interfaces and defines
	 * 			how the Dcm treats a service request. */
	Dcm_DspDidControlMaskType DcmDspDidControlMask;
}Dcm_DspDidControlType;
#endif /* #if(STD_ON == DCM_UDS0x2F_ENABLE) */

#if(STD_ON == DCM_UDS0x22_ENABLE)
/**
 * @brief	This container contains the configuration (parameters) of the DID read.
 */
typedef struct
{
#if(STD_ON == DCM_PROCESSING_CONDITIONS_ENABLED)
	/**< @brief Reference to DcmModeRule. */
	uint8 DcmDspDidReadModeRuleRef;
#endif /* #if(STD_ON == DCM_PROCESSING_CONDITIONS_ENABLED) */
	/**< @brief Reference to DcmDspSessionRow Referenced sessions are allowed to read this DID. */
	Dcm_SessionDataType DcmDspDidReadSessionRef;
	/**< @brief Reference to DcmDspSecurityRow Referenced security levels are allowed to read this DID. */
	Dcm_SecurityDataType DcmDspDidReadSecurityLevelRef;
}Dcm_DspDidReadType;
#endif /* #if(STD_ON == DCM_UDS0x22_ENABLE) */

#if(STD_ON == DCM_UDS0x2E_ENABLE)
/**
 * @brief	This container contains the configuration (parameters) of the DID write.
 */
typedef struct
{
#if(STD_ON == DCM_PROCESSING_CONDITIONS_ENABLED)
	/**< @brief Reference to DcmModeRule. */
	uint8 DcmDspDidWriteModeRuleRef;
#endif /* #if(STD_ON == DCM_PROCESSING_CONDITIONS_ENABLED) */
	/**< @brief Reference to DcmDspSessionRow Referenced sessions are allowed to write this DID. */
	Dcm_SessionDataType DcmDspDidWriteSessionRef;
	/**< @brief Reference to DcmDspSecurityRow Referenced security levels are allowed to wirte this DID. */
	Dcm_SecurityDataType DcmDspDidWriteSecurityLevelRef;
}Dcm_DspDidWriteType;
#endif /* #if(STD_ON == DCM_UDS0x2E_ENABLE) */

/**
 * @brief	This container contains the configuration (parameters) of the DID's Info.
 */
typedef struct
{
#if(STD_ON == DCM_UDS0x2C_ENABLE)
	/**< @brief Indicates if this DID can be dynamically defined. */
	boolean DcmDspDidDynamicallyDefined;
	/**< @brief The DDDID index in all DDDIDs. */
	uint8 DcmDspDDDIDIndex;
	/**< @brief Maximum number of source elements of a DDDID. */
	uint8 DcmDspDDDIDMaxElements;
#endif /* #if(STD_ON == DCM_UDS0x2C_ENABLE) */
#if(STD_ON == DCM_UDS0x2F_ENABLE)
	/**< @brief This container contains the configuration (parameters) of the DID control. */
	P2CONST(Dcm_DspDidControlType, AUTOMATIC, DCM_CONST)DcmDspDidControl;
#endif /* #if(STD_ON == DCM_UDS0x2F_ENABLE) */
#if(STD_ON == DCM_UDS0x22_ENABLE)
	/**< @brief This container contains the configuration (parameters) of the DID read. */
	P2CONST(Dcm_DspDidReadType, AUTOMATIC, DCM_CONST)DcmDspDidRead;
#endif /* #if(STD_ON == DCM_UDS0x22_ENABLE) */
#if(STD_ON == DCM_UDS0x2E_ENABLE)
	/**< @brief This container contains the configuration (parameters) of the DID write. */
	P2CONST(Dcm_DspDidWriteType, AUTOMATIC, DCM_CONST)DcmDspDidWrite;
#endif /* #if(STD_ON == DCM_UDS0x2E_ENABLE) */
}Dcm_DspDidInfoType;
#endif /* #if(0u != DCM_DSP_DID_INTO_NUM) */

#if(0u != DCM_DSP_DID_NUM)
#if(0u != DCM_DSP_DID_SIGNAL_NUM)
/**
 * @brief	This container defines the reference to 1 DcmDspData container and position relevant for
 * 			this DID.
 */
typedef struct
{
#if(STD_ON == DCM_UDS0x2F_ENABLE)
	/**< @brief Signal index of the DID. */
	uint8 DcmDspDidSignalIndex;
#endif /* #if(STD_ON == DCM_UDS0x2F_ENABLE) */
	/**< @brief Defines the absolute byte offset of the data defined by DcmDspDidDataRef reference to
	 * 			DcmDspData container in the DID. */
	uint16 DcmDspDidDataPos;
	/**< @brief Reference to 1 DcmDspData container relevant for this DID. */
	P2CONST(Dcm_DspDataType, AUTOMATIC, DCM_CONST)DcmDspDidDataRef;
}Dcm_DspDidSignalType;
#endif /* #if(0u != DCM_DSP_DID_SIGNAL_NUM) */

#if(0u)
	/* TODO:2025.12.10, LY: Not supported. */
/**
 * @brief	This container defines the support information to declare the usability of the data bytes
 * 			within the DIDs.
 */
typedef struct
{
	/**< @brief Length of the support information in bytes. */
	uint8 DcmDspDidSupportInfoLen;
	/**< @brief Length of the support information in bytes. */
	uint8 DcmDspDidSupportInfoPos;
}Dcm_DspDidSupportInfoType;
#endif /* #if(0u) */

/**
 * @brief	This container contains the configuration (parameters) of the DID.
 */
typedef struct
{
	/**< @brief Allow to activate or deactivate the usage of a DID, for multi purpose ECUs. */
	boolean DcmDspDidUsed;
	/**< @brief Signals number. */
	uint8 DcmDspDidSignalNum;
	/**< @brief 2 byte Identifier of the DID. */
	uint16 DcmDspDidIdentifier;
	/**< @brief Reference to DcmDspDidInfo containing information on this DID. */
	P2CONST(Dcm_DspDidInfoType, AUTOMATIC, DCM_CONST)DcmDspDidInfoRef;
#if(0u != DCM_DSP_DID_SIGNAL_NUM)
	/**< @brief This container defines the reference to 1 DcmDspData container and position relevant for
	 * 			this DID. */
	P2CONST(Dcm_DspDidSignalType, AUTOMATIC, DCM_CONST)DcmDspDidSignal;
#endif /* #if(0u != DCM_DSP_DID_SIGNAL_NUM) */
#if(0u)
	/* TODO:2025.12.10, LY: Not supported. */
	/**< @brief Reference to DcmDspVehInfoTags: atp.Status=obsolete, atp.StatusComment=This reference is
	 * 			set to obsolete and will be removed in release 4.3. Use DcmDspEnableObdMirror instead.,
	 * 			atp.StatusRevisionBegin=4.2.2. */
	P2CONST(uint8, AUTOMATIC, DCM_CONST)DcmDspDidInfotypeRef;
	/**< @brief Reference to DcmDspPid.Tags: atp.Status=obsolete, atp.StatusComment=This reference is
	 * 			set to obsolete and will be removed in release 4.3. Use DcmDspEnableObdMirror instead.,
	 * 			atp.StatusRevisionBegin=4.2.2. */
	P2CONST(uint8, AUTOMATIC, DCM_CONST)DcmDspDidPidRef;
	/**< @brief Reference to DcmDspDid in case this DID refer to one or serveral other DID's. */
	P2CONST(uint8, AUTOMATIC, DCM_CONST)DcmDspDidRef;
#endif /* #if(0u) */
}Dcm_DspDidType;
#endif /* #if(0u != DCM_DSP_DID_NUM) */

#if(0u != DCM_DSP_DID_RANGE_NUM)
/**
 * @brief	This container defines the DID Range.
 */
typedef struct
{
	/**< @brief Parameter specifying if there are gaps in the DID range (parameter set to TRUE) or not
	 * 			(parameter set to FALSE). */
	boolean DcmDspDidRangeHasGaps;
	/**< @brief When the parameter DcmDspDidRangeUsePort is set to true the DCM will access the Data
	 * 			using an R-Port requiring a PortInteface DataServices_DIDRange. In that case,
	 * 			DcmDspDidRangeIsDidAvailableFnc, DcmDspDidRangeReadDidFnc and DcmDspDidRangeWriteDidFnc
	 * 			are ignored and the RTE APIs are used. When the parameter DcmDspDidRangeUsePort is
	 * 			false, the DCM calls the functions defined in DcmDspDidRangeIsDidAvailableFnc,
	 * 			DcmDspDidRangeReadDidFnc and DcmDspDidRangeWriteDidFnc. */
	boolean DcmDspDidRangeUsePort;
	/**< @brief Lower limit of DID range. */
	uint16 DcmDspDidRangeIdentifierLowerLimit;
	/**< @brief Upper limit of DID range. */
	uint16 DcmDspDidRangeIdentifierUpperLimit;
	/**< @brief Maximum data length in bytes. */
	uint16 DcmDspDidRangeMaxDataLength;
#if(STD_ON == DCM_DSP_DID_RANGE_IS_DID_AVAILABLE_FNC_ENABLE)
	/**< @brief Function name to request from application if a specific DID is available within the
	 * 			range or not. */
	Dcm_DspDidRangeIsDidAvailableFncType DcmDspDidRangeIsDidAvailableFnc;
#endif /* #if(STD_ON == DCM_DSP_DID_RANGE_READ_FNC_ENABLE) */
#if(STD_ON == DCM_DSP_DID_RANGE_READ_DATA_LENGTH_FNC_ENABLE)
	/**< @brief Function name to request from application the length of the data of a range DID. */
	Dcm_DspDidRangeReadDataLengthFncType DcmDspDidRangeReadDataLengthFnc;
#endif /* #if(STD_ON == DCM_DSP_DID_RANGE_READ_DATA_LENGTH_FNC_ENABLE) */
#if(STD_ON == DCM_DSP_DID_RANGE_READ_DID_FNC_ENABLE)
	/**< @brief Function name to request from application the data range value of a DID.
	 * 			(ReadData-function). */
	Dcm_DspDidRangeReadDidFncType DcmDspDidRangeReadDidFnc;
#endif /* #if(STD_ON == DCM_DSP_DID_RANGE_READ_DID_FNC_ENABLE) */
#if(STD_ON == DCM_DSP_DID_RANGE_WRITE_DID_FNC_ENABLE)
	/**< @brief Function name to request application to write the data range value of a DID.
	 * 			(WriteData-function). */
	Dcm_DspDidRangeWriteDidFncType DcmDspDidRangeWriteDidFnc;
#endif /* #if(STD_ON == DCM_DSP_DID_RANGE_WRITE_DID_FNC_ENABLE) */
	/**< @brief Reference to DcmDspDidInfo containing information on this DID Range. */
	P2CONST(Dcm_DspDidInfoType, AUTOMATIC, DCM_CONST)DcmDspDidRangeInfoRef;
}Dcm_DspDidRangeType;
#endif /* #if(0u != DCM_DPS_DID_RANGE_NUM) */

#if(0u != DCM_DSP_MEMORY_NUM)
#if(0u != DCM_DSP_READ_MEMORY_RANGE_INFO_NUM)
/**
 * @brief	Provides the range of memory address allowed for reading.
 */
typedef struct
{
#if(STD_ON == DCM_PROCESSING_CONDITIONS_ENABLED)
	/**< @brief Reference to DcmModeRule. */
	uint8 DcmDspReadMemoryRangeModeRuleRef;
#endif /* #if(STD_ON == DCM_PROCESSING_CONDITIONS_ENABLED) */
	/**< @brief Link to the Security Access Levels needed for read access on this memory address. If
	 * 			there is no reference, no check of security level shall be done. */
	Dcm_SecurityDataType DcmDspReadMemoryRangeSecurityLevelRef;
	/**< @brief Low memory address of a range allowed for reading. */
	uint32 DcmDspReadMemoryRangeLow;
	/**< @brief High memory address of a range allowed for reading. */
	uint32 DcmDspReadMemoryRangeHigh;
}Dcm_DspReadMemoryRangeInfoType;
#endif /* #if(0u != DCM_DSP_READ_MEMORY_RANGE_INFO_NUM) */

#if(0u != DCM_DSP_WRITE_MEMORY_RANGE_INFO_NUM)
/**
 * @brief	Provides the range of memory address allowed for writting.
 */
typedef struct
{
#if(STD_ON == DCM_PROCESSING_CONDITIONS_ENABLED)
	/**< @brief Reference to DcmModeRule. */
	uint8 DcmDspWriteMemoryRangeModeRuleRef;
#endif /* #if(STD_ON == DCM_PROCESSING_CONDITIONS_ENABLED) */
	/**< @brief Link to the Security Access Levels needed for write access on this memory address. If
	 * 			there is no reference, no check of security level shall be done. */
	Dcm_SecurityDataType DcmDspWriteMemoryRangeSecurityLevelRef;
	/**< @brief Low memory address of a range allowed for writing. */
	uint32 DcmDspWriteMemoryRangeLow;
	/**< @brief High memory address of a range allowed for writing. */
	uint32 DcmDspWriteMemoryRangeHigh;
}Dcm_DspWriteMemoryRangeInfoType;
#endif /* #if(0u != DCM_DSP_WRITE_MEMORY_RANGE_INFO_NUM) */

/**
 * @brief	Provides the value of memory identifier used to select the desired memory device.
 */
typedef struct
{
	/**< @brief Value of the memory device identifier used. */
	uint8 DcmDspMemoryIdValue;
#if(0u != DCM_DSP_READ_MEMORY_RANGE_INFO_NUM)
	/**< @brief Read memory range information number. */
	uint8 DcmDspReadMemoryRangeInfoNum;
#endif /* #if(0u != DCM_DSP_READ_MEMORY_RANGE_INFO_NUM) */
#if(0u != DCM_DSP_WRITE_MEMORY_RANGE_INFO_NUM)
	/**< @brief Write memory range information number. */
	uint8 DcmDspWriteMemoryRangeInfoNum;
#endif /* #if(0u != DCM_DSP_WRITE_MEMORY_RANGE_INFO_NUM) */
#if(0u != DCM_DSP_READ_MEMORY_RANGE_INFO_NUM)
	/**< @brief Provides the range of memory address allowed for reading. */
	P2CONST(Dcm_DspReadMemoryRangeInfoType, AUTOMATIC, DCM_CONST)DcmDspReadMemoryRangeInfo;
#endif /* #if(0u != DCM_DSP_READ_MEMORY_RANGE_INFO_NUM) */
#if(0u != DCM_DSP_WRITE_MEMORY_RANGE_INFO_NUM)
	/**< @brief Provides the range of memory address allowed for writting. */
	P2CONST(Dcm_DspWriteMemoryRangeInfoType, AUTOMATIC, DCM_CONST)DcmDspWriteMemoryRangeInfo;
#endif /* #if(0u != DCM_DSP_WRITE_MEMORY_RANGE_INFO_NUM) */
}Dcm_DspMemoryIdInfoType;

/**
 * @brief	This container contains the configuration of the memory access.
 */
typedef struct
{
#if(0u != DCM_DSP_MEMORY_FORMAT_ID_NUM)
	/**< @brief This container contains the configuration of the supported
	 * 			AddressAndLengthFormatIdentifiers for memory access. */
	P2CONST(uint8, AUTOMATIC, DCM_CONST)DcmDspSupportedAddressAndLengthFormatIdentifier;
#endif /* #if(0u != DCM_DSP_MEMORY_FORMAT_ID_NUM) */
	/**< @brief Provides the value of memory identifier used to select the desired memory device. */
	P2CONST(Dcm_DspMemoryIdInfoType, AUTOMATIC, DCM_CONST)DcmDspMemoryIdInfo;
}Dcm_DspMemoryType;
#endif /* #if(0u != DCM_DSP_MEMORY_NUM) */

#if(0u != DCM_DSP_PID_NUM)
/**
 * @brief	This container defines the supported information.
 */
typedef struct
{
	/**< @brief Referenced Bit of the SupportInfo. */
	uint8 DcmDspPidDataSupportInfoBit;
	/**< @brief Reference to DcmDspPidSupportInfo. */
	uint8 DcmDspPidDataSupportInfoRef;
}Dcm_DspPidDataSupportInfoType;

/**
 * @brief	Contains specific configuration parameter of PID for service $01. This container exists only
 * 			if DcmDspPidService is set to DCM_SERVICE_01 or DCM_SERVICE_01_02.
 */
typedef struct
{
	/**< @brief Defines the endianness of the data belonging to a PID in a diagnostic response message. */
	Dcm_DspDataEndiannessType DcmDspPidDataEndianness;
	/**< @brief Provide the implementation data type of data belonging to a PID. */
	Dcm_DspDataEnumType DcmDspPidDataType;
	/**< @brief If this parameter is set to USE_DATA_SYNCH_FNC, the Dcm will use the function defined in
	 * 			DcmDspPidDataReadFnc to get the PID data value. */
	Dcm_DspDataUsePortType DcmDspPidDataUsePort;
	/**< @brief Function name for reading PID data value. */
	Dcm_DspPidDataReadFncType DcmDspPidDataReadFnc;
	/**< @brief This container contains the configuration (parameters) of an alternative Diagnosis
	 * 			Representation by the means of a VariableDataPrototoype in a DataInterface. */
	P2CONST(Dcm_DspAlternativeDataInterfaceType, AUTOMATIC, DCM_CONST)DcmDspAlternativeDataInterface;
	/**< @brief This container contains the configuration (parameters) of an alternative Diagnosis
	 * 			Representation by the means of an ApplicationDataType. */
	P2CONST(Dcm_DspAlternativeDataType, AUTOMATIC, DCM_CONST)DcmDspAlternativeDataType;
	/**< @brief This container contains the configuration (parameters) of an alternative Diagnosis
	 * 			Representation by the means of Diagnostic Extract. */
	P2CONST(Dcm_DspAlternativeDiagnosticDataElementType, AUTOMATIC, DCM_CONST)DcmDspAlternativeDiagnosticDataElement;
	/**< @brief Instance Reference to the primitive data in a port where the data element is typed with
	 * 			an ApplicationPrimitveDataType or an ImplementationDataType. */
	P2CONST(Dcm_DataElementInstanceType, AUTOMATIC, DCM_CONST)DcmDataElementInstance;
	/**< @brief Instance Reference to the primitve sub-element (at any level) of composite data in a
	 * 			port where the data element is typed with an ApplicationCompositeDataType. */
	P2CONST(Dcm_SubElementInDataElementInstanceType, AUTOMATIC, DCM_CONST)DcmSubElementInDataElementInstance;
	/**< @brief Instance Reference to the primitve sub-element (at any level) of composite data in a
	 * 			port where the data element is typed with an ImplementationDataType. */
	P2CONST(Dcm_SubElementInImplDataElementInstanceType, AUTOMATIC, DCM_CONST)DcmSubElementInImplDataElementInstance;
}Dcm_DspPidService01Type;

/**
 * @brief	Contains specific configuration parameter of PID for service $02. This container exists only
 * 			if DcmDspPidService is set to DCM_SERVICE_02 or DCM_SERVICE_01_02.
 */
typedef struct
{
	/**< @brief Reference to DemPidDataElement in DEM configuration. Allows to link the DCM PID and DEM
	 * 			PID configuration for Mode $02. */
	uint8 DcmDspPidDataDemRef;
}Dcm_DspPidService02Type;

/**
 * @brief	This container defines the parameter for a Signal in the PID.
 */
typedef struct
{
	/**< @brief This is the position in bytes of the PID structure and will not start at position 0 in
	 * 			case a support information is available (for packeted PIDs). */
	uint8 DcmDspPidByteOffset;
	/**< @brief Defines the array length in bytes or the the maximum array length for variable
	 * 			datalengths. */
	uint8 DcmDspPidDataByteSize;
	/**< @brief This container defines the supported information. */
	P2CONST(Dcm_DspPidDataSupportInfoType, AUTOMATIC, DCM_CONST)DcmDspPidDataSupportInfo;
	/**< @brief Contains specific configuration parameter of PID for service $01. This container exists
	 * 			only if DcmDspPidService is set to DCM_SERVICE_01 or DCM_SERVICE_01_02. */
	P2CONST(Dcm_DspPidService01Type, AUTOMATIC, DCM_CONST)DcmDspPidService01;
	/**< @brief Contains specific configuration parameter of PID for service $02. This container exists
	 * 			only if DcmDspPidService is set to DCM_SERVICE_01 or DCM_SERVICE_01_02. */
	P2CONST(Dcm_DspPidService02Type, AUTOMATIC, DCM_CONST)DcmDspPidService02;
}Dcm_DspPidDataType;

/**
 * @brief	This container defines the support information (typically byte A) to declare the usability
 * 			of the data bytes within the so-called packeted PIDs (e.g. PID$68).
 */
typedef struct
{
	/**< @brief Length of the support information in bytes. */
	uint8 DcmDspPidSupportInfoLen;
	/**< @brief Position of the support information in bytes. */
	uint8 DcmDspPidSupportInfoPos;
}Dcm_DspPidSupportInfoType;

/**
 * @brief	This container defines the availability of a PID to the DCM.
 */
typedef struct
{
	/**< @brief Allow to activate or deactivate the usage of a PID, for multi purpose ECUs. */
	boolean DcmDspPidUsed;
	/**< @brief 1 byte Identifier of the PID. */
	uint8 DcmDspPidIdentifier;
	/**< @brief Length of a PID in byte(s). */
	uint8 DcmDspPidSize;
	/**< @brief Indicates if a PID is used with service $01 and/or $02. */
	Dcm_DspPidServiceType DcmDspPidService;
	/**< @brief This container defines the parameter for a Signal in the PID. */
	P2CONST(Dcm_DspPidDataType, AUTOMATIC, DCM_CONST)DcmDspPidData;
	/**< @brief This container defines the support information (typically byte A) to declare the
	 * 			usability of the data bytes within the so-called packeted PIDs (e.g. PID$68). */
	P2CONST(Dcm_DspPidSupportInfoType, AUTOMATIC, DCM_CONST)DcmDspPidSupportInfo;
}Dcm_DspPidType;
#endif /* #if(0u != DCM_DSP_PID_NUM) */

#if(0u != DCM_DSP_REQUEST_CONTROL_NUM)
/**
 * @brief	This container contains the configuration (parameters) of the "Request control of on-board
 * 			system, test or component" service (Service $08).
 */
typedef struct
{
	/**< @brief  */
	uint8 DcmDspRequestControlInBufferSize;
	/**< @brief  */
	uint8 DcmDspRequestControlInfoByte;
	/**< @brief  */
	uint8 DcmDspRequestControlOutBufferSize;
	/**< @brief  */
	uint8 DcmDspRequestControlTestId;
}Dcm_DspRequestControlType;
#endif /* #if(0u != DCM_DSP_REQUEST_CONTROL_NUM) */

#if(0u != DCM_DSP_REQUEST_FILE_TRANSFER_NUM)
/**
 * @brief	This container contains the configuration for RequestFileTransfer.
 */
typedef struct
{
	/**< @brief Defines if a C/S or C function call shall be used for RequestFileTransfer processing. */
	boolean DcmRequestFileTransferUsePort;
	/**< @brief Defines the length (number of bytes, i.e. the value of fileSizeOrDirInfoParameterLength)
	 * 			of the fileSizeUncompressedOrDirInfoLength and fileSizeCompressed in the response of
	 * 			RequestFileTransfer. */
	uint8 DcmRequestFileTransferFileSizeOrDirInfoParameterLength;
	/**< @brief Defines the length (number of bytes) of the maxNumberOfBlockLength parameter in the
	 * 			response of RequestFileTransfer. */
	uint8 DcmRequestFileTransferLengthFormatIdentifier;
	/**< @brief Defines the maximum size allowed for the FileAndDirName parameter with RTE interfaces
	 * 			used for RequestFileTransfer. */
	uint16 DcmRequestFileTransferMaxFileAndDirName;
}Dcm_DspRequestFileTransferType;
#endif /* #if(0u != DCM_DSP_REQUEST_FILE_TRANSFER_NUM) */

#if(0u != DCM_DSP_ROE_NUM)
/**
 * @brief	This container contains the eventTypeRecord supported for onChangeOfDataIdentifier eventType.
 */
typedef struct
{
	/**< @brief Reference to a Did which is watched. */
	uint8 DcmDspRoeDidRef;
}Dcm_DspRoeOnChangeOfDataIdentifierType;

/**
 * @brief	This container contains the eventTypeRecord supported for onDTCStatusChange eventType.
 */
typedef struct
{
	/**< @brief Value of the relevant DTCStatusMask. */
	uint8 DcmDspRoeDTCStatusMask;
}Dcm_DspRoeOnDTCStatusChangeType;

/**
 * @brief	This container contains a list of all supported Roe eventTypeRecords which are accepted by
 * 			this ECU.
 */
typedef struct
{
	/**< @brief EventId for a global identification of this ROE event it is used within APIs
	 * 			Dcm_TriggerOnEvent() and the ModeDeclarationGroup. */
	uint8 DcmDspRoeEventId;
	/**< @brief Initial Roe status of this RoeEvent. */
	Dcm_DspRoeInitialEventStatusType DcmDspRoeInitialEventStatus;
	/**< @brief This container contains the eventTypeRecord supported for onChangeOfDataIdentifier
	 * 			eventType. */
	P2CONST(Dcm_DspRoeOnChangeOfDataIdentifierType, AUTOMATIC, DCM_CONST)DcmDspRoeOnChangeOfDataIdentifier;
	/**< @brief This container contains the eventTypeRecord supported for onDTCStatusChange eventType. */
	P2CONST(Dcm_DspRoeOnDTCStatusChangeType, AUTOMATIC, DCM_CONST)DcmDspRoeOnDTCStatusChange;
}Dcm_DspRoeEventType;

/**
 * @brief	Provide the configuration of the ResponseOnEvent mechanism.
 */
typedef struct
{
	/**< @brief Provide the minimum time in seconds between two transmissions of ROE event. It is used
	 * 			for the delay between two different consecutive Roe transmissions. */
	uint8 DcmDspRoeInterMessageTime;
	/**< @brief This container contains a list of all supported Roe eventTypeRecords which are accepted
	 * 			by this ECU. */
	P2CONST(Dcm_DspRoeEventType, AUTOMATIC, DCM_CONST)DcmDspRoeEvent;
	/**< @brief This container configures the available EventWindowTime in this Ecu. */
	P2CONST(Dcm_DspRoeEventWindowTimeType, AUTOMATIC, DCM_CONST)DcmDspRoeEventWindowTime;
}Dcm_DspRoeType;
#endif /* #if(0u != DCM_DSP_ROE_NUM) */

#if(STD_ON == DCM_UDS0x31_ENABLE)
#if(0u)
	/* TODO:2025.12.10, LY: Not supported. */
/**
 * @brief	This container contains the configuration (parameters) of an alternative Diagnosis
 * 			Representation by the means of a ArgumentDataPrototype.
 */
typedef struct
{
	/**< @brief Alternative Diagnosis Representation for the data defined by the means of a
	 * 			ArgumentDataPrototype. */
	uint8 DcmDataElement;
}Dcm_DspAlternativeArgumentDataType;
#endif /* #if(0u) */

/**
 * @brief	Provides description of a routine signal used in RoutineControl service.
 */
typedef struct
{
	/**< @brief Provide the length in bits of the signal in the RoutineControl request/response. */
	uint16 DcmDspRoutineSignalLength;
	/**< @brief Provide the position of the signal in the RoutineControl request/response. */
	uint16 DcmDspRoutineSignalPos;
	/**< @brief Defines the endianness of the data belonging to a Routine In Signal for RequestResult
	 * 			subfunction. */
	Dcm_DspDataEndiannessType DcmDspRoutineSignalEndianness;
	/**< @brief Provide the type of the signal in the RoutineControl request/response. */
	Dcm_DspDataEnumType DcmDspRoutineSignalType;
#if(0u)
	/* TODO:2025.12.10, LY: Not supported. */
	/**< @brief This container contains the configuration (parameters) of an alternative Diagnosis
	 * 			Representation by the means of a ArgumentDataPrototype. */
	P2CONST(Dcm_DspAlternativeArgumentDataType, AUTOMATIC, DCM_CONST)DcmDspAlternativeArgumentData;
	/**< @brief This container contains the configuration (parameters) of an alternative Diagnosis
	 * 			Representation by the means of an ApplicationDataType. */
	P2CONST(Dcm_DspAlternativeDataType, AUTOMATIC, DCM_CONST)DcmDspAlternativeDataType;
	/**< @brief This container contains the configuration (parameters) of an alternative Diagnosis
	 * 			Representation by the means of Diagnostic Extract. */
	P2CONST(Dcm_DspAlternativeDiagnosticDataElementType, AUTOMATIC, DCM_CONST)DcmDspAlternativeDiagnosticDataElement;
#endif /* #if(0u) */
}Dcm_DspRoutineSignalType;

#if(STD_ON == DCM_DSP_ROUTINE_REQUEST_RESULTS_ENABLED)
/**
 * @brief	Provides the configuration of RequestResult subservice for RoutineControl service.
 */
typedef struct
{
#if(0u != DCM_DSP_REQUEST_ROUTINE_RESULTS_OUT_SIGNAL_NUM)
	/**< @brief Request routine results out-signals number. */
	uint8 DcmDspRequestRoutineResultsOutSignalNum;
#endif /* #if(0u != DCM_DSP_REQUEST_ROUTINE_RESULTS_OUT_SIGNAL_NUM) */
	/**< @brief Function name for request to application the results of a routine.
	 * 			(Routine_RequestResults-function). */
	Dcm_DspRequestRoutineResultsFncType DcmDspRequestRoutineResultsFnc;
#if(0u != DCM_DSP_COMMON_AUTHORIZATION_NUM)
	/**< @brief Reference to DcmDspCommonAuthorization. */
	P2CONST(Dcm_DspCommonAuthorizationType, AUTOMATIC, DCM_CONST)DcmDspRequestRoutineResultsCommonAuthorizationRef;
#endif /* #if(0u != DCM_DSP_COMMON_AUTHORIZATION_NUM) */
#if(0u != DCM_DSP_REQUEST_ROUTINE_RESULTS_OUT_SIGNAL_NUM)
	/**< @brief Provide description of output parameter of RequestResult subservice for RoutineControl
	 * 			service. */
	P2CONST(Dcm_DspRoutineSignalType, AUTOMATIC, DCM_CONST)DcmDspRequestRoutineResultsOutSignal;
#endif /* #if(0u != DCM_DSP_REQUEST_ROUTINE_RESULTS_OUT_SIGNAL_NUM) */
}Dcm_DspRequestRoutineResultsType;
#endif /* #if(STD_ON == DCM_DSP_ROUTINE_REQUEST_RESULTS_ENABLED) */

#if(STD_ON == DCM_DSP_ROUTINE_START_ENABLED)
/**
 * @brief	Provides the configuration of Start subservice for RoutineControl service.
 */
typedef struct
{
#if(0u != DCM_DSP_START_ROUTINE_IN_SIGNAL_NUM)
	/**< @brief Start routine in-signals number. */
	uint8 DcmDspStartRoutineInSignalNum;
#endif /* #if(0u != DCM_DSP_START_ROUTINE_IN_SIGNAL_NUM) */
#if(0u != DCM_DSP_START_ROUTINE_OUT_SIGNAL_NUM)
	/**< @brief Start routine out-signals number. */
	uint8 DcmDspStartRoutineOutSignalNum;
#endif /* #if(0u != DCM_DSP_START_ROUTINE_OUT_SIGNAL_NUM) */
	/**< @brief Function name for request to application to start a routine. (Routine_Start-function). */
	Dcm_DspStartRoutineFncType DcmDspStartRoutineFnc;
#if(0u != DCM_DSP_COMMON_AUTHORIZATION_NUM)
	/**< @brief Reference to DcmDspCommonAuthorization. */
	P2CONST(Dcm_DspCommonAuthorizationType, AUTOMATIC, DCM_CONST)DcmDspStartRoutineCommonAuthorizationRef;
#endif /* #if(0u != DCM_DSP_COMMON_AUTHORIZATION_NUM) */
#if(0u != DCM_DSP_START_ROUTINE_IN_SIGNAL_NUM)
	/**< @brief Provide description of input parameter of StartRoutine subservice for RoutineControl
	 * 			service. */
	P2CONST(Dcm_DspRoutineSignalType, AUTOMATIC, DCM_CONST)DcmDspStartRoutineInSignal;
#endif /* #if(0u != DCM_DSP_START_ROUTINE_IN_SIGNAL_NUM) */
#if(0u != DCM_DSP_START_ROUTINE_OUT_SIGNAL_NUM)
	/**< @brief Provide description of output parameter of StartRoutine subservice for RoutineControl
	 * 			service. */
	P2CONST(Dcm_DspRoutineSignalType, AUTOMATIC, DCM_CONST)DcmDspStartRoutineOutSignal;
#endif /* #if(0u != DCM_DSP_START_ROUTINE_OUT_SIGNAL_NUM) */
}Dcm_DspStartRoutineType;
#endif /* #if(STD_ON == DCM_DSP_ROUTINE_START_ENABLED) */

#if(STD_ON == DCM_DSP_ROUTINE_STOP_ENABLED)
/**
 * @brief	Provides the configuration of Stop subservice for RoutineControl service.
 */
typedef struct
{
#if(STD_ON == DCM_DSP_ROUTINE_CONFIRMATION_FNC_ENABLED)
#if(STD_ON == DCM_DSP_STOP_CONFIRMATION_FNC_ENABLED)
	/**< @brief Allows to enable/disable the confirmation function to indicate the transmission of a
	 * 			response to a StopRoutine request. */
	boolean DcmDspStopRoutineConfirmationEnabled;
#endif /* #if(STD_ON == DCM_DSP_STOP_CONFIRMATION_FNC_ENABLED) */
#endif /* #if(STD_ON == DCM_DSP_ROUTINE_CONFIRMATION_FNC_ENABLED) */
#if(0u != DCM_DSP_STOP_ROUTINE_IN_SIGNAL_NUM)
	/**< @brief Stop routine in-signals number. */
	uint8 DcmDspStopRoutineInSignalNum;
#endif /* #if(0u != DCM_DSP_STOP_ROUTINE_IN_SIGNAL_NUM) */
#if(0u != DCM_DSP_STOP_ROUTINE_OUT_SIGNAL_NUM)
	/**< @brief Stop routine out-signals number. */
	uint8 DcmDspStopRoutineOutSignalNum;
#endif /* #if(0u != DCM_DSP_STOP_ROUTINE_OUT_SIGNAL_NUM) */
#if(STD_ON == DCM_DSP_ROUTINE_CONFIRMATION_FNC_ENABLED)
#if(STD_ON == DCM_DSP_STOP_CONFIRMATION_FNC_ENABLED)
	/**< @brief C-function to call if a transmission confirmation is needed by the issuer
	 * 			(BSW module). */
	Dcm_DspRoutineConfirmationFncType DcmDspStopRoutineConfirmationFnc;
#endif /* #if(STD_ON == DCM_DSP_STOP_CONFIRMATION_FNC_ENABLED) */
#endif /* #if(STD_ON == DCM_DSP_ROUTINE_CONFIRMATION_FNC_ENABLED) */
	/**< @brief Function name for request to application to start a routine. (Routine_Stop-function). */
	Dcm_DspStopRoutineFncType DcmDspStopRoutineFnc;
#if(0u != DCM_DSP_COMMON_AUTHORIZATION_NUM)
	/**< @brief Reference to DcmDspCommonAuthorization. */
	P2CONST(Dcm_DspCommonAuthorizationType, AUTOMATIC, DCM_CONST)DcmDspStopRoutineCommonAuthorizationRef;
#endif /* #if(0u != DCM_DSP_COMMON_AUTHORIZATION_NUM) */
#if(0u != DCM_DSP_STOP_ROUTINE_IN_SIGNAL_NUM)
	/**< @brief Provide description of input parameter of StopRoutine subservice for RoutineControl
	 * 			service. */
	P2CONST(Dcm_DspRoutineSignalType, AUTOMATIC, DCM_CONST)DcmDspStopRoutineInSignal;
#endif /* #if(0u != DCM_DSP_STOP_ROUTINE_IN_SIGNAL_NUM) */
#if(0u != DCM_DSP_STOP_ROUTINE_OUT_SIGNAL_NUM)
	/**< @brief Provide description of output parameter of StopRoutine subservice for RoutineControl
	 * 			service. */
	P2CONST(Dcm_DspRoutineSignalType, AUTOMATIC, DCM_CONST)DcmDspStopRoutineOutSignal;
#endif /* #if(0u != DCM_DSP_STOP_ROUTINE_OUT_SIGNAL_NUM) */
}Dcm_DspStopRoutineType;
#endif /* #if(STD_ON == DCM_DSP_ROUTINE_STOP_ENABLED) */

/**
 * @brief	This container contains the configuration (parameters) for Routines.
 */
typedef struct
{
	/**< @brief Allow to activate or deactivate the usage of a Routine, for multi purpose ECUs. */
	boolean DcmDspRoutineUsed;
	/**< @brief If this parameter is set to true, the DCM uses a port requiring a PortInterface
	 * 			RoutineServices_{RoutineName}. */
	boolean DcmDspRoutineUsePort;
	/**< @brief 2 bytes Identifier of the RID. */
	uint16 DcmDspRoutineIdentifier;
#if(0u != DCM_DSP_COMMON_AUTHORIZATION_NUM)
	/**< @brief Reference to DcmDspCommonAuthorization. */
	P2CONST(Dcm_DspCommonAuthorizationType, AUTOMATIC, DCM_CONST)DcmDspCommonAuthorizationRef;
#endif /* #if(0u != DCM_DSP_COMMON_AUTHORIZATION_NUM) */
#if(STD_ON == DCM_DSP_ROUTINE_REQUEST_RESULTS_ENABLED)
	/**< @brief Provides the configuration of RequestResult subservice for RoutineControl service. */
	P2CONST(Dcm_DspRequestRoutineResultsType, AUTOMATIC, DCM_CONST)DcmDspRequestRoutineResults;
#endif /* #if(STD_ON == DCM_DSP_ROUTINE_REQUEST_RESULTS_ENABLED) */
#if(STD_ON == DCM_DSP_ROUTINE_START_ENABLED)
	/**< @brief Provides the configuration of Start subservice for RoutineControl service. */
	P2CONST(Dcm_DspStartRoutineType, AUTOMATIC, DCM_CONST)DcmDspStartRoutine;
#endif /* #if(STD_ON == DCM_DSP_ROUTINE_START_ENABLED) */
#if(STD_ON == DCM_DSP_ROUTINE_STOP_ENABLED)
	/**< @brief Provides the configuration of Stop subservice for RoutineControl service. */
	P2CONST(Dcm_DspStopRoutineType, AUTOMATIC, DCM_CONST)DcmDspStopRoutine;
#endif /* #if(STD_ON == DCM_DSP_ROUTINE_STOP_ENABLED) */
#if(0u)
	/* TODO:2025.12.10, LY: Not supported. */
	/**< @brief Manufacturer specific value reported to the tester for the record identifiers 0xE000 to
	 * 			OxE1FF. (OBD use cases). */
	uint8 DcmDspRoutineInfoByte;
	/**< @brief Reference to DcmDspRequestControl. */
	P2CONST(Dcm_DspRequestControlType, AUTOMATIC, DCM_CONST)DcmDspRoutineTidRef;
#endif /* #if(0u) */
}Dcm_DspRoutineType;
#endif /* #if(STD_ON == DCM_UDS0x31_ENABLE) */

#if(STD_ON == DCM_UDS0x27_ENABLE)
/**
 * @brief	Definition of a single Row of configuration for security level configuration (per security
 * 			level).
 */
typedef struct
{
#if(STD_ON == DCM_DSP_SECURITY_ATTEMPT_COUNTER_ENABLED)
	/**< @brief This configuration parameter controls the existence of the APIs to set / get the attempt
	 * 			counter values towards application (Xxx_SetSecurityAttemptCounter() /
	 * 			Xxx_GetSecurityAttemptCounter()). */
	boolean DcmDspSecurityAttemptCounterEnabled;
#endif /* #if(STD_ON == DCM_DSP_SECURITY_ATTEMPT_COUNTER_ENABLED) */
	/**< @brief Value of Security level. */
	uint8 DcmDspSecurityLevel;
	/**< @brief Number of failed security accesses after which the delay time is activated. */
	uint8 DcmDspSecurityNumAttDelay;
	/**< @brief Size in bytes of the AccessDataRecord used in GetSeed. */
	uint32 DcmDspSecurityADRSize;
	/**< @brief Delay time after failed security access in seconds. */
	uint32 DcmDspSecurityDelayTime;
	/**< @brief Value of the delay timer in case of 'power on' in seconds. */
	uint32 DcmDspSecurityDelayTimeOnBoot;
	/**< @brief Size of the security key (in Bytes). */
	uint32 DcmDspSecurityKeySize;
	/**< @brief Size of the security seed (in Bytes). */
	uint32 DcmDspSecuritySeedSize;
	/**< @brief Defines which kind of interface shall be used for security access. */
	Dcm_DspDataUsePortType DcmDspSecurityUsePort;
#if(STD_ON == DCM_DSP_SECURITY_ATTEMPT_COUNTER_ENABLED)
	/**< @brief Function name to request the value of an attempt counter. */
	Dcm_DspSecurityGetAttemptCounterFncType DcmDspSecurityGetAttemptCounterFnc;
	/**< @brief Function name to set the value of an attempt counter. */
	Dcm_DspSecuritySetAttemptCounterFncType DcmDspSecuritySetAttemptCounterFnc;
#endif /* #if(STD_ON == DCM_DSP_SECURITY_ATTEMPT_COUNTER_ENABLED) */
	/**< @brief Function name to request the result of a key comparison. */
	Dcm_DspSecurityCompareKeyFncType DcmDspSecurityCompareKeyFnc;
	/**< @brief Callout function name used to request a seed. */
	Dcm_DspSecurityGetSeedFncType DcmDspSecurityGetSeedFnc;
}Dcm_DspSecurityRowType;
#endif /* #if(STD_ON == DCM_UDS0x27_ENABLE) */

#if(STD_ON == DCM_UDS0x10_ENABLE)
/**
 * @brief	This container holds all parameters needed to configure a single session.
 */
typedef struct
{
	/**< @brief SubFunction value of the DiagnosticSession. */
	uint8 DcmDspSessionLevel;
	/**< @brief This is the session value for P2ServerMax in seconds (per Session). */
	uint16 DcmDspSessionP2ServerMax;
#if(STD_ON == DCM_DSP_SESSION_TIM_P2_PENDING_WINDOW)
	/**< @brief Defines the minimum elapsed time of the P2 server timer after which the DCM module is
	 * 			allowed to transmit the negative response code 0x78.. */
	uint16 DcmDspSessionP2PendingThreshold;
#endif /* #if(STD_ON == DCM_DSP_SESSION_TIM_P2_PENDING_WINDOW) */
	/**< @brief This parameter defines whether this diagnostic session allows to jump to Bootloader
	 * 			(OEM Bootloader or System Supplier Bootloader) and determines, from which unit the final
	 * 			response will be sent. */
	Dcm_DspSessionForBootType DcmDspSessionForBoot;
	/**< @brief This is the session value for P2*ServerMax in seconds (per Session). */
	uint32 DcmDspSessionP2StarServerMax;
}Dcm_DspSessionRowType;
#endif /* #if(STD_ON == DCM_UDS0x10_ENABLE) */

#if(0u != DCM_DSP_VEHINFO_NUM)
/**
 * @brief	Data Item of an InfoType; ShortName is post-fix of the port interface name.
 */
typedef struct
{
	/**< @brief Defines the order of the data item in the InfoType; values: 0..255; first data item
	 * 			having the order number 0; the next 1 and so on. */
	uint8 DcmDspVehInfoDataOrder;
	/**< @brief Callout function name for reading InfoType data item. Only required in case parameter
	 * 			'DcmDspVehInfoDataUsePort' is set to 'false' */
	Dcm_DspVehInfoDataReadFncType DcmDspVehInfoDataReadFnc;
	/**< @brief Size in bytes of the InfoType data item. */
	uint8 DcmDspVehInfoDataSize;
	/**< @brief When this parameter is set to true the DCM will access the Data using an R-Port
	 * 			requiring a PortInterface IInfotypeServices_{VehInfoData}. */
	boolean DcmDspVehInfoDataUsePort;
}Dcm_DspVehInfoDataType;

/**
 * @brief	This container contains the configuration (parameters) for one single VehicleInfoType of
 * 			service $09.
 */
typedef struct
{
	/**< @brief Indicate the Dcm, which side is responsible to fill the number of data items (NODI),
	 * 			Dcm or the provider of the InfoType data. In case the responsibility is on provider
	 * 			side, only one DcmDspVehInfoData container is allowed. */
	boolean DcmDspVehInfoNODIProvResp;
	/**< @brief Value of InfoType. */
	uint8 DcmDspVehInfoInfoType;
	/**< @brief Data Item of an InfoType; ShortName is post-fix of the port interface name. */
	P2CONST(Dcm_DspVehInfoDataType, AUTOMATIC, DCM_CONST)DcmDspVehInfoData;
}Dcm_DspVehInfoType;
#endif /* #if(0u != DCM_DSP_VEHINFO_NUM) */

/**
 * @brief	These parameters apply to Diagnostic Service Processing. There will always be one set of
 * 			these parameters per Dcm.
 */
typedef struct
{
#if(STD_ON == DCM_UDS0x14_ENABLE)
	/**< @brief This container contains the configuration for the Clear DTC service. */
	P2CONST(Dcm_DspClearDTCType, AUTOMATIC, DCM_CONST)DcmDspClearDTC;
#endif /* #if(STD_ON == DCM_UDS0x14_ENABLE) */
#if(STD_ON == DCM_UDS0x28_ENABLE)
	/**< @brief Provides the configuration of the CommunicationControl mechanism. */
	P2CONST(Dcm_DspComControlType, AUTOMATIC, DCM_CONST)DcmDspComControl;
#endif /* #if(STD_ON == DCM_UDS0x14_ENABLE) */
#if(STD_ON == DCM_UDS0x31_ENABLE)
#if(0u != DCM_DSP_COMMON_AUTHORIZATION_NUM)
	/**< @brief This container contains the configuration (parameters) for the common Authorization
	 * 			being equal for several services / sub-services. */
	P2CONST(Dcm_DspCommonAuthorizationType, AUTOMATIC, DCM_CONST)DcmDspCommonAuthorization;
#endif /* #if(0u != DCM_DSP_COMMON_AUTHORIZATION_NUM) */
#endif /* #if(STD_ON == DCM_UDS0x31_ENABLE) */
#if(STD_ON == DCM_UDS0x85_ENABLE)
	/**< @brief Provide the configuration of the ControlDTCSetting mechanism. */
	P2CONST(Dcm_DspControlDTCSettingType, AUTOMATIC, DCM_CONST)DcmDspControlDTCSetting;
#endif /* #if(STD_ON == DCM_UDS0x85_ENABLE) */
#if(0u != DCM_DSP_DATA_NUM)
	/**< @brief This container contains the configuration (parameters) of a Data belonging to a DID. */
	P2CONST(Dcm_DspDataType, AUTOMATIC, DCM_CONST)DcmDspData;
#endif /* #if(0u != DCM_DSP_DATA_NUM) */
#if(0u != DCM_DSP_DID_NUM)
	/**< @brief This container contains the configuration (parameters) of the DID. */
	P2CONST(Dcm_DspDidType, AUTOMATIC, DCM_CONST)DcmDspDid;
#endif /* #if(0u != DCM_DSP_DID_NUM) */
#if(0u != DCM_DSP_DID_INTO_NUM)
	/**< @brief This container contains the configuration (parameters) of the DID's Info. */
	P2CONST(Dcm_DspDidInfoType, AUTOMATIC, DCM_CONST)DcmDspDidInfo;
#endif /* #if(0u != DCM_DSP_DID_INTO_NUM) */
#if(0u != DCM_DSP_DID_RANGE_NUM)
	/**< @brief This container defines the DID Range. */
	P2CONST(Dcm_DspDidRangeType, AUTOMATIC, DCM_CONST)DcmDspDidRange;
#endif /* #if(0u != DCM_DPS_DID_RANGE_NUM) */
#if(0u != DCM_DSP_MEMORY_NUM)
	/**< @brief This container contains the configuration of the memory access. */
	P2CONST(Dcm_DspMemoryType, AUTOMATIC, DCM_CONST)DcmDspMemory;
#endif /* #if(0u != DCM_DSP_MEMORY_NUM) */
#if(0u != DCM_DSP_PID_NUM)
	/**< @brief This container defines the availability of a PID to the DCM. */
	P2CONST(Dcm_DspPidType, AUTOMATIC, DCM_CONST)DcmDspPid;
#endif /* #if(0u != DCM_DSP_PID_NUM) */
#if(0u != DCM_DSP_REQUEST_CONTROL_NUM)
	/**< @brief This container contains the configuration (parameters) of the "Request control of
	 * 			on-board system, test or component" service (Service $08). */
	P2CONST(Dcm_DspRequestControlType, AUTOMATIC, DCM_CONST)DcmDspRequestControl;
#endif /* #if(0u != DCM_DSP_REQUEST_CONTROL_NUM) */
#if(0u != DCM_DSP_REQUEST_FILE_TRANSFER_NUM)
	/**< @brief This container contains the configuration for RequestFileTransfer. */
	P2CONST(Dcm_DspRequestFileTransferType, AUTOMATIC, DCM_CONST)DcmDspRequestFileTransfer;
#endif /* #if(0u != DCM_DSP_REQUEST_FILE_TRANSFER_NUM) */
#if(0u != DCM_DSP_ROE_NUM)
	/**< @brief Provide the configuration of the ResponseOnEvent mechanism. */
	P2CONST(Dcm_DspRoeType, AUTOMATIC, DCM_CONST)DcmDspRoe;
#endif /* #if(0u != DCM_DSP_ROE_NUM) */
#if(STD_ON == DCM_UDS0x31_ENABLE)
	/**< @brief This container contains the configuration (parameters) for Routines. */
	P2CONST(Dcm_DspRoutineType, AUTOMATIC, DCM_CONST)DcmDspRoutine;
#endif /* #if(STD_ON == DCM_UDS0x31_ENABLE) */
#if(STD_ON == DCM_UDS0x27_ENABLE)
	/**< @brief This container contains the configuration ( DSP parameter) for security level
	 * 			configuration (per security level) Description This container contains Rows of
	 * 			DcmDspSecurityRow. */
	P2CONST(Dcm_DspSecurityRowType, AUTOMATIC, DCM_CONST)DcmDspSecurityRow;
#endif /* #if(STD_ON == DCM_UDS0x27_ENABLE) */
#if(STD_ON == DCM_UDS0x10_ENABLE)
	/**< @brief Parent container holding single rows to configure particular sessions. */
	P2CONST(Dcm_DspSessionRowType, AUTOMATIC, DCM_CONST)DcmDspSessionRow;
#endif /* #if(STD_ON == DCM_UDS0x10_ENABLE) */
#if(0u != DCM_DSP_VEHINFO_NUM)
	/**< @brief This container contains the configuration (parameters) for one single VehicleInfoType
	 * 			of service $09. */
	P2CONST(Dcm_DspVehInfoType, AUTOMATIC, DCM_CONST)DcmDspVehInfo;
#endif /* #if(0u != DCM_DSP_VEHINFO_NUM) */
}Dcm_DspType;

#if(STD_ON == DCM_PROCESSING_CONDITIONS_ENABLED)
/**
 * @brief	This container contains the configuration of a array element compare value.
 */
typedef struct
{
	/**< @brief Index to an element of the compare value array. */
	uint64 DcmSwcDataElementArrayElementIndex;
	/**< @brief Value of an array element compare value. */
	uint64 DcmSwcDataElementArrayElementValue;
}Dcm_SwcDataElementArrayElementType;

/**
 * @brief	This container contains the configuration of a primitive compare value.
 */
typedef struct
{
	/**< @brief Primitive compare value. */
	uint64 DcmSwcDataElementPrimitiveValue;
}Dcm_SwcDataElementPrimitiveType;

/**
 * @brief	This container contains the configuration of a mode condition or an environmental conditions
 * 			which can be used as argument in DcmModeRules.
 */
typedef struct
{
	/**< @brief This parameter references a mode of a ModeDeclarationGroupPrototype provided by a Basic
	 * 			Software Module used for the condition. */
	uint8 DcmBswModeRef;
	/**< @brief Reference to a certificate data element that provides the compare value. */
	uint8 DcmModeConditionCertificateCompareElementRef;
	/**< @brief This parameter references a mode in a particular mode request port of a software
	 * 			component that is used for the condition. */
	uint8 DcmSwcModeRef;
	/**< @brief Reference to environmental conditions. It is possible to reference a S/R Receiver-Port
	 * 			to read physical values and compare (equal, greater, less,...) them with a configured
	 * 			value that is defined by DcmSwcDataElementValue. */
	uint8 DcmSwcSRDataElementRef;
	/**< @brief This parameter specifies what kind of comparison that is made for the evaluation of the
	 * 			mode condition. */
	Dcm_ConditionType DcmConditionType;
	/**< @brief This container contains the configuration of a array element compare value. */
	P2CONST(Dcm_SwcDataElementArrayElementType, AUTOMATIC, DCM_CONST)DcmSwcDataElementArrayElement;
	/**< @brief This container contains the configuration of a primitive compare value. */
	P2CONST(Dcm_SwcDataElementPrimitiveType, AUTOMATIC, DCM_CONST)DcmSwcDataElementPrimitive;
}Dcm_ModeConditionType;

/**
 * @brief	This container contains the configuration of a mode rule which represents a logical
 * 			expression with DcmModeConditions or other DcmModeRules as arguments.
 */
typedef struct
{
	/**< @brief Optional parameter which defines the NRC to be sent in case the mode rule condition is
	 * 			not valid. */
	uint8 DcmModeRuleNrcValue;
	/**< @brief This is a choice reference either to a mode condition or a an other mode rule serving as
	 * 			sub-expression. */
	uint8 DcmArgumentRef;
	/**< @brief This parameter specifies the logical operator to be used in the logical expression. If
	 * 			the expression only consists of a single condition this parameter shall not be used. */
	Dcm_LogicalOperatorType DcmLogicalOperator;
}Dcm_ModeRuleType;

/**
 * @brief	This container contains the configuration for mode arbitration functionality of the Dcm.
 */
typedef struct
{
	/**< @brief This container contains the configuration of a mode condition or an environmental
	 * 			conditions which can be used as argument in DcmModeRules. */
	P2CONST(Dcm_ModeConditionType, AUTOMATIC, DCM_CONST)Dcm_ModeCondition;
	/**< @brief This container contains the configuration of a mode rule which represents a logical
	 * 			expression with DcmModeConditions or other DcmModeRules as arguments. */
	P2CONST(Dcm_ModeRuleType, AUTOMATIC, DCM_CONST)Dcm_ModeRule;
}Dcm_ProcessingConditionsType;
#endif /* #if(STD_ON == DCM_PROCESSING_CONDITIONS_ENABLED) */

/* @req [SWS_Dcm_00982] */
/**
 * @brief	This type defines a data structure for the post build parameters of the DCM. At
 * 			initialization the DCM gets a pointer to a structure of this type to get access to its
 * 			configuration data, which is necessary for initialization.
 */
typedef struct
{
	/**< @brief These parameters configure the Diagnostic Service Dispatcher submodule. */
	P2CONST(Dcm_DsdType, AUTOMATIC, DCM_CONST)DcmDsd;
	/**< @brief These parameters configure the Diagnostic Session Layer submodule. */
	P2CONST(Dcm_DslType, AUTOMATIC, DCM_CONST)DcmDsl;
	/**< @brief These parameters apply to Diagnostic Service Processing. */
	P2CONST(Dcm_DspType, AUTOMATIC, DCM_CONST)DcmDsp;
	/**< @brief This container contains the configuration for a main connection of a diagnostic
	 * 			protocol. */
#if(0u != DCM_DSL_MAIN_CONNECTION_NUM)
	P2CONST(Dcm_DslMainConnectionType, AUTOMATIC, DCM_CONST)DcmDslMainConnection;
#endif /* #if(0u != DCM_DSL_MAIN_CONNECTION_NUM) */
	/**< @brief This container contains the configuration parameters of a reception channel in a
	 * 			diagnostic connection. */
	P2CONST(Dcm_DslProtocolRxType, AUTOMATIC, DCM_CONST)DcmDslProtocolRx;
	/**< @brief This container contains the configuration parameters of a transmission channel in a
	 * 			diagnostic connection. */
#if(0u != DCM_DSL_PROTOCOL_TX_NUM)
	P2CONST(Dcm_DslProtocolTxType, AUTOMATIC, DCM_CONST)DcmDslProtocolTx;
#endif /* #if(0u != DCM_DSL_PROTOCOL_TX_NUM) */
#if(STD_ON == DCM_PROCESSING_CONDITIONS_ENABLED)
	/**< @brief This container contains the configuration for mode arbitration functionality of Dcm. */
	P2CONST(Dcm_ProcessingConditionsType, AUTOMATIC, DCM_CONST)DcmProcessingConditions;
#endif /* #if(STD_ON == DCM_PROCESSING_CONDITIONS_ENABLED) */
#if(0u != DCM_DSP_DATA_BLOCK_USED_NUM)
	/**< @brief Pointer to the DcmDspDataReadBlock. */
	P2VAR(Dcm_DspDataReadBlockType, AUTOMATIC, DCM_CONST)DcmDspDataReadBlock;
#endif /* #if(0u != DCM_DSP_DATA_BLOCK_USED_NUM) */
}Dcm_ConfigType;
/*====================================================================================================*
 *                                    GLOBAL VARIABLE DECLARATIONS
 *====================================================================================================*/

/*====================================================================================================*
 *                                        FUNCTION PROTOTYPES
 *====================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* DCM_TYPES_H */
/** @} */
