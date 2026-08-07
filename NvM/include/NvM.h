/**
 * @file        NvM.h
 * @brief       AUTOSAR NvM - NvM driver header file.
 * @details     NvM driver header file, containing the Autosar API specification and
 *               other variables and functions that are exported by the NvM driver.
 * @version     1.2.0
 * @addtogroup  NvM
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

#ifndef NVM_H
#define NVM_H

#ifdef __cplusplus
extern "C"{
#endif

/*====================================================================================================*
 *                                           INCLUDE FILES                                          
 *====================================================================================================*/
#include "NvM_Cfg.h"
#include "NvM_Types.h"

/*====================================================================================================*
 *                                  SOURCE FILE VERSION INFORMATION                                 
 *====================================================================================================*/
#define NVM_VENDOR_ID                      0U
#define NVM_MODULE_ID					   20U
#define NVM_AR_RELEASE_MAJOR_VERSION       4U
#define NVM_AR_RELEASE_MINOR_VERSION       2U
#define NVM_AR_RELEASE_REVISION_VERSION    2U
#define NVM_SW_MAJOR_VERSION               1U
#define NVM_SW_MINOR_VERSION               2U
#define NVM_SW_PATCH_VERSION               0U

/*====================================================================================================*
 *                                         FILE VERSION CHECKS                                      
 *====================================================================================================*/
/* Check if current file and NvM_Cfg.h header file are of the same vendor */
#if(NVM_VENDOR_ID != NVM_CFG_VENDOR_ID )
#error "NvM.h and NvM_Cfg.h have different vendor id"
#endif

/* Check if current file and NvM_Cfg.h header file are of the same Autosar version */
#if(\
		(NVM_AR_RELEASE_MAJOR_VERSION != NVM_CFG_AR_RELEASE_MAJOR_VERSION) || \
		(NVM_AR_RELEASE_MINOR_VERSION != NVM_CFG_AR_RELEASE_MINOR_VERSION) || \
		(NVM_AR_RELEASE_REVISION_VERSION != NVM_CFG_AR_RELEASE_REVISION_VERSION) \
		)
#error "AutoSar Version Number of NvM.h and NvM_Cfg.h are different "
#endif

/* Check if current file and NvM_Cfg.h header file are of the same software version */
#if(\
		(NVM_SW_MAJOR_VERSION != NVM_CFG_SW_MAJOR_VERSION) || \
		(NVM_SW_MINOR_VERSION != NVM_CFG_SW_MINOR_VERSION) || \
		(NVM_SW_PATCH_VERSION != NVM_CFG_SW_PATCH_VERSION) \
		)
#error "Software Version Number of NvM.h and NvM_Cfg.h are different "
#endif

/* Check if current file and NvM_Types.h header file are of the same vendor */
#if(NVM_VENDOR_ID != NVM_TYPES_VENDOR_ID )
#error "NvM.h and NvM_Types.h have different vendor id"
#endif

/* Check if current file and NvM_Types.h header file are of the same Autosar version */
#if(\
		(NVM_AR_RELEASE_MAJOR_VERSION != NVM_TYPES_AR_RELEASE_MAJOR_VERSION) || \
		(NVM_AR_RELEASE_MINOR_VERSION != NVM_TYPES_AR_RELEASE_MINOR_VERSION) || \
		(NVM_AR_RELEASE_REVISION_VERSION != NVM_TYPES_AR_RELEASE_REVISION_VERSION) \
		)
#error "AutoSar Version Number of NvM.h and NvM_Types.h are different "
#endif

/* Check if current file and NvM_Types.h header file are of the same software version */
#if(\
		(NVM_SW_MAJOR_VERSION != NVM_TYPES_SW_MAJOR_VERSION) || \
		(NVM_SW_MINOR_VERSION != NVM_TYPES_SW_MINOR_VERSION) || \
		(NVM_SW_PATCH_VERSION != NVM_TYPES_SW_PATCH_VERSION) \
		)
