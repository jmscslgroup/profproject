//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: profproject.h
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
#ifndef RTW_HEADER_profproject_h_
#define RTW_HEADER_profproject_h_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros_initialize.h"
#include "profproject_types.h"

extern "C"
{

#include "rtGetNaN.h"

}

extern "C"
{

#include "rt_nonfinite.h"

}

extern "C"
{

#include "rtGetInf.h"

}

#include <string.h>
#include <stddef.h>

// Macros for accessing real-time model data structure
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

// Block signals (default storage)
struct B_profproject_T {
  real_T ProportionalGain;             // '<S46>/Proportional Gain'
  real_T DerivativeGain;               // '<S35>/Derivative Gain'
  real_T FilterCoefficient;            // '<S44>/Filter Coefficient'
  real_T Switch;                       // '<S32>/Switch'
  SL_Bus_profproject_std_msgs_Float64 In1;// '<S7>/In1'
  int8_T DataTypeConv2;                // '<S32>/DataTypeConv2'
  boolean_T AND3;                      // '<S32>/AND3'
};

// Block states (default storage) for system '<Root>'
struct DW_profproject_T {
  ros_slroscpp_internal_block_P_T obj; // '<S3>/SinkBlock'
  ros_slroscpp_internal_block_S_T obj_k;// '<S4>/SourceBlock'
  real_T sinceLastMsg;                 // '<S2>/timeout set to 0 output'
  boolean_T Memory_PreviousInput;      // '<S32>/Memory'
  boolean_T sinceLastMsg_not_empty;    // '<S2>/timeout set to 0 output'
};

// Continuous states (default storage)
struct X_profproject_T {
  real_T Integrator_CSTATE;            // '<S41>/Integrator'
  real_T Filter_CSTATE;                // '<S36>/Filter'
};

// State derivatives (default storage)
struct XDot_profproject_T {
  real_T Integrator_CSTATE;            // '<S41>/Integrator'
  real_T Filter_CSTATE;                // '<S36>/Filter'
};

// State disabled
struct XDis_profproject_T {
  boolean_T Integrator_CSTATE;         // '<S41>/Integrator'
  boolean_T Filter_CSTATE;             // '<S36>/Filter'
};

#ifndef ODE3_INTG
#define ODE3_INTG

// ODE3 Integration Data
struct ODE3_IntgData {
  real_T *y;                           // output
  real_T *f[3];                        // derivatives
};

#endif

// Parameters (default storage)
struct P_profproject_T_ {
  real_T rawaccel_D;                   // Mask Parameter: rawaccel_D
                                          //  Referenced by: '<S35>/Derivative Gain'

  real_T rawaccel_I;                   // Mask Parameter: rawaccel_I
                                          //  Referenced by: '<S38>/Integral Gain'

  real_T rawaccel_InitialConditionForFil;
                              // Mask Parameter: rawaccel_InitialConditionForFil
                                 //  Referenced by: '<S36>/Filter'

  real_T rawaccel_InitialConditionForInt;
                              // Mask Parameter: rawaccel_InitialConditionForInt
                                 //  Referenced by: '<S41>/Integrator'

  real_T rawaccel_LowerSaturationLimit;
                                // Mask Parameter: rawaccel_LowerSaturationLimit
                                   //  Referenced by:
                                   //    '<S48>/Saturation'
                                   //    '<S34>/DeadZone'

  real_T rawaccel_N;                   // Mask Parameter: rawaccel_N
                                          //  Referenced by: '<S44>/Filter Coefficient'

  real_T rawaccel_P;                   // Mask Parameter: rawaccel_P
                                          //  Referenced by: '<S46>/Proportional Gain'

  real_T rawaccel_UpperSaturationLimit;
                                // Mask Parameter: rawaccel_UpperSaturationLimit
                                   //  Referenced by:
                                   //    '<S48>/Saturation'
                                   //    '<S34>/DeadZone'

  real_T DeadMansSwitch_stepSize;     // Mask Parameter: DeadMansSwitch_stepSize
                                         //  Referenced by: '<S2>/Simulate step size'

  real_T DeadMansSwitch_timeout;       // Mask Parameter: DeadMansSwitch_timeout
                                          //  Referenced by: '<S2>/Timeout in seconds'

  SL_Bus_profproject_std_msgs_Float64 Constant_Value;// Computed Parameter: Constant_Value
                                                        //  Referenced by: '<S1>/Constant'

  SL_Bus_profproject_std_msgs_Float64 Out1_Y0;// Computed Parameter: Out1_Y0
                                                 //  Referenced by: '<S7>/Out1'

  SL_Bus_profproject_std_msgs_Float64 Constant_Value_p;// Computed Parameter: Constant_Value_p
                                                          //  Referenced by: '<S4>/Constant'

  real_T Constant1_Value;              // Expression: 0
                                          //  Referenced by: '<S32>/Constant1'

  real_T Saturation_UpperSat;          // Expression: 1.5
                                          //  Referenced by: '<Root>/Saturation'

  real_T Saturation_LowerSat;          // Expression: -3
                                          //  Referenced by: '<Root>/Saturation'

  real_T ZeroGain_Gain;                // Expression: 0
                                          //  Referenced by: '<S32>/ZeroGain'

  boolean_T Memory_InitialCondition;
                                  // Computed Parameter: Memory_InitialCondition
                                     //  Referenced by: '<S32>/Memory'

};

// Real-time Model Data Structure
struct tag_RTM_profproject_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_profproject_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_profproject_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[2];
  real_T odeF[3][2];
  ODE3_IntgData intgData;

  //
  //  Sizes:
  //  The following substructure contains sizes information
  //  for many of the model attributes such as inputs, outputs,
  //  dwork, sample times, etc.

  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern P_profproject_T profproject_P;

