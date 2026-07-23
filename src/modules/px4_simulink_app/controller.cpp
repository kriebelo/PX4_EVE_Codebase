//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: controller.cpp
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
#include "controller_types.h"
#include "controller_private.h"
#include <math.h>
#include "rtwtypes.h"

extern "C"
{

#include "rt_nonfinite.h"

}

#include "rt_defines.h"

// Block signals (default storage)
B_controller_T controller_B;

// Block states (default storage)
DW_controller_T controller_DW;

// Real-time model
RT_MODEL_controller_T controller_M_ = RT_MODEL_controller_T();
RT_MODEL_controller_T *const controller_M = &controller_M_;

// Forward declaration for local functions
static void controll_PX4Actuators_setupImpl(px4_internal_block_PX4Actuato_T *obj);

// System initialize for atomic system:
void controller_PX4Timestamp_Init(DW_PX4Timestamp_controller_T *localDW)
{
  // Start for MATLABSystem: '<S31>/PX4 Timestamp'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void controller_PX4Timestamp(B_PX4Timestamp_controller_T *localB)
{
  // MATLABSystem: '<S31>/PX4 Timestamp'
  localB->PX4Timestamp = hrt_absolute_time();
}

// Termination for atomic system:
void controller_PX4Timestamp_Term(DW_PX4Timestamp_controller_T *localDW)
{
  // Terminate for MATLABSystem: '<S31>/PX4 Timestamp'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S31>/PX4 Timestamp'
}

real32_T rt_atan2f_snf(real32_T u0, real32_T u1)
{
  real32_T y;
  if (rtIsNaNF(u0) || rtIsNaNF(u1)) {
    y = (rtNaNF);
  } else if (rtIsInfF(u0) && rtIsInfF(u1)) {
    int32_T tmp;
    int32_T tmp_0;
    if (u0 > 0.0F) {
      tmp = 1;
    } else {
      tmp = -1;
    }

    if (u1 > 0.0F) {
      tmp_0 = 1;
    } else {
      tmp_0 = -1;
    }

    y = static_cast<real32_T>(atan2(static_cast<real_T>(static_cast<real32_T>
      (tmp)), static_cast<real_T>(static_cast<real32_T>(tmp_0))));
  } else if (u1 == 0.0F) {
    if (u0 > 0.0F) {
      y = RT_PIF / 2.0F;
    } else if (u0 < 0.0F) {
      y = -(RT_PIF / 2.0F);
    } else {
      y = 0.0F;
    }
  } else {
    y = static_cast<real32_T>(atan2(static_cast<real_T>(u0), static_cast<real_T>
      (u1)));
  }

  return y;
}

static void controll_PX4Actuators_setupImpl(px4_internal_block_PX4Actuato_T *obj)
{
  int32_T n;
  int32_T n_0;
  obj->ValidMotorIdx[0] = true;
  obj->ValidMotorIdx[1] = true;
  obj->ValidServoIdx[0] = true;
  obj->ValidServoIdx[5] = true;
  obj->ValidServoIdx[6] = true;
  obj->ValidServoIdx[7] = true;
  n = 0;
  for (int32_T b_k = 0; b_k < 12; b_k++) {
    // Start for MATLABSystem: '<Root>/PX4 Actuator Write'
    if (obj->ValidMotorIdx[b_k]) {
      n++;
    }
  }

  n_0 = 0;
  for (int32_T b_k = 0; b_k < 8; b_k++) {
    // Start for MATLABSystem: '<Root>/PX4 Actuator Write'
    if (obj->ValidServoIdx[b_k]) {
      n_0++;
    }
  }

  // Start for MATLABSystem: '<Root>/PX4 Actuator Write'
  obj->QSize = static_cast<uint8_T>(n + n_0);
  MW_actuators_init(obj->QSize);
}

// Model step function
void controller_step(void)
{
  real32_T numAccum;
  real32_T rtb_CastToSingle19;
  real32_T rtb_CastToSingle1_h;
  real32_T rtb_CastToSingle3;
  real32_T rtb_CastToSingle5;
  real32_T rtb_CastToSingle6;
  real32_T rtb_CastToSingle_m;
  real32_T rtb_Converttimefromustos;
  real32_T rtb_Pitch;
  real32_T rtb_Saturation;
  real32_T rtb_Thrust;
  real32_T rtb_Yaw;
  real32_T rtb_theta;
  boolean_T b_varargout_1;

  // MATLABSystem: '<S164>/SourceBlock'
  b_varargout_1 = uORB_read_step(controller_DW.obj_d.orbMetadataObj,
    &controller_DW.obj_d.eventStructObj, &controller_B.r1, false, 5000.0);

  // Outputs for Enabled SubSystem: '<S164>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S165>/Enable'

  // Start for MATLABSystem: '<S164>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S165>/In1'
    controller_B.In1_d = controller_B.r1;
  }

  // End of Outputs for SubSystem: '<S164>/Enabled Subsystem'

  // Fcn: '<S13>/Fcn1' incorporates:
  //   DataTypeConversion: '<S13>/Cast To Single1'

  controller_B.ActivationFlag = (static_cast<real32_T>
    (controller_B.In1_d.values[6]) - 1000.0F) / 500.0F;

  // Saturate: '<S13>/Saturation1'
  if (controller_B.ActivationFlag > controller_P.Saturation1_UpperSat) {
    controller_B.ActivationFlag = controller_P.Saturation1_UpperSat;
  } else if (controller_B.ActivationFlag < controller_P.Saturation1_LowerSat) {
    controller_B.ActivationFlag = controller_P.Saturation1_LowerSat;
  }

  // End of Saturate: '<S13>/Saturation1'

  // Fcn: '<S12>/Fcn5' incorporates:
  //   DataTypeConversion: '<S12>/Data Type Conversion1'

  rtb_Pitch = (static_cast<real32_T>(controller_B.In1_d.values[1]) - 1500.0F) /
    500.0F;

  // Saturate: '<S12>/Saturation8'
  if (rtb_Pitch > controller_P.Saturation8_UpperSat) {
    rtb_Pitch = controller_P.Saturation8_UpperSat;
  } else if (rtb_Pitch < controller_P.Saturation8_LowerSat) {
    rtb_Pitch = controller_P.Saturation8_LowerSat;
  }

  // End of Saturate: '<S12>/Saturation8'

  // Switch: '<S25>/Check for activation'
  if (!(controller_B.ActivationFlag > controller_P.Checkforactivation_Threshold))
  {
    // Switch: '<S25>/Check for activation'
    controller_DW.Savedpitchinput_PreviousInput = rtb_Pitch;
  }

  // End of Switch: '<S25>/Check for activation'

  // MATLABSystem: '<S166>/SourceBlock'
  b_varargout_1 = uORB_read_step(controller_DW.obj_l.orbMetadataObj,
    &controller_DW.obj_l.eventStructObj, &controller_B.r, false, 1.0);

  // Outputs for Enabled SubSystem: '<S166>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S167>/Enable'

  // Start for MATLABSystem: '<S166>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S167>/In1'
    controller_B.In1 = controller_B.r;
  }

  // End of Outputs for SubSystem: '<S166>/Enabled Subsystem'

  // MATLAB Function: '<S2>/quat2eul'
  rtb_theta = static_cast<real32_T>(asin(static_cast<real_T>
    ((controller_B.In1.q[1] * controller_B.In1.q[3] - controller_B.In1.q[0] *
      controller_B.In1.q[2]) * -2.0F)));

  // MATLABSystem: '<S154>/SourceBlock'
  b_varargout_1 = uORB_read_step(controller_DW.obj_m.orbMetadataObj,
    &controller_DW.obj_m.eventStructObj, &controller_B.r4, false, 1.0);

  // Outputs for Enabled SubSystem: '<S154>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S155>/Enable'

  // Start for MATLABSystem: '<S154>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S155>/In1'
    controller_B.In1_m = controller_B.r4;
  }

  // End of Outputs for SubSystem: '<S154>/Enabled Subsystem'

  // MATLABSystem: '<S13>/Read Parameter'
  b_varargout_1 = MW_ParamRead_Step(controller_DW.obj_n.MW_PARAMHANDLE,
    MW_SINGLE, &controller_B.ParamStep);
  if (b_varargout_1) {
    controller_B.ParamStep = 0.0F;
  }

  // MATLABSystem: '<S13>/Read Parameter1'
  b_varargout_1 = MW_ParamRead_Step(controller_DW.obj_k.MW_PARAMHANDLE,
    MW_SINGLE, &controller_B.ParamStep_k);
  if (b_varargout_1) {
    controller_B.ParamStep_k = 0.0F;
  }

  // MATLABSystem: '<S13>/Read Parameter2'
  b_varargout_1 = MW_ParamRead_Step(controller_DW.obj_ms.MW_PARAMHANDLE,
    MW_SINGLE, &controller_B.ParamStep_c);
  if (b_varargout_1) {
    controller_B.ParamStep_c = 0.0F;
  }

  // Fcn: '<S12>/Fcn6' incorporates:
  //   DataTypeConversion: '<S12>/Data Type Conversion3'

  rtb_Thrust = (static_cast<real32_T>(controller_B.In1_d.values[2]) - 1000.0F) /
    1000.0F;

  // Saturate: '<S12>/Saturation10'
  if (rtb_Thrust > controller_P.Saturation10_UpperSat) {
    rtb_Thrust = controller_P.Saturation10_UpperSat;
  } else if (rtb_Thrust < controller_P.Saturation10_LowerSat) {
    rtb_Thrust = controller_P.Saturation10_LowerSat;
  }

  // End of Saturate: '<S12>/Saturation10'

  // Switch: '<S26>/Check for activation'
  if (!(controller_B.ActivationFlag >
        controller_P.Checkforactivation_Threshold_a)) {
    // Switch: '<S26>/Check for activation'
    controller_DW.SavedThrustinput_PreviousInput = rtb_Thrust;
  }

  // End of Switch: '<S26>/Check for activation'

  // Fcn: '<S12>/Fcn7' incorporates:
  //   DataTypeConversion: '<S12>/Data Type Conversion2'

  rtb_Yaw = (static_cast<real32_T>(controller_B.In1_d.values[3]) - 1500.0F) /
    500.0F;

  // Saturate: '<S12>/Saturation7'
  if (rtb_Yaw > controller_P.Saturation7_UpperSat) {
    rtb_Yaw = controller_P.Saturation7_UpperSat;
  } else if (rtb_Yaw < controller_P.Saturation7_LowerSat) {
    rtb_Yaw = controller_P.Saturation7_LowerSat;
  }

  // End of Saturate: '<S12>/Saturation7'

  // Switch: '<S27>/Check for activation'
  if (!(controller_B.ActivationFlag >
        controller_P.Checkforactivation_Threshold_g)) {
    // Switch: '<S27>/Check for activation'
    controller_DW.Savedyawinput_PreviousInput = rtb_Yaw;
  }

  // End of Switch: '<S27>/Check for activation'

  // MATLABSystem: '<Root>/PX4 Timestamp'
  controller_B.rtb_PX4Timestamp_c = hrt_absolute_time();

  // Switch: '<S29>/Give stored time instead  of current time after activation'
  if (!(controller_B.ActivationFlag >
        controller_P.Givestoredtimeinsteadofcurrentt)) {
    // Switch: '<S29>/Give stored time instead  of current time after activation' incorporates:
    //   MATLABSystem: '<Root>/PX4 Timestamp'

    controller_DW.StoreStartTime_PreviousInput = controller_B.rtb_PX4Timestamp_c;
  }

  // End of Switch: '<S29>/Give stored time instead  of current time after activation' 

  // Gain: '<S29>/Convert time from us to s' incorporates:
  //   DataTypeConversion: '<S29>/Convert time from  uint64 to single'
  //   MATLABSystem: '<Root>/PX4 Timestamp'
  //   Sum: '<S29>/Get difference between  activation time and current time'
  //   Switch: '<S29>/Give stored time instead  of current time after activation'

  rtb_Converttimefromustos = static_cast<real32_T>
    (controller_B.rtb_PX4Timestamp_c -
     controller_DW.StoreStartTime_PreviousInput) *
    controller_P.Converttimefromustos_Gain;

  // MATLABSystem: '<S11>/Read Parameter6'
  b_varargout_1 = MW_ParamRead_Step(controller_DW.obj_pe.MW_PARAMHANDLE,
    MW_SINGLE, &controller_B.ParamStep_b);
  if (b_varargout_1) {
    controller_B.ParamStep_b = 0.0F;
  }

  // Gain: '<S11>/Gain2' incorporates:
  //   DataTypeConversion: '<S11>/Cast To Double7'
  //   MATLABSystem: '<S11>/Read Parameter6'
  //
  controller_InstP.phugoid_amp = controller_P.Gain2_Gain *
    controller_B.ParamStep_b;

  // MATLABSystem: '<S11>/Read Parameter3'
  b_varargout_1 = MW_ParamRead_Step(controller_DW.obj_f.MW_PARAMHANDLE,
    MW_SINGLE, &controller_B.ParamStep_b);
  if (b_varargout_1) {
    controller_B.ParamStep_b = 0.0F;
  }

  // Gain: '<S11>/Gain1' incorporates:
  //   DataTypeConversion: '<S11>/Cast To Double4'
  //   MATLABSystem: '<S11>/Read Parameter3'
  //
  controller_InstP.dutch_roll_amp = controller_P.Gain1_Gain_d *
    controller_B.ParamStep_b;

  // MATLABSystem: '<S11>/Read Parameter15'
  b_varargout_1 = MW_ParamRead_Step(controller_DW.obj_lg.MW_PARAMHANDLE,
    MW_SINGLE, &controller_B.ParamStep_b);
  if (b_varargout_1) {
    controller_B.ParamStep_b = 0.0F;
  }

  // ParameterWriter: '<S11>/Parameter Writer17' incorporates:
  //   MATLABSystem: '<S11>/Read Parameter15'
  //
  controller_InstP.short_period_sweep_freq_min = controller_B.ParamStep_b;

  // MATLABSystem: '<S11>/Read Parameter19'
  b_varargout_1 = MW_ParamRead_Step(controller_DW.obj_hl.MW_PARAMHANDLE,
    MW_SINGLE, &controller_B.ParamStep_p);
  if (b_varargout_1) {
    controller_B.ParamStep_p = 0.0F;
  }

  // Gain: '<S11>/Gain4' incorporates:
  //   DataTypeConversion: '<S11>/Cast To Double18'
  //   MATLABSystem: '<S11>/Read Parameter19'
  //
  controller_InstP.dutch_roll_diff_thrust_amp = controller_P.Gain4_Gain *
    controller_B.ParamStep_p;

  // MATLABSystem: '<S11>/Read Parameter'
  b_varargout_1 = MW_ParamRead_Step(controller_DW.obj_ng.MW_PARAMHANDLE,
    MW_SINGLE, &controller_B.ParamStep_p);
  if (b_varargout_1) {
    controller_B.ParamStep_p = 0.0F;
  }

  // Gain: '<S11>/Gain' incorporates:
  //   DataTypeConversion: '<S11>/Cast To Double1'
  //   MATLABSystem: '<S11>/Read Parameter'
  //
  controller_InstP.short_period_amp = controller_P.Gain_Gain_a *
    controller_B.ParamStep_p;

  // MATLABSystem: '<S11>/Read Parameter20'
  b_varargout_1 = MW_ParamRead_Step(controller_DW.obj_hd.MW_PARAMHANDLE,
    MW_SINGLE, &controller_InstP.dutch_roll_diff_thrust_period);
  if (b_varargout_1) {
    controller_InstP.dutch_roll_diff_thrust_period = 0.0F;
  }

  // MATLABSystem: '<S11>/Read Parameter5'
  b_varargout_1 = MW_ParamRead_Step(controller_DW.obj_o5.MW_PARAMHANDLE,
    MW_SINGLE, &controller_InstP.dutch_roll_dur);
  if (b_varargout_1) {
    controller_InstP.dutch_roll_dur = 0.0F;
  }

  // MATLABSystem: '<S11>/Read Parameter7'
  b_varargout_1 = MW_ParamRead_Step(controller_DW.obj_l1.MW_PARAMHANDLE,
    MW_SINGLE, &controller_B.ParamStep_p);
  if (b_varargout_1) {
    controller_B.ParamStep_p = 0.0F;
  }

  // ParameterWriter: '<S11>/Parameter Writer9' incorporates:
  //   DataTypeConversion: '<S11>/Cast To Double8'
  //   MATLABSystem: '<S11>/Read Parameter7'
  //   Product: '<S11>/Reciprocal'
  //
  controller_InstP.phugoid_period = static_cast<real32_T>(1.0 /
    controller_B.ParamStep_p);

  // MATLABSystem: '<S11>/Read Parameter16'
  b_varargout_1 = MW_ParamRead_Step(controller_DW.obj_i.MW_PARAMHANDLE,
    MW_SINGLE, &controller_B.ParamStep_cv);
  if (b_varargout_1) {
    controller_B.ParamStep_cv = 0.0F;
  }

  // ParameterWriter: '<S11>/Parameter Writer18' incorporates:
  //   MATLABSystem: '<S11>/Read Parameter16'
  //
  controller_InstP.short_period_sweep_freq_max = controller_B.ParamStep_cv;

  // MATLABSystem: '<S11>/Read Parameter18'
  b_varargout_1 = MW_ParamRead_Step(controller_DW.obj_jt.MW_PARAMHANDLE,
    MW_SINGLE, &controller_B.ParamStep_f);
  if (b_varargout_1) {
    controller_B.ParamStep_f = 0.0F;
  }

  // Gain: '<S11>/Gain3' incorporates:
  //   DataTypeConversion: '<S11>/Cast To Double17'
  //   MATLABSystem: '<S11>/Read Parameter18'
  //
  controller_B.Gain3 = controller_P.Gain3_Gain * controller_B.ParamStep_f;

  // ParameterWriter: '<S11>/Parameter Writer21'
  controller_InstP.short_period_sweep_amp = static_cast<real32_T>
    (controller_B.Gain3);

  // MATLABSystem: '<S11>/Read Parameter4'
  b_varargout_1 = MW_ParamRead_Step(controller_DW.obj_e.MW_PARAMHANDLE,
    MW_SINGLE, &controller_B.ParamStep_f);
  if (b_varargout_1) {
    controller_B.ParamStep_f = 0.0F;
  }

  // ParameterWriter: '<S11>/Parameter Writer4' incorporates:
  //   MATLABSystem: '<S11>/Read Parameter4'
  //
  controller_InstP.dutch_roll_freq = controller_B.ParamStep_f;

  // MATLABSystem: '<S11>/Read Parameter17'
  b_varargout_1 = MW_ParamRead_Step(controller_DW.obj_a.MW_PARAMHANDLE,
    MW_SINGLE, &controller_P.Setendtimeofdoublet_Threshold);
  if (b_varargout_1) {
    // Switch: '<S152>/Set end time of doublet'
    controller_P.Setendtimeofdoublet_Threshold = 0.0F;
  }

  // ParameterWriter: '<S11>/Parameter Writer20' incorporates:
  //   Constant: '<S153>/Constant'
  //   MATLABSystem: '<S11>/Read Parameter17'
  //
  controller_P.Constant_Value_l = controller_P.Setendtimeofdoublet_Threshold;

  // MATLABSystem: '<S11>/Read Parameter1'
  b_varargout_1 = MW_ParamRead_Step(controller_DW.obj_ah.MW_PARAMHANDLE,
    MW_SINGLE, &controller_B.ParamStep_g);
  if (b_varargout_1) {
    controller_B.ParamStep_g = 0.0F;
  }

  // ParameterWriter: '<S11>/Parameter Writer11' incorporates:
  //   DataTypeConversion: '<S11>/Cast To Double2'
  //   MATLABSystem: '<S11>/Read Parameter1'
  //   Product: '<S11>/Reciprocal2'
  //
  controller_InstP.short_period_period = static_cast<real32_T>(1.0 /
    controller_B.ParamStep_g);

  // ParameterWriter: '<S11>/Parameter Writer7' incorporates:
  //   MATLABSystem: '<S11>/Read Parameter7'
  //
  controller_InstP.phugoid_freq = controller_B.ParamStep_p;

  // MATLABSystem: '<S11>/Read Parameter8'
  b_varargout_1 = MW_ParamRead_Step(controller_DW.obj_p.MW_PARAMHANDLE,
    MW_SINGLE, &controller_InstP.phugoid_dur);
  if (b_varargout_1) {
    controller_InstP.phugoid_dur = 0.0F;
  }

  // ParameterWriter: '<S11>/Parameter Writer10' incorporates:
  //   DataTypeConversion: '<S11>/Cast To Double5'
  //   MATLABSystem: '<S11>/Read Parameter4'
  //   Product: '<S11>/Reciprocal1'
  //
  controller_InstP.dutch_roll_period = static_cast<real32_T>(1.0 /
    controller_B.ParamStep_f);

  // MATLABSystem: '<S11>/Read Parameter2'
  b_varargout_1 = MW_ParamRead_Step(controller_DW.obj_j.MW_PARAMHANDLE,
    MW_SINGLE, &controller_InstP.short_period_dur);
  if (b_varargout_1) {
    controller_InstP.short_period_dur = 0.0F;
  }

  // ParameterWriter: '<S11>/Parameter Writer1' incorporates:
  //   MATLABSystem: '<S11>/Read Parameter1'
  //
  controller_InstP.short_period_freq = controller_B.ParamStep_g;

  // If: '<S19>/Activate different control logics after activation flag is triggered' incorporates:
  //   MATLABSystem: '<S13>/Read Parameter2'
  //
  if ((controller_B.ActivationFlag > 0.5F) && (controller_B.ParamStep_c < 4.5F))
  {
    // Outputs for IfAction SubSystem: '<S19>/Mode Selection - SysID' incorporates:
    //   ActionPort: '<S28>/Action Port'

    // If: '<S28>/Set if condition for mode to be chosen'
    if ((controller_B.ParamStep_c >= -0.5F) && (controller_B.ParamStep_c < 0.5F))
    {
      // Outputs for IfAction SubSystem: '<S28>/Short Period Doublet' incorporates:
      //   ActionPort: '<S151>/Action Port'

      // Switch: '<S151>/Set time to re-allow  pilot inputs'
      if (!(rtb_Converttimefromustos > controller_InstP.short_period_dur)) {
        // Switch: '<S151>/Set end time of doublet' incorporates:
        //   DataTypeConversion: '<S151>/Cast To Single'
        //   SignalGenerator: '<S151>/Doublet Generator'
        //   Sum: '<S151>/Sum Initial Pitch Input  and Doublet Wave'

        if (rtb_Converttimefromustos >= controller_InstP.short_period_period) {
          rtb_Pitch = controller_DW.Savedpitchinput_PreviousInput;
        } else {
          // SignalGenerator: '<S151>/Doublet Generator' incorporates:
          //   DataTypeConversion: '<S151>/Cast To Double'

          controller_B.Gain2_g = controller_InstP.short_period_freq *
            rtb_Converttimefromustos;
          if (controller_B.Gain2_g - floor(controller_B.Gain2_g) >= 0.5) {
            controller_B.Gain2_g = controller_InstP.short_period_amp;
          } else {
            controller_B.Gain2_g = -controller_InstP.short_period_amp;
          }

          rtb_Pitch = controller_DW.Savedpitchinput_PreviousInput + static_cast<
            real32_T>(controller_B.Gain2_g);
        }

        // End of Switch: '<S151>/Set end time of doublet'
      }

      // End of Switch: '<S151>/Set time to re-allow  pilot inputs'

      // SignalConversion: '<S28>/Signal Conversion7' incorporates:
      //   Merge: '<S28>/Merge2'
      //   SignalConversion: '<S151>/Signal Conversion'

      rtb_Converttimefromustos = rtb_Thrust;

      // End of Outputs for SubSystem: '<S28>/Short Period Doublet'
    } else if ((controller_B.ParamStep_c >= 0.5F) && (controller_B.ParamStep_c <
                1.5F)) {
      // Outputs for IfAction SubSystem: '<S28>/Short Period Sine Sweep' incorporates:
      //   ActionPort: '<S152>/Action Port'

      // Switch: '<S152>/Set end time of doublet' incorporates:
      //   Constant: '<S153>/Constant'
      //   Constant: '<S153>/Constant1'
      //   Constant: '<S153>/Constant2'
      //   Constant: '<S153>/Constant3'
      //   DataTypeConversion: '<S152>/Cast To Single'
      //   Gain: '<S152>/Gain'
      //   Gain: '<S153>/Gain1'
      //   Product: '<S153>/Product'
      //   Product: '<S153>/Product1'
      //   Product: '<S153>/Product2'
      //   Product: '<S153>/Reciprocal'
      //   Sum: '<S152>/Sum Initial Pitch Input  and Doublet Wave'
      //   Sum: '<S153>/Add'
      //   Sum: '<S153>/Add1'
      //   Trigonometry: '<S153>/Sin'

      if (!(rtb_Converttimefromustos >=
            controller_P.Setendtimeofdoublet_Threshold)) {
        rtb_Pitch = static_cast<real32_T>(sin((1.0 /
          controller_P.Constant_Value_l *
          (controller_InstP.short_period_sweep_freq_max -
           controller_InstP.short_period_sweep_freq_min) *
          controller_P.Constant1_Value * rtb_Converttimefromustos +
          controller_InstP.short_period_sweep_freq_min) *
          (controller_P.Gain1_Gain_o * rtb_Converttimefromustos))) *
          controller_InstP.short_period_sweep_amp +
          controller_DW.Savedpitchinput_PreviousInput;
      }

      // End of Switch: '<S152>/Set end time of doublet'

      // SignalConversion: '<S28>/Signal Conversion7' incorporates:
      //   Merge: '<S28>/Merge2'
      //   SignalConversion: '<S152>/Signal Conversion'

      rtb_Converttimefromustos = rtb_Thrust;

      // End of Outputs for SubSystem: '<S28>/Short Period Sine Sweep'
    } else if ((controller_B.ParamStep_c >= 1.5F) && (controller_B.ParamStep_c <
                2.5F)) {
      // Outputs for IfAction SubSystem: '<S28>/Dutch Roll Doublet' incorporates:
      //   ActionPort: '<S148>/Action Port'

      // Switch: '<S148>/Set time to re-allow  pilot inputs'
      if (!(rtb_Converttimefromustos > controller_InstP.dutch_roll_dur)) {
        // Switch: '<S148>/Switch1'
        if (rtb_Converttimefromustos > controller_InstP.dutch_roll_period) {
          // DataTypeConversion: '<S148>/Cast To Single1'
          rtb_Yaw = controller_DW.Savedyawinput_PreviousInput;
        } else {
          // SignalGenerator: '<S148>/Doublet Generator' incorporates:
          //   DataTypeConversion: '<S148>/Cast To Double'

          controller_B.Gain2_g = controller_InstP.dutch_roll_freq *
            rtb_Converttimefromustos;
          if (controller_B.Gain2_g - floor(controller_B.Gain2_g) >= 0.5) {
            controller_B.Gain2_g = controller_InstP.dutch_roll_amp;
          } else {
            controller_B.Gain2_g = -controller_InstP.dutch_roll_amp;
          }

          // DataTypeConversion: '<S148>/Cast To Single1' incorporates:
          //   DataTypeConversion: '<S148>/Cast To Single'
          //   SignalGenerator: '<S148>/Doublet Generator'
          //   Sum: '<S148>/Sum Initial Yaw Input  and Doublet Wave'

          rtb_Yaw = controller_DW.Savedyawinput_PreviousInput +
            static_cast<real32_T>(controller_B.Gain2_g);
        }

        // End of Switch: '<S148>/Switch1'
      }

      // End of Switch: '<S148>/Set time to re-allow  pilot inputs'

      // SignalConversion: '<S28>/Signal Conversion7' incorporates:
      //   Merge: '<S28>/Merge2'
      //   SignalConversion: '<S148>/Signal Conversion'

      rtb_Converttimefromustos = rtb_Thrust;

      // End of Outputs for SubSystem: '<S28>/Dutch Roll Doublet'
    } else if ((controller_B.ParamStep_c >= 2.5F) && (controller_B.ParamStep_c <
                3.5F)) {
      // Outputs for IfAction SubSystem: '<S28>/Dutch Roll Thrust 3211' incorporates:
      //   ActionPort: '<S149>/Action Port'

      // Switch: '<S149>/Switch3' incorporates:
      //   Gain: '<S149>/Gain3'
      //   Gain: '<S149>/Gain4'
      //   Gain: '<S149>/Gain5'
      //   Gain: '<S149>/Gain6'
      //   Gain: '<S149>/Gain7'
      //   Switch: '<S149>/Switch'
      //   Switch: '<S149>/Switch1'
      //   Switch: '<S149>/Switch2'
      //   Switch: '<S149>/Switch5'

      if (controller_P.Gain7_Gain * rtb_Converttimefromustos >
          controller_InstP.dutch_roll_diff_thrust_period) {
        // SignalConversion: '<S28>/Signal Conversion7' incorporates:
        //   Merge: '<S28>/Merge2'

        rtb_Converttimefromustos = rtb_Thrust;
      } else {
        if (controller_P.Gain6_Gain * rtb_Converttimefromustos >
            controller_InstP.dutch_roll_diff_thrust_period) {
          // Switch: '<S149>/Switch5' incorporates:
          //   Constant: '<S149>/Constant3'

          controller_B.Gain2_g = controller_P.Constant3_Value;
        } else if (controller_P.Gain5_Gain * rtb_Converttimefromustos >
                   controller_InstP.dutch_roll_diff_thrust_period) {
          // Switch: '<S149>/Switch2' incorporates:
          //   Constant: '<S149>/Constant1'
          //   Switch: '<S149>/Switch5'

          controller_B.Gain2_g = controller_P.Constant1_Value_i;
        } else if (controller_P.Gain4_Gain_m * rtb_Converttimefromustos >
                   controller_InstP.dutch_roll_diff_thrust_period) {
          // Switch: '<S149>/Switch1' incorporates:
          //   Constant: '<S149>/Constant'
          //   Switch: '<S149>/Switch2'
          //   Switch: '<S149>/Switch5'

          controller_B.Gain2_g = controller_P.Constant_Value_o;
        } else if (controller_P.Gain3_Gain_n * rtb_Converttimefromustos >
                   controller_InstP.dutch_roll_diff_thrust_period) {
          // Switch: '<S149>/Switch' incorporates:
          //   Constant: '<S149>/Constant1'
          //   Switch: '<S149>/Switch1'
          //   Switch: '<S149>/Switch2'
          //   Switch: '<S149>/Switch5'

          controller_B.Gain2_g = controller_P.Constant1_Value_i;
        } else {
          // Switch: '<S149>/Switch5' incorporates:
          //   Constant: '<S149>/Constant'

          controller_B.Gain2_g = controller_P.Constant_Value_o;
        }

        // Gain: '<S149>/Gain2' incorporates:
        //   Gain: '<S149>/Gain3'
        //   Gain: '<S149>/Gain4'
        //   Gain: '<S149>/Gain5'
        //   Switch: '<S149>/Switch'
        //   Switch: '<S149>/Switch1'
        //   Switch: '<S149>/Switch2'
        //   Switch: '<S149>/Switch5'

        controller_B.Gain2_g *= controller_InstP.dutch_roll_diff_thrust_amp;

        // SignalConversion: '<S28>/Signal Conversion7' incorporates:
        //   DataTypeConversion: '<S149>/Cast To Single1'
        //   DataTypeConversion: '<S149>/Cast To Single2'
        //   Gain: '<S149>/Gain'
        //   Gain: '<S149>/Gain1'
        //   Merge: '<S28>/Merge2'
        //   Sum: '<S149>/Add'
        //   Sum: '<S149>/Add1'

        rtb_Thrust = static_cast<real32_T>(controller_P.Gain1_Gain *
          controller_B.Gain2_g + controller_DW.SavedThrustinput_PreviousInput);
        rtb_Converttimefromustos = static_cast<real32_T>(controller_P.Gain_Gain *
          controller_B.Gain2_g + controller_DW.SavedThrustinput_PreviousInput);
      }

      // End of Switch: '<S149>/Switch3'
      // End of Outputs for SubSystem: '<S28>/Dutch Roll Thrust 3211'
    } else if (controller_B.ParamStep_c >= 3.5F) {
      // Outputs for IfAction SubSystem: '<S28>/Phugoid Doublet' incorporates:
      //   ActionPort: '<S150>/Action Port'

      // Switch: '<S150>/Set time to re-allow  pilot inputs'
      if (!(rtb_Converttimefromustos > controller_InstP.phugoid_dur)) {
        // Switch: '<S150>/Switch1' incorporates:
        //   DataTypeConversion: '<S150>/Cast To Single'
        //   SignalGenerator: '<S150>/Doublet Generator'
        //   Sum: '<S150>/Sum Initial Thrust Input  and Doublet Wave'

        if (rtb_Converttimefromustos > controller_InstP.phugoid_period) {
          rtb_Thrust = controller_DW.SavedThrustinput_PreviousInput;
        } else {
          // SignalGenerator: '<S150>/Doublet Generator' incorporates:
          //   DataTypeConversion: '<S150>/Cast To Double'

          controller_B.Gain2_g = controller_InstP.phugoid_freq *
            rtb_Converttimefromustos;
          if (controller_B.Gain2_g - floor(controller_B.Gain2_g) >= 0.5) {
            controller_B.Gain2_g = controller_InstP.phugoid_amp;
          } else {
            controller_B.Gain2_g = -controller_InstP.phugoid_amp;
          }

          rtb_Thrust = controller_DW.SavedThrustinput_PreviousInput +
            static_cast<real32_T>(controller_B.Gain2_g);
        }

        // End of Switch: '<S150>/Switch1'
      }

      // End of Switch: '<S150>/Set time to re-allow  pilot inputs'

      // SignalConversion: '<S28>/Signal Conversion7' incorporates:
      //   Merge: '<S28>/Merge2'
      //   SignalConversion: '<S150>/Signal Conversion'

      rtb_Converttimefromustos = rtb_Thrust;

      // End of Outputs for SubSystem: '<S28>/Phugoid Doublet'
    } else {
      // Outputs for IfAction SubSystem: '<S28>/Default Deflections' incorporates:
      //   ActionPort: '<S147>/Action Port'

      // SignalConversion: '<S28>/Signal Conversion7' incorporates:
      //   Merge: '<S28>/Merge2'
      //   SignalConversion: '<S147>/Signal Conversion'

      rtb_Converttimefromustos = rtb_Thrust;

      // End of Outputs for SubSystem: '<S28>/Default Deflections'
    }

    // End of If: '<S28>/Set if condition for mode to be chosen'
    // End of Outputs for SubSystem: '<S19>/Mode Selection - SysID'
  } else {
    // Outputs for IfAction SubSystem: '<S19>/Default Deflections' incorporates:
    //   ActionPort: '<S24>/Action Port'

    // SignalConversion: '<S24>/Signal Conversion1'
    rtb_Converttimefromustos = rtb_Thrust;

    // End of Outputs for SubSystem: '<S19>/Default Deflections'
  }

  // End of If: '<S19>/Activate different control logics after activation flag is triggered' 

  // MATLABSystem: '<S11>/Read Parameter9'
  b_varargout_1 = MW_ParamRead_Step(controller_DW.obj_mf.MW_PARAMHANDLE,
    MW_SINGLE, &controller_InstP.pitch_con_gain_i);
  if (b_varargout_1) {
    controller_InstP.pitch_con_gain_i = 0.0F;
  }

  // MATLABSystem: '<S11>/Read Parameter14'
  b_varargout_1 = MW_ParamRead_Step(controller_DW.obj_lx.MW_PARAMHANDLE,
    MW_SINGLE, &controller_InstP.vel_lp_freq);
  if (b_varargout_1) {
    controller_InstP.vel_lp_freq = 0.0F;
  }

  // MATLABSystem: '<S11>/Read Parameter12'
  b_varargout_1 = MW_ParamRead_Step(controller_DW.obj_gx.MW_PARAMHANDLE,
    MW_SINGLE, &controller_InstP.vel_con_gain_p);
  if (b_varargout_1) {
    controller_InstP.vel_con_gain_p = 0.0F;
  }

  // MATLABSystem: '<S11>/Read Parameter10'
  b_varargout_1 = MW_ParamRead_Step(controller_DW.obj_bg.MW_PARAMHANDLE,
    MW_SINGLE, &controller_InstP.pitch_con_gain_p);
  if (b_varargout_1) {
    controller_InstP.pitch_con_gain_p = 0.0F;
  }

  // MATLABSystem: '<S11>/Read Parameter11'
  b_varargout_1 = MW_ParamRead_Step(controller_DW.obj_i4.MW_PARAMHANDLE,
    MW_SINGLE, &controller_InstP.vel_con_gain_i);
  if (b_varargout_1) {
    controller_InstP.vel_con_gain_i = 0.0F;
  }

  // Outputs for Atomic SubSystem: '<S19>/Controller'
  // Switch: '<S23>/Switch3' incorporates:
  //   MATLABSystem: '<S13>/Read Parameter2'
  //
  if (controller_B.ParamStep_c > controller_P.Switch3_Threshold) {
    // Switch: '<S23>/Switch2' incorporates:
    //   Constant: '<S23>/Constant'

    if (controller_B.ActivationFlag > controller_P.Switch2_Threshold) {
      rtb_Thrust = controller_P.Constant_Value_k2;
      rtb_Converttimefromustos = controller_P.Constant_Value_k2;
    }

    // End of Switch: '<S23>/Switch2'
  }

  // End of Switch: '<S23>/Switch3'
  controller_PX4Timestamp(&controller_B.PX4Timestamp_o);

  // Gain: '<S35>/Gain' incorporates:
  //   Constant: '<S35>/Constant'

  rtb_CastToSingle_m = controller_P.Gain_Gain_m * controller_InstP.vel_lp_freq;

  // DiscreteFilter: '<S35>/Discrete Filter1' incorporates:
  //   Bias: '<S35>/Bias'
  //   Constant: '<S35>/Constant1'
  //   SignalConversion generated from: '<S35>/Vector Concatenate'

  rtb_CastToSingle1_h = controller_B.In1_m.true_airspeed_m_s -
    (rtb_CastToSingle_m + controller_P.Bias_Bias) *
    controller_DW.DiscreteFilter1_states;
  numAccum = controller_P.Constant1_Value_ii * rtb_CastToSingle1_h +
    rtb_CastToSingle_m * controller_DW.DiscreteFilter1_states;

  // Sum: '<S35>/Sum' incorporates:
  //   DiscreteFilter: '<S35>/Discrete Filter1'
  //   MATLABSystem: '<S13>/Read Parameter1'
  //
  rtb_CastToSingle_m = controller_B.ParamStep_k - numAccum;

  // DiscreteIntegrator: '<S127>/Integrator'
  if (controller_DW.Integrator_IC_LOADING != 0) {
    controller_DW.Integrator_DSTATE = rtb_theta;
  }

  if ((controller_B.ActivationFlag > 0.0F) &&
      (controller_DW.Integrator_PrevResetState <= 0)) {
    controller_DW.Integrator_DSTATE = rtb_theta;
  }

  // Sum: '<S136>/Sum' incorporates:
  //   DiscreteIntegrator: '<S127>/Integrator'
  //   Gain: '<S132>/Proportional Gain'

  rtb_CastToSingle3 = controller_InstP.vel_con_gain_p * rtb_CastToSingle_m +
    controller_DW.Integrator_DSTATE;

  // Saturate: '<S134>/Saturation'
  if (rtb_CastToSingle3 > controller_P.PIDController_UpperSaturationLi) {
    rtb_CastToSingle5 = controller_P.PIDController_UpperSaturationLi;
  } else if (rtb_CastToSingle3 < controller_P.PIDController_LowerSaturationLi) {
    rtb_CastToSingle5 = controller_P.PIDController_LowerSaturationLi;
  } else {
    rtb_CastToSingle5 = rtb_CastToSingle3;
  }

  // End of Saturate: '<S134>/Saturation'

  // Switch: '<S30>/Switch' incorporates:
  //   Gain: '<S18>/Gain1'
  //   MATLABSystem: '<S13>/Read Parameter'
  //   MATLABSystem: '<S13>/Read Parameter2'
  //
  if (controller_B.ParamStep_c > controller_P.Switch_Threshold_e) {
    rtb_CastToSingle6 = rtb_CastToSingle5;
  } else {
    rtb_CastToSingle6 = controller_P.Gain1_Gain_g * controller_B.ParamStep;
  }

  // End of Switch: '<S30>/Switch'

  // Sum: '<S34>/Sum'
  controller_B.ParamStep = rtb_CastToSingle6 - rtb_theta;

  // DiscreteIntegrator: '<S73>/Integrator'
  if (controller_DW.Integrator_IC_LOADING_e != 0) {
    controller_DW.Integrator_DSTATE_a =
      controller_DW.Savedpitchinput_PreviousInput;
  }

  if (((controller_B.ActivationFlag > 0.0F) &&
       (controller_DW.Integrator_PrevResetState_f <= 0)) ||
      ((controller_B.ActivationFlag <= 0.0F) &&
       (controller_DW.Integrator_PrevResetState_f == 1))) {
    controller_DW.Integrator_DSTATE_a =
      controller_DW.Savedpitchinput_PreviousInput;
  }

  // Sum: '<S82>/Sum' incorporates:
  //   DiscreteIntegrator: '<S73>/Integrator'
  //   Gain: '<S78>/Proportional Gain'

  rtb_CastToSingle19 = controller_InstP.pitch_con_gain_p *
    controller_B.ParamStep + controller_DW.Integrator_DSTATE_a;

  // Saturate: '<S80>/Saturation'
  if (rtb_CastToSingle19 > controller_P.PIDController_UpperSaturation_o) {
    rtb_Saturation = controller_P.PIDController_UpperSaturation_o;
  } else if (rtb_CastToSingle19 < controller_P.PIDController_LowerSaturation_m)
  {
    rtb_Saturation = controller_P.PIDController_LowerSaturation_m;
  } else {
    rtb_Saturation = rtb_CastToSingle19;
  }

  // End of Saturate: '<S80>/Saturation'

  // BusAssignment: '<S31>/Bus Assignment' incorporates:
  //   Constant: '<S13>/Constant6'
  //   Gain: '<S30>/Gain'
  //   Gain: '<S32>/Gain'
  //   Gain: '<S33>/Gain'
  //   MATLABSystem: '<S13>/Read Parameter1'
  //   MATLABSystem: '<S13>/Read Parameter2'
  //   MATLABSystem: '<S31>/PX4 Timestamp'
  //
  controller_B.BusAssignment_k.timestamp =
    controller_B.PX4Timestamp_o.PX4Timestamp;
  controller_B.BusAssignment_k.activation_flag = controller_B.ActivationFlag;
  controller_B.BusAssignment_k.mode_selector = controller_B.ParamStep_c;
  controller_B.BusAssignment_k.test_mode_selector = controller_P.Constant6_Value;
  controller_B.BusAssignment_k.elevator_cmd = controller_P.Gain_Gain_mm *
    rtb_Saturation;
  controller_B.BusAssignment_k.pitch_angle = controller_P.Gain_Gain_i *
    rtb_theta;
  controller_B.BusAssignment_k.pitch_angle_cmd = controller_P.Gain_Gain_ax *
    rtb_CastToSingle6;
  controller_B.BusAssignment_k.airspeed = controller_B.In1_m.true_airspeed_m_s;
  controller_B.BusAssignment_k.airspeed_cmd = controller_B.ParamStep_k;

  // MATLABSystem: '<S37>/SinkBlock' incorporates:
  //   BusAssignment: '<S31>/Bus Assignment'

  uORB_write_step(controller_DW.obj_mu.orbMetadataObj,
                  &controller_DW.obj_mu.orbAdvertiseObj,
                  &controller_B.BusAssignment_k);
  controller_PX4Timestamp(&controller_B.PX4Timestamp_h);

  // BusAssignment: '<S92>/Bus Assignment' incorporates:
  //   DiscreteFilter: '<S35>/Discrete Filter1'
  //   MATLABSystem: '<S92>/PX4 Timestamp'

  controller_B.BusAssignment_b.timestamp =
    controller_B.PX4Timestamp_h.PX4Timestamp;
  controller_B.BusAssignment_b.v_raw = controller_B.In1_m.true_airspeed_m_s;
  controller_B.BusAssignment_b.v_filtered = numAccum;

  // MATLABSystem: '<S146>/SinkBlock' incorporates:
  //   BusAssignment: '<S92>/Bus Assignment'

  uORB_write_step(controller_DW.obj_b.orbMetadataObj,
                  &controller_DW.obj_b.orbAdvertiseObj,
                  &controller_B.BusAssignment_b);

  // Update for DiscreteFilter: '<S35>/Discrete Filter1'
  controller_DW.DiscreteFilter1_states = rtb_CastToSingle1_h;

  // Update for DiscreteIntegrator: '<S127>/Integrator' incorporates:
  //   DiscreteIntegrator: '<S73>/Integrator'
  //   Gain: '<S119>/Kb'
  //   Gain: '<S124>/Integral Gain'
  //   Sum: '<S119>/SumI2'
  //   Sum: '<S119>/SumI4'

  controller_DW.Integrator_IC_LOADING = 0U;
  controller_DW.Integrator_DSTATE += ((rtb_CastToSingle5 - rtb_CastToSingle3) *
    controller_P.PIDController_Kb_c + controller_InstP.vel_con_gain_i *
    rtb_CastToSingle_m) * controller_P.Integrator_gainval;
  if (controller_B.ActivationFlag > 0.0F) {
    controller_DW.Integrator_PrevResetState = 1;
    controller_DW.Integrator_PrevResetState_f = 1;
  } else if (controller_B.ActivationFlag < 0.0F) {
    controller_DW.Integrator_PrevResetState = -1;
    controller_DW.Integrator_PrevResetState_f = -1;
  } else if (controller_B.ActivationFlag == 0.0F) {
    controller_DW.Integrator_PrevResetState = 0;
    controller_DW.Integrator_PrevResetState_f = 0;
  } else {
    controller_DW.Integrator_PrevResetState = 2;
    controller_DW.Integrator_PrevResetState_f = 2;
  }

  // End of Update for DiscreteIntegrator: '<S127>/Integrator'

  // Update for DiscreteIntegrator: '<S73>/Integrator' incorporates:
  //   Gain: '<S65>/Kb'
  //   Gain: '<S70>/Integral Gain'
  //   Sum: '<S65>/SumI2'
  //   Sum: '<S65>/SumI4'

  controller_DW.Integrator_IC_LOADING_e = 0U;
  controller_DW.Integrator_DSTATE_a += ((rtb_Saturation - rtb_CastToSingle19) *
    controller_P.PIDController_Kb + controller_InstP.pitch_con_gain_i *
    controller_B.ParamStep) * controller_P.Integrator_gainval_i;

  // Switch: '<S23>/Switch1' incorporates:
  //   MATLABSystem: '<S13>/Read Parameter2'
  //
  if (controller_B.ParamStep_c > controller_P.Switch1_Threshold) {
    // Switch: '<S23>/Switch'
    if (controller_B.ActivationFlag > controller_P.Switch_Threshold) {
      rtb_Pitch = rtb_Saturation;
    }

    // End of Switch: '<S23>/Switch'
  }

  // Gain: '<S21>/Pitch control portion' incorporates:
  //   Switch: '<S23>/Switch1'

  rtb_CastToSingle_m = controller_P.Pitchcontrolportion_Gain * rtb_Pitch;

  // End of Outputs for SubSystem: '<S19>/Controller'

  // Fcn: '<S12>/Fcn2' incorporates:
  //   DataTypeConversion: '<S12>/Data Type Conversion'

  rtb_CastToSingle3 = (static_cast<real32_T>(controller_B.In1_d.values[0]) -
                       1500.0F) / 500.0F;

  // Saturate: '<S12>/Saturation9'
  if (rtb_CastToSingle3 > controller_P.Saturation9_UpperSat) {
    rtb_CastToSingle3 = controller_P.Saturation9_UpperSat;
  } else if (rtb_CastToSingle3 < controller_P.Saturation9_LowerSat) {
    rtb_CastToSingle3 = controller_P.Saturation9_LowerSat;
  }

  // Gain: '<S21>/Roll control portion' incorporates:
  //   Gain: '<S12>/Gain'
  //   Saturate: '<S12>/Saturation9'

  rtb_Pitch = controller_P.Gain_Gain_h * rtb_CastToSingle3 *
    controller_P.Rollcontrolportion_Gain;

  // Sum: '<S21>/Add Elevon Left'
  controller_B.ParamStep_k = rtb_Pitch - rtb_CastToSingle_m;

  // Sum: '<S21>/Add Elevon Right'
  rtb_Pitch = (0.0F - rtb_Pitch) - rtb_CastToSingle_m;

  // Fcn: '<S13>/Fcn7' incorporates:
  //   DataTypeConversion: '<S13>/Cast To Single'

  rtb_CastToSingle3 = (static_cast<real32_T>(controller_B.In1_d.values[5]) -
                       1000.0F) / 500.0F;

  // Saturate: '<S13>/Saturation7'
  if (rtb_CastToSingle3 > controller_P.Saturation7_UpperSat_m) {
    rtb_CastToSingle3 = controller_P.Saturation7_UpperSat_m;
  } else if (rtb_CastToSingle3 < controller_P.Saturation7_LowerSat_b) {
    rtb_CastToSingle3 = controller_P.Saturation7_LowerSat_b;
  }

  // Switch: '<S22>/Switch' incorporates:
  //   Constant: '<S22>/No Rudder Deflection Value'
  //   Constant: '<S22>/Spoiler Rudder Deflection Value'
  //   Saturate: '<S13>/Saturation7'

  if (rtb_CastToSingle3 > controller_P.Switch_Threshold_n) {
    rtb_CastToSingle1_h = controller_P.SpoilerRudderDeflectionValue_Va;
  } else {
    rtb_CastToSingle1_h = controller_P.NoRudderDeflectionValue_Value;
  }

  // End of Switch: '<S22>/Switch'

  // Switch: '<S22>/Deflection Logic Rudder Right' incorporates:
  //   Constant: '<S22>/No Rudder Deflection Value'

  if (rtb_Yaw > controller_P.DeflectionLogicRudderRight_Thre) {
    rtb_CastToSingle_m = rtb_Yaw;
  } else {
    rtb_CastToSingle_m = controller_P.NoRudderDeflectionValue_Value;
  }

  // Fcn: '<S22>/Function for Deflection Value Rudder Right' incorporates:
  //   Sum: '<S22>/Add'
  //   Switch: '<S22>/Deflection Logic Rudder Right'

  rtb_CastToSingle_m = ((rtb_CastToSingle_m + rtb_CastToSingle1_h) - 0.5F) *
    2.0F;

  // Gain: '<S22>/Reverse for Rudder Left'
  rtb_Yaw *= controller_P.ReverseforRudderLeft_Gain;

  // Switch: '<S22>/Deflection Logic Rudder Left' incorporates:
  //   Constant: '<S22>/No Rudder Deflection Value'

  if (!(rtb_Yaw > controller_P.DeflectionLogicRudderLeft_Thres)) {
    rtb_Yaw = controller_P.NoRudderDeflectionValue_Value;
  }

  // Fcn: '<S22>/Function for Deflection Value Rudder Left' incorporates:
  //   Sum: '<S22>/Add1'
  //   Switch: '<S22>/Deflection Logic Rudder Left'

  rtb_CastToSingle1_h = ((rtb_CastToSingle1_h + rtb_Yaw) - 0.5F) * 2.0F;

  // Gain: '<S2>/Control Authority Gain'
  rtb_CastToSingle3 = controller_P.ControlAuthorityGain_Gain *
    controller_B.ParamStep_k;
  rtb_Yaw = controller_P.ControlAuthorityGain_Gain * rtb_Pitch;

  // MATLABSystem: '<Root>/PX4 Actuator Write'
  for (controller_B.ParamStep_g1 = 0; controller_B.ParamStep_g1 < 12;
       controller_B.ParamStep_g1++) {
    controller_B.motorValues[controller_B.ParamStep_g1] = (rtNaNF);
  }

  for (controller_B.ParamStep_g1 = 0; controller_B.ParamStep_g1 < 8;
       controller_B.ParamStep_g1++) {
    controller_B.servoValues[controller_B.ParamStep_g1] = (rtNaNF);
  }

  // Saturate: '<S2>/Output Limitation'
  if (rtb_Thrust > controller_P.OutputLimitation_UpperSat) {
    // MATLABSystem: '<Root>/PX4 Actuator Write'
    controller_B.motorValues[0] = controller_P.OutputLimitation_UpperSat;
  } else if (rtb_Thrust < controller_P.OutputLimitation_LowerSat) {
    // MATLABSystem: '<Root>/PX4 Actuator Write'
    controller_B.motorValues[0] = controller_P.OutputLimitation_LowerSat;
  } else {
    // MATLABSystem: '<Root>/PX4 Actuator Write'
    controller_B.motorValues[0] = rtb_Thrust;
  }

  if (rtb_Converttimefromustos > controller_P.OutputLimitation_UpperSat) {
    // MATLABSystem: '<Root>/PX4 Actuator Write'
    controller_B.motorValues[1] = controller_P.OutputLimitation_UpperSat;
  } else if (rtb_Converttimefromustos < controller_P.OutputLimitation_LowerSat)
  {
    // MATLABSystem: '<Root>/PX4 Actuator Write'
    controller_B.motorValues[1] = controller_P.OutputLimitation_LowerSat;
  } else {
    // MATLABSystem: '<Root>/PX4 Actuator Write'
    controller_B.motorValues[1] = rtb_Converttimefromustos;
  }

  if (rtb_CastToSingle3 > controller_P.OutputLimitation_UpperSat) {
    // MATLABSystem: '<Root>/PX4 Actuator Write'
    controller_B.servoValues[0] = controller_P.OutputLimitation_UpperSat;
  } else if (rtb_CastToSingle3 < controller_P.OutputLimitation_LowerSat) {
    // MATLABSystem: '<Root>/PX4 Actuator Write'
    controller_B.servoValues[0] = controller_P.OutputLimitation_LowerSat;
  } else {
    // MATLABSystem: '<Root>/PX4 Actuator Write'
    controller_B.servoValues[0] = rtb_CastToSingle3;
  }

  if (rtb_Yaw > controller_P.OutputLimitation_UpperSat) {
    // MATLABSystem: '<Root>/PX4 Actuator Write'
    controller_B.servoValues[5] = controller_P.OutputLimitation_UpperSat;
  } else if (rtb_Yaw < controller_P.OutputLimitation_LowerSat) {
    // MATLABSystem: '<Root>/PX4 Actuator Write'
    controller_B.servoValues[5] = controller_P.OutputLimitation_LowerSat;
  } else {
    // MATLABSystem: '<Root>/PX4 Actuator Write'
    controller_B.servoValues[5] = rtb_Yaw;
  }

  if (rtb_CastToSingle_m > controller_P.OutputLimitation_UpperSat) {
    // MATLABSystem: '<Root>/PX4 Actuator Write'
    controller_B.servoValues[6] = controller_P.OutputLimitation_UpperSat;
  } else if (rtb_CastToSingle_m < controller_P.OutputLimitation_LowerSat) {
    // MATLABSystem: '<Root>/PX4 Actuator Write'
    controller_B.servoValues[6] = controller_P.OutputLimitation_LowerSat;
  } else {
    // MATLABSystem: '<Root>/PX4 Actuator Write'
    controller_B.servoValues[6] = rtb_CastToSingle_m;
  }

  if (rtb_CastToSingle1_h > controller_P.OutputLimitation_UpperSat) {
    // MATLABSystem: '<Root>/PX4 Actuator Write'
    controller_B.servoValues[7] = controller_P.OutputLimitation_UpperSat;
  } else if (rtb_CastToSingle1_h < controller_P.OutputLimitation_LowerSat) {
    // MATLABSystem: '<Root>/PX4 Actuator Write'
    controller_B.servoValues[7] = controller_P.OutputLimitation_LowerSat;
  } else {
    // MATLABSystem: '<Root>/PX4 Actuator Write'
    controller_B.servoValues[7] = rtb_CastToSingle1_h;
  }

  // End of Saturate: '<S2>/Output Limitation'

  // MATLABSystem: '<Root>/PX4 Actuator Write' incorporates:
  //   Constant: '<S16>/Constant'
  //   RelationalOperator: '<S16>/Compare'

  MW_actuators_set(controller_B.In1_d.values[4] >=
                   controller_P.CompareToConstant3_const,
                   &controller_B.motorValues[0], &controller_B.servoValues[0]);
  controller_PX4Timestamp(&controller_B.PX4Timestamp_n);

  // Saturate: '<S14>/Output Limitation1'
  if (controller_B.ParamStep_k > controller_P.OutputLimitation1_UpperSat) {
    controller_B.ParamStep_k = controller_P.OutputLimitation1_UpperSat;
  } else if (controller_B.ParamStep_k < controller_P.OutputLimitation1_LowerSat)
  {
    controller_B.ParamStep_k = controller_P.OutputLimitation1_LowerSat;
  }

  // End of Saturate: '<S14>/Output Limitation1'

  // Saturate: '<S14>/Output Limitation'
  if (rtb_Pitch > controller_P.OutputLimitation_UpperSat_m) {
    rtb_Pitch = controller_P.OutputLimitation_UpperSat_m;
  } else if (rtb_Pitch < controller_P.OutputLimitation_LowerSat_l) {
    rtb_Pitch = controller_P.OutputLimitation_LowerSat_l;
  }

  // End of Saturate: '<S14>/Output Limitation'

  // MATLABSystem: '<S162>/SourceBlock'
  b_varargout_1 = uORB_read_step(controller_DW.obj_o.orbMetadataObj,
    &controller_DW.obj_o.eventStructObj, &controller_B.r3, false, 1.0);

  // Outputs for Enabled SubSystem: '<S162>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S163>/Enable'

  // Start for MATLABSystem: '<S162>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S163>/In1'
    controller_B.In1_k = controller_B.r3;
  }

  // End of Outputs for SubSystem: '<S162>/Enabled Subsystem'

  // BusAssignment: '<S159>/Bus Assignment' incorporates:
  //   Constant: '<S13>/Constant6'
  //   Gain: '<S14>/Gain'
  //   Gain: '<S14>/Gain1'
  //   MATLABSystem: '<S13>/Read Parameter2'
  //   MATLABSystem: '<S159>/PX4 Timestamp'
  //   Sum: '<S14>/Add'
  //   Sum: '<S14>/Sum'
  //
  controller_B.BusAssignment_c.timestamp =
    controller_B.PX4Timestamp_n.PX4Timestamp;
  controller_B.BusAssignment_c.activation_flag = controller_B.ActivationFlag;
  controller_B.BusAssignment_c.mode_selector = controller_B.ParamStep_c;
  controller_B.BusAssignment_c.test_mode_selector = controller_P.Constant6_Value;
  controller_B.BusAssignment_c.aileron = (rtb_Pitch - controller_B.ParamStep_k) *
    controller_P.Gain1_Gain_a;
  controller_B.BusAssignment_c.elevator = (rtb_Pitch + controller_B.ParamStep_k)
    * controller_P.Gain_Gain_l;

  // Saturate: '<S14>/Output Limitation3'
  if (rtb_CastToSingle_m > controller_P.OutputLimitation3_UpperSat) {
    rtb_CastToSingle_m = controller_P.OutputLimitation3_UpperSat;
  } else if (rtb_CastToSingle_m < controller_P.OutputLimitation3_LowerSat) {
    rtb_CastToSingle_m = controller_P.OutputLimitation3_LowerSat;
  }

  // Saturate: '<S14>/Output Limitation2'
  if (rtb_CastToSingle1_h > controller_P.OutputLimitation2_UpperSat) {
    rtb_CastToSingle1_h = controller_P.OutputLimitation2_UpperSat;
  } else if (rtb_CastToSingle1_h < controller_P.OutputLimitation2_LowerSat) {
    rtb_CastToSingle1_h = controller_P.OutputLimitation2_LowerSat;
  }

  // BusAssignment: '<S159>/Bus Assignment' incorporates:
  //   Fcn: '<S14>/Fcn1'
  //   Fcn: '<S14>/Fcn5'
  //   MATLAB Function: '<S2>/quat2eul'
  //   Saturate: '<S14>/Output Limitation2'
  //   Saturate: '<S14>/Output Limitation3'
  //   Sum: '<S14>/Add1'

  controller_B.BusAssignment_c.rudder = (rtb_CastToSingle_m + 1.0F) / 2.0F -
    (rtb_CastToSingle1_h + 1.0F) / 2.0F;
  controller_B.BusAssignment_c.throttle = rtb_Thrust;
  controller_B.BusAssignment_c.roll_rate = controller_B.In1_k.x;
  controller_B.BusAssignment_c.pitch_rate = controller_B.In1_k.y;
  controller_B.BusAssignment_c.yaw_rate = controller_B.In1_k.z;
  controller_B.BusAssignment_c.roll_angle = rt_atan2f_snf((controller_B.In1.q[0]
    * controller_B.In1.q[1] + controller_B.In1.q[2] * controller_B.In1.q[3]) *
    2.0F, ((controller_B.In1.q[0] * controller_B.In1.q[0] - controller_B.In1.q[1]
            * controller_B.In1.q[1]) - controller_B.In1.q[2] *
           controller_B.In1.q[2]) + controller_B.In1.q[3] * controller_B.In1.q[3]);
  controller_B.BusAssignment_c.pitch_angle = rtb_theta;
  controller_B.BusAssignment_c.airspeed = controller_B.In1_m.true_airspeed_m_s;
  controller_B.BusAssignment_c._padding0[0] = 0U;
  controller_B.BusAssignment_c._padding0[1] = 0U;
  controller_B.BusAssignment_c._padding0[2] = 0U;
  controller_B.BusAssignment_c._padding0[3] = 0U;

  // MATLABSystem: '<S161>/SinkBlock' incorporates:
  //   BusAssignment: '<S159>/Bus Assignment'

  uORB_write_step(controller_DW.obj_md.orbMetadataObj,
                  &controller_DW.obj_md.orbAdvertiseObj,
                  &controller_B.BusAssignment_c);
  controller_PX4Timestamp(&controller_B.PX4Timestamp);

  // MATLABSystem: '<S11>/Read Parameter13'
  b_varargout_1 = MW_ParamRead_Step(controller_DW.obj_lp.MW_PARAMHANDLE,
    MW_INT32, &controller_B.ParamStep_g1);
  if (b_varargout_1) {
    controller_B.ParamStep_g1 = 0;
  }

  // BusAssignment: '<S156>/Bus Assignment' incorporates:
  //   DataTypeConversion: '<S11>/Cast To Single10'
  //   DataTypeConversion: '<S11>/Cast To Single14'
  //   DataTypeConversion: '<S11>/Cast To Single17'
  //   DataTypeConversion: '<S11>/Cast To Single19'
  //   DataTypeConversion: '<S11>/Cast To Single7'
  //   DataTypeConversion: '<S11>/Data Type Conversion'
  //   MATLABSystem: '<S11>/Read Parameter1'
  //   MATLABSystem: '<S11>/Read Parameter10'
  //   MATLABSystem: '<S11>/Read Parameter11'
  //   MATLABSystem: '<S11>/Read Parameter12'
  //   MATLABSystem: '<S11>/Read Parameter13'
  //   MATLABSystem: '<S11>/Read Parameter14'
  //   MATLABSystem: '<S11>/Read Parameter15'
  //   MATLABSystem: '<S11>/Read Parameter16'
  //   MATLABSystem: '<S11>/Read Parameter17'
  //   MATLABSystem: '<S11>/Read Parameter2'
  //   MATLABSystem: '<S11>/Read Parameter20'
  //   MATLABSystem: '<S11>/Read Parameter4'
  //   MATLABSystem: '<S11>/Read Parameter5'
  //   MATLABSystem: '<S11>/Read Parameter7'
  //   MATLABSystem: '<S11>/Read Parameter8'
  //   MATLABSystem: '<S11>/Read Parameter9'
  //   MATLABSystem: '<S156>/PX4 Timestamp'
  //
  controller_B.BusAssignment.timestamp = controller_B.PX4Timestamp.PX4Timestamp;
  controller_B.BusAssignment.sp_doublet_amp = static_cast<real32_T>
    (controller_InstP.short_period_amp);
  controller_B.BusAssignment.sp_doublet_freq = controller_B.ParamStep_g;
  controller_B.BusAssignment.sp_doublet_dur = controller_InstP.short_period_dur;
  controller_B.BusAssignment.sp_sweep_amp = static_cast<real32_T>
    (controller_B.Gain3);
  controller_B.BusAssignment.sp_sweep_freq_min = controller_B.ParamStep_b;
  controller_B.BusAssignment.sp_sweep_freq_max = controller_B.ParamStep_cv;
  controller_B.BusAssignment.sp_sweep_dur =
    controller_P.Setendtimeofdoublet_Threshold;
  controller_B.BusAssignment.dr_doublet_amp = static_cast<real32_T>
    (controller_InstP.dutch_roll_amp);
  controller_B.BusAssignment.dr_doublet_freq = controller_B.ParamStep_f;
  controller_B.BusAssignment.dr_doublet_dur = controller_InstP.dutch_roll_dur;
  controller_B.BusAssignment.dr_diff_thrust_amp = static_cast<real32_T>
    (controller_InstP.dutch_roll_diff_thrust_amp);
  controller_B.BusAssignment.dr_diff_thrust_period =
    controller_InstP.dutch_roll_diff_thrust_period;
  controller_B.BusAssignment.ph_doublet_amp = static_cast<real32_T>
    (controller_InstP.phugoid_amp);
  controller_B.BusAssignment.ph_doublet_freq = controller_B.ParamStep_p;
  controller_B.BusAssignment.ph_doublet_dur = controller_InstP.phugoid_dur;
  controller_B.BusAssignment.pitch_con_gain_p =
    controller_InstP.pitch_con_gain_p;
  controller_B.BusAssignment.pitch_con_gain_i =
    controller_InstP.pitch_con_gain_i;
  controller_B.BusAssignment.vel_con_gain_p = controller_InstP.vel_con_gain_p;
  controller_B.BusAssignment.vel_con_gain_i = controller_InstP.vel_con_gain_i;
  controller_B.BusAssignment.vel_lp_freq = controller_InstP.vel_lp_freq;
  controller_B.BusAssignment.pilot_marker = static_cast<uint32_T>
    (controller_B.ParamStep_g1);
  controller_B.BusAssignment._padding0[0] = 0U;
  controller_B.BusAssignment._padding0[1] = 0U;
  controller_B.BusAssignment._padding0[2] = 0U;
  controller_B.BusAssignment._padding0[3] = 0U;

  // MATLABSystem: '<S158>/SinkBlock' incorporates:
  //   BusAssignment: '<S156>/Bus Assignment'

  uORB_write_step(controller_DW.obj_g.orbMetadataObj,
                  &controller_DW.obj_g.orbAdvertiseObj,
                  &controller_B.BusAssignment);

  // MATLABSystem: '<S6>/SourceBlock'
  uORB_read_step(controller_DW.obj_og.orbMetadataObj,
                 &controller_DW.obj_og.eventStructObj, &controller_B.r2, false,
                 1.0);
}

