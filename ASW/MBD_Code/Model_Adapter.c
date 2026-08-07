/*
 * File: Model_Adapter.c
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

#include "Model_Adapter.h"
#include "rtwtypes.h"
#include "BackMassage_Model_types.h"

/* Exported data definition */

/* Definition for custom storage class: ExportToFile */
boolean_T AppInto_ActiveFlankEn;       /* '<Root>/In_ActiveFlank' */

/* 主动侧翼 0:off;1:on */
uint8_T AppInto_ActiveFlankMode;       /* '<Root>/In_ActiveFlankMode' */

/* 0:idle;1:mid;2:Left;3:Right */
uint8_T AppInto_ActiveFlankSensitivity;/* '<Root>/In_ActiveFlankSensitivity' */

/* 0:idle;1:level1;2:level2;3:level3 */
boolean_T AppInto_AdaptiveFlank;       /* '<Root>/In_AdaptiveFlank' */

/* 自适应侧翼0:off;1:on */
boolean_T AppInto_AdaptiveLumbar;      /* '<Root>/In_AdaptiveLumbar' */

/* 0:off;1:on */
uint32_T AppInto_F_SensorPress[2];     /* '<Root>/In_F_SensorPress' */

/* 侧翼感应气袋压力 */
uint8_T AppInto_FaultState;            /* '<Root>/In_Fault' */

/* 故障信号 */
uint8_T AppInto_FlankFunc;             /* '<Root>/In_Flank_Req' */

/* 0:IDLE;1:up;2:Down;3:Fwd;4:Rwd;5:Centre */
uint32_T AppInto_FlankPress[2];        /* '<Root>/In_FlankPress' */

/* 侧翼气袋压力 */
uint32_T AppInto_GasStoragePress;      /* '<Root>/In_GasStoragePress' */

/* 储气罐压力 */
uint32_T AppInto_L_SensorPress[2];     /* '<Root>/In_L_SensorPress' */

/* 腰托感应气袋压力 */
uint8_T AppInto_LumbarFunc;            /* '<Root>/In_LumbarFunc' */

/* 0:IDLE;1:up;2:Down;3:Fwd;4:Rwd;5:Centre */
uint32_T AppInto_LumbarPress[2];       /* '<Root>/In_LumbarPress' */

/* 腰托气袋压力 */
boolean_T AppInto_MassageEnable;       /* '<Root>/In_MassageEn' */

/* 按摩使能信号 */
uint8_T AppInto_MassageGrade;          /* '<Root>/In_Garde' */

/* 按摩强度等级 */
uint8_T AppInto_MassageMode;           /* '<Root>/In_MassageReq' */

/* 按摩请求信号 */
BagState AppOut_FlankBag[2];           /* '<Root>/FuncSelect_Flank' */

/* 下气袋;0:空闲;1:充气;2:泄气 */
boolean_T AppOut_GasStorage;           /* '<Root>/OutGasStorage' */

/* 储气罐开关 */
BagState AppOut_LumbarBag[2];          /* '<Root>/FuncSelect_Lumbar' */

/* 腰托气袋;0:空闲;1:充气;2:泄气 */
boolean_T AppOut_MassageBag[8];        /* '<Root>/Massage_of_stateflow' */

/* 8个气袋 */
boolean_T AppOut_PumpState;            /* '<Root>/Logical Operator' */

/* 泵开关:1 enable;0,disable */
FuncGroup AppOut_RunState;             /* '<Root>/Data Store Read' */
BagState AppOut_SensorBag[4];          /* '<Root>/SensorFunc' */

/* 感应气袋;0:空闲;1:充气;2:泄气 */
boolean_T AppOut_ValvePower;           /* '<Root>/Logical Operator1' */

/* 电磁阀电源开关:1 enable;0,disable */

/* Const memory section */
/* Definition for custom storage class: Const */
const uint8_T MassageMode1[4][11] = { { 1U, 1U, 1U, 0U, 0U, 0U, 0U, 0U, 0U, 2U,
    2U }, { 2U, 0U, 0U, 1U, 1U, 0U, 0U, 0U, 0U, 2U, 3U }, { 3U, 0U, 0U, 0U, 0U,
    1U, 1U, 0U, 0U, 2U, 4U }, { 4U, 0U, 0U, 0U, 0U, 0U, 0U, 1U, 1U, 2U, 1U } };
                              /* Referenced by: '<Root>/Massage_of_stateflow' */

