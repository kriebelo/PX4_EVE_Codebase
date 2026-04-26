//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: controller_data.cpp
//
// Code generated for Simulink model 'controller'.
//
// Model version                  : 1.82
// Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
// C/C++ source code generated on : Sun Apr 26 21:15:41 2026
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "controller.h"

// Block parameters (default storage)
P_controller_T controller_P = {
  // Mask Parameter: PIDController_Kb
  //  Referenced by: '<S113>/Kb'

  1.0F,

  // Mask Parameter: PIDController_Kb_c
  //  Referenced by: '<S60>/Kb'

  1.0F,

  // Mask Parameter: PIDController_LowerSaturationLi
  //  Referenced by: '<S128>/Saturation'

  -0.17453292F,

  // Mask Parameter: PIDController_LowerSaturation_m
  //  Referenced by: '<S75>/Saturation'

  -0.75F,

  // Mask Parameter: PIDController_UpperSaturationLi
  //  Referenced by: '<S128>/Saturation'

  0.34906584F,

  // Mask Parameter: PIDController_UpperSaturation_d
  //  Referenced by: '<S75>/Saturation'

  0.75F,

  // Mask Parameter: CompareToConstant3_const
  //  Referenced by: '<S16>/Constant'

  1500U,

  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S152>/Out1'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // position

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // q

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // velocity

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // angular_velocity

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // position_variance

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // orientation_variance

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // velocity_variance
    0U,                                // pose_frame
    0U,                                // velocity_frame
    0U,                                // reset_counter
    0,                                 // quality

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value
  //  Referenced by: '<S151>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // position

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // q

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // velocity

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // angular_velocity

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // position_variance

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // orientation_variance

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // velocity_variance
    0U,                                // pose_frame
    0U,                                // velocity_frame
    0U,                                // reset_counter
    0,                                 // quality

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Out1_Y0_a
  //  Referenced by: '<S146>/Out1'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_last_signal
    0,                                 // rssi
    0.0F,                              // rssi_dbm
    0U,                                // rc_lost_frame_count
    0U,                                // rc_total_frame_count
    0U,                                // rc_ppm_frame_length

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
    ,                                  // values
    0U,                                // channel_count
    false,                             // rc_failsafe
    false,                             // rc_lost
    0U,                                // input_source
    0,                                 // link_quality
    0U                                 // _padding0
  },

  // Computed Parameter: Out1_Y0_i
  //  Referenced by: '<S150>/Out1'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_last_signal
    0,                                 // rssi
    0.0F,                              // rssi_dbm
    0U,                                // rc_lost_frame_count
    0U,                                // rc_total_frame_count
    0U,                                // rc_ppm_frame_length

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
    ,                                  // values
    0U,                                // channel_count
    false,                             // rc_failsafe
    false,                             // rc_lost
    0U,                                // input_source
    0,                                 // link_quality
    0U                                 // _padding0
  },

  // Computed Parameter: Constant_Value_d
  //  Referenced by: '<S149>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_last_signal
    0,                                 // rssi
    0.0F,                              // rssi_dbm
    0U,                                // rc_lost_frame_count
    0U,                                // rc_total_frame_count
    0U,                                // rc_ppm_frame_length

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
    ,                                  // values
    0U,                                // channel_count
    false,                             // rc_failsafe
    false,                             // rc_lost
    0U,                                // input_source
    0,                                 // link_quality
    0U                                 // _padding0
  },

  // Computed Parameter: Constant_Value_c
  //  Referenced by: '<S145>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_last_signal
    0,                                 // rssi
    0.0F,                              // rssi_dbm
    0U,                                // rc_lost_frame_count
    0U,                                // rc_total_frame_count
    0U,                                // rc_ppm_frame_length

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
    ,                                  // values
    0U,                                // channel_count
    false,                             // rc_failsafe
    false,                             // rc_lost
    0U,                                // input_source
    0,                                 // link_quality
    0U                                 // _padding0
  },

  // Computed Parameter: Out1_Y0_k
  //  Referenced by: '<S7>/Out1'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample
    0U,                                // device_id
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z
    0.0F,                              // temperature
    0U,                                // error_count

    {
      0U, 0U, 0U }
    ,                                  // clip_counter
    0U,                                // samples

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_k
  //  Referenced by: '<S6>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample
    0U,                                // device_id
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z
    0.0F,                              // temperature
    0U,                                // error_count

    {
      0U, 0U, 0U }
    ,                                  // clip_counter
    0U,                                // samples

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Out1_Y0_e
  //  Referenced by: '<S148>/Out1'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample
    0U,                                // device_id
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z
    0.0F,                              // temperature
    0U,                                // error_count

    {
      0U, 0U, 0U }
    ,                                  // clip_counter
    0U,                                // samples

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_m
  //  Referenced by: '<S147>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample
    0U,                                // device_id
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z
    0.0F,                              // temperature
    0U,                                // error_count

    {
      0U, 0U, 0U }
    ,                                  // clip_counter
    0U,                                // samples

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Out1_Y0_io
  //  Referenced by: '<S144>/Out1'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample
    0.0F,                              // indicated_airspeed_m_s
    0.0F,                              // true_airspeed_m_s
    0.0F,                              // air_temperature_celsius
    0.0F                               // confidence
  },

  // Computed Parameter: Constant_Value_a
  //  Referenced by: '<S143>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample
    0.0F,                              // indicated_airspeed_m_s
    0.0F,                              // true_airspeed_m_s
    0.0F,                              // air_temperature_celsius
    0.0F                               // confidence
  },

  // Expression: 1/100
  //  Referenced by: '<S12>/Gain2'

  0.01,

  // Expression: double(1/12.5)
  //  Referenced by: '<S12>/Gain'

  0.08,

  // Expression: 1/100
  //  Referenced by: '<S12>/Gain1'

  0.01,

  // Computed Parameter: TmpRTBAtPX4TimestampOutport1_In
  //  Referenced by:

  (0ULL),

  // Computed Parameter: StoreStartTime_InitialCondition
  //  Referenced by: '<S29>/Store Start Time'

  (0ULL),

  // Computed Parameter: SpoilerRudderDeflectionValue_Va
  //  Referenced by: '<S22>/Spoiler Rudder Deflection Value'

  0.5F,

  // Computed Parameter: Gain1_Gain_o
  //  Referenced by: '<S18>/Gain1'

  0.0174532924F,

  // Computed Parameter: Switch_Threshold
  //  Referenced by: '<S23>/Switch'

  0.5F,

  // Computed Parameter: Constant_Value_b
  //  Referenced by: '<S23>/Constant'

  0.0F,

  // Computed Parameter: Switch2_Threshold
  //  Referenced by: '<S23>/Switch2'

  0.5F,

  // Computed Parameter: Switch3_Threshold
  //  Referenced by: '<S23>/Switch3'

  0.5F,

  // Computed Parameter: Integrator_gainval
  //  Referenced by: '<S121>/Integrator'

  0.001F,

  // Computed Parameter: Switch_Threshold_k
  //  Referenced by: '<S30>/Switch'

  0.5F,

  // Computed Parameter: Integrator_gainval_b
  //  Referenced by: '<S68>/Integrator'

  0.001F,

  // Computed Parameter: Switch1_Threshold
  //  Referenced by: '<S23>/Switch1'

  0.5F,

  // Computed Parameter: Constant7_Value
  //  Referenced by: '<S14>/Constant7'

  1.0F,

  // Computed Parameter: Constant6_Value
  //  Referenced by: '<S14>/Constant6'

  0.0F,

  // Computed Parameter: TmpRTBAtOutputLimitationOutport
  //  Referenced by:

  0.0F,

  // Computed Parameter: Saturation1_UpperSat
  //  Referenced by: '<S14>/Saturation1'

  2.0F,

  // Computed Parameter: Saturation1_LowerSat
  //  Referenced by: '<S14>/Saturation1'

  0.0F,

  // Computed Parameter: Saturation8_UpperSat
  //  Referenced by: '<S13>/Saturation8'

  1.0F,

  // Computed Parameter: Saturation8_LowerSat
  //  Referenced by: '<S13>/Saturation8'

  -1.0F,

  // Computed Parameter: Savedpitchinput_InitialConditio
  //  Referenced by: '<S25>/Saved pitch input'

  0.0F,

  // Computed Parameter: Checkforactivation_Threshold
  //  Referenced by: '<S25>/Check for activation'

  0.5F,

  // Computed Parameter: Switch4_Threshold
  //  Referenced by: '<S14>/Switch4'

  2.5F,

  // Computed Parameter: Saturation_UpperSat
  //  Referenced by: '<S14>/Saturation'

  1.0F,

  // Computed Parameter: Saturation_LowerSat
  //  Referenced by: '<S14>/Saturation'

  0.0F,

  // Computed Parameter: Saturation7_UpperSat
  //  Referenced by: '<S13>/Saturation7'

  1.0F,

  // Computed Parameter: Saturation7_LowerSat
  //  Referenced by: '<S13>/Saturation7'

  -1.0F,

  // Computed Parameter: Savedyawinput_InitialCondition
  //  Referenced by: '<S27>/Saved yaw input'

  0.0F,

  // Computed Parameter: Checkforactivation_Threshold_d
  //  Referenced by: '<S27>/Check for activation'

  0.5F,

  // Computed Parameter: Saturation10_UpperSat
  //  Referenced by: '<S13>/Saturation10'

  1.0F,

  // Computed Parameter: Saturation10_LowerSat
  //  Referenced by: '<S13>/Saturation10'

  0.0F,

  // Computed Parameter: SavedThrustinput_InitialConditi
  //  Referenced by: '<S26>/Saved Thrust input'

  0.0F,

  // Computed Parameter: Checkforactivation_Threshold_m
  //  Referenced by: '<S26>/Check for activation'

  0.5F,

  // Computed Parameter: Givestoredtimeinsteadofcurrentt
  //  Referenced by: '<S29>/Give stored time instead  of current time after activation'

  0.5F,

  // Computed Parameter: Converttimefromustos_Gain
  //  Referenced by: '<S29>/Convert time from us to s'

  1.0E-6F,

  // Computed Parameter: Pitchcontrolportion_Gain
  //  Referenced by: '<S21>/Pitch control portion'

  0.5F,

  // Computed Parameter: Saturation9_UpperSat
  //  Referenced by: '<S13>/Saturation9'

  1.0F,

  // Computed Parameter: Saturation9_LowerSat
  //  Referenced by: '<S13>/Saturation9'

  -1.0F,

  // Computed Parameter: Gain_Gain_h
  //  Referenced by: '<S13>/Gain'

  -1.0F,

  // Computed Parameter: Rollcontrolportion_Gain
  //  Referenced by: '<S21>/Roll control portion'

  0.5F,

  // Computed Parameter: Saturation7_UpperSat_m
  //  Referenced by: '<S14>/Saturation7'

  2.0F,

  // Computed Parameter: Saturation7_LowerSat_b
  //  Referenced by: '<S14>/Saturation7'

  0.0F,

  // Computed Parameter: NoRudderDeflectionValue_Value
  //  Referenced by: '<S22>/No Rudder Deflection Value'

  0.0F,

  // Computed Parameter: Switch_Threshold_j
  //  Referenced by: '<S22>/Switch'

  0.5F,

  // Computed Parameter: DeflectionLogicRudderRight_Thre
  //  Referenced by: '<S22>/Deflection Logic Rudder Right'

  0.0F,

  // Computed Parameter: ReverseforRudderLeft_Gain
  //  Referenced by: '<S22>/Reverse for Rudder Left'

  -1.0F,

  // Computed Parameter: DeflectionLogicRudderLeft_Thres
  //  Referenced by: '<S22>/Deflection Logic Rudder Left'

  0.0F,

  // Computed Parameter: ControlAuthorityGain_Gain
  //  Referenced by: '<S2>/Control Authority Gain'

  1.0F,

  // Computed Parameter: OutputLimitation_UpperSat
  //  Referenced by: '<S2>/Output Limitation'

  1.0F,

  // Computed Parameter: OutputLimitation_LowerSat
  //  Referenced by: '<S2>/Output Limitation'

  -1.0F
};

