//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: controller.h
//
// Code generated for Simulink model 'controller'.
//
// Model version                  : 1.86
// Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
// C/C++ source code generated on : Mon Apr 27 13:35:29 2026
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef controller_h_
#define controller_h_
#include <poll.h>
#include <uORB/uORB.h>
#include <drivers/drv_hrt.h>
#include "rtwtypes.h"
#include "MW_uORB_Read.h"
#include "MW_uORB_Write.h"
#include "MW_PX4_Parameter.h"
#include "MW_Parameter.h"
#include "MW_PX4_Actuators.h"
#include "controller_types.h"
#include <uORB/topics/vehicle_odometry.h>
#include <uORB/topics/input_rc.h>
#include <uORB/topics/system_identification.h>
#include <uORB/topics/flight_testing.h>
#include <uORB/topics/sensor_accel.h>
#include <uORB/topics/sensor_gyro.h>
#include <uORB/topics/glide_controller.h>
#include <uORB/topics/airspeed.h>

extern "C"
{

#include "rt_nonfinite.h"

}

extern "C"
{

#include "rtGetNaN.h"

}

#include <stddef.h>

// Block signals for system '<S32>/PX4 Timestamp'
struct B_PX4Timestamp_controller_T {
  uint64_T PX4Timestamp;               // '<S32>/PX4 Timestamp'
};

// Block states (default storage) for system '<S32>/PX4 Timestamp'
struct DW_PX4Timestamp_controller_T {
  px4_internal_block_getPX4Abso_T obj; // '<S32>/PX4 Timestamp'
  boolean_T objisempty;                // '<S32>/PX4 Timestamp'
};

// Block signals (default storage)
struct B_controller_T {
  px4_Bus_vehicle_odometry In1;        // '<S164>/In1'
  px4_Bus_vehicle_odometry r;
  px4_Bus_input_rc In1_d;              // '<S162>/In1'
  px4_Bus_input_rc r1;
  px4_Bus_system_identification BusAssignment;// '<S156>/Bus Assignment'
  px4_Bus_flight_testing BusAssignment_j;// '<S153>/Bus Assignment'
  real32_T motorValues[12];
  real32_T motorValues_m[12];
  px4_Bus_sensor_accel r2;
  px4_Bus_sensor_gyro In1_k;           // '<S160>/In1'
  px4_Bus_sensor_gyro r3;
  px4_Bus_glide_controller BusAssignment_e;// '<S32>/Bus Assignment'
  real32_T servoValues[8];
  px4_Bus_airspeed In1_m;              // '<S150>/In1'
  px4_Bus_airspeed r4;
  real_T temp;
  uint64_T rtb_PX4Timestamp_c;
  real32_T ParamStep;
  real32_T yTemp;
  real32_T ParamStep_k;
  real32_T ParamStep_c;
  real32_T ParamStep_b;
  real32_T ParamStep_p;
  real32_T ParamStep_cv;
  real32_T ParamStep_f;
  real32_T ParamStep_g;
  B_PX4Timestamp_controller_T PX4Timestamp_n;// '<S32>/PX4 Timestamp'
  B_PX4Timestamp_controller_T PX4Timestamp;// '<S32>/PX4 Timestamp'
  B_PX4Timestamp_controller_T PX4Timestamp_h;// '<S32>/PX4 Timestamp'
};

