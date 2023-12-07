/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: actuation.c
 *
 * Code generated for Simulink model 'actuation'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Fri Apr  7 23:07:34 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "actuation.h"
#include "rtwtypes.h"
#include "actuation_types.h"

/* Block states (default storage) */
DW_actuation_T actuation_DW;

/* Real-time model */
static RT_MODEL_actuation_T actuation_M_;
RT_MODEL_actuation_T *const actuation_M = &actuation_M_;

/* Model step function */
void actuation_step(void)
{
  codertarget_arduinobase_inter_T *obj;
  real_T rtb_PulseGenerator;

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  rtb_PulseGenerator = (actuation_DW.clockTickCounter <
                        actuation_P.PulseGenerator_Duty) &&
    (actuation_DW.clockTickCounter >= 0L) ? actuation_P.PulseGenerator_Amp : 0.0;
  if (actuation_DW.clockTickCounter >= actuation_P.PulseGenerator_Period - 1.0)
  {
    actuation_DW.clockTickCounter = 0L;
  } else {
    actuation_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* MATLABSystem: '<Root>/PWM' */
  obj = &actuation_DW.obj;
  obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(7UL);
  if (!(rtb_PulseGenerator <= 255.0)) {
    rtb_PulseGenerator = 255.0;
  }

  if (!(rtb_PulseGenerator >= 0.0)) {
    rtb_PulseGenerator = 0.0;
  }

  MW_PWM_SetDutyCycle(actuation_DW.obj.PWMDriverObj.MW_PWM_HANDLE,
                      rtb_PulseGenerator);

  /* End of MATLABSystem: '<Root>/PWM' */
}

/* Model initialize function */
void actuation_initialize(void)
{
  {
    codertarget_arduinobase_inter_T *obj;

    /* Start for MATLABSystem: '<Root>/PWM' */
    actuation_DW.obj.matlabCodegenIsDeleted = true;
    actuation_DW.obj.isInitialized = 0L;
    actuation_DW.obj.matlabCodegenIsDeleted = false;
    obj = &actuation_DW.obj;
    actuation_DW.obj.isSetupComplete = false;
    actuation_DW.obj.isInitialized = 1L;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(7UL, 0.0, 0.0);
    actuation_DW.obj.isSetupComplete = true;
  }
}

/* Model terminate function */
void actuation_terminate(void)
{
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for MATLABSystem: '<Root>/PWM' */
  obj = &actuation_DW.obj;
  if (!actuation_DW.obj.matlabCodegenIsDeleted) {
    actuation_DW.obj.matlabCodegenIsDeleted = true;
    if ((actuation_DW.obj.isInitialized == 1L) &&
        actuation_DW.obj.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(7UL);
      MW_PWM_SetDutyCycle(actuation_DW.obj.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(7UL);
      MW_PWM_Close(actuation_DW.obj.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