// Model initialize function
void controller_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  {
    static const char_T ParameterNameStr[14] = "THETA_COMMAND";
    static const char_T ParameterNameStr_0[17] = "AIRSPEED_COMMAND";
    static const char_T ParameterNameStr_1[14] = "MODE_SELECTOR";
    static const char_T ParameterNameStr_2[15] = "PH_DOUBLET_AMP";
    static const char_T ParameterNameStr_3[15] = "DR_DOUBLET_AMP";
    static const char_T ParameterNameStr_4[16] = "SP_SWEEP_FR_MIN";
    static const char_T ParameterNameStr_5[16] = "DR_DIFF_THR_AMP";
    static const char_T ParameterNameStr_6[15] = "SP_DOUBLET_AMP";
    static const char_T ParameterNameStr_7[16] = "DR_DIFF_THR_PER";
    static const char_T ParameterNameStr_8[15] = "DR_DOUBLET_DUR";
    static const char_T ParameterNameStr_9[16] = "PH_DOUBLET_FREQ";
    static const char_T ParameterNameStr_a[16] = "SP_SWEEP_FR_MAX";
    static const char_T ParameterNameStr_b[13] = "SP_SWEEP_AMP";
    static const char_T ParameterNameStr_c[16] = "DR_DOUBLET_FREQ";
    static const char_T ParameterNameStr_d[13] = "SP_SWEEP_DUR";
    static const char_T ParameterNameStr_e[16] = "SP_DOUBLET_FREQ";
    static const char_T ParameterNameStr_f[15] = "PH_DOUBLET_DUR";
    static const char_T ParameterNameStr_g[15] = "SP_DOUBLET_DUR";
    static const char_T ParameterNameStr_h[17] = "PITCH_CON_GAIN_I";
    static const char_T ParameterNameStr_i[12] = "VEL_LP_FREQ";
    static const char_T ParameterNameStr_j[17] = "VEL_CONTR_GAIN_P";
    static const char_T ParameterNameStr_k[17] = "PITCH_CON_GAIN_P";
    static const char_T ParameterNameStr_l[17] = "VEL_CONTR_GAIN_I";
    static const char_T ParameterNameStr_m[13] = "PILOT_MARKER";
    int32_T i;

    // InitializeConditions for Switch: '<S25>/Check for activation' incorporates:
    //   Memory: '<S25>/Saved pitch input'

    controller_DW.Savedpitchinput_PreviousInput =
      controller_P.Savedpitchinput_InitialConditio;

    // InitializeConditions for Switch: '<S26>/Check for activation' incorporates:
    //   Memory: '<S26>/Saved Thrust input'

    controller_DW.SavedThrustinput_PreviousInput =
      controller_P.SavedThrustinput_InitialConditi;

    // InitializeConditions for Switch: '<S27>/Check for activation' incorporates:
    //   Memory: '<S27>/Saved yaw input'

    controller_DW.Savedyawinput_PreviousInput =
      controller_P.Savedyawinput_InitialCondition;

    // InitializeConditions for Switch: '<S29>/Give stored time instead  of current time after activation' incorporates:
    //   Memory: '<S29>/Store Start Time'

    controller_DW.StoreStartTime_PreviousInput =
      controller_P.StoreStartTime_InitialCondition;

    // SystemInitialize for Enabled SubSystem: '<S164>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S165>/In1' incorporates:
    //   Outport: '<S165>/Out1'

    controller_B.In1_d = controller_P.Out1_Y0_i;

    // End of SystemInitialize for SubSystem: '<S164>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S166>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S167>/In1' incorporates:
    //   Outport: '<S167>/Out1'

    controller_B.In1 = controller_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S166>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S154>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S155>/In1' incorporates:
    //   Outport: '<S155>/Out1'

    controller_B.In1_m = controller_P.Out1_Y0_io;

    // End of SystemInitialize for SubSystem: '<S154>/Enabled Subsystem'

    // SystemInitialize for Atomic SubSystem: '<S19>/Controller'
    // InitializeConditions for DiscreteFilter: '<S35>/Discrete Filter1'
    controller_DW.DiscreteFilter1_states =
      controller_P.DiscreteFilter1_InitialStates;

    // InitializeConditions for DiscreteIntegrator: '<S127>/Integrator'
    controller_DW.Integrator_PrevResetState = 2;
    controller_DW.Integrator_IC_LOADING = 1U;

    // InitializeConditions for DiscreteIntegrator: '<S73>/Integrator'
    controller_DW.Integrator_PrevResetState_f = 2;
    controller_DW.Integrator_IC_LOADING_e = 1U;
    controller_PX4Timestamp_Init(&controller_DW.PX4Timestamp_o);

    // Start for MATLABSystem: '<S37>/SinkBlock' incorporates:
    //   BusAssignment: '<S31>/Bus Assignment'

    controller_DW.obj_mu.matlabCodegenIsDeleted = false;
    controller_DW.obj_mu.isSetupComplete = false;
    controller_DW.obj_mu.isInitialized = 1;
    controller_DW.obj_mu.orbMetadataObj = ORB_ID(glide_controller);
    uORB_write_initialize(controller_DW.obj_mu.orbMetadataObj,
                          &controller_DW.obj_mu.orbAdvertiseObj,
                          &controller_B.BusAssignment_k, 1);
    controller_DW.obj_mu.isSetupComplete = true;
    controller_PX4Timestamp_Init(&controller_DW.PX4Timestamp_h);

    // Start for MATLABSystem: '<S146>/SinkBlock' incorporates:
    //   BusAssignment: '<S92>/Bus Assignment'

    controller_DW.obj_b.matlabCodegenIsDeleted = false;
    controller_DW.obj_b.isSetupComplete = false;
    controller_DW.obj_b.isInitialized = 1;
    controller_DW.obj_b.orbMetadataObj = ORB_ID(velocity_filter);
    uORB_write_initialize(controller_DW.obj_b.orbMetadataObj,
                          &controller_DW.obj_b.orbAdvertiseObj,
                          &controller_B.BusAssignment_b, 1);
    controller_DW.obj_b.isSetupComplete = true;

    // End of SystemInitialize for SubSystem: '<S19>/Controller'

    // SystemInitialize for Enabled SubSystem: '<S162>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S163>/In1' incorporates:
    //   Outport: '<S163>/Out1'

    controller_B.In1_k = controller_P.Out1_Y0_e;

    // End of SystemInitialize for SubSystem: '<S162>/Enabled Subsystem'

    // Start for MATLABSystem: '<S164>/SourceBlock'
    controller_DW.obj_d.matlabCodegenIsDeleted = false;
    controller_DW.obj_d.isSetupComplete = false;
    controller_DW.obj_d.isInitialized = 1;
    controller_DW.obj_d.orbMetadataObj = ORB_ID(input_rc);
    uORB_read_initialize(controller_DW.obj_d.orbMetadataObj,
                         &controller_DW.obj_d.eventStructObj);
    controller_DW.obj_d.isSetupComplete = true;

    // Start for MATLABSystem: '<S166>/SourceBlock'
    controller_DW.obj_l.matlabCodegenIsDeleted = false;
    controller_DW.obj_l.isSetupComplete = false;
    controller_DW.obj_l.isInitialized = 1;
    controller_DW.obj_l.orbMetadataObj = ORB_ID(vehicle_odometry);
    uORB_read_initialize(controller_DW.obj_l.orbMetadataObj,
                         &controller_DW.obj_l.eventStructObj);
    controller_DW.obj_l.isSetupComplete = true;

    // Start for MATLABSystem: '<S154>/SourceBlock'
    controller_DW.obj_m.matlabCodegenIsDeleted = false;
    controller_DW.obj_m.isSetupComplete = false;
    controller_DW.obj_m.isInitialized = 1;
    controller_DW.obj_m.orbMetadataObj = ORB_ID(airspeed);
    uORB_read_initialize(controller_DW.obj_m.orbMetadataObj,
                         &controller_DW.obj_m.eventStructObj);
    controller_DW.obj_m.isSetupComplete = true;

    // Start for MATLABSystem: '<S13>/Read Parameter'
    controller_DW.obj_n.matlabCodegenIsDeleted = false;
    controller_DW.obj_n.isInitialized = 1;
    controller_DW.obj_n.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr[0],
      true, 4.0);
    controller_DW.obj_n.isSetupComplete = true;

    // Start for MATLABSystem: '<S13>/Read Parameter1'
    controller_DW.obj_k.matlabCodegenIsDeleted = false;
    controller_DW.obj_k.isInitialized = 1;
    controller_DW.obj_k.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_0[0],
      true, 4.0);
    controller_DW.obj_k.isSetupComplete = true;

    // Start for MATLABSystem: '<S13>/Read Parameter2'
    controller_DW.obj_ms.matlabCodegenIsDeleted = false;
    controller_DW.obj_ms.isInitialized = 1;
    controller_DW.obj_ms.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_1[0],
      true, 4.0);
    controller_DW.obj_ms.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/PX4 Timestamp'
    controller_DW.obj_h.matlabCodegenIsDeleted = false;
    controller_DW.obj_h.isInitialized = 1;
    controller_DW.obj_h.isSetupComplete = true;

    // Start for MATLABSystem: '<S11>/Read Parameter6'
    controller_DW.obj_pe.matlabCodegenIsDeleted = false;
    controller_DW.obj_pe.isInitialized = 1;
    controller_DW.obj_pe.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_2[0],
      true, 4.0);
    controller_DW.obj_pe.isSetupComplete = true;

    // Start for MATLABSystem: '<S11>/Read Parameter3'
    controller_DW.obj_f.matlabCodegenIsDeleted = false;
    controller_DW.obj_f.isInitialized = 1;
    controller_DW.obj_f.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_3[0],
      true, 4.0);
    controller_DW.obj_f.isSetupComplete = true;

    // Start for MATLABSystem: '<S11>/Read Parameter15'
    controller_DW.obj_lg.matlabCodegenIsDeleted = false;
    controller_DW.obj_lg.isInitialized = 1;
    controller_DW.obj_lg.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_4[0],
      true, 4.0);
    controller_DW.obj_lg.isSetupComplete = true;

    // Start for MATLABSystem: '<S11>/Read Parameter19'
    controller_DW.obj_hl.matlabCodegenIsDeleted = false;
    controller_DW.obj_hl.isInitialized = 1;
    controller_DW.obj_hl.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_5[0],
      true, 4.0);
    controller_DW.obj_hl.isSetupComplete = true;

    // Start for MATLABSystem: '<S11>/Read Parameter'
    controller_DW.obj_ng.matlabCodegenIsDeleted = false;
    controller_DW.obj_ng.isInitialized = 1;
    controller_DW.obj_ng.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_6[0],
      true, 4.0);
    controller_DW.obj_ng.isSetupComplete = true;

    // Start for MATLABSystem: '<S11>/Read Parameter20'
    controller_DW.obj_hd.matlabCodegenIsDeleted = false;
    controller_DW.obj_hd.isInitialized = 1;
    controller_DW.obj_hd.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_7[0],
      true, 4.0);
    controller_DW.obj_hd.isSetupComplete = true;

    // Start for MATLABSystem: '<S11>/Read Parameter5'
    controller_DW.obj_o5.matlabCodegenIsDeleted = false;
    controller_DW.obj_o5.isInitialized = 1;
    controller_DW.obj_o5.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_8[0],
      true, 4.0);
    controller_DW.obj_o5.isSetupComplete = true;

    // Start for MATLABSystem: '<S11>/Read Parameter7'
    controller_DW.obj_l1.matlabCodegenIsDeleted = false;
    controller_DW.obj_l1.isInitialized = 1;
    controller_DW.obj_l1.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_9[0],
      true, 4.0);
    controller_DW.obj_l1.isSetupComplete = true;

    // Start for MATLABSystem: '<S11>/Read Parameter16'
    controller_DW.obj_i.matlabCodegenIsDeleted = false;
    controller_DW.obj_i.isInitialized = 1;
    controller_DW.obj_i.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_a[0],
      true, 4.0);
    controller_DW.obj_i.isSetupComplete = true;

    // Start for MATLABSystem: '<S11>/Read Parameter18'
    controller_DW.obj_jt.matlabCodegenIsDeleted = false;
    controller_DW.obj_jt.isInitialized = 1;
    controller_DW.obj_jt.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_b[0],
      true, 4.0);
    controller_DW.obj_jt.isSetupComplete = true;

    // Start for MATLABSystem: '<S11>/Read Parameter4'
    controller_DW.obj_e.matlabCodegenIsDeleted = false;
    controller_DW.obj_e.isInitialized = 1;
    controller_DW.obj_e.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_c[0],
      true, 4.0);
    controller_DW.obj_e.isSetupComplete = true;

    // Start for MATLABSystem: '<S11>/Read Parameter17'
    controller_DW.obj_a.matlabCodegenIsDeleted = false;
    controller_DW.obj_a.isInitialized = 1;
    controller_DW.obj_a.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_d[0],
      true, 4.0);
    controller_DW.obj_a.isSetupComplete = true;

    // Start for MATLABSystem: '<S11>/Read Parameter1'
    controller_DW.obj_ah.matlabCodegenIsDeleted = false;
    controller_DW.obj_ah.isInitialized = 1;
    controller_DW.obj_ah.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_e[0],
      true, 4.0);
    controller_DW.obj_ah.isSetupComplete = true;

    // Start for MATLABSystem: '<S11>/Read Parameter8'
    controller_DW.obj_p.matlabCodegenIsDeleted = false;
    controller_DW.obj_p.isInitialized = 1;
    controller_DW.obj_p.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_f[0],
      true, 4.0);
    controller_DW.obj_p.isSetupComplete = true;

    // Start for MATLABSystem: '<S11>/Read Parameter2'
    controller_DW.obj_j.matlabCodegenIsDeleted = false;
    controller_DW.obj_j.isInitialized = 1;
    controller_DW.obj_j.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_g[0],
      true, 4.0);
    controller_DW.obj_j.isSetupComplete = true;

    // Start for MATLABSystem: '<S11>/Read Parameter9'
    controller_DW.obj_mf.matlabCodegenIsDeleted = false;
    controller_DW.obj_mf.isInitialized = 1;
    controller_DW.obj_mf.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_h[0],
      true, 4.0);
    controller_DW.obj_mf.isSetupComplete = true;

    // Start for MATLABSystem: '<S11>/Read Parameter14'
    controller_DW.obj_lx.matlabCodegenIsDeleted = false;
    controller_DW.obj_lx.isInitialized = 1;
    controller_DW.obj_lx.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_i[0],
      true, 4.0);
    controller_DW.obj_lx.isSetupComplete = true;

    // Start for MATLABSystem: '<S11>/Read Parameter12'
    controller_DW.obj_gx.matlabCodegenIsDeleted = false;
    controller_DW.obj_gx.isInitialized = 1;
    controller_DW.obj_gx.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_j[0],
      true, 4.0);
    controller_DW.obj_gx.isSetupComplete = true;

    // Start for MATLABSystem: '<S11>/Read Parameter10'
    controller_DW.obj_bg.matlabCodegenIsDeleted = false;
    controller_DW.obj_bg.isInitialized = 1;
    controller_DW.obj_bg.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_k[0],
      true, 4.0);
    controller_DW.obj_bg.isSetupComplete = true;

    // Start for MATLABSystem: '<S11>/Read Parameter11'
    controller_DW.obj_i4.matlabCodegenIsDeleted = false;
    controller_DW.obj_i4.isInitialized = 1;
    controller_DW.obj_i4.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_l[0],
      true, 4.0);
    controller_DW.obj_i4.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/PX4 Actuator Write'
    for (i = 0; i < 12; i++) {
      controller_DW.obj.ValidMotorIdx[i] = false;
    }

    for (i = 0; i < 8; i++) {
      controller_DW.obj.ValidServoIdx[i] = false;
    }

    controller_DW.obj.matlabCodegenIsDeleted = false;
    controller_DW.obj.isSetupComplete = false;
    controller_DW.obj.isInitialized = 1;
    controll_PX4Actuators_setupImpl(&controller_DW.obj);
    controller_DW.obj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<Root>/PX4 Actuator Write'
    controller_PX4Timestamp_Init(&controller_DW.PX4Timestamp_n);

    // Start for MATLABSystem: '<S162>/SourceBlock'
    controller_DW.obj_o.matlabCodegenIsDeleted = false;
    controller_DW.obj_o.isSetupComplete = false;
    controller_DW.obj_o.isInitialized = 1;
    controller_DW.obj_o.orbMetadataObj = ORB_ID(sensor_gyro);
    uORB_read_initialize(controller_DW.obj_o.orbMetadataObj,
                         &controller_DW.obj_o.eventStructObj);
    controller_DW.obj_o.isSetupComplete = true;

    // Start for MATLABSystem: '<S161>/SinkBlock' incorporates:
    //   BusAssignment: '<S159>/Bus Assignment'

    controller_DW.obj_md.matlabCodegenIsDeleted = false;
    controller_DW.obj_md.isSetupComplete = false;
    controller_DW.obj_md.isInitialized = 1;
    controller_DW.obj_md.orbMetadataObj = ORB_ID(system_identification);
    uORB_write_initialize(controller_DW.obj_md.orbMetadataObj,
                          &controller_DW.obj_md.orbAdvertiseObj,
                          &controller_B.BusAssignment_c, 1);
    controller_DW.obj_md.isSetupComplete = true;
    controller_PX4Timestamp_Init(&controller_DW.PX4Timestamp);

    // Start for MATLABSystem: '<S11>/Read Parameter13'
    controller_DW.obj_lp.matlabCodegenIsDeleted = false;
    controller_DW.obj_lp.isInitialized = 1;
    controller_DW.obj_lp.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_m[0],
      true, 4.0);
    controller_DW.obj_lp.isSetupComplete = true;

    // Start for MATLABSystem: '<S158>/SinkBlock' incorporates:
    //   BusAssignment: '<S156>/Bus Assignment'

    controller_DW.obj_g.matlabCodegenIsDeleted = false;
    controller_DW.obj_g.isSetupComplete = false;
    controller_DW.obj_g.isInitialized = 1;
    controller_DW.obj_g.orbMetadataObj = ORB_ID(flight_testing);
    uORB_write_initialize(controller_DW.obj_g.orbMetadataObj,
                          &controller_DW.obj_g.orbAdvertiseObj,
                          &controller_B.BusAssignment, 1);
    controller_DW.obj_g.isSetupComplete = true;

    // Start for MATLABSystem: '<S6>/SourceBlock'
    controller_DW.obj_og.matlabCodegenIsDeleted = false;
    controller_DW.obj_og.isSetupComplete = false;
    controller_DW.obj_og.isInitialized = 1;
    controller_DW.obj_og.orbMetadataObj = ORB_ID(sensor_accel);
    uORB_read_initialize(controller_DW.obj_og.orbMetadataObj,
                         &controller_DW.obj_og.eventStructObj);
    controller_DW.obj_og.isSetupComplete = true;
  }
}

