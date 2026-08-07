/*******************************************************************************
**                                                                            **
** Copyright (C) 2009-2020, iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.            **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** All rights reserved. This software is iSOFT property. Duplication          **
** or disclosure without iSOFT written authorization is prohibited.           **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : Rte_WdgM_Type.h                                             **
**                                                                            **
**  Created on  : 2022/09/09 15:28:53                          				  **
**  Author      : peng.wu                                                     **
**  Vendor      : iSOFT                                                       **
**  DESCRIPTION : Post-build configuration parameter of WdgM                  **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#ifndef RTE_WDGM_TYPE_H_
#define RTE_WDGM_TYPE_H_

/*===================[type definitions]===========================*/
/* Type of local status for each Supervision entities */
/* DD_2_181 */
typedef  enum
{
    WDGM_LOCAL_STATUS_OK,
    WDGM_LOCAL_STATUS_FAILED,
    WDGM_LOCAL_STATUS_EXPIRED,
    WDGM_LOCAL_STATUS_DEACTIVATED
} WdgM_LocalStatusType;

/* Type of global status */
/* DD_2_181 */
typedef enum
{
    WDGM_GLOBAL_STATUS_OK,
    WDGM_GLOBAL_STATUS_FAILED,
    WDGM_GLOBAL_STATUS_EXPIRED,
    WDGM_GLOBAL_STATUS_STOPPED,
    WDGM_GLOBAL_STATUS_DEACTIVATED
} WdgM_GlobalStatusType;

#endif /* #ifndef  RTE_WDGM_TYPE_H_ */