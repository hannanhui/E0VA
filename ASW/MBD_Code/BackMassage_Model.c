/*
 * File: BackMassage_Model.c
 *
 * Code generated for Simulink model 'BackMassage_Model'.
 *
 * Model version                  : 1.3628
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Tue Dec 30 13:31:20 2025
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

#include "BackMassage_Model.h"
#include "Model_Adapter.h"
#include "rtwtypes.h"
#include "BackMassage_Model_private.h"
#include <math.h>

/* Named constants for Chart: '<S2>/Left_Flank' */
#define BackMassage_Model_IN_Hold_15_10 ((uint8_T)1U)
#define BackMassage_Model_IN_Idle      ((uint8_T)1U)
#define BackMassage_Model_IN_Idle_b    ((uint8_T)2U)
#define BackMassage_Model_IN_Inflation ((uint8_T)1U)
#define BackMassage_Model_IN_Leakage   ((uint8_T)2U)
#define BackMassage_Model_IN_Main      ((uint8_T)1U)
#define BackMassage_Model_IN_Over_30   ((uint8_T)2U)
#define BackMassage_Model_IN_Start     ((uint8_T)2U)
#define BackMassage_Model_IN_hold_15_30 ((uint8_T)3U)
#define BackMassage_Model_IN_main      ((uint8_T)3U)
#define BackMassage__IN_NO_ACTIVE_CHILD ((uint8_T)0U)

/* Named constants for Chart: '<S3>/Left_Lumbar' */
#define BackMassag_IN_NO_ACTIVE_CHILD_p ((uint8_T)0U)
#define BackMassage_Mod_IN_Hold_15_10_h ((uint8_T)1U)
#define BackMassage_Mod_IN_hold_15_30_f ((uint8_T)3U)
#define BackMassage_Mode_IN_Inflation_g ((uint8_T)1U)
#define BackMassage_Model_IN_Idle_o    ((uint8_T)1U)
#define BackMassage_Model_IN_Idle_ox   ((uint8_T)2U)
#define BackMassage_Model_IN_Leakage_e ((uint8_T)2U)
#define BackMassage_Model_IN_Main_a    ((uint8_T)1U)
#define BackMassage_Model_IN_Over_30_i ((uint8_T)2U)
#define BackMassage_Model_IN_Start_m   ((uint8_T)2U)
#define BackMassage_Model_IN_main_o    ((uint8_T)3U)

/* Named constants for Chart: '<Root>/Active_Flank' */
#define BackMassag_IN_NO_ACTIVE_CHILD_g ((uint8_T)0U)
#define BackMassage_Mode_IN_Inflation_n ((uint8_T)1U)
#define BackMassage_Model_IN_IDLE      ((uint8_T)1U)
#define BackMassage_Model_IN_Idle_f    ((uint8_T)1U)
#define BackMassage_Model_IN_Leakage1  ((uint8_T)2U)
#define BackMassage_Model_IN_Leakage_a ((uint8_T)2U)
#define BackMassage_Model_IN_Left_Func ((uint8_T)2U)
#define BackMassage_Model_IN_Main_l    ((uint8_T)2U)
#define BackMassage_Model_IN_Recover   ((uint8_T)2U)
#define BackMassage_Model_IN_Right_Func ((uint8_T)3U)
#define BackMassage_Model_IN_SensorBag ((uint8_T)2U)
#define BackMassage_Model_IN_Start_b   ((uint8_T)3U)
#define BackMassage_Model_IN_Start_bo  ((uint8_T)1U)
#define BackMassage_Model_IN_Step2_1   ((uint8_T)2U)
#define BackMassage_Model_IN_Step3     ((uint8_T)3U)
#define BackMassage_Model_IN_Step3_1   ((uint8_T)1U)
#define BackMassage_Model_IN_Step3_2   ((uint8_T)1U)
#define BackMassage_Model_IN_Step4     ((uint8_T)4U)
#define BackMassage_Model_IN_Step_3_1  ((uint8_T)2U)
#define BackMassage_Model_IN_Test_Func ((uint8_T)4U)
#define BackMassage_Model_IN_idle      ((uint8_T)3U)
#define BackMassage_Model_IN_mid       ((uint8_T)5U)
#define BackMassage_Model_IN_start     ((uint8_T)3U)

/* Named constants for Chart: '<Root>/Function_switch' */
#define BackMassage_Model_IN_Fault     ((uint8_T)1U)
#define BackMassage_Model_IN_Idle_p    ((uint8_T)2U)
#define BackMassage_Model_IN_Run       ((uint8_T)2U)
#define BackMassage_Model_IN_Sensor    ((uint8_T)3U)

/* Named constants for Chart: '<Root>/GasStorage' */
#define BackMassage_Model_IN_Error     ((uint8_T)1U)
#define BackMassage_Model_IN_IDLE_i    ((uint8_T)2U)
#define BackMassage_Model_IN_Run_n     ((uint8_T)3U)
#define BackMassage_Model_IN_start_h   ((uint8_T)1U)
#define BackMassage_Model_IN_stop      ((uint8_T)2U)

/* Named constants for Chart: '<Root>/Massage_of_stateflow' */
#define BackMassa_event_MassageUpdate_t (0)
#define BackMassage_Mod_IN_asynchronous ((uint8_T)3U)
#define BackMassage_Model_IN_Dot       ((uint8_T)1U)
#define BackMassage_Model_IN_Dot_IDLE  ((uint8_T)1U)
#define BackMassage_Model_IN_Dot_run   ((uint8_T)2U)
#define BackMassage_Model_IN_Enable    ((uint8_T)1U)
#define BackMassage_Model_IN_IDLE_d    ((uint8_T)3U)
#define BackMassage_Model_IN_Knock     ((uint8_T)2U)
#define BackMassage_Model_IN_Knock_IDLE ((uint8_T)2U)
#define BackMassage_Model_IN_Leakage_e3 ((uint8_T)3U)
#define BackMassage_Model_IN_Start_f   ((uint8_T)2U)
#define BackMassage_Model_IN_bag1      ((uint8_T)3U)
#define BackMassage_Model_IN_other     ((uint8_T)4U)

/* Named constants for Chart: '<Root>/Passive_Lumbar' */
#define BackMassage_Model_IN_Buffer    ((uint8_T)1U)
#define BackMassage_Model_IN_Deflation ((uint8_T)1U)
#define BackMassage_Model_IN_FWD       ((uint8_T)1U)
#define BackMassage_Model_IN_READY     ((uint8_T)3U)
#define BackMassage_Model_IN_RWD       ((uint8_T)3U)
#define BackMassage_Model_IN_delay     ((uint8_T)2U)
#define BackMassage_Model_IN_down      ((uint8_T)4U)
#define BackMassage_Model_IN_end       ((uint8_T)3U)
#define BackMassage_Model_IN_idle_m    ((uint8_T)2U)
#define BackMassage_Model_IN_up        ((uint8_T)5U)

/* Named constants for Chart: '<Root>/Passive_flank' */
#define BackMassage_Model_IN_Deal      ((uint8_T)1U)
#define BackMassage_Model_IN_Fwd       ((uint8_T)1U)
#define BackMassage_Model_IN_Rwd       ((uint8_T)2U)
#define BackMassage_Model_IN_down_j    ((uint8_T)3U)

/* Block signals (default storage) */
B_BackMassage_Model_T BackMassage_Model_B;

/* Block states (default storage) */
DW_BackMassage_Model_T BackMassage_Model_DW;

/* External outputs (root outports fed by signals with default storage) */
ExtY_BackMassage_Model_T BackMassage_Model_Y;

/* Real-time model */
static RT_MODEL_BackMassage_Model_T BackMassage_Model_M_;
RT_MODEL_BackMassage_Model_T *const BackMassage_Model_M = &BackMassage_Model_M_;

/* Forward declaration for local functions */
static void BackMassage_Model_Sensitivity(uint32_T *Loc_TargetPress);
static boolean_T BackMassage_Model_all(const boolean_T x[2]);
static void BackMassage_M_exit_internal_mid(void);
static void BackMassage_Model_mid(void);
static void BackMassage_Model_Right_Func(const uint32_T *Loc_TargetPress);
static void BackMassag_enter_internal_Step3(void);
static void BackMassage_Model_Step3(void);
static void BackMassage_Model_Test_Func(void);
static void BackMassage__exit_internal_Main(void);
static void BackMassage__enter_internal_mid(void);
static void BackMa_enter_internal_Test_Func(void);
static void BackMassage_M_enter_atomic_IDLE(void);
static void BackMassage_Model_Main(void);
static void BackMass_Reset_GasStorage_Error(void);
static void BackMassage_enter_internal_Deal(void);
static void BackMassage_Model_FWD(void);
static boolean_T BackMassage_Model_any(const boolean_T x[2]);
static void BackMassage_exit_internal_READY(void);
static void BackMassage_M_enter_internal_up(void);
static void BackMassage_enter_internal_down(void);
static void BackMassage_Model_READY(void);
static boolean_T BackMassage_F_MassageTimeUpdata(void);
static void broadcast_MassageUpdate_t_c2_Ba(void);
static void BackMassage_Mode_Asyn_Get_Array(const uint8_T Array[8], boolean_T
  Value, boolean_T Output[8]);
static void BackMassage_Model_List_Legal(uint8_T List_Max);
static void BackMassage_Model_MassageRun(void);
static void BackMassag_exit_internal_Enable(void);
static void BackMassa_enter_internal_Enable(void);
static void BackMassage_Model_Enable(void);
static void BackMassag_c2_BackMassage_Model(void);
static void BackMassage_Model_Func_Init(void);
static void BackMassage_enter_internal_Idle(void);

/*
 * System initialize for atomic system:
 *    '<S2>/Left_Flank'
 *    '<S2>/Right_Flank'
 */
void BackMassage_Mod_Left_Flank_Init(BagState *rty_Out_Bag, boolean_T
  *rty_Out_PumpState, boolean_T *rty_Out_ValvePowerState)
{
  *rty_Out_Bag = BagState_IDLE;
  *rty_Out_PumpState = false;
  *rty_Out_ValvePowerState = false;
}

/*
 * Output and update for atomic system:
 *    '<S2>/Left_Flank'
 *    '<S2>/Right_Flank'
 */
void BackMassage_Model_Left_Flank(boolean_T rtu_In_FuncEn, uint32_T
  rtu_In_LumbarPress, uint32_T rtu_In_L_SensorPress, BagState *rty_Out_Bag,
  boolean_T *rty_Out_PumpState, boolean_T *rty_Out_ValvePowerState,
  DW_Left_Flank_BackMassage_Mod_T *localDW)
{
  if (localDW->temporalCounter_i1 < 2047U) {
    localDW->temporalCounter_i1++;
  }

  /* Chart: '<S2>/Left_Flank' */
  if (localDW->is_active_c15_BackMassage_Model == 0U) {
    localDW->is_active_c15_BackMassage_Model = 1U;
    localDW->is_c15_BackMassage_Model = BackMassage_Model_IN_Start;
    *rty_Out_PumpState = false;
    *rty_Out_ValvePowerState = false;
    *rty_Out_Bag = BagState_IDLE;
  } else if (localDW->is_c15_BackMassage_Model == BackMassage_Model_IN_Main) {
    if (!rtu_In_FuncEn) {
      localDW->is_Inflation = BackMassage__IN_NO_ACTIVE_CHILD;
      localDW->is_Leakage = BackMassage__IN_NO_ACTIVE_CHILD;
      localDW->is_Main = BackMassage__IN_NO_ACTIVE_CHILD;
      localDW->is_c15_BackMassage_Model = BackMassage_Model_IN_Start;
      *rty_Out_PumpState = false;
      *rty_Out_ValvePowerState = false;
      *rty_Out_Bag = BagState_IDLE;
    } else {
      switch (localDW->is_Main) {
       case BackMassage_Model_IN_Inflation:
        if (rtu_In_L_SensorPress > 16000U) {
          localDW->is_Inflation = BackMassage__IN_NO_ACTIVE_CHILD;
          localDW->is_Main = BackMassage_Model_IN_main;
          *rty_Out_PumpState = false;
          *rty_Out_ValvePowerState = false;
          *rty_Out_Bag = BagState_IDLE;
        } else {
          switch (localDW->is_Inflation) {
           case BackMassage_Model_IN_Hold_15_10:
            if ((localDW->temporalCounter_i1 >= 100U) || (rtu_In_LumbarPress >
                 Flank_OverPress)) {
              localDW->is_Inflation = BackMassage_Model_IN_Idle_b;
              *rty_Out_PumpState = false;
              *rty_Out_ValvePowerState = false;
              *rty_Out_Bag = BagState_IDLE;
            } else {
              *rty_Out_PumpState = true;
              *rty_Out_ValvePowerState = true;
              *rty_Out_Bag = BagState_Inflation;
            }
            break;

           default:
            /* case IN_Idle: */
            *rty_Out_PumpState = false;
            *rty_Out_ValvePowerState = false;
            *rty_Out_Bag = BagState_IDLE;
            break;
          }
        }
        break;

       case BackMassage_Model_IN_Leakage:
        if ((rtu_In_L_SensorPress < 14000U) && (localDW->LeakageState != 2)) {
          localDW->is_Leakage = BackMassage__IN_NO_ACTIVE_CHILD;
          localDW->is_Main = BackMassage_Model_IN_Inflation;
          localDW->is_Inflation = BackMassage_Model_IN_Hold_15_10;
          localDW->temporalCounter_i1 = 0U;
          *rty_Out_PumpState = true;
          *rty_Out_ValvePowerState = true;
          *rty_Out_Bag = BagState_Inflation;
        } else {
          switch (localDW->is_Leakage) {
           case BackMassage_Model_IN_Idle:
            if ((rtu_In_L_SensorPress > 28000U) && (rtu_In_LumbarPress > 3000U))
            {
              localDW->is_Leakage = BackMassage_Model_IN_Over_30;
              localDW->temporalCounter_i1 = 0U;
              localDW->LeakageState = 2U;
              *rty_Out_PumpState = false;
              *rty_Out_ValvePowerState = true;
              *rty_Out_Bag = BagState_Leakage;
            } else {
              localDW->LeakageState = 0U;
              *rty_Out_PumpState = false;
              *rty_Out_ValvePowerState = false;
              *rty_Out_Bag = BagState_IDLE;
            }
            break;

           case BackMassage_Model_IN_Over_30:
            if ((rtu_In_L_SensorPress < 14000U) || (localDW->temporalCounter_i1 >=
                 2000U)) {
              localDW->is_Leakage = BackMassage__IN_NO_ACTIVE_CHILD;
              localDW->is_Main = BackMassage_Model_IN_main;
              *rty_Out_PumpState = false;
              *rty_Out_ValvePowerState = false;
              *rty_Out_Bag = BagState_IDLE;
            } else {
              localDW->LeakageState = 2U;
              *rty_Out_PumpState = false;
              *rty_Out_ValvePowerState = true;
              *rty_Out_Bag = BagState_Leakage;
            }
            break;

           default:
            /* case IN_hold_15_30: */
            if ((localDW->temporalCounter_i1 >= 50U) && (rtu_In_L_SensorPress >
                 28000U)) {
              localDW->is_Leakage = BackMassage_Model_IN_Over_30;
              localDW->temporalCounter_i1 = 0U;
              localDW->LeakageState = 2U;
              *rty_Out_PumpState = false;
              *rty_Out_ValvePowerState = true;
              *rty_Out_Bag = BagState_Leakage;
            } else if (localDW->temporalCounter_i1 >= 100U) {
              localDW->is_Leakage = BackMassage_Model_IN_Idle;
              localDW->LeakageState = 0U;
              *rty_Out_PumpState = false;
              *rty_Out_ValvePowerState = false;
              *rty_Out_Bag = BagState_IDLE;
            } else {
              localDW->LeakageState = 1U;
              *rty_Out_PumpState = false;
              *rty_Out_ValvePowerState = true;
              *rty_Out_Bag = BagState_Leakage;
            }
            break;
          }
        }
        break;

       default:
        /* case IN_main: */
        if (rtu_In_L_SensorPress > 15000U) {
          localDW->is_Main = BackMassage_Model_IN_Leakage;
          localDW->is_Leakage = BackMassage_Model_IN_hold_15_30;
          localDW->temporalCounter_i1 = 0U;
          localDW->LeakageState = 1U;
          *rty_Out_PumpState = false;
          *rty_Out_ValvePowerState = true;
          *rty_Out_Bag = BagState_Leakage;
        } else {
          *rty_Out_PumpState = false;
          *rty_Out_ValvePowerState = false;
          *rty_Out_Bag = BagState_IDLE;
        }
        break;
      }
    }

    /* case IN_Start: */
  } else if (rtu_In_FuncEn) {
    localDW->is_c15_BackMassage_Model = BackMassage_Model_IN_Main;
    localDW->is_Main = BackMassage_Model_IN_main;
    *rty_Out_PumpState = false;
    *rty_Out_ValvePowerState = false;
    *rty_Out_Bag = BagState_IDLE;
  } else {
    *rty_Out_PumpState = false;
    *rty_Out_ValvePowerState = false;
    *rty_Out_Bag = BagState_IDLE;
  }

  /* End of Chart: '<S2>/Left_Flank' */
}

/*
 * System initialize for atomic system:
 *    '<S3>/Left_Lumbar'
 *    '<S3>/Right_Lumbar'
 */
void BackMassage_Mo_Left_Lumbar_Init(BagState *rty_Out_Bag, boolean_T
  *rty_Out_PumpState, boolean_T *rty_Out_ValvePowerState)
{
  *rty_Out_Bag = BagState_IDLE;
  *rty_Out_PumpState = false;
  *rty_Out_ValvePowerState = false;
}

/*
 * Output and update for atomic system:
 *    '<S3>/Left_Lumbar'
 *    '<S3>/Right_Lumbar'
 */
void BackMassage_Model_Left_Lumbar(boolean_T rtu_In_FuncEn, uint32_T
  rtu_In_LumbarPress, uint32_T rtu_In_L_SensorPress, BagState *rty_Out_Bag,
  boolean_T *rty_Out_PumpState, boolean_T *rty_Out_ValvePowerState,
  DW_Left_Lumbar_BackMassage_Mo_T *localDW)
{
  if (localDW->temporalCounter_i1 < 2047U) {
    localDW->temporalCounter_i1++;
  }

  /* Chart: '<S3>/Left_Lumbar' */
  if (localDW->is_active_c5_BackMassage_Model == 0U) {
    localDW->is_active_c5_BackMassage_Model = 1U;
    localDW->is_c5_BackMassage_Model = BackMassage_Model_IN_Start_m;
    *rty_Out_PumpState = false;
    *rty_Out_ValvePowerState = false;
    *rty_Out_Bag = BagState_IDLE;
  } else if (localDW->is_c5_BackMassage_Model == BackMassage_Model_IN_Main_a) {
    if (!rtu_In_FuncEn) {
      localDW->is_Inflation = BackMassag_IN_NO_ACTIVE_CHILD_p;
      localDW->is_Leakage = BackMassag_IN_NO_ACTIVE_CHILD_p;
      localDW->is_Main = BackMassag_IN_NO_ACTIVE_CHILD_p;
      localDW->is_c5_BackMassage_Model = BackMassage_Model_IN_Start_m;
      *rty_Out_PumpState = false;
      *rty_Out_ValvePowerState = false;
      *rty_Out_Bag = BagState_IDLE;
    } else {
      switch (localDW->is_Main) {
       case BackMassage_Mode_IN_Inflation_g:
        if (rtu_In_L_SensorPress > 16000U) {
          localDW->is_Inflation = BackMassag_IN_NO_ACTIVE_CHILD_p;
          localDW->is_Main = BackMassage_Model_IN_main_o;
          *rty_Out_PumpState = false;
          *rty_Out_ValvePowerState = false;
          *rty_Out_Bag = BagState_IDLE;
        } else {
          switch (localDW->is_Inflation) {
           case BackMassage_Mod_IN_Hold_15_10_h:
            if ((localDW->temporalCounter_i1 >= 100U) || (rtu_In_LumbarPress >
                 45000U)) {
              localDW->is_Inflation = BackMassage_Model_IN_Idle_ox;
              *rty_Out_PumpState = false;
              *rty_Out_ValvePowerState = false;
              *rty_Out_Bag = BagState_IDLE;
            } else {
              *rty_Out_PumpState = true;
              *rty_Out_ValvePowerState = true;
              *rty_Out_Bag = BagState_Inflation;
            }
            break;

           default:
            /* case IN_Idle: */
            *rty_Out_PumpState = false;
            *rty_Out_ValvePowerState = false;
            *rty_Out_Bag = BagState_IDLE;
            break;
          }
        }
        break;

       case BackMassage_Model_IN_Leakage_e:
        if ((rtu_In_L_SensorPress < 14000U) && (localDW->LeakageState != 2)) {
          localDW->is_Leakage = BackMassag_IN_NO_ACTIVE_CHILD_p;
          localDW->is_Main = BackMassage_Mode_IN_Inflation_g;
          localDW->is_Inflation = BackMassage_Mod_IN_Hold_15_10_h;
          localDW->temporalCounter_i1 = 0U;
          *rty_Out_PumpState = true;
          *rty_Out_ValvePowerState = true;
          *rty_Out_Bag = BagState_Inflation;
        } else {
          switch (localDW->is_Leakage) {
           case BackMassage_Model_IN_Idle_o:
            if ((rtu_In_L_SensorPress > 28000U) && (rtu_In_LumbarPress > 3000U))
            {
              localDW->is_Leakage = BackMassage_Model_IN_Over_30_i;
              localDW->temporalCounter_i1 = 0U;
              localDW->LeakageState = 2U;
              *rty_Out_PumpState = false;
              *rty_Out_ValvePowerState = true;
              *rty_Out_Bag = BagState_Leakage;
            } else {
              localDW->LeakageState = 0U;
              *rty_Out_PumpState = false;
              *rty_Out_ValvePowerState = false;
              *rty_Out_Bag = BagState_IDLE;
            }
            break;

           case BackMassage_Model_IN_Over_30_i:
            if ((rtu_In_L_SensorPress < 14000U) || (localDW->temporalCounter_i1 >=
                 2000U)) {
              localDW->is_Leakage = BackMassag_IN_NO_ACTIVE_CHILD_p;
              localDW->is_Main = BackMassage_Model_IN_main_o;
              *rty_Out_PumpState = false;
              *rty_Out_ValvePowerState = false;
              *rty_Out_Bag = BagState_IDLE;
            } else {
              localDW->LeakageState = 2U;
              *rty_Out_PumpState = false;
              *rty_Out_ValvePowerState = true;
              *rty_Out_Bag = BagState_Leakage;
            }
            break;

           default:
            /* case IN_hold_15_30: */
            if ((localDW->temporalCounter_i1 >= 50U) && (rtu_In_L_SensorPress >
                 28000U)) {
              localDW->is_Leakage = BackMassage_Model_IN_Over_30_i;
              localDW->temporalCounter_i1 = 0U;
              localDW->LeakageState = 2U;
              *rty_Out_PumpState = false;
              *rty_Out_ValvePowerState = true;
              *rty_Out_Bag = BagState_Leakage;
            } else if (localDW->temporalCounter_i1 >= 100U) {
              localDW->is_Leakage = BackMassage_Model_IN_Idle_o;
              localDW->LeakageState = 0U;
              *rty_Out_PumpState = false;
              *rty_Out_ValvePowerState = false;
              *rty_Out_Bag = BagState_IDLE;
            } else {
              localDW->LeakageState = 1U;
              *rty_Out_PumpState = false;
              *rty_Out_ValvePowerState = true;
              *rty_Out_Bag = BagState_Leakage;
            }
            break;
          }
        }
        break;

       default:
        /* case IN_main: */
        if (rtu_In_L_SensorPress > 15000U) {
          localDW->is_Main = BackMassage_Model_IN_Leakage_e;
          localDW->is_Leakage = BackMassage_Mod_IN_hold_15_30_f;
          localDW->temporalCounter_i1 = 0U;
          localDW->LeakageState = 1U;
          *rty_Out_PumpState = false;
          *rty_Out_ValvePowerState = true;
          *rty_Out_Bag = BagState_Leakage;
        } else {
          *rty_Out_PumpState = false;
          *rty_Out_ValvePowerState = false;
          *rty_Out_Bag = BagState_IDLE;
        }
        break;
      }
    }

    /* case IN_Start: */
  } else if (rtu_In_FuncEn) {
    localDW->is_c5_BackMassage_Model = BackMassage_Model_IN_Main_a;
    localDW->is_Main = BackMassage_Model_IN_main_o;
    *rty_Out_PumpState = false;
    *rty_Out_ValvePowerState = false;
    *rty_Out_Bag = BagState_IDLE;
  } else {
    *rty_Out_PumpState = false;
    *rty_Out_ValvePowerState = false;
    *rty_Out_Bag = BagState_IDLE;
  }

  /* End of Chart: '<S3>/Left_Lumbar' */
}

