/*******************************************************************************
**                                                                            **
** Copyright (C) iSOFT   (2022)                                               **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to iSOFT.         **
** Passing on and copying of this document, and communication                 **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : Fee_MemMap.h                                                **
**                                                                            **
**  Created on  :                                                             **
**  Author      : zhengfei.li                                                 **
**  Vendor      :                                                             **
**  DESCRIPTION : Memory mapping abstraction declaration of Fee               **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19_11                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
#define FEE_MEMMAP_VENDOR_ID        62u
#define FEE_MEMMAP_MODULE_ID        21u
#define FEE_MEMMAP_AR_MAJOR_VERSION 4u
#define FEE_MEMMAP_AR_MINOR_VERSION 2u
#define FEE_MEMMAP_AR_PATCH_VERSION 2u
#define FEE_MEMMAP_SW_MAJOR_VERSION 2u
#define FEE_MEMMAP_SW_MINOR_VERSION 0u
#define FEE_MEMMAP_SW_PATCH_VERSION 0u
#define FEE_MEMMAP_VENDOR_API_INFIX 0u

#if defined FEE_START_SEC_CODE
#undef FEE_START_SEC_CODE
#define START_SEC_CODE
#elif defined FEE_STOP_SEC_CODE
#undef FEE_STOP_SEC_CODE
#define STOP_SEC_CODE

#elif defined FEE_START_SEC_FEEJOBENDNOTIFICATION_CALLBACK_CODE
#undef FEE_START_SEC_FEEJOBENDNOTIFICATION_CALLBACK_CODE
#define START_SEC_CALLBACK_CODE
#elif defined FEE_STOP_SEC_FEEJOBENDNOTIFICATION_CALLBACK_CODE
#undef FEE_STOP_SEC_FEEJOBENDNOTIFICATION_CALLBACK_CODE
#define STOP_SEC_CALLBACK_CODE

#elif defined FEE_START_SEC_FEEJOBERRORNOTIFICATION_CALLBACK_CODE
#undef FEE_START_SEC_FEEJOBERRORNOTIFICATION_CALLBACK_CODE
#define START_SEC_CALLBACK_CODE
#elif defined FEE_STOP_SEC_FEEJOBERRORNOTIFICATION_CALLBACK_CODE
#undef FEE_STOP_SEC_FEEJOBERRORNOTIFICATION_CALLBACK_CODE
#define STOP_SEC_CALLBACK_CODE

#elif defined FEE_START_SEC_VAR_INIT_PTR
#undef FEE_START_SEC_VAR_INIT_PTR
#define START_SEC_VAR_INIT_PTR
#elif defined FEE_STOP_SEC_VAR_INIT_PTR
#undef FEE_STOP_SEC_VAR_INIT_PTR
#define STOP_SEC_VAR_INIT_PTR

#elif defined FEE_START_SEC_VAR_INIT_8
#undef FEE_START_SEC_VAR_INIT_8
#define START_SEC_VAR_INIT_8
#elif defined FEE_STOP_SEC_VAR_INIT_8
#undef FEE_STOP_SEC_VAR_INIT_8
#define STOP_SEC_VAR_INIT_8

#elif defined FEE_START_SEC_VAR_NO_INIT_UNSPECIFIED
#undef FEE_START_SEC_VAR_NO_INIT_UNSPECIFIED
#define START_SEC_VAR_NO_INIT_UNSPECIFIED
#elif defined FEE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#undef FEE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#define STOP_SEC_VAR_NO_INIT_UNSPECIFIED

#elif defined FEE_START_SEC_VAR_NO_INIT_8
#undef FEE_START_SEC_VAR_NO_INIT_8
#define START_SEC_VAR_NO_INIT_8
#elif defined FEE_STOP_SEC_VAR_NO_INIT_8
#undef FEE_STOP_SEC_VAR_NO_INIT_8
#define STOP_SEC_VAR_NO_INIT_8

#elif defined FEE_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#undef FEE_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#define START_SEC_CONST_PBCFG_UNSPECIFIED
#elif defined FEE_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#undef FEE_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#define STOP_SEC_CONST_PBCFG_UNSPECIFIED

#elif defined FEE_START_SEC_PCCONFIG_DATA_UNSPECIFIED
#undef FEE_START_SEC_PCCONFIG_DATA_UNSPECIFIED
#define START_SEC_CONFIG_DATA_UNSPECIFIED
#elif defined FEE_STOP_SEC_PCCONFIG_DATA_UNSPECIFIED
#undef FEE_STOP_SEC_PCCONFIG_DATA_UNSPECIFIED
#define STOP_SEC_CONFIG_DATA_UNSPECIFIED

#else
#error "Fee not include this section"
#endif
#include "MemMap.h"
/*******************************************************************************
**                      End of file                                           **
*******************************************************************************/
