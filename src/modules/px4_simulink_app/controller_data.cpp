//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: controller_data.cpp
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
#include "controller.h"

// Block parameters (default storage)
P_controller_T controller_P = {
  // Mask Parameter: PIDController_Kb
  //  Referenced by: '<S65>/Kb'

  1.0F,

  // Mask Parameter: PIDController_Kb_c
  //  Referenced by: '<S119>/Kb'

  1.0F,

  // Mask Parameter: PIDController_LowerSaturationLi
  //  Referenced by: '<S134>/Saturation'

  -0.17453292F,

  // Mask Parameter: PIDController_LowerSaturation_m
  //  Referenced by: '<S80>/Saturation'

  -0.75F,

  // Mask Parameter: PIDController_UpperSaturationLi
  //  Referenced by: '<S134>/Saturation'

  0.34906584F,

  // Mask Parameter: PIDController_UpperSaturation_o
  //  Referenced by: '<S80>/Saturation'

  0.75F,

  // Mask Parameter: CompareToConstant3_const
  //  Referenced by: '<S16>/Constant'

  1500U,

  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S167>/Out1'

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
  //  Referenced by: '<S166>/Constant'

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

  // Computed Parameter: Constant_Value_e
  //  Referenced by: '<S157>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // sp_doublet_amp
    0.0F,                              // sp_doublet_freq
    0.0F,                              // sp_doublet_dur
    0.0F,                              // sp_sweep_amp
    0.0F,                              // sp_sweep_freq_min
    0.0F,                              // sp_sweep_freq_max
    0.0F,                              // sp_sweep_dur
    0.0F,                              // dr_doublet_amp
    0.0F,                              // dr_doublet_freq
    0.0F,                              // dr_doublet_dur
    0.0F,                              // dr_diff_thrust_amp
    0.0F,                              // dr_diff_thrust_period
    0.0F,                              // ph_doublet_amp
    0.0F,                              // ph_doublet_freq
    0.0F,                              // ph_doublet_dur
    0.0F,                              // pitch_con_gain_p
    0.0F,                              // pitch_con_gain_i
    0.0F,                              // vel_con_gain_p
    0.0F,                              // vel_con_gain_i
    0.0F,                              // vel_lp_freq
    0U,                                // pilot_marker

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Out1_Y0_i
  //  Referenced by: '<S165>/Out1'

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
  //  Referenced by: '<S164>/Constant'

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

  // Computed Parameter: Constant_Value_j
  //  Referenced by: '<S160>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // activation_flag
    0.0F,                              // mode_selector
    0.0F,                              // test_mode_selector
    0.0F,                              // aileron
    0.0F,                              // elevator
    0.0F,                              // rudder
    0.0F,                              // throttle
    0.0F,                              // roll_rate
    0.0F,                              // pitch_rate
    0.0F,                              // yaw_rate
    0.0F,                              // roll_angle
    0.0F,                              // pitch_angle
    0.0F,                              // airspeed

    {
      0U, 0U, 0U, 0U }
    // _padding0
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
  //  Referenced by: '<S163>/Out1'

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
  //  Referenced by: '<S162>/Constant'

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

  // Computed Parameter: Constant_Value_p
  //  Referenced by: '<S36>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // activation_flag
    0.0F,                              // mode_selector
    0.0F,                              // test_mode_selector
    0.0F,                              // elevator_cmd
    0.0F,                              // pitch_angle
    0.0F,                              // pitch_angle_cmd
    0.0F,                              // airspeed
    0.0F                               // airspeed_cmd
  },

  // Computed Parameter: Out1_Y0_io
  //  Referenced by: '<S155>/Out1'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample
    0.0F,                              // indicated_airspeed_m_s
    0.0F,                              // true_airspeed_m_s
    0.0F,                              // air_temperature_celsius
    0.0F                               // confidence
  },

  // Computed Parameter: Constant_Value_a
  //  Referenced by: '<S154>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample
    0.0F,                              // indicated_airspeed_m_s
    0.0F,                              // true_airspeed_m_s
    0.0F,                              // air_temperature_celsius
    0.0F                               // confidence
  },

  // Computed Parameter: Constant_Value_b
  //  Referenced by: '<S145>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // v_raw
    0.0F                               // v_filtered
  },

  // Expression: short_period_sweep_dur
  //  Referenced by: '<S153>/Constant'

  30.0,

  // Expression: 0.5
  //  Referenced by: '<S153>/Constant1'

  0.5,

  // Expression: 1
  //  Referenced by: '<S149>/Gain1'

  1.0,

  // Expression: -1
  //  Referenced by: '<S149>/Gain'

  -1.0,

  // Expression: 0
  //  Referenced by: '<S149>/Constant3'

  0.0,

  // Expression: -1
  //  Referenced by: '<S149>/Constant1'

  -1.0,

  // Expression: 1
  //  Referenced by: '<S149>/Constant'

  1.0,

  // Expression: 1/100
  //  Referenced by: '<S11>/Gain2'

  0.01,

  // Expression: 1/100
  //  Referenced by: '<S11>/Gain1'

  0.01,

  // Expression: double(1/100)
  //  Referenced by: '<S11>/Gain4'

  0.01,

  // Expression: double(1/12.5)
  //  Referenced by: '<S11>/Gain'

  0.08,

  // Expression: double(1/12.5)
  //  Referenced by: '<S11>/Gain3'

  0.08,

  // Computed Parameter: StoreStartTime_InitialCondition
  //  Referenced by: '<S29>/Store Start Time'

  (0ULL),

  // Computed Parameter: SpoilerRudderDeflectionValue_Va
  //  Referenced by: '<S22>/Spoiler Rudder Deflection Value'

  0.5F,

  // Computed Parameter: Gain1_Gain_o
  //  Referenced by: '<S153>/Gain1'

  6.28318548F,

  // Expression: short_period_sweep_dur
  //  Referenced by: '<S152>/Set end time of doublet'

  30.0F,

  // Computed Parameter: Gain3_Gain_n
  //  Referenced by: '<S149>/Gain3'

  0.333333343F,

  // Computed Parameter: Gain4_Gain_m
  //  Referenced by: '<S149>/Gain4'

  0.2F,

  // Computed Parameter: Gain5_Gain
  //  Referenced by: '<S149>/Gain5'

  0.166666672F,

  // Computed Parameter: Gain6_Gain
  //  Referenced by: '<S149>/Gain6'

  0.142857149F,

  // Computed Parameter: Gain7_Gain
  //  Referenced by: '<S149>/Gain7'

  0.05F,

  // Computed Parameter: Merge2_InitialOutput
  //  Referenced by: '<S28>/Merge2'

  0.0F,

  // Computed Parameter: Gain1_Gain_g
  //  Referenced by: '<S18>/Gain1'

  0.0174532924F,

  // Computed Parameter: Switch_Threshold
  //  Referenced by: '<S23>/Switch'

  0.5F,

  // Computed Parameter: Constant_Value_k2
  //  Referenced by: '<S23>/Constant'

  0.0F,

  // Computed Parameter: Switch2_Threshold
  //  Referenced by: '<S23>/Switch2'

  0.5F,

  // Computed Parameter: Switch3_Threshold
  //  Referenced by: '<S23>/Switch3'

  4.5F,

  // Computed Parameter: Constant1_Value_ii
  //  Referenced by: '<S35>/Constant1'

  0.0F,

  // Computed Parameter: Gain_Gain_m
  //  Referenced by: '<S35>/Gain'

  0.004F,

  // Computed Parameter: Constant2_Value
  //  Referenced by: '<S35>/Constant2'

  1.0F,

  // Computed Parameter: Bias_Bias
  //  Referenced by: '<S35>/Bias'

  -1.0F,

  // Computed Parameter: DiscreteFilter1_InitialStates
  //  Referenced by: '<S35>/Discrete Filter1'

  0.0F,

  // Computed Parameter: Integrator_gainval
  //  Referenced by: '<S127>/Integrator'

  0.004F,

  // Computed Parameter: Switch_Threshold_e
  //  Referenced by: '<S30>/Switch'

  5.5F,

  // Computed Parameter: Integrator_gainval_i
  //  Referenced by: '<S73>/Integrator'

  0.004F,

  // Computed Parameter: Gain_Gain_mm
  //  Referenced by: '<S30>/Gain'

  12.5F,

  // Computed Parameter: Gain_Gain_i
  //  Referenced by: '<S32>/Gain'

  57.2957802F,

  // Computed Parameter: Gain_Gain_ax
  //  Referenced by: '<S33>/Gain'

  57.2957802F,

  // Computed Parameter: Switch1_Threshold
  //  Referenced by: '<S23>/Switch1'

  4.5F,

  // Computed Parameter: Saturation1_UpperSat
  //  Referenced by: '<S13>/Saturation1'

  2.0F,

  // Computed Parameter: Saturation1_LowerSat
  //  Referenced by: '<S13>/Saturation1'

  0.0F,

  // Computed Parameter: Savedpitchinput_InitialConditio
  //  Referenced by: '<S25>/Saved pitch input'

  0.0F,

  // Computed Parameter: Saturation8_UpperSat
  //  Referenced by: '<S12>/Saturation8'

  1.0F,

  // Computed Parameter: Saturation8_LowerSat
  //  Referenced by: '<S12>/Saturation8'

  -1.0F,

  // Computed Parameter: Checkforactivation_Threshold
  //  Referenced by: '<S25>/Check for activation'

  0.5F,

  // Computed Parameter: Constant6_Value
  //  Referenced by: '<S13>/Constant6'

  0.0F,

  // Computed Parameter: Saturation10_UpperSat
  //  Referenced by: '<S12>/Saturation10'

  1.0F,

  // Computed Parameter: Saturation10_LowerSat
  //  Referenced by: '<S12>/Saturation10'

  0.0F,

  // Computed Parameter: SavedThrustinput_InitialConditi
  //  Referenced by: '<S26>/Saved Thrust input'

  0.0F,

  // Computed Parameter: Checkforactivation_Threshold_a
  //  Referenced by: '<S26>/Check for activation'

  0.5F,

  // Computed Parameter: Saturation7_UpperSat
  //  Referenced by: '<S12>/Saturation7'

  1.0F,

  // Computed Parameter: Saturation7_LowerSat
  //  Referenced by: '<S12>/Saturation7'

  -1.0F,

  // Computed Parameter: Savedyawinput_InitialCondition
  //  Referenced by: '<S27>/Saved yaw input'

  0.0F,

  // Computed Parameter: Checkforactivation_Threshold_g
  //  Referenced by: '<S27>/Check for activation'

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
  //  Referenced by: '<S12>/Saturation9'

  1.0F,

  // Computed Parameter: Saturation9_LowerSat
  //  Referenced by: '<S12>/Saturation9'

  -1.0F,

  // Computed Parameter: Gain_Gain_h
  //  Referenced by: '<S12>/Gain'

  -1.0F,

  // Computed Parameter: Rollcontrolportion_Gain
  //  Referenced by: '<S21>/Roll control portion'

  0.5F,

  // Computed Parameter: ControlAuthorityGain_Gain
  //  Referenced by: '<S2>/Control Authority Gain'

  1.0F,

  // Computed Parameter: NoRudderDeflectionValue_Value
  //  Referenced by: '<S22>/No Rudder Deflection Value'

  0.0F,

  // Computed Parameter: DeflectionLogicRudderRight_Thre
  //  Referenced by: '<S22>/Deflection Logic Rudder Right'

  0.0F,

  // Computed Parameter: Saturation7_UpperSat_m
  //  Referenced by: '<S13>/Saturation7'

  2.0F,

  // Computed Parameter: Saturation7_LowerSat_b
  //  Referenced by: '<S13>/Saturation7'

  0.0F,

  // Computed Parameter: Switch_Threshold_n
  //  Referenced by: '<S22>/Switch'

  0.5F,

  // Computed Parameter: ReverseforRudderLeft_Gain
  //  Referenced by: '<S22>/Reverse for Rudder Left'

  -1.0F,

  // Computed Parameter: DeflectionLogicRudderLeft_Thres
  //  Referenced by: '<S22>/Deflection Logic Rudder Left'

  0.0F,

  // Computed Parameter: OutputLimitation_UpperSat
  //  Referenced by: '<S2>/Output Limitation'

  1.0F,

  // Computed Parameter: OutputLimitation_LowerSat
  //  Referenced by: '<S2>/Output Limitation'

  -1.0F,

  // Computed Parameter: OutputLimitation2_UpperSat
  //  Referenced by: '<S14>/Output Limitation2'

  1.0F,

  // Computed Parameter: OutputLimitation2_LowerSat
  //  Referenced by: '<S14>/Output Limitation2'

  -1.0F,

  // Computed Parameter: OutputLimitation3_UpperSat
  //  Referenced by: '<S14>/Output Limitation3'

  1.0F,

  // Computed Parameter: OutputLimitation3_LowerSat
  //  Referenced by: '<S14>/Output Limitation3'

  -1.0F,

  // Computed Parameter: OutputLimitation1_UpperSat
  //  Referenced by: '<S14>/Output Limitation1'

  1.0F,

  // Computed Parameter: OutputLimitation1_LowerSat
  //  Referenced by: '<S14>/Output Limitation1'

  -1.0F,

  // Computed Parameter: OutputLimitation_UpperSat_m
  //  Referenced by: '<S14>/Output Limitation'

  1.0F,

  // Computed Parameter: OutputLimitation_LowerSat_l
  //  Referenced by: '<S14>/Output Limitation'

  -1.0F,

  // Computed Parameter: Gain1_Gain_a
  //  Referenced by: '<S14>/Gain1'

  0.5F,

  // Computed Parameter: Gain_Gain_l
  //  Referenced by: '<S14>/Gain'

  0.5F
};

