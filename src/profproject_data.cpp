//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: profproject_data.cpp
//
// Code generated for Simulink model 'profproject'.
//
// Model version                  : 6.11
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Wed Oct 25 21:47:47 2023
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "profproject.h"

// Block parameters (default storage)
P_profproject_T profproject_P = {
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

  // Computed Parameter: Constant_Value_g
  //  Referenced by: '<S4>/Constant'

  {
    0.0                                // Data
  },

  // Computed Parameter: Out1_Y0_d
  //  Referenced by: '<S8>/Out1'

  {
    0.0                                // Data
  },

  // Computed Parameter: Constant_Value_p
  //  Referenced by: '<S5>/Constant'

  {
    0.0                                // Data
  },

  // Expression: 0
  //  Referenced by: '<Root>/Integrator'

  0.0,

  // Expression: 0.05
  //  Referenced by: '<Root>/Gain1'

  0.05,

  // Expression: 1.5
  //  Referenced by: '<Root>/Saturation'

  1.5,

  // Expression: -3
  //  Referenced by: '<Root>/Saturation'

  -3.0,

  // Expression: 0.05
  //  Referenced by: '<Root>/Gain'

  0.05
};

//
// File trailer for generated code.
//
// [EOF]
//
