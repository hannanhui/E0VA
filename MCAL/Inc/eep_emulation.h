/***************************************************************************//**
 * @file     eep_emulation.h
 * @brief    EEPROM emulation header file.
 * @version  V1.3
 * @date     May-2021
 * @author   Zhixin Semiconductor
 *
 * @note
 * Copyright (C) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved..
 * 
 ******************************************************************************/
#ifndef EEP_EMULATION_H
#define EEP_EMULATION_H

#include "ee_config.h"

#if (defined(DEV_Z20K148M)) || (defined(DEV_Z20K146M))||(defined(DEV_Z20K144M))
#include "common_drv.h"
#else
#include "Z20K11xM_drv.h"
#endif



/* Return code definition */
#define EE_OK                                       0x00000000U
#define EE_ERROR_BUSY                               0x00000001U
#define EE_ERROR_DATA_NOT_FOUND                     0x00000002U
#define EE_ERROR_NOT_IN_CACHE                       0x00000004U
#define EE_ERROR_ECC                                0x00000008U
#define EE_ERROR_INPUT_PARA                         0x00000010U
#define EE_ERROR_NO_ENOUGH_SPACE                    0x00000020U
#define EE_ERROR_FLASH_ERR                          0x00000040U
#define EE_ERROR_CACHE_ITEM                         0x00000080U
#define EE_ERROR_SWAP                               0x00000100U
#define EE_ERROR_NOT_ENOUGH_SECTORS                 0x00000200U
#define EE_ERROR_HEADER_INVALID                     0x00000400U
#define EE_ERROR_WRITTEN_LOC_NOT_EMPTY              0x00000800U
#define EE_ERROR_REC_ID_OUT_OF_RANGE                0x00001000U
#define EE_ERROR_READ_REC_DATA_ECC                  0x00002000U
#define EE_ERROR_READ_ECC                           0x00004000U
#define EE_ERROR_WRITTEN_VALUE                      0x00008000U

#define FLASH_MODULE      Z20K1XX

#if (FLASH_MODULE == Z20K1XX)
#define EE_FL_SECTOR_SIZE   8192U
#define EE_FL_PHRASE_SIZE   16U
#define EE_ECC_SIZE            EE_FL_PHRASE_SIZE
#endif


#define EE_SECTOR_ID_OFFSET         0U
#define EE_SECTOR_ADDR_OFFSET       4U
#define EE_SECTOR_SIZE_OFFSET       8U
#define EE_SECTOR_CHECKSUM_OFFSET   12U
#define EE_SECTOR_VALID_OFFSET      EE_FL_PHRASE_SIZE
#define EE_SECTOR_INVALID_OFFSET    (EE_SECTOR_VALID_OFFSET + EE_FL_PHRASE_SIZE)
#define EE_SECTOR_RECORD_OFFSET     (EE_FL_PHRASE_SIZE * 3U)
#define EE_SECTOR_INFO_LEN           EE_FL_PHRASE_SIZE
#define EE_SECTOR_VALID_LEN          EE_FL_PHRASE_SIZE
#define EE_SECTOR_INVALID_LEN        EE_FL_PHRASE_SIZE
#define EE_SECTOR_HEADER_LEN         (EE_SECTOR_INFO_LEN + EE_SECTOR_VALID_LEN + EE_SECTOR_INVALID_LEN)


#define EE_RECORD_ID_OFFSET          0U
#define EE_RECORD_SIZE_OFFSET        2U
#define EE_RECORD_ADDR_OFFSET        4U
#define EE_RECORD_CHECKSUM_OFFSET    8U
#define EE_RECORD_VALID_OFFSET       EE_FL_PHRASE_SIZE
#define EE_RECORD_INVALID_OFFSET     (EE_RECORD_VALID_OFFSET + EE_FL_PHRASE_SIZE)
#define EE_RECORD_ID_LEN             2U
#define EE_RECORD_SIZE_LEN           2U
#define EE_RECORD_ADDR_LEN           4U
#define EE_RECORD_CHECKSUM_LEN       4U
#define EE_RECORD_INFO_LEN           EE_FL_PHRASE_SIZE
#define EE_RECORD_VALID_LEN          EE_FL_PHRASE_SIZE
#define EE_RECORD_INVALID_LEN        EE_FL_PHRASE_SIZE
#define EE_RECORD_HEADER_LEN         (EE_RECORD_INFO_LEN + EE_RECORD_VALID_LEN + EE_RECORD_INVALID_LEN)


