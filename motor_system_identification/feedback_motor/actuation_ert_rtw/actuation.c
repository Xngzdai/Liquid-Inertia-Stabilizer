/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: actuation.c
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

#include "actuation.h"
#include "rtwtypes.h"

/* Block states (default storage) */
DW_actuation_T actuation_DW;

/* Real-time model */
static RT_MODEL_actuation_T actuation_M_;
RT_MODEL_actuation_T *const actuation_M = &actuation_M_;

/* Model step function */
void actuation_step(void)
{
  uint8_T tmp;

  /* MATLABSystem: '<Root>/Standard Servo Write' incorporates:
   *  Constant: '<S1>/Vector'
   *  MultiPortSwitch: '<S1>/Output'
   *  UnitDelay: '<S2>/Output'
   */
  if (actuation_P.DesiredShaftAngle_OutValues[actuation_DW.Output_DSTATE] > 180)
  {
    tmp = 180U;
  } else {
    tmp = actuation_P.DesiredShaftAngle_OutValues[actuation_DW.Output_DSTATE];
  }

  MW_servoWrite(0, tmp);

  /* End of MATLABSystem: '<Root>/Standard Servo Write' */

  /* Sum: '<S3>/FixPt Sum1' incorporates:
   *  Constant: '<S3>/FixPt Constant'
   *  UnitDelay: '<S2>/Output'
   */
  actuation_DW.Output_DSTATE += actuation_P.FixPtConstant_Value;

  /* Switch: '<S4>/FixPt Switch' */
  if (actuation_DW.Output_DSTATE > actuation_P.LimitedCounter_uplimit) {
    /* Sum: '<S3>/FixPt Sum1' incorporates:
     *  Constant: '<S4>/Constant'
     */
    actuation_DW.Output_DSTATE = actuation_P.Constant_Value;
  }

  /* End of Switch: '<S4>/FixPt Switch' */
}

/* Model initialize function */
void actuation_initialize(void)
{
  /* InitializeConditions for Sum: '<S3>/FixPt Sum1' incorporates:
   *  UnitDelay: '<S2>/Output'
   */
  actuation_DW.Output_DSTATE = actuation_P.Output_InitialCondition;

  /* Start for MATLABSystem: '<Root>/Standard Servo Write' */
  MW_servoAttach(0, 4);
}

/* Model terminate function */
void actuation_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