/* 模式1 */
const uint8_T MassageMode2[4][11] = { { 1U, 1U, 1U, 0U, 0U, 0U, 0U, 0U, 0U, 3U,
    2U }, { 2U, 0U, 0U, 1U, 1U, 0U, 0U, 0U, 0U, 3U, 3U }, { 3U, 0U, 0U, 0U, 0U,
    1U, 1U, 0U, 0U, 3U, 4U }, { 4U, 0U, 0U, 0U, 0U, 0U, 0U, 1U, 1U, 3U, 1U } };
                              /* Referenced by: '<Root>/Massage_of_stateflow' */

/* 模式2 */
const uint8_T MassageMode3[8][11] = { { 1U, 1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 2U,
    2U }, { 2U, 0U, 1U, 0U, 0U, 0U, 0U, 0U, 0U, 2U, 3U }, { 3U, 0U, 0U, 1U, 0U,
    0U, 0U, 0U, 0U, 2U, 4U }, { 4U, 0U, 0U, 0U, 1U, 0U, 0U, 0U, 0U, 2U, 5U }, {
    5U, 0U, 0U, 0U, 0U, 1U, 0U, 0U, 0U, 2U, 6U }, { 6U, 0U, 0U, 0U, 0U, 0U, 1U,
    0U, 0U, 2U, 7U }, { 7U, 0U, 0U, 0U, 0U, 0U, 0U, 1U, 0U, 2U, 8U }, { 8U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 1U, 2U, 1U } };
                              /* Referenced by: '<Root>/Massage_of_stateflow' */

/* 模式3 */
const uint8_T MassageMode4[6][11] = { { 1U, 1U, 0U, 1U, 0U, 0U, 0U, 0U, 0U, 1U,
    2U }, { 2U, 0U, 1U, 0U, 1U, 0U, 0U, 0U, 0U, 1U, 3U }, { 3U, 0U, 0U, 1U, 0U,
    1U, 0U, 0U, 0U, 1U, 4U }, { 4U, 0U, 0U, 0U, 1U, 0U, 1U, 0U, 0U, 1U, 5U }, {
    5U, 0U, 0U, 0U, 0U, 1U, 0U, 1U, 0U, 1U, 6U }, { 6U, 0U, 0U, 0U, 0U, 0U, 1U,
    0U, 1U, 1U, 1U } };       /* Referenced by: '<Root>/Massage_of_stateflow' */

/* 模式4 */
const uint8_T MassageMode5[4][11] = { { 1U, 1U, 1U, 0U, 0U, 0U, 0U, 0U, 0U, 1U,
    2U }, { 2U, 0U, 0U, 1U, 1U, 0U, 0U, 0U, 0U, 1U, 3U }, { 3U, 0U, 0U, 0U, 0U,
    1U, 1U, 0U, 0U, 1U, 4U }, { 4U, 0U, 0U, 0U, 0U, 0U, 0U, 1U, 1U, 1U, 1U } };
                              /* Referenced by: '<Root>/Massage_of_stateflow' */

/* 模式5 */
const uint8_T MassageMode6[4][11] = { { 1U, 1U, 0U, 0U, 1U, 0U, 0U, 0U, 0U, 1U,
    2U }, { 2U, 0U, 1U, 1U, 0U, 0U, 0U, 0U, 0U, 1U, 3U }, { 3U, 0U, 0U, 0U, 0U,
    1U, 0U, 0U, 1U, 1U, 4U }, { 4U, 0U, 0U, 0U, 0U, 0U, 1U, 1U, 0U, 1U, 1U } };
                              /* Referenced by: '<Root>/Massage_of_stateflow' */

/* 模式6 */
const uint8_T MassageMode7[2][11] = { { 1U, 1U, 1U, 0U, 0U, 0U, 0U, 1U, 1U, 1U,
    2U }, { 2U, 0U, 0U, 1U, 1U, 1U, 1U, 0U, 0U, 1U, 1U } };
                              /* Referenced by: '<Root>/Massage_of_stateflow' */

