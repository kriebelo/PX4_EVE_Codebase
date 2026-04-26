//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: controller.h
//
// Code generated for Simulink model 'controller'.
//
// Model version                  : 1.82
// Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
// C/C++ source code generated on : Sat Apr 25 21:06:54 2026
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
#include "MW_PX4_Parameter.h"
#include "MW_Parameter.h"
#include "MW_PX4_Actuators.h"
#include "controller_types.h"
#include <uORB/topics/vehicle_odometry.h>
#include <uORB/topics/input_rc.h>
#include <uORB/topics/sensor_accel.h>
#include <uORB/topics/sensor_gyro.h>
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

// Block signals for system '<S12>/Read Parameter11'
struct B_ReadParameter11_controller_T {
  real32_T ReadParameter11_o1;         // '<S12>/Read Parameter11'
};

// Block states (default storage) for system '<S12>/Read Parameter11'
struct DW_ReadParameter11_controller_T {
  px4_internal_block_ParameterU_T obj; // '<S12>/Read Parameter11'
  boolean_T objisempty;                // '<S12>/Read Parameter11'
};

// Block signals (default storage)
struct B_controller_T {
  px4_Bus_vehicle_odometry In1;        // '<S152>/In1'
  px4_Bus_vehicle_odometry r;
  px4_Bus_input_rc In1_d;              // '<S150>/In1'
  px4_Bus_input_rc r1;
  real32_T motorValues[12];
  real32_T motorValues_m[12];
  px4_Bus_sensor_accel r2;
  px4_Bus_sensor_gyro r3;
  real32_T servoValues[8];
  px4_Bus_airspeed In1_m;              // '<S144>/In1'
  px4_Bus_airspeed r4;
  uint64_T TmpRTBAtPX4TimestampOutport1;// '<Root>/PX4 Timestamp'
  real32_T TmpRTBAtOutputLimitationOutport[6];// '<S2>/Output Limitation'
  B_ReadParameter11_controller_T ReadParameter12;// '<S12>/Read Parameter11'
  B_ReadParameter11_controller_T ReadParameter11;// '<S12>/Read Parameter11'
};

// Block states (default storage) for system '<Root>'
struct DW_controller_T {
  px4_internal_block_PX4Actuato_T obj; // '<Root>/PX4 Actuator Write'
  px4_internal_block_Subscriber_T obj_l;// '<S151>/SourceBlock'
  px4_internal_block_Subscriber_T obj_d;// '<S149>/SourceBlock'
  px4_internal_block_Subscriber_T obj_o;// '<S147>/SourceBlock'
  px4_internal_block_Subscriber_T obj_j;// '<S145>/SourceBlock'
  px4_internal_block_Subscriber_T obj_m;// '<S143>/SourceBlock'
  px4_internal_block_Subscriber_T obj_og;// '<S6>/SourceBlock'
  px4_internal_block_getPX4Abso_T obj_h;// '<Root>/PX4 Timestamp'
  px4_internal_block_ParameterU_T obj_ms;// '<S14>/Read Parameter2'
  px4_internal_block_ParameterU_T obj_k;// '<S14>/Read Parameter1'
  px4_internal_block_ParameterU_T obj_n;// '<S14>/Read Parameter'
  px4_internal_block_ParameterU_T obj_mf;// '<S12>/Read Parameter9'
  px4_internal_block_ParameterU_T obj_p;// '<S12>/Read Parameter8'
  px4_internal_block_ParameterU_T obj_l1;// '<S12>/Read Parameter7'
  px4_internal_block_ParameterU_T obj_pe;// '<S12>/Read Parameter6'
  px4_internal_block_ParameterU_T obj_o5;// '<S12>/Read Parameter5'
  px4_internal_block_ParameterU_T obj_e;// '<S12>/Read Parameter4'
  px4_internal_block_ParameterU_T obj_f;// '<S12>/Read Parameter3'
  px4_internal_block_ParameterU_T obj_ju;// '<S12>/Read Parameter2'
  px4_internal_block_ParameterU_T obj_b;// '<S12>/Read Parameter10'
  px4_internal_block_ParameterU_T obj_a;// '<S12>/Read Parameter1'
  px4_internal_block_ParameterU_T obj_ng;// '<S12>/Read Parameter'
  uint64_T TmpRTBAtPX4TimestampOutport1_Bu;// synthesized block
  uint64_T StoreStartTime_PreviousInput;// '<S29>/Store Start Time'
  real32_T Integrator_DSTATE;          // '<S121>/Integrator'
  real32_T Integrator_DSTATE_e;        // '<S68>/Integrator'
  real32_T TmpRTBAtOutputLimitationOutport[6];// synthesized block
  real32_T Savedpitchinput_PreviousInput;// '<S25>/Saved pitch input'
  real32_T Savedyawinput_PreviousInput;// '<S27>/Saved yaw input'
  real32_T SavedThrustinput_PreviousInput;// '<S26>/Saved Thrust input'
  real32_T TmpRTBAtControllerOutport2_Buff;// synthesized block
  real32_T TmpRTBAtControlAuthorityGainInp[2];// synthesized block
  real32_T TmpRTBAtFunctionforDeflectionVa;// synthesized block
  real32_T TmpRTBAtFunctionforDeflection_m;// synthesized block
  int8_T Integrator_PrevResetState;    // '<S121>/Integrator'
  int8_T Integrator_PrevResetState_k;  // '<S68>/Integrator'
  uint8_T Integrator_IC_LOADING;       // '<S121>/Integrator'
  uint8_T Integrator_IC_LOADING_p;     // '<S68>/Integrator'
  DW_ReadParameter11_controller_T ReadParameter12;// '<S12>/Read Parameter11'
  DW_ReadParameter11_controller_T ReadParameter11;// '<S12>/Read Parameter11'
};

