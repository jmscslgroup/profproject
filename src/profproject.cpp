//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: profproject.cpp
//
// Code generated for Simulink model 'profproject'.
//
// Model version                  : 6.22
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Mon Nov  6 21:43:11 2023
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "profproject.h"

extern "C"
{

#include "rt_nonfinite.h"

}

#include <math.h>
#include "rtwtypes.h"
#include "profproject_types.h"
#include "profproject_private.h"

// Block signals (default storage)
B_profproject_T profproject_B;

// Continuous states
X_profproject_T profproject_X;

// Block states (default storage)
DW_profproject_T profproject_DW;

// Real-time model
RT_MODEL_profproject_T profproject_M_ = RT_MODEL_profproject_T();
RT_MODEL_profproject_T *const profproject_M = &profproject_M_;

//
// This function updates continuous states using the ODE3 fixed-step
// solver algorithm
//
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  // Solver Matrices
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = static_cast<ODE3_IntgData *>(rtsiGetSolverData(si));
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  // Save the state values at time t in y, we'll use x as ynew.
  (void) memcpy(y, x,
                static_cast<uint_T>(nXc)*sizeof(real_T));

  // Assumes that rtsiSetT and ModelOutputs are up-to-date
  // f0 = f(t,y)
  rtsiSetdX(si, f0);
  profproject_derivatives();

  // f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*));
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  profproject_step();
  profproject_derivatives();

  // f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*));
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  profproject_step();
  profproject_derivatives();

  // tnew = t + hA(3);
  // ynew = y + f*hB(:,3);
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