// Model terminate function
void controller_terminate(void)
{
  int32_T i;
  real32_T servoValues[8];

  // Terminate for MATLABSystem: '<S164>/SourceBlock'
  if (!controller_DW.obj_d.matlabCodegenIsDeleted) {
    controller_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((controller_DW.obj_d.isInitialized == 1) &&
        controller_DW.obj_d.isSetupComplete) {
      uORB_read_terminate(&controller_DW.obj_d.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S164>/SourceBlock'

  // Terminate for MATLABSystem: '<S166>/SourceBlock'
  if (!controller_DW.obj_l.matlabCodegenIsDeleted) {
    controller_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((controller_DW.obj_l.isInitialized == 1) &&
        controller_DW.obj_l.isSetupComplete) {
      uORB_read_terminate(&controller_DW.obj_l.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S166>/SourceBlock'

  // Terminate for MATLABSystem: '<S154>/SourceBlock'
  if (!controller_DW.obj_m.matlabCodegenIsDeleted) {
    controller_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((controller_DW.obj_m.isInitialized == 1) &&
        controller_DW.obj_m.isSetupComplete) {
      uORB_read_terminate(&controller_DW.obj_m.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S154>/SourceBlock'

  // Terminate for MATLABSystem: '<S13>/Read Parameter'
  if (!controller_DW.obj_n.matlabCodegenIsDeleted) {
    controller_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S13>/Read Parameter'

  // Terminate for MATLABSystem: '<S13>/Read Parameter1'
  if (!controller_DW.obj_k.matlabCodegenIsDeleted) {
    controller_DW.obj_k.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S13>/Read Parameter1'

  // Terminate for MATLABSystem: '<S13>/Read Parameter2'
  if (!controller_DW.obj_ms.matlabCodegenIsDeleted) {
    controller_DW.obj_ms.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S13>/Read Parameter2'

  // Terminate for MATLABSystem: '<Root>/PX4 Timestamp'
  if (!controller_DW.obj_h.matlabCodegenIsDeleted) {
    controller_DW.obj_h.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/PX4 Timestamp'

  // Terminate for MATLABSystem: '<S11>/Read Parameter6'
  if (!controller_DW.obj_pe.matlabCodegenIsDeleted) {
    controller_DW.obj_pe.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S11>/Read Parameter6'

  // Terminate for MATLABSystem: '<S11>/Read Parameter3'
  if (!controller_DW.obj_f.matlabCodegenIsDeleted) {
    controller_DW.obj_f.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S11>/Read Parameter3'

  // Terminate for MATLABSystem: '<S11>/Read Parameter15'
  if (!controller_DW.obj_lg.matlabCodegenIsDeleted) {
    controller_DW.obj_lg.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S11>/Read Parameter15'

  // Terminate for MATLABSystem: '<S11>/Read Parameter19'
  if (!controller_DW.obj_hl.matlabCodegenIsDeleted) {
    controller_DW.obj_hl.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S11>/Read Parameter19'

  // Terminate for MATLABSystem: '<S11>/Read Parameter'
  if (!controller_DW.obj_ng.matlabCodegenIsDeleted) {
    controller_DW.obj_ng.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S11>/Read Parameter'

  // Terminate for MATLABSystem: '<S11>/Read Parameter20'
  if (!controller_DW.obj_hd.matlabCodegenIsDeleted) {
    controller_DW.obj_hd.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S11>/Read Parameter20'

  // Terminate for MATLABSystem: '<S11>/Read Parameter5'
  if (!controller_DW.obj_o5.matlabCodegenIsDeleted) {
    controller_DW.obj_o5.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S11>/Read Parameter5'

  // Terminate for MATLABSystem: '<S11>/Read Parameter7'
  if (!controller_DW.obj_l1.matlabCodegenIsDeleted) {
    controller_DW.obj_l1.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S11>/Read Parameter7'

  // Terminate for MATLABSystem: '<S11>/Read Parameter16'
  if (!controller_DW.obj_i.matlabCodegenIsDeleted) {
    controller_DW.obj_i.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S11>/Read Parameter16'

  // Terminate for MATLABSystem: '<S11>/Read Parameter18'
  if (!controller_DW.obj_jt.matlabCodegenIsDeleted) {
    controller_DW.obj_jt.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S11>/Read Parameter18'

  // Terminate for MATLABSystem: '<S11>/Read Parameter4'
  if (!controller_DW.obj_e.matlabCodegenIsDeleted) {
    controller_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S11>/Read Parameter4'

  // Terminate for MATLABSystem: '<S11>/Read Parameter17'
  if (!controller_DW.obj_a.matlabCodegenIsDeleted) {
    controller_DW.obj_a.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S11>/Read Parameter17'

  // Terminate for MATLABSystem: '<S11>/Read Parameter1'
  if (!controller_DW.obj_ah.matlabCodegenIsDeleted) {
    controller_DW.obj_ah.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S11>/Read Parameter1'

  // Terminate for MATLABSystem: '<S11>/Read Parameter8'
  if (!controller_DW.obj_p.matlabCodegenIsDeleted) {
    controller_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S11>/Read Parameter8'

  // Terminate for MATLABSystem: '<S11>/Read Parameter2'
  if (!controller_DW.obj_j.matlabCodegenIsDeleted) {
    controller_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S11>/Read Parameter2'

  // Terminate for MATLABSystem: '<S11>/Read Parameter9'
  if (!controller_DW.obj_mf.matlabCodegenIsDeleted) {
    controller_DW.obj_mf.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S11>/Read Parameter9'

  // Terminate for MATLABSystem: '<S11>/Read Parameter14'
  if (!controller_DW.obj_lx.matlabCodegenIsDeleted) {
    controller_DW.obj_lx.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S11>/Read Parameter14'

  // Terminate for MATLABSystem: '<S11>/Read Parameter12'
  if (!controller_DW.obj_gx.matlabCodegenIsDeleted) {
    controller_DW.obj_gx.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S11>/Read Parameter12'

  // Terminate for MATLABSystem: '<S11>/Read Parameter10'
  if (!controller_DW.obj_bg.matlabCodegenIsDeleted) {
    controller_DW.obj_bg.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S11>/Read Parameter10'

  // Terminate for MATLABSystem: '<S11>/Read Parameter11'
  if (!controller_DW.obj_i4.matlabCodegenIsDeleted) {
    controller_DW.obj_i4.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S11>/Read Parameter11'

  // Terminate for Atomic SubSystem: '<S19>/Controller'
  controller_PX4Timestamp_Term(&controller_DW.PX4Timestamp_o);

  // Terminate for MATLABSystem: '<S37>/SinkBlock'
  if (!controller_DW.obj_mu.matlabCodegenIsDeleted) {
    controller_DW.obj_mu.matlabCodegenIsDeleted = true;
    if ((controller_DW.obj_mu.isInitialized == 1) &&
        controller_DW.obj_mu.isSetupComplete) {
      uORB_write_terminate(&controller_DW.obj_mu.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S37>/SinkBlock'
  controller_PX4Timestamp_Term(&controller_DW.PX4Timestamp_h);

  // Terminate for MATLABSystem: '<S146>/SinkBlock'
  if (!controller_DW.obj_b.matlabCodegenIsDeleted) {
    controller_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((controller_DW.obj_b.isInitialized == 1) &&
        controller_DW.obj_b.isSetupComplete) {
      uORB_write_terminate(&controller_DW.obj_b.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S146>/SinkBlock'
  // End of Terminate for SubSystem: '<S19>/Controller'

  // Terminate for MATLABSystem: '<Root>/PX4 Actuator Write'
  if (!controller_DW.obj.matlabCodegenIsDeleted) {
    controller_DW.obj.matlabCodegenIsDeleted = true;
    if ((controller_DW.obj.isInitialized == 1) &&
        controller_DW.obj.isSetupComplete) {
      for (i = 0; i < 12; i++) {
        controller_B.motorValues_m[i] = (rtNaNF);
      }

      for (i = 0; i < 8; i++) {
        servoValues[i] = (rtNaNF);
      }

      for (i = 0; i < 12; i++) {
        if (controller_DW.obj.ValidMotorIdx[i]) {
          controller_B.motorValues_m[i] = 0.0F;
        }
      }

      for (i = 0; i < 8; i++) {
        if (controller_DW.obj.ValidServoIdx[i]) {
          servoValues[i] = 0.0F;
        }
      }

      MW_actuators_set(false, &controller_B.motorValues_m[0], &servoValues[0]);
      MW_actuators_terminate();
    }
  }

  // End of Terminate for MATLABSystem: '<Root>/PX4 Actuator Write'
  controller_PX4Timestamp_Term(&controller_DW.PX4Timestamp_n);

  // Terminate for MATLABSystem: '<S162>/SourceBlock'
  if (!controller_DW.obj_o.matlabCodegenIsDeleted) {
    controller_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((controller_DW.obj_o.isInitialized == 1) &&
        controller_DW.obj_o.isSetupComplete) {
      uORB_read_terminate(&controller_DW.obj_o.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S162>/SourceBlock'

  // Terminate for MATLABSystem: '<S161>/SinkBlock'
  if (!controller_DW.obj_md.matlabCodegenIsDeleted) {
    controller_DW.obj_md.matlabCodegenIsDeleted = true;
    if ((controller_DW.obj_md.isInitialized == 1) &&
        controller_DW.obj_md.isSetupComplete) {
      uORB_write_terminate(&controller_DW.obj_md.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S161>/SinkBlock'
  controller_PX4Timestamp_Term(&controller_DW.PX4Timestamp);

  // Terminate for MATLABSystem: '<S11>/Read Parameter13'
  if (!controller_DW.obj_lp.matlabCodegenIsDeleted) {
    controller_DW.obj_lp.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S11>/Read Parameter13'

  // Terminate for MATLABSystem: '<S158>/SinkBlock'
  if (!controller_DW.obj_g.matlabCodegenIsDeleted) {
    controller_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((controller_DW.obj_g.isInitialized == 1) &&
        controller_DW.obj_g.isSetupComplete) {
      uORB_write_terminate(&controller_DW.obj_g.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S158>/SinkBlock'

  // Terminate for MATLABSystem: '<S6>/SourceBlock'
  if (!controller_DW.obj_og.matlabCodegenIsDeleted) {
    controller_DW.obj_og.matlabCodegenIsDeleted = true;
    if ((controller_DW.obj_og.isInitialized == 1) &&
        controller_DW.obj_og.isSetupComplete) {
      uORB_read_terminate(&controller_DW.obj_og.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S6>/SourceBlock'
}

const char_T* RT_MODEL_controller_T::getErrorStatus() const
{
  return (errorStatus);
}

void RT_MODEL_controller_T::setErrorStatus(const char_T* const volatile
  aErrorStatus)
{
  (errorStatus = aErrorStatus);
}

//
// File trailer for generated code.
//
// [EOF]
//
