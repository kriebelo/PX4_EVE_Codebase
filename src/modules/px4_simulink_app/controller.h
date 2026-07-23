//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: controller.h
//
// Code generated for Simulink model 'controller'.
//
// Model version                  : 1.137
// Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
// C/C++ source code generated on : Thu Jul 23 11:45:57 2026
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
#include <uORB/topics/flight_testing.h>
#include <uORB/topics/input_rc.h>
#include <uORB/topics/system_identification.h>
#include <uORB/topics/sensor_accel.h>
#include <uORB/topics/sensor_gyro.h>
#include <uORB/topics/glide_controller.h>
#include <uORB/topics/airspeed.h>
#include <uORB/topics/velocity_filter.h>

extern "C"
{

#include "rt_nonfinite.h"

}

extern "C"
{

#include "rtGetNaN.h"

}

#include <stddef.h>

// Block signals for system '<S31>/PX4 Timestamp'
struct B_PX4Timestamp_controller_T {
  uint64_T PX4Timestamp;               // '<S31>/PX4 Timestamp'
};

// Block states (default storage) for system '<S31>/PX4 Timestamp'
struct DW_PX4Timestamp_controller_T {
  px4_internal_block_getPX4Abso_T obj; // '<S31>/PX4 Timestamp'
  boolean_T objisempty;                // '<S31>/PX4 Timestamp'
};

// Block signals (default storage)
struct B_controller_T {
  px4_Bus_vehicle_odometry In1;        // '<S167>/In1'
  px4_Bus_vehicle_odometry r;
  px4_Bus_flight_testing BusAssignment;// '<S156>/Bus Assignment'
  px4_Bus_input_rc In1_d;              // '<S165>/In1'
  px4_Bus_input_rc r1;
  px4_Bus_system_identification BusAssignment_c;// '<S159>/Bus Assignment'
  real32_T motorValues[12];
  real32_T motorValues_m[12];
  px4_Bus_sensor_accel r2;
  px4_Bus_sensor_gyro In1_k;           // '<S163>/In1'
  px4_Bus_sensor_gyro r3;
  px4_Bus_glide_controller BusAssignment_k;// '<S31>/Bus Assignment'
  real32_T servoValues[8];
  px4_Bus_airspeed In1_m;              // '<S155>/In1'
  px4_Bus_airspeed r4;
  px4_Bus_velocity_filter BusAssignment_b;// '<S92>/Bus Assignment'
  real_T Gain3;                        // '<S11>/Gain3'
  real_T Gain2_g;                      // '<S149>/Gain2'
  uint64_T rtb_PX4Timestamp_c;
  real32_T ParamStep;
  real32_T ParamStep_k;
  real32_T ParamStep_c;
  real32_T ParamStep_b;
  real32_T ParamStep_p;
  real32_T ParamStep_cv;
  real32_T ParamStep_f;
  real32_T ParamStep_g;
  real32_T ActivationFlag;             // '<S13>/Saturation1'
  int32_T ParamStep_g1;
  B_PX4Timestamp_controller_T PX4Timestamp_n;// '<S31>/PX4 Timestamp'
  B_PX4Timestamp_controller_T PX4Timestamp;// '<S31>/PX4 Timestamp'
  B_PX4Timestamp_controller_T PX4Timestamp_h;// '<S31>/PX4 Timestamp'
  B_PX4Timestamp_controller_T PX4Timestamp_o;// '<S31>/PX4 Timestamp'
};

