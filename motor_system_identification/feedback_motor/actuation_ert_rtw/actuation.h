/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: actuation.h
 *
 * Code generated for Simulink model 'actuation'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Tue Apr  4 13:11:44 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_actuation_h_
#define RTW_HEADER_actuation_h_
#ifndef actuation_COMMON_INCLUDES_
#define actuation_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_ServoWriteRead.h"
#endif                                 /* actuation_COMMON_INCLUDES_ */

#include "actuation_types.h"
#include <stddef.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  uint16_T Output_DSTATE;              /* '<S2>/Output' */
} DW_actuation_T;

/* Parameters (default storage) */
struct P_actuation_T_ {
  uint16_T LimitedCounter_uplimit;     /* Mask Parameter: LimitedCounter_uplimit
                                        * Referenced by: '<S4>/FixPt Switch'
                                        */
  uint8_T DesiredShaftAngle_OutValues[360];
                                  /* Mask Parameter: DesiredShaftAngle_OutValues
                                   * Referenced by: '<S1>/Vector'
                                   */
  uint16_T Constant_Value;             /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S4>/Constant'
                                        */
  uint16_T Output_InitialCondition;
                                  /* Computed Parameter: Output_InitialCondition
                                   * Referenced by: '<S2>/Output'
                                   */
  uint16_T FixPtConstant_Value;       /* Computed Parameter: FixPtConstant_Value
                                       * Referenced by: '<S3>/FixPt Constant'
                                       */
};

/* Real-time Model Data Structure */
struct tag_RTM_actuation_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P_actuation_T actuation_P;

/* Block states (default storage) */
extern DW_actuation_T actuation_DW;

/* Model entry point functions */
extern void actuation_initialize(void);
extern void actuation_step(void);
extern void actuation_terminate(void);

/* Real-time Model object */
extern RT_MODEL_actuation_T *const actuation_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S2>/Data Type Propagation' : Unused code path elimination
 * Block '<S3>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S4>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S1>/Out' : Eliminate redundant signal conversion block
 */

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
 * '<Root>' : 'actuation'
 * '<S1>'   : 'actuation/Desired Shaft  Angle'
 * '<S2>'   : 'actuation/Desired Shaft  Angle/LimitedCounter'
 * '<S3>'   : 'actuation/Desired Shaft  Angle/LimitedCounter/Increment Real World'
 * '<S4>'   : 'actuation/Desired Shaft  Angle/LimitedCounter/Wrap To Zero'
 */
#endif                                 /* RTW_HEADER_actuation_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