#ifdef __cplusplus

}

#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_profproject_T profproject_B;

#ifdef __cplusplus

}

#endif

// Continuous states (default storage)
extern X_profproject_T profproject_X;

// Block states (default storage)
extern struct DW_profproject_T profproject_DW;

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void profproject_initialize(void);
  extern void profproject_step(void);
  extern void profproject_terminate(void);

#ifdef __cplusplus

}

#endif

// Real-time Model object
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_profproject_T *const profproject_M;

#ifdef __cplusplus

}

#endif

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<Root>/Scope' : Unused code path elimination


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'profproject'
//  '<S1>'   : 'profproject/Blank Message'
//  '<S2>'   : 'profproject/Dead Man's Switch'
//  '<S3>'   : 'profproject/Publish'
//  '<S4>'   : 'profproject/Subscribe1'
//  '<S5>'   : 'profproject/rawaccel'
//  '<S6>'   : 'profproject/Dead Man's Switch/timeout set to 0 output'
//  '<S7>'   : 'profproject/Subscribe1/Enabled Subsystem'
//  '<S8>'   : 'profproject/rawaccel/Anti-windup'
//  '<S9>'   : 'profproject/rawaccel/D Gain'
//  '<S10>'  : 'profproject/rawaccel/Filter'
//  '<S11>'  : 'profproject/rawaccel/Filter ICs'
//  '<S12>'  : 'profproject/rawaccel/I Gain'
//  '<S13>'  : 'profproject/rawaccel/Ideal P Gain'
//  '<S14>'  : 'profproject/rawaccel/Ideal P Gain Fdbk'
//  '<S15>'  : 'profproject/rawaccel/Integrator'
//  '<S16>'  : 'profproject/rawaccel/Integrator ICs'
//  '<S17>'  : 'profproject/rawaccel/N Copy'
//  '<S18>'  : 'profproject/rawaccel/N Gain'
//  '<S19>'  : 'profproject/rawaccel/P Copy'
//  '<S20>'  : 'profproject/rawaccel/Parallel P Gain'
//  '<S21>'  : 'profproject/rawaccel/Reset Signal'
//  '<S22>'  : 'profproject/rawaccel/Saturation'
//  '<S23>'  : 'profproject/rawaccel/Saturation Fdbk'
//  '<S24>'  : 'profproject/rawaccel/Sum'
//  '<S25>'  : 'profproject/rawaccel/Sum Fdbk'
//  '<S26>'  : 'profproject/rawaccel/Tracking Mode'
//  '<S27>'  : 'profproject/rawaccel/Tracking Mode Sum'
//  '<S28>'  : 'profproject/rawaccel/Tsamp - Integral'
//  '<S29>'  : 'profproject/rawaccel/Tsamp - Ngain'
//  '<S30>'  : 'profproject/rawaccel/postSat Signal'
//  '<S31>'  : 'profproject/rawaccel/preSat Signal'
//  '<S32>'  : 'profproject/rawaccel/Anti-windup/Cont. Clamping Parallel'
//  '<S33>'  : 'profproject/rawaccel/Anti-windup/Cont. Clamping Parallel/Dead Zone'
//  '<S34>'  : 'profproject/rawaccel/Anti-windup/Cont. Clamping Parallel/Dead Zone/Enabled'
//  '<S35>'  : 'profproject/rawaccel/D Gain/Internal Parameters'
//  '<S36>'  : 'profproject/rawaccel/Filter/Cont. Filter'
//  '<S37>'  : 'profproject/rawaccel/Filter ICs/Internal IC - Filter'
//  '<S38>'  : 'profproject/rawaccel/I Gain/Internal Parameters'
//  '<S39>'  : 'profproject/rawaccel/Ideal P Gain/Passthrough'
//  '<S40>'  : 'profproject/rawaccel/Ideal P Gain Fdbk/Disabled'
//  '<S41>'  : 'profproject/rawaccel/Integrator/Continuous'
//  '<S42>'  : 'profproject/rawaccel/Integrator ICs/Internal IC'
//  '<S43>'  : 'profproject/rawaccel/N Copy/Disabled'
//  '<S44>'  : 'profproject/rawaccel/N Gain/Internal Parameters'
//  '<S45>'  : 'profproject/rawaccel/P Copy/Disabled'
//  '<S46>'  : 'profproject/rawaccel/Parallel P Gain/Internal Parameters'
//  '<S47>'  : 'profproject/rawaccel/Reset Signal/Disabled'
//  '<S48>'  : 'profproject/rawaccel/Saturation/Enabled'
//  '<S49>'  : 'profproject/rawaccel/Saturation Fdbk/Disabled'
//  '<S50>'  : 'profproject/rawaccel/Sum/Sum_PID'
//  '<S51>'  : 'profproject/rawaccel/Sum Fdbk/Disabled'
//  '<S52>'  : 'profproject/rawaccel/Tracking Mode/Disabled'
//  '<S53>'  : 'profproject/rawaccel/Tracking Mode Sum/Passthrough'
//  '<S54>'  : 'profproject/rawaccel/Tsamp - Integral/Passthrough'
//  '<S55>'  : 'profproject/rawaccel/Tsamp - Ngain/Passthrough'
//  '<S56>'  : 'profproject/rawaccel/postSat Signal/Forward_Path'
//  '<S57>'  : 'profproject/rawaccel/preSat Signal/Forward_Path'

#endif                                 // RTW_HEADER_profproject_h_

//
// File trailer for generated code.
//
// [EOF]
//