#error "Software Version Number of NvM.h and NvM_Types.h are different "
#endif

/*====================================================================================================*
 *                                             CONSTANTS                                            
 *====================================================================================================*/

/* Add code here */

/*====================================================================================================*
 *                                         DEFINES AND MACROS                                       
 *====================================================================================================*/
/**
 * @brief The passed BlockID is out of range
 */
#define NVM_E_PARAM_BLOCK_ID	(0x0AU)
/**
 * @brief The passed Block type is error
 */
#define NVM_E_PARAM_BLOCK_TYPE	(0x0BU)
/**
 * @brief  DataIndex parameter exceeds the total number of configured datasets
 */
#define NVM_E_PARAM_BLOCK_DATA_IDX	(0x0CU)
/**
 * @brief  No permanent RAM block and no explicit syncronization is configured
 *         and a NULL pointer is passed via the parameter NvM_DstPtr
 */
#define NVM_E_PARAM_ADDRESS	(0x0DU)
/**
 * @brief  NULL pointer is passed via the parameter RequestResultPtr.
 */
#define NVM_E_PARAM_DATA	(0x0EU)
/**
 * @brief  NULL pointer is passed via the parameter versionInfo
 */
#define NVM_E_PARAM_POINTER	(0x0FU)
/**
 * @brief The block has no default data
 */
#define NVM_E_BLOCK_WITHOUT_DEFAULTS	(0x11U)
/**
 * @brief  NVM is not yet initialized
 */
#define NVM_E_NOT_INITIALIZED	(0x14U)
/**
 * @brief NVRAM block identifier is already queued or currently in progress
 */
#define NVM_E_BLOCK_PENDING	(0x15U)
/**
 * @brief Default data is not available/configured for the referenced NVRAM block
 */
#define NVM_E_BLOCK_CONFIG	(0x18U)
/**
 * @brief The block is locked
 */
#define NVM_E_BLOCK_LOCKED	(0x19U)

/**
 * @brief service ID of function: NvM_Init
 */
#define NVM_SID_INIT                            (0x00U)
/**
 * @brief service ID of function: NvM_SetDataIndex
 */
#define NVM_SID_SETDATAINDEX                    (0x01U)
/**
 * @brief service ID of function: NvM_GetDataIndex
 */
#define NVM_SID_GETDATAINDEX                    (0x02U)
/**
 * @brief service ID of function: NvM_SetBlockProtection
 */
#define NVM_SID_SETBLOCKPROTECTION              (0x03U)
/**
 * @brief service ID of function: NvM_GetErrorStatus
 */
#define NVM_SID_GETERRORSTATUS                  (0x04U)
/**
 * @brief service ID of function: NvM_SetRamBlockStatus
 */
#define NVM_SID_SETRAMBLOCKSTATUS               (0x05U)
/**
 * @brief service ID of function: NvM_ReadBlock
 */
#define NVM_SID_READBLOCK                       (0x06U)
/**
 * @brief service ID of function: NvM_WriteBlock
 */
#define NVM_SID_WRITEBLOCK                      (0x07U)
/**
 * @brief service ID of function: NvM_RestoreBlockDefaults
 */
#define NVM_SID_RESTOREBLOCKDEFAULTS            (0x08U)
/**
 * @brief service ID of function: NvM_EraseNvBlock
 */
#define NVM_SID_ERASENVBLOCK                    (0x09U)
/**
 * @brief service ID of function: NvM_CancelJobs
 */
#define NVM_SID_CANCELJOBS                      (0X10U)
/**
 * @brief service ID of function: NvM_SetBlockLockStatus
 */
#define NVM_SID_SETBLOCKLOCKSTATUS              (0x13U)
/**
 * @brief service ID of function: NvM_CancelWriteAll
 */
#define NVM_SID_CANCELWRITEALL                  (0x0AU)
/**
 * @brief service ID of function: NvM_InvalidateNvBlock
 */