/* Function for Chart: '<Root>/Active_Flank' */
static void BackMassage_Model_Sensitivity(uint32_T *Loc_TargetPress)
{
  /* Inport: '<Root>/In_ActiveFlankSensitivity' */
  switch (AppInto_ActiveFlankSensitivity) {
   case 0:
    *Loc_TargetPress = 28000U;
    break;

   case 1:
    *Loc_TargetPress = 33000U;
    break;

   case 2:
    *Loc_TargetPress = 38000U;
    break;

   default:
    *Loc_TargetPress = 28000U;
    break;
  }

  /* End of Inport: '<Root>/In_ActiveFlankSensitivity' */
}

/* Function for Chart: '<Root>/Active_Flank' */
static boolean_T BackMassage_Model_all(const boolean_T x[2])
{
  int32_T k;
  boolean_T exitg1;
  boolean_T y;
  y = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (!x[k]) {
      y = false;
      exitg1 = true;
    } else {
      k++;
    }
  }

  return y;
}

/* Function for Chart: '<Root>/Active_Flank' */
static void BackMassage_M_exit_internal_mid(void)
{
  BackMassage_Model_DW.is_Recover_p = BackMassag_IN_NO_ACTIVE_CHILD_g;
  BackMassage_Model_DW.is_RightBag = BackMassag_IN_NO_ACTIVE_CHILD_g;
  BackMassage_Model_DW.is_Recover = BackMassag_IN_NO_ACTIVE_CHILD_g;
  BackMassage_Model_DW.is_LeftBag = BackMassag_IN_NO_ACTIVE_CHILD_g;
}

/* Function for Chart: '<Root>/Active_Flank' */
static void BackMassage_Model_mid(void)
{
  boolean_T tmp[2];
  tmp[0] = ((int32_T)BackMassage_Model_B.Out_FlankBag[0] == 0);
  tmp[1] = ((int32_T)BackMassage_Model_B.Out_FlankBag[1] == 0);
  if (!BackMassage_Model_all(tmp)) {
    BackMassage_Model_DW.durationCounter_1_c = 0;
  }

  if (BackMassage_Model_DW.durationCounter_1_c > 200) {
    BackMassage_M_exit_internal_mid();
    BackMassage_Model_DW.is_Main = BackMassage_Model_IN_Idle_f;
    BackMassage_Model_B.Out_FlankBag[0] = BagState_IDLE;
    tmp[0] = ((int32_T)BackMassage_Model_B.Out_FlankBag[0] == 0);
    BackMassage_Model_B.Out_FlankBag[1] = BagState_IDLE;
    tmp[1] = ((int32_T)BackMassage_Model_B.Out_FlankBag[1] == 0);
    if (!BackMassage_Model_all(tmp)) {
      BackMassage_Model_DW.durationCounter_1_c = 0;
      BackMassage_Model_DW.durationCounter_1_e = 0;
      BackMassage_Model_DW.durationCounter_1_g = 0;
    }

    BackMassage_Model_DW.is_Idle = BackMassage_Model_IN_IDLE;
    BackMassage_Model_DW.App_RunState.GasStorage = false;
    BackMassage_Model_B.Out_GasStorage = false;
    BackMassage_Model_B.Out_PumpState_j[0] = false;
    BackMassage_Model_B.Out_ValvePower[0] = false;
    BackMassage_Model_B.Out_PumpState_j[1] = false;
    BackMassage_Model_B.Out_ValvePower[1] = false;
  } else {
    switch (BackMassage_Model_DW.is_LeftBag) {
     case BackMassage_Model_IN_IDLE:
      break;

     default:
      /* Inport: '<Root>/In_FlankPress' */
      /* case IN_Recover: */
      if ((AppInto_FlankPress[0] == BackMassage_Model_DW.Loc_FlankPress_Save[0])
          || (BackMassage_Model_DW.temporalCounter_i1_b >= 2000U)) {
        BackMassage_Model_DW.is_Recover = BackMassag_IN_NO_ACTIVE_CHILD_g;
        BackMassage_Model_DW.is_LeftBag = BackMassage_Model_IN_IDLE;
        BackMassage_Model_B.Out_ValvePower[0] = false;
        BackMassage_Model_B.Out_PumpState_j[0] = false;
        BackMassage_Model_B.Out_FlankBag[0] = BagState_IDLE;
        tmp[0] = ((int32_T)BackMassage_Model_B.Out_FlankBag[0] == 0);
        tmp[1] = ((int32_T)BackMassage_Model_B.Out_FlankBag[1] == 0);
        if (!BackMassage_Model_all(tmp)) {
          BackMassage_Model_DW.durationCounter_1_c = 0;
          BackMassage_Model_DW.durationCounter_1_e = 0;
          BackMassage_Model_DW.durationCounter_1_g = 0;
        }
      } else {
        switch (BackMassage_Model_DW.is_Recover) {
         case BackMassage_Mode_IN_Inflation_n:
          if (AppInto_FlankPress[0] > BackMassage_Model_DW.Loc_FlankPress_Save[0])
          {
            BackMassage_Model_DW.is_Recover = BackMassag_IN_NO_ACTIVE_CHILD_g;
            BackMassage_Model_DW.is_LeftBag = BackMassage_Model_IN_IDLE;
            BackMassage_Model_B.Out_ValvePower[0] = false;
            BackMassage_Model_B.Out_PumpState_j[0] = false;
            BackMassage_Model_B.Out_FlankBag[0] = BagState_IDLE;
            tmp[0] = ((int32_T)BackMassage_Model_B.Out_FlankBag[0] == 0);
            tmp[1] = ((int32_T)BackMassage_Model_B.Out_FlankBag[1] == 0);
            if (!BackMassage_Model_all(tmp)) {
              BackMassage_Model_DW.durationCounter_1_c = 0;
              BackMassage_Model_DW.durationCounter_1_e = 0;
              BackMassage_Model_DW.durationCounter_1_g = 0;
            }
          } else {
            BackMassage_Model_B.Out_PumpState_j[0] = true;
            BackMassage_Model_B.Out_FlankBag[0] = BagState_Inflation;
            tmp[0] = ((int32_T)BackMassage_Model_B.Out_FlankBag[0] == 0);
            tmp[1] = ((int32_T)BackMassage_Model_B.Out_FlankBag[1] == 0);
            if (!BackMassage_Model_all(tmp)) {
              BackMassage_Model_DW.durationCounter_1_c = 0;
              BackMassage_Model_DW.durationCounter_1_e = 0;
              BackMassage_Model_DW.durationCounter_1_g = 0;
            }
          }
          break;

         case BackMassage_Model_IN_Leakage_a:
          if (AppInto_FlankPress[0] <= BackMassage_Model_DW.Loc_FlankPress_Save
              [0]) {
            BackMassage_Model_DW.is_Recover = BackMassag_IN_NO_ACTIVE_CHILD_g;
            BackMassage_Model_DW.is_LeftBag = BackMassage_Model_IN_IDLE;
            BackMassage_Model_B.Out_ValvePower[0] = false;
            BackMassage_Model_B.Out_PumpState_j[0] = false;
            BackMassage_Model_B.Out_FlankBag[0] = BagState_IDLE;
            tmp[0] = ((int32_T)BackMassage_Model_B.Out_FlankBag[0] == 0);
            tmp[1] = ((int32_T)BackMassage_Model_B.Out_FlankBag[1] == 0);
            if (!BackMassage_Model_all(tmp)) {
              BackMassage_Model_DW.durationCounter_1_c = 0;
              BackMassage_Model_DW.durationCounter_1_e = 0;
              BackMassage_Model_DW.durationCounter_1_g = 0;
            }
          } else {
            BackMassage_Model_B.Out_PumpState_j[0] = false;
            BackMassage_Model_B.Out_FlankBag[0] = BagState_Leakage;
            tmp[0] = ((int32_T)BackMassage_Model_B.Out_FlankBag[0] == 0);
            tmp[1] = ((int32_T)BackMassage_Model_B.Out_FlankBag[1] == 0);
            if (!BackMassage_Model_all(tmp)) {
              BackMassage_Model_DW.durationCounter_1_c = 0;
              BackMassage_Model_DW.durationCounter_1_e = 0;
              BackMassage_Model_DW.durationCounter_1_g = 0;
            }
          }
          break;

         default:
          /* case IN_start: */
          if (AppInto_FlankPress[0] > BackMassage_Model_DW.Loc_FlankPress_Save[0])
          {
            BackMassage_Model_DW.is_Recover = BackMassage_Model_IN_Leakage_a;
          } else if (AppInto_FlankPress[0] <
                     BackMassage_Model_DW.Loc_FlankPress_Save[0]) {
            BackMassage_Model_DW.is_Recover = BackMassage_Mode_IN_Inflation_n;
          }
          break;
        }
      }
      break;
    }

    switch (BackMassage_Model_DW.is_RightBag) {
     case BackMassage_Model_IN_IDLE:
      break;

     default:
      /* Inport: '<Root>/In_FlankPress' */
      /* case IN_Recover: */
      if ((AppInto_FlankPress[1] == BackMassage_Model_DW.Loc_FlankPress_Save[1])
          || (BackMassage_Model_DW.temporalCounter_i2_a >= 2000U)) {
        BackMassage_Model_DW.is_Recover_p = BackMassag_IN_NO_ACTIVE_CHILD_g;
        BackMassage_Model_DW.is_RightBag = BackMassage_Model_IN_IDLE;
        BackMassage_Model_B.Out_ValvePower[1] = false;
        BackMassage_Model_B.Out_PumpState_j[1] = false;
        BackMassage_Model_B.Out_FlankBag[1] = BagState_IDLE;
        tmp[0] = ((int32_T)BackMassage_Model_B.Out_FlankBag[0] == 0);
        tmp[1] = ((int32_T)BackMassage_Model_B.Out_FlankBag[1] == 0);
        if (!BackMassage_Model_all(tmp)) {
          BackMassage_Model_DW.durationCounter_1_c = 0;
          BackMassage_Model_DW.durationCounter_1_e = 0;
          BackMassage_Model_DW.durationCounter_1_g = 0;
        }
      } else {
        switch (BackMassage_Model_DW.is_Recover_p) {
         case BackMassage_Mode_IN_Inflation_n:
          if (AppInto_FlankPress[1] > BackMassage_Model_DW.Loc_FlankPress_Save[1])
          {
            BackMassage_Model_DW.is_Recover_p = BackMassag_IN_NO_ACTIVE_CHILD_g;
            BackMassage_Model_DW.is_RightBag = BackMassage_Model_IN_IDLE;
            BackMassage_Model_B.Out_ValvePower[1] = false;
            BackMassage_Model_B.Out_PumpState_j[1] = false;
            BackMassage_Model_B.Out_FlankBag[1] = BagState_IDLE;
            tmp[0] = ((int32_T)BackMassage_Model_B.Out_FlankBag[0] == 0);
            tmp[1] = ((int32_T)BackMassage_Model_B.Out_FlankBag[1] == 0);
            if (!BackMassage_Model_all(tmp)) {
              BackMassage_Model_DW.durationCounter_1_c = 0;
              BackMassage_Model_DW.durationCounter_1_e = 0;
              BackMassage_Model_DW.durationCounter_1_g = 0;
            }
          } else {
            BackMassage_Model_B.Out_PumpState_j[1] = true;
            BackMassage_Model_B.Out_FlankBag[1] = BagState_Inflation;
            tmp[0] = ((int32_T)BackMassage_Model_B.Out_FlankBag[0] == 0);
            tmp[1] = ((int32_T)BackMassage_Model_B.Out_FlankBag[1] == 0);
            if (!BackMassage_Model_all(tmp)) {
              BackMassage_Model_DW.durationCounter_1_c = 0;
              BackMassage_Model_DW.durationCounter_1_e = 0;
              BackMassage_Model_DW.durationCounter_1_g = 0;
            }
          }
          break;

         case BackMassage_Model_IN_Leakage1:
          if (AppInto_FlankPress[1] <= BackMassage_Model_DW.Loc_FlankPress_Save
              [1]) {
            BackMassage_Model_DW.is_Recover_p = BackMassag_IN_NO_ACTIVE_CHILD_g;
            BackMassage_Model_DW.is_RightBag = BackMassage_Model_IN_IDLE;
            BackMassage_Model_B.Out_ValvePower[1] = false;
            BackMassage_Model_B.Out_PumpState_j[1] = false;
            BackMassage_Model_B.Out_FlankBag[1] = BagState_IDLE;
            tmp[0] = ((int32_T)BackMassage_Model_B.Out_FlankBag[0] == 0);
            tmp[1] = ((int32_T)BackMassage_Model_B.Out_FlankBag[1] == 0);
            if (!BackMassage_Model_all(tmp)) {
              BackMassage_Model_DW.durationCounter_1_c = 0;
              BackMassage_Model_DW.durationCounter_1_e = 0;
              BackMassage_Model_DW.durationCounter_1_g = 0;
            }
          } else {
            BackMassage_Model_B.Out_PumpState_j[1] = false;
            BackMassage_Model_B.Out_FlankBag[1] = BagState_Leakage;
            tmp[0] = ((int32_T)BackMassage_Model_B.Out_FlankBag[0] == 0);
            tmp[1] = ((int32_T)BackMassage_Model_B.Out_FlankBag[1] == 0);
            if (!BackMassage_Model_all(tmp)) {
              BackMassage_Model_DW.durationCounter_1_c = 0;
              BackMassage_Model_DW.durationCounter_1_e = 0;
              BackMassage_Model_DW.durationCounter_1_g = 0;
            }
          }
          break;

         default:
          /* case IN_Start: */
          if (AppInto_FlankPress[1] > BackMassage_Model_DW.Loc_FlankPress_Save[1])
          {
            BackMassage_Model_DW.is_Recover_p = BackMassage_Model_IN_Leakage1;
          } else if (AppInto_FlankPress[1] <
                     BackMassage_Model_DW.Loc_FlankPress_Save[1]) {
            BackMassage_Model_DW.is_Recover_p = BackMassage_Mode_IN_Inflation_n;
          }
          break;
        }
      }
      break;
    }
  }
}

/* Function for Chart: '<Root>/Active_Flank' */
static void BackMassage_Model_Right_Func(const uint32_T *Loc_TargetPress)
{
  boolean_T tmp[2];
  tmp[0] = ((int32_T)BackMassage_Model_B.Out_FlankBag[0] == 0);
  tmp[1] = ((int32_T)BackMassage_Model_B.Out_FlankBag[1] == 0);
  if (!BackMassage_Model_all(tmp)) {
    BackMassage_Model_DW.durationCounter_1_g = 0;
  }

  if (BackMassage_Model_DW.durationCounter_1_g > 200) {
    BackMassage_Model_DW.is_Right_Func = BackMassag_IN_NO_ACTIVE_CHILD_g;
    BackMassage_Model_DW.is_Main = BackMassage_Model_IN_Idle_f;
    BackMassage_Model_B.Out_FlankBag[0] = BagState_IDLE;
    tmp[0] = ((int32_T)BackMassage_Model_B.Out_FlankBag[0] == 0);
    BackMassage_Model_B.Out_FlankBag[1] = BagState_IDLE;
    tmp[1] = ((int32_T)BackMassage_Model_B.Out_FlankBag[1] == 0);
    if (!BackMassage_Model_all(tmp)) {
      BackMassage_Model_DW.durationCounter_1_c = 0;
      BackMassage_Model_DW.durationCounter_1_e = 0;
      BackMassage_Model_DW.durationCounter_1_g = 0;
    }

    BackMassage_Model_DW.is_Idle = BackMassage_Model_IN_IDLE;
    BackMassage_Model_DW.App_RunState.GasStorage = false;
    BackMassage_Model_B.Out_GasStorage = false;
    BackMassage_Model_B.Out_PumpState_j[0] = false;
    BackMassage_Model_B.Out_ValvePower[0] = false;
    BackMassage_Model_B.Out_PumpState_j[1] = false;
    BackMassage_Model_B.Out_ValvePower[1] = false;
  } else {
    switch (BackMassage_Model_DW.is_Right_Func) {
     case BackMassage_Model_IN_IDLE:
      /* Inport: '<Root>/In_FlankPress' */
      if (AppInto_FlankPress[0] >= *Loc_TargetPress) {
        BackMassage_Model_DW.is_Right_Func = BackMassage_Model_IN_idle;
        BackMassage_Model_DW.temporalCounter_i1_b = 0U;
        BackMassage_Model_B.Out_PumpState_j[0] = false;
        BackMassage_Model_B.Out_FlankBag[0] = BagState_IDLE;
        tmp[0] = ((int32_T)BackMassage_Model_B.Out_FlankBag[0] == 0);
        BackMassage_Model_B.Out_PumpState_j[1] = false;
        BackMassage_Model_B.Out_FlankBag[1] = BagState_IDLE;
        tmp[1] = ((int32_T)BackMassage_Model_B.Out_FlankBag[1] == 0);
        if (!BackMassage_Model_all(tmp)) {
          BackMassage_Model_DW.durationCounter_1_c = 0;
          BackMassage_Model_DW.durationCounter_1_e = 0;
          BackMassage_Model_DW.durationCounter_1_g = 0;
        }
      } else if (AppInto_FlankPress[0] < *Loc_TargetPress) {
        BackMassage_Model_DW.is_Right_Func = BackMassage_Model_IN_Leakage_a;
        BackMassage_Model_DW.temporalCounter_i1_b = 0U;
        BackMassage_Model_B.Out_FlankBag[0] = BagState_Inflation;
        BackMassage_Model_B.Out_ValvePower[0] = true;
        BackMassage_Model_B.Out_PumpState_j[0] = true;
        tmp[0] = ((int32_T)BackMassage_Model_B.Out_FlankBag[0] == 0);
        BackMassage_Model_B.Out_ValvePower[1] = true;
        BackMassage_Model_B.Out_PumpState_j[1] = true;
        tmp[1] = ((int32_T)BackMassage_Model_B.Out_FlankBag[1] == 0);
        if (!BackMassage_Model_all(tmp)) {
          BackMassage_Model_DW.durationCounter_1_c = 0;
          BackMassage_Model_DW.durationCounter_1_e = 0;
          BackMassage_Model_DW.durationCounter_1_g = 0;
        }

        BackMassage_Model_B.Out_FlankBag[1] = BagState_IDLE;
        tmp[0] = ((int32_T)BackMassage_Model_B.Out_FlankBag[0] == 0);
        tmp[1] = ((int32_T)BackMassage_Model_B.Out_FlankBag[1] == 0);
        if (!BackMassage_Model_all(tmp)) {
          BackMassage_Model_DW.durationCounter_1_c = 0;
          BackMassage_Model_DW.durationCounter_1_e = 0;
          BackMassage_Model_DW.durationCounter_1_g = 0;
        }
      }

      /* End of Inport: '<Root>/In_FlankPress' */
      break;

     case BackMassage_Model_IN_Leakage_a:
      if ((BackMassage_Model_DW.temporalCounter_i1_b * 10 >= ((uint16_T)
            MaxInflation_T)) || (AppInto_FlankPress[0] >= *Loc_TargetPress)) {
        BackMassage_Model_DW.is_Right_Func = BackMassage_Model_IN_idle;
        BackMassage_Model_DW.temporalCounter_i1_b = 0U;
        BackMassage_Model_B.Out_PumpState_j[0] = false;
        BackMassage_Model_B.Out_FlankBag[0] = BagState_IDLE;
        tmp[0] = ((int32_T)BackMassage_Model_B.Out_FlankBag[0] == 0);
        BackMassage_Model_B.Out_PumpState_j[1] = false;
        BackMassage_Model_B.Out_FlankBag[1] = BagState_IDLE;
        tmp[1] = ((int32_T)BackMassage_Model_B.Out_FlankBag[1] == 0);
        if (!BackMassage_Model_all(tmp)) {
          BackMassage_Model_DW.durationCounter_1_c = 0;
          BackMassage_Model_DW.durationCounter_1_e = 0;
          BackMassage_Model_DW.durationCounter_1_g = 0;
        }
      } else {
        BackMassage_Model_B.Out_FlankBag[0] = BagState_Inflation;
        BackMassage_Model_B.Out_ValvePower[0] = true;
        BackMassage_Model_B.Out_PumpState_j[0] = true;
        tmp[0] = ((int32_T)BackMassage_Model_B.Out_FlankBag[0] == 0);
        BackMassage_Model_B.Out_ValvePower[1] = true;
        BackMassage_Model_B.Out_PumpState_j[1] = true;
        tmp[1] = ((int32_T)BackMassage_Model_B.Out_FlankBag[1] == 0);
        if (!BackMassage_Model_all(tmp)) {
          BackMassage_Model_DW.durationCounter_1_c = 0;
          BackMassage_Model_DW.durationCounter_1_e = 0;
          BackMassage_Model_DW.durationCounter_1_g = 0;
        }

        BackMassage_Model_B.Out_FlankBag[1] = BagState_IDLE;
        tmp[0] = ((int32_T)BackMassage_Model_B.Out_FlankBag[0] == 0);
        tmp[1] = ((int32_T)BackMassage_Model_B.Out_FlankBag[1] == 0);
        if (!BackMassage_Model_all(tmp)) {
          BackMassage_Model_DW.durationCounter_1_c = 0;
          BackMassage_Model_DW.durationCounter_1_e = 0;
          BackMassage_Model_DW.durationCounter_1_g = 0;
        }

        BackMassage_Model_B.Out_GasStorage =
          ((BackMassage_Model_DW.temporalCounter_i1_b >= 20U) ||
           BackMassage_Model_B.Out_GasStorage);
      }
      break;

     default:
      /* case IN_idle: */
      if (BackMassage_Model_DW.temporalCounter_i1_b >= 20U) {
        BackMassage_Model_B.Out_GasStorage = false;
        BackMassage_Model_B.Out_ValvePower[0] = false;
        BackMassage_Model_B.Out_ValvePower[1] = false;
      }
      break;
    }
  }
}

/* Function for Chart: '<Root>/Active_Flank' */
static void BackMassag_enter_internal_Step3(void)
{
  boolean_T tmp[2];
  BackMassage_Model_DW.is_Step3 = BackMassage_Model_IN_Step_3_1;
  BackMassage_Model_DW.temporalCounter_i1_b = 0U;
  BackMassage_Model_DW.App_RunState.GasStorage = true;
  BackMassage_Model_B.Out_GasStorage = true;
  BackMassage_Model_B.Out_FlankBag[1] = BagState_Inflation;
  BackMassage_Model_B.Out_PumpState_j[0] = true;
  tmp[0] = ((int32_T)BackMassage_Model_B.Out_FlankBag[0] == 0);
  BackMassage_Model_B.Out_PumpState_j[1] = true;
  tmp[1] = ((int32_T)BackMassage_Model_B.Out_FlankBag[1] == 0);
  if (!BackMassage_Model_all(tmp)) {
    BackMassage_Model_DW.durationCounter_1_c = 0;
    BackMassage_Model_DW.durationCounter_1_e = 0;
    BackMassage_Model_DW.durationCounter_1_g = 0;
  }
}

