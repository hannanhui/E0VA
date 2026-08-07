/**
 * @file        NvM_Cbk.h
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

#ifndef NVM_CBK_H
#define NVM_CBK_H

#ifdef __cplusplus
extern "C"{
#endif

/*====================================================================================================*
 *                                           INCLUDE FILES                                          
 *====================================================================================================*/

/*====================================================================================================*
 *                                  SOURCE FILE VERSION INFORMATION                                 
 *====================================================================================================*/
#define NVM_CBK_VENDOR_ID                      0U
#define NVM_CBK_AR_RELEASE_MAJOR_VERSION       4U
#define NVM_CBK_AR_RELEASE_MINOR_VERSION       2U
#define NVM_CBK_AR_RELEASE_REVISION_VERSION    2U
#define NVM_CBK_SW_MAJOR_VERSION               1U
#define NVM_CBK_SW_MINOR_VERSION               2U
#define NVM_CBK_SW_PATCH_VERSION               0U

/*====================================================================================================*
 *                                         FILE VERSION CHECKS                                      
 *====================================================================================================*/

/*====================================================================================================*
 *                                             CONSTANTS                                            
 *====================================================================================================*/

/*====================================================================================================*
 *                                         DEFINES AND MACROS                                       
 *====================================================================================================*/

/*====================================================================================================*
 *                                               ENUMS                                              
 *====================================================================================================*/

/*====================================================================================================*
 *                                   STRUCTURES AND OTHER TYPEDEFS                                  
 *====================================================================================================*/

/*====================================================================================================*
 *                                    GLOBAL VARIABLE DECLARATIONS                                  
 *====================================================================================================*/

/*====================================================================================================*
 *                                        FUNCTION PROTOTYPES                                       
 *====================================================================================================*/
#define NVM_START_SEC_CODE
#include "NvM_MemMap.h"

#if (NVM_POLLING_MODE == STD_OFF)
void NvM_JobErrorNotification(void);
void NvM_JobEndNotification(void);
#endif /* NVM_POLLING_MODE == STD_OFF */

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* NVM_CBK_H */
/** @} */
