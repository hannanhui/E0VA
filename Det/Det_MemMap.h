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
**  FILENAME    : Det_MemMap.h                                               **
**                                                                           **
**  Created on  :                                                            **
**  Author      : haibin.shao                                                **
**  Vendor      :                                                            **
**  DESCRIPTION : DET memmap                                                 **
**                                                                           **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                      **
**                                                                           **
**************************************************************************** */

/*=======[M E M M A P  S Y M B O L  D E F I N E]=============================*/
#ifdef DET_START_SEC_CODE
#undef DET_START_SEC_CODE
#define START_SEC_CODE
#elif defined DET_STOP_SEC_CODE
#undef DET_STOP_SEC_CODE
#define STOP_SEC_CODE
#elif defined DET_START_SEC_CONST_8BIT
#undef DET_START_SEC_CONST_8BIT
#define START_SEC_CONST_8
#elif defined DET_STOP_SEC_CONST_8BIT
#undef DET_STOP_SEC_CONST_8BIT
#define STOP_SEC_CONST_8
#elif defined DET_START_SEC_CONST_32BIT
#undef DET_START_SEC_CONST_32BIT
#define START_SEC_CONST_32
#elif defined DET_STOP_SEC_CONST_32BIT
#undef DET_STOP_SEC_CONST_32BIT
#define STOP_SEC_CONST_32
#elif defined DET_START_SEC_VAR_NO_INIT_8BIT
#undef DET_START_SEC_VAR_NO_INIT_8BIT
#define START_SEC_VAR_NO_INIT_8
#elif defined DET_STOP_SEC_VAR_NO_INIT_8BIT
#undef DET_STOP_SEC_VAR_NO_INIT_8BIT
#define STOP_SEC_VAR_NO_INIT_8
#elif defined DET_START_SEC_VAR_NO_INIT_16BIT
#undef DET_START_SEC_VAR_NO_INIT_16BIT
#define START_SEC_VAR_NO_INIT_16
#elif defined DET_STOP_SEC_VAR_NO_INIT_16BIT
#undef DET_STOP_SEC_VAR_NO_INIT_16BIT
#define STOP_SEC_VAR_NO_INIT_16
#elif defined DET_START_SEC_VAR_NO_INIT_32BIT
#undef DET_START_SEC_VAR_NO_INIT_32BIT
#define START_SEC_VAR_NO_INIT_32
#elif defined DET_STOP_SEC_VAR_NO_INIT_32BIT
#undef DET_STOP_SEC_VAR_NO_INIT_32BIT
#define STOP_SEC_VAR_NO_INIT_32
#elif defined DET_START_SEC_VAR_NO_INIT_UNSPECIFIED
#undef DET_START_SEC_VAR_NO_INIT_UNSPECIFIED
#define START_SEC_VAR_NO_INIT_UNSPECIFIED
#elif defined DET_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#undef DET_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#define STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#elif defined DET_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
#undef DET_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
#define START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
#elif defined DET_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
#undef DET_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
#define STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
#elif defined DET_START_SEC_VAR_POWER_ON_INIT_BOOLEEPN
#undef DET_START_SEC_VAR_POWER_ON_INIT_BOOLEEPN
#define START_SEC_VAR_POWER_ON_INIT_BOOLEEPN
#elif defined DET_STOP_SEC_VAR_POWER_ON_INIT_BOOLEEPN
#undef DET_STOP_SEC_VAR_POWER_ON_INIT_BOOLEEPN
#define STOP_SEC_VAR_POWER_ON_INIT_BOOLEEPN
#elif defined DET_START_SEC_VAR_POWER_ON_INIT_8BIT
#undef DET_START_SEC_VAR_POWER_ON_INIT_8BIT
#define START_SEC_VAR_POWER_ON_INIT_8
#elif defined DET_STOP_SEC_VAR_POWER_ON_INIT_8BIT
#undef DET_STOP_SEC_VAR_POWER_ON_INIT_8BIT
#define STOP_SEC_VAR_POWER_ON_INIT_8
#elif defined DET_START_SEC_VAR_NO_INIT_16BIT
#undef DET_START_SEC_VAR_NO_INIT_16BIT
#define START_SEC_VAR_NO_INIT_16
#elif defined DET_STOP_SEC_VAR_NO_INIT_16BIT
#undef DET_STOP_SEC_VAR_NO_INIT_16BIT
#define STOP_SEC_VAR_NO_INIT_16
#elif defined DET_START_SEC_DLTRXINDICATION_CALLBACK_CODE
#undef DET_START_SEC_DLTRXINDICATION_CALLBACK_CODE
#define START_SEC_CALLBACK_CODE
#elif defined DET_STOP_SEC_DLTRXINDICATION_CALLBACK_CODE
#undef DET_STOP_SEC_DLTRXINDICATION_CALLBACK_CODE
#define STOP_SEC_CALLBACK_CODE
#elif defined DET_START_SEC_DLTTRIGGERTRANSMIT_CALLBACK_CODE
#undef DET_START_SEC_DLTTRIGGERTRANSMIT_CALLBACK_CODE
#define START_SEC_CALLBACK_CODE
#elif defined DET_STOP_SEC_DLTTRIGGERTRANSMIT_CALLBACK_CODE
#undef DET_STOP_SEC_DLTTRIGGERTRANSMIT_CALLBACK_CODE
#define STOP_SEC_CALLBACK_CODE
#elif defined DET_START_SEC_DLTTXCONFIRMATION_CALLBACK_CODE
#undef DET_START_SEC_DLTTXCONFIRMATION_CALLBACK_CODE
#define START_SEC_CALLBACK_CODE
#elif defined DET_STOP_SEC_DLTTXCONFIRMATION_CALLBACK_CODE
#undef DET_STOP_SEC_DLTTXCONFIRMATION_CALLBACK_CODE
#define STOP_SEC_CALLBACK_CODE
#elif defined DET_START_SEC_DLTTPTXCONFIRMATION_CALLBACK_CODE
#undef DET_START_SEC_DLTTPTXCONFIRMATION_CALLBACK_CODE
#define START_SEC_CALLBACK_CODE
#elif defined DET_STOP_SEC_DLTTPTXCONFIRMATION_CALLBACK_CODE
#undef DET_STOP_SEC_DLTTPTXCONFIRMATION_CALLBACK_CODE
#define STOP_SEC_CALLBACK_CODE
#elif defined DET_START_SEC_DLTCOPYTXDATA_CALLBACK_CODE
#undef DET_START_SEC_DLTCOPYTXDATA_CALLBACK_CODE
#define START_SEC_CALLBACK_CODE
#elif defined DET_STOP_SEC_DLTCOPYTXDATA_CALLBACK_CODE
#undef DET_STOP_SEC_DLTCOPYTXDATA_CALLBACK_CODE
#define STOP_SEC_CALLBACK_CODE
#elif defined DET_START_SEC_DLTSTARTOFRECEPTION_CALLBACK_CODE
#undef DET_START_SEC_DLTSTARTOFRECEPTION_CALLBACK_CODE
#define START_SEC_CALLBACK_CODE
#elif defined DET_STOP_SEC_DLTSTARTOFRECEPTION_CALLBACK_CODE
#undef DET_STOP_SEC_DLTSTARTOFRECEPTION_CALLBACK_CODE
#define STOP_SEC_CALLBACK_CODE
#elif defined DET_START_SEC_DLTTPRXINDICATION_CALLBACK_CODE
#undef DET_START_SEC_DLTTPRXINDICATION_CALLBACK_CODE
#define START_SEC_CALLBACK_CODE
#elif defined DET_STOP_SEC_DLTTPRXINDICATION_CALLBACK_CODE
#undef DET_STOP_SEC_DLTTPRXINDICATION_CALLBACK_CODE
#define STOP_SEC_CALLBACK_CODE
#elif defined DET_START_SEC_DLTCOPYRXDATA_CALLBACK_CODE
#undef DET_START_SEC_DLTCOPYRXDATA_CALLBACK_CODE
#define START_SEC_CALLBACK_CODE
#elif defined DET_STOP_SEC_DLTCOPYRXDATA_CALLBACK_CODE
#undef DET_STOP_SEC_DLTCOPYRXDATA_CALLBACK_CODE
#define STOP_SEC_CALLBACK_CODE
#elif defined DET_START_SEC_CONST_UNSPECIFIED
#undef DET_START_SEC_CONST_UNSPECIFIED
#define START_SEC_CONST_UNSPECIFIED
#elif defined DET_STOP_SEC_CONST_UNSPECIFIED
#undef DET_STOP_SEC_CONST_UNSPECIFIED
#define STOP_SEC_CONST_UNSPECIFIED
#else
//#error "Det not include this section"
#endif

//#include "MemMap.h"