/* Function for Chart: '<Root>/Active_Flank' */
static void BackMassage_Model_Step3(void)
{
  boolean_T tmp[2];
  if (BackMassage_Model_DW.temporalCounter_i2_a >= 500U) {
    if (BackMassage_Model_DW.is_Step3 == BackMassage_Model_IN_Step3_1) {
      BackMassage_Model_DW.is_Step3_1 = BackMassag_IN_NO_ACTIVE_CHILD_g;
      BackMassage_Model_DW.is_Step3 = BackMassag_IN_NO_ACTIVE_CHILD_g;
    } else {
      BackMassage_Model_DW.is_Step3 = BackMassag_IN_NO_ACTIVE_CHILD_g;
    }

    BackMassage_Model_DW.is_Test_Func = BackMassage_Model_IN_Step4;
    BackMassage_Model_DW.temporalCounter_i2_a = 0U;
    BackMassage_Model_B.Out_FlankBag[1] = BagState_Leakage;
    BackMassage_Model_B.Out_ValvePower[0] = true;
    tmp[0] = ((int32_T)BackMassage_Model_B.Out_FlankBag[0] == 0);
    BackMassage_Model_B.Out_ValvePower[1] = true;
    tmp[1] = ((int32_T)BackMassage_Model_B.Out_FlankBag[1] == 0);
    if (!BackMassage_Model_all(tmp)) {
      BackMassage_Model_DW.durationCounter_1_c = 0;
      BackMassage_Model_DW.durationCounter_1_e = 0;
      BackMassage_Model_DW.durationCounter_1_g = 0;
    }

    BackMassage_Model_DW.is_Step4 = BackMassage_Model_IN_Step_3_1;
    BackMassage_Model_DW.temporalCounter_i1_b = 0U;
    BackMassage_Model_DW.App_RunState.GasStorage = true;
    BackMassage_Model_B.Out_GasStorage = true;
    BackMassage_Model_B.Out_FlankBag[0] = BagState_Inflation;
    BackMassage_Model_B.Out_PumpState_j[0] = true;
    tmp[0] = ((int32_T)BackMassage_Model_B.Out_FlankBag[0] == 0);
    BackMassage_Model_B.Out_PumpState_j[1] = true;
    tmp[1] = ((int32_T)BackMassage_Model_B.Out_FlankBag[1] == 0);
    if (!BackMassage_Model_all(tmp)) {
      BackMassage_Model_DW.durationCounter_1_c = 0;
      BackMassage_Model_DW.durationCounter_1_e = 0;
      BackMassage_Model_DW.durationCounter_1_g = 0;
    }
  } else {
    BackMassage_Model_B.Out_FlankBag[0] = BagState_Leakage;
    BackMassage_Model_B.Out_ValvePower[0] = true;
    tmp[0] = ((int32_T)BackMassage_Model_B.Out_FlankBag[0] == 0);
    BackMassage_Model_B.Out_ValvePower[1] = true;
    tmp[1] = ((int32_T)BackMassage_Model_B.Out_FlankBag[1] == 0);
    if (!BackMassage_Model_all(tmp)) {
      BackMassage_Model_DW.durationCounter_1_c = 0;
      BackMassage_Model_DW.durationCounter_1_e = 0;
      BackMassage_Model_DW.durationCounter_1_g = 0;
    }

    if (BackMassage_Model_DW.is_Step3 == BackMassage_Model_IN_Step3_1) {
      BackMassage_Model_B.Out_FlankBag[1] = BagState_IDLE;
      tmp[0] = ((int32_T)BackMassage_Model_B.Out_FlankBag[0] == 0);
      tmp[1] = ((int32_T)BackMassage_Model_B.Out_FlankBag[1] == 0);
      if (!BackMassage_Model_all(tmp)) {
        BackMassage_Model_DW.durationCounter_1_c = 0;
        BackMassage_Model_DW.durationCounter_1_e = 0;
        BackMassage_Model_DW.durationCounter_1_g = 0;
      }

      if (BackMassage_Model_DW.is_Step3_1 == BackMassage_Model_IN_IDLE) {
        /* Inport: '<Root>/In_GasStoragePress' */
        if ((AppInto_GasStoragePress < GasStorage_StartPress) &&
            (!BackMassage_Model_DW.GasStorageBag_Error)) {
          BackMassage_Model_DW.is_Step3_1 = BackMassage_Model_IN_SensorBag;
          BackMassage_Model_DW.temporalCounter_i1_b = 0U;
        } else {
          BackMassage_Model_DW.App_RunState.GasStorage = false;
          BackMassage_Model_B.Out_GasStorage = false;
          BackMassage_Model_B.Out_PumpState_j[0] = false;
          BackMassage_Model_B.Out_PumpState_j[1] = false;
        }
      } else {
        boolean_T guard1 = false;

        /* Inport: '<Root>/In_GasStoragePress' */
        /* case IN_SensorBag: */
        guard1 = false;
        if (AppInto_GasStoragePress >= GasStorage_OverPress) {
          guard1 = true;
        } else if (BackMassage_Model_DW.temporalCounter_i1_b >= 3000U) {
          BackMassage_Model_DW.GasStorageBag_Error = true;
          guard1 = true;
        } else if (BackMassage_Model_DW.GasStorageBag_Error) {
          guard1 = true;
        } else {
          BackMassage_Model_DW.App_RunState.GasStorage = true;
          BackMassage_Model_B.Out_PumpState_j[0] = true;
          BackMassage_Model_B.Out_PumpState_j[1] = true;
          BackMassage_Model_B.Out_GasStorage = true;
        }

        if (guard1) {
          BackMassage_Model_DW.is_Step3_1 = BackMassage_Model_IN_IDLE;
          BackMassage_Model_DW.App_RunState.GasStorage = false;
          BackMassage_Model_B.Out_GasStorage = false;
          BackMassage_Model_B.Out_PumpState_j[0] = false;
          BackMassage_Model_B.Out_PumpState_j[1] = false;
        }
      }

      /* case IN_Step_3_1: */
    } else if (BackMassage_Model_DW.temporalCounter_i1_b >= 200U) {
      BackMassage_Model_DW.is_Step3 = BackMassage_Model_IN_Step3_1;
      BackMassage_Model_B.Out_FlankBag[1] = BagState_IDLE;
      tmp[0] = ((int32_T)BackMassage_Model_B.Out_FlankBag[0] == 0);
      tmp[1] = ((int32_T)BackMassage_Model_B.Out_FlankBag[1] == 0);
      if (!BackMassage_Model_all(tmp)) {
        BackMassage_Model_DW.durationCounter_1_c = 0;
        BackMassage_Model_DW.durationCounter_1_e = 0;
        BackMassage_Model_DW.durationCounter_1_g = 0;
      }

      BackMassage_Model_DW.is_Step3_1 = BackMassage_Model_IN_SensorBag;
      BackMassage_Model_DW.temporalCounter_i1_b = 0U;
    } else {
      BackMassage_Model_DW.App_RunState.GasStorage = true;
      BackMassage_Model_B.Out_GasStorage = true;
      BackMassage_Model_B.Out_FlankBag[1] = BagState_Inflation;
      BackMassage_Model_B.Out_PumpState_j[0] = true;
      tmp[0] = ((int32_T)BackMassage_Model_B.Out_FlankBag[0] == 0);
      BackMassage_Model_B.Out_PumpState_j[1] = true;
      tmp[1] = ((int32_T)BackMassage_Model_B.Out_FlankBag[1] == 0);
      if (!BackMassage_Model_all(tmp)) {
        BackMassage_Model_DW.durationCounter_1_c = 0;
        BackMassage_Model_DW.durationCounter_1_e = 0;
        BackMassage_Model_DW.durationCounter_1_g = 0;
      }
    }
  }
}

/* Function for Chart: '<Root>/Active_Flank' */
static void BackMassage_Model_Test_Func(void)
{
  boolean_T tmp[2];
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  guard1 = false;
  guard2 = false;
  switch (BackMassage_Model_DW.is_Test_Func) {
   case BackMassage_Model_IN_Start_bo:
    if (BackMassage_Model_DW.temporalCounter_i1_b >= 200U) {
      BackMassage_Model_DW.is_Test_Func = BackMassage_Model_IN_Step2_1;
      BackMassage_Model_DW.temporalCounter_i2_a = 0U;
      BackMassage_Model_B.Out_FlankBag[0] = BagState_IDLE;
      tmp[0] = ((int32_T)BackMassage_Model_B.Out_FlankBag[0] == 0);
      BackMassage_Model_B.Out_FlankBag[1] = BagState_IDLE;
      tmp[1] = ((int32_T)BackMassage_Model_B.Out_FlankBag[1] == 0);
      if (!BackMassage_Model_all(tmp)) {
        BackMassage_Model_DW.durationCounter_1_c = 0;
        BackMassage_Model_DW.durationCounter_1_e = 0;
        BackMassage_Model_DW.durationCounter_1_g = 0;
      }

      BackMassage_Model_DW.is_Step2_1 = BackMassage_Model_IN_SensorBag;
      BackMassage_Model_DW.temporalCounter_i1_b = 0U;
    } else {
      BackMassage_Model_B.Out_GasStorage = true;
      BackMassage_Model_B.Out_FlankBag[0] = BagState_Inflation;
      BackMassage_Model_B.Out_ValvePower[0] = true;
      BackMassage_Model_B.Out_PumpState_j[0] = true;
      tmp[0] = ((int32_T)BackMassage_Model_B.Out_FlankBag[0] == 0);
      BackMassage_Model_B.Out_ValvePower[1] = true;
      BackMassage_Model_B.Out_PumpState_j[1] = true;
      tmp[1] = ((int32_T)BackMassage_Model_B.Out_FlankBag[1] == 0);
      if (!BackMassage_Model_all(tmp)) {
        BackMassage_Model_DW.durationCounter_1_c = 0;
        BackMassage_Model_DW.durationCounter_1_e = 0;
        BackMassage_Model_DW.durationCounter_1_g = 0;
      }

      BackMassage_Model_B.Out_FlankBag[1] = BagState_IDLE;
      tmp[0] = ((int32_T)BackMassage_Model_B.Out_FlankBag[0] == 0);
      tmp[1] = ((int32_T)BackMassage_Model_B.Out_FlankBag[1] == 0);
      if (!BackMassage_Model_all(tmp)) {
        BackMassage_Model_DW.durationCounter_1_c = 0;
        BackMassage_Model_DW.durationCounter_1_e = 0;
        BackMassage_Model_DW.durationCounter_1_g = 0;
      }
    }
    break;

   case BackMassage_Model_IN_Step2_1:
    if (BackMassage_Model_DW.temporalCounter_i2_a >= 300U) {
      BackMassage_Model_DW.is_Step2_1 = BackMassag_IN_NO_ACTIVE_CHILD_g;
      BackMassage_Model_DW.is_Test_Func = BackMassage_Model_IN_Step3;
      BackMassage_Model_DW.temporalCounter_i2_a = 0U;
      BackMassage_Model_B.Out_FlankBag[0] = BagState_Leakage;
      BackMassage_Model_B.Out_PumpState_j[0] = false;
      BackMassage_Model_B.Out_ValvePower[0] = true;
      tmp[0] = ((int32_T)BackMassage_Model_B.Out_FlankBag[0] == 0);
      BackMassage_Model_B.Out_PumpState_j[1] = false;
      BackMassage_Model_B.Out_ValvePower[1] = true;
      tmp[1] = ((int32_T)BackMassage_Model_B.Out_FlankBag[1] == 0);
      if (!BackMassage_Model_all(tmp)) {
        BackMassage_Model_DW.durationCounter_1_c = 0;
        BackMassage_Model_DW.durationCounter_1_e = 0;
        BackMassage_Model_DW.durationCounter_1_g = 0;
      }

      BackMassag_enter_internal_Step3();
    } else {
      BackMassage_Model_B.Out_FlankBag[0] = BagState_IDLE;
      tmp[0] = ((int32_T)BackMassage_Model_B.Out_FlankBag[0] == 0);
      BackMassage_Model_B.Out_FlankBag[1] = BagState_IDLE;
      tmp[1] = ((int32_T)BackMassage_Model_B.Out_FlankBag[1] == 0);
      if (!BackMassage_Model_all(tmp)) {
        BackMassage_Model_DW.durationCounter_1_c = 0;
        BackMassage_Model_DW.durationCounter_1_e = 0;
        BackMassage_Model_DW.durationCounter_1_g = 0;
      }

      switch (BackMassage_Model_DW.is_Step2_1) {
       case BackMassage_Model_IN_IDLE:
        /* Inport: '<Root>/In_GasStoragePress' */
        if ((AppInto_GasStoragePress < GasStorage_StartPress) &&
            (!BackMassage_Model_DW.GasStorageBag_Error)) {
          BackMassage_Model_DW.is_Step2_1 = BackMassage_Model_IN_SensorBag;
          BackMassage_Model_DW.temporalCounter_i1_b = 0U;
        } else {
          BackMassage_Model_DW.App_RunState.GasStorage = false;
          BackMassage_Model_B.Out_GasStorage = false;
          BackMassage_Model_B.Out_PumpState_j[0] = false;
          BackMassage_Model_B.Out_ValvePower[0] = false;
          BackMassage_Model_B.Out_PumpState_j[1] = false;
          BackMassage_Model_B.Out_ValvePower[1] = false;
        }
        break;

       default:
        /* case IN_SensorBag: */
        if (AppInto_GasStoragePress >= GasStorage_OverPress) {
          guard2 = true;
        } else if (BackMassage_Model_DW.temporalCounter_i1_b >= 3000U) {
          BackMassage_Model_DW.GasStorageBag_Error = true;
          guard2 = true;
        } else if (BackMassage_Model_DW.GasStorageBag_Error) {
          guard2 = true;
        } else {
          BackMassage_Model_DW.App_RunState.GasStorage = true;
          BackMassage_Model_B.Out_PumpState_j[0] = true;
          BackMassage_Model_B.Out_ValvePower[0] = true;
          BackMassage_Model_B.Out_PumpState_j[1] = true;
          BackMassage_Model_B.Out_ValvePower[1] = true;
          BackMassage_Model_B.Out_GasStorage = true;
        }
        break;
      }
    }
    break;

   case BackMassage_Model_IN_Step3:
    BackMassage_Model_Step3();
    break;

   default:
    /* case IN_Step4: */
    if (BackMassage_Model_DW.temporalCounter_i2_a >= 500U) {
      if (BackMassage_Model_DW.is_Step4 == BackMassage_Model_IN_Step3_2) {
        BackMassage_Model_DW.is_Step3_2 = BackMassag_IN_NO_ACTIVE_CHILD_g;
        BackMassage_Model_B.Out_PumpState_j[0] = false;
        BackMassage_Model_B.Out_PumpState_j[1] = false;
        BackMassage_Model_DW.is_Step4 = BackMassag_IN_NO_ACTIVE_CHILD_g;
      } else {
        BackMassage_Model_DW.is_Step4 = BackMassag_IN_NO_ACTIVE_CHILD_g;
      }

      BackMassage_Model_DW.is_Test_Func = BackMassage_Model_IN_Step3;
      BackMassage_Model_DW.temporalCounter_i2_a = 0U;
      BackMassage_Model_B.Out_FlankBag[0] = BagState_Leakage;
      BackMassage_Model_B.Out_ValvePower[0] = true;
      tmp[0] = ((int32_T)BackMassage_Model_B.Out_FlankBag[0] == 0);
      BackMassage_Model_B.Out_ValvePower[1] = true;
      tmp[1] = ((int32_T)BackMassage_Model_B.Out_FlankBag[1] == 0);
      if (!BackMassage_Model_all(tmp)) {
        BackMassage_Model_DW.durationCounter_1_c = 0;
        BackMassage_Model_DW.durationCounter_1_e = 0;
        BackMassage_Model_DW.durationCounter_1_g = 0;
      }

      BackMassag_enter_internal_Step3();
    } else {
      BackMassage_Model_B.Out_FlankBag[1] = BagState_Leakage;
      BackMassage_Model_B.Out_ValvePower[0] = true;
      tmp[0] = ((int32_T)BackMassage_Model_B.Out_FlankBag[0] == 0);
      BackMassage_Model_B.Out_ValvePower[1] = true;
      tmp[1] = ((int32_T)BackMassage_Model_B.Out_FlankBag[1] == 0);
      if (!BackMassage_Model_all(tmp)) {
        BackMassage_Model_DW.durationCounter_1_c = 0;
        BackMassage_Model_DW.durationCounter_1_e = 0;
        BackMassage_Model_DW.durationCounter_1_g = 0;
      }

      switch (BackMassage_Model_DW.is_Step4) {
       case BackMassage_Model_IN_Step3_2:
        BackMassage_Model_B.Out_FlankBag[0] = BagState_IDLE;
        tmp[0] = ((int32_T)BackMassage_Model_B.Out_FlankBag[0] == 0);
        tmp[1] = ((int32_T)BackMassage_Model_B.Out_FlankBag[1] == 0);
        if (!BackMassage_Model_all(tmp)) {
          BackMassage_Model_DW.durationCounter_1_c = 0;
          BackMassage_Model_DW.durationCounter_1_e = 0;
          BackMassage_Model_DW.durationCounter_1_g = 0;
        }

        switch (BackMassage_Model_DW.is_Step3_2) {
         case BackMassage_Model_IN_IDLE:
          /* Inport: '<Root>/In_GasStoragePress' */
          if ((AppInto_GasStoragePress < GasStorage_StartPress) &&
              (!BackMassage_Model_DW.GasStorageBag_Error)) {
            BackMassage_Model_DW.is_Step3_2 = BackMassage_Model_IN_SensorBag;
            BackMassage_Model_DW.temporalCounter_i1_b = 0U;
          } else {
            BackMassage_Model_DW.App_RunState.GasStorage = false;
            BackMassage_Model_B.Out_GasStorage = false;
            BackMassage_Model_B.Out_PumpState_j[0] = false;
            BackMassage_Model_B.Out_PumpState_j[1] = false;
          }
          break;

         default:
          /* case IN_SensorBag: */
          if (AppInto_GasStoragePress >= GasStorage_OverPress) {
            guard1 = true;
          } else if (BackMassage_Model_DW.temporalCounter_i1_b >= 3000U) {
            BackMassage_Model_DW.GasStorageBag_Error = true;
            guard1 = true;
          } else if (BackMassage_Model_DW.GasStorageBag_Error) {
            guard1 = true;
          } else {
            BackMassage_Model_DW.App_RunState.GasStorage = true;
            BackMassage_Model_B.Out_PumpState_j[0] = true;
            BackMassage_Model_B.Out_PumpState_j[1] = true;
            BackMassage_Model_B.Out_GasStorage = true;
          }
          break;
        }
        break;

       default:
        /* case IN_Step_3_1: */
        if (BackMassage_Model_DW.temporalCounter_i1_b >= 200U) {
          BackMassage_Model_DW.is_Step4 = BackMassage_Model_IN_Step3_2;
          BackMassage_Model_B.Out_FlankBag[0] = BagState_IDLE;
          tmp[0] = ((int32_T)BackMassage_Model_B.Out_FlankBag[0] == 0);
          tmp[1] = ((int32_T)BackMassage_Model_B.Out_FlankBag[1] == 0);
          if (!BackMassage_Model_all(tmp)) {
            BackMassage_Model_DW.durationCounter_1_c = 0;
            BackMassage_Model_DW.durationCounter_1_e = 0;
            BackMassage_Model_DW.durationCounter_1_g = 0;
          }

          BackMassage_Model_DW.is_Step3_2 = BackMassage_Model_IN_SensorBag;
          BackMassage_Model_DW.temporalCounter_i1_b = 0U;
        } else {
          BackMassage_Model_DW.App_RunState.GasStorage = true;
          BackMassage_Model_B.Out_GasStorage = true;
          BackMassage_Model_B.Out_FlankBag[0] = BagState_Inflation;
          BackMassage_Model_B.Out_PumpState_j[0] = true;
          tmp[0] = ((int32_T)BackMassage_Model_B.Out_FlankBag[0] == 0);
          BackMassage_Model_B.Out_PumpState_j[1] = true;
          tmp[1] = ((int32_T)BackMassage_Model_B.Out_FlankBag[1] == 0);
          if (!BackMassage_Model_all(tmp)) {
            BackMassage_Model_DW.durationCounter_1_c = 0;
            BackMassage_Model_DW.durationCounter_1_e = 0;
            BackMassage_Model_DW.durationCounter_1_g = 0;
          }
        }
        break;
      }
    }
    break;
  }

  if (guard2) {
    BackMassage_Model_DW.is_Step2_1 = BackMassage_Model_IN_IDLE;
    BackMassage_Model_DW.App_RunState.GasStorage = false;
    BackMassage_Model_B.Out_GasStorage = false;
    BackMassage_Model_B.Out_PumpState_j[0] = false;
    BackMassage_Model_B.Out_ValvePower[0] = false;
    BackMassage_Model_B.Out_PumpState_j[1] = false;
    BackMassage_Model_B.Out_ValvePower[1] = false;
  }

  if (guard1) {
    BackMassage_Model_DW.is_Step3_2 = BackMassage_Model_IN_IDLE;
    BackMassage_Model_DW.App_RunState.GasStorage = false;
    BackMassage_Model_B.Out_GasStorage = false;
    BackMassage_Model_B.Out_PumpState_j[0] = false;
    BackMassage_Model_B.Out_PumpState_j[1] = false;
  }
}

/* Function for Chart: '<Root>/Active_Flank' */
static void BackMassage__exit_internal_Main(void)
{
  if (BackMassage_Model_DW.is_Main == BackMassage_Model_IN_Test_Func) {
    switch (BackMassage_Model_DW.is_Test_Func) {
     case BackMassage_Model_IN_Step2_1:
      BackMassage_Model_DW.is_Step2_1 = BackMassag_IN_NO_ACTIVE_CHILD_g;
      BackMassage_Model_DW.is_Test_Func = BackMassag_IN_NO_ACTIVE_CHILD_g;
      break;

     case BackMassage_Model_IN_Step3:
      if (BackMassage_Model_DW.is_Step3 == BackMassage_Model_IN_Step3_1) {
        BackMassage_Model_DW.is_Step3_1 = BackMassag_IN_NO_ACTIVE_CHILD_g;
        BackMassage_Model_DW.is_Step3 = BackMassag_IN_NO_ACTIVE_CHILD_g;
      } else {
        BackMassage_Model_DW.is_Step3 = BackMassag_IN_NO_ACTIVE_CHILD_g;
      }

      BackMassage_Model_DW.is_Test_Func = BackMassag_IN_NO_ACTIVE_CHILD_g;
      break;

     case BackMassage_Model_IN_Step4:
      if (BackMassage_Model_DW.is_Step4 == BackMassage_Model_IN_Step3_2) {
        BackMassage_Model_DW.is_Step3_2 = BackMassag_IN_NO_ACTIVE_CHILD_g;
        BackMassage_Model_DW.is_Step4 = BackMassag_IN_NO_ACTIVE_CHILD_g;
      } else {
        BackMassage_Model_DW.is_Step4 = BackMassag_IN_NO_ACTIVE_CHILD_g;
      }

      BackMassage_Model_DW.is_Test_Func = BackMassag_IN_NO_ACTIVE_CHILD_g;
      break;

     default:
      BackMassage_Model_DW.is_Test_Func = BackMassag_IN_NO_ACTIVE_CHILD_g;
      break;
    }

    BackMassage_Model_B.Out_GasStorage = false;
    BackMassage_Model_B.Out_PumpState_j[0] = false;
    BackMassage_Model_B.Out_ValvePower[0] = false;
    BackMassage_Model_B.Out_PumpState_j[1] = false;
    BackMassage_Model_B.Out_ValvePower[1] = false;
    BackMassage_Model_DW.is_Main = BackMassag_IN_NO_ACTIVE_CHILD_g;
  } else {
    BackMassage_Model_DW.is_Idle = BackMassag_IN_NO_ACTIVE_CHILD_g;
    BackMassage_Model_DW.is_Left_Func = BackMassag_IN_NO_ACTIVE_CHILD_g;
    BackMassage_Model_DW.is_Right_Func = BackMassag_IN_NO_ACTIVE_CHILD_g;
    BackMassage_M_exit_internal_mid();
    BackMassage_Model_DW.is_Main = BackMassag_IN_NO_ACTIVE_CHILD_g;
  }
}

