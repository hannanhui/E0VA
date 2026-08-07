/*
 * File: BackMassage_Model.h
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

#ifndef RTW_HEADER_BackMassage_Model_h_
#define RTW_HEADER_BackMassage_Model_h_
#ifndef BackMassage_Model_COMMON_INCLUDES_
#define BackMassage_Model_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* BackMassage_Model_COMMON_INCLUDES_ */

#include "BackMassage_Model_types.h"

/* Includes for objects with custom storage classes */
#include "Model_Adapter.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<S2>/Left_Flank' */
typedef struct {
  uint16_T temporalCounter_i1;         /* '<S2>/Left_Flank' */
  uint8_T is_c15_BackMassage_Model;    /* '<S2>/Left_Flank' */
  uint8_T is_Main;                     /* '<S2>/Left_Flank' */
  uint8_T is_Leakage;                  /* '<S2>/Left_Flank' */
  uint8_T is_Inflation;                /* '<S2>/Left_Flank' */
  uint8_T LeakageState;                /* '<S2>/Left_Flank' */
  uint8_T is_active_c15_BackMassage_Model;/* '<S2>/Left_Flank' */
} DW_Left_Flank_BackMassage_Mod_T;

/* Block states (default storage) for system '<S3>/Left_Lumbar' */
typedef struct {
  uint16_T temporalCounter_i1;         /* '<S3>/Left_Lumbar' */
  uint8_T is_c5_BackMassage_Model;     /* '<S3>/Left_Lumbar' */
  uint8_T is_Main;                     /* '<S3>/Left_Lumbar' */
  uint8_T is_Leakage;                  /* '<S3>/Left_Lumbar' */
  uint8_T is_Inflation;                /* '<S3>/Left_Lumbar' */
  uint8_T LeakageState;                /* '<S3>/Left_Lumbar' */
  uint8_T is_active_c5_BackMassage_Model;/* '<S3>/Left_Lumbar' */
} DW_Left_Lumbar_BackMassage_Mo_T;

