/*
 * File: Model_Adapter.h
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

#ifndef RTW_HEADER_Model_Adapter_h_
#define RTW_HEADER_Model_Adapter_h_
#include "rtwtypes.h"
#include "BackMassage_Model_types.h"

/* Exported data define */

/* Definition for custom storage class: Define */
#define Flank_OverPress                38000U                    /* Referenced by:
                                                                  * '<Root>/Passive_flank'
                                                                  * '<S2>/Left_Flank'
                                                                  * '<S2>/Right_Flank'
                                                                  *//* 侧翼最大压力 */
#define GasStorage_OverPress           80000U                    /* Referenced by:
                                                                  * '<Root>/Active_Flank'
                                                                  * '<Root>/GasStorage'
                                                                  *//* 储气罐最大压力 */
#define GasStorage_StartPress          65000U                    /* Referenced by:
                                                                  * '<Root>/Active_Flank'
                                                                  * '<Root>/GasStorage'
                                                                  *//* 储气罐补气压力 */
#define KnockCnt                       9U                        /* Referenced by: '<Root>/Massage_of_stateflow' *//* 叩击次数 */
#define Lumbar_OverPress               45000U                    /* Referenced by: '<Root>/Passive_Lumbar' *//* 侧翼最大压力 */
#define MA_TimeOut                     1080U                     /* Referenced by: '<Root>/Massage_of_stateflow' *//* 按摩超时，单位秒 */
#define MaxDeflation_T                 60000U                    /* Referenced by: '<Root>/Passive_Lumbar' *//* 最大充气时间ms */
#define MaxInflation_T                 15000U                    /* Referenced by:
                                                                  * '<Root>/Active_Flank'
                                                                  * '<Root>/Passive_Lumbar'
                                                                  * '<Root>/Passive_flank'
                                                                  *//* 最大充气时间ms */
#define PauseTime                      100U                      /* Referenced by: '<Root>/Massage_of_stateflow' *//* 气袋切换时间ms */

/* 气袋工作模式 */
typedef enum {
  BagState_IDLE = 0,                   /* Default value */
  BagState_Inflation,
  BagState_Leakage
} BagState;

typedef struct {
  boolean_T Active_Flank;
  boolean_T Passive_Lumbar;
  boolean_T Passive_Flank;
  boolean_T Auto_Lumbar;
  boolean_T Auto_Flank;
  boolean_T Massage;
  boolean_T SensorInit;
  boolean_T GasStorage;
} FuncGroup;

/* Exported data declaration */

/* Declaration for custom storage class: ExportToFile */
extern boolean_T AppInto_ActiveFlankEn;/* '<Root>/In_ActiveFlank' */

/* 主动侧翼 0:off;1:on */
extern uint8_T AppInto_ActiveFlankMode;/* '<Root>/In_ActiveFlankMode' */

/* 0:idle;1:mid;2:Left;3:Right */
extern uint8_T AppInto_ActiveFlankSensitivity;/* '<Root>/In_ActiveFlankSensitivity' */

/* 0:idle;1:level1;2:level2;3:level3 */
extern boolean_T AppInto_AdaptiveFlank;/* '<Root>/In_AdaptiveFlank' */

/* 自适应侧翼0:off;1:on */
extern boolean_T AppInto_AdaptiveLumbar;/* '<Root>/In_AdaptiveLumbar' */

/* 0:off;1:on */
extern uint32_T AppInto_F_SensorPress[2];/* '<Root>/In_F_SensorPress' */

/* 侧翼感应气袋压力 */
extern uint8_T AppInto_FaultState;     /* '<Root>/In_Fault' */

/* 故障信号 */
extern uint8_T AppInto_FlankFunc;      /* '<Root>/In_Flank_Req' */

/* 0:IDLE;1:up;2:Down;3:Fwd;4:Rwd;5:Centre */
extern uint32_T AppInto_FlankPress[2]; /* '<Root>/In_FlankPress' */

/* 侧翼气袋压力 */
extern uint32_T AppInto_GasStoragePress;/* '<Root>/In_GasStoragePress' */

/* 储气罐压力 */
extern uint32_T AppInto_L_SensorPress[2];/* '<Root>/In_L_SensorPress' */

/* 腰托感应气袋压力 */
extern uint8_T AppInto_LumbarFunc;     /* '<Root>/In_LumbarFunc' */