/* Function for Chart: '<Root>/Active_Flank' */
static void BackMassage__enter_internal_mid(void)
{
  boolean_T tmp[2];
  BackMassage_Model_DW.is_LeftBag = BackMassage_Model_IN_Recover;
  BackMassage_Model_DW.temporalCounter_i1_b = 0U;
  BackMassage_Model_DW.is_Recover = BackMassage_Model_IN_start;
  BackMassage_Model_B.Out_FlankBag[0] = BagState_IDLE;
  tmp[0] = ((int32_T)BackMassage_Model_B.Out_FlankBag[0] == 0);
  tmp[1] = ((int32_T)BackMassage_Model_B.Out_FlankBag[1] == 0);
  if (!BackMassage_Model_all(tmp)) {
    BackMassage_Model_DW.durationCounter_1_c = 0;
    BackMassage_Model_DW.durationCounter_1_e = 0;
    BackMassage_Model_DW.durationCounter_1_g = 0;
  }

  BackMassage_Model_B.Out_ValvePower[0] = true;
  BackMassage_Model_DW.is_RightBag = BackMassage_Model_IN_Recover;
  BackMassage_Model_DW.temporalCounter_i2_a = 0U;
  BackMassage_Model_DW.is_Recover_p = BackMassage_Model_IN_Start_b;
  BackMassage_Model_B.Out_FlankBag[1] = BagState_IDLE;
  tmp[0] = ((int32_T)BackMassage_Model_B.Out_FlankBag[0] == 0);
  tmp[1] = ((int32_T)BackMassage_Model_B.Out_FlankBag[1] == 0);
  if (!BackMassage_Model_all(tmp)) {
    BackMassage_Model_DW.durationCounter_1_c = 0;
    BackMassage_Model_DW.durationCounter_1_e = 0;
    BackMassage_Model_DW.durationCounter_1_g = 0;
  }

  BackMassage_Model_B.Out_ValvePower[1] = true;
}

/* Function for Chart: '<Root>/Active_Flank' */
static void BackMa_enter_internal_Test_Func(void)
{
  boolean_T tmp[2];
  BackMassage_Model_DW.is_Test_Func = BackMassage_Model_IN_Start_bo;
  BackMassage_Model_DW.temporalCounter_i1_b = 0U;
  BackMassage_Model_B.Out_GasStorage = true;
  BackMassage_Model_B.Out_FlankBag[0] = BagState_Inflation;
  BackMassage_Model_B.Out_ValvePower[0] = true;
  BackMassage_Model_B.Out_PumpState_j[0] = true;
  tmp[0] = ((int32_T)BackMassage_Model_B.Out_FlankBag[0] == 0);
  BackMassage_Model_B.Out_ValvePower[1] = true;
  BackMassage_Model_B.Out_PumpState_j[1] = true;
  tmp[1] = ((int32_T)BackMassage_Model_B.Out_FlankBag[1] == 0);
  if (!BackMassage_Model_all(tmp)) {
    BackMassage_Model_DW.durationCounter_1_c = 0;
    BackMassage_Model_DW.durationCounter_1_e = 0;
    BackMassage_Model_DW.durationCounter_1_g = 0;
  }

  BackMassage_Model_B.Out_FlankBag[1] = BagState_IDLE;
  tmp[0] = ((int32_T)BackMassage_Model_B.Out_FlankBag[0] == 0);
  tmp[1] = ((int32_T)BackMassage_Model_B.Out_FlankBag[1] == 0);
  if (!BackMassage_Model_all(tmp)) {
    BackMassage_Model_DW.durationCounter_1_c = 0;
    BackMassage_Model_DW.durationCounter_1_e = 0;
    BackMassage_Model_DW.durationCounter_1_g = 0;
  }
}

/* Function for Chart: '<Root>/Active_Flank' */
static void BackMassage_M_enter_atomic_IDLE(void)
{
  boolean_T tmp[2];
  BackMassage_Model_DW.App_RunState.Active_Flank = false;
  BackMassage_Model_B.Out_GasStorage = false;
  BackMassage_Model_B.Out_PumpState_j[0] = false;
  BackMassage_Model_B.Out_ValvePower[0] = false;
  BackMassage_Model_B.Out_FlankBag[0] = BagState_IDLE;
  tmp[0] = ((int32_T)BackMassage_Model_B.Out_FlankBag[0] == 0);
  BackMassage_Model_B.Out_PumpState_j[1] = false;
  BackMassage_Model_B.Out_ValvePower[1] = false;
  BackMassage_Model_B.Out_FlankBag[1] = BagState_IDLE;
  tmp[1] = ((int32_T)BackMassage_Model_B.Out_FlankBag[1] == 0);
  if (!BackMassage_Model_all(tmp)) {
    BackMassage_Model_DW.durationCounter_1_c = 0;
    BackMassage_Model_DW.durationCounter_1_e = 0;
    BackMassage_Model_DW.durationCounter_1_g = 0;
  }
}

/* Function for Chart: '<Root>/Active_Flank' */
static void BackMassage_Model_Main(void)
{
  uint32_T Loc_TargetPress;
  boolean_T tmp[2];

  /* DataStoreRead: '<Root>/Data Store Read9' incorporates:
   *  Inport: '<Root>/In_ActiveFlankMode'
   *  Inport: '<Root>/In_FlankPress'
   *  Inport: '<Root>/In_GasStoragePress'
   */
  if (!BackMassage_Model_DW.App_Func_En.Active_Flank) {
    BackMassage__exit_internal_Main();
    BackMassage_Model_DW.is_c10_BackMassage_Model = BackMassage_Model_IN_IDLE;
    BackMassage_M_enter_atomic_IDLE();
  } else {
    BackMassage_Model_Sensitivity(&Loc_TargetPress);
    if (BackMassage_Model_DW.Loc_save_mode != AppInto_ActiveFlankMode) {
      BackMassage_Model_DW.Loc_save_mode = AppInto_ActiveFlankMode;
      switch (AppInto_ActiveFlankMode) {
       case 1:
        BackMassage__exit_internal_Main();
        BackMassage_Model_DW.durationCounter_1_c = 0;
        BackMassage_Model_DW.is_Main = BackMassage_Model_IN_mid;
        BackMassage_Model_B.Out_PumpState_j[0] = false;
        BackMassage_Model_B.Out_PumpState_j[1] = false;
        BackMassage_Model_B.Out_GasStorage = false;
        BackMassage__enter_internal_mid();
        break;

       case 2:
        BackMassage__exit_internal_Main();
        BackMassage_Model_DW.durationCounter_1_e = 0;
        BackMassage_Model_DW.is_Main = BackMassage_Model_IN_Left_Func;
        BackMassage_Model_DW.is_Left_Func = BackMassage_Model_IN_IDLE;
        break;

       case 3:
        BackMassage__exit_internal_Main();
        BackMassage_Model_DW.durationCounter_1_g = 0;
        BackMassage_Model_DW.is_Main = BackMassage_Model_IN_Right_Func;
        BackMassage_Model_DW.is_Right_Func = BackMassage_Model_IN_IDLE;
        break;

       case 4:
        BackMassage__exit_internal_Main();
        BackMassage_Model_DW.is_Main = BackMassage_Model_IN_Test_Func;
        BackMa_enter_internal_Test_Func();
        break;

       default:
        BackMassage__exit_internal_Main();
        BackMassage_Model_DW.is_Main = BackMassage_Model_IN_Idle_f;
        BackMassage_Model_B.Out_FlankBag[0] = BagState_IDLE;
        tmp[0] = ((int32_T)BackMassage_Model_B.Out_FlankBag[0] == 0);
        BackMassage_Model_B.Out_FlankBag[1] = BagState_IDLE;
        tmp[1] = ((int32_T)BackMassage_Model_B.Out_FlankBag[1] == 0);
        if (!BackMassage_Model_all(tmp)) {
          BackMassage_Model_DW.durationCounter_1_c = 0;
          BackMassage_Model_DW.durationCounter_1_e = 0;
          BackMassage_Model_DW.durationCounter_1_g = 0;
        }

        BackMassage_Model_DW.is_Idle = BackMassage_Model_IN_IDLE;
        BackMassage_Model_DW.App_RunState.GasStorage = false;
        BackMassage_Model_B.Out_GasStorage = false;
        BackMassage_Model_B.Out_PumpState_j[0] = false;
        BackMassage_Model_B.Out_ValvePower[0] = false;
        BackMassage_Model_B.Out_PumpState_j[1] = false;
        BackMassage_Model_B.Out_ValvePower[1] = false;
        break;
      }
    } else {
      boolean_T guard1 = false;
      guard1 = false;
      switch (BackMassage_Model_DW.is_Main) {
       case BackMassage_Model_IN_Idle_f:
        BackMassage_Model_B.Out_FlankBag[0] = BagState_IDLE;
        tmp[0] = ((int32_T)BackMassage_Model_B.Out_FlankBag[0] == 0);
        BackMassage_Model_B.Out_FlankBag[1] = BagState_IDLE;
        tmp[1] = ((int32_T)BackMassage_Model_B.Out_FlankBag[1] == 0);
        if (!BackMassage_Model_all(tmp)) {
          BackMassage_Model_DW.durationCounter_1_c = 0;
          BackMassage_Model_DW.durationCounter_1_e = 0;
          BackMassage_Model_DW.durationCounter_1_g = 0;
        }

        switch (BackMassage_Model_DW.is_Idle) {
         case BackMassage_Model_IN_IDLE:
          if ((AppInto_GasStoragePress < GasStorage_StartPress) &&
              (!BackMassage_Model_DW.GasStorageBag_Error)) {
            BackMassage_Model_DW.is_Idle = BackMassage_Model_IN_SensorBag;
            BackMassage_Model_DW.temporalCounter_i1_b = 0U;
          } else {
            BackMassage_Model_DW.App_RunState.GasStorage = false;
            BackMassage_Model_B.Out_GasStorage = false;
            BackMassage_Model_B.Out_PumpState_j[0] = false;
            BackMassage_Model_B.Out_ValvePower[0] = false;
            BackMassage_Model_B.Out_PumpState_j[1] = false;
            BackMassage_Model_B.Out_ValvePower[1] = false;
          }
          break;

         default:
          /* case IN_SensorBag: */
          if (AppInto_GasStoragePress >= GasStorage_OverPress) {
            guard1 = true;
          } else if (BackMassage_Model_DW.temporalCounter_i1_b >= 3000U) {
            BackMassage_Model_DW.GasStorageBag_Error = true;
            guard1 = true;
          } else if (BackMassage_Model_DW.GasStorageBag_Error) {
            guard1 = true;
          } else {
            BackMassage_Model_DW.App_RunState.GasStorage = true;
            BackMassage_Model_B.Out_PumpState_j[0] = true;
            BackMassage_Model_B.Out_ValvePower[0] = true;
            BackMassage_Model_B.Out_PumpState_j[1] = true;
            BackMassage_Model_B.Out_ValvePower[1] = true;
            BackMassage_Model_B.Out_GasStorage = true;
          }
          break;
        }
        break;

       case BackMassage_Model_IN_Left_Func:
        tmp[0] = ((int32_T)BackMassage_Model_B.Out_FlankBag[0] == 0);
        tmp[1] = ((int32_T)BackMassage_Model_B.Out_FlankBag[1] == 0);
        if (!BackMassage_Model_all(tmp)) {
          BackMassage_Model_DW.durationCounter_1_e = 0;
        }

        if (BackMassage_Model_DW.durationCounter_1_e > 200) {
          BackMassage_Model_DW.is_Left_Func = BackMassag_IN_NO_ACTIVE_CHILD_g;
          BackMassage_Model_DW.is_Main = BackMassage_Model_IN_Idle_f;
          BackMassage_Model_B.Out_FlankBag[0] = BagState_IDLE;
          tmp[0] = ((int32_T)BackMassage_Model_B.Out_FlankBag[0] == 0);
          BackMassage_Model_B.Out_FlankBag[1] = BagState_IDLE;
          tmp[1] = ((int32_T)BackMassage_Model_B.Out_FlankBag[1] == 0);
          if (!BackMassage_Model_all(tmp)) {
            BackMassage_Model_DW.durationCounter_1_c = 0;
            BackMassage_Model_DW.durationCounter_1_e = 0;
            BackMassage_Model_DW.durationCounter_1_g = 0;
          }

          BackMassage_Model_DW.is_Idle = BackMassage_Model_IN_IDLE;
          BackMassage_Model_DW.App_RunState.GasStorage = false;
          BackMassage_Model_B.Out_GasStorage = false;
          BackMassage_Model_B.Out_PumpState_j[0] = false;
          BackMassage_Model_B.Out_ValvePower[0] = false;
          BackMassage_Model_B.Out_PumpState_j[1] = false;
          BackMassage_Model_B.Out_ValvePower[1] = false;
        } else {
          switch (BackMassage_Model_DW.is_Left_Func) {
           case BackMassage_Model_IN_IDLE:
            if (AppInto_FlankPress[1] >= Loc_TargetPress) {
              BackMassage_Model_DW.is_Left_Func = BackMassage_Model_IN_idle;
              BackMassage_Model_DW.temporalCounter_i1_b = 0U;
              BackMassage_Model_B.Out_PumpState_j[0] = false;
              BackMassage_Model_B.Out_FlankBag[0] = BagState_IDLE;
              tmp[0] = ((int32_T)BackMassage_Model_B.Out_FlankBag[0] == 0);
              BackMassage_Model_B.Out_PumpState_j[1] = false;
              BackMassage_Model_B.Out_FlankBag[1] = BagState_IDLE;
              tmp[1] = ((int32_T)BackMassage_Model_B.Out_FlankBag[1] == 0);
              if (!BackMassage_Model_all(tmp)) {
                BackMassage_Model_DW.durationCounter_1_c = 0;
                BackMassage_Model_DW.durationCounter_1_e = 0;
                BackMassage_Model_DW.durationCounter_1_g = 0;
              }
            } else if (AppInto_FlankPress[1] < Loc_TargetPress) {
              BackMassage_Model_DW.is_Left_Func = BackMassage_Model_IN_Leakage_a;
              BackMassage_Model_DW.temporalCounter_i1_b = 0U;
              BackMassage_Model_B.Out_FlankBag[0] = BagState_IDLE;
              BackMassage_Model_B.Out_ValvePower[0] = true;
              BackMassage_Model_B.Out_PumpState_j[0] = true;
              tmp[0] = ((int32_T)BackMassage_Model_B.Out_FlankBag[0] == 0);
              BackMassage_Model_B.Out_ValvePower[1] = true;
              BackMassage_Model_B.Out_PumpState_j[1] = true;
              tmp[1] = ((int32_T)BackMassage_Model_B.Out_FlankBag[1] == 0);
              if (!BackMassage_Model_all(tmp)) {
                BackMassage_Model_DW.durationCounter_1_c = 0;
                BackMassage_Model_DW.durationCounter_1_e = 0;
                BackMassage_Model_DW.durationCounter_1_g = 0;
              }

              BackMassage_Model_B.Out_FlankBag[1] = BagState_Inflation;
              tmp[0] = ((int32_T)BackMassage_Model_B.Out_FlankBag[0] == 0);
              tmp[1] = ((int32_T)BackMassage_Model_B.Out_FlankBag[1] == 0);
              if (!BackMassage_Model_all(tmp)) {
                BackMassage_Model_DW.durationCounter_1_c = 0;
                BackMassage_Model_DW.durationCounter_1_e = 0;
                BackMassage_Model_DW.durationCounter_1_g = 0;
              }
            }
            break;

           case BackMassage_Model_IN_Leakage_a:
            if ((BackMassage_Model_DW.temporalCounter_i1_b * 10 >= ((uint16_T)
                  MaxInflation_T)) || (AppInto_FlankPress[1] >= Loc_TargetPress))
            {
              BackMassage_Model_DW.is_Left_Func = BackMassage_Model_IN_idle;
              BackMassage_Model_DW.temporalCounter_i1_b = 0U;
              BackMassage_Model_B.Out_PumpState_j[0] = false;
              BackMassage_Model_B.Out_FlankBag[0] = BagState_IDLE;
              tmp[0] = ((int32_T)BackMassage_Model_B.Out_FlankBag[0] == 0);
              BackMassage_Model_B.Out_PumpState_j[1] = false;
              BackMassage_Model_B.Out_FlankBag[1] = BagState_IDLE;
              tmp[1] = ((int32_T)BackMassage_Model_B.Out_FlankBag[1] == 0);
              if (!BackMassage_Model_all(tmp)) {
                BackMassage_Model_DW.durationCounter_1_c = 0;
                BackMassage_Model_DW.durationCounter_1_e = 0;
                BackMassage_Model_DW.durationCounter_1_g = 0;
              }
            } else {
              BackMassage_Model_B.Out_FlankBag[0] = BagState_IDLE;
              BackMassage_Model_B.Out_ValvePower[0] = true;
              BackMassage_Model_B.Out_PumpState_j[0] = true;
              tmp[0] = ((int32_T)BackMassage_Model_B.Out_FlankBag[0] == 0);
              BackMassage_Model_B.Out_ValvePower[1] = true;
              BackMassage_Model_B.Out_PumpState_j[1] = true;
              tmp[1] = ((int32_T)BackMassage_Model_B.Out_FlankBag[1] == 0);
              if (!BackMassage_Model_all(tmp)) {
                BackMassage_Model_DW.durationCounter_1_c = 0;
                BackMassage_Model_DW.durationCounter_1_e = 0;
                BackMassage_Model_DW.durationCounter_1_g = 0;
              }

              BackMassage_Model_B.Out_FlankBag[1] = BagState_Inflation;
              tmp[0] = ((int32_T)BackMassage_Model_B.Out_FlankBag[0] == 0);
              tmp[1] = ((int32_T)BackMassage_Model_B.Out_FlankBag[1] == 0);
              if (!BackMassage_Model_all(tmp)) {
                BackMassage_Model_DW.durationCounter_1_c = 0;
                BackMassage_Model_DW.durationCounter_1_e = 0;
                BackMassage_Model_DW.durationCounter_1_g = 0;
              }

              BackMassage_Model_B.Out_GasStorage =
                ((BackMassage_Model_DW.temporalCounter_i1_b >= 20U) ||
                 BackMassage_Model_B.Out_GasStorage);
            }
            break;

           default:
            /* case IN_idle: */
            if (BackMassage_Model_DW.temporalCounter_i1_b >= 20U) {
              BackMassage_Model_B.Out_ValvePower[0] = false;
              BackMassage_Model_B.Out_ValvePower[1] = false;
              BackMassage_Model_B.Out_GasStorage = false;
            }
            break;
          }
        }
        break;

       case BackMassage_Model_IN_Right_Func:
        BackMassage_Model_Right_Func(&Loc_TargetPress);
        break;

       case BackMassage_Model_IN_Test_Func:
        BackMassage_Model_Test_Func();
        break;

       default:
        /* case IN_mid: */
        BackMassage_Model_mid();
        break;
      }

      if (guard1) {
        BackMassage_Model_DW.is_Idle = BackMassage_Model_IN_IDLE;
        BackMassage_Model_DW.App_RunState.GasStorage = false;
        BackMassage_Model_B.Out_GasStorage = false;
        BackMassage_Model_B.Out_PumpState_j[0] = false;
        BackMassage_Model_B.Out_ValvePower[0] = false;
        BackMassage_Model_B.Out_PumpState_j[1] = false;
        BackMassage_Model_B.Out_ValvePower[1] = false;
      }
    }
  }

  /* End of DataStoreRead: '<Root>/Data Store Read9' */
}

/* Function for Chart: '<Root>/Active_Flank' */
static void BackMass_Reset_GasStorage_Error(void)
{
  /* Inport: '<Root>/In_ActiveFlankMode' */
  BackMassage_Model_DW.GasStorageBag_Error = (((AppInto_ActiveFlankMode < 1) ||
    (AppInto_ActiveFlankMode > 4)) && BackMassage_Model_DW.GasStorageBag_Error);
}

/* Function for Chart: '<Root>/Passive_flank' */
static void BackMassage_enter_internal_Deal(void)
{
  /* Inport: '<Root>/In_Flank_Req' */
  BackMassage_Model_DW.Loc_flank_save = AppInto_FlankFunc;
  switch (AppInto_FlankFunc) {
   case 1:
    BackMassage_Model_DW.isStable = false;
    BackMassage_Model_DW.is_Deal = BackMassage_Model_IN_up;
    BackMassage_Model_DW.temporalCounter_i1_j = 0U;
    BackMassage_Model_B.Out_ValvePowerState = true;
    BackMassage_Model_B.Out_PumpState = true;
    BackMassage_Model_B.Out_flank_bag[0] = BagState_Inflation;
    break;

   case 2:
    BackMassage_Model_DW.isStable = false;
    BackMassage_Model_DW.is_Deal = BackMassage_Model_IN_down_j;
    BackMassage_Model_DW.temporalCounter_i1_j = 0U;
    BackMassage_Model_B.Out_ValvePowerState = true;
    BackMassage_Model_B.Out_PumpState = false;
    BackMassage_Model_B.Out_flank_bag[0] = BagState_Leakage;
    break;

   case 3:
    BackMassage_Model_DW.isStable = false;
    BackMassage_Model_DW.is_Deal = BackMassage_Model_IN_Fwd;
    BackMassage_Model_DW.temporalCounter_i1_j = 0U;
    BackMassage_Model_B.Out_ValvePowerState = true;
    BackMassage_Model_B.Out_PumpState = true;
    BackMassage_Model_B.Out_flank_bag[1] = BagState_Inflation;
    break;

   case 4:
    BackMassage_Model_DW.isStable = false;
    BackMassage_Model_DW.is_Deal = BackMassage_Model_IN_Rwd;
    BackMassage_Model_DW.temporalCounter_i1_j = 0U;
    BackMassage_Model_B.Out_ValvePowerState = true;
    BackMassage_Model_B.Out_PumpState = false;
    BackMassage_Model_B.Out_flank_bag[1] = BagState_Leakage;
    break;

   default:
    BackMassage_Model_DW.isStable = false;
    BackMassage_Model_DW.is_Deal = BackMassage_Model_IN_other;
    BackMassage_Model_DW.App_RunState.Passive_Flank = false;
    BackMassage_Model_B.Out_ValvePowerState = false;
    BackMassage_Model_B.Out_PumpState = false;
    BackMassage_Model_B.Out_flank_bag[0] = BagState_IDLE;
    BackMassage_Model_B.Out_flank_bag[1] = BagState_IDLE;
    break;
  }

  /* End of Inport: '<Root>/In_Flank_Req' */
}

/* Function for Chart: '<Root>/Passive_Lumbar' */
static void BackMassage_Model_FWD(void)
{
  switch (BackMassage_Model_DW.is_up_bag_h) {
   case BackMassage_Mode_IN_Inflation_n:
    if ((BackMassage_Model_DW.temporalCounter_i1_h * 10 >= ((uint16_T)
          MaxInflation_T)) || (AppInto_LumbarPress[0] > Lumbar_OverPress)) {
      BackMassage_Model_DW.isStable_h = false;
      BackMassage_Model_DW.is_up_bag_h = BackMassage_Model_IN_idle_m;
      BackMassage_Model_DW.temporalCounter_i1_h = 0U;
      BackMassage_Model_B.Out_LumbarBag[0] = BagState_IDLE;
    } else {
      BackMassage_Model_B.Out_bValvePowerState = true;
      BackMassage_Model_B.Out_bPumpState[0] = true;
      BackMassage_Model_B.Out_LumbarBag[0] = BagState_Inflation;
    }
    break;

   case BackMassage_Model_IN_idle_m:
    if (BackMassage_Model_DW.temporalCounter_i1_h >= 50U) {
      BackMassage_Model_B.Out_bPumpState[0] = false;
    }
    break;

   default:
    /* Inport: '<Root>/In_LumbarPress' */
    /* case IN_start: */
    if (AppInto_LumbarPress[0] < Lumbar_OverPress) {
      BackMassage_Model_DW.isStable_h = false;
      BackMassage_Model_DW.is_up_bag_h = BackMassage_Mode_IN_Inflation_n;
      BackMassage_Model_DW.temporalCounter_i1_h = 0U;
      BackMassage_Model_B.Out_bValvePowerState = true;
      BackMassage_Model_B.Out_bPumpState[0] = true;
      BackMassage_Model_B.Out_LumbarBag[0] = BagState_Inflation;
    } else {
      BackMassage_Model_DW.isStable_h = false;
      BackMassage_Model_DW.is_up_bag_h = BackMassage_Model_IN_idle_m;
      BackMassage_Model_DW.temporalCounter_i1_h = 0U;
      BackMassage_Model_B.Out_LumbarBag[0] = BagState_IDLE;
    }
    break;
  }

  switch (BackMassage_Model_DW.is_down_bag_g) {
   case BackMassage_Mode_IN_Inflation_n:
    if ((BackMassage_Model_DW.temporalCounter_i2 * 10 >= ((uint16_T)
          MaxInflation_T)) || (AppInto_LumbarPress[1] > Lumbar_OverPress)) {
      BackMassage_Model_DW.isStable_h = false;
      BackMassage_Model_DW.is_down_bag_g = BackMassage_Model_IN_idle_m;
      BackMassage_Model_DW.temporalCounter_i2 = 0U;
      BackMassage_Model_B.Out_LumbarBag[1] = BagState_IDLE;
    } else {
      BackMassage_Model_B.Out_bValvePowerState = true;
      BackMassage_Model_B.Out_LumbarBag[1] = BagState_Inflation;
      BackMassage_Model_B.Out_bPumpState[1] = true;
    }
    break;

   case BackMassage_Model_IN_idle_m:
    if (BackMassage_Model_DW.temporalCounter_i2 >= 50U) {
      BackMassage_Model_B.Out_bPumpState[1] = false;
    }
    break;

   default:
    /* Inport: '<Root>/In_LumbarPress' */
    /* case IN_start: */
    if (AppInto_LumbarPress[1] < Lumbar_OverPress) {
      BackMassage_Model_DW.isStable_h = false;
      BackMassage_Model_DW.is_down_bag_g = BackMassage_Mode_IN_Inflation_n;
      BackMassage_Model_DW.temporalCounter_i2 = 0U;
      BackMassage_Model_B.Out_bValvePowerState = true;
      BackMassage_Model_B.Out_LumbarBag[1] = BagState_Inflation;
      BackMassage_Model_B.Out_bPumpState[1] = true;
    } else {
      BackMassage_Model_DW.isStable_h = false;
      BackMassage_Model_DW.is_down_bag_g = BackMassage_Model_IN_idle_m;
      BackMassage_Model_DW.temporalCounter_i2 = 0U;
      BackMassage_Model_B.Out_LumbarBag[1] = BagState_IDLE;
    }
    break;
  }
}