/* Macros for CallBack period controlling */
#define EE_CALLBACK_READ_BYTES_NUM               0x0020U
#define EE_CALLBACK_SEARCH_BYTES_NUM             0x0020U
#define EE_CALLBACK_VERIFY_BYTES_NUM             0x0020U



#define MIN_SECTOR_NUM      2U

#define EE_RETRY_TIMES      3U



/* Define record status type */
typedef enum
{
    EE_REC_STAT_VALID = 0U,
    EE_REC_STAT_DELETED = 1U,
    EE_REC_STAT_INCONSISTENT = 2U,
    EE_REC_STAT_HEADER_INVALID = 3U,
    EE_REC_STAT_HEADER_BLANK = 4U, 
}EE_RecordStatus_t;

/* Define sector status type */
typedef enum
{
    EE_SEC_STAT_VALID = 0U,
    EE_SEC_STAT_INVALIDATED = 1U,
    EE_SEC_STAT_INCONSISTENT = 2U,
    EE_SEC_STAT_HEADER_INVALID = 3U,
    EE_SEC_STAT_HEADER_BLANK = 4U, 
}EE_SectorStatus_t;


/* Define Sector Config type */
typedef struct
{
    uint32_t startAddr;        /* the sector start address */
    uint32_t size;             /* the size of sector */
}EE_SectorConfig_t;

/* Define Sector run-time information type */
typedef struct
{
    uint32_t index;            /* the sector index */ 
    uint32_t id;               /* the ID of sector */
    EE_SectorStatus_t status;  /* status of this sector */    
    uint32_t recordAddr;       /* the address of next record header to be
                                 written */
    uint32_t dataAddr;         /* the address of current record data */      
}EE_SectorInfo_t;
    
/* Define Sector header type */
typedef struct
{
    uint32_t id;               /* the ID of active sector */
    uint32_t startAddr;        /* the sector start address */
    uint32_t size;             /* the size of sector */
    EE_SectorStatus_t status;  /* status of this sector */    
}EE_SectorHeader_t;

/* record header type */
typedef struct
{    
    EE_RecordStatus_t  recordStatus; /* record status */ 
    uint32_t  dataStartAddr;         /* the record start address */    
    uint16_t  dataSize;              /* the record size */
    uint16_t  recordID;              /* the unique record ID */
}EE_RecordHeader_t;

/* Define Cache Table type */
typedef struct
{
    uint32_t* cachePtr;               /* a pointer to cache table */
    uint32_t num;                    /* the number of items
                                        (each item is 4-byte) */
}EE_cache_t;

/* Define Sector Config type */
typedef struct
{
    uint32_t sectorNum;             /* the number of sectors being used emulation */    
    const EE_SectorConfig_t  **sectors;   /* the sector configuration array pointer */
    ControlState_t cacheEn;         /* the flag to enable/disable the cache table */
    EE_cache_t *cTable;             /* the cache table structure */  
    EE_SectorInfo_t actSecInfo;     /* the information of active sector */ 
    volatile FlagStatus_t busyFlag; /* the busy flag of the sectors */
    uint16_t maxRecordId;           /* the maximum record ID supported. The 
                                       record ID is from 0 - maxRecordId */
}EE_Config_t;

/***************************************************************************!
 * @brief: Init the EEPROM Emulation driver
 *
 * @param[in]  eeConfig: EE configuration struct
 * @param[in]  swapEn: It indicates if it swaps sectors when it finds invalid 
 *                     record header during sector scanning.
 * @param[in]  CallBack: it points to a function to service the time critical 
 *                       events. Any code reachable from this function
 *                       must not be placed in the same Flash block as the 
 *                       EEPROM emulation
 *
 * @return result
 *         EE_OK
 *         EE_ERROR_BUSY
 *         EE_ERROR_NOT_ENOUGH_SECTORS
 *         EE_ERROR_FLASH_ERR
 *         EE_ERROR_ECC
 *         EE_ERROR_REC_HEADER_INVALID
 *         EE_ERROR_INPUT_PARA
 *         EE_ERROR_SWAP
 *         
 *
 ****************************************************************************/
 extern EE_Config_t eeConf;
 