// Block states (default storage) for system '<Root>'
struct DW_controller_T {
  px4_internal_block_PX4Actuato_T obj; // '<Root>/PX4 Actuator Write'
  px4_internal_block_Subscriber_T obj_l;// '<S166>/SourceBlock'
  px4_internal_block_Subscriber_T obj_d;// '<S164>/SourceBlock'
  px4_internal_block_Subscriber_T obj_o;// '<S162>/SourceBlock'
  px4_internal_block_Subscriber_T obj_m;// '<S154>/SourceBlock'
  px4_internal_block_Subscriber_T obj_og;// '<S6>/SourceBlock'
  px4_internal_block_getPX4Abso_T obj_h;// '<Root>/PX4 Timestamp'
  px4_internal_block_Publisher__T obj_md;// '<S161>/SinkBlock'
  px4_internal_block_Publisher__T obj_g;// '<S158>/SinkBlock'
  px4_internal_block_Publisher__T obj_b;// '<S146>/SinkBlock'
  px4_internal_block_Publisher__T obj_mu;// '<S37>/SinkBlock'
  px4_internal_block_ParameterU_T obj_ms;// '<S13>/Read Parameter2'
  px4_internal_block_ParameterU_T obj_k;// '<S13>/Read Parameter1'
  px4_internal_block_ParameterU_T obj_n;// '<S13>/Read Parameter'
  px4_internal_block_ParameterU_T obj_mf;// '<S11>/Read Parameter9'
  px4_internal_block_ParameterU_T obj_p;// '<S11>/Read Parameter8'
  px4_internal_block_ParameterU_T obj_l1;// '<S11>/Read Parameter7'
  px4_internal_block_ParameterU_T obj_pe;// '<S11>/Read Parameter6'
  px4_internal_block_ParameterU_T obj_o5;// '<S11>/Read Parameter5'
  px4_internal_block_ParameterU_T obj_e;// '<S11>/Read Parameter4'
  px4_internal_block_ParameterU_T obj_f;// '<S11>/Read Parameter3'
  px4_internal_block_ParameterU_T obj_hd;// '<S11>/Read Parameter20'
  px4_internal_block_ParameterU_T obj_j;// '<S11>/Read Parameter2'
  px4_internal_block_ParameterU_T obj_hl;// '<S11>/Read Parameter19'
  px4_internal_block_ParameterU_T obj_jt;// '<S11>/Read Parameter18'
  px4_internal_block_ParameterU_T obj_a;// '<S11>/Read Parameter17'
  px4_internal_block_ParameterU_T obj_i;// '<S11>/Read Parameter16'
  px4_internal_block_ParameterU_T obj_lg;// '<S11>/Read Parameter15'
  px4_internal_block_ParameterU_T obj_lx;// '<S11>/Read Parameter14'
  px4_internal_block_ParameterU_T obj_lp;// '<S11>/Read Parameter13'
  px4_internal_block_ParameterU_T obj_gx;// '<S11>/Read Parameter12'
  px4_internal_block_ParameterU_T obj_i4;// '<S11>/Read Parameter11'
  px4_internal_block_ParameterU_T obj_bg;// '<S11>/Read Parameter10'
  px4_internal_block_ParameterU_T obj_ah;// '<S11>/Read Parameter1'
  px4_internal_block_ParameterU_T obj_ng;// '<S11>/Read Parameter'
  uint64_T StoreStartTime_PreviousInput;// '<S29>/Store Start Time'
  real32_T DiscreteFilter1_states;     // '<S35>/Discrete Filter1'
  real32_T Integrator_DSTATE;          // '<S127>/Integrator'
  real32_T Integrator_DSTATE_a;        // '<S73>/Integrator'
  real32_T Savedpitchinput_PreviousInput;// '<S25>/Saved pitch input'
  real32_T SavedThrustinput_PreviousInput;// '<S26>/Saved Thrust input'
  real32_T Savedyawinput_PreviousInput;// '<S27>/Saved yaw input'
  int8_T Integrator_PrevResetState;    // '<S127>/Integrator'
  int8_T Integrator_PrevResetState_f;  // '<S73>/Integrator'
  uint8_T Integrator_IC_LOADING;       // '<S127>/Integrator'
  uint8_T Integrator_IC_LOADING_e;     // '<S73>/Integrator'
  DW_PX4Timestamp_controller_T PX4Timestamp_n;// '<S31>/PX4 Timestamp'
  DW_PX4Timestamp_controller_T PX4Timestamp;// '<S31>/PX4 Timestamp'
  DW_PX4Timestamp_controller_T PX4Timestamp_h;// '<S31>/PX4 Timestamp'
  DW_PX4Timestamp_controller_T PX4Timestamp_o;// '<S31>/PX4 Timestamp'
};

// instance parameters, for system '<Root>'
struct InstP_controller_T {
  real_T dutch_roll_amp;               // Variable: dutch_roll_amp
                                          //  Referenced by: '<S148>/Doublet Generator'

  real_T dutch_roll_diff_thrust_amp;   // Variable: dutch_roll_diff_thrust_amp
                                          //  Referenced by: '<S149>/Gain2'

  real_T dutch_roll_freq;              // Variable: dutch_roll_freq
                                          //  Referenced by: '<S148>/Doublet Generator'

  real_T phugoid_amp;                  // Variable: phugoid_amp
                                          //  Referenced by: '<S150>/Doublet Generator'

  real_T phugoid_freq;                 // Variable: phugoid_freq
                                          //  Referenced by: '<S150>/Doublet Generator'

  real_T short_period_amp;             // Variable: short_period_amp
                                          //  Referenced by: '<S151>/Doublet Generator'

