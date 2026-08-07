/*******************************************************************************
**                                                                            **
** Copyright (C) iSOFT   (2020)                                               **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to iSOFT.         **
** Passing on and copying of this document, and communication                 **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : SchM_KeyM.h                                                 **
**                                                                            **
**  Created on  :                                                             **
**  Author      : yuzhe.zhang                                                 **
**  Vendor      :                                                             **
**  DESCRIPTION : mainfunction define head file                               **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/

/******************************************************************************
**                      Revision Control History                             **
******************************************************************************/
/*  <VERSION>    <DATE>      <AUTHOR>        <REVISION LOG>
 *  V1.0.0     2020-06-01   yuzhe.zhang     initial version.
 */

#ifndef SCHM_KEYM_H
#define SCHM_KEYM_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
#if (STD_ON == KEYM_CRYPTO_KEYMANAGER_ENABLED)
/*************************************************************************/
/*
 * Brief               Function is called periodically according the specified time interval.
 * ServiceId           0x19
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        None
 */
/*************************************************************************/

void KeyM_MainFunction(void);
#endif /* STD_ON == KEYM_CRYPTO_KEYMANAGER_ENABLED */
#endif /*SCHM_KEYM_H*/