// Block states (default storage) for system '<Root>'
struct DW_controller_T {
  px4_internal_block_PX4Actuato_T obj; // '<Root>/PX4 Actuator Write'
  px4_internal_block_Subscriber_T obj_l;// '<S163>/SourceBlock'
  px4_internal_block_Subscriber_T obj_d;// '<S161>/SourceBlock'
  px4_internal_block_Subscriber_T obj_o;// '<S159>/SourceBlock'
  px4_internal_block_Subscriber_T obj_j;// '<S151>/SourceBlock'
  px4_internal_block_Subscriber_T obj_m;// '<S149>/SourceBlock'
  px4_internal_block_Subscriber_T obj_og;// '<S6>/SourceBlock'
  px4_internal_block_getPX4Abso_T obj_h;// '<Root>/PX4 Timestamp'
  px4_internal_block_Publisher__T obj_md;// '<S158>/SinkBlock'
  px4_internal_block_Publisher__T obj_n;// '<S155>/SinkBlock'
  px4_internal_block_Publisher__T obj_h0;// '<S38>/SinkBlock'
  px4_internal_block_ParameterU_T obj_ms;// '<S14>/Read Parameter2'
  px4_internal_block_ParameterU_T obj_k;// '<S14>/Read Parameter1'
  px4_internal_block_ParameterU_T obj_nh;// '<S14>/Read Parameter'
  px4_internal_block_ParameterU_T obj_mf;// '<S12>/Read Parameter9'
  px4_internal_block_ParameterU_T obj_p;// '<S12>/Read Parameter8'
  px4_internal_block_ParameterU_T obj_l1;// '<S12>/Read Parameter7'
  px4_internal_block_ParameterU_T obj_pe;// '<S12>/Read Parameter6'
  px4_internal_block_ParameterU_T obj_o5;// '<S12>/Read Parameter5'
  px4_internal_block_ParameterU_T obj_e;// '<S12>/Read Parameter4'
  px4_internal_block_ParameterU_T obj_f;// '<S12>/Read Parameter3'
  px4_internal_block_ParameterU_T obj_ju;// '<S12>/Read Parameter2'
  px4_internal_block_ParameterU_T obj_lp;// '<S12>/Read Parameter13'
  px4_internal_block_ParameterU_T obj_g;// '<S12>/Read Parameter12'
  px4_internal_block_ParameterU_T obj_i;// '<S12>/Read Parameter11'
  px4_internal_block_ParameterU_T obj_b;// '<S12>/Read Parameter10'
  px4_internal_block_ParameterU_T obj_a;// '<S12>/Read Parameter1'
  px4_internal_block_ParameterU_T obj_ng;// '<S12>/Read Parameter'
  uint64_T StoreStartTime_PreviousInput;// '<S30>/Store Start Time'
  real32_T Integrator_DSTATE;          // '<S127>/Integrator'
  real32_T Integrator_DSTATE_e;        // '<S74>/Integrator'
  real32_T Savedpitchinput_PreviousInput;// '<S26>/Saved pitch input'
  real32_T Savedyawinput_PreviousInput;// '<S28>/Saved yaw input'
  real32_T SavedThrustinput_PreviousInput;// '<S27>/Saved Thrust input'
  int8_T Integrator_PrevResetState;    // '<S127>/Integrator'
  int8_T Integrator_PrevResetState_k;  // '<S74>/Integrator'
  uint8_T Integrator_IC_LOADING;       // '<S127>/Integrator'
  uint8_T Integrator_IC_LOADING_p;     // '<S74>/Integrator'
  DW_PX4Timestamp_controller_T PX4Timestamp_n;// '<S32>/PX4 Timestamp'
  DW_PX4Timestamp_controller_T PX4Timestamp;// '<S32>/PX4 Timestamp'
  DW_PX4Timestamp_controller_T PX4Timestamp_h;// '<S32>/PX4 Timestamp'
};

// instance parameters, for system '<Root>'
struct InstP_controller_T {
  real_T dutch_roll_amp;               // Variable: dutch_roll_amp
                                          //  Referenced by: '<S146>/Doublet Generator'

  real_T dutch_roll_freq;              // Variable: dutch_roll_freq
                                          //  Referenced by: '<S146>/Doublet Generator'

  real_T phugoid_amp;                  // Variable: phugoid_amp
                                          //  Referenced by: '<S147>/Doublet Generator'

  real_T phugoid_freq;                 // Variable: phugoid_freq
                                          //  Referenced by: '<S147>/Doublet Generator'

  real_T short_period_amp;             // Variable: short_period_amp
                                          //  Referenced by: '<S148>/Doublet Generator'

  real_T short_period_freq;            // Variable: short_period_freq
                                          //  Referenced by: '<S148>/Doublet Generator'

  real32_T dutch_roll_dur;             // Variable: dutch_roll_dur
                                          //  Referenced by: '<S146>/Set time to re-allow  pilot inputs'

  real32_T dutch_roll_period;          // Variable: dutch_roll_period
                                          //  Referenced by: '<S146>/Switch1'

  real32_T phugoid_dur;                // Variable: phugoid_dur
                                          //  Referenced by: '<S147>/Set time to re-allow  pilot inputs'

  real32_T phugoid_period;             // Variable: phugoid_period
                                          //  Referenced by: '<S147>/Switch1'

  real32_T pitch_con_gain_i;           // Variable: pitch_con_gain_i
                                          //  Referenced by: '<S71>/Integral Gain'

  real32_T pitch_con_gain_p;           // Variable: pitch_con_gain_p
                                          //  Referenced by: '<S79>/Proportional Gain'

  real32_T short_period_dur;           // Variable: short_period_dur
                                          //  Referenced by: '<S148>/Set time to re-allow  pilot inputs'

  real32_T short_period_period;        // Variable: short_period_period
                                          //  Referenced by: '<S148>/Set end time of doublet'

  real32_T vel_con_gain_i;             // Variable: vel_con_gain_i
                                          //  Referenced by: '<S124>/Integral Gain'

  real32_T vel_con_gain_p;             // Variable: vel_con_gain_p
                                          //  Referenced by: '<S132>/Proportional Gain'

};