/* Block signals (default storage) */
typedef struct {
  BagState Out_flank_bag[2];           /* '<Root>/Passive_flank' */
  BagState Out_LumbarBag[2];           /* '<Root>/Passive_Lumbar' */
  BagState Out_FlankBag[2];            /* '<Root>/Active_Flank' */
  uint8_T Add;                         /* '<S8>/Add' */
  uint8_T Saturation;                  /* '<S8>/Saturation' */
  boolean_T Out_PumpState;             /* '<Root>/Passive_flank' */
  boolean_T Out_ValvePowerState;       /* '<Root>/Passive_flank' */
  boolean_T Out_bPumpState[2];         /* '<Root>/Passive_Lumbar' */
  boolean_T Out_bValvePowerState;      /* '<Root>/Passive_Lumbar' */
  boolean_T Out_BagState[8];           /* '<Root>/Massage_of_stateflow' */
  boolean_T Out_PumpState_l;           /* '<Root>/Massage_of_stateflow' */
  boolean_T Out_ValvePowerState_j;     /* '<Root>/Massage_of_stateflow' */
  boolean_T Out_bGasStorageBag;        /* '<Root>/GasStorage' */
  boolean_T Out_PumpState_j[2];        /* '<Root>/Active_Flank' */
  boolean_T Out_ValvePower[2];         /* '<Root>/Active_Flank' */
  boolean_T Out_GasStorage;            /* '<Root>/Active_Flank' */
} B_BackMassage_Model_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Loc_FcnCnt;                   /* '<Root>/Massage_of_stateflow' */
  TimeUpdataGroup MA_TimeUpdata;       /* '<Root>/Data Store Memory' */
  FuncGroup App_Func_En;               /* '<Root>/Data Store Memory15' */
  FuncGroup App_RunState;              /* '<Root>/Data Store Memory16' */
  int32_T sfEvent;                     /* '<Root>/Massage_of_stateflow' */
  int32_T durationCounter_2;           /* '<Root>/Massage_of_stateflow' */
  int32_T durationCounter_1;           /* '<Root>/Function_switch' */
  int32_T durationCounter_1_c;         /* '<Root>/Active_Flank' */
  int32_T durationCounter_1_e;         /* '<Root>/Active_Flank' */
  int32_T durationCounter_1_g;         /* '<Root>/Active_Flank' */
  uint32_T Loc_MA_Time;                /* '<Root>/Massage_of_stateflow' */
  uint32_T temporalCounter_i1;         /* '<Root>/Massage_of_stateflow' */
  uint32_T Loc_FlankPress_Save[2];     /* '<Root>/Active_Flank' */
  BagState FlankBagInfo[2];            /* '<Root>/Data Store Memory10' */
  BagState SensorBagInfo[4];           /* '<Root>/Data Store Memory14' */
  BagState LumbarBagInfo[2];           /* '<Root>/Data Store Memory4' */
  uint16_T temporalCounter_i1_j;       /* '<Root>/Passive_flank' */
  uint16_T temporalCounter_i1_h;       /* '<Root>/Passive_Lumbar' */
  uint16_T temporalCounter_i2;         /* '<Root>/Passive_Lumbar' */
  uint16_T Loc_TimeInfo[7];            /* '<Root>/Massage_of_stateflow' */
  uint16_T temporalCounter_i1_o;       /* '<Root>/GasStorage' */
  uint16_T temporalCounter_i1_b;       /* '<Root>/Active_Flank' */
  uint16_T temporalCounter_i2_a;       /* '<Root>/Active_Flank' */
  uint8_T Record_List;                 /* '<Root>/Data Store Memory3' */
  uint8_T is_c1_BackMassage_Model;     /* '<Root>/Passive_flank' */
  uint8_T is_Deal;                     /* '<Root>/Passive_flank' */
  uint8_T Loc_flank_save;              /* '<Root>/Passive_flank' */
  uint8_T is_active_c1_BackMassage_Model;/* '<Root>/Passive_flank' */
  uint8_T is_c12_BackMassage_Model;    /* '<Root>/Passive_Lumbar' */
  uint8_T is_READY;                    /* '<Root>/Passive_Lumbar' */
  uint8_T is_up_bag;                   /* '<Root>/Passive_Lumbar' */
  uint8_T is_down_bag;                 /* '<Root>/Passive_Lumbar' */
  uint8_T is_down_bag_p;               /* '<Root>/Passive_Lumbar' */
  uint8_T is_up_bag_k;                 /* '<Root>/Passive_Lumbar' */
  uint8_T is_up_bag_h;                 /* '<Root>/Passive_Lumbar' */
  uint8_T is_down_bag_g;               /* '<Root>/Passive_Lumbar' */
  uint8_T is_RWD;                      /* '<Root>/Passive_Lumbar' */
  uint8_T is_IDLE;                     /* '<Root>/Passive_Lumbar' */
  uint8_T Loc_Backup_lumMode;          /* '<Root>/Passive_Lumbar' */
  uint8_T is_active_c12_BackMassage_Model;/* '<Root>/Passive_Lumbar' */
  uint8_T is_c2_BackMassage_Model;     /* '<Root>/Massage_of_stateflow' */
  uint8_T is_Enable;                   /* '<Root>/Massage_of_stateflow' */
  uint8_T is_Dot;                      /* '<Root>/Massage_of_stateflow' */
  uint8_T is_Knock;                    /* '<Root>/Massage_of_stateflow' */
  uint8_T is_bag1;                     /* '<Root>/Massage_of_stateflow' */
  uint8_T is_asynchronous;             /* '<Root>/Massage_of_stateflow' */
  uint8_T is_bag1_g;                   /* '<Root>/Massage_of_stateflow' */
  uint8_T Loc_RunList;                 /* '<Root>/Massage_of_stateflow' */
  uint8_T Loc_BagInfo[11];             /* '<Root>/Massage_of_stateflow' */
  uint8_T Loc_MassageReqPre;           /* '<Root>/Massage_of_stateflow' */
  uint8_T is_active_c2_BackMassage_Model;/* '<Root>/Massage_of_stateflow' */
  uint8_T is_c13_BackMassage_Model;    /* '<Root>/GasStorage' */
  uint8_T is_Run;                      /* '<Root>/GasStorage' */
  uint8_T is_active_c13_BackMassage_Model;/* '<Root>/GasStorage' */
  uint8_T is_c3_BackMassage_Model;     /* '<Root>/Function_switch' */
  uint8_T is_Sensor;                   /* '<Root>/Function_switch' */
  uint8_T is_active_c3_BackMassage_Model;/* '<Root>/Function_switch' */
  uint8_T is_c10_BackMassage_Model;    /* '<Root>/Active_Flank' */
  uint8_T is_Main;                     /* '<Root>/Active_Flank' */
  uint8_T is_LeftBag;                  /* '<Root>/Active_Flank' */
  uint8_T is_Recover;                  /* '<Root>/Active_Flank' */
  uint8_T is_RightBag;                 /* '<Root>/Active_Flank' */
  uint8_T is_Recover_p;                /* '<Root>/Active_Flank' */
  uint8_T is_Left_Func;                /* '<Root>/Active_Flank' */
  uint8_T is_Right_Func;               /* '<Root>/Active_Flank' */
  uint8_T is_Test_Func;                /* '<Root>/Active_Flank' */
  uint8_T is_Step2_1;                  /* '<Root>/Active_Flank' */
  uint8_T is_Step3;                    /* '<Root>/Active_Flank' */
  uint8_T is_Step3_1;                  /* '<Root>/Active_Flank' */
  uint8_T is_Step4;                    /* '<Root>/Active_Flank' */
  uint8_T is_Step3_2;                  /* '<Root>/Active_Flank' */
  uint8_T is_Idle;                     /* '<Root>/Active_Flank' */
  uint8_T Loc_save_mode;               /* '<Root>/Active_Flank' */
  uint8_T is_active_c10_BackMassage_Model;/* '<Root>/Active_Flank' */
  boolean_T MassageBagInfo[8];         /* '<Root>/Data Store Memory1' */
  boolean_T GasStorageInfo;            /* '<Root>/Data Store Memory11' */
  boolean_T FlankFuncUpdata;           /* '<Root>/Data Store Memory12' */
  boolean_T ActiveFlankUpdata;         /* '<Root>/Data Store Memory13' */
  boolean_T Lb_ReleseFlag;             /* '<Root>/Data Store Memory2' */
  boolean_T FK_ReleseFlag;             /* '<Root>/Data Store Memory22' */
  boolean_T M_MassageUpdata;           /* '<Root>/Data Store Memory5' */
  boolean_T PumpState;                 /* '<Root>/Data Store Memory7' */
  boolean_T LumbarUpdata;              /* '<Root>/Data Store Memory8' */
  boolean_T ValvePowerState;           /* '<Root>/Data Store Memory9' */
  boolean_T BeforGasStorageState;      /* '<Root>/Data Store Memory17' */
  boolean_T GasStorageBag_Error;       /* '<Root>/Data Store Memory6' */
  boolean_T isStable;                  /* '<Root>/Passive_flank' */
  boolean_T isStable_h;                /* '<Root>/Passive_Lumbar' */
  boolean_T Loc_TimeState;             /* '<Root>/Massage_of_stateflow' */
  boolean_T isStable_e;                /* '<Root>/Massage_of_stateflow' */
  DW_Left_Lumbar_BackMassage_Mo_T sf_Right_Lumbar;/* '<S3>/Right_Lumbar' */
  DW_Left_Lumbar_BackMassage_Mo_T sf_Left_Lumbar;/* '<S3>/Left_Lumbar' */
  DW_Left_Flank_BackMassage_Mod_T sf_Right_Flank;/* '<S2>/Right_Flank' */
  DW_Left_Flank_BackMassage_Mod_T sf_Left_Flank;/* '<S2>/Left_Flank' */
} DW_BackMassage_Model_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  uint8_T Out_Record_List;             /* '<Root>/Out_Record_List' */
  boolean_T Out_GasStroage_Error;      /* '<Root>/Out_GasStroage_Error' */
} ExtY_BackMassage_Model_T;