uint32_t EE_Init(EE_Config_t* eeConfig, ControlState_t swapEn, 
                 void (*CallBack) (void));

/***************************************************************************//**
 * @brief  This API is to read the specific data record. The data record size
 *         is determined by the data size stored in emulated EEPROM.
 *
 * @param[in]  eeConfig: EE configuration struct
 * @param[in]  recordID: the ID of record to be read
 * @param[in]  dataSize: the size of data to be read from the record. It can not
 *                       exceeds the size of record.
 * @param[in]  buf: it points to the buffer that stores the data read out from
 *                  record.
 * @param[out]  acturalReadSize: the size of data that are actually read out 
 *                               will be stored to the memory pointed by
 *                               acturalReadSize after calling this function
 * @param[in]  CallBack: it points to a function to service the time critical 
 *                       events. Any code reachable from this function
 *                       must not be placed in the same Flash block as the 
 *                       EEPROM emulation
 *
 * @note       User must ensure that the data size to be read does not exceed 
 *             the buffer size. 
 *             
 *
 * @return     EE_OK
 *             EE_ERROR_BUSY -- EE is writing or erasing
 *             EE_ERROR_DATA_NOT_FOUND
 *             EE_ERROR_REC_ID_OUT_OF_RANGE
 *             EE_ERROR_ECC
 *             EE_ERROR_REC_HEADER_INVALID
 *
 ******************************************************************************/  
uint32_t EE_ReadRecord(EE_Config_t* eeConfig, uint16_t recordID, 
                       uint16_t dataSize, uint8_t *buf, 
                       uint16_t *acturalReadSize, void (*CallBack) (void));

/***************************************************************************
 * @brief; This API is to write data records to the EEPROM emulated Flash
 *          and re-write data record if this program operation fails.
 *
 * @param[in]  eeConfig: EE configuration struct
 * @param[in]  recordID: the ID of record to be written
 * @param[in]  dataSize: the size of data to be written. 
 * @param[in]  buf: it points to the buffer that stores the data to be written
 * @param[in]  srcInFlash: it indicates if the location of data(buf) to be 
 *                         written is in FLASH.
 *                         - 1: in flash
 *                         - 0: not in flash
 * @param[in]  CallBack: it points to a function to service the time critical 
 *                       events. Any code reachable from this function
 *                       must not be placed in the same Flash block as the 
 *                       EEPROM emulation
 *
 * @return EE_OK
 *         EE_ERROR_BUSY -- EE is writing or erasing
 *         EE_ERROR_NO_ENOUGH_SPACE
 *         EE_ERROR_SWAP
 *         EE_ERROR_INPUT_PARA
 *         EE_ERROR_WRITTEN_LOC_NOT_EMPTY
 *         EE_ERROR_READ_REC_DATA_ECC
 *         EE_ERROR_WRITTEN_VALUE
 *         EE_ERROR_ECC
 *
 ****************************************************************************/
uint32_t EE_WriteRecord(EE_Config_t* eeConfig, uint16_t recordID, 
                        uint16_t dataSize,const uint8_t *buf, 
                        uint32_t srcInFlash,void (*CallBack) (void));

/***************************************************************************//**
 * @brief  This API is to delete the specific data record. 
 *
 * @param[in]  eeConfig: EE configuration struct
 * @param[in]  recordID: the ID of record to be read
 * @param[in]  CallBack: it points to a function to service the time critical 
 *                       events. Any code reachable from this function
 *                       must not be placed in the same Flash block as the 
 *                       EEPROM emulation
 *
 * @return     EE_OK
 *             EE_ERROR_BUSY -- EE is writing or erasing
 *             EE_ERROR_DATA_NOT_FOUND
 *             EE_ERROR_REC_ID_OUT_OF_RANGE
 *             EE_ERROR_FLASH_ERR
 *
 ******************************************************************************/   
uint32_t EE_DeleteRecord(EE_Config_t* eeConfig, uint16_t recordID, 
                         void (*CallBack) (void));
void Eep_Init();
#endif