// instance parameters, for system '<Root>'
struct InstP_controller_T {
  real_T dutch_roll_amp;               // Variable: dutch_roll_amp
                                          //  Referenced by: '<S140>/Doublet Generator'

  real_T dutch_roll_freq;              // Variable: dutch_roll_freq
                                          //  Referenced by: '<S140>/Doublet Generator'

  real_T phugoid_amp;                  // Variable: phugoid_amp
                                          //  Referenced by: '<S141>/Doublet Generator'

  real_T phugoid_freq;                 // Variable: phugoid_freq
                                          //  Referenced by: '<S141>/Doublet Generator'

  real_T short_period_amp;             // Variable: short_period_amp
                                          //  Referenced by: '<S142>/Doublet Generator'

  real_T short_period_freq;            // Variable: short_period_freq
                                          //  Referenced by: '<S142>/Doublet Generator'

  real32_T dutch_roll_dur;             // Variable: dutch_roll_dur
                                          //  Referenced by: '<S140>/Set time to re-allow  pilot inputs'

  real32_T dutch_roll_period;          // Variable: dutch_roll_period
                                          //  Referenced by: '<S140>/Switch1'

  real32_T phugoid_dur;                // Variable: phugoid_dur
                                          //  Referenced by: '<S141>/Set time to re-allow  pilot inputs'

  real32_T phugoid_period;             // Variable: phugoid_period
                                          //  Referenced by: '<S141>/Switch1'

  real32_T pitch_con_gain_i;           // Variable: pitch_con_gain_i
                                          //  Referenced by: '<S65>/Integral Gain'

  real32_T pitch_con_gain_p;           // Variable: pitch_con_gain_p
                                          //  Referenced by: '<S73>/Proportional Gain'

  real32_T short_period_dur;           // Variable: short_period_dur
                                          //  Referenced by: '<S142>/Set time to re-allow  pilot inputs'

  real32_T short_period_period;        // Variable: short_period_period
                                          //  Referenced by: '<S142>/Set end time of doublet'

  real32_T vel_con_gain_i;             // Variable: vel_con_gain_i
                                          //  Referenced by: '<S118>/Integral Gain'

  real32_T vel_con_gain_p;             // Variable: vel_con_gain_p
                                          //  Referenced by: '<S126>/Proportional Gain'

};