  real_T short_period_freq;            // Variable: short_period_freq
                                          //  Referenced by: '<S151>/Doublet Generator'

  real_T short_period_sweep_freq_max;  // Variable: short_period_sweep_freq_max
                                          //  Referenced by: '<S153>/Constant2'

  real_T short_period_sweep_freq_min;  // Variable: short_period_sweep_freq_min
                                          //  Referenced by: '<S153>/Constant3'

  real32_T dutch_roll_diff_thrust_period;
                                      // Variable: dutch_roll_diff_thrust_period
                                         //  Referenced by:
                                         //    '<S149>/Switch'
                                         //    '<S149>/Switch1'
                                         //    '<S149>/Switch2'
                                         //    '<S149>/Switch3'
                                         //    '<S149>/Switch5'

  real32_T dutch_roll_dur;             // Variable: dutch_roll_dur
                                          //  Referenced by: '<S148>/Set time to re-allow  pilot inputs'

  real32_T dutch_roll_period;          // Variable: dutch_roll_period
                                          //  Referenced by: '<S148>/Switch1'

  real32_T phugoid_dur;                // Variable: phugoid_dur
                                          //  Referenced by: '<S150>/Set time to re-allow  pilot inputs'

  real32_T phugoid_period;             // Variable: phugoid_period
                                          //  Referenced by: '<S150>/Switch1'

  real32_T pitch_con_gain_i;           // Variable: pitch_con_gain_i
                                          //  Referenced by: '<S70>/Integral Gain'

  real32_T pitch_con_gain_p;           // Variable: pitch_con_gain_p
                                          //  Referenced by: '<S78>/Proportional Gain'

  real32_T short_period_dur;           // Variable: short_period_dur
                                          //  Referenced by: '<S151>/Set time to re-allow  pilot inputs'

  real32_T short_period_period;        // Variable: short_period_period
                                          //  Referenced by: '<S151>/Set end time of doublet'

  real32_T short_period_sweep_amp;     // Variable: short_period_sweep_amp
                                          //  Referenced by: '<S152>/Gain'

  real32_T vel_con_gain_i;             // Variable: vel_con_gain_i
                                          //  Referenced by: '<S124>/Integral Gain'

  real32_T vel_con_gain_p;             // Variable: vel_con_gain_p
                                          //  Referenced by: '<S132>/Proportional Gain'

  real32_T vel_lp_freq;                // Variable: vel_lp_freq
                                          //  Referenced by: '<S35>/Constant'

};

// Parameters (default storage)
struct P_controller_T_ {
  real32_T PIDController_Kb;           // Mask Parameter: PIDController_Kb
                                          //  Referenced by: '<S65>/Kb'

  real32_T PIDController_Kb_c;         // Mask Parameter: PIDController_Kb_c
                                          //  Referenced by: '<S119>/Kb'

  real32_T PIDController_LowerSaturationLi;
                              // Mask Parameter: PIDController_LowerSaturationLi
                                 //  Referenced by: '<S134>/Saturation'

  real32_T PIDController_LowerSaturation_m;
                              // Mask Parameter: PIDController_LowerSaturation_m
                                 //  Referenced by: '<S80>/Saturation'

  real32_T PIDController_UpperSaturationLi;
                              // Mask Parameter: PIDController_UpperSaturationLi
                                 //  Referenced by: '<S134>/Saturation'

  real32_T PIDController_UpperSaturation_o;
                              // Mask Parameter: PIDController_UpperSaturation_o
                                 //  Referenced by: '<S80>/Saturation'

  uint16_T CompareToConstant3_const; // Mask Parameter: CompareToConstant3_const
                                        //  Referenced by: '<S16>/Constant'

  px4_Bus_vehicle_odometry Out1_Y0;    // Computed Parameter: Out1_Y0
                                          //  Referenced by: '<S167>/Out1'

  px4_Bus_vehicle_odometry Constant_Value;// Computed Parameter: Constant_Value
                                             //  Referenced by: '<S166>/Constant'

  px4_Bus_flight_testing Constant_Value_e;// Computed Parameter: Constant_Value_e
                                             //  Referenced by: '<S157>/Constant'

  px4_Bus_input_rc Out1_Y0_i;          // Computed Parameter: Out1_Y0_i
                                          //  Referenced by: '<S165>/Out1'

  px4_Bus_input_rc Constant_Value_d;   // Computed Parameter: Constant_Value_d
                                          //  Referenced by: '<S164>/Constant'

  px4_Bus_system_identification Constant_Value_j;// Computed Parameter: Constant_Value_j
                                                    //  Referenced by: '<S160>/Constant'