/* 0:IDLE;1:up;2:Down;3:Fwd;4:Rwd;5:Centre */
extern uint32_T AppInto_LumbarPress[2];/* '<Root>/In_LumbarPress' */

/* 腰托气袋压力 */
extern boolean_T AppInto_MassageEnable;/* '<Root>/In_MassageEn' */

/* 按摩使能信号 */
extern uint8_T AppInto_MassageGrade;   /* '<Root>/In_Garde' */

/* 按摩强度等级 */
extern uint8_T AppInto_MassageMode;    /* '<Root>/In_MassageReq' */

/* 按摩请求信号 */
extern BagState AppOut_FlankBag[2];    /* '<Root>/FuncSelect_Flank' */

/* 下气袋;0:空闲;1:充气;2:泄气 */
extern boolean_T AppOut_GasStorage;    /* '<Root>/OutGasStorage' */

/* 储气罐开关 */
extern BagState AppOut_LumbarBag[2];   /* '<Root>/FuncSelect_Lumbar' */

/* 腰托气袋;0:空闲;1:充气;2:泄气 */
extern boolean_T AppOut_MassageBag[8]; /* '<Root>/Massage_of_stateflow' */

/* 8个气袋 */
extern boolean_T AppOut_PumpState;     /* '<Root>/Logical Operator' */

/* 泵开关:1 enable;0,disable */
extern FuncGroup AppOut_RunState;      /* '<Root>/Data Store Read' */
extern BagState AppOut_SensorBag[4];   /* '<Root>/SensorFunc' */

/* 感应气袋;0:空闲;1:充气;2:泄气 */
extern boolean_T AppOut_ValvePower;    /* '<Root>/Logical Operator1' */

/* 电磁阀电源开关:1 enable;0,disable */

/* Const memory section */
/* Declaration for custom storage class: Const */
extern const uint8_T MassageMode1[4][11];

/* Referenced by: '<Root>/Massage_of_stateflow' */

/* 模式1 */
extern const uint8_T MassageMode2[4][11];

/* Referenced by: '<Root>/Massage_of_stateflow' */

/* 模式2 */
extern const uint8_T MassageMode3[8][11];

/* Referenced by: '<Root>/Massage_of_stateflow' */

/* 模式3 */
extern const uint8_T MassageMode4[6][11];

/* Referenced by: '<Root>/Massage_of_stateflow' */

/* 模式4 */
extern const uint8_T MassageMode5[4][11];

/* Referenced by: '<Root>/Massage_of_stateflow' */

/* 模式5 */
extern const uint8_T MassageMode6[4][11];

/* Referenced by: '<Root>/Massage_of_stateflow' */

/* 模式6 */
extern const uint8_T MassageMode7[2][11];

/* Referenced by: '<Root>/Massage_of_stateflow' */

/* 模式7 */
extern const uint8_T MassageMode8[2][11];

/* Referenced by: '<Root>/Massage_of_stateflow' */

/* 模式8 */
extern const uint16_T MassageTime1[4][7];

/* Referenced by: '<Root>/Massage_of_stateflow' */

/* 模式1时间配置 */
extern const uint16_T MassageTime2[4][7];

/* Referenced by: '<Root>/Massage_of_stateflow' */

/* 模式2时间配置 */
extern const uint16_T MassageTime3[8][7];

/* Referenced by: '<Root>/Massage_of_stateflow' */

/* 模式3时间配置 */
extern const uint16_T MassageTime4[6][7];

/* Referenced by: '<Root>/Massage_of_stateflow' */

/* 模式4时间配置 */
extern const uint16_T MassageTime5[4][7];

/* Referenced by: '<Root>/Massage_of_stateflow' */

/* 模式5时间配置 */
extern const uint16_T MassageTime6[4][7];

/* Referenced by: '<Root>/Massage_of_stateflow' */

/* 模式6时间配置 */
extern const uint16_T MassageTime7[2][7];

/* Referenced by: '<Root>/Massage_of_stateflow' */

/* 模式7时间配置 */
extern const uint16_T MassageTime8[2][7];

/* Referenced by: '<Root>/Massage_of_stateflow' */

/* 模式8时间配置 */
#endif                                 /* RTW_HEADER_Model_Adapter_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
