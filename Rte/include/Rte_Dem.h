/*
 * Rte_Dem.h
 *
 *  Created on: 2026年2月4日
 *      Author: Administrator
 */

#ifndef ANGHUI_ASR422_BSW_V1_0_RTE_INCLUDE_RTE_DEM_H_
#define ANGHUI_ASR422_BSW_V1_0_RTE_INCLUDE_RTE_DEM_H_

#include "Rte_Dem_Type.h"

FUNC(Std_ReturnType, DEM_CODE) Dem_SetEventStatus
(
    Dem_EventIdType EventId,
    Dem_EventStatusType EventStatus
);

FUNC(Std_ReturnType, DEM_CODE) Dem_ResetEventStatus
(
    Dem_EventIdType EventId
);

FUNC(Std_ReturnType, DEM_CODE) Dem_PrestoreFreezeFrame
(
    Dem_EventIdType EventId
);

FUNC(Std_ReturnType, DEM_CODE) Dem_ClearPrestoredFreezeFrame
(
    Dem_EventIdType EventId
);

FUNC(Std_ReturnType, DEM_CODE) Dem_SetOperationCycleState
(
    uint8 OperationCycleId,
    Dem_OperationCycleStateType CycleState
);

FUNC(Std_ReturnType, DEM_CODE) Dem_GetOperationCycleState
(
    uint8 OperationCycleId,
    P2VAR(Dem_OperationCycleStateType, AUTOMATIC, DEM_APPL_DATA) pCycleState
);

FUNC(Std_ReturnType, DEM_CODE) Dem_SetAgingCycleState
(
    uint8 OperationCycleId
);

FUNC(Std_ReturnType, DEM_CODE) Dem_SetWIRStatus
(
    Dem_EventIdType EventId,
    boolean WIRStatus
);

FUNC(Std_ReturnType, DEM_CODE) Dem_GetFaultDetectionCounter
(
    Dem_EventIdType EventId,
    P2VAR(sint8, AUTOMATIC, DEM_CODE) pFaultDetectionCounter
);

FUNC(Dem_ReturnClearDTCType, DEM_CODE)Dem_ClearDTC
(
    uint32 DTC,
    Dem_DTCFormatType DTCFormat,
    Dem_DTCOriginType DTCOrigin
);

FUNC(Dem_ReturnClearDTCType, DEM_CODE)Dem_DcmClearDTC
(
    uint32 DTC,
    Dem_DTCFormatType DTCFormat,
    Dem_DTCOriginType DTCOrigin
);

FUNC(Dem_ReturnControlDTCSettingType, DEM_CODE)Dem_DcmEnableDTCSetting
(
    uint32 DTCGroup,
    Dem_DTCKindType DTCKind
);
#endif /* ANGHUI_ASR422_BSW_V1_0_RTE_INCLUDE_RTE_DEM_H_ */
