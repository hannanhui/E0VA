/**
 * @file        FBL.h
 * @brief       AUTOSAR FBL - FBL driver header file.
 * @details     FBL driver header file, containing the Autosar API specification and
 *               other variables and functions that are exported by the FBL driver.
 * @version     1.0.0
 *
 * @addtogroup  FBL
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

#ifndef FBL_H
#define FBL_H

#ifdef __cplusplus
extern "C"{
#endif

/*====================================================================================================*
 *                                           INCLUDE FILES                                          
 *====================================================================================================*/

#include "FBL_Cfg.h"
#include "Dcm.h"

/*====================================================================================================*
 *                                  HEADER FILE VERSION INFORMATION
 *====================================================================================================*/

/**
* @brief Parameters that shall be published within the FBL driver header file and also in the
*        module's description file
*/
#define FBL_VENDOR_ID                    xx
#define FBL_MODULE_ID                    xx
#define FBL_AR_RELEASE_MAJOR_VERSION     xx
#define FBL_AR_RELEASE_MINOR_VERSION     xx
#define FBL_AR_RELEASE_REVISION_VERSION  xx
#define FBL_SW_MAJOR_VERSION             xx
#define FBL_SW_MINOR_VERSION             xx
#define FBL_SW_PATCH_VERSION             xx

/*====================================================================================================*
 *                                         FILE VERSION CHECKS                                      
 *====================================================================================================*/

/* Add code here */

/*====================================================================================================*
 *                                             CONSTANTS                                            
 *====================================================================================================*/

/* Add code here */

/*====================================================================================================*
 *                                         DEFINES AND MACROS                                       
 *====================================================================================================*/

/* FBL module execute result */
#define FBL_OK                		   0x00U
#define FBL_NOT_OK                     0x01U
#define FBL_ERR_SEQUENCE               0x02U
#define FBL_ERR_FINGERPRINT            0x03U
#define FBL_ERR_FLASHDRIVER            0x04U
#define FBL_ERR_PHYSICAL_PAR           0x05U
#define FBL_EER_DATA                   0x06U
#define FBL_EER_STEP                   0x07U
#define FBL_EER_PARAMETER     		   0x08U
#define FBL_EER_PROGRAMINFO     	   0x09U

/* DCM calls the interface step */
#define FBL_UDS0X34_STEP               0x01U
#define FBL_UDS0X36_STEP               0x02U
#define FBL_UDS0X37_STEP               0x03U
#define FBL_UDS_DEPEND_CHECK_STEP      0x04U
#define FBL_UDS_INTEGRITY_CHECK_STEP   0x05U
#define FBL_UDS0X310202_STEP           0x06U
#define FBL_UDS0X31FF00_STEP           0x07U

/*====================================================================================================*
 *                                               ENUMS                                              
 *====================================================================================================*/

/* Add code here */

/*====================================================================================================*
 *                                   STRUCTURES AND OTHER TYPEDEFS                                  
 *====================================================================================================*/
#define kFlashOk	0x00u
#define kFlashFailed	0x01u


/*=======[T Y P E   D E F I N I T I O N S]====================================*/
/** flash driver major version number */
typedef uint8 tMajorVersion;

/** flash driver minor version number */
typedef uint8 tMinorVersion;

/** bugfix / patchlevel number */
typedef uint8 tBugfixVersion;

/** result of flash driver routines */
typedef uint16 tFlashResult;

/** logical address */
typedef uint32 tFlashAddress;

/** length (in bytes) */
typedef uint32 tFlashLength;

/** ambiguous data */
typedef uint8 tFlashData;

/** watchdog trigger routine */
typedef void (*tWDTriggerFct)(void);



/** initialization: input parameters */
typedef struct
{
    /* flash driver patch level version */
    tBugfixVersion patchLevel;

    /* flash driver minor version number */
    tMajorVersion minorNumber;

    /* flash driver major version number */
    tMinorVersion majorNumber;

    /* reserved for future use, set to 0x00 for now */
    uint8 reserved1;

    /* retrun value / error code: output parameters */
    tFlashResult errorCode;

    /* reserved for future use, set to 0x0000 for now */
    uint16 reserved2;

    /* erase / write: input parameters */
    /* logical target address */
    tFlashAddress address;

    /* lenght information (in bytes) */
    tFlashLength length;

    /* pointer to data buffer */
    const tFlashData *data;

    /* pointer to watchdog trigger routine */
    tWDTriggerFct wdTriggerFct;



//    uint8_t      (* wdTriggerFct)(void); /**< Pointer to watchdog handling function   */


} tFlashParam;

/** prototype of flash driver routine */
typedef void (*tFlashFct)(tFlashParam* flashParam);

/** flash infomation table */
typedef struct
{
    /* Motorola Star12 */
    const uint8 mcuType;

    /* some mask number */
    const uint8 maskType;

    /* byte reserved for future use */
    const uint8 reserve;

    /* interface version number */
    const uint8 interface;

    /* flash initialize function */
    const tFlashFct flashInitFct;

    /* flash de-initialize function */
    const tFlashFct flashDeInitFct;

    /* flash erase function */
    const tFlashFct flashEraseFct;

    /* flash program function */
    const tFlashFct flashWriteFct;

    const uint32 reserved;

} tFlash_InfoType;
extern const tFlash_InfoType* BLFlash_InfoPtr;

