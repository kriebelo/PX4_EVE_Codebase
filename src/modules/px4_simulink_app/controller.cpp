//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: controller.cpp
//
// Code generated for Simulink model 'controller'.
//
// Model version                  : 1.88
// Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
// C/C++ source code generated on : Tue Apr 28 23:51:53 2026
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "controller.h"
#include "controller_types.h"
#include "controller_private.h"

extern "C"
{

#include "rt_nonfinite.h"

}

#include <math.h>
#include "rtwtypes.h"
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
  // Start for MATLABSystem: '<S32>/PX4 Timestamp'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void controller_PX4Timestamp(B_PX4Timestamp_controller_T *localB)
{
  // MATLABSystem: '<S32>/PX4 Timestamp'
  localB->PX4Timestamp = hrt_absolute_time();
}

// Termination for atomic system:
void controller_PX4Timestamp_Term(DW_PX4Timestamp_controller_T *localDW)
{
  // Terminate for MATLABSystem: '<S32>/PX4 Timestamp'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S32>/PX4 Timestamp'
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
  real32_T rtb_Add1_e;
  real32_T rtb_Converttimefromustos;
  real32_T rtb_Gain_c;
  real32_T rtb_Gain_j;
  real32_T rtb_OutputLimitation3;
  real32_T rtb_Saturation;
  real32_T rtb_Saturation1;
  real32_T rtb_Saturation10;
  real32_T rtb_Saturation7;
  real32_T rtb_Saturation8;
  real32_T rtb_Saturation_f;
  real32_T rtb_Sum_p;
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

  // Fcn: '<S14>/Fcn1' incorporates:
  //   DataTypeConversion: '<S14>/Cast To Single1'

  rtb_Saturation1 = (static_cast<real32_T>(controller_B.In1_d.values[6]) -
                     1000.0F) / 500.0F;

  // Saturate: '<S14>/Saturation1'
  if (rtb_Saturation1 > controller_P.Saturation1_UpperSat) {
    rtb_Saturation1 = controller_P.Saturation1_UpperSat;
  } else if (rtb_Saturation1 < controller_P.Saturation1_LowerSat) {
    rtb_Saturation1 = controller_P.Saturation1_LowerSat;
  }

  // End of Saturate: '<S14>/Saturation1'

  // MATLABSystem: '<S14>/Read Parameter2'
  b_varargout_1 = MW_ParamRead_Step(controller_DW.obj_ms.MW_PARAMHANDLE,
    MW_SINGLE, &controller_B.ParamStep);
  if (b_varargout_1) {
    controller_B.ParamStep = 0.0F;
  }

  // MATLABSystem: '<S14>/Modulo by Constant' incorporates:
  //   MATLABSystem: '<S14>/Read Parameter2'
  //
  if (rtIsNaNF(controller_B.ParamStep) || rtIsInfF(controller_B.ParamStep)) {
    controller_B.yTemp = (rtNaNF);
  } else {
    controller_B.yTemp = static_cast<real32_T>(fmod(static_cast<real_T>
      (controller_B.ParamStep), 3.0));
    if (controller_B.yTemp == 0.0F) {
      controller_B.yTemp = 0.0F;
    } else if (controller_B.yTemp < 0.0F) {
      controller_B.yTemp += 3.0F;
    }
  }

  // Switch: '<S14>/Switch4' incorporates:
  //   Constant: '<S14>/Constant6'
  //   Constant: '<S14>/Constant7'
  //   MATLABSystem: '<S14>/Read Parameter2'
  //
  if (controller_B.ParamStep > controller_P.Switch4_Threshold) {
    rtb_Saturation = controller_P.Constant7_Value;
  } else {
    rtb_Saturation = controller_P.Constant6_Value;
  }

  // End of Switch: '<S14>/Switch4'

  // Saturate: '<S14>/Saturation'
  if (rtb_Saturation > controller_P.Saturation_UpperSat) {
    rtb_Saturation = controller_P.Saturation_UpperSat;
  } else if (rtb_Saturation < controller_P.Saturation_LowerSat) {
    rtb_Saturation = controller_P.Saturation_LowerSat;
  }

  // End of Saturate: '<S14>/Saturation'

  // Fcn: '<S13>/Fcn5' incorporates:
  //   DataTypeConversion: '<S13>/Data Type Conversion1'

  rtb_Saturation8 = (static_cast<real32_T>(controller_B.In1_d.values[1]) -
                     1500.0F) / 500.0F;

  // Saturate: '<S13>/Saturation8'
  if (rtb_Saturation8 > controller_P.Saturation8_UpperSat) {
    rtb_Saturation8 = controller_P.Saturation8_UpperSat;
  } else if (rtb_Saturation8 < controller_P.Saturation8_LowerSat) {
    rtb_Saturation8 = controller_P.Saturation8_LowerSat;
  }

  // End of Saturate: '<S13>/Saturation8'

  // Switch: '<S26>/Check for activation'
  if (!(rtb_Saturation1 > controller_P.Checkforactivation_Threshold)) {
    // Switch: '<S26>/Check for activation'
    controller_DW.Savedpitchinput_PreviousInput = rtb_Saturation8;
  }

  // End of Switch: '<S26>/Check for activation'

  // Fcn: '<S13>/Fcn7' incorporates:
  //   DataTypeConversion: '<S13>/Data Type Conversion2'

  rtb_Saturation7 = (static_cast<real32_T>(controller_B.In1_d.values[3]) -
                     1500.0F) / 500.0F;

  // Saturate: '<S13>/Saturation7'
  if (rtb_Saturation7 > controller_P.Saturation7_UpperSat) {
    rtb_Saturation7 = controller_P.Saturation7_UpperSat;
  } else if (rtb_Saturation7 < controller_P.Saturation7_LowerSat) {
    rtb_Saturation7 = controller_P.Saturation7_LowerSat;
  }

  // End of Saturate: '<S13>/Saturation7'

  // Switch: '<S28>/Check for activation'
  if (!(rtb_Saturation1 > controller_P.Checkforactivation_Threshold_d)) {
    // Switch: '<S28>/Check for activation'
    controller_DW.Savedyawinput_PreviousInput = rtb_Saturation7;
  }

  // End of Switch: '<S28>/Check for activation'

  // Fcn: '<S13>/Fcn6' incorporates:
  //   DataTypeConversion: '<S13>/Data Type Conversion3'

  rtb_Saturation10 = (static_cast<real32_T>(controller_B.In1_d.values[2]) -
                      1000.0F) / 1000.0F;

  // Saturate: '<S13>/Saturation10'
  if (rtb_Saturation10 > controller_P.Saturation10_UpperSat) {
    rtb_Saturation10 = controller_P.Saturation10_UpperSat;
  } else if (rtb_Saturation10 < controller_P.Saturation10_LowerSat) {
    rtb_Saturation10 = controller_P.Saturation10_LowerSat;
  }

  // End of Saturate: '<S13>/Saturation10'

  // Switch: '<S27>/Check for activation'
  if (!(rtb_Saturation1 > controller_P.Checkforactivation_Threshold_m)) {
    // Switch: '<S27>/Check for activation'
    controller_DW.SavedThrustinput_PreviousInput = rtb_Saturation10;
  }

  // End of Switch: '<S27>/Check for activation'

  // MATLABSystem: '<Root>/PX4 Timestamp'
  controller_B.rtb_PX4Timestamp_c = hrt_absolute_time();

  // Switch: '<S30>/Give stored time instead  of current time after activation'
  if (!(rtb_Saturation1 > controller_P.Givestoredtimeinsteadofcurrentt)) {
    // Switch: '<S30>/Give stored time instead  of current time after activation' incorporates:
    //   MATLABSystem: '<Root>/PX4 Timestamp'

    controller_DW.StoreStartTime_PreviousInput = controller_B.rtb_PX4Timestamp_c;
  }

  // End of Switch: '<S30>/Give stored time instead  of current time after activation' 

  // Gain: '<S30>/Convert time from us to s' incorporates:
  //   DataTypeConversion: '<S30>/Convert time from  uint64 to single'
  //   MATLABSystem: '<Root>/PX4 Timestamp'
  //   Sum: '<S30>/Get difference between  activation time and current time'
  //   Switch: '<S30>/Give stored time instead  of current time after activation'

  rtb_Converttimefromustos = static_cast<real32_T>
    (controller_B.rtb_PX4Timestamp_c -
     controller_DW.StoreStartTime_PreviousInput) *
    controller_P.Converttimefromustos_Gain;

  // MATLABSystem: '<S12>/Read Parameter1'
  b_varargout_1 = MW_ParamRead_Step(controller_DW.obj_a.MW_PARAMHANDLE,
    MW_SINGLE, &controller_B.ParamStep);
  if (b_varargout_1) {
    controller_B.ParamStep = 0.0F;
  }

  // ParameterWriter: '<S12>/Parameter Writer1' incorporates:
  //   MATLABSystem: '<S12>/Read Parameter1'
  //
  controller_InstP.short_period_freq = controller_B.ParamStep;

  // MATLABSystem: '<S12>/Read Parameter3'
  b_varargout_1 = MW_ParamRead_Step(controller_DW.obj_f.MW_PARAMHANDLE,
    MW_SINGLE, &controller_B.ParamStep_k);
  if (b_varargout_1) {
    controller_B.ParamStep_k = 0.0F;
  }

  // ParameterWriter: '<S12>/Parameter Writer3' incorporates:
  //   DataTypeConversion: '<S12>/Cast To Double4'
  //   Gain: '<S12>/Gain1'
  //   MATLABSystem: '<S12>/Read Parameter3'
  //
  controller_InstP.dutch_roll_amp = controller_P.Gain1_Gain *
    controller_B.ParamStep_k;

  // MATLABSystem: '<S12>/Read Parameter7'
  b_varargout_1 = MW_ParamRead_Step(controller_DW.obj_l1.MW_PARAMHANDLE,
    MW_SINGLE, &controller_B.ParamStep_c);
  if (b_varargout_1) {
    controller_B.ParamStep_c = 0.0F;
  }

  // ParameterWriter: '<S12>/Parameter Writer7' incorporates:
  //   MATLABSystem: '<S12>/Read Parameter7'
  //
  controller_InstP.phugoid_freq = controller_B.ParamStep_c;

  // MATLABSystem: '<S12>/Read Parameter'
  b_varargout_1 = MW_ParamRead_Step(controller_DW.obj_ng.MW_PARAMHANDLE,
    MW_SINGLE, &controller_B.ParamStep_b);
  if (b_varargout_1) {
    controller_B.ParamStep_b = 0.0F;
  }

  // ParameterWriter: '<S12>/Parameter Writer' incorporates:
  //   DataTypeConversion: '<S12>/Cast To Double1'
  //   Gain: '<S12>/Gain'
  //   MATLABSystem: '<S12>/Read Parameter'
  //
  controller_InstP.short_period_amp = controller_P.Gain_Gain *
    controller_B.ParamStep_b;

  // MATLABSystem: '<S12>/Read Parameter6'
  b_varargout_1 = MW_ParamRead_Step(controller_DW.obj_pe.MW_PARAMHANDLE,
    MW_SINGLE, &controller_B.ParamStep_p);
  if (b_varargout_1) {
    controller_B.ParamStep_p = 0.0F;
  }

  // ParameterWriter: '<S12>/Parameter Writer6' incorporates:
  //   DataTypeConversion: '<S12>/Cast To Double7'
  //   Gain: '<S12>/Gain2'
  //   MATLABSystem: '<S12>/Read Parameter6'
  //
  controller_InstP.phugoid_amp = controller_P.Gain2_Gain *
    controller_B.ParamStep_p;

  // MATLABSystem: '<S12>/Read Parameter4'
  b_varargout_1 = MW_ParamRead_Step(controller_DW.obj_e.MW_PARAMHANDLE,
    MW_SINGLE, &controller_B.ParamStep_cv);
  if (b_varargout_1) {
    controller_B.ParamStep_cv = 0.0F;
  }

  // ParameterWriter: '<S12>/Parameter Writer4' incorporates:
  //   MATLABSystem: '<S12>/Read Parameter4'
  //
  controller_InstP.dutch_roll_freq = controller_B.ParamStep_cv;

  // ParameterWriter: '<S12>/Parameter Writer10' incorporates:
  //   DataTypeConversion: '<S12>/Cast To Double5'
  //   MATLABSystem: '<S12>/Read Parameter4'
  //   Product: '<S12>/Reciprocal1'
  //
  controller_InstP.dutch_roll_period = static_cast<real32_T>(1.0 /
    controller_B.ParamStep_cv);

  // MATLABSystem: '<S12>/Read Parameter8'
  b_varargout_1 = MW_ParamRead_Step(controller_DW.obj_p.MW_PARAMHANDLE,
    MW_SINGLE, &controller_InstP.phugoid_dur);
  if (b_varargout_1) {
    controller_InstP.phugoid_dur = 0.0F;
  }

  // MATLABSystem: '<S12>/Read Parameter2'
  b_varargout_1 = MW_ParamRead_Step(controller_DW.obj_ju.MW_PARAMHANDLE,
    MW_SINGLE, &controller_InstP.short_period_dur);
  if (b_varargout_1) {
    controller_InstP.short_period_dur = 0.0F;
  }

  // ParameterWriter: '<S12>/Parameter Writer9' incorporates:
  //   DataTypeConversion: '<S12>/Cast To Double8'
  //   MATLABSystem: '<S12>/Read Parameter7'
  //   Product: '<S12>/Reciprocal'
  //
  controller_InstP.phugoid_period = static_cast<real32_T>(1.0 /
    controller_B.ParamStep_c);

  // MATLABSystem: '<S12>/Read Parameter5'
  b_varargout_1 = MW_ParamRead_Step(controller_DW.obj_o5.MW_PARAMHANDLE,
    MW_SINGLE, &controller_InstP.dutch_roll_dur);
  if (b_varargout_1) {
    controller_InstP.dutch_roll_dur = 0.0F;
  }

  // ParameterWriter: '<S12>/Parameter Writer11' incorporates:
  //   DataTypeConversion: '<S12>/Cast To Double2'
  //   MATLABSystem: '<S12>/Read Parameter1'
  //   Product: '<S12>/Reciprocal2'
  //
  controller_InstP.short_period_period = static_cast<real32_T>(1.0 /
    controller_B.ParamStep);

  // If: '<S20>/Activate different control logics after activation flag is triggered' 
  if ((rtb_Saturation1 > 0.5F) && (rtb_Saturation < 0.5F)) {
    // Outputs for IfAction SubSystem: '<S20>/Mode Selection - SysID' incorporates:
    //   ActionPort: '<S29>/Action Port'

    // If: '<S29>/Set if condition for mode to be chosen' incorporates:
    //   MATLABSystem: '<S14>/Modulo by Constant'

    if ((controller_B.yTemp >= -0.5F) && (controller_B.yTemp < 0.5F)) {
      // Outputs for IfAction SubSystem: '<S29>/Short Period Doublet' incorporates:
      //   ActionPort: '<S151>/Action Port'

      // Switch: '<S151>/Set time to re-allow  pilot inputs'
      if (!(rtb_Converttimefromustos > controller_InstP.short_period_dur)) {
        // Switch: '<S151>/Set end time of doublet' incorporates:
        //   DataTypeConversion: '<S151>/Cast To Single'
        //   SignalGenerator: '<S151>/Doublet Generator'
        //   Sum: '<S151>/Sum Initial Pitch Input  and Doublet Wave'

        if (rtb_Converttimefromustos >= controller_InstP.short_period_period) {
          rtb_Saturation8 = controller_DW.Savedpitchinput_PreviousInput;
        } else {
          // SignalGenerator: '<S151>/Doublet Generator' incorporates:
          //   DataTypeConversion: '<S151>/Cast To Double'

          controller_B.temp = controller_InstP.short_period_freq *
            rtb_Converttimefromustos;
          if (controller_B.temp - floor(controller_B.temp) >= 0.5) {
            controller_B.temp = controller_InstP.short_period_amp;
          } else {
            controller_B.temp = -controller_InstP.short_period_amp;
          }

          rtb_Saturation8 = controller_DW.Savedpitchinput_PreviousInput +
            static_cast<real32_T>(controller_B.temp);
        }

        // End of Switch: '<S151>/Set end time of doublet'
      }

      // End of Switch: '<S151>/Set time to re-allow  pilot inputs'
      // End of Outputs for SubSystem: '<S29>/Short Period Doublet'
    } else if ((controller_B.yTemp >= 0.5F) && (controller_B.yTemp < 1.5F)) {
      // Outputs for IfAction SubSystem: '<S29>/Dutch Roll Doublet' incorporates:
      //   ActionPort: '<S149>/Action Port'

      // Switch: '<S149>/Set time to re-allow  pilot inputs'
      if (!(rtb_Converttimefromustos > controller_InstP.dutch_roll_dur)) {
        // Switch: '<S149>/Switch1'
        if (rtb_Converttimefromustos > controller_InstP.dutch_roll_period) {
          // DataTypeConversion: '<S149>/Cast To Single1'
          rtb_Saturation7 = controller_DW.Savedyawinput_PreviousInput;
        } else {
          // SignalGenerator: '<S149>/Doublet Generator' incorporates:
          //   DataTypeConversion: '<S149>/Cast To Double'

          controller_B.temp = controller_InstP.dutch_roll_freq *
            rtb_Converttimefromustos;
          if (controller_B.temp - floor(controller_B.temp) >= 0.5) {
            controller_B.temp = controller_InstP.dutch_roll_amp;
          } else {
            controller_B.temp = -controller_InstP.dutch_roll_amp;
          }

          // DataTypeConversion: '<S149>/Cast To Single1' incorporates:
          //   DataTypeConversion: '<S149>/Cast To Single'
          //   SignalGenerator: '<S149>/Doublet Generator'
          //   Sum: '<S149>/Sum Initial Yaw Input  and Doublet Wave'

          rtb_Saturation7 = controller_DW.Savedyawinput_PreviousInput +
            static_cast<real32_T>(controller_B.temp);
        }

        // End of Switch: '<S149>/Switch1'
      }

      // End of Switch: '<S149>/Set time to re-allow  pilot inputs'
      // End of Outputs for SubSystem: '<S29>/Dutch Roll Doublet'
    } else if ((controller_B.yTemp >= 1.5F) && (controller_B.yTemp < 2.5F)) {
      // Outputs for IfAction SubSystem: '<S29>/Phugoid Doublet' incorporates:
      //   ActionPort: '<S150>/Action Port'

      // Switch: '<S150>/Set time to re-allow  pilot inputs'
      if (!(rtb_Converttimefromustos > controller_InstP.phugoid_dur)) {
        // Switch: '<S150>/Switch1'
        if (rtb_Converttimefromustos > controller_InstP.phugoid_period) {
          // DataTypeConversion: '<S150>/Cast To Single1'
          rtb_Saturation10 = controller_DW.SavedThrustinput_PreviousInput;
        } else {
          // SignalGenerator: '<S150>/Doublet Generator' incorporates:
          //   DataTypeConversion: '<S150>/Cast To Double'

          controller_B.temp = controller_InstP.phugoid_freq *
            rtb_Converttimefromustos;
          if (controller_B.temp - floor(controller_B.temp) >= 0.5) {
            controller_B.temp = controller_InstP.phugoid_amp;
          } else {
            controller_B.temp = -controller_InstP.phugoid_amp;
          }

          // DataTypeConversion: '<S150>/Cast To Single1' incorporates:
          //   DataTypeConversion: '<S150>/Cast To Single'
          //   SignalGenerator: '<S150>/Doublet Generator'
          //   Sum: '<S150>/Sum Initial Thrust Input  and Doublet Wave'

          rtb_Saturation10 = controller_DW.SavedThrustinput_PreviousInput +
            static_cast<real32_T>(controller_B.temp);
        }

        // End of Switch: '<S150>/Switch1'
      }

      // End of Switch: '<S150>/Set time to re-allow  pilot inputs'
      // End of Outputs for SubSystem: '<S29>/Phugoid Doublet'
    }

    // End of If: '<S29>/Set if condition for mode to be chosen'
    // End of Outputs for SubSystem: '<S20>/Mode Selection - SysID'
  }

  // End of If: '<S20>/Activate different control logics after activation flag is triggered' 

  // MATLABSystem: '<S12>/Read Parameter12'
  b_varargout_1 = MW_ParamRead_Step(controller_DW.obj_gx.MW_PARAMHANDLE,
    MW_SINGLE, &controller_InstP.vel_con_gain_p);
  if (b_varargout_1) {
    controller_InstP.vel_con_gain_p = 0.0F;
  }

  // MATLABSystem: '<S12>/Read Parameter10'
  b_varargout_1 = MW_ParamRead_Step(controller_DW.obj_b.MW_PARAMHANDLE,
    MW_SINGLE, &controller_InstP.pitch_con_gain_p);
  if (b_varargout_1) {
    controller_InstP.pitch_con_gain_p = 0.0F;
  }

  // MATLABSystem: '<S12>/Read Parameter11'
  b_varargout_1 = MW_ParamRead_Step(controller_DW.obj_i.MW_PARAMHANDLE,
    MW_SINGLE, &controller_InstP.vel_con_gain_i);
  if (b_varargout_1) {
    controller_InstP.vel_con_gain_i = 0.0F;
  }

  // MATLABSystem: '<S12>/Read Parameter14'
  b_varargout_1 = MW_ParamRead_Step(controller_DW.obj_lx.MW_PARAMHANDLE,
    MW_SINGLE, &controller_InstP.vel_lp_freq);
  if (b_varargout_1) {
    controller_InstP.vel_lp_freq = 0.0F;
  }

  // MATLABSystem: '<S12>/Read Parameter9'
  b_varargout_1 = MW_ParamRead_Step(controller_DW.obj_mf.MW_PARAMHANDLE,
    MW_SINGLE, &controller_InstP.pitch_con_gain_i);
  if (b_varargout_1) {
    controller_InstP.pitch_con_gain_i = 0.0F;
  }

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
  rtb_Converttimefromustos = static_cast<real32_T>(asin(static_cast<real_T>
    ((controller_B.In1.q[1] * controller_B.In1.q[3] - controller_B.In1.q[0] *
      controller_B.In1.q[2]) * -2.0F)));

  // MATLABSystem: '<S152>/SourceBlock'
  b_varargout_1 = uORB_read_step(controller_DW.obj_m.orbMetadataObj,
    &controller_DW.obj_m.eventStructObj, &controller_B.r4, false, 1.0);

  // Outputs for Enabled SubSystem: '<S152>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S153>/Enable'

  // Start for MATLABSystem: '<S152>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S153>/In1'
    controller_B.In1_m = controller_B.r4;
  }

  // End of Outputs for SubSystem: '<S152>/Enabled Subsystem'

  // MATLABSystem: '<S14>/Read Parameter'
  b_varargout_1 = MW_ParamRead_Step(controller_DW.obj_nh.MW_PARAMHANDLE,
    MW_SINGLE, &controller_B.ParamStep_f);
  if (b_varargout_1) {
    controller_B.ParamStep_f = 0.0F;
  }

  // MATLABSystem: '<S14>/Read Parameter1'
  b_varargout_1 = MW_ParamRead_Step(controller_DW.obj_k.MW_PARAMHANDLE,
    MW_SINGLE, &controller_B.ParamStep_g);
  if (b_varargout_1) {
    controller_B.ParamStep_g = 0.0F;
  }

  // Outputs for Atomic SubSystem: '<S20>/Controller'
  // Switch: '<S24>/Switch3'
  if (rtb_Saturation > controller_P.Switch3_Threshold) {
    // Switch: '<S24>/Switch2' incorporates:
    //   Constant: '<S24>/Constant'

    if (rtb_Saturation1 > controller_P.Switch2_Threshold) {
      rtb_Saturation10 = controller_P.Constant_Value_b;
    }

    // End of Switch: '<S24>/Switch2'
  }

  // End of Switch: '<S24>/Switch3'
  controller_PX4Timestamp(&controller_B.PX4Timestamp_h);

  // Gain: '<S36>/Gain' incorporates:
  //   Constant: '<S36>/Constant'

  rtb_Add1_e = controller_P.Gain_Gain_b * controller_InstP.vel_lp_freq;

  // DiscreteFilter: '<S36>/Discrete Filter1' incorporates:
  //   Bias: '<S36>/Bias'
  //   Constant: '<S36>/Constant1'
  //   SignalConversion generated from: '<S36>/Vector Concatenate'

  controller_B.denAccum = controller_B.In1_m.true_airspeed_m_s - (rtb_Add1_e +
    controller_P.Bias_Bias) * controller_DW.DiscreteFilter1_states;
  numAccum = controller_P.Constant1_Value * controller_B.denAccum + rtb_Add1_e *
    controller_DW.DiscreteFilter1_states;

  // Sum: '<S36>/Sum' incorporates:
  //   DiscreteFilter: '<S36>/Discrete Filter1'
  //   MATLABSystem: '<S14>/Read Parameter1'
  //
  rtb_Gain_c = controller_B.ParamStep_g - numAccum;

  // DiscreteIntegrator: '<S128>/Integrator'
  if (controller_DW.Integrator_IC_LOADING != 0) {
    controller_DW.Integrator_DSTATE = rtb_Converttimefromustos;
  }

  if ((rtb_Saturation1 > 0.0F) && (controller_DW.Integrator_PrevResetState <= 0))
  {
    controller_DW.Integrator_DSTATE = rtb_Converttimefromustos;
  }

  // Sum: '<S137>/Sum' incorporates:
  //   DiscreteIntegrator: '<S128>/Integrator'
  //   Gain: '<S133>/Proportional Gain'

  rtb_OutputLimitation3 = controller_InstP.vel_con_gain_p * rtb_Gain_c +
    controller_DW.Integrator_DSTATE;

  // Saturate: '<S135>/Saturation'
  if (rtb_OutputLimitation3 > controller_P.PIDController_UpperSaturationLi) {
    rtb_Add1_e = controller_P.PIDController_UpperSaturationLi;
  } else if (rtb_OutputLimitation3 <
             controller_P.PIDController_LowerSaturationLi) {
    rtb_Add1_e = controller_P.PIDController_LowerSaturationLi;
  } else {
    rtb_Add1_e = rtb_OutputLimitation3;
  }

  // End of Saturate: '<S135>/Saturation'

  // Switch: '<S31>/Switch' incorporates:
  //   Gain: '<S19>/Gain1'
  //   MATLABSystem: '<S14>/Modulo by Constant'
  //   MATLABSystem: '<S14>/Read Parameter'
  //
  if (controller_B.yTemp > controller_P.Switch_Threshold_k) {
    rtb_Gain_j = rtb_Add1_e;
  } else {
    rtb_Gain_j = controller_P.Gain1_Gain_o * controller_B.ParamStep_f;
  }

  // End of Switch: '<S31>/Switch'

  // Sum: '<S35>/Sum'
  controller_B.ParamStep_f = rtb_Gain_j - rtb_Converttimefromustos;

  // DiscreteIntegrator: '<S74>/Integrator'
  if (controller_DW.Integrator_IC_LOADING_p != 0) {
    controller_DW.Integrator_DSTATE_e =
      controller_DW.Savedpitchinput_PreviousInput;
  }

  if (((rtb_Saturation1 > 0.0F) && (controller_DW.Integrator_PrevResetState_k <=
        0)) || ((rtb_Saturation1 <= 0.0F) &&
                (controller_DW.Integrator_PrevResetState_k == 1))) {
    controller_DW.Integrator_DSTATE_e =
      controller_DW.Savedpitchinput_PreviousInput;
  }

  // Sum: '<S83>/Sum' incorporates:
  //   DiscreteIntegrator: '<S74>/Integrator'
  //   Gain: '<S79>/Proportional Gain'

  rtb_Sum_p = controller_InstP.pitch_con_gain_p * controller_B.ParamStep_f +
    controller_DW.Integrator_DSTATE_e;

  // Saturate: '<S81>/Saturation'
  if (rtb_Sum_p > controller_P.PIDController_UpperSaturation_d) {
    rtb_Saturation_f = controller_P.PIDController_UpperSaturation_d;
  } else if (rtb_Sum_p < controller_P.PIDController_LowerSaturation_m) {
    rtb_Saturation_f = controller_P.PIDController_LowerSaturation_m;
  } else {
    rtb_Saturation_f = rtb_Sum_p;
  }

  // End of Saturate: '<S81>/Saturation'

  // BusAssignment: '<S32>/Bus Assignment' incorporates:
  //   Gain: '<S31>/Gain'
  //   Gain: '<S33>/Gain'
  //   Gain: '<S34>/Gain'
  //   MATLABSystem: '<S14>/Modulo by Constant'
  //   MATLABSystem: '<S14>/Read Parameter1'
  //   MATLABSystem: '<S32>/PX4 Timestamp'
  //
  controller_B.BusAssignment_e.timestamp =
    controller_B.PX4Timestamp_h.PX4Timestamp;
  controller_B.BusAssignment_e.activation_flag = rtb_Saturation1;
  controller_B.BusAssignment_e.mode_selector = controller_B.yTemp;
  controller_B.BusAssignment_e.test_mode_selector = rtb_Saturation;
  controller_B.BusAssignment_e.elevator_cmd = controller_P.Gain_Gain_p *
    rtb_Saturation_f;
  controller_B.BusAssignment_e.pitch_angle = controller_P.Gain_Gain_o *
    rtb_Converttimefromustos;
  controller_B.BusAssignment_e.pitch_angle_cmd = controller_P.Gain_Gain_m *
    rtb_Gain_j;
  controller_B.BusAssignment_e.airspeed = controller_B.In1_m.true_airspeed_m_s;
  controller_B.BusAssignment_e.airspeed_cmd = controller_B.ParamStep_g;

  // MATLABSystem: '<S38>/SinkBlock' incorporates:
  //   BusAssignment: '<S32>/Bus Assignment'

  uORB_write_step(controller_DW.obj_h0.orbMetadataObj,
                  &controller_DW.obj_h0.orbAdvertiseObj,
                  &controller_B.BusAssignment_e);
  controller_PX4Timestamp(&controller_B.PX4Timestamp_c);

  // BusAssignment: '<S93>/Bus Assignment' incorporates:
  //   DiscreteFilter: '<S36>/Discrete Filter1'
  //   MATLABSystem: '<S93>/PX4 Timestamp'

  controller_B.BusAssignment_k.timestamp =
    controller_B.PX4Timestamp_c.PX4Timestamp;
  controller_B.BusAssignment_k.v_raw = controller_B.In1_m.true_airspeed_m_s;
  controller_B.BusAssignment_k.v_filtered = numAccum;

  // MATLABSystem: '<S147>/SinkBlock' incorporates:
  //   BusAssignment: '<S93>/Bus Assignment'

  uORB_write_step(controller_DW.obj_n.orbMetadataObj,
                  &controller_DW.obj_n.orbAdvertiseObj,
                  &controller_B.BusAssignment_k);

  // Update for DiscreteFilter: '<S36>/Discrete Filter1'
  controller_DW.DiscreteFilter1_states = controller_B.denAccum;

  // Update for DiscreteIntegrator: '<S128>/Integrator' incorporates:
  //   DiscreteIntegrator: '<S74>/Integrator'
  //   Gain: '<S120>/Kb'
  //   Gain: '<S125>/Integral Gain'
  //   Sum: '<S120>/SumI2'
  //   Sum: '<S120>/SumI4'

  controller_DW.Integrator_IC_LOADING = 0U;
  controller_DW.Integrator_DSTATE += ((rtb_Add1_e - rtb_OutputLimitation3) *
    controller_P.PIDController_Kb_p + controller_InstP.vel_con_gain_i *
    rtb_Gain_c) * controller_P.Integrator_gainval;
  if (rtb_Saturation1 > 0.0F) {
    controller_DW.Integrator_PrevResetState = 1;
    controller_DW.Integrator_PrevResetState_k = 1;
  } else if (rtb_Saturation1 < 0.0F) {
    controller_DW.Integrator_PrevResetState = -1;
    controller_DW.Integrator_PrevResetState_k = -1;
  } else if (rtb_Saturation1 == 0.0F) {
    controller_DW.Integrator_PrevResetState = 0;
    controller_DW.Integrator_PrevResetState_k = 0;
  } else {
    controller_DW.Integrator_PrevResetState = 2;
    controller_DW.Integrator_PrevResetState_k = 2;
  }

  // End of Update for DiscreteIntegrator: '<S128>/Integrator'

  // Update for DiscreteIntegrator: '<S74>/Integrator' incorporates:
  //   Gain: '<S66>/Kb'
  //   Gain: '<S71>/Integral Gain'
  //   Sum: '<S66>/SumI2'
  //   Sum: '<S66>/SumI4'

  controller_DW.Integrator_IC_LOADING_p = 0U;
  controller_DW.Integrator_DSTATE_e += ((rtb_Saturation_f - rtb_Sum_p) *
    controller_P.PIDController_Kb + controller_InstP.pitch_con_gain_i *
    controller_B.ParamStep_f) * controller_P.Integrator_gainval_b;

  // Switch: '<S24>/Switch1'
  if (rtb_Saturation > controller_P.Switch1_Threshold) {
    // Switch: '<S24>/Switch'
    if (rtb_Saturation1 > controller_P.Switch_Threshold) {
      rtb_Saturation8 = rtb_Saturation_f;
    }

    // End of Switch: '<S24>/Switch'
  }

  // Gain: '<S22>/Pitch control portion' incorporates:
  //   Switch: '<S24>/Switch1'

  rtb_OutputLimitation3 = controller_P.Pitchcontrolportion_Gain *
    rtb_Saturation8;

  // End of Outputs for SubSystem: '<S20>/Controller'

  // Fcn: '<S13>/Fcn2' incorporates:
  //   DataTypeConversion: '<S13>/Data Type Conversion'

  controller_B.ParamStep_g = (static_cast<real32_T>(controller_B.In1_d.values[0])
    - 1500.0F) / 500.0F;

  // Saturate: '<S13>/Saturation9'
  if (controller_B.ParamStep_g > controller_P.Saturation9_UpperSat) {
    controller_B.ParamStep_g = controller_P.Saturation9_UpperSat;
  } else if (controller_B.ParamStep_g < controller_P.Saturation9_LowerSat) {
    controller_B.ParamStep_g = controller_P.Saturation9_LowerSat;
  }

  // Gain: '<S22>/Roll control portion' incorporates:
  //   Gain: '<S13>/Gain'
  //   Saturate: '<S13>/Saturation9'

  rtb_Saturation8 = controller_P.Gain_Gain_h * controller_B.ParamStep_g *
    controller_P.Rollcontrolportion_Gain;

  // Sum: '<S22>/Add Elevon Left'
  rtb_Gain_c = rtb_Saturation8 - rtb_OutputLimitation3;

  // Sum: '<S22>/Add Elevon Right'
  rtb_Saturation8 = (0.0F - rtb_Saturation8) - rtb_OutputLimitation3;

  // Fcn: '<S14>/Fcn7' incorporates:
  //   DataTypeConversion: '<S14>/Cast To Single'

  controller_B.ParamStep_g = (static_cast<real32_T>(controller_B.In1_d.values[5])
    - 1000.0F) / 500.0F;

  // Saturate: '<S14>/Saturation7'
  if (controller_B.ParamStep_g > controller_P.Saturation7_UpperSat_m) {
    controller_B.ParamStep_g = controller_P.Saturation7_UpperSat_m;
  } else if (controller_B.ParamStep_g < controller_P.Saturation7_LowerSat_b) {
    controller_B.ParamStep_g = controller_P.Saturation7_LowerSat_b;
  }

  // Switch: '<S23>/Switch' incorporates:
  //   Constant: '<S23>/No Rudder Deflection Value'
  //   Constant: '<S23>/Spoiler Rudder Deflection Value'
  //   Saturate: '<S14>/Saturation7'

  if (controller_B.ParamStep_g > controller_P.Switch_Threshold_j) {
    rtb_Add1_e = controller_P.SpoilerRudderDeflectionValue_Va;
  } else {
    rtb_Add1_e = controller_P.NoRudderDeflectionValue_Value;
  }

  // End of Switch: '<S23>/Switch'

  // Switch: '<S23>/Deflection Logic Rudder Right' incorporates:
  //   Constant: '<S23>/No Rudder Deflection Value'

  if (rtb_Saturation7 > controller_P.DeflectionLogicRudderRight_Thre) {
    rtb_OutputLimitation3 = rtb_Saturation7;
  } else {
    rtb_OutputLimitation3 = controller_P.NoRudderDeflectionValue_Value;
  }

  // Fcn: '<S23>/Function for Deflection Value Rudder Right' incorporates:
  //   Sum: '<S23>/Add'
  //   Switch: '<S23>/Deflection Logic Rudder Right'

  rtb_OutputLimitation3 = ((rtb_OutputLimitation3 + rtb_Add1_e) - 0.5F) * 2.0F;

  // Gain: '<S23>/Reverse for Rudder Left'
  rtb_Saturation7 *= controller_P.ReverseforRudderLeft_Gain;

  // Switch: '<S23>/Deflection Logic Rudder Left' incorporates:
  //   Constant: '<S23>/No Rudder Deflection Value'

  if (!(rtb_Saturation7 > controller_P.DeflectionLogicRudderLeft_Thres)) {
    rtb_Saturation7 = controller_P.NoRudderDeflectionValue_Value;
  }

  // Fcn: '<S23>/Function for Deflection Value Rudder Left' incorporates:
  //   Sum: '<S23>/Add1'
  //   Switch: '<S23>/Deflection Logic Rudder Left'

  rtb_Add1_e = ((rtb_Add1_e + rtb_Saturation7) - 0.5F) * 2.0F;

  // Gain: '<S2>/Control Authority Gain'
  controller_B.ParamStep_g = controller_P.ControlAuthorityGain_Gain * rtb_Gain_c;
  rtb_Saturation7 = controller_P.ControlAuthorityGain_Gain * rtb_Saturation8;

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
  if (rtb_Saturation10 > controller_P.OutputLimitation_UpperSat) {
    // MATLABSystem: '<Root>/PX4 Actuator Write'
    controller_B.motorValues[0] = controller_P.OutputLimitation_UpperSat;
    controller_B.motorValues[1] = controller_P.OutputLimitation_UpperSat;
  } else if (rtb_Saturation10 < controller_P.OutputLimitation_LowerSat) {
    // MATLABSystem: '<Root>/PX4 Actuator Write'
    controller_B.motorValues[0] = controller_P.OutputLimitation_LowerSat;
    controller_B.motorValues[1] = controller_P.OutputLimitation_LowerSat;
  } else {
    // MATLABSystem: '<Root>/PX4 Actuator Write'
    controller_B.motorValues[0] = rtb_Saturation10;
    controller_B.motorValues[1] = rtb_Saturation10;
  }

  if (controller_B.ParamStep_g > controller_P.OutputLimitation_UpperSat) {
    // MATLABSystem: '<Root>/PX4 Actuator Write'
    controller_B.servoValues[0] = controller_P.OutputLimitation_UpperSat;
  } else if (controller_B.ParamStep_g < controller_P.OutputLimitation_LowerSat)
  {
    // MATLABSystem: '<Root>/PX4 Actuator Write'
    controller_B.servoValues[0] = controller_P.OutputLimitation_LowerSat;
  } else {
    // MATLABSystem: '<Root>/PX4 Actuator Write'
    controller_B.servoValues[0] = controller_B.ParamStep_g;
  }

  if (rtb_Saturation7 > controller_P.OutputLimitation_UpperSat) {
    // MATLABSystem: '<Root>/PX4 Actuator Write'
    controller_B.servoValues[5] = controller_P.OutputLimitation_UpperSat;
  } else if (rtb_Saturation7 < controller_P.OutputLimitation_LowerSat) {
    // MATLABSystem: '<Root>/PX4 Actuator Write'
    controller_B.servoValues[5] = controller_P.OutputLimitation_LowerSat;
  } else {
    // MATLABSystem: '<Root>/PX4 Actuator Write'
    controller_B.servoValues[5] = rtb_Saturation7;
  }

  if (rtb_OutputLimitation3 > controller_P.OutputLimitation_UpperSat) {
    // MATLABSystem: '<Root>/PX4 Actuator Write'
    controller_B.servoValues[6] = controller_P.OutputLimitation_UpperSat;
  } else if (rtb_OutputLimitation3 < controller_P.OutputLimitation_LowerSat) {
    // MATLABSystem: '<Root>/PX4 Actuator Write'
    controller_B.servoValues[6] = controller_P.OutputLimitation_LowerSat;
  } else {
    // MATLABSystem: '<Root>/PX4 Actuator Write'
    controller_B.servoValues[6] = rtb_OutputLimitation3;
  }

  if (rtb_Add1_e > controller_P.OutputLimitation_UpperSat) {
    // MATLABSystem: '<Root>/PX4 Actuator Write'
    controller_B.servoValues[7] = controller_P.OutputLimitation_UpperSat;
  } else if (rtb_Add1_e < controller_P.OutputLimitation_LowerSat) {
    // MATLABSystem: '<Root>/PX4 Actuator Write'
    controller_B.servoValues[7] = controller_P.OutputLimitation_LowerSat;
  } else {
    // MATLABSystem: '<Root>/PX4 Actuator Write'
    controller_B.servoValues[7] = rtb_Add1_e;
  }

  // End of Saturate: '<S2>/Output Limitation'

  // MATLABSystem: '<Root>/PX4 Actuator Write' incorporates:
  //   Constant: '<S17>/Constant'
  //   RelationalOperator: '<S17>/Compare'

  MW_actuators_set(controller_B.In1_d.values[4] >=
                   controller_P.CompareToConstant3_const,
                   &controller_B.motorValues[0], &controller_B.servoValues[0]);
  controller_PX4Timestamp(&controller_B.PX4Timestamp_n);

  // Saturate: '<S15>/Output Limitation1'
  if (rtb_Gain_c > controller_P.OutputLimitation1_UpperSat) {
    rtb_Gain_c = controller_P.OutputLimitation1_UpperSat;
  } else if (rtb_Gain_c < controller_P.OutputLimitation1_LowerSat) {
    rtb_Gain_c = controller_P.OutputLimitation1_LowerSat;
  }

  // End of Saturate: '<S15>/Output Limitation1'

  // Saturate: '<S15>/Output Limitation'
  if (rtb_Saturation8 > controller_P.OutputLimitation_UpperSat_m) {
    rtb_Saturation8 = controller_P.OutputLimitation_UpperSat_m;
  } else if (rtb_Saturation8 < controller_P.OutputLimitation_LowerSat_l) {
    rtb_Saturation8 = controller_P.OutputLimitation_LowerSat_l;
  }

  // End of Saturate: '<S15>/Output Limitation'

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
  //   Gain: '<S15>/Gain'
  //   Gain: '<S15>/Gain1'
  //   MATLABSystem: '<S14>/Modulo by Constant'
  //   MATLABSystem: '<S159>/PX4 Timestamp'
  //   Sum: '<S15>/Add'
  //   Sum: '<S15>/Sum'

  controller_B.BusAssignment_c.timestamp =
    controller_B.PX4Timestamp_n.PX4Timestamp;
  controller_B.BusAssignment_c.activation_flag = rtb_Saturation1;
  controller_B.BusAssignment_c.mode_selector = controller_B.yTemp;
  controller_B.BusAssignment_c.test_mode_selector = rtb_Saturation;
  controller_B.BusAssignment_c.aileron = (rtb_Saturation8 - rtb_Gain_c) *
    controller_P.Gain1_Gain_a;
  controller_B.BusAssignment_c.elevator = (rtb_Saturation8 + rtb_Gain_c) *
    controller_P.Gain_Gain_l;

  // Saturate: '<S15>/Output Limitation3'
  if (rtb_OutputLimitation3 > controller_P.OutputLimitation3_UpperSat) {
    rtb_OutputLimitation3 = controller_P.OutputLimitation3_UpperSat;
  } else if (rtb_OutputLimitation3 < controller_P.OutputLimitation3_LowerSat) {
    rtb_OutputLimitation3 = controller_P.OutputLimitation3_LowerSat;
  }

  // Saturate: '<S15>/Output Limitation2'
  if (rtb_Add1_e > controller_P.OutputLimitation2_UpperSat) {
    rtb_Add1_e = controller_P.OutputLimitation2_UpperSat;
  } else if (rtb_Add1_e < controller_P.OutputLimitation2_LowerSat) {
    rtb_Add1_e = controller_P.OutputLimitation2_LowerSat;
  }

  // BusAssignment: '<S159>/Bus Assignment' incorporates:
  //   Fcn: '<S15>/Fcn1'
  //   Fcn: '<S15>/Fcn5'
  //   MATLAB Function: '<S2>/quat2eul'
  //   Saturate: '<S15>/Output Limitation2'
  //   Saturate: '<S15>/Output Limitation3'
  //   Sum: '<S15>/Add1'

  controller_B.BusAssignment_c.rudder = (rtb_OutputLimitation3 + 1.0F) / 2.0F -
    (rtb_Add1_e + 1.0F) / 2.0F;
  controller_B.BusAssignment_c.throttle = rtb_Saturation10;
  controller_B.BusAssignment_c.roll_rate = controller_B.In1_k.x;
  controller_B.BusAssignment_c.pitch_rate = controller_B.In1_k.y;
  controller_B.BusAssignment_c.yaw_rate = controller_B.In1_k.z;
  controller_B.BusAssignment_c.roll_angle = rt_atan2f_snf((controller_B.In1.q[0]
    * controller_B.In1.q[1] + controller_B.In1.q[2] * controller_B.In1.q[3]) *
    2.0F, ((controller_B.In1.q[0] * controller_B.In1.q[0] - controller_B.In1.q[1]
            * controller_B.In1.q[1]) - controller_B.In1.q[2] *
           controller_B.In1.q[2]) + controller_B.In1.q[3] * controller_B.In1.q[3]);
  controller_B.BusAssignment_c.pitch_angle = rtb_Converttimefromustos;
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

  // MATLABSystem: '<S12>/Read Parameter13'
  b_varargout_1 = MW_ParamRead_Step(controller_DW.obj_lp.MW_PARAMHANDLE,
    MW_INT32, &controller_B.ParamStep_g1);
  if (b_varargout_1) {
    controller_B.ParamStep_g1 = 0;
  }

  // BusAssignment: '<S156>/Bus Assignment' incorporates:
  //   DataTypeConversion: '<S12>/Data Type Conversion'
  //   MATLABSystem: '<S12>/Read Parameter'
  //   MATLABSystem: '<S12>/Read Parameter1'
  //   MATLABSystem: '<S12>/Read Parameter10'
  //   MATLABSystem: '<S12>/Read Parameter11'
  //   MATLABSystem: '<S12>/Read Parameter12'
  //   MATLABSystem: '<S12>/Read Parameter13'
  //   MATLABSystem: '<S12>/Read Parameter14'
  //   MATLABSystem: '<S12>/Read Parameter2'
  //   MATLABSystem: '<S12>/Read Parameter3'
  //   MATLABSystem: '<S12>/Read Parameter4'
  //   MATLABSystem: '<S12>/Read Parameter5'
  //   MATLABSystem: '<S12>/Read Parameter6'
  //   MATLABSystem: '<S12>/Read Parameter7'
  //   MATLABSystem: '<S12>/Read Parameter8'
  //   MATLABSystem: '<S12>/Read Parameter9'
  //   MATLABSystem: '<S156>/PX4 Timestamp'
  //
  controller_B.BusAssignment.timestamp = controller_B.PX4Timestamp.PX4Timestamp;
  controller_B.BusAssignment.sp_doublet_amp = controller_B.ParamStep_b;
  controller_B.BusAssignment.sp_doublet_freq = controller_B.ParamStep;
  controller_B.BusAssignment.sp_doublet_dur = controller_InstP.short_period_dur;
  controller_B.BusAssignment.dr_doublet_amp = controller_B.ParamStep_k;
  controller_B.BusAssignment.dr_doublet_freq = controller_B.ParamStep_cv;
  controller_B.BusAssignment.dr_doublet_dur = controller_InstP.dutch_roll_dur;
  controller_B.BusAssignment.ph_doublet_amp = controller_B.ParamStep_p;
  controller_B.BusAssignment.ph_doublet_freq = controller_B.ParamStep_c;
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

  // MATLABSystem: '<S154>/SourceBlock'
  uORB_read_step(controller_DW.obj_j.orbMetadataObj,
                 &controller_DW.obj_j.eventStructObj, &controller_B.r1, false,
                 1.0);
}

