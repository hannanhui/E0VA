/*
 * File: BackMassage_Model_private.h
 *
 * Code generated for Simulink model 'BackMassage_Model'.
 *
 * Model version                  : 1.3596
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Tue Dec  2 19:46:35 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. MISRA C:2012 guidelines
 *    2. Polyspace
 *    3. ROM efficiency
 *    4. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_BackMassage_Model_private_h_
#define RTW_HEADER_BackMassage_Model_private_h_
#include "rtwtypes.h"
#include "Model_Adapter.h"
#include "BackMassage_Model.h"
#include "BackMassage_Model_types.h"

extern real_T rt_roundd_snf(real_T u);
extern void BackMassage_Mod_Left_Flank_Init(BagState *rty_Out_Bag, boolean_T
  *rty_Out_PumpState, boolean_T *rty_Out_ValvePowerState);
extern void BackMassage_Model_Left_Flank(boolean_T rtu_In_FuncEn, uint32_T
  rtu_In_LumbarPress, uint32_T rtu_In_L_SensorPress, BagState *rty_Out_Bag,
  boolean_T *rty_Out_PumpState, boolean_T *rty_Out_ValvePowerState,
  DW_Left_Flank_BackMassage_Mod_T *localDW);
extern void BackMassage_Mo_Left_Lumbar_Init(BagState *rty_Out_Bag, boolean_T
  *rty_Out_PumpState, boolean_T *rty_Out_ValvePowerState);
extern void BackMassage_Model_Left_Lumbar(boolean_T rtu_In_FuncEn, uint32_T
  rtu_In_LumbarPress, uint32_T rtu_In_L_SensorPress, BagState *rty_Out_Bag,
  boolean_T *rty_Out_PumpState, boolean_T *rty_Out_ValvePowerState,
  DW_Left_Lumbar_BackMassage_Mo_T *localDW);

#endif                             /* RTW_HEADER_BackMassage_Model_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