/* Function for Chart: '<Root>/Passive_Lumbar' */
static boolean_T BackMassage_Model_any(const boolean_T x[2])
{
  int32_T k;
  boolean_T exitg1;
  boolean_T y;
  y = false;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (x[k]) {
      y = true;
      exitg1 = true;
    } else {
      k++;
    }
  }

  return y;
}

/* Function for Chart: '<Root>/Passive_Lumbar' */
static void BackMassage_exit_internal_READY(void)
{
  switch (BackMassage_Model_DW.is_READY) {
   case BackMassage_Model_IN_FWD:
    BackMassage_Model_DW.is_down_bag_g = BackMassag_IN_NO_ACTIVE_CHILD_g;
    BackMassage_Model_DW.is_up_bag_h = BackMassag_IN_NO_ACTIVE_CHILD_g;
    BackMassage_Model_B.Out_LumbarBag[0] = BagState_IDLE;
    BackMassage_Model_B.Out_LumbarBag[1] = BagState_IDLE;
    BackMassage_Model_DW.is_READY = BackMassag_IN_NO_ACTIVE_CHILD_g;
    break;

   case BackMassage_Model_IN_RWD:
    BackMassage_Model_DW.is_RWD = BackMassag_IN_NO_ACTIVE_CHILD_g;
    BackMassage_Model_B.Out_LumbarBag[0] = BagState_IDLE;
    BackMassage_Model_B.Out_LumbarBag[1] = BagState_IDLE;
    BackMassage_Model_DW.is_READY = BackMassag_IN_NO_ACTIVE_CHILD_g;
    break;

   case BackMassage_Model_IN_down:
    BackMassage_Model_DW.is_up_bag_k = BackMassag_IN_NO_ACTIVE_CHILD_g;
    BackMassage_Model_DW.is_down_bag_p = BackMassag_IN_NO_ACTIVE_CHILD_g;
    BackMassage_Model_B.Out_LumbarBag[0] = BagState_IDLE;
    BackMassage_Model_B.Out_LumbarBag[1] = BagState_IDLE;
    BackMassage_Model_DW.is_READY = BackMassag_IN_NO_ACTIVE_CHILD_g;
    break;

   case BackMassage_Model_IN_up:
    BackMassage_Model_DW.is_down_bag = BackMassag_IN_NO_ACTIVE_CHILD_g;
    BackMassage_Model_DW.is_up_bag = BackMassag_IN_NO_ACTIVE_CHILD_g;
    BackMassage_Model_B.Out_LumbarBag[0] = BagState_IDLE;
    BackMassage_Model_B.Out_LumbarBag[1] = BagState_IDLE;
    BackMassage_Model_DW.is_READY = BackMassag_IN_NO_ACTIVE_CHILD_g;
    break;

   default:
    BackMassage_Model_DW.is_IDLE = BackMassag_IN_NO_ACTIVE_CHILD_g;
    BackMassage_Model_DW.is_READY = BackMassag_IN_NO_ACTIVE_CHILD_g;
    break;
  }
}

/* Function for Chart: '<Root>/Passive_Lumbar' */
static void BackMassage_M_enter_internal_up(void)
{
  BackMassage_Model_DW.is_up_bag = BackMassage_Model_IN_start;
  BackMassage_Model_DW.isStable_h = false;
  BackMassage_Model_DW.is_down_bag = BackMassage_Model_IN_Deflation;
  BackMassage_Model_DW.temporalCounter_i2 = 0U;
  BackMassage_Model_B.Out_bValvePowerState = true;
  BackMassage_Model_B.Out_LumbarBag[1] = BagState_Leakage;
}

/* Function for Chart: '<Root>/Passive_Lumbar' */
static void BackMassage_enter_internal_down(void)
{
  BackMassage_Model_DW.is_down_bag_p = BackMassage_Model_IN_start;
  BackMassage_Model_DW.isStable_h = false;
  BackMassage_Model_DW.is_up_bag_k = BackMassage_Model_IN_Deflation;
  BackMassage_Model_DW.temporalCounter_i2 = 0U;
  BackMassage_Model_B.Out_bValvePowerState = true;
  BackMassage_Model_B.Out_LumbarBag[0] = BagState_Leakage;
}

/* Function for Chart: '<Root>/Passive_Lumbar' */
static void BackMassage_Model_READY(void)
{
  /* Inport: '<Root>/In_Fault' incorporates:
   *  DataStoreRead: '<Root>/Data Store Read10'
   *  Inport: '<Root>/In_LumbarFunc'
   */
  if (AppInto_FaultState != 0) {
    BackMassage_exit_internal_READY();
    BackMassage_Model_DW.isStable_h = false;
    BackMassage_Model_DW.is_c12_BackMassage_Model = BackMassage_Model_IN_IDLE_i;
    BackMassage_Model_DW.App_RunState.Passive_Lumbar = false;
    BackMassage_Model_B.Out_bValvePowerState = false;
    BackMassage_Model_B.Out_LumbarBag[0] = BagState_IDLE;
    BackMassage_Model_B.Out_bPumpState[0] = false;
    BackMassage_Model_B.Out_LumbarBag[1] = BagState_IDLE;
    BackMassage_Model_B.Out_bPumpState[1] = false;
  } else if (!BackMassage_Model_DW.App_Func_En.Passive_Lumbar) {
    BackMassage_exit_internal_READY();
    BackMassage_Model_DW.isStable_h = false;
    BackMassage_Model_DW.is_c12_BackMassage_Model = BackMassage_Model_IN_Buffer;
    BackMassage_Model_DW.temporalCounter_i1_h = 0U;
    BackMassage_Model_B.Out_LumbarBag[0] = BagState_IDLE;
    BackMassage_Model_B.Out_LumbarBag[1] = BagState_IDLE;
  } else if (AppInto_LumbarFunc != BackMassage_Model_DW.Loc_Backup_lumMode) {
    /* Inport: '<Root>/In_LumbarFunc' */
    BackMassage_Model_DW.Loc_Backup_lumMode = AppInto_LumbarFunc;
    switch (AppInto_LumbarFunc) {
     case 1:
      BackMassage_exit_internal_READY();
      BackMassage_Model_DW.is_READY = BackMassage_Model_IN_up;
      BackMassage_M_enter_internal_up();
      break;

     case 2:
      BackMassage_exit_internal_READY();
      BackMassage_Model_DW.is_READY = BackMassage_Model_IN_down;
      BackMassage_enter_internal_down();
      break;

     case 3:
      BackMassage_exit_internal_READY();
      BackMassage_Model_DW.is_READY = BackMassage_Model_IN_FWD;
      BackMassage_Model_DW.is_up_bag_h = BackMassage_Model_IN_start;
      BackMassage_Model_DW.isStable_h = false;
      BackMassage_Model_DW.is_down_bag_g = BackMassage_Model_IN_start;
      break;

     case 4:
      BackMassage_exit_internal_READY();
      BackMassage_Model_DW.is_READY = BackMassage_Model_IN_RWD;
      BackMassage_Model_DW.isStable_h = false;
      BackMassage_Model_DW.is_RWD = BackMassage_Mode_IN_Inflation_n;
      BackMassage_Model_DW.temporalCounter_i1_h = 0U;
      BackMassage_Model_B.Out_bValvePowerState = true;
      BackMassage_Model_B.Out_bPumpState[0] = false;
      BackMassage_Model_B.Out_LumbarBag[0] = BagState_Leakage;
      BackMassage_Model_B.Out_bPumpState[1] = false;
      BackMassage_Model_B.Out_LumbarBag[1] = BagState_Leakage;
      break;

     default:
      BackMassage_exit_internal_READY();
      BackMassage_Model_DW.is_READY = BackMassage_Model_IN_IDLE_i;
      BackMassage_Model_B.Out_LumbarBag[0] = BagState_IDLE;
      BackMassage_Model_B.Out_LumbarBag[1] = BagState_IDLE;
      BackMassage_Model_B.Out_bValvePowerState = false;
      BackMassage_Model_DW.isStable_h = false;
      BackMassage_Model_DW.is_IDLE = BackMassage_Model_IN_Start_bo;
      break;
    }
  } else {
    switch (BackMassage_Model_DW.is_READY) {
     case BackMassage_Model_IN_FWD:
      BackMassage_Model_FWD();
      break;

     case BackMassage_Model_IN_IDLE_i:
      BackMassage_Model_B.Out_LumbarBag[0] = BagState_IDLE;
      BackMassage_Model_B.Out_LumbarBag[1] = BagState_IDLE;
      BackMassage_Model_B.Out_bValvePowerState = false;
      switch (BackMassage_Model_DW.is_IDLE) {
       case BackMassage_Model_IN_Start_bo:
        if (BackMassage_Model_any(BackMassage_Model_B.Out_bPumpState)) {
          BackMassage_Model_DW.isStable_h = false;
          BackMassage_Model_DW.is_IDLE = BackMassage_Model_IN_delay;
          BackMassage_Model_DW.temporalCounter_i1_h = 0U;
        } else {
          BackMassage_Model_DW.isStable_h = false;
          BackMassage_Model_DW.is_IDLE = BackMassage_Model_IN_end;
          BackMassage_Model_B.Out_bPumpState[0] = false;
          BackMassage_Model_B.Out_bPumpState[1] = false;
        }
        break;

       case BackMassage_Model_IN_delay:
        if (BackMassage_Model_DW.temporalCounter_i1_h >= 50U) {
          BackMassage_Model_B.Out_bPumpState[0] = false;
          BackMassage_Model_B.Out_bPumpState[1] = false;
        }
        break;

       default:
        /* case IN_end: */
        break;
      }
      break;

     case BackMassage_Model_IN_RWD:
      if (BackMassage_Model_DW.is_RWD == BackMassage_Mode_IN_Inflation_n) {
        if (BackMassage_Model_DW.temporalCounter_i1_h * 10 >= ((uint16_T)
             MaxDeflation_T)) {
          BackMassage_Model_DW.isStable_h = false;
          BackMassage_Model_DW.is_RWD = BackMassage_Model_IN_idle_m;
          BackMassage_Model_B.Out_bValvePowerState = false;
          BackMassage_Model_B.Out_LumbarBag[0] = BagState_IDLE;
          BackMassage_Model_B.Out_bPumpState[0] = false;
          BackMassage_Model_B.Out_LumbarBag[1] = BagState_IDLE;
          BackMassage_Model_B.Out_bPumpState[1] = false;
        } else {
          BackMassage_Model_B.Out_bValvePowerState = true;
          BackMassage_Model_B.Out_bPumpState[0] = false;
          BackMassage_Model_B.Out_LumbarBag[0] = BagState_Leakage;
          BackMassage_Model_B.Out_bPumpState[1] = false;
          BackMassage_Model_B.Out_LumbarBag[1] = BagState_Leakage;
        }
      } else {
        /* case IN_idle: */
      }
      break;

     case BackMassage_Model_IN_down:
      switch (BackMassage_Model_DW.is_down_bag_p) {
       case BackMassage_Mode_IN_Inflation_n:
        if ((BackMassage_Model_DW.temporalCounter_i1_h * 10 >= ((uint16_T)
              MaxInflation_T)) || (AppInto_LumbarPress[1] > Lumbar_OverPress)) {
          BackMassage_Model_DW.isStable_h = false;
          BackMassage_Model_DW.is_down_bag_p = BackMassage_Model_IN_idle_m;
          BackMassage_Model_DW.temporalCounter_i1_h = 0U;
          BackMassage_Model_B.Out_LumbarBag[1] = BagState_IDLE;
        } else {
          BackMassage_Model_B.Out_bValvePowerState = true;
          BackMassage_Model_B.Out_LumbarBag[1] = BagState_Inflation;
          BackMassage_Model_B.Out_bPumpState[1] = true;
        }
        break;

       case BackMassage_Model_IN_idle_m:
        if (BackMassage_Model_DW.temporalCounter_i1_h >= 50U) {
          BackMassage_Model_B.Out_bPumpState[1] = false;
        }
        break;

       default:
        /* Inport: '<Root>/In_LumbarPress' */
        /* case IN_start: */
        if (AppInto_LumbarPress[1] < Lumbar_OverPress) {
          BackMassage_Model_DW.isStable_h = false;
          BackMassage_Model_DW.is_down_bag_p = BackMassage_Mode_IN_Inflation_n;
          BackMassage_Model_DW.temporalCounter_i1_h = 0U;
          BackMassage_Model_B.Out_bValvePowerState = true;
          BackMassage_Model_B.Out_LumbarBag[1] = BagState_Inflation;
          BackMassage_Model_B.Out_bPumpState[1] = true;
        } else {
          BackMassage_Model_DW.isStable_h = false;
          BackMassage_Model_DW.is_down_bag_p = BackMassage_Model_IN_idle_m;
          BackMassage_Model_DW.temporalCounter_i1_h = 0U;
          BackMassage_Model_B.Out_LumbarBag[1] = BagState_IDLE;
        }
        break;
      }

      if (BackMassage_Model_DW.is_up_bag_k == BackMassage_Model_IN_Deflation) {
        if (BackMassage_Model_DW.temporalCounter_i2 * 10 >= ((uint16_T)
             MaxDeflation_T)) {
          BackMassage_Model_DW.isStable_h = false;
          BackMassage_Model_DW.is_up_bag_k = BackMassage_Model_IN_idle_m;
          BackMassage_Model_B.Out_LumbarBag[0] = BagState_IDLE;
        } else {
          BackMassage_Model_B.Out_bValvePowerState = true;
          BackMassage_Model_B.Out_LumbarBag[0] = BagState_Leakage;
        }
      } else {
        /* case IN_idle: */
      }
      break;

     default:
      /* case IN_up: */
      switch (BackMassage_Model_DW.is_up_bag) {
       case BackMassage_Mode_IN_Inflation_n:
        if ((BackMassage_Model_DW.temporalCounter_i1_h * 10 >= ((uint16_T)
              MaxInflation_T)) || (AppInto_LumbarPress[0] > Lumbar_OverPress)) {
          BackMassage_Model_DW.isStable_h = false;
          BackMassage_Model_DW.is_up_bag = BackMassage_Model_IN_idle_m;
          BackMassage_Model_DW.temporalCounter_i1_h = 0U;
          BackMassage_Model_B.Out_LumbarBag[0] = BagState_IDLE;
        } else {
          BackMassage_Model_B.Out_bValvePowerState = true;
          BackMassage_Model_B.Out_LumbarBag[0] = BagState_Inflation;
          BackMassage_Model_B.Out_bPumpState[0] = true;
        }
        break;

       case BackMassage_Model_IN_idle_m:
        if (BackMassage_Model_DW.temporalCounter_i1_h >= 50U) {
          BackMassage_Model_B.Out_bPumpState[0] = false;
        }
        break;

       default:
        /* Inport: '<Root>/In_LumbarPress' */
        /* case IN_start: */
        if (AppInto_LumbarPress[0] < Lumbar_OverPress) {
          BackMassage_Model_DW.isStable_h = false;
          BackMassage_Model_DW.is_up_bag = BackMassage_Mode_IN_Inflation_n;
          BackMassage_Model_DW.temporalCounter_i1_h = 0U;
          BackMassage_Model_B.Out_bValvePowerState = true;
          BackMassage_Model_B.Out_LumbarBag[0] = BagState_Inflation;
          BackMassage_Model_B.Out_bPumpState[0] = true;
        } else {
          BackMassage_Model_DW.isStable_h = false;
          BackMassage_Model_DW.is_up_bag = BackMassage_Model_IN_idle_m;
          BackMassage_Model_DW.temporalCounter_i1_h = 0U;
          BackMassage_Model_B.Out_LumbarBag[0] = BagState_IDLE;
        }
        break;
      }

      if (BackMassage_Model_DW.is_down_bag == BackMassage_Model_IN_Deflation) {
        if (BackMassage_Model_DW.temporalCounter_i2 * 10 >= ((uint16_T)
             MaxDeflation_T)) {
          BackMassage_Model_DW.isStable_h = false;
          BackMassage_Model_DW.is_down_bag = BackMassage_Model_IN_idle_m;
          BackMassage_Model_B.Out_LumbarBag[1] = BagState_IDLE;
        } else {
          BackMassage_Model_B.Out_bValvePowerState = true;
          BackMassage_Model_B.Out_LumbarBag[1] = BagState_Leakage;
        }
      } else {
        /* case IN_idle: */
      }
      break;
    }
  }

  /* End of Inport: '<Root>/In_Fault' */
}