/* 模式7 */
const uint8_T MassageMode8[2][11] = { { 1U, 1U, 1U, 0U, 0U, 0U, 0U, 1U, 1U, 2U,
    2U }, { 2U, 0U, 0U, 1U, 1U, 1U, 1U, 0U, 0U, 2U, 1U } };
                              /* Referenced by: '<Root>/Massage_of_stateflow' */

/* 模式8 */
const uint16_T MassageTime1[4][7] = { { 3000U, 130U, 120U, 160U, 180U, 230U,
    270U }, { 3000U, 130U, 120U, 160U, 180U, 230U, 270U }, { 3000U, 130U, 120U,
    160U, 180U, 230U, 270U }, { 3000U, 130U, 120U, 160U, 180U, 230U, 270U } };
                              /* Referenced by: '<Root>/Massage_of_stateflow' */

/* 模式1时间配置 */
const uint16_T MassageTime2[4][7] = { { 3000U, 320U, 320U, 380U, 380U, 450U,
    450U }, { 3000U, 320U, 320U, 380U, 380U, 450U, 450U }, { 3000U, 320U, 320U,
    380U, 380U, 450U, 450U }, { 3000U, 320U, 320U, 380U, 380U, 450U, 450U } };
                              /* Referenced by: '<Root>/Massage_of_stateflow' */

/* 模式2时间配置 */
const uint16_T MassageTime3[8][7] = { { 3000U, 170U, 130U, 230U, 180U, 300U,
    240U }, { 3000U, 170U, 130U, 230U, 180U, 300U, 240U }, { 3000U, 170U, 130U,
    230U, 180U, 300U, 240U }, { 3000U, 170U, 130U, 230U, 180U, 300U, 240U }, {
    3000U, 170U, 130U, 230U, 180U, 300U, 240U }, { 3000U, 170U, 130U, 230U, 180U,
    300U, 240U }, { 3000U, 170U, 130U, 230U, 180U, 300U, 240U }, { 3000U, 170U,
    130U, 230U, 180U, 300U, 240U } };
                              /* Referenced by: '<Root>/Massage_of_stateflow' */

/* 模式3时间配置 */
const uint16_T MassageTime4[6][7] = { { 0U, 2000U, 0U, 4000U, 0U, 6000U, 0U }, {
    0U, 2000U, 0U, 4000U, 0U, 6000U, 0U }, { 0U, 2000U, 0U, 4000U, 0U, 6000U, 0U
  }, { 0U, 2000U, 0U, 4000U, 0U, 6000U, 0U }, { 0U, 2000U, 0U, 4000U, 0U, 6000U,
    0U }, { 0U, 2000U, 0U, 4000U, 0U, 6000U, 0U } };
                              /* Referenced by: '<Root>/Massage_of_stateflow' */

/* 模式4时间配置 */
const uint16_T MassageTime5[4][7] = { { 0U, 2000U, 0U, 4000U, 0U, 6000U, 0U }, {
    0U, 2000U, 0U, 4000U, 0U, 6000U, 0U }, { 0U, 2000U, 0U, 4000U, 0U, 6000U, 0U
  }, { 0U, 2000U, 0U, 4000U, 0U, 6000U, 0U } };
                              /* Referenced by: '<Root>/Massage_of_stateflow' */

/* 模式5时间配置 */
const uint16_T MassageTime6[4][7] = { { 0U, 2000U, 0U, 4000U, 0U, 6000U, 0U }, {
    0U, 2000U, 0U, 4000U, 0U, 6000U, 0U }, { 0U, 2000U, 0U, 4000U, 0U, 6000U, 0U
  }, { 0U, 2000U, 0U, 4000U, 0U, 6000U, 0U } };
                              /* Referenced by: '<Root>/Massage_of_stateflow' */

/* 模式6时间配置 */
const uint16_T MassageTime7[2][7] = { { 0U, 2000U, 0U, 4000U, 0U, 6000U, 0U }, {
    0U, 2000U, 0U, 4000U, 0U, 6000U, 0U } };
                              /* Referenced by: '<Root>/Massage_of_stateflow' */

/* 模式7时间配置 */
const uint16_T MassageTime8[2][7] = { { 3000U, 90U, 160U, 160U, 180U, 230U, 270U
  }, { 3000U, 90U, 160U, 160U, 180U, 230U, 270U } };
                              /* Referenced by: '<Root>/Massage_of_stateflow' */

/* 模式8时间配置 */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
