/**
 * @file        SecM.h
 * @brief       AUTOSAR SecM - SecM driver header file.
 * @details     SecM driver header file, containing the Autosar API specification and
 *               other variables and functions that are exported by the SecM driver.
 * @version     1.0.0
 *
 * @addtogroup  SecM
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

#ifndef SECM_H
#define SECM_H

#ifdef __cplusplus
extern "C"{
#endif

/*====================================================================================================*
 *                                           INCLUDE FILES                                          
 *====================================================================================================*/

#include "FBL.h"
#include "Crc.h"
#include "SecM_Cfg.h"
#include <lzss_decomp.h>
/*====================================================================================================*
 *                                  HEADER FILE VERSION INFORMATION
 *====================================================================================================*/

/**
* @brief Parameters that shall be published within the SecM driver header file and also in the
*        module's description file
*/
#define SecM_VENDOR_ID                    xx
#define SecM_MODULE_ID                    xx
#define SecM_AR_RELEASE_MAJOR_VERSION     xx
#define SecM_AR_RELEASE_MINOR_VERSION     xx
#define SecM_AR_RELEASE_REVISION_VERSION  xx
#define SecM_SW_MAJOR_VERSION             xx
#define SecM_SW_MINOR_VERSION             xx
#define SecM_SW_PATCH_VERSION             xx

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

/* Add code here */

/*====================================================================================================*
 *                                               ENUMS                                              
 *====================================================================================================*/

/* Add code here */

/*====================================================================================================*
 *                                   STRUCTURES AND OTHER TYPEDEFS                                  
 *====================================================================================================*/

/* struct type for Crc Check Sum */
#if(STD_ON == CRC32_ALGORITHM)
typedef uint32 SecM_CrcCheckSumType;
#endif
#if(STD_ON == CRC16_ALGORITHM)
typedef uint16 SecM_CrcCheckSumType;
#endif

/*  struct type for Crc Check  */
typedef struct
{
	/* CRC first call */
    boolean CrcFirstCall;
    /*  CRC Check Sum  */
    SecM_CrcCheckSumType CrcCheckSum;
}SecM_CheckState;

/*====================================================================================================*
 *                                    GLOBAL VARIABLE DECLARATIONS                                  
 *====================================================================================================*/

/* Add code here */

/*====================================================================================================*
 *                                        FUNCTION PROTOTYPES                                       
 *====================================================================================================*/

FUNC(Std_ReturnType,AUTOMATIC) SecM_CreatCrc
(
	P2VAR(SecM_CheckState,AUTOMATIC,AUTOMATIC) CheckState,
	P2CONST(uint8,AUTOMATIC,AUTOMATIC) CheckBuffer,
	VAR(uint32, AUTOMATIC) CheckLength
);

FUNC(Std_ReturnType,AUTOMATIC) SecM_SofawareCheck
(
	P2CONST(FBL_SegmentPhyInfoType,AUTOMATIC,AUTOMATIC) SegmentInfo,
	P2VAR(SecM_CheckState,AUTOMATIC,AUTOMATIC) CheckState
);
void SHA_Init();
FUNC(Std_ReturnType,AUTOMATIC) SHA_Calculate();
void  SHA_Finish(void);
FUNC(Std_ReturnType,AUTOMATIC) LZSS_Calculate();
FUNC(Std_ReturnType,AUTOMATIC) RSA_Calculate(uint8 *RawShaData);

#ifdef __cplusplus
}
#endif

#endif /* SECM_H */
/** @} */
