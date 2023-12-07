/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
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

volatile int IsrOverrun = 0;
static boolean_T OverrunFlag = 0;
void rt_OneStep(void)
{
  /* Check for overrun. Protect OverrunFlag against preemption */
  if (OverrunFlag++) {
    IsrOverrun = 1;
    OverrunFlag--;
    return;
  }

#ifndef _MW_ARDUINO_LOOP_

  sei();

#endif;

  actuation_step();

  /* Get model outputs here */
#ifndef _MW_ARDUINO_LOOP_

  cli();

#endif;

  OverrunFlag--;
}

volatile boolean_T stopRequested;
volatile boolean_T runModel;
int main(void)
{
  float modelBaseRate = 0.0005;
  float systemClock = 0;

  /* Initialize variables */
  stopRequested = false;
  runModel = false;
  init();
  MW_Arduino_Init();
  rtmSetErrorStatus(actuation_M, 0);
  actuation_initialize();
  cli();
  configureArduinoAVRTimer();
  runModel = rtmGetErrorStatus(actuation_M) == (NULL);

#ifndef _MW_ARDUINO_LOOP_

  sei();

#endif;

  sei();
  while (runModel) {
    stopRequested = !(rtmGetErrorStatus(actuation_M) == (NULL));
    runModel = !(stopRequested);
    MW_Arduino_Loop();
  }

  /* Terminate model */
  actuation_terminate();
  cli();
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
