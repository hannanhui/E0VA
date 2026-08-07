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
**  FILENAME    : Csm_MemMap.h                                                **
**                                                                            **
**  Created on  :                                                             **
**  Author      : yuzhe.zhang                                                 **
**  Vendor      :                                                             **
**  DESCRIPTION : MemMap header for CRYIF                                     **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/
/******************************************************************************
**                      Revision Control History                             **
******************************************************************************/
/*  <VERSION>     <DATE>      <AUTHOR>        <REVISION LOG>
 *    V1.0.0     2020-07-16   yuzhe.zhang     R19-11
 *    V2.0.0     2023-02-06   jie.gu          R19-11
 */
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
/*General function.*/
#if defined CRYIF_START_SEC_CODE
#undef CRYIF_START_SEC_CODE
#define START_SEC_CODE
#elif defined CRYIF_STOP_SEC_CODE
#undef CRYIF_STOP_SEC_CODE
#define STOP_SEC_CODE
#elif defined CRYIF_START_SEC_CBK_NOTIFICATION_CODE
#undef CRYIF_START_SEC_CBK_NOTIFICATION_CODE
#define START_SEC_CALLBACK_CODE
#elif defined CRYIF_STOP_SEC_CBK_NOTIFICATION_CODE
#undef CRYIF_STOP_SEC_CBK_NOTIFICATION_CODE
#define STOP_SEC_CALLBACK_CODE
/* Data */
#elif defined CRYIF_START_SEC_VAR_CLEARED_BOOLEAN
#undef CRYIF_START_SEC_VAR_CLEARED_BOOLEAN
#define START_SEC_VAR_CLEARED_BOOLEAN
#elif defined CRYIF_STOP_SEC_VAR_CLEARED_BOOLEAN
#undef CRYIF_STOP_SEC_VAR_CLEARED_BOOLEAN
#define STOP_SEC_VAR_CLEARED_BOOLEAN
#elif defined CRYIF_START_SEC_CONST_UNSPECIFIED
#undef CRYIF_START_SEC_CONST_UNSPECIFIED
#define START_SEC_CONST_UNSPECIFIED
#elif defined CRYIF_STOP_SEC_CONST_UNSPECIFIED
#undef CRYIF_STOP_SEC_CONST_UNSPECIFIED
#define STOP_SEC_CONST_UNSPECIFIED
#else
#error "CRYIF not include this section"
#endif

#include "MemMap.h"