// instance parameters
InstP_controller_T controller_InstP = {
  // Variable: dutch_roll_amp
  //  Referenced by: '<S140>/Doublet Generator'

  0.1,

  // Variable: dutch_roll_freq
  //  Referenced by: '<S140>/Doublet Generator'

  0.44,

  // Variable: phugoid_amp
  //  Referenced by: '<S141>/Doublet Generator'

  0.1,

  // Variable: phugoid_freq
  //  Referenced by: '<S141>/Doublet Generator'

  0.166667,

  // Variable: short_period_amp
  //  Referenced by: '<S142>/Doublet Generator'

  0.24,

  // Variable: short_period_freq
  //  Referenced by: '<S142>/Doublet Generator'

  1.1,

  // Variable: dutch_roll_dur
  //  Referenced by: '<S140>/Set time to re-allow  pilot inputs'

  7.5F,

  // Variable: dutch_roll_period
  //  Referenced by: '<S140>/Switch1'

  2.2727F,

  // Variable: phugoid_dur
  //  Referenced by: '<S141>/Set time to re-allow  pilot inputs'

  20.0F,

  // Variable: phugoid_period
  //  Referenced by: '<S141>/Switch1'

  6.0F,

  // Variable: pitch_con_gain_i
  //  Referenced by: '<S65>/Integral Gain'

  -2.2918F,

  // Variable: pitch_con_gain_p
  //  Referenced by: '<S73>/Proportional Gain'

  -1.3751F,

  // Variable: short_period_dur
  //  Referenced by: '<S142>/Set time to re-allow  pilot inputs'

  2.5F,

  // Variable: short_period_period
  //  Referenced by: '<S142>/Set end time of doublet'

  0.9091F,

  // Variable: vel_con_gain_i
  //  Referenced by: '<S118>/Integral Gain'

  -0.015F,

  // Variable: vel_con_gain_p
  //  Referenced by: '<S126>/Proportional Gain'

  -0.06F
};

//
// File trailer for generated code.
//
// [EOF]
//