// Parameters (default storage)
struct P_controller_T_ {
  real32_T PIDController_Kb;           // Mask Parameter: PIDController_Kb
                                          //  Referenced by: '<S66>/Kb'

  real32_T PIDController_Kb_p;         // Mask Parameter: PIDController_Kb_p
                                          //  Referenced by: '<S119>/Kb'

  real32_T PIDController_LowerSaturationLi;
                              // Mask Parameter: PIDController_LowerSaturationLi
                                 //  Referenced by: '<S134>/Saturation'

  real32_T PIDController_LowerSaturation_m;
                              // Mask Parameter: PIDController_LowerSaturation_m
                                 //  Referenced by: '<S81>/Saturation'

  real32_T PIDController_UpperSaturationLi;
                              // Mask Parameter: PIDController_UpperSaturationLi
                                 //  Referenced by: '<S134>/Saturation'

  real32_T PIDController_UpperSaturation_d;
                              // Mask Parameter: PIDController_UpperSaturation_d
                                 //  Referenced by: '<S81>/Saturation'

  uint16_T CompareToConstant3_const; // Mask Parameter: CompareToConstant3_const
                                        //  Referenced by: '<S17>/Constant'

  px4_Bus_vehicle_odometry Out1_Y0;    // Computed Parameter: Out1_Y0
                                          //  Referenced by: '<S164>/Out1'

  px4_Bus_vehicle_odometry Constant_Value;// Computed Parameter: Constant_Value
                                             //  Referenced by: '<S163>/Constant'

  px4_Bus_input_rc Out1_Y0_a;          // Computed Parameter: Out1_Y0_a
                                          //  Referenced by: '<S152>/Out1'

  px4_Bus_input_rc Out1_Y0_i;          // Computed Parameter: Out1_Y0_i
                                          //  Referenced by: '<S162>/Out1'

  px4_Bus_input_rc Constant_Value_d;   // Computed Parameter: Constant_Value_d
                                          //  Referenced by: '<S161>/Constant'

  px4_Bus_input_rc Constant_Value_c;   // Computed Parameter: Constant_Value_c
                                          //  Referenced by: '<S151>/Constant'

  px4_Bus_flight_testing Constant_Value_cr;// Computed Parameter: Constant_Value_cr
                                              //  Referenced by: '<S154>/Constant'

  px4_Bus_system_identification Constant_Value_j;// Computed Parameter: Constant_Value_j
                                                    //  Referenced by: '<S157>/Constant'

  px4_Bus_sensor_accel Out1_Y0_k;      // Computed Parameter: Out1_Y0_k
                                          //  Referenced by: '<S7>/Out1'

  px4_Bus_sensor_accel Constant_Value_k;// Computed Parameter: Constant_Value_k
                                           //  Referenced by: '<S6>/Constant'

  px4_Bus_sensor_gyro Out1_Y0_e;       // Computed Parameter: Out1_Y0_e
                                          //  Referenced by: '<S160>/Out1'

  px4_Bus_sensor_gyro Constant_Value_m;// Computed Parameter: Constant_Value_m
                                          //  Referenced by: '<S159>/Constant'

  px4_Bus_glide_controller Constant_Value_d3;// Computed Parameter: Constant_Value_d3
                                                //  Referenced by: '<S37>/Constant'

  px4_Bus_airspeed Out1_Y0_io;         // Computed Parameter: Out1_Y0_io
                                          //  Referenced by: '<S150>/Out1'

  px4_Bus_airspeed Constant_Value_a;   // Computed Parameter: Constant_Value_a
                                          //  Referenced by: '<S149>/Constant'

  real_T Gain2_Gain;                   // Expression: 1/100
                                          //  Referenced by: '<S12>/Gain2'

  real_T Gain1_Gain;                   // Expression: 1/100
                                          //  Referenced by: '<S12>/Gain1'

  real_T Gain_Gain;                    // Expression: double(1/12.5)
                                          //  Referenced by: '<S12>/Gain'

  uint64_T StoreStartTime_InitialCondition;
                          // Computed Parameter: StoreStartTime_InitialCondition
                             //  Referenced by: '<S30>/Store Start Time'

  real32_T SpoilerRudderDeflectionValue_Va;
                          // Computed Parameter: SpoilerRudderDeflectionValue_Va
                             //  Referenced by: '<S23>/Spoiler Rudder Deflection Value'

  real32_T Gain1_Gain_o;               // Computed Parameter: Gain1_Gain_o
                                          //  Referenced by: '<S19>/Gain1'

  real32_T Switch_Threshold;           // Computed Parameter: Switch_Threshold
                                          //  Referenced by: '<S24>/Switch'

  real32_T Constant_Value_b;           // Computed Parameter: Constant_Value_b
                                          //  Referenced by: '<S24>/Constant'