  px4_Bus_sensor_accel Out1_Y0_k;      // Computed Parameter: Out1_Y0_k
                                          //  Referenced by: '<S7>/Out1'

  px4_Bus_sensor_accel Constant_Value_k;// Computed Parameter: Constant_Value_k
                                           //  Referenced by: '<S6>/Constant'

  px4_Bus_sensor_gyro Out1_Y0_e;       // Computed Parameter: Out1_Y0_e
                                          //  Referenced by: '<S163>/Out1'

  px4_Bus_sensor_gyro Constant_Value_m;// Computed Parameter: Constant_Value_m
                                          //  Referenced by: '<S162>/Constant'

  px4_Bus_glide_controller Constant_Value_p;// Computed Parameter: Constant_Value_p
                                               //  Referenced by: '<S36>/Constant'

  px4_Bus_airspeed Out1_Y0_io;         // Computed Parameter: Out1_Y0_io
                                          //  Referenced by: '<S155>/Out1'

  px4_Bus_airspeed Constant_Value_a;   // Computed Parameter: Constant_Value_a
                                          //  Referenced by: '<S154>/Constant'

  px4_Bus_velocity_filter Constant_Value_b;// Computed Parameter: Constant_Value_b
                                              //  Referenced by: '<S145>/Constant'

  real_T Constant_Value_l;             // Expression: short_period_sweep_dur
                                          //  Referenced by: '<S153>/Constant'

  real_T Constant1_Value;              // Expression: 0.5
                                          //  Referenced by: '<S153>/Constant1'

  real_T Gain1_Gain;                   // Expression: 1
                                          //  Referenced by: '<S149>/Gain1'

  real_T Gain_Gain;                    // Expression: -1
                                          //  Referenced by: '<S149>/Gain'

  real_T Constant3_Value;              // Expression: 0
                                          //  Referenced by: '<S149>/Constant3'

  real_T Constant1_Value_i;            // Expression: -1
                                          //  Referenced by: '<S149>/Constant1'

  real_T Constant_Value_o;             // Expression: 1
                                          //  Referenced by: '<S149>/Constant'

  real_T Gain2_Gain;                   // Expression: 1/100
                                          //  Referenced by: '<S11>/Gain2'

  real_T Gain1_Gain_d;                 // Expression: 1/100
                                          //  Referenced by: '<S11>/Gain1'

  real_T Gain4_Gain;                   // Expression: double(1/100)
                                          //  Referenced by: '<S11>/Gain4'

  real_T Gain_Gain_a;                  // Expression: double(1/12.5)
                                          //  Referenced by: '<S11>/Gain'

  real_T Gain3_Gain;                   // Expression: double(1/12.5)
                                          //  Referenced by: '<S11>/Gain3'

  uint64_T StoreStartTime_InitialCondition;
                          // Computed Parameter: StoreStartTime_InitialCondition
                             //  Referenced by: '<S29>/Store Start Time'

  real32_T SpoilerRudderDeflectionValue_Va;
                          // Computed Parameter: SpoilerRudderDeflectionValue_Va
                             //  Referenced by: '<S22>/Spoiler Rudder Deflection Value'

  real32_T Gain1_Gain_o;               // Computed Parameter: Gain1_Gain_o
                                          //  Referenced by: '<S153>/Gain1'

  real32_T Setendtimeofdoublet_Threshold;// Expression: short_period_sweep_dur
                                            //  Referenced by: '<S152>/Set end time of doublet'

  real32_T Gain3_Gain_n;               // Computed Parameter: Gain3_Gain_n
                                          //  Referenced by: '<S149>/Gain3'

  real32_T Gain4_Gain_m;               // Computed Parameter: Gain4_Gain_m
                                          //  Referenced by: '<S149>/Gain4'

  real32_T Gain5_Gain;                 // Computed Parameter: Gain5_Gain
                                          //  Referenced by: '<S149>/Gain5'

  real32_T Gain6_Gain;                 // Computed Parameter: Gain6_Gain
                                          //  Referenced by: '<S149>/Gain6'

  real32_T Gain7_Gain;                 // Computed Parameter: Gain7_Gain
                                          //  Referenced by: '<S149>/Gain7'

  real32_T Merge2_InitialOutput;     // Computed Parameter: Merge2_InitialOutput
                                        //  Referenced by: '<S28>/Merge2'

  real32_T Gain1_Gain_g;               // Computed Parameter: Gain1_Gain_g
                                          //  Referenced by: '<S18>/Gain1'

  real32_T Switch_Threshold;           // Computed Parameter: Switch_Threshold
                                          //  Referenced by: '<S23>/Switch'