// Parameters (default storage)
struct P_controller_T_ {
  real32_T PIDController_Kb;           // Mask Parameter: PIDController_Kb
                                          //  Referenced by: '<S113>/Kb'

  real32_T PIDController_Kb_c;         // Mask Parameter: PIDController_Kb_c
                                          //  Referenced by: '<S60>/Kb'

  real32_T PIDController_LowerSaturationLi;
                              // Mask Parameter: PIDController_LowerSaturationLi
                                 //  Referenced by: '<S128>/Saturation'

  real32_T PIDController_LowerSaturation_m;
                              // Mask Parameter: PIDController_LowerSaturation_m
                                 //  Referenced by: '<S75>/Saturation'

  real32_T PIDController_UpperSaturationLi;
                              // Mask Parameter: PIDController_UpperSaturationLi
                                 //  Referenced by: '<S128>/Saturation'

  real32_T PIDController_UpperSaturation_d;
                              // Mask Parameter: PIDController_UpperSaturation_d
                                 //  Referenced by: '<S75>/Saturation'

  uint16_T CompareToConstant3_const; // Mask Parameter: CompareToConstant3_const
                                        //  Referenced by: '<S16>/Constant'

  px4_Bus_vehicle_odometry Out1_Y0;    // Computed Parameter: Out1_Y0
                                          //  Referenced by: '<S152>/Out1'

  px4_Bus_vehicle_odometry Constant_Value;// Computed Parameter: Constant_Value
                                             //  Referenced by: '<S151>/Constant'

  px4_Bus_input_rc Out1_Y0_a;          // Computed Parameter: Out1_Y0_a
                                          //  Referenced by: '<S146>/Out1'

  px4_Bus_input_rc Out1_Y0_i;          // Computed Parameter: Out1_Y0_i
                                          //  Referenced by: '<S150>/Out1'

  px4_Bus_input_rc Constant_Value_d;   // Computed Parameter: Constant_Value_d
                                          //  Referenced by: '<S149>/Constant'

  px4_Bus_input_rc Constant_Value_c;   // Computed Parameter: Constant_Value_c
                                          //  Referenced by: '<S145>/Constant'

  px4_Bus_sensor_accel Out1_Y0_k;      // Computed Parameter: Out1_Y0_k
                                          //  Referenced by: '<S7>/Out1'

  px4_Bus_sensor_accel Constant_Value_k;// Computed Parameter: Constant_Value_k
                                           //  Referenced by: '<S6>/Constant'

  px4_Bus_sensor_gyro Out1_Y0_e;       // Computed Parameter: Out1_Y0_e
                                          //  Referenced by: '<S148>/Out1'

  px4_Bus_sensor_gyro Constant_Value_m;// Computed Parameter: Constant_Value_m
                                          //  Referenced by: '<S147>/Constant'

  px4_Bus_airspeed Out1_Y0_io;         // Computed Parameter: Out1_Y0_io
                                          //  Referenced by: '<S144>/Out1'

  px4_Bus_airspeed Constant_Value_a;   // Computed Parameter: Constant_Value_a
                                          //  Referenced by: '<S143>/Constant'

  real_T Gain1_Gain;                   // Expression: 1/100
                                          //  Referenced by: '<S12>/Gain1'

  real_T Gain2_Gain;                   // Expression: 1/100
                                          //  Referenced by: '<S12>/Gain2'

  real_T Gain_Gain;                    // Expression: double(1/12.5)
                                          //  Referenced by: '<S12>/Gain'

  uint64_T TmpRTBAtPX4TimestampOutport1_In;
                          // Computed Parameter: TmpRTBAtPX4TimestampOutport1_In
                             //  Referenced by:

  uint64_T StoreStartTime_InitialCondition;
                          // Computed Parameter: StoreStartTime_InitialCondition
                             //  Referenced by: '<S29>/Store Start Time'

  real32_T SpoilerRudderDeflectionValue_Va;
                          // Computed Parameter: SpoilerRudderDeflectionValue_Va
                             //  Referenced by: '<S22>/Spoiler Rudder Deflection Value'

