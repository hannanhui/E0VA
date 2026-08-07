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
**  Author      : qinchun.yang                                                **
**  Vendor      :                                                             **
**  DESCRIPTION : MemMap header for CSM                                       **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/
/******************************************************************************
**                      Revision Control History                             **
******************************************************************************/
/*  <VERSION>     <DATE>       <AUTHOR>        <REVISION LOG>
 *    V1.0.0      2019-10-18   qinchun.yang     Initial version
 *    V1.1.0      2020-07-16   yuzhe.zhang      R19-11
 *    V2.0.0      2023-02-06   jie.gu           R19_11
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
#ifdef CSM_START_SEC_CODE
#undef CSM_START_SEC_CODE
#define START_SEC_CODE
#elif defined CSM_STOP_SEC_CODE
#undef CSM_STOP_SEC_CODE
#define STOP_SEC_CODE
#elif defined CSM_START_SEC_CBK_NOTIFICATION_CODE
#undef CSM_START_SEC_CBK_NOTIFICATION_CODE
#define START_SEC_CALLBACK_CODE
#elif defined CSM_STOP_SEC_CBK_NOTIFICATION_CODE
#undef CSM_STOP_SEC_CBK_NOTIFICATION_CODE
#define STOP_SEC_CALLBACK_CODE
/* Data */
#elif defined CSM_START_SEC_VAR_CLEARED_BOOLEAN
#undef CSM_START_SEC_VAR_CLEARED_BOOLEAN
#define START_SEC_VAR_CLEARED_BOOLEAN
#elif defined CSM_STOP_SEC_VAR_CLEARED_BOOLEAN
#undef CSM_STOP_SEC_VAR_CLEARED_BOOLEAN
#define STOP_SEC_VAR_CLEARED_BOOLEAN
#elif defined CSM_START_SEC_VAR_CLEARED_UNSPECIFIED
#undef CSM_START_SEC_VAR_CLEARED_UNSPECIFIED
#define START_SEC_VAR_CLEARED_UNSPECIFIED
#elif defined CSM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#undef CSM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#define STOP_SEC_VAR_CLEARED_UNSPECIFIED
/*Const data.*/
#elif defined CSM_START_SEC_CONST_PTR
#undef CSM_START_SEC_CONST_PTR
#define START_SEC_CONST_PTR
#elif defined CSM_STOP_SEC_CONST_PTR
#undef CSM_STOP_SEC_CONST_PTR
#define STOP_SEC_CONST_PTR
#elif defined CSM_START_SEC_CONST_UNSPECIFIED
#undef CSM_START_SEC_CONST_UNSPECIFIED
#define START_SEC_CONST_UNSPECIFIED
#elif defined CSM_STOP_SEC_CONST_UNSPECIFIED
#undef CSM_STOP_SEC_CONST_UNSPECIFIED
#define STOP_SEC_CONST_UNSPECIFIED

/*No-Init data(clear)*/
#elif defined CSM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#undef CSM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#define START_SEC_VAR_NO_INIT_UNSPECIFIED
#elif defined CSM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#undef CSM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#define STOP_SEC_VAR_NO_INIT_UNSPECIFIED

#else
#error "CSM not include this section"
#endif

#include "MemMap.h"