/* Real-time Model Data Structure */
struct tag_RTM_BackMassage_Model_T {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern B_BackMassage_Model_T BackMassage_Model_B;

/* Block states (default storage) */
extern DW_BackMassage_Model_T BackMassage_Model_DW;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_BackMassage_Model_T BackMassage_Model_Y;

/* Model entry point functions */
extern void BackMassage_Model_initialize(void);
extern void BackMassage_Model_step(void);
extern void BackMassage_Model_terminate(void);

/* Real-time Model object */
extern RT_MODEL_BackMassage_Model_T *const BackMassage_Model_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'BackMassage_Model'
 * '<S1>'   : 'BackMassage_Model/Active_Flank'
 * '<S2>'   : 'BackMassage_Model/Auto_Flank'
 * '<S3>'   : 'BackMassage_Model/Auto_Lumbar'
 * '<S4>'   : 'BackMassage_Model/FuncSelect_Flank'
 * '<S5>'   : 'BackMassage_Model/FuncSelect_Lumbar'
 * '<S6>'   : 'BackMassage_Model/Function_switch'
 * '<S7>'   : 'BackMassage_Model/GasStorage'
 * '<S8>'   : 'BackMassage_Model/MassageSigDeal'
 * '<S9>'   : 'BackMassage_Model/Massage_of_stateflow'
 * '<S10>'  : 'BackMassage_Model/OutGasStorage'
 * '<S11>'  : 'BackMassage_Model/Passive_Lumbar'
 * '<S12>'  : 'BackMassage_Model/Passive_flank'
 * '<S13>'  : 'BackMassage_Model/SensorFunc'
 * '<S14>'  : 'BackMassage_Model/Auto_Flank/Left_Flank'
 * '<S15>'  : 'BackMassage_Model/Auto_Flank/Right_Flank'
 * '<S16>'  : 'BackMassage_Model/Auto_Lumbar/Left_Lumbar'
 * '<S17>'  : 'BackMassage_Model/Auto_Lumbar/Right_Lumbar'
 */
#endif                                 /* RTW_HEADER_BackMassage_Model_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