  real32_T Gain1_Gain_o;               // Computed Parameter: Gain1_Gain_o
                                          //  Referenced by: '<S18>/Gain1'

  real32_T Switch_Threshold;           // Computed Parameter: Switch_Threshold
                                          //  Referenced by: '<S23>/Switch'

  real32_T Constant_Value_b;           // Computed Parameter: Constant_Value_b
                                          //  Referenced by: '<S23>/Constant'

  real32_T Switch2_Threshold;          // Computed Parameter: Switch2_Threshold
                                          //  Referenced by: '<S23>/Switch2'

  real32_T Switch3_Threshold;          // Computed Parameter: Switch3_Threshold
                                          //  Referenced by: '<S23>/Switch3'

  real32_T Integrator_gainval;         // Computed Parameter: Integrator_gainval
                                          //  Referenced by: '<S121>/Integrator'

  real32_T Switch_Threshold_k;         // Computed Parameter: Switch_Threshold_k
                                          //  Referenced by: '<S30>/Switch'

  real32_T Integrator_gainval_b;     // Computed Parameter: Integrator_gainval_b
                                        //  Referenced by: '<S68>/Integrator'

  real32_T Switch1_Threshold;          // Computed Parameter: Switch1_Threshold
                                          //  Referenced by: '<S23>/Switch1'

  real32_T Constant7_Value;            // Computed Parameter: Constant7_Value
                                          //  Referenced by: '<S14>/Constant7'

  real32_T Constant6_Value;            // Computed Parameter: Constant6_Value
                                          //  Referenced by: '<S14>/Constant6'

  real32_T TmpRTBAtOutputLimitationOutport;
                          // Computed Parameter: TmpRTBAtOutputLimitationOutport
                             //  Referenced by:

  real32_T Saturation1_UpperSat;     // Computed Parameter: Saturation1_UpperSat
                                        //  Referenced by: '<S14>/Saturation1'

  real32_T Saturation1_LowerSat;     // Computed Parameter: Saturation1_LowerSat
                                        //  Referenced by: '<S14>/Saturation1'

  real32_T Saturation8_UpperSat;     // Computed Parameter: Saturation8_UpperSat
                                        //  Referenced by: '<S13>/Saturation8'

  real32_T Saturation8_LowerSat;     // Computed Parameter: Saturation8_LowerSat
                                        //  Referenced by: '<S13>/Saturation8'

  real32_T Savedpitchinput_InitialConditio;
                          // Computed Parameter: Savedpitchinput_InitialConditio
                             //  Referenced by: '<S25>/Saved pitch input'

  real32_T Checkforactivation_Threshold;
                             // Computed Parameter: Checkforactivation_Threshold
                                //  Referenced by: '<S25>/Check for activation'

  real32_T Switch4_Threshold;          // Computed Parameter: Switch4_Threshold
                                          //  Referenced by: '<S14>/Switch4'

  real32_T Saturation_UpperSat;       // Computed Parameter: Saturation_UpperSat
                                         //  Referenced by: '<S14>/Saturation'

  real32_T Saturation_LowerSat;       // Computed Parameter: Saturation_LowerSat
                                         //  Referenced by: '<S14>/Saturation'

  real32_T Saturation7_UpperSat;     // Computed Parameter: Saturation7_UpperSat
                                        //  Referenced by: '<S13>/Saturation7'

  real32_T Saturation7_LowerSat;     // Computed Parameter: Saturation7_LowerSat
                                        //  Referenced by: '<S13>/Saturation7'

  real32_T Savedyawinput_InitialCondition;
                           // Computed Parameter: Savedyawinput_InitialCondition
                              //  Referenced by: '<S27>/Saved yaw input'

  real32_T Checkforactivation_Threshold_d;
                           // Computed Parameter: Checkforactivation_Threshold_d
                              //  Referenced by: '<S27>/Check for activation'

  real32_T Saturation10_UpperSat;   // Computed Parameter: Saturation10_UpperSat
                                       //  Referenced by: '<S13>/Saturation10'