#define NVM_SID_INVALIDATENVBLOCK                 (0x0BU)
/**
 * @brief service ID of function: NvM_ReadAll
 */
#define NVM_SID_READALL                         (0x0CU)
/**
 * @brief service ID of function: NvM_WriteAll
 */
#define NVM_SID_WRITEALL                        (0x0DU)
/**
 * @brief service ID of function: NvM_MainFunction
 */
#define NVM_SID_MAINFUNCTION                    (0x0EU)
/**
 * @brief service ID of function: NvM_ValidateAll
 */
#define NVM_SID_VALIDATEALL                     (0x19U)
/**
 * @brief service ID of function: NvM_GetVersionInfo
 */
#define NVM_SID_GETVERSIONINFO                  (0x0FU)
/**
 * @brief service ID of function: NvM_ReadPRAMBlock
 */
#define NVM_SID_READPRAMBLOCK                   (0x16U)
/**
 * @brief service ID of function: NvM_WritePRAMBlock
 */
#define NVM_SID_WRITEPRAMBLOCK                  (0x17U)
/**
 * @brief service ID of function: NvM_RestorePRAMBlockDefaults
 */
#define NVM_SID_RESTOREPRAMBLOCKDEFAULTS        (0x18U)

#define NVM_INVALID_DATA						(0xFFU)

#define NVM_INVALID_CRC							(0xFFFFFFFFU)

/*====================================================================================================*
 *                                               ENUMS                                              
 *====================================================================================================*/
/**
 * @brief The types of storage supported by NVRAM
 */
typedef enum
{
	/**< @brief NVM_BLOCK_NATIVE type of NVRAM storage - NV Blocks: 1 - RAM Blocks: 1
	 * - ROM Blocks: 0..1 - Administrative Blocks: 1 */
	NVM_BLOCK_NATIVE = 0U,
	/**< @brief NVM_BLOCK_REDUNDANT type of NVRAM storage - NV Blocks: 2 - RAM Blocks: 1
	 * - ROM Blocks: 0..1 - Administrative Blocks: 1 */
	NVM_BLOCK_REDUNDANT,
	/**< @brief NVM_BLOCK_DATASET type of NVRAM storage - NV Blocks: 1..m(m<256) - RAM Blocks: 1
	 * - ROM Blocks: 0..n - Administrative Blocks: 1 */
	NVM_BLOCK_DATASET
}NvM_BlockManagementType;

/**
 * @brief Defines CRC data width for the NVRAM block
 */
typedef enum
{
	/**< @brief Block do not use CRC */
	NVM_CRC_NOT_USED = 0U,
	/**< @brief Block use a CRC type of uint8 - 1 byte */
	NVM_CRC8 = 1U,
	/**< @brief Block use a CRC type of uint16 - 2 byte */
	NVM_CRC16 = 2U,
	/**< @brief Block use a CRC type of uint32 - 4 byte */
	NVM_CRC32 = 4U
}NvM_BlockCrcType;

/*====================================================================================================*
 *                                   STRUCTURES AND OTHER TYPEDEFS                                  
 *====================================================================================================*/
/**
 * @brief Pointer type of the callback function at the end of a single job
 */
typedef P2FUNC(Std_ReturnType, NVM_APPL_CODE, NvM_SingleBlockCallbackType) \
		(uint8 ServiceId, NvM_RequestResultType JobResult);

#if (NVM_MULTI_BLOCK_CALLBACK == STD_ON)
/**
 * @brief Pointer type of the callback function at the end of a multi job
 */
typedef P2FUNC(void, NVM_APPL_CODE, NvM_MultiBlockCallbackType) \
		(uint8 ServiceId, NvM_RequestResultType JobResult);
#endif /* NVM_MULTI_BLOCK_CALLBACK == STD_ON */

/**
 * @brief Pointer type of the callback function at the end of a restore the default value job
 */
typedef P2FUNC(Std_ReturnType, NVM_APPL_CODE, NvM_InitBlockCallbackType)(void);