  real32_T Switch2_Threshold;          // Computed Parameter: Switch2_Threshold
                                          //  Referenced by: '<S24>/Switch2'

  real32_T Switch3_Threshold;          // Computed Parameter: Switch3_Threshold
                                          //  Referenced by: '<S24>/Switch3'

  real32_T Integrator_gainval;         // Computed Parameter: Integrator_gainval
                                          //  Referenced by: '<S127>/Integrator'

  real32_T Switch_Threshold_k;         // Computed Parameter: Switch_Threshold_k
                                          //  Referenced by: '<S31>/Switch'

  real32_T Integrator_gainval_b;     // Computed Parameter: Integrator_gainval_b
                                        //  Referenced by: '<S74>/Integrator'

  real32_T Gain_Gain_p;                // Computed Parameter: Gain_Gain_p
                                          //  Referenced by: '<S31>/Gain'

  real32_T Gain_Gain_o;                // Computed Parameter: Gain_Gain_o
                                          //  Referenced by: '<S33>/Gain'

  real32_T Gain_Gain_m;                // Computed Parameter: Gain_Gain_m
                                          //  Referenced by: '<S34>/Gain'

  real32_T Switch1_Threshold;          // Computed Parameter: Switch1_Threshold
                                          //  Referenced by: '<S24>/Switch1'

  real32_T Constant7_Value;            // Computed Parameter: Constant7_Value
                                          //  Referenced by: '<S14>/Constant7'

  real32_T Constant6_Value;            // Computed Parameter: Constant6_Value
                                          //  Referenced by: '<S14>/Constant6'

  real32_T Saturation1_UpperSat;     // Computed Parameter: Saturation1_UpperSat
                                        //  Referenced by: '<S14>/Saturation1'

  real32_T Saturation1_LowerSat;     // Computed Parameter: Saturation1_LowerSat
                                        //  Referenced by: '<S14>/Saturation1'

  real32_T Switch4_Threshold;          // Computed Parameter: Switch4_Threshold
                                          //  Referenced by: '<S14>/Switch4'

  real32_T Saturation_UpperSat;       // Computed Parameter: Saturation_UpperSat
                                         //  Referenced by: '<S14>/Saturation'

  real32_T Saturation_LowerSat;       // Computed Parameter: Saturation_LowerSat
                                         //  Referenced by: '<S14>/Saturation'

  real32_T Saturation8_UpperSat;     // Computed Parameter: Saturation8_UpperSat
                                        //  Referenced by: '<S13>/Saturation8'

  real32_T Saturation8_LowerSat;     // Computed Parameter: Saturation8_LowerSat
                                        //  Referenced by: '<S13>/Saturation8'

  real32_T Savedpitchinput_InitialConditio;
                          // Computed Parameter: Savedpitchinput_InitialConditio
                             //  Referenced by: '<S26>/Saved pitch input'

  real32_T Checkforactivation_Threshold;
                             // Computed Parameter: Checkforactivation_Threshold
                                //  Referenced by: '<S26>/Check for activation'

  real32_T Saturation7_UpperSat;     // Computed Parameter: Saturation7_UpperSat
                                        //  Referenced by: '<S13>/Saturation7'

  real32_T Saturation7_LowerSat;     // Computed Parameter: Saturation7_LowerSat
                                        //  Referenced by: '<S13>/Saturation7'

  real32_T Savedyawinput_InitialCondition;
                           // Computed Parameter: Savedyawinput_InitialCondition
                              //  Referenced by: '<S28>/Saved yaw input'

  real32_T Checkforactivation_Threshold_d;
                           // Computed Parameter: Checkforactivation_Threshold_d
                              //  Referenced by: '<S28>/Check for activation'

  real32_T Saturation10_UpperSat;   // Computed Parameter: Saturation10_UpperSat
                                       //  Referenced by: '<S13>/Saturation10'

  real32_T Saturation10_LowerSat;   // Computed Parameter: Saturation10_LowerSat
                                       //  Referenced by: '<S13>/Saturation10'

  real32_T SavedThrustinput_InitialConditi;
                          // Computed Parameter: SavedThrustinput_InitialConditi
                             //  Referenced by: '<S27>/Saved Thrust input'

  real32_T Checkforactivation_Threshold_m;
                           // Computed Parameter: Checkforactivation_Threshold_m
                              //  Referenced by: '<S27>/Check for activation'

  real32_T Givestoredtimeinsteadofcurrentt;
                          // Computed Parameter: Givestoredtimeinsteadofcurrentt
                             //  Referenced by: '<S30>/Give stored time instead  of current time after activation'

  real32_T Converttimefromustos_Gain;
                                // Computed Parameter: Converttimefromustos_Gain
                                   //  Referenced by: '<S30>/Convert time from us to s'

