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
**  FILENAME    : SchM_EthTSyn.h                                              **
**                                                                            **
**  Created on  : 2022-11-09                                                  **
**  Author      : Xinrun.Wang                                                 **
**  Vendor      :                                                             **
**  DESCRIPTION : Scheduler Manager for EthTSyn                               **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*  <VERSION>    <DATE>      <AUTHOR>        <REVISION LOG>
 *  V1.0.0       2022-11-9   Xinrun.Wang     Initial upload
 */
#ifndef SCHM_ETHTSYN_H
#define SCHM_ETHTSYN_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#if !defined(ETHTSYN_USED_SCHM)
#define ETHTSYN_USED_SCHM 1
#endif /* !defined(ETHTSYN_USED_SCHM) */

#if ETHTSYN_USED_SCHM
#include "Os.h"
#endif /* ETHTSYN_USED_SCHM */

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
#if ETHTSYN_USED_SCHM
#define SchM_Enter_EthTSyn() DisableAllInterrupts()
#define SchM_Exit_EthTSyn()  EnableAllInterrupts()
#else
#define SchM_Enter_EthTSyn()
#define SchM_Exit_EthTSyn()
#endif /* ETHTSYN_USED_SCHM */
/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Declaration                               **
*******************************************************************************/

/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/

#endif /* SCHM_ETHTSYN_H */