  real32_T Constant_Value_k2;          // Computed Parameter: Constant_Value_k2
                                          //  Referenced by: '<S23>/Constant'

  real32_T Switch2_Threshold;          // Computed Parameter: Switch2_Threshold
                                          //  Referenced by: '<S23>/Switch2'

  real32_T Switch3_Threshold;          // Computed Parameter: Switch3_Threshold
                                          //  Referenced by: '<S23>/Switch3'

  real32_T Constant1_Value_ii;         // Computed Parameter: Constant1_Value_ii
                                          //  Referenced by: '<S35>/Constant1'

  real32_T Gain_Gain_m;                // Computed Parameter: Gain_Gain_m
                                          //  Referenced by: '<S35>/Gain'

  real32_T Constant2_Value;            // Computed Parameter: Constant2_Value
                                          //  Referenced by: '<S35>/Constant2'

  real32_T Bias_Bias;                  // Computed Parameter: Bias_Bias
                                          //  Referenced by: '<S35>/Bias'

  real32_T DiscreteFilter1_InitialStates;
                            // Computed Parameter: DiscreteFilter1_InitialStates
                               //  Referenced by: '<S35>/Discrete Filter1'

  real32_T Integrator_gainval;         // Computed Parameter: Integrator_gainval
                                          //  Referenced by: '<S127>/Integrator'

  real32_T Switch_Threshold_e;         // Computed Parameter: Switch_Threshold_e
                                          //  Referenced by: '<S30>/Switch'

  real32_T Integrator_gainval_i;     // Computed Parameter: Integrator_gainval_i
                                        //  Referenced by: '<S73>/Integrator'

  real32_T Gain_Gain_mm;               // Computed Parameter: Gain_Gain_mm
                                          //  Referenced by: '<S30>/Gain'

  real32_T Gain_Gain_i;                // Computed Parameter: Gain_Gain_i
                                          //  Referenced by: '<S32>/Gain'

  real32_T Gain_Gain_ax;               // Computed Parameter: Gain_Gain_ax
                                          //  Referenced by: '<S33>/Gain'

  real32_T Switch1_Threshold;          // Computed Parameter: Switch1_Threshold
                                          //  Referenced by: '<S23>/Switch1'

  real32_T Saturation1_UpperSat;     // Computed Parameter: Saturation1_UpperSat
                                        //  Referenced by: '<S13>/Saturation1'

  real32_T Saturation1_LowerSat;     // Computed Parameter: Saturation1_LowerSat
                                        //  Referenced by: '<S13>/Saturation1'

  real32_T Savedpitchinput_InitialConditio;
                          // Computed Parameter: Savedpitchinput_InitialConditio
                             //  Referenced by: '<S25>/Saved pitch input'

  real32_T Saturation8_UpperSat;     // Computed Parameter: Saturation8_UpperSat
                                        //  Referenced by: '<S12>/Saturation8'

  real32_T Saturation8_LowerSat;     // Computed Parameter: Saturation8_LowerSat
                                        //  Referenced by: '<S12>/Saturation8'

  real32_T Checkforactivation_Threshold;
                             // Computed Parameter: Checkforactivation_Threshold
                                //  Referenced by: '<S25>/Check for activation'

  real32_T Constant6_Value;            // Computed Parameter: Constant6_Value
                                          //  Referenced by: '<S13>/Constant6'

  real32_T Saturation10_UpperSat;   // Computed Parameter: Saturation10_UpperSat
                                       //  Referenced by: '<S12>/Saturation10'

  real32_T Saturation10_LowerSat;   // Computed Parameter: Saturation10_LowerSat
                                       //  Referenced by: '<S12>/Saturation10'

  real32_T SavedThrustinput_InitialConditi;
                          // Computed Parameter: SavedThrustinput_InitialConditi
                             //  Referenced by: '<S26>/Saved Thrust input'

  real32_T Checkforactivation_Threshold_a;
                           // Computed Parameter: Checkforactivation_Threshold_a
                              //  Referenced by: '<S26>/Check for activation'

  real32_T Saturation7_UpperSat;     // Computed Parameter: Saturation7_UpperSat
                                        //  Referenced by: '<S12>/Saturation7'

  real32_T Saturation7_LowerSat;     // Computed Parameter: Saturation7_LowerSat
                                        //  Referenced by: '<S12>/Saturation7'

  real32_T Savedyawinput_InitialCondition;
                           // Computed Parameter: Savedyawinput_InitialCondition
                              //  Referenced by: '<S27>/Saved yaw input'