/* The physical data type of the paragraph contains the address and length */
typedef struct
{
	/* The beginning address of the Segment   */
	FBL_AddressType SegmentAddre;
	/* The length  of the Segment   */
	FBL_LengthType  SegmentLength;
	/* Segment CRC check sum */
	uint32 SegmentCrcCheck;
	uint32 SegmentSHACheck;
}FBL_SegmentPhyInfoType;

/*The physical information of the data logic block, contains the segment
 *  information contained in the starting address, block length, and logical block*/
typedef struct
{
	/* The beginning address of the logical block  */
	FBL_AddressType BlockAddress;
	/* Data length of the logical block  */
	FBL_LengthType  BlockLength;
	/* Statue of the logical block  */
	boolean  BlockStatue;
	/* Crc of the logical block  */
	uint32  BlockCrcCheck;
	/*  Block programming number  */
	uint8 BlockProNum;
    /* Data segment information contained in the logical block*/
	FBL_SegmentPhyInfoType FBL_SegmentInfo;
}FBL_LogicalBlPhyInfoType;

/* The information of the logical block, contains the number of blocks,
 * each piece of information  */
typedef struct
{
	/*  Number of logical blocks  */
	uint8 BlockNumber;
	/*  Number of logical blocks  */
	FBL_LogicalBlPhyInfoType  FBL_LogicalBlPhyInfo[LOGICAL_MAX];
}FBL_LogicalBlInfoType;

/* Flash drive information, which contains the driven data segment information
 * and the starting site, length, and check values of the driver   */
typedef struct
{
	/* The beginning address of the flash drive */
	FBL_AddressType FlashAddress;
	/* Flash length  */
	FBL_LengthType  FlashLength;
	/* Flash-check value  */
	uint32  FlashCrcCheck;
	/* Flash segment information  */
	FBL_SegmentPhyInfoType FalshSegmentInfo;
}FBL_FlashDriveInfoType;

/* App status information contains information such as the effectiveness of the app,
 *  the number of programs, and the number of successful downloads  */
typedef struct
{
	/*  APP Effective mark  */
	boolean AppValid;
	/* The app successfully downloads the number of times */
	uint8 AppDownSucNum;
	/* number of Application programming  */
	uint8 AppPrograNum;
}FBL_AppStatusType;



/* Application programming information  */
typedef struct
{
	/*  Number of logical blocks  */
	FBL_AppStatusType FBL_AppStatus;

	/* Logical block information for programming */
	FBL_LogicalBlInfoType FBL_LogicalBlInfo;
	/* The object check value of the app programming information  */
	uint32  CrcCheck;
}FBL_AppProgramInfoType;

/*====================================================================================================*
 *                                    GLOBAL VARIABLE DECLARATIONS                                  
 *====================================================================================================*/

extern uint32 FBL_TranCrcData;
extern  FBL_AppProgramInfoType FBL_AppProgramInfo;

/*====================================================================================================*
 *                                        FUNCTION PROTOTYPES                                       
 *====================================================================================================*/

FUNC(Std_ReturnType,AUTOMATIC) FBL_WriteFlashAppInfo(void);

FUNC(Std_ReturnType,AUTOMATIC)FBL_Dcm0x34Call
(
	uint32 MemoryAddress,
    uint32 MemorySize,
    P2VAR(uint32,AUTOMATIC,DCM_VAR)BlockLength
);

FUNC(Std_ReturnType,AUTOMATIC) FBL_Dcm0x36Call
(
	CONST(FBL_AddressType,AUTOMATIC) StartAdd,
	P2CONST(uint8,AUTOMATIC,AUTOMATIC) SourceBuff,
	CONST(FBL_LengthType,AUTOMATIC) Length
);

FUNC(Std_ReturnType,AUTOMATIC) FBL_Dcm0x37Call(void);

FUNC(Std_ReturnType,AUTOMATIC) FBL_DcmIntegrityCheck(P2CONST(uint8,AUTOMATIC,AUTOMATIC) CheckSum);

FUNC(Std_ReturnType,AUTOMATIC) FBL_Dcm0x31ff00Erase(CONST(uint8,AUTOMATIC) Index);

FUNC(Std_ReturnType,AUTOMATIC) FBL_DcmDependCheckCall(void);

FUNC(void,AUTOMATIC) FBL_Init(void);

FUNC(Std_ReturnType,AUTOMATIC) FBL_Dcm0x31DD02Check(P2CONST(uint8,AUTOMATIC,AUTOMATIC) SourceBuff);

FUNC(Std_ReturnType,AUTOMATIC)CheckProgrammingDependncies(void);
FUNC(void,AUTOMATIC) FBL_MainFunction(void);

#ifdef __cplusplus
}
#endif

#endif /* FBL_H */
/** @} */
