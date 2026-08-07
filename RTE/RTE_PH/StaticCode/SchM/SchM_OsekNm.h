/**
 *
 * Copyright (C) iSOFT   (2022)
 *
 * All rights reserved.
 *
 * This document contains proprietary information belonging to iSOFT.Passing on and copying of this document, and
 * communication of its contents is not permitted without prior written authorization.
 *
 *
 *  @file               : SchM_OsekNm.h
 *  @version            : V1.0.0
 *  @author             : darren.zhang
 *  @date               : 2017/12/02
 *  @vendor             : isoft
 *  @description        : OsekNm schm
 *  @specification(s)   : AUTOSAR classic Platform R19-11 custom
 *
 */

#ifndef SCHM_OSEKNM_H_
#define SCHM_OSEKNM_H_

/*=================================================[inclusions]=======================================================*/
#if !defined(OSEKNM_SCHM_USED_OS)
#define OSEKNM_SCHM_USED_OS 1
#endif /* !defined(OSEKNM_SCHM_USED_OS) */

#if OSEKNM_SCHM_USED_OS
#include "Os.h"
#endif /* OSEKNM_SCHM_USED_OS */

/*=================================================[macros]===========================================================*/

#if OSEKNM_SCHM_USED_OS

#define SchM_Enter_OsekNm_Network(nmChannel) SuspendAllInterrupts()
#define SchM_Exit_OsekNm_Network(nmChannel)  ResumeAllInterrupts()
#define SchM_Enter_OsekNm_MsgContext()       SuspendAllInterrupts()
#define SchM_Exit_OsekNm_MsgContext()        ResumeAllInterrupts()

#else

#define SchM_Enter_OsekNm_Network(nmChannel)
#define SchM_Exit_OsekNm_Network(nmChannel)
#define SchM_Enter_OsekNm_MsgContext()
#define SchM_Exit_OsekNm_MsgContext()
#endif /* OSEKNM_SCHM_USED_OS */

#endif /* SCHM_OSEKNM_H_ */