  real32_T Checkforactivation_Threshold_g;
                           // Computed Parameter: Checkforactivation_Threshold_g
                              //  Referenced by: '<S27>/Check for activation'

  real32_T Givestoredtimeinsteadofcurrentt;
                          // Computed Parameter: Givestoredtimeinsteadofcurrentt
                             //  Referenced by: '<S29>/Give stored time instead  of current time after activation'

  real32_T Converttimefromustos_Gain;
                                // Computed Parameter: Converttimefromustos_Gain
                                   //  Referenced by: '<S29>/Convert time from us to s'

  real32_T Pitchcontrolportion_Gain;
                                 // Computed Parameter: Pitchcontrolportion_Gain
                                    //  Referenced by: '<S21>/Pitch control portion'

  real32_T Saturation9_UpperSat;     // Computed Parameter: Saturation9_UpperSat
                                        //  Referenced by: '<S12>/Saturation9'

  real32_T Saturation9_LowerSat;     // Computed Parameter: Saturation9_LowerSat
                                        //  Referenced by: '<S12>/Saturation9'

  real32_T Gain_Gain_h;                // Computed Parameter: Gain_Gain_h
                                          //  Referenced by: '<S12>/Gain'

  real32_T Rollcontrolportion_Gain;
                                  // Computed Parameter: Rollcontrolportion_Gain
                                     //  Referenced by: '<S21>/Roll control portion'

  real32_T ControlAuthorityGain_Gain;
                                // Computed Parameter: ControlAuthorityGain_Gain
                                   //  Referenced by: '<S2>/Control Authority Gain'

  real32_T NoRudderDeflectionValue_Value;
                            // Computed Parameter: NoRudderDeflectionValue_Value
                               //  Referenced by: '<S22>/No Rudder Deflection Value'

  real32_T DeflectionLogicRudderRight_Thre;
                          // Computed Parameter: DeflectionLogicRudderRight_Thre
                             //  Referenced by: '<S22>/Deflection Logic Rudder Right'

  real32_T Saturation7_UpperSat_m; // Computed Parameter: Saturation7_UpperSat_m
                                      //  Referenced by: '<S13>/Saturation7'

  real32_T Saturation7_LowerSat_b; // Computed Parameter: Saturation7_LowerSat_b
                                      //  Referenced by: '<S13>/Saturation7'

  real32_T Switch_Threshold_n;         // Computed Parameter: Switch_Threshold_n
                                          //  Referenced by: '<S22>/Switch'

  real32_T ReverseforRudderLeft_Gain;
                                // Computed Parameter: ReverseforRudderLeft_Gain
                                   //  Referenced by: '<S22>/Reverse for Rudder Left'

  real32_T DeflectionLogicRudderLeft_Thres;
                          // Computed Parameter: DeflectionLogicRudderLeft_Thres
                             //  Referenced by: '<S22>/Deflection Logic Rudder Left'

  real32_T OutputLimitation_UpperSat;
                                // Computed Parameter: OutputLimitation_UpperSat
                                   //  Referenced by: '<S2>/Output Limitation'

  real32_T OutputLimitation_LowerSat;
                                // Computed Parameter: OutputLimitation_LowerSat
                                   //  Referenced by: '<S2>/Output Limitation'

  real32_T OutputLimitation2_UpperSat;
                               // Computed Parameter: OutputLimitation2_UpperSat
                                  //  Referenced by: '<S14>/Output Limitation2'

  real32_T OutputLimitation2_LowerSat;
                               // Computed Parameter: OutputLimitation2_LowerSat
                                  //  Referenced by: '<S14>/Output Limitation2'

  real32_T OutputLimitation3_UpperSat;
                               // Computed Parameter: OutputLimitation3_UpperSat
                                  //  Referenced by: '<S14>/Output Limitation3'

  real32_T OutputLimitation3_LowerSat;
                               // Computed Parameter: OutputLimitation3_LowerSat
                                  //  Referenced by: '<S14>/Output Limitation3'

  real32_T OutputLimitation1_UpperSat;
                               // Computed Parameter: OutputLimitation1_UpperSat
                                  //  Referenced by: '<S14>/Output Limitation1'

  real32_T OutputLimitation1_LowerSat;
                               // Computed Parameter: OutputLimitation1_LowerSat
                                  //  Referenced by: '<S14>/Output Limitation1'

  real32_T OutputLimitation_UpperSat_m;
                              // Computed Parameter: OutputLimitation_UpperSat_m
                                 //  Referenced by: '<S14>/Output Limitation'

  real32_T OutputLimitation_LowerSat_l;
                              // Computed Parameter: OutputLimitation_LowerSat_l
                                 //  Referenced by: '<S14>/Output Limitation'

