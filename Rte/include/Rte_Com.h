/*
 * Rte_Com.h
 *
 *  Created on: 2026年5月19日
 *      Author: Administrator
 */

#ifndef ANGHUI_ASR422_BSW_V1_0_RTE_INCLUDE_RTE_COM_H_
#define ANGHUI_ASR422_BSW_V1_0_RTE_INCLUDE_RTE_COM_H_

#include "Std_Types.h"
#include "Com.h"


#define RTE_RTE_COM_VENDOR_ID             					(0U)
#define RTE_RTE_COM_AR_RELEASE_MAJOR_VERSION      			(4U)
#define RTE_RTE_COM_AR_RELEASE_MINOR_VERSION      			(2U)
#define RTE_RTE_COM_AR_RELEASE_REVISION_VERSION      		(2U)
#define RTE_RTE_COM_SW_MAJOR_VERSION      					(1U)
#define RTE_RTE_COM_SW_MINOR_VERSION      					(2U)
#define RTE_RTE_COM_SW_PATCH_VERSION      					(0U)

void VehModMngtGlbSafe1CarModSts1_Rx(void);

#endif /* ANGHUI_ASR422_BSW_V1_0_RTE_INCLUDE_RTE_COM_H_ */