/* Function for Chart: '<Root>/Massage_of_stateflow' */
static boolean_T BackMassage_F_MassageTimeUpdata(void)
{
  boolean_T Output;
  if (BackMassage_Model_DW.MA_TimeUpdata.Massage ||
      BackMassage_Model_DW.MA_TimeUpdata.Grade) {
    Output = true;
    BackMassage_Model_DW.MA_TimeUpdata.Massage = false;
    BackMassage_Model_DW.MA_TimeUpdata.Grade = false;
  } else {
    Output = false;
  }

  return Output;
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Function for Chart: '<Root>/Massage_of_stateflow' */
static void broadcast_MassageUpdate_t_c2_Ba(void)
{
  int32_T b_previousEvent;
  b_previousEvent = BackMassage_Model_DW.sfEvent;
  BackMassage_Model_DW.sfEvent = BackMassa_event_MassageUpdate_t;

  /* Chart: '<Root>/Massage_of_stateflow' */
  BackMassag_c2_BackMassage_Model();
  BackMassage_Model_DW.sfEvent = b_previousEvent;
}

/* Function for Chart: '<Root>/Massage_of_stateflow' */
static void BackMassage_Mode_Asyn_Get_Array(const uint8_T Array[8], boolean_T
  Value, boolean_T Output[8])
{
  int32_T i;
  uint8_T Loc_Count;
  Loc_Count = 0U;
  for (i = 0; i < 8; i++) {
    Output[i] = false;
    if (Array[i] == 1) {
      Loc_Count++;
      if ((Loc_Count & 1) == 1) {
        Output[i] = Value;
      } else {
        Output[i] = !Value;
      }
    }
  }
}

/* Function for Chart: '<Root>/Massage_of_stateflow' */
static void BackMassage_Model_List_Legal(uint8_T List_Max)
{
  if (BackMassage_Model_DW.Loc_RunList == 0) {
    BackMassage_Model_DW.Loc_RunList = 1U;
  } else if (BackMassage_Model_DW.Loc_RunList > List_Max) {
    BackMassage_Model_DW.Loc_RunList = List_Max;
  }
}

/* Function for Chart: '<Root>/Massage_of_stateflow' */
static void BackMassage_Model_MassageRun(void)
{
  int32_T i;
  switch (BackMassage_Model_B.Add) {
   case 1:
    BackMassage_Model_List_Legal(4);
    for (i = 0; i < 11; i++) {
      BackMassage_Model_DW.Loc_BagInfo[i] =
        MassageMode1[BackMassage_Model_DW.Loc_RunList - 1][i];
    }

    for (i = 0; i < 7; i++) {
      BackMassage_Model_DW.Loc_TimeInfo[i] =
        MassageTime1[BackMassage_Model_DW.Loc_RunList - 1][i];
    }
    break;

   case 2:
    BackMassage_Model_List_Legal(4);
    for (i = 0; i < 11; i++) {
      BackMassage_Model_DW.Loc_BagInfo[i] =
        MassageMode2[BackMassage_Model_DW.Loc_RunList - 1][i];
    }

    for (i = 0; i < 7; i++) {
      BackMassage_Model_DW.Loc_TimeInfo[i] =
        MassageTime2[BackMassage_Model_DW.Loc_RunList - 1][i];
    }
    break;

   case 3:
    BackMassage_Model_List_Legal(8);
    for (i = 0; i < 11; i++) {
      BackMassage_Model_DW.Loc_BagInfo[i] =
        MassageMode3[BackMassage_Model_DW.Loc_RunList - 1][i];
    }

    for (i = 0; i < 7; i++) {
      BackMassage_Model_DW.Loc_TimeInfo[i] =
        MassageTime3[BackMassage_Model_DW.Loc_RunList - 1][i];
    }
    break;

   case 4:
    BackMassage_Model_List_Legal(6);
    for (i = 0; i < 11; i++) {
      BackMassage_Model_DW.Loc_BagInfo[i] =
        MassageMode4[BackMassage_Model_DW.Loc_RunList - 1][i];
    }

    for (i = 0; i < 7; i++) {
      BackMassage_Model_DW.Loc_TimeInfo[i] =
        MassageTime4[BackMassage_Model_DW.Loc_RunList - 1][i];
    }
    break;

   case 5:
    BackMassage_Model_List_Legal(4);
    for (i = 0; i < 11; i++) {
      BackMassage_Model_DW.Loc_BagInfo[i] =
        MassageMode5[BackMassage_Model_DW.Loc_RunList - 1][i];
    }

    for (i = 0; i < 7; i++) {
      BackMassage_Model_DW.Loc_TimeInfo[i] =
        MassageTime5[BackMassage_Model_DW.Loc_RunList - 1][i];
    }
    break;

   case 6:
    BackMassage_Model_List_Legal(4);
    for (i = 0; i < 11; i++) {
      BackMassage_Model_DW.Loc_BagInfo[i] =
        MassageMode6[BackMassage_Model_DW.Loc_RunList - 1][i];
    }

    for (i = 0; i < 7; i++) {
      BackMassage_Model_DW.Loc_TimeInfo[i] =
        MassageTime6[BackMassage_Model_DW.Loc_RunList - 1][i];
    }
    break;

   case 7:
    BackMassage_Model_List_Legal(2);
    for (i = 0; i < 11; i++) {
      BackMassage_Model_DW.Loc_BagInfo[i] =
        MassageMode7[BackMassage_Model_DW.Loc_RunList - 1][i];
    }

    for (i = 0; i < 7; i++) {
      BackMassage_Model_DW.Loc_TimeInfo[i] =
        MassageTime7[BackMassage_Model_DW.Loc_RunList - 1][i];
    }
    break;

   case 8:
    BackMassage_Model_List_Legal(2);
    for (i = 0; i < 11; i++) {
      BackMassage_Model_DW.Loc_BagInfo[i] =
        MassageMode8[BackMassage_Model_DW.Loc_RunList - 1][i];
    }

    for (i = 0; i < 7; i++) {
      BackMassage_Model_DW.Loc_TimeInfo[i] =
        MassageTime8[BackMassage_Model_DW.Loc_RunList - 1][i];
    }
    break;

   default:
    for (i = 0; i < 11; i++) {
      BackMassage_Model_DW.Loc_BagInfo[i] = 0U;
    }
    break;
  }
}

/* Function for Chart: '<Root>/Massage_of_stateflow' */
static void BackMassag_exit_internal_Enable(void)
{
  int32_T i;
  switch (BackMassage_Model_DW.is_Enable) {
   case BackMassage_Model_IN_Knock:
    BackMassage_Model_DW.is_bag1 = BackMassag_IN_NO_ACTIVE_CHILD_g;
    BackMassage_Model_DW.is_Knock = BackMassag_IN_NO_ACTIVE_CHILD_g;
    for (i = 0; i < 8; i++) {
      BackMassage_Model_B.Out_BagState[i] = false;
    }

    BackMassage_Model_DW.is_Enable = BackMassag_IN_NO_ACTIVE_CHILD_g;
    break;

   case BackMassage_Mod_IN_asynchronous:
    BackMassage_Model_DW.is_bag1_g = BackMassag_IN_NO_ACTIVE_CHILD_g;
    BackMassage_Model_DW.is_asynchronous = BackMassag_IN_NO_ACTIVE_CHILD_g;
    for (i = 0; i < 8; i++) {
      BackMassage_Model_B.Out_BagState[i] = false;
    }

    BackMassage_Model_DW.is_Enable = BackMassag_IN_NO_ACTIVE_CHILD_g;
    break;

   default:
    BackMassage_Model_DW.is_Dot = BackMassag_IN_NO_ACTIVE_CHILD_g;
    BackMassage_Model_DW.is_Enable = BackMassag_IN_NO_ACTIVE_CHILD_g;
    break;
  }
}

/* Function for Chart: '<Root>/Massage_of_stateflow' */
static void BackMassa_enter_internal_Enable(void)
{
  int32_T i;
  BackMassage_Model_DW.Loc_MassageReqPre = BackMassage_Model_B.Add;
  BackMassage_Model_MassageRun();
  switch (BackMassage_Model_DW.Loc_BagInfo[9]) {
   case 1:
    BackMassage_Model_DW.is_Enable = BackMassage_Model_IN_Dot;
    BackMassage_Model_B.Out_ValvePowerState_j = true;
    BackMassage_Model_B.Out_PumpState_l = true;
    BackMassage_Model_DW.isStable_e = false;
    BackMassage_Model_DW.is_Dot = BackMassage_Model_IN_Dot_IDLE;
    BackMassage_Model_DW.temporalCounter_i1 = 0U;
    for (i = 0; i < 8; i++) {
      BackMassage_Model_B.Out_BagState[i] = false;
    }
    break;

   case 2:
    BackMassage_Model_DW.is_Enable = BackMassage_Model_IN_Knock;
    BackMassage_Model_DW.Loc_FcnCnt = 0.0;
    BackMassage_Model_B.Out_ValvePowerState_j = true;
    BackMassage_Model_B.Out_PumpState_l = true;
    BackMassage_Model_DW.isStable_e = false;
    BackMassage_Model_DW.is_Knock = BackMassage_Model_IN_Knock_IDLE;
    BackMassage_Model_DW.temporalCounter_i1 = 0U;
    for (i = 0; i < 8; i++) {
      BackMassage_Model_B.Out_BagState[i] = false;
    }
    break;

   case 3:
    BackMassage_Model_DW.is_Enable = BackMassage_Mod_IN_asynchronous;
    BackMassage_Model_DW.Loc_FcnCnt = 0.0;
    BackMassage_Model_B.Out_ValvePowerState_j = true;
    BackMassage_Model_B.Out_PumpState_l = true;
    BackMassage_Model_DW.isStable_e = false;
    BackMassage_Model_DW.is_asynchronous = BackMassage_Model_IN_Knock_IDLE;
    BackMassage_Model_DW.temporalCounter_i1 = 0U;
    for (i = 0; i < 8; i++) {
      BackMassage_Model_B.Out_BagState[i] = false;
    }
    break;

   default:
    BackMassage_Model_DW.isStable_e = false;
    BackMassage_Model_DW.is_Enable = BackMassage_Model_IN_other;
    for (i = 0; i < 8; i++) {
      BackMassage_Model_B.Out_BagState[i] = false;
    }

    BackMassage_Model_B.Out_ValvePowerState_j = false;
    BackMassage_Model_B.Out_PumpState_l = false;
    BackMassage_Model_DW.Loc_MA_Time = 0U;
    break;
  }
}

/* Function for Chart: '<Root>/Massage_of_stateflow' */
static void BackMassage_Model_Enable(void)
{
  int32_T i;
  uint8_T tmp[8];
  static const int8_T b[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };

  if (BackMassage_Model_B.Add != BackMassage_Model_DW.Loc_MassageReqPre) {
    BackMassag_exit_internal_Enable();
    BackMassage_Model_DW.durationCounter_2 = 0;
    BackMassage_Model_DW.is_c2_BackMassage_Model = BackMassage_Model_IN_Enable;
    BackMassage_Model_DW.App_RunState.Massage = true;
    BackMassage_Model_DW.Loc_RunList = 1U;
    BackMassage_Model_DW.Record_List = 1U;
    BackMassage_Model_DW.Loc_TimeState = BackMassage_F_MassageTimeUpdata();
    BackMassage_Model_DW.Loc_MA_Time = 0U;
    BackMassa_enter_internal_Enable();
  } else if (!BackMassage_Model_DW.App_Func_En.Massage) {
    BackMassag_exit_internal_Enable();
    BackMassage_Model_DW.isStable_e = false;
    BackMassage_Model_DW.is_c2_BackMassage_Model = BackMassage_Model_IN_Start_f;
    BackMassage_Model_DW.App_RunState.Massage = false;
    for (i = 0; i < 8; i++) {
      BackMassage_Model_B.Out_BagState[i] = false;
    }

    BackMassage_Model_B.Out_ValvePowerState_j = false;
    BackMassage_Model_B.Out_PumpState_l = false;
    BackMassage_Model_DW.Loc_MA_Time = 0U;
  } else {
    BackMassage_Model_DW.Record_List = BackMassage_Model_DW.Loc_RunList;
    BackMassage_Model_DW.Loc_TimeState = BackMassage_F_MassageTimeUpdata();
    if (BackMassage_Model_DW.Loc_TimeState) {
      BackMassage_Model_DW.durationCounter_2 = 0;
    }

    i = (int32_T)rt_roundd_snf(0.01 * (real_T)
      BackMassage_Model_DW.durationCounter_2);
    if (i >= 0) {
      BackMassage_Model_DW.Loc_MA_Time = (uint32_T)i;
    } else {
      BackMassage_Model_DW.Loc_MA_Time = 0U;
    }

    if (BackMassage_Model_DW.sfEvent == BackMassa_event_MassageUpdate_t) {
      BackMassage_Model_DW.Loc_MassageReqPre = BackMassage_Model_B.Add;
      BackMassage_Model_MassageRun();
      switch (BackMassage_Model_DW.Loc_BagInfo[9]) {
       case 1:
        BackMassag_exit_internal_Enable();
        BackMassage_Model_DW.is_Enable = BackMassage_Model_IN_Dot;
        BackMassage_Model_B.Out_ValvePowerState_j = true;
        BackMassage_Model_B.Out_PumpState_l = true;
        BackMassage_Model_DW.isStable_e = false;
        BackMassage_Model_DW.is_Dot = BackMassage_Model_IN_Dot_IDLE;
        BackMassage_Model_DW.temporalCounter_i1 = 0U;
        for (i = 0; i < 8; i++) {
          BackMassage_Model_B.Out_BagState[i] = false;
        }
        break;

       case 2:
        BackMassag_exit_internal_Enable();
        BackMassage_Model_DW.is_Enable = BackMassage_Model_IN_Knock;
        BackMassage_Model_DW.Loc_FcnCnt = 0.0;
        BackMassage_Model_B.Out_ValvePowerState_j = true;
        BackMassage_Model_B.Out_PumpState_l = true;
        BackMassage_Model_DW.isStable_e = false;
        BackMassage_Model_DW.is_Knock = BackMassage_Model_IN_Knock_IDLE;
        BackMassage_Model_DW.temporalCounter_i1 = 0U;
        for (i = 0; i < 8; i++) {
          BackMassage_Model_B.Out_BagState[i] = false;
        }
        break;

       case 3:
        BackMassag_exit_internal_Enable();
        BackMassage_Model_DW.is_Enable = BackMassage_Mod_IN_asynchronous;
        BackMassage_Model_DW.Loc_FcnCnt = 0.0;
        BackMassage_Model_B.Out_ValvePowerState_j = true;
        BackMassage_Model_B.Out_PumpState_l = true;
        BackMassage_Model_DW.isStable_e = false;
        BackMassage_Model_DW.is_asynchronous = BackMassage_Model_IN_Knock_IDLE;
        BackMassage_Model_DW.temporalCounter_i1 = 0U;
        for (i = 0; i < 8; i++) {
          BackMassage_Model_B.Out_BagState[i] = false;
        }
        break;

       default:
        BackMassag_exit_internal_Enable();
        BackMassage_Model_DW.isStable_e = false;
        BackMassage_Model_DW.is_Enable = BackMassage_Model_IN_other;
        for (i = 0; i < 8; i++) {
          BackMassage_Model_B.Out_BagState[i] = false;
        }

        BackMassage_Model_B.Out_ValvePowerState_j = false;
        BackMassage_Model_B.Out_PumpState_l = false;
        BackMassage_Model_DW.Loc_MA_Time = 0U;
        break;
      }
    } else {
      switch (BackMassage_Model_DW.is_Enable) {
       case BackMassage_Model_IN_Dot:
        {
          BackMassage_Model_B.Out_ValvePowerState_j = true;
          BackMassage_Model_B.Out_PumpState_l = true;
          switch (BackMassage_Model_DW.is_Dot) {
           case BackMassage_Model_IN_Dot_IDLE:
            if ((((uint16_T)PauseTime) == 0) || ((uint32_T)((int32_T)
                  BackMassage_Model_DW.temporalCounter_i1 * 10) >= ((uint16_T)
                  PauseTime))) {
              BackMassage_Model_DW.isStable_e = false;
              BackMassage_Model_DW.is_Dot = BackMassage_Model_IN_Dot_run;
              BackMassage_Model_DW.temporalCounter_i1 = 0U;
              for (i = 0; i < 8; i++) {
                BackMassage_Model_B.Out_BagState[i] =
                  (BackMassage_Model_DW.Loc_BagInfo[b[i]] != 0);
              }
            }
            break;

           case BackMassage_Model_IN_Dot_run:
            {
              uint8_T tmp_0;
              if (BackMassage_Model_B.Saturation > 127) {
                tmp_0 = MAX_uint8_T;
              } else {
                tmp_0 = (uint8_T)(BackMassage_Model_B.Saturation << 1);
              }

              if ((uint32_T)((int32_T)BackMassage_Model_DW.temporalCounter_i1 *
                             10) >= BackMassage_Model_DW.Loc_TimeInfo[tmp_0 - 1])
              {
                BackMassage_Model_DW.isStable_e = false;
                BackMassage_Model_DW.is_Dot = BackMassage_Model_IN_IDLE_d;
                for (i = 0; i < 8; i++) {
                  BackMassage_Model_B.Out_BagState[i] = false;
                }

                BackMassage_Model_DW.Loc_RunList =
                  BackMassage_Model_DW.Loc_BagInfo[10];
                broadcast_MassageUpdate_t_c2_Ba();
              }
            }
            break;

           case BackMassage_Model_IN_IDLE_d:
            break;
          }
        }
        break;

       case BackMassage_Model_IN_Knock:
        {
          BackMassage_Model_B.Out_ValvePowerState_j = true;
          BackMassage_Model_B.Out_PumpState_l = true;
          switch (BackMassage_Model_DW.is_Knock) {
           case BackMassage_Model_IN_IDLE:
            break;

           case BackMassage_Model_IN_Knock_IDLE:
            if ((((uint16_T)PauseTime) == 0) || ((uint32_T)((int32_T)
                  BackMassage_Model_DW.temporalCounter_i1 * 10) >= ((uint16_T)
                  PauseTime))) {
              BackMassage_Model_DW.is_Knock = BackMassage_Model_IN_bag1;
              BackMassage_Model_DW.isStable_e = false;
              BackMassage_Model_DW.is_bag1 = BackMassage_Model_IN_Knock;
              BackMassage_Model_DW.temporalCounter_i1 = 0U;
              for (i = 0; i < 8; i++) {
                BackMassage_Model_B.Out_BagState[i] =
                  (BackMassage_Model_DW.Loc_BagInfo[b[i]] != 0);
              }
            }
            break;

           case BackMassage_Model_IN_bag1:
            {
              switch (BackMassage_Model_DW.is_bag1) {
               case BackMassage_Mode_IN_Inflation_n:
                {
                  uint8_T tmp_0;
                  if (BackMassage_Model_B.Saturation > 127) {
                    tmp_0 = MAX_uint8_T;
                  } else {
                    tmp_0 = (uint8_T)(BackMassage_Model_B.Saturation << 1);
                  }

                  if ((uint32_T)((int32_T)
                                 BackMassage_Model_DW.temporalCounter_i1 * 10) >=
                      BackMassage_Model_DW.Loc_TimeInfo[tmp_0 - 1]) {
                    if (BackMassage_Model_DW.Loc_FcnCnt >= ((uint8_T)KnockCnt))
                    {
                      BackMassage_Model_DW.is_bag1 =
                        BackMassag_IN_NO_ACTIVE_CHILD_g;
                      BackMassage_Model_DW.isStable_e = false;
                      BackMassage_Model_DW.is_Knock = BackMassage_Model_IN_IDLE;
                      for (i = 0; i < 8; i++) {
                        BackMassage_Model_B.Out_BagState[i] = false;
                      }

                      BackMassage_Model_DW.Loc_RunList =
                        BackMassage_Model_DW.Loc_BagInfo[10];
                      broadcast_MassageUpdate_t_c2_Ba();
                    } else {
                      BackMassage_Model_DW.isStable_e = false;
                      BackMassage_Model_DW.is_bag1 =
                        BackMassage_Model_IN_Leakage_e3;
                      BackMassage_Model_DW.temporalCounter_i1 = 0U;
                      for (i = 0; i < 8; i++) {
                        BackMassage_Model_B.Out_BagState[i] = false;
                      }
                    }
                  }
                }
                break;

               case BackMassage_Model_IN_Knock:
                if ((uint32_T)((int32_T)BackMassage_Model_DW.temporalCounter_i1 *
                               10) >= BackMassage_Model_DW.Loc_TimeInfo[0]) {
                  BackMassage_Model_DW.isStable_e = false;
                  BackMassage_Model_DW.is_bag1 = BackMassage_Model_IN_Leakage_e3;
                  BackMassage_Model_DW.temporalCounter_i1 = 0U;
                  for (i = 0; i < 8; i++) {
                    BackMassage_Model_B.Out_BagState[i] = false;
                  }
                }
                break;

               case BackMassage_Model_IN_Leakage_e3:
                {
                  uint8_T tmp_0;
                  if (BackMassage_Model_B.Saturation > 127) {
                    tmp_0 = MAX_uint8_T;
                  } else {
                    tmp_0 = (uint8_T)(BackMassage_Model_B.Saturation << 1);
                  }

                  i = (int32_T)(tmp_0 + 1U);
                  if (BackMassage_Model_B.Saturation > 127) {
                    tmp_0 = MAX_uint8_T;
                  } else {
                    tmp_0 = (uint8_T)(BackMassage_Model_B.Saturation << 1);
                  }

                  if (tmp_0 + 1U > 255U) {
                    i = 255;
                  }

                  if ((uint32_T)((int32_T)
                                 BackMassage_Model_DW.temporalCounter_i1 * 10) >=
                      BackMassage_Model_DW.Loc_TimeInfo[i - 1]) {
                    BackMassage_Model_DW.isStable_e = false;
                    BackMassage_Model_DW.is_bag1 =
                      BackMassage_Mode_IN_Inflation_n;
                    BackMassage_Model_DW.temporalCounter_i1 = 0U;
                    BackMassage_Model_DW.Loc_FcnCnt++;
                    for (i = 0; i < 8; i++) {
                      BackMassage_Model_B.Out_BagState[i] =
                        (BackMassage_Model_DW.Loc_BagInfo[b[i]] != 0);
                    }
                  }
                }
                break;
              }
            }
            break;
          }
        }
        break;

       case BackMassage_Mod_IN_asynchronous:
        {
          BackMassage_Model_B.Out_ValvePowerState_j = true;
          BackMassage_Model_B.Out_PumpState_l = true;
          switch (BackMassage_Model_DW.is_asynchronous) {
           case BackMassage_Model_IN_IDLE:
            break;

           case BackMassage_Model_IN_Knock_IDLE:
            if ((((uint16_T)PauseTime) == 0) || ((uint32_T)((int32_T)
                  BackMassage_Model_DW.temporalCounter_i1 * 10) >= ((uint16_T)
                  PauseTime))) {
              BackMassage_Model_DW.is_asynchronous = BackMassage_Model_IN_bag1;
              BackMassage_Model_DW.isStable_e = false;
              BackMassage_Model_DW.is_bag1_g = BackMassage_Model_IN_Knock;
              BackMassage_Model_DW.temporalCounter_i1 = 0U;
              for (i = 0; i < 8; i++) {
                BackMassage_Model_B.Out_BagState[i] =
                  (BackMassage_Model_DW.Loc_BagInfo[b[i]] != 0);
              }
            }
            break;

           case BackMassage_Model_IN_bag1:
            {
              switch (BackMassage_Model_DW.is_bag1_g) {
               case BackMassage_Mode_IN_Inflation_n:
                {
                  uint8_T tmp_0;
                  if (BackMassage_Model_B.Saturation > 127) {
                    tmp_0 = MAX_uint8_T;
                  } else {
                    tmp_0 = (uint8_T)(BackMassage_Model_B.Saturation << 1);
                  }

                  if ((uint32_T)((int32_T)
                                 BackMassage_Model_DW.temporalCounter_i1 * 10) >=
                      BackMassage_Model_DW.Loc_TimeInfo[tmp_0 - 1]) {
                    if (BackMassage_Model_DW.Loc_FcnCnt >= ((uint8_T)KnockCnt))
                    {
                      BackMassage_Model_DW.is_bag1_g =
                        BackMassag_IN_NO_ACTIVE_CHILD_g;
                      BackMassage_Model_DW.isStable_e = false;
                      BackMassage_Model_DW.is_asynchronous =
                        BackMassage_Model_IN_IDLE;
                      for (i = 0; i < 8; i++) {
                        BackMassage_Model_B.Out_BagState[i] = false;
                      }

                      BackMassage_Model_DW.Loc_RunList =
                        BackMassage_Model_DW.Loc_BagInfo[10];
                      broadcast_MassageUpdate_t_c2_Ba();
                    } else {
                      BackMassage_Model_DW.isStable_e = false;
                      BackMassage_Model_DW.is_bag1_g =
                        BackMassage_Model_IN_Leakage_e3;
                      BackMassage_Model_DW.temporalCounter_i1 = 0U;
                      for (i = 0; i < 8; i++) {
                        tmp[i] = BackMassage_Model_DW.Loc_BagInfo[b[i]];
                      }

                      BackMassage_Mode_Asyn_Get_Array(tmp, false,
                        BackMassage_Model_B.Out_BagState);
                    }
                  }
                }
                break;

               case BackMassage_Model_IN_Knock:
                if ((uint32_T)((int32_T)BackMassage_Model_DW.temporalCounter_i1 *
                               10) >= BackMassage_Model_DW.Loc_TimeInfo[0]) {
                  BackMassage_Model_DW.isStable_e = false;
                  BackMassage_Model_DW.is_bag1_g =
                    BackMassage_Model_IN_Leakage_e3;
                  BackMassage_Model_DW.temporalCounter_i1 = 0U;
                  for (i = 0; i < 8; i++) {
                    tmp[i] = BackMassage_Model_DW.Loc_BagInfo[b[i]];
                  }

                  BackMassage_Mode_Asyn_Get_Array(tmp, false,
                    BackMassage_Model_B.Out_BagState);
                }
                break;

               case BackMassage_Model_IN_Leakage_e3:
                {
                  uint8_T tmp_0;
                  if (BackMassage_Model_B.Saturation > 127) {
                    tmp_0 = MAX_uint8_T;
                  } else {
                    tmp_0 = (uint8_T)(BackMassage_Model_B.Saturation << 1);
                  }

                  i = (int32_T)(tmp_0 + 1U);
                  if (BackMassage_Model_B.Saturation > 127) {
                    tmp_0 = MAX_uint8_T;
                  } else {
                    tmp_0 = (uint8_T)(BackMassage_Model_B.Saturation << 1);
                  }

                  if (tmp_0 + 1U > 255U) {
                    i = 255;
                  }

                  if ((uint32_T)((int32_T)
                                 BackMassage_Model_DW.temporalCounter_i1 * 10) >=
                      BackMassage_Model_DW.Loc_TimeInfo[i - 1]) {
                    BackMassage_Model_DW.isStable_e = false;
                    BackMassage_Model_DW.is_bag1_g =
                      BackMassage_Mode_IN_Inflation_n;
                    BackMassage_Model_DW.temporalCounter_i1 = 0U;
                    BackMassage_Model_DW.Loc_FcnCnt++;
                    for (i = 0; i < 8; i++) {
                      tmp[i] = BackMassage_Model_DW.Loc_BagInfo[b[i]];
                    }

                    BackMassage_Mode_Asyn_Get_Array(tmp, true,
                      BackMassage_Model_B.Out_BagState);
                  }
                }
                break;
              }
            }
            break;
          }
        }
        break;

       case BackMassage_Model_IN_other:
        for (i = 0; i < 8; i++) {
          BackMassage_Model_B.Out_BagState[i] = false;
        }

        BackMassage_Model_B.Out_ValvePowerState_j = false;
        BackMassage_Model_B.Out_PumpState_l = false;
        BackMassage_Model_DW.Loc_MA_Time = 0U;
        break;
      }
    }
  }
}

/* Function for Chart: '<Root>/Massage_of_stateflow' */
static void BackMassag_c2_BackMassage_Model(void)
{
  int32_T i;

  /* Chart: '<Root>/Massage_of_stateflow' incorporates:
   *  DataStoreRead: '<Root>/Data Store Read13'
   */
  if (BackMassage_Model_DW.is_active_c2_BackMassage_Model == 0U) {
    BackMassage_Model_DW.is_active_c2_BackMassage_Model = 1U;
    BackMassage_Model_DW.durationCounter_2 = 0;
    BackMassage_Model_DW.is_c2_BackMassage_Model = BackMassage_Model_IN_Enable;
    BackMassage_Model_DW.App_RunState.Massage = true;
    BackMassage_Model_DW.Loc_RunList = 1U;
    BackMassage_Model_DW.Record_List = 1U;
    BackMassage_Model_DW.Loc_TimeState = BackMassage_F_MassageTimeUpdata();
    BackMassage_Model_DW.Loc_MA_Time = 0U;
    BackMassa_enter_internal_Enable();
  } else {
    switch (BackMassage_Model_DW.is_c2_BackMassage_Model) {
     case BackMassage_Model_IN_Enable:
      BackMassage_Model_Enable();
      break;

     case BackMassage_Model_IN_Start_f:
      if (BackMassage_Model_DW.App_Func_En.Massage) {
        BackMassage_Model_DW.durationCounter_2 = 0;
        BackMassage_Model_DW.is_c2_BackMassage_Model =
          BackMassage_Model_IN_Enable;
        BackMassage_Model_DW.App_RunState.Massage = true;
        BackMassage_Model_DW.Loc_RunList = 1U;
        BackMassage_Model_DW.Record_List = 1U;
        BackMassage_Model_DW.Loc_TimeState = BackMassage_F_MassageTimeUpdata();
        BackMassage_Model_DW.Loc_MA_Time = 0U;
        BackMassa_enter_internal_Enable();
      } else {
        BackMassage_Model_DW.App_RunState.Massage = false;
        for (i = 0; i < 8; i++) {
          BackMassage_Model_B.Out_BagState[i] = false;
        }

        BackMassage_Model_B.Out_ValvePowerState_j = false;
        BackMassage_Model_B.Out_PumpState_l = false;
        BackMassage_Model_DW.Loc_MA_Time = 0U;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Massage_of_stateflow' */
}

/* Function for Chart: '<Root>/Function_switch' */
static void BackMassage_Model_Func_Init(void)
{
  BackMassage_Model_DW.App_Func_En.Active_Flank = false;
  BackMassage_Model_DW.App_Func_En.Passive_Lumbar = false;
  BackMassage_Model_DW.App_Func_En.Passive_Flank = false;
  BackMassage_Model_DW.App_Func_En.Massage = false;
  BackMassage_Model_DW.App_Func_En.Auto_Lumbar = false;
  BackMassage_Model_DW.App_Func_En.Auto_Flank = false;
  BackMassage_Model_DW.App_Func_En.SensorInit = false;
  BackMassage_Model_DW.App_Func_En.GasStorage = false;
}

/* Function for Chart: '<Root>/Function_switch' */
static void BackMassage_enter_internal_Idle(void)
{
  /* Inport: '<Root>/In_ActiveFlank' incorporates:
   *  Inport: '<Root>/In_AdaptiveLumbar'
   *  Inport: '<Root>/In_Flank_Req'
   *  Inport: '<Root>/In_LumbarFunc'
   *  Inport: '<Root>/In_MassageEn'
   */
  if (AppInto_ActiveFlankEn) {
    BackMassage_Model_DW.App_Func_En.Active_Flank = true;
  } else if (AppInto_LumbarFunc != 0) {
    BackMassage_Model_DW.App_Func_En.Passive_Lumbar = true;
  } else if (AppInto_FlankFunc != 0) {
    BackMassage_Model_DW.App_Func_En.Passive_Flank = true;
  } else if (AppInto_MassageEnable) {
    BackMassage_Model_DW.App_Func_En.Massage = true;
  } else if (AppInto_AdaptiveLumbar) {
    BackMassage_Model_DW.App_Func_En.Auto_Lumbar = true;
    BackMassage_Model_DW.App_RunState.Auto_Lumbar = true;
  } else {
    BackMassage_Model_DW.App_RunState.Auto_Lumbar = false;

    /* Inport: '<Root>/In_AdaptiveFlank' */
    if (AppInto_AdaptiveFlank) {
      BackMassage_Model_DW.App_Func_En.Auto_Flank = true;
      BackMassage_Model_DW.App_RunState.Auto_Flank = true;
    } else {
      BackMassage_Model_DW.App_RunState.Auto_Flank = false;
      BackMassage_Model_DW.App_Func_En.GasStorage = true;
    }

    /* End of Inport: '<Root>/In_AdaptiveFlank' */
  }

  /* End of Inport: '<Root>/In_ActiveFlank' */
}

/* Model step function */
void BackMassage_Model_step(void)
{
  /* local block i/o variables */
  BagState rtb_Out_Bag;
  BagState rtb_Out_Bag_m;
  BagState rtb_Out_Bag_d;
  BagState rtb_Out_Bag_dt;
  boolean_T rtb_Out_PumpState;
  boolean_T rtb_Out_ValvePowerState;
  boolean_T rtb_Out_PumpState_i;
  boolean_T rtb_Out_ValvePowerState_e;
  boolean_T rtb_Out_PumpState_ig;
  boolean_T rtb_Out_ValvePowerState_i;
  boolean_T rtb_Out_PumpState_e;
  boolean_T rtb_Out_ValvePowerState_g;
  int32_T i;
  boolean_T tmp[2];
  boolean_T tmp_0[2];
  boolean_T tmp_1[2];
  boolean_T rtb_Out_bPump;
  boolean_T rtb_Out_bPump_e;
  boolean_T rtb_Out_bValvePower_d;

  /* Chart: '<Root>/Active_Flank' incorporates:
   *  DataStoreRead: '<Root>/Data Store Read9'
   *  Inport: '<Root>/In_ActiveFlankMode'
   *  Inport: '<Root>/In_FlankPress'
   */
  if (BackMassage_Model_DW.temporalCounter_i1_b < 8191U) {
    BackMassage_Model_DW.temporalCounter_i1_b++;
  }

  if (BackMassage_Model_DW.temporalCounter_i2_a < 2047U) {
    BackMassage_Model_DW.temporalCounter_i2_a++;
  }

  if (BackMassage_Model_DW.is_active_c10_BackMassage_Model == 0U) {
    BackMassage_Model_DW.is_active_c10_BackMassage_Model = 1U;
    BackMassage_Model_DW.is_c10_BackMassage_Model = BackMassage_Model_IN_IDLE;
    BackMassage_M_enter_atomic_IDLE();
  } else if (BackMassage_Model_DW.is_c10_BackMassage_Model ==
             BackMassage_Model_IN_IDLE) {
    if (BackMassage_Model_DW.App_Func_En.Active_Flank) {
      BackMassage_Model_DW.is_c10_BackMassage_Model =
        BackMassage_Model_IN_Main_l;
      BackMassage_Model_DW.App_RunState.Active_Flank = true;
      BackMassage_Model_DW.Loc_FlankPress_Save[0] = AppInto_FlankPress[0];
      BackMassage_Model_DW.Loc_FlankPress_Save[1] = AppInto_FlankPress[1];
      BackMass_Reset_GasStorage_Error();
      BackMassage_Model_DW.Loc_save_mode = AppInto_ActiveFlankMode;
      BackMassage_Model_B.Out_GasStorage =
        BackMassage_Model_DW.BeforGasStorageState;
      BackMassage_Model_DW.BeforGasStorageState = false;
      switch (AppInto_ActiveFlankMode) {
       case 1:
        BackMassage_Model_DW.durationCounter_1_c = 0;
        BackMassage_Model_DW.is_Main = BackMassage_Model_IN_mid;
        BackMassage_Model_B.Out_PumpState_j[0] = false;
        BackMassage_Model_B.Out_PumpState_j[1] = false;
        BackMassage_Model_B.Out_GasStorage = false;
        BackMassage__enter_internal_mid();
        break;

       case 2:
        BackMassage_Model_DW.durationCounter_1_e = 0;
        BackMassage_Model_DW.is_Main = BackMassage_Model_IN_Left_Func;
        BackMassage_Model_DW.is_Left_Func = BackMassage_Model_IN_IDLE;
        break;

       case 3:
        BackMassage_Model_DW.durationCounter_1_g = 0;
        BackMassage_Model_DW.is_Main = BackMassage_Model_IN_Right_Func;
        BackMassage_Model_DW.is_Right_Func = BackMassage_Model_IN_IDLE;
        break;

       case 4:
        BackMassage_Model_DW.is_Main = BackMassage_Model_IN_Test_Func;
        BackMa_enter_internal_Test_Func();
        break;

       default:
        BackMassage_Model_DW.is_Main = BackMassage_Model_IN_Idle_f;
        BackMassage_Model_B.Out_FlankBag[0] = BagState_IDLE;
        tmp_1[0] = ((int32_T)BackMassage_Model_B.Out_FlankBag[0] == 0);
        BackMassage_Model_B.Out_FlankBag[1] = BagState_IDLE;
        tmp_1[1] = ((int32_T)BackMassage_Model_B.Out_FlankBag[1] == 0);
        if (!BackMassage_Model_all(tmp_1)) {
          BackMassage_Model_DW.durationCounter_1_c = 0;
          BackMassage_Model_DW.durationCounter_1_e = 0;
          BackMassage_Model_DW.durationCounter_1_g = 0;
        }

        BackMassage_Model_DW.is_Idle = BackMassage_Model_IN_IDLE;
        BackMassage_Model_DW.App_RunState.GasStorage = false;
        BackMassage_Model_B.Out_GasStorage = false;
        BackMassage_Model_B.Out_PumpState_j[0] = false;
        BackMassage_Model_B.Out_ValvePower[0] = false;
        BackMassage_Model_B.Out_PumpState_j[1] = false;
        BackMassage_Model_B.Out_ValvePower[1] = false;
        break;
      }
    } else {
      BackMassage_Model_DW.App_RunState.Active_Flank = false;
      BackMassage_Model_B.Out_GasStorage = false;
      BackMassage_Model_B.Out_PumpState_j[0] = false;
      BackMassage_Model_B.Out_ValvePower[0] = false;
      BackMassage_Model_B.Out_FlankBag[0] = BagState_IDLE;
      tmp_1[0] = ((int32_T)BackMassage_Model_B.Out_FlankBag[0] == 0);
      BackMassage_Model_B.Out_PumpState_j[1] = false;
      BackMassage_Model_B.Out_ValvePower[1] = false;
      BackMassage_Model_B.Out_FlankBag[1] = BagState_IDLE;
      tmp_1[1] = ((int32_T)BackMassage_Model_B.Out_FlankBag[1] == 0);
      if (!BackMassage_Model_all(tmp_1)) {
        BackMassage_Model_DW.durationCounter_1_c = 0;
        BackMassage_Model_DW.durationCounter_1_e = 0;
        BackMassage_Model_DW.durationCounter_1_g = 0;
      }
    }
  } else {
    /* case IN_Main: */
    BackMassage_Model_Main();
  }

  tmp_1[0] = ((int32_T)BackMassage_Model_B.Out_FlankBag[0] == 0);
  tmp[0] = ((int32_T)BackMassage_Model_B.Out_FlankBag[0] == 0);
  tmp_0[0] = ((int32_T)BackMassage_Model_B.Out_FlankBag[0] == 0);
  tmp_1[1] = ((int32_T)BackMassage_Model_B.Out_FlankBag[1] == 0);
  tmp[1] = ((int32_T)BackMassage_Model_B.Out_FlankBag[1] == 0);
  tmp_0[1] = ((int32_T)BackMassage_Model_B.Out_FlankBag[1] == 0);
  if (BackMassage_Model_all(tmp_1)) {
    BackMassage_Model_DW.durationCounter_1_c++;
  } else {
    BackMassage_Model_DW.durationCounter_1_c = 0;
  }

  if (BackMassage_Model_all(tmp)) {
    BackMassage_Model_DW.durationCounter_1_e++;
  } else {
    BackMassage_Model_DW.durationCounter_1_e = 0;
  }

  if (BackMassage_Model_all(tmp_0)) {
    BackMassage_Model_DW.durationCounter_1_g++;
  } else {
    BackMassage_Model_DW.durationCounter_1_g = 0;
  }

  /* End of Chart: '<Root>/Active_Flank' */

  /* Chart: '<Root>/Passive_flank' */
  if (BackMassage_Model_DW.temporalCounter_i1_j < 8191U) {
    BackMassage_Model_DW.temporalCounter_i1_j++;
  }

  i = 0;
  do {
    BackMassage_Model_DW.isStable = true;
    if (BackMassage_Model_DW.is_active_c1_BackMassage_Model == 0U) {
      BackMassage_Model_DW.is_active_c1_BackMassage_Model = 1U;
      BackMassage_Model_DW.isStable = false;
      BackMassage_Model_DW.is_c1_BackMassage_Model =
        BackMassage_Model_IN_Start_f;
      BackMassage_Model_DW.App_RunState.Passive_Flank = false;
      BackMassage_Model_B.Out_ValvePowerState = false;
      BackMassage_Model_B.Out_PumpState = false;
      BackMassage_Model_B.Out_flank_bag[0] = BagState_IDLE;
      BackMassage_Model_B.Out_flank_bag[1] = BagState_IDLE;
    } else if (BackMassage_Model_DW.is_c1_BackMassage_Model ==
               BackMassage_Model_IN_Deal) {
      if (BackMassage_Model_DW.Loc_flank_save != AppInto_FlankFunc) {
        BackMassage_Model_DW.App_RunState.Passive_Flank = true;
        BackMassage_Model_B.Out_flank_bag[0] = BagState_IDLE;
        BackMassage_Model_B.Out_flank_bag[1] = BagState_IDLE;
        BackMassage_enter_internal_Deal();
      } else if (!BackMassage_Model_DW.App_Func_En.Passive_Flank) {
        BackMassage_Model_DW.is_Deal = BackMassag_IN_NO_ACTIVE_CHILD_g;
        BackMassage_Model_DW.isStable = false;
        BackMassage_Model_DW.is_c1_BackMassage_Model =
          BackMassage_Model_IN_Start_f;
        BackMassage_Model_DW.App_RunState.Passive_Flank = false;
        BackMassage_Model_B.Out_ValvePowerState = false;
        BackMassage_Model_B.Out_PumpState = false;
        BackMassage_Model_B.Out_flank_bag[0] = BagState_IDLE;
        BackMassage_Model_B.Out_flank_bag[1] = BagState_IDLE;
      } else {
        switch (BackMassage_Model_DW.is_Deal) {
         case BackMassage_Model_IN_Fwd:
          if ((BackMassage_Model_DW.temporalCounter_i1_j * 10 >= ((uint16_T)
                MaxInflation_T)) || (AppInto_FlankPress[1] > Flank_OverPress)) {
            BackMassage_Model_DW.isStable = false;
            BackMassage_Model_DW.is_Deal = BackMassage_Model_IN_other;
            BackMassage_Model_DW.App_RunState.Passive_Flank = false;
            BackMassage_Model_B.Out_ValvePowerState = false;
            BackMassage_Model_B.Out_PumpState = false;
            BackMassage_Model_B.Out_flank_bag[0] = BagState_IDLE;
            BackMassage_Model_B.Out_flank_bag[1] = BagState_IDLE;
          } else {
            BackMassage_Model_B.Out_ValvePowerState = true;
            BackMassage_Model_B.Out_PumpState = true;
            BackMassage_Model_B.Out_flank_bag[1] = BagState_Inflation;
          }
          break;

         case BackMassage_Model_IN_Rwd:
          if (BackMassage_Model_DW.temporalCounter_i1_j * 10 >= ((uint16_T)
               MaxInflation_T)) {
            BackMassage_Model_DW.isStable = false;
            BackMassage_Model_DW.is_Deal = BackMassage_Model_IN_other;
            BackMassage_Model_DW.App_RunState.Passive_Flank = false;
            BackMassage_Model_B.Out_ValvePowerState = false;
            BackMassage_Model_B.Out_PumpState = false;
            BackMassage_Model_B.Out_flank_bag[0] = BagState_IDLE;
            BackMassage_Model_B.Out_flank_bag[1] = BagState_IDLE;
          } else {
            BackMassage_Model_B.Out_ValvePowerState = true;
            BackMassage_Model_B.Out_PumpState = false;
            BackMassage_Model_B.Out_flank_bag[1] = BagState_Leakage;
          }
          break;

         case BackMassage_Model_IN_down_j:
          if (BackMassage_Model_DW.temporalCounter_i1_j * 10 >= ((uint16_T)
               MaxInflation_T)) {
            BackMassage_Model_DW.isStable = false;
            BackMassage_Model_DW.is_Deal = BackMassage_Model_IN_other;
            BackMassage_Model_DW.App_RunState.Passive_Flank = false;
            BackMassage_Model_B.Out_ValvePowerState = false;
            BackMassage_Model_B.Out_PumpState = false;
            BackMassage_Model_B.Out_flank_bag[0] = BagState_IDLE;
            BackMassage_Model_B.Out_flank_bag[1] = BagState_IDLE;
          } else {
            BackMassage_Model_B.Out_ValvePowerState = true;
            BackMassage_Model_B.Out_PumpState = false;
            BackMassage_Model_B.Out_flank_bag[0] = BagState_Leakage;
          }
          break;

         case BackMassage_Model_IN_other:
          BackMassage_Model_DW.App_RunState.Passive_Flank = false;
          BackMassage_Model_B.Out_ValvePowerState = false;
          BackMassage_Model_B.Out_PumpState = false;
          BackMassage_Model_B.Out_flank_bag[0] = BagState_IDLE;
          BackMassage_Model_B.Out_flank_bag[1] = BagState_IDLE;
          break;

         default:
          /* case IN_up: */
          if ((BackMassage_Model_DW.temporalCounter_i1_j * 10 >= ((uint16_T)
                MaxInflation_T)) || (AppInto_FlankPress[0] > Flank_OverPress)) {
            BackMassage_Model_DW.isStable = false;
            BackMassage_Model_DW.is_Deal = BackMassage_Model_IN_other;
            BackMassage_Model_DW.App_RunState.Passive_Flank = false;
            BackMassage_Model_B.Out_ValvePowerState = false;
            BackMassage_Model_B.Out_PumpState = false;
            BackMassage_Model_B.Out_flank_bag[0] = BagState_IDLE;
            BackMassage_Model_B.Out_flank_bag[1] = BagState_IDLE;
          } else {
            BackMassage_Model_B.Out_ValvePowerState = true;
            BackMassage_Model_B.Out_PumpState = true;
            BackMassage_Model_B.Out_flank_bag[0] = BagState_Inflation;
          }
          break;
        }
      }

      /* case IN_Start: */
    } else if (BackMassage_Model_DW.App_Func_En.Passive_Flank) {
      BackMassage_Model_DW.is_c1_BackMassage_Model = BackMassage_Model_IN_Deal;
      BackMassage_Model_DW.App_RunState.Passive_Flank = true;
      BackMassage_Model_B.Out_flank_bag[0] = BagState_IDLE;
      BackMassage_Model_B.Out_flank_bag[1] = BagState_IDLE;
      BackMassage_enter_internal_Deal();
    } else {
      BackMassage_Model_DW.App_RunState.Passive_Flank = false;
      BackMassage_Model_B.Out_ValvePowerState = false;
      BackMassage_Model_B.Out_PumpState = false;
      BackMassage_Model_B.Out_flank_bag[0] = BagState_IDLE;
      BackMassage_Model_B.Out_flank_bag[1] = BagState_IDLE;
    }

    i = (int32_T)((uint32_T)i + 1U);
  } while ((!BackMassage_Model_DW.isStable) && ((uint32_T)i <= 3U));

  /* End of Chart: '<Root>/Passive_flank' */

  /* Outputs for Atomic SubSystem: '<Root>/Auto_Flank' */
  /* Chart: '<S2>/Left_Flank' incorporates:
   *  DataStoreRead: '<Root>/Data Store Read15'
   *  Inport: '<Root>/In_F_SensorPress'
   *  Inport: '<Root>/In_FlankPress'
   */
  BackMassage_Model_Left_Flank(BackMassage_Model_DW.App_Func_En.Auto_Flank,
    AppInto_FlankPress[0], AppInto_F_SensorPress[0], &rtb_Out_Bag_dt,
    &rtb_Out_PumpState_e, &rtb_Out_ValvePowerState_g,
    &BackMassage_Model_DW.sf_Left_Flank);

  /* Chart: '<S2>/Right_Flank' incorporates:
   *  DataStoreRead: '<Root>/Data Store Read15'
   *  Inport: '<Root>/In_F_SensorPress'
   *  Inport: '<Root>/In_FlankPress'
   */
  BackMassage_Model_Left_Flank(BackMassage_Model_DW.App_Func_En.Auto_Flank,
    AppInto_FlankPress[1], AppInto_F_SensorPress[1], &rtb_Out_Bag_d,
    &rtb_Out_PumpState_ig, &rtb_Out_ValvePowerState_i,
    &BackMassage_Model_DW.sf_Right_Flank);

  /* End of Outputs for SubSystem: '<Root>/Auto_Flank' */

  /* Chart: '<Root>/FuncSelect_Flank' incorporates:
   *  SignalConversion generated from: '<S4>/ SFunction '
   */
  if (BackMassage_Model_DW.App_RunState.Active_Flank) {
    AppOut_FlankBag[0] = BackMassage_Model_B.Out_FlankBag[0];
  } else if (BackMassage_Model_DW.App_RunState.Passive_Flank) {
    AppOut_FlankBag[0] = BackMassage_Model_B.Out_flank_bag[0];
  } else if (BackMassage_Model_DW.App_RunState.Auto_Flank) {
    AppOut_FlankBag[0] = rtb_Out_Bag_dt;
  } else {
    AppOut_FlankBag[0] = BackMassage_Model_B.Out_FlankBag[0];
  }

  if (BackMassage_Model_DW.App_RunState.Active_Flank) {
    AppOut_FlankBag[1] = BackMassage_Model_B.Out_FlankBag[1];
  } else if (BackMassage_Model_DW.App_RunState.Passive_Flank) {
    AppOut_FlankBag[1] = BackMassage_Model_B.Out_flank_bag[1];
  } else if (BackMassage_Model_DW.App_RunState.Auto_Flank) {
    AppOut_FlankBag[1] = rtb_Out_Bag_d;
  } else {
    AppOut_FlankBag[1] = BackMassage_Model_B.Out_FlankBag[1];
  }

  /* End of Chart: '<Root>/FuncSelect_Flank' */

  /* Chart: '<Root>/Passive_Lumbar' */
  if (BackMassage_Model_DW.temporalCounter_i1_h < 8191U) {
    BackMassage_Model_DW.temporalCounter_i1_h++;
  }

  if (BackMassage_Model_DW.temporalCounter_i2 < 8191U) {
    BackMassage_Model_DW.temporalCounter_i2++;
  }

  i = 0;
  do {
    BackMassage_Model_DW.isStable_h = true;
    if (BackMassage_Model_DW.is_active_c12_BackMassage_Model == 0U) {
      BackMassage_Model_DW.is_active_c12_BackMassage_Model = 1U;
      BackMassage_Model_DW.isStable_h = false;
      BackMassage_Model_DW.is_c12_BackMassage_Model =
        BackMassage_Model_IN_IDLE_i;
      BackMassage_Model_DW.App_RunState.Passive_Lumbar = false;
      BackMassage_Model_B.Out_bValvePowerState = false;
      BackMassage_Model_B.Out_LumbarBag[0] = BagState_IDLE;
      BackMassage_Model_B.Out_bPumpState[0] = false;
      BackMassage_Model_B.Out_LumbarBag[1] = BagState_IDLE;
      BackMassage_Model_B.Out_bPumpState[1] = false;
    } else {
      switch (BackMassage_Model_DW.is_c12_BackMassage_Model) {
       case BackMassage_Model_IN_Buffer:
        if ((!BackMassage_Model_any(BackMassage_Model_B.Out_bPumpState)) ||
            (AppInto_FaultState != 0)) {
          BackMassage_Model_DW.isStable_h = false;
          BackMassage_Model_DW.is_c12_BackMassage_Model =
            BackMassage_Model_IN_IDLE_i;
          BackMassage_Model_DW.App_RunState.Passive_Lumbar = false;
          BackMassage_Model_B.Out_bValvePowerState = false;
          BackMassage_Model_B.Out_LumbarBag[0] = BagState_IDLE;
          BackMassage_Model_B.Out_bPumpState[0] = false;
          BackMassage_Model_B.Out_LumbarBag[1] = BagState_IDLE;
          BackMassage_Model_B.Out_bPumpState[1] = false;
        } else if (BackMassage_Model_DW.temporalCounter_i1_h >= 50U) {
          BackMassage_Model_B.Out_bPumpState[0] = false;
          BackMassage_Model_B.Out_bPumpState[1] = false;
        }
        break;

       case BackMassage_Model_IN_IDLE_i:
        if (BackMassage_Model_DW.App_Func_En.Passive_Lumbar) {
          BackMassage_Model_DW.is_c12_BackMassage_Model =
            BackMassage_Model_IN_READY;
          BackMassage_Model_DW.App_RunState.Passive_Lumbar = true;
          BackMassage_Model_B.Out_bValvePowerState = false;
          BackMassage_Model_B.Out_bPumpState[0] = false;
          BackMassage_Model_B.Out_bPumpState[1] = false;
          BackMassage_Model_DW.Loc_Backup_lumMode = AppInto_LumbarFunc;
          switch (AppInto_LumbarFunc) {
           case 1:
            BackMassage_Model_DW.is_READY = BackMassage_Model_IN_up;
            BackMassage_M_enter_internal_up();
            break;

           case 2:
            BackMassage_Model_DW.is_READY = BackMassage_Model_IN_down;
            BackMassage_enter_internal_down();
            break;

           case 3:
            BackMassage_Model_DW.is_READY = BackMassage_Model_IN_FWD;
            BackMassage_Model_DW.is_up_bag_h = BackMassage_Model_IN_start;
            BackMassage_Model_DW.isStable_h = false;
            BackMassage_Model_DW.is_down_bag_g = BackMassage_Model_IN_start;
            break;

           case 4:
            BackMassage_Model_DW.is_READY = BackMassage_Model_IN_RWD;
            BackMassage_Model_DW.isStable_h = false;
            BackMassage_Model_DW.is_RWD = BackMassage_Mode_IN_Inflation_n;
            BackMassage_Model_DW.temporalCounter_i1_h = 0U;
            BackMassage_Model_B.Out_bValvePowerState = true;
            BackMassage_Model_B.Out_bPumpState[0] = false;
            BackMassage_Model_B.Out_LumbarBag[0] = BagState_Leakage;
            BackMassage_Model_B.Out_bPumpState[1] = false;
            BackMassage_Model_B.Out_LumbarBag[1] = BagState_Leakage;
            break;

           default:
            BackMassage_Model_DW.is_READY = BackMassage_Model_IN_IDLE_i;
            BackMassage_Model_B.Out_LumbarBag[0] = BagState_IDLE;
            BackMassage_Model_B.Out_LumbarBag[1] = BagState_IDLE;
            BackMassage_Model_DW.isStable_h = false;
            BackMassage_Model_DW.is_IDLE = BackMassage_Model_IN_Start_bo;
            break;
          }
        }
        break;

       default:
        /* case IN_READY: */
        BackMassage_Model_READY();
        break;
      }
    }

    i = (int32_T)((uint32_T)i + 1U);
  } while ((!BackMassage_Model_DW.isStable_h) && ((uint32_T)i <= 3U));

  /* End of Chart: '<Root>/Passive_Lumbar' */

  /* Outputs for Atomic SubSystem: '<Root>/Auto_Lumbar' */
  /* Chart: '<S3>/Left_Lumbar' incorporates:
   *  DataStoreRead: '<Root>/Data Store Read14'
   *  Inport: '<Root>/In_L_SensorPress'
   *  Inport: '<Root>/In_LumbarPress'
   */
  BackMassage_Model_Left_Lumbar(BackMassage_Model_DW.App_Func_En.Auto_Lumbar,
    AppInto_LumbarPress[0], AppInto_L_SensorPress[0], &rtb_Out_Bag_m,
    &rtb_Out_PumpState_i, &rtb_Out_ValvePowerState_e,
    &BackMassage_Model_DW.sf_Left_Lumbar);

  /* Chart: '<S3>/Right_Lumbar' incorporates:
   *  DataStoreRead: '<Root>/Data Store Read14'
   *  Inport: '<Root>/In_L_SensorPress'
   *  Inport: '<Root>/In_LumbarPress'
   */
  BackMassage_Model_Left_Lumbar(BackMassage_Model_DW.App_Func_En.Auto_Lumbar,
    AppInto_LumbarPress[1], AppInto_L_SensorPress[1], &rtb_Out_Bag,
    &rtb_Out_PumpState, &rtb_Out_ValvePowerState,
    &BackMassage_Model_DW.sf_Right_Lumbar);

  /* End of Outputs for SubSystem: '<Root>/Auto_Lumbar' */

  /* Chart: '<Root>/FuncSelect_Lumbar' incorporates:
   *  SignalConversion generated from: '<S5>/ SFunction '
   */
  if (BackMassage_Model_DW.App_RunState.Passive_Lumbar) {
    AppOut_LumbarBag[0] = BackMassage_Model_B.Out_LumbarBag[0];
  } else if (BackMassage_Model_DW.App_RunState.Auto_Lumbar) {
    AppOut_LumbarBag[0] = rtb_Out_Bag_m;
  } else {
    AppOut_LumbarBag[0] = BackMassage_Model_B.Out_LumbarBag[0];
  }

  if (BackMassage_Model_DW.App_RunState.Passive_Lumbar) {
    AppOut_LumbarBag[1] = BackMassage_Model_B.Out_LumbarBag[1];
  } else if (BackMassage_Model_DW.App_RunState.Auto_Lumbar) {
    AppOut_LumbarBag[1] = rtb_Out_Bag;
  } else {
    AppOut_LumbarBag[1] = BackMassage_Model_B.Out_LumbarBag[1];
  }

  /* End of Chart: '<Root>/FuncSelect_Lumbar' */

  /* Sum: '<S8>/Add' incorporates:
   *  Constant: '<S8>/Constant'
   *  Inport: '<Root>/In_MassageReq'
   */
  BackMassage_Model_B.Add = (uint8_T)(AppInto_MassageMode + 1U);

  /* Saturate: '<S8>/Saturation' incorporates:
   *  Constant: '<S8>/Constant'
   *  Inport: '<Root>/In_Garde'
   *  Sum: '<S8>/Add1'
   */
  if ((uint8_T)(AppInto_MassageGrade + 1U) > 3) {
    /* Saturate: '<S8>/Saturation' */
    BackMassage_Model_B.Saturation = 3U;
  } else if ((uint8_T)(AppInto_MassageGrade + 1U) < 1) {
    /* Saturate: '<S8>/Saturation' */
    BackMassage_Model_B.Saturation = 1U;
  } else {
    /* Saturate: '<S8>/Saturation' */
    BackMassage_Model_B.Saturation = (uint8_T)(AppInto_MassageGrade + 1U);
  }

  /* End of Saturate: '<S8>/Saturation' */

  /* Chart: '<Root>/Massage_of_stateflow' */
  if (BackMassage_Model_DW.temporalCounter_i1 < MAX_uint32_T) {
    BackMassage_Model_DW.temporalCounter_i1++;
  }

  BackMassage_Model_DW.sfEvent = -1;
  i = 0;
  do {
    BackMassage_Model_DW.isStable_e = true;
    BackMassag_c2_BackMassage_Model();
    i = (int32_T)((uint32_T)i + 1U);
  } while ((!BackMassage_Model_DW.isStable_e) && ((uint32_T)i <= 1U));

  if (!BackMassage_Model_DW.Loc_TimeState) {
    BackMassage_Model_DW.durationCounter_2++;
  } else {
    BackMassage_Model_DW.durationCounter_2 = 0;
  }

  for (i = 0; i < 8; i++) {
    /* SignalConversion generated from: '<S9>/ SFunction ' incorporates:
     *  Chart: '<Root>/Massage_of_stateflow'
     */
    AppOut_MassageBag[i] = BackMassage_Model_B.Out_BagState[i];
  }

  /* Chart: '<Root>/SensorFunc' incorporates:
   *  DataStoreRead: '<Root>/Data Store Read8'
   */
  if (BackMassage_Model_DW.App_Func_En.SensorInit) {
    BackMassage_Model_DW.App_RunState.SensorInit = true;
    AppOut_SensorBag[0] = BagState_Leakage;
    AppOut_SensorBag[1] = BagState_Leakage;
    AppOut_SensorBag[2] = BagState_Leakage;
    AppOut_SensorBag[3] = BagState_Leakage;
    rtb_Out_bPump = true;
  } else {
    BackMassage_Model_DW.App_RunState.SensorInit = false;
    AppOut_SensorBag[0] = BagState_IDLE;
    AppOut_SensorBag[1] = BagState_IDLE;
    AppOut_SensorBag[2] = BagState_IDLE;
    AppOut_SensorBag[3] = BagState_IDLE;
    rtb_Out_bPump = false;
  }

  /* End of Chart: '<Root>/SensorFunc' */

  /* Chart: '<Root>/GasStorage' */
  if (BackMassage_Model_DW.temporalCounter_i1_o < 4095U) {
    BackMassage_Model_DW.temporalCounter_i1_o++;
  }

  i = 0;
  boolean_T isStable;
  do {
    isStable = true;
    if (BackMassage_Model_DW.is_active_c13_BackMassage_Model == 0U) {
      BackMassage_Model_DW.is_active_c13_BackMassage_Model = 1U;
      isStable = false;
      BackMassage_Model_DW.is_c13_BackMassage_Model =
        BackMassage_Model_IN_IDLE_i;
      BackMassage_Model_DW.App_RunState.GasStorage = false;
      rtb_Out_bPump_e = false;
      rtb_Out_bValvePower_d = false;
      BackMassage_Model_DW.BeforGasStorageState =
        (BackMassage_Model_DW.App_Func_En.Active_Flank &&
         BackMassage_Model_B.Out_bGasStorageBag);
      BackMassage_Model_B.Out_bGasStorageBag = false;
    } else {
      switch (BackMassage_Model_DW.is_c13_BackMassage_Model) {
       case BackMassage_Model_IN_Error:
        if ((!BackMassage_Model_DW.GasStorageBag_Error) && (AppInto_FaultState ==
             0)) {
          isStable = false;
          BackMassage_Model_DW.is_c13_BackMassage_Model =
            BackMassage_Model_IN_IDLE_i;
          BackMassage_Model_DW.App_RunState.GasStorage = false;
          rtb_Out_bPump_e = false;
          rtb_Out_bValvePower_d = false;
          BackMassage_Model_DW.BeforGasStorageState =
            (BackMassage_Model_DW.App_Func_En.Active_Flank &&
             BackMassage_Model_B.Out_bGasStorageBag);
          BackMassage_Model_B.Out_bGasStorageBag = false;
        } else {
          BackMassage_Model_DW.App_RunState.GasStorage = false;
          rtb_Out_bPump_e = false;
          rtb_Out_bValvePower_d = false;
          BackMassage_Model_B.Out_bGasStorageBag = false;
        }
        break;

       case BackMassage_Model_IN_IDLE_i:
        if (BackMassage_Model_DW.App_Func_En.GasStorage) {
          BackMassage_Model_DW.is_c13_BackMassage_Model =
            BackMassage_Model_IN_Run_n;
          BackMassage_Model_DW.App_RunState.GasStorage = true;
          BackMassage_Model_DW.BeforGasStorageState =
            BackMassage_Model_B.Out_bGasStorageBag;
          isStable = false;
          BackMassage_Model_DW.is_Run = BackMassage_Model_IN_stop;
          rtb_Out_bPump_e = false;
          rtb_Out_bValvePower_d = false;
          BackMassage_Model_B.Out_bGasStorageBag = false;
        } else {
          BackMassage_Model_DW.App_RunState.GasStorage = false;
          rtb_Out_bPump_e = false;
          rtb_Out_bValvePower_d = false;
        }
        break;

       default:
        /* case IN_Run: */
        if ((AppInto_FaultState != 0) ||
            BackMassage_Model_DW.GasStorageBag_Error) {
          BackMassage_Model_DW.is_Run = BackMassag_IN_NO_ACTIVE_CHILD_g;
          isStable = false;
          BackMassage_Model_DW.is_c13_BackMassage_Model =
            BackMassage_Model_IN_Error;
          BackMassage_Model_DW.App_RunState.GasStorage = false;
          rtb_Out_bPump_e = false;
          rtb_Out_bValvePower_d = false;
          BackMassage_Model_B.Out_bGasStorageBag = false;
        } else if (!BackMassage_Model_DW.App_Func_En.GasStorage) {
          BackMassage_Model_DW.is_Run = BackMassag_IN_NO_ACTIVE_CHILD_g;
          isStable = false;
          BackMassage_Model_DW.is_c13_BackMassage_Model =
            BackMassage_Model_IN_IDLE_i;
          BackMassage_Model_DW.App_RunState.GasStorage = false;
          rtb_Out_bPump_e = false;
          rtb_Out_bValvePower_d = false;
          BackMassage_Model_DW.BeforGasStorageState =
            (BackMassage_Model_DW.App_Func_En.Active_Flank &&
             BackMassage_Model_B.Out_bGasStorageBag);
          BackMassage_Model_B.Out_bGasStorageBag = false;
        } else {
          BackMassage_Model_DW.BeforGasStorageState =
            BackMassage_Model_B.Out_bGasStorageBag;
          if (BackMassage_Model_DW.is_Run == BackMassage_Model_IN_start_h) {
            if (BackMassage_Model_DW.temporalCounter_i1_o >= 3000U) {
              BackMassage_Model_DW.GasStorageBag_Error = true;
              BackMassage_Model_DW.is_Run = BackMassag_IN_NO_ACTIVE_CHILD_g;
              isStable = false;
              BackMassage_Model_DW.is_c13_BackMassage_Model =
                BackMassage_Model_IN_Error;
              BackMassage_Model_DW.App_RunState.GasStorage = false;
              rtb_Out_bPump_e = false;
              rtb_Out_bValvePower_d = false;
              BackMassage_Model_B.Out_bGasStorageBag = false;
            } else if (AppInto_GasStoragePress > GasStorage_OverPress) {
              isStable = false;
              BackMassage_Model_DW.is_Run = BackMassage_Model_IN_stop;
              rtb_Out_bPump_e = false;
              rtb_Out_bValvePower_d = false;
              BackMassage_Model_B.Out_bGasStorageBag = false;
            } else {
              rtb_Out_bPump_e = true;
              rtb_Out_bValvePower_d = true;
              BackMassage_Model_B.Out_bGasStorageBag = true;
            }

            /* case IN_stop: */
          } else if (AppInto_GasStoragePress < GasStorage_StartPress) {
            isStable = false;
            BackMassage_Model_DW.is_Run = BackMassage_Model_IN_start_h;
            BackMassage_Model_DW.temporalCounter_i1_o = 0U;
            rtb_Out_bPump_e = true;
            rtb_Out_bValvePower_d = true;
            BackMassage_Model_B.Out_bGasStorageBag = true;
          } else {
            rtb_Out_bPump_e = false;
            rtb_Out_bValvePower_d = false;
            BackMassage_Model_B.Out_bGasStorageBag = false;
          }
        }
        break;
      }
    }

    i = (int32_T)((uint32_T)i + 1U);
  } while ((!isStable) && ((uint32_T)i <= 3U));

  /* End of Chart: '<Root>/GasStorage' */

  /* Chart: '<Root>/OutGasStorage' */
  if (BackMassage_Model_DW.App_RunState.Active_Flank) {
    AppOut_GasStorage = BackMassage_Model_B.Out_GasStorage;
  } else {
    AppOut_GasStorage = BackMassage_Model_B.Out_bGasStorageBag;
  }

  /* End of Chart: '<Root>/OutGasStorage' */

  /* Outputs for Atomic SubSystem: '<Root>/Auto_Lumbar' */
  /* Outputs for Atomic SubSystem: '<Root>/Auto_Flank' */
  /* Logic: '<Root>/Logical Operator' incorporates:
   *  Logic: '<Root>/Logical Operator3'
   *  Logic: '<S2>/Logical Operator'
   *  Logic: '<S3>/Logical Operator'
   */
  AppOut_PumpState = (BackMassage_Model_B.Out_PumpState_j[0] ||
                      BackMassage_Model_B.Out_PumpState_j[1] ||
                      (BackMassage_Model_B.Out_bPumpState[0] ||
                       BackMassage_Model_B.Out_bPumpState[1]) ||
                      BackMassage_Model_B.Out_PumpState ||
                      BackMassage_Model_B.Out_PumpState_l ||
                      (rtb_Out_PumpState_i || rtb_Out_PumpState) ||
                      (rtb_Out_PumpState_e || rtb_Out_PumpState_ig) ||
                      rtb_Out_bPump_e);

  /* Logic: '<Root>/Logical Operator1' incorporates:
   *  Logic: '<S2>/Logical Operator1'
   *  Logic: '<S3>/Logical Operator1'
   */
  AppOut_ValvePower = (BackMassage_Model_B.Out_ValvePower[0] ||
                       BackMassage_Model_B.Out_ValvePower[1] ||
                       BackMassage_Model_B.Out_bValvePowerState ||
                       BackMassage_Model_B.Out_ValvePowerState ||
                       BackMassage_Model_B.Out_ValvePowerState_j ||
                       (rtb_Out_ValvePowerState_e || rtb_Out_ValvePowerState) ||
                       (rtb_Out_ValvePowerState_g || rtb_Out_ValvePowerState_i) ||
                       rtb_Out_bValvePower_d || rtb_Out_bPump);

  /* End of Outputs for SubSystem: '<Root>/Auto_Flank' */
  /* End of Outputs for SubSystem: '<Root>/Auto_Lumbar' */

  /* Chart: '<Root>/Function_switch' incorporates:
   *  Inport: '<Root>/In_ActiveFlank'
   *  Inport: '<Root>/In_AdaptiveFlank'
   *  Inport: '<Root>/In_AdaptiveLumbar'
   *  Inport: '<Root>/In_Fault'
   *  Inport: '<Root>/In_Flank_Req'
   *  Inport: '<Root>/In_LumbarFunc'
   *  Inport: '<Root>/In_MassageEn'
   */
  if (BackMassage_Model_DW.is_active_c3_BackMassage_Model == 0U) {
    BackMassage_Model_DW.is_active_c3_BackMassage_Model = 1U;
    BackMassage_Model_DW.durationCounter_1 = 0;
    BackMassage_Model_DW.is_c3_BackMassage_Model = BackMassage_Model_IN_Sensor;
    BackMassage_Model_Func_Init();
    BackMassage_Model_DW.is_Sensor = BackMassage_Model_IN_Run;
    BackMassage_Model_DW.App_Func_En.SensorInit = true;
  } else {
    switch (BackMassage_Model_DW.is_c3_BackMassage_Model) {
     case BackMassage_Model_IN_Fault:
      if (AppInto_FaultState == 0) {
        BackMassage_Model_DW.is_c3_BackMassage_Model =
          BackMassage_Model_IN_Idle_p;
        BackMassage_Model_Func_Init();
        BackMassage_enter_internal_Idle();
      } else {
        BackMassage_Model_Func_Init();
      }
      break;

     case BackMassage_Model_IN_Idle_p:
      if (AppInto_FaultState != 0) {
        BackMassage_Model_DW.is_c3_BackMassage_Model =
          BackMassage_Model_IN_Fault;
        BackMassage_Model_Func_Init();
      } else {
        BackMassage_Model_Func_Init();
        if (AppInto_ActiveFlankEn) {
          BackMassage_Model_DW.App_Func_En.Active_Flank = true;
        } else if (AppInto_LumbarFunc != 0) {
          BackMassage_Model_DW.App_Func_En.Passive_Lumbar = true;
        } else if (AppInto_FlankFunc != 0) {
          BackMassage_Model_DW.App_Func_En.Passive_Flank = true;
        } else if (AppInto_MassageEnable) {
          BackMassage_Model_DW.App_Func_En.Massage = true;
        } else if (AppInto_AdaptiveLumbar) {
          BackMassage_Model_DW.App_Func_En.Auto_Lumbar = true;
          BackMassage_Model_DW.App_RunState.Auto_Lumbar = true;
        } else {
          BackMassage_Model_DW.App_RunState.Auto_Lumbar = false;
          if (AppInto_AdaptiveFlank) {
            BackMassage_Model_DW.App_Func_En.Auto_Flank = true;
            BackMassage_Model_DW.App_RunState.Auto_Flank = true;
          } else {
            BackMassage_Model_DW.App_RunState.Auto_Flank = false;
            BackMassage_Model_DW.App_Func_En.GasStorage = true;
          }
        }
      }
      break;

     default:
      /* case IN_Sensor: */
      if (AppInto_FaultState != 0) {
        BackMassage_Model_DW.durationCounter_1 = 0;
      }

      if (BackMassage_Model_DW.durationCounter_1 > 200) {
        BackMassage_Model_DW.is_Sensor = BackMassag_IN_NO_ACTIVE_CHILD_g;
        BackMassage_Model_DW.is_c3_BackMassage_Model =
          BackMassage_Model_IN_Idle_p;
        BackMassage_Model_Func_Init();
        BackMassage_enter_internal_Idle();
      } else if (BackMassage_Model_DW.is_Sensor == BackMassage_Model_IN_Fault) {
        if (AppInto_FaultState == 0) {
          BackMassage_Model_DW.is_Sensor = BackMassage_Model_IN_Run;
          BackMassage_Model_DW.App_Func_En.SensorInit = true;
        } else {
          BackMassage_Model_Func_Init();
        }

        /* case IN_Run: */
      } else if (AppInto_FaultState != 0) {
        BackMassage_Model_DW.is_Sensor = BackMassage_Model_IN_Fault;
        BackMassage_Model_Func_Init();
      }
      break;
    }
  }

  if (AppInto_FaultState == 0) {
    BackMassage_Model_DW.durationCounter_1++;
  } else {
    BackMassage_Model_DW.durationCounter_1 = 0;
  }

  /* End of Chart: '<Root>/Function_switch' */

  /* Outport: '<Root>/Out_Record_List' incorporates:
   *  DataStoreRead: '<Root>/Data Store Read11'
   */
  BackMassage_Model_Y.Out_Record_List = BackMassage_Model_DW.Record_List;

  /* Outport: '<Root>/Out_GasStroage_Error' incorporates:
   *  DataStoreRead: '<Root>/Data Store Read7'
   */
  BackMassage_Model_Y.Out_GasStroage_Error =
    BackMassage_Model_DW.GasStorageBag_Error;

  /* DataStoreRead: '<Root>/Data Store Read' */
  AppOut_RunState = BackMassage_Model_DW.App_RunState;
}

/* Model initialize function */
void BackMassage_Model_initialize(void)
{
  {
    /* local block i/o variables */
    BagState rtb_Out_Bag;
    BagState rtb_Out_Bag_m;
    BagState rtb_Out_Bag_d;
    BagState rtb_Out_Bag_dt;
    boolean_T rtb_Out_PumpState;
    boolean_T rtb_Out_ValvePowerState;
    boolean_T rtb_Out_PumpState_i;
    boolean_T rtb_Out_ValvePowerState_e;
    boolean_T rtb_Out_PumpState_ig;
    boolean_T rtb_Out_ValvePowerState_i;
    boolean_T rtb_Out_PumpState_e;
    boolean_T rtb_Out_ValvePowerState_g;

    /* SystemInitialize for Chart: '<Root>/Active_Flank' */
    BackMassage_Model_B.Out_FlankBag[0] = BagState_IDLE;

    /* SystemInitialize for Chart: '<Root>/Passive_flank' */
    BackMassage_Model_B.Out_flank_bag[0] = BagState_IDLE;

    /* SystemInitialize for Chart: '<Root>/Active_Flank' */
    BackMassage_Model_B.Out_FlankBag[1] = BagState_IDLE;

    /* SystemInitialize for Chart: '<Root>/Passive_flank' */
    BackMassage_Model_B.Out_flank_bag[1] = BagState_IDLE;

    /* SystemInitialize for Atomic SubSystem: '<Root>/Auto_Flank' */

    /* SystemInitialize for Chart: '<S2>/Left_Flank' */
    BackMassage_Mod_Left_Flank_Init(&rtb_Out_Bag_dt, &rtb_Out_PumpState_e,
      &rtb_Out_ValvePowerState_g);

    /* SystemInitialize for Chart: '<S2>/Right_Flank' */
    BackMassage_Mod_Left_Flank_Init(&rtb_Out_Bag_d, &rtb_Out_PumpState_ig,
      &rtb_Out_ValvePowerState_i);

    /* End of SystemInitialize for SubSystem: '<Root>/Auto_Flank' */

    /* SystemInitialize for Chart: '<Root>/FuncSelect_Flank' */
    AppOut_FlankBag[0] = BagState_IDLE;

    /* SystemInitialize for Chart: '<Root>/Passive_Lumbar' */
    BackMassage_Model_B.Out_LumbarBag[0] = BagState_IDLE;

    /* SystemInitialize for Chart: '<Root>/FuncSelect_Flank' */
    AppOut_FlankBag[1] = BagState_IDLE;

    /* SystemInitialize for Chart: '<Root>/Passive_Lumbar' */
    BackMassage_Model_B.Out_LumbarBag[1] = BagState_IDLE;

    /* SystemInitialize for Atomic SubSystem: '<Root>/Auto_Lumbar' */

    /* SystemInitialize for Chart: '<S3>/Left_Lumbar' */
    BackMassage_Mo_Left_Lumbar_Init(&rtb_Out_Bag_m, &rtb_Out_PumpState_i,
      &rtb_Out_ValvePowerState_e);

    /* SystemInitialize for Chart: '<S3>/Right_Lumbar' */
    BackMassage_Mo_Left_Lumbar_Init(&rtb_Out_Bag, &rtb_Out_PumpState,
      &rtb_Out_ValvePowerState);

    /* End of SystemInitialize for SubSystem: '<Root>/Auto_Lumbar' */

    /* SystemInitialize for Chart: '<Root>/FuncSelect_Lumbar' */
    AppOut_LumbarBag[0] = BagState_IDLE;
    AppOut_LumbarBag[1] = BagState_IDLE;

    /* SystemInitialize for Chart: '<Root>/Massage_of_stateflow' */
    BackMassage_Model_DW.sfEvent = -1;
    BackMassage_Model_DW.Loc_RunList = 1U;

    /* SystemInitialize for Chart: '<Root>/SensorFunc' */
    AppOut_SensorBag[0] = BagState_IDLE;
    AppOut_SensorBag[1] = BagState_IDLE;
    AppOut_SensorBag[2] = BagState_IDLE;
    AppOut_SensorBag[3] = BagState_IDLE;
  }
}

/* Model terminate function */
void BackMassage_Model_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