  real32_T Gain1_Gain_a;               // Computed Parameter: Gain1_Gain_a
                                          //  Referenced by: '<S14>/Gain1'

  real32_T Gain_Gain_l;                // Computed Parameter: Gain_Gain_l
                                          //  Referenced by: '<S14>/Gain'

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
//  Block '<S154>/NOT' : Unused code path elimination
//  Block '<S162>/NOT' : Unused code path elimination
//  Block '<S4>/Bitwise Operator' : Unused code path elimination
//  Block '<S4>/Data Type Conversion' : Unused code path elimination
//  Block '<S4>/Data Type Conversion1' : Unused code path elimination
//  Block '<S4>/Data Type Conversion2' : Unused code path elimination
//  Block '<S4>/Gain' : Unused code path elimination
//  Block '<S4>/Gain1' : Unused code path elimination
//  Block '<S164>/NOT' : Unused code path elimination
//  Block '<S4>/Signal Copy7' : Unused code path elimination
//  Block '<S166>/NOT' : Unused code path elimination
//  Block '<S5>/Signal Copy' : Unused code path elimination
//  Block '<S5>/Signal Copy1' : Unused code path elimination
//  Block '<S5>/Signal Copy2' : Unused code path elimination
//  Block '<S34>/Signal Conversion' : Eliminate redundant signal conversion block
//  Block '<S150>/Cast To Single1' : Eliminate redundant data type conversion
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
//  '<S10>'  : 'controller/Flight Controller/Get Airspeed'
//  '<S11>'  : 'controller/Flight Controller/Getting Parameters from PX4'
//  '<S12>'  : 'controller/Flight Controller/InputConditioning'
//  '<S13>'  : 'controller/Flight Controller/SwitchConditioning'
//  '<S14>'  : 'controller/Flight Controller/System Identification Logging'
//  '<S15>'  : 'controller/Flight Controller/quat2eul'
//  '<S16>'  : 'controller/Flight Controller/ARMINGControl/Compare To Constant3'
//  '<S17>'  : 'controller/Flight Controller/Control logic/Control Allocation'
//  '<S18>'  : 'controller/Flight Controller/Control logic/Degrees to Radians'
//  '<S19>'  : 'controller/Flight Controller/Control logic/Flight Testing'
//  '<S20>'  : 'controller/Flight Controller/Control logic/Control Allocation/Control Mixing'
//  '<S21>'  : 'controller/Flight Controller/Control logic/Control Allocation/Control Mixing/Control Surfaces Wing'
//  '<S22>'  : 'controller/Flight Controller/Control logic/Control Allocation/Control Mixing/Control Surfaces Winglet'
//  '<S23>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller'
//  '<S24>'  : 'controller/Flight Controller/Control logic/Flight Testing/Default Deflections'
//  '<S25>'  : 'controller/Flight Controller/Control logic/Flight Testing/Initial Pitch Input'
//  '<S26>'  : 'controller/Flight Controller/Control logic/Flight Testing/Initital Thrust Input'
//  '<S27>'  : 'controller/Flight Controller/Control logic/Flight Testing/Initital Yaw Input'
//  '<S28>'  : 'controller/Flight Controller/Control logic/Flight Testing/Mode Selection - SysID'
//  '<S29>'  : 'controller/Flight Controller/Control logic/Flight Testing/System Timer'
//  '<S30>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller'
//  '<S31>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/PX4 ULog'
//  '<S32>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Radians to Degrees'
//  '<S33>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Radians to Degrees1'
//  '<S34>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control'
//  '<S35>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller'
//  '<S36>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/PX4 ULog/PX4 uORB Message'
//  '<S37>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/PX4 ULog/PX4_log_write'
//  '<S38>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller'
//  '<S39>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Anti-windup'
//  '<S40>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/D Gain'
//  '<S41>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/External Derivative'
//  '<S42>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Filter'
//  '<S43>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Filter ICs'
//  '<S44>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/I Gain'
//  '<S45>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Ideal P Gain'
//  '<S46>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Ideal P Gain Fdbk'
//  '<S47>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Integrator'
//  '<S48>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Integrator ICs'
//  '<S49>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/N Copy'
//  '<S50>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/N Gain'
//  '<S51>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/P Copy'
//  '<S52>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Parallel P Gain'
//  '<S53>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Reset Signal'
//  '<S54>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Saturation'
//  '<S55>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Saturation Fdbk'
//  '<S56>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Sum'
//  '<S57>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Sum Fdbk'
//  '<S58>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Tracking Mode'
//  '<S59>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Tracking Mode Sum'
//  '<S60>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Tsamp - Integral'
//  '<S61>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Tsamp - Ngain'
//  '<S62>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/postSat Signal'
//  '<S63>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/preInt Signal'
//  '<S64>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/preSat Signal'
//  '<S65>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Anti-windup/Back Calculation'
//  '<S66>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/D Gain/Disabled'
//  '<S67>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/External Derivative/Disabled'
//  '<S68>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Filter/Disabled'
//  '<S69>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Filter ICs/Disabled'
//  '<S70>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/I Gain/Internal Parameters'
//  '<S71>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Ideal P Gain/Passthrough'
//  '<S72>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S73>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Integrator/Discrete'
//  '<S74>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Integrator ICs/External IC'
//  '<S75>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/N Copy/Disabled wSignal Specification'
//  '<S76>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/N Gain/Disabled'
//  '<S77>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/P Copy/Disabled'
//  '<S78>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Parallel P Gain/Internal Parameters'
//  '<S79>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Reset Signal/External Reset'
//  '<S80>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Saturation/Enabled'
//  '<S81>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Saturation Fdbk/Disabled'
//  '<S82>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Sum/Sum_PI'
//  '<S83>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Sum Fdbk/Disabled'
//  '<S84>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Tracking Mode/Disabled'
//  '<S85>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Tracking Mode Sum/Passthrough'
//  '<S86>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Tsamp - Integral/TsSignalSpecification'
//  '<S87>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Tsamp - Ngain/Passthrough'
//  '<S88>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/postSat Signal/Forward_Path'
//  '<S89>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/preInt Signal/Internal PreInt'
//  '<S90>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/preSat Signal/Forward_Path'
//  '<S91>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller'
//  '<S92>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PX4 ULog'
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
//  '<S145>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PX4 ULog/PX4 uORB Message'
//  '<S146>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PX4 ULog/PX4_log_write'
//  '<S147>' : 'controller/Flight Controller/Control logic/Flight Testing/Mode Selection - SysID/Default Deflections'
//  '<S148>' : 'controller/Flight Controller/Control logic/Flight Testing/Mode Selection - SysID/Dutch Roll Doublet'
//  '<S149>' : 'controller/Flight Controller/Control logic/Flight Testing/Mode Selection - SysID/Dutch Roll Thrust 3211'
//  '<S150>' : 'controller/Flight Controller/Control logic/Flight Testing/Mode Selection - SysID/Phugoid Doublet'
//  '<S151>' : 'controller/Flight Controller/Control logic/Flight Testing/Mode Selection - SysID/Short Period Doublet'
//  '<S152>' : 'controller/Flight Controller/Control logic/Flight Testing/Mode Selection - SysID/Short Period Sine Sweep'
//  '<S153>' : 'controller/Flight Controller/Control logic/Flight Testing/Mode Selection - SysID/Short Period Sine Sweep/Sine Sweep Generator'
//  '<S154>' : 'controller/Flight Controller/Get Airspeed/PX4 uORB Read2'
//  '<S155>' : 'controller/Flight Controller/Get Airspeed/PX4 uORB Read2/Enabled Subsystem'
//  '<S156>' : 'controller/Flight Controller/Getting Parameters from PX4/PX4 ULog'
//  '<S157>' : 'controller/Flight Controller/Getting Parameters from PX4/PX4 ULog/PX4 uORB Message'
//  '<S158>' : 'controller/Flight Controller/Getting Parameters from PX4/PX4 ULog/PX4_log_write'
//  '<S159>' : 'controller/Flight Controller/System Identification Logging/PX4 ULog'
//  '<S160>' : 'controller/Flight Controller/System Identification Logging/PX4 ULog/PX4 uORB Message'
//  '<S161>' : 'controller/Flight Controller/System Identification Logging/PX4 ULog/PX4_log_write'
//  '<S162>' : 'controller/Gyroscope/PX4 uORB Read'
//  '<S163>' : 'controller/Gyroscope/PX4 uORB Read/Enabled Subsystem'
//  '<S164>' : 'controller/Radio Control Transmitter/PX4 uORB Read'
//  '<S165>' : 'controller/Radio Control Transmitter/PX4 uORB Read/Enabled Subsystem'
//  '<S166>' : 'controller/Vehicle Attitude/PX4 uORB Read'
//  '<S167>' : 'controller/Vehicle Attitude/PX4 uORB Read/Enabled Subsystem'

#endif                                 // controller_h_

//
// File trailer for generated code.
//
// [EOF]
//