// Model step function
void profproject_step(void)
{
  SL_Bus_profproject_std_msgs_Float64 b_varargout_2;
  SL_Bus_profproject_std_msgs_Float64 rtb_BusAssignment;
  real_T rtb_IntegralGain;
  real_T rtb_SignPreSat;
  real_T rtb_ZeroGain;
  real_T rtb_safeValue;
  int32_T tmp;
  if (rtmIsMajorTimeStep(profproject_M)) {
    // set solver stop time
    rtsiSetSolverStopTime(&profproject_M->solverInfo,
                          ((profproject_M->Timing.clockTick0+1)*
      profproject_M->Timing.stepSize0));
  }                                    // end MajorTimeStep

  // Update absolute time of base rate at minor time step
  if (rtmIsMinorTimeStep(profproject_M)) {
    profproject_M->Timing.t[0] = rtsiGetT(&profproject_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(profproject_M)) {
    boolean_T b_varargout_1;

    // Outputs for Atomic SubSystem: '<Root>/Subscribe1'
    // MATLABSystem: '<S4>/SourceBlock'
    b_varargout_1 = Sub_profproject_39.getLatestMessage(&b_varargout_2);

    // Outputs for Enabled SubSystem: '<S4>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S7>/Enable'

    if (b_varargout_1) {
      // SignalConversion generated from: '<S7>/In1'
      profproject_B.In1 = b_varargout_2;
    }

    // End of Outputs for SubSystem: '<S4>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<Root>/Subscribe1'

    // Outputs for Atomic SubSystem: '<Root>/Dead Man's Switch'
    // MATLAB Function: '<S2>/timeout set to 0 output' incorporates:
    //   MATLABSystem: '<S4>/SourceBlock'

    if (!profproject_DW.sinceLastMsg_not_empty) {
      // Outputs for Atomic SubSystem: '<Root>/Dead Man's Switch'
      profproject_DW.sinceLastMsg = profproject_P.DeadMansSwitch_timeout /
        profproject_P.DeadMansSwitch_stepSize + 1.0;

      // End of Outputs for SubSystem: '<Root>/Dead Man's Switch'
      profproject_DW.sinceLastMsg_not_empty = true;
    }

    rtb_safeValue = 0.0;

    // Outputs for Atomic SubSystem: '<Root>/Subscribe1'
    if (b_varargout_1) {
      profproject_DW.sinceLastMsg = 0.0;
    } else {
      profproject_DW.sinceLastMsg++;
    }

    // End of Outputs for SubSystem: '<Root>/Subscribe1'

    // Outputs for Atomic SubSystem: '<Root>/Dead Man's Switch'
    if (profproject_DW.sinceLastMsg < profproject_P.DeadMansSwitch_timeout /
        profproject_P.DeadMansSwitch_stepSize) {
      rtb_safeValue = profproject_B.In1.Data;
    }

    // End of MATLAB Function: '<S2>/timeout set to 0 output'
    // End of Outputs for SubSystem: '<Root>/Dead Man's Switch'
    // End of Outputs for SubSystem: '<Root>/Dead Man's Switch'

    // Gain: '<S46>/Proportional Gain'
    profproject_B.ProportionalGain = profproject_P.rawaccel_P * rtb_safeValue;

    // Gain: '<S35>/Derivative Gain'
    profproject_B.DerivativeGain = profproject_P.rawaccel_D * rtb_safeValue;
  }

  // Gain: '<S44>/Filter Coefficient' incorporates:
  //   Integrator: '<S36>/Filter'
  //   Sum: '<S36>/SumD'

  profproject_B.FilterCoefficient = (profproject_B.DerivativeGain -
    profproject_X.Filter_CSTATE) * profproject_P.rawaccel_N;

  // Sum: '<S50>/Sum' incorporates:
  //   Integrator: '<S41>/Integrator'

  rtb_SignPreSat = (profproject_B.ProportionalGain +
                    profproject_X.Integrator_CSTATE) +
    profproject_B.FilterCoefficient;

  // Saturate: '<S48>/Saturation'
  if (rtb_SignPreSat > profproject_P.rawaccel_UpperSaturationLimit) {
    rtb_ZeroGain = profproject_P.rawaccel_UpperSaturationLimit;
  } else if (rtb_SignPreSat < profproject_P.rawaccel_LowerSaturationLimit) {
    rtb_ZeroGain = profproject_P.rawaccel_LowerSaturationLimit;
  } else {
    rtb_ZeroGain = rtb_SignPreSat;
  }

  // End of Saturate: '<S48>/Saturation'

  // Saturate: '<Root>/Saturation'
  if (rtb_ZeroGain > profproject_P.Saturation_UpperSat) {
    // BusAssignment: '<Root>/Bus Assignment'
    rtb_BusAssignment.Data = profproject_P.Saturation_UpperSat;
  } else if (rtb_ZeroGain < profproject_P.Saturation_LowerSat) {
    // BusAssignment: '<Root>/Bus Assignment'
    rtb_BusAssignment.Data = profproject_P.Saturation_LowerSat;
  } else {
    // BusAssignment: '<Root>/Bus Assignment'
    rtb_BusAssignment.Data = rtb_ZeroGain;
  }

  // End of Saturate: '<Root>/Saturation'

  // Outputs for Atomic SubSystem: '<Root>/Publish'
  // MATLABSystem: '<S3>/SinkBlock'
  Pub_profproject_35.publish(&rtb_BusAssignment);

  // End of Outputs for SubSystem: '<Root>/Publish'

  // Gain: '<S32>/ZeroGain'
  rtb_ZeroGain = profproject_P.ZeroGain_Gain * rtb_SignPreSat;

  // DeadZone: '<S34>/DeadZone'
  if (rtb_SignPreSat > profproject_P.rawaccel_UpperSaturationLimit) {
    rtb_SignPreSat -= profproject_P.rawaccel_UpperSaturationLimit;
  } else if (rtb_SignPreSat >= profproject_P.rawaccel_LowerSaturationLimit) {
    rtb_SignPreSat = 0.0;
  } else {
    rtb_SignPreSat -= profproject_P.rawaccel_LowerSaturationLimit;
  }

  // End of DeadZone: '<S34>/DeadZone'
  if (rtmIsMajorTimeStep(profproject_M)) {
    // Gain: '<S38>/Integral Gain'
    rtb_IntegralGain = profproject_P.rawaccel_I * rtb_safeValue;

    // Signum: '<S32>/SignPreIntegrator'
    if (rtIsNaN(rtb_IntegralGain)) {
      // DataTypeConversion: '<S32>/DataTypeConv2'
      rtb_safeValue = (rtNaN);
    } else if (rtb_IntegralGain < 0.0) {
      // DataTypeConversion: '<S32>/DataTypeConv2'
      rtb_safeValue = -1.0;
    } else {
      // DataTypeConversion: '<S32>/DataTypeConv2'
      rtb_safeValue = (rtb_IntegralGain > 0.0);
    }

    // End of Signum: '<S32>/SignPreIntegrator'

    // DataTypeConversion: '<S32>/DataTypeConv2'
    if (rtIsNaN(rtb_safeValue)) {
      tmp = 0;
    } else {
      tmp = static_cast<int32_T>(fmod(rtb_safeValue, 256.0));
    }

    // DataTypeConversion: '<S32>/DataTypeConv2'
    profproject_B.DataTypeConv2 = static_cast<int8_T>(tmp < 0 ?
      static_cast<int32_T>(static_cast<int8_T>(-static_cast<int8_T>(static_cast<
      uint8_T>(-static_cast<real_T>(tmp))))) : tmp);
  }

  // Signum: '<S32>/SignPreSat'
  if (rtIsNaN(rtb_SignPreSat)) {
    // DataTypeConversion: '<S32>/DataTypeConv1'
    rtb_safeValue = (rtNaN);
  } else if (rtb_SignPreSat < 0.0) {
    // DataTypeConversion: '<S32>/DataTypeConv1'
    rtb_safeValue = -1.0;
  } else {
    // DataTypeConversion: '<S32>/DataTypeConv1'
    rtb_safeValue = (rtb_SignPreSat > 0.0);
  }

  // End of Signum: '<S32>/SignPreSat'

  // DataTypeConversion: '<S32>/DataTypeConv1'
  if (rtIsNaN(rtb_safeValue)) {
    tmp = 0;
  } else {
    tmp = static_cast<int32_T>(fmod(rtb_safeValue, 256.0));
  }

  // Logic: '<S32>/AND3' incorporates:
  //   DataTypeConversion: '<S32>/DataTypeConv1'
  //   RelationalOperator: '<S32>/Equal1'
  //   RelationalOperator: '<S32>/NotEqual'

  profproject_B.AND3 = ((rtb_ZeroGain != rtb_SignPreSat) && ((tmp < 0 ?
    static_cast<int32_T>(static_cast<int8_T>(-static_cast<int8_T>
    (static_cast<uint8_T>(-static_cast<real_T>(tmp))))) : tmp) ==
    profproject_B.DataTypeConv2));
  if (rtmIsMajorTimeStep(profproject_M)) {
    // Switch: '<S32>/Switch' incorporates:
    //   Memory: '<S32>/Memory'

    if (profproject_DW.Memory_PreviousInput) {
      // Switch: '<S32>/Switch' incorporates:
      //   Constant: '<S32>/Constant1'

      profproject_B.Switch = profproject_P.Constant1_Value;
    } else {
      // Switch: '<S32>/Switch'
      profproject_B.Switch = rtb_IntegralGain;
    }

    // End of Switch: '<S32>/Switch'
  }

  if (rtmIsMajorTimeStep(profproject_M)) {
    if (rtmIsMajorTimeStep(profproject_M)) {
      // Update for Memory: '<S32>/Memory'
      profproject_DW.Memory_PreviousInput = profproject_B.AND3;
    }
  }                                    // end MajorTimeStep

  if (rtmIsMajorTimeStep(profproject_M)) {
    rt_ertODEUpdateContinuousStates(&profproject_M->solverInfo);

    // Update absolute time for base rate
    // The "clockTick0" counts the number of times the code of this task has
    //  been executed. The absolute time is the multiplication of "clockTick0"
    //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
    //  overflow during the application lifespan selected.

    ++profproject_M->Timing.clockTick0;
    profproject_M->Timing.t[0] = rtsiGetSolverStopTime
      (&profproject_M->solverInfo);

    {
      // Update absolute timer for sample time: [0.05s, 0.0s]
      // The "clockTick1" counts the number of times the code of this task has
      //  been executed. The resolution of this integer timer is 0.05, which is the step size
      //  of the task. Size of "clockTick1" ensures timer will not overflow during the
      //  application lifespan selected.

      profproject_M->Timing.clockTick1++;
    }
  }                                    // end MajorTimeStep
}

// Derivatives for root system: '<Root>'
void profproject_derivatives(void)
{
  XDot_profproject_T *_rtXdot;
  _rtXdot = ((XDot_profproject_T *) profproject_M->derivs);

  // Derivatives for Integrator: '<S41>/Integrator'
  _rtXdot->Integrator_CSTATE = profproject_B.Switch;

  // Derivatives for Integrator: '<S36>/Filter'
  _rtXdot->Filter_CSTATE = profproject_B.FilterCoefficient;
}

// Model initialize function
void profproject_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  {
    // Setup solver object
    rtsiSetSimTimeStepPtr(&profproject_M->solverInfo,
                          &profproject_M->Timing.simTimeStep);
    rtsiSetTPtr(&profproject_M->solverInfo, &rtmGetTPtr(profproject_M));
    rtsiSetStepSizePtr(&profproject_M->solverInfo,
                       &profproject_M->Timing.stepSize0);
    rtsiSetdXPtr(&profproject_M->solverInfo, &profproject_M->derivs);
    rtsiSetContStatesPtr(&profproject_M->solverInfo, (real_T **)
                         &profproject_M->contStates);
    rtsiSetNumContStatesPtr(&profproject_M->solverInfo,
      &profproject_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&profproject_M->solverInfo,
      &profproject_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&profproject_M->solverInfo,
      &profproject_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&profproject_M->solverInfo,
      &profproject_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&profproject_M->solverInfo, (&rtmGetErrorStatus
      (profproject_M)));
    rtsiSetRTModelPtr(&profproject_M->solverInfo, profproject_M);
  }

  rtsiSetSimTimeStep(&profproject_M->solverInfo, MAJOR_TIME_STEP);
  profproject_M->intgData.y = profproject_M->odeY;
  profproject_M->intgData.f[0] = profproject_M->odeF[0];
  profproject_M->intgData.f[1] = profproject_M->odeF[1];
  profproject_M->intgData.f[2] = profproject_M->odeF[2];
  profproject_M->contStates = ((X_profproject_T *) &profproject_X);
  rtsiSetSolverData(&profproject_M->solverInfo, static_cast<void *>
                    (&profproject_M->intgData));
  rtsiSetIsMinorTimeStepWithModeChange(&profproject_M->solverInfo, false);
  rtsiSetSolverName(&profproject_M->solverInfo,"ode3");
  rtmSetTPtr(profproject_M, &profproject_M->Timing.tArray[0]);
  profproject_M->Timing.stepSize0 = 0.05;

  {
    char_T b_zeroDelimTopic_0[10];
    char_T b_zeroDelimTopic[8];
    static const char_T tmp[7] = { 'r', 'e', 'l', '_', 'v', 'e', 'l' };

    static const char_T tmp_0[9] = { 'c', 'm', 'd', '_', 'a', 'c', 'c', 'e', 'l'
    };

    // InitializeConditions for Integrator: '<S41>/Integrator'
    profproject_X.Integrator_CSTATE =
      profproject_P.rawaccel_InitialConditionForInt;

    // InitializeConditions for Integrator: '<S36>/Filter'
    profproject_X.Filter_CSTATE = profproject_P.rawaccel_InitialConditionForFil;

    // InitializeConditions for Memory: '<S32>/Memory'
    profproject_DW.Memory_PreviousInput = profproject_P.Memory_InitialCondition;

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe1'
    // SystemInitialize for Enabled SubSystem: '<S4>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S7>/In1' incorporates:
    //   Outport: '<S7>/Out1'

    profproject_B.In1 = profproject_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S4>/Enabled Subsystem'

    // Start for MATLABSystem: '<S4>/SourceBlock'
    profproject_DW.obj_k.matlabCodegenIsDeleted = false;
    profproject_DW.obj_k.isInitialized = 1;
    for (int32_T i = 0; i < 7; i++) {
      b_zeroDelimTopic[i] = tmp[i];
    }

    b_zeroDelimTopic[7] = '\x00';
    Sub_profproject_39.createSubscriber(&b_zeroDelimTopic[0], 1);
    profproject_DW.obj_k.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S4>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe1'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish'
    // Start for MATLABSystem: '<S3>/SinkBlock'
    profproject_DW.obj.matlabCodegenIsDeleted = false;
    profproject_DW.obj.isInitialized = 1;
    for (int32_T i = 0; i < 9; i++) {
      b_zeroDelimTopic_0[i] = tmp_0[i];
    }

    b_zeroDelimTopic_0[9] = '\x00';
    Pub_profproject_35.createPublisher(&b_zeroDelimTopic_0[0], 1);
    profproject_DW.obj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S3>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish'
  }
}

// Model terminate function
void profproject_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Subscribe1'
  // Terminate for MATLABSystem: '<S4>/SourceBlock'
  if (!profproject_DW.obj_k.matlabCodegenIsDeleted) {
    profproject_DW.obj_k.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S4>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe1'

  // Terminate for Atomic SubSystem: '<Root>/Publish'
  // Terminate for MATLABSystem: '<S3>/SinkBlock'
  if (!profproject_DW.obj.matlabCodegenIsDeleted) {
    profproject_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S3>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish'
}

//
// File trailer for generated code.
//
// [EOF]
//