  real32_T Saturation10_LowerSat;   // Computed Parameter: Saturation10_LowerSat
                                       //  Referenced by: '<S13>/Saturation10'

  real32_T SavedThrustinput_InitialConditi;
                          // Computed Parameter: SavedThrustinput_InitialConditi
                             //  Referenced by: '<S26>/Saved Thrust input'

  real32_T Checkforactivation_Threshold_m;
                           // Computed Parameter: Checkforactivation_Threshold_m
                              //  Referenced by: '<S26>/Check for activation'

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
                                        //  Referenced by: '<S13>/Saturation9'

  real32_T Saturation9_LowerSat;     // Computed Parameter: Saturation9_LowerSat
                                        //  Referenced by: '<S13>/Saturation9'

  real32_T Gain_Gain_h;                // Computed Parameter: Gain_Gain_h
                                          //  Referenced by: '<S13>/Gain'

  real32_T Rollcontrolportion_Gain;
                                  // Computed Parameter: Rollcontrolportion_Gain
                                     //  Referenced by: '<S21>/Roll control portion'

  real32_T Saturation7_UpperSat_m; // Computed Parameter: Saturation7_UpperSat_m
                                      //  Referenced by: '<S14>/Saturation7'

  real32_T Saturation7_LowerSat_b; // Computed Parameter: Saturation7_LowerSat_b
                                      //  Referenced by: '<S14>/Saturation7'

  real32_T NoRudderDeflectionValue_Value;
                            // Computed Parameter: NoRudderDeflectionValue_Value
                               //  Referenced by: '<S22>/No Rudder Deflection Value'

  real32_T Switch_Threshold_j;         // Computed Parameter: Switch_Threshold_j
                                          //  Referenced by: '<S22>/Switch'

  real32_T DeflectionLogicRudderRight_Thre;
                          // Computed Parameter: DeflectionLogicRudderRight_Thre
                             //  Referenced by: '<S22>/Deflection Logic Rudder Right'

  real32_T ReverseforRudderLeft_Gain;
                                // Computed Parameter: ReverseforRudderLeft_Gain
                                   //  Referenced by: '<S22>/Reverse for Rudder Left'

  real32_T DeflectionLogicRudderLeft_Thres;
                          // Computed Parameter: DeflectionLogicRudderLeft_Thres
                             //  Referenced by: '<S22>/Deflection Logic Rudder Left'

  real32_T ControlAuthorityGain_Gain;
                                // Computed Parameter: ControlAuthorityGain_Gain
                                   //  Referenced by: '<S2>/Control Authority Gain'

  real32_T OutputLimitation_UpperSat;
                                // Computed Parameter: OutputLimitation_UpperSat
                                   //  Referenced by: '<S2>/Output Limitation'

  real32_T OutputLimitation_LowerSat;
                                // Computed Parameter: OutputLimitation_LowerSat
                                   //  Referenced by: '<S2>/Output Limitation'

};

// Real-time Model Data Structure
struct tag_RTM_controller_T {
  const char_T * volatile errorStatus;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    struct {
      uint8_T TID[2];
    } TaskCounters;

    struct {
      boolean_T TID0_1;
    } RateInteraction;
  } Timing;

  const char_T* getErrorStatus() const;
  void setErrorStatus(const char_T* const volatile aErrorStatus);
  boolean_T StepTask(int32_T idx) const;
  uint8_T &TaskCounter(int32_T idx);
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

// External function called from main
#ifdef __cplusplus

extern "C"
{

#endif

  extern void controller_SetEventsForThisBaseStep(boolean_T *eventFlags);

#ifdef __cplusplus

}