  real32_T Pitchcontrolportion_Gain;
                                 // Computed Parameter: Pitchcontrolportion_Gain
                                    //  Referenced by: '<S22>/Pitch control portion'

  real32_T Saturation9_UpperSat;     // Computed Parameter: Saturation9_UpperSat
                                        //  Referenced by: '<S13>/Saturation9'

  real32_T Saturation9_LowerSat;     // Computed Parameter: Saturation9_LowerSat
                                        //  Referenced by: '<S13>/Saturation9'

  real32_T Gain_Gain_h;                // Computed Parameter: Gain_Gain_h
                                          //  Referenced by: '<S13>/Gain'

  real32_T Rollcontrolportion_Gain;
                                  // Computed Parameter: Rollcontrolportion_Gain
                                     //  Referenced by: '<S22>/Roll control portion'

  real32_T ControlAuthorityGain_Gain;
                                // Computed Parameter: ControlAuthorityGain_Gain
                                   //  Referenced by: '<S2>/Control Authority Gain'

  real32_T NoRudderDeflectionValue_Value;
                            // Computed Parameter: NoRudderDeflectionValue_Value
                               //  Referenced by: '<S23>/No Rudder Deflection Value'

  real32_T DeflectionLogicRudderRight_Thre;
                          // Computed Parameter: DeflectionLogicRudderRight_Thre
                             //  Referenced by: '<S23>/Deflection Logic Rudder Right'

  real32_T Saturation7_UpperSat_m; // Computed Parameter: Saturation7_UpperSat_m
                                      //  Referenced by: '<S14>/Saturation7'

  real32_T Saturation7_LowerSat_b; // Computed Parameter: Saturation7_LowerSat_b
                                      //  Referenced by: '<S14>/Saturation7'

  real32_T Switch_Threshold_j;         // Computed Parameter: Switch_Threshold_j
                                          //  Referenced by: '<S23>/Switch'

  real32_T ReverseforRudderLeft_Gain;
                                // Computed Parameter: ReverseforRudderLeft_Gain
                                   //  Referenced by: '<S23>/Reverse for Rudder Left'

  real32_T DeflectionLogicRudderLeft_Thres;
                          // Computed Parameter: DeflectionLogicRudderLeft_Thres
                             //  Referenced by: '<S23>/Deflection Logic Rudder Left'

  real32_T OutputLimitation_UpperSat;
                                // Computed Parameter: OutputLimitation_UpperSat
                                   //  Referenced by: '<S2>/Output Limitation'

  real32_T OutputLimitation_LowerSat;
                                // Computed Parameter: OutputLimitation_LowerSat
                                   //  Referenced by: '<S2>/Output Limitation'

  real32_T OutputLimitation2_UpperSat;
                               // Computed Parameter: OutputLimitation2_UpperSat
                                  //  Referenced by: '<S15>/Output Limitation2'

  real32_T OutputLimitation2_LowerSat;
                               // Computed Parameter: OutputLimitation2_LowerSat
                                  //  Referenced by: '<S15>/Output Limitation2'

  real32_T OutputLimitation3_UpperSat;
                               // Computed Parameter: OutputLimitation3_UpperSat
                                  //  Referenced by: '<S15>/Output Limitation3'

  real32_T OutputLimitation3_LowerSat;
                               // Computed Parameter: OutputLimitation3_LowerSat
                                  //  Referenced by: '<S15>/Output Limitation3'

  real32_T OutputLimitation1_UpperSat;
                               // Computed Parameter: OutputLimitation1_UpperSat
                                  //  Referenced by: '<S15>/Output Limitation1'

  real32_T OutputLimitation1_LowerSat;
                               // Computed Parameter: OutputLimitation1_LowerSat
                                  //  Referenced by: '<S15>/Output Limitation1'

  real32_T OutputLimitation_UpperSat_m;
                              // Computed Parameter: OutputLimitation_UpperSat_m
                                 //  Referenced by: '<S15>/Output Limitation'

  real32_T OutputLimitation_LowerSat_l;
                              // Computed Parameter: OutputLimitation_LowerSat_l
                                 //  Referenced by: '<S15>/Output Limitation'

  real32_T Gain1_Gain_a;               // Computed Parameter: Gain1_Gain_a
                                          //  Referenced by: '<S15>/Gain1'

  real32_T Gain_Gain_l;                // Computed Parameter: Gain_Gain_l
                                          //  Referenced by: '<S15>/Gain'

};

// Real-time Model Data Structure
struct tag_RTM_controller_T {
  const char_T * volatile errorStatus;
  const char_T* getErrorStatus() const;
  void setErrorStatus(const char_T* const volatile aErrorStatus);
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern P_controller_T controller_P;

#ifdef __cplusplus

}