/**
 * @brief The type of callback function pointer that copies data from a mirrored block to a
 * 		  RAM block
 */
typedef P2FUNC(Std_ReturnType, NVM_APPL_CODE, NvM_ReadRamBlockFromNvCallbackType) \
		(const void* NvMBuffer);

/**
 * @brief The type of callback function pointer that writes data from a RAM block to a mirrored block
 */
typedef P2FUNC(Std_ReturnType, NVM_APPL_CODE, NvM_WriteRamBlockToNvCallbackType)(void* NvMBuffer);

typedef struct
{
	/**< @brief NVRAM block CRC type/length */
	const NvM_BlockCrcType NvM_CrcTypeOfBlock;
	/**< @brief NVRAM block job priority */
	const uint8 NvM_BlockJobPriority;
	/**< @brief NVRAM block management type */
	const NvM_BlockManagementType NvM_ManagementTypeofBlock;
	/**< @brief Defines whether the RAM block shall be auto validated during shutdown phase */
	const boolean NvM_BlockUseAutoValidation;
	/**< @brief Defines whether the CRC of the RAM block shall be compared during a write job with the
	 * CRC which was calculated during the last successful read or write job */
	const boolean NvM_BlockUseCRCCompMechanism;
	/**< @brief Defines CRC usage for the NVRAM block, i.e. memory space for CRC is reserved in RAM
	 * and NV memory */
	const boolean NvM_BlockUseCrc;
	/**< @brief Defines if NvMSetRamBlockStatusApi shall be used for this block or not */
	const boolean NvM_BlockUseSetRamBlockStatus;
	/**< @brief Defines whether the NVRAM block uses the display synchronization mechanism */
	const boolean NvM_BlockUseSyncMechanism;
	/**< @brief Defines an initial write protection of the NV block */
	const boolean NvM_BlockWriteProt;
	/**< @brief This parameter specifies whether BswM is informed about the current status
	 * of the specified block */
	const boolean NvM_BswMBlockStatusInformation;
	/**< @brief Defines CRC (re)calculation for the permanent RAM block or NVRAM blocks which are
	 * configured to use explicit synchronization mechanism. */
	const boolean NvM_CalcRamBlockCrc;
	/**< @brief Entry address of a block specific callback routine which shall be called if no
	 * ROM data is available for initialization of the NVRAM block. */
	NvM_InitBlockCallbackType NvM_InitBlockCallback;
	/**< @brief Defines the maximum number of read retries. */
	const uint8 NvM_MaxNumOfReadRetries;
	/**< @brief Defines the maximum number of write retries. */
	const uint8 NvM_MaxNumOfWriteRetries;
	/**< @brief The block base number used to link the underlying Fee/Ea*/
	const uint16 NvM_NvBlockBaseNumber;
	/**< @brief Defines the Nv block data length in bytes */
	const uint16 NvM_NvBlockLength;
	/**< @brief Defines the number of multiple Nv blocks in a contiguous area according to the
	 * the given block management type */
	const uint8 NvM_NvBlockNum;
	/**< @brief Identification of a NVRAM block via a unique block identifier */
	const NvM_BlockIdType NvM_NvramBlockIdentifier;
	/**< @brief Defines the NVRAM device ID where the NVRAM block is located */
	const uint8 NvM_NvramDeviceId;
	/**< @brief Defines the start address of the RAM block data. */
	uint8* const NvM_RamBlockDataAddress;
	/**< @brief Entry address of a block specific callback routine which shall be called in order to
	 * let the application copy data from the NvM module's mirror to RAM block */
	NvM_ReadRamBlockFromNvCallbackType NvM_ReadRamBlockFromNvCallback;
	/**< @brief Defines whrther a NVRAM block shall be treated resistant to configuration
	 * changes or not. */
	const boolean NvM_ResistantToChangedSw;
	/**< @brief Defines the start address of the ROM block data. */
	const uint8* NvM_RomBlockDataAddress;
	/**< @brief Defines the number of multiple ROM blocks in a contiguous area according to the
	 * given block management type */
	const uint8 NvM_RomBlockNum;
	/**< @brief Defines whether a NVRAM block shall be processed during NvM_ReadAll or not. */
	const boolean NvM_SelectBlockForReadAll;
	/**< @brief Defines whether a NVRAM block shall be processed during NvM_WriteAll or not. */
	const boolean NvM_SelectBlockForWriteAll;
	/**< @brief Entry address of the block specific callback routine which shall be invoked
	 * on termination of each asynchronous single block request [NVM113] */
	NvM_SingleBlockCallbackType NvM_SingleBlockCallback;
	/**< Defines if the Static block ID check is enabled */
	const boolean NvM_StaticBlockIDCheck;
	/**< Defines write protection after first write */
	const boolean NvM_WriteBlockOnce;
	/**< Entry address of a block specific callback routine which shall be called in order
	 * to let the application copy data from RAM block to NvM module's mirror */
	NvM_WriteRamBlockToNvCallbackType NvM_WriteRamBlockToNvCallback;
	/**< Defines if write verification is enabled */
	const boolean NvM_WriteVerification;
	/**< Defines the number of bytes to compare in each step when comparing the content of a
	 * RAM block and a block read block */
	const uint16 NvM_WriteVerificationDataSize;
	/**< The underlying Ea/Fee block address */
	const uint16 NvM_EaOrFeeRef;
}NvM_BlockDescriptorType;

