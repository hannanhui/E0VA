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
**  FILENAME    : CSM_Type.h                                                 **
**                                                                            **
**  Created on  :                                                             **
**  Author      : yuzhe.zhang                                                 **
**  Vendor      :                                                             **
**  DESCRIPTION : type declaration of KeyManager                              **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/

/******************************************************************************
**                      Revision Control History                             **
******************************************************************************/
/*  <VERSION>    <DATE>      <AUTHOR>        <REVISION LOG>
 *  V1.0.0     2020-06-01    yuzhe.zhang     initial version.
 *  V2.0.0     2023-02-06    jie.gu          R19_11
 */
#ifndef CSM_TYPE_H
#define CSM_TYPE_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Crypto_GeneralTypes.h"
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*Jobs PC-config type*/
typedef struct
{
    P2CONST(Crypto_JobPrimitiveInfoType, TYPEDEF, CSM_CONST) jobPrimitiveInfo;
    P2CONST(Crypto_JobInfoType, TYPEDEF, CSM_CONST) jobInfo;
    P2VAR(Crypto_JobRedirectionInfoType, TYPEDEF, CSM_CONST) inOutRedirtRef;
    uint32 queRef;
    boolean usePort;
} Csm_JobsCfgType;

/*configuration of a CSM key*/
typedef struct
{
    uint32 cryIfKey;
    boolean usePort;
} Csm_KeyCfgType;

/* CSM queue configurations*/
typedef struct
{
    uint32 queueSize;
    uint32 cryIfChRef;
} Csm_QueueCfgType;

/*Identification of a CSM service configuration via a numeric identifier*/
typedef uint16 Csm_ConfigIdType;
#endif