#endif

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void controller_initialize(void);
  extern void controller_step0(void);  // Sample time: [0.001s, 0.0s]
  extern void controller_step1(void);  // Sample time: [0.004s, 0.0s]
  extern void controller_step(int_T tid);
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
//  Block '<S143>/NOT' : Unused code path elimination
//  Block '<S145>/NOT' : Unused code path elimination
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
//  Block '<S147>/NOT' : Unused code path elimination
//  Block '<S4>/Bitwise Operator' : Unused code path elimination
//  Block '<S4>/Data Type Conversion' : Unused code path elimination
//  Block '<S4>/Data Type Conversion1' : Unused code path elimination
//  Block '<S4>/Data Type Conversion2' : Unused code path elimination
//  Block '<S4>/Gain' : Unused code path elimination
//  Block '<S4>/Gain1' : Unused code path elimination
//  Block '<S149>/NOT' : Unused code path elimination
//  Block '<S4>/Signal Copy7' : Unused code path elimination
//  Block '<S151>/NOT' : Unused code path elimination
//  Block '<S5>/Signal Copy' : Unused code path elimination
//  Block '<S5>/Signal Copy1' : Unused code path elimination
//  Block '<S5>/Signal Copy2' : Unused code path elimination
//  Block '<S31>/Signal Conversion' : Eliminate redundant signal conversion block
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
//  '<S31>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control'
//  '<S32>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller'
//  '<S33>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller'
//  '<S34>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Anti-windup'
//  '<S35>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/D Gain'
//  '<S36>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/External Derivative'
//  '<S37>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Filter'
//  '<S38>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Filter ICs'
//  '<S39>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/I Gain'
//  '<S40>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Ideal P Gain'
//  '<S41>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Ideal P Gain Fdbk'
//  '<S42>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Integrator'
//  '<S43>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Integrator ICs'
//  '<S44>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/N Copy'
//  '<S45>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/N Gain'
//  '<S46>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/P Copy'
//  '<S47>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Parallel P Gain'
//  '<S48>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Reset Signal'
//  '<S49>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Saturation'
//  '<S50>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Saturation Fdbk'
//  '<S51>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Sum'
//  '<S52>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Sum Fdbk'
//  '<S53>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Tracking Mode'
//  '<S54>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Tracking Mode Sum'
//  '<S55>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Tsamp - Integral'
//  '<S56>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Tsamp - Ngain'
//  '<S57>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/postSat Signal'
//  '<S58>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/preInt Signal'
//  '<S59>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/preSat Signal'
//  '<S60>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Anti-windup/Back Calculation'
//  '<S61>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/D Gain/Disabled'
//  '<S62>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/External Derivative/Disabled'
//  '<S63>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Filter/Disabled'
//  '<S64>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Filter ICs/Disabled'
//  '<S65>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/I Gain/Internal Parameters'
//  '<S66>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Ideal P Gain/Passthrough'
//  '<S67>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S68>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Integrator/Discrete'
//  '<S69>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Integrator ICs/External IC'
//  '<S70>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/N Copy/Disabled wSignal Specification'
//  '<S71>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/N Gain/Disabled'
//  '<S72>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/P Copy/Disabled'
//  '<S73>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Parallel P Gain/Internal Parameters'
//  '<S74>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Reset Signal/External Reset'
//  '<S75>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Saturation/Enabled'
//  '<S76>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Saturation Fdbk/Disabled'
//  '<S77>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Sum/Sum_PI'
//  '<S78>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Sum Fdbk/Disabled'
//  '<S79>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Tracking Mode/Disabled'
//  '<S80>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Tracking Mode Sum/Passthrough'
//  '<S81>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Tsamp - Integral/TsSignalSpecification'
//  '<S82>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/Tsamp - Ngain/Passthrough'
//  '<S83>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/postSat Signal/Forward_Path'
//  '<S84>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/preInt Signal/Internal PreInt'
//  '<S85>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Theta Control/PID Controller/preSat Signal/Forward_Path'
//  '<S86>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller'
//  '<S87>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/Anti-windup'
//  '<S88>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/D Gain'
//  '<S89>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/External Derivative'
//  '<S90>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/Filter'
//  '<S91>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/Filter ICs'
//  '<S92>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/I Gain'
//  '<S93>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/Ideal P Gain'
//  '<S94>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/Ideal P Gain Fdbk'
//  '<S95>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/Integrator'
//  '<S96>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/Integrator ICs'
//  '<S97>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/N Copy'
//  '<S98>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/N Gain'
//  '<S99>'  : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/P Copy'
//  '<S100>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/Parallel P Gain'
//  '<S101>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/Reset Signal'
//  '<S102>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/Saturation'
//  '<S103>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/Saturation Fdbk'
//  '<S104>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/Sum'
//  '<S105>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/Sum Fdbk'
//  '<S106>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/Tracking Mode'
//  '<S107>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/Tracking Mode Sum'
//  '<S108>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/Tsamp - Integral'
//  '<S109>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/Tsamp - Ngain'
//  '<S110>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/postSat Signal'
//  '<S111>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/preInt Signal'
//  '<S112>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/preSat Signal'
//  '<S113>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/Anti-windup/Back Calculation'
//  '<S114>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/D Gain/Disabled'
//  '<S115>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/External Derivative/Disabled'
//  '<S116>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/Filter/Disabled'
//  '<S117>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/Filter ICs/Disabled'
//  '<S118>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/I Gain/Internal Parameters'
//  '<S119>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/Ideal P Gain/Passthrough'
//  '<S120>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S121>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/Integrator/Discrete'
//  '<S122>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/Integrator ICs/External IC'
//  '<S123>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/N Copy/Disabled wSignal Specification'
//  '<S124>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/N Gain/Disabled'
//  '<S125>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/P Copy/Disabled'
//  '<S126>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/Parallel P Gain/Internal Parameters'
//  '<S127>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/Reset Signal/External Reset'
//  '<S128>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/Saturation/Enabled'
//  '<S129>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/Saturation Fdbk/Disabled'
//  '<S130>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/Sum/Sum_PI'
//  '<S131>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/Sum Fdbk/Disabled'
//  '<S132>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/Tracking Mode/Disabled'
//  '<S133>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/Tracking Mode Sum/Passthrough'
//  '<S134>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/Tsamp - Integral/TsSignalSpecification'
//  '<S135>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/Tsamp - Ngain/Passthrough'
//  '<S136>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/postSat Signal/Forward_Path'
//  '<S137>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/preInt Signal/Internal PreInt'
//  '<S138>' : 'controller/Flight Controller/Control logic/Flight Testing/Controller/Glide Controller/Velocity controller/PID Controller/preSat Signal/Forward_Path'
//  '<S139>' : 'controller/Flight Controller/Control logic/Flight Testing/Mode Selection - SysID/Default Deflections'
//  '<S140>' : 'controller/Flight Controller/Control logic/Flight Testing/Mode Selection - SysID/Dutch Roll Doublet'
//  '<S141>' : 'controller/Flight Controller/Control logic/Flight Testing/Mode Selection - SysID/Phugoid Doublet'
//  '<S142>' : 'controller/Flight Controller/Control logic/Flight Testing/Mode Selection - SysID/Short Period Doublet'
//  '<S143>' : 'controller/Flight Controller/Get AIrpeed/PX4 uORB Read2'
//  '<S144>' : 'controller/Flight Controller/Get AIrpeed/PX4 uORB Read2/Enabled Subsystem'
//  '<S145>' : 'controller/Flight Controller/Get Additional RC Inputs/PX4 uORB Read1'
//  '<S146>' : 'controller/Flight Controller/Get Additional RC Inputs/PX4 uORB Read1/Enabled Subsystem'
//  '<S147>' : 'controller/Gyroscope/PX4 uORB Read'
//  '<S148>' : 'controller/Gyroscope/PX4 uORB Read/Enabled Subsystem'
//  '<S149>' : 'controller/Radio Control Transmitter/PX4 uORB Read'
//  '<S150>' : 'controller/Radio Control Transmitter/PX4 uORB Read/Enabled Subsystem'
//  '<S151>' : 'controller/Vehicle Attitude/PX4 uORB Read'
//  '<S152>' : 'controller/Vehicle Attitude/PX4 uORB Read/Enabled Subsystem'

#endif                                 // controller_h_

//
// File trailer for generated code.
//
// [EOF]
//
