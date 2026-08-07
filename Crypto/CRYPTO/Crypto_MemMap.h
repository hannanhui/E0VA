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
**  FILENAME    : Crypto_MemMap.h                                             **
**                                                                            **
**  Created on  :                                                             **
**  Author      : yuhao.ge                                                    **
**  Vendor      :                                                             **
**  DESCRIPTION : MemMap header for Crypto                                    **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.4.0                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/
#ifdef CRYPTO_START_SEC_CODE
#undef CRYPTO_START_SEC_CODE
#define START_SEC_CODE
#elif defined CRYPTO_STOP_SEC_CODE
#undef CRYPTO_STOP_SEC_CODE
#define STOP_SEC_CODE
/* Data */
#elif defined CRYPTO_START_SEC_VAR_CLEARED_BOOLEAN
#undef CRYPTO_START_SEC_VAR_CLEARED_BOOLEAN
#define START_SEC_VAR_CLEARED_BOOLEAN
#elif defined CRYPTO_STOP_SEC_VAR_CLEARED_BOOLEAN
#undef CRYPTO_STOP_SEC_VAR_CLEARED_BOOLEAN
#define STOP_SEC_VAR_CLEARED_BOOLEAN
#elif defined CRYPTO_START_SEC_VAR_CLEARED_UNSPECIFIED
#undef CRYPTO_START_SEC_VAR_CLEARED_UNSPECIFIED
#define START_SEC_VAR_CLEARED_UNSPECIFIED
#elif defined CRYPTO_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#undef CRYPTO_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#define STOP_SEC_VAR_CLEARED_UNSPECIFIED
#elif defined CRYPTO_START_SEC_VAR_CLEARED_8
#undef CRYPTO_START_SEC_VAR_CLEARED_8
#define START_SEC_VAR_CLEARED_8
#elif defined CRYPTO_STOP_SEC_VAR_CLEARED_8
#undef CRYPTO_STOP_SEC_VAR_CLEARED_8
#define STOP_SEC_VAR_CLEARED_8
#elif defined CRYPTO_START_SEC_VAR_CLEARED_32
#undef CRYPTO_START_SEC_VAR_CLEARED_32
#define START_SEC_VAR_CLEARED_32
#elif defined CRYPTO_STOP_SEC_VAR_CLEARED_32
#undef CRYPTO_STOP_SEC_VAR_CLEARED_32
#define STOP_SEC_VAR_CLEARED_32
#elif defined CRYPTO_START_SEC_CONST_UNSPECIFIED
#undef CRYPTO_START_SEC_CONST_UNSPECIFIED
#define START_SEC_CONST_UNSPECIFIED
#elif defined CRYPTO_STOP_SEC_CONST_UNSPECIFIED
#undef CRYPTO_STOP_SEC_CONST_UNSPECIFIED
#define STOP_SEC_CONST_UNSPECIFIED
#else
#error "Crypto not include this section"
#endif

#include "MemMap.h"