// instance parameters
InstP_controller_T controller_InstP = {
  // Variable: dutch_roll_amp
  //  Referenced by: '<S148>/Doublet Generator'

  0.1,

  // Variable: dutch_roll_diff_thrust_amp
  //  Referenced by: '<S149>/Gain2'

  0.2,

  // Variable: dutch_roll_freq
  //  Referenced by: '<S148>/Doublet Generator'

  0.44,

  // Variable: phugoid_amp
  //  Referenced by: '<S150>/Doublet Generator'

  0.1,

  // Variable: phugoid_freq
  //  Referenced by: '<S150>/Doublet Generator'

  0.166667,

  // Variable: short_period_amp
  //  Referenced by: '<S151>/Doublet Generator'

  0.24,

  // Variable: short_period_freq
  //  Referenced by: '<S151>/Doublet Generator'

  1.1,

  // Variable: short_period_sweep_freq_max
  //  Referenced by: '<S153>/Constant2'

  1.5,

  // Variable: short_period_sweep_freq_min
  //  Referenced by: '<S153>/Constant3'

  0.5,

  // Variable: dutch_roll_diff_thrust_period
  //  Referenced by:
  //    '<S149>/Switch'
  //    '<S149>/Switch1'
  //    '<S149>/Switch2'
  //    '<S149>/Switch3'
  //    '<S149>/Switch5'

  1.0F,

  // Variable: dutch_roll_dur
  //  Referenced by: '<S148>/Set time to re-allow  pilot inputs'

  7.5F,

  // Variable: dutch_roll_period
  //  Referenced by: '<S148>/Switch1'

  2.2727F,

  // Variable: phugoid_dur
  //  Referenced by: '<S150>/Set time to re-allow  pilot inputs'

  20.0F,

  // Variable: phugoid_period
  //  Referenced by: '<S150>/Switch1'

  6.0F,

  // Variable: pitch_con_gain_i
  //  Referenced by: '<S70>/Integral Gain'

  -2.2918F,

  // Variable: pitch_con_gain_p
  //  Referenced by: '<S78>/Proportional Gain'

  -1.3751F,

  // Variable: short_period_dur
  //  Referenced by: '<S151>/Set time to re-allow  pilot inputs'

  2.5F,

  // Variable: short_period_period
  //  Referenced by: '<S151>/Set end time of doublet'

  0.9091F,

  // Variable: short_period_sweep_amp
  //  Referenced by: '<S152>/Gain'

  -0.3F,

  // Variable: vel_con_gain_i
  //  Referenced by: '<S124>/Integral Gain'

  -0.015F,

  // Variable: vel_con_gain_p
  //  Referenced by: '<S132>/Proportional Gain'

  -0.06F,

  // Variable: vel_lp_freq
  //  Referenced by: '<S35>/Constant'

  20.0F
};

//
// File trailer for generated code.
//
// [EOF]
//