// Model initialize function
void controller_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  {
    static const char_T ParameterNameStr[14] = "MODE_SELECTOR";
    static const char_T ParameterNameStr_0[16] = "SP_DOUBLET_FREQ";
    static const char_T ParameterNameStr_1[15] = "DR_DOUBLET_AMP";
    static const char_T ParameterNameStr_2[16] = "PH_DOUBLET_FREQ";
    static const char_T ParameterNameStr_3[15] = "SP_DOUBLET_AMP";
    static const char_T ParameterNameStr_4[15] = "PH_DOUBLET_AMP";
    static const char_T ParameterNameStr_5[16] = "DR_DOUBLET_FREQ";
    static const char_T ParameterNameStr_6[15] = "PH_DOUBLET_DUR";
    static const char_T ParameterNameStr_7[15] = "SP_DOUBLET_DUR";
    static const char_T ParameterNameStr_8[15] = "DR_DOUBLET_DUR";
    static const char_T ParameterNameStr_9[17] = "VEL_CONTR_GAIN_P";
    static const char_T ParameterNameStr_a[17] = "PITCH_CON_GAIN_P";
    static const char_T ParameterNameStr_b[17] = "VEL_CONTR_GAIN_I";
    static const char_T ParameterNameStr_c[12] = "VEL_LP_FREQ";
    static const char_T ParameterNameStr_d[17] = "PITCH_CON_GAIN_I";
    static const char_T ParameterNameStr_e[14] = "THETA_COMMAND";
    static const char_T ParameterNameStr_f[17] = "AIRSPEED_COMMAND";
    static const char_T ParameterNameStr_g[13] = "PILOT_MARKER";
    int32_T i;

    // InitializeConditions for Switch: '<S26>/Check for activation' incorporates:
    //   Memory: '<S26>/Saved pitch input'

    controller_DW.Savedpitchinput_PreviousInput =
      controller_P.Savedpitchinput_InitialConditio;

    // InitializeConditions for Switch: '<S28>/Check for activation' incorporates:
    //   Memory: '<S28>/Saved yaw input'

    controller_DW.Savedyawinput_PreviousInput =
      controller_P.Savedyawinput_InitialCondition;

    // InitializeConditions for Switch: '<S27>/Check for activation' incorporates:
    //   Memory: '<S27>/Saved Thrust input'

    controller_DW.SavedThrustinput_PreviousInput =
      controller_P.SavedThrustinput_InitialConditi;

    // InitializeConditions for Switch: '<S30>/Give stored time instead  of current time after activation' incorporates:
    //   Memory: '<S30>/Store Start Time'

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

    // SystemInitialize for Enabled SubSystem: '<S152>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S153>/In1' incorporates:
    //   Outport: '<S153>/Out1'

    controller_B.In1_m = controller_P.Out1_Y0_io;

    // End of SystemInitialize for SubSystem: '<S152>/Enabled Subsystem'

    // SystemInitialize for Atomic SubSystem: '<S20>/Controller'
    // InitializeConditions for DiscreteFilter: '<S36>/Discrete Filter1'
    controller_DW.DiscreteFilter1_states =
      controller_P.DiscreteFilter1_InitialStates;

    // InitializeConditions for DiscreteIntegrator: '<S128>/Integrator'
    controller_DW.Integrator_PrevResetState = 2;
    controller_DW.Integrator_IC_LOADING = 1U;

    // InitializeConditions for DiscreteIntegrator: '<S74>/Integrator'
    controller_DW.Integrator_PrevResetState_k = 2;
    controller_DW.Integrator_IC_LOADING_p = 1U;
    controller_PX4Timestamp_Init(&controller_DW.PX4Timestamp_h);

    // Start for MATLABSystem: '<S38>/SinkBlock' incorporates:
    //   BusAssignment: '<S32>/Bus Assignment'

    controller_DW.obj_h0.matlabCodegenIsDeleted = false;
    controller_DW.obj_h0.isSetupComplete = false;
    controller_DW.obj_h0.isInitialized = 1;
    controller_DW.obj_h0.orbMetadataObj = ORB_ID(glide_controller);
    uORB_write_initialize(controller_DW.obj_h0.orbMetadataObj,
                          &controller_DW.obj_h0.orbAdvertiseObj,
                          &controller_B.BusAssignment_e, 1);
    controller_DW.obj_h0.isSetupComplete = true;
    controller_PX4Timestamp_Init(&controller_DW.PX4Timestamp_c);

    // Start for MATLABSystem: '<S147>/SinkBlock' incorporates:
    //   BusAssignment: '<S93>/Bus Assignment'

    controller_DW.obj_n.matlabCodegenIsDeleted = false;
    controller_DW.obj_n.isSetupComplete = false;
    controller_DW.obj_n.isInitialized = 1;
    controller_DW.obj_n.orbMetadataObj = ORB_ID(velocity_filter);
    uORB_write_initialize(controller_DW.obj_n.orbMetadataObj,
                          &controller_DW.obj_n.orbAdvertiseObj,
                          &controller_B.BusAssignment_k, 1);
    controller_DW.obj_n.isSetupComplete = true;

    // End of SystemInitialize for SubSystem: '<S20>/Controller'

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

    // Start for MATLABSystem: '<S14>/Read Parameter2'
    controller_DW.obj_ms.matlabCodegenIsDeleted = false;
    controller_DW.obj_ms.isInitialized = 1;
    controller_DW.obj_ms.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr[0],
      true, 4.0);
    controller_DW.obj_ms.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/PX4 Timestamp'
    controller_DW.obj_h.matlabCodegenIsDeleted = false;
    controller_DW.obj_h.isInitialized = 1;
    controller_DW.obj_h.isSetupComplete = true;

    // Start for MATLABSystem: '<S12>/Read Parameter1'
    controller_DW.obj_a.matlabCodegenIsDeleted = false;
    controller_DW.obj_a.isInitialized = 1;
    controller_DW.obj_a.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_0[0],
      true, 4.0);
    controller_DW.obj_a.isSetupComplete = true;

    // Start for MATLABSystem: '<S12>/Read Parameter3'
    controller_DW.obj_f.matlabCodegenIsDeleted = false;
    controller_DW.obj_f.isInitialized = 1;
    controller_DW.obj_f.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_1[0],
      true, 4.0);
    controller_DW.obj_f.isSetupComplete = true;

    // Start for MATLABSystem: '<S12>/Read Parameter7'
    controller_DW.obj_l1.matlabCodegenIsDeleted = false;
    controller_DW.obj_l1.isInitialized = 1;
    controller_DW.obj_l1.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_2[0],
      true, 4.0);
    controller_DW.obj_l1.isSetupComplete = true;

    // Start for MATLABSystem: '<S12>/Read Parameter'
    controller_DW.obj_ng.matlabCodegenIsDeleted = false;
    controller_DW.obj_ng.isInitialized = 1;
    controller_DW.obj_ng.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_3[0],
      true, 4.0);
    controller_DW.obj_ng.isSetupComplete = true;

    // Start for MATLABSystem: '<S12>/Read Parameter6'
    controller_DW.obj_pe.matlabCodegenIsDeleted = false;
    controller_DW.obj_pe.isInitialized = 1;
    controller_DW.obj_pe.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_4[0],
      true, 4.0);
    controller_DW.obj_pe.isSetupComplete = true;

    // Start for MATLABSystem: '<S12>/Read Parameter4'
    controller_DW.obj_e.matlabCodegenIsDeleted = false;
    controller_DW.obj_e.isInitialized = 1;
    controller_DW.obj_e.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_5[0],
      true, 4.0);
    controller_DW.obj_e.isSetupComplete = true;

    // Start for MATLABSystem: '<S12>/Read Parameter8'
    controller_DW.obj_p.matlabCodegenIsDeleted = false;
    controller_DW.obj_p.isInitialized = 1;
    controller_DW.obj_p.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_6[0],
      true, 4.0);
    controller_DW.obj_p.isSetupComplete = true;

    // Start for MATLABSystem: '<S12>/Read Parameter2'
    controller_DW.obj_ju.matlabCodegenIsDeleted = false;
    controller_DW.obj_ju.isInitialized = 1;
    controller_DW.obj_ju.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_7[0],
      true, 4.0);
    controller_DW.obj_ju.isSetupComplete = true;

    // Start for MATLABSystem: '<S12>/Read Parameter5'
    controller_DW.obj_o5.matlabCodegenIsDeleted = false;
    controller_DW.obj_o5.isInitialized = 1;
    controller_DW.obj_o5.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_8[0],
      true, 4.0);
    controller_DW.obj_o5.isSetupComplete = true;

    // Start for MATLABSystem: '<S12>/Read Parameter12'
    controller_DW.obj_gx.matlabCodegenIsDeleted = false;
    controller_DW.obj_gx.isInitialized = 1;
    controller_DW.obj_gx.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_9[0],
      true, 4.0);
    controller_DW.obj_gx.isSetupComplete = true;

    // Start for MATLABSystem: '<S12>/Read Parameter10'
    controller_DW.obj_b.matlabCodegenIsDeleted = false;
    controller_DW.obj_b.isInitialized = 1;
    controller_DW.obj_b.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_a[0],
      true, 4.0);
    controller_DW.obj_b.isSetupComplete = true;

    // Start for MATLABSystem: '<S12>/Read Parameter11'
    controller_DW.obj_i.matlabCodegenIsDeleted = false;
    controller_DW.obj_i.isInitialized = 1;
    controller_DW.obj_i.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_b[0],
      true, 4.0);
    controller_DW.obj_i.isSetupComplete = true;

    // Start for MATLABSystem: '<S12>/Read Parameter14'
    controller_DW.obj_lx.matlabCodegenIsDeleted = false;
    controller_DW.obj_lx.isInitialized = 1;
    controller_DW.obj_lx.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_c[0],
      true, 4.0);
    controller_DW.obj_lx.isSetupComplete = true;

    // Start for MATLABSystem: '<S12>/Read Parameter9'
    controller_DW.obj_mf.matlabCodegenIsDeleted = false;
    controller_DW.obj_mf.isInitialized = 1;
    controller_DW.obj_mf.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_d[0],
      true, 4.0);
    controller_DW.obj_mf.isSetupComplete = true;

    // Start for MATLABSystem: '<S166>/SourceBlock'
    controller_DW.obj_l.matlabCodegenIsDeleted = false;
    controller_DW.obj_l.isSetupComplete = false;
    controller_DW.obj_l.isInitialized = 1;
    controller_DW.obj_l.orbMetadataObj = ORB_ID(vehicle_odometry);
    uORB_read_initialize(controller_DW.obj_l.orbMetadataObj,
                         &controller_DW.obj_l.eventStructObj);
    controller_DW.obj_l.isSetupComplete = true;

    // Start for MATLABSystem: '<S152>/SourceBlock'
    controller_DW.obj_m.matlabCodegenIsDeleted = false;
    controller_DW.obj_m.isSetupComplete = false;
    controller_DW.obj_m.isInitialized = 1;
    controller_DW.obj_m.orbMetadataObj = ORB_ID(airspeed);
    uORB_read_initialize(controller_DW.obj_m.orbMetadataObj,
                         &controller_DW.obj_m.eventStructObj);
    controller_DW.obj_m.isSetupComplete = true;

    // Start for MATLABSystem: '<S14>/Read Parameter'
    controller_DW.obj_nh.matlabCodegenIsDeleted = false;
    controller_DW.obj_nh.isInitialized = 1;
    controller_DW.obj_nh.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_e[0],
      true, 4.0);
    controller_DW.obj_nh.isSetupComplete = true;

    // Start for MATLABSystem: '<S14>/Read Parameter1'
    controller_DW.obj_k.matlabCodegenIsDeleted = false;
    controller_DW.obj_k.isInitialized = 1;
    controller_DW.obj_k.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_f[0],
      true, 4.0);
    controller_DW.obj_k.isSetupComplete = true;

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

    // Start for MATLABSystem: '<S12>/Read Parameter13'
    controller_DW.obj_lp.matlabCodegenIsDeleted = false;
    controller_DW.obj_lp.isInitialized = 1;
    controller_DW.obj_lp.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_g[0],
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

    // Start for MATLABSystem: '<S154>/SourceBlock'
    controller_DW.obj_j.matlabCodegenIsDeleted = false;
    controller_DW.obj_j.isSetupComplete = false;
    controller_DW.obj_j.isInitialized = 1;
    controller_DW.obj_j.orbMetadataObj = ORB_ID(input_rc);
    uORB_read_initialize(controller_DW.obj_j.orbMetadataObj,
                         &controller_DW.obj_j.eventStructObj);
    controller_DW.obj_j.isSetupComplete = true;
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

  // Terminate for MATLABSystem: '<S14>/Read Parameter2'
  if (!controller_DW.obj_ms.matlabCodegenIsDeleted) {
    controller_DW.obj_ms.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S14>/Read Parameter2'

  // Terminate for MATLABSystem: '<Root>/PX4 Timestamp'
  if (!controller_DW.obj_h.matlabCodegenIsDeleted) {
    controller_DW.obj_h.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/PX4 Timestamp'

  // Terminate for MATLABSystem: '<S12>/Read Parameter1'
  if (!controller_DW.obj_a.matlabCodegenIsDeleted) {
    controller_DW.obj_a.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S12>/Read Parameter1'

  // Terminate for MATLABSystem: '<S12>/Read Parameter3'
  if (!controller_DW.obj_f.matlabCodegenIsDeleted) {
    controller_DW.obj_f.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S12>/Read Parameter3'

  // Terminate for MATLABSystem: '<S12>/Read Parameter7'
  if (!controller_DW.obj_l1.matlabCodegenIsDeleted) {
    controller_DW.obj_l1.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S12>/Read Parameter7'

  // Terminate for MATLABSystem: '<S12>/Read Parameter'
  if (!controller_DW.obj_ng.matlabCodegenIsDeleted) {
    controller_DW.obj_ng.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S12>/Read Parameter'

  // Terminate for MATLABSystem: '<S12>/Read Parameter6'
  if (!controller_DW.obj_pe.matlabCodegenIsDeleted) {
    controller_DW.obj_pe.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S12>/Read Parameter6'

  // Terminate for MATLABSystem: '<S12>/Read Parameter4'
  if (!controller_DW.obj_e.matlabCodegenIsDeleted) {
    controller_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S12>/Read Parameter4'

  // Terminate for MATLABSystem: '<S12>/Read Parameter8'
  if (!controller_DW.obj_p.matlabCodegenIsDeleted) {
    controller_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S12>/Read Parameter8'

  // Terminate for MATLABSystem: '<S12>/Read Parameter2'
  if (!controller_DW.obj_ju.matlabCodegenIsDeleted) {
    controller_DW.obj_ju.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S12>/Read Parameter2'

  // Terminate for MATLABSystem: '<S12>/Read Parameter5'
  if (!controller_DW.obj_o5.matlabCodegenIsDeleted) {
    controller_DW.obj_o5.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S12>/Read Parameter5'

  // Terminate for MATLABSystem: '<S12>/Read Parameter12'
  if (!controller_DW.obj_gx.matlabCodegenIsDeleted) {
    controller_DW.obj_gx.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S12>/Read Parameter12'

  // Terminate for MATLABSystem: '<S12>/Read Parameter10'
  if (!controller_DW.obj_b.matlabCodegenIsDeleted) {
    controller_DW.obj_b.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S12>/Read Parameter10'

  // Terminate for MATLABSystem: '<S12>/Read Parameter11'
  if (!controller_DW.obj_i.matlabCodegenIsDeleted) {
    controller_DW.obj_i.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S12>/Read Parameter11'

  // Terminate for MATLABSystem: '<S12>/Read Parameter14'
  if (!controller_DW.obj_lx.matlabCodegenIsDeleted) {
    controller_DW.obj_lx.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S12>/Read Parameter14'

  // Terminate for MATLABSystem: '<S12>/Read Parameter9'
  if (!controller_DW.obj_mf.matlabCodegenIsDeleted) {
    controller_DW.obj_mf.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S12>/Read Parameter9'

  // Terminate for MATLABSystem: '<S166>/SourceBlock'
  if (!controller_DW.obj_l.matlabCodegenIsDeleted) {
    controller_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((controller_DW.obj_l.isInitialized == 1) &&
        controller_DW.obj_l.isSetupComplete) {
      uORB_read_terminate(&controller_DW.obj_l.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S166>/SourceBlock'

  // Terminate for MATLABSystem: '<S152>/SourceBlock'
  if (!controller_DW.obj_m.matlabCodegenIsDeleted) {
    controller_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((controller_DW.obj_m.isInitialized == 1) &&
        controller_DW.obj_m.isSetupComplete) {
      uORB_read_terminate(&controller_DW.obj_m.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S152>/SourceBlock'

  // Terminate for MATLABSystem: '<S14>/Read Parameter'
  if (!controller_DW.obj_nh.matlabCodegenIsDeleted) {
    controller_DW.obj_nh.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S14>/Read Parameter'

  // Terminate for MATLABSystem: '<S14>/Read Parameter1'
  if (!controller_DW.obj_k.matlabCodegenIsDeleted) {
    controller_DW.obj_k.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S14>/Read Parameter1'

  // Terminate for Atomic SubSystem: '<S20>/Controller'
  controller_PX4Timestamp_Term(&controller_DW.PX4Timestamp_h);

  // Terminate for MATLABSystem: '<S38>/SinkBlock'
  if (!controller_DW.obj_h0.matlabCodegenIsDeleted) {
    controller_DW.obj_h0.matlabCodegenIsDeleted = true;
    if ((controller_DW.obj_h0.isInitialized == 1) &&
        controller_DW.obj_h0.isSetupComplete) {
      uORB_write_terminate(&controller_DW.obj_h0.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S38>/SinkBlock'
  controller_PX4Timestamp_Term(&controller_DW.PX4Timestamp_c);

  // Terminate for MATLABSystem: '<S147>/SinkBlock'
  if (!controller_DW.obj_n.matlabCodegenIsDeleted) {
    controller_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((controller_DW.obj_n.isInitialized == 1) &&
        controller_DW.obj_n.isSetupComplete) {
      uORB_write_terminate(&controller_DW.obj_n.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S147>/SinkBlock'
  // End of Terminate for SubSystem: '<S20>/Controller'

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

  // Terminate for MATLABSystem: '<S12>/Read Parameter13'
  if (!controller_DW.obj_lp.matlabCodegenIsDeleted) {
    controller_DW.obj_lp.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S12>/Read Parameter13'

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

  // Terminate for MATLABSystem: '<S154>/SourceBlock'
  if (!controller_DW.obj_j.matlabCodegenIsDeleted) {
    controller_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((controller_DW.obj_j.isInitialized == 1) &&
        controller_DW.obj_j.isSetupComplete) {
      uORB_read_terminate(&controller_DW.obj_j.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S154>/SourceBlock'
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