/**
 * @brief Since this type is used for compliance purposes only (meaning that NvM_Init will now
 * 		  have a pointer to this type as parameter, based on SWS_BSW_00047) it will be left
 * 		  to the developer to chose how to implement it, considering it has no use for the NvM
 * 		  module in any way.
 * @req [SWS_NvM_00880]
 */
typedef struct
{
#if (NVM_MULTI_BLOCK_CALLBACK == STD_ON)
	/**< @brief Common callback routine to notify the upper layer that an asynchronous multi
	 * block request has been finished */
	NvM_MultiBlockCallbackType NvM_MultiBlockCallback;
#endif /* NVM_MULTI_BLOCK_CALLBACK == STD_ON */
	/**< @brief Defines whether dynamic configuration processing is enabled */
	const boolean NvM_DynamicConfiguration;
	/**< @brief The definition allows the memory driver to be switched to fast mode when performing
	 * NvM_ReadAll and NvM_WriteAll */
	const boolean NvM_DrvModeSwitch;
	/**< @brief Configuration ID regarding the NV memory layout. This configuration ID shall be
	 * published as e.g. a SW-C shall have the possibility to write it to NV memory */
	const uint8* NvM_ConfigurationID;
	/**< @brief NVRAM block management information */
	const NvM_BlockDescriptorType* NvM_BlockDescriptor;
}NvM_ConfigType;

/*====================================================================================================*
 *                                    GLOBAL VARIABLE DECLARATIONS                                  
 *====================================================================================================*/
/* Obtain the NvM module configuration */
NVM_CONF_PB

/*====================================================================================================*
 *                                        FUNCTION PROTOTYPES                                       
 *====================================================================================================*/
#define NVM_START_SEC_CODE
#include "NvM_MemMap.h"
#if (\
	NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_1 || \
	NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_2 || \
	NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3 \
	)

FUNC(void, NVM_CODE) NvM_Init(P2CONST(NvM_ConfigType, AUTOMATIC, NVM_APPL_CONST) ConfigPtr);
FUNC(void, NVM_CODE) NvM_WriteAll(void);
FUNC(void, NVM_CODE) NvM_ReadAll(void);
FUNC(void, NVM_CODE) NvM_CancelWriteAll(void);
FUNC(Std_ReturnType, NVM_CODE) NvM_GetErrorStatus
(
	VAR(NvM_BlockIdType, AUTOMATIC) BlockId,
	P2VAR(NvM_RequestResultType, AUTOMATIC, NVM_APPL_VAR) RequestResultPtr
);

