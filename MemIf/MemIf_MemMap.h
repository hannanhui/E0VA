/******************************************************************************
**                                                                           **
** Copyright (C) iSOFT   (2022)                                              **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to iSOFT.        **
** Passing on and copying of this document, and communication                **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
**************************************************************************** **
**                                                                           **
**  FILENAME    : MemIf_MemMap.h                                             **
**                                                                           **
**  Created on  : 2022/1/26 15:21:52                                         **
**  Author      : haibin.shao                                                **
**  Vendor      :                                                            **
**  DESCRIPTION : MemIf memmap                                               **
**                                                                           **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                     **
**                                                                           **
**************************************************************************** */

#ifdef MEMIF_START_SEC_CODE
#undef MEMIF_START_SEC_CODE
#define START_SEC_CODE
#elif defined MEMIF_STOP_SEC_CODE
#undef MEMIF_STOP_SEC_CODE
#define STOP_SEC_CODE
#elif defined MEMIF_START_SEC_CONST_8BIT
#undef MEMIF_START_SEC_CONST_8BIT
#define START_SEC_CONST_8BIT
#elif defined MEMIF_STOP_SEC_CONST_8BIT
#undef MEMIF_STOP_SEC_CONST_8BIT
#define STOP_SEC_CONST_8BIT
#elif defined MEMIF_START_SEC_CONST_32BIT
#undef MEMIF_START_SEC_CONST_32BIT
#define START_SEC_CONST_32BIT
#elif defined MEMIF_STOP_SEC_CONST_32BIT
#undef MEMIF_STOP_SEC_CONST_32BIT
#define STOP_SEC_CONST_32BIT
#elif defined MEMIF_START_SEC_CONST_UNSPECIFIED
#undef MEMIF_START_SEC_CONST_UNSPECIFIED
#define START_SEC_CONST_UNSPECIFIED
#elif defined MEMIF_STOP_SEC_CONST_UNSPECIFIED
#undef MEMIF_STOP_SEC_CONST_UNSPECIFIED
#define STOP_SEC_CONST_UNSPECIFIED
#else
//#error "MemIf not include this section"
#endif

//#include "MemMap.h"