#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_controller_T controller_B;

#ifdef __cplusplus

}

#endif

// Block states (default storage)
extern struct DW_controller_T controller_DW;

// instance parameters
extern InstP_controller_T controller_InstP;

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void controller_initialize(void);
  extern void controller_step(void);
  extern void controller_terminate(void);

#ifdef __cplusplus

}

#endif

// Real-time Model object
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_controller_T *const controller_M;

#ifdef __cplusplus

}

#endif

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S6>/NOT' : Unused code path elimination
//  Block '<S149>/NOT' : Unused code path elimination
//  Block '<S151>/NOT' : Unused code path elimination
//  Block '<S14>/Cast To Single2' : Unused code path elimination
//  Block '<S14>/Cast To Single3' : Unused code path elimination
//  Block '<S14>/Cast To Single4' : Unused code path elimination
//  Block '<S14>/Cast To Single5' : Unused code path elimination
//  Block '<S14>/Constant' : Unused code path elimination
//  Block '<S14>/Constant1' : Unused code path elimination
//  Block '<S14>/Constant2' : Unused code path elimination
//  Block '<S14>/Constant3' : Unused code path elimination
//  Block '<S14>/Constant4' : Unused code path elimination
//  Block '<S14>/Constant5' : Unused code path elimination
//  Block '<S14>/Fcn2' : Unused code path elimination
//  Block '<S14>/Fcn3' : Unused code path elimination
//  Block '<S14>/Fcn4' : Unused code path elimination
//  Block '<S14>/Fcn5' : Unused code path elimination
//  Block '<S14>/Saturation2' : Unused code path elimination
//  Block '<S14>/Saturation3' : Unused code path elimination
//  Block '<S14>/Saturation4' : Unused code path elimination
//  Block '<S14>/Saturation5' : Unused code path elimination
//  Block '<S14>/Switch' : Unused code path elimination
//  Block '<S14>/Switch1' : Unused code path elimination
//  Block '<S14>/Switch2' : Unused code path elimination
//  Block '<S14>/Switch3' : Unused code path elimination
//  Block '<S159>/NOT' : Unused code path elimination
//  Block '<S4>/Bitwise Operator' : Unused code path elimination
//  Block '<S4>/Data Type Conversion' : Unused code path elimination
//  Block '<S4>/Data Type Conversion1' : Unused code path elimination
//  Block '<S4>/Data Type Conversion2' : Unused code path elimination
//  Block '<S4>/Gain' : Unused code path elimination
//  Block '<S4>/Gain1' : Unused code path elimination
//  Block '<S161>/NOT' : Unused code path elimination
//  Block '<S4>/Signal Copy7' : Unused code path elimination
//  Block '<S163>/NOT' : Unused code path elimination
//  Block '<S5>/Signal Copy' : Unused code path elimination
//  Block '<S5>/Signal Copy1' : Unused code path elimination
//  Block '<S5>/Signal Copy2' : Unused code path elimination
//  Block '<S35>/Signal Conversion' : Eliminate redundant signal conversion block
//  Block '<S4>/Signal Copy' : Eliminate redundant signal conversion block
//  Block '<S4>/Signal Copy1' : Eliminate redundant signal conversion block
//  Block '<S4>/Signal Copy2' : Eliminate redundant signal conversion block
//  Block '<S4>/Signal Copy3' : Eliminate redundant signal conversion block
//  Block '<S4>/Signal Copy4' : Eliminate redundant signal conversion block
//  Block '<S4>/Signal Copy5' : Eliminate redundant signal conversion block
//  Block '<S4>/Signal Copy6' : Eliminate redundant signal conversion block


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
//  '<Root>' : 'controller'
//  '<S1>'   : 'controller/Accelerometer'
//  '<S2>'   : 'controller/Flight Controller'
//  '<S3>'   : 'controller/Gyroscope'
//  '<S4>'   : 'controller/Radio Control Transmitter'
//  '<S5>'   : 'controller/Vehicle Attitude'
//  '<S6>'   : 'controller/Accelerometer/PX4 uORB Read'
//  '<S7>'   : 'controller/Accelerometer/PX4 uORB Read/Enabled Subsystem'
//  '<S8>'   : 'controller/Flight Controller/ARMINGControl'
//  '<S9>'   : 'controller/Flight Controller/Control logic'
//  '<S10>'  : 'controller/Flight Controller/Get AIrpeed'
//  '<S11>'  : 'controller/Flight Controller/Get Additional RC Inputs'
//  '<S12>'  : 'controller/Flight Controller/Getting Parameters from PX4'
//  '<S13>'  : 'controller/Flight Controller/InputConditioning'
//  '<S14>'  : 'controller/Flight Controller/SwitchConditioning'
//  '<S15>'  : 'controller/Flight Controller/System Identification Logging'
//  '<S16>'  : 'controller/Flight Controller/quat2eul'
//  '<S17>'  : 'controller/Flight Controller/ARMINGControl/Compare To Constant3'
//  '<S18>'  : 'controller/Flight Controller/Control logic/Control Allocation'
//  '<S19>'  : 'controller/Flight Controller/Control logic/Degrees to Radians'
//  '<S20>'  : 'controller/Flight Controller/Control logic/Flight Testing'
//  '<S21>'  : 'controller/Flight Controller/Control logic/Control Allocation/Control Mixing'
//  '<S22>'  : 'controller/Flight Controller/Control logic/Control Allocation/Control Mixing/Control Surfaces Wing'
//  '<S23>'  : 'controller/Flight Controller/Control logic/Control Allocation/Control Mixing/Control Surfaces Winglet'
//  '<S24>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller'
//  '<S25>'  : 'controller/Flight Controller/Control logic/Flight Testing/Default Deflections'
//  '<S26>'  : 'controller/Flight Controller/Control logic/Flight Testing/Initial Pitch Input'
//  '<S27>'  : 'controller/Flight Controller/Control logic/Flight Testing/Initital Thrust Input'
//  '<S28>'  : 'controller/Flight Controller/Control logic/Flight Testing/Initital Yaw Input'
//  '<S29>'  : 'controller/Flight Controller/Control logic/Flight Testing/Mode Selection - SysID'
//  '<S30>'  : 'controller/Flight Controller/Control logic/Flight Testing/System Timer'
//  '<S31>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller'
//  '<S32>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/PX4 ULog'
//  '<S33>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Radians to Degrees'
//  '<S34>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Radians to Degrees1'
//  '<S35>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control'
//  '<S36>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller'
//  '<S37>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/PX4 ULog/PX4 uORB Message'
//  '<S38>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/PX4 ULog/PX4_log_write'
//  '<S39>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller'
//  '<S40>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Anti-windup'
//  '<S41>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/D Gain'
//  '<S42>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/External Derivative'
//  '<S43>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Filter'
//  '<S44>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Filter ICs'
//  '<S45>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/I Gain'
//  '<S46>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Ideal P Gain'
//  '<S47>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Ideal P Gain Fdbk'
//  '<S48>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Integrator'
//  '<S49>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Integrator ICs'
//  '<S50>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/N Copy'
//  '<S51>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/N Gain'
//  '<S52>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/P Copy'
//  '<S53>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Parallel P Gain'
//  '<S54>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Reset Signal'
//  '<S55>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Saturation'
//  '<S56>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Saturation Fdbk'
//  '<S57>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Sum'
//  '<S58>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Sum Fdbk'
//  '<S59>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Tracking Mode'
//  '<S60>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Tracking Mode Sum'
//  '<S61>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Tsamp - Integral'
//  '<S62>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Tsamp - Ngain'
//  '<S63>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/postSat Signal'
//  '<S64>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/preInt Signal'
//  '<S65>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/preSat Signal'
//  '<S66>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Anti-windup/Back Calculation'
//  '<S67>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/D Gain/Disabled'
//  '<S68>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/External Derivative/Disabled'
//  '<S69>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Filter/Disabled'
//  '<S70>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Filter ICs/Disabled'
//  '<S71>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/I Gain/Internal Parameters'
//  '<S72>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Ideal P Gain/Passthrough'
//  '<S73>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S74>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Integrator/Discrete'
//  '<S75>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Integrator ICs/External IC'
//  '<S76>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/N Copy/Disabled wSignal Specification'
//  '<S77>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/N Gain/Disabled'
//  '<S78>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/P Copy/Disabled'
//  '<S79>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Parallel P Gain/Internal Parameters'
//  '<S80>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Reset Signal/External Reset'
//  '<S81>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Saturation/Enabled'
//  '<S82>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Saturation Fdbk/Disabled'
//  '<S83>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Sum/Sum_PI'
//  '<S84>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Sum Fdbk/Disabled'
//  '<S85>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Tracking Mode/Disabled'
//  '<S86>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Tracking Mode Sum/Passthrough'
//  '<S87>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Tsamp - Integral/TsSignalSpecification'
//  '<S88>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Tsamp - Ngain/Passthrough'
//  '<S89>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/postSat Signal/Forward_Path'
//  '<S90>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/preInt Signal/Internal PreInt'
//  '<S91>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/preSat Signal/Forward_Path'
//  '<S92>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller'
//  '<S93>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/Anti-windup'
//  '<S94>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/D Gain'
//  '<S95>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/External Derivative'
//  '<S96>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/Filter'
//  '<S97>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/Filter ICs'
//  '<S98>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/I Gain'
//  '<S99>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/Ideal P Gain'
//  '<S100>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/Ideal P Gain Fdbk'
//  '<S101>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/Integrator'
//  '<S102>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/Integrator ICs'
//  '<S103>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/N Copy'
//  '<S104>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/N Gain'
//  '<S105>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/P Copy'
//  '<S106>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/Parallel P Gain'
//  '<S107>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/Reset Signal'
//  '<S108>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/Saturation'
//  '<S109>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/Saturation Fdbk'
//  '<S110>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/Sum'
//  '<S111>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/Sum Fdbk'
//  '<S112>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/Tracking Mode'
//  '<S113>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/Tracking Mode Sum'
//  '<S114>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/Tsamp - Integral'
//  '<S115>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/Tsamp - Ngain'
//  '<S116>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/postSat Signal'
//  '<S117>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/preInt Signal'
//  '<S118>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/preSat Signal'
//  '<S119>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/Anti-windup/Back Calculation'
//  '<S120>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/D Gain/Disabled'
//  '<S121>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/External Derivative/Disabled'
//  '<S122>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/Filter/Disabled'
//  '<S123>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/Filter ICs/Disabled'
//  '<S124>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/I Gain/Internal Parameters'
//  '<S125>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/Ideal P Gain/Passthrough'
//  '<S126>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S127>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/Integrator/Discrete'
//  '<S128>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/Integrator ICs/External IC'
//  '<S129>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/N Copy/Disabled wSignal Specification'
//  '<S130>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/N Gain/Disabled'
//  '<S131>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/P Copy/Disabled'
//  '<S132>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/Parallel P Gain/Internal Parameters'
//  '<S133>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/Reset Signal/External Reset'
//  '<S134>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/Saturation/Enabled'
//  '<S135>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/Saturation Fdbk/Disabled'
//  '<S136>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/Sum/Sum_PI'
//  '<S137>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/Sum Fdbk/Disabled'
//  '<S138>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/Tracking Mode/Disabled'
//  '<S139>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/Tracking Mode Sum/Passthrough'
//  '<S140>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/Tsamp - Integral/TsSignalSpecification'
//  '<S141>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/Tsamp - Ngain/Passthrough'
//  '<S142>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/postSat Signal/Forward_Path'
//  '<S143>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/preInt Signal/Internal PreInt'
//  '<S144>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/preSat Signal/Forward_Path'
//  '<S145>' : 'controller/Flight Controller/Control logic/Flight Testing/Mode Selection - SysID/Default Deflections'
//  '<S146>' : 'controller/Flight Controller/Control logic/Flight Testing/Mode Selection - SysID/Dutch Roll Doublet'
//  '<S147>' : 'controller/Flight Controller/Control logic/Flight Testing/Mode Selection - SysID/Phugoid Doublet'
//  '<S148>' : 'controller/Flight Controller/Control logic/Flight Testing/Mode Selection - SysID/Short Period Doublet'
//  '<S149>' : 'controller/Flight Controller/Get AIrpeed/PX4 uORB Read2'
//  '<S150>' : 'controller/Flight Controller/Get AIrpeed/PX4 uORB Read2/Enabled Subsystem'
//  '<S151>' : 'controller/Flight Controller/Get Additional RC Inputs/PX4 uORB Read1'
//  '<S152>' : 'controller/Flight Controller/Get Additional RC Inputs/PX4 uORB Read1/Enabled Subsystem'
//  '<S153>' : 'controller/Flight Controller/Getting Parameters from PX4/PX4 ULog'
//  '<S154>' : 'controller/Flight Controller/Getting Parameters from PX4/PX4 ULog/PX4 uORB Message'
//  '<S155>' : 'controller/Flight Controller/Getting Parameters from PX4/PX4 ULog/PX4_log_write'
//  '<S156>' : 'controller/Flight Controller/System Identification Logging/PX4 ULog'
//  '<S157>' : 'controller/Flight Controller/System Identification Logging/PX4 ULog/PX4 uORB Message'
//  '<S158>' : 'controller/Flight Controller/System Identification Logging/PX4 ULog/PX4_log_write'
//  '<S159>' : 'controller/Gyroscope/PX4 uORB Read'
//  '<S160>' : 'controller/Gyroscope/PX4 uORB Read/Enabled Subsystem'
//  '<S161>' : 'controller/Radio Control Transmitter/PX4 uORB Read'
//  '<S162>' : 'controller/Radio Control Transmitter/PX4 uORB Read/Enabled Subsystem'
//  '<S163>' : 'controller/Vehicle Attitude/PX4 uORB Read'
//  '<S164>' : 'controller/Vehicle Attitude/PX4 uORB Read/Enabled Subsystem'

#endif                                 // controller_h_

//
// File trailer for generated code.
//
// [EOF]
//