FUNC(Std_ReturnType, NVM_CODE) NvM_SetRamBlockStatus
(
	VAR(NvM_BlockIdType, AUTOMATIC) BlockId,
	VAR(boolean, AUTOMATIC) BlockChanged
);

FUNC(void, NVM_CODE) NvM_SetBlockLockStatus
(
	VAR(NvM_BlockIdType, AUTOMATIC) BlockId,
	VAR(boolean, AUTOMATIC) BlockLocked
);

#endif /* NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_1 || \
		NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_2 || \
		NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3 \ */

#if (\
	NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_2 || \
	NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3 \
	)

FUNC(void, NVM_CODE) NvM_ValidateAll(void);
FUNC(Std_ReturnType, NVM_CODE) NvM_WriteBlock
(
	VAR(NvM_BlockIdType, AUTOMATIC) BlockId,
	P2CONST(void, AUTOMATIC, NVM_APPL_CONST) NvM_SrcPtr
);
FUNC(Std_ReturnType, NVM_CODE) NvM_ReadBlock
(
	VAR(NvM_BlockIdType, AUTOMATIC) BlockId,
	P2VAR(void, AUTOMATIC, NVM_APPL_VAR) NvM_DstPtr
);
FUNC(Std_ReturnType, NVM_CODE) NvM_RestoreBlockDefaults
(
	VAR(NvM_BlockIdType, AUTOMATIC) BlockId,
	P2VAR(void, AUTOMATIC, NVM_APPL_VAR) NvM_DestPtr
);
FUNC(Std_ReturnType, NVM_CODE) NvM_CancelJobs(VAR(NvM_BlockIdType, AUTOMATIC) BlockId);
FUNC(Std_ReturnType, NVM_CODE) NvM_WritePRAMBlock(VAR(NvM_BlockIdType, AUTOMATIC) BlockId);
FUNC(Std_ReturnType, NVM_CODE) NvM_ReadPRAMBlock(VAR(NvM_BlockIdType, AUTOMATIC) BlockId);
FUNC(Std_ReturnType, NVM_CODE) NvM_RestorePRAMBlockDefaults(VAR(NvM_BlockIdType, AUTOMATIC) BlockId);
FUNC(Std_ReturnType, NVM_CODE) NvM_SetDataIndex
(
	VAR(NvM_BlockIdType, AUTOMATIC) BlockId,
	VAR(uint8, AUTOMATIC) DataIndex
);
FUNC(Std_ReturnType, NVM_CODE) NvM_GetDataIndex
(
	VAR(NvM_BlockIdType, AUTOMATIC) BlockId,
	P2VAR(uint8, AUTOMATIC, NVM_APPL_VAR) DataIndexPtr
);

#endif /* NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_2 || \
		NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3 \ */

#if (NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3)

FUNC(Std_ReturnType, NVM_CODE) NvM_SetBlockProtection
(
	VAR(NvM_BlockIdType, AUTOMATIC) BlockId,
	VAR(boolean, AUTOMATIC) ProtectionEnabled
);
FUNC(Std_ReturnType, NVM_CODE) NvM_EraseNvBlock(VAR(NvM_BlockIdType, AUTOMATIC) BlockId);
FUNC(Std_ReturnType, NVM_CODE) NvM_InvalidateNvBlock(VAR(NvM_BlockIdType, AUTOMATIC) BlockId);

#endif /* NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3 */

FUNC(void, NVM_CODE) NvM_MainFunction(void);

#if (STD_ON == NVM_VERSION_INFO_API)
FUNC(void, NVM_CODE) NvM_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, NVM_APPL_VAR) versionInfo);
#endif /*(STD_ON == NVM_VERSION_INFO_API)*/

#ifdef AH_TEST_NVM
FUNC(void, NVM_CODE) NvM_DeInit();
#endif

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* NVM_H */
/** @} */
