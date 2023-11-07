//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: profproject_data.cpp
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

// Block parameters (default storage)
P_profproject_T profproject_P = {
  // Mask Parameter: rawaccel_D
  //  Referenced by: '<S35>/Derivative Gain'

  0.0,

  // Mask Parameter: rawaccel_I
  //  Referenced by: '<S38>/Integral Gain'

  0.25,

  // Mask Parameter: rawaccel_InitialConditionForFil
  //  Referenced by: '<S36>/Filter'

  0.0,

  // Mask Parameter: rawaccel_InitialConditionForInt
  //  Referenced by: '<S41>/Integrator'

  0.0,

  // Mask Parameter: rawaccel_LowerSaturationLimit
  //  Referenced by:
  //    '<S48>/Saturation'
  //    '<S34>/DeadZone'

  -3.0,

  // Mask Parameter: rawaccel_N
  //  Referenced by: '<S44>/Filter Coefficient'

  100.0,

  // Mask Parameter: rawaccel_P
  //  Referenced by: '<S46>/Proportional Gain'

  0.25,

  // Mask Parameter: rawaccel_UpperSaturationLimit
  //  Referenced by:
  //    '<S48>/Saturation'
  //    '<S34>/DeadZone'

  1.5,

  // Mask Parameter: DeadMansSwitch_stepSize
  //  Referenced by: '<S2>/Simulate step size'

  0.05,

  // Mask Parameter: DeadMansSwitch_timeout
  //  Referenced by: '<S2>/Timeout in seconds'

  0.4,

  // Computed Parameter: Constant_Value
  //  Referenced by: '<S1>/Constant'

  {
    0.0                                // Data
  },

  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S7>/Out1'

  {
    0.0                                // Data
  },

  // Computed Parameter: Constant_Value_p
  //  Referenced by: '<S4>/Constant'

  {
    0.0                                // Data
  },

  // Expression: 0
  //  Referenced by: '<S32>/Constant1'

  0.0,

  // Expression: 1.5
  //  Referenced by: '<Root>/Saturation'

  1.5,

  // Expression: -3
  //  Referenced by: '<Root>/Saturation'

  -3.0,

  // Expression: 0
  //  Referenced by: '<S32>/ZeroGain'

  0.0,

  // Computed Parameter: Memory_InitialCondition
  //  Referenced by: '<S32>/Memory'

  false
};

//
// File trailer for generated code.
//
// [EOF]
//
